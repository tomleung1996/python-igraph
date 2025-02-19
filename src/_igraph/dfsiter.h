/* -*- mode: C -*-  */
/* 
   IGraph library.
   Copyright (C) 2020  The igraph development team
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc.,  51 Franklin Street, Fifth Floor, Boston, MA 
   02110-1301 USA

*/

#ifndef PYTHON_DFSITER_H
#define PYTHON_DFSITER_H

#include "preamble.h"

#include "graphobject.h"

/**
 * \ingroup python_interface_dfsiter
 * \brief A structure representing a DFS iterator of a graph
 */
typedef struct {
  PyObject_HEAD
  igraphmodule_GraphObject* gref;
  igraph_stack_int_t stack;
  igraph_vector_int_t neis;
  igraph_t *graph;
  char *visited;
  igraph_neimode_t mode;
  igraph_bool_t advanced;
} igraphmodule_DFSIterObject;

extern PyTypeObject* igraphmodule_DFSIterType;

int igraphmodule_DFSIter_register_type(void);

PyObject* igraphmodule_DFSIter_new(
  igraphmodule_GraphObject *g, PyObject *o, igraph_neimode_t mode,
  igraph_bool_t advanced
);

#endif
