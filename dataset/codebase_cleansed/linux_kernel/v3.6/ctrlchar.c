static void
ctrlchar_handle_sysrq(struct work_struct *work)
{
handle_sysrq(ctrlchar_sysrq_key);
}
unsigned int
ctrlchar_handle(const unsigned char *buf, int len, struct tty_struct *tty)
{
if ((len < 2) || (len > 3))
return CTRLCHAR_NONE;
if ((buf[0] != '^') && (buf[0] != '\252'))
return CTRLCHAR_NONE;
#ifdef CONFIG_MAGIC_SYSRQ
if (len == 3 && buf[1] == '-') {
ctrlchar_sysrq_key = buf[2];
schedule_work(&ctrlchar_work);
return CTRLCHAR_SYSRQ;
}
#endif
if (len != 2)
return CTRLCHAR_NONE;
switch (tolower(buf[1])) {
case 'c':
return INTR_CHAR(tty) | CTRLCHAR_CTRL;
case 'd':
return EOF_CHAR(tty) | CTRLCHAR_CTRL;
case 'z':
return SUSP_CHAR(tty) | CTRLCHAR_CTRL;
}
return CTRLCHAR_NONE;
}
