void ieee754_xcpt(struct ieee754xctx *xcp)\r\n{\r\nprintk(KERN_DEBUG "floating point exception in \"%s\", type=%s\n",\r\nxcp->op, rtnames[xcp->rt]);\r\n}
