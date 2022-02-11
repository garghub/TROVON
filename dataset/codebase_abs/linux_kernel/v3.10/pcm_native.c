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
V_92 -> V_142 =
V_6 -> V_92 -> V_142 ;
goto V_143;
}
}
F_65 ( V_6 , & V_92 -> V_141 ) ;
V_143:
V_92 -> V_144 = V_6 -> V_122 -> V_144 ;
V_92 -> V_145 = V_6 -> V_92 -> V_145 ;
if ( V_3 -> V_14 == V_135 ) {
V_92 -> V_146 = F_66 ( V_6 ) ;
if ( V_6 -> V_92 -> V_91 == V_147 ||
V_6 -> V_92 -> V_91 == V_148 ) {
V_92 -> V_149 = V_6 -> V_111 - V_92 -> V_146 ;
V_92 -> V_149 += V_6 -> V_149 ;
} else
V_92 -> V_149 = 0 ;
} else {
V_92 -> V_146 = F_67 ( V_6 ) ;
if ( V_6 -> V_92 -> V_91 == V_147 )
V_92 -> V_149 = V_92 -> V_146 + V_6 -> V_149 ;
else
V_92 -> V_149 = 0 ;
}
V_92 -> V_150 = V_6 -> V_150 ;
V_92 -> V_151 = V_6 -> V_151 ;
V_6 -> V_150 = 0 ;
V_6 -> V_151 = 0 ;
V_138:
F_37 ( V_3 ) ;
return 0 ;
}
static int F_68 ( struct V_2 * V_3 ,
struct F_63 T_2 * V_152 )
{
struct F_63 V_92 ;
int V_153 ;
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
V_153 = F_63 ( V_3 , & V_92 ) ;
if ( V_153 < 0 )
return V_153 ;
if ( F_10 ( V_152 , & V_92 , sizeof( V_92 ) ) )
return - V_33 ;
return 0 ;
}
static int F_69 ( struct V_2 * V_3 ,
struct F_69 * V_4 )
{
struct V_5 * V_6 ;
unsigned int V_154 ;
V_154 = V_4 -> V_154 ;
V_6 = V_3 -> V_6 ;
F_36 ( V_3 ) ;
if ( V_6 -> V_92 -> V_91 == V_96 ) {
F_37 ( V_3 ) ;
return - V_99 ;
}
F_37 ( V_3 ) ;
if ( V_154 >= V_6 -> V_109 )
return - V_62 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_154 = V_154 ;
return V_3 -> V_26 -> V_27 ( V_3 , V_155 , V_4 ) ;
}
static int F_70 ( struct V_2 * V_3 ,
struct F_69 T_2 * V_29 )
{
struct F_69 V_4 ;
int V_153 ;
if ( F_62 ( & V_4 , V_29 , sizeof( V_4 ) ) )
return - V_33 ;
V_153 = F_69 ( V_3 , & V_4 ) ;
if ( V_153 < 0 )
return V_153 ;
if ( F_10 ( V_29 , & V_4 , sizeof( V_4 ) ) )
return - V_33 ;
return 0 ;
}
static void F_71 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_156 == NULL )
return;
if ( V_6 -> V_156 == V_3 ) {
F_65 ( V_6 , & V_6 -> V_139 ) ;
} else {
F_71 ( V_6 -> V_156 ) ;
V_6 -> V_139 = V_6 -> V_156 -> V_6 -> V_139 ;
}
V_6 -> V_156 = NULL ;
}
static int F_72 ( struct V_157 * V_26 ,
struct V_2 * V_3 ,
int V_91 , int V_158 )
{
struct V_2 * V_159 = NULL ;
struct V_2 * V_160 ;
int V_153 = 0 ;
F_73 (s, substream) {
if ( V_158 && V_159 != V_3 )
F_74 ( & V_159 -> V_161 . V_162 ,
V_163 ) ;
V_153 = V_26 -> V_164 ( V_159 , V_91 ) ;
if ( V_153 < 0 )
goto V_165;
}
F_73 (s, substream) {
V_153 = V_26 -> V_166 ( V_159 , V_91 ) ;
if ( V_153 < 0 ) {
if ( V_26 -> V_167 ) {
F_73 (s1, substream) {
if ( V_160 == V_159 )
break;
V_26 -> V_167 ( V_160 , V_91 ) ;
}
}
V_159 = NULL ;
goto V_165;
}
}
F_73 (s, substream) {
V_26 -> V_168 ( V_159 , V_91 ) ;
}
V_165:
if ( V_158 ) {
F_73 (s1, substream) {
if ( V_160 != V_3 )
F_75 ( & V_160 -> V_161 . V_162 ) ;
if ( V_160 == V_159 )
break;
}
}
return V_153 ;
}
static int F_76 ( struct V_157 * V_26 ,
struct V_2 * V_3 ,
int V_91 )
{
int V_153 ;
V_153 = V_26 -> V_164 ( V_3 , V_91 ) ;
if ( V_153 < 0 )
return V_153 ;
V_153 = V_26 -> V_166 ( V_3 , V_91 ) ;
if ( V_153 == 0 )
V_26 -> V_168 ( V_3 , V_91 ) ;
else if ( V_26 -> V_167 )
V_26 -> V_167 ( V_3 , V_91 ) ;
return V_153 ;
}
static int F_77 ( struct V_157 * V_26 ,
struct V_2 * V_3 ,
int V_91 )
{
int V_153 ;
if ( F_78 ( V_3 ) ) {
if ( ! F_79 ( & V_3 -> V_169 -> V_162 ) ) {
F_75 ( & V_3 -> V_161 . V_162 ) ;
F_80 ( & V_3 -> V_169 -> V_162 ) ;
F_80 ( & V_3 -> V_161 . V_162 ) ;
}
V_153 = F_72 ( V_26 , V_3 , V_91 , 1 ) ;
F_75 ( & V_3 -> V_169 -> V_162 ) ;
} else {
V_153 = F_76 ( V_26 , V_3 , V_91 ) ;
}
return V_153 ;
}
static int F_81 ( struct V_157 * V_26 ,
struct V_2 * V_3 ,
int V_91 )
{
int V_153 ;
F_82 ( & V_170 ) ;
if ( F_78 ( V_3 ) ) {
F_80 ( & V_3 -> V_169 -> V_162 ) ;
F_80 ( & V_3 -> V_161 . V_162 ) ;
V_153 = F_72 ( V_26 , V_3 , V_91 , 1 ) ;
F_75 ( & V_3 -> V_161 . V_162 ) ;
F_75 ( & V_3 -> V_169 -> V_162 ) ;
} else {
F_80 ( & V_3 -> V_161 . V_162 ) ;
V_153 = F_76 ( V_26 , V_3 , V_91 ) ;
F_75 ( & V_3 -> V_161 . V_162 ) ;
}
F_83 ( & V_170 ) ;
return V_153 ;
}
static int F_84 ( struct V_157 * V_26 ,
struct V_2 * V_3 ,
int V_91 )
{
int V_153 ;
F_85 ( & V_171 ) ;
if ( F_78 ( V_3 ) )
V_153 = F_72 ( V_26 , V_3 , V_91 , 0 ) ;
else
V_153 = F_76 ( V_26 , V_3 , V_91 ) ;
F_86 ( & V_171 ) ;
return V_153 ;
}
static int F_87 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 != V_98 )
return - V_99 ;
if ( V_3 -> V_14 == V_135 &&
! F_88 ( V_3 ) )
return - V_172 ;
V_6 -> V_156 = V_3 ;
return 0 ;
}
static int F_89 ( struct V_2 * V_3 , int V_91 )
{
if ( V_3 -> V_6 -> V_156 != V_3 )
return 0 ;
return V_3 -> V_26 -> V_173 ( V_3 , V_174 ) ;
}
static void F_90 ( struct V_2 * V_3 , int V_91 )
{
if ( V_3 -> V_6 -> V_156 == V_3 )
V_3 -> V_26 -> V_173 ( V_3 , V_175 ) ;
}
static void F_91 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_71 ( V_3 ) ;
V_6 -> V_176 = V_177 ;
V_6 -> V_178 = ( V_6 -> V_111 * V_179 ) /
V_6 -> V_89 ;
V_6 -> V_92 -> V_91 = V_91 ;
if ( V_3 -> V_14 == V_135 &&
V_6 -> V_127 > 0 )
F_59 ( V_3 , V_136 ) ;
if ( V_3 -> V_180 )
F_92 ( V_3 -> V_180 , V_181 ,
& V_6 -> V_139 ) ;
}
int F_93 ( struct V_2 * V_3 )
{
return F_77 ( & V_182 , V_3 ,
V_147 ) ;
}
static int F_94 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
V_6 -> V_156 = V_3 ;
return 0 ;
}
static int F_95 ( struct V_2 * V_3 , int V_91 )
{
if ( V_3 -> V_6 -> V_156 == V_3 &&
F_58 ( V_3 ) )
V_3 -> V_26 -> V_173 ( V_3 , V_175 ) ;
return 0 ;
}
static void F_96 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 != V_91 ) {
F_71 ( V_3 ) ;
if ( V_3 -> V_180 )
F_92 ( V_3 -> V_180 , V_183 ,
& V_6 -> V_139 ) ;
V_6 -> V_92 -> V_91 = V_91 ;
}
F_97 ( & V_6 -> V_184 ) ;
F_97 ( & V_6 -> V_185 ) ;
}
int F_98 ( struct V_2 * V_3 , T_4 V_91 )
{
return F_77 ( & V_186 , V_3 , V_91 ) ;
}
int F_99 ( struct V_2 * V_3 )
{
return F_76 ( & V_186 , V_3 ,
V_97 ) ;
}
static int F_100 ( struct V_2 * V_3 , int V_187 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( ! ( V_6 -> V_4 & V_188 ) )
return - V_189 ;
if ( V_187 ) {
if ( V_6 -> V_92 -> V_91 != V_147 )
return - V_99 ;
} else if ( V_6 -> V_92 -> V_91 != V_190 )
return - V_99 ;
V_6 -> V_156 = V_3 ;
return 0 ;
}
static int F_101 ( struct V_2 * V_3 , int V_187 )
{
if ( V_3 -> V_6 -> V_156 != V_3 )
return 0 ;
if ( V_187 )
F_64 ( V_3 ) ;
V_3 -> V_6 -> V_176 = V_177 - V_179 * 1000 ;
return V_3 -> V_26 -> V_173 ( V_3 ,
V_187 ? V_191 :
V_192 ) ;
}
static void F_102 ( struct V_2 * V_3 , int V_187 )
{
if ( V_3 -> V_6 -> V_156 == V_3 )
V_3 -> V_26 -> V_173 ( V_3 ,
V_187 ? V_192 :
V_191 ) ;
}
static void F_103 ( struct V_2 * V_3 , int V_187 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_71 ( V_3 ) ;
if ( V_187 ) {
V_6 -> V_92 -> V_91 = V_190 ;
if ( V_3 -> V_180 )
F_92 ( V_3 -> V_180 ,
V_193 ,
& V_6 -> V_139 ) ;
F_97 ( & V_6 -> V_184 ) ;
F_97 ( & V_6 -> V_185 ) ;
} else {
V_6 -> V_92 -> V_91 = V_147 ;
if ( V_3 -> V_180 )
F_92 ( V_3 -> V_180 ,
V_194 ,
& V_6 -> V_139 ) ;
}
}
static int F_104 ( struct V_2 * V_3 , int V_187 )
{
return F_77 ( & V_195 , V_3 , V_187 ) ;
}
static int F_105 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_196 )
return - V_197 ;
V_6 -> V_156 = V_3 ;
return 0 ;
}
static int F_106 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_156 != V_3 )
return 0 ;
if ( ! F_58 ( V_3 ) )
return 0 ;
V_3 -> V_26 -> V_173 ( V_3 , V_198 ) ;
return 0 ;
}
static void F_107 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_71 ( V_3 ) ;
if ( V_3 -> V_180 )
F_92 ( V_3 -> V_180 , V_199 ,
& V_6 -> V_139 ) ;
V_6 -> V_92 -> V_137 = V_6 -> V_92 -> V_91 ;
V_6 -> V_92 -> V_91 = V_196 ;
F_97 ( & V_6 -> V_184 ) ;
F_97 ( & V_6 -> V_185 ) ;
}
int F_108 ( struct V_2 * V_3 )
{
int V_30 ;
unsigned long V_79 ;
if ( ! V_3 )
return 0 ;
F_109 ( V_3 , V_79 ) ;
V_30 = F_77 ( & V_200 , V_3 , 0 ) ;
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
for ( V_3 = V_8 -> V_201 [ V_14 ] . V_3 ;
V_3 ; V_3 = V_3 -> V_202 ) {
if ( V_3 -> V_6 == NULL )
continue;
V_30 = F_108 ( V_3 ) ;
if ( V_30 < 0 && V_30 != - V_197 )
return V_30 ;
}
}
return 0 ;
}
static int F_112 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( ! ( V_6 -> V_4 & V_203 ) )
return - V_189 ;
V_6 -> V_156 = V_3 ;
return 0 ;
}
static int F_113 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_156 != V_3 )
return 0 ;
if ( V_6 -> V_92 -> V_137 != V_147 &&
( V_6 -> V_92 -> V_137 != V_148 ||
V_3 -> V_14 != V_135 ) )
return 0 ;
return V_3 -> V_26 -> V_173 ( V_3 , V_204 ) ;
}
static void F_114 ( struct V_2 * V_3 , int V_91 )
{
if ( V_3 -> V_6 -> V_156 == V_3 &&
F_58 ( V_3 ) )
V_3 -> V_26 -> V_173 ( V_3 , V_198 ) ;
}
static void F_115 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_71 ( V_3 ) ;
if ( V_3 -> V_180 )
F_92 ( V_3 -> V_180 , V_205 ,
& V_6 -> V_139 ) ;
V_6 -> V_92 -> V_91 = V_6 -> V_92 -> V_137 ;
}
static int F_116 ( struct V_2 * V_3 )
{
struct V_206 * V_11 = V_3 -> V_8 -> V_11 ;
int V_153 ;
F_117 ( V_11 ) ;
if ( ( V_153 = F_118 ( V_11 , V_207 ) ) >= 0 )
V_153 = F_81 ( & V_208 , V_3 , 0 ) ;
F_119 ( V_11 ) ;
return V_153 ;
}
static int F_116 ( struct V_2 * V_3 )
{
return - V_189 ;
}
static int F_120 ( struct V_2 * V_3 )
{
struct V_206 * V_11 = V_3 -> V_8 -> V_11 ;
struct V_5 * V_6 = V_3 -> V_6 ;
int V_133 ;
F_117 ( V_11 ) ;
if ( V_6 -> V_92 -> V_91 == V_196 ) {
V_133 = F_118 ( V_11 , V_207 ) ;
if ( V_133 < 0 )
goto V_165;
}
F_36 ( V_3 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_209 :
V_133 = 0 ;
break;
case V_147 :
V_133 = F_98 ( V_3 , V_209 ) ;
break;
default:
V_133 = - V_99 ;
}
F_37 ( V_3 ) ;
V_165:
F_119 ( V_11 ) ;
return V_133 ;
}
static int F_121 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_147 :
case V_98 :
case V_190 :
case V_196 :
return 0 ;
default:
return - V_99 ;
}
}
static int F_122 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_30 = V_3 -> V_26 -> V_27 ( V_3 , V_210 , NULL ) ;
if ( V_30 < 0 )
return V_30 ;
V_6 -> V_211 = 0 ;
V_6 -> V_212 = V_6 -> V_92 -> V_145 -
V_6 -> V_92 -> V_145 % V_6 -> V_90 ;
V_6 -> V_213 = V_6 -> V_92 -> V_145 ;
V_6 -> V_214 = 0 ;
return 0 ;
}
static void F_123 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
V_6 -> V_122 -> V_144 = V_6 -> V_92 -> V_145 ;
if ( V_3 -> V_14 == V_135 &&
V_6 -> V_127 > 0 )
F_59 ( V_3 , V_136 ) ;
}
static int F_124 ( struct V_2 * V_3 )
{
return F_84 ( & V_215 , V_3 , 0 ) ;
}
static int F_125 ( struct V_2 * V_3 ,
int V_216 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 ||
V_6 -> V_92 -> V_91 == V_93 )
return - V_99 ;
if ( F_58 ( V_3 ) )
return - V_197 ;
V_3 -> V_216 = V_216 ;
return 0 ;
}
static int F_126 ( struct V_2 * V_3 , int V_91 )
{
int V_30 ;
V_30 = V_3 -> V_26 -> V_217 ( V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
return F_122 ( V_3 , 0 ) ;
}
static void F_127 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
V_6 -> V_122 -> V_144 = V_6 -> V_92 -> V_145 ;
F_35 ( V_3 , V_98 ) ;
}
static int F_128 ( struct V_2 * V_3 ,
struct V_218 * V_218 )
{
int V_153 ;
struct V_206 * V_11 = V_3 -> V_8 -> V_11 ;
int V_216 ;
if ( V_218 )
V_216 = V_218 -> V_216 ;
else
V_216 = V_3 -> V_216 ;
F_117 ( V_11 ) ;
if ( ( V_153 = F_118 ( V_11 , V_207 ) ) >= 0 )
V_153 = F_84 ( & V_219 ,
V_3 , V_216 ) ;
F_119 ( V_11 ) ;
return V_153 ;
}
static int F_129 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_96 :
case V_93 :
case V_196 :
return - V_99 ;
}
V_6 -> V_156 = V_3 ;
return 0 ;
}
static int F_130 ( struct V_2 * V_3 , int V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_3 -> V_14 == V_135 ) {
switch ( V_6 -> V_92 -> V_91 ) {
case V_98 :
if ( ! F_131 ( V_3 ) ) {
F_89 ( V_3 , V_148 ) ;
F_91 ( V_3 , V_148 ) ;
}
break;
case V_147 :
V_6 -> V_92 -> V_91 = V_148 ;
break;
case V_209 :
V_6 -> V_92 -> V_91 = V_97 ;
break;
default:
break;
}
} else {
if ( V_6 -> V_92 -> V_91 == V_147 ) {
int V_220 = F_67 ( V_6 ) > 0 ?
V_148 : V_97 ;
F_95 ( V_3 , V_220 ) ;
F_96 ( V_3 , V_220 ) ;
}
}
return 0 ;
}
static void F_132 ( struct V_2 * V_3 , int V_91 )
{
}
static int F_133 ( struct V_2 * V_3 ,
struct V_218 * V_218 )
{
struct V_206 * V_11 ;
struct V_5 * V_6 ;
struct V_2 * V_159 ;
T_5 V_221 ;
int V_133 = 0 ;
int V_222 = 0 ;
V_11 = V_3 -> V_8 -> V_11 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
F_117 ( V_11 ) ;
if ( V_6 -> V_92 -> V_91 == V_196 ) {
V_133 = F_118 ( V_11 , V_207 ) ;
if ( V_133 < 0 ) {
F_119 ( V_11 ) ;
return V_133 ;
}
}
if ( V_218 ) {
if ( V_218 -> V_216 & V_223 )
V_222 = 1 ;
} else if ( V_3 -> V_216 & V_223 )
V_222 = 1 ;
F_85 ( & V_171 ) ;
F_36 ( V_3 ) ;
if ( V_6 -> V_92 -> V_91 == V_190 )
F_104 ( V_3 , 0 ) ;
V_133 = F_77 ( & V_224 , V_3 , 0 ) ;
if ( V_133 < 0 )
goto V_225;
if ( V_222 ) {
V_133 = - V_226 ;
goto V_225;
}
for (; ; ) {
long V_227 ;
struct V_5 * V_228 ;
if ( F_134 ( V_229 ) ) {
V_133 = - V_230 ;
break;
}
V_228 = NULL ;
F_73 (s, substream) {
if ( V_159 -> V_14 != V_135 )
continue;
V_6 = V_159 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_148 ) {
V_228 = V_6 ;
break;
}
}
if ( ! V_228 )
break;
F_135 ( & V_221 , V_229 ) ;
F_136 ( & V_228 -> V_184 , & V_221 ) ;
F_37 ( V_3 ) ;
F_86 ( & V_171 ) ;
F_119 ( V_11 ) ;
if ( V_6 -> V_112 )
V_227 = V_231 ;
else {
V_227 = 10 ;
if ( V_6 -> V_89 ) {
long V_232 = V_6 -> V_90 * 2 / V_6 -> V_89 ;
V_227 = V_71 ( V_232 , V_227 ) ;
}
V_227 = F_137 ( V_227 * 1000 ) ;
}
V_227 = F_138 ( V_227 ) ;
F_117 ( V_11 ) ;
F_85 ( & V_171 ) ;
F_36 ( V_3 ) ;
F_139 ( & V_228 -> V_184 , & V_221 ) ;
if ( V_11 -> V_233 ) {
V_133 = - V_234 ;
break;
}
if ( V_227 == 0 ) {
if ( V_3 -> V_6 -> V_92 -> V_91 == V_196 )
V_133 = - V_235 ;
else {
F_140 ( L_12 ) ;
F_98 ( V_3 , V_97 ) ;
V_133 = - V_236 ;
}
break;
}
}
V_225:
F_37 ( V_3 ) ;
F_86 ( & V_171 ) ;
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
V_6 -> V_92 -> V_91 == V_196 )
return - V_99 ;
F_36 ( V_3 ) ;
if ( V_6 -> V_92 -> V_91 == V_190 )
F_104 ( V_3 , 0 ) ;
F_98 ( V_3 , V_97 ) ;
F_37 ( V_3 ) ;
return V_133 ;
}
static struct V_218 * F_142 ( int V_237 , int * V_238 )
{
struct V_218 * V_218 ;
struct V_239 * V_239 ;
unsigned int V_240 ;
V_218 = F_143 ( V_237 , V_238 ) ;
if ( ! V_218 )
return NULL ;
V_239 = F_144 ( V_218 ) ;
if ( ! F_145 ( V_239 -> V_241 ) ||
F_146 ( V_239 ) != V_242 ) {
F_147 ( V_218 , * V_238 ) ;
return NULL ;
}
V_240 = F_148 ( V_239 ) ;
if ( ! F_149 ( V_240 , V_243 ) &&
! F_149 ( V_240 , V_244 ) ) {
F_147 ( V_218 , * V_238 ) ;
return NULL ;
}
return V_218 ;
}
static int F_150 ( struct V_2 * V_3 , int V_237 )
{
int V_153 = 0 ;
struct V_218 * V_218 ;
struct V_245 * V_246 ;
struct V_2 * V_247 ;
struct V_248 * V_169 ;
int V_238 ;
V_218 = F_142 ( V_237 , & V_238 ) ;
if ( ! V_218 )
return - V_99 ;
V_246 = V_218 -> V_249 ;
V_247 = V_246 -> V_3 ;
V_169 = F_9 ( sizeof( * V_169 ) , V_31 ) ;
if ( ! V_169 ) {
V_153 = - V_32 ;
goto V_250;
}
F_151 ( & V_171 ) ;
F_152 ( & V_170 ) ;
if ( V_3 -> V_6 -> V_92 -> V_91 == V_96 ||
V_3 -> V_6 -> V_92 -> V_91 != V_247 -> V_6 -> V_92 -> V_91 ) {
V_153 = - V_99 ;
goto V_138;
}
if ( F_78 ( V_247 ) ) {
V_153 = - V_251 ;
goto V_138;
}
if ( ! F_78 ( V_3 ) ) {
V_3 -> V_169 = V_169 ;
V_169 = NULL ;
F_153 ( & V_3 -> V_169 -> V_162 ) ;
F_154 ( & V_3 -> V_169 -> V_252 ) ;
F_155 ( & V_3 -> V_253 , & V_3 -> V_169 -> V_252 ) ;
V_3 -> V_169 -> V_254 = 1 ;
}
F_155 ( & V_247 -> V_253 , & V_3 -> V_169 -> V_252 ) ;
V_3 -> V_169 -> V_254 ++ ;
V_247 -> V_169 = V_3 -> V_169 ;
V_138:
F_156 ( & V_170 ) ;
F_157 ( & V_171 ) ;
V_250:
F_158 ( V_247 -> V_8 -> V_11 ) ;
F_147 ( V_218 , V_238 ) ;
F_11 ( V_169 ) ;
return V_153 ;
}
static void F_159 ( struct V_2 * V_3 )
{
V_3 -> V_169 = & V_3 -> V_161 ;
F_154 ( & V_3 -> V_161 . V_252 ) ;
F_155 ( & V_3 -> V_253 , & V_3 -> V_161 . V_252 ) ;
}
static int F_160 ( struct V_2 * V_3 )
{
struct V_2 * V_159 ;
int V_153 = 0 ;
F_151 ( & V_171 ) ;
F_152 ( & V_170 ) ;
if ( ! F_78 ( V_3 ) ) {
V_153 = - V_251 ;
goto V_138;
}
F_161 ( & V_3 -> V_253 ) ;
V_3 -> V_169 -> V_254 -- ;
if ( V_3 -> V_169 -> V_254 == 1 ) {
F_73 (s, substream) {
F_159 ( V_159 ) ;
break;
}
F_11 ( V_3 -> V_169 ) ;
}
F_159 ( V_3 ) ;
V_138:
F_156 ( & V_170 ) ;
F_157 ( & V_171 ) ;
return V_153 ;
}
static int F_162 ( struct V_34 * V_35 ,
struct V_73 * V_255 )
{
struct V_39 V_232 ;
F_163 ( F_164 ( V_35 , V_255 -> V_80 [ 0 ] ) ,
F_164 ( V_35 , V_255 -> V_80 [ 1 ] ) , & V_232 ) ;
return F_21 ( F_19 ( V_35 , V_255 -> V_82 ) , & V_232 ) ;
}
static int F_165 ( struct V_34 * V_35 ,
struct V_73 * V_255 )
{
struct V_39 V_232 ;
F_166 ( F_164 ( V_35 , V_255 -> V_80 [ 0 ] ) ,
F_164 ( V_35 , V_255 -> V_80 [ 1 ] ) , & V_232 ) ;
return F_21 ( F_19 ( V_35 , V_255 -> V_82 ) , & V_232 ) ;
}
static int F_167 ( struct V_34 * V_35 ,
struct V_73 * V_255 )
{
struct V_39 V_232 ;
F_168 ( F_164 ( V_35 , V_255 -> V_80 [ 0 ] ) ,
F_164 ( V_35 , V_255 -> V_80 [ 1 ] ) ,
( unsigned long ) V_255 -> V_256 , & V_232 ) ;
return F_21 ( F_19 ( V_35 , V_255 -> V_82 ) , & V_232 ) ;
}
static int F_169 ( struct V_34 * V_35 ,
struct V_73 * V_255 )
{
struct V_39 V_232 ;
F_170 ( F_164 ( V_35 , V_255 -> V_80 [ 0 ] ) ,
( unsigned long ) V_255 -> V_256 ,
F_164 ( V_35 , V_255 -> V_80 [ 1 ] ) , & V_232 ) ;
return F_21 ( F_19 ( V_35 , V_255 -> V_82 ) , & V_232 ) ;
}
static int F_171 ( struct V_34 * V_35 ,
struct V_73 * V_255 )
{
unsigned int V_36 ;
struct V_39 * V_40 = F_19 ( V_35 , V_255 -> V_80 [ 0 ] ) ;
struct V_41 V_42 ;
struct V_41 * V_257 = F_13 ( V_35 , V_84 ) ;
F_172 ( & V_42 ) ;
for ( V_36 = 0 ; V_36 <= V_258 ; ++ V_36 ) {
int V_65 ;
if ( ! F_173 ( V_257 , V_36 ) )
continue;
V_65 = F_50 ( V_36 ) ;
if ( V_65 <= 0 )
continue;
if ( ( unsigned ) V_65 < V_40 -> V_70 || ( unsigned ) V_65 > V_40 -> V_71 )
F_174 ( & V_42 , V_36 ) ;
}
return F_17 ( V_257 , & V_42 ) ;
}
static int F_175 ( struct V_34 * V_35 ,
struct V_73 * V_255 )
{
struct V_39 V_232 ;
unsigned int V_36 ;
V_232 . V_70 = V_259 ;
V_232 . V_71 = 0 ;
V_232 . V_69 = 0 ;
V_232 . V_72 = 0 ;
for ( V_36 = 0 ; V_36 <= V_258 ; ++ V_36 ) {
int V_65 ;
if ( ! F_173 ( F_13 ( V_35 , V_84 ) , V_36 ) )
continue;
V_65 = F_50 ( V_36 ) ;
if ( V_65 <= 0 )
continue;
if ( V_232 . V_70 > ( unsigned ) V_65 )
V_232 . V_70 = V_65 ;
if ( V_232 . V_71 < ( unsigned ) V_65 )
V_232 . V_71 = V_65 ;
}
V_232 . integer = 1 ;
return F_21 ( F_19 ( V_35 , V_255 -> V_82 ) , & V_232 ) ;
}
static int F_176 ( struct V_34 * V_35 ,
struct V_73 * V_255 )
{
struct V_37 * V_38 = V_255 -> V_256 ;
return F_177 ( F_19 ( V_35 , V_255 -> V_82 ) ,
V_260 . V_254 ,
V_260 . V_261 , V_38 -> V_262 ) ;
}
static int F_178 ( struct V_34 * V_35 ,
struct V_73 * V_255 )
{
struct V_39 V_232 ;
struct V_2 * V_3 = V_255 -> V_256 ;
V_232 . V_70 = 0 ;
V_232 . V_71 = V_3 -> V_263 ;
V_232 . V_69 = 0 ;
V_232 . V_72 = 0 ;
V_232 . integer = 1 ;
return F_21 ( F_19 ( V_35 , V_255 -> V_82 ) , & V_232 ) ;
}
int F_179 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_43 * V_44 = & V_6 -> V_45 ;
int V_36 , V_30 ;
for ( V_36 = V_60 ; V_36 <= V_61 ; V_36 ++ ) {
F_172 ( F_18 ( V_44 , V_36 ) ) ;
}
for ( V_36 = V_67 ; V_36 <= V_49 ; V_36 ++ ) {
F_180 ( F_22 ( V_44 , V_36 ) ) ;
}
F_181 ( F_22 ( V_44 , V_85 ) ) ;
F_181 ( F_22 ( V_44 , V_264 ) ) ;
F_181 ( F_22 ( V_44 , V_265 ) ) ;
F_181 ( F_22 ( V_44 , V_55 ) ) ;
F_181 ( F_22 ( V_44 , V_266 ) ) ;
V_30 = F_182 ( V_6 , 0 , V_84 ,
F_171 , NULL ,
V_55 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_55 ,
F_175 , NULL ,
V_84 ,
V_55 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_55 ,
F_165 , NULL ,
V_266 , V_85 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_266 ,
F_162 , NULL ,
V_55 , V_85 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_266 ,
F_169 , ( void * ) 8 ,
V_267 , V_268 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_266 ,
F_169 , ( void * ) 8 ,
V_265 , V_264 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_85 ,
F_165 , NULL ,
V_266 , V_55 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_57 ,
F_169 , ( void * ) 1000000 ,
V_268 , V_269 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_57 ,
F_169 , ( void * ) 1000000 ,
V_264 , V_270 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_271 ,
F_165 , NULL ,
V_264 , V_268 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_268 ,
F_165 , NULL ,
V_264 , V_271 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_268 ,
F_169 , ( void * ) 8 ,
V_267 , V_266 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_268 ,
F_167 , ( void * ) 1000000 ,
V_269 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_264 ,
F_162 , NULL ,
V_268 , V_271 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_264 ,
F_169 , ( void * ) 8 ,
V_265 , V_266 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_264 ,
F_167 , ( void * ) 1000000 ,
V_270 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_267 ,
F_167 , ( void * ) 8 ,
V_268 , V_266 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_265 ,
F_167 , ( void * ) 8 ,
V_264 , V_266 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_269 ,
F_169 , ( void * ) 1000000 ,
V_268 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_270 ,
F_169 , ( void * ) 1000000 ,
V_264 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
return 0 ;
}
int F_183 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_37 * V_38 = & V_6 -> V_38 ;
int V_30 ;
unsigned int V_257 = 0 ;
if ( V_38 -> V_4 & V_272 )
V_257 |= 1 << V_273 ;
if ( V_38 -> V_4 & V_274 )
V_257 |= 1 << V_275 ;
if ( V_38 -> V_4 & V_276 ) {
if ( V_38 -> V_4 & V_272 )
V_257 |= 1 << V_277 ;
if ( V_38 -> V_4 & V_274 )
V_257 |= 1 << V_278 ;
if ( V_38 -> V_4 & V_279 )
V_257 |= 1 << V_280 ;
}
V_30 = F_184 ( V_6 , V_281 , V_257 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_185 ( V_6 , V_84 , V_38 -> V_282 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_184 ( V_6 , V_283 , 1 << V_284 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_186 ( V_6 , V_85 ,
V_38 -> V_285 , V_38 -> V_286 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_186 ( V_6 , V_57 ,
V_38 -> V_287 , V_38 -> V_288 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_186 ( V_6 , V_267 ,
V_38 -> V_289 , V_38 -> V_290 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_186 ( V_6 , V_271 ,
V_38 -> V_291 , V_38 -> V_292 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_186 ( V_6 , V_265 ,
V_38 -> V_289 , V_38 -> V_263 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_265 ,
F_178 , V_3 ,
V_265 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_6 -> V_293 ) {
V_30 = F_186 ( V_6 , V_265 , 0 , V_6 -> V_293 ) ;
if ( V_30 < 0 )
return V_30 ;
}
if ( ! ( V_38 -> V_262 & ( V_294 | V_295 ) ) ) {
V_30 = F_182 ( V_6 , 0 , V_57 ,
F_176 , V_38 ,
V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
}
F_187 ( V_6 , V_268 ) ;
return 0 ;
}
static void F_188 ( struct V_2 * V_3 )
{
F_160 ( V_3 ) ;
}
void F_189 ( struct V_2 * V_3 )
{
V_3 -> V_296 -- ;
if ( V_3 -> V_296 > 0 )
return;
F_141 ( V_3 ) ;
if ( V_3 -> V_297 ) {
if ( V_3 -> V_26 -> V_132 != NULL )
V_3 -> V_26 -> V_132 ( V_3 ) ;
V_3 -> V_26 -> V_298 ( V_3 ) ;
V_3 -> V_297 = 0 ;
}
if ( F_52 ( & V_3 -> V_130 ) )
F_53 ( & V_3 -> V_130 ) ;
if ( V_3 -> V_299 ) {
V_3 -> V_299 ( V_3 ) ;
V_3 -> V_299 = NULL ;
}
F_190 ( V_3 ) ;
}
int F_191 ( struct V_7 * V_8 , int V_14 ,
struct V_218 * V_218 ,
struct V_2 * * V_300 )
{
struct V_2 * V_3 ;
int V_30 ;
V_30 = F_192 ( V_8 , V_14 , V_218 , & V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_3 -> V_296 > 1 ) {
* V_300 = V_3 ;
return 0 ;
}
V_30 = F_179 ( V_3 ) ;
if ( V_30 < 0 ) {
F_140 ( L_13 ) ;
goto error;
}
if ( ( V_30 = V_3 -> V_26 -> V_301 ( V_3 ) ) < 0 )
goto error;
V_3 -> V_297 = 1 ;
V_30 = F_183 ( V_3 ) ;
if ( V_30 < 0 ) {
F_140 ( L_14 ) ;
goto error;
}
* V_300 = V_3 ;
return 0 ;
error:
F_189 ( V_3 ) ;
return V_30 ;
}
static int F_193 ( struct V_218 * V_218 ,
struct V_7 * V_8 ,
int V_14 )
{
struct V_245 * V_246 ;
struct V_2 * V_3 ;
int V_30 ;
V_30 = F_191 ( V_8 , V_14 , V_218 , & V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
V_246 = F_194 ( sizeof( * V_246 ) , V_31 ) ;
if ( V_246 == NULL ) {
F_189 ( V_3 ) ;
return - V_32 ;
}
V_246 -> V_3 = V_3 ;
if ( V_3 -> V_296 == 1 ) {
V_3 -> V_218 = V_246 ;
V_3 -> V_299 = F_188 ;
}
V_218 -> V_249 = V_246 ;
return 0 ;
}
static int F_195 ( struct V_239 * V_239 , struct V_218 * V_218 )
{
struct V_7 * V_8 ;
int V_30 = F_196 ( V_239 , V_218 ) ;
if ( V_30 < 0 )
return V_30 ;
V_8 = F_149 ( F_148 ( V_239 ) ,
V_243 ) ;
V_30 = F_197 ( V_218 , V_8 , V_135 ) ;
if ( V_8 )
F_158 ( V_8 -> V_11 ) ;
return V_30 ;
}
static int F_198 ( struct V_239 * V_239 , struct V_218 * V_218 )
{
struct V_7 * V_8 ;
int V_30 = F_196 ( V_239 , V_218 ) ;
if ( V_30 < 0 )
return V_30 ;
V_8 = F_149 ( F_148 ( V_239 ) ,
V_244 ) ;
V_30 = F_197 ( V_218 , V_8 , V_302 ) ;
if ( V_8 )
F_158 ( V_8 -> V_11 ) ;
return V_30 ;
}
static int F_197 ( struct V_218 * V_218 , struct V_7 * V_8 , int V_14 )
{
int V_30 ;
T_5 V_221 ;
if ( V_8 == NULL ) {
V_30 = - V_234 ;
goto V_303;
}
V_30 = F_199 ( V_8 -> V_11 , V_218 ) ;
if ( V_30 < 0 )
goto V_303;
if ( ! F_200 ( V_8 -> V_11 -> V_304 ) ) {
V_30 = - V_33 ;
goto V_305;
}
F_135 ( & V_221 , V_229 ) ;
F_136 ( & V_8 -> V_306 , & V_221 ) ;
F_201 ( & V_8 -> V_307 ) ;
while ( 1 ) {
V_30 = F_193 ( V_218 , V_8 , V_14 ) ;
if ( V_30 >= 0 )
break;
if ( V_30 == - V_226 ) {
if ( V_218 -> V_216 & V_223 ) {
V_30 = - V_197 ;
break;
}
} else
break;
F_202 ( V_308 ) ;
F_203 ( & V_8 -> V_307 ) ;
F_204 () ;
F_201 ( & V_8 -> V_307 ) ;
if ( V_8 -> V_11 -> V_233 ) {
V_30 = - V_234 ;
break;
}
if ( F_134 ( V_229 ) ) {
V_30 = - V_230 ;
break;
}
}
F_139 ( & V_8 -> V_306 , & V_221 ) ;
F_203 ( & V_8 -> V_307 ) ;
if ( V_30 < 0 )
goto V_309;
return V_30 ;
V_309:
F_205 ( V_8 -> V_11 -> V_304 ) ;
V_305:
F_206 ( V_8 -> V_11 , V_218 ) ;
V_303:
return V_30 ;
}
static int F_207 ( struct V_239 * V_239 , struct V_218 * V_218 )
{
struct V_7 * V_8 ;
struct V_2 * V_3 ;
struct V_245 * V_246 ;
V_246 = V_218 -> V_249 ;
V_3 = V_246 -> V_3 ;
if ( F_208 ( ! V_3 ) )
return - V_95 ;
V_8 = V_3 -> V_8 ;
F_201 ( & V_8 -> V_307 ) ;
F_189 ( V_3 ) ;
F_11 ( V_246 ) ;
F_203 ( & V_8 -> V_307 ) ;
F_97 ( & V_8 -> V_306 ) ;
F_205 ( V_8 -> V_11 -> V_304 ) ;
F_206 ( V_8 -> V_11 , V_218 ) ;
return 0 ;
}
static T_6 F_209 ( struct V_2 * V_3 ,
T_3 V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_144 ;
T_6 V_310 ;
T_6 V_311 ;
if ( V_94 == 0 )
return 0 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_98 :
break;
case V_148 :
case V_147 :
if ( F_64 ( V_3 ) >= 0 )
break;
case V_209 :
V_310 = - V_172 ;
goto V_312;
case V_196 :
V_310 = - V_235 ;
goto V_312;
default:
V_310 = - V_99 ;
goto V_312;
}
V_311 = F_210 ( V_6 ) ;
if ( V_311 <= 0 ) {
V_310 = 0 ;
goto V_312;
}
if ( V_94 > ( T_3 ) V_311 )
V_94 = V_311 ;
V_144 = V_6 -> V_122 -> V_144 - V_94 ;
if ( V_144 < 0 )
V_144 += V_6 -> V_128 ;
V_6 -> V_122 -> V_144 = V_144 ;
V_310 = V_94 ;
V_312:
F_37 ( V_3 ) ;
return V_310 ;
}
static T_6 F_211 ( struct V_2 * V_3 ,
T_3 V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_144 ;
T_6 V_310 ;
T_6 V_311 ;
if ( V_94 == 0 )
return 0 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_98 :
case V_148 :
break;
case V_147 :
if ( F_64 ( V_3 ) >= 0 )
break;
case V_209 :
V_310 = - V_172 ;
goto V_312;
case V_196 :
V_310 = - V_235 ;
goto V_312;
default:
V_310 = - V_99 ;
goto V_312;
}
V_311 = F_212 ( V_6 ) ;
if ( V_311 <= 0 ) {
V_310 = 0 ;
goto V_312;
}
if ( V_94 > ( T_3 ) V_311 )
V_94 = V_311 ;
V_144 = V_6 -> V_122 -> V_144 - V_94 ;
if ( V_144 < 0 )
V_144 += V_6 -> V_128 ;
V_6 -> V_122 -> V_144 = V_144 ;
V_310 = V_94 ;
V_312:
F_37 ( V_3 ) ;
return V_310 ;
}
static T_6 F_213 ( struct V_2 * V_3 ,
T_3 V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_144 ;
T_6 V_310 ;
T_6 V_146 ;
if ( V_94 == 0 )
return 0 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_98 :
case V_190 :
break;
case V_148 :
case V_147 :
if ( F_64 ( V_3 ) >= 0 )
break;
case V_209 :
V_310 = - V_172 ;
goto V_312;
case V_196 :
V_310 = - V_235 ;
goto V_312;
default:
V_310 = - V_99 ;
goto V_312;
}
V_146 = F_66 ( V_6 ) ;
if ( V_146 <= 0 ) {
V_310 = 0 ;
goto V_312;
}
if ( V_94 > ( T_3 ) V_146 )
V_94 = V_146 ;
V_144 = V_6 -> V_122 -> V_144 + V_94 ;
if ( V_144 >= ( T_6 ) V_6 -> V_128 )
V_144 -= V_6 -> V_128 ;
V_6 -> V_122 -> V_144 = V_144 ;
V_310 = V_94 ;
V_312:
F_37 ( V_3 ) ;
return V_310 ;
}
static T_6 F_214 ( struct V_2 * V_3 ,
T_3 V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_144 ;
T_6 V_310 ;
T_6 V_146 ;
if ( V_94 == 0 )
return 0 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_98 :
case V_148 :
case V_190 :
break;
case V_147 :
if ( F_64 ( V_3 ) >= 0 )
break;
case V_209 :
V_310 = - V_172 ;
goto V_312;
case V_196 :
V_310 = - V_235 ;
goto V_312;
default:
V_310 = - V_99 ;
goto V_312;
}
V_146 = F_67 ( V_6 ) ;
if ( V_146 <= 0 ) {
V_310 = 0 ;
goto V_312;
}
if ( V_94 > ( T_3 ) V_146 )
V_94 = V_146 ;
V_144 = V_6 -> V_122 -> V_144 + V_94 ;
if ( V_144 >= ( T_6 ) V_6 -> V_128 )
V_144 -= V_6 -> V_128 ;
V_6 -> V_122 -> V_144 = V_144 ;
V_310 = V_94 ;
V_312:
F_37 ( V_3 ) ;
return V_310 ;
}
static int F_215 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_30 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_148 :
if ( V_3 -> V_14 == V_302 )
goto V_313;
case V_147 :
if ( ( V_30 = F_64 ( V_3 ) ) < 0 )
break;
case V_98 :
case V_196 :
V_30 = 0 ;
break;
case V_209 :
V_30 = - V_172 ;
break;
default:
V_313:
V_30 = - V_99 ;
break;
}
F_37 ( V_3 ) ;
return V_30 ;
}
static int F_216 ( struct V_2 * V_3 ,
T_6 T_2 * V_153 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_30 ;
T_6 V_314 = 0 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_148 :
if ( V_3 -> V_14 == V_302 )
goto V_313;
case V_147 :
if ( ( V_30 = F_64 ( V_3 ) ) < 0 )
break;
case V_98 :
case V_196 :
V_30 = 0 ;
if ( V_3 -> V_14 == V_135 )
V_314 = F_210 ( V_6 ) ;
else
V_314 = F_67 ( V_6 ) ;
V_314 += V_6 -> V_149 ;
break;
case V_209 :
V_30 = - V_172 ;
break;
default:
V_313:
V_30 = - V_99 ;
break;
}
F_37 ( V_3 ) ;
if ( ! V_30 )
if ( F_217 ( V_314 , V_153 ) )
V_30 = - V_33 ;
return V_30 ;
}
static int F_218 ( struct V_2 * V_3 ,
struct F_218 T_2 * V_315 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct F_218 V_316 ;
volatile struct V_317 * V_92 ;
volatile struct V_318 * V_122 ;
int V_30 ;
memset ( & V_316 , 0 , sizeof( V_316 ) ) ;
if ( F_219 ( V_316 . V_79 , ( unsigned T_2 * ) & ( V_315 -> V_79 ) ) )
return - V_33 ;
if ( F_62 ( & V_316 . V_319 . V_122 , & ( V_315 -> V_319 . V_122 ) , sizeof( struct V_318 ) ) )
return - V_33 ;
V_92 = V_6 -> V_92 ;
V_122 = V_6 -> V_122 ;
if ( V_316 . V_79 & V_320 ) {
V_30 = F_215 ( V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
}
F_36 ( V_3 ) ;
if ( ! ( V_316 . V_79 & V_321 ) )
V_122 -> V_144 = V_316 . V_319 . V_122 . V_144 ;
else
V_316 . V_319 . V_122 . V_144 = V_122 -> V_144 ;
if ( ! ( V_316 . V_79 & V_322 ) )
V_122 -> V_123 = V_316 . V_319 . V_122 . V_123 ;
else
V_316 . V_319 . V_122 . V_123 = V_122 -> V_123 ;
V_316 . V_159 . V_92 . V_91 = V_92 -> V_91 ;
V_316 . V_159 . V_92 . V_145 = V_92 -> V_145 ;
V_316 . V_159 . V_92 . V_141 = V_92 -> V_141 ;
V_316 . V_159 . V_92 . V_137 = V_92 -> V_137 ;
F_37 ( V_3 ) ;
if ( F_10 ( V_315 , & V_316 , sizeof( V_316 ) ) )
return - V_33 ;
return 0 ;
}
static int F_220 ( struct V_2 * V_3 , int T_2 * V_323 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_324 ;
if ( F_219 ( V_324 , V_323 ) )
return - V_33 ;
if ( V_324 < 0 || V_324 > V_325 )
return - V_62 ;
V_6 -> V_326 = V_327 ;
if ( V_324 == V_328 )
V_6 -> V_326 = V_328 ;
return 0 ;
}
static int F_221 ( struct V_218 * V_218 ,
struct V_2 * V_3 ,
unsigned int V_329 , void T_2 * V_324 )
{
switch ( V_329 ) {
case V_330 :
return F_217 ( V_331 , ( int T_2 * ) V_324 ) ? - V_33 : 0 ;
case V_332 :
return F_8 ( V_3 , V_324 ) ;
case V_333 :
return 0 ;
case V_334 :
return F_220 ( V_3 , V_324 ) ;
case V_335 :
return F_30 ( V_3 , V_324 ) ;
case V_336 :
return F_55 ( V_3 , V_324 ) ;
case V_337 :
return F_56 ( V_3 ) ;
case V_338 :
return F_61 ( V_3 , V_324 ) ;
case V_339 :
return F_68 ( V_3 , V_324 ) ;
case V_340 :
return F_70 ( V_3 , V_324 ) ;
case V_341 :
return F_128 ( V_3 , V_218 ) ;
case V_342 :
return F_124 ( V_3 ) ;
case V_343 :
return F_81 ( & V_182 , V_3 , V_147 ) ;
case V_344 :
return F_150 ( V_3 , ( int ) ( unsigned long ) V_324 ) ;
case V_345 :
return F_160 ( V_3 ) ;
case V_346 :
return F_116 ( V_3 ) ;
case V_347 :
return F_120 ( V_3 ) ;
case V_348 :
return F_215 ( V_3 ) ;
case V_349 :
return F_216 ( V_3 , V_324 ) ;
case V_350 :
return F_218 ( V_3 , V_324 ) ;
#ifdef F_222
case V_351 :
return F_223 ( V_3 , V_324 ) ;
case V_352 :
return F_224 ( V_3 , V_324 ) ;
#endif
case V_353 :
return F_133 ( V_3 , V_218 ) ;
case V_354 :
return F_141 ( V_3 ) ;
case V_355 :
{
int V_153 ;
F_36 ( V_3 ) ;
V_153 = F_104 ( V_3 , ( int ) ( unsigned long ) V_324 ) ;
F_37 ( V_3 ) ;
return V_153 ;
}
}
F_140 ( L_15 , V_329 ) ;
return - V_356 ;
}
static int F_225 ( struct V_218 * V_218 ,
struct V_2 * V_3 ,
unsigned int V_329 , void T_2 * V_324 )
{
if ( F_208 ( ! V_3 ) )
return - V_95 ;
if ( F_208 ( V_3 -> V_14 != V_135 ) )
return - V_62 ;
switch ( V_329 ) {
case V_357 :
{
struct V_358 V_359 ;
struct V_358 T_2 * V_360 = V_324 ;
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_133 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( F_217 ( 0 , & V_360 -> V_133 ) )
return - V_33 ;
if ( F_62 ( & V_359 , V_360 , sizeof( V_359 ) ) )
return - V_33 ;
V_133 = F_226 ( V_3 , V_359 . V_361 , V_359 . V_94 ) ;
F_227 ( V_133 , & V_360 -> V_133 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
case V_362 :
{
struct V_363 V_364 ;
struct V_363 T_2 * V_365 = V_324 ;
struct V_5 * V_6 = V_3 -> V_6 ;
void T_2 * * V_366 ;
T_6 V_133 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( V_6 -> V_109 > 128 )
return - V_62 ;
if ( F_217 ( 0 , & V_365 -> V_133 ) )
return - V_33 ;
if ( F_62 ( & V_364 , V_365 , sizeof( V_364 ) ) )
return - V_33 ;
V_366 = F_31 ( V_364 . V_366 ,
sizeof( void * ) * V_6 -> V_109 ) ;
if ( F_32 ( V_366 ) )
return F_33 ( V_366 ) ;
V_133 = F_228 ( V_3 , V_366 , V_364 . V_94 ) ;
F_11 ( V_366 ) ;
F_227 ( V_133 , & V_365 -> V_133 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
case V_367 :
{
T_3 V_94 ;
T_3 T_2 * V_368 = V_324 ;
T_6 V_133 ;
if ( F_219 ( V_94 , V_368 ) )
return - V_33 ;
if ( F_217 ( 0 , V_368 ) )
return - V_33 ;
V_133 = F_209 ( V_3 , V_94 ) ;
F_227 ( V_133 , V_368 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
case V_369 :
{
T_3 V_94 ;
T_3 T_2 * V_368 = V_324 ;
T_6 V_133 ;
if ( F_219 ( V_94 , V_368 ) )
return - V_33 ;
if ( F_217 ( 0 , V_368 ) )
return - V_33 ;
V_133 = F_213 ( V_3 , V_94 ) ;
F_227 ( V_133 , V_368 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
}
return F_221 ( V_218 , V_3 , V_329 , V_324 ) ;
}
static int F_229 ( struct V_218 * V_218 ,
struct V_2 * V_3 ,
unsigned int V_329 , void T_2 * V_324 )
{
if ( F_208 ( ! V_3 ) )
return - V_95 ;
if ( F_208 ( V_3 -> V_14 != V_302 ) )
return - V_62 ;
switch ( V_329 ) {
case V_370 :
{
struct V_358 V_359 ;
struct V_358 T_2 * V_360 = V_324 ;
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_133 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( F_217 ( 0 , & V_360 -> V_133 ) )
return - V_33 ;
if ( F_62 ( & V_359 , V_360 , sizeof( V_359 ) ) )
return - V_33 ;
V_133 = F_230 ( V_3 , V_359 . V_361 , V_359 . V_94 ) ;
F_227 ( V_133 , & V_360 -> V_133 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
case V_371 :
{
struct V_363 V_364 ;
struct V_363 T_2 * V_365 = V_324 ;
struct V_5 * V_6 = V_3 -> V_6 ;
void * V_366 ;
T_6 V_133 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( V_6 -> V_109 > 128 )
return - V_62 ;
if ( F_217 ( 0 , & V_365 -> V_133 ) )
return - V_33 ;
if ( F_62 ( & V_364 , V_365 , sizeof( V_364 ) ) )
return - V_33 ;
V_366 = F_31 ( V_364 . V_366 ,
sizeof( void * ) * V_6 -> V_109 ) ;
if ( F_32 ( V_366 ) )
return F_33 ( V_366 ) ;
V_133 = F_231 ( V_3 , V_366 , V_364 . V_94 ) ;
F_11 ( V_366 ) ;
F_227 ( V_133 , & V_365 -> V_133 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
case V_367 :
{
T_3 V_94 ;
T_3 T_2 * V_368 = V_324 ;
T_6 V_133 ;
if ( F_219 ( V_94 , V_368 ) )
return - V_33 ;
if ( F_217 ( 0 , V_368 ) )
return - V_33 ;
V_133 = F_211 ( V_3 , V_94 ) ;
F_227 ( V_133 , V_368 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
case V_369 :
{
T_3 V_94 ;
T_3 T_2 * V_368 = V_324 ;
T_6 V_133 ;
if ( F_219 ( V_94 , V_368 ) )
return - V_33 ;
if ( F_217 ( 0 , V_368 ) )
return - V_33 ;
V_133 = F_214 ( V_3 , V_94 ) ;
F_227 ( V_133 , V_368 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
}
return F_221 ( V_218 , V_3 , V_329 , V_324 ) ;
}
static long F_232 ( struct V_218 * V_218 , unsigned int V_329 ,
unsigned long V_324 )
{
struct V_245 * V_246 ;
V_246 = V_218 -> V_249 ;
if ( ( ( V_329 >> 8 ) & 0xff ) != 'A' )
return - V_356 ;
return F_225 ( V_218 , V_246 -> V_3 , V_329 ,
( void T_2 * ) V_324 ) ;
}
static long F_233 ( struct V_218 * V_218 , unsigned int V_329 ,
unsigned long V_324 )
{
struct V_245 * V_246 ;
V_246 = V_218 -> V_249 ;
if ( ( ( V_329 >> 8 ) & 0xff ) != 'A' )
return - V_356 ;
return F_229 ( V_218 , V_246 -> V_3 , V_329 ,
( void T_2 * ) V_324 ) ;
}
int F_234 ( struct V_2 * V_3 ,
unsigned int V_329 , void * V_324 )
{
T_1 V_1 ;
int V_133 ;
V_1 = F_1 () ;
switch ( V_3 -> V_14 ) {
case V_135 :
V_133 = F_225 ( NULL , V_3 , V_329 ,
( void T_2 * ) V_324 ) ;
break;
case V_302 :
V_133 = F_229 ( NULL , V_3 , V_329 ,
( void T_2 * ) V_324 ) ;
break;
default:
V_133 = - V_62 ;
break;
}
F_5 ( V_1 ) ;
return V_133 ;
}
static T_7 F_235 ( struct V_218 * V_218 , char T_2 * V_361 , T_8 V_254 ,
T_9 * V_372 )
{
struct V_245 * V_246 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_133 ;
V_246 = V_218 -> V_249 ;
V_3 = V_246 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( ! F_236 ( V_6 , V_254 ) )
return - V_62 ;
V_254 = F_237 ( V_6 , V_254 ) ;
V_133 = F_230 ( V_3 , V_361 , V_254 ) ;
if ( V_133 > 0 )
V_133 = F_238 ( V_6 , V_133 ) ;
return V_133 ;
}
static T_7 F_239 ( struct V_218 * V_218 , const char T_2 * V_361 ,
T_8 V_254 , T_9 * V_372 )
{
struct V_245 * V_246 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_133 ;
V_246 = V_218 -> V_249 ;
V_3 = V_246 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( ! F_236 ( V_6 , V_254 ) )
return - V_62 ;
V_254 = F_237 ( V_6 , V_254 ) ;
V_133 = F_226 ( V_3 , V_361 , V_254 ) ;
if ( V_133 > 0 )
V_133 = F_238 ( V_6 , V_133 ) ;
return V_133 ;
}
static T_7 F_240 ( struct V_373 * V_374 , const struct V_375 * V_376 ,
unsigned long V_377 , T_9 V_378 )
{
struct V_245 * V_246 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_133 ;
unsigned long V_40 ;
void T_2 * * V_366 ;
T_3 V_94 ;
V_246 = V_374 -> V_379 -> V_249 ;
V_3 = V_246 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( V_377 > 1024 || V_377 != V_6 -> V_109 )
return - V_62 ;
if ( ! F_236 ( V_6 , V_376 -> V_380 ) )
return - V_62 ;
V_94 = F_241 ( V_6 , V_376 -> V_380 ) ;
V_366 = F_9 ( sizeof( void * ) * V_377 , V_31 ) ;
if ( V_366 == NULL )
return - V_32 ;
for ( V_40 = 0 ; V_40 < V_377 ; ++ V_40 )
V_366 [ V_40 ] = V_376 [ V_40 ] . V_381 ;
V_133 = F_231 ( V_3 , V_366 , V_94 ) ;
if ( V_133 > 0 )
V_133 = F_238 ( V_6 , V_133 ) ;
F_11 ( V_366 ) ;
return V_133 ;
}
static T_7 F_242 ( struct V_373 * V_374 , const struct V_375 * V_376 ,
unsigned long V_377 , T_9 V_378 )
{
struct V_245 * V_246 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_133 ;
unsigned long V_40 ;
void T_2 * * V_366 ;
T_3 V_94 ;
V_246 = V_374 -> V_379 -> V_249 ;
V_3 = V_246 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( V_377 > 128 || V_377 != V_6 -> V_109 ||
! F_236 ( V_6 , V_376 -> V_380 ) )
return - V_62 ;
V_94 = F_241 ( V_6 , V_376 -> V_380 ) ;
V_366 = F_9 ( sizeof( void * ) * V_377 , V_31 ) ;
if ( V_366 == NULL )
return - V_32 ;
for ( V_40 = 0 ; V_40 < V_377 ; ++ V_40 )
V_366 [ V_40 ] = V_376 [ V_40 ] . V_381 ;
V_133 = F_228 ( V_3 , V_366 , V_94 ) ;
if ( V_133 > 0 )
V_133 = F_238 ( V_6 , V_133 ) ;
F_11 ( V_366 ) ;
return V_133 ;
}
static unsigned int F_243 ( struct V_218 * V_218 , T_10 * V_221 )
{
struct V_245 * V_246 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
unsigned int V_257 ;
T_3 V_146 ;
V_246 = V_218 -> V_249 ;
V_3 = V_246 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
F_244 ( V_218 , & V_6 -> V_184 , V_221 ) ;
F_36 ( V_3 ) ;
V_146 = F_66 ( V_6 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_147 :
case V_98 :
case V_190 :
if ( V_146 >= V_6 -> V_122 -> V_123 ) {
V_257 = V_382 | V_383 ;
break;
}
case V_148 :
V_257 = 0 ;
break;
default:
V_257 = V_382 | V_383 | V_384 ;
break;
}
F_37 ( V_3 ) ;
return V_257 ;
}
static unsigned int F_245 ( struct V_218 * V_218 , T_10 * V_221 )
{
struct V_245 * V_246 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
unsigned int V_257 ;
T_3 V_146 ;
V_246 = V_218 -> V_249 ;
V_3 = V_246 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
F_244 ( V_218 , & V_6 -> V_184 , V_221 ) ;
F_36 ( V_3 ) ;
V_146 = F_67 ( V_6 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_147 :
case V_98 :
case V_190 :
if ( V_146 >= V_6 -> V_122 -> V_123 ) {
V_257 = V_385 | V_386 ;
break;
}
V_257 = 0 ;
break;
case V_148 :
if ( V_146 > 0 ) {
V_257 = V_385 | V_386 ;
break;
}
default:
V_257 = V_385 | V_386 | V_384 ;
break;
}
F_37 ( V_3 ) ;
return V_257 ;
}
static int F_246 ( struct V_387 * V_388 ,
struct V_389 * V_390 )
{
struct V_2 * V_3 = V_388 -> V_391 ;
struct V_5 * V_6 ;
if ( V_3 == NULL )
return V_392 ;
V_6 = V_3 -> V_6 ;
V_390 -> V_393 = F_247 ( V_6 -> V_92 ) ;
F_248 ( V_390 -> V_393 ) ;
return 0 ;
}
static int V_317 ( struct V_2 * V_3 , struct V_218 * V_218 ,
struct V_387 * V_388 )
{
long V_394 ;
if ( ! ( V_388 -> V_395 & V_396 ) )
return - V_62 ;
V_394 = V_388 -> V_397 - V_388 -> V_398 ;
if ( V_394 != F_249 ( sizeof( struct V_317 ) ) )
return - V_62 ;
V_388 -> V_399 = & V_400 ;
V_388 -> V_391 = V_3 ;
V_388 -> V_395 |= V_401 | V_402 ;
return 0 ;
}
static int F_250 ( struct V_387 * V_388 ,
struct V_389 * V_390 )
{
struct V_2 * V_3 = V_388 -> V_391 ;
struct V_5 * V_6 ;
if ( V_3 == NULL )
return V_392 ;
V_6 = V_3 -> V_6 ;
V_390 -> V_393 = F_247 ( V_6 -> V_122 ) ;
F_248 ( V_390 -> V_393 ) ;
return 0 ;
}
static int V_318 ( struct V_2 * V_3 , struct V_218 * V_218 ,
struct V_387 * V_388 )
{
long V_394 ;
if ( ! ( V_388 -> V_395 & V_396 ) )
return - V_62 ;
V_394 = V_388 -> V_397 - V_388 -> V_398 ;
if ( V_394 != F_249 ( sizeof( struct V_318 ) ) )
return - V_62 ;
V_388 -> V_399 = & V_403 ;
V_388 -> V_391 = V_3 ;
V_388 -> V_395 |= V_401 | V_402 ;
return 0 ;
}
static int V_317 ( struct V_2 * V_3 , struct V_218 * V_218 ,
struct V_387 * V_388 )
{
return - V_95 ;
}
static int V_318 ( struct V_2 * V_3 , struct V_218 * V_218 ,
struct V_387 * V_388 )
{
return - V_95 ;
}
static inline struct V_393 *
F_251 ( struct V_2 * V_3 , unsigned long V_404 )
{
void * V_405 = V_3 -> V_6 -> V_406 + V_404 ;
#if F_39 ( V_407 ) && F_39 ( V_408 )
if ( V_3 -> V_409 . V_410 . type == V_411 )
return F_247 ( F_252 ( V_405 ) ) ;
#endif
#if F_39 ( V_412 ) && F_39 ( V_413 )
if ( V_3 -> V_409 . V_410 . type == V_411 ) {
T_11 V_414 = V_3 -> V_6 -> V_415 + V_404 ;
V_414 -= F_253 ( V_3 -> V_409 . V_410 . V_410 ) ;
return F_254 ( V_414 >> V_416 ) ;
}
#endif
return F_247 ( V_405 ) ;
}
static int F_255 ( struct V_387 * V_388 ,
struct V_389 * V_390 )
{
struct V_2 * V_3 = V_388 -> V_391 ;
struct V_5 * V_6 ;
unsigned long V_372 ;
struct V_393 * V_393 ;
T_8 V_293 ;
if ( V_3 == NULL )
return V_392 ;
V_6 = V_3 -> V_6 ;
V_372 = V_390 -> V_417 << V_416 ;
V_293 = F_249 ( V_6 -> V_293 ) ;
if ( V_372 > V_293 - V_418 )
return V_392 ;
if ( V_3 -> V_26 -> V_393 )
V_393 = V_3 -> V_26 -> V_393 ( V_3 , V_372 ) ;
else
V_393 = F_251 ( V_3 , V_372 ) ;
if ( ! V_393 )
return V_392 ;
F_248 ( V_393 ) ;
V_390 -> V_393 = V_393 ;
return 0 ;
}
int F_256 ( struct V_2 * V_3 ,
struct V_387 * V_388 )
{
V_388 -> V_395 |= V_401 | V_402 ;
#ifdef F_257
if ( ! V_3 -> V_26 -> V_393 &&
V_3 -> V_409 . V_410 . type == V_411 )
return F_258 ( V_3 -> V_409 . V_410 . V_410 ,
V_388 ,
V_3 -> V_6 -> V_406 ,
V_3 -> V_6 -> V_415 ,
V_388 -> V_397 - V_388 -> V_398 ) ;
#elif F_39 ( V_407 ) && F_39 ( V_408 )
if ( V_3 -> V_409 . V_410 . type == V_411 &&
! F_259 ( V_3 -> V_409 . V_410 . V_410 ) )
V_388 -> V_419 = F_260 ( V_388 -> V_419 ) ;
#endif
V_388 -> V_399 = & V_420 ;
return 0 ;
}
int F_261 ( struct V_2 * V_3 ,
struct V_387 * V_388 )
{
struct V_5 * V_6 = V_3 -> V_6 ; ;
V_388 -> V_419 = F_260 ( V_388 -> V_419 ) ;
return F_262 ( V_388 , V_6 -> V_415 , V_6 -> V_293 ) ;
}
int F_263 ( struct V_2 * V_3 , struct V_218 * V_218 ,
struct V_387 * V_388 )
{
struct V_5 * V_6 ;
long V_394 ;
unsigned long V_372 ;
T_8 V_293 ;
int V_30 ;
if ( V_3 -> V_14 == V_135 ) {
if ( ! ( V_388 -> V_395 & ( V_421 | V_396 ) ) )
return - V_62 ;
} else {
if ( ! ( V_388 -> V_395 & V_396 ) )
return - V_62 ;
}
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( ! ( V_6 -> V_4 & V_276 ) )
return - V_95 ;
if ( V_6 -> V_106 == V_273 ||
V_6 -> V_106 == V_275 )
return - V_62 ;
V_394 = V_388 -> V_397 - V_388 -> V_398 ;
V_372 = V_388 -> V_422 << V_416 ;
V_293 = F_249 ( V_6 -> V_293 ) ;
if ( ( T_8 ) V_394 > V_293 )
return - V_62 ;
if ( V_372 > V_293 - V_394 )
return - V_62 ;
V_388 -> V_399 = & V_423 ;
V_388 -> V_391 = V_3 ;
if ( V_3 -> V_26 -> V_424 )
V_30 = V_3 -> V_26 -> V_424 ( V_3 , V_388 ) ;
else
V_30 = F_256 ( V_3 , V_388 ) ;
if ( ! V_30 )
F_264 ( & V_3 -> V_103 ) ;
return V_30 ;
}
static int F_265 ( struct V_218 * V_218 , struct V_387 * V_388 )
{
struct V_245 * V_246 ;
struct V_2 * V_3 ;
unsigned long V_372 ;
V_246 = V_218 -> V_249 ;
V_3 = V_246 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_372 = V_388 -> V_422 << V_416 ;
switch ( V_372 ) {
case V_425 :
if ( V_246 -> V_426 )
return - V_95 ;
return V_317 ( V_3 , V_218 , V_388 ) ;
case V_427 :
if ( V_246 -> V_426 )
return - V_95 ;
return V_318 ( V_3 , V_218 , V_388 ) ;
default:
return F_263 ( V_3 , V_218 , V_388 ) ;
}
return 0 ;
}
static int F_266 ( int V_237 , struct V_218 * V_218 , int V_428 )
{
struct V_245 * V_246 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
V_246 = V_218 -> V_249 ;
V_3 = V_246 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
return F_267 ( V_237 , V_218 , V_428 , & V_6 -> V_429 ) ;
}
static void F_268 ( struct V_34 * V_35 ,
struct V_430 * V_431 )
{
unsigned int V_40 ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
V_35 -> V_79 = V_431 -> V_79 ;
for ( V_40 = 0 ; V_40 < F_269 ( V_431 -> V_432 ) ; V_40 ++ )
V_35 -> V_432 [ V_40 ] . V_65 [ 0 ] = V_431 -> V_432 [ V_40 ] ;
memcpy ( V_35 -> V_433 , V_431 -> V_433 , sizeof( V_431 -> V_433 ) ) ;
V_35 -> V_54 = F_270 ( V_431 -> V_54 ) ;
V_35 -> V_66 = F_270 ( V_431 -> V_66 ) ;
V_35 -> V_4 = V_431 -> V_4 ;
V_35 -> V_56 = V_431 -> V_56 ;
V_35 -> V_58 = V_431 -> V_58 ;
V_35 -> V_59 = V_431 -> V_59 ;
V_35 -> V_53 = V_431 -> V_53 ;
}
static void F_271 ( struct V_430 * V_431 ,
struct V_34 * V_35 )
{
unsigned int V_40 ;
memset ( V_431 , 0 , sizeof( * V_431 ) ) ;
V_431 -> V_79 = V_35 -> V_79 ;
for ( V_40 = 0 ; V_40 < F_269 ( V_431 -> V_432 ) ; V_40 ++ )
V_431 -> V_432 [ V_40 ] = V_35 -> V_432 [ V_40 ] . V_65 [ 0 ] ;
memcpy ( V_431 -> V_433 , V_35 -> V_433 , sizeof( V_431 -> V_433 ) ) ;
V_431 -> V_54 = F_272 ( V_35 -> V_54 ) ;
V_431 -> V_66 = F_272 ( V_35 -> V_66 ) ;
V_431 -> V_4 = V_35 -> V_4 ;
V_431 -> V_56 = V_35 -> V_56 ;
V_431 -> V_58 = V_35 -> V_58 ;
V_431 -> V_59 = V_35 -> V_59 ;
V_431 -> V_53 = V_35 -> V_53 ;
}
static int F_223 ( struct V_2 * V_3 ,
struct V_430 T_2 * V_434 )
{
struct V_34 * V_35 ;
struct V_430 * V_431 = NULL ;
int V_30 ;
V_35 = F_9 ( sizeof( * V_35 ) , V_31 ) ;
if ( ! V_35 )
return - V_32 ;
V_431 = F_31 ( V_434 , sizeof( * V_431 ) ) ;
if ( F_32 ( V_431 ) ) {
V_30 = F_33 ( V_431 ) ;
goto V_435;
}
F_268 ( V_35 , V_431 ) ;
V_30 = F_12 ( V_3 , V_35 ) ;
F_271 ( V_431 , V_35 ) ;
if ( F_10 ( V_434 , V_431 , sizeof( * V_431 ) ) ) {
if ( ! V_30 )
V_30 = - V_33 ;
}
F_11 ( V_431 ) ;
V_435:
F_11 ( V_35 ) ;
return V_30 ;
}
static int F_224 ( struct V_2 * V_3 ,
struct V_430 T_2 * V_434 )
{
struct V_34 * V_35 ;
struct V_430 * V_431 = NULL ;
int V_30 ;
V_35 = F_9 ( sizeof( * V_35 ) , V_31 ) ;
if ( ! V_35 )
return - V_32 ;
V_431 = F_31 ( V_434 , sizeof( * V_431 ) ) ;
if ( F_32 ( V_431 ) ) {
V_30 = F_33 ( V_431 ) ;
goto V_435;
}
F_268 ( V_35 , V_431 ) ;
V_30 = V_34 ( V_3 , V_35 ) ;
F_271 ( V_431 , V_35 ) ;
if ( F_10 ( V_434 , V_431 , sizeof( * V_431 ) ) ) {
if ( ! V_30 )
V_30 = - V_33 ;
}
F_11 ( V_431 ) ;
V_435:
F_11 ( V_35 ) ;
return V_30 ;
}
static unsigned long F_273 ( struct V_218 * V_218 ,
unsigned long V_414 ,
unsigned long V_436 ,
unsigned long V_417 ,
unsigned long V_79 )
{
struct V_245 * V_246 = V_218 -> V_249 ;
struct V_2 * V_3 = V_246 -> V_3 ;
struct V_5 * V_6 = V_3 -> V_6 ;
unsigned long V_372 = V_417 << V_416 ;
switch ( V_372 ) {
case V_425 :
return ( unsigned long ) V_6 -> V_92 ;
case V_427 :
return ( unsigned long ) V_6 -> V_122 ;
default:
return ( unsigned long ) V_6 -> V_406 + V_372 ;
}
}
