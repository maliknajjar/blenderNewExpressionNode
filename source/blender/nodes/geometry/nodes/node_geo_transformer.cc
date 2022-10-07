/* SPDX-License-Identifier: GPL-2.0-or-later */

#include "GEO_realize_instances.hh"

#include "node_geometry_util.hh"

void register_node_type_geo_transformer()
{
  // namespace file_ns = blender::nodes::node_geo_join_geometry_cc;

  static bNodeType ntype;

  geo_node_type_base(&ntype, GEO_NODE_TRANSFORMER, "transformer", NODE_CLASS_GEOMETRY);
  // ntype.geometry_node_execute = file_ns::node_geo_exec;
  // ntype.declare = file_ns::node_declare;
  nodeRegisterType(&ntype);
}
