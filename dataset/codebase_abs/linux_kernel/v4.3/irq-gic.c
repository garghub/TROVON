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
static inline bool F_10 ( struct V_10 * V_11 )
{
void * V_6 = F_11 ( V_11 ) ;
return V_6 != NULL ;
}
static void F_12 ( struct V_10 * V_11 , T_2 V_14 )
{
T_2 V_15 = 1 << ( F_9 ( V_11 ) % 32 ) ;
F_13 ( V_15 , F_6 ( V_11 ) + V_14 + ( F_9 ( V_11 ) / 32 ) * 4 ) ;
}
static int F_14 ( struct V_10 * V_11 , T_2 V_14 )
{
T_2 V_15 = 1 << ( F_9 ( V_11 ) % 32 ) ;
return ! ! ( F_15 ( F_6 ( V_11 ) + V_14 + ( F_9 ( V_11 ) / 32 ) * 4 ) & V_15 ) ;
}
static void F_16 ( struct V_10 * V_11 )
{
F_12 ( V_11 , V_16 ) ;
}
static void F_17 ( struct V_10 * V_11 )
{
F_16 ( V_11 ) ;
if ( F_18 ( V_11 ) )
F_12 ( V_11 , V_17 ) ;
}
static void F_19 ( struct V_10 * V_11 )
{
F_12 ( V_11 , V_18 ) ;
}
static void F_20 ( struct V_10 * V_11 )
{
F_13 ( F_9 ( V_11 ) , F_8 ( V_11 ) + V_19 ) ;
}
static void F_21 ( struct V_10 * V_11 )
{
if ( F_18 ( V_11 ) )
return;
F_13 ( F_9 ( V_11 ) , F_8 ( V_11 ) + V_20 ) ;
}
static int F_22 ( struct V_10 * V_11 ,
enum V_21 V_22 , bool V_23 )
{
T_2 V_24 ;
switch ( V_22 ) {
case V_25 :
V_24 = V_23 ? V_26 : V_27 ;
break;
case V_28 :
V_24 = V_23 ? V_29 : V_17 ;
break;
case V_30 :
V_24 = V_23 ? V_16 : V_18 ;
break;
default:
return - V_31 ;
}
F_12 ( V_11 , V_24 ) ;
return 0 ;
}
static int F_23 ( struct V_10 * V_11 ,
enum V_21 V_22 , bool * V_23 )
{
switch ( V_22 ) {
case V_25 :
* V_23 = F_14 ( V_11 , V_26 ) ;
break;
case V_28 :
* V_23 = F_14 ( V_11 , V_29 ) ;
break;
case V_30 :
* V_23 = ! F_14 ( V_11 , V_18 ) ;
break;
default:
return - V_31 ;
}
return 0 ;
}
static int F_24 ( struct V_10 * V_11 , unsigned int type )
{
void T_1 * V_2 = F_6 ( V_11 ) ;
unsigned int V_32 = F_9 ( V_11 ) ;
if ( V_32 < 16 )
return - V_31 ;
if ( V_32 >= 32 && type != V_33 &&
type != V_34 )
return - V_31 ;
return F_25 ( V_32 , type , V_2 , NULL ) ;
}
static int F_26 ( struct V_10 * V_11 , void * V_35 )
{
if ( F_10 ( V_11 ) )
return - V_31 ;
if ( V_35 )
F_27 ( V_11 ) ;
else
F_28 ( V_11 ) ;
return 0 ;
}
static int F_29 ( struct V_10 * V_11 , const struct V_36 * V_37 ,
bool V_38 )
{
void T_1 * V_24 = F_6 ( V_11 ) + V_39 + ( F_9 ( V_11 ) & ~ 3 ) ;
unsigned int V_40 , V_41 = ( F_9 ( V_11 ) % 4 ) * 8 ;
T_2 V_23 , V_15 , V_42 ;
unsigned long V_43 ;
if ( ! V_38 )
V_40 = F_30 ( V_37 , V_44 ) ;
else
V_40 = F_31 ( V_37 ) ;
if ( V_40 >= V_45 || V_40 >= V_46 )
return - V_31 ;
F_32 ( & V_47 , V_43 ) ;
V_15 = 0xff << V_41 ;
V_42 = V_48 [ V_40 ] << V_41 ;
V_23 = F_15 ( V_24 ) & ~ V_15 ;
F_13 ( V_23 | V_42 , V_24 ) ;
F_33 ( & V_47 , V_43 ) ;
return V_49 ;
}
static void T_3 F_34 ( struct V_50 * V_51 )
{
T_2 V_52 , V_53 ;
struct V_5 * V_54 = & V_12 [ 0 ] ;
void T_1 * V_9 = F_5 ( V_54 ) ;
do {
V_52 = F_15 ( V_9 + V_55 ) ;
V_53 = V_52 & V_56 ;
if ( F_35 ( V_53 > 15 && V_53 < 1021 ) ) {
if ( F_36 ( & V_57 ) )
F_13 ( V_52 , V_9 + V_19 ) ;
F_37 ( V_54 -> V_58 , V_53 , V_51 ) ;
continue;
}
if ( V_53 < 16 ) {
F_13 ( V_52 , V_9 + V_19 ) ;
if ( F_36 ( & V_57 ) )
F_13 ( V_52 , V_9 + V_20 ) ;
#ifdef F_38
F_39 ( V_53 , V_51 ) ;
#endif
continue;
}
break;
} while ( 1 );
}
static void F_40 ( struct V_59 * V_60 )
{
struct V_5 * V_61 = F_41 ( V_60 ) ;
struct V_62 * V_63 = F_42 ( V_60 ) ;
unsigned int V_64 , F_9 ;
unsigned long V_65 ;
F_43 ( V_63 , V_60 ) ;
F_44 ( & V_47 ) ;
V_65 = F_15 ( F_5 ( V_61 ) + V_55 ) ;
F_45 ( & V_47 ) ;
F_9 = ( V_65 & V_56 ) ;
if ( F_9 == V_66 )
goto V_67;
V_64 = F_46 ( V_61 -> V_58 , F_9 ) ;
if ( F_47 ( F_9 < 32 || F_9 > 1020 ) )
F_48 ( V_60 ) ;
else
F_49 ( V_64 ) ;
V_67:
F_50 ( V_63 , V_60 ) ;
}
void T_4 F_51 ( unsigned int V_68 , unsigned int V_69 )
{
if ( V_68 >= V_70 )
F_52 () ;
F_53 ( V_69 , F_40 ,
& V_12 [ V_68 ] ) ;
}
static T_5 F_54 ( struct V_5 * V_54 )
{
void T_1 * V_2 = F_4 ( V_54 ) ;
T_2 V_15 , V_71 ;
for ( V_71 = V_15 = 0 ; V_71 < 32 ; V_71 += 4 ) {
V_15 = F_15 ( V_2 + V_39 + V_71 ) ;
V_15 |= V_15 >> 16 ;
V_15 |= V_15 >> 8 ;
if ( V_15 )
break;
}
if ( ! V_15 && F_55 () > 1 )
F_56 ( L_1 ) ;
return V_15 ;
}
static void F_57 ( struct V_5 * V_54 )
{
void T_1 * V_9 = F_5 ( V_54 ) ;
T_2 V_72 = 0 ;
T_2 V_73 = 0 ;
if ( F_36 ( & V_57 ) )
V_73 = V_74 ;
V_72 = F_58 ( V_9 + V_75 ) ;
V_72 &= V_76 ;
F_13 ( V_72 | V_73 | V_77 , V_9 + V_75 ) ;
}
static void T_4 F_59 ( struct V_5 * V_54 )
{
unsigned int V_71 ;
T_2 V_36 ;
unsigned int V_78 = V_54 -> V_78 ;
void T_1 * V_2 = F_4 ( V_54 ) ;
F_13 ( V_79 , V_2 + V_80 ) ;
V_36 = F_54 ( V_54 ) ;
V_36 |= V_36 << 8 ;
V_36 |= V_36 << 16 ;
for ( V_71 = 32 ; V_71 < V_78 ; V_71 += 4 )
F_13 ( V_36 , V_2 + V_39 + V_71 * 4 / 4 ) ;
F_60 ( V_2 , V_78 , NULL ) ;
F_13 ( V_81 , V_2 + V_80 ) ;
}
static void F_61 ( struct V_5 * V_54 )
{
void T_1 * V_8 = F_4 ( V_54 ) ;
void T_1 * V_2 = F_5 ( V_54 ) ;
unsigned int V_82 , V_40 = F_62 () ;
int V_71 ;
if ( V_54 == & V_12 [ 0 ] ) {
F_63 ( V_40 >= V_45 ) ;
V_82 = F_54 ( V_54 ) ;
V_48 [ V_40 ] = V_82 ;
for ( V_71 = 0 ; V_71 < V_45 ; V_71 ++ )
if ( V_71 != V_40 )
V_48 [ V_71 ] &= ~ V_82 ;
}
F_64 ( V_8 , NULL ) ;
F_13 ( V_83 , V_2 + V_84 ) ;
F_57 ( V_54 ) ;
}
int F_65 ( unsigned int V_68 )
{
void T_1 * V_9 ;
T_2 V_23 = 0 ;
if ( V_68 >= V_70 )
return - V_31 ;
V_9 = F_5 ( & V_12 [ V_68 ] ) ;
V_23 = F_58 ( V_9 + V_75 ) ;
V_23 &= ~ V_77 ;
F_13 ( V_23 , V_9 + V_75 ) ;
return 0 ;
}
static void F_66 ( unsigned int V_68 )
{
unsigned int V_78 ;
void T_1 * V_8 ;
int V_71 ;
if ( V_68 >= V_70 )
F_52 () ;
V_78 = V_12 [ V_68 ] . V_78 ;
V_8 = F_4 ( & V_12 [ V_68 ] ) ;
if ( ! V_8 )
return;
for ( V_71 = 0 ; V_71 < F_67 ( V_78 , 16 ) ; V_71 ++ )
V_12 [ V_68 ] . V_85 [ V_71 ] =
F_15 ( V_8 + V_86 + V_71 * 4 ) ;
for ( V_71 = 0 ; V_71 < F_67 ( V_78 , 4 ) ; V_71 ++ )
V_12 [ V_68 ] . V_87 [ V_71 ] =
F_15 ( V_8 + V_39 + V_71 * 4 ) ;
for ( V_71 = 0 ; V_71 < F_67 ( V_78 , 32 ) ; V_71 ++ )
V_12 [ V_68 ] . V_88 [ V_71 ] =
F_15 ( V_8 + V_18 + V_71 * 4 ) ;
}
static void F_68 ( unsigned int V_68 )
{
unsigned int V_78 ;
unsigned int V_71 ;
void T_1 * V_8 ;
if ( V_68 >= V_70 )
F_52 () ;
V_78 = V_12 [ V_68 ] . V_78 ;
V_8 = F_4 ( & V_12 [ V_68 ] ) ;
if ( ! V_8 )
return;
F_13 ( V_79 , V_8 + V_80 ) ;
for ( V_71 = 0 ; V_71 < F_67 ( V_78 , 16 ) ; V_71 ++ )
F_13 ( V_12 [ V_68 ] . V_85 [ V_71 ] ,
V_8 + V_86 + V_71 * 4 ) ;
for ( V_71 = 0 ; V_71 < F_67 ( V_78 , 4 ) ; V_71 ++ )
F_13 ( V_89 ,
V_8 + V_90 + V_71 * 4 ) ;
for ( V_71 = 0 ; V_71 < F_67 ( V_78 , 4 ) ; V_71 ++ )
F_13 ( V_12 [ V_68 ] . V_87 [ V_71 ] ,
V_8 + V_39 + V_71 * 4 ) ;
for ( V_71 = 0 ; V_71 < F_67 ( V_78 , 32 ) ; V_71 ++ )
F_13 ( V_12 [ V_68 ] . V_88 [ V_71 ] ,
V_8 + V_18 + V_71 * 4 ) ;
F_13 ( V_81 , V_8 + V_80 ) ;
}
static void F_69 ( unsigned int V_68 )
{
int V_71 ;
T_2 * V_91 ;
void T_1 * V_8 ;
void T_1 * V_9 ;
if ( V_68 >= V_70 )
F_52 () ;
V_8 = F_4 ( & V_12 [ V_68 ] ) ;
V_9 = F_5 ( & V_12 [ V_68 ] ) ;
if ( ! V_8 || ! V_9 )
return;
V_91 = F_70 ( V_12 [ V_68 ] . V_92 ) ;
for ( V_71 = 0 ; V_71 < F_67 ( 32 , 32 ) ; V_71 ++ )
V_91 [ V_71 ] = F_15 ( V_8 + V_18 + V_71 * 4 ) ;
V_91 = F_70 ( V_12 [ V_68 ] . V_93 ) ;
for ( V_71 = 0 ; V_71 < F_67 ( 32 , 16 ) ; V_71 ++ )
V_91 [ V_71 ] = F_15 ( V_8 + V_86 + V_71 * 4 ) ;
}
static void F_71 ( unsigned int V_68 )
{
int V_71 ;
T_2 * V_91 ;
void T_1 * V_8 ;
void T_1 * V_9 ;
if ( V_68 >= V_70 )
F_52 () ;
V_8 = F_4 ( & V_12 [ V_68 ] ) ;
V_9 = F_5 ( & V_12 [ V_68 ] ) ;
if ( ! V_8 || ! V_9 )
return;
V_91 = F_70 ( V_12 [ V_68 ] . V_92 ) ;
for ( V_71 = 0 ; V_71 < F_67 ( 32 , 32 ) ; V_71 ++ )
F_13 ( V_91 [ V_71 ] , V_8 + V_18 + V_71 * 4 ) ;
V_91 = F_70 ( V_12 [ V_68 ] . V_93 ) ;
for ( V_71 = 0 ; V_71 < F_67 ( 32 , 16 ) ; V_71 ++ )
F_13 ( V_91 [ V_71 ] , V_8 + V_86 + V_71 * 4 ) ;
for ( V_71 = 0 ; V_71 < F_67 ( 32 , 4 ) ; V_71 ++ )
F_13 ( V_89 ,
V_8 + V_90 + V_71 * 4 ) ;
F_13 ( V_83 , V_9 + V_84 ) ;
F_57 ( & V_12 [ V_68 ] ) ;
}
static int F_72 ( struct V_94 * V_95 , unsigned long V_96 , void * V_97 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_70 ; V_71 ++ ) {
#ifdef F_73
if ( ! V_12 [ V_71 ] . V_7 )
continue;
#endif
switch ( V_96 ) {
case V_98 :
F_69 ( V_71 ) ;
break;
case V_99 :
case V_100 :
F_71 ( V_71 ) ;
break;
case V_101 :
F_66 ( V_71 ) ;
break;
case V_102 :
case V_103 :
F_68 ( V_71 ) ;
break;
}
}
return V_104 ;
}
static void T_4 F_74 ( struct V_5 * V_54 )
{
V_54 -> V_92 = F_75 ( F_67 ( 32 , 32 ) * 4 ,
sizeof( T_2 ) ) ;
F_63 ( ! V_54 -> V_92 ) ;
V_54 -> V_93 = F_75 ( F_67 ( 32 , 16 ) * 4 ,
sizeof( T_2 ) ) ;
F_63 ( ! V_54 -> V_93 ) ;
if ( V_54 == & V_12 [ 0 ] )
F_76 ( & V_105 ) ;
}
static void T_4 F_74 ( struct V_5 * V_54 )
{
}
static void F_77 ( const struct V_36 * V_15 , unsigned int V_69 )
{
int V_40 ;
unsigned long V_43 , V_106 = 0 ;
F_32 ( & V_47 , V_43 ) ;
F_78 (cpu, mask)
V_106 |= V_48 [ V_40 ] ;
F_79 ( V_107 ) ;
F_13 ( V_106 << 16 | V_69 , F_4 ( & V_12 [ 0 ] ) + V_108 ) ;
F_33 ( & V_47 , V_43 ) ;
}
void F_80 ( unsigned int V_109 , unsigned int V_69 )
{
F_63 ( V_109 >= V_45 ) ;
V_109 = 1 << V_109 ;
F_13 ( ( V_109 << 16 ) | V_69 , F_4 ( & V_12 [ 0 ] ) + V_108 ) ;
}
int F_81 ( unsigned int V_40 )
{
unsigned int V_110 ;
if ( V_40 >= V_45 )
return - 1 ;
V_110 = V_48 [ V_40 ] ;
if ( V_110 & ( V_110 - 1 ) )
return - 1 ;
return F_82 ( V_110 ) ;
}
void F_83 ( unsigned int V_111 )
{
unsigned int V_112 , V_78 , V_68 = 0 ;
void T_1 * V_8 ;
int V_71 , V_113 , V_40 = F_62 () ;
T_2 V_23 , V_114 , V_115 ;
if ( V_68 >= V_70 )
F_52 () ;
V_8 = F_4 ( & V_12 [ V_68 ] ) ;
if ( ! V_8 )
return;
V_78 = V_12 [ V_68 ] . V_78 ;
V_112 = F_82 ( V_48 [ V_40 ] ) ;
V_114 = 0x01010101 << V_112 ;
V_113 = ( V_112 - V_111 ) & 31 ;
F_44 ( & V_47 ) ;
V_48 [ V_40 ] = 1 << V_111 ;
for ( V_71 = 8 ; V_71 < F_67 ( V_78 , 4 ) ; V_71 ++ ) {
V_23 = F_15 ( V_8 + V_39 + V_71 * 4 ) ;
V_115 = V_23 & V_114 ;
if ( V_115 ) {
V_23 &= ~ V_115 ;
V_23 |= F_84 ( V_115 , V_113 ) ;
F_13 ( V_23 , V_8 + V_39 + V_71 * 4 ) ;
}
}
F_45 ( & V_47 ) ;
for ( V_71 = 0 ; V_71 < 16 ; V_71 += 4 ) {
int V_116 ;
V_23 = F_15 ( V_8 + V_117 + V_71 ) ;
if ( ! V_23 )
continue;
F_13 ( V_23 , V_8 + V_118 + V_71 ) ;
for ( V_116 = V_71 ; V_116 < V_71 + 4 ; V_116 ++ ) {
if ( V_23 & 0xff )
F_13 ( ( 1 << ( V_111 + 16 ) ) | V_116 ,
V_8 + V_108 ) ;
V_23 >>= 8 ;
}
}
}
unsigned long F_85 ( void )
{
if ( ! V_119 )
return 0 ;
return V_119 + V_108 ;
}
void T_4 F_86 ( struct V_120 * V_121 )
{
struct V_122 V_123 ;
if ( F_87 ( V_121 , 0 , & V_123 ) == 0 ) {
V_119 = V_123 . V_124 ;
F_88 ( L_2 , V_119 ) ;
}
}
static int F_89 ( struct V_125 * V_11 , unsigned int V_69 ,
T_6 V_126 )
{
struct V_62 * V_63 = & V_127 ;
if ( F_36 ( & V_57 ) ) {
if ( V_11 -> V_128 == ( void * ) & V_12 [ 0 ] )
V_63 = & V_129 ;
}
if ( V_126 < 32 ) {
F_90 ( V_69 ) ;
F_91 ( V_11 , V_69 , V_126 , V_63 , V_11 -> V_128 ,
V_130 , NULL , NULL ) ;
F_92 ( V_69 , V_131 ) ;
} else {
F_91 ( V_11 , V_69 , V_126 , V_63 , V_11 -> V_128 ,
V_132 , NULL , NULL ) ;
F_93 ( V_69 ) ;
}
return 0 ;
}
static void F_94 ( struct V_125 * V_11 , unsigned int V_69 )
{
}
static int F_95 ( struct V_125 * V_11 ,
struct V_120 * V_133 ,
const T_2 * V_134 , unsigned int V_135 ,
unsigned long * V_136 , unsigned int * V_137 )
{
unsigned long V_138 = 0 ;
if ( V_11 -> V_139 != V_133 )
return - V_31 ;
if ( V_135 < 3 )
return - V_31 ;
* V_136 = V_134 [ 1 ] + 16 ;
if ( ! V_134 [ 0 ] )
* V_136 += 16 ;
* V_137 = V_134 [ 2 ] & V_140 ;
return V_138 ;
}
static int F_96 ( struct V_94 * V_141 , unsigned long V_142 ,
void * V_143 )
{
if ( V_142 == V_144 || V_142 == V_145 )
F_61 ( & V_12 [ 0 ] ) ;
return V_104 ;
}
static int F_97 ( struct V_125 * V_58 , unsigned int V_146 ,
unsigned int V_147 , void * V_148 )
{
int V_71 , V_138 ;
T_6 V_13 ;
unsigned int type = V_149 ;
struct V_150 * V_10 = V_148 ;
V_138 = F_95 ( V_58 , V_10 -> V_151 , V_10 -> args ,
V_10 -> V_152 , & V_13 , & type ) ;
if ( V_138 )
return V_138 ;
for ( V_71 = 0 ; V_71 < V_147 ; V_71 ++ )
F_89 ( V_58 , V_146 + V_71 , V_13 + V_71 ) ;
return 0 ;
}
static void T_4 F_98 ( unsigned int V_68 , int V_153 ,
void T_1 * V_8 , void T_1 * V_9 ,
T_2 V_154 , struct V_120 * V_121 )
{
T_6 V_155 ;
struct V_5 * V_54 ;
int V_78 , V_156 , V_71 ;
F_63 ( V_68 >= V_70 ) ;
V_54 = & V_12 [ V_68 ] ;
#ifdef F_73
if ( V_154 ) {
unsigned int V_40 ;
V_54 -> V_8 . V_3 = F_99 (void __iomem *) ;
V_54 -> V_9 . V_3 = F_99 (void __iomem *) ;
if ( F_100 ( ! V_54 -> V_8 . V_3 ||
! V_54 -> V_9 . V_3 ) ) {
F_101 ( V_54 -> V_8 . V_3 ) ;
F_101 ( V_54 -> V_9 . V_3 ) ;
return;
}
F_102 (cpu) {
T_2 V_157 = F_103 ( V_40 ) ;
T_2 V_158 = F_104 ( V_157 , 0 ) ;
unsigned long V_14 = V_154 * V_158 ;
* F_105 ( V_54 -> V_8 . V_3 , V_40 ) = V_8 + V_14 ;
* F_105 ( V_54 -> V_9 . V_3 , V_40 ) = V_9 + V_14 ;
}
F_106 ( V_54 , F_1 ) ;
} else
#endif
{
F_107 ( V_154 ,
L_3 ,
V_154 ) ;
V_54 -> V_8 . V_4 = V_8 ;
V_54 -> V_9 . V_4 = V_9 ;
F_106 ( V_54 , F_3 ) ;
}
V_78 = F_15 ( F_4 ( V_54 ) + V_159 ) & 0x1f ;
V_78 = ( V_78 + 1 ) * 32 ;
if ( V_78 > 1020 )
V_78 = 1020 ;
V_54 -> V_78 = V_78 ;
if ( V_121 ) {
V_54 -> V_58 = F_108 ( V_121 , V_78 ,
& V_160 ,
V_54 ) ;
} else {
if ( V_68 == 0 && ( V_153 & 31 ) > 0 ) {
V_155 = 16 ;
if ( V_153 != - 1 )
V_153 = ( V_153 & ~ 31 ) + 16 ;
} else {
V_155 = 32 ;
}
V_78 -= V_155 ;
V_156 = F_109 ( V_153 , 16 , V_78 ,
F_110 () ) ;
if ( F_111 ( V_156 ) ) {
F_107 ( 1 , L_4 ,
V_153 ) ;
V_156 = V_153 ;
}
V_54 -> V_58 = F_112 ( V_121 , V_78 , V_156 ,
V_155 , & V_161 , V_54 ) ;
}
if ( F_100 ( ! V_54 -> V_58 ) )
return;
if ( V_68 == 0 ) {
for ( V_71 = 0 ; V_71 < V_45 ; V_71 ++ )
V_48 [ V_71 ] = 0xff ;
#ifdef F_38
F_113 ( F_77 ) ;
F_114 ( & V_162 ) ;
#endif
F_115 ( F_34 ) ;
if ( F_36 ( & V_57 ) )
F_88 ( L_5 ) ;
}
F_59 ( V_54 ) ;
F_61 ( V_54 ) ;
F_74 ( V_54 ) ;
}
void T_4 F_116 ( unsigned int V_68 , int V_153 ,
void T_1 * V_8 , void T_1 * V_9 ,
T_2 V_154 , struct V_120 * V_121 )
{
F_117 ( & V_57 ) ;
F_98 ( V_68 , V_153 , V_8 , V_9 ,
V_154 , V_121 ) ;
}
static bool F_118 ( struct V_120 * V_121 , void T_1 * * V_2 )
{
struct V_122 V_163 ;
F_87 ( V_121 , 1 , & V_163 ) ;
if ( ! F_119 () )
return false ;
if ( F_120 ( & V_163 ) < V_164 )
return false ;
if ( F_120 ( & V_163 ) == V_165 ) {
T_2 V_166 , V_167 ;
V_166 = F_15 ( * V_2 + V_168 ) ;
V_167 = F_15 ( * V_2 + V_168 + 0xf000 ) ;
if ( ( V_166 & 0xffff0fff ) != 0x0202043B ||
V_166 != V_167 )
return false ;
* V_2 += 0xf000 ;
V_163 . V_124 += 0xf000 ;
F_121 ( L_6 ,
& V_163 . V_124 ) ;
}
return true ;
}
static int T_4
F_122 ( struct V_120 * V_121 , struct V_120 * V_169 )
{
void T_1 * V_9 ;
void T_1 * V_8 ;
T_2 V_154 ;
int V_69 ;
if ( F_100 ( ! V_121 ) )
return - V_170 ;
V_8 = F_123 ( V_121 , 0 ) ;
F_107 ( ! V_8 , L_7 ) ;
V_9 = F_123 ( V_121 , 1 ) ;
F_107 ( ! V_9 , L_8 ) ;
if ( V_171 == 0 && ! F_118 ( V_121 , & V_9 ) )
F_117 ( & V_57 ) ;
if ( F_124 ( V_121 , L_9 , & V_154 ) )
V_154 = 0 ;
F_98 ( V_171 , - 1 , V_8 , V_9 , V_154 , V_121 ) ;
if ( ! V_171 )
F_86 ( V_121 ) ;
if ( V_169 ) {
V_69 = F_125 ( V_121 , 0 ) ;
F_51 ( V_171 , V_69 ) ;
}
if ( F_126 ( V_172 ) )
F_127 ( V_121 , V_12 [ V_171 ] . V_58 ) ;
V_171 ++ ;
return 0 ;
}
static int T_4
F_128 ( struct V_173 * V_174 ,
const unsigned long V_175 )
{
struct V_176 * V_177 ;
T_7 F_8 ;
static int V_178 ;
V_177 = (struct V_176 * ) V_174 ;
if ( F_129 ( V_177 , V_175 ) )
return - V_31 ;
F_8 = V_177 -> V_179 ;
if ( V_178 && F_8 != V_180 )
return - V_31 ;
V_180 = F_8 ;
V_178 = 1 ;
return 0 ;
}
static int T_4
F_130 ( struct V_173 * V_174 ,
const unsigned long V_175 )
{
struct V_181 * V_182 ;
V_182 = (struct V_181 * ) V_174 ;
if ( F_131 ( V_182 , V_175 ) )
return - V_31 ;
V_183 = V_182 -> V_179 ;
return 0 ;
}
int T_4
F_132 ( struct V_184 * V_185 )
{
void T_1 * V_9 , * V_8 ;
int V_186 ;
V_186 = F_133 ( V_187 ,
sizeof( struct V_188 ) ,
F_128 , V_185 ,
V_189 , 0 ) ;
if ( V_186 <= 0 ) {
F_134 ( L_10 ) ;
return - V_31 ;
}
V_186 = F_133 ( V_187 ,
sizeof( struct V_188 ) ,
F_130 , V_185 ,
V_190 , 0 ) ;
if ( V_186 <= 0 ) {
F_134 ( L_11 ) ;
return - V_31 ;
} else if ( V_186 > 1 ) {
F_134 ( L_12 ) ;
return - V_31 ;
}
V_9 = F_135 ( V_180 , V_191 ) ;
if ( ! V_9 ) {
F_134 ( L_13 ) ;
return - V_192 ;
}
V_8 = F_135 ( V_183 , V_193 ) ;
if ( ! V_8 ) {
F_134 ( L_14 ) ;
F_136 ( V_9 ) ;
return - V_192 ;
}
if ( ! F_119 () )
F_117 ( & V_57 ) ;
F_98 ( 0 , - 1 , V_8 , V_9 , 0 , NULL ) ;
F_137 ( V_12 [ 0 ] . V_58 ) ;
V_194 = V_195 ;
return 0 ;
}
