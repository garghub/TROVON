enum i40iw_status_code i40iw_manage_vf_pble_bp(struct i40iw_sc_cqp *cqp,
struct i40iw_manage_vf_pble_info *info,
u64 scratch,
bool post_sq)
{
u64 *wqe;
u64 temp, header, pd_pl_pba = 0;
wqe = i40iw_sc_cqp_get_next_send_wqe(cqp, scratch);
if (!wqe)
return I40IW_ERR_RING_FULL;
temp = LS_64(info->pd_entry_cnt, I40IW_CQPSQ_MVPBP_PD_ENTRY_CNT) |
LS_64(info->first_pd_index, I40IW_CQPSQ_MVPBP_FIRST_PD_INX) |
LS_64(info->sd_index, I40IW_CQPSQ_MVPBP_SD_INX);
set_64bit_val(wqe, 16, temp);
header = LS_64((info->inv_pd_ent ? 1 : 0), I40IW_CQPSQ_MVPBP_INV_PD_ENT) |
LS_64(I40IW_CQP_OP_MANAGE_VF_PBLE_BP, I40IW_CQPSQ_OPCODE) |
LS_64(cqp->polarity, I40IW_CQPSQ_WQEVALID);
set_64bit_val(wqe, 24, header);
pd_pl_pba = LS_64(info->pd_pl_pba >> 3, I40IW_CQPSQ_MVPBP_PD_PLPBA);
set_64bit_val(wqe, 32, pd_pl_pba);
i40iw_debug_buf(cqp->dev, I40IW_DEBUG_WQE, "MANAGE VF_PBLE_BP WQE", wqe, I40IW_CQP_WQE_SIZE * 8);
if (post_sq)
i40iw_sc_cqp_post_sq(cqp);
return 0;
}
