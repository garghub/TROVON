enum ia_css_err ia_css_rmgr_init(void)
{
enum ia_css_err err = IA_CSS_SUCCESS;
err = ia_css_rmgr_init_vbuf(vbuf_ref);
if (err == IA_CSS_SUCCESS)
err = ia_css_rmgr_init_vbuf(vbuf_write);
if (err == IA_CSS_SUCCESS)
err = ia_css_rmgr_init_vbuf(hmm_buffer_pool);
if (err != IA_CSS_SUCCESS)
ia_css_rmgr_uninit();
return err;
}
void ia_css_rmgr_uninit(void)
{
ia_css_rmgr_uninit_vbuf(hmm_buffer_pool);
ia_css_rmgr_uninit_vbuf(vbuf_write);
ia_css_rmgr_uninit_vbuf(vbuf_ref);
}
