static void kvm_rtas_set_xive(struct kvm_vcpu *vcpu, struct rtas_args *args)
{
u32 irq, server, priority;
int rc;
if (args->nargs != 3 || args->nret != 1) {
rc = -3;
goto out;
}
irq = args->args[0];
server = args->args[1];
priority = args->args[2];
rc = kvmppc_xics_set_xive(vcpu->kvm, irq, server, priority);
if (rc)
rc = -3;
out:
args->rets[0] = rc;
}
static void kvm_rtas_get_xive(struct kvm_vcpu *vcpu, struct rtas_args *args)
{
u32 irq, server, priority;
int rc;
if (args->nargs != 1 || args->nret != 3) {
rc = -3;
goto out;
}
irq = args->args[0];
server = priority = 0;
rc = kvmppc_xics_get_xive(vcpu->kvm, irq, &server, &priority);
if (rc) {
rc = -3;
goto out;
}
args->rets[1] = server;
args->rets[2] = priority;
out:
args->rets[0] = rc;
}
static void kvm_rtas_int_off(struct kvm_vcpu *vcpu, struct rtas_args *args)
{
u32 irq;
int rc;
if (args->nargs != 1 || args->nret != 1) {
rc = -3;
goto out;
}
irq = args->args[0];
rc = kvmppc_xics_int_off(vcpu->kvm, irq);
if (rc)
rc = -3;
out:
args->rets[0] = rc;
}
static void kvm_rtas_int_on(struct kvm_vcpu *vcpu, struct rtas_args *args)
{
u32 irq;
int rc;
if (args->nargs != 1 || args->nret != 1) {
rc = -3;
goto out;
}
irq = args->args[0];
rc = kvmppc_xics_int_on(vcpu->kvm, irq);
if (rc)
rc = -3;
out:
args->rets[0] = rc;
}
static int rtas_name_matches(char *s1, char *s2)
{
struct kvm_rtas_token_args args;
return !strncmp(s1, s2, sizeof(args.name));
}
static int rtas_token_undefine(struct kvm *kvm, char *name)
{
struct rtas_token_definition *d, *tmp;
lockdep_assert_held(&kvm->lock);
list_for_each_entry_safe(d, tmp, &kvm->arch.rtas_tokens, list) {
if (rtas_name_matches(d->handler->name, name)) {
list_del(&d->list);
kfree(d);
return 0;
}
}
return 0;
}
static int rtas_token_define(struct kvm *kvm, char *name, u64 token)
{
struct rtas_token_definition *d;
struct rtas_handler *h = NULL;
bool found;
int i;
lockdep_assert_held(&kvm->lock);
list_for_each_entry(d, &kvm->arch.rtas_tokens, list) {
if (d->token == token)
return -EEXIST;
}
found = false;
for (i = 0; i < ARRAY_SIZE(rtas_handlers); i++) {
h = &rtas_handlers[i];
if (rtas_name_matches(h->name, name)) {
found = true;
break;
}
}
if (!found)
return -ENOENT;
d = kzalloc(sizeof(*d), GFP_KERNEL);
if (!d)
return -ENOMEM;
d->handler = h;
d->token = token;
list_add_tail(&d->list, &kvm->arch.rtas_tokens);
return 0;
}
int kvm_vm_ioctl_rtas_define_token(struct kvm *kvm, void __user *argp)
{
struct kvm_rtas_token_args args;
int rc;
if (copy_from_user(&args, argp, sizeof(args)))
return -EFAULT;
mutex_lock(&kvm->lock);
if (args.token)
rc = rtas_token_define(kvm, args.name, args.token);
else
rc = rtas_token_undefine(kvm, args.name);
mutex_unlock(&kvm->lock);
return rc;
}
int kvmppc_rtas_hcall(struct kvm_vcpu *vcpu)
{
struct rtas_token_definition *d;
struct rtas_args args;
rtas_arg_t *orig_rets;
gpa_t args_phys;
int rc;
args_phys = kvmppc_get_gpr(vcpu, 4);
rc = kvm_read_guest(vcpu->kvm, args_phys, &args, sizeof(args));
if (rc)
goto fail;
orig_rets = args.rets;
args.rets = &args.args[args.nargs];
mutex_lock(&vcpu->kvm->lock);
rc = -ENOENT;
list_for_each_entry(d, &vcpu->kvm->arch.rtas_tokens, list) {
if (d->token == args.token) {
d->handler->handler(vcpu, &args);
rc = 0;
break;
}
}
mutex_unlock(&vcpu->kvm->lock);
if (rc == 0) {
args.rets = orig_rets;
rc = kvm_write_guest(vcpu->kvm, args_phys, &args, sizeof(args));
if (rc)
goto fail;
}
return rc;
fail:
return rc;
}
void kvmppc_rtas_tokens_free(struct kvm *kvm)
{
struct rtas_token_definition *d, *tmp;
lockdep_assert_held(&kvm->lock);
list_for_each_entry_safe(d, tmp, &kvm->arch.rtas_tokens, list) {
list_del(&d->list);
kfree(d);
}
}
