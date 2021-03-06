static int __init integrity_audit_setup(char *str)
{
unsigned long audit;
if (!strict_strtoul(str, 0, &audit))
integrity_audit_info = audit ? 1 : 0;
return 1;
}
void integrity_audit_msg(int audit_msgno, struct inode *inode,
const unsigned char *fname, const char *op,
const char *cause, int result, int audit_info)
{
struct audit_buffer *ab;
if (!integrity_audit_info && audit_info == 1)
return;
ab = audit_log_start(current->audit_context, GFP_KERNEL, audit_msgno);
audit_log_format(ab, "pid=%d uid=%u auid=%u ses=%u",
current->pid,
from_kuid(&init_user_ns, current_cred()->uid),
from_kuid(&init_user_ns, audit_get_loginuid(current)),
audit_get_sessionid(current));
audit_log_task_context(ab);
audit_log_format(ab, " op=");
audit_log_string(ab, op);
audit_log_format(ab, " cause=");
audit_log_string(ab, cause);
audit_log_format(ab, " comm=");
audit_log_untrustedstring(ab, current->comm);
if (fname) {
audit_log_format(ab, " name=");
audit_log_untrustedstring(ab, fname);
}
if (inode) {
audit_log_format(ab, " dev=");
audit_log_untrustedstring(ab, inode->i_sb->s_id);
audit_log_format(ab, " ino=%lu", inode->i_ino);
}
audit_log_format(ab, " res=%d", !result);
audit_log_end(ab);
}
