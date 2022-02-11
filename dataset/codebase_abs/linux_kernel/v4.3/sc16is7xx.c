static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , V_2 ) ;
return V_4 -> line ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_1 V_5 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
unsigned int V_9 = 0 ;
const T_1 line = F_1 ( V_2 ) ;
F_5 ( V_7 -> V_10 , ( V_5 << V_11 ) | line , & V_9 ) ;
return V_9 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_9 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
const T_1 line = F_1 ( V_2 ) ;
F_7 ( V_7 -> V_10 , ( V_5 << V_11 ) | line , V_9 ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned int V_12 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
const T_1 line = F_1 ( V_2 ) ;
T_1 V_13 = ( V_14 << V_11 ) | line ;
F_9 ( V_7 -> V_10 , true ) ;
F_10 ( V_7 -> V_10 , V_13 , V_7 -> V_15 , V_12 ) ;
F_9 ( V_7 -> V_10 , false ) ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
const T_1 line = F_1 ( V_2 ) ;
T_1 V_13 = ( V_17 << V_11 ) | line ;
F_9 ( V_7 -> V_10 , true ) ;
F_12 ( V_7 -> V_10 , V_13 , V_7 -> V_15 , V_16 ) ;
F_9 ( V_7 -> V_10 , false ) ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_5 ,
T_1 V_18 , T_1 V_9 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
const T_1 line = F_1 ( V_2 ) ;
F_14 ( V_7 -> V_10 , ( V_5 << V_11 ) | line ,
V_18 , V_9 ) ;
}
static int F_15 ( void )
{
int V_19 ;
F_16 ( V_20 > V_21 ) ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ )
if ( ! F_17 ( V_19 , & V_22 ) )
break;
return V_19 ;
}
static void F_18 ( struct V_1 * V_2 , int V_23 )
{
F_13 ( V_2 , V_24 ,
V_25 ,
V_23 ? 0 : V_25 ) ;
}
static bool F_19 ( struct V_26 * V_8 , unsigned int V_5 )
{
switch ( V_5 >> V_11 ) {
case V_14 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
return true ;
default:
break;
}
return false ;
}
static bool F_20 ( struct V_26 * V_8 , unsigned int V_5 )
{
switch ( V_5 >> V_11 ) {
case V_14 :
return true ;
default:
break;
}
return false ;
}
static int F_21 ( struct V_1 * V_2 , int V_33 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
T_1 V_34 ;
T_1 V_35 = 0 ;
unsigned long V_36 = V_2 -> V_37 , div = V_36 / 16 / V_33 ;
if ( div > 0xffff ) {
V_35 = V_38 ;
div /= 4 ;
}
V_34 = F_3 ( V_2 , V_39 ) ;
F_6 ( V_2 , V_39 ,
V_40 ) ;
F_9 ( V_7 -> V_10 , true ) ;
F_6 ( V_2 , V_41 ,
V_42 ) ;
F_9 ( V_7 -> V_10 , false ) ;
F_6 ( V_2 , V_39 , V_34 ) ;
F_13 ( V_2 , V_43 ,
V_38 ,
V_35 ) ;
F_6 ( V_2 , V_39 ,
V_44 ) ;
F_9 ( V_7 -> V_10 , true ) ;
F_6 ( V_2 , V_45 , div / 256 ) ;
F_6 ( V_2 , V_46 , div % 256 ) ;
F_9 ( V_7 -> V_10 , false ) ;
F_6 ( V_2 , V_39 , V_34 ) ;
return F_22 ( V_36 / 16 , div ) ;
}
static void F_23 ( struct V_1 * V_2 , unsigned int V_12 ,
unsigned int V_47 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
unsigned int V_48 = 0 , V_49 , V_50 , V_51 , V_19 ;
bool V_52 = ( V_47 == V_53 ) ? true : false ;
if ( F_24 ( V_12 >= sizeof( V_7 -> V_15 ) ) ) {
F_25 ( V_2 -> V_8 ,
L_1 ,
V_2 -> line , V_12 ) ;
V_2 -> V_54 . V_55 ++ ;
V_12 = sizeof( V_7 -> V_15 ) ;
}
while ( V_12 ) {
if ( V_52 ) {
V_48 = F_3 ( V_2 , V_28 ) ;
if ( ! ( V_48 & V_56 ) )
V_52 = false ;
} else
V_48 = 0 ;
if ( V_52 ) {
V_7 -> V_15 [ 0 ] = F_3 ( V_2 , V_14 ) ;
V_51 = 1 ;
} else {
F_8 ( V_2 , V_12 ) ;
V_51 = V_12 ;
}
V_48 &= V_57 ;
V_2 -> V_54 . V_58 ++ ;
V_50 = V_59 ;
if ( F_24 ( V_48 ) ) {
if ( V_48 & V_60 ) {
V_2 -> V_54 . V_61 ++ ;
if ( F_26 ( V_2 ) )
continue;
} else if ( V_48 & V_62 )
V_2 -> V_54 . V_63 ++ ;
else if ( V_48 & V_64 )
V_2 -> V_54 . V_65 ++ ;
else if ( V_48 & V_66 )
V_2 -> V_54 . V_67 ++ ;
V_48 &= V_2 -> V_68 ;
if ( V_48 & V_60 )
V_50 = V_69 ;
else if ( V_48 & V_62 )
V_50 = V_70 ;
else if ( V_48 & V_64 )
V_50 = V_71 ;
else if ( V_48 & V_66 )
V_50 = V_72 ;
}
for ( V_19 = 0 ; V_19 < V_51 ; ++ V_19 ) {
V_49 = V_7 -> V_15 [ V_19 ] ;
if ( F_27 ( V_2 , V_49 ) )
continue;
if ( V_48 & V_2 -> V_73 )
continue;
F_28 ( V_2 , V_48 , V_66 , V_49 ,
V_50 ) ;
}
V_12 -= V_51 ;
}
F_29 ( & V_2 -> V_74 -> V_2 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
struct V_75 * V_76 = & V_2 -> V_74 -> V_76 ;
unsigned int V_77 , V_16 , V_19 ;
if ( F_24 ( V_2 -> V_78 ) ) {
F_6 ( V_2 , V_17 , V_2 -> V_78 ) ;
V_2 -> V_54 . V_79 ++ ;
V_2 -> V_78 = 0 ;
return;
}
if ( F_31 ( V_76 ) || F_32 ( V_2 ) )
return;
V_16 = F_33 ( V_76 ) ;
if ( F_34 ( V_16 ) ) {
V_77 = F_3 ( V_2 , V_30 ) ;
V_16 = ( V_16 > V_77 ) ? V_77 : V_16 ;
V_2 -> V_54 . V_79 += V_16 ;
for ( V_19 = 0 ; V_19 < V_16 ; ++ V_19 ) {
V_7 -> V_15 [ V_19 ] = V_76 -> V_15 [ V_76 -> V_80 ] ;
V_76 -> V_80 = ( V_76 -> V_80 + 1 ) & ( V_81 - 1 ) ;
}
F_11 ( V_2 , V_16 ) ;
}
if ( F_33 ( V_76 ) < V_82 )
F_35 ( V_2 ) ;
}
static void F_36 ( struct V_6 * V_7 , int V_83 )
{
struct V_1 * V_2 = & V_7 -> V_84 [ V_83 ] . V_2 ;
do {
unsigned int V_47 , V_85 , V_12 ;
V_47 = F_3 ( V_2 , V_27 ) ;
if ( V_47 & V_86 )
break;
V_47 &= V_87 ;
switch ( V_47 ) {
case V_88 :
case V_53 :
case V_89 :
case V_90 :
V_12 = F_3 ( V_2 , V_31 ) ;
if ( V_12 )
F_23 ( V_2 , V_12 , V_47 ) ;
break;
case V_91 :
V_85 = F_3 ( V_2 , V_29 ) ;
F_37 ( V_2 ,
! ! ( V_85 & V_92 ) ) ;
break;
case V_93 :
F_30 ( V_2 ) ;
break;
default:
F_38 ( V_2 -> V_8 ,
L_2 ,
V_2 -> line , V_47 ) ;
break;
}
} while ( 1 );
}
static void F_39 ( struct V_94 * V_95 )
{
struct V_6 * V_7 = F_40 ( V_95 , V_96 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_7 -> V_97 -> V_98 ; ++ V_19 )
F_36 ( V_7 , V_19 ) ;
}
static T_2 F_41 ( int V_99 , void * V_100 )
{
struct V_6 * V_7 = (struct V_6 * ) V_100 ;
F_42 ( & V_7 -> V_101 , & V_7 -> V_96 ) ;
return V_102 ;
}
static void F_43 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = & ( F_2 ( V_95 , V_103 ) -> V_2 ) ;
if ( ( V_2 -> V_104 . V_105 & V_106 ) &&
( V_2 -> V_104 . V_107 > 0 ) )
F_44 ( V_2 -> V_104 . V_107 ) ;
F_30 ( V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
const T_3 V_18 = V_108 |
V_109 ;
T_3 V_110 = 0 ;
struct V_111 * V_104 = & V_2 -> V_104 ;
unsigned long V_112 ;
F_46 ( & V_2 -> V_113 , V_112 ) ;
if ( V_104 -> V_105 & V_106 ) {
V_110 |= V_108 ;
if ( V_104 -> V_105 & V_114 )
V_110 |= V_109 ;
}
F_47 ( & V_2 -> V_113 , V_112 ) ;
F_13 ( V_2 , V_115 , V_18 , V_110 ) ;
}
static void F_48 ( struct V_94 * V_95 )
{
struct V_3 * V_4 = F_2 ( V_95 , V_116 ) ;
struct V_117 V_118 ;
unsigned long V_112 ;
F_46 ( & V_4 -> V_2 . V_113 , V_112 ) ;
V_118 = V_4 -> V_118 ;
memset ( & V_4 -> V_118 , 0 , sizeof( V_4 -> V_118 ) ) ;
F_47 ( & V_4 -> V_2 . V_113 , V_112 ) ;
if ( V_118 . V_105 & V_119 )
F_13 ( & V_4 -> V_2 , V_43 ,
V_120 ,
( V_4 -> V_2 . V_121 & V_122 ) ?
V_120 : 0 ) ;
if ( V_118 . V_105 & V_123 )
F_13 ( & V_4 -> V_2 , V_24 ,
V_118 . V_124 , 0 ) ;
if ( V_118 . V_105 & V_125 )
F_45 ( & V_4 -> V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 , T_1 V_126 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
struct V_3 * V_4 = F_2 ( V_2 , V_2 ) ;
V_4 -> V_118 . V_105 |= V_123 ;
V_4 -> V_118 . V_124 |= V_126 ;
F_42 ( & V_7 -> V_101 , & V_4 -> V_116 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_49 ( V_2 , V_127 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_49 ( V_2 , V_128 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
struct V_3 * V_4 = F_2 ( V_2 , V_2 ) ;
F_42 ( & V_7 -> V_101 , & V_4 -> V_103 ) ;
}
static unsigned int F_53 ( struct V_1 * V_2 )
{
unsigned int V_48 ;
V_48 = F_3 ( V_2 , V_28 ) ;
return ( V_48 & V_129 ) ? V_130 : 0 ;
}
static unsigned int F_54 ( struct V_1 * V_2 )
{
return V_131 | V_132 ;
}
static void F_55 ( struct V_1 * V_2 , unsigned int V_121 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
struct V_3 * V_4 = F_2 ( V_2 , V_2 ) ;
V_4 -> V_118 . V_105 |= V_119 ;
F_42 ( & V_7 -> V_101 , & V_4 -> V_116 ) ;
}
static void F_56 ( struct V_1 * V_2 , int V_133 )
{
F_13 ( V_2 , V_39 ,
V_134 ,
V_133 ? V_134 : 0 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_135 * V_136 ,
struct V_135 * V_137 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
unsigned int V_34 , V_138 = 0 ;
int V_33 ;
V_136 -> V_139 &= ~ V_140 ;
switch ( V_136 -> V_139 & V_141 ) {
case V_142 :
V_34 = V_143 ;
break;
case V_144 :
V_34 = V_145 ;
break;
case V_146 :
V_34 = V_147 ;
break;
case V_148 :
V_34 = V_149 ;
break;
default:
V_34 = V_149 ;
V_136 -> V_139 &= ~ V_141 ;
V_136 -> V_139 |= V_148 ;
break;
}
if ( V_136 -> V_139 & V_150 ) {
V_34 |= V_151 ;
if ( ! ( V_136 -> V_139 & V_152 ) )
V_34 |= V_153 ;
}
if ( V_136 -> V_139 & V_154 )
V_34 |= V_155 ;
V_2 -> V_68 = V_66 ;
if ( V_136 -> V_156 & V_157 )
V_2 -> V_68 |= V_62 |
V_64 ;
if ( V_136 -> V_156 & ( V_158 | V_159 ) )
V_2 -> V_68 |= V_60 ;
V_2 -> V_73 = 0 ;
if ( V_136 -> V_156 & V_160 )
V_2 -> V_73 |= V_60 ;
if ( ! ( V_136 -> V_139 & V_161 ) )
V_2 -> V_73 |= V_57 ;
F_6 ( V_2 , V_39 ,
V_40 ) ;
F_9 ( V_7 -> V_10 , true ) ;
F_6 ( V_2 , V_162 , V_136 -> V_163 [ V_164 ] ) ;
F_6 ( V_2 , V_165 , V_136 -> V_163 [ V_166 ] ) ;
if ( V_136 -> V_139 & V_167 )
V_138 |= V_168 |
V_169 ;
if ( V_136 -> V_156 & V_170 )
V_138 |= V_171 ;
if ( V_136 -> V_156 & V_172 )
V_138 |= V_173 ;
F_6 ( V_2 , V_41 , V_138 ) ;
F_9 ( V_7 -> V_10 , false ) ;
F_6 ( V_2 , V_39 , V_34 ) ;
V_33 = F_58 ( V_2 , V_136 , V_137 ,
V_2 -> V_37 / 16 / 4 / 0xffff ,
V_2 -> V_37 / 16 ) ;
V_33 = F_21 ( V_2 , V_33 ) ;
F_59 ( V_2 , V_136 -> V_139 , V_33 ) ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_111 * V_104 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
struct V_3 * V_4 = F_2 ( V_2 , V_2 ) ;
if ( V_104 -> V_105 & V_106 ) {
bool V_174 , V_175 ;
V_174 = V_104 -> V_105 & V_114 ;
V_175 = V_104 -> V_105 & V_176 ;
if ( V_174 == V_175 )
F_61 ( V_2 -> V_8 ,
L_3 ,
V_175 , V_174 ) ;
if ( V_104 -> V_177 )
return - V_178 ;
}
V_2 -> V_104 = * V_104 ;
V_4 -> V_118 . V_105 |= V_125 ;
F_42 ( & V_7 -> V_101 , & V_4 -> V_116 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
unsigned int V_9 ;
F_18 ( V_2 , 1 ) ;
V_9 = V_179 | V_180 ;
F_6 ( V_2 , V_181 , V_9 ) ;
F_63 ( 5 ) ;
F_6 ( V_2 , V_181 ,
V_182 ) ;
F_6 ( V_2 , V_39 ,
V_40 ) ;
F_9 ( V_7 -> V_10 , true ) ;
F_6 ( V_2 , V_41 ,
V_42 ) ;
F_13 ( V_2 , V_43 ,
V_183 ,
V_183 ) ;
F_6 ( V_2 , V_184 ,
F_64 ( 24 ) |
F_65 ( 48 ) ) ;
F_9 ( V_7 -> V_10 , false ) ;
F_6 ( V_2 , V_39 , V_149 ) ;
F_13 ( V_2 , V_115 ,
V_185 |
V_186 ,
0 ) ;
V_9 = V_128 | V_127 |
V_187 ;
F_6 ( V_2 , V_24 , V_9 ) ;
return 0 ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
F_6 ( V_2 , V_24 , 0 ) ;
F_13 ( V_2 , V_115 ,
V_185 |
V_186 ,
V_185 |
V_186 ) ;
F_18 ( V_2 , 0 ) ;
F_67 ( & V_7 -> V_101 ) ;
}
static const char * F_68 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
return ( V_2 -> type == V_188 ) ? V_7 -> V_97 -> V_189 : NULL ;
}
static int F_69 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_70 ( struct V_1 * V_2 , int V_105 )
{
if ( V_105 & V_190 )
V_2 -> type = V_188 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_191 * V_7 )
{
if ( ( V_7 -> type != V_192 ) && ( V_7 -> type != V_188 ) )
return - V_178 ;
if ( V_7 -> V_99 != V_2 -> V_99 )
return - V_178 ;
return 0 ;
}
static void F_72 ( struct V_1 * V_2 , unsigned int V_74 ,
unsigned int V_193 )
{
F_18 ( V_2 , ( V_74 == V_194 ) ? 1 : 0 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
}
static int F_74 ( struct V_195 * V_196 , unsigned V_197 )
{
unsigned int V_9 ;
struct V_6 * V_7 = F_75 ( V_196 , struct V_6 ,
V_198 ) ;
struct V_1 * V_2 = & V_7 -> V_84 [ 0 ] . V_2 ;
V_9 = F_3 ( V_2 , V_32 ) ;
return ! ! ( V_9 & F_76 ( V_197 ) ) ;
}
static void F_77 ( struct V_195 * V_196 , unsigned V_197 , int V_9 )
{
struct V_6 * V_7 = F_75 ( V_196 , struct V_6 ,
V_198 ) ;
struct V_1 * V_2 = & V_7 -> V_84 [ 0 ] . V_2 ;
F_13 ( V_2 , V_32 , F_76 ( V_197 ) ,
V_9 ? F_76 ( V_197 ) : 0 ) ;
}
static int F_78 ( struct V_195 * V_196 ,
unsigned V_197 )
{
struct V_6 * V_7 = F_75 ( V_196 , struct V_6 ,
V_198 ) ;
struct V_1 * V_2 = & V_7 -> V_84 [ 0 ] . V_2 ;
F_13 ( V_2 , V_199 , F_76 ( V_197 ) , 0 ) ;
return 0 ;
}
static int F_79 ( struct V_195 * V_196 ,
unsigned V_197 , int V_9 )
{
struct V_6 * V_7 = F_75 ( V_196 , struct V_6 ,
V_198 ) ;
struct V_1 * V_2 = & V_7 -> V_84 [ 0 ] . V_2 ;
F_13 ( V_2 , V_32 , F_76 ( V_197 ) ,
V_9 ? F_76 ( V_197 ) : 0 ) ;
F_13 ( V_2 , V_199 , F_76 ( V_197 ) ,
F_76 ( V_197 ) ) ;
return 0 ;
}
static int F_80 ( struct V_26 * V_8 ,
const struct V_200 * V_97 ,
struct V_10 * V_10 , int V_99 , unsigned long V_105 )
{
struct V_201 V_201 = { . V_202 = V_203 / 2 } ;
unsigned long V_204 , * V_205 = F_81 ( V_8 ) ;
int V_19 , V_206 ;
struct V_6 * V_7 ;
if ( F_82 ( V_10 ) )
return F_83 ( V_10 ) ;
V_7 = F_84 ( V_8 , sizeof( * V_7 ) +
sizeof( struct V_3 ) * V_97 -> V_98 ,
V_207 ) ;
if ( ! V_7 ) {
F_61 ( V_8 , L_4 ) ;
return - V_208 ;
}
V_7 -> V_36 = F_85 ( V_8 , NULL ) ;
if ( F_82 ( V_7 -> V_36 ) ) {
if ( V_205 )
V_204 = * V_205 ;
else
return F_83 ( V_7 -> V_36 ) ;
} else {
F_86 ( V_7 -> V_36 ) ;
V_204 = F_87 ( V_7 -> V_36 ) ;
}
V_7 -> V_10 = V_10 ;
V_7 -> V_97 = V_97 ;
F_88 ( V_8 , V_7 ) ;
F_89 ( & V_7 -> V_101 ) ;
F_90 ( & V_7 -> V_96 , F_39 ) ;
V_7 -> V_209 = F_91 ( V_210 , & V_7 -> V_101 ,
L_5 ) ;
if ( F_82 ( V_7 -> V_209 ) ) {
V_206 = F_83 ( V_7 -> V_209 ) ;
goto V_211;
}
F_92 ( V_7 -> V_209 , V_212 , & V_201 ) ;
#ifdef F_93
if ( V_97 -> V_213 ) {
V_7 -> V_198 . V_214 = V_215 ;
V_7 -> V_198 . V_8 = V_8 ;
V_7 -> V_198 . V_216 = F_94 ( V_8 ) ;
V_7 -> V_198 . V_217 = F_78 ;
V_7 -> V_198 . V_218 = F_74 ;
V_7 -> V_198 . V_219 = F_79 ;
V_7 -> V_198 . V_220 = F_77 ;
V_7 -> V_198 . V_221 = - 1 ;
V_7 -> V_198 . V_222 = V_97 -> V_213 ;
V_7 -> V_198 . V_223 = 1 ;
V_206 = F_95 ( & V_7 -> V_198 ) ;
if ( V_206 )
goto V_224;
}
#endif
for ( V_19 = 0 ; V_19 < V_97 -> V_98 ; ++ V_19 ) {
V_7 -> V_84 [ V_19 ] . line = V_19 ;
V_7 -> V_84 [ V_19 ] . V_2 . V_8 = V_8 ;
V_7 -> V_84 [ V_19 ] . V_2 . V_99 = V_99 ;
V_7 -> V_84 [ V_19 ] . V_2 . type = V_188 ;
V_7 -> V_84 [ V_19 ] . V_2 . V_225 = V_226 ;
V_7 -> V_84 [ V_19 ] . V_2 . V_105 = V_227 | V_228 ;
V_7 -> V_84 [ V_19 ] . V_2 . V_229 = V_230 ;
V_7 -> V_84 [ V_19 ] . V_2 . V_37 = V_204 ;
V_7 -> V_84 [ V_19 ] . V_2 . V_231 = F_60 ;
V_7 -> V_84 [ V_19 ] . V_2 . V_232 = & V_233 ;
V_7 -> V_84 [ V_19 ] . V_2 . line = F_15 () ;
if ( V_7 -> V_84 [ V_19 ] . V_2 . line >= V_20 ) {
V_206 = - V_208 ;
goto V_234;
}
F_6 ( & V_7 -> V_84 [ V_19 ] . V_2 , V_24 , 0 ) ;
F_6 ( & V_7 -> V_84 [ V_19 ] . V_2 , V_115 ,
V_185 |
V_186 ) ;
F_90 ( & V_7 -> V_84 [ V_19 ] . V_103 , F_43 ) ;
F_90 ( & V_7 -> V_84 [ V_19 ] . V_116 , F_48 ) ;
F_96 ( & V_235 , & V_7 -> V_84 [ V_19 ] . V_2 ) ;
F_18 ( & V_7 -> V_84 [ V_19 ] . V_2 , 0 ) ;
}
V_206 = F_97 ( V_8 , V_99 , F_41 ,
V_236 | V_105 , F_94 ( V_8 ) , V_7 ) ;
if ( ! V_206 )
return 0 ;
V_234:
for ( V_19 -- ; V_19 >= 0 ; V_19 -- ) {
F_98 ( & V_235 , & V_7 -> V_84 [ V_19 ] . V_2 ) ;
F_99 ( V_7 -> V_84 [ V_19 ] . V_2 . line , & V_22 ) ;
}
#ifdef F_93
if ( V_97 -> V_213 )
F_100 ( & V_7 -> V_198 ) ;
V_224:
#endif
F_101 ( V_7 -> V_209 ) ;
V_211:
if ( ! F_82 ( V_7 -> V_36 ) )
F_102 ( V_7 -> V_36 ) ;
return V_206 ;
}
static int F_103 ( struct V_26 * V_8 )
{
struct V_6 * V_7 = F_4 ( V_8 ) ;
int V_19 ;
#ifdef F_93
if ( V_7 -> V_97 -> V_213 )
F_100 ( & V_7 -> V_198 ) ;
#endif
for ( V_19 = 0 ; V_19 < V_7 -> V_97 -> V_98 ; V_19 ++ ) {
F_98 ( & V_235 , & V_7 -> V_84 [ V_19 ] . V_2 ) ;
F_99 ( V_7 -> V_84 [ V_19 ] . V_2 . line , & V_22 ) ;
F_18 ( & V_7 -> V_84 [ V_19 ] . V_2 , 0 ) ;
}
F_67 ( & V_7 -> V_101 ) ;
F_101 ( V_7 -> V_209 ) ;
if ( ! F_82 ( V_7 -> V_36 ) )
F_102 ( V_7 -> V_36 ) ;
return 0 ;
}
static int F_104 ( struct V_237 * V_238 )
{
const struct V_200 * V_97 ;
unsigned long V_105 = 0 ;
struct V_10 * V_10 ;
int V_206 ;
V_238 -> V_239 = 8 ;
V_238 -> V_240 = V_238 -> V_240 ? : V_241 ;
V_238 -> V_242 = V_238 -> V_242 ? : 15000000 ;
V_206 = F_105 ( V_238 ) ;
if ( V_206 )
return V_206 ;
if ( V_238 -> V_8 . V_243 ) {
const struct V_244 * V_245 =
F_106 ( V_246 , & V_238 -> V_8 ) ;
V_97 = (struct V_200 * ) V_245 -> V_247 ;
} else {
const struct V_248 * V_249 = F_107 ( V_238 ) ;
V_97 = (struct V_200 * ) V_249 -> V_250 ;
V_105 = V_251 ;
}
V_252 . V_253 = ( 0xf << V_11 ) |
( V_97 -> V_98 - 1 ) ;
V_10 = F_108 ( V_238 , & V_252 ) ;
return F_80 ( & V_238 -> V_8 , V_97 , V_10 , V_238 -> V_99 , V_105 ) ;
}
static int F_109 ( struct V_237 * V_238 )
{
return F_103 ( & V_238 -> V_8 ) ;
}
static int F_110 ( struct V_254 * V_255 ,
const struct V_256 * V_257 )
{
const struct V_200 * V_97 ;
unsigned long V_105 = 0 ;
struct V_10 * V_10 ;
if ( V_255 -> V_8 . V_243 ) {
const struct V_244 * V_245 =
F_106 ( V_246 , & V_255 -> V_8 ) ;
V_97 = (struct V_200 * ) V_245 -> V_247 ;
} else {
V_97 = (struct V_200 * ) V_257 -> V_250 ;
V_105 = V_251 ;
}
V_252 . V_253 = ( 0xf << V_11 ) |
( V_97 -> V_98 - 1 ) ;
V_10 = F_111 ( V_255 , & V_252 ) ;
return F_80 ( & V_255 -> V_8 , V_97 , V_10 , V_255 -> V_99 , V_105 ) ;
}
static int F_112 ( struct V_254 * V_258 )
{
return F_103 ( & V_258 -> V_8 ) ;
}
static int T_4 F_113 ( void )
{
int V_206 ;
V_206 = F_114 ( & V_235 ) ;
if ( V_206 ) {
F_115 ( L_6 ) ;
return V_206 ;
}
#ifdef F_116
V_206 = F_117 ( & V_259 ) ;
if ( V_206 < 0 ) {
F_115 ( L_7 , V_206 ) ;
return V_206 ;
}
#endif
#ifdef F_118
V_206 = F_119 ( & V_260 ) ;
if ( V_206 < 0 ) {
F_115 ( L_8 , V_206 ) ;
return V_206 ;
}
#endif
return V_206 ;
}
static void T_5 F_120 ( void )
{
#ifdef F_116
F_121 ( & V_259 ) ;
#endif
#ifdef F_118
F_122 ( & V_260 ) ;
#endif
F_123 ( & V_235 ) ;
}
