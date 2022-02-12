static DH *get_dh512(void)
{
DH *dh=NULL;
if ((dh=DH_new()) == NULL) return(NULL);
dh->p=BN_bin2bn(dh512_p,sizeof(dh512_p),NULL);
dh->g=BN_bin2bn(dh512_g,sizeof(dh512_g),NULL);
if ((dh->p == NULL) || (dh->g == NULL))
return(NULL);
return(dh);
}
static int usage(const char *errstr, int isunknownarg)
{
if(isunknownarg)
fprintf(stderr, "Error: unknown argument '%s'\n", errstr);
else
fprintf(stderr, "Error: %s\n", errstr);
fprintf(stderr, "%s\n", helpstring);
return 1;
}
static int err_str0(const char *str0)
{
fprintf(stderr, "%s\n", str0);
return 1;
}
static int err_str1(const char *fmt, const char *str1)
{
fprintf(stderr, fmt, str1);
fprintf(stderr, "\n");
return 1;
}
static int parse_max_tunnels(const char *s, unsigned int *maxtunnels)
{
unsigned long l;
if(!int_strtoul(s, &l) || (l < 1) || (l > 1024)) {
fprintf(stderr, "Error, '%s' is an invalid value for "
"maxtunnels\n", s);
return 0;
}
*maxtunnels = (unsigned int)l;
return 1;
}
static int parse_server_mode(const char *s, int *servermode)
{
unsigned long l;
if(!int_strtoul(s, &l) || (l > 1)) {
fprintf(stderr, "Error, '%s' is an invalid value for the "
"server mode\n", s);
return 0;
}
*servermode = (int)l;
return 1;
}
static int parse_dh_special(const char *s, const char **dh_special)
{
if((strcmp(s, "NULL") == 0) || (strcmp(s, "generate") == 0) ||
(strcmp(s, "standard") == 0)) {
*dh_special = s;
return 1;
}
fprintf(stderr, "Error, '%s' is an invalid value for 'dh_special'\n", s);
return 0;
}
static int parse_verify_level(const char *s, unsigned int *verify_level)
{
unsigned long l;
if(!int_strtoul(s, &l) || (l > 3)) {
fprintf(stderr, "Error, '%s' is an invalid value for "
"out_verify\n", s);
return 0;
}
*verify_level = (unsigned int)l;
return 1;
}
static int parse_verify_depth(const char *s, unsigned int *verify_depth)
{
unsigned long l;
if(!int_strtoul(s, &l) || (l < 1) || (l > 50)) {
fprintf(stderr, "Error, '%s' is an invalid value for "
"verify_depth\n", s);
return 0;
}
*verify_depth = (unsigned int)l;
return 1;
}
static void tunala_world_del_item(tunala_world_t *world, unsigned int idx)
{
tunala_item_t *item = world->tunnels + idx;
if(item->clean_read != -1)
close(item->clean_read);
if(item->clean_send != item->clean_read)
close(item->clean_send);
item->clean_read = item->clean_send = -1;
if(item->dirty_read != -1)
close(item->dirty_read);
if(item->dirty_send != item->dirty_read)
close(item->dirty_send);
item->dirty_read = item->dirty_send = -1;
state_machine_close(&item->sm);
if(idx + 1 < world->tunnels_used)
memmove(world->tunnels + idx,
world->tunnels + (idx + 1),
(world->tunnels_used - (idx + 1)) *
sizeof(tunala_item_t));
world->tunnels_used--;
}
static int tunala_item_io(tunala_selector_t *selector, tunala_item_t *item)
{
int c_r, c_s, d_r, d_s;
if((item->clean_read != -1) && FD_ISSET(item->clean_read,
&selector->last_selected.excepts))
return 0;
if((item->clean_send != -1) && FD_ISSET(item->clean_send,
&selector->last_selected.excepts))
return 0;
if((item->dirty_read != -1) && FD_ISSET(item->dirty_read,
&selector->last_selected.excepts))
return 0;
if((item->dirty_send != -1) && FD_ISSET(item->dirty_send,
&selector->last_selected.excepts))
return 0;
c_r = c_s = d_r = d_s = 0;
if(item->clean_read != -1)
c_r = FD_ISSET(item->clean_read, &selector->last_selected.reads);
if(item->clean_send != -1)
c_s = FD_ISSET(item->clean_send, &selector->last_selected.sends);
if(item->dirty_read != -1)
d_r = FD_ISSET(item->dirty_read, &selector->last_selected.reads);
if(item->dirty_send != -1)
d_s = FD_ISSET(item->dirty_send, &selector->last_selected.sends);
if(!c_r && !c_s && !d_r && !d_s)
return 1;
if(c_r)
c_r = (buffer_from_fd(state_machine_get_buffer(&item->sm,
SM_CLEAN_IN), item->clean_read) <= 0);
if(c_s)
c_s = (buffer_to_fd(state_machine_get_buffer(&item->sm,
SM_CLEAN_OUT), item->clean_send) <= 0);
if(d_r)
d_r = (buffer_from_fd(state_machine_get_buffer(&item->sm,
SM_DIRTY_IN), item->dirty_read) <= 0);
if(d_s)
d_s = (buffer_to_fd(state_machine_get_buffer(&item->sm,
SM_DIRTY_OUT), item->dirty_send) <= 0);
if(c_r) {
close(item->clean_read);
if(item->clean_send == item->clean_read)
item->clean_send = -1;
item->clean_read = -1;
}
if(c_s && (item->clean_send != -1)) {
close(item->clean_send);
if(item->clean_send == item->clean_read)
item->clean_read = -1;
item->clean_send = -1;
}
if(d_r) {
close(item->dirty_read);
if(item->dirty_send == item->dirty_read)
item->dirty_send = -1;
item->dirty_read = -1;
}
if(d_s && (item->dirty_send != -1)) {
close(item->dirty_send);
if(item->dirty_send == item->dirty_read)
item->dirty_read = -1;
item->dirty_send = -1;
}
if(!state_machine_churn(&item->sm))
return 0;
if(((item->clean_read == -1) || (item->clean_send == -1)) &&
((item->dirty_read == -1) || (item->dirty_send == -1)))
return 0;
if((item->clean_read == -1) || (item->clean_send == -1)) {
if(!state_machine_close_clean(&item->sm))
return 0;
}
if((item->dirty_read == -1) || (item->dirty_send == -1)) {
if(!state_machine_close_dirty(&item->sm))
return 0;
}
return 1;
}
