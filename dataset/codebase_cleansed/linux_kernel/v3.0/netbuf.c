void a_netbuf_enqueue(A_NETBUF_QUEUE_T *q, void *pkt)
{
skb_queue_tail((struct sk_buff_head *) q, (struct sk_buff *) pkt);
}
void a_netbuf_prequeue(A_NETBUF_QUEUE_T *q, void *pkt)
{
skb_queue_head((struct sk_buff_head *) q, (struct sk_buff *) pkt);
}
void *a_netbuf_dequeue(A_NETBUF_QUEUE_T *q)
{
return((void *) skb_dequeue((struct sk_buff_head *) q));
}
int a_netbuf_queue_size(A_NETBUF_QUEUE_T *q)
{
return(skb_queue_len((struct sk_buff_head *) q));
}
int a_netbuf_queue_empty(A_NETBUF_QUEUE_T *q)
{
return(skb_queue_empty((struct sk_buff_head *) q));
}
void a_netbuf_queue_init(A_NETBUF_QUEUE_T *q)
{
skb_queue_head_init((struct sk_buff_head *) q);
}
void *
a_netbuf_alloc(int size)
{
struct sk_buff *skb;
size += 2 * (A_GET_CACHE_LINE_BYTES());
skb = dev_alloc_skb(AR6000_DATA_OFFSET + sizeof(struct htc_packet) + size);
skb_reserve(skb, AR6000_DATA_OFFSET + sizeof(struct htc_packet) + A_GET_CACHE_LINE_BYTES());
return ((void *)skb);
}
void *
a_netbuf_alloc_raw(int size)
{
struct sk_buff *skb;
skb = dev_alloc_skb(size);
return ((void *)skb);
}
void
a_netbuf_free(void *bufPtr)
{
struct sk_buff *skb = (struct sk_buff *)bufPtr;
dev_kfree_skb(skb);
}
u32 a_netbuf_to_len(void *bufPtr)
{
return (((struct sk_buff *)bufPtr)->len);
}
void *
a_netbuf_to_data(void *bufPtr)
{
return (((struct sk_buff *)bufPtr)->data);
}
int
a_netbuf_push(void *bufPtr, s32 len)
{
skb_push((struct sk_buff *)bufPtr, len);
return 0;
}
int
a_netbuf_push_data(void *bufPtr, char *srcPtr, s32 len)
{
skb_push((struct sk_buff *) bufPtr, len);
memcpy(((struct sk_buff *)bufPtr)->data, srcPtr, len);
return 0;
}
int
a_netbuf_put(void *bufPtr, s32 len)
{
skb_put((struct sk_buff *)bufPtr, len);
return 0;
}
int
a_netbuf_put_data(void *bufPtr, char *srcPtr, s32 len)
{
char *start = (char*)(((struct sk_buff *)bufPtr)->data +
((struct sk_buff *)bufPtr)->len);
skb_put((struct sk_buff *)bufPtr, len);
memcpy(start, srcPtr, len);
return 0;
}
int
a_netbuf_setlen(void *bufPtr, s32 len)
{
skb_trim((struct sk_buff *)bufPtr, len);
return 0;
}
int
a_netbuf_trim(void *bufPtr, s32 len)
{
skb_trim((struct sk_buff *)bufPtr, ((struct sk_buff *)bufPtr)->len - len);
return 0;
}
int
a_netbuf_trim_data(void *bufPtr, char *dstPtr, s32 len)
{
char *start = (char*)(((struct sk_buff *)bufPtr)->data +
(((struct sk_buff *)bufPtr)->len - len));
memcpy(dstPtr, start, len);
skb_trim((struct sk_buff *)bufPtr, ((struct sk_buff *)bufPtr)->len - len);
return 0;
}
s32 a_netbuf_headroom(void *bufPtr)
{
return (skb_headroom((struct sk_buff *)bufPtr));
}
int
a_netbuf_pull(void *bufPtr, s32 len)
{
skb_pull((struct sk_buff *)bufPtr, len);
return 0;
}
int
a_netbuf_pull_data(void *bufPtr, char *dstPtr, s32 len)
{
memcpy(dstPtr, ((struct sk_buff *)bufPtr)->data, len);
skb_pull((struct sk_buff *)bufPtr, len);
return 0;
}
