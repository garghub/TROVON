const char *drbd_conn_str(enum drbd_conns s)
{
return s > C_BEHIND ? "TOO_LARGE" : drbd_conn_s_names[s];
}
const char *drbd_role_str(enum drbd_role s)
{
return s > R_SECONDARY ? "TOO_LARGE" : drbd_role_s_names[s];
}
const char *drbd_disk_str(enum drbd_disk_state s)
{
return s > D_UP_TO_DATE ? "TOO_LARGE" : drbd_disk_s_names[s];
}
const char *drbd_set_st_err_str(enum drbd_state_rv err)
{
return err <= SS_AFTER_LAST_ERROR ? "TOO_SMALL" :
err > SS_TWO_PRIMARIES ? "TOO_LARGE"
: drbd_state_sw_errors[-err];
}
