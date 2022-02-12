void dgnc_tracer_free(void)
{
if (dgnc_trcbuf)
vfree(dgnc_trcbuf);
}
