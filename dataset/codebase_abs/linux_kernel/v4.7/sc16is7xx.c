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
unsigned int V_47 , V_12 ;
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
F_24 ( V_2 , V_12 , V_47 ) ;
break;
case V_91 :
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
static void F_38 ( struct V_92 * V_93 )
{
struct V_6 * V_7 = F_39 ( V_93 , V_94 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_7 -> V_95 -> V_96 ; ++ V_19 )
F_37 ( V_7 , V_19 ) ;
}
static T_2 F_40 ( int V_97 , void * V_98 )
{
struct V_6 * V_7 = (struct V_6 * ) V_98 ;
F_41 ( & V_7 -> V_99 , & V_7 -> V_94 ) ;
return V_100 ;
}
static void F_42 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = & ( F_2 ( V_93 , V_101 ) -> V_2 ) ;
if ( ( V_2 -> V_102 . V_103 & V_104 ) &&
( V_2 -> V_102 . V_105 > 0 ) )
F_43 ( V_2 -> V_102 . V_105 ) ;
F_30 ( V_2 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
const T_3 V_18 = V_106 |
V_107 ;
T_3 V_108 = 0 ;
struct V_109 * V_102 = & V_2 -> V_102 ;
unsigned long V_110 ;
F_45 ( & V_2 -> V_111 , V_110 ) ;
if ( V_102 -> V_103 & V_104 ) {
V_108 |= V_106 ;
if ( V_102 -> V_103 & V_112 )
V_108 |= V_107 ;
}
F_46 ( & V_2 -> V_111 , V_110 ) ;
F_14 ( V_2 , V_113 , V_18 , V_108 ) ;
}
static void F_47 ( struct V_92 * V_93 )
{
struct V_3 * V_4 = F_2 ( V_93 , V_114 ) ;
struct V_115 V_116 ;
unsigned long V_110 ;
F_45 ( & V_4 -> V_2 . V_111 , V_110 ) ;
V_116 = V_4 -> V_116 ;
memset ( & V_4 -> V_116 , 0 , sizeof( V_4 -> V_116 ) ) ;
F_46 ( & V_4 -> V_2 . V_111 , V_110 ) ;
if ( V_116 . V_103 & V_117 ) {
F_14 ( & V_4 -> V_2 , V_43 ,
V_118 ,
( V_4 -> V_2 . V_119 & V_120 ) ?
V_118 : 0 ) ;
F_14 ( & V_4 -> V_2 , V_43 ,
V_121 ,
( V_4 -> V_2 . V_119 & V_122 ) ?
V_121 : 0 ) ;
F_14 ( & V_4 -> V_2 , V_43 ,
V_123 ,
( V_4 -> V_2 . V_119 & V_124 ) ?
V_123 : 0 ) ;
}
if ( V_116 . V_103 & V_125 )
F_14 ( & V_4 -> V_2 , V_24 ,
V_116 . V_126 , 0 ) ;
if ( V_116 . V_103 & V_127 )
F_44 ( & V_4 -> V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 , T_1 V_128 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
struct V_3 * V_4 = F_2 ( V_2 , V_2 ) ;
V_4 -> V_116 . V_103 |= V_125 ;
V_4 -> V_116 . V_126 |= V_128 ;
F_41 ( & V_7 -> V_99 , & V_4 -> V_114 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_48 ( V_2 , V_129 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_48 ( V_2 , V_130 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
struct V_3 * V_4 = F_2 ( V_2 , V_2 ) ;
F_41 ( & V_7 -> V_99 , & V_4 -> V_101 ) ;
}
static unsigned int F_52 ( struct V_1 * V_2 )
{
unsigned int V_48 ;
V_48 = F_3 ( V_2 , V_28 ) ;
return ( V_48 & V_131 ) ? V_132 : 0 ;
}
static unsigned int F_53 ( struct V_1 * V_2 )
{
return V_133 | V_134 ;
}
static void F_54 ( struct V_1 * V_2 , unsigned int V_119 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
struct V_3 * V_4 = F_2 ( V_2 , V_2 ) ;
V_4 -> V_116 . V_103 |= V_117 ;
F_41 ( & V_7 -> V_99 , & V_4 -> V_114 ) ;
}
static void F_55 ( struct V_1 * V_2 , int V_135 )
{
F_14 ( V_2 , V_39 ,
V_136 ,
V_135 ? V_136 : 0 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_137 * V_138 ,
struct V_137 * V_139 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
unsigned int V_34 , V_140 = 0 ;
int V_33 ;
V_138 -> V_141 &= ~ V_142 ;
switch ( V_138 -> V_141 & V_143 ) {
case V_144 :
V_34 = V_145 ;
break;
case V_146 :
V_34 = V_147 ;
break;
case V_148 :
V_34 = V_149 ;
break;
case V_150 :
V_34 = V_151 ;
break;
default:
V_34 = V_151 ;
V_138 -> V_141 &= ~ V_143 ;
V_138 -> V_141 |= V_150 ;
break;
}
if ( V_138 -> V_141 & V_152 ) {
V_34 |= V_153 ;
if ( ! ( V_138 -> V_141 & V_154 ) )
V_34 |= V_155 ;
}
if ( V_138 -> V_141 & V_156 )
V_34 |= V_157 ;
V_2 -> V_68 = V_66 ;
if ( V_138 -> V_158 & V_159 )
V_2 -> V_68 |= V_62 |
V_64 ;
if ( V_138 -> V_158 & ( V_160 | V_161 ) )
V_2 -> V_68 |= V_60 ;
V_2 -> V_73 = 0 ;
if ( V_138 -> V_158 & V_162 )
V_2 -> V_73 |= V_60 ;
if ( ! ( V_138 -> V_141 & V_163 ) )
V_2 -> V_73 |= V_57 ;
F_6 ( V_2 , V_39 ,
V_40 ) ;
F_9 ( V_7 -> V_10 , true ) ;
F_6 ( V_2 , V_164 , V_138 -> V_165 [ V_166 ] ) ;
F_6 ( V_2 , V_167 , V_138 -> V_165 [ V_168 ] ) ;
if ( V_138 -> V_141 & V_169 )
V_140 |= V_170 |
V_171 ;
if ( V_138 -> V_158 & V_172 )
V_140 |= V_173 ;
if ( V_138 -> V_158 & V_174 )
V_140 |= V_175 ;
F_6 ( V_2 , V_41 , V_140 ) ;
F_9 ( V_7 -> V_10 , false ) ;
F_6 ( V_2 , V_39 , V_34 ) ;
V_33 = F_57 ( V_2 , V_138 , V_139 ,
V_2 -> V_37 / 16 / 4 / 0xffff ,
V_2 -> V_37 / 16 ) ;
V_33 = F_22 ( V_2 , V_33 ) ;
F_58 ( V_2 , V_138 -> V_141 , V_33 ) ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_109 * V_102 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
struct V_3 * V_4 = F_2 ( V_2 , V_2 ) ;
if ( V_102 -> V_103 & V_104 ) {
bool V_176 , V_177 ;
V_176 = V_102 -> V_103 & V_112 ;
V_177 = V_102 -> V_103 & V_178 ;
if ( V_176 == V_177 )
F_60 ( V_2 -> V_8 ,
L_4 ,
V_177 , V_176 ) ;
if ( V_102 -> V_179 )
return - V_180 ;
}
V_2 -> V_102 = * V_102 ;
V_4 -> V_116 . V_103 |= V_127 ;
F_41 ( & V_7 -> V_99 , & V_4 -> V_114 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
unsigned int V_9 ;
F_19 ( V_2 , 1 ) ;
V_9 = V_181 | V_182 ;
F_6 ( V_2 , V_183 , V_9 ) ;
F_62 ( 5 ) ;
F_6 ( V_2 , V_183 ,
V_184 ) ;
F_6 ( V_2 , V_39 ,
V_40 ) ;
F_9 ( V_7 -> V_10 , true ) ;
F_6 ( V_2 , V_41 ,
V_42 ) ;
F_14 ( V_2 , V_43 ,
V_185 ,
V_185 ) ;
F_6 ( V_2 , V_186 ,
F_63 ( 24 ) |
F_64 ( 48 ) ) ;
F_9 ( V_7 -> V_10 , false ) ;
F_6 ( V_2 , V_39 , V_151 ) ;
F_14 ( V_2 , V_113 ,
V_187 |
V_188 ,
0 ) ;
V_9 = V_130 | V_129 ;
F_6 ( V_2 , V_24 , V_9 ) ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
F_6 ( V_2 , V_24 , 0 ) ;
F_14 ( V_2 , V_113 ,
V_187 |
V_188 ,
V_187 |
V_188 ) ;
F_19 ( V_2 , 0 ) ;
F_66 ( & V_7 -> V_99 ) ;
}
static const char * F_67 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 -> V_8 ) ;
return ( V_2 -> type == V_189 ) ? V_7 -> V_95 -> V_190 : NULL ;
}
static int F_68 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_69 ( struct V_1 * V_2 , int V_103 )
{
if ( V_103 & V_191 )
V_2 -> type = V_189 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_192 * V_7 )
{
if ( ( V_7 -> type != V_193 ) && ( V_7 -> type != V_189 ) )
return - V_180 ;
if ( V_7 -> V_97 != V_2 -> V_97 )
return - V_180 ;
return 0 ;
}
static void F_71 ( struct V_1 * V_2 , unsigned int V_74 ,
unsigned int V_194 )
{
F_19 ( V_2 , ( V_74 == V_195 ) ? 1 : 0 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
}
static int F_73 ( struct V_196 * V_197 , unsigned V_198 )
{
unsigned int V_9 ;
struct V_6 * V_7 = F_74 ( V_197 ) ;
struct V_1 * V_2 = & V_7 -> V_85 [ 0 ] . V_2 ;
V_9 = F_3 ( V_2 , V_32 ) ;
return ! ! ( V_9 & F_75 ( V_198 ) ) ;
}
static void F_76 ( struct V_196 * V_197 , unsigned V_198 , int V_9 )
{
struct V_6 * V_7 = F_74 ( V_197 ) ;
struct V_1 * V_2 = & V_7 -> V_85 [ 0 ] . V_2 ;
F_14 ( V_2 , V_32 , F_75 ( V_198 ) ,
V_9 ? F_75 ( V_198 ) : 0 ) ;
}
static int F_77 ( struct V_196 * V_197 ,
unsigned V_198 )
{
struct V_6 * V_7 = F_74 ( V_197 ) ;
struct V_1 * V_2 = & V_7 -> V_85 [ 0 ] . V_2 ;
F_14 ( V_2 , V_199 , F_75 ( V_198 ) , 0 ) ;
return 0 ;
}
static int F_78 ( struct V_196 * V_197 ,
unsigned V_198 , int V_9 )
{
struct V_6 * V_7 = F_74 ( V_197 ) ;
struct V_1 * V_2 = & V_7 -> V_85 [ 0 ] . V_2 ;
F_14 ( V_2 , V_32 , F_75 ( V_198 ) ,
V_9 ? F_75 ( V_198 ) : 0 ) ;
F_14 ( V_2 , V_199 , F_75 ( V_198 ) ,
F_75 ( V_198 ) ) ;
return 0 ;
}
static int F_79 ( struct V_26 * V_8 ,
const struct V_200 * V_95 ,
struct V_10 * V_10 , int V_97 , unsigned long V_103 )
{
struct V_201 V_201 = { . V_202 = V_203 / 2 } ;
unsigned long V_204 , * V_205 = F_80 ( V_8 ) ;
int V_19 , V_206 ;
struct V_6 * V_7 ;
if ( F_81 ( V_10 ) )
return F_82 ( V_10 ) ;
V_7 = F_83 ( V_8 , sizeof( * V_7 ) +
sizeof( struct V_3 ) * V_95 -> V_96 ,
V_207 ) ;
if ( ! V_7 ) {
F_60 ( V_8 , L_5 ) ;
return - V_208 ;
}
V_7 -> V_36 = F_84 ( V_8 , NULL ) ;
if ( F_81 ( V_7 -> V_36 ) ) {
if ( V_205 )
V_204 = * V_205 ;
else
return F_82 ( V_7 -> V_36 ) ;
} else {
F_85 ( V_7 -> V_36 ) ;
V_204 = F_86 ( V_7 -> V_36 ) ;
}
V_7 -> V_10 = V_10 ;
V_7 -> V_95 = V_95 ;
F_87 ( V_8 , V_7 ) ;
F_88 ( & V_7 -> V_99 ) ;
F_89 ( & V_7 -> V_94 , F_38 ) ;
V_7 -> V_209 = F_90 ( V_210 , & V_7 -> V_99 ,
L_6 ) ;
if ( F_81 ( V_7 -> V_209 ) ) {
V_206 = F_82 ( V_7 -> V_209 ) ;
goto V_211;
}
F_91 ( V_7 -> V_209 , V_212 , & V_201 ) ;
#ifdef F_92
if ( V_95 -> V_213 ) {
V_7 -> V_214 . V_215 = V_216 ;
V_7 -> V_214 . V_217 = V_8 ;
V_7 -> V_214 . V_218 = F_93 ( V_8 ) ;
V_7 -> V_214 . V_219 = F_77 ;
V_7 -> V_214 . V_220 = F_73 ;
V_7 -> V_214 . V_221 = F_78 ;
V_7 -> V_214 . V_222 = F_76 ;
V_7 -> V_214 . V_223 = - 1 ;
V_7 -> V_214 . V_224 = V_95 -> V_213 ;
V_7 -> V_214 . V_225 = 1 ;
V_206 = F_94 ( & V_7 -> V_214 , V_7 ) ;
if ( V_206 )
goto V_226;
}
#endif
for ( V_19 = 0 ; V_19 < V_95 -> V_96 ; ++ V_19 ) {
V_7 -> V_85 [ V_19 ] . line = V_19 ;
V_7 -> V_85 [ V_19 ] . V_2 . V_8 = V_8 ;
V_7 -> V_85 [ V_19 ] . V_2 . V_97 = V_97 ;
V_7 -> V_85 [ V_19 ] . V_2 . type = V_189 ;
V_7 -> V_85 [ V_19 ] . V_2 . V_227 = V_80 ;
V_7 -> V_85 [ V_19 ] . V_2 . V_103 = V_228 | V_229 ;
V_7 -> V_85 [ V_19 ] . V_2 . V_230 = V_231 ;
V_7 -> V_85 [ V_19 ] . V_2 . V_37 = V_204 ;
V_7 -> V_85 [ V_19 ] . V_2 . V_232 = F_59 ;
V_7 -> V_85 [ V_19 ] . V_2 . V_233 = & V_234 ;
V_7 -> V_85 [ V_19 ] . V_2 . line = F_16 () ;
if ( V_7 -> V_85 [ V_19 ] . V_2 . line >= V_20 ) {
V_206 = - V_208 ;
goto V_235;
}
F_6 ( & V_7 -> V_85 [ V_19 ] . V_2 , V_24 , 0 ) ;
F_6 ( & V_7 -> V_85 [ V_19 ] . V_2 , V_113 ,
V_187 |
V_188 ) ;
F_89 ( & V_7 -> V_85 [ V_19 ] . V_101 , F_42 ) ;
F_89 ( & V_7 -> V_85 [ V_19 ] . V_114 , F_47 ) ;
F_95 ( & V_236 , & V_7 -> V_85 [ V_19 ] . V_2 ) ;
F_19 ( & V_7 -> V_85 [ V_19 ] . V_2 , 0 ) ;
}
V_206 = F_96 ( V_8 , V_97 , F_40 ,
V_237 | V_103 , F_93 ( V_8 ) , V_7 ) ;
if ( ! V_206 )
return 0 ;
V_235:
for ( V_19 -- ; V_19 >= 0 ; V_19 -- ) {
F_97 ( & V_236 , & V_7 -> V_85 [ V_19 ] . V_2 ) ;
F_98 ( V_7 -> V_85 [ V_19 ] . V_2 . line , & V_22 ) ;
}
#ifdef F_92
if ( V_95 -> V_213 )
F_99 ( & V_7 -> V_214 ) ;
V_226:
#endif
F_100 ( V_7 -> V_209 ) ;
V_211:
if ( ! F_81 ( V_7 -> V_36 ) )
F_101 ( V_7 -> V_36 ) ;
return V_206 ;
}
static int F_102 ( struct V_26 * V_8 )
{
struct V_6 * V_7 = F_4 ( V_8 ) ;
int V_19 ;
#ifdef F_92
if ( V_7 -> V_95 -> V_213 )
F_99 ( & V_7 -> V_214 ) ;
#endif
for ( V_19 = 0 ; V_19 < V_7 -> V_95 -> V_96 ; V_19 ++ ) {
F_97 ( & V_236 , & V_7 -> V_85 [ V_19 ] . V_2 ) ;
F_98 ( V_7 -> V_85 [ V_19 ] . V_2 . line , & V_22 ) ;
F_19 ( & V_7 -> V_85 [ V_19 ] . V_2 , 0 ) ;
}
F_66 ( & V_7 -> V_99 ) ;
F_100 ( V_7 -> V_209 ) ;
if ( ! F_81 ( V_7 -> V_36 ) )
F_101 ( V_7 -> V_36 ) ;
return 0 ;
}
static int F_103 ( struct V_238 * V_239 )
{
const struct V_200 * V_95 ;
unsigned long V_103 = 0 ;
struct V_10 * V_10 ;
int V_206 ;
V_239 -> V_240 = 8 ;
V_239 -> V_241 = V_239 -> V_241 ? : V_242 ;
V_239 -> V_243 = V_239 -> V_243 ? : 15000000 ;
V_206 = F_104 ( V_239 ) ;
if ( V_206 )
return V_206 ;
if ( V_239 -> V_8 . V_244 ) {
const struct V_245 * V_246 =
F_105 ( V_247 , & V_239 -> V_8 ) ;
if ( ! V_246 )
return - V_248 ;
V_95 = (struct V_200 * ) V_246 -> V_249 ;
} else {
const struct V_250 * V_251 = F_106 ( V_239 ) ;
V_95 = (struct V_200 * ) V_251 -> V_252 ;
V_103 = V_253 ;
}
V_254 . V_255 = ( 0xf << V_11 ) |
( V_95 -> V_96 - 1 ) ;
V_10 = F_107 ( V_239 , & V_254 ) ;
return F_79 ( & V_239 -> V_8 , V_95 , V_10 , V_239 -> V_97 , V_103 ) ;
}
static int F_108 ( struct V_238 * V_239 )
{
return F_102 ( & V_239 -> V_8 ) ;
}
static int F_109 ( struct V_256 * V_257 ,
const struct V_258 * V_259 )
{
const struct V_200 * V_95 ;
unsigned long V_103 = 0 ;
struct V_10 * V_10 ;
if ( V_257 -> V_8 . V_244 ) {
const struct V_245 * V_246 =
F_105 ( V_247 , & V_257 -> V_8 ) ;
if ( ! V_246 )
return - V_248 ;
V_95 = (struct V_200 * ) V_246 -> V_249 ;
} else {
V_95 = (struct V_200 * ) V_259 -> V_252 ;
V_103 = V_253 ;
}
V_254 . V_255 = ( 0xf << V_11 ) |
( V_95 -> V_96 - 1 ) ;
V_10 = F_110 ( V_257 , & V_254 ) ;
return F_79 ( & V_257 -> V_8 , V_95 , V_10 , V_257 -> V_97 , V_103 ) ;
}
static int F_111 ( struct V_256 * V_260 )
{
return F_102 ( & V_260 -> V_8 ) ;
}
static int T_4 F_112 ( void )
{
int V_206 ;
V_206 = F_113 ( & V_236 ) ;
if ( V_206 ) {
F_114 ( L_7 ) ;
return V_206 ;
}
#ifdef F_115
V_206 = F_116 ( & V_261 ) ;
if ( V_206 < 0 ) {
F_114 ( L_8 , V_206 ) ;
return V_206 ;
}
#endif
#ifdef F_117
V_206 = F_118 ( & V_262 ) ;
if ( V_206 < 0 ) {
F_114 ( L_9 , V_206 ) ;
return V_206 ;
}
#endif
return V_206 ;
}
static void T_5 F_119 ( void )
{
#ifdef F_115
F_120 ( & V_261 ) ;
#endif
#ifdef F_117
F_121 ( & V_262 ) ;
#endif
F_122 ( & V_236 ) ;
}
