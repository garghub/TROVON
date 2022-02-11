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
static inline void F_57 ( struct V_1 * V_2 ,
int V_112 )
{
#ifdef F_58
if ( V_2 -> V_113 )
F_59 ( V_2 -> V_113 , V_112 ,
& V_2 -> V_15 -> V_114 ) ;
#endif
}
static int V_53 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
struct V_14 * V_15 ;
int V_38 , V_106 ;
unsigned int V_82 ;
T_3 V_115 ;
if ( F_60 ( V_2 ) )
return - V_116 ;
V_15 = V_2 -> V_15 ;
F_11 ( V_2 ) ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_117 :
case V_118 :
case V_119 :
break;
default:
F_13 ( V_2 ) ;
return - V_120 ;
}
F_13 ( V_2 ) ;
#if F_61 ( V_121 )
if ( ! V_2 -> V_122 . V_122 )
#endif
if ( F_62 ( & V_2 -> V_123 ) )
return - V_120 ;
V_54 -> V_72 = ~ 0U ;
V_38 = F_32 ( V_2 , V_54 ) ;
if ( V_38 < 0 )
goto V_124;
V_38 = F_63 ( V_2 , V_54 ) ;
if ( V_38 < 0 )
goto V_124;
if ( V_2 -> V_34 -> V_125 != NULL ) {
V_38 = V_2 -> V_34 -> V_125 ( V_2 , V_54 ) ;
if ( V_38 < 0 )
goto V_124;
}
V_15 -> V_126 = F_64 ( V_54 ) ;
V_15 -> V_127 = F_65 ( V_54 ) ;
V_15 -> V_128 = F_66 ( V_54 ) ;
V_15 -> V_129 = F_67 ( V_54 ) ;
V_15 -> V_107 = F_68 ( V_54 ) ;
V_15 -> V_108 = F_69 ( V_54 ) ;
V_15 -> V_130 = F_70 ( V_54 ) ;
V_15 -> V_131 = F_71 ( V_54 ) ;
V_15 -> V_13 = V_54 -> V_13 ;
V_15 -> V_76 = V_54 -> V_76 ;
V_15 -> V_77 = V_54 -> V_77 ;
V_15 -> V_132 =
( V_54 -> V_13 & V_133 ) &&
( V_54 -> V_11 & V_134 ) ;
V_82 = F_72 ( V_15 -> V_127 ) ;
V_15 -> V_135 = V_82 ;
V_82 *= V_15 -> V_129 ;
V_15 -> V_136 = V_82 ;
V_115 = 1 ;
while ( V_82 % 8 != 0 ) {
V_82 *= 2 ;
V_115 *= 2 ;
}
V_15 -> V_137 = V_82 / 8 ;
V_15 -> V_138 = V_115 ;
V_15 -> V_139 = V_140 ;
V_15 -> V_141 = 1 ;
V_15 -> V_142 -> V_143 = V_15 -> V_108 ;
V_15 -> V_144 = 1 ;
V_15 -> V_145 = V_15 -> V_131 ;
V_15 -> V_146 = 0 ;
V_15 -> V_147 = 0 ;
V_15 -> V_148 = V_15 -> V_131 ;
while ( V_15 -> V_148 * 2 <= V_149 - V_15 -> V_131 )
V_15 -> V_148 *= 2 ;
F_73 ( V_2 ) ;
F_56 ( V_2 , V_118 ) ;
if ( F_74 ( & V_2 -> V_150 ) )
F_75 ( & V_2 -> V_150 ) ;
if ( ( V_106 = F_55 ( V_15 ) ) >= 0 )
F_76 ( & V_2 -> V_150 ,
V_151 , V_106 ) ;
return 0 ;
V_124:
F_56 ( V_2 , V_117 ) ;
if ( V_2 -> V_34 -> V_152 != NULL )
V_2 -> V_34 -> V_152 ( V_2 ) ;
return V_38 ;
}
static int F_77 ( struct V_1 * V_2 ,
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
static int F_78 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
int V_153 = 0 ;
if ( F_60 ( V_2 ) )
return - V_116 ;
V_15 = V_2 -> V_15 ;
F_11 ( V_2 ) ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_118 :
case V_119 :
break;
default:
F_13 ( V_2 ) ;
return - V_120 ;
}
F_13 ( V_2 ) ;
if ( F_62 ( & V_2 -> V_123 ) )
return - V_120 ;
if ( V_2 -> V_34 -> V_152 )
V_153 = V_2 -> V_34 -> V_152 ( V_2 ) ;
F_56 ( V_2 , V_117 ) ;
F_75 ( & V_2 -> V_150 ) ;
return V_153 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct F_79 * V_54 )
{
struct V_14 * V_15 ;
int V_38 ;
if ( F_60 ( V_2 ) )
return - V_116 ;
V_15 = V_2 -> V_15 ;
F_11 ( V_2 ) ;
if ( V_15 -> V_110 -> V_109 == V_117 ) {
F_13 ( V_2 ) ;
return - V_120 ;
}
F_13 ( V_2 ) ;
if ( V_54 -> V_139 < 0 ||
V_54 -> V_139 > V_154 )
return - V_80 ;
if ( V_54 -> V_155 >= F_80 ( 2 , 0 , 12 ) &&
V_54 -> V_156 > V_157 )
return - V_80 ;
if ( V_54 -> V_143 == 0 )
return - V_80 ;
if ( V_54 -> V_147 >= V_15 -> V_148 ) {
if ( V_54 -> V_146 != 0 )
return - V_80 ;
} else {
if ( V_54 -> V_147 > V_54 -> V_146 )
return - V_80 ;
if ( V_54 -> V_146 > V_15 -> V_131 )
return - V_80 ;
}
V_38 = 0 ;
F_11 ( V_2 ) ;
V_15 -> V_139 = V_54 -> V_139 ;
if ( V_54 -> V_155 >= F_80 ( 2 , 0 , 12 ) )
V_15 -> V_156 = V_54 -> V_156 ;
V_15 -> V_141 = V_54 -> V_141 ;
V_15 -> V_142 -> V_143 = V_54 -> V_143 ;
V_15 -> V_144 = V_54 -> V_144 ;
V_15 -> V_145 = V_54 -> V_145 ;
V_15 -> V_146 = V_54 -> V_146 ;
V_15 -> V_147 = V_54 -> V_147 ;
V_54 -> V_148 = V_15 -> V_148 ;
if ( F_81 ( V_2 ) ) {
if ( V_2 -> V_22 == V_158 &&
V_15 -> V_147 > 0 )
F_82 ( V_2 , V_159 ) ;
V_38 = F_83 ( V_2 , V_15 ) ;
}
F_13 ( V_2 ) ;
return V_38 ;
}
static int F_84 ( struct V_1 * V_2 ,
struct F_79 T_2 * V_105 )
{
struct F_79 V_54 ;
int V_38 ;
if ( F_85 ( & V_54 , V_105 , sizeof( V_54 ) ) )
return - V_41 ;
V_38 = F_79 ( V_2 , & V_54 ) ;
if ( F_28 ( V_105 , & V_54 , sizeof( V_54 ) ) )
return - V_41 ;
return V_38 ;
}
int F_86 ( struct V_1 * V_2 ,
struct F_86 * V_110 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
F_11 ( V_2 ) ;
F_87 ( V_110 -> V_160 ,
& V_15 -> V_161 ) ;
if ( V_15 -> V_161 . V_162 ==
V_163 ) {
if ( V_15 -> V_42 . V_13 & V_164 )
V_15 -> V_161 . V_162 =
V_165 ;
else
V_15 -> V_161 . V_162 =
V_166 ;
V_15 -> V_167 . V_168 = 0 ;
} else
V_15 -> V_167 . V_168 = 1 ;
V_110 -> V_109 = V_15 -> V_110 -> V_109 ;
V_110 -> V_169 = V_15 -> V_110 -> V_169 ;
if ( V_110 -> V_109 == V_117 )
goto V_170;
V_110 -> V_114 = V_15 -> V_114 ;
if ( F_81 ( V_2 ) ) {
F_88 ( V_2 ) ;
if ( V_15 -> V_139 == V_171 ) {
V_110 -> V_172 = V_15 -> V_110 -> V_172 ;
V_110 -> V_173 = V_15 -> V_173 ;
V_110 -> V_174 =
V_15 -> V_110 -> V_174 ;
if ( V_15 -> V_167 . V_168 == 1 )
F_89 ( & V_110 -> V_160 ,
& V_110 -> V_175 ,
& V_15 -> V_167 ) ;
goto V_176;
}
} else {
if ( V_15 -> V_139 == V_171 )
F_90 ( V_15 , & V_110 -> V_172 ) ;
}
V_176:
V_110 -> V_177 = V_15 -> V_142 -> V_177 ;
V_110 -> V_178 = V_15 -> V_110 -> V_178 ;
if ( V_2 -> V_22 == V_158 ) {
V_110 -> V_179 = F_91 ( V_15 ) ;
if ( V_15 -> V_110 -> V_109 == V_180 ||
V_15 -> V_110 -> V_109 == V_181 ) {
V_110 -> V_182 = V_15 -> V_131 - V_110 -> V_179 ;
V_110 -> V_182 += V_15 -> V_182 ;
} else
V_110 -> V_182 = 0 ;
} else {
V_110 -> V_179 = F_92 ( V_15 ) ;
if ( V_15 -> V_110 -> V_109 == V_180 )
V_110 -> V_182 = V_110 -> V_179 + V_15 -> V_182 ;
else
V_110 -> V_182 = 0 ;
}
V_110 -> V_183 = V_15 -> V_183 ;
V_110 -> V_184 = V_15 -> V_184 ;
V_15 -> V_183 = 0 ;
V_15 -> V_184 = 0 ;
V_170:
F_13 ( V_2 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct F_86 T_2 * V_185 ,
bool V_186 )
{
struct F_86 V_110 ;
int V_187 ;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
if ( V_186 && F_94 ( V_110 . V_160 ,
( V_188 T_2 * ) ( & V_185 -> V_160 ) ) )
return - V_41 ;
V_187 = F_86 ( V_2 , & V_110 ) ;
if ( V_187 < 0 )
return V_187 ;
if ( F_28 ( V_185 , & V_110 , sizeof( V_110 ) ) )
return - V_41 ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 ,
struct F_95 * V_13 )
{
struct V_14 * V_15 ;
unsigned int V_189 ;
V_189 = V_13 -> V_189 ;
V_15 = V_2 -> V_15 ;
F_11 ( V_2 ) ;
if ( V_15 -> V_110 -> V_109 == V_117 ) {
F_13 ( V_2 ) ;
return - V_120 ;
}
F_13 ( V_2 ) ;
if ( V_189 >= V_15 -> V_129 )
return - V_80 ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_189 = V_189 ;
return V_2 -> V_34 -> V_35 ( V_2 , V_190 , V_13 ) ;
}
static int F_96 ( struct V_1 * V_2 ,
struct F_95 T_2 * V_37 )
{
struct F_95 V_13 ;
int V_187 ;
if ( F_85 ( & V_13 , V_37 , sizeof( V_13 ) ) )
return - V_41 ;
V_187 = F_95 ( V_2 , & V_13 ) ;
if ( V_187 < 0 )
return V_187 ;
if ( F_28 ( V_37 , & V_13 , sizeof( V_13 ) ) )
return - V_41 ;
return 0 ;
}
static void F_97 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_15 -> V_191 == NULL )
return;
if ( V_15 -> V_191 == V_2 ) {
if ( ! V_15 -> V_192 )
F_90 ( V_15 , & V_15 -> V_114 ) ;
} else {
F_97 ( V_15 -> V_191 ) ;
V_15 -> V_114 = V_15 -> V_191 -> V_15 -> V_114 ;
}
V_15 -> V_191 = NULL ;
}
static int F_98 ( struct V_193 * V_34 ,
struct V_1 * V_2 ,
int V_109 , int V_194 )
{
struct V_1 * V_195 = NULL ;
struct V_1 * V_196 ;
int V_187 = 0 , V_197 = 1 ;
F_99 (s, substream) {
if ( V_194 && V_195 != V_2 ) {
if ( V_195 -> V_3 -> V_4 )
F_100 ( & V_195 -> V_7 . V_8 , V_197 ) ;
else
F_101 ( & V_195 -> V_7 . V_10 , V_197 ) ;
V_197 ++ ;
}
V_187 = V_34 -> V_198 ( V_195 , V_109 ) ;
if ( V_187 < 0 )
goto V_199;
}
F_99 (s, substream) {
V_187 = V_34 -> V_200 ( V_195 , V_109 ) ;
if ( V_187 < 0 ) {
if ( V_34 -> V_201 ) {
F_99 (s1, substream) {
if ( V_196 == V_195 )
break;
V_34 -> V_201 ( V_196 , V_109 ) ;
}
}
V_195 = NULL ;
goto V_199;
}
}
F_99 (s, substream) {
V_34 -> V_202 ( V_195 , V_109 ) ;
}
V_199:
if ( V_194 ) {
F_99 (s1, substream) {
if ( V_196 != V_2 ) {
if ( V_196 -> V_3 -> V_4 )
F_7 ( & V_196 -> V_7 . V_8 ) ;
else
F_9 ( & V_196 -> V_7 . V_10 ) ;
}
if ( V_196 == V_195 )
break;
}
}
return V_187 ;
}
static int F_102 ( struct V_193 * V_34 ,
struct V_1 * V_2 ,
int V_109 )
{
int V_187 ;
V_187 = V_34 -> V_198 ( V_2 , V_109 ) ;
if ( V_187 < 0 )
return V_187 ;
V_187 = V_34 -> V_200 ( V_2 , V_109 ) ;
if ( V_187 == 0 )
V_34 -> V_202 ( V_2 , V_109 ) ;
else if ( V_34 -> V_201 )
V_34 -> V_201 ( V_2 , V_109 ) ;
return V_187 ;
}
static int F_103 ( struct V_193 * V_34 ,
struct V_1 * V_2 ,
int V_109 )
{
int V_187 ;
if ( ! F_104 ( V_2 ) )
return F_102 ( V_34 , V_2 , V_109 ) ;
if ( V_2 -> V_3 -> V_4 ) {
if ( ! F_105 ( & V_2 -> V_203 -> V_8 ) ) {
F_7 ( & V_2 -> V_7 . V_8 ) ;
F_3 ( & V_2 -> V_203 -> V_8 ) ;
F_3 ( & V_2 -> V_7 . V_8 ) ;
}
V_187 = F_98 ( V_34 , V_2 , V_109 , 1 ) ;
F_7 ( & V_2 -> V_203 -> V_8 ) ;
} else {
if ( ! F_106 ( & V_2 -> V_203 -> V_10 ) ) {
F_9 ( & V_2 -> V_7 . V_10 ) ;
F_5 ( & V_2 -> V_203 -> V_10 ) ;
F_5 ( & V_2 -> V_7 . V_10 ) ;
}
V_187 = F_98 ( V_34 , V_2 , V_109 , 1 ) ;
F_9 ( & V_2 -> V_203 -> V_10 ) ;
}
return V_187 ;
}
static int F_107 ( struct V_193 * V_34 ,
struct V_1 * V_2 ,
int V_109 )
{
int V_187 ;
F_11 ( V_2 ) ;
V_187 = F_103 ( V_34 , V_2 , V_109 ) ;
F_13 ( V_2 ) ;
return V_187 ;
}
static int F_108 ( struct V_193 * V_34 ,
struct V_1 * V_2 ,
int V_109 )
{
int V_187 ;
F_109 ( & V_5 ) ;
if ( F_104 ( V_2 ) )
V_187 = F_98 ( V_34 , V_2 , V_109 , 0 ) ;
else
V_187 = F_102 ( V_34 , V_2 , V_109 ) ;
F_8 ( & V_5 ) ;
return V_187 ;
}
static int F_110 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_15 -> V_110 -> V_109 != V_119 )
return - V_120 ;
if ( V_2 -> V_22 == V_158 &&
! F_111 ( V_2 ) )
return - V_204 ;
V_15 -> V_192 = false ;
V_15 -> V_191 = V_2 ;
return 0 ;
}
static int F_112 ( struct V_1 * V_2 , int V_109 )
{
if ( V_2 -> V_15 -> V_191 != V_2 )
return 0 ;
return V_2 -> V_34 -> V_205 ( V_2 , V_206 ) ;
}
static void F_113 ( struct V_1 * V_2 , int V_109 )
{
if ( V_2 -> V_15 -> V_191 == V_2 )
V_2 -> V_34 -> V_205 ( V_2 , V_207 ) ;
}
static void F_114 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
F_97 ( V_2 ) ;
V_15 -> V_208 = V_209 ;
V_15 -> V_210 = ( V_15 -> V_131 * V_211 ) /
V_15 -> V_107 ;
V_15 -> V_110 -> V_109 = V_109 ;
if ( V_2 -> V_22 == V_158 &&
V_15 -> V_147 > 0 )
F_82 ( V_2 , V_159 ) ;
F_57 ( V_2 , V_212 ) ;
}
int F_115 ( struct V_1 * V_2 )
{
return F_103 ( & V_213 , V_2 ,
V_180 ) ;
}
static int F_116 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_15 -> V_110 -> V_109 == V_117 )
return - V_120 ;
V_15 -> V_191 = V_2 ;
return 0 ;
}
static int F_117 ( struct V_1 * V_2 , int V_109 )
{
if ( V_2 -> V_15 -> V_191 == V_2 &&
F_81 ( V_2 ) )
V_2 -> V_34 -> V_205 ( V_2 , V_207 ) ;
return 0 ;
}
static void F_118 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_15 -> V_110 -> V_109 != V_109 ) {
F_97 ( V_2 ) ;
V_15 -> V_110 -> V_109 = V_109 ;
F_57 ( V_2 , V_214 ) ;
}
F_119 ( & V_15 -> V_215 ) ;
F_119 ( & V_15 -> V_216 ) ;
}
int F_120 ( struct V_1 * V_2 , T_4 V_109 )
{
return F_103 ( & V_217 , V_2 , V_109 ) ;
}
int F_121 ( struct V_1 * V_2 )
{
return F_102 ( & V_217 , V_2 ,
V_118 ) ;
}
int F_122 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
int V_218 = 0 ;
F_123 ( V_2 , V_11 ) ;
if ( F_81 ( V_2 ) )
V_218 = F_120 ( V_2 , V_219 ) ;
F_17 ( V_2 , V_11 ) ;
return V_218 ;
}
static int F_124 ( struct V_1 * V_2 , int V_220 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( ! ( V_15 -> V_13 & V_221 ) )
return - V_222 ;
if ( V_220 ) {
if ( V_15 -> V_110 -> V_109 != V_180 )
return - V_120 ;
} else if ( V_15 -> V_110 -> V_109 != V_223 )
return - V_120 ;
V_15 -> V_191 = V_2 ;
return 0 ;
}
static int F_125 ( struct V_1 * V_2 , int V_220 )
{
if ( V_2 -> V_15 -> V_191 != V_2 )
return 0 ;
if ( V_220 )
F_88 ( V_2 ) ;
V_2 -> V_15 -> V_208 = V_209 - V_211 * 1000 ;
return V_2 -> V_34 -> V_205 ( V_2 ,
V_220 ? V_224 :
V_225 ) ;
}
static void F_126 ( struct V_1 * V_2 , int V_220 )
{
if ( V_2 -> V_15 -> V_191 == V_2 )
V_2 -> V_34 -> V_205 ( V_2 ,
V_220 ? V_225 :
V_224 ) ;
}
static void F_127 ( struct V_1 * V_2 , int V_220 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
F_97 ( V_2 ) ;
if ( V_220 ) {
V_15 -> V_110 -> V_109 = V_223 ;
F_57 ( V_2 , V_226 ) ;
F_119 ( & V_15 -> V_215 ) ;
F_119 ( & V_15 -> V_216 ) ;
} else {
V_15 -> V_110 -> V_109 = V_180 ;
F_57 ( V_2 , V_227 ) ;
}
}
static int F_128 ( struct V_1 * V_2 , int V_220 )
{
return F_103 ( & V_228 , V_2 , V_220 ) ;
}
static int F_129 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_15 -> V_110 -> V_109 == V_229 )
return - V_230 ;
V_15 -> V_191 = V_2 ;
return 0 ;
}
static int F_130 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_15 -> V_191 != V_2 )
return 0 ;
if ( ! F_81 ( V_2 ) )
return 0 ;
V_2 -> V_34 -> V_205 ( V_2 , V_231 ) ;
return 0 ;
}
static void F_131 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
F_97 ( V_2 ) ;
V_15 -> V_110 -> V_169 = V_15 -> V_110 -> V_109 ;
V_15 -> V_110 -> V_109 = V_229 ;
F_57 ( V_2 , V_232 ) ;
F_119 ( & V_15 -> V_215 ) ;
F_119 ( & V_15 -> V_216 ) ;
}
int F_132 ( struct V_1 * V_2 )
{
int V_38 ;
unsigned long V_11 ;
if ( ! V_2 )
return 0 ;
F_123 ( V_2 , V_11 ) ;
V_38 = F_103 ( & V_233 , V_2 , 0 ) ;
F_17 ( V_2 , V_11 ) ;
return V_38 ;
}
int F_133 ( struct V_16 * V_3 )
{
struct V_1 * V_2 ;
int V_22 , V_38 = 0 ;
if ( ! V_3 )
return 0 ;
for ( V_22 = 0 ; V_22 < 2 ; V_22 ++ ) {
for ( V_2 = V_3 -> V_234 [ V_22 ] . V_2 ;
V_2 ; V_2 = V_2 -> V_235 ) {
if ( V_2 -> V_15 == NULL )
continue;
V_38 = F_132 ( V_2 ) ;
if ( V_38 < 0 && V_38 != - V_230 )
return V_38 ;
}
}
return 0 ;
}
static int F_134 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( ! ( V_15 -> V_13 & V_236 ) )
return - V_222 ;
V_15 -> V_191 = V_2 ;
return 0 ;
}
static int F_135 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_15 -> V_191 != V_2 )
return 0 ;
if ( V_15 -> V_110 -> V_169 != V_180 &&
( V_15 -> V_110 -> V_169 != V_181 ||
V_2 -> V_22 != V_158 ) )
return 0 ;
return V_2 -> V_34 -> V_205 ( V_2 , V_237 ) ;
}
static void F_136 ( struct V_1 * V_2 , int V_109 )
{
if ( V_2 -> V_15 -> V_191 == V_2 &&
F_81 ( V_2 ) )
V_2 -> V_34 -> V_205 ( V_2 , V_231 ) ;
}
static void F_137 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
F_97 ( V_2 ) ;
V_15 -> V_110 -> V_109 = V_15 -> V_110 -> V_169 ;
F_57 ( V_2 , V_238 ) ;
}
static int F_138 ( struct V_1 * V_2 )
{
struct V_239 * V_19 = V_2 -> V_3 -> V_19 ;
int V_187 ;
F_139 ( V_19 ) ;
if ( ( V_187 = F_140 ( V_19 , V_240 ) ) >= 0 )
V_187 = F_107 ( & V_241 , V_2 , 0 ) ;
F_141 ( V_19 ) ;
return V_187 ;
}
static int F_138 ( struct V_1 * V_2 )
{
return - V_222 ;
}
static int F_142 ( struct V_1 * V_2 )
{
struct V_239 * V_19 = V_2 -> V_3 -> V_19 ;
struct V_14 * V_15 = V_2 -> V_15 ;
int V_153 ;
F_139 ( V_19 ) ;
if ( V_15 -> V_110 -> V_109 == V_229 ) {
V_153 = F_140 ( V_19 , V_240 ) ;
if ( V_153 < 0 )
goto V_199;
}
F_11 ( V_2 ) ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_219 :
V_153 = 0 ;
break;
case V_180 :
V_153 = F_120 ( V_2 , V_219 ) ;
break;
default:
V_153 = - V_120 ;
}
F_13 ( V_2 ) ;
V_199:
F_141 ( V_19 ) ;
return V_153 ;
}
static int F_143 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_180 :
case V_119 :
case V_223 :
case V_229 :
return 0 ;
default:
return - V_120 ;
}
}
static int F_144 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
int V_38 = V_2 -> V_34 -> V_35 ( V_2 , V_242 , NULL ) ;
if ( V_38 < 0 )
return V_38 ;
V_15 -> V_243 = 0 ;
V_15 -> V_244 = V_15 -> V_110 -> V_178 -
V_15 -> V_110 -> V_178 % V_15 -> V_108 ;
V_15 -> V_245 = V_15 -> V_110 -> V_178 ;
V_15 -> V_246 = 0 ;
return 0 ;
}
static void F_145 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
V_15 -> V_142 -> V_177 = V_15 -> V_110 -> V_178 ;
if ( V_2 -> V_22 == V_158 &&
V_15 -> V_147 > 0 )
F_82 ( V_2 , V_159 ) ;
}
static int F_146 ( struct V_1 * V_2 )
{
return F_108 ( & V_247 , V_2 , 0 ) ;
}
static int F_147 ( struct V_1 * V_2 ,
int V_248 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_15 -> V_110 -> V_109 == V_117 ||
V_15 -> V_110 -> V_109 == V_111 )
return - V_120 ;
if ( F_81 ( V_2 ) )
return - V_230 ;
V_2 -> V_248 = V_248 ;
return 0 ;
}
static int F_148 ( struct V_1 * V_2 , int V_109 )
{
int V_38 ;
V_38 = V_2 -> V_34 -> V_249 ( V_2 ) ;
if ( V_38 < 0 )
return V_38 ;
return F_144 ( V_2 , 0 ) ;
}
static void F_149 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
V_15 -> V_142 -> V_177 = V_15 -> V_110 -> V_178 ;
F_56 ( V_2 , V_119 ) ;
}
static int F_150 ( struct V_1 * V_2 ,
struct V_250 * V_250 )
{
int V_187 ;
struct V_239 * V_19 = V_2 -> V_3 -> V_19 ;
int V_248 ;
if ( V_250 )
V_248 = V_250 -> V_248 ;
else
V_248 = V_2 -> V_248 ;
F_139 ( V_19 ) ;
if ( ( V_187 = F_140 ( V_19 , V_240 ) ) >= 0 )
V_187 = F_108 ( & V_251 ,
V_2 , V_248 ) ;
F_141 ( V_19 ) ;
return V_187 ;
}
static int F_151 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_117 :
case V_111 :
case V_229 :
return - V_120 ;
}
V_15 -> V_191 = V_2 ;
return 0 ;
}
static int F_152 ( struct V_1 * V_2 , int V_109 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_22 == V_158 ) {
switch ( V_15 -> V_110 -> V_109 ) {
case V_119 :
if ( ! F_153 ( V_2 ) ) {
F_112 ( V_2 , V_181 ) ;
F_114 ( V_2 , V_181 ) ;
} else {
V_15 -> V_110 -> V_109 = V_118 ;
}
break;
case V_180 :
V_15 -> V_110 -> V_109 = V_181 ;
break;
case V_219 :
V_15 -> V_110 -> V_109 = V_118 ;
break;
default:
break;
}
} else {
if ( V_15 -> V_110 -> V_109 == V_180 ) {
int V_252 = F_92 ( V_15 ) > 0 ?
V_181 : V_118 ;
F_117 ( V_2 , V_252 ) ;
F_118 ( V_2 , V_252 ) ;
}
}
if ( V_15 -> V_110 -> V_109 == V_181 &&
V_15 -> V_191 == V_2 &&
( V_15 -> V_42 . V_13 & V_100 ) )
return V_2 -> V_34 -> V_205 ( V_2 ,
V_253 ) ;
return 0 ;
}
static void F_154 ( struct V_1 * V_2 , int V_109 )
{
}
static int F_155 ( struct V_1 * V_2 ,
struct V_250 * V_250 )
{
struct V_239 * V_19 ;
struct V_14 * V_15 ;
struct V_1 * V_195 ;
T_5 V_254 ;
int V_153 = 0 ;
int V_255 = 0 ;
V_19 = V_2 -> V_3 -> V_19 ;
V_15 = V_2 -> V_15 ;
if ( V_15 -> V_110 -> V_109 == V_117 )
return - V_120 ;
F_139 ( V_19 ) ;
if ( V_15 -> V_110 -> V_109 == V_229 ) {
V_153 = F_140 ( V_19 , V_240 ) ;
if ( V_153 < 0 ) {
F_141 ( V_19 ) ;
return V_153 ;
}
}
if ( V_250 ) {
if ( V_250 -> V_248 & V_256 )
V_255 = 1 ;
} else if ( V_2 -> V_248 & V_256 )
V_255 = 1 ;
F_109 ( & V_5 ) ;
F_11 ( V_2 ) ;
if ( V_15 -> V_110 -> V_109 == V_223 )
F_128 ( V_2 , 0 ) ;
V_153 = F_103 ( & V_257 , V_2 , 0 ) ;
if ( V_153 < 0 )
goto V_258;
if ( V_255 ) {
V_153 = - V_259 ;
goto V_258;
}
for (; ; ) {
long V_260 ;
struct V_14 * V_261 ;
if ( F_156 ( V_262 ) ) {
V_153 = - V_263 ;
break;
}
V_261 = NULL ;
F_99 (s, substream) {
if ( V_195 -> V_22 != V_158 )
continue;
V_15 = V_195 -> V_15 ;
if ( V_15 -> V_110 -> V_109 == V_181 ) {
V_261 = V_15 ;
break;
}
}
if ( ! V_261 )
break;
F_157 ( & V_254 , V_262 ) ;
F_158 ( & V_261 -> V_215 , & V_254 ) ;
F_13 ( V_2 ) ;
F_8 ( & V_5 ) ;
F_141 ( V_19 ) ;
if ( V_15 -> V_132 )
V_260 = V_264 ;
else {
V_260 = 10 ;
if ( V_15 -> V_107 ) {
long V_265 = V_15 -> V_108 * 2 / V_15 -> V_107 ;
V_260 = V_88 ( V_265 , V_260 ) ;
}
V_260 = F_159 ( V_260 * 1000 ) ;
}
V_260 = F_160 ( V_260 ) ;
F_139 ( V_19 ) ;
F_109 ( & V_5 ) ;
F_11 ( V_2 ) ;
F_161 ( & V_261 -> V_215 , & V_254 ) ;
if ( V_19 -> V_266 ) {
V_153 = - V_267 ;
break;
}
if ( V_260 == 0 ) {
if ( V_2 -> V_15 -> V_110 -> V_109 == V_229 )
V_153 = - V_268 ;
else {
F_162 ( V_2 -> V_3 -> V_19 -> V_51 ,
L_12 ) ;
F_120 ( V_2 , V_118 ) ;
V_153 = - V_269 ;
}
break;
}
}
V_258:
F_13 ( V_2 ) ;
F_8 ( & V_5 ) ;
F_141 ( V_19 ) ;
return V_153 ;
}
static int F_163 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
int V_153 = 0 ;
if ( F_60 ( V_2 ) )
return - V_116 ;
V_15 = V_2 -> V_15 ;
if ( V_15 -> V_110 -> V_109 == V_117 ||
V_15 -> V_110 -> V_109 == V_111 ||
V_15 -> V_110 -> V_109 == V_229 )
return - V_120 ;
F_11 ( V_2 ) ;
if ( V_15 -> V_110 -> V_109 == V_223 )
F_128 ( V_2 , 0 ) ;
F_120 ( V_2 , V_118 ) ;
F_13 ( V_2 ) ;
return V_153 ;
}
static bool F_164 ( struct V_250 * V_250 )
{
struct V_270 * V_270 = F_165 ( V_250 ) ;
unsigned int V_271 ;
if ( ! F_166 ( V_270 -> V_272 ) || F_167 ( V_270 ) != V_273 )
return false ;
V_271 = F_168 ( V_270 ) ;
return F_169 ( V_271 , V_274 ) ||
F_169 ( V_271 , V_275 ) ;
}
static int F_170 ( struct V_1 * V_2 , int V_276 )
{
int V_187 = 0 ;
struct V_277 * V_278 ;
struct V_1 * V_279 ;
struct V_280 * V_203 ;
struct V_276 V_281 = F_171 ( V_276 ) ;
if ( ! V_281 . V_250 )
return - V_120 ;
if ( ! F_164 ( V_281 . V_250 ) ) {
V_187 = - V_120 ;
goto V_282;
}
V_278 = V_281 . V_250 -> V_283 ;
V_279 = V_278 -> V_2 ;
V_203 = F_27 ( sizeof( * V_203 ) , V_39 ) ;
if ( ! V_203 ) {
V_187 = - V_40 ;
goto V_284;
}
F_172 ( & V_5 ) ;
F_173 ( & V_9 ) ;
if ( V_2 -> V_15 -> V_110 -> V_109 == V_117 ||
V_2 -> V_15 -> V_110 -> V_109 != V_279 -> V_15 -> V_110 -> V_109 ||
V_2 -> V_3 -> V_4 != V_279 -> V_3 -> V_4 ) {
V_187 = - V_120 ;
goto V_170;
}
if ( F_104 ( V_279 ) ) {
V_187 = - V_285 ;
goto V_170;
}
if ( ! F_104 ( V_2 ) ) {
V_2 -> V_203 = V_203 ;
V_203 = NULL ;
F_174 ( & V_2 -> V_203 -> V_10 ) ;
F_175 ( & V_2 -> V_203 -> V_8 ) ;
F_176 ( & V_2 -> V_203 -> V_286 ) ;
F_177 ( & V_2 -> V_287 , & V_2 -> V_203 -> V_286 ) ;
V_2 -> V_203 -> V_288 = 1 ;
}
F_177 ( & V_279 -> V_287 , & V_2 -> V_203 -> V_286 ) ;
V_2 -> V_203 -> V_288 ++ ;
V_279 -> V_203 = V_2 -> V_203 ;
V_170:
F_178 ( & V_9 ) ;
F_179 ( & V_5 ) ;
V_284:
F_180 ( V_279 -> V_3 -> V_19 ) ;
F_29 ( V_203 ) ;
V_282:
F_181 ( V_281 ) ;
return V_187 ;
}
static void F_182 ( struct V_1 * V_2 )
{
V_2 -> V_203 = & V_2 -> V_7 ;
F_176 ( & V_2 -> V_7 . V_286 ) ;
F_177 ( & V_2 -> V_287 , & V_2 -> V_7 . V_286 ) ;
}
static int F_183 ( struct V_1 * V_2 )
{
struct V_1 * V_195 ;
int V_187 = 0 ;
F_172 ( & V_5 ) ;
F_173 ( & V_9 ) ;
if ( ! F_104 ( V_2 ) ) {
V_187 = - V_285 ;
goto V_170;
}
F_184 ( & V_2 -> V_287 ) ;
V_2 -> V_203 -> V_288 -- ;
if ( V_2 -> V_203 -> V_288 == 1 ) {
F_99 (s, substream) {
F_182 ( V_195 ) ;
break;
}
F_29 ( V_2 -> V_203 ) ;
}
F_182 ( V_2 ) ;
V_170:
F_178 ( & V_9 ) ;
F_179 ( & V_5 ) ;
return V_187 ;
}
static int F_185 ( struct V_53 * V_54 ,
struct V_90 * V_289 )
{
struct V_57 V_265 ;
F_186 ( F_187 ( V_54 , V_289 -> V_96 [ 0 ] ) ,
F_187 ( V_54 , V_289 -> V_96 [ 1 ] ) , & V_265 ) ;
return F_42 ( F_40 ( V_54 , V_289 -> V_98 ) , & V_265 ) ;
}
static int F_188 ( struct V_53 * V_54 ,
struct V_90 * V_289 )
{
struct V_57 V_265 ;
F_189 ( F_187 ( V_54 , V_289 -> V_96 [ 0 ] ) ,
F_187 ( V_54 , V_289 -> V_96 [ 1 ] ) , & V_265 ) ;
return F_42 ( F_40 ( V_54 , V_289 -> V_98 ) , & V_265 ) ;
}
static int F_190 ( struct V_53 * V_54 ,
struct V_90 * V_289 )
{
struct V_57 V_265 ;
F_191 ( F_187 ( V_54 , V_289 -> V_96 [ 0 ] ) ,
F_187 ( V_54 , V_289 -> V_96 [ 1 ] ) ,
( unsigned long ) V_289 -> V_290 , & V_265 ) ;
return F_42 ( F_40 ( V_54 , V_289 -> V_98 ) , & V_265 ) ;
}
static int F_192 ( struct V_53 * V_54 ,
struct V_90 * V_289 )
{
struct V_57 V_265 ;
F_193 ( F_187 ( V_54 , V_289 -> V_96 [ 0 ] ) ,
( unsigned long ) V_289 -> V_290 ,
F_187 ( V_54 , V_289 -> V_96 [ 1 ] ) , & V_265 ) ;
return F_42 ( F_40 ( V_54 , V_289 -> V_98 ) , & V_265 ) ;
}
static int F_194 ( struct V_53 * V_54 ,
struct V_90 * V_289 )
{
unsigned int V_55 ;
struct V_57 * V_58 = F_40 ( V_54 , V_289 -> V_96 [ 0 ] ) ;
struct V_59 V_60 ;
struct V_59 * V_291 = F_33 ( V_54 , V_102 ) ;
F_195 ( & V_60 ) ;
for ( V_55 = 0 ; V_55 <= V_292 ; ++ V_55 ) {
int V_82 ;
if ( ! F_196 ( V_291 , V_55 ) )
continue;
V_82 = F_72 ( V_55 ) ;
if ( V_82 <= 0 )
continue;
if ( ( unsigned ) V_82 < V_58 -> V_87 || ( unsigned ) V_82 > V_58 -> V_88 )
F_197 ( & V_60 , V_55 ) ;
}
return F_38 ( V_291 , & V_60 ) ;
}
static int F_198 ( struct V_53 * V_54 ,
struct V_90 * V_289 )
{
struct V_57 V_265 ;
unsigned int V_55 ;
V_265 . V_87 = V_293 ;
V_265 . V_88 = 0 ;
V_265 . V_86 = 0 ;
V_265 . V_89 = 0 ;
for ( V_55 = 0 ; V_55 <= V_292 ; ++ V_55 ) {
int V_82 ;
if ( ! F_196 ( F_33 ( V_54 , V_102 ) , V_55 ) )
continue;
V_82 = F_72 ( V_55 ) ;
if ( V_82 <= 0 )
continue;
if ( V_265 . V_87 > ( unsigned ) V_82 )
V_265 . V_87 = V_82 ;
if ( V_265 . V_88 < ( unsigned ) V_82 )
V_265 . V_88 = V_82 ;
}
V_265 . integer = 1 ;
return F_42 ( F_40 ( V_54 , V_289 -> V_98 ) , & V_265 ) ;
}
static int F_199 ( struct V_53 * V_54 ,
struct V_90 * V_289 )
{
struct V_56 * V_42 = V_289 -> V_290 ;
return F_200 ( F_40 ( V_54 , V_289 -> V_98 ) ,
V_294 . V_288 ,
V_294 . V_295 , V_42 -> V_296 ) ;
}
static int F_201 ( struct V_53 * V_54 ,
struct V_90 * V_289 )
{
struct V_57 V_265 ;
struct V_1 * V_2 = V_289 -> V_290 ;
V_265 . V_87 = 0 ;
V_265 . V_88 = V_2 -> V_297 ;
V_265 . V_86 = 0 ;
V_265 . V_89 = 0 ;
V_265 . integer = 1 ;
return F_42 ( F_40 ( V_54 , V_289 -> V_98 ) , & V_265 ) ;
}
int F_202 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_61 * V_62 = & V_15 -> V_63 ;
int V_55 , V_38 ;
for ( V_55 = V_78 ; V_55 <= V_79 ; V_55 ++ ) {
F_195 ( F_39 ( V_62 , V_55 ) ) ;
}
for ( V_55 = V_84 ; V_55 <= V_67 ; V_55 ++ ) {
F_203 ( F_43 ( V_62 , V_55 ) ) ;
}
F_204 ( F_43 ( V_62 , V_103 ) ) ;
F_204 ( F_43 ( V_62 , V_298 ) ) ;
F_204 ( F_43 ( V_62 , V_299 ) ) ;
F_204 ( F_43 ( V_62 , V_73 ) ) ;
F_204 ( F_43 ( V_62 , V_300 ) ) ;
V_38 = F_205 ( V_15 , 0 , V_102 ,
F_194 , NULL ,
V_73 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_205 ( V_15 , 0 , V_73 ,
F_198 , NULL ,
V_102 ,
V_73 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_205 ( V_15 , 0 , V_73 ,
F_188 , NULL ,
V_300 , V_103 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_205 ( V_15 , 0 , V_300 ,
F_185 , NULL ,
V_73 , V_103 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_205 ( V_15 , 0 , V_300 ,
F_192 , ( void * ) 8 ,
V_301 , V_302 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_205 ( V_15 , 0 , V_300 ,
F_192 , ( void * ) 8 ,
V_299 , V_298 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_205 ( V_15 , 0 , V_103 ,
F_188 , NULL ,
V_300 , V_73 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_205 ( V_15 , 0 , V_75 ,
F_192 , ( void * ) 1000000 ,
V_302 , V_303 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_205 ( V_15 , 0 , V_75 ,
F_192 , ( void * ) 1000000 ,
V_298 , V_304 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_205 ( V_15 , 0 , V_305 ,
F_188 , NULL ,
V_298 , V_302 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_205 ( V_15 , 0 , V_302 ,
F_188 , NULL ,
V_298 , V_305 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_205 ( V_15 , 0 , V_302 ,
F_192 , ( void * ) 8 ,
V_301 , V_300 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_205 ( V_15 , 0 , V_302 ,
F_190 , ( void * ) 1000000 ,
V_303 , V_75 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_205 ( V_15 , 0 , V_298 ,
F_185 , NULL ,
V_302 , V_305 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_205 ( V_15 , 0 , V_298 ,
F_192 , ( void * ) 8 ,
V_299 , V_300 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_205 ( V_15 , 0 , V_298 ,
F_190 , ( void * ) 1000000 ,
V_304 , V_75 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_205 ( V_15 , 0 , V_301 ,
F_190 , ( void * ) 8 ,
V_302 , V_300 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_205 ( V_15 , 0 , V_299 ,
F_190 , ( void * ) 8 ,
V_298 , V_300 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_205 ( V_15 , 0 , V_303 ,
F_192 , ( void * ) 1000000 ,
V_302 , V_75 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_205 ( V_15 , 0 , V_304 ,
F_192 , ( void * ) 1000000 ,
V_298 , V_75 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
return 0 ;
}
int F_206 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_56 * V_42 = & V_15 -> V_42 ;
int V_38 ;
unsigned int V_291 = 0 ;
if ( V_42 -> V_13 & V_306 )
V_291 |= 1 << V_307 ;
if ( V_42 -> V_13 & V_308 )
V_291 |= 1 << V_309 ;
if ( F_30 ( V_2 ) ) {
if ( V_42 -> V_13 & V_306 )
V_291 |= 1 << V_310 ;
if ( V_42 -> V_13 & V_308 )
V_291 |= 1 << V_311 ;
if ( V_42 -> V_13 & V_312 )
V_291 |= 1 << V_313 ;
}
V_38 = F_207 ( V_15 , V_314 , V_291 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_208 ( V_15 , V_102 , V_42 -> V_315 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_207 ( V_15 , V_316 , 1 << V_317 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_209 ( V_15 , V_103 ,
V_42 -> V_318 , V_42 -> V_319 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_209 ( V_15 , V_75 ,
V_42 -> V_320 , V_42 -> V_321 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_209 ( V_15 , V_301 ,
V_42 -> V_322 , V_42 -> V_323 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_209 ( V_15 , V_305 ,
V_42 -> V_324 , V_42 -> V_325 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_209 ( V_15 , V_299 ,
V_42 -> V_322 , V_42 -> V_297 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_205 ( V_15 , 0 , V_299 ,
F_201 , V_2 ,
V_299 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_15 -> V_326 ) {
V_38 = F_209 ( V_15 , V_299 , 0 , V_15 -> V_326 ) ;
if ( V_38 < 0 )
return V_38 ;
}
if ( ! ( V_42 -> V_296 & ( V_327 | V_328 ) ) ) {
V_38 = F_205 ( V_15 , 0 , V_75 ,
F_199 , V_42 ,
V_75 , - 1 ) ;
if ( V_38 < 0 )
return V_38 ;
}
F_210 ( V_15 , V_302 ) ;
return 0 ;
}
static void F_211 ( struct V_1 * V_2 )
{
F_183 ( V_2 ) ;
}
void F_212 ( struct V_1 * V_2 )
{
V_2 -> V_329 -- ;
if ( V_2 -> V_329 > 0 )
return;
F_163 ( V_2 ) ;
if ( V_2 -> V_330 ) {
if ( V_2 -> V_34 -> V_152 &&
V_2 -> V_15 -> V_110 -> V_109 != V_117 )
V_2 -> V_34 -> V_152 ( V_2 ) ;
V_2 -> V_34 -> V_331 ( V_2 ) ;
V_2 -> V_330 = 0 ;
}
if ( F_74 ( & V_2 -> V_150 ) )
F_75 ( & V_2 -> V_150 ) ;
if ( V_2 -> V_332 ) {
V_2 -> V_332 ( V_2 ) ;
V_2 -> V_332 = NULL ;
}
F_213 ( V_2 ) ;
}
int F_214 ( struct V_16 * V_3 , int V_22 ,
struct V_250 * V_250 ,
struct V_1 * * V_333 )
{
struct V_1 * V_2 ;
int V_38 ;
V_38 = F_215 ( V_3 , V_22 , V_250 , & V_2 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_2 -> V_329 > 1 ) {
* V_333 = V_2 ;
return 0 ;
}
V_38 = F_202 ( V_2 ) ;
if ( V_38 < 0 ) {
F_216 ( V_3 , L_13 ) ;
goto error;
}
if ( ( V_38 = V_2 -> V_34 -> V_334 ( V_2 ) ) < 0 )
goto error;
V_2 -> V_330 = 1 ;
V_38 = F_206 ( V_2 ) ;
if ( V_38 < 0 ) {
F_216 ( V_3 , L_14 ) ;
goto error;
}
* V_333 = V_2 ;
return 0 ;
error:
F_212 ( V_2 ) ;
return V_38 ;
}
static int F_217 ( struct V_250 * V_250 ,
struct V_16 * V_3 ,
int V_22 )
{
struct V_277 * V_278 ;
struct V_1 * V_2 ;
int V_38 ;
V_38 = F_214 ( V_3 , V_22 , V_250 , & V_2 ) ;
if ( V_38 < 0 )
return V_38 ;
V_278 = F_218 ( sizeof( * V_278 ) , V_39 ) ;
if ( V_278 == NULL ) {
F_212 ( V_2 ) ;
return - V_40 ;
}
V_278 -> V_2 = V_2 ;
if ( V_2 -> V_329 == 1 ) {
V_2 -> V_250 = V_278 ;
V_2 -> V_332 = F_211 ;
}
V_250 -> V_283 = V_278 ;
return 0 ;
}
static int F_219 ( struct V_270 * V_270 , struct V_250 * V_250 )
{
struct V_16 * V_3 ;
int V_38 = F_220 ( V_270 , V_250 ) ;
if ( V_38 < 0 )
return V_38 ;
V_3 = F_169 ( F_168 ( V_270 ) ,
V_274 ) ;
V_38 = F_221 ( V_250 , V_3 , V_158 ) ;
if ( V_3 )
F_180 ( V_3 -> V_19 ) ;
return V_38 ;
}
static int F_222 ( struct V_270 * V_270 , struct V_250 * V_250 )
{
struct V_16 * V_3 ;
int V_38 = F_220 ( V_270 , V_250 ) ;
if ( V_38 < 0 )
return V_38 ;
V_3 = F_169 ( F_168 ( V_270 ) ,
V_275 ) ;
V_38 = F_221 ( V_250 , V_3 , V_335 ) ;
if ( V_3 )
F_180 ( V_3 -> V_19 ) ;
return V_38 ;
}
static int F_221 ( struct V_250 * V_250 , struct V_16 * V_3 , int V_22 )
{
int V_38 ;
T_5 V_254 ;
if ( V_3 == NULL ) {
V_38 = - V_267 ;
goto V_336;
}
V_38 = F_223 ( V_3 -> V_19 , V_250 ) ;
if ( V_38 < 0 )
goto V_336;
if ( ! F_224 ( V_3 -> V_19 -> V_337 ) ) {
V_38 = - V_41 ;
goto V_338;
}
F_157 ( & V_254 , V_262 ) ;
F_158 ( & V_3 -> V_339 , & V_254 ) ;
F_3 ( & V_3 -> V_340 ) ;
while ( 1 ) {
V_38 = F_217 ( V_250 , V_3 , V_22 ) ;
if ( V_38 >= 0 )
break;
if ( V_38 == - V_259 ) {
if ( V_250 -> V_248 & V_256 ) {
V_38 = - V_230 ;
break;
}
} else
break;
F_225 ( V_341 ) ;
F_7 ( & V_3 -> V_340 ) ;
F_226 () ;
F_3 ( & V_3 -> V_340 ) ;
if ( V_3 -> V_19 -> V_266 ) {
V_38 = - V_267 ;
break;
}
if ( F_156 ( V_262 ) ) {
V_38 = - V_263 ;
break;
}
}
F_161 ( & V_3 -> V_339 , & V_254 ) ;
F_7 ( & V_3 -> V_340 ) ;
if ( V_38 < 0 )
goto V_342;
return V_38 ;
V_342:
F_227 ( V_3 -> V_19 -> V_337 ) ;
V_338:
F_228 ( V_3 -> V_19 , V_250 ) ;
V_336:
return V_38 ;
}
static int F_229 ( struct V_270 * V_270 , struct V_250 * V_250 )
{
struct V_16 * V_3 ;
struct V_1 * V_2 ;
struct V_277 * V_278 ;
V_278 = V_250 -> V_283 ;
V_2 = V_278 -> V_2 ;
if ( F_230 ( ! V_2 ) )
return - V_116 ;
V_3 = V_2 -> V_3 ;
F_3 ( & V_3 -> V_340 ) ;
F_212 ( V_2 ) ;
F_29 ( V_278 ) ;
F_7 ( & V_3 -> V_340 ) ;
F_119 ( & V_3 -> V_339 ) ;
F_227 ( V_3 -> V_19 -> V_337 ) ;
F_228 ( V_3 -> V_19 , V_250 ) ;
return 0 ;
}
static T_6 F_231 ( struct V_1 * V_2 ,
T_3 V_115 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
T_6 V_177 ;
T_6 V_218 ;
T_6 V_343 ;
if ( V_115 == 0 )
return 0 ;
F_11 ( V_2 ) ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_119 :
break;
case V_181 :
case V_180 :
if ( F_88 ( V_2 ) >= 0 )
break;
case V_219 :
V_218 = - V_204 ;
goto V_344;
case V_229 :
V_218 = - V_268 ;
goto V_344;
default:
V_218 = - V_120 ;
goto V_344;
}
V_343 = F_232 ( V_15 ) ;
if ( V_343 <= 0 ) {
V_218 = 0 ;
goto V_344;
}
if ( V_115 > ( T_3 ) V_343 )
V_115 = V_343 ;
V_177 = V_15 -> V_142 -> V_177 - V_115 ;
if ( V_177 < 0 )
V_177 += V_15 -> V_148 ;
V_15 -> V_142 -> V_177 = V_177 ;
V_218 = V_115 ;
V_344:
F_13 ( V_2 ) ;
return V_218 ;
}
static T_6 F_233 ( struct V_1 * V_2 ,
T_3 V_115 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
T_6 V_177 ;
T_6 V_218 ;
T_6 V_343 ;
if ( V_115 == 0 )
return 0 ;
F_11 ( V_2 ) ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_119 :
case V_181 :
break;
case V_180 :
if ( F_88 ( V_2 ) >= 0 )
break;
case V_219 :
V_218 = - V_204 ;
goto V_344;
case V_229 :
V_218 = - V_268 ;
goto V_344;
default:
V_218 = - V_120 ;
goto V_344;
}
V_343 = F_234 ( V_15 ) ;
if ( V_343 <= 0 ) {
V_218 = 0 ;
goto V_344;
}
if ( V_115 > ( T_3 ) V_343 )
V_115 = V_343 ;
V_177 = V_15 -> V_142 -> V_177 - V_115 ;
if ( V_177 < 0 )
V_177 += V_15 -> V_148 ;
V_15 -> V_142 -> V_177 = V_177 ;
V_218 = V_115 ;
V_344:
F_13 ( V_2 ) ;
return V_218 ;
}
static T_6 F_235 ( struct V_1 * V_2 ,
T_3 V_115 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
T_6 V_177 ;
T_6 V_218 ;
T_6 V_179 ;
if ( V_115 == 0 )
return 0 ;
F_11 ( V_2 ) ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_119 :
case V_223 :
break;
case V_181 :
case V_180 :
if ( F_88 ( V_2 ) >= 0 )
break;
case V_219 :
V_218 = - V_204 ;
goto V_344;
case V_229 :
V_218 = - V_268 ;
goto V_344;
default:
V_218 = - V_120 ;
goto V_344;
}
V_179 = F_91 ( V_15 ) ;
if ( V_179 <= 0 ) {
V_218 = 0 ;
goto V_344;
}
if ( V_115 > ( T_3 ) V_179 )
V_115 = V_179 ;
V_177 = V_15 -> V_142 -> V_177 + V_115 ;
if ( V_177 >= ( T_6 ) V_15 -> V_148 )
V_177 -= V_15 -> V_148 ;
V_15 -> V_142 -> V_177 = V_177 ;
V_218 = V_115 ;
V_344:
F_13 ( V_2 ) ;
return V_218 ;
}
static T_6 F_236 ( struct V_1 * V_2 ,
T_3 V_115 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
T_6 V_177 ;
T_6 V_218 ;
T_6 V_179 ;
if ( V_115 == 0 )
return 0 ;
F_11 ( V_2 ) ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_119 :
case V_181 :
case V_223 :
break;
case V_180 :
if ( F_88 ( V_2 ) >= 0 )
break;
case V_219 :
V_218 = - V_204 ;
goto V_344;
case V_229 :
V_218 = - V_268 ;
goto V_344;
default:
V_218 = - V_120 ;
goto V_344;
}
V_179 = F_92 ( V_15 ) ;
if ( V_179 <= 0 ) {
V_218 = 0 ;
goto V_344;
}
if ( V_115 > ( T_3 ) V_179 )
V_115 = V_179 ;
V_177 = V_15 -> V_142 -> V_177 + V_115 ;
if ( V_177 >= ( T_6 ) V_15 -> V_148 )
V_177 -= V_15 -> V_148 ;
V_15 -> V_142 -> V_177 = V_177 ;
V_218 = V_115 ;
V_344:
F_13 ( V_2 ) ;
return V_218 ;
}
static int F_237 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
int V_38 ;
F_11 ( V_2 ) ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_181 :
if ( V_2 -> V_22 == V_335 )
goto V_345;
case V_180 :
if ( ( V_38 = F_88 ( V_2 ) ) < 0 )
break;
case V_119 :
case V_229 :
V_38 = 0 ;
break;
case V_219 :
V_38 = - V_204 ;
break;
default:
V_345:
V_38 = - V_120 ;
break;
}
F_13 ( V_2 ) ;
return V_38 ;
}
static int F_238 ( struct V_1 * V_2 ,
T_6 T_2 * V_187 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
int V_38 ;
T_6 V_346 = 0 ;
F_11 ( V_2 ) ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_181 :
if ( V_2 -> V_22 == V_335 )
goto V_345;
case V_180 :
if ( ( V_38 = F_88 ( V_2 ) ) < 0 )
break;
case V_119 :
case V_229 :
V_38 = 0 ;
if ( V_2 -> V_22 == V_158 )
V_346 = F_232 ( V_15 ) ;
else
V_346 = F_92 ( V_15 ) ;
V_346 += V_15 -> V_182 ;
break;
case V_219 :
V_38 = - V_204 ;
break;
default:
V_345:
V_38 = - V_120 ;
break;
}
F_13 ( V_2 ) ;
if ( ! V_38 )
if ( F_239 ( V_346 , V_187 ) )
V_38 = - V_41 ;
return V_38 ;
}
static int F_240 ( struct V_1 * V_2 ,
struct F_240 T_2 * V_347 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct F_240 V_348 ;
volatile struct V_349 * V_110 ;
volatile struct V_350 * V_142 ;
int V_38 ;
memset ( & V_348 , 0 , sizeof( V_348 ) ) ;
if ( F_94 ( V_348 . V_11 , ( unsigned T_2 * ) & ( V_347 -> V_11 ) ) )
return - V_41 ;
if ( F_85 ( & V_348 . V_351 . V_142 , & ( V_347 -> V_351 . V_142 ) , sizeof( struct V_350 ) ) )
return - V_41 ;
V_110 = V_15 -> V_110 ;
V_142 = V_15 -> V_142 ;
if ( V_348 . V_11 & V_352 ) {
V_38 = F_237 ( V_2 ) ;
if ( V_38 < 0 )
return V_38 ;
}
F_11 ( V_2 ) ;
if ( ! ( V_348 . V_11 & V_353 ) )
V_142 -> V_177 = V_348 . V_351 . V_142 . V_177 ;
else
V_348 . V_351 . V_142 . V_177 = V_142 -> V_177 ;
if ( ! ( V_348 . V_11 & V_354 ) )
V_142 -> V_143 = V_348 . V_351 . V_142 . V_143 ;
else
V_348 . V_351 . V_142 . V_143 = V_142 -> V_143 ;
V_348 . V_195 . V_110 . V_109 = V_110 -> V_109 ;
V_348 . V_195 . V_110 . V_178 = V_110 -> V_178 ;
V_348 . V_195 . V_110 . V_172 = V_110 -> V_172 ;
V_348 . V_195 . V_110 . V_169 = V_110 -> V_169 ;
F_13 ( V_2 ) ;
if ( F_28 ( V_347 , & V_348 , sizeof( V_348 ) ) )
return - V_41 ;
return 0 ;
}
static int F_241 ( struct V_1 * V_2 , int T_2 * V_355 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
int V_356 ;
if ( F_94 ( V_356 , V_355 ) )
return - V_41 ;
if ( V_356 < 0 || V_356 > V_157 )
return - V_80 ;
V_15 -> V_156 = V_356 ;
return 0 ;
}
static int F_242 ( struct V_250 * V_250 ,
struct V_1 * V_2 ,
unsigned int V_357 , void T_2 * V_356 )
{
switch ( V_357 ) {
case V_358 :
return F_239 ( V_359 , ( int T_2 * ) V_356 ) ? - V_41 : 0 ;
case V_360 :
return F_26 ( V_2 , V_356 ) ;
case V_361 :
return 0 ;
case V_362 :
return F_241 ( V_2 , V_356 ) ;
case V_363 :
return F_51 ( V_2 , V_356 ) ;
case V_364 :
return F_77 ( V_2 , V_356 ) ;
case V_365 :
return F_78 ( V_2 ) ;
case V_366 :
return F_84 ( V_2 , V_356 ) ;
case V_367 :
return F_93 ( V_2 , V_356 , false ) ;
case V_368 :
return F_93 ( V_2 , V_356 , true ) ;
case V_369 :
return F_96 ( V_2 , V_356 ) ;
case V_370 :
return F_150 ( V_2 , V_250 ) ;
case V_371 :
return F_146 ( V_2 ) ;
case V_372 :
return F_107 ( & V_213 , V_2 , V_180 ) ;
case V_373 :
return F_170 ( V_2 , ( int ) ( unsigned long ) V_356 ) ;
case V_374 :
return F_183 ( V_2 ) ;
case V_375 :
return F_138 ( V_2 ) ;
case V_376 :
return F_142 ( V_2 ) ;
case V_377 :
return F_237 ( V_2 ) ;
case V_378 :
return F_238 ( V_2 , V_356 ) ;
case V_379 :
return F_240 ( V_2 , V_356 ) ;
#ifdef F_243
case V_380 :
return F_244 ( V_2 , V_356 ) ;
case V_381 :
return F_245 ( V_2 , V_356 ) ;
#endif
case V_382 :
return F_155 ( V_2 , V_250 ) ;
case V_383 :
return F_163 ( V_2 ) ;
case V_384 :
{
int V_187 ;
F_11 ( V_2 ) ;
V_187 = F_128 ( V_2 , ( int ) ( unsigned long ) V_356 ) ;
F_13 ( V_2 ) ;
return V_187 ;
}
}
F_216 ( V_2 -> V_3 , L_15 , V_357 ) ;
return - V_385 ;
}
static int F_246 ( struct V_250 * V_250 ,
struct V_1 * V_2 ,
unsigned int V_357 , void T_2 * V_356 )
{
if ( F_230 ( ! V_2 ) )
return - V_116 ;
if ( F_230 ( V_2 -> V_22 != V_158 ) )
return - V_80 ;
switch ( V_357 ) {
case V_386 :
{
struct V_387 V_388 ;
struct V_387 T_2 * V_389 = V_356 ;
struct V_14 * V_15 = V_2 -> V_15 ;
T_6 V_153 ;
if ( V_15 -> V_110 -> V_109 == V_117 )
return - V_120 ;
if ( F_239 ( 0 , & V_389 -> V_153 ) )
return - V_41 ;
if ( F_85 ( & V_388 , V_389 , sizeof( V_388 ) ) )
return - V_41 ;
V_153 = F_247 ( V_2 , V_388 . V_390 , V_388 . V_115 ) ;
F_248 ( V_153 , & V_389 -> V_153 ) ;
return V_153 < 0 ? V_153 : 0 ;
}
case V_391 :
{
struct V_392 V_393 ;
struct V_392 T_2 * V_394 = V_356 ;
struct V_14 * V_15 = V_2 -> V_15 ;
void T_2 * * V_395 ;
T_6 V_153 ;
if ( V_15 -> V_110 -> V_109 == V_117 )
return - V_120 ;
if ( V_15 -> V_129 > 128 )
return - V_80 ;
if ( F_239 ( 0 , & V_394 -> V_153 ) )
return - V_41 ;
if ( F_85 ( & V_393 , V_394 , sizeof( V_393 ) ) )
return - V_41 ;
V_395 = F_52 ( V_393 . V_395 ,
sizeof( void * ) * V_15 -> V_129 ) ;
if ( F_53 ( V_395 ) )
return F_54 ( V_395 ) ;
V_153 = F_249 ( V_2 , V_395 , V_393 . V_115 ) ;
F_29 ( V_395 ) ;
F_248 ( V_153 , & V_394 -> V_153 ) ;
return V_153 < 0 ? V_153 : 0 ;
}
case V_396 :
{
T_3 V_115 ;
T_3 T_2 * V_397 = V_356 ;
T_6 V_153 ;
if ( F_94 ( V_115 , V_397 ) )
return - V_41 ;
if ( F_239 ( 0 , V_397 ) )
return - V_41 ;
V_153 = F_231 ( V_2 , V_115 ) ;
F_248 ( V_153 , V_397 ) ;
return V_153 < 0 ? V_153 : 0 ;
}
case V_398 :
{
T_3 V_115 ;
T_3 T_2 * V_397 = V_356 ;
T_6 V_153 ;
if ( F_94 ( V_115 , V_397 ) )
return - V_41 ;
if ( F_239 ( 0 , V_397 ) )
return - V_41 ;
V_153 = F_235 ( V_2 , V_115 ) ;
F_248 ( V_153 , V_397 ) ;
return V_153 < 0 ? V_153 : 0 ;
}
}
return F_242 ( V_250 , V_2 , V_357 , V_356 ) ;
}
static int F_250 ( struct V_250 * V_250 ,
struct V_1 * V_2 ,
unsigned int V_357 , void T_2 * V_356 )
{
if ( F_230 ( ! V_2 ) )
return - V_116 ;
if ( F_230 ( V_2 -> V_22 != V_335 ) )
return - V_80 ;
switch ( V_357 ) {
case V_399 :
{
struct V_387 V_388 ;
struct V_387 T_2 * V_389 = V_356 ;
struct V_14 * V_15 = V_2 -> V_15 ;
T_6 V_153 ;
if ( V_15 -> V_110 -> V_109 == V_117 )
return - V_120 ;
if ( F_239 ( 0 , & V_389 -> V_153 ) )
return - V_41 ;
if ( F_85 ( & V_388 , V_389 , sizeof( V_388 ) ) )
return - V_41 ;
V_153 = F_251 ( V_2 , V_388 . V_390 , V_388 . V_115 ) ;
F_248 ( V_153 , & V_389 -> V_153 ) ;
return V_153 < 0 ? V_153 : 0 ;
}
case V_400 :
{
struct V_392 V_393 ;
struct V_392 T_2 * V_394 = V_356 ;
struct V_14 * V_15 = V_2 -> V_15 ;
void * V_395 ;
T_6 V_153 ;
if ( V_15 -> V_110 -> V_109 == V_117 )
return - V_120 ;
if ( V_15 -> V_129 > 128 )
return - V_80 ;
if ( F_239 ( 0 , & V_394 -> V_153 ) )
return - V_41 ;
if ( F_85 ( & V_393 , V_394 , sizeof( V_393 ) ) )
return - V_41 ;
V_395 = F_52 ( V_393 . V_395 ,
sizeof( void * ) * V_15 -> V_129 ) ;
if ( F_53 ( V_395 ) )
return F_54 ( V_395 ) ;
V_153 = F_252 ( V_2 , V_395 , V_393 . V_115 ) ;
F_29 ( V_395 ) ;
F_248 ( V_153 , & V_394 -> V_153 ) ;
return V_153 < 0 ? V_153 : 0 ;
}
case V_396 :
{
T_3 V_115 ;
T_3 T_2 * V_397 = V_356 ;
T_6 V_153 ;
if ( F_94 ( V_115 , V_397 ) )
return - V_41 ;
if ( F_239 ( 0 , V_397 ) )
return - V_41 ;
V_153 = F_233 ( V_2 , V_115 ) ;
F_248 ( V_153 , V_397 ) ;
return V_153 < 0 ? V_153 : 0 ;
}
case V_398 :
{
T_3 V_115 ;
T_3 T_2 * V_397 = V_356 ;
T_6 V_153 ;
if ( F_94 ( V_115 , V_397 ) )
return - V_41 ;
if ( F_239 ( 0 , V_397 ) )
return - V_41 ;
V_153 = F_236 ( V_2 , V_115 ) ;
F_248 ( V_153 , V_397 ) ;
return V_153 < 0 ? V_153 : 0 ;
}
}
return F_242 ( V_250 , V_2 , V_357 , V_356 ) ;
}
static long F_253 ( struct V_250 * V_250 , unsigned int V_357 ,
unsigned long V_356 )
{
struct V_277 * V_278 ;
V_278 = V_250 -> V_283 ;
if ( ( ( V_357 >> 8 ) & 0xff ) != 'A' )
return - V_385 ;
return F_246 ( V_250 , V_278 -> V_2 , V_357 ,
( void T_2 * ) V_356 ) ;
}
static long F_254 ( struct V_250 * V_250 , unsigned int V_357 ,
unsigned long V_356 )
{
struct V_277 * V_278 ;
V_278 = V_250 -> V_283 ;
if ( ( ( V_357 >> 8 ) & 0xff ) != 'A' )
return - V_385 ;
return F_250 ( V_250 , V_278 -> V_2 , V_357 ,
( void T_2 * ) V_356 ) ;
}
int F_255 ( struct V_1 * V_2 ,
unsigned int V_357 , void * V_356 )
{
T_1 V_12 ;
int V_153 ;
V_12 = F_19 () ;
switch ( V_2 -> V_22 ) {
case V_158 :
V_153 = F_246 ( NULL , V_2 , V_357 ,
( void T_2 * ) V_356 ) ;
break;
case V_335 :
V_153 = F_250 ( NULL , V_2 , V_357 ,
( void T_2 * ) V_356 ) ;
break;
default:
V_153 = - V_80 ;
break;
}
F_23 ( V_12 ) ;
return V_153 ;
}
static T_7 F_256 ( struct V_250 * V_250 , char T_2 * V_390 , T_8 V_288 ,
T_9 * V_401 )
{
struct V_277 * V_278 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
T_6 V_153 ;
V_278 = V_250 -> V_283 ;
V_2 = V_278 -> V_2 ;
if ( F_60 ( V_2 ) )
return - V_116 ;
V_15 = V_2 -> V_15 ;
if ( V_15 -> V_110 -> V_109 == V_117 )
return - V_120 ;
if ( ! F_257 ( V_15 , V_288 ) )
return - V_80 ;
V_288 = F_258 ( V_15 , V_288 ) ;
V_153 = F_251 ( V_2 , V_390 , V_288 ) ;
if ( V_153 > 0 )
V_153 = F_259 ( V_15 , V_153 ) ;
return V_153 ;
}
static T_7 F_260 ( struct V_250 * V_250 , const char T_2 * V_390 ,
T_8 V_288 , T_9 * V_401 )
{
struct V_277 * V_278 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
T_6 V_153 ;
V_278 = V_250 -> V_283 ;
V_2 = V_278 -> V_2 ;
if ( F_60 ( V_2 ) )
return - V_116 ;
V_15 = V_2 -> V_15 ;
if ( V_15 -> V_110 -> V_109 == V_117 )
return - V_120 ;
if ( ! F_257 ( V_15 , V_288 ) )
return - V_80 ;
V_288 = F_258 ( V_15 , V_288 ) ;
V_153 = F_247 ( V_2 , V_390 , V_288 ) ;
if ( V_153 > 0 )
V_153 = F_259 ( V_15 , V_153 ) ;
return V_153 ;
}
static T_7 F_261 ( struct V_402 * V_403 , struct V_404 * V_405 )
{
struct V_277 * V_278 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
T_6 V_153 ;
unsigned long V_58 ;
void T_2 * * V_395 ;
T_3 V_115 ;
V_278 = V_403 -> V_406 -> V_283 ;
V_2 = V_278 -> V_2 ;
if ( F_60 ( V_2 ) )
return - V_116 ;
V_15 = V_2 -> V_15 ;
if ( V_15 -> V_110 -> V_109 == V_117 )
return - V_120 ;
if ( ! F_262 ( V_405 ) )
return - V_80 ;
if ( V_405 -> V_407 > 1024 || V_405 -> V_407 != V_15 -> V_129 )
return - V_80 ;
if ( ! F_257 ( V_15 , V_405 -> V_408 -> V_409 ) )
return - V_80 ;
V_115 = F_263 ( V_15 , V_405 -> V_408 -> V_409 ) ;
V_395 = F_27 ( sizeof( void * ) * V_405 -> V_407 , V_39 ) ;
if ( V_395 == NULL )
return - V_40 ;
for ( V_58 = 0 ; V_58 < V_405 -> V_407 ; ++ V_58 )
V_395 [ V_58 ] = V_405 -> V_408 [ V_58 ] . V_410 ;
V_153 = F_252 ( V_2 , V_395 , V_115 ) ;
if ( V_153 > 0 )
V_153 = F_259 ( V_15 , V_153 ) ;
F_29 ( V_395 ) ;
return V_153 ;
}
static T_7 F_264 ( struct V_402 * V_403 , struct V_404 * V_411 )
{
struct V_277 * V_278 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
T_6 V_153 ;
unsigned long V_58 ;
void T_2 * * V_395 ;
T_3 V_115 ;
V_278 = V_403 -> V_406 -> V_283 ;
V_2 = V_278 -> V_2 ;
if ( F_60 ( V_2 ) )
return - V_116 ;
V_15 = V_2 -> V_15 ;
if ( V_15 -> V_110 -> V_109 == V_117 )
return - V_120 ;
if ( ! F_262 ( V_411 ) )
return - V_80 ;
if ( V_411 -> V_407 > 128 || V_411 -> V_407 != V_15 -> V_129 ||
! F_257 ( V_15 , V_411 -> V_408 -> V_409 ) )
return - V_80 ;
V_115 = F_263 ( V_15 , V_411 -> V_408 -> V_409 ) ;
V_395 = F_27 ( sizeof( void * ) * V_411 -> V_407 , V_39 ) ;
if ( V_395 == NULL )
return - V_40 ;
for ( V_58 = 0 ; V_58 < V_411 -> V_407 ; ++ V_58 )
V_395 [ V_58 ] = V_411 -> V_408 [ V_58 ] . V_410 ;
V_153 = F_249 ( V_2 , V_395 , V_115 ) ;
if ( V_153 > 0 )
V_153 = F_259 ( V_15 , V_153 ) ;
F_29 ( V_395 ) ;
return V_153 ;
}
static unsigned int F_265 ( struct V_250 * V_250 , T_10 * V_254 )
{
struct V_277 * V_278 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
unsigned int V_291 ;
T_3 V_179 ;
V_278 = V_250 -> V_283 ;
V_2 = V_278 -> V_2 ;
if ( F_60 ( V_2 ) )
return - V_116 ;
V_15 = V_2 -> V_15 ;
F_266 ( V_250 , & V_15 -> V_215 , V_254 ) ;
F_11 ( V_2 ) ;
V_179 = F_91 ( V_15 ) ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_180 :
case V_119 :
case V_223 :
if ( V_179 >= V_15 -> V_142 -> V_143 ) {
V_291 = V_412 | V_413 ;
break;
}
case V_181 :
V_291 = 0 ;
break;
default:
V_291 = V_412 | V_413 | V_414 ;
break;
}
F_13 ( V_2 ) ;
return V_291 ;
}
static unsigned int F_267 ( struct V_250 * V_250 , T_10 * V_254 )
{
struct V_277 * V_278 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
unsigned int V_291 ;
T_3 V_179 ;
V_278 = V_250 -> V_283 ;
V_2 = V_278 -> V_2 ;
if ( F_60 ( V_2 ) )
return - V_116 ;
V_15 = V_2 -> V_15 ;
F_266 ( V_250 , & V_15 -> V_215 , V_254 ) ;
F_11 ( V_2 ) ;
V_179 = F_92 ( V_15 ) ;
switch ( V_15 -> V_110 -> V_109 ) {
case V_180 :
case V_119 :
case V_223 :
if ( V_179 >= V_15 -> V_142 -> V_143 ) {
V_291 = V_415 | V_416 ;
break;
}
V_291 = 0 ;
break;
case V_181 :
if ( V_179 > 0 ) {
V_291 = V_415 | V_416 ;
break;
}
default:
V_291 = V_415 | V_416 | V_414 ;
break;
}
F_13 ( V_2 ) ;
return V_291 ;
}
static int F_268 ( struct V_417 * V_418 ,
struct V_419 * V_420 )
{
struct V_1 * V_2 = V_418 -> V_421 ;
struct V_14 * V_15 ;
if ( V_2 == NULL )
return V_422 ;
V_15 = V_2 -> V_15 ;
V_420 -> V_423 = F_269 ( V_15 -> V_110 ) ;
F_270 ( V_420 -> V_423 ) ;
return 0 ;
}
static int V_349 ( struct V_1 * V_2 , struct V_250 * V_250 ,
struct V_417 * V_418 )
{
long V_424 ;
if ( ! ( V_418 -> V_425 & V_426 ) )
return - V_80 ;
V_424 = V_418 -> V_427 - V_418 -> V_428 ;
if ( V_424 != F_271 ( sizeof( struct V_349 ) ) )
return - V_80 ;
V_418 -> V_429 = & V_430 ;
V_418 -> V_421 = V_2 ;
V_418 -> V_425 |= V_431 | V_432 ;
return 0 ;
}
static int F_272 ( struct V_417 * V_418 ,
struct V_419 * V_420 )
{
struct V_1 * V_2 = V_418 -> V_421 ;
struct V_14 * V_15 ;
if ( V_2 == NULL )
return V_422 ;
V_15 = V_2 -> V_15 ;
V_420 -> V_423 = F_269 ( V_15 -> V_142 ) ;
F_270 ( V_420 -> V_423 ) ;
return 0 ;
}
static int V_350 ( struct V_1 * V_2 , struct V_250 * V_250 ,
struct V_417 * V_418 )
{
long V_424 ;
if ( ! ( V_418 -> V_425 & V_426 ) )
return - V_80 ;
V_424 = V_418 -> V_427 - V_418 -> V_428 ;
if ( V_424 != F_271 ( sizeof( struct V_350 ) ) )
return - V_80 ;
V_418 -> V_429 = & V_433 ;
V_418 -> V_421 = V_2 ;
V_418 -> V_425 |= V_431 | V_432 ;
return 0 ;
}
static int V_349 ( struct V_1 * V_2 , struct V_250 * V_250 ,
struct V_417 * V_418 )
{
return - V_116 ;
}
static int V_350 ( struct V_1 * V_2 , struct V_250 * V_250 ,
struct V_417 * V_418 )
{
return - V_116 ;
}
static inline struct V_423 *
F_273 ( struct V_1 * V_2 , unsigned long V_434 )
{
void * V_435 = V_2 -> V_15 -> V_436 + V_434 ;
return F_269 ( V_435 ) ;
}
static int F_274 ( struct V_417 * V_418 ,
struct V_419 * V_420 )
{
struct V_1 * V_2 = V_418 -> V_421 ;
struct V_14 * V_15 ;
unsigned long V_401 ;
struct V_423 * V_423 ;
T_8 V_326 ;
if ( V_2 == NULL )
return V_422 ;
V_15 = V_2 -> V_15 ;
V_401 = V_420 -> V_437 << V_438 ;
V_326 = F_271 ( V_15 -> V_326 ) ;
if ( V_401 > V_326 - V_439 )
return V_422 ;
if ( V_2 -> V_34 -> V_423 )
V_423 = V_2 -> V_34 -> V_423 ( V_2 , V_401 ) ;
else
V_423 = F_273 ( V_2 , V_401 ) ;
if ( ! V_423 )
return V_422 ;
F_270 ( V_423 ) ;
V_420 -> V_423 = V_423 ;
return 0 ;
}
int F_275 ( struct V_1 * V_2 ,
struct V_417 * V_418 )
{
V_418 -> V_425 |= V_431 | V_432 ;
#ifdef F_276
if ( V_2 -> V_50 . V_51 . type == V_440 ) {
V_418 -> V_441 = F_277 ( V_418 -> V_441 ) ;
return F_278 ( V_418 , V_418 -> V_428 ,
V_2 -> V_50 . V_442 >> V_438 ,
V_418 -> V_427 - V_418 -> V_428 , V_418 -> V_441 ) ;
}
#endif
#ifndef F_279
if ( ! V_2 -> V_34 -> V_423 &&
V_2 -> V_50 . V_51 . type == V_52 )
return F_280 ( V_2 -> V_50 . V_51 . V_51 ,
V_418 ,
V_2 -> V_15 -> V_436 ,
V_2 -> V_15 -> V_443 ,
V_418 -> V_427 - V_418 -> V_428 ) ;
#endif
V_418 -> V_429 = & V_444 ;
return 0 ;
}
int F_281 ( struct V_1 * V_2 ,
struct V_417 * V_418 )
{
struct V_14 * V_15 = V_2 -> V_15 ; ;
V_418 -> V_441 = F_282 ( V_418 -> V_441 ) ;
return F_283 ( V_418 , V_15 -> V_443 , V_15 -> V_326 ) ;
}
int F_284 ( struct V_1 * V_2 , struct V_250 * V_250 ,
struct V_417 * V_418 )
{
struct V_14 * V_15 ;
long V_424 ;
unsigned long V_401 ;
T_8 V_326 ;
int V_38 ;
if ( V_2 -> V_22 == V_158 ) {
if ( ! ( V_418 -> V_425 & ( V_445 | V_426 ) ) )
return - V_80 ;
} else {
if ( ! ( V_418 -> V_425 & V_426 ) )
return - V_80 ;
}
V_15 = V_2 -> V_15 ;
if ( V_15 -> V_110 -> V_109 == V_117 )
return - V_120 ;
if ( ! ( V_15 -> V_13 & V_43 ) )
return - V_116 ;
if ( V_15 -> V_126 == V_307 ||
V_15 -> V_126 == V_309 )
return - V_80 ;
V_424 = V_418 -> V_427 - V_418 -> V_428 ;
V_401 = V_418 -> V_446 << V_438 ;
V_326 = F_271 ( V_15 -> V_326 ) ;
if ( ( T_8 ) V_424 > V_326 )
return - V_80 ;
if ( V_401 > V_326 - V_424 )
return - V_80 ;
V_418 -> V_429 = & V_447 ;
V_418 -> V_421 = V_2 ;
if ( V_2 -> V_34 -> V_49 )
V_38 = V_2 -> V_34 -> V_49 ( V_2 , V_418 ) ;
else
V_38 = F_275 ( V_2 , V_418 ) ;
if ( ! V_38 )
F_285 ( & V_2 -> V_123 ) ;
return V_38 ;
}
static int F_286 ( struct V_250 * V_250 , struct V_417 * V_418 )
{
struct V_277 * V_278 ;
struct V_1 * V_2 ;
unsigned long V_401 ;
V_278 = V_250 -> V_283 ;
V_2 = V_278 -> V_2 ;
if ( F_60 ( V_2 ) )
return - V_116 ;
V_401 = V_418 -> V_446 << V_438 ;
switch ( V_401 ) {
case V_448 :
if ( V_278 -> V_449 )
return - V_116 ;
return V_349 ( V_2 , V_250 , V_418 ) ;
case V_450 :
if ( V_278 -> V_449 )
return - V_116 ;
return V_350 ( V_2 , V_250 , V_418 ) ;
default:
return F_284 ( V_2 , V_250 , V_418 ) ;
}
return 0 ;
}
static int F_287 ( int V_276 , struct V_250 * V_250 , int V_451 )
{
struct V_277 * V_278 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
V_278 = V_250 -> V_283 ;
V_2 = V_278 -> V_2 ;
if ( F_60 ( V_2 ) )
return - V_116 ;
V_15 = V_2 -> V_15 ;
return F_288 ( V_276 , V_250 , V_451 , & V_15 -> V_452 ) ;
}
static void F_289 ( struct V_53 * V_54 ,
struct V_453 * V_454 )
{
unsigned int V_58 ;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_11 = V_454 -> V_11 ;
for ( V_58 = 0 ; V_58 < F_290 ( V_454 -> V_455 ) ; V_58 ++ )
V_54 -> V_455 [ V_58 ] . V_82 [ 0 ] = V_454 -> V_455 [ V_58 ] ;
memcpy ( V_54 -> V_456 , V_454 -> V_456 , sizeof( V_454 -> V_456 ) ) ;
V_54 -> V_72 = F_291 ( V_454 -> V_72 ) ;
V_54 -> V_83 = F_291 ( V_454 -> V_83 ) ;
V_54 -> V_13 = V_454 -> V_13 ;
V_54 -> V_74 = V_454 -> V_74 ;
V_54 -> V_76 = V_454 -> V_76 ;
V_54 -> V_77 = V_454 -> V_77 ;
V_54 -> V_71 = V_454 -> V_71 ;
}
static void F_292 ( struct V_453 * V_454 ,
struct V_53 * V_54 )
{
unsigned int V_58 ;
memset ( V_454 , 0 , sizeof( * V_454 ) ) ;
V_454 -> V_11 = V_54 -> V_11 ;
for ( V_58 = 0 ; V_58 < F_290 ( V_454 -> V_455 ) ; V_58 ++ )
V_454 -> V_455 [ V_58 ] = V_54 -> V_455 [ V_58 ] . V_82 [ 0 ] ;
memcpy ( V_454 -> V_456 , V_54 -> V_456 , sizeof( V_454 -> V_456 ) ) ;
V_454 -> V_72 = F_293 ( V_54 -> V_72 ) ;
V_454 -> V_83 = F_293 ( V_54 -> V_83 ) ;
V_454 -> V_13 = V_54 -> V_13 ;
V_454 -> V_74 = V_54 -> V_74 ;
V_454 -> V_76 = V_54 -> V_76 ;
V_454 -> V_77 = V_54 -> V_77 ;
V_454 -> V_71 = V_54 -> V_71 ;
}
static int F_244 ( struct V_1 * V_2 ,
struct V_453 T_2 * V_457 )
{
struct V_53 * V_54 ;
struct V_453 * V_454 = NULL ;
int V_38 ;
V_54 = F_27 ( sizeof( * V_54 ) , V_39 ) ;
if ( ! V_54 )
return - V_40 ;
V_454 = F_52 ( V_457 , sizeof( * V_454 ) ) ;
if ( F_53 ( V_454 ) ) {
V_38 = F_54 ( V_454 ) ;
goto V_458;
}
F_289 ( V_54 , V_454 ) ;
V_38 = F_32 ( V_2 , V_54 ) ;
F_292 ( V_454 , V_54 ) ;
if ( F_28 ( V_457 , V_454 , sizeof( * V_454 ) ) ) {
if ( ! V_38 )
V_38 = - V_41 ;
}
F_29 ( V_454 ) ;
V_458:
F_29 ( V_54 ) ;
return V_38 ;
}
static int F_245 ( struct V_1 * V_2 ,
struct V_453 T_2 * V_457 )
{
struct V_53 * V_54 ;
struct V_453 * V_454 = NULL ;
int V_38 ;
V_54 = F_27 ( sizeof( * V_54 ) , V_39 ) ;
if ( ! V_54 )
return - V_40 ;
V_454 = F_52 ( V_457 , sizeof( * V_454 ) ) ;
if ( F_53 ( V_454 ) ) {
V_38 = F_54 ( V_454 ) ;
goto V_458;
}
F_289 ( V_54 , V_454 ) ;
V_38 = V_53 ( V_2 , V_54 ) ;
F_292 ( V_454 , V_54 ) ;
if ( F_28 ( V_457 , V_454 , sizeof( * V_454 ) ) ) {
if ( ! V_38 )
V_38 = - V_41 ;
}
F_29 ( V_454 ) ;
V_458:
F_29 ( V_54 ) ;
return V_38 ;
}
static unsigned long F_294 ( struct V_250 * V_250 ,
unsigned long V_442 ,
unsigned long V_459 ,
unsigned long V_437 ,
unsigned long V_11 )
{
struct V_277 * V_278 = V_250 -> V_283 ;
struct V_1 * V_2 = V_278 -> V_2 ;
struct V_14 * V_15 = V_2 -> V_15 ;
unsigned long V_401 = V_437 << V_438 ;
switch ( V_401 ) {
case V_448 :
return ( unsigned long ) V_15 -> V_110 ;
case V_450 :
return ( unsigned long ) V_15 -> V_142 ;
default:
return ( unsigned long ) V_15 -> V_436 + V_401 ;
}
}
