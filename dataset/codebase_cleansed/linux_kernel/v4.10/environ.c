static bool tomoyo_check_env_acl(struct tomoyo_request_info *r,
const struct tomoyo_acl_info *ptr)
{
const struct tomoyo_env_acl *acl =
container_of(ptr, typeof(*acl), head);
return tomoyo_path_matches_pattern(r->param.environ.name, acl->env);
}
static int tomoyo_audit_env_log(struct tomoyo_request_info *r)
{
return tomoyo_supervisor(r, "misc env %s\n",
r->param.environ.name->name);
}
int tomoyo_env_perm(struct tomoyo_request_info *r, const char *env)
{
struct tomoyo_path_info environ;
int error;
if (!env || !*env)
return 0;
environ.name = env;
tomoyo_fill_path_info(&environ);
r->param_type = TOMOYO_TYPE_ENV_ACL;
r->param.environ.name = &environ;
do {
tomoyo_check_acl(r, tomoyo_check_env_acl);
error = tomoyo_audit_env_log(r);
} while (error == TOMOYO_RETRY_REQUEST);
return error;
}
static bool tomoyo_same_env_acl(const struct tomoyo_acl_info *a,
const struct tomoyo_acl_info *b)
{
const struct tomoyo_env_acl *p1 = container_of(a, typeof(*p1), head);
const struct tomoyo_env_acl *p2 = container_of(b, typeof(*p2), head);
return p1->env == p2->env;
}
static int tomoyo_write_env(struct tomoyo_acl_param *param)
{
struct tomoyo_env_acl e = { .head.type = TOMOYO_TYPE_ENV_ACL };
int error = -ENOMEM;
const char *data = tomoyo_read_token(param);
if (!tomoyo_correct_word(data) || strchr(data, '='))
return -EINVAL;
e.env = tomoyo_get_name(data);
if (!e.env)
return error;
error = tomoyo_update_domain(&e.head, sizeof(e), param,
tomoyo_same_env_acl, NULL);
tomoyo_put_name(e.env);
return error;
}
int tomoyo_write_misc(struct tomoyo_acl_param *param)
{
if (tomoyo_str_starts(&param->data, "env "))
return tomoyo_write_env(param);
return -EINVAL;
}
