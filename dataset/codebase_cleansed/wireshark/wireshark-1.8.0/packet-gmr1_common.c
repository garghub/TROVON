void
gmr1_get_msg_params(gmr1_pd_e pd, guint8 oct, const gchar **msg_str,
int *ett_tree, int *hf_idx, gmr1_msg_func_t *msg_func_p)
{
switch (pd) {
case GMR1_PD_RR:
gmr1_get_msg_rr_params(oct, 1, msg_str, ett_tree, hf_idx, msg_func_p);
break;
default:
*msg_str = NULL;
*ett_tree = -1;
*hf_idx = -1;
*msg_func_p = NULL;
}
}
void
proto_register_gmr1_common(void)
{
static hf_register_info hf[] = {
{ &hf_gmr1_skip_ind,
{ "Skip Indicator", "gmr1.skip_ind",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_gmr1_l3_pd,
{ "Protocol discriminator","gmr1.l3_protocol_discriminator",
FT_UINT8, BASE_DEC, VALS(gmr1_pd_vals), 0x0f,
NULL, HFILL }
},
{ &hf_gmr1_elem_id,
{ "Element ID", "gmr1.ie.elem_id",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_gmr1_len,
{ "Length", "gmr1.ie.length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_com_cm2_spare1,
{ "Spare", "gmr1.common.cm2.spare1",
FT_UINT8, BASE_DEC, NULL, 0x80,
NULL, HFILL }
},
{ &hf_com_cm2_revision,
{ "Revision Level", "gmr1.common.cm2.revision",
FT_UINT8, BASE_DEC, VALS(com_cm2_revision_vals), 0x60,
NULL, HFILL }
},
{ &hf_com_cm2_early_send,
{ "ES IND", "gmr1.common.cm2.early_send",
FT_UINT8, BASE_DEC, VALS(com_cm2_early_send_vals), 0x10,
NULL, HFILL }
},
{ &hf_com_cm2_a5_1,
{ "A5/1", "gmr1.common.cm2.a5_1",
FT_UINT8, BASE_DEC, VALS(com_cm2_a5_1_vals), 0x08,
NULL, HFILL }
},
{ &hf_com_cm2_mes_type,
{ "MES terminal type", "gmr1.common.cm2.mes_type",
FT_UINT8, BASE_DEC, VALS(com_cm2_mes_type_vals), 0x07,
NULL, HFILL }
},
{ &hf_com_cm2_spare2,
{ "Spare", "gmr1.common.cm2.spare2",
FT_UINT8, BASE_DEC, NULL, 0xc0,
NULL, HFILL }
},
{ &hf_com_cm2_ss_screen_ind,
{ "SS Screening Indicator", "gmr1.common.cm2.ss_screen_ind",
FT_UINT8, BASE_DEC, VALS(com_cm2_ss_screen_ind_vals), 0x30,
NULL, HFILL }
},
{ &hf_com_cm2_sms_cap,
{ "SM capability", "gmr1.common.cm2.sms_cap",
FT_UINT8, BASE_DEC, VALS(com_cm2_sms_cap_vals), 0x08,
NULL, HFILL }
},
{ &hf_com_cm2_spare3,
{ "Spare", "gmr1.common.cm2.spare3",
FT_UINT8, BASE_DEC, NULL, 0x06,
NULL, HFILL }
},
{ &hf_com_cm2_freq_cap,
{ "FC", "gmr1.common.cm2.freq_cap",
FT_UINT8, BASE_DEC, VALS(com_cm2_freq_cap_vals), 0x01,
NULL, HFILL }
},
{ &hf_com_cm2_cm3_presence,
{ "CM3", "gmr1.common.cm2.cm3_presence",
FT_UINT8, BASE_DEC, VALS(com_cm3_presence_vals), 0x80,
NULL, HFILL }
},
{ &hf_com_cm2_spare4,
{ "Spare", "gmr1.common.cm2.spare4",
FT_UINT8, BASE_DEC, NULL, 0x7c,
NULL, HFILL }
},
{ &hf_com_cm2_a5_3,
{ "A5/3", "gmr1.common.cm2.a5_3",
FT_UINT8, BASE_DEC, VALS(com_cm2_a5_3_vals), 0x02,
NULL, HFILL }
},
{ &hf_com_cm2_a5_2_gmr1,
{ "A5/2 GMR-1", "gmr1.common.cm2.a5_2_gmr1",
FT_UINT8, BASE_DEC, VALS(com_cm2_a5_2_gmr1_vals), 0x01,
NULL, HFILL }
},
};
proto_gmr1_common = proto_register_protocol("GEO-Mobile Radio (1) Common", "GMR-1 Common", "gmr1_common");
proto_register_field_array(proto_gmr1_common, hf, array_length(hf));
}
void
proto_reg_handoff_gmr1_common(void)
{
}
