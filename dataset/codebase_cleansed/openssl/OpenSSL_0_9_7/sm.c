void state_machine_init(state_machine_t *machine)
{
machine->ssl = NULL;
machine->bio_intossl = machine->bio_fromssl = NULL;
buffer_init(&machine->clean_in);
buffer_init(&machine->clean_out);
buffer_init(&machine->dirty_in);
buffer_init(&machine->dirty_out);
}
void state_machine_close(state_machine_t *machine)
{
if(machine->ssl)
SSL_free(machine->ssl);
#if 0
if(machine->bio_intossl)
BIO_free(machine->bio_intossl);
if(machine->bio_fromssl)
BIO_free(machine->bio_fromssl);
#endif
buffer_close(&machine->clean_in);
buffer_close(&machine->clean_out);
buffer_close(&machine->dirty_in);
buffer_close(&machine->dirty_out);
state_machine_init(machine);
}
buffer_t *state_machine_get_buffer(state_machine_t *machine, sm_buffer_t type)
{
switch(type) {
case SM_CLEAN_IN:
return &machine->clean_in;
case SM_CLEAN_OUT:
return &machine->clean_out;
case SM_DIRTY_IN:
return &machine->dirty_in;
case SM_DIRTY_OUT:
return &machine->dirty_out;
default:
break;
}
abort();
return NULL;
}
SSL *state_machine_get_SSL(state_machine_t *machine)
{
return machine->ssl;
}
int state_machine_set_SSL(state_machine_t *machine, SSL *ssl, int is_server)
{
if(machine->ssl)
abort();
machine->ssl = ssl;
if((machine->bio_intossl = BIO_new(BIO_s_mem())) == NULL)
abort();
if((machine->bio_fromssl = BIO_new(BIO_s_mem())) == NULL)
abort();
SSL_set_bio(machine->ssl, machine->bio_intossl, machine->bio_fromssl);
if(is_server)
SSL_set_accept_state(machine->ssl);
else
SSL_set_connect_state(machine->ssl);
return state_machine_churn(machine);
}
int state_machine_churn(state_machine_t *machine)
{
unsigned int loop;
if(machine->ssl == NULL) {
if(buffer_empty(&machine->clean_out))
return 0;
else
return 1;
}
for(loop = 0; loop < 2; loop++) {
buffer_to_SSL(&machine->clean_in, machine->ssl);
buffer_to_BIO(&machine->dirty_in, machine->bio_intossl);
buffer_from_SSL(&machine->clean_out, machine->ssl);
buffer_from_BIO(&machine->dirty_out, machine->bio_fromssl);
}
if(SSL_get_app_data(machine->ssl) || (SSL_get_shutdown(machine->ssl) &&
buffer_empty(&machine->dirty_out))) {
if(!state_machine_close_dirty(machine))
return 0;
}
return 1;
}
int state_machine_close_clean(state_machine_t *machine)
{
buffer_close(&machine->clean_in);
buffer_close(&machine->clean_out);
if(machine->ssl)
SSL_shutdown(machine->ssl);
state_machine_churn(machine);
if(buffer_empty(&machine->dirty_in) &&
buffer_empty(&machine->dirty_out))
return 0;
return 1;
}
int state_machine_close_dirty(state_machine_t *machine)
{
buffer_close(&machine->dirty_in);
buffer_close(&machine->dirty_out);
buffer_close(&machine->clean_in);
if(machine->ssl)
SSL_free(machine->ssl);
machine->ssl = NULL;
machine->bio_intossl = machine->bio_fromssl = NULL;
if(buffer_empty(&machine->clean_out))
return 0;
return 1;
}
