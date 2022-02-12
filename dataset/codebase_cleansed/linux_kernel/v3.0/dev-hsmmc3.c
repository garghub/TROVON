void s3c_sdhci3_set_platdata(struct s3c_sdhci_platdata *pd)
{
struct s3c_sdhci_platdata *set = &s3c_hsmmc3_def_platdata;
set->cd_type = pd->cd_type;
set->ext_cd_init = pd->ext_cd_init;
set->ext_cd_cleanup = pd->ext_cd_cleanup;
set->ext_cd_gpio = pd->ext_cd_gpio;
set->ext_cd_gpio_invert = pd->ext_cd_gpio_invert;
if (pd->max_width)
set->max_width = pd->max_width;
if (pd->cfg_gpio)
set->cfg_gpio = pd->cfg_gpio;
if (pd->cfg_card)
set->cfg_card = pd->cfg_card;
if (pd->host_caps)
set->host_caps |= pd->host_caps;
if (pd->clk_type)
set->clk_type = pd->clk_type;
}
