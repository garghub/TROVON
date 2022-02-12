int RAND_poll(void)
{
long pid, iosb[2];
int status = 0;
struct
{
short length, code;
long *buffer;
int *retlen;
} item[32], *pitem;
unsigned char data_buffer[256];
short total_length = 0;
struct items_data_st *pitems_data;
pitems_data = items_data;
pitem = item;
while (pitems_data->length)
{
pitem->length = pitems_data->length;
pitem->code = pitems_data->code;
pitem->buffer = (long *)data_buffer[total_length];
pitem->retlen = 0;
total_length += pitems_data->length;
pitems_data++;
pitem++;
}
pitem->length = pitem->code = 0;
pid = -1;
while ((status = sys$getjpiw(0, &pid, 0, item, iosb, 0, 0))
!= SS$_NOMOREPROC)
{
if (status == SS$_NORMAL)
{
RAND_add(data_buffer, total_length, total_length/2);
}
}
sys$gettim(iosb);
RAND_add((unsigned char *)iosb, sizeof(iosb), sizeof(iosb)/2);
return 1;
}
