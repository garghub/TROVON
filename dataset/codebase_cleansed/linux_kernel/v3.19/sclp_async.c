static int call_home_on_panic(struct notifier_block *self,
unsigned long event, void *data)
{
strncat(data, init_utsname()->nodename,
sizeof(init_utsname()->nodename));
sclp_async_send_wait(data);
return NOTIFY_DONE;
}
static int proc_handler_callhome(struct ctl_table *ctl, int write,
void __user *buffer, size_t *count,
loff_t *ppos)
{
unsigned long val;
int len, rc;
char buf[3];
if (!*count || (*ppos && !write)) {
*count = 0;
return 0;
}
if (!write) {
len = snprintf(buf, sizeof(buf), "%d\n", callhome_enabled);
rc = copy_to_user(buffer, buf, sizeof(buf));
if (rc != 0)
return -EFAULT;
} else {
len = *count;
rc = kstrtoul_from_user(buffer, len, 0, &val);
if (rc)
return rc;
if (val != 0 && val != 1)
return -EINVAL;
callhome_enabled = val;
}
*count = len;
*ppos += len;
return 0;
}
static int sclp_async_send_wait(char *message)
{
struct async_evbuf *evb;
int rc;
unsigned long flags;
if (!callhome_enabled)
return 0;
sccb->evbuf.header.type = EVTYP_ASYNC;
sccb->evbuf.rtype = 0xA5;
sccb->evbuf.otype = 0x00;
evb = &sccb->evbuf;
request->command = SCLP_CMDW_WRITE_EVENT_DATA;
request->sccb = sccb;
request->status = SCLP_REQ_FILLED;
strncpy(sccb->evbuf.data, message, sizeof(sccb->evbuf.data));
strncpy(sccb->evbuf.comp_id, CONFIG_SCLP_ASYNC_ID,
sizeof(sccb->evbuf.comp_id));
sccb->evbuf.header.length = sizeof(sccb->evbuf);
sccb->header.length = sizeof(sccb->evbuf) + sizeof(sccb->header);
sccb->header.function_code = SCLP_NORMAL_WRITE;
rc = sclp_add_request(request);
if (rc)
return rc;
spin_lock_irqsave(&sclp_async_lock, flags);
while (request->status != SCLP_REQ_DONE &&
request->status != SCLP_REQ_FAILED) {
sclp_sync_wait();
}
spin_unlock_irqrestore(&sclp_async_lock, flags);
if (request->status != SCLP_REQ_DONE)
return -EIO;
rc = ((struct sclp_async_sccb *)
request->sccb)->header.response_code;
if (rc != 0x0020)
return -EIO;
if (evb->header.flags != 0x80)
return -EIO;
return rc;
}
static int __init sclp_async_init(void)
{
int rc;
rc = sclp_register(&sclp_async_register);
if (rc)
return rc;
rc = -EOPNOTSUPP;
if (!(sclp_async_register.sclp_receive_mask & EVTYP_ASYNC_MASK))
goto out_sclp;
rc = -ENOMEM;
callhome_sysctl_header = register_sysctl_table(kern_dir_table);
if (!callhome_sysctl_header)
goto out_sclp;
request = kzalloc(sizeof(struct sclp_req), GFP_KERNEL);
sccb = (struct sclp_async_sccb *) get_zeroed_page(GFP_KERNEL | GFP_DMA);
if (!request || !sccb)
goto out_mem;
rc = atomic_notifier_chain_register(&panic_notifier_list,
&call_home_panic_nb);
if (!rc)
goto out;
out_mem:
kfree(request);
free_page((unsigned long) sccb);
unregister_sysctl_table(callhome_sysctl_header);
out_sclp:
sclp_unregister(&sclp_async_register);
out:
return rc;
}
static void __exit sclp_async_exit(void)
{
atomic_notifier_chain_unregister(&panic_notifier_list,
&call_home_panic_nb);
unregister_sysctl_table(callhome_sysctl_header);
sclp_unregister(&sclp_async_register);
free_page((unsigned long) sccb);
kfree(request);
}
