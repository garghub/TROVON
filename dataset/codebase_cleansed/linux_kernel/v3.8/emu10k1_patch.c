int
snd_emu10k1_sample_new(struct snd_emux *rec, struct snd_sf_sample *sp,
struct snd_util_memhdr *hdr,
const void __user *data, long count)
{
int offset;
int truesize, size, loopsize, blocksize;
int loopend, sampleend;
unsigned int start_addr;
struct snd_emu10k1 *emu;
emu = rec->hw;
if (snd_BUG_ON(!sp || !hdr))
return -EINVAL;
if (sp->v.size == 0) {
snd_printd("emu: rom font for sample %d\n", sp->v.sample);
return 0;
}
sp->v.end -= sp->v.start;
sp->v.loopstart -= sp->v.start;
sp->v.loopend -= sp->v.start;
sp->v.start = 0;
sampleend = sp->v.end;
if (sampleend > sp->v.size)
sampleend = sp->v.size;
loopend = sp->v.loopend;
if (loopend > sampleend)
loopend = sampleend;
if (sp->v.loopstart >= sp->v.loopend) {
int tmp = sp->v.loopstart;
sp->v.loopstart = sp->v.loopend;
sp->v.loopend = tmp;
}
truesize = sp->v.size + BLANK_HEAD_SIZE;
loopsize = 0;
#if 0
if (sp->v.mode_flags & (SNDRV_SFNT_SAMPLE_BIDIR_LOOP|SNDRV_SFNT_SAMPLE_REVERSE_LOOP))
loopsize = sp->v.loopend - sp->v.loopstart;
truesize += loopsize;
#endif
if (sp->v.mode_flags & SNDRV_SFNT_SAMPLE_NO_BLANK)
truesize += BLANK_LOOP_SIZE;
blocksize = truesize;
if (! (sp->v.mode_flags & SNDRV_SFNT_SAMPLE_8BITS))
blocksize *= 2;
sp->block = snd_emu10k1_synth_alloc(emu, blocksize);
if (sp->block == NULL) {
snd_printd("emu10k1: synth malloc failed (size=%d)\n", blocksize);
return -ENOSPC;
}
sp->v.truesize = blocksize;
offset = 0;
size = BLANK_HEAD_SIZE;
if (! (sp->v.mode_flags & SNDRV_SFNT_SAMPLE_8BITS))
size *= 2;
if (offset + size > blocksize)
return -EINVAL;
snd_emu10k1_synth_bzero(emu, sp->block, offset, size);
offset += size;
size = loopend;
if (! (sp->v.mode_flags & SNDRV_SFNT_SAMPLE_8BITS))
size *= 2;
if (offset + size > blocksize)
return -EINVAL;
if (snd_emu10k1_synth_copy_from_user(emu, sp->block, offset, data, size)) {
snd_emu10k1_synth_free(emu, sp->block);
sp->block = NULL;
return -EFAULT;
}
offset += size;
data += size;
#if 0
if (sp->v.mode_flags & (SNDRV_SFNT_SAMPLE_BIDIR_LOOP|SNDRV_SFNT_SAMPLE_REVERSE_LOOP)) {
if (! (sp->v.mode_flags & SNDRV_SFNT_SAMPLE_8BITS)) {
int woffset;
unsigned short *wblock = (unsigned short*)block;
woffset = offset / 2;
if (offset + loopsize * 2 > blocksize)
return -EINVAL;
for (i = 0; i < loopsize; i++)
wblock[woffset + i] = wblock[woffset - i -1];
offset += loopsize * 2;
} else {
if (offset + loopsize > blocksize)
return -EINVAL;
for (i = 0; i < loopsize; i++)
block[offset + i] = block[offset - i -1];
offset += loopsize;
}
if (sp->v.mode_flags & SNDRV_SFNT_SAMPLE_BIDIR_LOOP) {
sp->v.loopend += loopsize;
} else {
sp->v.loopstart += loopsize;
sp->v.loopend += loopsize;
}
sp->v.end += loopsize;
}
#endif
size = sp->v.size - loopend;
if (size < 0)
return -EINVAL;
if (! (sp->v.mode_flags & SNDRV_SFNT_SAMPLE_8BITS))
size *= 2;
if (snd_emu10k1_synth_copy_from_user(emu, sp->block, offset, data, size)) {
snd_emu10k1_synth_free(emu, sp->block);
sp->block = NULL;
return -EFAULT;
}
offset += size;
if (offset < blocksize)
snd_emu10k1_synth_bzero(emu, sp->block, offset, blocksize - offset);
if (sp->v.mode_flags & SNDRV_SFNT_SAMPLE_NO_BLANK) {
if (sp->v.mode_flags & SNDRV_SFNT_SAMPLE_SINGLESHOT) {
sp->v.loopstart = sp->v.end + BLANK_LOOP_START;
sp->v.loopend = sp->v.end + BLANK_LOOP_END;
}
}
#if 0
if (sp->v.mode_flags & SNDRV_SFNT_SAMPLE_UNSIGNED) {
if (! (sp->v.mode_flags & SNDRV_SFNT_SAMPLE_8BITS)) {
unsigned short *wblock = (unsigned short*)block;
for (i = 0; i < truesize; i++)
wblock[i] ^= 0x8000;
} else {
for (i = 0; i < truesize; i++)
block[i] ^= 0x80;
}
}
#endif
start_addr = BLANK_HEAD_SIZE * 2;
if (! (sp->v.mode_flags & SNDRV_SFNT_SAMPLE_8BITS))
start_addr >>= 1;
sp->v.start += start_addr;
sp->v.end += start_addr;
sp->v.loopstart += start_addr;
sp->v.loopend += start_addr;
return 0;
}
int
snd_emu10k1_sample_free(struct snd_emux *rec, struct snd_sf_sample *sp,
struct snd_util_memhdr *hdr)
{
struct snd_emu10k1 *emu;
emu = rec->hw;
if (snd_BUG_ON(!sp || !hdr))
return -EINVAL;
if (sp->block) {
snd_emu10k1_synth_free(emu, sp->block);
sp->block = NULL;
}
return 0;
}
