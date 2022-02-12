int __init netlbl_netlink_init(void)
{
int ret_val;
ret_val = netlbl_mgmt_genl_init();
if (ret_val != 0)
return ret_val;
ret_val = netlbl_cipsov4_genl_init();
if (ret_val != 0)
return ret_val;
ret_val = netlbl_calipso_genl_init();
if (ret_val != 0)
return ret_val;
return netlbl_unlabel_genl_init();
}
struct audit_buffer *netlbl_audit_start_common(int type,
struct netlbl_audit *audit_info)
{
struct audit_buffer *audit_buf;
char *secctx;
u32 secctx_len;
if (audit_enabled == 0)
return NULL;
audit_buf = audit_log_start(current->audit_context, GFP_ATOMIC, type);
if (audit_buf == NULL)
return NULL;
audit_log_format(audit_buf, "netlabel: auid=%u ses=%u",
from_kuid(&init_user_ns, audit_info->loginuid),
audit_info->sessionid);
if (audit_info->secid != 0 &&
security_secid_to_secctx(audit_info->secid,
&secctx,
&secctx_len) == 0) {
audit_log_format(audit_buf, " subj=%s", secctx);
security_release_secctx(secctx, secctx_len);
}
return audit_buf;
}
