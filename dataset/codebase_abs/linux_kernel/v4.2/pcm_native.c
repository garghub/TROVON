void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 ) {
F_2 ( & V_5 , V_6 ) ;
F_3 ( & V_2 -> V_7 . V_8 ) ;
} else {
F_4 ( & V_9 ) ;
F_5 ( & V_2 -> V_7 . V_10 ) ;
}
}
void F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 ) {
F_7 ( & V_2 -> V_7 . V_8 ) ;
F_8 ( & V_5 ) ;
} else {
F_9 ( & V_2 -> V_7 . V_10 ) ;
F_10 ( & V_9 ) ;
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
unsigned long V_11 = 0 ;
if ( ! V_2 -> V_3 -> V_4 )
F_16 ( V_11 ) ;
F_1 ( V_2 ) ;
return V_11 ;
}
void F_17 ( struct V_1 * V_2 ,
unsigned long V_11 )
{
F_6 ( V_2 ) ;
if ( ! V_2 -> V_3 -> V_4 )
F_18 ( V_11 ) ;
}
static inline T_1 F_19 ( void )
{
T_1 V_12 = F_20 () ;
F_21 ( F_22 () ) ;
return V_12 ;
}
static inline void F_23 ( T_1 V_12 )
{
F_21 ( V_12 ) ;
}
int F_24 ( struct V_1 * V_2 , struct F_24 * V_13 )
{
struct V_14 * V_15 ;
struct V_16 * V_3 = V_2 -> V_3 ;
struct V_17 * V_18 = V_2 -> V_18 ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_19 = V_3 -> V_19 -> V_20 ;
V_13 -> V_21 = V_3 -> V_21 ;
V_13 -> V_22 = V_2 -> V_22 ;
V_13 -> V_23 = V_2 -> V_20 ;
F_25 ( V_13 -> V_24 , V_3 -> V_24 , sizeof( V_13 -> V_24 ) ) ;
F_25 ( V_13 -> V_25 , V_3 -> V_25 , sizeof( V_13 -> V_25 ) ) ;
V_13 -> V_26 = V_3 -> V_26 ;
V_13 -> V_27 = V_3 -> V_27 ;
V_13 -> V_28 = V_18 -> V_29 ;
V_13 -> V_30 = V_18 -> V_29 - V_18 -> V_31 ;
F_25 ( V_13 -> V_32 , V_2 -> V_25 , sizeof( V_13 -> V_32 ) ) ;
V_15 = V_2 -> V_15 ;
if ( V_15 ) {
V_13 -> V_33 = V_15 -> V_33 ;
V_2 -> V_34 -> V_35 ( V_2 , V_36 , V_13 ) ;
}
return 0 ;
}
int F_26 ( struct V_1 * V_2 ,
struct F_24 T_2 * V_37 )
{
struct F_24 * V_13 ;
int V_38 ;
V_13 = F_27 ( sizeof( * V_13 ) , V_39 ) ;
if ( ! V_13 )
return - V_40 ;
V_38 = F_24 ( V_2 , V_13 ) ;
if ( V_38 >= 0 ) {
if ( F_28 ( V_37 , V_13 , sizeof( * V_13 ) ) )
V_38 = - V_41 ;
}
F_29 ( V_13 ) ;
return V_38 ;
}
static bool F_30 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_15 -> V_42 . V_13 & V_43 ) )
return false ;
#if F_31 ( V_44 ) || F_31 ( V_45 ) || F_31 ( V_46 ) ||\
F_31 ( V_47 ) || F_31 ( V_48 )
if ( ! V_2 -> V_34 -> V_49 &&
V_2 -> V_50 . V_51 . type == V_52 )
return false ;
#endif
return true ;
}
int F_32 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
unsigned int V_55 ;
struct V_56 * V_42 ;
struct V_57 * V_58 = NULL ;
struct V_59 * V_60 = NULL ;
struct V_61 * V_62 = & V_2 -> V_15 -> V_63 ;
unsigned int V_64 [ V_62 -> V_65 ] ;
unsigned int V_66 [ V_67 + 1 ] ;
unsigned int V_68 = 2 ;
int V_69 , V_70 ;
V_54 -> V_13 = 0 ;
V_54 -> V_71 = 0 ;
if ( V_54 -> V_72 & ( 1 << V_73 ) )
V_54 -> V_74 = 0 ;
if ( V_54 -> V_72 & ( 1 << V_75 ) ) {
V_54 -> V_76 = 0 ;
V_54 -> V_77 = 0 ;
}
for ( V_55 = V_78 ; V_55 <= V_79 ; V_55 ++ ) {
V_60 = F_33 ( V_54 , V_55 ) ;
if ( F_34 ( V_60 ) )
return - V_80 ;
if ( ! ( V_54 -> V_72 & ( 1 << V_55 ) ) )
continue;
#ifdef F_35
F_36 ( L_1 , V_81 [ V_55 ] ) ;
F_37 ( L_2 , V_60 -> V_82 [ 3 ] , V_60 -> V_82 [ 2 ] , V_60 -> V_82 [ 1 ] , V_60 -> V_82 [ 0 ] ) ;
#endif
V_69 = F_38 ( V_60 , F_39 ( V_62 , V_55 ) ) ;
#ifdef F_35
F_37 ( L_3 , V_60 -> V_82 [ 3 ] , V_60 -> V_82 [ 2 ] , V_60 -> V_82 [ 1 ] , V_60 -> V_82 [ 0 ] ) ;
#endif
if ( V_69 )
V_54 -> V_83 |= 1 << V_55 ;
if ( V_69 < 0 )
return V_69 ;
}
for ( V_55 = V_84 ; V_55 <= V_67 ; V_55 ++ ) {
V_58 = F_40 ( V_54 , V_55 ) ;
if ( F_41 ( V_58 ) )
return - V_80 ;
if ( ! ( V_54 -> V_72 & ( 1 << V_55 ) ) )
continue;
#ifdef F_35
F_36 ( L_1 , V_81 [ V_55 ] ) ;
if ( V_58 -> V_85 )
F_37 ( L_4 ) ;
else
F_37 ( L_5 ,
V_58 -> V_86 ? '(' : '[' , V_58 -> V_87 ,
V_58 -> V_88 , V_58 -> V_89 ? ')' : ']' ) ;
F_37 ( L_6 ) ;
#endif
V_69 = F_42 ( V_58 , F_43 ( V_62 , V_55 ) ) ;
#ifdef F_35
if ( V_58 -> V_85 )
F_37 ( L_7 ) ;
else
F_37 ( L_8 ,
V_58 -> V_86 ? '(' : '[' , V_58 -> V_87 ,
V_58 -> V_88 , V_58 -> V_89 ? ')' : ']' ) ;
#endif
if ( V_69 )
V_54 -> V_83 |= 1 << V_55 ;
if ( V_69 < 0 )
return V_69 ;
}
for ( V_55 = 0 ; V_55 < V_62 -> V_65 ; V_55 ++ )
V_64 [ V_55 ] = 0 ;
for ( V_55 = 0 ; V_55 <= V_67 ; V_55 ++ )
V_66 [ V_55 ] = ( V_54 -> V_72 & ( 1 << V_55 ) ) ? 1 : 0 ;
do {
V_70 = 0 ;
for ( V_55 = 0 ; V_55 < V_62 -> V_65 ; V_55 ++ ) {
struct V_90 * V_91 = & V_62 -> V_92 [ V_55 ] ;
unsigned int V_93 ;
int V_94 = 0 ;
if ( V_91 -> V_95 && ! ( V_91 -> V_95 & V_54 -> V_11 ) )
continue;
for ( V_93 = 0 ; V_91 -> V_96 [ V_93 ] >= 0 ; V_93 ++ ) {
if ( V_66 [ V_91 -> V_96 [ V_93 ] ] > V_64 [ V_55 ] ) {
V_94 = 1 ;
break;
}
}
if ( ! V_94 )
continue;
#ifdef F_35
F_36 ( L_9 , V_55 , V_91 -> V_97 ) ;
if ( V_91 -> V_98 >= 0 ) {
F_37 ( L_1 , V_81 [ V_91 -> V_98 ] ) ;
if ( F_44 ( V_91 -> V_98 ) ) {
V_60 = F_33 ( V_54 , V_91 -> V_98 ) ;
F_37 ( L_10 , * V_60 -> V_82 ) ;
} else {
V_58 = F_40 ( V_54 , V_91 -> V_98 ) ;
if ( V_58 -> V_85 )
F_37 ( L_4 ) ;
else
F_37 ( L_5 ,
V_58 -> V_86 ? '(' : '[' , V_58 -> V_87 ,
V_58 -> V_88 , V_58 -> V_89 ? ')' : ']' ) ;
}
}
#endif
V_69 = V_91 -> V_97 ( V_54 , V_91 ) ;
#ifdef F_35
if ( V_91 -> V_98 >= 0 ) {
F_37 ( L_6 ) ;
if ( F_44 ( V_91 -> V_98 ) )
F_37 ( L_10 , * V_60 -> V_82 ) ;
else {
if ( V_58 -> V_85 )
F_37 ( L_4 ) ;
else
F_37 ( L_5 ,
V_58 -> V_86 ? '(' : '[' , V_58 -> V_87 ,
V_58 -> V_88 , V_58 -> V_89 ? ')' : ']' ) ;
}
}
F_37 ( L_11 ) ;
#endif
V_64 [ V_55 ] = V_68 ;
if ( V_69 && V_91 -> V_98 >= 0 ) {
V_54 -> V_83 |= ( 1 << V_91 -> V_98 ) ;
V_66 [ V_91 -> V_98 ] = V_68 ;
V_70 = 1 ;
}
if ( V_69 < 0 )
return V_69 ;
V_68 ++ ;
}
} while ( V_70 );
if ( ! V_54 -> V_74 ) {
V_58 = F_40 ( V_54 , V_73 ) ;
if ( F_45 ( V_58 ) )
V_54 -> V_74 = F_46 ( V_58 ) ;
}
if ( ! V_54 -> V_77 ) {
V_58 = F_40 ( V_54 , V_75 ) ;
if ( F_45 ( V_58 ) ) {
V_54 -> V_76 = F_46 ( V_58 ) ;
V_54 -> V_77 = 1 ;
}
}
V_42 = & V_2 -> V_15 -> V_42 ;
if ( ! V_54 -> V_13 ) {
V_54 -> V_13 = V_42 -> V_13 & ~ ( V_99 |
V_100 ) ;
if ( ! F_30 ( V_2 ) )
V_54 -> V_13 &= ~ ( V_43 |
V_101 ) ;
}
if ( ! V_54 -> V_71 ) {
V_60 = F_33 ( V_54 , V_102 ) ;
V_58 = F_40 ( V_54 , V_103 ) ;
if ( F_47 ( V_60 ) == F_48 ( V_60 ) &&
F_49 ( V_58 ) == F_50 ( V_58 ) ) {
V_69 = V_2 -> V_34 -> V_35 ( V_2 ,
V_104 , V_54 ) ;
if ( V_69 < 0 )
return V_69 ;
}
}
V_54 -> V_72 = 0 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_53 T_2 * V_105 )
{
struct V_53 * V_54 ;
int V_38 ;
V_54 = F_52 ( V_105 , sizeof( * V_54 ) ) ;
if ( F_53 ( V_54 ) )
return F_54 ( V_54 ) ;
V_38 = F_32 ( V_2 , V_54 ) ;
if ( F_28 ( V_105 , V_54 , sizeof( * V_54 ) ) ) {
if ( ! V_38 )
V_38 = - V_41 ;
}
F_29 ( V_54 ) ;
return V_38 ;
}
static int F_55 ( struct V_14 * V_15 )
{
int V_106 ;
if ( ! V_15 -> V_107 )
return - 1 ;
V_106 = ( 750000 / V_15 -> V_107 ) * V_15 -> V_108 ;
V_106 += ( ( 750000 % V_15 -> V_107 ) * V_15 -> V_108 ) /
V_15 -> V_107 ;
return V_106 ;
}
static void F_56 ( struct V_1 * V_2 , int V_109 )
{
F_11 ( V_2 ) ;
if ( V_2 -> V_15 -> V_110 -> V_109 != V_111 )
V_2 -> V_15 -> V_110 -> V_109 = V_109 ;
F_13 ( V_2 ) ;
}
static int V_53 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
struct V_14 * V_15 ;
int V_38 , V_106 ;
unsigned int V_82 ;
T_3 V_112 ;
if ( F_57 ( V_2 ) )
return - V_113 ;
V_15 = V_2 -> V_15 ;
F_11 ( V_2 ) ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_114 :
case V_115 :
case V_116 :
break;
default:
F_13 ( V_2 ) ;
return - V_117 ;
}
F_13 ( V_2 ) ;
#if F_58 ( V_118 )
if ( ! V_2 -> V_119 . V_119 )
#endif
if ( F_59 ( & V_2 -> V_120 ) )
return - V_117 ;
V_54 -> V_72 = ~ 0U ;
V_38 = F_32 ( V_2 , V_54 ) ;
if ( V_38 < 0 )
goto V_121;
V_38 = F_60 ( V_2 , V_54 ) ;
if ( V_38 < 0 )
goto V_121;
if ( V_2 -> V_34 -> V_122 != NULL ) {
V_38 = V_2 -> V_34 -> V_122 ( V_2 , V_54 ) ;
if ( V_38 < 0 )
goto V_121;
}
V_15 -> V_123 = F_61 ( V_54 ) ;
V_15 -> V_124 = F_62 ( V_54 ) ;
V_15 -> V_125 = F_63 ( V_54 ) ;
V_15 -> V_126 = F_64 ( V_54 ) ;
V_15 -> V_107 = F_65 ( V_54 ) ;
V_15 -> V_108 = F_66 ( V_54 ) ;
V_15 -> V_127 = F_67 ( V_54 ) ;
V_15 -> V_128 = F_68 ( V_54 ) ;
V_15 -> V_13 = V_54 -> V_13 ;
V_15 -> V_76 = V_54 -> V_76 ;
V_15 -> V_77 = V_54 -> V_77 ;
V_15 -> V_129 =
( V_54 -> V_13 & V_130 ) &&
( V_54 -> V_11 & V_131 ) ;
V_82 = F_69 ( V_15 -> V_124 ) ;
V_15 -> V_132 = V_82 ;
V_82 *= V_15 -> V_126 ;
V_15 -> V_133 = V_82 ;
V_112 = 1 ;
while ( V_82 % 8 != 0 ) {
V_82 *= 2 ;
V_112 *= 2 ;
}
V_15 -> V_134 = V_82 / 8 ;
V_15 -> V_135 = V_112 ;
V_15 -> V_136 = V_137 ;
V_15 -> V_138 = 1 ;
V_15 -> V_139 -> V_140 = V_15 -> V_108 ;
V_15 -> V_141 = 1 ;
V_15 -> V_142 = V_15 -> V_128 ;
V_15 -> V_143 = 0 ;
V_15 -> V_144 = 0 ;
V_15 -> V_145 = V_15 -> V_128 ;
while ( V_15 -> V_145 * 2 <= V_146 - V_15 -> V_128 )
V_15 -> V_145 *= 2 ;
F_70 ( V_2 ) ;
F_56 ( V_2 , V_115 ) ;
if ( F_71 ( & V_2 -> V_147 ) )
F_72 ( & V_2 -> V_147 ) ;
if ( ( V_106 = F_55 ( V_15 ) ) >= 0 )
F_73 ( & V_2 -> V_147 ,
V_148 , V_106 ) ;
return 0 ;
V_121:
F_56 ( V_2 , V_114 ) ;
if ( V_2 -> V_34 -> V_149 != NULL )
V_2 -> V_34 -> V_149 ( V_2 ) ;
return V_38 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_53 T_2 * V_105 )
{
struct V_53 * V_54 ;
int V_38 ;
V_54 = F_52 ( V_105 , sizeof( * V_54 ) ) ;
if ( F_53 ( V_54 ) )
return F_54 ( V_54 ) ;
V_38 = V_53 ( V_2 , V_54 ) ;
if ( F_28 ( V_105 , V_54 , sizeof( * V_54 ) ) ) {
if ( ! V_38 )
V_38 = - V_41 ;
}
F_29 ( V_54 ) ;
return V_38 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
int V_150 = 0 ;
if ( F_57 ( V_2 ) )
return - V_113 ;
V_15 = V_2 -> V_15 ;
F_11 ( V_2 ) ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_115 :
case V_116 :
break;
default:
F_13 ( V_2 ) ;
return - V_117 ;
}
F_13 ( V_2 ) ;
if ( F_59 ( & V_2 -> V_120 ) )
return - V_117 ;
if ( V_2 -> V_34 -> V_149 )
V_150 = V_2 -> V_34 -> V_149 ( V_2 ) ;
F_56 ( V_2 , V_114 ) ;
F_72 ( & V_2 -> V_147 ) ;
return V_150 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct F_76 * V_54 )
{
struct V_14 * V_15 ;
int V_38 ;
if ( F_57 ( V_2 ) )
return - V_113 ;
V_15 = V_2 -> V_15 ;
F_11 ( V_2 ) ;
if ( V_15 -> V_110 -> V_109 == V_114 ) {
F_13 ( V_2 ) ;
return - V_117 ;
}
F_13 ( V_2 ) ;
if ( V_54 -> V_136 > V_151 )
return - V_80 ;
if ( V_54 -> V_152 >= F_77 ( 2 , 0 , 12 ) &&
V_54 -> V_153 > V_154 )
return - V_80 ;
if ( V_54 -> V_140 == 0 )
return - V_80 ;
if ( V_54 -> V_144 >= V_15 -> V_145 ) {
if ( V_54 -> V_143 != 0 )
return - V_80 ;
} else {
if ( V_54 -> V_144 > V_54 -> V_143 )
return - V_80 ;
if ( V_54 -> V_143 > V_15 -> V_128 )
return - V_80 ;
}
V_38 = 0 ;
F_11 ( V_2 ) ;
V_15 -> V_136 = V_54 -> V_136 ;
if ( V_54 -> V_152 >= F_77 ( 2 , 0 , 12 ) )
V_15 -> V_153 = V_54 -> V_153 ;
V_15 -> V_138 = V_54 -> V_138 ;
V_15 -> V_139 -> V_140 = V_54 -> V_140 ;
V_15 -> V_141 = V_54 -> V_141 ;
V_15 -> V_142 = V_54 -> V_142 ;
V_15 -> V_143 = V_54 -> V_143 ;
V_15 -> V_144 = V_54 -> V_144 ;
V_54 -> V_145 = V_15 -> V_145 ;
if ( F_78 ( V_2 ) ) {
if ( V_2 -> V_22 == V_155 &&
V_15 -> V_144 > 0 )
F_79 ( V_2 , V_156 ) ;
V_38 = F_80 ( V_2 , V_15 ) ;
}
F_13 ( V_2 ) ;
return V_38 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct F_76 T_2 * V_105 )
{
struct F_76 V_54 ;
int V_38 ;
if ( F_82 ( & V_54 , V_105 , sizeof( V_54 ) ) )
return - V_41 ;
V_38 = F_76 ( V_2 , & V_54 ) ;
if ( F_28 ( V_105 , & V_54 , sizeof( V_54 ) ) )
return - V_41 ;
return V_38 ;
}
int F_83 ( struct V_1 * V_2 ,
struct F_83 * V_110 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
F_11 ( V_2 ) ;
F_84 ( V_110 -> V_157 ,
& V_15 -> V_158 ) ;
if ( V_15 -> V_158 . V_159 ==
V_160 ) {
if ( V_15 -> V_42 . V_13 & V_161 )
V_15 -> V_158 . V_159 =
V_162 ;
else
V_15 -> V_158 . V_159 =
V_163 ;
V_15 -> V_164 . V_165 = 0 ;
} else
V_15 -> V_164 . V_165 = 1 ;
V_110 -> V_109 = V_15 -> V_110 -> V_109 ;
V_110 -> V_166 = V_15 -> V_110 -> V_166 ;
if ( V_110 -> V_109 == V_114 )
goto V_167;
V_110 -> V_168 = V_15 -> V_168 ;
if ( F_78 ( V_2 ) ) {
F_85 ( V_2 ) ;
if ( V_15 -> V_136 == V_169 ) {
V_110 -> V_170 = V_15 -> V_110 -> V_170 ;
V_110 -> V_171 = V_15 -> V_171 ;
V_110 -> V_172 =
V_15 -> V_110 -> V_172 ;
if ( V_15 -> V_164 . V_165 == 1 )
F_86 ( & V_110 -> V_157 ,
& V_110 -> V_173 ,
& V_15 -> V_164 ) ;
goto V_174;
}
} else {
if ( V_15 -> V_136 == V_169 )
F_87 ( V_15 , & V_110 -> V_170 ) ;
}
V_174:
V_110 -> V_175 = V_15 -> V_139 -> V_175 ;
V_110 -> V_176 = V_15 -> V_110 -> V_176 ;
if ( V_2 -> V_22 == V_155 ) {
V_110 -> V_177 = F_88 ( V_15 ) ;
if ( V_15 -> V_110 -> V_109 == V_178 ||
V_15 -> V_110 -> V_109 == V_179 ) {
V_110 -> V_180 = V_15 -> V_128 - V_110 -> V_177 ;
V_110 -> V_180 += V_15 -> V_180 ;
} else
V_110 -> V_180 = 0 ;
} else {
V_110 -> V_177 = F_89 ( V_15 ) ;
if ( V_15 -> V_110 -> V_109 == V_178 )
V_110 -> V_180 = V_110 -> V_177 + V_15 -> V_180 ;
else
V_110 -> V_180 = 0 ;
}
V_110 -> V_181 = V_15 -> V_181 ;
V_110 -> V_182 = V_15 -> V_182 ;
V_15 -> V_181 = 0 ;
V_15 -> V_182 = 0 ;
V_167:
F_13 ( V_2 ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct F_83 T_2 * V_183 ,
bool V_184 )
{
struct F_83 V_110 ;
int V_185 ;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
if ( V_184 && F_91 ( V_110 . V_157 ,
( V_186 T_2 * ) ( & V_183 -> V_157 ) ) )
return - V_41 ;
V_185 = F_83 ( V_2 , & V_110 ) ;
if ( V_185 < 0 )
return V_185 ;
if ( F_28 ( V_183 , & V_110 , sizeof( V_110 ) ) )
return - V_41 ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct F_92 * V_13 )
{
struct V_14 * V_15 ;
unsigned int V_187 ;
V_187 = V_13 -> V_187 ;
V_15 = V_2 -> V_15 ;
F_11 ( V_2 ) ;
if ( V_15 -> V_110 -> V_109 == V_114 ) {
F_13 ( V_2 ) ;
return - V_117 ;
}
F_13 ( V_2 ) ;
if ( V_187 >= V_15 -> V_126 )
return - V_80 ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_187 = V_187 ;
return V_2 -> V_34 -> V_35 ( V_2 , V_188 , V_13 ) ;
}
static int F_93 ( struct V_1 * V_2 ,
struct F_92 T_2 * V_37 )
{
struct F_92 V_13 ;
int V_185 ;
if ( F_82 ( & V_13 , V_37 , sizeof( V_13 ) ) )
return - V_41 ;
V_185 = F_92 ( V_2 , & V_13 ) ;
if ( V_185 < 0 )
return V_185 ;
if ( F_28 ( V_37 , & V_13 , sizeof( V_13 ) ) )
return - V_41 ;
return 0 ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_15 -> V_189 == NULL )
return;
if ( V_15 -> V_189 == V_2 ) {
if ( ! V_15 -> V_190 )
F_87 ( V_15 , & V_15 -> V_168 ) ;
} else {
F_94 ( V_15 -> V_189 ) ;
V_15 -> V_168 = V_15 -> V_189 -> V_15 -> V_168 ;
}
V_15 -> V_189 = NULL ;
}
static int F_95 ( struct V_191 * V_34 ,
struct V_1 * V_2 ,
int V_109 , int V_192 )
{
struct V_1 * V_193 = NULL ;
struct V_1 * V_194 ;
int V_185 = 0 , V_195 = 1 ;
F_96 (s, substream) {
if ( V_192 && V_193 != V_2 ) {
if ( V_193 -> V_3 -> V_4 )
F_97 ( & V_193 -> V_7 . V_8 , V_195 ) ;
else
F_98 ( & V_193 -> V_7 . V_10 , V_195 ) ;
V_195 ++ ;
}
V_185 = V_34 -> V_196 ( V_193 , V_109 ) ;
if ( V_185 < 0 )
goto V_197;
}
F_96 (s, substream) {
V_185 = V_34 -> V_198 ( V_193 , V_109 ) ;
if ( V_185 < 0 ) {
if ( V_34 -> V_199 ) {
F_96 (s1, substream) {
if ( V_194 == V_193 )
break;
V_34 -> V_199 ( V_194 , V_109 ) ;
}
}
V_193 = NULL ;
goto V_197;
}
}
F_96 (s, substream) {
V_34 -> V_200 ( V_193 , V_109 ) ;
}
V_197:
if ( V_192 ) {
F_96 (s1, substream) {
if ( V_194 != V_2 ) {
if ( V_194 -> V_3 -> V_4 )
F_7 ( & V_194 -> V_7 . V_8 ) ;
else
F_9 ( & V_194 -> V_7 . V_10 ) ;
}
if ( V_194 == V_193 )
break;
}
}
return V_185 ;
}
static int F_99 ( struct V_191 * V_34 ,
struct V_1 * V_2 ,
int V_109 )
{
int V_185 ;
V_185 = V_34 -> V_196 ( V_2 , V_109 ) ;
if ( V_185 < 0 )
return V_185 ;
V_185 = V_34 -> V_198 ( V_2 , V_109 ) ;
if ( V_185 == 0 )
V_34 -> V_200 ( V_2 , V_109 ) ;
else if ( V_34 -> V_199 )
V_34 -> V_199 ( V_2 , V_109 ) ;
return V_185 ;
}
static int F_100 ( struct V_191 * V_34 ,
struct V_1 * V_2 ,
int V_109 )
{
int V_185 ;
if ( ! F_101 ( V_2 ) )
return F_99 ( V_34 , V_2 , V_109 ) ;
if ( V_2 -> V_3 -> V_4 ) {
if ( ! F_102 ( & V_2 -> V_201 -> V_8 ) ) {
F_7 ( & V_2 -> V_7 . V_8 ) ;
F_3 ( & V_2 -> V_201 -> V_8 ) ;
F_3 ( & V_2 -> V_7 . V_8 ) ;
}
V_185 = F_95 ( V_34 , V_2 , V_109 , 1 ) ;
F_7 ( & V_2 -> V_201 -> V_8 ) ;
} else {
if ( ! F_103 ( & V_2 -> V_201 -> V_10 ) ) {
F_9 ( & V_2 -> V_7 . V_10 ) ;
F_5 ( & V_2 -> V_201 -> V_10 ) ;
F_5 ( & V_2 -> V_7 . V_10 ) ;
}
V_185 = F_95 ( V_34 , V_2 , V_109 , 1 ) ;
F_9 ( & V_2 -> V_201 -> V_10 ) ;
}
return V_185 ;
}
static int F_104 ( struct V_191 * V_34 ,
struct V_1 * V_2 ,
int V_109 )
{
int V_185 ;
F_11 ( V_2 ) ;
V_185 = F_100 ( V_34 , V_2 , V_109 ) ;
F_13 ( V_2 ) ;
return V_185 ;
}
static int F_105 ( struct V_191 * V_34 ,
struct V_1 * V_2 ,
int V_109 )
{
int V_185 ;
F_106 ( & V_5 ) ;
if ( F_101 ( V_2 ) )
V_185 = F_95 ( V_34 , V_2 , V_109 , 0 ) ;
else
V_185 = F_99 ( V_34 , V_2 , V_109 ) ;
F_8 ( & V_5 ) ;
return V_185 ;
}
static int F_107 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_15 -> V_110 -> V_109 != V_116 )
return - V_117 ;
if ( V_2 -> V_22 == V_155 &&
! F_108 ( V_2 ) )
return - V_202 ;
V_15 -> V_190 = false ;
V_15 -> V_189 = V_2 ;
return 0 ;
}
static int F_109 ( struct V_1 * V_2 , int V_109 )
{
if ( V_2 -> V_15 -> V_189 != V_2 )
return 0 ;
return V_2 -> V_34 -> V_203 ( V_2 , V_204 ) ;
}
static void F_110 ( struct V_1 * V_2 , int V_109 )
{
if ( V_2 -> V_15 -> V_189 == V_2 )
V_2 -> V_34 -> V_203 ( V_2 , V_205 ) ;
}
static void F_111 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
F_94 ( V_2 ) ;
V_15 -> V_206 = V_207 ;
V_15 -> V_208 = ( V_15 -> V_128 * V_209 ) /
V_15 -> V_107 ;
V_15 -> V_110 -> V_109 = V_109 ;
if ( V_2 -> V_22 == V_155 &&
V_15 -> V_144 > 0 )
F_79 ( V_2 , V_156 ) ;
if ( V_2 -> V_210 )
F_112 ( V_2 -> V_210 , V_211 ,
& V_15 -> V_168 ) ;
}
int F_113 ( struct V_1 * V_2 )
{
return F_100 ( & V_212 , V_2 ,
V_178 ) ;
}
static int F_114 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_15 -> V_110 -> V_109 == V_114 )
return - V_117 ;
V_15 -> V_189 = V_2 ;
return 0 ;
}
static int F_115 ( struct V_1 * V_2 , int V_109 )
{
if ( V_2 -> V_15 -> V_189 == V_2 &&
F_78 ( V_2 ) )
V_2 -> V_34 -> V_203 ( V_2 , V_205 ) ;
return 0 ;
}
static void F_116 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_15 -> V_110 -> V_109 != V_109 ) {
F_94 ( V_2 ) ;
V_15 -> V_110 -> V_109 = V_109 ;
if ( V_2 -> V_210 )
F_112 ( V_2 -> V_210 , V_213 ,
& V_15 -> V_168 ) ;
}
F_117 ( & V_15 -> V_214 ) ;
F_117 ( & V_15 -> V_215 ) ;
}
int F_118 ( struct V_1 * V_2 , T_4 V_109 )
{
return F_100 ( & V_216 , V_2 , V_109 ) ;
}
int F_119 ( struct V_1 * V_2 )
{
return F_99 ( & V_216 , V_2 ,
V_115 ) ;
}
int F_120 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
int V_217 = 0 ;
F_121 ( V_2 , V_11 ) ;
if ( F_78 ( V_2 ) )
V_217 = F_118 ( V_2 , V_218 ) ;
F_17 ( V_2 , V_11 ) ;
return V_217 ;
}
static int F_122 ( struct V_1 * V_2 , int V_219 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( ! ( V_15 -> V_13 & V_220 ) )
return - V_221 ;
if ( V_219 ) {
if ( V_15 -> V_110 -> V_109 != V_178 )
return - V_117 ;
} else if ( V_15 -> V_110 -> V_109 != V_222 )
return - V_117 ;
V_15 -> V_189 = V_2 ;
return 0 ;
}
static int F_123 ( struct V_1 * V_2 , int V_219 )
{
if ( V_2 -> V_15 -> V_189 != V_2 )
return 0 ;
if ( V_219 )
F_85 ( V_2 ) ;
V_2 -> V_15 -> V_206 = V_207 - V_209 * 1000 ;
return V_2 -> V_34 -> V_203 ( V_2 ,
V_219 ? V_223 :
V_224 ) ;
}
static void F_124 ( struct V_1 * V_2 , int V_219 )
{
if ( V_2 -> V_15 -> V_189 == V_2 )
V_2 -> V_34 -> V_203 ( V_2 ,
V_219 ? V_224 :
V_223 ) ;
}
static void F_125 ( struct V_1 * V_2 , int V_219 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
F_94 ( V_2 ) ;
if ( V_219 ) {
V_15 -> V_110 -> V_109 = V_222 ;
if ( V_2 -> V_210 )
F_112 ( V_2 -> V_210 ,
V_225 ,
& V_15 -> V_168 ) ;
F_117 ( & V_15 -> V_214 ) ;
F_117 ( & V_15 -> V_215 ) ;
} else {
V_15 -> V_110 -> V_109 = V_178 ;
if ( V_2 -> V_210 )
F_112 ( V_2 -> V_210 ,
V_226 ,
& V_15 -> V_168 ) ;
}
}
static int F_126 ( struct V_1 * V_2 , int V_219 )
{
return F_100 ( & V_227 , V_2 , V_219 ) ;
}
static int F_127 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_15 -> V_110 -> V_109 == V_228 )
return - V_229 ;
V_15 -> V_189 = V_2 ;
return 0 ;
}
static int F_128 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_15 -> V_189 != V_2 )
return 0 ;
if ( ! F_78 ( V_2 ) )
return 0 ;
V_2 -> V_34 -> V_203 ( V_2 , V_230 ) ;
return 0 ;
}
static void F_129 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
F_94 ( V_2 ) ;
V_15 -> V_110 -> V_166 = V_15 -> V_110 -> V_109 ;
V_15 -> V_110 -> V_109 = V_228 ;
if ( V_2 -> V_210 )
F_112 ( V_2 -> V_210 , V_231 ,
& V_15 -> V_168 ) ;
F_117 ( & V_15 -> V_214 ) ;
F_117 ( & V_15 -> V_215 ) ;
}
int F_130 ( struct V_1 * V_2 )
{
int V_38 ;
unsigned long V_11 ;
if ( ! V_2 )
return 0 ;
F_121 ( V_2 , V_11 ) ;
V_38 = F_100 ( & V_232 , V_2 , 0 ) ;
F_17 ( V_2 , V_11 ) ;
return V_38 ;
}
int F_131 ( struct V_16 * V_3 )
{
struct V_1 * V_2 ;
int V_22 , V_38 = 0 ;
if ( ! V_3 )
return 0 ;
for ( V_22 = 0 ; V_22 < 2 ; V_22 ++ ) {
for ( V_2 = V_3 -> V_233 [ V_22 ] . V_2 ;
V_2 ; V_2 = V_2 -> V_234 ) {
if ( V_2 -> V_15 == NULL )
continue;
V_38 = F_130 ( V_2 ) ;
if ( V_38 < 0 && V_38 != - V_229 )
return V_38 ;
}
}
return 0 ;
}
static int F_132 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( ! ( V_15 -> V_13 & V_235 ) )
return - V_221 ;
V_15 -> V_189 = V_2 ;
return 0 ;
}
static int F_133 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_15 -> V_189 != V_2 )
return 0 ;
if ( V_15 -> V_110 -> V_166 != V_178 &&
( V_15 -> V_110 -> V_166 != V_179 ||
V_2 -> V_22 != V_155 ) )
return 0 ;
return V_2 -> V_34 -> V_203 ( V_2 , V_236 ) ;
}
static void F_134 ( struct V_1 * V_2 , int V_109 )
{
if ( V_2 -> V_15 -> V_189 == V_2 &&
F_78 ( V_2 ) )
V_2 -> V_34 -> V_203 ( V_2 , V_230 ) ;
}
static void F_135 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
F_94 ( V_2 ) ;
V_15 -> V_110 -> V_109 = V_15 -> V_110 -> V_166 ;
if ( V_2 -> V_210 )
F_112 ( V_2 -> V_210 , V_237 ,
& V_15 -> V_168 ) ;
}
static int F_136 ( struct V_1 * V_2 )
{
struct V_238 * V_19 = V_2 -> V_3 -> V_19 ;
int V_185 ;
F_137 ( V_19 ) ;
if ( ( V_185 = F_138 ( V_19 , V_239 ) ) >= 0 )
V_185 = F_104 ( & V_240 , V_2 , 0 ) ;
F_139 ( V_19 ) ;
return V_185 ;
}
static int F_136 ( struct V_1 * V_2 )
{
return - V_221 ;
}
static int F_140 ( struct V_1 * V_2 )
{
struct V_238 * V_19 = V_2 -> V_3 -> V_19 ;
struct V_14 * V_15 = V_2 -> V_15 ;
int V_150 ;
F_137 ( V_19 ) ;
if ( V_15 -> V_110 -> V_109 == V_228 ) {
V_150 = F_138 ( V_19 , V_239 ) ;
if ( V_150 < 0 )
goto V_197;
}
F_11 ( V_2 ) ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_218 :
V_150 = 0 ;
break;
case V_178 :
V_150 = F_118 ( V_2 , V_218 ) ;
break;
default:
V_150 = - V_117 ;
}
F_13 ( V_2 ) ;
V_197:
F_139 ( V_19 ) ;
return V_150 ;
}
static int F_141 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_178 :
case V_116 :
case V_222 :
case V_228 :
return 0 ;
default:
return - V_117 ;
}
}
static int F_142 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
int V_38 = V_2 -> V_34 -> V_35 ( V_2 , V_241 , NULL ) ;
if ( V_38 < 0 )
return V_38 ;
V_15 -> V_242 = 0 ;
V_15 -> V_243 = V_15 -> V_110 -> V_176 -
V_15 -> V_110 -> V_176 % V_15 -> V_108 ;
V_15 -> V_244 = V_15 -> V_110 -> V_176 ;
V_15 -> V_245 = 0 ;
return 0 ;
}
static void F_143 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
V_15 -> V_139 -> V_175 = V_15 -> V_110 -> V_176 ;
if ( V_2 -> V_22 == V_155 &&
V_15 -> V_144 > 0 )
F_79 ( V_2 , V_156 ) ;
}
static int F_144 ( struct V_1 * V_2 )
{
return F_105 ( & V_246 , V_2 , 0 ) ;
}
static int F_145 ( struct V_1 * V_2 ,
int V_247 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_15 -> V_110 -> V_109 == V_114 ||
V_15 -> V_110 -> V_109 == V_111 )
return - V_117 ;
if ( F_78 ( V_2 ) )
return - V_229 ;
V_2 -> V_247 = V_247 ;
return 0 ;
}
static int F_146 ( struct V_1 * V_2 , int V_109 )
{
int V_38 ;
V_38 = V_2 -> V_34 -> V_248 ( V_2 ) ;
if ( V_38 < 0 )
return V_38 ;
return F_142 ( V_2 , 0 ) ;
}
static void F_147 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
V_15 -> V_139 -> V_175 = V_15 -> V_110 -> V_176 ;
F_56 ( V_2 , V_116 ) ;
}
static int F_148 ( struct V_1 * V_2 ,
struct V_249 * V_249 )
{
int V_185 ;
struct V_238 * V_19 = V_2 -> V_3 -> V_19 ;
int V_247 ;
if ( V_249 )
V_247 = V_249 -> V_247 ;
else
V_247 = V_2 -> V_247 ;
F_137 ( V_19 ) ;
if ( ( V_185 = F_138 ( V_19 , V_239 ) ) >= 0 )
V_185 = F_105 ( & V_250 ,
V_2 , V_247 ) ;
F_139 ( V_19 ) ;
return V_185 ;
}
static int F_149 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_114 :
case V_111 :
case V_228 :
return - V_117 ;
}
V_15 -> V_189 = V_2 ;
return 0 ;
}
static int F_150 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_22 == V_155 ) {
switch ( V_15 -> V_110 -> V_109 ) {
case V_116 :
if ( ! F_151 ( V_2 ) ) {
F_109 ( V_2 , V_179 ) ;
F_111 ( V_2 , V_179 ) ;
} else {
V_15 -> V_110 -> V_109 = V_115 ;
}
break;
case V_178 :
V_15 -> V_110 -> V_109 = V_179 ;
break;
case V_218 :
V_15 -> V_110 -> V_109 = V_115 ;
break;
default:
break;
}
} else {
if ( V_15 -> V_110 -> V_109 == V_178 ) {
int V_251 = F_89 ( V_15 ) > 0 ?
V_179 : V_115 ;
F_115 ( V_2 , V_251 ) ;
F_116 ( V_2 , V_251 ) ;
}
}
if ( V_15 -> V_110 -> V_109 == V_179 &&
V_15 -> V_189 == V_2 &&
( V_15 -> V_42 . V_13 & V_100 ) )
return V_2 -> V_34 -> V_203 ( V_2 ,
V_252 ) ;
return 0 ;
}
static void F_152 ( struct V_1 * V_2 , int V_109 )
{
}
static int F_153 ( struct V_1 * V_2 ,
struct V_249 * V_249 )
{
struct V_238 * V_19 ;
struct V_14 * V_15 ;
struct V_1 * V_193 ;
T_5 V_253 ;
int V_150 = 0 ;
int V_254 = 0 ;
V_19 = V_2 -> V_3 -> V_19 ;
V_15 = V_2 -> V_15 ;
if ( V_15 -> V_110 -> V_109 == V_114 )
return - V_117 ;
F_137 ( V_19 ) ;
if ( V_15 -> V_110 -> V_109 == V_228 ) {
V_150 = F_138 ( V_19 , V_239 ) ;
if ( V_150 < 0 ) {
F_139 ( V_19 ) ;
return V_150 ;
}
}
if ( V_249 ) {
if ( V_249 -> V_247 & V_255 )
V_254 = 1 ;
} else if ( V_2 -> V_247 & V_255 )
V_254 = 1 ;
F_106 ( & V_5 ) ;
F_11 ( V_2 ) ;
if ( V_15 -> V_110 -> V_109 == V_222 )
F_126 ( V_2 , 0 ) ;
V_150 = F_100 ( & V_256 , V_2 , 0 ) ;
if ( V_150 < 0 )
goto V_257;
if ( V_254 ) {
V_150 = - V_258 ;
goto V_257;
}
for (; ; ) {
long V_259 ;
struct V_14 * V_260 ;
if ( F_154 ( V_261 ) ) {
V_150 = - V_262 ;
break;
}
V_260 = NULL ;
F_96 (s, substream) {
if ( V_193 -> V_22 != V_155 )
continue;
V_15 = V_193 -> V_15 ;
if ( V_15 -> V_110 -> V_109 == V_179 ) {
V_260 = V_15 ;
break;
}
}
if ( ! V_260 )
break;
F_155 ( & V_253 , V_261 ) ;
F_156 ( & V_260 -> V_214 , & V_253 ) ;
F_13 ( V_2 ) ;
F_8 ( & V_5 ) ;
F_139 ( V_19 ) ;
if ( V_15 -> V_129 )
V_259 = V_263 ;
else {
V_259 = 10 ;
if ( V_15 -> V_107 ) {
long V_264 = V_15 -> V_108 * 2 / V_15 -> V_107 ;
V_259 = V_88 ( V_264 , V_259 ) ;
}
V_259 = F_157 ( V_259 * 1000 ) ;
}
V_259 = F_158 ( V_259 ) ;
F_137 ( V_19 ) ;
F_106 ( & V_5 ) ;
F_11 ( V_2 ) ;
F_159 ( & V_260 -> V_214 , & V_253 ) ;
if ( V_19 -> V_265 ) {
V_150 = - V_266 ;
break;
}
if ( V_259 == 0 ) {
if ( V_2 -> V_15 -> V_110 -> V_109 == V_228 )
V_150 = - V_267 ;
else {
F_160 ( V_2 -> V_3 -> V_19 -> V_51 ,
L_12 ) ;
F_118 ( V_2 , V_115 ) ;
V_150 = - V_268 ;
}
break;
}
}
V_257:
F_13 ( V_2 ) ;
F_8 ( & V_5 ) ;
F_139 ( V_19 ) ;
return V_150 ;
}
static int F_161 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
int V_150 = 0 ;
if ( F_57 ( V_2 ) )
return - V_113 ;
V_15 = V_2 -> V_15 ;
if ( V_15 -> V_110 -> V_109 == V_114 ||
V_15 -> V_110 -> V_109 == V_111 ||
V_15 -> V_110 -> V_109 == V_228 )
return - V_117 ;
F_11 ( V_2 ) ;
if ( V_15 -> V_110 -> V_109 == V_222 )
F_126 ( V_2 , 0 ) ;
F_118 ( V_2 , V_115 ) ;
F_13 ( V_2 ) ;
return V_150 ;
}
static bool F_162 ( struct V_249 * V_249 )
{
struct V_269 * V_269 = F_163 ( V_249 ) ;
unsigned int V_270 ;
if ( ! F_164 ( V_269 -> V_271 ) || F_165 ( V_269 ) != V_272 )
return false ;
V_270 = F_166 ( V_269 ) ;
return F_167 ( V_270 , V_273 ) ||
F_167 ( V_270 , V_274 ) ;
}
static int F_168 ( struct V_1 * V_2 , int V_275 )
{
int V_185 = 0 ;
struct V_276 * V_277 ;
struct V_1 * V_278 ;
struct V_279 * V_201 ;
struct V_275 V_280 = F_169 ( V_275 ) ;
if ( ! V_280 . V_249 )
return - V_117 ;
if ( ! F_162 ( V_280 . V_249 ) ) {
V_185 = - V_117 ;
goto V_281;
}
V_277 = V_280 . V_249 -> V_282 ;
V_278 = V_277 -> V_2 ;
V_201 = F_27 ( sizeof( * V_201 ) , V_39 ) ;
if ( ! V_201 ) {
V_185 = - V_40 ;
goto V_283;
}
F_170 ( & V_5 ) ;
F_171 ( & V_9 ) ;
if ( V_2 -> V_15 -> V_110 -> V_109 == V_114 ||
V_2 -> V_15 -> V_110 -> V_109 != V_278 -> V_15 -> V_110 -> V_109 ||
V_2 -> V_3 -> V_4 != V_278 -> V_3 -> V_4 ) {
V_185 = - V_117 ;
goto V_167;
}
if ( F_101 ( V_278 ) ) {
V_185 = - V_284 ;
goto V_167;
}
if ( ! F_101 ( V_2 ) ) {
V_2 -> V_201 = V_201 ;
V_201 = NULL ;
F_172 ( & V_2 -> V_201 -> V_10 ) ;
F_173 ( & V_2 -> V_201 -> V_8 ) ;
F_174 ( & V_2 -> V_201 -> V_285 ) ;
F_175 ( & V_2 -> V_286 , & V_2 -> V_201 -> V_285 ) ;
V_2 -> V_201 -> V_287 = 1 ;
}
F_175 ( & V_278 -> V_286 , & V_2 -> V_201 -> V_285 ) ;
V_2 -> V_201 -> V_287 ++ ;
V_278 -> V_201 = V_2 -> V_201 ;
V_167:
F_176 ( & V_9 ) ;
F_177 ( & V_5 ) ;
V_283:
F_178 ( V_278 -> V_3 -> V_19 ) ;
F_29 ( V_201 ) ;
V_281:
F_179 ( V_280 ) ;
return V_185 ;
}
static void F_180 ( struct V_1 * V_2 )
{
V_2 -> V_201 = & V_2 -> V_7 ;
F_174 ( & V_2 -> V_7 . V_285 ) ;
F_175 ( & V_2 -> V_286 , & V_2 -> V_7 . V_285 ) ;
}
static int F_181 ( struct V_1 * V_2 )
{
struct V_1 * V_193 ;
int V_185 = 0 ;
F_170 ( & V_5 ) ;
F_171 ( & V_9 ) ;
if ( ! F_101 ( V_2 ) ) {
V_185 = - V_284 ;
goto V_167;
}
F_182 ( & V_2 -> V_286 ) ;
V_2 -> V_201 -> V_287 -- ;
if ( V_2 -> V_201 -> V_287 == 1 ) {
F_96 (s, substream) {
F_180 ( V_193 ) ;
break;
}
F_29 ( V_2 -> V_201 ) ;
}
F_180 ( V_2 ) ;
V_167:
F_176 ( & V_9 ) ;
F_177 ( & V_5 ) ;
return V_185 ;
}
static int F_183 ( struct V_53 * V_54 ,
struct V_90 * V_288 )
{
struct V_57 V_264 ;
F_184 ( F_185 ( V_54 , V_288 -> V_96 [ 0 ] ) ,
F_185 ( V_54 , V_288 -> V_96 [ 1 ] ) , & V_264 ) ;
return F_42 ( F_40 ( V_54 , V_288 -> V_98 ) , & V_264 ) ;
}
static int F_186 ( struct V_53 * V_54 ,
struct V_90 * V_288 )
{
struct V_57 V_264 ;
F_187 ( F_185 ( V_54 , V_288 -> V_96 [ 0 ] ) ,
F_185 ( V_54 , V_288 -> V_96 [ 1 ] ) , & V_264 ) ;
return F_42 ( F_40 ( V_54 , V_288 -> V_98 ) , & V_264 ) ;
}
static int F_188 ( struct V_53 * V_54 ,
struct V_90 * V_288 )
{
struct V_57 V_264 ;
F_189 ( F_185 ( V_54 , V_288 -> V_96 [ 0 ] ) ,
F_185 ( V_54 , V_288 -> V_96 [ 1 ] ) ,
( unsigned long ) V_288 -> V_289 , & V_264 ) ;
return F_42 ( F_40 ( V_54 , V_288 -> V_98 ) , & V_264 ) ;
}
static int F_190 ( struct V_53 * V_54 ,
struct V_90 * V_288 )
{
struct V_57 V_264 ;
F_191 ( F_185 ( V_54 , V_288 -> V_96 [ 0 ] ) ,
( unsigned long ) V_288 -> V_289 ,
F_185 ( V_54 , V_288 -> V_96 [ 1 ] ) , & V_264 ) ;
return F_42 ( F_40 ( V_54 , V_288 -> V_98 ) , & V_264 ) ;
}
static int F_192 ( struct V_53 * V_54 ,
struct V_90 * V_288 )
{
unsigned int V_55 ;
struct V_57 * V_58 = F_40 ( V_54 , V_288 -> V_96 [ 0 ] ) ;
struct V_59 V_60 ;
struct V_59 * V_290 = F_33 ( V_54 , V_102 ) ;
F_193 ( & V_60 ) ;
for ( V_55 = 0 ; V_55 <= V_291 ; ++ V_55 ) {
int V_82 ;
if ( ! F_194 ( V_290 , V_55 ) )
continue;
V_82 = F_69 ( V_55 ) ;
if ( V_82 <= 0 )
continue;
if ( ( unsigned ) V_82 < V_58 -> V_87 || ( unsigned ) V_82 > V_58 -> V_88 )
F_195 ( & V_60 , V_55 ) ;
}
return F_38 ( V_290 , & V_60 ) ;
}
static int F_196 ( struct V_53 * V_54 ,
struct V_90 * V_288 )
{
struct V_57 V_264 ;
unsigned int V_55 ;
V_264 . V_87 = V_292 ;
V_264 . V_88 = 0 ;
V_264 . V_86 = 0 ;
V_264 . V_89 = 0 ;
for ( V_55 = 0 ; V_55 <= V_291 ; ++ V_55 ) {
int V_82 ;
if ( ! F_194 ( F_33 ( V_54 , V_102 ) , V_55 ) )
continue;
V_82 = F_69 ( V_55 ) ;
if ( V_82 <= 0 )
continue;
if ( V_264 . V_87 > ( unsigned ) V_82 )
V_264 . V_87 = V_82 ;
if ( V_264 . V_88 < ( unsigned ) V_82 )
V_264 . V_88 = V_82 ;
}
V_264 . integer = 1 ;
return F_42 ( F_40 ( V_54 , V_288 -> V_98 ) , & V_264 ) ;
}
static int F_197 ( struct V_53 * V_54 ,
struct V_90 * V_288 )
{
struct V_56 * V_42 = V_288 -> V_289 ;
return F_198 ( F_40 ( V_54 , V_288 -> V_98 ) ,
V_293 . V_287 ,
V_293 . V_294 , V_42 -> V_295 ) ;
}
static int F_199 ( struct V_53 * V_54 ,
struct V_90 * V_288 )
{
struct V_57 V_264 ;
struct V_1 * V_2 = V_288 -> V_289 ;
V_264 . V_87 = 0 ;
V_264 . V_88 = V_2 -> V_296 ;
V_264 . V_86 = 0 ;
V_264 . V_89 = 0 ;
V_264 . integer = 1 ;
return F_42 ( F_40 ( V_54 , V_288 -> V_98 ) , & V_264 ) ;
}
int F_200 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_61 * V_62 = & V_15 -> V_63 ;
int V_55 , V_38 ;
for ( V_55 = V_78 ; V_55 <= V_79 ; V_55 ++ ) {
F_193 ( F_39 ( V_62 , V_55 ) ) ;
}
for ( V_55 = V_84 ; V_55 <= V_67 ; V_55 ++ ) {
F_201 ( F_43 ( V_62 , V_55 ) ) ;
}
F_202 ( F_43 ( V_62 , V_103 ) ) ;
F_202 ( F_43 ( V_62 , V_297 ) ) ;
F_202 ( F_43 ( V_62 , V_298 ) ) ;
F_202 ( F_43 ( V_62 , V_73 ) ) ;
F_202 ( F_43 ( V_62 , V_299 ) ) ;
V_38 = F_203 ( V_15 , 0 , V_102 ,
F_192 , NULL ,
V_73 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_203 ( V_15 , 0 , V_73 ,
F_196 , NULL ,
V_102 ,
V_73 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_203 ( V_15 , 0 , V_73 ,
F_186 , NULL ,
V_299 , V_103 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_203 ( V_15 , 0 , V_299 ,
F_183 , NULL ,
V_73 , V_103 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_203 ( V_15 , 0 , V_299 ,
F_190 , ( void * ) 8 ,
V_300 , V_301 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_203 ( V_15 , 0 , V_299 ,
F_190 , ( void * ) 8 ,
V_298 , V_297 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_203 ( V_15 , 0 , V_103 ,
F_186 , NULL ,
V_299 , V_73 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_203 ( V_15 , 0 , V_75 ,
F_190 , ( void * ) 1000000 ,
V_301 , V_302 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_203 ( V_15 , 0 , V_75 ,
F_190 , ( void * ) 1000000 ,
V_297 , V_303 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_203 ( V_15 , 0 , V_304 ,
F_186 , NULL ,
V_297 , V_301 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_203 ( V_15 , 0 , V_301 ,
F_186 , NULL ,
V_297 , V_304 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_203 ( V_15 , 0 , V_301 ,
F_190 , ( void * ) 8 ,
V_300 , V_299 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_203 ( V_15 , 0 , V_301 ,
F_188 , ( void * ) 1000000 ,
V_302 , V_75 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_203 ( V_15 , 0 , V_297 ,
F_183 , NULL ,
V_301 , V_304 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_203 ( V_15 , 0 , V_297 ,
F_190 , ( void * ) 8 ,
V_298 , V_299 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_203 ( V_15 , 0 , V_297 ,
F_188 , ( void * ) 1000000 ,
V_303 , V_75 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_203 ( V_15 , 0 , V_300 ,
F_188 , ( void * ) 8 ,
V_301 , V_299 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_203 ( V_15 , 0 , V_298 ,
F_188 , ( void * ) 8 ,
V_297 , V_299 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_203 ( V_15 , 0 , V_302 ,
F_190 , ( void * ) 1000000 ,
V_301 , V_75 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_203 ( V_15 , 0 , V_303 ,
F_190 , ( void * ) 1000000 ,
V_297 , V_75 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
return 0 ;
}
int F_204 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_56 * V_42 = & V_15 -> V_42 ;
int V_38 ;
unsigned int V_290 = 0 ;
if ( V_42 -> V_13 & V_305 )
V_290 |= 1 << V_306 ;
if ( V_42 -> V_13 & V_307 )
V_290 |= 1 << V_308 ;
if ( F_30 ( V_2 ) ) {
if ( V_42 -> V_13 & V_305 )
V_290 |= 1 << V_309 ;
if ( V_42 -> V_13 & V_307 )
V_290 |= 1 << V_310 ;
if ( V_42 -> V_13 & V_311 )
V_290 |= 1 << V_312 ;
}
V_38 = F_205 ( V_15 , V_313 , V_290 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_206 ( V_15 , V_102 , V_42 -> V_314 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_205 ( V_15 , V_315 , 1 << V_316 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_207 ( V_15 , V_103 ,
V_42 -> V_317 , V_42 -> V_318 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_207 ( V_15 , V_75 ,
V_42 -> V_319 , V_42 -> V_320 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_207 ( V_15 , V_300 ,
V_42 -> V_321 , V_42 -> V_322 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_207 ( V_15 , V_304 ,
V_42 -> V_323 , V_42 -> V_324 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_207 ( V_15 , V_298 ,
V_42 -> V_321 , V_42 -> V_296 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_203 ( V_15 , 0 , V_298 ,
F_199 , V_2 ,
V_298 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_15 -> V_325 ) {
V_38 = F_207 ( V_15 , V_298 , 0 , V_15 -> V_325 ) ;
if ( V_38 < 0 )
return V_38 ;
}
if ( ! ( V_42 -> V_295 & ( V_326 | V_327 ) ) ) {
V_38 = F_203 ( V_15 , 0 , V_75 ,
F_197 , V_42 ,
V_75 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
}
F_208 ( V_15 , V_301 ) ;
return 0 ;
}
static void F_209 ( struct V_1 * V_2 )
{
F_181 ( V_2 ) ;
}
void F_210 ( struct V_1 * V_2 )
{
V_2 -> V_328 -- ;
if ( V_2 -> V_328 > 0 )
return;
F_161 ( V_2 ) ;
if ( V_2 -> V_329 ) {
if ( V_2 -> V_34 -> V_149 != NULL )
V_2 -> V_34 -> V_149 ( V_2 ) ;
V_2 -> V_34 -> V_330 ( V_2 ) ;
V_2 -> V_329 = 0 ;
}
if ( F_71 ( & V_2 -> V_147 ) )
F_72 ( & V_2 -> V_147 ) ;
if ( V_2 -> V_331 ) {
V_2 -> V_331 ( V_2 ) ;
V_2 -> V_331 = NULL ;
}
F_211 ( V_2 ) ;
}
int F_212 ( struct V_16 * V_3 , int V_22 ,
struct V_249 * V_249 ,
struct V_1 * * V_332 )
{
struct V_1 * V_2 ;
int V_38 ;
V_38 = F_213 ( V_3 , V_22 , V_249 , & V_2 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_2 -> V_328 > 1 ) {
* V_332 = V_2 ;
return 0 ;
}
V_38 = F_200 ( V_2 ) ;
if ( V_38 < 0 ) {
F_214 ( V_3 , L_13 ) ;
goto error;
}
if ( ( V_38 = V_2 -> V_34 -> V_333 ( V_2 ) ) < 0 )
goto error;
V_2 -> V_329 = 1 ;
V_38 = F_204 ( V_2 ) ;
if ( V_38 < 0 ) {
F_214 ( V_3 , L_14 ) ;
goto error;
}
* V_332 = V_2 ;
return 0 ;
error:
F_210 ( V_2 ) ;
return V_38 ;
}
static int F_215 ( struct V_249 * V_249 ,
struct V_16 * V_3 ,
int V_22 )
{
struct V_276 * V_277 ;
struct V_1 * V_2 ;
int V_38 ;
V_38 = F_212 ( V_3 , V_22 , V_249 , & V_2 ) ;
if ( V_38 < 0 )
return V_38 ;
V_277 = F_216 ( sizeof( * V_277 ) , V_39 ) ;
if ( V_277 == NULL ) {
F_210 ( V_2 ) ;
return - V_40 ;
}
V_277 -> V_2 = V_2 ;
if ( V_2 -> V_328 == 1 ) {
V_2 -> V_249 = V_277 ;
V_2 -> V_331 = F_209 ;
}
V_249 -> V_282 = V_277 ;
return 0 ;
}
static int F_217 ( struct V_269 * V_269 , struct V_249 * V_249 )
{
struct V_16 * V_3 ;
int V_38 = F_218 ( V_269 , V_249 ) ;
if ( V_38 < 0 )
return V_38 ;
V_3 = F_167 ( F_166 ( V_269 ) ,
V_273 ) ;
V_38 = F_219 ( V_249 , V_3 , V_155 ) ;
if ( V_3 )
F_178 ( V_3 -> V_19 ) ;
return V_38 ;
}
static int F_220 ( struct V_269 * V_269 , struct V_249 * V_249 )
{
struct V_16 * V_3 ;
int V_38 = F_218 ( V_269 , V_249 ) ;
if ( V_38 < 0 )
return V_38 ;
V_3 = F_167 ( F_166 ( V_269 ) ,
V_274 ) ;
V_38 = F_219 ( V_249 , V_3 , V_334 ) ;
if ( V_3 )
F_178 ( V_3 -> V_19 ) ;
return V_38 ;
}
static int F_219 ( struct V_249 * V_249 , struct V_16 * V_3 , int V_22 )
{
int V_38 ;
T_5 V_253 ;
if ( V_3 == NULL ) {
V_38 = - V_266 ;
goto V_335;
}
V_38 = F_221 ( V_3 -> V_19 , V_249 ) ;
if ( V_38 < 0 )
goto V_335;
if ( ! F_222 ( V_3 -> V_19 -> V_336 ) ) {
V_38 = - V_41 ;
goto V_337;
}
F_155 ( & V_253 , V_261 ) ;
F_156 ( & V_3 -> V_338 , & V_253 ) ;
F_3 ( & V_3 -> V_339 ) ;
while ( 1 ) {
V_38 = F_215 ( V_249 , V_3 , V_22 ) ;
if ( V_38 >= 0 )
break;
if ( V_38 == - V_258 ) {
if ( V_249 -> V_247 & V_255 ) {
V_38 = - V_229 ;
break;
}
} else
break;
F_223 ( V_340 ) ;
F_7 ( & V_3 -> V_339 ) ;
F_224 () ;
F_3 ( & V_3 -> V_339 ) ;
if ( V_3 -> V_19 -> V_265 ) {
V_38 = - V_266 ;
break;
}
if ( F_154 ( V_261 ) ) {
V_38 = - V_262 ;
break;
}
}
F_159 ( & V_3 -> V_338 , & V_253 ) ;
F_7 ( & V_3 -> V_339 ) ;
if ( V_38 < 0 )
goto V_341;
return V_38 ;
V_341:
F_225 ( V_3 -> V_19 -> V_336 ) ;
V_337:
F_226 ( V_3 -> V_19 , V_249 ) ;
V_335:
return V_38 ;
}
static int F_227 ( struct V_269 * V_269 , struct V_249 * V_249 )
{
struct V_16 * V_3 ;
struct V_1 * V_2 ;
struct V_276 * V_277 ;
V_277 = V_249 -> V_282 ;
V_2 = V_277 -> V_2 ;
if ( F_228 ( ! V_2 ) )
return - V_113 ;
V_3 = V_2 -> V_3 ;
F_3 ( & V_3 -> V_339 ) ;
F_210 ( V_2 ) ;
F_29 ( V_277 ) ;
F_7 ( & V_3 -> V_339 ) ;
F_117 ( & V_3 -> V_338 ) ;
F_225 ( V_3 -> V_19 -> V_336 ) ;
F_226 ( V_3 -> V_19 , V_249 ) ;
return 0 ;
}
static T_6 F_229 ( struct V_1 * V_2 ,
T_3 V_112 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
T_6 V_175 ;
T_6 V_217 ;
T_6 V_342 ;
if ( V_112 == 0 )
return 0 ;
F_11 ( V_2 ) ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_116 :
break;
case V_179 :
case V_178 :
if ( F_85 ( V_2 ) >= 0 )
break;
case V_218 :
V_217 = - V_202 ;
goto V_343;
case V_228 :
V_217 = - V_267 ;
goto V_343;
default:
V_217 = - V_117 ;
goto V_343;
}
V_342 = F_230 ( V_15 ) ;
if ( V_342 <= 0 ) {
V_217 = 0 ;
goto V_343;
}
if ( V_112 > ( T_3 ) V_342 )
V_112 = V_342 ;
V_175 = V_15 -> V_139 -> V_175 - V_112 ;
if ( V_175 < 0 )
V_175 += V_15 -> V_145 ;
V_15 -> V_139 -> V_175 = V_175 ;
V_217 = V_112 ;
V_343:
F_13 ( V_2 ) ;
return V_217 ;
}
static T_6 F_231 ( struct V_1 * V_2 ,
T_3 V_112 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
T_6 V_175 ;
T_6 V_217 ;
T_6 V_342 ;
if ( V_112 == 0 )
return 0 ;
F_11 ( V_2 ) ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_116 :
case V_179 :
break;
case V_178 :
if ( F_85 ( V_2 ) >= 0 )
break;
case V_218 :
V_217 = - V_202 ;
goto V_343;
case V_228 :
V_217 = - V_267 ;
goto V_343;
default:
V_217 = - V_117 ;
goto V_343;
}
V_342 = F_232 ( V_15 ) ;
if ( V_342 <= 0 ) {
V_217 = 0 ;
goto V_343;
}
if ( V_112 > ( T_3 ) V_342 )
V_112 = V_342 ;
V_175 = V_15 -> V_139 -> V_175 - V_112 ;
if ( V_175 < 0 )
V_175 += V_15 -> V_145 ;
V_15 -> V_139 -> V_175 = V_175 ;
V_217 = V_112 ;
V_343:
F_13 ( V_2 ) ;
return V_217 ;
}
static T_6 F_233 ( struct V_1 * V_2 ,
T_3 V_112 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
T_6 V_175 ;
T_6 V_217 ;
T_6 V_177 ;
if ( V_112 == 0 )
return 0 ;
F_11 ( V_2 ) ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_116 :
case V_222 :
break;
case V_179 :
case V_178 :
if ( F_85 ( V_2 ) >= 0 )
break;
case V_218 :
V_217 = - V_202 ;
goto V_343;
case V_228 :
V_217 = - V_267 ;
goto V_343;
default:
V_217 = - V_117 ;
goto V_343;
}
V_177 = F_88 ( V_15 ) ;
if ( V_177 <= 0 ) {
V_217 = 0 ;
goto V_343;
}
if ( V_112 > ( T_3 ) V_177 )
V_112 = V_177 ;
V_175 = V_15 -> V_139 -> V_175 + V_112 ;
if ( V_175 >= ( T_6 ) V_15 -> V_145 )
V_175 -= V_15 -> V_145 ;
V_15 -> V_139 -> V_175 = V_175 ;
V_217 = V_112 ;
V_343:
F_13 ( V_2 ) ;
return V_217 ;
}
static T_6 F_234 ( struct V_1 * V_2 ,
T_3 V_112 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
T_6 V_175 ;
T_6 V_217 ;
T_6 V_177 ;
if ( V_112 == 0 )
return 0 ;
F_11 ( V_2 ) ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_116 :
case V_179 :
case V_222 :
break;
case V_178 :
if ( F_85 ( V_2 ) >= 0 )
break;
case V_218 :
V_217 = - V_202 ;
goto V_343;
case V_228 :
V_217 = - V_267 ;
goto V_343;
default:
V_217 = - V_117 ;
goto V_343;
}
V_177 = F_89 ( V_15 ) ;
if ( V_177 <= 0 ) {
V_217 = 0 ;
goto V_343;
}
if ( V_112 > ( T_3 ) V_177 )
V_112 = V_177 ;
V_175 = V_15 -> V_139 -> V_175 + V_112 ;
if ( V_175 >= ( T_6 ) V_15 -> V_145 )
V_175 -= V_15 -> V_145 ;
V_15 -> V_139 -> V_175 = V_175 ;
V_217 = V_112 ;
V_343:
F_13 ( V_2 ) ;
return V_217 ;
}
static int F_235 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
int V_38 ;
F_11 ( V_2 ) ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_179 :
if ( V_2 -> V_22 == V_334 )
goto V_344;
case V_178 :
if ( ( V_38 = F_85 ( V_2 ) ) < 0 )
break;
case V_116 :
case V_228 :
V_38 = 0 ;
break;
case V_218 :
V_38 = - V_202 ;
break;
default:
V_344:
V_38 = - V_117 ;
break;
}
F_13 ( V_2 ) ;
return V_38 ;
}
static int F_236 ( struct V_1 * V_2 ,
T_6 T_2 * V_185 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
int V_38 ;
T_6 V_345 = 0 ;
F_11 ( V_2 ) ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_179 :
if ( V_2 -> V_22 == V_334 )
goto V_344;
case V_178 :
if ( ( V_38 = F_85 ( V_2 ) ) < 0 )
break;
case V_116 :
case V_228 :
V_38 = 0 ;
if ( V_2 -> V_22 == V_155 )
V_345 = F_230 ( V_15 ) ;
else
V_345 = F_89 ( V_15 ) ;
V_345 += V_15 -> V_180 ;
break;
case V_218 :
V_38 = - V_202 ;
break;
default:
V_344:
V_38 = - V_117 ;
break;
}
F_13 ( V_2 ) ;
if ( ! V_38 )
if ( F_237 ( V_345 , V_185 ) )
V_38 = - V_41 ;
return V_38 ;
}
static int F_238 ( struct V_1 * V_2 ,
struct F_238 T_2 * V_346 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct F_238 V_347 ;
volatile struct V_348 * V_110 ;
volatile struct V_349 * V_139 ;
int V_38 ;
memset ( & V_347 , 0 , sizeof( V_347 ) ) ;
if ( F_91 ( V_347 . V_11 , ( unsigned T_2 * ) & ( V_346 -> V_11 ) ) )
return - V_41 ;
if ( F_82 ( & V_347 . V_350 . V_139 , & ( V_346 -> V_350 . V_139 ) , sizeof( struct V_349 ) ) )
return - V_41 ;
V_110 = V_15 -> V_110 ;
V_139 = V_15 -> V_139 ;
if ( V_347 . V_11 & V_351 ) {
V_38 = F_235 ( V_2 ) ;
if ( V_38 < 0 )
return V_38 ;
}
F_11 ( V_2 ) ;
if ( ! ( V_347 . V_11 & V_352 ) )
V_139 -> V_175 = V_347 . V_350 . V_139 . V_175 ;
else
V_347 . V_350 . V_139 . V_175 = V_139 -> V_175 ;
if ( ! ( V_347 . V_11 & V_353 ) )
V_139 -> V_140 = V_347 . V_350 . V_139 . V_140 ;
else
V_347 . V_350 . V_139 . V_140 = V_139 -> V_140 ;
V_347 . V_193 . V_110 . V_109 = V_110 -> V_109 ;
V_347 . V_193 . V_110 . V_176 = V_110 -> V_176 ;
V_347 . V_193 . V_110 . V_170 = V_110 -> V_170 ;
V_347 . V_193 . V_110 . V_166 = V_110 -> V_166 ;
F_13 ( V_2 ) ;
if ( F_28 ( V_346 , & V_347 , sizeof( V_347 ) ) )
return - V_41 ;
return 0 ;
}
static int F_239 ( struct V_1 * V_2 , int T_2 * V_354 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
int V_355 ;
if ( F_91 ( V_355 , V_354 ) )
return - V_41 ;
if ( V_355 < 0 || V_355 > V_154 )
return - V_80 ;
V_15 -> V_153 = V_355 ;
return 0 ;
}
static int F_240 ( struct V_249 * V_249 ,
struct V_1 * V_2 ,
unsigned int V_356 , void T_2 * V_355 )
{
switch ( V_356 ) {
case V_357 :
return F_237 ( V_358 , ( int T_2 * ) V_355 ) ? - V_41 : 0 ;
case V_359 :
return F_26 ( V_2 , V_355 ) ;
case V_360 :
return 0 ;
case V_361 :
return F_239 ( V_2 , V_355 ) ;
case V_362 :
return F_51 ( V_2 , V_355 ) ;
case V_363 :
return F_74 ( V_2 , V_355 ) ;
case V_364 :
return F_75 ( V_2 ) ;
case V_365 :
return F_81 ( V_2 , V_355 ) ;
case V_366 :
return F_90 ( V_2 , V_355 , false ) ;
case V_367 :
return F_90 ( V_2 , V_355 , true ) ;
case V_368 :
return F_93 ( V_2 , V_355 ) ;
case V_369 :
return F_148 ( V_2 , V_249 ) ;
case V_370 :
return F_144 ( V_2 ) ;
case V_371 :
return F_104 ( & V_212 , V_2 , V_178 ) ;
case V_372 :
return F_168 ( V_2 , ( int ) ( unsigned long ) V_355 ) ;
case V_373 :
return F_181 ( V_2 ) ;
case V_374 :
return F_136 ( V_2 ) ;
case V_375 :
return F_140 ( V_2 ) ;
case V_376 :
return F_235 ( V_2 ) ;
case V_377 :
return F_236 ( V_2 , V_355 ) ;
case V_378 :
return F_238 ( V_2 , V_355 ) ;
#ifdef F_241
case V_379 :
return F_242 ( V_2 , V_355 ) ;
case V_380 :
return F_243 ( V_2 , V_355 ) ;
#endif
case V_381 :
return F_153 ( V_2 , V_249 ) ;
case V_382 :
return F_161 ( V_2 ) ;
case V_383 :
{
int V_185 ;
F_11 ( V_2 ) ;
V_185 = F_126 ( V_2 , ( int ) ( unsigned long ) V_355 ) ;
F_13 ( V_2 ) ;
return V_185 ;
}
}
F_214 ( V_2 -> V_3 , L_15 , V_356 ) ;
return - V_384 ;
}
static int F_244 ( struct V_249 * V_249 ,
struct V_1 * V_2 ,
unsigned int V_356 , void T_2 * V_355 )
{
if ( F_228 ( ! V_2 ) )
return - V_113 ;
if ( F_228 ( V_2 -> V_22 != V_155 ) )
return - V_80 ;
switch ( V_356 ) {
case V_385 :
{
struct V_386 V_387 ;
struct V_386 T_2 * V_388 = V_355 ;
struct V_14 * V_15 = V_2 -> V_15 ;
T_6 V_150 ;
if ( V_15 -> V_110 -> V_109 == V_114 )
return - V_117 ;
if ( F_237 ( 0 , & V_388 -> V_150 ) )
return - V_41 ;
if ( F_82 ( & V_387 , V_388 , sizeof( V_387 ) ) )
return - V_41 ;
V_150 = F_245 ( V_2 , V_387 . V_389 , V_387 . V_112 ) ;
F_246 ( V_150 , & V_388 -> V_150 ) ;
return V_150 < 0 ? V_150 : 0 ;
}
case V_390 :
{
struct V_391 V_392 ;
struct V_391 T_2 * V_393 = V_355 ;
struct V_14 * V_15 = V_2 -> V_15 ;
void T_2 * * V_394 ;
T_6 V_150 ;
if ( V_15 -> V_110 -> V_109 == V_114 )
return - V_117 ;
if ( V_15 -> V_126 > 128 )
return - V_80 ;
if ( F_237 ( 0 , & V_393 -> V_150 ) )
return - V_41 ;
if ( F_82 ( & V_392 , V_393 , sizeof( V_392 ) ) )
return - V_41 ;
V_394 = F_52 ( V_392 . V_394 ,
sizeof( void * ) * V_15 -> V_126 ) ;
if ( F_53 ( V_394 ) )
return F_54 ( V_394 ) ;
V_150 = F_247 ( V_2 , V_394 , V_392 . V_112 ) ;
F_29 ( V_394 ) ;
F_246 ( V_150 , & V_393 -> V_150 ) ;
return V_150 < 0 ? V_150 : 0 ;
}
case V_395 :
{
T_3 V_112 ;
T_3 T_2 * V_396 = V_355 ;
T_6 V_150 ;
if ( F_91 ( V_112 , V_396 ) )
return - V_41 ;
if ( F_237 ( 0 , V_396 ) )
return - V_41 ;
V_150 = F_229 ( V_2 , V_112 ) ;
F_246 ( V_150 , V_396 ) ;
return V_150 < 0 ? V_150 : 0 ;
}
case V_397 :
{
T_3 V_112 ;
T_3 T_2 * V_396 = V_355 ;
T_6 V_150 ;
if ( F_91 ( V_112 , V_396 ) )
return - V_41 ;
if ( F_237 ( 0 , V_396 ) )
return - V_41 ;
V_150 = F_233 ( V_2 , V_112 ) ;
F_246 ( V_150 , V_396 ) ;
return V_150 < 0 ? V_150 : 0 ;
}
}
return F_240 ( V_249 , V_2 , V_356 , V_355 ) ;
}
static int F_248 ( struct V_249 * V_249 ,
struct V_1 * V_2 ,
unsigned int V_356 , void T_2 * V_355 )
{
if ( F_228 ( ! V_2 ) )
return - V_113 ;
if ( F_228 ( V_2 -> V_22 != V_334 ) )
return - V_80 ;
switch ( V_356 ) {
case V_398 :
{
struct V_386 V_387 ;
struct V_386 T_2 * V_388 = V_355 ;
struct V_14 * V_15 = V_2 -> V_15 ;
T_6 V_150 ;
if ( V_15 -> V_110 -> V_109 == V_114 )
return - V_117 ;
if ( F_237 ( 0 , & V_388 -> V_150 ) )
return - V_41 ;
if ( F_82 ( & V_387 , V_388 , sizeof( V_387 ) ) )
return - V_41 ;
V_150 = F_249 ( V_2 , V_387 . V_389 , V_387 . V_112 ) ;
F_246 ( V_150 , & V_388 -> V_150 ) ;
return V_150 < 0 ? V_150 : 0 ;
}
case V_399 :
{
struct V_391 V_392 ;
struct V_391 T_2 * V_393 = V_355 ;
struct V_14 * V_15 = V_2 -> V_15 ;
void * V_394 ;
T_6 V_150 ;
if ( V_15 -> V_110 -> V_109 == V_114 )
return - V_117 ;
if ( V_15 -> V_126 > 128 )
return - V_80 ;
if ( F_237 ( 0 , & V_393 -> V_150 ) )
return - V_41 ;
if ( F_82 ( & V_392 , V_393 , sizeof( V_392 ) ) )
return - V_41 ;
V_394 = F_52 ( V_392 . V_394 ,
sizeof( void * ) * V_15 -> V_126 ) ;
if ( F_53 ( V_394 ) )
return F_54 ( V_394 ) ;
V_150 = F_250 ( V_2 , V_394 , V_392 . V_112 ) ;
F_29 ( V_394 ) ;
F_246 ( V_150 , & V_393 -> V_150 ) ;
return V_150 < 0 ? V_150 : 0 ;
}
case V_395 :
{
T_3 V_112 ;
T_3 T_2 * V_396 = V_355 ;
T_6 V_150 ;
if ( F_91 ( V_112 , V_396 ) )
return - V_41 ;
if ( F_237 ( 0 , V_396 ) )
return - V_41 ;
V_150 = F_231 ( V_2 , V_112 ) ;
F_246 ( V_150 , V_396 ) ;
return V_150 < 0 ? V_150 : 0 ;
}
case V_397 :
{
T_3 V_112 ;
T_3 T_2 * V_396 = V_355 ;
T_6 V_150 ;
if ( F_91 ( V_112 , V_396 ) )
return - V_41 ;
if ( F_237 ( 0 , V_396 ) )
return - V_41 ;
V_150 = F_234 ( V_2 , V_112 ) ;
F_246 ( V_150 , V_396 ) ;
return V_150 < 0 ? V_150 : 0 ;
}
}
return F_240 ( V_249 , V_2 , V_356 , V_355 ) ;
}
static long F_251 ( struct V_249 * V_249 , unsigned int V_356 ,
unsigned long V_355 )
{
struct V_276 * V_277 ;
V_277 = V_249 -> V_282 ;
if ( ( ( V_356 >> 8 ) & 0xff ) != 'A' )
return - V_384 ;
return F_244 ( V_249 , V_277 -> V_2 , V_356 ,
( void T_2 * ) V_355 ) ;
}
static long F_252 ( struct V_249 * V_249 , unsigned int V_356 ,
unsigned long V_355 )
{
struct V_276 * V_277 ;
V_277 = V_249 -> V_282 ;
if ( ( ( V_356 >> 8 ) & 0xff ) != 'A' )
return - V_384 ;
return F_248 ( V_249 , V_277 -> V_2 , V_356 ,
( void T_2 * ) V_355 ) ;
}
int F_253 ( struct V_1 * V_2 ,
unsigned int V_356 , void * V_355 )
{
T_1 V_12 ;
int V_150 ;
V_12 = F_19 () ;
switch ( V_2 -> V_22 ) {
case V_155 :
V_150 = F_244 ( NULL , V_2 , V_356 ,
( void T_2 * ) V_355 ) ;
break;
case V_334 :
V_150 = F_248 ( NULL , V_2 , V_356 ,
( void T_2 * ) V_355 ) ;
break;
default:
V_150 = - V_80 ;
break;
}
F_23 ( V_12 ) ;
return V_150 ;
}
static T_7 F_254 ( struct V_249 * V_249 , char T_2 * V_389 , T_8 V_287 ,
T_9 * V_400 )
{
struct V_276 * V_277 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
T_6 V_150 ;
V_277 = V_249 -> V_282 ;
V_2 = V_277 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_113 ;
V_15 = V_2 -> V_15 ;
if ( V_15 -> V_110 -> V_109 == V_114 )
return - V_117 ;
if ( ! F_255 ( V_15 , V_287 ) )
return - V_80 ;
V_287 = F_256 ( V_15 , V_287 ) ;
V_150 = F_249 ( V_2 , V_389 , V_287 ) ;
if ( V_150 > 0 )
V_150 = F_257 ( V_15 , V_150 ) ;
return V_150 ;
}
static T_7 F_258 ( struct V_249 * V_249 , const char T_2 * V_389 ,
T_8 V_287 , T_9 * V_400 )
{
struct V_276 * V_277 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
T_6 V_150 ;
V_277 = V_249 -> V_282 ;
V_2 = V_277 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_113 ;
V_15 = V_2 -> V_15 ;
if ( V_15 -> V_110 -> V_109 == V_114 )
return - V_117 ;
if ( ! F_255 ( V_15 , V_287 ) )
return - V_80 ;
V_287 = F_256 ( V_15 , V_287 ) ;
V_150 = F_245 ( V_2 , V_389 , V_287 ) ;
if ( V_150 > 0 )
V_150 = F_257 ( V_15 , V_150 ) ;
return V_150 ;
}
static T_7 F_259 ( struct V_401 * V_402 , struct V_403 * V_404 )
{
struct V_276 * V_277 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
T_6 V_150 ;
unsigned long V_58 ;
void T_2 * * V_394 ;
T_3 V_112 ;
V_277 = V_402 -> V_405 -> V_282 ;
V_2 = V_277 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_113 ;
V_15 = V_2 -> V_15 ;
if ( V_15 -> V_110 -> V_109 == V_114 )
return - V_117 ;
if ( ! F_260 ( V_404 ) )
return - V_80 ;
if ( V_404 -> V_406 > 1024 || V_404 -> V_406 != V_15 -> V_126 )
return - V_80 ;
if ( ! F_255 ( V_15 , V_404 -> V_407 -> V_408 ) )
return - V_80 ;
V_112 = F_261 ( V_15 , V_404 -> V_407 -> V_408 ) ;
V_394 = F_27 ( sizeof( void * ) * V_404 -> V_406 , V_39 ) ;
if ( V_394 == NULL )
return - V_40 ;
for ( V_58 = 0 ; V_58 < V_404 -> V_406 ; ++ V_58 )
V_394 [ V_58 ] = V_404 -> V_407 [ V_58 ] . V_409 ;
V_150 = F_250 ( V_2 , V_394 , V_112 ) ;
if ( V_150 > 0 )
V_150 = F_257 ( V_15 , V_150 ) ;
F_29 ( V_394 ) ;
return V_150 ;
}
static T_7 F_262 ( struct V_401 * V_402 , struct V_403 * V_410 )
{
struct V_276 * V_277 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
T_6 V_150 ;
unsigned long V_58 ;
void T_2 * * V_394 ;
T_3 V_112 ;
V_277 = V_402 -> V_405 -> V_282 ;
V_2 = V_277 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_113 ;
V_15 = V_2 -> V_15 ;
if ( V_15 -> V_110 -> V_109 == V_114 )
return - V_117 ;
if ( ! F_260 ( V_410 ) )
return - V_80 ;
if ( V_410 -> V_406 > 128 || V_410 -> V_406 != V_15 -> V_126 ||
! F_255 ( V_15 , V_410 -> V_407 -> V_408 ) )
return - V_80 ;
V_112 = F_261 ( V_15 , V_410 -> V_407 -> V_408 ) ;
V_394 = F_27 ( sizeof( void * ) * V_410 -> V_406 , V_39 ) ;
if ( V_394 == NULL )
return - V_40 ;
for ( V_58 = 0 ; V_58 < V_410 -> V_406 ; ++ V_58 )
V_394 [ V_58 ] = V_410 -> V_407 [ V_58 ] . V_409 ;
V_150 = F_247 ( V_2 , V_394 , V_112 ) ;
if ( V_150 > 0 )
V_150 = F_257 ( V_15 , V_150 ) ;
F_29 ( V_394 ) ;
return V_150 ;
}
static unsigned int F_263 ( struct V_249 * V_249 , T_10 * V_253 )
{
struct V_276 * V_277 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
unsigned int V_290 ;
T_3 V_177 ;
V_277 = V_249 -> V_282 ;
V_2 = V_277 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_113 ;
V_15 = V_2 -> V_15 ;
F_264 ( V_249 , & V_15 -> V_214 , V_253 ) ;
F_11 ( V_2 ) ;
V_177 = F_88 ( V_15 ) ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_178 :
case V_116 :
case V_222 :
if ( V_177 >= V_15 -> V_139 -> V_140 ) {
V_290 = V_411 | V_412 ;
break;
}
case V_179 :
V_290 = 0 ;
break;
default:
V_290 = V_411 | V_412 | V_413 ;
break;
}
F_13 ( V_2 ) ;
return V_290 ;
}
static unsigned int F_265 ( struct V_249 * V_249 , T_10 * V_253 )
{
struct V_276 * V_277 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
unsigned int V_290 ;
T_3 V_177 ;
V_277 = V_249 -> V_282 ;
V_2 = V_277 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_113 ;
V_15 = V_2 -> V_15 ;
F_264 ( V_249 , & V_15 -> V_214 , V_253 ) ;
F_11 ( V_2 ) ;
V_177 = F_89 ( V_15 ) ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_178 :
case V_116 :
case V_222 :
if ( V_177 >= V_15 -> V_139 -> V_140 ) {
V_290 = V_414 | V_415 ;
break;
}
V_290 = 0 ;
break;
case V_179 :
if ( V_177 > 0 ) {
V_290 = V_414 | V_415 ;
break;
}
default:
V_290 = V_414 | V_415 | V_413 ;
break;
}
F_13 ( V_2 ) ;
return V_290 ;
}
static int F_266 ( struct V_416 * V_417 ,
struct V_418 * V_419 )
{
struct V_1 * V_2 = V_417 -> V_420 ;
struct V_14 * V_15 ;
if ( V_2 == NULL )
return V_421 ;
V_15 = V_2 -> V_15 ;
V_419 -> V_422 = F_267 ( V_15 -> V_110 ) ;
F_268 ( V_419 -> V_422 ) ;
return 0 ;
}
static int V_348 ( struct V_1 * V_2 , struct V_249 * V_249 ,
struct V_416 * V_417 )
{
long V_423 ;
if ( ! ( V_417 -> V_424 & V_425 ) )
return - V_80 ;
V_423 = V_417 -> V_426 - V_417 -> V_427 ;
if ( V_423 != F_269 ( sizeof( struct V_348 ) ) )
return - V_80 ;
V_417 -> V_428 = & V_429 ;
V_417 -> V_420 = V_2 ;
V_417 -> V_424 |= V_430 | V_431 ;
return 0 ;
}
static int F_270 ( struct V_416 * V_417 ,
struct V_418 * V_419 )
{
struct V_1 * V_2 = V_417 -> V_420 ;
struct V_14 * V_15 ;
if ( V_2 == NULL )
return V_421 ;
V_15 = V_2 -> V_15 ;
V_419 -> V_422 = F_267 ( V_15 -> V_139 ) ;
F_268 ( V_419 -> V_422 ) ;
return 0 ;
}
static int V_349 ( struct V_1 * V_2 , struct V_249 * V_249 ,
struct V_416 * V_417 )
{
long V_423 ;
if ( ! ( V_417 -> V_424 & V_425 ) )
return - V_80 ;
V_423 = V_417 -> V_426 - V_417 -> V_427 ;
if ( V_423 != F_269 ( sizeof( struct V_349 ) ) )
return - V_80 ;
V_417 -> V_428 = & V_432 ;
V_417 -> V_420 = V_2 ;
V_417 -> V_424 |= V_430 | V_431 ;
return 0 ;
}
static int V_348 ( struct V_1 * V_2 , struct V_249 * V_249 ,
struct V_416 * V_417 )
{
return - V_113 ;
}
static int V_349 ( struct V_1 * V_2 , struct V_249 * V_249 ,
struct V_416 * V_417 )
{
return - V_113 ;
}
static inline struct V_422 *
F_271 ( struct V_1 * V_2 , unsigned long V_433 )
{
void * V_434 = V_2 -> V_15 -> V_435 + V_433 ;
return F_267 ( V_434 ) ;
}
static int F_272 ( struct V_416 * V_417 ,
struct V_418 * V_419 )
{
struct V_1 * V_2 = V_417 -> V_420 ;
struct V_14 * V_15 ;
unsigned long V_400 ;
struct V_422 * V_422 ;
T_8 V_325 ;
if ( V_2 == NULL )
return V_421 ;
V_15 = V_2 -> V_15 ;
V_400 = V_419 -> V_436 << V_437 ;
V_325 = F_269 ( V_15 -> V_325 ) ;
if ( V_400 > V_325 - V_438 )
return V_421 ;
if ( V_2 -> V_34 -> V_422 )
V_422 = V_2 -> V_34 -> V_422 ( V_2 , V_400 ) ;
else
V_422 = F_271 ( V_2 , V_400 ) ;
if ( ! V_422 )
return V_421 ;
F_268 ( V_422 ) ;
V_419 -> V_422 = V_422 ;
return 0 ;
}
int F_273 ( struct V_1 * V_2 ,
struct V_416 * V_417 )
{
V_417 -> V_424 |= V_430 | V_431 ;
#ifdef F_274
if ( V_2 -> V_50 . V_51 . type == V_439 ) {
V_417 -> V_440 = F_275 ( V_417 -> V_440 ) ;
return F_276 ( V_417 , V_417 -> V_427 ,
V_2 -> V_50 . V_441 >> V_437 ,
V_417 -> V_426 - V_417 -> V_427 , V_417 -> V_440 ) ;
}
#endif
#ifndef F_277
if ( ! V_2 -> V_34 -> V_422 &&
V_2 -> V_50 . V_51 . type == V_52 )
return F_278 ( V_2 -> V_50 . V_51 . V_51 ,
V_417 ,
V_2 -> V_15 -> V_435 ,
V_2 -> V_15 -> V_442 ,
V_417 -> V_426 - V_417 -> V_427 ) ;
#endif
V_417 -> V_428 = & V_443 ;
return 0 ;
}
int F_279 ( struct V_1 * V_2 ,
struct V_416 * V_417 )
{
struct V_14 * V_15 = V_2 -> V_15 ; ;
V_417 -> V_440 = F_280 ( V_417 -> V_440 ) ;
return F_281 ( V_417 , V_15 -> V_442 , V_15 -> V_325 ) ;
}
int F_282 ( struct V_1 * V_2 , struct V_249 * V_249 ,
struct V_416 * V_417 )
{
struct V_14 * V_15 ;
long V_423 ;
unsigned long V_400 ;
T_8 V_325 ;
int V_38 ;
if ( V_2 -> V_22 == V_155 ) {
if ( ! ( V_417 -> V_424 & ( V_444 | V_425 ) ) )
return - V_80 ;
} else {
if ( ! ( V_417 -> V_424 & V_425 ) )
return - V_80 ;
}
V_15 = V_2 -> V_15 ;
if ( V_15 -> V_110 -> V_109 == V_114 )
return - V_117 ;
if ( ! ( V_15 -> V_13 & V_43 ) )
return - V_113 ;
if ( V_15 -> V_123 == V_306 ||
V_15 -> V_123 == V_308 )
return - V_80 ;
V_423 = V_417 -> V_426 - V_417 -> V_427 ;
V_400 = V_417 -> V_445 << V_437 ;
V_325 = F_269 ( V_15 -> V_325 ) ;
if ( ( T_8 ) V_423 > V_325 )
return - V_80 ;
if ( V_400 > V_325 - V_423 )
return - V_80 ;
V_417 -> V_428 = & V_446 ;
V_417 -> V_420 = V_2 ;
if ( V_2 -> V_34 -> V_49 )
V_38 = V_2 -> V_34 -> V_49 ( V_2 , V_417 ) ;
else
V_38 = F_273 ( V_2 , V_417 ) ;
if ( ! V_38 )
F_283 ( & V_2 -> V_120 ) ;
return V_38 ;
}
static int F_284 ( struct V_249 * V_249 , struct V_416 * V_417 )
{
struct V_276 * V_277 ;
struct V_1 * V_2 ;
unsigned long V_400 ;
V_277 = V_249 -> V_282 ;
V_2 = V_277 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_113 ;
V_400 = V_417 -> V_445 << V_437 ;
switch ( V_400 ) {
case V_447 :
if ( V_277 -> V_448 )
return - V_113 ;
return V_348 ( V_2 , V_249 , V_417 ) ;
case V_449 :
if ( V_277 -> V_448 )
return - V_113 ;
return V_349 ( V_2 , V_249 , V_417 ) ;
default:
return F_282 ( V_2 , V_249 , V_417 ) ;
}
return 0 ;
}
static int F_285 ( int V_275 , struct V_249 * V_249 , int V_450 )
{
struct V_276 * V_277 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
V_277 = V_249 -> V_282 ;
V_2 = V_277 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_113 ;
V_15 = V_2 -> V_15 ;
return F_286 ( V_275 , V_249 , V_450 , & V_15 -> V_451 ) ;
}
static void F_287 ( struct V_53 * V_54 ,
struct V_452 * V_453 )
{
unsigned int V_58 ;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_11 = V_453 -> V_11 ;
for ( V_58 = 0 ; V_58 < F_288 ( V_453 -> V_454 ) ; V_58 ++ )
V_54 -> V_454 [ V_58 ] . V_82 [ 0 ] = V_453 -> V_454 [ V_58 ] ;
memcpy ( V_54 -> V_455 , V_453 -> V_455 , sizeof( V_453 -> V_455 ) ) ;
V_54 -> V_72 = F_289 ( V_453 -> V_72 ) ;
V_54 -> V_83 = F_289 ( V_453 -> V_83 ) ;
V_54 -> V_13 = V_453 -> V_13 ;
V_54 -> V_74 = V_453 -> V_74 ;
V_54 -> V_76 = V_453 -> V_76 ;
V_54 -> V_77 = V_453 -> V_77 ;
V_54 -> V_71 = V_453 -> V_71 ;
}
static void F_290 ( struct V_452 * V_453 ,
struct V_53 * V_54 )
{
unsigned int V_58 ;
memset ( V_453 , 0 , sizeof( * V_453 ) ) ;
V_453 -> V_11 = V_54 -> V_11 ;
for ( V_58 = 0 ; V_58 < F_288 ( V_453 -> V_454 ) ; V_58 ++ )
V_453 -> V_454 [ V_58 ] = V_54 -> V_454 [ V_58 ] . V_82 [ 0 ] ;
memcpy ( V_453 -> V_455 , V_54 -> V_455 , sizeof( V_453 -> V_455 ) ) ;
V_453 -> V_72 = F_291 ( V_54 -> V_72 ) ;
V_453 -> V_83 = F_291 ( V_54 -> V_83 ) ;
V_453 -> V_13 = V_54 -> V_13 ;
V_453 -> V_74 = V_54 -> V_74 ;
V_453 -> V_76 = V_54 -> V_76 ;
V_453 -> V_77 = V_54 -> V_77 ;
V_453 -> V_71 = V_54 -> V_71 ;
}
static int F_242 ( struct V_1 * V_2 ,
struct V_452 T_2 * V_456 )
{
struct V_53 * V_54 ;
struct V_452 * V_453 = NULL ;
int V_38 ;
V_54 = F_27 ( sizeof( * V_54 ) , V_39 ) ;
if ( ! V_54 )
return - V_40 ;
V_453 = F_52 ( V_456 , sizeof( * V_453 ) ) ;
if ( F_53 ( V_453 ) ) {
V_38 = F_54 ( V_453 ) ;
goto V_457;
}
F_287 ( V_54 , V_453 ) ;
V_38 = F_32 ( V_2 , V_54 ) ;
F_290 ( V_453 , V_54 ) ;
if ( F_28 ( V_456 , V_453 , sizeof( * V_453 ) ) ) {
if ( ! V_38 )
V_38 = - V_41 ;
}
F_29 ( V_453 ) ;
V_457:
F_29 ( V_54 ) ;
return V_38 ;
}
static int F_243 ( struct V_1 * V_2 ,
struct V_452 T_2 * V_456 )
{
struct V_53 * V_54 ;
struct V_452 * V_453 = NULL ;
int V_38 ;
V_54 = F_27 ( sizeof( * V_54 ) , V_39 ) ;
if ( ! V_54 )
return - V_40 ;
V_453 = F_52 ( V_456 , sizeof( * V_453 ) ) ;
if ( F_53 ( V_453 ) ) {
V_38 = F_54 ( V_453 ) ;
goto V_457;
}
F_287 ( V_54 , V_453 ) ;
V_38 = V_53 ( V_2 , V_54 ) ;
F_290 ( V_453 , V_54 ) ;
if ( F_28 ( V_456 , V_453 , sizeof( * V_453 ) ) ) {
if ( ! V_38 )
V_38 = - V_41 ;
}
F_29 ( V_453 ) ;
V_457:
F_29 ( V_54 ) ;
return V_38 ;
}
static unsigned long F_292 ( struct V_249 * V_249 ,
unsigned long V_441 ,
unsigned long V_458 ,
unsigned long V_436 ,
unsigned long V_11 )
{
struct V_276 * V_277 = V_249 -> V_282 ;
struct V_1 * V_2 = V_277 -> V_2 ;
struct V_14 * V_15 = V_2 -> V_15 ;
unsigned long V_400 = V_436 << V_437 ;
switch ( V_400 ) {
case V_447 :
return ( unsigned long ) V_15 -> V_110 ;
case V_449 :
return ( unsigned long ) V_15 -> V_139 ;
default:
return ( unsigned long ) V_15 -> V_435 + V_400 ;
}
}
