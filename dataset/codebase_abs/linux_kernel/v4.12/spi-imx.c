static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 == V_5 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 == V_6 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 == V_7 ;
}
static inline unsigned F_4 ( struct V_1 * V_2 )
{
return F_3 ( V_2 ) ? 64 : 8 ;
}
static unsigned int F_5 ( unsigned int V_8 ,
unsigned int V_9 , unsigned int V_10 , unsigned int * V_11 )
{
int V_12 ;
for ( V_12 = 2 ; V_12 < V_10 ; V_12 ++ )
if ( V_9 * V_13 [ V_12 ] >= V_8 )
break;
* V_11 = V_8 / V_13 [ V_12 ] ;
return V_12 ;
}
static unsigned int F_6 ( unsigned int V_8 ,
unsigned int V_9 , unsigned int * V_11 )
{
int V_12 , div = 4 ;
for ( V_12 = 0 ; V_12 < 7 ; V_12 ++ ) {
if ( V_9 * div >= V_8 )
goto V_14;
div <<= 1 ;
}
V_14:
* V_11 = V_8 / div ;
return V_12 ;
}
static int F_7 ( const int V_15 )
{
return F_8 ( V_15 , V_16 ) ;
}
static bool F_9 ( struct V_17 * V_18 , struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_1 * V_23 = F_10 ( V_18 ) ;
unsigned int V_15 , V_12 ;
if ( ! V_18 -> V_24 )
return false ;
if ( ! V_22 )
return false ;
V_15 = V_22 -> V_25 ;
if ( ! V_15 )
V_15 = V_20 -> V_25 ;
V_15 = F_7 ( V_15 ) ;
if ( V_15 != 1 && V_15 != 2 && V_15 != 4 )
return false ;
for ( V_12 = F_4 ( V_23 ) / 2 ; V_12 > 0 ; V_12 -- ) {
if ( ! ( V_22 -> V_26 % ( V_12 * V_15 ) ) )
break;
}
if ( V_12 == 0 )
return false ;
V_23 -> V_27 = V_12 ;
return true ;
}
static unsigned int F_11 ( struct V_1 * V_23 ,
unsigned int V_9 , unsigned int * V_11 )
{
unsigned int V_28 , V_29 ;
unsigned int V_8 = V_23 -> V_30 ;
if ( F_12 ( V_9 > V_8 ) )
return 0 ;
V_29 = F_13 ( V_8 ) - F_13 ( V_9 ) ;
if ( V_8 > V_9 << V_29 )
V_29 ++ ;
V_29 = V_10 ( 4U , V_29 ) - 4 ;
if ( F_12 ( V_29 > 0xf ) ) {
F_14 ( V_23 -> V_31 , L_1 ,
V_9 , V_8 ) ;
return 0xff ;
}
V_28 = F_8 ( V_8 , V_9 << V_29 ) - 1 ;
F_15 ( V_23 -> V_31 , L_2 ,
V_32 , V_8 , V_9 , V_29 , V_28 ) ;
* V_11 = ( V_8 / ( V_28 + 1 ) ) >> V_29 ;
return ( V_28 << V_33 ) |
( V_29 << V_34 ) ;
}
static void F_16 ( struct V_1 * V_23 , int V_35 )
{
unsigned V_36 = 0 ;
if ( V_35 & V_37 )
V_36 |= V_38 ;
if ( V_35 & V_39 )
V_36 |= V_40 ;
F_17 ( V_36 , V_23 -> V_41 + V_42 ) ;
}
static void F_18 ( struct V_1 * V_23 )
{
T_1 V_43 ;
V_43 = F_19 ( V_23 -> V_41 + V_44 ) ;
V_43 |= V_45 ;
F_17 ( V_43 , V_23 -> V_41 + V_44 ) ;
}
static int F_20 ( struct V_19 * V_20 ,
struct V_46 * V_47 )
{
struct V_1 * V_23 = F_10 ( V_20 -> V_18 ) ;
T_1 V_48 = V_49 ;
T_1 V_50 = V_47 -> V_51 , V_52 , V_43 ;
T_1 V_53 = F_19 ( V_23 -> V_41 + V_54 ) ;
V_48 |= V_55 ;
if ( V_20 -> V_56 & V_57 )
V_48 |= F_21 ( V_23 -> V_58 ) ;
V_48 |= F_11 ( V_23 , V_47 -> V_51 , & V_50 ) ;
V_23 -> V_59 = V_50 ;
V_48 |= F_22 ( V_20 -> V_60 ) ;
V_48 |= ( V_47 -> V_15 - 1 ) << V_61 ;
V_53 |= F_23 ( V_20 -> V_60 ) ;
if ( V_20 -> V_56 & V_62 )
V_53 |= F_24 ( V_20 -> V_60 ) ;
else
V_53 &= ~ F_24 ( V_20 -> V_60 ) ;
if ( V_20 -> V_56 & V_63 ) {
V_53 |= F_25 ( V_20 -> V_60 ) ;
V_53 |= F_26 ( V_20 -> V_60 ) ;
} else {
V_53 &= ~ F_25 ( V_20 -> V_60 ) ;
V_53 &= ~ F_26 ( V_20 -> V_60 ) ;
}
if ( V_20 -> V_56 & V_64 )
V_53 |= F_27 ( V_20 -> V_60 ) ;
else
V_53 &= ~ F_27 ( V_20 -> V_60 ) ;
if ( V_23 -> V_65 )
V_48 |= V_66 ;
F_17 ( V_48 , V_23 -> V_41 + V_44 ) ;
V_43 = F_19 ( V_23 -> V_41 + V_67 ) ;
if ( V_20 -> V_56 & V_68 )
V_43 |= V_69 ;
else
V_43 &= ~ V_69 ;
F_17 ( V_43 , V_23 -> V_41 + V_67 ) ;
F_17 ( V_53 , V_23 -> V_41 + V_54 ) ;
V_52 = ( 2 * 1000000 ) / V_50 ;
if ( F_28 ( V_52 < 10 ) )
F_29 ( V_52 ) ;
else
F_30 ( V_52 , V_52 + 10 ) ;
F_17 ( F_31 ( V_23 -> V_27 ) |
F_32 ( V_23 -> V_27 ) |
F_33 ( V_23 -> V_27 ) |
V_70 | V_71 |
V_72 , V_23 -> V_41 + V_73 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_23 )
{
return F_19 ( V_23 -> V_41 + V_74 ) & V_75 ;
}
static void F_35 ( struct V_1 * V_23 )
{
while ( F_34 ( V_23 ) )
F_19 ( V_23 -> V_41 + V_76 ) ;
}
static void F_36 ( struct V_1 * V_23 , int V_35 )
{
unsigned int V_36 = 0 ;
if ( V_35 & V_37 )
V_36 |= V_77 ;
if ( V_35 & V_39 )
V_36 |= V_78 ;
F_17 ( V_36 , V_23 -> V_41 + V_79 ) ;
}
static void F_37 ( struct V_1 * V_23 )
{
unsigned int V_43 ;
V_43 = F_19 ( V_23 -> V_41 + V_80 ) ;
V_43 |= V_81 ;
F_17 ( V_43 , V_23 -> V_41 + V_80 ) ;
}
static int F_38 ( struct V_19 * V_20 , struct V_46 * V_47 )
{
struct V_1 * V_23 = F_10 ( V_20 -> V_18 ) ;
unsigned int V_43 = V_82 | V_83 ;
unsigned int V_50 ;
V_43 |= F_6 ( V_23 -> V_30 , V_47 -> V_51 , & V_50 ) <<
V_84 ;
V_23 -> V_59 = V_50 ;
if ( F_2 ( V_23 ) ) {
V_43 |= ( V_47 -> V_15 - 1 ) << V_85 ;
V_43 |= V_86 ;
} else {
V_43 |= ( V_47 -> V_15 - 1 ) << V_87 ;
}
if ( V_20 -> V_56 & V_62 )
V_43 |= V_88 ;
if ( V_20 -> V_56 & V_63 )
V_43 |= V_89 ;
if ( V_20 -> V_56 & V_64 )
V_43 |= V_90 ;
if ( V_20 -> V_91 < 0 )
V_43 |= ( V_20 -> V_91 + 32 ) <<
( F_2 ( V_23 ) ? V_92 :
V_93 ) ;
if ( V_23 -> V_65 )
V_43 |= V_94 ;
F_17 ( V_43 , V_23 -> V_41 + V_80 ) ;
V_43 = F_19 ( V_23 -> V_41 + V_95 ) ;
if ( V_20 -> V_56 & V_68 )
V_43 |= V_96 ;
else
V_43 &= ~ V_96 ;
F_17 ( V_43 , V_23 -> V_41 + V_95 ) ;
if ( V_23 -> V_65 ) {
F_17 ( V_97 | V_98 ,
V_23 -> V_41 + V_99 ) ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_23 )
{
return F_19 ( V_23 -> V_41 + V_100 ) & V_101 ;
}
static void F_40 ( struct V_1 * V_23 )
{
while ( F_19 ( V_23 -> V_41 + V_100 ) & V_101 )
F_19 ( V_23 -> V_41 + V_76 ) ;
}
static void F_41 ( struct V_1 * V_23 , int V_35 )
{
unsigned int V_36 = 0 ;
if ( V_35 & V_37 )
V_36 |= V_102 ;
if ( V_35 & V_39 )
V_36 |= V_103 ;
F_17 ( V_36 , V_23 -> V_41 + V_79 ) ;
}
static void F_42 ( struct V_1 * V_23 )
{
unsigned int V_43 ;
V_43 = F_19 ( V_23 -> V_41 + V_80 ) ;
V_43 |= V_104 ;
F_17 ( V_43 , V_23 -> V_41 + V_80 ) ;
}
static int F_43 ( struct V_19 * V_20 , struct V_46 * V_47 )
{
struct V_1 * V_23 = F_10 ( V_20 -> V_18 ) ;
unsigned int V_43 = V_105 | V_106 ;
unsigned int V_10 = F_1 ( V_23 ) ? 16 : 18 ;
unsigned int V_50 ;
V_43 |= F_5 ( V_23 -> V_30 , V_47 -> V_51 , V_10 , & V_50 )
<< V_107 ;
V_23 -> V_59 = V_50 ;
V_43 |= V_47 -> V_15 - 1 ;
if ( V_20 -> V_56 & V_62 )
V_43 |= V_108 ;
if ( V_20 -> V_56 & V_63 )
V_43 |= V_109 ;
if ( V_20 -> V_56 & V_64 )
V_43 |= V_110 ;
if ( V_20 -> V_91 < 0 )
V_43 |= ( V_20 -> V_91 + 32 ) << V_111 ;
F_17 ( V_43 , V_23 -> V_41 + V_80 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_23 )
{
return F_19 ( V_23 -> V_41 + V_79 ) & V_112 ;
}
static void F_45 ( struct V_1 * V_23 )
{
F_17 ( 1 , V_23 -> V_41 + V_113 ) ;
}
static void F_46 ( struct V_1 * V_23 , int V_35 )
{
unsigned int V_36 = 0 ;
if ( V_35 & V_37 )
V_36 |= V_114 ;
if ( V_35 & V_39 )
V_36 |= V_115 ;
F_17 ( V_36 , V_23 -> V_41 + V_79 ) ;
}
static void F_47 ( struct V_1 * V_23 )
{
unsigned int V_43 ;
V_43 = F_19 ( V_23 -> V_41 + V_80 ) ;
V_43 |= V_116 ;
F_17 ( V_43 , V_23 -> V_41 + V_80 ) ;
}
static int F_48 ( struct V_19 * V_20 , struct V_46 * V_47 )
{
struct V_1 * V_23 = F_10 ( V_20 -> V_18 ) ;
unsigned int V_43 = V_117 | V_118 ;
unsigned int V_50 ;
V_43 |= F_6 ( V_23 -> V_30 , V_47 -> V_51 , & V_50 ) <<
V_119 ;
V_23 -> V_59 = V_50 ;
V_43 |= V_47 -> V_15 - 1 ;
if ( V_20 -> V_56 & V_62 )
V_43 |= V_120 ;
if ( V_20 -> V_56 & V_63 )
V_43 |= V_121 ;
F_17 ( V_43 , V_23 -> V_41 + V_80 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_23 )
{
return F_19 ( V_23 -> V_41 + V_79 ) & V_122 ;
}
static void F_50 ( struct V_1 * V_23 )
{
F_17 ( 1 , V_23 -> V_41 + V_113 ) ;
}
static void F_51 ( struct V_19 * V_20 , int V_123 )
{
int V_124 = V_123 != V_125 ;
int V_126 = ! ( V_20 -> V_56 & V_64 ) ;
if ( ! F_52 ( V_20 -> V_91 ) )
return;
F_53 ( V_20 -> V_91 , V_126 ^ V_124 ) ;
}
static void F_54 ( struct V_1 * V_23 )
{
while ( V_23 -> V_127 < F_4 ( V_23 ) ) {
if ( ! V_23 -> V_128 )
break;
V_23 -> V_129 ( V_23 ) ;
V_23 -> V_127 ++ ;
}
V_23 -> V_3 -> V_130 ( V_23 ) ;
}
static T_2 F_55 ( int V_131 , void * V_132 )
{
struct V_1 * V_23 = V_132 ;
while ( V_23 -> V_3 -> V_133 ( V_23 ) ) {
V_23 -> V_134 ( V_23 ) ;
V_23 -> V_127 -- ;
}
if ( V_23 -> V_128 ) {
F_54 ( V_23 ) ;
return V_135 ;
}
if ( V_23 -> V_127 ) {
V_23 -> V_3 -> V_136 (
V_23 , V_39 ) ;
return V_135 ;
}
V_23 -> V_3 -> V_136 ( V_23 , 0 ) ;
F_56 ( & V_23 -> V_137 ) ;
return V_135 ;
}
static int F_57 ( struct V_17 * V_18 ,
int V_138 )
{
int V_139 ;
enum V_140 V_141 ;
struct V_142 V_134 = {} , V_129 = {} ;
struct V_1 * V_23 = F_10 ( V_18 ) ;
switch ( V_138 ) {
case 4 :
V_141 = V_143 ;
break;
case 2 :
V_141 = V_144 ;
break;
case 1 :
V_141 = V_145 ;
break;
default:
return - V_146 ;
}
V_129 . V_147 = V_148 ;
V_129 . V_149 = V_23 -> V_150 + V_151 ;
V_129 . V_152 = V_141 ;
V_129 . V_153 = V_23 -> V_27 ;
V_139 = F_58 ( V_18 -> V_154 , & V_129 ) ;
if ( V_139 ) {
F_14 ( V_23 -> V_31 , L_3 , V_139 ) ;
return V_139 ;
}
V_134 . V_147 = V_155 ;
V_134 . V_156 = V_23 -> V_150 + V_76 ;
V_134 . V_157 = V_141 ;
V_134 . V_158 = V_23 -> V_27 ;
V_139 = F_58 ( V_18 -> V_24 , & V_134 ) ;
if ( V_139 ) {
F_14 ( V_23 -> V_31 , L_4 , V_139 ) ;
return V_139 ;
}
V_23 -> V_138 = V_138 ;
return 0 ;
}
static int F_59 ( struct V_19 * V_20 ,
struct V_21 * V_159 )
{
struct V_1 * V_23 = F_10 ( V_20 -> V_18 ) ;
struct V_46 V_47 ;
int V_139 ;
V_47 . V_15 = V_159 ? V_159 -> V_25 : V_20 -> V_25 ;
V_47 . V_51 = V_159 ? V_159 -> V_51 : V_20 -> V_160 ;
if ( ! V_47 . V_51 )
V_47 . V_51 = V_20 -> V_160 ;
if ( ! V_47 . V_15 )
V_47 . V_15 = V_20 -> V_25 ;
if ( V_47 . V_15 <= 8 ) {
V_23 -> V_134 = V_161 ;
V_23 -> V_129 = V_162 ;
} else if ( V_47 . V_15 <= 16 ) {
V_23 -> V_134 = V_163 ;
V_23 -> V_129 = V_164 ;
} else {
V_23 -> V_134 = V_165 ;
V_23 -> V_129 = V_166 ;
}
if ( F_9 ( V_23 -> V_167 . V_18 , V_20 , V_159 ) )
V_23 -> V_65 = 1 ;
else
V_23 -> V_65 = 0 ;
if ( V_23 -> V_65 ) {
V_139 = F_57 ( V_20 -> V_18 ,
F_7 ( V_47 . V_15 ) ) ;
if ( V_139 )
return V_139 ;
}
V_23 -> V_3 -> V_47 ( V_20 , & V_47 ) ;
return 0 ;
}
static void F_60 ( struct V_1 * V_23 )
{
struct V_17 * V_18 = V_23 -> V_167 . V_18 ;
if ( V_18 -> V_24 ) {
F_61 ( V_18 -> V_24 ) ;
V_18 -> V_24 = NULL ;
}
if ( V_18 -> V_154 ) {
F_61 ( V_18 -> V_154 ) ;
V_18 -> V_154 = NULL ;
}
}
static int F_62 ( struct V_168 * V_31 , struct V_1 * V_23 ,
struct V_17 * V_18 )
{
int V_139 ;
if ( F_63 ( L_5 ) )
return 0 ;
V_23 -> V_27 = F_4 ( V_23 ) / 2 ;
V_18 -> V_154 = F_64 ( V_31 , L_6 ) ;
if ( F_65 ( V_18 -> V_154 ) ) {
V_139 = F_66 ( V_18 -> V_154 ) ;
F_15 ( V_31 , L_7 , V_139 ) ;
V_18 -> V_154 = NULL ;
goto V_169;
}
V_18 -> V_24 = F_64 ( V_31 , L_8 ) ;
if ( F_65 ( V_18 -> V_24 ) ) {
V_139 = F_66 ( V_18 -> V_24 ) ;
F_15 ( V_31 , L_9 , V_139 ) ;
V_18 -> V_24 = NULL ;
goto V_169;
}
F_57 ( V_18 , 1 ) ;
F_67 ( & V_23 -> V_170 ) ;
F_67 ( & V_23 -> V_171 ) ;
V_18 -> V_172 = F_9 ;
V_18 -> V_173 = V_174 ;
V_23 -> V_167 . V_18 -> V_175 = V_176 |
V_177 ;
return 0 ;
V_169:
F_60 ( V_23 ) ;
return V_139 ;
}
static void F_68 ( void * V_178 )
{
struct V_1 * V_23 = (struct V_1 * ) V_178 ;
F_56 ( & V_23 -> V_170 ) ;
}
static void F_69 ( void * V_178 )
{
struct V_1 * V_23 = (struct V_1 * ) V_178 ;
F_56 ( & V_23 -> V_171 ) ;
}
static int F_70 ( struct V_1 * V_23 , int V_179 )
{
unsigned long V_180 = 0 ;
V_180 = ( 8 + 4 ) * V_179 / V_23 -> V_59 ;
V_180 += 1 ;
return F_71 ( 2 * V_180 * V_181 ) ;
}
static int F_72 ( struct V_1 * V_23 ,
struct V_21 * V_22 )
{
struct V_182 * V_183 , * V_184 ;
unsigned long V_185 ;
unsigned long V_180 ;
struct V_17 * V_18 = V_23 -> V_167 . V_18 ;
struct V_186 * V_129 = & V_22 -> V_187 , * V_134 = & V_22 -> V_188 ;
V_184 = F_73 ( V_18 -> V_24 ,
V_134 -> V_189 , V_134 -> V_190 , V_155 ,
V_191 | V_192 ) ;
if ( ! V_184 )
return - V_146 ;
V_184 -> V_193 = F_68 ;
V_184 -> V_194 = ( void * ) V_23 ;
F_74 ( V_184 ) ;
F_75 ( & V_23 -> V_170 ) ;
F_76 ( V_18 -> V_24 ) ;
V_183 = F_73 ( V_18 -> V_154 ,
V_129 -> V_189 , V_129 -> V_190 , V_148 ,
V_191 | V_192 ) ;
if ( ! V_183 ) {
F_77 ( V_18 -> V_154 ) ;
return - V_146 ;
}
V_183 -> V_193 = F_69 ;
V_183 -> V_194 = ( void * ) V_23 ;
F_74 ( V_183 ) ;
F_75 ( & V_23 -> V_171 ) ;
F_76 ( V_18 -> V_154 ) ;
V_185 = F_70 ( V_23 , V_22 -> V_26 ) ;
V_180 = F_78 ( & V_23 -> V_171 ,
V_185 ) ;
if ( ! V_180 ) {
F_14 ( V_23 -> V_31 , L_10 ) ;
F_77 ( V_18 -> V_154 ) ;
F_77 ( V_18 -> V_24 ) ;
return - V_195 ;
}
V_180 = F_78 ( & V_23 -> V_170 ,
V_185 ) ;
if ( ! V_180 ) {
F_14 ( & V_18 -> V_31 , L_11 ) ;
V_23 -> V_3 -> V_196 ( V_23 ) ;
F_77 ( V_18 -> V_24 ) ;
return - V_195 ;
}
return V_22 -> V_26 ;
}
static int F_79 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_1 * V_23 = F_10 ( V_20 -> V_18 ) ;
unsigned long V_185 ;
unsigned long V_180 ;
V_23 -> V_197 = V_22 -> V_197 ;
V_23 -> V_198 = V_22 -> V_198 ;
V_23 -> V_128 = V_22 -> V_26 ;
V_23 -> V_127 = 0 ;
F_75 ( & V_23 -> V_137 ) ;
F_54 ( V_23 ) ;
V_23 -> V_3 -> V_136 ( V_23 , V_37 ) ;
V_185 = F_70 ( V_23 , V_22 -> V_26 ) ;
V_180 = F_78 ( & V_23 -> V_137 ,
V_185 ) ;
if ( ! V_180 ) {
F_14 ( & V_20 -> V_31 , L_12 ) ;
V_23 -> V_3 -> V_196 ( V_23 ) ;
return - V_195 ;
}
return V_22 -> V_26 ;
}
static int F_80 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_1 * V_23 = F_10 ( V_20 -> V_18 ) ;
if ( V_23 -> V_65 )
return F_72 ( V_23 , V_22 ) ;
else
return F_79 ( V_20 , V_22 ) ;
}
static int F_81 ( struct V_19 * V_20 )
{
F_15 ( & V_20 -> V_31 , L_13 , V_32 ,
V_20 -> V_56 , V_20 -> V_25 , V_20 -> V_160 ) ;
if ( F_52 ( V_20 -> V_91 ) )
F_82 ( V_20 -> V_91 ,
V_20 -> V_56 & V_64 ? 0 : 1 ) ;
F_51 ( V_20 , V_125 ) ;
return 0 ;
}
static void F_83 ( struct V_19 * V_20 )
{
}
static int
F_84 ( struct V_17 * V_18 , struct V_199 * V_200 )
{
struct V_1 * V_23 = F_10 ( V_18 ) ;
int V_139 ;
V_139 = F_85 ( V_23 -> V_201 ) ;
if ( V_139 )
return V_139 ;
V_139 = F_85 ( V_23 -> V_202 ) ;
if ( V_139 ) {
F_86 ( V_23 -> V_201 ) ;
return V_139 ;
}
return 0 ;
}
static int
F_87 ( struct V_17 * V_18 , struct V_199 * V_200 )
{
struct V_1 * V_23 = F_10 ( V_18 ) ;
F_86 ( V_23 -> V_202 ) ;
F_86 ( V_23 -> V_201 ) ;
return 0 ;
}
static int F_88 ( struct V_203 * V_204 )
{
struct V_205 * V_206 = V_204 -> V_31 . V_207 ;
const struct V_208 * V_209 =
F_89 ( V_210 , & V_204 -> V_31 ) ;
struct V_211 * V_212 =
F_90 ( & V_204 -> V_31 ) ;
struct V_17 * V_18 ;
struct V_1 * V_23 ;
struct V_213 * V_214 ;
int V_12 , V_139 , V_131 , V_58 ;
if ( ! V_206 && ! V_212 ) {
F_14 ( & V_204 -> V_31 , L_14 ) ;
return - V_146 ;
}
V_18 = F_91 ( & V_204 -> V_31 , sizeof( struct V_1 ) ) ;
V_139 = F_92 ( V_206 , L_15 , & V_58 ) ;
if ( ( V_139 < 0 ) || ( V_58 >= 0x3 ) ) {
V_58 = 0 ;
}
if ( ! V_18 )
return - V_215 ;
F_93 ( V_204 , V_18 ) ;
V_18 -> V_216 = F_94 ( 1 , 32 ) ;
V_18 -> V_217 = V_206 ? - 1 : V_204 -> V_218 ;
V_23 = F_10 ( V_18 ) ;
V_23 -> V_167 . V_18 = V_18 ;
V_23 -> V_31 = & V_204 -> V_31 ;
V_23 -> V_3 = V_209 ? V_209 -> V_219 :
(struct V_220 * ) V_204 -> V_221 -> V_222 ;
if ( V_212 ) {
V_18 -> V_223 = V_212 -> V_223 ;
V_18 -> V_224 = F_95 ( & V_18 -> V_31 ,
sizeof( int ) * V_18 -> V_223 , V_225 ) ;
if ( ! V_18 -> V_224 )
return - V_215 ;
for ( V_12 = 0 ; V_12 < V_18 -> V_223 ; V_12 ++ )
V_18 -> V_224 [ V_12 ] = V_212 -> V_226 [ V_12 ] ;
}
V_23 -> V_167 . V_226 = F_51 ;
V_23 -> V_167 . V_227 = F_59 ;
V_23 -> V_167 . V_228 = F_80 ;
V_23 -> V_167 . V_18 -> V_229 = F_81 ;
V_23 -> V_167 . V_18 -> V_230 = F_83 ;
V_23 -> V_167 . V_18 -> V_231 = F_84 ;
V_23 -> V_167 . V_18 -> V_232 = F_87 ;
V_23 -> V_167 . V_18 -> V_233 = V_63 | V_62 | V_64 ;
if ( F_2 ( V_23 ) || F_3 ( V_23 ) )
V_23 -> V_167 . V_18 -> V_233 |= V_68 | V_57 ;
V_23 -> V_58 = V_58 ;
F_67 ( & V_23 -> V_137 ) ;
V_214 = F_96 ( V_204 , V_234 , 0 ) ;
V_23 -> V_41 = F_97 ( & V_204 -> V_31 , V_214 ) ;
if ( F_65 ( V_23 -> V_41 ) ) {
V_139 = F_66 ( V_23 -> V_41 ) ;
goto V_235;
}
V_23 -> V_150 = V_214 -> V_236 ;
V_131 = F_98 ( V_204 , 0 ) ;
if ( V_131 < 0 ) {
V_139 = V_131 ;
goto V_235;
}
V_139 = F_99 ( & V_204 -> V_31 , V_131 , F_55 , 0 ,
F_100 ( & V_204 -> V_31 ) , V_23 ) ;
if ( V_139 ) {
F_14 ( & V_204 -> V_31 , L_16 , V_131 , V_139 ) ;
goto V_235;
}
V_23 -> V_202 = F_101 ( & V_204 -> V_31 , L_17 ) ;
if ( F_65 ( V_23 -> V_202 ) ) {
V_139 = F_66 ( V_23 -> V_202 ) ;
goto V_235;
}
V_23 -> V_201 = F_101 ( & V_204 -> V_31 , L_18 ) ;
if ( F_65 ( V_23 -> V_201 ) ) {
V_139 = F_66 ( V_23 -> V_201 ) ;
goto V_235;
}
V_139 = F_102 ( V_23 -> V_201 ) ;
if ( V_139 )
goto V_235;
V_139 = F_102 ( V_23 -> V_202 ) ;
if ( V_139 )
goto V_237;
V_23 -> V_30 = F_103 ( V_23 -> V_201 ) ;
if ( F_2 ( V_23 ) || F_3 ( V_23 ) ) {
V_139 = F_62 ( & V_204 -> V_31 , V_23 , V_18 ) ;
if ( V_139 == - V_238 )
goto V_239;
if ( V_139 < 0 )
F_14 ( & V_204 -> V_31 , L_19 ,
V_139 ) ;
}
V_23 -> V_3 -> V_196 ( V_23 ) ;
V_23 -> V_3 -> V_136 ( V_23 , 0 ) ;
V_18 -> V_31 . V_207 = V_204 -> V_31 . V_207 ;
V_139 = F_104 ( & V_23 -> V_167 ) ;
if ( V_139 ) {
F_14 ( & V_204 -> V_31 , L_20 , V_139 ) ;
goto V_239;
}
if ( ! V_18 -> V_224 ) {
F_14 ( & V_204 -> V_31 , L_21 ) ;
V_139 = - V_146 ;
goto V_239;
}
for ( V_12 = 0 ; V_12 < V_18 -> V_223 ; V_12 ++ ) {
if ( ! F_52 ( V_18 -> V_224 [ V_12 ] ) )
continue;
V_139 = F_105 ( & V_204 -> V_31 , V_18 -> V_224 [ V_12 ] ,
V_240 ) ;
if ( V_139 ) {
F_14 ( & V_204 -> V_31 , L_22 ,
V_18 -> V_224 [ V_12 ] ) ;
goto V_239;
}
}
F_106 ( & V_204 -> V_31 , L_23 ) ;
F_86 ( V_23 -> V_202 ) ;
F_86 ( V_23 -> V_201 ) ;
return V_139 ;
V_239:
F_107 ( V_23 -> V_202 ) ;
V_237:
F_107 ( V_23 -> V_201 ) ;
V_235:
F_108 ( V_18 ) ;
return V_139 ;
}
static int F_109 ( struct V_203 * V_204 )
{
struct V_17 * V_18 = F_110 ( V_204 ) ;
struct V_1 * V_23 = F_10 ( V_18 ) ;
F_111 ( & V_23 -> V_167 ) ;
F_17 ( 0 , V_23 -> V_41 + V_80 ) ;
F_112 ( V_23 -> V_202 ) ;
F_112 ( V_23 -> V_201 ) ;
F_60 ( V_23 ) ;
F_108 ( V_18 ) ;
return 0 ;
}
