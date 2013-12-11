#include <stdio.h>
#include <unistd.h>

#include "agm_modelPrinter.h"
#include "agm_modelEdge.h"

void AGMModelPrinter::printWorld(const AGMModel::SPtr &w)
{
	AGMModelPrinter::printWorld(w.get());
}

void AGMModelPrinter::printWorld(const AGMModel *w)
{
	for (uint32_t i=0; i<w->symbols.size(); ++i)
	{
		printf("(%d): %s\n", w->symbols[i]->identifier, w->symbols[i]->symbolType.c_str());
		std::map<std::string, std::string>::const_iterator itr = w->symbols[i]->attributes.begin();
		for(; itr!=w->symbols[i]->attributes.end(); ++itr)
		{
			printf("\t<%s> --> <%s>\n", itr->first.c_str(), itr->second.c_str());
		}
	}

	for (uint32_t i=0; i<w->edges.size(); ++i)
	{
		printf("%d -> %d  (%s)\n", w->edges[i].symbolPair.first, w->edges[i].symbolPair.second, w->edges[i].linking.c_str());
	}
}

#ifdef ROBOCOMP_SUPPORT
void AGMModelPrinter::printWorld(const RoboCompAGMWorldModel::World &w)
{
	AGMModelPrinter::printWorld(stdout, w);
}

void AGMModelPrinter::printWorld(FILE *fd, const RoboCompAGMWorldModel::World &w)
{
	for (uint32_t i=0; i<w.nodes.size(); ++i)
	{
		fprintf(fd, "(%d): %s\n", w.nodes[i].nodeIdentifier, w.nodes[i].nodeType.c_str());
		RoboCompAGMWorldModel::StringDictionary::const_iterator itr = w.nodes[i].attributes.begin();
		for(; itr!=w.nodes[i].attributes.end(); ++itr)
		{
			fprintf(fd, "\t<%s> --> <%s>\n", itr->first.c_str(), itr->second.c_str());
		}
	}

	for (uint32_t i=0; i<w.edges.size(); ++i)
	{
		fprintf(fd, "%d -> %d  (%s)\n", w.edges[i].a, w.edges[i].b, w.edges[i].edgeType.c_str());
	}
}

#endif

