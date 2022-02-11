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
if ( F_12 ( ! V_16 ) )
return;
F_9 ( V_7 -> V_10 , true ) ;
F_13 ( V_7 -> V_10 , V_13 , V_7 -> V_15 , V_16 ) ;
F_9 ( V_7 -> V_10 , false ) ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_5 ,
T_1 V_18 , T_1 V_9 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
const T_1 line = F_1 ( V_2 ) ;
F_15 ( V_7 -> V_10 , ( V_5 << V_11 ) | line ,
V_18 , V_9 ) ;
}
static int F_16 ( void )
{
int V_19 ;
F_17 ( V_20 > V_21 ) ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ )
if ( ! F_18 ( V_19 , & V_22 ) )
break;
return V_19 ;
}
static void F_19 ( struct V_1 * V_2 , int V_23 )
{
F_14 ( V_2 , V_24 ,
V_25 ,
V_23 ? 0 : V_25 ) ;
}
static bool F_20 ( struct V_26 * V_8 , unsigned int V_5 )
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
static bool F_21 ( struct V_26 * V_8 , unsigned int V_5 )
{
switch ( V_5 >> V_11 ) {
case V_14 :
return true ;
default:
break;
}
return false ;
}
static int F_22 ( struct V_1 * V_2 , int V_33 )
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
F_14 ( V_2 , V_43 ,
V_38 ,
V_35 ) ;
F_6 ( V_2 , V_39 ,
V_44 ) ;
F_9 ( V_7 -> V_10 , true ) ;
F_6 ( V_2 , V_45 , div / 256 ) ;
F_6 ( V_2 , V_46 , div % 256 ) ;
F_9 ( V_7 -> V_10 , false ) ;
F_6 ( V_2 , V_39 , V_34 ) ;
return F_23 ( V_36 / 16 , div ) ;
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_12 ,
unsigned int V_47 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
unsigned int V_48 = 0 , V_49 , V_50 , V_51 , V_19 ;
bool V_52 = ( V_47 == V_53 ) ? true : false ;
if ( F_12 ( V_12 >= sizeof( V_7 -> V_15 ) ) ) {
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
if ( F_12 ( V_48 ) ) {
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
if ( F_12 ( V_2 -> V_78 ) ) {
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
if ( V_77 > V_80 ) {
F_35 ( V_2 -> V_8 ,
L_2 ,
V_77 , V_80 ) ;
V_77 = 0 ;
}
V_16 = ( V_16 > V_77 ) ? V_77 : V_16 ;
V_2 -> V_54 . V_79 += V_16 ;
for ( V_19 = 0 ; V_19 < V_16 ; ++ V_19 ) {
V_7 -> V_15 [ V_19 ] = V_76 -> V_15 [ V_76 -> V_81 ] ;
V_76 -> V_81 = ( V_76 -> V_81 + 1 ) & ( V_82 - 1 ) ;
}
F_11 ( V_2 , V_16 ) ;
}
if ( F_33 ( V_76 ) < V_83 )
F_36 ( V_2 ) ;
}
static void F_37 ( struct V_6 * V_7 , int V_84 )
{
struct V_1 * V_2 = & V_7 -> V_85 [ V_84 ] . V_2 ;
do {
unsigned int V_47 , V_86 , V_12 ;
V_47 = F_3 ( V_2 , V_27 ) ;
if ( V_47 & V_87 )
break;
V_47 &= V_88 ;
switch ( V_47 ) {
case V_89 :
case V_53 :
case V_90 :
case V_91 :
V_12 = F_3 ( V_2 , V_31 ) ;
if ( V_12 )
F_24 ( V_2 , V_12 , V_47 ) ;
break;
case V_92 :
V_86 = F_3 ( V_2 , V_29 ) ;
F_38 ( V_2 ,
! ! ( V_86 & V_93 ) ) ;
break;
case V_94 :
F_30 ( V_2 ) ;
break;
default:
F_35 ( V_2 -> V_8 ,
L_3 ,
V_2 -> line , V_47 ) ;
break;
}
} while ( 1 );
}
static void F_39 ( struct V_95 * V_96 )
{
struct V_6 * V_7 = F_40 ( V_96 , V_97 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_7 -> V_98 -> V_99 ; ++ V_19 )
F_37 ( V_7 , V_19 ) ;
}
static T_2 F_41 ( int V_100 , void * V_101 )
{
struct V_6 * V_7 = (struct V_6 * ) V_101 ;
F_42 ( & V_7 -> V_102 , & V_7 -> V_97 ) ;
return V_103 ;
}
static void F_43 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = & ( F_2 ( V_96 , V_104 ) -> V_2 ) ;
if ( ( V_2 -> V_105 . V_106 & V_107 ) &&
( V_2 -> V_105 . V_108 > 0 ) )
F_44 ( V_2 -> V_105 . V_108 ) ;
F_30 ( V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
const T_3 V_18 = V_109 |
V_110 ;
T_3 V_111 = 0 ;
struct V_112 * V_105 = & V_2 -> V_105 ;
unsigned long V_113 ;
F_46 ( & V_2 -> V_114 , V_113 ) ;
if ( V_105 -> V_106 & V_107 ) {
V_111 |= V_109 ;
if ( V_105 -> V_106 & V_115 )
V_111 |= V_110 ;
}
F_47 ( & V_2 -> V_114 , V_113 ) ;
F_14 ( V_2 , V_116 , V_18 , V_111 ) ;
}
static void F_48 ( struct V_95 * V_96 )
{
struct V_3 * V_4 = F_2 ( V_96 , V_117 ) ;
struct V_118 V_119 ;
unsigned long V_113 ;
F_46 ( & V_4 -> V_2 . V_114 , V_113 ) ;
V_119 = V_4 -> V_119 ;
memset ( & V_4 -> V_119 , 0 , sizeof( V_4 -> V_119 ) ) ;
F_47 ( & V_4 -> V_2 . V_114 , V_113 ) ;
if ( V_119 . V_106 & V_120 ) {
F_14 ( & V_4 -> V_2 , V_43 ,
V_121 ,
( V_4 -> V_2 . V_122 & V_123 ) ?
V_121 : 0 ) ;
F_14 ( & V_4 -> V_2 , V_43 ,
V_124 ,
( V_4 -> V_2 . V_122 & V_125 ) ?
V_124 : 0 ) ;
F_14 ( & V_4 -> V_2 , V_43 ,
V_126 ,
( V_4 -> V_2 . V_122 & V_127 ) ?
V_126 : 0 ) ;
}
if ( V_119 . V_106 & V_128 )
F_14 ( & V_4 -> V_2 , V_24 ,
V_119 . V_129 , 0 ) ;
if ( V_119 . V_106 & V_130 )
F_45 ( & V_4 -> V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 , T_1 V_131 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
struct V_3 * V_4 = F_2 ( V_2 , V_2 ) ;
V_4 -> V_119 . V_106 |= V_128 ;
V_4 -> V_119 . V_129 |= V_131 ;
F_42 ( & V_7 -> V_102 , & V_4 -> V_117 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_49 ( V_2 , V_132 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_49 ( V_2 , V_133 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
struct V_3 * V_4 = F_2 ( V_2 , V_2 ) ;
F_42 ( & V_7 -> V_102 , & V_4 -> V_104 ) ;
}
static unsigned int F_53 ( struct V_1 * V_2 )
{
unsigned int V_48 ;
V_48 = F_3 ( V_2 , V_28 ) ;
return ( V_48 & V_134 ) ? V_135 : 0 ;
}
static unsigned int F_54 ( struct V_1 * V_2 )
{
return V_136 | V_137 ;
}
static void F_55 ( struct V_1 * V_2 , unsigned int V_122 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
struct V_3 * V_4 = F_2 ( V_2 , V_2 ) ;
V_4 -> V_119 . V_106 |= V_120 ;
F_42 ( & V_7 -> V_102 , & V_4 -> V_117 ) ;
}
static void F_56 ( struct V_1 * V_2 , int V_138 )
{
F_14 ( V_2 , V_39 ,
V_139 ,
V_138 ? V_139 : 0 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_140 * V_141 ,
struct V_140 * V_142 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
unsigned int V_34 , V_143 = 0 ;
int V_33 ;
V_141 -> V_144 &= ~ V_145 ;
switch ( V_141 -> V_144 & V_146 ) {
case V_147 :
V_34 = V_148 ;
break;
case V_149 :
V_34 = V_150 ;
break;
case V_151 :
V_34 = V_152 ;
break;
case V_153 :
V_34 = V_154 ;
break;
default:
V_34 = V_154 ;
V_141 -> V_144 &= ~ V_146 ;
V_141 -> V_144 |= V_153 ;
break;
}
if ( V_141 -> V_144 & V_155 ) {
V_34 |= V_156 ;
if ( ! ( V_141 -> V_144 & V_157 ) )
V_34 |= V_158 ;
}
if ( V_141 -> V_144 & V_159 )
V_34 |= V_160 ;
V_2 -> V_68 = V_66 ;
if ( V_141 -> V_161 & V_162 )
V_2 -> V_68 |= V_62 |
V_64 ;
if ( V_141 -> V_161 & ( V_163 | V_164 ) )
V_2 -> V_68 |= V_60 ;
V_2 -> V_73 = 0 ;
if ( V_141 -> V_161 & V_165 )
V_2 -> V_73 |= V_60 ;
if ( ! ( V_141 -> V_144 & V_166 ) )
V_2 -> V_73 |= V_57 ;
F_6 ( V_2 , V_39 ,
V_40 ) ;
F_9 ( V_7 -> V_10 , true ) ;
F_6 ( V_2 , V_167 , V_141 -> V_168 [ V_169 ] ) ;
F_6 ( V_2 , V_170 , V_141 -> V_168 [ V_171 ] ) ;
if ( V_141 -> V_144 & V_172 )
V_143 |= V_173 |
V_174 ;
if ( V_141 -> V_161 & V_175 )
V_143 |= V_176 ;
if ( V_141 -> V_161 & V_177 )
V_143 |= V_178 ;
F_6 ( V_2 , V_41 , V_143 ) ;
F_9 ( V_7 -> V_10 , false ) ;
F_6 ( V_2 , V_39 , V_34 ) ;
V_33 = F_58 ( V_2 , V_141 , V_142 ,
V_2 -> V_37 / 16 / 4 / 0xffff ,
V_2 -> V_37 / 16 ) ;
V_33 = F_22 ( V_2 , V_33 ) ;
F_59 ( V_2 , V_141 -> V_144 , V_33 ) ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_112 * V_105 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
struct V_3 * V_4 = F_2 ( V_2 , V_2 ) ;
if ( V_105 -> V_106 & V_107 ) {
bool V_179 , V_180 ;
V_179 = V_105 -> V_106 & V_115 ;
V_180 = V_105 -> V_106 & V_181 ;
if ( V_179 == V_180 )
F_61 ( V_2 -> V_8 ,
L_4 ,
V_180 , V_179 ) ;
if ( V_105 -> V_182 )
return - V_183 ;
}
V_2 -> V_105 = * V_105 ;
V_4 -> V_119 . V_106 |= V_130 ;
F_42 ( & V_7 -> V_102 , & V_4 -> V_117 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
unsigned int V_9 ;
F_19 ( V_2 , 1 ) ;
V_9 = V_184 | V_185 ;
F_6 ( V_2 , V_186 , V_9 ) ;
F_63 ( 5 ) ;
F_6 ( V_2 , V_186 ,
V_187 ) ;
F_6 ( V_2 , V_39 ,
V_40 ) ;
F_9 ( V_7 -> V_10 , true ) ;
F_6 ( V_2 , V_41 ,
V_42 ) ;
F_14 ( V_2 , V_43 ,
V_188 ,
V_188 ) ;
F_6 ( V_2 , V_189 ,
F_64 ( 24 ) |
F_65 ( 48 ) ) ;
F_9 ( V_7 -> V_10 , false ) ;
F_6 ( V_2 , V_39 , V_154 ) ;
F_14 ( V_2 , V_116 ,
V_190 |
V_191 ,
0 ) ;
V_9 = V_133 | V_132 |
V_192 ;
F_6 ( V_2 , V_24 , V_9 ) ;
return 0 ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
F_6 ( V_2 , V_24 , 0 ) ;
F_14 ( V_2 , V_116 ,
V_190 |
V_191 ,
V_190 |
V_191 ) ;
F_19 ( V_2 , 0 ) ;
F_67 ( & V_7 -> V_102 ) ;
}
static const char * F_68 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
return ( V_2 -> type == V_193 ) ? V_7 -> V_98 -> V_194 : NULL ;
}
static int F_69 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_70 ( struct V_1 * V_2 , int V_106 )
{
if ( V_106 & V_195 )
V_2 -> type = V_193 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_196 * V_7 )
{
if ( ( V_7 -> type != V_197 ) && ( V_7 -> type != V_193 ) )
return - V_183 ;
if ( V_7 -> V_100 != V_2 -> V_100 )
return - V_183 ;
return 0 ;
}
static void F_72 ( struct V_1 * V_2 , unsigned int V_74 ,
unsigned int V_198 )
{
F_19 ( V_2 , ( V_74 == V_199 ) ? 1 : 0 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
}
static int F_74 ( struct V_200 * V_201 , unsigned V_202 )
{
unsigned int V_9 ;
struct V_6 * V_7 = F_75 ( V_201 , struct V_6 ,
V_203 ) ;
struct V_1 * V_2 = & V_7 -> V_85 [ 0 ] . V_2 ;
V_9 = F_3 ( V_2 , V_32 ) ;
return ! ! ( V_9 & F_76 ( V_202 ) ) ;
}
static void F_77 ( struct V_200 * V_201 , unsigned V_202 , int V_9 )
{
struct V_6 * V_7 = F_75 ( V_201 , struct V_6 ,
V_203 ) ;
struct V_1 * V_2 = & V_7 -> V_85 [ 0 ] . V_2 ;
F_14 ( V_2 , V_32 , F_76 ( V_202 ) ,
V_9 ? F_76 ( V_202 ) : 0 ) ;
}
static int F_78 ( struct V_200 * V_201 ,
unsigned V_202 )
{
struct V_6 * V_7 = F_75 ( V_201 , struct V_6 ,
V_203 ) ;
struct V_1 * V_2 = & V_7 -> V_85 [ 0 ] . V_2 ;
F_14 ( V_2 , V_204 , F_76 ( V_202 ) , 0 ) ;
return 0 ;
}
static int F_79 ( struct V_200 * V_201 ,
unsigned V_202 , int V_9 )
{
struct V_6 * V_7 = F_75 ( V_201 , struct V_6 ,
V_203 ) ;
struct V_1 * V_2 = & V_7 -> V_85 [ 0 ] . V_2 ;
F_14 ( V_2 , V_32 , F_76 ( V_202 ) ,
V_9 ? F_76 ( V_202 ) : 0 ) ;
F_14 ( V_2 , V_204 , F_76 ( V_202 ) ,
F_76 ( V_202 ) ) ;
return 0 ;
}
static int F_80 ( struct V_26 * V_8 ,
const struct V_205 * V_98 ,
struct V_10 * V_10 , int V_100 , unsigned long V_106 )
{
struct V_206 V_206 = { . V_207 = V_208 / 2 } ;
unsigned long V_209 , * V_210 = F_81 ( V_8 ) ;
int V_19 , V_211 ;
struct V_6 * V_7 ;
if ( F_82 ( V_10 ) )
return F_83 ( V_10 ) ;
V_7 = F_84 ( V_8 , sizeof( * V_7 ) +
sizeof( struct V_3 ) * V_98 -> V_99 ,
V_212 ) ;
if ( ! V_7 ) {
F_61 ( V_8 , L_5 ) ;
return - V_213 ;
}
V_7 -> V_36 = F_85 ( V_8 , NULL ) ;
if ( F_82 ( V_7 -> V_36 ) ) {
if ( V_210 )
V_209 = * V_210 ;
else
return F_83 ( V_7 -> V_36 ) ;
} else {
F_86 ( V_7 -> V_36 ) ;
V_209 = F_87 ( V_7 -> V_36 ) ;
}
V_7 -> V_10 = V_10 ;
V_7 -> V_98 = V_98 ;
F_88 ( V_8 , V_7 ) ;
F_89 ( & V_7 -> V_102 ) ;
F_90 ( & V_7 -> V_97 , F_39 ) ;
V_7 -> V_214 = F_91 ( V_215 , & V_7 -> V_102 ,
L_6 ) ;
if ( F_82 ( V_7 -> V_214 ) ) {
V_211 = F_83 ( V_7 -> V_214 ) ;
goto V_216;
}
F_92 ( V_7 -> V_214 , V_217 , & V_206 ) ;
#ifdef F_93
if ( V_98 -> V_218 ) {
V_7 -> V_203 . V_219 = V_220 ;
V_7 -> V_203 . V_221 = V_8 ;
V_7 -> V_203 . V_222 = F_94 ( V_8 ) ;
V_7 -> V_203 . V_223 = F_78 ;
V_7 -> V_203 . V_224 = F_74 ;
V_7 -> V_203 . V_225 = F_79 ;
V_7 -> V_203 . V_226 = F_77 ;
V_7 -> V_203 . V_227 = - 1 ;
V_7 -> V_203 . V_228 = V_98 -> V_218 ;
V_7 -> V_203 . V_229 = 1 ;
V_211 = F_95 ( & V_7 -> V_203 ) ;
if ( V_211 )
goto V_230;
}
#endif
for ( V_19 = 0 ; V_19 < V_98 -> V_99 ; ++ V_19 ) {
V_7 -> V_85 [ V_19 ] . line = V_19 ;
V_7 -> V_85 [ V_19 ] . V_2 . V_8 = V_8 ;
V_7 -> V_85 [ V_19 ] . V_2 . V_100 = V_100 ;
V_7 -> V_85 [ V_19 ] . V_2 . type = V_193 ;
V_7 -> V_85 [ V_19 ] . V_2 . V_231 = V_80 ;
V_7 -> V_85 [ V_19 ] . V_2 . V_106 = V_232 | V_233 ;
V_7 -> V_85 [ V_19 ] . V_2 . V_234 = V_235 ;
V_7 -> V_85 [ V_19 ] . V_2 . V_37 = V_209 ;
V_7 -> V_85 [ V_19 ] . V_2 . V_236 = F_60 ;
V_7 -> V_85 [ V_19 ] . V_2 . V_237 = & V_238 ;
V_7 -> V_85 [ V_19 ] . V_2 . line = F_16 () ;
if ( V_7 -> V_85 [ V_19 ] . V_2 . line >= V_20 ) {
V_211 = - V_213 ;
goto V_239;
}
F_6 ( & V_7 -> V_85 [ V_19 ] . V_2 , V_24 , 0 ) ;
F_6 ( & V_7 -> V_85 [ V_19 ] . V_2 , V_116 ,
V_190 |
V_191 ) ;
F_90 ( & V_7 -> V_85 [ V_19 ] . V_104 , F_43 ) ;
F_90 ( & V_7 -> V_85 [ V_19 ] . V_117 , F_48 ) ;
F_96 ( & V_240 , & V_7 -> V_85 [ V_19 ] . V_2 ) ;
F_19 ( & V_7 -> V_85 [ V_19 ] . V_2 , 0 ) ;
}
V_211 = F_97 ( V_8 , V_100 , F_41 ,
V_241 | V_106 , F_94 ( V_8 ) , V_7 ) ;
if ( ! V_211 )
return 0 ;
V_239:
for ( V_19 -- ; V_19 >= 0 ; V_19 -- ) {
F_98 ( & V_240 , & V_7 -> V_85 [ V_19 ] . V_2 ) ;
F_99 ( V_7 -> V_85 [ V_19 ] . V_2 . line , & V_22 ) ;
}
#ifdef F_93
if ( V_98 -> V_218 )
F_100 ( & V_7 -> V_203 ) ;
V_230:
#endif
F_101 ( V_7 -> V_214 ) ;
V_216:
if ( ! F_82 ( V_7 -> V_36 ) )
F_102 ( V_7 -> V_36 ) ;
return V_211 ;
}
static int F_103 ( struct V_26 * V_8 )
{
struct V_6 * V_7 = F_4 ( V_8 ) ;
int V_19 ;
#ifdef F_93
if ( V_7 -> V_98 -> V_218 )
F_100 ( & V_7 -> V_203 ) ;
#endif
for ( V_19 = 0 ; V_19 < V_7 -> V_98 -> V_99 ; V_19 ++ ) {
F_98 ( & V_240 , & V_7 -> V_85 [ V_19 ] . V_2 ) ;
F_99 ( V_7 -> V_85 [ V_19 ] . V_2 . line , & V_22 ) ;
F_19 ( & V_7 -> V_85 [ V_19 ] . V_2 , 0 ) ;
}
F_67 ( & V_7 -> V_102 ) ;
F_101 ( V_7 -> V_214 ) ;
if ( ! F_82 ( V_7 -> V_36 ) )
F_102 ( V_7 -> V_36 ) ;
return 0 ;
}
static int F_104 ( struct V_242 * V_243 )
{
const struct V_205 * V_98 ;
unsigned long V_106 = 0 ;
struct V_10 * V_10 ;
int V_211 ;
V_243 -> V_244 = 8 ;
V_243 -> V_245 = V_243 -> V_245 ? : V_246 ;
V_243 -> V_247 = V_243 -> V_247 ? : 15000000 ;
V_211 = F_105 ( V_243 ) ;
if ( V_211 )
return V_211 ;
if ( V_243 -> V_8 . V_248 ) {
const struct V_249 * V_250 =
F_106 ( V_251 , & V_243 -> V_8 ) ;
if ( ! V_250 )
return - V_252 ;
V_98 = (struct V_205 * ) V_250 -> V_253 ;
} else {
const struct V_254 * V_255 = F_107 ( V_243 ) ;
V_98 = (struct V_205 * ) V_255 -> V_256 ;
V_106 = V_257 ;
}
V_258 . V_259 = ( 0xf << V_11 ) |
( V_98 -> V_99 - 1 ) ;
V_10 = F_108 ( V_243 , & V_258 ) ;
return F_80 ( & V_243 -> V_8 , V_98 , V_10 , V_243 -> V_100 , V_106 ) ;
}
static int F_109 ( struct V_242 * V_243 )
{
return F_103 ( & V_243 -> V_8 ) ;
}
static int F_110 ( struct V_260 * V_261 ,
const struct V_262 * V_263 )
{
const struct V_205 * V_98 ;
unsigned long V_106 = 0 ;
struct V_10 * V_10 ;
if ( V_261 -> V_8 . V_248 ) {
const struct V_249 * V_250 =
F_106 ( V_251 , & V_261 -> V_8 ) ;
if ( ! V_250 )
return - V_252 ;
V_98 = (struct V_205 * ) V_250 -> V_253 ;
} else {
V_98 = (struct V_205 * ) V_263 -> V_256 ;
V_106 = V_257 ;
}
V_258 . V_259 = ( 0xf << V_11 ) |
( V_98 -> V_99 - 1 ) ;
V_10 = F_111 ( V_261 , & V_258 ) ;
return F_80 ( & V_261 -> V_8 , V_98 , V_10 , V_261 -> V_100 , V_106 ) ;
}
static int F_112 ( struct V_260 * V_264 )
{
return F_103 ( & V_264 -> V_8 ) ;
}
static int T_4 F_113 ( void )
{
int V_211 ;
V_211 = F_114 ( & V_240 ) ;
if ( V_211 ) {
F_115 ( L_7 ) ;
return V_211 ;
}
#ifdef F_116
V_211 = F_117 ( & V_265 ) ;
if ( V_211 < 0 ) {
F_115 ( L_8 , V_211 ) ;
return V_211 ;
}
#endif
#ifdef F_118
V_211 = F_119 ( & V_266 ) ;
if ( V_211 < 0 ) {
F_115 ( L_9 , V_211 ) ;
return V_211 ;
}
#endif
return V_211 ;
}
static void T_5 F_120 ( void )
{
#ifdef F_116
F_121 ( & V_265 ) ;
#endif
#ifdef F_118
F_122 ( & V_266 ) ;
#endif
F_123 ( & V_240 ) ;
}
