void
makeseg(char *eth1, char *eth2, char *ip1, char *ip2, char *p1, char *p2, int *s1, int *s2, char *flags, int len)
{
int i;
printf("2002/01/07 00:00:%02d.%06d\n", ts/1000000, ts%1000000);
printf("0000 %s %s 08 00\n", eth1, eth2);
printf("000e 45 00 %02x %02x 00 00 00 00 40 06 00 00 %s %s\n", (len+40)>>8, (len+40)&0xff, ip1, ip2);
printf("0022 %s %s %02x %02x %02x %02x %02x %02x %02x %02x 50 %s 80 00 00 00 00 00", p1, p2,
((*s1)>>24)&0xff,
((*s1)>>16)&0xff,
((*s1)>>8)&0xff,
((*s1))&0xff,
((*s2)>>24)&0xff,
((*s2)>>16)&0xff,
((*s2)>>8)&0xff,
((*s2))&0xff,
flags );
for(i=0;i<(len<(snap_len-40)?len:snap_len-40);i++)printf(" 00");
printf("\n");
printf("\n");
(*s1)+=len;
}
int next_ack_due()
{
int slot = next_slot;
int ack_lost = 0, seg_lost = 0;
if (next_slot == first_slot)
return (((unsigned int)(1<<31)) - 1);
while (seg_hist[slot].flags & (SEG_ACK_LOST || SEG_SEG_LOST)) {
if (seg_hist[slot].flags & SEG_ACK_LOST)
ack_lost++;
if (seg_hist[slot].flags & SEG_SEG_LOST)
seg_lost++;
slot = (slot + 1) % SEG_HIST_SIZE;
}
if (slot == next_slot)
return (((unsigned int)(1<<31)) - 1);
if (slot == first_slot && next_slot == ((first_slot + 1) % SEG_HIST_SIZE))
return (seg_hist[first_slot].ts + ack_delay + jitter);
if (seg_lost)
return (seg_hist[slot].ts + ack_delay + jitter);
if (ack_lost) {
if (delayed_ack) {
if (((first_slot + 1 + 2 * ack_lost) % SEG_HIST_SIZE) >= next_slot)
return (((unsigned int)(1<<31)) - 1);
else
return seg_hist[(first_slot + 1 + 2 * ack_lost) % SEG_HIST_SIZE].ts +
ack_delay + jitter;
}
else
return seg_hist[slot].ts + ack_delay + jitter;
}
else {
if (delayed_ack)
return (seg_hist[(first_slot + 1)%SEG_HIST_SIZE].ts+ack_delay+jitter);
else
return (seg_hist[first_slot].ts+ack_delay+jitter);
}
}
int
gen_next_ack(int force, int spacing)
{
int seq_to_ack, new_ts, data_acked;
seq_to_ack = seg_hist[first_slot].seq_num + seg_hist[first_slot].len;
used_win = used_win - seg_hist[first_slot].len;
data_acked = seg_hist[first_slot].len;
new_ts = seg_hist[first_slot].ts + ack_delay;
first_slot = (first_slot + 1) % SEG_HIST_SIZE;
if (delayed_ack && (first_slot != next_slot)) {
seq_to_ack += seg_hist[first_slot].len;
used_win = used_win - seg_hist[first_slot].len;
data_acked += seg_hist[first_slot].len;
new_ts = seg_hist[first_slot].ts + ack_delay;
first_slot = (first_slot + 1) % SEG_HIST_SIZE;
}
if (new_ts + jitter <= ts)
ts++;
else
ts = new_ts + jitter;
jitter = (rand() % 10 - 5);
makeseg(eth_2, eth_1, ip_2, ip_1, port_2, port_1, &seq_2, &seq_to_ack, "10", 0);
if (cwnd >= ssthresh)
cwnd += (1460*data_acked)/cwnd;
else
cwnd = cwnd + data_acked;
if (verbose) fprintf(stderr, "Ack rcvd. ts: %d, data_acked: %d, cwnd: %d, window: %d\n",
ts, data_acked, cwnd, window);
if (cwnd > window) cwnd = window;
}
void
makeackedrun(int len, int spacing, int ackdelay)
{
int next_ack_ts=0;
if (verbose) fprintf(stderr, "makeackedrun: Len=%d, spacing=%d, ackdelay=%d\n",
len, spacing, ackdelay);
while(len>0){
int seglen, saved_seq;
seglen=(len>1460)?1460:len;
if (seglen > (cwnd - used_win)) seglen = cwnd - used_win;
len-=seglen;
saved_seq = seq_1;
if (verbose) fprintf(stderr, "Sending segment. ts: %d, jitter: %d\n", ts, jitter);
if(len){
makeseg(eth_1, eth_2, ip_1, ip_2, port_1, port_2, &seq_1, &seq_2, "10", seglen);
} else {
makeseg(eth_1, eth_2, ip_1, ip_2, port_1, port_2, &seq_1, &seq_2, "18", seglen);
}
add_seg_sent(saved_seq, seglen);
jitter = (rand()%10) - 5;
if (verbose) fprintf(stderr, "used win: %d, cwnd: %d\n", used_win, cwnd);
if ((next_ack_ts = next_ack_due()) < ts + spacing + jitter) {
int old_ts = ts;
if (verbose) fprintf(stderr, "Non forced ACK ...ts + spacing + jitter:%d, jitter: %d\n", ts + spacing + jitter, jitter);
gen_next_ack(NO_FORCE_ACK, spacing);
if (old_ts + spacing + jitter <= ts)
ts++;
else
ts = old_ts + spacing + jitter;
} else if (used_win == cwnd) {
if (verbose) fprintf(stderr, "Forced ACK ... \n");
gen_next_ack(FORCE_ACK, spacing);
ts+=(spacing+jitter);
}
else {
ts+=(spacing+jitter);
}
if (verbose) fprintf(stderr, "Next Ack Due: %d\n", next_ack_ts);
}
}
void
makeackedrundroppedtail8kb(int len, int spacing, int ackdelay)
{
int old_seq1;
int dropped_tail;
int i;
int num_dupes;
if (verbose) fprintf(stderr, "makeackedrundroppedtail8kB: Len=%d, spacing=%d, ackdelay=%d\n",
len, spacing, ackdelay);
old_seq1=seq_1;
while(len>0){
int seglen;
seglen=(len>1460)?1460:len;
len-=seglen;
if(seglen==1460){
makeseg(eth_1, eth_2, ip_1, ip_2, port_1, port_2, &seq_1, &seq_2, "10", seglen);
} else {
makeseg(eth_1, eth_2, ip_1, ip_2, port_1, port_2, &seq_1, &seq_2, "18", seglen);
}
ts+=spacing;
}
ts+=ackdelay;
i=0;
num_dupes=-1;
dropped_tail=0;
while(old_seq1!=seq_1){
int ack_len;
ack_len=((seq_1-old_seq1)>2920)?2920:(seq_1-old_seq1);
i++;
if(i==6){
dropped_tail=old_seq1;
}
old_seq1+=ack_len;
if(i<6){
makeseg(eth_2, eth_1, ip_2, ip_1, port_2, port_1, &seq_2, &old_seq1, "10", 0);
} else if (i==6) {
makeseg(eth_2, eth_1, ip_2, ip_1, port_2, port_1, &seq_2, &dropped_tail, "10", 0);
num_dupes+=2;
} else {
makeseg(eth_2, eth_1, ip_2, ip_1, port_2, port_1, &seq_2, &dropped_tail, "10", 0);
makeseg(eth_2, eth_1, ip_2, ip_1, port_2, port_1, &seq_2, &dropped_tail, "10", 0);
num_dupes+=2;
}
ts+=spacing/2;
}
if(!dropped_tail){
return;
}
if(num_dupes<3){
int seglen;
ts+=1000000;
seglen=((seq_1-dropped_tail)>1460)?1460:(seq_1-dropped_tail);
if(seglen==1460){
makeseg(eth_1, eth_2, ip_1, ip_2, port_1, port_2, &dropped_tail, &seq_2, "10", seglen);
} else {
makeseg(eth_1, eth_2, ip_1, ip_2, port_1, port_2, &dropped_tail, &seq_2, "18", seglen);
}
ts+=ackdelay;
makeseg(eth_2, eth_1, ip_2, ip_1, port_2, port_1, &seq_2, &seq_1, "10", 0);
ts+=spacing;
return;
}
while(dropped_tail!=seq_1){
int seglen;
int ack;
seglen=((seq_1-dropped_tail)>1460)?1460:(seq_1-dropped_tail);
if(seglen==1460){
makeseg(eth_1, eth_2, ip_1, ip_2, port_1, port_2, &dropped_tail, &seq_2, "10", seglen);
} else {
makeseg(eth_1, eth_2, ip_1, ip_2, port_1, port_2, &dropped_tail, &seq_2, "18", seglen);
}
ts+=ackdelay;
ack=dropped_tail;
makeseg(eth_2, eth_1, ip_2, ip_1, port_2, port_1, &seq_2, &ack, "10", 0);
ts+=spacing;
}
}
void usage()
{
fprintf(stderr, "Usage: mkcap [OPTIONS], where\n");
fprintf(stderr, "\t-a <ack-delay> is the delay to an ACK (SRT)\n");
fprintf(stderr, "\t-b <bytes-to-send> is the bytes to send on connection\n");
fprintf(stderr, "\t-i <ip-addr-hex> is the sender IP address in hex\n");
fprintf(stderr, "\t-I <ip-addr-hex> is the recipient IP address in hex\n");
fprintf(stderr, "\t-n <ISN> is almost the ISN for the sender\n");
fprintf(stderr, "\t-N <ISN> is almost the ISN for the recipient\n");
fprintf(stderr, "\t-p <port-number-hex> is the port number for sender\n");
fprintf(stderr, "\t-P <port-number-hex> is the port number for recipient\n");
fprintf(stderr, "\t-s <send-spacing> is the send spacing\n");
fprintf(stderr, "\t-w <window-size> is the window size\n");
}
int
all_digits(char *str)
{
int i;
if (!str || !(*str)) {
return 0;
}
for (i = 0; str[i]; i++) {
if (!isdigit(str[i]))
return 0;
}
return 1;
}
void
process_drop_list(char *drop_list)
{
int commas=0;
char *tok, *save;
if (!drop_list || !(*drop_list)) {
fprintf(stderr, "Strange drop list. NULL or an empty string. No drops!\n");
return;
}
save = (char *)g_strdup(drop_list);
for (tok=(char *)strtok(drop_list, ","); tok; tok=(char *)strtok(NULL, ",")) {
commas++;
}
seg_drop_count = (commas+1)/2;
drops = (seg_drop_t *)g_malloc(sizeof(seg_drop_t) * seg_drop_count);
if (!drops) {
fprintf(stderr, "Unable to allocate space for drops ... going without!\n");
seg_drop_count = 0;
g_free(save);
return;
}
commas = 0;
for (tok=(char *)strtok(save, ","); tok; tok=(char *)strtok(NULL, ",")) {
int num = atoi(tok);
if (!all_digits(tok)) {
fprintf(stderr, "Error in segment offset or count. Not all digits: %s\n",
tok);
fprintf(stderr, "No packet drops being performed!\n");
g_free(save);
g_free(drops);
seg_drop_count = 0; drops = NULL;
return;
}
if (num == 0) num = 1;
if (commas % 2)
drops[commas / 2].drop_seg_count = num;
else
drops[commas / 2].drop_seg_start = num;
}
g_free(save);
}
int
main(int argc, char *argv[])
{
int i;
int len;
int type;
int cnt;
extern char *optarg;
extern int optind;
int opt;
while ((opt = getopt(argc, argv, "a:b:d:Di:I:j:l:n:N:p:P:r:s:vw:")) != EOF) {
switch (opt) {
case 'a':
ack_delay = atoi(optarg);
break;
case 'b':
total_bytes = atoi(optarg);
break;
case 'd':
process_drop_list(optarg);
break;
case 'D':
tcp_nodelay = (tcp_nodelay + 1) % 1;
break;
case 'i':
ip_1 = optarg;
break;
case 'I':
ip_2 = optarg;
break;
case 'l':
snap_len = atoi(optarg);
break;
case 'n':
seq_1 = atoi(optarg);
break;
case 'N':
seq_2 = atoi(optarg);
break;
case 'p':
port_1 = optarg;
break;
case 'P':
port_2 = optarg;
break;
case 'r':
run_type = atoi(optarg);
break;
case 's':
send_spacing = atoi(optarg);
break;
case 'v':
verbose++;
break;
case 'w':
window = atoi(optarg);
ssthresh = window / 2;
break;
default:
usage();
break;
}
}
if (verbose) fprintf(stderr, "IP1: %s, IP2: %s, P1: %s, P2: %s, Ack Delay: %d, Send Spacing: %d\n",
ip_1, ip_2, port_1, port_2, ack_delay, send_spacing);
if (run_type == 0) {
makeackedrun(total_bytes, send_spacing, ack_delay);
}
else {
for(cnt=0;cnt<200;cnt++){
type=rand()%150;
if(type<75){
int j;
j=5+rand()%10;
for(i=0;i<j;i++){
makeackedrun(32768, send_spacing, ack_delay);
}
} else if(type<90) {
int j;
j=4+rand()%4;
for(i=0;i<j;i++){
len=100+rand()&0xfff;
makeackedrun(len, send_spacing, ack_delay);
}
} else {
for(i=0;i<5;i++){
len=100+rand()&0x3fff+0x1fff;
makeackedrun(len, send_spacing, ack_delay);
}
}
}
}
return 0;
}
