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
V_21 ,
V_69 , 0 , V_68 ) ;
break;
case V_11 :
F_27 ( V_35 , V_4 -> V_25 , V_4 -> V_25 ,
V_70 , 0 , V_68 ) ;
default:
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
F_27 ( V_35 , V_4 -> V_23 [ V_19 ] ,
V_4 -> V_23 [ V_19 ] ,
V_71 [ V_19 ] , 0 ,
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
F_29 ( V_35 , V_21 ,
V_21 , V_72 ,
0 ) ;
break;
case V_11 :
F_29 ( V_35 , V_4 -> V_25 , V_4 -> V_25 ,
V_72 , 0 ) ;
default:
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
F_29 ( V_35 , V_4 -> V_23 [ V_19 ] ,
V_4 -> V_23 [ V_19 ] ,
V_72 , 0 ) ;
}
}
static void F_30 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
enum V_73 V_74 ,
T_1 * V_75 , T_1 * V_76 )
{
struct V_77 * V_78 ;
unsigned long V_79 = V_4 -> V_16 . V_80 ;
int V_81 = 100 ;
int V_82 = 100 ;
T_1 V_83 = 0 ;
T_1 V_84 = 0 ;
int V_48 ;
V_78 = V_35 -> V_40 -> V_85 -> V_86 [ V_74 ] ;
F_15 (i, &basic, BITS_PER_LONG) {
int V_40 = V_78 -> V_87 [ V_48 ] . V_88 ;
if ( V_40 >= V_89 ) {
V_84 |= F_7 ( V_40 - V_89 ) ;
if ( V_81 > V_40 )
V_81 = V_40 ;
} else {
F_31 ( V_90 != 0 ) ;
V_83 |= F_7 ( V_40 ) ;
if ( V_82 > V_40 )
V_82 = V_40 ;
}
}
if ( V_91 < V_81 )
V_84 |= F_32 ( 24 ) >> V_89 ;
if ( V_92 < V_81 )
V_84 |= F_32 ( 12 ) >> V_89 ;
V_84 |= F_32 ( 6 ) >> V_89 ;
if ( V_93 < V_82 )
V_83 |= F_32 ( 11 ) >> V_90 ;
if ( V_94 < V_82 )
V_83 |= F_32 ( 5 ) >> V_90 ;
if ( V_95 < V_82 )
V_83 |= F_32 ( 2 ) >> V_90 ;
V_83 |= F_32 ( 1 ) >> V_90 ;
* V_75 = V_83 ;
* V_76 = V_84 ;
}
static void F_33 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
struct V_96 * V_97 )
{
T_1 V_98 = V_4 -> V_16 . V_99 &
V_100 ;
T_3 V_101 = V_102 | V_103 ;
F_34 ( V_35 , L_5 , V_98 ) ;
switch ( V_98 ) {
case V_104 :
break;
case V_105 :
case V_106 :
V_97 -> V_107 |= F_35 ( V_101 ) ;
break;
case V_108 :
if ( V_4 -> V_16 . V_109 . V_110 > V_111 )
V_97 -> V_107 |= F_35 ( V_101 ) ;
break;
default:
F_21 ( V_35 , L_6 ,
V_98 ) ;
break;
}
}
static void F_36 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
struct V_96 * V_97 ,
const T_1 * V_112 ,
T_3 V_113 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_114 * V_115 ;
bool V_116 = ! ! ( V_4 -> V_16 . V_99 &
V_100 ) ;
T_1 V_117 , V_118 ;
const T_1 * V_119 = V_112 ? : V_4 -> V_16 . V_119 ;
int V_48 ;
V_97 -> V_120 = F_35 ( F_37 ( V_8 -> V_44 ,
V_8 -> V_56 ) ) ;
V_97 -> V_113 = F_35 ( V_113 ) ;
switch ( V_4 -> type ) {
case V_10 :
if ( V_4 -> V_50 )
V_97 -> V_121 = F_35 ( V_122 ) ;
else
V_97 -> V_121 = F_35 ( V_123 ) ;
break;
case V_11 :
V_97 -> V_121 = F_35 ( V_124 ) ;
break;
case V_125 :
V_97 -> V_121 = F_35 ( V_126 ) ;
break;
case V_20 :
V_97 -> V_121 = F_35 ( V_127 ) ;
break;
case V_49 :
V_97 -> V_121 = F_35 ( V_128 ) ;
break;
default:
F_20 ( 1 ) ;
}
V_97 -> V_14 = F_35 ( V_8 -> V_14 ) ;
memcpy ( V_97 -> V_129 , V_4 -> V_130 , V_131 ) ;
if ( V_119 )
memcpy ( V_97 -> V_132 , V_119 , V_131 ) ;
else
F_38 ( V_97 -> V_132 ) ;
F_39 () ;
V_115 = F_40 ( V_4 -> V_133 ) ;
F_30 ( V_35 , V_4 , V_115 ? V_115 -> V_134 . V_135 -> V_74
: V_136 ,
& V_117 , & V_118 ) ;
F_41 () ;
V_97 -> V_75 = F_35 ( ( T_3 ) V_117 ) ;
V_97 -> V_76 = F_35 ( ( T_3 ) V_118 ) ;
V_97 -> V_137 =
F_35 ( V_4 -> V_16 . V_138 ?
V_139 : 0 ) ;
V_97 -> V_140 =
F_35 ( V_4 -> V_16 . V_141 ?
V_142 : 0 ) ;
for ( V_48 = 0 ; V_48 < V_22 ; V_48 ++ ) {
T_1 V_143 = V_71 [ V_48 ] ;
V_97 -> V_19 [ V_143 ] . V_144 =
F_42 ( V_8 -> V_145 [ V_48 ] . V_144 ) ;
V_97 -> V_19 [ V_143 ] . V_146 =
F_42 ( V_8 -> V_145 [ V_48 ] . V_146 ) ;
V_97 -> V_19 [ V_143 ] . V_147 =
F_42 ( V_8 -> V_145 [ V_48 ] . V_148 * 32 ) ;
V_97 -> V_19 [ V_143 ] . V_149 = V_8 -> V_145 [ V_48 ] . V_150 ;
V_97 -> V_19 [ V_143 ] . V_151 = F_7 ( V_143 ) ;
}
if ( V_4 -> type == V_11 )
V_97 -> V_19 [ V_69 ] . V_151 |=
F_7 ( V_70 ) ;
if ( V_4 -> V_16 . V_152 )
V_97 -> V_153 |= F_35 ( V_154 ) ;
if ( V_4 -> V_16 . V_155 )
V_97 -> V_107 |= F_35 ( V_156 ) ;
F_34 ( V_35 , L_7 ,
V_4 -> V_16 . V_155 ,
V_4 -> V_16 . V_99 ) ;
if ( V_4 -> V_16 . V_109 . V_110 != V_157 )
V_97 -> V_153 |= F_35 ( V_158 ) ;
if ( V_116 )
F_33 ( V_35 , V_4 , V_97 ) ;
V_97 -> V_159 = F_35 ( V_160 ) ;
}
static int F_43 ( struct V_34 * V_35 ,
struct V_96 * V_97 )
{
int V_47 = F_44 ( V_35 , V_161 , 0 ,
sizeof( * V_97 ) , V_97 ) ;
if ( V_47 )
F_21 ( V_35 , L_8 ,
F_45 ( V_97 -> V_113 ) , V_47 ) ;
return V_47 ;
}
static int F_46 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_113 , bool V_162 ,
const T_1 * V_112 )
{
struct V_96 V_97 = {} ;
struct V_163 * V_164 ;
F_47 ( V_4 -> type != V_10 ) ;
F_36 ( V_35 , V_4 , & V_97 , V_112 , V_113 ) ;
if ( V_4 -> V_50 ) {
struct V_165 * V_166 =
& V_4 -> V_16 . V_167 ;
V_97 . V_168 . V_169 = F_35 ( V_166 -> V_170 &
V_171 ) ;
V_164 = & V_97 . V_168 . V_30 ;
} else {
V_164 = & V_97 . V_30 ;
}
if ( V_4 -> V_16 . V_172 && V_4 -> V_16 . V_173 &&
! V_162 ) {
T_3 V_174 ;
V_174 = V_4 -> V_16 . V_175 *
V_4 -> V_16 . V_17 ;
V_174 *= 1024 ;
V_164 -> V_176 =
F_48 ( V_4 -> V_16 . V_177 + V_174 ) ;
V_164 -> V_178 =
F_35 ( V_4 -> V_16 . V_179 + V_174 ) ;
F_49 ( V_35 , L_9 ,
F_50 ( V_164 -> V_176 ) ,
F_45 ( V_164 -> V_178 ) ,
V_174 ) ;
V_164 -> V_180 = F_35 ( 1 ) ;
} else {
V_164 -> V_180 = F_35 ( 0 ) ;
V_97 . V_159 |= F_35 ( V_181 ) ;
}
V_164 -> V_182 = F_35 ( V_4 -> V_16 . V_17 ) ;
V_164 -> V_183 =
F_35 ( F_51 ( V_4 -> V_16 . V_17 ) ) ;
V_164 -> V_184 = F_35 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_173 ) ;
V_164 -> V_185 =
F_35 ( F_51 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_173 ) ) ;
V_164 -> V_186 = F_35 ( V_35 -> V_40 -> V_187 . V_186 ) ;
V_164 -> V_188 = F_35 ( V_4 -> V_16 . V_189 ) ;
if ( V_4 -> V_190 && V_4 -> V_16 . V_172 && V_4 -> V_50 )
V_97 . V_159 |= F_35 ( V_191 ) ;
return F_43 ( V_35 , & V_97 ) ;
}
static int F_52 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_113 )
{
struct V_96 V_97 = {} ;
F_47 ( V_4 -> type != V_125 ) ;
F_36 ( V_35 , V_4 , & V_97 , NULL , V_113 ) ;
V_97 . V_159 = F_35 ( V_192 |
V_193 |
V_181 |
V_191 |
V_194 ) ;
F_53 ( V_35 -> V_40 , V_195 ) ;
return F_43 ( V_35 , & V_97 ) ;
}
static int F_54 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_113 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_96 V_97 = {} ;
F_47 ( V_4 -> type != V_49 ) ;
F_36 ( V_35 , V_4 , & V_97 , NULL , V_113 ) ;
V_97 . V_159 = F_35 ( V_181 |
V_191 ) ;
V_97 . V_196 . V_182 = F_35 ( V_4 -> V_16 . V_17 ) ;
V_97 . V_196 . V_183 =
F_35 ( F_51 ( V_4 -> V_16 . V_17 ) ) ;
V_97 . V_196 . V_197 = F_35 ( V_8 -> V_44 ) ;
return F_43 ( V_35 , & V_97 ) ;
}
static void F_55 ( void * V_1 , T_1 * V_2 , struct V_3 * V_4 )
{
struct V_198 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 -> type == V_11 && V_4 -> V_50 &&
V_8 -> V_199 )
V_6 -> V_200 = true ;
}
static int F_56 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_113 )
{
struct V_96 V_97 = {} ;
struct V_198 V_6 = {} ;
F_47 ( V_4 -> type != V_20 ) ;
F_36 ( V_35 , V_4 , & V_97 , NULL , V_113 ) ;
V_97 . V_107 |= F_35 ( V_156 ) ;
V_97 . V_159 = F_35 ( V_191 ) ;
F_13 (
V_35 -> V_40 , V_41 ,
F_55 , & V_6 ) ;
V_97 . V_201 . V_202 = F_35 ( V_6 . V_200 ? 1 : 0 ) ;
return F_43 ( V_35 , & V_97 ) ;
}
static void F_57 ( struct V_34 * V_35 ,
struct V_203 * V_204 ,
T_1 * V_205 , T_3 V_206 )
{
T_3 V_207 ;
struct V_208 * V_209 = (struct V_208 * ) V_205 ;
V_207 = V_209 -> V_210 . V_205 . V_211 - V_205 ;
while ( ( V_207 < ( V_206 - 2 ) ) &&
( V_205 [ V_207 ] != V_212 ) )
V_207 += V_205 [ V_207 + 1 ] + 2 ;
if ( ( V_207 < ( V_206 - 1 ) ) && ( V_205 [ V_207 ] == V_212 ) ) {
V_204 -> V_207 = F_35 ( V_207 ) ;
V_204 -> V_213 = F_35 ( ( T_3 ) V_205 [ V_207 + 1 ] ) ;
} else {
F_58 ( V_35 , L_10 ) ;
}
}
static int F_59 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
struct V_214 * V_205 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_215 V_97 = {
. V_44 = V_216 ,
. V_217 = V_218 ,
} ;
struct V_203 V_204 = {} ;
struct V_219 * V_220 ;
T_3 V_221 ;
T_3 V_222 , V_223 ;
if ( F_47 ( ! V_205 ) )
return - V_224 ;
V_221 = V_205 -> V_225 ;
V_204 . V_226 = F_35 ( ( T_3 ) V_8 -> V_44 ) ;
V_220 = F_60 ( V_205 ) ;
V_204 . V_227 . V_225 = F_42 ( ( T_2 ) V_221 ) ;
V_204 . V_227 . V_36 = V_8 -> V_62 . V_36 ;
V_204 . V_227 . V_228 = F_35 ( V_229 ) ;
V_223 = V_230 | V_231 ;
V_223 |=
F_61 ( V_35 , ( void * ) V_205 -> V_6 , V_220 , 0 ) <<
V_232 ;
V_204 . V_227 . V_223 = F_35 ( V_223 ) ;
V_35 -> V_233 =
F_62 ( V_35 , F_63 ( V_35 ) ,
V_35 -> V_233 ) ;
V_204 . V_227 . V_234 =
F_35 ( F_7 ( V_35 -> V_233 ) <<
V_235 ) ;
if ( V_220 -> V_74 == V_236 || V_4 -> V_50 ) {
V_222 = V_89 ;
} else {
V_222 = V_90 ;
V_204 . V_227 . V_234 |= F_35 ( V_237 ) ;
}
V_204 . V_227 . V_234 |=
F_35 ( F_64 ( V_222 ) ) ;
if ( V_4 -> type == V_11 )
F_57 ( V_35 , & V_204 ,
V_205 -> V_6 ,
V_221 ) ;
V_97 . V_225 [ 0 ] = sizeof( V_204 ) ;
V_97 . V_6 [ 0 ] = & V_204 ;
V_97 . V_238 [ 0 ] = 0 ;
V_97 . V_225 [ 1 ] = V_221 ;
V_97 . V_6 [ 1 ] = V_205 -> V_6 ;
V_97 . V_238 [ 1 ] = V_239 ;
return F_65 ( V_35 , & V_97 ) ;
}
int F_66 ( struct V_34 * V_35 ,
struct V_3 * V_4 )
{
struct V_214 * V_205 ;
int V_47 ;
F_47 ( V_4 -> type != V_11 &&
V_4 -> type != V_49 ) ;
V_205 = F_67 ( V_35 -> V_40 , V_4 , NULL ) ;
if ( ! V_205 )
return - V_240 ;
V_47 = F_59 ( V_35 , V_4 , V_205 ) ;
F_68 ( V_205 ) ;
return V_47 ;
}
static void F_69 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_241 * V_6 = V_1 ;
if ( V_4 -> type != V_10 || ! V_4 -> V_16 . V_172 )
return;
if ( V_4 -> V_50 && V_6 -> V_242 )
return;
V_6 -> V_242 = V_4 -> V_16 . V_179 ;
V_6 -> V_17 = V_4 -> V_16 . V_17 ;
}
static void F_70 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
struct V_243 * V_244 ,
bool V_245 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_241 V_6 = {
. V_35 = V_35 ,
. V_4 = V_4 ,
. V_242 = 0
} ;
V_244 -> V_182 = F_35 ( V_4 -> V_16 . V_17 ) ;
V_244 -> V_183 =
F_35 ( F_51 ( V_4 -> V_16 . V_17 ) ) ;
V_244 -> V_184 = F_35 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_173 ) ;
V_244 -> V_185 =
F_35 ( F_51 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_173 ) ) ;
V_244 -> V_246 = F_35 ( V_4 -> V_25 ) ;
if ( V_245 ) {
F_13 (
V_35 -> V_40 , V_41 ,
F_69 , & V_6 ) ;
if ( V_6 . V_242 ) {
T_3 rand = ( F_71 () % ( 64 - 36 ) ) + 36 ;
V_8 -> V_247 = V_6 . V_242 +
F_72 ( V_6 . V_17 * rand /
100 ) ;
} else {
V_8 -> V_247 =
F_73 ( V_35 -> V_248 ,
V_249 ) ;
}
}
V_244 -> V_250 = F_35 ( V_8 -> V_247 ) ;
V_244 -> V_251 = 0 ;
V_244 -> V_197 = F_35 ( V_8 -> V_44 ) ;
}
static int F_74 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_113 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_96 V_97 = {} ;
F_47 ( V_4 -> type != V_11 || V_4 -> V_50 ) ;
F_36 ( V_35 , V_4 , & V_97 , NULL , V_113 ) ;
V_97 . V_159 |= F_35 ( V_191 ) ;
if ( V_8 -> V_252 ) {
V_97 . V_159 |= F_35 ( V_181 ) ;
F_75 ( V_35 , L_11 ) ;
} else {
F_75 ( V_35 , L_12 ) ;
}
F_70 ( V_35 , V_4 , & V_97 . V_253 ,
V_113 == V_254 ) ;
return F_43 ( V_35 , & V_97 ) ;
}
static int F_76 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_113 )
{
struct V_96 V_97 = {} ;
struct V_165 * V_166 = & V_4 -> V_16 . V_167 ;
F_47 ( V_4 -> type != V_11 || ! V_4 -> V_50 ) ;
F_36 ( V_35 , V_4 , & V_97 , NULL , V_113 ) ;
V_97 . V_159 |= F_35 ( V_191 |
V_181 ) ;
F_70 ( V_35 , V_4 , & V_97 . V_255 . V_253 ,
V_113 == V_254 ) ;
V_97 . V_255 . V_169 = F_35 ( V_166 -> V_170 &
V_171 ) ;
V_97 . V_255 . V_256 =
F_35 ( ! ! ( V_166 -> V_170 &
V_257 ) ) ;
return F_43 ( V_35 , & V_97 ) ;
}
static int F_77 ( struct V_34 * V_35 , struct V_3 * V_4 ,
T_3 V_113 , bool V_162 ,
const T_1 * V_112 )
{
switch ( V_4 -> type ) {
case V_10 :
return F_46 ( V_35 , V_4 , V_113 ,
V_162 ,
V_112 ) ;
break;
case V_11 :
if ( ! V_4 -> V_50 )
return F_74 ( V_35 , V_4 , V_113 ) ;
else
return F_76 ( V_35 , V_4 , V_113 ) ;
break;
case V_125 :
return F_52 ( V_35 , V_4 , V_113 ) ;
case V_20 :
return F_56 ( V_35 , V_4 , V_113 ) ;
case V_49 :
return F_54 ( V_35 , V_4 , V_113 ) ;
default:
break;
}
return - V_258 ;
}
int F_78 ( struct V_34 * V_35 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_47 ;
if ( F_79 ( V_8 -> V_259 , L_13 ,
V_4 -> V_130 , F_80 ( V_4 ) ) )
return - V_54 ;
V_47 = F_77 ( V_35 , V_4 , V_254 ,
true , NULL ) ;
if ( V_47 )
return V_47 ;
F_81 ( V_35 , V_4 ) ;
V_8 -> V_259 = true ;
return 0 ;
}
int F_82 ( struct V_34 * V_35 , struct V_3 * V_4 ,
bool V_162 , const T_1 * V_112 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( F_79 ( ! V_8 -> V_259 , L_14 ,
V_4 -> V_130 , F_80 ( V_4 ) ) )
return - V_54 ;
return F_77 ( V_35 , V_4 , V_260 ,
V_162 , V_112 ) ;
}
int F_83 ( struct V_34 * V_35 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_96 V_97 ;
int V_47 ;
if ( F_79 ( ! V_8 -> V_259 , L_15 ,
V_4 -> V_130 , F_80 ( V_4 ) ) )
return - V_54 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_120 = F_35 ( F_37 ( V_8 -> V_44 ,
V_8 -> V_56 ) ) ;
V_97 . V_113 = F_35 ( V_261 ) ;
V_47 = F_44 ( V_35 , V_161 , 0 ,
sizeof( V_97 ) , & V_97 ) ;
if ( V_47 ) {
F_21 ( V_35 , L_16 , V_47 ) ;
return V_47 ;
}
V_8 -> V_259 = false ;
if ( V_4 -> type == V_125 )
F_5 ( V_262 , V_35 -> V_40 -> V_217 ) ;
return 0 ;
}
static void F_84 ( struct V_34 * V_35 ,
struct V_3 * V_263 , T_3 V_264 ,
bool V_265 )
{
struct V_7 * V_8 =
F_2 ( V_263 ) ;
if ( ! V_265 && ! V_8 -> V_266 )
return;
V_8 -> V_266 = true ;
if ( ! F_85 ( V_263 ) ) {
int V_267 = F_86 ( V_263 ) ;
F_66 ( V_35 , V_263 ) ;
if ( V_263 -> V_50 &&
! F_87 ( & V_8 -> V_57 ) && V_264 &&
V_265 ) {
T_3 V_268 = ( V_267 + 1 ) *
V_263 -> V_16 . V_17 -
V_269 ;
T_3 V_270 = V_264 + V_268 * 1024 ;
F_88 ( V_35 , V_263 ,
V_269 -
V_271 ,
V_270 ) ;
}
} else if ( ! F_87 ( & V_8 -> V_57 ) ) {
F_89 ( V_263 ) ;
F_90 ( V_35 -> V_263 , NULL ) ;
}
}
void F_91 ( struct V_34 * V_35 ,
struct V_272 * V_273 )
{
struct V_274 * V_275 = F_92 ( V_273 ) ;
struct V_276 * V_205 = ( void * ) V_275 -> V_6 ;
struct V_277 * V_278 ;
struct V_3 * V_263 ;
struct V_3 * V_279 ;
T_2 V_52 ;
F_12 ( & V_35 -> V_39 ) ;
V_278 = & V_205 -> V_278 ;
V_35 -> V_280 = F_45 ( V_205 -> V_264 ) ;
V_52 = F_93 ( V_278 -> V_52 . V_52 ) & V_281 ;
F_94 ( V_35 ,
L_17 ,
V_52 , V_278 -> V_282 ,
F_50 ( V_205 -> V_283 ) ,
V_35 -> V_280 ,
F_45 ( V_278 -> V_284 ) ) ;
V_263 = F_95 ( V_35 -> V_263 ,
F_96 ( & V_35 -> V_39 ) ) ;
if ( F_97 ( V_263 && V_263 -> V_285 ) )
F_84 ( V_35 , V_263 , V_35 -> V_280 ,
( V_52 == V_286 ) ) ;
V_279 = F_95 ( V_35 -> V_287 ,
F_96 ( & V_35 -> V_39 ) ) ;
if ( F_97 ( V_279 ) ) {
struct V_7 * V_8 =
F_2 ( V_279 ) ;
if ( ! V_35 -> V_288 )
V_35 -> V_288 =
V_289 ;
else
V_35 -> V_288 -- ;
if ( V_35 -> V_288 == 0 ) {
F_98 ( V_35 , V_8 , false ) ;
F_90 ( V_35 -> V_287 , NULL ) ;
}
}
}
static void F_99 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_290 * V_291 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_34 * V_35 = V_8 -> V_35 ;
struct V_292 * V_293 ;
struct V_294 * V_295 ;
T_3 V_296 , V_297 ;
T_3 V_298 , V_299 ;
if ( V_8 -> V_44 != ( T_2 ) F_45 ( V_291 -> V_300 ) )
return;
V_298 = F_45 ( V_291 -> V_301 ) ;
V_299 =
F_45 ( V_291 -> V_302 ) ;
if ( F_45 ( V_291 -> V_302 ) >
V_303 )
F_100 ( V_4 ) ;
if ( ! F_101 ( V_35 -> V_304 ,
V_305 ) )
return;
V_295 = F_102 ( V_35 -> V_304 ,
V_305 ) ;
V_293 = ( void * ) V_295 -> V_6 ;
V_296 = F_45 ( V_293 -> V_306 ) ;
V_297 =
F_45 ( V_293 -> V_307 ) ;
if ( ! F_103 ( V_35 , V_4 , V_295 ) )
return;
if ( V_299 >= V_297 ||
V_298 >= V_296 )
F_104 ( V_35 , V_295 , NULL ) ;
}
void F_105 ( struct V_34 * V_35 ,
struct V_272 * V_273 )
{
struct V_274 * V_275 = F_92 ( V_273 ) ;
struct V_290 * V_308 = ( void * ) V_275 -> V_6 ;
F_49 ( V_35 ,
L_18 ,
F_45 ( V_308 -> V_300 ) ,
F_45 ( V_308 -> V_301 ) ,
F_45 ( V_308 -> V_302 ) ,
F_45 ( V_308 -> V_309 ) ,
F_45 ( V_308 -> V_310 ) ) ;
F_13 ( V_35 -> V_40 ,
V_311 ,
F_99 ,
V_308 ) ;
}
