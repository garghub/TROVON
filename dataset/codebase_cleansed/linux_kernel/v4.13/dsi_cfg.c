const struct msm_dsi_cfg_handler *msm_dsi_cfg_get(u32 major, u32 minor)
{
const struct msm_dsi_cfg_handler *cfg_hnd = NULL;
int i;
for (i = ARRAY_SIZE(dsi_cfg_handlers) - 1; i >= 0; i--) {
if ((dsi_cfg_handlers[i].major == major) &&
(dsi_cfg_handlers[i].minor == minor)) {
cfg_hnd = &dsi_cfg_handlers[i];
break;
}
}
return cfg_hnd;
}
