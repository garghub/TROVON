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
#ifdef F_14
if ( V_15 ) {
int V_16 = 0 ;
while ( V_16 != V_17 ) {
int V_18 , V_19 ;
V_16 = F_15 ( 0x628B , V_16 ) ;
if ( V_16 == V_17 )
break;
V_18 = F_16 ( V_16 , 2 ) ;
V_19 = F_16 ( V_16 , 3 ) ;
V_10 = V_20 [ V_19 & 0xf ] ;
V_2 -> V_12 = V_21 [ ( V_19 >> 4 ) & 0x7 ] ;
if ( ( V_18 & 0x7 ) == 0x1 )
V_2 -> V_14 = V_22 ;
else if ( ( V_18 & 0x7 ) == 0x5 ) {
if ( V_19 & 0x80 )
V_2 -> V_14 = V_23 ;
else
V_2 -> V_14 = V_24 ;
}
F_17 ( V_16 , L_1 ) ;
F_18 ( V_16 , NULL , V_2 ) ;
F_19 ( V_16 ) ;
break;
}
}
#endif
if ( V_10 & 0xfe00 ) {
if ( ! F_20 ( V_10 , V_25 , L_2 ) )
return - V_26 ;
V_13 = F_21 ( V_2 , V_10 ) ;
F_22 ( V_10 , V_25 ) ;
return V_13 ;
} else if ( V_10 )
return - V_27 ;
for ( V_8 = & V_9 [ 0 ] ; * V_8 ; V_8 ++ )
{
unsigned short V_28 = 0 ;
int V_29 ;
if ( ! F_20 ( * V_8 , V_25 , L_2 ) )
continue;
for ( V_29 = 0 ; V_29 < 4 ; V_29 ++ )
{
unsigned short V_30 ;
V_30 = F_10 ( * V_8 + V_31 ) ;
V_28 |= ( V_30 >> 4 ) << ( ( V_30 & 0x03 ) << 2 ) ;
}
if ( V_28 == 0xbaba && ! F_21 ( V_2 , * V_8 ) ) {
F_22 ( * V_8 , V_25 ) ;
return 0 ;
}
F_22 ( * V_8 , V_25 ) ;
V_2 -> V_12 = V_11 ;
}
return - V_32 ;
}
struct V_1 * T_1 F_23 ( int V_33 )
{
struct V_1 * V_2 = F_24 ( sizeof( struct V_34 ) ) ;
int V_13 ;
if ( ! V_2 )
return F_25 ( - V_35 ) ;
sprintf ( V_2 -> V_36 , L_3 , V_33 ) ;
F_26 ( V_2 ) ;
V_13 = F_13 ( V_2 ) ;
if ( ! V_13 )
return V_2 ;
F_27 ( V_2 ) ;
return F_25 ( V_13 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_37 ;
unsigned short V_10 = V_2 -> V_3 ;
struct V_34 * V_38 = F_29 ( V_2 ) ;
#if V_39 > 6
F_30 ( V_40 L_4 , V_2 -> V_36 ) ;
#endif
if ( ! V_2 -> V_12 || ! V_41 [ V_2 -> V_12 ] )
return - V_27 ;
V_37 = F_31 ( V_2 -> V_12 , V_42 , 0 , V_2 -> V_36 , V_2 ) ;
if ( V_37 )
return V_37 ;
if ( ! F_20 ( V_10 , V_25 , L_2 ) ) {
F_30 ( V_43 L_5
, V_10 ) ;
goto V_44;
}
if ( ! F_20 ( V_10 + 0x4000 , V_25 , L_6 ) ) {
F_30 ( V_43 L_5
, V_10 + 0x4000 ) ;
goto V_45;
}
if ( ! F_20 ( V_10 + 0x8000 , V_25 , L_6 ) ) {
F_30 ( V_43 L_5
, V_10 + 0x8000 ) ;
goto V_46;
}
if ( ! F_20 ( V_10 + 0xc000 , V_25 , L_6 ) ) {
F_30 ( V_43 L_5
, V_10 + 0xc000 ) ;
goto V_47;
}
if ( V_38 -> V_48 ) {
F_30 ( L_7 , V_2 -> V_36 ) ;
F_9 ( F_10 ( V_2 -> V_3 + V_6 ) & ~ 4 , V_2 -> V_3 + V_6 ) ;
}
F_32 ( V_2 ) ;
F_33 ( V_2 ) ;
#if V_39 > 6
F_30 ( V_40 L_8 , V_2 -> V_36 ) ;
#endif
return 0 ;
V_47:
F_22 ( V_10 + 0x8000 , V_25 ) ;
V_46:
F_22 ( V_10 + 0x4000 , V_25 ) ;
V_45:
F_22 ( V_10 , V_25 ) ;
V_44:
F_34 ( V_2 -> V_12 , V_2 ) ;
return - V_26 ;
}
static int F_35 ( struct V_1 * V_2 )
{
unsigned short V_10 = V_2 -> V_3 ;
struct V_34 * V_38 = F_29 ( V_2 ) ;
int V_12 = V_2 -> V_12 ;
F_36 ( V_2 ) ;
F_9 ( V_49 | V_41 [ V_12 ] , V_10 + V_50 ) ;
V_38 -> V_51 = 0 ;
F_4 ( V_2 , V_52 | V_53 ) ;
F_9 ( 0 , V_10 + V_54 ) ;
F_34 ( V_12 , V_2 ) ;
F_9 ( V_55 , V_10 + V_56 ) ;
F_22 ( V_10 , V_25 ) ;
F_22 ( V_10 + 0x4000 , 16 ) ;
F_22 ( V_10 + 0x8000 , 16 ) ;
F_22 ( V_10 + 0xc000 , 16 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_34 * V_38 = F_29 ( V_2 ) ;
unsigned short V_10 = V_2 -> V_3 ;
if ( V_38 -> V_51 )
{
if ( F_38 ( V_57 , F_39 ( V_2 ) + V_58 / 2 ) )
{
if ( V_38 -> V_59 == V_38 -> V_60 )
{
unsigned short V_61 = 200 , V_62 ;
F_30 ( V_43 L_9 ,
V_2 -> V_36 , F_1 ( V_2 ) ) ;
F_40 ( V_2 ) ;
V_38 -> V_60 = 0 ;
F_6 ( V_2 , V_38 -> V_59 ) ;
F_4 ( V_2 , V_63 ) ;
F_9 ( 0 , V_10 + V_54 ) ;
while ( ! F_41 ( V_62 = F_1 ( V_2 ) ) )
{
if ( ! -- V_61 )
{
V_61 = 200 ;
F_30 ( V_43 L_10 ,
V_2 -> V_36 , V_62 ) ;
F_6 ( V_2 , V_38 -> V_59 ) ;
F_4 ( V_2 , V_63 ) ;
F_9 ( 0 , V_10 + V_54 ) ;
}
}
F_42 ( V_2 ) ;
}
else
{
unsigned short V_64 = F_1 ( V_2 ) ;
if ( F_43 ( V_64 ) )
{
unsigned short V_65 = F_44 ( V_2 ) ;
F_30 ( V_43 L_11 ,
V_2 -> V_36 , V_64 , V_65 ) ;
F_45 ( V_2 ) ;
}
else
{
unsigned short V_65 = F_44 ( V_2 ) ;
if ( F_46 ( V_2 ) && ! V_65 )
{
F_30 ( V_43 L_12 ,
V_2 -> V_36 , V_64 , V_65 ) ;
F_32 ( V_2 ) ;
F_42 ( V_2 ) ;
}
else
{
F_30 ( V_43 L_13 , V_2 -> V_36 ) ;
}
}
}
}
}
else
{
if ( F_38 ( V_57 , V_38 -> V_66 + 10 ) )
{
unsigned short V_64 = F_1 ( V_2 ) ;
F_30 ( V_43 L_14 ,
V_2 -> V_36 , V_64 ) ;
F_32 ( V_2 ) ;
F_42 ( V_2 ) ;
}
}
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_34 * V_38 = F_29 ( V_2 ) ;
#ifdef F_48
unsigned long V_67 ;
#endif
int V_64 ;
F_49 ( V_2 -> V_12 ) ;
#ifdef F_48
F_50 ( & V_38 -> V_68 , V_67 ) ;
#endif
V_64 = F_1 ( V_2 ) ;
F_37 ( V_2 ) ;
F_30 ( V_69 L_15 , V_2 -> V_36 ,
( F_41 ( V_64 ) ? L_16 :
L_17 ) ) ;
V_2 -> V_70 . V_71 ++ ;
V_38 -> V_72 = V_57 ;
if ( ! F_41 ( V_64 ) ) {
F_4 ( V_2 , V_73 ) ;
F_9 ( 0 , V_2 -> V_3 + V_54 ) ;
}
F_42 ( V_2 ) ;
#ifdef F_48
F_51 ( & V_38 -> V_68 , V_67 ) ;
#endif
}
static T_2 F_52 ( struct V_74 * V_75 , struct V_1 * V_2 )
{
short V_76 = V_75 -> V_77 ;
#ifdef F_48
struct V_34 * V_38 = F_29 ( V_2 ) ;
unsigned long V_67 ;
#endif
#if V_39 > 6
F_30 ( V_40 L_18 , V_2 -> V_36 ) ;
#endif
if ( V_75 -> V_77 < V_78 ) {
if ( F_53 ( V_75 , V_78 ) )
return V_79 ;
V_76 = V_78 ;
}
F_49 ( V_2 -> V_12 ) ;
#ifdef F_48
F_50 ( & V_38 -> V_68 , V_67 ) ;
#endif
{
unsigned short * V_80 = ( unsigned short * ) V_75 -> V_80 ;
V_2 -> V_70 . V_81 += V_76 ;
F_54 ( V_2 , V_80 , V_76 ) ;
}
F_55 ( V_75 ) ;
#ifdef F_48
F_51 ( & V_38 -> V_68 , V_67 ) ;
#endif
F_56 ( V_2 -> V_12 ) ;
return V_79 ;
}
static unsigned short F_57 ( struct V_1 * V_2 ,
unsigned short V_64 )
{
unsigned short V_82 = F_58 ( V_64 ) ;
struct V_34 * V_38 = F_29 ( V_2 ) ;
unsigned short V_10 = V_2 -> V_3 ;
if ( ( V_2 -> V_67 & V_83 ) && ! ( V_38 -> V_51 & V_84 ) ) {
short V_85 , V_86 ;
while ( F_59 ( V_64 ) == 2 )
V_64 = F_1 ( V_2 ) ;
#if V_39 > 4
F_30 ( L_19 ,
V_2 -> V_36 , V_64 ) ;
#endif
F_5 ( V_87 & ~ 31 , V_10 + V_88 ) ;
V_85 = F_2 ( V_10 + F_12 ( V_87 ) ) ;
if ( V_85 & 1 << 11 ) {
F_30 ( V_43 L_20 ,
V_2 -> V_36 ) ;
} else if ( ! ( V_85 & 1 << 13 ) ) {
F_30 ( V_43 L_21 , V_2 -> V_36 ) ;
}
F_5 ( V_89 & ~ 31 , V_10 + V_88 ) ;
V_86 = F_2 ( V_10 + F_12 ( V_89 ) ) ;
if ( V_86 & ( V_90 | V_91 ) ) {
F_30 ( V_43 L_22 , V_2 -> V_36 , ( V_86 & V_90 ) ? L_23 : L_24 , V_86 & V_92 , ( ( V_86 & V_92 ) != 1 ) ? L_25 : L_26 ) ;
}
else if ( V_86 & V_93 ) {
F_30 ( V_43 L_27 , V_2 -> V_36 ) ;
}
else if ( V_86 & V_94 ) {
#if V_39 > 4
F_30 ( V_40 L_28 , V_2 -> V_36 ) ;
#endif
} else {
F_30 ( L_29 , V_2 -> V_36 ,
V_86 ) ;
}
V_38 -> V_51 |= V_84 ;
F_6 ( V_2 , V_38 -> V_59 ) ;
if ( ! ( V_38 -> V_51 & V_95 ) ) {
V_82 |= V_96 ;
F_7 ( V_2 , V_38 -> V_97 ) ;
V_38 -> V_98 = V_38 -> V_97 ;
V_38 -> V_51 |= V_95 ;
}
V_82 |= V_63 | 0x2000 ;
}
if ( ( V_2 -> V_67 & V_83 ) && ! ( V_38 -> V_51 & V_95 ) && F_60 ( V_64 ) == 4 )
V_38 -> V_51 |= V_95 ;
return V_82 ;
}
static void F_61 ( struct V_1 * V_2 )
{
unsigned long int V_99 = V_57 ;
while ( F_3 ( V_2 ) && ( F_62 ( V_57 , V_99 + 10 ) ) ) ;
if ( F_3 ( V_2 ) ) {
F_30 ( L_30 , V_2 -> V_36 ) ;
}
}
static T_3 V_42 ( int V_100 , void * V_101 )
{
struct V_1 * V_2 = V_101 ;
struct V_34 * V_38 ;
unsigned short V_10 , V_64 , V_82 ;
unsigned short V_102 , V_103 ;
V_38 = F_29 ( V_2 ) ;
V_10 = V_2 -> V_3 ;
F_63 ( & V_38 -> V_68 ) ;
V_102 = F_2 ( V_10 + V_104 ) ;
V_103 = F_2 ( V_10 + V_105 ) ;
F_9 ( V_49 | V_41 [ V_2 -> V_12 ] , V_10 + V_50 ) ;
V_64 = F_1 ( V_2 ) ;
#if V_39 > 4
F_30 ( V_40 L_31 , V_2 -> V_36 , V_64 ) ;
#endif
if ( V_38 -> V_51 == ( V_84 | V_95 ) ) {
do {
F_61 ( V_2 ) ;
V_82 = F_58 ( V_64 ) ;
F_4 ( V_2 , V_82 ) ;
F_9 ( 0 , V_10 + V_54 ) ;
F_61 ( V_2 ) ;
if ( F_41 ( V_64 ) ) {
if ( ! F_44 ( V_2 ) ) {
F_30 ( L_32 , V_2 -> V_36 ) ;
}
}
if ( F_64 ( V_64 ) )
F_65 ( V_2 ) ;
V_64 = F_1 ( V_2 ) ;
} while ( V_64 & 0xc000 );
if ( F_66 ( V_64 ) )
{
F_30 ( V_43 L_33 ,
V_2 -> V_36 , V_64 ) ;
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
V_2 -> V_70 . V_106 ++ ;
#if 1
F_67 ( V_2 ) ;
#else
V_38 -> V_107 = V_38 -> V_108 ;
#endif
F_7 ( V_2 , V_38 -> V_97 ) ;
F_4 ( V_2 , V_96 ) ;
F_9 ( 0 , V_10 + V_54 ) ;
}
} else {
if ( V_64 & 0x8000 )
V_82 = F_57 ( V_2 , V_64 ) ;
else
V_82 = F_58 ( V_64 ) ;
F_4 ( V_2 , V_82 ) ;
F_9 ( 0 , V_10 + V_54 ) ;
}
F_61 ( V_2 ) ;
F_9 ( V_109 | V_41 [ V_2 -> V_12 ] , V_10 + V_50 ) ;
#if V_39 > 6
F_30 ( L_34 , V_2 -> V_36 ) ;
#endif
F_5 ( V_102 , V_10 + V_104 ) ;
F_5 ( V_103 , V_10 + V_105 ) ;
F_68 ( & V_38 -> V_68 ) ;
return V_110 ;
}
static void F_69 ( struct V_1 * V_2 )
{
unsigned char V_111 = F_10 ( V_2 -> V_3 + 0x300e ) ;
V_111 &= ~ 0x82 ;
switch ( V_2 -> V_14 ) {
case V_24 :
V_111 |= 0x2 ;
case V_23 :
V_111 |= 0x80 ;
break;
}
F_9 ( V_111 , V_2 -> V_3 + 0x300e ) ;
F_70 ( 20 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_34 * V_38 = F_29 ( V_2 ) ;
unsigned short V_112 = V_38 -> V_98 ;
unsigned short V_61 = V_38 -> V_113 ;
unsigned short V_10 = V_2 -> V_3 ;
unsigned short V_64 ;
#if V_39 > 6
F_30 ( V_40 L_35 , V_2 -> V_36 ) ;
#endif
do {
unsigned short V_114 , V_115 , V_116 , V_117 ;
F_5 ( V_112 , V_10 + V_104 ) ;
V_64 = F_2 ( V_10 + V_118 ) ;
if ( F_71 ( V_64 ) )
{
V_114 = F_2 ( V_10 + V_118 ) ;
V_115 = F_2 ( V_10 + V_118 ) ;
V_116 = F_2 ( V_10 + V_118 ) ;
F_5 ( V_116 , V_10 + V_104 ) ;
V_117 = F_2 ( V_10 + V_118 ) ;
if ( V_114 != 0x0000 )
{
F_30 ( V_43 L_36 ,
V_2 -> V_36 , V_114 ) ;
continue;
}
else if ( V_116 != V_112 + 0x16 )
{
F_30 ( V_43 L_37 ,
V_2 -> V_36 , V_112 + 0x16 , V_116 ) ;
continue;
}
else if ( ( V_117 & 0xc000 ) != 0xc000 )
{
F_30 ( V_43 L_38 ,
V_2 -> V_36 , V_117 & 0xc000 ) ;
continue;
}
else if ( ! F_72 ( V_64 ) )
{
V_2 -> V_70 . V_106 ++ ;
if ( F_73 ( V_64 ) )
V_2 -> V_70 . V_119 ++ ;
if ( F_74 ( V_64 ) )
V_2 -> V_70 . V_120 ++ ;
if ( F_75 ( V_64 ) )
V_2 -> V_70 . V_121 ++ ;
if ( F_76 ( V_64 ) )
V_2 -> V_70 . V_122 ++ ;
if ( F_77 ( V_64 ) )
V_2 -> V_70 . V_123 ++ ;
}
else
{
struct V_74 * V_124 ;
V_117 &= 0x3fff ;
V_124 = F_78 ( V_2 , V_117 + 16 ) ;
if ( V_124 == NULL )
{
F_30 ( V_43 L_39 , V_2 -> V_36 ) ;
V_2 -> V_70 . V_125 ++ ;
break;
}
F_79 ( V_124 , 2 ) ;
F_5 ( V_116 + 10 , V_10 + V_104 ) ;
F_80 ( V_10 + V_118 , F_81 ( V_124 , V_117 ) , ( V_117 + 1 ) >> 1 ) ;
V_124 -> V_126 = F_82 ( V_124 , V_2 ) ;
F_83 ( V_124 ) ;
V_2 -> V_70 . V_127 ++ ;
V_2 -> V_70 . V_128 += V_117 ;
}
F_5 ( V_112 , V_10 + V_105 ) ;
F_5 ( 0 , V_10 + V_118 ) ;
F_5 ( 0 , V_10 + V_118 ) ;
V_112 = V_115 ;
}
} while ( F_71 ( V_64 ) && V_61 -- );
V_38 -> V_98 = V_112 ;
}
static void F_54 ( struct V_1 * V_2 , unsigned short * V_75 ,
unsigned short V_77 )
{
struct V_34 * V_38 = F_29 ( V_2 ) ;
unsigned short V_10 = V_2 -> V_3 ;
if ( V_129 || V_38 -> V_48 ) {
F_4 ( V_2 , V_52 ) ;
F_5 ( 0xFFFF , V_10 + V_54 ) ;
}
F_5 ( V_38 -> V_130 , V_10 + V_105 ) ;
F_5 ( 0x0000 , V_10 + V_118 ) ;
F_5 ( V_131 | V_132 , V_10 + V_118 ) ;
F_5 ( V_38 -> V_130 + 0x08 , V_10 + V_118 ) ;
F_5 ( V_38 -> V_130 + 0x0e , V_10 + V_118 ) ;
F_5 ( 0x0000 , V_10 + V_118 ) ;
F_5 ( 0x0000 , V_10 + V_118 ) ;
F_5 ( V_38 -> V_130 + 0x08 , V_10 + V_118 ) ;
F_5 ( 0x8000 | V_77 , V_10 + V_118 ) ;
F_5 ( - 1 , V_10 + V_118 ) ;
F_5 ( V_38 -> V_130 + 0x16 , V_10 + V_118 ) ;
F_5 ( 0 , V_10 + V_118 ) ;
F_84 ( V_10 + V_118 , V_75 , ( V_77 + 1 ) >> 1 ) ;
F_5 ( V_38 -> V_133 + 0xc , V_10 + V_105 ) ;
F_5 ( V_38 -> V_130 , V_10 + V_118 ) ;
V_2 -> V_134 = V_57 ;
V_38 -> V_133 = V_38 -> V_130 ;
if ( V_38 -> V_130 == V_135 + ( ( V_38 -> V_136 - 1 ) * V_137 ) )
V_38 -> V_130 = V_135 ;
else
V_38 -> V_130 += V_137 ;
if ( V_38 -> V_130 != V_38 -> V_138 )
F_42 ( V_2 ) ;
if ( V_129 || V_38 -> V_48 ) {
F_4 ( V_2 , V_139 ) ;
F_5 ( 0xFFFF , V_10 + V_54 ) ;
}
V_2 -> V_70 . V_140 ++ ;
V_38 -> V_72 = V_57 ;
}
static int T_1 F_21 ( struct V_1 * V_2 , unsigned short V_10 )
{
unsigned short V_141 [ 3 ] ;
unsigned char V_142 ;
unsigned int V_143 ;
int V_29 ;
unsigned short V_144 = 0 ;
struct V_34 * V_38 = F_29 ( V_2 ) ;
F_30 ( L_40 , V_2 -> V_36 , V_10 ) ;
F_9 ( V_145 , V_10 + V_56 ) ;
F_9 ( 0 , V_10 + V_56 ) ;
F_85 ( 500 ) ;
F_9 ( V_55 , V_10 + V_56 ) ;
V_141 [ 0 ] = F_86 ( V_10 , 2 ) ;
V_141 [ 1 ] = F_86 ( V_10 , 3 ) ;
V_141 [ 2 ] = F_86 ( V_10 , 4 ) ;
if ( ! ( ( V_141 [ 2 ] == 0x00aa && ( ( V_141 [ 1 ] & 0xff00 ) == 0x0000 ) ) ||
( V_141 [ 2 ] == 0x0080 && ( ( V_141 [ 1 ] & 0xff00 ) == 0x5F00 ) ) ) )
{
F_30 ( L_41 ,
V_141 [ 2 ] , V_141 [ 1 ] , V_141 [ 0 ] ) ;
return - V_32 ;
}
for ( V_29 = 0 ; V_29 < 64 ; V_29 ++ )
V_144 += F_86 ( V_10 , V_29 ) ;
if ( V_144 != 0xbaba )
F_30 ( L_42 , V_144 ) ;
V_2 -> V_3 = V_10 ;
for ( V_29 = 0 ; V_29 < 6 ; V_29 ++ )
V_2 -> V_146 [ V_29 ] = ( ( unsigned char * ) V_141 ) [ 5 - V_29 ] ;
{
static const char V_147 [] = { 0 , 9 , 3 , 4 , 5 , 10 , 11 , 0 } ;
unsigned short V_148 = F_86 ( V_10 , 0 ) ;
if ( ! V_2 -> V_12 )
V_2 -> V_12 = V_147 [ V_148 >> 13 ] ;
if ( V_2 -> V_14 == 0xff ) {
V_2 -> V_14 = ! ( V_148 & 0x1000 ) ? V_22 :
F_86 ( V_10 , 5 ) & 0x1 ? V_24 : V_23 ;
}
V_142 = ! ( ( V_148 & 0x400 ) >> 10 ) ;
}
memset ( V_38 , 0 , sizeof( struct V_34 ) ) ;
F_87 ( & V_38 -> V_68 ) ;
F_30 ( L_43 , V_2 -> V_12 ,
V_149 [ V_2 -> V_14 ] , V_142 ? 8 : 16 ) ;
if ( ! F_20 ( V_2 -> V_3 + 0x300e , 1 , L_2 ) )
return - V_26 ;
F_69 ( V_2 ) ;
F_22 ( V_2 -> V_3 + 0x300e , 1 ) ;
F_5 ( 0 , V_2 -> V_3 + V_105 ) ;
for ( V_29 = 0 ; V_29 < 32768 ; V_29 ++ )
F_5 ( 0 , V_2 -> V_3 + V_118 ) ;
for ( V_143 = 0 ; V_143 < 64 ; V_143 ++ )
{
F_5 ( V_143 << 10 , V_2 -> V_3 + V_104 ) ;
if ( F_2 ( V_2 -> V_3 + V_118 ) )
break;
F_5 ( V_143 << 10 , V_2 -> V_3 + V_105 ) ;
F_5 ( V_143 | 0x5000 , V_2 -> V_3 + V_118 ) ;
F_5 ( V_143 << 10 , V_2 -> V_3 + V_104 ) ;
if ( F_2 ( V_2 -> V_3 + V_118 ) != ( V_143 | 0x5000 ) )
break;
}
V_38 -> V_136 = 4 ;
V_38 -> V_150 = 0x3ff6 ;
switch ( V_143 )
{
case 64 :
V_38 -> V_150 += 0x4000 ;
case 48 :
V_38 -> V_136 += 4 ;
V_38 -> V_150 += 0x4000 ;
case 32 :
V_38 -> V_150 += 0x4000 ;
case 16 :
F_30 ( L_44 , V_143 ) ;
break;
default:
F_30 ( L_45 , V_143 ) ;
return - V_32 ;
break;
}
V_38 -> V_97 = V_135 + ( V_38 -> V_136 * V_137 ) ;
V_38 -> V_48 = V_142 ;
V_2 -> V_151 = & V_152 ;
V_2 -> V_153 = 2 * V_58 ;
return F_88 ( V_2 ) ;
}
static unsigned short T_1 F_86 ( unsigned short V_10 ,
unsigned char V_154 )
{
unsigned short V_4 = 0x180 | ( V_154 & 0x7f ) ;
unsigned short V_155 = 0 , V_156 = V_157 | V_55 ;
int V_29 ;
F_9 ( V_157 | V_55 , V_10 + V_56 ) ;
for ( V_29 = 0x100 ; V_29 ; V_29 >>= 1 )
{
if ( V_4 & V_29 )
V_156 |= V_158 ;
else
V_156 &= ~ V_158 ;
F_9 ( V_156 , V_10 + V_56 ) ;
F_9 ( V_156 | V_159 , V_10 + V_56 ) ;
F_89 () ;
F_9 ( V_156 , V_10 + V_56 ) ;
F_89 () ;
}
V_156 &= ~ V_158 ;
F_9 ( V_156 , V_10 + V_56 ) ;
for ( V_29 = 0x8000 ; V_29 ; V_29 >>= 1 )
{
F_9 ( V_156 | V_159 , V_10 + V_56 ) ;
F_89 () ;
if ( F_10 ( V_10 + V_56 ) & V_160 )
V_155 |= V_29 ;
F_9 ( V_156 , V_10 + V_56 ) ;
F_89 () ;
}
V_156 &= ~ V_157 ;
F_9 ( V_156 | V_159 , V_10 + V_56 ) ;
F_89 () ;
F_9 ( V_156 , V_10 + V_56 ) ;
F_89 () ;
return V_155 ;
}
static unsigned short F_44 ( struct V_1 * V_2 )
{
struct V_34 * V_38 = F_29 ( V_2 ) ;
unsigned short V_161 = V_38 -> V_138 ;
unsigned short V_64 ;
if ( ! F_46 ( V_2 ) && V_38 -> V_130 == V_38 -> V_138 )
return 0x0000 ;
do
{
F_5 ( V_161 & ~ 31 , V_2 -> V_3 + V_88 ) ;
V_64 = F_2 ( V_2 -> V_3 + F_12 ( V_161 ) ) ;
if ( ! F_90 ( V_64 ) )
{
V_38 -> V_59 = V_161 ;
return V_64 ;
}
else
{
V_38 -> V_60 = 0 ;
V_2 -> V_70 . V_162 += F_91 ( V_64 ) ;
if ( ! F_92 ( V_64 ) )
{
char * V_163 = NULL ;
V_2 -> V_70 . V_71 ++ ;
if ( F_93 ( V_64 ) )
V_2 -> V_70 . V_164 ++ ;
if ( F_94 ( V_64 ) ) {
V_163 = L_46 ;
V_2 -> V_70 . V_165 ++ ;
}
if ( F_95 ( V_64 ) ) {
V_163 = L_47 ;
V_2 -> V_70 . V_165 ++ ;
}
if ( F_96 ( V_64 ) ) {
V_163 = L_48 ;
V_2 -> V_70 . V_166 ++ ;
}
if ( F_97 ( V_64 ) ) {
V_163 = L_49 ;
V_2 -> V_70 . V_164 ++ ;
}
if ( V_163 )
F_30 ( V_69 L_50 ,
V_2 -> V_36 , V_163 ) ;
}
else
V_2 -> V_70 . V_140 ++ ;
}
if ( V_161 == V_135 + ( ( V_38 -> V_136 - 1 ) * V_137 ) )
V_38 -> V_138 = V_161 = V_135 ;
else
V_38 -> V_138 = V_161 += V_137 ;
F_42 ( V_2 ) ;
}
while ( V_38 -> V_138 != V_38 -> V_130 );
V_38 -> V_59 = V_38 -> V_133 + 0x08 ;
return V_64 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_34 * V_38 = F_29 ( V_2 ) ;
unsigned short V_10 = V_2 -> V_3 ;
V_38 -> V_60 = V_38 -> V_59 ;
F_6 ( V_2 , V_38 -> V_59 ) ;
F_4 ( V_2 , V_63 ) ;
F_9 ( 0 , V_10 + V_54 ) ;
{
unsigned short V_61 = 50 , V_167 = 5 ;
while ( ! F_1 ( V_2 ) )
{
if ( ! -- V_61 )
{
if ( -- V_167 )
{
F_30 ( V_43 L_51 , V_2 -> V_36 , F_1 ( V_2 ) , F_3 ( V_2 ) ) ;
F_6 ( V_2 , V_38 -> V_59 ) ;
F_4 ( V_2 , V_63 ) ;
F_9 ( 0 , V_10 + V_54 ) ;
V_61 = 100 ;
}
else
{
F_30 ( V_43 L_52 , V_2 -> V_36 ) ;
F_32 ( V_2 ) ;
F_42 ( V_2 ) ;
return;
}
}
}
}
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_34 * V_38 = F_29 ( V_2 ) ;
unsigned short V_161 = V_135 ;
unsigned short V_168 ;
unsigned short V_10 = V_2 -> V_3 ;
for ( V_168 = 0 ; V_168 < V_38 -> V_136 ; V_168 ++ )
{
F_5 ( V_161 , V_10 + V_105 ) ;
F_5 ( 0x0000 , V_10 + V_118 ) ;
F_5 ( V_131 | V_132 , V_10 + V_118 ) ;
F_5 ( V_161 + 0x08 , V_10 + V_118 ) ;
F_5 ( V_161 + 0x0e , V_10 + V_118 ) ;
F_5 ( 0x0000 , V_10 + V_118 ) ;
F_5 ( 0x0000 , V_10 + V_118 ) ;
F_5 ( V_161 + 0x08 , V_10 + V_118 ) ;
F_5 ( 0x8000 , V_10 + V_118 ) ;
F_5 ( - 1 , V_10 + V_118 ) ;
F_5 ( V_161 + 0x16 , V_10 + V_118 ) ;
F_5 ( 0x0000 , V_10 + V_118 ) ;
V_161 += V_137 ;
}
V_38 -> V_130 = V_135 ;
V_38 -> V_138 = V_135 ;
V_38 -> V_133 = V_161 - V_137 ;
V_38 -> V_59 = V_38 -> V_133 + 0x08 ;
V_38 -> V_97 = V_161 ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_34 * V_38 = F_29 ( V_2 ) ;
unsigned short V_112 = V_38 -> V_97 ;
unsigned short V_10 = V_2 -> V_3 ;
V_38 -> V_113 = 0 ;
V_38 -> V_169 = V_38 -> V_98 = V_112 ;
do
{
V_38 -> V_113 ++ ;
F_5 ( V_112 , V_10 + V_105 ) ;
F_5 ( 0 , V_10 + V_118 ) ; F_5 ( 0 , V_10 + V_118 ) ;
F_5 ( V_112 + V_170 , V_10 + V_118 ) ;
F_5 ( 0xffff , V_10 + V_118 ) ;
F_5 ( 0x0000 , V_10 + V_118 ) ;
F_5 ( 0xdead , V_10 + V_118 ) ;
F_5 ( 0xdead , V_10 + V_118 ) ;
F_5 ( 0xdead , V_10 + V_118 ) ;
F_5 ( 0xdead , V_10 + V_118 ) ;
F_5 ( 0xdead , V_10 + V_118 ) ;
F_5 ( 0xdead , V_10 + V_118 ) ;
F_5 ( 0x0000 , V_10 + V_118 ) ;
F_5 ( V_112 + V_170 + 0x16 , V_10 + V_118 ) ;
F_5 ( V_112 + 0x20 , V_10 + V_118 ) ;
F_5 ( 0 , V_10 + V_118 ) ;
F_5 ( V_170 - 0x20 , V_10 + V_118 ) ;
V_38 -> V_171 = V_112 ;
V_112 += V_170 ;
} while ( V_112 <= V_38 -> V_150 - V_170 );
F_5 ( V_38 -> V_169 + 6 , V_10 + V_105 ) ;
F_5 ( V_38 -> V_169 + 0x16 , V_10 + V_118 ) ;
F_5 ( V_38 -> V_171 + 4 , V_10 + V_105 ) ;
F_5 ( V_38 -> V_169 , V_10 + V_118 ) ;
F_5 ( V_38 -> V_171 + 0x16 + 2 , V_10 + V_105 ) ;
F_5 ( V_38 -> V_169 + 0x16 , V_10 + V_118 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_34 * V_38 = F_29 ( V_2 ) ;
unsigned short V_10 = V_2 -> V_3 ;
int V_29 ;
#if V_39 > 6
F_30 ( L_53 , V_2 -> V_36 ) ;
#endif
V_38 -> V_51 = 0 ;
F_8 ( V_2 ) ;
F_9 ( V_49 | V_41 [ V_2 -> V_12 ] , V_10 + V_50 ) ;
F_5 ( V_38 -> V_150 & ~ 31 , V_10 + V_88 ) ;
F_5 ( V_38 -> V_48 ? 0x0001 : 0x0000 , V_10 + 0x8006 ) ;
F_5 ( 0x0000 , V_10 + 0x8008 ) ;
F_5 ( 0x0000 , V_10 + 0x800a ) ;
F_5 ( 0x0000 , V_10 + 0x800c ) ;
F_5 ( 0x0000 , V_10 + 0x800e ) ;
for ( V_29 = 0 ; V_29 < F_98 ( V_172 ) * 2 ; V_29 += 32 ) {
int V_173 ;
F_5 ( V_29 , V_10 + V_88 ) ;
for ( V_173 = 0 ; V_173 < 16 && ( V_29 + V_173 ) / 2 < F_98 ( V_172 ) ; V_173 += 2 )
F_5 ( V_172 [ ( V_29 + V_173 ) / 2 ] ,
V_10 + 0x4000 + V_173 ) ;
for ( V_173 = 0 ; V_173 < 16 && ( V_29 + V_173 + 16 ) / 2 < F_98 ( V_172 ) ; V_173 += 2 )
F_5 ( V_172 [ ( V_29 + V_173 + 16 ) / 2 ] ,
V_10 + 0x8000 + V_173 ) ;
}
F_5 ( V_174 & ~ 31 , V_10 + V_88 ) ;
V_29 = F_2 ( V_10 + F_12 ( V_174 ) ) ;
F_5 ( ( V_2 -> V_67 & V_175 ) ? ( V_29 | 1 ) : ( V_29 & ~ 1 ) ,
V_10 + F_12 ( V_174 ) ) ;
V_38 -> V_176 = V_2 -> V_67 & V_175 ;
#if 0
eexp_setup_filter(dev);
#endif
F_5 ( V_177 & ~ 31 , V_10 + V_88 ) ;
F_5 ( ( ( unsigned short * ) V_2 -> V_146 ) [ 0 ] , V_10 + F_12 ( V_177 ) ) ;
F_5 ( ( ( unsigned short * ) V_2 -> V_146 ) [ 1 ] ,
V_10 + F_12 ( V_177 + 2 ) ) ;
F_5 ( ( ( unsigned short * ) V_2 -> V_146 ) [ 2 ] ,
V_10 + F_12 ( V_177 + 4 ) ) ;
F_40 ( V_2 ) ;
F_67 ( V_2 ) ;
F_9 ( 0 , V_10 + V_56 ) ;
F_70 ( 5 ) ;
F_4 ( V_2 , 0xf000 ) ;
F_9 ( 0 , V_10 + V_54 ) ;
F_5 ( 0 , V_10 + V_88 ) ;
{
unsigned short V_178 = 50 , V_179 = 5 ;
while ( F_2 ( V_10 + 0x4000 ) )
{
if ( ! -- V_178 )
{
F_30 ( V_43 L_54 ,
V_2 -> V_36 ) ;
F_4 ( V_2 , 0 ) ;
F_9 ( 0 , V_10 + V_54 ) ;
V_178 = 100 ;
if ( ! -- V_179 )
{
F_30 ( V_43 L_55 ,
V_2 -> V_36 ) ;
return;
}
}
}
}
F_6 ( V_2 , V_180 ) ;
F_4 ( V_2 , 0xf000 | V_63 ) ;
F_9 ( 0 , V_10 + V_54 ) ;
{
unsigned short V_181 = 50 , V_182 = 5 ;
while ( ! F_1 ( V_2 ) )
{
if ( ! -- V_181 )
{
if ( -- V_182 )
{
F_30 ( V_43 L_56 ,
V_2 -> V_36 , F_1 ( V_2 ) , F_3 ( V_2 ) ) ;
F_6 ( V_2 , V_180 ) ;
F_4 ( V_2 , 0xf000 | V_63 ) ;
F_9 ( 0 , V_10 + V_54 ) ;
V_181 = 100 ;
}
else
{
F_30 ( V_43 L_57 , V_2 -> V_36 ) ;
return;
}
}
}
}
F_11 ( V_2 ) ;
F_9 ( V_109 | V_41 [ V_2 -> V_12 ] , V_10 + V_50 ) ;
V_38 -> V_66 = V_57 ;
#if V_39 > 6
F_30 ( L_58 , V_2 -> V_36 ) ;
#endif
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_183 * V_184 ;
unsigned short V_10 = V_2 -> V_3 ;
int V_185 = F_100 ( V_2 ) ;
int V_29 ;
if ( V_185 > 8 ) {
F_30 ( V_69 L_59 ,
V_2 -> V_36 , V_185 ) ;
V_185 = 8 ;
}
F_5 ( V_186 & ~ 31 , V_10 + V_88 ) ;
F_5 ( 6 * V_185 , V_10 + F_12 ( V_186 ) ) ;
V_29 = 0 ;
F_101 (ha, dev) {
unsigned short * V_80 = ( unsigned short * ) V_184 -> V_7 ;
if ( V_29 == V_185 )
break;
F_5 ( ( V_187 + ( 6 * V_29 ) ) & ~ 31 , V_10 + V_88 ) ;
F_5 ( V_80 [ 0 ] , V_10 + F_12 ( V_187 + ( 6 * V_29 ) ) ) ;
F_5 ( ( V_187 + ( 6 * V_29 ) + 2 ) & ~ 31 , V_10 + V_88 ) ;
F_5 ( V_80 [ 1 ] , V_10 + F_12 ( V_187 + ( 6 * V_29 ) + 2 ) ) ;
F_5 ( ( V_187 + ( 6 * V_29 ) + 4 ) & ~ 31 , V_10 + V_88 ) ;
F_5 ( V_80 [ 2 ] , V_10 + F_12 ( V_187 + ( 6 * V_29 ) + 4 ) ) ;
V_29 ++ ;
}
}
static void
F_102 ( struct V_1 * V_2 )
{
unsigned short V_10 = V_2 -> V_3 ;
struct V_34 * V_38 = F_29 ( V_2 ) ;
int V_188 = 0 , V_29 ;
if ( ( V_2 -> V_67 & V_175 ) != V_38 -> V_176 ) {
F_5 ( V_174 & ~ 31 , V_10 + V_88 ) ;
V_29 = F_2 ( V_10 + F_12 ( V_174 ) ) ;
F_5 ( ( V_2 -> V_67 & V_175 ) ? ( V_29 | 1 ) : ( V_29 & ~ 1 ) ,
V_10 + F_12 ( V_174 ) ) ;
V_38 -> V_176 = V_2 -> V_67 & V_175 ;
V_188 = 1 ;
}
if ( ! ( V_2 -> V_67 & V_175 ) ) {
F_99 ( V_2 ) ;
if ( V_38 -> V_189 != F_100 ( V_2 ) ) {
V_188 = 1 ;
V_38 -> V_189 = F_100 ( V_2 ) ;
}
}
if ( V_188 ) {
unsigned long V_190 ;
F_4 ( V_2 , V_52 ) ;
F_9 ( 0 , V_10 + V_54 ) ;
F_9 ( 0 , V_10 + V_54 ) ;
#if 0
printk("%s: waiting for CU to go suspended\n", dev->name);
#endif
V_190 = V_57 ;
while ( ( F_59 ( F_1 ( V_2 ) ) == 2 ) &&
( F_62 ( V_57 , V_190 + 2000 ) ) ) ;
if ( F_59 ( F_1 ( V_2 ) ) == 2 )
F_30 ( L_60 , V_2 -> V_36 ) ;
V_38 -> V_51 &= ~ ( V_84 ) ;
F_6 ( V_2 , V_180 ) ;
F_4 ( V_2 , V_63 ) ;
F_9 ( 0 , V_10 + V_54 ) ;
}
}
int T_1 F_103 ( void )
{
struct V_1 * V_2 ;
int V_191 , V_192 = 0 ;
for ( V_191 = 0 ; V_191 < V_193 ; V_191 ++ ) {
V_2 = F_24 ( sizeof( struct V_34 ) ) ;
V_2 -> V_12 = V_12 [ V_191 ] ;
V_2 -> V_3 = V_194 [ V_191 ] ;
if ( V_194 [ V_191 ] == 0 ) {
if ( V_191 )
break;
F_30 ( V_195 L_61 ) ;
}
if ( F_13 ( V_2 ) == 0 ) {
V_196 [ V_191 ] = V_2 ;
V_192 ++ ;
continue;
}
F_30 ( V_43 L_62 , V_194 [ V_191 ] ) ;
F_27 ( V_2 ) ;
break;
}
if ( V_192 )
return 0 ;
return - V_27 ;
}
void T_4 F_104 ( void )
{
int V_191 ;
for ( V_191 = 0 ; V_191 < V_193 ; V_191 ++ ) {
struct V_1 * V_2 = V_196 [ V_191 ] ;
if ( V_2 ) {
F_105 ( V_2 ) ;
F_27 ( V_2 ) ;
}
}
}
