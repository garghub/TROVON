static int dissect_q932_ros(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data) {
if (data == NULL)
return 0;
rose_ctx_tmp = get_rose_ctx(data);
DISSECTOR_ASSERT(rose_ctx_tmp);
return dissect_ROS_PDU(tvb, pinfo, tree, NULL);
}
void proto_register_q932_ros(void) {
static hf_register_info hf[] = {
#include "packet-q932-ros-hfarr.c"
};
static gint *ett[] = {
#include "packet-q932-ros-ettarr.c"
};
static ei_register_info ei[] = {
{ &ei_ros_undecoded, { "q932.ros.undecoded", PI_UNDECODED, PI_WARN, "Undecoded", EXPFILL }},
};
expert_module_t* expert_q932_ros;
proto_q932_ros = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_set_cant_toggle(proto_q932_ros);
proto_register_field_array(proto_q932_ros, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_q932_ros = expert_register_protocol(proto_q932_ros);
expert_register_field_array(expert_q932_ros, ei, array_length(ei));
new_register_dissector(PFNAME, dissect_q932_ros, proto_q932_ros);
}
void proto_reg_handoff_q932_ros(void) {
data_handle = find_dissector("data");
}
