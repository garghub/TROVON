void apei_mce_report_mem_error(int severity, struct cper_sec_mem_err *mem_err)
{
struct mce m;
if (!(mem_err->validation_bits & CPER_MEM_VALID_PA))
return;
mce_setup(&m);
m.bank = 1;
m.status = MCI_STATUS_VAL | MCI_STATUS_EN | MCI_STATUS_ADDRV | 0x9f;
if (severity >= GHES_SEV_RECOVERABLE)
m.status |= MCI_STATUS_UC;
if (severity >= GHES_SEV_PANIC)
m.status |= MCI_STATUS_PCC;
m.addr = mem_err->physical_addr;
mce_log(&m);
}
int apei_write_mce(struct mce *m)
{
struct cper_mce_record rcd;
memset(&rcd, 0, sizeof(rcd));
memcpy(rcd.hdr.signature, CPER_SIG_RECORD, CPER_SIG_SIZE);
rcd.hdr.revision = CPER_RECORD_REV;
rcd.hdr.signature_end = CPER_SIG_END;
rcd.hdr.section_count = 1;
rcd.hdr.error_severity = CPER_SEV_FATAL;
rcd.hdr.validation_bits = 0;
rcd.hdr.record_length = sizeof(rcd);
rcd.hdr.creator_id = CPER_CREATOR_MCE;
rcd.hdr.notification_type = CPER_NOTIFY_MCE;
rcd.hdr.record_id = cper_next_record_id();
rcd.hdr.flags = CPER_HW_ERROR_FLAGS_PREVERR;
rcd.sec_hdr.section_offset = (void *)&rcd.mce - (void *)&rcd;
rcd.sec_hdr.section_length = sizeof(rcd.mce);
rcd.sec_hdr.revision = CPER_SEC_REV;
rcd.sec_hdr.validation_bits = 0;
rcd.sec_hdr.flags = CPER_SEC_PRIMARY;
rcd.sec_hdr.section_type = CPER_SECTION_TYPE_MCE;
rcd.sec_hdr.section_severity = CPER_SEV_FATAL;
memcpy(&rcd.mce, m, sizeof(*m));
return erst_write(&rcd.hdr);
}
ssize_t apei_read_mce(struct mce *m, u64 *record_id)
{
struct cper_mce_record rcd;
int rc, pos;
rc = erst_get_record_id_begin(&pos);
if (rc)
return rc;
retry:
rc = erst_get_record_id_next(&pos, record_id);
if (rc)
goto out;
if (*record_id == APEI_ERST_INVALID_RECORD_ID)
goto out;
rc = erst_read(*record_id, &rcd.hdr, sizeof(rcd));
if (rc == -ENOENT)
goto retry;
else if (rc < 0)
goto out;
else if (rc != sizeof(rcd) ||
uuid_le_cmp(rcd.hdr.creator_id, CPER_CREATOR_MCE))
goto retry;
memcpy(m, &rcd.mce, sizeof(*m));
rc = sizeof(*m);
out:
erst_get_record_id_end();
return rc;
}
int apei_check_mce(void)
{
return erst_get_record_count();
}
int apei_clear_mce(u64 record_id)
{
return erst_clear(record_id);
}
