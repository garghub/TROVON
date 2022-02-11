static inline unsigned short F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 + 0xc008 ) ;
}
static inline unsigned short F_3 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 + 0xc00a ) ;
}
static inline void F_4 ( struct V_1 * V_2 , unsigned short V_4 )
{
F_5 ( V_4 , V_2 -> V_3 + 0xc00a ) ;
}
static inline void F_6 ( struct V_1 * V_2 , unsigned short V_5 )
{
F_5 ( V_5 , V_2 -> V_3 + 0xc00c ) ;
}
static inline void F_7 ( struct V_1 * V_2 , unsigned short V_5 )
{
F_5 ( V_5 , V_2 -> V_3 + 0xc00e ) ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
F_9 ( F_10 ( V_2 -> V_3 + V_6 ) | 2 , V_2 -> V_3 + V_6 ) ;
}
static inline void F_11 ( struct V_1 * V_2 )
{
F_9 ( F_10 ( V_2 -> V_3 + V_6 ) & ~ 2 , V_2 -> V_3 + V_6 ) ;
}
static inline unsigned short int F_12 ( short int V_7 )
{
V_7 &= 0x1f ;
if ( V_7 > 0xf ) V_7 += 0x3ff0 ;
return V_7 + 0x4000 ;
}
static int T_1 F_13 ( struct V_1 * V_2 )
{
unsigned short * V_8 ;
static unsigned short V_9 [] = { 0x240 , 0x300 , 0x310 , 0x270 , 0x320 , 0x340 , 0 } ;
unsigned short V_10 = V_2 -> V_3 ;
int V_11 = V_2 -> V_12 ;
int V_13 ;
V_2 -> V_14 = 0xff ;
if ( V_10 & 0xfe00 ) {
if ( ! F_14 ( V_10 , V_15 , L_1 ) )
return - V_16 ;
V_13 = F_15 ( V_2 , V_10 ) ;
F_16 ( V_10 , V_15 ) ;
return V_13 ;
} else if ( V_10 )
return - V_17 ;
for ( V_8 = & V_9 [ 0 ] ; * V_8 ; V_8 ++ )
{
unsigned short V_18 = 0 ;
int V_19 ;
if ( ! F_14 ( * V_8 , V_15 , L_1 ) )
continue;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ )
{
unsigned short V_20 ;
V_20 = F_10 ( * V_8 + V_21 ) ;
V_18 |= ( V_20 >> 4 ) << ( ( V_20 & 0x03 ) << 2 ) ;
}
if ( V_18 == 0xbaba && ! F_15 ( V_2 , * V_8 ) ) {
F_16 ( * V_8 , V_15 ) ;
return 0 ;
}
F_16 ( * V_8 , V_15 ) ;
V_2 -> V_12 = V_11 ;
}
return - V_22 ;
}
struct V_1 * T_1 F_17 ( int V_23 )
{
struct V_1 * V_2 = F_18 ( sizeof( struct V_24 ) ) ;
int V_13 ;
if ( ! V_2 )
return F_19 ( - V_25 ) ;
sprintf ( V_2 -> V_26 , L_2 , V_23 ) ;
F_20 ( V_2 ) ;
V_13 = F_13 ( V_2 ) ;
if ( ! V_13 )
return V_2 ;
F_21 ( V_2 ) ;
return F_19 ( V_13 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_27 ;
unsigned short V_10 = V_2 -> V_3 ;
struct V_24 * V_28 = F_23 ( V_2 ) ;
#if V_29 > 6
F_24 ( V_30 L_3 , V_2 -> V_26 ) ;
#endif
if ( ! V_2 -> V_12 || ! V_31 [ V_2 -> V_12 ] )
return - V_17 ;
V_27 = F_25 ( V_2 -> V_12 , V_32 , 0 , V_2 -> V_26 , V_2 ) ;
if ( V_27 )
return V_27 ;
if ( ! F_14 ( V_10 , V_15 , L_1 ) ) {
F_24 ( V_33 L_4
, V_10 ) ;
goto V_34;
}
if ( ! F_14 ( V_10 + 0x4000 , V_15 , L_5 ) ) {
F_24 ( V_33 L_4
, V_10 + 0x4000 ) ;
goto V_35;
}
if ( ! F_14 ( V_10 + 0x8000 , V_15 , L_5 ) ) {
F_24 ( V_33 L_4
, V_10 + 0x8000 ) ;
goto V_36;
}
if ( ! F_14 ( V_10 + 0xc000 , V_15 , L_5 ) ) {
F_24 ( V_33 L_4
, V_10 + 0xc000 ) ;
goto V_37;
}
if ( V_28 -> V_38 ) {
F_24 ( L_6 , V_2 -> V_26 ) ;
F_9 ( F_10 ( V_2 -> V_3 + V_6 ) & ~ 4 , V_2 -> V_3 + V_6 ) ;
}
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
#if V_29 > 6
F_24 ( V_30 L_7 , V_2 -> V_26 ) ;
#endif
return 0 ;
V_37:
F_16 ( V_10 + 0x8000 , V_15 ) ;
V_36:
F_16 ( V_10 + 0x4000 , V_15 ) ;
V_35:
F_16 ( V_10 , V_15 ) ;
V_34:
F_28 ( V_2 -> V_12 , V_2 ) ;
return - V_16 ;
}
static int F_29 ( struct V_1 * V_2 )
{
unsigned short V_10 = V_2 -> V_3 ;
struct V_24 * V_28 = F_23 ( V_2 ) ;
int V_12 = V_2 -> V_12 ;
F_30 ( V_2 ) ;
F_9 ( V_39 | V_31 [ V_12 ] , V_10 + V_40 ) ;
V_28 -> V_41 = 0 ;
F_4 ( V_2 , V_42 | V_43 ) ;
F_9 ( 0 , V_10 + V_44 ) ;
F_28 ( V_12 , V_2 ) ;
F_9 ( V_45 , V_10 + V_46 ) ;
F_16 ( V_10 , V_15 ) ;
F_16 ( V_10 + 0x4000 , 16 ) ;
F_16 ( V_10 + 0x8000 , 16 ) ;
F_16 ( V_10 + 0xc000 , 16 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_24 * V_28 = F_23 ( V_2 ) ;
unsigned short V_10 = V_2 -> V_3 ;
if ( V_28 -> V_41 )
{
if ( F_32 ( V_47 , F_33 ( V_2 ) + V_48 / 2 ) )
{
if ( V_28 -> V_49 == V_28 -> V_50 )
{
unsigned short V_51 = 200 , V_52 ;
F_24 ( V_33 L_8 ,
V_2 -> V_26 , F_1 ( V_2 ) ) ;
F_34 ( V_2 ) ;
V_28 -> V_50 = 0 ;
F_6 ( V_2 , V_28 -> V_49 ) ;
F_4 ( V_2 , V_53 ) ;
F_9 ( 0 , V_10 + V_44 ) ;
while ( ! F_35 ( V_52 = F_1 ( V_2 ) ) )
{
if ( ! -- V_51 )
{
V_51 = 200 ;
F_24 ( V_33 L_9 ,
V_2 -> V_26 , V_52 ) ;
F_6 ( V_2 , V_28 -> V_49 ) ;
F_4 ( V_2 , V_53 ) ;
F_9 ( 0 , V_10 + V_44 ) ;
}
}
F_36 ( V_2 ) ;
}
else
{
unsigned short V_54 = F_1 ( V_2 ) ;
if ( F_37 ( V_54 ) )
{
unsigned short V_55 = F_38 ( V_2 ) ;
F_24 ( V_33 L_10 ,
V_2 -> V_26 , V_54 , V_55 ) ;
F_39 ( V_2 ) ;
}
else
{
unsigned short V_55 = F_38 ( V_2 ) ;
if ( F_40 ( V_2 ) && ! V_55 )
{
F_24 ( V_33 L_11 ,
V_2 -> V_26 , V_54 , V_55 ) ;
F_26 ( V_2 ) ;
F_36 ( V_2 ) ;
}
else
{
F_24 ( V_33 L_12 , V_2 -> V_26 ) ;
}
}
}
}
}
else
{
if ( F_32 ( V_47 , V_28 -> V_56 + 10 ) )
{
unsigned short V_54 = F_1 ( V_2 ) ;
F_24 ( V_33 L_13 ,
V_2 -> V_26 , V_54 ) ;
F_26 ( V_2 ) ;
F_36 ( V_2 ) ;
}
}
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_24 * V_28 = F_23 ( V_2 ) ;
#ifdef F_42
unsigned long V_57 ;
#endif
int V_54 ;
F_43 ( V_2 -> V_12 ) ;
#ifdef F_42
F_44 ( & V_28 -> V_58 , V_57 ) ;
#endif
V_54 = F_1 ( V_2 ) ;
F_31 ( V_2 ) ;
F_24 ( V_59 L_14 , V_2 -> V_26 ,
( F_35 ( V_54 ) ? L_15 :
L_16 ) ) ;
V_2 -> V_60 . V_61 ++ ;
V_28 -> V_62 = V_47 ;
if ( ! F_35 ( V_54 ) ) {
F_4 ( V_2 , V_63 ) ;
F_9 ( 0 , V_2 -> V_3 + V_44 ) ;
}
F_36 ( V_2 ) ;
#ifdef F_42
F_45 ( & V_28 -> V_58 , V_57 ) ;
#endif
}
static T_2 F_46 ( struct V_64 * V_65 , struct V_1 * V_2 )
{
short V_66 = V_65 -> V_67 ;
#ifdef F_42
struct V_24 * V_28 = F_23 ( V_2 ) ;
unsigned long V_57 ;
#endif
#if V_29 > 6
F_24 ( V_30 L_17 , V_2 -> V_26 ) ;
#endif
if ( V_65 -> V_67 < V_68 ) {
if ( F_47 ( V_65 , V_68 ) )
return V_69 ;
V_66 = V_68 ;
}
F_43 ( V_2 -> V_12 ) ;
#ifdef F_42
F_44 ( & V_28 -> V_58 , V_57 ) ;
#endif
{
unsigned short * V_70 = ( unsigned short * ) V_65 -> V_70 ;
V_2 -> V_60 . V_71 += V_66 ;
F_48 ( V_2 , V_70 , V_66 ) ;
}
F_49 ( V_65 ) ;
#ifdef F_42
F_45 ( & V_28 -> V_58 , V_57 ) ;
#endif
F_50 ( V_2 -> V_12 ) ;
return V_69 ;
}
static unsigned short F_51 ( struct V_1 * V_2 ,
unsigned short V_54 )
{
unsigned short V_72 = F_52 ( V_54 ) ;
struct V_24 * V_28 = F_23 ( V_2 ) ;
unsigned short V_10 = V_2 -> V_3 ;
if ( ( V_2 -> V_57 & V_73 ) && ! ( V_28 -> V_41 & V_74 ) ) {
short V_75 , V_76 ;
while ( F_53 ( V_54 ) == 2 )
V_54 = F_1 ( V_2 ) ;
#if V_29 > 4
F_24 ( L_18 ,
V_2 -> V_26 , V_54 ) ;
#endif
F_5 ( V_77 & ~ 31 , V_10 + V_78 ) ;
V_75 = F_2 ( V_10 + F_12 ( V_77 ) ) ;
if ( V_75 & 1 << 11 ) {
F_24 ( V_33 L_19 ,
V_2 -> V_26 ) ;
} else if ( ! ( V_75 & 1 << 13 ) ) {
F_24 ( V_33 L_20 , V_2 -> V_26 ) ;
}
F_5 ( V_79 & ~ 31 , V_10 + V_78 ) ;
V_76 = F_2 ( V_10 + F_12 ( V_79 ) ) ;
if ( V_76 & ( V_80 | V_81 ) ) {
F_24 ( V_33 L_21 , V_2 -> V_26 , ( V_76 & V_80 ) ? L_22 : L_23 , V_76 & V_82 , ( ( V_76 & V_82 ) != 1 ) ? L_24 : L_25 ) ;
}
else if ( V_76 & V_83 ) {
F_24 ( V_33 L_26 , V_2 -> V_26 ) ;
}
else if ( V_76 & V_84 ) {
#if V_29 > 4
F_24 ( V_30 L_27 , V_2 -> V_26 ) ;
#endif
} else {
F_24 ( L_28 , V_2 -> V_26 ,
V_76 ) ;
}
V_28 -> V_41 |= V_74 ;
F_6 ( V_2 , V_28 -> V_49 ) ;
if ( ! ( V_28 -> V_41 & V_85 ) ) {
V_72 |= V_86 ;
F_7 ( V_2 , V_28 -> V_87 ) ;
V_28 -> V_88 = V_28 -> V_87 ;
V_28 -> V_41 |= V_85 ;
}
V_72 |= V_53 | 0x2000 ;
}
if ( ( V_2 -> V_57 & V_73 ) && ! ( V_28 -> V_41 & V_85 ) && F_54 ( V_54 ) == 4 )
V_28 -> V_41 |= V_85 ;
return V_72 ;
}
static void F_55 ( struct V_1 * V_2 )
{
unsigned long int V_89 = V_47 ;
while ( F_3 ( V_2 ) && ( F_56 ( V_47 , V_89 + 10 ) ) ) ;
if ( F_3 ( V_2 ) ) {
F_24 ( L_29 , V_2 -> V_26 ) ;
}
}
static T_3 V_32 ( int V_90 , void * V_91 )
{
struct V_1 * V_2 = V_91 ;
struct V_24 * V_28 ;
unsigned short V_10 , V_54 , V_72 ;
unsigned short V_92 , V_93 ;
V_28 = F_23 ( V_2 ) ;
V_10 = V_2 -> V_3 ;
F_57 ( & V_28 -> V_58 ) ;
V_92 = F_2 ( V_10 + V_94 ) ;
V_93 = F_2 ( V_10 + V_95 ) ;
F_9 ( V_39 | V_31 [ V_2 -> V_12 ] , V_10 + V_40 ) ;
V_54 = F_1 ( V_2 ) ;
#if V_29 > 4
F_24 ( V_30 L_30 , V_2 -> V_26 , V_54 ) ;
#endif
if ( V_28 -> V_41 == ( V_74 | V_85 ) ) {
do {
F_55 ( V_2 ) ;
V_72 = F_52 ( V_54 ) ;
F_4 ( V_2 , V_72 ) ;
F_9 ( 0 , V_10 + V_44 ) ;
F_55 ( V_2 ) ;
if ( F_35 ( V_54 ) ) {
if ( ! F_38 ( V_2 ) ) {
F_24 ( L_31 , V_2 -> V_26 ) ;
}
}
if ( F_58 ( V_54 ) )
F_59 ( V_2 ) ;
V_54 = F_1 ( V_2 ) ;
} while ( V_54 & 0xc000 );
if ( F_60 ( V_54 ) )
{
F_24 ( V_33 L_32 ,
V_2 -> V_26 , V_54 ) ;
#if 0
printk(KERN_WARNING "%s: cur_rfd=%04x, cur_rbd=%04x\n", dev->name, lp->cur_rfd, lp->cur_rbd);
outw(lp->cur_rfd, ioaddr+READ_PTR);
printk(KERN_WARNING "%s: [%04x]\n", dev->name, inw(ioaddr+DATAPORT));
outw(lp->cur_rfd+6, ioaddr+READ_PTR);
printk(KERN_WARNING "%s: rbd is %04x\n", dev->name, rbd= inw(ioaddr+DATAPORT));
outw(rbd, ioaddr+READ_PTR);
printk(KERN_WARNING "%s: [%04x %04x] ", dev->name, inw(ioaddr+DATAPORT), inw(ioaddr+DATAPORT));
outw(rbd+8, ioaddr+READ_PTR);
printk("[%04x]\n", inw(ioaddr+DATAPORT));
#endif
V_2 -> V_60 . V_96 ++ ;
#if 1
F_61 ( V_2 ) ;
#else
V_28 -> V_97 = V_28 -> V_98 ;
#endif
F_7 ( V_2 , V_28 -> V_87 ) ;
F_4 ( V_2 , V_86 ) ;
F_9 ( 0 , V_10 + V_44 ) ;
}
} else {
if ( V_54 & 0x8000 )
V_72 = F_51 ( V_2 , V_54 ) ;
else
V_72 = F_52 ( V_54 ) ;
F_4 ( V_2 , V_72 ) ;
F_9 ( 0 , V_10 + V_44 ) ;
}
F_55 ( V_2 ) ;
F_9 ( V_99 | V_31 [ V_2 -> V_12 ] , V_10 + V_40 ) ;
#if V_29 > 6
F_24 ( L_33 , V_2 -> V_26 ) ;
#endif
F_5 ( V_92 , V_10 + V_94 ) ;
F_5 ( V_93 , V_10 + V_95 ) ;
F_62 ( & V_28 -> V_58 ) ;
return V_100 ;
}
static void F_63 ( struct V_1 * V_2 )
{
unsigned char V_101 = F_10 ( V_2 -> V_3 + 0x300e ) ;
V_101 &= ~ 0x82 ;
switch ( V_2 -> V_14 ) {
case V_102 :
V_101 |= 0x2 ;
case V_103 :
V_101 |= 0x80 ;
break;
}
F_9 ( V_101 , V_2 -> V_3 + 0x300e ) ;
F_64 ( 20 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_24 * V_28 = F_23 ( V_2 ) ;
unsigned short V_104 = V_28 -> V_88 ;
unsigned short V_51 = V_28 -> V_105 ;
unsigned short V_10 = V_2 -> V_3 ;
unsigned short V_54 ;
#if V_29 > 6
F_24 ( V_30 L_34 , V_2 -> V_26 ) ;
#endif
do {
unsigned short V_106 , V_107 , V_108 , V_109 ;
F_5 ( V_104 , V_10 + V_94 ) ;
V_54 = F_2 ( V_10 + V_110 ) ;
if ( F_65 ( V_54 ) )
{
V_106 = F_2 ( V_10 + V_110 ) ;
V_107 = F_2 ( V_10 + V_110 ) ;
V_108 = F_2 ( V_10 + V_110 ) ;
F_5 ( V_108 , V_10 + V_94 ) ;
V_109 = F_2 ( V_10 + V_110 ) ;
if ( V_106 != 0x0000 )
{
F_24 ( V_33 L_35 ,
V_2 -> V_26 , V_106 ) ;
continue;
}
else if ( V_108 != V_104 + 0x16 )
{
F_24 ( V_33 L_36 ,
V_2 -> V_26 , V_104 + 0x16 , V_108 ) ;
continue;
}
else if ( ( V_109 & 0xc000 ) != 0xc000 )
{
F_24 ( V_33 L_37 ,
V_2 -> V_26 , V_109 & 0xc000 ) ;
continue;
}
else if ( ! F_66 ( V_54 ) )
{
V_2 -> V_60 . V_96 ++ ;
if ( F_67 ( V_54 ) )
V_2 -> V_60 . V_111 ++ ;
if ( F_68 ( V_54 ) )
V_2 -> V_60 . V_112 ++ ;
if ( F_69 ( V_54 ) )
V_2 -> V_60 . V_113 ++ ;
if ( F_70 ( V_54 ) )
V_2 -> V_60 . V_114 ++ ;
if ( F_71 ( V_54 ) )
V_2 -> V_60 . V_115 ++ ;
}
else
{
struct V_64 * V_116 ;
V_109 &= 0x3fff ;
V_116 = F_72 ( V_2 , V_109 + 16 ) ;
if ( V_116 == NULL )
{
F_24 ( V_33 L_38 , V_2 -> V_26 ) ;
V_2 -> V_60 . V_117 ++ ;
break;
}
F_73 ( V_116 , 2 ) ;
F_5 ( V_108 + 10 , V_10 + V_94 ) ;
F_74 ( V_10 + V_110 , F_75 ( V_116 , V_109 ) , ( V_109 + 1 ) >> 1 ) ;
V_116 -> V_118 = F_76 ( V_116 , V_2 ) ;
F_77 ( V_116 ) ;
V_2 -> V_60 . V_119 ++ ;
V_2 -> V_60 . V_120 += V_109 ;
}
F_5 ( V_104 , V_10 + V_95 ) ;
F_5 ( 0 , V_10 + V_110 ) ;
F_5 ( 0 , V_10 + V_110 ) ;
V_104 = V_107 ;
}
} while ( F_65 ( V_54 ) && V_51 -- );
V_28 -> V_88 = V_104 ;
}
static void F_48 ( struct V_1 * V_2 , unsigned short * V_65 ,
unsigned short V_67 )
{
struct V_24 * V_28 = F_23 ( V_2 ) ;
unsigned short V_10 = V_2 -> V_3 ;
if ( V_121 || V_28 -> V_38 ) {
F_4 ( V_2 , V_42 ) ;
F_5 ( 0xFFFF , V_10 + V_44 ) ;
}
F_5 ( V_28 -> V_122 , V_10 + V_95 ) ;
F_5 ( 0x0000 , V_10 + V_110 ) ;
F_5 ( V_123 | V_124 , V_10 + V_110 ) ;
F_5 ( V_28 -> V_122 + 0x08 , V_10 + V_110 ) ;
F_5 ( V_28 -> V_122 + 0x0e , V_10 + V_110 ) ;
F_5 ( 0x0000 , V_10 + V_110 ) ;
F_5 ( 0x0000 , V_10 + V_110 ) ;
F_5 ( V_28 -> V_122 + 0x08 , V_10 + V_110 ) ;
F_5 ( 0x8000 | V_67 , V_10 + V_110 ) ;
F_5 ( - 1 , V_10 + V_110 ) ;
F_5 ( V_28 -> V_122 + 0x16 , V_10 + V_110 ) ;
F_5 ( 0 , V_10 + V_110 ) ;
F_78 ( V_10 + V_110 , V_65 , ( V_67 + 1 ) >> 1 ) ;
F_5 ( V_28 -> V_125 + 0xc , V_10 + V_95 ) ;
F_5 ( V_28 -> V_122 , V_10 + V_110 ) ;
V_2 -> V_126 = V_47 ;
V_28 -> V_125 = V_28 -> V_122 ;
if ( V_28 -> V_122 == V_127 + ( ( V_28 -> V_128 - 1 ) * V_129 ) )
V_28 -> V_122 = V_127 ;
else
V_28 -> V_122 += V_129 ;
if ( V_28 -> V_122 != V_28 -> V_130 )
F_36 ( V_2 ) ;
if ( V_121 || V_28 -> V_38 ) {
F_4 ( V_2 , V_131 ) ;
F_5 ( 0xFFFF , V_10 + V_44 ) ;
}
V_2 -> V_60 . V_132 ++ ;
V_28 -> V_62 = V_47 ;
}
static int T_1 F_15 ( struct V_1 * V_2 , unsigned short V_10 )
{
unsigned short V_133 [ 3 ] ;
unsigned char V_134 ;
unsigned int V_135 ;
int V_19 ;
unsigned short V_136 = 0 ;
struct V_24 * V_28 = F_23 ( V_2 ) ;
F_24 ( L_39 , V_2 -> V_26 , V_10 ) ;
F_9 ( V_137 , V_10 + V_46 ) ;
F_9 ( 0 , V_10 + V_46 ) ;
F_79 ( 500 ) ;
F_9 ( V_45 , V_10 + V_46 ) ;
V_133 [ 0 ] = F_80 ( V_10 , 2 ) ;
V_133 [ 1 ] = F_80 ( V_10 , 3 ) ;
V_133 [ 2 ] = F_80 ( V_10 , 4 ) ;
if ( ! ( ( V_133 [ 2 ] == 0x00aa && ( ( V_133 [ 1 ] & 0xff00 ) == 0x0000 ) ) ||
( V_133 [ 2 ] == 0x0080 && ( ( V_133 [ 1 ] & 0xff00 ) == 0x5F00 ) ) ) )
{
F_24 ( L_40 ,
V_133 [ 2 ] , V_133 [ 1 ] , V_133 [ 0 ] ) ;
return - V_22 ;
}
for ( V_19 = 0 ; V_19 < 64 ; V_19 ++ )
V_136 += F_80 ( V_10 , V_19 ) ;
if ( V_136 != 0xbaba )
F_24 ( L_41 , V_136 ) ;
V_2 -> V_3 = V_10 ;
for ( V_19 = 0 ; V_19 < 6 ; V_19 ++ )
V_2 -> V_138 [ V_19 ] = ( ( unsigned char * ) V_133 ) [ 5 - V_19 ] ;
{
static const char V_139 [] = { 0 , 9 , 3 , 4 , 5 , 10 , 11 , 0 } ;
unsigned short V_140 = F_80 ( V_10 , 0 ) ;
if ( ! V_2 -> V_12 )
V_2 -> V_12 = V_139 [ V_140 >> 13 ] ;
if ( V_2 -> V_14 == 0xff ) {
V_2 -> V_14 = ! ( V_140 & 0x1000 ) ? V_141 :
F_80 ( V_10 , 5 ) & 0x1 ? V_102 : V_103 ;
}
V_134 = ! ( ( V_140 & 0x400 ) >> 10 ) ;
}
memset ( V_28 , 0 , sizeof( struct V_24 ) ) ;
F_81 ( & V_28 -> V_58 ) ;
F_24 ( L_42 , V_2 -> V_12 ,
V_142 [ V_2 -> V_14 ] , V_134 ? 8 : 16 ) ;
if ( ! F_14 ( V_2 -> V_3 + 0x300e , 1 , L_1 ) )
return - V_16 ;
F_63 ( V_2 ) ;
F_16 ( V_2 -> V_3 + 0x300e , 1 ) ;
F_5 ( 0 , V_2 -> V_3 + V_95 ) ;
for ( V_19 = 0 ; V_19 < 32768 ; V_19 ++ )
F_5 ( 0 , V_2 -> V_3 + V_110 ) ;
for ( V_135 = 0 ; V_135 < 64 ; V_135 ++ )
{
F_5 ( V_135 << 10 , V_2 -> V_3 + V_94 ) ;
if ( F_2 ( V_2 -> V_3 + V_110 ) )
break;
F_5 ( V_135 << 10 , V_2 -> V_3 + V_95 ) ;
F_5 ( V_135 | 0x5000 , V_2 -> V_3 + V_110 ) ;
F_5 ( V_135 << 10 , V_2 -> V_3 + V_94 ) ;
if ( F_2 ( V_2 -> V_3 + V_110 ) != ( V_135 | 0x5000 ) )
break;
}
V_28 -> V_128 = 4 ;
V_28 -> V_143 = 0x3ff6 ;
switch ( V_135 )
{
case 64 :
V_28 -> V_143 += 0x4000 ;
case 48 :
V_28 -> V_128 += 4 ;
V_28 -> V_143 += 0x4000 ;
case 32 :
V_28 -> V_143 += 0x4000 ;
case 16 :
F_24 ( L_43 , V_135 ) ;
break;
default:
F_24 ( L_44 , V_135 ) ;
return - V_22 ;
break;
}
V_28 -> V_87 = V_127 + ( V_28 -> V_128 * V_129 ) ;
V_28 -> V_38 = V_134 ;
V_2 -> V_144 = & V_145 ;
V_2 -> V_146 = 2 * V_48 ;
return F_82 ( V_2 ) ;
}
static unsigned short T_1 F_80 ( unsigned short V_10 ,
unsigned char V_147 )
{
unsigned short V_4 = 0x180 | ( V_147 & 0x7f ) ;
unsigned short V_148 = 0 , V_149 = V_150 | V_45 ;
int V_19 ;
F_9 ( V_150 | V_45 , V_10 + V_46 ) ;
for ( V_19 = 0x100 ; V_19 ; V_19 >>= 1 )
{
if ( V_4 & V_19 )
V_149 |= V_151 ;
else
V_149 &= ~ V_151 ;
F_9 ( V_149 , V_10 + V_46 ) ;
F_9 ( V_149 | V_152 , V_10 + V_46 ) ;
F_83 () ;
F_9 ( V_149 , V_10 + V_46 ) ;
F_83 () ;
}
V_149 &= ~ V_151 ;
F_9 ( V_149 , V_10 + V_46 ) ;
for ( V_19 = 0x8000 ; V_19 ; V_19 >>= 1 )
{
F_9 ( V_149 | V_152 , V_10 + V_46 ) ;
F_83 () ;
if ( F_10 ( V_10 + V_46 ) & V_153 )
V_148 |= V_19 ;
F_9 ( V_149 , V_10 + V_46 ) ;
F_83 () ;
}
V_149 &= ~ V_150 ;
F_9 ( V_149 | V_152 , V_10 + V_46 ) ;
F_83 () ;
F_9 ( V_149 , V_10 + V_46 ) ;
F_83 () ;
return V_148 ;
}
static unsigned short F_38 ( struct V_1 * V_2 )
{
struct V_24 * V_28 = F_23 ( V_2 ) ;
unsigned short V_154 = V_28 -> V_130 ;
unsigned short V_54 ;
if ( ! F_40 ( V_2 ) && V_28 -> V_122 == V_28 -> V_130 )
return 0x0000 ;
do
{
F_5 ( V_154 & ~ 31 , V_2 -> V_3 + V_78 ) ;
V_54 = F_2 ( V_2 -> V_3 + F_12 ( V_154 ) ) ;
if ( ! F_84 ( V_54 ) )
{
V_28 -> V_49 = V_154 ;
return V_54 ;
}
else
{
V_28 -> V_50 = 0 ;
V_2 -> V_60 . V_155 += F_85 ( V_54 ) ;
if ( ! F_86 ( V_54 ) )
{
char * V_156 = NULL ;
V_2 -> V_60 . V_61 ++ ;
if ( F_87 ( V_54 ) )
V_2 -> V_60 . V_157 ++ ;
if ( F_88 ( V_54 ) ) {
V_156 = L_45 ;
V_2 -> V_60 . V_158 ++ ;
}
if ( F_89 ( V_54 ) ) {
V_156 = L_46 ;
V_2 -> V_60 . V_158 ++ ;
}
if ( F_90 ( V_54 ) ) {
V_156 = L_47 ;
V_2 -> V_60 . V_159 ++ ;
}
if ( F_91 ( V_54 ) ) {
V_156 = L_48 ;
V_2 -> V_60 . V_157 ++ ;
}
if ( V_156 )
F_24 ( V_59 L_49 ,
V_2 -> V_26 , V_156 ) ;
}
else
V_2 -> V_60 . V_132 ++ ;
}
if ( V_154 == V_127 + ( ( V_28 -> V_128 - 1 ) * V_129 ) )
V_28 -> V_130 = V_154 = V_127 ;
else
V_28 -> V_130 = V_154 += V_129 ;
F_36 ( V_2 ) ;
}
while ( V_28 -> V_130 != V_28 -> V_122 );
V_28 -> V_49 = V_28 -> V_125 + 0x08 ;
return V_54 ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_24 * V_28 = F_23 ( V_2 ) ;
unsigned short V_10 = V_2 -> V_3 ;
V_28 -> V_50 = V_28 -> V_49 ;
F_6 ( V_2 , V_28 -> V_49 ) ;
F_4 ( V_2 , V_53 ) ;
F_9 ( 0 , V_10 + V_44 ) ;
{
unsigned short V_51 = 50 , V_160 = 5 ;
while ( ! F_1 ( V_2 ) )
{
if ( ! -- V_51 )
{
if ( -- V_160 )
{
F_24 ( V_33 L_50 , V_2 -> V_26 , F_1 ( V_2 ) , F_3 ( V_2 ) ) ;
F_6 ( V_2 , V_28 -> V_49 ) ;
F_4 ( V_2 , V_53 ) ;
F_9 ( 0 , V_10 + V_44 ) ;
V_51 = 100 ;
}
else
{
F_24 ( V_33 L_51 , V_2 -> V_26 ) ;
F_26 ( V_2 ) ;
F_36 ( V_2 ) ;
return;
}
}
}
}
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_24 * V_28 = F_23 ( V_2 ) ;
unsigned short V_154 = V_127 ;
unsigned short V_161 ;
unsigned short V_10 = V_2 -> V_3 ;
for ( V_161 = 0 ; V_161 < V_28 -> V_128 ; V_161 ++ )
{
F_5 ( V_154 , V_10 + V_95 ) ;
F_5 ( 0x0000 , V_10 + V_110 ) ;
F_5 ( V_123 | V_124 , V_10 + V_110 ) ;
F_5 ( V_154 + 0x08 , V_10 + V_110 ) ;
F_5 ( V_154 + 0x0e , V_10 + V_110 ) ;
F_5 ( 0x0000 , V_10 + V_110 ) ;
F_5 ( 0x0000 , V_10 + V_110 ) ;
F_5 ( V_154 + 0x08 , V_10 + V_110 ) ;
F_5 ( 0x8000 , V_10 + V_110 ) ;
F_5 ( - 1 , V_10 + V_110 ) ;
F_5 ( V_154 + 0x16 , V_10 + V_110 ) ;
F_5 ( 0x0000 , V_10 + V_110 ) ;
V_154 += V_129 ;
}
V_28 -> V_122 = V_127 ;
V_28 -> V_130 = V_127 ;
V_28 -> V_125 = V_154 - V_129 ;
V_28 -> V_49 = V_28 -> V_125 + 0x08 ;
V_28 -> V_87 = V_154 ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_24 * V_28 = F_23 ( V_2 ) ;
unsigned short V_104 = V_28 -> V_87 ;
unsigned short V_10 = V_2 -> V_3 ;
V_28 -> V_105 = 0 ;
V_28 -> V_162 = V_28 -> V_88 = V_104 ;
do
{
V_28 -> V_105 ++ ;
F_5 ( V_104 , V_10 + V_95 ) ;
F_5 ( 0 , V_10 + V_110 ) ; F_5 ( 0 , V_10 + V_110 ) ;
F_5 ( V_104 + V_163 , V_10 + V_110 ) ;
F_5 ( 0xffff , V_10 + V_110 ) ;
F_5 ( 0x0000 , V_10 + V_110 ) ;
F_5 ( 0xdead , V_10 + V_110 ) ;
F_5 ( 0xdead , V_10 + V_110 ) ;
F_5 ( 0xdead , V_10 + V_110 ) ;
F_5 ( 0xdead , V_10 + V_110 ) ;
F_5 ( 0xdead , V_10 + V_110 ) ;
F_5 ( 0xdead , V_10 + V_110 ) ;
F_5 ( 0x0000 , V_10 + V_110 ) ;
F_5 ( V_104 + V_163 + 0x16 , V_10 + V_110 ) ;
F_5 ( V_104 + 0x20 , V_10 + V_110 ) ;
F_5 ( 0 , V_10 + V_110 ) ;
F_5 ( V_163 - 0x20 , V_10 + V_110 ) ;
V_28 -> V_164 = V_104 ;
V_104 += V_163 ;
} while ( V_104 <= V_28 -> V_143 - V_163 );
F_5 ( V_28 -> V_162 + 6 , V_10 + V_95 ) ;
F_5 ( V_28 -> V_162 + 0x16 , V_10 + V_110 ) ;
F_5 ( V_28 -> V_164 + 4 , V_10 + V_95 ) ;
F_5 ( V_28 -> V_162 , V_10 + V_110 ) ;
F_5 ( V_28 -> V_164 + 0x16 + 2 , V_10 + V_95 ) ;
F_5 ( V_28 -> V_162 + 0x16 , V_10 + V_110 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_24 * V_28 = F_23 ( V_2 ) ;
unsigned short V_10 = V_2 -> V_3 ;
int V_19 ;
#if V_29 > 6
F_24 ( L_52 , V_2 -> V_26 ) ;
#endif
V_28 -> V_41 = 0 ;
F_8 ( V_2 ) ;
F_9 ( V_39 | V_31 [ V_2 -> V_12 ] , V_10 + V_40 ) ;
F_5 ( V_28 -> V_143 & ~ 31 , V_10 + V_78 ) ;
F_5 ( V_28 -> V_38 ? 0x0001 : 0x0000 , V_10 + 0x8006 ) ;
F_5 ( 0x0000 , V_10 + 0x8008 ) ;
F_5 ( 0x0000 , V_10 + 0x800a ) ;
F_5 ( 0x0000 , V_10 + 0x800c ) ;
F_5 ( 0x0000 , V_10 + 0x800e ) ;
for ( V_19 = 0 ; V_19 < F_92 ( V_165 ) * 2 ; V_19 += 32 ) {
int V_166 ;
F_5 ( V_19 , V_10 + V_78 ) ;
for ( V_166 = 0 ; V_166 < 16 && ( V_19 + V_166 ) / 2 < F_92 ( V_165 ) ; V_166 += 2 )
F_5 ( V_165 [ ( V_19 + V_166 ) / 2 ] ,
V_10 + 0x4000 + V_166 ) ;
for ( V_166 = 0 ; V_166 < 16 && ( V_19 + V_166 + 16 ) / 2 < F_92 ( V_165 ) ; V_166 += 2 )
F_5 ( V_165 [ ( V_19 + V_166 + 16 ) / 2 ] ,
V_10 + 0x8000 + V_166 ) ;
}
F_5 ( V_167 & ~ 31 , V_10 + V_78 ) ;
V_19 = F_2 ( V_10 + F_12 ( V_167 ) ) ;
F_5 ( ( V_2 -> V_57 & V_168 ) ? ( V_19 | 1 ) : ( V_19 & ~ 1 ) ,
V_10 + F_12 ( V_167 ) ) ;
V_28 -> V_169 = V_2 -> V_57 & V_168 ;
#if 0
eexp_setup_filter(dev);
#endif
F_5 ( V_170 & ~ 31 , V_10 + V_78 ) ;
F_5 ( ( ( unsigned short * ) V_2 -> V_138 ) [ 0 ] , V_10 + F_12 ( V_170 ) ) ;
F_5 ( ( ( unsigned short * ) V_2 -> V_138 ) [ 1 ] ,
V_10 + F_12 ( V_170 + 2 ) ) ;
F_5 ( ( ( unsigned short * ) V_2 -> V_138 ) [ 2 ] ,
V_10 + F_12 ( V_170 + 4 ) ) ;
F_34 ( V_2 ) ;
F_61 ( V_2 ) ;
F_9 ( 0 , V_10 + V_46 ) ;
F_64 ( 5 ) ;
F_4 ( V_2 , 0xf000 ) ;
F_9 ( 0 , V_10 + V_44 ) ;
F_5 ( 0 , V_10 + V_78 ) ;
{
unsigned short V_171 = 50 , V_172 = 5 ;
while ( F_2 ( V_10 + 0x4000 ) )
{
if ( ! -- V_171 )
{
F_24 ( V_33 L_53 ,
V_2 -> V_26 ) ;
F_4 ( V_2 , 0 ) ;
F_9 ( 0 , V_10 + V_44 ) ;
V_171 = 100 ;
if ( ! -- V_172 )
{
F_24 ( V_33 L_54 ,
V_2 -> V_26 ) ;
return;
}
}
}
}
F_6 ( V_2 , V_173 ) ;
F_4 ( V_2 , 0xf000 | V_53 ) ;
F_9 ( 0 , V_10 + V_44 ) ;
{
unsigned short V_174 = 50 , V_175 = 5 ;
while ( ! F_1 ( V_2 ) )
{
if ( ! -- V_174 )
{
if ( -- V_175 )
{
F_24 ( V_33 L_55 ,
V_2 -> V_26 , F_1 ( V_2 ) , F_3 ( V_2 ) ) ;
F_6 ( V_2 , V_173 ) ;
F_4 ( V_2 , 0xf000 | V_53 ) ;
F_9 ( 0 , V_10 + V_44 ) ;
V_174 = 100 ;
}
else
{
F_24 ( V_33 L_56 , V_2 -> V_26 ) ;
return;
}
}
}
}
F_11 ( V_2 ) ;
F_9 ( V_99 | V_31 [ V_2 -> V_12 ] , V_10 + V_40 ) ;
V_28 -> V_56 = V_47 ;
#if V_29 > 6
F_24 ( L_57 , V_2 -> V_26 ) ;
#endif
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_176 * V_177 ;
unsigned short V_10 = V_2 -> V_3 ;
int V_178 = F_94 ( V_2 ) ;
int V_19 ;
if ( V_178 > 8 ) {
F_24 ( V_59 L_58 ,
V_2 -> V_26 , V_178 ) ;
V_178 = 8 ;
}
F_5 ( V_179 & ~ 31 , V_10 + V_78 ) ;
F_5 ( 6 * V_178 , V_10 + F_12 ( V_179 ) ) ;
V_19 = 0 ;
F_95 (ha, dev) {
unsigned short * V_70 = ( unsigned short * ) V_177 -> V_7 ;
if ( V_19 == V_178 )
break;
F_5 ( ( V_180 + ( 6 * V_19 ) ) & ~ 31 , V_10 + V_78 ) ;
F_5 ( V_70 [ 0 ] , V_10 + F_12 ( V_180 + ( 6 * V_19 ) ) ) ;
F_5 ( ( V_180 + ( 6 * V_19 ) + 2 ) & ~ 31 , V_10 + V_78 ) ;
F_5 ( V_70 [ 1 ] , V_10 + F_12 ( V_180 + ( 6 * V_19 ) + 2 ) ) ;
F_5 ( ( V_180 + ( 6 * V_19 ) + 4 ) & ~ 31 , V_10 + V_78 ) ;
F_5 ( V_70 [ 2 ] , V_10 + F_12 ( V_180 + ( 6 * V_19 ) + 4 ) ) ;
V_19 ++ ;
}
}
static void
F_96 ( struct V_1 * V_2 )
{
unsigned short V_10 = V_2 -> V_3 ;
struct V_24 * V_28 = F_23 ( V_2 ) ;
int V_181 = 0 , V_19 ;
if ( ( V_2 -> V_57 & V_168 ) != V_28 -> V_169 ) {
F_5 ( V_167 & ~ 31 , V_10 + V_78 ) ;
V_19 = F_2 ( V_10 + F_12 ( V_167 ) ) ;
F_5 ( ( V_2 -> V_57 & V_168 ) ? ( V_19 | 1 ) : ( V_19 & ~ 1 ) ,
V_10 + F_12 ( V_167 ) ) ;
V_28 -> V_169 = V_2 -> V_57 & V_168 ;
V_181 = 1 ;
}
if ( ! ( V_2 -> V_57 & V_168 ) ) {
F_93 ( V_2 ) ;
if ( V_28 -> V_182 != F_94 ( V_2 ) ) {
V_181 = 1 ;
V_28 -> V_182 = F_94 ( V_2 ) ;
}
}
if ( V_181 ) {
unsigned long V_183 ;
F_4 ( V_2 , V_42 ) ;
F_9 ( 0 , V_10 + V_44 ) ;
F_9 ( 0 , V_10 + V_44 ) ;
#if 0
printk("%s: waiting for CU to go suspended\n", dev->name);
#endif
V_183 = V_47 ;
while ( ( F_53 ( F_1 ( V_2 ) ) == 2 ) &&
( F_56 ( V_47 , V_183 + 2000 ) ) ) ;
if ( F_53 ( F_1 ( V_2 ) ) == 2 )
F_24 ( L_59 , V_2 -> V_26 ) ;
V_28 -> V_41 &= ~ ( V_74 ) ;
F_6 ( V_2 , V_173 ) ;
F_4 ( V_2 , V_53 ) ;
F_9 ( 0 , V_10 + V_44 ) ;
}
}
int T_1 F_97 ( void )
{
struct V_1 * V_2 ;
int V_184 , V_185 = 0 ;
for ( V_184 = 0 ; V_184 < V_186 ; V_184 ++ ) {
V_2 = F_18 ( sizeof( struct V_24 ) ) ;
V_2 -> V_12 = V_12 [ V_184 ] ;
V_2 -> V_3 = V_187 [ V_184 ] ;
if ( V_187 [ V_184 ] == 0 ) {
if ( V_184 )
break;
F_24 ( V_188 L_60 ) ;
}
if ( F_13 ( V_2 ) == 0 ) {
V_189 [ V_184 ] = V_2 ;
V_185 ++ ;
continue;
}
F_24 ( V_33 L_61 , V_187 [ V_184 ] ) ;
F_21 ( V_2 ) ;
break;
}
if ( V_185 )
return 0 ;
return - V_17 ;
}
void T_4 F_98 ( void )
{
int V_184 ;
for ( V_184 = 0 ; V_184 < V_186 ; V_184 ++ ) {
struct V_1 * V_2 = V_189 [ V_184 ] ;
if ( V_2 ) {
F_99 ( V_2 ) ;
F_21 ( V_2 ) ;
}
}
}
