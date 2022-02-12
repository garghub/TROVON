void ieee754_xcpt(struct ieee754xctx *xcp)
{
printk(KERN_DEBUG "floating point exception in \"%s\", type=%s\n",
xcp->op, rtnames[xcp->rt]);
}
