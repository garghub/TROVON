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
V_48 |= F_11 ( V_23 , V_47 -> V_51 , & V_50 ) ;
V_23 -> V_56 = V_50 ;
V_48 |= F_21 ( V_20 -> V_57 ) ;
V_48 |= ( V_47 -> V_15 - 1 ) << V_58 ;
V_53 |= F_22 ( V_20 -> V_57 ) ;
if ( V_20 -> V_59 & V_60 )
V_53 |= F_23 ( V_20 -> V_57 ) ;
else
V_53 &= ~ F_23 ( V_20 -> V_57 ) ;
if ( V_20 -> V_59 & V_61 ) {
V_53 |= F_24 ( V_20 -> V_57 ) ;
V_53 |= F_25 ( V_20 -> V_57 ) ;
} else {
V_53 &= ~ F_24 ( V_20 -> V_57 ) ;
V_53 &= ~ F_25 ( V_20 -> V_57 ) ;
}
if ( V_20 -> V_59 & V_62 )
V_53 |= F_26 ( V_20 -> V_57 ) ;
else
V_53 &= ~ F_26 ( V_20 -> V_57 ) ;
if ( V_23 -> V_63 )
V_48 |= V_64 ;
F_17 ( V_48 , V_23 -> V_41 + V_44 ) ;
V_43 = F_19 ( V_23 -> V_41 + V_65 ) ;
if ( V_20 -> V_59 & V_66 )
V_43 |= V_67 ;
else
V_43 &= ~ V_67 ;
F_17 ( V_43 , V_23 -> V_41 + V_65 ) ;
F_17 ( V_53 , V_23 -> V_41 + V_54 ) ;
V_52 = ( 2 * 1000000 ) / V_50 ;
if ( F_27 ( V_52 < 10 ) )
F_28 ( V_52 ) ;
else
F_29 ( V_52 , V_52 + 10 ) ;
F_17 ( F_30 ( V_23 -> V_27 ) |
F_31 ( V_23 -> V_27 ) |
F_32 ( V_23 -> V_27 ) |
V_68 | V_69 |
V_70 , V_23 -> V_41 + V_71 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_23 )
{
return F_19 ( V_23 -> V_41 + V_72 ) & V_73 ;
}
static void F_34 ( struct V_1 * V_23 )
{
while ( F_33 ( V_23 ) )
F_19 ( V_23 -> V_41 + V_74 ) ;
}
static void F_35 ( struct V_1 * V_23 , int V_35 )
{
unsigned int V_36 = 0 ;
if ( V_35 & V_37 )
V_36 |= V_75 ;
if ( V_35 & V_39 )
V_36 |= V_76 ;
F_17 ( V_36 , V_23 -> V_41 + V_77 ) ;
}
static void F_36 ( struct V_1 * V_23 )
{
unsigned int V_43 ;
V_43 = F_19 ( V_23 -> V_41 + V_78 ) ;
V_43 |= V_79 ;
F_17 ( V_43 , V_23 -> V_41 + V_78 ) ;
}
static int F_37 ( struct V_19 * V_20 , struct V_46 * V_47 )
{
struct V_1 * V_23 = F_10 ( V_20 -> V_18 ) ;
unsigned int V_43 = V_80 | V_81 ;
unsigned int V_50 ;
V_43 |= F_6 ( V_23 -> V_30 , V_47 -> V_51 , & V_50 ) <<
V_82 ;
V_23 -> V_56 = V_50 ;
if ( F_2 ( V_23 ) ) {
V_43 |= ( V_47 -> V_15 - 1 ) << V_83 ;
V_43 |= V_84 ;
} else {
V_43 |= ( V_47 -> V_15 - 1 ) << V_85 ;
}
if ( V_20 -> V_59 & V_60 )
V_43 |= V_86 ;
if ( V_20 -> V_59 & V_61 )
V_43 |= V_87 ;
if ( V_20 -> V_59 & V_62 )
V_43 |= V_88 ;
if ( V_20 -> V_89 < 0 )
V_43 |= ( V_20 -> V_89 + 32 ) <<
( F_2 ( V_23 ) ? V_90 :
V_91 ) ;
if ( V_23 -> V_63 )
V_43 |= V_92 ;
F_17 ( V_43 , V_23 -> V_41 + V_78 ) ;
V_43 = F_19 ( V_23 -> V_41 + V_93 ) ;
if ( V_20 -> V_59 & V_66 )
V_43 |= V_94 ;
else
V_43 &= ~ V_94 ;
F_17 ( V_43 , V_23 -> V_41 + V_93 ) ;
if ( V_23 -> V_63 ) {
F_17 ( V_95 | V_96 ,
V_23 -> V_41 + V_97 ) ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_23 )
{
return F_19 ( V_23 -> V_41 + V_98 ) & V_99 ;
}
static void F_39 ( struct V_1 * V_23 )
{
while ( F_19 ( V_23 -> V_41 + V_98 ) & V_99 )
F_19 ( V_23 -> V_41 + V_74 ) ;
}
static void F_40 ( struct V_1 * V_23 , int V_35 )
{
unsigned int V_36 = 0 ;
if ( V_35 & V_37 )
V_36 |= V_100 ;
if ( V_35 & V_39 )
V_36 |= V_101 ;
F_17 ( V_36 , V_23 -> V_41 + V_77 ) ;
}
static void F_41 ( struct V_1 * V_23 )
{
unsigned int V_43 ;
V_43 = F_19 ( V_23 -> V_41 + V_78 ) ;
V_43 |= V_102 ;
F_17 ( V_43 , V_23 -> V_41 + V_78 ) ;
}
static int F_42 ( struct V_19 * V_20 , struct V_46 * V_47 )
{
struct V_1 * V_23 = F_10 ( V_20 -> V_18 ) ;
unsigned int V_43 = V_103 | V_104 ;
unsigned int V_10 = F_1 ( V_23 ) ? 16 : 18 ;
unsigned int V_50 ;
V_43 |= F_5 ( V_23 -> V_30 , V_47 -> V_51 , V_10 , & V_50 )
<< V_105 ;
V_23 -> V_56 = V_50 ;
V_43 |= V_47 -> V_15 - 1 ;
if ( V_20 -> V_59 & V_60 )
V_43 |= V_106 ;
if ( V_20 -> V_59 & V_61 )
V_43 |= V_107 ;
if ( V_20 -> V_59 & V_62 )
V_43 |= V_108 ;
if ( V_20 -> V_89 < 0 )
V_43 |= ( V_20 -> V_89 + 32 ) << V_109 ;
F_17 ( V_43 , V_23 -> V_41 + V_78 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_23 )
{
return F_19 ( V_23 -> V_41 + V_77 ) & V_110 ;
}
static void F_44 ( struct V_1 * V_23 )
{
F_17 ( 1 , V_23 -> V_41 + V_111 ) ;
}
static void F_45 ( struct V_1 * V_23 , int V_35 )
{
unsigned int V_36 = 0 ;
if ( V_35 & V_37 )
V_36 |= V_112 ;
if ( V_35 & V_39 )
V_36 |= V_113 ;
F_17 ( V_36 , V_23 -> V_41 + V_77 ) ;
}
static void F_46 ( struct V_1 * V_23 )
{
unsigned int V_43 ;
V_43 = F_19 ( V_23 -> V_41 + V_78 ) ;
V_43 |= V_114 ;
F_17 ( V_43 , V_23 -> V_41 + V_78 ) ;
}
static int F_47 ( struct V_19 * V_20 , struct V_46 * V_47 )
{
struct V_1 * V_23 = F_10 ( V_20 -> V_18 ) ;
unsigned int V_43 = V_115 | V_116 ;
unsigned int V_50 ;
V_43 |= F_6 ( V_23 -> V_30 , V_47 -> V_51 , & V_50 ) <<
V_117 ;
V_23 -> V_56 = V_50 ;
V_43 |= V_47 -> V_15 - 1 ;
if ( V_20 -> V_59 & V_60 )
V_43 |= V_118 ;
if ( V_20 -> V_59 & V_61 )
V_43 |= V_119 ;
F_17 ( V_43 , V_23 -> V_41 + V_78 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_23 )
{
return F_19 ( V_23 -> V_41 + V_77 ) & V_120 ;
}
static void F_49 ( struct V_1 * V_23 )
{
F_17 ( 1 , V_23 -> V_41 + V_111 ) ;
}
static void F_50 ( struct V_19 * V_20 , int V_121 )
{
int V_122 = V_121 != V_123 ;
int V_124 = ! ( V_20 -> V_59 & V_62 ) ;
if ( ! F_51 ( V_20 -> V_89 ) )
return;
F_52 ( V_20 -> V_89 , V_124 ^ V_122 ) ;
}
static void F_53 ( struct V_1 * V_23 )
{
while ( V_23 -> V_125 < F_4 ( V_23 ) ) {
if ( ! V_23 -> V_126 )
break;
V_23 -> V_127 ( V_23 ) ;
V_23 -> V_125 ++ ;
}
V_23 -> V_3 -> V_128 ( V_23 ) ;
}
static T_2 F_54 ( int V_129 , void * V_130 )
{
struct V_1 * V_23 = V_130 ;
while ( V_23 -> V_3 -> V_131 ( V_23 ) ) {
V_23 -> V_132 ( V_23 ) ;
V_23 -> V_125 -- ;
}
if ( V_23 -> V_126 ) {
F_53 ( V_23 ) ;
return V_133 ;
}
if ( V_23 -> V_125 ) {
V_23 -> V_3 -> V_134 (
V_23 , V_39 ) ;
return V_133 ;
}
V_23 -> V_3 -> V_134 ( V_23 , 0 ) ;
F_55 ( & V_23 -> V_135 ) ;
return V_133 ;
}
static int F_56 ( struct V_17 * V_18 ,
int V_136 )
{
int V_137 ;
enum V_138 V_139 ;
struct V_140 V_132 = {} , V_127 = {} ;
struct V_1 * V_23 = F_10 ( V_18 ) ;
switch ( V_136 ) {
case 4 :
V_139 = V_141 ;
break;
case 2 :
V_139 = V_142 ;
break;
case 1 :
V_139 = V_143 ;
break;
default:
return - V_144 ;
}
V_127 . V_145 = V_146 ;
V_127 . V_147 = V_23 -> V_148 + V_149 ;
V_127 . V_150 = V_139 ;
V_127 . V_151 = V_23 -> V_27 ;
V_137 = F_57 ( V_18 -> V_152 , & V_127 ) ;
if ( V_137 ) {
F_14 ( V_23 -> V_31 , L_3 , V_137 ) ;
return V_137 ;
}
V_132 . V_145 = V_153 ;
V_132 . V_154 = V_23 -> V_148 + V_74 ;
V_132 . V_155 = V_139 ;
V_132 . V_156 = V_23 -> V_27 ;
V_137 = F_57 ( V_18 -> V_24 , & V_132 ) ;
if ( V_137 ) {
F_14 ( V_23 -> V_31 , L_4 , V_137 ) ;
return V_137 ;
}
V_23 -> V_136 = V_136 ;
return 0 ;
}
static int F_58 ( struct V_19 * V_20 ,
struct V_21 * V_157 )
{
struct V_1 * V_23 = F_10 ( V_20 -> V_18 ) ;
struct V_46 V_47 ;
int V_137 ;
V_47 . V_15 = V_157 ? V_157 -> V_25 : V_20 -> V_25 ;
V_47 . V_51 = V_157 ? V_157 -> V_51 : V_20 -> V_158 ;
if ( ! V_47 . V_51 )
V_47 . V_51 = V_20 -> V_158 ;
if ( ! V_47 . V_15 )
V_47 . V_15 = V_20 -> V_25 ;
if ( V_47 . V_15 <= 8 ) {
V_23 -> V_132 = V_159 ;
V_23 -> V_127 = V_160 ;
} else if ( V_47 . V_15 <= 16 ) {
V_23 -> V_132 = V_161 ;
V_23 -> V_127 = V_162 ;
} else {
V_23 -> V_132 = V_163 ;
V_23 -> V_127 = V_164 ;
}
if ( F_9 ( V_23 -> V_165 . V_18 , V_20 , V_157 ) )
V_23 -> V_63 = 1 ;
else
V_23 -> V_63 = 0 ;
if ( V_23 -> V_63 ) {
V_137 = F_56 ( V_20 -> V_18 ,
F_7 ( V_47 . V_15 ) ) ;
if ( V_137 )
return V_137 ;
}
V_23 -> V_3 -> V_47 ( V_20 , & V_47 ) ;
return 0 ;
}
static void F_59 ( struct V_1 * V_23 )
{
struct V_17 * V_18 = V_23 -> V_165 . V_18 ;
if ( V_18 -> V_24 ) {
F_60 ( V_18 -> V_24 ) ;
V_18 -> V_24 = NULL ;
}
if ( V_18 -> V_152 ) {
F_60 ( V_18 -> V_152 ) ;
V_18 -> V_152 = NULL ;
}
}
static int F_61 ( struct V_166 * V_31 , struct V_1 * V_23 ,
struct V_17 * V_18 )
{
int V_137 ;
if ( F_62 ( L_5 ) )
return 0 ;
V_23 -> V_27 = F_4 ( V_23 ) / 2 ;
V_18 -> V_152 = F_63 ( V_31 , L_6 ) ;
if ( F_64 ( V_18 -> V_152 ) ) {
V_137 = F_65 ( V_18 -> V_152 ) ;
F_15 ( V_31 , L_7 , V_137 ) ;
V_18 -> V_152 = NULL ;
goto V_167;
}
V_18 -> V_24 = F_63 ( V_31 , L_8 ) ;
if ( F_64 ( V_18 -> V_24 ) ) {
V_137 = F_65 ( V_18 -> V_24 ) ;
F_15 ( V_31 , L_9 , V_137 ) ;
V_18 -> V_24 = NULL ;
goto V_167;
}
F_56 ( V_18 , 1 ) ;
F_66 ( & V_23 -> V_168 ) ;
F_66 ( & V_23 -> V_169 ) ;
V_18 -> V_170 = F_9 ;
V_18 -> V_171 = V_172 ;
V_23 -> V_165 . V_18 -> V_173 = V_174 |
V_175 ;
return 0 ;
V_167:
F_59 ( V_23 ) ;
return V_137 ;
}
static void F_67 ( void * V_176 )
{
struct V_1 * V_23 = (struct V_1 * ) V_176 ;
F_55 ( & V_23 -> V_168 ) ;
}
static void F_68 ( void * V_176 )
{
struct V_1 * V_23 = (struct V_1 * ) V_176 ;
F_55 ( & V_23 -> V_169 ) ;
}
static int F_69 ( struct V_1 * V_23 , int V_177 )
{
unsigned long V_178 = 0 ;
V_178 = ( 8 + 4 ) * V_177 / V_23 -> V_56 ;
V_178 += 1 ;
return F_70 ( 2 * V_178 * V_179 ) ;
}
static int F_71 ( struct V_1 * V_23 ,
struct V_21 * V_22 )
{
struct V_180 * V_181 , * V_182 ;
unsigned long V_183 ;
unsigned long V_178 ;
struct V_17 * V_18 = V_23 -> V_165 . V_18 ;
struct V_184 * V_127 = & V_22 -> V_185 , * V_132 = & V_22 -> V_186 ;
V_182 = F_72 ( V_18 -> V_24 ,
V_132 -> V_187 , V_132 -> V_188 , V_153 ,
V_189 | V_190 ) ;
if ( ! V_182 )
return - V_144 ;
V_182 -> V_191 = F_67 ;
V_182 -> V_192 = ( void * ) V_23 ;
F_73 ( V_182 ) ;
F_74 ( & V_23 -> V_168 ) ;
F_75 ( V_18 -> V_24 ) ;
V_181 = F_72 ( V_18 -> V_152 ,
V_127 -> V_187 , V_127 -> V_188 , V_146 ,
V_189 | V_190 ) ;
if ( ! V_181 ) {
F_76 ( V_18 -> V_152 ) ;
return - V_144 ;
}
V_181 -> V_191 = F_68 ;
V_181 -> V_192 = ( void * ) V_23 ;
F_73 ( V_181 ) ;
F_74 ( & V_23 -> V_169 ) ;
F_75 ( V_18 -> V_152 ) ;
V_183 = F_69 ( V_23 , V_22 -> V_26 ) ;
V_178 = F_77 ( & V_23 -> V_169 ,
V_183 ) ;
if ( ! V_178 ) {
F_14 ( V_23 -> V_31 , L_10 ) ;
F_76 ( V_18 -> V_152 ) ;
F_76 ( V_18 -> V_24 ) ;
return - V_193 ;
}
V_178 = F_77 ( & V_23 -> V_168 ,
V_183 ) ;
if ( ! V_178 ) {
F_14 ( & V_18 -> V_31 , L_11 ) ;
V_23 -> V_3 -> V_194 ( V_23 ) ;
F_76 ( V_18 -> V_24 ) ;
return - V_193 ;
}
return V_22 -> V_26 ;
}
static int F_78 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_1 * V_23 = F_10 ( V_20 -> V_18 ) ;
unsigned long V_183 ;
unsigned long V_178 ;
V_23 -> V_195 = V_22 -> V_195 ;
V_23 -> V_196 = V_22 -> V_196 ;
V_23 -> V_126 = V_22 -> V_26 ;
V_23 -> V_125 = 0 ;
F_74 ( & V_23 -> V_135 ) ;
F_53 ( V_23 ) ;
V_23 -> V_3 -> V_134 ( V_23 , V_37 ) ;
V_183 = F_69 ( V_23 , V_22 -> V_26 ) ;
V_178 = F_77 ( & V_23 -> V_135 ,
V_183 ) ;
if ( ! V_178 ) {
F_14 ( & V_20 -> V_31 , L_12 ) ;
V_23 -> V_3 -> V_194 ( V_23 ) ;
return - V_193 ;
}
return V_22 -> V_26 ;
}
static int F_79 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_1 * V_23 = F_10 ( V_20 -> V_18 ) ;
if ( V_23 -> V_63 )
return F_71 ( V_23 , V_22 ) ;
else
return F_78 ( V_20 , V_22 ) ;
}
static int F_80 ( struct V_19 * V_20 )
{
F_15 ( & V_20 -> V_31 , L_13 , V_32 ,
V_20 -> V_59 , V_20 -> V_25 , V_20 -> V_158 ) ;
if ( F_51 ( V_20 -> V_89 ) )
F_81 ( V_20 -> V_89 ,
V_20 -> V_59 & V_62 ? 0 : 1 ) ;
F_50 ( V_20 , V_123 ) ;
return 0 ;
}
static void F_82 ( struct V_19 * V_20 )
{
}
static int
F_83 ( struct V_17 * V_18 , struct V_197 * V_198 )
{
struct V_1 * V_23 = F_10 ( V_18 ) ;
int V_137 ;
V_137 = F_84 ( V_23 -> V_199 ) ;
if ( V_137 )
return V_137 ;
V_137 = F_84 ( V_23 -> V_200 ) ;
if ( V_137 ) {
F_85 ( V_23 -> V_199 ) ;
return V_137 ;
}
return 0 ;
}
static int
F_86 ( struct V_17 * V_18 , struct V_197 * V_198 )
{
struct V_1 * V_23 = F_10 ( V_18 ) ;
F_85 ( V_23 -> V_200 ) ;
F_85 ( V_23 -> V_199 ) ;
return 0 ;
}
static int F_87 ( struct V_201 * V_202 )
{
struct V_203 * V_204 = V_202 -> V_31 . V_205 ;
const struct V_206 * V_207 =
F_88 ( V_208 , & V_202 -> V_31 ) ;
struct V_209 * V_210 =
F_89 ( & V_202 -> V_31 ) ;
struct V_17 * V_18 ;
struct V_1 * V_23 ;
struct V_211 * V_212 ;
int V_12 , V_137 , V_129 ;
if ( ! V_204 && ! V_210 ) {
F_14 ( & V_202 -> V_31 , L_14 ) ;
return - V_144 ;
}
V_18 = F_90 ( & V_202 -> V_31 , sizeof( struct V_1 ) ) ;
if ( ! V_18 )
return - V_213 ;
F_91 ( V_202 , V_18 ) ;
V_18 -> V_214 = F_92 ( 1 , 32 ) ;
V_18 -> V_215 = V_204 ? - 1 : V_202 -> V_216 ;
V_23 = F_10 ( V_18 ) ;
V_23 -> V_165 . V_18 = V_18 ;
V_23 -> V_31 = & V_202 -> V_31 ;
V_23 -> V_3 = V_207 ? V_207 -> V_217 :
(struct V_218 * ) V_202 -> V_219 -> V_220 ;
if ( V_210 ) {
V_18 -> V_221 = V_210 -> V_221 ;
V_18 -> V_222 = F_93 ( & V_18 -> V_31 ,
sizeof( int ) * V_18 -> V_221 , V_223 ) ;
if ( ! V_18 -> V_222 )
return - V_213 ;
for ( V_12 = 0 ; V_12 < V_18 -> V_221 ; V_12 ++ )
V_18 -> V_222 [ V_12 ] = V_210 -> V_224 [ V_12 ] ;
}
V_23 -> V_165 . V_224 = F_50 ;
V_23 -> V_165 . V_225 = F_58 ;
V_23 -> V_165 . V_226 = F_79 ;
V_23 -> V_165 . V_18 -> V_227 = F_80 ;
V_23 -> V_165 . V_18 -> V_228 = F_82 ;
V_23 -> V_165 . V_18 -> V_229 = F_83 ;
V_23 -> V_165 . V_18 -> V_230 = F_86 ;
V_23 -> V_165 . V_18 -> V_231 = V_61 | V_60 | V_62 ;
if ( F_2 ( V_23 ) || F_3 ( V_23 ) )
V_23 -> V_165 . V_18 -> V_231 |= V_66 ;
F_66 ( & V_23 -> V_135 ) ;
V_212 = F_94 ( V_202 , V_232 , 0 ) ;
V_23 -> V_41 = F_95 ( & V_202 -> V_31 , V_212 ) ;
if ( F_64 ( V_23 -> V_41 ) ) {
V_137 = F_65 ( V_23 -> V_41 ) ;
goto V_233;
}
V_23 -> V_148 = V_212 -> V_234 ;
V_129 = F_96 ( V_202 , 0 ) ;
if ( V_129 < 0 ) {
V_137 = V_129 ;
goto V_233;
}
V_137 = F_97 ( & V_202 -> V_31 , V_129 , F_54 , 0 ,
F_98 ( & V_202 -> V_31 ) , V_23 ) ;
if ( V_137 ) {
F_14 ( & V_202 -> V_31 , L_15 , V_129 , V_137 ) ;
goto V_233;
}
V_23 -> V_200 = F_99 ( & V_202 -> V_31 , L_16 ) ;
if ( F_64 ( V_23 -> V_200 ) ) {
V_137 = F_65 ( V_23 -> V_200 ) ;
goto V_233;
}
V_23 -> V_199 = F_99 ( & V_202 -> V_31 , L_17 ) ;
if ( F_64 ( V_23 -> V_199 ) ) {
V_137 = F_65 ( V_23 -> V_199 ) ;
goto V_233;
}
V_137 = F_100 ( V_23 -> V_199 ) ;
if ( V_137 )
goto V_233;
V_137 = F_100 ( V_23 -> V_200 ) ;
if ( V_137 )
goto V_235;
V_23 -> V_30 = F_101 ( V_23 -> V_199 ) ;
if ( F_2 ( V_23 ) || F_3 ( V_23 ) ) {
V_137 = F_61 ( & V_202 -> V_31 , V_23 , V_18 ) ;
if ( V_137 == - V_236 )
goto V_237;
if ( V_137 < 0 )
F_14 ( & V_202 -> V_31 , L_18 ,
V_137 ) ;
}
V_23 -> V_3 -> V_194 ( V_23 ) ;
V_23 -> V_3 -> V_134 ( V_23 , 0 ) ;
V_18 -> V_31 . V_205 = V_202 -> V_31 . V_205 ;
V_137 = F_102 ( & V_23 -> V_165 ) ;
if ( V_137 ) {
F_14 ( & V_202 -> V_31 , L_19 , V_137 ) ;
goto V_237;
}
if ( ! V_18 -> V_222 ) {
F_14 ( & V_202 -> V_31 , L_20 ) ;
V_137 = - V_144 ;
goto V_237;
}
for ( V_12 = 0 ; V_12 < V_18 -> V_221 ; V_12 ++ ) {
if ( ! F_51 ( V_18 -> V_222 [ V_12 ] ) )
continue;
V_137 = F_103 ( & V_202 -> V_31 , V_18 -> V_222 [ V_12 ] ,
V_238 ) ;
if ( V_137 ) {
F_14 ( & V_202 -> V_31 , L_21 ,
V_18 -> V_222 [ V_12 ] ) ;
goto V_237;
}
}
F_104 ( & V_202 -> V_31 , L_22 ) ;
F_85 ( V_23 -> V_200 ) ;
F_85 ( V_23 -> V_199 ) ;
return V_137 ;
V_237:
F_105 ( V_23 -> V_200 ) ;
V_235:
F_105 ( V_23 -> V_199 ) ;
V_233:
F_106 ( V_18 ) ;
return V_137 ;
}
static int F_107 ( struct V_201 * V_202 )
{
struct V_17 * V_18 = F_108 ( V_202 ) ;
struct V_1 * V_23 = F_10 ( V_18 ) ;
F_109 ( & V_23 -> V_165 ) ;
F_17 ( 0 , V_23 -> V_41 + V_78 ) ;
F_110 ( V_23 -> V_200 ) ;
F_110 ( V_23 -> V_199 ) ;
F_59 ( V_23 ) ;
F_106 ( V_18 ) ;
return 0 ;
}
