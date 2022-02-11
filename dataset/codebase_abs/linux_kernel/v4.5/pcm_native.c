static inline void F_1 ( struct V_1 * V_2 )
{
while ( ! F_2 ( V_2 ) )
F_3 () ;
}
void F_4 ( struct V_3 * V_4 )
{
if ( V_4 -> V_5 -> V_6 ) {
F_5 ( & V_7 , V_8 ) ;
F_6 ( & V_4 -> V_9 . V_10 ) ;
} else {
F_7 ( & V_11 ) ;
F_8 ( & V_4 -> V_9 . V_2 ) ;
}
}
void F_9 ( struct V_3 * V_4 )
{
if ( V_4 -> V_5 -> V_6 ) {
F_10 ( & V_4 -> V_9 . V_10 ) ;
F_11 ( & V_7 ) ;
} else {
F_12 ( & V_4 -> V_9 . V_2 ) ;
F_13 ( & V_11 ) ;
}
}
void F_14 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_5 -> V_6 )
F_15 () ;
F_4 ( V_4 ) ;
}
void F_16 ( struct V_3 * V_4 )
{
F_9 ( V_4 ) ;
if ( ! V_4 -> V_5 -> V_6 )
F_17 () ;
}
unsigned long F_18 ( struct V_3 * V_4 )
{
unsigned long V_12 = 0 ;
if ( ! V_4 -> V_5 -> V_6 )
F_19 ( V_12 ) ;
F_4 ( V_4 ) ;
return V_12 ;
}
void F_20 ( struct V_3 * V_4 ,
unsigned long V_12 )
{
F_9 ( V_4 ) ;
if ( ! V_4 -> V_5 -> V_6 )
F_21 ( V_12 ) ;
}
static inline T_1 F_22 ( void )
{
T_1 V_13 = F_23 () ;
F_24 ( F_25 () ) ;
return V_13 ;
}
static inline void F_26 ( T_1 V_13 )
{
F_24 ( V_13 ) ;
}
int F_27 ( struct V_3 * V_4 , struct F_27 * V_14 )
{
struct V_15 * V_16 ;
struct V_17 * V_5 = V_4 -> V_5 ;
struct V_18 * V_19 = V_4 -> V_19 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
V_14 -> V_20 = V_5 -> V_20 -> V_21 ;
V_14 -> V_22 = V_5 -> V_22 ;
V_14 -> V_23 = V_4 -> V_23 ;
V_14 -> V_24 = V_4 -> V_21 ;
F_28 ( V_14 -> V_25 , V_5 -> V_25 , sizeof( V_14 -> V_25 ) ) ;
F_28 ( V_14 -> V_26 , V_5 -> V_26 , sizeof( V_14 -> V_26 ) ) ;
V_14 -> V_27 = V_5 -> V_27 ;
V_14 -> V_28 = V_5 -> V_28 ;
V_14 -> V_29 = V_19 -> V_30 ;
V_14 -> V_31 = V_19 -> V_30 - V_19 -> V_32 ;
F_28 ( V_14 -> V_33 , V_4 -> V_26 , sizeof( V_14 -> V_33 ) ) ;
V_16 = V_4 -> V_16 ;
if ( V_16 ) {
V_14 -> V_34 = V_16 -> V_34 ;
V_4 -> V_35 -> V_36 ( V_4 , V_37 , V_14 ) ;
}
return 0 ;
}
int F_29 ( struct V_3 * V_4 ,
struct F_27 T_2 * V_38 )
{
struct F_27 * V_14 ;
int V_39 ;
V_14 = F_30 ( sizeof( * V_14 ) , V_40 ) ;
if ( ! V_14 )
return - V_41 ;
V_39 = F_27 ( V_4 , V_14 ) ;
if ( V_39 >= 0 ) {
if ( F_31 ( V_38 , V_14 , sizeof( * V_14 ) ) )
V_39 = - V_42 ;
}
F_32 ( V_14 ) ;
return V_39 ;
}
static bool F_33 ( struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_16 -> V_43 . V_14 & V_44 ) )
return false ;
#if F_34 ( V_45 ) || F_34 ( V_46 ) || F_34 ( V_47 ) ||\
F_34 ( V_48 ) || F_34 ( V_49 )
if ( ! V_4 -> V_35 -> V_50 &&
V_4 -> V_51 . V_52 . type == V_53 )
return false ;
#endif
return true ;
}
int F_35 ( struct V_3 * V_4 ,
struct V_54 * V_55 )
{
unsigned int V_56 ;
struct V_57 * V_43 ;
struct V_58 * V_59 = NULL ;
struct V_60 * V_61 = NULL ;
struct V_62 * V_63 = & V_4 -> V_16 -> V_64 ;
unsigned int V_65 [ V_63 -> V_66 ] ;
unsigned int V_67 [ V_68 + 1 ] ;
unsigned int V_69 = 2 ;
int V_70 , V_71 ;
V_55 -> V_14 = 0 ;
V_55 -> V_72 = 0 ;
if ( V_55 -> V_73 & ( 1 << V_74 ) )
V_55 -> V_75 = 0 ;
if ( V_55 -> V_73 & ( 1 << V_76 ) ) {
V_55 -> V_77 = 0 ;
V_55 -> V_78 = 0 ;
}
for ( V_56 = V_79 ; V_56 <= V_80 ; V_56 ++ ) {
V_61 = F_36 ( V_55 , V_56 ) ;
if ( F_37 ( V_61 ) )
return - V_81 ;
if ( ! ( V_55 -> V_73 & ( 1 << V_56 ) ) )
continue;
#ifdef F_38
F_39 ( L_1 , V_82 [ V_56 ] ) ;
F_40 ( L_2 , V_61 -> V_83 [ 3 ] , V_61 -> V_83 [ 2 ] , V_61 -> V_83 [ 1 ] , V_61 -> V_83 [ 0 ] ) ;
#endif
V_70 = F_41 ( V_61 , F_42 ( V_63 , V_56 ) ) ;
#ifdef F_38
F_40 ( L_3 , V_61 -> V_83 [ 3 ] , V_61 -> V_83 [ 2 ] , V_61 -> V_83 [ 1 ] , V_61 -> V_83 [ 0 ] ) ;
#endif
if ( V_70 )
V_55 -> V_84 |= 1 << V_56 ;
if ( V_70 < 0 )
return V_70 ;
}
for ( V_56 = V_85 ; V_56 <= V_68 ; V_56 ++ ) {
V_59 = F_43 ( V_55 , V_56 ) ;
if ( F_44 ( V_59 ) )
return - V_81 ;
if ( ! ( V_55 -> V_73 & ( 1 << V_56 ) ) )
continue;
#ifdef F_38
F_39 ( L_1 , V_82 [ V_56 ] ) ;
if ( V_59 -> V_86 )
F_40 ( L_4 ) ;
else
F_40 ( L_5 ,
V_59 -> V_87 ? '(' : '[' , V_59 -> V_88 ,
V_59 -> V_89 , V_59 -> V_90 ? ')' : ']' ) ;
F_40 ( L_6 ) ;
#endif
V_70 = F_45 ( V_59 , F_46 ( V_63 , V_56 ) ) ;
#ifdef F_38
if ( V_59 -> V_86 )
F_40 ( L_7 ) ;
else
F_40 ( L_8 ,
V_59 -> V_87 ? '(' : '[' , V_59 -> V_88 ,
V_59 -> V_89 , V_59 -> V_90 ? ')' : ']' ) ;
#endif
if ( V_70 )
V_55 -> V_84 |= 1 << V_56 ;
if ( V_70 < 0 )
return V_70 ;
}
for ( V_56 = 0 ; V_56 < V_63 -> V_66 ; V_56 ++ )
V_65 [ V_56 ] = 0 ;
for ( V_56 = 0 ; V_56 <= V_68 ; V_56 ++ )
V_67 [ V_56 ] = ( V_55 -> V_73 & ( 1 << V_56 ) ) ? 1 : 0 ;
do {
V_71 = 0 ;
for ( V_56 = 0 ; V_56 < V_63 -> V_66 ; V_56 ++ ) {
struct V_91 * V_92 = & V_63 -> V_93 [ V_56 ] ;
unsigned int V_94 ;
int V_95 = 0 ;
if ( V_92 -> V_96 && ! ( V_92 -> V_96 & V_55 -> V_12 ) )
continue;
for ( V_94 = 0 ; V_92 -> V_97 [ V_94 ] >= 0 ; V_94 ++ ) {
if ( V_67 [ V_92 -> V_97 [ V_94 ] ] > V_65 [ V_56 ] ) {
V_95 = 1 ;
break;
}
}
if ( ! V_95 )
continue;
#ifdef F_38
F_39 ( L_9 , V_56 , V_92 -> V_98 ) ;
if ( V_92 -> V_99 >= 0 ) {
F_40 ( L_1 , V_82 [ V_92 -> V_99 ] ) ;
if ( F_47 ( V_92 -> V_99 ) ) {
V_61 = F_36 ( V_55 , V_92 -> V_99 ) ;
F_40 ( L_10 , * V_61 -> V_83 ) ;
} else {
V_59 = F_43 ( V_55 , V_92 -> V_99 ) ;
if ( V_59 -> V_86 )
F_40 ( L_4 ) ;
else
F_40 ( L_5 ,
V_59 -> V_87 ? '(' : '[' , V_59 -> V_88 ,
V_59 -> V_89 , V_59 -> V_90 ? ')' : ']' ) ;
}
}
#endif
V_70 = V_92 -> V_98 ( V_55 , V_92 ) ;
#ifdef F_38
if ( V_92 -> V_99 >= 0 ) {
F_40 ( L_6 ) ;
if ( F_47 ( V_92 -> V_99 ) )
F_40 ( L_10 , * V_61 -> V_83 ) ;
else {
if ( V_59 -> V_86 )
F_40 ( L_4 ) ;
else
F_40 ( L_5 ,
V_59 -> V_87 ? '(' : '[' , V_59 -> V_88 ,
V_59 -> V_89 , V_59 -> V_90 ? ')' : ']' ) ;
}
}
F_40 ( L_11 ) ;
#endif
V_65 [ V_56 ] = V_69 ;
if ( V_70 && V_92 -> V_99 >= 0 ) {
V_55 -> V_84 |= ( 1 << V_92 -> V_99 ) ;
V_67 [ V_92 -> V_99 ] = V_69 ;
V_71 = 1 ;
}
if ( V_70 < 0 )
return V_70 ;
V_69 ++ ;
}
} while ( V_71 );
if ( ! V_55 -> V_75 ) {
V_59 = F_43 ( V_55 , V_74 ) ;
if ( F_48 ( V_59 ) )
V_55 -> V_75 = F_49 ( V_59 ) ;
}
if ( ! V_55 -> V_78 ) {
V_59 = F_43 ( V_55 , V_76 ) ;
if ( F_48 ( V_59 ) ) {
V_55 -> V_77 = F_49 ( V_59 ) ;
V_55 -> V_78 = 1 ;
}
}
V_43 = & V_4 -> V_16 -> V_43 ;
if ( ! V_55 -> V_14 ) {
V_55 -> V_14 = V_43 -> V_14 & ~ ( V_100 |
V_101 ) ;
if ( ! F_33 ( V_4 ) )
V_55 -> V_14 &= ~ ( V_44 |
V_102 ) ;
}
if ( ! V_55 -> V_72 ) {
V_61 = F_36 ( V_55 , V_103 ) ;
V_59 = F_43 ( V_55 , V_104 ) ;
if ( F_50 ( V_61 ) == F_51 ( V_61 ) &&
F_52 ( V_59 ) == F_53 ( V_59 ) ) {
V_70 = V_4 -> V_35 -> V_36 ( V_4 ,
V_105 , V_55 ) ;
if ( V_70 < 0 )
return V_70 ;
}
}
V_55 -> V_73 = 0 ;
return 0 ;
}
static int F_54 ( struct V_3 * V_4 ,
struct V_54 T_2 * V_106 )
{
struct V_54 * V_55 ;
int V_39 ;
V_55 = F_55 ( V_106 , sizeof( * V_55 ) ) ;
if ( F_56 ( V_55 ) )
return F_57 ( V_55 ) ;
V_39 = F_35 ( V_4 , V_55 ) ;
if ( F_31 ( V_106 , V_55 , sizeof( * V_55 ) ) ) {
if ( ! V_39 )
V_39 = - V_42 ;
}
F_32 ( V_55 ) ;
return V_39 ;
}
static int F_58 ( struct V_15 * V_16 )
{
int V_107 ;
if ( ! V_16 -> V_108 )
return - 1 ;
V_107 = ( 750000 / V_16 -> V_108 ) * V_16 -> V_109 ;
V_107 += ( ( 750000 % V_16 -> V_108 ) * V_16 -> V_109 ) /
V_16 -> V_108 ;
return V_107 ;
}
static void F_59 ( struct V_3 * V_4 , int V_110 )
{
F_14 ( V_4 ) ;
if ( V_4 -> V_16 -> V_111 -> V_110 != V_112 )
V_4 -> V_16 -> V_111 -> V_110 = V_110 ;
F_16 ( V_4 ) ;
}
static inline void F_60 ( struct V_3 * V_4 ,
int V_113 )
{
#ifdef F_61
if ( V_4 -> V_114 )
F_62 ( V_4 -> V_114 , V_113 ,
& V_4 -> V_16 -> V_115 ) ;
#endif
}
static int V_54 ( struct V_3 * V_4 ,
struct V_54 * V_55 )
{
struct V_15 * V_16 ;
int V_39 , V_107 ;
unsigned int V_83 ;
T_3 V_116 ;
if ( F_63 ( V_4 ) )
return - V_117 ;
V_16 = V_4 -> V_16 ;
F_14 ( V_4 ) ;
switch ( V_16 -> V_111 -> V_110 ) {
case V_118 :
case V_119 :
case V_120 :
break;
default:
F_16 ( V_4 ) ;
return - V_121 ;
}
F_16 ( V_4 ) ;
#if F_64 ( V_122 )
if ( ! V_4 -> V_123 . V_123 )
#endif
if ( F_65 ( & V_4 -> V_124 ) )
return - V_121 ;
V_55 -> V_73 = ~ 0U ;
V_39 = F_35 ( V_4 , V_55 ) ;
if ( V_39 < 0 )
goto V_125;
V_39 = F_66 ( V_4 , V_55 ) ;
if ( V_39 < 0 )
goto V_125;
if ( V_4 -> V_35 -> V_126 != NULL ) {
V_39 = V_4 -> V_35 -> V_126 ( V_4 , V_55 ) ;
if ( V_39 < 0 )
goto V_125;
}
V_16 -> V_127 = F_67 ( V_55 ) ;
V_16 -> V_128 = F_68 ( V_55 ) ;
V_16 -> V_129 = F_69 ( V_55 ) ;
V_16 -> V_130 = F_70 ( V_55 ) ;
V_16 -> V_108 = F_71 ( V_55 ) ;
V_16 -> V_109 = F_72 ( V_55 ) ;
V_16 -> V_131 = F_73 ( V_55 ) ;
V_16 -> V_132 = F_74 ( V_55 ) ;
V_16 -> V_14 = V_55 -> V_14 ;
V_16 -> V_77 = V_55 -> V_77 ;
V_16 -> V_78 = V_55 -> V_78 ;
V_16 -> V_133 =
( V_55 -> V_14 & V_134 ) &&
( V_55 -> V_12 & V_135 ) ;
V_83 = F_75 ( V_16 -> V_128 ) ;
V_16 -> V_136 = V_83 ;
V_83 *= V_16 -> V_130 ;
V_16 -> V_137 = V_83 ;
V_116 = 1 ;
while ( V_83 % 8 != 0 ) {
V_83 *= 2 ;
V_116 *= 2 ;
}
V_16 -> V_138 = V_83 / 8 ;
V_16 -> V_139 = V_116 ;
V_16 -> V_140 = V_141 ;
V_16 -> V_142 = 1 ;
V_16 -> V_143 -> V_144 = V_16 -> V_109 ;
V_16 -> V_145 = 1 ;
V_16 -> V_146 = V_16 -> V_132 ;
V_16 -> V_147 = 0 ;
V_16 -> V_148 = 0 ;
V_16 -> V_149 = V_16 -> V_132 ;
while ( V_16 -> V_149 * 2 <= V_150 - V_16 -> V_132 )
V_16 -> V_149 *= 2 ;
F_76 ( V_4 ) ;
F_59 ( V_4 , V_119 ) ;
if ( F_77 ( & V_4 -> V_151 ) )
F_78 ( & V_4 -> V_151 ) ;
if ( ( V_107 = F_58 ( V_16 ) ) >= 0 )
F_79 ( & V_4 -> V_151 ,
V_152 , V_107 ) ;
return 0 ;
V_125:
F_59 ( V_4 , V_118 ) ;
if ( V_4 -> V_35 -> V_153 != NULL )
V_4 -> V_35 -> V_153 ( V_4 ) ;
return V_39 ;
}
static int F_80 ( struct V_3 * V_4 ,
struct V_54 T_2 * V_106 )
{
struct V_54 * V_55 ;
int V_39 ;
V_55 = F_55 ( V_106 , sizeof( * V_55 ) ) ;
if ( F_56 ( V_55 ) )
return F_57 ( V_55 ) ;
V_39 = V_54 ( V_4 , V_55 ) ;
if ( F_31 ( V_106 , V_55 , sizeof( * V_55 ) ) ) {
if ( ! V_39 )
V_39 = - V_42 ;
}
F_32 ( V_55 ) ;
return V_39 ;
}
static int F_81 ( struct V_3 * V_4 )
{
struct V_15 * V_16 ;
int V_154 = 0 ;
if ( F_63 ( V_4 ) )
return - V_117 ;
V_16 = V_4 -> V_16 ;
F_14 ( V_4 ) ;
switch ( V_16 -> V_111 -> V_110 ) {
case V_119 :
case V_120 :
break;
default:
F_16 ( V_4 ) ;
return - V_121 ;
}
F_16 ( V_4 ) ;
if ( F_65 ( & V_4 -> V_124 ) )
return - V_121 ;
if ( V_4 -> V_35 -> V_153 )
V_154 = V_4 -> V_35 -> V_153 ( V_4 ) ;
F_59 ( V_4 , V_118 ) ;
F_78 ( & V_4 -> V_151 ) ;
return V_154 ;
}
static int F_82 ( struct V_3 * V_4 ,
struct F_82 * V_55 )
{
struct V_15 * V_16 ;
int V_39 ;
if ( F_63 ( V_4 ) )
return - V_117 ;
V_16 = V_4 -> V_16 ;
F_14 ( V_4 ) ;
if ( V_16 -> V_111 -> V_110 == V_118 ) {
F_16 ( V_4 ) ;
return - V_121 ;
}
F_16 ( V_4 ) ;
if ( V_55 -> V_140 < 0 ||
V_55 -> V_140 > V_155 )
return - V_81 ;
if ( V_55 -> V_156 >= F_83 ( 2 , 0 , 12 ) &&
V_55 -> V_157 > V_158 )
return - V_81 ;
if ( V_55 -> V_144 == 0 )
return - V_81 ;
if ( V_55 -> V_148 >= V_16 -> V_149 ) {
if ( V_55 -> V_147 != 0 )
return - V_81 ;
} else {
if ( V_55 -> V_148 > V_55 -> V_147 )
return - V_81 ;
if ( V_55 -> V_147 > V_16 -> V_132 )
return - V_81 ;
}
V_39 = 0 ;
F_14 ( V_4 ) ;
V_16 -> V_140 = V_55 -> V_140 ;
if ( V_55 -> V_156 >= F_83 ( 2 , 0 , 12 ) )
V_16 -> V_157 = V_55 -> V_157 ;
V_16 -> V_142 = V_55 -> V_142 ;
V_16 -> V_143 -> V_144 = V_55 -> V_144 ;
V_16 -> V_145 = V_55 -> V_145 ;
V_16 -> V_146 = V_55 -> V_146 ;
V_16 -> V_147 = V_55 -> V_147 ;
V_16 -> V_148 = V_55 -> V_148 ;
V_55 -> V_149 = V_16 -> V_149 ;
if ( F_84 ( V_4 ) ) {
if ( V_4 -> V_23 == V_159 &&
V_16 -> V_148 > 0 )
F_85 ( V_4 , V_160 ) ;
V_39 = F_86 ( V_4 , V_16 ) ;
}
F_16 ( V_4 ) ;
return V_39 ;
}
static int F_87 ( struct V_3 * V_4 ,
struct F_82 T_2 * V_106 )
{
struct F_82 V_55 ;
int V_39 ;
if ( F_88 ( & V_55 , V_106 , sizeof( V_55 ) ) )
return - V_42 ;
V_39 = F_82 ( V_4 , & V_55 ) ;
if ( F_31 ( V_106 , & V_55 , sizeof( V_55 ) ) )
return - V_42 ;
return V_39 ;
}
int F_89 ( struct V_3 * V_4 ,
struct F_89 * V_111 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
F_14 ( V_4 ) ;
F_90 ( V_111 -> V_161 ,
& V_16 -> V_162 ) ;
if ( V_16 -> V_162 . V_163 ==
V_164 ) {
if ( V_16 -> V_43 . V_14 & V_165 )
V_16 -> V_162 . V_163 =
V_166 ;
else
V_16 -> V_162 . V_163 =
V_167 ;
V_16 -> V_168 . V_169 = 0 ;
} else
V_16 -> V_168 . V_169 = 1 ;
V_111 -> V_110 = V_16 -> V_111 -> V_110 ;
V_111 -> V_170 = V_16 -> V_111 -> V_170 ;
if ( V_111 -> V_110 == V_118 )
goto V_171;
V_111 -> V_115 = V_16 -> V_115 ;
if ( F_84 ( V_4 ) ) {
F_91 ( V_4 ) ;
if ( V_16 -> V_140 == V_172 ) {
V_111 -> V_173 = V_16 -> V_111 -> V_173 ;
V_111 -> V_174 = V_16 -> V_174 ;
V_111 -> V_175 =
V_16 -> V_111 -> V_175 ;
if ( V_16 -> V_168 . V_169 == 1 )
F_92 ( & V_111 -> V_161 ,
& V_111 -> V_176 ,
& V_16 -> V_168 ) ;
goto V_177;
}
} else {
if ( V_16 -> V_140 == V_172 )
F_93 ( V_16 , & V_111 -> V_173 ) ;
}
V_177:
V_111 -> V_178 = V_16 -> V_143 -> V_178 ;
V_111 -> V_179 = V_16 -> V_111 -> V_179 ;
if ( V_4 -> V_23 == V_159 ) {
V_111 -> V_180 = F_94 ( V_16 ) ;
if ( V_16 -> V_111 -> V_110 == V_181 ||
V_16 -> V_111 -> V_110 == V_182 ) {
V_111 -> V_183 = V_16 -> V_132 - V_111 -> V_180 ;
V_111 -> V_183 += V_16 -> V_183 ;
} else
V_111 -> V_183 = 0 ;
} else {
V_111 -> V_180 = F_95 ( V_16 ) ;
if ( V_16 -> V_111 -> V_110 == V_181 )
V_111 -> V_183 = V_111 -> V_180 + V_16 -> V_183 ;
else
V_111 -> V_183 = 0 ;
}
V_111 -> V_184 = V_16 -> V_184 ;
V_111 -> V_185 = V_16 -> V_185 ;
V_16 -> V_184 = 0 ;
V_16 -> V_185 = 0 ;
V_171:
F_16 ( V_4 ) ;
return 0 ;
}
static int F_96 ( struct V_3 * V_4 ,
struct F_89 T_2 * V_186 ,
bool V_187 )
{
struct F_89 V_111 ;
int V_188 ;
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
if ( V_187 && F_97 ( V_111 . V_161 ,
( V_189 T_2 * ) ( & V_186 -> V_161 ) ) )
return - V_42 ;
V_188 = F_89 ( V_4 , & V_111 ) ;
if ( V_188 < 0 )
return V_188 ;
if ( F_31 ( V_186 , & V_111 , sizeof( V_111 ) ) )
return - V_42 ;
return 0 ;
}
static int F_98 ( struct V_3 * V_4 ,
struct F_98 * V_14 )
{
struct V_15 * V_16 ;
unsigned int V_190 ;
V_190 = V_14 -> V_190 ;
V_16 = V_4 -> V_16 ;
F_14 ( V_4 ) ;
if ( V_16 -> V_111 -> V_110 == V_118 ) {
F_16 ( V_4 ) ;
return - V_121 ;
}
F_16 ( V_4 ) ;
if ( V_190 >= V_16 -> V_130 )
return - V_81 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
V_14 -> V_190 = V_190 ;
return V_4 -> V_35 -> V_36 ( V_4 , V_191 , V_14 ) ;
}
static int F_99 ( struct V_3 * V_4 ,
struct F_98 T_2 * V_38 )
{
struct F_98 V_14 ;
int V_188 ;
if ( F_88 ( & V_14 , V_38 , sizeof( V_14 ) ) )
return - V_42 ;
V_188 = F_98 ( V_4 , & V_14 ) ;
if ( V_188 < 0 )
return V_188 ;
if ( F_31 ( V_38 , & V_14 , sizeof( V_14 ) ) )
return - V_42 ;
return 0 ;
}
static void F_100 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
if ( V_16 -> V_192 == NULL )
return;
if ( V_16 -> V_192 == V_4 ) {
if ( ! V_16 -> V_193 )
F_93 ( V_16 , & V_16 -> V_115 ) ;
} else {
F_100 ( V_16 -> V_192 ) ;
V_16 -> V_115 = V_16 -> V_192 -> V_16 -> V_115 ;
}
V_16 -> V_192 = NULL ;
}
static int F_101 ( const struct V_194 * V_35 ,
struct V_3 * V_4 ,
int V_110 , int V_195 )
{
struct V_3 * V_196 = NULL ;
struct V_3 * V_197 ;
int V_188 = 0 , V_198 = 1 ;
F_102 (s, substream) {
if ( V_195 && V_196 != V_4 ) {
if ( V_196 -> V_5 -> V_6 )
F_103 ( & V_196 -> V_9 . V_10 , V_198 ) ;
else
F_104 ( & V_196 -> V_9 . V_2 , V_198 ) ;
V_198 ++ ;
}
V_188 = V_35 -> V_199 ( V_196 , V_110 ) ;
if ( V_188 < 0 )
goto V_200;
}
F_102 (s, substream) {
V_188 = V_35 -> V_201 ( V_196 , V_110 ) ;
if ( V_188 < 0 ) {
if ( V_35 -> V_202 ) {
F_102 (s1, substream) {
if ( V_197 == V_196 )
break;
V_35 -> V_202 ( V_197 , V_110 ) ;
}
}
V_196 = NULL ;
goto V_200;
}
}
F_102 (s, substream) {
V_35 -> V_203 ( V_196 , V_110 ) ;
}
V_200:
if ( V_195 ) {
F_102 (s1, substream) {
if ( V_197 != V_4 ) {
if ( V_197 -> V_5 -> V_6 )
F_10 ( & V_197 -> V_9 . V_10 ) ;
else
F_12 ( & V_197 -> V_9 . V_2 ) ;
}
if ( V_197 == V_196 )
break;
}
}
return V_188 ;
}
static int F_105 ( const struct V_194 * V_35 ,
struct V_3 * V_4 ,
int V_110 )
{
int V_188 ;
V_188 = V_35 -> V_199 ( V_4 , V_110 ) ;
if ( V_188 < 0 )
return V_188 ;
V_188 = V_35 -> V_201 ( V_4 , V_110 ) ;
if ( V_188 == 0 )
V_35 -> V_203 ( V_4 , V_110 ) ;
else if ( V_35 -> V_202 )
V_35 -> V_202 ( V_4 , V_110 ) ;
return V_188 ;
}
static int F_106 ( const struct V_194 * V_35 ,
struct V_3 * V_4 ,
int V_110 )
{
int V_188 ;
if ( ! F_107 ( V_4 ) )
return F_105 ( V_35 , V_4 , V_110 ) ;
if ( V_4 -> V_5 -> V_6 ) {
if ( ! F_108 ( & V_4 -> V_204 -> V_10 ) ) {
F_10 ( & V_4 -> V_9 . V_10 ) ;
F_6 ( & V_4 -> V_204 -> V_10 ) ;
F_6 ( & V_4 -> V_9 . V_10 ) ;
}
V_188 = F_101 ( V_35 , V_4 , V_110 , 1 ) ;
F_10 ( & V_4 -> V_204 -> V_10 ) ;
} else {
if ( ! F_109 ( & V_4 -> V_204 -> V_2 ) ) {
F_12 ( & V_4 -> V_9 . V_2 ) ;
F_8 ( & V_4 -> V_204 -> V_2 ) ;
F_8 ( & V_4 -> V_9 . V_2 ) ;
}
V_188 = F_101 ( V_35 , V_4 , V_110 , 1 ) ;
F_12 ( & V_4 -> V_204 -> V_2 ) ;
}
return V_188 ;
}
static int F_110 ( const struct V_194 * V_35 ,
struct V_3 * V_4 ,
int V_110 )
{
int V_188 ;
F_14 ( V_4 ) ;
V_188 = F_106 ( V_35 , V_4 , V_110 ) ;
F_16 ( V_4 ) ;
return V_188 ;
}
static int F_111 ( const struct V_194 * V_35 ,
struct V_3 * V_4 ,
int V_110 )
{
int V_188 ;
F_112 ( & V_7 ) ;
if ( F_107 ( V_4 ) )
V_188 = F_101 ( V_35 , V_4 , V_110 , 0 ) ;
else
V_188 = F_105 ( V_35 , V_4 , V_110 ) ;
F_11 ( & V_7 ) ;
return V_188 ;
}
static int F_113 ( struct V_3 * V_4 , int V_110 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
if ( V_16 -> V_111 -> V_110 != V_120 )
return - V_121 ;
if ( V_4 -> V_23 == V_159 &&
! F_114 ( V_4 ) )
return - V_205 ;
V_16 -> V_193 = false ;
V_16 -> V_192 = V_4 ;
return 0 ;
}
static int F_115 ( struct V_3 * V_4 , int V_110 )
{
if ( V_4 -> V_16 -> V_192 != V_4 )
return 0 ;
return V_4 -> V_35 -> V_206 ( V_4 , V_207 ) ;
}
static void F_116 ( struct V_3 * V_4 , int V_110 )
{
if ( V_4 -> V_16 -> V_192 == V_4 )
V_4 -> V_35 -> V_206 ( V_4 , V_208 ) ;
}
static void F_117 ( struct V_3 * V_4 , int V_110 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
F_100 ( V_4 ) ;
V_16 -> V_209 = V_210 ;
V_16 -> V_211 = ( V_16 -> V_132 * V_212 ) /
V_16 -> V_108 ;
V_16 -> V_111 -> V_110 = V_110 ;
if ( V_4 -> V_23 == V_159 &&
V_16 -> V_148 > 0 )
F_85 ( V_4 , V_160 ) ;
F_60 ( V_4 , V_213 ) ;
}
int F_118 ( struct V_3 * V_4 )
{
return F_106 ( & V_214 , V_4 ,
V_181 ) ;
}
static int F_119 ( struct V_3 * V_4 , int V_110 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
if ( V_16 -> V_111 -> V_110 == V_118 )
return - V_121 ;
V_16 -> V_192 = V_4 ;
return 0 ;
}
static int F_120 ( struct V_3 * V_4 , int V_110 )
{
if ( V_4 -> V_16 -> V_192 == V_4 &&
F_84 ( V_4 ) )
V_4 -> V_35 -> V_206 ( V_4 , V_208 ) ;
return 0 ;
}
static void F_121 ( struct V_3 * V_4 , int V_110 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
if ( V_16 -> V_111 -> V_110 != V_110 ) {
F_100 ( V_4 ) ;
V_16 -> V_111 -> V_110 = V_110 ;
F_60 ( V_4 , V_215 ) ;
}
F_122 ( & V_16 -> V_216 ) ;
F_122 ( & V_16 -> V_217 ) ;
}
int F_123 ( struct V_3 * V_4 , T_4 V_110 )
{
return F_106 ( & V_218 , V_4 , V_110 ) ;
}
int F_124 ( struct V_3 * V_4 )
{
return F_105 ( & V_218 , V_4 ,
V_119 ) ;
}
int F_125 ( struct V_3 * V_4 )
{
unsigned long V_12 ;
int V_219 = 0 ;
F_126 ( V_4 , V_12 ) ;
if ( F_84 ( V_4 ) )
V_219 = F_123 ( V_4 , V_220 ) ;
F_20 ( V_4 , V_12 ) ;
return V_219 ;
}
static int F_127 ( struct V_3 * V_4 , int V_221 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
if ( ! ( V_16 -> V_14 & V_222 ) )
return - V_223 ;
if ( V_221 ) {
if ( V_16 -> V_111 -> V_110 != V_181 )
return - V_121 ;
} else if ( V_16 -> V_111 -> V_110 != V_224 )
return - V_121 ;
V_16 -> V_192 = V_4 ;
return 0 ;
}
static int F_128 ( struct V_3 * V_4 , int V_221 )
{
if ( V_4 -> V_16 -> V_192 != V_4 )
return 0 ;
if ( V_221 )
F_91 ( V_4 ) ;
V_4 -> V_16 -> V_209 = V_210 - V_212 * 1000 ;
return V_4 -> V_35 -> V_206 ( V_4 ,
V_221 ? V_225 :
V_226 ) ;
}
static void F_129 ( struct V_3 * V_4 , int V_221 )
{
if ( V_4 -> V_16 -> V_192 == V_4 )
V_4 -> V_35 -> V_206 ( V_4 ,
V_221 ? V_226 :
V_225 ) ;
}
static void F_130 ( struct V_3 * V_4 , int V_221 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
F_100 ( V_4 ) ;
if ( V_221 ) {
V_16 -> V_111 -> V_110 = V_224 ;
F_60 ( V_4 , V_227 ) ;
F_122 ( & V_16 -> V_216 ) ;
F_122 ( & V_16 -> V_217 ) ;
} else {
V_16 -> V_111 -> V_110 = V_181 ;
F_60 ( V_4 , V_228 ) ;
}
}
static int F_131 ( struct V_3 * V_4 , int V_221 )
{
return F_106 ( & V_229 , V_4 , V_221 ) ;
}
static int F_132 ( struct V_3 * V_4 , int V_110 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
if ( V_16 -> V_111 -> V_110 == V_230 )
return - V_231 ;
V_16 -> V_192 = V_4 ;
return 0 ;
}
static int F_133 ( struct V_3 * V_4 , int V_110 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
if ( V_16 -> V_192 != V_4 )
return 0 ;
if ( ! F_84 ( V_4 ) )
return 0 ;
V_4 -> V_35 -> V_206 ( V_4 , V_232 ) ;
return 0 ;
}
static void F_134 ( struct V_3 * V_4 , int V_110 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
F_100 ( V_4 ) ;
V_16 -> V_111 -> V_170 = V_16 -> V_111 -> V_110 ;
V_16 -> V_111 -> V_110 = V_230 ;
F_60 ( V_4 , V_233 ) ;
F_122 ( & V_16 -> V_216 ) ;
F_122 ( & V_16 -> V_217 ) ;
}
int F_135 ( struct V_3 * V_4 )
{
int V_39 ;
unsigned long V_12 ;
if ( ! V_4 )
return 0 ;
F_126 ( V_4 , V_12 ) ;
V_39 = F_106 ( & V_234 , V_4 , 0 ) ;
F_20 ( V_4 , V_12 ) ;
return V_39 ;
}
int F_136 ( struct V_17 * V_5 )
{
struct V_3 * V_4 ;
int V_23 , V_39 = 0 ;
if ( ! V_5 )
return 0 ;
for ( V_23 = 0 ; V_23 < 2 ; V_23 ++ ) {
for ( V_4 = V_5 -> V_235 [ V_23 ] . V_4 ;
V_4 ; V_4 = V_4 -> V_236 ) {
if ( V_4 -> V_16 == NULL )
continue;
V_39 = F_135 ( V_4 ) ;
if ( V_39 < 0 && V_39 != - V_231 )
return V_39 ;
}
}
return 0 ;
}
static int F_137 ( struct V_3 * V_4 , int V_110 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
if ( ! ( V_16 -> V_14 & V_237 ) )
return - V_223 ;
V_16 -> V_192 = V_4 ;
return 0 ;
}
static int F_138 ( struct V_3 * V_4 , int V_110 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
if ( V_16 -> V_192 != V_4 )
return 0 ;
if ( V_16 -> V_111 -> V_170 != V_181 &&
( V_16 -> V_111 -> V_170 != V_182 ||
V_4 -> V_23 != V_159 ) )
return 0 ;
return V_4 -> V_35 -> V_206 ( V_4 , V_238 ) ;
}
static void F_139 ( struct V_3 * V_4 , int V_110 )
{
if ( V_4 -> V_16 -> V_192 == V_4 &&
F_84 ( V_4 ) )
V_4 -> V_35 -> V_206 ( V_4 , V_232 ) ;
}
static void F_140 ( struct V_3 * V_4 , int V_110 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
F_100 ( V_4 ) ;
V_16 -> V_111 -> V_110 = V_16 -> V_111 -> V_170 ;
F_60 ( V_4 , V_239 ) ;
}
static int F_141 ( struct V_3 * V_4 )
{
struct V_240 * V_20 = V_4 -> V_5 -> V_20 ;
int V_188 ;
F_142 ( V_20 ) ;
if ( ( V_188 = F_143 ( V_20 , V_241 ) ) >= 0 )
V_188 = F_110 ( & V_242 , V_4 , 0 ) ;
F_144 ( V_20 ) ;
return V_188 ;
}
static int F_141 ( struct V_3 * V_4 )
{
return - V_223 ;
}
static int F_145 ( struct V_3 * V_4 )
{
struct V_240 * V_20 = V_4 -> V_5 -> V_20 ;
struct V_15 * V_16 = V_4 -> V_16 ;
int V_154 ;
F_142 ( V_20 ) ;
if ( V_16 -> V_111 -> V_110 == V_230 ) {
V_154 = F_143 ( V_20 , V_241 ) ;
if ( V_154 < 0 )
goto V_200;
}
F_14 ( V_4 ) ;
switch ( V_16 -> V_111 -> V_110 ) {
case V_220 :
V_154 = 0 ;
break;
case V_181 :
V_154 = F_123 ( V_4 , V_220 ) ;
break;
default:
V_154 = - V_121 ;
}
F_16 ( V_4 ) ;
V_200:
F_144 ( V_20 ) ;
return V_154 ;
}
static int F_146 ( struct V_3 * V_4 , int V_110 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
switch ( V_16 -> V_111 -> V_110 ) {
case V_181 :
case V_120 :
case V_224 :
case V_230 :
return 0 ;
default:
return - V_121 ;
}
}
static int F_147 ( struct V_3 * V_4 , int V_110 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
int V_39 = V_4 -> V_35 -> V_36 ( V_4 , V_243 , NULL ) ;
if ( V_39 < 0 )
return V_39 ;
V_16 -> V_244 = 0 ;
V_16 -> V_245 = V_16 -> V_111 -> V_179 -
V_16 -> V_111 -> V_179 % V_16 -> V_109 ;
V_16 -> V_246 = V_16 -> V_111 -> V_179 ;
V_16 -> V_247 = 0 ;
return 0 ;
}
static void F_148 ( struct V_3 * V_4 , int V_110 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
V_16 -> V_143 -> V_178 = V_16 -> V_111 -> V_179 ;
if ( V_4 -> V_23 == V_159 &&
V_16 -> V_148 > 0 )
F_85 ( V_4 , V_160 ) ;
}
static int F_149 ( struct V_3 * V_4 )
{
return F_111 ( & V_248 , V_4 , 0 ) ;
}
static int F_150 ( struct V_3 * V_4 ,
int V_249 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
if ( V_16 -> V_111 -> V_110 == V_118 ||
V_16 -> V_111 -> V_110 == V_112 )
return - V_121 ;
if ( F_84 ( V_4 ) )
return - V_231 ;
V_4 -> V_249 = V_249 ;
return 0 ;
}
static int F_151 ( struct V_3 * V_4 , int V_110 )
{
int V_39 ;
V_39 = V_4 -> V_35 -> V_250 ( V_4 ) ;
if ( V_39 < 0 )
return V_39 ;
return F_147 ( V_4 , 0 ) ;
}
static void F_152 ( struct V_3 * V_4 , int V_110 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
V_16 -> V_143 -> V_178 = V_16 -> V_111 -> V_179 ;
F_59 ( V_4 , V_120 ) ;
}
static int F_153 ( struct V_3 * V_4 ,
struct V_251 * V_251 )
{
int V_188 ;
struct V_240 * V_20 = V_4 -> V_5 -> V_20 ;
int V_249 ;
if ( V_251 )
V_249 = V_251 -> V_249 ;
else
V_249 = V_4 -> V_249 ;
F_142 ( V_20 ) ;
if ( ( V_188 = F_143 ( V_20 , V_241 ) ) >= 0 )
V_188 = F_111 ( & V_252 ,
V_4 , V_249 ) ;
F_144 ( V_20 ) ;
return V_188 ;
}
static int F_154 ( struct V_3 * V_4 , int V_110 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
switch ( V_16 -> V_111 -> V_110 ) {
case V_118 :
case V_112 :
case V_230 :
return - V_121 ;
}
V_16 -> V_192 = V_4 ;
return 0 ;
}
static int F_155 ( struct V_3 * V_4 , int V_110 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
if ( V_4 -> V_23 == V_159 ) {
switch ( V_16 -> V_111 -> V_110 ) {
case V_120 :
if ( ! F_156 ( V_4 ) ) {
F_115 ( V_4 , V_182 ) ;
F_117 ( V_4 , V_182 ) ;
} else {
V_16 -> V_111 -> V_110 = V_119 ;
}
break;
case V_181 :
V_16 -> V_111 -> V_110 = V_182 ;
break;
case V_220 :
V_16 -> V_111 -> V_110 = V_119 ;
break;
default:
break;
}
} else {
if ( V_16 -> V_111 -> V_110 == V_181 ) {
int V_253 = F_95 ( V_16 ) > 0 ?
V_182 : V_119 ;
F_120 ( V_4 , V_253 ) ;
F_121 ( V_4 , V_253 ) ;
}
}
if ( V_16 -> V_111 -> V_110 == V_182 &&
V_16 -> V_192 == V_4 &&
( V_16 -> V_43 . V_14 & V_101 ) )
return V_4 -> V_35 -> V_206 ( V_4 ,
V_254 ) ;
return 0 ;
}
static void F_157 ( struct V_3 * V_4 , int V_110 )
{
}
static int F_158 ( struct V_3 * V_4 ,
struct V_251 * V_251 )
{
struct V_240 * V_20 ;
struct V_15 * V_16 ;
struct V_3 * V_196 ;
T_5 V_255 ;
int V_154 = 0 ;
int V_256 = 0 ;
V_20 = V_4 -> V_5 -> V_20 ;
V_16 = V_4 -> V_16 ;
if ( V_16 -> V_111 -> V_110 == V_118 )
return - V_121 ;
F_142 ( V_20 ) ;
if ( V_16 -> V_111 -> V_110 == V_230 ) {
V_154 = F_143 ( V_20 , V_241 ) ;
if ( V_154 < 0 ) {
F_144 ( V_20 ) ;
return V_154 ;
}
}
if ( V_251 ) {
if ( V_251 -> V_249 & V_257 )
V_256 = 1 ;
} else if ( V_4 -> V_249 & V_257 )
V_256 = 1 ;
F_112 ( & V_7 ) ;
F_14 ( V_4 ) ;
if ( V_16 -> V_111 -> V_110 == V_224 )
F_131 ( V_4 , 0 ) ;
V_154 = F_106 ( & V_258 , V_4 , 0 ) ;
if ( V_154 < 0 )
goto V_259;
if ( V_256 ) {
V_154 = - V_260 ;
goto V_259;
}
for (; ; ) {
long V_261 ;
struct V_15 * V_262 ;
if ( F_159 ( V_263 ) ) {
V_154 = - V_264 ;
break;
}
V_262 = NULL ;
F_102 (s, substream) {
if ( V_196 -> V_23 != V_159 )
continue;
V_16 = V_196 -> V_16 ;
if ( V_16 -> V_111 -> V_110 == V_182 ) {
V_262 = V_16 ;
break;
}
}
if ( ! V_262 )
break;
F_160 ( & V_255 , V_263 ) ;
F_161 ( & V_262 -> V_216 , & V_255 ) ;
F_16 ( V_4 ) ;
F_11 ( & V_7 ) ;
F_144 ( V_20 ) ;
if ( V_16 -> V_133 )
V_261 = V_265 ;
else {
V_261 = 10 ;
if ( V_16 -> V_108 ) {
long V_266 = V_16 -> V_109 * 2 / V_16 -> V_108 ;
V_261 = V_89 ( V_266 , V_261 ) ;
}
V_261 = F_162 ( V_261 * 1000 ) ;
}
V_261 = F_163 ( V_261 ) ;
F_142 ( V_20 ) ;
F_112 ( & V_7 ) ;
F_14 ( V_4 ) ;
F_164 ( & V_262 -> V_216 , & V_255 ) ;
if ( V_20 -> V_267 ) {
V_154 = - V_268 ;
break;
}
if ( V_261 == 0 ) {
if ( V_4 -> V_16 -> V_111 -> V_110 == V_230 )
V_154 = - V_269 ;
else {
F_165 ( V_4 -> V_5 -> V_20 -> V_52 ,
L_12 ) ;
F_123 ( V_4 , V_119 ) ;
V_154 = - V_270 ;
}
break;
}
}
V_259:
F_16 ( V_4 ) ;
F_11 ( & V_7 ) ;
F_144 ( V_20 ) ;
return V_154 ;
}
static int F_166 ( struct V_3 * V_4 )
{
struct V_15 * V_16 ;
int V_154 = 0 ;
if ( F_63 ( V_4 ) )
return - V_117 ;
V_16 = V_4 -> V_16 ;
if ( V_16 -> V_111 -> V_110 == V_118 ||
V_16 -> V_111 -> V_110 == V_112 ||
V_16 -> V_111 -> V_110 == V_230 )
return - V_121 ;
F_14 ( V_4 ) ;
if ( V_16 -> V_111 -> V_110 == V_224 )
F_131 ( V_4 , 0 ) ;
F_123 ( V_4 , V_119 ) ;
F_16 ( V_4 ) ;
return V_154 ;
}
static bool F_167 ( struct V_251 * V_251 )
{
struct V_271 * V_271 = F_168 ( V_251 ) ;
unsigned int V_272 ;
if ( ! F_169 ( V_271 -> V_273 ) || F_170 ( V_271 ) != V_274 )
return false ;
V_272 = F_171 ( V_271 ) ;
return F_172 ( V_272 , V_275 ) ||
F_172 ( V_272 , V_276 ) ;
}
static int F_173 ( struct V_3 * V_4 , int V_277 )
{
int V_188 = 0 ;
struct V_278 * V_279 ;
struct V_3 * V_280 ;
struct V_281 * V_204 ;
struct V_277 V_282 = F_174 ( V_277 ) ;
if ( ! V_282 . V_251 )
return - V_121 ;
if ( ! F_167 ( V_282 . V_251 ) ) {
V_188 = - V_121 ;
goto V_283;
}
V_279 = V_282 . V_251 -> V_284 ;
V_280 = V_279 -> V_4 ;
V_204 = F_30 ( sizeof( * V_204 ) , V_40 ) ;
if ( ! V_204 ) {
V_188 = - V_41 ;
goto V_285;
}
F_1 ( & V_7 ) ;
F_175 ( & V_11 ) ;
if ( V_4 -> V_16 -> V_111 -> V_110 == V_118 ||
V_4 -> V_16 -> V_111 -> V_110 != V_280 -> V_16 -> V_111 -> V_110 ||
V_4 -> V_5 -> V_6 != V_280 -> V_5 -> V_6 ) {
V_188 = - V_121 ;
goto V_171;
}
if ( F_107 ( V_280 ) ) {
V_188 = - V_286 ;
goto V_171;
}
if ( ! F_107 ( V_4 ) ) {
V_4 -> V_204 = V_204 ;
V_204 = NULL ;
F_176 ( & V_4 -> V_204 -> V_2 ) ;
F_177 ( & V_4 -> V_204 -> V_10 ) ;
F_178 ( & V_4 -> V_204 -> V_287 ) ;
F_179 ( & V_4 -> V_288 , & V_4 -> V_204 -> V_287 ) ;
V_4 -> V_204 -> V_289 = 1 ;
}
F_179 ( & V_280 -> V_288 , & V_4 -> V_204 -> V_287 ) ;
V_4 -> V_204 -> V_289 ++ ;
V_280 -> V_204 = V_4 -> V_204 ;
V_171:
F_180 ( & V_11 ) ;
F_181 ( & V_7 ) ;
V_285:
F_182 ( V_280 -> V_5 -> V_20 ) ;
F_32 ( V_204 ) ;
V_283:
F_183 ( V_282 ) ;
return V_188 ;
}
static void F_184 ( struct V_3 * V_4 )
{
V_4 -> V_204 = & V_4 -> V_9 ;
F_178 ( & V_4 -> V_9 . V_287 ) ;
F_179 ( & V_4 -> V_288 , & V_4 -> V_9 . V_287 ) ;
}
static int F_185 ( struct V_3 * V_4 )
{
struct V_3 * V_196 ;
int V_188 = 0 ;
F_1 ( & V_7 ) ;
F_175 ( & V_11 ) ;
if ( ! F_107 ( V_4 ) ) {
V_188 = - V_286 ;
goto V_171;
}
F_186 ( & V_4 -> V_288 ) ;
V_4 -> V_204 -> V_289 -- ;
if ( V_4 -> V_204 -> V_289 == 1 ) {
F_102 (s, substream) {
F_184 ( V_196 ) ;
break;
}
F_32 ( V_4 -> V_204 ) ;
}
F_184 ( V_4 ) ;
V_171:
F_180 ( & V_11 ) ;
F_181 ( & V_7 ) ;
return V_188 ;
}
static int F_187 ( struct V_54 * V_55 ,
struct V_91 * V_290 )
{
struct V_58 V_266 ;
F_188 ( F_189 ( V_55 , V_290 -> V_97 [ 0 ] ) ,
F_189 ( V_55 , V_290 -> V_97 [ 1 ] ) , & V_266 ) ;
return F_45 ( F_43 ( V_55 , V_290 -> V_99 ) , & V_266 ) ;
}
static int F_190 ( struct V_54 * V_55 ,
struct V_91 * V_290 )
{
struct V_58 V_266 ;
F_191 ( F_189 ( V_55 , V_290 -> V_97 [ 0 ] ) ,
F_189 ( V_55 , V_290 -> V_97 [ 1 ] ) , & V_266 ) ;
return F_45 ( F_43 ( V_55 , V_290 -> V_99 ) , & V_266 ) ;
}
static int F_192 ( struct V_54 * V_55 ,
struct V_91 * V_290 )
{
struct V_58 V_266 ;
F_193 ( F_189 ( V_55 , V_290 -> V_97 [ 0 ] ) ,
F_189 ( V_55 , V_290 -> V_97 [ 1 ] ) ,
( unsigned long ) V_290 -> V_291 , & V_266 ) ;
return F_45 ( F_43 ( V_55 , V_290 -> V_99 ) , & V_266 ) ;
}
static int F_194 ( struct V_54 * V_55 ,
struct V_91 * V_290 )
{
struct V_58 V_266 ;
F_195 ( F_189 ( V_55 , V_290 -> V_97 [ 0 ] ) ,
( unsigned long ) V_290 -> V_291 ,
F_189 ( V_55 , V_290 -> V_97 [ 1 ] ) , & V_266 ) ;
return F_45 ( F_43 ( V_55 , V_290 -> V_99 ) , & V_266 ) ;
}
static int F_196 ( struct V_54 * V_55 ,
struct V_91 * V_290 )
{
unsigned int V_56 ;
struct V_58 * V_59 = F_43 ( V_55 , V_290 -> V_97 [ 0 ] ) ;
struct V_60 V_61 ;
struct V_60 * V_292 = F_36 ( V_55 , V_103 ) ;
F_197 ( & V_61 ) ;
for ( V_56 = 0 ; V_56 <= V_293 ; ++ V_56 ) {
int V_83 ;
if ( ! F_198 ( V_292 , V_56 ) )
continue;
V_83 = F_75 ( V_56 ) ;
if ( V_83 <= 0 )
continue;
if ( ( unsigned ) V_83 < V_59 -> V_88 || ( unsigned ) V_83 > V_59 -> V_89 )
F_199 ( & V_61 , V_56 ) ;
}
return F_41 ( V_292 , & V_61 ) ;
}
static int F_200 ( struct V_54 * V_55 ,
struct V_91 * V_290 )
{
struct V_58 V_266 ;
unsigned int V_56 ;
V_266 . V_88 = V_294 ;
V_266 . V_89 = 0 ;
V_266 . V_87 = 0 ;
V_266 . V_90 = 0 ;
for ( V_56 = 0 ; V_56 <= V_293 ; ++ V_56 ) {
int V_83 ;
if ( ! F_198 ( F_36 ( V_55 , V_103 ) , V_56 ) )
continue;
V_83 = F_75 ( V_56 ) ;
if ( V_83 <= 0 )
continue;
if ( V_266 . V_88 > ( unsigned ) V_83 )
V_266 . V_88 = V_83 ;
if ( V_266 . V_89 < ( unsigned ) V_83 )
V_266 . V_89 = V_83 ;
}
V_266 . integer = 1 ;
return F_45 ( F_43 ( V_55 , V_290 -> V_99 ) , & V_266 ) ;
}
static int F_201 ( struct V_54 * V_55 ,
struct V_91 * V_290 )
{
struct V_57 * V_43 = V_290 -> V_291 ;
return F_202 ( F_43 ( V_55 , V_290 -> V_99 ) ,
V_295 . V_289 ,
V_295 . V_296 , V_43 -> V_297 ) ;
}
static int F_203 ( struct V_54 * V_55 ,
struct V_91 * V_290 )
{
struct V_58 V_266 ;
struct V_3 * V_4 = V_290 -> V_291 ;
V_266 . V_88 = 0 ;
V_266 . V_89 = V_4 -> V_298 ;
V_266 . V_87 = 0 ;
V_266 . V_90 = 0 ;
V_266 . integer = 1 ;
return F_45 ( F_43 ( V_55 , V_290 -> V_99 ) , & V_266 ) ;
}
int F_204 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_62 * V_63 = & V_16 -> V_64 ;
int V_56 , V_39 ;
for ( V_56 = V_79 ; V_56 <= V_80 ; V_56 ++ ) {
F_197 ( F_42 ( V_63 , V_56 ) ) ;
}
for ( V_56 = V_85 ; V_56 <= V_68 ; V_56 ++ ) {
F_205 ( F_46 ( V_63 , V_56 ) ) ;
}
F_206 ( F_46 ( V_63 , V_104 ) ) ;
F_206 ( F_46 ( V_63 , V_299 ) ) ;
F_206 ( F_46 ( V_63 , V_300 ) ) ;
F_206 ( F_46 ( V_63 , V_74 ) ) ;
F_206 ( F_46 ( V_63 , V_301 ) ) ;
V_39 = F_207 ( V_16 , 0 , V_103 ,
F_196 , NULL ,
V_74 , - 1 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_207 ( V_16 , 0 , V_74 ,
F_200 , NULL ,
V_103 ,
V_74 , - 1 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_207 ( V_16 , 0 , V_74 ,
F_190 , NULL ,
V_301 , V_104 , - 1 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_207 ( V_16 , 0 , V_301 ,
F_187 , NULL ,
V_74 , V_104 , - 1 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_207 ( V_16 , 0 , V_301 ,
F_194 , ( void * ) 8 ,
V_302 , V_303 , - 1 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_207 ( V_16 , 0 , V_301 ,
F_194 , ( void * ) 8 ,
V_300 , V_299 , - 1 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_207 ( V_16 , 0 , V_104 ,
F_190 , NULL ,
V_301 , V_74 , - 1 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_207 ( V_16 , 0 , V_76 ,
F_194 , ( void * ) 1000000 ,
V_303 , V_304 , - 1 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_207 ( V_16 , 0 , V_76 ,
F_194 , ( void * ) 1000000 ,
V_299 , V_305 , - 1 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_207 ( V_16 , 0 , V_306 ,
F_190 , NULL ,
V_299 , V_303 , - 1 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_207 ( V_16 , 0 , V_303 ,
F_190 , NULL ,
V_299 , V_306 , - 1 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_207 ( V_16 , 0 , V_303 ,
F_194 , ( void * ) 8 ,
V_302 , V_301 , - 1 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_207 ( V_16 , 0 , V_303 ,
F_192 , ( void * ) 1000000 ,
V_304 , V_76 , - 1 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_207 ( V_16 , 0 , V_299 ,
F_187 , NULL ,
V_303 , V_306 , - 1 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_207 ( V_16 , 0 , V_299 ,
F_194 , ( void * ) 8 ,
V_300 , V_301 , - 1 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_207 ( V_16 , 0 , V_299 ,
F_192 , ( void * ) 1000000 ,
V_305 , V_76 , - 1 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_207 ( V_16 , 0 , V_302 ,
F_192 , ( void * ) 8 ,
V_303 , V_301 , - 1 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_207 ( V_16 , 0 , V_300 ,
F_192 , ( void * ) 8 ,
V_299 , V_301 , - 1 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_207 ( V_16 , 0 , V_304 ,
F_194 , ( void * ) 1000000 ,
V_303 , V_76 , - 1 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_207 ( V_16 , 0 , V_305 ,
F_194 , ( void * ) 1000000 ,
V_299 , V_76 , - 1 ) ;
if ( V_39 < 0 )
return V_39 ;
return 0 ;
}
int F_208 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_57 * V_43 = & V_16 -> V_43 ;
int V_39 ;
unsigned int V_292 = 0 ;
if ( V_43 -> V_14 & V_307 )
V_292 |= 1 << V_308 ;
if ( V_43 -> V_14 & V_309 )
V_292 |= 1 << V_310 ;
if ( F_33 ( V_4 ) ) {
if ( V_43 -> V_14 & V_307 )
V_292 |= 1 << V_311 ;
if ( V_43 -> V_14 & V_309 )
V_292 |= 1 << V_312 ;
if ( V_43 -> V_14 & V_313 )
V_292 |= 1 << V_314 ;
}
V_39 = F_209 ( V_16 , V_315 , V_292 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_210 ( V_16 , V_103 , V_43 -> V_316 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_209 ( V_16 , V_317 , 1 << V_318 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_211 ( V_16 , V_104 ,
V_43 -> V_319 , V_43 -> V_320 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_211 ( V_16 , V_76 ,
V_43 -> V_321 , V_43 -> V_322 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_211 ( V_16 , V_302 ,
V_43 -> V_323 , V_43 -> V_324 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_211 ( V_16 , V_306 ,
V_43 -> V_325 , V_43 -> V_326 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_211 ( V_16 , V_300 ,
V_43 -> V_323 , V_43 -> V_298 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_207 ( V_16 , 0 , V_300 ,
F_203 , V_4 ,
V_300 , - 1 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_16 -> V_327 ) {
V_39 = F_211 ( V_16 , V_300 , 0 , V_16 -> V_327 ) ;
if ( V_39 < 0 )
return V_39 ;
}
if ( ! ( V_43 -> V_297 & ( V_328 | V_329 ) ) ) {
V_39 = F_207 ( V_16 , 0 , V_76 ,
F_201 , V_43 ,
V_76 , - 1 ) ;
if ( V_39 < 0 )
return V_39 ;
}
F_212 ( V_16 , V_303 ) ;
return 0 ;
}
static void F_213 ( struct V_3 * V_4 )
{
F_185 ( V_4 ) ;
}
void F_214 ( struct V_3 * V_4 )
{
V_4 -> V_330 -- ;
if ( V_4 -> V_330 > 0 )
return;
F_166 ( V_4 ) ;
if ( V_4 -> V_331 ) {
if ( V_4 -> V_35 -> V_153 &&
V_4 -> V_16 -> V_111 -> V_110 != V_118 )
V_4 -> V_35 -> V_153 ( V_4 ) ;
V_4 -> V_35 -> V_332 ( V_4 ) ;
V_4 -> V_331 = 0 ;
}
if ( F_77 ( & V_4 -> V_151 ) )
F_78 ( & V_4 -> V_151 ) ;
if ( V_4 -> V_333 ) {
V_4 -> V_333 ( V_4 ) ;
V_4 -> V_333 = NULL ;
}
F_215 ( V_4 ) ;
}
int F_216 ( struct V_17 * V_5 , int V_23 ,
struct V_251 * V_251 ,
struct V_3 * * V_334 )
{
struct V_3 * V_4 ;
int V_39 ;
V_39 = F_217 ( V_5 , V_23 , V_251 , & V_4 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_4 -> V_330 > 1 ) {
* V_334 = V_4 ;
return 0 ;
}
V_39 = F_204 ( V_4 ) ;
if ( V_39 < 0 ) {
F_218 ( V_5 , L_13 ) ;
goto error;
}
if ( ( V_39 = V_4 -> V_35 -> V_335 ( V_4 ) ) < 0 )
goto error;
V_4 -> V_331 = 1 ;
V_39 = F_208 ( V_4 ) ;
if ( V_39 < 0 ) {
F_218 ( V_5 , L_14 ) ;
goto error;
}
* V_334 = V_4 ;
return 0 ;
error:
F_214 ( V_4 ) ;
return V_39 ;
}
static int F_219 ( struct V_251 * V_251 ,
struct V_17 * V_5 ,
int V_23 )
{
struct V_278 * V_279 ;
struct V_3 * V_4 ;
int V_39 ;
V_39 = F_216 ( V_5 , V_23 , V_251 , & V_4 ) ;
if ( V_39 < 0 )
return V_39 ;
V_279 = F_220 ( sizeof( * V_279 ) , V_40 ) ;
if ( V_279 == NULL ) {
F_214 ( V_4 ) ;
return - V_41 ;
}
V_279 -> V_4 = V_4 ;
if ( V_4 -> V_330 == 1 ) {
V_4 -> V_251 = V_279 ;
V_4 -> V_333 = F_213 ;
}
V_251 -> V_284 = V_279 ;
return 0 ;
}
static int F_221 ( struct V_271 * V_271 , struct V_251 * V_251 )
{
struct V_17 * V_5 ;
int V_39 = F_222 ( V_271 , V_251 ) ;
if ( V_39 < 0 )
return V_39 ;
V_5 = F_172 ( F_171 ( V_271 ) ,
V_275 ) ;
V_39 = F_223 ( V_251 , V_5 , V_159 ) ;
if ( V_5 )
F_182 ( V_5 -> V_20 ) ;
return V_39 ;
}
static int F_224 ( struct V_271 * V_271 , struct V_251 * V_251 )
{
struct V_17 * V_5 ;
int V_39 = F_222 ( V_271 , V_251 ) ;
if ( V_39 < 0 )
return V_39 ;
V_5 = F_172 ( F_171 ( V_271 ) ,
V_276 ) ;
V_39 = F_223 ( V_251 , V_5 , V_336 ) ;
if ( V_5 )
F_182 ( V_5 -> V_20 ) ;
return V_39 ;
}
static int F_223 ( struct V_251 * V_251 , struct V_17 * V_5 , int V_23 )
{
int V_39 ;
T_5 V_255 ;
if ( V_5 == NULL ) {
V_39 = - V_268 ;
goto V_337;
}
V_39 = F_225 ( V_5 -> V_20 , V_251 ) ;
if ( V_39 < 0 )
goto V_337;
if ( ! F_226 ( V_5 -> V_20 -> V_338 ) ) {
V_39 = - V_42 ;
goto V_339;
}
F_160 ( & V_255 , V_263 ) ;
F_161 ( & V_5 -> V_340 , & V_255 ) ;
F_6 ( & V_5 -> V_341 ) ;
while ( 1 ) {
V_39 = F_219 ( V_251 , V_5 , V_23 ) ;
if ( V_39 >= 0 )
break;
if ( V_39 == - V_260 ) {
if ( V_251 -> V_249 & V_257 ) {
V_39 = - V_231 ;
break;
}
} else
break;
F_227 ( V_342 ) ;
F_10 ( & V_5 -> V_341 ) ;
F_228 () ;
F_6 ( & V_5 -> V_341 ) ;
if ( V_5 -> V_20 -> V_267 ) {
V_39 = - V_268 ;
break;
}
if ( F_159 ( V_263 ) ) {
V_39 = - V_264 ;
break;
}
}
F_164 ( & V_5 -> V_340 , & V_255 ) ;
F_10 ( & V_5 -> V_341 ) ;
if ( V_39 < 0 )
goto V_343;
return V_39 ;
V_343:
F_229 ( V_5 -> V_20 -> V_338 ) ;
V_339:
F_230 ( V_5 -> V_20 , V_251 ) ;
V_337:
return V_39 ;
}
static int F_231 ( struct V_271 * V_271 , struct V_251 * V_251 )
{
struct V_17 * V_5 ;
struct V_3 * V_4 ;
struct V_278 * V_279 ;
V_279 = V_251 -> V_284 ;
V_4 = V_279 -> V_4 ;
if ( F_232 ( ! V_4 ) )
return - V_117 ;
V_5 = V_4 -> V_5 ;
F_6 ( & V_5 -> V_341 ) ;
F_214 ( V_4 ) ;
F_32 ( V_279 ) ;
F_10 ( & V_5 -> V_341 ) ;
F_122 ( & V_5 -> V_340 ) ;
F_229 ( V_5 -> V_20 -> V_338 ) ;
F_230 ( V_5 -> V_20 , V_251 ) ;
return 0 ;
}
static T_6 F_233 ( struct V_3 * V_4 ,
T_3 V_116 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
T_6 V_178 ;
T_6 V_219 ;
T_6 V_344 ;
if ( V_116 == 0 )
return 0 ;
F_14 ( V_4 ) ;
switch ( V_16 -> V_111 -> V_110 ) {
case V_120 :
break;
case V_182 :
case V_181 :
if ( F_91 ( V_4 ) >= 0 )
break;
case V_220 :
V_219 = - V_205 ;
goto V_345;
case V_230 :
V_219 = - V_269 ;
goto V_345;
default:
V_219 = - V_121 ;
goto V_345;
}
V_344 = F_234 ( V_16 ) ;
if ( V_344 <= 0 ) {
V_219 = 0 ;
goto V_345;
}
if ( V_116 > ( T_3 ) V_344 )
V_116 = V_344 ;
V_178 = V_16 -> V_143 -> V_178 - V_116 ;
if ( V_178 < 0 )
V_178 += V_16 -> V_149 ;
V_16 -> V_143 -> V_178 = V_178 ;
V_219 = V_116 ;
V_345:
F_16 ( V_4 ) ;
return V_219 ;
}
static T_6 F_235 ( struct V_3 * V_4 ,
T_3 V_116 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
T_6 V_178 ;
T_6 V_219 ;
T_6 V_344 ;
if ( V_116 == 0 )
return 0 ;
F_14 ( V_4 ) ;
switch ( V_16 -> V_111 -> V_110 ) {
case V_120 :
case V_182 :
break;
case V_181 :
if ( F_91 ( V_4 ) >= 0 )
break;
case V_220 :
V_219 = - V_205 ;
goto V_345;
case V_230 :
V_219 = - V_269 ;
goto V_345;
default:
V_219 = - V_121 ;
goto V_345;
}
V_344 = F_236 ( V_16 ) ;
if ( V_344 <= 0 ) {
V_219 = 0 ;
goto V_345;
}
if ( V_116 > ( T_3 ) V_344 )
V_116 = V_344 ;
V_178 = V_16 -> V_143 -> V_178 - V_116 ;
if ( V_178 < 0 )
V_178 += V_16 -> V_149 ;
V_16 -> V_143 -> V_178 = V_178 ;
V_219 = V_116 ;
V_345:
F_16 ( V_4 ) ;
return V_219 ;
}
static T_6 F_237 ( struct V_3 * V_4 ,
T_3 V_116 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
T_6 V_178 ;
T_6 V_219 ;
T_6 V_180 ;
if ( V_116 == 0 )
return 0 ;
F_14 ( V_4 ) ;
switch ( V_16 -> V_111 -> V_110 ) {
case V_120 :
case V_224 :
break;
case V_182 :
case V_181 :
if ( F_91 ( V_4 ) >= 0 )
break;
case V_220 :
V_219 = - V_205 ;
goto V_345;
case V_230 :
V_219 = - V_269 ;
goto V_345;
default:
V_219 = - V_121 ;
goto V_345;
}
V_180 = F_94 ( V_16 ) ;
if ( V_180 <= 0 ) {
V_219 = 0 ;
goto V_345;
}
if ( V_116 > ( T_3 ) V_180 )
V_116 = V_180 ;
V_178 = V_16 -> V_143 -> V_178 + V_116 ;
if ( V_178 >= ( T_6 ) V_16 -> V_149 )
V_178 -= V_16 -> V_149 ;
V_16 -> V_143 -> V_178 = V_178 ;
V_219 = V_116 ;
V_345:
F_16 ( V_4 ) ;
return V_219 ;
}
static T_6 F_238 ( struct V_3 * V_4 ,
T_3 V_116 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
T_6 V_178 ;
T_6 V_219 ;
T_6 V_180 ;
if ( V_116 == 0 )
return 0 ;
F_14 ( V_4 ) ;
switch ( V_16 -> V_111 -> V_110 ) {
case V_120 :
case V_182 :
case V_224 :
break;
case V_181 :
if ( F_91 ( V_4 ) >= 0 )
break;
case V_220 :
V_219 = - V_205 ;
goto V_345;
case V_230 :
V_219 = - V_269 ;
goto V_345;
default:
V_219 = - V_121 ;
goto V_345;
}
V_180 = F_95 ( V_16 ) ;
if ( V_180 <= 0 ) {
V_219 = 0 ;
goto V_345;
}
if ( V_116 > ( T_3 ) V_180 )
V_116 = V_180 ;
V_178 = V_16 -> V_143 -> V_178 + V_116 ;
if ( V_178 >= ( T_6 ) V_16 -> V_149 )
V_178 -= V_16 -> V_149 ;
V_16 -> V_143 -> V_178 = V_178 ;
V_219 = V_116 ;
V_345:
F_16 ( V_4 ) ;
return V_219 ;
}
static int F_239 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
int V_39 ;
F_14 ( V_4 ) ;
switch ( V_16 -> V_111 -> V_110 ) {
case V_182 :
if ( V_4 -> V_23 == V_336 )
goto V_346;
case V_181 :
if ( ( V_39 = F_91 ( V_4 ) ) < 0 )
break;
case V_120 :
case V_230 :
V_39 = 0 ;
break;
case V_220 :
V_39 = - V_205 ;
break;
default:
V_346:
V_39 = - V_121 ;
break;
}
F_16 ( V_4 ) ;
return V_39 ;
}
static int F_240 ( struct V_3 * V_4 ,
T_6 T_2 * V_188 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
int V_39 ;
T_6 V_347 = 0 ;
F_14 ( V_4 ) ;
switch ( V_16 -> V_111 -> V_110 ) {
case V_182 :
if ( V_4 -> V_23 == V_336 )
goto V_346;
case V_181 :
if ( ( V_39 = F_91 ( V_4 ) ) < 0 )
break;
case V_120 :
case V_230 :
V_39 = 0 ;
if ( V_4 -> V_23 == V_159 )
V_347 = F_234 ( V_16 ) ;
else
V_347 = F_95 ( V_16 ) ;
V_347 += V_16 -> V_183 ;
break;
case V_220 :
V_39 = - V_205 ;
break;
default:
V_346:
V_39 = - V_121 ;
break;
}
F_16 ( V_4 ) ;
if ( ! V_39 )
if ( F_241 ( V_347 , V_188 ) )
V_39 = - V_42 ;
return V_39 ;
}
static int F_242 ( struct V_3 * V_4 ,
struct F_242 T_2 * V_348 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct F_242 V_349 ;
volatile struct V_350 * V_111 ;
volatile struct V_351 * V_143 ;
int V_39 ;
memset ( & V_349 , 0 , sizeof( V_349 ) ) ;
if ( F_97 ( V_349 . V_12 , ( unsigned T_2 * ) & ( V_348 -> V_12 ) ) )
return - V_42 ;
if ( F_88 ( & V_349 . V_352 . V_143 , & ( V_348 -> V_352 . V_143 ) , sizeof( struct V_351 ) ) )
return - V_42 ;
V_111 = V_16 -> V_111 ;
V_143 = V_16 -> V_143 ;
if ( V_349 . V_12 & V_353 ) {
V_39 = F_239 ( V_4 ) ;
if ( V_39 < 0 )
return V_39 ;
}
F_14 ( V_4 ) ;
if ( ! ( V_349 . V_12 & V_354 ) )
V_143 -> V_178 = V_349 . V_352 . V_143 . V_178 ;
else
V_349 . V_352 . V_143 . V_178 = V_143 -> V_178 ;
if ( ! ( V_349 . V_12 & V_355 ) )
V_143 -> V_144 = V_349 . V_352 . V_143 . V_144 ;
else
V_349 . V_352 . V_143 . V_144 = V_143 -> V_144 ;
V_349 . V_196 . V_111 . V_110 = V_111 -> V_110 ;
V_349 . V_196 . V_111 . V_179 = V_111 -> V_179 ;
V_349 . V_196 . V_111 . V_173 = V_111 -> V_173 ;
V_349 . V_196 . V_111 . V_170 = V_111 -> V_170 ;
F_16 ( V_4 ) ;
if ( F_31 ( V_348 , & V_349 , sizeof( V_349 ) ) )
return - V_42 ;
return 0 ;
}
static int F_243 ( struct V_3 * V_4 , int T_2 * V_356 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
int V_357 ;
if ( F_97 ( V_357 , V_356 ) )
return - V_42 ;
if ( V_357 < 0 || V_357 > V_158 )
return - V_81 ;
V_16 -> V_157 = V_357 ;
return 0 ;
}
static int F_244 ( struct V_251 * V_251 ,
struct V_3 * V_4 ,
unsigned int V_358 , void T_2 * V_357 )
{
switch ( V_358 ) {
case V_359 :
return F_241 ( V_360 , ( int T_2 * ) V_357 ) ? - V_42 : 0 ;
case V_361 :
return F_29 ( V_4 , V_357 ) ;
case V_362 :
return 0 ;
case V_363 :
return F_243 ( V_4 , V_357 ) ;
case V_364 :
return F_54 ( V_4 , V_357 ) ;
case V_365 :
return F_80 ( V_4 , V_357 ) ;
case V_366 :
return F_81 ( V_4 ) ;
case V_367 :
return F_87 ( V_4 , V_357 ) ;
case V_368 :
return F_96 ( V_4 , V_357 , false ) ;
case V_369 :
return F_96 ( V_4 , V_357 , true ) ;
case V_370 :
return F_99 ( V_4 , V_357 ) ;
case V_371 :
return F_153 ( V_4 , V_251 ) ;
case V_372 :
return F_149 ( V_4 ) ;
case V_373 :
return F_110 ( & V_214 , V_4 , V_181 ) ;
case V_374 :
return F_173 ( V_4 , ( int ) ( unsigned long ) V_357 ) ;
case V_375 :
return F_185 ( V_4 ) ;
case V_376 :
return F_141 ( V_4 ) ;
case V_377 :
return F_145 ( V_4 ) ;
case V_378 :
return F_239 ( V_4 ) ;
case V_379 :
return F_240 ( V_4 , V_357 ) ;
case V_380 :
return F_242 ( V_4 , V_357 ) ;
#ifdef F_245
case V_381 :
return F_246 ( V_4 , V_357 ) ;
case V_382 :
return F_247 ( V_4 , V_357 ) ;
#endif
case V_383 :
return F_158 ( V_4 , V_251 ) ;
case V_384 :
return F_166 ( V_4 ) ;
case V_385 :
{
int V_188 ;
F_14 ( V_4 ) ;
V_188 = F_131 ( V_4 , ( int ) ( unsigned long ) V_357 ) ;
F_16 ( V_4 ) ;
return V_188 ;
}
}
F_218 ( V_4 -> V_5 , L_15 , V_358 ) ;
return - V_386 ;
}
static int F_248 ( struct V_251 * V_251 ,
struct V_3 * V_4 ,
unsigned int V_358 , void T_2 * V_357 )
{
if ( F_232 ( ! V_4 ) )
return - V_117 ;
if ( F_232 ( V_4 -> V_23 != V_159 ) )
return - V_81 ;
switch ( V_358 ) {
case V_387 :
{
struct V_388 V_389 ;
struct V_388 T_2 * V_390 = V_357 ;
struct V_15 * V_16 = V_4 -> V_16 ;
T_6 V_154 ;
if ( V_16 -> V_111 -> V_110 == V_118 )
return - V_121 ;
if ( F_241 ( 0 , & V_390 -> V_154 ) )
return - V_42 ;
if ( F_88 ( & V_389 , V_390 , sizeof( V_389 ) ) )
return - V_42 ;
V_154 = F_249 ( V_4 , V_389 . V_391 , V_389 . V_116 ) ;
F_250 ( V_154 , & V_390 -> V_154 ) ;
return V_154 < 0 ? V_154 : 0 ;
}
case V_392 :
{
struct V_393 V_394 ;
struct V_393 T_2 * V_395 = V_357 ;
struct V_15 * V_16 = V_4 -> V_16 ;
void T_2 * * V_396 ;
T_6 V_154 ;
if ( V_16 -> V_111 -> V_110 == V_118 )
return - V_121 ;
if ( V_16 -> V_130 > 128 )
return - V_81 ;
if ( F_241 ( 0 , & V_395 -> V_154 ) )
return - V_42 ;
if ( F_88 ( & V_394 , V_395 , sizeof( V_394 ) ) )
return - V_42 ;
V_396 = F_55 ( V_394 . V_396 ,
sizeof( void * ) * V_16 -> V_130 ) ;
if ( F_56 ( V_396 ) )
return F_57 ( V_396 ) ;
V_154 = F_251 ( V_4 , V_396 , V_394 . V_116 ) ;
F_32 ( V_396 ) ;
F_250 ( V_154 , & V_395 -> V_154 ) ;
return V_154 < 0 ? V_154 : 0 ;
}
case V_397 :
{
T_3 V_116 ;
T_3 T_2 * V_398 = V_357 ;
T_6 V_154 ;
if ( F_97 ( V_116 , V_398 ) )
return - V_42 ;
if ( F_241 ( 0 , V_398 ) )
return - V_42 ;
V_154 = F_233 ( V_4 , V_116 ) ;
F_250 ( V_154 , V_398 ) ;
return V_154 < 0 ? V_154 : 0 ;
}
case V_399 :
{
T_3 V_116 ;
T_3 T_2 * V_398 = V_357 ;
T_6 V_154 ;
if ( F_97 ( V_116 , V_398 ) )
return - V_42 ;
if ( F_241 ( 0 , V_398 ) )
return - V_42 ;
V_154 = F_237 ( V_4 , V_116 ) ;
F_250 ( V_154 , V_398 ) ;
return V_154 < 0 ? V_154 : 0 ;
}
}
return F_244 ( V_251 , V_4 , V_358 , V_357 ) ;
}
static int F_252 ( struct V_251 * V_251 ,
struct V_3 * V_4 ,
unsigned int V_358 , void T_2 * V_357 )
{
if ( F_232 ( ! V_4 ) )
return - V_117 ;
if ( F_232 ( V_4 -> V_23 != V_336 ) )
return - V_81 ;
switch ( V_358 ) {
case V_400 :
{
struct V_388 V_389 ;
struct V_388 T_2 * V_390 = V_357 ;
struct V_15 * V_16 = V_4 -> V_16 ;
T_6 V_154 ;
if ( V_16 -> V_111 -> V_110 == V_118 )
return - V_121 ;
if ( F_241 ( 0 , & V_390 -> V_154 ) )
return - V_42 ;
if ( F_88 ( & V_389 , V_390 , sizeof( V_389 ) ) )
return - V_42 ;
V_154 = F_253 ( V_4 , V_389 . V_391 , V_389 . V_116 ) ;
F_250 ( V_154 , & V_390 -> V_154 ) ;
return V_154 < 0 ? V_154 : 0 ;
}
case V_401 :
{
struct V_393 V_394 ;
struct V_393 T_2 * V_395 = V_357 ;
struct V_15 * V_16 = V_4 -> V_16 ;
void * V_396 ;
T_6 V_154 ;
if ( V_16 -> V_111 -> V_110 == V_118 )
return - V_121 ;
if ( V_16 -> V_130 > 128 )
return - V_81 ;
if ( F_241 ( 0 , & V_395 -> V_154 ) )
return - V_42 ;
if ( F_88 ( & V_394 , V_395 , sizeof( V_394 ) ) )
return - V_42 ;
V_396 = F_55 ( V_394 . V_396 ,
sizeof( void * ) * V_16 -> V_130 ) ;
if ( F_56 ( V_396 ) )
return F_57 ( V_396 ) ;
V_154 = F_254 ( V_4 , V_396 , V_394 . V_116 ) ;
F_32 ( V_396 ) ;
F_250 ( V_154 , & V_395 -> V_154 ) ;
return V_154 < 0 ? V_154 : 0 ;
}
case V_397 :
{
T_3 V_116 ;
T_3 T_2 * V_398 = V_357 ;
T_6 V_154 ;
if ( F_97 ( V_116 , V_398 ) )
return - V_42 ;
if ( F_241 ( 0 , V_398 ) )
return - V_42 ;
V_154 = F_235 ( V_4 , V_116 ) ;
F_250 ( V_154 , V_398 ) ;
return V_154 < 0 ? V_154 : 0 ;
}
case V_399 :
{
T_3 V_116 ;
T_3 T_2 * V_398 = V_357 ;
T_6 V_154 ;
if ( F_97 ( V_116 , V_398 ) )
return - V_42 ;
if ( F_241 ( 0 , V_398 ) )
return - V_42 ;
V_154 = F_238 ( V_4 , V_116 ) ;
F_250 ( V_154 , V_398 ) ;
return V_154 < 0 ? V_154 : 0 ;
}
}
return F_244 ( V_251 , V_4 , V_358 , V_357 ) ;
}
static long F_255 ( struct V_251 * V_251 , unsigned int V_358 ,
unsigned long V_357 )
{
struct V_278 * V_279 ;
V_279 = V_251 -> V_284 ;
if ( ( ( V_358 >> 8 ) & 0xff ) != 'A' )
return - V_386 ;
return F_248 ( V_251 , V_279 -> V_4 , V_358 ,
( void T_2 * ) V_357 ) ;
}
static long F_256 ( struct V_251 * V_251 , unsigned int V_358 ,
unsigned long V_357 )
{
struct V_278 * V_279 ;
V_279 = V_251 -> V_284 ;
if ( ( ( V_358 >> 8 ) & 0xff ) != 'A' )
return - V_386 ;
return F_252 ( V_251 , V_279 -> V_4 , V_358 ,
( void T_2 * ) V_357 ) ;
}
int F_257 ( struct V_3 * V_4 ,
unsigned int V_358 , void * V_357 )
{
T_1 V_13 ;
int V_154 ;
V_13 = F_22 () ;
switch ( V_4 -> V_23 ) {
case V_159 :
V_154 = F_248 ( NULL , V_4 , V_358 ,
( void T_2 * ) V_357 ) ;
break;
case V_336 :
V_154 = F_252 ( NULL , V_4 , V_358 ,
( void T_2 * ) V_357 ) ;
break;
default:
V_154 = - V_81 ;
break;
}
F_26 ( V_13 ) ;
return V_154 ;
}
static T_7 F_258 ( struct V_251 * V_251 , char T_2 * V_391 , T_8 V_289 ,
T_9 * V_402 )
{
struct V_278 * V_279 ;
struct V_3 * V_4 ;
struct V_15 * V_16 ;
T_6 V_154 ;
V_279 = V_251 -> V_284 ;
V_4 = V_279 -> V_4 ;
if ( F_63 ( V_4 ) )
return - V_117 ;
V_16 = V_4 -> V_16 ;
if ( V_16 -> V_111 -> V_110 == V_118 )
return - V_121 ;
if ( ! F_259 ( V_16 , V_289 ) )
return - V_81 ;
V_289 = F_260 ( V_16 , V_289 ) ;
V_154 = F_253 ( V_4 , V_391 , V_289 ) ;
if ( V_154 > 0 )
V_154 = F_261 ( V_16 , V_154 ) ;
return V_154 ;
}
static T_7 F_262 ( struct V_251 * V_251 , const char T_2 * V_391 ,
T_8 V_289 , T_9 * V_402 )
{
struct V_278 * V_279 ;
struct V_3 * V_4 ;
struct V_15 * V_16 ;
T_6 V_154 ;
V_279 = V_251 -> V_284 ;
V_4 = V_279 -> V_4 ;
if ( F_63 ( V_4 ) )
return - V_117 ;
V_16 = V_4 -> V_16 ;
if ( V_16 -> V_111 -> V_110 == V_118 )
return - V_121 ;
if ( ! F_259 ( V_16 , V_289 ) )
return - V_81 ;
V_289 = F_260 ( V_16 , V_289 ) ;
V_154 = F_249 ( V_4 , V_391 , V_289 ) ;
if ( V_154 > 0 )
V_154 = F_261 ( V_16 , V_154 ) ;
return V_154 ;
}
static T_7 F_263 ( struct V_403 * V_404 , struct V_405 * V_406 )
{
struct V_278 * V_279 ;
struct V_3 * V_4 ;
struct V_15 * V_16 ;
T_6 V_154 ;
unsigned long V_59 ;
void T_2 * * V_396 ;
T_3 V_116 ;
V_279 = V_404 -> V_407 -> V_284 ;
V_4 = V_279 -> V_4 ;
if ( F_63 ( V_4 ) )
return - V_117 ;
V_16 = V_4 -> V_16 ;
if ( V_16 -> V_111 -> V_110 == V_118 )
return - V_121 ;
if ( ! F_264 ( V_406 ) )
return - V_81 ;
if ( V_406 -> V_408 > 1024 || V_406 -> V_408 != V_16 -> V_130 )
return - V_81 ;
if ( ! F_259 ( V_16 , V_406 -> V_409 -> V_410 ) )
return - V_81 ;
V_116 = F_265 ( V_16 , V_406 -> V_409 -> V_410 ) ;
V_396 = F_30 ( sizeof( void * ) * V_406 -> V_408 , V_40 ) ;
if ( V_396 == NULL )
return - V_41 ;
for ( V_59 = 0 ; V_59 < V_406 -> V_408 ; ++ V_59 )
V_396 [ V_59 ] = V_406 -> V_409 [ V_59 ] . V_411 ;
V_154 = F_254 ( V_4 , V_396 , V_116 ) ;
if ( V_154 > 0 )
V_154 = F_261 ( V_16 , V_154 ) ;
F_32 ( V_396 ) ;
return V_154 ;
}
static T_7 F_266 ( struct V_403 * V_404 , struct V_405 * V_412 )
{
struct V_278 * V_279 ;
struct V_3 * V_4 ;
struct V_15 * V_16 ;
T_6 V_154 ;
unsigned long V_59 ;
void T_2 * * V_396 ;
T_3 V_116 ;
V_279 = V_404 -> V_407 -> V_284 ;
V_4 = V_279 -> V_4 ;
if ( F_63 ( V_4 ) )
return - V_117 ;
V_16 = V_4 -> V_16 ;
if ( V_16 -> V_111 -> V_110 == V_118 )
return - V_121 ;
if ( ! F_264 ( V_412 ) )
return - V_81 ;
if ( V_412 -> V_408 > 128 || V_412 -> V_408 != V_16 -> V_130 ||
! F_259 ( V_16 , V_412 -> V_409 -> V_410 ) )
return - V_81 ;
V_116 = F_265 ( V_16 , V_412 -> V_409 -> V_410 ) ;
V_396 = F_30 ( sizeof( void * ) * V_412 -> V_408 , V_40 ) ;
if ( V_396 == NULL )
return - V_41 ;
for ( V_59 = 0 ; V_59 < V_412 -> V_408 ; ++ V_59 )
V_396 [ V_59 ] = V_412 -> V_409 [ V_59 ] . V_411 ;
V_154 = F_251 ( V_4 , V_396 , V_116 ) ;
if ( V_154 > 0 )
V_154 = F_261 ( V_16 , V_154 ) ;
F_32 ( V_396 ) ;
return V_154 ;
}
static unsigned int F_267 ( struct V_251 * V_251 , T_10 * V_255 )
{
struct V_278 * V_279 ;
struct V_3 * V_4 ;
struct V_15 * V_16 ;
unsigned int V_292 ;
T_3 V_180 ;
V_279 = V_251 -> V_284 ;
V_4 = V_279 -> V_4 ;
if ( F_63 ( V_4 ) )
return - V_117 ;
V_16 = V_4 -> V_16 ;
F_268 ( V_251 , & V_16 -> V_216 , V_255 ) ;
F_14 ( V_4 ) ;
V_180 = F_94 ( V_16 ) ;
switch ( V_16 -> V_111 -> V_110 ) {
case V_181 :
case V_120 :
case V_224 :
if ( V_180 >= V_16 -> V_143 -> V_144 ) {
V_292 = V_413 | V_414 ;
break;
}
case V_182 :
V_292 = 0 ;
break;
default:
V_292 = V_413 | V_414 | V_415 ;
break;
}
F_16 ( V_4 ) ;
return V_292 ;
}
static unsigned int F_269 ( struct V_251 * V_251 , T_10 * V_255 )
{
struct V_278 * V_279 ;
struct V_3 * V_4 ;
struct V_15 * V_16 ;
unsigned int V_292 ;
T_3 V_180 ;
V_279 = V_251 -> V_284 ;
V_4 = V_279 -> V_4 ;
if ( F_63 ( V_4 ) )
return - V_117 ;
V_16 = V_4 -> V_16 ;
F_268 ( V_251 , & V_16 -> V_216 , V_255 ) ;
F_14 ( V_4 ) ;
V_180 = F_95 ( V_16 ) ;
switch ( V_16 -> V_111 -> V_110 ) {
case V_181 :
case V_120 :
case V_224 :
if ( V_180 >= V_16 -> V_143 -> V_144 ) {
V_292 = V_416 | V_417 ;
break;
}
V_292 = 0 ;
break;
case V_182 :
if ( V_180 > 0 ) {
V_292 = V_416 | V_417 ;
break;
}
default:
V_292 = V_416 | V_417 | V_415 ;
break;
}
F_16 ( V_4 ) ;
return V_292 ;
}
static int F_270 ( struct V_418 * V_419 ,
struct V_420 * V_421 )
{
struct V_3 * V_4 = V_419 -> V_422 ;
struct V_15 * V_16 ;
if ( V_4 == NULL )
return V_423 ;
V_16 = V_4 -> V_16 ;
V_421 -> V_424 = F_271 ( V_16 -> V_111 ) ;
F_272 ( V_421 -> V_424 ) ;
return 0 ;
}
static int V_350 ( struct V_3 * V_4 , struct V_251 * V_251 ,
struct V_418 * V_419 )
{
long V_425 ;
if ( ! ( V_419 -> V_426 & V_427 ) )
return - V_81 ;
V_425 = V_419 -> V_428 - V_419 -> V_429 ;
if ( V_425 != F_273 ( sizeof( struct V_350 ) ) )
return - V_81 ;
V_419 -> V_430 = & V_431 ;
V_419 -> V_422 = V_4 ;
V_419 -> V_426 |= V_432 | V_433 ;
return 0 ;
}
static int F_274 ( struct V_418 * V_419 ,
struct V_420 * V_421 )
{
struct V_3 * V_4 = V_419 -> V_422 ;
struct V_15 * V_16 ;
if ( V_4 == NULL )
return V_423 ;
V_16 = V_4 -> V_16 ;
V_421 -> V_424 = F_271 ( V_16 -> V_143 ) ;
F_272 ( V_421 -> V_424 ) ;
return 0 ;
}
static int V_351 ( struct V_3 * V_4 , struct V_251 * V_251 ,
struct V_418 * V_419 )
{
long V_425 ;
if ( ! ( V_419 -> V_426 & V_427 ) )
return - V_81 ;
V_425 = V_419 -> V_428 - V_419 -> V_429 ;
if ( V_425 != F_273 ( sizeof( struct V_351 ) ) )
return - V_81 ;
V_419 -> V_430 = & V_434 ;
V_419 -> V_422 = V_4 ;
V_419 -> V_426 |= V_432 | V_433 ;
return 0 ;
}
static int V_350 ( struct V_3 * V_4 , struct V_251 * V_251 ,
struct V_418 * V_419 )
{
return - V_117 ;
}
static int V_351 ( struct V_3 * V_4 , struct V_251 * V_251 ,
struct V_418 * V_419 )
{
return - V_117 ;
}
static inline struct V_424 *
F_275 ( struct V_3 * V_4 , unsigned long V_435 )
{
void * V_436 = V_4 -> V_16 -> V_437 + V_435 ;
return F_271 ( V_436 ) ;
}
static int F_276 ( struct V_418 * V_419 ,
struct V_420 * V_421 )
{
struct V_3 * V_4 = V_419 -> V_422 ;
struct V_15 * V_16 ;
unsigned long V_402 ;
struct V_424 * V_424 ;
T_8 V_327 ;
if ( V_4 == NULL )
return V_423 ;
V_16 = V_4 -> V_16 ;
V_402 = V_421 -> V_438 << V_439 ;
V_327 = F_273 ( V_16 -> V_327 ) ;
if ( V_402 > V_327 - V_440 )
return V_423 ;
if ( V_4 -> V_35 -> V_424 )
V_424 = V_4 -> V_35 -> V_424 ( V_4 , V_402 ) ;
else
V_424 = F_275 ( V_4 , V_402 ) ;
if ( ! V_424 )
return V_423 ;
F_272 ( V_424 ) ;
V_421 -> V_424 = V_424 ;
return 0 ;
}
int F_277 ( struct V_3 * V_4 ,
struct V_418 * V_419 )
{
V_419 -> V_426 |= V_432 | V_433 ;
#ifdef F_278
if ( V_4 -> V_51 . V_52 . type == V_441 ) {
V_419 -> V_442 = F_279 ( V_419 -> V_442 ) ;
return F_280 ( V_419 , V_419 -> V_429 ,
V_4 -> V_51 . V_443 >> V_439 ,
V_419 -> V_428 - V_419 -> V_429 , V_419 -> V_442 ) ;
}
#endif
#ifndef F_281
if ( ! V_4 -> V_35 -> V_424 &&
V_4 -> V_51 . V_52 . type == V_53 )
return F_282 ( V_4 -> V_51 . V_52 . V_52 ,
V_419 ,
V_4 -> V_16 -> V_437 ,
V_4 -> V_16 -> V_444 ,
V_419 -> V_428 - V_419 -> V_429 ) ;
#endif
V_419 -> V_430 = & V_445 ;
return 0 ;
}
int F_283 ( struct V_3 * V_4 ,
struct V_418 * V_419 )
{
struct V_15 * V_16 = V_4 -> V_16 ; ;
V_419 -> V_442 = F_284 ( V_419 -> V_442 ) ;
return F_285 ( V_419 , V_16 -> V_444 , V_16 -> V_327 ) ;
}
int F_286 ( struct V_3 * V_4 , struct V_251 * V_251 ,
struct V_418 * V_419 )
{
struct V_15 * V_16 ;
long V_425 ;
unsigned long V_402 ;
T_8 V_327 ;
int V_39 ;
if ( V_4 -> V_23 == V_159 ) {
if ( ! ( V_419 -> V_426 & ( V_446 | V_427 ) ) )
return - V_81 ;
} else {
if ( ! ( V_419 -> V_426 & V_427 ) )
return - V_81 ;
}
V_16 = V_4 -> V_16 ;
if ( V_16 -> V_111 -> V_110 == V_118 )
return - V_121 ;
if ( ! ( V_16 -> V_14 & V_44 ) )
return - V_117 ;
if ( V_16 -> V_127 == V_308 ||
V_16 -> V_127 == V_310 )
return - V_81 ;
V_425 = V_419 -> V_428 - V_419 -> V_429 ;
V_402 = V_419 -> V_447 << V_439 ;
V_327 = F_273 ( V_16 -> V_327 ) ;
if ( ( T_8 ) V_425 > V_327 )
return - V_81 ;
if ( V_402 > V_327 - V_425 )
return - V_81 ;
V_419 -> V_430 = & V_448 ;
V_419 -> V_422 = V_4 ;
if ( V_4 -> V_35 -> V_50 )
V_39 = V_4 -> V_35 -> V_50 ( V_4 , V_419 ) ;
else
V_39 = F_277 ( V_4 , V_419 ) ;
if ( ! V_39 )
F_287 ( & V_4 -> V_124 ) ;
return V_39 ;
}
static int F_288 ( struct V_251 * V_251 , struct V_418 * V_419 )
{
struct V_278 * V_279 ;
struct V_3 * V_4 ;
unsigned long V_402 ;
V_279 = V_251 -> V_284 ;
V_4 = V_279 -> V_4 ;
if ( F_63 ( V_4 ) )
return - V_117 ;
V_402 = V_419 -> V_447 << V_439 ;
switch ( V_402 ) {
case V_449 :
if ( V_279 -> V_450 )
return - V_117 ;
return V_350 ( V_4 , V_251 , V_419 ) ;
case V_451 :
if ( V_279 -> V_450 )
return - V_117 ;
return V_351 ( V_4 , V_251 , V_419 ) ;
default:
return F_286 ( V_4 , V_251 , V_419 ) ;
}
return 0 ;
}
static int F_289 ( int V_277 , struct V_251 * V_251 , int V_452 )
{
struct V_278 * V_279 ;
struct V_3 * V_4 ;
struct V_15 * V_16 ;
V_279 = V_251 -> V_284 ;
V_4 = V_279 -> V_4 ;
if ( F_63 ( V_4 ) )
return - V_117 ;
V_16 = V_4 -> V_16 ;
return F_290 ( V_277 , V_251 , V_452 , & V_16 -> V_453 ) ;
}
static void F_291 ( struct V_54 * V_55 ,
struct V_454 * V_455 )
{
unsigned int V_59 ;
memset ( V_55 , 0 , sizeof( * V_55 ) ) ;
V_55 -> V_12 = V_455 -> V_12 ;
for ( V_59 = 0 ; V_59 < F_292 ( V_455 -> V_456 ) ; V_59 ++ )
V_55 -> V_456 [ V_59 ] . V_83 [ 0 ] = V_455 -> V_456 [ V_59 ] ;
memcpy ( V_55 -> V_457 , V_455 -> V_457 , sizeof( V_455 -> V_457 ) ) ;
V_55 -> V_73 = F_293 ( V_455 -> V_73 ) ;
V_55 -> V_84 = F_293 ( V_455 -> V_84 ) ;
V_55 -> V_14 = V_455 -> V_14 ;
V_55 -> V_75 = V_455 -> V_75 ;
V_55 -> V_77 = V_455 -> V_77 ;
V_55 -> V_78 = V_455 -> V_78 ;
V_55 -> V_72 = V_455 -> V_72 ;
}
static void F_294 ( struct V_454 * V_455 ,
struct V_54 * V_55 )
{
unsigned int V_59 ;
memset ( V_455 , 0 , sizeof( * V_455 ) ) ;
V_455 -> V_12 = V_55 -> V_12 ;
for ( V_59 = 0 ; V_59 < F_292 ( V_455 -> V_456 ) ; V_59 ++ )
V_455 -> V_456 [ V_59 ] = V_55 -> V_456 [ V_59 ] . V_83 [ 0 ] ;
memcpy ( V_455 -> V_457 , V_55 -> V_457 , sizeof( V_455 -> V_457 ) ) ;
V_455 -> V_73 = F_295 ( V_55 -> V_73 ) ;
V_455 -> V_84 = F_295 ( V_55 -> V_84 ) ;
V_455 -> V_14 = V_55 -> V_14 ;
V_455 -> V_75 = V_55 -> V_75 ;
V_455 -> V_77 = V_55 -> V_77 ;
V_455 -> V_78 = V_55 -> V_78 ;
V_455 -> V_72 = V_55 -> V_72 ;
}
static int F_246 ( struct V_3 * V_4 ,
struct V_454 T_2 * V_458 )
{
struct V_54 * V_55 ;
struct V_454 * V_455 = NULL ;
int V_39 ;
V_55 = F_30 ( sizeof( * V_55 ) , V_40 ) ;
if ( ! V_55 )
return - V_41 ;
V_455 = F_55 ( V_458 , sizeof( * V_455 ) ) ;
if ( F_56 ( V_455 ) ) {
V_39 = F_57 ( V_455 ) ;
goto V_459;
}
F_291 ( V_55 , V_455 ) ;
V_39 = F_35 ( V_4 , V_55 ) ;
F_294 ( V_455 , V_55 ) ;
if ( F_31 ( V_458 , V_455 , sizeof( * V_455 ) ) ) {
if ( ! V_39 )
V_39 = - V_42 ;
}
F_32 ( V_455 ) ;
V_459:
F_32 ( V_55 ) ;
return V_39 ;
}
static int F_247 ( struct V_3 * V_4 ,
struct V_454 T_2 * V_458 )
{
struct V_54 * V_55 ;
struct V_454 * V_455 = NULL ;
int V_39 ;
V_55 = F_30 ( sizeof( * V_55 ) , V_40 ) ;
if ( ! V_55 )
return - V_41 ;
V_455 = F_55 ( V_458 , sizeof( * V_455 ) ) ;
if ( F_56 ( V_455 ) ) {
V_39 = F_57 ( V_455 ) ;
goto V_459;
}
F_291 ( V_55 , V_455 ) ;
V_39 = V_54 ( V_4 , V_55 ) ;
F_294 ( V_455 , V_55 ) ;
if ( F_31 ( V_458 , V_455 , sizeof( * V_455 ) ) ) {
if ( ! V_39 )
V_39 = - V_42 ;
}
F_32 ( V_455 ) ;
V_459:
F_32 ( V_55 ) ;
return V_39 ;
}
static unsigned long F_296 ( struct V_251 * V_251 ,
unsigned long V_443 ,
unsigned long V_460 ,
unsigned long V_438 ,
unsigned long V_12 )
{
struct V_278 * V_279 = V_251 -> V_284 ;
struct V_3 * V_4 = V_279 -> V_4 ;
struct V_15 * V_16 = V_4 -> V_16 ;
unsigned long V_402 = V_438 << V_439 ;
switch ( V_402 ) {
case V_449 :
return ( unsigned long ) V_16 -> V_111 ;
case V_451 :
return ( unsigned long ) V_16 -> V_143 ;
default:
return ( unsigned long ) V_16 -> V_437 + V_402 ;
}
}
