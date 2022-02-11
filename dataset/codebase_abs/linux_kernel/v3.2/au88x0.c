static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! ( V_3 = F_2 ( V_2 , 0x40 , 0xff ) ) ) {
F_3 (KERN_INFO CARD_NAME
L_1 ) ;
} else {
F_3 (KERN_WARNING CARD_NAME
L_2 , rc) ;
}
}
static void F_4 ( struct V_1 * V_4 )
{
int V_3 ;
T_1 V_5 ;
if ( ! ( V_3 = F_5 ( V_4 , 0x42 , & V_5 ) )
&& ( ( V_5 & 0x10 )
|| ! ( V_3 = F_2 ( V_4 , 0x42 , V_5 | 0x10 ) ) ) ) {
F_3 (KERN_INFO CARD_NAME
L_3 , value | 0x10 ) ;
} else {
F_3 (KERN_WARNING CARD_NAME
L_2 , rc) ;
}
}
static void T_2 F_6 ( struct V_1 * V_2 , int V_6 )
{
struct V_1 * V_4 = NULL ;
if ( V_6 == 255 ) {
V_4 = F_7 ( V_7 ,
V_8 , NULL ) ;
if ( V_4 == NULL ) {
V_4 = F_7 ( V_7 ,
V_9 , NULL ) ;
if ( V_4 == NULL )
V_4 = F_7 ( V_10 ,
V_11 , NULL ) ;
}
if ( V_4 ) {
F_3 (KERN_INFO CARD_NAME L_4 ) ;
F_1 ( V_2 ) ;
F_4 ( V_4 ) ;
}
} else {
if ( V_6 & 0x1 )
F_1 ( V_2 ) ;
if ( ( V_6 & 0x2 ) && ( V_4 = F_7 ( V_7 ,
V_8 , NULL ) ) )
F_4 ( V_4 ) ;
if ( ( V_6 & 0x4 ) && ( V_4 = F_7 ( V_7 ,
V_9 , NULL ) ) )
F_4 ( V_4 ) ;
if ( ( V_6 & 0x8 ) && ( V_4 = F_7 ( V_10 ,
V_11 , NULL ) ) )
F_4 ( V_4 ) ;
}
F_8 ( V_4 ) ;
}
static int F_9 ( struct V_12 * V_13 )
{
T_3 * V_2 = V_13 -> V_14 ;
F_10 ( V_2 ) ;
F_11 ( V_2 ) ;
F_12 ( V_2 -> V_15 , V_2 ) ;
F_13 ( V_2 -> V_16 ) ;
F_14 ( V_2 -> V_1 ) ;
F_15 ( V_2 -> V_1 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
static int T_2
F_17 ( struct V_17 * V_18 , struct V_1 * V_19 , T_3 * * V_20 )
{
T_3 * V_21 ;
int V_22 ;
static struct V_23 V_24 = {
. V_25 = F_9 ,
} ;
* V_20 = NULL ;
if ( ( V_22 = F_18 ( V_19 ) ) < 0 )
return V_22 ;
if ( F_19 ( V_19 , F_20 ( 32 ) ) < 0 ||
F_21 ( V_19 , F_20 ( 32 ) ) < 0 ) {
F_3 ( V_26 L_5 ) ;
F_15 ( V_19 ) ;
return - V_27 ;
}
V_21 = F_22 ( sizeof( * V_21 ) , V_28 ) ;
if ( V_21 == NULL ) {
F_15 ( V_19 ) ;
return - V_29 ;
}
V_21 -> V_18 = V_18 ;
V_21 -> V_1 = V_19 ;
V_21 -> V_30 = F_23 ( V_19 , 0 ) ;
V_21 -> V_31 = V_19 -> V_31 ;
V_21 -> V_13 = V_19 -> V_13 ;
V_21 -> V_18 = V_18 ;
V_21 -> V_15 = - 1 ;
if ( ( V_22 = F_24 ( V_19 , V_32 ) ) != 0 )
goto V_33;
V_21 -> V_16 = F_25 ( V_19 , 0 ) ;
if ( ! V_21 -> V_16 ) {
F_3 ( V_26 L_6 ) ;
V_22 = - V_29 ;
goto V_34;
}
if ( ( V_22 = F_26 ( V_21 ) ) != 0 ) {
F_3 ( V_26 L_7 ) ;
goto V_35;
}
if ( ( V_22 = F_27 ( V_19 -> V_15 , V_36 ,
V_37 , V_38 ,
V_21 ) ) != 0 ) {
F_3 ( V_26 L_8 ) ;
goto V_39;
}
V_21 -> V_15 = V_19 -> V_15 ;
F_28 ( V_19 ) ;
if ( ( V_22 = F_29 ( V_18 , V_40 , V_21 , & V_24 ) ) < 0 ) {
goto V_41;
}
F_30 ( V_18 , & V_19 -> V_42 ) ;
* V_20 = V_21 ;
return 0 ;
V_41:
F_12 ( V_21 -> V_15 , V_21 ) ;
V_39:
F_11 ( V_21 ) ;
V_35:
F_13 ( V_21 -> V_16 ) ;
V_34:
F_14 ( V_21 -> V_1 ) ;
V_33:
F_15 ( V_21 -> V_1 ) ;
F_10 ( V_21 ) ;
F_16 ( V_21 ) ;
return V_22 ;
}
static int T_2
F_31 ( struct V_1 * V_19 , const struct V_43 * V_44 )
{
static int V_42 ;
struct V_17 * V_18 ;
T_3 * V_21 ;
int V_22 ;
if ( V_42 >= V_45 )
return - V_46 ;
if ( ! V_47 [ V_42 ] ) {
V_42 ++ ;
return - V_48 ;
}
V_22 = F_32 ( V_49 [ V_42 ] , V_50 [ V_42 ] , V_51 , 0 , & V_18 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( ( V_22 = F_17 ( V_18 , V_19 , & V_21 ) ) < 0 ) {
F_33 ( V_18 ) ;
return V_22 ;
}
F_6 ( V_19 , V_52 [ V_42 ] ) ;
strcpy ( V_18 -> V_53 , V_32 ) ;
sprintf ( V_18 -> V_54 , L_9 , V_32 ) ;
sprintf ( V_18 -> V_55 , L_10 ,
V_18 -> V_54 , V_21 -> V_30 , V_21 -> V_15 ) ;
if ( ( V_22 = F_34 ( V_21 , V_56 , V_57 ) ) < 0 ) {
F_33 ( V_18 ) ;
return V_22 ;
}
#ifndef F_35
if ( ( V_22 = F_34 ( V_21 , V_58 , 1 ) ) < 0 ) {
F_33 ( V_18 ) ;
return V_22 ;
}
if ( ( V_22 = F_34 ( V_21 , V_59 , V_60 ) ) < 0 ) {
F_33 ( V_18 ) ;
return V_22 ;
}
#endif
#ifndef F_36
if ( ( V_22 = F_34 ( V_21 , V_61 , V_62 ) ) < 0 ) {
F_33 ( V_18 ) ;
return V_22 ;
}
#endif
if ( ( V_22 = F_37 ( V_21 ) ) < 0 ) {
F_33 ( V_18 ) ;
return V_22 ;
}
if ( ( V_22 = F_38 ( V_21 ) ) < 0 ) {
F_33 ( V_18 ) ;
return V_22 ;
}
F_39 ( V_21 ) ;
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
if ( ( V_22 = F_40 ( V_19 , V_63 ,
& ( V_21 -> V_13 ) ) ) < 0 ) {
F_33 ( V_18 ) ;
return V_22 ;
}
if ( ( V_22 = F_40 ( V_19 , V_64 ,
& ( V_21 -> V_31 ) ) ) < 0 ) {
F_33 ( V_18 ) ;
return V_22 ;
}
V_21 -> V_65 = V_19 -> V_66 ;
#ifdef F_41
if ( ( V_21 -> V_65 ) != 0xfe && ( V_21 -> V_65 ) != 0xfa ) {
F_3 ( V_67
L_11 ,
V_21 -> V_65 ) ;
F_3 ( V_67
L_12 ) ;
F_33 ( V_18 ) ;
V_22 = - V_46 ;
return V_22 ;
}
#endif
if ( ( V_22 = F_42 ( V_18 ) ) < 0 ) {
F_33 ( V_18 ) ;
return V_22 ;
}
F_43 ( V_19 , V_18 ) ;
V_42 ++ ;
F_44 ( V_21 , 1 ) ;
F_45 ( V_21 ) ;
return 0 ;
}
static void T_4 F_46 ( struct V_1 * V_19 )
{
F_33 ( F_47 ( V_19 ) ) ;
F_43 ( V_19 , NULL ) ;
}
static int T_5 F_48 ( void )
{
return F_49 ( & V_53 ) ;
}
static void T_6 F_50 ( void )
{
F_51 ( & V_53 ) ;
}
