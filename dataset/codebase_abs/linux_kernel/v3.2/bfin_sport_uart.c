static inline void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_2 ( L_1 , V_4 , V_3 ,
V_2 -> V_5 , V_2 -> V_6 ) ;
__asm__ __volatile__ (
"%[val] <<= 1;"
"%[val] = %[val] & %[mask1];"
"%[val] = %[val] | %[mask2];"
: [val]"+d"(value)
: [mask1]"d"(up->txmask1), [mask2]"d"(up->txmask2)
: "ASTAT"
);
F_2 ( L_2 , V_4 , V_3 ) ;
F_3 ( V_2 , V_3 ) ;
}
static inline unsigned char F_4 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
unsigned char V_7 ;
T_1 V_8 , V_9 , V_10 , V_11 ;
if ( ( V_2 -> V_12 + V_2 -> V_13 ) > 7 )
V_3 = F_5 ( V_2 ) ;
else
V_3 = F_6 ( V_2 ) ;
F_2 ( L_3 , V_4 , V_3 ,
V_2 -> V_12 , V_2 -> V_14 ) ;
__asm__ __volatile__ (
"%[extr] = 0;"
"%[mask1] = %[rxmask];"
"%[mask2] = 0x0200(Z);"
"%[shift] = 0;"
"LSETUP(.Lloop_s, .Lloop_e) LC0 = %[lc];"
".Lloop_s:"
"%[tmp] = extract(%[val], %[mask1].L)(Z);"
"%[tmp] <<= %[shift];"
"%[extr] = %[extr] | %[tmp];"
"%[mask1] = %[mask1] - %[mask2];"
".Lloop_e:"
"%[shift] += 1;"
: [extr]"=&d"(extract), [shift]"=&d"(tmp_shift), [tmp]"=&d"(tmp),
[mask1]"=&d"(tmp_mask1), [mask2]"=&d"(tmp_mask2)
: [val]"d"(value), [rxmask]"d"(up->rxmask), [lc]"a"(up->csize)
: "ASTAT", "LB0", "LC0", "LT0"
);
F_2 ( L_4 , V_7 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 , int V_15 , int V_16 )
{
int V_17 , V_18 ;
unsigned int V_19 = F_8 () ;
F_9 ( V_2 , ( V_20 | V_21 | V_22 | V_23 | V_24 ) ) ;
F_10 ( V_2 , V_15 + 1 ) ;
F_2 ( L_5 , V_4 , F_11 ( V_2 ) , F_12 ( V_2 ) ) ;
F_13 ( V_2 , ( V_25 | V_26 | V_27 | V_28 | V_29 ) ) ;
F_14 ( V_2 , ( V_15 + 1 ) * 2 - 1 ) ;
F_2 ( L_6 , V_4 , F_15 ( V_2 ) , F_16 ( V_2 ) ) ;
V_17 = V_19 / ( 2 * V_16 ) - 1 ;
V_18 = V_19 / ( 2 * V_16 * 2 * 97 / 100 ) - 1 ;
F_17 ( V_2 , V_17 ) ;
F_18 ( V_2 , V_18 ) ;
F_19 () ;
F_2 ( L_7 ,
V_4 , V_19 , V_16 , V_17 , V_18 ) ;
return 0 ;
}
static T_2 F_20 ( int V_30 , void * V_31 )
{
struct V_1 * V_2 = V_31 ;
struct V_32 * V_33 = V_2 -> V_34 . V_35 -> V_34 . V_33 ;
unsigned int V_36 ;
F_21 ( & V_2 -> V_34 . V_37 ) ;
while ( F_22 ( V_2 ) & V_38 ) {
V_36 = F_4 ( V_2 ) ;
V_2 -> V_34 . V_39 . V_40 ++ ;
if ( ! F_23 ( & V_2 -> V_34 , V_36 ) )
F_24 ( V_33 , V_36 , V_41 ) ;
}
F_25 ( V_33 ) ;
F_26 ( & V_2 -> V_34 . V_37 ) ;
return V_42 ;
}
static T_2 F_27 ( int V_30 , void * V_31 )
{
struct V_1 * V_2 = V_31 ;
F_21 ( & V_2 -> V_34 . V_37 ) ;
F_28 ( V_2 ) ;
F_26 ( & V_2 -> V_34 . V_37 ) ;
return V_42 ;
}
static T_2 F_29 ( int V_30 , void * V_31 )
{
struct V_1 * V_2 = V_31 ;
struct V_32 * V_33 = V_2 -> V_34 . V_35 -> V_34 . V_33 ;
unsigned int V_43 = F_22 ( V_2 ) ;
F_21 ( & V_2 -> V_34 . V_37 ) ;
if ( V_43 & V_44 ) {
V_2 -> V_34 . V_39 . V_45 ++ ;
F_24 ( V_33 , 0 , V_46 ) ;
F_30 ( V_2 , V_44 ) ;
}
if ( V_43 & ( V_47 | V_48 | V_49 ) ) {
F_31 ( L_8 ,
( V_43 & V_47 ) ? L_9 : L_10 ,
( V_43 & V_48 ) ? L_11 : L_10 ,
( V_43 & V_49 ) ? L_12 : L_10 ) ;
F_9 ( V_2 , F_11 ( V_2 ) & ~ V_50 ) ;
F_13 ( V_2 , F_15 ( V_2 ) & ~ V_51 ) ;
}
F_19 () ;
F_26 ( & V_2 -> V_34 . V_37 ) ;
return V_42 ;
}
static unsigned int F_32 ( struct V_52 * V_34 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
if ( V_2 -> V_53 < 0 )
return V_54 | V_55 | V_56 ;
if ( F_33 ( V_2 ) )
return V_54 | V_55 | V_56 ;
else
return V_55 | V_56 ;
}
static void F_34 ( struct V_52 * V_34 , unsigned int V_57 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
if ( V_2 -> V_58 < 0 )
return;
if ( V_57 & V_59 )
F_35 ( V_2 ) ;
else
F_36 ( V_2 ) ;
}
static T_2 F_37 ( int V_30 , void * V_31 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 ;
unsigned int V_60 ;
V_60 = F_32 ( & V_2 -> V_34 ) ;
F_38 ( & V_2 -> V_34 , V_60 & V_54 ) ;
return V_42 ;
}
static unsigned int F_32 ( struct V_52 * V_34 )
{
F_2 ( L_13 , V_4 ) ;
return V_54 | V_61 | V_55 ;
}
static void F_34 ( struct V_52 * V_34 , unsigned int V_57 )
{
F_2 ( L_13 , V_4 ) ;
}
static int F_39 ( struct V_52 * V_34 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
int V_62 ;
F_2 ( L_13 , V_4 ) ;
V_62 = F_40 ( V_2 -> V_34 . V_30 , F_20 , 0 ,
L_14 , V_2 ) ;
if ( V_62 ) {
F_41 ( V_34 -> V_63 , L_15 ) ;
return V_62 ;
}
V_62 = F_40 ( V_2 -> V_34 . V_30 + 1 , F_27 , 0 ,
L_16 , V_2 ) ;
if ( V_62 ) {
F_41 ( V_34 -> V_63 , L_17 ) ;
goto V_64;
}
V_62 = F_40 ( V_2 -> V_65 , F_29 , 0 ,
L_18 , V_2 ) ;
if ( V_62 ) {
F_41 ( V_34 -> V_63 , L_19 ) ;
goto V_66;
}
#ifdef F_42
if ( V_2 -> V_53 >= 0 ) {
if ( F_40 ( F_43 ( V_2 -> V_53 ) ,
F_37 ,
V_67 | V_68 |
0 , L_20 , V_2 ) ) {
V_2 -> V_53 = - 1 ;
F_44 ( V_34 -> V_63 , L_21 ) ;
}
}
if ( V_2 -> V_58 >= 0 )
F_45 ( V_2 -> V_58 , 0 ) ;
#endif
return 0 ;
V_66:
F_46 ( V_2 -> V_34 . V_30 + 1 , V_2 ) ;
V_64:
F_46 ( V_2 -> V_34 . V_30 , V_2 ) ;
return V_62 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_69 * V_70 = & V_2 -> V_34 . V_35 -> V_70 ;
if ( F_22 ( V_2 ) & V_71 )
return 0 ;
if ( V_2 -> V_34 . V_72 ) {
F_1 ( V_2 , V_2 -> V_34 . V_72 ) ;
V_2 -> V_34 . V_39 . V_73 ++ ;
V_2 -> V_34 . V_72 = 0 ;
return 1 ;
}
if ( F_47 ( V_70 ) || F_48 ( & V_2 -> V_34 ) ) {
if ( F_22 ( V_2 ) & V_74 )
F_49 ( & V_2 -> V_34 ) ;
return 0 ;
}
while( ! ( F_22 ( V_2 ) & V_71 ) && ! F_47 ( V_70 ) ) {
F_1 ( V_2 , V_70 -> V_75 [ V_70 -> V_76 ] ) ;
V_70 -> V_76 = ( V_70 -> V_76 + 1 ) & ( V_77 - 1 ) ;
V_2 -> V_34 . V_39 . V_73 ++ ;
}
if ( F_50 ( V_70 ) < V_78 )
F_51 ( & V_2 -> V_34 ) ;
return 1 ;
}
static unsigned int F_52 ( struct V_52 * V_34 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
unsigned int V_43 ;
V_43 = F_22 ( V_2 ) ;
F_2 ( L_22 , V_4 , V_43 ) ;
if ( V_43 & V_74 ) {
return V_79 ;
} else
return 0 ;
}
static void F_49 ( struct V_52 * V_34 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
F_2 ( L_13 , V_4 ) ;
if ( ! ( F_11 ( V_2 ) & V_50 ) )
return;
F_3 ( V_2 , 0xffff ) ;
while ( ! ( F_22 ( V_2 ) & V_74 ) )
F_53 () ;
F_9 ( V_2 , ( F_11 ( V_2 ) & ~ V_50 ) ) ;
F_19 () ;
return;
}
static void F_54 ( struct V_52 * V_34 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
F_2 ( L_13 , V_4 ) ;
if ( F_28 ( V_2 ) ) {
F_9 ( V_2 , ( F_11 ( V_2 ) | V_50 ) ) ;
F_19 () ;
}
F_2 ( L_23 , V_4 ) ;
}
static void F_55 ( struct V_52 * V_34 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
F_2 ( L_13 , V_4 ) ;
F_13 ( V_2 , ( F_15 ( V_2 ) & ~ V_51 ) ) ;
F_19 () ;
}
static void F_56 ( struct V_52 * V_34 )
{
F_2 ( L_13 , V_4 ) ;
}
static void F_57 ( struct V_52 * V_34 , int V_80 )
{
F_2 ( L_13 , V_4 ) ;
}
static void F_58 ( struct V_52 * V_34 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
F_59 ( V_34 -> V_63 , L_13 , V_4 ) ;
F_9 ( V_2 , ( F_11 ( V_2 ) & ~ V_50 ) ) ;
F_13 ( V_2 , ( F_15 ( V_2 ) & ~ V_51 ) ) ;
F_19 () ;
F_46 ( V_2 -> V_34 . V_30 , V_2 ) ;
F_46 ( V_2 -> V_34 . V_30 + 1 , V_2 ) ;
F_46 ( V_2 -> V_65 , V_2 ) ;
#ifdef F_42
if ( V_2 -> V_53 >= 0 )
F_46 ( F_43 ( V_2 -> V_53 ) , V_2 ) ;
#endif
}
static const char * F_60 ( struct V_52 * V_34 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
F_2 ( L_13 , V_4 ) ;
return V_2 -> V_34 . type == V_81 ? L_24 : NULL ;
}
static void F_61 ( struct V_52 * V_34 )
{
F_2 ( L_13 , V_4 ) ;
}
static int F_62 ( struct V_52 * V_34 )
{
F_2 ( L_13 , V_4 ) ;
return 0 ;
}
static void F_63 ( struct V_52 * V_34 , int V_82 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
F_2 ( L_13 , V_4 ) ;
V_2 -> V_34 . type = V_81 ;
}
static int F_64 ( struct V_52 * V_34 , struct V_83 * V_84 )
{
F_2 ( L_13 , V_4 ) ;
return 0 ;
}
static void F_65 ( struct V_52 * V_34 ,
struct V_85 * V_86 , struct V_85 * V_87 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
unsigned long V_82 ;
int V_88 ;
F_2 ( L_25 , V_4 , V_86 -> V_89 ) ;
switch ( V_86 -> V_89 & V_90 ) {
case V_91 :
V_2 -> V_12 = 8 ;
break;
case V_92 :
V_2 -> V_12 = 7 ;
break;
case V_93 :
V_2 -> V_12 = 6 ;
break;
case V_94 :
V_2 -> V_12 = 5 ;
break;
default:
F_66 ( L_26 ) ;
}
if ( V_86 -> V_89 & V_95 ) {
V_2 -> V_13 = 1 ;
}
if ( V_86 -> V_89 & V_96 ) {
F_66 ( L_27 ) ;
}
F_67 ( & V_2 -> V_34 . V_37 , V_82 ) ;
V_34 -> V_97 = 0 ;
V_34 -> V_98 = 0 ;
V_2 -> V_14 = 0x01 | ( ( ( V_2 -> V_12 + V_2 -> V_13 ) * 2 - 1 ) << 0x8 ) ;
for ( V_88 = 0 , V_2 -> V_5 = 0 ; V_88 < V_2 -> V_12 ; V_88 ++ )
V_2 -> V_5 |= ( 1 << V_88 ) ;
V_2 -> V_6 = ( 1 << V_88 ) ;
if ( V_2 -> V_13 ) {
++ V_88 ;
V_2 -> V_6 |= ( 1 << V_88 ) ;
}
V_2 -> V_5 <<= 1 ;
V_2 -> V_6 <<= 1 ;
V_34 -> V_99 = F_68 ( V_34 , V_86 , V_87 , 0 , F_8 () / 16 ) ;
F_9 ( V_2 , F_11 ( V_2 ) & ~ V_50 ) ;
F_13 ( V_2 , F_15 ( V_2 ) & ~ V_51 ) ;
F_7 ( V_2 , V_2 -> V_12 + V_2 -> V_13 , V_34 -> V_99 ) ;
F_3 ( V_2 , 0xffff ) ;
F_3 ( V_2 , 0xffff ) ;
F_9 ( V_2 , ( F_11 ( V_2 ) | V_50 ) ) ;
F_19 () ;
while ( ! ( F_22 ( V_2 ) & V_74 ) )
F_53 () ;
F_9 ( V_2 , F_11 ( V_2 ) & ~ V_50 ) ;
F_19 () ;
F_69 ( V_34 , V_86 -> V_89 , V_34 -> V_99 ) ;
F_13 ( V_2 , F_15 ( V_2 ) | V_51 ) ;
F_19 () ;
F_70 ( & V_2 -> V_34 . V_37 , V_82 ) ;
}
static int T_3
F_71 ( struct V_100 * V_101 , char * V_102 )
{
struct V_1 * V_2 ;
int V_103 = 57600 ;
int V_104 = 8 ;
int V_105 = 'n' ;
# ifdef F_42
int V_106 = 'r' ;
# else
int V_106 = 'n' ;
# endif
if ( V_101 -> V_107 < 0 || V_101 -> V_107 >= V_108 )
return - V_109 ;
V_2 = V_110 [ V_101 -> V_107 ] ;
if ( ! V_2 )
return - V_109 ;
if ( V_102 )
F_72 ( V_102 , & V_103 , & V_105 , & V_104 , & V_106 ) ;
return F_73 ( & V_2 -> V_34 , V_101 , V_103 , V_105 , V_104 , V_106 ) ;
}
static void F_74 ( struct V_52 * V_34 , int V_36 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
while ( F_22 ( V_2 ) & V_71 )
F_75 () ;
F_1 ( V_2 , V_36 ) ;
}
static void
F_76 ( struct V_100 * V_101 , const char * V_111 , unsigned int V_112 )
{
struct V_1 * V_2 = V_110 [ V_101 -> V_107 ] ;
unsigned long V_82 ;
F_67 ( & V_2 -> V_34 . V_37 , V_82 ) ;
if ( F_11 ( V_2 ) & V_50 )
F_77 ( & V_2 -> V_34 , V_111 , V_112 , F_74 ) ;
else {
while ( F_22 ( V_2 ) & V_71 )
F_75 () ;
F_3 ( V_2 , 0xffff ) ;
F_9 ( V_2 , ( F_11 ( V_2 ) | V_50 ) ) ;
F_19 () ;
F_77 ( & V_2 -> V_34 , V_111 , V_112 , F_74 ) ;
while ( F_22 ( V_2 ) & V_71 )
F_75 () ;
F_3 ( V_2 , 0xffff ) ;
while ( ! ( F_22 ( V_2 ) & V_74 ) )
F_75 () ;
F_9 ( V_2 , ( F_11 ( V_2 ) & ~ V_50 ) ) ;
F_19 () ;
}
F_70 ( & V_2 -> V_34 . V_37 , V_82 ) ;
}
static int F_78 ( struct V_113 * V_63 )
{
struct V_1 * V_114 = F_79 ( V_63 ) ;
F_59 ( V_63 , L_13 , V_4 ) ;
if ( V_114 )
F_80 ( & V_115 , & V_114 -> V_34 ) ;
return 0 ;
}
static int F_81 ( struct V_113 * V_63 )
{
struct V_1 * V_114 = F_79 ( V_63 ) ;
F_59 ( V_63 , L_13 , V_4 ) ;
if ( V_114 )
F_82 ( & V_115 , & V_114 -> V_34 ) ;
return 0 ;
}
static int T_4 F_83 ( struct V_116 * V_117 )
{
struct V_118 * V_119 ;
struct V_1 * V_114 ;
int V_62 = 0 ;
F_59 ( & V_117 -> V_63 , L_13 , V_4 ) ;
if ( V_117 -> V_120 < 0 || V_117 -> V_120 >= V_108 ) {
F_41 ( & V_117 -> V_63 , L_28 ) ;
return - V_121 ;
}
if ( V_110 [ V_117 -> V_120 ] == NULL ) {
V_110 [ V_117 -> V_120 ] =
F_84 ( sizeof( struct V_1 ) , V_122 ) ;
V_114 = V_110 [ V_117 -> V_120 ] ;
if ( ! V_114 ) {
F_41 ( & V_117 -> V_63 ,
L_29 ) ;
return - V_123 ;
}
V_62 = F_85 (
( unsigned short * ) V_117 -> V_63 . V_124 , V_125 ) ;
if ( V_62 ) {
F_41 ( & V_117 -> V_63 ,
L_30 ) ;
goto V_126;
}
F_86 ( & V_114 -> V_34 . V_37 ) ;
V_114 -> V_34 . V_127 = V_128 ,
V_114 -> V_34 . V_129 = & V_130 ;
V_114 -> V_34 . line = V_117 -> V_120 ;
V_114 -> V_34 . V_131 = V_132 ;
V_114 -> V_34 . V_82 = V_133 ;
V_119 = F_87 ( V_117 , V_134 , 0 ) ;
if ( V_119 == NULL ) {
F_41 ( & V_117 -> V_63 , L_31 ) ;
V_62 = - V_121 ;
goto V_135;
}
V_114 -> V_34 . V_136 = F_88 ( V_119 -> V_137 , F_89 ( V_119 ) ) ;
if ( ! V_114 -> V_34 . V_136 ) {
F_41 ( & V_117 -> V_63 , L_32 ) ;
V_62 = - V_138 ;
goto V_135;
}
V_114 -> V_34 . V_139 = V_119 -> V_137 ;
V_114 -> V_34 . V_30 = F_90 ( V_117 , 0 ) ;
if ( ( int ) V_114 -> V_34 . V_30 < 0 ) {
F_41 ( & V_117 -> V_63 , L_33 ) ;
V_62 = - V_121 ;
goto V_140;
}
V_114 -> V_65 = F_90 ( V_117 , 1 ) ;
if ( V_114 -> V_65 < 0 ) {
F_41 ( & V_117 -> V_63 , L_34 ) ;
V_62 = - V_121 ;
goto V_140;
}
#ifdef F_42
V_119 = F_87 ( V_117 , V_141 , 0 ) ;
if ( V_119 == NULL )
V_114 -> V_53 = - 1 ;
else
V_114 -> V_53 = V_119 -> V_137 ;
V_119 = F_87 ( V_117 , V_141 , 1 ) ;
if ( V_119 == NULL )
V_114 -> V_58 = - 1 ;
else
V_114 -> V_58 = V_119 -> V_137 ;
if ( V_114 -> V_58 >= 0 )
F_91 ( V_114 -> V_58 , V_125 ) ;
#endif
}
#ifdef F_92
if ( ! F_93 ( V_117 ) ) {
#endif
V_114 = V_110 [ V_117 -> V_120 ] ;
V_114 -> V_34 . V_63 = & V_117 -> V_63 ;
F_94 ( & V_117 -> V_63 , V_114 ) ;
V_62 = F_95 ( & V_115 , & V_114 -> V_34 ) ;
#ifdef F_92
}
#endif
if ( ! V_62 )
return 0 ;
if ( V_114 ) {
V_140:
F_96 ( V_114 -> V_34 . V_136 ) ;
V_135:
F_97 (
( unsigned short * ) V_117 -> V_63 . V_124 ) ;
V_126:
F_98 ( V_114 ) ;
V_110 [ V_117 -> V_120 ] = NULL ;
}
return V_62 ;
}
static int T_5 F_99 ( struct V_116 * V_117 )
{
struct V_1 * V_114 = F_100 ( V_117 ) ;
F_59 ( & V_117 -> V_63 , L_13 , V_4 ) ;
F_94 ( & V_117 -> V_63 , NULL ) ;
if ( V_114 ) {
F_101 ( & V_115 , & V_114 -> V_34 ) ;
#ifdef F_102
if ( V_114 -> V_58 >= 0 )
F_103 ( V_114 -> V_58 ) ;
#endif
F_96 ( V_114 -> V_34 . V_136 ) ;
F_97 (
( unsigned short * ) V_117 -> V_63 . V_124 ) ;
F_98 ( V_114 ) ;
V_110 [ V_117 -> V_120 ] = NULL ;
}
return 0 ;
}
static int T_3 F_104 ( void )
{
F_105 ( & V_142 , V_125 ) ;
F_106 ( V_143 ,
V_108 , 0 ) ;
F_107 ( & V_144 ) ;
return 0 ;
}
static int T_3 F_108 ( void )
{
int V_62 ;
F_109 ( L_35 ) ;
V_62 = F_110 ( & V_115 ) ;
if ( V_62 ) {
F_31 ( L_36 ,
V_115 . V_145 , V_62 ) ;
return V_62 ;
}
V_62 = F_111 ( & V_146 ) ;
if ( V_62 ) {
F_31 ( L_37 , V_62 ) ;
F_112 ( & V_115 ) ;
}
return V_62 ;
}
static void T_6 F_113 ( void )
{
F_114 ( & V_146 ) ;
F_112 ( & V_115 ) ;
}
