static int otg_set_protocol(struct otg_fsm *fsm, int protocol)
{
int ret = 0;
if (fsm->protocol != protocol) {
VDBG("Changing role fsm->protocol= %d; new protocol= %d\n",
fsm->protocol, protocol);
if (fsm->protocol == PROTO_HOST)
ret = fsm->ops->start_host(fsm, 0);
else if (fsm->protocol == PROTO_GADGET)
ret = fsm->ops->start_gadget(fsm, 0);
if (ret)
return ret;
if (protocol == PROTO_HOST)
ret = fsm->ops->start_host(fsm, 1);
else if (protocol == PROTO_GADGET)
ret = fsm->ops->start_gadget(fsm, 1);
if (ret)
return ret;
fsm->protocol = protocol;
return 0;
}
return 0;
}
void otg_leave_state(struct otg_fsm *fsm, enum usb_otg_state old_state)
{
switch (old_state) {
case OTG_STATE_B_IDLE:
otg_del_timer(fsm, b_se0_srp_tmr);
fsm->b_se0_srp = 0;
break;
case OTG_STATE_B_SRP_INIT:
fsm->b_srp_done = 0;
break;
case OTG_STATE_B_PERIPHERAL:
break;
case OTG_STATE_B_WAIT_ACON:
otg_del_timer(fsm, b_ase0_brst_tmr);
fsm->b_ase0_brst_tmout = 0;
break;
case OTG_STATE_B_HOST:
break;
case OTG_STATE_A_IDLE:
break;
case OTG_STATE_A_WAIT_VRISE:
otg_del_timer(fsm, a_wait_vrise_tmr);
fsm->a_wait_vrise_tmout = 0;
break;
case OTG_STATE_A_WAIT_BCON:
otg_del_timer(fsm, a_wait_bcon_tmr);
fsm->a_wait_bcon_tmout = 0;
break;
case OTG_STATE_A_HOST:
otg_del_timer(fsm, a_wait_enum_tmr);
break;
case OTG_STATE_A_SUSPEND:
otg_del_timer(fsm, a_aidl_bdis_tmr);
fsm->a_aidl_bdis_tmout = 0;
fsm->a_suspend_req = 0;
break;
case OTG_STATE_A_PERIPHERAL:
break;
case OTG_STATE_A_WAIT_VFALL:
otg_del_timer(fsm, a_wait_vrise_tmr);
break;
case OTG_STATE_A_VBUS_ERR:
break;
default:
break;
}
}
int otg_set_state(struct otg_fsm *fsm, enum usb_otg_state new_state)
{
state_changed = 1;
if (fsm->otg->phy->state == new_state)
return 0;
VDBG("Set state: %s\n", otg_state_string(new_state));
otg_leave_state(fsm, fsm->otg->phy->state);
switch (new_state) {
case OTG_STATE_B_IDLE:
otg_drv_vbus(fsm, 0);
otg_chrg_vbus(fsm, 0);
otg_loc_conn(fsm, 0);
otg_loc_sof(fsm, 0);
otg_set_protocol(fsm, PROTO_UNDEF);
otg_add_timer(fsm, b_se0_srp_tmr);
break;
case OTG_STATE_B_SRP_INIT:
otg_start_pulse(fsm);
otg_loc_sof(fsm, 0);
otg_set_protocol(fsm, PROTO_UNDEF);
otg_add_timer(fsm, b_srp_fail_tmr);
break;
case OTG_STATE_B_PERIPHERAL:
otg_chrg_vbus(fsm, 0);
otg_loc_conn(fsm, 1);
otg_loc_sof(fsm, 0);
otg_set_protocol(fsm, PROTO_GADGET);
break;
case OTG_STATE_B_WAIT_ACON:
otg_chrg_vbus(fsm, 0);
otg_loc_conn(fsm, 0);
otg_loc_sof(fsm, 0);
otg_set_protocol(fsm, PROTO_HOST);
otg_add_timer(fsm, b_ase0_brst_tmr);
fsm->a_bus_suspend = 0;
break;
case OTG_STATE_B_HOST:
otg_chrg_vbus(fsm, 0);
otg_loc_conn(fsm, 0);
otg_loc_sof(fsm, 1);
otg_set_protocol(fsm, PROTO_HOST);
usb_bus_start_enum(fsm->otg->host,
fsm->otg->host->otg_port);
break;
case OTG_STATE_A_IDLE:
otg_drv_vbus(fsm, 0);
otg_chrg_vbus(fsm, 0);
otg_loc_conn(fsm, 0);
otg_loc_sof(fsm, 0);
otg_set_protocol(fsm, PROTO_HOST);
break;
case OTG_STATE_A_WAIT_VRISE:
otg_drv_vbus(fsm, 1);
otg_loc_conn(fsm, 0);
otg_loc_sof(fsm, 0);
otg_set_protocol(fsm, PROTO_HOST);
otg_add_timer(fsm, a_wait_vrise_tmr);
break;
case OTG_STATE_A_WAIT_BCON:
otg_drv_vbus(fsm, 1);
otg_loc_conn(fsm, 0);
otg_loc_sof(fsm, 0);
otg_set_protocol(fsm, PROTO_HOST);
otg_add_timer(fsm, a_wait_bcon_tmr);
break;
case OTG_STATE_A_HOST:
otg_drv_vbus(fsm, 1);
otg_loc_conn(fsm, 0);
otg_loc_sof(fsm, 1);
otg_set_protocol(fsm, PROTO_HOST);
if (!fsm->a_bus_req || fsm->a_suspend_req)
otg_add_timer(fsm, a_wait_enum_tmr);
break;
case OTG_STATE_A_SUSPEND:
otg_drv_vbus(fsm, 1);
otg_loc_conn(fsm, 0);
otg_loc_sof(fsm, 0);
otg_set_protocol(fsm, PROTO_HOST);
otg_add_timer(fsm, a_aidl_bdis_tmr);
break;
case OTG_STATE_A_PERIPHERAL:
otg_loc_conn(fsm, 1);
otg_loc_sof(fsm, 0);
otg_set_protocol(fsm, PROTO_GADGET);
otg_drv_vbus(fsm, 1);
break;
case OTG_STATE_A_WAIT_VFALL:
otg_drv_vbus(fsm, 0);
otg_loc_conn(fsm, 0);
otg_loc_sof(fsm, 0);
otg_set_protocol(fsm, PROTO_HOST);
break;
case OTG_STATE_A_VBUS_ERR:
otg_drv_vbus(fsm, 0);
otg_loc_conn(fsm, 0);
otg_loc_sof(fsm, 0);
otg_set_protocol(fsm, PROTO_UNDEF);
break;
default:
break;
}
fsm->otg->phy->state = new_state;
return 0;
}
int otg_statemachine(struct otg_fsm *fsm)
{
enum usb_otg_state state;
unsigned long flags;
spin_lock_irqsave(&fsm->lock, flags);
state = fsm->otg->phy->state;
state_changed = 0;
switch (state) {
case OTG_STATE_UNDEFINED:
VDBG("fsm->id = %d\n", fsm->id);
if (fsm->id)
otg_set_state(fsm, OTG_STATE_B_IDLE);
else
otg_set_state(fsm, OTG_STATE_A_IDLE);
break;
case OTG_STATE_B_IDLE:
if (!fsm->id)
otg_set_state(fsm, OTG_STATE_A_IDLE);
else if (fsm->b_sess_vld && fsm->otg->gadget)
otg_set_state(fsm, OTG_STATE_B_PERIPHERAL);
else if (fsm->b_bus_req && fsm->b_sess_end && fsm->b_se0_srp)
otg_set_state(fsm, OTG_STATE_B_SRP_INIT);
break;
case OTG_STATE_B_SRP_INIT:
if (!fsm->id || fsm->b_srp_done)
otg_set_state(fsm, OTG_STATE_B_IDLE);
break;
case OTG_STATE_B_PERIPHERAL:
if (!fsm->id || !fsm->b_sess_vld)
otg_set_state(fsm, OTG_STATE_B_IDLE);
else if (fsm->b_bus_req && fsm->otg->
gadget->b_hnp_enable && fsm->a_bus_suspend)
otg_set_state(fsm, OTG_STATE_B_WAIT_ACON);
break;
case OTG_STATE_B_WAIT_ACON:
if (fsm->a_conn)
otg_set_state(fsm, OTG_STATE_B_HOST);
else if (!fsm->id || !fsm->b_sess_vld)
otg_set_state(fsm, OTG_STATE_B_IDLE);
else if (fsm->a_bus_resume || fsm->b_ase0_brst_tmout) {
fsm->b_ase0_brst_tmout = 0;
otg_set_state(fsm, OTG_STATE_B_PERIPHERAL);
}
break;
case OTG_STATE_B_HOST:
if (!fsm->id || !fsm->b_sess_vld)
otg_set_state(fsm, OTG_STATE_B_IDLE);
else if (!fsm->b_bus_req || !fsm->a_conn)
otg_set_state(fsm, OTG_STATE_B_PERIPHERAL);
break;
case OTG_STATE_A_IDLE:
if (fsm->id)
otg_set_state(fsm, OTG_STATE_B_IDLE);
else if (!fsm->a_bus_drop && (fsm->a_bus_req || fsm->a_srp_det))
otg_set_state(fsm, OTG_STATE_A_WAIT_VRISE);
break;
case OTG_STATE_A_WAIT_VRISE:
if (fsm->id || fsm->a_bus_drop || fsm->a_vbus_vld ||
fsm->a_wait_vrise_tmout) {
otg_set_state(fsm, OTG_STATE_A_WAIT_BCON);
}
break;
case OTG_STATE_A_WAIT_BCON:
if (!fsm->a_vbus_vld)
otg_set_state(fsm, OTG_STATE_A_VBUS_ERR);
else if (fsm->b_conn)
otg_set_state(fsm, OTG_STATE_A_HOST);
else if (fsm->id | fsm->a_bus_drop | fsm->a_wait_bcon_tmout)
otg_set_state(fsm, OTG_STATE_A_WAIT_VFALL);
break;
case OTG_STATE_A_HOST:
if ((!fsm->a_bus_req || fsm->a_suspend_req) &&
fsm->otg->host->b_hnp_enable)
otg_set_state(fsm, OTG_STATE_A_SUSPEND);
else if (fsm->id || !fsm->b_conn || fsm->a_bus_drop)
otg_set_state(fsm, OTG_STATE_A_WAIT_BCON);
else if (!fsm->a_vbus_vld)
otg_set_state(fsm, OTG_STATE_A_VBUS_ERR);
break;
case OTG_STATE_A_SUSPEND:
if (!fsm->b_conn && fsm->otg->host->b_hnp_enable)
otg_set_state(fsm, OTG_STATE_A_PERIPHERAL);
else if (!fsm->b_conn && !fsm->otg->host->b_hnp_enable)
otg_set_state(fsm, OTG_STATE_A_WAIT_BCON);
else if (fsm->a_bus_req || fsm->b_bus_resume)
otg_set_state(fsm, OTG_STATE_A_HOST);
else if (fsm->id || fsm->a_bus_drop || fsm->a_aidl_bdis_tmout)
otg_set_state(fsm, OTG_STATE_A_WAIT_VFALL);
else if (!fsm->a_vbus_vld)
otg_set_state(fsm, OTG_STATE_A_VBUS_ERR);
break;
case OTG_STATE_A_PERIPHERAL:
if (fsm->id || fsm->a_bus_drop)
otg_set_state(fsm, OTG_STATE_A_WAIT_VFALL);
else if (fsm->b_bus_suspend)
otg_set_state(fsm, OTG_STATE_A_WAIT_BCON);
else if (!fsm->a_vbus_vld)
otg_set_state(fsm, OTG_STATE_A_VBUS_ERR);
break;
case OTG_STATE_A_WAIT_VFALL:
if (fsm->id || fsm->a_bus_req || (!fsm->a_sess_vld &&
!fsm->b_conn))
otg_set_state(fsm, OTG_STATE_A_IDLE);
break;
case OTG_STATE_A_VBUS_ERR:
if (fsm->id || fsm->a_bus_drop || fsm->a_clr_err)
otg_set_state(fsm, OTG_STATE_A_WAIT_VFALL);
break;
default:
break;
}
spin_unlock_irqrestore(&fsm->lock, flags);
VDBG("quit statemachine, changed = %d\n", state_changed);
return state_changed;
}
