CsrResult unifi_coredump_request_at_next_reset(card_t *card, s8 enable)
{
CsrResult r;
if (enable)
{
unifi_trace(card->ospriv, UDBG2, "Mini-coredump requested after reset\n");
}
if (card == NULL)
{
r = CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
else
{
card->request_coredump_on_reset = enable?1 : 0;
r = CSR_RESULT_SUCCESS;
}
return r;
}
CsrResult unifi_coredump_handle_request(card_t *card)
{
CsrResult r = CSR_RESULT_SUCCESS;
if (card == NULL)
{
r = CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
else
{
if (card->request_coredump_on_reset == 1)
{
card->request_coredump_on_reset = 0;
r = unifi_coredump_capture(card, NULL);
}
}
return r;
}
CsrResult unifi_coredump_capture(card_t *card, struct unifi_coredump_req *req)
{
CsrResult r = CSR_RESULT_SUCCESS;
static u16 dump_seq_no = 1;
u32 time_of_capture;
if (card->dump_next_write == NULL)
{
r = CSR_RESULT_SUCCESS;
goto done;
}
if (card->helper == NULL)
{
r = CSR_WIFI_HIP_RESULT_INVALID_VALUE;
goto done;
}
time_of_capture = CsrTimeGet(NULL);
unifi_info(card->ospriv, "Mini-coredump capture at t=%u\n", time_of_capture);
r = unifi_set_host_state(card, UNIFI_HOST_STATE_AWAKE);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to wake UniFi\n");
goto done;
}
CsrThreadSleep(20);
unifi_trace(card->ospriv, UDBG4, "Stopping XAPs for coredump capture\n");
r = unifi_card_stop_processor(card, UNIFI_PROC_BOTH);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to stop UniFi XAPs\n");
goto done;
}
r = unifi_coredump_from_sdio(card, card->dump_next_write);
if (r == CSR_RESULT_SUCCESS)
{
card->dump_next_write->requestor = (req?1 : 0);
card->dump_next_write->timestamp = time_of_capture;
card->dump_next_write->count = dump_seq_no++;
card->dump_cur_read = card->dump_next_write;
card->dump_next_write = card->dump_next_write->next;
if (dump_seq_no == 0)
{
dump_seq_no = 1;
}
unifi_trace(card->ospriv, UDBG3,
"Coredump (%p), SeqNo=%d, cur_read=%p, next_write=%p\n",
req,
card->dump_cur_read->count,
card->dump_cur_read, card->dump_next_write);
}
unifi_trace(card->ospriv, UDBG4, "Restart XAPs after coredump\n");
r = card_start_processor(card, UNIFI_PROC_BOTH);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to start UniFi XAPs\n");
goto done;
}
done:
return r;
}
static s32 get_value_from_coredump(const coredump_buffer *coreDump,
const unifi_coredump_space_t space,
const u16 offset_in_space)
{
s32 r = -1;
u16 offset_in_zone;
u32 zone_end_offset;
s32 i;
const struct coredump_zone *def = &zonedef_table[0];
for (i = 0; i < HIP_CDUMP_NUM_ZONES; i++, def++)
{
if (space == def->space)
{
zone_end_offset = def->offset + def->length;
if (offset_in_space < zone_end_offset &&
offset_in_space >= def->offset)
{
offset_in_zone = offset_in_space - def->offset;
r = (s32) * (coreDump->zone[i] + offset_in_zone);
unifi_trace(NULL, UDBG6,
"sp %d, offs 0x%04x = 0x%04x (in z%d 0x%04x->0x%04x)\n",
space, offset_in_space, r,
i, def->offset, zone_end_offset - 1);
break;
}
}
}
return r;
}
CsrResult unifi_coredump_get_value(card_t *card, struct unifi_coredump_req *req)
{
CsrResult r;
s32 i = 0;
coredump_buffer *find_dump = NULL;
if (req == NULL || card == NULL)
{
r = CSR_WIFI_HIP_RESULT_INVALID_VALUE;
goto done;
}
req->value = -1;
if (card->dump_buf == NULL)
{
unifi_trace(card->ospriv, UDBG2, "No coredump buffers\n");
r = CSR_WIFI_HIP_RESULT_NOT_FOUND;
goto done;
}
if (card->dump_cur_read == NULL)
{
unifi_trace(card->ospriv, UDBG4, "No coredumps captured\n");
r = CSR_WIFI_HIP_RESULT_NOT_FOUND;
goto done;
}
switch (req->index)
{
case 0:
find_dump = card->dump_cur_read;
break;
case -1:
for (find_dump = card->dump_cur_read->next;
(find_dump->count == 0) && (find_dump != card->dump_cur_read);
find_dump = card->dump_cur_read->next)
{
}
break;
default:
for (i = 0, find_dump = card->dump_cur_read;
i < req->index;
i++, find_dump = find_dump->prev)
{
unifi_trace(card->ospriv, UDBG6,
"%d: %d, @%p, p=%p, n=%p, cr=%p, h=%p\n",
i, find_dump->count, find_dump, find_dump->prev,
find_dump->next, card->dump_cur_read, card->dump_buf);
if (find_dump->prev == card->dump_cur_read)
{
if (i != req->index)
{
unifi_trace(card->ospriv, UDBG6,
"Dump index %d not found %d\n", req->index, i);
r = CSR_WIFI_HIP_RESULT_NOT_FOUND;
goto done;
}
break;
}
}
break;
}
if (find_dump->count == 0)
{
unifi_trace(card->ospriv, UDBG4, "Not captured %d\n", req->index);
r = CSR_WIFI_HIP_RESULT_NOT_FOUND;
goto done;
}
unifi_trace(card->ospriv, UDBG6, "Req index %d, found seq %d at step %d\n",
req->index, find_dump->count, i);
req->value = get_value_from_coredump(find_dump, req->space, (u16)req->offset);
if (req->value < 0)
{
r = CSR_WIFI_HIP_RESULT_RANGE;
unifi_trace(card->ospriv, UDBG4,
"Can't read space %d, reg 0x%x from coredump buffer %d\n",
req->space, req->offset, req->index);
}
else
{
r = CSR_RESULT_SUCCESS;
}
req->chip_ver = find_dump->chip_ver;
req->fw_ver = find_dump->fw_ver;
req->timestamp = find_dump->timestamp;
req->requestor = find_dump->requestor;
req->serial = find_dump->count;
done:
return r;
}
static CsrResult unifi_coredump_read_zone(card_t *card, u16 *zonebuf, const struct coredump_zone *def)
{
CsrResult r;
if (zonebuf == NULL || def == NULL)
{
r = CSR_WIFI_HIP_RESULT_INVALID_VALUE;
goto done;
}
if (def->cpu != UNIFI_PROC_INVALID)
{
if (def->cpu != UNIFI_PROC_MAC && def->cpu != UNIFI_PROC_PHY)
{
r = CSR_WIFI_HIP_RESULT_INVALID_VALUE;
goto done;
}
r = unifi_set_proc_select(card, def->cpu);
if (r != CSR_RESULT_SUCCESS)
{
goto done;
}
}
unifi_trace(card->ospriv, UDBG4,
"Dump sp %d, offs 0x%04x, 0x%04x words @GP=%08x CPU %d\n",
def->space, def->offset, def->length, def->gp, def->cpu);
r = unifi_card_readn(card, def->gp, zonebuf, (u16)(def->length * 2));
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
goto done;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Can't read UniFi shared data area\n");
goto done;
}
done:
return r;
}
static CsrResult unifi_coredump_read_zones(card_t *card, coredump_buffer *dump_buf)
{
CsrResult r = CSR_RESULT_SUCCESS;
s32 i;
for (i = 0;
(i < HIP_CDUMP_NUM_ZONES) && (r == 0);
i++)
{
r = unifi_coredump_read_zone(card, dump_buf->zone[i], &zonedef_table[i]);
}
return r;
}
static CsrResult unifi_coredump_from_sdio(card_t *card, coredump_buffer *dump_buf)
{
u16 val;
CsrResult r;
u32 sdio_addr;
if (dump_buf == NULL)
{
r = CSR_WIFI_HIP_RESULT_INVALID_VALUE;
goto done;
}
unifi_trace(card->ospriv, UDBG4, "Get chip version\n");
sdio_addr = 2 * ChipHelper_GBL_CHIP_VERSION(card->helper);
if (sdio_addr != 0)
{
r = unifi_read_direct16(card, sdio_addr, &val);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
goto done;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Can't read GBL_CHIP_VERSION\n");
goto done;
}
}
dump_buf->chip_ver = val;
dump_buf->fw_ver = card->build_id;
unifi_trace(card->ospriv, UDBG4, "chip_ver 0x%04x, fw_ver %u\n",
dump_buf->chip_ver, dump_buf->fw_ver);
r = unifi_coredump_read_zones(card, dump_buf);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
goto done;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Can't read UniFi memory areas\n");
goto done;
}
done:
return r;
}
static
coredump_buffer* new_coredump_node(void *ospriv, coredump_buffer *prevnode)
{
coredump_buffer *newnode = NULL;
u16 *newzone = NULL;
s32 i;
u32 zone_size;
newnode = kzalloc(sizeof(coredump_buffer), GFP_KERNEL);
if (newnode == NULL)
{
return NULL;
}
for (i = 0; i < HIP_CDUMP_NUM_ZONES; i++)
{
zone_size = sizeof(u16) * zonedef_table[i].length;
newzone = kzalloc(zone_size, GFP_KERNEL);
newnode->zone[i] = newzone;
if (newzone == NULL)
{
unifi_error(ospriv, "Out of memory on coredump zone %d (%d words)\n",
i, zonedef_table[i].length);
break;
}
}
if (newzone == NULL)
{
for (i = 0; newnode->zone[i] != NULL; i++)
{
kfree(newnode->zone[i]);
newnode->zone[i] = NULL;
}
}
newnode->prev = prevnode;
if (prevnode)
{
prevnode->next = newnode;
}
newnode->next = NULL;
return newnode;
}
CsrResult unifi_coredump_init(card_t *card, u16 num_dump_buffers)
{
#ifndef UNIFI_DISABLE_COREDUMP
void *ospriv = card->ospriv;
coredump_buffer *prev = NULL;
coredump_buffer *newnode = NULL;
u32 i = 0;
#endif
card->request_coredump_on_reset = 0;
card->dump_next_write = NULL;
card->dump_cur_read = NULL;
card->dump_buf = NULL;
#ifndef UNIFI_DISABLE_COREDUMP
unifi_trace(ospriv, UDBG1,
"Allocate buffers for %d core dumps\n", num_dump_buffers);
if (num_dump_buffers == 0)
{
goto done;
}
card->dump_buf = new_coredump_node(ospriv, NULL);
if (card->dump_buf == NULL)
{
goto fail;
}
prev = card->dump_buf;
newnode = card->dump_buf;
for (i = 1; i < num_dump_buffers; i++)
{
newnode = new_coredump_node(ospriv, prev);
if (newnode == NULL)
{
goto fail;
}
prev = newnode;
}
card->dump_buf->prev = newnode;
newnode->next = card->dump_buf;
card->dump_next_write = card->dump_buf;
card->dump_cur_read = NULL;
unifi_trace(ospriv, UDBG2, "Core dump configured (%d dumps max)\n", i);
done:
#endif
return CSR_RESULT_SUCCESS;
#ifndef UNIFI_DISABLE_COREDUMP
fail:
unifi_error(ospriv, "Out of memory allocating core dump node %d\n", i);
unifi_coredump_free(card);
return CSR_WIFI_HIP_RESULT_NO_MEMORY;
#endif
}
void unifi_coredump_free(card_t *card)
{
void *ospriv = card->ospriv;
coredump_buffer *node, *del_node;
s16 i = 0;
s16 j;
unifi_trace(ospriv, UDBG2, "Core dump de-configured\n");
if (card->dump_buf == NULL)
{
return;
}
node = card->dump_buf;
do
{
for (j = 0; j < HIP_CDUMP_NUM_ZONES; j++)
{
kfree(node->zone[j]);
node->zone[j] = NULL;
}
del_node = node;
node = node->next;
kfree(del_node);
i++;
} while ((node != NULL) && (node != card->dump_buf));
unifi_trace(ospriv, UDBG3, "Freed %d coredump buffers\n", i);
card->dump_buf = NULL;
card->dump_next_write = NULL;
card->dump_cur_read = NULL;
}
