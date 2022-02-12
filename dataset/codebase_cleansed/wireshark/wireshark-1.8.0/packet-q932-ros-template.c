static int dissect_q932_ros(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
rose_ctx_tmp = get_rose_ctx(pinfo->private_data);
DISSECTOR_ASSERT(rose_ctx_tmp);
return dissect_ROS_PDU(tvb, pinfo, tree);
}
void proto_register_q932_ros(void) {
static hf_register_info hf[] = {
#include "packet-q932-ros-hfarr.c"
};
static gint *ett[] = {
#include "packet-q932-ros-ettarr.c"
};
proto_q932_ros = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_set_cant_toggle(proto_q932_ros);
proto_register_field_array(proto_q932_ros, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector(PFNAME, dissect_q932_ros, proto_q932_ros);
}
void proto_reg_handoff_q932_ros(void) {
data_handle = find_dissector("data");
}
