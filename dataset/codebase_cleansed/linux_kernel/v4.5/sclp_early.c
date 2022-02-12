static int __init sclp_cmd_sync_early(sclp_cmdw_t cmd, void *sccb)
{
int rc;
__ctl_set_bit(0, 9);
rc = sclp_service_call(cmd, sccb);
if (rc)
goto out;
__load_psw_mask(PSW_DEFAULT_KEY | PSW_MASK_BASE | PSW_MASK_EA |
PSW_MASK_BA | PSW_MASK_EXT | PSW_MASK_WAIT);
local_irq_disable();
out:
barrier();
__ctl_clear_bit(0, 9);
return rc;
}
static int __init sclp_read_info_early(struct read_info_sccb *sccb)
{
int rc, i;
sclp_cmdw_t commands[] = {SCLP_CMDW_READ_SCP_INFO_FORCED,
SCLP_CMDW_READ_SCP_INFO};
for (i = 0; i < ARRAY_SIZE(commands); i++) {
do {
memset(sccb, 0, sizeof(*sccb));
sccb->header.length = sizeof(*sccb);
sccb->header.function_code = 0x80;
sccb->header.control_mask[2] = 0x80;
rc = sclp_cmd_sync_early(commands[i], sccb);
} while (rc == -EBUSY);
if (rc)
break;
if (sccb->header.response_code == 0x10)
return 0;
if (sccb->header.response_code != 0x1f0)
break;
}
return -EIO;
}
static void __init sclp_facilities_detect(struct read_info_sccb *sccb)
{
struct sclp_core_entry *cpue;
u16 boot_cpu_address, cpu;
if (sclp_read_info_early(sccb))
return;
sclp.facilities = sccb->facilities;
sclp.has_sprp = !!(sccb->fac84 & 0x02);
sclp.has_core_type = !!(sccb->fac84 & 0x01);
sclp.has_esca = !!(sccb->fac116 & 0x08);
sclp.has_hvs = !!(sccb->fac119 & 0x80);
if (sccb->fac85 & 0x02)
S390_lowcore.machine_flags |= MACHINE_FLAG_ESOP;
sclp.rnmax = sccb->rnmax ? sccb->rnmax : sccb->rnmax2;
sclp.rzm = sccb->rnsize ? sccb->rnsize : sccb->rnsize2;
sclp.rzm <<= 20;
sclp.ibc = sccb->ibc;
if (sccb->hamaxpow && sccb->hamaxpow < 64)
sclp.hamax = (1UL << sccb->hamaxpow) - 1;
else
sclp.hamax = U64_MAX;
if (!sccb->hcpua) {
if (MACHINE_IS_VM)
sclp.max_cores = 64;
else
sclp.max_cores = sccb->ncpurl;
} else {
sclp.max_cores = sccb->hcpua + 1;
}
boot_cpu_address = stap();
cpue = (void *)sccb + sccb->cpuoff;
for (cpu = 0; cpu < sccb->ncpurl; cpue++, cpu++) {
if (boot_cpu_address != cpue->core_id)
continue;
sclp.has_siif = cpue->siif;
sclp.has_sigpif = cpue->sigpif;
sclp.has_sief2 = cpue->sief2;
break;
}
sclp_ipl_info.is_valid = 1;
if (sccb->flags & 0x2)
sclp_ipl_info.has_dump = 1;
memcpy(&sclp_ipl_info.loadparm, &sccb->loadparm, LOADPARM_LEN);
sclp.mtid = (sccb->fac42 & 0x80) ? (sccb->fac42 & 31) : 0;
sclp.mtid_cp = (sccb->fac42 & 0x80) ? (sccb->fac43 & 31) : 0;
sclp.mtid_prev = (sccb->fac42 & 0x80) ? (sccb->fac66 & 31) : 0;
}
void __init sclp_get_ipl_info(struct sclp_ipl_info *info)
{
*info = sclp_ipl_info;
}
static int __init sclp_cmd_early(sclp_cmdw_t cmd, void *sccb)
{
int rc;
do {
rc = sclp_cmd_sync_early(cmd, sccb);
} while (rc == -EBUSY);
if (rc)
return -EIO;
if (((struct sccb_header *) sccb)->response_code != 0x0020)
return -EIO;
return 0;
}
static void __init sccb_init_eq_size(struct sdias_sccb *sccb)
{
memset(sccb, 0, sizeof(*sccb));
sccb->hdr.length = sizeof(*sccb);
sccb->evbuf.hdr.length = sizeof(struct sdias_evbuf);
sccb->evbuf.hdr.type = EVTYP_SDIAS;
sccb->evbuf.event_qual = SDIAS_EQ_SIZE;
sccb->evbuf.data_id = SDIAS_DI_FCP_DUMP;
sccb->evbuf.event_id = 4712;
sccb->evbuf.dbs = 1;
}
static int __init sclp_set_event_mask(struct init_sccb *sccb,
unsigned long receive_mask,
unsigned long send_mask)
{
memset(sccb, 0, sizeof(*sccb));
sccb->header.length = sizeof(*sccb);
sccb->mask_length = sizeof(sccb_mask_t);
sccb->receive_mask = receive_mask;
sccb->send_mask = send_mask;
return sclp_cmd_early(SCLP_CMDW_WRITE_EVENT_MASK, sccb);
}
static long __init sclp_hsa_size_init(struct sdias_sccb *sccb)
{
sccb_init_eq_size(sccb);
if (sclp_cmd_early(SCLP_CMDW_WRITE_EVENT_DATA, sccb))
return -EIO;
if (sccb->evbuf.blk_cnt == 0)
return 0;
return (sccb->evbuf.blk_cnt - 1) * PAGE_SIZE;
}
static long __init sclp_hsa_copy_wait(struct sccb_header *sccb)
{
memset(sccb, 0, PAGE_SIZE);
sccb->length = PAGE_SIZE;
if (sclp_cmd_early(SCLP_CMDW_READ_EVENT_DATA, sccb))
return -EIO;
if (((struct sdias_sccb *) sccb)->evbuf.blk_cnt == 0)
return 0;
return (((struct sdias_sccb *) sccb)->evbuf.blk_cnt - 1) * PAGE_SIZE;
}
static void __init sclp_hsa_size_detect(void *sccb)
{
long size;
if (sclp_set_event_mask(sccb, 0, 0x40000010))
return;
size = sclp_hsa_size_init(sccb);
if (size < 0)
return;
if (size != 0)
goto out;
if (sclp_set_event_mask(sccb, 0x00000010, 0x40000010))
return;
size = sclp_hsa_size_init(sccb);
if (size < 0)
return;
size = sclp_hsa_copy_wait(sccb);
if (size < 0)
return;
out:
sclp.hsa_size = size;
}
static unsigned int __init sclp_con_check_linemode(struct init_sccb *sccb)
{
if (!(sccb->sclp_send_mask & EVTYP_OPCMD_MASK))
return 0;
if (!(sccb->sclp_receive_mask & (EVTYP_MSG_MASK | EVTYP_PMSGCMD_MASK)))
return 0;
return 1;
}
static void __init sclp_console_detect(struct init_sccb *sccb)
{
if (sccb->header.response_code != 0x20)
return;
if (sccb->sclp_send_mask & EVTYP_VT220MSG_MASK)
sclp.has_vt220 = 1;
if (sclp_con_check_linemode(sccb))
sclp.has_linemode = 1;
}
void __init sclp_early_detect(void)
{
void *sccb = &sccb_early;
sclp_facilities_detect(sccb);
sclp_hsa_size_detect(sccb);
sclp_set_event_mask(sccb, 0, 0);
sclp_console_detect(sccb);
}
