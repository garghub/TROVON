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
F_34 ( V_20 -> V_79 -> V_5 . V_80 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = & V_2 -> V_5 ;
struct V_81 * V_82 = & V_2 -> V_5 . V_79 -> V_82 ;
unsigned int V_51 ;
int V_83 ;
if ( V_2 -> V_5 . V_84 ) {
F_10 ( V_2 , V_85 , V_2 -> V_5 . V_84 ) ;
V_2 -> V_5 . V_61 . V_86 ++ ;
V_2 -> V_5 . V_84 = 0 ;
return;
}
V_83 = ( F_36 ( V_82 ) || F_37 ( & V_2 -> V_5 ) ) ;
if ( ! V_83 ) {
F_10 ( V_2 , V_85 , V_82 -> V_87 [ V_82 -> V_88 ] ) ;
V_82 -> V_88 = ( V_82 -> V_88 + 1 ) & ( V_89 - 1 ) ;
V_2 -> V_5 . V_61 . V_86 ++ ;
if ( F_38 ( V_82 ) < V_90 )
F_39 ( & V_2 -> V_5 ) ;
}
if ( V_83 || F_36 ( V_82 ) ) {
V_51 = F_9 ( V_2 , F_25 ( ( V_20 -> line ) % 2 ) ) ;
V_51 &= ~ V_52 ;
F_11 ( V_2 , F_25 ( ( V_20 -> line ) % 2 ) , V_51 ) ;
}
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = & V_2 -> V_5 ;
unsigned int V_91 ;
V_91 = F_9 ( V_2 , F_41 ( ( V_20 -> line ) % 2 ) ) ;
V_91 >>= ( V_20 -> line ) % 2 ;
if ( V_91 & ( V_25 << V_92 ) )
F_42 ( V_20 , ! ( V_91 & V_25 ) ) ;
if ( V_91 & ( V_31 << V_92 ) )
V_20 -> V_61 . V_93 ++ ;
if ( V_91 & ( ( V_31 | V_25 ) <<
V_92 ) )
F_43 ( & V_20 -> V_79 -> V_5 . V_94 ) ;
}
static T_4 F_44 ( int V_95 , void * V_96 )
{
struct V_1 * V_2 = V_96 ;
struct V_19 * V_20 = & V_2 -> V_5 ;
T_4 V_23 = V_97 ;
unsigned int V_98 ;
int V_64 ;
for ( V_64 = 16 ; V_64 ; V_64 -- ) {
V_98 = F_9 ( V_2 ,
F_45 ( ( V_20 -> line ) % 2 ) ) ;
V_98 &= F_9 ( V_2 ,
F_25 ( ( V_20 -> line ) % 2 ) ) ;
V_98 &= V_99 ;
if ( ! V_98 )
break;
if ( V_98 & V_100 )
F_29 ( V_2 ) ;
if ( V_98 & V_101 )
F_40 ( V_2 ) ;
if ( V_98 & V_102 )
F_35 ( V_2 ) ;
V_23 = V_103 ;
}
return V_23 ;
}
static int F_46 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_20 ( V_20 ) ;
unsigned int V_104 ;
int V_105 ;
V_105 = F_47 ( V_2 -> V_5 . V_95 , F_44 ,
V_106 , L_1 , V_2 ) ;
if ( V_105 )
return V_105 ;
F_13 ( V_2 ) ;
F_10 ( V_2 , V_48 , V_107 ) ;
F_9 ( V_2 , F_41 ( ( V_20 -> line ) % 2 ) ) ;
V_104 = F_8 ( V_2 , V_9 ) ;
V_104 &= ~ ( V_108 | V_109 ) ;
F_10 ( V_2 , V_9 , V_104 ) ;
F_10 ( V_2 , V_48 , V_49 | V_110 ) ;
V_2 -> V_50 = 1 ;
F_11 ( V_2 , F_25 ( ( V_20 -> line ) % 2 ) ,
V_111 | V_112 ) ;
return 0 ;
}
static void F_48 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_20 ( V_20 ) ;
F_10 ( V_2 , V_48 , V_49 | V_113 ) ;
V_2 -> V_50 = 1 ;
F_49 ( V_2 -> V_5 . V_95 , V_2 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = & V_2 -> V_5 ;
if ( V_2 -> V_114 )
return;
F_10 ( V_2 , V_48 , V_115 ) ;
F_10 ( V_2 , V_48 , V_116 ) ;
F_10 ( V_2 , V_9 , V_117 ) ;
F_10 ( V_2 , V_10 , 0 ) ;
F_10 ( V_2 , V_118 ,
F_51 ( 0 ) | F_52 ( 15 ) ) ;
F_10 ( V_2 , V_119 , 0 ) ;
F_10 ( V_2 , V_54 , 0 ) ;
F_11 ( V_2 , F_25 ( ( V_20 -> line ) % 2 ) , 0 ) ;
V_2 -> V_114 = 1 ;
}
static void F_53 ( struct V_19 * V_20 , struct V_120 * V_121 ,
struct V_120 * V_122 )
{
struct V_1 * V_2 = F_20 ( V_20 ) ;
unsigned int V_104 = 0 , V_35 = 0 , V_123 = 0 ;
unsigned int V_124 = 0 , V_125 = 0 , V_126 = 0 ;
unsigned int V_127 , V_128 , V_129 ;
unsigned int V_130 , V_131 ;
unsigned int V_132 ;
V_124 |= ~ ( V_133 | V_134 |
V_135 ) ;
V_125 |= ~ V_136 ;
V_126 |= ~ V_56 ;
switch ( V_121 -> V_137 & V_138 ) {
case V_139 :
case V_140 :
V_124 |= V_133 ;
break;
case V_141 :
V_104 |= V_142 ;
break;
case V_143 :
default:
V_104 |= V_117 ;
break;
}
if ( V_121 -> V_137 & V_144 )
V_35 |= V_136 ;
else
V_35 |= V_145 ;
if ( V_121 -> V_137 & V_146 )
V_104 |= V_147 ;
else
V_104 |= V_148 ;
if ( V_121 -> V_137 & V_149 )
V_104 |= V_134 ;
else
V_104 |= V_150 ;
V_130 = F_54 ( V_20 , V_121 , V_122 , 1200 , 5000000 ) ;
V_131 = F_55 ( V_130 ) ;
if ( V_131 > V_151 )
V_131 = V_151 ;
F_56 ( V_20 , V_121 -> V_137 , V_130 ) ;
V_20 -> V_75 = V_70 ;
if ( V_121 -> V_152 & V_153 )
V_20 -> V_75 |= V_68 |
V_69 ;
if ( V_121 -> V_152 & ( V_154 | V_155 ) )
V_20 -> V_75 |= V_67 ;
V_20 -> V_156 = 0 ;
if ( V_121 -> V_152 & V_157 )
V_20 -> V_156 |= V_68 |
V_69 ;
if ( V_121 -> V_152 & V_158 ) {
V_20 -> V_156 |= V_67 ;
if ( V_121 -> V_152 & V_157 )
V_20 -> V_156 |= V_70 ;
}
if ( V_121 -> V_137 & V_159 )
V_132 = V_110 ;
else
V_132 = V_113 ;
if ( V_121 -> V_137 & V_160 )
V_123 |= V_56 ;
else
V_123 &= ~ V_56 ;
F_57 ( & V_20 -> V_161 ) ;
if ( V_2 -> V_50 )
V_132 |= V_49 ;
else
V_132 |= V_53 ;
V_127 = F_8 ( V_2 , V_9 ) & V_124 ;
V_128 = F_8 ( V_2 , V_10 ) & V_125 ;
V_129 = F_8 ( V_2 , V_54 ) & V_126 ;
if ( ! V_2 -> V_50 )
F_18 ( V_2 ) ;
F_10 ( V_2 , V_48 , V_49 | V_113 ) ;
F_10 ( V_2 , V_9 , V_104 | V_127 ) ;
F_10 ( V_2 , V_10 , V_35 | V_128 ) ;
F_10 ( V_2 , V_162 , V_131 ) ;
F_10 ( V_2 , V_54 , V_123 | V_129 ) ;
F_10 ( V_2 , V_48 , V_132 ) ;
F_58 ( & V_20 -> V_161 ) ;
}
static const char * F_59 ( struct V_19 * V_20 )
{
return L_2 ;
}
static void F_60 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_20 ( V_20 ) ;
struct V_163 * V_164 = V_2 -> V_164 ;
int V_165 ;
F_61 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
F_61 ( V_20 -> V_6 ) ;
V_20 -> V_6 = NULL ;
V_165 = F_62 ( - 1 , & V_164 -> V_165 ) ;
if ( ! V_165 )
F_63 ( V_164 -> V_166 , V_167 ) ;
F_63 ( V_20 -> V_168 , V_167 ) ;
}
static int F_64 ( struct V_19 * V_20 )
{
const char * V_169 = V_170 L_3 ;
struct V_1 * V_2 = F_20 ( V_20 ) ;
struct V_163 * V_164 = V_2 -> V_164 ;
if ( ! V_20 -> V_6 )
V_20 -> V_6 = F_65 ( V_20 -> V_168 ,
V_167 ) ;
if ( ! V_20 -> V_6 ) {
F_66 ( V_169 ) ;
return - V_171 ;
}
if ( ! V_2 -> V_7 )
V_2 -> V_7 = F_65 ( V_164 -> V_166 ,
V_167 ) ;
if ( ! V_2 -> V_7 ) {
F_66 ( V_169 ) ;
F_61 ( V_20 -> V_6 ) ;
V_20 -> V_6 = NULL ;
return - V_171 ;
}
return 0 ;
}
static int F_67 ( struct V_19 * V_20 )
{
const char * V_169 = V_170 L_4 ;
struct V_163 * V_164 = F_20 ( V_20 ) -> V_164 ;
int V_165 ;
int V_105 = 0 ;
if ( ! F_68 ( V_20 -> V_168 , V_167 ,
L_1 ) ) {
F_66 ( V_169 ) ;
return - V_172 ;
}
V_165 = F_62 ( 1 , & V_164 -> V_165 ) ;
if ( V_165 == 1 ) {
if ( ! F_68 ( V_164 -> V_166 , V_167 ,
L_1 ) ) {
F_69 ( - 1 , & V_164 -> V_165 ) ;
F_66 ( V_169 ) ;
V_105 = - V_172 ;
}
}
if ( ! V_105 ) {
V_105 = F_64 ( V_20 ) ;
if ( V_105 ) {
V_165 = F_62 ( - 1 , & V_164 -> V_165 ) ;
if ( ! V_165 )
F_63 ( V_164 -> V_166 ,
V_167 ) ;
}
}
if ( V_105 ) {
F_63 ( V_20 -> V_168 , V_167 ) ;
return V_105 ;
}
return 0 ;
}
static void F_70 ( struct V_19 * V_20 , int V_173 )
{
struct V_1 * V_2 = F_20 ( V_20 ) ;
if ( V_173 & V_174 ) {
if ( F_67 ( V_20 ) )
return;
V_20 -> type = V_175 ;
F_50 ( V_2 ) ;
}
}
static int F_71 ( struct V_19 * V_20 , struct V_176 * V_177 )
{
int V_105 = 0 ;
if ( V_177 -> type != V_178 && V_177 -> type != V_175 )
V_105 = - V_179 ;
if ( V_177 -> V_95 != V_20 -> V_95 )
V_105 = - V_179 ;
if ( V_177 -> V_180 != V_20 -> V_181 / 16 )
V_105 = - V_179 ;
return V_105 ;
}
static void T_5 F_72 ( void )
{
static int V_182 ;
int V_183 , V_184 ;
int V_185 , line ;
if ( V_182 )
return;
switch ( V_186 ) {
case V_187 :
case V_188 :
V_185 = 4 ;
break;
default:
V_185 = 2 ;
break;
}
V_182 = 1 ;
for ( V_183 = 0 , line = 0 ; V_183 < V_189 && line < V_185 ;
V_183 ++ ) {
V_190 [ V_183 ] . V_166 = F_73 ( line ) ;
for ( V_184 = 0 ; V_184 < V_191 && line < V_185 ;
V_184 ++ , line ++ ) {
struct V_1 * V_2 = & V_190 [ V_183 ] . V_2 [ V_184 ] ;
struct V_19 * V_20 = & V_2 -> V_5 ;
V_2 -> V_164 = & V_190 [ V_183 ] ;
V_20 -> V_95 = F_74 ( line ) ;
V_20 -> V_181 = 100000000 / 20 * 16 ;
V_20 -> V_192 = 16 ;
V_20 -> V_193 = V_194 ;
V_20 -> V_173 = V_195 ;
V_20 -> V_196 = & V_197 ;
V_20 -> line = line ;
V_20 -> V_168 = F_75 ( line ) ;
}
}
}
static void F_76 ( struct V_19 * V_20 , int V_62 )
{
struct V_1 * V_2 = F_20 ( V_20 ) ;
F_15 ( V_2 ) ;
F_10 ( V_2 , V_85 , V_62 ) ;
}
static void F_77 ( struct V_198 * V_199 , const char * V_200 ,
unsigned int V_64 )
{
int V_183 = V_199 -> V_201 / V_191 ;
int V_184 = V_199 -> V_201 % V_191 ;
struct V_1 * V_2 = & V_190 [ V_183 ] . V_2 [ V_184 ] ;
struct V_19 * V_20 = & V_2 -> V_5 ;
unsigned long V_173 ;
unsigned int V_51 ;
F_78 ( & V_20 -> V_161 , V_173 ) ;
V_51 = F_9 ( V_2 , F_25 ( ( V_20 -> line ) % 2 ) ) ;
F_11 ( V_2 , F_25 ( ( V_20 -> line ) % 2 ) ,
V_51 & ~ V_52 ) ;
F_10 ( V_2 , V_48 , V_53 ) ;
F_79 ( & V_20 -> V_161 , V_173 ) ;
F_80 ( & V_2 -> V_5 , V_200 , V_64 , F_76 ) ;
F_78 ( & V_20 -> V_161 , V_173 ) ;
F_18 ( V_2 ) ;
if ( V_2 -> V_50 )
F_10 ( V_2 , V_48 , V_49 ) ;
F_11 ( V_2 , F_25 ( ( V_20 -> line ) % 2 ) , V_51 ) ;
F_79 ( & V_20 -> V_161 , V_173 ) ;
}
static int T_5 F_81 ( struct V_198 * V_199 , char * V_202 )
{
int V_183 = V_199 -> V_201 / V_191 ;
int V_184 = V_199 -> V_201 % V_191 ;
struct V_1 * V_2 = & V_190 [ V_183 ] . V_2 [ V_184 ] ;
struct V_19 * V_20 = & V_2 -> V_5 ;
int V_130 = 115200 ;
int V_203 = 8 ;
int V_73 = 'n' ;
int V_204 = 'n' ;
int V_105 ;
if ( ! V_2 -> V_164 )
return - V_205 ;
V_105 = F_64 ( V_20 ) ;
if ( V_105 )
return V_105 ;
F_50 ( V_2 ) ;
if ( V_202 )
F_82 ( V_202 , & V_130 , & V_73 , & V_203 , & V_204 ) ;
return F_83 ( V_20 , V_199 , V_130 , V_73 , V_203 , V_204 ) ;
}
static int T_5 F_84 ( void )
{
F_72 () ;
F_85 ( & V_206 ) ;
return 0 ;
}
static int T_5 F_86 ( void )
{
int V_207 , V_105 ;
F_72 () ;
V_105 = F_87 ( & V_208 ) ;
if ( V_105 )
return V_105 ;
for ( V_207 = 0 ; V_207 < V_189 * V_191 ; V_207 ++ ) {
struct V_163 * V_164 = & V_190 [ V_207 / V_191 ] ;
struct V_1 * V_2 = & V_164 -> V_2 [ V_207 % V_191 ] ;
struct V_19 * V_20 = & V_2 -> V_5 ;
if ( V_2 -> V_164 )
F_88 ( & V_208 , V_20 ) ;
}
return 0 ;
}
static void T_6 F_89 ( void )
{
int V_207 ;
for ( V_207 = V_189 * V_191 - 1 ; V_207 >= 0 ; V_207 -- ) {
struct V_163 * V_164 = & V_190 [ V_207 / V_191 ] ;
struct V_1 * V_2 = & V_164 -> V_2 [ V_207 % V_191 ] ;
struct V_19 * V_20 = & V_2 -> V_5 ;
if ( V_2 -> V_164 )
F_90 ( & V_208 , V_20 ) ;
}
F_91 ( & V_208 ) ;
}
