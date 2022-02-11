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
if ( V_58 & V_62 )
F_3 ( V_2 , V_13 , V_63 ) ;
if ( V_58 & ( V_64 |
V_65 | V_62 ) )
F_14 ( V_2 ) ;
if ( V_58 & V_66 )
F_18 ( V_2 ) ;
F_25 ( & V_2 -> V_59 ) ;
return V_67 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_21 = 0 ;
unsigned int V_11 , V_68 ;
unsigned int V_69 ;
struct V_70 * V_71 ;
unsigned long V_72 ;
F_3 ( V_2 , V_73 , ( ( V_51 << 8 ) | V_74 ) ) ;
V_69 = V_40 ;
while ( V_69 -- && F_1 ( V_2 , V_6 ) & 0x00ff )
F_1 ( V_2 , V_42 ) ;
V_69 = V_40 ;
while ( V_69 -- && F_1 ( V_2 , V_6 ) & 0xff00 )
F_27 () ;
F_3 ( V_2 , V_14 , 0 ) ;
F_3 ( V_2 , V_13 , ~ 0 ) ;
V_71 = F_28 ( V_2 , struct V_70 , V_2 ) ;
snprintf ( V_71 -> V_75 , sizeof( V_71 -> V_75 ) , L_1 , V_2 -> line ) ;
V_21 = F_29 ( V_2 -> V_76 , V_2 -> V_56 , F_23 ,
V_77 , V_71 -> V_75 , V_2 ) ;
if ( V_21 ) {
F_30 ( V_2 -> V_76 , L_2 ,
V_2 -> V_56 , V_21 ) ;
return V_21 ;
}
V_68 = F_1 ( V_2 , V_78 ) ;
V_68 |= V_79 | V_80 ;
F_3 ( V_2 , V_78 , V_68 ) ;
F_31 ( & V_2 -> V_59 , V_72 ) ;
V_11 = F_1 ( V_2 , V_14 ) ;
V_11 |= V_16 | V_17 | V_81 ;
F_3 ( V_2 , V_14 , V_11 ) ;
F_32 ( & V_2 -> V_59 , V_72 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_14 , 0 ) ;
F_3 ( V_2 , V_13 , ~ 0 ) ;
F_34 ( V_2 -> V_76 , V_2 -> V_56 , V_2 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_82 * V_84 )
{
unsigned int V_85 , V_86 ;
unsigned int V_87 = 0 , V_68 ;
unsigned long V_72 ;
V_85 = F_36 ( V_2 , V_83 , V_84 , 0 , V_88 ) ;
V_86 = ( unsigned int ) ( ( V_2 -> V_89 + V_85 / 2 ) / V_85 ) ;
switch ( V_83 -> V_90 & V_91 ) {
case V_92 :
V_87 |= V_93 ;
break;
case V_94 :
V_87 |= V_95 ;
break;
case V_96 :
V_87 |= V_97 ;
break;
case V_98 :
default:
V_87 |= V_99 ;
break;
}
V_87 &= ~ ( V_100 | V_101 ) ;
if ( V_83 -> V_90 & V_102 )
V_87 |= V_101 ;
else
V_87 |= V_100 ;
V_87 &= ~ V_103 ;
V_83 -> V_90 &= ~ V_104 ;
if ( V_83 -> V_90 & V_105 ) {
V_87 |= V_106 ;
if ( V_83 -> V_90 & V_107 )
V_87 |= V_108 ;
else
V_87 |= V_109 ;
}
F_31 ( & V_2 -> V_59 , V_72 ) ;
F_37 ( V_2 , V_83 -> V_90 , V_85 ) ;
V_2 -> V_31 = V_29 ;
if ( V_83 -> V_110 & V_111 )
V_2 -> V_31 |= V_23 | V_24 ;
if ( V_83 -> V_110 & ( V_112 | V_113 | V_114 ) )
V_2 -> V_31 |= V_22 ;
V_2 -> V_115 = 0 ;
if ( V_83 -> V_110 & V_116 )
V_2 -> V_115 |= V_24 | V_23 ;
if ( V_83 -> V_110 & V_112 ) {
V_2 -> V_115 |= V_22 ;
if ( V_83 -> V_110 & V_116 )
V_2 -> V_115 |= V_29 ;
}
V_68 = F_1 ( V_2 , V_78 ) ;
V_68 &= ~ ( V_117 | V_118 | V_119 ) ;
if ( V_83 -> V_90 & V_120 ) {
V_68 |= V_117 ;
V_68 |= V_118 ;
V_68 |= V_119 ;
}
F_3 ( V_2 , V_121 , V_86 & 0xffff ) ;
F_3 ( V_2 , V_122 , ( V_86 & 0x1f0000 ) >> 16 ) ;
F_3 ( V_2 , V_123 , V_87 ) ;
V_68 |= V_79 | V_80 ;
F_3 ( V_2 , V_78 , V_68 ) ;
F_32 ( & V_2 -> V_59 , V_72 ) ;
if ( F_38 ( V_83 ) )
F_39 ( V_83 , V_85 , V_85 ) ;
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
static void F_43 ( struct V_1 * V_2 , int V_72 )
{
if ( V_72 & V_124 )
V_2 -> type = V_125 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_126 * V_127 )
{
if ( V_127 -> type != V_125 )
return - V_128 ;
if ( V_2 -> V_56 != V_127 -> V_56 )
return - V_128 ;
if ( V_2 -> V_129 != V_127 -> V_130 )
return - V_128 ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
unsigned int V_131 , V_132 = 10000 ;
do {
V_131 = F_1 ( V_2 , V_6 ) ;
if ( -- V_132 == 0 )
break;
F_46 ( 1 ) ;
} while ( V_131 & 0xff00 );
}
static void F_47 ( struct V_1 * V_2 , int V_38 )
{
F_45 ( V_2 ) ;
F_3 ( V_2 , V_49 , V_38 ) ;
}
static void F_48 ( struct V_133 * V_134 , const char * V_135 ,
unsigned int V_47 )
{
struct V_1 * V_2 = & V_136 [ V_134 -> V_137 ] -> V_2 ;
int V_138 = 1 ;
unsigned long V_72 ;
if ( V_2 -> V_139 )
V_138 = 0 ;
else if ( V_140 )
V_138 = F_49 ( & V_2 -> V_59 , V_72 ) ;
else
F_31 ( & V_2 -> V_59 , V_72 ) ;
F_50 ( V_2 , V_135 , V_47 , F_47 ) ;
F_45 ( V_2 ) ;
if ( V_138 )
F_32 ( & V_2 -> V_59 , V_72 ) ;
}
static int T_2 F_51 ( struct V_133 * V_134 , char * V_141 )
{
struct V_1 * V_2 ;
int V_85 = 115200 ;
int V_142 = 8 ;
int V_27 = 'n' ;
int V_143 = 'n' ;
if ( V_134 -> V_137 >= V_144 || V_134 -> V_137 < 0 )
V_134 -> V_137 = 0 ;
V_2 = & V_136 [ V_134 -> V_137 ] -> V_2 ;
if ( V_2 == NULL ) {
F_52 ( L_4 , V_134 -> V_137 ) ;
return - V_145 ;
}
if ( V_141 )
F_53 ( V_141 , & V_85 , & V_27 , & V_142 , & V_143 ) ;
return F_54 ( V_2 , V_134 , V_85 , V_27 , V_142 , V_143 ) ;
}
static void F_55 ( struct V_1 * V_2 , int V_146 )
{
unsigned int V_69 = V_40 ;
while ( V_69 -- &&
! ( F_56 ( V_2 -> V_4 + V_41 ) & V_147 ) )
F_27 () ;
F_57 ( V_146 , V_2 -> V_4 + V_49 ) ;
}
static void F_58 ( struct V_133 * V_148 , const char * V_135 ,
unsigned V_149 )
{
struct V_150 * V_76 = V_148 -> V_151 ;
F_50 ( & V_76 -> V_2 , V_135 , V_149 , F_55 ) ;
}
static int T_2 F_59 (
struct V_150 * V_152 ,
const char * V_153 )
{
if ( ! V_152 -> V_2 . V_4 )
return - V_145 ;
V_152 -> V_148 -> V_154 = F_58 ;
return 0 ;
}
static int F_60 ( int V_137 , struct V_152 * V_76 )
{
struct V_155 * V_156 ;
int V_21 = V_137 ;
if ( ! F_61 ( V_157 ) )
return V_21 ;
V_156 = V_76 -> V_158 ;
if ( ! V_156 )
return V_21 ;
V_21 = F_62 ( V_156 , L_5 ) ;
if ( V_21 < 0 )
V_21 = V_137 ;
else if ( V_21 >= F_63 ( V_136 ) || V_136 [ V_21 ] != NULL ) {
F_64 ( V_76 , L_6 , V_21 ) ;
V_21 = V_137 ;
}
return V_21 ;
}
static int F_65 ( struct V_159 * V_76 )
{
struct V_70 * V_160 = F_66 ( V_76 ) ;
if ( V_160 ) {
F_67 ( & V_161 , & V_160 -> V_2 ) ;
V_136 [ V_160 -> V_2 . line ] = NULL ;
V_162 -- ;
}
if ( ! V_162 )
F_68 ( & V_161 ) ;
return 0 ;
}
static int F_69 ( struct V_159 * V_163 )
{
struct V_164 * V_165 ;
struct V_1 * V_166 ;
struct V_167 * V_167 ;
int V_56 ;
int V_137 ;
int V_21 ;
for ( V_137 = 0 ; V_137 < F_63 ( V_136 ) ; V_137 ++ )
if ( V_136 [ V_137 ] == NULL )
break;
if ( V_137 == F_63 ( V_136 ) )
return - V_168 ;
V_137 = F_60 ( V_137 , & V_163 -> V_76 ) ;
V_136 [ V_137 ] = F_70 ( & V_163 -> V_76 ,
sizeof( * V_136 [ V_137 ] ) , V_169 ) ;
if ( ! V_136 [ V_137 ] )
return - V_170 ;
V_166 = & V_136 [ V_137 ] -> V_2 ;
V_166 -> V_76 = & V_163 -> V_76 ;
V_166 -> line = V_137 ;
V_166 -> type = V_125 ;
V_166 -> V_129 = V_171 ;
V_166 -> V_89 = V_172 ;
V_166 -> V_173 = V_174 ;
V_166 -> V_175 = & V_176 ;
V_166 -> V_72 = V_177 ;
V_167 = F_71 ( & V_163 -> V_76 , NULL ) ;
if ( ! F_72 ( V_167 ) )
V_166 -> V_89 = F_73 ( V_167 ) ;
V_165 = F_74 ( V_163 , V_178 , 0 ) ;
if ( ! V_165 ) {
F_30 ( & V_163 -> V_76 , L_7 ) ;
return - V_145 ;
}
V_166 -> V_179 = V_165 -> V_180 ;
V_166 -> V_4 = F_75 ( & V_163 -> V_76 , V_165 ) ;
if ( F_76 ( V_166 -> V_4 ) )
return F_77 ( V_166 -> V_4 ) ;
V_56 = F_78 ( V_163 , 0 ) ;
if ( V_56 < 0 ) {
F_30 ( & V_163 -> V_76 , L_8 , V_56 ) ;
return V_56 ;
}
V_166 -> V_56 = V_56 ;
if ( ! V_162 ) {
V_21 = F_79 ( & V_161 ) ;
if ( V_21 < 0 ) {
F_80 ( L_9 ) ;
return V_21 ;
}
}
V_162 ++ ;
V_21 = F_81 ( & V_161 , V_166 ) ;
if ( V_21 ) {
V_136 [ V_137 ] = NULL ;
F_65 ( V_163 ) ;
}
F_82 ( V_163 , V_166 ) ;
return V_21 ;
}
static int F_83 ( struct V_152 * V_76 )
{
struct V_70 * V_160 = F_84 ( V_76 ) ;
F_85 ( & V_161 , & V_160 -> V_2 ) ;
return 0 ;
}
static int F_86 ( struct V_152 * V_76 )
{
struct V_70 * V_160 = F_84 ( V_76 ) ;
F_87 ( & V_161 , & V_160 -> V_2 ) ;
return 0 ;
}
