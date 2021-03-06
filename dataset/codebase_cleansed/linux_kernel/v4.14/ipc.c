static void audit_ptrace_mask(struct audit_buffer *ab, u32 mask)
{
switch (mask) {
case MAY_READ:
audit_log_string(ab, "read");
break;
case MAY_WRITE:
audit_log_string(ab, "trace");
break;
case AA_MAY_BE_READ:
audit_log_string(ab, "readby");
break;
case AA_MAY_BE_TRACED:
audit_log_string(ab, "tracedby");
break;
}
}
static void audit_ptrace_cb(struct audit_buffer *ab, void *va)
{
struct common_audit_data *sa = va;
if (aad(sa)->request & AA_PTRACE_PERM_MASK) {
audit_log_format(ab, " requested_mask=");
audit_ptrace_mask(ab, aad(sa)->request);
if (aad(sa)->denied & AA_PTRACE_PERM_MASK) {
audit_log_format(ab, " denied_mask=");
audit_ptrace_mask(ab, aad(sa)->denied);
}
}
audit_log_format(ab, " peer=");
aa_label_xaudit(ab, labels_ns(aad(sa)->label), aad(sa)->peer,
FLAGS_NONE, GFP_ATOMIC);
}
static int profile_ptrace_perm(struct aa_profile *profile,
struct aa_profile *peer, u32 request,
struct common_audit_data *sa)
{
struct aa_perms perms = { };
if (profile_unconfined(profile) ||
!PROFILE_MEDIATES(profile, AA_CLASS_PTRACE))
return 0;
aad(sa)->peer = &peer->label;
aa_profile_match_label(profile, &peer->label, AA_CLASS_PTRACE, request,
&perms);
aa_apply_modes_to_perms(profile, &perms);
return aa_check_perms(profile, &perms, request, sa, audit_ptrace_cb);
}
static int cross_ptrace_perm(struct aa_profile *tracer,
struct aa_profile *tracee, u32 request,
struct common_audit_data *sa)
{
if (PROFILE_MEDIATES(tracer, AA_CLASS_PTRACE))
return xcheck(profile_ptrace_perm(tracer, tracee, request, sa),
profile_ptrace_perm(tracee, tracer,
request << PTRACE_PERM_SHIFT,
sa));
if (profile_unconfined(tracer) || tracer == tracee)
return 0;
aad(sa)->label = &tracer->label;
aad(sa)->peer = &tracee->label;
aad(sa)->request = 0;
aad(sa)->error = aa_capable(&tracer->label, CAP_SYS_PTRACE, 1);
return aa_audit(AUDIT_APPARMOR_AUTO, tracer, sa, audit_ptrace_cb);
}
int aa_may_ptrace(struct aa_label *tracer, struct aa_label *tracee,
u32 request)
{
DEFINE_AUDIT_DATA(sa, LSM_AUDIT_DATA_NONE, OP_PTRACE);
return xcheck_labels_profiles(tracer, tracee, cross_ptrace_perm,
request, &sa);
}
static inline int map_signal_num(int sig)
{
if (sig > SIGRTMAX)
return SIGUNKNOWN;
else if (sig >= SIGRTMIN)
return sig - SIGRTMIN + 128;
else if (sig < MAXMAPPED_SIG)
return sig_map[sig];
return SIGUNKNOWN;
}
static void audit_signal_mask(struct audit_buffer *ab, u32 mask)
{
if (mask & MAY_READ)
audit_log_string(ab, "receive");
if (mask & MAY_WRITE)
audit_log_string(ab, "send");
}
static void audit_signal_cb(struct audit_buffer *ab, void *va)
{
struct common_audit_data *sa = va;
if (aad(sa)->request & AA_SIGNAL_PERM_MASK) {
audit_log_format(ab, " requested_mask=");
audit_signal_mask(ab, aad(sa)->request);
if (aad(sa)->denied & AA_SIGNAL_PERM_MASK) {
audit_log_format(ab, " denied_mask=");
audit_signal_mask(ab, aad(sa)->denied);
}
}
if (aad(sa)->signal < MAXMAPPED_SIG)
audit_log_format(ab, " signal=%s", sig_names[aad(sa)->signal]);
else
audit_log_format(ab, " signal=rtmin+%d",
aad(sa)->signal - 128);
audit_log_format(ab, " peer=");
aa_label_xaudit(ab, labels_ns(aad(sa)->label), aad(sa)->peer,
FLAGS_NONE, GFP_ATOMIC);
}
static void profile_match_signal(struct aa_profile *profile, const char *label,
int signal, struct aa_perms *perms)
{
unsigned int state;
state = aa_dfa_next(profile->policy.dfa,
profile->policy.start[AA_CLASS_SIGNAL],
signal);
state = aa_dfa_match(profile->policy.dfa, state, label);
aa_compute_perms(profile->policy.dfa, state, perms);
}
static int profile_signal_perm(struct aa_profile *profile,
struct aa_profile *peer, u32 request,
struct common_audit_data *sa)
{
struct aa_perms perms;
if (profile_unconfined(profile) ||
!PROFILE_MEDIATES(profile, AA_CLASS_SIGNAL))
return 0;
aad(sa)->peer = &peer->label;
profile_match_signal(profile, peer->base.hname, aad(sa)->signal,
&perms);
aa_apply_modes_to_perms(profile, &perms);
return aa_check_perms(profile, &perms, request, sa, audit_signal_cb);
}
static int aa_signal_cross_perm(struct aa_profile *sender,
struct aa_profile *target,
struct common_audit_data *sa)
{
return xcheck(profile_signal_perm(sender, target, MAY_WRITE, sa),
profile_signal_perm(target, sender, MAY_READ, sa));
}
int aa_may_signal(struct aa_label *sender, struct aa_label *target, int sig)
{
DEFINE_AUDIT_DATA(sa, LSM_AUDIT_DATA_NONE, OP_SIGNAL);
aad(&sa)->signal = map_signal_num(sig);
return xcheck_labels_profiles(sender, target, aa_signal_cross_perm,
&sa);
}
