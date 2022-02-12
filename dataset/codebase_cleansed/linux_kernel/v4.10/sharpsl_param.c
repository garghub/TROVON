void sharpsl_save_param(void)
{
memcpy(&sharpsl_param, param_start(PARAM_BASE), sizeof(struct sharpsl_param_info));
if (sharpsl_param.comadj_keyword != COMADJ_MAGIC)
sharpsl_param.comadj=-1;
if (sharpsl_param.phad_keyword != PHAD_MAGIC)
sharpsl_param.phadadj=-1;
if (sharpsl_param.uuid_keyword != UUID_MAGIC)
sharpsl_param.uuid[0]=-1;
if (sharpsl_param.touch_keyword != TOUCH_MAGIC)
sharpsl_param.touch_xp=-1;
if (sharpsl_param.adadj_keyword != AD_MAGIC)
sharpsl_param.adadj=-1;
}
