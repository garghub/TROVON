static void T_1 * F_1 ( union V_1 * V_2 )
{
return F_2 ( * V_2 -> V_3 ) ;
}
static void T_1 * F_3 ( union V_1 * V_2 )
{
return V_2 -> V_4 ;
}
static inline void T_1 * F_4 ( struct V_5 * V_6 )
{
return V_6 -> V_7 ( & V_6 -> V_8 ) ;
}
static inline void T_1 * F_5 ( struct V_5 * V_6 )
{
return V_6 -> V_7 ( & V_6 -> V_9 ) ;
}
static inline void T_1 * F_6 ( struct V_10 * V_11 )
{
struct V_5 * V_12 = F_7 ( V_11 ) ;
return F_4 ( V_12 ) ;
}
static inline void T_1 * F_8 ( struct V_10 * V_11 )
{
struct V_5 * V_12 = F_7 ( V_11 ) ;
return F_5 ( V_12 ) ;
}
static inline unsigned int F_9 ( struct V_10 * V_11 )
{
return V_11 -> V_13 ;
}
static void F_10 ( struct V_10 * V_11 )
{
T_2 V_14 = 1 << ( F_9 ( V_11 ) % 32 ) ;
unsigned long V_15 ;
F_11 ( & V_16 , V_15 ) ;
F_12 ( V_14 , F_6 ( V_11 ) + V_17 + ( F_9 ( V_11 ) / 32 ) * 4 ) ;
if ( V_18 . V_19 )
V_18 . V_19 ( V_11 ) ;
F_13 ( & V_16 , V_15 ) ;
}
static void F_14 ( struct V_10 * V_11 )
{
T_2 V_14 = 1 << ( F_9 ( V_11 ) % 32 ) ;
unsigned long V_15 ;
F_11 ( & V_16 , V_15 ) ;
if ( V_18 . V_20 )
V_18 . V_20 ( V_11 ) ;
F_12 ( V_14 , F_6 ( V_11 ) + V_21 + ( F_9 ( V_11 ) / 32 ) * 4 ) ;
F_13 ( & V_16 , V_15 ) ;
}
static void F_15 ( struct V_10 * V_11 )
{
if ( V_18 . V_22 ) {
F_16 ( & V_16 ) ;
V_18 . V_22 ( V_11 ) ;
F_17 ( & V_16 ) ;
}
F_12 ( F_9 ( V_11 ) , F_8 ( V_11 ) + V_23 ) ;
}
static int F_18 ( struct V_10 * V_11 , unsigned int type )
{
void T_1 * V_2 = F_6 ( V_11 ) ;
unsigned int V_24 = F_9 ( V_11 ) ;
unsigned long V_15 ;
int V_25 ;
if ( V_24 < 16 )
return - V_26 ;
if ( V_24 >= 32 && type != V_27 &&
type != V_28 )
return - V_26 ;
F_11 ( & V_16 , V_15 ) ;
if ( V_18 . V_29 )
V_18 . V_29 ( V_11 , type ) ;
V_25 = F_19 ( V_24 , type , V_2 , NULL ) ;
F_13 ( & V_16 , V_15 ) ;
return V_25 ;
}
static int F_20 ( struct V_10 * V_11 )
{
if ( V_18 . V_30 )
return V_18 . V_30 ( V_11 ) ;
return 0 ;
}
static int F_21 ( struct V_10 * V_11 , const struct V_31 * V_32 ,
bool V_33 )
{
void T_1 * V_34 = F_6 ( V_11 ) + V_35 + ( F_9 ( V_11 ) & ~ 3 ) ;
unsigned int V_36 , V_37 = ( F_9 ( V_11 ) % 4 ) * 8 ;
T_2 V_38 , V_14 , V_39 ;
unsigned long V_15 ;
if ( ! V_33 )
V_36 = F_22 ( V_32 , V_40 ) ;
else
V_36 = F_23 ( V_32 ) ;
if ( V_36 >= V_41 || V_36 >= V_42 )
return - V_26 ;
F_11 ( & V_16 , V_15 ) ;
V_14 = 0xff << V_37 ;
V_39 = V_43 [ V_36 ] << V_37 ;
V_38 = F_24 ( V_34 ) & ~ V_14 ;
F_12 ( V_38 | V_39 , V_34 ) ;
F_13 ( & V_16 , V_15 ) ;
return V_44 ;
}
static int F_25 ( struct V_10 * V_11 , unsigned int V_45 )
{
int V_25 = - V_46 ;
if ( V_18 . V_47 )
V_25 = V_18 . V_47 ( V_11 , V_45 ) ;
return V_25 ;
}
static void T_3 F_26 ( struct V_48 * V_49 )
{
T_2 V_50 , V_51 ;
struct V_5 * V_52 = & V_12 [ 0 ] ;
void T_1 * V_9 = F_5 ( V_52 ) ;
do {
V_50 = F_24 ( V_9 + V_53 ) ;
V_51 = V_50 & V_54 ;
if ( F_27 ( V_51 > 15 && V_51 < 1021 ) ) {
F_28 ( V_52 -> V_55 , V_51 , V_49 ) ;
continue;
}
if ( V_51 < 16 ) {
F_12 ( V_50 , V_9 + V_23 ) ;
#ifdef F_29
F_30 ( V_51 , V_49 ) ;
#endif
continue;
}
break;
} while ( 1 );
}
static void F_31 ( unsigned int V_56 , struct V_57 * V_58 )
{
struct V_5 * V_59 = F_32 ( V_56 ) ;
struct V_60 * V_61 = F_33 ( V_56 ) ;
unsigned int V_62 , F_9 ;
unsigned long V_63 ;
F_34 ( V_61 , V_58 ) ;
F_16 ( & V_16 ) ;
V_63 = F_24 ( F_5 ( V_59 ) + V_53 ) ;
F_17 ( & V_16 ) ;
F_9 = ( V_63 & V_54 ) ;
if ( F_9 == V_64 )
goto V_65;
V_62 = F_35 ( V_59 -> V_55 , F_9 ) ;
if ( F_36 ( F_9 < 32 || F_9 > 1020 ) )
F_37 ( V_62 , V_58 ) ;
else
F_38 ( V_62 ) ;
V_65:
F_39 ( V_61 , V_58 ) ;
}
void T_4 F_40 ( unsigned int V_66 , unsigned int V_56 )
{
if ( V_66 >= V_67 )
F_41 () ;
if ( F_42 ( V_56 , & V_12 [ V_66 ] ) != 0 )
F_41 () ;
F_43 ( V_56 , F_31 ) ;
}
static T_5 F_44 ( struct V_5 * V_52 )
{
void T_1 * V_2 = F_4 ( V_52 ) ;
T_2 V_14 , V_68 ;
for ( V_68 = V_14 = 0 ; V_68 < 32 ; V_68 += 4 ) {
V_14 = F_24 ( V_2 + V_35 + V_68 ) ;
V_14 |= V_14 >> 16 ;
V_14 |= V_14 >> 8 ;
if ( V_14 )
break;
}
if ( ! V_14 )
F_45 ( L_1 ) ;
return V_14 ;
}
static void F_46 ( void )
{
void T_1 * V_9 = F_5 ( & V_12 [ 0 ] ) ;
T_2 V_69 = 0 ;
V_69 = F_47 ( V_9 + V_70 ) ;
V_69 &= V_71 ;
F_12 ( V_69 | V_72 , V_9 + V_70 ) ;
}
static void T_4 F_48 ( struct V_5 * V_52 )
{
unsigned int V_68 ;
T_2 V_31 ;
unsigned int V_73 = V_52 -> V_73 ;
void T_1 * V_2 = F_4 ( V_52 ) ;
F_12 ( V_74 , V_2 + V_75 ) ;
V_31 = F_44 ( V_52 ) ;
V_31 |= V_31 << 8 ;
V_31 |= V_31 << 16 ;
for ( V_68 = 32 ; V_68 < V_73 ; V_68 += 4 )
F_12 ( V_31 , V_2 + V_35 + V_68 * 4 / 4 ) ;
F_49 ( V_2 , V_73 , NULL ) ;
F_12 ( V_76 , V_2 + V_75 ) ;
}
static void F_50 ( struct V_5 * V_52 )
{
void T_1 * V_8 = F_4 ( V_52 ) ;
void T_1 * V_2 = F_5 ( V_52 ) ;
unsigned int V_77 , V_36 = F_51 () ;
int V_68 ;
F_52 ( V_36 >= V_41 ) ;
V_77 = F_44 ( V_52 ) ;
V_43 [ V_36 ] = V_77 ;
for ( V_68 = 0 ; V_68 < V_41 ; V_68 ++ )
if ( V_68 != V_36 )
V_43 [ V_68 ] &= ~ V_77 ;
F_53 ( V_8 , NULL ) ;
F_12 ( V_78 , V_2 + V_79 ) ;
F_46 () ;
}
void F_54 ( void )
{
void T_1 * V_9 = F_5 ( & V_12 [ 0 ] ) ;
T_2 V_38 = 0 ;
V_38 = F_47 ( V_9 + V_70 ) ;
V_38 &= ~ V_72 ;
F_12 ( V_38 , V_9 + V_70 ) ;
}
static void F_55 ( unsigned int V_66 )
{
unsigned int V_73 ;
void T_1 * V_8 ;
int V_68 ;
if ( V_66 >= V_67 )
F_41 () ;
V_73 = V_12 [ V_66 ] . V_73 ;
V_8 = F_4 ( & V_12 [ V_66 ] ) ;
if ( ! V_8 )
return;
for ( V_68 = 0 ; V_68 < F_56 ( V_73 , 16 ) ; V_68 ++ )
V_12 [ V_66 ] . V_80 [ V_68 ] =
F_24 ( V_8 + V_81 + V_68 * 4 ) ;
for ( V_68 = 0 ; V_68 < F_56 ( V_73 , 4 ) ; V_68 ++ )
V_12 [ V_66 ] . V_82 [ V_68 ] =
F_24 ( V_8 + V_35 + V_68 * 4 ) ;
for ( V_68 = 0 ; V_68 < F_56 ( V_73 , 32 ) ; V_68 ++ )
V_12 [ V_66 ] . V_83 [ V_68 ] =
F_24 ( V_8 + V_21 + V_68 * 4 ) ;
}
static void F_57 ( unsigned int V_66 )
{
unsigned int V_73 ;
unsigned int V_68 ;
void T_1 * V_8 ;
if ( V_66 >= V_67 )
F_41 () ;
V_73 = V_12 [ V_66 ] . V_73 ;
V_8 = F_4 ( & V_12 [ V_66 ] ) ;
if ( ! V_8 )
return;
F_12 ( V_74 , V_8 + V_75 ) ;
for ( V_68 = 0 ; V_68 < F_56 ( V_73 , 16 ) ; V_68 ++ )
F_12 ( V_12 [ V_66 ] . V_80 [ V_68 ] ,
V_8 + V_81 + V_68 * 4 ) ;
for ( V_68 = 0 ; V_68 < F_56 ( V_73 , 4 ) ; V_68 ++ )
F_12 ( V_84 ,
V_8 + V_85 + V_68 * 4 ) ;
for ( V_68 = 0 ; V_68 < F_56 ( V_73 , 4 ) ; V_68 ++ )
F_12 ( V_12 [ V_66 ] . V_82 [ V_68 ] ,
V_8 + V_35 + V_68 * 4 ) ;
for ( V_68 = 0 ; V_68 < F_56 ( V_73 , 32 ) ; V_68 ++ )
F_12 ( V_12 [ V_66 ] . V_83 [ V_68 ] ,
V_8 + V_21 + V_68 * 4 ) ;
F_12 ( V_76 , V_8 + V_75 ) ;
}
static void F_58 ( unsigned int V_66 )
{
int V_68 ;
T_2 * V_86 ;
void T_1 * V_8 ;
void T_1 * V_9 ;
if ( V_66 >= V_67 )
F_41 () ;
V_8 = F_4 ( & V_12 [ V_66 ] ) ;
V_9 = F_5 ( & V_12 [ V_66 ] ) ;
if ( ! V_8 || ! V_9 )
return;
V_86 = F_59 ( V_12 [ V_66 ] . V_87 ) ;
for ( V_68 = 0 ; V_68 < F_56 ( 32 , 32 ) ; V_68 ++ )
V_86 [ V_68 ] = F_24 ( V_8 + V_21 + V_68 * 4 ) ;
V_86 = F_59 ( V_12 [ V_66 ] . V_88 ) ;
for ( V_68 = 0 ; V_68 < F_56 ( 32 , 16 ) ; V_68 ++ )
V_86 [ V_68 ] = F_24 ( V_8 + V_81 + V_68 * 4 ) ;
}
static void F_60 ( unsigned int V_66 )
{
int V_68 ;
T_2 * V_86 ;
void T_1 * V_8 ;
void T_1 * V_9 ;
if ( V_66 >= V_67 )
F_41 () ;
V_8 = F_4 ( & V_12 [ V_66 ] ) ;
V_9 = F_5 ( & V_12 [ V_66 ] ) ;
if ( ! V_8 || ! V_9 )
return;
V_86 = F_59 ( V_12 [ V_66 ] . V_87 ) ;
for ( V_68 = 0 ; V_68 < F_56 ( 32 , 32 ) ; V_68 ++ )
F_12 ( V_86 [ V_68 ] , V_8 + V_21 + V_68 * 4 ) ;
V_86 = F_59 ( V_12 [ V_66 ] . V_88 ) ;
for ( V_68 = 0 ; V_68 < F_56 ( 32 , 16 ) ; V_68 ++ )
F_12 ( V_86 [ V_68 ] , V_8 + V_81 + V_68 * 4 ) ;
for ( V_68 = 0 ; V_68 < F_56 ( 32 , 4 ) ; V_68 ++ )
F_12 ( V_84 ,
V_8 + V_85 + V_68 * 4 ) ;
F_12 ( V_78 , V_9 + V_79 ) ;
F_46 () ;
}
static int F_61 ( struct V_89 * V_90 , unsigned long V_91 , void * V_92 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_67 ; V_68 ++ ) {
#ifdef F_62
if ( ! V_12 [ V_68 ] . V_7 )
continue;
#endif
switch ( V_91 ) {
case V_93 :
F_58 ( V_68 ) ;
break;
case V_94 :
case V_95 :
F_60 ( V_68 ) ;
break;
case V_96 :
F_55 ( V_68 ) ;
break;
case V_97 :
case V_98 :
F_57 ( V_68 ) ;
break;
}
}
return V_99 ;
}
static void T_4 F_63 ( struct V_5 * V_52 )
{
V_52 -> V_87 = F_64 ( F_56 ( 32 , 32 ) * 4 ,
sizeof( T_2 ) ) ;
F_52 ( ! V_52 -> V_87 ) ;
V_52 -> V_88 = F_64 ( F_56 ( 32 , 16 ) * 4 ,
sizeof( T_2 ) ) ;
F_52 ( ! V_52 -> V_88 ) ;
if ( V_52 == & V_12 [ 0 ] )
F_65 ( & V_100 ) ;
}
static void T_4 F_63 ( struct V_5 * V_52 )
{
}
static void F_66 ( const struct V_31 * V_14 , unsigned int V_56 )
{
int V_36 ;
unsigned long V_15 , V_101 = 0 ;
F_11 ( & V_16 , V_15 ) ;
F_67 (cpu, mask)
V_101 |= V_43 [ V_36 ] ;
F_68 ( V_102 ) ;
F_12 ( V_101 << 16 | V_56 , F_4 ( & V_12 [ 0 ] ) + V_103 ) ;
F_13 ( & V_16 , V_15 ) ;
}
void F_69 ( unsigned int V_104 , unsigned int V_56 )
{
F_52 ( V_104 >= V_41 ) ;
V_104 = 1 << V_104 ;
F_12 ( ( V_104 << 16 ) | V_56 , F_4 ( & V_12 [ 0 ] ) + V_103 ) ;
}
int F_70 ( unsigned int V_36 )
{
unsigned int V_105 ;
if ( V_36 >= V_41 )
return - 1 ;
V_105 = V_43 [ V_36 ] ;
if ( V_105 & ( V_105 - 1 ) )
return - 1 ;
return F_71 ( V_105 ) ;
}
void F_72 ( unsigned int V_106 )
{
unsigned int V_107 , V_73 , V_66 = 0 ;
void T_1 * V_8 ;
int V_68 , V_108 , V_36 = F_51 () ;
T_2 V_38 , V_109 , V_110 ;
if ( V_66 >= V_67 )
F_41 () ;
V_8 = F_4 ( & V_12 [ V_66 ] ) ;
if ( ! V_8 )
return;
V_73 = V_12 [ V_66 ] . V_73 ;
V_107 = F_71 ( V_43 [ V_36 ] ) ;
V_109 = 0x01010101 << V_107 ;
V_108 = ( V_107 - V_106 ) & 31 ;
F_16 ( & V_16 ) ;
V_43 [ V_36 ] = 1 << V_106 ;
for ( V_68 = 8 ; V_68 < F_56 ( V_73 , 4 ) ; V_68 ++ ) {
V_38 = F_24 ( V_8 + V_35 + V_68 * 4 ) ;
V_110 = V_38 & V_109 ;
if ( V_110 ) {
V_38 &= ~ V_110 ;
V_38 |= F_73 ( V_110 , V_108 ) ;
F_12 ( V_38 , V_8 + V_35 + V_68 * 4 ) ;
}
}
F_17 ( & V_16 ) ;
for ( V_68 = 0 ; V_68 < 16 ; V_68 += 4 ) {
int V_111 ;
V_38 = F_24 ( V_8 + V_112 + V_68 ) ;
if ( ! V_38 )
continue;
F_12 ( V_38 , V_8 + V_113 + V_68 ) ;
for ( V_111 = V_68 ; V_111 < V_68 + 4 ; V_111 ++ ) {
if ( V_38 & 0xff )
F_12 ( ( 1 << ( V_106 + 16 ) ) | V_111 ,
V_8 + V_103 ) ;
V_38 >>= 8 ;
}
}
}
unsigned long F_74 ( void )
{
if ( ! V_114 )
return 0 ;
return V_114 + V_103 ;
}
void T_4 F_75 ( struct V_115 * V_116 )
{
struct V_117 V_118 ;
if ( F_76 ( V_116 , 0 , & V_118 ) == 0 ) {
V_114 = V_118 . V_119 ;
F_77 ( L_2 , V_114 ) ;
}
}
static int F_78 ( struct V_120 * V_11 , unsigned int V_56 ,
T_6 V_121 )
{
if ( V_121 < 32 ) {
F_79 ( V_56 ) ;
F_80 ( V_11 , V_56 , V_121 , & V_122 , V_11 -> V_123 ,
V_124 , NULL , NULL ) ;
F_81 ( V_56 , V_125 | V_126 ) ;
} else {
F_80 ( V_11 , V_56 , V_121 , & V_122 , V_11 -> V_123 ,
V_127 , NULL , NULL ) ;
F_81 ( V_56 , V_125 | V_128 ) ;
V_129 -> V_101 ( V_11 , V_56 , V_121 ) ;
}
return 0 ;
}
static void F_82 ( struct V_120 * V_11 , unsigned int V_56 )
{
V_129 -> V_130 ( V_11 , V_56 ) ;
}
static int F_83 ( struct V_120 * V_11 ,
struct V_115 * V_131 ,
const T_2 * V_132 , unsigned int V_133 ,
unsigned long * V_134 , unsigned int * V_135 )
{
unsigned long V_25 = 0 ;
if ( V_11 -> V_136 != V_131 )
return - V_26 ;
if ( V_133 < 3 )
return - V_26 ;
* V_134 = V_132 [ 1 ] + 16 ;
if ( ! V_132 [ 0 ] ) {
V_25 = V_129 -> V_137 ( V_11 , V_131 ,
V_132 ,
V_133 ,
V_134 ,
V_135 ) ;
if ( F_84 ( V_25 ) )
return V_25 ;
}
* V_135 = V_132 [ 2 ] & V_138 ;
return V_25 ;
}
static int F_85 ( struct V_89 * V_139 , unsigned long V_140 ,
void * V_141 )
{
if ( V_140 == V_142 || V_140 == V_143 )
F_50 ( & V_12 [ 0 ] ) ;
return V_99 ;
}
static int F_86 ( struct V_120 * V_55 , unsigned int V_144 ,
unsigned int V_145 , void * V_146 )
{
int V_68 , V_25 ;
T_6 V_13 ;
unsigned int type = V_147 ;
struct V_148 * V_10 = V_146 ;
V_25 = F_83 ( V_55 , V_10 -> V_149 , V_10 -> args ,
V_10 -> V_150 , & V_13 , & type ) ;
if ( V_25 )
return V_25 ;
for ( V_68 = 0 ; V_68 < V_145 ; V_68 ++ )
F_78 ( V_55 , V_144 + V_68 , V_13 + V_68 ) ;
return 0 ;
}
static int F_87 ( struct V_120 * V_11 , unsigned int V_56 ,
T_6 V_121 )
{
return 0 ;
}
static void F_88 ( struct V_120 * V_11 ,
unsigned int V_56 )
{
}
static int F_89 ( struct V_120 * V_11 ,
struct V_115 * V_131 ,
const T_2 * V_132 , unsigned int V_133 ,
unsigned long * V_134 ,
unsigned int * V_135 )
{
* V_134 += 16 ;
return 0 ;
}
void T_4 F_90 ( unsigned int V_66 , int V_151 ,
void T_1 * V_8 , void T_1 * V_9 ,
T_2 V_152 , struct V_115 * V_116 )
{
T_6 V_153 ;
struct V_5 * V_52 ;
int V_73 , V_154 , V_68 ;
int V_155 ;
F_52 ( V_66 >= V_67 ) ;
V_52 = & V_12 [ V_66 ] ;
#ifdef F_62
if ( V_152 ) {
unsigned int V_36 ;
V_52 -> V_8 . V_3 = F_91 (void __iomem *) ;
V_52 -> V_9 . V_3 = F_91 (void __iomem *) ;
if ( F_92 ( ! V_52 -> V_8 . V_3 ||
! V_52 -> V_9 . V_3 ) ) {
F_93 ( V_52 -> V_8 . V_3 ) ;
F_93 ( V_52 -> V_9 . V_3 ) ;
return;
}
F_94 (cpu) {
T_2 V_156 = F_95 ( V_36 ) ;
T_2 V_157 = F_96 ( V_156 , 0 ) ;
unsigned long V_158 = V_152 * V_157 ;
* F_97 ( V_52 -> V_8 . V_3 , V_36 ) = V_8 + V_158 ;
* F_97 ( V_52 -> V_9 . V_3 , V_36 ) = V_9 + V_158 ;
}
F_98 ( V_52 , F_1 ) ;
} else
#endif
{
F_99 ( V_152 ,
L_3 ,
V_152 ) ;
V_52 -> V_8 . V_4 = V_8 ;
V_52 -> V_9 . V_4 = V_9 ;
F_98 ( V_52 , F_3 ) ;
}
for ( V_68 = 0 ; V_68 < V_41 ; V_68 ++ )
V_43 [ V_68 ] = 0xff ;
V_73 = F_24 ( F_4 ( V_52 ) + V_159 ) & 0x1f ;
V_73 = ( V_73 + 1 ) * 32 ;
if ( V_73 > 1020 )
V_73 = 1020 ;
V_52 -> V_73 = V_73 ;
if ( V_116 ) {
const struct V_160 * V_161 = & V_162 ;
if ( ! F_100 ( V_116 , L_4 ,
& V_155 ) ) {
V_161 = & V_163 ;
V_73 = V_155 ;
}
V_52 -> V_55 = F_101 ( V_116 , V_73 , V_161 , V_52 ) ;
} else {
if ( V_66 == 0 && ( V_151 & 31 ) > 0 ) {
V_153 = 16 ;
if ( V_151 != - 1 )
V_151 = ( V_151 & ~ 31 ) + 16 ;
} else {
V_153 = 32 ;
}
V_73 -= V_153 ;
V_154 = F_102 ( V_151 , 16 , V_73 ,
F_103 () ) ;
if ( F_84 ( V_154 ) ) {
F_99 ( 1 , L_5 ,
V_151 ) ;
V_154 = V_151 ;
}
V_52 -> V_55 = F_104 ( V_116 , V_73 , V_154 ,
V_153 , & V_163 , V_52 ) ;
}
if ( F_92 ( ! V_52 -> V_55 ) )
return;
if ( V_66 == 0 ) {
#ifdef F_29
F_105 ( F_66 ) ;
F_106 ( & V_164 ) ;
#endif
F_107 ( F_26 ) ;
}
V_122 . V_15 |= V_18 . V_15 ;
F_48 ( V_52 ) ;
F_50 ( V_52 ) ;
F_63 ( V_52 ) ;
}
static int T_4
F_108 ( struct V_115 * V_116 , struct V_115 * V_165 )
{
void T_1 * V_9 ;
void T_1 * V_8 ;
T_2 V_152 ;
int V_56 ;
if ( F_92 ( ! V_116 ) )
return - V_166 ;
V_8 = F_109 ( V_116 , 0 ) ;
F_99 ( ! V_8 , L_6 ) ;
V_9 = F_109 ( V_116 , 1 ) ;
F_99 ( ! V_9 , L_7 ) ;
if ( F_100 ( V_116 , L_8 , & V_152 ) )
V_152 = 0 ;
F_90 ( V_167 , - 1 , V_8 , V_9 , V_152 , V_116 ) ;
if ( ! V_167 )
F_75 ( V_116 ) ;
if ( V_165 ) {
V_56 = F_110 ( V_116 , 0 ) ;
F_40 ( V_167 , V_56 ) ;
}
if ( F_111 ( V_168 ) )
F_112 ( V_116 , V_12 [ V_167 ] . V_55 ) ;
V_167 ++ ;
return 0 ;
}
