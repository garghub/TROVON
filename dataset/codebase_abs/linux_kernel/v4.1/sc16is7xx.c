static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
unsigned int V_7 = 0 ;
F_3 ( V_5 -> V_8 ,
( V_3 << V_9 ) | V_2 -> line , & V_7 ) ;
return V_7 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
F_5 ( V_5 -> V_8 ,
( V_3 << V_9 ) | V_2 -> line , V_7 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_10 , T_1 V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
F_7 ( V_5 -> V_8 ,
( V_3 << V_9 ) | V_2 -> line ,
V_10 , V_7 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_11 )
{
F_6 ( V_2 , V_12 ,
V_13 ,
V_11 ? 0 : V_13 ) ;
}
static bool F_9 ( struct V_14 * V_6 , unsigned int V_3 )
{
switch ( V_3 >> V_9 ) {
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
return true ;
default:
break;
}
return false ;
}
static bool F_10 ( struct V_14 * V_6 , unsigned int V_3 )
{
switch ( V_3 >> V_9 ) {
case V_15 :
return true ;
default:
break;
}
return false ;
}
static int F_11 ( struct V_1 * V_2 , int V_22 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
T_1 V_23 ;
T_1 V_24 = 0 ;
unsigned long V_25 = V_2 -> V_26 , div = V_25 / 16 / V_22 ;
if ( div > 0xffff ) {
V_24 = V_27 ;
div /= 4 ;
}
V_23 = F_1 ( V_2 , V_28 ) ;
F_4 ( V_2 , V_28 ,
V_29 ) ;
F_12 ( V_5 -> V_8 , true ) ;
F_4 ( V_2 , V_30 ,
V_31 ) ;
F_12 ( V_5 -> V_8 , false ) ;
F_4 ( V_2 , V_28 , V_23 ) ;
F_6 ( V_2 , V_32 ,
V_27 ,
V_24 ) ;
F_4 ( V_2 , V_28 ,
V_33 ) ;
F_12 ( V_5 -> V_8 , true ) ;
F_4 ( V_2 , V_34 , div / 256 ) ;
F_4 ( V_2 , V_35 , div % 256 ) ;
F_12 ( V_5 -> V_8 , false ) ;
F_4 ( V_2 , V_28 , V_23 ) ;
return F_13 ( V_25 / 16 , div ) ;
}
static void F_14 ( struct V_1 * V_2 , unsigned int V_36 ,
unsigned int V_37 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
unsigned int V_38 = 0 , V_39 , V_40 , V_41 , V_42 ;
bool V_43 = ( V_37 == V_44 ) ? true : false ;
if ( F_15 ( V_36 >= sizeof( V_5 -> V_45 ) ) ) {
F_16 ( V_2 -> V_6 ,
L_1 ,
V_2 -> line , V_36 ) ;
V_2 -> V_46 . V_47 ++ ;
V_36 = sizeof( V_5 -> V_45 ) ;
}
while ( V_36 ) {
if ( V_43 ) {
V_38 = F_1 ( V_2 , V_17 ) ;
if ( ! ( V_38 & V_48 ) )
V_43 = false ;
} else
V_38 = 0 ;
if ( V_43 ) {
V_5 -> V_45 [ 0 ] = F_1 ( V_2 , V_15 ) ;
V_41 = 1 ;
} else {
F_12 ( V_5 -> V_8 , true ) ;
F_17 ( V_5 -> V_8 , V_15 ,
V_5 -> V_45 , V_36 ) ;
F_12 ( V_5 -> V_8 , false ) ;
V_41 = V_36 ;
}
V_38 &= V_49 ;
V_2 -> V_46 . V_50 ++ ;
V_40 = V_51 ;
if ( F_15 ( V_38 ) ) {
if ( V_38 & V_52 ) {
V_2 -> V_46 . V_53 ++ ;
if ( F_18 ( V_2 ) )
continue;
} else if ( V_38 & V_54 )
V_2 -> V_46 . V_55 ++ ;
else if ( V_38 & V_56 )
V_2 -> V_46 . V_57 ++ ;
else if ( V_38 & V_58 )
V_2 -> V_46 . V_59 ++ ;
V_38 &= V_2 -> V_60 ;
if ( V_38 & V_52 )
V_40 = V_61 ;
else if ( V_38 & V_54 )
V_40 = V_62 ;
else if ( V_38 & V_56 )
V_40 = V_63 ;
else if ( V_38 & V_58 )
V_40 = V_64 ;
}
for ( V_42 = 0 ; V_42 < V_41 ; ++ V_42 ) {
V_39 = V_5 -> V_45 [ V_42 ] ;
if ( F_19 ( V_2 , V_39 ) )
continue;
if ( V_38 & V_2 -> V_65 )
continue;
F_20 ( V_2 , V_38 , V_58 , V_39 ,
V_40 ) ;
}
V_36 -= V_41 ;
}
F_21 ( & V_2 -> V_66 -> V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_67 * V_68 = & V_2 -> V_66 -> V_68 ;
unsigned int V_69 , V_70 , V_42 ;
if ( F_15 ( V_2 -> V_71 ) ) {
F_4 ( V_2 , V_72 , V_2 -> V_71 ) ;
V_2 -> V_46 . V_73 ++ ;
V_2 -> V_71 = 0 ;
return;
}
if ( F_23 ( V_68 ) || F_24 ( V_2 ) )
return;
V_70 = F_25 ( V_68 ) ;
if ( F_26 ( V_70 ) ) {
V_69 = F_1 ( V_2 , V_19 ) ;
V_70 = ( V_70 > V_69 ) ? V_69 : V_70 ;
V_2 -> V_46 . V_73 += V_70 ;
for ( V_42 = 0 ; V_42 < V_70 ; ++ V_42 ) {
V_5 -> V_45 [ V_42 ] = V_68 -> V_45 [ V_68 -> V_74 ] ;
V_68 -> V_74 = ( V_68 -> V_74 + 1 ) & ( V_75 - 1 ) ;
}
F_12 ( V_5 -> V_8 , true ) ;
F_27 ( V_5 -> V_8 , V_72 , V_5 -> V_45 , V_70 ) ;
F_12 ( V_5 -> V_8 , false ) ;
}
if ( F_25 ( V_68 ) < V_76 )
F_28 ( V_2 ) ;
}
static void F_29 ( struct V_4 * V_5 , int V_77 )
{
struct V_1 * V_2 = & V_5 -> V_78 [ V_77 ] . V_2 ;
do {
unsigned int V_37 , V_79 , V_36 ;
V_37 = F_1 ( V_2 , V_16 ) ;
if ( V_37 & V_80 )
break;
V_37 &= V_81 ;
switch ( V_37 ) {
case V_82 :
case V_44 :
case V_83 :
case V_84 :
V_36 = F_1 ( V_2 , V_20 ) ;
if ( V_36 )
F_14 ( V_2 , V_36 , V_37 ) ;
break;
case V_85 :
V_79 = F_1 ( V_2 , V_18 ) ;
F_30 ( V_2 ,
! ! ( V_79 & V_86 ) ) ;
break;
case V_87 :
F_31 ( & V_5 -> V_88 ) ;
F_22 ( V_2 ) ;
F_32 ( & V_5 -> V_88 ) ;
break;
default:
F_33 ( V_2 -> V_6 ,
L_2 ,
V_2 -> line , V_37 ) ;
break;
}
} while ( 1 );
}
static T_2 F_34 ( int V_89 , void * V_90 )
{
struct V_4 * V_5 = (struct V_4 * ) V_90 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_91 . V_92 ; ++ V_42 )
F_29 ( V_5 , V_42 ) ;
return V_93 ;
}
static void F_35 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = F_36 ( V_95 , V_98 ) ;
struct V_4 * V_5 = F_2 ( V_97 -> V_2 . V_6 ) ;
F_31 ( & V_5 -> V_88 ) ;
F_22 ( & V_97 -> V_2 ) ;
F_32 ( & V_5 -> V_88 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_96 * V_97 = F_36 ( V_2 , V_2 ) ;
struct V_67 * V_68 = & V_97 -> V_2 . V_66 -> V_68 ;
if ( V_2 -> V_99 . V_100 & V_101 ) {
int V_38 = F_1 ( V_2 , V_17 ) ;
if ( ! ( V_38 & V_102 ) )
return;
if ( F_23 ( V_68 ) &&
( V_2 -> V_99 . V_103 > 0 ) )
F_38 ( V_2 -> V_99 . V_103 ) ;
}
F_6 ( V_2 , V_12 ,
V_104 ,
0 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_96 * V_97 = F_36 ( V_2 , V_2 ) ;
V_97 -> V_2 . V_60 &= ~ V_105 ;
F_6 ( V_2 , V_12 ,
V_105 ,
0 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_96 * V_97 = F_36 ( V_2 , V_2 ) ;
if ( ( V_2 -> V_99 . V_100 & V_101 ) &&
( V_2 -> V_99 . V_106 > 0 ) ) {
F_38 ( V_2 -> V_99 . V_106 ) ;
}
if ( ! F_41 ( & V_97 -> V_98 ) )
F_42 ( & V_97 -> V_98 ) ;
}
static unsigned int F_43 ( struct V_1 * V_2 )
{
unsigned int V_107 , V_38 ;
V_107 = F_1 ( V_2 , V_19 ) ;
V_38 = F_1 ( V_2 , V_17 ) ;
return ( ( V_38 & V_108 ) && ! V_107 ) ? V_109 : 0 ;
}
static unsigned int F_44 ( struct V_1 * V_2 )
{
return V_110 | V_111 ;
}
static void F_45 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = F_36 ( V_95 , V_112 ) ;
F_6 ( & V_97 -> V_2 , V_32 ,
V_113 ,
( V_97 -> V_2 . V_114 & V_115 ) ?
V_113 : 0 ) ;
}
static void F_46 ( struct V_1 * V_2 , unsigned int V_114 )
{
struct V_96 * V_97 = F_36 ( V_2 , V_2 ) ;
F_42 ( & V_97 -> V_112 ) ;
}
static void F_47 ( struct V_1 * V_2 , int V_116 )
{
F_6 ( V_2 , V_28 ,
V_117 ,
V_116 ? V_117 : 0 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_118 * V_119 ,
struct V_118 * V_120 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
unsigned int V_23 , V_121 = 0 ;
int V_22 ;
V_119 -> V_122 &= ~ V_123 ;
switch ( V_119 -> V_122 & V_124 ) {
case V_125 :
V_23 = V_126 ;
break;
case V_127 :
V_23 = V_128 ;
break;
case V_129 :
V_23 = V_130 ;
break;
case V_131 :
V_23 = V_132 ;
break;
default:
V_23 = V_132 ;
V_119 -> V_122 &= ~ V_124 ;
V_119 -> V_122 |= V_131 ;
break;
}
if ( V_119 -> V_122 & V_133 ) {
V_23 |= V_134 ;
if ( ! ( V_119 -> V_122 & V_135 ) )
V_23 |= V_136 ;
}
if ( V_119 -> V_122 & V_137 )
V_23 |= V_138 ;
V_2 -> V_60 = V_58 ;
if ( V_119 -> V_139 & V_140 )
V_2 -> V_60 |= V_54 |
V_56 ;
if ( V_119 -> V_139 & ( V_141 | V_142 ) )
V_2 -> V_60 |= V_52 ;
V_2 -> V_65 = 0 ;
if ( V_119 -> V_139 & V_143 )
V_2 -> V_65 |= V_52 ;
if ( ! ( V_119 -> V_122 & V_144 ) )
V_2 -> V_65 |= V_49 ;
F_4 ( V_2 , V_28 ,
V_29 ) ;
F_12 ( V_5 -> V_8 , true ) ;
F_4 ( V_2 , V_145 , V_119 -> V_146 [ V_147 ] ) ;
F_4 ( V_2 , V_148 , V_119 -> V_146 [ V_149 ] ) ;
if ( V_119 -> V_122 & V_150 )
V_121 |= V_151 |
V_152 ;
if ( V_119 -> V_139 & V_153 )
V_121 |= V_154 ;
if ( V_119 -> V_139 & V_155 )
V_121 |= V_156 ;
F_4 ( V_2 , V_30 , V_121 ) ;
F_12 ( V_5 -> V_8 , false ) ;
F_4 ( V_2 , V_28 , V_23 ) ;
V_22 = F_49 ( V_2 , V_119 , V_120 ,
V_2 -> V_26 / 16 / 4 / 0xffff ,
V_2 -> V_26 / 16 ) ;
V_22 = F_11 ( V_2 , V_22 ) ;
F_50 ( V_2 , V_119 -> V_122 , V_22 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_157 * V_99 )
{
const T_3 V_10 = V_158 |
V_159 ;
T_3 V_160 = 0 ;
if ( V_99 -> V_100 & V_101 ) {
bool V_161 , V_162 ;
V_161 = V_99 -> V_100 & V_163 ;
V_162 = V_99 -> V_100 & V_164 ;
V_160 |= V_158 ;
if ( ! V_161 && V_162 )
;
else if ( V_161 && ! V_162 )
V_160 |= V_159 ;
else
F_52 ( V_2 -> V_6 ,
L_3 ,
V_162 , V_161 ) ;
}
F_6 ( V_2 , V_165 , V_10 , V_160 ) ;
V_2 -> V_99 = * V_99 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
unsigned int V_7 ;
F_8 ( V_2 , 1 ) ;
V_7 = V_166 | V_167 ;
F_4 ( V_2 , V_168 , V_7 ) ;
F_54 ( 5 ) ;
F_4 ( V_2 , V_168 ,
V_169 ) ;
F_4 ( V_2 , V_28 ,
V_29 ) ;
F_12 ( V_5 -> V_8 , true ) ;
F_4 ( V_2 , V_30 ,
V_31 ) ;
F_6 ( V_2 , V_32 ,
V_170 ,
V_170 ) ;
F_4 ( V_2 , V_171 ,
F_55 ( 24 ) |
F_56 ( 48 ) ) ;
F_12 ( V_5 -> V_8 , false ) ;
F_4 ( V_2 , V_28 , V_132 ) ;
F_6 ( V_2 , V_165 ,
V_172 |
V_173 ,
0 ) ;
V_7 = V_174 | V_104 |
V_175 ;
F_4 ( V_2 , V_12 , V_7 ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_12 , 0 ) ;
F_6 ( V_2 , V_165 ,
V_172 |
V_173 ,
V_172 |
V_173 ) ;
F_8 ( V_2 , 0 ) ;
}
static const char * F_58 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
return ( V_2 -> type == V_176 ) ? V_5 -> V_177 -> V_178 : NULL ;
}
static int F_59 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_60 ( struct V_1 * V_2 , int V_100 )
{
if ( V_100 & V_179 )
V_2 -> type = V_176 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_180 * V_5 )
{
if ( ( V_5 -> type != V_181 ) && ( V_5 -> type != V_176 ) )
return - V_182 ;
if ( V_5 -> V_89 != V_2 -> V_89 )
return - V_182 ;
return 0 ;
}
static void F_62 ( struct V_1 * V_2 , unsigned int V_66 ,
unsigned int V_183 )
{
F_8 ( V_2 , ( V_66 == V_184 ) ? 1 : 0 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
}
static int F_64 ( struct V_185 * V_186 , unsigned V_187 )
{
unsigned int V_7 ;
struct V_4 * V_5 = F_65 ( V_186 , struct V_4 ,
V_188 ) ;
struct V_1 * V_2 = & V_5 -> V_78 [ 0 ] . V_2 ;
V_7 = F_1 ( V_2 , V_21 ) ;
return ! ! ( V_7 & F_66 ( V_187 ) ) ;
}
static void F_67 ( struct V_185 * V_186 , unsigned V_187 , int V_7 )
{
struct V_4 * V_5 = F_65 ( V_186 , struct V_4 ,
V_188 ) ;
struct V_1 * V_2 = & V_5 -> V_78 [ 0 ] . V_2 ;
F_6 ( V_2 , V_21 , F_66 ( V_187 ) ,
V_7 ? F_66 ( V_187 ) : 0 ) ;
}
static int F_68 ( struct V_185 * V_186 ,
unsigned V_187 )
{
struct V_4 * V_5 = F_65 ( V_186 , struct V_4 ,
V_188 ) ;
struct V_1 * V_2 = & V_5 -> V_78 [ 0 ] . V_2 ;
F_6 ( V_2 , V_189 , F_66 ( V_187 ) , 0 ) ;
return 0 ;
}
static int F_69 ( struct V_185 * V_186 ,
unsigned V_187 , int V_7 )
{
struct V_4 * V_5 = F_65 ( V_186 , struct V_4 ,
V_188 ) ;
struct V_1 * V_2 = & V_5 -> V_78 [ 0 ] . V_2 ;
F_6 ( V_2 , V_21 , F_66 ( V_187 ) ,
V_7 ? F_66 ( V_187 ) : 0 ) ;
F_6 ( V_2 , V_189 , F_66 ( V_187 ) ,
F_66 ( V_187 ) ) ;
return 0 ;
}
static int F_70 ( struct V_14 * V_6 ,
struct V_190 * V_177 ,
struct V_8 * V_8 , int V_89 , unsigned long V_100 )
{
unsigned long V_191 , * V_192 = F_71 ( V_6 ) ;
int V_42 , V_193 ;
struct V_4 * V_5 ;
if ( F_72 ( V_8 ) )
return F_73 ( V_8 ) ;
V_5 = F_74 ( V_6 , sizeof( * V_5 ) +
sizeof( struct V_96 ) * V_177 -> V_194 ,
V_195 ) ;
if ( ! V_5 ) {
F_52 ( V_6 , L_4 ) ;
return - V_196 ;
}
V_5 -> V_25 = F_75 ( V_6 , NULL ) ;
if ( F_72 ( V_5 -> V_25 ) ) {
if ( V_192 )
V_191 = * V_192 ;
else
return F_73 ( V_5 -> V_25 ) ;
} else {
F_76 ( V_5 -> V_25 ) ;
V_191 = F_77 ( V_5 -> V_25 ) ;
}
V_5 -> V_8 = V_8 ;
V_5 -> V_177 = V_177 ;
F_78 ( V_6 , V_5 ) ;
V_5 -> V_91 . V_197 = V_198 ;
V_5 -> V_91 . V_199 = L_5 ;
V_5 -> V_91 . V_92 = V_177 -> V_194 ;
V_193 = F_79 ( & V_5 -> V_91 ) ;
if ( V_193 ) {
F_52 ( V_6 , L_6 ) ;
goto V_200;
}
#ifdef F_80
if ( V_177 -> V_201 ) {
V_5 -> V_188 . V_197 = V_198 ;
V_5 -> V_188 . V_6 = V_6 ;
V_5 -> V_188 . V_202 = V_199 ( V_6 ) ;
V_5 -> V_188 . V_203 = F_68 ;
V_5 -> V_188 . V_204 = F_64 ;
V_5 -> V_188 . V_205 = F_69 ;
V_5 -> V_188 . V_206 = F_67 ;
V_5 -> V_188 . V_207 = - 1 ;
V_5 -> V_188 . V_208 = V_177 -> V_201 ;
V_5 -> V_188 . V_209 = 1 ;
V_193 = F_81 ( & V_5 -> V_188 ) ;
if ( V_193 )
goto V_210;
}
#endif
F_82 ( & V_5 -> V_88 ) ;
for ( V_42 = 0 ; V_42 < V_177 -> V_194 ; ++ V_42 ) {
V_5 -> V_78 [ V_42 ] . V_2 . line = V_42 ;
V_5 -> V_78 [ V_42 ] . V_2 . V_6 = V_6 ;
V_5 -> V_78 [ V_42 ] . V_2 . V_89 = V_89 ;
V_5 -> V_78 [ V_42 ] . V_2 . type = V_176 ;
V_5 -> V_78 [ V_42 ] . V_2 . V_211 = V_212 ;
V_5 -> V_78 [ V_42 ] . V_2 . V_100 = V_213 | V_214 ;
V_5 -> V_78 [ V_42 ] . V_2 . V_215 = V_216 ;
V_5 -> V_78 [ V_42 ] . V_2 . V_26 = V_191 ;
V_5 -> V_78 [ V_42 ] . V_2 . V_217 = F_51 ;
V_5 -> V_78 [ V_42 ] . V_2 . V_218 = & V_219 ;
F_4 ( & V_5 -> V_78 [ V_42 ] . V_2 , V_12 , 0 ) ;
F_4 ( & V_5 -> V_78 [ V_42 ] . V_2 , V_165 ,
V_172 |
V_173 ) ;
F_83 ( & V_5 -> V_78 [ V_42 ] . V_98 , F_35 ) ;
F_83 ( & V_5 -> V_78 [ V_42 ] . V_112 , F_45 ) ;
F_84 ( & V_5 -> V_91 , & V_5 -> V_78 [ V_42 ] . V_2 ) ;
F_8 ( & V_5 -> V_78 [ V_42 ] . V_2 , 0 ) ;
}
V_193 = F_85 ( V_6 , V_89 , NULL , F_34 ,
V_220 | V_100 , V_199 ( V_6 ) , V_5 ) ;
if ( ! V_193 )
return 0 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_91 . V_92 ; V_42 ++ )
F_86 ( & V_5 -> V_91 , & V_5 -> V_78 [ V_42 ] . V_2 ) ;
F_87 ( & V_5 -> V_88 ) ;
#ifdef F_80
if ( V_177 -> V_201 )
F_88 ( & V_5 -> V_188 ) ;
V_210:
#endif
F_89 ( & V_5 -> V_91 ) ;
V_200:
if ( ! F_72 ( V_5 -> V_25 ) )
F_90 ( V_5 -> V_25 ) ;
return V_193 ;
}
static int F_91 ( struct V_14 * V_6 )
{
struct V_4 * V_5 = F_2 ( V_6 ) ;
int V_42 ;
#ifdef F_80
if ( V_5 -> V_177 -> V_201 )
F_88 ( & V_5 -> V_188 ) ;
#endif
for ( V_42 = 0 ; V_42 < V_5 -> V_91 . V_92 ; V_42 ++ ) {
F_92 ( & V_5 -> V_78 [ V_42 ] . V_98 ) ;
F_92 ( & V_5 -> V_78 [ V_42 ] . V_112 ) ;
F_86 ( & V_5 -> V_91 , & V_5 -> V_78 [ V_42 ] . V_2 ) ;
F_8 ( & V_5 -> V_78 [ V_42 ] . V_2 , 0 ) ;
}
F_87 ( & V_5 -> V_88 ) ;
F_89 ( & V_5 -> V_91 ) ;
if ( ! F_72 ( V_5 -> V_25 ) )
F_90 ( V_5 -> V_25 ) ;
return 0 ;
}
static int F_93 ( struct V_221 * V_222 ,
const struct V_223 * V_224 )
{
struct V_190 * V_177 ;
unsigned long V_100 = 0 ;
struct V_8 * V_8 ;
if ( V_222 -> V_6 . V_225 ) {
const struct V_226 * V_227 =
F_94 ( V_228 , & V_222 -> V_6 ) ;
V_177 = (struct V_190 * ) V_227 -> V_229 ;
} else {
V_177 = (struct V_190 * ) V_224 -> V_230 ;
V_100 = V_231 ;
}
V_232 . V_233 = ( 0xf << V_9 ) |
( V_177 -> V_194 - 1 ) ;
V_8 = F_95 ( V_222 , & V_232 ) ;
return F_70 ( & V_222 -> V_6 , V_177 , V_8 , V_222 -> V_89 , V_100 ) ;
}
static int F_96 ( struct V_221 * V_234 )
{
return F_91 ( & V_234 -> V_6 ) ;
}
