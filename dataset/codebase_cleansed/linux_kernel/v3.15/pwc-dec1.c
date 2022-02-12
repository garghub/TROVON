void pwc_dec1_init(struct pwc_device *pdev, const unsigned char *cmd)\r\n{\r\nstruct pwc_dec1_private *pdec = &pdev->dec1;\r\npdec->version = pdev->release;\r\n}
