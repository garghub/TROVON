static void F_1 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
T_2 V_9 ;
if ( V_4 == V_6 -> V_4 )
return;
switch ( V_6 -> V_4 -> type ) {
case V_10 :
if ( V_4 -> type != V_11 ||
V_6 -> V_12 != V_13 ||
! F_3 ( V_8 -> V_14 , V_6 -> V_15 ) )
break;
V_9 = F_4 ( V_6 -> V_4 -> V_16 . V_17 ,
V_4 -> V_16 . V_17 ) ;
if ( ! V_9 )
break;
if ( ( V_6 -> V_4 -> V_16 . V_17 -
V_4 -> V_16 . V_17 ) % V_9 == 0 ) {
V_6 -> V_12 = V_8 -> V_14 ;
return;
}
break;
case V_11 :
if ( ( V_4 -> type != V_11 &&
V_4 -> type != V_10 ) ||
V_6 -> V_12 != V_13 ||
! F_3 ( V_8 -> V_14 , V_6 -> V_15 ) )
break;
V_9 = F_4 ( V_6 -> V_4 -> V_16 . V_17 ,
V_4 -> V_16 . V_17 ) ;
if ( ! V_9 )
break;
if ( ( V_6 -> V_4 -> V_16 . V_17 -
V_4 -> V_16 . V_17 ) % V_9 == 0 ) {
V_6 -> V_12 = V_8 -> V_14 ;
return;
}
break;
default:
break;
}
F_5 ( V_8 -> V_14 , V_6 -> V_15 ) ;
if ( V_6 -> V_12 == V_8 -> V_14 )
V_6 -> V_12 = V_13 ;
}
T_3 F_6 ( struct V_3 * V_4 )
{
T_3 V_18 = 0 , V_19 ;
if ( V_4 -> type == V_20 )
return F_7 ( V_21 ) ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
if ( V_4 -> V_23 [ V_19 ] != V_24 )
V_18 |= F_7 ( V_4 -> V_23 [ V_19 ] ) ;
}
if ( V_4 -> type == V_11 )
V_18 |= F_7 ( V_4 -> V_25 ) ;
return V_18 ;
}
static void F_8 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_26 * V_6 = V_1 ;
if ( V_4 == V_6 -> V_27 )
return;
V_6 -> V_28 |= F_6 ( V_4 ) ;
}
static void F_9 ( void * V_1 ,
struct V_29 * V_30 )
{
struct V_26 * V_6 = V_1 ;
struct V_31 * V_32 = F_10 ( V_30 ) ;
V_6 -> V_28 |= V_32 -> V_33 ;
}
unsigned long F_11 ( struct V_34 * V_35 ,
struct V_3 * V_27 )
{
T_1 V_36 ;
struct V_26 V_6 = {
. V_27 = V_27 ,
. V_28 =
F_7 ( V_21 ) |
F_7 ( V_35 -> V_37 ) |
F_7 ( V_38 ) ,
} ;
F_12 ( & V_35 -> V_39 ) ;
F_13 (
V_35 -> V_40 , V_41 ,
F_8 , & V_6 ) ;
F_14 ( V_35 -> V_40 ,
F_9 ,
& V_6 ) ;
F_15 (sta_id, mvm->sta_drained, IWL_MVM_STATION_COUNT)
V_6 . V_28 |= V_35 -> V_42 [ V_36 ] ;
return V_6 . V_28 ;
}
static void F_16 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 == V_6 -> V_4 ) {
V_6 -> V_43 = true ;
return;
}
F_5 ( V_8 -> V_44 , V_6 -> V_45 ) ;
F_1 ( V_1 , V_2 , V_4 ) ;
}
void F_17 ( struct V_34 * V_35 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_5 V_6 = {
. V_35 = V_35 ,
. V_4 = V_4 ,
. V_15 = { ( 1 << V_13 ) - 1 } ,
. V_12 = V_13 ,
} ;
F_13 (
V_35 -> V_40 , V_41 ,
F_1 , & V_6 ) ;
if ( V_6 . V_12 != V_13 )
V_8 -> V_14 = V_6 . V_12 ;
else if ( ! F_3 ( V_8 -> V_14 , V_6 . V_15 ) )
V_8 -> V_14 = F_18 ( V_6 . V_15 ,
V_13 ) ;
}
static int F_19 ( struct V_34 * V_35 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_5 V_6 = {
. V_35 = V_35 ,
. V_4 = V_4 ,
. V_45 = { ( 1 << V_46 ) - 1 } ,
. V_15 = { ( 1 << V_13 ) - 1 } ,
. V_12 = V_13 ,
. V_43 = false ,
} ;
T_3 V_19 ;
int V_47 , V_48 ;
unsigned long V_28 ;
switch ( V_4 -> type ) {
case V_49 :
break;
case V_10 :
if ( ! V_4 -> V_50 )
break;
default:
F_5 ( 0 , V_6 . V_45 ) ;
}
F_13 (
V_35 -> V_40 , V_41 ,
F_16 , & V_6 ) ;
V_28 = F_11 ( V_35 , V_4 ) ;
if ( V_6 . V_43 )
return 0 ;
if ( F_20 ( F_3 ( V_51 , & V_35 -> V_52 ) ) )
return - V_53 ;
V_8 -> V_44 = F_18 ( V_6 . V_45 ,
V_46 ) ;
if ( V_8 -> V_44 == V_46 ) {
F_21 ( V_35 , L_1 ) ;
V_47 = - V_54 ;
goto V_55;
}
if ( V_6 . V_12 != V_13 )
V_8 -> V_14 = V_6 . V_12 ;
else
V_8 -> V_14 = F_18 ( V_6 . V_15 ,
V_13 ) ;
if ( V_8 -> V_14 == V_13 ) {
F_21 ( V_35 , L_2 ) ;
V_47 = - V_54 ;
goto V_55;
}
V_8 -> V_56 = 0 ;
F_22 ( & V_8 -> V_57 . V_58 ) ;
V_8 -> V_57 . V_44 = V_59 ;
if ( V_4 -> type == V_20 ) {
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
V_4 -> V_23 [ V_19 ] = V_24 ;
return 0 ;
}
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
T_1 V_60 = F_23 ( & V_28 ,
V_35 -> V_61 ) ;
if ( V_60 >= V_35 -> V_61 ) {
F_21 ( V_35 , L_3 ) ;
V_47 = - V_54 ;
goto V_55;
}
F_24 ( V_60 , & V_28 ) ;
V_4 -> V_23 [ V_19 ] = V_60 ;
}
if ( V_4 -> type == V_11 ) {
T_1 V_60 = F_23 ( & V_28 ,
V_35 -> V_61 ) ;
if ( V_60 >= V_35 -> V_61 ) {
F_21 ( V_35 , L_4 ) ;
V_47 = - V_54 ;
goto V_55;
}
V_4 -> V_25 = V_60 ;
} else {
V_4 -> V_25 = V_24 ;
}
V_8 -> V_62 . V_36 = V_63 ;
V_8 -> V_64 = V_63 ;
for ( V_48 = 0 ; V_48 < V_65 ; V_48 ++ )
V_8 -> V_66 [ V_48 ] = V_67 ;
return 0 ;
V_55:
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
memset ( V_4 -> V_23 , V_24 , sizeof( V_4 -> V_23 ) ) ;
V_4 -> V_25 = V_24 ;
return V_47 ;
}
int F_25 ( struct V_34 * V_35 , struct V_3 * V_4 )
{
unsigned int V_68 =
F_26 ( V_35 , V_4 , false , false ) ;
T_3 V_19 ;
int V_47 ;
F_12 ( & V_35 -> V_39 ) ;
V_47 = F_19 ( V_35 , V_4 ) ;
if ( V_47 )
return V_47 ;
switch ( V_4 -> type ) {
case V_20 :
F_27 ( V_35 , V_21 ,
V_69 , V_68 ) ;
break;
case V_11 :
F_27 ( V_35 , V_4 -> V_25 ,
V_70 , V_68 ) ;
default:
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
F_27 ( V_35 , V_4 -> V_23 [ V_19 ] ,
V_71 [ V_19 ] ,
V_68 ) ;
break;
}
return 0 ;
}
void F_28 ( struct V_34 * V_35 , struct V_3 * V_4 )
{
int V_19 ;
F_12 ( & V_35 -> V_39 ) ;
switch ( V_4 -> type ) {
case V_20 :
F_29 ( V_35 , V_21 , 0 ) ;
break;
case V_11 :
F_29 ( V_35 , V_4 -> V_25 , 0 ) ;
default:
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
F_29 ( V_35 , V_4 -> V_23 [ V_19 ] , 0 ) ;
}
}
static void F_30 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
enum V_72 V_73 ,
T_1 * V_74 , T_1 * V_75 )
{
struct V_76 * V_77 ;
unsigned long V_78 = V_4 -> V_16 . V_79 ;
int V_80 = 100 ;
int V_81 = 100 ;
T_1 V_82 = 0 ;
T_1 V_83 = 0 ;
int V_48 ;
V_77 = V_35 -> V_40 -> V_84 -> V_85 [ V_73 ] ;
F_15 (i, &basic, BITS_PER_LONG) {
int V_40 = V_77 -> V_86 [ V_48 ] . V_87 ;
if ( V_40 >= V_88 ) {
V_83 |= F_7 ( V_40 - V_88 ) ;
if ( V_80 > V_40 )
V_80 = V_40 ;
} else {
F_31 ( V_89 != 0 ) ;
V_82 |= F_7 ( V_40 ) ;
if ( V_81 > V_40 )
V_81 = V_40 ;
}
}
if ( V_90 < V_80 )
V_83 |= F_32 ( 24 ) >> V_88 ;
if ( V_91 < V_80 )
V_83 |= F_32 ( 12 ) >> V_88 ;
V_83 |= F_32 ( 6 ) >> V_88 ;
if ( V_92 < V_81 )
V_82 |= F_32 ( 11 ) >> V_89 ;
if ( V_93 < V_81 )
V_82 |= F_32 ( 5 ) >> V_89 ;
if ( V_94 < V_81 )
V_82 |= F_32 ( 2 ) >> V_89 ;
V_82 |= F_32 ( 1 ) >> V_89 ;
* V_74 = V_82 ;
* V_75 = V_83 ;
}
static void F_33 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
struct V_95 * V_96 )
{
T_1 V_97 = V_4 -> V_16 . V_98 &
V_99 ;
T_3 V_100 = V_101 | V_102 ;
F_34 ( V_35 , L_5 , V_97 ) ;
switch ( V_97 ) {
case V_103 :
break;
case V_104 :
case V_105 :
V_96 -> V_106 |= F_35 ( V_100 ) ;
break;
case V_107 :
if ( V_4 -> V_16 . V_108 . V_109 > V_110 )
V_96 -> V_106 |= F_35 ( V_100 ) ;
break;
default:
F_21 ( V_35 , L_6 ,
V_97 ) ;
break;
}
}
static void F_36 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
struct V_95 * V_96 ,
const T_1 * V_111 ,
T_3 V_112 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_113 * V_114 ;
bool V_115 = ! ! ( V_4 -> V_16 . V_98 &
V_99 ) ;
T_1 V_116 , V_117 ;
const T_1 * V_118 = V_111 ? : V_4 -> V_16 . V_118 ;
int V_48 ;
V_96 -> V_119 = F_35 ( F_37 ( V_8 -> V_44 ,
V_8 -> V_56 ) ) ;
V_96 -> V_112 = F_35 ( V_112 ) ;
switch ( V_4 -> type ) {
case V_10 :
if ( V_4 -> V_50 )
V_96 -> V_120 = F_35 ( V_121 ) ;
else
V_96 -> V_120 = F_35 ( V_122 ) ;
break;
case V_11 :
V_96 -> V_120 = F_35 ( V_123 ) ;
break;
case V_124 :
V_96 -> V_120 = F_35 ( V_125 ) ;
break;
case V_20 :
V_96 -> V_120 = F_35 ( V_126 ) ;
break;
case V_49 :
V_96 -> V_120 = F_35 ( V_127 ) ;
break;
default:
F_20 ( 1 ) ;
}
V_96 -> V_14 = F_35 ( V_8 -> V_14 ) ;
memcpy ( V_96 -> V_128 , V_4 -> V_129 , V_130 ) ;
if ( V_118 )
memcpy ( V_96 -> V_131 , V_118 , V_130 ) ;
else
F_38 ( V_96 -> V_131 ) ;
F_39 () ;
V_114 = F_40 ( V_4 -> V_132 ) ;
F_30 ( V_35 , V_4 , V_114 ? V_114 -> V_133 . V_134 -> V_73
: V_135 ,
& V_116 , & V_117 ) ;
F_41 () ;
V_96 -> V_74 = F_35 ( ( T_3 ) V_116 ) ;
V_96 -> V_75 = F_35 ( ( T_3 ) V_117 ) ;
V_96 -> V_136 =
F_35 ( V_4 -> V_16 . V_137 ?
V_138 : 0 ) ;
V_96 -> V_139 =
F_35 ( V_4 -> V_16 . V_140 ?
V_141 : 0 ) ;
for ( V_48 = 0 ; V_48 < V_22 ; V_48 ++ ) {
T_1 V_142 = V_71 [ V_48 ] ;
V_96 -> V_19 [ V_142 ] . V_143 =
F_42 ( V_8 -> V_144 [ V_48 ] . V_143 ) ;
V_96 -> V_19 [ V_142 ] . V_145 =
F_42 ( V_8 -> V_144 [ V_48 ] . V_145 ) ;
V_96 -> V_19 [ V_142 ] . V_146 =
F_42 ( V_8 -> V_144 [ V_48 ] . V_147 * 32 ) ;
V_96 -> V_19 [ V_142 ] . V_148 = V_8 -> V_144 [ V_48 ] . V_149 ;
V_96 -> V_19 [ V_142 ] . V_150 = F_7 ( V_142 ) ;
}
if ( V_4 -> type == V_11 )
V_96 -> V_19 [ V_69 ] . V_150 |=
F_7 ( V_70 ) ;
if ( V_4 -> V_16 . V_151 )
V_96 -> V_152 |= F_35 ( V_153 ) ;
if ( V_4 -> V_16 . V_154 )
V_96 -> V_106 |= F_35 ( V_155 ) ;
F_34 ( V_35 , L_7 ,
V_4 -> V_16 . V_154 ,
V_4 -> V_16 . V_98 ) ;
if ( V_4 -> V_16 . V_108 . V_109 != V_156 )
V_96 -> V_152 |= F_35 ( V_157 ) ;
if ( V_115 )
F_33 ( V_35 , V_4 , V_96 ) ;
V_96 -> V_158 = F_35 ( V_159 ) ;
}
static int F_43 ( struct V_34 * V_35 ,
struct V_95 * V_96 )
{
int V_47 = F_44 ( V_35 , V_160 , 0 ,
sizeof( * V_96 ) , V_96 ) ;
if ( V_47 )
F_21 ( V_35 , L_8 ,
F_45 ( V_96 -> V_112 ) , V_47 ) ;
return V_47 ;
}
static int F_46 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_112 , bool V_161 ,
const T_1 * V_111 )
{
struct V_95 V_96 = {} ;
struct V_162 * V_163 ;
F_47 ( V_4 -> type != V_10 ) ;
F_36 ( V_35 , V_4 , & V_96 , V_111 , V_112 ) ;
if ( V_4 -> V_50 ) {
struct V_164 * V_165 =
& V_4 -> V_16 . V_166 ;
V_96 . V_167 . V_168 = F_35 ( V_165 -> V_169 &
V_170 ) ;
V_163 = & V_96 . V_167 . V_30 ;
} else {
V_163 = & V_96 . V_30 ;
}
if ( V_4 -> V_16 . V_171 && V_4 -> V_16 . V_172 &&
! V_161 ) {
T_3 V_173 ;
V_173 = V_4 -> V_16 . V_174 *
V_4 -> V_16 . V_17 ;
V_173 *= 1024 ;
V_163 -> V_175 =
F_48 ( V_4 -> V_16 . V_176 + V_173 ) ;
V_163 -> V_177 =
F_35 ( V_4 -> V_16 . V_178 + V_173 ) ;
F_49 ( V_35 , L_9 ,
F_50 ( V_163 -> V_175 ) ,
F_45 ( V_163 -> V_177 ) ,
V_173 ) ;
V_163 -> V_179 = F_35 ( 1 ) ;
} else {
V_163 -> V_179 = F_35 ( 0 ) ;
V_96 . V_158 |= F_35 ( V_180 ) ;
}
V_163 -> V_181 = F_35 ( V_4 -> V_16 . V_17 ) ;
V_163 -> V_182 =
F_35 ( F_51 ( V_4 -> V_16 . V_17 ) ) ;
V_163 -> V_183 = F_35 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_172 ) ;
V_163 -> V_184 =
F_35 ( F_51 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_172 ) ) ;
V_163 -> V_185 = F_35 ( V_35 -> V_40 -> V_186 . V_185 ) ;
V_163 -> V_187 = F_35 ( V_4 -> V_16 . V_188 ) ;
return F_43 ( V_35 , & V_96 ) ;
}
static int F_52 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_112 )
{
struct V_95 V_96 = {} ;
F_47 ( V_4 -> type != V_124 ) ;
F_36 ( V_35 , V_4 , & V_96 , NULL , V_112 ) ;
V_96 . V_158 = F_35 ( V_189 |
V_190 |
V_180 |
V_191 |
V_192 ) ;
F_53 ( V_35 -> V_40 , V_193 ) ;
return F_43 ( V_35 , & V_96 ) ;
}
static int F_54 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_112 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_95 V_96 = {} ;
F_47 ( V_4 -> type != V_49 ) ;
F_36 ( V_35 , V_4 , & V_96 , NULL , V_112 ) ;
V_96 . V_158 = F_35 ( V_180 |
V_191 ) ;
V_96 . V_194 . V_181 = F_35 ( V_4 -> V_16 . V_17 ) ;
V_96 . V_194 . V_182 =
F_35 ( F_51 ( V_4 -> V_16 . V_17 ) ) ;
V_96 . V_194 . V_195 = F_35 ( V_8 -> V_44 ) ;
return F_43 ( V_35 , & V_96 ) ;
}
static void F_55 ( void * V_1 , T_1 * V_2 , struct V_3 * V_4 )
{
struct V_196 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 -> type == V_11 && V_4 -> V_50 &&
V_8 -> V_197 )
V_6 -> V_198 = true ;
}
static int F_56 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_112 )
{
struct V_95 V_96 = {} ;
struct V_196 V_6 = {} ;
F_47 ( V_4 -> type != V_20 ) ;
F_36 ( V_35 , V_4 , & V_96 , NULL , V_112 ) ;
V_96 . V_106 |= F_35 ( V_155 ) ;
V_96 . V_158 = F_35 ( V_191 ) ;
F_13 (
V_35 -> V_40 , V_41 ,
F_55 , & V_6 ) ;
V_96 . V_199 . V_200 = F_35 ( V_6 . V_198 ? 1 : 0 ) ;
return F_43 ( V_35 , & V_96 ) ;
}
static void F_57 ( struct V_34 * V_35 ,
struct V_201 * V_202 ,
T_1 * V_203 , T_3 V_204 )
{
T_3 V_205 ;
struct V_206 * V_207 = (struct V_206 * ) V_203 ;
V_205 = V_207 -> V_208 . V_203 . V_209 - V_203 ;
while ( ( V_205 < ( V_204 - 2 ) ) &&
( V_203 [ V_205 ] != V_210 ) )
V_205 += V_203 [ V_205 + 1 ] + 2 ;
if ( ( V_205 < ( V_204 - 1 ) ) && ( V_203 [ V_205 ] == V_210 ) ) {
V_202 -> V_205 = F_35 ( V_205 ) ;
V_202 -> V_211 = F_35 ( ( T_3 ) V_203 [ V_205 + 1 ] ) ;
} else {
F_58 ( V_35 , L_10 ) ;
}
}
static int F_59 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
struct V_212 * V_203 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_213 V_96 = {
. V_44 = V_214 ,
. V_215 = V_216 ,
} ;
struct V_201 V_202 = {} ;
struct V_217 * V_218 ;
T_3 V_219 ;
T_3 V_220 , V_221 ;
if ( F_47 ( ! V_203 ) )
return - V_222 ;
V_219 = V_203 -> V_223 ;
V_202 . V_224 = F_35 ( ( T_3 ) V_8 -> V_44 ) ;
V_218 = F_60 ( V_203 ) ;
V_202 . V_225 . V_223 = F_42 ( ( T_2 ) V_219 ) ;
V_202 . V_225 . V_36 = V_8 -> V_62 . V_36 ;
V_202 . V_225 . V_226 = F_35 ( V_227 ) ;
V_221 = V_228 | V_229 ;
V_221 |=
F_61 ( V_35 , ( void * ) V_203 -> V_6 , V_218 , 0 ) <<
V_230 ;
V_202 . V_225 . V_221 = F_35 ( V_221 ) ;
V_35 -> V_231 =
F_62 ( V_35 , F_63 ( V_35 ) ,
V_35 -> V_231 ) ;
V_202 . V_225 . V_232 =
F_35 ( F_7 ( V_35 -> V_231 ) <<
V_233 ) ;
if ( V_218 -> V_73 == V_234 || V_4 -> V_50 ) {
V_220 = V_88 ;
} else {
V_220 = V_89 ;
V_202 . V_225 . V_232 |= F_35 ( V_235 ) ;
}
V_202 . V_225 . V_232 |=
F_35 ( F_64 ( V_220 ) ) ;
if ( V_4 -> type == V_11 )
F_57 ( V_35 , & V_202 ,
V_203 -> V_6 ,
V_219 ) ;
V_96 . V_223 [ 0 ] = sizeof( V_202 ) ;
V_96 . V_6 [ 0 ] = & V_202 ;
V_96 . V_236 [ 0 ] = 0 ;
V_96 . V_223 [ 1 ] = V_219 ;
V_96 . V_6 [ 1 ] = V_203 -> V_6 ;
V_96 . V_236 [ 1 ] = V_237 ;
return F_65 ( V_35 , & V_96 ) ;
}
int F_66 ( struct V_34 * V_35 ,
struct V_3 * V_4 )
{
struct V_212 * V_203 ;
int V_47 ;
F_47 ( V_4 -> type != V_11 &&
V_4 -> type != V_49 ) ;
V_203 = F_67 ( V_35 -> V_40 , V_4 , NULL ) ;
if ( ! V_203 )
return - V_238 ;
V_47 = F_59 ( V_35 , V_4 , V_203 ) ;
F_68 ( V_203 ) ;
return V_47 ;
}
static void F_69 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_239 * V_6 = V_1 ;
if ( V_4 -> type != V_10 || ! V_4 -> V_16 . V_171 )
return;
if ( V_4 -> V_50 && V_6 -> V_240 )
return;
V_6 -> V_240 = V_4 -> V_16 . V_178 ;
V_6 -> V_17 = V_4 -> V_16 . V_17 ;
}
static void F_70 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
struct V_241 * V_242 ,
bool V_243 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_239 V_6 = {
. V_35 = V_35 ,
. V_4 = V_4 ,
. V_240 = 0
} ;
V_242 -> V_181 = F_35 ( V_4 -> V_16 . V_17 ) ;
V_242 -> V_182 =
F_35 ( F_51 ( V_4 -> V_16 . V_17 ) ) ;
V_242 -> V_183 = F_35 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_172 ) ;
V_242 -> V_184 =
F_35 ( F_51 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_172 ) ) ;
V_242 -> V_244 = F_35 ( V_4 -> V_25 ) ;
if ( V_243 ) {
F_13 (
V_35 -> V_40 , V_41 ,
F_69 , & V_6 ) ;
if ( V_6 . V_240 ) {
T_3 rand = ( F_71 () % ( 64 - 36 ) ) + 36 ;
V_8 -> V_245 = V_6 . V_240 +
F_72 ( V_6 . V_17 * rand /
100 ) ;
} else {
V_8 -> V_245 =
F_73 ( V_35 -> V_246 ,
V_247 ) ;
}
}
V_242 -> V_248 = F_35 ( V_8 -> V_245 ) ;
V_242 -> V_249 = 0 ;
V_242 -> V_195 = F_35 ( V_8 -> V_44 ) ;
}
static int F_74 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_112 )
{
struct V_95 V_96 = {} ;
F_47 ( V_4 -> type != V_11 || V_4 -> V_50 ) ;
F_36 ( V_35 , V_4 , & V_96 , NULL , V_112 ) ;
V_96 . V_158 |= F_35 ( V_191 |
V_180 ) ;
F_70 ( V_35 , V_4 , & V_96 . V_250 ,
V_112 == V_251 ) ;
return F_43 ( V_35 , & V_96 ) ;
}
static int F_75 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_112 )
{
struct V_95 V_96 = {} ;
struct V_164 * V_165 = & V_4 -> V_16 . V_166 ;
F_47 ( V_4 -> type != V_11 || ! V_4 -> V_50 ) ;
F_36 ( V_35 , V_4 , & V_96 , NULL , V_112 ) ;
V_96 . V_158 |= F_35 ( V_191 |
V_180 ) ;
F_70 ( V_35 , V_4 , & V_96 . V_252 . V_250 ,
V_112 == V_251 ) ;
V_96 . V_252 . V_168 = F_35 ( V_165 -> V_169 &
V_170 ) ;
V_96 . V_252 . V_253 =
F_35 ( ! ! ( V_165 -> V_169 &
V_254 ) ) ;
return F_43 ( V_35 , & V_96 ) ;
}
static int F_76 ( struct V_34 * V_35 , struct V_3 * V_4 ,
T_3 V_112 , bool V_161 ,
const T_1 * V_111 )
{
switch ( V_4 -> type ) {
case V_10 :
return F_46 ( V_35 , V_4 , V_112 ,
V_161 ,
V_111 ) ;
break;
case V_11 :
if ( ! V_4 -> V_50 )
return F_74 ( V_35 , V_4 , V_112 ) ;
else
return F_75 ( V_35 , V_4 , V_112 ) ;
break;
case V_124 :
return F_52 ( V_35 , V_4 , V_112 ) ;
case V_20 :
return F_56 ( V_35 , V_4 , V_112 ) ;
case V_49 :
return F_54 ( V_35 , V_4 , V_112 ) ;
default:
break;
}
return - V_255 ;
}
int F_77 ( struct V_34 * V_35 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_47 ;
if ( F_78 ( V_8 -> V_256 , L_11 ,
V_4 -> V_129 , F_79 ( V_4 ) ) )
return - V_54 ;
V_47 = F_76 ( V_35 , V_4 , V_251 ,
true , NULL ) ;
if ( V_47 )
return V_47 ;
F_80 ( V_35 , V_4 ) ;
V_8 -> V_256 = true ;
return 0 ;
}
int F_81 ( struct V_34 * V_35 , struct V_3 * V_4 ,
bool V_161 , const T_1 * V_111 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( F_78 ( ! V_8 -> V_256 , L_12 ,
V_4 -> V_129 , F_79 ( V_4 ) ) )
return - V_54 ;
return F_76 ( V_35 , V_4 , V_257 ,
V_161 , V_111 ) ;
}
int F_82 ( struct V_34 * V_35 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_95 V_96 ;
int V_47 ;
if ( F_78 ( ! V_8 -> V_256 , L_13 ,
V_4 -> V_129 , F_79 ( V_4 ) ) )
return - V_54 ;
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_119 = F_35 ( F_37 ( V_8 -> V_44 ,
V_8 -> V_56 ) ) ;
V_96 . V_112 = F_35 ( V_258 ) ;
V_47 = F_44 ( V_35 , V_160 , 0 ,
sizeof( V_96 ) , & V_96 ) ;
if ( V_47 ) {
F_21 ( V_35 , L_14 , V_47 ) ;
return V_47 ;
}
V_8 -> V_256 = false ;
if ( V_4 -> type == V_124 )
F_5 ( V_259 , V_35 -> V_40 -> V_215 ) ;
return 0 ;
}
static void F_83 ( struct V_34 * V_35 ,
struct V_3 * V_260 , T_3 V_261 ,
bool V_262 )
{
struct V_7 * V_8 =
F_2 ( V_260 ) ;
if ( ! V_262 && ! V_8 -> V_263 )
return;
V_8 -> V_263 = true ;
if ( ! F_84 ( V_260 ) ) {
int V_264 = F_85 ( V_260 ) ;
F_66 ( V_35 , V_260 ) ;
if ( V_260 -> V_50 &&
! F_86 ( & V_8 -> V_57 ) && V_261 &&
V_262 ) {
T_3 V_265 = ( V_264 + 1 ) *
V_260 -> V_16 . V_17 -
V_266 ;
T_3 V_267 = V_261 + V_265 * 1024 ;
F_87 ( V_35 , V_260 ,
V_266 -
V_268 ,
V_267 ) ;
}
} else if ( ! F_86 ( & V_8 -> V_57 ) ) {
F_88 ( V_260 ) ;
F_89 ( V_35 -> V_260 , NULL ) ;
}
}
int F_90 ( struct V_34 * V_35 ,
struct V_269 * V_270 ,
struct V_271 * V_96 )
{
struct V_272 * V_273 = F_91 ( V_270 ) ;
struct V_274 * V_203 = ( void * ) V_273 -> V_6 ;
struct V_275 * V_276 ;
struct V_3 * V_260 ;
struct V_3 * V_277 ;
T_2 V_52 ;
F_12 ( & V_35 -> V_39 ) ;
V_276 = & V_203 -> V_276 ;
V_35 -> V_278 = F_45 ( V_203 -> V_261 ) ;
V_52 = F_92 ( V_276 -> V_52 . V_52 ) & V_279 ;
F_93 ( V_35 ,
L_15 ,
V_52 , V_276 -> V_280 ,
F_50 ( V_203 -> V_281 ) ,
V_35 -> V_278 ,
F_45 ( V_276 -> V_282 ) ) ;
V_260 = F_94 ( V_35 -> V_260 ,
F_95 ( & V_35 -> V_39 ) ) ;
if ( F_96 ( V_260 && V_260 -> V_283 ) )
F_83 ( V_35 , V_260 , V_35 -> V_278 ,
( V_52 == V_284 ) ) ;
V_277 = F_94 ( V_35 -> V_285 ,
F_95 ( & V_35 -> V_39 ) ) ;
if ( F_96 ( V_277 ) ) {
struct V_7 * V_8 =
F_2 ( V_277 ) ;
if ( ! V_35 -> V_286 )
V_35 -> V_286 =
V_287 ;
else
V_35 -> V_286 -- ;
if ( V_35 -> V_286 == 0 ) {
F_97 ( V_35 , V_8 , false ) ;
F_89 ( V_35 -> V_285 , NULL ) ;
}
}
return 0 ;
}
static void F_98 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_288 * V_289 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_34 * V_35 = V_8 -> V_35 ;
struct V_290 * V_291 ;
struct V_292 * V_293 ;
T_3 V_294 , V_295 ;
T_3 V_296 , V_297 ;
if ( V_8 -> V_44 != ( T_2 ) F_45 ( V_289 -> V_298 ) )
return;
V_296 = F_45 ( V_289 -> V_299 ) ;
V_297 =
F_45 ( V_289 -> V_300 ) ;
if ( F_45 ( V_289 -> V_300 ) >
V_301 )
F_99 ( V_4 ) ;
if ( ! F_100 ( V_35 -> V_302 ,
V_303 ) )
return;
V_293 = F_101 ( V_35 -> V_302 ,
V_303 ) ;
V_291 = ( void * ) V_293 -> V_6 ;
V_294 = F_45 ( V_291 -> V_304 ) ;
V_295 =
F_45 ( V_291 -> V_305 ) ;
if ( ! F_102 ( V_35 , V_4 , V_293 ) )
return;
if ( V_297 >= V_295 ||
V_296 >= V_294 )
F_103 ( V_35 , V_293 , NULL ) ;
}
int F_104 ( struct V_34 * V_35 ,
struct V_269 * V_270 ,
struct V_271 * V_96 )
{
struct V_272 * V_273 = F_91 ( V_270 ) ;
struct V_288 * V_306 = ( void * ) V_273 -> V_6 ;
F_49 ( V_35 ,
L_16 ,
F_45 ( V_306 -> V_298 ) ,
F_45 ( V_306 -> V_299 ) ,
F_45 ( V_306 -> V_300 ) ,
F_45 ( V_306 -> V_307 ) ,
F_45 ( V_306 -> V_308 ) ) ;
F_13 ( V_35 -> V_40 ,
V_309 ,
F_98 ,
V_306 ) ;
return 0 ;
}
