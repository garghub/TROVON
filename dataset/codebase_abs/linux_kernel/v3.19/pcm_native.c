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
V_53 -> V_12 = V_41 -> V_12 & ~ V_98 ;
if ( ! F_30 ( V_2 ) )
V_53 -> V_12 &= ~ ( V_42 |
V_99 ) ;
}
if ( ! V_53 -> V_70 ) {
V_59 = F_33 ( V_53 , V_100 ) ;
V_57 = F_40 ( V_53 , V_101 ) ;
if ( F_47 ( V_59 ) == F_48 ( V_59 ) &&
F_49 ( V_57 ) == F_50 ( V_57 ) ) {
V_68 = V_2 -> V_33 -> V_34 ( V_2 ,
V_102 , V_53 ) ;
if ( V_68 < 0 )
return V_68 ;
}
}
V_53 -> V_71 = 0 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_52 T_2 * V_103 )
{
struct V_52 * V_53 ;
int V_37 ;
V_53 = F_52 ( V_103 , sizeof( * V_53 ) ) ;
if ( F_53 ( V_53 ) )
return F_54 ( V_53 ) ;
V_37 = F_32 ( V_2 , V_53 ) ;
if ( F_28 ( V_103 , V_53 , sizeof( * V_53 ) ) ) {
if ( ! V_37 )
V_37 = - V_40 ;
}
F_29 ( V_53 ) ;
return V_37 ;
}
static int F_55 ( struct V_13 * V_14 )
{
int V_104 ;
if ( ! V_14 -> V_105 )
return - 1 ;
V_104 = ( 750000 / V_14 -> V_105 ) * V_14 -> V_106 ;
V_104 += ( ( 750000 % V_14 -> V_105 ) * V_14 -> V_106 ) /
V_14 -> V_105 ;
return V_104 ;
}
static void F_56 ( struct V_1 * V_2 , int V_107 )
{
F_11 ( V_2 ) ;
if ( V_2 -> V_14 -> V_108 -> V_107 != V_109 )
V_2 -> V_14 -> V_108 -> V_107 = V_107 ;
F_13 ( V_2 ) ;
}
static int V_52 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_13 * V_14 ;
int V_37 , V_104 ;
unsigned int V_81 ;
T_3 V_110 ;
if ( F_57 ( V_2 ) )
return - V_111 ;
V_14 = V_2 -> V_14 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_108 -> V_107 ) {
case V_112 :
case V_113 :
case V_114 :
break;
default:
F_13 ( V_2 ) ;
return - V_115 ;
}
F_13 ( V_2 ) ;
#if F_58 ( V_116 )
if ( ! V_2 -> V_117 . V_117 )
#endif
if ( F_59 ( & V_2 -> V_118 ) )
return - V_115 ;
V_53 -> V_71 = ~ 0U ;
V_37 = F_32 ( V_2 , V_53 ) ;
if ( V_37 < 0 )
goto V_119;
V_37 = F_60 ( V_2 , V_53 ) ;
if ( V_37 < 0 )
goto V_119;
if ( V_2 -> V_33 -> V_120 != NULL ) {
V_37 = V_2 -> V_33 -> V_120 ( V_2 , V_53 ) ;
if ( V_37 < 0 )
goto V_119;
}
V_14 -> V_121 = F_61 ( V_53 ) ;
V_14 -> V_122 = F_62 ( V_53 ) ;
V_14 -> V_123 = F_63 ( V_53 ) ;
V_14 -> V_124 = F_64 ( V_53 ) ;
V_14 -> V_105 = F_65 ( V_53 ) ;
V_14 -> V_106 = F_66 ( V_53 ) ;
V_14 -> V_125 = F_67 ( V_53 ) ;
V_14 -> V_126 = F_68 ( V_53 ) ;
V_14 -> V_12 = V_53 -> V_12 ;
V_14 -> V_75 = V_53 -> V_75 ;
V_14 -> V_76 = V_53 -> V_76 ;
V_14 -> V_127 =
( V_53 -> V_12 & V_128 ) &&
( V_53 -> V_10 & V_129 ) ;
V_81 = F_69 ( V_14 -> V_122 ) ;
V_14 -> V_130 = V_81 ;
V_81 *= V_14 -> V_124 ;
V_14 -> V_131 = V_81 ;
V_110 = 1 ;
while ( V_81 % 8 != 0 ) {
V_81 *= 2 ;
V_110 *= 2 ;
}
V_14 -> V_132 = V_81 / 8 ;
V_14 -> V_133 = V_110 ;
V_14 -> V_134 = V_135 ;
V_14 -> V_136 = 1 ;
V_14 -> V_137 -> V_138 = V_14 -> V_106 ;
V_14 -> V_139 = 1 ;
V_14 -> V_140 = V_14 -> V_126 ;
V_14 -> V_141 = 0 ;
V_14 -> V_142 = 0 ;
V_14 -> V_143 = V_14 -> V_126 ;
while ( V_14 -> V_143 * 2 <= V_144 - V_14 -> V_126 )
V_14 -> V_143 *= 2 ;
F_70 ( V_2 ) ;
F_56 ( V_2 , V_113 ) ;
if ( F_71 ( & V_2 -> V_145 ) )
F_72 ( & V_2 -> V_145 ) ;
if ( ( V_104 = F_55 ( V_14 ) ) >= 0 )
F_73 ( & V_2 -> V_145 ,
V_146 , V_104 ) ;
return 0 ;
V_119:
F_56 ( V_2 , V_112 ) ;
if ( V_2 -> V_33 -> V_147 != NULL )
V_2 -> V_33 -> V_147 ( V_2 ) ;
return V_37 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_52 T_2 * V_103 )
{
struct V_52 * V_53 ;
int V_37 ;
V_53 = F_52 ( V_103 , sizeof( * V_53 ) ) ;
if ( F_53 ( V_53 ) )
return F_54 ( V_53 ) ;
V_37 = V_52 ( V_2 , V_53 ) ;
if ( F_28 ( V_103 , V_53 , sizeof( * V_53 ) ) ) {
if ( ! V_37 )
V_37 = - V_40 ;
}
F_29 ( V_53 ) ;
return V_37 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
int V_148 = 0 ;
if ( F_57 ( V_2 ) )
return - V_111 ;
V_14 = V_2 -> V_14 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_108 -> V_107 ) {
case V_113 :
case V_114 :
break;
default:
F_13 ( V_2 ) ;
return - V_115 ;
}
F_13 ( V_2 ) ;
if ( F_59 ( & V_2 -> V_118 ) )
return - V_115 ;
if ( V_2 -> V_33 -> V_147 )
V_148 = V_2 -> V_33 -> V_147 ( V_2 ) ;
F_56 ( V_2 , V_112 ) ;
F_72 ( & V_2 -> V_145 ) ;
return V_148 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct F_76 * V_53 )
{
struct V_13 * V_14 ;
int V_37 ;
if ( F_57 ( V_2 ) )
return - V_111 ;
V_14 = V_2 -> V_14 ;
F_11 ( V_2 ) ;
if ( V_14 -> V_108 -> V_107 == V_112 ) {
F_13 ( V_2 ) ;
return - V_115 ;
}
F_13 ( V_2 ) ;
if ( V_53 -> V_134 > V_149 )
return - V_79 ;
if ( V_53 -> V_150 >= F_77 ( 2 , 0 , 12 ) &&
V_53 -> V_151 > V_152 )
return - V_79 ;
if ( V_53 -> V_138 == 0 )
return - V_79 ;
if ( V_53 -> V_142 >= V_14 -> V_143 ) {
if ( V_53 -> V_141 != 0 )
return - V_79 ;
} else {
if ( V_53 -> V_142 > V_53 -> V_141 )
return - V_79 ;
if ( V_53 -> V_141 > V_14 -> V_126 )
return - V_79 ;
}
V_37 = 0 ;
F_11 ( V_2 ) ;
V_14 -> V_134 = V_53 -> V_134 ;
if ( V_53 -> V_150 >= F_77 ( 2 , 0 , 12 ) )
V_14 -> V_151 = V_53 -> V_151 ;
V_14 -> V_136 = V_53 -> V_136 ;
V_14 -> V_137 -> V_138 = V_53 -> V_138 ;
V_14 -> V_139 = V_53 -> V_139 ;
V_14 -> V_140 = V_53 -> V_140 ;
V_14 -> V_141 = V_53 -> V_141 ;
V_14 -> V_142 = V_53 -> V_142 ;
V_53 -> V_143 = V_14 -> V_143 ;
if ( F_78 ( V_2 ) ) {
if ( V_2 -> V_21 == V_153 &&
V_14 -> V_142 > 0 )
F_79 ( V_2 , V_154 ) ;
V_37 = F_80 ( V_2 , V_14 ) ;
}
F_13 ( V_2 ) ;
return V_37 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct F_76 T_2 * V_103 )
{
struct F_76 V_53 ;
int V_37 ;
if ( F_82 ( & V_53 , V_103 , sizeof( V_53 ) ) )
return - V_40 ;
V_37 = F_76 ( V_2 , & V_53 ) ;
if ( F_28 ( V_103 , & V_53 , sizeof( V_53 ) ) )
return - V_40 ;
return V_37 ;
}
int F_83 ( struct V_1 * V_2 ,
struct F_83 * V_108 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_11 ( V_2 ) ;
V_108 -> V_107 = V_14 -> V_108 -> V_107 ;
V_108 -> V_155 = V_14 -> V_108 -> V_155 ;
if ( V_108 -> V_107 == V_112 )
goto V_156;
V_108 -> V_157 = V_14 -> V_157 ;
if ( F_78 ( V_2 ) ) {
F_84 ( V_2 ) ;
if ( V_14 -> V_134 == V_158 ) {
V_108 -> V_159 = V_14 -> V_108 -> V_159 ;
V_108 -> V_160 =
V_14 -> V_108 -> V_160 ;
goto V_161;
}
}
F_85 ( V_14 , & V_108 -> V_159 ) ;
V_161:
V_108 -> V_162 = V_14 -> V_137 -> V_162 ;
V_108 -> V_163 = V_14 -> V_108 -> V_163 ;
if ( V_2 -> V_21 == V_153 ) {
V_108 -> V_164 = F_86 ( V_14 ) ;
if ( V_14 -> V_108 -> V_107 == V_165 ||
V_14 -> V_108 -> V_107 == V_166 ) {
V_108 -> V_167 = V_14 -> V_126 - V_108 -> V_164 ;
V_108 -> V_167 += V_14 -> V_167 ;
} else
V_108 -> V_167 = 0 ;
} else {
V_108 -> V_164 = F_87 ( V_14 ) ;
if ( V_14 -> V_108 -> V_107 == V_165 )
V_108 -> V_167 = V_108 -> V_164 + V_14 -> V_167 ;
else
V_108 -> V_167 = 0 ;
}
V_108 -> V_168 = V_14 -> V_168 ;
V_108 -> V_169 = V_14 -> V_169 ;
V_14 -> V_168 = 0 ;
V_14 -> V_169 = 0 ;
V_156:
F_13 ( V_2 ) ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct F_83 T_2 * V_170 )
{
struct F_83 V_108 ;
int V_171 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_171 = F_83 ( V_2 , & V_108 ) ;
if ( V_171 < 0 )
return V_171 ;
if ( F_28 ( V_170 , & V_108 , sizeof( V_108 ) ) )
return - V_40 ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct F_89 * V_12 )
{
struct V_13 * V_14 ;
unsigned int V_172 ;
V_172 = V_12 -> V_172 ;
V_14 = V_2 -> V_14 ;
F_11 ( V_2 ) ;
if ( V_14 -> V_108 -> V_107 == V_112 ) {
F_13 ( V_2 ) ;
return - V_115 ;
}
F_13 ( V_2 ) ;
if ( V_172 >= V_14 -> V_124 )
return - V_79 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_172 = V_172 ;
return V_2 -> V_33 -> V_34 ( V_2 , V_173 , V_12 ) ;
}
static int F_90 ( struct V_1 * V_2 ,
struct F_89 T_2 * V_36 )
{
struct F_89 V_12 ;
int V_171 ;
if ( F_82 ( & V_12 , V_36 , sizeof( V_12 ) ) )
return - V_40 ;
V_171 = F_89 ( V_2 , & V_12 ) ;
if ( V_171 < 0 )
return V_171 ;
if ( F_28 ( V_36 , & V_12 , sizeof( V_12 ) ) )
return - V_40 ;
return 0 ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_174 == NULL )
return;
if ( V_14 -> V_174 == V_2 ) {
F_85 ( V_14 , & V_14 -> V_157 ) ;
} else {
F_91 ( V_14 -> V_174 ) ;
V_14 -> V_157 = V_14 -> V_174 -> V_14 -> V_157 ;
}
V_14 -> V_174 = NULL ;
}
static int F_92 ( struct V_175 * V_33 ,
struct V_1 * V_2 ,
int V_107 , int V_176 )
{
struct V_1 * V_177 = NULL ;
struct V_1 * V_178 ;
int V_171 = 0 , V_179 = 1 ;
F_93 (s, substream) {
if ( V_176 && V_177 != V_2 ) {
if ( V_177 -> V_3 -> V_4 )
F_94 ( & V_177 -> V_6 . V_7 , V_179 ) ;
else
F_95 ( & V_177 -> V_6 . V_9 , V_179 ) ;
V_179 ++ ;
}
V_171 = V_33 -> V_180 ( V_177 , V_107 ) ;
if ( V_171 < 0 )
goto V_181;
}
F_93 (s, substream) {
V_171 = V_33 -> V_182 ( V_177 , V_107 ) ;
if ( V_171 < 0 ) {
if ( V_33 -> V_183 ) {
F_93 (s1, substream) {
if ( V_178 == V_177 )
break;
V_33 -> V_183 ( V_178 , V_107 ) ;
}
}
V_177 = NULL ;
goto V_181;
}
}
F_93 (s, substream) {
V_33 -> V_184 ( V_177 , V_107 ) ;
}
V_181:
if ( V_176 ) {
F_93 (s1, substream) {
if ( V_178 != V_2 ) {
if ( V_178 -> V_3 -> V_4 )
F_7 ( & V_178 -> V_6 . V_7 ) ;
else
F_9 ( & V_178 -> V_6 . V_9 ) ;
}
if ( V_178 == V_177 )
break;
}
}
return V_171 ;
}
static int F_96 ( struct V_175 * V_33 ,
struct V_1 * V_2 ,
int V_107 )
{
int V_171 ;
V_171 = V_33 -> V_180 ( V_2 , V_107 ) ;
if ( V_171 < 0 )
return V_171 ;
V_171 = V_33 -> V_182 ( V_2 , V_107 ) ;
if ( V_171 == 0 )
V_33 -> V_184 ( V_2 , V_107 ) ;
else if ( V_33 -> V_183 )
V_33 -> V_183 ( V_2 , V_107 ) ;
return V_171 ;
}
static int F_97 ( struct V_175 * V_33 ,
struct V_1 * V_2 ,
int V_107 )
{
int V_171 ;
if ( ! F_98 ( V_2 ) )
return F_96 ( V_33 , V_2 , V_107 ) ;
if ( V_2 -> V_3 -> V_4 ) {
if ( ! F_99 ( & V_2 -> V_185 -> V_7 ) ) {
F_7 ( & V_2 -> V_6 . V_7 ) ;
F_3 ( & V_2 -> V_185 -> V_7 ) ;
F_3 ( & V_2 -> V_6 . V_7 ) ;
}
V_171 = F_92 ( V_33 , V_2 , V_107 , 1 ) ;
F_7 ( & V_2 -> V_185 -> V_7 ) ;
} else {
if ( ! F_100 ( & V_2 -> V_185 -> V_9 ) ) {
F_9 ( & V_2 -> V_6 . V_9 ) ;
F_5 ( & V_2 -> V_185 -> V_9 ) ;
F_5 ( & V_2 -> V_6 . V_9 ) ;
}
V_171 = F_92 ( V_33 , V_2 , V_107 , 1 ) ;
F_9 ( & V_2 -> V_185 -> V_9 ) ;
}
return V_171 ;
}
static int F_101 ( struct V_175 * V_33 ,
struct V_1 * V_2 ,
int V_107 )
{
int V_171 ;
F_11 ( V_2 ) ;
V_171 = F_97 ( V_33 , V_2 , V_107 ) ;
F_13 ( V_2 ) ;
return V_171 ;
}
static int F_102 ( struct V_175 * V_33 ,
struct V_1 * V_2 ,
int V_107 )
{
int V_171 ;
F_2 ( & V_5 ) ;
if ( F_98 ( V_2 ) )
V_171 = F_92 ( V_33 , V_2 , V_107 , 0 ) ;
else
V_171 = F_96 ( V_33 , V_2 , V_107 ) ;
F_8 ( & V_5 ) ;
return V_171 ;
}
static int F_103 ( struct V_1 * V_2 , int V_107 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_108 -> V_107 != V_114 )
return - V_115 ;
if ( V_2 -> V_21 == V_153 &&
! F_104 ( V_2 ) )
return - V_186 ;
V_14 -> V_174 = V_2 ;
return 0 ;
}
static int F_105 ( struct V_1 * V_2 , int V_107 )
{
if ( V_2 -> V_14 -> V_174 != V_2 )
return 0 ;
return V_2 -> V_33 -> V_187 ( V_2 , V_188 ) ;
}
static void F_106 ( struct V_1 * V_2 , int V_107 )
{
if ( V_2 -> V_14 -> V_174 == V_2 )
V_2 -> V_33 -> V_187 ( V_2 , V_189 ) ;
}
static void F_107 ( struct V_1 * V_2 , int V_107 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_91 ( V_2 ) ;
V_14 -> V_190 = V_191 ;
V_14 -> V_192 = ( V_14 -> V_126 * V_193 ) /
V_14 -> V_105 ;
V_14 -> V_108 -> V_107 = V_107 ;
if ( V_2 -> V_21 == V_153 &&
V_14 -> V_142 > 0 )
F_79 ( V_2 , V_154 ) ;
if ( V_2 -> V_194 )
F_108 ( V_2 -> V_194 , V_195 ,
& V_14 -> V_157 ) ;
}
int F_109 ( struct V_1 * V_2 )
{
return F_97 ( & V_196 , V_2 ,
V_165 ) ;
}
static int F_110 ( struct V_1 * V_2 , int V_107 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_108 -> V_107 == V_112 )
return - V_115 ;
V_14 -> V_174 = V_2 ;
return 0 ;
}
static int F_111 ( struct V_1 * V_2 , int V_107 )
{
if ( V_2 -> V_14 -> V_174 == V_2 &&
F_78 ( V_2 ) )
V_2 -> V_33 -> V_187 ( V_2 , V_189 ) ;
return 0 ;
}
static void F_112 ( struct V_1 * V_2 , int V_107 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_108 -> V_107 != V_107 ) {
F_91 ( V_2 ) ;
V_14 -> V_108 -> V_107 = V_107 ;
if ( V_2 -> V_194 )
F_108 ( V_2 -> V_194 , V_197 ,
& V_14 -> V_157 ) ;
}
F_113 ( & V_14 -> V_198 ) ;
F_113 ( & V_14 -> V_199 ) ;
}
int F_114 ( struct V_1 * V_2 , T_4 V_107 )
{
return F_97 ( & V_200 , V_2 , V_107 ) ;
}
int F_115 ( struct V_1 * V_2 )
{
return F_96 ( & V_200 , V_2 ,
V_113 ) ;
}
int F_116 ( struct V_1 * V_2 )
{
unsigned long V_10 ;
int V_201 = 0 ;
F_117 ( V_2 , V_10 ) ;
if ( F_78 ( V_2 ) )
V_201 = F_114 ( V_2 , V_202 ) ;
F_17 ( V_2 , V_10 ) ;
return V_201 ;
}
static int F_118 ( struct V_1 * V_2 , int V_203 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( ! ( V_14 -> V_12 & V_204 ) )
return - V_205 ;
if ( V_203 ) {
if ( V_14 -> V_108 -> V_107 != V_165 )
return - V_115 ;
} else if ( V_14 -> V_108 -> V_107 != V_206 )
return - V_115 ;
V_14 -> V_174 = V_2 ;
return 0 ;
}
static int F_119 ( struct V_1 * V_2 , int V_203 )
{
if ( V_2 -> V_14 -> V_174 != V_2 )
return 0 ;
if ( V_203 )
F_84 ( V_2 ) ;
V_2 -> V_14 -> V_190 = V_191 - V_193 * 1000 ;
return V_2 -> V_33 -> V_187 ( V_2 ,
V_203 ? V_207 :
V_208 ) ;
}
static void F_120 ( struct V_1 * V_2 , int V_203 )
{
if ( V_2 -> V_14 -> V_174 == V_2 )
V_2 -> V_33 -> V_187 ( V_2 ,
V_203 ? V_208 :
V_207 ) ;
}
static void F_121 ( struct V_1 * V_2 , int V_203 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_91 ( V_2 ) ;
if ( V_203 ) {
V_14 -> V_108 -> V_107 = V_206 ;
if ( V_2 -> V_194 )
F_108 ( V_2 -> V_194 ,
V_209 ,
& V_14 -> V_157 ) ;
F_113 ( & V_14 -> V_198 ) ;
F_113 ( & V_14 -> V_199 ) ;
} else {
V_14 -> V_108 -> V_107 = V_165 ;
if ( V_2 -> V_194 )
F_108 ( V_2 -> V_194 ,
V_210 ,
& V_14 -> V_157 ) ;
}
}
static int F_122 ( struct V_1 * V_2 , int V_203 )
{
return F_97 ( & V_211 , V_2 , V_203 ) ;
}
static int F_123 ( struct V_1 * V_2 , int V_107 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_108 -> V_107 == V_212 )
return - V_213 ;
V_14 -> V_174 = V_2 ;
return 0 ;
}
static int F_124 ( struct V_1 * V_2 , int V_107 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_174 != V_2 )
return 0 ;
if ( ! F_78 ( V_2 ) )
return 0 ;
V_2 -> V_33 -> V_187 ( V_2 , V_214 ) ;
return 0 ;
}
static void F_125 ( struct V_1 * V_2 , int V_107 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_91 ( V_2 ) ;
V_14 -> V_108 -> V_155 = V_14 -> V_108 -> V_107 ;
V_14 -> V_108 -> V_107 = V_212 ;
if ( V_2 -> V_194 )
F_108 ( V_2 -> V_194 , V_215 ,
& V_14 -> V_157 ) ;
F_113 ( & V_14 -> V_198 ) ;
F_113 ( & V_14 -> V_199 ) ;
}
int F_126 ( struct V_1 * V_2 )
{
int V_37 ;
unsigned long V_10 ;
if ( ! V_2 )
return 0 ;
F_117 ( V_2 , V_10 ) ;
V_37 = F_97 ( & V_216 , V_2 , 0 ) ;
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
for ( V_2 = V_3 -> V_217 [ V_21 ] . V_2 ;
V_2 ; V_2 = V_2 -> V_218 ) {
if ( V_2 -> V_14 == NULL )
continue;
V_37 = F_126 ( V_2 ) ;
if ( V_37 < 0 && V_37 != - V_213 )
return V_37 ;
}
}
return 0 ;
}
static int F_128 ( struct V_1 * V_2 , int V_107 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( ! ( V_14 -> V_12 & V_219 ) )
return - V_205 ;
V_14 -> V_174 = V_2 ;
return 0 ;
}
static int F_129 ( struct V_1 * V_2 , int V_107 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_174 != V_2 )
return 0 ;
if ( V_14 -> V_108 -> V_155 != V_165 &&
( V_14 -> V_108 -> V_155 != V_166 ||
V_2 -> V_21 != V_153 ) )
return 0 ;
return V_2 -> V_33 -> V_187 ( V_2 , V_220 ) ;
}
static void F_130 ( struct V_1 * V_2 , int V_107 )
{
if ( V_2 -> V_14 -> V_174 == V_2 &&
F_78 ( V_2 ) )
V_2 -> V_33 -> V_187 ( V_2 , V_214 ) ;
}
static void F_131 ( struct V_1 * V_2 , int V_107 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_91 ( V_2 ) ;
V_14 -> V_108 -> V_107 = V_14 -> V_108 -> V_155 ;
if ( V_2 -> V_194 )
F_108 ( V_2 -> V_194 , V_221 ,
& V_14 -> V_157 ) ;
}
static int F_132 ( struct V_1 * V_2 )
{
struct V_222 * V_18 = V_2 -> V_3 -> V_18 ;
int V_171 ;
F_133 ( V_18 ) ;
if ( ( V_171 = F_134 ( V_18 , V_223 ) ) >= 0 )
V_171 = F_101 ( & V_224 , V_2 , 0 ) ;
F_135 ( V_18 ) ;
return V_171 ;
}
static int F_132 ( struct V_1 * V_2 )
{
return - V_205 ;
}
static int F_136 ( struct V_1 * V_2 )
{
struct V_222 * V_18 = V_2 -> V_3 -> V_18 ;
struct V_13 * V_14 = V_2 -> V_14 ;
int V_148 ;
F_133 ( V_18 ) ;
if ( V_14 -> V_108 -> V_107 == V_212 ) {
V_148 = F_134 ( V_18 , V_223 ) ;
if ( V_148 < 0 )
goto V_181;
}
F_11 ( V_2 ) ;
switch ( V_14 -> V_108 -> V_107 ) {
case V_202 :
V_148 = 0 ;
break;
case V_165 :
V_148 = F_114 ( V_2 , V_202 ) ;
break;
default:
V_148 = - V_115 ;
}
F_13 ( V_2 ) ;
V_181:
F_135 ( V_18 ) ;
return V_148 ;
}
static int F_137 ( struct V_1 * V_2 , int V_107 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
switch ( V_14 -> V_108 -> V_107 ) {
case V_165 :
case V_114 :
case V_206 :
case V_212 :
return 0 ;
default:
return - V_115 ;
}
}
static int F_138 ( struct V_1 * V_2 , int V_107 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_37 = V_2 -> V_33 -> V_34 ( V_2 , V_225 , NULL ) ;
if ( V_37 < 0 )
return V_37 ;
V_14 -> V_226 = 0 ;
V_14 -> V_227 = V_14 -> V_108 -> V_163 -
V_14 -> V_108 -> V_163 % V_14 -> V_106 ;
V_14 -> V_228 = V_14 -> V_108 -> V_163 ;
V_14 -> V_229 = 0 ;
return 0 ;
}
static void F_139 ( struct V_1 * V_2 , int V_107 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
V_14 -> V_137 -> V_162 = V_14 -> V_108 -> V_163 ;
if ( V_2 -> V_21 == V_153 &&
V_14 -> V_142 > 0 )
F_79 ( V_2 , V_154 ) ;
}
static int F_140 ( struct V_1 * V_2 )
{
return F_102 ( & V_230 , V_2 , 0 ) ;
}
static int F_141 ( struct V_1 * V_2 ,
int V_231 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_108 -> V_107 == V_112 ||
V_14 -> V_108 -> V_107 == V_109 )
return - V_115 ;
if ( F_78 ( V_2 ) )
return - V_213 ;
V_2 -> V_231 = V_231 ;
return 0 ;
}
static int F_142 ( struct V_1 * V_2 , int V_107 )
{
int V_37 ;
V_37 = V_2 -> V_33 -> V_232 ( V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
return F_138 ( V_2 , 0 ) ;
}
static void F_143 ( struct V_1 * V_2 , int V_107 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
V_14 -> V_137 -> V_162 = V_14 -> V_108 -> V_163 ;
F_56 ( V_2 , V_114 ) ;
}
static int F_144 ( struct V_1 * V_2 ,
struct V_233 * V_233 )
{
int V_171 ;
struct V_222 * V_18 = V_2 -> V_3 -> V_18 ;
int V_231 ;
if ( V_233 )
V_231 = V_233 -> V_231 ;
else
V_231 = V_2 -> V_231 ;
F_133 ( V_18 ) ;
if ( ( V_171 = F_134 ( V_18 , V_223 ) ) >= 0 )
V_171 = F_102 ( & V_234 ,
V_2 , V_231 ) ;
F_135 ( V_18 ) ;
return V_171 ;
}
static int F_145 ( struct V_1 * V_2 , int V_107 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
switch ( V_14 -> V_108 -> V_107 ) {
case V_112 :
case V_109 :
case V_212 :
return - V_115 ;
}
V_14 -> V_174 = V_2 ;
return 0 ;
}
static int F_146 ( struct V_1 * V_2 , int V_107 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_2 -> V_21 == V_153 ) {
switch ( V_14 -> V_108 -> V_107 ) {
case V_114 :
if ( ! F_147 ( V_2 ) ) {
F_105 ( V_2 , V_166 ) ;
F_107 ( V_2 , V_166 ) ;
}
break;
case V_165 :
V_14 -> V_108 -> V_107 = V_166 ;
break;
case V_202 :
V_14 -> V_108 -> V_107 = V_113 ;
break;
default:
break;
}
} else {
if ( V_14 -> V_108 -> V_107 == V_165 ) {
int V_235 = F_87 ( V_14 ) > 0 ?
V_166 : V_113 ;
F_111 ( V_2 , V_235 ) ;
F_112 ( V_2 , V_235 ) ;
}
}
return 0 ;
}
static void F_148 ( struct V_1 * V_2 , int V_107 )
{
}
static int F_149 ( struct V_1 * V_2 ,
struct V_233 * V_233 )
{
struct V_222 * V_18 ;
struct V_13 * V_14 ;
struct V_1 * V_177 ;
T_5 V_236 ;
int V_148 = 0 ;
int V_237 = 0 ;
V_18 = V_2 -> V_3 -> V_18 ;
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_108 -> V_107 == V_112 )
return - V_115 ;
F_133 ( V_18 ) ;
if ( V_14 -> V_108 -> V_107 == V_212 ) {
V_148 = F_134 ( V_18 , V_223 ) ;
if ( V_148 < 0 ) {
F_135 ( V_18 ) ;
return V_148 ;
}
}
if ( V_233 ) {
if ( V_233 -> V_231 & V_238 )
V_237 = 1 ;
} else if ( V_2 -> V_231 & V_238 )
V_237 = 1 ;
F_2 ( & V_5 ) ;
F_11 ( V_2 ) ;
if ( V_14 -> V_108 -> V_107 == V_206 )
F_122 ( V_2 , 0 ) ;
V_148 = F_97 ( & V_239 , V_2 , 0 ) ;
if ( V_148 < 0 )
goto V_240;
if ( V_237 ) {
V_148 = - V_241 ;
goto V_240;
}
for (; ; ) {
long V_242 ;
struct V_13 * V_243 ;
if ( F_150 ( V_244 ) ) {
V_148 = - V_245 ;
break;
}
V_243 = NULL ;
F_93 (s, substream) {
if ( V_177 -> V_21 != V_153 )
continue;
V_14 = V_177 -> V_14 ;
if ( V_14 -> V_108 -> V_107 == V_166 ) {
V_243 = V_14 ;
break;
}
}
if ( ! V_243 )
break;
F_151 ( & V_236 , V_244 ) ;
F_152 ( & V_243 -> V_198 , & V_236 ) ;
F_13 ( V_2 ) ;
F_8 ( & V_5 ) ;
F_135 ( V_18 ) ;
if ( V_14 -> V_127 )
V_242 = V_246 ;
else {
V_242 = 10 ;
if ( V_14 -> V_105 ) {
long V_247 = V_14 -> V_106 * 2 / V_14 -> V_105 ;
V_242 = V_87 ( V_247 , V_242 ) ;
}
V_242 = F_153 ( V_242 * 1000 ) ;
}
V_242 = F_154 ( V_242 ) ;
F_133 ( V_18 ) ;
F_2 ( & V_5 ) ;
F_11 ( V_2 ) ;
F_155 ( & V_243 -> V_198 , & V_236 ) ;
if ( V_18 -> V_248 ) {
V_148 = - V_249 ;
break;
}
if ( V_242 == 0 ) {
if ( V_2 -> V_14 -> V_108 -> V_107 == V_212 )
V_148 = - V_250 ;
else {
F_156 ( V_2 -> V_3 -> V_18 -> V_50 ,
L_12 ) ;
F_114 ( V_2 , V_113 ) ;
V_148 = - V_251 ;
}
break;
}
}
V_240:
F_13 ( V_2 ) ;
F_8 ( & V_5 ) ;
F_135 ( V_18 ) ;
return V_148 ;
}
static int F_157 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
int V_148 = 0 ;
if ( F_57 ( V_2 ) )
return - V_111 ;
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_108 -> V_107 == V_112 ||
V_14 -> V_108 -> V_107 == V_109 ||
V_14 -> V_108 -> V_107 == V_212 )
return - V_115 ;
F_11 ( V_2 ) ;
if ( V_14 -> V_108 -> V_107 == V_206 )
F_122 ( V_2 , 0 ) ;
F_114 ( V_2 , V_113 ) ;
F_13 ( V_2 ) ;
return V_148 ;
}
static bool F_158 ( struct V_233 * V_233 )
{
struct V_252 * V_252 = F_159 ( V_233 ) ;
unsigned int V_253 ;
if ( ! F_160 ( V_252 -> V_254 ) || F_161 ( V_252 ) != V_255 )
return false ;
V_253 = F_162 ( V_252 ) ;
return F_163 ( V_253 , V_256 ) ||
F_163 ( V_253 , V_257 ) ;
}
static int F_164 ( struct V_1 * V_2 , int V_258 )
{
int V_171 = 0 ;
struct V_259 * V_260 ;
struct V_1 * V_261 ;
struct V_262 * V_185 ;
struct V_258 V_263 = F_165 ( V_258 ) ;
if ( ! V_263 . V_233 )
return - V_115 ;
if ( ! F_158 ( V_263 . V_233 ) ) {
V_171 = - V_115 ;
goto V_264;
}
V_260 = V_263 . V_233 -> V_265 ;
V_261 = V_260 -> V_2 ;
V_185 = F_27 ( sizeof( * V_185 ) , V_38 ) ;
if ( ! V_185 ) {
V_171 = - V_39 ;
goto V_266;
}
F_166 ( & V_5 ) ;
F_167 ( & V_8 ) ;
if ( V_2 -> V_14 -> V_108 -> V_107 == V_112 ||
V_2 -> V_14 -> V_108 -> V_107 != V_261 -> V_14 -> V_108 -> V_107 ||
V_2 -> V_3 -> V_4 != V_261 -> V_3 -> V_4 ) {
V_171 = - V_115 ;
goto V_156;
}
if ( F_98 ( V_261 ) ) {
V_171 = - V_267 ;
goto V_156;
}
if ( ! F_98 ( V_2 ) ) {
V_2 -> V_185 = V_185 ;
V_185 = NULL ;
F_168 ( & V_2 -> V_185 -> V_9 ) ;
F_169 ( & V_2 -> V_185 -> V_7 ) ;
F_170 ( & V_2 -> V_185 -> V_268 ) ;
F_171 ( & V_2 -> V_269 , & V_2 -> V_185 -> V_268 ) ;
V_2 -> V_185 -> V_270 = 1 ;
}
F_171 ( & V_261 -> V_269 , & V_2 -> V_185 -> V_268 ) ;
V_2 -> V_185 -> V_270 ++ ;
V_261 -> V_185 = V_2 -> V_185 ;
V_156:
F_172 ( & V_8 ) ;
F_173 ( & V_5 ) ;
V_266:
F_174 ( V_261 -> V_3 -> V_18 ) ;
F_29 ( V_185 ) ;
V_264:
F_175 ( V_263 ) ;
return V_171 ;
}
static void F_176 ( struct V_1 * V_2 )
{
V_2 -> V_185 = & V_2 -> V_6 ;
F_170 ( & V_2 -> V_6 . V_268 ) ;
F_171 ( & V_2 -> V_269 , & V_2 -> V_6 . V_268 ) ;
}
static int F_177 ( struct V_1 * V_2 )
{
struct V_1 * V_177 ;
int V_171 = 0 ;
F_166 ( & V_5 ) ;
F_167 ( & V_8 ) ;
if ( ! F_98 ( V_2 ) ) {
V_171 = - V_267 ;
goto V_156;
}
F_178 ( & V_2 -> V_269 ) ;
V_2 -> V_185 -> V_270 -- ;
if ( V_2 -> V_185 -> V_270 == 1 ) {
F_93 (s, substream) {
F_176 ( V_177 ) ;
break;
}
F_29 ( V_2 -> V_185 ) ;
}
F_176 ( V_2 ) ;
V_156:
F_172 ( & V_8 ) ;
F_173 ( & V_5 ) ;
return V_171 ;
}
static int F_179 ( struct V_52 * V_53 ,
struct V_89 * V_271 )
{
struct V_56 V_247 ;
F_180 ( F_181 ( V_53 , V_271 -> V_95 [ 0 ] ) ,
F_181 ( V_53 , V_271 -> V_95 [ 1 ] ) , & V_247 ) ;
return F_42 ( F_40 ( V_53 , V_271 -> V_97 ) , & V_247 ) ;
}
static int F_182 ( struct V_52 * V_53 ,
struct V_89 * V_271 )
{
struct V_56 V_247 ;
F_183 ( F_181 ( V_53 , V_271 -> V_95 [ 0 ] ) ,
F_181 ( V_53 , V_271 -> V_95 [ 1 ] ) , & V_247 ) ;
return F_42 ( F_40 ( V_53 , V_271 -> V_97 ) , & V_247 ) ;
}
static int F_184 ( struct V_52 * V_53 ,
struct V_89 * V_271 )
{
struct V_56 V_247 ;
F_185 ( F_181 ( V_53 , V_271 -> V_95 [ 0 ] ) ,
F_181 ( V_53 , V_271 -> V_95 [ 1 ] ) ,
( unsigned long ) V_271 -> V_272 , & V_247 ) ;
return F_42 ( F_40 ( V_53 , V_271 -> V_97 ) , & V_247 ) ;
}
static int F_186 ( struct V_52 * V_53 ,
struct V_89 * V_271 )
{
struct V_56 V_247 ;
F_187 ( F_181 ( V_53 , V_271 -> V_95 [ 0 ] ) ,
( unsigned long ) V_271 -> V_272 ,
F_181 ( V_53 , V_271 -> V_95 [ 1 ] ) , & V_247 ) ;
return F_42 ( F_40 ( V_53 , V_271 -> V_97 ) , & V_247 ) ;
}
static int F_188 ( struct V_52 * V_53 ,
struct V_89 * V_271 )
{
unsigned int V_54 ;
struct V_56 * V_57 = F_40 ( V_53 , V_271 -> V_95 [ 0 ] ) ;
struct V_58 V_59 ;
struct V_58 * V_273 = F_33 ( V_53 , V_100 ) ;
F_189 ( & V_59 ) ;
for ( V_54 = 0 ; V_54 <= V_274 ; ++ V_54 ) {
int V_81 ;
if ( ! F_190 ( V_273 , V_54 ) )
continue;
V_81 = F_69 ( V_54 ) ;
if ( V_81 <= 0 )
continue;
if ( ( unsigned ) V_81 < V_57 -> V_86 || ( unsigned ) V_81 > V_57 -> V_87 )
F_191 ( & V_59 , V_54 ) ;
}
return F_38 ( V_273 , & V_59 ) ;
}
static int F_192 ( struct V_52 * V_53 ,
struct V_89 * V_271 )
{
struct V_56 V_247 ;
unsigned int V_54 ;
V_247 . V_86 = V_275 ;
V_247 . V_87 = 0 ;
V_247 . V_85 = 0 ;
V_247 . V_88 = 0 ;
for ( V_54 = 0 ; V_54 <= V_274 ; ++ V_54 ) {
int V_81 ;
if ( ! F_190 ( F_33 ( V_53 , V_100 ) , V_54 ) )
continue;
V_81 = F_69 ( V_54 ) ;
if ( V_81 <= 0 )
continue;
if ( V_247 . V_86 > ( unsigned ) V_81 )
V_247 . V_86 = V_81 ;
if ( V_247 . V_87 < ( unsigned ) V_81 )
V_247 . V_87 = V_81 ;
}
V_247 . integer = 1 ;
return F_42 ( F_40 ( V_53 , V_271 -> V_97 ) , & V_247 ) ;
}
static int F_193 ( struct V_52 * V_53 ,
struct V_89 * V_271 )
{
struct V_55 * V_41 = V_271 -> V_272 ;
return F_194 ( F_40 ( V_53 , V_271 -> V_97 ) ,
V_276 . V_270 ,
V_276 . V_277 , V_41 -> V_278 ) ;
}
static int F_195 ( struct V_52 * V_53 ,
struct V_89 * V_271 )
{
struct V_56 V_247 ;
struct V_1 * V_2 = V_271 -> V_272 ;
V_247 . V_86 = 0 ;
V_247 . V_87 = V_2 -> V_279 ;
V_247 . V_85 = 0 ;
V_247 . V_88 = 0 ;
V_247 . integer = 1 ;
return F_42 ( F_40 ( V_53 , V_271 -> V_97 ) , & V_247 ) ;
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
F_198 ( F_43 ( V_61 , V_101 ) ) ;
F_198 ( F_43 ( V_61 , V_280 ) ) ;
F_198 ( F_43 ( V_61 , V_281 ) ) ;
F_198 ( F_43 ( V_61 , V_72 ) ) ;
F_198 ( F_43 ( V_61 , V_282 ) ) ;
V_37 = F_199 ( V_14 , 0 , V_100 ,
F_188 , NULL ,
V_72 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_72 ,
F_192 , NULL ,
V_100 ,
V_72 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_72 ,
F_182 , NULL ,
V_282 , V_101 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_282 ,
F_179 , NULL ,
V_72 , V_101 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_282 ,
F_186 , ( void * ) 8 ,
V_283 , V_284 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_282 ,
F_186 , ( void * ) 8 ,
V_281 , V_280 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_101 ,
F_182 , NULL ,
V_282 , V_72 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_74 ,
F_186 , ( void * ) 1000000 ,
V_284 , V_285 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_74 ,
F_186 , ( void * ) 1000000 ,
V_280 , V_286 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_287 ,
F_182 , NULL ,
V_280 , V_284 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_284 ,
F_182 , NULL ,
V_280 , V_287 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_284 ,
F_186 , ( void * ) 8 ,
V_283 , V_282 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_284 ,
F_184 , ( void * ) 1000000 ,
V_285 , V_74 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_280 ,
F_179 , NULL ,
V_284 , V_287 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_280 ,
F_186 , ( void * ) 8 ,
V_281 , V_282 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_280 ,
F_184 , ( void * ) 1000000 ,
V_286 , V_74 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_283 ,
F_184 , ( void * ) 8 ,
V_284 , V_282 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_281 ,
F_184 , ( void * ) 8 ,
V_280 , V_282 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_285 ,
F_186 , ( void * ) 1000000 ,
V_284 , V_74 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_286 ,
F_186 , ( void * ) 1000000 ,
V_280 , V_74 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
return 0 ;
}
int F_200 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_55 * V_41 = & V_14 -> V_41 ;
int V_37 ;
unsigned int V_273 = 0 ;
if ( V_41 -> V_12 & V_288 )
V_273 |= 1 << V_289 ;
if ( V_41 -> V_12 & V_290 )
V_273 |= 1 << V_291 ;
if ( F_30 ( V_2 ) ) {
if ( V_41 -> V_12 & V_288 )
V_273 |= 1 << V_292 ;
if ( V_41 -> V_12 & V_290 )
V_273 |= 1 << V_293 ;
if ( V_41 -> V_12 & V_294 )
V_273 |= 1 << V_295 ;
}
V_37 = F_201 ( V_14 , V_296 , V_273 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_202 ( V_14 , V_100 , V_41 -> V_297 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_201 ( V_14 , V_298 , 1 << V_299 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_203 ( V_14 , V_101 ,
V_41 -> V_300 , V_41 -> V_301 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_203 ( V_14 , V_74 ,
V_41 -> V_302 , V_41 -> V_303 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_203 ( V_14 , V_283 ,
V_41 -> V_304 , V_41 -> V_305 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_203 ( V_14 , V_287 ,
V_41 -> V_306 , V_41 -> V_307 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_203 ( V_14 , V_281 ,
V_41 -> V_304 , V_41 -> V_279 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_199 ( V_14 , 0 , V_281 ,
F_195 , V_2 ,
V_281 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_14 -> V_308 ) {
V_37 = F_203 ( V_14 , V_281 , 0 , V_14 -> V_308 ) ;
if ( V_37 < 0 )
return V_37 ;
}
if ( ! ( V_41 -> V_278 & ( V_309 | V_310 ) ) ) {
V_37 = F_199 ( V_14 , 0 , V_74 ,
F_193 , V_41 ,
V_74 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
}
F_204 ( V_14 , V_284 ) ;
return 0 ;
}
static void F_205 ( struct V_1 * V_2 )
{
F_177 ( V_2 ) ;
}
void F_206 ( struct V_1 * V_2 )
{
V_2 -> V_311 -- ;
if ( V_2 -> V_311 > 0 )
return;
F_157 ( V_2 ) ;
if ( V_2 -> V_312 ) {
if ( V_2 -> V_33 -> V_147 != NULL )
V_2 -> V_33 -> V_147 ( V_2 ) ;
V_2 -> V_33 -> V_313 ( V_2 ) ;
V_2 -> V_312 = 0 ;
}
if ( F_71 ( & V_2 -> V_145 ) )
F_72 ( & V_2 -> V_145 ) ;
if ( V_2 -> V_314 ) {
V_2 -> V_314 ( V_2 ) ;
V_2 -> V_314 = NULL ;
}
F_207 ( V_2 ) ;
}
int F_208 ( struct V_15 * V_3 , int V_21 ,
struct V_233 * V_233 ,
struct V_1 * * V_315 )
{
struct V_1 * V_2 ;
int V_37 ;
V_37 = F_209 ( V_3 , V_21 , V_233 , & V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_2 -> V_311 > 1 ) {
* V_315 = V_2 ;
return 0 ;
}
V_37 = F_196 ( V_2 ) ;
if ( V_37 < 0 ) {
F_210 ( V_3 , L_13 ) ;
goto error;
}
if ( ( V_37 = V_2 -> V_33 -> V_316 ( V_2 ) ) < 0 )
goto error;
V_2 -> V_312 = 1 ;
V_37 = F_200 ( V_2 ) ;
if ( V_37 < 0 ) {
F_210 ( V_3 , L_14 ) ;
goto error;
}
* V_315 = V_2 ;
return 0 ;
error:
F_206 ( V_2 ) ;
return V_37 ;
}
static int F_211 ( struct V_233 * V_233 ,
struct V_15 * V_3 ,
int V_21 )
{
struct V_259 * V_260 ;
struct V_1 * V_2 ;
int V_37 ;
V_37 = F_208 ( V_3 , V_21 , V_233 , & V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
V_260 = F_212 ( sizeof( * V_260 ) , V_38 ) ;
if ( V_260 == NULL ) {
F_206 ( V_2 ) ;
return - V_39 ;
}
V_260 -> V_2 = V_2 ;
if ( V_2 -> V_311 == 1 ) {
V_2 -> V_233 = V_260 ;
V_2 -> V_314 = F_205 ;
}
V_233 -> V_265 = V_260 ;
return 0 ;
}
static int F_213 ( struct V_252 * V_252 , struct V_233 * V_233 )
{
struct V_15 * V_3 ;
int V_37 = F_214 ( V_252 , V_233 ) ;
if ( V_37 < 0 )
return V_37 ;
V_3 = F_163 ( F_162 ( V_252 ) ,
V_256 ) ;
V_37 = F_215 ( V_233 , V_3 , V_153 ) ;
if ( V_3 )
F_174 ( V_3 -> V_18 ) ;
return V_37 ;
}
static int F_216 ( struct V_252 * V_252 , struct V_233 * V_233 )
{
struct V_15 * V_3 ;
int V_37 = F_214 ( V_252 , V_233 ) ;
if ( V_37 < 0 )
return V_37 ;
V_3 = F_163 ( F_162 ( V_252 ) ,
V_257 ) ;
V_37 = F_215 ( V_233 , V_3 , V_317 ) ;
if ( V_3 )
F_174 ( V_3 -> V_18 ) ;
return V_37 ;
}
static int F_215 ( struct V_233 * V_233 , struct V_15 * V_3 , int V_21 )
{
int V_37 ;
T_5 V_236 ;
if ( V_3 == NULL ) {
V_37 = - V_249 ;
goto V_318;
}
V_37 = F_217 ( V_3 -> V_18 , V_233 ) ;
if ( V_37 < 0 )
goto V_318;
if ( ! F_218 ( V_3 -> V_18 -> V_319 ) ) {
V_37 = - V_40 ;
goto V_320;
}
F_151 ( & V_236 , V_244 ) ;
F_152 ( & V_3 -> V_321 , & V_236 ) ;
F_3 ( & V_3 -> V_322 ) ;
while ( 1 ) {
V_37 = F_211 ( V_233 , V_3 , V_21 ) ;
if ( V_37 >= 0 )
break;
if ( V_37 == - V_241 ) {
if ( V_233 -> V_231 & V_238 ) {
V_37 = - V_213 ;
break;
}
} else
break;
F_219 ( V_323 ) ;
F_7 ( & V_3 -> V_322 ) ;
F_220 () ;
F_3 ( & V_3 -> V_322 ) ;
if ( V_3 -> V_18 -> V_248 ) {
V_37 = - V_249 ;
break;
}
if ( F_150 ( V_244 ) ) {
V_37 = - V_245 ;
break;
}
}
F_155 ( & V_3 -> V_321 , & V_236 ) ;
F_7 ( & V_3 -> V_322 ) ;
if ( V_37 < 0 )
goto V_324;
return V_37 ;
V_324:
F_221 ( V_3 -> V_18 -> V_319 ) ;
V_320:
F_222 ( V_3 -> V_18 , V_233 ) ;
V_318:
return V_37 ;
}
static int F_223 ( struct V_252 * V_252 , struct V_233 * V_233 )
{
struct V_15 * V_3 ;
struct V_1 * V_2 ;
struct V_259 * V_260 ;
V_260 = V_233 -> V_265 ;
V_2 = V_260 -> V_2 ;
if ( F_224 ( ! V_2 ) )
return - V_111 ;
V_3 = V_2 -> V_3 ;
F_3 ( & V_3 -> V_322 ) ;
F_206 ( V_2 ) ;
F_29 ( V_260 ) ;
F_7 ( & V_3 -> V_322 ) ;
F_113 ( & V_3 -> V_321 ) ;
F_221 ( V_3 -> V_18 -> V_319 ) ;
F_222 ( V_3 -> V_18 , V_233 ) ;
return 0 ;
}
static T_6 F_225 ( struct V_1 * V_2 ,
T_3 V_110 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 V_162 ;
T_6 V_201 ;
T_6 V_325 ;
if ( V_110 == 0 )
return 0 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_108 -> V_107 ) {
case V_114 :
break;
case V_166 :
case V_165 :
if ( F_84 ( V_2 ) >= 0 )
break;
case V_202 :
V_201 = - V_186 ;
goto V_326;
case V_212 :
V_201 = - V_250 ;
goto V_326;
default:
V_201 = - V_115 ;
goto V_326;
}
V_325 = F_226 ( V_14 ) ;
if ( V_325 <= 0 ) {
V_201 = 0 ;
goto V_326;
}
if ( V_110 > ( T_3 ) V_325 )
V_110 = V_325 ;
V_162 = V_14 -> V_137 -> V_162 - V_110 ;
if ( V_162 < 0 )
V_162 += V_14 -> V_143 ;
V_14 -> V_137 -> V_162 = V_162 ;
V_201 = V_110 ;
V_326:
F_13 ( V_2 ) ;
return V_201 ;
}
static T_6 F_227 ( struct V_1 * V_2 ,
T_3 V_110 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 V_162 ;
T_6 V_201 ;
T_6 V_325 ;
if ( V_110 == 0 )
return 0 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_108 -> V_107 ) {
case V_114 :
case V_166 :
break;
case V_165 :
if ( F_84 ( V_2 ) >= 0 )
break;
case V_202 :
V_201 = - V_186 ;
goto V_326;
case V_212 :
V_201 = - V_250 ;
goto V_326;
default:
V_201 = - V_115 ;
goto V_326;
}
V_325 = F_228 ( V_14 ) ;
if ( V_325 <= 0 ) {
V_201 = 0 ;
goto V_326;
}
if ( V_110 > ( T_3 ) V_325 )
V_110 = V_325 ;
V_162 = V_14 -> V_137 -> V_162 - V_110 ;
if ( V_162 < 0 )
V_162 += V_14 -> V_143 ;
V_14 -> V_137 -> V_162 = V_162 ;
V_201 = V_110 ;
V_326:
F_13 ( V_2 ) ;
return V_201 ;
}
static T_6 F_229 ( struct V_1 * V_2 ,
T_3 V_110 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 V_162 ;
T_6 V_201 ;
T_6 V_164 ;
if ( V_110 == 0 )
return 0 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_108 -> V_107 ) {
case V_114 :
case V_206 :
break;
case V_166 :
case V_165 :
if ( F_84 ( V_2 ) >= 0 )
break;
case V_202 :
V_201 = - V_186 ;
goto V_326;
case V_212 :
V_201 = - V_250 ;
goto V_326;
default:
V_201 = - V_115 ;
goto V_326;
}
V_164 = F_86 ( V_14 ) ;
if ( V_164 <= 0 ) {
V_201 = 0 ;
goto V_326;
}
if ( V_110 > ( T_3 ) V_164 )
V_110 = V_164 ;
V_162 = V_14 -> V_137 -> V_162 + V_110 ;
if ( V_162 >= ( T_6 ) V_14 -> V_143 )
V_162 -= V_14 -> V_143 ;
V_14 -> V_137 -> V_162 = V_162 ;
V_201 = V_110 ;
V_326:
F_13 ( V_2 ) ;
return V_201 ;
}
static T_6 F_230 ( struct V_1 * V_2 ,
T_3 V_110 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 V_162 ;
T_6 V_201 ;
T_6 V_164 ;
if ( V_110 == 0 )
return 0 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_108 -> V_107 ) {
case V_114 :
case V_166 :
case V_206 :
break;
case V_165 :
if ( F_84 ( V_2 ) >= 0 )
break;
case V_202 :
V_201 = - V_186 ;
goto V_326;
case V_212 :
V_201 = - V_250 ;
goto V_326;
default:
V_201 = - V_115 ;
goto V_326;
}
V_164 = F_87 ( V_14 ) ;
if ( V_164 <= 0 ) {
V_201 = 0 ;
goto V_326;
}
if ( V_110 > ( T_3 ) V_164 )
V_110 = V_164 ;
V_162 = V_14 -> V_137 -> V_162 + V_110 ;
if ( V_162 >= ( T_6 ) V_14 -> V_143 )
V_162 -= V_14 -> V_143 ;
V_14 -> V_137 -> V_162 = V_162 ;
V_201 = V_110 ;
V_326:
F_13 ( V_2 ) ;
return V_201 ;
}
static int F_231 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_37 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_108 -> V_107 ) {
case V_166 :
if ( V_2 -> V_21 == V_317 )
goto V_327;
case V_165 :
if ( ( V_37 = F_84 ( V_2 ) ) < 0 )
break;
case V_114 :
case V_212 :
V_37 = 0 ;
break;
case V_202 :
V_37 = - V_186 ;
break;
default:
V_327:
V_37 = - V_115 ;
break;
}
F_13 ( V_2 ) ;
return V_37 ;
}
static int F_232 ( struct V_1 * V_2 ,
T_6 T_2 * V_171 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_37 ;
T_6 V_328 = 0 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_108 -> V_107 ) {
case V_166 :
if ( V_2 -> V_21 == V_317 )
goto V_327;
case V_165 :
if ( ( V_37 = F_84 ( V_2 ) ) < 0 )
break;
case V_114 :
case V_212 :
V_37 = 0 ;
if ( V_2 -> V_21 == V_153 )
V_328 = F_226 ( V_14 ) ;
else
V_328 = F_87 ( V_14 ) ;
V_328 += V_14 -> V_167 ;
break;
case V_202 :
V_37 = - V_186 ;
break;
default:
V_327:
V_37 = - V_115 ;
break;
}
F_13 ( V_2 ) ;
if ( ! V_37 )
if ( F_233 ( V_328 , V_171 ) )
V_37 = - V_40 ;
return V_37 ;
}
static int F_234 ( struct V_1 * V_2 ,
struct F_234 T_2 * V_329 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct F_234 V_330 ;
volatile struct V_331 * V_108 ;
volatile struct V_332 * V_137 ;
int V_37 ;
memset ( & V_330 , 0 , sizeof( V_330 ) ) ;
if ( F_235 ( V_330 . V_10 , ( unsigned T_2 * ) & ( V_329 -> V_10 ) ) )
return - V_40 ;
if ( F_82 ( & V_330 . V_333 . V_137 , & ( V_329 -> V_333 . V_137 ) , sizeof( struct V_332 ) ) )
return - V_40 ;
V_108 = V_14 -> V_108 ;
V_137 = V_14 -> V_137 ;
if ( V_330 . V_10 & V_334 ) {
V_37 = F_231 ( V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
}
F_11 ( V_2 ) ;
if ( ! ( V_330 . V_10 & V_335 ) )
V_137 -> V_162 = V_330 . V_333 . V_137 . V_162 ;
else
V_330 . V_333 . V_137 . V_162 = V_137 -> V_162 ;
if ( ! ( V_330 . V_10 & V_336 ) )
V_137 -> V_138 = V_330 . V_333 . V_137 . V_138 ;
else
V_330 . V_333 . V_137 . V_138 = V_137 -> V_138 ;
V_330 . V_177 . V_108 . V_107 = V_108 -> V_107 ;
V_330 . V_177 . V_108 . V_163 = V_108 -> V_163 ;
V_330 . V_177 . V_108 . V_159 = V_108 -> V_159 ;
V_330 . V_177 . V_108 . V_155 = V_108 -> V_155 ;
F_13 ( V_2 ) ;
if ( F_28 ( V_329 , & V_330 , sizeof( V_330 ) ) )
return - V_40 ;
return 0 ;
}
static int F_236 ( struct V_1 * V_2 , int T_2 * V_337 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_338 ;
if ( F_235 ( V_338 , V_337 ) )
return - V_40 ;
if ( V_338 < 0 || V_338 > V_152 )
return - V_79 ;
V_14 -> V_151 = V_338 ;
return 0 ;
}
static int F_237 ( struct V_233 * V_233 ,
struct V_1 * V_2 ,
unsigned int V_339 , void T_2 * V_338 )
{
switch ( V_339 ) {
case V_340 :
return F_233 ( V_341 , ( int T_2 * ) V_338 ) ? - V_40 : 0 ;
case V_342 :
return F_26 ( V_2 , V_338 ) ;
case V_343 :
return 0 ;
case V_344 :
return F_236 ( V_2 , V_338 ) ;
case V_345 :
return F_51 ( V_2 , V_338 ) ;
case V_346 :
return F_74 ( V_2 , V_338 ) ;
case V_347 :
return F_75 ( V_2 ) ;
case V_348 :
return F_81 ( V_2 , V_338 ) ;
case V_349 :
return F_88 ( V_2 , V_338 ) ;
case V_350 :
return F_90 ( V_2 , V_338 ) ;
case V_351 :
return F_144 ( V_2 , V_233 ) ;
case V_352 :
return F_140 ( V_2 ) ;
case V_353 :
return F_101 ( & V_196 , V_2 , V_165 ) ;
case V_354 :
return F_164 ( V_2 , ( int ) ( unsigned long ) V_338 ) ;
case V_355 :
return F_177 ( V_2 ) ;
case V_356 :
return F_132 ( V_2 ) ;
case V_357 :
return F_136 ( V_2 ) ;
case V_358 :
return F_231 ( V_2 ) ;
case V_359 :
return F_232 ( V_2 , V_338 ) ;
case V_360 :
return F_234 ( V_2 , V_338 ) ;
#ifdef F_238
case V_361 :
return F_239 ( V_2 , V_338 ) ;
case V_362 :
return F_240 ( V_2 , V_338 ) ;
#endif
case V_363 :
return F_149 ( V_2 , V_233 ) ;
case V_364 :
return F_157 ( V_2 ) ;
case V_365 :
{
int V_171 ;
F_11 ( V_2 ) ;
V_171 = F_122 ( V_2 , ( int ) ( unsigned long ) V_338 ) ;
F_13 ( V_2 ) ;
return V_171 ;
}
}
F_210 ( V_2 -> V_3 , L_15 , V_339 ) ;
return - V_366 ;
}
static int F_241 ( struct V_233 * V_233 ,
struct V_1 * V_2 ,
unsigned int V_339 , void T_2 * V_338 )
{
if ( F_224 ( ! V_2 ) )
return - V_111 ;
if ( F_224 ( V_2 -> V_21 != V_153 ) )
return - V_79 ;
switch ( V_339 ) {
case V_367 :
{
struct V_368 V_369 ;
struct V_368 T_2 * V_370 = V_338 ;
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 V_148 ;
if ( V_14 -> V_108 -> V_107 == V_112 )
return - V_115 ;
if ( F_233 ( 0 , & V_370 -> V_148 ) )
return - V_40 ;
if ( F_82 ( & V_369 , V_370 , sizeof( V_369 ) ) )
return - V_40 ;
V_148 = F_242 ( V_2 , V_369 . V_371 , V_369 . V_110 ) ;
F_243 ( V_148 , & V_370 -> V_148 ) ;
return V_148 < 0 ? V_148 : 0 ;
}
case V_372 :
{
struct V_373 V_374 ;
struct V_373 T_2 * V_375 = V_338 ;
struct V_13 * V_14 = V_2 -> V_14 ;
void T_2 * * V_376 ;
T_6 V_148 ;
if ( V_14 -> V_108 -> V_107 == V_112 )
return - V_115 ;
if ( V_14 -> V_124 > 128 )
return - V_79 ;
if ( F_233 ( 0 , & V_375 -> V_148 ) )
return - V_40 ;
if ( F_82 ( & V_374 , V_375 , sizeof( V_374 ) ) )
return - V_40 ;
V_376 = F_52 ( V_374 . V_376 ,
sizeof( void * ) * V_14 -> V_124 ) ;
if ( F_53 ( V_376 ) )
return F_54 ( V_376 ) ;
V_148 = F_244 ( V_2 , V_376 , V_374 . V_110 ) ;
F_29 ( V_376 ) ;
F_243 ( V_148 , & V_375 -> V_148 ) ;
return V_148 < 0 ? V_148 : 0 ;
}
case V_377 :
{
T_3 V_110 ;
T_3 T_2 * V_378 = V_338 ;
T_6 V_148 ;
if ( F_235 ( V_110 , V_378 ) )
return - V_40 ;
if ( F_233 ( 0 , V_378 ) )
return - V_40 ;
V_148 = F_225 ( V_2 , V_110 ) ;
F_243 ( V_148 , V_378 ) ;
return V_148 < 0 ? V_148 : 0 ;
}
case V_379 :
{
T_3 V_110 ;
T_3 T_2 * V_378 = V_338 ;
T_6 V_148 ;
if ( F_235 ( V_110 , V_378 ) )
return - V_40 ;
if ( F_233 ( 0 , V_378 ) )
return - V_40 ;
V_148 = F_229 ( V_2 , V_110 ) ;
F_243 ( V_148 , V_378 ) ;
return V_148 < 0 ? V_148 : 0 ;
}
}
return F_237 ( V_233 , V_2 , V_339 , V_338 ) ;
}
static int F_245 ( struct V_233 * V_233 ,
struct V_1 * V_2 ,
unsigned int V_339 , void T_2 * V_338 )
{
if ( F_224 ( ! V_2 ) )
return - V_111 ;
if ( F_224 ( V_2 -> V_21 != V_317 ) )
return - V_79 ;
switch ( V_339 ) {
case V_380 :
{
struct V_368 V_369 ;
struct V_368 T_2 * V_370 = V_338 ;
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 V_148 ;
if ( V_14 -> V_108 -> V_107 == V_112 )
return - V_115 ;
if ( F_233 ( 0 , & V_370 -> V_148 ) )
return - V_40 ;
if ( F_82 ( & V_369 , V_370 , sizeof( V_369 ) ) )
return - V_40 ;
V_148 = F_246 ( V_2 , V_369 . V_371 , V_369 . V_110 ) ;
F_243 ( V_148 , & V_370 -> V_148 ) ;
return V_148 < 0 ? V_148 : 0 ;
}
case V_381 :
{
struct V_373 V_374 ;
struct V_373 T_2 * V_375 = V_338 ;
struct V_13 * V_14 = V_2 -> V_14 ;
void * V_376 ;
T_6 V_148 ;
if ( V_14 -> V_108 -> V_107 == V_112 )
return - V_115 ;
if ( V_14 -> V_124 > 128 )
return - V_79 ;
if ( F_233 ( 0 , & V_375 -> V_148 ) )
return - V_40 ;
if ( F_82 ( & V_374 , V_375 , sizeof( V_374 ) ) )
return - V_40 ;
V_376 = F_52 ( V_374 . V_376 ,
sizeof( void * ) * V_14 -> V_124 ) ;
if ( F_53 ( V_376 ) )
return F_54 ( V_376 ) ;
V_148 = F_247 ( V_2 , V_376 , V_374 . V_110 ) ;
F_29 ( V_376 ) ;
F_243 ( V_148 , & V_375 -> V_148 ) ;
return V_148 < 0 ? V_148 : 0 ;
}
case V_377 :
{
T_3 V_110 ;
T_3 T_2 * V_378 = V_338 ;
T_6 V_148 ;
if ( F_235 ( V_110 , V_378 ) )
return - V_40 ;
if ( F_233 ( 0 , V_378 ) )
return - V_40 ;
V_148 = F_227 ( V_2 , V_110 ) ;
F_243 ( V_148 , V_378 ) ;
return V_148 < 0 ? V_148 : 0 ;
}
case V_379 :
{
T_3 V_110 ;
T_3 T_2 * V_378 = V_338 ;
T_6 V_148 ;
if ( F_235 ( V_110 , V_378 ) )
return - V_40 ;
if ( F_233 ( 0 , V_378 ) )
return - V_40 ;
V_148 = F_230 ( V_2 , V_110 ) ;
F_243 ( V_148 , V_378 ) ;
return V_148 < 0 ? V_148 : 0 ;
}
}
return F_237 ( V_233 , V_2 , V_339 , V_338 ) ;
}
static long F_248 ( struct V_233 * V_233 , unsigned int V_339 ,
unsigned long V_338 )
{
struct V_259 * V_260 ;
V_260 = V_233 -> V_265 ;
if ( ( ( V_339 >> 8 ) & 0xff ) != 'A' )
return - V_366 ;
return F_241 ( V_233 , V_260 -> V_2 , V_339 ,
( void T_2 * ) V_338 ) ;
}
static long F_249 ( struct V_233 * V_233 , unsigned int V_339 ,
unsigned long V_338 )
{
struct V_259 * V_260 ;
V_260 = V_233 -> V_265 ;
if ( ( ( V_339 >> 8 ) & 0xff ) != 'A' )
return - V_366 ;
return F_245 ( V_233 , V_260 -> V_2 , V_339 ,
( void T_2 * ) V_338 ) ;
}
int F_250 ( struct V_1 * V_2 ,
unsigned int V_339 , void * V_338 )
{
T_1 V_11 ;
int V_148 ;
V_11 = F_19 () ;
switch ( V_2 -> V_21 ) {
case V_153 :
V_148 = F_241 ( NULL , V_2 , V_339 ,
( void T_2 * ) V_338 ) ;
break;
case V_317 :
V_148 = F_245 ( NULL , V_2 , V_339 ,
( void T_2 * ) V_338 ) ;
break;
default:
V_148 = - V_79 ;
break;
}
F_23 ( V_11 ) ;
return V_148 ;
}
static T_7 F_251 ( struct V_233 * V_233 , char T_2 * V_371 , T_8 V_270 ,
T_9 * V_382 )
{
struct V_259 * V_260 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
T_6 V_148 ;
V_260 = V_233 -> V_265 ;
V_2 = V_260 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_111 ;
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_108 -> V_107 == V_112 )
return - V_115 ;
if ( ! F_252 ( V_14 , V_270 ) )
return - V_79 ;
V_270 = F_253 ( V_14 , V_270 ) ;
V_148 = F_246 ( V_2 , V_371 , V_270 ) ;
if ( V_148 > 0 )
V_148 = F_254 ( V_14 , V_148 ) ;
return V_148 ;
}
static T_7 F_255 ( struct V_233 * V_233 , const char T_2 * V_371 ,
T_8 V_270 , T_9 * V_382 )
{
struct V_259 * V_260 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
T_6 V_148 ;
V_260 = V_233 -> V_265 ;
V_2 = V_260 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_111 ;
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_108 -> V_107 == V_112 )
return - V_115 ;
if ( ! F_252 ( V_14 , V_270 ) )
return - V_79 ;
V_270 = F_253 ( V_14 , V_270 ) ;
V_148 = F_242 ( V_2 , V_371 , V_270 ) ;
if ( V_148 > 0 )
V_148 = F_254 ( V_14 , V_148 ) ;
return V_148 ;
}
static T_7 F_256 ( struct V_383 * V_384 , const struct V_385 * V_386 ,
unsigned long V_387 , T_9 V_388 )
{
struct V_259 * V_260 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
T_6 V_148 ;
unsigned long V_57 ;
void T_2 * * V_376 ;
T_3 V_110 ;
V_260 = V_384 -> V_389 -> V_265 ;
V_2 = V_260 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_111 ;
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_108 -> V_107 == V_112 )
return - V_115 ;
if ( V_387 > 1024 || V_387 != V_14 -> V_124 )
return - V_79 ;
if ( ! F_252 ( V_14 , V_386 -> V_390 ) )
return - V_79 ;
V_110 = F_257 ( V_14 , V_386 -> V_390 ) ;
V_376 = F_27 ( sizeof( void * ) * V_387 , V_38 ) ;
if ( V_376 == NULL )
return - V_39 ;
for ( V_57 = 0 ; V_57 < V_387 ; ++ V_57 )
V_376 [ V_57 ] = V_386 [ V_57 ] . V_391 ;
V_148 = F_247 ( V_2 , V_376 , V_110 ) ;
if ( V_148 > 0 )
V_148 = F_254 ( V_14 , V_148 ) ;
F_29 ( V_376 ) ;
return V_148 ;
}
static T_7 F_258 ( struct V_383 * V_384 , const struct V_385 * V_386 ,
unsigned long V_387 , T_9 V_388 )
{
struct V_259 * V_260 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
T_6 V_148 ;
unsigned long V_57 ;
void T_2 * * V_376 ;
T_3 V_110 ;
V_260 = V_384 -> V_389 -> V_265 ;
V_2 = V_260 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_111 ;
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_108 -> V_107 == V_112 )
return - V_115 ;
if ( V_387 > 128 || V_387 != V_14 -> V_124 ||
! F_252 ( V_14 , V_386 -> V_390 ) )
return - V_79 ;
V_110 = F_257 ( V_14 , V_386 -> V_390 ) ;
V_376 = F_27 ( sizeof( void * ) * V_387 , V_38 ) ;
if ( V_376 == NULL )
return - V_39 ;
for ( V_57 = 0 ; V_57 < V_387 ; ++ V_57 )
V_376 [ V_57 ] = V_386 [ V_57 ] . V_391 ;
V_148 = F_244 ( V_2 , V_376 , V_110 ) ;
if ( V_148 > 0 )
V_148 = F_254 ( V_14 , V_148 ) ;
F_29 ( V_376 ) ;
return V_148 ;
}
static unsigned int F_259 ( struct V_233 * V_233 , T_10 * V_236 )
{
struct V_259 * V_260 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
unsigned int V_273 ;
T_3 V_164 ;
V_260 = V_233 -> V_265 ;
V_2 = V_260 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_111 ;
V_14 = V_2 -> V_14 ;
F_260 ( V_233 , & V_14 -> V_198 , V_236 ) ;
F_11 ( V_2 ) ;
V_164 = F_86 ( V_14 ) ;
switch ( V_14 -> V_108 -> V_107 ) {
case V_165 :
case V_114 :
case V_206 :
if ( V_164 >= V_14 -> V_137 -> V_138 ) {
V_273 = V_392 | V_393 ;
break;
}
case V_166 :
V_273 = 0 ;
break;
default:
V_273 = V_392 | V_393 | V_394 ;
break;
}
F_13 ( V_2 ) ;
return V_273 ;
}
static unsigned int F_261 ( struct V_233 * V_233 , T_10 * V_236 )
{
struct V_259 * V_260 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
unsigned int V_273 ;
T_3 V_164 ;
V_260 = V_233 -> V_265 ;
V_2 = V_260 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_111 ;
V_14 = V_2 -> V_14 ;
F_260 ( V_233 , & V_14 -> V_198 , V_236 ) ;
F_11 ( V_2 ) ;
V_164 = F_87 ( V_14 ) ;
switch ( V_14 -> V_108 -> V_107 ) {
case V_165 :
case V_114 :
case V_206 :
if ( V_164 >= V_14 -> V_137 -> V_138 ) {
V_273 = V_395 | V_396 ;
break;
}
V_273 = 0 ;
break;
case V_166 :
if ( V_164 > 0 ) {
V_273 = V_395 | V_396 ;
break;
}
default:
V_273 = V_395 | V_396 | V_394 ;
break;
}
F_13 ( V_2 ) ;
return V_273 ;
}
static int F_262 ( struct V_397 * V_398 ,
struct V_399 * V_400 )
{
struct V_1 * V_2 = V_398 -> V_401 ;
struct V_13 * V_14 ;
if ( V_2 == NULL )
return V_402 ;
V_14 = V_2 -> V_14 ;
V_400 -> V_403 = F_263 ( V_14 -> V_108 ) ;
F_264 ( V_400 -> V_403 ) ;
return 0 ;
}
static int V_331 ( struct V_1 * V_2 , struct V_233 * V_233 ,
struct V_397 * V_398 )
{
long V_404 ;
if ( ! ( V_398 -> V_405 & V_406 ) )
return - V_79 ;
V_404 = V_398 -> V_407 - V_398 -> V_408 ;
if ( V_404 != F_265 ( sizeof( struct V_331 ) ) )
return - V_79 ;
V_398 -> V_409 = & V_410 ;
V_398 -> V_401 = V_2 ;
V_398 -> V_405 |= V_411 | V_412 ;
return 0 ;
}
static int F_266 ( struct V_397 * V_398 ,
struct V_399 * V_400 )
{
struct V_1 * V_2 = V_398 -> V_401 ;
struct V_13 * V_14 ;
if ( V_2 == NULL )
return V_402 ;
V_14 = V_2 -> V_14 ;
V_400 -> V_403 = F_263 ( V_14 -> V_137 ) ;
F_264 ( V_400 -> V_403 ) ;
return 0 ;
}
static int V_332 ( struct V_1 * V_2 , struct V_233 * V_233 ,
struct V_397 * V_398 )
{
long V_404 ;
if ( ! ( V_398 -> V_405 & V_406 ) )
return - V_79 ;
V_404 = V_398 -> V_407 - V_398 -> V_408 ;
if ( V_404 != F_265 ( sizeof( struct V_332 ) ) )
return - V_79 ;
V_398 -> V_409 = & V_413 ;
V_398 -> V_401 = V_2 ;
V_398 -> V_405 |= V_411 | V_412 ;
return 0 ;
}
static int V_331 ( struct V_1 * V_2 , struct V_233 * V_233 ,
struct V_397 * V_398 )
{
return - V_111 ;
}
static int V_332 ( struct V_1 * V_2 , struct V_233 * V_233 ,
struct V_397 * V_398 )
{
return - V_111 ;
}
static inline struct V_403 *
F_267 ( struct V_1 * V_2 , unsigned long V_414 )
{
void * V_415 = V_2 -> V_14 -> V_416 + V_414 ;
return F_263 ( V_415 ) ;
}
static int F_268 ( struct V_397 * V_398 ,
struct V_399 * V_400 )
{
struct V_1 * V_2 = V_398 -> V_401 ;
struct V_13 * V_14 ;
unsigned long V_382 ;
struct V_403 * V_403 ;
T_8 V_308 ;
if ( V_2 == NULL )
return V_402 ;
V_14 = V_2 -> V_14 ;
V_382 = V_400 -> V_417 << V_418 ;
V_308 = F_265 ( V_14 -> V_308 ) ;
if ( V_382 > V_308 - V_419 )
return V_402 ;
if ( V_2 -> V_33 -> V_403 )
V_403 = V_2 -> V_33 -> V_403 ( V_2 , V_382 ) ;
else
V_403 = F_267 ( V_2 , V_382 ) ;
if ( ! V_403 )
return V_402 ;
F_264 ( V_403 ) ;
V_400 -> V_403 = V_403 ;
return 0 ;
}
int F_269 ( struct V_1 * V_2 ,
struct V_397 * V_398 )
{
V_398 -> V_405 |= V_411 | V_412 ;
#ifdef F_270
if ( V_2 -> V_49 . V_50 . type == V_420 ) {
V_398 -> V_421 = F_271 ( V_398 -> V_421 ) ;
return F_272 ( V_398 , V_398 -> V_408 ,
V_2 -> V_49 . V_422 >> V_418 ,
V_398 -> V_407 - V_398 -> V_408 , V_398 -> V_421 ) ;
}
#endif
#ifndef F_273
if ( ! V_2 -> V_33 -> V_403 &&
V_2 -> V_49 . V_50 . type == V_51 )
return F_274 ( V_2 -> V_49 . V_50 . V_50 ,
V_398 ,
V_2 -> V_14 -> V_416 ,
V_2 -> V_14 -> V_423 ,
V_398 -> V_407 - V_398 -> V_408 ) ;
#endif
V_398 -> V_409 = & V_424 ;
return 0 ;
}
int F_275 ( struct V_1 * V_2 ,
struct V_397 * V_398 )
{
struct V_13 * V_14 = V_2 -> V_14 ; ;
V_398 -> V_421 = F_276 ( V_398 -> V_421 ) ;
return F_277 ( V_398 , V_14 -> V_423 , V_14 -> V_308 ) ;
}
int F_278 ( struct V_1 * V_2 , struct V_233 * V_233 ,
struct V_397 * V_398 )
{
struct V_13 * V_14 ;
long V_404 ;
unsigned long V_382 ;
T_8 V_308 ;
int V_37 ;
if ( V_2 -> V_21 == V_153 ) {
if ( ! ( V_398 -> V_405 & ( V_425 | V_406 ) ) )
return - V_79 ;
} else {
if ( ! ( V_398 -> V_405 & V_406 ) )
return - V_79 ;
}
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_108 -> V_107 == V_112 )
return - V_115 ;
if ( ! ( V_14 -> V_12 & V_42 ) )
return - V_111 ;
if ( V_14 -> V_121 == V_289 ||
V_14 -> V_121 == V_291 )
return - V_79 ;
V_404 = V_398 -> V_407 - V_398 -> V_408 ;
V_382 = V_398 -> V_426 << V_418 ;
V_308 = F_265 ( V_14 -> V_308 ) ;
if ( ( T_8 ) V_404 > V_308 )
return - V_79 ;
if ( V_382 > V_308 - V_404 )
return - V_79 ;
V_398 -> V_409 = & V_427 ;
V_398 -> V_401 = V_2 ;
if ( V_2 -> V_33 -> V_48 )
V_37 = V_2 -> V_33 -> V_48 ( V_2 , V_398 ) ;
else
V_37 = F_269 ( V_2 , V_398 ) ;
if ( ! V_37 )
F_279 ( & V_2 -> V_118 ) ;
return V_37 ;
}
static int F_280 ( struct V_233 * V_233 , struct V_397 * V_398 )
{
struct V_259 * V_260 ;
struct V_1 * V_2 ;
unsigned long V_382 ;
V_260 = V_233 -> V_265 ;
V_2 = V_260 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_111 ;
V_382 = V_398 -> V_426 << V_418 ;
switch ( V_382 ) {
case V_428 :
if ( V_260 -> V_429 )
return - V_111 ;
return V_331 ( V_2 , V_233 , V_398 ) ;
case V_430 :
if ( V_260 -> V_429 )
return - V_111 ;
return V_332 ( V_2 , V_233 , V_398 ) ;
default:
return F_278 ( V_2 , V_233 , V_398 ) ;
}
return 0 ;
}
static int F_281 ( int V_258 , struct V_233 * V_233 , int V_431 )
{
struct V_259 * V_260 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
V_260 = V_233 -> V_265 ;
V_2 = V_260 -> V_2 ;
if ( F_57 ( V_2 ) )
return - V_111 ;
V_14 = V_2 -> V_14 ;
return F_282 ( V_258 , V_233 , V_431 , & V_14 -> V_432 ) ;
}
static void F_283 ( struct V_52 * V_53 ,
struct V_433 * V_434 )
{
unsigned int V_57 ;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
V_53 -> V_10 = V_434 -> V_10 ;
for ( V_57 = 0 ; V_57 < F_284 ( V_434 -> V_435 ) ; V_57 ++ )
V_53 -> V_435 [ V_57 ] . V_81 [ 0 ] = V_434 -> V_435 [ V_57 ] ;
memcpy ( V_53 -> V_436 , V_434 -> V_436 , sizeof( V_434 -> V_436 ) ) ;
V_53 -> V_71 = F_285 ( V_434 -> V_71 ) ;
V_53 -> V_82 = F_285 ( V_434 -> V_82 ) ;
V_53 -> V_12 = V_434 -> V_12 ;
V_53 -> V_73 = V_434 -> V_73 ;
V_53 -> V_75 = V_434 -> V_75 ;
V_53 -> V_76 = V_434 -> V_76 ;
V_53 -> V_70 = V_434 -> V_70 ;
}
static void F_286 ( struct V_433 * V_434 ,
struct V_52 * V_53 )
{
unsigned int V_57 ;
memset ( V_434 , 0 , sizeof( * V_434 ) ) ;
V_434 -> V_10 = V_53 -> V_10 ;
for ( V_57 = 0 ; V_57 < F_284 ( V_434 -> V_435 ) ; V_57 ++ )
V_434 -> V_435 [ V_57 ] = V_53 -> V_435 [ V_57 ] . V_81 [ 0 ] ;
memcpy ( V_434 -> V_436 , V_53 -> V_436 , sizeof( V_434 -> V_436 ) ) ;
V_434 -> V_71 = F_287 ( V_53 -> V_71 ) ;
V_434 -> V_82 = F_287 ( V_53 -> V_82 ) ;
V_434 -> V_12 = V_53 -> V_12 ;
V_434 -> V_73 = V_53 -> V_73 ;
V_434 -> V_75 = V_53 -> V_75 ;
V_434 -> V_76 = V_53 -> V_76 ;
V_434 -> V_70 = V_53 -> V_70 ;
}
static int F_239 ( struct V_1 * V_2 ,
struct V_433 T_2 * V_437 )
{
struct V_52 * V_53 ;
struct V_433 * V_434 = NULL ;
int V_37 ;
V_53 = F_27 ( sizeof( * V_53 ) , V_38 ) ;
if ( ! V_53 )
return - V_39 ;
V_434 = F_52 ( V_437 , sizeof( * V_434 ) ) ;
if ( F_53 ( V_434 ) ) {
V_37 = F_54 ( V_434 ) ;
goto V_438;
}
F_283 ( V_53 , V_434 ) ;
V_37 = F_32 ( V_2 , V_53 ) ;
F_286 ( V_434 , V_53 ) ;
if ( F_28 ( V_437 , V_434 , sizeof( * V_434 ) ) ) {
if ( ! V_37 )
V_37 = - V_40 ;
}
F_29 ( V_434 ) ;
V_438:
F_29 ( V_53 ) ;
return V_37 ;
}
static int F_240 ( struct V_1 * V_2 ,
struct V_433 T_2 * V_437 )
{
struct V_52 * V_53 ;
struct V_433 * V_434 = NULL ;
int V_37 ;
V_53 = F_27 ( sizeof( * V_53 ) , V_38 ) ;
if ( ! V_53 )
return - V_39 ;
V_434 = F_52 ( V_437 , sizeof( * V_434 ) ) ;
if ( F_53 ( V_434 ) ) {
V_37 = F_54 ( V_434 ) ;
goto V_438;
}
F_283 ( V_53 , V_434 ) ;
V_37 = V_52 ( V_2 , V_53 ) ;
F_286 ( V_434 , V_53 ) ;
if ( F_28 ( V_437 , V_434 , sizeof( * V_434 ) ) ) {
if ( ! V_37 )
V_37 = - V_40 ;
}
F_29 ( V_434 ) ;
V_438:
F_29 ( V_53 ) ;
return V_37 ;
}
static unsigned long F_288 ( struct V_233 * V_233 ,
unsigned long V_422 ,
unsigned long V_439 ,
unsigned long V_417 ,
unsigned long V_10 )
{
struct V_259 * V_260 = V_233 -> V_265 ;
struct V_1 * V_2 = V_260 -> V_2 ;
struct V_13 * V_14 = V_2 -> V_14 ;
unsigned long V_382 = V_417 << V_418 ;
switch ( V_382 ) {
case V_428 :
return ( unsigned long ) V_14 -> V_108 ;
case V_430 :
return ( unsigned long ) V_14 -> V_137 ;
default:
return ( unsigned long ) V_14 -> V_416 + V_382 ;
}
}
