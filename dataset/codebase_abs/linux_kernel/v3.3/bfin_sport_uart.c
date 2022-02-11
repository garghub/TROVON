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
if ( V_2 -> V_58 >= 0 ) {
if ( F_45 ( V_2 -> V_58 , V_69 ) ) {
F_44 ( V_34 -> V_63 , L_22 , V_2 -> V_58 ) ;
V_2 -> V_58 = - 1 ;
} else
F_46 ( V_2 -> V_58 , 0 ) ;
}
#endif
return 0 ;
V_66:
F_47 ( V_2 -> V_34 . V_30 + 1 , V_2 ) ;
V_64:
F_47 ( V_2 -> V_34 . V_30 , V_2 ) ;
return V_62 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_70 * V_71 = & V_2 -> V_34 . V_35 -> V_71 ;
if ( F_22 ( V_2 ) & V_72 )
return 0 ;
if ( V_2 -> V_34 . V_73 ) {
F_1 ( V_2 , V_2 -> V_34 . V_73 ) ;
V_2 -> V_34 . V_39 . V_74 ++ ;
V_2 -> V_34 . V_73 = 0 ;
return 1 ;
}
if ( F_48 ( V_71 ) || F_49 ( & V_2 -> V_34 ) ) {
if ( F_22 ( V_2 ) & V_75 )
F_50 ( & V_2 -> V_34 ) ;
return 0 ;
}
while( ! ( F_22 ( V_2 ) & V_72 ) && ! F_48 ( V_71 ) ) {
F_1 ( V_2 , V_71 -> V_76 [ V_71 -> V_77 ] ) ;
V_71 -> V_77 = ( V_71 -> V_77 + 1 ) & ( V_78 - 1 ) ;
V_2 -> V_34 . V_39 . V_74 ++ ;
}
if ( F_51 ( V_71 ) < V_79 )
F_52 ( & V_2 -> V_34 ) ;
return 1 ;
}
static unsigned int F_53 ( struct V_52 * V_34 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
unsigned int V_43 ;
V_43 = F_22 ( V_2 ) ;
F_2 ( L_23 , V_4 , V_43 ) ;
if ( V_43 & V_75 ) {
return V_80 ;
} else
return 0 ;
}
static void F_50 ( struct V_52 * V_34 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
F_2 ( L_13 , V_4 ) ;
if ( ! ( F_11 ( V_2 ) & V_50 ) )
return;
F_3 ( V_2 , 0xffff ) ;
while ( ! ( F_22 ( V_2 ) & V_75 ) )
F_54 () ;
F_9 ( V_2 , ( F_11 ( V_2 ) & ~ V_50 ) ) ;
F_19 () ;
return;
}
static void F_55 ( struct V_52 * V_34 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
F_2 ( L_13 , V_4 ) ;
if ( F_28 ( V_2 ) ) {
F_9 ( V_2 , ( F_11 ( V_2 ) | V_50 ) ) ;
F_19 () ;
}
F_2 ( L_24 , V_4 ) ;
}
static void F_56 ( struct V_52 * V_34 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
F_2 ( L_13 , V_4 ) ;
F_13 ( V_2 , ( F_15 ( V_2 ) & ~ V_51 ) ) ;
F_19 () ;
}
static void F_57 ( struct V_52 * V_34 )
{
F_2 ( L_13 , V_4 ) ;
}
static void F_58 ( struct V_52 * V_34 , int V_81 )
{
F_2 ( L_13 , V_4 ) ;
}
static void F_59 ( struct V_52 * V_34 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
F_60 ( V_34 -> V_63 , L_13 , V_4 ) ;
F_9 ( V_2 , ( F_11 ( V_2 ) & ~ V_50 ) ) ;
F_13 ( V_2 , ( F_15 ( V_2 ) & ~ V_51 ) ) ;
F_19 () ;
F_47 ( V_2 -> V_34 . V_30 , V_2 ) ;
F_47 ( V_2 -> V_34 . V_30 + 1 , V_2 ) ;
F_47 ( V_2 -> V_65 , V_2 ) ;
#ifdef F_42
if ( V_2 -> V_53 >= 0 )
F_47 ( F_43 ( V_2 -> V_53 ) , V_2 ) ;
if ( V_2 -> V_58 >= 0 )
F_61 ( V_2 -> V_58 ) ;
#endif
}
static const char * F_62 ( struct V_52 * V_34 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
F_2 ( L_13 , V_4 ) ;
return V_2 -> V_34 . type == V_82 ? L_25 : NULL ;
}
static void F_63 ( struct V_52 * V_34 )
{
F_2 ( L_13 , V_4 ) ;
}
static int F_64 ( struct V_52 * V_34 )
{
F_2 ( L_13 , V_4 ) ;
return 0 ;
}
static void F_65 ( struct V_52 * V_34 , int V_83 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
F_2 ( L_13 , V_4 ) ;
V_2 -> V_34 . type = V_82 ;
}
static int F_66 ( struct V_52 * V_34 , struct V_84 * V_85 )
{
F_2 ( L_13 , V_4 ) ;
return 0 ;
}
static void F_67 ( struct V_52 * V_34 ,
struct V_86 * V_87 , struct V_86 * V_88 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
unsigned long V_83 ;
int V_89 ;
F_2 ( L_26 , V_4 , V_87 -> V_90 ) ;
switch ( V_87 -> V_90 & V_91 ) {
case V_92 :
V_2 -> V_12 = 8 ;
break;
case V_93 :
V_2 -> V_12 = 7 ;
break;
case V_94 :
V_2 -> V_12 = 6 ;
break;
case V_95 :
V_2 -> V_12 = 5 ;
break;
default:
F_68 ( L_27 ) ;
}
if ( V_87 -> V_90 & V_96 ) {
V_2 -> V_13 = 1 ;
}
if ( V_87 -> V_90 & V_97 ) {
F_68 ( L_28 ) ;
}
F_69 ( & V_2 -> V_34 . V_37 , V_83 ) ;
V_34 -> V_98 = 0 ;
V_34 -> V_99 = 0 ;
V_2 -> V_14 = 0x01 | ( ( ( V_2 -> V_12 + V_2 -> V_13 ) * 2 - 1 ) << 0x8 ) ;
for ( V_89 = 0 , V_2 -> V_5 = 0 ; V_89 < V_2 -> V_12 ; V_89 ++ )
V_2 -> V_5 |= ( 1 << V_89 ) ;
V_2 -> V_6 = ( 1 << V_89 ) ;
if ( V_2 -> V_13 ) {
++ V_89 ;
V_2 -> V_6 |= ( 1 << V_89 ) ;
}
V_2 -> V_5 <<= 1 ;
V_2 -> V_6 <<= 1 ;
V_34 -> V_100 = F_70 ( V_34 , V_87 , V_88 , 0 , F_8 () / 16 ) ;
F_9 ( V_2 , F_11 ( V_2 ) & ~ V_50 ) ;
F_13 ( V_2 , F_15 ( V_2 ) & ~ V_51 ) ;
F_7 ( V_2 , V_2 -> V_12 + V_2 -> V_13 , V_34 -> V_100 ) ;
F_3 ( V_2 , 0xffff ) ;
F_3 ( V_2 , 0xffff ) ;
F_9 ( V_2 , ( F_11 ( V_2 ) | V_50 ) ) ;
F_19 () ;
while ( ! ( F_22 ( V_2 ) & V_75 ) )
F_54 () ;
F_9 ( V_2 , F_11 ( V_2 ) & ~ V_50 ) ;
F_19 () ;
F_71 ( V_34 , V_87 -> V_90 , V_34 -> V_100 ) ;
F_13 ( V_2 , F_15 ( V_2 ) | V_51 ) ;
F_19 () ;
F_72 ( & V_2 -> V_34 . V_37 , V_83 ) ;
}
static int T_3
F_73 ( struct V_101 * V_102 , char * V_103 )
{
struct V_1 * V_2 ;
int V_104 = 57600 ;
int V_105 = 8 ;
int V_106 = 'n' ;
# ifdef F_42
int V_107 = 'r' ;
# else
int V_107 = 'n' ;
# endif
if ( V_102 -> V_108 < 0 || V_102 -> V_108 >= V_109 )
return - V_110 ;
V_2 = V_111 [ V_102 -> V_108 ] ;
if ( ! V_2 )
return - V_110 ;
if ( V_103 )
F_74 ( V_103 , & V_104 , & V_106 , & V_105 , & V_107 ) ;
return F_75 ( & V_2 -> V_34 , V_102 , V_104 , V_106 , V_105 , V_107 ) ;
}
static void F_76 ( struct V_52 * V_34 , int V_36 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
while ( F_22 ( V_2 ) & V_72 )
F_77 () ;
F_1 ( V_2 , V_36 ) ;
}
static void
F_78 ( struct V_101 * V_102 , const char * V_112 , unsigned int V_113 )
{
struct V_1 * V_2 = V_111 [ V_102 -> V_108 ] ;
unsigned long V_83 ;
F_69 ( & V_2 -> V_34 . V_37 , V_83 ) ;
if ( F_11 ( V_2 ) & V_50 )
F_79 ( & V_2 -> V_34 , V_112 , V_113 , F_76 ) ;
else {
while ( F_22 ( V_2 ) & V_72 )
F_77 () ;
F_3 ( V_2 , 0xffff ) ;
F_9 ( V_2 , ( F_11 ( V_2 ) | V_50 ) ) ;
F_19 () ;
F_79 ( & V_2 -> V_34 , V_112 , V_113 , F_76 ) ;
while ( F_22 ( V_2 ) & V_72 )
F_77 () ;
F_3 ( V_2 , 0xffff ) ;
while ( ! ( F_22 ( V_2 ) & V_75 ) )
F_77 () ;
F_9 ( V_2 , ( F_11 ( V_2 ) & ~ V_50 ) ) ;
F_19 () ;
}
F_72 ( & V_2 -> V_34 . V_37 , V_83 ) ;
}
static int F_80 ( struct V_114 * V_63 )
{
struct V_1 * V_115 = F_81 ( V_63 ) ;
F_60 ( V_63 , L_13 , V_4 ) ;
if ( V_115 )
F_82 ( & V_116 , & V_115 -> V_34 ) ;
return 0 ;
}
static int F_83 ( struct V_114 * V_63 )
{
struct V_1 * V_115 = F_81 ( V_63 ) ;
F_60 ( V_63 , L_13 , V_4 ) ;
if ( V_115 )
F_84 ( & V_116 , & V_115 -> V_34 ) ;
return 0 ;
}
static int T_4 F_85 ( struct V_117 * V_118 )
{
struct V_119 * V_120 ;
struct V_1 * V_115 ;
int V_62 = 0 ;
F_60 ( & V_118 -> V_63 , L_13 , V_4 ) ;
if ( V_118 -> V_121 < 0 || V_118 -> V_121 >= V_109 ) {
F_41 ( & V_118 -> V_63 , L_29 ) ;
return - V_122 ;
}
if ( V_111 [ V_118 -> V_121 ] == NULL ) {
V_111 [ V_118 -> V_121 ] =
F_86 ( sizeof( struct V_1 ) , V_123 ) ;
V_115 = V_111 [ V_118 -> V_121 ] ;
if ( ! V_115 ) {
F_41 ( & V_118 -> V_63 ,
L_30 ) ;
return - V_124 ;
}
V_62 = F_87 (
( unsigned short * ) V_118 -> V_63 . V_125 , V_69 ) ;
if ( V_62 ) {
F_41 ( & V_118 -> V_63 ,
L_31 ) ;
goto V_126;
}
F_88 ( & V_115 -> V_34 . V_37 ) ;
V_115 -> V_34 . V_127 = V_128 ,
V_115 -> V_34 . V_129 = & V_130 ;
V_115 -> V_34 . line = V_118 -> V_121 ;
V_115 -> V_34 . V_131 = V_132 ;
V_115 -> V_34 . V_83 = V_133 ;
V_120 = F_89 ( V_118 , V_134 , 0 ) ;
if ( V_120 == NULL ) {
F_41 ( & V_118 -> V_63 , L_32 ) ;
V_62 = - V_122 ;
goto V_135;
}
V_115 -> V_34 . V_136 = F_90 ( V_120 -> V_137 , F_91 ( V_120 ) ) ;
if ( ! V_115 -> V_34 . V_136 ) {
F_41 ( & V_118 -> V_63 , L_33 ) ;
V_62 = - V_138 ;
goto V_135;
}
V_115 -> V_34 . V_139 = V_120 -> V_137 ;
V_115 -> V_34 . V_30 = F_92 ( V_118 , 0 ) ;
if ( ( int ) V_115 -> V_34 . V_30 < 0 ) {
F_41 ( & V_118 -> V_63 , L_34 ) ;
V_62 = - V_122 ;
goto V_140;
}
V_115 -> V_65 = F_92 ( V_118 , 1 ) ;
if ( V_115 -> V_65 < 0 ) {
F_41 ( & V_118 -> V_63 , L_35 ) ;
V_62 = - V_122 ;
goto V_140;
}
#ifdef F_42
V_120 = F_89 ( V_118 , V_141 , 0 ) ;
if ( V_120 == NULL )
V_115 -> V_53 = - 1 ;
else {
V_115 -> V_53 = V_120 -> V_137 ;
V_115 -> V_34 . V_83 |= V_142 ;
}
V_120 = F_89 ( V_118 , V_141 , 1 ) ;
if ( V_120 == NULL )
V_115 -> V_58 = - 1 ;
else
V_115 -> V_58 = V_120 -> V_137 ;
#endif
}
#ifdef F_93
if ( ! F_94 ( V_118 ) ) {
#endif
V_115 = V_111 [ V_118 -> V_121 ] ;
V_115 -> V_34 . V_63 = & V_118 -> V_63 ;
F_95 ( & V_118 -> V_63 , V_115 ) ;
V_62 = F_96 ( & V_116 , & V_115 -> V_34 ) ;
#ifdef F_93
}
#endif
if ( ! V_62 )
return 0 ;
if ( V_115 ) {
V_140:
F_97 ( V_115 -> V_34 . V_136 ) ;
V_135:
F_98 (
( unsigned short * ) V_118 -> V_63 . V_125 ) ;
V_126:
F_99 ( V_115 ) ;
V_111 [ V_118 -> V_121 ] = NULL ;
}
return V_62 ;
}
static int T_5 F_100 ( struct V_117 * V_118 )
{
struct V_1 * V_115 = F_101 ( V_118 ) ;
F_60 ( & V_118 -> V_63 , L_13 , V_4 ) ;
F_95 ( & V_118 -> V_63 , NULL ) ;
if ( V_115 ) {
F_102 ( & V_116 , & V_115 -> V_34 ) ;
F_97 ( V_115 -> V_34 . V_136 ) ;
F_98 (
( unsigned short * ) V_118 -> V_63 . V_125 ) ;
F_99 ( V_115 ) ;
V_111 [ V_118 -> V_121 ] = NULL ;
}
return 0 ;
}
static int T_3 F_103 ( void )
{
F_104 ( & V_143 , V_69 ) ;
F_105 ( V_144 ,
V_109 , 0 ) ;
F_106 ( & V_145 ) ;
return 0 ;
}
static int T_3 F_107 ( void )
{
int V_62 ;
F_108 ( L_36 ) ;
V_62 = F_109 ( & V_116 ) ;
if ( V_62 ) {
F_31 ( L_37 ,
V_116 . V_146 , V_62 ) ;
return V_62 ;
}
V_62 = F_110 ( & V_147 ) ;
if ( V_62 ) {
F_31 ( L_38 , V_62 ) ;
F_111 ( & V_116 ) ;
}
return V_62 ;
}
static void T_6 F_112 ( void )
{
F_113 ( & V_147 ) ;
F_111 ( & V_116 ) ;
}
