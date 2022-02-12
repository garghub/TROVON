int coda_h264_padding(int size, char *p)
{
int nal_size;
int diff;
diff = size - (size & ~0x7);
if (diff == 0)
return 0;
nal_size = coda_filler_size[diff];
memcpy(p, coda_filler_nal, nal_size);
*(p + nal_size - 1) = 0x80;
return nal_size;
}
