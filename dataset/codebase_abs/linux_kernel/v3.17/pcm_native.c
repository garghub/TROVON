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
if ( V_35 -> V_133 >= F_59 ( 2 , 0 , 12 ) &&
V_35 -> V_134 > V_135 )
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
if ( V_35 -> V_133 >= F_59 ( 2 , 0 , 12 ) )
V_6 -> V_134 = V_35 -> V_134 ;
V_6 -> V_119 = V_35 -> V_119 ;
V_6 -> V_120 -> V_121 = V_35 -> V_121 ;
V_6 -> V_122 = V_35 -> V_122 ;
V_6 -> V_123 = V_35 -> V_123 ;
V_6 -> V_124 = V_35 -> V_124 ;
V_6 -> V_125 = V_35 -> V_125 ;
V_35 -> V_126 = V_6 -> V_126 ;
if ( F_60 ( V_3 ) ) {
if ( V_3 -> V_14 == V_136 &&
V_6 -> V_125 > 0 )
F_61 ( V_3 , V_137 ) ;
V_30 = F_62 ( V_3 , V_6 ) ;
}
F_38 ( V_3 ) ;
return V_30 ;
}
static int F_63 ( struct V_2 * V_3 ,
struct F_58 T_2 * V_86 )
{
struct F_58 V_35 ;
int V_30 ;
if ( F_64 ( & V_35 , V_86 , sizeof( V_35 ) ) )
return - V_33 ;
V_30 = F_58 ( V_3 , & V_35 ) ;
if ( F_10 ( V_86 , & V_35 , sizeof( V_35 ) ) )
return - V_33 ;
return V_30 ;
}
int F_65 ( struct V_2 * V_3 ,
struct F_65 * V_91 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_37 ( V_3 ) ;
V_91 -> V_90 = V_6 -> V_91 -> V_90 ;
V_91 -> V_138 = V_6 -> V_91 -> V_138 ;
if ( V_91 -> V_90 == V_95 )
goto V_139;
V_91 -> V_140 = V_6 -> V_140 ;
if ( F_60 ( V_3 ) ) {
F_66 ( V_3 ) ;
if ( V_6 -> V_117 == V_141 ) {
V_91 -> V_142 = V_6 -> V_91 -> V_142 ;
V_91 -> V_143 =
V_6 -> V_91 -> V_143 ;
goto V_144;
}
}
F_67 ( V_6 , & V_91 -> V_142 ) ;
V_144:
V_91 -> V_145 = V_6 -> V_120 -> V_145 ;
V_91 -> V_146 = V_6 -> V_91 -> V_146 ;
if ( V_3 -> V_14 == V_136 ) {
V_91 -> V_147 = F_68 ( V_6 ) ;
if ( V_6 -> V_91 -> V_90 == V_148 ||
V_6 -> V_91 -> V_90 == V_149 ) {
V_91 -> V_150 = V_6 -> V_109 - V_91 -> V_147 ;
V_91 -> V_150 += V_6 -> V_150 ;
} else
V_91 -> V_150 = 0 ;
} else {
V_91 -> V_147 = F_69 ( V_6 ) ;
if ( V_6 -> V_91 -> V_90 == V_148 )
V_91 -> V_150 = V_91 -> V_147 + V_6 -> V_150 ;
else
V_91 -> V_150 = 0 ;
}
V_91 -> V_151 = V_6 -> V_151 ;
V_91 -> V_152 = V_6 -> V_152 ;
V_6 -> V_151 = 0 ;
V_6 -> V_152 = 0 ;
V_139:
F_38 ( V_3 ) ;
return 0 ;
}
static int F_70 ( struct V_2 * V_3 ,
struct F_65 T_2 * V_153 )
{
struct F_65 V_91 ;
int V_154 ;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_154 = F_65 ( V_3 , & V_91 ) ;
if ( V_154 < 0 )
return V_154 ;
if ( F_10 ( V_153 , & V_91 , sizeof( V_91 ) ) )
return - V_33 ;
return 0 ;
}
static int F_71 ( struct V_2 * V_3 ,
struct F_71 * V_4 )
{
struct V_5 * V_6 ;
unsigned int V_155 ;
V_155 = V_4 -> V_155 ;
V_6 = V_3 -> V_6 ;
F_37 ( V_3 ) ;
if ( V_6 -> V_91 -> V_90 == V_95 ) {
F_38 ( V_3 ) ;
return - V_98 ;
}
F_38 ( V_3 ) ;
if ( V_155 >= V_6 -> V_107 )
return - V_62 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_155 = V_155 ;
return V_3 -> V_26 -> V_27 ( V_3 , V_156 , V_4 ) ;
}
static int F_72 ( struct V_2 * V_3 ,
struct F_71 T_2 * V_29 )
{
struct F_71 V_4 ;
int V_154 ;
if ( F_64 ( & V_4 , V_29 , sizeof( V_4 ) ) )
return - V_33 ;
V_154 = F_71 ( V_3 , & V_4 ) ;
if ( V_154 < 0 )
return V_154 ;
if ( F_10 ( V_29 , & V_4 , sizeof( V_4 ) ) )
return - V_33 ;
return 0 ;
}
static void F_73 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_157 == NULL )
return;
if ( V_6 -> V_157 == V_3 ) {
F_67 ( V_6 , & V_6 -> V_140 ) ;
} else {
F_73 ( V_6 -> V_157 ) ;
V_6 -> V_140 = V_6 -> V_157 -> V_6 -> V_140 ;
}
V_6 -> V_157 = NULL ;
}
static int F_74 ( struct V_158 * V_26 ,
struct V_2 * V_3 ,
int V_90 , int V_159 )
{
struct V_2 * V_160 = NULL ;
struct V_2 * V_161 ;
int V_154 = 0 ;
F_75 (s, substream) {
if ( V_159 && V_160 != V_3 )
F_76 ( & V_160 -> V_162 . V_163 ,
V_164 ) ;
V_154 = V_26 -> V_165 ( V_160 , V_90 ) ;
if ( V_154 < 0 )
goto V_166;
}
F_75 (s, substream) {
V_154 = V_26 -> V_167 ( V_160 , V_90 ) ;
if ( V_154 < 0 ) {
if ( V_26 -> V_168 ) {
F_75 (s1, substream) {
if ( V_161 == V_160 )
break;
V_26 -> V_168 ( V_161 , V_90 ) ;
}
}
V_160 = NULL ;
goto V_166;
}
}
F_75 (s, substream) {
V_26 -> V_169 ( V_160 , V_90 ) ;
}
V_166:
if ( V_159 ) {
F_75 (s1, substream) {
if ( V_161 != V_3 )
F_77 ( & V_161 -> V_162 . V_163 ) ;
if ( V_161 == V_160 )
break;
}
}
return V_154 ;
}
static int F_78 ( struct V_158 * V_26 ,
struct V_2 * V_3 ,
int V_90 )
{
int V_154 ;
V_154 = V_26 -> V_165 ( V_3 , V_90 ) ;
if ( V_154 < 0 )
return V_154 ;
V_154 = V_26 -> V_167 ( V_3 , V_90 ) ;
if ( V_154 == 0 )
V_26 -> V_169 ( V_3 , V_90 ) ;
else if ( V_26 -> V_168 )
V_26 -> V_168 ( V_3 , V_90 ) ;
return V_154 ;
}
static int F_79 ( struct V_158 * V_26 ,
struct V_2 * V_3 ,
int V_90 )
{
int V_154 ;
if ( F_80 ( V_3 ) ) {
if ( ! F_81 ( & V_3 -> V_170 -> V_163 ) ) {
F_77 ( & V_3 -> V_162 . V_163 ) ;
F_82 ( & V_3 -> V_170 -> V_163 ) ;
F_82 ( & V_3 -> V_162 . V_163 ) ;
}
V_154 = F_74 ( V_26 , V_3 , V_90 , 1 ) ;
F_77 ( & V_3 -> V_170 -> V_163 ) ;
} else {
V_154 = F_78 ( V_26 , V_3 , V_90 ) ;
}
return V_154 ;
}
static int F_83 ( struct V_158 * V_26 ,
struct V_2 * V_3 ,
int V_90 )
{
int V_154 ;
F_84 ( & V_171 ) ;
if ( F_80 ( V_3 ) ) {
F_82 ( & V_3 -> V_170 -> V_163 ) ;
F_82 ( & V_3 -> V_162 . V_163 ) ;
V_154 = F_74 ( V_26 , V_3 , V_90 , 1 ) ;
F_77 ( & V_3 -> V_162 . V_163 ) ;
F_77 ( & V_3 -> V_170 -> V_163 ) ;
} else {
F_82 ( & V_3 -> V_162 . V_163 ) ;
V_154 = F_78 ( V_26 , V_3 , V_90 ) ;
F_77 ( & V_3 -> V_162 . V_163 ) ;
}
F_85 ( & V_171 ) ;
return V_154 ;
}
static int F_86 ( struct V_158 * V_26 ,
struct V_2 * V_3 ,
int V_90 )
{
int V_154 ;
F_87 ( & V_172 ) ;
if ( F_80 ( V_3 ) )
V_154 = F_74 ( V_26 , V_3 , V_90 , 0 ) ;
else
V_154 = F_78 ( V_26 , V_3 , V_90 ) ;
F_88 ( & V_172 ) ;
return V_154 ;
}
static int F_89 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_91 -> V_90 != V_97 )
return - V_98 ;
if ( V_3 -> V_14 == V_136 &&
! F_90 ( V_3 ) )
return - V_173 ;
V_6 -> V_157 = V_3 ;
return 0 ;
}
static int F_91 ( struct V_2 * V_3 , int V_90 )
{
if ( V_3 -> V_6 -> V_157 != V_3 )
return 0 ;
return V_3 -> V_26 -> V_174 ( V_3 , V_175 ) ;
}
static void F_92 ( struct V_2 * V_3 , int V_90 )
{
if ( V_3 -> V_6 -> V_157 == V_3 )
V_3 -> V_26 -> V_174 ( V_3 , V_176 ) ;
}
static void F_93 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_73 ( V_3 ) ;
V_6 -> V_177 = V_178 ;
V_6 -> V_179 = ( V_6 -> V_109 * V_180 ) /
V_6 -> V_88 ;
V_6 -> V_91 -> V_90 = V_90 ;
if ( V_3 -> V_14 == V_136 &&
V_6 -> V_125 > 0 )
F_61 ( V_3 , V_137 ) ;
if ( V_3 -> V_181 )
F_94 ( V_3 -> V_181 , V_182 ,
& V_6 -> V_140 ) ;
}
int F_95 ( struct V_2 * V_3 )
{
return F_79 ( & V_183 , V_3 ,
V_148 ) ;
}
static int F_96 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_91 -> V_90 == V_95 )
return - V_98 ;
V_6 -> V_157 = V_3 ;
return 0 ;
}
static int F_97 ( struct V_2 * V_3 , int V_90 )
{
if ( V_3 -> V_6 -> V_157 == V_3 &&
F_60 ( V_3 ) )
V_3 -> V_26 -> V_174 ( V_3 , V_176 ) ;
return 0 ;
}
static void F_98 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_91 -> V_90 != V_90 ) {
F_73 ( V_3 ) ;
if ( V_3 -> V_181 )
F_94 ( V_3 -> V_181 , V_184 ,
& V_6 -> V_140 ) ;
V_6 -> V_91 -> V_90 = V_90 ;
}
F_99 ( & V_6 -> V_185 ) ;
F_99 ( & V_6 -> V_186 ) ;
}
int F_100 ( struct V_2 * V_3 , T_4 V_90 )
{
return F_79 ( & V_187 , V_3 , V_90 ) ;
}
int F_101 ( struct V_2 * V_3 )
{
return F_78 ( & V_187 , V_3 ,
V_96 ) ;
}
static int F_102 ( struct V_2 * V_3 , int V_188 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( ! ( V_6 -> V_4 & V_189 ) )
return - V_190 ;
if ( V_188 ) {
if ( V_6 -> V_91 -> V_90 != V_148 )
return - V_98 ;
} else if ( V_6 -> V_91 -> V_90 != V_191 )
return - V_98 ;
V_6 -> V_157 = V_3 ;
return 0 ;
}
static int F_103 ( struct V_2 * V_3 , int V_188 )
{
if ( V_3 -> V_6 -> V_157 != V_3 )
return 0 ;
if ( V_188 )
F_66 ( V_3 ) ;
V_3 -> V_6 -> V_177 = V_178 - V_180 * 1000 ;
return V_3 -> V_26 -> V_174 ( V_3 ,
V_188 ? V_192 :
V_193 ) ;
}
static void F_104 ( struct V_2 * V_3 , int V_188 )
{
if ( V_3 -> V_6 -> V_157 == V_3 )
V_3 -> V_26 -> V_174 ( V_3 ,
V_188 ? V_193 :
V_192 ) ;
}
static void F_105 ( struct V_2 * V_3 , int V_188 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_73 ( V_3 ) ;
if ( V_188 ) {
V_6 -> V_91 -> V_90 = V_191 ;
if ( V_3 -> V_181 )
F_94 ( V_3 -> V_181 ,
V_194 ,
& V_6 -> V_140 ) ;
F_99 ( & V_6 -> V_185 ) ;
F_99 ( & V_6 -> V_186 ) ;
} else {
V_6 -> V_91 -> V_90 = V_148 ;
if ( V_3 -> V_181 )
F_94 ( V_3 -> V_181 ,
V_195 ,
& V_6 -> V_140 ) ;
}
}
static int F_106 ( struct V_2 * V_3 , int V_188 )
{
return F_79 ( & V_196 , V_3 , V_188 ) ;
}
static int F_107 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_91 -> V_90 == V_197 )
return - V_198 ;
V_6 -> V_157 = V_3 ;
return 0 ;
}
static int F_108 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_157 != V_3 )
return 0 ;
if ( ! F_60 ( V_3 ) )
return 0 ;
V_3 -> V_26 -> V_174 ( V_3 , V_199 ) ;
return 0 ;
}
static void F_109 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_73 ( V_3 ) ;
if ( V_3 -> V_181 )
F_94 ( V_3 -> V_181 , V_200 ,
& V_6 -> V_140 ) ;
V_6 -> V_91 -> V_138 = V_6 -> V_91 -> V_90 ;
V_6 -> V_91 -> V_90 = V_197 ;
F_99 ( & V_6 -> V_185 ) ;
F_99 ( & V_6 -> V_186 ) ;
}
int F_110 ( struct V_2 * V_3 )
{
int V_30 ;
unsigned long V_78 ;
if ( ! V_3 )
return 0 ;
F_111 ( V_3 , V_78 ) ;
V_30 = F_79 ( & V_201 , V_3 , 0 ) ;
F_112 ( V_3 , V_78 ) ;
return V_30 ;
}
int F_113 ( struct V_7 * V_8 )
{
struct V_2 * V_3 ;
int V_14 , V_30 = 0 ;
if ( ! V_8 )
return 0 ;
for ( V_14 = 0 ; V_14 < 2 ; V_14 ++ ) {
for ( V_3 = V_8 -> V_202 [ V_14 ] . V_3 ;
V_3 ; V_3 = V_3 -> V_203 ) {
if ( V_3 -> V_6 == NULL )
continue;
V_30 = F_110 ( V_3 ) ;
if ( V_30 < 0 && V_30 != - V_198 )
return V_30 ;
}
}
return 0 ;
}
static int F_114 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( ! ( V_6 -> V_4 & V_204 ) )
return - V_190 ;
V_6 -> V_157 = V_3 ;
return 0 ;
}
static int F_115 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_157 != V_3 )
return 0 ;
if ( V_6 -> V_91 -> V_138 != V_148 &&
( V_6 -> V_91 -> V_138 != V_149 ||
V_3 -> V_14 != V_136 ) )
return 0 ;
return V_3 -> V_26 -> V_174 ( V_3 , V_205 ) ;
}
static void F_116 ( struct V_2 * V_3 , int V_90 )
{
if ( V_3 -> V_6 -> V_157 == V_3 &&
F_60 ( V_3 ) )
V_3 -> V_26 -> V_174 ( V_3 , V_199 ) ;
}
static void F_117 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
F_73 ( V_3 ) ;
if ( V_3 -> V_181 )
F_94 ( V_3 -> V_181 , V_206 ,
& V_6 -> V_140 ) ;
V_6 -> V_91 -> V_90 = V_6 -> V_91 -> V_138 ;
}
static int F_118 ( struct V_2 * V_3 )
{
struct V_207 * V_11 = V_3 -> V_8 -> V_11 ;
int V_154 ;
F_119 ( V_11 ) ;
if ( ( V_154 = F_120 ( V_11 , V_208 ) ) >= 0 )
V_154 = F_83 ( & V_209 , V_3 , 0 ) ;
F_121 ( V_11 ) ;
return V_154 ;
}
static int F_118 ( struct V_2 * V_3 )
{
return - V_190 ;
}
static int F_122 ( struct V_2 * V_3 )
{
struct V_207 * V_11 = V_3 -> V_8 -> V_11 ;
struct V_5 * V_6 = V_3 -> V_6 ;
int V_131 ;
F_119 ( V_11 ) ;
if ( V_6 -> V_91 -> V_90 == V_197 ) {
V_131 = F_120 ( V_11 , V_208 ) ;
if ( V_131 < 0 )
goto V_166;
}
F_37 ( V_3 ) ;
switch ( V_6 -> V_91 -> V_90 ) {
case V_210 :
V_131 = 0 ;
break;
case V_148 :
V_131 = F_100 ( V_3 , V_210 ) ;
break;
default:
V_131 = - V_98 ;
}
F_38 ( V_3 ) ;
V_166:
F_121 ( V_11 ) ;
return V_131 ;
}
static int F_123 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
switch ( V_6 -> V_91 -> V_90 ) {
case V_148 :
case V_97 :
case V_191 :
case V_197 :
return 0 ;
default:
return - V_98 ;
}
}
static int F_124 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_30 = V_3 -> V_26 -> V_27 ( V_3 , V_211 , NULL ) ;
if ( V_30 < 0 )
return V_30 ;
V_6 -> V_212 = 0 ;
V_6 -> V_213 = V_6 -> V_91 -> V_146 -
V_6 -> V_91 -> V_146 % V_6 -> V_89 ;
V_6 -> V_214 = V_6 -> V_91 -> V_146 ;
V_6 -> V_215 = 0 ;
return 0 ;
}
static void F_125 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
V_6 -> V_120 -> V_145 = V_6 -> V_91 -> V_146 ;
if ( V_3 -> V_14 == V_136 &&
V_6 -> V_125 > 0 )
F_61 ( V_3 , V_137 ) ;
}
static int F_126 ( struct V_2 * V_3 )
{
return F_86 ( & V_216 , V_3 , 0 ) ;
}
static int F_127 ( struct V_2 * V_3 ,
int V_217 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_6 -> V_91 -> V_90 == V_95 ||
V_6 -> V_91 -> V_90 == V_92 )
return - V_98 ;
if ( F_60 ( V_3 ) )
return - V_198 ;
V_3 -> V_217 = V_217 ;
return 0 ;
}
static int F_128 ( struct V_2 * V_3 , int V_90 )
{
int V_30 ;
V_30 = V_3 -> V_26 -> V_218 ( V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
return F_124 ( V_3 , 0 ) ;
}
static void F_129 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
V_6 -> V_120 -> V_145 = V_6 -> V_91 -> V_146 ;
F_36 ( V_3 , V_97 ) ;
}
static int F_130 ( struct V_2 * V_3 ,
struct V_219 * V_219 )
{
int V_154 ;
struct V_207 * V_11 = V_3 -> V_8 -> V_11 ;
int V_217 ;
if ( V_219 )
V_217 = V_219 -> V_217 ;
else
V_217 = V_3 -> V_217 ;
F_119 ( V_11 ) ;
if ( ( V_154 = F_120 ( V_11 , V_208 ) ) >= 0 )
V_154 = F_86 ( & V_220 ,
V_3 , V_217 ) ;
F_121 ( V_11 ) ;
return V_154 ;
}
static int F_131 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
switch ( V_6 -> V_91 -> V_90 ) {
case V_95 :
case V_92 :
case V_197 :
return - V_98 ;
}
V_6 -> V_157 = V_3 ;
return 0 ;
}
static int F_132 ( struct V_2 * V_3 , int V_90 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_3 -> V_14 == V_136 ) {
switch ( V_6 -> V_91 -> V_90 ) {
case V_97 :
if ( ! F_133 ( V_3 ) ) {
F_91 ( V_3 , V_149 ) ;
F_93 ( V_3 , V_149 ) ;
}
break;
case V_148 :
V_6 -> V_91 -> V_90 = V_149 ;
break;
case V_210 :
V_6 -> V_91 -> V_90 = V_96 ;
break;
default:
break;
}
} else {
if ( V_6 -> V_91 -> V_90 == V_148 ) {
int V_221 = F_69 ( V_6 ) > 0 ?
V_149 : V_96 ;
F_97 ( V_3 , V_221 ) ;
F_98 ( V_3 , V_221 ) ;
}
}
return 0 ;
}
static void F_134 ( struct V_2 * V_3 , int V_90 )
{
}
static int F_135 ( struct V_2 * V_3 ,
struct V_219 * V_219 )
{
struct V_207 * V_11 ;
struct V_5 * V_6 ;
struct V_2 * V_160 ;
T_5 V_222 ;
int V_131 = 0 ;
int V_223 = 0 ;
V_11 = V_3 -> V_8 -> V_11 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_91 -> V_90 == V_95 )
return - V_98 ;
F_119 ( V_11 ) ;
if ( V_6 -> V_91 -> V_90 == V_197 ) {
V_131 = F_120 ( V_11 , V_208 ) ;
if ( V_131 < 0 ) {
F_121 ( V_11 ) ;
return V_131 ;
}
}
if ( V_219 ) {
if ( V_219 -> V_217 & V_224 )
V_223 = 1 ;
} else if ( V_3 -> V_217 & V_224 )
V_223 = 1 ;
F_87 ( & V_172 ) ;
F_37 ( V_3 ) ;
if ( V_6 -> V_91 -> V_90 == V_191 )
F_106 ( V_3 , 0 ) ;
V_131 = F_79 ( & V_225 , V_3 , 0 ) ;
if ( V_131 < 0 )
goto V_226;
if ( V_223 ) {
V_131 = - V_227 ;
goto V_226;
}
for (; ; ) {
long V_228 ;
struct V_5 * V_229 ;
if ( F_136 ( V_230 ) ) {
V_131 = - V_231 ;
break;
}
V_229 = NULL ;
F_75 (s, substream) {
if ( V_160 -> V_14 != V_136 )
continue;
V_6 = V_160 -> V_6 ;
if ( V_6 -> V_91 -> V_90 == V_149 ) {
V_229 = V_6 ;
break;
}
}
if ( ! V_229 )
break;
F_137 ( & V_222 , V_230 ) ;
F_138 ( & V_229 -> V_185 , & V_222 ) ;
F_38 ( V_3 ) ;
F_88 ( & V_172 ) ;
F_121 ( V_11 ) ;
if ( V_6 -> V_110 )
V_228 = V_232 ;
else {
V_228 = 10 ;
if ( V_6 -> V_88 ) {
long V_233 = V_6 -> V_89 * 2 / V_6 -> V_88 ;
V_228 = V_70 ( V_233 , V_228 ) ;
}
V_228 = F_139 ( V_228 * 1000 ) ;
}
V_228 = F_140 ( V_228 ) ;
F_119 ( V_11 ) ;
F_87 ( & V_172 ) ;
F_37 ( V_3 ) ;
F_141 ( & V_229 -> V_185 , & V_222 ) ;
if ( V_11 -> V_234 ) {
V_131 = - V_235 ;
break;
}
if ( V_228 == 0 ) {
if ( V_3 -> V_6 -> V_91 -> V_90 == V_197 )
V_131 = - V_236 ;
else {
F_142 ( V_3 -> V_8 -> V_11 -> V_237 ,
L_12 ) ;
F_100 ( V_3 , V_96 ) ;
V_131 = - V_238 ;
}
break;
}
}
V_226:
F_38 ( V_3 ) ;
F_88 ( & V_172 ) ;
F_121 ( V_11 ) ;
return V_131 ;
}
static int F_143 ( struct V_2 * V_3 )
{
struct V_5 * V_6 ;
int V_131 = 0 ;
if ( F_39 ( V_3 ) )
return - V_94 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_91 -> V_90 == V_95 ||
V_6 -> V_91 -> V_90 == V_92 ||
V_6 -> V_91 -> V_90 == V_197 )
return - V_98 ;
F_37 ( V_3 ) ;
if ( V_6 -> V_91 -> V_90 == V_191 )
F_106 ( V_3 , 0 ) ;
F_100 ( V_3 , V_96 ) ;
F_38 ( V_3 ) ;
return V_131 ;
}
static bool F_144 ( struct V_219 * V_219 )
{
struct V_239 * V_239 = F_145 ( V_219 ) ;
unsigned int V_240 ;
if ( ! F_146 ( V_239 -> V_241 ) || F_147 ( V_239 ) != V_242 )
return false ;
V_240 = F_148 ( V_239 ) ;
return F_149 ( V_240 , V_243 ) ||
F_149 ( V_240 , V_244 ) ;
}
static int F_150 ( struct V_2 * V_3 , int V_245 )
{
int V_154 = 0 ;
struct V_246 * V_247 ;
struct V_2 * V_248 ;
struct V_249 * V_170 ;
struct V_245 V_250 = F_151 ( V_245 ) ;
if ( ! V_250 . V_219 )
return - V_98 ;
if ( ! F_144 ( V_250 . V_219 ) ) {
V_154 = - V_98 ;
goto V_251;
}
V_247 = V_250 . V_219 -> V_252 ;
V_248 = V_247 -> V_3 ;
V_170 = F_9 ( sizeof( * V_170 ) , V_31 ) ;
if ( ! V_170 ) {
V_154 = - V_32 ;
goto V_253;
}
F_152 ( & V_172 ) ;
F_153 ( & V_171 ) ;
if ( V_3 -> V_6 -> V_91 -> V_90 == V_95 ||
V_3 -> V_6 -> V_91 -> V_90 != V_248 -> V_6 -> V_91 -> V_90 ) {
V_154 = - V_98 ;
goto V_139;
}
if ( F_80 ( V_248 ) ) {
V_154 = - V_254 ;
goto V_139;
}
if ( ! F_80 ( V_3 ) ) {
V_3 -> V_170 = V_170 ;
V_170 = NULL ;
F_154 ( & V_3 -> V_170 -> V_163 ) ;
F_155 ( & V_3 -> V_170 -> V_255 ) ;
F_156 ( & V_3 -> V_256 , & V_3 -> V_170 -> V_255 ) ;
V_3 -> V_170 -> V_257 = 1 ;
}
F_156 ( & V_248 -> V_256 , & V_3 -> V_170 -> V_255 ) ;
V_3 -> V_170 -> V_257 ++ ;
V_248 -> V_170 = V_3 -> V_170 ;
V_139:
F_157 ( & V_171 ) ;
F_158 ( & V_172 ) ;
V_253:
F_159 ( V_248 -> V_8 -> V_11 ) ;
F_11 ( V_170 ) ;
V_251:
F_160 ( V_250 ) ;
return V_154 ;
}
static void F_161 ( struct V_2 * V_3 )
{
V_3 -> V_170 = & V_3 -> V_162 ;
F_155 ( & V_3 -> V_162 . V_255 ) ;
F_156 ( & V_3 -> V_256 , & V_3 -> V_162 . V_255 ) ;
}
static int F_162 ( struct V_2 * V_3 )
{
struct V_2 * V_160 ;
int V_154 = 0 ;
F_152 ( & V_172 ) ;
F_153 ( & V_171 ) ;
if ( ! F_80 ( V_3 ) ) {
V_154 = - V_254 ;
goto V_139;
}
F_163 ( & V_3 -> V_256 ) ;
V_3 -> V_170 -> V_257 -- ;
if ( V_3 -> V_170 -> V_257 == 1 ) {
F_75 (s, substream) {
F_161 ( V_160 ) ;
break;
}
F_11 ( V_3 -> V_170 ) ;
}
F_161 ( V_3 ) ;
V_139:
F_157 ( & V_171 ) ;
F_158 ( & V_172 ) ;
return V_154 ;
}
static int F_164 ( struct V_34 * V_35 ,
struct V_72 * V_258 )
{
struct V_39 V_233 ;
F_165 ( F_166 ( V_35 , V_258 -> V_79 [ 0 ] ) ,
F_166 ( V_35 , V_258 -> V_79 [ 1 ] ) , & V_233 ) ;
return F_22 ( F_20 ( V_35 , V_258 -> V_81 ) , & V_233 ) ;
}
static int F_167 ( struct V_34 * V_35 ,
struct V_72 * V_258 )
{
struct V_39 V_233 ;
F_168 ( F_166 ( V_35 , V_258 -> V_79 [ 0 ] ) ,
F_166 ( V_35 , V_258 -> V_79 [ 1 ] ) , & V_233 ) ;
return F_22 ( F_20 ( V_35 , V_258 -> V_81 ) , & V_233 ) ;
}
static int F_169 ( struct V_34 * V_35 ,
struct V_72 * V_258 )
{
struct V_39 V_233 ;
F_170 ( F_166 ( V_35 , V_258 -> V_79 [ 0 ] ) ,
F_166 ( V_35 , V_258 -> V_79 [ 1 ] ) ,
( unsigned long ) V_258 -> V_259 , & V_233 ) ;
return F_22 ( F_20 ( V_35 , V_258 -> V_81 ) , & V_233 ) ;
}
static int F_171 ( struct V_34 * V_35 ,
struct V_72 * V_258 )
{
struct V_39 V_233 ;
F_172 ( F_166 ( V_35 , V_258 -> V_79 [ 0 ] ) ,
( unsigned long ) V_258 -> V_259 ,
F_166 ( V_35 , V_258 -> V_79 [ 1 ] ) , & V_233 ) ;
return F_22 ( F_20 ( V_35 , V_258 -> V_81 ) , & V_233 ) ;
}
static int F_173 ( struct V_34 * V_35 ,
struct V_72 * V_258 )
{
unsigned int V_36 ;
struct V_39 * V_40 = F_20 ( V_35 , V_258 -> V_79 [ 0 ] ) ;
struct V_41 V_42 ;
struct V_41 * V_260 = F_13 ( V_35 , V_83 ) ;
F_174 ( & V_42 ) ;
for ( V_36 = 0 ; V_36 <= V_261 ; ++ V_36 ) {
int V_64 ;
if ( ! F_175 ( V_260 , V_36 ) )
continue;
V_64 = F_51 ( V_36 ) ;
if ( V_64 <= 0 )
continue;
if ( ( unsigned ) V_64 < V_40 -> V_69 || ( unsigned ) V_64 > V_40 -> V_70 )
F_176 ( & V_42 , V_36 ) ;
}
return F_18 ( V_260 , & V_42 ) ;
}
static int F_177 ( struct V_34 * V_35 ,
struct V_72 * V_258 )
{
struct V_39 V_233 ;
unsigned int V_36 ;
V_233 . V_69 = V_262 ;
V_233 . V_70 = 0 ;
V_233 . V_68 = 0 ;
V_233 . V_71 = 0 ;
for ( V_36 = 0 ; V_36 <= V_261 ; ++ V_36 ) {
int V_64 ;
if ( ! F_175 ( F_13 ( V_35 , V_83 ) , V_36 ) )
continue;
V_64 = F_51 ( V_36 ) ;
if ( V_64 <= 0 )
continue;
if ( V_233 . V_69 > ( unsigned ) V_64 )
V_233 . V_69 = V_64 ;
if ( V_233 . V_70 < ( unsigned ) V_64 )
V_233 . V_70 = V_64 ;
}
V_233 . integer = 1 ;
return F_22 ( F_20 ( V_35 , V_258 -> V_81 ) , & V_233 ) ;
}
static int F_178 ( struct V_34 * V_35 ,
struct V_72 * V_258 )
{
struct V_37 * V_38 = V_258 -> V_259 ;
return F_179 ( F_20 ( V_35 , V_258 -> V_81 ) ,
V_263 . V_257 ,
V_263 . V_264 , V_38 -> V_265 ) ;
}
static int F_180 ( struct V_34 * V_35 ,
struct V_72 * V_258 )
{
struct V_39 V_233 ;
struct V_2 * V_3 = V_258 -> V_259 ;
V_233 . V_69 = 0 ;
V_233 . V_70 = V_3 -> V_266 ;
V_233 . V_68 = 0 ;
V_233 . V_71 = 0 ;
V_233 . integer = 1 ;
return F_22 ( F_20 ( V_35 , V_258 -> V_81 ) , & V_233 ) ;
}
int F_181 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_43 * V_44 = & V_6 -> V_45 ;
int V_36 , V_30 ;
for ( V_36 = V_60 ; V_36 <= V_61 ; V_36 ++ ) {
F_174 ( F_19 ( V_44 , V_36 ) ) ;
}
for ( V_36 = V_66 ; V_36 <= V_49 ; V_36 ++ ) {
F_182 ( F_23 ( V_44 , V_36 ) ) ;
}
F_183 ( F_23 ( V_44 , V_84 ) ) ;
F_183 ( F_23 ( V_44 , V_267 ) ) ;
F_183 ( F_23 ( V_44 , V_268 ) ) ;
F_183 ( F_23 ( V_44 , V_55 ) ) ;
F_183 ( F_23 ( V_44 , V_269 ) ) ;
V_30 = F_184 ( V_6 , 0 , V_83 ,
F_173 , NULL ,
V_55 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_184 ( V_6 , 0 , V_55 ,
F_177 , NULL ,
V_83 ,
V_55 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_184 ( V_6 , 0 , V_55 ,
F_167 , NULL ,
V_269 , V_84 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_184 ( V_6 , 0 , V_269 ,
F_164 , NULL ,
V_55 , V_84 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_184 ( V_6 , 0 , V_269 ,
F_171 , ( void * ) 8 ,
V_270 , V_271 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_184 ( V_6 , 0 , V_269 ,
F_171 , ( void * ) 8 ,
V_268 , V_267 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_184 ( V_6 , 0 , V_84 ,
F_167 , NULL ,
V_269 , V_55 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_184 ( V_6 , 0 , V_57 ,
F_171 , ( void * ) 1000000 ,
V_271 , V_272 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_184 ( V_6 , 0 , V_57 ,
F_171 , ( void * ) 1000000 ,
V_267 , V_273 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_184 ( V_6 , 0 , V_274 ,
F_167 , NULL ,
V_267 , V_271 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_184 ( V_6 , 0 , V_271 ,
F_167 , NULL ,
V_267 , V_274 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_184 ( V_6 , 0 , V_271 ,
F_171 , ( void * ) 8 ,
V_270 , V_269 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_184 ( V_6 , 0 , V_271 ,
F_169 , ( void * ) 1000000 ,
V_272 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_184 ( V_6 , 0 , V_267 ,
F_164 , NULL ,
V_271 , V_274 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_184 ( V_6 , 0 , V_267 ,
F_171 , ( void * ) 8 ,
V_268 , V_269 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_184 ( V_6 , 0 , V_267 ,
F_169 , ( void * ) 1000000 ,
V_273 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_184 ( V_6 , 0 , V_270 ,
F_169 , ( void * ) 8 ,
V_271 , V_269 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_184 ( V_6 , 0 , V_268 ,
F_169 , ( void * ) 8 ,
V_267 , V_269 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_184 ( V_6 , 0 , V_272 ,
F_171 , ( void * ) 1000000 ,
V_271 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_184 ( V_6 , 0 , V_273 ,
F_171 , ( void * ) 1000000 ,
V_267 , V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
return 0 ;
}
int F_185 ( struct V_2 * V_3 )
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
V_30 = F_186 ( V_6 , V_284 , V_260 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_187 ( V_6 , V_83 , V_38 -> V_285 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_186 ( V_6 , V_286 , 1 << V_287 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_188 ( V_6 , V_84 ,
V_38 -> V_288 , V_38 -> V_289 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_188 ( V_6 , V_57 ,
V_38 -> V_290 , V_38 -> V_291 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_188 ( V_6 , V_270 ,
V_38 -> V_292 , V_38 -> V_293 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_188 ( V_6 , V_274 ,
V_38 -> V_294 , V_38 -> V_295 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_188 ( V_6 , V_268 ,
V_38 -> V_292 , V_38 -> V_266 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_184 ( V_6 , 0 , V_268 ,
F_180 , V_3 ,
V_268 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_6 -> V_296 ) {
V_30 = F_188 ( V_6 , V_268 , 0 , V_6 -> V_296 ) ;
if ( V_30 < 0 )
return V_30 ;
}
if ( ! ( V_38 -> V_265 & ( V_297 | V_298 ) ) ) {
V_30 = F_184 ( V_6 , 0 , V_57 ,
F_178 , V_38 ,
V_57 , - 1 ) ;
if ( V_30 < 0 )
return V_30 ;
}
F_189 ( V_6 , V_271 ) ;
return 0 ;
}
static void F_190 ( struct V_2 * V_3 )
{
F_162 ( V_3 ) ;
}
void F_191 ( struct V_2 * V_3 )
{
V_3 -> V_299 -- ;
if ( V_3 -> V_299 > 0 )
return;
F_143 ( V_3 ) ;
if ( V_3 -> V_300 ) {
if ( V_3 -> V_26 -> V_130 != NULL )
V_3 -> V_26 -> V_130 ( V_3 ) ;
V_3 -> V_26 -> V_301 ( V_3 ) ;
V_3 -> V_300 = 0 ;
}
if ( F_53 ( & V_3 -> V_128 ) )
F_54 ( & V_3 -> V_128 ) ;
if ( V_3 -> V_302 ) {
V_3 -> V_302 ( V_3 ) ;
V_3 -> V_302 = NULL ;
}
F_192 ( V_3 ) ;
}
int F_193 ( struct V_7 * V_8 , int V_14 ,
struct V_219 * V_219 ,
struct V_2 * * V_303 )
{
struct V_2 * V_3 ;
int V_30 ;
V_30 = F_194 ( V_8 , V_14 , V_219 , & V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_3 -> V_299 > 1 ) {
* V_303 = V_3 ;
return 0 ;
}
V_30 = F_181 ( V_3 ) ;
if ( V_30 < 0 ) {
F_195 ( V_8 , L_13 ) ;
goto error;
}
if ( ( V_30 = V_3 -> V_26 -> V_304 ( V_3 ) ) < 0 )
goto error;
V_3 -> V_300 = 1 ;
V_30 = F_185 ( V_3 ) ;
if ( V_30 < 0 ) {
F_195 ( V_8 , L_14 ) ;
goto error;
}
* V_303 = V_3 ;
return 0 ;
error:
F_191 ( V_3 ) ;
return V_30 ;
}
static int F_196 ( struct V_219 * V_219 ,
struct V_7 * V_8 ,
int V_14 )
{
struct V_246 * V_247 ;
struct V_2 * V_3 ;
int V_30 ;
V_30 = F_193 ( V_8 , V_14 , V_219 , & V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
V_247 = F_197 ( sizeof( * V_247 ) , V_31 ) ;
if ( V_247 == NULL ) {
F_191 ( V_3 ) ;
return - V_32 ;
}
V_247 -> V_3 = V_3 ;
if ( V_3 -> V_299 == 1 ) {
V_3 -> V_219 = V_247 ;
V_3 -> V_302 = F_190 ;
}
V_219 -> V_252 = V_247 ;
return 0 ;
}
static int F_198 ( struct V_239 * V_239 , struct V_219 * V_219 )
{
struct V_7 * V_8 ;
int V_30 = F_199 ( V_239 , V_219 ) ;
if ( V_30 < 0 )
return V_30 ;
V_8 = F_149 ( F_148 ( V_239 ) ,
V_243 ) ;
V_30 = F_200 ( V_219 , V_8 , V_136 ) ;
if ( V_8 )
F_159 ( V_8 -> V_11 ) ;
return V_30 ;
}
static int F_201 ( struct V_239 * V_239 , struct V_219 * V_219 )
{
struct V_7 * V_8 ;
int V_30 = F_199 ( V_239 , V_219 ) ;
if ( V_30 < 0 )
return V_30 ;
V_8 = F_149 ( F_148 ( V_239 ) ,
V_244 ) ;
V_30 = F_200 ( V_219 , V_8 , V_305 ) ;
if ( V_8 )
F_159 ( V_8 -> V_11 ) ;
return V_30 ;
}
static int F_200 ( struct V_219 * V_219 , struct V_7 * V_8 , int V_14 )
{
int V_30 ;
T_5 V_222 ;
if ( V_8 == NULL ) {
V_30 = - V_235 ;
goto V_306;
}
V_30 = F_202 ( V_8 -> V_11 , V_219 ) ;
if ( V_30 < 0 )
goto V_306;
if ( ! F_203 ( V_8 -> V_11 -> V_307 ) ) {
V_30 = - V_33 ;
goto V_308;
}
F_137 ( & V_222 , V_230 ) ;
F_138 ( & V_8 -> V_309 , & V_222 ) ;
F_204 ( & V_8 -> V_310 ) ;
while ( 1 ) {
V_30 = F_196 ( V_219 , V_8 , V_14 ) ;
if ( V_30 >= 0 )
break;
if ( V_30 == - V_227 ) {
if ( V_219 -> V_217 & V_224 ) {
V_30 = - V_198 ;
break;
}
} else
break;
F_205 ( V_311 ) ;
F_206 ( & V_8 -> V_310 ) ;
F_207 () ;
F_204 ( & V_8 -> V_310 ) ;
if ( V_8 -> V_11 -> V_234 ) {
V_30 = - V_235 ;
break;
}
if ( F_136 ( V_230 ) ) {
V_30 = - V_231 ;
break;
}
}
F_141 ( & V_8 -> V_309 , & V_222 ) ;
F_206 ( & V_8 -> V_310 ) ;
if ( V_30 < 0 )
goto V_312;
return V_30 ;
V_312:
F_208 ( V_8 -> V_11 -> V_307 ) ;
V_308:
F_209 ( V_8 -> V_11 , V_219 ) ;
V_306:
return V_30 ;
}
static int F_210 ( struct V_239 * V_239 , struct V_219 * V_219 )
{
struct V_7 * V_8 ;
struct V_2 * V_3 ;
struct V_246 * V_247 ;
V_247 = V_219 -> V_252 ;
V_3 = V_247 -> V_3 ;
if ( F_211 ( ! V_3 ) )
return - V_94 ;
V_8 = V_3 -> V_8 ;
F_204 ( & V_8 -> V_310 ) ;
F_191 ( V_3 ) ;
F_11 ( V_247 ) ;
F_206 ( & V_8 -> V_310 ) ;
F_99 ( & V_8 -> V_309 ) ;
F_208 ( V_8 -> V_11 -> V_307 ) ;
F_209 ( V_8 -> V_11 , V_219 ) ;
return 0 ;
}
static T_6 F_212 ( struct V_2 * V_3 ,
T_3 V_93 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_145 ;
T_6 V_313 ;
T_6 V_314 ;
if ( V_93 == 0 )
return 0 ;
F_37 ( V_3 ) ;
switch ( V_6 -> V_91 -> V_90 ) {
case V_97 :
break;
case V_149 :
case V_148 :
if ( F_66 ( V_3 ) >= 0 )
break;
case V_210 :
V_313 = - V_173 ;
goto V_315;
case V_197 :
V_313 = - V_236 ;
goto V_315;
default:
V_313 = - V_98 ;
goto V_315;
}
V_314 = F_213 ( V_6 ) ;
if ( V_314 <= 0 ) {
V_313 = 0 ;
goto V_315;
}
if ( V_93 > ( T_3 ) V_314 )
V_93 = V_314 ;
V_145 = V_6 -> V_120 -> V_145 - V_93 ;
if ( V_145 < 0 )
V_145 += V_6 -> V_126 ;
V_6 -> V_120 -> V_145 = V_145 ;
V_313 = V_93 ;
V_315:
F_38 ( V_3 ) ;
return V_313 ;
}
static T_6 F_214 ( struct V_2 * V_3 ,
T_3 V_93 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_145 ;
T_6 V_313 ;
T_6 V_314 ;
if ( V_93 == 0 )
return 0 ;
F_37 ( V_3 ) ;
switch ( V_6 -> V_91 -> V_90 ) {
case V_97 :
case V_149 :
break;
case V_148 :
if ( F_66 ( V_3 ) >= 0 )
break;
case V_210 :
V_313 = - V_173 ;
goto V_315;
case V_197 :
V_313 = - V_236 ;
goto V_315;
default:
V_313 = - V_98 ;
goto V_315;
}
V_314 = F_215 ( V_6 ) ;
if ( V_314 <= 0 ) {
V_313 = 0 ;
goto V_315;
}
if ( V_93 > ( T_3 ) V_314 )
V_93 = V_314 ;
V_145 = V_6 -> V_120 -> V_145 - V_93 ;
if ( V_145 < 0 )
V_145 += V_6 -> V_126 ;
V_6 -> V_120 -> V_145 = V_145 ;
V_313 = V_93 ;
V_315:
F_38 ( V_3 ) ;
return V_313 ;
}
static T_6 F_216 ( struct V_2 * V_3 ,
T_3 V_93 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_145 ;
T_6 V_313 ;
T_6 V_147 ;
if ( V_93 == 0 )
return 0 ;
F_37 ( V_3 ) ;
switch ( V_6 -> V_91 -> V_90 ) {
case V_97 :
case V_191 :
break;
case V_149 :
case V_148 :
if ( F_66 ( V_3 ) >= 0 )
break;
case V_210 :
V_313 = - V_173 ;
goto V_315;
case V_197 :
V_313 = - V_236 ;
goto V_315;
default:
V_313 = - V_98 ;
goto V_315;
}
V_147 = F_68 ( V_6 ) ;
if ( V_147 <= 0 ) {
V_313 = 0 ;
goto V_315;
}
if ( V_93 > ( T_3 ) V_147 )
V_93 = V_147 ;
V_145 = V_6 -> V_120 -> V_145 + V_93 ;
if ( V_145 >= ( T_6 ) V_6 -> V_126 )
V_145 -= V_6 -> V_126 ;
V_6 -> V_120 -> V_145 = V_145 ;
V_313 = V_93 ;
V_315:
F_38 ( V_3 ) ;
return V_313 ;
}
static T_6 F_217 ( struct V_2 * V_3 ,
T_3 V_93 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_145 ;
T_6 V_313 ;
T_6 V_147 ;
if ( V_93 == 0 )
return 0 ;
F_37 ( V_3 ) ;
switch ( V_6 -> V_91 -> V_90 ) {
case V_97 :
case V_149 :
case V_191 :
break;
case V_148 :
if ( F_66 ( V_3 ) >= 0 )
break;
case V_210 :
V_313 = - V_173 ;
goto V_315;
case V_197 :
V_313 = - V_236 ;
goto V_315;
default:
V_313 = - V_98 ;
goto V_315;
}
V_147 = F_69 ( V_6 ) ;
if ( V_147 <= 0 ) {
V_313 = 0 ;
goto V_315;
}
if ( V_93 > ( T_3 ) V_147 )
V_93 = V_147 ;
V_145 = V_6 -> V_120 -> V_145 + V_93 ;
if ( V_145 >= ( T_6 ) V_6 -> V_126 )
V_145 -= V_6 -> V_126 ;
V_6 -> V_120 -> V_145 = V_145 ;
V_313 = V_93 ;
V_315:
F_38 ( V_3 ) ;
return V_313 ;
}
static int F_218 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_30 ;
F_37 ( V_3 ) ;
switch ( V_6 -> V_91 -> V_90 ) {
case V_149 :
if ( V_3 -> V_14 == V_305 )
goto V_316;
case V_148 :
if ( ( V_30 = F_66 ( V_3 ) ) < 0 )
break;
case V_97 :
case V_197 :
V_30 = 0 ;
break;
case V_210 :
V_30 = - V_173 ;
break;
default:
V_316:
V_30 = - V_98 ;
break;
}
F_38 ( V_3 ) ;
return V_30 ;
}
static int F_219 ( struct V_2 * V_3 ,
T_6 T_2 * V_154 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_30 ;
T_6 V_317 = 0 ;
F_37 ( V_3 ) ;
switch ( V_6 -> V_91 -> V_90 ) {
case V_149 :
if ( V_3 -> V_14 == V_305 )
goto V_316;
case V_148 :
if ( ( V_30 = F_66 ( V_3 ) ) < 0 )
break;
case V_97 :
case V_197 :
V_30 = 0 ;
if ( V_3 -> V_14 == V_136 )
V_317 = F_213 ( V_6 ) ;
else
V_317 = F_69 ( V_6 ) ;
V_317 += V_6 -> V_150 ;
break;
case V_210 :
V_30 = - V_173 ;
break;
default:
V_316:
V_30 = - V_98 ;
break;
}
F_38 ( V_3 ) ;
if ( ! V_30 )
if ( F_220 ( V_317 , V_154 ) )
V_30 = - V_33 ;
return V_30 ;
}
static int F_221 ( struct V_2 * V_3 ,
struct F_221 T_2 * V_318 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct F_221 V_319 ;
volatile struct V_320 * V_91 ;
volatile struct V_321 * V_120 ;
int V_30 ;
memset ( & V_319 , 0 , sizeof( V_319 ) ) ;
if ( F_222 ( V_319 . V_78 , ( unsigned T_2 * ) & ( V_318 -> V_78 ) ) )
return - V_33 ;
if ( F_64 ( & V_319 . V_322 . V_120 , & ( V_318 -> V_322 . V_120 ) , sizeof( struct V_321 ) ) )
return - V_33 ;
V_91 = V_6 -> V_91 ;
V_120 = V_6 -> V_120 ;
if ( V_319 . V_78 & V_323 ) {
V_30 = F_218 ( V_3 ) ;
if ( V_30 < 0 )
return V_30 ;
}
F_37 ( V_3 ) ;
if ( ! ( V_319 . V_78 & V_324 ) )
V_120 -> V_145 = V_319 . V_322 . V_120 . V_145 ;
else
V_319 . V_322 . V_120 . V_145 = V_120 -> V_145 ;
if ( ! ( V_319 . V_78 & V_325 ) )
V_120 -> V_121 = V_319 . V_322 . V_120 . V_121 ;
else
V_319 . V_322 . V_120 . V_121 = V_120 -> V_121 ;
V_319 . V_160 . V_91 . V_90 = V_91 -> V_90 ;
V_319 . V_160 . V_91 . V_146 = V_91 -> V_146 ;
V_319 . V_160 . V_91 . V_142 = V_91 -> V_142 ;
V_319 . V_160 . V_91 . V_138 = V_91 -> V_138 ;
F_38 ( V_3 ) ;
if ( F_10 ( V_318 , & V_319 , sizeof( V_319 ) ) )
return - V_33 ;
return 0 ;
}
static int F_223 ( struct V_2 * V_3 , int T_2 * V_326 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_327 ;
if ( F_222 ( V_327 , V_326 ) )
return - V_33 ;
if ( V_327 < 0 || V_327 > V_135 )
return - V_62 ;
V_6 -> V_134 = V_327 ;
return 0 ;
}
static int F_224 ( struct V_219 * V_219 ,
struct V_2 * V_3 ,
unsigned int V_328 , void T_2 * V_327 )
{
switch ( V_328 ) {
case V_329 :
return F_220 ( V_330 , ( int T_2 * ) V_327 ) ? - V_33 : 0 ;
case V_331 :
return F_8 ( V_3 , V_327 ) ;
case V_332 :
return 0 ;
case V_333 :
return F_223 ( V_3 , V_327 ) ;
case V_334 :
return F_31 ( V_3 , V_327 ) ;
case V_335 :
return F_56 ( V_3 , V_327 ) ;
case V_336 :
return F_57 ( V_3 ) ;
case V_337 :
return F_63 ( V_3 , V_327 ) ;
case V_338 :
return F_70 ( V_3 , V_327 ) ;
case V_339 :
return F_72 ( V_3 , V_327 ) ;
case V_340 :
return F_130 ( V_3 , V_219 ) ;
case V_341 :
return F_126 ( V_3 ) ;
case V_342 :
return F_83 ( & V_183 , V_3 , V_148 ) ;
case V_343 :
return F_150 ( V_3 , ( int ) ( unsigned long ) V_327 ) ;
case V_344 :
return F_162 ( V_3 ) ;
case V_345 :
return F_118 ( V_3 ) ;
case V_346 :
return F_122 ( V_3 ) ;
case V_347 :
return F_218 ( V_3 ) ;
case V_348 :
return F_219 ( V_3 , V_327 ) ;
case V_349 :
return F_221 ( V_3 , V_327 ) ;
#ifdef F_225
case V_350 :
return F_226 ( V_3 , V_327 ) ;
case V_351 :
return F_227 ( V_3 , V_327 ) ;
#endif
case V_352 :
return F_135 ( V_3 , V_219 ) ;
case V_353 :
return F_143 ( V_3 ) ;
case V_354 :
{
int V_154 ;
F_37 ( V_3 ) ;
V_154 = F_106 ( V_3 , ( int ) ( unsigned long ) V_327 ) ;
F_38 ( V_3 ) ;
return V_154 ;
}
}
F_195 ( V_3 -> V_8 , L_15 , V_328 ) ;
return - V_355 ;
}
static int F_228 ( struct V_219 * V_219 ,
struct V_2 * V_3 ,
unsigned int V_328 , void T_2 * V_327 )
{
if ( F_211 ( ! V_3 ) )
return - V_94 ;
if ( F_211 ( V_3 -> V_14 != V_136 ) )
return - V_62 ;
switch ( V_328 ) {
case V_356 :
{
struct V_357 V_358 ;
struct V_357 T_2 * V_359 = V_327 ;
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_131 ;
if ( V_6 -> V_91 -> V_90 == V_95 )
return - V_98 ;
if ( F_220 ( 0 , & V_359 -> V_131 ) )
return - V_33 ;
if ( F_64 ( & V_358 , V_359 , sizeof( V_358 ) ) )
return - V_33 ;
V_131 = F_229 ( V_3 , V_358 . V_360 , V_358 . V_93 ) ;
F_230 ( V_131 , & V_359 -> V_131 ) ;
return V_131 < 0 ? V_131 : 0 ;
}
case V_361 :
{
struct V_362 V_363 ;
struct V_362 T_2 * V_364 = V_327 ;
struct V_5 * V_6 = V_3 -> V_6 ;
void T_2 * * V_365 ;
T_6 V_131 ;
if ( V_6 -> V_91 -> V_90 == V_95 )
return - V_98 ;
if ( V_6 -> V_107 > 128 )
return - V_62 ;
if ( F_220 ( 0 , & V_364 -> V_131 ) )
return - V_33 ;
if ( F_64 ( & V_363 , V_364 , sizeof( V_363 ) ) )
return - V_33 ;
V_365 = F_32 ( V_363 . V_365 ,
sizeof( void * ) * V_6 -> V_107 ) ;
if ( F_33 ( V_365 ) )
return F_34 ( V_365 ) ;
V_131 = F_231 ( V_3 , V_365 , V_363 . V_93 ) ;
F_11 ( V_365 ) ;
F_230 ( V_131 , & V_364 -> V_131 ) ;
return V_131 < 0 ? V_131 : 0 ;
}
case V_366 :
{
T_3 V_93 ;
T_3 T_2 * V_367 = V_327 ;
T_6 V_131 ;
if ( F_222 ( V_93 , V_367 ) )
return - V_33 ;
if ( F_220 ( 0 , V_367 ) )
return - V_33 ;
V_131 = F_212 ( V_3 , V_93 ) ;
F_230 ( V_131 , V_367 ) ;
return V_131 < 0 ? V_131 : 0 ;
}
case V_368 :
{
T_3 V_93 ;
T_3 T_2 * V_367 = V_327 ;
T_6 V_131 ;
if ( F_222 ( V_93 , V_367 ) )
return - V_33 ;
if ( F_220 ( 0 , V_367 ) )
return - V_33 ;
V_131 = F_216 ( V_3 , V_93 ) ;
F_230 ( V_131 , V_367 ) ;
return V_131 < 0 ? V_131 : 0 ;
}
}
return F_224 ( V_219 , V_3 , V_328 , V_327 ) ;
}
static int F_232 ( struct V_219 * V_219 ,
struct V_2 * V_3 ,
unsigned int V_328 , void T_2 * V_327 )
{
if ( F_211 ( ! V_3 ) )
return - V_94 ;
if ( F_211 ( V_3 -> V_14 != V_305 ) )
return - V_62 ;
switch ( V_328 ) {
case V_369 :
{
struct V_357 V_358 ;
struct V_357 T_2 * V_359 = V_327 ;
struct V_5 * V_6 = V_3 -> V_6 ;
T_6 V_131 ;
if ( V_6 -> V_91 -> V_90 == V_95 )
return - V_98 ;
if ( F_220 ( 0 , & V_359 -> V_131 ) )
return - V_33 ;
if ( F_64 ( & V_358 , V_359 , sizeof( V_358 ) ) )
return - V_33 ;
V_131 = F_233 ( V_3 , V_358 . V_360 , V_358 . V_93 ) ;
F_230 ( V_131 , & V_359 -> V_131 ) ;
return V_131 < 0 ? V_131 : 0 ;
}
case V_370 :
{
struct V_362 V_363 ;
struct V_362 T_2 * V_364 = V_327 ;
struct V_5 * V_6 = V_3 -> V_6 ;
void * V_365 ;
T_6 V_131 ;
if ( V_6 -> V_91 -> V_90 == V_95 )
return - V_98 ;
if ( V_6 -> V_107 > 128 )
return - V_62 ;
if ( F_220 ( 0 , & V_364 -> V_131 ) )
return - V_33 ;
if ( F_64 ( & V_363 , V_364 , sizeof( V_363 ) ) )
return - V_33 ;
V_365 = F_32 ( V_363 . V_365 ,
sizeof( void * ) * V_6 -> V_107 ) ;
if ( F_33 ( V_365 ) )
return F_34 ( V_365 ) ;
V_131 = F_234 ( V_3 , V_365 , V_363 . V_93 ) ;
F_11 ( V_365 ) ;
F_230 ( V_131 , & V_364 -> V_131 ) ;
return V_131 < 0 ? V_131 : 0 ;
}
case V_366 :
{
T_3 V_93 ;
T_3 T_2 * V_367 = V_327 ;
T_6 V_131 ;
if ( F_222 ( V_93 , V_367 ) )
return - V_33 ;
if ( F_220 ( 0 , V_367 ) )
return - V_33 ;
V_131 = F_214 ( V_3 , V_93 ) ;
F_230 ( V_131 , V_367 ) ;
return V_131 < 0 ? V_131 : 0 ;
}
case V_368 :
{
T_3 V_93 ;
T_3 T_2 * V_367 = V_327 ;
T_6 V_131 ;
if ( F_222 ( V_93 , V_367 ) )
return - V_33 ;
if ( F_220 ( 0 , V_367 ) )
return - V_33 ;
V_131 = F_217 ( V_3 , V_93 ) ;
F_230 ( V_131 , V_367 ) ;
return V_131 < 0 ? V_131 : 0 ;
}
}
return F_224 ( V_219 , V_3 , V_328 , V_327 ) ;
}
static long F_235 ( struct V_219 * V_219 , unsigned int V_328 ,
unsigned long V_327 )
{
struct V_246 * V_247 ;
V_247 = V_219 -> V_252 ;
if ( ( ( V_328 >> 8 ) & 0xff ) != 'A' )
return - V_355 ;
return F_228 ( V_219 , V_247 -> V_3 , V_328 ,
( void T_2 * ) V_327 ) ;
}
static long F_236 ( struct V_219 * V_219 , unsigned int V_328 ,
unsigned long V_327 )
{
struct V_246 * V_247 ;
V_247 = V_219 -> V_252 ;
if ( ( ( V_328 >> 8 ) & 0xff ) != 'A' )
return - V_355 ;
return F_232 ( V_219 , V_247 -> V_3 , V_328 ,
( void T_2 * ) V_327 ) ;
}
int F_237 ( struct V_2 * V_3 ,
unsigned int V_328 , void * V_327 )
{
T_1 V_1 ;
int V_131 ;
V_1 = F_1 () ;
switch ( V_3 -> V_14 ) {
case V_136 :
V_131 = F_228 ( NULL , V_3 , V_328 ,
( void T_2 * ) V_327 ) ;
break;
case V_305 :
V_131 = F_232 ( NULL , V_3 , V_328 ,
( void T_2 * ) V_327 ) ;
break;
default:
V_131 = - V_62 ;
break;
}
F_5 ( V_1 ) ;
return V_131 ;
}
static T_7 F_238 ( struct V_219 * V_219 , char T_2 * V_360 , T_8 V_257 ,
T_9 * V_371 )
{
struct V_246 * V_247 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_131 ;
V_247 = V_219 -> V_252 ;
V_3 = V_247 -> V_3 ;
if ( F_39 ( V_3 ) )
return - V_94 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_91 -> V_90 == V_95 )
return - V_98 ;
if ( ! F_239 ( V_6 , V_257 ) )
return - V_62 ;
V_257 = F_240 ( V_6 , V_257 ) ;
V_131 = F_233 ( V_3 , V_360 , V_257 ) ;
if ( V_131 > 0 )
V_131 = F_241 ( V_6 , V_131 ) ;
return V_131 ;
}
static T_7 F_242 ( struct V_219 * V_219 , const char T_2 * V_360 ,
T_8 V_257 , T_9 * V_371 )
{
struct V_246 * V_247 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_131 ;
V_247 = V_219 -> V_252 ;
V_3 = V_247 -> V_3 ;
if ( F_39 ( V_3 ) )
return - V_94 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_91 -> V_90 == V_95 )
return - V_98 ;
if ( ! F_239 ( V_6 , V_257 ) )
return - V_62 ;
V_257 = F_240 ( V_6 , V_257 ) ;
V_131 = F_229 ( V_3 , V_360 , V_257 ) ;
if ( V_131 > 0 )
V_131 = F_241 ( V_6 , V_131 ) ;
return V_131 ;
}
static T_7 F_243 ( struct V_372 * V_373 , const struct V_374 * V_375 ,
unsigned long V_376 , T_9 V_377 )
{
struct V_246 * V_247 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_131 ;
unsigned long V_40 ;
void T_2 * * V_365 ;
T_3 V_93 ;
V_247 = V_373 -> V_378 -> V_252 ;
V_3 = V_247 -> V_3 ;
if ( F_39 ( V_3 ) )
return - V_94 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_91 -> V_90 == V_95 )
return - V_98 ;
if ( V_376 > 1024 || V_376 != V_6 -> V_107 )
return - V_62 ;
if ( ! F_239 ( V_6 , V_375 -> V_379 ) )
return - V_62 ;
V_93 = F_244 ( V_6 , V_375 -> V_379 ) ;
V_365 = F_9 ( sizeof( void * ) * V_376 , V_31 ) ;
if ( V_365 == NULL )
return - V_32 ;
for ( V_40 = 0 ; V_40 < V_376 ; ++ V_40 )
V_365 [ V_40 ] = V_375 [ V_40 ] . V_380 ;
V_131 = F_234 ( V_3 , V_365 , V_93 ) ;
if ( V_131 > 0 )
V_131 = F_241 ( V_6 , V_131 ) ;
F_11 ( V_365 ) ;
return V_131 ;
}
static T_7 F_245 ( struct V_372 * V_373 , const struct V_374 * V_375 ,
unsigned long V_376 , T_9 V_377 )
{
struct V_246 * V_247 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
T_6 V_131 ;
unsigned long V_40 ;
void T_2 * * V_365 ;
T_3 V_93 ;
V_247 = V_373 -> V_378 -> V_252 ;
V_3 = V_247 -> V_3 ;
if ( F_39 ( V_3 ) )
return - V_94 ;
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_91 -> V_90 == V_95 )
return - V_98 ;
if ( V_376 > 128 || V_376 != V_6 -> V_107 ||
! F_239 ( V_6 , V_375 -> V_379 ) )
return - V_62 ;
V_93 = F_244 ( V_6 , V_375 -> V_379 ) ;
V_365 = F_9 ( sizeof( void * ) * V_376 , V_31 ) ;
if ( V_365 == NULL )
return - V_32 ;
for ( V_40 = 0 ; V_40 < V_376 ; ++ V_40 )
V_365 [ V_40 ] = V_375 [ V_40 ] . V_380 ;
V_131 = F_231 ( V_3 , V_365 , V_93 ) ;
if ( V_131 > 0 )
V_131 = F_241 ( V_6 , V_131 ) ;
F_11 ( V_365 ) ;
return V_131 ;
}
static unsigned int F_246 ( struct V_219 * V_219 , T_10 * V_222 )
{
struct V_246 * V_247 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
unsigned int V_260 ;
T_3 V_147 ;
V_247 = V_219 -> V_252 ;
V_3 = V_247 -> V_3 ;
if ( F_39 ( V_3 ) )
return - V_94 ;
V_6 = V_3 -> V_6 ;
F_247 ( V_219 , & V_6 -> V_185 , V_222 ) ;
F_37 ( V_3 ) ;
V_147 = F_68 ( V_6 ) ;
switch ( V_6 -> V_91 -> V_90 ) {
case V_148 :
case V_97 :
case V_191 :
if ( V_147 >= V_6 -> V_120 -> V_121 ) {
V_260 = V_381 | V_382 ;
break;
}
case V_149 :
V_260 = 0 ;
break;
default:
V_260 = V_381 | V_382 | V_383 ;
break;
}
F_38 ( V_3 ) ;
return V_260 ;
}
static unsigned int F_248 ( struct V_219 * V_219 , T_10 * V_222 )
{
struct V_246 * V_247 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
unsigned int V_260 ;
T_3 V_147 ;
V_247 = V_219 -> V_252 ;
V_3 = V_247 -> V_3 ;
if ( F_39 ( V_3 ) )
return - V_94 ;
V_6 = V_3 -> V_6 ;
F_247 ( V_219 , & V_6 -> V_185 , V_222 ) ;
F_37 ( V_3 ) ;
V_147 = F_69 ( V_6 ) ;
switch ( V_6 -> V_91 -> V_90 ) {
case V_148 :
case V_97 :
case V_191 :
if ( V_147 >= V_6 -> V_120 -> V_121 ) {
V_260 = V_384 | V_385 ;
break;
}
V_260 = 0 ;
break;
case V_149 :
if ( V_147 > 0 ) {
V_260 = V_384 | V_385 ;
break;
}
default:
V_260 = V_384 | V_385 | V_383 ;
break;
}
F_38 ( V_3 ) ;
return V_260 ;
}
static int F_249 ( struct V_386 * V_387 ,
struct V_388 * V_389 )
{
struct V_2 * V_3 = V_387 -> V_390 ;
struct V_5 * V_6 ;
if ( V_3 == NULL )
return V_391 ;
V_6 = V_3 -> V_6 ;
V_389 -> V_392 = F_250 ( V_6 -> V_91 ) ;
F_251 ( V_389 -> V_392 ) ;
return 0 ;
}
static int V_320 ( struct V_2 * V_3 , struct V_219 * V_219 ,
struct V_386 * V_387 )
{
long V_393 ;
if ( ! ( V_387 -> V_394 & V_395 ) )
return - V_62 ;
V_393 = V_387 -> V_396 - V_387 -> V_397 ;
if ( V_393 != F_252 ( sizeof( struct V_320 ) ) )
return - V_62 ;
V_387 -> V_398 = & V_399 ;
V_387 -> V_390 = V_3 ;
V_387 -> V_394 |= V_400 | V_401 ;
return 0 ;
}
static int F_253 ( struct V_386 * V_387 ,
struct V_388 * V_389 )
{
struct V_2 * V_3 = V_387 -> V_390 ;
struct V_5 * V_6 ;
if ( V_3 == NULL )
return V_391 ;
V_6 = V_3 -> V_6 ;
V_389 -> V_392 = F_250 ( V_6 -> V_120 ) ;
F_251 ( V_389 -> V_392 ) ;
return 0 ;
}
static int V_321 ( struct V_2 * V_3 , struct V_219 * V_219 ,
struct V_386 * V_387 )
{
long V_393 ;
if ( ! ( V_387 -> V_394 & V_395 ) )
return - V_62 ;
V_393 = V_387 -> V_396 - V_387 -> V_397 ;
if ( V_393 != F_252 ( sizeof( struct V_321 ) ) )
return - V_62 ;
V_387 -> V_398 = & V_402 ;
V_387 -> V_390 = V_3 ;
V_387 -> V_394 |= V_400 | V_401 ;
return 0 ;
}
static int V_320 ( struct V_2 * V_3 , struct V_219 * V_219 ,
struct V_386 * V_387 )
{
return - V_94 ;
}
static int V_321 ( struct V_2 * V_3 , struct V_219 * V_219 ,
struct V_386 * V_387 )
{
return - V_94 ;
}
static inline struct V_392 *
F_254 ( struct V_2 * V_3 , unsigned long V_403 )
{
void * V_404 = V_3 -> V_6 -> V_405 + V_403 ;
#if F_255 ( V_406 ) && F_255 ( V_407 )
if ( V_3 -> V_408 . V_237 . type == V_409 )
return F_250 ( F_256 ( V_404 ) ) ;
#endif
#if F_255 ( V_410 ) && F_255 ( V_411 )
if ( V_3 -> V_408 . V_237 . type == V_409 ) {
T_11 V_412 = V_3 -> V_6 -> V_413 + V_403 ;
V_412 -= F_257 ( V_3 -> V_408 . V_237 . V_237 ) ;
return F_258 ( V_412 >> V_414 ) ;
}
#endif
return F_250 ( V_404 ) ;
}
static int F_259 ( struct V_386 * V_387 ,
struct V_388 * V_389 )
{
struct V_2 * V_3 = V_387 -> V_390 ;
struct V_5 * V_6 ;
unsigned long V_371 ;
struct V_392 * V_392 ;
T_8 V_296 ;
if ( V_3 == NULL )
return V_391 ;
V_6 = V_3 -> V_6 ;
V_371 = V_389 -> V_415 << V_414 ;
V_296 = F_252 ( V_6 -> V_296 ) ;
if ( V_371 > V_296 - V_416 )
return V_391 ;
if ( V_3 -> V_26 -> V_392 )
V_392 = V_3 -> V_26 -> V_392 ( V_3 , V_371 ) ;
else
V_392 = F_254 ( V_3 , V_371 ) ;
if ( ! V_392 )
return V_391 ;
F_251 ( V_392 ) ;
V_389 -> V_392 = V_392 ;
return 0 ;
}
int F_260 ( struct V_2 * V_3 ,
struct V_386 * V_387 )
{
V_387 -> V_394 |= V_400 | V_401 ;
#ifdef F_261
if ( V_3 -> V_408 . V_237 . type == V_417 ) {
V_387 -> V_418 = F_262 ( V_387 -> V_418 ) ;
return F_263 ( V_387 , V_387 -> V_397 ,
V_3 -> V_408 . V_412 >> V_414 ,
V_387 -> V_396 - V_387 -> V_397 , V_387 -> V_418 ) ;
}
#endif
#ifdef F_264
if ( ! V_3 -> V_26 -> V_392 &&
V_3 -> V_408 . V_237 . type == V_409 )
return F_265 ( V_3 -> V_408 . V_237 . V_237 ,
V_387 ,
V_3 -> V_6 -> V_405 ,
V_3 -> V_6 -> V_413 ,
V_387 -> V_396 - V_387 -> V_397 ) ;
#elif F_255 ( V_406 ) && F_255 ( V_407 )
if ( V_3 -> V_408 . V_237 . type == V_409 &&
! F_266 ( V_3 -> V_408 . V_237 . V_237 ) )
V_387 -> V_418 = F_267 ( V_387 -> V_418 ) ;
#endif
V_387 -> V_398 = & V_419 ;
return 0 ;
}
int F_268 ( struct V_2 * V_3 ,
struct V_386 * V_387 )
{
struct V_5 * V_6 = V_3 -> V_6 ; ;
V_387 -> V_418 = F_267 ( V_387 -> V_418 ) ;
return F_269 ( V_387 , V_6 -> V_413 , V_6 -> V_296 ) ;
}
int F_270 ( struct V_2 * V_3 , struct V_219 * V_219 ,
struct V_386 * V_387 )
{
struct V_5 * V_6 ;
long V_393 ;
unsigned long V_371 ;
T_8 V_296 ;
int V_30 ;
if ( V_3 -> V_14 == V_136 ) {
if ( ! ( V_387 -> V_394 & ( V_420 | V_395 ) ) )
return - V_62 ;
} else {
if ( ! ( V_387 -> V_394 & V_395 ) )
return - V_62 ;
}
V_6 = V_3 -> V_6 ;
if ( V_6 -> V_91 -> V_90 == V_95 )
return - V_98 ;
if ( ! ( V_6 -> V_4 & V_279 ) )
return - V_94 ;
if ( V_6 -> V_104 == V_276 ||
V_6 -> V_104 == V_278 )
return - V_62 ;
V_393 = V_387 -> V_396 - V_387 -> V_397 ;
V_371 = V_387 -> V_421 << V_414 ;
V_296 = F_252 ( V_6 -> V_296 ) ;
if ( ( T_8 ) V_393 > V_296 )
return - V_62 ;
if ( V_371 > V_296 - V_393 )
return - V_62 ;
V_387 -> V_398 = & V_422 ;
V_387 -> V_390 = V_3 ;
if ( V_3 -> V_26 -> V_423 )
V_30 = V_3 -> V_26 -> V_423 ( V_3 , V_387 ) ;
else
V_30 = F_260 ( V_3 , V_387 ) ;
if ( ! V_30 )
F_271 ( & V_3 -> V_101 ) ;
return V_30 ;
}
static int F_272 ( struct V_219 * V_219 , struct V_386 * V_387 )
{
struct V_246 * V_247 ;
struct V_2 * V_3 ;
unsigned long V_371 ;
V_247 = V_219 -> V_252 ;
V_3 = V_247 -> V_3 ;
if ( F_39 ( V_3 ) )
return - V_94 ;
V_371 = V_387 -> V_421 << V_414 ;
switch ( V_371 ) {
case V_424 :
if ( V_247 -> V_425 )
return - V_94 ;
return V_320 ( V_3 , V_219 , V_387 ) ;
case V_426 :
if ( V_247 -> V_425 )
return - V_94 ;
return V_321 ( V_3 , V_219 , V_387 ) ;
default:
return F_270 ( V_3 , V_219 , V_387 ) ;
}
return 0 ;
}
static int F_273 ( int V_245 , struct V_219 * V_219 , int V_427 )
{
struct V_246 * V_247 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
V_247 = V_219 -> V_252 ;
V_3 = V_247 -> V_3 ;
if ( F_39 ( V_3 ) )
return - V_94 ;
V_6 = V_3 -> V_6 ;
return F_274 ( V_245 , V_219 , V_427 , & V_6 -> V_428 ) ;
}
static void F_275 ( struct V_34 * V_35 ,
struct V_429 * V_430 )
{
unsigned int V_40 ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
V_35 -> V_78 = V_430 -> V_78 ;
for ( V_40 = 0 ; V_40 < F_276 ( V_430 -> V_431 ) ; V_40 ++ )
V_35 -> V_431 [ V_40 ] . V_64 [ 0 ] = V_430 -> V_431 [ V_40 ] ;
memcpy ( V_35 -> V_432 , V_430 -> V_432 , sizeof( V_430 -> V_432 ) ) ;
V_35 -> V_54 = F_277 ( V_430 -> V_54 ) ;
V_35 -> V_65 = F_277 ( V_430 -> V_65 ) ;
V_35 -> V_4 = V_430 -> V_4 ;
V_35 -> V_56 = V_430 -> V_56 ;
V_35 -> V_58 = V_430 -> V_58 ;
V_35 -> V_59 = V_430 -> V_59 ;
V_35 -> V_53 = V_430 -> V_53 ;
}
static void F_278 ( struct V_429 * V_430 ,
struct V_34 * V_35 )
{
unsigned int V_40 ;
memset ( V_430 , 0 , sizeof( * V_430 ) ) ;
V_430 -> V_78 = V_35 -> V_78 ;
for ( V_40 = 0 ; V_40 < F_276 ( V_430 -> V_431 ) ; V_40 ++ )
V_430 -> V_431 [ V_40 ] = V_35 -> V_431 [ V_40 ] . V_64 [ 0 ] ;
memcpy ( V_430 -> V_432 , V_35 -> V_432 , sizeof( V_430 -> V_432 ) ) ;
V_430 -> V_54 = F_279 ( V_35 -> V_54 ) ;
V_430 -> V_65 = F_279 ( V_35 -> V_65 ) ;
V_430 -> V_4 = V_35 -> V_4 ;
V_430 -> V_56 = V_35 -> V_56 ;
V_430 -> V_58 = V_35 -> V_58 ;
V_430 -> V_59 = V_35 -> V_59 ;
V_430 -> V_53 = V_35 -> V_53 ;
}
static int F_226 ( struct V_2 * V_3 ,
struct V_429 T_2 * V_433 )
{
struct V_34 * V_35 ;
struct V_429 * V_430 = NULL ;
int V_30 ;
V_35 = F_9 ( sizeof( * V_35 ) , V_31 ) ;
if ( ! V_35 )
return - V_32 ;
V_430 = F_32 ( V_433 , sizeof( * V_430 ) ) ;
if ( F_33 ( V_430 ) ) {
V_30 = F_34 ( V_430 ) ;
goto V_434;
}
F_275 ( V_35 , V_430 ) ;
V_30 = F_12 ( V_3 , V_35 ) ;
F_278 ( V_430 , V_35 ) ;
if ( F_10 ( V_433 , V_430 , sizeof( * V_430 ) ) ) {
if ( ! V_30 )
V_30 = - V_33 ;
}
F_11 ( V_430 ) ;
V_434:
F_11 ( V_35 ) ;
return V_30 ;
}
static int F_227 ( struct V_2 * V_3 ,
struct V_429 T_2 * V_433 )
{
struct V_34 * V_35 ;
struct V_429 * V_430 = NULL ;
int V_30 ;
V_35 = F_9 ( sizeof( * V_35 ) , V_31 ) ;
if ( ! V_35 )
return - V_32 ;
V_430 = F_32 ( V_433 , sizeof( * V_430 ) ) ;
if ( F_33 ( V_430 ) ) {
V_30 = F_34 ( V_430 ) ;
goto V_434;
}
F_275 ( V_35 , V_430 ) ;
V_30 = V_34 ( V_3 , V_35 ) ;
F_278 ( V_430 , V_35 ) ;
if ( F_10 ( V_433 , V_430 , sizeof( * V_430 ) ) ) {
if ( ! V_30 )
V_30 = - V_33 ;
}
F_11 ( V_430 ) ;
V_434:
F_11 ( V_35 ) ;
return V_30 ;
}
static unsigned long F_280 ( struct V_219 * V_219 ,
unsigned long V_412 ,
unsigned long V_435 ,
unsigned long V_415 ,
unsigned long V_78 )
{
struct V_246 * V_247 = V_219 -> V_252 ;
struct V_2 * V_3 = V_247 -> V_3 ;
struct V_5 * V_6 = V_3 -> V_6 ;
unsigned long V_371 = V_415 << V_414 ;
switch ( V_371 ) {
case V_424 :
return ( unsigned long ) V_6 -> V_91 ;
case V_426 :
return ( unsigned long ) V_6 -> V_120 ;
default:
return ( unsigned long ) V_6 -> V_405 + V_371 ;
}
}
