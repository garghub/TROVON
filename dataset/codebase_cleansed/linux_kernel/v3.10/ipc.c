static void audit_cb(struct audit_buffer *ab, void *va)
{
struct common_audit_data *sa = va;
audit_log_format(ab, " target=");
audit_log_untrustedstring(ab, sa->aad->target);
}
static int aa_audit_ptrace(struct aa_profile *profile,
struct aa_profile *target, int error)
{
struct common_audit_data sa;
struct apparmor_audit_data aad = {0,};
sa.type = LSM_AUDIT_DATA_NONE;
sa.aad = &aad;
aad.op = OP_PTRACE;
aad.target = target;
aad.error = error;
return aa_audit(AUDIT_APPARMOR_AUTO, profile, GFP_ATOMIC, &sa,
audit_cb);
}
int aa_may_ptrace(struct task_struct *tracer_task, struct aa_profile *tracer,
struct aa_profile *tracee, unsigned int mode)
{
if (unconfined(tracer) || tracer == tracee)
return 0;
return aa_capable(tracer_task, tracer, CAP_SYS_PTRACE, 1);
}
int aa_ptrace(struct task_struct *tracer, struct task_struct *tracee,
unsigned int mode)
{
struct aa_profile *tracer_p;
const struct cred *cred = get_task_cred(tracer);
int error = 0;
tracer_p = aa_cred_profile(cred);
if (!unconfined(tracer_p)) {
const struct cred *lcred = get_task_cred(tracee);
struct aa_profile *tracee_p = aa_cred_profile(lcred);
error = aa_may_ptrace(tracer, tracer_p, tracee_p, mode);
error = aa_audit_ptrace(tracer_p, tracee_p, error);
put_cred(lcred);
}
put_cred(cred);
return error;
}
