static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
V_6 = V_2 -> V_8 ;
F_2 ( & V_6 -> V_9 ) ;
if ( V_6 -> V_10 )
F_3 ( V_4 , L_1 , V_6 -> V_10 ) ;
F_3 ( V_4 , L_2 , V_6 -> V_11 ) ;
F_3 ( V_4 , L_3 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ )
F_3 ( V_4 , L_4 , V_6 -> V_12 , V_6 -> V_13 [ V_7 ] ) ;
F_3 ( V_4 , L_5 ) ;
F_3 ( V_4 , L_6 , V_6 -> V_14 ) ;
F_3 ( V_4 , L_7 , V_6 -> V_15 ) ;
F_3 ( V_4 , L_8 , V_6 -> V_16 ) ;
if ( V_6 -> V_17 ) {
F_3 ( V_4 , L_9 , V_6 -> V_17 -> V_18 ) ;
F_3 ( V_4 , L_10 , F_4 ( V_6 -> V_17 ) ) ;
F_3 ( V_4 , L_11 , V_6 -> V_17 -> V_19 ) ;
} else {
F_3 ( V_4 , L_12 ) ;
}
if ( V_6 -> V_20 ) {
F_2 ( & V_6 -> V_20 -> V_21 ) ;
F_3 ( V_4 , L_13 , V_6 -> V_20 -> V_22 ) ;
F_3 ( V_4 , L_14 , V_6 -> V_20 -> V_23 ) ;
F_3 ( V_4 , L_15 , V_6 -> V_20 -> V_24 ) ;
F_3 ( V_4 , L_16 , V_6 -> V_20 -> V_25 ) ;
F_3 ( V_4 , L_17 , V_6 -> V_20 -> V_26 ) ;
F_5 ( & V_6 -> V_20 -> V_21 ) ;
}
#if 0
if (emu->voices[0].state != SNDRV_EMUX_ST_OFF && emu->voices[0].ch >= 0) {
struct snd_emux_voice *vp = &emu->voices[0];
snd_iprintf(buf, "voice 0: on\n");
snd_iprintf(buf, "mod delay=%x, atkhld=%x, dcysus=%x, rel=%x\n",
vp->reg.parm.moddelay,
vp->reg.parm.modatkhld,
vp->reg.parm.moddcysus,
vp->reg.parm.modrelease);
snd_iprintf(buf, "vol delay=%x, atkhld=%x, dcysus=%x, rel=%x\n",
vp->reg.parm.voldelay,
vp->reg.parm.volatkhld,
vp->reg.parm.voldcysus,
vp->reg.parm.volrelease);
snd_iprintf(buf, "lfo1 delay=%x, lfo2 delay=%x, pefe=%x\n",
vp->reg.parm.lfo1delay,
vp->reg.parm.lfo2delay,
vp->reg.parm.pefe);
snd_iprintf(buf, "fmmod=%x, tremfrq=%x, fm2frq2=%x\n",
vp->reg.parm.fmmod,
vp->reg.parm.tremfrq,
vp->reg.parm.fm2frq2);
snd_iprintf(buf, "cutoff=%x, filterQ=%x, chorus=%x, reverb=%x\n",
vp->reg.parm.cutoff,
vp->reg.parm.filterQ,
vp->reg.parm.chorus,
vp->reg.parm.reverb);
snd_iprintf(buf, "avol=%x, acutoff=%x, apitch=%x\n",
vp->avol, vp->acutoff, vp->apitch);
snd_iprintf(buf, "apan=%x, aaux=%x, ptarget=%x, vtarget=%x, ftarget=%x\n",
vp->apan, vp->aaux,
vp->ptarget,
vp->vtarget,
vp->ftarget);
snd_iprintf(buf, "start=%x, end=%x, loopstart=%x, loopend=%x\n",
vp->reg.start, vp->reg.end, vp->reg.loopstart, vp->reg.loopend);
snd_iprintf(buf, "sample_mode=%x, rate=%x\n", vp->reg.sample_mode, vp->reg.rate_offset);
}
#endif
F_5 ( & V_6 -> V_9 ) ;
}
void F_6 ( struct V_5 * V_6 , struct V_27 * V_28 , int V_29 )
{
struct V_1 * V_2 ;
char V_10 [ 64 ] ;
sprintf ( V_10 , L_18 , V_29 ) ;
V_2 = F_7 ( V_28 , V_10 , V_28 -> V_30 ) ;
if ( V_2 == NULL )
return;
V_2 -> V_31 = V_32 ;
V_2 -> V_8 = V_6 ;
V_2 -> V_33 . V_34 . V_35 = F_1 ;
if ( F_8 ( V_2 ) < 0 )
F_9 ( V_2 ) ;
else
V_6 -> V_36 = V_2 ;
}
void F_10 ( struct V_5 * V_6 )
{
F_9 ( V_6 -> V_36 ) ;
V_6 -> V_36 = NULL ;
}
