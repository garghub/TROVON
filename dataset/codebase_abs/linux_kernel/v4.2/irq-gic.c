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
static void F_10 ( struct V_10 * V_11 , T_2 V_14 )
{
T_2 V_15 = 1 << ( F_9 ( V_11 ) % 32 ) ;
F_11 ( V_15 , F_6 ( V_11 ) + V_14 + ( F_9 ( V_11 ) / 32 ) * 4 ) ;
}
static int F_12 ( struct V_10 * V_11 , T_2 V_14 )
{
T_2 V_15 = 1 << ( F_9 ( V_11 ) % 32 ) ;
return ! ! ( F_13 ( F_6 ( V_11 ) + V_14 + ( F_9 ( V_11 ) / 32 ) * 4 ) & V_15 ) ;
}
static void F_14 ( struct V_10 * V_11 )
{
F_10 ( V_11 , V_16 ) ;
}
static void F_15 ( struct V_10 * V_11 )
{
F_10 ( V_11 , V_17 ) ;
}
static void F_16 ( struct V_10 * V_11 )
{
F_11 ( F_9 ( V_11 ) , F_8 ( V_11 ) + V_18 ) ;
}
static int F_17 ( struct V_10 * V_11 ,
enum V_19 V_20 , bool V_21 )
{
T_2 V_22 ;
switch ( V_20 ) {
case V_23 :
V_22 = V_21 ? V_24 : V_25 ;
break;
case V_26 :
V_22 = V_21 ? V_27 : V_28 ;
break;
case V_29 :
V_22 = V_21 ? V_16 : V_17 ;
break;
default:
return - V_30 ;
}
F_10 ( V_11 , V_22 ) ;
return 0 ;
}
static int F_18 ( struct V_10 * V_11 ,
enum V_19 V_20 , bool * V_21 )
{
switch ( V_20 ) {
case V_23 :
* V_21 = F_12 ( V_11 , V_24 ) ;
break;
case V_26 :
* V_21 = F_12 ( V_11 , V_27 ) ;
break;
case V_29 :
* V_21 = ! F_12 ( V_11 , V_17 ) ;
break;
default:
return - V_30 ;
}
return 0 ;
}
static int F_19 ( struct V_10 * V_11 , unsigned int type )
{
void T_1 * V_2 = F_6 ( V_11 ) ;
unsigned int V_31 = F_9 ( V_11 ) ;
if ( V_31 < 16 )
return - V_30 ;
if ( V_31 >= 32 && type != V_32 &&
type != V_33 )
return - V_30 ;
return F_20 ( V_31 , type , V_2 , NULL ) ;
}
static int F_21 ( struct V_10 * V_11 , const struct V_34 * V_35 ,
bool V_36 )
{
void T_1 * V_22 = F_6 ( V_11 ) + V_37 + ( F_9 ( V_11 ) & ~ 3 ) ;
unsigned int V_38 , V_39 = ( F_9 ( V_11 ) % 4 ) * 8 ;
T_2 V_21 , V_15 , V_40 ;
unsigned long V_41 ;
if ( ! V_36 )
V_38 = F_22 ( V_35 , V_42 ) ;
else
V_38 = F_23 ( V_35 ) ;
if ( V_38 >= V_43 || V_38 >= V_44 )
return - V_30 ;
F_24 ( & V_45 , V_41 ) ;
V_15 = 0xff << V_39 ;
V_40 = V_46 [ V_38 ] << V_39 ;
V_21 = F_13 ( V_22 ) & ~ V_15 ;
F_11 ( V_21 | V_40 , V_22 ) ;
F_25 ( & V_45 , V_41 ) ;
return V_47 ;
}
static void T_3 F_26 ( struct V_48 * V_49 )
{
T_2 V_50 , V_51 ;
struct V_5 * V_52 = & V_12 [ 0 ] ;
void T_1 * V_9 = F_5 ( V_52 ) ;
do {
V_50 = F_13 ( V_9 + V_53 ) ;
V_51 = V_50 & V_54 ;
if ( F_27 ( V_51 > 15 && V_51 < 1021 ) ) {
F_28 ( V_52 -> V_55 , V_51 , V_49 ) ;
continue;
}
if ( V_51 < 16 ) {
F_11 ( V_50 , V_9 + V_18 ) ;
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
F_35 ( & V_45 ) ;
V_63 = F_13 ( F_5 ( V_59 ) + V_53 ) ;
F_36 ( & V_45 ) ;
F_9 = ( V_63 & V_54 ) ;
if ( F_9 == V_64 )
goto V_65;
V_62 = F_37 ( V_59 -> V_55 , F_9 ) ;
if ( F_38 ( F_9 < 32 || F_9 > 1020 ) )
F_39 ( V_62 , V_58 ) ;
else
F_40 ( V_62 ) ;
V_65:
F_41 ( V_61 , V_58 ) ;
}
void T_4 F_42 ( unsigned int V_66 , unsigned int V_56 )
{
if ( V_66 >= V_67 )
F_43 () ;
if ( F_44 ( V_56 , & V_12 [ V_66 ] ) != 0 )
F_43 () ;
F_45 ( V_56 , F_31 ) ;
}
static T_5 F_46 ( struct V_5 * V_52 )
{
void T_1 * V_2 = F_4 ( V_52 ) ;
T_2 V_15 , V_68 ;
for ( V_68 = V_15 = 0 ; V_68 < 32 ; V_68 += 4 ) {
V_15 = F_13 ( V_2 + V_37 + V_68 ) ;
V_15 |= V_15 >> 16 ;
V_15 |= V_15 >> 8 ;
if ( V_15 )
break;
}
if ( ! V_15 && F_47 () > 1 )
F_48 ( L_1 ) ;
return V_15 ;
}
static void F_49 ( void )
{
void T_1 * V_9 = F_5 ( & V_12 [ 0 ] ) ;
T_2 V_69 = 0 ;
V_69 = F_50 ( V_9 + V_70 ) ;
V_69 &= V_71 ;
F_11 ( V_69 | V_72 , V_9 + V_70 ) ;
}
static void T_4 F_51 ( struct V_5 * V_52 )
{
unsigned int V_68 ;
T_2 V_34 ;
unsigned int V_73 = V_52 -> V_73 ;
void T_1 * V_2 = F_4 ( V_52 ) ;
F_11 ( V_74 , V_2 + V_75 ) ;
V_34 = F_46 ( V_52 ) ;
V_34 |= V_34 << 8 ;
V_34 |= V_34 << 16 ;
for ( V_68 = 32 ; V_68 < V_73 ; V_68 += 4 )
F_11 ( V_34 , V_2 + V_37 + V_68 * 4 / 4 ) ;
F_52 ( V_2 , V_73 , NULL ) ;
F_11 ( V_76 , V_2 + V_75 ) ;
}
static void F_53 ( struct V_5 * V_52 )
{
void T_1 * V_8 = F_4 ( V_52 ) ;
void T_1 * V_2 = F_5 ( V_52 ) ;
unsigned int V_77 , V_38 = F_54 () ;
int V_68 ;
F_55 ( V_38 >= V_43 ) ;
V_77 = F_46 ( V_52 ) ;
V_46 [ V_38 ] = V_77 ;
for ( V_68 = 0 ; V_68 < V_43 ; V_68 ++ )
if ( V_68 != V_38 )
V_46 [ V_68 ] &= ~ V_77 ;
F_56 ( V_8 , NULL ) ;
F_11 ( V_78 , V_2 + V_79 ) ;
F_49 () ;
}
void F_57 ( void )
{
void T_1 * V_9 = F_5 ( & V_12 [ 0 ] ) ;
T_2 V_21 = 0 ;
V_21 = F_50 ( V_9 + V_70 ) ;
V_21 &= ~ V_72 ;
F_11 ( V_21 , V_9 + V_70 ) ;
}
static void F_58 ( unsigned int V_66 )
{
unsigned int V_73 ;
void T_1 * V_8 ;
int V_68 ;
if ( V_66 >= V_67 )
F_43 () ;
V_73 = V_12 [ V_66 ] . V_73 ;
V_8 = F_4 ( & V_12 [ V_66 ] ) ;
if ( ! V_8 )
return;
for ( V_68 = 0 ; V_68 < F_59 ( V_73 , 16 ) ; V_68 ++ )
V_12 [ V_66 ] . V_80 [ V_68 ] =
F_13 ( V_8 + V_81 + V_68 * 4 ) ;
for ( V_68 = 0 ; V_68 < F_59 ( V_73 , 4 ) ; V_68 ++ )
V_12 [ V_66 ] . V_82 [ V_68 ] =
F_13 ( V_8 + V_37 + V_68 * 4 ) ;
for ( V_68 = 0 ; V_68 < F_59 ( V_73 , 32 ) ; V_68 ++ )
V_12 [ V_66 ] . V_83 [ V_68 ] =
F_13 ( V_8 + V_17 + V_68 * 4 ) ;
}
static void F_60 ( unsigned int V_66 )
{
unsigned int V_73 ;
unsigned int V_68 ;
void T_1 * V_8 ;
if ( V_66 >= V_67 )
F_43 () ;
V_73 = V_12 [ V_66 ] . V_73 ;
V_8 = F_4 ( & V_12 [ V_66 ] ) ;
if ( ! V_8 )
return;
F_11 ( V_74 , V_8 + V_75 ) ;
for ( V_68 = 0 ; V_68 < F_59 ( V_73 , 16 ) ; V_68 ++ )
F_11 ( V_12 [ V_66 ] . V_80 [ V_68 ] ,
V_8 + V_81 + V_68 * 4 ) ;
for ( V_68 = 0 ; V_68 < F_59 ( V_73 , 4 ) ; V_68 ++ )
F_11 ( V_84 ,
V_8 + V_85 + V_68 * 4 ) ;
for ( V_68 = 0 ; V_68 < F_59 ( V_73 , 4 ) ; V_68 ++ )
F_11 ( V_12 [ V_66 ] . V_82 [ V_68 ] ,
V_8 + V_37 + V_68 * 4 ) ;
for ( V_68 = 0 ; V_68 < F_59 ( V_73 , 32 ) ; V_68 ++ )
F_11 ( V_12 [ V_66 ] . V_83 [ V_68 ] ,
V_8 + V_17 + V_68 * 4 ) ;
F_11 ( V_76 , V_8 + V_75 ) ;
}
static void F_61 ( unsigned int V_66 )
{
int V_68 ;
T_2 * V_86 ;
void T_1 * V_8 ;
void T_1 * V_9 ;
if ( V_66 >= V_67 )
F_43 () ;
V_8 = F_4 ( & V_12 [ V_66 ] ) ;
V_9 = F_5 ( & V_12 [ V_66 ] ) ;
if ( ! V_8 || ! V_9 )
return;
V_86 = F_62 ( V_12 [ V_66 ] . V_87 ) ;
for ( V_68 = 0 ; V_68 < F_59 ( 32 , 32 ) ; V_68 ++ )
V_86 [ V_68 ] = F_13 ( V_8 + V_17 + V_68 * 4 ) ;
V_86 = F_62 ( V_12 [ V_66 ] . V_88 ) ;
for ( V_68 = 0 ; V_68 < F_59 ( 32 , 16 ) ; V_68 ++ )
V_86 [ V_68 ] = F_13 ( V_8 + V_81 + V_68 * 4 ) ;
}
static void F_63 ( unsigned int V_66 )
{
int V_68 ;
T_2 * V_86 ;
void T_1 * V_8 ;
void T_1 * V_9 ;
if ( V_66 >= V_67 )
F_43 () ;
V_8 = F_4 ( & V_12 [ V_66 ] ) ;
V_9 = F_5 ( & V_12 [ V_66 ] ) ;
if ( ! V_8 || ! V_9 )
return;
V_86 = F_62 ( V_12 [ V_66 ] . V_87 ) ;
for ( V_68 = 0 ; V_68 < F_59 ( 32 , 32 ) ; V_68 ++ )
F_11 ( V_86 [ V_68 ] , V_8 + V_17 + V_68 * 4 ) ;
V_86 = F_62 ( V_12 [ V_66 ] . V_88 ) ;
for ( V_68 = 0 ; V_68 < F_59 ( 32 , 16 ) ; V_68 ++ )
F_11 ( V_86 [ V_68 ] , V_8 + V_81 + V_68 * 4 ) ;
for ( V_68 = 0 ; V_68 < F_59 ( 32 , 4 ) ; V_68 ++ )
F_11 ( V_84 ,
V_8 + V_85 + V_68 * 4 ) ;
F_11 ( V_78 , V_9 + V_79 ) ;
F_49 () ;
}
static int F_64 ( struct V_89 * V_90 , unsigned long V_91 , void * V_92 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_67 ; V_68 ++ ) {
#ifdef F_65
if ( ! V_12 [ V_68 ] . V_7 )
continue;
#endif
switch ( V_91 ) {
case V_93 :
F_61 ( V_68 ) ;
break;
case V_94 :
case V_95 :
F_63 ( V_68 ) ;
break;
case V_96 :
F_58 ( V_68 ) ;
break;
case V_97 :
case V_98 :
F_60 ( V_68 ) ;
break;
}
}
return V_99 ;
}
static void T_4 F_66 ( struct V_5 * V_52 )
{
V_52 -> V_87 = F_67 ( F_59 ( 32 , 32 ) * 4 ,
sizeof( T_2 ) ) ;
F_55 ( ! V_52 -> V_87 ) ;
V_52 -> V_88 = F_67 ( F_59 ( 32 , 16 ) * 4 ,
sizeof( T_2 ) ) ;
F_55 ( ! V_52 -> V_88 ) ;
if ( V_52 == & V_12 [ 0 ] )
F_68 ( & V_100 ) ;
}
static void T_4 F_66 ( struct V_5 * V_52 )
{
}
static void F_69 ( const struct V_34 * V_15 , unsigned int V_56 )
{
int V_38 ;
unsigned long V_41 , V_101 = 0 ;
F_24 ( & V_45 , V_41 ) ;
F_70 (cpu, mask)
V_101 |= V_46 [ V_38 ] ;
F_71 ( V_102 ) ;
F_11 ( V_101 << 16 | V_56 , F_4 ( & V_12 [ 0 ] ) + V_103 ) ;
F_25 ( & V_45 , V_41 ) ;
}
void F_72 ( unsigned int V_104 , unsigned int V_56 )
{
F_55 ( V_104 >= V_43 ) ;
V_104 = 1 << V_104 ;
F_11 ( ( V_104 << 16 ) | V_56 , F_4 ( & V_12 [ 0 ] ) + V_103 ) ;
}
int F_73 ( unsigned int V_38 )
{
unsigned int V_105 ;
if ( V_38 >= V_43 )
return - 1 ;
V_105 = V_46 [ V_38 ] ;
if ( V_105 & ( V_105 - 1 ) )
return - 1 ;
return F_74 ( V_105 ) ;
}
void F_75 ( unsigned int V_106 )
{
unsigned int V_107 , V_73 , V_66 = 0 ;
void T_1 * V_8 ;
int V_68 , V_108 , V_38 = F_54 () ;
T_2 V_21 , V_109 , V_110 ;
if ( V_66 >= V_67 )
F_43 () ;
V_8 = F_4 ( & V_12 [ V_66 ] ) ;
if ( ! V_8 )
return;
V_73 = V_12 [ V_66 ] . V_73 ;
V_107 = F_74 ( V_46 [ V_38 ] ) ;
V_109 = 0x01010101 << V_107 ;
V_108 = ( V_107 - V_106 ) & 31 ;
F_35 ( & V_45 ) ;
V_46 [ V_38 ] = 1 << V_106 ;
for ( V_68 = 8 ; V_68 < F_59 ( V_73 , 4 ) ; V_68 ++ ) {
V_21 = F_13 ( V_8 + V_37 + V_68 * 4 ) ;
V_110 = V_21 & V_109 ;
if ( V_110 ) {
V_21 &= ~ V_110 ;
V_21 |= F_76 ( V_110 , V_108 ) ;
F_11 ( V_21 , V_8 + V_37 + V_68 * 4 ) ;
}
}
F_36 ( & V_45 ) ;
for ( V_68 = 0 ; V_68 < 16 ; V_68 += 4 ) {
int V_111 ;
V_21 = F_13 ( V_8 + V_112 + V_68 ) ;
if ( ! V_21 )
continue;
F_11 ( V_21 , V_8 + V_113 + V_68 ) ;
for ( V_111 = V_68 ; V_111 < V_68 + 4 ; V_111 ++ ) {
if ( V_21 & 0xff )
F_11 ( ( 1 << ( V_106 + 16 ) ) | V_111 ,
V_8 + V_103 ) ;
V_21 >>= 8 ;
}
}
}
unsigned long F_77 ( void )
{
if ( ! V_114 )
return 0 ;
return V_114 + V_103 ;
}
void T_4 F_78 ( struct V_115 * V_116 )
{
struct V_117 V_118 ;
if ( F_79 ( V_116 , 0 , & V_118 ) == 0 ) {
V_114 = V_118 . V_119 ;
F_80 ( L_2 , V_114 ) ;
}
}
static int F_81 ( struct V_120 * V_11 , unsigned int V_56 ,
T_6 V_121 )
{
if ( V_121 < 32 ) {
F_82 ( V_56 ) ;
F_83 ( V_11 , V_56 , V_121 , & V_122 , V_11 -> V_123 ,
V_124 , NULL , NULL ) ;
F_84 ( V_56 , V_125 | V_126 ) ;
} else {
F_83 ( V_11 , V_56 , V_121 , & V_122 , V_11 -> V_123 ,
V_127 , NULL , NULL ) ;
F_84 ( V_56 , V_125 | V_128 ) ;
}
return 0 ;
}
static void F_85 ( struct V_120 * V_11 , unsigned int V_56 )
{
}
static int F_86 ( struct V_120 * V_11 ,
struct V_115 * V_129 ,
const T_2 * V_130 , unsigned int V_131 ,
unsigned long * V_132 , unsigned int * V_133 )
{
unsigned long V_134 = 0 ;
if ( V_11 -> V_135 != V_129 )
return - V_30 ;
if ( V_131 < 3 )
return - V_30 ;
* V_132 = V_130 [ 1 ] + 16 ;
if ( ! V_130 [ 0 ] )
* V_132 += 16 ;
* V_133 = V_130 [ 2 ] & V_136 ;
return V_134 ;
}
static int F_87 ( struct V_89 * V_137 , unsigned long V_138 ,
void * V_139 )
{
if ( V_138 == V_140 || V_138 == V_141 )
F_53 ( & V_12 [ 0 ] ) ;
return V_99 ;
}
static int F_88 ( struct V_120 * V_55 , unsigned int V_142 ,
unsigned int V_143 , void * V_144 )
{
int V_68 , V_134 ;
T_6 V_13 ;
unsigned int type = V_145 ;
struct V_146 * V_10 = V_144 ;
V_134 = F_86 ( V_55 , V_10 -> V_147 , V_10 -> args ,
V_10 -> V_148 , & V_13 , & type ) ;
if ( V_134 )
return V_134 ;
for ( V_68 = 0 ; V_68 < V_143 ; V_68 ++ )
F_81 ( V_55 , V_142 + V_68 , V_13 + V_68 ) ;
return 0 ;
}
void F_89 ( unsigned long V_41 )
{
V_122 . V_41 |= V_41 ;
}
void T_4 F_90 ( unsigned int V_66 , int V_149 ,
void T_1 * V_8 , void T_1 * V_9 ,
T_2 V_150 , struct V_115 * V_116 )
{
T_6 V_151 ;
struct V_5 * V_52 ;
int V_73 , V_152 , V_68 ;
F_55 ( V_66 >= V_67 ) ;
V_52 = & V_12 [ V_66 ] ;
#ifdef F_65
if ( V_150 ) {
unsigned int V_38 ;
V_52 -> V_8 . V_3 = F_91 (void __iomem *) ;
V_52 -> V_9 . V_3 = F_91 (void __iomem *) ;
if ( F_92 ( ! V_52 -> V_8 . V_3 ||
! V_52 -> V_9 . V_3 ) ) {
F_93 ( V_52 -> V_8 . V_3 ) ;
F_93 ( V_52 -> V_9 . V_3 ) ;
return;
}
F_94 (cpu) {
T_2 V_153 = F_95 ( V_38 ) ;
T_2 V_154 = F_96 ( V_153 , 0 ) ;
unsigned long V_14 = V_150 * V_154 ;
* F_97 ( V_52 -> V_8 . V_3 , V_38 ) = V_8 + V_14 ;
* F_97 ( V_52 -> V_9 . V_3 , V_38 ) = V_9 + V_14 ;
}
F_98 ( V_52 , F_1 ) ;
} else
#endif
{
F_99 ( V_150 ,
L_3 ,
V_150 ) ;
V_52 -> V_8 . V_4 = V_8 ;
V_52 -> V_9 . V_4 = V_9 ;
F_98 ( V_52 , F_3 ) ;
}
for ( V_68 = 0 ; V_68 < V_43 ; V_68 ++ )
V_46 [ V_68 ] = 0xff ;
V_73 = F_13 ( F_4 ( V_52 ) + V_155 ) & 0x1f ;
V_73 = ( V_73 + 1 ) * 32 ;
if ( V_73 > 1020 )
V_73 = 1020 ;
V_52 -> V_73 = V_73 ;
if ( V_116 ) {
V_52 -> V_55 = F_100 ( V_116 , V_73 ,
& V_156 ,
V_52 ) ;
} else {
if ( V_66 == 0 && ( V_149 & 31 ) > 0 ) {
V_151 = 16 ;
if ( V_149 != - 1 )
V_149 = ( V_149 & ~ 31 ) + 16 ;
} else {
V_151 = 32 ;
}
V_73 -= V_151 ;
V_152 = F_101 ( V_149 , 16 , V_73 ,
F_102 () ) ;
if ( F_103 ( V_152 ) ) {
F_99 ( 1 , L_4 ,
V_149 ) ;
V_152 = V_149 ;
}
V_52 -> V_55 = F_104 ( V_116 , V_73 , V_152 ,
V_151 , & V_157 , V_52 ) ;
}
if ( F_92 ( ! V_52 -> V_55 ) )
return;
if ( V_66 == 0 ) {
#ifdef F_29
F_105 ( F_69 ) ;
F_106 ( & V_158 ) ;
#endif
F_107 ( F_26 ) ;
}
F_51 ( V_52 ) ;
F_53 ( V_52 ) ;
F_66 ( V_52 ) ;
}
static int T_4
F_108 ( struct V_115 * V_116 , struct V_115 * V_159 )
{
void T_1 * V_9 ;
void T_1 * V_8 ;
T_2 V_150 ;
int V_56 ;
if ( F_92 ( ! V_116 ) )
return - V_160 ;
V_8 = F_109 ( V_116 , 0 ) ;
F_99 ( ! V_8 , L_5 ) ;
V_9 = F_109 ( V_116 , 1 ) ;
F_99 ( ! V_9 , L_6 ) ;
if ( F_110 ( V_116 , L_7 , & V_150 ) )
V_150 = 0 ;
F_90 ( V_161 , - 1 , V_8 , V_9 , V_150 , V_116 ) ;
if ( ! V_161 )
F_78 ( V_116 ) ;
if ( V_159 ) {
V_56 = F_111 ( V_116 , 0 ) ;
F_42 ( V_161 , V_56 ) ;
}
if ( F_112 ( V_162 ) )
F_113 ( V_116 , V_12 [ V_161 ] . V_55 ) ;
V_161 ++ ;
return 0 ;
}
static int T_4
F_114 ( struct V_163 * V_164 ,
const unsigned long V_165 )
{
struct V_166 * V_167 ;
T_7 F_8 ;
static int V_168 ;
V_167 = (struct V_166 * ) V_164 ;
if ( F_115 ( V_167 , V_165 ) )
return - V_30 ;
F_8 = V_167 -> V_169 ;
if ( V_168 && F_8 != V_170 )
return - V_30 ;
V_170 = F_8 ;
V_168 = 1 ;
return 0 ;
}
static int T_4
F_116 ( struct V_163 * V_164 ,
const unsigned long V_165 )
{
struct V_171 * V_172 ;
V_172 = (struct V_171 * ) V_164 ;
if ( F_117 ( V_172 , V_165 ) )
return - V_30 ;
V_173 = V_172 -> V_169 ;
return 0 ;
}
int T_4
F_118 ( struct V_174 * V_175 )
{
void T_1 * V_9 , * V_8 ;
int V_176 ;
V_176 = F_119 ( V_177 ,
sizeof( struct V_178 ) ,
F_114 , V_175 ,
V_179 , 0 ) ;
if ( V_176 <= 0 ) {
F_120 ( L_8 ) ;
return - V_30 ;
}
V_176 = F_119 ( V_177 ,
sizeof( struct V_178 ) ,
F_116 , V_175 ,
V_180 , 0 ) ;
if ( V_176 <= 0 ) {
F_120 ( L_9 ) ;
return - V_30 ;
} else if ( V_176 > 1 ) {
F_120 ( L_10 ) ;
return - V_30 ;
}
V_9 = F_121 ( V_170 , V_181 ) ;
if ( ! V_9 ) {
F_120 ( L_11 ) ;
return - V_182 ;
}
V_8 = F_121 ( V_173 , V_183 ) ;
if ( ! V_8 ) {
F_120 ( L_12 ) ;
F_122 ( V_9 ) ;
return - V_182 ;
}
F_90 ( 0 , - 1 , V_8 , V_9 , 0 , NULL ) ;
F_123 ( V_12 [ 0 ] . V_55 ) ;
V_184 = V_185 ;
return 0 ;
}
