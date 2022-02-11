int F_1 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char V_4 )
{
int V_5 ;
unsigned char V_6 [ 2 ] ;
V_6 [ 0 ] = V_3 & 0x7f ;
V_6 [ 1 ] = V_4 ;
if ( ( V_5 = F_2 ( V_2 , V_6 , 2 ) ) != 2 ) {
F_3 ( V_7 L_1
L_2 , V_6 [ 0 ] , V_6 [ 1 ] , V_5 ) ;
return V_5 < 0 ? V_5 : - V_8 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned char V_3 )
{
int V_5 ;
unsigned char V_6 ;
if ( ( V_5 = F_2 ( V_2 , & V_3 , 1 ) ) != 1 ) {
F_3 ( V_7 L_3
L_4 , V_3 ) ;
return V_5 < 0 ? V_5 : - V_8 ;
}
if ( ( V_5 = F_5 ( V_2 , & V_6 , 1 ) ) != 1 ) {
F_3 ( V_7 L_5
L_6 , V_3 ) ;
return V_5 < 0 ? V_5 : - V_8 ;
}
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 , int V_9 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
int V_5 ;
V_9 = V_9 ? V_13 : 0 ;
if ( V_9 != ( V_11 -> V_14 [ V_15 ] & V_9 ) ) {
V_11 -> V_14 [ V_15 ] &= ~ V_13 ;
V_11 -> V_14 [ V_15 ] |= V_9 ;
V_5 = F_1 ( V_2 , V_15 ,
V_11 -> V_14 [ V_15 ] ) ;
if ( V_5 < 0 )
return V_5 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
int V_9 ,
unsigned char * V_16 ,
int V_17 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
char * V_18 = V_9 ?
V_11 -> V_19 . V_20 : V_11 -> V_19 . V_21 ;
char V_22 [ 32 ] ;
int V_5 , V_23 ;
if ( ! memcmp ( V_18 , V_16 , V_17 ) )
return 0 ;
if ( ( V_5 = F_6 ( V_2 , V_9 ) ) < 0 )
return V_5 ;
memcpy ( V_18 , V_16 , V_17 ) ;
if ( V_9 ) {
memset ( V_22 , 0 , sizeof( V_22 ) ) ;
if ( memcmp ( V_18 , V_22 , V_17 ) == 0 ) {
V_11 -> V_14 [ V_24 ] &= ~ V_25 ;
V_11 -> V_14 [ V_24 ] |= V_26 |
V_27 ;
V_5 = F_1 ( V_2 , V_24 ,
V_11 -> V_14 [ V_24 ] ) ;
return V_5 < 0 ? V_5 : 0 ;
}
}
V_22 [ 0 ] = V_28 | V_29 ;
for ( V_23 = 0 ; V_23 < V_17 ; V_23 ++ )
V_22 [ V_23 + 1 ] = F_8 ( V_16 [ V_23 ] ) ;
if ( F_2 ( V_2 , V_22 , V_17 + 1 ) != V_17 + 1 )
return - V_8 ;
return 1 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_12 ) ;
}
int F_11 ( struct V_30 * V_31 ,
unsigned char V_32 ,
unsigned int V_33 ,
struct V_1 * * V_34 )
{
static unsigned char V_35 [] = {
V_36 | V_28 ,
V_37 | V_38 ,
0x00 ,
V_39 | V_40 ,
V_41 ,
V_42 | V_43 ,
V_44 | V_45 ,
} ;
static unsigned char V_46 [] = {
V_47 | V_28 ,
0xff ,
V_48 | V_49 ,
V_50 | V_27 | V_51 ,
} ;
int V_5 ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
unsigned char V_6 [ 24 ] ;
if ( ( V_5 = F_12 ( V_31 , L_7 ,
V_52 | ( V_32 & 7 ) ,
& V_2 ) ) < 0 )
return V_5 ;
V_11 = V_2 -> V_12 = F_13 ( sizeof( * V_11 ) , V_53 ) ;
if ( V_11 == NULL ) {
F_14 ( V_2 ) ;
return - V_54 ;
}
V_2 -> V_55 = F_9 ;
F_15 ( V_31 ) ;
V_5 = F_4 ( V_2 , V_56 ) ;
if ( V_5 != V_57 ) {
F_3 ( V_58 L_8
L_9 , V_5 ) ;
V_5 = F_4 ( V_2 , V_56 ) ;
}
if ( V_5 != V_57 ) {
F_16 ( V_31 ) ;
F_3 ( V_7 L_10
L_11 ,
V_57 , V_5 ) ;
F_3 ( V_7 L_12 ) ;
return - V_59 ;
}
V_5 = F_1 ( V_2 , V_60 , 0x00 ) ;
if ( V_5 < 0 )
goto V_61;
memcpy ( V_11 -> V_14 + ( V_35 [ 0 ] & 0x7f ) , V_35 + 1 , 6 ) ;
if ( ( V_5 = F_2 ( V_2 , V_35 , 7 ) ) != 7 ) {
V_5 = V_5 < 0 ? V_5 : - V_8 ;
goto V_61;
}
memset ( V_6 , 0 , 7 ) ;
V_6 [ 0 ] = 9 ;
if ( ( V_5 = F_2 ( V_2 , V_6 , 7 ) ) != 7 )
goto V_61;
memcpy ( V_11 -> V_14 + ( V_46 [ 0 ] & 0x7f ) , V_46 + 1 , 3 ) ;
if ( ( V_5 = F_2 ( V_2 , V_46 , 4 ) ) != 4 ) {
V_5 = V_5 < 0 ? V_5 : - V_8 ;
goto V_61;
}
F_17 ( V_62 , V_6 ) ;
memset ( V_6 + 4 , 0 , 24 - 4 ) ;
if ( F_7 ( V_2 , 0 , V_6 , 24 ) < 0 )
goto V_61;
memcpy ( V_11 -> V_19 . V_63 , V_6 , 24 ) ;
memcpy ( V_11 -> V_19 . V_64 , V_6 , 24 ) ;
F_16 ( V_31 ) ;
if ( V_33 < 1 )
V_33 = 1 ;
V_11 -> V_33 = V_33 ;
F_18 ( V_2 ) ;
#if 0
{
char buf[128];
int xx;
buf[0] = 0x81;
snd_i2c_sendbytes(device, buf, 1);
snd_i2c_readbytes(device, buf, 127);
for (xx = 0; xx < 127; xx++)
printk(KERN_DEBUG "reg[0x%x] = 0x%x\n", xx+1, buf[xx]);
}
#endif
if ( V_34 )
* V_34 = V_2 ;
return 0 ;
V_61:
F_16 ( V_31 ) ;
F_14 ( V_2 ) ;
return V_5 < 0 ? V_5 : - V_8 ;
}
static void F_18 ( struct V_1 * V_10 )
{
struct V_10 * V_11 ;
unsigned long V_65 ;
int V_22 , V_66 = 0 ;
if ( F_19 ( ! V_10 ) )
return;
V_11 = V_10 -> V_12 ;
F_15 ( V_10 -> V_31 ) ;
if ( ( V_11 -> V_14 [ V_60 ] & V_67 ) ==
V_67 )
V_66 = 1 ;
V_11 -> V_14 [ V_60 ] &= ~ ( V_68 | V_69 ) ;
F_1 ( V_10 , V_60 ,
V_11 -> V_14 [ V_60 ] ) ;
F_20 ( 200 ) ;
V_11 -> V_14 [ V_60 ] |= V_68 | V_41 ;
F_1 ( V_10 , V_60 ,
V_11 -> V_14 [ V_60 ] ) ;
F_20 ( 200 ) ;
F_16 ( V_10 -> V_31 ) ;
V_65 = V_70 + V_11 -> V_33 ;
while ( F_21 ( V_65 , V_70 ) ) {
F_15 ( V_10 -> V_31 ) ;
V_22 = F_4 ( V_10 , V_71 ) ;
F_16 ( V_10 -> V_31 ) ;
if ( ! ( V_22 & V_72 ) )
break;
F_22 ( 1 ) ;
}
F_15 ( V_10 -> V_31 ) ;
V_11 -> V_14 [ V_60 ] &= ~ V_69 ;
if ( V_66 )
V_11 -> V_14 [ V_60 ] |= V_67 ;
F_1 ( V_10 , V_60 ,
V_11 -> V_14 [ V_60 ] ) ;
F_16 ( V_10 -> V_31 ) ;
}
static int F_23 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
V_76 -> type = V_77 ;
V_76 -> V_17 = 1 ;
V_76 -> V_78 . integer . V_79 = 0 ;
V_76 -> V_78 . integer . V_80 = 255 ;
return 0 ;
}
static int F_24 ( struct V_73 * V_74 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = F_25 ( V_74 ) ;
int V_22 ;
F_15 ( V_2 -> V_31 ) ;
V_22 = F_4 ( V_2 , V_74 -> V_83 ) ;
F_16 ( V_2 -> V_31 ) ;
if ( V_22 < 0 )
return V_22 ;
V_82 -> V_78 . integer . V_78 [ 0 ] = V_22 ;
return 0 ;
}
static int F_26 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
V_76 -> type = V_84 ;
V_76 -> V_17 = 10 ;
return 0 ;
}
static int F_27 ( struct V_73 * V_74 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = F_25 ( V_74 ) ;
unsigned char V_3 = V_85 ;
int V_5 ;
F_15 ( V_2 -> V_31 ) ;
if ( ( V_5 = F_2 ( V_2 , & V_3 , 1 ) ) != 1 ) {
F_3 ( V_7 L_3
L_4 , V_3 ) ;
F_16 ( V_2 -> V_31 ) ;
return V_5 < 0 ? V_5 : - V_8 ;
}
V_5 = F_5 ( V_2 , V_82 -> V_78 . V_86 . V_22 , 10 ) ;
if ( V_5 != 10 ) {
F_3 ( V_7 L_13
L_6 ) ;
F_16 ( V_2 -> V_31 ) ;
return V_5 < 0 ? V_5 : - V_8 ;
}
F_16 ( V_2 -> V_31 ) ;
return 0 ;
}
static int F_28 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
V_76 -> type = V_87 ;
V_76 -> V_17 = 1 ;
return 0 ;
}
static int F_29 ( struct V_73 * V_74 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = F_25 ( V_74 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
F_15 ( V_2 -> V_31 ) ;
memcpy ( V_82 -> V_78 . V_88 . V_89 , V_11 -> V_19 . V_63 , 24 ) ;
F_16 ( V_2 -> V_31 ) ;
return 0 ;
}
static int F_30 ( struct V_73 * V_74 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = F_25 ( V_74 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned char * V_89 = V_74 -> V_83 ?
V_11 -> V_19 . V_64 : V_11 -> V_19 . V_63 ;
struct V_90 * V_91 = V_11 -> V_19 . V_92 ?
V_11 -> V_19 . V_92 -> V_91 : NULL ;
int V_5 , V_93 ;
F_15 ( V_2 -> V_31 ) ;
V_93 = memcmp ( V_82 -> V_78 . V_88 . V_89 , V_89 , 24 ) != 0 ;
memcpy ( V_89 , V_82 -> V_78 . V_88 . V_89 , 24 ) ;
if ( V_93 && ( V_74 -> V_83 ?
V_91 != NULL : V_91 == NULL ) ) {
V_5 = F_7 ( V_2 , 0 , V_89 , 24 ) ;
if ( V_5 < 0 )
V_93 = V_5 ;
}
F_16 ( V_2 -> V_31 ) ;
return V_93 ;
}
static int F_31 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
V_76 -> type = V_87 ;
V_76 -> V_17 = 1 ;
return 0 ;
}
static int F_32 ( struct V_73 * V_74 ,
struct V_81 * V_82 )
{
memset ( V_82 -> V_78 . V_88 . V_89 , 0xff , 24 ) ;
return 0 ;
}
int F_33 ( struct V_1 * V_10 ,
struct V_94 * V_95 ,
struct V_94 * V_96 )
{
struct V_10 * V_11 = V_10 -> V_12 ;
struct V_73 * V_97 ;
unsigned int V_23 ;
int V_5 ;
if ( F_19 ( ! V_95 || ! V_96 ) )
return - V_98 ;
for ( V_23 = 0 ; V_23 < F_34 ( V_99 ) ; V_23 ++ ) {
V_97 = F_35 ( & V_99 [ V_23 ] , V_10 ) ;
if ( V_97 == NULL )
return - V_54 ;
V_97 -> V_100 . V_2 = V_95 -> V_101 -> V_2 ;
V_97 -> V_100 . V_102 = V_95 -> V_103 ;
V_5 = F_36 ( V_10 -> V_31 -> V_104 , V_97 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ! strcmp ( V_97 -> V_100 . V_105 ,
F_37 ( L_14 , V_106 , V_107 ) ) )
V_11 -> V_19 . V_108 = V_97 ;
}
V_11 -> V_19 . V_92 = V_95 ;
V_11 -> V_109 . V_92 = V_96 ;
if ( F_19 ( ! V_11 -> V_19 . V_108 ) )
return - V_8 ;
return 0 ;
}
int F_38 ( struct V_1 * V_10 , int V_110 )
{
struct V_10 * V_11 ;
if ( F_19 ( ! V_10 ) )
return - V_111 ;
V_11 = V_10 -> V_12 ;
if ( V_110 )
memcpy ( V_11 -> V_19 . V_64 ,
V_11 -> V_19 . V_63 , 24 ) ;
V_11 -> V_19 . V_108 -> V_112 [ 0 ] . V_113 &= ~ V_114 ;
F_39 ( V_10 -> V_31 -> V_104 ,
V_115 | V_116 ,
& V_11 -> V_19 . V_108 -> V_100 ) ;
return 0 ;
}
int F_40 ( struct V_1 * V_10 , unsigned int V_117 )
{
struct V_10 * V_11 ;
char * V_89 ;
int V_5 , V_118 ;
if ( F_19 ( ! V_10 ) )
return - V_111 ;
V_11 = V_10 -> V_12 ;
V_89 = V_11 -> V_19 . V_64 ;
F_15 ( V_10 -> V_31 ) ;
if ( V_89 [ 0 ] & V_119 ) {
V_89 [ 0 ] &= ~ V_120 ;
switch ( V_117 ) {
case 32000 : V_89 [ 0 ] |= V_121 ; break;
case 44100 : V_89 [ 0 ] |= V_122 ; break;
case 48000 : V_89 [ 0 ] |= V_123 ; break;
default: V_89 [ 0 ] |= V_124 ; break;
}
} else {
V_89 [ 3 ] &= ~ V_125 ;
switch ( V_117 ) {
case 32000 : V_89 [ 3 ] |= V_126 ; break;
case 44100 : V_89 [ 3 ] |= V_127 ; break;
case 48000 : V_89 [ 3 ] |= V_128 ; break;
}
}
V_5 = F_7 ( V_10 , 0 , V_89 , 24 ) ;
if ( V_5 > 0 )
F_39 ( V_10 -> V_31 -> V_104 ,
V_115 ,
& V_11 -> V_19 . V_108 -> V_100 ) ;
V_118 = V_11 -> V_117 != V_117 ;
V_11 -> V_117 = V_117 ;
F_16 ( V_10 -> V_31 ) ;
if ( V_118 )
F_18 ( V_10 ) ;
return V_5 < 0 ? V_5 : 0 ;
}
static int T_1 F_41 ( void )
{
return 0 ;
}
static void T_2 F_42 ( void )
{
}
