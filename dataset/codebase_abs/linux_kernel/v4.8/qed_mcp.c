bool F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 || ! V_2 -> V_3 -> V_4 )
return false ;
return true ;
}
void F_2 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
T_1 V_7 = F_3 ( V_2 -> V_3 -> V_4 ,
V_8 ) ;
T_1 V_9 = F_4 ( V_2 , V_6 , V_7 ) ;
V_2 -> V_3 -> V_10 = F_5 ( V_9 ,
F_6 ( V_2 ) ) ;
F_7 ( V_2 , V_11 ,
L_1 ,
V_2 -> V_3 -> V_10 , F_6 ( V_2 ) ) ;
}
void F_8 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
T_1 V_12 = F_9 ( V_2 -> V_3 -> V_13 ) ;
T_1 V_14 , V_15 ;
if ( ! V_2 -> V_3 -> V_4 )
return;
for ( V_15 = 0 ; V_15 < V_12 ; V_15 ++ ) {
V_14 = F_4 ( V_2 , V_6 ,
V_2 -> V_3 -> V_16 +
( V_15 << 2 ) + sizeof( T_1 ) ) ;
( ( T_1 * ) V_2 -> V_3 -> V_17 ) [ V_15 ] =
F_10 ( ( V_18 V_19 ) V_14 ) ;
}
}
int F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 ) {
F_12 ( V_2 -> V_3 -> V_17 ) ;
F_12 ( V_2 -> V_3 -> V_20 ) ;
}
F_12 ( V_2 -> V_3 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_21 * V_22 = V_2 -> V_3 ;
T_1 V_23 , V_9 ;
T_1 V_24 = F_14 ( V_2 ) ;
V_22 -> V_4 = F_4 ( V_2 , V_6 , V_25 ) ;
if ( ! V_22 -> V_4 )
return 0 ;
V_22 -> V_4 |= V_26 ;
V_23 = F_4 ( V_2 , V_6 ,
F_3 ( V_22 -> V_4 ,
V_27 ) ) ;
V_22 -> V_28 = F_5 ( V_23 , V_24 ) ;
F_7 ( V_2 , V_11 ,
L_2 ,
V_23 , V_22 -> V_28 , V_24 ) ;
V_9 = F_4 ( V_2 , V_6 ,
F_3 ( V_22 -> V_4 ,
V_29 ) ) ;
V_22 -> V_16 = F_5 ( V_9 , V_24 ) ;
V_22 -> V_13 = ( V_30 ) F_4 ( V_2 , V_6 , V_22 -> V_16 ) ;
V_22 -> V_31 = F_15 ( V_2 , V_6 , V_32 ) &
V_33 ;
V_22 -> V_34 = F_15 ( V_2 , V_6 , V_35 ) &
V_36 ;
V_22 -> V_37 = ( V_30 ) F_4 ( V_2 , V_6 , V_38 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_21 * V_22 ;
T_1 V_39 ;
V_2 -> V_3 = F_17 ( sizeof( * V_2 -> V_3 ) , V_40 ) ;
if ( ! V_2 -> V_3 )
goto V_41;
V_22 = V_2 -> V_3 ;
if ( F_13 ( V_2 , V_6 ) != 0 ) {
F_18 ( V_2 , L_3 ) ;
return 0 ;
}
V_39 = F_9 ( V_22 -> V_13 ) * sizeof( T_1 ) ;
V_22 -> V_17 = F_17 ( V_39 , V_40 ) ;
V_22 -> V_20 =
F_17 ( sizeof( T_1 ) * F_9 (
V_22 -> V_13 ) , V_40 ) ;
if ( ! V_22 -> V_20 || ! V_22 -> V_16 )
goto V_41;
F_19 ( & V_22 -> V_42 ) ;
return 0 ;
V_41:
F_18 ( V_2 , L_4 ) ;
F_11 ( V_2 ) ;
return - V_43 ;
}
static int F_20 ( struct V_1 * V_2 ,
T_1 V_44 )
{
F_21 ( & V_2 -> V_3 -> V_42 ) ;
if ( V_44 == V_45 || V_44 == V_46 )
V_2 -> V_3 -> V_47 = false ;
if ( V_2 -> V_3 -> V_47 ) {
F_18 ( V_2 ,
L_5 ,
V_44 ) ;
F_22 ( & V_2 -> V_3 -> V_42 ) ;
return - V_48 ;
}
if ( V_44 == V_49 || V_44 == V_50 ) {
V_2 -> V_3 -> V_47 = true ;
F_22 ( & V_2 -> V_3 -> V_42 ) ;
}
return 0 ;
}
static void F_23 ( struct V_1 * V_2 ,
T_1 V_44 )
{
if ( V_44 != V_49 && V_44 != V_50 )
F_22 ( & V_2 -> V_3 -> V_42 ) ;
}
int F_24 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
T_1 V_51 = ++ V_2 -> V_3 -> V_31 ;
T_2 V_52 = V_53 ;
T_1 V_54 , V_55 = 0 ;
int V_56 = 0 ;
V_56 = F_20 ( V_2 , V_57 ) ;
if ( V_56 != 0 )
return V_56 ;
V_54 = F_4 ( V_2 , V_6 , V_38 ) ;
F_25 ( V_2 , V_6 , V_32 ,
( V_57 | V_51 ) ) ;
do {
F_26 ( V_52 ) ;
} while ( ( V_54 == F_4 ( V_2 , V_6 ,
V_38 ) ) &&
( V_55 ++ < V_58 ) );
if ( V_54 !=
F_4 ( V_2 , V_6 , V_38 ) ) {
F_7 ( V_2 , V_11 ,
L_6 , V_55 * V_52 ) ;
} else {
F_27 ( V_2 , L_7 ) ;
V_56 = - V_59 ;
}
F_23 ( V_2 , V_57 ) ;
return V_56 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 V_44 ,
T_1 V_60 ,
T_1 * V_61 ,
T_1 * V_62 )
{
T_2 V_52 = V_53 ;
T_1 V_51 , V_55 = 1 , V_63 ;
int V_56 = 0 ;
V_63 = F_15 ( V_2 , V_6 , V_32 ) &
V_33 ;
if ( V_2 -> V_3 -> V_37 !=
F_4 ( V_2 , V_6 , V_38 ) ) {
F_7 ( V_2 , V_11 , L_8 ) ;
F_13 ( V_2 , V_6 ) ;
F_2 ( V_2 , V_6 ) ;
}
V_51 = ++ V_2 -> V_3 -> V_31 ;
F_25 ( V_2 , V_6 , V_64 , V_60 ) ;
F_25 ( V_2 , V_6 , V_32 , ( V_44 | V_51 ) ) ;
F_7 ( V_2 , V_11 ,
L_9 ,
( V_44 | V_51 ) , V_60 ) ;
do {
F_26 ( V_52 ) ;
* V_61 = F_15 ( V_2 , V_6 , V_65 ) ;
} while ( ( V_51 != ( * V_61 & V_66 ) ) &&
( V_55 ++ < V_67 ) );
F_7 ( V_2 , V_11 ,
L_10 ,
V_55 * V_52 , * V_61 , V_51 ) ;
if ( V_51 == ( * V_61 & V_66 ) ) {
* V_61 &= V_68 ;
* V_62 = F_15 ( V_2 , V_6 , V_69 ) ;
} else {
F_27 ( V_2 , L_11 ) ;
* V_61 = 0 ;
V_56 = - V_59 ;
}
return V_56 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_70 * V_71 )
{
T_1 V_72 ;
int V_56 ;
if ( ! F_1 ( V_2 ) ) {
F_18 ( V_2 , L_12 ) ;
return - V_48 ;
}
V_72 = V_2 -> V_3 -> V_28 +
F_30 ( struct V_73 , V_74 ) ;
V_56 = F_20 ( V_2 , V_71 -> V_44 ) ;
if ( V_56 )
return V_56 ;
if ( V_71 -> V_75 != NULL )
F_31 ( V_2 , V_6 , V_72 ,
V_71 -> V_75 ,
sizeof( * V_71 -> V_75 ) ) ;
V_56 = F_28 ( V_2 , V_6 , V_71 -> V_44 ,
V_71 -> V_60 , & V_71 -> V_76 ,
& V_71 -> V_77 ) ;
if ( V_71 -> V_78 != NULL )
F_32 ( V_2 , V_6 , V_71 -> V_78 ,
V_72 ,
sizeof( * V_71 -> V_78 ) ) ;
F_23 ( V_2 , V_71 -> V_44 ) ;
return V_56 ;
}
int F_33 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 V_44 ,
T_1 V_60 ,
T_1 * V_61 ,
T_1 * V_62 )
{
struct V_70 V_79 ;
int V_56 ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_44 = V_44 ;
V_79 . V_60 = V_60 ;
V_56 = F_29 ( V_2 , V_6 , & V_79 ) ;
if ( V_56 )
return V_56 ;
* V_61 = V_79 . V_76 ;
* V_62 = V_79 . V_77 ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 * V_80 )
{
struct V_81 * V_82 = V_2 -> V_82 ;
struct V_70 V_79 ;
union V_83 V_74 ;
int V_56 ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_44 = V_49 ;
V_79 . V_60 = V_84 | V_85 |
V_82 -> V_86 ;
memcpy ( & V_74 . V_87 , V_82 -> V_87 , V_88 ) ;
V_79 . V_75 = & V_74 ;
V_56 = F_29 ( V_2 , V_6 , & V_79 ) ;
if ( V_56 ) {
F_27 ( V_2 , L_13 ) ;
return V_56 ;
}
* V_80 = V_79 . V_76 ;
if ( ! ( * V_80 ) ||
( ( * V_80 ) == V_89 ) ||
( ( * V_80 ) == V_90 ) ||
( ( * V_80 ) == V_91 ) ) {
F_27 ( V_2 , L_14 ) ;
return - V_48 ;
}
return 0 ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
T_1 V_7 = F_3 ( V_2 -> V_3 -> V_4 ,
V_92 ) ;
T_1 V_93 = F_4 ( V_2 , V_6 , V_7 ) ;
T_1 V_94 = F_5 ( V_93 ,
F_36 ( V_2 ) ) ;
T_1 V_95 [ V_96 / 32 ] ;
int V_15 ;
F_7 ( V_2 ,
V_11 ,
L_15 ,
V_93 , V_94 ) ;
for ( V_15 = 0 ; V_15 < ( V_96 / 32 ) ; V_15 ++ ) {
V_95 [ V_15 ] = F_4 ( V_2 , V_6 ,
V_94 +
F_30 ( struct V_97 ,
V_98 ) +
sizeof( T_1 ) * V_15 ) ;
F_7 ( V_2 , ( V_11 | V_99 ) ,
L_16 ,
V_15 * 32 , ( V_15 + 1 ) * 32 - 1 , V_95 [ V_15 ] ) ;
}
if ( F_37 ( V_2 , V_95 ) )
F_38 ( V_2 , V_100 ) ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_1 * V_101 )
{
T_1 V_7 = F_3 ( V_2 -> V_3 -> V_4 ,
V_102 ) ;
T_1 V_103 = F_4 ( V_2 , V_6 , V_7 ) ;
T_1 V_104 = F_5 ( V_103 ,
F_14 ( V_2 ) ) ;
struct V_70 V_79 ;
union V_83 V_74 ;
int V_56 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < ( V_96 / 32 ) ; V_15 ++ )
F_7 ( V_2 , ( V_11 | V_99 ) ,
L_17 ,
V_15 * 32 , ( V_15 + 1 ) * 32 - 1 , V_101 [ V_15 ] ) ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_44 = V_105 ;
memcpy ( & V_74 . V_106 , V_101 , V_96 / 8 ) ;
V_79 . V_75 = & V_74 ;
V_56 = F_29 ( V_2 , V_6 , & V_79 ) ;
if ( V_56 ) {
F_18 ( V_2 , L_18 ) ;
return - V_48 ;
}
for ( V_15 = 0 ; V_15 < ( V_96 / 32 ) ; V_15 ++ )
F_40 ( V_2 , V_6 ,
V_104 +
F_30 ( struct V_107 , V_108 ) +
V_15 * sizeof( T_1 ) , 0 ) ;
return V_56 ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
T_1 V_109 ;
V_109 = F_4 ( V_2 , V_6 ,
V_2 -> V_3 -> V_10 +
F_30 ( struct V_110 ,
V_111 ) ) ;
F_7 ( V_2 ,
( V_112 | V_11 ) ,
L_19 ,
V_109 ,
( T_1 ) ( V_2 -> V_3 -> V_10 +
F_30 ( struct V_110 ,
V_111 ) ) ) ;
V_109 = F_42 ( V_109 ,
V_113 ) ;
if ( V_109 == V_114 )
F_18 ( V_2 , L_20 ) ;
else
F_18 ( V_2 , L_21 ) ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
bool V_115 )
{
struct V_116 * V_117 ;
T_2 V_118 , V_119 ;
T_1 V_120 = 0 ;
V_117 = & V_2 -> V_3 -> V_121 ;
memset ( V_117 , 0 , sizeof( * V_117 ) ) ;
if ( ! V_115 ) {
V_120 = F_4 ( V_2 , V_6 ,
V_2 -> V_3 -> V_10 +
F_30 ( struct V_110 , V_122 ) ) ;
F_7 ( V_2 , ( V_123 | V_11 ) ,
L_22 ,
V_120 ,
( T_1 ) ( V_2 -> V_3 -> V_10 +
F_30 ( struct V_110 ,
V_122 ) ) ) ;
} else {
F_7 ( V_2 , V_123 ,
L_23 ) ;
return;
}
if ( V_2 -> V_124 )
V_117 -> V_125 = ! ! ( V_120 & V_126 ) ;
else
V_117 -> V_125 = false ;
V_117 -> V_127 = true ;
switch ( ( V_120 & V_128 ) ) {
case V_129 :
V_117 -> V_130 = 100000 ;
break;
case V_131 :
V_117 -> V_130 = 50000 ;
break;
case V_132 :
V_117 -> V_130 = 40000 ;
break;
case V_133 :
V_117 -> V_130 = 25000 ;
break;
case V_134 :
V_117 -> V_130 = 20000 ;
break;
case V_135 :
V_117 -> V_130 = 10000 ;
break;
case V_136 :
V_117 -> V_127 = false ;
case V_137 :
V_117 -> V_130 = 1000 ;
break;
default:
V_117 -> V_130 = 0 ;
}
if ( V_117 -> V_125 && V_117 -> V_130 )
V_117 -> V_138 = V_117 -> V_130 ;
else
V_117 -> V_138 = 0 ;
V_118 = V_2 -> V_3 -> V_139 . V_140 ;
V_119 = V_2 -> V_3 -> V_139 . V_141 ;
F_44 ( V_2 , V_6 , V_117 , V_118 ) ;
F_45 ( V_2 , V_6 , V_117 , V_119 ) ;
F_46 ( V_2 -> V_82 , V_117 -> V_142 ) ;
V_117 -> V_143 = ! ! ( V_120 & V_144 ) ;
V_117 -> V_145 = ! ! ( V_120 &
V_146 ) ;
V_117 -> V_147 = ! ! ( V_120 &
V_148 ) ;
V_117 -> V_149 = ! ! ( V_120 & V_150 ) ;
V_117 -> V_151 |=
( V_120 & V_152 ) ?
V_153 : 0 ;
V_117 -> V_151 |=
( V_120 & V_154 ) ?
V_155 : 0 ;
V_117 -> V_151 |=
( V_120 & V_156 ) ?
V_157 : 0 ;
V_117 -> V_151 |=
( V_120 & V_158 ) ?
V_159 : 0 ;
V_117 -> V_151 |=
( V_120 & V_160 ) ?
V_161 : 0 ;
V_117 -> V_151 |=
( V_120 & V_162 ) ?
V_163 : 0 ;
V_117 -> V_151 |=
( V_120 & V_164 ) ?
V_165 : 0 ;
V_117 -> V_166 =
! ! ( V_120 & V_167 ) ;
V_117 -> V_168 =
! ! ( V_120 & V_169 ) ;
switch ( V_120 & V_170 ) {
case V_171 :
V_117 -> V_172 = V_173 ;
break;
case V_174 :
V_117 -> V_172 = V_175 ;
break;
case V_176 :
V_117 -> V_172 = V_177 ;
break;
default:
V_117 -> V_172 = 0 ;
}
V_117 -> V_178 = ! ! ( V_120 & V_179 ) ;
F_47 ( V_2 ) ;
}
int F_48 ( struct V_1 * V_2 , struct V_5 * V_6 , bool V_180 )
{
struct V_181 * V_182 = & V_2 -> V_3 -> V_183 ;
struct V_70 V_79 ;
union V_83 V_74 ;
struct V_184 * V_185 ;
int V_56 = 0 ;
T_1 V_44 ;
V_185 = & V_74 . V_186 ;
memset ( V_185 , 0 , sizeof( * V_185 ) ) ;
V_44 = V_180 ? V_187 : V_188 ;
if ( ! V_182 -> V_130 . V_189 )
V_185 -> V_130 = V_182 -> V_130 . V_190 ;
V_185 -> V_191 |= ( V_182 -> V_191 . V_189 ) ? V_192 : 0 ;
V_185 -> V_191 |= ( V_182 -> V_191 . V_193 ) ? V_194 : 0 ;
V_185 -> V_191 |= ( V_182 -> V_191 . V_195 ) ? V_196 : 0 ;
V_185 -> V_197 = V_182 -> V_130 . V_198 ;
V_185 -> V_199 = V_182 -> V_199 ;
V_2 -> V_124 = V_180 ;
if ( V_180 ) {
F_7 ( V_2 , V_123 ,
L_24 ,
V_185 -> V_130 ,
V_185 -> V_191 ,
V_185 -> V_197 ,
V_185 -> V_199 ,
V_185 -> V_200 ) ;
} else {
F_7 ( V_2 , V_123 ,
L_25 ) ;
}
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_44 = V_44 ;
V_79 . V_75 = & V_74 ;
V_56 = F_29 ( V_2 , V_6 , & V_79 ) ;
if ( V_56 ) {
F_27 ( V_2 , L_13 ) ;
return V_56 ;
}
if ( ! V_180 )
F_43 ( V_2 , V_6 , true ) ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_107 * V_201 )
{
struct V_202 * V_22 ;
V_22 = & V_2 -> V_3 -> V_139 ;
V_22 -> V_141 = ( V_201 -> V_203 &
V_204 ) >>
V_205 ;
if ( V_22 -> V_141 < 1 || V_22 -> V_141 > 100 ) {
F_50 ( V_2 ,
L_26 ,
V_22 -> V_141 ) ;
V_22 -> V_141 = 1 ;
}
V_22 -> V_140 = ( V_201 -> V_203 &
V_206 ) >>
V_207 ;
if ( V_22 -> V_140 < 1 || V_22 -> V_140 > 100 ) {
F_50 ( V_2 ,
L_27 ,
V_22 -> V_140 ) ;
V_22 -> V_140 = 100 ;
}
}
static T_1 F_51 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_107 * V_208 ,
int V_209 )
{
T_1 V_7 = F_3 ( V_2 -> V_3 -> V_4 ,
V_102 ) ;
T_1 V_93 = F_4 ( V_2 , V_6 , V_7 ) ;
T_1 V_104 = F_5 ( V_93 , V_209 ) ;
T_1 V_15 , V_39 ;
memset ( V_208 , 0 , sizeof( * V_208 ) ) ;
V_39 = F_52 ( T_1 , sizeof( * V_208 ) ,
F_53 ( V_93 ) ) ;
for ( V_15 = 0 ; V_15 < V_39 / sizeof( T_1 ) ; V_15 ++ )
( ( T_1 * ) V_208 ) [ V_15 ] = F_4 ( V_2 , V_6 ,
V_104 + ( V_15 << 2 ) ) ;
return V_39 ;
}
int F_54 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_2 * V_210 )
{
struct V_107 V_211 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < F_55 ( V_2 -> V_82 ) ;
V_15 += V_2 -> V_82 -> V_212 ) {
F_51 ( V_2 , V_6 , & V_211 ,
F_56 ( V_2 , V_15 ) ) ;
if ( V_211 . V_203 & V_213 )
continue;
if ( ( V_211 . V_203 & V_214 ) ==
V_215 ) {
* V_210 = ( T_2 ) V_15 ;
return 0 ;
}
}
F_18 ( V_2 ,
L_28 ) ;
return - V_216 ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_202 * V_22 ;
struct V_107 V_211 ;
T_1 V_217 = 0 , V_60 = 0 ;
F_51 ( V_2 , V_6 , & V_211 ,
F_14 ( V_2 ) ) ;
F_49 ( V_2 , & V_211 ) ;
V_22 = & V_2 -> V_3 -> V_139 ;
F_58 ( V_2 -> V_82 , V_22 -> V_141 ) ;
F_59 ( V_2 -> V_82 , V_22 -> V_140 ) ;
F_33 ( V_2 , V_6 , V_218 , 0 , & V_217 ,
& V_60 ) ;
}
int F_60 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_21 * V_219 = V_2 -> V_3 ;
int V_56 = 0 ;
bool V_220 = false ;
V_30 V_15 ;
F_7 ( V_2 , V_11 , L_29 ) ;
F_8 ( V_2 , V_6 ) ;
for ( V_15 = 0 ; V_15 < V_219 -> V_13 ; V_15 ++ ) {
if ( V_219 -> V_17 [ V_15 ] == V_219 -> V_20 [ V_15 ] )
continue;
V_220 = true ;
F_7 ( V_2 , V_123 ,
L_30 ,
V_15 , V_219 -> V_20 [ V_15 ] , V_219 -> V_17 [ V_15 ] ) ;
switch ( V_15 ) {
case V_221 :
F_43 ( V_2 , V_6 , false ) ;
break;
case V_222 :
F_35 ( V_2 , V_6 ) ;
break;
case V_223 :
F_61 ( V_2 , V_6 ,
V_224 ) ;
break;
case V_225 :
F_61 ( V_2 , V_6 ,
V_226 ) ;
break;
case V_227 :
F_61 ( V_2 , V_6 ,
V_228 ) ;
break;
case V_229 :
F_41 ( V_2 , V_6 ) ;
break;
case V_230 :
F_57 ( V_2 , V_6 ) ;
break;
default:
F_18 ( V_2 , L_31 , V_15 ) ;
V_56 = - V_216 ;
}
}
for ( V_15 = 0 ; V_15 < F_9 ( V_219 -> V_13 ) ; V_15 ++ ) {
V_19 V_231 = F_62 ( ( ( T_1 * ) V_219 -> V_17 ) [ V_15 ] ) ;
F_40 ( V_2 , V_6 ,
V_219 -> V_16 + sizeof( T_1 ) +
F_9 ( V_219 -> V_13 ) *
sizeof( T_1 ) + V_15 * sizeof( T_1 ) ,
( V_18 T_1 ) V_231 ) ;
}
if ( ! V_220 ) {
F_18 ( V_2 ,
L_32 ) ;
V_56 = - V_216 ;
}
memcpy ( V_219 -> V_20 , V_219 -> V_17 , V_219 -> V_13 ) ;
return V_56 ;
}
int F_63 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 * V_232 , T_1 * V_233 )
{
T_1 V_234 ;
if ( F_64 ( V_2 -> V_82 ) ) {
if ( V_2 -> V_235 ) {
struct V_236 * V_237 ;
V_237 = & V_2 -> V_235 -> V_238 ;
* V_232 = V_237 -> V_239 . V_240 ;
return 0 ;
} else {
F_7 ( V_2 ,
V_99 ,
L_33 ) ;
return - V_216 ;
}
}
V_234 = F_4 ( V_2 , V_6 ,
F_3 ( V_2 ->
V_3 -> V_4 ,
V_241 ) ) ;
* V_232 =
F_4 ( V_2 , V_6 ,
F_5 ( V_234 ,
0 ) + F_30 ( struct V_242 , V_240 ) ) ;
if ( V_233 != NULL ) {
* V_233 = F_4 ( V_2 , V_6 ,
F_5 ( V_234 , 0 ) +
F_30 ( struct V_242 ,
V_243 ) ) ;
}
return 0 ;
}
int F_65 ( struct V_81 * V_82 ,
T_1 * V_244 )
{
struct V_1 * V_2 = & V_82 -> V_245 [ 0 ] ;
struct V_5 * V_6 ;
if ( F_64 ( V_82 ) )
return - V_216 ;
if ( ! F_1 ( V_2 ) ) {
F_18 ( V_2 , L_12 ) ;
return - V_48 ;
}
* V_244 = V_246 ;
V_6 = F_66 ( V_2 ) ;
if ( ! V_6 )
return - V_48 ;
* V_244 = F_4 ( V_2 , V_6 , V_2 -> V_3 -> V_10 +
F_30 ( struct V_110 , V_247 ) ) ;
F_67 ( V_2 , V_6 ) ;
return 0 ;
}
static int
F_68 ( struct V_1 * V_2 ,
struct V_107 * V_22 ,
enum V_248 * V_249 )
{
int V_56 = 0 ;
switch ( V_22 -> V_203 & V_214 ) {
case V_215 :
if ( F_69 ( V_250 ,
& V_2 -> V_251 . V_252 ) )
* V_249 = V_253 ;
else
* V_249 = V_254 ;
break;
case V_255 :
* V_249 = V_256 ;
break;
case V_257 :
F_18 ( V_2 , L_34 ) ;
V_56 = - V_216 ;
break;
default:
V_56 = - V_216 ;
}
return V_56 ;
}
int F_70 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_202 * V_219 ;
struct V_107 V_211 ;
F_51 ( V_2 , V_6 , & V_211 ,
F_14 ( V_2 ) ) ;
V_219 = & V_2 -> V_3 -> V_139 ;
V_219 -> V_258 = ( V_211 . V_203 &
V_259 ) ? 1 : 0 ;
if ( F_68 ( V_2 , & V_211 ,
& V_219 -> V_260 ) ) {
F_27 ( V_2 , L_35 ,
( T_1 ) ( V_211 . V_203 & V_214 ) ) ;
return - V_216 ;
}
F_49 ( V_2 , & V_211 ) ;
if ( V_211 . V_261 || V_211 . V_262 ) {
V_219 -> V_263 [ 0 ] = ( T_2 ) ( V_211 . V_261 >> 8 ) ;
V_219 -> V_263 [ 1 ] = ( T_2 ) ( V_211 . V_261 ) ;
V_219 -> V_263 [ 2 ] = ( T_2 ) ( V_211 . V_262 >> 24 ) ;
V_219 -> V_263 [ 3 ] = ( T_2 ) ( V_211 . V_262 >> 16 ) ;
V_219 -> V_263 [ 4 ] = ( T_2 ) ( V_211 . V_262 >> 8 ) ;
V_219 -> V_263 [ 5 ] = ( T_2 ) ( V_211 . V_262 ) ;
} else {
F_18 ( V_2 , L_36 ) ;
}
V_219 -> V_264 = ( V_265 ) V_211 . V_266 |
( ( ( V_265 ) V_211 . V_267 ) << 32 ) ;
V_219 -> V_268 = ( V_265 ) V_211 . V_269 |
( ( ( V_265 ) V_211 . V_270 ) << 32 ) ;
V_219 -> V_271 = ( V_30 ) ( V_211 . V_272 & V_273 ) ;
F_7 ( V_2 , ( V_11 | V_274 ) ,
L_37 ,
V_219 -> V_258 , V_219 -> V_260 ,
V_219 -> V_141 , V_219 -> V_140 ,
V_219 -> V_263 [ 0 ] , V_219 -> V_263 [ 1 ] , V_219 -> V_263 [ 2 ] ,
V_219 -> V_263 [ 3 ] , V_219 -> V_263 [ 4 ] , V_219 -> V_263 [ 5 ] ,
V_219 -> V_264 , V_219 -> V_268 , V_219 -> V_271 ) ;
return 0 ;
}
struct V_181
* F_71 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return NULL ;
return & V_2 -> V_3 -> V_183 ;
}
struct V_116
* F_72 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return NULL ;
return & V_2 -> V_3 -> V_121 ;
}
struct V_275
* F_73 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_3 )
return NULL ;
return & V_2 -> V_3 -> V_276 ;
}
int F_74 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
T_1 V_217 = 0 , V_60 = 0 ;
int V_56 ;
V_56 = F_33 ( V_2 , V_6 ,
V_277 , 1000 ,
& V_217 , & V_60 ) ;
F_75 ( 1020 ) ;
return V_56 ;
}
int F_76 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 * V_278 )
{
T_1 V_279 ;
if ( F_64 ( V_2 -> V_82 ) )
return - V_216 ;
V_279 = F_4 ( V_2 , V_6 , V_280 ) ;
V_279 = ( V_279 & V_281 ) >>
V_282 ;
V_279 = ( 1 << ( V_279 + V_283 ) ) ;
* V_278 = V_279 ;
return 0 ;
}
int F_77 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_2 V_284 , T_2 V_285 )
{
T_1 V_217 = 0 , V_60 = 0 , V_286 = 0 ;
int V_56 ;
if ( ! F_78 ( V_2 ) )
return 0 ;
V_285 *= V_2 -> V_82 -> V_287 ;
V_60 |= ( V_284 << V_288 ) &
V_289 ;
V_60 |= ( V_285 << V_290 ) &
V_291 ;
V_56 = F_33 ( V_2 , V_6 , V_292 , V_60 ,
& V_217 , & V_286 ) ;
if ( V_217 != V_293 ) {
F_18 ( V_2 , L_38 , V_284 ) ;
V_56 = - V_216 ;
} else {
F_7 ( V_2 , V_99 ,
L_39 ,
V_285 , V_284 ) ;
}
return V_56 ;
}
int
F_79 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_294 * V_295 )
{
struct V_296 * V_297 ;
struct V_70 V_79 ;
union V_83 V_74 ;
V_19 V_231 ;
T_1 V_15 ;
int V_56 ;
V_297 = & V_74 . V_298 ;
V_297 -> V_299 = V_295 -> V_299 ;
for ( V_15 = 0 ; V_15 < ( V_88 - 4 ) / sizeof( T_1 ) ; V_15 ++ ) {
V_231 = F_62 ( * ( ( T_1 * ) & V_295 -> V_300 [ V_15 * sizeof( T_1 ) ] ) ) ;
* ( V_19 * ) & V_297 -> V_300 [ V_15 * sizeof( T_1 ) ] = V_231 ;
}
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_44 = V_301 ;
V_79 . V_75 = & V_74 ;
V_56 = F_29 ( V_2 , V_6 , & V_79 ) ;
if ( V_56 )
F_27 ( V_2 , L_13 ) ;
return V_56 ;
}
int F_80 ( struct V_1 * V_2 , struct V_5 * V_6 ,
enum V_302 V_303 )
{
T_1 V_217 = 0 , V_60 = 0 , V_64 ;
int V_56 ;
switch ( V_303 ) {
case V_304 :
V_64 = V_305 ;
break;
case V_306 :
V_64 = V_307 ;
break;
case V_308 :
V_64 = V_309 ;
break;
default:
F_18 ( V_2 , L_40 , V_303 ) ;
return - V_216 ;
}
V_56 = F_33 ( V_2 , V_6 , V_310 ,
V_64 , & V_217 , & V_60 ) ;
return V_56 ;
}
int F_81 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_64 = 0 , V_311 , V_60 ;
int V_56 = 0 ;
V_64 = ( V_312 <<
V_313 ) ;
V_56 = F_33 ( V_2 , V_6 , V_314 ,
V_64 , & V_311 , & V_60 ) ;
if ( V_56 )
return V_56 ;
if ( ( ( V_311 & V_68 ) != V_315 ) ||
( V_60 != V_316 ) )
V_56 = - V_59 ;
return V_56 ;
}
int F_82 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 V_64 , V_311 , V_60 ;
int V_56 = 0 ;
V_64 = ( V_317 <<
V_313 ) ;
V_56 = F_33 ( V_2 , V_6 , V_314 ,
V_64 , & V_311 , & V_60 ) ;
if ( V_56 )
return V_56 ;
if ( ( ( V_311 & V_68 ) != V_315 ) ||
( V_60 != V_316 ) )
V_56 = - V_59 ;
return V_56 ;
}
