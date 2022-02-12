struct ptlrpc_connection *
ptlrpc_connection_get(lnet_process_id_t peer, lnet_nid_t self,
struct obd_uuid *uuid)
{
struct ptlrpc_connection *conn, *conn2;
conn = cfs_hash_lookup(conn_hash, &peer);
if (conn)
GOTO(out, conn);
OBD_ALLOC_PTR(conn);
if (!conn)
return NULL;
conn->c_peer = peer;
conn->c_self = self;
INIT_HLIST_NODE(&conn->c_hash);
atomic_set(&conn->c_refcount, 1);
if (uuid)
obd_str2uuid(&conn->c_remote_uuid, uuid->uuid);
conn2 = cfs_hash_findadd_unique(conn_hash, &peer, &conn->c_hash);
if (conn != conn2) {
OBD_FREE_PTR(conn);
conn = conn2;
}
out:
CDEBUG(D_INFO, "conn=%p refcount %d to %s\n",
conn, atomic_read(&conn->c_refcount),
libcfs_nid2str(conn->c_peer.nid));
return conn;
}
int ptlrpc_connection_put(struct ptlrpc_connection *conn)
{
int rc = 0;
if (!conn)
return rc;
LASSERT(atomic_read(&conn->c_refcount) > 1);
if (atomic_dec_return(&conn->c_refcount) == 1)
rc = 1;
CDEBUG(D_INFO, "PUT conn=%p refcount %d to %s\n",
conn, atomic_read(&conn->c_refcount),
libcfs_nid2str(conn->c_peer.nid));
return rc;
}
struct ptlrpc_connection *
ptlrpc_connection_addref(struct ptlrpc_connection *conn)
{
atomic_inc(&conn->c_refcount);
CDEBUG(D_INFO, "conn=%p refcount %d to %s\n",
conn, atomic_read(&conn->c_refcount),
libcfs_nid2str(conn->c_peer.nid));
return conn;
}
int ptlrpc_connection_init(void)
{
conn_hash = cfs_hash_create("CONN_HASH",
HASH_CONN_CUR_BITS,
HASH_CONN_MAX_BITS,
HASH_CONN_BKT_BITS, 0,
CFS_HASH_MIN_THETA,
CFS_HASH_MAX_THETA,
&conn_hash_ops, CFS_HASH_DEFAULT);
if (!conn_hash)
return -ENOMEM;
return 0;
}
void ptlrpc_connection_fini(void)
{
cfs_hash_putref(conn_hash);
}
static unsigned
conn_hashfn(struct cfs_hash *hs, const void *key, unsigned mask)
{
return cfs_hash_djb2_hash(key, sizeof(lnet_process_id_t), mask);
}
static int
conn_keycmp(const void *key, struct hlist_node *hnode)
{
struct ptlrpc_connection *conn;
const lnet_process_id_t *conn_key;
LASSERT(key != NULL);
conn_key = (lnet_process_id_t*)key;
conn = hlist_entry(hnode, struct ptlrpc_connection, c_hash);
return conn_key->nid == conn->c_peer.nid &&
conn_key->pid == conn->c_peer.pid;
}
static void *
conn_key(struct hlist_node *hnode)
{
struct ptlrpc_connection *conn;
conn = hlist_entry(hnode, struct ptlrpc_connection, c_hash);
return &conn->c_peer;
}
static void *
conn_object(struct hlist_node *hnode)
{
return hlist_entry(hnode, struct ptlrpc_connection, c_hash);
}
static void
conn_get(struct cfs_hash *hs, struct hlist_node *hnode)
{
struct ptlrpc_connection *conn;
conn = hlist_entry(hnode, struct ptlrpc_connection, c_hash);
atomic_inc(&conn->c_refcount);
}
static void
conn_put_locked(struct cfs_hash *hs, struct hlist_node *hnode)
{
struct ptlrpc_connection *conn;
conn = hlist_entry(hnode, struct ptlrpc_connection, c_hash);
atomic_dec(&conn->c_refcount);
}
static void
conn_exit(struct cfs_hash *hs, struct hlist_node *hnode)
{
struct ptlrpc_connection *conn;
conn = hlist_entry(hnode, struct ptlrpc_connection, c_hash);
LASSERTF(atomic_read(&conn->c_refcount) == 0,
"Busy connection with %d refs\n",
atomic_read(&conn->c_refcount));
OBD_FREE_PTR(conn);
}
