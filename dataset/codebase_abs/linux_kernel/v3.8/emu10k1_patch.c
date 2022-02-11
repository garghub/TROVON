int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
const void T_1 * V_7 , long V_8 )
{
int V_9 ;
int V_10 , V_11 , V_12 , V_13 ;
int V_14 , V_15 ;
unsigned int V_16 ;
struct V_17 * V_18 ;
V_18 = V_2 -> V_19 ;
if ( F_2 ( ! V_4 || ! V_6 ) )
return - V_20 ;
if ( V_4 -> V_21 . V_11 == 0 ) {
F_3 ( L_1 , V_4 -> V_21 . V_22 ) ;
return 0 ;
}
V_4 -> V_21 . V_23 -= V_4 -> V_21 . V_24 ;
V_4 -> V_21 . V_25 -= V_4 -> V_21 . V_24 ;
V_4 -> V_21 . V_14 -= V_4 -> V_21 . V_24 ;
V_4 -> V_21 . V_24 = 0 ;
V_15 = V_4 -> V_21 . V_23 ;
if ( V_15 > V_4 -> V_21 . V_11 )
V_15 = V_4 -> V_21 . V_11 ;
V_14 = V_4 -> V_21 . V_14 ;
if ( V_14 > V_15 )
V_14 = V_15 ;
if ( V_4 -> V_21 . V_25 >= V_4 -> V_21 . V_14 ) {
int V_26 = V_4 -> V_21 . V_25 ;
V_4 -> V_21 . V_25 = V_4 -> V_21 . V_14 ;
V_4 -> V_21 . V_14 = V_26 ;
}
V_10 = V_4 -> V_21 . V_11 + V_27 ;
V_12 = 0 ;
#if 0
if (sp->v.mode_flags & (SNDRV_SFNT_SAMPLE_BIDIR_LOOP|SNDRV_SFNT_SAMPLE_REVERSE_LOOP))
loopsize = sp->v.loopend - sp->v.loopstart;
truesize += loopsize;
#endif
if ( V_4 -> V_21 . V_28 & V_29 )
V_10 += V_30 ;
V_13 = V_10 ;
if ( ! ( V_4 -> V_21 . V_28 & V_31 ) )
V_13 *= 2 ;
V_4 -> V_32 = F_4 ( V_18 , V_13 ) ;
if ( V_4 -> V_32 == NULL ) {
F_3 ( L_2 , V_13 ) ;
return - V_33 ;
}
V_4 -> V_21 . V_10 = V_13 ;
V_9 = 0 ;
V_11 = V_27 ;
if ( ! ( V_4 -> V_21 . V_28 & V_31 ) )
V_11 *= 2 ;
if ( V_9 + V_11 > V_13 )
return - V_20 ;
F_5 ( V_18 , V_4 -> V_32 , V_9 , V_11 ) ;
V_9 += V_11 ;
V_11 = V_14 ;
if ( ! ( V_4 -> V_21 . V_28 & V_31 ) )
V_11 *= 2 ;
if ( V_9 + V_11 > V_13 )
return - V_20 ;
if ( F_6 ( V_18 , V_4 -> V_32 , V_9 , V_7 , V_11 ) ) {
F_7 ( V_18 , V_4 -> V_32 ) ;
V_4 -> V_32 = NULL ;
return - V_34 ;
}
V_9 += V_11 ;
V_7 += V_11 ;
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
V_11 = V_4 -> V_21 . V_11 - V_14 ;
if ( V_11 < 0 )
return - V_20 ;
if ( ! ( V_4 -> V_21 . V_28 & V_31 ) )
V_11 *= 2 ;
if ( F_6 ( V_18 , V_4 -> V_32 , V_9 , V_7 , V_11 ) ) {
F_7 ( V_18 , V_4 -> V_32 ) ;
V_4 -> V_32 = NULL ;
return - V_34 ;
}
V_9 += V_11 ;
if ( V_9 < V_13 )
F_5 ( V_18 , V_4 -> V_32 , V_9 , V_13 - V_9 ) ;
if ( V_4 -> V_21 . V_28 & V_29 ) {
if ( V_4 -> V_21 . V_28 & V_35 ) {
V_4 -> V_21 . V_25 = V_4 -> V_21 . V_23 + V_36 ;
V_4 -> V_21 . V_14 = V_4 -> V_21 . V_23 + V_37 ;
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
V_16 = V_27 * 2 ;
if ( ! ( V_4 -> V_21 . V_28 & V_31 ) )
V_16 >>= 1 ;
V_4 -> V_21 . V_24 += V_16 ;
V_4 -> V_21 . V_23 += V_16 ;
V_4 -> V_21 . V_25 += V_16 ;
V_4 -> V_21 . V_14 += V_16 ;
return 0 ;
}
int
F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_17 * V_18 ;
V_18 = V_2 -> V_19 ;
if ( F_2 ( ! V_4 || ! V_6 ) )
return - V_20 ;
if ( V_4 -> V_32 ) {
F_7 ( V_18 , V_4 -> V_32 ) ;
V_4 -> V_32 = NULL ;
}
return 0 ;
}
