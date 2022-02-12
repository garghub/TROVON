int wl_ucode_data_init(struct wl_info *wl)
{
int rc;
rc = wl_check_firmwares(wl);
rc = rc < 0 ? rc : wl_ucode_init_buf(wl, (void **)&d11lcn0bsinitvals24,
D11LCN0BSINITVALS24);
rc = rc < 0 ? rc : wl_ucode_init_buf(wl, (void **)&d11lcn0initvals24,
D11LCN0INITVALS24);
rc = rc < 0 ? rc : wl_ucode_init_buf(wl, (void **)&d11lcn1bsinitvals24,
D11LCN1BSINITVALS24);
rc = rc < 0 ? rc : wl_ucode_init_buf(wl, (void **)&d11lcn1initvals24,
D11LCN1INITVALS24);
rc = rc < 0 ? rc : wl_ucode_init_buf(wl, (void **)&d11lcn2bsinitvals24,
D11LCN2BSINITVALS24);
rc = rc < 0 ? rc : wl_ucode_init_buf(wl, (void **)&d11lcn2initvals24,
D11LCN2INITVALS24);
rc = rc < 0 ? rc : wl_ucode_init_buf(wl, (void **)&d11n0absinitvals16,
D11N0ABSINITVALS16);
rc = rc < 0 ? rc : wl_ucode_init_buf(wl, (void **)&d11n0bsinitvals16,
D11N0BSINITVALS16);
rc = rc < 0 ? rc : wl_ucode_init_buf(wl, (void **)&d11n0initvals16,
D11N0INITVALS16);
rc = rc < 0 ? rc : wl_ucode_init_buf(wl, (void **)&bcm43xx_16_mimo,
D11UCODE_OVERSIGHT16_MIMO);
rc = rc < 0 ? rc : wl_ucode_init_uint(wl, &bcm43xx_16_mimosz,
D11UCODE_OVERSIGHT16_MIMOSZ);
rc = rc < 0 ? rc : wl_ucode_init_buf(wl, (void **)&bcm43xx_24_lcn,
D11UCODE_OVERSIGHT24_LCN);
rc = rc < 0 ? rc : wl_ucode_init_uint(wl, &bcm43xx_24_lcnsz,
D11UCODE_OVERSIGHT24_LCNSZ);
rc = rc < 0 ? rc : wl_ucode_init_buf(wl, (void **)&bcm43xx_bommajor,
D11UCODE_OVERSIGHT_BOMMAJOR);
rc = rc < 0 ? rc : wl_ucode_init_buf(wl, (void **)&bcm43xx_bomminor,
D11UCODE_OVERSIGHT_BOMMINOR);
return rc;
}
void wl_ucode_data_free(void)
{
wl_ucode_free_buf((void *)d11lcn0bsinitvals24);
wl_ucode_free_buf((void *)d11lcn0initvals24);
wl_ucode_free_buf((void *)d11lcn1bsinitvals24);
wl_ucode_free_buf((void *)d11lcn1initvals24);
wl_ucode_free_buf((void *)d11lcn2bsinitvals24);
wl_ucode_free_buf((void *)d11lcn2initvals24);
wl_ucode_free_buf((void *)d11n0absinitvals16);
wl_ucode_free_buf((void *)d11n0bsinitvals16);
wl_ucode_free_buf((void *)d11n0initvals16);
wl_ucode_free_buf((void *)bcm43xx_16_mimo);
wl_ucode_free_buf((void *)bcm43xx_24_lcn);
wl_ucode_free_buf((void *)bcm43xx_bommajor);
wl_ucode_free_buf((void *)bcm43xx_bomminor);
return;
}
