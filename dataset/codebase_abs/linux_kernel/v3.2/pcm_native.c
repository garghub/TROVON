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
static int V_34 ( struct V_2 * V_3 ,
struct V_34 * V_35 )
{
struct V_5 * V_6 ;
int V_30 , V_88 ;
unsigned int V_65 ;
T_3 V_91 ;
if ( F_35 ( V_3 ) )
return - V_92 ;
V_6 = V_3 -> V_6 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_93 -> V_94 ) {
case V_95 :
case V_96 :
case V_97 :
break;
default:
F_37 ( V_3 ) ;
return - V_98 ;
}
F_37 ( V_3 ) ;
#if F_38 ( V_99 ) || F_38 ( V_100 )
if ( ! V_3 -> V_101 . V_101 )
#endif
if ( F_39 ( & V_3 -> V_102 ) )
return - V_98 ;
V_35 -> V_54 = ~ 0U ;
V_30 = F_12 ( V_3 , V_35 ) ;
if ( V_30 < 0 )
goto V_103;
V_30 = F_40 ( V_3 , V_35 ) ;
if ( V_30 < 0 )
goto V_103;
if ( V_3 -> V_26 -> V_104 != NULL ) {
V_30 = V_3 -> V_26 -> V_104 ( V_3 , V_35 ) ;
if ( V_30 < 0 )
goto V_103;
}
V_6 -> V_105 = F_41 ( V_35 ) ;
V_6 -> V_106 = F_42 ( V_35 ) ;
V_6 -> V_107 = F_43 ( V_35 ) ;
V_6 -> V_108 = F_44 ( V_35 ) ;
V_6 -> V_89 = F_45 ( V_35 ) ;
V_6 -> V_90 = F_46 ( V_35 ) ;
V_6 -> V_109 = F_47 ( V_35 ) ;
V_6 -> V_110 = F_48 ( V_35 ) ;
V_6 -> V_4 = V_35 -> V_4 ;
V_6 -> V_58 = V_35 -> V_58 ;
V_6 -> V_59 = V_35 -> V_59 ;
V_6 -> V_111 =
( V_35 -> V_4 & V_112 ) &&
( V_35 -> V_79 & V_113 ) ;
V_65 = F_49 ( V_6 -> V_106 ) ;
V_6 -> V_114 = V_65 ;
V_65 *= V_6 -> V_108 ;
V_6 -> V_115 = V_65 ;
V_91 = 1 ;
while ( V_65 % 8 != 0 ) {
V_65 *= 2 ;
V_91 *= 2 ;
}
V_6 -> V_116 = V_65 / 8 ;
V_6 -> V_117 = V_91 ;
V_6 -> V_118 = V_119 ;
V_6 -> V_120 = 1 ;
V_6 -> V_121 -> V_122 = V_6 -> V_90 ;
V_6 -> V_123 = 1 ;
V_6 -> V_124 = V_6 -> V_110 ;
V_6 -> V_125 = 0 ;
V_6 -> V_126 = 0 ;
V_6 -> V_127 = V_6 -> V_110 ;
while ( V_6 -> V_127 * 2 <= V_128 - V_6 -> V_110 )
V_6 -> V_127 *= 2 ;
F_50 ( V_3 ) ;
V_6 -> V_93 -> V_94 = V_96 ;
if ( F_51 ( & V_3 -> V_129 ) )
F_52 ( & V_3 -> V_129 ) ;
if ( ( V_88 = F_34 ( V_6 ) ) >= 0 )
F_53 ( & V_3 -> V_129 ,
V_130 , V_88 ) ;
return 0 ;
V_103:
V_6 -> V_93 -> V_94 = V_95 ;
if ( V_3 -> V_26 -> V_131 != NULL )
V_3 -> V_26 -> V_131 ( V_3 ) ;
return V_30 ;
}
static int F_54 ( struct V_2 * V_3 ,
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
static int F_55 ( struct V_2 * V_3 )
{
struct V_5 * V_6 ;
int V_132 = 0 ;
if ( F_35 ( V_3 ) )
return - V_92 ;
V_6 = V_3 -> V_6 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_93 -> V_94 ) {
case V_96 :
case V_97 :
break;
default:
F_37 ( V_3 ) ;
return - V_98 ;
}
F_37 ( V_3 ) ;
if ( F_39 ( & V_3 -> V_102 ) )
return - V_98 ;
if ( V_3 -> V_26 -> V_131 )
V_132 = V_3 -> V_26 -> V_131 ( V_3 ) ;
V_6 -> V_93 -> V_94 = V_95 ;
F_52 ( & V_3 -> V_129 ) ;
return V_132 ;
}
static int F_56 ( struct V_2 * V_3 ,
struct F_56 * V_35 )
{
struct V_5 * V_6 ;
int V_30 ;
if ( F_35 ( V_3 ) )
return - V_92 ;
V_6 = V_3 -> V_6 ;
F_36 ( V_3 ) ;
if ( V_6 -> V_93 -> V_94 == V_95 ) {
F_37 ( V_3 ) ;
return - V_98 ;
}
F_37 ( V_3 ) ;
if ( V_35 -> V_118 > V_133 )
return - V_62 ;
if ( V_35 -> V_122 == 0 )
return - V_62 ;
if ( V_35 -> V_126 >= V_6 -> V_127 ) {
if ( V_35 -> V_125 != 0 )
return - V_62 ;
} else {
if ( V_35 -> V_126 > V_35 -> V_125 )
return - V_62 ;
if ( V_35 -> V_125 > V_6 -> V_110 )
return - V_62 ;
}
V_30 = 0 ;
F_36 ( V_3 ) ;
V_6 -> V_118 = V_35 -> V_118 ;
V_6 -> V_120 = V_35 -> V_120 ;
V_6 -> V_121 -> V_122 = V_35 -> V_122 ;
V_6 -> V_123 = V_35 -> V_123 ;
V_6 -> V_124 = V_35 -> V_124 ;
V_6 -> V_125 = V_35 -> V_125 ;
V_6 -> V_126 = V_35 -> V_126 ;
V_35 -> V_127 = V_6 -> V_127 ;
if ( F_57 ( V_3 ) ) {
if ( V_3 -> V_14 == V_134 &&
V_6 -> V_126 > 0 )
F_58 ( V_3 , V_135 ) ;
V_30 = F_59 ( V_3 , V_6 ) ;
}
F_37 ( V_3 ) ;
return V_30 ;
}
static int F_60 ( struct V_2 * V_3 ,
struct F_56 T_2 * V_87 )
{
struct F_56 V_35 ;
int V_30 ;
if ( F_61 ( & V_35 , V_87 , sizeof( V_35 ) ) )
return - V_33 ;
V_30 = F_56 ( V_3 , & V_35 ) ;
if ( F_10 ( V_87 , & V_35 , sizeof( V_35 ) ) )
return - V_33 ;
return V_30 ;
}
int F_62 ( struct V_2 * V_3 ,
struct F_62 * V_93 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_36 ( V_3 ) ;
V_93 -> V_94 = V_6 -> V_93 -> V_94 ;
V_93 -> V_136 = V_6 -> V_93 -> V_136 ;
if ( V_93 -> V_94 == V_95 )
goto V_137;
V_93 -> V_138 = V_6 -> V_138 ;
if ( F_57 ( V_3 ) ) {
F_63 ( V_3 ) ;
if ( V_6 -> V_118 == V_139 ) {
V_93 -> V_140 = V_6 -> V_93 -> V_140 ;
goto V_141;
}
}
F_64 ( V_6 , & V_93 -> V_140 ) ;
V_141:
V_93 -> V_142 = V_6 -> V_121 -> V_142 ;
V_93 -> V_143 = V_6 -> V_93 -> V_143 ;
if ( V_3 -> V_14 == V_134 ) {
V_93 -> V_144 = F_65 ( V_6 ) ;
if ( V_6 -> V_93 -> V_94 == V_145 ||
V_6 -> V_93 -> V_94 == V_146 ) {
V_93 -> V_147 = V_6 -> V_110 - V_93 -> V_144 ;
V_93 -> V_147 += V_6 -> V_147 ;
} else
V_93 -> V_147 = 0 ;
} else {
V_93 -> V_144 = F_66 ( V_6 ) ;
if ( V_6 -> V_93 -> V_94 == V_145 )
V_93 -> V_147 = V_93 -> V_144 + V_6 -> V_147 ;
else
V_93 -> V_147 = 0 ;
}
V_93 -> V_148 = V_6 -> V_148 ;
V_93 -> V_149 = V_6 -> V_149 ;
V_6 -> V_148 = 0 ;
V_6 -> V_149 = 0 ;
V_137:
F_37 ( V_3 ) ;
return 0 ;
}
static int F_67 ( struct V_2 * V_3 ,
struct F_62 T_2 * V_150 )
{
struct F_62 V_93 ;
int V_151 ;
memset ( & V_93 , 0 , sizeof( V_93 ) ) ;
V_151 = F_62 ( V_3 , & V_93 ) ;
if ( V_151 < 0 )
return V_151 ;
if ( F_10 ( V_150 , & V_93 , sizeof( V_93 ) ) )
return - V_33 ;
return 0 ;
}
static int F_68 ( struct V_2 * V_3 ,
struct F_68 * V_4 )
{
struct V_5 * V_6 ;
unsigned int V_152 ;
V_152 = V_4 -> V_152 ;
V_6 = V_3 -> V_6 ;
F_36 ( V_3 ) ;
if ( V_6 -> V_93 -> V_94 == V_95 ) {
F_37 ( V_3 ) ;
return - V_98 ;
}
F_37 ( V_3 ) ;
if ( V_152 >= V_6 -> V_108 )
return - V_62 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_152 = V_152 ;
return V_3 -> V_26 -> V_27 ( V_3 , V_153 , V_4 ) ;
}
static int F_69 ( struct V_2 * V_3 ,
struct F_68 T_2 * V_29 )
{
struct F_68 V_4 ;
int V_151 ;
if ( F_61 ( & V_4 , V_29 , sizeof( V_4 ) ) )
return - V_33 ;
V_151 = F_68 ( V_3 , & V_4 ) ;
if ( V_151 < 0 )
return V_151 ;
if ( F_10 ( V_29 , & V_4 , sizeof( V_4 ) ) )
return - V_33 ;
return 0 ;
}
static void F_70 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_154 == NULL )
return;
if ( V_6 -> V_154 == V_3 ) {
F_64 ( V_6 , & V_6 -> V_138 ) ;
} else {
F_70 ( V_6 -> V_154 ) ;
V_6 -> V_138 = V_6 -> V_154 -> V_6 -> V_138 ;
}
V_6 -> V_154 = NULL ;
}
static int F_71 ( struct V_155 * V_26 ,
struct V_2 * V_3 ,
int V_94 , int V_156 )
{
struct V_2 * V_157 = NULL ;
struct V_2 * V_158 ;
int V_151 = 0 ;
F_72 (s, substream) {
if ( V_156 && V_157 != V_3 )
F_73 ( & V_157 -> V_159 . V_160 ,
V_161 ) ;
V_151 = V_26 -> V_162 ( V_157 , V_94 ) ;
if ( V_151 < 0 )
goto V_163;
}
F_72 (s, substream) {
V_151 = V_26 -> V_164 ( V_157 , V_94 ) ;
if ( V_151 < 0 ) {
if ( V_26 -> V_165 ) {
F_72 (s1, substream) {
if ( V_158 == V_157 )
break;
V_26 -> V_165 ( V_158 , V_94 ) ;
}
}
V_157 = NULL ;
goto V_163;
}
}
F_72 (s, substream) {
V_26 -> V_166 ( V_157 , V_94 ) ;
}
V_163:
if ( V_156 ) {
F_72 (s1, substream) {
if ( V_158 != V_3 )
F_74 ( & V_158 -> V_159 . V_160 ) ;
if ( V_158 == V_157 )
break;
}
}
return V_151 ;
}
static int F_75 ( struct V_155 * V_26 ,
struct V_2 * V_3 ,
int V_94 )
{
int V_151 ;
V_151 = V_26 -> V_162 ( V_3 , V_94 ) ;
if ( V_151 < 0 )
return V_151 ;
V_151 = V_26 -> V_164 ( V_3 , V_94 ) ;
if ( V_151 == 0 )
V_26 -> V_166 ( V_3 , V_94 ) ;
else if ( V_26 -> V_165 )
V_26 -> V_165 ( V_3 , V_94 ) ;
return V_151 ;
}
static int F_76 ( struct V_155 * V_26 ,
struct V_2 * V_3 ,
int V_94 )
{
int V_151 ;
if ( F_77 ( V_3 ) ) {
if ( ! F_78 ( & V_3 -> V_167 -> V_160 ) ) {
F_74 ( & V_3 -> V_159 . V_160 ) ;
F_79 ( & V_3 -> V_167 -> V_160 ) ;
F_79 ( & V_3 -> V_159 . V_160 ) ;
}
V_151 = F_71 ( V_26 , V_3 , V_94 , 1 ) ;
F_74 ( & V_3 -> V_167 -> V_160 ) ;
} else {
V_151 = F_75 ( V_26 , V_3 , V_94 ) ;
}
return V_151 ;
}
static int F_80 ( struct V_155 * V_26 ,
struct V_2 * V_3 ,
int V_94 )
{
int V_151 ;
F_81 ( & V_168 ) ;
if ( F_77 ( V_3 ) ) {
F_79 ( & V_3 -> V_167 -> V_160 ) ;
F_79 ( & V_3 -> V_159 . V_160 ) ;
V_151 = F_71 ( V_26 , V_3 , V_94 , 1 ) ;
F_74 ( & V_3 -> V_159 . V_160 ) ;
F_74 ( & V_3 -> V_167 -> V_160 ) ;
} else {
F_79 ( & V_3 -> V_159 . V_160 ) ;
V_151 = F_75 ( V_26 , V_3 , V_94 ) ;
F_74 ( & V_3 -> V_159 . V_160 ) ;
}
F_82 ( & V_168 ) ;
return V_151 ;
}
static int F_83 ( struct V_155 * V_26 ,
struct V_2 * V_3 ,
int V_94 )
{
int V_151 ;
F_84 ( & V_169 ) ;
if ( F_77 ( V_3 ) )
V_151 = F_71 ( V_26 , V_3 , V_94 , 0 ) ;
else
V_151 = F_75 ( V_26 , V_3 , V_94 ) ;
F_85 ( & V_169 ) ;
return V_151 ;
}
static int F_86 ( struct V_2 * V_3 , int V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_93 -> V_94 != V_97 )
return - V_98 ;
if ( V_3 -> V_14 == V_134 &&
! F_87 ( V_3 ) )
return - V_170 ;
V_6 -> V_154 = V_3 ;
return 0 ;
}
static int F_88 ( struct V_2 * V_3 , int V_94 )
{
if ( V_3 -> V_6 -> V_154 != V_3 )
return 0 ;
return V_3 -> V_26 -> V_171 ( V_3 , V_172 ) ;
}
static void F_89 ( struct V_2 * V_3 , int V_94 )
{
if ( V_3 -> V_6 -> V_154 == V_3 )
V_3 -> V_26 -> V_171 ( V_3 , V_173 ) ;
}
static void F_90 ( struct V_2 * V_3 , int V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_70 ( V_3 ) ;
V_6 -> V_174 = V_175 ;
V_6 -> V_176 = ( V_6 -> V_110 * V_177 ) /
V_6 -> V_89 ;
V_6 -> V_93 -> V_94 = V_94 ;
if ( V_3 -> V_14 == V_134 &&
V_6 -> V_126 > 0 )
F_58 ( V_3 , V_135 ) ;
if ( V_3 -> V_178 )
F_91 ( V_3 -> V_178 , V_179 ,
& V_6 -> V_138 ) ;
}
int F_92 ( struct V_2 * V_3 )
{
return F_76 ( & V_180 , V_3 ,
V_145 ) ;
}
static int F_93 ( struct V_2 * V_3 , int V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_93 -> V_94 == V_95 )
return - V_98 ;
V_6 -> V_154 = V_3 ;
return 0 ;
}
static int F_94 ( struct V_2 * V_3 , int V_94 )
{
if ( V_3 -> V_6 -> V_154 == V_3 &&
F_57 ( V_3 ) )
V_3 -> V_26 -> V_171 ( V_3 , V_173 ) ;
return 0 ;
}
static void F_95 ( struct V_2 * V_3 , int V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_93 -> V_94 != V_94 ) {
F_70 ( V_3 ) ;
if ( V_3 -> V_178 )
F_91 ( V_3 -> V_178 , V_181 ,
& V_6 -> V_138 ) ;
V_6 -> V_93 -> V_94 = V_94 ;
}
F_96 ( & V_6 -> V_182 ) ;
F_96 ( & V_6 -> V_183 ) ;
}
int F_97 ( struct V_2 * V_3 , T_4 V_94 )
{
return F_76 ( & V_184 , V_3 , V_94 ) ;
}
int F_98 ( struct V_2 * V_3 )
{
return F_75 ( & V_184 , V_3 ,
V_96 ) ;
}
static int F_99 ( struct V_2 * V_3 , int V_185 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( ! ( V_6 -> V_4 & V_186 ) )
return - V_187 ;
if ( V_185 ) {
if ( V_6 -> V_93 -> V_94 != V_145 )
return - V_98 ;
} else if ( V_6 -> V_93 -> V_94 != V_188 )
return - V_98 ;
V_6 -> V_154 = V_3 ;
return 0 ;
}
static int F_100 ( struct V_2 * V_3 , int V_185 )
{
if ( V_3 -> V_6 -> V_154 != V_3 )
return 0 ;
if ( V_185 )
F_63 ( V_3 ) ;
V_3 -> V_6 -> V_174 = V_175 - V_177 * 1000 ;
return V_3 -> V_26 -> V_171 ( V_3 ,
V_185 ? V_189 :
V_190 ) ;
}
static void F_101 ( struct V_2 * V_3 , int V_185 )
{
if ( V_3 -> V_6 -> V_154 == V_3 )
V_3 -> V_26 -> V_171 ( V_3 ,
V_185 ? V_190 :
V_189 ) ;
}
static void F_102 ( struct V_2 * V_3 , int V_185 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_70 ( V_3 ) ;
if ( V_185 ) {
V_6 -> V_93 -> V_94 = V_188 ;
if ( V_3 -> V_178 )
F_91 ( V_3 -> V_178 ,
V_191 ,
& V_6 -> V_138 ) ;
F_96 ( & V_6 -> V_182 ) ;
F_96 ( & V_6 -> V_183 ) ;
} else {
V_6 -> V_93 -> V_94 = V_145 ;
if ( V_3 -> V_178 )
F_91 ( V_3 -> V_178 ,
V_192 ,
& V_6 -> V_138 ) ;
}
}
static int F_103 ( struct V_2 * V_3 , int V_185 )
{
return F_76 ( & V_193 , V_3 , V_185 ) ;
}
static int F_104 ( struct V_2 * V_3 , int V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_93 -> V_94 == V_194 )
return - V_195 ;
V_6 -> V_154 = V_3 ;
return 0 ;
}
static int F_105 ( struct V_2 * V_3 , int V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_154 != V_3 )
return 0 ;
if ( ! F_57 ( V_3 ) )
return 0 ;
V_3 -> V_26 -> V_171 ( V_3 , V_196 ) ;
return 0 ;
}
static void F_106 ( struct V_2 * V_3 , int V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_70 ( V_3 ) ;
if ( V_3 -> V_178 )
F_91 ( V_3 -> V_178 , V_197 ,
& V_6 -> V_138 ) ;
V_6 -> V_93 -> V_136 = V_6 -> V_93 -> V_94 ;
V_6 -> V_93 -> V_94 = V_194 ;
F_96 ( & V_6 -> V_182 ) ;
F_96 ( & V_6 -> V_183 ) ;
}
int F_107 ( struct V_2 * V_3 )
{
int V_30 ;
unsigned long V_79 ;
if ( ! V_3 )
return 0 ;
F_108 ( V_3 , V_79 ) ;
V_30 = F_76 ( & V_198 , V_3 , 0 ) ;
F_109 ( V_3 , V_79 ) ;
return V_30 ;
}
int F_110 ( struct V_7 * V_8 )
{
struct V_2 * V_3 ;
int V_14 , V_30 = 0 ;
if ( ! V_8 )
return 0 ;
for ( V_14 = 0 ; V_14 < 2 ; V_14 ++ ) {
for ( V_3 = V_8 -> V_199 [ V_14 ] . V_3 ;
V_3 ; V_3 = V_3 -> V_200 ) {
if ( V_3 -> V_6 == NULL )
continue;
V_30 = F_107 ( V_3 ) ;
if ( V_30 < 0 && V_30 != - V_195 )
return V_30 ;
}
}
return 0 ;
}
static int F_111 ( struct V_2 * V_3 , int V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( ! ( V_6 -> V_4 & V_201 ) )
return - V_187 ;
V_6 -> V_154 = V_3 ;
return 0 ;
}
static int F_112 ( struct V_2 * V_3 , int V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_154 != V_3 )
return 0 ;
if ( V_6 -> V_93 -> V_136 != V_145 &&
( V_6 -> V_93 -> V_136 != V_146 ||
V_3 -> V_14 != V_134 ) )
return 0 ;
return V_3 -> V_26 -> V_171 ( V_3 , V_202 ) ;
}
static void F_113 ( struct V_2 * V_3 , int V_94 )
{
if ( V_3 -> V_6 -> V_154 == V_3 &&
F_57 ( V_3 ) )
V_3 -> V_26 -> V_171 ( V_3 , V_196 ) ;
}
static void F_114 ( struct V_2 * V_3 , int V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_70 ( V_3 ) ;
if ( V_3 -> V_178 )
F_91 ( V_3 -> V_178 , V_203 ,
& V_6 -> V_138 ) ;
V_6 -> V_93 -> V_94 = V_6 -> V_93 -> V_136 ;
}
static int F_115 ( struct V_2 * V_3 )
{
struct V_204 * V_11 = V_3 -> V_8 -> V_11 ;
int V_151 ;
F_116 ( V_11 ) ;
if ( ( V_151 = F_117 ( V_11 , V_205 ) ) >= 0 )
V_151 = F_80 ( & V_206 , V_3 , 0 ) ;
F_118 ( V_11 ) ;
return V_151 ;
}
static int F_115 ( struct V_2 * V_3 )
{
return - V_187 ;
}
static int F_119 ( struct V_2 * V_3 )
{
struct V_204 * V_11 = V_3 -> V_8 -> V_11 ;
struct V_5 * V_6 = V_3 -> V_6 ;
int V_132 ;
F_116 ( V_11 ) ;
if ( V_6 -> V_93 -> V_94 == V_194 ) {
V_132 = F_117 ( V_11 , V_205 ) ;
if ( V_132 < 0 )
goto V_163;
}
F_36 ( V_3 ) ;
switch ( V_6 -> V_93 -> V_94 ) {
case V_207 :
V_132 = 0 ;
break;
case V_145 :
V_132 = F_97 ( V_3 , V_207 ) ;
break;
default:
V_132 = - V_98 ;
}
F_37 ( V_3 ) ;
V_163:
F_118 ( V_11 ) ;
return V_132 ;
}
static int F_120 ( struct V_2 * V_3 , int V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
switch ( V_6 -> V_93 -> V_94 ) {
case V_145 :
case V_97 :
case V_188 :
case V_194 :
return 0 ;
default:
return - V_98 ;
}
}
static int F_121 ( struct V_2 * V_3 , int V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_30 = V_3 -> V_26 -> V_27 ( V_3 , V_208 , NULL ) ;
if ( V_30 < 0 )
return V_30 ;
V_6 -> V_209 = 0 ;
V_6 -> V_210 = V_6 -> V_93 -> V_143 -
V_6 -> V_93 -> V_143 % V_6 -> V_90 ;
V_6 -> V_211 = V_6 -> V_93 -> V_143 ;
V_6 -> V_212 = 0 ;
return 0 ;
}
static void F_122 ( struct V_2 * V_3 , int V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
V_6 -> V_121 -> V_142 = V_6 -> V_93 -> V_143 ;
if ( V_3 -> V_14 == V_134 &&
V_6 -> V_126 > 0 )
F_58 ( V_3 , V_135 ) ;
}
static int F_123 ( struct V_2 * V_3 )
{
return F_83 ( & V_213 , V_3 , 0 ) ;
}
static int F_124 ( struct V_2 * V_3 ,
int V_214 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_93 -> V_94 == V_95 ||
V_6 -> V_93 -> V_94 == V_215 )
return - V_98 ;
if ( F_57 ( V_3 ) )
return - V_195 ;
V_3 -> V_214 = V_214 ;
return 0 ;
}
static int F_125 ( struct V_2 * V_3 , int V_94 )
{
int V_30 ;
V_30 = V_3 -> V_26 -> V_216 ( V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
return F_121 ( V_3 , 0 ) ;
}
static void F_126 ( struct V_2 * V_3 , int V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
V_6 -> V_121 -> V_142 = V_6 -> V_93 -> V_143 ;
V_6 -> V_93 -> V_94 = V_97 ;
}
static int F_127 ( struct V_2 * V_3 ,
struct V_217 * V_217 )
{
int V_151 ;
struct V_204 * V_11 = V_3 -> V_8 -> V_11 ;
int V_214 ;
if ( V_217 )
V_214 = V_217 -> V_214 ;
else
V_214 = V_3 -> V_214 ;
F_116 ( V_11 ) ;
if ( ( V_151 = F_117 ( V_11 , V_205 ) ) >= 0 )
V_151 = F_83 ( & V_218 ,
V_3 , V_214 ) ;
F_118 ( V_11 ) ;
return V_151 ;
}
static int F_128 ( struct V_2 * V_3 , int V_94 )
{
V_3 -> V_6 -> V_154 = V_3 ;
return 0 ;
}
static int F_129 ( struct V_2 * V_3 , int V_94 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_3 -> V_14 == V_134 ) {
switch ( V_6 -> V_93 -> V_94 ) {
case V_97 :
if ( ! F_130 ( V_3 ) ) {
F_88 ( V_3 , V_146 ) ;
F_90 ( V_3 , V_146 ) ;
}
break;
case V_145 :
V_6 -> V_93 -> V_94 = V_146 ;
break;
default:
break;
}
} else {
if ( V_6 -> V_93 -> V_94 == V_145 ) {
int V_219 = F_66 ( V_6 ) > 0 ?
V_146 : V_96 ;
F_94 ( V_3 , V_219 ) ;
F_95 ( V_3 , V_219 ) ;
}
}
return 0 ;
}
static void F_131 ( struct V_2 * V_3 , int V_94 )
{
}
static int F_132 ( struct V_2 * V_3 ,
struct V_217 * V_217 )
{
struct V_204 * V_11 ;
struct V_5 * V_6 ;
struct V_2 * V_157 ;
T_5 V_220 ;
int V_132 = 0 ;
int V_221 = 0 ;
V_11 = V_3 -> V_8 -> V_11 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_93 -> V_94 == V_95 )
return - V_98 ;
F_116 ( V_11 ) ;
if ( V_6 -> V_93 -> V_94 == V_194 ) {
V_132 = F_117 ( V_11 , V_205 ) ;
if ( V_132 < 0 ) {
F_118 ( V_11 ) ;
return V_132 ;
}
}
if ( V_217 ) {
if ( V_217 -> V_214 & V_222 )
V_221 = 1 ;
} else if ( V_3 -> V_214 & V_222 )
V_221 = 1 ;
F_84 ( & V_169 ) ;
F_36 ( V_3 ) ;
if ( V_6 -> V_93 -> V_94 == V_188 )
F_103 ( V_3 , 0 ) ;
V_132 = F_76 ( & V_223 , V_3 , 0 ) ;
if ( V_132 < 0 )
goto V_224;
if ( V_221 ) {
V_132 = - V_225 ;
goto V_224;
}
for (; ; ) {
long V_226 ;
struct V_5 * V_227 ;
if ( F_133 ( V_228 ) ) {
V_132 = - V_229 ;
break;
}
V_227 = NULL ;
F_72 (s, substream) {
if ( V_157 -> V_14 != V_134 )
continue;
V_6 = V_157 -> V_6 ;
if ( V_6 -> V_93 -> V_94 == V_146 ) {
V_227 = V_6 ;
break;
}
}
if ( ! V_227 )
break;
F_134 ( & V_220 , V_228 ) ;
F_135 ( & V_227 -> V_182 , & V_220 ) ;
F_37 ( V_3 ) ;
F_85 ( & V_169 ) ;
F_118 ( V_11 ) ;
if ( V_6 -> V_111 )
V_226 = V_230 ;
else {
V_226 = 10 ;
if ( V_6 -> V_89 ) {
long V_231 = V_6 -> V_90 * 2 / V_6 -> V_89 ;
V_226 = V_71 ( V_231 , V_226 ) ;
}
V_226 = F_136 ( V_226 * 1000 ) ;
}
V_226 = F_137 ( V_226 ) ;
F_116 ( V_11 ) ;
F_84 ( & V_169 ) ;
F_36 ( V_3 ) ;
F_138 ( & V_227 -> V_182 , & V_220 ) ;
if ( V_226 == 0 ) {
if ( V_3 -> V_6 -> V_93 -> V_94 == V_194 )
V_132 = - V_232 ;
else {
F_139 ( L_12 ) ;
F_97 ( V_3 , V_96 ) ;
V_132 = - V_233 ;
}
break;
}
}
V_224:
F_37 ( V_3 ) ;
F_85 ( & V_169 ) ;
F_118 ( V_11 ) ;
return V_132 ;
}
static int F_140 ( struct V_2 * V_3 )
{
struct V_5 * V_6 ;
int V_132 = 0 ;
if ( F_35 ( V_3 ) )
return - V_92 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_93 -> V_94 == V_95 ||
V_6 -> V_93 -> V_94 == V_215 ||
V_6 -> V_93 -> V_94 == V_194 )
return - V_98 ;
F_36 ( V_3 ) ;
if ( V_6 -> V_93 -> V_94 == V_188 )
F_103 ( V_3 , 0 ) ;
F_97 ( V_3 , V_96 ) ;
F_37 ( V_3 ) ;
return V_132 ;
}
static struct V_217 * F_141 ( int V_234 )
{
struct V_217 * V_217 ;
struct V_235 * V_235 ;
unsigned int V_236 ;
V_217 = F_142 ( V_234 ) ;
if ( ! V_217 )
return NULL ;
V_235 = V_217 -> V_237 . V_238 -> V_239 ;
if ( ! F_143 ( V_235 -> V_240 ) ||
F_144 ( V_235 ) != V_241 ) {
F_145 ( V_217 ) ;
return NULL ;
}
V_236 = F_146 ( V_235 ) ;
if ( ! F_147 ( V_236 , V_242 ) &&
! F_147 ( V_236 , V_243 ) ) {
F_145 ( V_217 ) ;
return NULL ;
}
return V_217 ;
}
static int F_148 ( struct V_2 * V_3 , int V_234 )
{
int V_151 = 0 ;
struct V_217 * V_217 ;
struct V_244 * V_245 ;
struct V_2 * V_246 ;
V_217 = F_141 ( V_234 ) ;
if ( ! V_217 )
return - V_98 ;
V_245 = V_217 -> V_247 ;
V_246 = V_245 -> V_3 ;
F_149 ( & V_169 ) ;
F_150 ( & V_168 ) ;
if ( V_3 -> V_6 -> V_93 -> V_94 == V_95 ||
V_3 -> V_6 -> V_93 -> V_94 != V_246 -> V_6 -> V_93 -> V_94 ) {
V_151 = - V_98 ;
goto V_137;
}
if ( F_77 ( V_246 ) ) {
V_151 = - V_248 ;
goto V_137;
}
if ( ! F_77 ( V_3 ) ) {
V_3 -> V_167 = F_9 ( sizeof( struct V_249 ) , V_250 ) ;
if ( V_3 -> V_167 == NULL ) {
V_151 = - V_32 ;
goto V_137;
}
F_151 ( & V_3 -> V_167 -> V_160 ) ;
F_152 ( & V_3 -> V_167 -> V_251 ) ;
F_153 ( & V_3 -> V_252 , & V_3 -> V_167 -> V_251 ) ;
V_3 -> V_167 -> V_253 = 1 ;
}
F_153 ( & V_246 -> V_252 , & V_3 -> V_167 -> V_251 ) ;
V_3 -> V_167 -> V_253 ++ ;
V_246 -> V_167 = V_3 -> V_167 ;
V_137:
F_154 ( & V_168 ) ;
F_155 ( & V_169 ) ;
F_145 ( V_217 ) ;
return V_151 ;
}
static void F_156 ( struct V_2 * V_3 )
{
V_3 -> V_167 = & V_3 -> V_159 ;
F_152 ( & V_3 -> V_159 . V_251 ) ;
F_153 ( & V_3 -> V_252 , & V_3 -> V_159 . V_251 ) ;
}
static int F_157 ( struct V_2 * V_3 )
{
struct V_2 * V_157 ;
int V_151 = 0 ;
F_149 ( & V_169 ) ;
F_150 ( & V_168 ) ;
if ( ! F_77 ( V_3 ) ) {
V_151 = - V_248 ;
goto V_137;
}
F_158 ( & V_3 -> V_252 ) ;
V_3 -> V_167 -> V_253 -- ;
if ( V_3 -> V_167 -> V_253 == 1 ) {
F_72 (s, substream) {
F_156 ( V_157 ) ;
break;
}
F_11 ( V_3 -> V_167 ) ;
}
F_156 ( V_3 ) ;
V_137:
F_154 ( & V_168 ) ;
F_155 ( & V_169 ) ;
return V_151 ;
}
static int F_159 ( struct V_34 * V_35 ,
struct V_73 * V_254 )
{
struct V_39 V_231 ;
F_160 ( F_161 ( V_35 , V_254 -> V_80 [ 0 ] ) ,
F_161 ( V_35 , V_254 -> V_80 [ 1 ] ) , & V_231 ) ;
return F_21 ( F_19 ( V_35 , V_254 -> V_82 ) , & V_231 ) ;
}
static int F_162 ( struct V_34 * V_35 ,
struct V_73 * V_254 )
{
struct V_39 V_231 ;
F_163 ( F_161 ( V_35 , V_254 -> V_80 [ 0 ] ) ,
F_161 ( V_35 , V_254 -> V_80 [ 1 ] ) , & V_231 ) ;
return F_21 ( F_19 ( V_35 , V_254 -> V_82 ) , & V_231 ) ;
}
static int F_164 ( struct V_34 * V_35 ,
struct V_73 * V_254 )
{
struct V_39 V_231 ;
F_165 ( F_161 ( V_35 , V_254 -> V_80 [ 0 ] ) ,
F_161 ( V_35 , V_254 -> V_80 [ 1 ] ) ,
( unsigned long ) V_254 -> V_255 , & V_231 ) ;
return F_21 ( F_19 ( V_35 , V_254 -> V_82 ) , & V_231 ) ;
}
static int F_166 ( struct V_34 * V_35 ,
struct V_73 * V_254 )
{
struct V_39 V_231 ;
F_167 ( F_161 ( V_35 , V_254 -> V_80 [ 0 ] ) ,
( unsigned long ) V_254 -> V_255 ,
F_161 ( V_35 , V_254 -> V_80 [ 1 ] ) , & V_231 ) ;
return F_21 ( F_19 ( V_35 , V_254 -> V_82 ) , & V_231 ) ;
}
static int F_168 ( struct V_34 * V_35 ,
struct V_73 * V_254 )
{
unsigned int V_36 ;
struct V_39 * V_40 = F_19 ( V_35 , V_254 -> V_80 [ 0 ] ) ;
struct V_41 V_42 ;
struct V_41 * V_256 = F_13 ( V_35 , V_84 ) ;
F_169 ( & V_42 ) ;
for ( V_36 = 0 ; V_36 <= V_257 ; ++ V_36 ) {
int V_65 ;
if ( ! F_170 ( V_256 , V_36 ) )
continue;
V_65 = F_49 ( V_36 ) ;
if ( V_65 <= 0 )
continue;
if ( ( unsigned ) V_65 < V_40 -> V_70 || ( unsigned ) V_65 > V_40 -> V_71 )
F_171 ( & V_42 , V_36 ) ;
}
return F_17 ( V_256 , & V_42 ) ;
}
static int F_172 ( struct V_34 * V_35 ,
struct V_73 * V_254 )
{
struct V_39 V_231 ;
unsigned int V_36 ;
V_231 . V_70 = V_258 ;
V_231 . V_71 = 0 ;
V_231 . V_69 = 0 ;
V_231 . V_72 = 0 ;
for ( V_36 = 0 ; V_36 <= V_257 ; ++ V_36 ) {
int V_65 ;
if ( ! F_170 ( F_13 ( V_35 , V_84 ) , V_36 ) )
continue;
V_65 = F_49 ( V_36 ) ;
if ( V_65 <= 0 )
continue;
if ( V_231 . V_70 > ( unsigned ) V_65 )
V_231 . V_70 = V_65 ;
if ( V_231 . V_71 < ( unsigned ) V_65 )
V_231 . V_71 = V_65 ;
}
V_231 . integer = 1 ;
return F_21 ( F_19 ( V_35 , V_254 -> V_82 ) , & V_231 ) ;
}
static int F_173 ( struct V_34 * V_35 ,
struct V_73 * V_254 )
{
struct V_37 * V_38 = V_254 -> V_255 ;
return F_174 ( F_19 ( V_35 , V_254 -> V_82 ) ,
V_259 . V_253 ,
V_259 . V_260 , V_38 -> V_261 ) ;
}
static int F_175 ( struct V_34 * V_35 ,
struct V_73 * V_254 )
{
struct V_39 V_231 ;
struct V_2 * V_3 = V_254 -> V_255 ;
V_231 . V_70 = 0 ;
V_231 . V_71 = V_3 -> V_262 ;
V_231 . V_69 = 0 ;
V_231 . V_72 = 0 ;
V_231 . integer = 1 ;
return F_21 ( F_19 ( V_35 , V_254 -> V_82 ) , & V_231 ) ;
}
int F_176 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_43 * V_44 = & V_6 -> V_45 ;
int V_36 , V_30 ;
for ( V_36 = V_60 ; V_36 <= V_61 ; V_36 ++ ) {
F_169 ( F_18 ( V_44 , V_36 ) ) ;
}
for ( V_36 = V_67 ; V_36 <= V_49 ; V_36 ++ ) {
F_177 ( F_22 ( V_44 , V_36 ) ) ;
}
F_178 ( F_22 ( V_44 , V_85 ) ) ;
F_178 ( F_22 ( V_44 , V_263 ) ) ;
F_178 ( F_22 ( V_44 , V_264 ) ) ;
F_178 ( F_22 ( V_44 , V_55 ) ) ;
F_178 ( F_22 ( V_44 , V_265 ) ) ;
V_30 = F_179 ( V_6 , 0 , V_84 ,
F_168 , NULL ,
V_55 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_179 ( V_6 , 0 , V_55 ,
F_172 , NULL ,
V_84 ,
V_55 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_179 ( V_6 , 0 , V_55 ,
F_162 , NULL ,
V_265 , V_85 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_179 ( V_6 , 0 , V_265 ,
F_159 , NULL ,
V_55 , V_85 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_179 ( V_6 , 0 , V_265 ,
F_166 , ( void * ) 8 ,
V_266 , V_267 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_179 ( V_6 , 0 , V_265 ,
F_166 , ( void * ) 8 ,
V_264 , V_263 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_179 ( V_6 , 0 , V_85 ,
F_162 , NULL ,
V_265 , V_55 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_179 ( V_6 , 0 , V_57 ,
F_166 , ( void * ) 1000000 ,
V_267 , V_268 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_179 ( V_6 , 0 , V_57 ,
F_166 , ( void * ) 1000000 ,
V_263 , V_269 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_179 ( V_6 , 0 , V_270 ,
F_162 , NULL ,
V_263 , V_267 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_179 ( V_6 , 0 , V_267 ,
F_162 , NULL ,
V_263 , V_270 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_179 ( V_6 , 0 , V_267 ,
F_166 , ( void * ) 8 ,
V_266 , V_265 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_179 ( V_6 , 0 , V_267 ,
F_164 , ( void * ) 1000000 ,
V_268 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_179 ( V_6 , 0 , V_263 ,
F_159 , NULL ,
V_267 , V_270 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_179 ( V_6 , 0 , V_263 ,
F_166 , ( void * ) 8 ,
V_264 , V_265 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_179 ( V_6 , 0 , V_263 ,
F_164 , ( void * ) 1000000 ,
V_269 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_179 ( V_6 , 0 , V_266 ,
F_164 , ( void * ) 8 ,
V_267 , V_265 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_179 ( V_6 , 0 , V_264 ,
F_164 , ( void * ) 8 ,
V_263 , V_265 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_179 ( V_6 , 0 , V_268 ,
F_166 , ( void * ) 1000000 ,
V_267 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_179 ( V_6 , 0 , V_269 ,
F_166 , ( void * ) 1000000 ,
V_263 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
return 0 ;
}
int F_180 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_37 * V_38 = & V_6 -> V_38 ;
int V_30 ;
unsigned int V_256 = 0 ;
if ( V_38 -> V_4 & V_271 )
V_256 |= 1 << V_272 ;
if ( V_38 -> V_4 & V_273 )
V_256 |= 1 << V_274 ;
if ( V_38 -> V_4 & V_275 ) {
if ( V_38 -> V_4 & V_271 )
V_256 |= 1 << V_276 ;
if ( V_38 -> V_4 & V_273 )
V_256 |= 1 << V_277 ;
if ( V_38 -> V_4 & V_278 )
V_256 |= 1 << V_279 ;
}
V_30 = F_181 ( V_6 , V_280 , V_256 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_182 ( V_6 , V_84 , V_38 -> V_281 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_181 ( V_6 , V_282 , 1 << V_283 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , V_85 ,
V_38 -> V_284 , V_38 -> V_285 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , V_57 ,
V_38 -> V_286 , V_38 -> V_287 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , V_266 ,
V_38 -> V_288 , V_38 -> V_289 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , V_270 ,
V_38 -> V_290 , V_38 -> V_291 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , V_264 ,
V_38 -> V_288 , V_38 -> V_262 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_179 ( V_6 , 0 , V_264 ,
F_175 , V_3 ,
V_264 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_6 -> V_292 ) {
V_30 = F_183 ( V_6 , V_264 , 0 , V_6 -> V_292 ) ;
if ( V_30 < 0 )
return - V_62 ;
}
if ( ! ( V_38 -> V_261 & ( V_293 | V_294 ) ) ) {
V_30 = F_179 ( V_6 , 0 , V_57 ,
F_173 , V_38 ,
V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
}
F_184 ( V_6 , V_267 ) ;
return 0 ;
}
static void F_185 ( struct V_2 * V_3 )
{
F_157 ( V_3 ) ;
}
void F_186 ( struct V_2 * V_3 )
{
V_3 -> V_295 -- ;
if ( V_3 -> V_295 > 0 )
return;
F_140 ( V_3 ) ;
if ( V_3 -> V_296 ) {
if ( V_3 -> V_26 -> V_131 != NULL )
V_3 -> V_26 -> V_131 ( V_3 ) ;
V_3 -> V_26 -> V_297 ( V_3 ) ;
V_3 -> V_296 = 0 ;
}
if ( F_51 ( & V_3 -> V_129 ) )
F_52 ( & V_3 -> V_129 ) ;
if ( V_3 -> V_298 ) {
V_3 -> V_298 ( V_3 ) ;
V_3 -> V_298 = NULL ;
}
F_187 ( V_3 ) ;
}
int F_188 ( struct V_7 * V_8 , int V_14 ,
struct V_217 * V_217 ,
struct V_2 * * V_299 )
{
struct V_2 * V_3 ;
int V_30 ;
V_30 = F_189 ( V_8 , V_14 , V_217 , & V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_3 -> V_295 > 1 ) {
* V_299 = V_3 ;
return 0 ;
}
V_30 = F_176 ( V_3 ) ;
if ( V_30 < 0 ) {
F_139 ( L_13 ) ;
goto error;
}
if ( ( V_30 = V_3 -> V_26 -> V_300 ( V_3 ) ) < 0 )
goto error;
V_3 -> V_296 = 1 ;
V_30 = F_180 ( V_3 ) ;
if ( V_30 < 0 ) {
F_139 ( L_14 ) ;
goto error;
}
* V_299 = V_3 ;
return 0 ;
error:
F_186 ( V_3 ) ;
return V_30 ;
}
static int F_190 ( struct V_217 * V_217 ,
struct V_7 * V_8 ,
int V_14 )
{
struct V_244 * V_245 ;
struct V_2 * V_3 ;
int V_30 ;
V_30 = F_188 ( V_8 , V_14 , V_217 , & V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
V_245 = F_191 ( sizeof( * V_245 ) , V_31 ) ;
if ( V_245 == NULL ) {
F_186 ( V_3 ) ;
return - V_32 ;
}
V_245 -> V_3 = V_3 ;
if ( V_3 -> V_295 == 1 ) {
V_3 -> V_217 = V_245 ;
V_3 -> V_298 = F_185 ;
}
V_217 -> V_247 = V_245 ;
return 0 ;
}
static int F_192 ( struct V_235 * V_235 , struct V_217 * V_217 )
{
struct V_7 * V_8 ;
int V_30 = F_193 ( V_235 , V_217 ) ;
if ( V_30 < 0 )
return V_30 ;
V_8 = F_147 ( F_146 ( V_235 ) ,
V_242 ) ;
return F_194 ( V_217 , V_8 , V_134 ) ;
}
static int F_195 ( struct V_235 * V_235 , struct V_217 * V_217 )
{
struct V_7 * V_8 ;
int V_30 = F_193 ( V_235 , V_217 ) ;
if ( V_30 < 0 )
return V_30 ;
V_8 = F_147 ( F_146 ( V_235 ) ,
V_243 ) ;
return F_194 ( V_217 , V_8 , V_301 ) ;
}
static int F_194 ( struct V_217 * V_217 , struct V_7 * V_8 , int V_14 )
{
int V_30 ;
T_5 V_220 ;
if ( V_8 == NULL ) {
V_30 = - V_302 ;
goto V_303;
}
V_30 = F_196 ( V_8 -> V_11 , V_217 ) ;
if ( V_30 < 0 )
goto V_303;
if ( ! F_197 ( V_8 -> V_11 -> V_304 ) ) {
V_30 = - V_33 ;
goto V_305;
}
F_134 ( & V_220 , V_228 ) ;
F_135 ( & V_8 -> V_306 , & V_220 ) ;
F_198 ( & V_8 -> V_307 ) ;
while ( 1 ) {
V_30 = F_190 ( V_217 , V_8 , V_14 ) ;
if ( V_30 >= 0 )
break;
if ( V_30 == - V_225 ) {
if ( V_217 -> V_214 & V_222 ) {
V_30 = - V_195 ;
break;
}
} else
break;
F_199 ( V_308 ) ;
F_200 ( & V_8 -> V_307 ) ;
F_201 () ;
F_198 ( & V_8 -> V_307 ) ;
if ( F_133 ( V_228 ) ) {
V_30 = - V_229 ;
break;
}
}
F_138 ( & V_8 -> V_306 , & V_220 ) ;
F_200 ( & V_8 -> V_307 ) ;
if ( V_30 < 0 )
goto V_309;
return V_30 ;
V_309:
F_202 ( V_8 -> V_11 -> V_304 ) ;
V_305:
F_203 ( V_8 -> V_11 , V_217 ) ;
V_303:
return V_30 ;
}
static int F_204 ( struct V_235 * V_235 , struct V_217 * V_217 )
{
struct V_7 * V_8 ;
struct V_2 * V_3 ;
struct V_244 * V_245 ;
V_245 = V_217 -> V_247 ;
V_3 = V_245 -> V_3 ;
if ( F_205 ( ! V_3 ) )
return - V_92 ;
V_8 = V_3 -> V_8 ;
F_198 ( & V_8 -> V_307 ) ;
F_186 ( V_3 ) ;
F_11 ( V_245 ) ;
F_200 ( & V_8 -> V_307 ) ;
F_96 ( & V_8 -> V_306 ) ;
F_202 ( V_8 -> V_11 -> V_304 ) ;
F_203 ( V_8 -> V_11 , V_217 ) ;
return 0 ;
}
static T_6 F_206 ( struct V_2 * V_3 ,
T_3 V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_142 ;
T_6 V_310 ;
T_6 V_311 ;
if ( V_91 == 0 )
return 0 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_93 -> V_94 ) {
case V_97 :
break;
case V_146 :
case V_145 :
if ( F_63 ( V_3 ) >= 0 )
break;
case V_207 :
V_310 = - V_170 ;
goto V_312;
case V_194 :
V_310 = - V_232 ;
goto V_312;
default:
V_310 = - V_98 ;
goto V_312;
}
V_311 = F_207 ( V_6 ) ;
if ( V_311 <= 0 ) {
V_310 = 0 ;
goto V_312;
}
if ( V_91 > ( T_3 ) V_311 )
V_91 = V_311 ;
V_142 = V_6 -> V_121 -> V_142 - V_91 ;
if ( V_142 < 0 )
V_142 += V_6 -> V_127 ;
V_6 -> V_121 -> V_142 = V_142 ;
V_310 = V_91 ;
V_312:
F_37 ( V_3 ) ;
return V_310 ;
}
static T_6 F_208 ( struct V_2 * V_3 ,
T_3 V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_142 ;
T_6 V_310 ;
T_6 V_311 ;
if ( V_91 == 0 )
return 0 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_93 -> V_94 ) {
case V_97 :
case V_146 :
break;
case V_145 :
if ( F_63 ( V_3 ) >= 0 )
break;
case V_207 :
V_310 = - V_170 ;
goto V_312;
case V_194 :
V_310 = - V_232 ;
goto V_312;
default:
V_310 = - V_98 ;
goto V_312;
}
V_311 = F_209 ( V_6 ) ;
if ( V_311 <= 0 ) {
V_310 = 0 ;
goto V_312;
}
if ( V_91 > ( T_3 ) V_311 )
V_91 = V_311 ;
V_142 = V_6 -> V_121 -> V_142 - V_91 ;
if ( V_142 < 0 )
V_142 += V_6 -> V_127 ;
V_6 -> V_121 -> V_142 = V_142 ;
V_310 = V_91 ;
V_312:
F_37 ( V_3 ) ;
return V_310 ;
}
static T_6 F_210 ( struct V_2 * V_3 ,
T_3 V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_142 ;
T_6 V_310 ;
T_6 V_144 ;
if ( V_91 == 0 )
return 0 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_93 -> V_94 ) {
case V_97 :
case V_188 :
break;
case V_146 :
case V_145 :
if ( F_63 ( V_3 ) >= 0 )
break;
case V_207 :
V_310 = - V_170 ;
goto V_312;
case V_194 :
V_310 = - V_232 ;
goto V_312;
default:
V_310 = - V_98 ;
goto V_312;
}
V_144 = F_65 ( V_6 ) ;
if ( V_144 <= 0 ) {
V_310 = 0 ;
goto V_312;
}
if ( V_91 > ( T_3 ) V_144 )
V_91 = V_144 ;
V_142 = V_6 -> V_121 -> V_142 + V_91 ;
if ( V_142 >= ( T_6 ) V_6 -> V_127 )
V_142 -= V_6 -> V_127 ;
V_6 -> V_121 -> V_142 = V_142 ;
V_310 = V_91 ;
V_312:
F_37 ( V_3 ) ;
return V_310 ;
}
static T_6 F_211 ( struct V_2 * V_3 ,
T_3 V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_142 ;
T_6 V_310 ;
T_6 V_144 ;
if ( V_91 == 0 )
return 0 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_93 -> V_94 ) {
case V_97 :
case V_146 :
case V_188 :
break;
case V_145 :
if ( F_63 ( V_3 ) >= 0 )
break;
case V_207 :
V_310 = - V_170 ;
goto V_312;
case V_194 :
V_310 = - V_232 ;
goto V_312;
default:
V_310 = - V_98 ;
goto V_312;
}
V_144 = F_66 ( V_6 ) ;
if ( V_144 <= 0 ) {
V_310 = 0 ;
goto V_312;
}
if ( V_91 > ( T_3 ) V_144 )
V_91 = V_144 ;
V_142 = V_6 -> V_121 -> V_142 + V_91 ;
if ( V_142 >= ( T_6 ) V_6 -> V_127 )
V_142 -= V_6 -> V_127 ;
V_6 -> V_121 -> V_142 = V_142 ;
V_310 = V_91 ;
V_312:
F_37 ( V_3 ) ;
return V_310 ;
}
static int F_212 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_30 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_93 -> V_94 ) {
case V_146 :
if ( V_3 -> V_14 == V_301 )
goto V_313;
case V_145 :
if ( ( V_30 = F_63 ( V_3 ) ) < 0 )
break;
case V_97 :
case V_194 :
V_30 = 0 ;
break;
case V_207 :
V_30 = - V_170 ;
break;
default:
V_313:
V_30 = - V_98 ;
break;
}
F_37 ( V_3 ) ;
return V_30 ;
}
static int F_213 ( struct V_2 * V_3 ,
T_6 T_2 * V_151 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_30 ;
T_6 V_314 = 0 ;
F_36 ( V_3 ) ;
switch ( V_6 -> V_93 -> V_94 ) {
case V_146 :
if ( V_3 -> V_14 == V_301 )
goto V_313;
case V_145 :
if ( ( V_30 = F_63 ( V_3 ) ) < 0 )
break;
case V_97 :
case V_194 :
V_30 = 0 ;
if ( V_3 -> V_14 == V_134 )
V_314 = F_207 ( V_6 ) ;
else
V_314 = F_66 ( V_6 ) ;
V_314 += V_6 -> V_147 ;
break;
case V_207 :
V_30 = - V_170 ;
break;
default:
V_313:
V_30 = - V_98 ;
break;
}
F_37 ( V_3 ) ;
if ( ! V_30 )
if ( F_214 ( V_314 , V_151 ) )
V_30 = - V_33 ;
return V_30 ;
}
static int F_215 ( struct V_2 * V_3 ,
struct F_215 T_2 * V_315 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct F_215 V_316 ;
volatile struct V_317 * V_93 ;
volatile struct V_318 * V_121 ;
int V_30 ;
memset ( & V_316 , 0 , sizeof( V_316 ) ) ;
if ( F_216 ( V_316 . V_79 , ( unsigned T_2 * ) & ( V_315 -> V_79 ) ) )
return - V_33 ;
if ( F_61 ( & V_316 . V_319 . V_121 , & ( V_315 -> V_319 . V_121 ) , sizeof( struct V_318 ) ) )
return - V_33 ;
V_93 = V_6 -> V_93 ;
V_121 = V_6 -> V_121 ;
if ( V_316 . V_79 & V_320 ) {
V_30 = F_212 ( V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
}
F_36 ( V_3 ) ;
if ( ! ( V_316 . V_79 & V_321 ) )
V_121 -> V_142 = V_316 . V_319 . V_121 . V_142 ;
else
V_316 . V_319 . V_121 . V_142 = V_121 -> V_142 ;
if ( ! ( V_316 . V_79 & V_322 ) )
V_121 -> V_122 = V_316 . V_319 . V_121 . V_122 ;
else
V_316 . V_319 . V_121 . V_122 = V_121 -> V_122 ;
V_316 . V_157 . V_93 . V_94 = V_93 -> V_94 ;
V_316 . V_157 . V_93 . V_143 = V_93 -> V_143 ;
V_316 . V_157 . V_93 . V_140 = V_93 -> V_140 ;
V_316 . V_157 . V_93 . V_136 = V_93 -> V_136 ;
F_37 ( V_3 ) ;
if ( F_10 ( V_315 , & V_316 , sizeof( V_316 ) ) )
return - V_33 ;
return 0 ;
}
static int F_217 ( struct V_2 * V_3 , int T_2 * V_323 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_324 ;
if ( F_216 ( V_324 , V_323 ) )
return - V_33 ;
if ( V_324 < 0 || V_324 > V_325 )
return - V_62 ;
V_6 -> V_326 = V_327 ;
if ( V_324 == V_328 )
V_6 -> V_326 = V_328 ;
return 0 ;
}
static int F_218 ( struct V_217 * V_217 ,
struct V_2 * V_3 ,
unsigned int V_329 , void T_2 * V_324 )
{
switch ( V_329 ) {
case V_330 :
return F_214 ( V_331 , ( int T_2 * ) V_324 ) ? - V_33 : 0 ;
case V_332 :
return F_8 ( V_3 , V_324 ) ;
case V_333 :
return 0 ;
case V_334 :
return F_217 ( V_3 , V_324 ) ;
case V_335 :
return F_30 ( V_3 , V_324 ) ;
case V_336 :
return F_54 ( V_3 , V_324 ) ;
case V_337 :
return F_55 ( V_3 ) ;
case V_338 :
return F_60 ( V_3 , V_324 ) ;
case V_339 :
return F_67 ( V_3 , V_324 ) ;
case V_340 :
return F_69 ( V_3 , V_324 ) ;
case V_341 :
return F_127 ( V_3 , V_217 ) ;
case V_342 :
return F_123 ( V_3 ) ;
case V_343 :
return F_80 ( & V_180 , V_3 , V_145 ) ;
case V_344 :
return F_148 ( V_3 , ( int ) ( unsigned long ) V_324 ) ;
case V_345 :
return F_157 ( V_3 ) ;
case V_346 :
return F_115 ( V_3 ) ;
case V_347 :
return F_119 ( V_3 ) ;
case V_348 :
return F_212 ( V_3 ) ;
case V_349 :
return F_213 ( V_3 , V_324 ) ;
case V_350 :
return F_215 ( V_3 , V_324 ) ;
#ifdef F_219
case V_351 :
return F_220 ( V_3 , V_324 ) ;
case V_352 :
return F_221 ( V_3 , V_324 ) ;
#endif
case V_353 :
return F_132 ( V_3 , V_217 ) ;
case V_354 :
return F_140 ( V_3 ) ;
case V_355 :
{
int V_151 ;
F_36 ( V_3 ) ;
V_151 = F_103 ( V_3 , ( int ) ( unsigned long ) V_324 ) ;
F_37 ( V_3 ) ;
return V_151 ;
}
}
F_139 ( L_15 , V_329 ) ;
return - V_356 ;
}
static int F_222 ( struct V_217 * V_217 ,
struct V_2 * V_3 ,
unsigned int V_329 , void T_2 * V_324 )
{
if ( F_205 ( ! V_3 ) )
return - V_92 ;
if ( F_205 ( V_3 -> V_14 != V_134 ) )
return - V_62 ;
switch ( V_329 ) {
case V_357 :
{
struct V_358 V_359 ;
struct V_358 T_2 * V_360 = V_324 ;
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_132 ;
if ( V_6 -> V_93 -> V_94 == V_95 )
return - V_98 ;
if ( F_214 ( 0 , & V_360 -> V_132 ) )
return - V_33 ;
if ( F_61 ( & V_359 , V_360 , sizeof( V_359 ) ) )
return - V_33 ;
V_132 = F_223 ( V_3 , V_359 . V_361 , V_359 . V_91 ) ;
F_224 ( V_132 , & V_360 -> V_132 ) ;
return V_132 < 0 ? V_132 : 0 ;
}
case V_362 :
{
struct V_363 V_364 ;
struct V_363 T_2 * V_365 = V_324 ;
struct V_5 * V_6 = V_3 -> V_6 ;
void T_2 * * V_366 ;
T_6 V_132 ;
if ( V_6 -> V_93 -> V_94 == V_95 )
return - V_98 ;
if ( V_6 -> V_108 > 128 )
return - V_62 ;
if ( F_214 ( 0 , & V_365 -> V_132 ) )
return - V_33 ;
if ( F_61 ( & V_364 , V_365 , sizeof( V_364 ) ) )
return - V_33 ;
V_366 = F_31 ( V_364 . V_366 ,
sizeof( void * ) * V_6 -> V_108 ) ;
if ( F_32 ( V_366 ) )
return F_33 ( V_366 ) ;
V_132 = F_225 ( V_3 , V_366 , V_364 . V_91 ) ;
F_11 ( V_366 ) ;
F_224 ( V_132 , & V_365 -> V_132 ) ;
return V_132 < 0 ? V_132 : 0 ;
}
case V_367 :
{
T_3 V_91 ;
T_3 T_2 * V_368 = V_324 ;
T_6 V_132 ;
if ( F_216 ( V_91 , V_368 ) )
return - V_33 ;
if ( F_214 ( 0 , V_368 ) )
return - V_33 ;
V_132 = F_206 ( V_3 , V_91 ) ;
F_224 ( V_132 , V_368 ) ;
return V_132 < 0 ? V_132 : 0 ;
}
case V_369 :
{
T_3 V_91 ;
T_3 T_2 * V_368 = V_324 ;
T_6 V_132 ;
if ( F_216 ( V_91 , V_368 ) )
return - V_33 ;
if ( F_214 ( 0 , V_368 ) )
return - V_33 ;
V_132 = F_210 ( V_3 , V_91 ) ;
F_224 ( V_132 , V_368 ) ;
return V_132 < 0 ? V_132 : 0 ;
}
}
return F_218 ( V_217 , V_3 , V_329 , V_324 ) ;
}
static int F_226 ( struct V_217 * V_217 ,
struct V_2 * V_3 ,
unsigned int V_329 , void T_2 * V_324 )
{
if ( F_205 ( ! V_3 ) )
return - V_92 ;
if ( F_205 ( V_3 -> V_14 != V_301 ) )
return - V_62 ;
switch ( V_329 ) {
case V_370 :
{
struct V_358 V_359 ;
struct V_358 T_2 * V_360 = V_324 ;
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_132 ;
if ( V_6 -> V_93 -> V_94 == V_95 )
return - V_98 ;
if ( F_214 ( 0 , & V_360 -> V_132 ) )
return - V_33 ;
if ( F_61 ( & V_359 , V_360 , sizeof( V_359 ) ) )
return - V_33 ;
V_132 = F_227 ( V_3 , V_359 . V_361 , V_359 . V_91 ) ;
F_224 ( V_132 , & V_360 -> V_132 ) ;
return V_132 < 0 ? V_132 : 0 ;
}
case V_371 :
{
struct V_363 V_364 ;
struct V_363 T_2 * V_365 = V_324 ;
struct V_5 * V_6 = V_3 -> V_6 ;
void * V_366 ;
T_6 V_132 ;
if ( V_6 -> V_93 -> V_94 == V_95 )
return - V_98 ;
if ( V_6 -> V_108 > 128 )
return - V_62 ;
if ( F_214 ( 0 , & V_365 -> V_132 ) )
return - V_33 ;
if ( F_61 ( & V_364 , V_365 , sizeof( V_364 ) ) )
return - V_33 ;
V_366 = F_31 ( V_364 . V_366 ,
sizeof( void * ) * V_6 -> V_108 ) ;
if ( F_32 ( V_366 ) )
return F_33 ( V_366 ) ;
V_132 = F_228 ( V_3 , V_366 , V_364 . V_91 ) ;
F_11 ( V_366 ) ;
F_224 ( V_132 , & V_365 -> V_132 ) ;
return V_132 < 0 ? V_132 : 0 ;
}
case V_367 :
{
T_3 V_91 ;
T_3 T_2 * V_368 = V_324 ;
T_6 V_132 ;
if ( F_216 ( V_91 , V_368 ) )
return - V_33 ;
if ( F_214 ( 0 , V_368 ) )
return - V_33 ;
V_132 = F_208 ( V_3 , V_91 ) ;
F_224 ( V_132 , V_368 ) ;
return V_132 < 0 ? V_132 : 0 ;
}
case V_369 :
{
T_3 V_91 ;
T_3 T_2 * V_368 = V_324 ;
T_6 V_132 ;
if ( F_216 ( V_91 , V_368 ) )
return - V_33 ;
if ( F_214 ( 0 , V_368 ) )
return - V_33 ;
V_132 = F_211 ( V_3 , V_91 ) ;
F_224 ( V_132 , V_368 ) ;
return V_132 < 0 ? V_132 : 0 ;
}
}
return F_218 ( V_217 , V_3 , V_329 , V_324 ) ;
}
static long F_229 ( struct V_217 * V_217 , unsigned int V_329 ,
unsigned long V_324 )
{
struct V_244 * V_245 ;
V_245 = V_217 -> V_247 ;
if ( ( ( V_329 >> 8 ) & 0xff ) != 'A' )
return - V_356 ;
return F_222 ( V_217 , V_245 -> V_3 , V_329 ,
( void T_2 * ) V_324 ) ;
}
static long F_230 ( struct V_217 * V_217 , unsigned int V_329 ,
unsigned long V_324 )
{
struct V_244 * V_245 ;
V_245 = V_217 -> V_247 ;
if ( ( ( V_329 >> 8 ) & 0xff ) != 'A' )
return - V_356 ;
return F_226 ( V_217 , V_245 -> V_3 , V_329 ,
( void T_2 * ) V_324 ) ;
}
int F_231 ( struct V_2 * V_3 ,
unsigned int V_329 , void * V_324 )
{
T_1 V_1 ;
int V_132 ;
V_1 = F_1 () ;
switch ( V_3 -> V_14 ) {
case V_134 :
V_132 = F_222 ( NULL , V_3 , V_329 ,
( void T_2 * ) V_324 ) ;
break;
case V_301 :
V_132 = F_226 ( NULL , V_3 , V_329 ,
( void T_2 * ) V_324 ) ;
break;
default:
V_132 = - V_62 ;
break;
}
F_5 ( V_1 ) ;
return V_132 ;
}
static T_7 F_232 ( struct V_217 * V_217 , char T_2 * V_361 , T_8 V_253 ,
T_9 * V_372 )
{
struct V_244 * V_245 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_132 ;
V_245 = V_217 -> V_247 ;
V_3 = V_245 -> V_3 ;
if ( F_35 ( V_3 ) )
return - V_92 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_93 -> V_94 == V_95 )
return - V_98 ;
if ( ! F_233 ( V_6 , V_253 ) )
return - V_62 ;
V_253 = F_234 ( V_6 , V_253 ) ;
V_132 = F_227 ( V_3 , V_361 , V_253 ) ;
if ( V_132 > 0 )
V_132 = F_235 ( V_6 , V_132 ) ;
return V_132 ;
}
static T_7 F_236 ( struct V_217 * V_217 , const char T_2 * V_361 ,
T_8 V_253 , T_9 * V_372 )
{
struct V_244 * V_245 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_132 ;
V_245 = V_217 -> V_247 ;
V_3 = V_245 -> V_3 ;
if ( F_35 ( V_3 ) )
return - V_92 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_93 -> V_94 == V_95 )
return - V_98 ;
if ( ! F_233 ( V_6 , V_253 ) )
return - V_62 ;
V_253 = F_234 ( V_6 , V_253 ) ;
V_132 = F_223 ( V_3 , V_361 , V_253 ) ;
if ( V_132 > 0 )
V_132 = F_235 ( V_6 , V_132 ) ;
return V_132 ;
}
static T_7 F_237 ( struct V_373 * V_374 , const struct V_375 * V_376 ,
unsigned long V_377 , T_9 V_378 )
{
struct V_244 * V_245 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_132 ;
unsigned long V_40 ;
void T_2 * * V_366 ;
T_3 V_91 ;
V_245 = V_374 -> V_379 -> V_247 ;
V_3 = V_245 -> V_3 ;
if ( F_35 ( V_3 ) )
return - V_92 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_93 -> V_94 == V_95 )
return - V_98 ;
if ( V_377 > 1024 || V_377 != V_6 -> V_108 )
return - V_62 ;
if ( ! F_233 ( V_6 , V_376 -> V_380 ) )
return - V_62 ;
V_91 = F_238 ( V_6 , V_376 -> V_380 ) ;
V_366 = F_9 ( sizeof( void * ) * V_377 , V_31 ) ;
if ( V_366 == NULL )
return - V_32 ;
for ( V_40 = 0 ; V_40 < V_377 ; ++ V_40 )
V_366 [ V_40 ] = V_376 [ V_40 ] . V_381 ;
V_132 = F_228 ( V_3 , V_366 , V_91 ) ;
if ( V_132 > 0 )
V_132 = F_235 ( V_6 , V_132 ) ;
F_11 ( V_366 ) ;
return V_132 ;
}
static T_7 F_239 ( struct V_373 * V_374 , const struct V_375 * V_376 ,
unsigned long V_377 , T_9 V_378 )
{
struct V_244 * V_245 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_132 ;
unsigned long V_40 ;
void T_2 * * V_366 ;
T_3 V_91 ;
V_245 = V_374 -> V_379 -> V_247 ;
V_3 = V_245 -> V_3 ;
if ( F_35 ( V_3 ) )
return - V_92 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_93 -> V_94 == V_95 )
return - V_98 ;
if ( V_377 > 128 || V_377 != V_6 -> V_108 ||
! F_233 ( V_6 , V_376 -> V_380 ) )
return - V_62 ;
V_91 = F_238 ( V_6 , V_376 -> V_380 ) ;
V_366 = F_9 ( sizeof( void * ) * V_377 , V_31 ) ;
if ( V_366 == NULL )
return - V_32 ;
for ( V_40 = 0 ; V_40 < V_377 ; ++ V_40 )
V_366 [ V_40 ] = V_376 [ V_40 ] . V_381 ;
V_132 = F_225 ( V_3 , V_366 , V_91 ) ;
if ( V_132 > 0 )
V_132 = F_235 ( V_6 , V_132 ) ;
F_11 ( V_366 ) ;
return V_132 ;
}
static unsigned int F_240 ( struct V_217 * V_217 , T_10 * V_220 )
{
struct V_244 * V_245 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
unsigned int V_256 ;
T_3 V_144 ;
V_245 = V_217 -> V_247 ;
V_3 = V_245 -> V_3 ;
if ( F_35 ( V_3 ) )
return - V_92 ;
V_6 = V_3 -> V_6 ;
F_241 ( V_217 , & V_6 -> V_182 , V_220 ) ;
F_36 ( V_3 ) ;
V_144 = F_65 ( V_6 ) ;
switch ( V_6 -> V_93 -> V_94 ) {
case V_145 :
case V_97 :
case V_188 :
if ( V_144 >= V_6 -> V_121 -> V_122 ) {
V_256 = V_382 | V_383 ;
break;
}
case V_146 :
V_256 = 0 ;
break;
default:
V_256 = V_382 | V_383 | V_384 ;
break;
}
F_37 ( V_3 ) ;
return V_256 ;
}
static unsigned int F_242 ( struct V_217 * V_217 , T_10 * V_220 )
{
struct V_244 * V_245 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
unsigned int V_256 ;
T_3 V_144 ;
V_245 = V_217 -> V_247 ;
V_3 = V_245 -> V_3 ;
if ( F_35 ( V_3 ) )
return - V_92 ;
V_6 = V_3 -> V_6 ;
F_241 ( V_217 , & V_6 -> V_182 , V_220 ) ;
F_36 ( V_3 ) ;
V_144 = F_66 ( V_6 ) ;
switch ( V_6 -> V_93 -> V_94 ) {
case V_145 :
case V_97 :
case V_188 :
if ( V_144 >= V_6 -> V_121 -> V_122 ) {
V_256 = V_385 | V_386 ;
break;
}
V_256 = 0 ;
break;
case V_146 :
if ( V_144 > 0 ) {
V_256 = V_385 | V_386 ;
break;
}
default:
V_256 = V_385 | V_386 | V_384 ;
break;
}
F_37 ( V_3 ) ;
return V_256 ;
}
static int F_243 ( struct V_387 * V_388 ,
struct V_389 * V_390 )
{
struct V_2 * V_3 = V_388 -> V_391 ;
struct V_5 * V_6 ;
if ( V_3 == NULL )
return V_392 ;
V_6 = V_3 -> V_6 ;
V_390 -> V_393 = F_244 ( V_6 -> V_93 ) ;
F_245 ( V_390 -> V_393 ) ;
return 0 ;
}
static int V_317 ( struct V_2 * V_3 , struct V_217 * V_217 ,
struct V_387 * V_388 )
{
long V_394 ;
if ( ! ( V_388 -> V_395 & V_396 ) )
return - V_62 ;
V_394 = V_388 -> V_397 - V_388 -> V_398 ;
if ( V_394 != F_246 ( sizeof( struct V_317 ) ) )
return - V_62 ;
V_388 -> V_399 = & V_400 ;
V_388 -> V_391 = V_3 ;
V_388 -> V_395 |= V_401 ;
return 0 ;
}
static int F_247 ( struct V_387 * V_388 ,
struct V_389 * V_390 )
{
struct V_2 * V_3 = V_388 -> V_391 ;
struct V_5 * V_6 ;
if ( V_3 == NULL )
return V_392 ;
V_6 = V_3 -> V_6 ;
V_390 -> V_393 = F_244 ( V_6 -> V_121 ) ;
F_245 ( V_390 -> V_393 ) ;
return 0 ;
}
static int V_318 ( struct V_2 * V_3 , struct V_217 * V_217 ,
struct V_387 * V_388 )
{
long V_394 ;
if ( ! ( V_388 -> V_395 & V_396 ) )
return - V_62 ;
V_394 = V_388 -> V_397 - V_388 -> V_398 ;
if ( V_394 != F_246 ( sizeof( struct V_318 ) ) )
return - V_62 ;
V_388 -> V_399 = & V_402 ;
V_388 -> V_391 = V_3 ;
V_388 -> V_395 |= V_401 ;
return 0 ;
}
static int V_317 ( struct V_2 * V_3 , struct V_217 * V_217 ,
struct V_387 * V_388 )
{
return - V_92 ;
}
static int V_318 ( struct V_2 * V_3 , struct V_217 * V_217 ,
struct V_387 * V_388 )
{
return - V_92 ;
}
static inline struct V_393 *
F_248 ( struct V_2 * V_3 , unsigned long V_403 )
{
void * V_404 = V_3 -> V_6 -> V_405 + V_403 ;
#if F_38 ( V_406 ) && F_38 ( V_407 )
if ( V_3 -> V_408 . V_409 . type == V_410 )
return F_244 ( F_249 ( V_404 ) ) ;
#endif
#if F_38 ( V_411 ) && F_38 ( V_412 )
if ( V_3 -> V_408 . V_409 . type == V_410 ) {
T_11 V_413 = V_3 -> V_6 -> V_414 + V_403 ;
V_413 -= F_250 ( V_3 -> V_408 . V_409 . V_409 ) ;
return F_251 ( V_413 >> V_415 ) ;
}
#endif
return F_244 ( V_404 ) ;
}
static int F_252 ( struct V_387 * V_388 ,
struct V_389 * V_390 )
{
struct V_2 * V_3 = V_388 -> V_391 ;
struct V_5 * V_6 ;
unsigned long V_372 ;
struct V_393 * V_393 ;
T_8 V_292 ;
if ( V_3 == NULL )
return V_392 ;
V_6 = V_3 -> V_6 ;
V_372 = V_390 -> V_416 << V_415 ;
V_292 = F_246 ( V_6 -> V_292 ) ;
if ( V_372 > V_292 - V_417 )
return V_392 ;
if ( V_3 -> V_26 -> V_393 )
V_393 = V_3 -> V_26 -> V_393 ( V_3 , V_372 ) ;
else
V_393 = F_248 ( V_3 , V_372 ) ;
if ( ! V_393 )
return V_392 ;
F_245 ( V_393 ) ;
V_390 -> V_393 = V_393 ;
return 0 ;
}
int F_253 ( struct V_2 * V_3 ,
struct V_387 * V_388 )
{
V_388 -> V_395 |= V_401 ;
#ifdef F_254
if ( ! V_3 -> V_26 -> V_393 &&
V_3 -> V_408 . V_409 . type == V_410 )
return F_255 ( V_3 -> V_408 . V_409 . V_409 ,
V_388 ,
V_3 -> V_6 -> V_405 ,
V_3 -> V_6 -> V_414 ,
V_388 -> V_397 - V_388 -> V_398 ) ;
#elif F_38 ( V_406 ) && F_38 ( V_407 )
if ( V_3 -> V_408 . V_409 . type == V_410 &&
! F_256 ( V_3 -> V_408 . V_409 . V_409 ) )
V_388 -> V_418 = F_257 ( V_388 -> V_418 ) ;
#endif
V_388 -> V_399 = & V_419 ;
return 0 ;
}
int F_258 ( struct V_2 * V_3 ,
struct V_387 * V_388 )
{
long V_394 ;
unsigned long V_372 ;
V_388 -> V_418 = F_257 ( V_388 -> V_418 ) ;
V_388 -> V_395 |= V_420 ;
V_394 = V_388 -> V_397 - V_388 -> V_398 ;
V_372 = V_388 -> V_421 << V_415 ;
if ( F_259 ( V_388 , V_388 -> V_398 ,
( V_3 -> V_6 -> V_414 + V_372 ) >> V_415 ,
V_394 , V_388 -> V_418 ) )
return - V_225 ;
return 0 ;
}
int F_260 ( struct V_2 * V_3 , struct V_217 * V_217 ,
struct V_387 * V_388 )
{
struct V_5 * V_6 ;
long V_394 ;
unsigned long V_372 ;
T_8 V_292 ;
int V_30 ;
if ( V_3 -> V_14 == V_134 ) {
if ( ! ( V_388 -> V_395 & ( V_422 | V_396 ) ) )
return - V_62 ;
} else {
if ( ! ( V_388 -> V_395 & V_396 ) )
return - V_62 ;
}
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_93 -> V_94 == V_95 )
return - V_98 ;
if ( ! ( V_6 -> V_4 & V_275 ) )
return - V_92 ;
if ( V_6 -> V_105 == V_272 ||
V_6 -> V_105 == V_274 )
return - V_62 ;
V_394 = V_388 -> V_397 - V_388 -> V_398 ;
V_372 = V_388 -> V_421 << V_415 ;
V_292 = F_246 ( V_6 -> V_292 ) ;
if ( ( T_8 ) V_394 > V_292 )
return - V_62 ;
if ( V_372 > V_292 - V_394 )
return - V_62 ;
V_388 -> V_399 = & V_423 ;
V_388 -> V_391 = V_3 ;
if ( V_3 -> V_26 -> V_424 )
V_30 = V_3 -> V_26 -> V_424 ( V_3 , V_388 ) ;
else
V_30 = F_253 ( V_3 , V_388 ) ;
if ( ! V_30 )
F_261 ( & V_3 -> V_102 ) ;
return V_30 ;
}
static int F_262 ( struct V_217 * V_217 , struct V_387 * V_388 )
{
struct V_244 * V_245 ;
struct V_2 * V_3 ;
unsigned long V_372 ;
V_245 = V_217 -> V_247 ;
V_3 = V_245 -> V_3 ;
if ( F_35 ( V_3 ) )
return - V_92 ;
V_372 = V_388 -> V_421 << V_415 ;
switch ( V_372 ) {
case V_425 :
if ( V_245 -> V_426 )
return - V_92 ;
return V_317 ( V_3 , V_217 , V_388 ) ;
case V_427 :
if ( V_245 -> V_426 )
return - V_92 ;
return V_318 ( V_3 , V_217 , V_388 ) ;
default:
return F_260 ( V_3 , V_217 , V_388 ) ;
}
return 0 ;
}
static int F_263 ( int V_234 , struct V_217 * V_217 , int V_428 )
{
struct V_244 * V_245 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
V_245 = V_217 -> V_247 ;
V_3 = V_245 -> V_3 ;
if ( F_35 ( V_3 ) )
return - V_92 ;
V_6 = V_3 -> V_6 ;
return F_264 ( V_234 , V_217 , V_428 , & V_6 -> V_429 ) ;
}
static void F_265 ( struct V_34 * V_35 ,
struct V_430 * V_431 )
{
unsigned int V_40 ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
V_35 -> V_79 = V_431 -> V_79 ;
for ( V_40 = 0 ; V_40 < F_266 ( V_431 -> V_432 ) ; V_40 ++ )
V_35 -> V_432 [ V_40 ] . V_65 [ 0 ] = V_431 -> V_432 [ V_40 ] ;
memcpy ( V_35 -> V_433 , V_431 -> V_433 , sizeof( V_431 -> V_433 ) ) ;
V_35 -> V_54 = F_267 ( V_431 -> V_54 ) ;
V_35 -> V_66 = F_267 ( V_431 -> V_66 ) ;
V_35 -> V_4 = V_431 -> V_4 ;
V_35 -> V_56 = V_431 -> V_56 ;
V_35 -> V_58 = V_431 -> V_58 ;
V_35 -> V_59 = V_431 -> V_59 ;
V_35 -> V_53 = V_431 -> V_53 ;
}
static void F_268 ( struct V_430 * V_431 ,
struct V_34 * V_35 )
{
unsigned int V_40 ;
memset ( V_431 , 0 , sizeof( * V_431 ) ) ;
V_431 -> V_79 = V_35 -> V_79 ;
for ( V_40 = 0 ; V_40 < F_266 ( V_431 -> V_432 ) ; V_40 ++ )
V_431 -> V_432 [ V_40 ] = V_35 -> V_432 [ V_40 ] . V_65 [ 0 ] ;
memcpy ( V_431 -> V_433 , V_35 -> V_433 , sizeof( V_431 -> V_433 ) ) ;
V_431 -> V_54 = F_269 ( V_35 -> V_54 ) ;
V_431 -> V_66 = F_269 ( V_35 -> V_66 ) ;
V_431 -> V_4 = V_35 -> V_4 ;
V_431 -> V_56 = V_35 -> V_56 ;
V_431 -> V_58 = V_35 -> V_58 ;
V_431 -> V_59 = V_35 -> V_59 ;
V_431 -> V_53 = V_35 -> V_53 ;
}
static int F_220 ( struct V_2 * V_3 ,
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
F_265 ( V_35 , V_431 ) ;
V_30 = F_12 ( V_3 , V_35 ) ;
F_268 ( V_431 , V_35 ) ;
if ( F_10 ( V_434 , V_431 , sizeof( * V_431 ) ) ) {
if ( ! V_30 )
V_30 = - V_33 ;
}
F_11 ( V_431 ) ;
V_435:
F_11 ( V_35 ) ;
return V_30 ;
}
static int F_221 ( struct V_2 * V_3 ,
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
F_265 ( V_35 , V_431 ) ;
V_30 = V_34 ( V_3 , V_35 ) ;
F_268 ( V_431 , V_35 ) ;
if ( F_10 ( V_434 , V_431 , sizeof( * V_431 ) ) ) {
if ( ! V_30 )
V_30 = - V_33 ;
}
F_11 ( V_431 ) ;
V_435:
F_11 ( V_35 ) ;
return V_30 ;
}
static unsigned long F_270 ( struct V_217 * V_217 ,
unsigned long V_413 ,
unsigned long V_436 ,
unsigned long V_416 ,
unsigned long V_79 )
{
struct V_244 * V_245 = V_217 -> V_247 ;
struct V_2 * V_3 = V_245 -> V_3 ;
struct V_5 * V_6 = V_3 -> V_6 ;
unsigned long V_372 = V_416 << V_415 ;
switch ( V_372 ) {
case V_425 :
return ( unsigned long ) V_6 -> V_93 ;
case V_427 :
return ( unsigned long ) V_6 -> V_121 ;
default:
return ( unsigned long ) V_6 -> V_405 + V_372 ;
}
}
