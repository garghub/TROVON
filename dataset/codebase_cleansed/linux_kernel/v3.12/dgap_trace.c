void dgap_tracer_free(void)
{
if(dgap_trcbuf)
vfree(dgap_trcbuf);
}
