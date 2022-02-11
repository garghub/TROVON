static int F_1 ( struct V_1 * V_2 )
{
unsigned char V_3 ;
F_2 ( V_2 , V_4 , 0 ) ;
if ( ( ( V_3 = F_3 ( V_2 , V_4 ) ) & 0x07 ) != 0 ) {
F_4 ( L_1 , V_2 -> V_5 . V_6 , V_3 ) ;
return - V_7 ;
}
F_5 ( 160 ) ;
F_2 ( V_2 , V_4 , 1 ) ;
F_5 ( 160 ) ;
if ( ( ( V_3 = F_3 ( V_2 , V_4 ) ) & 0x07 ) != 1 ) {
F_4 ( L_2 , V_2 -> V_5 . V_6 , V_3 ) ;
return - V_7 ;
}
return 0 ;
}
static T_1 F_6 ( int V_8 , void * V_9 )
{
struct V_10 * V_11 = V_9 ;
int V_12 , V_13 = 5 ;
int V_14 = 0 ;
do {
V_12 = 0 ;
if ( F_7 ( V_11 -> V_15 ) ) {
V_14 = 1 ;
F_8 ( V_8 , V_11 -> V_2 ) ;
V_12 ++ ;
}
if ( F_7 ( V_11 -> V_16 ) & 0x01 ) {
V_14 = 1 ;
F_9 ( V_8 , V_11 -> V_17 ) ;
V_12 ++ ;
}
} while ( V_12 && -- V_13 > 0 );
return F_10 ( V_14 ) ;
}
static void F_11 ( int V_18 , struct V_19 * V_20 ,
struct V_1 * V_2 )
{
V_2 -> V_21 = 1 ;
V_2 -> V_22 = 1 ;
V_2 -> V_23 = V_23 [ V_18 ] ;
V_2 -> V_24 = ( V_2 -> V_5 . V_6 >> 4 ) & 0x0f ;
if ( V_2 -> V_5 . V_25 > 3 )
V_2 -> V_24 |= 0x10 ;
if ( V_2 -> V_5 . V_26 > 3 )
V_2 -> V_24 |= 0x20 ;
V_2 -> V_24 |= 0x40 ;
F_12 ( V_2 -> V_24 , F_13 ( V_2 , V_27 ) ) ;
}
static int F_14 ( struct V_28 * V_29 )
{
struct V_19 * V_20 = V_29 -> V_20 ;
struct V_30 V_31 , V_32 ;
int V_33 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_31 . V_34 = V_32 . V_34 = V_35 ;
strcpy ( V_31 . V_36 , L_3 ) ;
strcpy ( V_32 . V_36 , L_4 ) ;
if ( ( V_33 = F_15 ( V_20 , & V_31 , & V_32 ) ) < 0 )
return V_33 ;
strcpy ( V_31 . V_36 , L_5 ) ;
strcpy ( V_32 . V_36 , L_6 ) ;
if ( ( V_33 = F_15 ( V_20 , & V_31 , & V_32 ) ) < 0 )
return V_33 ;
strcpy ( V_31 . V_36 , L_3 ) ; V_31 . V_37 = 1 ;
strcpy ( V_32 . V_36 , L_7 ) ;
if ( ( V_33 = F_15 ( V_20 , & V_31 , & V_32 ) ) < 0 )
return V_33 ;
strcpy ( V_31 . V_36 , L_5 ) ;
strcpy ( V_32 . V_36 , L_8 ) ;
if ( ( V_33 = F_15 ( V_20 , & V_31 , & V_32 ) ) < 0 )
return V_33 ;
#if 0
if (snd_mixer_group_rename(mixer,
SNDRV_MIXER_IN_MONO, 0,
SNDRV_MIXER_IN_MIC, 0) < 0)
goto __error;
if (snd_mixer_elem_rename(mixer,
SNDRV_MIXER_IN_MONO, 0, SNDRV_MIXER_ETYPE_INPUT,
SNDRV_MIXER_IN_MIC, 0) < 0)
goto __error;
if (snd_mixer_elem_rename(mixer,
"Mono Capture Volume", 0, SNDRV_MIXER_ETYPE_VOLUME1,
"Mic Capture Volume", 0) < 0)
goto __error;
if (snd_mixer_elem_rename(mixer,
"Mono Capture Switch", 0, SNDRV_MIXER_ETYPE_SWITCH1,
"Mic Capture Switch", 0) < 0)
goto __error;
#endif
return 0 ;
}
static void F_16 ( struct V_19 * V_20 )
{
struct V_10 * V_11 = V_20 -> V_38 ;
if ( V_11 == NULL )
return;
if ( V_11 -> V_8 >= 0 )
F_17 ( V_11 -> V_8 , ( void * ) V_11 ) ;
}
static int F_18 ( struct V_39 * V_40 , unsigned int V_18 )
{
return V_41 [ V_18 ] ;
}
static int F_19 ( struct V_39 * V_40 , unsigned int V_18 )
{
static int V_42 [] = { 5 , 11 , 12 , 9 , 7 , 15 , 3 , - 1 } ;
static int V_43 [] = { 5 , 6 , 7 , 1 , 3 , - 1 } ;
int V_44 , V_45 , V_46 , V_33 ;
struct V_19 * V_20 ;
struct V_1 * V_2 = NULL ;
struct V_28 * V_17 ;
struct V_10 * V_11 ;
V_33 = F_20 ( V_40 , V_37 [ V_18 ] , V_47 [ V_18 ] , V_48 ,
sizeof( struct V_10 ) , & V_20 ) ;
if ( V_33 < 0 )
return V_33 ;
V_20 -> V_49 = F_16 ;
V_11 = V_20 -> V_38 ;
V_11 -> V_20 = V_20 ;
V_11 -> V_8 = - 1 ;
V_44 = V_8 [ V_18 ] ;
if ( V_44 == V_50 ) {
if ( ( V_44 = F_21 ( V_42 ) ) < 0 ) {
F_22 (KERN_ERR PFX L_9 ) ;
V_33 = - V_51 ;
goto V_52;
}
}
V_45 = V_25 [ V_18 ] ;
if ( V_45 == V_53 ) {
if ( ( V_45 = F_23 ( V_43 ) ) < 0 ) {
F_22 (KERN_ERR PFX L_10 ) ;
V_33 = - V_51 ;
goto V_52;
}
}
V_46 = V_26 [ V_18 ] ;
if ( V_46 == V_53 ) {
if ( ( V_46 = F_23 ( V_43 ) ) < 0 ) {
F_22 (KERN_ERR PFX L_11 ) ;
V_33 = - V_51 ;
goto V_52;
}
}
if ( V_6 [ V_18 ] != V_54 ) {
V_33 = F_24 ( V_20 ,
V_6 [ V_18 ] ,
- V_44 , V_45 , V_46 ,
0 , V_55 [ V_18 ] ,
V_56 [ V_18 ] ,
0 , & V_2 ) ;
} else {
static unsigned long V_57 [] = {
0x220 , 0x230 , 0x240 , 0x250 , 0x260
} ;
int V_58 ;
for ( V_58 = 0 ; V_58 < F_25 ( V_57 ) ; V_58 ++ ) {
V_33 = F_24 ( V_20 ,
V_57 [ V_58 ] ,
- V_44 , V_45 , V_46 ,
0 , V_55 [ V_18 ] ,
V_56 [ V_18 ] ,
0 , & V_2 ) ;
if ( V_33 >= 0 ) {
V_6 [ V_18 ] = V_57 [ V_58 ] ;
break;
}
}
}
if ( V_33 < 0 )
goto V_52;
if ( ( V_33 = F_1 ( V_2 ) ) < 0 )
goto V_52;
V_11 -> V_15 = V_2 -> V_5 . V_59 ;
V_11 -> V_16 = V_2 -> V_5 . V_6 + 0x10c + 2 ;
F_11 ( V_18 , V_20 , V_2 ) ;
if ( ( V_33 = F_26 ( V_2 ) ) < 0 )
goto V_52;
if ( ! V_2 -> V_60 ) {
F_22 (KERN_ERR PFX L_12 , gus->gf1.port) ;
V_33 = - V_7 ;
goto V_52;
}
if ( F_27 ( V_44 , F_6 , 0 , L_13 , ( void * ) V_11 ) ) {
F_22 (KERN_ERR PFX L_14 , xirq) ;
V_33 = - V_51 ;
goto V_52;
}
V_11 -> V_8 = V_44 ;
V_33 = F_28 ( V_20 ,
V_2 -> V_5 . V_6 + 0x10c , - 1 , V_44 ,
V_46 < 0 ? V_45 : V_46 , V_45 ,
V_61 ,
V_62 |
V_63 |
V_64 ,
& V_17 ) ;
if ( V_33 < 0 )
goto V_52;
V_33 = F_29 ( V_17 , 0 ) ;
if ( V_33 < 0 )
goto V_52;
V_33 = F_30 ( V_17 ) ;
if ( V_33 < 0 )
goto V_52;
V_33 = F_31 ( V_17 , 2 ) ;
if ( V_33 < 0 )
goto V_52;
if ( V_56 [ V_18 ] > 0 ) {
if ( ( V_33 = F_32 ( V_2 , 1 , 1 ) ) < 0 )
goto V_52;
}
V_33 = F_14 ( V_17 ) ;
if ( V_33 < 0 )
goto V_52;
V_33 = F_33 ( V_2 , 0 ) ;
if ( V_33 < 0 )
goto V_52;
sprintf ( V_20 -> V_65 + strlen ( V_20 -> V_65 ) , L_15 , V_2 -> V_5 . V_6 , V_44 , V_45 ) ;
if ( V_46 >= 0 )
sprintf ( V_20 -> V_65 + strlen ( V_20 -> V_65 ) , L_16 , V_46 ) ;
V_33 = F_34 ( V_20 ) ;
if ( V_33 < 0 )
goto V_52;
V_11 -> V_2 = V_2 ;
V_11 -> V_17 = V_17 ;
F_35 ( V_40 , V_20 ) ;
return 0 ;
V_52:
F_36 ( V_20 ) ;
return V_33 ;
}
static int F_37 ( struct V_39 * V_66 , unsigned int V_18 )
{
F_36 ( F_38 ( V_66 ) ) ;
return 0 ;
}
