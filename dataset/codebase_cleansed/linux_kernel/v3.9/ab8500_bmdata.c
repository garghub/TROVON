int ab8500_bm_of_probe(struct device *dev,
struct device_node *np,
struct abx500_bm_data *bm)
{
struct batres_vs_temp *tmp_batres_tbl;
struct device_node *battery_node;
const char *btech;
int i;
battery_node = of_parse_phandle(np, "battery", 0);
if (!battery_node) {
dev_err(dev, "battery node or reference missing\n");
return -EINVAL;
}
btech = of_get_property(battery_node, "stericsson,battery-type", NULL);
if (!btech) {
dev_warn(dev, "missing property battery-name/type\n");
return -EINVAL;
}
if (strncmp(btech, "LION", 4) == 0) {
bm->no_maintenance = true;
bm->chg_unknown_bat = true;
bm->bat_type[BATTERY_UNKNOWN].charge_full_design = 2600;
bm->bat_type[BATTERY_UNKNOWN].termination_vol = 4150;
bm->bat_type[BATTERY_UNKNOWN].recharge_cap = 95;
bm->bat_type[BATTERY_UNKNOWN].normal_cur_lvl = 520;
bm->bat_type[BATTERY_UNKNOWN].normal_vol_lvl = 4200;
}
if (of_property_read_bool(battery_node, "thermistor-on-batctrl")) {
if (strncmp(btech, "LION", 4) == 0)
tmp_batres_tbl = temp_to_batres_tbl_9100;
else
tmp_batres_tbl = temp_to_batres_tbl_thermistor;
} else {
bm->n_btypes = 4;
bm->bat_type = bat_type_ext_thermistor;
bm->adc_therm = ABx500_ADC_THERM_BATTEMP;
tmp_batres_tbl = temp_to_batres_tbl_ext_thermistor;
}
for (i = 0; i < bm->n_btypes; ++i)
bm->bat_type[i].batres_tbl = tmp_batres_tbl;
of_node_put(battery_node);
return 0;
}
