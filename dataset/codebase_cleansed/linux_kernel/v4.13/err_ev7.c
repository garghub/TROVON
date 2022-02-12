struct ev7_lf_subpackets *
ev7_collect_logout_frame_subpackets(struct el_subpacket *el_ptr,
struct ev7_lf_subpackets *lf_subpackets)
{
struct el_subpacket *subpacket;
int i;
if (el_ptr->class != EL_CLASS__HEADER ||
el_ptr->type != EL_TYPE__HEADER__LOGOUT_FRAME)
return NULL;
el_ptr = (struct el_subpacket *)
((unsigned long)el_ptr + el_ptr->length);
if (el_ptr->class != EL_CLASS__PAL ||
el_ptr->type != EL_TYPE__PAL__LOGOUT_FRAME)
return NULL;
lf_subpackets->logout = (struct ev7_pal_logout_subpacket *)
el_ptr->by_type.raw.data_start;
subpacket = (struct el_subpacket *)
((unsigned long)el_ptr + el_ptr->length);
for (i = 0;
subpacket && i < lf_subpackets->logout->subpacket_count;
subpacket = (struct el_subpacket *)
((unsigned long)subpacket + subpacket->length), i++) {
if (subpacket->class != EL_CLASS__PAL) {
printk("%s**UNEXPECTED SUBPACKET CLASS %d "
"IN LOGOUT FRAME (packet %d\n",
err_print_prefix, subpacket->class, i);
return NULL;
}
switch(subpacket->type) {
case EL_TYPE__PAL__EV7_PROCESSOR:
lf_subpackets->ev7 =
(struct ev7_pal_processor_subpacket *)
subpacket->by_type.raw.data_start;
break;
case EL_TYPE__PAL__EV7_RBOX:
lf_subpackets->rbox = (struct ev7_pal_rbox_subpacket *)
subpacket->by_type.raw.data_start;
break;
case EL_TYPE__PAL__EV7_ZBOX:
lf_subpackets->zbox = (struct ev7_pal_zbox_subpacket *)
subpacket->by_type.raw.data_start;
break;
case EL_TYPE__PAL__EV7_IO:
lf_subpackets->io = (struct ev7_pal_io_subpacket *)
subpacket->by_type.raw.data_start;
break;
case EL_TYPE__PAL__ENV__AMBIENT_TEMPERATURE:
case EL_TYPE__PAL__ENV__AIRMOVER_FAN:
case EL_TYPE__PAL__ENV__VOLTAGE:
case EL_TYPE__PAL__ENV__INTRUSION:
case EL_TYPE__PAL__ENV__POWER_SUPPLY:
case EL_TYPE__PAL__ENV__LAN:
case EL_TYPE__PAL__ENV__HOT_PLUG:
lf_subpackets->env[ev7_lf_env_index(subpacket->type)] =
(struct ev7_pal_environmental_subpacket *)
subpacket->by_type.raw.data_start;
break;
default:
return NULL;
}
}
return lf_subpackets;
}
void
ev7_machine_check(unsigned long vector, unsigned long la_ptr)
{
struct el_subpacket *el_ptr = (struct el_subpacket *)la_ptr;
char *saved_err_prefix = err_print_prefix;
mb();
draina();
err_print_prefix = KERN_CRIT;
printk("%s*CPU %s Error (Vector 0x%x) reported on CPU %d\n",
err_print_prefix,
(vector == SCB_Q_PROCERR) ? "Correctable" : "Uncorrectable",
(unsigned int)vector, (int)smp_processor_id());
el_process_subpacket(el_ptr);
err_print_prefix = saved_err_prefix;
wrmces(0x7);
mb();
}
static struct el_subpacket *
ev7_process_pal_subpacket(struct el_subpacket *header)
{
struct ev7_pal_subpacket *packet;
if (header->class != EL_CLASS__PAL) {
printk("%s ** Unexpected header CLASS %d TYPE %d, aborting\n",
err_print_prefix,
header->class, header->type);
return NULL;
}
packet = (struct ev7_pal_subpacket *)header->by_type.raw.data_start;
switch(header->type) {
case EL_TYPE__PAL__LOGOUT_FRAME:
printk("%s*** MCHK occurred on LPID %lld (RBOX %llx)\n",
err_print_prefix,
packet->by_type.logout.whami,
packet->by_type.logout.rbox_whami);
el_print_timestamp(&packet->by_type.logout.timestamp);
printk("%s EXC_ADDR: %016llx\n"
" HALT_CODE: %llx\n",
err_print_prefix,
packet->by_type.logout.exc_addr,
packet->by_type.logout.halt_code);
el_process_subpackets(header,
packet->by_type.logout.subpacket_count);
break;
default:
printk("%s ** PAL TYPE %d SUBPACKET\n",
err_print_prefix,
header->type);
el_annotate_subpacket(header);
break;
}
return (struct el_subpacket *)((unsigned long)header + header->length);
}
void __init
ev7_register_error_handlers(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(el_ev7_pal_annotations); i++)
cdl_register_subpacket_annotation(&el_ev7_pal_annotations[i]);
cdl_register_subpacket_handler(&ev7_pal_subpacket_handler);
}
