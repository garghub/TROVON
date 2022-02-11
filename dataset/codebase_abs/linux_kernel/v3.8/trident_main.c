static unsigned short F_1 ( struct V_1 * V_2 , unsigned short V_3 )
{
unsigned int V_4 = 0 , V_5 ;
unsigned short V_6 = 0xffff ;
unsigned long V_7 ;
struct V_8 * V_9 = V_2 -> V_10 ;
F_2 ( & V_9 -> V_11 , V_7 ) ;
if ( V_9 -> V_12 == V_13 ) {
V_4 = ( V_14 | ( V_3 & 0x000000ff ) ) ;
F_3 ( V_4 , F_4 ( V_9 , V_15 ) ) ;
do {
V_4 = F_5 ( F_4 ( V_9 , V_15 ) ) ;
if ( ( V_4 & V_14 ) == 0 )
break;
} while ( -- V_6 );
} else if ( V_9 -> V_12 == V_16 ) {
V_4 = ( V_17 | ( V_3 & 0x000000ff ) ) ;
V_5 = V_2 -> V_18 == 0 ? V_19 : V_20 ;
F_3 ( V_4 , F_4 ( V_9 , V_5 ) ) ;
do {
V_4 = F_5 ( F_4 ( V_9 , V_5 ) ) ;
if ( ( V_4 & 0x00000C00 ) == 0 )
break;
} while ( -- V_6 );
} else if ( V_9 -> V_12 == V_21 ) {
V_4 = V_22 | V_23 | ( V_3 & 0x000000ff ) ;
if ( V_2 -> V_18 == 1 )
V_4 |= V_24 ;
F_3 ( V_4 , F_4 ( V_9 , V_25 ) ) ;
do {
V_4 = F_5 ( F_4 ( V_9 , V_25 ) ) ;
if ( ( V_4 & ( V_22 ) ) == 0 )
break;
} while ( -- V_6 );
}
if ( V_6 == 0 && ! V_9 -> V_26 ) {
F_6 ( V_27 L_1 ,
V_3 , V_4 ) ;
V_4 = 0 ;
}
F_7 ( & V_9 -> V_11 , V_7 ) ;
return ( ( unsigned short ) ( V_4 >> 16 ) ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned short V_3 ,
unsigned short V_28 )
{
unsigned int V_29 , V_4 ;
unsigned short V_6 = 0xffff ;
unsigned long V_7 ;
struct V_8 * V_9 = V_2 -> V_10 ;
V_4 = ( ( unsigned long ) V_28 ) << 16 ;
F_2 ( & V_9 -> V_11 , V_7 ) ;
if ( V_9 -> V_12 == V_13 ) {
V_29 = V_30 ;
do {
if ( ( F_9 ( F_4 ( V_9 , V_29 ) ) & V_31 ) == 0 )
break;
} while ( -- V_6 );
V_4 |= ( V_31 | ( V_3 & 0x000000ff ) ) ;
} else if ( V_9 -> V_12 == V_16 ) {
V_29 = V_32 ;
do {
if ( ( F_9 ( F_4 ( V_9 , V_29 ) ) & V_33 ) == 0 )
break;
} while ( -- V_6 );
V_4 |= ( V_33 | ( V_2 -> V_18 << 8 ) | ( V_3 & 0x000000ff ) ) ;
} else if ( V_9 -> V_12 == V_21 ) {
V_29 = V_34 ;
do {
if ( ( F_9 ( F_4 ( V_9 , V_29 ) ) & ( V_35 ) ) == 0 )
break;
} while ( -- V_6 );
V_4 |= V_35 | V_23 | ( V_3 & 0x000000ff ) ;
if ( V_2 -> V_18 == 1 )
V_4 |= V_24 ;
} else {
V_29 = 0 ;
V_6 = 0 ;
}
if ( V_6 == 0 ) {
F_7 ( & V_9 -> V_11 , V_7 ) ;
return;
}
F_3 ( V_4 , F_4 ( V_9 , V_29 ) ) ;
F_7 ( & V_9 -> V_11 , V_7 ) ;
}
static void F_10 ( struct V_8 * V_9 )
{
unsigned int V_36 ;
V_36 = F_5 ( F_4 ( V_9 , V_37 ) ) ;
V_36 |= V_38 ;
V_36 |= V_39 ;
if ( V_9 -> V_12 == V_21 )
V_36 |= V_40 ;
F_3 ( V_36 , F_4 ( V_9 , V_37 ) ) ;
}
static void F_11 ( struct V_8 * V_9 )
{
unsigned int V_41 ;
V_41 = F_5 ( F_4 ( V_9 , V_37 ) ) ;
V_41 &= ~ V_38 ;
V_41 &= ~ V_39 ;
F_3 ( V_41 , F_4 ( V_9 , V_37 ) ) ;
}
void F_12 ( struct V_8 * V_9 , unsigned int V_42 )
{
unsigned int V_43 = 1 << ( V_42 & 0x1f ) ;
unsigned int V_3 = ( V_42 & 0x20 ) ? V_44 : V_45 ;
F_3 ( V_43 , F_4 ( V_9 , V_3 ) ) ;
}
void F_13 ( struct V_8 * V_9 , unsigned int V_42 )
{
unsigned int V_43 = 1 << ( V_42 & 0x1f ) ;
unsigned int V_3 = ( V_42 & 0x20 ) ? V_46 : V_47 ;
F_3 ( V_43 , F_4 ( V_9 , V_3 ) ) ;
}
static int F_14 ( struct V_8 * V_9 )
{
int V_48 ;
if ( V_9 -> V_49 >= V_9 -> V_50 )
return - 1 ;
for ( V_48 = 31 ; V_48 >= 0 ; V_48 -- ) {
if ( ! ( V_9 -> V_51 [ V_52 ] & ( 1 << V_48 ) ) ) {
V_9 -> V_51 [ V_52 ] |= 1 << V_48 ;
V_9 -> V_49 ++ ;
return V_48 + 32 ;
}
}
return - 1 ;
}
static void F_15 ( struct V_8 * V_9 , int V_53 )
{
if ( V_53 < 32 || V_53 > 63 )
return;
V_53 &= 0x1f ;
if ( V_9 -> V_51 [ V_52 ] & ( 1 << V_53 ) ) {
V_9 -> V_51 [ V_52 ] &= ~ ( 1 << V_53 ) ;
V_9 -> V_49 -- ;
}
}
static int F_16 ( struct V_8 * V_9 )
{
int V_48 ;
for ( V_48 = 31 ; V_48 >= 0 ; V_48 -- ) {
if ( ! ( V_9 -> V_51 [ V_54 ] & ( 1 << V_48 ) ) ) {
V_9 -> V_51 [ V_54 ] |= 1 << V_48 ;
V_9 -> V_55 . V_56 ++ ;
return V_48 ;
}
}
return - 1 ;
}
static void F_17 ( struct V_8 * V_9 , int V_53 )
{
if ( V_53 < 0 || V_53 > 31 )
return;
V_53 &= 0x1f ;
if ( V_9 -> V_51 [ V_54 ] & ( 1 << V_53 ) ) {
V_9 -> V_51 [ V_54 ] &= ~ ( 1 << V_53 ) ;
V_9 -> V_55 . V_56 -- ;
}
}
void F_18 ( struct V_8 * V_9 ,
struct V_57 * V_42 )
{
unsigned int V_58 ;
unsigned int V_59 [ 5 ] ;
V_59 [ 1 ] = V_42 -> V_60 ;
V_59 [ 4 ] = ( V_42 -> V_61 << 31 ) |
( ( V_42 -> V_62 & 0x0000007f ) << 24 ) |
( ( V_42 -> V_63 & 0x0000000f ) << 12 ) ;
V_58 = ( ( V_42 -> V_64 & 3 ) << 14 ) |
( ( V_42 -> V_65 & 0x7f ) << 7 ) |
( V_42 -> V_66 & 0x7f ) ;
switch ( V_9 -> V_12 ) {
case V_21 :
V_59 [ 4 ] |= V_42 -> V_67 > 31 ?
( V_42 -> V_68 & 0x000003ff ) :
( ( V_42 -> V_68 & 0x00003fc ) << ( 16 - 2 ) ) |
( V_42 -> V_69 & 0x00000fff ) ;
V_59 [ 0 ] = ( V_42 -> V_70 << 16 ) | ( ( V_42 -> V_71 & 0x00000fff ) << 4 ) |
( V_42 -> V_72 & 0x0000000f ) ;
V_59 [ 2 ] = ( V_42 -> V_73 << 16 ) | ( V_42 -> V_74 & 0x0ffff ) ;
V_59 [ 3 ] = ( V_42 -> V_75 << 16 ) | V_58 ;
break;
case V_13 :
V_59 [ 4 ] |= ( ( V_42 -> V_68 & 0x000003fc ) << ( 16 - 2 ) ) |
( V_42 -> V_69 & 0x00000fff ) ;
V_59 [ 0 ] = ( V_42 -> V_70 << 16 ) | ( ( V_42 -> V_71 & 0x00000fff ) << 4 ) |
( V_42 -> V_72 & 0x0000000f ) ;
V_59 [ 2 ] = ( V_42 -> V_73 << 16 ) | ( V_42 -> V_74 & 0x0ffff ) ;
V_59 [ 3 ] = V_58 ;
break;
case V_16 :
V_59 [ 4 ] |= ( ( V_42 -> V_68 & 0x000003fc ) << ( 16 - 2 ) ) |
( V_42 -> V_69 & 0x00000fff ) ;
V_59 [ 0 ] = ( V_42 -> V_74 << 24 ) | ( V_42 -> V_70 & 0x00ffffff ) ;
V_59 [ 2 ] = ( ( V_42 -> V_74 << 16 ) & 0xff000000 ) |
( V_42 -> V_73 & 0x00ffffff ) ;
V_59 [ 3 ] = ( V_42 -> V_71 << 20 ) |
( ( V_42 -> V_72 & 0x0000000f ) << 16 ) | V_58 ;
break;
default:
F_19 () ;
return;
}
F_20 ( V_42 -> V_67 , F_4 ( V_9 , V_37 ) ) ;
F_3 ( V_59 [ 0 ] , F_4 ( V_9 , V_76 + 0 ) ) ;
F_3 ( V_59 [ 1 ] , F_4 ( V_9 , V_76 + 4 ) ) ;
F_3 ( V_59 [ 2 ] , F_4 ( V_9 , V_76 + 8 ) ) ;
F_3 ( V_59 [ 3 ] , F_4 ( V_9 , V_76 + 12 ) ) ;
F_3 ( V_59 [ 4 ] , F_4 ( V_9 , V_76 + 16 ) ) ;
#if 0
printk(KERN_DEBUG "written %i channel:\n", voice->number);
printk(KERN_DEBUG " regs[0] = 0x%x/0x%x\n",
regs[0], inl(TRID_REG(trident, CH_START + 0)));
printk(KERN_DEBUG " regs[1] = 0x%x/0x%x\n",
regs[1], inl(TRID_REG(trident, CH_START + 4)));
printk(KERN_DEBUG " regs[2] = 0x%x/0x%x\n",
regs[2], inl(TRID_REG(trident, CH_START + 8)));
printk(KERN_DEBUG " regs[3] = 0x%x/0x%x\n",
regs[3], inl(TRID_REG(trident, CH_START + 12)));
printk(KERN_DEBUG " regs[4] = 0x%x/0x%x\n",
regs[4], inl(TRID_REG(trident, CH_START + 16)));
#endif
}
static void F_21 ( struct V_8 * V_9 ,
struct V_57 * V_42 ,
unsigned int V_70 )
{
V_42 -> V_70 = V_70 ;
F_20 ( V_42 -> V_67 , F_4 ( V_9 , V_37 ) ) ;
if ( V_9 -> V_12 != V_16 ) {
F_22 ( V_42 -> V_70 , F_4 ( V_9 , V_77 ) + 2 ) ;
} else {
F_3 ( ( V_42 -> V_74 << 24 ) |
( V_42 -> V_70 & 0x00ffffff ) , F_4 ( V_9 , V_78 ) ) ;
}
}
static void F_23 ( struct V_8 * V_9 ,
struct V_57 * V_42 ,
unsigned int V_73 )
{
V_42 -> V_73 = V_73 ;
F_20 ( V_42 -> V_67 , F_4 ( V_9 , V_37 ) ) ;
if ( V_9 -> V_12 != V_16 ) {
F_22 ( V_42 -> V_73 , F_4 ( V_9 , V_79 ) + 2 ) ;
} else {
F_3 ( ( ( V_42 -> V_74 << 16 ) & 0xff000000 ) | ( V_42 -> V_73 & 0x00ffffff ) ,
F_4 ( V_9 , V_80 ) ) ;
}
}
static void F_24 ( struct V_8 * V_9 ,
struct V_57 * V_42 ,
unsigned int V_68 )
{
V_42 -> V_68 = V_68 ;
F_20 ( V_42 -> V_67 , F_4 ( V_9 , V_37 ) ) ;
switch ( V_9 -> V_12 ) {
case V_13 :
case V_16 :
F_20 ( V_42 -> V_68 >> 2 , F_4 ( V_9 , V_81 + 2 ) ) ;
break;
case V_21 :
F_22 ( ( V_42 -> V_63 << 12 ) | V_42 -> V_68 ,
F_4 ( V_9 , V_81 ) ) ;
break;
}
}
static void F_25 ( struct V_8 * V_9 ,
struct V_57 * V_42 ,
unsigned int V_62 )
{
V_42 -> V_62 = V_62 ;
F_20 ( V_42 -> V_67 , F_4 ( V_9 , V_37 ) ) ;
F_20 ( ( ( V_42 -> V_61 & 0x01 ) << 7 ) | ( V_42 -> V_62 & 0x7f ) ,
F_4 ( V_9 , V_81 + 3 ) ) ;
}
static void F_26 ( struct V_8 * V_9 ,
struct V_57 * V_42 ,
unsigned int V_65 )
{
V_42 -> V_65 = V_65 ;
F_20 ( V_42 -> V_67 , F_4 ( V_9 , V_37 ) ) ;
F_22 ( ( ( V_42 -> V_64 & 0x0003 ) << 14 ) | ( ( V_42 -> V_65 & 0x007f ) << 7 ) |
( V_42 -> V_66 & 0x007f ) ,
F_4 ( V_9 , V_9 -> V_12 == V_16 ?
V_82 : V_83 ) ) ;
}
static void F_27 ( struct V_8 * V_9 ,
struct V_57 * V_42 ,
unsigned int V_66 )
{
V_42 -> V_66 = V_66 ;
F_20 ( V_42 -> V_67 , F_4 ( V_9 , V_37 ) ) ;
F_22 ( ( ( V_42 -> V_64 & 0x0003 ) << 14 ) | ( ( V_42 -> V_65 & 0x007f ) << 7 ) |
( V_42 -> V_66 & 0x007f ) ,
F_4 ( V_9 , V_9 -> V_12 == V_16 ?
V_82 : V_83 ) ) ;
}
static unsigned int F_28 ( unsigned int V_84 )
{
unsigned int V_85 ;
if ( V_84 == 44100 )
V_85 = 0xeb3 ;
else if ( V_84 == 8000 )
V_85 = 0x2ab ;
else if ( V_84 == 48000 )
V_85 = 0x1000 ;
else
V_85 = ( ( ( V_84 << 12 ) + 24000 ) / 48000 ) & 0x0000ffff ;
return V_85 ;
}
static unsigned int F_29 ( unsigned int V_84 )
{
unsigned int V_85 ;
if ( V_84 == 44100 )
V_85 = 0x116a ;
else if ( V_84 == 8000 )
V_85 = 0x6000 ;
else if ( V_84 == 48000 )
V_85 = 0x1000 ;
else
V_85 = ( ( 48000 << 12 ) / V_84 ) & 0x0000ffff ;
return V_85 ;
}
static unsigned int F_30 ( unsigned int V_84 ,
unsigned int V_86 )
{
unsigned int V_87 = ( V_84 * V_86 ) / 48000 ;
if ( V_87 < 64 )
V_87 = V_87 / 2 ;
else
V_87 -= 32 ;
return V_87 ;
}
static unsigned int F_31 ( struct V_88 * V_89 )
{
unsigned int V_63 ;
struct V_90 * V_91 = V_89 -> V_91 ;
V_63 = 0x00000001 ;
if ( F_32 ( V_91 -> V_92 ) == 16 )
V_63 |= 0x00000008 ;
if ( F_33 ( V_91 -> V_92 ) )
V_63 |= 0x00000002 ;
if ( V_91 -> V_93 > 1 )
V_63 |= 0x00000004 ;
return V_63 ;
}
static int F_34 ( struct V_88 * V_89 ,
unsigned int V_94 ,
void * V_95 )
{
return F_35 ( V_89 , V_94 , V_95 ) ;
}
static int F_36 ( struct V_88 * V_89 ,
struct V_96 * V_97 )
{
struct V_8 * V_9 = F_37 ( V_89 ) ;
struct V_90 * V_91 = V_89 -> V_91 ;
struct V_57 * V_42 = V_91 -> V_10 ;
int V_98 ;
if ( ( V_98 = F_38 ( V_89 , F_39 ( V_97 ) ) ) < 0 )
return V_98 ;
if ( V_9 -> V_99 . V_100 ) {
if ( V_98 > 0 ) {
if ( V_42 -> V_101 )
F_40 ( V_9 , V_42 -> V_101 ) ;
V_42 -> V_101 = F_41 ( V_9 , V_89 ) ;
if ( V_42 -> V_101 == NULL )
return - V_102 ;
}
}
return 0 ;
}
static int F_42 ( struct V_88 * V_89 ,
struct V_96 * V_97 )
{
struct V_8 * V_9 = F_37 ( V_89 ) ;
struct V_90 * V_91 = V_89 -> V_91 ;
struct V_57 * V_42 = V_91 -> V_10 ;
struct V_57 * V_103 = V_42 -> V_104 ;
if ( F_43 ( V_97 ) / 2 != F_44 ( V_97 ) ) {
if ( V_103 == NULL ) {
V_103 = F_45 ( V_9 , V_105 , 0 , 0 ) ;
if ( V_103 == NULL )
return - V_102 ;
V_42 -> V_104 = V_103 ;
V_103 -> V_89 = V_89 ;
}
} else {
if ( V_103 != NULL ) {
F_46 ( V_9 , V_103 ) ;
V_42 -> V_104 = V_103 = NULL ;
}
}
return 0 ;
}
static int F_47 ( struct V_88 * V_89 ,
struct V_96 * V_97 )
{
int V_98 ;
V_98 = F_36 ( V_89 , V_97 ) ;
if ( V_98 >= 0 )
V_98 = F_42 ( V_89 , V_97 ) ;
return V_98 ;
}
static int F_48 ( struct V_88 * V_89 )
{
struct V_8 * V_9 = F_37 ( V_89 ) ;
struct V_90 * V_91 = V_89 -> V_91 ;
struct V_57 * V_42 = V_91 -> V_10 ;
struct V_57 * V_103 = V_42 ? V_42 -> V_104 : NULL ;
if ( V_9 -> V_99 . V_100 ) {
if ( V_42 && V_42 -> V_101 ) {
F_40 ( V_9 , V_42 -> V_101 ) ;
V_42 -> V_101 = NULL ;
}
}
F_49 ( V_89 ) ;
if ( V_103 != NULL ) {
F_46 ( V_9 , V_103 ) ;
V_42 -> V_104 = NULL ;
}
return 0 ;
}
static int F_50 ( struct V_88 * V_89 )
{
struct V_8 * V_9 = F_37 ( V_89 ) ;
struct V_90 * V_91 = V_89 -> V_91 ;
struct V_57 * V_42 = V_91 -> V_10 ;
struct V_57 * V_103 = V_42 -> V_104 ;
struct V_106 * V_107 = & V_9 -> V_108 [ V_89 -> V_67 ] ;
F_51 ( & V_9 -> V_11 ) ;
V_42 -> V_74 = F_28 ( V_91 -> V_84 ) ;
V_42 -> V_109 = F_30 ( V_91 -> V_84 , V_91 -> V_86 ) ;
if ( V_42 -> V_101 )
V_42 -> V_60 = V_42 -> V_101 -> V_110 ;
else
V_42 -> V_60 = V_91 -> V_111 ;
V_42 -> V_70 = 0 ;
V_42 -> V_73 = V_91 -> V_112 - 1 ;
V_42 -> V_63 = F_31 ( V_89 ) ;
V_42 -> V_64 = 3 ;
V_42 -> V_61 = 1 ;
V_42 -> V_69 = 0 ;
V_42 -> V_71 = 0 ;
V_42 -> V_72 = 0 ;
V_42 -> V_68 = V_107 -> V_113 ;
V_42 -> V_65 = V_107 -> V_114 ;
V_42 -> V_66 = V_107 -> V_115 ;
V_42 -> V_62 = V_107 -> V_116 ;
V_42 -> V_75 = 0 ;
#if 0
voice->Attribute = (1<<(30-16))|(2<<(26-16))|
(0<<(24-16))|(0x1f<<(19-16));
#else
V_42 -> V_75 = 0 ;
#endif
F_18 ( V_9 , V_42 ) ;
if ( V_103 != NULL ) {
V_103 -> V_74 = V_42 -> V_74 ;
V_103 -> V_109 = V_42 -> V_109 ;
V_103 -> V_60 = V_42 -> V_60 ;
V_103 -> V_70 = 0 ;
V_103 -> V_73 = ( V_91 -> V_86 * 2 ) + 4 - 1 ;
V_103 -> V_63 = V_42 -> V_63 ;
V_103 -> V_64 = 3 ;
V_103 -> V_61 = V_9 -> V_12 == V_21 ? 0 : 1 ;
V_103 -> V_69 = 0 ;
V_103 -> V_71 = 0 ;
V_103 -> V_72 = 0 ;
V_103 -> V_68 = 0x3ff ;
V_103 -> V_65 = V_103 -> V_66 = 0x7f ;
V_103 -> V_62 = 0x7f ;
#if 0
evoice->Attribute = (1<<(30-16))|(2<<(26-16))|
(0<<(24-16))|(0x1f<<(19-16));
#else
V_103 -> V_75 = 0 ;
#endif
F_18 ( V_9 , V_103 ) ;
V_103 -> V_117 = 1 ;
V_103 -> V_118 = V_91 -> V_86 ;
V_103 -> V_73 = ( V_91 -> V_86 * 2 ) - 1 ;
}
F_52 ( & V_9 -> V_11 ) ;
return 0 ;
}
static int F_53 ( struct V_88 * V_89 ,
struct V_96 * V_97 )
{
return F_36 ( V_89 , V_97 ) ;
}
static int F_54 ( struct V_88 * V_89 )
{
struct V_8 * V_9 = F_37 ( V_89 ) ;
struct V_90 * V_91 = V_89 -> V_91 ;
struct V_57 * V_42 = V_91 -> V_10 ;
unsigned int V_36 , V_119 ;
F_51 ( & V_9 -> V_11 ) ;
F_20 ( 0 , F_4 ( V_9 , V_120 ) ) ;
F_20 ( 0x54 , F_4 ( V_9 , V_121 ) ) ;
V_42 -> V_60 = V_91 -> V_111 ;
F_3 ( V_42 -> V_60 , F_4 ( V_9 , V_122 ) ) ;
if ( V_42 -> V_101 )
V_42 -> V_60 = V_42 -> V_101 -> V_110 ;
V_119 = F_55 ( V_89 ) - 1 ;
F_20 ( ( V_119 & 0x00ff0000 ) >> 16 , F_4 ( V_9 , V_123 ) ) ;
F_22 ( ( V_119 & 0x0000ffff ) , F_4 ( V_9 , V_124 ) ) ;
V_119 ++ ;
V_36 = ( ( ( unsigned int ) 48000L << 12 ) + ( V_91 -> V_84 / 2 ) ) / V_91 -> V_84 ;
F_22 ( V_36 , F_4 ( V_9 , V_125 ) ) ;
if ( F_32 ( V_91 -> V_92 ) == 16 ) {
V_36 = ( unsigned short ) ( ( V_119 >> 1 ) - 1 ) ;
} else {
V_36 = ( unsigned short ) ( V_119 - 1 ) ;
}
F_3 ( ( V_36 << 16 ) | V_36 , F_4 ( V_9 , V_126 ) ) ;
V_9 -> V_127 = 0x19 ;
if ( F_32 ( V_91 -> V_92 ) == 16 )
V_9 -> V_127 |= 0x80 ;
if ( F_33 ( V_91 -> V_92 ) )
V_9 -> V_127 |= 0x20 ;
if ( V_91 -> V_93 > 1 )
V_9 -> V_127 |= 0x40 ;
V_42 -> V_74 = F_28 ( V_91 -> V_84 ) ;
V_42 -> V_109 = F_30 ( V_91 -> V_84 , V_91 -> V_86 ) ;
V_42 -> V_128 = 1 ;
V_42 -> V_118 = V_91 -> V_86 ;
V_42 -> V_129 = V_91 -> V_112 ;
V_42 -> V_70 = 0 ;
V_42 -> V_73 = V_42 -> V_130 = ( V_91 -> V_86 * 2 ) + 6 - 1 ;
V_42 -> V_63 = F_31 ( V_89 ) ;
V_42 -> V_64 = 3 ;
V_42 -> V_65 = 0x7f ;
V_42 -> V_66 = 0x7f ;
V_42 -> V_61 = 1 ;
V_42 -> V_62 = 0x7f ;
V_42 -> V_68 = 0x3ff ;
V_42 -> V_69 = 0 ;
V_42 -> V_71 = 0 ;
V_42 -> V_72 = 0 ;
V_42 -> V_75 = 0 ;
F_18 ( V_9 , V_42 ) ;
F_52 ( & V_9 -> V_11 ) ;
return 0 ;
}
static int F_56 ( struct V_88 * V_89 ,
struct V_96 * V_97 )
{
int V_98 ;
if ( ( V_98 = F_38 ( V_89 , F_39 ( V_97 ) ) ) < 0 )
return V_98 ;
return F_42 ( V_89 , V_97 ) ;
}
static int F_57 ( struct V_88 * V_89 )
{
struct V_8 * V_9 = F_37 ( V_89 ) ;
struct V_90 * V_91 = V_89 -> V_91 ;
struct V_57 * V_42 = V_91 -> V_10 ;
struct V_57 * V_103 = V_42 ? V_42 -> V_104 : NULL ;
F_49 ( V_89 ) ;
if ( V_103 != NULL ) {
F_46 ( V_9 , V_103 ) ;
V_42 -> V_104 = NULL ;
}
return 0 ;
}
static int F_58 ( struct V_88 * V_89 )
{
struct V_8 * V_9 = F_37 ( V_89 ) ;
struct V_90 * V_91 = V_89 -> V_91 ;
struct V_57 * V_42 = V_91 -> V_10 ;
struct V_57 * V_103 = V_42 -> V_104 ;
F_51 ( & V_9 -> V_11 ) ;
V_42 -> V_60 = V_91 -> V_111 ;
V_42 -> V_74 = F_29 ( V_91 -> V_84 ) ;
V_42 -> V_109 = F_30 ( V_91 -> V_84 , V_91 -> V_86 ) ;
V_42 -> V_70 = 0 ;
V_42 -> V_73 = V_91 -> V_112 - 1 ;
V_42 -> V_63 = F_31 ( V_89 ) ;
V_42 -> V_64 = 0 ;
V_42 -> V_65 = 0 ;
V_42 -> V_66 = 0 ;
V_42 -> V_61 = 1 ;
V_42 -> V_62 = V_131 ;
V_42 -> V_68 = 0 ;
V_42 -> V_69 = 0 ;
V_42 -> V_71 = 0 ;
V_42 -> V_72 = 0 ;
V_42 -> V_75 = ( 2 << ( 30 - 16 ) ) |
( 2 << ( 26 - 16 ) ) |
( 2 << ( 24 - 16 ) ) |
( 1 << ( 23 - 16 ) ) ;
F_18 ( V_9 , V_42 ) ;
if ( V_103 != NULL ) {
V_103 -> V_74 = F_28 ( V_91 -> V_84 ) ;
V_103 -> V_109 = V_42 -> V_109 ;
V_103 -> V_60 = V_42 -> V_60 ;
V_103 -> V_70 = 0 ;
V_103 -> V_73 = ( V_91 -> V_86 * 2 ) + 20 - 1 ;
V_103 -> V_63 = V_42 -> V_63 ;
V_103 -> V_64 = 3 ;
V_103 -> V_61 = 0 ;
V_103 -> V_69 = 0 ;
V_103 -> V_71 = 0 ;
V_103 -> V_72 = 0 ;
V_103 -> V_68 = 0x3ff ;
V_103 -> V_65 = V_103 -> V_66 = 0x7f ;
V_103 -> V_62 = 0x7f ;
V_103 -> V_75 = 0 ;
F_18 ( V_9 , V_103 ) ;
V_103 -> V_117 = 1 ;
V_103 -> V_118 = V_91 -> V_86 ;
V_103 -> V_73 = ( V_91 -> V_86 * 2 ) - 1 ;
}
F_52 ( & V_9 -> V_11 ) ;
return 0 ;
}
static int F_59 ( struct V_88 * V_89 )
{
struct V_8 * V_9 = F_37 ( V_89 ) ;
struct V_90 * V_91 = V_89 -> V_91 ;
struct V_57 * V_42 = V_91 -> V_10 ;
struct V_57 * V_103 = V_42 -> V_104 ;
F_51 ( & V_9 -> V_11 ) ;
if ( V_42 -> V_101 )
V_42 -> V_60 = V_42 -> V_101 -> V_110 ;
else
V_42 -> V_60 = V_91 -> V_111 ;
V_42 -> V_73 = V_91 -> V_112 - 1 ;
V_42 -> V_74 = 0x1000 ;
V_42 -> V_109 = F_30 ( 48000 , V_91 -> V_86 ) ;
V_42 -> V_70 = 0 ;
V_42 -> V_63 = F_31 ( V_89 ) ;
V_42 -> V_64 = 3 ;
V_42 -> V_65 = 0x7f ;
V_42 -> V_66 = 0x7f ;
V_42 -> V_61 = 1 ;
V_42 -> V_62 = 0x7f ;
V_42 -> V_68 = 0x3ff ;
V_42 -> V_69 = 0 ;
V_42 -> V_71 = 0 ;
V_42 -> V_72 = 0 ;
V_42 -> V_75 = 0 ;
F_20 ( ( ( V_42 -> V_67 & 0x3f ) | 0x80 ) , F_4 ( V_9 , V_132 + V_42 -> V_133 ) ) ;
F_18 ( V_9 , V_42 ) ;
if ( V_103 != NULL ) {
V_103 -> V_74 = V_42 -> V_74 ;
V_103 -> V_109 = V_42 -> V_109 ;
V_103 -> V_60 = V_42 -> V_60 ;
V_103 -> V_70 = 0 ;
V_103 -> V_73 = ( V_91 -> V_86 * 2 ) + 4 - 1 ;
V_103 -> V_63 = V_42 -> V_63 ;
V_103 -> V_64 = 3 ;
V_103 -> V_61 = V_9 -> V_12 == V_21 ? 0 : 1 ;
V_103 -> V_69 = 0 ;
V_103 -> V_71 = 0 ;
V_103 -> V_72 = 0 ;
V_103 -> V_68 = 0x3ff ;
V_103 -> V_65 = V_103 -> V_66 = 0x7f ;
V_103 -> V_62 = 0x7f ;
V_103 -> V_75 = 0 ;
F_18 ( V_9 , V_103 ) ;
V_103 -> V_117 = 1 ;
V_103 -> V_118 = V_91 -> V_86 ;
V_103 -> V_73 = ( V_91 -> V_86 * 2 ) - 1 ;
}
F_52 ( & V_9 -> V_11 ) ;
return 0 ;
}
static int F_60 ( struct V_88 * V_89 ,
struct V_96 * V_97 )
{
struct V_8 * V_9 = F_37 ( V_89 ) ;
unsigned int V_134 = 0 , V_135 = 0 ;
int V_98 ;
V_98 = F_36 ( V_89 , V_97 ) ;
if ( V_98 < 0 )
return V_98 ;
if ( V_9 -> V_12 == V_21 ) {
V_98 = F_42 ( V_89 , V_97 ) ;
if ( V_98 < 0 )
return V_98 ;
}
F_51 ( & V_9 -> V_11 ) ;
V_134 = V_9 -> V_136 ;
if ( V_134 & V_137 )
V_9 -> V_136 &= ~ V_138 ;
else
V_9 -> V_136 &= ~ ( V_139 << 24 ) ;
if ( F_61 ( V_97 ) >= 48000 ) {
V_9 -> V_140 = 0x3c ;
V_9 -> V_136 |=
V_9 -> V_141 & V_137 ?
V_142 :
( V_143 << 24 ) ;
}
else if ( F_61 ( V_97 ) >= 44100 ) {
V_9 -> V_140 = 0x3e ;
V_9 -> V_136 |=
V_9 -> V_141 & V_137 ?
V_144 :
( V_145 << 24 ) ;
}
else {
V_9 -> V_140 = 0x3d ;
V_9 -> V_136 |=
V_9 -> V_141 & V_137 ?
V_146 :
( V_147 << 24 ) ;
}
V_135 = V_134 != V_9 -> V_136 ;
F_52 ( & V_9 -> V_11 ) ;
if ( V_135 )
F_62 ( V_9 -> V_148 , V_149 , & V_9 -> V_150 -> V_151 ) ;
return 0 ;
}
static int F_63 ( struct V_88 * V_89 )
{
struct V_8 * V_9 = F_37 ( V_89 ) ;
struct V_90 * V_91 = V_89 -> V_91 ;
struct V_57 * V_42 = V_91 -> V_10 ;
struct V_57 * V_103 = V_42 -> V_104 ;
struct V_106 * V_107 = & V_9 -> V_108 [ V_89 -> V_67 ] ;
unsigned int V_152 , V_153 ;
unsigned int V_154 ;
F_51 ( & V_9 -> V_11 ) ;
if ( V_9 -> V_12 != V_21 ) {
V_42 -> V_74 = F_28 ( V_91 -> V_84 ) ;
V_42 -> V_109 = F_30 ( V_91 -> V_84 , V_91 -> V_86 ) ;
V_153 = V_91 -> V_111 ;
if ( V_42 -> V_101 )
V_42 -> V_60 = V_42 -> V_101 -> V_110 ;
else
V_42 -> V_60 = V_153 ;
V_42 -> V_128 = 1 ;
V_42 -> V_155 = 1 ;
V_42 -> V_118 = V_91 -> V_86 ;
V_42 -> V_129 = V_91 -> V_112 ;
V_152 = V_91 -> V_112 - 1 ;
V_42 -> V_73 = V_42 -> V_130 = ( V_91 -> V_86 * 2 ) + 6 - 1 ;
V_42 -> V_63 = F_31 ( V_89 ) ;
V_42 -> V_64 = 3 ;
V_42 -> V_65 = 0x7f ;
V_42 -> V_66 = 0x7f ;
V_42 -> V_61 = 1 ;
V_42 -> V_62 = 0x7f ;
V_42 -> V_68 = 0x3ff ;
V_42 -> V_69 = 0 ;
V_42 -> V_70 = 0 ;
V_42 -> V_71 = 0 ;
V_42 -> V_72 = 0 ;
V_42 -> V_75 = 0 ;
F_18 ( V_9 , V_42 ) ;
F_22 ( ( V_152 & 0xffff ) , F_4 ( V_9 , V_156 ) ) ;
F_20 ( ( V_152 >> 16 ) , F_4 ( V_9 , V_156 + 2 ) ) ;
F_3 ( ( V_153 & 0xfffffffc ) , F_4 ( V_9 , V_157 ) ) ;
F_22 ( ( V_42 -> V_70 & 0xffff ) , F_4 ( V_9 , V_158 ) ) ;
F_20 ( ( V_42 -> V_70 >> 16 ) , F_4 ( V_9 , V_158 + 2 ) ) ;
F_20 ( V_9 -> V_140 , F_4 ( V_9 , V_158 + 3 ) ) ;
F_3 ( V_9 -> V_136 , F_4 ( V_9 , V_159 ) ) ;
} else {
V_42 -> V_74 = 0x800 ;
V_42 -> V_109 = F_30 ( 48000 , V_91 -> V_86 ) ;
if ( V_42 -> V_101 )
V_42 -> V_60 = V_42 -> V_101 -> V_110 ;
else
V_42 -> V_60 = V_91 -> V_111 ;
V_42 -> V_70 = 0 ;
V_42 -> V_73 = V_91 -> V_112 - 1 ;
V_42 -> V_63 = F_31 ( V_89 ) ;
V_42 -> V_64 = 3 ;
V_42 -> V_61 = 1 ;
V_42 -> V_69 = 0 ;
V_42 -> V_71 = 0 ;
V_42 -> V_72 = 0 ;
V_42 -> V_68 = V_107 -> V_113 ;
V_42 -> V_65 = V_107 -> V_114 ;
V_42 -> V_66 = V_107 -> V_115 ;
V_42 -> V_62 = V_107 -> V_116 ;
V_42 -> V_75 = ( 1 << ( 30 - 16 ) ) | ( 7 << ( 26 - 16 ) ) |
( 0 << ( 24 - 16 ) ) | ( 0 << ( 19 - 16 ) ) ;
F_18 ( V_9 , V_42 ) ;
if ( V_103 != NULL ) {
V_103 -> V_74 = V_42 -> V_74 ;
V_103 -> V_109 = V_42 -> V_109 ;
V_103 -> V_60 = V_42 -> V_60 ;
V_103 -> V_70 = 0 ;
V_103 -> V_73 = ( V_91 -> V_86 * 2 ) + 4 - 1 ;
V_103 -> V_63 = V_42 -> V_63 ;
V_103 -> V_64 = 3 ;
V_103 -> V_61 = V_9 -> V_12 == V_21 ? 0 : 1 ;
V_103 -> V_69 = 0 ;
V_103 -> V_71 = 0 ;
V_103 -> V_72 = 0 ;
V_103 -> V_68 = 0x3ff ;
V_103 -> V_65 = V_103 -> V_66 = 0x7f ;
V_103 -> V_62 = 0x7f ;
V_103 -> V_75 = 0 ;
F_18 ( V_9 , V_103 ) ;
V_103 -> V_117 = 1 ;
V_103 -> V_118 = V_91 -> V_86 ;
V_103 -> V_73 = ( V_91 -> V_86 * 2 ) - 1 ;
}
F_3 ( V_9 -> V_136 , F_4 ( V_9 , V_160 ) ) ;
V_154 = F_5 ( F_4 ( V_9 , V_37 ) ) ;
V_154 &= ~ ( 1 << 19 ) ;
F_3 ( V_154 , F_4 ( V_9 , V_37 ) ) ;
V_154 = F_5 ( F_4 ( V_9 , V_161 ) ) ;
V_154 |= V_162 ;
F_3 ( V_154 , F_4 ( V_9 , V_161 ) ) ;
}
F_52 ( & V_9 -> V_11 ) ;
return 0 ;
}
static int F_64 ( struct V_88 * V_89 ,
int V_94 )
{
struct V_8 * V_9 = F_37 ( V_89 ) ;
struct V_88 * V_163 ;
unsigned int V_164 , V_165 , V_166 , V_167 ;
struct V_57 * V_42 , * V_103 ;
unsigned int V_36 , V_168 ;
switch ( V_94 ) {
case V_169 :
case V_170 :
case V_171 :
V_168 = 1 ;
break;
case V_172 :
case V_173 :
case V_174 :
V_168 = 0 ;
break;
default:
return - V_175 ;
}
V_164 = V_165 = V_166 = V_167 = 0 ;
F_65 ( & V_9 -> V_11 ) ;
V_36 = F_5 ( F_4 ( V_9 , V_176 ) ) & 0x00ffffff ;
F_66 (s, substream) {
if ( (struct V_8 * ) F_37 ( V_163 ) == V_9 ) {
V_42 = V_163 -> V_91 -> V_10 ;
V_103 = V_42 -> V_104 ;
V_164 |= 1 << ( V_42 -> V_67 & 0x1f ) ;
if ( V_103 == NULL ) {
V_165 |= 1 << ( V_42 -> V_67 & 0x1f ) ;
} else {
V_164 |= 1 << ( V_103 -> V_67 & 0x1f ) ;
V_165 |= 1 << ( V_103 -> V_67 & 0x1f ) ;
if ( V_168 )
V_103 -> V_177 = V_36 ;
}
if ( V_168 ) {
V_42 -> V_178 = 1 ;
V_42 -> V_177 = V_36 ;
} else {
V_42 -> V_178 = 0 ;
}
F_67 ( V_163 , V_89 ) ;
if ( V_42 -> V_179 )
V_166 = 1 ;
if ( V_42 -> V_180 )
V_167 = 1 ;
}
}
if ( V_167 ) {
if ( V_9 -> V_12 != V_21 ) {
F_3 ( V_9 -> V_136 , F_4 ( V_9 , V_159 ) ) ;
V_36 = V_9 -> V_140 ;
if ( ! V_168 )
V_36 &= ~ ( 0x28 ) ;
F_20 ( V_36 , F_4 ( V_9 , V_158 + 3 ) ) ;
} else {
F_3 ( V_9 -> V_136 , F_4 ( V_9 , V_160 ) ) ;
V_36 = F_5 ( F_4 ( V_9 , V_161 ) ) | V_162 ;
F_3 ( V_36 , F_4 ( V_9 , V_161 ) ) ;
}
}
if ( ! V_168 )
F_3 ( V_164 , F_4 ( V_9 , V_46 ) ) ;
V_36 = F_5 ( F_4 ( V_9 , V_181 ) ) ;
if ( V_168 ) {
V_36 |= V_165 ;
} else {
V_36 &= ~ V_165 ;
}
F_3 ( V_36 , F_4 ( V_9 , V_181 ) ) ;
if ( V_168 ) {
F_3 ( V_164 , F_4 ( V_9 , V_44 ) ) ;
if ( V_166 && V_9 -> V_12 != V_21 )
F_20 ( V_9 -> V_127 , F_4 ( V_9 , V_182 ) ) ;
} else {
if ( V_166 && V_9 -> V_12 != V_21 )
F_20 ( 0x00 , F_4 ( V_9 , V_182 ) ) ;
}
F_68 ( & V_9 -> V_11 ) ;
return 0 ;
}
static T_1 F_69 ( struct V_88 * V_89 )
{
struct V_8 * V_9 = F_37 ( V_89 ) ;
struct V_90 * V_91 = V_89 -> V_91 ;
struct V_57 * V_42 = V_91 -> V_10 ;
unsigned int V_183 ;
if ( ! V_42 -> V_178 )
return 0 ;
F_65 ( & V_9 -> V_11 ) ;
F_20 ( V_42 -> V_67 , F_4 ( V_9 , V_37 ) ) ;
if ( V_9 -> V_12 != V_16 ) {
V_183 = F_9 ( F_4 ( V_9 , V_77 + 2 ) ) ;
} else {
V_183 = ( unsigned int ) F_5 ( F_4 ( V_9 , V_78 ) ) & 0x00ffffff ;
}
F_68 ( & V_9 -> V_11 ) ;
if ( V_183 >= V_91 -> V_112 )
V_183 = 0 ;
return V_183 ;
}
static T_1 F_70 ( struct V_88 * V_89 )
{
struct V_8 * V_9 = F_37 ( V_89 ) ;
struct V_90 * V_91 = V_89 -> V_91 ;
struct V_57 * V_42 = V_91 -> V_10 ;
unsigned int V_184 ;
if ( ! V_42 -> V_178 )
return 0 ;
V_184 = F_9 ( F_4 ( V_9 , V_126 ) ) ;
if ( V_91 -> V_93 > 1 )
V_184 >>= 1 ;
if ( V_184 > 0 )
V_184 = V_91 -> V_112 - V_184 ;
return V_184 ;
}
static T_1 F_71 ( struct V_88 * V_89 )
{
struct V_8 * V_9 = F_37 ( V_89 ) ;
struct V_90 * V_91 = V_89 -> V_91 ;
struct V_57 * V_42 = V_91 -> V_10 ;
unsigned int V_184 ;
if ( ! V_42 -> V_178 )
return 0 ;
V_184 = F_5 ( F_4 ( V_9 , V_158 ) ) & 0x00ffffff ;
return V_184 ;
}
static void F_72 ( struct V_90 * V_91 )
{
struct V_57 * V_42 = V_91 -> V_10 ;
struct V_8 * V_9 ;
if ( V_42 ) {
V_9 = V_42 -> V_9 ;
F_46 ( V_9 , V_42 ) ;
}
}
static int F_73 ( struct V_88 * V_89 )
{
struct V_8 * V_9 = F_37 ( V_89 ) ;
struct V_90 * V_91 = V_89 -> V_91 ;
struct V_57 * V_42 ;
V_42 = F_45 ( V_9 , V_105 , 0 , 0 ) ;
if ( V_42 == NULL )
return - V_185 ;
F_74 ( V_9 , V_42 , V_89 ) ;
V_42 -> V_89 = V_89 ;
V_91 -> V_10 = V_42 ;
V_91 -> V_186 = F_72 ;
V_91 -> V_187 = V_188 ;
F_75 ( V_89 ) ;
F_76 ( V_91 , V_189 , 0 , 64 * 1024 ) ;
return 0 ;
}
static int F_77 ( struct V_88 * V_89 )
{
struct V_8 * V_9 = F_37 ( V_89 ) ;
struct V_90 * V_91 = V_89 -> V_91 ;
struct V_57 * V_42 = V_91 -> V_10 ;
F_78 ( V_9 , V_42 , V_89 ) ;
return 0 ;
}
static int F_79 ( struct V_88 * V_89 )
{
struct V_8 * V_9 = F_37 ( V_89 ) ;
struct V_57 * V_42 ;
struct V_90 * V_91 = V_89 -> V_91 ;
V_42 = F_45 ( V_9 , V_105 , 0 , 0 ) ;
if ( V_42 == NULL )
return - V_185 ;
V_42 -> V_180 = 1 ;
V_42 -> V_89 = V_89 ;
F_51 ( & V_9 -> V_11 ) ;
V_9 -> V_136 = V_9 -> V_141 ;
F_52 ( & V_9 -> V_11 ) ;
V_91 -> V_10 = V_42 ;
V_91 -> V_186 = F_72 ;
if ( V_9 -> V_12 == V_21 ) {
V_91 -> V_187 = V_190 ;
} else {
V_91 -> V_187 = V_191 ;
}
V_9 -> V_150 -> V_192 [ 0 ] . V_193 &= ~ V_194 ;
F_62 ( V_9 -> V_148 , V_149 |
V_195 , & V_9 -> V_150 -> V_151 ) ;
F_76 ( V_91 , V_189 , 0 , 64 * 1024 ) ;
return 0 ;
}
static int F_80 ( struct V_88 * V_89 )
{
struct V_8 * V_9 = F_37 ( V_89 ) ;
unsigned int V_154 ;
F_51 ( & V_9 -> V_11 ) ;
if ( V_9 -> V_12 != V_21 ) {
F_20 ( V_9 -> V_196 , F_4 ( V_9 , V_158 + 3 ) ) ;
F_3 ( V_9 -> V_141 , F_4 ( V_9 , V_159 ) ) ;
} else {
F_3 ( V_9 -> V_141 , F_4 ( V_9 , V_160 ) ) ;
V_154 = F_5 ( F_4 ( V_9 , V_161 ) ) ;
if ( V_9 -> V_196 ) {
V_154 |= V_162 ;
} else {
V_154 &= ~ V_162 ;
}
F_3 ( V_154 , F_4 ( V_9 , V_161 ) ) ;
}
F_52 ( & V_9 -> V_11 ) ;
V_9 -> V_150 -> V_192 [ 0 ] . V_193 |= V_194 ;
F_62 ( V_9 -> V_148 , V_149 |
V_195 , & V_9 -> V_150 -> V_151 ) ;
return 0 ;
}
static int F_81 ( struct V_88 * V_89 )
{
struct V_8 * V_9 = F_37 ( V_89 ) ;
struct V_57 * V_42 ;
struct V_90 * V_91 = V_89 -> V_91 ;
V_42 = F_45 ( V_9 , V_105 , 0 , 0 ) ;
if ( V_42 == NULL )
return - V_185 ;
V_42 -> V_179 = 1 ;
V_42 -> V_89 = V_89 ;
V_91 -> V_10 = V_42 ;
V_91 -> V_186 = F_72 ;
V_91 -> V_187 = V_197 ;
F_75 ( V_89 ) ;
F_76 ( V_91 , V_189 , 0 , 64 * 1024 ) ;
return 0 ;
}
static int F_82 ( struct V_88 * V_89 )
{
return 0 ;
}
static int F_83 ( struct V_88 * V_89 )
{
struct V_8 * V_9 = F_37 ( V_89 ) ;
struct V_57 * V_42 ;
struct V_90 * V_91 = V_89 -> V_91 ;
V_42 = F_45 ( V_9 , V_105 , 0 , 0 ) ;
if ( V_42 == NULL )
return - V_185 ;
V_42 -> V_133 = V_89 -> V_67 ;
V_42 -> V_89 = V_89 ;
V_91 -> V_10 = V_42 ;
V_91 -> V_186 = F_72 ;
V_91 -> V_187 = V_198 ;
F_76 ( V_91 , V_189 , 0 , 64 * 1024 ) ;
return 0 ;
}
static int F_84 ( struct V_88 * V_89 )
{
struct V_8 * V_9 = F_37 ( V_89 ) ;
struct V_57 * V_42 ;
struct V_90 * V_91 = V_89 -> V_91 ;
V_42 = V_91 -> V_10 ;
F_51 ( & V_9 -> V_11 ) ;
F_20 ( 0x00 , F_4 ( V_9 , V_132 + V_42 -> V_133 ) ) ;
F_52 ( & V_9 -> V_11 ) ;
return 0 ;
}
int F_85 ( struct V_8 * V_9 ,
int V_12 , struct V_199 * * V_200 )
{
struct V_199 * V_201 ;
int V_98 ;
if ( V_200 )
* V_200 = NULL ;
if ( ( V_98 = F_86 ( V_9 -> V_148 , L_2 , V_12 , V_9 -> V_50 , 1 , & V_201 ) ) < 0 )
return V_98 ;
V_201 -> V_10 = V_9 ;
if ( V_9 -> V_99 . V_100 ) {
F_87 ( V_201 , V_202 , & V_203 ) ;
} else {
F_87 ( V_201 , V_202 , & V_204 ) ;
}
F_87 ( V_201 , V_205 ,
V_9 -> V_12 != V_21 ?
& V_206 :
& V_207 ) ;
V_201 -> V_208 = 0 ;
V_201 -> V_209 = V_210 ;
strcpy ( V_201 -> V_211 , L_3 ) ;
V_9 -> V_201 = V_201 ;
if ( V_9 -> V_99 . V_100 ) {
struct V_88 * V_89 ;
for ( V_89 = V_201 -> V_212 [ V_202 ] . V_89 ; V_89 ; V_89 = V_89 -> V_213 )
F_88 ( V_89 , V_214 ,
F_89 ( V_9 -> V_215 ) ,
64 * 1024 , 128 * 1024 ) ;
F_88 ( V_201 -> V_212 [ V_205 ] . V_89 ,
V_216 , F_89 ( V_9 -> V_215 ) ,
64 * 1024 , 128 * 1024 ) ;
} else {
F_90 ( V_201 , V_216 ,
F_89 ( V_9 -> V_215 ) , 64 * 1024 , 128 * 1024 ) ;
}
if ( V_200 )
* V_200 = V_201 ;
return 0 ;
}
int F_91 ( struct V_8 * V_9 ,
int V_12 , struct V_199 * * V_200 )
{
struct V_199 * V_217 ;
int V_98 ;
int V_218 = 3 ;
struct V_88 * V_89 ;
if ( V_200 )
* V_200 = NULL ;
if ( V_9 -> V_12 == V_16 )
V_218 = 4 ;
if ( ( V_98 = F_86 ( V_9 -> V_148 , L_2 , V_12 , 0 , V_218 , & V_217 ) ) < 0 )
return V_98 ;
V_217 -> V_10 = V_9 ;
if ( V_9 -> V_99 . V_100 )
F_87 ( V_217 , V_205 , & V_219 ) ;
else
F_87 ( V_217 , V_205 , & V_220 ) ;
V_217 -> V_208 = 0 ;
strcpy ( V_217 -> V_211 , L_3 ) ;
V_89 = V_217 -> V_212 [ V_205 ] . V_89 ;
strcpy ( V_89 -> V_211 , L_4 ) ;
V_89 = V_89 -> V_213 ;
strcpy ( V_89 -> V_211 , L_5 ) ;
V_89 = V_89 -> V_213 ;
strcpy ( V_89 -> V_211 , L_6 ) ;
if ( V_218 == 4 ) {
V_89 = V_89 -> V_213 ;
strcpy ( V_89 -> V_211 , L_7 ) ;
}
V_9 -> V_217 = V_217 ;
if ( V_9 -> V_99 . V_100 )
F_90 ( V_217 , V_214 ,
F_89 ( V_9 -> V_215 ) , 0 , 128 * 1024 ) ;
else
F_90 ( V_217 , V_216 ,
F_89 ( V_9 -> V_215 ) , 64 * 1024 , 128 * 1024 ) ;
if ( V_200 )
* V_200 = V_217 ;
return 0 ;
}
int F_92 ( struct V_8 * V_9 ,
int V_12 , struct V_199 * * V_200 )
{
struct V_199 * V_180 ;
int V_98 ;
if ( V_200 )
* V_200 = NULL ;
if ( ( V_98 = F_86 ( V_9 -> V_148 , L_8 , V_12 , 1 , 0 , & V_180 ) ) < 0 )
return V_98 ;
V_180 -> V_10 = V_9 ;
if ( V_9 -> V_12 != V_21 ) {
F_87 ( V_180 , V_202 , & V_221 ) ;
} else {
F_87 ( V_180 , V_202 , & V_222 ) ;
}
V_180 -> V_208 = 0 ;
strcpy ( V_180 -> V_211 , L_9 ) ;
V_9 -> V_180 = V_180 ;
F_90 ( V_180 , V_216 , F_89 ( V_9 -> V_215 ) , 64 * 1024 , 128 * 1024 ) ;
if ( V_200 )
* V_200 = V_180 ;
return 0 ;
}
static int F_93 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
struct V_8 * V_9 = F_94 ( V_224 ) ;
unsigned char V_36 ;
F_51 ( & V_9 -> V_11 ) ;
V_36 = V_9 -> V_196 ;
V_226 -> V_227 . integer . V_227 [ 0 ] = V_36 == V_224 -> V_228 ;
F_52 ( & V_9 -> V_11 ) ;
return 0 ;
}
static int F_95 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
struct V_8 * V_9 = F_94 ( V_224 ) ;
unsigned char V_36 ;
int V_135 ;
V_36 = V_226 -> V_227 . integer . V_227 [ 0 ] ? ( unsigned char ) V_224 -> V_228 : 0x00 ;
F_51 ( & V_9 -> V_11 ) ;
V_135 = V_9 -> V_196 != V_36 ;
V_9 -> V_196 = V_36 ;
if ( V_9 -> V_12 != V_21 ) {
if ( ( F_96 ( F_4 ( V_9 , V_158 + 3 ) ) & 0x10 ) == 0 ) {
F_3 ( V_9 -> V_141 , F_4 ( V_9 , V_159 ) ) ;
F_20 ( V_9 -> V_196 , F_4 ( V_9 , V_158 + 3 ) ) ;
}
} else {
if ( V_9 -> V_180 == NULL ) {
unsigned int V_154 ;
F_3 ( V_9 -> V_141 , F_4 ( V_9 , V_160 ) ) ;
V_154 = F_5 ( F_4 ( V_9 , V_161 ) ) & ~ V_162 ;
if ( V_36 )
V_154 |= V_162 ;
F_3 ( V_154 , F_4 ( V_9 , V_161 ) ) ;
}
}
F_52 ( & V_9 -> V_11 ) ;
return V_135 ;
}
static int F_97 ( struct V_223 * V_224 ,
struct V_229 * V_230 )
{
V_230 -> type = V_231 ;
V_230 -> V_6 = 1 ;
return 0 ;
}
static int F_98 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
struct V_8 * V_9 = F_94 ( V_224 ) ;
F_51 ( & V_9 -> V_11 ) ;
V_226 -> V_227 . V_232 . V_233 [ 0 ] = ( V_9 -> V_141 >> 0 ) & 0xff ;
V_226 -> V_227 . V_232 . V_233 [ 1 ] = ( V_9 -> V_141 >> 8 ) & 0xff ;
V_226 -> V_227 . V_232 . V_233 [ 2 ] = ( V_9 -> V_141 >> 16 ) & 0xff ;
V_226 -> V_227 . V_232 . V_233 [ 3 ] = ( V_9 -> V_141 >> 24 ) & 0xff ;
F_52 ( & V_9 -> V_11 ) ;
return 0 ;
}
static int F_99 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
struct V_8 * V_9 = F_94 ( V_224 ) ;
unsigned int V_36 ;
int V_135 ;
V_36 = ( V_226 -> V_227 . V_232 . V_233 [ 0 ] << 0 ) |
( V_226 -> V_227 . V_232 . V_233 [ 1 ] << 8 ) |
( V_226 -> V_227 . V_232 . V_233 [ 2 ] << 16 ) |
( V_226 -> V_227 . V_232 . V_233 [ 3 ] << 24 ) ;
F_51 ( & V_9 -> V_11 ) ;
V_135 = V_9 -> V_141 != V_36 ;
V_9 -> V_141 = V_36 ;
if ( V_9 -> V_12 != V_21 ) {
if ( ( F_96 ( F_4 ( V_9 , V_158 + 3 ) ) & 0x10 ) == 0 )
F_3 ( V_9 -> V_141 , F_4 ( V_9 , V_159 ) ) ;
} else {
if ( V_9 -> V_180 == NULL )
F_3 ( V_9 -> V_141 , F_4 ( V_9 , V_160 ) ) ;
}
F_52 ( & V_9 -> V_11 ) ;
return V_135 ;
}
static int F_100 ( struct V_223 * V_224 ,
struct V_229 * V_230 )
{
V_230 -> type = V_231 ;
V_230 -> V_6 = 1 ;
return 0 ;
}
static int F_101 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
V_226 -> V_227 . V_232 . V_233 [ 0 ] = 0xff ;
V_226 -> V_227 . V_232 . V_233 [ 1 ] = 0xff ;
V_226 -> V_227 . V_232 . V_233 [ 2 ] = 0xff ;
V_226 -> V_227 . V_232 . V_233 [ 3 ] = 0xff ;
return 0 ;
}
static int F_102 ( struct V_223 * V_224 ,
struct V_229 * V_230 )
{
V_230 -> type = V_231 ;
V_230 -> V_6 = 1 ;
return 0 ;
}
static int F_103 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
struct V_8 * V_9 = F_94 ( V_224 ) ;
F_51 ( & V_9 -> V_11 ) ;
V_226 -> V_227 . V_232 . V_233 [ 0 ] = ( V_9 -> V_136 >> 0 ) & 0xff ;
V_226 -> V_227 . V_232 . V_233 [ 1 ] = ( V_9 -> V_136 >> 8 ) & 0xff ;
V_226 -> V_227 . V_232 . V_233 [ 2 ] = ( V_9 -> V_136 >> 16 ) & 0xff ;
V_226 -> V_227 . V_232 . V_233 [ 3 ] = ( V_9 -> V_136 >> 24 ) & 0xff ;
F_52 ( & V_9 -> V_11 ) ;
return 0 ;
}
static int F_104 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
struct V_8 * V_9 = F_94 ( V_224 ) ;
unsigned int V_36 ;
int V_135 ;
V_36 = ( V_226 -> V_227 . V_232 . V_233 [ 0 ] << 0 ) |
( V_226 -> V_227 . V_232 . V_233 [ 1 ] << 8 ) |
( V_226 -> V_227 . V_232 . V_233 [ 2 ] << 16 ) |
( V_226 -> V_227 . V_232 . V_233 [ 3 ] << 24 ) ;
F_51 ( & V_9 -> V_11 ) ;
V_135 = V_9 -> V_136 != V_36 ;
V_9 -> V_136 = V_36 ;
if ( V_9 -> V_180 != NULL ) {
if ( V_9 -> V_12 != V_21 ) {
F_3 ( V_9 -> V_136 , F_4 ( V_9 , V_159 ) ) ;
} else {
F_3 ( V_9 -> V_141 , F_4 ( V_9 , V_160 ) ) ;
}
}
F_52 ( & V_9 -> V_11 ) ;
return V_135 ;
}
static int F_105 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
struct V_8 * V_9 = F_94 ( V_224 ) ;
unsigned char V_36 ;
F_51 ( & V_9 -> V_11 ) ;
V_36 = V_9 -> V_234 = F_5 ( F_4 ( V_9 , V_235 ) ) ;
V_226 -> V_227 . integer . V_227 [ 0 ] = ( V_36 & ( 1 << V_224 -> V_228 ) ) ? 1 : 0 ;
F_52 ( & V_9 -> V_11 ) ;
return 0 ;
}
static int F_106 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
struct V_8 * V_9 = F_94 ( V_224 ) ;
unsigned char V_36 ;
int V_135 = 0 ;
F_51 ( & V_9 -> V_11 ) ;
V_36 = V_9 -> V_234 = F_5 ( F_4 ( V_9 , V_235 ) ) ;
V_36 &= ~ ( 1 << V_224 -> V_228 ) ;
if ( V_226 -> V_227 . integer . V_227 [ 0 ] )
V_36 |= 1 << V_224 -> V_228 ;
V_135 = V_36 != V_9 -> V_234 ;
V_9 -> V_234 = V_36 ;
F_3 ( V_9 -> V_234 = V_36 , F_4 ( V_9 , V_235 ) ) ;
F_52 ( & V_9 -> V_11 ) ;
return V_135 ;
}
static int F_107 ( struct V_223 * V_224 ,
struct V_229 * V_230 )
{
V_230 -> type = V_236 ;
V_230 -> V_6 = 2 ;
V_230 -> V_227 . integer . V_237 = 0 ;
V_230 -> V_227 . integer . V_238 = 255 ;
return 0 ;
}
static int F_108 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
struct V_8 * V_9 = F_94 ( V_224 ) ;
unsigned int V_36 ;
V_36 = V_9 -> V_239 ;
V_226 -> V_227 . integer . V_227 [ 0 ] = 255 - ( ( V_36 >> V_224 -> V_228 ) & 0xff ) ;
V_226 -> V_227 . integer . V_227 [ 1 ] = 255 - ( ( V_36 >> ( V_224 -> V_228 + 8 ) ) & 0xff ) ;
return 0 ;
}
static int F_109 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
struct V_8 * V_9 = F_94 ( V_224 ) ;
unsigned int V_36 ;
int V_135 = 0 ;
F_51 ( & V_9 -> V_11 ) ;
V_36 = V_9 -> V_239 ;
V_36 &= ~ ( 0xffff << V_224 -> V_228 ) ;
V_36 |= ( ( 255 - ( V_226 -> V_227 . integer . V_227 [ 0 ] & 0xff ) ) |
( ( 255 - ( V_226 -> V_227 . integer . V_227 [ 1 ] & 0xff ) ) << 8 ) ) << V_224 -> V_228 ;
V_135 = V_36 != V_9 -> V_239 ;
F_3 ( V_9 -> V_239 = V_36 , F_4 ( V_9 , V_240 ) ) ;
F_52 ( & V_9 -> V_11 ) ;
return V_135 ;
}
static int F_110 ( struct V_223 * V_224 ,
struct V_229 * V_230 )
{
struct V_8 * V_9 = F_94 ( V_224 ) ;
V_230 -> type = V_236 ;
V_230 -> V_6 = 1 ;
V_230 -> V_227 . integer . V_237 = 0 ;
V_230 -> V_227 . integer . V_238 = 255 ;
if ( V_9 -> V_12 == V_21 )
V_230 -> V_227 . integer . V_238 = 1023 ;
return 0 ;
}
static int F_111 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
struct V_8 * V_9 = F_94 ( V_224 ) ;
struct V_106 * V_107 = & V_9 -> V_108 [ F_112 ( V_224 , & V_226 -> V_151 ) ] ;
if ( V_9 -> V_12 == V_21 ) {
V_226 -> V_227 . integer . V_227 [ 0 ] = 1023 - V_107 -> V_113 ;
} else {
V_226 -> V_227 . integer . V_227 [ 0 ] = 255 - ( V_107 -> V_113 >> 2 ) ;
}
return 0 ;
}
static int F_113 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
struct V_8 * V_9 = F_94 ( V_224 ) ;
struct V_106 * V_107 = & V_9 -> V_108 [ F_112 ( V_224 , & V_226 -> V_151 ) ] ;
unsigned int V_36 ;
int V_135 = 0 ;
if ( V_9 -> V_12 == V_21 ) {
V_36 = 1023 - ( V_226 -> V_227 . integer . V_227 [ 0 ] & 1023 ) ;
} else {
V_36 = ( 255 - ( V_226 -> V_227 . integer . V_227 [ 0 ] & 255 ) ) << 2 ;
}
F_51 ( & V_9 -> V_11 ) ;
V_135 = V_36 != V_107 -> V_113 ;
V_107 -> V_113 = V_36 ;
if ( V_107 -> V_42 != NULL )
F_24 ( V_9 , V_107 -> V_42 , V_36 ) ;
F_52 ( & V_9 -> V_11 ) ;
return V_135 ;
}
static int F_114 ( struct V_223 * V_224 ,
struct V_229 * V_230 )
{
V_230 -> type = V_236 ;
V_230 -> V_6 = 1 ;
V_230 -> V_227 . integer . V_237 = 0 ;
V_230 -> V_227 . integer . V_238 = 127 ;
return 0 ;
}
static int F_115 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
struct V_8 * V_9 = F_94 ( V_224 ) ;
struct V_106 * V_107 = & V_9 -> V_108 [ F_112 ( V_224 , & V_226 -> V_151 ) ] ;
V_226 -> V_227 . integer . V_227 [ 0 ] = V_107 -> V_116 ;
if ( V_226 -> V_227 . integer . V_227 [ 0 ] & 0x40 ) {
V_226 -> V_227 . integer . V_227 [ 0 ] = ( 0x3f - ( V_226 -> V_227 . integer . V_227 [ 0 ] & 0x3f ) ) ;
} else {
V_226 -> V_227 . integer . V_227 [ 0 ] |= 0x40 ;
}
return 0 ;
}
static int F_116 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
struct V_8 * V_9 = F_94 ( V_224 ) ;
struct V_106 * V_107 = & V_9 -> V_108 [ F_112 ( V_224 , & V_226 -> V_151 ) ] ;
unsigned char V_36 ;
int V_135 = 0 ;
if ( V_226 -> V_227 . integer . V_227 [ 0 ] & 0x40 )
V_36 = V_226 -> V_227 . integer . V_227 [ 0 ] & 0x3f ;
else
V_36 = ( 0x3f - ( V_226 -> V_227 . integer . V_227 [ 0 ] & 0x3f ) ) | 0x40 ;
F_51 ( & V_9 -> V_11 ) ;
V_135 = V_36 != V_107 -> V_116 ;
V_107 -> V_116 = V_36 ;
if ( V_107 -> V_42 != NULL )
F_25 ( V_9 , V_107 -> V_42 , V_36 ) ;
F_52 ( & V_9 -> V_11 ) ;
return V_135 ;
}
static int F_117 ( struct V_223 * V_224 ,
struct V_229 * V_230 )
{
V_230 -> type = V_236 ;
V_230 -> V_6 = 1 ;
V_230 -> V_227 . integer . V_237 = 0 ;
V_230 -> V_227 . integer . V_238 = 127 ;
return 0 ;
}
static int F_118 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
struct V_8 * V_9 = F_94 ( V_224 ) ;
struct V_106 * V_107 = & V_9 -> V_108 [ F_112 ( V_224 , & V_226 -> V_151 ) ] ;
V_226 -> V_227 . integer . V_227 [ 0 ] = 127 - V_107 -> V_114 ;
return 0 ;
}
static int F_119 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
struct V_8 * V_9 = F_94 ( V_224 ) ;
struct V_106 * V_107 = & V_9 -> V_108 [ F_112 ( V_224 , & V_226 -> V_151 ) ] ;
unsigned short V_36 ;
int V_135 = 0 ;
V_36 = 0x7f - ( V_226 -> V_227 . integer . V_227 [ 0 ] & 0x7f ) ;
F_51 ( & V_9 -> V_11 ) ;
V_135 = V_36 != V_107 -> V_114 ;
V_107 -> V_114 = V_36 ;
if ( V_107 -> V_42 != NULL )
F_26 ( V_9 , V_107 -> V_42 , V_36 ) ;
F_52 ( & V_9 -> V_11 ) ;
return V_135 ;
}
static int F_120 ( struct V_223 * V_224 ,
struct V_229 * V_230 )
{
V_230 -> type = V_236 ;
V_230 -> V_6 = 1 ;
V_230 -> V_227 . integer . V_237 = 0 ;
V_230 -> V_227 . integer . V_238 = 127 ;
return 0 ;
}
static int F_121 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
struct V_8 * V_9 = F_94 ( V_224 ) ;
struct V_106 * V_107 = & V_9 -> V_108 [ F_112 ( V_224 , & V_226 -> V_151 ) ] ;
V_226 -> V_227 . integer . V_227 [ 0 ] = 127 - V_107 -> V_115 ;
return 0 ;
}
static int F_122 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
struct V_8 * V_9 = F_94 ( V_224 ) ;
struct V_106 * V_107 = & V_9 -> V_108 [ F_112 ( V_224 , & V_226 -> V_151 ) ] ;
unsigned short V_36 ;
int V_135 = 0 ;
V_36 = 0x7f - ( V_226 -> V_227 . integer . V_227 [ 0 ] & 0x7f ) ;
F_51 ( & V_9 -> V_11 ) ;
V_135 = V_36 != V_107 -> V_115 ;
V_107 -> V_115 = V_36 ;
if ( V_107 -> V_42 != NULL )
F_27 ( V_9 , V_107 -> V_42 , V_36 ) ;
F_52 ( & V_9 -> V_11 ) ;
return V_135 ;
}
static void F_123 ( struct V_241 * V_148 ,
struct V_223 * V_242 ,
int V_18 , int V_243 )
{
struct V_244 V_151 ;
if ( ! V_242 )
return;
if ( V_243 )
V_242 -> V_192 [ V_18 ] . V_193 &= ~ V_194 ;
else
V_242 -> V_192 [ V_18 ] . V_193 |= V_194 ;
F_62 ( V_148 , V_149 |
V_195 ,
F_124 ( & V_151 , V_242 , V_18 ) ) ;
}
static void F_125 ( struct V_8 * V_9 ,
struct V_106 * V_245 ,
int V_18 , int V_243 )
{
F_123 ( V_9 -> V_148 , V_9 -> V_246 , V_18 , V_243 ) ;
F_123 ( V_9 -> V_148 , V_9 -> V_247 , V_18 , V_243 ) ;
F_123 ( V_9 -> V_148 , V_9 -> V_248 , V_18 , V_243 ) ;
F_123 ( V_9 -> V_148 , V_9 -> V_249 , V_18 , V_243 ) ;
}
static int F_74 ( struct V_8 * V_9 ,
struct V_57 * V_42 ,
struct V_88 * V_89 )
{
struct V_106 * V_245 ;
if ( F_126 ( ! V_9 || ! V_42 || ! V_89 ) )
return - V_175 ;
V_245 = & V_9 -> V_108 [ V_89 -> V_67 ] ;
V_245 -> V_42 = V_42 ;
V_245 -> V_113 = V_250 ;
V_245 -> V_116 = V_131 ;
V_245 -> V_114 = V_251 ;
V_245 -> V_115 = V_252 ;
F_125 ( V_9 , V_245 , V_89 -> V_67 , 1 ) ;
return 0 ;
}
static int F_78 ( struct V_8 * V_9 , struct V_57 * V_42 , struct V_88 * V_89 )
{
struct V_106 * V_245 ;
if ( F_126 ( ! V_9 || ! V_89 ) )
return - V_175 ;
V_245 = & V_9 -> V_108 [ V_89 -> V_67 ] ;
V_245 -> V_42 = NULL ;
F_125 ( V_9 , V_245 , V_89 -> V_67 , 0 ) ;
return 0 ;
}
static int F_127 ( struct V_8 * V_9 , int V_253 )
{
struct V_254 V_255 ;
struct V_241 * V_148 = V_9 -> V_148 ;
struct V_223 * V_242 ;
struct V_225 * V_256 ;
int V_48 , V_98 , V_257 = 2 ;
static struct V_258 V_259 = {
. V_260 = F_8 ,
. V_261 = F_1 ,
} ;
V_256 = F_128 ( sizeof( * V_256 ) , V_262 ) ;
if ( ! V_256 )
return - V_102 ;
if ( ( V_98 = F_129 ( V_9 -> V_148 , 0 , & V_259 , NULL , & V_9 -> V_263 ) ) < 0 )
goto V_264;
memset ( & V_255 , 0 , sizeof( V_255 ) ) ;
V_255 . V_10 = V_9 ;
V_9 -> V_26 = 1 ;
V_265:
if ( ( V_98 = F_130 ( V_9 -> V_263 , & V_255 , & V_9 -> V_2 ) ) < 0 ) {
if ( V_9 -> V_12 == V_21 ) {
if ( ( V_98 = F_131 ( V_9 ) ) < 0 )
goto V_264;
if ( V_257 -- > 0 )
goto V_265;
V_98 = - V_266 ;
}
goto V_264;
}
if ( V_9 -> V_12 == V_21 &&
( F_5 ( F_4 ( V_9 , V_161 ) ) & V_267 ) != 0 ) {
V_255 . V_18 = 1 ;
V_98 = F_130 ( V_9 -> V_263 , & V_255 , & V_9 -> V_268 ) ;
if ( V_98 < 0 )
F_6 ( V_27 L_10 ) ;
#if 0
{
struct snd_ac97 *mc97;
err = snd_ac97_modem(trident->card, &_ac97, &mc97);
if (err < 0)
snd_printk(KERN_ERR "snd_ac97_modem returned error %i\n", err);
}
#endif
}
V_9 -> V_26 = 0 ;
if ( V_9 -> V_12 != V_21 ) {
if ( ( V_98 = F_132 ( V_148 , V_242 = F_133 ( & V_269 , V_9 ) ) ) < 0 )
goto V_264;
V_242 -> V_270 ( V_242 , V_256 ) ;
if ( ( V_98 = F_132 ( V_148 , V_242 = F_133 ( & V_271 , V_9 ) ) ) < 0 )
goto V_264;
V_242 -> V_270 ( V_242 , V_256 ) ;
F_3 ( V_9 -> V_239 = 0x00000000 , F_4 ( V_9 , V_240 ) ) ;
} else {
F_3 ( V_9 -> V_239 = 0xffff0000 , F_4 ( V_9 , V_240 ) ) ;
}
for ( V_48 = 0 ; V_48 < 32 ; V_48 ++ ) {
struct V_106 * V_245 ;
V_245 = & V_9 -> V_108 [ V_48 ] ;
V_245 -> V_42 = NULL ;
}
if ( ( V_9 -> V_246 = F_133 ( & V_272 , V_9 ) ) == NULL )
goto V_273;
if ( ( V_98 = F_132 ( V_148 , V_9 -> V_246 ) ) )
goto V_264;
if ( ( V_9 -> V_247 = F_133 ( & V_274 , V_9 ) ) == NULL )
goto V_273;
if ( ( V_98 = F_132 ( V_148 , V_9 -> V_247 ) ) )
goto V_264;
if ( ( V_9 -> V_248 = F_133 ( & V_275 , V_9 ) ) == NULL )
goto V_273;
if ( ( V_98 = F_132 ( V_148 , V_9 -> V_248 ) ) )
goto V_264;
if ( ( V_9 -> V_249 = F_133 ( & V_276 , V_9 ) ) == NULL )
goto V_273;
if ( ( V_98 = F_132 ( V_148 , V_9 -> V_249 ) ) )
goto V_264;
if ( V_9 -> V_12 == V_16 ) {
if ( ( V_98 = F_132 ( V_148 , V_242 = F_133 ( & V_277 , V_9 ) ) ) < 0 )
goto V_264;
V_242 -> V_270 ( V_242 , V_256 ) ;
}
if ( V_9 -> V_12 == V_16 || V_9 -> V_12 == V_21 ) {
V_242 = F_133 ( & V_278 , V_9 ) ;
if ( V_242 == NULL ) {
V_98 = - V_102 ;
goto V_264;
}
if ( V_9 -> V_2 -> V_279 & V_280 )
V_242 -> V_151 . V_281 ++ ;
if ( V_9 -> V_268 && ( V_9 -> V_268 -> V_279 & V_280 ) )
V_242 -> V_151 . V_281 ++ ;
V_48 = V_242 -> V_151 . V_281 ;
if ( ( V_98 = F_132 ( V_148 , V_242 ) ) < 0 )
goto V_264;
V_242 -> V_270 ( V_242 , V_256 ) ;
V_242 = F_133 ( & V_282 , V_9 ) ;
if ( V_242 == NULL ) {
V_98 = - V_102 ;
goto V_264;
}
V_242 -> V_151 . V_281 = V_48 ;
V_242 -> V_151 . V_12 = V_253 ;
if ( ( V_98 = F_132 ( V_148 , V_242 ) ) < 0 )
goto V_264;
V_242 = F_133 ( & V_283 , V_9 ) ;
if ( V_242 == NULL ) {
V_98 = - V_102 ;
goto V_264;
}
V_242 -> V_151 . V_281 = V_48 ;
V_242 -> V_151 . V_12 = V_253 ;
if ( ( V_98 = F_132 ( V_148 , V_242 ) ) < 0 )
goto V_264;
V_242 = F_133 ( & V_284 , V_9 ) ;
if ( V_242 == NULL ) {
V_98 = - V_102 ;
goto V_264;
}
V_242 -> V_151 . V_281 = V_48 ;
V_242 -> V_151 . V_12 = V_253 ;
if ( ( V_98 = F_132 ( V_148 , V_242 ) ) < 0 )
goto V_264;
V_9 -> V_150 = V_242 ;
}
V_98 = 0 ;
goto V_264;
V_273:
V_98 = - V_102 ;
V_264:
F_134 ( V_256 ) ;
return V_98 ;
}
static unsigned char F_135 ( struct V_285 * V_285 )
{
struct V_8 * V_286 = F_136 ( V_285 ) ;
if ( F_126 ( ! V_286 ) )
return 0 ;
return F_96 ( F_4 ( V_286 , V_287 ) ) ;
}
static void F_137 ( struct V_285 * V_285 )
{
struct V_8 * V_286 = F_136 ( V_285 ) ;
if ( F_126 ( ! V_286 ) )
return;
F_20 ( 0xff , F_4 ( V_286 , V_287 ) ) ;
}
static int F_138 ( struct V_285 * V_285 , int * V_288 , int * V_289 )
{
struct V_8 * V_286 = F_136 ( V_285 ) ;
int V_290 ;
if ( F_126 ( ! V_286 ) )
return 0 ;
* V_289 = ( ~ F_96 ( F_4 ( V_286 , V_287 ) ) >> 4 ) & 0xf ;
for ( V_290 = 0 ; V_290 < 4 ; V_290 ++ ) {
V_288 [ V_290 ] = F_9 ( F_4 ( V_286 , V_291 + V_290 * 2 ) ) ;
if ( V_288 [ V_290 ] == 0xffff ) V_288 [ V_290 ] = - 1 ;
}
return 0 ;
}
static int F_139 ( struct V_285 * V_285 , int V_292 )
{
struct V_8 * V_286 = F_136 ( V_285 ) ;
if ( F_126 ( ! V_286 ) )
return 0 ;
switch ( V_292 ) {
case V_293 :
F_20 ( V_294 , F_4 ( V_286 , V_295 ) ) ;
F_140 ( 20 ) ;
return 0 ;
case V_296 :
F_20 ( 0 , F_4 ( V_286 , V_295 ) ) ;
return 0 ;
default:
return - 1 ;
}
}
int F_141 ( struct V_8 * V_286 )
{
struct V_285 * V_297 ;
V_286 -> V_285 = V_297 = F_142 () ;
if ( ! V_297 ) {
F_143 ( V_27 L_11 ) ;
return - V_102 ;
}
F_144 ( V_297 , L_3 ) ;
F_145 ( V_297 , L_12 , F_146 ( V_286 -> V_215 ) ) ;
F_147 ( V_297 , & V_286 -> V_215 -> V_298 ) ;
F_148 ( V_297 , V_286 ) ;
V_297 -> V_299 = 64 ;
V_297 -> V_261 = F_135 ;
V_297 -> V_300 = F_137 ;
V_297 -> V_301 = F_138 ;
V_297 -> V_302 = F_139 ;
F_149 ( V_297 ) ;
return 0 ;
}
static inline void F_150 ( struct V_8 * V_286 )
{
if ( V_286 -> V_285 ) {
F_151 ( V_286 -> V_285 ) ;
V_286 -> V_285 = NULL ;
}
}
int F_141 ( struct V_8 * V_286 ) { return - V_303 ; }
static inline void F_150 ( struct V_8 * V_286 ) { }
static inline void F_152 ( struct V_8 * V_286 )
{
F_153 ( 1 ) ;
}
static int F_131 ( struct V_8 * V_9 )
{
unsigned long V_304 ;
unsigned int V_290 ;
int V_305 ;
V_305 = V_9 -> V_306 ? 0 : 2 ;
V_307:
F_154 ( V_9 -> V_215 , 0x46 , 0x04 ) ;
F_155 ( 100 ) ;
F_154 ( V_9 -> V_215 , 0x46 , 0x00 ) ;
F_155 ( 100 ) ;
F_20 ( 0x00 , F_4 ( V_9 , V_308 ) ) ;
V_290 = V_309 | V_310 | V_311 | V_312 | V_313 | V_314 ;
F_3 ( V_290 , F_4 ( V_9 , V_161 ) ) ;
F_155 ( 1000 ) ;
V_290 &= ~ V_314 ;
F_3 ( V_290 , F_4 ( V_9 , V_161 ) ) ;
F_155 ( 2000 ) ;
V_304 = ( V_315 + ( V_316 * 3 ) / 4 ) + 1 ;
do {
if ( ( F_5 ( F_4 ( V_9 , V_161 ) ) & V_267 ) != 0 )
goto V_317;
F_152 ( V_9 ) ;
} while ( F_156 ( V_304 , V_315 ) );
F_6 ( V_27 L_13 , F_5 ( F_4 ( V_9 , V_161 ) ) ) ;
if ( V_305 -- > 0 ) {
V_304 = V_315 + V_316 ;
do {
F_152 ( V_9 ) ;
} while ( F_156 ( V_304 , V_315 ) );
goto V_307;
}
V_317:
do {
if ( ( F_5 ( F_4 ( V_9 , V_161 ) ) & V_318 ) != 0 )
break;
F_152 ( V_9 ) ;
} while ( F_156 ( V_304 , V_315 ) );
F_3 ( V_40 , F_4 ( V_9 , V_37 ) ) ;
return 0 ;
}
static void F_157 ( struct V_319 * V_320 ,
struct V_321 * V_322 )
{
struct V_8 * V_9 = V_320 -> V_10 ;
char * V_163 ;
switch ( V_9 -> V_12 ) {
case V_21 :
V_163 = L_14 ;
break;
case V_13 :
V_163 = L_15 ;
break;
case V_16 :
V_163 = L_16 ;
break;
default:
V_163 = L_17 ;
}
F_158 ( V_322 , L_18 , V_163 ) ;
F_158 ( V_322 , L_19 , V_9 -> V_323 ) ;
F_158 ( V_322 , L_20 , V_9 -> V_324 ) ;
if ( V_9 -> V_12 == V_16 || V_9 -> V_12 == V_21 )
F_158 ( V_322 , L_21 , V_9 -> V_196 == 0x28 ? L_22 : L_23 ) ;
if ( V_9 -> V_12 == V_16 ) {
F_158 ( V_322 , L_24 , V_9 -> V_234 & 0x00000010 ? L_22 : L_23 ) ;
if ( V_9 -> V_99 . V_100 ) {
F_158 ( V_322 , L_25 ) ;
F_158 ( V_322 , L_26 , V_9 -> V_99 . V_325 -> V_326 ) ;
F_158 ( V_322 , L_27 , V_9 -> V_99 . V_325 -> V_327 ) ;
F_158 ( V_322 , L_28 , F_159 ( V_9 -> V_99 . V_325 ) ) ;
}
}
}
static void F_160 ( struct V_8 * V_9 )
{
struct V_319 * V_320 ;
const char * V_163 = L_29 ;
if ( V_9 -> V_12 == V_21 )
V_163 = L_30 ;
if ( ! F_161 ( V_9 -> V_148 , V_163 , & V_320 ) )
F_162 ( V_320 , V_9 , F_157 ) ;
}
static int F_163 ( struct V_328 * V_12 )
{
struct V_8 * V_9 = V_12 -> V_329 ;
return F_164 ( V_9 ) ;
}
static int F_165 ( struct V_8 * V_9 )
{
int V_290 ;
if ( F_166 ( V_216 , F_89 ( V_9 -> V_215 ) ,
2 * V_330 * 4 , & V_9 -> V_99 . V_322 ) < 0 ) {
F_6 ( V_27 L_31 ) ;
return - V_102 ;
}
V_9 -> V_99 . V_100 = ( unsigned int * ) F_167 ( ( unsigned long ) V_9 -> V_99 . V_322 . V_331 , V_330 * 4 ) ;
V_9 -> V_99 . V_332 = F_167 ( V_9 -> V_99 . V_322 . V_333 , V_330 * 4 ) ;
V_9 -> V_99 . V_334 = F_168 ( V_330 *sizeof( unsigned long ) ) ;
if ( V_9 -> V_99 . V_334 == NULL ) {
F_6 ( V_27 L_32 ) ;
return - V_102 ;
}
if ( F_166 ( V_216 , F_89 ( V_9 -> V_215 ) ,
V_335 , & V_9 -> V_99 . V_336 ) < 0 ) {
F_6 ( V_27 L_33 ) ;
return - V_102 ;
}
memset ( V_9 -> V_99 . V_336 . V_331 , 0 , V_335 ) ;
for ( V_290 = 0 ; V_290 < V_330 ; V_290 ++ ) {
V_9 -> V_99 . V_100 [ V_290 ] = F_169 ( V_9 -> V_99 . V_336 . V_333 & ~ ( V_335 - 1 ) ) ;
V_9 -> V_99 . V_334 [ V_290 ] = ( unsigned long ) V_9 -> V_99 . V_336 . V_331 ;
}
V_9 -> V_99 . V_325 = F_170 ( V_335 * V_330 ) ;
if ( V_9 -> V_99 . V_325 == NULL )
return - V_102 ;
V_9 -> V_99 . V_325 -> V_337 = sizeof( struct V_338 ) ;
return 0 ;
}
static void F_171 ( struct V_8 * V_9 )
{
F_3 ( 0xffffffff , F_4 ( V_9 , V_47 ) ) ;
F_3 ( 0xffffffff , F_4 ( V_9 , V_46 ) ) ;
F_3 ( 0 , F_4 ( V_9 , V_339 ) ) ;
F_3 ( 0 , F_4 ( V_9 , V_181 ) ) ;
}
static int F_172 ( struct V_8 * V_9 )
{
struct V_340 * V_215 = V_9 -> V_215 ;
unsigned long V_304 ;
F_173 ( V_215 , 0x40 , 0 ) ;
F_154 ( V_215 , 0x44 , 0 ) ;
F_154 ( V_215 , 0x45 , 0 ) ;
F_154 ( V_215 , 0x46 , 4 ) ;
F_155 ( 100 ) ;
F_154 ( V_215 , 0x46 , 0 ) ;
F_155 ( 100 ) ;
F_3 ( 0x00000001 , F_4 ( V_9 , V_341 ) ) ;
F_155 ( 100 ) ;
F_3 ( 0x00000000 , F_4 ( V_9 , V_341 ) ) ;
V_9 -> V_234 = 0x0000004a ;
F_3 ( V_9 -> V_234 , F_4 ( V_9 , V_341 ) ) ;
V_304 = ( V_315 + ( V_316 * 3 ) / 4 ) + 1 ;
do {
if ( ( F_5 ( F_4 ( V_9 , V_341 ) ) & 0x0010 ) != 0 )
goto V_342;
F_152 ( V_9 ) ;
} while ( F_156 ( V_304 , V_315 ) );
F_6 ( V_27 L_34 ) ;
return - V_266 ;
V_342:
F_171 ( V_9 ) ;
return 0 ;
}
static int F_174 ( struct V_8 * V_9 )
{
struct V_340 * V_215 = V_9 -> V_215 ;
unsigned long V_304 ;
F_173 ( V_215 , 0x40 , 0 ) ;
F_154 ( V_215 , 0x44 , 0 ) ;
F_154 ( V_215 , 0x45 , 0 ) ;
F_154 ( V_215 , 0x46 , 1 ) ;
F_155 ( 100 ) ;
F_154 ( V_215 , 0x46 , 0 ) ;
F_155 ( 100 ) ;
F_3 ( 0x00000001 , F_4 ( V_9 , V_235 ) ) ;
F_155 ( 100 ) ;
F_3 ( 0x00000000 , F_4 ( V_9 , V_235 ) ) ;
V_304 = ( V_315 + ( V_316 * 3 ) / 4 ) + 1 ;
do {
if ( ( F_5 ( F_4 ( V_9 , V_235 ) ) & 0x0008 ) != 0 )
goto V_343;
F_152 ( V_9 ) ;
} while ( F_156 ( V_304 , V_315 ) );
F_6 ( V_27 L_13 , F_5 ( F_4 ( V_9 , V_235 ) ) ) ;
return - V_266 ;
V_343:
V_9 -> V_234 = 0x00000002 ;
F_3 ( V_9 -> V_234 , F_4 ( V_9 , V_235 ) ) ;
F_3 ( V_344 , F_4 ( V_9 , V_345 ) ) ;
F_171 ( V_9 ) ;
if ( V_9 -> V_99 . V_100 != NULL ) {
unsigned int V_290 ;
V_290 = V_9 -> V_99 . V_332 ;
V_290 |= 0x00000001 ;
F_3 ( V_290 , F_4 ( V_9 , V_346 ) ) ;
} else {
F_3 ( 0 , F_4 ( V_9 , V_346 ) ) ;
}
F_3 ( V_9 -> V_141 , F_4 ( V_9 , V_159 ) ) ;
F_20 ( V_9 -> V_196 , F_4 ( V_9 , V_158 + 3 ) ) ;
return 0 ;
}
static int F_175 ( struct V_8 * V_9 )
{
int V_98 ;
if ( ( V_98 = F_131 ( V_9 ) ) < 0 )
return V_98 ;
F_171 ( V_9 ) ;
F_3 ( V_9 -> V_141 , F_4 ( V_9 , V_160 ) ) ;
return 0 ;
}
int F_176 ( struct V_241 * V_148 ,
struct V_340 * V_215 ,
int V_347 ,
int V_253 ,
int V_348 ,
struct V_8 * * V_349 )
{
struct V_8 * V_9 ;
int V_290 , V_98 ;
struct V_57 * V_42 ;
struct V_106 * V_245 ;
static struct V_350 V_259 = {
. V_351 = F_163 ,
} ;
* V_349 = NULL ;
if ( ( V_98 = F_177 ( V_215 ) ) < 0 )
return V_98 ;
if ( F_178 ( V_215 , F_179 ( 30 ) ) < 0 ||
F_180 ( V_215 , F_179 ( 30 ) ) < 0 ) {
F_6 ( V_27 L_35 ) ;
F_181 ( V_215 ) ;
return - V_352 ;
}
V_9 = F_128 ( sizeof( * V_9 ) , V_262 ) ;
if ( V_9 == NULL ) {
F_181 ( V_215 ) ;
return - V_102 ;
}
V_9 -> V_12 = ( V_215 -> V_353 << 16 ) | V_215 -> V_12 ;
V_9 -> V_148 = V_148 ;
V_9 -> V_215 = V_215 ;
F_182 ( & V_9 -> V_11 ) ;
F_182 ( & V_9 -> V_354 ) ;
F_182 ( & V_9 -> V_355 ) ;
if ( V_347 < 1 )
V_347 = 1 ;
if ( V_347 > 32 )
V_347 = 32 ;
V_9 -> V_50 = V_347 ;
if ( V_348 < 0 )
V_348 = 0 ;
V_9 -> V_55 . V_356 = V_348 * 1024 ;
V_9 -> V_357 = - 1 ;
V_9 -> V_358 = F_4 ( V_9 , V_359 ) ;
F_183 ( V_215 ) ;
if ( ( V_98 = F_184 ( V_215 , L_36 ) ) < 0 ) {
F_134 ( V_9 ) ;
F_181 ( V_215 ) ;
return V_98 ;
}
V_9 -> V_360 = F_185 ( V_215 , 0 ) ;
if ( F_186 ( V_215 -> V_357 , V_361 , V_362 ,
V_363 , V_9 ) ) {
F_6 ( V_27 L_37 , V_215 -> V_357 ) ;
F_164 ( V_9 ) ;
return - V_364 ;
}
V_9 -> V_357 = V_215 -> V_357 ;
V_9 -> V_99 . V_100 = NULL ;
V_9 -> V_99 . V_322 . V_331 = NULL ;
if ( V_9 -> V_12 == V_16 ) {
if ( ( V_98 = F_165 ( V_9 ) ) < 0 ) {
F_164 ( V_9 ) ;
return V_98 ;
}
}
V_9 -> V_141 = V_9 -> V_136 = V_365 ;
switch ( V_9 -> V_12 ) {
case V_13 :
V_98 = F_172 ( V_9 ) ;
break;
case V_16 :
V_98 = F_174 ( V_9 ) ;
break;
case V_21 :
V_98 = F_175 ( V_9 ) ;
break;
default:
F_19 () ;
break;
}
if ( V_98 < 0 ) {
F_164 ( V_9 ) ;
return V_98 ;
}
if ( ( V_98 = F_187 ( V_148 , V_366 , V_9 , & V_259 ) ) < 0 ) {
F_164 ( V_9 ) ;
return V_98 ;
}
if ( ( V_98 = F_127 ( V_9 , V_253 ) ) < 0 )
return V_98 ;
for ( V_290 = 0 ; V_290 < 64 ; V_290 ++ ) {
V_42 = & V_9 -> V_55 . V_367 [ V_290 ] ;
V_42 -> V_67 = V_290 ;
V_42 -> V_9 = V_9 ;
}
for ( V_290 = 0 ; V_290 < 32 ; V_290 ++ ) {
V_245 = & V_9 -> V_108 [ V_290 ] ;
V_245 -> V_113 = V_250 ;
V_245 -> V_116 = V_131 ;
V_245 -> V_114 = V_251 ;
V_245 -> V_115 = V_252 ;
}
F_10 ( V_9 ) ;
F_160 ( V_9 ) ;
F_188 ( V_148 , & V_215 -> V_298 ) ;
* V_349 = V_9 ;
return 0 ;
}
static int F_164 ( struct V_8 * V_9 )
{
F_150 ( V_9 ) ;
F_11 ( V_9 ) ;
if ( V_9 -> V_12 == V_16 )
F_20 ( 0x00 , F_4 ( V_9 , V_158 + 3 ) ) ;
else if ( V_9 -> V_12 == V_21 ) {
F_3 ( 0 , F_4 ( V_9 , V_161 ) ) ;
}
if ( V_9 -> V_357 >= 0 )
F_189 ( V_9 -> V_357 , V_9 ) ;
if ( V_9 -> V_99 . V_322 . V_331 ) {
F_3 ( 0 , F_4 ( V_9 , V_346 ) ) ;
if ( V_9 -> V_99 . V_325 )
F_190 ( V_9 -> V_99 . V_325 ) ;
if ( V_9 -> V_99 . V_336 . V_331 )
F_191 ( & V_9 -> V_99 . V_336 ) ;
F_192 ( V_9 -> V_99 . V_334 ) ;
F_191 ( & V_9 -> V_99 . V_322 ) ;
}
F_193 ( V_9 -> V_215 ) ;
F_181 ( V_9 -> V_215 ) ;
F_134 ( V_9 ) ;
return 0 ;
}
static T_2 V_361 ( int V_357 , void * V_368 )
{
struct V_8 * V_9 = V_368 ;
unsigned int V_369 , V_370 , V_177 , V_53 , V_43 , V_41 ;
int V_85 ;
struct V_57 * V_42 ;
V_369 = F_5 ( F_4 ( V_9 , V_345 ) ) ;
if ( ( V_369 & ( V_371 | V_372 ) ) == 0 )
return V_373 ;
if ( V_369 & V_371 ) {
F_65 ( & V_9 -> V_11 ) ;
V_177 = F_5 ( F_4 ( V_9 , V_176 ) ) & 0x00ffffff ;
V_370 = F_5 ( F_4 ( V_9 , V_374 ) ) ;
if ( V_370 == 0 )
goto V_375;
F_3 ( V_370 , F_4 ( V_9 , V_374 ) ) ;
V_375:
V_370 = F_5 ( F_4 ( V_9 , V_376 ) ) ;
if ( V_370 == 0 )
goto V_377;
for ( V_53 = 63 ; V_53 >= 32 ; V_53 -- ) {
V_43 = 1 << ( V_53 & 0x1f ) ;
if ( ( V_370 & V_43 ) == 0 )
continue;
V_42 = & V_9 -> V_55 . V_367 [ V_53 ] ;
if ( ! V_42 -> V_201 || V_42 -> V_89 == NULL ) {
F_3 ( V_43 , F_4 ( V_9 , V_46 ) ) ;
continue;
}
V_85 = ( int ) V_177 - ( int ) V_42 -> V_177 ;
if ( V_85 < 0 )
V_85 = - V_85 ;
if ( ( unsigned int ) V_85 < V_42 -> V_109 ) {
V_9 -> V_323 ++ ;
if ( V_9 -> V_324 < ( unsigned int ) V_85 )
V_9 -> V_324 = V_85 ;
continue;
}
V_42 -> V_177 = V_177 ;
if ( V_42 -> V_128 ) {
if ( ! V_42 -> V_155 ) {
V_41 = F_9 ( F_4 ( V_9 , V_126 ) ) ;
if ( V_9 -> V_127 & 0x40 )
V_41 >>= 1 ;
if ( V_41 > 0 )
V_41 = V_42 -> V_129 - V_41 ;
} else {
V_41 = F_5 ( F_4 ( V_9 , V_158 ) ) & 0x00ffffff ;
}
if ( V_41 < V_42 -> V_118 ) {
if ( V_41 > 0x10 )
V_41 = V_42 -> V_130 - 7 ;
else
V_41 = V_42 -> V_130 + 2 ;
F_13 ( V_9 , V_42 -> V_67 ) ;
F_23 ( V_9 , V_42 , V_41 ) ;
F_12 ( V_9 , V_42 -> V_67 ) ;
}
} else if ( V_42 -> V_117 ) {
V_42 -> V_117 = 0 ;
F_13 ( V_9 , V_42 -> V_67 ) ;
F_21 ( V_9 , V_42 , V_42 -> V_118 ) ;
F_23 ( V_9 , V_42 , V_42 -> V_73 ) ;
F_12 ( V_9 , V_42 -> V_67 ) ;
}
#if 0
if (voice->extra) {
snd_trident_stop_voice(trident, voice->extra->number);
snd_trident_write_cso_reg(trident, voice->extra, 0);
snd_trident_start_voice(trident, voice->extra->number);
}
#endif
F_68 ( & V_9 -> V_11 ) ;
F_194 ( V_42 -> V_89 ) ;
F_65 ( & V_9 -> V_11 ) ;
}
F_3 ( V_370 , F_4 ( V_9 , V_376 ) ) ;
V_377:
F_68 ( & V_9 -> V_11 ) ;
}
if ( V_369 & V_372 ) {
if ( V_9 -> V_378 ) {
F_195 ( V_357 , V_9 -> V_378 -> V_10 ) ;
} else {
F_96 ( F_4 ( V_9 , V_379 ) ) ;
}
}
return V_380 ;
}
struct V_57 * F_45 ( struct V_8 * V_9 , int type , int V_381 , int V_360 )
{
struct V_57 * V_382 ;
unsigned long V_7 ;
int V_48 ;
F_2 ( & V_9 -> V_355 , V_7 ) ;
if ( type == V_105 ) {
V_48 = F_14 ( V_9 ) ;
if( V_48 < 0 ) {
F_7 ( & V_9 -> V_355 , V_7 ) ;
return NULL ;
}
V_382 = & V_9 -> V_55 . V_367 [ V_48 ] ;
V_382 -> V_383 = 1 ;
V_382 -> V_201 = 1 ;
V_382 -> V_179 = 0 ;
V_382 -> V_180 = 0 ;
V_382 -> V_101 = NULL ;
V_382 -> V_89 = NULL ;
F_7 ( & V_9 -> V_355 , V_7 ) ;
return V_382 ;
}
if ( type == V_384 ) {
V_48 = F_16 ( V_9 ) ;
if( V_48 < 0 ) {
F_7 ( & V_9 -> V_355 , V_7 ) ;
return NULL ;
}
V_382 = & V_9 -> V_55 . V_367 [ V_48 ] ;
V_382 -> V_383 = 1 ;
V_382 -> V_55 = 1 ;
V_382 -> V_381 = V_381 ;
V_382 -> V_360 = V_360 ;
V_382 -> V_101 = NULL ;
F_7 ( & V_9 -> V_355 , V_7 ) ;
return V_382 ;
}
if ( type == V_385 ) {
}
F_7 ( & V_9 -> V_355 , V_7 ) ;
return NULL ;
}
void F_46 ( struct V_8 * V_9 , struct V_57 * V_42 )
{
unsigned long V_7 ;
void (* V_186)( struct V_57 * );
void * V_10 ;
if ( V_42 == NULL || ! V_42 -> V_383 )
return;
F_196 ( V_9 , V_42 -> V_67 , V_42 -> V_67 ) ;
F_2 ( & V_9 -> V_355 , V_7 ) ;
V_186 = V_42 -> V_186 ;
V_10 = V_42 -> V_10 ;
V_42 -> V_186 = NULL ;
V_42 -> V_10 = NULL ;
if ( V_42 -> V_201 )
F_15 ( V_9 , V_42 -> V_67 ) ;
if ( V_42 -> V_55 )
F_17 ( V_9 , V_42 -> V_67 ) ;
V_42 -> V_383 = V_42 -> V_201 = V_42 -> V_55 = V_42 -> V_386 = 0 ;
V_42 -> V_179 = V_42 -> V_180 = 0 ;
V_42 -> V_387 = NULL ;
V_42 -> V_89 = NULL ;
V_42 -> V_104 = NULL ;
F_7 ( & V_9 -> V_355 , V_7 ) ;
if ( V_186 )
V_186 ( V_42 ) ;
}
static void F_196 ( struct V_8 * V_9 , unsigned short V_388 , unsigned short V_389 )
{
unsigned int V_290 , V_36 , V_43 [ 2 ] = { 0 , 0 } ;
if ( F_126 ( V_388 > 63 || V_389 > 63 ) )
return;
for ( V_290 = V_388 ; V_290 <= V_389 ; V_290 ++ )
V_43 [ V_290 >> 5 ] |= 1 << ( V_290 & 0x1f ) ;
if ( V_43 [ 0 ] ) {
F_3 ( V_43 [ 0 ] , F_4 ( V_9 , V_47 ) ) ;
V_36 = F_5 ( F_4 ( V_9 , V_339 ) ) ;
F_3 ( V_36 & ~ V_43 [ 0 ] , F_4 ( V_9 , V_339 ) ) ;
}
if ( V_43 [ 1 ] ) {
F_3 ( V_43 [ 1 ] , F_4 ( V_9 , V_46 ) ) ;
V_36 = F_5 ( F_4 ( V_9 , V_181 ) ) ;
F_3 ( V_36 & ~ V_43 [ 1 ] , F_4 ( V_9 , V_181 ) ) ;
}
}
static int F_197 ( struct V_12 * V_298 )
{
struct V_340 * V_215 = F_198 ( V_298 ) ;
struct V_241 * V_148 = F_199 ( V_298 ) ;
struct V_8 * V_9 = V_148 -> V_10 ;
V_9 -> V_306 = 1 ;
F_200 ( V_148 , V_390 ) ;
F_201 ( V_9 -> V_201 ) ;
F_201 ( V_9 -> V_217 ) ;
F_201 ( V_9 -> V_180 ) ;
F_202 ( V_9 -> V_2 ) ;
F_202 ( V_9 -> V_268 ) ;
F_181 ( V_215 ) ;
F_203 ( V_215 ) ;
F_204 ( V_215 , V_391 ) ;
return 0 ;
}
static int F_205 ( struct V_12 * V_298 )
{
struct V_340 * V_215 = F_198 ( V_298 ) ;
struct V_241 * V_148 = F_199 ( V_298 ) ;
struct V_8 * V_9 = V_148 -> V_10 ;
F_204 ( V_215 , V_392 ) ;
F_206 ( V_215 ) ;
if ( F_177 ( V_215 ) < 0 ) {
F_143 ( V_27 L_38
L_39 ) ;
F_207 ( V_148 ) ;
return - V_266 ;
}
F_183 ( V_215 ) ;
switch ( V_9 -> V_12 ) {
case V_13 :
F_172 ( V_9 ) ;
break;
case V_16 :
F_174 ( V_9 ) ;
break;
case V_21 :
F_175 ( V_9 ) ;
break;
}
F_208 ( V_9 -> V_2 ) ;
F_208 ( V_9 -> V_268 ) ;
F_3 ( V_9 -> V_239 , F_4 ( V_9 , V_240 ) ) ;
F_10 ( V_9 ) ;
F_200 ( V_148 , V_393 ) ;
V_9 -> V_306 = 0 ;
return 0 ;
}
