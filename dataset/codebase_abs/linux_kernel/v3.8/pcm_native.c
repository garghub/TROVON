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
V_239 = V_218 -> V_241 . V_242 -> V_243 ;
if ( ! F_144 ( V_239 -> V_244 ) ||
F_145 ( V_239 ) != V_245 ) {
F_146 ( V_218 , * V_238 ) ;
return NULL ;
}
V_240 = F_147 ( V_239 ) ;
if ( ! F_148 ( V_240 , V_246 ) &&
! F_148 ( V_240 , V_247 ) ) {
F_146 ( V_218 , * V_238 ) ;
return NULL ;
}
return V_218 ;
}
static int F_149 ( struct V_2 * V_3 , int V_237 )
{
int V_153 = 0 ;
struct V_218 * V_218 ;
struct V_248 * V_249 ;
struct V_2 * V_250 ;
struct V_251 * V_169 ;
int V_238 ;
V_218 = F_142 ( V_237 , & V_238 ) ;
if ( ! V_218 )
return - V_99 ;
V_249 = V_218 -> V_252 ;
V_250 = V_249 -> V_3 ;
V_169 = F_9 ( sizeof( * V_169 ) , V_31 ) ;
if ( ! V_169 ) {
V_153 = - V_32 ;
goto V_253;
}
F_150 ( & V_171 ) ;
F_151 ( & V_170 ) ;
if ( V_3 -> V_6 -> V_92 -> V_91 == V_96 ||
V_3 -> V_6 -> V_92 -> V_91 != V_250 -> V_6 -> V_92 -> V_91 ) {
V_153 = - V_99 ;
goto V_138;
}
if ( F_78 ( V_250 ) ) {
V_153 = - V_254 ;
goto V_138;
}
if ( ! F_78 ( V_3 ) ) {
V_3 -> V_169 = V_169 ;
F_152 ( & V_3 -> V_169 -> V_162 ) ;
F_153 ( & V_3 -> V_169 -> V_255 ) ;
F_154 ( & V_3 -> V_256 , & V_3 -> V_169 -> V_255 ) ;
V_3 -> V_169 -> V_257 = 1 ;
}
F_154 ( & V_250 -> V_256 , & V_3 -> V_169 -> V_255 ) ;
V_3 -> V_169 -> V_257 ++ ;
V_250 -> V_169 = V_3 -> V_169 ;
V_138:
F_155 ( & V_170 ) ;
F_156 ( & V_171 ) ;
V_253:
F_157 ( V_250 -> V_8 -> V_11 ) ;
F_146 ( V_218 , V_238 ) ;
if ( V_153 < 0 )
F_11 ( V_169 ) ;
return V_153 ;
}
static void F_158 ( struct V_2 * V_3 )
{
V_3 -> V_169 = & V_3 -> V_161 ;
F_153 ( & V_3 -> V_161 . V_255 ) ;
F_154 ( & V_3 -> V_256 , & V_3 -> V_161 . V_255 ) ;
}
static int F_159 ( struct V_2 * V_3 )
{
struct V_2 * V_159 ;
int V_153 = 0 ;
F_150 ( & V_171 ) ;
F_151 ( & V_170 ) ;
if ( ! F_78 ( V_3 ) ) {
V_153 = - V_254 ;
goto V_138;
}
F_160 ( & V_3 -> V_256 ) ;
V_3 -> V_169 -> V_257 -- ;
if ( V_3 -> V_169 -> V_257 == 1 ) {
F_73 (s, substream) {
F_158 ( V_159 ) ;
break;
}
F_11 ( V_3 -> V_169 ) ;
}
F_158 ( V_3 ) ;
V_138:
F_155 ( & V_170 ) ;
F_156 ( & V_171 ) ;
return V_153 ;
}
static int F_161 ( struct V_34 * V_35 ,
struct V_73 * V_258 )
{
struct V_39 V_232 ;
F_162 ( F_163 ( V_35 , V_258 -> V_80 [ 0 ] ) ,
F_163 ( V_35 , V_258 -> V_80 [ 1 ] ) , & V_232 ) ;
return F_21 ( F_19 ( V_35 , V_258 -> V_82 ) , & V_232 ) ;
}
static int F_164 ( struct V_34 * V_35 ,
struct V_73 * V_258 )
{
struct V_39 V_232 ;
F_165 ( F_163 ( V_35 , V_258 -> V_80 [ 0 ] ) ,
F_163 ( V_35 , V_258 -> V_80 [ 1 ] ) , & V_232 ) ;
return F_21 ( F_19 ( V_35 , V_258 -> V_82 ) , & V_232 ) ;
}
static int F_166 ( struct V_34 * V_35 ,
struct V_73 * V_258 )
{
struct V_39 V_232 ;
F_167 ( F_163 ( V_35 , V_258 -> V_80 [ 0 ] ) ,
F_163 ( V_35 , V_258 -> V_80 [ 1 ] ) ,
( unsigned long ) V_258 -> V_259 , & V_232 ) ;
return F_21 ( F_19 ( V_35 , V_258 -> V_82 ) , & V_232 ) ;
}
static int F_168 ( struct V_34 * V_35 ,
struct V_73 * V_258 )
{
struct V_39 V_232 ;
F_169 ( F_163 ( V_35 , V_258 -> V_80 [ 0 ] ) ,
( unsigned long ) V_258 -> V_259 ,
F_163 ( V_35 , V_258 -> V_80 [ 1 ] ) , & V_232 ) ;
return F_21 ( F_19 ( V_35 , V_258 -> V_82 ) , & V_232 ) ;
}
static int F_170 ( struct V_34 * V_35 ,
struct V_73 * V_258 )
{
unsigned int V_36 ;
struct V_39 * V_40 = F_19 ( V_35 , V_258 -> V_80 [ 0 ] ) ;
struct V_41 V_42 ;
struct V_41 * V_260 = F_13 ( V_35 , V_84 ) ;
F_171 ( & V_42 ) ;
for ( V_36 = 0 ; V_36 <= V_261 ; ++ V_36 ) {
int V_65 ;
if ( ! F_172 ( V_260 , V_36 ) )
continue;
V_65 = F_50 ( V_36 ) ;
if ( V_65 <= 0 )
continue;
if ( ( unsigned ) V_65 < V_40 -> V_70 || ( unsigned ) V_65 > V_40 -> V_71 )
F_173 ( & V_42 , V_36 ) ;
}
return F_17 ( V_260 , & V_42 ) ;
}
static int F_174 ( struct V_34 * V_35 ,
struct V_73 * V_258 )
{
struct V_39 V_232 ;
unsigned int V_36 ;
V_232 . V_70 = V_262 ;
V_232 . V_71 = 0 ;
V_232 . V_69 = 0 ;
V_232 . V_72 = 0 ;
for ( V_36 = 0 ; V_36 <= V_261 ; ++ V_36 ) {
int V_65 ;
if ( ! F_172 ( F_13 ( V_35 , V_84 ) , V_36 ) )
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
return F_21 ( F_19 ( V_35 , V_258 -> V_82 ) , & V_232 ) ;
}
static int F_175 ( struct V_34 * V_35 ,
struct V_73 * V_258 )
{
struct V_37 * V_38 = V_258 -> V_259 ;
return F_176 ( F_19 ( V_35 , V_258 -> V_82 ) ,
V_263 . V_257 ,
V_263 . V_264 , V_38 -> V_265 ) ;
}
static int F_177 ( struct V_34 * V_35 ,
struct V_73 * V_258 )
{
struct V_39 V_232 ;
struct V_2 * V_3 = V_258 -> V_259 ;
V_232 . V_70 = 0 ;
V_232 . V_71 = V_3 -> V_266 ;
V_232 . V_69 = 0 ;
V_232 . V_72 = 0 ;
V_232 . integer = 1 ;
return F_21 ( F_19 ( V_35 , V_258 -> V_82 ) , & V_232 ) ;
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
F_180 ( F_22 ( V_44 , V_267 ) ) ;
F_180 ( F_22 ( V_44 , V_268 ) ) ;
F_180 ( F_22 ( V_44 , V_55 ) ) ;
F_180 ( F_22 ( V_44 , V_269 ) ) ;
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
V_269 , V_85 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_269 ,
F_161 , NULL ,
V_55 , V_85 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_269 ,
F_168 , ( void * ) 8 ,
V_270 , V_271 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_269 ,
F_168 , ( void * ) 8 ,
V_268 , V_267 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_85 ,
F_164 , NULL ,
V_269 , V_55 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_57 ,
F_168 , ( void * ) 1000000 ,
V_271 , V_272 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_57 ,
F_168 , ( void * ) 1000000 ,
V_267 , V_273 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_274 ,
F_164 , NULL ,
V_267 , V_271 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_271 ,
F_164 , NULL ,
V_267 , V_274 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_271 ,
F_168 , ( void * ) 8 ,
V_270 , V_269 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_271 ,
F_166 , ( void * ) 1000000 ,
V_272 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_267 ,
F_161 , NULL ,
V_271 , V_274 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_267 ,
F_168 , ( void * ) 8 ,
V_268 , V_269 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_267 ,
F_166 , ( void * ) 1000000 ,
V_273 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_270 ,
F_166 , ( void * ) 8 ,
V_271 , V_269 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_268 ,
F_166 , ( void * ) 8 ,
V_267 , V_269 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_272 ,
F_168 , ( void * ) 1000000 ,
V_271 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_273 ,
F_168 , ( void * ) 1000000 ,
V_267 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
return 0 ;
}
int F_182 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_37 * V_38 = & V_6 -> V_38 ;
int V_30 ;
unsigned int V_260 = 0 ;
if ( V_38 -> V_4 & V_275 )
V_260 |= 1 << V_276 ;
if ( V_38 -> V_4 & V_277 )
V_260 |= 1 << V_278 ;
if ( V_38 -> V_4 & V_279 ) {
if ( V_38 -> V_4 & V_275 )
V_260 |= 1 << V_280 ;
if ( V_38 -> V_4 & V_277 )
V_260 |= 1 << V_281 ;
if ( V_38 -> V_4 & V_282 )
V_260 |= 1 << V_283 ;
}
V_30 = F_183 ( V_6 , V_284 , V_260 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_184 ( V_6 , V_84 , V_38 -> V_285 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , V_286 , 1 << V_287 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_185 ( V_6 , V_85 ,
V_38 -> V_288 , V_38 -> V_289 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_185 ( V_6 , V_57 ,
V_38 -> V_290 , V_38 -> V_291 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_185 ( V_6 , V_270 ,
V_38 -> V_292 , V_38 -> V_293 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_185 ( V_6 , V_274 ,
V_38 -> V_294 , V_38 -> V_295 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_185 ( V_6 , V_268 ,
V_38 -> V_292 , V_38 -> V_266 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , 0 , V_268 ,
F_177 , V_3 ,
V_268 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_6 -> V_296 ) {
V_30 = F_185 ( V_6 , V_268 , 0 , V_6 -> V_296 ) ;
if ( V_30 < 0 )
return V_30 ;
}
if ( ! ( V_38 -> V_265 & ( V_297 | V_298 ) ) ) {
V_30 = F_181 ( V_6 , 0 , V_57 ,
F_175 , V_38 ,
V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
}
F_186 ( V_6 , V_271 ) ;
return 0 ;
}
static void F_187 ( struct V_2 * V_3 )
{
F_159 ( V_3 ) ;
}
void F_188 ( struct V_2 * V_3 )
{
V_3 -> V_299 -- ;
if ( V_3 -> V_299 > 0 )
return;
F_141 ( V_3 ) ;
if ( V_3 -> V_300 ) {
if ( V_3 -> V_26 -> V_132 != NULL )
V_3 -> V_26 -> V_132 ( V_3 ) ;
V_3 -> V_26 -> V_301 ( V_3 ) ;
V_3 -> V_300 = 0 ;
}
if ( F_52 ( & V_3 -> V_130 ) )
F_53 ( & V_3 -> V_130 ) ;
if ( V_3 -> V_302 ) {
V_3 -> V_302 ( V_3 ) ;
V_3 -> V_302 = NULL ;
}
F_189 ( V_3 ) ;
}
int F_190 ( struct V_7 * V_8 , int V_14 ,
struct V_218 * V_218 ,
struct V_2 * * V_303 )
{
struct V_2 * V_3 ;
int V_30 ;
V_30 = F_191 ( V_8 , V_14 , V_218 , & V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_3 -> V_299 > 1 ) {
* V_303 = V_3 ;
return 0 ;
}
V_30 = F_178 ( V_3 ) ;
if ( V_30 < 0 ) {
F_140 ( L_13 ) ;
goto error;
}
if ( ( V_30 = V_3 -> V_26 -> V_304 ( V_3 ) ) < 0 )
goto error;
V_3 -> V_300 = 1 ;
V_30 = F_182 ( V_3 ) ;
if ( V_30 < 0 ) {
F_140 ( L_14 ) ;
goto error;
}
* V_303 = V_3 ;
return 0 ;
error:
F_188 ( V_3 ) ;
return V_30 ;
}
static int F_192 ( struct V_218 * V_218 ,
struct V_7 * V_8 ,
int V_14 )
{
struct V_248 * V_249 ;
struct V_2 * V_3 ;
int V_30 ;
V_30 = F_190 ( V_8 , V_14 , V_218 , & V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
V_249 = F_193 ( sizeof( * V_249 ) , V_31 ) ;
if ( V_249 == NULL ) {
F_188 ( V_3 ) ;
return - V_32 ;
}
V_249 -> V_3 = V_3 ;
if ( V_3 -> V_299 == 1 ) {
V_3 -> V_218 = V_249 ;
V_3 -> V_302 = F_187 ;
}
V_218 -> V_252 = V_249 ;
return 0 ;
}
static int F_194 ( struct V_239 * V_239 , struct V_218 * V_218 )
{
struct V_7 * V_8 ;
int V_30 = F_195 ( V_239 , V_218 ) ;
if ( V_30 < 0 )
return V_30 ;
V_8 = F_148 ( F_147 ( V_239 ) ,
V_246 ) ;
V_30 = F_196 ( V_218 , V_8 , V_135 ) ;
if ( V_8 )
F_157 ( V_8 -> V_11 ) ;
return V_30 ;
}
static int F_197 ( struct V_239 * V_239 , struct V_218 * V_218 )
{
struct V_7 * V_8 ;
int V_30 = F_195 ( V_239 , V_218 ) ;
if ( V_30 < 0 )
return V_30 ;
V_8 = F_148 ( F_147 ( V_239 ) ,
V_247 ) ;
V_30 = F_196 ( V_218 , V_8 , V_305 ) ;
if ( V_8 )
F_157 ( V_8 -> V_11 ) ;
return V_30 ;
}
static int F_196 ( struct V_218 * V_218 , struct V_7 * V_8 , int V_14 )
{
int V_30 ;
T_5 V_221 ;
if ( V_8 == NULL ) {
V_30 = - V_234 ;
goto V_306;
}
V_30 = F_198 ( V_8 -> V_11 , V_218 ) ;
if ( V_30 < 0 )
goto V_306;
if ( ! F_199 ( V_8 -> V_11 -> V_307 ) ) {
V_30 = - V_33 ;
goto V_308;
}
F_135 ( & V_221 , V_229 ) ;
F_136 ( & V_8 -> V_309 , & V_221 ) ;
F_200 ( & V_8 -> V_310 ) ;
while ( 1 ) {
V_30 = F_192 ( V_218 , V_8 , V_14 ) ;
if ( V_30 >= 0 )
break;
if ( V_30 == - V_226 ) {
if ( V_218 -> V_216 & V_223 ) {
V_30 = - V_197 ;
break;
}
} else
break;
F_201 ( V_311 ) ;
F_202 ( & V_8 -> V_310 ) ;
F_203 () ;
F_200 ( & V_8 -> V_310 ) ;
if ( V_8 -> V_11 -> V_233 ) {
V_30 = - V_234 ;
break;
}
if ( F_134 ( V_229 ) ) {
V_30 = - V_230 ;
break;
}
}
F_139 ( & V_8 -> V_309 , & V_221 ) ;
F_202 ( & V_8 -> V_310 ) ;
if ( V_30 < 0 )
goto V_312;
return V_30 ;
V_312:
F_204 ( V_8 -> V_11 -> V_307 ) ;
V_308:
F_205 ( V_8 -> V_11 , V_218 ) ;
V_306:
return V_30 ;
}
static int F_206 ( struct V_239 * V_239 , struct V_218 * V_218 )
{
struct V_7 * V_8 ;
struct V_2 * V_3 ;
struct V_248 * V_249 ;
V_249 = V_218 -> V_252 ;
V_3 = V_249 -> V_3 ;
if ( F_207 ( ! V_3 ) )
return - V_95 ;
V_8 = V_3 -> V_8 ;
F_200 ( & V_8 -> V_310 ) ;
F_188 ( V_3 ) ;
F_11 ( V_249 ) ;
F_202 ( & V_8 -> V_310 ) ;
F_97 ( & V_8 -> V_309 ) ;
F_204 ( V_8 -> V_11 -> V_307 ) ;
F_205 ( V_8 -> V_11 , V_218 ) ;
return 0 ;
}
static T_6 F_208 ( struct V_2 * V_3 ,
T_3 V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_144 ;
T_6 V_313 ;
T_6 V_314 ;
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
V_313 = - V_172 ;
goto V_315;
case V_196 :
V_313 = - V_235 ;
goto V_315;
default:
V_313 = - V_99 ;
goto V_315;
}
V_314 = F_209 ( V_6 ) ;
if ( V_314 <= 0 ) {
V_313 = 0 ;
goto V_315;
}
if ( V_94 > ( T_3 ) V_314 )
V_94 = V_314 ;
V_144 = V_6 -> V_122 -> V_144 - V_94 ;
if ( V_144 < 0 )
V_144 += V_6 -> V_128 ;
V_6 -> V_122 -> V_144 = V_144 ;
V_313 = V_94 ;
V_315:
F_37 ( V_3 ) ;
return V_313 ;
}
static T_6 F_210 ( struct V_2 * V_3 ,
T_3 V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_144 ;
T_6 V_313 ;
T_6 V_314 ;
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
V_313 = - V_172 ;
goto V_315;
case V_196 :
V_313 = - V_235 ;
goto V_315;
default:
V_313 = - V_99 ;
goto V_315;
}
V_314 = F_211 ( V_6 ) ;
if ( V_314 <= 0 ) {
V_313 = 0 ;
goto V_315;
}
if ( V_94 > ( T_3 ) V_314 )
V_94 = V_314 ;
V_144 = V_6 -> V_122 -> V_144 - V_94 ;
if ( V_144 < 0 )
V_144 += V_6 -> V_128 ;
V_6 -> V_122 -> V_144 = V_144 ;
V_313 = V_94 ;
V_315:
F_37 ( V_3 ) ;
return V_313 ;
}
static T_6 F_212 ( struct V_2 * V_3 ,
T_3 V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_144 ;
T_6 V_313 ;
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
V_313 = - V_172 ;
goto V_315;
case V_196 :
V_313 = - V_235 ;
goto V_315;
default:
V_313 = - V_99 ;
goto V_315;
}
V_146 = F_66 ( V_6 ) ;
if ( V_146 <= 0 ) {
V_313 = 0 ;
goto V_315;
}
if ( V_94 > ( T_3 ) V_146 )
V_94 = V_146 ;
V_144 = V_6 -> V_122 -> V_144 + V_94 ;
if ( V_144 >= ( T_6 ) V_6 -> V_128 )
V_144 -= V_6 -> V_128 ;
V_6 -> V_122 -> V_144 = V_144 ;
V_313 = V_94 ;
V_315:
F_37 ( V_3 ) ;
return V_313 ;
}
static T_6 F_213 ( struct V_2 * V_3 ,
T_3 V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_144 ;
T_6 V_313 ;
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
V_313 = - V_172 ;
goto V_315;
case V_196 :
V_313 = - V_235 ;
goto V_315;
default:
V_313 = - V_99 ;
goto V_315;
}
V_146 = F_67 ( V_6 ) ;
if ( V_146 <= 0 ) {
V_313 = 0 ;
goto V_315;
}
if ( V_94 > ( T_3 ) V_146 )
V_94 = V_146 ;
V_144 = V_6 -> V_122 -> V_144 + V_94 ;
if ( V_144 >= ( T_6 ) V_6 -> V_128 )
V_144 -= V_6 -> V_128 ;
V_6 -> V_122 -> V_144 = V_144 ;
V_313 = V_94 ;
V_315:
F_37 ( V_3 ) ;
return V_313 ;
}
static int F_214 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_30 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_148 :
if ( V_3 -> V_14 == V_305 )
goto V_316;
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
V_316:
V_30 = - V_99 ;
break;
}
F_37 ( V_3 ) ;
return V_30 ;
}
static int F_215 ( struct V_2 * V_3 ,
T_6 T_2 * V_153 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_30 ;
T_6 V_317 = 0 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_148 :
if ( V_3 -> V_14 == V_305 )
goto V_316;
case V_147 :
if ( ( V_30 = F_64 ( V_3 ) ) < 0 )
break;
case V_98 :
case V_196 :
V_30 = 0 ;
if ( V_3 -> V_14 == V_135 )
V_317 = F_209 ( V_6 ) ;
else
V_317 = F_67 ( V_6 ) ;
V_317 += V_6 -> V_149 ;
break;
case V_209 :
V_30 = - V_172 ;
break;
default:
V_316:
V_30 = - V_99 ;
break;
}
F_37 ( V_3 ) ;
if ( ! V_30 )
if ( F_216 ( V_317 , V_153 ) )
V_30 = - V_33 ;
return V_30 ;
}
static int F_217 ( struct V_2 * V_3 ,
struct F_217 T_2 * V_318 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct F_217 V_319 ;
volatile struct V_320 * V_92 ;
volatile struct V_321 * V_122 ;
int V_30 ;
memset ( & V_319 , 0 , sizeof( V_319 ) ) ;
if ( F_218 ( V_319 . V_79 , ( unsigned T_2 * ) & ( V_318 -> V_79 ) ) )
return - V_33 ;
if ( F_62 ( & V_319 . V_322 . V_122 , & ( V_318 -> V_322 . V_122 ) , sizeof( struct V_321 ) ) )
return - V_33 ;
V_92 = V_6 -> V_92 ;
V_122 = V_6 -> V_122 ;
if ( V_319 . V_79 & V_323 ) {
V_30 = F_214 ( V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
}
F_36 ( V_3 ) ;
if ( ! ( V_319 . V_79 & V_324 ) )
V_122 -> V_144 = V_319 . V_322 . V_122 . V_144 ;
else
V_319 . V_322 . V_122 . V_144 = V_122 -> V_144 ;
if ( ! ( V_319 . V_79 & V_325 ) )
V_122 -> V_123 = V_319 . V_322 . V_122 . V_123 ;
else
V_319 . V_322 . V_122 . V_123 = V_122 -> V_123 ;
V_319 . V_159 . V_92 . V_91 = V_92 -> V_91 ;
V_319 . V_159 . V_92 . V_145 = V_92 -> V_145 ;
V_319 . V_159 . V_92 . V_141 = V_92 -> V_141 ;
V_319 . V_159 . V_92 . V_137 = V_92 -> V_137 ;
F_37 ( V_3 ) ;
if ( F_10 ( V_318 , & V_319 , sizeof( V_319 ) ) )
return - V_33 ;
return 0 ;
}
static int F_219 ( struct V_2 * V_3 , int T_2 * V_326 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_327 ;
if ( F_218 ( V_327 , V_326 ) )
return - V_33 ;
if ( V_327 < 0 || V_327 > V_328 )
return - V_62 ;
V_6 -> V_329 = V_330 ;
if ( V_327 == V_331 )
V_6 -> V_329 = V_331 ;
return 0 ;
}
static int F_220 ( struct V_218 * V_218 ,
struct V_2 * V_3 ,
unsigned int V_332 , void T_2 * V_327 )
{
switch ( V_332 ) {
case V_333 :
return F_216 ( V_334 , ( int T_2 * ) V_327 ) ? - V_33 : 0 ;
case V_335 :
return F_8 ( V_3 , V_327 ) ;
case V_336 :
return 0 ;
case V_337 :
return F_219 ( V_3 , V_327 ) ;
case V_338 :
return F_30 ( V_3 , V_327 ) ;
case V_339 :
return F_55 ( V_3 , V_327 ) ;
case V_340 :
return F_56 ( V_3 ) ;
case V_341 :
return F_61 ( V_3 , V_327 ) ;
case V_342 :
return F_68 ( V_3 , V_327 ) ;
case V_343 :
return F_70 ( V_3 , V_327 ) ;
case V_344 :
return F_128 ( V_3 , V_218 ) ;
case V_345 :
return F_124 ( V_3 ) ;
case V_346 :
return F_81 ( & V_182 , V_3 , V_147 ) ;
case V_347 :
return F_149 ( V_3 , ( int ) ( unsigned long ) V_327 ) ;
case V_348 :
return F_159 ( V_3 ) ;
case V_349 :
return F_116 ( V_3 ) ;
case V_350 :
return F_120 ( V_3 ) ;
case V_351 :
return F_214 ( V_3 ) ;
case V_352 :
return F_215 ( V_3 , V_327 ) ;
case V_353 :
return F_217 ( V_3 , V_327 ) ;
#ifdef F_221
case V_354 :
return F_222 ( V_3 , V_327 ) ;
case V_355 :
return F_223 ( V_3 , V_327 ) ;
#endif
case V_356 :
return F_133 ( V_3 , V_218 ) ;
case V_357 :
return F_141 ( V_3 ) ;
case V_358 :
{
int V_153 ;
F_36 ( V_3 ) ;
V_153 = F_104 ( V_3 , ( int ) ( unsigned long ) V_327 ) ;
F_37 ( V_3 ) ;
return V_153 ;
}
}
F_140 ( L_15 , V_332 ) ;
return - V_359 ;
}
static int F_224 ( struct V_218 * V_218 ,
struct V_2 * V_3 ,
unsigned int V_332 , void T_2 * V_327 )
{
if ( F_207 ( ! V_3 ) )
return - V_95 ;
if ( F_207 ( V_3 -> V_14 != V_135 ) )
return - V_62 ;
switch ( V_332 ) {
case V_360 :
{
struct V_361 V_362 ;
struct V_361 T_2 * V_363 = V_327 ;
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_133 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( F_216 ( 0 , & V_363 -> V_133 ) )
return - V_33 ;
if ( F_62 ( & V_362 , V_363 , sizeof( V_362 ) ) )
return - V_33 ;
V_133 = F_225 ( V_3 , V_362 . V_364 , V_362 . V_94 ) ;
F_226 ( V_133 , & V_363 -> V_133 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
case V_365 :
{
struct V_366 V_367 ;
struct V_366 T_2 * V_368 = V_327 ;
struct V_5 * V_6 = V_3 -> V_6 ;
void T_2 * * V_369 ;
T_6 V_133 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( V_6 -> V_109 > 128 )
return - V_62 ;
if ( F_216 ( 0 , & V_368 -> V_133 ) )
return - V_33 ;
if ( F_62 ( & V_367 , V_368 , sizeof( V_367 ) ) )
return - V_33 ;
V_369 = F_31 ( V_367 . V_369 ,
sizeof( void * ) * V_6 -> V_109 ) ;
if ( F_32 ( V_369 ) )
return F_33 ( V_369 ) ;
V_133 = F_227 ( V_3 , V_369 , V_367 . V_94 ) ;
F_11 ( V_369 ) ;
F_226 ( V_133 , & V_368 -> V_133 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
case V_370 :
{
T_3 V_94 ;
T_3 T_2 * V_371 = V_327 ;
T_6 V_133 ;
if ( F_218 ( V_94 , V_371 ) )
return - V_33 ;
if ( F_216 ( 0 , V_371 ) )
return - V_33 ;
V_133 = F_208 ( V_3 , V_94 ) ;
F_226 ( V_133 , V_371 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
case V_372 :
{
T_3 V_94 ;
T_3 T_2 * V_371 = V_327 ;
T_6 V_133 ;
if ( F_218 ( V_94 , V_371 ) )
return - V_33 ;
if ( F_216 ( 0 , V_371 ) )
return - V_33 ;
V_133 = F_212 ( V_3 , V_94 ) ;
F_226 ( V_133 , V_371 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
}
return F_220 ( V_218 , V_3 , V_332 , V_327 ) ;
}
static int F_228 ( struct V_218 * V_218 ,
struct V_2 * V_3 ,
unsigned int V_332 , void T_2 * V_327 )
{
if ( F_207 ( ! V_3 ) )
return - V_95 ;
if ( F_207 ( V_3 -> V_14 != V_305 ) )
return - V_62 ;
switch ( V_332 ) {
case V_373 :
{
struct V_361 V_362 ;
struct V_361 T_2 * V_363 = V_327 ;
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_133 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( F_216 ( 0 , & V_363 -> V_133 ) )
return - V_33 ;
if ( F_62 ( & V_362 , V_363 , sizeof( V_362 ) ) )
return - V_33 ;
V_133 = F_229 ( V_3 , V_362 . V_364 , V_362 . V_94 ) ;
F_226 ( V_133 , & V_363 -> V_133 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
case V_374 :
{
struct V_366 V_367 ;
struct V_366 T_2 * V_368 = V_327 ;
struct V_5 * V_6 = V_3 -> V_6 ;
void * V_369 ;
T_6 V_133 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( V_6 -> V_109 > 128 )
return - V_62 ;
if ( F_216 ( 0 , & V_368 -> V_133 ) )
return - V_33 ;
if ( F_62 ( & V_367 , V_368 , sizeof( V_367 ) ) )
return - V_33 ;
V_369 = F_31 ( V_367 . V_369 ,
sizeof( void * ) * V_6 -> V_109 ) ;
if ( F_32 ( V_369 ) )
return F_33 ( V_369 ) ;
V_133 = F_230 ( V_3 , V_369 , V_367 . V_94 ) ;
F_11 ( V_369 ) ;
F_226 ( V_133 , & V_368 -> V_133 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
case V_370 :
{
T_3 V_94 ;
T_3 T_2 * V_371 = V_327 ;
T_6 V_133 ;
if ( F_218 ( V_94 , V_371 ) )
return - V_33 ;
if ( F_216 ( 0 , V_371 ) )
return - V_33 ;
V_133 = F_210 ( V_3 , V_94 ) ;
F_226 ( V_133 , V_371 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
case V_372 :
{
T_3 V_94 ;
T_3 T_2 * V_371 = V_327 ;
T_6 V_133 ;
if ( F_218 ( V_94 , V_371 ) )
return - V_33 ;
if ( F_216 ( 0 , V_371 ) )
return - V_33 ;
V_133 = F_213 ( V_3 , V_94 ) ;
F_226 ( V_133 , V_371 ) ;
return V_133 < 0 ? V_133 : 0 ;
}
}
return F_220 ( V_218 , V_3 , V_332 , V_327 ) ;
}
static long F_231 ( struct V_218 * V_218 , unsigned int V_332 ,
unsigned long V_327 )
{
struct V_248 * V_249 ;
V_249 = V_218 -> V_252 ;
if ( ( ( V_332 >> 8 ) & 0xff ) != 'A' )
return - V_359 ;
return F_224 ( V_218 , V_249 -> V_3 , V_332 ,
( void T_2 * ) V_327 ) ;
}
static long F_232 ( struct V_218 * V_218 , unsigned int V_332 ,
unsigned long V_327 )
{
struct V_248 * V_249 ;
V_249 = V_218 -> V_252 ;
if ( ( ( V_332 >> 8 ) & 0xff ) != 'A' )
return - V_359 ;
return F_228 ( V_218 , V_249 -> V_3 , V_332 ,
( void T_2 * ) V_327 ) ;
}
int F_233 ( struct V_2 * V_3 ,
unsigned int V_332 , void * V_327 )
{
T_1 V_1 ;
int V_133 ;
V_1 = F_1 () ;
switch ( V_3 -> V_14 ) {
case V_135 :
V_133 = F_224 ( NULL , V_3 , V_332 ,
( void T_2 * ) V_327 ) ;
break;
case V_305 :
V_133 = F_228 ( NULL , V_3 , V_332 ,
( void T_2 * ) V_327 ) ;
break;
default:
V_133 = - V_62 ;
break;
}
F_5 ( V_1 ) ;
return V_133 ;
}
static T_7 F_234 ( struct V_218 * V_218 , char T_2 * V_364 , T_8 V_257 ,
T_9 * V_375 )
{
struct V_248 * V_249 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_133 ;
V_249 = V_218 -> V_252 ;
V_3 = V_249 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( ! F_235 ( V_6 , V_257 ) )
return - V_62 ;
V_257 = F_236 ( V_6 , V_257 ) ;
V_133 = F_229 ( V_3 , V_364 , V_257 ) ;
if ( V_133 > 0 )
V_133 = F_237 ( V_6 , V_133 ) ;
return V_133 ;
}
static T_7 F_238 ( struct V_218 * V_218 , const char T_2 * V_364 ,
T_8 V_257 , T_9 * V_375 )
{
struct V_248 * V_249 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_133 ;
V_249 = V_218 -> V_252 ;
V_3 = V_249 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( ! F_235 ( V_6 , V_257 ) )
return - V_62 ;
V_257 = F_236 ( V_6 , V_257 ) ;
V_133 = F_225 ( V_3 , V_364 , V_257 ) ;
if ( V_133 > 0 )
V_133 = F_237 ( V_6 , V_133 ) ;
return V_133 ;
}
static T_7 F_239 ( struct V_376 * V_377 , const struct V_378 * V_379 ,
unsigned long V_380 , T_9 V_381 )
{
struct V_248 * V_249 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_133 ;
unsigned long V_40 ;
void T_2 * * V_369 ;
T_3 V_94 ;
V_249 = V_377 -> V_382 -> V_252 ;
V_3 = V_249 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( V_380 > 1024 || V_380 != V_6 -> V_109 )
return - V_62 ;
if ( ! F_235 ( V_6 , V_379 -> V_383 ) )
return - V_62 ;
V_94 = F_240 ( V_6 , V_379 -> V_383 ) ;
V_369 = F_9 ( sizeof( void * ) * V_380 , V_31 ) ;
if ( V_369 == NULL )
return - V_32 ;
for ( V_40 = 0 ; V_40 < V_380 ; ++ V_40 )
V_369 [ V_40 ] = V_379 [ V_40 ] . V_384 ;
V_133 = F_230 ( V_3 , V_369 , V_94 ) ;
if ( V_133 > 0 )
V_133 = F_237 ( V_6 , V_133 ) ;
F_11 ( V_369 ) ;
return V_133 ;
}
static T_7 F_241 ( struct V_376 * V_377 , const struct V_378 * V_379 ,
unsigned long V_380 , T_9 V_381 )
{
struct V_248 * V_249 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_133 ;
unsigned long V_40 ;
void T_2 * * V_369 ;
T_3 V_94 ;
V_249 = V_377 -> V_382 -> V_252 ;
V_3 = V_249 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( V_380 > 128 || V_380 != V_6 -> V_109 ||
! F_235 ( V_6 , V_379 -> V_383 ) )
return - V_62 ;
V_94 = F_240 ( V_6 , V_379 -> V_383 ) ;
V_369 = F_9 ( sizeof( void * ) * V_380 , V_31 ) ;
if ( V_369 == NULL )
return - V_32 ;
for ( V_40 = 0 ; V_40 < V_380 ; ++ V_40 )
V_369 [ V_40 ] = V_379 [ V_40 ] . V_384 ;
V_133 = F_227 ( V_3 , V_369 , V_94 ) ;
if ( V_133 > 0 )
V_133 = F_237 ( V_6 , V_133 ) ;
F_11 ( V_369 ) ;
return V_133 ;
}
static unsigned int F_242 ( struct V_218 * V_218 , T_10 * V_221 )
{
struct V_248 * V_249 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
unsigned int V_260 ;
T_3 V_146 ;
V_249 = V_218 -> V_252 ;
V_3 = V_249 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
F_243 ( V_218 , & V_6 -> V_184 , V_221 ) ;
F_36 ( V_3 ) ;
V_146 = F_66 ( V_6 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_147 :
case V_98 :
case V_190 :
if ( V_146 >= V_6 -> V_122 -> V_123 ) {
V_260 = V_385 | V_386 ;
break;
}
case V_148 :
V_260 = 0 ;
break;
default:
V_260 = V_385 | V_386 | V_387 ;
break;
}
F_37 ( V_3 ) ;
return V_260 ;
}
static unsigned int F_244 ( struct V_218 * V_218 , T_10 * V_221 )
{
struct V_248 * V_249 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
unsigned int V_260 ;
T_3 V_146 ;
V_249 = V_218 -> V_252 ;
V_3 = V_249 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
F_243 ( V_218 , & V_6 -> V_184 , V_221 ) ;
F_36 ( V_3 ) ;
V_146 = F_67 ( V_6 ) ;
switch ( V_6 -> V_92 -> V_91 ) {
case V_147 :
case V_98 :
case V_190 :
if ( V_146 >= V_6 -> V_122 -> V_123 ) {
V_260 = V_388 | V_389 ;
break;
}
V_260 = 0 ;
break;
case V_148 :
if ( V_146 > 0 ) {
V_260 = V_388 | V_389 ;
break;
}
default:
V_260 = V_388 | V_389 | V_387 ;
break;
}
F_37 ( V_3 ) ;
return V_260 ;
}
static int F_245 ( struct V_390 * V_391 ,
struct V_392 * V_393 )
{
struct V_2 * V_3 = V_391 -> V_394 ;
struct V_5 * V_6 ;
if ( V_3 == NULL )
return V_395 ;
V_6 = V_3 -> V_6 ;
V_393 -> V_396 = F_246 ( V_6 -> V_92 ) ;
F_247 ( V_393 -> V_396 ) ;
return 0 ;
}
static int V_320 ( struct V_2 * V_3 , struct V_218 * V_218 ,
struct V_390 * V_391 )
{
long V_397 ;
if ( ! ( V_391 -> V_398 & V_399 ) )
return - V_62 ;
V_397 = V_391 -> V_400 - V_391 -> V_401 ;
if ( V_397 != F_248 ( sizeof( struct V_320 ) ) )
return - V_62 ;
V_391 -> V_402 = & V_403 ;
V_391 -> V_394 = V_3 ;
V_391 -> V_398 |= V_404 | V_405 ;
return 0 ;
}
static int F_249 ( struct V_390 * V_391 ,
struct V_392 * V_393 )
{
struct V_2 * V_3 = V_391 -> V_394 ;
struct V_5 * V_6 ;
if ( V_3 == NULL )
return V_395 ;
V_6 = V_3 -> V_6 ;
V_393 -> V_396 = F_246 ( V_6 -> V_122 ) ;
F_247 ( V_393 -> V_396 ) ;
return 0 ;
}
static int V_321 ( struct V_2 * V_3 , struct V_218 * V_218 ,
struct V_390 * V_391 )
{
long V_397 ;
if ( ! ( V_391 -> V_398 & V_399 ) )
return - V_62 ;
V_397 = V_391 -> V_400 - V_391 -> V_401 ;
if ( V_397 != F_248 ( sizeof( struct V_321 ) ) )
return - V_62 ;
V_391 -> V_402 = & V_406 ;
V_391 -> V_394 = V_3 ;
V_391 -> V_398 |= V_404 | V_405 ;
return 0 ;
}
static int V_320 ( struct V_2 * V_3 , struct V_218 * V_218 ,
struct V_390 * V_391 )
{
return - V_95 ;
}
static int V_321 ( struct V_2 * V_3 , struct V_218 * V_218 ,
struct V_390 * V_391 )
{
return - V_95 ;
}
static inline struct V_396 *
F_250 ( struct V_2 * V_3 , unsigned long V_407 )
{
void * V_408 = V_3 -> V_6 -> V_409 + V_407 ;
#if F_39 ( V_410 ) && F_39 ( V_411 )
if ( V_3 -> V_412 . V_413 . type == V_414 )
return F_246 ( F_251 ( V_408 ) ) ;
#endif
#if F_39 ( V_415 ) && F_39 ( V_416 )
if ( V_3 -> V_412 . V_413 . type == V_414 ) {
T_11 V_417 = V_3 -> V_6 -> V_418 + V_407 ;
V_417 -= F_252 ( V_3 -> V_412 . V_413 . V_413 ) ;
return F_253 ( V_417 >> V_419 ) ;
}
#endif
return F_246 ( V_408 ) ;
}
static int F_254 ( struct V_390 * V_391 ,
struct V_392 * V_393 )
{
struct V_2 * V_3 = V_391 -> V_394 ;
struct V_5 * V_6 ;
unsigned long V_375 ;
struct V_396 * V_396 ;
T_8 V_296 ;
if ( V_3 == NULL )
return V_395 ;
V_6 = V_3 -> V_6 ;
V_375 = V_393 -> V_420 << V_419 ;
V_296 = F_248 ( V_6 -> V_296 ) ;
if ( V_375 > V_296 - V_421 )
return V_395 ;
if ( V_3 -> V_26 -> V_396 )
V_396 = V_3 -> V_26 -> V_396 ( V_3 , V_375 ) ;
else
V_396 = F_250 ( V_3 , V_375 ) ;
if ( ! V_396 )
return V_395 ;
F_247 ( V_396 ) ;
V_393 -> V_396 = V_396 ;
return 0 ;
}
int F_255 ( struct V_2 * V_3 ,
struct V_390 * V_391 )
{
V_391 -> V_398 |= V_404 | V_405 ;
#ifdef F_256
if ( ! V_3 -> V_26 -> V_396 &&
V_3 -> V_412 . V_413 . type == V_414 )
return F_257 ( V_3 -> V_412 . V_413 . V_413 ,
V_391 ,
V_3 -> V_6 -> V_409 ,
V_3 -> V_6 -> V_418 ,
V_391 -> V_400 - V_391 -> V_401 ) ;
#elif F_39 ( V_410 ) && F_39 ( V_411 )
if ( V_3 -> V_412 . V_413 . type == V_414 &&
! F_258 ( V_3 -> V_412 . V_413 . V_413 ) )
V_391 -> V_422 = F_259 ( V_391 -> V_422 ) ;
#endif
V_391 -> V_402 = & V_423 ;
return 0 ;
}
int F_260 ( struct V_2 * V_3 ,
struct V_390 * V_391 )
{
long V_397 ;
unsigned long V_375 ;
V_391 -> V_422 = F_259 ( V_391 -> V_422 ) ;
V_391 -> V_398 |= V_424 ;
V_397 = V_391 -> V_400 - V_391 -> V_401 ;
V_375 = V_391 -> V_425 << V_419 ;
if ( F_261 ( V_391 , V_391 -> V_401 ,
( V_3 -> V_6 -> V_418 + V_375 ) >> V_419 ,
V_397 , V_391 -> V_422 ) )
return - V_226 ;
return 0 ;
}
int F_262 ( struct V_2 * V_3 , struct V_218 * V_218 ,
struct V_390 * V_391 )
{
struct V_5 * V_6 ;
long V_397 ;
unsigned long V_375 ;
T_8 V_296 ;
int V_30 ;
if ( V_3 -> V_14 == V_135 ) {
if ( ! ( V_391 -> V_398 & ( V_426 | V_399 ) ) )
return - V_62 ;
} else {
if ( ! ( V_391 -> V_398 & V_399 ) )
return - V_62 ;
}
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_92 -> V_91 == V_96 )
return - V_99 ;
if ( ! ( V_6 -> V_4 & V_279 ) )
return - V_95 ;
if ( V_6 -> V_106 == V_276 ||
V_6 -> V_106 == V_278 )
return - V_62 ;
V_397 = V_391 -> V_400 - V_391 -> V_401 ;
V_375 = V_391 -> V_425 << V_419 ;
V_296 = F_248 ( V_6 -> V_296 ) ;
if ( ( T_8 ) V_397 > V_296 )
return - V_62 ;
if ( V_375 > V_296 - V_397 )
return - V_62 ;
V_391 -> V_402 = & V_427 ;
V_391 -> V_394 = V_3 ;
if ( V_3 -> V_26 -> V_428 )
V_30 = V_3 -> V_26 -> V_428 ( V_3 , V_391 ) ;
else
V_30 = F_255 ( V_3 , V_391 ) ;
if ( ! V_30 )
F_263 ( & V_3 -> V_103 ) ;
return V_30 ;
}
static int F_264 ( struct V_218 * V_218 , struct V_390 * V_391 )
{
struct V_248 * V_249 ;
struct V_2 * V_3 ;
unsigned long V_375 ;
V_249 = V_218 -> V_252 ;
V_3 = V_249 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_375 = V_391 -> V_425 << V_419 ;
switch ( V_375 ) {
case V_429 :
if ( V_249 -> V_430 )
return - V_95 ;
return V_320 ( V_3 , V_218 , V_391 ) ;
case V_431 :
if ( V_249 -> V_430 )
return - V_95 ;
return V_321 ( V_3 , V_218 , V_391 ) ;
default:
return F_262 ( V_3 , V_218 , V_391 ) ;
}
return 0 ;
}
static int F_265 ( int V_237 , struct V_218 * V_218 , int V_432 )
{
struct V_248 * V_249 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
V_249 = V_218 -> V_252 ;
V_3 = V_249 -> V_3 ;
if ( F_38 ( V_3 ) )
return - V_95 ;
V_6 = V_3 -> V_6 ;
return F_266 ( V_237 , V_218 , V_432 , & V_6 -> V_433 ) ;
}
static void F_267 ( struct V_34 * V_35 ,
struct V_434 * V_435 )
{
unsigned int V_40 ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
V_35 -> V_79 = V_435 -> V_79 ;
for ( V_40 = 0 ; V_40 < F_268 ( V_435 -> V_436 ) ; V_40 ++ )
V_35 -> V_436 [ V_40 ] . V_65 [ 0 ] = V_435 -> V_436 [ V_40 ] ;
memcpy ( V_35 -> V_437 , V_435 -> V_437 , sizeof( V_435 -> V_437 ) ) ;
V_35 -> V_54 = F_269 ( V_435 -> V_54 ) ;
V_35 -> V_66 = F_269 ( V_435 -> V_66 ) ;
V_35 -> V_4 = V_435 -> V_4 ;
V_35 -> V_56 = V_435 -> V_56 ;
V_35 -> V_58 = V_435 -> V_58 ;
V_35 -> V_59 = V_435 -> V_59 ;
V_35 -> V_53 = V_435 -> V_53 ;
}
static void F_270 ( struct V_434 * V_435 ,
struct V_34 * V_35 )
{
unsigned int V_40 ;
memset ( V_435 , 0 , sizeof( * V_435 ) ) ;
V_435 -> V_79 = V_35 -> V_79 ;
for ( V_40 = 0 ; V_40 < F_268 ( V_435 -> V_436 ) ; V_40 ++ )
V_435 -> V_436 [ V_40 ] = V_35 -> V_436 [ V_40 ] . V_65 [ 0 ] ;
memcpy ( V_435 -> V_437 , V_35 -> V_437 , sizeof( V_435 -> V_437 ) ) ;
V_435 -> V_54 = F_271 ( V_35 -> V_54 ) ;
V_435 -> V_66 = F_271 ( V_35 -> V_66 ) ;
V_435 -> V_4 = V_35 -> V_4 ;
V_435 -> V_56 = V_35 -> V_56 ;
V_435 -> V_58 = V_35 -> V_58 ;
V_435 -> V_59 = V_35 -> V_59 ;
V_435 -> V_53 = V_35 -> V_53 ;
}
static int F_222 ( struct V_2 * V_3 ,
struct V_434 T_2 * V_438 )
{
struct V_34 * V_35 ;
struct V_434 * V_435 = NULL ;
int V_30 ;
V_35 = F_9 ( sizeof( * V_35 ) , V_31 ) ;
if ( ! V_35 )
return - V_32 ;
V_435 = F_31 ( V_438 , sizeof( * V_435 ) ) ;
if ( F_32 ( V_435 ) ) {
V_30 = F_33 ( V_435 ) ;
goto V_439;
}
F_267 ( V_35 , V_435 ) ;
V_30 = F_12 ( V_3 , V_35 ) ;
F_270 ( V_435 , V_35 ) ;
if ( F_10 ( V_438 , V_435 , sizeof( * V_435 ) ) ) {
if ( ! V_30 )
V_30 = - V_33 ;
}
F_11 ( V_435 ) ;
V_439:
F_11 ( V_35 ) ;
return V_30 ;
}
static int F_223 ( struct V_2 * V_3 ,
struct V_434 T_2 * V_438 )
{
struct V_34 * V_35 ;
struct V_434 * V_435 = NULL ;
int V_30 ;
V_35 = F_9 ( sizeof( * V_35 ) , V_31 ) ;
if ( ! V_35 )
return - V_32 ;
V_435 = F_31 ( V_438 , sizeof( * V_435 ) ) ;
if ( F_32 ( V_435 ) ) {
V_30 = F_33 ( V_435 ) ;
goto V_439;
}
F_267 ( V_35 , V_435 ) ;
V_30 = V_34 ( V_3 , V_35 ) ;
F_270 ( V_435 , V_35 ) ;
if ( F_10 ( V_438 , V_435 , sizeof( * V_435 ) ) ) {
if ( ! V_30 )
V_30 = - V_33 ;
}
F_11 ( V_435 ) ;
V_439:
F_11 ( V_35 ) ;
return V_30 ;
}
static unsigned long F_272 ( struct V_218 * V_218 ,
unsigned long V_417 ,
unsigned long V_440 ,
unsigned long V_420 ,
unsigned long V_79 )
{
struct V_248 * V_249 = V_218 -> V_252 ;
struct V_2 * V_3 = V_249 -> V_3 ;
struct V_5 * V_6 = V_3 -> V_6 ;
unsigned long V_375 = V_420 << V_419 ;
switch ( V_375 ) {
case V_429 :
return ( unsigned long ) V_6 -> V_92 ;
case V_431 :
return ( unsigned long ) V_6 -> V_122 ;
default:
return ( unsigned long ) V_6 -> V_409 + V_375 ;
}
}
