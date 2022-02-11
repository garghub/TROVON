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
struct V_32 * V_33 = & V_2 -> V_33 . V_34 -> V_33 ;
unsigned int V_35 ;
F_21 ( & V_2 -> V_33 . V_36 ) ;
while ( F_22 ( V_2 ) & V_37 ) {
V_35 = F_4 ( V_2 ) ;
V_2 -> V_33 . V_38 . V_39 ++ ;
if ( ! F_23 ( & V_2 -> V_33 , V_35 ) )
F_24 ( V_33 , V_35 , V_40 ) ;
}
F_25 ( & V_2 -> V_33 . V_36 ) ;
F_26 ( V_33 ) ;
return V_41 ;
}
static T_2 F_27 ( int V_30 , void * V_31 )
{
struct V_1 * V_2 = V_31 ;
F_21 ( & V_2 -> V_33 . V_36 ) ;
F_28 ( V_2 ) ;
F_25 ( & V_2 -> V_33 . V_36 ) ;
return V_41 ;
}
static T_2 F_29 ( int V_30 , void * V_31 )
{
struct V_1 * V_2 = V_31 ;
unsigned int V_42 = F_22 ( V_2 ) ;
F_21 ( & V_2 -> V_33 . V_36 ) ;
if ( V_42 & V_43 ) {
V_2 -> V_33 . V_38 . V_44 ++ ;
F_24 ( & V_2 -> V_33 . V_34 -> V_33 , 0 , V_45 ) ;
F_30 ( V_2 , V_43 ) ;
}
if ( V_42 & ( V_46 | V_47 | V_48 ) ) {
F_31 ( L_8 ,
( V_42 & V_46 ) ? L_9 : L_10 ,
( V_42 & V_47 ) ? L_11 : L_10 ,
( V_42 & V_48 ) ? L_12 : L_10 ) ;
F_9 ( V_2 , F_11 ( V_2 ) & ~ V_49 ) ;
F_13 ( V_2 , F_15 ( V_2 ) & ~ V_50 ) ;
}
F_19 () ;
F_25 ( & V_2 -> V_33 . V_36 ) ;
return V_41 ;
}
static unsigned int F_32 ( struct V_51 * V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_33 ;
if ( V_2 -> V_52 < 0 )
return V_53 | V_54 | V_55 ;
if ( F_33 ( V_2 ) )
return V_53 | V_54 | V_55 ;
else
return V_54 | V_55 ;
}
static void F_34 ( struct V_51 * V_33 , unsigned int V_56 )
{
struct V_1 * V_2 = (struct V_1 * ) V_33 ;
if ( V_2 -> V_57 < 0 )
return;
if ( V_56 & V_58 )
F_35 ( V_2 ) ;
else
F_36 ( V_2 ) ;
}
static T_2 F_37 ( int V_30 , void * V_31 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 ;
unsigned int V_59 ;
V_59 = F_32 ( & V_2 -> V_33 ) ;
F_38 ( & V_2 -> V_33 , V_59 & V_53 ) ;
return V_41 ;
}
static unsigned int F_32 ( struct V_51 * V_33 )
{
F_2 ( L_13 , V_4 ) ;
return V_53 | V_60 | V_54 ;
}
static void F_34 ( struct V_51 * V_33 , unsigned int V_56 )
{
F_2 ( L_13 , V_4 ) ;
}
static int F_39 ( struct V_51 * V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_33 ;
int V_61 ;
F_2 ( L_13 , V_4 ) ;
V_61 = F_40 ( V_2 -> V_33 . V_30 , F_20 , 0 ,
L_14 , V_2 ) ;
if ( V_61 ) {
F_41 ( V_33 -> V_62 , L_15 ) ;
return V_61 ;
}
V_61 = F_40 ( V_2 -> V_33 . V_30 + 1 , F_27 , 0 ,
L_16 , V_2 ) ;
if ( V_61 ) {
F_41 ( V_33 -> V_62 , L_17 ) ;
goto V_63;
}
V_61 = F_40 ( V_2 -> V_64 , F_29 , 0 ,
L_18 , V_2 ) ;
if ( V_61 ) {
F_41 ( V_33 -> V_62 , L_19 ) ;
goto V_65;
}
#ifdef F_42
if ( V_2 -> V_52 >= 0 ) {
if ( F_40 ( F_43 ( V_2 -> V_52 ) ,
F_37 ,
V_66 | V_67 |
0 , L_20 , V_2 ) ) {
V_2 -> V_52 = - 1 ;
F_44 ( V_33 -> V_62 , L_21 ) ;
}
}
if ( V_2 -> V_57 >= 0 ) {
if ( F_45 ( V_2 -> V_57 , V_68 ) ) {
F_44 ( V_33 -> V_62 , L_22 , V_2 -> V_57 ) ;
V_2 -> V_57 = - 1 ;
} else
F_46 ( V_2 -> V_57 , 0 ) ;
}
#endif
return 0 ;
V_65:
F_47 ( V_2 -> V_33 . V_30 + 1 , V_2 ) ;
V_63:
F_47 ( V_2 -> V_33 . V_30 , V_2 ) ;
return V_61 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_69 * V_70 = & V_2 -> V_33 . V_34 -> V_70 ;
if ( F_22 ( V_2 ) & V_71 )
return 0 ;
if ( V_2 -> V_33 . V_72 ) {
F_1 ( V_2 , V_2 -> V_33 . V_72 ) ;
V_2 -> V_33 . V_38 . V_73 ++ ;
V_2 -> V_33 . V_72 = 0 ;
return 1 ;
}
if ( F_48 ( V_70 ) || F_49 ( & V_2 -> V_33 ) ) {
if ( F_22 ( V_2 ) & V_74 )
F_50 ( & V_2 -> V_33 ) ;
return 0 ;
}
while( ! ( F_22 ( V_2 ) & V_71 ) && ! F_48 ( V_70 ) ) {
F_1 ( V_2 , V_70 -> V_75 [ V_70 -> V_76 ] ) ;
V_70 -> V_76 = ( V_70 -> V_76 + 1 ) & ( V_77 - 1 ) ;
V_2 -> V_33 . V_38 . V_73 ++ ;
}
if ( F_51 ( V_70 ) < V_78 )
F_52 ( & V_2 -> V_33 ) ;
return 1 ;
}
static unsigned int F_53 ( struct V_51 * V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_33 ;
unsigned int V_42 ;
V_42 = F_22 ( V_2 ) ;
F_2 ( L_23 , V_4 , V_42 ) ;
if ( V_42 & V_74 ) {
return V_79 ;
} else
return 0 ;
}
static void F_50 ( struct V_51 * V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_33 ;
F_2 ( L_13 , V_4 ) ;
if ( ! ( F_11 ( V_2 ) & V_49 ) )
return;
F_3 ( V_2 , 0xffff ) ;
while ( ! ( F_22 ( V_2 ) & V_74 ) )
F_54 () ;
F_9 ( V_2 , ( F_11 ( V_2 ) & ~ V_49 ) ) ;
F_19 () ;
return;
}
static void F_55 ( struct V_51 * V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_33 ;
F_2 ( L_13 , V_4 ) ;
if ( F_28 ( V_2 ) ) {
F_9 ( V_2 , ( F_11 ( V_2 ) | V_49 ) ) ;
F_19 () ;
}
F_2 ( L_24 , V_4 ) ;
}
static void F_56 ( struct V_51 * V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_33 ;
F_2 ( L_13 , V_4 ) ;
F_13 ( V_2 , ( F_15 ( V_2 ) & ~ V_50 ) ) ;
F_19 () ;
}
static void F_57 ( struct V_51 * V_33 , int V_80 )
{
F_2 ( L_13 , V_4 ) ;
}
static void F_58 ( struct V_51 * V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_33 ;
F_59 ( V_33 -> V_62 , L_13 , V_4 ) ;
F_9 ( V_2 , ( F_11 ( V_2 ) & ~ V_49 ) ) ;
F_13 ( V_2 , ( F_15 ( V_2 ) & ~ V_50 ) ) ;
F_19 () ;
F_47 ( V_2 -> V_33 . V_30 , V_2 ) ;
F_47 ( V_2 -> V_33 . V_30 + 1 , V_2 ) ;
F_47 ( V_2 -> V_64 , V_2 ) ;
#ifdef F_42
if ( V_2 -> V_52 >= 0 )
F_47 ( F_43 ( V_2 -> V_52 ) , V_2 ) ;
if ( V_2 -> V_57 >= 0 )
F_60 ( V_2 -> V_57 ) ;
#endif
}
static const char * F_61 ( struct V_51 * V_33 )
{
struct V_1 * V_2 = (struct V_1 * ) V_33 ;
F_2 ( L_13 , V_4 ) ;
return V_2 -> V_33 . type == V_81 ? L_25 : NULL ;
}
static void F_62 ( struct V_51 * V_33 )
{
F_2 ( L_13 , V_4 ) ;
}
static int F_63 ( struct V_51 * V_33 )
{
F_2 ( L_13 , V_4 ) ;
return 0 ;
}
static void F_64 ( struct V_51 * V_33 , int V_82 )
{
struct V_1 * V_2 = (struct V_1 * ) V_33 ;
F_2 ( L_13 , V_4 ) ;
V_2 -> V_33 . type = V_81 ;
}
static int F_65 ( struct V_51 * V_33 , struct V_83 * V_84 )
{
F_2 ( L_13 , V_4 ) ;
return 0 ;
}
static void F_66 ( struct V_51 * V_33 ,
struct V_85 * V_86 , struct V_85 * V_87 )
{
struct V_1 * V_2 = (struct V_1 * ) V_33 ;
unsigned long V_82 ;
int V_88 ;
F_2 ( L_26 , V_4 , V_86 -> V_89 ) ;
#ifdef F_42
if ( V_87 == NULL && V_2 -> V_52 != - 1 )
V_86 -> V_89 |= V_90 ;
else if ( V_2 -> V_52 == - 1 )
V_86 -> V_89 &= ~ V_90 ;
#endif
switch ( V_86 -> V_89 & V_91 ) {
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
F_67 ( L_27 ) ;
break;
}
if ( V_86 -> V_89 & V_96 ) {
V_2 -> V_13 = 1 ;
}
if ( V_86 -> V_89 & V_97 ) {
F_67 ( L_28 ) ;
}
F_68 ( & V_2 -> V_33 . V_36 , V_82 ) ;
V_33 -> V_98 = 0 ;
V_33 -> V_99 = 0 ;
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
V_33 -> V_100 = F_69 ( V_33 , V_86 , V_87 , 0 , F_8 () / 16 ) ;
F_9 ( V_2 , F_11 ( V_2 ) & ~ V_49 ) ;
F_13 ( V_2 , F_15 ( V_2 ) & ~ V_50 ) ;
F_7 ( V_2 , V_2 -> V_12 + V_2 -> V_13 , V_33 -> V_100 ) ;
F_3 ( V_2 , 0xffff ) ;
F_3 ( V_2 , 0xffff ) ;
F_9 ( V_2 , ( F_11 ( V_2 ) | V_49 ) ) ;
F_19 () ;
while ( ! ( F_22 ( V_2 ) & V_74 ) )
F_54 () ;
F_9 ( V_2 , F_11 ( V_2 ) & ~ V_49 ) ;
F_19 () ;
F_70 ( V_33 , V_86 -> V_89 , V_33 -> V_100 ) ;
F_13 ( V_2 , F_15 ( V_2 ) | V_50 ) ;
F_19 () ;
F_71 ( & V_2 -> V_33 . V_36 , V_82 ) ;
}
static int T_3
F_72 ( struct V_101 * V_102 , char * V_103 )
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
F_73 ( V_103 , & V_104 , & V_106 , & V_105 , & V_107 ) ;
return F_74 ( & V_2 -> V_33 , V_102 , V_104 , V_106 , V_105 , V_107 ) ;
}
static void F_75 ( struct V_51 * V_33 , int V_35 )
{
struct V_1 * V_2 = (struct V_1 * ) V_33 ;
while ( F_22 ( V_2 ) & V_71 )
F_76 () ;
F_1 ( V_2 , V_35 ) ;
}
static void
F_77 ( struct V_101 * V_102 , const char * V_112 , unsigned int V_113 )
{
struct V_1 * V_2 = V_111 [ V_102 -> V_108 ] ;
unsigned long V_82 ;
F_68 ( & V_2 -> V_33 . V_36 , V_82 ) ;
if ( F_11 ( V_2 ) & V_49 )
F_78 ( & V_2 -> V_33 , V_112 , V_113 , F_75 ) ;
else {
while ( F_22 ( V_2 ) & V_71 )
F_76 () ;
F_3 ( V_2 , 0xffff ) ;
F_9 ( V_2 , ( F_11 ( V_2 ) | V_49 ) ) ;
F_19 () ;
F_78 ( & V_2 -> V_33 , V_112 , V_113 , F_75 ) ;
while ( F_22 ( V_2 ) & V_71 )
F_76 () ;
F_3 ( V_2 , 0xffff ) ;
while ( ! ( F_22 ( V_2 ) & V_74 ) )
F_76 () ;
F_9 ( V_2 , ( F_11 ( V_2 ) & ~ V_49 ) ) ;
F_19 () ;
}
F_71 ( & V_2 -> V_33 . V_36 , V_82 ) ;
}
static int F_79 ( struct V_114 * V_62 )
{
struct V_1 * V_115 = F_80 ( V_62 ) ;
F_59 ( V_62 , L_13 , V_4 ) ;
if ( V_115 )
F_81 ( & V_116 , & V_115 -> V_33 ) ;
return 0 ;
}
static int F_82 ( struct V_114 * V_62 )
{
struct V_1 * V_115 = F_80 ( V_62 ) ;
F_59 ( V_62 , L_13 , V_4 ) ;
if ( V_115 )
F_83 ( & V_116 , & V_115 -> V_33 ) ;
return 0 ;
}
static int F_84 ( struct V_117 * V_118 )
{
struct V_119 * V_120 ;
struct V_1 * V_115 ;
int V_61 = 0 ;
F_59 ( & V_118 -> V_62 , L_13 , V_4 ) ;
if ( V_118 -> V_121 < 0 || V_118 -> V_121 >= V_109 ) {
F_41 ( & V_118 -> V_62 , L_29 ) ;
return - V_122 ;
}
if ( V_111 [ V_118 -> V_121 ] == NULL ) {
V_111 [ V_118 -> V_121 ] =
F_85 ( sizeof( struct V_1 ) , V_123 ) ;
V_115 = V_111 [ V_118 -> V_121 ] ;
if ( ! V_115 ) {
F_41 ( & V_118 -> V_62 ,
L_30 ) ;
return - V_124 ;
}
V_61 = F_86 ( F_87 ( & V_118 -> V_62 ) ,
V_68 ) ;
if ( V_61 ) {
F_41 ( & V_118 -> V_62 ,
L_31 ) ;
goto V_125;
}
F_88 ( & V_115 -> V_33 . V_36 ) ;
V_115 -> V_33 . V_126 = V_127 ,
V_115 -> V_33 . V_128 = & V_129 ;
V_115 -> V_33 . line = V_118 -> V_121 ;
V_115 -> V_33 . V_130 = V_131 ;
V_115 -> V_33 . V_82 = V_132 ;
V_120 = F_89 ( V_118 , V_133 , 0 ) ;
if ( V_120 == NULL ) {
F_41 ( & V_118 -> V_62 , L_32 ) ;
V_61 = - V_122 ;
goto V_134;
}
V_115 -> V_33 . V_135 = F_90 ( V_120 -> V_136 , F_91 ( V_120 ) ) ;
if ( ! V_115 -> V_33 . V_135 ) {
F_41 ( & V_118 -> V_62 , L_33 ) ;
V_61 = - V_137 ;
goto V_134;
}
V_115 -> V_33 . V_138 = V_120 -> V_136 ;
V_115 -> V_33 . V_30 = F_92 ( V_118 , 0 ) ;
if ( ( int ) V_115 -> V_33 . V_30 < 0 ) {
F_41 ( & V_118 -> V_62 , L_34 ) ;
V_61 = - V_122 ;
goto V_139;
}
V_115 -> V_64 = F_92 ( V_118 , 1 ) ;
if ( V_115 -> V_64 < 0 ) {
F_41 ( & V_118 -> V_62 , L_35 ) ;
V_61 = - V_122 ;
goto V_139;
}
#ifdef F_42
V_120 = F_89 ( V_118 , V_140 , 0 ) ;
if ( V_120 == NULL )
V_115 -> V_52 = - 1 ;
else
V_115 -> V_52 = V_120 -> V_136 ;
V_120 = F_89 ( V_118 , V_140 , 1 ) ;
if ( V_120 == NULL )
V_115 -> V_57 = - 1 ;
else
V_115 -> V_57 = V_120 -> V_136 ;
#endif
}
#ifdef F_93
if ( ! F_94 ( V_118 ) ) {
#endif
V_115 = V_111 [ V_118 -> V_121 ] ;
V_115 -> V_33 . V_62 = & V_118 -> V_62 ;
F_95 ( & V_118 -> V_62 , V_115 ) ;
V_61 = F_96 ( & V_116 , & V_115 -> V_33 ) ;
#ifdef F_93
}
#endif
if ( ! V_61 )
return 0 ;
if ( V_115 ) {
V_139:
F_97 ( V_115 -> V_33 . V_135 ) ;
V_134:
F_98 ( F_87 ( & V_118 -> V_62 ) ) ;
V_125:
F_99 ( V_115 ) ;
V_111 [ V_118 -> V_121 ] = NULL ;
}
return V_61 ;
}
static int F_100 ( struct V_117 * V_118 )
{
struct V_1 * V_115 = F_101 ( V_118 ) ;
F_59 ( & V_118 -> V_62 , L_13 , V_4 ) ;
F_95 ( & V_118 -> V_62 , NULL ) ;
if ( V_115 ) {
F_102 ( & V_116 , & V_115 -> V_33 ) ;
F_97 ( V_115 -> V_33 . V_135 ) ;
F_98 ( F_87 ( & V_118 -> V_62 ) ) ;
F_99 ( V_115 ) ;
V_111 [ V_118 -> V_121 ] = NULL ;
}
return 0 ;
}
static int T_3 F_103 ( void )
{
F_104 ( & V_141 , V_68 ) ;
F_105 ( V_142 ,
V_109 , 0 ) ;
F_106 ( & V_143 ) ;
return 0 ;
}
static int T_3 F_107 ( void )
{
int V_61 ;
F_108 ( L_36 ) ;
V_61 = F_109 ( & V_116 ) ;
if ( V_61 ) {
F_31 ( L_37 ,
V_116 . V_144 , V_61 ) ;
return V_61 ;
}
V_61 = F_110 ( & V_145 ) ;
if ( V_61 ) {
F_31 ( L_38 , V_61 ) ;
F_111 ( & V_116 ) ;
}
return V_61 ;
}
static void T_4 F_112 ( void )
{
F_113 ( & V_145 ) ;
F_111 ( & V_116 ) ;
}
