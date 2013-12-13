#ifndef WORLDMODELPRINTER_H
#define WORLDMODELPRINTER_H

#include <stdio.h>

#include <agm_config.h>
#include <agm_model.h>
#include <agm_modelEdge.h>
#include <agm_modelSymbols.h>

#ifdef ROBOCOMP_SUPPORT
#include <AGMWorldModel.h>
#endif

/*!
 * @brief Utility class to print AGMModel graphs
 *
 * 
 * 
 */
class AGMModelPrinter
{
public:
	/// Prints a model given a shared pointer to it.
	static void printWorld(const AGMModel::SPtr &w);
	/// Prints a model given a regular pointer to it.
	static void printWorld(const AGMModel *w);
#ifdef ROBOCOMP_SUPPORT
	/// Prints a model given a RoboComp <em>RoboCompAGMWorldModel::World</em> model data type.
	static void printWorld(const RoboCompAGMWorldModel::World &w);
	/// Prints a model given a RoboComp <em>RoboCompAGMWorldModel::World</em> model data type, to a file.
	static void printWorld(FILE *fd, const RoboCompAGMWorldModel::World &w);
#endif
};


#endif

