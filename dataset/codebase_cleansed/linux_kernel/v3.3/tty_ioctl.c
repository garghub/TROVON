int tty_chars_in_buffer(struct tty_struct *tty)\r\n{\r\nif (tty->ops->chars_in_buffer)\r\nreturn tty->ops->chars_in_buffer(tty);\r\nelse\r\nreturn 0;\r\n}\r\nint tty_write_room(struct tty_struct *tty)\r\n{\r\nif (tty->ops->write_room)\r\nreturn tty->ops->write_room(tty);\r\nreturn 2048;\r\n}\r\nvoid tty_driver_flush_buffer(struct tty_struct *tty)\r\n{\r\nif (tty->ops->flush_buffer)\r\ntty->ops->flush_buffer(tty);\r\n}\r\nvoid tty_throttle(struct tty_struct *tty)\r\n{\r\nmutex_lock(&tty->termios_mutex);\r\nif (!test_and_set_bit(TTY_THROTTLED, &tty->flags) &&\r\ntty->ops->throttle)\r\ntty->ops->throttle(tty);\r\nmutex_unlock(&tty->termios_mutex);\r\n}\r\nvoid tty_unthrottle(struct tty_struct *tty)\r\n{\r\nmutex_lock(&tty->termios_mutex);\r\nif (test_and_clear_bit(TTY_THROTTLED, &tty->flags) &&\r\ntty->ops->unthrottle)\r\ntty->ops->unthrottle(tty);\r\nmutex_unlock(&tty->termios_mutex);\r\n}\r\nvoid tty_wait_until_sent(struct tty_struct *tty, long timeout)\r\n{\r\n#ifdef TTY_DEBUG_WAIT_UNTIL_SENT\r\nchar buf[64];\r\nprintk(KERN_DEBUG "%s wait until sent...\n", tty_name(tty, buf));\r\n#endif\r\nif (!timeout)\r\ntimeout = MAX_SCHEDULE_TIMEOUT;\r\nif (wait_event_interruptible_timeout(tty->write_wait,\r\n!tty_chars_in_buffer(tty), timeout) >= 0) {\r\nif (tty->ops->wait_until_sent)\r\ntty->ops->wait_until_sent(tty, timeout);\r\n}\r\n}\r\nstatic void unset_locked_termios(struct ktermios *termios,\r\nstruct ktermios *old,\r\nstruct ktermios *locked)\r\n{\r\nint i;\r\n#define NOSET_MASK(x, y, z) (x = ((x) & ~(z)) | ((y) & (z)))\r\nif (!locked) {\r\nprintk(KERN_WARNING "Warning?!? termios_locked is NULL.\n");\r\nreturn;\r\n}\r\nNOSET_MASK(termios->c_iflag, old->c_iflag, locked->c_iflag);\r\nNOSET_MASK(termios->c_oflag, old->c_oflag, locked->c_oflag);\r\nNOSET_MASK(termios->c_cflag, old->c_cflag, locked->c_cflag);\r\nNOSET_MASK(termios->c_lflag, old->c_lflag, locked->c_lflag);\r\ntermios->c_line = locked->c_line ? old->c_line : termios->c_line;\r\nfor (i = 0; i < NCCS; i++)\r\ntermios->c_cc[i] = locked->c_cc[i] ?\r\nold->c_cc[i] : termios->c_cc[i];\r\n}\r\nspeed_t tty_termios_baud_rate(struct ktermios *termios)\r\n{\r\nunsigned int cbaud;\r\ncbaud = termios->c_cflag & CBAUD;\r\n#ifdef BOTHER\r\nif (cbaud == BOTHER)\r\nreturn termios->c_ospeed;\r\n#endif\r\nif (cbaud & CBAUDEX) {\r\ncbaud &= ~CBAUDEX;\r\nif (cbaud < 1 || cbaud + 15 > n_baud_table)\r\ntermios->c_cflag &= ~CBAUDEX;\r\nelse\r\ncbaud += 15;\r\n}\r\nreturn baud_table[cbaud];\r\n}\r\nspeed_t tty_termios_input_baud_rate(struct ktermios *termios)\r\n{\r\n#ifdef IBSHIFT\r\nunsigned int cbaud = (termios->c_cflag >> IBSHIFT) & CBAUD;\r\nif (cbaud == B0)\r\nreturn tty_termios_baud_rate(termios);\r\nif (cbaud == BOTHER)\r\nreturn termios->c_ispeed;\r\nif (cbaud & CBAUDEX) {\r\ncbaud &= ~CBAUDEX;\r\nif (cbaud < 1 || cbaud + 15 > n_baud_table)\r\ntermios->c_cflag &= ~(CBAUDEX << IBSHIFT);\r\nelse\r\ncbaud += 15;\r\n}\r\nreturn baud_table[cbaud];\r\n#else\r\nreturn tty_termios_baud_rate(termios);\r\n#endif\r\n}\r\nvoid tty_termios_encode_baud_rate(struct ktermios *termios,\r\nspeed_t ibaud, speed_t obaud)\r\n{\r\nint i = 0;\r\nint ifound = -1, ofound = -1;\r\nint iclose = ibaud/50, oclose = obaud/50;\r\nint ibinput = 0;\r\nif (obaud == 0)\r\nibaud = 0;\r\ntermios->c_ispeed = ibaud;\r\ntermios->c_ospeed = obaud;\r\n#ifdef BOTHER\r\nif ((termios->c_cflag & CBAUD) == BOTHER)\r\noclose = 0;\r\nif (((termios->c_cflag >> IBSHIFT) & CBAUD) == BOTHER)\r\niclose = 0;\r\nif ((termios->c_cflag >> IBSHIFT) & CBAUD)\r\nibinput = 1;\r\n#endif\r\ntermios->c_cflag &= ~CBAUD;\r\ndo {\r\nif (obaud - oclose <= baud_table[i] &&\r\nobaud + oclose >= baud_table[i]) {\r\ntermios->c_cflag |= baud_bits[i];\r\nofound = i;\r\n}\r\nif (ibaud - iclose <= baud_table[i] &&\r\nibaud + iclose >= baud_table[i]) {\r\nif (ofound == i && !ibinput)\r\nifound = i;\r\n#ifdef IBSHIFT\r\nelse {\r\nifound = i;\r\ntermios->c_cflag |= (baud_bits[i] << IBSHIFT);\r\n}\r\n#endif\r\n}\r\n} while (++i < n_baud_table);\r\n#ifdef BOTHER\r\nif (ofound == -1)\r\ntermios->c_cflag |= BOTHER;\r\nif (ifound == -1 && (ibaud != obaud || ibinput))\r\ntermios->c_cflag |= (BOTHER << IBSHIFT);\r\n#else\r\nif (ifound == -1 || ofound == -1) {\r\nprintk_once(KERN_WARNING "tty: Unable to return correct "\r\n"speed data as your architecture needs updating.\n");\r\n}\r\n#endif\r\n}\r\nvoid tty_encode_baud_rate(struct tty_struct *tty, speed_t ibaud, speed_t obaud)\r\n{\r\ntty_termios_encode_baud_rate(tty->termios, ibaud, obaud);\r\n}\r\nspeed_t tty_get_baud_rate(struct tty_struct *tty)\r\n{\r\nspeed_t baud = tty_termios_baud_rate(tty->termios);\r\nif (baud == 38400 && tty->alt_speed) {\r\nif (!tty->warned) {\r\nprintk(KERN_WARNING "Use of setserial/setrocket to "\r\n"set SPD_* flags is deprecated\n");\r\ntty->warned = 1;\r\n}\r\nbaud = tty->alt_speed;\r\n}\r\nreturn baud;\r\n}\r\nvoid tty_termios_copy_hw(struct ktermios *new, struct ktermios *old)\r\n{\r\nnew->c_cflag &= HUPCL | CREAD | CLOCAL;\r\nnew->c_cflag |= old->c_cflag & ~(HUPCL | CREAD | CLOCAL);\r\nnew->c_ispeed = old->c_ispeed;\r\nnew->c_ospeed = old->c_ospeed;\r\n}\r\nint tty_termios_hw_change(struct ktermios *a, struct ktermios *b)\r\n{\r\nif (a->c_ispeed != b->c_ispeed || a->c_ospeed != b->c_ospeed)\r\nreturn 1;\r\nif ((a->c_cflag ^ b->c_cflag) & ~(HUPCL | CREAD | CLOCAL))\r\nreturn 1;\r\nreturn 0;\r\n}\r\nint tty_set_termios(struct tty_struct *tty, struct ktermios *new_termios)\r\n{\r\nstruct ktermios old_termios;\r\nstruct tty_ldisc *ld;\r\nunsigned long flags;\r\nmutex_lock(&tty->termios_mutex);\r\nold_termios = *tty->termios;\r\n*tty->termios = *new_termios;\r\nunset_locked_termios(tty->termios, &old_termios, tty->termios_locked);\r\nif (tty->link && tty->link->packet) {\r\nint extproc = (old_termios.c_lflag & EXTPROC) |\r\n(tty->termios->c_lflag & EXTPROC);\r\nint old_flow = ((old_termios.c_iflag & IXON) &&\r\n(old_termios.c_cc[VSTOP] == '\023') &&\r\n(old_termios.c_cc[VSTART] == '\021'));\r\nint new_flow = (I_IXON(tty) &&\r\nSTOP_CHAR(tty) == '\023' &&\r\nSTART_CHAR(tty) == '\021');\r\nif ((old_flow != new_flow) || extproc) {\r\nspin_lock_irqsave(&tty->ctrl_lock, flags);\r\nif (old_flow != new_flow) {\r\ntty->ctrl_status &= ~(TIOCPKT_DOSTOP | TIOCPKT_NOSTOP);\r\nif (new_flow)\r\ntty->ctrl_status |= TIOCPKT_DOSTOP;\r\nelse\r\ntty->ctrl_status |= TIOCPKT_NOSTOP;\r\n}\r\nif (extproc)\r\ntty->ctrl_status |= TIOCPKT_IOCTL;\r\nspin_unlock_irqrestore(&tty->ctrl_lock, flags);\r\nwake_up_interruptible(&tty->link->read_wait);\r\n}\r\n}\r\nif (tty->ops->set_termios)\r\n(*tty->ops->set_termios)(tty, &old_termios);\r\nelse\r\ntty_termios_copy_hw(tty->termios, &old_termios);\r\nld = tty_ldisc_ref(tty);\r\nif (ld != NULL) {\r\nif (ld->ops->set_termios)\r\n(ld->ops->set_termios)(tty, &old_termios);\r\ntty_ldisc_deref(ld);\r\n}\r\nmutex_unlock(&tty->termios_mutex);\r\nreturn 0;\r\n}\r\nstatic int set_termios(struct tty_struct *tty, void __user *arg, int opt)\r\n{\r\nstruct ktermios tmp_termios;\r\nstruct tty_ldisc *ld;\r\nint retval = tty_check_change(tty);\r\nif (retval)\r\nreturn retval;\r\nmutex_lock(&tty->termios_mutex);\r\nmemcpy(&tmp_termios, tty->termios, sizeof(struct ktermios));\r\nmutex_unlock(&tty->termios_mutex);\r\nif (opt & TERMIOS_TERMIO) {\r\nif (user_termio_to_kernel_termios(&tmp_termios,\r\n(struct termio __user *)arg))\r\nreturn -EFAULT;\r\n#ifdef TCGETS2\r\n} else if (opt & TERMIOS_OLD) {\r\nif (user_termios_to_kernel_termios_1(&tmp_termios,\r\n(struct termios __user *)arg))\r\nreturn -EFAULT;\r\n} else {\r\nif (user_termios_to_kernel_termios(&tmp_termios,\r\n(struct termios2 __user *)arg))\r\nreturn -EFAULT;\r\n}\r\n#else\r\n}\r\nvoid copy_termios(struct tty_struct *tty, struct ktermios *kterm)\r\n{\r\nmutex_lock(&tty->termios_mutex);\r\nmemcpy(kterm, tty->termios, sizeof(struct ktermios));\r\nmutex_unlock(&tty->termios_mutex);\r\n}\r\nstatic void copy_termios_locked(struct tty_struct *tty, struct ktermios *kterm)\r\n{\r\nmutex_lock(&tty->termios_mutex);\r\nmemcpy(kterm, tty->termios_locked, sizeof(struct ktermios));\r\nmutex_unlock(&tty->termios_mutex);\r\n}\r\nstatic int get_termio(struct tty_struct *tty, struct termio __user *termio)\r\n{\r\nstruct ktermios kterm;\r\ncopy_termios(tty, &kterm);\r\nif (kernel_termios_to_user_termio(termio, &kterm))\r\nreturn -EFAULT;\r\nreturn 0;\r\n}\r\nstatic int set_termiox(struct tty_struct *tty, void __user *arg, int opt)\r\n{\r\nstruct termiox tnew;\r\nstruct tty_ldisc *ld;\r\nif (tty->termiox == NULL)\r\nreturn -EINVAL;\r\nif (copy_from_user(&tnew, arg, sizeof(struct termiox)))\r\nreturn -EFAULT;\r\nld = tty_ldisc_ref(tty);\r\nif (ld != NULL) {\r\nif ((opt & TERMIOS_FLUSH) && ld->ops->flush_buffer)\r\nld->ops->flush_buffer(tty);\r\ntty_ldisc_deref(ld);\r\n}\r\nif (opt & TERMIOS_WAIT) {\r\ntty_wait_until_sent(tty, 0);\r\nif (signal_pending(current))\r\nreturn -EINTR;\r\n}\r\nmutex_lock(&tty->termios_mutex);\r\nif (tty->ops->set_termiox)\r\ntty->ops->set_termiox(tty, &tnew);\r\nmutex_unlock(&tty->termios_mutex);\r\nreturn 0;\r\n}\r\nstatic int get_sgflags(struct tty_struct *tty)\r\n{\r\nint flags = 0;\r\nif (!(tty->termios->c_lflag & ICANON)) {\r\nif (tty->termios->c_lflag & ISIG)\r\nflags |= 0x02;\r\nelse\r\nflags |= 0x20;\r\n}\r\nif (tty->termios->c_lflag & ECHO)\r\nflags |= 0x08;\r\nif (tty->termios->c_oflag & OPOST)\r\nif (tty->termios->c_oflag & ONLCR)\r\nflags |= 0x10;\r\nreturn flags;\r\n}\r\nstatic int get_sgttyb(struct tty_struct *tty, struct sgttyb __user *sgttyb)\r\n{\r\nstruct sgttyb tmp;\r\nmutex_lock(&tty->termios_mutex);\r\ntmp.sg_ispeed = tty->termios->c_ispeed;\r\ntmp.sg_ospeed = tty->termios->c_ospeed;\r\ntmp.sg_erase = tty->termios->c_cc[VERASE];\r\ntmp.sg_kill = tty->termios->c_cc[VKILL];\r\ntmp.sg_flags = get_sgflags(tty);\r\nmutex_unlock(&tty->termios_mutex);\r\nreturn copy_to_user(sgttyb, &tmp, sizeof(tmp)) ? -EFAULT : 0;\r\n}\r\nstatic void set_sgflags(struct ktermios *termios, int flags)\r\n{\r\ntermios->c_iflag = ICRNL | IXON;\r\ntermios->c_oflag = 0;\r\ntermios->c_lflag = ISIG | ICANON;\r\nif (flags & 0x02) {\r\ntermios->c_iflag = 0;\r\ntermios->c_lflag &= ~ICANON;\r\n}\r\nif (flags & 0x08) {\r\ntermios->c_lflag |= ECHO | ECHOE | ECHOK |\r\nECHOCTL | ECHOKE | IEXTEN;\r\n}\r\nif (flags & 0x10) {\r\ntermios->c_oflag |= OPOST | ONLCR;\r\n}\r\nif (flags & 0x20) {\r\ntermios->c_iflag = 0;\r\ntermios->c_lflag &= ~(ISIG | ICANON);\r\n}\r\nif (!(termios->c_lflag & ICANON)) {\r\ntermios->c_cc[VMIN] = 1;\r\ntermios->c_cc[VTIME] = 0;\r\n}\r\n}\r\nstatic int set_sgttyb(struct tty_struct *tty, struct sgttyb __user *sgttyb)\r\n{\r\nint retval;\r\nstruct sgttyb tmp;\r\nstruct ktermios termios;\r\nretval = tty_check_change(tty);\r\nif (retval)\r\nreturn retval;\r\nif (copy_from_user(&tmp, sgttyb, sizeof(tmp)))\r\nreturn -EFAULT;\r\nmutex_lock(&tty->termios_mutex);\r\ntermios = *tty->termios;\r\ntermios.c_cc[VERASE] = tmp.sg_erase;\r\ntermios.c_cc[VKILL] = tmp.sg_kill;\r\nset_sgflags(&termios, tmp.sg_flags);\r\n#ifdef BOTHER\r\ntty_termios_encode_baud_rate(&termios, termios.c_ispeed,\r\ntermios.c_ospeed);\r\n#endif\r\nmutex_unlock(&tty->termios_mutex);\r\ntty_set_termios(tty, &termios);\r\nreturn 0;\r\n}\r\nstatic int get_tchars(struct tty_struct *tty, struct tchars __user *tchars)\r\n{\r\nstruct tchars tmp;\r\nmutex_lock(&tty->termios_mutex);\r\ntmp.t_intrc = tty->termios->c_cc[VINTR];\r\ntmp.t_quitc = tty->termios->c_cc[VQUIT];\r\ntmp.t_startc = tty->termios->c_cc[VSTART];\r\ntmp.t_stopc = tty->termios->c_cc[VSTOP];\r\ntmp.t_eofc = tty->termios->c_cc[VEOF];\r\ntmp.t_brkc = tty->termios->c_cc[VEOL2];\r\nmutex_unlock(&tty->termios_mutex);\r\nreturn copy_to_user(tchars, &tmp, sizeof(tmp)) ? -EFAULT : 0;\r\n}\r\nstatic int set_tchars(struct tty_struct *tty, struct tchars __user *tchars)\r\n{\r\nstruct tchars tmp;\r\nif (copy_from_user(&tmp, tchars, sizeof(tmp)))\r\nreturn -EFAULT;\r\nmutex_lock(&tty->termios_mutex);\r\ntty->termios->c_cc[VINTR] = tmp.t_intrc;\r\ntty->termios->c_cc[VQUIT] = tmp.t_quitc;\r\ntty->termios->c_cc[VSTART] = tmp.t_startc;\r\ntty->termios->c_cc[VSTOP] = tmp.t_stopc;\r\ntty->termios->c_cc[VEOF] = tmp.t_eofc;\r\ntty->termios->c_cc[VEOL2] = tmp.t_brkc;\r\nmutex_unlock(&tty->termios_mutex);\r\nreturn 0;\r\n}\r\nstatic int get_ltchars(struct tty_struct *tty, struct ltchars __user *ltchars)\r\n{\r\nstruct ltchars tmp;\r\nmutex_lock(&tty->termios_mutex);\r\ntmp.t_suspc = tty->termios->c_cc[VSUSP];\r\ntmp.t_dsuspc = tty->termios->c_cc[VSUSP];\r\ntmp.t_rprntc = tty->termios->c_cc[VREPRINT];\r\ntmp.t_flushc = tty->termios->c_cc[VEOL2];\r\ntmp.t_werasc = tty->termios->c_cc[VWERASE];\r\ntmp.t_lnextc = tty->termios->c_cc[VLNEXT];\r\nmutex_unlock(&tty->termios_mutex);\r\nreturn copy_to_user(ltchars, &tmp, sizeof(tmp)) ? -EFAULT : 0;\r\n}\r\nstatic int set_ltchars(struct tty_struct *tty, struct ltchars __user *ltchars)\r\n{\r\nstruct ltchars tmp;\r\nif (copy_from_user(&tmp, ltchars, sizeof(tmp)))\r\nreturn -EFAULT;\r\nmutex_lock(&tty->termios_mutex);\r\ntty->termios->c_cc[VSUSP] = tmp.t_suspc;\r\ntty->termios->c_cc[VEOL2] = tmp.t_dsuspc;\r\ntty->termios->c_cc[VREPRINT] = tmp.t_rprntc;\r\ntty->termios->c_cc[VEOL2] = tmp.t_flushc;\r\ntty->termios->c_cc[VWERASE] = tmp.t_werasc;\r\ntty->termios->c_cc[VLNEXT] = tmp.t_lnextc;\r\nmutex_unlock(&tty->termios_mutex);\r\nreturn 0;\r\n}\r\nstatic int send_prio_char(struct tty_struct *tty, char ch)\r\n{\r\nint was_stopped = tty->stopped;\r\nif (tty->ops->send_xchar) {\r\ntty->ops->send_xchar(tty, ch);\r\nreturn 0;\r\n}\r\nif (tty_write_lock(tty, 0) < 0)\r\nreturn -ERESTARTSYS;\r\nif (was_stopped)\r\nstart_tty(tty);\r\ntty->ops->write(tty, &ch, 1);\r\nif (was_stopped)\r\nstop_tty(tty);\r\ntty_write_unlock(tty);\r\nreturn 0;\r\n}\r\nstatic int tty_change_softcar(struct tty_struct *tty, int arg)\r\n{\r\nint ret = 0;\r\nint bit = arg ? CLOCAL : 0;\r\nstruct ktermios old;\r\nmutex_lock(&tty->termios_mutex);\r\nold = *tty->termios;\r\ntty->termios->c_cflag &= ~CLOCAL;\r\ntty->termios->c_cflag |= bit;\r\nif (tty->ops->set_termios)\r\ntty->ops->set_termios(tty, &old);\r\nif ((tty->termios->c_cflag & CLOCAL) != bit)\r\nret = -EINVAL;\r\nmutex_unlock(&tty->termios_mutex);\r\nreturn ret;\r\n}\r\nint tty_mode_ioctl(struct tty_struct *tty, struct file *file,\r\nunsigned int cmd, unsigned long arg)\r\n{\r\nstruct tty_struct *real_tty;\r\nvoid __user *p = (void __user *)arg;\r\nint ret = 0;\r\nstruct ktermios kterm;\r\nBUG_ON(file == NULL);\r\nif (tty->driver->type == TTY_DRIVER_TYPE_PTY &&\r\ntty->driver->subtype == PTY_TYPE_MASTER)\r\nreal_tty = tty->link;\r\nelse\r\nreal_tty = tty;\r\nswitch (cmd) {\r\n#ifdef TIOCGETP\r\ncase TIOCGETP:\r\nreturn get_sgttyb(real_tty, (struct sgttyb __user *) arg);\r\ncase TIOCSETP:\r\ncase TIOCSETN:\r\nreturn set_sgttyb(real_tty, (struct sgttyb __user *) arg);\r\n#endif\r\n#ifdef TIOCGETC\r\ncase TIOCGETC:\r\nreturn get_tchars(real_tty, p);\r\ncase TIOCSETC:\r\nreturn set_tchars(real_tty, p);\r\n#endif\r\n#ifdef TIOCGLTC\r\ncase TIOCGLTC:\r\nreturn get_ltchars(real_tty, p);\r\ncase TIOCSLTC:\r\nreturn set_ltchars(real_tty, p);\r\n#endif\r\ncase TCSETSF:\r\nreturn set_termios(real_tty, p, TERMIOS_FLUSH | TERMIOS_WAIT | TERMIOS_OLD);\r\ncase TCSETSW:\r\nreturn set_termios(real_tty, p, TERMIOS_WAIT | TERMIOS_OLD);\r\ncase TCSETS:\r\nreturn set_termios(real_tty, p, TERMIOS_OLD);\r\n#ifndef TCGETS2\r\ncase TCGETS:\r\ncopy_termios(real_tty, &kterm);\r\nif (kernel_termios_to_user_termios((struct termios __user *)arg, &kterm))\r\nret = -EFAULT;\r\nreturn ret;\r\n#else\r\ncase TCGETS:\r\ncopy_termios(real_tty, &kterm);\r\nif (kernel_termios_to_user_termios_1((struct termios __user *)arg, &kterm))\r\nret = -EFAULT;\r\nreturn ret;\r\ncase TCGETS2:\r\ncopy_termios(real_tty, &kterm);\r\nif (kernel_termios_to_user_termios((struct termios2 __user *)arg, &kterm))\r\nret = -EFAULT;\r\nreturn ret;\r\ncase TCSETSF2:\r\nreturn set_termios(real_tty, p, TERMIOS_FLUSH | TERMIOS_WAIT);\r\ncase TCSETSW2:\r\nreturn set_termios(real_tty, p, TERMIOS_WAIT);\r\ncase TCSETS2:\r\nreturn set_termios(real_tty, p, 0);\r\n#endif\r\ncase TCGETA:\r\nreturn get_termio(real_tty, p);\r\ncase TCSETAF:\r\nreturn set_termios(real_tty, p, TERMIOS_FLUSH | TERMIOS_WAIT | TERMIOS_TERMIO);\r\ncase TCSETAW:\r\nreturn set_termios(real_tty, p, TERMIOS_WAIT | TERMIOS_TERMIO);\r\ncase TCSETA:\r\nreturn set_termios(real_tty, p, TERMIOS_TERMIO);\r\n#ifndef TCGETS2\r\ncase TIOCGLCKTRMIOS:\r\ncopy_termios_locked(real_tty, &kterm);\r\nif (kernel_termios_to_user_termios((struct termios __user *)arg, &kterm))\r\nret = -EFAULT;\r\nreturn ret;\r\ncase TIOCSLCKTRMIOS:\r\nif (!capable(CAP_SYS_ADMIN))\r\nreturn -EPERM;\r\ncopy_termios_locked(real_tty, &kterm);\r\nif (user_termios_to_kernel_termios(&kterm,\r\n(struct termios __user *) arg))\r\nreturn -EFAULT;\r\nmutex_lock(&real_tty->termios_mutex);\r\nmemcpy(real_tty->termios_locked, &kterm, sizeof(struct ktermios));\r\nmutex_unlock(&real_tty->termios_mutex);\r\nreturn 0;\r\n#else\r\ncase TIOCGLCKTRMIOS:\r\ncopy_termios_locked(real_tty, &kterm);\r\nif (kernel_termios_to_user_termios_1((struct termios __user *)arg, &kterm))\r\nret = -EFAULT;\r\nreturn ret;\r\ncase TIOCSLCKTRMIOS:\r\nif (!capable(CAP_SYS_ADMIN))\r\nreturn -EPERM;\r\ncopy_termios_locked(real_tty, &kterm);\r\nif (user_termios_to_kernel_termios_1(&kterm,\r\n(struct termios __user *) arg))\r\nreturn -EFAULT;\r\nmutex_lock(&real_tty->termios_mutex);\r\nmemcpy(real_tty->termios_locked, &kterm, sizeof(struct ktermios));\r\nmutex_unlock(&real_tty->termios_mutex);\r\nreturn ret;\r\n#endif\r\n#ifdef TCGETX\r\ncase TCGETX: {\r\nstruct termiox ktermx;\r\nif (real_tty->termiox == NULL)\r\nreturn -EINVAL;\r\nmutex_lock(&real_tty->termios_mutex);\r\nmemcpy(&ktermx, real_tty->termiox, sizeof(struct termiox));\r\nmutex_unlock(&real_tty->termios_mutex);\r\nif (copy_to_user(p, &ktermx, sizeof(struct termiox)))\r\nret = -EFAULT;\r\nreturn ret;\r\n}\r\ncase TCSETX:\r\nreturn set_termiox(real_tty, p, 0);\r\ncase TCSETXW:\r\nreturn set_termiox(real_tty, p, TERMIOS_WAIT);\r\ncase TCSETXF:\r\nreturn set_termiox(real_tty, p, TERMIOS_FLUSH);\r\n#endif\r\ncase TIOCGSOFTCAR:\r\ncopy_termios(real_tty, &kterm);\r\nret = put_user((kterm.c_cflag & CLOCAL) ? 1 : 0,\r\n(int __user *)arg);\r\nreturn ret;\r\ncase TIOCSSOFTCAR:\r\nif (get_user(arg, (unsigned int __user *) arg))\r\nreturn -EFAULT;\r\nreturn tty_change_softcar(real_tty, arg);\r\ndefault:\r\nreturn -ENOIOCTLCMD;\r\n}\r\n}\r\nint tty_perform_flush(struct tty_struct *tty, unsigned long arg)\r\n{\r\nstruct tty_ldisc *ld;\r\nint retval = tty_check_change(tty);\r\nif (retval)\r\nreturn retval;\r\nld = tty_ldisc_ref_wait(tty);\r\nswitch (arg) {\r\ncase TCIFLUSH:\r\nif (ld && ld->ops->flush_buffer)\r\nld->ops->flush_buffer(tty);\r\nbreak;\r\ncase TCIOFLUSH:\r\nif (ld && ld->ops->flush_buffer)\r\nld->ops->flush_buffer(tty);\r\ncase TCOFLUSH:\r\ntty_driver_flush_buffer(tty);\r\nbreak;\r\ndefault:\r\ntty_ldisc_deref(ld);\r\nreturn -EINVAL;\r\n}\r\ntty_ldisc_deref(ld);\r\nreturn 0;\r\n}\r\nint n_tty_ioctl_helper(struct tty_struct *tty, struct file *file,\r\nunsigned int cmd, unsigned long arg)\r\n{\r\nunsigned long flags;\r\nint retval;\r\nswitch (cmd) {\r\ncase TCXONC:\r\nretval = tty_check_change(tty);\r\nif (retval)\r\nreturn retval;\r\nswitch (arg) {\r\ncase TCOOFF:\r\nif (!tty->flow_stopped) {\r\ntty->flow_stopped = 1;\r\nstop_tty(tty);\r\n}\r\nbreak;\r\ncase TCOON:\r\nif (tty->flow_stopped) {\r\ntty->flow_stopped = 0;\r\nstart_tty(tty);\r\n}\r\nbreak;\r\ncase TCIOFF:\r\nif (STOP_CHAR(tty) != __DISABLED_CHAR)\r\nreturn send_prio_char(tty, STOP_CHAR(tty));\r\nbreak;\r\ncase TCION:\r\nif (START_CHAR(tty) != __DISABLED_CHAR)\r\nreturn send_prio_char(tty, START_CHAR(tty));\r\nbreak;\r\ndefault:\r\nreturn -EINVAL;\r\n}\r\nreturn 0;\r\ncase TCFLSH:\r\nreturn tty_perform_flush(tty, arg);\r\ncase TIOCPKT:\r\n{\r\nint pktmode;\r\nif (tty->driver->type != TTY_DRIVER_TYPE_PTY ||\r\ntty->driver->subtype != PTY_TYPE_MASTER)\r\nreturn -ENOTTY;\r\nif (get_user(pktmode, (int __user *) arg))\r\nreturn -EFAULT;\r\nspin_lock_irqsave(&tty->ctrl_lock, flags);\r\nif (pktmode) {\r\nif (!tty->packet) {\r\ntty->packet = 1;\r\ntty->link->ctrl_status = 0;\r\n}\r\n} else\r\ntty->packet = 0;\r\nspin_unlock_irqrestore(&tty->ctrl_lock, flags);\r\nreturn 0;\r\n}\r\ndefault:\r\nreturn tty_mode_ioctl(tty, file, cmd, arg);\r\n}\r\n}\r\nlong n_tty_compat_ioctl_helper(struct tty_struct *tty, struct file *file,\r\nunsigned int cmd, unsigned long arg)\r\n{\r\nswitch (cmd) {\r\ncase TIOCGLCKTRMIOS:\r\ncase TIOCSLCKTRMIOS:\r\nreturn tty_mode_ioctl(tty, file, cmd, (unsigned long) compat_ptr(arg));\r\ndefault:\r\nreturn -ENOIOCTLCMD;\r\n}\r\n}
