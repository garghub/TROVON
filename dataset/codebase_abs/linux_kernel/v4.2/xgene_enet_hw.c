static void F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_4 ;
T_2 V_5 = V_2 -> V_6 ;
enum V_7 V_8 = V_2 -> V_8 ;
V_3 [ 4 ] |= ( 1 << V_9 ) &
F_2 ( V_9 , V_10 ) ;
V_3 [ 3 ] |= V_11 ;
V_3 [ 2 ] |= V_12 ;
V_5 >>= 8 ;
V_3 [ 2 ] |= ( V_5 << V_13 ) &
F_3 ( V_13 , V_14 ) ;
V_5 >>= V_14 ;
V_3 [ 3 ] |= V_5 & F_3 ( V_15 , V_16 ) ;
V_3 [ 3 ] |= ( ( T_1 ) V_8 << V_17 ) &
F_2 ( V_17 , V_18 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_4 ;
bool V_19 ;
T_1 V_20 ;
V_19 = F_5 ( V_2 -> V_21 ) ;
V_20 = ( V_19 ) ? V_22 : V_23 ;
V_3 [ 4 ] |= ( V_20 << V_24 ) &
F_2 ( V_24 , V_25 ) ;
if ( V_19 ) {
V_3 [ 3 ] |= ( V_26 << V_27 ) &
F_2 ( V_27 , V_28 ) ;
}
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_4 ;
V_3 [ 3 ] |= V_29 ;
V_3 [ 3 ] |= ( 0xf << V_30 ) &
F_2 ( V_30 , V_31 ) ;
V_3 [ 4 ] |= 0x7 & F_2 ( V_32 , V_33 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
T_1 V_34 , T_1 V_35 )
{
struct V_36 * V_37 = F_8 ( V_2 -> V_38 ) ;
F_9 ( V_35 , V_37 -> V_39 + V_34 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
T_1 V_34 , T_1 * V_35 )
{
struct V_36 * V_37 = F_8 ( V_2 -> V_38 ) ;
* V_35 = F_11 ( V_37 -> V_39 + V_34 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_8 ( V_2 -> V_38 ) ;
int V_40 ;
F_7 ( V_2 , V_41 , V_2 -> V_42 ) ;
for ( V_40 = 0 ; V_40 < V_37 -> V_43 -> V_44 ; V_40 ++ ) {
F_7 ( V_2 , V_45 + ( V_40 * 4 ) ,
V_2 -> V_4 [ V_40 ] ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
memset ( V_2 -> V_4 , 0 , sizeof( V_2 -> V_4 ) ) ;
F_12 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( F_15 ( V_2 -> V_21 ) == V_46 )
F_6 ( V_2 ) ;
F_1 ( V_2 ) ;
F_12 ( V_2 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_1 V_47 , V_48 ;
bool V_19 ;
V_19 = F_5 ( V_2 -> V_21 ) ;
V_47 = V_2 -> V_21 & F_17 ( 9 , 0 ) ;
V_47 |= V_49 ;
V_48 = ( V_2 -> V_42 << 9 ) & F_17 ( 18 , 9 ) ;
V_48 |= V_50 ;
if ( V_19 )
V_48 |= V_51 ;
F_7 ( V_2 , V_52 , V_47 ) ;
F_7 ( V_2 , V_53 , V_48 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_1 V_54 ;
V_54 = V_2 -> V_21 | V_49 ;
F_7 ( V_2 , V_52 , V_54 ) ;
F_7 ( V_2 , V_53 , 0 ) ;
}
static struct V_1 * F_19 (
struct V_1 * V_2 )
{
T_1 V_55 = V_2 -> V_55 ;
T_1 V_40 , V_35 ;
bool V_19 ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
F_16 ( V_2 ) ;
V_2 -> V_56 = F_20 ( V_2 -> V_21 , V_55 ) ;
V_19 = F_5 ( V_2 -> V_21 ) ;
if ( V_19 || F_15 ( V_2 -> V_21 ) != V_57 )
return V_2 ;
for ( V_40 = 0 ; V_40 < V_2 -> V_56 ; V_40 ++ )
F_21 ( & V_2 -> V_58 [ V_40 ] ) ;
F_10 ( V_2 , V_59 , & V_35 ) ;
V_35 |= F_22 ( 31 - F_23 ( V_2 -> V_21 ) ) ;
F_7 ( V_2 , V_59 , V_35 ) ;
return V_2 ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_1 V_35 ;
bool V_19 ;
V_19 = F_5 ( V_2 -> V_21 ) ;
if ( V_19 || F_15 ( V_2 -> V_21 ) != V_57 )
goto V_60;
F_10 ( V_2 , V_59 , & V_35 ) ;
V_35 &= ~ F_22 ( 31 - F_23 ( V_2 -> V_21 ) ) ;
F_7 ( V_2 , V_59 , V_35 ) ;
V_60:
F_18 ( V_2 ) ;
F_13 ( V_2 ) ;
}
static void F_25 ( struct V_1 * V_2 , int V_61 )
{
F_9 ( V_61 , V_2 -> V_62 ) ;
}
static T_1 F_26 ( struct V_1 * V_2 )
{
T_1 T_3 * V_63 = V_2 -> V_63 ;
T_1 V_64 , V_65 ;
V_64 = F_11 ( & V_63 [ 1 ] ) ;
V_65 = F_27 ( V_66 , V_64 ) ;
return V_65 ;
}
void F_28 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
enum V_67 V_68 )
{
struct V_69 * V_70 = & V_37 -> V_70 ;
switch ( V_68 ) {
case V_71 :
V_70 -> V_72 ++ ;
break;
case V_73 :
case V_74 :
V_70 -> V_75 ++ ;
break;
case V_76 :
V_70 -> V_77 ++ ;
break;
case V_78 :
V_70 -> V_79 ++ ;
break;
case V_80 :
V_70 -> V_77 ++ ;
break;
case V_81 :
V_70 -> V_82 ++ ;
break;
default:
break;
}
}
static void F_29 ( struct V_36 * V_37 ,
T_1 V_34 , T_1 V_20 )
{
void T_3 * V_5 = V_37 -> V_83 + V_34 ;
F_9 ( V_20 , V_5 ) ;
}
static void F_30 ( struct V_36 * V_37 ,
T_1 V_34 , T_1 V_20 )
{
void T_3 * V_5 = V_37 -> V_84 + V_34 ;
F_9 ( V_20 , V_5 ) ;
}
static void F_31 ( struct V_36 * V_37 ,
T_1 V_34 , T_1 V_20 )
{
void T_3 * V_5 = V_37 -> V_85 + V_34 ;
F_9 ( V_20 , V_5 ) ;
}
static void F_32 ( struct V_36 * V_37 ,
T_1 V_34 , T_1 V_20 )
{
void T_3 * V_5 = V_37 -> V_86 + V_34 ;
F_9 ( V_20 , V_5 ) ;
}
static bool F_33 ( void T_3 * V_5 , void T_3 * V_87 ,
void T_3 * V_62 , void T_3 * V_88 ,
T_1 V_89 , T_1 V_90 )
{
T_1 V_91 ;
T_4 V_92 = 10 ;
F_9 ( V_89 , V_5 ) ;
F_9 ( V_90 , V_87 ) ;
F_9 ( V_93 , V_62 ) ;
while ( ! ( V_91 = F_11 ( V_88 ) ) && V_92 -- )
F_34 ( 1 ) ;
if ( ! V_91 )
return false ;
F_9 ( 0 , V_62 ) ;
return true ;
}
static void F_35 ( struct V_36 * V_37 ,
T_1 V_89 , T_1 V_90 )
{
void T_3 * V_5 , * V_87 , * V_62 , * V_88 ;
V_5 = V_37 -> V_94 + V_95 ;
V_87 = V_37 -> V_94 + V_96 ;
V_62 = V_37 -> V_94 + V_97 ;
V_88 = V_37 -> V_94 + V_98 ;
if ( ! F_33 ( V_5 , V_87 , V_62 , V_88 , V_89 , V_90 ) )
F_36 ( V_37 -> V_38 , L_1 ,
V_89 ) ;
}
static void F_37 ( struct V_36 * V_37 ,
T_1 V_34 , T_1 * V_20 )
{
void T_3 * V_5 = V_37 -> V_83 + V_34 ;
* V_20 = F_11 ( V_5 ) ;
}
static void F_38 ( struct V_36 * V_37 ,
T_1 V_34 , T_1 * V_20 )
{
void T_3 * V_5 = V_37 -> V_85 + V_34 ;
* V_20 = F_11 ( V_5 ) ;
}
static void F_39 ( struct V_36 * V_37 ,
T_1 V_34 , T_1 * V_20 )
{
void T_3 * V_5 = V_37 -> V_86 + V_34 ;
* V_20 = F_11 ( V_5 ) ;
}
static bool F_40 ( void T_3 * V_5 , void T_3 * V_99 ,
void T_3 * V_62 , void T_3 * V_88 ,
T_1 V_100 , T_1 * V_101 )
{
T_1 V_91 ;
T_4 V_92 = 10 ;
F_9 ( V_100 , V_5 ) ;
F_9 ( V_102 , V_62 ) ;
while ( ! ( V_91 = F_11 ( V_88 ) ) && V_92 -- )
F_34 ( 1 ) ;
if ( ! V_91 )
return false ;
* V_101 = F_11 ( V_99 ) ;
F_9 ( 0 , V_62 ) ;
return true ;
}
static void F_41 ( struct V_36 * V_37 ,
T_1 V_100 , T_1 * V_101 )
{
void T_3 * V_5 , * V_99 , * V_62 , * V_88 ;
V_5 = V_37 -> V_94 + V_95 ;
V_99 = V_37 -> V_94 + V_103 ;
V_62 = V_37 -> V_94 + V_97 ;
V_88 = V_37 -> V_94 + V_98 ;
if ( ! F_40 ( V_5 , V_99 , V_62 , V_88 , V_100 , V_101 ) )
F_36 ( V_37 -> V_38 , L_2 ,
V_100 ) ;
}
static int F_42 ( struct V_36 * V_37 , int V_104 ,
T_1 V_105 , T_5 V_35 )
{
T_1 V_5 = 0 , V_90 = 0 ;
T_1 V_91 ;
T_4 V_92 = 10 ;
F_43 ( & V_5 , V_104 ) ;
F_44 ( & V_5 , V_105 ) ;
F_35 ( V_37 , V_106 , V_5 ) ;
F_45 ( & V_90 , V_35 ) ;
F_35 ( V_37 , V_107 , V_90 ) ;
do {
F_46 ( 5 , 10 ) ;
F_41 ( V_37 , V_108 , & V_91 ) ;
} while ( ( V_91 & V_109 ) && V_92 -- );
if ( V_91 & V_109 ) {
F_36 ( V_37 -> V_38 , L_3 ) ;
return - V_110 ;
}
return 0 ;
}
static int F_47 ( struct V_36 * V_37 ,
T_4 V_104 , T_1 V_105 )
{
T_1 V_5 = 0 ;
T_1 V_35 , V_91 ;
T_4 V_92 = 10 ;
F_43 ( & V_5 , V_104 ) ;
F_44 ( & V_5 , V_105 ) ;
F_35 ( V_37 , V_106 , V_5 ) ;
F_35 ( V_37 , V_111 , V_112 ) ;
do {
F_46 ( 5 , 10 ) ;
F_41 ( V_37 , V_108 , & V_91 ) ;
} while ( ( V_91 & V_109 ) && V_92 -- );
if ( V_91 & V_109 ) {
F_36 ( V_37 -> V_38 , L_4 ) ;
return - V_110 ;
}
F_41 ( V_37 , V_113 , & V_35 ) ;
F_35 ( V_37 , V_111 , 0 ) ;
return V_35 ;
}
static void F_48 ( struct V_36 * V_37 )
{
T_1 V_114 , V_115 ;
T_4 * V_116 = V_37 -> V_38 -> V_116 ;
V_114 = ( V_116 [ 3 ] << 24 ) | ( V_116 [ 2 ] << 16 ) |
( V_116 [ 1 ] << 8 ) | V_116 [ 0 ] ;
V_115 = ( V_116 [ 5 ] << 24 ) | ( V_116 [ 4 ] << 16 ) ;
F_35 ( V_37 , V_117 , V_114 ) ;
F_35 ( V_37 , V_118 , V_115 ) ;
}
static int F_49 ( struct V_36 * V_37 )
{
struct V_119 * V_38 = V_37 -> V_38 ;
T_1 V_35 ;
T_4 V_92 = 10 ;
F_31 ( V_37 , V_120 , 0x0 ) ;
do {
F_46 ( 100 , 110 ) ;
F_38 ( V_37 , V_121 , & V_35 ) ;
} while ( ( V_35 != 0xffffffff ) && V_92 -- );
if ( V_35 != 0xffffffff ) {
F_36 ( V_38 , L_5 ) ;
return - V_122 ;
}
return 0 ;
}
static void F_50 ( struct V_36 * V_37 )
{
F_35 ( V_37 , V_123 , V_124 ) ;
F_35 ( V_37 , V_123 , 0 ) ;
}
static void F_51 ( struct V_36 * V_37 )
{
T_1 V_125 , V_126 ;
T_1 V_127 , V_128 ;
T_1 V_129 , V_130 ;
F_50 ( V_37 ) ;
F_39 ( V_37 , V_131 , & V_129 ) ;
F_39 ( V_37 , V_132 , & V_130 ) ;
F_41 ( V_37 , V_133 , & V_126 ) ;
F_41 ( V_37 , V_134 , & V_127 ) ;
F_37 ( V_37 , V_135 , & V_128 ) ;
switch ( V_37 -> V_136 ) {
case V_137 :
F_52 ( & V_126 , 1 ) ;
F_53 ( & V_129 , 0 ) ;
F_54 ( & V_130 , 500 ) ;
V_128 &= ~ V_138 ;
break;
case V_139 :
F_52 ( & V_126 , 1 ) ;
V_127 |= V_140 ;
F_53 ( & V_129 , 1 ) ;
F_54 ( & V_130 , 80 ) ;
V_128 &= ~ V_138 ;
break;
default:
F_52 ( & V_126 , 2 ) ;
V_127 |= V_141 ;
F_55 ( & V_128 , 4 ) ;
F_37 ( V_37 , V_142 , & V_125 ) ;
V_125 |= V_143 | V_144 ;
F_29 ( V_37 , V_142 , V_125 ) ;
break;
}
V_126 |= V_145 ;
F_35 ( V_37 , V_133 , V_126 ) ;
F_35 ( V_37 , V_134 , V_127 ) ;
F_48 ( V_37 ) ;
F_41 ( V_37 , V_146 , & V_125 ) ;
F_56 ( & V_125 , 7 ) ;
F_35 ( V_37 , V_146 , V_125 ) ;
F_37 ( V_37 , V_147 , & V_125 ) ;
V_125 |= V_148 ;
F_29 ( V_37 , V_147 , V_125 ) ;
F_29 ( V_37 , V_149 , 0 ) ;
F_29 ( V_37 , V_135 , V_128 ) ;
F_29 ( V_37 , V_150 , V_151 ) ;
F_32 ( V_37 , V_131 , V_129 ) ;
F_32 ( V_37 , V_132 , V_130 ) ;
F_39 ( V_37 , V_152 , & V_125 ) ;
V_125 &= ~ V_153 ;
V_125 &= ~ V_154 ;
V_125 |= V_155 ;
F_32 ( V_37 , V_152 , V_125 ) ;
F_29 ( V_37 , V_156 , V_157 ) ;
}
static void F_57 ( struct V_36 * V_37 )
{
T_1 V_20 = 0xffffffff ;
F_30 ( V_37 , V_158 , V_20 ) ;
F_30 ( V_37 , V_159 , V_20 ) ;
F_30 ( V_37 , V_160 , V_20 ) ;
F_30 ( V_37 , V_161 , V_20 ) ;
}
static void F_58 ( struct V_36 * V_37 ,
T_1 V_162 , T_5 V_163 )
{
T_1 V_164 ;
T_1 V_165 ;
V_165 = F_23 ( V_163 ) - 0x20 ;
F_37 ( V_37 , V_166 , & V_164 ) ;
V_164 |= V_167 ;
F_59 ( & V_164 , 3 ) ;
F_29 ( V_37 , V_166 , V_164 ) ;
F_37 ( V_37 , V_168 , & V_164 ) ;
F_60 ( & V_164 , V_162 ) ;
F_61 ( & V_164 , V_165 ) ;
F_29 ( V_37 , V_168 , V_164 ) ;
}
static void F_62 ( struct V_36 * V_37 )
{
T_1 V_35 ;
F_41 ( V_37 , V_123 , & V_35 ) ;
F_35 ( V_37 , V_123 , V_35 | V_169 ) ;
}
static void F_63 ( struct V_36 * V_37 )
{
T_1 V_35 ;
F_41 ( V_37 , V_123 , & V_35 ) ;
F_35 ( V_37 , V_123 , V_35 | V_170 ) ;
}
static void F_64 ( struct V_36 * V_37 )
{
T_1 V_35 ;
F_41 ( V_37 , V_123 , & V_35 ) ;
F_35 ( V_37 , V_123 , V_35 & ~ V_169 ) ;
}
static void F_65 ( struct V_36 * V_37 )
{
T_1 V_35 ;
F_41 ( V_37 , V_123 , & V_35 ) ;
F_35 ( V_37 , V_123 , V_35 & ~ V_170 ) ;
}
bool F_66 ( struct V_36 * V_171 )
{
if ( ! F_11 ( V_171 -> V_39 + V_172 ) )
return false ;
if ( F_11 ( V_171 -> V_39 + V_173 ) )
return false ;
return true ;
}
static int F_67 ( struct V_36 * V_37 )
{
T_1 V_20 ;
if ( ! F_66 ( V_37 ) )
return - V_122 ;
if ( ! F_68 ( V_37 -> V_174 ) ) {
F_69 ( V_37 -> V_174 ) ;
F_70 ( V_37 -> V_174 ) ;
F_69 ( V_37 -> V_174 ) ;
F_49 ( V_37 ) ;
}
F_57 ( V_37 ) ;
F_41 ( V_37 , V_146 , & V_20 ) ;
V_20 |= V_175 ;
F_56 ( & V_20 , 1 ) ;
F_35 ( V_37 , V_146 , V_20 ) ;
return 0 ;
}
static void F_71 ( struct V_36 * V_37 )
{
if ( ! F_68 ( V_37 -> V_174 ) )
F_70 ( V_37 -> V_174 ) ;
}
static int F_72 ( struct V_176 * V_177 , int V_178 , int V_179 )
{
struct V_36 * V_37 = V_177 -> V_180 ;
T_1 V_20 ;
V_20 = F_47 ( V_37 , V_178 , V_179 ) ;
F_73 ( V_37 -> V_38 , L_6 ,
V_178 , V_179 , V_20 ) ;
return V_20 ;
}
static int F_74 ( struct V_176 * V_177 , int V_178 , int V_179 ,
T_5 V_20 )
{
struct V_36 * V_37 = V_177 -> V_180 ;
F_73 ( V_37 -> V_38 , L_7 ,
V_178 , V_179 , V_20 ) ;
return F_42 ( V_37 , V_178 , V_179 , V_20 ) ;
}
static void F_75 ( struct V_119 * V_38 )
{
struct V_36 * V_37 = F_8 ( V_38 ) ;
struct V_181 * V_182 = V_37 -> V_183 ;
if ( V_182 -> V_184 ) {
if ( V_37 -> V_136 != V_182 -> V_185 ) {
V_37 -> V_136 = V_182 -> V_185 ;
F_51 ( V_37 ) ;
F_62 ( V_37 ) ;
F_63 ( V_37 ) ;
F_76 ( V_182 ) ;
}
} else {
F_64 ( V_37 ) ;
F_65 ( V_37 ) ;
V_37 -> V_136 = V_186 ;
F_76 ( V_182 ) ;
}
}
static int F_77 ( struct V_119 * V_38 )
{
struct V_36 * V_37 = F_8 ( V_38 ) ;
struct V_187 * V_188 ;
struct V_181 * V_183 ;
struct V_189 * V_190 = & V_37 -> V_191 -> V_190 ;
if ( V_190 -> V_192 ) {
V_188 = F_78 ( V_190 -> V_192 , L_8 , 0 ) ;
if ( ! V_188 ) {
F_73 ( V_38 , L_9 ) ;
return - V_122 ;
}
V_37 -> V_183 = F_79 ( V_188 ) ;
}
V_183 = V_37 -> V_183 ;
if ( ! V_183 ||
F_80 ( V_38 , V_183 , & F_75 ,
V_37 -> V_193 ) ) {
F_36 ( V_38 , L_10 ) ;
return - V_122 ;
}
V_37 -> V_136 = V_186 ;
V_183 -> V_194 &= ~ V_195 &
~ V_196 &
~ V_197 ;
V_183 -> V_198 = V_183 -> V_194 ;
return 0 ;
}
static int F_81 ( struct V_36 * V_37 ,
struct V_176 * V_199 )
{
struct V_189 * V_190 = & V_37 -> V_191 -> V_190 ;
struct V_119 * V_38 = V_37 -> V_38 ;
struct V_181 * V_200 ;
struct V_187 * V_201 ;
struct V_187 * V_202 = NULL ;
int V_203 ;
T_1 V_104 ;
if ( V_190 -> V_192 ) {
F_82 (dev->of_node, child_np) {
if ( F_83 ( V_201 ,
L_11 ) ) {
V_202 = V_201 ;
break;
}
}
if ( ! V_202 ) {
F_73 ( V_38 , L_12 ) ;
return - V_204 ;
}
return F_84 ( V_199 , V_202 ) ;
}
V_199 -> V_205 = ~ 0 ;
V_203 = F_85 ( V_199 ) ;
if ( V_203 )
return V_203 ;
V_203 = F_86 ( V_190 , L_13 , & V_104 ) ;
if ( V_203 )
V_203 = F_86 ( V_190 , L_14 , & V_104 ) ;
if ( V_203 )
return - V_206 ;
V_200 = F_87 ( V_199 , V_104 , false ) ;
if ( ! V_200 || F_68 ( V_200 ) )
return - V_207 ;
V_203 = F_88 ( V_200 ) ;
if ( V_203 )
F_89 ( V_200 ) ;
else
V_37 -> V_183 = V_200 ;
return V_203 ;
}
int F_90 ( struct V_36 * V_37 )
{
struct V_119 * V_38 = V_37 -> V_38 ;
struct V_176 * V_208 ;
int V_203 ;
V_208 = F_91 () ;
if ( ! V_208 )
return - V_209 ;
V_208 -> V_210 = L_15 ;
V_208 -> V_211 = F_72 ;
V_208 -> V_212 = F_74 ;
snprintf ( V_208 -> V_21 , V_213 , L_16 , L_17 ,
V_38 -> V_210 ) ;
V_208 -> V_180 = V_37 ;
V_208 -> V_214 = & V_38 -> V_190 ;
V_203 = F_81 ( V_37 , V_208 ) ;
if ( V_203 ) {
F_36 ( V_38 , L_18 ) ;
F_92 ( V_208 ) ;
return V_203 ;
}
V_37 -> V_208 = V_208 ;
V_203 = F_77 ( V_38 ) ;
if ( V_203 )
F_93 ( V_37 ) ;
return V_203 ;
}
void F_93 ( struct V_36 * V_37 )
{
if ( V_37 -> V_183 )
F_94 ( V_37 -> V_183 ) ;
F_95 ( V_37 -> V_208 ) ;
F_92 ( V_37 -> V_208 ) ;
V_37 -> V_208 = NULL ;
}
