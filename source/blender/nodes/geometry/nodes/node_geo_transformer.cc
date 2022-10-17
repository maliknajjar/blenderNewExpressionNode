/* SPDX-License-Identifier: GPL-2.0-or-later */

#include "NOD_socket.h"
#include "NOD_socket_search_link.hh"
#include "node_geometry_util.hh"

#include "Python.h"

#include "UI_interface.h"
#include "UI_resources.h"

#include "DNA_text_types.h"

namespace blender::nodes::node_geo_transformer_cc {

// NODE_STORAGE_FUNCS(NodeGeometryTransformer)

static void node_declare(NodeDeclarationBuilder &b)
{
  printf("node_declare\n");
  b.add_input<decl::Geometry>(N_("Mesh"));
  b.add_input<decl::Float>(N_("value"));
  b.add_output<decl::Geometry>(N_("Geometry"));
}

static void node_layout(uiLayout *layout, bContext *UNUSED(C), PointerRNA *ptr)
{
  uiItemR(layout, ptr, "Text", UI_ITEM_R_SPLIT_EMPTY_NAME, "", ICON_NONE);
}

static void node_init(bNodeTree *tree, bNode *node)
{
  printf("node_init\n");
  // NodeGeometryTransformer *nss = MEM_cnew<NodeGeometryTransformer>("__func__");
  // node->storage = nss;
}

static void node_update(bNodeTree *tree, bNode *node)
{
  Text *text = (Text *)node->id;
  printf("text content is: %s\n", text->sell->line);
  // const NodeGeometryTransformer &storage = node_storage(*node);
  // AssetMetaData *asset = node->id->asset_data;
  // printf("the pointer address of the file is: %p\n", asset);
}

static void node_geo_exec(GeoNodeExecParams params)
{
  printf("node_geo_exec\n");
  GeometrySet geometry_set = params.extract_input<GeometrySet>("Mesh");
  params.set_output("Mesh", std::move(geometry_set));

  // const NodeGeometryTransformer &storage = node_storage(params.node());
}

}  // namespace blender::nodes::node_geo_transformer_cc

void register_node_type_geo_transformer()
{
  namespace file_ns = blender::nodes::node_geo_transformer_cc;

  static bNodeType ntype;

  geo_node_type_base(&ntype, GEO_NODE_TRANSFORMER, "Transformer", NODE_CLASS_GEOMETRY);
  // node_type_storage(
  //     &ntype, "NodeGeometryTransformer", node_free_standard_storage,
  //     node_copy_standard_storage);
  ntype.declare = file_ns::node_declare;
  ntype.declaration_is_dynamic = true;
  ntype.initfunc = file_ns::node_init;
  ntype.updatefunc = file_ns::node_update;
  ntype.geometry_node_execute = file_ns::node_geo_exec;
  ntype.draw_buttons = file_ns::node_layout;
  nodeRegisterType(&ntype);
}
