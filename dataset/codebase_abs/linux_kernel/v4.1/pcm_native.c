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
F_84 ( V_109 -> V_156 ,
& V_14 -> V_157 ) ;
if ( V_14 -> V_157 . V_158 ==
V_159 ) {
if ( V_14 -> V_41 . V_12 & V_160 )
V_14 -> V_157 . V_158 =
V_161 ;
else
V_14 -> V_157 . V_158 =
V_162 ;
V_14 -> V_163 . V_164 = 0 ;
} else
V_14 -> V_163 . V_164 = 1 ;
V_109 -> V_108 = V_14 -> V_109 -> V_108 ;
V_109 -> V_165 = V_14 -> V_109 -> V_165 ;
if ( V_109 -> V_108 == V_113 )
goto V_166;
V_109 -> V_167 = V_14 -> V_167 ;
if ( F_78 ( V_2 ) ) {
F_85 ( V_2 ) ;
if ( V_14 -> V_135 == V_168 ) {
V_109 -> V_169 = V_14 -> V_109 -> V_169 ;
V_109 -> V_170 = V_14 -> V_170 ;
V_109 -> V_171 =
V_14 -> V_109 -> V_171 ;
if ( V_14 -> V_163 . V_164 == 1 )
F_86 ( & V_109 -> V_156 ,
& V_109 -> V_172 ,
& V_14 -> V_163 ) ;
goto V_173;
}
} else {
if ( V_14 -> V_135 == V_168 )
F_87 ( V_14 , & V_109 -> V_169 ) ;
}
V_173:
V_109 -> V_174 = V_14 -> V_138 -> V_174 ;
V_109 -> V_175 = V_14 -> V_109 -> V_175 ;
if ( V_2 -> V_21 == V_154 ) {
V_109 -> V_176 = F_88 ( V_14 ) ;
if ( V_14 -> V_109 -> V_108 == V_177 ||
V_14 -> V_109 -> V_108 == V_178 ) {
V_109 -> V_179 = V_14 -> V_127 - V_109 -> V_176 ;
V_109 -> V_179 += V_14 -> V_179 ;
} else
V_109 -> V_179 = 0 ;
} else {
V_109 -> V_176 = F_89 ( V_14 ) ;
if ( V_14 -> V_109 -> V_108 == V_177 )
V_109 -> V_179 = V_109 -> V_176 + V_14 -> V_179 ;
else
V_109 -> V_179 = 0 ;
}
V_109 -> V_180 = V_14 -> V_180 ;
V_109 -> V_181 = V_14 -> V_181 ;
V_14 -> V_180 = 0 ;
V_14 -> V_181 = 0 ;
V_166:
F_13 ( V_2 ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct F_83 T_2 * V_182 ,
bool V_183 )
{
struct F_83 V_109 ;
int V_184 ;
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
if ( V_183 && F_91 ( V_109 . V_156 ,
( V_185 T_2 * ) ( & V_182 -> V_156 ) ) )
return - V_40 ;
V_184 = F_83 ( V_2 , & V_109 ) ;
if ( V_184 < 0 )
return V_184 ;
if ( F_28 ( V_182 , & V_109 , sizeof( V_109 ) ) )
return - V_40 ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct F_92 * V_12 )
{
struct V_13 * V_14 ;
unsigned int V_186 ;
V_186 = V_12 -> V_186 ;
V_14 = V_2 -> V_14 ;
F_11 ( V_2 ) ;
if ( V_14 -> V_109 -> V_108 == V_113 ) {
F_13 ( V_2 ) ;
return - V_116 ;
}
F_13 ( V_2 ) ;
if ( V_186 >= V_14 -> V_125 )
return - V_79 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_186 = V_186 ;
return V_2 -> V_33 -> V_34 ( V_2 , V_187 , V_12 ) ;
}
static int F_93 ( struct V_1 * V_2 ,
struct F_92 T_2 * V_36 )
{
struct F_92 V_12 ;
int V_184 ;
if ( F_82 ( & V_12 , V_36 , sizeof( V_12 ) ) )
return - V_40 ;
V_184 = F_92 ( V_2 , & V_12 ) ;
if ( V_184 < 0 )
return V_184 ;
if ( F_28 ( V_36 , & V_12 , sizeof( V_12 ) ) )
return - V_40 ;
return 0 ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_188 == NULL )
return;
if ( V_14 -> V_188 == V_2 ) {
if ( ! V_14 -> V_189 )
F_87 ( V_14 , & V_14 -> V_167 ) ;
} else {
F_94 ( V_14 -> V_188 ) ;
V_14 -> V_167 = V_14 -> V_188 -> V_14 -> V_167 ;
}
V_14 -> V_188 = NULL ;
}
static int F_95 ( struct V_190 * V_33 ,
struct V_1 * V_2 ,
int V_108 , int V_191 )
{
struct V_1 * V_192 = NULL ;
struct V_1 * V_193 ;
int V_184 = 0 , V_194 = 1 ;
F_96 (s, substream) {
if ( V_191 && V_192 != V_2 ) {
if ( V_192 -> V_3 -> V_4 )
F_97 ( & V_192 -> V_6 . V_7 , V_194 ) ;
else
F_98 ( & V_192 -> V_6 . V_9 , V_194 ) ;
V_194 ++ ;
}
V_184 = V_33 -> V_195 ( V_192 , V_108 ) ;
if ( V_184 < 0 )
goto V_196;
}
F_96 (s, substream) {
V_184 = V_33 -> V_197 ( V_192 , V_108 ) ;
if ( V_184 < 0 ) {
if ( V_33 -> V_198 ) {
F_96 (s1, substream) {
if ( V_193 == V_192 )
break;
V_33 -> V_198 ( V_193 , V_108 ) ;
}
}
V_192 = NULL ;
goto V_196;
}
}
F_96 (s, substream) {
V_33 -> V_199 ( V_192 , V_108 ) ;
}
V_196:
if ( V_191 ) {
F_96 (s1, substream) {
if ( V_193 != V_2 ) {
if ( V_193 -> V_3 -> V_4 )
F_7 ( & V_193 -> V_6 . V_7 ) ;
else
F_9 ( & V_193 -> V_6 . V_9 ) ;
}
if ( V_193 == V_192 )
break;
}
}
return V_184 ;
}
static int F_99 ( struct V_190 * V_33 ,
struct V_1 * V_2 ,
int V_108 )
{
int V_184 ;
V_184 = V_33 -> V_195 ( V_2 , V_108 ) ;
if ( V_184 < 0 )
return V_184 ;
V_184 = V_33 -> V_197 ( V_2 , V_108 ) ;
if ( V_184 == 0 )
V_33 -> V_199 ( V_2 , V_108 ) ;
else if ( V_33 -> V_198 )
V_33 -> V_198 ( V_2 , V_108 ) ;
return V_184 ;
}
static int F_100 ( struct V_190 * V_33 ,
struct V_1 * V_2 ,
int V_108 )
{
int V_184 ;
if ( ! F_101 ( V_2 ) )
return F_99 ( V_33 , V_2 , V_108 ) ;
if ( V_2 -> V_3 -> V_4 ) {
if ( ! F_102 ( & V_2 -> V_200 -> V_7 ) ) {
F_7 ( & V_2 -> V_6 . V_7 ) ;
F_3 ( & V_2 -> V_200 -> V_7 ) ;
F_3 ( & V_2 -> V_6 . V_7 ) ;
}
V_184 = F_95 ( V_33 , V_2 , V_108 , 1 ) ;
F_7 ( & V_2 -> V_200 -> V_7 ) ;
} else {
if ( ! F_103 ( & V_2 -> V_200 -> V_9 ) ) {
F_9 ( & V_2 -> V_6 . V_9 ) ;
F_5 ( & V_2 -> V_200 -> V_9 ) ;
F_5 ( & V_2 -> V_6 . V_9 ) ;
}
V_184 = F_95 ( V_33 , V_2 , V_108 , 1 ) ;
F_9 ( & V_2 -> V_200 -> V_9 ) ;
}
return V_184 ;
}
static int F_104 ( struct V_190 * V_33 ,
struct V_1 * V_2 ,
int V_108 )
{
int V_184 ;
F_11 ( V_2 ) ;
V_184 = F_100 ( V_33 , V_2 , V_108 ) ;
F_13 ( V_2 ) ;
return V_184 ;
}
static int F_105 ( struct V_190 * V_33 ,
struct V_1 * V_2 ,
int V_108 )
{
int V_184 ;
F_2 ( & V_5 ) ;
if ( F_101 ( V_2 ) )
V_184 = F_95 ( V_33 , V_2 , V_108 , 0 ) ;
else
V_184 = F_99 ( V_33 , V_2 , V_108 ) ;
F_8 ( & V_5 ) ;
return V_184 ;
}
static int F_106 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_109 -> V_108 != V_115 )
return - V_116 ;
if ( V_2 -> V_21 == V_154 &&
! F_107 ( V_2 ) )
return - V_201 ;
V_14 -> V_189 = false ;
V_14 -> V_188 = V_2 ;
return 0 ;
}
static int F_108 ( struct V_1 * V_2 , int V_108 )
{
if ( V_2 -> V_14 -> V_188 != V_2 )
return 0 ;
return V_2 -> V_33 -> V_202 ( V_2 , V_203 ) ;
}
static void F_109 ( struct V_1 * V_2 , int V_108 )
{
if ( V_2 -> V_14 -> V_188 == V_2 )
V_2 -> V_33 -> V_202 ( V_2 , V_204 ) ;
}
static void F_110 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_94 ( V_2 ) ;
V_14 -> V_205 = V_206 ;
V_14 -> V_207 = ( V_14 -> V_127 * V_208 ) /
V_14 -> V_106 ;
V_14 -> V_109 -> V_108 = V_108 ;
if ( V_2 -> V_21 == V_154 &&
V_14 -> V_143 > 0 )
F_79 ( V_2 , V_155 ) ;
if ( V_2 -> V_209 )
F_111 ( V_2 -> V_209 , V_210 ,
& V_14 -> V_167 ) ;
}
int F_112 ( struct V_1 * V_2 )
{
return F_100 ( & V_211 , V_2 ,
V_177 ) ;
}
static int F_113 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_109 -> V_108 == V_113 )
return - V_116 ;
V_14 -> V_188 = V_2 ;
return 0 ;
}
static int F_114 ( struct V_1 * V_2 , int V_108 )
{
if ( V_2 -> V_14 -> V_188 == V_2 &&
F_78 ( V_2 ) )
V_2 -> V_33 -> V_202 ( V_2 , V_204 ) ;
return 0 ;
}
static void F_115 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_109 -> V_108 != V_108 ) {
F_94 ( V_2 ) ;
V_14 -> V_109 -> V_108 = V_108 ;
if ( V_2 -> V_209 )
F_111 ( V_2 -> V_209 , V_212 ,
& V_14 -> V_167 ) ;
}
F_116 ( & V_14 -> V_213 ) ;
F_116 ( & V_14 -> V_214 ) ;
}
int F_117 ( struct V_1 * V_2 , T_4 V_108 )
{
return F_100 ( & V_215 , V_2 , V_108 ) ;
}
int F_118 ( struct V_1 * V_2 )
{
return F_99 ( & V_215 , V_2 ,
V_114 ) ;
}
int F_119 ( struct V_1 * V_2 )
{
unsigned long V_10 ;
int V_216 = 0 ;
F_120 ( V_2 , V_10 ) ;
if ( F_78 ( V_2 ) )
V_216 = F_117 ( V_2 , V_217 ) ;
F_17 ( V_2 , V_10 ) ;
return V_216 ;
}
static int F_121 ( struct V_1 * V_2 , int V_218 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( ! ( V_14 -> V_12 & V_219 ) )
return - V_220 ;
if ( V_218 ) {
if ( V_14 -> V_109 -> V_108 != V_177 )
return - V_116 ;
} else if ( V_14 -> V_109 -> V_108 != V_221 )
return - V_116 ;
V_14 -> V_188 = V_2 ;
return 0 ;
}
static int F_122 ( struct V_1 * V_2 , int V_218 )
{
if ( V_2 -> V_14 -> V_188 != V_2 )
return 0 ;
if ( V_218 )
F_85 ( V_2 ) ;
V_2 -> V_14 -> V_205 = V_206 - V_208 * 1000 ;
return V_2 -> V_33 -> V_202 ( V_2 ,
V_218 ? V_222 :
V_223 ) ;
}
static void F_123 ( struct V_1 * V_2 , int V_218 )
{
if ( V_2 -> V_14 -> V_188 == V_2 )
V_2 -> V_33 -> V_202 ( V_2 ,
V_218 ? V_223 :
V_222 ) ;
}
static void F_124 ( struct V_1 * V_2 , int V_218 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_94 ( V_2 ) ;
if ( V_218 ) {
V_14 -> V_109 -> V_108 = V_221 ;
if ( V_2 -> V_209 )
F_111 ( V_2 -> V_209 ,
V_224 ,
& V_14 -> V_167 ) ;
F_116 ( & V_14 -> V_213 ) ;
F_116 ( & V_14 -> V_214 ) ;
} else {
V_14 -> V_109 -> V_108 = V_177 ;
if ( V_2 -> V_209 )
F_111 ( V_2 -> V_209 ,
V_225 ,
& V_14 -> V_167 ) ;
}
}
static int F_125 ( struct V_1 * V_2 , int V_218 )
{
return F_100 ( & V_226 , V_2 , V_218 ) ;
}
static int F_126 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_109 -> V_108 == V_227 )
return - V_228 ;
V_14 -> V_188 = V_2 ;
return 0 ;
}
static int F_127 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_188 != V_2 )
return 0 ;
if ( ! F_78 ( V_2 ) )
return 0 ;
V_2 -> V_33 -> V_202 ( V_2 , V_229 ) ;
return 0 ;
}
static void F_128 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_94 ( V_2 ) ;
V_14 -> V_109 -> V_165 = V_14 -> V_109 -> V_108 ;
V_14 -> V_109 -> V_108 = V_227 ;
if ( V_2 -> V_209 )
F_111 ( V_2 -> V_209 , V_230 ,
& V_14 -> V_167 ) ;
F_116 ( & V_14 -> V_213 ) ;
F_116 ( & V_14 -> V_214 ) ;
}
int F_129 ( struct V_1 * V_2 )
{
int V_37 ;
unsigned long V_10 ;
if ( ! V_2 )
return 0 ;
F_120 ( V_2 , V_10 ) ;
V_37 = F_100 ( & V_231 , V_2 , 0 ) ;
F_17 ( V_2 , V_10 ) ;
return V_37 ;
}
int F_130 ( struct V_15 * V_3 )
{
struct V_1 * V_2 ;
int V_21 , V_37 = 0 ;
if ( ! V_3 )
return 0 ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
for ( V_2 = V_3 -> V_232 [ V_21 ] . V_2 ;
V_2 ; V_2 = V_2 -> V_233 ) {
if ( V_2 -> V_14 == NULL )
continue;
V_37 = F_129 ( V_2 ) ;
if ( V_37 < 0 && V_37 != - V_228 )
return V_37 ;
}
}
return 0 ;
}
static int F_131 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( ! ( V_14 -> V_12 & V_234 ) )
return - V_220 ;
V_14 -> V_188 = V_2 ;
return 0 ;
}
static int F_132 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_188 != V_2 )
return 0 ;
if ( V_14 -> V_109 -> V_165 != V_177 &&
( V_14 -> V_109 -> V_165 != V_178 ||
V_2 -> V_21 != V_154 ) )
return 0 ;
return V_2 -> V_33 -> V_202 ( V_2 , V_235 ) ;
}
static void F_133 ( struct V_1 * V_2 , int V_108 )
{
if ( V_2 -> V_14 -> V_188 == V_2 &&
F_78 ( V_2 ) )
V_2 -> V_33 -> V_202 ( V_2 , V_229 ) ;
}
static void F_134 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_94 ( V_2 ) ;
V_14 -> V_109 -> V_108 = V_14 -> V_109 -> V_165 ;
if ( V_2 -> V_209 )
F_111 ( V_2 -> V_209 , V_236 ,
& V_14 -> V_167 ) ;
}
static int F_135 ( struct V_1 * V_2 )
{
struct V_237 * V_18 = V_2 -> V_3 -> V_18 ;
int V_184 ;
F_136 ( V_18 ) ;
if ( ( V_184 = F_137 ( V_18 , V_238 ) ) >= 0 )
V_184 = F_104 ( & V_239 , V_2 , 0 ) ;
F_138 ( V_18 ) ;
return V_184 ;
}
static int F_135 ( struct V_1 * V_2 )
{
return - V_220 ;
}
static int F_139 ( struct V_1 * V_2 )
{
struct V_237 * V_18 = V_2 -> V_3 -> V_18 ;
struct V_13 * V_14 = V_2 -> V_14 ;
int V_149 ;
F_136 ( V_18 ) ;
if ( V_14 -> V_109 -> V_108 == V_227 ) {
V_149 = F_137 ( V_18 , V_238 ) ;
if ( V_149 < 0 )
goto V_196;
}
F_11 ( V_2 ) ;
switch ( V_14 -> V_109 -> V_108 ) {
case V_217 :
V_149 = 0 ;
break;
case V_177 :
V_149 = F_117 ( V_2 , V_217 ) ;
break;
default:
V_149 = - V_116 ;
}
F_13 ( V_2 ) ;
V_196:
F_138 ( V_18 ) ;
return V_149 ;
}
static int F_140 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
switch ( V_14 -> V_109 -> V_108 ) {
case V_177 :
case V_115 :
case V_221 :
case V_227 :
return 0 ;
default:
return - V_116 ;
}
}
static int F_141 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_37 = V_2 -> V_33 -> V_34 ( V_2 , V_240 , NULL ) ;
if ( V_37 < 0 )
return V_37 ;
V_14 -> V_241 = 0 ;
V_14 -> V_242 = V_14 -> V_109 -> V_175 -
V_14 -> V_109 -> V_175 % V_14 -> V_107 ;
V_14 -> V_243 = V_14 -> V_109 -> V_175 ;
V_14 -> V_244 = 0 ;
return 0 ;
}
static void F_142 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
V_14 -> V_138 -> V_174 = V_14 -> V_109 -> V_175 ;
if ( V_2 -> V_21 == V_154 &&
V_14 -> V_143 > 0 )
F_79 ( V_2 , V_155 ) ;
}
static int F_143 ( struct V_1 * V_2 )
{
return F_105 ( & V_245 , V_2 , 0 ) ;
}
static int F_144 ( struct V_1 * V_2 ,
int V_246 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_109 -> V_108 == V_113 ||
V_14 -> V_109 -> V_108 == V_110 )
return - V_116 ;
if ( F_78 ( V_2 ) )
return - V_228 ;
V_2 -> V_246 = V_246 ;
return 0 ;
}
static int F_145 ( struct V_1 * V_2 , int V_108 )
{
int V_37 ;
V_37 = V_2 -> V_33 -> V_247 ( V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
return F_141 ( V_2 , 0 ) ;
}
static void F_146 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
V_14 -> V_138 -> V_174 = V_14 -> V_109 -> V_175 ;
F_56 ( V_2 , V_115 ) ;
}
static int F_147 ( struct V_1 * V_2 ,
struct V_248 * V_248 )
{
int V_184 ;
struct V_237 * V_18 = V_2 -> V_3 -> V_18 ;
int V_246 ;
if ( V_248 )
V_246 = V_248 -> V_246 ;
else
V_246 = V_2 -> V_246 ;
F_136 ( V_18 ) ;
if ( ( V_184 = F_137 ( V_18 , V_238 ) ) >= 0 )
V_184 = F_105 ( & V_249 ,
V_2 , V_246 ) ;
F_138 ( V_18 ) ;
return V_184 ;
}
static int F_148 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
switch ( V_14 -> V_109 -> V_108 ) {
case V_113 :
case V_110 :
case V_227 :
return - V_116 ;
}
V_14 -> V_188 = V_2 ;
return 0 ;
}
static int F_149 ( struct V_1 * V_2 , int V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_2 -> V_21 == V_154 ) {
switch ( V_14 -> V_109 -> V_108 ) {
case V_115 :
if ( ! F_150 ( V_2 ) ) {
F_108 ( V_2 , V_178 ) ;
F_110 ( V_2 , V_178 ) ;
} else {
V_14 -> V_109 -> V_108 = V_114 ;
}
break;
case V_177 :
V_14 -> V_109 -> V_108 = V_178 ;
break;
case V_217 :
V_14 -> V_109 -> V_108 = V_114 ;
break;
default:
break;
}
} else {
if ( V_14 -> V_109 -> V_108 == V_177 ) {
int V_250 = F_89 ( V_14 ) > 0 ?
V_178 : V_114 ;
F_114 ( V_2 , V_250 ) ;
F_115 ( V_2 , V_250 ) ;
}
}
if ( V_14 -> V_109 -> V_108 == V_178 &&
V_14 -> V_188 == V_2 &&
( V_14 -> V_41 . V_12 & V_99 ) )
return V_2 -> V_33 -> V_202 ( V_2 ,
V_251 ) ;
return 0 ;
}
static void F_151 ( struct V_1 * V_2 , int V_108 )
{
}
static int F_152 ( struct V_1 * V_2 ,
struct V_248 * V_248 )
{
struct V_237 * V_18 ;
struct V_13 * V_14 ;
struct V_1 * V_192 ;
T_5 V_252 ;
int V_149 = 0 ;
int V_253 = 0 ;
V_18 = V_2 -> V_3 -> V_18 ;
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_109 -> V_108 == V_113 )
return - V_116 ;
F_136 ( V_18 ) ;
if ( V_14 -> V_109 -> V_108 == V_227 ) {
V_149 = F_137 ( V_18 , V_238 ) ;
if ( V_149 < 0 ) {
F_138 ( V_18 ) ;
return V_149 ;
}
}
if ( V_248 ) {
if ( V_248 -> V_246 & V_254 )
V_253 = 1 ;
} else if ( V_2 -> V_246 & V_254 )
V_253 = 1 ;
F_2 ( & V_5 ) ;
F_11 ( V_2 ) ;
if ( V_14 -> V_109 -> V_108 == V_221 )
F_125 ( V_2 , 0 ) ;
V_149 = F_100 ( & V_255 , V_2 , 0 ) ;
if ( V_149 < 0 )
goto V_256;
if ( V_253 ) {
V_149 = - V_257 ;
goto V_256;
}
for (; ; ) {
long V_258 ;
struct V_13 * V_259 ;
if ( F_153 ( V_260 ) ) {
V_149 = - V_261 ;
break;
}
V_259 = NULL ;
F_96 (s, substream) {
if ( V_192 -> V_21 != V_154 )
continue;
V_14 = V_192 -> V_14 ;
if ( V_14 -> V_109 -> V_108 == V_178 ) {
V_259 = V_14 ;
break;
}
}
if ( ! V_259 )
break;
F_154 ( & V_252 , V_260 ) ;
F_155 ( & V_259 -> V_213 , & V_252 ) ;
F_13 ( V_2 ) ;
F_8 ( & V_5 ) ;
F_138 ( V_18 ) ;
if ( V_14 -> V_128 )
V_258 = V_262 ;
else {
V_258 = 10 ;
if ( V_14 -> V_106 ) {
long V_263 = V_14 -> V_107 * 2 / V_14 -> V_106 ;
V_258 = V_87 ( V_263 , V_258 ) ;
}
V_258 = F_156 ( V_258 * 1000 ) ;
}
V_258 = F_157 ( V_258 ) ;
F_136 ( V_18 ) ;
F_2 ( & V_5 ) ;
F_11 ( V_2 ) ;
F_158 ( & V_259 -> V_213 , & V_252 ) ;
if ( V_18 -> V_264 ) {
V_149 = - V_265 ;
break;
}
if ( V_258 == 0 ) {
if ( V_2 -> V_14 -> V_109 -> V_108 == V_227 )
V_149 = - V_266 ;
else {
F_159 ( V_2 -> V_3 -> V_18 -> V_50 ,
L_12 ) ;
F_117 ( V_2 , V_114 ) ;
V_149 = - V_267 ;
}
break;
}
}
V_256:
F_13 ( V_2 ) ;
F_8 ( & V_5 ) ;
F_138 ( V_18 ) ;
return V_149 ;
}
static int F_160 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
int V_149 = 0 ;
if ( F_57 ( V_2 ) )
return - V_112 ;
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_109 -> V_108 == V_113 ||
V_14 -> V_109 -> V_108 == V_110 ||
V_14 -> V_109 -> V_108 == V_227 )
return - V_116 ;
F_11 ( V_2 ) ;
if ( V_14 -> V_109 -> V_108 == V_221 )
F_125 ( V_2 , 0 ) ;
F_117 ( V_2 , V_114 ) ;
F_13 ( V_2 ) ;
return V_149 ;
}
static bool F_161 ( struct V_248 * V_248 )
{
struct V_268 * V_268 = F_162 ( V_248 ) ;
unsigned int V_269 ;
if ( ! F_163 ( V_268 -> V_270 ) || F_164 ( V_268 ) != V_271 )
return false ;
V_269 = F_165 ( V_268 ) ;
return F_166 ( V_269 , V_272 ) ||
F_166 ( V_269 , V_273 ) ;
}
static int F_167 ( struct V_1 * V_2 , int V_274 )
{
int V_184 = 0 ;
struct V_275 * V_276 ;
struct V_1 * V_277 ;
struct V_278 * V_200 ;
struct V_274 V_279 = F_168 ( V_274 ) ;
if ( ! V_279 . V_248 )
return - V_116 ;
if ( ! F_161 ( V_279 . V_248 ) ) {
V_184 = - V_116 ;
goto V_280;
}
V_276 = V_279 . V_248 -> V_281 ;
V_277 = V_276 -> V_2 ;
V_200 = F_27 ( sizeof( * V_200 ) , V_38 ) ;
if ( ! V_200 ) {
V_184 = - V_39 ;
goto V_282;
}
F_169 ( & V_5 ) ;
F_170 ( & V_8 ) ;
if ( V_2 -> V_14 -> V_109 -> V_108 == V_113 ||
V_2 -> V_14 -> V_109 -> V_108 != V_277 -> V_14 -> V_109 -> V_108 ||
V_2 -> V_3 -> V_4 != V_277 -> V_3 -> V_4 ) {
V_184 = - V_116 ;
goto V_166;
}
if ( F_101 ( V_277 ) ) {
V_184 = - V_283 ;
goto V_166;
}
if ( ! F_101 ( V_2 ) ) {
V_2 -> V_200 = V_200 ;
V_200 = NULL ;
F_171 ( & V_2 -> V_200 -> V_9 ) ;
F_172 ( & V_2 -> V_200 -> V_7 ) ;
F_173 ( & V_2 -> V_200 -> V_284 ) ;
F_174 ( & V_2 -> V_285 , & V_2 -> V_200 -> V_284 ) ;
V_2 -> V_200 -> V_286 = 1 ;
}
F_174 ( & V_277 -> V_285 , & V_2 -> V_200 -> V_284 ) ;
V_2 -> V_200 -> V_286 ++ ;
V_277 -> V_200 = V_2 -> V_200 ;
V_166:
F_175 ( & V_8 ) ;
F_176 ( & V_5 ) ;
V_282:
F_177 ( V_277 -> V_3 -> V_18 ) ;
F_29 ( V_200 ) ;
V_280:
F_178 ( V_279 ) ;
return V_184 ;
}
static void F_179 ( struct V_1 * V_2 )
{
V_2 -> V_200 = & V_2 -> V_6 ;
F_173 ( & V_2 -> V_6 . V_284 ) ;
F_174 ( & V_2 -> V_285 , & V_2 -> V_6 . V_284 ) ;
}
static int F_180 ( struct V_1 * V_2 )
{
struct V_1 * V_192 ;
int V_184 = 0 ;
F_169 ( & V_5 ) ;
F_170 ( & V_8 ) ;
if ( ! F_101 ( V_2 ) ) {
V_184 = - V_283 ;
goto V_166;
}
F_181 ( & V_2 -> V_285 ) ;
V_2 -> V_200 -> V_286 -- ;
if ( V_2 -> V_200 -> V_286 == 1 ) {
F_96 (s, substream) {
F_179 ( V_192 ) ;
break;
}
F_29 ( V_2 -> V_200 ) ;
}
F_179 ( V_2 ) ;
V_166:
F_175 ( & V_8 ) ;
F_176 ( & V_5 ) ;
return V_184 ;
}
static int F_182 ( struct V_52 * V_53 ,
struct V_89 * V_287 )
{
struct V_56 V_263 ;
F_183 ( F_184 ( V_53 , V_287 -> V_95 [ 0 ] ) ,
F_184 ( V_53 , V_287 -> V_95 [ 1 ] ) , & V_263 ) ;
return F_42 ( F_40 ( V_53 , V_287 -> V_97 ) , & V_263 ) ;
}
static int F_185 ( struct V_52 * V_53 ,
struct V_89 * V_287 )
{
struct V_56 V_263 ;
F_186 ( F_184 ( V_53 , V_287 -> V_95 [ 0 ] ) ,
F_184 ( V_53 , V_287 -> V_95 [ 1 ] ) , & V_263 ) ;
return F_42 ( F_40 ( V_53 , V_287 -> V_97 ) , & V_263 ) ;
}
static int F_187 ( struct V_52 * V_53 ,
struct V_89 * V_287 )
{
struct V_56 V_263 ;
F_188 ( F_184 ( V_53 , V_287 -> V_95 [ 0 ] ) ,
F_184 ( V_53 , V_287 -> V_95 [ 1 ] ) ,
( unsigned long ) V_287 -> V_288 , & V_263 ) ;
return F_42 ( F_40 ( V_53 , V_287 -> V_97 ) , & V_263 ) ;
}
static int F_189 ( struct V_52 * V_53 ,
struct V_89 * V_287 )
{
struct V_56 V_263 ;
F_190 ( F_184 ( V_53 , V_287 -> V_95 [ 0 ] ) ,
( unsigned long ) V_287 -> V_288 ,
F_184 ( V_53 , V_287 -> V_95 [ 1 ] ) , & V_263 ) ;
return F_42 ( F_40 ( V_53 , V_287 -> V_97 ) , & V_263 ) ;
}
static int F_191 ( struct V_52 * V_53 ,
struct V_89 * V_287 )
{
unsigned int V_54 ;
struct V_56 * V_57 = F_40 ( V_53 , V_287 -> V_95 [ 0 ] ) ;
struct V_58 V_59 ;
struct V_58 * V_289 = F_33 ( V_53 , V_101 ) ;
F_192 ( & V_59 ) ;
for ( V_54 = 0 ; V_54 <= V_290 ; ++ V_54 ) {
int V_81 ;
if ( ! F_193 ( V_289 , V_54 ) )
continue;
V_81 = F_69 ( V_54 ) ;
if ( V_81 <= 0 )
continue;
if ( ( unsigned ) V_81 < V_57 -> V_86 || ( unsigned ) V_81 > V_57 -> V_87 )
F_194 ( & V_59 , V_54 ) ;
}
return F_38 ( V_289 , & V_59 ) ;
}
static int F_195 ( struct V_52 * V_53 ,
struct V_89 * V_287 )
{
struct V_56 V_263 ;
unsigned int V_54 ;
V_263 . V_86 = V_291 ;
V_263 . V_87 = 0 ;
V_263 . V_85 = 0 ;
V_263 . V_88 = 0 ;
for ( V_54 = 0 ; V_54 <= V_290 ; ++ V_54 ) {
int V_81 ;
if ( ! F_193 ( F_33 ( V_53 , V_101 ) , V_54 ) )
continue;
V_81 = F_69 ( V_54 ) ;
if ( V_81 <= 0 )
continue;
if ( V_263 . V_86 > ( unsigned ) V_81 )
V_263 . V_86 = V_81 ;
if ( V_263 . V_87 < ( unsigned ) V_81 )
V_263 . V_87 = V_81 ;
}
V_263 . integer = 1 ;
return F_42 ( F_40 ( V_53 , V_287 -> V_97 ) , & V_263 ) ;
}
static int F_196 ( struct V_52 * V_53 ,
struct V_89 * V_287 )
{
struct V_55 * V_41 = V_287 -> V_288 ;
return F_197 ( F_40 ( V_53 , V_287 -> V_97 ) ,
V_292 . V_286 ,
V_292 . V_293 , V_41 -> V_294 ) ;
}
static int F_198 ( struct V_52 * V_53 ,
struct V_89 * V_287 )
{
struct V_56 V_263 ;
struct V_1 * V_2 = V_287 -> V_288 ;
V_263 . V_86 = 0 ;
V_263 . V_87 = V_2 -> V_295 ;
V_263 . V_85 = 0 ;
V_263 . V_88 = 0 ;
V_263 . integer = 1 ;
return F_42 ( F_40 ( V_53 , V_287 -> V_97 ) , & V_263 ) ;
}
int F_199 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_60 * V_61 = & V_14 -> V_62 ;
int V_54 , V_37 ;
for ( V_54 = V_77 ; V_54 <= V_78 ; V_54 ++ ) {
F_192 ( F_39 ( V_61 , V_54 ) ) ;
}
for ( V_54 = V_83 ; V_54 <= V_66 ; V_54 ++ ) {
F_200 ( F_43 ( V_61 , V_54 ) ) ;
}
F_201 ( F_43 ( V_61 , V_102 ) ) ;
F_201 ( F_43 ( V_61 , V_296 ) ) ;
F_201 ( F_43 ( V_61 , V_297 ) ) ;
F_201 ( F_43 ( V_61 , V_72 ) ) ;
F_201 ( F_43 ( V_61 , V_298 ) ) ;
V_37 = F_202 ( V_14 , 0 , V_101 ,
F_191 , NULL ,
V_72 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_202 ( V_14 , 0 , V_72 ,
F_195 , NULL ,
V_101 ,
V_72 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_202 ( V_14 , 0 , V_72 ,
F_185 , NULL ,
V_298 , V_102 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_202 ( V_14 , 0 , V_298 ,
F_182 , NULL ,
V_72 , V_102 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_202 ( V_14 , 0 , V_298 ,
F_189 , ( void * ) 8 ,
V_299 , V_300 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_202 ( V_14 , 0 , V_298 ,
F_189 , ( void * ) 8 ,
V_297 , V_296 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_202 ( V_14 , 0 , V_102 ,
F_185 , NULL ,
V_298 , V_72 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_202 ( V_14 , 0 , V_74 ,
F_189 , ( void * ) 1000000 ,
V_300 , V_301 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_202 ( V_14 , 0 , V_74 ,
F_189 , ( void * ) 1000000 ,
V_296 , V_302 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_202 ( V_14 , 0 , V_303 ,
F_185 , NULL ,
V_296 , V_300 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_202 ( V_14 , 0 , V_300 ,
F_185 , NULL ,
V_296 , V_303 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_202 ( V_14 , 0 , V_300 ,
F_189 , ( void * ) 8 ,
V_299 , V_298 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_202 ( V_14 , 0 , V_300 ,
F_187 , ( void * ) 1000000 ,
V_301 , V_74 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_202 ( V_14 , 0 , V_296 ,
F_182 , NULL ,
V_300 , V_303 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_202 ( V_14 , 0 , V_296 ,
F_189 , ( void * ) 8 ,
V_297 , V_298 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_202 ( V_14 , 0 , V_296 ,
F_187 , ( void * ) 1000000 ,
V_302 , V_74 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_202 ( V_14 , 0 , V_299 ,
F_187 , ( void * ) 8 ,
V_300 , V_298 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_202 ( V_14 , 0 , V_297 ,
F_187 , ( void * ) 8 ,
V_296 , V_298 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_202 ( V_14 , 0 , V_301 ,
F_189 , ( void * ) 1000000 ,
V_300 , V_74 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_202 ( V_14 , 0 , V_302 ,
F_189 , ( void * ) 1000000 ,
V_296 , V_74 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
return 0 ;
}
int F_203 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_55 * V_41 = & V_14 -> V_41 ;
int V_37 ;
unsigned int V_289 = 0 ;
if ( V_41 -> V_12 & V_304 )
V_289 |= 1 << V_305 ;
if ( V_41 -> V_12 & V_306 )
V_289 |= 1 << V_307 ;
if ( F_30 ( V_2 ) ) {
if ( V_41 -> V_12 & V_304 )
V_289 |= 1 << V_308 ;
if ( V_41 -> V_12 & V_306 )
V_289 |= 1 << V_309 ;
if ( V_41 -> V_12 & V_310 )
V_289 |= 1 << V_311 ;
}
V_37 = F_204 ( V_14 , V_312 , V_289 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_205 ( V_14 , V_101 , V_41 -> V_313 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_204 ( V_14 , V_314 , 1 << V_315 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_206 ( V_14 , V_102 ,
V_41 -> V_316 , V_41 -> V_317 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_206 ( V_14 , V_74 ,
V_41 -> V_318 , V_41 -> V_319 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_206 ( V_14 , V_299 ,
V_41 -> V_320 , V_41 -> V_321 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_206 ( V_14 , V_303 ,
V_41 -> V_322 , V_41 -> V_323 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_206 ( V_14 , V_297 ,
V_41 -> V_320 , V_41 -> V_295 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_202 ( V_14 , 0 , V_297 ,
F_198 , V_2 ,
V_297 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_14 -> V_324 ) {
V_37 = F_206 ( V_14 , V_297 , 0 , V_14 -> V_324 ) ;
if ( V_37 < 0 )
return V_37 ;
}
if ( ! ( V_41 -> V_294 & ( V_325 | V_326 ) ) ) {
V_37 = F_202 ( V_14 , 0 , V_74 ,
F_196 , V_41 ,
V_74 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
}
F_207 ( V_14 , V_300 ) ;
return 0 ;
}
static void F_208 ( struct V_1 * V_2 )
{
F_180 ( V_2 ) ;
}
void F_209 ( struct V_1 * V_2 )
{
V_2 -> V_327 -- ;
if ( V_2 -> V_327 > 0 )
return;
F_160 ( V_2 ) ;
if ( V_2 -> V_328 ) {
if ( V_2 -> V_33 -> V_148 != NULL )
V_2 -> V_33 -> V_148 ( V_2 ) ;
V_2 -> V_33 -> V_329 ( V_2 ) ;
V_2 -> V_328 = 0 ;
}
if ( F_71 ( & V_2 -> V_146 ) )
F_72 ( & V_2 -> V_146 ) ;
if ( V_2 -> V_330 ) {
V_2 -> V_330 ( V_2 ) ;
V_2 -> V_330 = NULL ;
}
F_210 ( V_2 ) ;
}
int F_211 ( struct V_15 * V_3 , int V_21 ,
struct V_248 * V_248 ,
struct V_1 * * V_331 )
{
struct V_1 * V_2 ;
int V_37 ;
V_37 = F_212 ( V_3 , V_21 , V_248 , & V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_2 -> V_327 > 1 ) {
* V_331 = V_2 ;
return 0 ;
}
V_37 = F_199 ( V_2 ) ;
if ( V_37 < 0 ) {
F_213 ( V_3 , L_13 ) ;
goto error;
}
if ( ( V_37 = V_2 -> V_33 -> V_332 ( V_2 ) ) < 0 )
goto error;
V_2 -> V_328 = 1 ;
V_37 = F_203 ( V_2 ) ;
if ( V_37 < 0 ) {
F_213 ( V_3 , L_14 ) ;
goto error;
}
* V_331 = V_2 ;
return 0 ;
error:
F_209 ( V_2 ) ;
return V_37 ;
}
static int F_214 ( struct V_248 * V_248 ,
struct V_15 * V_3 ,
int V_21 )
{
struct V_275 * V_276 ;
struct V_1 * V_2 ;
int V_37 ;
V_37 = F_211 ( V_3 , V_21 , V_248 , & V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
V_276 = F_215 ( sizeof( * V_276 ) , V_38 ) ;
if ( V_276 == NULL ) {
F_209 ( V_2 ) ;
return - V_39 ;
}
V_276 -> V_2 = V_2 ;
if ( V_2 -> V_327 == 1 ) {
V_2 -> V_248 = V_276 ;
V_2 -> V_330 = F_208 ;
}
V_248 -> V_281 = V_276 ;
return 0 ;
}
static int F_216 ( struct V_268 * V_268 , struct V_248 * V_248 )
{
struct V_15 * V_3 ;
int V_37 = F_217 ( V_268 , V_248 ) ;
if ( V_37 < 0 )
return V_37 ;
V_3 = F_166 ( F_165 ( V_268 ) ,
V_272 ) ;
V_37 = F_218 ( V_248 , V_3 , V_154 ) ;
if ( V_3 )
F_177 ( V_3 -> V_18 ) ;
return V_37 ;
}
static int F_219 ( struct V_268 * V_268 , struct V_248 * V_248 )
{
struct V_15 * V_3 ;
int V_37 = F_217 ( V_268 , V_248 ) ;
if ( V_37 < 0 )
return V_37 ;
V_3 = F_166 ( F_165 ( V_268 ) ,
V_273 ) ;
V_37 = F_218 ( V_248 , V_3 , V_333 ) ;
if ( V_3 )
F_177 ( V_3 -> V_18 ) ;
return V_37 ;
}
static int F_218 ( struct V_248 * V_248 , struct V_15 * V_3 , int V_21 )
{
int V_37 ;
T_5 V_252 ;
if ( V_3 == NULL ) {
V_37 = - V_265 ;
goto V_334;
}
V_37 = F_220 ( V_3 -> V_18 , V_248 ) ;
if ( V_37 < 0 )
goto V_334;
if ( ! F_221 ( V_3 -> V_18 -> V_335 ) ) {
V_37 = - V_40 ;
goto V_336;
}
F_154 ( & V_252 , V_260 ) ;
F_155 ( & V_3 -> V_337 , & V_252 ) ;
F_3 ( & V_3 -> V_338 ) ;
while ( 1 ) {
V_37 = F_214 ( V_248 , V_3 , V_21 ) ;
if ( V_37 >= 0 )
break;
if ( V_37 == - V_257 ) {
if ( V_248 -> V_246 & V_254 ) {
V_37 = - V_228 ;
break;
}
} else
break;
F_222 ( V_339 ) ;
F_7 ( & V_3 -> V_338 ) ;
F_223 () ;
F_3 ( & V_3 -> V_338 ) ;
if ( V_3 -> V_18 -> V_264 ) {
V_37 = - V_265 ;
break;
}
if ( F_153 ( V_260 ) ) {
V_37 = - V_261 ;
break;
}
}
F_158 ( & V_3 -> V_337 , & V_252 ) ;
F_7 ( & V_3 -> V_338 ) ;
if ( V_37 < 0 )
goto V_340;
return V_37 ;
V_340:
F_224 ( V_3 -> V_18 -> V_335 ) ;
V_336:
F_225 ( V_3 -> V_18 , V_248 ) ;
V_334:
return V_37 ;
}
static int F_226 ( struct V_268 * V_268 , struct V_248 * V_248 )
{
struct V_15 * V_3 ;
struct V_1 * V_2 ;
struct V_275 * V_276 ;
V_276 = V_248 -> V_281 ;
V_2 = V_276 -> V_2 ;
if ( F_227 ( ! V_2 ) )
return - V_112 ;
V_3 = V_2 -> V_3 ;
F_3 ( & V_3 -> V_338 ) ;
F_209 ( V_2 ) ;
F_29 ( V_276 ) ;
F_7 ( & V_3 -> V_338 ) ;
F_116 ( & V_3 -> V_337 ) ;
F_224 ( V_3 -> V_18 -> V_335 ) ;
F_225 ( V_3 -> V_18 , V_248 ) ;
return 0 ;
}
static T_6 F_228 ( struct V_1 * V_2 ,
T_3 V_111 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 V_174 ;
T_6 V_216 ;
T_6 V_341 ;
if ( V_111 == 0 )
return 0 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_109 -> V_108 ) {
case V_115 :
break;
case V_178 :
case V_177 :
if ( F_85 ( V_2 ) >= 0 )
break;
case V_217 :
V_216 = - V_201 ;
goto V_342;
case V_227 :
V_216 = - V_266 ;
goto V_342;
default:
V_216 = - V_116 ;
goto V_342;
}
V_341 = F_229 ( V_14 ) ;
if ( V_341 <= 0 ) {
V_216 = 0 ;
goto V_342;
}
if ( V_111 > ( T_3 ) V_341 )
V_111 = V_341 ;
V_174 = V_14 -> V_138 -> V_174 - V_111 ;
if ( V_174 < 0 )
V_174 += V_14 -> V_144 ;
V_14 -> V_138 -> V_174 = V_174 ;
V_216 = V_111 ;
V_342:
F_13 ( V_2 ) ;
return V_216 ;
}
static T_6 F_230 ( struct V_1 * V_2 ,
T_3 V_111 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 V_174 ;
T_6 V_216 ;
T_6 V_341 ;
if ( V_111 == 0 )
return 0 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_109 -> V_108 ) {
case V_115 :
case V_178 :
break;
case V_177 :
if ( F_85 ( V_2 ) >= 0 )
break;
case V_217 :
V_216 = - V_201 ;
goto V_342;
case V_227 :
V_216 = - V_266 ;
goto V_342;
default:
V_216 = - V_116 ;
goto V_342;
}
V_341 = F_231 ( V_14 ) ;
if ( V_341 <= 0 ) {
V_216 = 0 ;
goto V_342;
}
if ( V_111 > ( T_3 ) V_341 )
V_111 = V_341 ;
V_174 = V_14 -> V_138 -> V_174 - V_111 ;
if ( V_174 < 0 )
V_174 += V_14 -> V_144 ;
V_14 -> V_138 -> V_174 = V_174 ;
V_216 = V_111 ;
V_342:
F_13 ( V_2 ) ;
return V_216 ;
}
static T_6 F_232 ( struct V_1 * V_2 ,
T_3 V_111 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 V_174 ;
T_6 V_216 ;
T_6 V_176 ;
if ( V_111 == 0 )
return 0 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_109 -> V_108 ) {
case V_115 :
case V_221 :
break;
case V_178 :
case V_177 :
if ( F_85 ( V_2 ) >= 0 )
break;
case V_217 :
V_216 = - V_201 ;
goto V_342;
case V_227 :
V_216 = - V_266 ;
goto V_342;
default:
V_216 = - V_116 ;
goto V_342;
}
V_176 = F_88 ( V_14 ) ;
if ( V_176 <= 0 ) {
V_216 = 0 ;
goto V_342;
}
if ( V_111 > ( T_3 ) V_176 )
V_111 = V_176 ;
V_174 = V_14 -> V_138 -> V_174 + V_111 ;
if ( V_174 >= ( T_6 ) V_14 -> V_144 )
V_174 -= V_14 -> V_144 ;
V_14 -> V_138 -> V_174 = V_174 ;
V_216 = V_111 ;
V_342:
F_13 ( V_2 ) ;
return V_216 ;
}
static T_6 F_233 ( struct V_1 * V_2 ,
T_3 V_111 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 V_174 ;
T_6 V_216 ;
T_6 V_176 ;
if ( V_111 == 0 )
return 0 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_109 -> V_108 ) {
case V_115 :
case V_178 :
case V_221 :
break;
case V_177 :
if ( F_85 ( V_2 ) >= 0 )
break;
case V_217 :
V_216 = - V_201 ;
goto V_342;
case V_227 :
V_216 = - V_266 ;
goto V_342;
default:
V_216 = - V_116 ;
goto V_342;
}
V_176 = F_89 ( V_14 ) ;
if ( V_176 <= 0 ) {
V_216 = 0 ;
goto V_342;
}
if ( V_111 > ( T_3 ) V_176 )
V_111 = V_176 ;
V_174 = V_14 -> V_138 -> V_174 + V_111 ;
if ( V_174 >= ( T_6 ) V_14 -> V_144 )
V_174 -= V_14 -> V_144 ;
V_14 -> V_138 -> V_174 = V_174 ;
V_216 = V_111 ;
V_342:
F_13 ( V_2 ) ;
return V_216 ;
}
static int F_234 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_37 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_109 -> V_108 ) {
case V_178 :
if ( V_2 -> V_21 == V_333 )
goto V_343;
case V_177 :
if ( ( V_37 = F_85 ( V_2 ) ) < 0 )
break;
case V_115 :
case V_227 :
V_37 = 0 ;
break;
case V_217 :
V_37 = - V_201 ;
break;
default:
V_343:
V_37 = - V_116 ;
break;
}
F_13 ( V_2 ) ;
return V_37 ;
}
static int F_235 ( struct V_1 * V_2 ,
T_6 T_2 * V_184 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_37 ;
T_6 V_344 = 0 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_109 -> V_108 ) {
case V_178 :
if ( V_2 -> V_21 == V_333 )
goto V_343;
case V_177 :
if ( ( V_37 = F_85 ( V_2 ) ) < 0 )
break;
case V_115 :
case V_227 :
V_37 = 0 ;
if ( V_2 -> V_21 == V_154 )
V_344 = F_229 ( V_14 ) ;
else
V_344 = F_89 ( V_14 ) ;
V_344 += V_14 -> V_179 ;
break;
case V_217 :
V_37 = - V_201 ;
break;
default:
V_343:
V_37 = - V_116 ;
break;
}
F_13 ( V_2 ) ;
if ( ! V_37 )
if ( F_236 ( V_344 , V_184 ) )
V_37 = - V_40 ;
return V_37 ;
}
static int F_237 ( struct V_1 * V_2 ,
struct F_237 T_2 * V_345 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct F_237 V_346 ;
volatile struct V_347 * V_109 ;
volatile struct V_348 * V_138 ;
int V_37 ;
memset ( & V_346 , 0 , sizeof( V_346 ) ) ;
if ( F_91 ( V_346 . V_10 , ( unsigned T_2 * ) & ( V_345 -> V_10 ) ) )
return - V_40 ;
if ( F_82 ( & V_346 . V_349 . V_138 , & ( V_345 -> V_349 . V_138 ) , sizeof( struct V_348 ) ) )
return - V_40 ;
V_109 = V_14 -> V_109 ;
V_138 = V_14 -> V_138 ;
if ( V_346 . V_10 & V_350 ) {
V_37 = F_234 ( V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
}
F_11 ( V_2 ) ;
if ( ! ( V_346 . V_10 & V_351 ) )
V_138 -> V_174 = V_346 . V_349 . V_138 . V_174 ;
else
V_346 . V_349 . V_138 . V_174 = V_138 -> V_174 ;
if ( ! ( V_346 . V_10 & V_352 ) )
V_138 -> V_139 = V_346 . V_349 . V_138 . V_139 ;
else
V_346 . V_349 . V_138 . V_139 = V_138 -> V_139 ;
V_346 . V_192 . V_109 . V_108 = V_109 -> V_108 ;
V_346 . V_192 . V_109 . V_175 = V_109 -> V_175 ;
V_346 . V_192 . V_109 . V_169 = V_109 -> V_169 ;
V_346 . V_192 . V_109 . V_165 = V_109 -> V_165 ;
F_13 ( V_2 ) ;
if ( F_28 ( V_345 , & V_346 , sizeof( V_346 ) ) )
return - V_40 ;
return 0 ;
}
static int F_238 ( struct V_1 * V_2 , int T_2 * V_353 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_354 ;
if ( F_91 ( V_354 , V_353 ) )
return - V_40 ;
if ( V_354 < 0 || V_354 > V_153 )
return - V_79 ;
V_14 -> V_152 = V_354 ;
return 0 ;
}
static int F_239 ( struct V_248 * V_248 ,
struct V_1 * V_2 ,
unsigned int V_355 , void T_2 * V_354 )
{
switch ( V_355 ) {
case V_356 :
return F_236 ( V_357 , ( int T_2 * ) V_354 ) ? - V_40 : 0 ;
case V_358 :
return F_26 ( V_2 , V_354 ) ;
case V_359 :
return 0 ;
case V_360 :
return F_238 ( V_2 , V_354 ) ;
case V_361 :
return F_51 ( V_2 , V_354 ) ;
case V_362 :
return F_74 ( V_2 , V_354 ) ;
case V_363 :
return F_75 ( V_2 ) ;
case V_364 :
return F_81 ( V_2 , V_354 ) ;
case V_365 :
return F_90 ( V_2 , V_354 , false ) ;
case V_366 :
return F_90 ( V_2 , V_354 , true ) ;
case V_367 :
return F_93 ( V_2 , V_354 ) ;
case V_368 :
return F_147 ( V_2 , V_248 ) ;
case V_369 :
return F_143 ( V_2 ) ;
case V_370 :
return F_104 ( & V_211 , V_2 , V_177 ) ;
case V_371 :
return F_167 ( V_2 , ( int ) ( unsigned long ) V_354 ) ;
case V_372 :
return F_180 ( V_2 ) ;
case V_373 :
return F_135 ( V_2 ) ;
case V_374 :
return F_139 ( V_2 ) ;
case V_375 :
return F_234 ( V_2 ) ;
case V_376 :
return F_235 ( V_2 , V_354 ) ;
case V_377 :
return F_237 ( V_2 , V_354 ) ;
#ifdef F_240
case V_378 :
return F_241 ( V_2 , V_354 ) ;
case V_379 :
return F_242 ( V_2 , V_354 ) ;
#endif
case V_380 :
return F_152 ( V_2 , V_248 ) ;
case V_381 :
return F_160 ( V_2 ) ;
case V_382 :
{
int V_184 ;
F_11 ( V_2 ) ;
V_184 = F_125 ( V_2 , ( int ) ( unsigned long ) V_354 ) ;
F_13 ( V_2 ) ;
return V_184 ;
}
}
F_213 ( V_2 -> V_3 , L_15 , V_355 ) ;
return - V_383 ;
}
static int F_243 ( struct V_248 * V_248 ,
struct V_1 * V_2 ,
unsigned int V_355 , void T_2 * V_354 )
{
if ( F_227 ( ! V_2 ) )
return - V_112 ;
if ( F_227 ( V_2 -> V_21 != V_154 ) )
return - V_79 ;
switch ( V_355 ) {
case V_384 :
{
struct V_385 V_386 ;
struct V_385 T_2 * V_387 = V_354 ;
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 V_149 ;
if ( V_14 -> V_109 -> V_108 == V_113 )
return - V_116 ;
if ( F_236 ( 0 , & V_387 -> V_149 ) )
return - V_40 ;
if ( F_82 ( & V_386 , V_387 , sizeof( V_386 ) ) )
return - V_40 ;
V_149 = F_244 ( V_2 , V_386 . V_388 , V_386 . V_111 ) ;
F_245 ( V_149 , & V_387 -> V_149 ) ;
return V_149 < 0 ? V_149 : 0 ;
}
case V_389 :
{
struct V_390 V_391 ;
struct V_390 T_2 * V_392 = V_354 ;
struct V_13 * V_14 = V_2 -> V_14 ;
void T_2 * * V_393 ;
T_6 V_149 ;
if ( V_14 -> V_109 -> V_108 == V_113 )
return - V_116 ;
if ( V_14 -> V_125 > 128 )
return - V_79 ;
if ( F_236 ( 0 , & V_392 -> V_149 ) )
return - V_40 ;
if ( F_82 ( & V_391 , V_392 , sizeof( V_391 ) ) )
return - V_40 ;
V_393 = F_52 ( V_391 . V_393 ,
sizeof( void * ) * V_14 -> V_125 ) ;
if ( F_53 ( V_393 ) )
return F_54 ( V_393 ) ;
V_149 = F_246 ( V_2 , V_393 , V_391 . V_111 ) ;
F_29 ( V_393 ) ;
F_245 ( V_149 , & V_392 -> V_149 ) ;
return V_149 < 0 ? V_149 : 0 ;
}
case V_394 :
{
T_3 V_111 ;
T_3 T_2 * V_395 = V_354 ;
T_6 V_149 ;
if ( F_91 ( V_111 , V_395 ) )
return - V_40 ;
if ( F_236 ( 0 , V_395 ) )
return - V_40 ;
V_149 = F_228 ( V_2 , V_111 ) ;
F_245 ( V_149 , V_395 ) ;
return V_149 < 0 ? V_149 : 0 ;
}
case V_396 :
{
T_3 V_111 ;
T_3 T_2 * V_395 = V_354 ;
T_6 V_149 ;
if ( F_91 ( V_111 , V_395 ) )
return - V_40 ;
if ( F_236 ( 0 , V_395 ) )
return - V_40 ;
V_149 = F_232 ( V_2 , V_111 ) ;
F_245 ( V_149 , V_395 ) ;
return V_149 < 0 ? V_149 : 0 ;
}
}
return F_239 ( V_248 , V_2 , V_355 , V_354 ) ;
}
static int F_247 ( struct V_248 * V_248 ,
struct V_1 * V_2 ,
unsigned int V_355 , void T_2 * V_354 )
{
if ( F_227 ( ! V_2 ) )
return - V_112 ;
if ( F_227 ( V_2 -> V_21 != V_333 ) )
return - V_79 ;
switch ( V_355 ) {
case V_397 :
{
struct V_385 V_386 ;
struct V_385 T_2 * V_387 = V_354 ;
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 V_149 ;
if ( V_14 -> V_109 -> V_108 == V_113 )
return - V_116 ;
if ( F_236 ( 0 , & V_387 -> V_149 ) )
return - V_40 ;
if ( F_82 ( & V_386 , V_387 , sizeof( V_386 ) ) )
return - V_40 ;
V_149 = F_248 ( V_2 , V_386 . V_388 , V_386 . V_111 ) ;
F_245 ( V_149 , & V_387 -> V_149 ) ;
return V_149 < 0 ? V_149 : 0 ;
}
case V_398 :
{
struct V_390 V_391 ;
struct V_390 T_2 * V_392 = V_354 ;
struct V_13 * V_14 = V_2 -> V_14 ;
void * V_393 ;
T_6 V_149 ;
if ( V_14 -> V_109 -> V_108 == V_113 )
return - V_116 ;
if ( V_14 -> V_125 > 128 )
return - V_79 ;
if ( F_236 ( 0 , & V_392 -> V_149 ) )
return - V_40 ;
if ( F_82 ( & V_391 , V_392 , sizeof( V_391 ) ) )
return - V_40 ;
V_393 = F_52 ( V_391 . V_393 ,
sizeof( void * ) * V_14 -> V_125 ) ;
if ( F_53 ( V_393 ) )
return F_54 ( V_393 ) ;
V_149 = F_249 ( V_2 , V_393 , V_391 . V_111 ) ;
F_29 ( V_393 ) ;
F_245 ( V_149 , & V_392 -> V_149 ) ;
return V_149 < 0 ? V_149 : 0 ;
}
case V_394 :
{
T_3 V_111 ;
T_3 T_2 * V_395 = V_354 ;
T_6 V_149 ;
if ( F_91 ( V_111 , V_395 ) )
return - V_40 ;
if ( F_236 ( 0 , V_395 ) )
return - V_40 ;
V_149 = F_230 ( V_2 , V_111 ) ;
F_245 ( V_149 , V_395 ) ;
return V_149 < 0 ? V_149 : 0 ;
}
case V_396 :
{
T_3 V_111 ;
T_3 T_2 * V_395 = V_354 ;
T_6 V_149 ;
if ( F_91 ( V_111 , V_395 ) )
return - V_40 ;
if ( F_236 ( 0 , V_395 ) )
return - V_40 ;
V_149 = F_233 ( V_2 , V_111 ) ;
F_245 ( V_149 , V_395 ) ;
return V_149 < 0 ? V_149 : 0 ;
}
}
return F_239 ( V_248 , V_2 , V_355 , V_354 ) ;
}
static long F_250 ( struct V_248 * V_248 , unsigned int V_355 ,
unsigned long V_354 )
{
struct V_275 * V_276 ;
V_276 = V_248 -> V_281 ;
if ( ( ( V_355 >> 8 ) & 0xff ) != 'A' )
return - V_383 ;
return F_243 ( V_248 , V_276 -> V_2 , V_355 ,
( void T_2 * ) V_354 ) ;
}
static long F_251 ( struct V_248 * V_248 , unsigned int V_355 ,
unsigned long V_354 )
{
struct V_275 * V_276 ;
V_276 = V_248 -> V_281 ;
if ( ( ( V_355 >> 8 ) & 0xff ) != 'A' )
return - V_383 ;
return F_247 ( V_248 , V_276 -> V_2 , V_355 ,
( void T_2 * ) V_354 ) ;
}
int F_252 ( struct V_1 * V_2 ,
unsigned int V_355 , void * V_354 )
{
T_1 V_11 ;
int V_149 ;
V_11 = F_19 () ;
switch ( V_2 -> V_21 ) {
case V_154 :
V_149 = F_243 ( NULL , V_2 , V_355 ,
( void T_2 * ) V_354 ) ;
break;
case V_333 :
V_149 = F_247 ( NULL , V_2 , V_355 ,
( void T_2 * ) V_354 ) ;
break;
default:
V_149 = - V_79 ;
break;
}
F_23 ( V_11 ) ;
return V_149 ;
}
static T_7 F_253 ( struct V_248 * V_248 , char T_2 * V_388 , T_8 V_286 ,
T_9 * V_399 )
{
struct V_275 * V_276 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
T_6 V_149 ;
V_276 = V_248 -> V_281 ;
V_2 = V_276 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_112 ;
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_109 -> V_108 == V_113 )
return - V_116 ;
if ( ! F_254 ( V_14 , V_286 ) )
return - V_79 ;
V_286 = F_255 ( V_14 , V_286 ) ;
V_149 = F_248 ( V_2 , V_388 , V_286 ) ;
if ( V_149 > 0 )
V_149 = F_256 ( V_14 , V_149 ) ;
return V_149 ;
}
static T_7 F_257 ( struct V_248 * V_248 , const char T_2 * V_388 ,
T_8 V_286 , T_9 * V_399 )
{
struct V_275 * V_276 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
T_6 V_149 ;
V_276 = V_248 -> V_281 ;
V_2 = V_276 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_112 ;
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_109 -> V_108 == V_113 )
return - V_116 ;
if ( ! F_254 ( V_14 , V_286 ) )
return - V_79 ;
V_286 = F_255 ( V_14 , V_286 ) ;
V_149 = F_244 ( V_2 , V_388 , V_286 ) ;
if ( V_149 > 0 )
V_149 = F_256 ( V_14 , V_149 ) ;
return V_149 ;
}
static T_7 F_258 ( struct V_400 * V_401 , struct V_402 * V_403 )
{
struct V_275 * V_276 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
T_6 V_149 ;
unsigned long V_57 ;
void T_2 * * V_393 ;
T_3 V_111 ;
V_276 = V_401 -> V_404 -> V_281 ;
V_2 = V_276 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_112 ;
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_109 -> V_108 == V_113 )
return - V_116 ;
if ( ! F_259 ( V_403 ) )
return - V_79 ;
if ( V_403 -> V_405 > 1024 || V_403 -> V_405 != V_14 -> V_125 )
return - V_79 ;
if ( ! F_254 ( V_14 , V_403 -> V_406 -> V_407 ) )
return - V_79 ;
V_111 = F_260 ( V_14 , V_403 -> V_406 -> V_407 ) ;
V_393 = F_27 ( sizeof( void * ) * V_403 -> V_405 , V_38 ) ;
if ( V_393 == NULL )
return - V_39 ;
for ( V_57 = 0 ; V_57 < V_403 -> V_405 ; ++ V_57 )
V_393 [ V_57 ] = V_403 -> V_406 [ V_57 ] . V_408 ;
V_149 = F_249 ( V_2 , V_393 , V_111 ) ;
if ( V_149 > 0 )
V_149 = F_256 ( V_14 , V_149 ) ;
F_29 ( V_393 ) ;
return V_149 ;
}
static T_7 F_261 ( struct V_400 * V_401 , struct V_402 * V_409 )
{
struct V_275 * V_276 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
T_6 V_149 ;
unsigned long V_57 ;
void T_2 * * V_393 ;
T_3 V_111 ;
V_276 = V_401 -> V_404 -> V_281 ;
V_2 = V_276 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_112 ;
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_109 -> V_108 == V_113 )
return - V_116 ;
if ( ! F_259 ( V_409 ) )
return - V_79 ;
if ( V_409 -> V_405 > 128 || V_409 -> V_405 != V_14 -> V_125 ||
! F_254 ( V_14 , V_409 -> V_406 -> V_407 ) )
return - V_79 ;
V_111 = F_260 ( V_14 , V_409 -> V_406 -> V_407 ) ;
V_393 = F_27 ( sizeof( void * ) * V_409 -> V_405 , V_38 ) ;
if ( V_393 == NULL )
return - V_39 ;
for ( V_57 = 0 ; V_57 < V_409 -> V_405 ; ++ V_57 )
V_393 [ V_57 ] = V_409 -> V_406 [ V_57 ] . V_408 ;
V_149 = F_246 ( V_2 , V_393 , V_111 ) ;
if ( V_149 > 0 )
V_149 = F_256 ( V_14 , V_149 ) ;
F_29 ( V_393 ) ;
return V_149 ;
}
static unsigned int F_262 ( struct V_248 * V_248 , T_10 * V_252 )
{
struct V_275 * V_276 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
unsigned int V_289 ;
T_3 V_176 ;
V_276 = V_248 -> V_281 ;
V_2 = V_276 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_112 ;
V_14 = V_2 -> V_14 ;
F_263 ( V_248 , & V_14 -> V_213 , V_252 ) ;
F_11 ( V_2 ) ;
V_176 = F_88 ( V_14 ) ;
switch ( V_14 -> V_109 -> V_108 ) {
case V_177 :
case V_115 :
case V_221 :
if ( V_176 >= V_14 -> V_138 -> V_139 ) {
V_289 = V_410 | V_411 ;
break;
}
case V_178 :
V_289 = 0 ;
break;
default:
V_289 = V_410 | V_411 | V_412 ;
break;
}
F_13 ( V_2 ) ;
return V_289 ;
}
static unsigned int F_264 ( struct V_248 * V_248 , T_10 * V_252 )
{
struct V_275 * V_276 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
unsigned int V_289 ;
T_3 V_176 ;
V_276 = V_248 -> V_281 ;
V_2 = V_276 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_112 ;
V_14 = V_2 -> V_14 ;
F_263 ( V_248 , & V_14 -> V_213 , V_252 ) ;
F_11 ( V_2 ) ;
V_176 = F_89 ( V_14 ) ;
switch ( V_14 -> V_109 -> V_108 ) {
case V_177 :
case V_115 :
case V_221 :
if ( V_176 >= V_14 -> V_138 -> V_139 ) {
V_289 = V_413 | V_414 ;
break;
}
V_289 = 0 ;
break;
case V_178 :
if ( V_176 > 0 ) {
V_289 = V_413 | V_414 ;
break;
}
default:
V_289 = V_413 | V_414 | V_412 ;
break;
}
F_13 ( V_2 ) ;
return V_289 ;
}
static int F_265 ( struct V_415 * V_416 ,
struct V_417 * V_418 )
{
struct V_1 * V_2 = V_416 -> V_419 ;
struct V_13 * V_14 ;
if ( V_2 == NULL )
return V_420 ;
V_14 = V_2 -> V_14 ;
V_418 -> V_421 = F_266 ( V_14 -> V_109 ) ;
F_267 ( V_418 -> V_421 ) ;
return 0 ;
}
static int V_347 ( struct V_1 * V_2 , struct V_248 * V_248 ,
struct V_415 * V_416 )
{
long V_422 ;
if ( ! ( V_416 -> V_423 & V_424 ) )
return - V_79 ;
V_422 = V_416 -> V_425 - V_416 -> V_426 ;
if ( V_422 != F_268 ( sizeof( struct V_347 ) ) )
return - V_79 ;
V_416 -> V_427 = & V_428 ;
V_416 -> V_419 = V_2 ;
V_416 -> V_423 |= V_429 | V_430 ;
return 0 ;
}
static int F_269 ( struct V_415 * V_416 ,
struct V_417 * V_418 )
{
struct V_1 * V_2 = V_416 -> V_419 ;
struct V_13 * V_14 ;
if ( V_2 == NULL )
return V_420 ;
V_14 = V_2 -> V_14 ;
V_418 -> V_421 = F_266 ( V_14 -> V_138 ) ;
F_267 ( V_418 -> V_421 ) ;
return 0 ;
}
static int V_348 ( struct V_1 * V_2 , struct V_248 * V_248 ,
struct V_415 * V_416 )
{
long V_422 ;
if ( ! ( V_416 -> V_423 & V_424 ) )
return - V_79 ;
V_422 = V_416 -> V_425 - V_416 -> V_426 ;
if ( V_422 != F_268 ( sizeof( struct V_348 ) ) )
return - V_79 ;
V_416 -> V_427 = & V_431 ;
V_416 -> V_419 = V_2 ;
V_416 -> V_423 |= V_429 | V_430 ;
return 0 ;
}
static int V_347 ( struct V_1 * V_2 , struct V_248 * V_248 ,
struct V_415 * V_416 )
{
return - V_112 ;
}
static int V_348 ( struct V_1 * V_2 , struct V_248 * V_248 ,
struct V_415 * V_416 )
{
return - V_112 ;
}
static inline struct V_421 *
F_270 ( struct V_1 * V_2 , unsigned long V_432 )
{
void * V_433 = V_2 -> V_14 -> V_434 + V_432 ;
return F_266 ( V_433 ) ;
}
static int F_271 ( struct V_415 * V_416 ,
struct V_417 * V_418 )
{
struct V_1 * V_2 = V_416 -> V_419 ;
struct V_13 * V_14 ;
unsigned long V_399 ;
struct V_421 * V_421 ;
T_8 V_324 ;
if ( V_2 == NULL )
return V_420 ;
V_14 = V_2 -> V_14 ;
V_399 = V_418 -> V_435 << V_436 ;
V_324 = F_268 ( V_14 -> V_324 ) ;
if ( V_399 > V_324 - V_437 )
return V_420 ;
if ( V_2 -> V_33 -> V_421 )
V_421 = V_2 -> V_33 -> V_421 ( V_2 , V_399 ) ;
else
V_421 = F_270 ( V_2 , V_399 ) ;
if ( ! V_421 )
return V_420 ;
F_267 ( V_421 ) ;
V_418 -> V_421 = V_421 ;
return 0 ;
}
int F_272 ( struct V_1 * V_2 ,
struct V_415 * V_416 )
{
V_416 -> V_423 |= V_429 | V_430 ;
#ifdef F_273
if ( V_2 -> V_49 . V_50 . type == V_438 ) {
V_416 -> V_439 = F_274 ( V_416 -> V_439 ) ;
return F_275 ( V_416 , V_416 -> V_426 ,
V_2 -> V_49 . V_440 >> V_436 ,
V_416 -> V_425 - V_416 -> V_426 , V_416 -> V_439 ) ;
}
#endif
#ifndef F_276
if ( ! V_2 -> V_33 -> V_421 &&
V_2 -> V_49 . V_50 . type == V_51 )
return F_277 ( V_2 -> V_49 . V_50 . V_50 ,
V_416 ,
V_2 -> V_14 -> V_434 ,
V_2 -> V_14 -> V_441 ,
V_416 -> V_425 - V_416 -> V_426 ) ;
#endif
V_416 -> V_427 = & V_442 ;
return 0 ;
}
int F_278 ( struct V_1 * V_2 ,
struct V_415 * V_416 )
{
struct V_13 * V_14 = V_2 -> V_14 ; ;
V_416 -> V_439 = F_279 ( V_416 -> V_439 ) ;
return F_280 ( V_416 , V_14 -> V_441 , V_14 -> V_324 ) ;
}
int F_281 ( struct V_1 * V_2 , struct V_248 * V_248 ,
struct V_415 * V_416 )
{
struct V_13 * V_14 ;
long V_422 ;
unsigned long V_399 ;
T_8 V_324 ;
int V_37 ;
if ( V_2 -> V_21 == V_154 ) {
if ( ! ( V_416 -> V_423 & ( V_443 | V_424 ) ) )
return - V_79 ;
} else {
if ( ! ( V_416 -> V_423 & V_424 ) )
return - V_79 ;
}
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_109 -> V_108 == V_113 )
return - V_116 ;
if ( ! ( V_14 -> V_12 & V_42 ) )
return - V_112 ;
if ( V_14 -> V_122 == V_305 ||
V_14 -> V_122 == V_307 )
return - V_79 ;
V_422 = V_416 -> V_425 - V_416 -> V_426 ;
V_399 = V_416 -> V_444 << V_436 ;
V_324 = F_268 ( V_14 -> V_324 ) ;
if ( ( T_8 ) V_422 > V_324 )
return - V_79 ;
if ( V_399 > V_324 - V_422 )
return - V_79 ;
V_416 -> V_427 = & V_445 ;
V_416 -> V_419 = V_2 ;
if ( V_2 -> V_33 -> V_48 )
V_37 = V_2 -> V_33 -> V_48 ( V_2 , V_416 ) ;
else
V_37 = F_272 ( V_2 , V_416 ) ;
if ( ! V_37 )
F_282 ( & V_2 -> V_119 ) ;
return V_37 ;
}
static int F_283 ( struct V_248 * V_248 , struct V_415 * V_416 )
{
struct V_275 * V_276 ;
struct V_1 * V_2 ;
unsigned long V_399 ;
V_276 = V_248 -> V_281 ;
V_2 = V_276 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_112 ;
V_399 = V_416 -> V_444 << V_436 ;
switch ( V_399 ) {
case V_446 :
if ( V_276 -> V_447 )
return - V_112 ;
return V_347 ( V_2 , V_248 , V_416 ) ;
case V_448 :
if ( V_276 -> V_447 )
return - V_112 ;
return V_348 ( V_2 , V_248 , V_416 ) ;
default:
return F_281 ( V_2 , V_248 , V_416 ) ;
}
return 0 ;
}
static int F_284 ( int V_274 , struct V_248 * V_248 , int V_449 )
{
struct V_275 * V_276 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
V_276 = V_248 -> V_281 ;
V_2 = V_276 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_112 ;
V_14 = V_2 -> V_14 ;
return F_285 ( V_274 , V_248 , V_449 , & V_14 -> V_450 ) ;
}
static void F_286 ( struct V_52 * V_53 ,
struct V_451 * V_452 )
{
unsigned int V_57 ;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
V_53 -> V_10 = V_452 -> V_10 ;
for ( V_57 = 0 ; V_57 < F_287 ( V_452 -> V_453 ) ; V_57 ++ )
V_53 -> V_453 [ V_57 ] . V_81 [ 0 ] = V_452 -> V_453 [ V_57 ] ;
memcpy ( V_53 -> V_454 , V_452 -> V_454 , sizeof( V_452 -> V_454 ) ) ;
V_53 -> V_71 = F_288 ( V_452 -> V_71 ) ;
V_53 -> V_82 = F_288 ( V_452 -> V_82 ) ;
V_53 -> V_12 = V_452 -> V_12 ;
V_53 -> V_73 = V_452 -> V_73 ;
V_53 -> V_75 = V_452 -> V_75 ;
V_53 -> V_76 = V_452 -> V_76 ;
V_53 -> V_70 = V_452 -> V_70 ;
}
static void F_289 ( struct V_451 * V_452 ,
struct V_52 * V_53 )
{
unsigned int V_57 ;
memset ( V_452 , 0 , sizeof( * V_452 ) ) ;
V_452 -> V_10 = V_53 -> V_10 ;
for ( V_57 = 0 ; V_57 < F_287 ( V_452 -> V_453 ) ; V_57 ++ )
V_452 -> V_453 [ V_57 ] = V_53 -> V_453 [ V_57 ] . V_81 [ 0 ] ;
memcpy ( V_452 -> V_454 , V_53 -> V_454 , sizeof( V_452 -> V_454 ) ) ;
V_452 -> V_71 = F_290 ( V_53 -> V_71 ) ;
V_452 -> V_82 = F_290 ( V_53 -> V_82 ) ;
V_452 -> V_12 = V_53 -> V_12 ;
V_452 -> V_73 = V_53 -> V_73 ;
V_452 -> V_75 = V_53 -> V_75 ;
V_452 -> V_76 = V_53 -> V_76 ;
V_452 -> V_70 = V_53 -> V_70 ;
}
static int F_241 ( struct V_1 * V_2 ,
struct V_451 T_2 * V_455 )
{
struct V_52 * V_53 ;
struct V_451 * V_452 = NULL ;
int V_37 ;
V_53 = F_27 ( sizeof( * V_53 ) , V_38 ) ;
if ( ! V_53 )
return - V_39 ;
V_452 = F_52 ( V_455 , sizeof( * V_452 ) ) ;
if ( F_53 ( V_452 ) ) {
V_37 = F_54 ( V_452 ) ;
goto V_456;
}
F_286 ( V_53 , V_452 ) ;
V_37 = F_32 ( V_2 , V_53 ) ;
F_289 ( V_452 , V_53 ) ;
if ( F_28 ( V_455 , V_452 , sizeof( * V_452 ) ) ) {
if ( ! V_37 )
V_37 = - V_40 ;
}
F_29 ( V_452 ) ;
V_456:
F_29 ( V_53 ) ;
return V_37 ;
}
static int F_242 ( struct V_1 * V_2 ,
struct V_451 T_2 * V_455 )
{
struct V_52 * V_53 ;
struct V_451 * V_452 = NULL ;
int V_37 ;
V_53 = F_27 ( sizeof( * V_53 ) , V_38 ) ;
if ( ! V_53 )
return - V_39 ;
V_452 = F_52 ( V_455 , sizeof( * V_452 ) ) ;
if ( F_53 ( V_452 ) ) {
V_37 = F_54 ( V_452 ) ;
goto V_456;
}
F_286 ( V_53 , V_452 ) ;
V_37 = V_52 ( V_2 , V_53 ) ;
F_289 ( V_452 , V_53 ) ;
if ( F_28 ( V_455 , V_452 , sizeof( * V_452 ) ) ) {
if ( ! V_37 )
V_37 = - V_40 ;
}
F_29 ( V_452 ) ;
V_456:
F_29 ( V_53 ) ;
return V_37 ;
}
static unsigned long F_291 ( struct V_248 * V_248 ,
unsigned long V_440 ,
unsigned long V_457 ,
unsigned long V_435 ,
unsigned long V_10 )
{
struct V_275 * V_276 = V_248 -> V_281 ;
struct V_1 * V_2 = V_276 -> V_2 ;
struct V_13 * V_14 = V_2 -> V_14 ;
unsigned long V_399 = V_435 << V_436 ;
switch ( V_399 ) {
case V_446 :
return ( unsigned long ) V_14 -> V_109 ;
case V_448 :
return ( unsigned long ) V_14 -> V_138 ;
default:
return ( unsigned long ) V_14 -> V_434 + V_399 ;
}
}
