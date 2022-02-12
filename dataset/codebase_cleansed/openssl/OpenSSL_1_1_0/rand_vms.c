int RAND_poll(void)
{
struct items_data_st item_entry;
int item_entry_count = sizeof(items_data)/sizeof(item_entry);
struct {
short length, code;
int *buffer;
int *retlen;
} item[item_entry_count], *pitem;
struct items_data_st *pitems_data;
int data_buffer[(item_entry_count*2)+4];
int iosb[2];
int sys_time[2];
int *ptr;
int i, j ;
int tmp_length = 0;
int total_length = 0;
pitems_data = items_data;
pitem = item;
while (pitems_data->length) {
pitem->length = pitems_data->length;
pitem->code = pitems_data->code;
pitem->buffer = &data_buffer[total_length];
pitem->retlen = 0;
total_length += pitems_data->length/4;
pitems_data++;
pitem ++;
}
pitem->length = pitem->code = 0;
if (sys$getjpiw(EFN$C_ENF, NULL, NULL, item, &iosb, 0, 0) == SS$_NORMAL) {
for (i = 0; i < total_length; i++) {
sys$gettim((struct _generic_64 *)&sys_time[0]);
srand(sys_time[0] * data_buffer[0] * data_buffer[1] + i);
if (i == (total_length - 1)) {
ptr = &data_buffer[i];
for (j = 0; j < 4; j++) {
data_buffer[i + j] = ptr[j];
data_buffer[i + j] ^= (sys_time[0] ^ rand());
tmp_length++;
}
} else {
data_buffer[i] ^= (sys_time[0] ^ rand());
}
}
total_length += (tmp_length - 1);
RAND_add((PTR_T) data_buffer, total_length*4, total_length * 2);
} else {
return 0;
}
return 1;
}
