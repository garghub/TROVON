static int calc_tpm2_event_size(struct tcg_pcr_event2 *event,
struct tcg_pcr_event *event_header)
{
struct tcg_efi_specid_event *efispecid;
struct tcg_event_field *event_field;
void *marker;
void *marker_start;
u32 halg_size;
size_t size;
u16 halg;
int i;
int j;
marker = event;
marker_start = marker;
marker = marker + sizeof(event->pcr_idx) + sizeof(event->event_type)
+ sizeof(event->count);
efispecid = (struct tcg_efi_specid_event *)event_header->event;
if (event->count > efispecid->num_algs)
return 0;
for (i = 0; i < event->count; i++) {
halg_size = sizeof(event->digests[i].alg_id);
memcpy(&halg, marker, halg_size);
marker = marker + halg_size;
for (j = 0; j < efispecid->num_algs; j++) {
if (halg == efispecid->digest_sizes[j].alg_id) {
marker +=
efispecid->digest_sizes[j].digest_size;
break;
}
}
if (j == efispecid->num_algs)
return 0;
}
event_field = (struct tcg_event_field *)marker;
marker = marker + sizeof(event_field->event_size)
+ event_field->event_size;
size = marker - marker_start;
if ((event->event_type == 0) && (event_field->event_size == 0))
return 0;
return size;
}
static void *tpm2_bios_measurements_start(struct seq_file *m, loff_t *pos)
{
struct tpm_chip *chip = m->private;
struct tpm_bios_log *log = &chip->log;
void *addr = log->bios_event_log;
void *limit = log->bios_event_log_end;
struct tcg_pcr_event *event_header;
struct tcg_pcr_event2 *event;
size_t size;
int i;
event_header = addr;
size = sizeof(struct tcg_pcr_event) - sizeof(event_header->event)
+ event_header->event_size;
if (*pos == 0) {
if (addr + size < limit) {
if ((event_header->event_type == 0) &&
(event_header->event_size == 0))
return NULL;
return SEQ_START_TOKEN;
}
}
if (*pos > 0) {
addr += size;
event = addr;
size = calc_tpm2_event_size(event, event_header);
if ((addr + size >= limit) || (size == 0))
return NULL;
}
for (i = 0; i < (*pos - 1); i++) {
event = addr;
size = calc_tpm2_event_size(event, event_header);
if ((addr + size >= limit) || (size == 0))
return NULL;
addr += size;
}
return addr;
}
static void *tpm2_bios_measurements_next(struct seq_file *m, void *v,
loff_t *pos)
{
struct tcg_pcr_event *event_header;
struct tcg_pcr_event2 *event;
struct tpm_chip *chip = m->private;
struct tpm_bios_log *log = &chip->log;
void *limit = log->bios_event_log_end;
size_t event_size;
void *marker;
event_header = log->bios_event_log;
if (v == SEQ_START_TOKEN) {
event_size = sizeof(struct tcg_pcr_event) -
sizeof(event_header->event) + event_header->event_size;
marker = event_header;
} else {
event = v;
event_size = calc_tpm2_event_size(event, event_header);
if (event_size == 0)
return NULL;
marker = event;
}
marker = marker + event_size;
if (marker >= limit)
return NULL;
v = marker;
event = v;
event_size = calc_tpm2_event_size(event, event_header);
if (((v + event_size) >= limit) || (event_size == 0))
return NULL;
(*pos)++;
return v;
}
static void tpm2_bios_measurements_stop(struct seq_file *m, void *v)
{
}
static int tpm2_binary_bios_measurements_show(struct seq_file *m, void *v)
{
struct tpm_chip *chip = m->private;
struct tpm_bios_log *log = &chip->log;
struct tcg_pcr_event *event_header = log->bios_event_log;
struct tcg_pcr_event2 *event = v;
void *temp_ptr;
size_t size;
if (v == SEQ_START_TOKEN) {
size = sizeof(struct tcg_pcr_event) -
sizeof(event_header->event) + event_header->event_size;
temp_ptr = event_header;
if (size > 0)
seq_write(m, temp_ptr, size);
} else {
size = calc_tpm2_event_size(event, event_header);
temp_ptr = event;
if (size > 0)
seq_write(m, temp_ptr, size);
}
return 0;
}
