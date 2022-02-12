static void audit_cb(struct audit_buffer *ab, void *va)
{
struct common_audit_data *sa = va;
audit_log_format(ab, " peer=");
audit_log_untrustedstring(ab, aad(sa)->peer->base.hname);
}
static int aa_audit_ptrace(struct aa_profile *profile,
struct aa_profile *target, int error)
{
DEFINE_AUDIT_DATA(sa, LSM_AUDIT_DATA_NONE, OP_PTRACE);
aad(&sa)->peer = target;
aad(&sa)->error = error;
return aa_audit(AUDIT_APPARMOR_AUTO, profile, &sa, audit_cb);
}
int aa_may_ptrace(struct aa_profile *tracer, struct aa_profile *tracee,
unsigned int mode)
{
if (unconfined(tracer) || tracer == tracee)
return 0;
return aa_capable(tracer, CAP_SYS_PTRACE, 1);
}
int aa_ptrace(struct task_struct *tracer, struct task_struct *tracee,
unsigned int mode)
{
struct aa_profile *tracer_p = aa_get_task_profile(tracer);
int error = 0;
if (!unconfined(tracer_p)) {
struct aa_profile *tracee_p = aa_get_task_profile(tracee);
error = aa_may_ptrace(tracer_p, tracee_p, mode);
error = aa_audit_ptrace(tracer_p, tracee_p, error);
aa_put_profile(tracee_p);
}
aa_put_profile(tracer_p);
return error;
}
