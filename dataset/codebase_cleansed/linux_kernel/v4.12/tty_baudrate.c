speed_t tty_termios_baud_rate(struct ktermios *termios)
{
unsigned int cbaud;
cbaud = termios->c_cflag & CBAUD;
#ifdef BOTHER
if (cbaud == BOTHER)
return termios->c_ospeed;
#endif
if (cbaud & CBAUDEX) {
cbaud &= ~CBAUDEX;
if (cbaud < 1 || cbaud + 15 > n_baud_table)
termios->c_cflag &= ~CBAUDEX;
else
cbaud += 15;
}
return baud_table[cbaud];
}
speed_t tty_termios_input_baud_rate(struct ktermios *termios)
{
#ifdef IBSHIFT
unsigned int cbaud = (termios->c_cflag >> IBSHIFT) & CBAUD;
if (cbaud == B0)
return tty_termios_baud_rate(termios);
if (cbaud == BOTHER)
return termios->c_ispeed;
if (cbaud & CBAUDEX) {
cbaud &= ~CBAUDEX;
if (cbaud < 1 || cbaud + 15 > n_baud_table)
termios->c_cflag &= ~(CBAUDEX << IBSHIFT);
else
cbaud += 15;
}
return baud_table[cbaud];
#else
return tty_termios_baud_rate(termios);
#endif
}
void tty_termios_encode_baud_rate(struct ktermios *termios,
speed_t ibaud, speed_t obaud)
{
int i = 0;
int ifound = -1, ofound = -1;
int iclose = ibaud/50, oclose = obaud/50;
int ibinput = 0;
if (obaud == 0)
ibaud = 0;
termios->c_ispeed = ibaud;
termios->c_ospeed = obaud;
#ifdef BOTHER
if ((termios->c_cflag & CBAUD) == BOTHER)
oclose = 0;
if (((termios->c_cflag >> IBSHIFT) & CBAUD) == BOTHER)
iclose = 0;
if ((termios->c_cflag >> IBSHIFT) & CBAUD)
ibinput = 1;
#endif
termios->c_cflag &= ~CBAUD;
do {
if (obaud - oclose <= baud_table[i] &&
obaud + oclose >= baud_table[i]) {
termios->c_cflag |= baud_bits[i];
ofound = i;
}
if (ibaud - iclose <= baud_table[i] &&
ibaud + iclose >= baud_table[i]) {
if (ofound == i && !ibinput)
ifound = i;
#ifdef IBSHIFT
else {
ifound = i;
termios->c_cflag |= (baud_bits[i] << IBSHIFT);
}
#endif
}
} while (++i < n_baud_table);
#ifdef BOTHER
if (ofound == -1)
termios->c_cflag |= BOTHER;
if (ifound == -1 && (ibaud != obaud || ibinput))
termios->c_cflag |= (BOTHER << IBSHIFT);
#else
if (ifound == -1 || ofound == -1)
pr_warn_once("tty: Unable to return correct speed data as your architecture needs updating.\n");
#endif
}
void tty_encode_baud_rate(struct tty_struct *tty, speed_t ibaud, speed_t obaud)
{
tty_termios_encode_baud_rate(&tty->termios, ibaud, obaud);
}
