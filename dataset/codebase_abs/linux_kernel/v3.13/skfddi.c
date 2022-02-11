static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
void T_1 * V_9 ;
int V_10 ;
F_2 ( L_1 ) ;
if ( V_11 == 0 )
F_3 ( L_2 , V_12 ) ;
V_10 = F_4 ( V_2 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_5 ( V_2 , L_3 ) ;
if ( V_10 )
goto V_13;
F_6 ( V_2 ) ;
#ifdef F_7
if ( ! ( F_8 ( V_2 , 0 ) & V_14 ) ) {
F_3 ( V_15 L_4 ) ;
V_10 = - V_16 ;
goto V_17;
}
V_9 = F_9 ( F_10 ( V_2 , 0 ) , 0x4000 ) ;
#else
if ( ! ( F_8 ( V_2 , 1 ) & V_18 ) ) {
F_3 ( V_15 L_5 ) ;
V_10 = - V_16 ;
goto V_17;
}
V_9 = F_11 ( F_10 ( V_2 , 1 ) , V_19 ) ;
#endif
if ( ! V_9 ) {
F_3 ( V_15 L_6
L_7 ) ;
V_10 = - V_16 ;
goto V_17;
}
V_6 = F_12 ( sizeof( struct V_7 ) ) ;
if ( ! V_6 ) {
F_3 ( V_15 L_8
L_7 ) ;
V_10 = - V_20 ;
goto V_21;
}
V_6 -> V_22 = V_2 -> V_22 ;
V_6 -> V_23 = & V_24 ;
F_13 ( V_6 , & V_2 -> V_6 ) ;
V_8 = F_14 ( V_6 ) ;
V_8 -> V_25 . V_6 = V_6 ;
V_8 -> V_25 . V_26 = V_27 ;
V_8 -> V_25 . V_2 = * V_2 ;
V_8 -> V_25 . V_28 = V_29 ;
V_8 -> V_25 . V_30 = V_31 ;
V_8 -> V_25 . V_6 = V_6 ;
V_8 -> V_32 . V_33 = - 1 ;
V_8 -> V_32 . V_34 = V_9 ;
V_8 -> V_25 . V_35 = FALSE ;
F_15 ( & V_8 -> V_25 . V_36 ) ;
V_6 -> V_37 = ( unsigned long ) V_9 ;
V_10 = F_16 ( V_6 ) ;
if ( V_10 )
goto V_38;
V_10 = F_17 ( V_6 ) ;
if ( V_10 )
goto V_39;
++ V_11 ;
F_18 ( V_2 , V_6 ) ;
if ( ( V_2 -> V_40 & 0xff00 ) == 0x5500 ||
( V_2 -> V_40 & 0xff00 ) == 0x5800 )
F_3 ( L_9
L_10 , V_6 -> V_41 ,
V_2 -> V_40 ) ;
else
F_3 ( L_11 , V_6 -> V_41 ) ;
return 0 ;
V_39:
if ( V_8 -> V_25 . V_42 )
F_19 ( V_2 , V_8 -> V_25 . V_43 ,
V_8 -> V_25 . V_42 ,
V_8 -> V_25 . V_44 ) ;
F_19 ( V_2 , V_31 ,
V_8 -> V_25 . V_45 , V_8 -> V_25 . V_46 ) ;
V_38:
F_20 ( V_6 ) ;
V_21:
#ifdef F_7
F_21 ( V_9 ) ;
#else
F_22 ( V_9 ) ;
#endif
V_17:
F_23 ( V_2 ) ;
V_13:
F_24 ( V_2 ) ;
return V_10 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_5 * V_47 = F_26 ( V_2 ) ;
struct V_7 * V_48 = F_14 ( V_47 ) ;
F_27 ( V_47 ) ;
if ( V_48 -> V_25 . V_42 ) {
F_19 ( & V_48 -> V_25 . V_2 ,
V_48 -> V_25 . V_43 ,
V_48 -> V_25 . V_42 ,
V_48 -> V_25 . V_44 ) ;
V_48 -> V_25 . V_42 = NULL ;
}
if ( V_48 -> V_25 . V_45 ) {
F_19 ( & V_48 -> V_25 . V_2 ,
V_31 ,
V_48 -> V_25 . V_45 ,
V_48 -> V_25 . V_46 ) ;
V_48 -> V_25 . V_45 = NULL ;
}
#ifdef F_7
F_21 ( V_48 -> V_32 . V_34 ) ;
#else
F_22 ( V_48 -> V_32 . V_34 ) ;
#endif
F_23 ( V_2 ) ;
F_20 ( V_47 ) ;
F_24 ( V_2 ) ;
F_18 ( V_2 , NULL ) ;
}
static int F_16 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_14 ( V_6 ) ;
T_2 * V_49 = & V_8 -> V_25 ;
int V_10 = - V_16 ;
F_2 ( L_12 ) ;
V_49 -> V_37 = V_6 -> V_37 ;
V_8 -> V_32 . V_22 = V_6 -> V_22 ;
F_28 ( & V_49 -> V_50 ) ;
V_49 -> V_45 = F_29 ( & V_49 -> V_2 , V_31 , & V_49 -> V_46 ) ;
if ( ! V_49 -> V_45 ) {
F_3 ( L_13 ) ;
F_3 ( L_14 , V_31 ) ;
goto V_51;
}
V_49 -> V_43 = F_30 () ;
F_2 ( L_15 , V_49 -> V_43 ) ;
if ( V_49 -> V_43 > 0 ) {
V_49 -> V_43 += 16 ;
V_49 -> V_42 = F_29 ( & V_49 -> V_2 ,
V_49 -> V_43 ,
& V_49 -> V_44 ) ;
if ( ! V_49 -> V_42 ) {
F_3 ( L_13 ) ;
F_3 ( L_16 ,
V_49 -> V_43 ) ;
goto V_51;
}
V_49 -> V_52 = 0 ;
} else {
V_49 -> V_42 = NULL ;
V_49 -> V_52 = 0 ;
}
memset ( V_49 -> V_42 , 0 , V_49 -> V_43 ) ;
F_31 ( V_8 ) ;
F_2 ( L_17 ) ;
if ( F_32 ( V_8 ) != 0 ) {
F_2 ( L_18 ) ;
goto V_51;
}
F_33 ( V_8 , NULL ) ;
F_2 ( L_19 , V_8 -> V_32 . V_53 . V_54 ) ;
memcpy ( V_6 -> V_55 , V_8 -> V_32 . V_53 . V_54 , V_56 ) ;
F_34 ( V_8 , 0 ) ;
return 0 ;
V_51:
if ( V_49 -> V_42 ) {
F_19 ( & V_49 -> V_2 ,
V_49 -> V_43 ,
V_49 -> V_42 ,
V_49 -> V_44 ) ;
V_49 -> V_42 = NULL ;
}
if ( V_49 -> V_45 ) {
F_19 ( & V_49 -> V_2 , V_31 ,
V_49 -> V_45 , V_49 -> V_46 ) ;
V_49 -> V_45 = NULL ;
}
return V_10 ;
}
static int F_35 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_14 ( V_6 ) ;
int V_10 ;
F_2 ( L_20 ) ;
V_10 = F_36 ( V_6 -> V_22 , V_57 , V_58 ,
V_6 -> V_41 , V_6 ) ;
if ( V_10 )
return V_10 ;
F_33 ( V_8 , NULL ) ;
memcpy ( V_6 -> V_55 , V_8 -> V_32 . V_53 . V_54 , V_56 ) ;
F_37 ( V_8 , NULL ) ;
F_38 ( V_8 , 1 ) ;
F_39 () ;
F_40 ( V_8 ) ;
F_41 ( V_8 , V_59 ) ;
F_42 ( V_6 ) ;
return 0 ;
}
static int F_43 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_14 ( V_6 ) ;
T_2 * V_49 = & V_8 -> V_25 ;
F_44 () ;
F_34 ( V_8 , 1 ) ;
F_31 ( V_8 ) ;
F_45 ( V_8 ) ;
F_46 ( V_8 ) ;
F_47 ( V_6 ) ;
F_48 ( V_6 -> V_22 , V_6 ) ;
F_49 ( & V_49 -> V_36 ) ;
V_49 -> V_28 = V_29 ;
return 0 ;
}
static T_3 V_57 ( int V_22 , void * V_60 )
{
struct V_5 * V_6 = V_60 ;
struct V_7 * V_8 ;
T_2 * V_49 ;
V_8 = F_14 ( V_6 ) ;
V_49 = & V_8 -> V_25 ;
if ( F_50 ( F_51 ( V_61 ) ) == 0 ) {
return V_62 ;
}
if ( ( F_50 ( V_63 ) & V_8 -> V_32 . V_64 ) == 0 ) {
return V_62 ;
}
F_44 () ;
F_52 ( & V_49 -> V_50 ) ;
F_53 ( V_8 ) ;
if ( V_8 -> V_25 . V_35 ) {
F_54 ( V_8 ) ;
V_8 -> V_25 . V_35 = FALSE ;
}
F_55 ( & V_49 -> V_50 ) ;
F_39 () ;
return V_65 ;
}
static struct V_66 * F_56 ( struct V_5 * V_6 )
{
struct V_7 * V_49 = F_14 ( V_6 ) ;
V_49 -> V_25 . V_67 . V_68 [ 0 ] = 0x1234 ;
V_49 -> V_25 . V_67 . V_68 [ 1 ] = 0x5678 ;
#if 0
memcpy(bp->stats.smt_station_id, &bp->cmd_rsp_virt->smt_mib_get.smt_station_id, sizeof(bp->cmd_rsp_virt->smt_mib_get.smt_station_id));
bp->stats.smt_op_version_id = bp->cmd_rsp_virt->smt_mib_get.smt_op_version_id;
bp->stats.smt_hi_version_id = bp->cmd_rsp_virt->smt_mib_get.smt_hi_version_id;
bp->stats.smt_lo_version_id = bp->cmd_rsp_virt->smt_mib_get.smt_lo_version_id;
memcpy(bp->stats.smt_user_data, &bp->cmd_rsp_virt->smt_mib_get.smt_user_data, sizeof(bp->cmd_rsp_virt->smt_mib_get.smt_user_data));
bp->stats.smt_mib_version_id = bp->cmd_rsp_virt->smt_mib_get.smt_mib_version_id;
bp->stats.smt_mac_cts = bp->cmd_rsp_virt->smt_mib_get.smt_mac_ct;
bp->stats.smt_non_master_cts = bp->cmd_rsp_virt->smt_mib_get.smt_non_master_ct;
bp->stats.smt_master_cts = bp->cmd_rsp_virt->smt_mib_get.smt_master_ct;
bp->stats.smt_available_paths = bp->cmd_rsp_virt->smt_mib_get.smt_available_paths;
bp->stats.smt_config_capabilities = bp->cmd_rsp_virt->smt_mib_get.smt_config_capabilities;
bp->stats.smt_config_policy = bp->cmd_rsp_virt->smt_mib_get.smt_config_policy;
bp->stats.smt_connection_policy = bp->cmd_rsp_virt->smt_mib_get.smt_connection_policy;
bp->stats.smt_t_notify = bp->cmd_rsp_virt->smt_mib_get.smt_t_notify;
bp->stats.smt_stat_rpt_policy = bp->cmd_rsp_virt->smt_mib_get.smt_stat_rpt_policy;
bp->stats.smt_trace_max_expiration = bp->cmd_rsp_virt->smt_mib_get.smt_trace_max_expiration;
bp->stats.smt_bypass_present = bp->cmd_rsp_virt->smt_mib_get.smt_bypass_present;
bp->stats.smt_ecm_state = bp->cmd_rsp_virt->smt_mib_get.smt_ecm_state;
bp->stats.smt_cf_state = bp->cmd_rsp_virt->smt_mib_get.smt_cf_state;
bp->stats.smt_remote_disconnect_flag = bp->cmd_rsp_virt->smt_mib_get.smt_remote_disconnect_flag;
bp->stats.smt_station_status = bp->cmd_rsp_virt->smt_mib_get.smt_station_status;
bp->stats.smt_peer_wrap_flag = bp->cmd_rsp_virt->smt_mib_get.smt_peer_wrap_flag;
bp->stats.smt_time_stamp = bp->cmd_rsp_virt->smt_mib_get.smt_msg_time_stamp.ls;
bp->stats.smt_transition_time_stamp = bp->cmd_rsp_virt->smt_mib_get.smt_transition_time_stamp.ls;
bp->stats.mac_frame_status_functions = bp->cmd_rsp_virt->smt_mib_get.mac_frame_status_functions;
bp->stats.mac_t_max_capability = bp->cmd_rsp_virt->smt_mib_get.mac_t_max_capability;
bp->stats.mac_tvx_capability = bp->cmd_rsp_virt->smt_mib_get.mac_tvx_capability;
bp->stats.mac_available_paths = bp->cmd_rsp_virt->smt_mib_get.mac_available_paths;
bp->stats.mac_current_path = bp->cmd_rsp_virt->smt_mib_get.mac_current_path;
memcpy(bp->stats.mac_upstream_nbr, &bp->cmd_rsp_virt->smt_mib_get.mac_upstream_nbr, FDDI_K_ALEN);
memcpy(bp->stats.mac_downstream_nbr, &bp->cmd_rsp_virt->smt_mib_get.mac_downstream_nbr, FDDI_K_ALEN);
memcpy(bp->stats.mac_old_upstream_nbr, &bp->cmd_rsp_virt->smt_mib_get.mac_old_upstream_nbr, FDDI_K_ALEN);
memcpy(bp->stats.mac_old_downstream_nbr, &bp->cmd_rsp_virt->smt_mib_get.mac_old_downstream_nbr, FDDI_K_ALEN);
bp->stats.mac_dup_address_test = bp->cmd_rsp_virt->smt_mib_get.mac_dup_address_test;
bp->stats.mac_requested_paths = bp->cmd_rsp_virt->smt_mib_get.mac_requested_paths;
bp->stats.mac_downstream_port_type = bp->cmd_rsp_virt->smt_mib_get.mac_downstream_port_type;
memcpy(bp->stats.mac_smt_address, &bp->cmd_rsp_virt->smt_mib_get.mac_smt_address, FDDI_K_ALEN);
bp->stats.mac_t_req = bp->cmd_rsp_virt->smt_mib_get.mac_t_req;
bp->stats.mac_t_neg = bp->cmd_rsp_virt->smt_mib_get.mac_t_neg;
bp->stats.mac_t_max = bp->cmd_rsp_virt->smt_mib_get.mac_t_max;
bp->stats.mac_tvx_value = bp->cmd_rsp_virt->smt_mib_get.mac_tvx_value;
bp->stats.mac_frame_error_threshold = bp->cmd_rsp_virt->smt_mib_get.mac_frame_error_threshold;
bp->stats.mac_frame_error_ratio = bp->cmd_rsp_virt->smt_mib_get.mac_frame_error_ratio;
bp->stats.mac_rmt_state = bp->cmd_rsp_virt->smt_mib_get.mac_rmt_state;
bp->stats.mac_da_flag = bp->cmd_rsp_virt->smt_mib_get.mac_da_flag;
bp->stats.mac_una_da_flag = bp->cmd_rsp_virt->smt_mib_get.mac_unda_flag;
bp->stats.mac_frame_error_flag = bp->cmd_rsp_virt->smt_mib_get.mac_frame_error_flag;
bp->stats.mac_ma_unitdata_available = bp->cmd_rsp_virt->smt_mib_get.mac_ma_unitdata_available;
bp->stats.mac_hardware_present = bp->cmd_rsp_virt->smt_mib_get.mac_hardware_present;
bp->stats.mac_ma_unitdata_enable = bp->cmd_rsp_virt->smt_mib_get.mac_ma_unitdata_enable;
bp->stats.path_tvx_lower_bound = bp->cmd_rsp_virt->smt_mib_get.path_tvx_lower_bound;
bp->stats.path_t_max_lower_bound = bp->cmd_rsp_virt->smt_mib_get.path_t_max_lower_bound;
bp->stats.path_max_t_req = bp->cmd_rsp_virt->smt_mib_get.path_max_t_req;
memcpy(bp->stats.path_configuration, &bp->cmd_rsp_virt->smt_mib_get.path_configuration, sizeof(bp->cmd_rsp_virt->smt_mib_get.path_configuration));
bp->stats.port_my_type[0] = bp->cmd_rsp_virt->smt_mib_get.port_my_type[0];
bp->stats.port_my_type[1] = bp->cmd_rsp_virt->smt_mib_get.port_my_type[1];
bp->stats.port_neighbor_type[0] = bp->cmd_rsp_virt->smt_mib_get.port_neighbor_type[0];
bp->stats.port_neighbor_type[1] = bp->cmd_rsp_virt->smt_mib_get.port_neighbor_type[1];
bp->stats.port_connection_policies[0] = bp->cmd_rsp_virt->smt_mib_get.port_connection_policies[0];
bp->stats.port_connection_policies[1] = bp->cmd_rsp_virt->smt_mib_get.port_connection_policies[1];
bp->stats.port_mac_indicated[0] = bp->cmd_rsp_virt->smt_mib_get.port_mac_indicated[0];
bp->stats.port_mac_indicated[1] = bp->cmd_rsp_virt->smt_mib_get.port_mac_indicated[1];
bp->stats.port_current_path[0] = bp->cmd_rsp_virt->smt_mib_get.port_current_path[0];
bp->stats.port_current_path[1] = bp->cmd_rsp_virt->smt_mib_get.port_current_path[1];
memcpy(&bp->stats.port_requested_paths[0 * 3], &bp->cmd_rsp_virt->smt_mib_get.port_requested_paths[0], 3);
memcpy(&bp->stats.port_requested_paths[1 * 3], &bp->cmd_rsp_virt->smt_mib_get.port_requested_paths[1], 3);
bp->stats.port_mac_placement[0] = bp->cmd_rsp_virt->smt_mib_get.port_mac_placement[0];
bp->stats.port_mac_placement[1] = bp->cmd_rsp_virt->smt_mib_get.port_mac_placement[1];
bp->stats.port_available_paths[0] = bp->cmd_rsp_virt->smt_mib_get.port_available_paths[0];
bp->stats.port_available_paths[1] = bp->cmd_rsp_virt->smt_mib_get.port_available_paths[1];
bp->stats.port_pmd_class[0] = bp->cmd_rsp_virt->smt_mib_get.port_pmd_class[0];
bp->stats.port_pmd_class[1] = bp->cmd_rsp_virt->smt_mib_get.port_pmd_class[1];
bp->stats.port_connection_capabilities[0] = bp->cmd_rsp_virt->smt_mib_get.port_connection_capabilities[0];
bp->stats.port_connection_capabilities[1] = bp->cmd_rsp_virt->smt_mib_get.port_connection_capabilities[1];
bp->stats.port_bs_flag[0] = bp->cmd_rsp_virt->smt_mib_get.port_bs_flag[0];
bp->stats.port_bs_flag[1] = bp->cmd_rsp_virt->smt_mib_get.port_bs_flag[1];
bp->stats.port_ler_estimate[0] = bp->cmd_rsp_virt->smt_mib_get.port_ler_estimate[0];
bp->stats.port_ler_estimate[1] = bp->cmd_rsp_virt->smt_mib_get.port_ler_estimate[1];
bp->stats.port_ler_cutoff[0] = bp->cmd_rsp_virt->smt_mib_get.port_ler_cutoff[0];
bp->stats.port_ler_cutoff[1] = bp->cmd_rsp_virt->smt_mib_get.port_ler_cutoff[1];
bp->stats.port_ler_alarm[0] = bp->cmd_rsp_virt->smt_mib_get.port_ler_alarm[0];
bp->stats.port_ler_alarm[1] = bp->cmd_rsp_virt->smt_mib_get.port_ler_alarm[1];
bp->stats.port_connect_state[0] = bp->cmd_rsp_virt->smt_mib_get.port_connect_state[0];
bp->stats.port_connect_state[1] = bp->cmd_rsp_virt->smt_mib_get.port_connect_state[1];
bp->stats.port_pcm_state[0] = bp->cmd_rsp_virt->smt_mib_get.port_pcm_state[0];
bp->stats.port_pcm_state[1] = bp->cmd_rsp_virt->smt_mib_get.port_pcm_state[1];
bp->stats.port_pc_withhold[0] = bp->cmd_rsp_virt->smt_mib_get.port_pc_withhold[0];
bp->stats.port_pc_withhold[1] = bp->cmd_rsp_virt->smt_mib_get.port_pc_withhold[1];
bp->stats.port_ler_flag[0] = bp->cmd_rsp_virt->smt_mib_get.port_ler_flag[0];
bp->stats.port_ler_flag[1] = bp->cmd_rsp_virt->smt_mib_get.port_ler_flag[1];
bp->stats.port_hardware_present[0] = bp->cmd_rsp_virt->smt_mib_get.port_hardware_present[0];
bp->stats.port_hardware_present[1] = bp->cmd_rsp_virt->smt_mib_get.port_hardware_present[1];
bp->stats.mac_frame_cts = bp->cmd_rsp_virt->cntrs_get.cntrs.frame_cnt.ls;
bp->stats.mac_copied_cts = bp->cmd_rsp_virt->cntrs_get.cntrs.copied_cnt.ls;
bp->stats.mac_transmit_cts = bp->cmd_rsp_virt->cntrs_get.cntrs.transmit_cnt.ls;
bp->stats.mac_error_cts = bp->cmd_rsp_virt->cntrs_get.cntrs.error_cnt.ls;
bp->stats.mac_lost_cts = bp->cmd_rsp_virt->cntrs_get.cntrs.lost_cnt.ls;
bp->stats.port_lct_fail_cts[0] = bp->cmd_rsp_virt->cntrs_get.cntrs.lct_rejects[0].ls;
bp->stats.port_lct_fail_cts[1] = bp->cmd_rsp_virt->cntrs_get.cntrs.lct_rejects[1].ls;
bp->stats.port_lem_reject_cts[0] = bp->cmd_rsp_virt->cntrs_get.cntrs.lem_rejects[0].ls;
bp->stats.port_lem_reject_cts[1] = bp->cmd_rsp_virt->cntrs_get.cntrs.lem_rejects[1].ls;
bp->stats.port_lem_cts[0] = bp->cmd_rsp_virt->cntrs_get.cntrs.link_errors[0].ls;
bp->stats.port_lem_cts[1] = bp->cmd_rsp_virt->cntrs_get.cntrs.link_errors[1].ls;
#endif
return (struct V_66 * ) & V_49 -> V_25 . V_67 ;
}
static void F_57 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_14 ( V_6 ) ;
T_2 * V_49 = & V_8 -> V_25 ;
unsigned long V_69 ;
F_58 ( & V_49 -> V_50 , V_69 ) ;
F_59 ( V_6 ) ;
F_60 ( & V_49 -> V_50 , V_69 ) ;
}
static void F_59 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_14 ( V_6 ) ;
struct V_70 * V_71 ;
if ( V_6 -> V_72 & V_73 ) {
F_41 ( V_8 , V_74 ) ;
F_2 ( L_21 ) ;
}
else {
F_41 ( V_8 , V_59 ) ;
F_2 ( L_22 ) ;
F_40 ( V_8 ) ;
F_41 ( V_8 , V_75 ) ;
if ( V_6 -> V_72 & V_76 ) {
F_41 ( V_8 , V_77 ) ;
F_2 ( L_23 ) ;
} else if ( ! F_61 ( V_6 ) ) {
if ( F_62 ( V_6 ) <= V_78 ) {
F_63 (ha, dev) {
F_64 ( V_8 ,
(struct V_79 * ) V_71 -> V_80 ,
1 ) ;
F_2 ( L_24 ,
V_71 -> V_80 ) ;
}
} else {
F_41 ( V_8 , V_77 ) ;
F_2 ( L_23 ) ;
}
} else {
F_2 ( L_25 ) ;
}
F_65 ( V_8 ) ;
}
}
static int F_66 ( struct V_5 * V_6 , void * V_80 )
{
struct V_7 * V_8 = F_14 ( V_6 ) ;
struct V_81 * V_82 = (struct V_81 * ) V_80 ;
T_2 * V_49 = & V_8 -> V_25 ;
unsigned long V_69 ;
memcpy ( V_6 -> V_55 , V_82 -> V_83 , V_84 ) ;
F_58 ( & V_49 -> V_50 , V_69 ) ;
F_54 ( V_8 ) ;
F_60 ( & V_49 -> V_50 , V_69 ) ;
return 0 ;
}
static int F_67 ( struct V_5 * V_6 , struct V_85 * V_86 , int V_87 )
{
struct V_7 * V_8 = F_14 ( V_6 ) ;
T_2 * V_48 = & V_8 -> V_25 ;
struct V_88 V_89 ;
int V_90 = 0 ;
if ( F_68 ( & V_89 , V_86 -> V_91 , sizeof( struct V_88 ) ) )
return - V_92 ;
switch ( V_89 . V_87 ) {
case V_93 :
V_89 . V_94 = sizeof( V_48 -> V_67 ) ;
V_90 = F_69 ( V_89 . V_95 , F_56 ( V_6 ) , V_89 . V_94 )
? - V_92 : 0 ;
break;
case V_96 :
if ( ! F_70 ( V_97 ) ) {
V_90 = - V_98 ;
} else {
memset ( & V_48 -> V_67 , 0 , sizeof( V_48 -> V_67 ) ) ;
}
break;
default:
F_3 ( L_26 , V_6 -> V_41 , V_89 . V_87 ) ;
V_90 = - V_99 ;
}
return V_90 ;
}
static T_4 F_71 ( struct V_100 * V_101 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_14 ( V_6 ) ;
T_2 * V_49 = & V_8 -> V_25 ;
F_2 ( L_27 ) ;
if ( ! ( V_101 -> V_94 >= V_102 && V_101 -> V_94 <= V_103 ) ) {
V_49 -> V_67 . V_104 . V_105 ++ ;
F_42 ( V_6 ) ;
F_72 ( V_101 ) ;
return V_106 ;
}
if ( V_49 -> V_28 == 0 ) {
F_47 ( V_6 ) ;
return V_107 ;
}
V_49 -> V_28 -- ;
F_73 ( & V_49 -> V_36 , V_101 ) ;
F_74 ( F_14 ( V_6 ) ) ;
if ( V_49 -> V_28 == 0 ) {
F_47 ( V_6 ) ;
}
return V_106 ;
}
static void F_74 ( struct V_7 * V_8 )
{
T_2 * V_49 = & V_8 -> V_25 ;
struct V_100 * V_101 ;
unsigned char V_108 ;
int V_109 ;
struct V_110 * V_111 ;
T_5 V_112 ;
unsigned long V_69 ;
int V_113 ;
F_2 ( L_28 ) ;
for (; ; ) {
V_101 = F_75 ( & V_49 -> V_36 ) ;
if ( ! V_101 ) {
F_2 ( L_29 ) ;
return;
}
F_58 ( & V_49 -> V_50 , V_69 ) ;
V_108 = V_101 -> V_95 [ 0 ] ;
V_109 = ( V_108 & V_114 ) ? V_115 : V_116 ;
#ifdef F_76
if ( ( V_108 & ~ ( V_114 | V_117 ) ) == V_118 ) {
if ( ! V_8 -> V_119 . V_120 )
V_108 &= ~ V_114 ;
else {
if ( V_8 -> V_121 . V_122 ) {
V_108 |= V_114 ;
}
}
}
#endif
V_113 = F_77 ( V_8 , V_108 , 1 , V_101 -> V_94 , V_109 ) ;
if ( ( V_113 & ( V_123 | V_124 ) ) == 0 ) {
if ( ( V_113 & V_125 ) != 0 ) {
F_2 ( L_30 ) ;
} else if ( ( V_113 & V_126 ) != 0 ) {
F_2 ( L_31 , V_49 -> V_6 -> V_41 ) ;
} else {
F_2 ( L_32 ,
V_49 -> V_6 -> V_41 ) ;
}
F_78 ( & V_49 -> V_36 , V_101 ) ;
F_60 ( & V_49 -> V_50 , V_69 ) ;
return;
}
V_49 -> V_28 ++ ;
F_79 ( V_101 -> V_95 , V_8 -> V_32 . V_53 . V_54 ) ;
V_111 = (struct V_110 * ) F_80 ( V_8 , V_109 ) ;
V_112 = F_81 ( & V_49 -> V_2 , V_101 -> V_95 ,
V_101 -> V_94 , V_127 ) ;
if ( V_113 & V_124 ) {
V_111 -> V_128 . V_101 = V_101 ;
V_111 -> V_128 . V_129 = V_112 ;
}
F_82 ( V_8 , V_101 -> V_95 , V_112 , V_101 -> V_94 ,
V_113 | V_130 | V_131 | V_132 ) ;
if ( ! ( V_113 & V_124 ) ) {
F_83 ( & V_49 -> V_2 , V_112 ,
V_101 -> V_94 , V_127 ) ;
F_84 ( V_101 ) ;
}
F_60 ( & V_49 -> V_50 , V_69 ) ;
}
return;
}
static void F_79 ( unsigned char * V_133 , unsigned char * V_134 )
{
unsigned char V_135 ;
if ( ( ( ( unsigned long ) V_133 [ 1 + 6 ] ) & ~ 0x01 ) != 0 )
return;
if ( ( unsigned short ) V_133 [ 1 + 10 ] != 0 )
return;
V_135 = V_133 [ 1 + 6 ] & 0x01 ;
memcpy ( & V_133 [ 1 + 6 ] , V_134 , V_56 ) ;
V_133 [ 8 ] |= V_135 ;
}
static void F_54 ( struct V_7 * V_8 )
{
F_2 ( L_33 ) ;
F_31 ( V_8 ) ;
F_45 ( V_8 ) ;
F_46 ( V_8 ) ;
F_34 ( V_8 , 1 ) ;
F_37 ( V_8 , ( V_8 -> V_25 . V_6 ) -> V_55 ) ;
F_38 ( V_8 , 1 ) ;
F_39 () ;
F_59 ( V_8 -> V_25 . V_6 ) ;
}
void F_85 ( struct V_7 * V_8 )
{
T_2 * V_49 = & V_8 -> V_25 ;
F_2 ( L_34 ) ;
F_55 ( & V_49 -> V_50 ) ;
F_74 ( V_8 ) ;
F_52 ( & V_49 -> V_50 ) ;
F_42 ( V_49 -> V_6 ) ;
}
void * F_86 ( struct V_7 * V_8 , unsigned int V_136 )
{
void * V_137 ;
F_2 ( L_35 , V_136 ) ;
V_137 = ( void * ) ( V_8 -> V_25 . V_42 + V_8 -> V_25 . V_52 ) ;
if ( ( V_8 -> V_25 . V_52 + V_136 ) > V_8 -> V_25 . V_43 ) {
F_3 ( L_36 , V_136 ) ;
return NULL ;
}
V_8 -> V_25 . V_52 += V_136 ;
F_2 ( L_37 ) ;
F_2 ( L_38 , ( V_138 ) V_137 ) ;
F_2 ( L_39 , ( V_138 )
( V_8 -> V_25 . V_44 +
( ( char * ) V_137 - ( char * ) V_8 -> V_25 . V_42 ) ) ) ;
return V_137 ;
}
void * F_87 ( struct V_7 * V_8 , unsigned int V_136 )
{
char * V_137 ;
F_2 ( L_40 ) ;
V_137 = F_86 ( V_8 , V_136 ) ;
V_136 = ( V_139 ) ( 16 - ( ( ( unsigned long ) V_137 ) & 15UL ) ) ;
V_136 = V_136 % 16 ;
F_2 ( L_41 , V_136 ) ;
F_2 ( L_42 ) ;
if ( ! F_86 ( V_8 , V_136 ) ) {
F_3 ( L_43 ) ;
return NULL ;
}
return V_137 + V_136 ;
}
unsigned long F_88 ( struct V_7 * V_8 , void * V_137 )
{
return V_8 -> V_25 . V_44 +
( ( char * ) V_137 - ( char * ) V_8 -> V_25 . V_42 ) ;
}
T_6 F_89 ( struct V_7 * V_8 , void * V_137 , int V_94 , int V_140 )
{
return V_8 -> V_25 . V_44 +
( ( char * ) V_137 - ( char * ) V_8 -> V_25 . V_42 ) ;
}
void F_90 ( struct V_7 * V_8 , volatile union V_141 * V_142 , int V_140 )
{
if ( V_140 & V_143 ) {
T_2 * V_49 = & V_8 -> V_25 ;
volatile struct V_144 * V_145 = & V_142 -> V_145 ;
if ( V_145 -> V_146 . V_101 && V_145 -> V_146 . V_129 ) {
int V_30 = V_49 -> V_30 ;
F_83 ( & V_49 -> V_2 , V_145 -> V_146 . V_129 ,
V_30 , V_147 ) ;
V_145 -> V_146 . V_129 = 0 ;
}
}
}
void F_91 ( struct V_7 * V_8 , volatile struct V_110 * V_111 )
{
struct V_100 * V_101 ;
F_2 ( L_44 ) ;
if ( ! ( V_101 = V_111 -> V_128 . V_101 ) ) {
F_2 ( L_45 ) ;
return;
}
V_111 -> V_128 . V_101 = NULL ;
F_83 ( & V_8 -> V_25 . V_2 , V_111 -> V_128 . V_129 ,
V_101 -> V_94 , V_127 ) ;
V_111 -> V_128 . V_129 = 0 ;
V_8 -> V_25 . V_67 . V_104 . V_148 ++ ;
V_8 -> V_25 . V_67 . V_104 . V_149 += V_101 -> V_94 ;
F_84 ( V_101 ) ;
F_2 ( L_46 ) ;
}
void F_92 ( unsigned char * V_150 , int V_151 )
{
int V_152 , V_153 ;
unsigned char V_154 [ 255 ] , V_155 [ 10 ] ;
if ( V_151 > 64 ) {
V_151 = 64 ;
}
F_3 ( V_156 L_47 ) ;
for ( V_152 = 0 , V_153 = 0 ; V_152 < V_151 / 8 ; V_152 ++ , V_153 += 8 )
F_3 ( V_156 L_48 ,
V_150 [ V_153 + 0 ] , V_150 [ V_153 + 1 ] , V_150 [ V_153 + 2 ] , V_150 [ V_153 + 3 ] ,
V_150 [ V_153 + 4 ] , V_150 [ V_153 + 5 ] , V_150 [ V_153 + 6 ] , V_150 [ V_153 + 7 ] ) ;
strcpy ( V_154 , L_49 ) ;
for ( V_152 = 0 ; V_152 < V_151 % 8 ; V_152 ++ ) {
sprintf ( V_155 , L_50 , V_150 [ V_153 + V_152 ] ) ;
strcat ( V_154 , V_155 ) ;
}
F_3 ( V_156 L_2 , V_154 ) ;
F_3 ( V_156 L_51 ) ;
}
void F_93 ( struct V_7 * V_8 , volatile struct V_144 * V_157 ,
int V_158 , int V_94 )
{
T_2 * V_49 = & V_8 -> V_25 ;
struct V_100 * V_101 ;
unsigned char * V_137 , * V_159 ;
unsigned short V_160 ;
V_139 V_161 ;
F_2 ( L_52 , V_94 ) ;
if ( V_158 != 1 ) {
F_3 ( L_53 ) ;
goto V_162;
}
V_101 = V_157 -> V_146 . V_101 ;
if ( ! V_101 ) {
F_2 ( L_54 ) ;
V_8 -> V_25 . V_67 . V_104 . V_163 ++ ;
goto V_162;
}
V_137 = V_101 -> V_95 ;
F_92 ( V_101 -> V_95 , V_94 ) ;
if ( ( V_137 [ 1 + 6 ] & V_164 ) == 0 )
V_161 = 0 ;
else {
int V_165 ;
F_2 ( L_55 ) ;
V_159 = V_137 + V_166 ;
V_160 = F_94 ( * ( ( V_167 * ) V_159 ) ) ;
V_161 = V_160 & V_168 ;
if ( V_94 < ( int ) ( V_166 + V_161 ) ) {
F_3 ( L_56 ) ;
goto V_162;
}
V_137 [ 1 + 6 ] &= ~ V_164 ;
V_137 = V_159 + V_161 ;
for ( V_165 = V_166 ; V_165 ; V_165 -- )
* -- V_137 = * -- V_159 ;
F_95 ( V_101 , V_161 ) ;
V_94 -= V_161 ;
V_161 = 0 ;
}
V_8 -> V_25 . V_67 . V_104 . V_169 ++ ;
V_8 -> V_25 . V_67 . V_104 . V_170 += V_94 ;
if ( V_137 [ 1 ] & 0x01 ) {
V_8 -> V_25 . V_67 . V_104 . V_171 ++ ;
}
V_157 -> V_146 . V_101 = NULL ;
F_96 ( V_101 , V_94 ) ;
V_101 -> V_172 = F_97 ( V_101 , V_49 -> V_6 ) ;
F_98 ( V_101 ) ;
F_99 ( V_8 , V_173 ) ;
return;
V_162:
F_2 ( L_57 ) ;
F_100 ( V_8 , V_157 , V_158 ) ;
V_8 -> V_25 . V_67 . V_104 . V_163 ++ ;
}
void F_100 ( struct V_7 * V_8 , volatile struct V_144 * V_157 ,
int V_158 )
{
volatile struct V_144 * V_174 ;
volatile struct V_144 * V_175 ;
struct V_100 * V_101 ;
int V_30 ;
unsigned char * V_176 ;
T_5 V_177 ;
if ( V_158 != 1 )
F_3 ( L_58 ) ;
V_30 = V_8 -> V_25 . V_30 ;
V_175 = V_157 ;
for (; V_158 > 0 ; V_158 -- ) {
V_174 = V_175 -> V_178 ;
V_157 = F_101 ( V_8 ) ;
V_101 = V_175 -> V_146 . V_101 ;
if ( V_101 == NULL ) {
F_2 ( L_59 ) ;
V_101 = F_102 ( V_30 + 3 , V_179 ) ;
if ( V_101 ) {
V_157 -> V_146 . V_101 = V_101 ;
F_103 ( V_101 , 3 ) ;
F_104 ( V_101 , V_30 ) ;
V_176 = V_101 -> V_95 ;
V_177 = F_81 ( & V_8 -> V_25 . V_2 ,
V_176 ,
V_30 ,
V_147 ) ;
V_157 -> V_146 . V_129 = V_177 ;
} else {
F_2 ( L_60 ) ;
V_157 -> V_146 . V_101 = NULL ;
V_176 = V_8 -> V_25 . V_45 ;
V_177 = V_8 -> V_25 . V_46 ;
}
} else {
V_157 -> V_146 . V_101 = V_101 ;
V_176 = V_101 -> V_95 ;
V_177 = F_81 ( & V_8 -> V_25 . V_2 ,
V_176 ,
V_30 ,
V_147 ) ;
V_157 -> V_146 . V_129 = V_177 ;
}
F_105 ( V_8 , V_176 , V_177 , V_30 ,
V_130 | V_131 ) ;
V_175 = V_174 ;
}
}
void F_106 ( struct V_7 * V_8 )
{
int V_30 ;
unsigned char * V_176 ;
unsigned long V_177 ;
struct V_100 * V_101 ;
volatile struct V_144 * V_157 ;
F_2 ( L_61 ) ;
V_30 = V_8 -> V_25 . V_30 ;
while ( F_107 ( V_8 ) > 0 ) {
F_2 ( L_62 ) ;
V_157 = F_101 ( V_8 ) ;
V_101 = F_102 ( V_30 + 3 , V_179 ) ;
if ( V_101 ) {
F_103 ( V_101 , 3 ) ;
F_104 ( V_101 , V_30 ) ;
V_176 = V_101 -> V_95 ;
V_177 = F_81 ( & V_8 -> V_25 . V_2 ,
V_176 ,
V_30 ,
V_147 ) ;
V_157 -> V_146 . V_129 = V_177 ;
} else {
F_2 ( L_60 ) ;
V_176 = V_8 -> V_25 . V_45 ;
V_177 = V_8 -> V_25 . V_46 ;
}
V_157 -> V_146 . V_101 = V_101 ;
F_105 ( V_8 , V_176 , V_177 , V_30 ,
V_130 | V_131 ) ;
}
F_2 ( L_63 ) ;
}
void F_108 ( struct V_7 * V_8 , volatile struct V_144 * V_157 ,
int V_158 )
{
struct V_100 * V_101 ;
F_2 ( L_64 ) ;
if ( V_158 != 1 )
F_3 ( L_65 ) ;
for (; V_158 > 0 ; V_158 -- ) {
V_101 = V_157 -> V_146 . V_101 ;
if ( V_101 != NULL ) {
T_2 * V_49 = & V_8 -> V_25 ;
int V_30 = V_49 -> V_30 ;
F_83 ( & V_49 -> V_2 , V_157 -> V_146 . V_129 ,
V_30 , V_147 ) ;
F_72 ( V_101 ) ;
V_157 -> V_146 . V_101 = NULL ;
}
V_157 = V_157 -> V_178 ;
}
}
int F_109 ( struct V_7 * V_8 , int V_94 , int V_108 ,
char * V_180 , int V_181 )
{
struct V_100 * V_101 ;
F_2 ( L_66 , V_94 ) ;
if ( V_94 != V_181 || V_94 < V_166 || ! V_180 ) {
F_2 ( L_67 ) ;
F_2 ( L_68 ,
V_94 , V_181 , ( unsigned long ) V_180 ) ;
return 0 ;
}
V_101 = F_102 ( V_94 + 3 , V_179 ) ;
if ( ! V_101 ) {
F_2 ( L_69 ) ;
return 0 ;
}
F_103 ( V_101 , 3 ) ;
F_104 ( V_101 , V_94 ) ;
F_110 ( V_101 , V_180 , V_94 ) ;
V_101 -> V_172 = F_97 ( V_101 , V_8 -> V_25 . V_6 ) ;
F_98 ( V_101 ) ;
return 0 ;
}
void F_111 ( struct V_7 * V_8 )
{
}
void F_112 ( struct V_7 * V_8 , T_6 V_90 )
{
F_2 ( L_70 ) ;
if ( V_90 & V_182 )
F_2 ( L_71 ) ;
if ( V_90 & V_183 )
F_2 ( L_72 ) ;
if ( V_90 & V_184 )
F_2 ( L_73 ) ;
if ( V_90 & V_185 )
F_2 ( L_74 ) ;
if ( V_90 & V_186 )
F_2 ( L_75 ) ;
if ( V_90 & V_187 )
F_2 ( L_76 ) ;
if ( V_90 & V_188 )
F_2 ( L_77 ) ;
if ( V_90 & V_189 )
F_2 ( L_78 ) ;
if ( V_90 & V_190 )
F_2 ( L_79 ) ;
if ( V_90 & V_191 )
F_2 ( L_80 ) ;
if ( V_90 & V_192 )
F_2 ( L_81 ) ;
if ( V_90 & V_193 )
F_2 ( L_82 ) ;
if ( V_90 & V_194 )
F_2 ( L_83 ) ;
if ( V_90 & V_195 )
F_2 ( L_84 ) ;
if ( V_90 & V_196 )
F_2 ( L_85 ) ;
if ( V_90 & V_197 )
F_2 ( L_86 ) ;
F_2 ( L_87 ) ;
}
unsigned long F_113 ( void )
{
return V_198 ;
}
void F_114 ( struct V_7 * V_8 , int V_199 )
{
F_2 ( L_88 ) ;
switch ( V_199 ) {
case 0 :
F_2 ( L_89 ) ;
break;
case 1 :
F_2 ( L_90 ) ;
V_8 -> V_25 . V_67 . V_104 . V_163 ++ ;
break;
default:
F_2 ( L_91 , V_199 ) ;
break;
}
}
void F_115 ( struct V_7 * V_8 , int V_200 )
{
#ifdef F_116
char * V_154 ;
switch ( V_200 ) {
case V_201 :
V_154 = L_92 ;
break;
case V_202 :
V_154 = L_93 ;
break;
case V_203 :
V_154 = L_94 ;
break;
case V_204 :
V_154 = L_95 ;
break;
case V_205 :
V_154 = L_96 ;
break;
case V_206 :
V_154 = L_97 ;
break;
case V_207 :
V_154 = L_98 ;
break;
case V_208 :
V_154 = L_99 ;
break;
case V_209 :
V_154 = L_100 ;
break;
default:
F_2 ( L_101 , V_200 ) ;
return;
}
F_2 ( L_102 , V_154 ) ;
#endif
}
void F_117 ( struct V_7 * V_8 , int V_210 )
{
#ifdef F_116
char * V_154 ;
switch ( V_210 ) {
case V_211 :
V_154 = L_103 ;
break;
case V_212 :
V_154 = L_104 ;
break;
case V_213 :
V_154 = L_105 ;
break;
case V_214 :
V_154 = L_106 ;
break;
case V_215 :
V_154 = L_107 ;
break;
case V_216 :
V_154 = L_108 ;
break;
case V_217 :
V_154 = L_109 ;
break;
case V_218 :
V_154 = L_110 ;
break;
default:
V_154 = L_111 ;
break;
}
F_2 ( L_112 , V_154 ) ;
#endif
}
void F_118 ( struct V_7 * V_8 , int V_219 )
{
#ifdef F_116
char * V_154 ;
switch ( V_219 ) {
case V_220 :
V_154 = L_113 ;
break;
case V_221 :
V_154 = L_114 ;
break;
case V_222 :
V_154 = L_115 ;
break;
case V_223 :
V_154 = L_116 ;
break;
case V_224 :
V_154 = L_117 ;
break;
case V_225 :
V_154 = L_118 ;
break;
case V_226 :
V_154 = L_119 ;
break;
case V_227 :
V_154 = L_120 ;
break;
default:
V_154 = L_111 ;
break;
}
F_2 ( L_121 , V_154 ) ;
#endif
}
void F_119 ( struct V_7 * V_8 )
{
F_2 ( L_122 ) ;
V_8 -> V_25 . V_35 = TRUE ;
}
