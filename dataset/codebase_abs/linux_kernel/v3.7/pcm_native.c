static inline T_1 F_1 ( void )
{
T_1 V_1 = F_2 () ;
F_3 ( F_4 () ) ;
return V_1 ;
}
static inline void F_5 ( T_1 V_1 )
{
F_3 ( V_1 ) ;
}
int F_6 ( struct V_2 * V_3 , struct F_6 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_9 * V_10 = V_3 -> V_10 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_11 = V_8 -> V_11 -> V_12 ;
V_4 -> V_13 = V_8 -> V_13 ;
V_4 -> V_14 = V_3 -> V_14 ;
V_4 -> V_15 = V_3 -> V_12 ;
F_7 ( V_4 -> V_16 , V_8 -> V_16 , sizeof( V_4 -> V_16 ) ) ;
F_7 ( V_4 -> V_17 , V_8 -> V_17 , sizeof( V_4 -> V_17 ) ) ;
V_4 -> V_18 = V_8 -> V_18 ;
V_4 -> V_19 = V_8 -> V_19 ;
V_4 -> V_20 = V_10 -> V_21 ;
V_4 -> V_22 = V_10 -> V_21 - V_10 -> V_23 ;
F_7 ( V_4 -> V_24 , V_3 -> V_17 , sizeof( V_4 -> V_24 ) ) ;
V_6 = V_3 -> V_6 ;
if ( V_6 ) {
V_4 -> V_25 = V_6 -> V_25 ;
V_3 -> V_26 -> V_27 ( V_3 , V_28 , V_4 ) ;
}
return 0 ;
}
int F_8 ( struct V_2 * V_3 ,
struct F_6 T_2 * V_29 )
{
struct F_6 * V_4 ;
int V_30 ;
V_4 = F_9 ( sizeof( * V_4 ) , V_31 ) ;
if ( ! V_4 )
return - V_32 ;
V_30 = F_6 ( V_3 , V_4 ) ;
if ( V_30 >= 0 ) {
if ( F_10 ( V_29 , V_4 , sizeof( * V_4 ) ) )
V_30 = - V_33 ;
}
F_11 ( V_4 ) ;
return V_30 ;
}
int F_12 ( struct V_2 * V_3 ,
struct V_34 * V_35 )
{
unsigned int V_36 ;
struct V_37 * V_38 ;
struct V_39 * V_40 = NULL ;
struct V_41 * V_42 = NULL ;
struct V_43 * V_44 = & V_3 -> V_6 -> V_45 ;
unsigned int V_46 [ V_44 -> V_47 ] ;
unsigned int V_48 [ V_49 + 1 ] ;
unsigned int V_50 = 2 ;
int V_51 , V_52 ;
V_35 -> V_4 = 0 ;
V_35 -> V_53 = 0 ;
if ( V_35 -> V_54 & ( 1 << V_55 ) )
V_35 -> V_56 = 0 ;
if ( V_35 -> V_54 & ( 1 << V_57 ) ) {
V_35 -> V_58 = 0 ;
V_35 -> V_59 = 0 ;
}
for ( V_36 = V_60 ; V_36 <= V_61 ; V_36 ++ ) {
V_42 = F_13 ( V_35 , V_36 ) ;
if ( F_14 ( V_42 ) )
return - V_62 ;
if ( ! ( V_35 -> V_54 & ( 1 << V_36 ) ) )
continue;
#ifdef F_15
F_16 ( V_63 L_1 , V_64 [ V_36 ] ) ;
F_16 ( L_2 , V_42 -> V_65 [ 3 ] , V_42 -> V_65 [ 2 ] , V_42 -> V_65 [ 1 ] , V_42 -> V_65 [ 0 ] ) ;
#endif
V_51 = F_17 ( V_42 , F_18 ( V_44 , V_36 ) ) ;
#ifdef F_15
F_16 ( L_3 , V_42 -> V_65 [ 3 ] , V_42 -> V_65 [ 2 ] , V_42 -> V_65 [ 1 ] , V_42 -> V_65 [ 0 ] ) ;
#endif
if ( V_51 )
V_35 -> V_66 |= 1 << V_36 ;
if ( V_51 < 0 )
return V_51 ;
}
for ( V_36 = V_67 ; V_36 <= V_49 ; V_36 ++ ) {
V_40 = F_19 ( V_35 , V_36 ) ;
if ( F_20 ( V_40 ) )
return - V_62 ;
if ( ! ( V_35 -> V_54 & ( 1 << V_36 ) ) )
continue;
#ifdef F_15
F_16 ( V_63 L_1 , V_64 [ V_36 ] ) ;
if ( V_40 -> V_68 )
F_16 ( L_4 ) ;
else
F_16 ( L_5 ,
V_40 -> V_69 ? '(' : '[' , V_40 -> V_70 ,
V_40 -> V_71 , V_40 -> V_72 ? ')' : ']' ) ;
F_16 ( L_6 ) ;
#endif
V_51 = F_21 ( V_40 , F_22 ( V_44 , V_36 ) ) ;
#ifdef F_15
if ( V_40 -> V_68 )
F_16 ( L_7 ) ;
else
F_16 ( L_8 ,
V_40 -> V_69 ? '(' : '[' , V_40 -> V_70 ,
V_40 -> V_71 , V_40 -> V_72 ? ')' : ']' ) ;
#endif
if ( V_51 )
V_35 -> V_66 |= 1 << V_36 ;
if ( V_51 < 0 )
return V_51 ;
}
for ( V_36 = 0 ; V_36 < V_44 -> V_47 ; V_36 ++ )
V_46 [ V_36 ] = 0 ;
for ( V_36 = 0 ; V_36 <= V_49 ; V_36 ++ )
V_48 [ V_36 ] = ( V_35 -> V_54 & ( 1 << V_36 ) ) ? 1 : 0 ;
do {
V_52 = 0 ;
for ( V_36 = 0 ; V_36 < V_44 -> V_47 ; V_36 ++ ) {
struct V_73 * V_74 = & V_44 -> V_75 [ V_36 ] ;
unsigned int V_76 ;
int V_77 = 0 ;
if ( V_74 -> V_78 && ! ( V_74 -> V_78 & V_35 -> V_79 ) )
continue;
for ( V_76 = 0 ; V_74 -> V_80 [ V_76 ] >= 0 ; V_76 ++ ) {
if ( V_48 [ V_74 -> V_80 [ V_76 ] ] > V_46 [ V_36 ] ) {
V_77 = 1 ;
break;
}
}
if ( ! V_77 )
continue;
#ifdef F_15
F_16 ( V_63 L_9 , V_36 , V_74 -> V_81 ) ;
if ( V_74 -> V_82 >= 0 ) {
F_16 ( L_1 , V_64 [ V_74 -> V_82 ] ) ;
if ( F_23 ( V_74 -> V_82 ) ) {
V_42 = F_13 ( V_35 , V_74 -> V_82 ) ;
F_16 ( L_10 , * V_42 -> V_65 ) ;
} else {
V_40 = F_19 ( V_35 , V_74 -> V_82 ) ;
if ( V_40 -> V_68 )
F_16 ( L_4 ) ;
else
F_16 ( L_5 ,
V_40 -> V_69 ? '(' : '[' , V_40 -> V_70 ,
V_40 -> V_71 , V_40 -> V_72 ? ')' : ']' ) ;
}
}
#endif
V_51 = V_74 -> V_81 ( V_35 , V_74 ) ;
#ifdef F_15
if ( V_74 -> V_82 >= 0 ) {
F_16 ( L_6 ) ;
if ( F_23 ( V_74 -> V_82 ) )
F_16 ( L_10 , * V_42 -> V_65 ) ;
else {
if ( V_40 -> V_68 )
F_16 ( L_4 ) ;
else
F_16 ( L_5 ,
V_40 -> V_69 ? '(' : '[' , V_40 -> V_70 ,
V_40 -> V_71 , V_40 -> V_72 ? ')' : ']' ) ;
}
}
F_16 ( L_11 ) ;
#endif
V_46 [ V_36 ] = V_50 ;
if ( V_51 && V_74 -> V_82 >= 0 ) {
V_35 -> V_66 |= ( 1 << V_74 -> V_82 ) ;
V_48 [ V_74 -> V_82 ] = V_50 ;
V_52 = 1 ;
}
if ( V_51 < 0 )
return V_51 ;
V_50 ++ ;
}
} while ( V_52 );
if ( ! V_35 -> V_56 ) {
V_40 = F_19 ( V_35 , V_55 ) ;
if ( F_24 ( V_40 ) )
V_35 -> V_56 = F_25 ( V_40 ) ;
}
if ( ! V_35 -> V_59 ) {
V_40 = F_19 ( V_35 , V_57 ) ;
if ( F_24 ( V_40 ) ) {
V_35 -> V_58 = F_25 ( V_40 ) ;
V_35 -> V_59 = 1 ;
}
}
V_38 = & V_3 -> V_6 -> V_38 ;
if ( ! V_35 -> V_4 )
V_35 -> V_4 = V_38 -> V_4 & ~ V_83 ;
if ( ! V_35 -> V_53 ) {
V_42 = F_13 ( V_35 , V_84 ) ;
V_40 = F_19 ( V_35 , V_85 ) ;
if ( F_26 ( V_42 ) == F_27 ( V_42 ) &&
F_28 ( V_40 ) == F_29 ( V_40 ) ) {
V_51 = V_3 -> V_26 -> V_27 ( V_3 ,
V_86 , V_35 ) ;
if ( V_51 < 0 )
return V_51 ;
}
}
V_35 -> V_54 = 0 ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 ,
struct V_34 T_2 * V_87 )
{
struct V_34 * V_35 ;
int V_30 ;
V_35 = F_31 ( V_87 , sizeof( * V_35 ) ) ;
if ( F_32 ( V_35 ) )
return F_33 ( V_35 ) ;
V_30 = F_12 ( V_3 , V_35 ) ;
if ( F_10 ( V_87 , V_35 , sizeof( * V_35 ) ) ) {
if ( ! V_30 )
V_30 = - V_33 ;
}
F_11 ( V_35 ) ;
return V_30 ;
}
static int F_34 ( struct V_5 * V_6 )
{
int V_88 ;
if ( ! V_6 -> V_89 )
return - 1 ;
V_88 = ( 750000 / V_6 -> V_89 ) * V_6 -> V_90 ;
V_88 += ( ( 750000 % V_6 -> V_89 ) * V_6 -> V_90 ) /
V_6 -> V_89 ;
return V_88 ;
}
static void F_35 ( struct V_2 * V_3 , int V_91 )
{
F_36 ( V_3 ) ;
if ( V_3 -> V_6 -> V_92 -> V_91 != V_93 )
V_3 -> V_6 -> V_92 -> V_91 = V_91 ;
F_37 ( V_3 ) ;
}
static int V_34 ( struct V_2 * V_3 ,
struct V_34 * V_35 )
{
struct V_5 * V_6 ;
int V_30 , V_88 ;
unsigned int V_65 ;
T_3 V_94 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_96 :
case V_97 :
case V_98 :
break;
default:
F_37 ( V_3 ) ;
return - V_99 ;
}
F_37 ( V_3 ) ;
#if F_39 ( V_100 ) || F_39 ( V_101 )
if ( ! V_3 -> V_102 . V_102 )
#endif
if ( F_40 ( & V_3 -> V_103 ) )
return - V_99 ;
V_35 -> V_54 = ~ 0U ;
V_30 = F_12 ( V_3 , V_35 ) ;
if ( V_30 < 0 )
goto V_104;
V_30 = F_41 ( V_3 , V_35 ) ;
if ( V_30 < 0 )
goto V_104;
if ( V_3 -> V_26 -> V_105 != NULL ) {
V_30 = V_3 -> V_26 -> V_105 ( V_3 , V_35 ) ;
if ( V_30 < 0 )
goto V_104;
}
V_6 -> V_106 = F_42 ( V_35 ) ;
V_6 -> V_107 = F_43 ( V_35 ) ;
V_6 -> V_108 = F_44 ( V_35 ) ;
V_6 -> V_109 = F_45 ( V_35 ) ;
V_6 -> V_89 = F_46 ( V_35 ) ;
V_6 -> V_90 = F_47 ( V_35 ) ;
V_6 -> V_110 = F_48 ( V_35 ) ;
V_6 -> V_111 = F_49 ( V_35 ) ;
V_6 -> V_4 = V_35 -> V_4 ;
V_6 -> V_58 = V_35 -> V_58 ;
V_6 -> V_59 = V_35 -> V_59 ;
V_6 -> V_112 =
( V_35 -> V_4 & V_113 ) &&
( V_35 -> V_79 & V_114 ) ;
V_65 = F_50 ( V_6 -> V_107 ) ;
V_6 -> V_115 = V_65 ;
V_65 *= V_6 -> V_109 ;
V_6 -> V_116 = V_65 ;
V_94 = 1 ;
while ( V_65 % 8 != 0 ) {
V_65 *= 2 ;
V_94 *= 2 ;
}
V_6 -> V_117 = V_65 / 8 ;
V_6 -> V_118 = V_94 ;
V_6 -> V_119 = V_120 ;
V_6 -> V_121 = 1 ;
V_6 -> V_122 -> V_123 = V_6 -> V_90 ;
V_6 -> V_124 = 1 ;
V_6 -> V_125 = V_6 -> V_111 ;
V_6 -> V_126 = 0 ;
V_6 -> V_127 = 0 ;
V_6 -> V_128 = V_6 -> V_111 ;
while ( V_6 -> V_128 * 2 <= V_129 - V_6 -> V_111 )
V_6 -> V_128 *= 2 ;
F_51 ( V_3 ) ;
F_35 ( V_3 , V_97 ) ;
if ( F_52 ( & V_3 -> V_130 ) )
F_53 ( & V_3 -> V_130 ) ;
if ( ( V_88 = F_34 ( V_6 ) ) >= 0 )
F_54 ( & V_3 -> V_130 ,
V_131 , V_88 ) ;
return 0 ;
V_104:
F_35 ( V_3 , V_96 ) ;
if ( V_3 -> V_26 -> V_132 != NULL )
V_3 -> V_26 -> V_132 ( V_3 ) ;
return V_30 ;
}
static int F_55 ( struct V_2 * V_3 ,
struct V_34 T_2 * V_87 )
{
struct V_34 * V_35 ;
int V_30 ;
V_35 = F_31 ( V_87 , sizeof( * V_35 ) ) ;
if ( F_32 ( V_35 ) )
return F_33 ( V_35 ) ;
V_30 = V_34 ( V_3 , V_35 ) ;
if ( F_10 ( V_87 , V_35 , sizeof( * V_35 ) ) ) {
if ( ! V_30 )
V_30 = - V_33 ;
}
F_11 ( V_35 ) ;
return V_30 ;
}
static int F_56 ( struct V_2 * V_3 )
{
struct V_5 * V_6 ;
int V_133 = 0 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_97 :
case V_98 :
break;
default:
F_37 ( V_3 ) ;
return - V_99 ;
}
F_37 ( V_3 ) ;
if ( F_40 ( & V_3 -> V_103 ) )
return - V_99 ;
if ( V_3 -> V_26 -> V_132 )
V_133 = V_3 -> V_26 -> V_132 ( V_3 ) ;
F_35 ( V_3 , V_96 ) ;
F_53 ( & V_3 -> V_130 ) ;
return V_133 ;
}
static int F_57 ( struct V_2 * V_3 ,
struct F_57 * V_35 )
{
struct V_5 * V_6 ;
int V_30 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
F_36 ( V_3 ) ;
if ( V_6 -> V_92 -> V_91 == V_96 ) {
F_37 ( V_3 ) ;
return - V_99 ;
}
F_37 ( V_3 ) ;
if ( V_35 -> V_119 > V_134 )
return - V_62 ;
if ( V_35 -> V_123 == 0 )
return - V_62 ;
if ( V_35 -> V_127 >= V_6 -> V_128 ) {
if ( V_35 -> V_126 != 0 )
return - V_62 ;
} else {
if ( V_35 -> V_127 > V_35 -> V_126 )
return - V_62 ;
if ( V_35 -> V_126 > V_6 -> V_111 )
return - V_62 ;
}
V_30 = 0 ;
F_36 ( V_3 ) ;
V_6 -> V_119 = V_35 -> V_119 ;
V_6 -> V_121 = V_35 -> V_121 ;
V_6 -> V_122 -> V_123 = V_35 -> V_123 ;
V_6 -> V_124 = V_35 -> V_124 ;
V_6 -> V_125 = V_35 -> V_125 ;
V_6 -> V_126 = V_35 -> V_126 ;
V_6 -> V_127 = V_35 -> V_127 ;
V_35 -> V_128 = V_6 -> V_128 ;
if ( F_58 ( V_3 ) ) {
if ( V_3 -> V_14 == V_135 &&
V_6 -> V_127 > 0 )
F_59 ( V_3 , V_136 ) ;
V_30 = F_60 ( V_3 , V_6 ) ;
}
F_37 ( V_3 ) ;
return V_30 ;
}
static int F_61 ( struct V_2 * V_3 ,
struct F_57 T_2 * V_87 )
{
struct F_57 V_35 ;
int V_30 ;
if ( F_62 ( & V_35 , V_87 , sizeof( V_35 ) ) )
return - V_33 ;
V_30 = F_57 ( V_3 , & V_35 ) ;
if ( F_10 ( V_87 , & V_35 , sizeof( V_35 ) ) )
return - V_33 ;
return V_30 ;
}
int F_63 ( struct V_2 * V_3 ,
struct F_63 * V_92 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_36 ( V_3 ) ;
V_92 -> V_91 = V_6 -> V_92 -> V_91 ;
V_92 -> V_137 = V_6 -> V_92 -> V_137 ;
if ( V_92 -> V_91 == V_96 )
goto V_138;
V_92 -> V_139 = V_6 -> V_139 ;
if ( F_58 ( V_3 ) ) {
F_64 ( V_3 ) ;
if ( V_6 -> V_119 == V_140 ) {
V_92 -> V_141 = V_6 -> V_92 -> V_141 ;
goto V_142;
}
}
F_65 ( V_6 , & V_92 -> V_141 ) ;
V_142:
V_92 -> V_143 = V_6 -> V_122 -> V_143 ;
V_92 -> V_144 = V_6 -> V_92 -> V_144 ;
if ( V_3 -> V_14 == V_135 ) {
V_92 -> V_145 = F_66 ( V_6 ) ;
if ( V_6 -> V_92 -> V_91 == V_146 ||
V_6 -> V_92 -> V_91 == V_147 ) {
V_92 -> V_148 = V_6 -> V_111 - V_92 -> V_145 ;
V_92 -> V_148 += V_6 -> V_148 ;
} else
V_92 -> V_148 = 0 ;
} else {
V_92 -> V_145 = F_67 ( V_6 ) ;
if ( V_6 -> V_92 -> V_91 == V_146 )
V_92 -> V_148 = V_92 -> V_145 + V_6 -> V_148 ;
else
V_92 -> V_148 = 0 ;
}
V_92 -> V_149 = V_6 -> V_149 ;
V_92 -> V_150 = V_6 -> V_150 ;
V_6 -> V_149 = 0 ;
V_6 -> V_150 = 0 ;
V_138:
F_37 ( V_3 ) ;
return 0 ;
}
static int F_68 ( struct V_2 * V_3 ,
struct F_63 T_2 * V_151 )
{
struct F_63 V_92 ;
int V_152 ;
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
V_152 = F_63 ( V_3 , & V_92 ) ;
if ( V_152 < 0 )
return V_152 ;
if ( F_10 ( V_151 , & V_92 , sizeof( V_92 ) ) )
return - V_33 ;
return 0 ;
}
static int F_69 ( struct V_2 * V_3 ,
struct F_69 * V_4 )
{
struct V_5 * V_6 ;
unsigned int V_153 ;
V_153 = V_4 -> V_153 ;
V_6 = V_3 -> V_6 ;
F_36 ( V_3 ) ;
if ( V_6 -> V_92 -> V_91 == V_96 ) {
F_37 ( V_3 ) ;
return - V_99 ;
}
F_37 ( V_3 ) ;
if ( V_153 >= V_6 -> V_109 )
return - V_62 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_153 = V_153 ;
return V_3 -> V_26 -> V_27 ( V_3 , V_154 , V_4 ) ;
}
static int F_70 ( struct V_2 * V_3 ,
struct F_69 T_2 * V_29 )
{
struct F_69 V_4 ;
int V_152 ;
if ( F_62 ( & V_4 , V_29 , sizeof( V_4 ) ) )
return - V_33 ;
V_152 = F_69 ( V_3 , & V_4 ) ;
if ( V_152 < 0 )
return V_152 ;
if ( F_10 ( V_29 , & V_4 , sizeof( V_4 ) ) )
return - V_33 ;
return 0 ;
}
static void F_71 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_155 == NULL )
return;
if ( V_6 -> V_155 == V_3 ) {
F_65 ( V_6 , & V_6 -> V_139 ) ;
} else {
F_71 ( V_6 -> V_155 ) ;
V_6 -> V_139 = V_6 -> V_155 -> V_6 -> V_139 ;
}
V_6 -> V_155 = NULL ;
}
static int F_72 ( struct V_156 * V_26 ,
struct V_2 * V_3 ,
int V_91 , int V_157 )
{
struct V_2 * V_158 = NULL ;
struct V_2 * V_159 ;
int V_152 = 0 ;
F_73 (s, substream) {
if ( V_157 && V_158 != V_3 )
F_74 ( & V_158 -> V_160 . V_161 ,
V_162 ) ;
V_152 = V_26 -> V_163 ( V_158 , V_91 ) ;
if ( V_152 < 0 )
goto V_164;
}
F_73 (s, substream) {
V_152 = V_26 -> V_165 ( V_158 , V_91 ) ;
if ( V_152 < 0 ) {
if ( V_26 -> V_166 ) {
F_73 (s1, substream) {
if ( V_159 == V_158 )
break;
V_26 -> V_166 ( V_159 , V_91 ) ;
}
}
V_158 = NULL ;
goto V_164;
}
}
F_73 (s, substream) {
V_26 -> V_167 ( V_158 , V_91 ) ;
}
V_164:
if ( V_157 ) {
F_73 (s1, substream) {
if ( V_159 != V_3 )
F_75 ( & V_159 -> V_160 . V_161 ) ;
if ( V_159 == V_158 )
break;
}
}
return V_152 ;
}
static int F_76 ( struct V_156 * V_26 ,
struct V_2 * V_3 ,
int V_91 )
{
int V_152 ;
V_152 = V_26 -> V_163 ( V_3 , V_91 ) ;
if ( V_152 < 0 )
return V_152 ;
V_152 = V_26 -> V_165 ( V_3 , V_91 ) ;
if ( V_152 == 0 )
V_26 -> V_167 ( V_3 , V_91 ) ;
else if ( V_26 -> V_166 )
V_26 -> V_166 ( V_3 , V_91 ) ;
return V_152 ;
}
static int F_77 ( struct V_156 * V_26 ,
struct V_2 * V_3 ,
int V_91 )
{
int V_152 ;
if ( F_78 ( V_3 ) ) {
if ( ! F_79 ( & V_3 -> V_168 -> V_161 ) ) {
F_75 ( & V_3 -> V_160 . V_161 ) ;
F_80 ( & V_3 -> V_168 -> V_161 ) ;
F_80 ( & V_3 -> V_160 . V_161 ) ;
}
V_152 = F_72 ( V_26 , V_3 , V_91 , 1 ) ;
F_75 ( & V_3 -> V_168 -> V_161 ) ;
} else {
V_152 = F_76 ( V_26 , V_3 , V_91 ) ;
}
return V_152 ;
}
static int F_81 ( struct V_156 * V_26 ,
struct V_2 * V_3 ,
int V_91 )
{
int V_152 ;
F_82 ( & V_169 ) ;
if ( F_78 ( V_3 ) ) {
F_80 ( & V_3 -> V_168 -> V_161 ) ;
F_80 ( & V_3 -> V_160 . V_161 ) ;
V_152 = F_72 ( V_26 , V_3 , V_91 , 1 ) ;
F_75 ( & V_3 -> V_160 . V_161 ) ;
F_75 ( & V_3 -> V_168 -> V_161 ) ;
} else {
F_80 ( & V_3 -> V_160 . V_161 ) ;
V_152 = F_76 ( V_26 , V_3 , V_91 ) ;
F_75 ( & V_3 -> V_160 . V_161 ) ;
}
F_83 ( & V_169 ) ;
return V_152 ;
}
static int F_84 ( struct V_156 * V_26 ,
struct V_2 * V_3 ,
int V_91 )
{
int V_152 ;
F_85 ( & V_170 ) ;
if ( F_78 ( V_3 ) )
V_152 = F_72 ( V_26 , V_3 , V_91 , 0 ) ;
else
V_152 = F_76 ( V_26 , V_3 , V_91 ) ;
F_86 ( & V_170 ) ;
return V_152 ;
}
static int F_87 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 != V_98 )
return - V_99 ;
if ( V_3 -> V_14 == V_135 &&
! F_88 ( V_3 ) )
return - V_171 ;
V_6 -> V_155 = V_3 ;
return 0 ;
}
static int F_89 ( struct V_2 * V_3 , int V_91 )
{
if ( V_3 -> V_6 -> V_155 != V_3 )
return 0 ;
return V_3 -> V_26 -> V_172 ( V_3 , V_173 ) ;
}
static void F_90 ( struct V_2 * V_3 , int V_91 )
{
if ( V_3 -> V_6 -> V_155 == V_3 )
V_3 -> V_26 -> V_172 ( V_3 , V_174 ) ;
}
static void F_91 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_71 ( V_3 ) ;
V_6 -> V_175 = V_176 ;
V_6 -> V_177 = ( V_6 -> V_111 * V_178 ) /
V_6 -> V_89 ;
V_6 -> V_92 -> V_91 = V_91 ;
if ( V_3 -> V_14 == V_135 &&
V_6 -> V_127 > 0 )
F_59 ( V_3 , V_136 ) ;
if ( V_3 -> V_179 )
F_92 ( V_3 -> V_179 , V_180 ,
& V_6 -> V_139 ) ;
}
int F_93 ( struct V_2 * V_3 )
{
return F_77 ( & V_181 , V_3 ,
V_146 ) ;
}
static int F_94 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
V_6 -> V_155 = V_3 ;
return 0 ;
}
static int F_95 ( struct V_2 * V_3 , int V_91 )
{
if ( V_3 -> V_6 -> V_155 == V_3 &&
F_58 ( V_3 ) )
V_3 -> V_26 -> V_172 ( V_3 , V_174 ) ;
return 0 ;
}
static void F_96 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 != V_91 ) {
F_71 ( V_3 ) ;
if ( V_3 -> V_179 )
F_92 ( V_3 -> V_179 , V_182 ,
& V_6 -> V_139 ) ;
V_6 -> V_92 -> V_91 = V_91 ;
}
F_97 ( & V_6 -> V_183 ) ;
F_97 ( & V_6 -> V_184 ) ;
}
int F_98 ( struct V_2 * V_3 , T_4 V_91 )
{
return F_77 ( & V_185 , V_3 , V_91 ) ;
}
int F_99 ( struct V_2 * V_3 )
{
return F_76 ( & V_185 , V_3 ,
V_97 ) ;
}
static int F_100 ( struct V_2 * V_3 , int V_186 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( ! ( V_6 -> V_4 & V_187 ) )
return - V_188 ;
if ( V_186 ) {
if ( V_6 -> V_92 -> V_91 != V_146 )
return - V_99 ;
} else if ( V_6 -> V_92 -> V_91 != V_189 )
return - V_99 ;
V_6 -> V_155 = V_3 ;
return 0 ;
}
static int F_101 ( struct V_2 * V_3 , int V_186 )
{
if ( V_3 -> V_6 -> V_155 != V_3 )
return 0 ;
if ( V_186 )
F_64 ( V_3 ) ;
V_3 -> V_6 -> V_175 = V_176 - V_178 * 1000 ;
return V_3 -> V_26 -> V_172 ( V_3 ,
V_186 ? V_190 :
V_191 ) ;
}
static void F_102 ( struct V_2 * V_3 , int V_186 )
{
if ( V_3 -> V_6 -> V_155 == V_3 )
V_3 -> V_26 -> V_172 ( V_3 ,
V_186 ? V_191 :
V_190 ) ;
}
static void F_103 ( struct V_2 * V_3 , int V_186 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_71 ( V_3 ) ;
if ( V_186 ) {
V_6 -> V_92 -> V_91 = V_189 ;
if ( V_3 -> V_179 )
F_92 ( V_3 -> V_179 ,
V_192 ,
& V_6 -> V_139 ) ;
F_97 ( & V_6 -> V_183 ) ;
F_97 ( & V_6 -> V_184 ) ;
} else {
V_6 -> V_92 -> V_91 = V_146 ;
if ( V_3 -> V_179 )
F_92 ( V_3 -> V_179 ,
V_193 ,
& V_6 -> V_139 ) ;
}
}
static int F_104 ( struct V_2 * V_3 , int V_186 )
{
return F_77 ( & V_194 , V_3 , V_186 ) ;
}
static int F_105 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_195 )
return - V_196 ;
V_6 -> V_155 = V_3 ;
return 0 ;
}
static int F_106 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_155 != V_3 )
return 0 ;
if ( ! F_58 ( V_3 ) )
return 0 ;
V_3 -> V_26 -> V_172 ( V_3 , V_197 ) ;
return 0 ;
}
static void F_107 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_71 ( V_3 ) ;
if ( V_3 -> V_179 )
F_92 ( V_3 -> V_179 , V_198 ,
& V_6 -> V_139 ) ;
V_6 -> V_92 -> V_137 = V_6 -> V_92 -> V_91 ;
V_6 -> V_92 -> V_91 = V_195 ;
F_97 ( & V_6 -> V_183 ) ;
F_97 ( & V_6 -> V_184 ) ;
}
int F_108 ( struct V_2 * V_3 )
{
int V_30 ;
unsigned long V_79 ;
if ( ! V_3 )
return 0 ;
F_109 ( V_3 , V_79 ) ;
V_30 = F_77 ( & V_199 , V_3 , 0 ) ;
F_110 ( V_3 , V_79 ) ;
return V_30 ;
}
int F_111 ( struct V_7 * V_8 )
{
struct V_2 * V_3 ;
int V_14 , V_30 = 0 ;
if ( ! V_8 )
return 0 ;
for ( V_14 = 0 ; V_14 < 2 ; V_14 ++ ) {
for ( V_3 = V_8 -> V_200 [ V_14 ] . V_3 ;
V_3 ; V_3 = V_3 -> V_201 ) {
if ( V_3 -> V_6 == NULL )
continue;
V_30 = F_108 ( V_3 ) ;
if ( V_30 < 0 && V_30 != - V_196 )
return V_30 ;
}
}
return 0 ;
}
static int F_112 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( ! ( V_6 -> V_4 & V_202 ) )
return - V_188 ;
V_6 -> V_155 = V_3 ;
return 0 ;
}
static int F_113 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_155 != V_3 )
return 0 ;
if ( V_6 -> V_92 -> V_137 != V_146 &&
( V_6 -> V_92 -> V_137 != V_147 ||
V_3 -> V_14 != V_135 ) )
return 0 ;
return V_3 -> V_26 -> V_172 ( V_3 , V_203 ) ;
}
static void F_114 ( struct V_2 * V_3 , int V_91 )
{
if ( V_3 -> V_6 -> V_155 == V_3 &&
F_58 ( V_3 ) )
V_3 -> V_26 -> V_172 ( V_3 , V_197 ) ;
}
static void F_115 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_71 ( V_3 ) ;
if ( V_3 -> V_179 )
F_92 ( V_3 -> V_179 , V_204 ,
& V_6 -> V_139 ) ;
V_6 -> V_92 -> V_91 = V_6 -> V_92 -> V_137 ;
}
static int F_116 ( struct V_2 * V_3 )
{
struct V_205 * V_11 = V_3 -> V_8 -> V_11 ;
int V_152 ;
F_117 ( V_11 ) ;
if ( ( V_152 = F_118 ( V_11 , V_206 ) ) >= 0 )
V_152 = F_81 ( & V_207 , V_3 , 0 ) ;
F_119 ( V_11 ) ;
return V_152 ;
}
static int F_116 ( struct V_2 * V_3 )
{
return - V_188 ;
}
static int F_120 ( struct V_2 * V_3 )
{
struct V_205 * V_11 = V_3 -> V_8 -> V_11 ;
struct V_5 * V_6 = V_3 -> V_6 ;
int V_133 ;
F_117 ( V_11 ) ;
if ( V_6 -> V_92 -> V_91 == V_195 ) {
V_133 = F_118 ( V_11 , V_206 ) ;
if ( V_133 < 0 )
goto V_164;
}
F_36 ( V_3 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_208 :
V_133 = 0 ;
break;
case V_146 :
V_133 = F_98 ( V_3 , V_208 ) ;
break;
default:
V_133 = - V_99 ;
}
F_37 ( V_3 ) ;
V_164:
F_119 ( V_11 ) ;
return V_133 ;
}
static int F_121 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_146 :
case V_98 :
case V_189 :
case V_195 :
return 0 ;
default:
return - V_99 ;
}
}
static int F_122 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_30 = V_3 -> V_26 -> V_27 ( V_3 , V_209 , NULL ) ;
if ( V_30 < 0 )
return V_30 ;
V_6 -> V_210 = 0 ;
V_6 -> V_211 = V_6 -> V_92 -> V_144 -
V_6 -> V_92 -> V_144 % V_6 -> V_90 ;
V_6 -> V_212 = V_6 -> V_92 -> V_144 ;
V_6 -> V_213 = 0 ;
return 0 ;
}
static void F_123 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
V_6 -> V_122 -> V_143 = V_6 -> V_92 -> V_144 ;
if ( V_3 -> V_14 == V_135 &&
V_6 -> V_127 > 0 )
F_59 ( V_3 , V_136 ) ;
}
static int F_124 ( struct V_2 * V_3 )
{
return F_84 ( & V_214 , V_3 , 0 ) ;
}
static int F_125 ( struct V_2 * V_3 ,
int V_215 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 ||
V_6 -> V_92 -> V_91 == V_93 )
return - V_99 ;
if ( F_58 ( V_3 ) )
return - V_196 ;
V_3 -> V_215 = V_215 ;
return 0 ;
}
static int F_126 ( struct V_2 * V_3 , int V_91 )
{
int V_30 ;
V_30 = V_3 -> V_26 -> V_216 ( V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
return F_122 ( V_3 , 0 ) ;
}
static void F_127 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
V_6 -> V_122 -> V_143 = V_6 -> V_92 -> V_144 ;
F_35 ( V_3 , V_98 ) ;
}
static int F_128 ( struct V_2 * V_3 ,
struct V_217 * V_217 )
{
int V_152 ;
struct V_205 * V_11 = V_3 -> V_8 -> V_11 ;
int V_215 ;
if ( V_217 )
V_215 = V_217 -> V_215 ;
else
V_215 = V_3 -> V_215 ;
F_117 ( V_11 ) ;
if ( ( V_152 = F_118 ( V_11 , V_206 ) ) >= 0 )
V_152 = F_84 ( & V_218 ,
V_3 , V_215 ) ;
F_119 ( V_11 ) ;
return V_152 ;
}
static int F_129 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_96 :
case V_93 :
case V_195 :
return - V_99 ;
}
V_6 -> V_155 = V_3 ;
return 0 ;
}
static int F_130 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_3 -> V_14 == V_135 ) {
switch ( V_6 -> V_92 -> V_91 ) {
case V_98 :
if ( ! F_131 ( V_3 ) ) {
F_89 ( V_3 , V_147 ) ;
F_91 ( V_3 , V_147 ) ;
}
break;
case V_146 :
V_6 -> V_92 -> V_91 = V_147 ;
break;
case V_208 :
V_6 -> V_92 -> V_91 = V_97 ;
break;
default:
break;
}
} else {
if ( V_6 -> V_92 -> V_91 == V_146 ) {
int V_219 = F_67 ( V_6 ) > 0 ?
V_147 : V_97 ;
F_95 ( V_3 , V_219 ) ;
F_96 ( V_3 , V_219 ) ;
}
}
return 0 ;
}
static void F_132 ( struct V_2 * V_3 , int V_91 )
{
}
static int F_133 ( struct V_2 * V_3 ,
struct V_217 * V_217 )
{
struct V_205 * V_11 ;
struct V_5 * V_6 ;
struct V_2 * V_158 ;
T_5 V_220 ;
int V_133 = 0 ;
int V_221 = 0 ;
V_11 = V_3 -> V_8 -> V_11 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
F_117 ( V_11 ) ;
if ( V_6 -> V_92 -> V_91 == V_195 ) {
V_133 = F_118 ( V_11 , V_206 ) ;
if ( V_133 < 0 ) {
F_119 ( V_11 ) ;
return V_133 ;
}
}
if ( V_217 ) {
if ( V_217 -> V_215 & V_222 )
V_221 = 1 ;
} else if ( V_3 -> V_215 & V_222 )
V_221 = 1 ;
F_85 ( & V_170 ) ;
F_36 ( V_3 ) ;
if ( V_6 -> V_92 -> V_91 == V_189 )
F_104 ( V_3 , 0 ) ;
V_133 = F_77 ( & V_223 , V_3 , 0 ) ;
if ( V_133 < 0 )
goto V_224;
if ( V_221 ) {
V_133 = - V_225 ;
goto V_224;
}
for (; ; ) {
long V_226 ;
struct V_5 * V_227 ;
if ( F_134 ( V_228 ) ) {
V_133 = - V_229 ;
break;
}
V_227 = NULL ;
F_73 (s, substream) {
if ( V_158 -> V_14 != V_135 )
continue;
V_6 = V_158 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_147 ) {
V_227 = V_6 ;
break;
}
}
if ( ! V_227 )
break;
F_135 ( & V_220 , V_228 ) ;
F_136 ( & V_227 -> V_183 , & V_220 ) ;
F_37 ( V_3 ) ;
F_86 ( & V_170 ) ;
F_119 ( V_11 ) ;
if ( V_6 -> V_112 )
V_226 = V_230 ;
else {
V_226 = 10 ;
if ( V_6 -> V_89 ) {
long V_231 = V_6 -> V_90 * 2 / V_6 -> V_89 ;
V_226 = V_71 ( V_231 , V_226 ) ;
}
V_226 = F_137 ( V_226 * 1000 ) ;
}
V_226 = F_138 ( V_226 ) ;
F_117 ( V_11 ) ;
F_85 ( & V_170 ) ;
F_36 ( V_3 ) ;
F_139 ( & V_227 -> V_183 , & V_220 ) ;
if ( V_11 -> V_232 ) {
V_133 = - V_233 ;
break;
}
if ( V_226 == 0 ) {
if ( V_3 -> V_6 -> V_92 -> V_91 == V_195 )
V_133 = - V_234 ;
else {
F_140 ( L_12 ) ;
F_98 ( V_3 , V_97 ) ;
V_133 = - V_235 ;
}
break;
}
}
V_224:
F_37 ( V_3 ) ;
F_86 ( & V_170 ) ;
F_119 ( V_11 ) ;
return V_133 ;
}
static int F_141 ( struct V_2 * V_3 )
{
struct V_5 * V_6 ;
int V_133 = 0 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 ||
V_6 -> V_92 -> V_91 == V_93 ||
V_6 -> V_92 -> V_91 == V_195 )
return - V_99 ;
F_36 ( V_3 ) ;
if ( V_6 -> V_92 -> V_91 == V_189 )
F_104 ( V_3 , 0 ) ;
F_98 ( V_3 , V_97 ) ;
F_37 ( V_3 ) ;
return V_133 ;
}
static struct V_217 * F_142 ( int V_236 , int * V_237 )
{
struct V_217 * V_217 ;
struct V_238 * V_238 ;
unsigned int V_239 ;
V_217 = F_143 ( V_236 , V_237 ) ;
if ( ! V_217 )
return NULL ;
V_238 = V_217 -> V_240 . V_241 -> V_242 ;
if ( ! F_144 ( V_238 -> V_243 ) ||
F_145 ( V_238 ) != V_244 ) {
F_146 ( V_217 , * V_237 ) ;
return NULL ;
}
V_239 = F_147 ( V_238 ) ;
if ( ! F_148 ( V_239 , V_245 ) &&
! F_148 ( V_239 , V_246 ) ) {
F_146 ( V_217 , * V_237 ) ;
return NULL ;
}
return V_217 ;
}
static int F_149 ( struct V_2 * V_3 , int V_236 )
{
int V_152 = 0 ;
struct V_217 * V_217 ;
struct V_247 * V_248 ;
struct V_2 * V_249 ;
struct V_250 * V_168 ;
int V_237 ;
V_217 = F_142 ( V_236 , & V_237 ) ;
if ( ! V_217 )
return - V_99 ;
V_248 = V_217 -> V_251 ;
V_249 = V_248 -> V_3 ;
V_168 = F_9 ( sizeof( * V_168 ) , V_31 ) ;
if ( ! V_168 ) {
V_152 = - V_32 ;
goto V_252;
}
F_150 ( & V_170 ) ;
F_151 ( & V_169 ) ;
if ( V_3 -> V_6 -> V_92 -> V_91 == V_96 ||
V_3 -> V_6 -> V_92 -> V_91 != V_249 -> V_6 -> V_92 -> V_91 ) {
V_152 = - V_99 ;
goto V_138;
}
if ( F_78 ( V_249 ) ) {
V_152 = - V_253 ;
goto V_138;
}
if ( ! F_78 ( V_3 ) ) {
V_3 -> V_168 = V_168 ;
F_152 ( & V_3 -> V_168 -> V_161 ) ;
F_153 ( & V_3 -> V_168 -> V_254 ) ;
F_154 ( & V_3 -> V_255 , & V_3 -> V_168 -> V_254 ) ;
V_3 -> V_168 -> V_256 = 1 ;
}
F_154 ( & V_249 -> V_255 , & V_3 -> V_168 -> V_254 ) ;
V_3 -> V_168 -> V_256 ++ ;
V_249 -> V_168 = V_3 -> V_168 ;
V_138:
F_155 ( & V_169 ) ;
F_156 ( & V_170 ) ;
V_252:
F_157 ( V_249 -> V_8 -> V_11 ) ;
F_146 ( V_217 , V_237 ) ;
if ( V_152 < 0 )
F_11 ( V_168 ) ;
return V_152 ;
}
static void F_158 ( struct V_2 * V_3 )
{
V_3 -> V_168 = & V_3 -> V_160 ;
F_153 ( & V_3 -> V_160 . V_254 ) ;
F_154 ( & V_3 -> V_255 , & V_3 -> V_160 . V_254 ) ;
}
static int F_159 ( struct V_2 * V_3 )
{
struct V_2 * V_158 ;
int V_152 = 0 ;
F_150 ( & V_170 ) ;
F_151 ( & V_169 ) ;
if ( ! F_78 ( V_3 ) ) {
V_152 = - V_253 ;
goto V_138;
}
F_160 ( & V_3 -> V_255 ) ;
V_3 -> V_168 -> V_256 -- ;
if ( V_3 -> V_168 -> V_256 == 1 ) {
F_73 (s, substream) {
F_158 ( V_158 ) ;
break;
}
F_11 ( V_3 -> V_168 ) ;
}
F_158 ( V_3 ) ;
V_138:
F_155 ( & V_169 ) ;
F_156 ( & V_170 ) ;
return V_152 ;
}
static int F_161 ( struct V_34 * V_35 ,
struct V_73 * V_257 )
{
struct V_39 V_231 ;
F_162 ( F_163 ( V_35 , V_257 -> V_80 [ 0 ] ) ,
F_163 ( V_35 , V_257 -> V_80 [ 1 ] ) , & V_231 ) ;
return F_21 ( F_19 ( V_35 , V_257 -> V_82 ) , & V_231 ) ;
}
static int F_164 ( struct V_34 * V_35 ,
struct V_73 * V_257 )
{
struct V_39 V_231 ;
F_165 ( F_163 ( V_35 , V_257 -> V_80 [ 0 ] ) ,
F_163 ( V_35 , V_257 -> V_80 [ 1 ] ) , & V_231 ) ;
return F_21 ( F_19 ( V_35 , V_257 -> V_82 ) , & V_231 ) ;
}
static int F_166 ( struct V_34 * V_35 ,
struct V_73 * V_257 )
{
struct V_39 V_231 ;
F_167 ( F_163 ( V_35 , V_257 -> V_80 [ 0 ] ) ,
F_163 ( V_35 , V_257 -> V_80 [ 1 ] ) ,
( unsigned long ) V_257 -> V_258 , & V_231 ) ;
return F_21 ( F_19 ( V_35 , V_257 -> V_82 ) , & V_231 ) ;
}
static int F_168 ( struct V_34 * V_35 ,
struct V_73 * V_257 )
{
struct V_39 V_231 ;
F_169 ( F_163 ( V_35 , V_257 -> V_80 [ 0 ] ) ,
( unsigned long ) V_257 -> V_258 ,
F_163 ( V_35 , V_257 -> V_80 [ 1 ] ) , & V_231 ) ;
return F_21 ( F_19 ( V_35 , V_257 -> V_82 ) , & V_231 ) ;
}
static int F_170 ( struct V_34 * V_35 ,
struct V_73 * V_257 )
{
unsigned int V_36 ;
struct V_39 * V_40 = F_19 ( V_35 , V_257 -> V_80 [ 0 ] ) ;
struct V_41 V_42 ;
struct V_41 * V_259 = F_13 ( V_35 , V_84 ) ;
F_171 ( & V_42 ) ;
for ( V_36 = 0 ; V_36 <= V_260 ; ++ V_36 ) {
int V_65 ;
if ( ! F_172 ( V_259 , V_36 ) )
continue;
V_65 = F_50 ( V_36 ) ;
if ( V_65 <= 0 )
continue;
if ( ( unsigned ) V_65 < V_40 -> V_70 || ( unsigned ) V_65 > V_40 -> V_71 )
F_173 ( & V_42 , V_36 ) ;
}
return F_17 ( V_259 , & V_42 ) ;
}
static int F_174 ( struct V_34 * V_35 ,
struct V_73 * V_257 )
{
struct V_39 V_231 ;
unsigned int V_36 ;
V_231 . V_70 = V_261 ;
V_231 . V_71 = 0 ;
V_231 . V_69 = 0 ;
V_231 . V_72 = 0 ;
for ( V_36 = 0 ; V_36 <= V_260 ; ++ V_36 ) {
int V_65 ;
if ( ! F_172 ( F_13 ( V_35 , V_84 ) , V_36 ) )
continue;
V_65 = F_50 ( V_36 ) ;
if ( V_65 <= 0 )
continue;
if ( V_231 . V_70 > ( unsigned ) V_65 )
V_231 . V_70 = V_65 ;
if ( V_231 . V_71 < ( unsigned ) V_65 )
V_231 . V_71 = V_65 ;
}
V_231 . integer = 1 ;
return F_21 ( F_19 ( V_35 , V_257 -> V_82 ) , & V_231 ) ;
}
static int F_175 ( struct V_34 * V_35 ,
struct V_73 * V_257 )
{
struct V_37 * V_38 = V_257 -> V_258 ;
return F_176 ( F_19 ( V_35 , V_257 -> V_82 ) ,
V_262 . V_256 ,
V_262 . V_263 , V_38 -> V_264 ) ;
}
static int F_177 ( struct V_34 * V_35 ,
struct V_73 * V_257 )
{
struct V_39 V_231 ;
struct V_2 * V_3 = V_257 -> V_258 ;
V_231 . V_70 = 0 ;
V_231 . V_71 = V_3 -> V_265 ;
V_231 . V_69 = 0 ;
V_231 . V_72 = 0 ;
V_231 . integer = 1 ;
return F_21 ( F_19 ( V_35 , V_257 -> V_82 ) , & V_231 ) ;
}
int F_178 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_43 * V_44 = & V_6 -> V_45 ;
int V_36 , V_30 ;
for ( V_36 = V_60 ; V_36 <= V_61 ; V_36 ++ ) {
F_171 ( F_18 ( V_44 , V_36 ) ) ;
}
for ( V_36 = V_67 ; V_36 <= V_49 ; V_36 ++ ) {
F_179 ( F_22 ( V_44 , V_36 ) ) ;
}
F_180 ( F_22 ( V_44 , V_85 ) ) ;
F_180 ( F_22 ( V_44 , V_266 ) ) ;
F_180 ( F_22 ( V_44 , V_267 ) ) ;
F_180 ( F_22 ( V_44 , V_55 ) ) ;
F_180 ( F_22 ( V_44 , V_268 ) ) ;
V_30 = F_181 ( V_6 , 0 , V_84 ,
F_170 , NULL ,
V_55 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_55 ,
F_174 , NULL ,
V_84 ,
V_55 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_55 ,
F_164 , NULL ,
V_268 , V_85 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_268 ,
F_161 , NULL ,
V_55 , V_85 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_268 ,
F_168 , ( void * ) 8 ,
V_269 , V_270 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_268 ,
F_168 , ( void * ) 8 ,
V_267 , V_266 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_85 ,
F_164 , NULL ,
V_268 , V_55 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_57 ,
F_168 , ( void * ) 1000000 ,
V_270 , V_271 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_57 ,
F_168 , ( void * ) 1000000 ,
V_266 , V_272 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_273 ,
F_164 , NULL ,
V_266 , V_270 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_270 ,
F_164 , NULL ,
V_266 , V_273 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_270 ,
F_168 , ( void * ) 8 ,
V_269 , V_268 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_270 ,
F_166 , ( void * ) 1000000 ,
V_271 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_266 ,
F_161 , NULL ,
V_270 , V_273 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_266 ,
F_168 , ( void * ) 8 ,
V_267 , V_268 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_266 ,
F_166 , ( void * ) 1000000 ,
V_272 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_269 ,
F_166 , ( void * ) 8 ,
V_270 , V_268 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_267 ,
F_166 , ( void * ) 8 ,
V_266 , V_268 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_271 ,
F_168 , ( void * ) 1000000 ,
V_270 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_272 ,
F_168 , ( void * ) 1000000 ,
V_266 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
return 0 ;
}
int F_182 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_37 * V_38 = & V_6 -> V_38 ;
int V_30 ;
unsigned int V_259 = 0 ;
if ( V_38 -> V_4 & V_274 )
V_259 |= 1 << V_275 ;
if ( V_38 -> V_4 & V_276 )
V_259 |= 1 << V_277 ;
if ( V_38 -> V_4 & V_278 ) {
if ( V_38 -> V_4 & V_274 )
V_259 |= 1 << V_279 ;
if ( V_38 -> V_4 & V_276 )
V_259 |= 1 << V_280 ;
if ( V_38 -> V_4 & V_281 )
V_259 |= 1 << V_282 ;
}
V_30 = F_183 ( V_6 , V_283 , V_259 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_184 ( V_6 , V_84 , V_38 -> V_284 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , V_285 , 1 << V_286 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_185 ( V_6 , V_85 ,
V_38 -> V_287 , V_38 -> V_288 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_185 ( V_6 , V_57 ,
V_38 -> V_289 , V_38 -> V_290 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_185 ( V_6 , V_269 ,
V_38 -> V_291 , V_38 -> V_292 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_185 ( V_6 , V_273 ,
V_38 -> V_293 , V_38 -> V_294 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_185 ( V_6 , V_267 ,
V_38 -> V_291 , V_38 -> V_265 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_267 ,
F_177 , V_3 ,
V_267 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_6 -> V_295 ) {
V_30 = F_185 ( V_6 , V_267 , 0 , V_6 -> V_295 ) ;
if ( V_30 < 0 )
return - V_62 ;
}
if ( ! ( V_38 -> V_264 & ( V_296 | V_297 ) ) ) {
V_30 = F_181 ( V_6 , 0 , V_57 ,
F_175 , V_38 ,
V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
}
F_186 ( V_6 , V_270 ) ;
return 0 ;
}
static void F_187 ( struct V_2 * V_3 )
{
F_159 ( V_3 ) ;
}
void F_188 ( struct V_2 * V_3 )
{
V_3 -> V_298 -- ;
if ( V_3 -> V_298 > 0 )
return;
F_141 ( V_3 ) ;
if ( V_3 -> V_299 ) {
if ( V_3 -> V_26 -> V_132 != NULL )
V_3 -> V_26 -> V_132 ( V_3 ) ;
V_3 -> V_26 -> V_300 ( V_3 ) ;
V_3 -> V_299 = 0 ;
}
if ( F_52 ( & V_3 -> V_130 ) )
F_53 ( & V_3 -> V_130 ) ;
if ( V_3 -> V_301 ) {
V_3 -> V_301 ( V_3 ) ;
V_3 -> V_301 = NULL ;
}
F_189 ( V_3 ) ;
}
int F_190 ( struct V_7 * V_8 , int V_14 ,
struct V_217 * V_217 ,
struct V_2 * * V_302 )
{
struct V_2 * V_3 ;
int V_30 ;
V_30 = F_191 ( V_8 , V_14 , V_217 , & V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_3 -> V_298 > 1 ) {
* V_302 = V_3 ;
return 0 ;
}
V_30 = F_178 ( V_3 ) ;
if ( V_30 < 0 ) {
F_140 ( L_13 ) ;
goto error;
}
if ( ( V_30 = V_3 -> V_26 -> V_303 ( V_3 ) ) < 0 )
goto error;
V_3 -> V_299 = 1 ;
V_30 = F_182 ( V_3 ) ;
if ( V_30 < 0 ) {
F_140 ( L_14 ) ;
goto error;
}
* V_302 = V_3 ;
return 0 ;
error:
F_188 ( V_3 ) ;
return V_30 ;
}
static int F_192 ( struct V_217 * V_217 ,
struct V_7 * V_8 ,
int V_14 )
{
struct V_247 * V_248 ;
struct V_2 * V_3 ;
int V_30 ;
V_30 = F_190 ( V_8 , V_14 , V_217 , & V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
V_248 = F_193 ( sizeof( * V_248 ) , V_31 ) ;
if ( V_248 == NULL ) {
F_188 ( V_3 ) ;
return - V_32 ;
}
V_248 -> V_3 = V_3 ;
if ( V_3 -> V_298 == 1 ) {
V_3 -> V_217 = V_248 ;
V_3 -> V_301 = F_187 ;
}
V_217 -> V_251 = V_248 ;
return 0 ;
}
static int F_194 ( struct V_238 * V_238 , struct V_217 * V_217 )
{
struct V_7 * V_8 ;
int V_30 = F_195 ( V_238 , V_217 ) ;
if ( V_30 < 0 )
return V_30 ;
V_8 = F_148 ( F_147 ( V_238 ) ,
V_245 ) ;
V_30 = F_196 ( V_217 , V_8 , V_135 ) ;
if ( V_8 )
F_157 ( V_8 -> V_11 ) ;
return V_30 ;
}
static int F_197 ( struct V_238 * V_238 , struct V_217 * V_217 )
{
struct V_7 * V_8 ;
int V_30 = F_195 ( V_238 , V_217 ) ;
if ( V_30 < 0 )
return V_30 ;
V_8 = F_148 ( F_147 ( V_238 ) ,
V_246 ) ;
V_30 = F_196 ( V_217 , V_8 , V_304 ) ;
if ( V_8 )
F_157 ( V_8 -> V_11 ) ;
return V_30 ;
}
static int F_196 ( struct V_217 * V_217 , struct V_7 * V_8 , int V_14 )
{
int V_30 ;
T_5 V_220 ;
if ( V_8 == NULL ) {
V_30 = - V_233 ;
goto V_305;
}
V_30 = F_198 ( V_8 -> V_11 , V_217 ) ;
if ( V_30 < 0 )
goto V_305;
if ( ! F_199 ( V_8 -> V_11 -> V_306 ) ) {
V_30 = - V_33 ;
goto V_307;
}
F_135 ( & V_220 , V_228 ) ;
F_136 ( & V_8 -> V_308 , & V_220 ) ;
F_200 ( & V_8 -> V_309 ) ;
while ( 1 ) {
V_30 = F_192 ( V_217 , V_8 , V_14 ) ;
if ( V_30 >= 0 )
break;
if ( V_30 == - V_225 ) {
if ( V_217 -> V_215 & V_222 ) {
V_30 = - V_196 ;
break;
}
} else
break;
F_201 ( V_310 ) ;
F_202 ( & V_8 -> V_309 ) ;
F_203 () ;
F_200 ( & V_8 -> V_309 ) ;
if ( V_8 -> V_11 -> V_232 ) {
V_30 = - V_233 ;
break;
}
if ( F_134 ( V_228 ) ) {
V_30 = - V_229 ;
break;
}
}
F_139 ( & V_8 -> V_308 , & V_220 ) ;
F_202 ( & V_8 -> V_309 ) ;
if ( V_30 < 0 )
goto V_311;
return V_30 ;
V_311:
F_204 ( V_8 -> V_11 -> V_306 ) ;
V_307:
F_205 ( V_8 -> V_11 , V_217 ) ;
V_305:
return V_30 ;
}
static int F_206 ( struct V_238 * V_238 , struct V_217 * V_217 )
{
struct V_7 * V_8 ;
struct V_2 * V_3 ;
struct V_247 * V_248 ;
V_248 = V_217 -> V_251 ;
V_3 = V_248 -> V_3 ;
if ( F_207 ( ! V_3 ) )
return - V_95 ;
V_8 = V_3 -> V_8 ;
F_200 ( & V_8 -> V_309 ) ;
F_188 ( V_3 ) ;
F_11 ( V_248 ) ;
F_202 ( & V_8 -> V_309 ) ;
F_97 ( & V_8 -> V_308 ) ;
F_204 ( V_8 -> V_11 -> V_306 ) ;
F_205 ( V_8 -> V_11 , V_217 ) ;
return 0 ;
}
static T_6 F_208 ( struct V_2 * V_3 ,
T_3 V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_143 ;
T_6 V_312 ;
T_6 V_313 ;
if ( V_94 == 0 )
return 0 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_98 :
break;
case V_147 :
case V_146 :
if ( F_64 ( V_3 ) >= 0 )
break;
case V_208 :
V_312 = - V_171 ;
goto V_314;
case V_195 :
V_312 = - V_234 ;
goto V_314;
default:
V_312 = - V_99 ;
goto V_314;
}
V_313 = F_209 ( V_6 ) ;
if ( V_313 <= 0 ) {
V_312 = 0 ;
goto V_314;
}
if ( V_94 > ( T_3 ) V_313 )
V_94 = V_313 ;
V_143 = V_6 -> V_122 -> V_143 - V_94 ;
if ( V_143 < 0 )
V_143 += V_6 -> V_128 ;
V_6 -> V_122 -> V_143 = V_143 ;
V_312 = V_94 ;
V_314:
F_37 ( V_3 ) ;
return V_312 ;
}
static T_6 F_210 ( struct V_2 * V_3 ,
T_3 V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_143 ;
T_6 V_312 ;
T_6 V_313 ;
if ( V_94 == 0 )
return 0 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_98 :
case V_147 :
break;
case V_146 :
if ( F_64 ( V_3 ) >= 0 )
break;
case V_208 :
V_312 = - V_171 ;
goto V_314;
case V_195 :
V_312 = - V_234 ;
goto V_314;
default:
V_312 = - V_99 ;
goto V_314;
}
V_313 = F_211 ( V_6 ) ;
if ( V_313 <= 0 ) {
V_312 = 0 ;
goto V_314;
}
if ( V_94 > ( T_3 ) V_313 )
V_94 = V_313 ;
V_143 = V_6 -> V_122 -> V_143 - V_94 ;
if ( V_143 < 0 )
V_143 += V_6 -> V_128 ;
V_6 -> V_122 -> V_143 = V_143 ;
V_312 = V_94 ;
V_314:
F_37 ( V_3 ) ;
return V_312 ;
}
static T_6 F_212 ( struct V_2 * V_3 ,
T_3 V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_143 ;
T_6 V_312 ;
T_6 V_145 ;
if ( V_94 == 0 )
return 0 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_98 :
case V_189 :
break;
case V_147 :
case V_146 :
if ( F_64 ( V_3 ) >= 0 )
break;
case V_208 :
V_312 = - V_171 ;
goto V_314;
case V_195 :
V_312 = - V_234 ;
goto V_314;
default:
V_312 = - V_99 ;
goto V_314;
}
V_145 = F_66 ( V_6 ) ;
if ( V_145 <= 0 ) {
V_312 = 0 ;
goto V_314;
}
if ( V_94 > ( T_3 ) V_145 )
V_94 = V_145 ;
V_143 = V_6 -> V_122 -> V_143 + V_94 ;
if ( V_143 >= ( T_6 ) V_6 -> V_128 )
V_143 -= V_6 -> V_128 ;
V_6 -> V_122 -> V_143 = V_143 ;
V_312 = V_94 ;
V_314:
F_37 ( V_3 ) ;
return V_312 ;
}
static T_6 F_213 ( struct V_2 * V_3 ,
T_3 V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_143 ;
T_6 V_312 ;
T_6 V_145 ;
if ( V_94 == 0 )
return 0 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_98 :
case V_147 :
case V_189 :
break;
case V_146 :
if ( F_64 ( V_3 ) >= 0 )
break;
case V_208 :
V_312 = - V_171 ;
goto V_314;
case V_195 :
V_312 = - V_234 ;
goto V_314;
default:
V_312 = - V_99 ;
goto V_314;
}
V_145 = F_67 ( V_6 ) ;
if ( V_145 <= 0 ) {
V_312 = 0 ;
goto V_314;
}
if ( V_94 > ( T_3 ) V_145 )
V_94 = V_145 ;
V_143 = V_6 -> V_122 -> V_143 + V_94 ;
if ( V_143 >= ( T_6 ) V_6 -> V_128 )
V_143 -= V_6 -> V_128 ;
V_6 -> V_122 -> V_143 = V_143 ;
V_312 = V_94 ;
V_314:
F_37 ( V_3 ) ;
return V_312 ;
}
static int F_214 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_30 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_147 :
if ( V_3 -> V_14 == V_304 )
goto V_315;
case V_146 :
if ( ( V_30 = F_64 ( V_3 ) ) < 0 )
break;
case V_98 :
case V_195 :
V_30 = 0 ;
break;
case V_208 :
V_30 = - V_171 ;
break;
default:
V_315:
V_30 = - V_99 ;
break;
}
F_37 ( V_3 ) ;
return V_30 ;
}
static int F_215 ( struct V_2 * V_3 ,
T_6 T_2 * V_152 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_30 ;
T_6 V_316 = 0 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_147 :
if ( V_3 -> V_14 == V_304 )
goto V_315;
case V_146 :
if ( ( V_30 = F_64 ( V_3 ) ) < 0 )
break;
case V_98 :
case V_195 :
V_30 = 0 ;
if ( V_3 -> V_14 == V_135 )
V_316 = F_209 ( V_6 ) ;
else
V_316 = F_67 ( V_6 ) ;
V_316 += V_6 -> V_148 ;
break;
case V_208 :
V_30 = - V_171 ;
break;
default:
V_315:
V_30 = - V_99 ;
break;
}
F_37 ( V_3 ) ;
if ( ! V_30 )
if ( F_216 ( V_316 , V_152 ) )
V_30 = - V_33 ;
return V_30 ;
}
static int F_217 ( struct V_2 * V_3 ,
struct F_217 T_2 * V_317 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct F_217 V_318 ;
volatile struct V_319 * V_92 ;
volatile struct V_320 * V_122 ;
int V_30 ;
memset ( & V_318 , 0 , sizeof( V_318 ) ) ;
if ( F_218 ( V_318 . V_79 , ( unsigned T_2 * ) & ( V_317 -> V_79 ) ) )
return - V_33 ;
if ( F_62 ( & V_318 . V_321 . V_122 , & ( V_317 -> V_321 . V_122 ) , sizeof( struct V_320 ) ) )
return - V_33 ;
V_92 = V_6 -> V_92 ;
V_122 = V_6 -> V_122 ;
if ( V_318 . V_79 & V_322 ) {
V_30 = F_214 ( V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
}
F_36 ( V_3 ) ;
if ( ! ( V_318 . V_79 & V_323 ) )
V_122 -> V_143 = V_318 . V_321 . V_122 . V_143 ;
else
V_318 . V_321 . V_122 . V_143 = V_122 -> V_143 ;
if ( ! ( V_318 . V_79 & V_324 ) )
V_122 -> V_123 = V_318 . V_321 . V_122 . V_123 ;
else
V_318 . V_321 . V_122 . V_123 = V_122 -> V_123 ;
V_318 . V_158 . V_92 . V_91 = V_92 -> V_91 ;
V_318 . V_158 . V_92 . V_144 = V_92 -> V_144 ;
V_318 . V_158 . V_92 . V_141 = V_92 -> V_141 ;
V_318 . V_158 . V_92 . V_137 = V_92 -> V_137 ;
F_37 ( V_3 ) ;
if ( F_10 ( V_317 , & V_318 , sizeof( V_318 ) ) )
return - V_33 ;
return 0 ;
}
static int F_219 ( struct V_2 * V_3 , int T_2 * V_325 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_326 ;
if ( F_218 ( V_326 , V_325 ) )
return - V_33 ;
if ( V_326 < 0 || V_326 > V_327 )
return - V_62 ;
V_6 -> V_328 = V_329 ;
if ( V_326 == V_330 )
V_6 -> V_328 = V_330 ;
return 0 ;
}
static int F_220 ( struct V_217 * V_217 ,
struct V_2 * V_3 ,
unsigned int V_331 , void T_2 * V_326 )
{
switch ( V_331 ) {
case V_332 :
return F_216 ( V_333 , ( int T_2 * ) V_326 ) ? - V_33 : 0 ;
case V_334 :
return F_8 ( V_3 , V_326 ) ;
case V_335 :
return 0 ;
case V_336 :
return F_219 ( V_3 , V_326 ) ;
case V_337 :
return F_30 ( V_3 , V_326 ) ;
case V_338 :
return F_55 ( V_3 , V_326 ) ;
case V_339 :
return F_56 ( V_3 ) ;
case V_340 :
return F_61 ( V_3 , V_326 ) ;
case V_341 :
return F_68 ( V_3 , V_326 ) ;
case V_342 :
return F_70 ( V_3 , V_326 ) ;
case V_343 :
return F_128 ( V_3 , V_217 ) ;
case V_344 :
return F_124 ( V_3 ) ;
case V_345 :
return F_81 ( & V_181 , V_3 , V_146 ) ;
case V_346 :
return F_149 ( V_3 , ( int ) ( unsigned long ) V_326 ) ;
case V_347 :
return F_159 ( V_3 ) ;
case V_348 :
return F_116 ( V_3 ) ;
case V_349 :
return F_120 ( V_3 ) ;
case V_350 :
return F_214 ( V_3 ) ;
case V_351 :
return F_215 ( V_3 , V_326 ) ;
case V_352 :
return F_217 ( V_3 , V_326 ) ;
#ifdef F_221
case V_353 :
return F_222 ( V_3 , V_326 ) ;
case V_354 :
return F_223 ( V_3 , V_326 ) ;
#endif
case V_355 :
return F_133 ( V_3 , V_217 ) ;
case V_356 :
return F_141 ( V_3 ) ;
case V_357 :
{
int V_152 ;
F_36 ( V_3 ) ;
V_152 = F_104 ( V_3 , ( int ) ( unsigned long ) V_326 ) ;
F_37 ( V_3 ) ;
return V_152 ;
}
}
F_140 ( L_15 , V_331 ) ;
return - V_358 ;
}
static int F_224 ( struct V_217 * V_217 ,
struct V_2 * V_3 ,
unsigned int V_331 , void T_2 * V_326 )
{
if ( F_207 ( ! V_3 ) )
return - V_95 ;
if ( F_207 ( V_3 -> V_14 != V_135 ) )
return - V_62 ;
switch ( V_331 ) {
case V_359 :
{
struct V_360 V_361 ;
struct V_360 T_2 * V_362 = V_326 ;
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_133 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( F_216 ( 0 , & V_362 -> V_133 ) )
return - V_33 ;
if ( F_62 ( & V_361 , V_362 , sizeof( V_361 ) ) )
return - V_33 ;
V_133 = F_225 ( V_3 , V_361 . V_363 , V_361 . V_94 ) ;
F_226 ( V_133 , & V_362 -> V_133 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
case V_364 :
{
struct V_365 V_366 ;
struct V_365 T_2 * V_367 = V_326 ;
struct V_5 * V_6 = V_3 -> V_6 ;
void T_2 * * V_368 ;
T_6 V_133 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( V_6 -> V_109 > 128 )
return - V_62 ;
if ( F_216 ( 0 , & V_367 -> V_133 ) )
return - V_33 ;
if ( F_62 ( & V_366 , V_367 , sizeof( V_366 ) ) )
return - V_33 ;
V_368 = F_31 ( V_366 . V_368 ,
sizeof( void * ) * V_6 -> V_109 ) ;
if ( F_32 ( V_368 ) )
return F_33 ( V_368 ) ;
V_133 = F_227 ( V_3 , V_368 , V_366 . V_94 ) ;
F_11 ( V_368 ) ;
F_226 ( V_133 , & V_367 -> V_133 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
case V_369 :
{
T_3 V_94 ;
T_3 T_2 * V_370 = V_326 ;
T_6 V_133 ;
if ( F_218 ( V_94 , V_370 ) )
return - V_33 ;
if ( F_216 ( 0 , V_370 ) )
return - V_33 ;
V_133 = F_208 ( V_3 , V_94 ) ;
F_226 ( V_133 , V_370 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
case V_371 :
{
T_3 V_94 ;
T_3 T_2 * V_370 = V_326 ;
T_6 V_133 ;
if ( F_218 ( V_94 , V_370 ) )
return - V_33 ;
if ( F_216 ( 0 , V_370 ) )
return - V_33 ;
V_133 = F_212 ( V_3 , V_94 ) ;
F_226 ( V_133 , V_370 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
}
return F_220 ( V_217 , V_3 , V_331 , V_326 ) ;
}
static int F_228 ( struct V_217 * V_217 ,
struct V_2 * V_3 ,
unsigned int V_331 , void T_2 * V_326 )
{
if ( F_207 ( ! V_3 ) )
return - V_95 ;
if ( F_207 ( V_3 -> V_14 != V_304 ) )
return - V_62 ;
switch ( V_331 ) {
case V_372 :
{
struct V_360 V_361 ;
struct V_360 T_2 * V_362 = V_326 ;
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_133 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( F_216 ( 0 , & V_362 -> V_133 ) )
return - V_33 ;
if ( F_62 ( & V_361 , V_362 , sizeof( V_361 ) ) )
return - V_33 ;
V_133 = F_229 ( V_3 , V_361 . V_363 , V_361 . V_94 ) ;
F_226 ( V_133 , & V_362 -> V_133 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
case V_373 :
{
struct V_365 V_366 ;
struct V_365 T_2 * V_367 = V_326 ;
struct V_5 * V_6 = V_3 -> V_6 ;
void * V_368 ;
T_6 V_133 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( V_6 -> V_109 > 128 )
return - V_62 ;
if ( F_216 ( 0 , & V_367 -> V_133 ) )
return - V_33 ;
if ( F_62 ( & V_366 , V_367 , sizeof( V_366 ) ) )
return - V_33 ;
V_368 = F_31 ( V_366 . V_368 ,
sizeof( void * ) * V_6 -> V_109 ) ;
if ( F_32 ( V_368 ) )
return F_33 ( V_368 ) ;
V_133 = F_230 ( V_3 , V_368 , V_366 . V_94 ) ;
F_11 ( V_368 ) ;
F_226 ( V_133 , & V_367 -> V_133 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
case V_369 :
{
T_3 V_94 ;
T_3 T_2 * V_370 = V_326 ;
T_6 V_133 ;
if ( F_218 ( V_94 , V_370 ) )
return - V_33 ;
if ( F_216 ( 0 , V_370 ) )
return - V_33 ;
V_133 = F_210 ( V_3 , V_94 ) ;
F_226 ( V_133 , V_370 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
case V_371 :
{
T_3 V_94 ;
T_3 T_2 * V_370 = V_326 ;
T_6 V_133 ;
if ( F_218 ( V_94 , V_370 ) )
return - V_33 ;
if ( F_216 ( 0 , V_370 ) )
return - V_33 ;
V_133 = F_213 ( V_3 , V_94 ) ;
F_226 ( V_133 , V_370 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
}
return F_220 ( V_217 , V_3 , V_331 , V_326 ) ;
}
static long F_231 ( struct V_217 * V_217 , unsigned int V_331 ,
unsigned long V_326 )
{
struct V_247 * V_248 ;
V_248 = V_217 -> V_251 ;
if ( ( ( V_331 >> 8 ) & 0xff ) != 'A' )
return - V_358 ;
return F_224 ( V_217 , V_248 -> V_3 , V_331 ,
( void T_2 * ) V_326 ) ;
}
static long F_232 ( struct V_217 * V_217 , unsigned int V_331 ,
unsigned long V_326 )
{
struct V_247 * V_248 ;
V_248 = V_217 -> V_251 ;
if ( ( ( V_331 >> 8 ) & 0xff ) != 'A' )
return - V_358 ;
return F_228 ( V_217 , V_248 -> V_3 , V_331 ,
( void T_2 * ) V_326 ) ;
}
int F_233 ( struct V_2 * V_3 ,
unsigned int V_331 , void * V_326 )
{
T_1 V_1 ;
int V_133 ;
V_1 = F_1 () ;
switch ( V_3 -> V_14 ) {
case V_135 :
V_133 = F_224 ( NULL , V_3 , V_331 ,
( void T_2 * ) V_326 ) ;
break;
case V_304 :
V_133 = F_228 ( NULL , V_3 , V_331 ,
( void T_2 * ) V_326 ) ;
break;
default:
V_133 = - V_62 ;
break;
}
F_5 ( V_1 ) ;
return V_133 ;
}
static T_7 F_234 ( struct V_217 * V_217 , char T_2 * V_363 , T_8 V_256 ,
T_9 * V_374 )
{
struct V_247 * V_248 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_133 ;
V_248 = V_217 -> V_251 ;
V_3 = V_248 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( ! F_235 ( V_6 , V_256 ) )
return - V_62 ;
V_256 = F_236 ( V_6 , V_256 ) ;
V_133 = F_229 ( V_3 , V_363 , V_256 ) ;
if ( V_133 > 0 )
V_133 = F_237 ( V_6 , V_133 ) ;
return V_133 ;
}
static T_7 F_238 ( struct V_217 * V_217 , const char T_2 * V_363 ,
T_8 V_256 , T_9 * V_374 )
{
struct V_247 * V_248 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_133 ;
V_248 = V_217 -> V_251 ;
V_3 = V_248 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( ! F_235 ( V_6 , V_256 ) )
return - V_62 ;
V_256 = F_236 ( V_6 , V_256 ) ;
V_133 = F_225 ( V_3 , V_363 , V_256 ) ;
if ( V_133 > 0 )
V_133 = F_237 ( V_6 , V_133 ) ;
return V_133 ;
}
static T_7 F_239 ( struct V_375 * V_376 , const struct V_377 * V_378 ,
unsigned long V_379 , T_9 V_380 )
{
struct V_247 * V_248 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_133 ;
unsigned long V_40 ;
void T_2 * * V_368 ;
T_3 V_94 ;
V_248 = V_376 -> V_381 -> V_251 ;
V_3 = V_248 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( V_379 > 1024 || V_379 != V_6 -> V_109 )
return - V_62 ;
if ( ! F_235 ( V_6 , V_378 -> V_382 ) )
return - V_62 ;
V_94 = F_240 ( V_6 , V_378 -> V_382 ) ;
V_368 = F_9 ( sizeof( void * ) * V_379 , V_31 ) ;
if ( V_368 == NULL )
return - V_32 ;
for ( V_40 = 0 ; V_40 < V_379 ; ++ V_40 )
V_368 [ V_40 ] = V_378 [ V_40 ] . V_383 ;
V_133 = F_230 ( V_3 , V_368 , V_94 ) ;
if ( V_133 > 0 )
V_133 = F_237 ( V_6 , V_133 ) ;
F_11 ( V_368 ) ;
return V_133 ;
}
static T_7 F_241 ( struct V_375 * V_376 , const struct V_377 * V_378 ,
unsigned long V_379 , T_9 V_380 )
{
struct V_247 * V_248 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_133 ;
unsigned long V_40 ;
void T_2 * * V_368 ;
T_3 V_94 ;
V_248 = V_376 -> V_381 -> V_251 ;
V_3 = V_248 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( V_379 > 128 || V_379 != V_6 -> V_109 ||
! F_235 ( V_6 , V_378 -> V_382 ) )
return - V_62 ;
V_94 = F_240 ( V_6 , V_378 -> V_382 ) ;
V_368 = F_9 ( sizeof( void * ) * V_379 , V_31 ) ;
if ( V_368 == NULL )
return - V_32 ;
for ( V_40 = 0 ; V_40 < V_379 ; ++ V_40 )
V_368 [ V_40 ] = V_378 [ V_40 ] . V_383 ;
V_133 = F_227 ( V_3 , V_368 , V_94 ) ;
if ( V_133 > 0 )
V_133 = F_237 ( V_6 , V_133 ) ;
F_11 ( V_368 ) ;
return V_133 ;
}
static unsigned int F_242 ( struct V_217 * V_217 , T_10 * V_220 )
{
struct V_247 * V_248 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
unsigned int V_259 ;
T_3 V_145 ;
V_248 = V_217 -> V_251 ;
V_3 = V_248 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
F_243 ( V_217 , & V_6 -> V_183 , V_220 ) ;
F_36 ( V_3 ) ;
V_145 = F_66 ( V_6 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_146 :
case V_98 :
case V_189 :
if ( V_145 >= V_6 -> V_122 -> V_123 ) {
V_259 = V_384 | V_385 ;
break;
}
case V_147 :
V_259 = 0 ;
break;
default:
V_259 = V_384 | V_385 | V_386 ;
break;
}
F_37 ( V_3 ) ;
return V_259 ;
}
static unsigned int F_244 ( struct V_217 * V_217 , T_10 * V_220 )
{
struct V_247 * V_248 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
unsigned int V_259 ;
T_3 V_145 ;
V_248 = V_217 -> V_251 ;
V_3 = V_248 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
F_243 ( V_217 , & V_6 -> V_183 , V_220 ) ;
F_36 ( V_3 ) ;
V_145 = F_67 ( V_6 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_146 :
case V_98 :
case V_189 :
if ( V_145 >= V_6 -> V_122 -> V_123 ) {
V_259 = V_387 | V_388 ;
break;
}
V_259 = 0 ;
break;
case V_147 :
if ( V_145 > 0 ) {
V_259 = V_387 | V_388 ;
break;
}
default:
V_259 = V_387 | V_388 | V_386 ;
break;
}
F_37 ( V_3 ) ;
return V_259 ;
}
static int F_245 ( struct V_389 * V_390 ,
struct V_391 * V_392 )
{
struct V_2 * V_3 = V_390 -> V_393 ;
struct V_5 * V_6 ;
if ( V_3 == NULL )
return V_394 ;
V_6 = V_3 -> V_6 ;
V_392 -> V_395 = F_246 ( V_6 -> V_92 ) ;
F_247 ( V_392 -> V_395 ) ;
return 0 ;
}
static int V_319 ( struct V_2 * V_3 , struct V_217 * V_217 ,
struct V_389 * V_390 )
{
long V_396 ;
if ( ! ( V_390 -> V_397 & V_398 ) )
return - V_62 ;
V_396 = V_390 -> V_399 - V_390 -> V_400 ;
if ( V_396 != F_248 ( sizeof( struct V_319 ) ) )
return - V_62 ;
V_390 -> V_401 = & V_402 ;
V_390 -> V_393 = V_3 ;
V_390 -> V_397 |= V_403 | V_404 ;
return 0 ;
}
static int F_249 ( struct V_389 * V_390 ,
struct V_391 * V_392 )
{
struct V_2 * V_3 = V_390 -> V_393 ;
struct V_5 * V_6 ;
if ( V_3 == NULL )
return V_394 ;
V_6 = V_3 -> V_6 ;
V_392 -> V_395 = F_246 ( V_6 -> V_122 ) ;
F_247 ( V_392 -> V_395 ) ;
return 0 ;
}
static int V_320 ( struct V_2 * V_3 , struct V_217 * V_217 ,
struct V_389 * V_390 )
{
long V_396 ;
if ( ! ( V_390 -> V_397 & V_398 ) )
return - V_62 ;
V_396 = V_390 -> V_399 - V_390 -> V_400 ;
if ( V_396 != F_248 ( sizeof( struct V_320 ) ) )
return - V_62 ;
V_390 -> V_401 = & V_405 ;
V_390 -> V_393 = V_3 ;
V_390 -> V_397 |= V_403 | V_404 ;
return 0 ;
}
static int V_319 ( struct V_2 * V_3 , struct V_217 * V_217 ,
struct V_389 * V_390 )
{
return - V_95 ;
}
static int V_320 ( struct V_2 * V_3 , struct V_217 * V_217 ,
struct V_389 * V_390 )
{
return - V_95 ;
}
static inline struct V_395 *
F_250 ( struct V_2 * V_3 , unsigned long V_406 )
{
void * V_407 = V_3 -> V_6 -> V_408 + V_406 ;
#if F_39 ( V_409 ) && F_39 ( V_410 )
if ( V_3 -> V_411 . V_412 . type == V_413 )
return F_246 ( F_251 ( V_407 ) ) ;
#endif
#if F_39 ( V_414 ) && F_39 ( V_415 )
if ( V_3 -> V_411 . V_412 . type == V_413 ) {
T_11 V_416 = V_3 -> V_6 -> V_417 + V_406 ;
V_416 -= F_252 ( V_3 -> V_411 . V_412 . V_412 ) ;
return F_253 ( V_416 >> V_418 ) ;
}
#endif
return F_246 ( V_407 ) ;
}
static int F_254 ( struct V_389 * V_390 ,
struct V_391 * V_392 )
{
struct V_2 * V_3 = V_390 -> V_393 ;
struct V_5 * V_6 ;
unsigned long V_374 ;
struct V_395 * V_395 ;
T_8 V_295 ;
if ( V_3 == NULL )
return V_394 ;
V_6 = V_3 -> V_6 ;
V_374 = V_392 -> V_419 << V_418 ;
V_295 = F_248 ( V_6 -> V_295 ) ;
if ( V_374 > V_295 - V_420 )
return V_394 ;
if ( V_3 -> V_26 -> V_395 )
V_395 = V_3 -> V_26 -> V_395 ( V_3 , V_374 ) ;
else
V_395 = F_250 ( V_3 , V_374 ) ;
if ( ! V_395 )
return V_394 ;
F_247 ( V_395 ) ;
V_392 -> V_395 = V_395 ;
return 0 ;
}
int F_255 ( struct V_2 * V_3 ,
struct V_389 * V_390 )
{
V_390 -> V_397 |= V_403 | V_404 ;
#ifdef F_256
if ( ! V_3 -> V_26 -> V_395 &&
V_3 -> V_411 . V_412 . type == V_413 )
return F_257 ( V_3 -> V_411 . V_412 . V_412 ,
V_390 ,
V_3 -> V_6 -> V_408 ,
V_3 -> V_6 -> V_417 ,
V_390 -> V_399 - V_390 -> V_400 ) ;
#elif F_39 ( V_409 ) && F_39 ( V_410 )
if ( V_3 -> V_411 . V_412 . type == V_413 &&
! F_258 ( V_3 -> V_411 . V_412 . V_412 ) )
V_390 -> V_421 = F_259 ( V_390 -> V_421 ) ;
#endif
V_390 -> V_401 = & V_422 ;
return 0 ;
}
int F_260 ( struct V_2 * V_3 ,
struct V_389 * V_390 )
{
long V_396 ;
unsigned long V_374 ;
V_390 -> V_421 = F_259 ( V_390 -> V_421 ) ;
V_390 -> V_397 |= V_423 ;
V_396 = V_390 -> V_399 - V_390 -> V_400 ;
V_374 = V_390 -> V_424 << V_418 ;
if ( F_261 ( V_390 , V_390 -> V_400 ,
( V_3 -> V_6 -> V_417 + V_374 ) >> V_418 ,
V_396 , V_390 -> V_421 ) )
return - V_225 ;
return 0 ;
}
int F_262 ( struct V_2 * V_3 , struct V_217 * V_217 ,
struct V_389 * V_390 )
{
struct V_5 * V_6 ;
long V_396 ;
unsigned long V_374 ;
T_8 V_295 ;
int V_30 ;
if ( V_3 -> V_14 == V_135 ) {
if ( ! ( V_390 -> V_397 & ( V_425 | V_398 ) ) )
return - V_62 ;
} else {
if ( ! ( V_390 -> V_397 & V_398 ) )
return - V_62 ;
}
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( ! ( V_6 -> V_4 & V_278 ) )
return - V_95 ;
if ( V_6 -> V_106 == V_275 ||
V_6 -> V_106 == V_277 )
return - V_62 ;
V_396 = V_390 -> V_399 - V_390 -> V_400 ;
V_374 = V_390 -> V_424 << V_418 ;
V_295 = F_248 ( V_6 -> V_295 ) ;
if ( ( T_8 ) V_396 > V_295 )
return - V_62 ;
if ( V_374 > V_295 - V_396 )
return - V_62 ;
V_390 -> V_401 = & V_426 ;
V_390 -> V_393 = V_3 ;
if ( V_3 -> V_26 -> V_427 )
V_30 = V_3 -> V_26 -> V_427 ( V_3 , V_390 ) ;
else
V_30 = F_255 ( V_3 , V_390 ) ;
if ( ! V_30 )
F_263 ( & V_3 -> V_103 ) ;
return V_30 ;
}
static int F_264 ( struct V_217 * V_217 , struct V_389 * V_390 )
{
struct V_247 * V_248 ;
struct V_2 * V_3 ;
unsigned long V_374 ;
V_248 = V_217 -> V_251 ;
V_3 = V_248 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_374 = V_390 -> V_424 << V_418 ;
switch ( V_374 ) {
case V_428 :
if ( V_248 -> V_429 )
return - V_95 ;
return V_319 ( V_3 , V_217 , V_390 ) ;
case V_430 :
if ( V_248 -> V_429 )
return - V_95 ;
return V_320 ( V_3 , V_217 , V_390 ) ;
default:
return F_262 ( V_3 , V_217 , V_390 ) ;
}
return 0 ;
}
static int F_265 ( int V_236 , struct V_217 * V_217 , int V_431 )
{
struct V_247 * V_248 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
V_248 = V_217 -> V_251 ;
V_3 = V_248 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
return F_266 ( V_236 , V_217 , V_431 , & V_6 -> V_432 ) ;
}
static void F_267 ( struct V_34 * V_35 ,
struct V_433 * V_434 )
{
unsigned int V_40 ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
V_35 -> V_79 = V_434 -> V_79 ;
for ( V_40 = 0 ; V_40 < F_268 ( V_434 -> V_435 ) ; V_40 ++ )
V_35 -> V_435 [ V_40 ] . V_65 [ 0 ] = V_434 -> V_435 [ V_40 ] ;
memcpy ( V_35 -> V_436 , V_434 -> V_436 , sizeof( V_434 -> V_436 ) ) ;
V_35 -> V_54 = F_269 ( V_434 -> V_54 ) ;
V_35 -> V_66 = F_269 ( V_434 -> V_66 ) ;
V_35 -> V_4 = V_434 -> V_4 ;
V_35 -> V_56 = V_434 -> V_56 ;
V_35 -> V_58 = V_434 -> V_58 ;
V_35 -> V_59 = V_434 -> V_59 ;
V_35 -> V_53 = V_434 -> V_53 ;
}
static void F_270 ( struct V_433 * V_434 ,
struct V_34 * V_35 )
{
unsigned int V_40 ;
memset ( V_434 , 0 , sizeof( * V_434 ) ) ;
V_434 -> V_79 = V_35 -> V_79 ;
for ( V_40 = 0 ; V_40 < F_268 ( V_434 -> V_435 ) ; V_40 ++ )
V_434 -> V_435 [ V_40 ] = V_35 -> V_435 [ V_40 ] . V_65 [ 0 ] ;
memcpy ( V_434 -> V_436 , V_35 -> V_436 , sizeof( V_434 -> V_436 ) ) ;
V_434 -> V_54 = F_271 ( V_35 -> V_54 ) ;
V_434 -> V_66 = F_271 ( V_35 -> V_66 ) ;
V_434 -> V_4 = V_35 -> V_4 ;
V_434 -> V_56 = V_35 -> V_56 ;
V_434 -> V_58 = V_35 -> V_58 ;
V_434 -> V_59 = V_35 -> V_59 ;
V_434 -> V_53 = V_35 -> V_53 ;
}
static int F_222 ( struct V_2 * V_3 ,
struct V_433 T_2 * V_437 )
{
struct V_34 * V_35 ;
struct V_433 * V_434 = NULL ;
int V_30 ;
V_35 = F_9 ( sizeof( * V_35 ) , V_31 ) ;
if ( ! V_35 )
return - V_32 ;
V_434 = F_31 ( V_437 , sizeof( * V_434 ) ) ;
if ( F_32 ( V_434 ) ) {
V_30 = F_33 ( V_434 ) ;
goto V_438;
}
F_267 ( V_35 , V_434 ) ;
V_30 = F_12 ( V_3 , V_35 ) ;
F_270 ( V_434 , V_35 ) ;
if ( F_10 ( V_437 , V_434 , sizeof( * V_434 ) ) ) {
if ( ! V_30 )
V_30 = - V_33 ;
}
F_11 ( V_434 ) ;
V_438:
F_11 ( V_35 ) ;
return V_30 ;
}
static int F_223 ( struct V_2 * V_3 ,
struct V_433 T_2 * V_437 )
{
struct V_34 * V_35 ;
struct V_433 * V_434 = NULL ;
int V_30 ;
V_35 = F_9 ( sizeof( * V_35 ) , V_31 ) ;
if ( ! V_35 )
return - V_32 ;
V_434 = F_31 ( V_437 , sizeof( * V_434 ) ) ;
if ( F_32 ( V_434 ) ) {
V_30 = F_33 ( V_434 ) ;
goto V_438;
}
F_267 ( V_35 , V_434 ) ;
V_30 = V_34 ( V_3 , V_35 ) ;
F_270 ( V_434 , V_35 ) ;
if ( F_10 ( V_437 , V_434 , sizeof( * V_434 ) ) ) {
if ( ! V_30 )
V_30 = - V_33 ;
}
F_11 ( V_434 ) ;
V_438:
F_11 ( V_35 ) ;
return V_30 ;
}
static unsigned long F_272 ( struct V_217 * V_217 ,
unsigned long V_416 ,
unsigned long V_439 ,
unsigned long V_419 ,
unsigned long V_79 )
{
struct V_247 * V_248 = V_217 -> V_251 ;
struct V_2 * V_3 = V_248 -> V_3 ;
struct V_5 * V_6 = V_3 -> V_6 ;
unsigned long V_374 = V_419 << V_418 ;
switch ( V_374 ) {
case V_428 :
return ( unsigned long ) V_6 -> V_92 ;
case V_430 :
return ( unsigned long ) V_6 -> V_122 ;
default:
return ( unsigned long ) V_6 -> V_408 + V_374 ;
}
}
