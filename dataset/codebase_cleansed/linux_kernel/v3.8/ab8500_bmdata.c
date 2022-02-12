int bmdevs_of_probe(struct device *dev, struct device_node *np,
struct abx500_bm_data **battery)
{
struct abx500_battery_type *btype;
struct device_node *np_bat_supply;
struct abx500_bm_data *bat;
const char *btech;
char bat_tech[8];
int i, thermistor;
*battery = &ab8500_bm_data;
np_bat_supply = of_parse_phandle(np, "battery", 0);
if (!np_bat_supply) {
dev_err(dev, "missing property battery\n");
return -EINVAL;
}
if (of_property_read_bool(np_bat_supply,
"thermistor-on-batctrl"))
thermistor = NTC_INTERNAL;
else
thermistor = NTC_EXTERNAL;
bat = *battery;
if (thermistor == NTC_EXTERNAL) {
bat->n_btypes = 4;
bat->bat_type = bat_type_ext_thermistor;
bat->adc_therm = ABx500_ADC_THERM_BATTEMP;
}
btech = of_get_property(np_bat_supply,
"stericsson,battery-type", NULL);
if (!btech) {
dev_warn(dev, "missing property battery-name/type\n");
strcpy(bat_tech, "UNKNOWN");
} else {
strcpy(bat_tech, btech);
}
if (strncmp(bat_tech, "LION", 4) == 0) {
bat->no_maintenance = true;
bat->chg_unknown_bat = true;
bat->bat_type[BATTERY_UNKNOWN].charge_full_design = 2600;
bat->bat_type[BATTERY_UNKNOWN].termination_vol = 4150;
bat->bat_type[BATTERY_UNKNOWN].recharge_vol = 4130;
bat->bat_type[BATTERY_UNKNOWN].normal_cur_lvl = 520;
bat->bat_type[BATTERY_UNKNOWN].normal_vol_lvl = 4200;
}
for (i = 0; i < bat->n_btypes; ++i) {
btype = (bat->bat_type + i);
if (thermistor == NTC_EXTERNAL) {
btype->batres_tbl =
temp_to_batres_tbl_ext_thermistor;
} else if (strncmp(bat_tech, "LION", 4) == 0) {
btype->batres_tbl =
temp_to_batres_tbl_9100;
} else {
btype->batres_tbl =
temp_to_batres_tbl_thermistor;
}
}
of_node_put(np_bat_supply);
return 0;
}
