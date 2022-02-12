static void reset(struct ceph_auth_client *ac)
{
struct ceph_auth_none_info *xi = ac->private;
xi->starting = true;
}
static void destroy(struct ceph_auth_client *ac)
{
kfree(ac->private);
ac->private = NULL;
}
static int is_authenticated(struct ceph_auth_client *ac)
{
struct ceph_auth_none_info *xi = ac->private;
return !xi->starting;
}
static int should_authenticate(struct ceph_auth_client *ac)
{
struct ceph_auth_none_info *xi = ac->private;
return xi->starting;
}
static int ceph_auth_none_build_authorizer(struct ceph_auth_client *ac,
struct ceph_none_authorizer *au)
{
void *p = au->buf;
void *const end = p + sizeof(au->buf);
int ret;
ceph_encode_8_safe(&p, end, 1, e_range);
ret = ceph_auth_entity_name_encode(ac->name, &p, end);
if (ret < 0)
return ret;
ceph_encode_64_safe(&p, end, ac->global_id, e_range);
au->buf_len = p - (void *)au->buf;
dout("%s built authorizer len %d\n", __func__, au->buf_len);
return 0;
e_range:
return -ERANGE;
}
static int build_request(struct ceph_auth_client *ac, void *buf, void *end)
{
return 0;
}
static int handle_reply(struct ceph_auth_client *ac, int result,
void *buf, void *end)
{
struct ceph_auth_none_info *xi = ac->private;
xi->starting = false;
return result;
}
static void ceph_auth_none_destroy_authorizer(struct ceph_authorizer *a)
{
kfree(a);
}
static int ceph_auth_none_create_authorizer(
struct ceph_auth_client *ac, int peer_type,
struct ceph_auth_handshake *auth)
{
struct ceph_none_authorizer *au;
int ret;
au = kmalloc(sizeof(*au), GFP_NOFS);
if (!au)
return -ENOMEM;
au->base.destroy = ceph_auth_none_destroy_authorizer;
ret = ceph_auth_none_build_authorizer(ac, au);
if (ret) {
kfree(au);
return ret;
}
auth->authorizer = (struct ceph_authorizer *) au;
auth->authorizer_buf = au->buf;
auth->authorizer_buf_len = au->buf_len;
auth->authorizer_reply_buf = au->reply_buf;
auth->authorizer_reply_buf_len = sizeof (au->reply_buf);
return 0;
}
int ceph_auth_none_init(struct ceph_auth_client *ac)
{
struct ceph_auth_none_info *xi;
dout("ceph_auth_none_init %p\n", ac);
xi = kzalloc(sizeof(*xi), GFP_NOFS);
if (!xi)
return -ENOMEM;
xi->starting = true;
ac->protocol = CEPH_AUTH_NONE;
ac->private = xi;
ac->ops = &ceph_auth_none_ops;
return 0;
}
