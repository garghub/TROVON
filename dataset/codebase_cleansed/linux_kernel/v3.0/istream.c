void diva_xdi_provide_istream_info (ADAPTER* a,
diva_xdi_stream_interface_t* pi) {
pi->provided_service = 0;
}
int diva_istream_write (void* context,
int Id,
void* data,
int length,
int final,
byte usr1,
byte usr2) {
ADAPTER* a = (ADAPTER*)context;
int written = 0, to_write = -1;
char tmp[4];
byte* data_ptr = (byte*)data;
for (;;) {
a->ram_in_dw (a,
#ifdef PLATFORM_GT_32BIT
ULongToPtr(a->tx_stream[Id] + a->tx_pos[Id]),
#else
(void*)(a->tx_stream[Id] + a->tx_pos[Id]),
#endif
(dword*)&tmp[0],
1);
if (tmp[0] & DIVA_DFIFO_READY) {
if (to_write < 0)
return (-1);
break;
}
to_write = min(length, DIVA_DFIFO_DATA_SZ);
if (to_write) {
a->ram_out_buffer (a,
#ifdef PLATFORM_GT_32BIT
ULongToPtr(a->tx_stream[Id] + a->tx_pos[Id]+4),
#else
(void*)(a->tx_stream[Id] + a->tx_pos[Id] + 4),
#endif
data_ptr,
(word)to_write);
length -= to_write;
written += to_write;
data_ptr += to_write;
}
tmp[1] = (char)to_write;
tmp[0] = (tmp[0] & DIVA_DFIFO_WRAP) |
DIVA_DFIFO_READY |
((!length && final) ? DIVA_DFIFO_LAST : 0);
if (tmp[0] & DIVA_DFIFO_LAST) {
tmp[2] = usr1;
tmp[3] = usr2;
}
a->ram_out_dw (a,
#ifdef PLATFORM_GT_32BIT
ULongToPtr(a->tx_stream[Id] + a->tx_pos[Id]),
#else
(void*)(a->tx_stream[Id] + a->tx_pos[Id]),
#endif
(dword*)&tmp[0],
1);
if (tmp[0] & DIVA_DFIFO_WRAP) {
a->tx_pos[Id] = 0;
} else {
a->tx_pos[Id] += DIVA_DFIFO_STEP;
}
if (!length) {
break;
}
}
return (written);
}
int diva_istream_read (void* context,
int Id,
void* data,
int max_length,
int* final,
byte* usr1,
byte* usr2) {
ADAPTER* a = (ADAPTER*)context;
int read = 0, to_read = -1;
char tmp[4];
byte* data_ptr = (byte*)data;
*final = 0;
for (;;) {
a->ram_in_dw (a,
#ifdef PLATFORM_GT_32BIT
ULongToPtr(a->rx_stream[Id] + a->rx_pos[Id]),
#else
(void*)(a->rx_stream[Id] + a->rx_pos[Id]),
#endif
(dword*)&tmp[0],
1);
if (tmp[1] > max_length) {
if (to_read < 0)
return (-2);
break;
}
if (!(tmp[0] & DIVA_DFIFO_READY)) {
if (to_read < 0)
return (-1);
break;
}
to_read = min(max_length, (int)tmp[1]);
if (to_read) {
a->ram_in_buffer(a,
#ifdef PLATFORM_GT_32BIT
ULongToPtr(a->rx_stream[Id] + a->rx_pos[Id] + 4),
#else
(void*)(a->rx_stream[Id] + a->rx_pos[Id] + 4),
#endif
data_ptr,
(word)to_read);
max_length -= to_read;
read += to_read;
data_ptr += to_read;
}
if (tmp[0] & DIVA_DFIFO_LAST) {
*final = 1;
}
tmp[0] &= DIVA_DFIFO_WRAP;
a->ram_out_dw(a,
#ifdef PLATFORM_GT_32BIT
ULongToPtr(a->rx_stream[Id] + a->rx_pos[Id]),
#else
(void*)(a->rx_stream[Id] + a->rx_pos[Id]),
#endif
(dword*)&tmp[0],
1);
if (tmp[0] & DIVA_DFIFO_WRAP) {
a->rx_pos[Id] = 0;
} else {
a->rx_pos[Id] += DIVA_DFIFO_STEP;
}
if (*final) {
if (usr1)
*usr1 = tmp[2];
if (usr2)
*usr2 = tmp[3];
break;
}
}
return (read);
}
void pr_stream (ADAPTER * a) {
}
