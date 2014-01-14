from pyparsing import Word, alphas, alphanums, nums, OneOrMore, CharsNotIn, Literal, Combine
from pyparsing import Suppress, ZeroOrMore, Group, StringEnd, srange, Forward, Optional, Or
from AGGL import *
from PySide.QtCore import *
from PySide.QtGui import *

class AGGL_QuantifierCondition:
	def __init__(self, condType):
		self.condType = condType

class AGGL_QuantifierEffect:
	def __init__(self, condType):
		self.condType = condType

class AGGL_QuantifierLink:
	def __init__(self, t, a, b, v):
		self.t = t
		self.a = a
		self.b = b
		self.v = v


class AGGLCodeParsing:
	@staticmethod
	def parseParameters(text, verbose=False):
		#print '<<'+text+'>>'
		ids     = Word(srange("[a-zA-Z0-9_]"))
		varDec  = Group(Combine(ids.setResultsName("var")+Literal(':')+ids.setResultsName("t")))
		params  = OneOrMore(varDec)
		r = params.parseString(text)
		#print r
		return r

	@staticmethod
	def parseFormula(text, verbose=False):
		if verbose: print 'Verbose:', verbose
		# Basic elements
		ids     = Word(srange("[a-zA-Z0-9_]"))
		po      = Suppress("(")
		pc      = Suppress(")")
		lt      = Suppress("<")
		gt      = Suppress(">")
		not_    = Word("not")
		and_    = Word("and")
		or_     = Word("or")
		forall_ = Word("forall")
		exists_ = Word("exists")
		when_   = Word("when")
		create_ = Word("create")
		delete_ = Word("delete")
		retype_ = Word("retype")
		# Identifiers
		ids     = Word(srange("[a-zA-Z0-9_]"))
		# List of identifiers
		varDec  = Group(Combine(ids.setResultsName("var")+Literal(':')+ids.setResultsName("t")))
		params  = OneOrMore(varDec)
		# Groups: complex elements, not, forall, when, create and the like
		formula = Forward()
		link          = Group( po +     ids.setResultsName("type") +                ids.setResultsName("a") + ids.setResultsName("b") + pc )
		notFormula    = Group( po +    not_.setResultsName("type") +                                  formula.setResultsName("child") + pc )
		andFormula    = Group( po +    and_.setResultsName("type") +                        OneOrMore(formula).setResultsName("more") + pc )
		orFormula     = Group( po +     or_.setResultsName("type") +                        OneOrMore(formula).setResultsName("more") + pc )
		forallFormula = Group( po + forall_.setResultsName("type") +  params.setResultsName("vars") + formula.setResultsName("child") + pc )
		whenFormula   = Group( po +   when_.setResultsName("type") +   formula.setResultsName("iff") + formula.setResultsName("then") + pc )
		functionCall  = Group( lt +     ids.setResultsName("func") +                       OneOrMore(ids).setResultsName("arguments") + gt )
		create        = Group( po + create_.setResultsName("type") +          ids.setResultsName("name") + ids.setResultsName("type") + pc )
		delete        = Group( po + delete_.setResultsName("type") +                                       ids.setResultsName("name") + pc )
		retype        = Group( po + retype_.setResultsName("type") +          ids.setResultsName("name") + ids.setResultsName("type") + pc )
		# Parse call
		formula << (notFormula | andFormula | link | orFormula | forallFormula | whenFormula | create | delete | retype | functionCall )
		return formula.parseWithTabs().parseString(text)


