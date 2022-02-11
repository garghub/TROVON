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
F_16 ( L_1 , V_63 [ V_36 ] ) ;
F_17 ( L_2 , V_42 -> V_64 [ 3 ] , V_42 -> V_64 [ 2 ] , V_42 -> V_64 [ 1 ] , V_42 -> V_64 [ 0 ] ) ;
#endif
V_51 = F_18 ( V_42 , F_19 ( V_44 , V_36 ) ) ;
#ifdef F_15
F_17 ( L_3 , V_42 -> V_64 [ 3 ] , V_42 -> V_64 [ 2 ] , V_42 -> V_64 [ 1 ] , V_42 -> V_64 [ 0 ] ) ;
#endif
if ( V_51 )
V_35 -> V_65 |= 1 << V_36 ;
if ( V_51 < 0 )
return V_51 ;
}
for ( V_36 = V_66 ; V_36 <= V_49 ; V_36 ++ ) {
V_40 = F_20 ( V_35 , V_36 ) ;
if ( F_21 ( V_40 ) )
return - V_62 ;
if ( ! ( V_35 -> V_54 & ( 1 << V_36 ) ) )
continue;
#ifdef F_15
F_16 ( L_1 , V_63 [ V_36 ] ) ;
if ( V_40 -> V_67 )
F_17 ( L_4 ) ;
else
F_17 ( L_5 ,
V_40 -> V_68 ? '(' : '[' , V_40 -> V_69 ,
V_40 -> V_70 , V_40 -> V_71 ? ')' : ']' ) ;
F_17 ( L_6 ) ;
#endif
V_51 = F_22 ( V_40 , F_23 ( V_44 , V_36 ) ) ;
#ifdef F_15
if ( V_40 -> V_67 )
F_17 ( L_7 ) ;
else
F_17 ( L_8 ,
V_40 -> V_68 ? '(' : '[' , V_40 -> V_69 ,
V_40 -> V_70 , V_40 -> V_71 ? ')' : ']' ) ;
#endif
if ( V_51 )
V_35 -> V_65 |= 1 << V_36 ;
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
struct V_72 * V_73 = & V_44 -> V_74 [ V_36 ] ;
unsigned int V_75 ;
int V_76 = 0 ;
if ( V_73 -> V_77 && ! ( V_73 -> V_77 & V_35 -> V_78 ) )
continue;
for ( V_75 = 0 ; V_73 -> V_79 [ V_75 ] >= 0 ; V_75 ++ ) {
if ( V_48 [ V_73 -> V_79 [ V_75 ] ] > V_46 [ V_36 ] ) {
V_76 = 1 ;
break;
}
}
if ( ! V_76 )
continue;
#ifdef F_15
F_16 ( L_9 , V_36 , V_73 -> V_80 ) ;
if ( V_73 -> V_81 >= 0 ) {
F_17 ( L_1 , V_63 [ V_73 -> V_81 ] ) ;
if ( F_24 ( V_73 -> V_81 ) ) {
V_42 = F_13 ( V_35 , V_73 -> V_81 ) ;
F_17 ( L_10 , * V_42 -> V_64 ) ;
} else {
V_40 = F_20 ( V_35 , V_73 -> V_81 ) ;
if ( V_40 -> V_67 )
F_17 ( L_4 ) ;
else
F_17 ( L_5 ,
V_40 -> V_68 ? '(' : '[' , V_40 -> V_69 ,
V_40 -> V_70 , V_40 -> V_71 ? ')' : ']' ) ;
}
}
#endif
V_51 = V_73 -> V_80 ( V_35 , V_73 ) ;
#ifdef F_15
if ( V_73 -> V_81 >= 0 ) {
F_17 ( L_6 ) ;
if ( F_24 ( V_73 -> V_81 ) )
F_17 ( L_10 , * V_42 -> V_64 ) ;
else {
if ( V_40 -> V_67 )
F_17 ( L_4 ) ;
else
F_17 ( L_5 ,
V_40 -> V_68 ? '(' : '[' , V_40 -> V_69 ,
V_40 -> V_70 , V_40 -> V_71 ? ')' : ']' ) ;
}
}
F_17 ( L_11 ) ;
#endif
V_46 [ V_36 ] = V_50 ;
if ( V_51 && V_73 -> V_81 >= 0 ) {
V_35 -> V_65 |= ( 1 << V_73 -> V_81 ) ;
V_48 [ V_73 -> V_81 ] = V_50 ;
V_52 = 1 ;
}
if ( V_51 < 0 )
return V_51 ;
V_50 ++ ;
}
} while ( V_52 );
if ( ! V_35 -> V_56 ) {
V_40 = F_20 ( V_35 , V_55 ) ;
if ( F_25 ( V_40 ) )
V_35 -> V_56 = F_26 ( V_40 ) ;
}
if ( ! V_35 -> V_59 ) {
V_40 = F_20 ( V_35 , V_57 ) ;
if ( F_25 ( V_40 ) ) {
V_35 -> V_58 = F_26 ( V_40 ) ;
V_35 -> V_59 = 1 ;
}
}
V_38 = & V_3 -> V_6 -> V_38 ;
if ( ! V_35 -> V_4 )
V_35 -> V_4 = V_38 -> V_4 & ~ V_82 ;
if ( ! V_35 -> V_53 ) {
V_42 = F_13 ( V_35 , V_83 ) ;
V_40 = F_20 ( V_35 , V_84 ) ;
if ( F_27 ( V_42 ) == F_28 ( V_42 ) &&
F_29 ( V_40 ) == F_30 ( V_40 ) ) {
V_51 = V_3 -> V_26 -> V_27 ( V_3 ,
V_85 , V_35 ) ;
if ( V_51 < 0 )
return V_51 ;
}
}
V_35 -> V_54 = 0 ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 ,
struct V_34 T_2 * V_86 )
{
struct V_34 * V_35 ;
int V_30 ;
V_35 = F_32 ( V_86 , sizeof( * V_35 ) ) ;
if ( F_33 ( V_35 ) )
return F_34 ( V_35 ) ;
V_30 = F_12 ( V_3 , V_35 ) ;
if ( F_10 ( V_86 , V_35 , sizeof( * V_35 ) ) ) {
if ( ! V_30 )
V_30 = - V_33 ;
}
F_11 ( V_35 ) ;
return V_30 ;
}
static int F_35 ( struct V_5 * V_6 )
{
int V_87 ;
if ( ! V_6 -> V_88 )
return - 1 ;
V_87 = ( 750000 / V_6 -> V_88 ) * V_6 -> V_89 ;
V_87 += ( ( 750000 % V_6 -> V_88 ) * V_6 -> V_89 ) /
V_6 -> V_88 ;
return V_87 ;
}
static void F_36 ( struct V_2 * V_3 , int V_90 )
{
F_37 ( V_3 ) ;
if ( V_3 -> V_6 -> V_91 -> V_90 != V_92 )
V_3 -> V_6 -> V_91 -> V_90 = V_90 ;
F_38 ( V_3 ) ;
}
static int V_34 ( struct V_2 * V_3 ,
struct V_34 * V_35 )
{
struct V_5 * V_6 ;
int V_30 , V_87 ;
unsigned int V_64 ;
T_3 V_93 ;
if ( F_39 ( V_3 ) )
return - V_94 ;
V_6 = V_3 -> V_6 ;
F_37 ( V_3 ) ;
switch ( V_6 -> V_91 -> V_90 ) {
case V_95 :
case V_96 :
case V_97 :
break;
default:
F_38 ( V_3 ) ;
return - V_98 ;
}
F_38 ( V_3 ) ;
#if F_40 ( V_99 )
if ( ! V_3 -> V_100 . V_100 )
#endif
if ( F_41 ( & V_3 -> V_101 ) )
return - V_98 ;
V_35 -> V_54 = ~ 0U ;
V_30 = F_12 ( V_3 , V_35 ) ;
if ( V_30 < 0 )
goto V_102;
V_30 = F_42 ( V_3 , V_35 ) ;
if ( V_30 < 0 )
goto V_102;
if ( V_3 -> V_26 -> V_103 != NULL ) {
V_30 = V_3 -> V_26 -> V_103 ( V_3 , V_35 ) ;
if ( V_30 < 0 )
goto V_102;
}
V_6 -> V_104 = F_43 ( V_35 ) ;
V_6 -> V_105 = F_44 ( V_35 ) ;
V_6 -> V_106 = F_45 ( V_35 ) ;
V_6 -> V_107 = F_46 ( V_35 ) ;
V_6 -> V_88 = F_47 ( V_35 ) ;
V_6 -> V_89 = F_48 ( V_35 ) ;
V_6 -> V_108 = F_49 ( V_35 ) ;
V_6 -> V_109 = F_50 ( V_35 ) ;
V_6 -> V_4 = V_35 -> V_4 ;
V_6 -> V_58 = V_35 -> V_58 ;
V_6 -> V_59 = V_35 -> V_59 ;
V_6 -> V_110 =
( V_35 -> V_4 & V_111 ) &&
( V_35 -> V_78 & V_112 ) ;
V_64 = F_51 ( V_6 -> V_105 ) ;
V_6 -> V_113 = V_64 ;
V_64 *= V_6 -> V_107 ;
V_6 -> V_114 = V_64 ;
V_93 = 1 ;
while ( V_64 % 8 != 0 ) {
V_64 *= 2 ;
V_93 *= 2 ;
}
V_6 -> V_115 = V_64 / 8 ;
V_6 -> V_116 = V_93 ;
V_6 -> V_117 = V_118 ;
V_6 -> V_119 = 1 ;
V_6 -> V_120 -> V_121 = V_6 -> V_89 ;
V_6 -> V_122 = 1 ;
V_6 -> V_123 = V_6 -> V_109 ;
V_6 -> V_124 = 0 ;
V_6 -> V_125 = 0 ;
V_6 -> V_126 = V_6 -> V_109 ;
while ( V_6 -> V_126 * 2 <= V_127 - V_6 -> V_109 )
V_6 -> V_126 *= 2 ;
F_52 ( V_3 ) ;
F_36 ( V_3 , V_96 ) ;
if ( F_53 ( & V_3 -> V_128 ) )
F_54 ( & V_3 -> V_128 ) ;
if ( ( V_87 = F_35 ( V_6 ) ) >= 0 )
F_55 ( & V_3 -> V_128 ,
V_129 , V_87 ) ;
return 0 ;
V_102:
F_36 ( V_3 , V_95 ) ;
if ( V_3 -> V_26 -> V_130 != NULL )
V_3 -> V_26 -> V_130 ( V_3 ) ;
return V_30 ;
}
static int F_56 ( struct V_2 * V_3 ,
struct V_34 T_2 * V_86 )
{
struct V_34 * V_35 ;
int V_30 ;
V_35 = F_32 ( V_86 , sizeof( * V_35 ) ) ;
if ( F_33 ( V_35 ) )
return F_34 ( V_35 ) ;
V_30 = V_34 ( V_3 , V_35 ) ;
if ( F_10 ( V_86 , V_35 , sizeof( * V_35 ) ) ) {
if ( ! V_30 )
V_30 = - V_33 ;
}
F_11 ( V_35 ) ;
return V_30 ;
}
static int F_57 ( struct V_2 * V_3 )
{
struct V_5 * V_6 ;
int V_131 = 0 ;
if ( F_39 ( V_3 ) )
return - V_94 ;
V_6 = V_3 -> V_6 ;
F_37 ( V_3 ) ;
switch ( V_6 -> V_91 -> V_90 ) {
case V_96 :
case V_97 :
break;
default:
F_38 ( V_3 ) ;
return - V_98 ;
}
F_38 ( V_3 ) ;
if ( F_41 ( & V_3 -> V_101 ) )
return - V_98 ;
if ( V_3 -> V_26 -> V_130 )
V_131 = V_3 -> V_26 -> V_130 ( V_3 ) ;
F_36 ( V_3 , V_95 ) ;
F_54 ( & V_3 -> V_128 ) ;
return V_131 ;
}
static int F_58 ( struct V_2 * V_3 ,
struct F_58 * V_35 )
{
struct V_5 * V_6 ;
int V_30 ;
if ( F_39 ( V_3 ) )
return - V_94 ;
V_6 = V_3 -> V_6 ;
F_37 ( V_3 ) ;
if ( V_6 -> V_91 -> V_90 == V_95 ) {
F_38 ( V_3 ) ;
return - V_98 ;
}
F_38 ( V_3 ) ;
if ( V_35 -> V_117 > V_132 )
return - V_62 ;
if ( V_35 -> V_121 == 0 )
return - V_62 ;
if ( V_35 -> V_125 >= V_6 -> V_126 ) {
if ( V_35 -> V_124 != 0 )
return - V_62 ;
} else {
if ( V_35 -> V_125 > V_35 -> V_124 )
return - V_62 ;
if ( V_35 -> V_124 > V_6 -> V_109 )
return - V_62 ;
}
V_30 = 0 ;
F_37 ( V_3 ) ;
V_6 -> V_117 = V_35 -> V_117 ;
V_6 -> V_119 = V_35 -> V_119 ;
V_6 -> V_120 -> V_121 = V_35 -> V_121 ;
V_6 -> V_122 = V_35 -> V_122 ;
V_6 -> V_123 = V_35 -> V_123 ;
V_6 -> V_124 = V_35 -> V_124 ;
V_6 -> V_125 = V_35 -> V_125 ;
V_35 -> V_126 = V_6 -> V_126 ;
if ( F_59 ( V_3 ) ) {
if ( V_3 -> V_14 == V_133 &&
V_6 -> V_125 > 0 )
F_60 ( V_3 , V_134 ) ;
V_30 = F_61 ( V_3 , V_6 ) ;
}
F_38 ( V_3 ) ;
return V_30 ;
}
static int F_62 ( struct V_2 * V_3 ,
struct F_58 T_2 * V_86 )
{
struct F_58 V_35 ;
int V_30 ;
if ( F_63 ( & V_35 , V_86 , sizeof( V_35 ) ) )
return - V_33 ;
V_30 = F_58 ( V_3 , & V_35 ) ;
if ( F_10 ( V_86 , & V_35 , sizeof( V_35 ) ) )
return - V_33 ;
return V_30 ;
}
int F_64 ( struct V_2 * V_3 ,
struct F_64 * V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_37 ( V_3 ) ;
V_91 -> V_90 = V_6 -> V_91 -> V_90 ;
V_91 -> V_135 = V_6 -> V_91 -> V_135 ;
if ( V_91 -> V_90 == V_95 )
goto V_136;
V_91 -> V_137 = V_6 -> V_137 ;
if ( F_59 ( V_3 ) ) {
F_65 ( V_3 ) ;
if ( V_6 -> V_117 == V_138 ) {
V_91 -> V_139 = V_6 -> V_91 -> V_139 ;
V_91 -> V_140 =
V_6 -> V_91 -> V_140 ;
goto V_141;
}
}
F_66 ( V_6 , & V_91 -> V_139 ) ;
V_141:
V_91 -> V_142 = V_6 -> V_120 -> V_142 ;
V_91 -> V_143 = V_6 -> V_91 -> V_143 ;
if ( V_3 -> V_14 == V_133 ) {
V_91 -> V_144 = F_67 ( V_6 ) ;
if ( V_6 -> V_91 -> V_90 == V_145 ||
V_6 -> V_91 -> V_90 == V_146 ) {
V_91 -> V_147 = V_6 -> V_109 - V_91 -> V_144 ;
V_91 -> V_147 += V_6 -> V_147 ;
} else
V_91 -> V_147 = 0 ;
} else {
V_91 -> V_144 = F_68 ( V_6 ) ;
if ( V_6 -> V_91 -> V_90 == V_145 )
V_91 -> V_147 = V_91 -> V_144 + V_6 -> V_147 ;
else
V_91 -> V_147 = 0 ;
}
V_91 -> V_148 = V_6 -> V_148 ;
V_91 -> V_149 = V_6 -> V_149 ;
V_6 -> V_148 = 0 ;
V_6 -> V_149 = 0 ;
V_136:
F_38 ( V_3 ) ;
return 0 ;
}
static int F_69 ( struct V_2 * V_3 ,
struct F_64 T_2 * V_150 )
{
struct F_64 V_91 ;
int V_151 ;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_151 = F_64 ( V_3 , & V_91 ) ;
if ( V_151 < 0 )
return V_151 ;
if ( F_10 ( V_150 , & V_91 , sizeof( V_91 ) ) )
return - V_33 ;
return 0 ;
}
static int F_70 ( struct V_2 * V_3 ,
struct F_70 * V_4 )
{
struct V_5 * V_6 ;
unsigned int V_152 ;
V_152 = V_4 -> V_152 ;
V_6 = V_3 -> V_6 ;
F_37 ( V_3 ) ;
if ( V_6 -> V_91 -> V_90 == V_95 ) {
F_38 ( V_3 ) ;
return - V_98 ;
}
F_38 ( V_3 ) ;
if ( V_152 >= V_6 -> V_107 )
return - V_62 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_152 = V_152 ;
return V_3 -> V_26 -> V_27 ( V_3 , V_153 , V_4 ) ;
}
static int F_71 ( struct V_2 * V_3 ,
struct F_70 T_2 * V_29 )
{
struct F_70 V_4 ;
int V_151 ;
if ( F_63 ( & V_4 , V_29 , sizeof( V_4 ) ) )
return - V_33 ;
V_151 = F_70 ( V_3 , & V_4 ) ;
if ( V_151 < 0 )
return V_151 ;
if ( F_10 ( V_29 , & V_4 , sizeof( V_4 ) ) )
return - V_33 ;
return 0 ;
}
static void F_72 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_154 == NULL )
return;
if ( V_6 -> V_154 == V_3 ) {
F_66 ( V_6 , & V_6 -> V_137 ) ;
} else {
F_72 ( V_6 -> V_154 ) ;
V_6 -> V_137 = V_6 -> V_154 -> V_6 -> V_137 ;
}
V_6 -> V_154 = NULL ;
}
static int F_73 ( struct V_155 * V_26 ,
struct V_2 * V_3 ,
int V_90 , int V_156 )
{
struct V_2 * V_157 = NULL ;
struct V_2 * V_158 ;
int V_151 = 0 ;
F_74 (s, substream) {
if ( V_156 && V_157 != V_3 )
F_75 ( & V_157 -> V_159 . V_160 ,
V_161 ) ;
V_151 = V_26 -> V_162 ( V_157 , V_90 ) ;
if ( V_151 < 0 )
goto V_163;
}
F_74 (s, substream) {
V_151 = V_26 -> V_164 ( V_157 , V_90 ) ;
if ( V_151 < 0 ) {
if ( V_26 -> V_165 ) {
F_74 (s1, substream) {
if ( V_158 == V_157 )
break;
V_26 -> V_165 ( V_158 , V_90 ) ;
}
}
V_157 = NULL ;
goto V_163;
}
}
F_74 (s, substream) {
V_26 -> V_166 ( V_157 , V_90 ) ;
}
V_163:
if ( V_156 ) {
F_74 (s1, substream) {
if ( V_158 != V_3 )
F_76 ( & V_158 -> V_159 . V_160 ) ;
if ( V_158 == V_157 )
break;
}
}
return V_151 ;
}
static int F_77 ( struct V_155 * V_26 ,
struct V_2 * V_3 ,
int V_90 )
{
int V_151 ;
V_151 = V_26 -> V_162 ( V_3 , V_90 ) ;
if ( V_151 < 0 )
return V_151 ;
V_151 = V_26 -> V_164 ( V_3 , V_90 ) ;
if ( V_151 == 0 )
V_26 -> V_166 ( V_3 , V_90 ) ;
else if ( V_26 -> V_165 )
V_26 -> V_165 ( V_3 , V_90 ) ;
return V_151 ;
}
static int F_78 ( struct V_155 * V_26 ,
struct V_2 * V_3 ,
int V_90 )
{
int V_151 ;
if ( F_79 ( V_3 ) ) {
if ( ! F_80 ( & V_3 -> V_167 -> V_160 ) ) {
F_76 ( & V_3 -> V_159 . V_160 ) ;
F_81 ( & V_3 -> V_167 -> V_160 ) ;
F_81 ( & V_3 -> V_159 . V_160 ) ;
}
V_151 = F_73 ( V_26 , V_3 , V_90 , 1 ) ;
F_76 ( & V_3 -> V_167 -> V_160 ) ;
} else {
V_151 = F_77 ( V_26 , V_3 , V_90 ) ;
}
return V_151 ;
}
static int F_82 ( struct V_155 * V_26 ,
struct V_2 * V_3 ,
int V_90 )
{
int V_151 ;
F_83 ( & V_168 ) ;
if ( F_79 ( V_3 ) ) {
F_81 ( & V_3 -> V_167 -> V_160 ) ;
F_81 ( & V_3 -> V_159 . V_160 ) ;
V_151 = F_73 ( V_26 , V_3 , V_90 , 1 ) ;
F_76 ( & V_3 -> V_159 . V_160 ) ;
F_76 ( & V_3 -> V_167 -> V_160 ) ;
} else {
F_81 ( & V_3 -> V_159 . V_160 ) ;
V_151 = F_77 ( V_26 , V_3 , V_90 ) ;
F_76 ( & V_3 -> V_159 . V_160 ) ;
}
F_84 ( & V_168 ) ;
return V_151 ;
}
static int F_85 ( struct V_155 * V_26 ,
struct V_2 * V_3 ,
int V_90 )
{
int V_151 ;
F_86 ( & V_169 ) ;
if ( F_79 ( V_3 ) )
V_151 = F_73 ( V_26 , V_3 , V_90 , 0 ) ;
else
V_151 = F_77 ( V_26 , V_3 , V_90 ) ;
F_87 ( & V_169 ) ;
return V_151 ;
}
static int F_88 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_91 -> V_90 != V_97 )
return - V_98 ;
if ( V_3 -> V_14 == V_133 &&
! F_89 ( V_3 ) )
return - V_170 ;
V_6 -> V_154 = V_3 ;
return 0 ;
}
static int F_90 ( struct V_2 * V_3 , int V_90 )
{
if ( V_3 -> V_6 -> V_154 != V_3 )
return 0 ;
return V_3 -> V_26 -> V_171 ( V_3 , V_172 ) ;
}
static void F_91 ( struct V_2 * V_3 , int V_90 )
{
if ( V_3 -> V_6 -> V_154 == V_3 )
V_3 -> V_26 -> V_171 ( V_3 , V_173 ) ;
}
static void F_92 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_72 ( V_3 ) ;
V_6 -> V_174 = V_175 ;
V_6 -> V_176 = ( V_6 -> V_109 * V_177 ) /
V_6 -> V_88 ;
V_6 -> V_91 -> V_90 = V_90 ;
if ( V_3 -> V_14 == V_133 &&
V_6 -> V_125 > 0 )
F_60 ( V_3 , V_134 ) ;
if ( V_3 -> V_178 )
F_93 ( V_3 -> V_178 , V_179 ,
& V_6 -> V_137 ) ;
}
int F_94 ( struct V_2 * V_3 )
{
return F_78 ( & V_180 , V_3 ,
V_145 ) ;
}
static int F_95 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_91 -> V_90 == V_95 )
return - V_98 ;
V_6 -> V_154 = V_3 ;
return 0 ;
}
static int F_96 ( struct V_2 * V_3 , int V_90 )
{
if ( V_3 -> V_6 -> V_154 == V_3 &&
F_59 ( V_3 ) )
V_3 -> V_26 -> V_171 ( V_3 , V_173 ) ;
return 0 ;
}
static void F_97 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_91 -> V_90 != V_90 ) {
F_72 ( V_3 ) ;
if ( V_3 -> V_178 )
F_93 ( V_3 -> V_178 , V_181 ,
& V_6 -> V_137 ) ;
V_6 -> V_91 -> V_90 = V_90 ;
}
F_98 ( & V_6 -> V_182 ) ;
F_98 ( & V_6 -> V_183 ) ;
}
int F_99 ( struct V_2 * V_3 , T_4 V_90 )
{
return F_78 ( & V_184 , V_3 , V_90 ) ;
}
int F_100 ( struct V_2 * V_3 )
{
return F_77 ( & V_184 , V_3 ,
V_96 ) ;
}
static int F_101 ( struct V_2 * V_3 , int V_185 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( ! ( V_6 -> V_4 & V_186 ) )
return - V_187 ;
if ( V_185 ) {
if ( V_6 -> V_91 -> V_90 != V_145 )
return - V_98 ;
} else if ( V_6 -> V_91 -> V_90 != V_188 )
return - V_98 ;
V_6 -> V_154 = V_3 ;
return 0 ;
}
static int F_102 ( struct V_2 * V_3 , int V_185 )
{
if ( V_3 -> V_6 -> V_154 != V_3 )
return 0 ;
if ( V_185 )
F_65 ( V_3 ) ;
V_3 -> V_6 -> V_174 = V_175 - V_177 * 1000 ;
return V_3 -> V_26 -> V_171 ( V_3 ,
V_185 ? V_189 :
V_190 ) ;
}
static void F_103 ( struct V_2 * V_3 , int V_185 )
{
if ( V_3 -> V_6 -> V_154 == V_3 )
V_3 -> V_26 -> V_171 ( V_3 ,
V_185 ? V_190 :
V_189 ) ;
}
static void F_104 ( struct V_2 * V_3 , int V_185 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_72 ( V_3 ) ;
if ( V_185 ) {
V_6 -> V_91 -> V_90 = V_188 ;
if ( V_3 -> V_178 )
F_93 ( V_3 -> V_178 ,
V_191 ,
& V_6 -> V_137 ) ;
F_98 ( & V_6 -> V_182 ) ;
F_98 ( & V_6 -> V_183 ) ;
} else {
V_6 -> V_91 -> V_90 = V_145 ;
if ( V_3 -> V_178 )
F_93 ( V_3 -> V_178 ,
V_192 ,
& V_6 -> V_137 ) ;
}
}
static int F_105 ( struct V_2 * V_3 , int V_185 )
{
return F_78 ( & V_193 , V_3 , V_185 ) ;
}
static int F_106 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_91 -> V_90 == V_194 )
return - V_195 ;
V_6 -> V_154 = V_3 ;
return 0 ;
}
static int F_107 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_154 != V_3 )
return 0 ;
if ( ! F_59 ( V_3 ) )
return 0 ;
V_3 -> V_26 -> V_171 ( V_3 , V_196 ) ;
return 0 ;
}
static void F_108 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_72 ( V_3 ) ;
if ( V_3 -> V_178 )
F_93 ( V_3 -> V_178 , V_197 ,
& V_6 -> V_137 ) ;
V_6 -> V_91 -> V_135 = V_6 -> V_91 -> V_90 ;
V_6 -> V_91 -> V_90 = V_194 ;
F_98 ( & V_6 -> V_182 ) ;
F_98 ( & V_6 -> V_183 ) ;
}
int F_109 ( struct V_2 * V_3 )
{
int V_30 ;
unsigned long V_78 ;
if ( ! V_3 )
return 0 ;
F_110 ( V_3 , V_78 ) ;
V_30 = F_78 ( & V_198 , V_3 , 0 ) ;
F_111 ( V_3 , V_78 ) ;
return V_30 ;
}
int F_112 ( struct V_7 * V_8 )
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
V_30 = F_109 ( V_3 ) ;
if ( V_30 < 0 && V_30 != - V_195 )
return V_30 ;
}
}
return 0 ;
}
static int F_113 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( ! ( V_6 -> V_4 & V_201 ) )
return - V_187 ;
V_6 -> V_154 = V_3 ;
return 0 ;
}
static int F_114 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_154 != V_3 )
return 0 ;
if ( V_6 -> V_91 -> V_135 != V_145 &&
( V_6 -> V_91 -> V_135 != V_146 ||
V_3 -> V_14 != V_133 ) )
return 0 ;
return V_3 -> V_26 -> V_171 ( V_3 , V_202 ) ;
}
static void F_115 ( struct V_2 * V_3 , int V_90 )
{
if ( V_3 -> V_6 -> V_154 == V_3 &&
F_59 ( V_3 ) )
V_3 -> V_26 -> V_171 ( V_3 , V_196 ) ;
}
static void F_116 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_72 ( V_3 ) ;
if ( V_3 -> V_178 )
F_93 ( V_3 -> V_178 , V_203 ,
& V_6 -> V_137 ) ;
V_6 -> V_91 -> V_90 = V_6 -> V_91 -> V_135 ;
}
static int F_117 ( struct V_2 * V_3 )
{
struct V_204 * V_11 = V_3 -> V_8 -> V_11 ;
int V_151 ;
F_118 ( V_11 ) ;
if ( ( V_151 = F_119 ( V_11 , V_205 ) ) >= 0 )
V_151 = F_82 ( & V_206 , V_3 , 0 ) ;
F_120 ( V_11 ) ;
return V_151 ;
}
static int F_117 ( struct V_2 * V_3 )
{
return - V_187 ;
}
static int F_121 ( struct V_2 * V_3 )
{
struct V_204 * V_11 = V_3 -> V_8 -> V_11 ;
struct V_5 * V_6 = V_3 -> V_6 ;
int V_131 ;
F_118 ( V_11 ) ;
if ( V_6 -> V_91 -> V_90 == V_194 ) {
V_131 = F_119 ( V_11 , V_205 ) ;
if ( V_131 < 0 )
goto V_163;
}
F_37 ( V_3 ) ;
switch ( V_6 -> V_91 -> V_90 ) {
case V_207 :
V_131 = 0 ;
break;
case V_145 :
V_131 = F_99 ( V_3 , V_207 ) ;
break;
default:
V_131 = - V_98 ;
}
F_38 ( V_3 ) ;
V_163:
F_120 ( V_11 ) ;
return V_131 ;
}
static int F_122 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
switch ( V_6 -> V_91 -> V_90 ) {
case V_145 :
case V_97 :
case V_188 :
case V_194 :
return 0 ;
default:
return - V_98 ;
}
}
static int F_123 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_30 = V_3 -> V_26 -> V_27 ( V_3 , V_208 , NULL ) ;
if ( V_30 < 0 )
return V_30 ;
V_6 -> V_209 = 0 ;
V_6 -> V_210 = V_6 -> V_91 -> V_143 -
V_6 -> V_91 -> V_143 % V_6 -> V_89 ;
V_6 -> V_211 = V_6 -> V_91 -> V_143 ;
V_6 -> V_212 = 0 ;
return 0 ;
}
static void F_124 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
V_6 -> V_120 -> V_142 = V_6 -> V_91 -> V_143 ;
if ( V_3 -> V_14 == V_133 &&
V_6 -> V_125 > 0 )
F_60 ( V_3 , V_134 ) ;
}
static int F_125 ( struct V_2 * V_3 )
{
return F_85 ( & V_213 , V_3 , 0 ) ;
}
static int F_126 ( struct V_2 * V_3 ,
int V_214 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_91 -> V_90 == V_95 ||
V_6 -> V_91 -> V_90 == V_92 )
return - V_98 ;
if ( F_59 ( V_3 ) )
return - V_195 ;
V_3 -> V_214 = V_214 ;
return 0 ;
}
static int F_127 ( struct V_2 * V_3 , int V_90 )
{
int V_30 ;
V_30 = V_3 -> V_26 -> V_215 ( V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
return F_123 ( V_3 , 0 ) ;
}
static void F_128 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
V_6 -> V_120 -> V_142 = V_6 -> V_91 -> V_143 ;
F_36 ( V_3 , V_97 ) ;
}
static int F_129 ( struct V_2 * V_3 ,
struct V_216 * V_216 )
{
int V_151 ;
struct V_204 * V_11 = V_3 -> V_8 -> V_11 ;
int V_214 ;
if ( V_216 )
V_214 = V_216 -> V_214 ;
else
V_214 = V_3 -> V_214 ;
F_118 ( V_11 ) ;
if ( ( V_151 = F_119 ( V_11 , V_205 ) ) >= 0 )
V_151 = F_85 ( & V_217 ,
V_3 , V_214 ) ;
F_120 ( V_11 ) ;
return V_151 ;
}
static int F_130 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
switch ( V_6 -> V_91 -> V_90 ) {
case V_95 :
case V_92 :
case V_194 :
return - V_98 ;
}
V_6 -> V_154 = V_3 ;
return 0 ;
}
static int F_131 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_3 -> V_14 == V_133 ) {
switch ( V_6 -> V_91 -> V_90 ) {
case V_97 :
if ( ! F_132 ( V_3 ) ) {
F_90 ( V_3 , V_146 ) ;
F_92 ( V_3 , V_146 ) ;
}
break;
case V_145 :
V_6 -> V_91 -> V_90 = V_146 ;
break;
case V_207 :
V_6 -> V_91 -> V_90 = V_96 ;
break;
default:
break;
}
} else {
if ( V_6 -> V_91 -> V_90 == V_145 ) {
int V_218 = F_68 ( V_6 ) > 0 ?
V_146 : V_96 ;
F_96 ( V_3 , V_218 ) ;
F_97 ( V_3 , V_218 ) ;
}
}
return 0 ;
}
static void F_133 ( struct V_2 * V_3 , int V_90 )
{
}
static int F_134 ( struct V_2 * V_3 ,
struct V_216 * V_216 )
{
struct V_204 * V_11 ;
struct V_5 * V_6 ;
struct V_2 * V_157 ;
T_5 V_219 ;
int V_131 = 0 ;
int V_220 = 0 ;
V_11 = V_3 -> V_8 -> V_11 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_91 -> V_90 == V_95 )
return - V_98 ;
F_118 ( V_11 ) ;
if ( V_6 -> V_91 -> V_90 == V_194 ) {
V_131 = F_119 ( V_11 , V_205 ) ;
if ( V_131 < 0 ) {
F_120 ( V_11 ) ;
return V_131 ;
}
}
if ( V_216 ) {
if ( V_216 -> V_214 & V_221 )
V_220 = 1 ;
} else if ( V_3 -> V_214 & V_221 )
V_220 = 1 ;
F_86 ( & V_169 ) ;
F_37 ( V_3 ) ;
if ( V_6 -> V_91 -> V_90 == V_188 )
F_105 ( V_3 , 0 ) ;
V_131 = F_78 ( & V_222 , V_3 , 0 ) ;
if ( V_131 < 0 )
goto V_223;
if ( V_220 ) {
V_131 = - V_224 ;
goto V_223;
}
for (; ; ) {
long V_225 ;
struct V_5 * V_226 ;
if ( F_135 ( V_227 ) ) {
V_131 = - V_228 ;
break;
}
V_226 = NULL ;
F_74 (s, substream) {
if ( V_157 -> V_14 != V_133 )
continue;
V_6 = V_157 -> V_6 ;
if ( V_6 -> V_91 -> V_90 == V_146 ) {
V_226 = V_6 ;
break;
}
}
if ( ! V_226 )
break;
F_136 ( & V_219 , V_227 ) ;
F_137 ( & V_226 -> V_182 , & V_219 ) ;
F_38 ( V_3 ) ;
F_87 ( & V_169 ) ;
F_120 ( V_11 ) ;
if ( V_6 -> V_110 )
V_225 = V_229 ;
else {
V_225 = 10 ;
if ( V_6 -> V_88 ) {
long V_230 = V_6 -> V_89 * 2 / V_6 -> V_88 ;
V_225 = V_70 ( V_230 , V_225 ) ;
}
V_225 = F_138 ( V_225 * 1000 ) ;
}
V_225 = F_139 ( V_225 ) ;
F_118 ( V_11 ) ;
F_86 ( & V_169 ) ;
F_37 ( V_3 ) ;
F_140 ( & V_226 -> V_182 , & V_219 ) ;
if ( V_11 -> V_231 ) {
V_131 = - V_232 ;
break;
}
if ( V_225 == 0 ) {
if ( V_3 -> V_6 -> V_91 -> V_90 == V_194 )
V_131 = - V_233 ;
else {
F_141 ( V_3 -> V_8 -> V_11 -> V_234 ,
L_12 ) ;
F_99 ( V_3 , V_96 ) ;
V_131 = - V_235 ;
}
break;
}
}
V_223:
F_38 ( V_3 ) ;
F_87 ( & V_169 ) ;
F_120 ( V_11 ) ;
return V_131 ;
}
static int F_142 ( struct V_2 * V_3 )
{
struct V_5 * V_6 ;
int V_131 = 0 ;
if ( F_39 ( V_3 ) )
return - V_94 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_91 -> V_90 == V_95 ||
V_6 -> V_91 -> V_90 == V_92 ||
V_6 -> V_91 -> V_90 == V_194 )
return - V_98 ;
F_37 ( V_3 ) ;
if ( V_6 -> V_91 -> V_90 == V_188 )
F_105 ( V_3 , 0 ) ;
F_99 ( V_3 , V_96 ) ;
F_38 ( V_3 ) ;
return V_131 ;
}
static bool F_143 ( struct V_216 * V_216 )
{
struct V_236 * V_236 = F_144 ( V_216 ) ;
unsigned int V_237 ;
if ( ! F_145 ( V_236 -> V_238 ) || F_146 ( V_236 ) != V_239 )
return false ;
V_237 = F_147 ( V_236 ) ;
return F_148 ( V_237 , V_240 ) ||
F_148 ( V_237 , V_241 ) ;
}
static int F_149 ( struct V_2 * V_3 , int V_242 )
{
int V_151 = 0 ;
struct V_243 * V_244 ;
struct V_2 * V_245 ;
struct V_246 * V_167 ;
struct V_242 V_247 = F_150 ( V_242 ) ;
if ( ! V_247 . V_216 )
return - V_98 ;
if ( ! F_143 ( V_247 . V_216 ) ) {
V_151 = - V_98 ;
goto V_248;
}
V_244 = V_247 . V_216 -> V_249 ;
V_245 = V_244 -> V_3 ;
V_167 = F_9 ( sizeof( * V_167 ) , V_31 ) ;
if ( ! V_167 ) {
V_151 = - V_32 ;
goto V_250;
}
F_151 ( & V_169 ) ;
F_152 ( & V_168 ) ;
if ( V_3 -> V_6 -> V_91 -> V_90 == V_95 ||
V_3 -> V_6 -> V_91 -> V_90 != V_245 -> V_6 -> V_91 -> V_90 ) {
V_151 = - V_98 ;
goto V_136;
}
if ( F_79 ( V_245 ) ) {
V_151 = - V_251 ;
goto V_136;
}
if ( ! F_79 ( V_3 ) ) {
V_3 -> V_167 = V_167 ;
V_167 = NULL ;
F_153 ( & V_3 -> V_167 -> V_160 ) ;
F_154 ( & V_3 -> V_167 -> V_252 ) ;
F_155 ( & V_3 -> V_253 , & V_3 -> V_167 -> V_252 ) ;
V_3 -> V_167 -> V_254 = 1 ;
}
F_155 ( & V_245 -> V_253 , & V_3 -> V_167 -> V_252 ) ;
V_3 -> V_167 -> V_254 ++ ;
V_245 -> V_167 = V_3 -> V_167 ;
V_136:
F_156 ( & V_168 ) ;
F_157 ( & V_169 ) ;
V_250:
F_158 ( V_245 -> V_8 -> V_11 ) ;
F_11 ( V_167 ) ;
V_248:
F_159 ( V_247 ) ;
return V_151 ;
}
static void F_160 ( struct V_2 * V_3 )
{
V_3 -> V_167 = & V_3 -> V_159 ;
F_154 ( & V_3 -> V_159 . V_252 ) ;
F_155 ( & V_3 -> V_253 , & V_3 -> V_159 . V_252 ) ;
}
static int F_161 ( struct V_2 * V_3 )
{
struct V_2 * V_157 ;
int V_151 = 0 ;
F_151 ( & V_169 ) ;
F_152 ( & V_168 ) ;
if ( ! F_79 ( V_3 ) ) {
V_151 = - V_251 ;
goto V_136;
}
F_162 ( & V_3 -> V_253 ) ;
V_3 -> V_167 -> V_254 -- ;
if ( V_3 -> V_167 -> V_254 == 1 ) {
F_74 (s, substream) {
F_160 ( V_157 ) ;
break;
}
F_11 ( V_3 -> V_167 ) ;
}
F_160 ( V_3 ) ;
V_136:
F_156 ( & V_168 ) ;
F_157 ( & V_169 ) ;
return V_151 ;
}
static int F_163 ( struct V_34 * V_35 ,
struct V_72 * V_255 )
{
struct V_39 V_230 ;
F_164 ( F_165 ( V_35 , V_255 -> V_79 [ 0 ] ) ,
F_165 ( V_35 , V_255 -> V_79 [ 1 ] ) , & V_230 ) ;
return F_22 ( F_20 ( V_35 , V_255 -> V_81 ) , & V_230 ) ;
}
static int F_166 ( struct V_34 * V_35 ,
struct V_72 * V_255 )
{
struct V_39 V_230 ;
F_167 ( F_165 ( V_35 , V_255 -> V_79 [ 0 ] ) ,
F_165 ( V_35 , V_255 -> V_79 [ 1 ] ) , & V_230 ) ;
return F_22 ( F_20 ( V_35 , V_255 -> V_81 ) , & V_230 ) ;
}
static int F_168 ( struct V_34 * V_35 ,
struct V_72 * V_255 )
{
struct V_39 V_230 ;
F_169 ( F_165 ( V_35 , V_255 -> V_79 [ 0 ] ) ,
F_165 ( V_35 , V_255 -> V_79 [ 1 ] ) ,
( unsigned long ) V_255 -> V_256 , & V_230 ) ;
return F_22 ( F_20 ( V_35 , V_255 -> V_81 ) , & V_230 ) ;
}
static int F_170 ( struct V_34 * V_35 ,
struct V_72 * V_255 )
{
struct V_39 V_230 ;
F_171 ( F_165 ( V_35 , V_255 -> V_79 [ 0 ] ) ,
( unsigned long ) V_255 -> V_256 ,
F_165 ( V_35 , V_255 -> V_79 [ 1 ] ) , & V_230 ) ;
return F_22 ( F_20 ( V_35 , V_255 -> V_81 ) , & V_230 ) ;
}
static int F_172 ( struct V_34 * V_35 ,
struct V_72 * V_255 )
{
unsigned int V_36 ;
struct V_39 * V_40 = F_20 ( V_35 , V_255 -> V_79 [ 0 ] ) ;
struct V_41 V_42 ;
struct V_41 * V_257 = F_13 ( V_35 , V_83 ) ;
F_173 ( & V_42 ) ;
for ( V_36 = 0 ; V_36 <= V_258 ; ++ V_36 ) {
int V_64 ;
if ( ! F_174 ( V_257 , V_36 ) )
continue;
V_64 = F_51 ( V_36 ) ;
if ( V_64 <= 0 )
continue;
if ( ( unsigned ) V_64 < V_40 -> V_69 || ( unsigned ) V_64 > V_40 -> V_70 )
F_175 ( & V_42 , V_36 ) ;
}
return F_18 ( V_257 , & V_42 ) ;
}
static int F_176 ( struct V_34 * V_35 ,
struct V_72 * V_255 )
{
struct V_39 V_230 ;
unsigned int V_36 ;
V_230 . V_69 = V_259 ;
V_230 . V_70 = 0 ;
V_230 . V_68 = 0 ;
V_230 . V_71 = 0 ;
for ( V_36 = 0 ; V_36 <= V_258 ; ++ V_36 ) {
int V_64 ;
if ( ! F_174 ( F_13 ( V_35 , V_83 ) , V_36 ) )
continue;
V_64 = F_51 ( V_36 ) ;
if ( V_64 <= 0 )
continue;
if ( V_230 . V_69 > ( unsigned ) V_64 )
V_230 . V_69 = V_64 ;
if ( V_230 . V_70 < ( unsigned ) V_64 )
V_230 . V_70 = V_64 ;
}
V_230 . integer = 1 ;
return F_22 ( F_20 ( V_35 , V_255 -> V_81 ) , & V_230 ) ;
}
static int F_177 ( struct V_34 * V_35 ,
struct V_72 * V_255 )
{
struct V_37 * V_38 = V_255 -> V_256 ;
return F_178 ( F_20 ( V_35 , V_255 -> V_81 ) ,
V_260 . V_254 ,
V_260 . V_261 , V_38 -> V_262 ) ;
}
static int F_179 ( struct V_34 * V_35 ,
struct V_72 * V_255 )
{
struct V_39 V_230 ;
struct V_2 * V_3 = V_255 -> V_256 ;
V_230 . V_69 = 0 ;
V_230 . V_70 = V_3 -> V_263 ;
V_230 . V_68 = 0 ;
V_230 . V_71 = 0 ;
V_230 . integer = 1 ;
return F_22 ( F_20 ( V_35 , V_255 -> V_81 ) , & V_230 ) ;
}
int F_180 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_43 * V_44 = & V_6 -> V_45 ;
int V_36 , V_30 ;
for ( V_36 = V_60 ; V_36 <= V_61 ; V_36 ++ ) {
F_173 ( F_19 ( V_44 , V_36 ) ) ;
}
for ( V_36 = V_66 ; V_36 <= V_49 ; V_36 ++ ) {
F_181 ( F_23 ( V_44 , V_36 ) ) ;
}
F_182 ( F_23 ( V_44 , V_84 ) ) ;
F_182 ( F_23 ( V_44 , V_264 ) ) ;
F_182 ( F_23 ( V_44 , V_265 ) ) ;
F_182 ( F_23 ( V_44 , V_55 ) ) ;
F_182 ( F_23 ( V_44 , V_266 ) ) ;
V_30 = F_183 ( V_6 , 0 , V_83 ,
F_172 , NULL ,
V_55 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , 0 , V_55 ,
F_176 , NULL ,
V_83 ,
V_55 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , 0 , V_55 ,
F_166 , NULL ,
V_266 , V_84 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , 0 , V_266 ,
F_163 , NULL ,
V_55 , V_84 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , 0 , V_266 ,
F_170 , ( void * ) 8 ,
V_267 , V_268 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , 0 , V_266 ,
F_170 , ( void * ) 8 ,
V_265 , V_264 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , 0 , V_84 ,
F_166 , NULL ,
V_266 , V_55 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , 0 , V_57 ,
F_170 , ( void * ) 1000000 ,
V_268 , V_269 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , 0 , V_57 ,
F_170 , ( void * ) 1000000 ,
V_264 , V_270 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , 0 , V_271 ,
F_166 , NULL ,
V_264 , V_268 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , 0 , V_268 ,
F_166 , NULL ,
V_264 , V_271 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , 0 , V_268 ,
F_170 , ( void * ) 8 ,
V_267 , V_266 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , 0 , V_268 ,
F_168 , ( void * ) 1000000 ,
V_269 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , 0 , V_264 ,
F_163 , NULL ,
V_268 , V_271 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , 0 , V_264 ,
F_170 , ( void * ) 8 ,
V_265 , V_266 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , 0 , V_264 ,
F_168 , ( void * ) 1000000 ,
V_270 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , 0 , V_267 ,
F_168 , ( void * ) 8 ,
V_268 , V_266 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , 0 , V_265 ,
F_168 , ( void * ) 8 ,
V_264 , V_266 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , 0 , V_269 ,
F_170 , ( void * ) 1000000 ,
V_268 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , 0 , V_270 ,
F_170 , ( void * ) 1000000 ,
V_264 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
return 0 ;
}
int F_184 ( struct V_2 * V_3 )
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
V_30 = F_185 ( V_6 , V_281 , V_257 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_186 ( V_6 , V_83 , V_38 -> V_282 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_185 ( V_6 , V_283 , 1 << V_284 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_187 ( V_6 , V_84 ,
V_38 -> V_285 , V_38 -> V_286 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_187 ( V_6 , V_57 ,
V_38 -> V_287 , V_38 -> V_288 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_187 ( V_6 , V_267 ,
V_38 -> V_289 , V_38 -> V_290 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_187 ( V_6 , V_271 ,
V_38 -> V_291 , V_38 -> V_292 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_187 ( V_6 , V_265 ,
V_38 -> V_289 , V_38 -> V_263 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_183 ( V_6 , 0 , V_265 ,
F_179 , V_3 ,
V_265 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_6 -> V_293 ) {
V_30 = F_187 ( V_6 , V_265 , 0 , V_6 -> V_293 ) ;
if ( V_30 < 0 )
return V_30 ;
}
if ( ! ( V_38 -> V_262 & ( V_294 | V_295 ) ) ) {
V_30 = F_183 ( V_6 , 0 , V_57 ,
F_177 , V_38 ,
V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
}
F_188 ( V_6 , V_268 ) ;
return 0 ;
}
static void F_189 ( struct V_2 * V_3 )
{
F_161 ( V_3 ) ;
}
void F_190 ( struct V_2 * V_3 )
{
V_3 -> V_296 -- ;
if ( V_3 -> V_296 > 0 )
return;
F_142 ( V_3 ) ;
if ( V_3 -> V_297 ) {
if ( V_3 -> V_26 -> V_130 != NULL )
V_3 -> V_26 -> V_130 ( V_3 ) ;
V_3 -> V_26 -> V_298 ( V_3 ) ;
V_3 -> V_297 = 0 ;
}
if ( F_53 ( & V_3 -> V_128 ) )
F_54 ( & V_3 -> V_128 ) ;
if ( V_3 -> V_299 ) {
V_3 -> V_299 ( V_3 ) ;
V_3 -> V_299 = NULL ;
}
F_191 ( V_3 ) ;
}
int F_192 ( struct V_7 * V_8 , int V_14 ,
struct V_216 * V_216 ,
struct V_2 * * V_300 )
{
struct V_2 * V_3 ;
int V_30 ;
V_30 = F_193 ( V_8 , V_14 , V_216 , & V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_3 -> V_296 > 1 ) {
* V_300 = V_3 ;
return 0 ;
}
V_30 = F_180 ( V_3 ) ;
if ( V_30 < 0 ) {
F_194 ( V_8 , L_13 ) ;
goto error;
}
if ( ( V_30 = V_3 -> V_26 -> V_301 ( V_3 ) ) < 0 )
goto error;
V_3 -> V_297 = 1 ;
V_30 = F_184 ( V_3 ) ;
if ( V_30 < 0 ) {
F_194 ( V_8 , L_14 ) ;
goto error;
}
* V_300 = V_3 ;
return 0 ;
error:
F_190 ( V_3 ) ;
return V_30 ;
}
static int F_195 ( struct V_216 * V_216 ,
struct V_7 * V_8 ,
int V_14 )
{
struct V_243 * V_244 ;
struct V_2 * V_3 ;
int V_30 ;
V_30 = F_192 ( V_8 , V_14 , V_216 , & V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
V_244 = F_196 ( sizeof( * V_244 ) , V_31 ) ;
if ( V_244 == NULL ) {
F_190 ( V_3 ) ;
return - V_32 ;
}
V_244 -> V_3 = V_3 ;
if ( V_3 -> V_296 == 1 ) {
V_3 -> V_216 = V_244 ;
V_3 -> V_299 = F_189 ;
}
V_216 -> V_249 = V_244 ;
return 0 ;
}
static int F_197 ( struct V_236 * V_236 , struct V_216 * V_216 )
{
struct V_7 * V_8 ;
int V_30 = F_198 ( V_236 , V_216 ) ;
if ( V_30 < 0 )
return V_30 ;
V_8 = F_148 ( F_147 ( V_236 ) ,
V_240 ) ;
V_30 = F_199 ( V_216 , V_8 , V_133 ) ;
if ( V_8 )
F_158 ( V_8 -> V_11 ) ;
return V_30 ;
}
static int F_200 ( struct V_236 * V_236 , struct V_216 * V_216 )
{
struct V_7 * V_8 ;
int V_30 = F_198 ( V_236 , V_216 ) ;
if ( V_30 < 0 )
return V_30 ;
V_8 = F_148 ( F_147 ( V_236 ) ,
V_241 ) ;
V_30 = F_199 ( V_216 , V_8 , V_302 ) ;
if ( V_8 )
F_158 ( V_8 -> V_11 ) ;
return V_30 ;
}
static int F_199 ( struct V_216 * V_216 , struct V_7 * V_8 , int V_14 )
{
int V_30 ;
T_5 V_219 ;
if ( V_8 == NULL ) {
V_30 = - V_232 ;
goto V_303;
}
V_30 = F_201 ( V_8 -> V_11 , V_216 ) ;
if ( V_30 < 0 )
goto V_303;
if ( ! F_202 ( V_8 -> V_11 -> V_304 ) ) {
V_30 = - V_33 ;
goto V_305;
}
F_136 ( & V_219 , V_227 ) ;
F_137 ( & V_8 -> V_306 , & V_219 ) ;
F_203 ( & V_8 -> V_307 ) ;
while ( 1 ) {
V_30 = F_195 ( V_216 , V_8 , V_14 ) ;
if ( V_30 >= 0 )
break;
if ( V_30 == - V_224 ) {
if ( V_216 -> V_214 & V_221 ) {
V_30 = - V_195 ;
break;
}
} else
break;
F_204 ( V_308 ) ;
F_205 ( & V_8 -> V_307 ) ;
F_206 () ;
F_203 ( & V_8 -> V_307 ) ;
if ( V_8 -> V_11 -> V_231 ) {
V_30 = - V_232 ;
break;
}
if ( F_135 ( V_227 ) ) {
V_30 = - V_228 ;
break;
}
}
F_140 ( & V_8 -> V_306 , & V_219 ) ;
F_205 ( & V_8 -> V_307 ) ;
if ( V_30 < 0 )
goto V_309;
return V_30 ;
V_309:
F_207 ( V_8 -> V_11 -> V_304 ) ;
V_305:
F_208 ( V_8 -> V_11 , V_216 ) ;
V_303:
return V_30 ;
}
static int F_209 ( struct V_236 * V_236 , struct V_216 * V_216 )
{
struct V_7 * V_8 ;
struct V_2 * V_3 ;
struct V_243 * V_244 ;
V_244 = V_216 -> V_249 ;
V_3 = V_244 -> V_3 ;
if ( F_210 ( ! V_3 ) )
return - V_94 ;
V_8 = V_3 -> V_8 ;
F_203 ( & V_8 -> V_307 ) ;
F_190 ( V_3 ) ;
F_11 ( V_244 ) ;
F_205 ( & V_8 -> V_307 ) ;
F_98 ( & V_8 -> V_306 ) ;
F_207 ( V_8 -> V_11 -> V_304 ) ;
F_208 ( V_8 -> V_11 , V_216 ) ;
return 0 ;
}
static T_6 F_211 ( struct V_2 * V_3 ,
T_3 V_93 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_142 ;
T_6 V_310 ;
T_6 V_311 ;
if ( V_93 == 0 )
return 0 ;
F_37 ( V_3 ) ;
switch ( V_6 -> V_91 -> V_90 ) {
case V_97 :
break;
case V_146 :
case V_145 :
if ( F_65 ( V_3 ) >= 0 )
break;
case V_207 :
V_310 = - V_170 ;
goto V_312;
case V_194 :
V_310 = - V_233 ;
goto V_312;
default:
V_310 = - V_98 ;
goto V_312;
}
V_311 = F_212 ( V_6 ) ;
if ( V_311 <= 0 ) {
V_310 = 0 ;
goto V_312;
}
if ( V_93 > ( T_3 ) V_311 )
V_93 = V_311 ;
V_142 = V_6 -> V_120 -> V_142 - V_93 ;
if ( V_142 < 0 )
V_142 += V_6 -> V_126 ;
V_6 -> V_120 -> V_142 = V_142 ;
V_310 = V_93 ;
V_312:
F_38 ( V_3 ) ;
return V_310 ;
}
static T_6 F_213 ( struct V_2 * V_3 ,
T_3 V_93 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_142 ;
T_6 V_310 ;
T_6 V_311 ;
if ( V_93 == 0 )
return 0 ;
F_37 ( V_3 ) ;
switch ( V_6 -> V_91 -> V_90 ) {
case V_97 :
case V_146 :
break;
case V_145 :
if ( F_65 ( V_3 ) >= 0 )
break;
case V_207 :
V_310 = - V_170 ;
goto V_312;
case V_194 :
V_310 = - V_233 ;
goto V_312;
default:
V_310 = - V_98 ;
goto V_312;
}
V_311 = F_214 ( V_6 ) ;
if ( V_311 <= 0 ) {
V_310 = 0 ;
goto V_312;
}
if ( V_93 > ( T_3 ) V_311 )
V_93 = V_311 ;
V_142 = V_6 -> V_120 -> V_142 - V_93 ;
if ( V_142 < 0 )
V_142 += V_6 -> V_126 ;
V_6 -> V_120 -> V_142 = V_142 ;
V_310 = V_93 ;
V_312:
F_38 ( V_3 ) ;
return V_310 ;
}
static T_6 F_215 ( struct V_2 * V_3 ,
T_3 V_93 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_142 ;
T_6 V_310 ;
T_6 V_144 ;
if ( V_93 == 0 )
return 0 ;
F_37 ( V_3 ) ;
switch ( V_6 -> V_91 -> V_90 ) {
case V_97 :
case V_188 :
break;
case V_146 :
case V_145 :
if ( F_65 ( V_3 ) >= 0 )
break;
case V_207 :
V_310 = - V_170 ;
goto V_312;
case V_194 :
V_310 = - V_233 ;
goto V_312;
default:
V_310 = - V_98 ;
goto V_312;
}
V_144 = F_67 ( V_6 ) ;
if ( V_144 <= 0 ) {
V_310 = 0 ;
goto V_312;
}
if ( V_93 > ( T_3 ) V_144 )
V_93 = V_144 ;
V_142 = V_6 -> V_120 -> V_142 + V_93 ;
if ( V_142 >= ( T_6 ) V_6 -> V_126 )
V_142 -= V_6 -> V_126 ;
V_6 -> V_120 -> V_142 = V_142 ;
V_310 = V_93 ;
V_312:
F_38 ( V_3 ) ;
return V_310 ;
}
static T_6 F_216 ( struct V_2 * V_3 ,
T_3 V_93 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_142 ;
T_6 V_310 ;
T_6 V_144 ;
if ( V_93 == 0 )
return 0 ;
F_37 ( V_3 ) ;
switch ( V_6 -> V_91 -> V_90 ) {
case V_97 :
case V_146 :
case V_188 :
break;
case V_145 :
if ( F_65 ( V_3 ) >= 0 )
break;
case V_207 :
V_310 = - V_170 ;
goto V_312;
case V_194 :
V_310 = - V_233 ;
goto V_312;
default:
V_310 = - V_98 ;
goto V_312;
}
V_144 = F_68 ( V_6 ) ;
if ( V_144 <= 0 ) {
V_310 = 0 ;
goto V_312;
}
if ( V_93 > ( T_3 ) V_144 )
V_93 = V_144 ;
V_142 = V_6 -> V_120 -> V_142 + V_93 ;
if ( V_142 >= ( T_6 ) V_6 -> V_126 )
V_142 -= V_6 -> V_126 ;
V_6 -> V_120 -> V_142 = V_142 ;
V_310 = V_93 ;
V_312:
F_38 ( V_3 ) ;
return V_310 ;
}
static int F_217 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_30 ;
F_37 ( V_3 ) ;
switch ( V_6 -> V_91 -> V_90 ) {
case V_146 :
if ( V_3 -> V_14 == V_302 )
goto V_313;
case V_145 :
if ( ( V_30 = F_65 ( V_3 ) ) < 0 )
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
F_38 ( V_3 ) ;
return V_30 ;
}
static int F_218 ( struct V_2 * V_3 ,
T_6 T_2 * V_151 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_30 ;
T_6 V_314 = 0 ;
F_37 ( V_3 ) ;
switch ( V_6 -> V_91 -> V_90 ) {
case V_146 :
if ( V_3 -> V_14 == V_302 )
goto V_313;
case V_145 :
if ( ( V_30 = F_65 ( V_3 ) ) < 0 )
break;
case V_97 :
case V_194 :
V_30 = 0 ;
if ( V_3 -> V_14 == V_133 )
V_314 = F_212 ( V_6 ) ;
else
V_314 = F_68 ( V_6 ) ;
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
F_38 ( V_3 ) ;
if ( ! V_30 )
if ( F_219 ( V_314 , V_151 ) )
V_30 = - V_33 ;
return V_30 ;
}
static int F_220 ( struct V_2 * V_3 ,
struct F_220 T_2 * V_315 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct F_220 V_316 ;
volatile struct V_317 * V_91 ;
volatile struct V_318 * V_120 ;
int V_30 ;
memset ( & V_316 , 0 , sizeof( V_316 ) ) ;
if ( F_221 ( V_316 . V_78 , ( unsigned T_2 * ) & ( V_315 -> V_78 ) ) )
return - V_33 ;
if ( F_63 ( & V_316 . V_319 . V_120 , & ( V_315 -> V_319 . V_120 ) , sizeof( struct V_318 ) ) )
return - V_33 ;
V_91 = V_6 -> V_91 ;
V_120 = V_6 -> V_120 ;
if ( V_316 . V_78 & V_320 ) {
V_30 = F_217 ( V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
}
F_37 ( V_3 ) ;
if ( ! ( V_316 . V_78 & V_321 ) )
V_120 -> V_142 = V_316 . V_319 . V_120 . V_142 ;
else
V_316 . V_319 . V_120 . V_142 = V_120 -> V_142 ;
if ( ! ( V_316 . V_78 & V_322 ) )
V_120 -> V_121 = V_316 . V_319 . V_120 . V_121 ;
else
V_316 . V_319 . V_120 . V_121 = V_120 -> V_121 ;
V_316 . V_157 . V_91 . V_90 = V_91 -> V_90 ;
V_316 . V_157 . V_91 . V_143 = V_91 -> V_143 ;
V_316 . V_157 . V_91 . V_139 = V_91 -> V_139 ;
V_316 . V_157 . V_91 . V_135 = V_91 -> V_135 ;
F_38 ( V_3 ) ;
if ( F_10 ( V_315 , & V_316 , sizeof( V_316 ) ) )
return - V_33 ;
return 0 ;
}
static int F_222 ( struct V_2 * V_3 , int T_2 * V_323 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_324 ;
if ( F_221 ( V_324 , V_323 ) )
return - V_33 ;
if ( V_324 < 0 || V_324 > V_325 )
return - V_62 ;
V_6 -> V_326 = V_327 ;
if ( V_324 == V_328 )
V_6 -> V_326 = V_328 ;
return 0 ;
}
static int F_223 ( struct V_216 * V_216 ,
struct V_2 * V_3 ,
unsigned int V_329 , void T_2 * V_324 )
{
switch ( V_329 ) {
case V_330 :
return F_219 ( V_331 , ( int T_2 * ) V_324 ) ? - V_33 : 0 ;
case V_332 :
return F_8 ( V_3 , V_324 ) ;
case V_333 :
return 0 ;
case V_334 :
return F_222 ( V_3 , V_324 ) ;
case V_335 :
return F_31 ( V_3 , V_324 ) ;
case V_336 :
return F_56 ( V_3 , V_324 ) ;
case V_337 :
return F_57 ( V_3 ) ;
case V_338 :
return F_62 ( V_3 , V_324 ) ;
case V_339 :
return F_69 ( V_3 , V_324 ) ;
case V_340 :
return F_71 ( V_3 , V_324 ) ;
case V_341 :
return F_129 ( V_3 , V_216 ) ;
case V_342 :
return F_125 ( V_3 ) ;
case V_343 :
return F_82 ( & V_180 , V_3 , V_145 ) ;
case V_344 :
return F_149 ( V_3 , ( int ) ( unsigned long ) V_324 ) ;
case V_345 :
return F_161 ( V_3 ) ;
case V_346 :
return F_117 ( V_3 ) ;
case V_347 :
return F_121 ( V_3 ) ;
case V_348 :
return F_217 ( V_3 ) ;
case V_349 :
return F_218 ( V_3 , V_324 ) ;
case V_350 :
return F_220 ( V_3 , V_324 ) ;
#ifdef F_224
case V_351 :
return F_225 ( V_3 , V_324 ) ;
case V_352 :
return F_226 ( V_3 , V_324 ) ;
#endif
case V_353 :
return F_134 ( V_3 , V_216 ) ;
case V_354 :
return F_142 ( V_3 ) ;
case V_355 :
{
int V_151 ;
F_37 ( V_3 ) ;
V_151 = F_105 ( V_3 , ( int ) ( unsigned long ) V_324 ) ;
F_38 ( V_3 ) ;
return V_151 ;
}
}
F_194 ( V_3 -> V_8 , L_15 , V_329 ) ;
return - V_356 ;
}
static int F_227 ( struct V_216 * V_216 ,
struct V_2 * V_3 ,
unsigned int V_329 , void T_2 * V_324 )
{
if ( F_210 ( ! V_3 ) )
return - V_94 ;
if ( F_210 ( V_3 -> V_14 != V_133 ) )
return - V_62 ;
switch ( V_329 ) {
case V_357 :
{
struct V_358 V_359 ;
struct V_358 T_2 * V_360 = V_324 ;
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_131 ;
if ( V_6 -> V_91 -> V_90 == V_95 )
return - V_98 ;
if ( F_219 ( 0 , & V_360 -> V_131 ) )
return - V_33 ;
if ( F_63 ( & V_359 , V_360 , sizeof( V_359 ) ) )
return - V_33 ;
V_131 = F_228 ( V_3 , V_359 . V_361 , V_359 . V_93 ) ;
F_229 ( V_131 , & V_360 -> V_131 ) ;
return V_131 < 0 ? V_131 : 0 ;
}
case V_362 :
{
struct V_363 V_364 ;
struct V_363 T_2 * V_365 = V_324 ;
struct V_5 * V_6 = V_3 -> V_6 ;
void T_2 * * V_366 ;
T_6 V_131 ;
if ( V_6 -> V_91 -> V_90 == V_95 )
return - V_98 ;
if ( V_6 -> V_107 > 128 )
return - V_62 ;
if ( F_219 ( 0 , & V_365 -> V_131 ) )
return - V_33 ;
if ( F_63 ( & V_364 , V_365 , sizeof( V_364 ) ) )
return - V_33 ;
V_366 = F_32 ( V_364 . V_366 ,
sizeof( void * ) * V_6 -> V_107 ) ;
if ( F_33 ( V_366 ) )
return F_34 ( V_366 ) ;
V_131 = F_230 ( V_3 , V_366 , V_364 . V_93 ) ;
F_11 ( V_366 ) ;
F_229 ( V_131 , & V_365 -> V_131 ) ;
return V_131 < 0 ? V_131 : 0 ;
}
case V_367 :
{
T_3 V_93 ;
T_3 T_2 * V_368 = V_324 ;
T_6 V_131 ;
if ( F_221 ( V_93 , V_368 ) )
return - V_33 ;
if ( F_219 ( 0 , V_368 ) )
return - V_33 ;
V_131 = F_211 ( V_3 , V_93 ) ;
F_229 ( V_131 , V_368 ) ;
return V_131 < 0 ? V_131 : 0 ;
}
case V_369 :
{
T_3 V_93 ;
T_3 T_2 * V_368 = V_324 ;
T_6 V_131 ;
if ( F_221 ( V_93 , V_368 ) )
return - V_33 ;
if ( F_219 ( 0 , V_368 ) )
return - V_33 ;
V_131 = F_215 ( V_3 , V_93 ) ;
F_229 ( V_131 , V_368 ) ;
return V_131 < 0 ? V_131 : 0 ;
}
}
return F_223 ( V_216 , V_3 , V_329 , V_324 ) ;
}
static int F_231 ( struct V_216 * V_216 ,
struct V_2 * V_3 ,
unsigned int V_329 , void T_2 * V_324 )
{
if ( F_210 ( ! V_3 ) )
return - V_94 ;
if ( F_210 ( V_3 -> V_14 != V_302 ) )
return - V_62 ;
switch ( V_329 ) {
case V_370 :
{
struct V_358 V_359 ;
struct V_358 T_2 * V_360 = V_324 ;
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_131 ;
if ( V_6 -> V_91 -> V_90 == V_95 )
return - V_98 ;
if ( F_219 ( 0 , & V_360 -> V_131 ) )
return - V_33 ;
if ( F_63 ( & V_359 , V_360 , sizeof( V_359 ) ) )
return - V_33 ;
V_131 = F_232 ( V_3 , V_359 . V_361 , V_359 . V_93 ) ;
F_229 ( V_131 , & V_360 -> V_131 ) ;
return V_131 < 0 ? V_131 : 0 ;
}
case V_371 :
{
struct V_363 V_364 ;
struct V_363 T_2 * V_365 = V_324 ;
struct V_5 * V_6 = V_3 -> V_6 ;
void * V_366 ;
T_6 V_131 ;
if ( V_6 -> V_91 -> V_90 == V_95 )
return - V_98 ;
if ( V_6 -> V_107 > 128 )
return - V_62 ;
if ( F_219 ( 0 , & V_365 -> V_131 ) )
return - V_33 ;
if ( F_63 ( & V_364 , V_365 , sizeof( V_364 ) ) )
return - V_33 ;
V_366 = F_32 ( V_364 . V_366 ,
sizeof( void * ) * V_6 -> V_107 ) ;
if ( F_33 ( V_366 ) )
return F_34 ( V_366 ) ;
V_131 = F_233 ( V_3 , V_366 , V_364 . V_93 ) ;
F_11 ( V_366 ) ;
F_229 ( V_131 , & V_365 -> V_131 ) ;
return V_131 < 0 ? V_131 : 0 ;
}
case V_367 :
{
T_3 V_93 ;
T_3 T_2 * V_368 = V_324 ;
T_6 V_131 ;
if ( F_221 ( V_93 , V_368 ) )
return - V_33 ;
if ( F_219 ( 0 , V_368 ) )
return - V_33 ;
V_131 = F_213 ( V_3 , V_93 ) ;
F_229 ( V_131 , V_368 ) ;
return V_131 < 0 ? V_131 : 0 ;
}
case V_369 :
{
T_3 V_93 ;
T_3 T_2 * V_368 = V_324 ;
T_6 V_131 ;
if ( F_221 ( V_93 , V_368 ) )
return - V_33 ;
if ( F_219 ( 0 , V_368 ) )
return - V_33 ;
V_131 = F_216 ( V_3 , V_93 ) ;
F_229 ( V_131 , V_368 ) ;
return V_131 < 0 ? V_131 : 0 ;
}
}
return F_223 ( V_216 , V_3 , V_329 , V_324 ) ;
}
static long F_234 ( struct V_216 * V_216 , unsigned int V_329 ,
unsigned long V_324 )
{
struct V_243 * V_244 ;
V_244 = V_216 -> V_249 ;
if ( ( ( V_329 >> 8 ) & 0xff ) != 'A' )
return - V_356 ;
return F_227 ( V_216 , V_244 -> V_3 , V_329 ,
( void T_2 * ) V_324 ) ;
}
static long F_235 ( struct V_216 * V_216 , unsigned int V_329 ,
unsigned long V_324 )
{
struct V_243 * V_244 ;
V_244 = V_216 -> V_249 ;
if ( ( ( V_329 >> 8 ) & 0xff ) != 'A' )
return - V_356 ;
return F_231 ( V_216 , V_244 -> V_3 , V_329 ,
( void T_2 * ) V_324 ) ;
}
int F_236 ( struct V_2 * V_3 ,
unsigned int V_329 , void * V_324 )
{
T_1 V_1 ;
int V_131 ;
V_1 = F_1 () ;
switch ( V_3 -> V_14 ) {
case V_133 :
V_131 = F_227 ( NULL , V_3 , V_329 ,
( void T_2 * ) V_324 ) ;
break;
case V_302 :
V_131 = F_231 ( NULL , V_3 , V_329 ,
( void T_2 * ) V_324 ) ;
break;
default:
V_131 = - V_62 ;
break;
}
F_5 ( V_1 ) ;
return V_131 ;
}
static T_7 F_237 ( struct V_216 * V_216 , char T_2 * V_361 , T_8 V_254 ,
T_9 * V_372 )
{
struct V_243 * V_244 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_131 ;
V_244 = V_216 -> V_249 ;
V_3 = V_244 -> V_3 ;
if ( F_39 ( V_3 ) )
return - V_94 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_91 -> V_90 == V_95 )
return - V_98 ;
if ( ! F_238 ( V_6 , V_254 ) )
return - V_62 ;
V_254 = F_239 ( V_6 , V_254 ) ;
V_131 = F_232 ( V_3 , V_361 , V_254 ) ;
if ( V_131 > 0 )
V_131 = F_240 ( V_6 , V_131 ) ;
return V_131 ;
}
static T_7 F_241 ( struct V_216 * V_216 , const char T_2 * V_361 ,
T_8 V_254 , T_9 * V_372 )
{
struct V_243 * V_244 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_131 ;
V_244 = V_216 -> V_249 ;
V_3 = V_244 -> V_3 ;
if ( F_39 ( V_3 ) )
return - V_94 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_91 -> V_90 == V_95 )
return - V_98 ;
if ( ! F_238 ( V_6 , V_254 ) )
return - V_62 ;
V_254 = F_239 ( V_6 , V_254 ) ;
V_131 = F_228 ( V_3 , V_361 , V_254 ) ;
if ( V_131 > 0 )
V_131 = F_240 ( V_6 , V_131 ) ;
return V_131 ;
}
static T_7 F_242 ( struct V_373 * V_374 , const struct V_375 * V_376 ,
unsigned long V_377 , T_9 V_378 )
{
struct V_243 * V_244 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_131 ;
unsigned long V_40 ;
void T_2 * * V_366 ;
T_3 V_93 ;
V_244 = V_374 -> V_379 -> V_249 ;
V_3 = V_244 -> V_3 ;
if ( F_39 ( V_3 ) )
return - V_94 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_91 -> V_90 == V_95 )
return - V_98 ;
if ( V_377 > 1024 || V_377 != V_6 -> V_107 )
return - V_62 ;
if ( ! F_238 ( V_6 , V_376 -> V_380 ) )
return - V_62 ;
V_93 = F_243 ( V_6 , V_376 -> V_380 ) ;
V_366 = F_9 ( sizeof( void * ) * V_377 , V_31 ) ;
if ( V_366 == NULL )
return - V_32 ;
for ( V_40 = 0 ; V_40 < V_377 ; ++ V_40 )
V_366 [ V_40 ] = V_376 [ V_40 ] . V_381 ;
V_131 = F_233 ( V_3 , V_366 , V_93 ) ;
if ( V_131 > 0 )
V_131 = F_240 ( V_6 , V_131 ) ;
F_11 ( V_366 ) ;
return V_131 ;
}
static T_7 F_244 ( struct V_373 * V_374 , const struct V_375 * V_376 ,
unsigned long V_377 , T_9 V_378 )
{
struct V_243 * V_244 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_131 ;
unsigned long V_40 ;
void T_2 * * V_366 ;
T_3 V_93 ;
V_244 = V_374 -> V_379 -> V_249 ;
V_3 = V_244 -> V_3 ;
if ( F_39 ( V_3 ) )
return - V_94 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_91 -> V_90 == V_95 )
return - V_98 ;
if ( V_377 > 128 || V_377 != V_6 -> V_107 ||
! F_238 ( V_6 , V_376 -> V_380 ) )
return - V_62 ;
V_93 = F_243 ( V_6 , V_376 -> V_380 ) ;
V_366 = F_9 ( sizeof( void * ) * V_377 , V_31 ) ;
if ( V_366 == NULL )
return - V_32 ;
for ( V_40 = 0 ; V_40 < V_377 ; ++ V_40 )
V_366 [ V_40 ] = V_376 [ V_40 ] . V_381 ;
V_131 = F_230 ( V_3 , V_366 , V_93 ) ;
if ( V_131 > 0 )
V_131 = F_240 ( V_6 , V_131 ) ;
F_11 ( V_366 ) ;
return V_131 ;
}
static unsigned int F_245 ( struct V_216 * V_216 , T_10 * V_219 )
{
struct V_243 * V_244 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
unsigned int V_257 ;
T_3 V_144 ;
V_244 = V_216 -> V_249 ;
V_3 = V_244 -> V_3 ;
if ( F_39 ( V_3 ) )
return - V_94 ;
V_6 = V_3 -> V_6 ;
F_246 ( V_216 , & V_6 -> V_182 , V_219 ) ;
F_37 ( V_3 ) ;
V_144 = F_67 ( V_6 ) ;
switch ( V_6 -> V_91 -> V_90 ) {
case V_145 :
case V_97 :
case V_188 :
if ( V_144 >= V_6 -> V_120 -> V_121 ) {
V_257 = V_382 | V_383 ;
break;
}
case V_146 :
V_257 = 0 ;
break;
default:
V_257 = V_382 | V_383 | V_384 ;
break;
}
F_38 ( V_3 ) ;
return V_257 ;
}
static unsigned int F_247 ( struct V_216 * V_216 , T_10 * V_219 )
{
struct V_243 * V_244 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
unsigned int V_257 ;
T_3 V_144 ;
V_244 = V_216 -> V_249 ;
V_3 = V_244 -> V_3 ;
if ( F_39 ( V_3 ) )
return - V_94 ;
V_6 = V_3 -> V_6 ;
F_246 ( V_216 , & V_6 -> V_182 , V_219 ) ;
F_37 ( V_3 ) ;
V_144 = F_68 ( V_6 ) ;
switch ( V_6 -> V_91 -> V_90 ) {
case V_145 :
case V_97 :
case V_188 :
if ( V_144 >= V_6 -> V_120 -> V_121 ) {
V_257 = V_385 | V_386 ;
break;
}
V_257 = 0 ;
break;
case V_146 :
if ( V_144 > 0 ) {
V_257 = V_385 | V_386 ;
break;
}
default:
V_257 = V_385 | V_386 | V_384 ;
break;
}
F_38 ( V_3 ) ;
return V_257 ;
}
static int F_248 ( struct V_387 * V_388 ,
struct V_389 * V_390 )
{
struct V_2 * V_3 = V_388 -> V_391 ;
struct V_5 * V_6 ;
if ( V_3 == NULL )
return V_392 ;
V_6 = V_3 -> V_6 ;
V_390 -> V_393 = F_249 ( V_6 -> V_91 ) ;
F_250 ( V_390 -> V_393 ) ;
return 0 ;
}
static int V_317 ( struct V_2 * V_3 , struct V_216 * V_216 ,
struct V_387 * V_388 )
{
long V_394 ;
if ( ! ( V_388 -> V_395 & V_396 ) )
return - V_62 ;
V_394 = V_388 -> V_397 - V_388 -> V_398 ;
if ( V_394 != F_251 ( sizeof( struct V_317 ) ) )
return - V_62 ;
V_388 -> V_399 = & V_400 ;
V_388 -> V_391 = V_3 ;
V_388 -> V_395 |= V_401 | V_402 ;
return 0 ;
}
static int F_252 ( struct V_387 * V_388 ,
struct V_389 * V_390 )
{
struct V_2 * V_3 = V_388 -> V_391 ;
struct V_5 * V_6 ;
if ( V_3 == NULL )
return V_392 ;
V_6 = V_3 -> V_6 ;
V_390 -> V_393 = F_249 ( V_6 -> V_120 ) ;
F_250 ( V_390 -> V_393 ) ;
return 0 ;
}
static int V_318 ( struct V_2 * V_3 , struct V_216 * V_216 ,
struct V_387 * V_388 )
{
long V_394 ;
if ( ! ( V_388 -> V_395 & V_396 ) )
return - V_62 ;
V_394 = V_388 -> V_397 - V_388 -> V_398 ;
if ( V_394 != F_251 ( sizeof( struct V_318 ) ) )
return - V_62 ;
V_388 -> V_399 = & V_403 ;
V_388 -> V_391 = V_3 ;
V_388 -> V_395 |= V_401 | V_402 ;
return 0 ;
}
static int V_317 ( struct V_2 * V_3 , struct V_216 * V_216 ,
struct V_387 * V_388 )
{
return - V_94 ;
}
static int V_318 ( struct V_2 * V_3 , struct V_216 * V_216 ,
struct V_387 * V_388 )
{
return - V_94 ;
}
static inline struct V_393 *
F_253 ( struct V_2 * V_3 , unsigned long V_404 )
{
void * V_405 = V_3 -> V_6 -> V_406 + V_404 ;
#if F_254 ( V_407 ) && F_254 ( V_408 )
if ( V_3 -> V_409 . V_234 . type == V_410 )
return F_249 ( F_255 ( V_405 ) ) ;
#endif
#if F_254 ( V_411 ) && F_254 ( V_412 )
if ( V_3 -> V_409 . V_234 . type == V_410 ) {
T_11 V_413 = V_3 -> V_6 -> V_414 + V_404 ;
V_413 -= F_256 ( V_3 -> V_409 . V_234 . V_234 ) ;
return F_257 ( V_413 >> V_415 ) ;
}
#endif
return F_249 ( V_405 ) ;
}
static int F_258 ( struct V_387 * V_388 ,
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
V_372 = V_390 -> V_416 << V_415 ;
V_293 = F_251 ( V_6 -> V_293 ) ;
if ( V_372 > V_293 - V_417 )
return V_392 ;
if ( V_3 -> V_26 -> V_393 )
V_393 = V_3 -> V_26 -> V_393 ( V_3 , V_372 ) ;
else
V_393 = F_253 ( V_3 , V_372 ) ;
if ( ! V_393 )
return V_392 ;
F_250 ( V_393 ) ;
V_390 -> V_393 = V_393 ;
return 0 ;
}
int F_259 ( struct V_2 * V_3 ,
struct V_387 * V_388 )
{
V_388 -> V_395 |= V_401 | V_402 ;
#ifdef F_260
if ( V_3 -> V_409 . V_234 . type == V_418 ) {
V_388 -> V_419 = F_261 ( V_388 -> V_419 ) ;
return F_262 ( V_388 , V_388 -> V_398 ,
V_3 -> V_409 . V_413 >> V_415 ,
V_388 -> V_397 - V_388 -> V_398 , V_388 -> V_419 ) ;
}
#endif
#ifdef F_263
if ( ! V_3 -> V_26 -> V_393 &&
V_3 -> V_409 . V_234 . type == V_410 )
return F_264 ( V_3 -> V_409 . V_234 . V_234 ,
V_388 ,
V_3 -> V_6 -> V_406 ,
V_3 -> V_6 -> V_414 ,
V_388 -> V_397 - V_388 -> V_398 ) ;
#elif F_254 ( V_407 ) && F_254 ( V_408 )
if ( V_3 -> V_409 . V_234 . type == V_410 &&
! F_265 ( V_3 -> V_409 . V_234 . V_234 ) )
V_388 -> V_419 = F_266 ( V_388 -> V_419 ) ;
#endif
V_388 -> V_399 = & V_420 ;
return 0 ;
}
int F_267 ( struct V_2 * V_3 ,
struct V_387 * V_388 )
{
struct V_5 * V_6 = V_3 -> V_6 ; ;
V_388 -> V_419 = F_266 ( V_388 -> V_419 ) ;
return F_268 ( V_388 , V_6 -> V_414 , V_6 -> V_293 ) ;
}
int F_269 ( struct V_2 * V_3 , struct V_216 * V_216 ,
struct V_387 * V_388 )
{
struct V_5 * V_6 ;
long V_394 ;
unsigned long V_372 ;
T_8 V_293 ;
int V_30 ;
if ( V_3 -> V_14 == V_133 ) {
if ( ! ( V_388 -> V_395 & ( V_421 | V_396 ) ) )
return - V_62 ;
} else {
if ( ! ( V_388 -> V_395 & V_396 ) )
return - V_62 ;
}
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_91 -> V_90 == V_95 )
return - V_98 ;
if ( ! ( V_6 -> V_4 & V_276 ) )
return - V_94 ;
if ( V_6 -> V_104 == V_273 ||
V_6 -> V_104 == V_275 )
return - V_62 ;
V_394 = V_388 -> V_397 - V_388 -> V_398 ;
V_372 = V_388 -> V_422 << V_415 ;
V_293 = F_251 ( V_6 -> V_293 ) ;
if ( ( T_8 ) V_394 > V_293 )
return - V_62 ;
if ( V_372 > V_293 - V_394 )
return - V_62 ;
V_388 -> V_399 = & V_423 ;
V_388 -> V_391 = V_3 ;
if ( V_3 -> V_26 -> V_424 )
V_30 = V_3 -> V_26 -> V_424 ( V_3 , V_388 ) ;
else
V_30 = F_259 ( V_3 , V_388 ) ;
if ( ! V_30 )
F_270 ( & V_3 -> V_101 ) ;
return V_30 ;
}
static int F_271 ( struct V_216 * V_216 , struct V_387 * V_388 )
{
struct V_243 * V_244 ;
struct V_2 * V_3 ;
unsigned long V_372 ;
V_244 = V_216 -> V_249 ;
V_3 = V_244 -> V_3 ;
if ( F_39 ( V_3 ) )
return - V_94 ;
V_372 = V_388 -> V_422 << V_415 ;
switch ( V_372 ) {
case V_425 :
if ( V_244 -> V_426 )
return - V_94 ;
return V_317 ( V_3 , V_216 , V_388 ) ;
case V_427 :
if ( V_244 -> V_426 )
return - V_94 ;
return V_318 ( V_3 , V_216 , V_388 ) ;
default:
return F_269 ( V_3 , V_216 , V_388 ) ;
}
return 0 ;
}
static int F_272 ( int V_242 , struct V_216 * V_216 , int V_428 )
{
struct V_243 * V_244 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
V_244 = V_216 -> V_249 ;
V_3 = V_244 -> V_3 ;
if ( F_39 ( V_3 ) )
return - V_94 ;
V_6 = V_3 -> V_6 ;
return F_273 ( V_242 , V_216 , V_428 , & V_6 -> V_429 ) ;
}
static void F_274 ( struct V_34 * V_35 ,
struct V_430 * V_431 )
{
unsigned int V_40 ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
V_35 -> V_78 = V_431 -> V_78 ;
for ( V_40 = 0 ; V_40 < F_275 ( V_431 -> V_432 ) ; V_40 ++ )
V_35 -> V_432 [ V_40 ] . V_64 [ 0 ] = V_431 -> V_432 [ V_40 ] ;
memcpy ( V_35 -> V_433 , V_431 -> V_433 , sizeof( V_431 -> V_433 ) ) ;
V_35 -> V_54 = F_276 ( V_431 -> V_54 ) ;
V_35 -> V_65 = F_276 ( V_431 -> V_65 ) ;
V_35 -> V_4 = V_431 -> V_4 ;
V_35 -> V_56 = V_431 -> V_56 ;
V_35 -> V_58 = V_431 -> V_58 ;
V_35 -> V_59 = V_431 -> V_59 ;
V_35 -> V_53 = V_431 -> V_53 ;
}
static void F_277 ( struct V_430 * V_431 ,
struct V_34 * V_35 )
{
unsigned int V_40 ;
memset ( V_431 , 0 , sizeof( * V_431 ) ) ;
V_431 -> V_78 = V_35 -> V_78 ;
for ( V_40 = 0 ; V_40 < F_275 ( V_431 -> V_432 ) ; V_40 ++ )
V_431 -> V_432 [ V_40 ] = V_35 -> V_432 [ V_40 ] . V_64 [ 0 ] ;
memcpy ( V_431 -> V_433 , V_35 -> V_433 , sizeof( V_431 -> V_433 ) ) ;
V_431 -> V_54 = F_278 ( V_35 -> V_54 ) ;
V_431 -> V_65 = F_278 ( V_35 -> V_65 ) ;
V_431 -> V_4 = V_35 -> V_4 ;
V_431 -> V_56 = V_35 -> V_56 ;
V_431 -> V_58 = V_35 -> V_58 ;
V_431 -> V_59 = V_35 -> V_59 ;
V_431 -> V_53 = V_35 -> V_53 ;
}
static int F_225 ( struct V_2 * V_3 ,
struct V_430 T_2 * V_434 )
{
struct V_34 * V_35 ;
struct V_430 * V_431 = NULL ;
int V_30 ;
V_35 = F_9 ( sizeof( * V_35 ) , V_31 ) ;
if ( ! V_35 )
return - V_32 ;
V_431 = F_32 ( V_434 , sizeof( * V_431 ) ) ;
if ( F_33 ( V_431 ) ) {
V_30 = F_34 ( V_431 ) ;
goto V_435;
}
F_274 ( V_35 , V_431 ) ;
V_30 = F_12 ( V_3 , V_35 ) ;
F_277 ( V_431 , V_35 ) ;
if ( F_10 ( V_434 , V_431 , sizeof( * V_431 ) ) ) {
if ( ! V_30 )
V_30 = - V_33 ;
}
F_11 ( V_431 ) ;
V_435:
F_11 ( V_35 ) ;
return V_30 ;
}
static int F_226 ( struct V_2 * V_3 ,
struct V_430 T_2 * V_434 )
{
struct V_34 * V_35 ;
struct V_430 * V_431 = NULL ;
int V_30 ;
V_35 = F_9 ( sizeof( * V_35 ) , V_31 ) ;
if ( ! V_35 )
return - V_32 ;
V_431 = F_32 ( V_434 , sizeof( * V_431 ) ) ;
if ( F_33 ( V_431 ) ) {
V_30 = F_34 ( V_431 ) ;
goto V_435;
}
F_274 ( V_35 , V_431 ) ;
V_30 = V_34 ( V_3 , V_35 ) ;
F_277 ( V_431 , V_35 ) ;
if ( F_10 ( V_434 , V_431 , sizeof( * V_431 ) ) ) {
if ( ! V_30 )
V_30 = - V_33 ;
}
F_11 ( V_431 ) ;
V_435:
F_11 ( V_35 ) ;
return V_30 ;
}
static unsigned long F_279 ( struct V_216 * V_216 ,
unsigned long V_413 ,
unsigned long V_436 ,
unsigned long V_416 ,
unsigned long V_78 )
{
struct V_243 * V_244 = V_216 -> V_249 ;
struct V_2 * V_3 = V_244 -> V_3 ;
struct V_5 * V_6 = V_3 -> V_6 ;
unsigned long V_372 = V_416 << V_415 ;
switch ( V_372 ) {
case V_425 :
return ( unsigned long ) V_6 -> V_91 ;
case V_427 :
return ( unsigned long ) V_6 -> V_120 ;
default:
return ( unsigned long ) V_6 -> V_406 + V_372 ;
}
}
