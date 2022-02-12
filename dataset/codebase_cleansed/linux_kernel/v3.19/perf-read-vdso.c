int main(void)
{
void *start, *end;
size_t size, written;
if (find_vdso_map(&start, &end))
return 1;
size = end - start;
while (size) {
written = fwrite(start, 1, size, stdout);
if (!written)
return 1;
start += written;
size -= written;
}
if (fflush(stdout))
return 1;
return 0;
}
