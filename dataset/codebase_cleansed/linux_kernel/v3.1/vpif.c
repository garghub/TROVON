static inline void vpif_wr_bit(u32 reg, u32 bit, u32 val)
{
if (val)
vpif_set_bit(reg, bit);
else
vpif_clr_bit(reg, bit);
}
static void vpif_set_mode_info(const struct vpif_channel_config_params *config,
u8 channel_id, u8 config_channel_id)
{
u32 value;
value = (config->eav2sav & vpifregs[config_channel_id].width_mask);
value <<= VPIF_CH_LEN_SHIFT;
value |= (config->sav2eav & vpifregs[config_channel_id].width_mask);
regw(value, vpifregs[channel_id].h_cfg);
value = (config->l1 & vpifregs[config_channel_id].len_mask);
value <<= VPIF_CH_LEN_SHIFT;
value |= (config->l3 & vpifregs[config_channel_id].len_mask);
regw(value, vpifregs[channel_id].v_cfg_00);
value = (config->l5 & vpifregs[config_channel_id].len_mask);
value <<= VPIF_CH_LEN_SHIFT;
value |= (config->l7 & vpifregs[config_channel_id].len_mask);
regw(value, vpifregs[channel_id].v_cfg_01);
value = (config->l9 & vpifregs[config_channel_id].len_mask);
value <<= VPIF_CH_LEN_SHIFT;
value |= (config->l11 & vpifregs[config_channel_id].len_mask);
regw(value, vpifregs[channel_id].v_cfg_02);
value = (config->vsize & vpifregs[config_channel_id].len_mask);
regw(value, vpifregs[channel_id].v_cfg);
}
static void config_vpif_params(struct vpif_params *vpifparams,
u8 channel_id, u8 found)
{
const struct vpif_channel_config_params *config = &vpifparams->std_info;
u32 value, ch_nip, reg;
u8 start, end;
int i;
start = channel_id;
end = channel_id + found;
for (i = start; i < end; i++) {
reg = vpifregs[i].ch_ctrl;
if (channel_id < 2)
ch_nip = VPIF_CAPTURE_CH_NIP;
else
ch_nip = VPIF_DISPLAY_CH_NIP;
vpif_wr_bit(reg, ch_nip, config->frm_fmt);
vpif_wr_bit(reg, VPIF_CH_YC_MUX_BIT, config->ycmux_mode);
vpif_wr_bit(reg, VPIF_CH_INPUT_FIELD_FRAME_BIT,
vpifparams->video_params.storage_mode);
vpif_clr_bit(reg, VPIF_CH_SDR_FMT_BIT);
vpif_wr_bit(reg, VPIF_CH_DATA_MODE_BIT, config->capture_format);
if (channel_id > 1)
vpif_set_bit(reg, VPIF_DISPLAY_PIX_EN_BIT);
else if (config->capture_format) {
vpif_wr_bit(reg, VPIF_CH_FID_POLARITY_BIT,
vpifparams->iface.fid_pol);
vpif_wr_bit(reg, VPIF_CH_V_VALID_POLARITY_BIT,
vpifparams->iface.vd_pol);
vpif_wr_bit(reg, VPIF_CH_H_VALID_POLARITY_BIT,
vpifparams->iface.hd_pol);
value = regr(reg);
value &= ((~(unsigned int)(0x3)) <<
VPIF_CH_DATA_WIDTH_BIT);
value |= ((vpifparams->params.data_sz) <<
VPIF_CH_DATA_WIDTH_BIT);
regw(value, reg);
}
regw((vpifparams->video_params.hpitch),
vpifregs[i].line_offset);
}
}
int vpif_set_video_params(struct vpif_params *vpifparams, u8 channel_id)
{
const struct vpif_channel_config_params *config = &vpifparams->std_info;
int found = 1;
vpif_set_mode_info(config, channel_id, channel_id);
if (!config->ycmux_mode) {
vpif_set_mode_info(config, channel_id + 1, channel_id);
found = 2;
}
config_vpif_params(vpifparams, channel_id, found);
regw(0x80, VPIF_REQ_SIZE);
regw(0x01, VPIF_EMULATION_CTRL);
return found;
}
void vpif_set_vbi_display_params(struct vpif_vbi_params *vbiparams,
u8 channel_id)
{
u32 value;
value = 0x3F8 & (vbiparams->hstart0);
value |= 0x3FFFFFF & ((vbiparams->vstart0) << 16);
regw(value, vpifregs[channel_id].vanc0_strt);
value = 0x3F8 & (vbiparams->hstart1);
value |= 0x3FFFFFF & ((vbiparams->vstart1) << 16);
regw(value, vpifregs[channel_id].vanc1_strt);
value = 0x3F8 & (vbiparams->hsize0);
value |= 0x3FFFFFF & ((vbiparams->vsize0) << 16);
regw(value, vpifregs[channel_id].vanc0_size);
value = 0x3F8 & (vbiparams->hsize1);
value |= 0x3FFFFFF & ((vbiparams->vsize1) << 16);
regw(value, vpifregs[channel_id].vanc1_size);
}
int vpif_channel_getfid(u8 channel_id)
{
return (regr(vpifregs[channel_id].ch_ctrl) & VPIF_CH_FID_MASK)
>> VPIF_CH_FID_SHIFT;
}
static int __init vpif_probe(struct platform_device *pdev)
{
int status = 0;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENOENT;
res_len = resource_size(res);
res = request_mem_region(res->start, res_len, res->name);
if (!res)
return -EBUSY;
vpif_base = ioremap(res->start, res_len);
if (!vpif_base) {
status = -EBUSY;
goto fail;
}
spin_lock_init(&vpif_lock);
dev_info(&pdev->dev, "vpif probe success\n");
return 0;
fail:
release_mem_region(res->start, res_len);
return status;
}
static int __devexit vpif_remove(struct platform_device *pdev)
{
iounmap(vpif_base);
release_mem_region(res->start, res_len);
return 0;
}
static void vpif_exit(void)
{
platform_driver_unregister(&vpif_driver);
}
static int __init vpif_init(void)
{
return platform_driver_register(&vpif_driver);
}
