static s32 uuid_hex_to_bin(char *buf, s32 len)
{
s32 i;
s32 result = 0;
int value;
for (i = 0; i < len; i++) {
value = hex_to_bin(*buf++);
result *= 16;
if (value > 0)
result += value;
}
return result;
}
void uuid_uuid_from_string(char *sz_uuid, struct dsp_uuid *uuid_obj)
{
s32 j;
uuid_obj->data1 = uuid_hex_to_bin(sz_uuid, 8);
sz_uuid += 8;
sz_uuid++;
uuid_obj->data2 = (u16) uuid_hex_to_bin(sz_uuid, 4);
sz_uuid += 4;
sz_uuid++;
uuid_obj->data3 = (u16) uuid_hex_to_bin(sz_uuid, 4);
sz_uuid += 4;
sz_uuid++;
uuid_obj->data4 = (u8) uuid_hex_to_bin(sz_uuid, 2);
sz_uuid += 2;
uuid_obj->data5 = (u8) uuid_hex_to_bin(sz_uuid, 2);
sz_uuid += 2;
sz_uuid++;
for (j = 0; j < 6; j++) {
uuid_obj->data6[j] = (u8) uuid_hex_to_bin(sz_uuid, 2);
sz_uuid += 2;
}
}
