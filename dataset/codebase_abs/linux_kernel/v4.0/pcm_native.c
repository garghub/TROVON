void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 ) {
F_2 ( & V_5 ) ;
F_3 ( & V_2 -> V_6 . V_7 ) ;
} else {
F_4 ( & V_8 ) ;
F_5 ( & V_2 -> V_6 . V_9 ) ;
}
}
void F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 ) {
F_7 ( & V_2 -> V_6 . V_7 ) ;
F_8 ( & V_5 ) ;
} else {
F_9 ( & V_2 -> V_6 . V_9 ) ;
F_10 ( & V_8 ) ;
}
}
void F_11 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 -> V_4 )
F_12 () ;
F_1 ( V_2 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
if ( ! V_2 -> V_3 -> V_4 )
F_14 () ;
}
unsigned long F_15 ( struct V_1 * V_2 )
{
unsigned long V_10 = 0 ;
if ( ! V_2 -> V_3 -> V_4 )
F_16 ( V_10 ) ;
F_1 ( V_2 ) ;
return V_10 ;
}
void F_17 ( struct V_1 * V_2 ,
unsigned long V_10 )
{
F_6 ( V_2 ) ;
if ( ! V_2 -> V_3 -> V_4 )
F_18 ( V_10 ) ;
}
static inline T_1 F_19 ( void )
{
T_1 V_11 = F_20 () ;
F_21 ( F_22 () ) ;
return V_11 ;
}
static inline void F_23 ( T_1 V_11 )
{
F_21 ( V_11 ) ;
}
int F_24 ( struct V_1 * V_2 , struct F_24 * V_12 )
{
struct V_13 * V_14 ;
struct V_15 * V_3 = V_2 -> V_3 ;
struct V_16 * V_17 = V_2 -> V_17 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_18 = V_3 -> V_18 -> V_19 ;
V_12 -> V_20 = V_3 -> V_20 ;
V_12 -> V_21 = V_2 -> V_21 ;
V_12 -> V_22 = V_2 -> V_19 ;
F_25 ( V_12 -> V_23 , V_3 -> V_23 , sizeof( V_12 -> V_23 ) ) ;
F_25 ( V_12 -> V_24 , V_3 -> V_24 , sizeof( V_12 -> V_24 ) ) ;
V_12 -> V_25 = V_3 -> V_25 ;
V_12 -> V_26 = V_3 -> V_26 ;
V_12 -> V_27 = V_17 -> V_28 ;
V_12 -> V_29 = V_17 -> V_28 - V_17 -> V_30 ;
F_25 ( V_12 -> V_31 , V_2 -> V_24 , sizeof( V_12 -> V_31 ) ) ;
V_14 = V_2 -> V_14 ;
if ( V_14 ) {
V_12 -> V_32 = V_14 -> V_32 ;
V_2 -> V_33 -> V_34 ( V_2 , V_35 , V_12 ) ;
}
return 0 ;
}
int F_26 ( struct V_1 * V_2 ,
struct F_24 T_2 * V_36 )
{
struct F_24 * V_12 ;
int V_37 ;
V_12 = F_27 ( sizeof( * V_12 ) , V_38 ) ;
if ( ! V_12 )
return - V_39 ;
V_37 = F_24 ( V_2 , V_12 ) ;
if ( V_37 >= 0 ) {
if ( F_28 ( V_36 , V_12 , sizeof( * V_12 ) ) )
V_37 = - V_40 ;
}
F_29 ( V_12 ) ;
return V_37 ;
}
static bool F_30 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_14 -> V_41 . V_12 & V_42 ) )
return false ;
#if F_31 ( V_43 ) || F_31 ( V_44 ) || F_31 ( V_45 ) ||\
F_31 ( V_46 ) || F_31 ( V_47 )
if ( ! V_2 -> V_33 -> V_48 &&
V_2 -> V_49 . V_50 . type == V_51 )
return false ;
#endif
return true ;
}
int F_32 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
unsigned int V_54 ;
struct V_55 * V_41 ;
struct V_56 * V_57 = NULL ;
struct V_58 * V_59 = NULL ;
struct V_60 * V_61 = & V_2 -> V_14 -> V_62 ;
unsigned int V_63 [ V_61 -> V_64 ] ;
unsigned int V_65 [ V_66 + 1 ] ;
unsigned int V_67 = 2 ;
int V_68 , V_69 ;
V_53 -> V_12 = 0 ;
V_53 -> V_70 = 0 ;
if ( V_53 -> V_71 & ( 1 << V_72 ) )
V_53 -> V_73 = 0 ;
if ( V_53 -> V_71 & ( 1 << V_74 ) ) {
V_53 -> V_75 = 0 ;
V_53 -> V_76 = 0 ;
}
for ( V_54 = V_77 ; V_54 <= V_78 ; V_54 ++ ) {
V_59 = F_33 ( V_53 , V_54 ) ;
if ( F_34 ( V_59 ) )
return - V_79 ;
if ( ! ( V_53 -> V_71 & ( 1 << V_54 ) ) )
continue;
#ifdef F_35
F_36 ( L_1 , V_80 [ V_54 ] ) ;
F_37 ( L_2 , V_59 -> V_81 [ 3 ] , V_59 -> V_81 [ 2 ] , V_59 -> V_81 [ 1 ] , V_59 -> V_81 [ 0 ] ) ;
#endif
V_68 = F_38 ( V_59 , F_39 ( V_61 , V_54 ) ) ;
#ifdef F_35
F_37 ( L_3 , V_59 -> V_81 [ 3 ] , V_59 -> V_81 [ 2 ] , V_59 -> V_81 [ 1 ] , V_59 -> V_81 [ 0 ] ) ;
#endif
if ( V_68 )
V_53 -> V_82 |= 1 << V_54 ;
if ( V_68 < 0 )
return V_68 ;
}
for ( V_54 = V_83 ; V_54 <= V_66 ; V_54 ++ ) {
V_57 = F_40 ( V_53 , V_54 ) ;
if ( F_41 ( V_57 ) )
return - V_79 ;
if ( ! ( V_53 -> V_71 & ( 1 << V_54 ) ) )
continue;
#ifdef F_35
F_36 ( L_1 , V_80 [ V_54 ] ) ;
if ( V_57 -> V_84 )
F_37 ( L_4 ) ;
else
F_37 ( L_5 ,
V_57 -> V_85 ? '(' : '[' , V_57 -> V_86 ,
V_57 -> V_87 , V_57 -> V_88 ? ')' : ']' ) ;
F_37 ( L_6 ) ;
#endif
V_68 = F_42 ( V_57 , F_43 ( V_61 , V_54 ) ) ;
#ifdef F_35
if ( V_57 -> V_84 )
F_37 ( L_7 ) ;
else
F_37 ( L_8 ,
V_57 -> V_85 ? '(' : '[' , V_57 -> V_86 ,
V_57 -> V_87 , V_57 -> V_88 ? ')' : ']' ) ;
#endif
if ( V_68 )
V_53 -> V_82 |= 1 << V_54 ;
if ( V_68 < 0 )
return V_68 ;
}
for ( V_54 = 0 ; V_54 < V_61 -> V_64 ; V_54 ++ )
V_63 [ V_54 ] = 0 ;
for ( V_54 = 0 ; V_54 <= V_66 ; V_54 ++ )
V_65 [ V_54 ] = ( V_53 -> V_71 & ( 1 << V_54 ) ) ? 1 : 0 ;
do {
V_69 = 0 ;
for ( V_54 = 0 ; V_54 < V_61 -> V_64 ; V_54 ++ ) {
struct V_89 * V_90 = & V_61 -> V_91 [ V_54 ] ;
unsigned int V_92 ;
int V_93 = 0 ;
if ( V_90 -> V_94 && ! ( V_90 -> V_94 & V_53 -> V_10 ) )
continue;
for ( V_92 = 0 ; V_90 -> V_95 [ V_92 ] >= 0 ; V_92 ++ ) {
if ( V_65 [ V_90 -> V_95 [ V_92 ] ] > V_63 [ V_54 ] ) {
V_93 = 1 ;
break;
}
}
if ( ! V_93 )
continue;
#ifdef F_35
F_36 ( L_9 , V_54 , V_90 -> V_96 ) ;
if ( V_90 -> V_97 >= 0 ) {
F_37 ( L_1 , V_80 [ V_90 -> V_97 ] ) ;
if ( F_44 ( V_90 -> V_97 ) ) {
V_59 = F_33 ( V_53 , V_90 -> V_97 ) ;
F_37 ( L_10 , * V_59 -> V_81 ) ;
} else {
V_57 = F_40 ( V_53 , V_90 -> V_97 ) ;
if ( V_57 -> V_84 )
F_37 ( L_4 ) ;
else
F_37 ( L_5 ,
V_57 -> V_85 ? '(' : '[' , V_57 -> V_86 ,
V_57 -> V_87 , V_57 -> V_88 ? ')' : ']' ) ;
}
}
#endif
V_68 = V_90 -> V_96 ( V_53 , V_90 ) ;
#ifdef F_35
if ( V_90 -> V_97 >= 0 ) {
F_37 ( L_6 ) ;
if ( F_44 ( V_90 -> V_97 ) )
F_37 ( L_10 , * V_59 -> V_81 ) ;
else {
if ( V_57 -> V_84 )
F_37 ( L_4 ) ;
else
F_37 ( L_5 ,
V_57 -> V_85 ? '(' : '[' , V_57 -> V_86 ,
V_57 -> V_87 , V_57 -> V_88 ? ')' : ']' ) ;
}
}
F_37 ( L_11 ) ;
#endif
V_63 [ V_54 ] = V_67 ;
if ( V_68 && V_90 -> V_97 >= 0 ) {
V_53 -> V_82 |= ( 1 << V_90 -> V_97 ) ;
V_65 [ V_90 -> V_97 ] = V_67 ;
V_69 = 1 ;
}
if ( V_68 < 0 )
return V_68 ;
V_67 ++ ;
}
} while ( V_69 );
if ( ! V_53 -> V_73 ) {
V_57 = F_40 ( V_53 , V_72 ) ;
if ( F_45 ( V_57 ) )
V_53 -> V_73 = F_46 ( V_57 ) ;
}
if ( ! V_53 -> V_76 ) {
V_57 = F_40 ( V_53 , V_74 ) ;
if ( F_45 ( V_57 ) ) {
V_53 -> V_75 = F_46 ( V_57 ) ;
V_53 -> V_76 = 1 ;
}
}
V_41 = & V_2 -> V_14 -> V_41 ;
if ( ! V_53 -> V_12 ) {
V_53 -> V_12 = V_41 -> V_12 & ~ ( V_98 |
V_99 ) ;
if ( ! F_30 ( V_2 ) )
V_53 -> V_12 &= ~ ( V_42 |
V_100 ) ;
}
if ( ! V_53 -> V_70 ) {
V_59 = F_33 ( V_53 , V_101 ) ;
V_57 = F_40 ( V_53 , V_102 ) ;
if ( F_47 ( V_59 ) == F_48 ( V_59 ) &&
F_49 ( V_57 ) == F_50 ( V_57 ) ) {
V_68 = V_2 -> V_33 -> V_34 ( V_2 ,
V_103 , V_53 ) ;
if ( V_68 < 0 )
return V_68 ;
}
}
V_53 -> V_71 = 0 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_52 T_2 * V_104 )
{
struct V_52 * V_53 ;
int V_37 ;
V_53 = F_52 ( V_104 , sizeof( * V_53 ) ) ;
if ( F_53 ( V_53 ) )
return F_54 ( V_53 ) ;
V_37 = F_32 ( V_2 , V_53 ) ;
if ( F_28 ( V_104 , V_53 , sizeof( * V_53 ) ) ) {
if ( ! V_37 )
V_37 = - V_40 ;
}
F_29 ( V_53 ) ;
return V_37 ;
}
static int F_55 ( struct V_13 * V_14 )
{
int V_105 ;
if ( ! V_14 -> V_106 )
return - 1 ;
V_105 = ( 750000 / V_14 -> V_106 ) * V_14 -> V_107 ;
V_105 += ( ( 750000 % V_14 -> V_106 ) * V_14 -> V_107 ) /
V_14 -> V_106 ;
return V_105 ;
}
static void F_56 ( struct V_1 * V_2 , int V_108 )
{
F_11 ( V_2 ) ;
if ( V_2 -> V_14 -> V_109 -> V_108 != V_110 )
V_2 -> V_14 -> V_109 -> V_108 = V_108 ;
F_13 ( V_2 ) ;
}
static int V_52 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_13 * V_14 ;
int V_37 , V_105 ;
unsigned int V_81 ;
T_3 V_111 ;
if ( F_57 ( V_2 ) )
return - V_112 ;
V_14 = V_2 -> V_14 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_109 -> V_108 ) {
case V_113 :
case V_114 :
case V_115 :
break;
default:
F_13 ( V_2 ) ;
return - V_116 ;
}
F_13 ( V_2 ) ;
#if F_58 ( V_117 )
if ( ! V_2 -> V_118 . V_118 )
#endif
if ( F_59 ( & V_2 -> V_119 ) )
return - V_116 ;
V_53 -> V_71 = ~ 0U ;
V_37 = F_32 ( V_2 , V_53 ) ;
if ( V_37 < 0 )
goto V_120;
V_37 = F_60 ( V_2 , V_53 ) ;
if ( V_37 < 0 )
goto V_120;
if ( V_2 -> V_33 -> V_121 != NULL ) {
V_37 = V_2 -> V_33 -> V_121 ( V_2 , V_53 ) ;
if ( V_37 < 0 )
goto V_120;
}
V_14 -> V_122 = F_61 ( V_53 ) ;
V_14 -> V_123 = F_62 ( V_53 ) ;
V_14 -> V_124 = F_63 ( V_53 ) ;
V_14 -> V_125 = F_64 ( V_53 ) ;
V_14 -> V_106 = F_65 ( V_53 ) ;
V_14 -> V_107 = F_66 ( V_53 ) ;
V_14 -> V_126 = F_67 ( V_53 ) ;
V_14 -> V_127 = F_68 ( V_53 ) ;
V_14 -> V_12 = V_53 -> V_12 ;
V_14 -> V_75 = V_53 -> V_75 ;
V_14 -> V_76 = V_53 -> V_76 ;
V_14 -> V_128 =
( V_53 -> V_12 & V_129 ) &&
( V_53 -> V_10 & V_130 ) ;
V_81 = F_69 ( V_14 -> V_123 ) ;
V_14 -> V_131 = V_81 ;
V_81 *= V_14 -> V_125 ;
V_14 -> V_132 = V_81 ;
V_111 = 1 ;
while ( V_81 % 8 != 0 ) {
V_81 *= 2 ;
V_111 *= 2 ;
}
V_14 -> V_133 = V_81 / 8 ;
V_14 -> V_134 = V_111 ;
V_14 -> V_135 = V_136 ;
V_14 -> V_137 = 1 ;
V_14 -> V_138 -> V_139 = V_14 -> V_107 ;
V_14 -> V_140 = 1 ;
V_14 -> V_141 = V_14 -> V_127 ;
V_14 -> V_142 = 0 ;
V_14 -> V_143 = 0 ;
V_14 -> V_144 = V_14 -> V_127 ;
while ( V_14 -> V_144 * 2 <= V_145 - V_14 -> V_127 )
V_14 -> V_144 *= 2 ;
F_70 ( V_2 ) ;
F_56 ( V_2 , V_114 ) ;
if ( F_71 ( & V_2 -> V_146 ) )
F_72 ( & V_2 -> V_146 ) ;
if ( ( V_105 = F_55 ( V_14 ) ) >= 0 )
F_73 ( & V_2 -> V_146 ,
V_147 , V_105 ) ;
return 0 ;
V_120:
F_56 ( V_2 , V_113 ) ;
if ( V_2 -> V_33 -> V_148 != NULL )
V_2 -> V_33 -> V_148 ( V_2 ) ;
return V_37 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_52 T_2 * V_104 )
{
struct V_52 * V_53 ;
int V_37 ;
V_53 = F_52 ( V_104 , sizeof( * V_53 ) ) ;
if ( F_53 ( V_53 ) )
return F_54 ( V_53 ) ;
V_37 = V_52 ( V_2 , V_53 ) ;
if ( F_28 ( V_104 , V_53 , sizeof( * V_53 ) ) ) {
if ( ! V_37 )
V_37 = - V_40 ;
}
F_29 ( V_53 ) ;
return V_37 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
int V_149 = 0 ;
if ( F_57 ( V_2 ) )
return - V_112 ;
V_14 = V_2 -> V_14 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_109 -> V_108 ) {
case V_114 :
case V_115 :
break;
default:
F_13 ( V_2 ) ;
return - V_116 ;
}
F_13 ( V_2 ) ;
if ( F_59 ( & V_2 -> V_119 ) )
return - V_116 ;
if ( V_2 -> V_33 -> V_148 )
V_149 = V_2 -> V_33 -> V_148 ( V_2 ) ;
F_56 ( V_2 , V_113 ) ;
F_72 ( & V_2 -> V_146 ) ;
return V_149 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct F_76 * V_53 )
{
struct V_13 * V_14 ;
int V_37 ;
if ( F_57 ( V_2 ) )
return - V_112 ;
V_14 = V_2 -> V_14 ;
F_11 ( V_2 ) ;
if ( V_14 -> V_109 -> V_108 == V_113 ) {
F_13 ( V_2 ) ;
return - V_116 ;
}
F_13 ( V_2 ) ;
if ( V_53 -> V_135 > V_150 )
return - V_79 ;
if ( V_53 -> V_151 >= F_77 ( 2 , 0 , 12 ) &&
V_53 -> V_152 > V_153 )
return - V_79 ;
if ( V_53 -> V_139 == 0 )
return - V_79 ;
if ( V_53 -> V_143 >= V_14 -> V_144 ) {
if ( V_53 -> V_142 != 0 )
return - V_79 ;
} else {
if ( V_53 -> V_143 > V_53 -> V_142 )
return - V_79 ;
if ( V_53 -> V_142 > V_14 -> V_127 )
return - V_79 ;
}
V_37 = 0 ;
F_11 ( V_2 ) ;
V_14 -> V_135 = V_53 -> V_135 ;
if ( V_53 -> V_151 >= F_77 ( 2 , 0 , 12 ) )
V_14 -> V_152 = V_53 -> V_152 ;
V_14 -> V_137 = V_53 -> V_137 ;
V_14 -> V_138 -> V_139 = V_53 -> V_139 ;
V_14 -> V_140 = V_53 -> V_140 ;
V_14 -> V_141 = V_53 -> V_141 ;
V_14 -> V_142 = V_53 -> V_142 ;
V_14 -> V_143 = V_53 -> V_143 ;
V_53 -> V_144 = V_14 -> V_144 ;
if ( F_78 ( V_2 ) ) {
if ( V_2 -> V_21 == V_154 &&
V_14 -> V_143 > 0 )
F_79 ( V_2 , V_155 ) ;
V_37 = F_80 ( V_2 , V_14 ) ;
}
F_13 ( V_2 ) ;
return V_37 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct F_76 T_2 * V_104 )
{
struct F_76 V_53 ;
int V_37 ;
if ( F_82 ( & V_53 , V_104 , sizeof( V_53 ) ) )
return - V_40 ;
V_37 = F_76 ( V_2 , & V_53 ) ;
if ( F_28 ( V_104 , & V_53 , sizeof( V_53 ) ) )
return - V_40 ;
return V_37 ;
}
int F_83 ( struct V_1 * V_2 ,
struct F_83 * V_109 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_11 ( V_2 ) ;
V_109 -> V_108 = V_14 -> V_109 -> V_108 ;
V_109 -> V_156 = V_14 -> V_109 -> V_156 ;
if ( V_109 -> V_108 == V_113 )
goto V_157;
V_109 -> V_158 = V_14 -> V_158 ;
if ( F_78 ( V_2 ) ) {
F_84 ( V_2 ) ;
if ( V_14 -> V_135 == V_159 ) {
V_109 -> V_160 = V_14 -> V_109 -> V_160 ;
V_109 -> V_161 =
V_14 -> V_109 -> V_161 ;
goto V_162;
}
} else {
if ( V_14 -> V_135 == V_159 )
F_85 ( V_14 , & V_109 -> V_160 ) ;
}
V_162:
V_109 -> V_163 = V_14 -> V_138 -> V_163 ;
V_109 -> V_164 = V_14 -> V_109 -> V_164 ;
if ( V_2 -> V_21 == V_154 ) {
V_109 -> V_165 = F_86 ( V_14 ) ;
if ( V_14 -> V_109 -> V_108 == V_166 ||
V_14 -> V_109 -> V_108 == V_167 ) {
V_109 -> V_168 = V_14 -> V_127 - V_109 -> V_165 ;
V_109 -> V_168 += V_14 -> V_168 ;
} else
V_109 -> V_168 = 0 ;
} else {
V_109 -> V_165 = F_87 ( V_14 ) ;
if ( V_14 -> V_109 -> V_108 == V_166 )
V_109 -> V_168 = V_109 -> V_165 + V_14 -> V_168 ;
else
V_109 -> V_168 = 0 ;
}
V_109 -> V_169 = V_14 -> V_169 ;
V_109 -> V_170 = V_14 -> V_170 ;
V_14 -> V_169 = 0 ;
V_14 -> V_170 = 0 ;
V_157:
F_13 ( V_2 ) ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct F_83 T_2 * V_171 )
{
struct F_83 V_109 ;
int V_172 ;
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
V_172 = F_83 ( V_2 , & V_109 ) ;
if ( V_172 < 0 )
return V_172 ;
if ( F_28 ( V_171 , & V_109 , sizeof( V_109 ) ) )
return - V_40 ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct F_89 * V_12 )
{
struct V_13 * V_14 ;
unsigned int V_173 ;
V_173 = V_12 -> V_173 ;
V_14 = V_2 -> V_14 ;
F_11 ( V_2 ) ;
if ( V_14 -> V_109 -> V_108 == V_113 ) {
F_13 ( V_2 ) ;
return - V_116 ;
}
F_13 ( V_2 ) ;
if ( V_173 >= V_14 -> V_125 )
return - V_79 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_173 = V_173 ;
return V_2 -> V_33 -> V_34 ( V_2 , V_174 , V_12 ) ;
}
static int F_90 ( struct V_1 * V_2 ,
struct F_89 T_2 * V_36 )
{
struct F_89 V_12 ;
int V_172 ;
if ( F_82 ( & V_12 , V_36 , sizeof( V_12 ) ) )
return - V_40 ;
V_172 = F_89 ( V_2 , & V_12 ) ;
if ( V_172 < 0 )
return V_172 ;
if ( F_28 ( V_36 , & V_12 , sizeof( V_12 ) ) )
return - V_40 ;
return 0 ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_175 == NULL )
return;
if ( V_14 -> V_175 == V_2 ) {
if ( ! V_14 -> V_176 )
F_85 ( V_14 , & V_14 -> V_158 ) ;
} else {
F_91 ( V_14 -> V_175 ) ;
V_14 -> V_158 = V_14 -> V_175 -> V_14 -> V_158 ;
}
V_14 -> V_175 = NULL ;
}
static int F_92 ( struct V_177 * V_33 ,
struct V_1 * V_2 ,
int V_108 , int V_178 )
{
struct V_1 * V_179 = NULL ;
struct V_1 * V_180 ;
int V_172 = 0 , V_181 = 1 ;
F_93 (s, substream) {
if ( V_178 && V_179 != V_2 ) {
if ( V_179 -> V_3 -> V_4 )
F_94 ( & V_179 -> V_6 . V_7 , V_181 ) ;
else
F_95 ( & V_179 -> V_6 . V_9 , V_181 ) ;
V_181 ++ ;
}
V_172 = V_33 -> V_182 ( V_179 , V_108 ) ;
if ( V_172 < 0 )
goto V_183;
}
F_93 (s, substream) {
V_172 = V_33 -> V_184 ( V_179 , V_108 ) ;
if ( V_172 < 0 ) {
if ( V_33 -> V_185 ) {
F_93 (s1, substream) {
if ( V_180 == V_179 )
break;
V_33 -> V_185 ( V_180 , V_108 ) ;
}
}
V_179 = NULL ;
goto V_183;
}
}
F_93 (s, substream) {
V_33 -> V_186 ( V_179 , V_108 ) ;
}
V_183:
if ( V_178 ) {
F_93 (s1, substream) {
if ( V_180 != V_2 ) {
if ( V_180 -> V_3 -> V_4 )
F_7 ( & V_180 -> V_6 . V_7 ) ;
else
F_9 ( & V_180 -> V_6 . V_9 ) ;
}
if ( V_180 == V_179 )
break;
}
}
return V_172 ;
}
static int F_96 ( struct V_177 * V_33 ,
struct V_1 * V_2 ,
int V_108 )
{
int V_172 ;
V_172 = V_33 -> V_182 ( V_2 , V_108 ) ;
if ( V_172 < 0 )
return V_172 ;
V_172 = V_33 -> V_184 ( V_2 , V_108 ) ;
if ( V_172 == 0 )
V_33 -> V_186 ( V_2 , V_108 ) ;
else if ( V_33 -> V_185 )
V_33 -> V_185 ( V_2 , V_108 ) ;
return V_172 ;
}
static int F_97 ( struct V_177 * V_33 ,
struct V_1 * V_2 ,
int V_108 )
{
int V_172 ;
if ( ! F_98 ( V_2 ) )
return F_96 ( V_33 , V_2 , V_108 ) ;
if ( V_2 -> V_3 -> V_4 ) {
if ( ! F_99 ( & V_2 -> V_187 -> V_7 ) ) {
F_7 ( & V_2 -> V_6 . V_7 ) ;
F_3 ( & V_2 -> V_187 -> V_7 ) ;
F_3 ( & V_2 -> V_6 . V_7 ) ;
}
V_172 = F_92 ( V_33 , V_2 , V_108 , 1 ) ;
F_7 ( & V_2 -> V_187 -> V_7 ) ;
} else {
if ( ! F_100 ( & V_2 -> V_187 -> V_9 ) ) {
F_9 ( & V_2 -> V_6 . V_9 ) ;
F_5 ( & V_2 -> V_187 -> V_9 ) ;
F_5 ( & V_2 -> V_6 . V_9 ) ;
}
V_172 = F_92 ( V_33 , V_2 , V_108 , 1 ) ;
F_9 ( & V_2 -> V_187 -> V_9 ) ;
}
return V_172 ;
}
static int F_101 ( struct V_177 * V_33 ,
struct V_1 * V_2 ,
int V_108 )
{
int V_172 ;
F_11 ( V_2 ) ;
V_172 = F_97 ( V_33 , V_2 , V_108 ) ;
F_13 ( V_2 ) ;
return V_172 ;
}
static int F_102 ( struct V_177 * V_33 ,
struct V_1 * V_2 ,
int V_108 )
{
int V_172 ;
F_2 ( & V_5 ) ;
if ( F_98 ( V_2 ) )
V_172 = F_92 ( V_33 , V_2 , V_108 , 0 ) ;
else
V_172 = F_96 ( V_33 , V_2 , V_108 ) ;
F_8 ( & V_5 ) ;
return V_172 ;
}
static int F_103 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_109 -> V_108 != V_115 )
return - V_116 ;
if ( V_2 -> V_21 == V_154 &&
! F_104 ( V_2 ) )
return - V_188 ;
V_14 -> V_176 = false ;
V_14 -> V_175 = V_2 ;
return 0 ;
}
static int F_105 ( struct V_1 * V_2 , int V_108 )
{
if ( V_2 -> V_14 -> V_175 != V_2 )
return 0 ;
return V_2 -> V_33 -> V_189 ( V_2 , V_190 ) ;
}
static void F_106 ( struct V_1 * V_2 , int V_108 )
{
if ( V_2 -> V_14 -> V_175 == V_2 )
V_2 -> V_33 -> V_189 ( V_2 , V_191 ) ;
}
static void F_107 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_91 ( V_2 ) ;
V_14 -> V_192 = V_193 ;
V_14 -> V_194 = ( V_14 -> V_127 * V_195 ) /
V_14 -> V_106 ;
V_14 -> V_109 -> V_108 = V_108 ;
if ( V_2 -> V_21 == V_154 &&
V_14 -> V_143 > 0 )
F_79 ( V_2 , V_155 ) ;
if ( V_2 -> V_196 )
F_108 ( V_2 -> V_196 , V_197 ,
& V_14 -> V_158 ) ;
}
int F_109 ( struct V_1 * V_2 )
{
return F_97 ( & V_198 , V_2 ,
V_166 ) ;
}
static int F_110 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_109 -> V_108 == V_113 )
return - V_116 ;
V_14 -> V_175 = V_2 ;
return 0 ;
}
static int F_111 ( struct V_1 * V_2 , int V_108 )
{
if ( V_2 -> V_14 -> V_175 == V_2 &&
F_78 ( V_2 ) )
V_2 -> V_33 -> V_189 ( V_2 , V_191 ) ;
return 0 ;
}
static void F_112 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_109 -> V_108 != V_108 ) {
F_91 ( V_2 ) ;
V_14 -> V_109 -> V_108 = V_108 ;
if ( V_2 -> V_196 )
F_108 ( V_2 -> V_196 , V_199 ,
& V_14 -> V_158 ) ;
}
F_113 ( & V_14 -> V_200 ) ;
F_113 ( & V_14 -> V_201 ) ;
}
int F_114 ( struct V_1 * V_2 , T_4 V_108 )
{
return F_97 ( & V_202 , V_2 , V_108 ) ;
}
int F_115 ( struct V_1 * V_2 )
{
return F_96 ( & V_202 , V_2 ,
V_114 ) ;
}
int F_116 ( struct V_1 * V_2 )
{
unsigned long V_10 ;
int V_203 = 0 ;
F_117 ( V_2 , V_10 ) ;
if ( F_78 ( V_2 ) )
V_203 = F_114 ( V_2 , V_204 ) ;
F_17 ( V_2 , V_10 ) ;
return V_203 ;
}
static int F_118 ( struct V_1 * V_2 , int V_205 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( ! ( V_14 -> V_12 & V_206 ) )
return - V_207 ;
if ( V_205 ) {
if ( V_14 -> V_109 -> V_108 != V_166 )
return - V_116 ;
} else if ( V_14 -> V_109 -> V_108 != V_208 )
return - V_116 ;
V_14 -> V_175 = V_2 ;
return 0 ;
}
static int F_119 ( struct V_1 * V_2 , int V_205 )
{
if ( V_2 -> V_14 -> V_175 != V_2 )
return 0 ;
if ( V_205 )
F_84 ( V_2 ) ;
V_2 -> V_14 -> V_192 = V_193 - V_195 * 1000 ;
return V_2 -> V_33 -> V_189 ( V_2 ,
V_205 ? V_209 :
V_210 ) ;
}
static void F_120 ( struct V_1 * V_2 , int V_205 )
{
if ( V_2 -> V_14 -> V_175 == V_2 )
V_2 -> V_33 -> V_189 ( V_2 ,
V_205 ? V_210 :
V_209 ) ;
}
static void F_121 ( struct V_1 * V_2 , int V_205 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_91 ( V_2 ) ;
if ( V_205 ) {
V_14 -> V_109 -> V_108 = V_208 ;
if ( V_2 -> V_196 )
F_108 ( V_2 -> V_196 ,
V_211 ,
& V_14 -> V_158 ) ;
F_113 ( & V_14 -> V_200 ) ;
F_113 ( & V_14 -> V_201 ) ;
} else {
V_14 -> V_109 -> V_108 = V_166 ;
if ( V_2 -> V_196 )
F_108 ( V_2 -> V_196 ,
V_212 ,
& V_14 -> V_158 ) ;
}
}
static int F_122 ( struct V_1 * V_2 , int V_205 )
{
return F_97 ( & V_213 , V_2 , V_205 ) ;
}
static int F_123 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_109 -> V_108 == V_214 )
return - V_215 ;
V_14 -> V_175 = V_2 ;
return 0 ;
}
static int F_124 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_175 != V_2 )
return 0 ;
if ( ! F_78 ( V_2 ) )
return 0 ;
V_2 -> V_33 -> V_189 ( V_2 , V_216 ) ;
return 0 ;
}
static void F_125 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_91 ( V_2 ) ;
V_14 -> V_109 -> V_156 = V_14 -> V_109 -> V_108 ;
V_14 -> V_109 -> V_108 = V_214 ;
if ( V_2 -> V_196 )
F_108 ( V_2 -> V_196 , V_217 ,
& V_14 -> V_158 ) ;
F_113 ( & V_14 -> V_200 ) ;
F_113 ( & V_14 -> V_201 ) ;
}
int F_126 ( struct V_1 * V_2 )
{
int V_37 ;
unsigned long V_10 ;
if ( ! V_2 )
return 0 ;
F_117 ( V_2 , V_10 ) ;
V_37 = F_97 ( & V_218 , V_2 , 0 ) ;
F_17 ( V_2 , V_10 ) ;
return V_37 ;
}
int F_127 ( struct V_15 * V_3 )
{
struct V_1 * V_2 ;
int V_21 , V_37 = 0 ;
if ( ! V_3 )
return 0 ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
for ( V_2 = V_3 -> V_219 [ V_21 ] . V_2 ;
V_2 ; V_2 = V_2 -> V_220 ) {
if ( V_2 -> V_14 == NULL )
continue;
V_37 = F_126 ( V_2 ) ;
if ( V_37 < 0 && V_37 != - V_215 )
return V_37 ;
}
}
return 0 ;
}
static int F_128 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( ! ( V_14 -> V_12 & V_221 ) )
return - V_207 ;
V_14 -> V_175 = V_2 ;
return 0 ;
}
static int F_129 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_175 != V_2 )
return 0 ;
if ( V_14 -> V_109 -> V_156 != V_166 &&
( V_14 -> V_109 -> V_156 != V_167 ||
V_2 -> V_21 != V_154 ) )
return 0 ;
return V_2 -> V_33 -> V_189 ( V_2 , V_222 ) ;
}
static void F_130 ( struct V_1 * V_2 , int V_108 )
{
if ( V_2 -> V_14 -> V_175 == V_2 &&
F_78 ( V_2 ) )
V_2 -> V_33 -> V_189 ( V_2 , V_216 ) ;
}
static void F_131 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_91 ( V_2 ) ;
V_14 -> V_109 -> V_108 = V_14 -> V_109 -> V_156 ;
if ( V_2 -> V_196 )
F_108 ( V_2 -> V_196 , V_223 ,
& V_14 -> V_158 ) ;
}
static int F_132 ( struct V_1 * V_2 )
{
struct V_224 * V_18 = V_2 -> V_3 -> V_18 ;
int V_172 ;
F_133 ( V_18 ) ;
if ( ( V_172 = F_134 ( V_18 , V_225 ) ) >= 0 )
V_172 = F_101 ( & V_226 , V_2 , 0 ) ;
F_135 ( V_18 ) ;
return V_172 ;
}
static int F_132 ( struct V_1 * V_2 )
{
return - V_207 ;
}
static int F_136 ( struct V_1 * V_2 )
{
struct V_224 * V_18 = V_2 -> V_3 -> V_18 ;
struct V_13 * V_14 = V_2 -> V_14 ;
int V_149 ;
F_133 ( V_18 ) ;
if ( V_14 -> V_109 -> V_108 == V_214 ) {
V_149 = F_134 ( V_18 , V_225 ) ;
if ( V_149 < 0 )
goto V_183;
}
F_11 ( V_2 ) ;
switch ( V_14 -> V_109 -> V_108 ) {
case V_204 :
V_149 = 0 ;
break;
case V_166 :
V_149 = F_114 ( V_2 , V_204 ) ;
break;
default:
V_149 = - V_116 ;
}
F_13 ( V_2 ) ;
V_183:
F_135 ( V_18 ) ;
return V_149 ;
}
static int F_137 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
switch ( V_14 -> V_109 -> V_108 ) {
case V_166 :
case V_115 :
case V_208 :
case V_214 :
return 0 ;
default:
return - V_116 ;
}
}
static int F_138 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_37 = V_2 -> V_33 -> V_34 ( V_2 , V_227 , NULL ) ;
if ( V_37 < 0 )
return V_37 ;
V_14 -> V_228 = 0 ;
V_14 -> V_229 = V_14 -> V_109 -> V_164 -
V_14 -> V_109 -> V_164 % V_14 -> V_107 ;
V_14 -> V_230 = V_14 -> V_109 -> V_164 ;
V_14 -> V_231 = 0 ;
return 0 ;
}
static void F_139 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
V_14 -> V_138 -> V_163 = V_14 -> V_109 -> V_164 ;
if ( V_2 -> V_21 == V_154 &&
V_14 -> V_143 > 0 )
F_79 ( V_2 , V_155 ) ;
}
static int F_140 ( struct V_1 * V_2 )
{
return F_102 ( & V_232 , V_2 , 0 ) ;
}
static int F_141 ( struct V_1 * V_2 ,
int V_233 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_109 -> V_108 == V_113 ||
V_14 -> V_109 -> V_108 == V_110 )
return - V_116 ;
if ( F_78 ( V_2 ) )
return - V_215 ;
V_2 -> V_233 = V_233 ;
return 0 ;
}
static int F_142 ( struct V_1 * V_2 , int V_108 )
{
int V_37 ;
V_37 = V_2 -> V_33 -> V_234 ( V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
return F_138 ( V_2 , 0 ) ;
}
static void F_143 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
V_14 -> V_138 -> V_163 = V_14 -> V_109 -> V_164 ;
F_56 ( V_2 , V_115 ) ;
}
static int F_144 ( struct V_1 * V_2 ,
struct V_235 * V_235 )
{
int V_172 ;
struct V_224 * V_18 = V_2 -> V_3 -> V_18 ;
int V_233 ;
if ( V_235 )
V_233 = V_235 -> V_233 ;
else
V_233 = V_2 -> V_233 ;
F_133 ( V_18 ) ;
if ( ( V_172 = F_134 ( V_18 , V_225 ) ) >= 0 )
V_172 = F_102 ( & V_236 ,
V_2 , V_233 ) ;
F_135 ( V_18 ) ;
return V_172 ;
}
static int F_145 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
switch ( V_14 -> V_109 -> V_108 ) {
case V_113 :
case V_110 :
case V_214 :
return - V_116 ;
}
V_14 -> V_175 = V_2 ;
return 0 ;
}
static int F_146 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_2 -> V_21 == V_154 ) {
switch ( V_14 -> V_109 -> V_108 ) {
case V_115 :
if ( ! F_147 ( V_2 ) ) {
F_105 ( V_2 , V_167 ) ;
F_107 ( V_2 , V_167 ) ;
} else {
V_14 -> V_109 -> V_108 = V_114 ;
}
break;
case V_166 :
V_14 -> V_109 -> V_108 = V_167 ;
break;
case V_204 :
V_14 -> V_109 -> V_108 = V_114 ;
break;
default:
break;
}
} else {
if ( V_14 -> V_109 -> V_108 == V_166 ) {
int V_237 = F_87 ( V_14 ) > 0 ?
V_167 : V_114 ;
F_111 ( V_2 , V_237 ) ;
F_112 ( V_2 , V_237 ) ;
}
}
if ( V_14 -> V_109 -> V_108 == V_167 &&
V_14 -> V_175 == V_2 &&
( V_14 -> V_41 . V_12 & V_99 ) )
return V_2 -> V_33 -> V_189 ( V_2 ,
V_238 ) ;
return 0 ;
}
static void F_148 ( struct V_1 * V_2 , int V_108 )
{
}
static int F_149 ( struct V_1 * V_2 ,
struct V_235 * V_235 )
{
struct V_224 * V_18 ;
struct V_13 * V_14 ;
struct V_1 * V_179 ;
T_5 V_239 ;
int V_149 = 0 ;
int V_240 = 0 ;
V_18 = V_2 -> V_3 -> V_18 ;
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_109 -> V_108 == V_113 )
return - V_116 ;
F_133 ( V_18 ) ;
if ( V_14 -> V_109 -> V_108 == V_214 ) {
V_149 = F_134 ( V_18 , V_225 ) ;
if ( V_149 < 0 ) {
F_135 ( V_18 ) ;
return V_149 ;
}
}
if ( V_235 ) {
if ( V_235 -> V_233 & V_241 )
V_240 = 1 ;
} else if ( V_2 -> V_233 & V_241 )
V_240 = 1 ;
F_2 ( & V_5 ) ;
F_11 ( V_2 ) ;
if ( V_14 -> V_109 -> V_108 == V_208 )
F_122 ( V_2 , 0 ) ;
V_149 = F_97 ( & V_242 , V_2 , 0 ) ;
if ( V_149 < 0 )
goto V_243;
if ( V_240 ) {
V_149 = - V_244 ;
goto V_243;
}
for (; ; ) {
long V_245 ;
struct V_13 * V_246 ;
if ( F_150 ( V_247 ) ) {
V_149 = - V_248 ;
break;
}
V_246 = NULL ;
F_93 (s, substream) {
if ( V_179 -> V_21 != V_154 )
continue;
V_14 = V_179 -> V_14 ;
if ( V_14 -> V_109 -> V_108 == V_167 ) {
V_246 = V_14 ;
break;
}
}
if ( ! V_246 )
break;
F_151 ( & V_239 , V_247 ) ;
F_152 ( & V_246 -> V_200 , & V_239 ) ;
F_13 ( V_2 ) ;
F_8 ( & V_5 ) ;
F_135 ( V_18 ) ;
if ( V_14 -> V_128 )
V_245 = V_249 ;
else {
V_245 = 10 ;
if ( V_14 -> V_106 ) {
long V_250 = V_14 -> V_107 * 2 / V_14 -> V_106 ;
V_245 = V_87 ( V_250 , V_245 ) ;
}
V_245 = F_153 ( V_245 * 1000 ) ;
}
V_245 = F_154 ( V_245 ) ;
F_133 ( V_18 ) ;
F_2 ( & V_5 ) ;
F_11 ( V_2 ) ;
F_155 ( & V_246 -> V_200 , & V_239 ) ;
if ( V_18 -> V_251 ) {
V_149 = - V_252 ;
break;
}
if ( V_245 == 0 ) {
if ( V_2 -> V_14 -> V_109 -> V_108 == V_214 )
V_149 = - V_253 ;
else {
F_156 ( V_2 -> V_3 -> V_18 -> V_50 ,
L_12 ) ;
F_114 ( V_2 , V_114 ) ;
V_149 = - V_254 ;
}
break;
}
}
V_243:
F_13 ( V_2 ) ;
F_8 ( & V_5 ) ;
F_135 ( V_18 ) ;
return V_149 ;
}
static int F_157 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
int V_149 = 0 ;
if ( F_57 ( V_2 ) )
return - V_112 ;
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_109 -> V_108 == V_113 ||
V_14 -> V_109 -> V_108 == V_110 ||
V_14 -> V_109 -> V_108 == V_214 )
return - V_116 ;
F_11 ( V_2 ) ;
if ( V_14 -> V_109 -> V_108 == V_208 )
F_122 ( V_2 , 0 ) ;
F_114 ( V_2 , V_114 ) ;
F_13 ( V_2 ) ;
return V_149 ;
}
static bool F_158 ( struct V_235 * V_235 )
{
struct V_255 * V_255 = F_159 ( V_235 ) ;
unsigned int V_256 ;
if ( ! F_160 ( V_255 -> V_257 ) || F_161 ( V_255 ) != V_258 )
return false ;
V_256 = F_162 ( V_255 ) ;
return F_163 ( V_256 , V_259 ) ||
F_163 ( V_256 , V_260 ) ;
}
static int F_164 ( struct V_1 * V_2 , int V_261 )
{
int V_172 = 0 ;
struct V_262 * V_263 ;
struct V_1 * V_264 ;
struct V_265 * V_187 ;
struct V_261 V_266 = F_165 ( V_261 ) ;
if ( ! V_266 . V_235 )
return - V_116 ;
if ( ! F_158 ( V_266 . V_235 ) ) {
V_172 = - V_116 ;
goto V_267;
}
V_263 = V_266 . V_235 -> V_268 ;
V_264 = V_263 -> V_2 ;
V_187 = F_27 ( sizeof( * V_187 ) , V_38 ) ;
if ( ! V_187 ) {
V_172 = - V_39 ;
goto V_269;
}
F_166 ( & V_5 ) ;
F_167 ( & V_8 ) ;
if ( V_2 -> V_14 -> V_109 -> V_108 == V_113 ||
V_2 -> V_14 -> V_109 -> V_108 != V_264 -> V_14 -> V_109 -> V_108 ||
V_2 -> V_3 -> V_4 != V_264 -> V_3 -> V_4 ) {
V_172 = - V_116 ;
goto V_157;
}
if ( F_98 ( V_264 ) ) {
V_172 = - V_270 ;
goto V_157;
}
if ( ! F_98 ( V_2 ) ) {
V_2 -> V_187 = V_187 ;
V_187 = NULL ;
F_168 ( & V_2 -> V_187 -> V_9 ) ;
F_169 ( & V_2 -> V_187 -> V_7 ) ;
F_170 ( & V_2 -> V_187 -> V_271 ) ;
F_171 ( & V_2 -> V_272 , & V_2 -> V_187 -> V_271 ) ;
V_2 -> V_187 -> V_273 = 1 ;
}
F_171 ( & V_264 -> V_272 , & V_2 -> V_187 -> V_271 ) ;
V_2 -> V_187 -> V_273 ++ ;
V_264 -> V_187 = V_2 -> V_187 ;
V_157:
F_172 ( & V_8 ) ;
F_173 ( & V_5 ) ;
V_269:
F_174 ( V_264 -> V_3 -> V_18 ) ;
F_29 ( V_187 ) ;
V_267:
F_175 ( V_266 ) ;
return V_172 ;
}
static void F_176 ( struct V_1 * V_2 )
{
V_2 -> V_187 = & V_2 -> V_6 ;
F_170 ( & V_2 -> V_6 . V_271 ) ;
F_171 ( & V_2 -> V_272 , & V_2 -> V_6 . V_271 ) ;
}
static int F_177 ( struct V_1 * V_2 )
{
struct V_1 * V_179 ;
int V_172 = 0 ;
F_166 ( & V_5 ) ;
F_167 ( & V_8 ) ;
if ( ! F_98 ( V_2 ) ) {
V_172 = - V_270 ;
goto V_157;
}
F_178 ( & V_2 -> V_272 ) ;
V_2 -> V_187 -> V_273 -- ;
if ( V_2 -> V_187 -> V_273 == 1 ) {
F_93 (s, substream) {
F_176 ( V_179 ) ;
break;
}
F_29 ( V_2 -> V_187 ) ;
}
F_176 ( V_2 ) ;
V_157:
F_172 ( & V_8 ) ;
F_173 ( & V_5 ) ;
return V_172 ;
}
static int F_179 ( struct V_52 * V_53 ,
struct V_89 * V_274 )
{
struct V_56 V_250 ;
F_180 ( F_181 ( V_53 , V_274 -> V_95 [ 0 ] ) ,
F_181 ( V_53 , V_274 -> V_95 [ 1 ] ) , & V_250 ) ;
return F_42 ( F_40 ( V_53 , V_274 -> V_97 ) , & V_250 ) ;
}
static int F_182 ( struct V_52 * V_53 ,
struct V_89 * V_274 )
{
struct V_56 V_250 ;
F_183 ( F_181 ( V_53 , V_274 -> V_95 [ 0 ] ) ,
F_181 ( V_53 , V_274 -> V_95 [ 1 ] ) , & V_250 ) ;
return F_42 ( F_40 ( V_53 , V_274 -> V_97 ) , & V_250 ) ;
}
static int F_184 ( struct V_52 * V_53 ,
struct V_89 * V_274 )
{
struct V_56 V_250 ;
F_185 ( F_181 ( V_53 , V_274 -> V_95 [ 0 ] ) ,
F_181 ( V_53 , V_274 -> V_95 [ 1 ] ) ,
( unsigned long ) V_274 -> V_275 , & V_250 ) ;
return F_42 ( F_40 ( V_53 , V_274 -> V_97 ) , & V_250 ) ;
}
static int F_186 ( struct V_52 * V_53 ,
struct V_89 * V_274 )
{
struct V_56 V_250 ;
F_187 ( F_181 ( V_53 , V_274 -> V_95 [ 0 ] ) ,
( unsigned long ) V_274 -> V_275 ,
F_181 ( V_53 , V_274 -> V_95 [ 1 ] ) , & V_250 ) ;
return F_42 ( F_40 ( V_53 , V_274 -> V_97 ) , & V_250 ) ;
}
static int F_188 ( struct V_52 * V_53 ,
struct V_89 * V_274 )
{
unsigned int V_54 ;
struct V_56 * V_57 = F_40 ( V_53 , V_274 -> V_95 [ 0 ] ) ;
struct V_58 V_59 ;
struct V_58 * V_276 = F_33 ( V_53 , V_101 ) ;
F_189 ( & V_59 ) ;
for ( V_54 = 0 ; V_54 <= V_277 ; ++ V_54 ) {
int V_81 ;
if ( ! F_190 ( V_276 , V_54 ) )
continue;
V_81 = F_69 ( V_54 ) ;
if ( V_81 <= 0 )
continue;
if ( ( unsigned ) V_81 < V_57 -> V_86 || ( unsigned ) V_81 > V_57 -> V_87 )
F_191 ( & V_59 , V_54 ) ;
}
return F_38 ( V_276 , & V_59 ) ;
}
static int F_192 ( struct V_52 * V_53 ,
struct V_89 * V_274 )
{
struct V_56 V_250 ;
unsigned int V_54 ;
V_250 . V_86 = V_278 ;
V_250 . V_87 = 0 ;
V_250 . V_85 = 0 ;
V_250 . V_88 = 0 ;
for ( V_54 = 0 ; V_54 <= V_277 ; ++ V_54 ) {
int V_81 ;
if ( ! F_190 ( F_33 ( V_53 , V_101 ) , V_54 ) )
continue;
V_81 = F_69 ( V_54 ) ;
if ( V_81 <= 0 )
continue;
if ( V_250 . V_86 > ( unsigned ) V_81 )
V_250 . V_86 = V_81 ;
if ( V_250 . V_87 < ( unsigned ) V_81 )
V_250 . V_87 = V_81 ;
}
V_250 . integer = 1 ;
return F_42 ( F_40 ( V_53 , V_274 -> V_97 ) , & V_250 ) ;
}
static int F_193 ( struct V_52 * V_53 ,
struct V_89 * V_274 )
{
struct V_55 * V_41 = V_274 -> V_275 ;
return F_194 ( F_40 ( V_53 , V_274 -> V_97 ) ,
V_279 . V_273 ,
V_279 . V_280 , V_41 -> V_281 ) ;
}
static int F_195 ( struct V_52 * V_53 ,
struct V_89 * V_274 )
{
struct V_56 V_250 ;
struct V_1 * V_2 = V_274 -> V_275 ;
V_250 . V_86 = 0 ;
V_250 . V_87 = V_2 -> V_282 ;
V_250 . V_85 = 0 ;
V_250 . V_88 = 0 ;
V_250 . integer = 1 ;
return F_42 ( F_40 ( V_53 , V_274 -> V_97 ) , & V_250 ) ;
}
int F_196 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_60 * V_61 = & V_14 -> V_62 ;
int V_54 , V_37 ;
for ( V_54 = V_77 ; V_54 <= V_78 ; V_54 ++ ) {
F_189 ( F_39 ( V_61 , V_54 ) ) ;
}
for ( V_54 = V_83 ; V_54 <= V_66 ; V_54 ++ ) {
F_197 ( F_43 ( V_61 , V_54 ) ) ;
}
F_198 ( F_43 ( V_61 , V_102 ) ) ;
F_198 ( F_43 ( V_61 , V_283 ) ) ;
F_198 ( F_43 ( V_61 , V_284 ) ) ;
F_198 ( F_43 ( V_61 , V_72 ) ) ;
F_198 ( F_43 ( V_61 , V_285 ) ) ;
V_37 = F_199 ( V_14 , 0 , V_101 ,
F_188 , NULL ,
V_72 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_72 ,
F_192 , NULL ,
V_101 ,
V_72 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_72 ,
F_182 , NULL ,
V_285 , V_102 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_285 ,
F_179 , NULL ,
V_72 , V_102 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_285 ,
F_186 , ( void * ) 8 ,
V_286 , V_287 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_285 ,
F_186 , ( void * ) 8 ,
V_284 , V_283 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_102 ,
F_182 , NULL ,
V_285 , V_72 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_74 ,
F_186 , ( void * ) 1000000 ,
V_287 , V_288 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_74 ,
F_186 , ( void * ) 1000000 ,
V_283 , V_289 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_290 ,
F_182 , NULL ,
V_283 , V_287 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_287 ,
F_182 , NULL ,
V_283 , V_290 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_287 ,
F_186 , ( void * ) 8 ,
V_286 , V_285 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_287 ,
F_184 , ( void * ) 1000000 ,
V_288 , V_74 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_283 ,
F_179 , NULL ,
V_287 , V_290 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_283 ,
F_186 , ( void * ) 8 ,
V_284 , V_285 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_283 ,
F_184 , ( void * ) 1000000 ,
V_289 , V_74 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_286 ,
F_184 , ( void * ) 8 ,
V_287 , V_285 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_284 ,
F_184 , ( void * ) 8 ,
V_283 , V_285 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_288 ,
F_186 , ( void * ) 1000000 ,
V_287 , V_74 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_289 ,
F_186 , ( void * ) 1000000 ,
V_283 , V_74 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
return 0 ;
}
int F_200 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_55 * V_41 = & V_14 -> V_41 ;
int V_37 ;
unsigned int V_276 = 0 ;
if ( V_41 -> V_12 & V_291 )
V_276 |= 1 << V_292 ;
if ( V_41 -> V_12 & V_293 )
V_276 |= 1 << V_294 ;
if ( F_30 ( V_2 ) ) {
if ( V_41 -> V_12 & V_291 )
V_276 |= 1 << V_295 ;
if ( V_41 -> V_12 & V_293 )
V_276 |= 1 << V_296 ;
if ( V_41 -> V_12 & V_297 )
V_276 |= 1 << V_298 ;
}
V_37 = F_201 ( V_14 , V_299 , V_276 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_202 ( V_14 , V_101 , V_41 -> V_300 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_201 ( V_14 , V_301 , 1 << V_302 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_203 ( V_14 , V_102 ,
V_41 -> V_303 , V_41 -> V_304 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_203 ( V_14 , V_74 ,
V_41 -> V_305 , V_41 -> V_306 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_203 ( V_14 , V_286 ,
V_41 -> V_307 , V_41 -> V_308 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_203 ( V_14 , V_290 ,
V_41 -> V_309 , V_41 -> V_310 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_203 ( V_14 , V_284 ,
V_41 -> V_307 , V_41 -> V_282 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_284 ,
F_195 , V_2 ,
V_284 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_14 -> V_311 ) {
V_37 = F_203 ( V_14 , V_284 , 0 , V_14 -> V_311 ) ;
if ( V_37 < 0 )
return V_37 ;
}
if ( ! ( V_41 -> V_281 & ( V_312 | V_313 ) ) ) {
V_37 = F_199 ( V_14 , 0 , V_74 ,
F_193 , V_41 ,
V_74 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
}
F_204 ( V_14 , V_287 ) ;
return 0 ;
}
static void F_205 ( struct V_1 * V_2 )
{
F_177 ( V_2 ) ;
}
void F_206 ( struct V_1 * V_2 )
{
V_2 -> V_314 -- ;
if ( V_2 -> V_314 > 0 )
return;
F_157 ( V_2 ) ;
if ( V_2 -> V_315 ) {
if ( V_2 -> V_33 -> V_148 != NULL )
V_2 -> V_33 -> V_148 ( V_2 ) ;
V_2 -> V_33 -> V_316 ( V_2 ) ;
V_2 -> V_315 = 0 ;
}
if ( F_71 ( & V_2 -> V_146 ) )
F_72 ( & V_2 -> V_146 ) ;
if ( V_2 -> V_317 ) {
V_2 -> V_317 ( V_2 ) ;
V_2 -> V_317 = NULL ;
}
F_207 ( V_2 ) ;
}
int F_208 ( struct V_15 * V_3 , int V_21 ,
struct V_235 * V_235 ,
struct V_1 * * V_318 )
{
struct V_1 * V_2 ;
int V_37 ;
V_37 = F_209 ( V_3 , V_21 , V_235 , & V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_2 -> V_314 > 1 ) {
* V_318 = V_2 ;
return 0 ;
}
V_37 = F_196 ( V_2 ) ;
if ( V_37 < 0 ) {
F_210 ( V_3 , L_13 ) ;
goto error;
}
if ( ( V_37 = V_2 -> V_33 -> V_319 ( V_2 ) ) < 0 )
goto error;
V_2 -> V_315 = 1 ;
V_37 = F_200 ( V_2 ) ;
if ( V_37 < 0 ) {
F_210 ( V_3 , L_14 ) ;
goto error;
}
* V_318 = V_2 ;
return 0 ;
error:
F_206 ( V_2 ) ;
return V_37 ;
}
static int F_211 ( struct V_235 * V_235 ,
struct V_15 * V_3 ,
int V_21 )
{
struct V_262 * V_263 ;
struct V_1 * V_2 ;
int V_37 ;
V_37 = F_208 ( V_3 , V_21 , V_235 , & V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
V_263 = F_212 ( sizeof( * V_263 ) , V_38 ) ;
if ( V_263 == NULL ) {
F_206 ( V_2 ) ;
return - V_39 ;
}
V_263 -> V_2 = V_2 ;
if ( V_2 -> V_314 == 1 ) {
V_2 -> V_235 = V_263 ;
V_2 -> V_317 = F_205 ;
}
V_235 -> V_268 = V_263 ;
return 0 ;
}
static int F_213 ( struct V_255 * V_255 , struct V_235 * V_235 )
{
struct V_15 * V_3 ;
int V_37 = F_214 ( V_255 , V_235 ) ;
if ( V_37 < 0 )
return V_37 ;
V_3 = F_163 ( F_162 ( V_255 ) ,
V_259 ) ;
V_37 = F_215 ( V_235 , V_3 , V_154 ) ;
if ( V_3 )
F_174 ( V_3 -> V_18 ) ;
return V_37 ;
}
static int F_216 ( struct V_255 * V_255 , struct V_235 * V_235 )
{
struct V_15 * V_3 ;
int V_37 = F_214 ( V_255 , V_235 ) ;
if ( V_37 < 0 )
return V_37 ;
V_3 = F_163 ( F_162 ( V_255 ) ,
V_260 ) ;
V_37 = F_215 ( V_235 , V_3 , V_320 ) ;
if ( V_3 )
F_174 ( V_3 -> V_18 ) ;
return V_37 ;
}
static int F_215 ( struct V_235 * V_235 , struct V_15 * V_3 , int V_21 )
{
int V_37 ;
T_5 V_239 ;
if ( V_3 == NULL ) {
V_37 = - V_252 ;
goto V_321;
}
V_37 = F_217 ( V_3 -> V_18 , V_235 ) ;
if ( V_37 < 0 )
goto V_321;
if ( ! F_218 ( V_3 -> V_18 -> V_322 ) ) {
V_37 = - V_40 ;
goto V_323;
}
F_151 ( & V_239 , V_247 ) ;
F_152 ( & V_3 -> V_324 , & V_239 ) ;
F_3 ( & V_3 -> V_325 ) ;
while ( 1 ) {
V_37 = F_211 ( V_235 , V_3 , V_21 ) ;
if ( V_37 >= 0 )
break;
if ( V_37 == - V_244 ) {
if ( V_235 -> V_233 & V_241 ) {
V_37 = - V_215 ;
break;
}
} else
break;
F_219 ( V_326 ) ;
F_7 ( & V_3 -> V_325 ) ;
F_220 () ;
F_3 ( & V_3 -> V_325 ) ;
if ( V_3 -> V_18 -> V_251 ) {
V_37 = - V_252 ;
break;
}
if ( F_150 ( V_247 ) ) {
V_37 = - V_248 ;
break;
}
}
F_155 ( & V_3 -> V_324 , & V_239 ) ;
F_7 ( & V_3 -> V_325 ) ;
if ( V_37 < 0 )
goto V_327;
return V_37 ;
V_327:
F_221 ( V_3 -> V_18 -> V_322 ) ;
V_323:
F_222 ( V_3 -> V_18 , V_235 ) ;
V_321:
return V_37 ;
}
static int F_223 ( struct V_255 * V_255 , struct V_235 * V_235 )
{
struct V_15 * V_3 ;
struct V_1 * V_2 ;
struct V_262 * V_263 ;
V_263 = V_235 -> V_268 ;
V_2 = V_263 -> V_2 ;
if ( F_224 ( ! V_2 ) )
return - V_112 ;
V_3 = V_2 -> V_3 ;
F_3 ( & V_3 -> V_325 ) ;
F_206 ( V_2 ) ;
F_29 ( V_263 ) ;
F_7 ( & V_3 -> V_325 ) ;
F_113 ( & V_3 -> V_324 ) ;
F_221 ( V_3 -> V_18 -> V_322 ) ;
F_222 ( V_3 -> V_18 , V_235 ) ;
return 0 ;
}
static T_6 F_225 ( struct V_1 * V_2 ,
T_3 V_111 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 V_163 ;
T_6 V_203 ;
T_6 V_328 ;
if ( V_111 == 0 )
return 0 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_109 -> V_108 ) {
case V_115 :
break;
case V_167 :
case V_166 :
if ( F_84 ( V_2 ) >= 0 )
break;
case V_204 :
V_203 = - V_188 ;
goto V_329;
case V_214 :
V_203 = - V_253 ;
goto V_329;
default:
V_203 = - V_116 ;
goto V_329;
}
V_328 = F_226 ( V_14 ) ;
if ( V_328 <= 0 ) {
V_203 = 0 ;
goto V_329;
}
if ( V_111 > ( T_3 ) V_328 )
V_111 = V_328 ;
V_163 = V_14 -> V_138 -> V_163 - V_111 ;
if ( V_163 < 0 )
V_163 += V_14 -> V_144 ;
V_14 -> V_138 -> V_163 = V_163 ;
V_203 = V_111 ;
V_329:
F_13 ( V_2 ) ;
return V_203 ;
}
static T_6 F_227 ( struct V_1 * V_2 ,
T_3 V_111 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 V_163 ;
T_6 V_203 ;
T_6 V_328 ;
if ( V_111 == 0 )
return 0 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_109 -> V_108 ) {
case V_115 :
case V_167 :
break;
case V_166 :
if ( F_84 ( V_2 ) >= 0 )
break;
case V_204 :
V_203 = - V_188 ;
goto V_329;
case V_214 :
V_203 = - V_253 ;
goto V_329;
default:
V_203 = - V_116 ;
goto V_329;
}
V_328 = F_228 ( V_14 ) ;
if ( V_328 <= 0 ) {
V_203 = 0 ;
goto V_329;
}
if ( V_111 > ( T_3 ) V_328 )
V_111 = V_328 ;
V_163 = V_14 -> V_138 -> V_163 - V_111 ;
if ( V_163 < 0 )
V_163 += V_14 -> V_144 ;
V_14 -> V_138 -> V_163 = V_163 ;
V_203 = V_111 ;
V_329:
F_13 ( V_2 ) ;
return V_203 ;
}
static T_6 F_229 ( struct V_1 * V_2 ,
T_3 V_111 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 V_163 ;
T_6 V_203 ;
T_6 V_165 ;
if ( V_111 == 0 )
return 0 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_109 -> V_108 ) {
case V_115 :
case V_208 :
break;
case V_167 :
case V_166 :
if ( F_84 ( V_2 ) >= 0 )
break;
case V_204 :
V_203 = - V_188 ;
goto V_329;
case V_214 :
V_203 = - V_253 ;
goto V_329;
default:
V_203 = - V_116 ;
goto V_329;
}
V_165 = F_86 ( V_14 ) ;
if ( V_165 <= 0 ) {
V_203 = 0 ;
goto V_329;
}
if ( V_111 > ( T_3 ) V_165 )
V_111 = V_165 ;
V_163 = V_14 -> V_138 -> V_163 + V_111 ;
if ( V_163 >= ( T_6 ) V_14 -> V_144 )
V_163 -= V_14 -> V_144 ;
V_14 -> V_138 -> V_163 = V_163 ;
V_203 = V_111 ;
V_329:
F_13 ( V_2 ) ;
return V_203 ;
}
static T_6 F_230 ( struct V_1 * V_2 ,
T_3 V_111 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 V_163 ;
T_6 V_203 ;
T_6 V_165 ;
if ( V_111 == 0 )
return 0 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_109 -> V_108 ) {
case V_115 :
case V_167 :
case V_208 :
break;
case V_166 :
if ( F_84 ( V_2 ) >= 0 )
break;
case V_204 :
V_203 = - V_188 ;
goto V_329;
case V_214 :
V_203 = - V_253 ;
goto V_329;
default:
V_203 = - V_116 ;
goto V_329;
}
V_165 = F_87 ( V_14 ) ;
if ( V_165 <= 0 ) {
V_203 = 0 ;
goto V_329;
}
if ( V_111 > ( T_3 ) V_165 )
V_111 = V_165 ;
V_163 = V_14 -> V_138 -> V_163 + V_111 ;
if ( V_163 >= ( T_6 ) V_14 -> V_144 )
V_163 -= V_14 -> V_144 ;
V_14 -> V_138 -> V_163 = V_163 ;
V_203 = V_111 ;
V_329:
F_13 ( V_2 ) ;
return V_203 ;
}
static int F_231 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_37 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_109 -> V_108 ) {
case V_167 :
if ( V_2 -> V_21 == V_320 )
goto V_330;
case V_166 :
if ( ( V_37 = F_84 ( V_2 ) ) < 0 )
break;
case V_115 :
case V_214 :
V_37 = 0 ;
break;
case V_204 :
V_37 = - V_188 ;
break;
default:
V_330:
V_37 = - V_116 ;
break;
}
F_13 ( V_2 ) ;
return V_37 ;
}
static int F_232 ( struct V_1 * V_2 ,
T_6 T_2 * V_172 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_37 ;
T_6 V_331 = 0 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_109 -> V_108 ) {
case V_167 :
if ( V_2 -> V_21 == V_320 )
goto V_330;
case V_166 :
if ( ( V_37 = F_84 ( V_2 ) ) < 0 )
break;
case V_115 :
case V_214 :
V_37 = 0 ;
if ( V_2 -> V_21 == V_154 )
V_331 = F_226 ( V_14 ) ;
else
V_331 = F_87 ( V_14 ) ;
V_331 += V_14 -> V_168 ;
break;
case V_204 :
V_37 = - V_188 ;
break;
default:
V_330:
V_37 = - V_116 ;
break;
}
F_13 ( V_2 ) ;
if ( ! V_37 )
if ( F_233 ( V_331 , V_172 ) )
V_37 = - V_40 ;
return V_37 ;
}
static int F_234 ( struct V_1 * V_2 ,
struct F_234 T_2 * V_332 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct F_234 V_333 ;
volatile struct V_334 * V_109 ;
volatile struct V_335 * V_138 ;
int V_37 ;
memset ( & V_333 , 0 , sizeof( V_333 ) ) ;
if ( F_235 ( V_333 . V_10 , ( unsigned T_2 * ) & ( V_332 -> V_10 ) ) )
return - V_40 ;
if ( F_82 ( & V_333 . V_336 . V_138 , & ( V_332 -> V_336 . V_138 ) , sizeof( struct V_335 ) ) )
return - V_40 ;
V_109 = V_14 -> V_109 ;
V_138 = V_14 -> V_138 ;
if ( V_333 . V_10 & V_337 ) {
V_37 = F_231 ( V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
}
F_11 ( V_2 ) ;
if ( ! ( V_333 . V_10 & V_338 ) )
V_138 -> V_163 = V_333 . V_336 . V_138 . V_163 ;
else
V_333 . V_336 . V_138 . V_163 = V_138 -> V_163 ;
if ( ! ( V_333 . V_10 & V_339 ) )
V_138 -> V_139 = V_333 . V_336 . V_138 . V_139 ;
else
V_333 . V_336 . V_138 . V_139 = V_138 -> V_139 ;
V_333 . V_179 . V_109 . V_108 = V_109 -> V_108 ;
V_333 . V_179 . V_109 . V_164 = V_109 -> V_164 ;
V_333 . V_179 . V_109 . V_160 = V_109 -> V_160 ;
V_333 . V_179 . V_109 . V_156 = V_109 -> V_156 ;
F_13 ( V_2 ) ;
if ( F_28 ( V_332 , & V_333 , sizeof( V_333 ) ) )
return - V_40 ;
return 0 ;
}
static int F_236 ( struct V_1 * V_2 , int T_2 * V_340 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_341 ;
if ( F_235 ( V_341 , V_340 ) )
return - V_40 ;
if ( V_341 < 0 || V_341 > V_153 )
return - V_79 ;
V_14 -> V_152 = V_341 ;
return 0 ;
}
static int F_237 ( struct V_235 * V_235 ,
struct V_1 * V_2 ,
unsigned int V_342 , void T_2 * V_341 )
{
switch ( V_342 ) {
case V_343 :
return F_233 ( V_344 , ( int T_2 * ) V_341 ) ? - V_40 : 0 ;
case V_345 :
return F_26 ( V_2 , V_341 ) ;
case V_346 :
return 0 ;
case V_347 :
return F_236 ( V_2 , V_341 ) ;
case V_348 :
return F_51 ( V_2 , V_341 ) ;
case V_349 :
return F_74 ( V_2 , V_341 ) ;
case V_350 :
return F_75 ( V_2 ) ;
case V_351 :
return F_81 ( V_2 , V_341 ) ;
case V_352 :
return F_88 ( V_2 , V_341 ) ;
case V_353 :
return F_90 ( V_2 , V_341 ) ;
case V_354 :
return F_144 ( V_2 , V_235 ) ;
case V_355 :
return F_140 ( V_2 ) ;
case V_356 :
return F_101 ( & V_198 , V_2 , V_166 ) ;
case V_357 :
return F_164 ( V_2 , ( int ) ( unsigned long ) V_341 ) ;
case V_358 :
return F_177 ( V_2 ) ;
case V_359 :
return F_132 ( V_2 ) ;
case V_360 :
return F_136 ( V_2 ) ;
case V_361 :
return F_231 ( V_2 ) ;
case V_362 :
return F_232 ( V_2 , V_341 ) ;
case V_363 :
return F_234 ( V_2 , V_341 ) ;
#ifdef F_238
case V_364 :
return F_239 ( V_2 , V_341 ) ;
case V_365 :
return F_240 ( V_2 , V_341 ) ;
#endif
case V_366 :
return F_149 ( V_2 , V_235 ) ;
case V_367 :
return F_157 ( V_2 ) ;
case V_368 :
{
int V_172 ;
F_11 ( V_2 ) ;
V_172 = F_122 ( V_2 , ( int ) ( unsigned long ) V_341 ) ;
F_13 ( V_2 ) ;
return V_172 ;
}
}
F_210 ( V_2 -> V_3 , L_15 , V_342 ) ;
return - V_369 ;
}
static int F_241 ( struct V_235 * V_235 ,
struct V_1 * V_2 ,
unsigned int V_342 , void T_2 * V_341 )
{
if ( F_224 ( ! V_2 ) )
return - V_112 ;
if ( F_224 ( V_2 -> V_21 != V_154 ) )
return - V_79 ;
switch ( V_342 ) {
case V_370 :
{
struct V_371 V_372 ;
struct V_371 T_2 * V_373 = V_341 ;
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 V_149 ;
if ( V_14 -> V_109 -> V_108 == V_113 )
return - V_116 ;
if ( F_233 ( 0 , & V_373 -> V_149 ) )
return - V_40 ;
if ( F_82 ( & V_372 , V_373 , sizeof( V_372 ) ) )
return - V_40 ;
V_149 = F_242 ( V_2 , V_372 . V_374 , V_372 . V_111 ) ;
F_243 ( V_149 , & V_373 -> V_149 ) ;
return V_149 < 0 ? V_149 : 0 ;
}
case V_375 :
{
struct V_376 V_377 ;
struct V_376 T_2 * V_378 = V_341 ;
struct V_13 * V_14 = V_2 -> V_14 ;
void T_2 * * V_379 ;
T_6 V_149 ;
if ( V_14 -> V_109 -> V_108 == V_113 )
return - V_116 ;
if ( V_14 -> V_125 > 128 )
return - V_79 ;
if ( F_233 ( 0 , & V_378 -> V_149 ) )
return - V_40 ;
if ( F_82 ( & V_377 , V_378 , sizeof( V_377 ) ) )
return - V_40 ;
V_379 = F_52 ( V_377 . V_379 ,
sizeof( void * ) * V_14 -> V_125 ) ;
if ( F_53 ( V_379 ) )
return F_54 ( V_379 ) ;
V_149 = F_244 ( V_2 , V_379 , V_377 . V_111 ) ;
F_29 ( V_379 ) ;
F_243 ( V_149 , & V_378 -> V_149 ) ;
return V_149 < 0 ? V_149 : 0 ;
}
case V_380 :
{
T_3 V_111 ;
T_3 T_2 * V_381 = V_341 ;
T_6 V_149 ;
if ( F_235 ( V_111 , V_381 ) )
return - V_40 ;
if ( F_233 ( 0 , V_381 ) )
return - V_40 ;
V_149 = F_225 ( V_2 , V_111 ) ;
F_243 ( V_149 , V_381 ) ;
return V_149 < 0 ? V_149 : 0 ;
}
case V_382 :
{
T_3 V_111 ;
T_3 T_2 * V_381 = V_341 ;
T_6 V_149 ;
if ( F_235 ( V_111 , V_381 ) )
return - V_40 ;
if ( F_233 ( 0 , V_381 ) )
return - V_40 ;
V_149 = F_229 ( V_2 , V_111 ) ;
F_243 ( V_149 , V_381 ) ;
return V_149 < 0 ? V_149 : 0 ;
}
}
return F_237 ( V_235 , V_2 , V_342 , V_341 ) ;
}
static int F_245 ( struct V_235 * V_235 ,
struct V_1 * V_2 ,
unsigned int V_342 , void T_2 * V_341 )
{
if ( F_224 ( ! V_2 ) )
return - V_112 ;
if ( F_224 ( V_2 -> V_21 != V_320 ) )
return - V_79 ;
switch ( V_342 ) {
case V_383 :
{
struct V_371 V_372 ;
struct V_371 T_2 * V_373 = V_341 ;
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 V_149 ;
if ( V_14 -> V_109 -> V_108 == V_113 )
return - V_116 ;
if ( F_233 ( 0 , & V_373 -> V_149 ) )
return - V_40 ;
if ( F_82 ( & V_372 , V_373 , sizeof( V_372 ) ) )
return - V_40 ;
V_149 = F_246 ( V_2 , V_372 . V_374 , V_372 . V_111 ) ;
F_243 ( V_149 , & V_373 -> V_149 ) ;
return V_149 < 0 ? V_149 : 0 ;
}
case V_384 :
{
struct V_376 V_377 ;
struct V_376 T_2 * V_378 = V_341 ;
struct V_13 * V_14 = V_2 -> V_14 ;
void * V_379 ;
T_6 V_149 ;
if ( V_14 -> V_109 -> V_108 == V_113 )
return - V_116 ;
if ( V_14 -> V_125 > 128 )
return - V_79 ;
if ( F_233 ( 0 , & V_378 -> V_149 ) )
return - V_40 ;
if ( F_82 ( & V_377 , V_378 , sizeof( V_377 ) ) )
return - V_40 ;
V_379 = F_52 ( V_377 . V_379 ,
sizeof( void * ) * V_14 -> V_125 ) ;
if ( F_53 ( V_379 ) )
return F_54 ( V_379 ) ;
V_149 = F_247 ( V_2 , V_379 , V_377 . V_111 ) ;
F_29 ( V_379 ) ;
F_243 ( V_149 , & V_378 -> V_149 ) ;
return V_149 < 0 ? V_149 : 0 ;
}
case V_380 :
{
T_3 V_111 ;
T_3 T_2 * V_381 = V_341 ;
T_6 V_149 ;
if ( F_235 ( V_111 , V_381 ) )
return - V_40 ;
if ( F_233 ( 0 , V_381 ) )
return - V_40 ;
V_149 = F_227 ( V_2 , V_111 ) ;
F_243 ( V_149 , V_381 ) ;
return V_149 < 0 ? V_149 : 0 ;
}
case V_382 :
{
T_3 V_111 ;
T_3 T_2 * V_381 = V_341 ;
T_6 V_149 ;
if ( F_235 ( V_111 , V_381 ) )
return - V_40 ;
if ( F_233 ( 0 , V_381 ) )
return - V_40 ;
V_149 = F_230 ( V_2 , V_111 ) ;
F_243 ( V_149 , V_381 ) ;
return V_149 < 0 ? V_149 : 0 ;
}
}
return F_237 ( V_235 , V_2 , V_342 , V_341 ) ;
}
static long F_248 ( struct V_235 * V_235 , unsigned int V_342 ,
unsigned long V_341 )
{
struct V_262 * V_263 ;
V_263 = V_235 -> V_268 ;
if ( ( ( V_342 >> 8 ) & 0xff ) != 'A' )
return - V_369 ;
return F_241 ( V_235 , V_263 -> V_2 , V_342 ,
( void T_2 * ) V_341 ) ;
}
static long F_249 ( struct V_235 * V_235 , unsigned int V_342 ,
unsigned long V_341 )
{
struct V_262 * V_263 ;
V_263 = V_235 -> V_268 ;
if ( ( ( V_342 >> 8 ) & 0xff ) != 'A' )
return - V_369 ;
return F_245 ( V_235 , V_263 -> V_2 , V_342 ,
( void T_2 * ) V_341 ) ;
}
int F_250 ( struct V_1 * V_2 ,
unsigned int V_342 , void * V_341 )
{
T_1 V_11 ;
int V_149 ;
V_11 = F_19 () ;
switch ( V_2 -> V_21 ) {
case V_154 :
V_149 = F_241 ( NULL , V_2 , V_342 ,
( void T_2 * ) V_341 ) ;
break;
case V_320 :
V_149 = F_245 ( NULL , V_2 , V_342 ,
( void T_2 * ) V_341 ) ;
break;
default:
V_149 = - V_79 ;
break;
}
F_23 ( V_11 ) ;
return V_149 ;
}
static T_7 F_251 ( struct V_235 * V_235 , char T_2 * V_374 , T_8 V_273 ,
T_9 * V_385 )
{
struct V_262 * V_263 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
T_6 V_149 ;
V_263 = V_235 -> V_268 ;
V_2 = V_263 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_112 ;
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_109 -> V_108 == V_113 )
return - V_116 ;
if ( ! F_252 ( V_14 , V_273 ) )
return - V_79 ;
V_273 = F_253 ( V_14 , V_273 ) ;
V_149 = F_246 ( V_2 , V_374 , V_273 ) ;
if ( V_149 > 0 )
V_149 = F_254 ( V_14 , V_149 ) ;
return V_149 ;
}
static T_7 F_255 ( struct V_235 * V_235 , const char T_2 * V_374 ,
T_8 V_273 , T_9 * V_385 )
{
struct V_262 * V_263 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
T_6 V_149 ;
V_263 = V_235 -> V_268 ;
V_2 = V_263 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_112 ;
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_109 -> V_108 == V_113 )
return - V_116 ;
if ( ! F_252 ( V_14 , V_273 ) )
return - V_79 ;
V_273 = F_253 ( V_14 , V_273 ) ;
V_149 = F_242 ( V_2 , V_374 , V_273 ) ;
if ( V_149 > 0 )
V_149 = F_254 ( V_14 , V_149 ) ;
return V_149 ;
}
static T_7 F_256 ( struct V_386 * V_387 , const struct V_388 * V_389 ,
unsigned long V_390 , T_9 V_391 )
{
struct V_262 * V_263 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
T_6 V_149 ;
unsigned long V_57 ;
void T_2 * * V_379 ;
T_3 V_111 ;
V_263 = V_387 -> V_392 -> V_268 ;
V_2 = V_263 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_112 ;
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_109 -> V_108 == V_113 )
return - V_116 ;
if ( V_390 > 1024 || V_390 != V_14 -> V_125 )
return - V_79 ;
if ( ! F_252 ( V_14 , V_389 -> V_393 ) )
return - V_79 ;
V_111 = F_257 ( V_14 , V_389 -> V_393 ) ;
V_379 = F_27 ( sizeof( void * ) * V_390 , V_38 ) ;
if ( V_379 == NULL )
return - V_39 ;
for ( V_57 = 0 ; V_57 < V_390 ; ++ V_57 )
V_379 [ V_57 ] = V_389 [ V_57 ] . V_394 ;
V_149 = F_247 ( V_2 , V_379 , V_111 ) ;
if ( V_149 > 0 )
V_149 = F_254 ( V_14 , V_149 ) ;
F_29 ( V_379 ) ;
return V_149 ;
}
static T_7 F_258 ( struct V_386 * V_387 , const struct V_388 * V_389 ,
unsigned long V_390 , T_9 V_391 )
{
struct V_262 * V_263 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
T_6 V_149 ;
unsigned long V_57 ;
void T_2 * * V_379 ;
T_3 V_111 ;
V_263 = V_387 -> V_392 -> V_268 ;
V_2 = V_263 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_112 ;
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_109 -> V_108 == V_113 )
return - V_116 ;
if ( V_390 > 128 || V_390 != V_14 -> V_125 ||
! F_252 ( V_14 , V_389 -> V_393 ) )
return - V_79 ;
V_111 = F_257 ( V_14 , V_389 -> V_393 ) ;
V_379 = F_27 ( sizeof( void * ) * V_390 , V_38 ) ;
if ( V_379 == NULL )
return - V_39 ;
for ( V_57 = 0 ; V_57 < V_390 ; ++ V_57 )
V_379 [ V_57 ] = V_389 [ V_57 ] . V_394 ;
V_149 = F_244 ( V_2 , V_379 , V_111 ) ;
if ( V_149 > 0 )
V_149 = F_254 ( V_14 , V_149 ) ;
F_29 ( V_379 ) ;
return V_149 ;
}
static unsigned int F_259 ( struct V_235 * V_235 , T_10 * V_239 )
{
struct V_262 * V_263 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
unsigned int V_276 ;
T_3 V_165 ;
V_263 = V_235 -> V_268 ;
V_2 = V_263 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_112 ;
V_14 = V_2 -> V_14 ;
F_260 ( V_235 , & V_14 -> V_200 , V_239 ) ;
F_11 ( V_2 ) ;
V_165 = F_86 ( V_14 ) ;
switch ( V_14 -> V_109 -> V_108 ) {
case V_166 :
case V_115 :
case V_208 :
if ( V_165 >= V_14 -> V_138 -> V_139 ) {
V_276 = V_395 | V_396 ;
break;
}
case V_167 :
V_276 = 0 ;
break;
default:
V_276 = V_395 | V_396 | V_397 ;
break;
}
F_13 ( V_2 ) ;
return V_276 ;
}
static unsigned int F_261 ( struct V_235 * V_235 , T_10 * V_239 )
{
struct V_262 * V_263 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
unsigned int V_276 ;
T_3 V_165 ;
V_263 = V_235 -> V_268 ;
V_2 = V_263 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_112 ;
V_14 = V_2 -> V_14 ;
F_260 ( V_235 , & V_14 -> V_200 , V_239 ) ;
F_11 ( V_2 ) ;
V_165 = F_87 ( V_14 ) ;
switch ( V_14 -> V_109 -> V_108 ) {
case V_166 :
case V_115 :
case V_208 :
if ( V_165 >= V_14 -> V_138 -> V_139 ) {
V_276 = V_398 | V_399 ;
break;
}
V_276 = 0 ;
break;
case V_167 :
if ( V_165 > 0 ) {
V_276 = V_398 | V_399 ;
break;
}
default:
V_276 = V_398 | V_399 | V_397 ;
break;
}
F_13 ( V_2 ) ;
return V_276 ;
}
static int F_262 ( struct V_400 * V_401 ,
struct V_402 * V_403 )
{
struct V_1 * V_2 = V_401 -> V_404 ;
struct V_13 * V_14 ;
if ( V_2 == NULL )
return V_405 ;
V_14 = V_2 -> V_14 ;
V_403 -> V_406 = F_263 ( V_14 -> V_109 ) ;
F_264 ( V_403 -> V_406 ) ;
return 0 ;
}
static int V_334 ( struct V_1 * V_2 , struct V_235 * V_235 ,
struct V_400 * V_401 )
{
long V_407 ;
if ( ! ( V_401 -> V_408 & V_409 ) )
return - V_79 ;
V_407 = V_401 -> V_410 - V_401 -> V_411 ;
if ( V_407 != F_265 ( sizeof( struct V_334 ) ) )
return - V_79 ;
V_401 -> V_412 = & V_413 ;
V_401 -> V_404 = V_2 ;
V_401 -> V_408 |= V_414 | V_415 ;
return 0 ;
}
static int F_266 ( struct V_400 * V_401 ,
struct V_402 * V_403 )
{
struct V_1 * V_2 = V_401 -> V_404 ;
struct V_13 * V_14 ;
if ( V_2 == NULL )
return V_405 ;
V_14 = V_2 -> V_14 ;
V_403 -> V_406 = F_263 ( V_14 -> V_138 ) ;
F_264 ( V_403 -> V_406 ) ;
return 0 ;
}
static int V_335 ( struct V_1 * V_2 , struct V_235 * V_235 ,
struct V_400 * V_401 )
{
long V_407 ;
if ( ! ( V_401 -> V_408 & V_409 ) )
return - V_79 ;
V_407 = V_401 -> V_410 - V_401 -> V_411 ;
if ( V_407 != F_265 ( sizeof( struct V_335 ) ) )
return - V_79 ;
V_401 -> V_412 = & V_416 ;
V_401 -> V_404 = V_2 ;
V_401 -> V_408 |= V_414 | V_415 ;
return 0 ;
}
static int V_334 ( struct V_1 * V_2 , struct V_235 * V_235 ,
struct V_400 * V_401 )
{
return - V_112 ;
}
static int V_335 ( struct V_1 * V_2 , struct V_235 * V_235 ,
struct V_400 * V_401 )
{
return - V_112 ;
}
static inline struct V_406 *
F_267 ( struct V_1 * V_2 , unsigned long V_417 )
{
void * V_418 = V_2 -> V_14 -> V_419 + V_417 ;
return F_263 ( V_418 ) ;
}
static int F_268 ( struct V_400 * V_401 ,
struct V_402 * V_403 )
{
struct V_1 * V_2 = V_401 -> V_404 ;
struct V_13 * V_14 ;
unsigned long V_385 ;
struct V_406 * V_406 ;
T_8 V_311 ;
if ( V_2 == NULL )
return V_405 ;
V_14 = V_2 -> V_14 ;
V_385 = V_403 -> V_420 << V_421 ;
V_311 = F_265 ( V_14 -> V_311 ) ;
if ( V_385 > V_311 - V_422 )
return V_405 ;
if ( V_2 -> V_33 -> V_406 )
V_406 = V_2 -> V_33 -> V_406 ( V_2 , V_385 ) ;
else
V_406 = F_267 ( V_2 , V_385 ) ;
if ( ! V_406 )
return V_405 ;
F_264 ( V_406 ) ;
V_403 -> V_406 = V_406 ;
return 0 ;
}
int F_269 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
V_401 -> V_408 |= V_414 | V_415 ;
#ifdef F_270
if ( V_2 -> V_49 . V_50 . type == V_423 ) {
V_401 -> V_424 = F_271 ( V_401 -> V_424 ) ;
return F_272 ( V_401 , V_401 -> V_411 ,
V_2 -> V_49 . V_425 >> V_421 ,
V_401 -> V_410 - V_401 -> V_411 , V_401 -> V_424 ) ;
}
#endif
#ifndef F_273
if ( ! V_2 -> V_33 -> V_406 &&
V_2 -> V_49 . V_50 . type == V_51 )
return F_274 ( V_2 -> V_49 . V_50 . V_50 ,
V_401 ,
V_2 -> V_14 -> V_419 ,
V_2 -> V_14 -> V_426 ,
V_401 -> V_410 - V_401 -> V_411 ) ;
#endif
V_401 -> V_412 = & V_427 ;
return 0 ;
}
int F_275 ( struct V_1 * V_2 ,
struct V_400 * V_401 )
{
struct V_13 * V_14 = V_2 -> V_14 ; ;
V_401 -> V_424 = F_276 ( V_401 -> V_424 ) ;
return F_277 ( V_401 , V_14 -> V_426 , V_14 -> V_311 ) ;
}
int F_278 ( struct V_1 * V_2 , struct V_235 * V_235 ,
struct V_400 * V_401 )
{
struct V_13 * V_14 ;
long V_407 ;
unsigned long V_385 ;
T_8 V_311 ;
int V_37 ;
if ( V_2 -> V_21 == V_154 ) {
if ( ! ( V_401 -> V_408 & ( V_428 | V_409 ) ) )
return - V_79 ;
} else {
if ( ! ( V_401 -> V_408 & V_409 ) )
return - V_79 ;
}
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_109 -> V_108 == V_113 )
return - V_116 ;
if ( ! ( V_14 -> V_12 & V_42 ) )
return - V_112 ;
if ( V_14 -> V_122 == V_292 ||
V_14 -> V_122 == V_294 )
return - V_79 ;
V_407 = V_401 -> V_410 - V_401 -> V_411 ;
V_385 = V_401 -> V_429 << V_421 ;
V_311 = F_265 ( V_14 -> V_311 ) ;
if ( ( T_8 ) V_407 > V_311 )
return - V_79 ;
if ( V_385 > V_311 - V_407 )
return - V_79 ;
V_401 -> V_412 = & V_430 ;
V_401 -> V_404 = V_2 ;
if ( V_2 -> V_33 -> V_48 )
V_37 = V_2 -> V_33 -> V_48 ( V_2 , V_401 ) ;
else
V_37 = F_269 ( V_2 , V_401 ) ;
if ( ! V_37 )
F_279 ( & V_2 -> V_119 ) ;
return V_37 ;
}
static int F_280 ( struct V_235 * V_235 , struct V_400 * V_401 )
{
struct V_262 * V_263 ;
struct V_1 * V_2 ;
unsigned long V_385 ;
V_263 = V_235 -> V_268 ;
V_2 = V_263 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_112 ;
V_385 = V_401 -> V_429 << V_421 ;
switch ( V_385 ) {
case V_431 :
if ( V_263 -> V_432 )
return - V_112 ;
return V_334 ( V_2 , V_235 , V_401 ) ;
case V_433 :
if ( V_263 -> V_432 )
return - V_112 ;
return V_335 ( V_2 , V_235 , V_401 ) ;
default:
return F_278 ( V_2 , V_235 , V_401 ) ;
}
return 0 ;
}
static int F_281 ( int V_261 , struct V_235 * V_235 , int V_434 )
{
struct V_262 * V_263 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
V_263 = V_235 -> V_268 ;
V_2 = V_263 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_112 ;
V_14 = V_2 -> V_14 ;
return F_282 ( V_261 , V_235 , V_434 , & V_14 -> V_435 ) ;
}
static void F_283 ( struct V_52 * V_53 ,
struct V_436 * V_437 )
{
unsigned int V_57 ;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
V_53 -> V_10 = V_437 -> V_10 ;
for ( V_57 = 0 ; V_57 < F_284 ( V_437 -> V_438 ) ; V_57 ++ )
V_53 -> V_438 [ V_57 ] . V_81 [ 0 ] = V_437 -> V_438 [ V_57 ] ;
memcpy ( V_53 -> V_439 , V_437 -> V_439 , sizeof( V_437 -> V_439 ) ) ;
V_53 -> V_71 = F_285 ( V_437 -> V_71 ) ;
V_53 -> V_82 = F_285 ( V_437 -> V_82 ) ;
V_53 -> V_12 = V_437 -> V_12 ;
V_53 -> V_73 = V_437 -> V_73 ;
V_53 -> V_75 = V_437 -> V_75 ;
V_53 -> V_76 = V_437 -> V_76 ;
V_53 -> V_70 = V_437 -> V_70 ;
}
static void F_286 ( struct V_436 * V_437 ,
struct V_52 * V_53 )
{
unsigned int V_57 ;
memset ( V_437 , 0 , sizeof( * V_437 ) ) ;
V_437 -> V_10 = V_53 -> V_10 ;
for ( V_57 = 0 ; V_57 < F_284 ( V_437 -> V_438 ) ; V_57 ++ )
V_437 -> V_438 [ V_57 ] = V_53 -> V_438 [ V_57 ] . V_81 [ 0 ] ;
memcpy ( V_437 -> V_439 , V_53 -> V_439 , sizeof( V_437 -> V_439 ) ) ;
V_437 -> V_71 = F_287 ( V_53 -> V_71 ) ;
V_437 -> V_82 = F_287 ( V_53 -> V_82 ) ;
V_437 -> V_12 = V_53 -> V_12 ;
V_437 -> V_73 = V_53 -> V_73 ;
V_437 -> V_75 = V_53 -> V_75 ;
V_437 -> V_76 = V_53 -> V_76 ;
V_437 -> V_70 = V_53 -> V_70 ;
}
static int F_239 ( struct V_1 * V_2 ,
struct V_436 T_2 * V_440 )
{
struct V_52 * V_53 ;
struct V_436 * V_437 = NULL ;
int V_37 ;
V_53 = F_27 ( sizeof( * V_53 ) , V_38 ) ;
if ( ! V_53 )
return - V_39 ;
V_437 = F_52 ( V_440 , sizeof( * V_437 ) ) ;
if ( F_53 ( V_437 ) ) {
V_37 = F_54 ( V_437 ) ;
goto V_441;
}
F_283 ( V_53 , V_437 ) ;
V_37 = F_32 ( V_2 , V_53 ) ;
F_286 ( V_437 , V_53 ) ;
if ( F_28 ( V_440 , V_437 , sizeof( * V_437 ) ) ) {
if ( ! V_37 )
V_37 = - V_40 ;
}
F_29 ( V_437 ) ;
V_441:
F_29 ( V_53 ) ;
return V_37 ;
}
static int F_240 ( struct V_1 * V_2 ,
struct V_436 T_2 * V_440 )
{
struct V_52 * V_53 ;
struct V_436 * V_437 = NULL ;
int V_37 ;
V_53 = F_27 ( sizeof( * V_53 ) , V_38 ) ;
if ( ! V_53 )
return - V_39 ;
V_437 = F_52 ( V_440 , sizeof( * V_437 ) ) ;
if ( F_53 ( V_437 ) ) {
V_37 = F_54 ( V_437 ) ;
goto V_441;
}
F_283 ( V_53 , V_437 ) ;
V_37 = V_52 ( V_2 , V_53 ) ;
F_286 ( V_437 , V_53 ) ;
if ( F_28 ( V_440 , V_437 , sizeof( * V_437 ) ) ) {
if ( ! V_37 )
V_37 = - V_40 ;
}
F_29 ( V_437 ) ;
V_441:
F_29 ( V_53 ) ;
return V_37 ;
}
static unsigned long F_288 ( struct V_235 * V_235 ,
unsigned long V_425 ,
unsigned long V_442 ,
unsigned long V_420 ,
unsigned long V_10 )
{
struct V_262 * V_263 = V_235 -> V_268 ;
struct V_1 * V_2 = V_263 -> V_2 ;
struct V_13 * V_14 = V_2 -> V_14 ;
unsigned long V_385 = V_420 << V_421 ;
switch ( V_385 ) {
case V_431 :
return ( unsigned long ) V_14 -> V_109 ;
case V_433 :
return ( unsigned long ) V_14 -> V_138 ;
default:
return ( unsigned long ) V_14 -> V_419 + V_385 ;
}
}
