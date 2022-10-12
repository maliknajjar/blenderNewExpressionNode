/* SPDX-License-Identifier: GPL-2.0-or-later */

#include "NOD_socket.h"
#include "NOD_socket_search_link.hh"
#include "node_geometry_util.hh"

#include <Python.h>

#include "UI_interface.h"
#include "UI_resources.h"

namespace blender::nodes::node_geo_transformer_cc {

NODE_STORAGE_FUNCS(NodeGeometryTrasnformer)

static void node_declare(NodeDeclarationBuilder &b)
{
  b.add_input<decl::Geometry>(N_("Geometry"));
  b.add_output<decl::Geometry>(N_("Geometry"));
}

static void node_update(bNodeTree *tree, bNode *node)
{
  printf("updating the node\n\n");
}

static void node_init(bNodeTree *tree, bNode *node)
{
}

static void node_geo_exec(GeoNodeExecParams params)
{
  GeometrySet geometry_set = params.extract_input<GeometrySet>("Geometry");
}

}  // namespace blender::nodes::node_geo_transformer_cc

void register_node_type_geo_transformer()
{
  namespace file_ns = blender::nodes::node_geo_transformer_cc;

  static bNodeType ntype;

  geo_node_type_base(&ntype, GEO_NODE_TRANSFORMER, "Transformer", NODE_CLASS_GEOMETRY);
  ntype.declare = file_ns::node_declare;
  ntype.declaration_is_dynamic = true;
  ntype.initfunc = file_ns::node_init;
  ntype.updatefunc = file_ns::node_update;
  ntype.geometry_node_execute = file_ns::node_geo_exec;
  nodeRegisterType(&ntype);
}
