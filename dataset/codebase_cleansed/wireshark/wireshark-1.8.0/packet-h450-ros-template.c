static void
argument_cb(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_) {
arg_next_tvb = tvb;
}
static void
result_cb(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_) {
res_next_tvb = tvb;
}
static void
error_cb(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_) {
err_next_tvb = tvb;
}
void proto_register_h450_ros(void) {
static hf_register_info hf[] = {
#include "packet-h450-ros-hfarr.c"
};
static gint *ett[] = {
#include "packet-h450-ros-ettarr.c"
};
proto_h450_ros = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_set_cant_toggle(proto_h450_ros);
proto_register_field_array(proto_h450_ros, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_h450_ros(void) {
data_handle = find_dissector("data");
}
