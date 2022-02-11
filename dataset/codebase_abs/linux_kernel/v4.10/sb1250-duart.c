static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
void T_2 * V_4 = V_2 -> V_5 . V_6 + V_3 ;
return F_2 ( V_4 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
void T_2 * V_4 = V_2 -> V_7 + V_3 ;
return F_2 ( V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_3 , T_1 V_8 )
{
void T_2 * V_4 = V_2 -> V_5 . V_6 + V_3 ;
F_5 ( V_8 , V_4 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_3 , T_1 V_8 )
{
void T_2 * V_4 = V_2 -> V_7 + V_3 ;
F_5 ( V_8 , V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_9 ) ;
F_1 ( V_2 , V_10 ) ;
}
static unsigned char F_8 ( struct V_1 * V_2 , int V_3 )
{
unsigned char V_11 ;
V_11 = F_1 ( V_2 , V_3 ) ;
if ( V_12 )
F_7 ( V_2 ) ;
return V_11 ;
}
static unsigned char F_9 ( struct V_1 * V_2 , int V_3 )
{
unsigned char V_11 ;
V_11 = F_3 ( V_2 , V_3 ) ;
if ( V_12 )
F_7 ( V_2 ) ;
return V_11 ;
}
static void F_10 ( struct V_1 * V_2 , int V_3 , unsigned int V_8 )
{
F_4 ( V_2 , V_3 , V_8 ) ;
if ( V_12 )
F_7 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_3 , unsigned int V_8 )
{
F_6 ( V_2 , V_3 , V_8 ) ;
if ( V_12 )
F_7 ( V_2 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
return F_8 ( V_2 , V_13 ) & V_14 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_15 = 10000 ;
while ( F_12 ( V_2 ) && -- V_15 )
F_8 ( V_2 , V_16 ) ;
return V_15 ;
}
static int T_3 F_14 ( struct V_1 * V_2 )
{
return F_8 ( V_2 , V_13 ) & V_17 ;
}
static int T_3 F_15 ( struct V_1 * V_2 )
{
int V_15 = 10000 ;
while ( ! F_14 ( V_2 ) && -- V_15 )
F_16 ( 2 ) ;
return V_15 ;
}
static int F_17 ( struct V_1 * V_2 )
{
return F_8 ( V_2 , V_13 ) & V_18 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_15 = 10000 ;
while ( ! F_17 ( V_2 ) && -- V_15 )
F_16 ( 2 ) ;
return V_15 ;
}
static unsigned int F_19 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_20 ( V_20 ) ;
return F_17 ( V_2 ) ? V_21 : 0 ;
}
static unsigned int F_21 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_20 ( V_20 ) ;
unsigned int V_22 , V_23 ;
V_23 = F_9 ( V_2 , V_24 ) ;
V_23 >>= ( V_20 -> line ) % 2 ;
V_22 = ( ! ( V_23 & V_25 ) ? V_26 : 0 ) |
( ! ( V_23 & V_27 ) ? V_28 : 0 ) |
( ! ( V_23 & V_29 ) ? V_30 : 0 ) |
( ! ( V_23 & V_31 ) ? V_32 : 0 ) ;
return V_22 ;
}
static void F_22 ( struct V_19 * V_20 , unsigned int V_22 )
{
struct V_1 * V_2 = F_20 ( V_20 ) ;
unsigned int V_33 = 0 , V_34 = 0 , V_35 ;
if ( V_22 & V_36 )
V_34 |= V_37 ;
else
V_33 |= V_38 ;
if ( V_22 & V_39 )
V_34 |= V_40 ;
else
V_33 |= V_41 ;
V_33 <<= ( V_20 -> line ) % 2 ;
V_34 <<= ( V_20 -> line ) % 2 ;
V_35 = F_8 ( V_2 , V_10 ) ;
V_35 &= ~ V_42 ;
if ( V_22 & V_43 )
V_35 |= V_44 ;
else
V_35 |= V_45 ;
F_11 ( V_2 , V_46 , V_33 ) ;
F_11 ( V_2 , V_47 , V_34 ) ;
F_10 ( V_2 , V_10 , V_35 ) ;
}
static void F_23 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_20 ( V_20 ) ;
F_10 ( V_2 , V_48 , V_49 ) ;
V_2 -> V_50 = 1 ;
}
static void F_24 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_20 ( V_20 ) ;
unsigned int V_51 ;
V_51 = F_9 ( V_2 , F_25 ( ( V_20 -> line ) % 2 ) ) ;
V_51 |= V_52 ;
F_11 ( V_2 , F_25 ( ( V_20 -> line ) % 2 ) , V_51 ) ;
F_10 ( V_2 , V_48 , V_53 ) ;
V_2 -> V_50 = 0 ;
}
static void F_26 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_20 ( V_20 ) ;
F_11 ( V_2 , F_25 ( ( V_20 -> line ) % 2 ) , 0 ) ;
}
static void F_27 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_20 ( V_20 ) ;
F_10 ( V_2 , V_54 ,
V_55 | V_56 ) ;
}
static void F_28 ( struct V_19 * V_20 , int V_57 )
{
struct V_1 * V_2 = F_20 ( V_20 ) ;
if ( V_57 == - 1 )
F_10 ( V_2 , V_48 , V_58 ) ;
else
F_10 ( V_2 , V_48 , V_59 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = & V_2 -> V_5 ;
struct V_60 * V_61 ;
unsigned int V_23 , V_62 , V_63 ;
int V_64 ;
for ( V_64 = 16 ; V_64 ; V_64 -- ) {
V_23 = F_8 ( V_2 , V_13 ) ;
if ( ! ( V_23 & V_14 ) )
break;
V_62 = F_8 ( V_2 , V_16 ) ;
V_63 = V_65 ;
V_61 = & V_20 -> V_61 ;
V_61 -> V_66 ++ ;
if ( F_30 ( V_23 &
( V_67 | V_68 |
V_69 | V_70 ) ) ) {
if ( V_23 & V_67 ) {
V_61 -> V_71 ++ ;
if ( F_31 ( V_20 ) )
continue;
} else if ( V_23 & V_68 )
V_61 -> V_72 ++ ;
else if ( V_23 & V_69 )
V_61 -> V_73 ++ ;
if ( V_23 & V_70 )
V_61 -> V_74 ++ ;
V_23 &= V_20 -> V_75 ;
if ( V_23 & V_67 )
V_63 = V_76 ;
else if ( V_23 & V_68 )
V_63 = V_77 ;
else if ( V_23 & V_69 )
V_63 = V_78 ;
}
if ( F_32 ( V_20 , V_62 ) )
continue;
F_33 ( V_20 , V_23 , V_70 , V_62 , V_63 ) ;
}
F_34 ( & V_20 -> V_79 -> V_5 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = & V_2 -> V_5 ;
struct V_80 * V_81 = & V_2 -> V_5 . V_79 -> V_81 ;
unsigned int V_51 ;
int V_82 ;
if ( V_2 -> V_5 . V_83 ) {
F_10 ( V_2 , V_84 , V_2 -> V_5 . V_83 ) ;
V_2 -> V_5 . V_61 . V_85 ++ ;
V_2 -> V_5 . V_83 = 0 ;
return;
}
V_82 = ( F_36 ( V_81 ) || F_37 ( & V_2 -> V_5 ) ) ;
if ( ! V_82 ) {
F_10 ( V_2 , V_84 , V_81 -> V_86 [ V_81 -> V_87 ] ) ;
V_81 -> V_87 = ( V_81 -> V_87 + 1 ) & ( V_88 - 1 ) ;
V_2 -> V_5 . V_61 . V_85 ++ ;
if ( F_38 ( V_81 ) < V_89 )
F_39 ( & V_2 -> V_5 ) ;
}
if ( V_82 || F_36 ( V_81 ) ) {
V_51 = F_9 ( V_2 , F_25 ( ( V_20 -> line ) % 2 ) ) ;
V_51 &= ~ V_52 ;
F_11 ( V_2 , F_25 ( ( V_20 -> line ) % 2 ) , V_51 ) ;
}
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = & V_2 -> V_5 ;
unsigned int V_90 ;
V_90 = F_9 ( V_2 , F_41 ( ( V_20 -> line ) % 2 ) ) ;
V_90 >>= ( V_20 -> line ) % 2 ;
if ( V_90 & ( V_25 << V_91 ) )
F_42 ( V_20 , ! ( V_90 & V_25 ) ) ;
if ( V_90 & ( V_31 << V_91 ) )
V_20 -> V_61 . V_92 ++ ;
if ( V_90 & ( ( V_31 | V_25 ) <<
V_91 ) )
F_43 ( & V_20 -> V_79 -> V_5 . V_93 ) ;
}
static T_4 F_44 ( int V_94 , void * V_95 )
{
struct V_1 * V_2 = V_95 ;
struct V_19 * V_20 = & V_2 -> V_5 ;
T_4 V_23 = V_96 ;
unsigned int V_97 ;
int V_64 ;
for ( V_64 = 16 ; V_64 ; V_64 -- ) {
V_97 = F_9 ( V_2 ,
F_45 ( ( V_20 -> line ) % 2 ) ) ;
V_97 &= F_9 ( V_2 ,
F_25 ( ( V_20 -> line ) % 2 ) ) ;
V_97 &= V_98 ;
if ( ! V_97 )
break;
if ( V_97 & V_99 )
F_29 ( V_2 ) ;
if ( V_97 & V_100 )
F_40 ( V_2 ) ;
if ( V_97 & V_101 )
F_35 ( V_2 ) ;
V_23 = V_102 ;
}
return V_23 ;
}
static int F_46 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_20 ( V_20 ) ;
unsigned int V_103 ;
int V_104 ;
V_104 = F_47 ( V_2 -> V_5 . V_94 , F_44 ,
V_105 , L_1 , V_2 ) ;
if ( V_104 )
return V_104 ;
F_13 ( V_2 ) ;
F_10 ( V_2 , V_48 , V_106 ) ;
F_9 ( V_2 , F_41 ( ( V_20 -> line ) % 2 ) ) ;
V_103 = F_8 ( V_2 , V_9 ) ;
V_103 &= ~ ( V_107 | V_108 ) ;
F_10 ( V_2 , V_9 , V_103 ) ;
F_10 ( V_2 , V_48 , V_49 | V_109 ) ;
V_2 -> V_50 = 1 ;
F_11 ( V_2 , F_25 ( ( V_20 -> line ) % 2 ) ,
V_110 | V_111 ) ;
return 0 ;
}
static void F_48 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_20 ( V_20 ) ;
F_10 ( V_2 , V_48 , V_49 | V_112 ) ;
V_2 -> V_50 = 1 ;
F_49 ( V_2 -> V_5 . V_94 , V_2 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = & V_2 -> V_5 ;
if ( V_2 -> V_113 )
return;
F_10 ( V_2 , V_48 , V_114 ) ;
F_10 ( V_2 , V_48 , V_115 ) ;
F_10 ( V_2 , V_9 , V_116 ) ;
F_10 ( V_2 , V_10 , 0 ) ;
F_10 ( V_2 , V_117 ,
F_51 ( 0 ) | F_52 ( 15 ) ) ;
F_10 ( V_2 , V_118 , 0 ) ;
F_10 ( V_2 , V_54 , 0 ) ;
F_11 ( V_2 , F_25 ( ( V_20 -> line ) % 2 ) , 0 ) ;
V_2 -> V_113 = 1 ;
}
static void F_53 ( struct V_19 * V_20 , struct V_119 * V_120 ,
struct V_119 * V_121 )
{
struct V_1 * V_2 = F_20 ( V_20 ) ;
unsigned int V_103 = 0 , V_35 = 0 , V_122 = 0 ;
unsigned int V_123 = 0 , V_124 = 0 , V_125 = 0 ;
unsigned int V_126 , V_127 , V_128 ;
unsigned int V_129 , V_130 ;
unsigned int V_131 ;
V_123 |= ~ ( V_132 | V_133 |
V_134 ) ;
V_124 |= ~ V_135 ;
V_125 |= ~ V_56 ;
switch ( V_120 -> V_136 & V_137 ) {
case V_138 :
case V_139 :
V_123 |= V_132 ;
break;
case V_140 :
V_103 |= V_141 ;
break;
case V_142 :
default:
V_103 |= V_116 ;
break;
}
if ( V_120 -> V_136 & V_143 )
V_35 |= V_135 ;
else
V_35 |= V_144 ;
if ( V_120 -> V_136 & V_145 )
V_103 |= V_146 ;
else
V_103 |= V_147 ;
if ( V_120 -> V_136 & V_148 )
V_103 |= V_133 ;
else
V_103 |= V_149 ;
V_129 = F_54 ( V_20 , V_120 , V_121 , 1200 , 5000000 ) ;
V_130 = F_55 ( V_129 ) ;
if ( V_130 > V_150 )
V_130 = V_150 ;
F_56 ( V_20 , V_120 -> V_136 , V_129 ) ;
V_20 -> V_75 = V_70 ;
if ( V_120 -> V_151 & V_152 )
V_20 -> V_75 |= V_68 |
V_69 ;
if ( V_120 -> V_151 & ( V_153 | V_154 | V_155 ) )
V_20 -> V_75 |= V_67 ;
V_20 -> V_156 = 0 ;
if ( V_120 -> V_151 & V_157 )
V_20 -> V_156 |= V_68 |
V_69 ;
if ( V_120 -> V_151 & V_153 ) {
V_20 -> V_156 |= V_67 ;
if ( V_120 -> V_151 & V_157 )
V_20 -> V_156 |= V_70 ;
}
if ( V_120 -> V_136 & V_158 )
V_131 = V_109 ;
else
V_131 = V_112 ;
if ( V_120 -> V_136 & V_159 )
V_122 |= V_56 ;
else
V_122 &= ~ V_56 ;
F_57 ( & V_20 -> V_160 ) ;
if ( V_2 -> V_50 )
V_131 |= V_49 ;
else
V_131 |= V_53 ;
V_126 = F_8 ( V_2 , V_9 ) & V_123 ;
V_127 = F_8 ( V_2 , V_10 ) & V_124 ;
V_128 = F_8 ( V_2 , V_54 ) & V_125 ;
if ( ! V_2 -> V_50 )
F_18 ( V_2 ) ;
F_10 ( V_2 , V_48 , V_49 | V_112 ) ;
F_10 ( V_2 , V_9 , V_103 | V_126 ) ;
F_10 ( V_2 , V_10 , V_35 | V_127 ) ;
F_10 ( V_2 , V_161 , V_130 ) ;
F_10 ( V_2 , V_54 , V_122 | V_128 ) ;
F_10 ( V_2 , V_48 , V_131 ) ;
F_58 ( & V_20 -> V_160 ) ;
}
static const char * F_59 ( struct V_19 * V_20 )
{
return L_2 ;
}
static void F_60 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_20 ( V_20 ) ;
struct V_162 * V_163 = V_2 -> V_163 ;
int V_164 ;
F_61 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
F_61 ( V_20 -> V_6 ) ;
V_20 -> V_6 = NULL ;
V_164 = F_62 ( - 1 , & V_163 -> V_164 ) ;
if ( ! V_164 )
F_63 ( V_163 -> V_165 , V_166 ) ;
F_63 ( V_20 -> V_167 , V_166 ) ;
}
static int F_64 ( struct V_19 * V_20 )
{
const char * V_168 = V_169 L_3 ;
struct V_1 * V_2 = F_20 ( V_20 ) ;
struct V_162 * V_163 = V_2 -> V_163 ;
if ( ! V_20 -> V_6 )
V_20 -> V_6 = F_65 ( V_20 -> V_167 ,
V_166 ) ;
if ( ! V_20 -> V_6 ) {
F_66 ( V_168 ) ;
return - V_170 ;
}
if ( ! V_2 -> V_7 )
V_2 -> V_7 = F_65 ( V_163 -> V_165 ,
V_166 ) ;
if ( ! V_2 -> V_7 ) {
F_66 ( V_168 ) ;
F_61 ( V_20 -> V_6 ) ;
V_20 -> V_6 = NULL ;
return - V_170 ;
}
return 0 ;
}
static int F_67 ( struct V_19 * V_20 )
{
const char * V_168 = V_169 L_4 ;
struct V_162 * V_163 = F_20 ( V_20 ) -> V_163 ;
int V_164 ;
int V_104 = 0 ;
if ( ! F_68 ( V_20 -> V_167 , V_166 ,
L_1 ) ) {
F_66 ( V_168 ) ;
return - V_171 ;
}
V_164 = F_62 ( 1 , & V_163 -> V_164 ) ;
if ( V_164 == 1 ) {
if ( ! F_68 ( V_163 -> V_165 , V_166 ,
L_1 ) ) {
F_69 ( - 1 , & V_163 -> V_164 ) ;
F_66 ( V_168 ) ;
V_104 = - V_171 ;
}
}
if ( ! V_104 ) {
V_104 = F_64 ( V_20 ) ;
if ( V_104 ) {
V_164 = F_62 ( - 1 , & V_163 -> V_164 ) ;
if ( ! V_164 )
F_63 ( V_163 -> V_165 ,
V_166 ) ;
}
}
if ( V_104 ) {
F_63 ( V_20 -> V_167 , V_166 ) ;
return V_104 ;
}
return 0 ;
}
static void F_70 ( struct V_19 * V_20 , int V_172 )
{
struct V_1 * V_2 = F_20 ( V_20 ) ;
if ( V_172 & V_173 ) {
if ( F_67 ( V_20 ) )
return;
V_20 -> type = V_174 ;
F_50 ( V_2 ) ;
}
}
static int F_71 ( struct V_19 * V_20 , struct V_175 * V_176 )
{
int V_104 = 0 ;
if ( V_176 -> type != V_177 && V_176 -> type != V_174 )
V_104 = - V_178 ;
if ( V_176 -> V_94 != V_20 -> V_94 )
V_104 = - V_178 ;
if ( V_176 -> V_179 != V_20 -> V_180 / 16 )
V_104 = - V_178 ;
return V_104 ;
}
static void T_5 F_72 ( void )
{
static int V_181 ;
int V_182 , V_183 ;
int V_184 , line ;
if ( V_181 )
return;
switch ( V_185 ) {
case V_186 :
case V_187 :
V_184 = 4 ;
break;
default:
V_184 = 2 ;
break;
}
V_181 = 1 ;
for ( V_182 = 0 , line = 0 ; V_182 < V_188 && line < V_184 ;
V_182 ++ ) {
V_189 [ V_182 ] . V_165 = F_73 ( line ) ;
for ( V_183 = 0 ; V_183 < V_190 && line < V_184 ;
V_183 ++ , line ++ ) {
struct V_1 * V_2 = & V_189 [ V_182 ] . V_2 [ V_183 ] ;
struct V_19 * V_20 = & V_2 -> V_5 ;
V_2 -> V_163 = & V_189 [ V_182 ] ;
V_20 -> V_94 = F_74 ( line ) ;
V_20 -> V_180 = 100000000 / 20 * 16 ;
V_20 -> V_191 = 16 ;
V_20 -> V_192 = V_193 ;
V_20 -> V_172 = V_194 ;
V_20 -> V_195 = & V_196 ;
V_20 -> line = line ;
V_20 -> V_167 = F_75 ( line ) ;
}
}
}
static void F_76 ( struct V_19 * V_20 , int V_62 )
{
struct V_1 * V_2 = F_20 ( V_20 ) ;
F_15 ( V_2 ) ;
F_10 ( V_2 , V_84 , V_62 ) ;
}
static void F_77 ( struct V_197 * V_198 , const char * V_199 ,
unsigned int V_64 )
{
int V_182 = V_198 -> V_200 / V_190 ;
int V_183 = V_198 -> V_200 % V_190 ;
struct V_1 * V_2 = & V_189 [ V_182 ] . V_2 [ V_183 ] ;
struct V_19 * V_20 = & V_2 -> V_5 ;
unsigned long V_172 ;
unsigned int V_51 ;
F_78 ( & V_20 -> V_160 , V_172 ) ;
V_51 = F_9 ( V_2 , F_25 ( ( V_20 -> line ) % 2 ) ) ;
F_11 ( V_2 , F_25 ( ( V_20 -> line ) % 2 ) ,
V_51 & ~ V_52 ) ;
F_10 ( V_2 , V_48 , V_53 ) ;
F_79 ( & V_20 -> V_160 , V_172 ) ;
F_80 ( & V_2 -> V_5 , V_199 , V_64 , F_76 ) ;
F_78 ( & V_20 -> V_160 , V_172 ) ;
F_18 ( V_2 ) ;
if ( V_2 -> V_50 )
F_10 ( V_2 , V_48 , V_49 ) ;
F_11 ( V_2 , F_25 ( ( V_20 -> line ) % 2 ) , V_51 ) ;
F_79 ( & V_20 -> V_160 , V_172 ) ;
}
static int T_5 F_81 ( struct V_197 * V_198 , char * V_201 )
{
int V_182 = V_198 -> V_200 / V_190 ;
int V_183 = V_198 -> V_200 % V_190 ;
struct V_1 * V_2 = & V_189 [ V_182 ] . V_2 [ V_183 ] ;
struct V_19 * V_20 = & V_2 -> V_5 ;
int V_129 = 115200 ;
int V_202 = 8 ;
int V_73 = 'n' ;
int V_203 = 'n' ;
int V_104 ;
if ( ! V_2 -> V_163 )
return - V_204 ;
V_104 = F_64 ( V_20 ) ;
if ( V_104 )
return V_104 ;
F_50 ( V_2 ) ;
if ( V_201 )
F_82 ( V_201 , & V_129 , & V_73 , & V_202 , & V_203 ) ;
return F_83 ( V_20 , V_198 , V_129 , V_73 , V_202 , V_203 ) ;
}
static int T_5 F_84 ( void )
{
F_72 () ;
F_85 ( & V_205 ) ;
return 0 ;
}
static int T_5 F_86 ( void )
{
int V_206 , V_104 ;
F_72 () ;
V_104 = F_87 ( & V_207 ) ;
if ( V_104 )
return V_104 ;
for ( V_206 = 0 ; V_206 < V_188 * V_190 ; V_206 ++ ) {
struct V_162 * V_163 = & V_189 [ V_206 / V_190 ] ;
struct V_1 * V_2 = & V_163 -> V_2 [ V_206 % V_190 ] ;
struct V_19 * V_20 = & V_2 -> V_5 ;
if ( V_2 -> V_163 )
F_88 ( & V_207 , V_20 ) ;
}
return 0 ;
}
static void T_6 F_89 ( void )
{
int V_206 ;
for ( V_206 = V_188 * V_190 - 1 ; V_206 >= 0 ; V_206 -- ) {
struct V_162 * V_163 = & V_189 [ V_206 / V_190 ] ;
struct V_1 * V_2 = & V_163 -> V_2 [ V_206 % V_190 ] ;
struct V_19 * V_20 = & V_2 -> V_5 ;
if ( V_2 -> V_163 )
F_90 ( & V_207 , V_20 ) ;
}
F_91 ( & V_207 ) ;
}
