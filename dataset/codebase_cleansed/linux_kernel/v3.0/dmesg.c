int main(int argc, char *argv[])
{
u_long start = CHIPMEM_START, end = CHIPMEM_END, p;
int found = 0;
struct savekmsg *m = NULL;
if (argc >= 2)
end = strtoul(argv[1], NULL, 0);
printf("Searching for SAVEKMSG magic...\n");
for (p = start; p <= end-sizeof(struct savekmsg); p += 4) {
m = (struct savekmsg *)p;
if ((m->magic1 == SAVEKMSG_MAGIC1) && (m->magic2 == SAVEKMSG_MAGIC2) &&
(m->magicptr == p)) {
found = 1;
break;
}
}
if (!found)
printf("Not found\n");
else {
printf("Found %ld bytes at 0x%08lx\n", m->size, (u_long)&m->data);
puts(">>>>>>>>>>>>>>>>>>>>");
fflush(stdout);
write(1, &m->data, m->size);
fflush(stdout);
puts("<<<<<<<<<<<<<<<<<<<<");
}
return(0);
}
