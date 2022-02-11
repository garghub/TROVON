static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! ( V_3 = F_2 ( V_2 , 0x40 , 0xff ) ) ) {
F_3 ( V_4
L_1 ) ;
} else {
F_4 ( V_4
L_2 , V_3 ) ;
}
}
static void F_5 ( struct V_1 * V_5 )
{
int V_3 ;
T_1 V_6 ;
if ( ! ( V_3 = F_6 ( V_5 , 0x42 , & V_6 ) )
&& ( ( V_6 & 0x10 )
|| ! ( V_3 = F_2 ( V_5 , 0x42 , V_6 | 0x10 ) ) ) ) {
F_3 ( V_4
L_3 , V_6 | 0x10 ) ;
} else {
F_4 ( V_4
L_2 , V_3 ) ;
}
}
static void F_7 ( struct V_1 * V_2 , int V_7 )
{
struct V_1 * V_5 = NULL ;
if ( V_7 == 255 ) {
V_5 = F_8 ( V_8 ,
V_9 , NULL ) ;
if ( V_5 == NULL ) {
V_5 = F_8 ( V_8 ,
V_10 , NULL ) ;
if ( V_5 == NULL )
V_5 = F_8 ( V_11 ,
V_12 , NULL ) ;
}
if ( V_5 ) {
F_3 ( V_4 L_4 ) ;
F_1 ( V_2 ) ;
F_5 ( V_5 ) ;
}
} else {
if ( V_7 & 0x1 )
F_1 ( V_2 ) ;
if ( ( V_7 & 0x2 ) && ( V_5 = F_8 ( V_8 ,
V_9 , NULL ) ) )
F_5 ( V_5 ) ;
if ( ( V_7 & 0x4 ) && ( V_5 = F_8 ( V_8 ,
V_10 , NULL ) ) )
F_5 ( V_5 ) ;
if ( ( V_7 & 0x8 ) && ( V_5 = F_8 ( V_11 ,
V_12 , NULL ) ) )
F_5 ( V_5 ) ;
}
F_9 ( V_5 ) ;
}
static int F_10 ( struct V_13 * V_14 )
{
T_2 * V_2 = V_14 -> V_15 ;
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
F_13 ( V_2 -> V_16 , V_2 ) ;
F_14 ( V_2 -> V_17 ) ;
F_15 ( V_2 -> V_1 ) ;
F_16 ( V_2 -> V_1 ) ;
F_17 ( V_2 ) ;
return 0 ;
}
static int
F_18 ( struct V_18 * V_19 , struct V_1 * V_20 , T_2 * * V_21 )
{
T_2 * V_22 ;
int V_23 ;
static struct V_24 V_25 = {
. V_26 = F_10 ,
} ;
* V_21 = NULL ;
if ( ( V_23 = F_19 ( V_20 ) ) < 0 )
return V_23 ;
if ( F_20 ( V_20 , F_21 ( 32 ) ) < 0 ||
F_22 ( V_20 , F_21 ( 32 ) ) < 0 ) {
F_23 ( L_5 ) ;
F_16 ( V_20 ) ;
return - V_27 ;
}
V_22 = F_24 ( sizeof( * V_22 ) , V_28 ) ;
if ( V_22 == NULL ) {
F_16 ( V_20 ) ;
return - V_29 ;
}
V_22 -> V_19 = V_19 ;
V_22 -> V_1 = V_20 ;
V_22 -> V_30 = F_25 ( V_20 , 0 ) ;
V_22 -> V_31 = V_20 -> V_31 ;
V_22 -> V_14 = V_20 -> V_14 ;
V_22 -> V_19 = V_19 ;
V_22 -> V_16 = - 1 ;
if ( ( V_23 = F_26 ( V_20 , V_32 ) ) != 0 )
goto V_33;
V_22 -> V_17 = F_27 ( V_20 , 0 ) ;
if ( ! V_22 -> V_17 ) {
F_23 ( L_6 ) ;
V_23 = - V_29 ;
goto V_34;
}
if ( ( V_23 = F_28 ( V_22 ) ) != 0 ) {
F_23 ( L_7 ) ;
goto V_35;
}
if ( ( V_23 = F_29 ( V_20 -> V_16 , V_36 ,
V_37 , V_38 ,
V_22 ) ) != 0 ) {
F_23 ( L_8 ) ;
goto V_39;
}
V_22 -> V_16 = V_20 -> V_16 ;
F_30 ( V_20 ) ;
if ( ( V_23 = F_31 ( V_19 , V_40 , V_22 , & V_25 ) ) < 0 ) {
goto V_41;
}
* V_21 = V_22 ;
return 0 ;
V_41:
F_13 ( V_22 -> V_16 , V_22 ) ;
V_39:
F_12 ( V_22 ) ;
V_35:
F_14 ( V_22 -> V_17 ) ;
V_34:
F_15 ( V_22 -> V_1 ) ;
V_33:
F_16 ( V_22 -> V_1 ) ;
F_11 ( V_22 ) ;
F_17 ( V_22 ) ;
return V_23 ;
}
static int
F_32 ( struct V_1 * V_20 , const struct V_42 * V_43 )
{
static int V_44 ;
struct V_18 * V_19 ;
T_2 * V_22 ;
int V_23 ;
if ( V_44 >= V_45 )
return - V_46 ;
if ( ! V_47 [ V_44 ] ) {
V_44 ++ ;
return - V_48 ;
}
V_23 = F_33 ( & V_20 -> V_44 , V_49 [ V_44 ] , V_50 [ V_44 ] , V_51 ,
0 , & V_19 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( ( V_23 = F_18 ( V_19 , V_20 , & V_22 ) ) < 0 ) {
F_34 ( V_19 ) ;
return V_23 ;
}
F_7 ( V_20 , V_52 [ V_44 ] ) ;
strcpy ( V_19 -> V_53 , V_32 ) ;
sprintf ( V_19 -> V_54 , L_9 , V_32 ) ;
sprintf ( V_19 -> V_55 , L_10 ,
V_19 -> V_54 , V_22 -> V_30 , V_22 -> V_16 ) ;
V_23 = F_35 ( V_22 ) ;
if ( V_23 < 0 ) {
F_34 ( V_19 ) ;
return V_23 ;
}
V_23 = F_36 ( V_22 , V_56 , V_57 ) ;
if ( V_23 < 0 ) {
F_34 ( V_19 ) ;
return V_23 ;
}
#ifndef F_37
if ( ( V_23 = F_36 ( V_22 , V_58 , 1 ) ) < 0 ) {
F_34 ( V_19 ) ;
return V_23 ;
}
if ( ( V_23 = F_36 ( V_22 , V_59 , V_60 ) ) < 0 ) {
F_34 ( V_19 ) ;
return V_23 ;
}
#endif
#ifndef F_38
if ( ( V_23 = F_36 ( V_22 , V_61 , V_62 ) ) < 0 ) {
F_34 ( V_19 ) ;
return V_23 ;
}
#endif
if ( ( V_23 = F_39 ( V_22 ) ) < 0 ) {
F_34 ( V_19 ) ;
return V_23 ;
}
F_40 ( V_22 ) ;
#if 0
if (snd_seq_device_new(card, 1, SNDRV_SEQ_DEV_ID_VORTEX_SYNTH,
sizeof(snd_vortex_synth_arg_t), &wave) < 0
|| wave == NULL) {
snd_printk(KERN_ERR "Can't initialize Aureal wavetable synth\n");
} else {
snd_vortex_synth_arg_t *arg;
arg = SNDRV_SEQ_DEVICE_ARGPTR(wave);
strcpy(wave->name, "Aureal Synth");
arg->hwptr = vortex;
arg->index = 1;
arg->seq_ports = seq_ports[dev];
arg->max_voices = max_synth_voices[dev];
}
#endif
if ( ( V_23 = F_41 ( V_20 , V_63 ,
& ( V_22 -> V_14 ) ) ) < 0 ) {
F_34 ( V_19 ) ;
return V_23 ;
}
if ( ( V_23 = F_41 ( V_20 , V_64 ,
& ( V_22 -> V_31 ) ) ) < 0 ) {
F_34 ( V_19 ) ;
return V_23 ;
}
V_22 -> V_65 = V_20 -> V_66 ;
#ifdef F_42
if ( ( V_22 -> V_65 ) != 0xfe && ( V_22 -> V_65 ) != 0xfa ) {
F_43 (
L_11 ,
V_22 -> V_65 ) ;
F_43 (
L_12 ) ;
F_34 ( V_19 ) ;
V_23 = - V_46 ;
return V_23 ;
}
#endif
if ( ( V_23 = F_44 ( V_19 ) ) < 0 ) {
F_34 ( V_19 ) ;
return V_23 ;
}
F_45 ( V_20 , V_19 ) ;
V_44 ++ ;
F_46 ( V_22 , 1 ) ;
F_47 ( V_22 ) ;
return 0 ;
}
static void F_48 ( struct V_1 * V_20 )
{
F_34 ( F_49 ( V_20 ) ) ;
}
