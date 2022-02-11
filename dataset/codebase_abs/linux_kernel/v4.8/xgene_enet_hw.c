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
if ( F_15 ( V_2 -> V_21 ) == V_46 ||
F_15 ( V_2 -> V_21 ) == V_47 )
F_6 ( V_2 ) ;
F_1 ( V_2 ) ;
F_12 ( V_2 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_1 V_48 , V_49 ;
bool V_19 ;
V_19 = F_5 ( V_2 -> V_21 ) ;
V_48 = V_2 -> V_21 & F_17 ( 9 , 0 ) ;
V_48 |= V_50 ;
V_49 = ( V_2 -> V_42 << 9 ) & F_17 ( 18 , 9 ) ;
V_49 |= V_51 ;
if ( V_19 )
V_49 |= V_52 ;
F_7 ( V_2 , V_53 , V_48 ) ;
F_7 ( V_2 , V_54 , V_49 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_1 V_55 ;
V_55 = V_2 -> V_21 | V_50 ;
F_7 ( V_2 , V_53 , V_55 ) ;
F_7 ( V_2 , V_54 , 0 ) ;
}
static struct V_1 * F_19 (
struct V_1 * V_2 )
{
T_1 V_56 = V_2 -> V_56 ;
T_1 V_40 , V_35 ;
bool V_19 ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
F_16 ( V_2 ) ;
V_2 -> V_57 = F_20 ( V_2 -> V_21 , V_56 ) ;
V_19 = F_5 ( V_2 -> V_21 ) ;
if ( V_19 || F_15 ( V_2 -> V_21 ) != V_58 )
return V_2 ;
for ( V_40 = 0 ; V_40 < V_2 -> V_57 ; V_40 ++ )
F_21 ( & V_2 -> V_59 [ V_40 ] ) ;
F_10 ( V_2 , V_60 , & V_35 ) ;
V_35 |= F_22 ( 31 - F_23 ( V_2 -> V_21 ) ) ;
F_7 ( V_2 , V_60 , V_35 ) ;
return V_2 ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_1 V_35 ;
bool V_19 ;
V_19 = F_5 ( V_2 -> V_21 ) ;
if ( V_19 || F_15 ( V_2 -> V_21 ) != V_58 )
goto V_61;
F_10 ( V_2 , V_60 , & V_35 ) ;
V_35 &= ~ F_22 ( 31 - F_23 ( V_2 -> V_21 ) ) ;
F_7 ( V_2 , V_60 , V_35 ) ;
V_61:
F_18 ( V_2 ) ;
F_13 ( V_2 ) ;
}
static void F_25 ( struct V_1 * V_2 , int V_62 )
{
F_9 ( V_62 , V_2 -> V_63 ) ;
}
static T_1 F_26 ( struct V_1 * V_2 )
{
T_1 T_3 * V_64 = V_2 -> V_64 ;
T_1 V_65 , V_66 ;
V_65 = F_11 ( & V_64 [ 1 ] ) ;
V_66 = F_27 ( V_67 , V_65 ) ;
return V_66 ;
}
static void F_28 ( struct V_1 * V_2 )
{
T_1 V_35 = 0x7777 ;
F_7 ( V_2 , V_68 , 0x8e ) ;
F_7 ( V_2 , V_69 , V_35 ) ;
F_7 ( V_2 , V_70 , V_35 << 16 ) ;
F_7 ( V_2 , V_71 , 0x40 ) ;
F_7 ( V_2 , V_72 , 0x80 ) ;
}
void F_29 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
enum V_73 V_74 )
{
switch ( V_74 ) {
case V_75 :
V_2 -> V_76 ++ ;
V_2 -> V_77 ++ ;
break;
case V_78 :
case V_79 :
V_2 -> V_80 ++ ;
V_2 -> V_77 ++ ;
break;
case V_81 :
V_2 -> V_82 ++ ;
V_2 -> V_77 ++ ;
break;
case V_83 :
V_2 -> V_84 ++ ;
V_2 -> V_77 ++ ;
break;
case V_85 :
V_2 -> V_82 ++ ;
V_2 -> V_77 ++ ;
break;
case V_86 :
V_2 -> V_87 ++ ;
break;
default:
break;
}
}
static void F_30 ( struct V_36 * V_37 ,
T_1 V_34 , T_1 V_20 )
{
void T_3 * V_5 = V_37 -> V_88 + V_34 ;
F_9 ( V_20 , V_5 ) ;
}
static void F_31 ( struct V_36 * V_37 ,
T_1 V_34 , T_1 V_20 )
{
void T_3 * V_5 = V_37 -> V_89 + V_34 ;
F_9 ( V_20 , V_5 ) ;
}
static void F_32 ( struct V_36 * V_37 ,
T_1 V_34 , T_1 V_20 )
{
void T_3 * V_5 = V_37 -> V_90 + V_34 ;
F_9 ( V_20 , V_5 ) ;
}
static void F_33 ( struct V_36 * V_37 ,
T_1 V_34 , T_1 V_20 )
{
void T_3 * V_5 = V_37 -> V_91 + V_34 ;
F_9 ( V_20 , V_5 ) ;
}
static bool F_34 ( void T_3 * V_5 , void T_3 * V_92 ,
void T_3 * V_63 , void T_3 * V_93 ,
T_1 V_94 , T_1 V_95 )
{
T_1 V_96 ;
T_4 V_97 = 10 ;
F_9 ( V_94 , V_5 ) ;
F_9 ( V_95 , V_92 ) ;
F_9 ( V_98 , V_63 ) ;
while ( ! ( V_96 = F_11 ( V_93 ) ) && V_97 -- )
F_35 ( 1 ) ;
if ( ! V_96 )
return false ;
F_9 ( 0 , V_63 ) ;
return true ;
}
static void F_36 ( struct V_36 * V_37 ,
T_1 V_94 , T_1 V_95 )
{
void T_3 * V_5 , * V_92 , * V_63 , * V_93 ;
V_5 = V_37 -> V_99 + V_100 ;
V_92 = V_37 -> V_99 + V_101 ;
V_63 = V_37 -> V_99 + V_102 ;
V_93 = V_37 -> V_99 + V_103 ;
if ( ! F_34 ( V_5 , V_92 , V_63 , V_93 , V_94 , V_95 ) )
F_37 ( V_37 -> V_38 , L_1 ,
V_94 ) ;
}
static void F_38 ( struct V_36 * V_37 ,
T_1 V_34 , T_1 * V_20 )
{
void T_3 * V_5 = V_37 -> V_88 + V_34 ;
* V_20 = F_11 ( V_5 ) ;
}
static void F_39 ( struct V_36 * V_37 ,
T_1 V_34 , T_1 * V_20 )
{
void T_3 * V_5 = V_37 -> V_90 + V_34 ;
* V_20 = F_11 ( V_5 ) ;
}
static void F_40 ( struct V_36 * V_37 ,
T_1 V_34 , T_1 * V_20 )
{
void T_3 * V_5 = V_37 -> V_91 + V_34 ;
* V_20 = F_11 ( V_5 ) ;
}
static bool F_41 ( void T_3 * V_5 , void T_3 * V_104 ,
void T_3 * V_63 , void T_3 * V_93 ,
T_1 V_105 , T_1 * V_106 )
{
T_1 V_96 ;
T_4 V_97 = 10 ;
F_9 ( V_105 , V_5 ) ;
F_9 ( V_107 , V_63 ) ;
while ( ! ( V_96 = F_11 ( V_93 ) ) && V_97 -- )
F_35 ( 1 ) ;
if ( ! V_96 )
return false ;
* V_106 = F_11 ( V_104 ) ;
F_9 ( 0 , V_63 ) ;
return true ;
}
static void F_42 ( struct V_36 * V_37 ,
T_1 V_105 , T_1 * V_106 )
{
void T_3 * V_5 , * V_104 , * V_63 , * V_93 ;
V_5 = V_37 -> V_99 + V_100 ;
V_104 = V_37 -> V_99 + V_108 ;
V_63 = V_37 -> V_99 + V_102 ;
V_93 = V_37 -> V_99 + V_103 ;
if ( ! F_41 ( V_5 , V_104 , V_63 , V_93 , V_105 , V_106 ) )
F_37 ( V_37 -> V_38 , L_2 ,
V_105 ) ;
}
static void F_43 ( struct V_36 * V_37 )
{
T_1 V_109 , V_110 ;
T_4 * V_111 = V_37 -> V_38 -> V_111 ;
V_109 = ( V_111 [ 3 ] << 24 ) | ( V_111 [ 2 ] << 16 ) |
( V_111 [ 1 ] << 8 ) | V_111 [ 0 ] ;
V_110 = ( V_111 [ 5 ] << 24 ) | ( V_111 [ 4 ] << 16 ) ;
F_36 ( V_37 , V_112 , V_109 ) ;
F_36 ( V_37 , V_113 , V_110 ) ;
}
static int F_44 ( struct V_36 * V_37 )
{
struct V_114 * V_38 = V_37 -> V_38 ;
T_1 V_35 ;
T_4 V_97 = 10 ;
F_32 ( V_37 , V_115 , 0x0 ) ;
do {
F_45 ( 100 , 110 ) ;
F_39 ( V_37 , V_116 , & V_35 ) ;
} while ( ( V_35 != 0xffffffff ) && V_97 -- );
if ( V_35 != 0xffffffff ) {
F_37 ( V_38 , L_3 ) ;
return - V_117 ;
}
return 0 ;
}
static void F_46 ( struct V_36 * V_37 )
{
F_36 ( V_37 , V_118 , V_119 ) ;
F_36 ( V_37 , V_118 , 0 ) ;
}
static void F_47 ( struct V_36 * V_37 )
{
struct V_120 * V_121 = & V_37 -> V_122 -> V_121 ;
if ( V_121 -> V_123 ) {
struct V_124 * V_125 = F_48 ( V_37 -> V_124 ) ;
switch ( V_37 -> V_126 ) {
case V_127 :
F_49 ( V_125 , 2500000 ) ;
break;
case V_128 :
F_49 ( V_125 , 25000000 ) ;
break;
default:
F_49 ( V_125 , 125000000 ) ;
break;
}
}
#ifdef F_50
else {
switch ( V_37 -> V_126 ) {
case V_127 :
F_51 ( F_52 ( V_121 ) ,
L_4 , NULL , NULL ) ;
break;
case V_128 :
F_51 ( F_52 ( V_121 ) ,
L_5 , NULL , NULL ) ;
break;
default:
F_51 ( F_52 ( V_121 ) ,
L_6 , NULL , NULL ) ;
break;
}
}
#endif
}
static void F_53 ( struct V_36 * V_37 )
{
struct V_120 * V_121 = & V_37 -> V_122 -> V_121 ;
T_1 V_129 , V_130 , V_131 ;
T_1 V_132 , V_133 , V_134 ;
F_40 ( V_37 , V_135 , & V_129 ) ;
F_40 ( V_37 , V_136 , & V_130 ) ;
F_42 ( V_37 , V_137 , & V_131 ) ;
F_42 ( V_37 , V_138 , & V_132 ) ;
F_38 ( V_37 , V_139 , & V_133 ) ;
switch ( V_37 -> V_126 ) {
case V_127 :
F_54 ( & V_131 , 1 ) ;
V_132 &= ~ ( V_140 | V_141 ) ;
F_55 ( & V_129 , 0 ) ;
F_56 ( & V_130 , 500 ) ;
V_133 &= ~ V_142 ;
break;
case V_128 :
F_54 ( & V_131 , 1 ) ;
V_132 &= ~ V_141 ;
V_132 |= V_140 ;
F_55 ( & V_129 , 1 ) ;
F_56 ( & V_130 , 80 ) ;
V_133 &= ~ V_142 ;
break;
default:
F_54 ( & V_131 , 2 ) ;
V_132 &= ~ V_140 ;
V_132 |= V_141 ;
F_55 ( & V_129 , 2 ) ;
F_56 ( & V_130 , 0 ) ;
if ( V_121 -> V_123 ) {
F_57 ( & V_133 , V_37 -> V_143 ) ;
F_58 ( & V_133 , V_37 -> V_144 ) ;
}
V_133 |= V_142 ;
F_38 ( V_37 , V_145 , & V_134 ) ;
V_134 |= V_146 | V_147 ;
F_30 ( V_37 , V_145 , V_134 ) ;
break;
}
V_131 |= V_148 | V_149 ;
F_36 ( V_37 , V_137 , V_131 ) ;
F_36 ( V_37 , V_138 , V_132 ) ;
F_30 ( V_37 , V_139 , V_133 ) ;
F_47 ( V_37 ) ;
F_33 ( V_37 , V_135 , V_129 ) ;
F_33 ( V_37 , V_136 , V_130 ) ;
}
static void F_59 ( struct V_36 * V_37 )
{
T_1 V_134 ;
if ( ! V_37 -> V_150 )
F_46 ( V_37 ) ;
F_53 ( V_37 ) ;
F_43 ( V_37 ) ;
F_42 ( V_37 , V_151 , & V_134 ) ;
F_60 ( & V_134 , 7 ) ;
F_36 ( V_37 , V_151 , V_134 ) ;
F_38 ( V_37 , V_152 , & V_134 ) ;
V_134 |= V_153 ;
F_30 ( V_37 , V_152 , V_134 ) ;
F_30 ( V_37 , V_154 , 0 ) ;
F_30 ( V_37 , V_155 , V_156 ) ;
F_40 ( V_37 , V_157 , & V_134 ) ;
V_134 &= ~ V_158 ;
V_134 &= ~ V_159 ;
V_134 |= V_160 ;
F_33 ( V_37 , V_157 , V_134 ) ;
F_30 ( V_37 , V_161 , V_162 ) ;
}
static void F_61 ( struct V_36 * V_37 )
{
T_1 V_20 = 0xffffffff ;
F_31 ( V_37 , V_163 , V_20 ) ;
F_31 ( V_37 , V_164 , V_20 ) ;
F_31 ( V_37 , V_165 , V_20 ) ;
F_31 ( V_37 , V_166 , V_20 ) ;
}
static void F_62 ( struct V_36 * V_37 ,
T_1 V_167 , T_5 V_168 )
{
T_1 V_169 ;
T_1 V_170 ;
V_170 = F_23 ( V_168 ) - 0x20 ;
F_38 ( V_37 , V_171 , & V_169 ) ;
V_169 |= V_172 ;
F_63 ( & V_169 , 3 ) ;
F_30 ( V_37 , V_171 , V_169 ) ;
F_38 ( V_37 , V_173 , & V_169 ) ;
F_64 ( & V_169 , V_167 ) ;
F_65 ( & V_169 , V_170 ) ;
F_30 ( V_37 , V_173 , V_169 ) ;
}
static void F_66 ( struct V_36 * V_37 )
{
T_1 V_35 ;
F_42 ( V_37 , V_118 , & V_35 ) ;
F_36 ( V_37 , V_118 , V_35 | V_174 ) ;
}
static void F_67 ( struct V_36 * V_37 )
{
T_1 V_35 ;
F_42 ( V_37 , V_118 , & V_35 ) ;
F_36 ( V_37 , V_118 , V_35 | V_175 ) ;
}
static void F_68 ( struct V_36 * V_37 )
{
T_1 V_35 ;
F_42 ( V_37 , V_118 , & V_35 ) ;
F_36 ( V_37 , V_118 , V_35 & ~ V_174 ) ;
}
static void F_69 ( struct V_36 * V_37 )
{
T_1 V_35 ;
F_42 ( V_37 , V_118 , & V_35 ) ;
F_36 ( V_37 , V_118 , V_35 & ~ V_175 ) ;
}
bool F_70 ( struct V_36 * V_176 )
{
if ( ! F_11 ( V_176 -> V_39 + V_177 ) )
return false ;
if ( F_11 ( V_176 -> V_39 + V_178 ) )
return false ;
return true ;
}
static int F_71 ( struct V_36 * V_37 )
{
struct V_120 * V_121 = & V_37 -> V_122 -> V_121 ;
if ( ! F_70 ( V_37 ) )
return - V_117 ;
if ( V_37 -> V_150 ) {
F_61 ( V_37 ) ;
return 0 ;
}
if ( V_121 -> V_123 ) {
F_72 ( V_37 -> V_124 ) ;
F_35 ( 5 ) ;
F_73 ( V_37 -> V_124 ) ;
F_35 ( 5 ) ;
F_72 ( V_37 -> V_124 ) ;
F_35 ( 5 ) ;
} else {
#ifdef F_50
if ( F_74 ( F_52 ( & V_37 -> V_122 -> V_121 ) , L_7 ) ) {
F_51 ( F_52 ( & V_37 -> V_122 -> V_121 ) ,
L_7 , NULL , NULL ) ;
} else if ( F_74 ( F_52 ( & V_37 -> V_122 -> V_121 ) ,
L_8 ) ) {
F_51 ( F_52 ( & V_37 -> V_122 -> V_121 ) ,
L_8 , NULL , NULL ) ;
}
#endif
}
F_44 ( V_37 ) ;
F_61 ( V_37 ) ;
return 0 ;
}
static void F_75 ( struct V_36 * V_37 ,
struct V_1 * V_2 )
{
T_1 V_5 , V_20 , V_35 ;
V_20 = F_23 ( V_2 -> V_21 ) ;
if ( F_5 ( V_2 -> V_21 ) ) {
V_5 = V_179 ;
V_35 = F_22 ( V_20 - 0x20 ) ;
} else {
V_5 = V_180 ;
V_35 = F_22 ( V_20 ) ;
}
F_31 ( V_37 , V_5 , V_35 ) ;
}
static void F_76 ( struct V_36 * V_37 )
{
struct V_120 * V_121 = & V_37 -> V_122 -> V_121 ;
struct V_1 * V_2 ;
T_1 V_181 , V_20 ;
int V_40 ;
V_181 = 0 ;
for ( V_40 = 0 ; V_40 < V_37 -> V_182 ; V_40 ++ ) {
V_2 = V_37 -> V_183 [ V_40 ] -> V_184 ;
V_20 = F_23 ( V_2 -> V_21 ) ;
V_181 |= F_22 ( V_20 - 0x20 ) ;
}
F_31 ( V_37 , V_179 , V_181 ) ;
V_181 = 0 ;
for ( V_40 = 0 ; V_40 < V_37 -> V_185 ; V_40 ++ ) {
V_2 = V_37 -> V_186 [ V_40 ] ;
V_20 = F_23 ( V_2 -> V_21 ) ;
V_181 |= F_22 ( V_20 ) ;
}
F_31 ( V_37 , V_180 , V_181 ) ;
if ( V_121 -> V_123 ) {
if ( ! F_77 ( V_37 -> V_124 ) )
F_73 ( V_37 -> V_124 ) ;
}
}
static void F_78 ( struct V_114 * V_38 )
{
struct V_36 * V_37 = F_8 ( V_38 ) ;
const struct V_187 * V_188 = V_37 -> V_188 ;
struct V_189 * V_190 = V_37 -> V_191 ;
if ( V_190 -> V_192 ) {
if ( V_37 -> V_126 != V_190 -> V_193 ) {
V_37 -> V_126 = V_190 -> V_193 ;
V_188 -> V_194 ( V_37 ) ;
V_188 -> V_195 ( V_37 ) ;
V_188 -> V_196 ( V_37 ) ;
F_79 ( V_190 ) ;
}
} else {
V_188 -> V_197 ( V_37 ) ;
V_188 -> V_198 ( V_37 ) ;
V_37 -> V_126 = V_199 ;
F_79 ( V_190 ) ;
}
}
static struct V_200 * F_80 ( struct V_120 * V_121 )
{
struct V_201 args ;
struct V_202 * V_203 ;
int V_74 ;
V_203 = F_81 ( F_82 ( V_121 ) ) ;
V_74 = F_83 ( V_203 , L_9 , 0 ,
& args ) ;
if ( F_84 ( V_74 ) ) {
F_85 ( V_121 , L_10 ) ;
return NULL ;
}
return args . V_204 ;
}
int F_86 ( struct V_114 * V_38 )
{
struct V_36 * V_37 = F_8 ( V_38 ) ;
struct V_205 * V_206 ;
struct V_189 * V_191 ;
struct V_120 * V_121 = & V_37 -> V_122 -> V_121 ;
int V_40 ;
if ( V_121 -> V_123 ) {
for ( V_40 = 0 ; V_40 < 2 ; V_40 ++ ) {
V_206 = F_87 ( V_121 -> V_123 , L_9 , V_40 ) ;
if ( V_206 )
break;
}
if ( ! V_206 ) {
F_88 ( V_38 , L_11 ) ;
return - V_117 ;
}
V_191 = F_89 ( V_38 , V_206 , & F_78 ,
0 , V_37 -> V_207 ) ;
F_90 ( V_206 ) ;
if ( ! V_191 ) {
F_37 ( V_38 , L_12 ) ;
return - V_117 ;
}
V_37 -> V_191 = V_191 ;
} else {
#ifdef F_50
struct V_200 * V_204 = F_80 ( V_121 ) ;
if ( V_204 )
V_37 -> V_191 = V_204 -> V_208 ;
V_191 = V_37 -> V_191 ;
if ( ! V_191 ||
F_91 ( V_38 , V_191 , & F_78 ,
V_37 -> V_207 ) ) {
F_37 ( V_38 , L_12 ) ;
return - V_117 ;
}
#else
return - V_117 ;
#endif
}
V_37 -> V_126 = V_199 ;
V_191 -> V_209 &= ~ V_210 &
~ V_211 &
~ V_212 ;
V_191 -> V_213 = V_191 -> V_209 ;
return 0 ;
}
static int F_92 ( struct V_36 * V_37 ,
struct V_214 * V_215 )
{
struct V_120 * V_121 = & V_37 -> V_122 -> V_121 ;
struct V_114 * V_38 = V_37 -> V_38 ;
struct V_189 * V_216 ;
struct V_205 * V_217 ;
struct V_205 * V_218 = NULL ;
T_1 V_219 ;
int V_220 ;
if ( V_121 -> V_123 ) {
F_93 (dev->of_node, child_np) {
if ( F_94 ( V_217 ,
L_13 ) ) {
V_218 = V_217 ;
break;
}
}
if ( ! V_218 ) {
F_88 ( V_38 , L_14 ) ;
return - V_221 ;
}
return F_95 ( V_215 , V_218 ) ;
}
V_215 -> V_222 = ~ 0 ;
V_220 = F_96 ( V_215 ) ;
if ( V_220 )
return V_220 ;
V_220 = F_97 ( V_121 , L_15 , & V_219 ) ;
if ( V_220 )
V_220 = F_97 ( V_121 , L_16 , & V_219 ) ;
if ( V_220 )
return - V_223 ;
V_216 = F_98 ( V_215 , V_219 ) ;
if ( ! V_216 )
return - V_224 ;
V_37 -> V_191 = V_216 ;
return V_220 ;
}
int F_99 ( struct V_36 * V_37 )
{
struct V_114 * V_38 = V_37 -> V_38 ;
struct V_214 * V_225 ;
int V_220 ;
V_225 = F_100 () ;
if ( ! V_225 )
return - V_226 ;
V_225 -> V_227 = L_17 ;
V_225 -> V_228 = V_229 ;
V_225 -> V_230 = V_231 ;
snprintf ( V_225 -> V_21 , V_232 , L_18 , L_19 ,
V_38 -> V_227 ) ;
V_225 -> V_233 = ( void V_234 * ) V_37 -> V_99 ;
V_225 -> V_125 = & V_37 -> V_122 -> V_121 ;
V_220 = F_92 ( V_37 , V_225 ) ;
if ( V_220 ) {
F_37 ( V_38 , L_20 ) ;
F_101 ( V_225 ) ;
return V_220 ;
}
V_37 -> V_225 = V_225 ;
V_220 = F_86 ( V_38 ) ;
if ( V_220 )
F_102 ( V_37 ) ;
return V_220 ;
}
void F_103 ( struct V_36 * V_37 )
{
if ( V_37 -> V_191 )
F_104 ( V_37 -> V_191 ) ;
}
void F_102 ( struct V_36 * V_37 )
{
if ( V_37 -> V_191 )
F_104 ( V_37 -> V_191 ) ;
F_105 ( V_37 -> V_225 ) ;
F_101 ( V_37 -> V_225 ) ;
V_37 -> V_225 = NULL ;
}
