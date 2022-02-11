static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
unsigned long V_5 = V_2 -> V_6 ;
#if 0
printk(KERN_DEBUG "i2c_setlines - 0x%lx <- %i,%i\n", port, ctrl, data);
#endif
F_2 ( ( V_4 << 1 ) | V_3 , V_5 ) ;
F_3 ( 10 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
unsigned long V_5 = V_2 -> V_6 ;
unsigned char V_7 ;
V_7 = F_5 ( V_5 ) & 1 ;
#if 0
printk(KERN_DEBUG "i2c_getclockline - 0x%lx -> %i\n", port, res);
#endif
return V_7 ;
}
static int F_6 ( struct V_1 * V_2 , int V_8 )
{
unsigned long V_5 = V_2 -> V_6 ;
unsigned char V_7 ;
if ( V_8 )
F_3 ( 10 ) ;
V_7 = ( F_5 ( V_5 ) & 2 ) >> 1 ;
#if 0
printk(KERN_DEBUG "i2c_getdataline - 0x%lx -> %i\n", port, res);
#endif
return V_7 ;
}
static int T_1 F_7 ( struct V_9 * V_10 ,
struct V_11 * V_12 , int V_13 ,
struct V_1 * * V_14 )
{
unsigned long V_5 ;
struct V_1 * V_2 ;
struct V_15 * V_16 = V_10 -> V_16 ;
char V_17 [ 32 ] ;
int V_18 ;
* V_14 = NULL ;
V_5 = V_19 [ V_13 ] ;
if ( V_5 == V_20 ) {
V_5 = 0x350 ;
if ( V_12 -> V_21 . V_5 == 0x250 ) {
V_5 = 0x360 ;
}
while ( V_5 <= 0x380 ) {
if ( ( V_10 -> V_22 = F_8 ( V_5 , 1 , L_1 ) ) != NULL )
break;
V_5 += 0x10 ;
}
} else {
V_10 -> V_22 = F_8 ( V_5 , 1 , L_1 ) ;
}
if ( V_10 -> V_22 == NULL ) {
F_9 ( V_23 L_2 ) ;
return - V_24 ;
}
sprintf ( V_17 , L_3 , V_16 -> V_25 ) ;
if ( ( V_18 = F_10 ( V_16 , V_17 , NULL , & V_2 ) ) < 0 )
return V_18 ;
V_2 -> V_6 = V_5 ;
V_2 -> V_26 . V_27 = & V_28 ;
if ( ( V_18 = F_11 ( V_2 , 0 ) ) < 0 )
return V_18 ;
* V_14 = V_2 ;
return 0 ;
}
static int T_1 F_12 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
int V_13
#ifdef F_13
, struct V_1 * * V_14
#endif
)
{
unsigned long V_29 ;
unsigned char V_30 , V_31 ;
int V_32 ;
F_14 ( V_12 , V_33 , 0 ) ;
if ( ( ( V_32 = F_15 ( V_12 , V_33 ) ) & 0x07 ) != 0 ) {
F_16 ( L_4 , V_12 -> V_21 . V_5 , V_32 ) ;
return - V_24 ;
}
F_3 ( 160 ) ;
F_14 ( V_12 , V_33 , 1 ) ;
F_3 ( 160 ) ;
if ( ( ( V_32 = F_15 ( V_12 , V_33 ) ) & 0x07 ) != 1 ) {
F_16 ( L_5 , V_12 -> V_21 . V_5 , V_32 ) ;
return - V_24 ;
}
F_17 ( & V_12 -> V_34 , V_29 ) ;
V_30 = F_18 ( V_12 , V_35 ) ;
F_19 ( V_12 , V_35 , ~ V_30 ) ;
V_31 = F_18 ( V_12 , V_35 ) ;
F_19 ( V_12 , V_35 , V_30 ) ;
F_20 ( & V_12 -> V_34 , V_29 ) ;
F_16 ( L_6 , V_12 -> V_21 . V_5 , V_30 , V_31 ) ;
if ( ( V_30 & 0xf0 ) == ( V_31 & 0xf0 ) &&
( V_30 & 0x0f ) != ( V_31 & 0x0f ) ) {
F_16 ( L_7 , V_12 -> V_21 . V_5 ) ;
V_12 -> V_36 = 1 ;
strcpy ( V_12 -> V_16 -> V_37 , L_8 ) ;
V_12 -> V_38 = V_30 >> 4 ;
#ifndef F_13
return 0 ;
#else
return F_7 ( V_10 , V_12 , V_13 , V_14 ) ;
#endif
}
F_16 ( L_9 , V_12 -> V_21 . V_5 ) ;
return - V_24 ;
}
static T_2 F_21 ( int V_39 , void * V_40 )
{
struct V_9 * V_10 = V_40 ;
int V_41 , V_42 = 5 ;
int V_43 = 0 ;
do {
V_41 = 0 ;
if ( F_5 ( V_10 -> V_44 ) ) {
V_43 = 1 ;
F_22 ( V_39 , V_10 -> V_12 ) ;
V_41 ++ ;
}
if ( F_5 ( V_10 -> V_45 ) & 0x01 ) {
V_43 = 1 ;
F_23 ( V_39 , V_10 -> V_46 ) ;
V_41 ++ ;
}
} while ( V_41 && -- V_42 > 0 );
return F_24 ( V_43 ) ;
}
static void T_1 F_25 ( struct V_11 * V_12 )
{
F_19 ( V_12 , V_33 , 0x00 ) ;
F_3 ( 160 ) ;
F_19 ( V_12 , V_33 , 0x01 ) ;
F_3 ( 160 ) ;
}
static void T_1 F_26 ( struct V_11 * V_12 , int * V_47 )
{
unsigned int V_48 ;
unsigned int V_49 ;
unsigned char V_32 ;
for ( V_48 = 0 ; V_48 < 4 ; V_48 ++ ) {
V_47 [ V_48 ] = 0 ;
V_32 = 0x55 ;
for ( V_49 = V_48 << 22 ;
V_49 < ( V_48 << 22 ) + 0x400000 ;
V_49 += 0x40000 , V_32 ++ ) {
F_27 ( V_12 , V_49 , V_32 ) ;
F_27 ( V_12 , V_49 + 1 , V_32 + 1 ) ;
#if 0
printk(KERN_DEBUG "d = 0x%x, local = 0x%x, "
"local + 1 = 0x%x, idx << 22 = 0x%x\n",
d,
snd_gf1_peek(gus, local),
snd_gf1_peek(gus, local + 1),
snd_gf1_peek(gus, idx << 22));
#endif
if ( F_28 ( V_12 , V_49 ) != V_32 ||
F_28 ( V_12 , V_49 + 1 ) != V_32 + 1 ||
F_28 ( V_12 , V_48 << 22 ) != 0x55 )
break;
V_47 [ V_48 ] ++ ;
}
}
#if 0
printk(KERN_DEBUG "sizes: %i %i %i %i\n",
sizes[0], sizes[1], sizes[2], sizes[3]);
#endif
}
static void T_1 F_29 ( struct V_11 * V_12 )
{
static unsigned int V_50 [ 13 ] =
{
0x00000001 , 0x00000101 , 0x01010101 , 0x00000401 ,
0x04040401 , 0x00040101 , 0x04040101 , 0x00000004 ,
0x00000404 , 0x04040404 , 0x00000010 , 0x00001010 ,
0x10101010
} ;
int V_51 , V_52 ;
unsigned int V_53 , V_54 ;
int V_55 [ 4 ] ;
unsigned char V_56 [ 8 ] ;
unsigned char V_57 ;
F_25 ( V_12 ) ;
F_19 ( V_12 , V_58 , F_30 ( V_12 , V_58 ) | 0x01 ) ;
F_19 ( V_12 , V_59 , 0x01 ) ;
F_31 ( V_12 , V_60 , ( F_32 ( V_12 , V_60 ) & 0xff10 ) | 0x004c ) ;
V_52 = 0 ;
F_27 ( V_12 , 0 , 0x55 ) ;
F_27 ( V_12 , 1 , 0xaa ) ;
#if 1
if ( F_28 ( V_12 , 0 ) == 0x55 && F_28 ( V_12 , 1 ) == 0xaa )
#else
if ( 0 )
#endif
{
F_26 ( V_12 , V_55 ) ;
V_54 = ( V_55 [ 3 ] << 24 ) | ( V_55 [ 2 ] << 16 ) |
( V_55 [ 1 ] << 8 ) | V_55 [ 0 ] ;
#if 0
printk(KERN_DEBUG "lmct = 0x%08x\n", lmct);
#endif
for ( V_53 = 0 ; V_53 < F_33 ( V_50 ) ; V_53 ++ )
if ( V_54 == V_50 [ V_53 ] ) {
#if 0
printk(KERN_DEBUG "found !!! %i\n", i);
#endif
F_31 ( V_12 , V_60 , ( F_32 ( V_12 , V_60 ) & 0xfff0 ) | V_53 ) ;
F_26 ( V_12 , V_55 ) ;
break;
}
if ( V_53 >= F_33 ( V_50 ) && ! V_12 -> V_21 . V_61 )
F_31 ( V_12 , V_60 , ( F_32 ( V_12 , V_60 ) & 0xfff0 ) | 2 ) ;
for ( V_53 = 0 ; V_53 < 4 ; V_53 ++ ) {
V_12 -> V_21 . V_62 . V_63 [ V_53 ] . V_64 =
V_12 -> V_21 . V_62 . V_65 [ V_53 ] . V_64 = V_53 << 22 ;
V_12 -> V_21 . V_62 . V_63 [ V_53 ] . V_66 =
V_12 -> V_21 . V_62 . V_65 [ V_53 ] . V_66 = V_55 [ V_53 ] << 18 ;
V_52 += V_55 [ V_53 ] ;
}
}
V_52 <<= 18 ;
V_12 -> V_21 . V_67 = V_52 ;
F_19 ( V_12 , V_59 , 0x03 ) ;
F_31 ( V_12 , V_60 , ( F_32 ( V_12 , V_60 ) & 0xff1f ) | ( 4 << 5 ) ) ;
V_12 -> V_21 . V_68 = 0 ;
V_12 -> V_21 . V_69 = 0 ;
for ( V_51 = 0 ; V_51 < 16L * 1024L * 1024L ; V_51 += 4L * 1024L * 1024L ) {
for ( V_53 = 0 ; V_53 < 8 ; ++ V_53 )
V_56 [ V_53 ] = F_28 ( V_12 , V_51 + V_53 ) ;
#ifdef F_34
F_35 ( V_70 L_10 , V_51 ,
V_56 [ 0 ] , V_56 [ 1 ] , V_56 [ 2 ] , V_56 [ 3 ] ,
V_56 [ 4 ] , V_56 [ 5 ] , V_56 [ 6 ] , V_56 [ 7 ] ) ;
#endif
if ( strncmp ( V_56 , L_11 , 8 ) )
continue;
V_57 = 0 ;
for ( V_53 = 0 ; V_53 < sizeof( struct V_71 ) ; V_53 ++ )
V_57 += F_28 ( V_12 , V_51 + V_53 ) ;
#ifdef F_34
F_35 ( V_70 L_12 , V_57 ) ;
#endif
if ( V_57 != 0 )
continue;
V_12 -> V_21 . V_68 ++ ;
V_12 -> V_21 . V_72 |= 1 << ( V_51 >> 22 ) ;
V_12 -> V_21 . V_69 = F_28 ( V_12 , V_51 + 40 ) |
( F_28 ( V_12 , V_51 + 41 ) << 8 ) |
( F_28 ( V_12 , V_51 + 42 ) << 16 ) |
( F_28 ( V_12 , V_51 + 43 ) << 24 ) ;
}
#if 0
if (gus->gf1.rom_memory > 0) {
if (gus->gf1.rom_banks == 1 && gus->gf1.rom_present == 8)
gus->card->type = SNDRV_CARD_TYPE_IW_DYNASONIC;
}
#endif
F_19 ( V_12 , V_59 , 0x00 ) ;
if ( ! V_12 -> V_21 . V_61 )
F_25 ( V_12 ) ;
}
static void T_1 F_36 ( int V_13 , struct V_11 * V_12 )
{
unsigned long V_29 ;
F_17 ( & V_12 -> V_34 , V_29 ) ;
F_19 ( V_12 , V_73 , 0x00 ) ;
F_19 ( V_12 , V_74 , 0x1f ) ;
F_19 ( V_12 , V_75 , 0x49 ) ;
F_19 ( V_12 , V_35 , 0x11 ) ;
F_19 ( V_12 , V_76 , 0x00 ) ;
F_19 ( V_12 , V_77 , 0x30 ) ;
F_19 ( V_12 , V_78 , 0x00 ) ;
F_20 ( & V_12 -> V_34 , V_29 ) ;
V_12 -> V_79 = 1 ;
V_12 -> V_80 = 1 ;
V_12 -> V_36 = 1 ;
V_12 -> V_81 = 1 ;
V_12 -> V_82 = V_82 [ V_13 ] ;
}
static int T_1 F_37 ( struct V_83 * V_84 )
{
struct V_15 * V_16 = V_84 -> V_16 ;
struct V_85 V_86 , V_87 ;
unsigned int V_48 ;
int V_18 ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
V_86 . V_88 = V_87 . V_88 = V_89 ;
#if 0
strcpy(id1.name, "Mic Playback Switch");
if ((err = snd_ctl_remove_id(card, &id1)) < 0)
return err;
strcpy(id1.name, "Mic Playback Volume");
if ((err = snd_ctl_remove_id(card, &id1)) < 0)
return err;
#endif
for ( V_48 = 0 ; V_48 < F_33 ( V_90 ) ; V_48 ++ )
if ( ( V_18 = F_38 ( V_16 , F_39 ( & V_90 [ V_48 ] , V_84 ) ) ) < 0 )
return V_18 ;
F_40 ( V_84 , V_91 , 0x9f ) ;
F_40 ( V_84 , V_92 , 0x9f ) ;
F_40 ( V_84 , V_93 , 0x9f ) ;
F_40 ( V_84 , V_94 , 0x9f ) ;
strcpy ( V_86 . V_17 , L_13 ) ;
strcpy ( V_87 . V_17 , L_14 ) ;
if ( ( V_18 = F_41 ( V_16 , & V_86 , & V_87 ) ) < 0 )
return V_18 ;
strcpy ( V_86 . V_17 , L_15 ) ;
strcpy ( V_87 . V_17 , L_16 ) ;
if ( ( V_18 = F_41 ( V_16 , & V_86 , & V_87 ) ) < 0 )
return V_18 ;
strcpy ( V_86 . V_17 , L_13 ) ; V_86 . V_95 = 1 ;
strcpy ( V_87 . V_17 , L_17 ) ;
if ( ( V_18 = F_41 ( V_16 , & V_86 , & V_87 ) ) < 0 )
return V_18 ;
strcpy ( V_86 . V_17 , L_15 ) ;
strcpy ( V_87 . V_17 , L_18 ) ;
if ( ( V_18 = F_41 ( V_16 , & V_86 , & V_87 ) ) < 0 )
return V_18 ;
return 0 ;
}
static int T_1 F_42 ( int V_13 , struct V_9 * V_10 ,
struct V_96 * V_16 ,
const struct V_97 * V_98 )
{
struct V_99 * V_100 ;
int V_18 ;
V_10 -> V_13 = F_43 ( V_16 , V_98 -> V_101 [ 0 ] . V_98 , NULL ) ;
if ( V_10 -> V_13 == NULL )
return - V_102 ;
#ifdef F_13
V_10 -> V_103 = F_43 ( V_16 , V_98 -> V_101 [ 1 ] . V_98 , NULL ) ;
if ( V_10 -> V_103 == NULL )
return - V_102 ;
#endif
V_100 = V_10 -> V_13 ;
V_18 = F_44 ( V_100 ) ;
if ( V_18 < 0 ) {
F_9 ( V_23 L_19 ) ;
return V_18 ;
}
if ( F_45 ( V_100 , 0 ) + 0x100 != F_45 ( V_100 , 1 ) ||
F_45 ( V_100 , 0 ) + 0x10c != F_45 ( V_100 , 2 ) ) {
F_9 ( V_23 L_20 ) ;
return - V_104 ;
}
V_5 [ V_13 ] = F_45 ( V_100 , 0 ) ;
V_105 [ V_13 ] = F_46 ( V_100 , 0 ) ;
if ( V_106 [ V_13 ] >= 0 )
V_106 [ V_13 ] = F_46 ( V_100 , 1 ) ;
V_39 [ V_13 ] = F_47 ( V_100 , 0 ) ;
F_16 ( L_21 ,
( unsigned long long ) F_45 ( V_100 , 0 ) ,
( unsigned long long ) F_45 ( V_100 , 1 ) ,
( unsigned long long ) F_45 ( V_100 , 2 ) ) ;
F_16 ( L_22 , V_105 [ V_13 ] , V_106 [ V_13 ] , V_39 [ V_13 ] ) ;
#ifdef F_13
V_100 = V_10 -> V_103 ;
V_18 = F_44 ( V_100 ) ;
if ( V_18 < 0 ) {
F_9 ( V_23 L_23 ) ;
return V_18 ;
}
V_19 [ V_13 ] = F_45 ( V_100 , 0 ) ;
F_16 ( L_24 , V_19 [ V_13 ] ) ;
#endif
return 0 ;
}
static void F_48 ( struct V_15 * V_16 )
{
struct V_9 * V_10 = V_16 -> V_107 ;
if ( V_10 == NULL )
return;
#ifdef F_13
F_49 ( V_10 -> V_22 ) ;
#endif
if ( V_10 -> V_39 >= 0 )
F_50 ( V_10 -> V_39 , ( void * ) V_10 ) ;
}
static int F_51 ( int V_13 , struct V_15 * * V_108 )
{
struct V_15 * V_16 ;
struct V_9 * V_10 ;
int V_18 ;
V_18 = F_52 ( V_95 [ V_13 ] , V_98 [ V_13 ] , V_109 ,
sizeof( struct V_9 ) , & V_16 ) ;
if ( V_18 < 0 )
return V_18 ;
V_10 = V_16 -> V_107 ;
V_10 -> V_16 = V_16 ;
V_10 -> V_39 = - 1 ;
V_16 -> V_110 = F_48 ;
* V_108 = V_16 ;
return 0 ;
}
static int T_1 F_53 ( struct V_15 * V_16 , int V_13 )
{
int V_111 , V_112 , V_113 ;
struct V_9 * V_10 = V_16 -> V_107 ;
struct V_83 * V_46 ;
struct V_11 * V_12 ;
#ifdef F_13
struct V_1 * V_114 ;
#endif
struct V_115 * V_116 ;
char * V_117 ;
int V_18 ;
V_111 = V_39 [ V_13 ] ;
V_112 = V_105 [ V_13 ] ;
V_113 = V_106 [ V_13 ] ;
if ( ( V_18 = F_54 ( V_16 ,
V_5 [ V_13 ] ,
- V_111 , V_112 , V_113 ,
0 , 32 ,
V_118 [ V_13 ] , V_119 [ V_13 ] , & V_12 ) ) < 0 )
return V_18 ;
if ( ( V_18 = F_12 ( V_10 , V_12 , V_13
#ifdef F_13
, & V_114
#endif
) ) < 0 )
return V_18 ;
V_10 -> V_44 = V_12 -> V_21 . V_120 ;
V_10 -> V_45 = V_12 -> V_21 . V_5 + 0x10c + 2 ;
F_36 ( V_13 , V_12 ) ;
F_29 ( V_12 ) ;
if ( ( V_18 = F_55 ( V_12 ) ) < 0 )
return V_18 ;
if ( F_56 ( V_111 , F_21 , 0 ,
L_25 , V_10 ) ) {
F_9 (KERN_ERR PFX L_26 , xirq) ;
return - V_102 ;
}
V_10 -> V_39 = V_111 ;
V_18 = F_57 ( V_16 ,
V_12 -> V_21 . V_5 + 0x10c , - 1 , V_111 ,
V_113 < 0 ? V_112 : V_113 , V_112 ,
V_121 ,
V_122 |
V_123 |
V_124 ,
& V_46 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_58 ( V_46 , 0 , & V_116 ) ;
if ( V_18 < 0 )
return V_18 ;
sprintf ( V_116 -> V_17 + strlen ( V_116 -> V_17 ) , L_27 , V_12 -> V_38 + 'A' ) ;
strcat ( V_116 -> V_17 , L_28 ) ;
V_18 = F_59 ( V_46 , 2 , NULL ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_60 ( V_46 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_118 [ V_13 ] > 0 ) {
V_18 = F_61 ( V_12 , 1 , 1 , NULL ) ;
if ( V_18 < 0 )
return V_18 ;
}
V_18 = F_37 ( V_46 ) ;
if ( V_18 < 0 )
return V_18 ;
#ifdef F_13
{
struct V_85 V_86 , V_87 ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
V_86 . V_88 = V_87 . V_88 = V_89 ;
strcpy ( V_86 . V_17 , L_29 ) ;
strcpy ( V_87 . V_17 , V_86 . V_17 ) ;
V_87 . V_95 = 1 ;
if ( ( V_18 = F_41 ( V_16 , & V_86 , & V_87 ) ) < 0 )
return V_18 ;
strcpy ( V_86 . V_17 , L_30 ) ;
strcpy ( V_87 . V_17 , V_86 . V_17 ) ;
if ( ( V_18 = F_41 ( V_16 , & V_86 , & V_87 ) ) < 0 )
return V_18 ;
if ( ( V_18 = F_62 ( V_16 , V_114 , 0 , 1 ) ) < 0 )
return V_18 ;
}
#endif
V_12 -> V_125 = V_126 [ V_13 ] ;
if ( ( V_18 = F_63 ( V_12 , 0 , NULL ) ) < 0 )
return V_18 ;
#ifndef F_13
V_117 = L_8 ;
if ( V_12 -> V_21 . V_68 == 1 && V_12 -> V_21 . V_72 == 8 )
V_117 = L_31 ;
#else
V_117 = L_32 ;
#endif
strcpy ( V_16 -> V_127 , V_117 ) ;
strcpy ( V_16 -> V_37 , V_117 ) ;
sprintf ( V_16 -> V_128 , L_33 ,
V_117 ,
V_12 -> V_21 . V_5 ,
V_111 ,
V_112 ) ;
if ( V_113 >= 0 )
sprintf ( V_16 -> V_128 + strlen ( V_16 -> V_128 ) , L_34 , V_113 ) ;
V_18 = F_64 ( V_16 ) ;
if ( V_18 < 0 )
return V_18 ;
V_10 -> V_46 = V_46 ;
V_10 -> V_12 = V_12 ;
return 0 ;
}
static int T_1 F_65 ( int V_13 , struct V_129 * V_130 )
{
struct V_15 * V_16 ;
int V_18 ;
V_18 = F_51 ( V_13 , & V_16 ) ;
if ( V_18 < 0 )
return V_18 ;
F_66 ( V_16 , V_130 ) ;
if ( ( V_18 = F_53 ( V_16 , V_13 ) ) < 0 ) {
F_67 ( V_16 ) ;
return V_18 ;
}
F_68 ( V_130 , V_16 ) ;
return 0 ;
}
static int T_1 F_69 ( struct V_129 * V_100 ,
unsigned int V_13 )
{
if ( ! V_131 [ V_13 ] )
return 0 ;
#ifdef F_70
if ( V_132 [ V_13 ] )
return 0 ;
#endif
return 1 ;
}
static int T_1 F_71 ( struct V_129 * V_100 ,
unsigned int V_13 )
{
int V_18 ;
static int V_133 [] = { 5 , 11 , 12 , 9 , 7 , 15 , 3 , - 1 } ;
static int V_134 [] = { 0 , 1 , 3 , 5 , 6 , 7 , - 1 } ;
if ( V_39 [ V_13 ] == V_135 ) {
if ( ( V_39 [ V_13 ] = F_72 ( V_133 ) ) < 0 ) {
F_9 (KERN_ERR PFX L_35 ) ;
return - V_102 ;
}
}
if ( V_105 [ V_13 ] == V_136 ) {
if ( ( V_105 [ V_13 ] = F_73 ( V_134 ) ) < 0 ) {
F_9 (KERN_ERR PFX L_36 ) ;
return - V_102 ;
}
}
if ( V_106 [ V_13 ] == V_136 ) {
if ( ( V_106 [ V_13 ] = F_73 ( V_134 ) ) < 0 ) {
F_9 (KERN_ERR PFX L_37 ) ;
return - V_102 ;
}
}
if ( V_5 [ V_13 ] != V_20 )
return F_65 ( V_13 , V_100 ) ;
else {
static long V_137 [] = { 0x210 , 0x220 , 0x230 , 0x240 , 0x250 , 0x260 } ;
int V_53 ;
for ( V_53 = 0 ; V_53 < F_33 ( V_137 ) ; V_53 ++ ) {
V_5 [ V_13 ] = V_137 [ V_53 ] ;
V_18 = F_65 ( V_13 , V_100 ) ;
if ( ! V_18 )
return 0 ;
}
return V_18 ;
}
}
static int T_3 F_74 ( struct V_129 * V_130 , unsigned int V_13 )
{
F_67 ( F_75 ( V_130 ) ) ;
F_68 ( V_130 , NULL ) ;
return 0 ;
}
static int T_1 F_76 ( struct V_96 * V_138 ,
const struct V_97 * V_139 )
{
static int V_13 ;
struct V_15 * V_16 ;
int V_7 ;
for ( ; V_13 < V_140 ; V_13 ++ ) {
if ( V_131 [ V_13 ] && V_132 [ V_13 ] )
break;
}
if ( V_13 >= V_140 )
return - V_24 ;
V_7 = F_51 ( V_13 , & V_16 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ( V_7 = F_42 ( V_13 , V_16 -> V_107 , V_138 , V_139 ) ) < 0 ) {
F_67 ( V_16 ) ;
return V_7 ;
}
F_66 ( V_16 , & V_138 -> V_16 -> V_13 ) ;
if ( ( V_7 = F_53 ( V_16 , V_13 ) ) < 0 ) {
F_67 ( V_16 ) ;
return V_7 ;
}
F_77 ( V_138 , V_16 ) ;
V_13 ++ ;
return 0 ;
}
static void T_3 F_78 ( struct V_96 * V_138 )
{
F_67 ( F_79 ( V_138 ) ) ;
F_77 ( V_138 , NULL ) ;
}
static int T_4 F_80 ( void )
{
int V_18 ;
V_18 = F_81 ( & V_141 , V_140 ) ;
#ifdef F_70
if ( ! V_18 )
V_142 = 1 ;
V_18 = F_82 ( & V_143 ) ;
if ( ! V_18 )
V_144 = 1 ;
if ( V_142 )
V_18 = 0 ;
#endif
return V_18 ;
}
static void T_5 F_83 ( void )
{
#ifdef F_70
if ( V_144 )
F_84 ( & V_143 ) ;
if ( V_142 )
#endif
F_85 ( & V_141 ) ;
}
