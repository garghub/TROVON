int
main(int ac, char **av)
{
int fd, n, i;
unsigned long ph, ps, np;
long nnote, nnote2, ns;
if (ac != 2) {
fprintf(stderr, "Usage: %s elf-file\n", av[0]);
exit(1);
}
fd = open(av[1], O_RDWR);
if (fd < 0) {
perror(av[1]);
exit(1);
}
nnote = 12 + ROUNDUP(strlen(arch) + 1) + sizeof(descr);
nnote2 = 12 + ROUNDUP(strlen(rpaname) + 1) + sizeof(rpanote);
n = read(fd, buf, sizeof(buf));
if (n < 0) {
perror("read");
exit(1);
}
if (memcmp(&buf[E_IDENT+EI_MAGIC], elf_magic, 4) != 0)
goto notelf;
e_class = buf[E_IDENT+EI_CLASS];
if (e_class != ELFCLASS32 && e_class != ELFCLASS64)
goto notelf;
e_data = buf[E_IDENT+EI_DATA];
if (e_data != ELFDATA2MSB && e_data != ELFDATA2LSB)
goto notelf;
if (n < E_HSIZE)
goto notelf;
ph = (e_class == ELFCLASS32 ? GET_32(E_PHOFF) : GET_64(E_PHOFF));
ps = GET_16(E_PHENTSIZE);
np = GET_16(E_PHNUM);
if (ph < E_HSIZE || ps < PH_HSIZE || np < 1)
goto notelf;
if (ph + (np + 2) * ps + nnote + nnote2 > n)
goto nospace;
for (i = 0; i < np; ++i) {
if (GET_32(ph + PH_TYPE) == PT_NOTE) {
fprintf(stderr, "%s already has a note entry\n",
av[1]);
exit(0);
}
ph += ps;
}
for (i = 0; i < 2 * ps + nnote + nnote2; ++i)
if (buf[ph + i] != 0)
goto nospace;
ns = ph + 2 * ps;
PUT_32(ph + PH_TYPE, PT_NOTE);
if (e_class == ELFCLASS32)
PUT_32(ph + PH_OFFSET, ns);
else
PUT_64(ph + PH_OFFSET, ns);
if (e_class == ELFCLASS32)
PUT_32(ph + PH_FILESZ, nnote);
else
PUT_64(ph + PH_FILESZ, nnote);
PUT_32(ns, strlen(arch) + 1);
PUT_32(ns + 4, N_DESCR * 4);
PUT_32(ns + 8, 0x1275);
strcpy((char *) &buf[ns + 12], arch);
ns += 12 + strlen(arch) + 1;
for (i = 0; i < N_DESCR; ++i, ns += 4)
PUT_32BE(ns, descr[i]);
ph += ps;
PUT_32(ph + PH_TYPE, PT_NOTE);
if (e_class == ELFCLASS32)
PUT_32(ph + PH_OFFSET, ns);
else
PUT_64(ph + PH_OFFSET, ns);
if (e_class == ELFCLASS32)
PUT_32(ph + PH_FILESZ, nnote);
else
PUT_64(ph + PH_FILESZ, nnote2);
PUT_32(ns, strlen(rpaname) + 1);
PUT_32(ns + 4, sizeof(rpanote));
PUT_32(ns + 8, 0x12759999);
strcpy((char *) &buf[ns + 12], rpaname);
ns += 12 + ROUNDUP(strlen(rpaname) + 1);
for (i = 0; i < N_RPA_DESCR; ++i, ns += 4)
PUT_32BE(ns, rpanote[i]);
PUT_16(E_PHNUM, np + 2);
lseek(fd, (long) 0, SEEK_SET);
i = write(fd, buf, n);
if (i < 0) {
perror("write");
exit(1);
}
if (i < n) {
fprintf(stderr, "%s: write truncated\n", av[1]);
exit(1);
}
exit(0);
notelf:
fprintf(stderr, "%s does not appear to be an ELF file\n", av[1]);
exit(1);
nospace:
fprintf(stderr, "sorry, I can't find space in %s to put the note\n",
av[1]);
exit(1);
}
