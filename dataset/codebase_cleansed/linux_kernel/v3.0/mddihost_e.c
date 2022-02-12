void mddi_host_start_ext_display(void)
{
down(&mddi_host_mutex);
if (!mddi_host_ext_powered) {
mddi_host_init(MDDI_HOST_EXT);
mddi_host_ext_powered = TRUE;
}
up(&mddi_host_mutex);
}
void mddi_host_stop_ext_display(void)
{
down(&mddi_host_mutex);
if (mddi_host_ext_powered) {
mddi_host_powerdown(MDDI_HOST_EXT);
mddi_host_ext_powered = FALSE;
}
up(&mddi_host_mutex);
}
