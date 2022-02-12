static int sockmap_test_sockets(int rate, int dot)
{
int i, sc, err, max_fd, one = 1;
int s1, s2, c1, c2, p1, p2;
struct sockaddr_in addr;
struct timeval timeout;
char buf[1024] = {0};
int *fds[4] = {&s1, &s2, &c1, &c2};
fd_set w;
s1 = s2 = p1 = p2 = c1 = c2 = 0;
for (i = 0; i < 4; i++) {
*fds[i] = socket(AF_INET, SOCK_STREAM, 0);
if (*fds[i] < 0) {
perror("socket s1 failed()");
err = *fds[i];
goto out;
}
}
for (i = 0; i < 2; i++) {
err = setsockopt(*fds[i], SOL_SOCKET, SO_REUSEADDR,
(char *)&one, sizeof(one));
if (err) {
perror("setsockopt failed()");
goto out;
}
}
for (i = 0; i < 4; i++) {
err = ioctl(*fds[i], FIONBIO, (char *)&one);
if (err < 0) {
perror("ioctl s1 failed()");
goto out;
}
}
memset(&addr, 0, sizeof(struct sockaddr_in));
addr.sin_family = AF_INET;
addr.sin_addr.s_addr = inet_addr("127.0.0.1");
addr.sin_port = htons(S1_PORT);
err = bind(s1, (struct sockaddr *)&addr, sizeof(addr));
if (err < 0) {
perror("bind s1 failed()\n");
goto out;
}
addr.sin_port = htons(S2_PORT);
err = bind(s2, (struct sockaddr *)&addr, sizeof(addr));
if (err < 0) {
perror("bind s2 failed()\n");
goto out;
}
addr.sin_port = htons(S1_PORT);
err = listen(s1, 32);
if (err < 0) {
perror("listen s1 failed()\n");
goto out;
}
addr.sin_port = htons(S2_PORT);
err = listen(s2, 32);
if (err < 0) {
perror("listen s1 failed()\n");
goto out;
}
addr.sin_port = htons(S1_PORT);
err = connect(c1, (struct sockaddr *)&addr, sizeof(addr));
if (err < 0 && errno != EINPROGRESS) {
perror("connect c1 failed()\n");
goto out;
}
addr.sin_port = htons(S2_PORT);
err = connect(c2, (struct sockaddr *)&addr, sizeof(addr));
if (err < 0 && errno != EINPROGRESS) {
perror("connect c2 failed()\n");
goto out;
}
p1 = accept(s1, NULL, NULL);
if (p1 < 0) {
perror("accept s1 failed()\n");
goto out;
}
p2 = accept(s2, NULL, NULL);
if (p2 < 0) {
perror("accept s1 failed()\n");
goto out;
}
max_fd = p2;
timeout.tv_sec = 10;
timeout.tv_usec = 0;
printf("connected sockets: c1 <-> p1, c2 <-> p2\n");
printf("cgroups binding: c1(%i) <-> s1(%i) - - - c2(%i) <-> s2(%i)\n",
c1, s1, c2, s2);
sc = send(c1, buf, sizeof(buf), 0);
if (sc < 0) {
perror("send failed()\n");
goto out;
}
do {
int s, rc, i;
FD_ZERO(&w);
FD_SET(c1, &w);
FD_SET(c2, &w);
FD_SET(p1, &w);
FD_SET(p2, &w);
s = select(max_fd + 1, &w, NULL, NULL, &timeout);
if (s == -1) {
perror("select()");
break;
} else if (!s) {
fprintf(stderr, "unexpected timeout\n");
break;
}
for (i = 0; i <= max_fd && s > 0; ++i) {
if (!FD_ISSET(i, &w))
continue;
s--;
rc = recv(i, buf, sizeof(buf), 0);
if (rc < 0) {
if (errno != EWOULDBLOCK) {
perror("recv failed()\n");
break;
}
}
if (rc == 0) {
close(i);
break;
}
sc = send(i, buf, rc, 0);
if (sc < 0) {
perror("send failed()\n");
break;
}
}
sleep(rate);
if (dot) {
printf(".");
fflush(stdout);
}
} while (running);
out:
close(s1);
close(s2);
close(p1);
close(p2);
close(c1);
close(c2);
return err;
}
int main(int argc, char **argv)
{
int rate = 1, dot = 1;
char filename[256];
int err, cg_fd;
char *cg_path;
cg_path = argv[argc - 1];
snprintf(filename, sizeof(filename), "%s_kern.o", argv[0]);
running = 1;
signal(SIGINT, running_handler);
if (load_bpf_file(filename)) {
fprintf(stderr, "load_bpf_file: (%s) %s\n",
filename, strerror(errno));
return 1;
}
cg_fd = open(cg_path, O_DIRECTORY, O_RDONLY);
if (cg_fd < 0) {
fprintf(stderr, "ERROR: (%i) open cg path failed: %s\n",
cg_fd, cg_path);
return cg_fd;
}
err = bpf_prog_attach(prog_fd[0], map_fd[0],
BPF_SK_SKB_STREAM_PARSER, 0);
if (err) {
fprintf(stderr, "ERROR: bpf_prog_attach (sockmap): %d (%s)\n",
err, strerror(errno));
return err;
}
err = bpf_prog_attach(prog_fd[1], map_fd[0],
BPF_SK_SKB_STREAM_VERDICT, 0);
if (err) {
fprintf(stderr, "ERROR: bpf_prog_attach (sockmap): %d (%s)\n",
err, strerror(errno));
return err;
}
err = bpf_prog_attach(prog_fd[2], cg_fd, BPF_CGROUP_SOCK_OPS, 0);
if (err) {
fprintf(stderr, "ERROR: bpf_prog_attach (groups): %d (%s)\n",
err, strerror(errno));
return err;
}
err = sockmap_test_sockets(rate, dot);
if (err) {
fprintf(stderr, "ERROR: test socket failed: %d\n", err);
return err;
}
return 0;
}
void running_handler(int a)
{
running = 0;
}
