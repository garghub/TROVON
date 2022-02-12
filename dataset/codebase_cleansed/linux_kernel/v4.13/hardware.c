const char *parisc_hardware_description(struct parisc_device_id *id)
{
struct hp_hardware *listptr;
for (listptr = hp_hardware_list; listptr->hw_type != HPHW_FAULTY; listptr++) {
if ((listptr->hw_type == id->hw_type) &&
(listptr->hversion == id->hversion) &&
(listptr->sversion == id->sversion)){
return listptr->name;
}
}
switch (id->hw_type) {
case HPHW_NPROC:
return "Unknown machine";
case HPHW_A_DIRECT:
switch (id->sversion) {
case 0x0D: return "MUX port";
case 0x0E: return "RS-232 port";
}
break;
case HPHW_MEMORY:
return "Memory";
}
return "unknown device";
}
enum cpu_type
parisc_get_cpu_type(unsigned long hversion)
{
struct hp_cpu_type_mask *ptr;
unsigned short model = ((unsigned short) (hversion)) >> 4;
for (ptr = hp_cpu_type_mask_list; 0 != ptr->mask; ptr++) {
if (ptr->model == (model & ptr->mask))
return ptr->cpu;
}
panic("could not identify CPU type\n");
return pcx;
}
