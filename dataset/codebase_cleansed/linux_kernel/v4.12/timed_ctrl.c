void timed_ctrl_snd_commnd(
const timed_ctrl_ID_t ID,
hrt_data mask,
hrt_data condition,
hrt_data counter,
hrt_address addr,
hrt_data value)
{
OP___assert(ID == TIMED_CTRL0_ID);
OP___assert(TIMED_CTRL_BASE[ID] != (hrt_address)-1);
timed_ctrl_reg_store(ID, _HRT_TIMED_CONTROLLER_CMD_REG_IDX, mask);
timed_ctrl_reg_store(ID, _HRT_TIMED_CONTROLLER_CMD_REG_IDX, condition);
timed_ctrl_reg_store(ID, _HRT_TIMED_CONTROLLER_CMD_REG_IDX, counter);
timed_ctrl_reg_store(ID, _HRT_TIMED_CONTROLLER_CMD_REG_IDX, (hrt_data)addr);
timed_ctrl_reg_store(ID, _HRT_TIMED_CONTROLLER_CMD_REG_IDX, value);
}
void timed_ctrl_snd_sp_commnd(
const timed_ctrl_ID_t ID,
hrt_data mask,
hrt_data condition,
hrt_data counter,
const sp_ID_t SP_ID,
hrt_address offset,
hrt_data value)
{
OP___assert(SP_ID < N_SP_ID);
OP___assert(SP_DMEM_BASE[SP_ID] != (hrt_address)-1);
timed_ctrl_snd_commnd(ID, mask, condition, counter,
SP_DMEM_BASE[SP_ID]+offset, value);
}
void timed_ctrl_snd_gpio_commnd(
const timed_ctrl_ID_t ID,
hrt_data mask,
hrt_data condition,
hrt_data counter,
const gpio_ID_t GPIO_ID,
hrt_address offset,
hrt_data value)
{
OP___assert(GPIO_ID < N_GPIO_ID);
OP___assert(GPIO_BASE[GPIO_ID] != (hrt_address)-1);
timed_ctrl_snd_commnd(ID, mask, condition, counter,
GPIO_BASE[GPIO_ID]+offset, value);
}
