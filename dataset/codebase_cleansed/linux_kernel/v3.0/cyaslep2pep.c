static cy_as_return_status_t
find_endpoint_directions(cy_as_device *dev_p,
cy_as_physical_endpoint_state epstate[4])
{
int i;
cy_as_physical_endpoint_state desired;
for (i = 0; i < 10; i++) {
int epno = end_point_map[i];
if (dev_p->usb_config[epno].enabled) {
int pep = dev_p->usb_config[epno].physical;
if (dev_p->usb_config[epno].type == cy_as_usb_iso) {
if (dev_p->usb_config[epno].dir == cy_as_usb_in)
desired = cy_as_e_p_iso_in;
else
desired = cy_as_e_p_iso_out;
} else {
if (dev_p->usb_config[epno].dir == cy_as_usb_in)
desired = cy_as_e_p_in;
else
desired = cy_as_e_p_out;
}
if (epstate[pep - 1] !=
cy_as_e_p_free && epstate[pep - 1] != desired)
return CY_AS_ERROR_INVALID_CONFIGURATION;
epstate[pep - 1] = desired;
}
}
dev_p->usb_ep1cfg[0] = 0;
dev_p->usb_ep1cfg[1] = 0;
if (dev_p->usb_config[1].enabled) {
if ((dev_p->usb_config[1].dir == cy_as_usb_out) ||
(dev_p->usb_config[1].dir == cy_as_usb_in_out)) {
dev_p->usb_ep1cfg[0] = (1 << 7);
if (dev_p->usb_config[1].type == cy_as_usb_bulk)
dev_p->usb_ep1cfg[0] |= (2 << 4);
else
dev_p->usb_ep1cfg[0] |= (3 << 4);
}
if ((dev_p->usb_config[1].dir == cy_as_usb_in) ||
(dev_p->usb_config[1].dir == cy_as_usb_in_out)) {
dev_p->usb_ep1cfg[1] = (1 << 7);
if (dev_p->usb_config[1].type == cy_as_usb_bulk)
dev_p->usb_ep1cfg[1] |= (2 << 4);
else
dev_p->usb_ep1cfg[1] |= (3 << 4);
}
}
return CY_AS_ERROR_SUCCESS;
}
static void
create_register_settings(cy_as_device *dev_p,
cy_as_physical_endpoint_state epstate[4])
{
int i;
uint8_t v;
for (i = 0; i < 4; i++) {
if (i == 0) {
dev_p->usb_pepcfg[i] =
pep_register_values
[dev_p->usb_phy_config - 1][0];
} else if (i == 2) {
dev_p->usb_pepcfg[i] =
pep_register_values
[dev_p->usb_phy_config - 1][1];
} else
dev_p->usb_pepcfg[i] = 0;
if (epstate[i] == cy_as_e_p_iso_in ||
epstate[i] == cy_as_e_p_in)
dev_p->usb_pepcfg[i] |= (1 << 6);
}
for (i = 0; i < 10; i++) {
int val;
int epnum = end_point_map[i];
v = 0x10;
if (dev_p->usb_config[epnum].enabled) {
v |= (1 << 7);
val = dev_p->usb_config[epnum].physical - 1;
cy_as_hal_assert(val >= 0 && val <= 3);
v |= (val << 5);
switch (dev_p->usb_config[epnum].type) {
case cy_as_usb_bulk:
val = 2;
break;
case cy_as_usb_int:
val = 3;
break;
case cy_as_usb_iso:
val = 1;
break;
default:
cy_as_hal_assert(cy_false);
break;
}
v |= (val << 3);
}
dev_p->usb_lepcfg[i] = v;
}
}
cy_as_return_status_t
cy_as_usb_map_logical2_physical(cy_as_device *dev_p)
{
cy_as_return_status_t ret;
cy_as_physical_endpoint_state epstate[4] = {
cy_as_e_p_free, cy_as_e_p_free,
cy_as_e_p_free, cy_as_e_p_free };
ret = find_endpoint_directions(dev_p, epstate);
if (ret != CY_AS_ERROR_SUCCESS)
return ret;
create_register_settings(dev_p, epstate);
return ret;
}
static uint16_t
get_max_dma_size(cy_as_device *dev_p, cy_as_end_point_number_t ep)
{
uint16_t size = dev_p->usb_config[ep].size;
if (size == 0) {
switch (dev_p->usb_config[ep].type) {
case cy_as_usb_control:
size = 64;
break;
case cy_as_usb_bulk:
size = cy_as_device_is_usb_high_speed(dev_p) ?
512 : 64;
break;
case cy_as_usb_int:
size = cy_as_device_is_usb_high_speed(dev_p) ?
1024 : 64;
break;
case cy_as_usb_iso:
size = cy_as_device_is_usb_high_speed(dev_p) ?
1024 : 1023;
break;
}
}
return size;
}
cy_as_return_status_t
cy_as_usb_set_dma_sizes(cy_as_device *dev_p)
{
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
uint32_t i;
for (i = 0; i < 10; i++) {
cy_as_usb_end_point_config *config_p =
&dev_p->usb_config[end_point_map[i]];
if (config_p->enabled) {
ret = cy_as_dma_set_max_dma_size(dev_p,
end_point_map[i],
get_max_dma_size(dev_p, end_point_map[i]));
if (ret != CY_AS_ERROR_SUCCESS)
break;
}
}
return ret;
}
cy_as_return_status_t
cy_as_usb_setup_dma(cy_as_device *dev_p)
{
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
uint32_t i;
for (i = 0; i < 10; i++) {
cy_as_usb_end_point_config *config_p =
&dev_p->usb_config[end_point_map[i]];
if (config_p->enabled) {
cy_as_dma_direction dir = cy_as_direction_out;
if (config_p->dir == cy_as_usb_in)
dir = cy_as_direction_in;
ret = cy_as_dma_enable_end_point(dev_p,
end_point_map[i], cy_true, dir);
if (ret != CY_AS_ERROR_SUCCESS)
break;
}
}
return ret;
}
