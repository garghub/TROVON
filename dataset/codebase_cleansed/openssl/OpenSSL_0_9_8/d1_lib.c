static long dtls1_default_timeout(void)
{
return(60*60*2);
}
SSL_METHOD *dtlsv1_base_method(void)
{
return(&DTLSv1_data);
}
int dtls1_new(SSL *s)
{
DTLS1_STATE *d1;
if (!ssl3_new(s)) return(0);
if ((d1=OPENSSL_malloc(sizeof *d1)) == NULL) return (0);
memset(d1,0, sizeof *d1);
#if defined(OPENSSL_SYS_VMS) || defined(VMS_TEST)
d1->bitmap.length=64;
#else
d1->bitmap.length=sizeof(d1->bitmap.map) * 8;
#endif
pq_64bit_init(&(d1->bitmap.map));
pq_64bit_init(&(d1->bitmap.max_seq_num));
pq_64bit_init(&(d1->next_bitmap.map));
pq_64bit_init(&(d1->next_bitmap.max_seq_num));
d1->unprocessed_rcds.q=pqueue_new();
d1->processed_rcds.q=pqueue_new();
d1->buffered_messages = pqueue_new();
d1->sent_messages=pqueue_new();
if ( s->server)
{
d1->cookie_len = sizeof(s->d1->cookie);
}
if( ! d1->unprocessed_rcds.q || ! d1->processed_rcds.q
|| ! d1->buffered_messages || ! d1->sent_messages)
{
if ( d1->unprocessed_rcds.q) pqueue_free(d1->unprocessed_rcds.q);
if ( d1->processed_rcds.q) pqueue_free(d1->processed_rcds.q);
if ( d1->buffered_messages) pqueue_free(d1->buffered_messages);
if ( d1->sent_messages) pqueue_free(d1->sent_messages);
OPENSSL_free(d1);
return (0);
}
s->d1=d1;
s->method->ssl_clear(s);
return(1);
}
void dtls1_free(SSL *s)
{
pitem *item = NULL;
hm_fragment *frag = NULL;
ssl3_free(s);
while( (item = pqueue_pop(s->d1->unprocessed_rcds.q)) != NULL)
{
OPENSSL_free(item->data);
pitem_free(item);
}
pqueue_free(s->d1->unprocessed_rcds.q);
while( (item = pqueue_pop(s->d1->processed_rcds.q)) != NULL)
{
OPENSSL_free(item->data);
pitem_free(item);
}
pqueue_free(s->d1->processed_rcds.q);
while( (item = pqueue_pop(s->d1->buffered_messages)) != NULL)
{
frag = (hm_fragment *)item->data;
OPENSSL_free(frag->fragment);
OPENSSL_free(frag);
pitem_free(item);
}
pqueue_free(s->d1->buffered_messages);
while ( (item = pqueue_pop(s->d1->sent_messages)) != NULL)
{
frag = (hm_fragment *)item->data;
OPENSSL_free(frag->fragment);
OPENSSL_free(frag);
pitem_free(item);
}
pqueue_free(s->d1->sent_messages);
pq_64bit_free(&(s->d1->bitmap.map));
pq_64bit_free(&(s->d1->bitmap.max_seq_num));
pq_64bit_free(&(s->d1->next_bitmap.map));
pq_64bit_free(&(s->d1->next_bitmap.max_seq_num));
OPENSSL_free(s->d1);
}
void dtls1_clear(SSL *s)
{
ssl3_clear(s);
s->version=DTLS1_VERSION;
}
