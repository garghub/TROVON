static void mmio_event_get_key(struct perf_evsel *evsel, struct perf_sample *sample,
struct event_key *key)
{
key->key = perf_evsel__intval(evsel, sample, "gpa");
key->info = perf_evsel__intval(evsel, sample, "type");
}
static bool mmio_event_begin(struct perf_evsel *evsel,
struct perf_sample *sample, struct event_key *key)
{
if (kvm_exit_event(evsel))
return true;
if (!strcmp(evsel->name, "kvm:kvm_mmio") &&
perf_evsel__intval(evsel, sample, "type") == KVM_TRACE_MMIO_WRITE) {
mmio_event_get_key(evsel, sample, key);
return true;
}
return false;
}
static bool mmio_event_end(struct perf_evsel *evsel, struct perf_sample *sample,
struct event_key *key)
{
if (kvm_entry_event(evsel))
return true;
if (!strcmp(evsel->name, "kvm:kvm_mmio") &&
perf_evsel__intval(evsel, sample, "type") == KVM_TRACE_MMIO_READ) {
mmio_event_get_key(evsel, sample, key);
return true;
}
return false;
}
static void mmio_event_decode_key(struct perf_kvm_stat *kvm __maybe_unused,
struct event_key *key,
char *decode)
{
scnprintf(decode, DECODE_STR_LEN, "%#lx:%s",
(unsigned long)key->key,
key->info == KVM_TRACE_MMIO_WRITE ? "W" : "R");
}
static void ioport_event_get_key(struct perf_evsel *evsel,
struct perf_sample *sample,
struct event_key *key)
{
key->key = perf_evsel__intval(evsel, sample, "port");
key->info = perf_evsel__intval(evsel, sample, "rw");
}
static bool ioport_event_begin(struct perf_evsel *evsel,
struct perf_sample *sample,
struct event_key *key)
{
if (!strcmp(evsel->name, "kvm:kvm_pio")) {
ioport_event_get_key(evsel, sample, key);
return true;
}
return false;
}
static bool ioport_event_end(struct perf_evsel *evsel,
struct perf_sample *sample __maybe_unused,
struct event_key *key __maybe_unused)
{
return kvm_entry_event(evsel);
}
static void ioport_event_decode_key(struct perf_kvm_stat *kvm __maybe_unused,
struct event_key *key,
char *decode)
{
scnprintf(decode, DECODE_STR_LEN, "%#llx:%s",
(unsigned long long)key->key,
key->info ? "POUT" : "PIN");
}
int cpu_isa_init(struct perf_kvm_stat *kvm, const char *cpuid)
{
if (strstr(cpuid, "Intel")) {
kvm->exit_reasons = vmx_exit_reasons;
kvm->exit_reasons_isa = "VMX";
} else if (strstr(cpuid, "AMD")) {
kvm->exit_reasons = svm_exit_reasons;
kvm->exit_reasons_isa = "SVM";
} else
return -ENOTSUP;
return 0;
}
