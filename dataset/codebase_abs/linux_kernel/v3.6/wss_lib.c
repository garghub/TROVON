static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , 0 , V_3 ,
& V_4 ) ;
}
static inline void F_3 ( struct V_5 * V_6 , T_1 V_7 , T_1 V_8 )
{
F_4 ( V_8 , V_6 -> V_9 + V_7 ) ;
}
static inline T_1 F_5 ( struct V_5 * V_6 , T_1 V_7 )
{
return F_6 ( V_6 -> V_9 + V_7 ) ;
}
static void F_7 ( struct V_5 * V_6 )
{
int V_10 ;
for ( V_10 = 250 ;
V_10 > 0 && ( F_5 ( V_6 , F_8 ( V_11 ) ) & V_12 ) ;
V_10 -- )
F_9 ( 100 ) ;
}
static void F_10 ( struct V_5 * V_6 , unsigned char V_13 ,
unsigned char V_14 )
{
int V_10 ;
for ( V_10 = 250 ;
V_10 > 0 && ( F_5 ( V_6 , F_8 ( V_11 ) ) & V_12 ) ;
V_10 -- )
F_9 ( 10 ) ;
F_3 ( V_6 , F_8 ( V_11 ) , V_6 -> V_15 | V_13 ) ;
F_3 ( V_6 , F_8 ( V_16 ) , V_14 ) ;
F_11 () ;
}
void F_12 ( struct V_5 * V_6 , unsigned char V_13 , unsigned char V_14 )
{
F_7 ( V_6 ) ;
#ifdef F_13
if ( F_5 ( V_6 , F_8 ( V_11 ) ) & V_12 )
F_14 ( V_17 L_1
L_2 , V_13 , V_14 ) ;
#endif
F_3 ( V_6 , F_8 ( V_11 ) , V_6 -> V_15 | V_13 ) ;
F_3 ( V_6 , F_8 ( V_16 ) , V_14 ) ;
V_6 -> V_18 [ V_13 ] = V_14 ;
F_11 () ;
F_15 ( L_3 ,
V_6 -> V_15 | V_13 , V_14 ) ;
}
unsigned char F_16 ( struct V_5 * V_6 , unsigned char V_13 )
{
F_7 ( V_6 ) ;
#ifdef F_13
if ( F_5 ( V_6 , F_8 ( V_11 ) ) & V_12 )
F_14 ( V_17 L_4
L_5 , V_13 ) ;
#endif
F_3 ( V_6 , F_8 ( V_11 ) , V_6 -> V_15 | V_13 ) ;
F_11 () ;
return F_5 ( V_6 , F_8 ( V_16 ) ) ;
}
void F_17 ( struct V_5 * V_6 , unsigned char V_13 ,
unsigned char V_8 )
{
F_3 ( V_6 , F_8 ( V_11 ) , V_6 -> V_15 | 0x17 ) ;
F_3 ( V_6 , F_8 ( V_16 ) ,
V_13 | ( V_6 -> V_18 [ V_19 ] & 0x01 ) ) ;
F_3 ( V_6 , F_8 ( V_16 ) , V_8 ) ;
V_6 -> V_20 [ F_18 ( V_13 ) ] = V_8 ;
#if 0
printk(KERN_DEBUG "ext out : reg = 0x%x, val = 0x%x\n", reg, val);
#endif
}
unsigned char F_19 ( struct V_5 * V_6 , unsigned char V_13 )
{
F_3 ( V_6 , F_8 ( V_11 ) , V_6 -> V_15 | 0x17 ) ;
F_3 ( V_6 , F_8 ( V_16 ) ,
V_13 | ( V_6 -> V_18 [ V_19 ] & 0x01 ) ) ;
#if 1
return F_5 ( V_6 , F_8 ( V_16 ) ) ;
#else
{
unsigned char V_21 ;
V_21 = F_5 ( V_6 , F_8 ( V_16 ) ) ;
F_20 ( V_17 L_6 ,
V_13 , V_21 ) ;
return V_21 ;
}
#endif
}
static void F_21 ( struct V_5 * V_6 )
{
int V_10 ;
for ( V_10 = 5 ; V_10 > 0 ; V_10 -- )
F_5 ( V_6 , F_8 ( V_11 ) ) ;
for ( V_10 = 25000 ;
V_10 > 0 && ( F_5 ( V_6 , F_8 ( V_11 ) ) & V_12 ) ;
V_10 -- )
F_9 ( 10 ) ;
}
void F_22 ( struct V_5 * V_6 )
{
unsigned long V_22 ;
int V_10 ;
F_7 ( V_6 ) ;
#ifdef F_13
if ( F_5 ( V_6 , F_8 ( V_11 ) ) & V_12 )
F_14 ( V_17
L_7 ) ;
#endif
F_23 ( & V_6 -> V_23 , V_22 ) ;
V_6 -> V_15 |= V_24 ;
V_10 = F_5 ( V_6 , F_8 ( V_11 ) ) ;
if ( V_10 == 0x80 )
F_14 ( V_17 L_8
L_9 ,
V_6 -> V_9 ) ;
if ( ! ( V_10 & V_24 ) )
F_3 ( V_6 , F_8 ( V_11 ) ,
V_6 -> V_15 | ( V_10 & 0x1f ) ) ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
}
void F_25 ( struct V_5 * V_6 )
{
unsigned long V_22 ;
unsigned long V_25 ;
int V_10 ;
int V_26 = V_27 | V_28 | V_29 ;
F_21 ( V_6 ) ;
#ifdef F_13
if ( F_5 ( V_6 , F_8 ( V_11 ) ) & V_12 )
F_14 ( V_17 L_10
L_11 ,
( long ) F_8 ( V_11 ) ) ;
#endif
F_23 ( & V_6 -> V_23 , V_22 ) ;
V_6 -> V_15 &= ~ V_24 ;
V_10 = F_5 ( V_6 , F_8 ( V_11 ) ) ;
F_3 ( V_6 , F_8 ( V_11 ) , V_6 -> V_15 | ( V_10 & 0x1f ) ) ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
if ( V_10 == 0x80 )
F_14 ( V_17 L_12
L_9 ,
V_6 -> V_9 ) ;
if ( ( V_10 & V_24 ) == 0 || ! ( V_6 -> V_30 & V_26 ) )
return;
F_26 ( 1 ) ;
F_15 ( L_13 , V_31 ) ;
V_25 = V_31 + F_27 ( 250 ) ;
while ( F_16 ( V_6 , V_32 ) &
V_33 ) {
if ( F_28 ( V_31 , V_25 ) ) {
F_14 ( V_34 L_14
L_15 ) ;
return;
}
F_26 ( 1 ) ;
}
F_15 ( L_16 , V_31 ) ;
V_25 = V_31 + F_27 ( 100 ) ;
while ( F_5 ( V_6 , F_8 ( V_11 ) ) & V_12 ) {
if ( F_28 ( V_31 , V_25 ) ) {
F_14 ( V_34 L_17 ) ;
return;
}
F_26 ( 1 ) ;
}
F_15 ( L_18 , V_31 ) ;
F_29 ( L_19 , F_5 ( V_6 , F_8 ( V_11 ) ) ) ;
}
static unsigned int F_30 ( unsigned char V_35 , unsigned int V_36 )
{
switch ( V_35 & 0xe0 ) {
case V_37 :
case V_38 :
V_36 >>= 1 ;
break;
case V_39 :
return V_36 >> 2 ;
}
if ( V_35 & V_40 )
V_36 >>= 1 ;
return V_36 ;
}
static int F_31 ( struct V_41 * V_42 ,
int V_43 )
{
struct V_5 * V_6 = F_32 ( V_42 ) ;
int V_44 = 0 ;
unsigned int V_45 ;
struct V_41 * V_46 ;
int V_47 ;
switch ( V_43 ) {
case V_48 :
case V_49 :
V_47 = 1 ; break;
case V_50 :
case V_51 :
V_47 = 0 ; break;
default:
return - V_52 ;
}
V_45 = 0 ;
F_33 (s, substream) {
if ( V_46 == V_6 -> V_53 ) {
V_45 |= V_54 ;
F_34 ( V_46 , V_42 ) ;
} else if ( V_46 == V_6 -> V_55 ) {
V_45 |= V_56 ;
F_34 ( V_46 , V_42 ) ;
}
}
F_35 ( & V_6 -> V_23 ) ;
if ( V_47 ) {
V_6 -> V_18 [ V_57 ] |= V_45 ;
if ( V_6 -> V_58 )
V_6 -> V_58 ( V_6 , V_45 , 1 ) ;
} else {
V_6 -> V_18 [ V_57 ] &= ~ V_45 ;
if ( V_6 -> V_58 )
V_6 -> V_58 ( V_6 , V_45 , 0 ) ;
}
F_12 ( V_6 , V_57 , V_6 -> V_18 [ V_57 ] ) ;
F_36 ( & V_6 -> V_23 ) ;
#if 0
snd_wss_debug(chip);
#endif
return V_44 ;
}
static unsigned char F_37 ( unsigned int V_59 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < F_38 ( V_61 ) ; V_60 ++ )
if ( V_59 == V_61 [ V_60 ] )
return V_62 [ V_60 ] ;
return V_62 [ F_38 ( V_61 ) - 1 ] ;
}
static unsigned char F_39 ( struct V_5 * V_6 ,
int V_35 ,
int V_63 )
{
unsigned char V_64 ;
V_64 = V_65 ;
switch ( V_35 ) {
case V_66 : V_64 = V_67 ; break;
case V_68 : V_64 = V_69 ; break;
case V_70 : V_64 = V_37 ; break;
case V_71 : V_64 = V_38 ; break;
case V_72 : V_64 = V_39 ; break;
}
if ( V_63 > 1 )
V_64 |= V_40 ;
#if 0
snd_printk(KERN_DEBUG "get_format: 0x%x (mode=0x%x)\n", format, mode);
#endif
return V_64 ;
}
static void F_40 ( struct V_5 * V_6 , int V_73 )
{
unsigned long V_22 ;
V_73 = V_73 ? 0x80 : 0 ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
if ( V_6 -> V_74 == V_73 ) {
F_24 ( & V_6 -> V_23 , V_22 ) ;
return;
}
if ( ! V_73 ) {
F_10 ( V_6 , V_75 ,
V_6 -> V_18 [ V_75 ] ) ;
F_10 ( V_6 , V_76 ,
V_6 -> V_18 [ V_76 ] ) ;
F_10 ( V_6 , V_77 ,
V_6 -> V_18 [ V_77 ] ) ;
} else {
F_10 ( V_6 , V_75 ,
0 ) ;
F_10 ( V_6 , V_76 ,
0 ) ;
F_10 ( V_6 , V_77 ,
0xfd ) ;
}
F_10 ( V_6 , V_78 ,
V_73 | V_6 -> V_18 [ V_78 ] ) ;
F_10 ( V_6 , V_79 ,
V_73 | V_6 -> V_18 [ V_79 ] ) ;
F_10 ( V_6 , V_80 ,
V_73 | V_6 -> V_18 [ V_80 ] ) ;
F_10 ( V_6 , V_81 ,
V_73 | V_6 -> V_18 [ V_81 ] ) ;
F_10 ( V_6 , V_82 ,
V_73 | V_6 -> V_18 [ V_82 ] ) ;
F_10 ( V_6 , V_83 ,
V_73 | V_6 -> V_18 [ V_83 ] ) ;
if ( ! ( V_6 -> V_30 & V_84 ) ) {
F_10 ( V_6 , V_85 ,
V_73 | V_6 -> V_18 [ V_85 ] ) ;
F_10 ( V_6 , V_86 ,
V_73 | V_6 -> V_18 [ V_86 ] ) ;
F_10 ( V_6 , V_87 ,
V_73 ? 0xc0 : V_6 -> V_18 [ V_87 ] ) ;
}
if ( V_6 -> V_30 == V_88 ) {
F_10 ( V_6 , V_89 ,
V_73 | V_6 -> V_18 [ V_89 ] ) ;
F_10 ( V_6 , V_90 ,
V_73 | V_6 -> V_18 [ V_90 ] ) ;
F_10 ( V_6 , V_91 ,
V_73 | V_6 -> V_18 [ V_91 ] ) ;
F_10 ( V_6 , V_92 ,
V_73 | V_6 -> V_18 [ V_92 ] ) ;
}
V_6 -> V_74 = V_73 ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
}
static void F_41 ( struct V_5 * V_6 ,
struct V_93 * V_94 ,
unsigned char V_95 )
{
unsigned long V_22 ;
int V_96 = 1 ;
F_42 ( & V_6 -> V_97 ) ;
if ( V_6 -> V_30 == V_98 ||
( V_6 -> V_30 & V_28 ) ) {
F_23 ( & V_6 -> V_23 , V_22 ) ;
if ( ( V_6 -> V_18 [ V_99 ] & 0x0f ) == ( V_95 & 0x0f ) ) {
F_12 ( V_6 , V_100 ,
V_6 -> V_18 [ V_100 ] | 0x10 ) ;
V_6 -> V_18 [ V_99 ] = V_95 ;
F_12 ( V_6 , V_99 ,
V_6 -> V_18 [ V_99 ] ) ;
F_12 ( V_6 , V_100 ,
V_6 -> V_18 [ V_100 ] &= ~ 0x10 ) ;
F_9 ( 100 ) ;
V_96 = 0 ;
}
F_24 ( & V_6 -> V_23 , V_22 ) ;
} else if ( V_6 -> V_30 == V_101 ) {
unsigned V_59 = F_43 ( V_94 ) ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
F_12 ( V_6 , V_99 , ( V_95 & 0xf0 ) ) ;
F_12 ( V_6 , V_102 , ( V_59 >> 8 ) & 0xff ) ;
F_12 ( V_6 , V_103 , V_59 & 0xff ) ;
V_96 = 0 ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
}
if ( V_96 ) {
F_22 ( V_6 ) ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
if ( V_6 -> V_30 != V_88 && ! V_6 -> V_104 ) {
if ( V_6 -> V_18 [ V_57 ] & V_56 )
V_95 = ( V_95 & 0xf0 ) |
( V_6 -> V_18 [ V_105 ] & 0x0f ) ;
} else {
V_6 -> V_18 [ V_99 ] = V_95 ;
}
F_12 ( V_6 , V_99 , V_95 ) ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
if ( V_6 -> V_30 == V_106 )
F_9 ( 100 ) ;
F_25 ( V_6 ) ;
}
F_44 ( & V_6 -> V_97 ) ;
}
static void F_45 ( struct V_5 * V_6 ,
struct V_93 * V_94 ,
unsigned char V_107 )
{
unsigned long V_22 ;
int V_96 = 1 ;
F_42 ( & V_6 -> V_97 ) ;
if ( V_6 -> V_30 == V_98 ||
( V_6 -> V_30 & V_28 ) ) {
F_23 ( & V_6 -> V_23 , V_22 ) ;
if ( ( V_6 -> V_18 [ V_99 ] & 0x0f ) == ( V_107 & 0x0f ) ||
( V_6 -> V_18 [ V_57 ] & V_54 ) ) {
F_12 ( V_6 , V_100 ,
V_6 -> V_18 [ V_100 ] | 0x20 ) ;
F_12 ( V_6 , V_105 ,
V_6 -> V_18 [ V_105 ] = V_107 ) ;
F_12 ( V_6 , V_100 ,
V_6 -> V_18 [ V_100 ] &= ~ 0x20 ) ;
V_96 = 0 ;
}
F_24 ( & V_6 -> V_23 , V_22 ) ;
} else if ( V_6 -> V_30 == V_101 ) {
unsigned V_59 = F_43 ( V_94 ) ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
F_12 ( V_6 , V_105 , ( V_107 & 0xf0 ) ) ;
F_12 ( V_6 , V_102 , ( V_59 >> 8 ) & 0xff ) ;
F_12 ( V_6 , V_103 , V_59 & 0xff ) ;
V_96 = 0 ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
}
if ( V_96 ) {
F_22 ( V_6 ) ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
if ( V_6 -> V_30 != V_88 &&
! ( V_6 -> V_18 [ V_57 ] & V_54 ) ) {
if ( V_6 -> V_104 )
F_12 ( V_6 , V_99 , V_107 ) ;
else
F_12 ( V_6 , V_99 ,
( V_6 -> V_18 [ V_99 ] & 0xf0 ) |
( V_107 & 0x0f ) ) ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
F_25 ( V_6 ) ;
F_22 ( V_6 ) ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
}
if ( V_6 -> V_30 & V_84 )
F_12 ( V_6 , V_99 , V_107 ) ;
else
F_12 ( V_6 , V_105 , V_107 ) ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
F_25 ( V_6 ) ;
}
F_44 ( & V_6 -> V_97 ) ;
}
static unsigned long F_46 ( struct V_108 * V_109 )
{
struct V_5 * V_6 = F_47 ( V_109 ) ;
if ( V_6 -> V_30 & V_110 )
return 14467 ;
else
return V_6 -> V_18 [ V_99 ] & 1 ? 9969 : 9920 ;
}
static int F_48 ( struct V_108 * V_109 )
{
unsigned long V_22 ;
unsigned int V_111 ;
struct V_5 * V_6 = F_47 ( V_109 ) ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
V_111 = V_109 -> V_112 ;
if ( ( V_6 -> V_18 [ V_100 ] & V_113 ) == 0 ||
( unsigned char ) ( V_111 >> 8 ) != V_6 -> V_18 [ V_114 ] ||
( unsigned char ) V_111 != V_6 -> V_18 [ V_115 ] ) {
V_6 -> V_18 [ V_114 ] = ( unsigned char ) ( V_111 >> 8 ) ;
F_12 ( V_6 , V_114 ,
V_6 -> V_18 [ V_114 ] ) ;
V_6 -> V_18 [ V_115 ] = ( unsigned char ) V_111 ;
F_12 ( V_6 , V_115 ,
V_6 -> V_18 [ V_115 ] ) ;
F_12 ( V_6 , V_100 ,
V_6 -> V_18 [ V_100 ] |
V_113 ) ;
}
F_24 ( & V_6 -> V_23 , V_22 ) ;
return 0 ;
}
static int F_49 ( struct V_108 * V_109 )
{
unsigned long V_22 ;
struct V_5 * V_6 = F_47 ( V_109 ) ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
V_6 -> V_18 [ V_100 ] &= ~ V_113 ;
F_12 ( V_6 , V_100 ,
V_6 -> V_18 [ V_100 ] ) ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
return 0 ;
}
static void F_50 ( struct V_5 * V_6 )
{
unsigned long V_22 ;
F_40 ( V_6 , 1 ) ;
F_25 ( V_6 ) ;
#ifdef F_51
F_14 ( V_17 L_20 ) ;
#endif
F_22 ( V_6 ) ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
V_6 -> V_18 [ V_57 ] &= ~ ( V_54 |
V_116 |
V_56 |
V_117 |
V_118 ) ;
V_6 -> V_18 [ V_57 ] |= V_119 ;
F_12 ( V_6 , V_57 , V_6 -> V_18 [ V_57 ] ) ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
F_25 ( V_6 ) ;
#ifdef F_51
F_14 ( V_17 L_21 ) ;
#endif
F_22 ( V_6 ) ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
V_6 -> V_18 [ V_57 ] &= ~ V_119 ;
F_12 ( V_6 , V_57 , V_6 -> V_18 [ V_57 ] ) ;
F_12 ( V_6 ,
V_100 , V_6 -> V_18 [ V_100 ] ) ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
F_25 ( V_6 ) ;
#ifdef F_51
F_14 ( V_17 L_22 ,
V_6 -> V_18 [ V_100 ] ) ;
#endif
F_23 ( & V_6 -> V_23 , V_22 ) ;
F_12 ( V_6 , V_120 ,
V_6 -> V_18 [ V_120 ] ) ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
F_22 ( V_6 ) ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
F_12 ( V_6 , V_99 ,
V_6 -> V_18 [ V_99 ] ) ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
F_25 ( V_6 ) ;
#ifdef F_51
F_14 ( V_17 L_23 ) ;
#endif
F_22 ( V_6 ) ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
if ( ! ( V_6 -> V_30 & V_84 ) )
F_12 ( V_6 , V_105 ,
V_6 -> V_18 [ V_105 ] ) ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
F_25 ( V_6 ) ;
F_40 ( V_6 , 0 ) ;
#ifdef F_51
F_14 ( V_17 L_24 ) ;
#endif
}
static int F_52 ( struct V_5 * V_6 , unsigned int V_121 )
{
unsigned long V_22 ;
F_42 ( & V_6 -> V_122 ) ;
if ( ( V_6 -> V_121 & V_121 ) ||
( ( V_6 -> V_121 & V_123 ) && V_6 -> V_104 ) ) {
F_44 ( & V_6 -> V_122 ) ;
return - V_124 ;
}
if ( V_6 -> V_121 & V_123 ) {
V_6 -> V_121 |= V_121 ;
F_44 ( & V_6 -> V_122 ) ;
return 0 ;
}
F_23 ( & V_6 -> V_23 , V_22 ) ;
if ( ! ( V_6 -> V_30 & V_84 ) ) {
F_12 ( V_6 , V_125 ,
V_126 |
V_127 |
V_128 ) ;
F_12 ( V_6 , V_125 , 0 ) ;
}
F_3 ( V_6 , F_8 ( V_129 ) , 0 ) ;
F_3 ( V_6 , F_8 ( V_129 ) , 0 ) ;
V_6 -> V_18 [ V_130 ] |= V_131 ;
F_12 ( V_6 , V_130 , V_6 -> V_18 [ V_130 ] ) ;
if ( ! ( V_6 -> V_30 & V_84 ) ) {
F_12 ( V_6 , V_125 ,
V_126 |
V_127 |
V_128 ) ;
F_12 ( V_6 , V_125 , 0 ) ;
}
F_24 ( & V_6 -> V_23 , V_22 ) ;
V_6 -> V_121 = V_121 ;
F_44 ( & V_6 -> V_122 ) ;
return 0 ;
}
static void F_53 ( struct V_5 * V_6 , unsigned int V_121 )
{
unsigned long V_22 ;
F_42 ( & V_6 -> V_122 ) ;
V_6 -> V_121 &= ~ V_121 ;
if ( V_6 -> V_121 & V_123 ) {
F_44 ( & V_6 -> V_122 ) ;
return;
}
F_23 ( & V_6 -> V_23 , V_22 ) ;
if ( ! ( V_6 -> V_30 & V_84 ) )
F_12 ( V_6 , V_125 , 0 ) ;
F_3 ( V_6 , F_8 ( V_129 ) , 0 ) ;
F_3 ( V_6 , F_8 ( V_129 ) , 0 ) ;
V_6 -> V_18 [ V_130 ] &= ~ V_131 ;
F_12 ( V_6 , V_130 , V_6 -> V_18 [ V_130 ] ) ;
if ( V_6 -> V_18 [ V_57 ] & ( V_54 | V_116 |
V_56 | V_117 ) ) {
F_24 ( & V_6 -> V_23 , V_22 ) ;
F_22 ( V_6 ) ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
V_6 -> V_18 [ V_57 ] &= ~ ( V_54 | V_116 |
V_56 | V_117 ) ;
F_12 ( V_6 , V_57 ,
V_6 -> V_18 [ V_57 ] ) ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
F_25 ( V_6 ) ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
}
if ( ! ( V_6 -> V_30 & V_84 ) )
F_12 ( V_6 , V_125 , 0 ) ;
F_3 ( V_6 , F_8 ( V_129 ) , 0 ) ;
F_3 ( V_6 , F_8 ( V_129 ) , 0 ) ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
V_6 -> V_121 = 0 ;
F_44 ( & V_6 -> V_122 ) ;
}
static int F_54 ( struct V_108 * V_109 )
{
struct V_5 * V_6 = F_47 ( V_109 ) ;
F_52 ( V_6 , V_132 ) ;
return 0 ;
}
static int F_55 ( struct V_108 * V_109 )
{
struct V_5 * V_6 = F_47 ( V_109 ) ;
F_53 ( V_6 , V_132 ) ;
return 0 ;
}
static int F_56 ( struct V_41 * V_42 ,
struct V_93 * V_133 )
{
struct V_5 * V_6 = F_32 ( V_42 ) ;
unsigned char V_134 ;
int V_135 ;
if ( ( V_135 = F_57 ( V_42 , F_58 ( V_133 ) ) ) < 0 )
return V_135 ;
V_134 = F_39 ( V_6 , F_59 ( V_133 ) ,
F_60 ( V_133 ) ) |
F_37 ( F_43 ( V_133 ) ) ;
V_6 -> V_136 ( V_6 , V_133 , V_134 ) ;
return 0 ;
}
static int F_61 ( struct V_41 * V_42 )
{
return F_62 ( V_42 ) ;
}
static int F_63 ( struct V_41 * V_42 )
{
struct V_5 * V_6 = F_32 ( V_42 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
unsigned long V_22 ;
unsigned int V_36 = F_64 ( V_42 ) ;
unsigned int V_137 = F_65 ( V_42 ) ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
V_6 -> V_138 = V_36 ;
V_6 -> V_18 [ V_57 ] &= ~ ( V_54 | V_116 ) ;
F_66 ( V_6 -> V_139 , V_2 -> V_140 , V_36 , V_141 | V_142 ) ;
V_137 = F_30 ( V_6 -> V_18 [ V_99 ] , V_137 ) - 1 ;
F_12 ( V_6 , V_143 , ( unsigned char ) V_137 ) ;
F_12 ( V_6 , V_144 , ( unsigned char ) ( V_137 >> 8 ) ) ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
#if 0
snd_wss_debug(chip);
#endif
return 0 ;
}
static int F_67 ( struct V_41 * V_42 ,
struct V_93 * V_133 )
{
struct V_5 * V_6 = F_32 ( V_42 ) ;
unsigned char V_145 ;
int V_135 ;
if ( ( V_135 = F_57 ( V_42 , F_58 ( V_133 ) ) ) < 0 )
return V_135 ;
V_145 = F_39 ( V_6 , F_59 ( V_133 ) ,
F_60 ( V_133 ) ) |
F_37 ( F_43 ( V_133 ) ) ;
V_6 -> V_146 ( V_6 , V_133 , V_145 ) ;
return 0 ;
}
static int F_68 ( struct V_41 * V_42 )
{
return F_62 ( V_42 ) ;
}
static int F_69 ( struct V_41 * V_42 )
{
struct V_5 * V_6 = F_32 ( V_42 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
unsigned long V_22 ;
unsigned int V_36 = F_64 ( V_42 ) ;
unsigned int V_137 = F_65 ( V_42 ) ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
V_6 -> V_147 = V_36 ;
V_6 -> V_18 [ V_57 ] &= ~ ( V_56 | V_117 ) ;
F_66 ( V_6 -> V_148 , V_2 -> V_140 , V_36 , V_149 | V_142 ) ;
if ( V_6 -> V_30 & V_84 )
V_137 = F_30 ( V_6 -> V_18 [ V_99 ] ,
V_137 ) ;
else
V_137 = F_30 ( V_6 -> V_18 [ V_105 ] ,
V_137 ) ;
V_137 -- ;
if ( V_6 -> V_104 && V_6 -> V_30 != V_88 ) {
F_12 ( V_6 , V_143 , ( unsigned char ) V_137 ) ;
F_12 ( V_6 , V_144 ,
( unsigned char ) ( V_137 >> 8 ) ) ;
} else {
F_12 ( V_6 , V_150 , ( unsigned char ) V_137 ) ;
F_12 ( V_6 , V_151 ,
( unsigned char ) ( V_137 >> 8 ) ) ;
}
F_24 ( & V_6 -> V_23 , V_22 ) ;
return 0 ;
}
void F_70 ( struct V_5 * V_6 )
{
unsigned long V_22 ;
unsigned char V_21 ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
V_21 = F_16 ( V_6 , V_32 ) ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
if ( V_21 & ( 0x08 | 0x02 ) )
V_6 -> V_55 -> V_2 -> V_152 ++ ;
}
T_2 F_71 ( int V_153 , void * V_154 )
{
struct V_5 * V_6 = V_154 ;
unsigned char V_155 ;
if ( V_6 -> V_30 & V_84 )
V_155 = V_126 ;
else
V_155 = F_16 ( V_6 , V_125 ) ;
if ( V_155 & V_128 ) {
if ( V_6 -> V_109 )
F_72 ( V_6 -> V_109 , V_6 -> V_109 -> V_112 ) ;
}
if ( V_6 -> V_104 && V_6 -> V_30 != V_88 ) {
if ( V_155 & V_126 ) {
if ( V_6 -> V_121 & V_156 ) {
if ( V_6 -> V_53 )
F_73 ( V_6 -> V_53 ) ;
}
if ( V_6 -> V_121 & V_157 ) {
if ( V_6 -> V_55 ) {
F_70 ( V_6 ) ;
F_73 ( V_6 -> V_55 ) ;
}
}
}
} else {
if ( V_155 & V_126 ) {
if ( V_6 -> V_53 )
F_73 ( V_6 -> V_53 ) ;
}
if ( V_155 & V_127 ) {
if ( V_6 -> V_55 ) {
F_70 ( V_6 ) ;
F_73 ( V_6 -> V_55 ) ;
}
}
}
F_35 ( & V_6 -> V_23 ) ;
V_155 = ~ V_158 | ~ V_155 ;
if ( V_6 -> V_30 & V_84 )
F_3 ( V_6 , F_8 ( V_129 ) , 0 ) ;
else
F_12 ( V_6 , V_125 , V_155 ) ;
F_36 ( & V_6 -> V_23 ) ;
return V_159 ;
}
static T_3 F_74 ( struct V_41 * V_42 )
{
struct V_5 * V_6 = F_32 ( V_42 ) ;
T_4 V_160 ;
if ( ! ( V_6 -> V_18 [ V_57 ] & V_54 ) )
return 0 ;
V_160 = F_75 ( V_6 -> V_139 , V_6 -> V_138 ) ;
return F_76 ( V_42 -> V_2 , V_160 ) ;
}
static T_3 F_77 ( struct V_41 * V_42 )
{
struct V_5 * V_6 = F_32 ( V_42 ) ;
T_4 V_160 ;
if ( ! ( V_6 -> V_18 [ V_57 ] & V_56 ) )
return 0 ;
V_160 = F_75 ( V_6 -> V_148 , V_6 -> V_147 ) ;
return F_76 ( V_42 -> V_2 , V_160 ) ;
}
static int F_78 ( struct V_5 * V_6 )
{
unsigned long V_10 = V_31 + F_27 ( 1000 ) ;
unsigned long V_22 ;
unsigned char V_161 ;
unsigned short V_30 = 0 ;
int V_135 = 0 ;
int V_60 ;
while ( F_5 ( V_6 , F_8 ( V_11 ) ) & V_12 ) {
if ( F_28 ( V_31 , V_10 ) )
return - V_162 ;
F_79 () ;
}
F_23 ( & V_6 -> V_23 , V_22 ) ;
F_10 ( V_6 , V_163 , 0 ) ;
F_10 ( V_6 , V_76 , 0x45 ) ;
V_161 = F_16 ( V_6 , V_76 ) ;
if ( V_161 != 0x45 ) {
if ( ( V_161 & ~ V_164 ) != 0x45 ) {
V_135 = - V_162 ;
goto V_165;
}
V_30 = V_166 ;
} else {
F_10 ( V_6 , V_75 , 0xaa ) ;
V_161 = F_16 ( V_6 , V_75 ) ;
if ( ( V_161 | V_164 ) != 0xaa ) {
V_135 = - V_162 ;
goto V_165;
}
}
F_5 ( V_6 , F_8 ( V_129 ) ) ;
F_3 ( V_6 , F_8 ( V_129 ) , 0 ) ;
F_11 () ;
if ( ( V_6 -> V_30 & V_167 ) != V_168 )
goto V_165;
if ( V_30 ) {
V_6 -> V_30 = V_30 ;
goto V_165;
}
V_161 = F_16 ( V_6 , V_163 ) ;
F_10 ( V_6 , V_163 , V_169 ) ;
for ( V_60 = 0 ; V_60 < 16 ; V_60 ++ ) {
if ( F_16 ( V_6 , V_60 ) != F_16 ( V_6 , 16 + V_60 ) ) {
if ( ( V_161 & 0xf ) != 0xa )
goto V_170;
F_10 ( V_6 , V_171 , 0 ) ;
V_161 = F_16 ( V_6 , V_171 ) & 0xe7 ;
if ( ! V_161 )
V_6 -> V_30 = V_172 ;
goto V_170;
}
}
if ( V_161 & 0x80 )
V_6 -> V_30 = V_173 ;
else
V_6 -> V_30 = V_29 ;
V_170:
F_10 ( V_6 , V_163 , 0 ) ;
V_165:
F_24 ( & V_6 -> V_23 , V_22 ) ;
return V_135 ;
}
static int F_80 ( struct V_5 * V_6 )
{
unsigned long V_22 ;
int V_60 , V_174 , V_175 , V_176 ;
unsigned char * V_160 ;
unsigned int V_177 ;
V_174 = F_78 ( V_6 ) ;
if ( V_174 < 0 )
return V_174 ;
V_177 = V_6 -> V_30 ;
if ( ( V_177 & V_167 ) == V_168 ) {
for ( V_60 = 0 ; V_60 < 50 ; V_60 ++ ) {
F_11 () ;
if ( F_5 ( V_6 , F_8 ( V_11 ) ) & V_12 )
F_26 ( 2 ) ;
else {
F_23 ( & V_6 -> V_23 , V_22 ) ;
F_12 ( V_6 , V_163 ,
V_169 ) ;
V_174 = F_16 ( V_6 , V_163 ) & 0x0f ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
if ( V_174 == 0x0a )
break;
}
}
F_15 ( L_25 , V_6 -> V_9 , V_174 ) ;
if ( V_174 != 0x0a )
return - V_162 ;
V_175 = F_16 ( V_6 , V_171 ) & 0xe7 ;
F_15 ( L_26 , V_175 ) ;
if ( V_175 == 0x80 ) {
unsigned char V_178 = F_16 ( V_6 , 23 ) ;
F_12 ( V_6 , 23 , ~ V_178 ) ;
if ( F_16 ( V_6 , 23 ) != V_178 )
V_6 -> V_30 = V_101 ;
else
V_6 -> V_30 = V_179 ;
} else if ( V_175 == 0xa0 ) {
V_6 -> V_30 = V_98 ;
} else if ( V_175 == 0xa2 ) {
V_6 -> V_30 = V_180 ;
} else if ( V_175 == 0xb2 ) {
V_6 -> V_30 = V_181 ;
} else if ( V_175 == 0x83 ) {
V_6 -> V_30 = V_182 ;
} else if ( V_175 == 0x03 ) {
V_6 -> V_30 = V_183 ;
} else {
F_14 ( V_34
L_27 , V_175 ) ;
return - V_162 ;
}
}
F_23 ( & V_6 -> V_23 , V_22 ) ;
F_5 ( V_6 , F_8 ( V_129 ) ) ;
F_3 ( V_6 , F_8 ( V_129 ) , 0 ) ;
F_11 () ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
if ( ! ( V_6 -> V_30 & V_84 ) )
V_6 -> V_18 [ V_163 ] = V_169 ;
switch ( V_6 -> V_30 ) {
case V_88 :
V_6 -> V_18 [ V_163 ] = V_184 ;
break;
case V_185 :
case V_183 :
case V_186 :
case V_187 :
case V_188 :
if ( V_177 == V_189 )
V_6 -> V_18 [ V_163 ] = V_190 ;
else
V_6 -> V_30 = V_182 ;
break;
}
V_6 -> V_18 [ V_57 ] =
( V_6 -> V_18 [ V_57 ] & ~ V_191 ) |
( V_6 -> V_104 ? V_191 : 0 ) ;
if ( V_6 -> V_30 != V_192 ) {
V_6 -> V_18 [ V_100 ] = 0x80 ;
V_6 -> V_18 [ V_120 ] =
V_6 -> V_30 == V_88 ? 0xc2 : 0x01 ;
}
if ( V_6 -> V_30 == V_101 )
V_6 -> V_18 [ V_193 ] = 8 ;
V_160 = ( unsigned char * ) & V_6 -> V_18 ;
V_176 = ( V_6 -> V_30 & V_84 ) ? 16 : 32 ;
F_25 ( V_6 ) ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
for ( V_60 = 0 ; V_60 < V_176 ; V_60 ++ )
F_12 ( V_6 , V_60 , * V_160 ++ ) ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
F_22 ( V_6 ) ;
F_25 ( V_6 ) ;
F_81 ( 2 ) ;
if ( ( V_177 & V_167 ) == V_168 ) {
if ( V_6 -> V_30 == V_183 ) {
V_175 = F_19 ( V_6 , V_194 ) ;
F_17 ( V_6 , V_194 , 0xff ) ;
V_174 = F_19 ( V_6 , V_194 ) ;
F_17 ( V_6 , V_194 , V_175 ) ;
F_15 ( L_28 , V_175 , V_174 ) ;
if ( ( V_174 & 0x1f ) == 0x1d ) {
V_6 -> V_30 = V_185 ;
switch ( V_174 >> 5 ) {
case 4 :
case 5 :
case 6 :
break;
default:
F_14 ( V_195
L_29
L_30 ,
V_174 ) ;
}
} else if ( ( V_174 & 0x1f ) == 0x0b ) {
switch ( V_174 >> 5 ) {
case 4 :
case 5 :
case 6 :
case 7 :
V_6 -> V_30 = V_183 ;
break;
default:
F_14 ( V_195
L_31
L_30 ,
V_174 ) ;
}
} else if ( ( V_174 & 0x1f ) == 0x08 ) {
V_6 -> V_30 = V_186 ;
switch ( V_174 >> 5 ) {
case 4 :
case 5 :
case 6 :
case 7 :
break;
default:
F_14 ( V_195
L_32
L_30 ,
V_174 ) ;
}
} else if ( ( V_174 & 0x1f ) == 0x09 ) {
V_6 -> V_30 = V_187 ;
switch ( V_174 >> 5 ) {
case 5 :
case 6 :
case 7 :
break;
default:
F_14 ( V_195
L_33
L_30 ,
V_174 ) ;
}
} else if ( ( V_174 & 0x1f ) == 0x1e ) {
V_6 -> V_30 = V_188 ;
switch ( V_174 >> 5 ) {
case 4 :
case 5 :
case 6 :
break;
default:
F_14 ( V_195
L_34
L_30 ,
V_174 ) ;
}
} else {
F_14 ( V_195
L_35
L_30 , V_174 ) ;
}
}
}
return 0 ;
}
static int F_82 ( struct V_41 * V_42 )
{
struct V_5 * V_6 = F_32 ( V_42 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
int V_135 ;
V_2 -> V_177 = V_196 ;
if ( V_6 -> V_30 & V_84 )
V_2 -> V_177 . V_197 &= ~ ( V_198 |
V_199 ) ;
if ( V_6 -> V_30 == V_88 && V_6 -> V_139 > 3 )
V_2 -> V_177 . V_197 &= ~ V_200 ;
if ( V_6 -> V_30 == V_185 ||
V_6 -> V_30 == V_188 )
V_2 -> V_177 . V_197 = V_201 | V_202 ;
F_83 ( V_6 -> V_139 , & V_2 -> V_177 . V_203 ) ;
F_83 ( V_6 -> V_139 , & V_2 -> V_177 . V_204 ) ;
if ( V_6 -> V_205 ) {
if ( ( V_135 = V_6 -> V_205 ( V_6 , V_6 -> V_206 , V_6 -> V_139 ) ) < 0 )
return V_135 ;
}
V_135 = F_52 ( V_6 , V_156 ) ;
if ( V_135 < 0 ) {
if ( V_6 -> V_207 )
V_6 -> V_207 ( V_6 , V_6 -> V_206 , V_6 -> V_139 ) ;
F_84 ( V_2 -> V_208 , V_2 -> V_209 ) ;
return V_135 ;
}
V_6 -> V_53 = V_42 ;
F_85 ( V_42 ) ;
V_6 -> V_210 ( V_2 ) ;
return 0 ;
}
static int F_86 ( struct V_41 * V_42 )
{
struct V_5 * V_6 = F_32 ( V_42 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
int V_135 ;
V_2 -> V_177 = V_211 ;
if ( V_6 -> V_30 & V_84 )
V_2 -> V_177 . V_197 &= ~ ( V_198 |
V_199 ) ;
if ( V_6 -> V_30 == V_185 ||
V_6 -> V_30 == V_188 ||
V_6 -> V_30 == V_192 )
V_2 -> V_177 . V_197 = V_201 |
V_202 ;
F_83 ( V_6 -> V_148 , & V_2 -> V_177 . V_203 ) ;
F_83 ( V_6 -> V_148 , & V_2 -> V_177 . V_204 ) ;
if ( V_6 -> V_205 ) {
if ( ( V_135 = V_6 -> V_205 ( V_6 , V_6 -> V_206 , V_6 -> V_148 ) ) < 0 )
return V_135 ;
}
V_135 = F_52 ( V_6 , V_157 ) ;
if ( V_135 < 0 ) {
if ( V_6 -> V_207 )
V_6 -> V_207 ( V_6 , V_6 -> V_206 , V_6 -> V_148 ) ;
F_84 ( V_2 -> V_208 , V_2 -> V_209 ) ;
return V_135 ;
}
V_6 -> V_55 = V_42 ;
F_85 ( V_42 ) ;
V_6 -> V_210 ( V_2 ) ;
return 0 ;
}
static int F_87 ( struct V_41 * V_42 )
{
struct V_5 * V_6 = F_32 ( V_42 ) ;
V_6 -> V_53 = NULL ;
F_53 ( V_6 , V_156 ) ;
return 0 ;
}
static int F_88 ( struct V_41 * V_42 )
{
struct V_5 * V_6 = F_32 ( V_42 ) ;
V_6 -> V_55 = NULL ;
F_53 ( V_6 , V_157 ) ;
return 0 ;
}
static void F_89 ( struct V_5 * V_6 , int V_212 )
{
int V_178 ;
if ( ! V_6 -> V_213 )
return;
F_4 ( 0x1c , V_214 ) ;
V_178 = F_6 ( V_215 ) ;
if ( V_212 )
V_178 |= V_216 ;
else
V_178 &= ~ V_216 ;
F_4 ( V_178 , V_215 ) ;
}
static void F_90 ( struct V_5 * V_6 )
{
int V_13 ;
unsigned long V_22 ;
F_91 ( V_6 -> V_217 ) ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
for ( V_13 = 0 ; V_13 < 32 ; V_13 ++ )
V_6 -> V_18 [ V_13 ] = F_16 ( V_6 , V_13 ) ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
if ( V_6 -> V_213 )
F_89 ( V_6 , 0 ) ;
}
static void F_92 ( struct V_5 * V_6 )
{
int V_13 ;
unsigned long V_22 ;
if ( V_6 -> V_213 )
F_89 ( V_6 , 1 ) ;
F_22 ( V_6 ) ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
for ( V_13 = 0 ; V_13 < 32 ; V_13 ++ ) {
switch ( V_13 ) {
case V_171 :
break;
default:
F_12 ( V_6 , V_13 , V_6 -> V_18 [ V_13 ] ) ;
break;
}
}
if ( V_6 -> V_30 == V_106 )
F_12 ( V_6 , V_99 ,
V_6 -> V_18 [ V_99 ] ) ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
#if 1
F_25 ( V_6 ) ;
#else
F_21 ( V_6 ) ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
V_6 -> V_15 &= ~ V_24 ;
V_10 = F_5 ( V_6 , F_8 ( V_11 ) ) ;
F_3 ( V_6 , F_8 ( V_11 ) , V_6 -> V_15 | ( V_10 & 0x1f ) ) ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
if ( V_10 == 0x80 )
F_14 ( V_34 L_36
L_37 , V_6 -> V_9 ) ;
if ( ( V_10 & V_24 ) == 0 ||
! ( V_6 -> V_30 & ( V_27 | V_28 ) ) ) {
return;
}
F_21 ( V_6 ) ;
#endif
}
static int F_93 ( struct V_5 * V_6 )
{
F_94 ( V_6 -> V_218 ) ;
F_94 ( V_6 -> V_219 ) ;
if ( V_6 -> V_153 >= 0 ) {
F_95 ( V_6 -> V_153 ) ;
if ( ! ( V_6 -> V_220 & V_221 ) )
F_96 ( V_6 -> V_153 , ( void * ) V_6 ) ;
}
if ( ! ( V_6 -> V_220 & V_222 ) && V_6 -> V_139 >= 0 ) {
F_97 ( V_6 -> V_139 ) ;
F_98 ( V_6 -> V_139 ) ;
}
if ( ! ( V_6 -> V_220 & V_223 ) &&
V_6 -> V_148 >= 0 && V_6 -> V_148 != V_6 -> V_139 ) {
F_97 ( V_6 -> V_148 ) ;
F_98 ( V_6 -> V_148 ) ;
}
if ( V_6 -> V_109 )
F_99 ( V_6 -> V_224 , V_6 -> V_109 ) ;
F_100 ( V_6 ) ;
return 0 ;
}
static int F_101 ( struct V_225 * V_226 )
{
struct V_5 * V_6 = V_226 -> V_227 ;
return F_93 ( V_6 ) ;
}
const char * F_102 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_30 ) {
case V_179 :
return L_38 ;
case V_98 :
return L_39 ;
case V_180 :
return L_40 ;
case V_181 :
return L_41 ;
case V_185 :
return L_42 ;
case V_182 :
return L_43 ;
case V_183 :
return L_44 ;
case V_186 :
return L_45 ;
case V_187 :
return L_46 ;
case V_188 :
return L_47 ;
case V_88 :
return L_48 ;
case V_106 :
return V_6 -> V_224 -> V_228 ;
case V_101 :
return L_49 ;
case V_192 :
return L_50 ;
case V_166 :
return L_51 ;
case V_29 :
return L_52 ;
case V_173 :
return L_53 ;
case V_172 :
return L_54 ;
default:
return L_55 ;
}
}
static int F_103 ( struct V_229 * V_224 ,
unsigned short V_30 ,
unsigned short V_220 ,
struct V_5 * * V_230 )
{
struct V_5 * V_6 ;
* V_230 = NULL ;
V_6 = F_104 ( sizeof( * V_6 ) , V_231 ) ;
if ( V_6 == NULL )
return - V_232 ;
V_6 -> V_30 = V_30 ;
V_6 -> V_220 = V_220 ;
F_105 ( & V_6 -> V_23 ) ;
F_106 ( & V_6 -> V_97 ) ;
F_106 ( & V_6 -> V_122 ) ;
V_6 -> V_224 = V_224 ;
V_6 -> V_210 = F_1 ;
V_6 -> V_136 = F_41 ;
V_6 -> V_146 = F_45 ;
if ( V_6 -> V_30 == V_192 )
memcpy ( & V_6 -> V_18 , & V_233 ,
sizeof( V_233 ) ) ;
else
memcpy ( & V_6 -> V_18 , & V_234 ,
sizeof( V_234 ) ) ;
if ( V_6 -> V_30 & V_84 ) {
V_6 -> V_18 [ V_130 ] = 0 ;
V_6 -> V_18 [ V_32 ] = 0 ;
}
* V_230 = V_6 ;
return 0 ;
}
int F_107 ( struct V_229 * V_224 ,
unsigned long V_9 ,
unsigned long V_235 ,
int V_153 , int V_139 , int V_148 ,
unsigned short V_30 ,
unsigned short V_220 ,
struct V_5 * * V_230 )
{
static struct V_236 V_237 = {
. V_238 = F_101 ,
} ;
struct V_5 * V_6 ;
int V_135 ;
V_135 = F_103 ( V_224 , V_30 , V_220 , & V_6 ) ;
if ( V_135 < 0 )
return V_135 ;
V_6 -> V_153 = - 1 ;
V_6 -> V_139 = - 1 ;
V_6 -> V_148 = - 1 ;
V_6 -> V_218 = F_108 ( V_9 , 4 , L_56 ) ;
if ( ! V_6 -> V_218 ) {
F_14 ( V_34 L_57 , V_9 ) ;
F_93 ( V_6 ) ;
return - V_239 ;
}
V_6 -> V_9 = V_9 ;
if ( ( long ) V_235 >= 0 ) {
V_6 -> V_219 = F_108 ( V_235 , 8 , L_58 ) ;
if ( ! V_6 -> V_219 ) {
F_14 ( V_34
L_59 , V_235 ) ;
F_93 ( V_6 ) ;
return - V_162 ;
}
}
V_6 -> V_235 = V_235 ;
if ( ! ( V_220 & V_221 ) )
if ( F_109 ( V_153 , F_71 , 0 ,
L_56 , ( void * ) V_6 ) ) {
F_14 ( V_34 L_60 , V_153 ) ;
F_93 ( V_6 ) ;
return - V_239 ;
}
V_6 -> V_153 = V_153 ;
if ( ! ( V_220 & V_222 ) && F_110 ( V_139 , L_61 ) ) {
F_14 ( V_34 L_62 , V_139 ) ;
F_93 ( V_6 ) ;
return - V_239 ;
}
V_6 -> V_139 = V_139 ;
if ( ! ( V_220 & V_223 ) && V_139 != V_148 &&
V_148 >= 0 && F_110 ( V_148 , L_63 ) ) {
F_14 ( V_34 L_64 , V_148 ) ;
F_93 ( V_6 ) ;
return - V_239 ;
}
if ( V_139 == V_148 || V_148 < 0 ) {
V_6 -> V_104 = 1 ;
V_6 -> V_148 = V_6 -> V_139 ;
} else
V_6 -> V_148 = V_148 ;
if ( V_30 == V_240 ) {
V_6 -> V_213 = 1 ;
V_6 -> V_30 = V_168 ;
F_89 ( V_6 , 1 ) ;
}
if ( F_80 ( V_6 ) < 0 ) {
F_93 ( V_6 ) ;
return - V_162 ;
}
F_50 ( V_6 ) ;
#if 0
if (chip->hardware & WSS_HW_CS4232_MASK) {
if (chip->res_cport == NULL)
snd_printk(KERN_ERR "CS4232 control port features are "
"not accessible\n");
}
#endif
V_135 = F_111 ( V_224 , V_241 , V_6 , & V_237 ) ;
if ( V_135 < 0 ) {
F_93 ( V_6 ) ;
return V_135 ;
}
#ifdef F_112
V_6 -> V_242 = F_90 ;
V_6 -> V_243 = F_92 ;
#endif
* V_230 = V_6 ;
return 0 ;
}
int F_113 ( struct V_5 * V_6 , int V_226 , struct V_244 * * V_245 )
{
struct V_244 * V_217 ;
int V_135 ;
V_135 = F_114 ( V_6 -> V_224 , L_56 , V_226 , 1 , 1 , & V_217 ) ;
if ( V_135 < 0 )
return V_135 ;
F_115 ( V_217 , V_246 , & V_247 ) ;
F_115 ( V_217 , V_248 , & V_249 ) ;
V_217 -> V_250 = V_6 ;
V_217 -> V_251 = 0 ;
if ( V_6 -> V_104 )
V_217 -> V_251 |= V_252 ;
if ( V_6 -> V_30 != V_88 )
V_217 -> V_251 |= V_253 ;
strcpy ( V_217 -> V_254 , F_102 ( V_6 ) ) ;
F_116 ( V_217 , V_255 ,
F_117 () ,
64 * 1024 , V_6 -> V_139 > 3 || V_6 -> V_148 > 3 ? 128 * 1024 : 64 * 1024 ) ;
V_6 -> V_217 = V_217 ;
if ( V_245 )
* V_245 = V_217 ;
return 0 ;
}
static void F_118 ( struct V_108 * V_109 )
{
struct V_5 * V_6 = V_109 -> V_250 ;
V_6 -> V_109 = NULL ;
}
int F_119 ( struct V_5 * V_6 , int V_226 , struct V_108 * * V_256 )
{
struct V_108 * V_109 ;
struct V_257 V_258 ;
int V_135 ;
V_258 . V_259 = V_260 ;
V_258 . V_261 = V_262 ;
V_258 . V_224 = V_6 -> V_224 -> V_263 ;
V_258 . V_226 = V_226 ;
V_258 . V_264 = 0 ;
if ( ( V_135 = F_120 ( V_6 -> V_224 , L_38 , & V_258 , & V_109 ) ) < 0 )
return V_135 ;
strcpy ( V_109 -> V_254 , F_102 ( V_6 ) ) ;
V_109 -> V_250 = V_6 ;
V_109 -> V_265 = F_118 ;
V_109 -> V_177 = V_266 ;
V_6 -> V_109 = V_109 ;
if ( V_256 )
* V_256 = V_109 ;
return 0 ;
}
static int F_121 ( struct V_267 * V_268 ,
struct V_269 * V_270 )
{
static char * V_271 [ 4 ] = {
L_65 , L_66 , L_67 , L_68
} ;
static char * V_272 [ 4 ] = {
L_65 , L_69 , L_67 , L_68
} ;
static char * V_273 [ 4 ] = {
L_65 , L_70 , L_67 , L_68
} ;
char * * V_274 = V_271 ;
struct V_5 * V_6 = F_122 ( V_268 ) ;
if ( F_123 ( ! V_6 -> V_224 ) )
return - V_52 ;
V_270 -> type = V_275 ;
V_270 -> V_137 = 2 ;
V_270 -> V_14 . V_276 . V_277 = 4 ;
if ( V_270 -> V_14 . V_276 . V_278 > 3 )
V_270 -> V_14 . V_276 . V_278 = 3 ;
if ( ! strcmp ( V_6 -> V_224 -> V_279 , L_71 ) )
V_274 = V_273 ;
switch ( V_6 -> V_30 ) {
case V_88 :
V_274 = V_273 ;
break;
case V_192 :
case V_106 :
V_274 = V_272 ;
break;
}
strcpy ( V_270 -> V_14 . V_276 . V_254 , V_274 [ V_270 -> V_14 . V_276 . V_278 ] ) ;
return 0 ;
}
static int F_124 ( struct V_267 * V_268 ,
struct V_280 * V_281 )
{
struct V_5 * V_6 = F_122 ( V_268 ) ;
unsigned long V_22 ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
V_281 -> V_14 . V_276 . V_278 [ 0 ] = ( V_6 -> V_18 [ V_75 ] & V_282 ) >> 6 ;
V_281 -> V_14 . V_276 . V_278 [ 1 ] = ( V_6 -> V_18 [ V_76 ] & V_282 ) >> 6 ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
return 0 ;
}
static int F_125 ( struct V_267 * V_268 ,
struct V_280 * V_281 )
{
struct V_5 * V_6 = F_122 ( V_268 ) ;
unsigned long V_22 ;
unsigned short V_283 , V_284 ;
int V_285 ;
if ( V_281 -> V_14 . V_276 . V_278 [ 0 ] > 3 ||
V_281 -> V_14 . V_276 . V_278 [ 1 ] > 3 )
return - V_52 ;
V_283 = V_281 -> V_14 . V_276 . V_278 [ 0 ] << 6 ;
V_284 = V_281 -> V_14 . V_276 . V_278 [ 1 ] << 6 ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
V_283 = ( V_6 -> V_18 [ V_75 ] & ~ V_282 ) | V_283 ;
V_284 = ( V_6 -> V_18 [ V_76 ] & ~ V_282 ) | V_284 ;
V_285 = V_283 != V_6 -> V_18 [ V_75 ] ||
V_284 != V_6 -> V_18 [ V_76 ] ;
F_12 ( V_6 , V_75 , V_283 ) ;
F_12 ( V_6 , V_76 , V_284 ) ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
return V_285 ;
}
int F_126 ( struct V_267 * V_268 ,
struct V_269 * V_270 )
{
int V_286 = ( V_268 -> V_287 >> 16 ) & 0xff ;
V_270 -> type = V_286 == 1 ? V_288 : V_289 ;
V_270 -> V_137 = 1 ;
V_270 -> V_14 . integer . V_290 = 0 ;
V_270 -> V_14 . integer . V_291 = V_286 ;
return 0 ;
}
int F_127 ( struct V_267 * V_268 ,
struct V_280 * V_281 )
{
struct V_5 * V_6 = F_122 ( V_268 ) ;
unsigned long V_22 ;
int V_13 = V_268 -> V_287 & 0xff ;
int V_292 = ( V_268 -> V_287 >> 8 ) & 0xff ;
int V_286 = ( V_268 -> V_287 >> 16 ) & 0xff ;
int V_293 = ( V_268 -> V_287 >> 24 ) & 0xff ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
V_281 -> V_14 . integer . V_14 [ 0 ] = ( V_6 -> V_18 [ V_13 ] >> V_292 ) & V_286 ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
if ( V_293 )
V_281 -> V_14 . integer . V_14 [ 0 ] = V_286 - V_281 -> V_14 . integer . V_14 [ 0 ] ;
return 0 ;
}
int F_128 ( struct V_267 * V_268 ,
struct V_280 * V_281 )
{
struct V_5 * V_6 = F_122 ( V_268 ) ;
unsigned long V_22 ;
int V_13 = V_268 -> V_287 & 0xff ;
int V_292 = ( V_268 -> V_287 >> 8 ) & 0xff ;
int V_286 = ( V_268 -> V_287 >> 16 ) & 0xff ;
int V_293 = ( V_268 -> V_287 >> 24 ) & 0xff ;
int V_285 ;
unsigned short V_8 ;
V_8 = ( V_281 -> V_14 . integer . V_14 [ 0 ] & V_286 ) ;
if ( V_293 )
V_8 = V_286 - V_8 ;
V_8 <<= V_292 ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
V_8 = ( V_6 -> V_18 [ V_13 ] & ~ ( V_286 << V_292 ) ) | V_8 ;
V_285 = V_8 != V_6 -> V_18 [ V_13 ] ;
F_12 ( V_6 , V_13 , V_8 ) ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
return V_285 ;
}
int F_129 ( struct V_267 * V_268 ,
struct V_269 * V_270 )
{
int V_286 = ( V_268 -> V_287 >> 24 ) & 0xff ;
V_270 -> type = V_286 == 1 ? V_288 : V_289 ;
V_270 -> V_137 = 2 ;
V_270 -> V_14 . integer . V_290 = 0 ;
V_270 -> V_14 . integer . V_291 = V_286 ;
return 0 ;
}
int F_130 ( struct V_267 * V_268 ,
struct V_280 * V_281 )
{
struct V_5 * V_6 = F_122 ( V_268 ) ;
unsigned long V_22 ;
int V_294 = V_268 -> V_287 & 0xff ;
int V_295 = ( V_268 -> V_287 >> 8 ) & 0xff ;
int V_296 = ( V_268 -> V_287 >> 16 ) & 0x07 ;
int V_297 = ( V_268 -> V_287 >> 19 ) & 0x07 ;
int V_286 = ( V_268 -> V_287 >> 24 ) & 0xff ;
int V_293 = ( V_268 -> V_287 >> 22 ) & 1 ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
V_281 -> V_14 . integer . V_14 [ 0 ] = ( V_6 -> V_18 [ V_294 ] >> V_296 ) & V_286 ;
V_281 -> V_14 . integer . V_14 [ 1 ] = ( V_6 -> V_18 [ V_295 ] >> V_297 ) & V_286 ;
F_24 ( & V_6 -> V_23 , V_22 ) ;
if ( V_293 ) {
V_281 -> V_14 . integer . V_14 [ 0 ] = V_286 - V_281 -> V_14 . integer . V_14 [ 0 ] ;
V_281 -> V_14 . integer . V_14 [ 1 ] = V_286 - V_281 -> V_14 . integer . V_14 [ 1 ] ;
}
return 0 ;
}
int F_131 ( struct V_267 * V_268 ,
struct V_280 * V_281 )
{
struct V_5 * V_6 = F_122 ( V_268 ) ;
unsigned long V_22 ;
int V_294 = V_268 -> V_287 & 0xff ;
int V_295 = ( V_268 -> V_287 >> 8 ) & 0xff ;
int V_296 = ( V_268 -> V_287 >> 16 ) & 0x07 ;
int V_297 = ( V_268 -> V_287 >> 19 ) & 0x07 ;
int V_286 = ( V_268 -> V_287 >> 24 ) & 0xff ;
int V_293 = ( V_268 -> V_287 >> 22 ) & 1 ;
int V_285 ;
unsigned short V_298 , V_299 ;
V_298 = V_281 -> V_14 . integer . V_14 [ 0 ] & V_286 ;
V_299 = V_281 -> V_14 . integer . V_14 [ 1 ] & V_286 ;
if ( V_293 ) {
V_298 = V_286 - V_298 ;
V_299 = V_286 - V_299 ;
}
V_298 <<= V_296 ;
V_299 <<= V_297 ;
F_23 ( & V_6 -> V_23 , V_22 ) ;
if ( V_294 != V_295 ) {
V_298 = ( V_6 -> V_18 [ V_294 ] & ~ ( V_286 << V_296 ) ) | V_298 ;
V_299 = ( V_6 -> V_18 [ V_295 ] & ~ ( V_286 << V_297 ) ) | V_299 ;
V_285 = V_298 != V_6 -> V_18 [ V_294 ] ||
V_299 != V_6 -> V_18 [ V_295 ] ;
F_12 ( V_6 , V_294 , V_298 ) ;
F_12 ( V_6 , V_295 , V_299 ) ;
} else {
V_286 = ( V_286 << V_296 ) | ( V_286 << V_297 ) ;
V_298 = ( V_6 -> V_18 [ V_294 ] & ~ V_286 ) | V_298 | V_299 ;
V_285 = V_298 != V_6 -> V_18 [ V_294 ] ;
F_12 ( V_6 , V_294 , V_298 ) ;
}
F_24 ( & V_6 -> V_23 , V_22 ) ;
return V_285 ;
}
int F_132 ( struct V_5 * V_6 )
{
struct V_229 * V_224 ;
unsigned int V_300 ;
int V_135 ;
int V_137 = F_38 ( V_301 ) ;
if ( F_123 ( ! V_6 || ! V_6 -> V_217 ) )
return - V_52 ;
V_224 = V_6 -> V_224 ;
strcpy ( V_224 -> V_302 , V_6 -> V_217 -> V_254 ) ;
if ( V_6 -> V_30 & V_84 )
V_137 = 11 ;
else if ( V_6 -> V_30 == V_192 )
V_137 = 9 ;
for ( V_300 = 0 ; V_300 < V_137 ; V_300 ++ ) {
V_135 = F_133 ( V_224 ,
F_134 ( & V_301 [ V_300 ] ,
V_6 ) ) ;
if ( V_135 < 0 )
return V_135 ;
}
return 0 ;
}
const struct V_303 * F_135 ( int V_304 )
{
return V_304 == V_246 ?
& V_247 : & V_249 ;
}
static int T_5 F_136 ( void )
{
return 0 ;
}
static void T_6 F_137 ( void )
{
}
