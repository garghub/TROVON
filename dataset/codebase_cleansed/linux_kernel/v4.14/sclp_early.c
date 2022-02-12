static int __init sclp_early_read_info(struct read_info_sccb *sccb)
{
int i;
sclp_cmdw_t commands[] = {SCLP_CMDW_READ_SCP_INFO_FORCED,
SCLP_CMDW_READ_SCP_INFO};
for (i = 0; i < ARRAY_SIZE(commands); i++) {
memset(sccb, 0, sizeof(*sccb));
sccb->header.length = sizeof(*sccb);
sccb->header.function_code = 0x80;
sccb->header.control_mask[2] = 0x80;
if (sclp_early_cmd(commands[i], sccb))
break;
if (sccb->header.response_code == 0x10)
return 0;
if (sccb->header.response_code != 0x1f0)
break;
}
return -EIO;
}
static void __init sclp_early_facilities_detect(struct read_info_sccb *sccb)
{
struct sclp_core_entry *cpue;
u16 boot_cpu_address, cpu;
if (sclp_early_read_info(sccb))
return;
sclp.facilities = sccb->facilities;
sclp.has_sprp = !!(sccb->fac84 & 0x02);
sclp.has_core_type = !!(sccb->fac84 & 0x01);
sclp.has_gsls = !!(sccb->fac85 & 0x80);
sclp.has_64bscao = !!(sccb->fac116 & 0x80);
sclp.has_cmma = !!(sccb->fac116 & 0x40);
sclp.has_esca = !!(sccb->fac116 & 0x08);
sclp.has_pfmfi = !!(sccb->fac117 & 0x40);
sclp.has_ibs = !!(sccb->fac117 & 0x20);
sclp.has_hvs = !!(sccb->fac119 & 0x80);
sclp.has_kss = !!(sccb->fac98 & 0x01);
if (sccb->fac85 & 0x02)
S390_lowcore.machine_flags |= MACHINE_FLAG_ESOP;
if (sccb->fac91 & 0x40)
S390_lowcore.machine_flags |= MACHINE_FLAG_TLB_GUEST;
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
sclp.has_gpere = cpue->gpere;
sclp.has_ib = cpue->ib;
sclp.has_cei = cpue->cei;
sclp.has_skey = cpue->skey;
break;
}
sclp_ipl_info.is_valid = 1;
if (sccb->fac91 & 0x2)
sclp_ipl_info.has_dump = 1;
memcpy(&sclp_ipl_info.loadparm, &sccb->loadparm, LOADPARM_LEN);
sclp.mtid = (sccb->fac42 & 0x80) ? (sccb->fac42 & 31) : 0;
sclp.mtid_cp = (sccb->fac42 & 0x80) ? (sccb->fac43 & 31) : 0;
sclp.mtid_prev = (sccb->fac42 & 0x80) ? (sccb->fac66 & 31) : 0;
sclp.hmfai = sccb->hmfai;
}
void __init sclp_early_get_ipl_info(struct sclp_ipl_info *info)
{
*info = sclp_ipl_info;
}
static void __init sclp_early_init_core_info(struct read_cpu_info_sccb *sccb)
{
if (!SCLP_HAS_CPU_INFO)
return;
memset(sccb, 0, sizeof(*sccb));
sccb->header.length = sizeof(*sccb);
if (sclp_early_cmd(SCLP_CMDW_READ_CPU_INFO, sccb))
return;
if (sccb->header.response_code != 0x0010)
return;
sclp_fill_core_info(&sclp_early_core_info, sccb);
sclp_early_core_info_valid = 1;
}
int __init sclp_early_get_core_info(struct sclp_core_info *info)
{
if (!sclp_early_core_info_valid)
return -EIO;
*info = sclp_early_core_info;
return 0;
}
static long __init sclp_early_hsa_size_init(struct sdias_sccb *sccb)
{
memset(sccb, 0, sizeof(*sccb));
sccb->hdr.length = sizeof(*sccb);
sccb->evbuf.hdr.length = sizeof(struct sdias_evbuf);
sccb->evbuf.hdr.type = EVTYP_SDIAS;
sccb->evbuf.event_qual = SDIAS_EQ_SIZE;
sccb->evbuf.data_id = SDIAS_DI_FCP_DUMP;
sccb->evbuf.event_id = 4712;
sccb->evbuf.dbs = 1;
if (sclp_early_cmd(SCLP_CMDW_WRITE_EVENT_DATA, sccb))
return -EIO;
if (sccb->hdr.response_code != 0x20)
return -EIO;
if (sccb->evbuf.blk_cnt == 0)
return 0;
return (sccb->evbuf.blk_cnt - 1) * PAGE_SIZE;
}
static long __init sclp_early_hsa_copy_wait(struct sdias_sccb *sccb)
{
memset(sccb, 0, PAGE_SIZE);
sccb->hdr.length = PAGE_SIZE;
if (sclp_early_cmd(SCLP_CMDW_READ_EVENT_DATA, sccb))
return -EIO;
if ((sccb->hdr.response_code != 0x20) && (sccb->hdr.response_code != 0x220))
return -EIO;
if (sccb->evbuf.blk_cnt == 0)
return 0;
return (sccb->evbuf.blk_cnt - 1) * PAGE_SIZE;
}
static void __init sclp_early_hsa_size_detect(void *sccb)
{
unsigned long flags;
long size = -EIO;
raw_local_irq_save(flags);
if (sclp_early_set_event_mask(sccb, EVTYP_SDIAS_MASK, EVTYP_SDIAS_MASK))
goto out;
size = sclp_early_hsa_size_init(sccb);
if (size)
goto out_mask;
if (!(S390_lowcore.ext_params & 1))
sclp_early_wait_irq();
size = sclp_early_hsa_copy_wait(sccb);
out_mask:
sclp_early_set_event_mask(sccb, 0, 0);
out:
raw_local_irq_restore(flags);
if (size > 0)
sclp.hsa_size = size;
}
static void __init sclp_early_console_detect(struct init_sccb *sccb)
{
if (sccb->header.response_code != 0x20)
return;
if (sccb->sclp_send_mask & EVTYP_VT220MSG_MASK)
sclp.has_vt220 = 1;
if (sclp_early_con_check_linemode(sccb))
sclp.has_linemode = 1;
}
void __init sclp_early_detect(void)
{
void *sccb = &sclp_early_sccb;
sclp_early_facilities_detect(sccb);
sclp_early_init_core_info(sccb);
sclp_early_hsa_size_detect(sccb);
sclp_early_set_event_mask(sccb, 0, 0);
sclp_early_console_detect(sccb);
}
