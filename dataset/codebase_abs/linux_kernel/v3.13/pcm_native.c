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
static bool F_142 ( struct V_218 * V_218 )
{
struct V_237 * V_237 = F_143 ( V_218 ) ;
unsigned int V_238 ;
if ( ! F_144 ( V_237 -> V_239 ) || F_145 ( V_237 ) != V_240 )
return false ;
V_238 = F_146 ( V_237 ) ;
return F_147 ( V_238 , V_241 ) ||
F_147 ( V_238 , V_242 ) ;
}
static int F_148 ( struct V_2 * V_3 , int V_243 )
{
int V_153 = 0 ;
struct V_244 * V_245 ;
struct V_2 * V_246 ;
struct V_247 * V_169 ;
struct V_243 V_248 = F_149 ( V_243 ) ;
if ( ! V_248 . V_218 )
return - V_99 ;
if ( ! F_142 ( V_248 . V_218 ) ) {
V_153 = - V_99 ;
goto V_249;
}
V_245 = V_248 . V_218 -> V_250 ;
V_246 = V_245 -> V_3 ;
V_169 = F_9 ( sizeof( * V_169 ) , V_31 ) ;
if ( ! V_169 ) {
V_153 = - V_32 ;
goto V_251;
}
F_150 ( & V_171 ) ;
F_151 ( & V_170 ) ;
if ( V_3 -> V_6 -> V_92 -> V_91 == V_96 ||
V_3 -> V_6 -> V_92 -> V_91 != V_246 -> V_6 -> V_92 -> V_91 ) {
V_153 = - V_99 ;
goto V_138;
}
if ( F_78 ( V_246 ) ) {
V_153 = - V_252 ;
goto V_138;
}
if ( ! F_78 ( V_3 ) ) {
V_3 -> V_169 = V_169 ;
V_169 = NULL ;
F_152 ( & V_3 -> V_169 -> V_162 ) ;
F_153 ( & V_3 -> V_169 -> V_253 ) ;
F_154 ( & V_3 -> V_254 , & V_3 -> V_169 -> V_253 ) ;
V_3 -> V_169 -> V_255 = 1 ;
}
F_154 ( & V_246 -> V_254 , & V_3 -> V_169 -> V_253 ) ;
V_3 -> V_169 -> V_255 ++ ;
V_246 -> V_169 = V_3 -> V_169 ;
V_138:
F_155 ( & V_170 ) ;
F_156 ( & V_171 ) ;
V_251:
F_157 ( V_246 -> V_8 -> V_11 ) ;
F_11 ( V_169 ) ;
V_249:
F_158 ( V_248 ) ;
return V_153 ;
}
static void F_159 ( struct V_2 * V_3 )
{
V_3 -> V_169 = & V_3 -> V_161 ;
F_153 ( & V_3 -> V_161 . V_253 ) ;
F_154 ( & V_3 -> V_254 , & V_3 -> V_161 . V_253 ) ;
}
static int F_160 ( struct V_2 * V_3 )
{
struct V_2 * V_159 ;
int V_153 = 0 ;
F_150 ( & V_171 ) ;
F_151 ( & V_170 ) ;
if ( ! F_78 ( V_3 ) ) {
V_153 = - V_252 ;
goto V_138;
}
F_161 ( & V_3 -> V_254 ) ;
V_3 -> V_169 -> V_255 -- ;
if ( V_3 -> V_169 -> V_255 == 1 ) {
F_73 (s, substream) {
F_159 ( V_159 ) ;
break;
}
F_11 ( V_3 -> V_169 ) ;
}
F_159 ( V_3 ) ;
V_138:
F_155 ( & V_170 ) ;
F_156 ( & V_171 ) ;
return V_153 ;
}
static int F_162 ( struct V_34 * V_35 ,
struct V_73 * V_256 )
{
struct V_39 V_232 ;
F_163 ( F_164 ( V_35 , V_256 -> V_80 [ 0 ] ) ,
F_164 ( V_35 , V_256 -> V_80 [ 1 ] ) , & V_232 ) ;
return F_21 ( F_19 ( V_35 , V_256 -> V_82 ) , & V_232 ) ;
}
static int F_165 ( struct V_34 * V_35 ,
struct V_73 * V_256 )
{
struct V_39 V_232 ;
F_166 ( F_164 ( V_35 , V_256 -> V_80 [ 0 ] ) ,
F_164 ( V_35 , V_256 -> V_80 [ 1 ] ) , & V_232 ) ;
return F_21 ( F_19 ( V_35 , V_256 -> V_82 ) , & V_232 ) ;
}
static int F_167 ( struct V_34 * V_35 ,
struct V_73 * V_256 )
{
struct V_39 V_232 ;
F_168 ( F_164 ( V_35 , V_256 -> V_80 [ 0 ] ) ,
F_164 ( V_35 , V_256 -> V_80 [ 1 ] ) ,
( unsigned long ) V_256 -> V_257 , & V_232 ) ;
return F_21 ( F_19 ( V_35 , V_256 -> V_82 ) , & V_232 ) ;
}
static int F_169 ( struct V_34 * V_35 ,
struct V_73 * V_256 )
{
struct V_39 V_232 ;
F_170 ( F_164 ( V_35 , V_256 -> V_80 [ 0 ] ) ,
( unsigned long ) V_256 -> V_257 ,
F_164 ( V_35 , V_256 -> V_80 [ 1 ] ) , & V_232 ) ;
return F_21 ( F_19 ( V_35 , V_256 -> V_82 ) , & V_232 ) ;
}
static int F_171 ( struct V_34 * V_35 ,
struct V_73 * V_256 )
{
unsigned int V_36 ;
struct V_39 * V_40 = F_19 ( V_35 , V_256 -> V_80 [ 0 ] ) ;
struct V_41 V_42 ;
struct V_41 * V_258 = F_13 ( V_35 , V_84 ) ;
F_172 ( & V_42 ) ;
for ( V_36 = 0 ; V_36 <= V_259 ; ++ V_36 ) {
int V_65 ;
if ( ! F_173 ( V_258 , V_36 ) )
continue;
V_65 = F_50 ( V_36 ) ;
if ( V_65 <= 0 )
continue;
if ( ( unsigned ) V_65 < V_40 -> V_70 || ( unsigned ) V_65 > V_40 -> V_71 )
F_174 ( & V_42 , V_36 ) ;
}
return F_17 ( V_258 , & V_42 ) ;
}
static int F_175 ( struct V_34 * V_35 ,
struct V_73 * V_256 )
{
struct V_39 V_232 ;
unsigned int V_36 ;
V_232 . V_70 = V_260 ;
V_232 . V_71 = 0 ;
V_232 . V_69 = 0 ;
V_232 . V_72 = 0 ;
for ( V_36 = 0 ; V_36 <= V_259 ; ++ V_36 ) {
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
return F_21 ( F_19 ( V_35 , V_256 -> V_82 ) , & V_232 ) ;
}
static int F_176 ( struct V_34 * V_35 ,
struct V_73 * V_256 )
{
struct V_37 * V_38 = V_256 -> V_257 ;
return F_177 ( F_19 ( V_35 , V_256 -> V_82 ) ,
V_261 . V_255 ,
V_261 . V_262 , V_38 -> V_263 ) ;
}
static int F_178 ( struct V_34 * V_35 ,
struct V_73 * V_256 )
{
struct V_39 V_232 ;
struct V_2 * V_3 = V_256 -> V_257 ;
V_232 . V_70 = 0 ;
V_232 . V_71 = V_3 -> V_264 ;
V_232 . V_69 = 0 ;
V_232 . V_72 = 0 ;
V_232 . integer = 1 ;
return F_21 ( F_19 ( V_35 , V_256 -> V_82 ) , & V_232 ) ;
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
F_181 ( F_22 ( V_44 , V_265 ) ) ;
F_181 ( F_22 ( V_44 , V_266 ) ) ;
F_181 ( F_22 ( V_44 , V_55 ) ) ;
F_181 ( F_22 ( V_44 , V_267 ) ) ;
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
V_267 , V_85 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_267 ,
F_162 , NULL ,
V_55 , V_85 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_267 ,
F_169 , ( void * ) 8 ,
V_268 , V_269 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_267 ,
F_169 , ( void * ) 8 ,
V_266 , V_265 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_85 ,
F_165 , NULL ,
V_267 , V_55 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_57 ,
F_169 , ( void * ) 1000000 ,
V_269 , V_270 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_57 ,
F_169 , ( void * ) 1000000 ,
V_265 , V_271 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_272 ,
F_165 , NULL ,
V_265 , V_269 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_269 ,
F_165 , NULL ,
V_265 , V_272 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_269 ,
F_169 , ( void * ) 8 ,
V_268 , V_267 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_269 ,
F_167 , ( void * ) 1000000 ,
V_270 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_265 ,
F_162 , NULL ,
V_269 , V_272 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_265 ,
F_169 , ( void * ) 8 ,
V_266 , V_267 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_265 ,
F_167 , ( void * ) 1000000 ,
V_271 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_268 ,
F_167 , ( void * ) 8 ,
V_269 , V_267 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_266 ,
F_167 , ( void * ) 8 ,
V_265 , V_267 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_270 ,
F_169 , ( void * ) 1000000 ,
V_269 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_271 ,
F_169 , ( void * ) 1000000 ,
V_265 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
return 0 ;
}
int F_183 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_37 * V_38 = & V_6 -> V_38 ;
int V_30 ;
unsigned int V_258 = 0 ;
if ( V_38 -> V_4 & V_273 )
V_258 |= 1 << V_274 ;
if ( V_38 -> V_4 & V_275 )
V_258 |= 1 << V_276 ;
if ( V_38 -> V_4 & V_277 ) {
if ( V_38 -> V_4 & V_273 )
V_258 |= 1 << V_278 ;
if ( V_38 -> V_4 & V_275 )
V_258 |= 1 << V_279 ;
if ( V_38 -> V_4 & V_280 )
V_258 |= 1 << V_281 ;
}
V_30 = F_184 ( V_6 , V_282 , V_258 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_185 ( V_6 , V_84 , V_38 -> V_283 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_184 ( V_6 , V_284 , 1 << V_285 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_186 ( V_6 , V_85 ,
V_38 -> V_286 , V_38 -> V_287 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_186 ( V_6 , V_57 ,
V_38 -> V_288 , V_38 -> V_289 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_186 ( V_6 , V_268 ,
V_38 -> V_290 , V_38 -> V_291 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_186 ( V_6 , V_272 ,
V_38 -> V_292 , V_38 -> V_293 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_186 ( V_6 , V_266 ,
V_38 -> V_290 , V_38 -> V_264 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , 0 , V_266 ,
F_178 , V_3 ,
V_266 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_6 -> V_294 ) {
V_30 = F_186 ( V_6 , V_266 , 0 , V_6 -> V_294 ) ;
if ( V_30 < 0 )
return V_30 ;
}
if ( ! ( V_38 -> V_263 & ( V_295 | V_296 ) ) ) {
V_30 = F_182 ( V_6 , 0 , V_57 ,
F_176 , V_38 ,
V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
}
F_187 ( V_6 , V_269 ) ;
return 0 ;
}
static void F_188 ( struct V_2 * V_3 )
{
F_160 ( V_3 ) ;
}
void F_189 ( struct V_2 * V_3 )
{
V_3 -> V_297 -- ;
if ( V_3 -> V_297 > 0 )
return;
F_141 ( V_3 ) ;
if ( V_3 -> V_298 ) {
if ( V_3 -> V_26 -> V_132 != NULL )
V_3 -> V_26 -> V_132 ( V_3 ) ;
V_3 -> V_26 -> V_299 ( V_3 ) ;
V_3 -> V_298 = 0 ;
}
if ( F_52 ( & V_3 -> V_130 ) )
F_53 ( & V_3 -> V_130 ) ;
if ( V_3 -> V_300 ) {
V_3 -> V_300 ( V_3 ) ;
V_3 -> V_300 = NULL ;
}
F_190 ( V_3 ) ;
}
int F_191 ( struct V_7 * V_8 , int V_14 ,
struct V_218 * V_218 ,
struct V_2 * * V_301 )
{
struct V_2 * V_3 ;
int V_30 ;
V_30 = F_192 ( V_8 , V_14 , V_218 , & V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_3 -> V_297 > 1 ) {
* V_301 = V_3 ;
return 0 ;
}
V_30 = F_179 ( V_3 ) ;
if ( V_30 < 0 ) {
F_140 ( L_13 ) ;
goto error;
}
if ( ( V_30 = V_3 -> V_26 -> V_302 ( V_3 ) ) < 0 )
goto error;
V_3 -> V_298 = 1 ;
V_30 = F_183 ( V_3 ) ;
if ( V_30 < 0 ) {
F_140 ( L_14 ) ;
goto error;
}
* V_301 = V_3 ;
return 0 ;
error:
F_189 ( V_3 ) ;
return V_30 ;
}
static int F_193 ( struct V_218 * V_218 ,
struct V_7 * V_8 ,
int V_14 )
{
struct V_244 * V_245 ;
struct V_2 * V_3 ;
int V_30 ;
V_30 = F_191 ( V_8 , V_14 , V_218 , & V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
V_245 = F_194 ( sizeof( * V_245 ) , V_31 ) ;
if ( V_245 == NULL ) {
F_189 ( V_3 ) ;
return - V_32 ;
}
V_245 -> V_3 = V_3 ;
if ( V_3 -> V_297 == 1 ) {
V_3 -> V_218 = V_245 ;
V_3 -> V_300 = F_188 ;
}
V_218 -> V_250 = V_245 ;
return 0 ;
}
static int F_195 ( struct V_237 * V_237 , struct V_218 * V_218 )
{
struct V_7 * V_8 ;
int V_30 = F_196 ( V_237 , V_218 ) ;
if ( V_30 < 0 )
return V_30 ;
V_8 = F_147 ( F_146 ( V_237 ) ,
V_241 ) ;
V_30 = F_197 ( V_218 , V_8 , V_135 ) ;
if ( V_8 )
F_157 ( V_8 -> V_11 ) ;
return V_30 ;
}
static int F_198 ( struct V_237 * V_237 , struct V_218 * V_218 )
{
struct V_7 * V_8 ;
int V_30 = F_196 ( V_237 , V_218 ) ;
if ( V_30 < 0 )
return V_30 ;
V_8 = F_147 ( F_146 ( V_237 ) ,
V_242 ) ;
V_30 = F_197 ( V_218 , V_8 , V_303 ) ;
if ( V_8 )
F_157 ( V_8 -> V_11 ) ;
return V_30 ;
}
static int F_197 ( struct V_218 * V_218 , struct V_7 * V_8 , int V_14 )
{
int V_30 ;
T_5 V_221 ;
if ( V_8 == NULL ) {
V_30 = - V_234 ;
goto V_304;
}
V_30 = F_199 ( V_8 -> V_11 , V_218 ) ;
if ( V_30 < 0 )
goto V_304;
if ( ! F_200 ( V_8 -> V_11 -> V_305 ) ) {
V_30 = - V_33 ;
goto V_306;
}
F_135 ( & V_221 , V_229 ) ;
F_136 ( & V_8 -> V_307 , & V_221 ) ;
F_201 ( & V_8 -> V_308 ) ;
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
F_202 ( V_309 ) ;
F_203 ( & V_8 -> V_308 ) ;
F_204 () ;
F_201 ( & V_8 -> V_308 ) ;
if ( V_8 -> V_11 -> V_233 ) {
V_30 = - V_234 ;
break;
}
if ( F_134 ( V_229 ) ) {
V_30 = - V_230 ;
break;
}
}
F_139 ( & V_8 -> V_307 , & V_221 ) ;
F_203 ( & V_8 -> V_308 ) ;
if ( V_30 < 0 )
goto V_310;
return V_30 ;
V_310:
F_205 ( V_8 -> V_11 -> V_305 ) ;
V_306:
F_206 ( V_8 -> V_11 , V_218 ) ;
V_304:
return V_30 ;
}
static int F_207 ( struct V_237 * V_237 , struct V_218 * V_218 )
{
struct V_7 * V_8 ;
struct V_2 * V_3 ;
struct V_244 * V_245 ;
V_245 = V_218 -> V_250 ;
V_3 = V_245 -> V_3 ;
if ( F_208 ( ! V_3 ) )
return - V_95 ;
V_8 = V_3 -> V_8 ;
F_201 ( & V_8 -> V_308 ) ;
F_189 ( V_3 ) ;
F_11 ( V_245 ) ;
F_203 ( & V_8 -> V_308 ) ;
F_97 ( & V_8 -> V_307 ) ;
F_205 ( V_8 -> V_11 -> V_305 ) ;
F_206 ( V_8 -> V_11 , V_218 ) ;
return 0 ;
}
static T_6 F_209 ( struct V_2 * V_3 ,
T_3 V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_144 ;
T_6 V_311 ;
T_6 V_312 ;
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
V_311 = - V_172 ;
goto V_313;
case V_196 :
V_311 = - V_235 ;
goto V_313;
default:
V_311 = - V_99 ;
goto V_313;
}
V_312 = F_210 ( V_6 ) ;
if ( V_312 <= 0 ) {
V_311 = 0 ;
goto V_313;
}
if ( V_94 > ( T_3 ) V_312 )
V_94 = V_312 ;
V_144 = V_6 -> V_122 -> V_144 - V_94 ;
if ( V_144 < 0 )
V_144 += V_6 -> V_128 ;
V_6 -> V_122 -> V_144 = V_144 ;
V_311 = V_94 ;
V_313:
F_37 ( V_3 ) ;
return V_311 ;
}
static T_6 F_211 ( struct V_2 * V_3 ,
T_3 V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_144 ;
T_6 V_311 ;
T_6 V_312 ;
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
V_311 = - V_172 ;
goto V_313;
case V_196 :
V_311 = - V_235 ;
goto V_313;
default:
V_311 = - V_99 ;
goto V_313;
}
V_312 = F_212 ( V_6 ) ;
if ( V_312 <= 0 ) {
V_311 = 0 ;
goto V_313;
}
if ( V_94 > ( T_3 ) V_312 )
V_94 = V_312 ;
V_144 = V_6 -> V_122 -> V_144 - V_94 ;
if ( V_144 < 0 )
V_144 += V_6 -> V_128 ;
V_6 -> V_122 -> V_144 = V_144 ;
V_311 = V_94 ;
V_313:
F_37 ( V_3 ) ;
return V_311 ;
}
static T_6 F_213 ( struct V_2 * V_3 ,
T_3 V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_144 ;
T_6 V_311 ;
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
V_311 = - V_172 ;
goto V_313;
case V_196 :
V_311 = - V_235 ;
goto V_313;
default:
V_311 = - V_99 ;
goto V_313;
}
V_146 = F_66 ( V_6 ) ;
if ( V_146 <= 0 ) {
V_311 = 0 ;
goto V_313;
}
if ( V_94 > ( T_3 ) V_146 )
V_94 = V_146 ;
V_144 = V_6 -> V_122 -> V_144 + V_94 ;
if ( V_144 >= ( T_6 ) V_6 -> V_128 )
V_144 -= V_6 -> V_128 ;
V_6 -> V_122 -> V_144 = V_144 ;
V_311 = V_94 ;
V_313:
F_37 ( V_3 ) ;
return V_311 ;
}
static T_6 F_214 ( struct V_2 * V_3 ,
T_3 V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_144 ;
T_6 V_311 ;
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
V_311 = - V_172 ;
goto V_313;
case V_196 :
V_311 = - V_235 ;
goto V_313;
default:
V_311 = - V_99 ;
goto V_313;
}
V_146 = F_67 ( V_6 ) ;
if ( V_146 <= 0 ) {
V_311 = 0 ;
goto V_313;
}
if ( V_94 > ( T_3 ) V_146 )
V_94 = V_146 ;
V_144 = V_6 -> V_122 -> V_144 + V_94 ;
if ( V_144 >= ( T_6 ) V_6 -> V_128 )
V_144 -= V_6 -> V_128 ;
V_6 -> V_122 -> V_144 = V_144 ;
V_311 = V_94 ;
V_313:
F_37 ( V_3 ) ;
return V_311 ;
}
static int F_215 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_30 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_148 :
if ( V_3 -> V_14 == V_303 )
goto V_314;
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
V_314:
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
T_6 V_315 = 0 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_148 :
if ( V_3 -> V_14 == V_303 )
goto V_314;
case V_147 :
if ( ( V_30 = F_64 ( V_3 ) ) < 0 )
break;
case V_98 :
case V_196 :
V_30 = 0 ;
if ( V_3 -> V_14 == V_135 )
V_315 = F_210 ( V_6 ) ;
else
V_315 = F_67 ( V_6 ) ;
V_315 += V_6 -> V_149 ;
break;
case V_209 :
V_30 = - V_172 ;
break;
default:
V_314:
V_30 = - V_99 ;
break;
}
F_37 ( V_3 ) ;
if ( ! V_30 )
if ( F_217 ( V_315 , V_153 ) )
V_30 = - V_33 ;
return V_30 ;
}
static int F_218 ( struct V_2 * V_3 ,
struct F_218 T_2 * V_316 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct F_218 V_317 ;
volatile struct V_318 * V_92 ;
volatile struct V_319 * V_122 ;
int V_30 ;
memset ( & V_317 , 0 , sizeof( V_317 ) ) ;
if ( F_219 ( V_317 . V_79 , ( unsigned T_2 * ) & ( V_316 -> V_79 ) ) )
return - V_33 ;
if ( F_62 ( & V_317 . V_320 . V_122 , & ( V_316 -> V_320 . V_122 ) , sizeof( struct V_319 ) ) )
return - V_33 ;
V_92 = V_6 -> V_92 ;
V_122 = V_6 -> V_122 ;
if ( V_317 . V_79 & V_321 ) {
V_30 = F_215 ( V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
}
F_36 ( V_3 ) ;
if ( ! ( V_317 . V_79 & V_322 ) )
V_122 -> V_144 = V_317 . V_320 . V_122 . V_144 ;
else
V_317 . V_320 . V_122 . V_144 = V_122 -> V_144 ;
if ( ! ( V_317 . V_79 & V_323 ) )
V_122 -> V_123 = V_317 . V_320 . V_122 . V_123 ;
else
V_317 . V_320 . V_122 . V_123 = V_122 -> V_123 ;
V_317 . V_159 . V_92 . V_91 = V_92 -> V_91 ;
V_317 . V_159 . V_92 . V_145 = V_92 -> V_145 ;
V_317 . V_159 . V_92 . V_141 = V_92 -> V_141 ;
V_317 . V_159 . V_92 . V_137 = V_92 -> V_137 ;
F_37 ( V_3 ) ;
if ( F_10 ( V_316 , & V_317 , sizeof( V_317 ) ) )
return - V_33 ;
return 0 ;
}
static int F_220 ( struct V_2 * V_3 , int T_2 * V_324 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_325 ;
if ( F_219 ( V_325 , V_324 ) )
return - V_33 ;
if ( V_325 < 0 || V_325 > V_326 )
return - V_62 ;
V_6 -> V_327 = V_328 ;
if ( V_325 == V_329 )
V_6 -> V_327 = V_329 ;
return 0 ;
}
static int F_221 ( struct V_218 * V_218 ,
struct V_2 * V_3 ,
unsigned int V_330 , void T_2 * V_325 )
{
switch ( V_330 ) {
case V_331 :
return F_217 ( V_332 , ( int T_2 * ) V_325 ) ? - V_33 : 0 ;
case V_333 :
return F_8 ( V_3 , V_325 ) ;
case V_334 :
return 0 ;
case V_335 :
return F_220 ( V_3 , V_325 ) ;
case V_336 :
return F_30 ( V_3 , V_325 ) ;
case V_337 :
return F_55 ( V_3 , V_325 ) ;
case V_338 :
return F_56 ( V_3 ) ;
case V_339 :
return F_61 ( V_3 , V_325 ) ;
case V_340 :
return F_68 ( V_3 , V_325 ) ;
case V_341 :
return F_70 ( V_3 , V_325 ) ;
case V_342 :
return F_128 ( V_3 , V_218 ) ;
case V_343 :
return F_124 ( V_3 ) ;
case V_344 :
return F_81 ( & V_182 , V_3 , V_147 ) ;
case V_345 :
return F_148 ( V_3 , ( int ) ( unsigned long ) V_325 ) ;
case V_346 :
return F_160 ( V_3 ) ;
case V_347 :
return F_116 ( V_3 ) ;
case V_348 :
return F_120 ( V_3 ) ;
case V_349 :
return F_215 ( V_3 ) ;
case V_350 :
return F_216 ( V_3 , V_325 ) ;
case V_351 :
return F_218 ( V_3 , V_325 ) ;
#ifdef F_222
case V_352 :
return F_223 ( V_3 , V_325 ) ;
case V_353 :
return F_224 ( V_3 , V_325 ) ;
#endif
case V_354 :
return F_133 ( V_3 , V_218 ) ;
case V_355 :
return F_141 ( V_3 ) ;
case V_356 :
{
int V_153 ;
F_36 ( V_3 ) ;
V_153 = F_104 ( V_3 , ( int ) ( unsigned long ) V_325 ) ;
F_37 ( V_3 ) ;
return V_153 ;
}
}
F_140 ( L_15 , V_330 ) ;
return - V_357 ;
}
static int F_225 ( struct V_218 * V_218 ,
struct V_2 * V_3 ,
unsigned int V_330 , void T_2 * V_325 )
{
if ( F_208 ( ! V_3 ) )
return - V_95 ;
if ( F_208 ( V_3 -> V_14 != V_135 ) )
return - V_62 ;
switch ( V_330 ) {
case V_358 :
{
struct V_359 V_360 ;
struct V_359 T_2 * V_361 = V_325 ;
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_133 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( F_217 ( 0 , & V_361 -> V_133 ) )
return - V_33 ;
if ( F_62 ( & V_360 , V_361 , sizeof( V_360 ) ) )
return - V_33 ;
V_133 = F_226 ( V_3 , V_360 . V_362 , V_360 . V_94 ) ;
F_227 ( V_133 , & V_361 -> V_133 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
case V_363 :
{
struct V_364 V_365 ;
struct V_364 T_2 * V_366 = V_325 ;
struct V_5 * V_6 = V_3 -> V_6 ;
void T_2 * * V_367 ;
T_6 V_133 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( V_6 -> V_109 > 128 )
return - V_62 ;
if ( F_217 ( 0 , & V_366 -> V_133 ) )
return - V_33 ;
if ( F_62 ( & V_365 , V_366 , sizeof( V_365 ) ) )
return - V_33 ;
V_367 = F_31 ( V_365 . V_367 ,
sizeof( void * ) * V_6 -> V_109 ) ;
if ( F_32 ( V_367 ) )
return F_33 ( V_367 ) ;
V_133 = F_228 ( V_3 , V_367 , V_365 . V_94 ) ;
F_11 ( V_367 ) ;
F_227 ( V_133 , & V_366 -> V_133 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
case V_368 :
{
T_3 V_94 ;
T_3 T_2 * V_369 = V_325 ;
T_6 V_133 ;
if ( F_219 ( V_94 , V_369 ) )
return - V_33 ;
if ( F_217 ( 0 , V_369 ) )
return - V_33 ;
V_133 = F_209 ( V_3 , V_94 ) ;
F_227 ( V_133 , V_369 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
case V_370 :
{
T_3 V_94 ;
T_3 T_2 * V_369 = V_325 ;
T_6 V_133 ;
if ( F_219 ( V_94 , V_369 ) )
return - V_33 ;
if ( F_217 ( 0 , V_369 ) )
return - V_33 ;
V_133 = F_213 ( V_3 , V_94 ) ;
F_227 ( V_133 , V_369 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
}
return F_221 ( V_218 , V_3 , V_330 , V_325 ) ;
}
static int F_229 ( struct V_218 * V_218 ,
struct V_2 * V_3 ,
unsigned int V_330 , void T_2 * V_325 )
{
if ( F_208 ( ! V_3 ) )
return - V_95 ;
if ( F_208 ( V_3 -> V_14 != V_303 ) )
return - V_62 ;
switch ( V_330 ) {
case V_371 :
{
struct V_359 V_360 ;
struct V_359 T_2 * V_361 = V_325 ;
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_133 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( F_217 ( 0 , & V_361 -> V_133 ) )
return - V_33 ;
if ( F_62 ( & V_360 , V_361 , sizeof( V_360 ) ) )
return - V_33 ;
V_133 = F_230 ( V_3 , V_360 . V_362 , V_360 . V_94 ) ;
F_227 ( V_133 , & V_361 -> V_133 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
case V_372 :
{
struct V_364 V_365 ;
struct V_364 T_2 * V_366 = V_325 ;
struct V_5 * V_6 = V_3 -> V_6 ;
void * V_367 ;
T_6 V_133 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( V_6 -> V_109 > 128 )
return - V_62 ;
if ( F_217 ( 0 , & V_366 -> V_133 ) )
return - V_33 ;
if ( F_62 ( & V_365 , V_366 , sizeof( V_365 ) ) )
return - V_33 ;
V_367 = F_31 ( V_365 . V_367 ,
sizeof( void * ) * V_6 -> V_109 ) ;
if ( F_32 ( V_367 ) )
return F_33 ( V_367 ) ;
V_133 = F_231 ( V_3 , V_367 , V_365 . V_94 ) ;
F_11 ( V_367 ) ;
F_227 ( V_133 , & V_366 -> V_133 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
case V_368 :
{
T_3 V_94 ;
T_3 T_2 * V_369 = V_325 ;
T_6 V_133 ;
if ( F_219 ( V_94 , V_369 ) )
return - V_33 ;
if ( F_217 ( 0 , V_369 ) )
return - V_33 ;
V_133 = F_211 ( V_3 , V_94 ) ;
F_227 ( V_133 , V_369 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
case V_370 :
{
T_3 V_94 ;
T_3 T_2 * V_369 = V_325 ;
T_6 V_133 ;
if ( F_219 ( V_94 , V_369 ) )
return - V_33 ;
if ( F_217 ( 0 , V_369 ) )
return - V_33 ;
V_133 = F_214 ( V_3 , V_94 ) ;
F_227 ( V_133 , V_369 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
}
return F_221 ( V_218 , V_3 , V_330 , V_325 ) ;
}
static long F_232 ( struct V_218 * V_218 , unsigned int V_330 ,
unsigned long V_325 )
{
struct V_244 * V_245 ;
V_245 = V_218 -> V_250 ;
if ( ( ( V_330 >> 8 ) & 0xff ) != 'A' )
return - V_357 ;
return F_225 ( V_218 , V_245 -> V_3 , V_330 ,
( void T_2 * ) V_325 ) ;
}
static long F_233 ( struct V_218 * V_218 , unsigned int V_330 ,
unsigned long V_325 )
{
struct V_244 * V_245 ;
V_245 = V_218 -> V_250 ;
if ( ( ( V_330 >> 8 ) & 0xff ) != 'A' )
return - V_357 ;
return F_229 ( V_218 , V_245 -> V_3 , V_330 ,
( void T_2 * ) V_325 ) ;
}
int F_234 ( struct V_2 * V_3 ,
unsigned int V_330 , void * V_325 )
{
T_1 V_1 ;
int V_133 ;
V_1 = F_1 () ;
switch ( V_3 -> V_14 ) {
case V_135 :
V_133 = F_225 ( NULL , V_3 , V_330 ,
( void T_2 * ) V_325 ) ;
break;
case V_303 :
V_133 = F_229 ( NULL , V_3 , V_330 ,
( void T_2 * ) V_325 ) ;
break;
default:
V_133 = - V_62 ;
break;
}
F_5 ( V_1 ) ;
return V_133 ;
}
static T_7 F_235 ( struct V_218 * V_218 , char T_2 * V_362 , T_8 V_255 ,
T_9 * V_373 )
{
struct V_244 * V_245 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_133 ;
V_245 = V_218 -> V_250 ;
V_3 = V_245 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( ! F_236 ( V_6 , V_255 ) )
return - V_62 ;
V_255 = F_237 ( V_6 , V_255 ) ;
V_133 = F_230 ( V_3 , V_362 , V_255 ) ;
if ( V_133 > 0 )
V_133 = F_238 ( V_6 , V_133 ) ;
return V_133 ;
}
static T_7 F_239 ( struct V_218 * V_218 , const char T_2 * V_362 ,
T_8 V_255 , T_9 * V_373 )
{
struct V_244 * V_245 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_133 ;
V_245 = V_218 -> V_250 ;
V_3 = V_245 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( ! F_236 ( V_6 , V_255 ) )
return - V_62 ;
V_255 = F_237 ( V_6 , V_255 ) ;
V_133 = F_226 ( V_3 , V_362 , V_255 ) ;
if ( V_133 > 0 )
V_133 = F_238 ( V_6 , V_133 ) ;
return V_133 ;
}
static T_7 F_240 ( struct V_374 * V_375 , const struct V_376 * V_377 ,
unsigned long V_378 , T_9 V_379 )
{
struct V_244 * V_245 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_133 ;
unsigned long V_40 ;
void T_2 * * V_367 ;
T_3 V_94 ;
V_245 = V_375 -> V_380 -> V_250 ;
V_3 = V_245 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( V_378 > 1024 || V_378 != V_6 -> V_109 )
return - V_62 ;
if ( ! F_236 ( V_6 , V_377 -> V_381 ) )
return - V_62 ;
V_94 = F_241 ( V_6 , V_377 -> V_381 ) ;
V_367 = F_9 ( sizeof( void * ) * V_378 , V_31 ) ;
if ( V_367 == NULL )
return - V_32 ;
for ( V_40 = 0 ; V_40 < V_378 ; ++ V_40 )
V_367 [ V_40 ] = V_377 [ V_40 ] . V_382 ;
V_133 = F_231 ( V_3 , V_367 , V_94 ) ;
if ( V_133 > 0 )
V_133 = F_238 ( V_6 , V_133 ) ;
F_11 ( V_367 ) ;
return V_133 ;
}
static T_7 F_242 ( struct V_374 * V_375 , const struct V_376 * V_377 ,
unsigned long V_378 , T_9 V_379 )
{
struct V_244 * V_245 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_133 ;
unsigned long V_40 ;
void T_2 * * V_367 ;
T_3 V_94 ;
V_245 = V_375 -> V_380 -> V_250 ;
V_3 = V_245 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( V_378 > 128 || V_378 != V_6 -> V_109 ||
! F_236 ( V_6 , V_377 -> V_381 ) )
return - V_62 ;
V_94 = F_241 ( V_6 , V_377 -> V_381 ) ;
V_367 = F_9 ( sizeof( void * ) * V_378 , V_31 ) ;
if ( V_367 == NULL )
return - V_32 ;
for ( V_40 = 0 ; V_40 < V_378 ; ++ V_40 )
V_367 [ V_40 ] = V_377 [ V_40 ] . V_382 ;
V_133 = F_228 ( V_3 , V_367 , V_94 ) ;
if ( V_133 > 0 )
V_133 = F_238 ( V_6 , V_133 ) ;
F_11 ( V_367 ) ;
return V_133 ;
}
static unsigned int F_243 ( struct V_218 * V_218 , T_10 * V_221 )
{
struct V_244 * V_245 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
unsigned int V_258 ;
T_3 V_146 ;
V_245 = V_218 -> V_250 ;
V_3 = V_245 -> V_3 ;
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
V_258 = V_383 | V_384 ;
break;
}
case V_148 :
V_258 = 0 ;
break;
default:
V_258 = V_383 | V_384 | V_385 ;
break;
}
F_37 ( V_3 ) ;
return V_258 ;
}
static unsigned int F_245 ( struct V_218 * V_218 , T_10 * V_221 )
{
struct V_244 * V_245 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
unsigned int V_258 ;
T_3 V_146 ;
V_245 = V_218 -> V_250 ;
V_3 = V_245 -> V_3 ;
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
V_258 = V_386 | V_387 ;
break;
}
V_258 = 0 ;
break;
case V_148 :
if ( V_146 > 0 ) {
V_258 = V_386 | V_387 ;
break;
}
default:
V_258 = V_386 | V_387 | V_385 ;
break;
}
F_37 ( V_3 ) ;
return V_258 ;
}
static int F_246 ( struct V_388 * V_389 ,
struct V_390 * V_391 )
{
struct V_2 * V_3 = V_389 -> V_392 ;
struct V_5 * V_6 ;
if ( V_3 == NULL )
return V_393 ;
V_6 = V_3 -> V_6 ;
V_391 -> V_394 = F_247 ( V_6 -> V_92 ) ;
F_248 ( V_391 -> V_394 ) ;
return 0 ;
}
static int V_318 ( struct V_2 * V_3 , struct V_218 * V_218 ,
struct V_388 * V_389 )
{
long V_395 ;
if ( ! ( V_389 -> V_396 & V_397 ) )
return - V_62 ;
V_395 = V_389 -> V_398 - V_389 -> V_399 ;
if ( V_395 != F_249 ( sizeof( struct V_318 ) ) )
return - V_62 ;
V_389 -> V_400 = & V_401 ;
V_389 -> V_392 = V_3 ;
V_389 -> V_396 |= V_402 | V_403 ;
return 0 ;
}
static int F_250 ( struct V_388 * V_389 ,
struct V_390 * V_391 )
{
struct V_2 * V_3 = V_389 -> V_392 ;
struct V_5 * V_6 ;
if ( V_3 == NULL )
return V_393 ;
V_6 = V_3 -> V_6 ;
V_391 -> V_394 = F_247 ( V_6 -> V_122 ) ;
F_248 ( V_391 -> V_394 ) ;
return 0 ;
}
static int V_319 ( struct V_2 * V_3 , struct V_218 * V_218 ,
struct V_388 * V_389 )
{
long V_395 ;
if ( ! ( V_389 -> V_396 & V_397 ) )
return - V_62 ;
V_395 = V_389 -> V_398 - V_389 -> V_399 ;
if ( V_395 != F_249 ( sizeof( struct V_319 ) ) )
return - V_62 ;
V_389 -> V_400 = & V_404 ;
V_389 -> V_392 = V_3 ;
V_389 -> V_396 |= V_402 | V_403 ;
return 0 ;
}
static int V_318 ( struct V_2 * V_3 , struct V_218 * V_218 ,
struct V_388 * V_389 )
{
return - V_95 ;
}
static int V_319 ( struct V_2 * V_3 , struct V_218 * V_218 ,
struct V_388 * V_389 )
{
return - V_95 ;
}
static inline struct V_394 *
F_251 ( struct V_2 * V_3 , unsigned long V_405 )
{
void * V_406 = V_3 -> V_6 -> V_407 + V_405 ;
#if F_39 ( V_408 ) && F_39 ( V_409 )
if ( V_3 -> V_410 . V_411 . type == V_412 )
return F_247 ( F_252 ( V_406 ) ) ;
#endif
#if F_39 ( V_413 ) && F_39 ( V_414 )
if ( V_3 -> V_410 . V_411 . type == V_412 ) {
T_11 V_415 = V_3 -> V_6 -> V_416 + V_405 ;
V_415 -= F_253 ( V_3 -> V_410 . V_411 . V_411 ) ;
return F_254 ( V_415 >> V_417 ) ;
}
#endif
return F_247 ( V_406 ) ;
}
static int F_255 ( struct V_388 * V_389 ,
struct V_390 * V_391 )
{
struct V_2 * V_3 = V_389 -> V_392 ;
struct V_5 * V_6 ;
unsigned long V_373 ;
struct V_394 * V_394 ;
T_8 V_294 ;
if ( V_3 == NULL )
return V_393 ;
V_6 = V_3 -> V_6 ;
V_373 = V_391 -> V_418 << V_417 ;
V_294 = F_249 ( V_6 -> V_294 ) ;
if ( V_373 > V_294 - V_419 )
return V_393 ;
if ( V_3 -> V_26 -> V_394 )
V_394 = V_3 -> V_26 -> V_394 ( V_3 , V_373 ) ;
else
V_394 = F_251 ( V_3 , V_373 ) ;
if ( ! V_394 )
return V_393 ;
F_248 ( V_394 ) ;
V_391 -> V_394 = V_394 ;
return 0 ;
}
int F_256 ( struct V_2 * V_3 ,
struct V_388 * V_389 )
{
V_389 -> V_396 |= V_402 | V_403 ;
#ifdef F_257
if ( V_3 -> V_410 . V_411 . type == V_420 ) {
V_389 -> V_421 = F_258 ( V_389 -> V_421 ) ;
return F_259 ( V_389 , V_389 -> V_399 ,
V_3 -> V_410 . V_415 >> V_417 ,
V_389 -> V_398 - V_389 -> V_399 , V_389 -> V_421 ) ;
}
#endif
#ifdef F_260
if ( ! V_3 -> V_26 -> V_394 &&
V_3 -> V_410 . V_411 . type == V_412 )
return F_261 ( V_3 -> V_410 . V_411 . V_411 ,
V_389 ,
V_3 -> V_6 -> V_407 ,
V_3 -> V_6 -> V_416 ,
V_389 -> V_398 - V_389 -> V_399 ) ;
#elif F_39 ( V_408 ) && F_39 ( V_409 )
if ( V_3 -> V_410 . V_411 . type == V_412 &&
! F_262 ( V_3 -> V_410 . V_411 . V_411 ) )
V_389 -> V_421 = F_263 ( V_389 -> V_421 ) ;
#endif
V_389 -> V_400 = & V_422 ;
return 0 ;
}
int F_264 ( struct V_2 * V_3 ,
struct V_388 * V_389 )
{
struct V_5 * V_6 = V_3 -> V_6 ; ;
V_389 -> V_421 = F_263 ( V_389 -> V_421 ) ;
return F_265 ( V_389 , V_6 -> V_416 , V_6 -> V_294 ) ;
}
int F_266 ( struct V_2 * V_3 , struct V_218 * V_218 ,
struct V_388 * V_389 )
{
struct V_5 * V_6 ;
long V_395 ;
unsigned long V_373 ;
T_8 V_294 ;
int V_30 ;
if ( V_3 -> V_14 == V_135 ) {
if ( ! ( V_389 -> V_396 & ( V_423 | V_397 ) ) )
return - V_62 ;
} else {
if ( ! ( V_389 -> V_396 & V_397 ) )
return - V_62 ;
}
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( ! ( V_6 -> V_4 & V_277 ) )
return - V_95 ;
if ( V_6 -> V_106 == V_274 ||
V_6 -> V_106 == V_276 )
return - V_62 ;
V_395 = V_389 -> V_398 - V_389 -> V_399 ;
V_373 = V_389 -> V_424 << V_417 ;
V_294 = F_249 ( V_6 -> V_294 ) ;
if ( ( T_8 ) V_395 > V_294 )
return - V_62 ;
if ( V_373 > V_294 - V_395 )
return - V_62 ;
V_389 -> V_400 = & V_425 ;
V_389 -> V_392 = V_3 ;
if ( V_3 -> V_26 -> V_426 )
V_30 = V_3 -> V_26 -> V_426 ( V_3 , V_389 ) ;
else
V_30 = F_256 ( V_3 , V_389 ) ;
if ( ! V_30 )
F_267 ( & V_3 -> V_103 ) ;
return V_30 ;
}
static int F_268 ( struct V_218 * V_218 , struct V_388 * V_389 )
{
struct V_244 * V_245 ;
struct V_2 * V_3 ;
unsigned long V_373 ;
V_245 = V_218 -> V_250 ;
V_3 = V_245 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_373 = V_389 -> V_424 << V_417 ;
switch ( V_373 ) {
case V_427 :
if ( V_245 -> V_428 )
return - V_95 ;
return V_318 ( V_3 , V_218 , V_389 ) ;
case V_429 :
if ( V_245 -> V_428 )
return - V_95 ;
return V_319 ( V_3 , V_218 , V_389 ) ;
default:
return F_266 ( V_3 , V_218 , V_389 ) ;
}
return 0 ;
}
static int F_269 ( int V_243 , struct V_218 * V_218 , int V_430 )
{
struct V_244 * V_245 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
V_245 = V_218 -> V_250 ;
V_3 = V_245 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
return F_270 ( V_243 , V_218 , V_430 , & V_6 -> V_431 ) ;
}
static void F_271 ( struct V_34 * V_35 ,
struct V_432 * V_433 )
{
unsigned int V_40 ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
V_35 -> V_79 = V_433 -> V_79 ;
for ( V_40 = 0 ; V_40 < F_272 ( V_433 -> V_434 ) ; V_40 ++ )
V_35 -> V_434 [ V_40 ] . V_65 [ 0 ] = V_433 -> V_434 [ V_40 ] ;
memcpy ( V_35 -> V_435 , V_433 -> V_435 , sizeof( V_433 -> V_435 ) ) ;
V_35 -> V_54 = F_273 ( V_433 -> V_54 ) ;
V_35 -> V_66 = F_273 ( V_433 -> V_66 ) ;
V_35 -> V_4 = V_433 -> V_4 ;
V_35 -> V_56 = V_433 -> V_56 ;
V_35 -> V_58 = V_433 -> V_58 ;
V_35 -> V_59 = V_433 -> V_59 ;
V_35 -> V_53 = V_433 -> V_53 ;
}
static void F_274 ( struct V_432 * V_433 ,
struct V_34 * V_35 )
{
unsigned int V_40 ;
memset ( V_433 , 0 , sizeof( * V_433 ) ) ;
V_433 -> V_79 = V_35 -> V_79 ;
for ( V_40 = 0 ; V_40 < F_272 ( V_433 -> V_434 ) ; V_40 ++ )
V_433 -> V_434 [ V_40 ] = V_35 -> V_434 [ V_40 ] . V_65 [ 0 ] ;
memcpy ( V_433 -> V_435 , V_35 -> V_435 , sizeof( V_433 -> V_435 ) ) ;
V_433 -> V_54 = F_275 ( V_35 -> V_54 ) ;
V_433 -> V_66 = F_275 ( V_35 -> V_66 ) ;
V_433 -> V_4 = V_35 -> V_4 ;
V_433 -> V_56 = V_35 -> V_56 ;
V_433 -> V_58 = V_35 -> V_58 ;
V_433 -> V_59 = V_35 -> V_59 ;
V_433 -> V_53 = V_35 -> V_53 ;
}
static int F_223 ( struct V_2 * V_3 ,
struct V_432 T_2 * V_436 )
{
struct V_34 * V_35 ;
struct V_432 * V_433 = NULL ;
int V_30 ;
V_35 = F_9 ( sizeof( * V_35 ) , V_31 ) ;
if ( ! V_35 )
return - V_32 ;
V_433 = F_31 ( V_436 , sizeof( * V_433 ) ) ;
if ( F_32 ( V_433 ) ) {
V_30 = F_33 ( V_433 ) ;
goto V_437;
}
F_271 ( V_35 , V_433 ) ;
V_30 = F_12 ( V_3 , V_35 ) ;
F_274 ( V_433 , V_35 ) ;
if ( F_10 ( V_436 , V_433 , sizeof( * V_433 ) ) ) {
if ( ! V_30 )
V_30 = - V_33 ;
}
F_11 ( V_433 ) ;
V_437:
F_11 ( V_35 ) ;
return V_30 ;
}
static int F_224 ( struct V_2 * V_3 ,
struct V_432 T_2 * V_436 )
{
struct V_34 * V_35 ;
struct V_432 * V_433 = NULL ;
int V_30 ;
V_35 = F_9 ( sizeof( * V_35 ) , V_31 ) ;
if ( ! V_35 )
return - V_32 ;
V_433 = F_31 ( V_436 , sizeof( * V_433 ) ) ;
if ( F_32 ( V_433 ) ) {
V_30 = F_33 ( V_433 ) ;
goto V_437;
}
F_271 ( V_35 , V_433 ) ;
V_30 = V_34 ( V_3 , V_35 ) ;
F_274 ( V_433 , V_35 ) ;
if ( F_10 ( V_436 , V_433 , sizeof( * V_433 ) ) ) {
if ( ! V_30 )
V_30 = - V_33 ;
}
F_11 ( V_433 ) ;
V_437:
F_11 ( V_35 ) ;
return V_30 ;
}
static unsigned long F_276 ( struct V_218 * V_218 ,
unsigned long V_415 ,
unsigned long V_438 ,
unsigned long V_418 ,
unsigned long V_79 )
{
struct V_244 * V_245 = V_218 -> V_250 ;
struct V_2 * V_3 = V_245 -> V_3 ;
struct V_5 * V_6 = V_3 -> V_6 ;
unsigned long V_373 = V_418 << V_417 ;
switch ( V_373 ) {
case V_427 :
return ( unsigned long ) V_6 -> V_92 ;
case V_429 :
return ( unsigned long ) V_6 -> V_122 ;
default:
return ( unsigned long ) V_6 -> V_407 + V_373 ;
}
}
