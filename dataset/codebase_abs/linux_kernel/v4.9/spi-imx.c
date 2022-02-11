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
unsigned int V_9 , unsigned int V_10 )
{
int V_11 ;
for ( V_11 = 2 ; V_11 < V_10 ; V_11 ++ )
if ( V_9 * V_12 [ V_11 ] >= V_8 )
return V_11 ;
return V_10 ;
}
static unsigned int F_6 ( unsigned int V_8 ,
unsigned int V_9 , unsigned int * V_13 )
{
int V_11 , div = 4 ;
for ( V_11 = 0 ; V_11 < 7 ; V_11 ++ ) {
if ( V_9 * div >= V_8 )
goto V_14;
div <<= 1 ;
}
V_14:
* V_13 = V_8 / div ;
return V_11 ;
}
static int F_7 ( const int V_15 )
{
return F_8 ( V_15 , V_16 ) ;
}
static bool F_9 ( struct V_17 * V_18 , struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_1 * V_23 = F_10 ( V_18 ) ;
unsigned int V_15 ;
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
if ( V_22 -> V_26 < V_23 -> V_27 * V_15 )
return false ;
if ( V_22 -> V_26 % ( V_23 -> V_27 * V_15 ) )
return false ;
return true ;
}
static unsigned int F_11 ( struct V_1 * V_23 ,
unsigned int V_9 , unsigned int * V_13 )
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
* V_13 = ( V_8 / ( V_28 + 1 ) ) >> V_29 ;
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
F_17 ( V_43 , V_23 -> V_41 + V_78 ) ;
V_43 = F_19 ( V_23 -> V_41 + V_92 ) ;
if ( V_20 -> V_59 & V_66 )
V_43 |= V_93 ;
else
V_43 &= ~ V_93 ;
F_17 ( V_43 , V_23 -> V_41 + V_92 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_23 )
{
return F_19 ( V_23 -> V_41 + V_94 ) & V_95 ;
}
static void F_39 ( struct V_1 * V_23 )
{
while ( F_19 ( V_23 -> V_41 + V_94 ) & V_95 )
F_19 ( V_23 -> V_41 + V_74 ) ;
}
static void F_40 ( struct V_1 * V_23 , int V_35 )
{
unsigned int V_36 = 0 ;
if ( V_35 & V_37 )
V_36 |= V_96 ;
if ( V_35 & V_39 )
V_36 |= V_97 ;
F_17 ( V_36 , V_23 -> V_41 + V_77 ) ;
}
static void F_41 ( struct V_1 * V_23 )
{
unsigned int V_43 ;
V_43 = F_19 ( V_23 -> V_41 + V_78 ) ;
V_43 |= V_98 ;
F_17 ( V_43 , V_23 -> V_41 + V_78 ) ;
}
static int F_42 ( struct V_19 * V_20 , struct V_46 * V_47 )
{
struct V_1 * V_23 = F_10 ( V_20 -> V_18 ) ;
unsigned int V_43 = V_99 | V_100 ;
unsigned int V_10 = F_1 ( V_23 ) ? 16 : 18 ;
V_43 |= F_5 ( V_23 -> V_30 , V_47 -> V_51 , V_10 ) <<
V_101 ;
V_43 |= V_47 -> V_15 - 1 ;
if ( V_20 -> V_59 & V_60 )
V_43 |= V_102 ;
if ( V_20 -> V_59 & V_61 )
V_43 |= V_103 ;
if ( V_20 -> V_59 & V_62 )
V_43 |= V_104 ;
if ( V_20 -> V_89 < 0 )
V_43 |= ( V_20 -> V_89 + 32 ) << V_105 ;
F_17 ( V_43 , V_23 -> V_41 + V_78 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_23 )
{
return F_19 ( V_23 -> V_41 + V_77 ) & V_106 ;
}
static void F_44 ( struct V_1 * V_23 )
{
F_17 ( 1 , V_23 -> V_41 + V_107 ) ;
}
static void F_45 ( struct V_1 * V_23 , int V_35 )
{
unsigned int V_36 = 0 ;
if ( V_35 & V_37 )
V_36 |= V_108 ;
if ( V_35 & V_39 )
V_36 |= V_109 ;
F_17 ( V_36 , V_23 -> V_41 + V_77 ) ;
}
static void F_46 ( struct V_1 * V_23 )
{
unsigned int V_43 ;
V_43 = F_19 ( V_23 -> V_41 + V_78 ) ;
V_43 |= V_110 ;
F_17 ( V_43 , V_23 -> V_41 + V_78 ) ;
}
static int F_47 ( struct V_19 * V_20 , struct V_46 * V_47 )
{
struct V_1 * V_23 = F_10 ( V_20 -> V_18 ) ;
unsigned int V_43 = V_111 | V_112 ;
unsigned int V_50 ;
V_43 |= F_6 ( V_23 -> V_30 , V_47 -> V_51 , & V_50 ) <<
V_113 ;
V_23 -> V_56 = V_50 ;
V_43 |= V_47 -> V_15 - 1 ;
if ( V_20 -> V_59 & V_60 )
V_43 |= V_114 ;
if ( V_20 -> V_59 & V_61 )
V_43 |= V_115 ;
F_17 ( V_43 , V_23 -> V_41 + V_78 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_23 )
{
return F_19 ( V_23 -> V_41 + V_77 ) & V_116 ;
}
static void F_49 ( struct V_1 * V_23 )
{
F_17 ( 1 , V_23 -> V_41 + V_107 ) ;
}
static void F_50 ( struct V_19 * V_20 , int V_117 )
{
int V_118 = V_117 != V_119 ;
int V_120 = ! ( V_20 -> V_59 & V_62 ) ;
if ( ! F_51 ( V_20 -> V_89 ) )
return;
F_52 ( V_20 -> V_89 , V_120 ^ V_118 ) ;
}
static void F_53 ( struct V_1 * V_23 )
{
while ( V_23 -> V_121 < F_4 ( V_23 ) ) {
if ( ! V_23 -> V_122 )
break;
V_23 -> V_123 ( V_23 ) ;
V_23 -> V_121 ++ ;
}
V_23 -> V_3 -> V_124 ( V_23 ) ;
}
static T_2 F_54 ( int V_125 , void * V_126 )
{
struct V_1 * V_23 = V_126 ;
while ( V_23 -> V_3 -> V_127 ( V_23 ) ) {
V_23 -> V_128 ( V_23 ) ;
V_23 -> V_121 -- ;
}
if ( V_23 -> V_122 ) {
F_53 ( V_23 ) ;
return V_129 ;
}
if ( V_23 -> V_121 ) {
V_23 -> V_3 -> V_130 (
V_23 , V_39 ) ;
return V_129 ;
}
V_23 -> V_3 -> V_130 ( V_23 , 0 ) ;
F_55 ( & V_23 -> V_131 ) ;
return V_129 ;
}
static int F_56 ( struct V_17 * V_18 ,
int V_132 )
{
int V_133 ;
enum V_134 V_135 ;
struct V_136 V_128 = {} , V_123 = {} ;
struct V_1 * V_23 = F_10 ( V_18 ) ;
if ( V_132 == V_23 -> V_132 )
return 0 ;
switch ( V_132 ) {
case 4 :
V_135 = V_137 ;
break;
case 2 :
V_135 = V_138 ;
break;
case 1 :
V_135 = V_139 ;
break;
default:
return - V_140 ;
}
V_123 . V_141 = V_142 ;
V_123 . V_143 = V_23 -> V_144 + V_145 ;
V_123 . V_146 = V_135 ;
V_123 . V_147 = V_23 -> V_27 ;
V_133 = F_57 ( V_18 -> V_148 , & V_123 ) ;
if ( V_133 ) {
F_14 ( V_23 -> V_31 , L_3 , V_133 ) ;
return V_133 ;
}
V_128 . V_141 = V_149 ;
V_128 . V_150 = V_23 -> V_144 + V_74 ;
V_128 . V_151 = V_135 ;
V_128 . V_152 = V_23 -> V_27 ;
V_133 = F_57 ( V_18 -> V_24 , & V_128 ) ;
if ( V_133 ) {
F_14 ( V_23 -> V_31 , L_4 , V_133 ) ;
return V_133 ;
}
V_23 -> V_132 = V_132 ;
return 0 ;
}
static int F_58 ( struct V_19 * V_20 ,
struct V_21 * V_153 )
{
struct V_1 * V_23 = F_10 ( V_20 -> V_18 ) ;
struct V_46 V_47 ;
int V_133 ;
V_47 . V_15 = V_153 ? V_153 -> V_25 : V_20 -> V_25 ;
V_47 . V_51 = V_153 ? V_153 -> V_51 : V_20 -> V_154 ;
if ( ! V_47 . V_51 )
V_47 . V_51 = V_20 -> V_154 ;
if ( ! V_47 . V_15 )
V_47 . V_15 = V_20 -> V_25 ;
if ( V_47 . V_15 <= 8 ) {
V_23 -> V_128 = V_155 ;
V_23 -> V_123 = V_156 ;
} else if ( V_47 . V_15 <= 16 ) {
V_23 -> V_128 = V_157 ;
V_23 -> V_123 = V_158 ;
} else {
V_23 -> V_128 = V_159 ;
V_23 -> V_123 = V_160 ;
}
if ( F_9 ( V_23 -> V_161 . V_18 , V_20 , V_153 ) )
V_23 -> V_63 = 1 ;
else
V_23 -> V_63 = 0 ;
if ( V_23 -> V_63 ) {
V_133 = F_56 ( V_20 -> V_18 ,
F_7 ( V_47 . V_15 ) ) ;
if ( V_133 )
return V_133 ;
}
V_23 -> V_3 -> V_47 ( V_20 , & V_47 ) ;
return 0 ;
}
static void F_59 ( struct V_1 * V_23 )
{
struct V_17 * V_18 = V_23 -> V_161 . V_18 ;
if ( V_18 -> V_24 ) {
F_60 ( V_18 -> V_24 ) ;
V_18 -> V_24 = NULL ;
}
if ( V_18 -> V_148 ) {
F_60 ( V_18 -> V_148 ) ;
V_18 -> V_148 = NULL ;
}
}
static int F_61 ( struct V_162 * V_31 , struct V_1 * V_23 ,
struct V_17 * V_18 )
{
int V_133 ;
if ( F_62 ( L_5 ) )
return 0 ;
V_23 -> V_27 = F_4 ( V_23 ) / 2 ;
V_18 -> V_148 = F_63 ( V_31 , L_6 ) ;
if ( F_64 ( V_18 -> V_148 ) ) {
V_133 = F_65 ( V_18 -> V_148 ) ;
F_15 ( V_31 , L_7 , V_133 ) ;
V_18 -> V_148 = NULL ;
goto V_163;
}
V_18 -> V_24 = F_63 ( V_31 , L_8 ) ;
if ( F_64 ( V_18 -> V_24 ) ) {
V_133 = F_65 ( V_18 -> V_24 ) ;
F_15 ( V_31 , L_9 , V_133 ) ;
V_18 -> V_24 = NULL ;
goto V_163;
}
F_56 ( V_18 , 1 ) ;
F_66 ( & V_23 -> V_164 ) ;
F_66 ( & V_23 -> V_165 ) ;
V_18 -> V_166 = F_9 ;
V_18 -> V_167 = V_168 ;
V_23 -> V_161 . V_18 -> V_169 = V_170 |
V_171 ;
return 0 ;
V_163:
F_59 ( V_23 ) ;
return V_133 ;
}
static void F_67 ( void * V_172 )
{
struct V_1 * V_23 = (struct V_1 * ) V_172 ;
F_55 ( & V_23 -> V_164 ) ;
}
static void F_68 ( void * V_172 )
{
struct V_1 * V_23 = (struct V_1 * ) V_172 ;
F_55 ( & V_23 -> V_165 ) ;
}
static int F_69 ( struct V_1 * V_23 , int V_173 )
{
unsigned long V_174 = 0 ;
V_174 = ( 8 + 4 ) * V_173 / V_23 -> V_56 ;
V_174 += 1 ;
return F_70 ( 2 * V_174 * V_175 ) ;
}
static int F_71 ( struct V_1 * V_23 ,
struct V_21 * V_22 )
{
struct V_176 * V_177 , * V_178 ;
unsigned long V_179 ;
unsigned long V_174 ;
struct V_17 * V_18 = V_23 -> V_161 . V_18 ;
struct V_180 * V_123 = & V_22 -> V_181 , * V_128 = & V_22 -> V_182 ;
V_178 = F_72 ( V_18 -> V_24 ,
V_128 -> V_183 , V_128 -> V_184 , V_149 ,
V_185 | V_186 ) ;
if ( ! V_178 )
return - V_140 ;
V_178 -> V_187 = F_67 ;
V_178 -> V_188 = ( void * ) V_23 ;
F_73 ( V_178 ) ;
F_74 ( & V_23 -> V_164 ) ;
F_75 ( V_18 -> V_24 ) ;
V_177 = F_72 ( V_18 -> V_148 ,
V_123 -> V_183 , V_123 -> V_184 , V_142 ,
V_185 | V_186 ) ;
if ( ! V_177 ) {
F_76 ( V_18 -> V_148 ) ;
return - V_140 ;
}
V_177 -> V_187 = F_68 ;
V_177 -> V_188 = ( void * ) V_23 ;
F_73 ( V_177 ) ;
F_74 ( & V_23 -> V_165 ) ;
F_75 ( V_18 -> V_148 ) ;
V_179 = F_69 ( V_23 , V_22 -> V_26 ) ;
V_174 = F_77 ( & V_23 -> V_165 ,
V_179 ) ;
if ( ! V_174 ) {
F_14 ( V_23 -> V_31 , L_10 ) ;
F_76 ( V_18 -> V_148 ) ;
F_76 ( V_18 -> V_24 ) ;
return - V_189 ;
}
V_174 = F_77 ( & V_23 -> V_164 ,
V_179 ) ;
if ( ! V_174 ) {
F_14 ( & V_18 -> V_31 , L_11 ) ;
V_23 -> V_3 -> V_190 ( V_23 ) ;
F_76 ( V_18 -> V_24 ) ;
return - V_189 ;
}
return V_22 -> V_26 ;
}
static int F_78 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_1 * V_23 = F_10 ( V_20 -> V_18 ) ;
unsigned long V_179 ;
unsigned long V_174 ;
V_23 -> V_191 = V_22 -> V_191 ;
V_23 -> V_192 = V_22 -> V_192 ;
V_23 -> V_122 = V_22 -> V_26 ;
V_23 -> V_121 = 0 ;
F_74 ( & V_23 -> V_131 ) ;
F_53 ( V_23 ) ;
V_23 -> V_3 -> V_130 ( V_23 , V_37 ) ;
V_179 = F_69 ( V_23 , V_22 -> V_26 ) ;
V_174 = F_77 ( & V_23 -> V_131 ,
V_179 ) ;
if ( ! V_174 ) {
F_14 ( & V_20 -> V_31 , L_12 ) ;
V_23 -> V_3 -> V_190 ( V_23 ) ;
return - V_189 ;
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
V_20 -> V_59 , V_20 -> V_25 , V_20 -> V_154 ) ;
if ( F_51 ( V_20 -> V_89 ) )
F_81 ( V_20 -> V_89 ,
V_20 -> V_59 & V_62 ? 0 : 1 ) ;
F_50 ( V_20 , V_119 ) ;
return 0 ;
}
static void F_82 ( struct V_19 * V_20 )
{
}
static int
F_83 ( struct V_17 * V_18 , struct V_193 * V_194 )
{
struct V_1 * V_23 = F_10 ( V_18 ) ;
int V_133 ;
V_133 = F_84 ( V_23 -> V_195 ) ;
if ( V_133 )
return V_133 ;
V_133 = F_84 ( V_23 -> V_196 ) ;
if ( V_133 ) {
F_85 ( V_23 -> V_195 ) ;
return V_133 ;
}
return 0 ;
}
static int
F_86 ( struct V_17 * V_18 , struct V_193 * V_194 )
{
struct V_1 * V_23 = F_10 ( V_18 ) ;
F_85 ( V_23 -> V_196 ) ;
F_85 ( V_23 -> V_195 ) ;
return 0 ;
}
static int F_87 ( struct V_197 * V_198 )
{
struct V_199 * V_200 = V_198 -> V_31 . V_201 ;
const struct V_202 * V_203 =
F_88 ( V_204 , & V_198 -> V_31 ) ;
struct V_205 * V_206 =
F_89 ( & V_198 -> V_31 ) ;
struct V_17 * V_18 ;
struct V_1 * V_23 ;
struct V_207 * V_208 ;
int V_11 , V_133 , V_125 ;
if ( ! V_200 && ! V_206 ) {
F_14 ( & V_198 -> V_31 , L_14 ) ;
return - V_140 ;
}
V_18 = F_90 ( & V_198 -> V_31 , sizeof( struct V_1 ) ) ;
if ( ! V_18 )
return - V_209 ;
F_91 ( V_198 , V_18 ) ;
V_18 -> V_210 = F_92 ( 1 , 32 ) ;
V_18 -> V_211 = V_200 ? - 1 : V_198 -> V_212 ;
V_23 = F_10 ( V_18 ) ;
V_23 -> V_161 . V_18 = V_18 ;
V_23 -> V_31 = & V_198 -> V_31 ;
V_23 -> V_3 = V_203 ? V_203 -> V_213 :
(struct V_214 * ) V_198 -> V_215 -> V_216 ;
if ( V_206 ) {
V_18 -> V_217 = V_206 -> V_217 ;
V_18 -> V_218 = F_93 ( & V_18 -> V_31 ,
sizeof( int ) * V_18 -> V_217 , V_219 ) ;
if ( ! V_18 -> V_218 )
return - V_209 ;
for ( V_11 = 0 ; V_11 < V_18 -> V_217 ; V_11 ++ )
V_18 -> V_218 [ V_11 ] = V_206 -> V_220 [ V_11 ] ;
}
V_23 -> V_161 . V_220 = F_50 ;
V_23 -> V_161 . V_221 = F_58 ;
V_23 -> V_161 . V_222 = F_79 ;
V_23 -> V_161 . V_18 -> V_223 = F_80 ;
V_23 -> V_161 . V_18 -> V_224 = F_82 ;
V_23 -> V_161 . V_18 -> V_225 = F_83 ;
V_23 -> V_161 . V_18 -> V_226 = F_86 ;
V_23 -> V_161 . V_18 -> V_227 = V_61 | V_60 | V_62 ;
if ( F_2 ( V_23 ) || F_3 ( V_23 ) )
V_23 -> V_161 . V_18 -> V_227 |= V_66 ;
F_66 ( & V_23 -> V_131 ) ;
V_208 = F_94 ( V_198 , V_228 , 0 ) ;
V_23 -> V_41 = F_95 ( & V_198 -> V_31 , V_208 ) ;
if ( F_64 ( V_23 -> V_41 ) ) {
V_133 = F_65 ( V_23 -> V_41 ) ;
goto V_229;
}
V_23 -> V_144 = V_208 -> V_230 ;
V_125 = F_96 ( V_198 , 0 ) ;
if ( V_125 < 0 ) {
V_133 = V_125 ;
goto V_229;
}
V_133 = F_97 ( & V_198 -> V_31 , V_125 , F_54 , 0 ,
F_98 ( & V_198 -> V_31 ) , V_23 ) ;
if ( V_133 ) {
F_14 ( & V_198 -> V_31 , L_15 , V_125 , V_133 ) ;
goto V_229;
}
V_23 -> V_196 = F_99 ( & V_198 -> V_31 , L_16 ) ;
if ( F_64 ( V_23 -> V_196 ) ) {
V_133 = F_65 ( V_23 -> V_196 ) ;
goto V_229;
}
V_23 -> V_195 = F_99 ( & V_198 -> V_31 , L_17 ) ;
if ( F_64 ( V_23 -> V_195 ) ) {
V_133 = F_65 ( V_23 -> V_195 ) ;
goto V_229;
}
V_133 = F_100 ( V_23 -> V_195 ) ;
if ( V_133 )
goto V_229;
V_133 = F_100 ( V_23 -> V_196 ) ;
if ( V_133 )
goto V_231;
V_23 -> V_30 = F_101 ( V_23 -> V_195 ) ;
if ( F_3 ( V_23 ) ) {
V_133 = F_61 ( & V_198 -> V_31 , V_23 , V_18 ) ;
if ( V_133 == - V_232 )
goto V_233;
if ( V_133 < 0 )
F_14 ( & V_198 -> V_31 , L_18 ,
V_133 ) ;
}
V_23 -> V_3 -> V_190 ( V_23 ) ;
V_23 -> V_3 -> V_130 ( V_23 , 0 ) ;
V_18 -> V_31 . V_201 = V_198 -> V_31 . V_201 ;
V_133 = F_102 ( & V_23 -> V_161 ) ;
if ( V_133 ) {
F_14 ( & V_198 -> V_31 , L_19 , V_133 ) ;
goto V_233;
}
if ( ! V_18 -> V_218 ) {
F_14 ( & V_198 -> V_31 , L_20 ) ;
V_133 = - V_140 ;
goto V_233;
}
for ( V_11 = 0 ; V_11 < V_18 -> V_217 ; V_11 ++ ) {
if ( ! F_51 ( V_18 -> V_218 [ V_11 ] ) )
continue;
V_133 = F_103 ( & V_198 -> V_31 , V_18 -> V_218 [ V_11 ] ,
V_234 ) ;
if ( V_133 ) {
F_14 ( & V_198 -> V_31 , L_21 ,
V_18 -> V_218 [ V_11 ] ) ;
goto V_233;
}
}
F_104 ( & V_198 -> V_31 , L_22 ) ;
F_85 ( V_23 -> V_196 ) ;
F_85 ( V_23 -> V_195 ) ;
return V_133 ;
V_233:
F_105 ( V_23 -> V_196 ) ;
V_231:
F_105 ( V_23 -> V_195 ) ;
V_229:
F_106 ( V_18 ) ;
return V_133 ;
}
static int F_107 ( struct V_197 * V_198 )
{
struct V_17 * V_18 = F_108 ( V_198 ) ;
struct V_1 * V_23 = F_10 ( V_18 ) ;
F_109 ( & V_23 -> V_161 ) ;
F_17 ( 0 , V_23 -> V_41 + V_78 ) ;
F_110 ( V_23 -> V_196 ) ;
F_110 ( V_23 -> V_195 ) ;
F_59 ( V_23 ) ;
F_106 ( V_18 ) ;
return 0 ;
}
