static int twinhan_input_mapping(struct hid_device *hdev, struct hid_input *hi,
struct hid_field *field, struct hid_usage *usage,
unsigned long **bit, int *max)
{
if ((usage->hid & HID_USAGE_PAGE) != HID_UP_KEYBOARD)
return 0;
switch (usage->hid & HID_USAGE) {
case 0x004: th_map_key_clear(KEY_TEXT); break;
case 0x006: th_map_key_clear(KEY_RESTART); break;
case 0x008: th_map_key_clear(KEY_EPG); break;
case 0x00c: th_map_key_clear(KEY_REWIND); break;
case 0x00e: th_map_key_clear(KEY_PROGRAM); break;
case 0x00f: th_map_key_clear(KEY_LIST); break;
case 0x010: th_map_key_clear(KEY_MUTE); break;
case 0x011: th_map_key_clear(KEY_FORWARD); break;
case 0x013: th_map_key_clear(KEY_PRINT); break;
case 0x017: th_map_key_clear(KEY_PAUSE); break;
case 0x019: th_map_key_clear(KEY_FAVORITES); break;
case 0x01d: th_map_key_clear(KEY_SCREEN); break;
case 0x01e: th_map_key_clear(KEY_NUMERIC_1); break;
case 0x01f: th_map_key_clear(KEY_NUMERIC_2); break;
case 0x020: th_map_key_clear(KEY_NUMERIC_3); break;
case 0x021: th_map_key_clear(KEY_NUMERIC_4); break;
case 0x022: th_map_key_clear(KEY_NUMERIC_5); break;
case 0x023: th_map_key_clear(KEY_NUMERIC_6); break;
case 0x024: th_map_key_clear(KEY_NUMERIC_7); break;
case 0x025: th_map_key_clear(KEY_NUMERIC_8); break;
case 0x026: th_map_key_clear(KEY_NUMERIC_9); break;
case 0x027: th_map_key_clear(KEY_NUMERIC_0); break;
case 0x028: th_map_key_clear(KEY_PLAY); break;
case 0x029: th_map_key_clear(KEY_CANCEL); break;
case 0x02b: th_map_key_clear(KEY_TAB); break;
case 0x03f: th_map_key_clear(KEY_POWER2); break;
case 0x04a: th_map_key_clear(KEY_RECORD); break;
case 0x04b: th_map_key_clear(KEY_CHANNELUP); break;
case 0x04d: th_map_key_clear(KEY_STOP); break;
case 0x04e: th_map_key_clear(KEY_CHANNELDOWN); break;
case 0x051: th_map_key_clear(KEY_VOLUMEDOWN); break;
case 0x052: th_map_key_clear(KEY_VOLUMEUP); break;
case 0x0e0:
case 0x0e1:
case 0x0e2:
case 0x0e3:
case 0x0e4:
case 0x0e5:
case 0x0e6:
case 0x0e7:
default:
return -1;
}
return 1;
}
