static inline unsigned int F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 , int V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static unsigned int F_5 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 , V_6 ) & 0xff00 )
return 0 ;
else
return V_7 ;
}
static unsigned int F_6 ( struct V_1 * V_2 )
{
return V_8 | V_9 ;
}
static void F_7 ( struct V_1 * V_2 , unsigned int V_10 )
{
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned int V_11 , V_12 ;
V_12 = F_1 ( V_2 , V_13 ) ;
V_11 = F_1 ( V_2 , V_14 ) ;
V_12 |= V_15 ;
V_11 &= ~ V_15 ;
F_3 ( V_2 , V_13 , V_12 ) ;
F_3 ( V_2 , V_14 , V_11 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned int V_11 ;
V_11 = F_1 ( V_2 , V_14 ) ;
if ( ! ( V_11 & V_15 ) ) {
V_11 |= V_15 ;
F_3 ( V_2 , V_14 , V_11 ) ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
unsigned int V_11 , V_12 ;
V_12 = F_1 ( V_2 , V_13 ) ;
V_11 = F_1 ( V_2 , V_14 ) ;
V_11 &= ~ ( V_16 | V_17 ) ;
V_12 |= V_16 | V_17 ;
F_3 ( V_2 , V_14 , V_11 ) ;
F_3 ( V_2 , V_13 , V_12 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_18 )
{
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int * V_19 ,
unsigned int * V_20 )
{
int V_21 = 0 ;
if ( * V_20 & V_22 ) {
* V_20 &= ~ ( V_23 | V_24 ) ;
V_2 -> V_25 . V_26 ++ ;
V_21 = F_13 ( V_2 ) ;
if ( V_21 )
return V_21 ;
} else if ( * V_20 & V_24 )
V_2 -> V_25 . V_27 ++ ;
else if ( * V_20 & V_23 )
V_2 -> V_25 . V_28 ++ ;
if ( * V_20 & V_29 )
V_2 -> V_25 . V_30 ++ ;
* V_20 &= V_2 -> V_31 ;
if ( * V_20 & V_22 )
* V_19 = V_32 ;
else if ( * V_20 & V_24 )
* V_19 = V_33 ;
else if ( * V_20 & V_23 )
* V_19 = V_34 ;
return V_21 ;
}
static inline void F_14 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = & V_2 -> V_37 -> V_2 ;
unsigned int V_38 , V_19 , V_20 , V_39 = V_40 ;
while ( ( F_1 ( V_2 , V_6 ) & 0x00ff ) && V_39 -- ) {
V_20 = F_1 ( V_2 , V_41 ) ;
V_38 = F_1 ( V_2 , V_42 ) ;
V_19 = V_43 ;
V_2 -> V_25 . V_44 ++ ;
if ( V_20 & ( V_22 | V_24 |
V_23 | V_29 ) )
if ( F_12 ( V_2 , & V_20 , & V_19 ) )
continue;
if ( F_15 ( V_2 , V_38 ) )
continue;
F_16 ( V_2 , V_20 , V_29 , V_38 , V_19 ) ;
}
F_17 ( V_36 ) ;
}
static inline void F_18 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = & V_2 -> V_37 -> V_46 ;
int V_47 ;
if ( V_2 -> V_48 ) {
F_3 ( V_2 , V_49 , V_2 -> V_48 ) ;
V_2 -> V_25 . V_50 ++ ;
V_2 -> V_48 = 0 ;
return;
}
if ( F_19 ( V_46 ) || F_20 ( V_2 ) ) {
F_8 ( V_2 ) ;
return;
}
V_47 = V_51 ;
do {
F_3 ( V_2 , V_49 , V_46 -> V_52 [ V_46 -> V_53 ] ) ;
V_46 -> V_53 = ( V_46 -> V_53 + 1 ) & ( V_54 - 1 ) ;
V_2 -> V_25 . V_50 ++ ;
if ( F_19 ( V_46 ) )
break;
} while ( -- V_47 > 0 );
if ( F_21 ( V_46 ) < V_55 )
F_22 ( V_2 ) ;
if ( F_19 ( V_46 ) )
F_8 ( V_2 ) ;
}
static T_1 F_23 ( int V_56 , void * V_57 )
{
struct V_1 * V_2 = V_57 ;
unsigned int V_58 ;
F_24 ( & V_2 -> V_59 ) ;
V_58 = F_1 ( V_2 , V_60 ) ;
if ( ! V_58 ) {
F_25 ( & V_2 -> V_59 ) ;
return V_61 ;
}
F_3 ( V_2 , V_13 , ~ 0 ) ;
if ( V_58 & ( V_62 |
V_63 | V_64 ) )
F_14 ( V_2 ) ;
if ( V_58 & V_65 )
F_18 ( V_2 ) ;
F_25 ( & V_2 -> V_59 ) ;
return V_66 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_21 = 0 ;
unsigned int V_11 , V_67 ;
unsigned int V_68 ;
struct V_69 * V_70 ;
unsigned long V_71 ;
F_3 ( V_2 , V_72 , ( ( V_51 << 8 ) | V_73 ) ) ;
V_68 = V_40 ;
while ( V_68 -- && F_1 ( V_2 , V_6 ) & 0x00ff )
F_1 ( V_2 , V_42 ) ;
V_68 = V_40 ;
while ( V_68 -- && F_1 ( V_2 , V_6 ) & 0xff00 )
F_27 () ;
F_3 ( V_2 , V_14 , 0 ) ;
F_3 ( V_2 , V_13 , ~ 0 ) ;
V_70 = F_28 ( V_2 , struct V_69 , V_2 ) ;
snprintf ( V_70 -> V_74 , sizeof( V_70 -> V_74 ) , L_1 , V_2 -> line ) ;
V_21 = F_29 ( V_2 -> V_75 , V_2 -> V_56 , F_23 ,
V_76 , V_70 -> V_74 , V_2 ) ;
if ( V_21 ) {
F_30 ( V_2 -> V_75 , L_2 ,
V_2 -> V_56 , V_21 ) ;
return V_21 ;
}
V_67 = F_1 ( V_2 , V_77 ) ;
V_67 |= V_78 | V_79 ;
F_3 ( V_2 , V_77 , V_67 ) ;
F_31 ( & V_2 -> V_59 , V_71 ) ;
V_11 = F_1 ( V_2 , V_14 ) ;
V_11 |= V_16 | V_17 | V_80 ;
F_3 ( V_2 , V_14 , V_11 ) ;
F_32 ( & V_2 -> V_59 , V_71 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_14 , 0 ) ;
F_3 ( V_2 , V_13 , ~ 0 ) ;
F_34 ( V_2 -> V_75 , V_2 -> V_56 , V_2 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_81 * V_82 ,
struct V_81 * V_83 )
{
unsigned int V_84 , V_85 ;
unsigned int V_86 = 0 , V_67 ;
unsigned long V_71 ;
V_84 = F_36 ( V_2 , V_82 , V_83 , 0 , V_87 ) ;
V_85 = ( unsigned int ) ( ( V_2 -> V_88 + V_84 / 2 ) / V_84 ) ;
switch ( V_82 -> V_89 & V_90 ) {
case V_91 :
V_86 |= V_92 ;
break;
case V_93 :
V_86 |= V_94 ;
break;
case V_95 :
V_86 |= V_96 ;
break;
case V_97 :
default:
V_86 |= V_98 ;
break;
}
V_86 &= ~ ( V_99 | V_100 ) ;
if ( V_82 -> V_89 & V_101 )
V_86 |= V_100 ;
else
V_86 |= V_99 ;
V_86 &= ~ V_102 ;
V_82 -> V_89 &= ~ V_103 ;
if ( V_82 -> V_89 & V_104 ) {
V_86 |= V_105 ;
if ( V_82 -> V_89 & V_106 )
V_86 |= V_107 ;
else
V_86 |= V_108 ;
}
F_31 ( & V_2 -> V_59 , V_71 ) ;
F_37 ( V_2 , V_82 -> V_89 , V_84 ) ;
V_2 -> V_31 = V_29 ;
if ( V_82 -> V_109 & V_110 )
V_2 -> V_31 |= V_23 | V_24 ;
if ( V_82 -> V_109 & ( V_111 | V_112 | V_113 ) )
V_2 -> V_31 |= V_22 ;
V_2 -> V_114 = 0 ;
if ( V_82 -> V_109 & V_115 )
V_2 -> V_114 |= V_24 | V_23 ;
if ( V_82 -> V_109 & V_111 ) {
V_2 -> V_114 |= V_22 ;
if ( V_82 -> V_109 & V_115 )
V_2 -> V_114 |= V_29 ;
}
V_67 = F_1 ( V_2 , V_77 ) ;
V_67 &= ~ ( V_116 | V_117 | V_118 ) ;
if ( V_82 -> V_89 & V_119 ) {
V_67 |= V_116 ;
V_67 |= V_117 ;
V_67 |= V_118 ;
}
F_3 ( V_2 , V_120 , V_85 & 0xffff ) ;
F_3 ( V_2 , V_121 , ( V_85 & 0x1f0000 ) >> 16 ) ;
F_3 ( V_2 , V_122 , V_86 ) ;
V_67 |= V_78 | V_79 ;
F_3 ( V_2 , V_77 , V_67 ) ;
F_32 ( & V_2 -> V_59 , V_71 ) ;
if ( F_38 ( V_82 ) )
F_39 ( V_82 , V_84 , V_84 ) ;
}
static const char * F_40 ( struct V_1 * V_2 )
{
return L_3 ;
}
static void F_41 ( struct V_1 * V_2 )
{
}
static int F_42 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_43 ( struct V_1 * V_2 , int V_71 )
{
if ( V_71 & V_123 )
V_2 -> type = V_124 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_125 * V_126 )
{
if ( V_126 -> type != V_124 )
return - V_127 ;
if ( V_2 -> V_56 != V_126 -> V_56 )
return - V_127 ;
if ( V_2 -> V_128 != V_126 -> V_129 )
return - V_127 ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
unsigned int V_130 , V_131 = 10000 ;
do {
V_130 = F_1 ( V_2 , V_6 ) ;
if ( -- V_131 == 0 )
break;
F_46 ( 1 ) ;
} while ( V_130 & 0xff00 );
}
static void F_47 ( struct V_1 * V_2 , int V_38 )
{
F_45 ( V_2 ) ;
F_3 ( V_2 , V_49 , V_38 ) ;
}
static void F_48 ( struct V_132 * V_133 , const char * V_134 ,
unsigned int V_47 )
{
struct V_1 * V_2 = & V_135 [ V_133 -> V_136 ] -> V_2 ;
int V_137 = 1 ;
unsigned long V_71 ;
if ( V_2 -> V_138 )
V_137 = 0 ;
else if ( V_139 )
V_137 = F_49 ( & V_2 -> V_59 , V_71 ) ;
else
F_31 ( & V_2 -> V_59 , V_71 ) ;
F_50 ( V_2 , V_134 , V_47 , F_47 ) ;
F_45 ( V_2 ) ;
if ( V_137 )
F_32 ( & V_2 -> V_59 , V_71 ) ;
}
static int T_2 F_51 ( struct V_132 * V_133 , char * V_140 )
{
struct V_1 * V_2 ;
int V_84 = 115200 ;
int V_141 = 8 ;
int V_27 = 'n' ;
int V_142 = 'n' ;
if ( V_133 -> V_136 >= V_143 || V_133 -> V_136 < 0 )
V_133 -> V_136 = 0 ;
V_2 = & V_135 [ V_133 -> V_136 ] -> V_2 ;
if ( V_2 == NULL ) {
F_52 ( L_4 , V_133 -> V_136 ) ;
return - V_144 ;
}
if ( V_140 )
F_53 ( V_140 , & V_84 , & V_27 , & V_141 , & V_142 ) ;
return F_54 ( V_2 , V_133 , V_84 , V_27 , V_141 , V_142 ) ;
}
static void F_55 ( struct V_1 * V_2 , int V_145 )
{
unsigned int V_68 = V_40 ;
while ( V_68 -- &&
! ( F_56 ( V_2 -> V_4 + V_41 ) & V_146 ) )
F_27 () ;
F_57 ( V_145 , V_2 -> V_4 + V_49 ) ;
}
static void F_58 ( struct V_132 * V_147 , const char * V_134 ,
unsigned V_148 )
{
struct V_149 * V_75 = V_147 -> V_150 ;
F_50 ( & V_75 -> V_2 , V_134 , V_148 , F_55 ) ;
}
static int T_2 F_59 (
struct V_149 * V_151 ,
const char * V_152 )
{
if ( ! V_151 -> V_2 . V_4 )
return - V_144 ;
V_151 -> V_147 -> V_153 = F_58 ;
return 0 ;
}
static int F_60 ( int V_136 , struct V_151 * V_75 )
{
struct V_154 * V_155 ;
int V_21 = V_136 ;
if ( ! F_61 ( V_156 ) )
return V_21 ;
V_155 = V_75 -> V_157 ;
if ( ! V_155 )
return V_21 ;
V_21 = F_62 ( V_155 , L_5 ) ;
if ( F_63 ( V_21 ) )
V_21 = V_136 ;
else if ( V_21 >= F_64 ( V_135 ) || V_135 [ V_21 ] != NULL ) {
F_65 ( V_75 , L_6 , V_21 ) ;
V_21 = V_136 ;
}
return V_21 ;
}
static int F_66 ( struct V_158 * V_75 )
{
struct V_69 * V_159 = F_67 ( V_75 ) ;
if ( V_159 ) {
F_68 ( & V_160 , & V_159 -> V_2 ) ;
V_135 [ V_159 -> V_2 . line ] = NULL ;
V_161 -- ;
}
if ( ! V_161 )
F_69 ( & V_160 ) ;
return 0 ;
}
static int F_70 ( struct V_158 * V_162 )
{
struct V_163 * V_164 ;
struct V_1 * V_165 ;
struct V_166 * V_166 ;
int V_56 ;
int V_136 ;
int V_21 ;
for ( V_136 = 0 ; V_136 < F_64 ( V_135 ) ; V_136 ++ )
if ( V_135 [ V_136 ] == NULL )
break;
if ( V_136 == F_64 ( V_135 ) )
return - V_167 ;
V_136 = F_60 ( V_136 , & V_162 -> V_75 ) ;
V_135 [ V_136 ] = F_71 ( & V_162 -> V_75 ,
sizeof( * V_135 [ V_136 ] ) , V_168 ) ;
if ( ! V_135 [ V_136 ] )
return - V_169 ;
V_165 = & V_135 [ V_136 ] -> V_2 ;
V_165 -> V_75 = & V_162 -> V_75 ;
V_165 -> line = V_136 ;
V_165 -> type = V_124 ;
V_165 -> V_128 = V_170 ;
V_165 -> V_88 = V_171 ;
V_165 -> V_172 = V_173 ;
V_165 -> V_174 = & V_175 ;
V_165 -> V_71 = V_176 ;
V_166 = F_72 ( & V_162 -> V_75 , NULL ) ;
if ( ! F_73 ( V_166 ) )
V_165 -> V_88 = F_74 ( V_166 ) ;
V_164 = F_75 ( V_162 , V_177 , 0 ) ;
if ( ! V_164 ) {
F_30 ( & V_162 -> V_75 , L_7 ) ;
return - V_144 ;
}
V_165 -> V_178 = V_164 -> V_179 ;
V_165 -> V_4 = F_76 ( & V_162 -> V_75 , V_164 ) ;
if ( F_77 ( V_165 -> V_4 ) )
return F_78 ( V_165 -> V_4 ) ;
V_56 = F_79 ( V_162 , 0 ) ;
if ( V_56 < 0 ) {
F_30 ( & V_162 -> V_75 , L_8 ) ;
return - V_144 ;
}
V_165 -> V_56 = V_56 ;
if ( ! V_161 ) {
V_21 = F_80 ( & V_160 ) ;
if ( V_21 < 0 ) {
F_81 ( L_9 ) ;
return V_21 ;
}
}
V_161 ++ ;
V_21 = F_82 ( & V_160 , V_165 ) ;
if ( V_21 ) {
V_135 [ V_136 ] = NULL ;
F_66 ( V_162 ) ;
}
F_83 ( V_162 , V_165 ) ;
return V_21 ;
}
static int F_84 ( struct V_151 * V_75 )
{
struct V_69 * V_159 = F_85 ( V_75 ) ;
F_86 ( & V_160 , & V_159 -> V_2 ) ;
return 0 ;
}
static int F_87 ( struct V_151 * V_75 )
{
struct V_69 * V_159 = F_85 ( V_75 ) ;
F_88 ( & V_160 , & V_159 -> V_2 ) ;
return 0 ;
}
