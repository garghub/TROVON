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
V_97 -> V_143 = F_35 ( V_144 ) ;
for ( V_48 = 0 ; V_48 < V_22 ; V_48 ++ ) {
T_1 V_145 = V_71 [ V_48 ] ;
V_97 -> V_19 [ V_145 ] . V_146 =
F_42 ( V_8 -> V_147 [ V_48 ] . V_146 ) ;
V_97 -> V_19 [ V_145 ] . V_148 =
F_42 ( V_8 -> V_147 [ V_48 ] . V_148 ) ;
V_97 -> V_19 [ V_145 ] . V_149 =
F_42 ( V_8 -> V_147 [ V_48 ] . V_150 * 32 ) ;
V_97 -> V_19 [ V_145 ] . V_151 = V_8 -> V_147 [ V_48 ] . V_152 ;
V_97 -> V_19 [ V_145 ] . V_153 = F_7 ( V_145 ) ;
}
if ( V_4 -> type == V_11 ) {
V_97 -> V_19 [ V_69 ] . V_153 |=
F_7 ( V_70 ) ;
V_97 -> V_143 |= F_35 ( V_154 ) ;
if ( V_8 -> V_155 || ! V_35 -> V_156 ) {
V_97 -> V_143 |= F_35 ( V_157 ) ;
F_43 ( V_35 , L_7 ) ;
} else {
F_43 ( V_35 , L_8 ) ;
}
}
if ( V_4 -> V_16 . V_158 )
V_97 -> V_159 |= F_35 ( V_160 ) ;
if ( V_4 -> V_16 . V_161 )
V_97 -> V_107 |= F_35 ( V_162 ) ;
F_34 ( V_35 , L_9 ,
V_4 -> V_16 . V_161 ,
V_4 -> V_16 . V_99 ) ;
if ( V_4 -> V_16 . V_109 . V_110 != V_163 )
V_97 -> V_159 |= F_35 ( V_164 ) ;
if ( V_116 )
F_33 ( V_35 , V_4 , V_97 ) ;
}
static int F_44 ( struct V_34 * V_35 ,
struct V_96 * V_97 )
{
int V_47 = F_45 ( V_35 , V_165 , 0 ,
sizeof( * V_97 ) , V_97 ) ;
if ( V_47 )
F_21 ( V_35 , L_10 ,
F_46 ( V_97 -> V_113 ) , V_47 ) ;
return V_47 ;
}
static int F_47 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_113 , bool V_166 ,
const T_1 * V_112 )
{
struct V_96 V_97 = {} ;
struct V_167 * V_168 ;
F_48 ( V_4 -> type != V_10 ) ;
F_36 ( V_35 , V_4 , & V_97 , V_112 , V_113 ) ;
if ( V_4 -> V_50 ) {
struct V_169 * V_170 =
& V_4 -> V_16 . V_171 ;
V_97 . V_172 . V_173 = F_35 ( V_170 -> V_174 &
V_175 ) ;
V_168 = & V_97 . V_172 . V_30 ;
} else {
V_168 = & V_97 . V_30 ;
}
if ( V_4 -> V_16 . V_176 && V_4 -> V_16 . V_177 &&
! V_166 ) {
T_3 V_178 ;
V_178 = V_4 -> V_16 . V_179 *
V_4 -> V_16 . V_17 ;
V_178 *= 1024 ;
V_168 -> V_180 =
F_49 ( V_4 -> V_16 . V_181 + V_178 ) ;
V_168 -> V_182 =
F_35 ( V_4 -> V_16 . V_183 + V_178 ) ;
F_50 ( V_35 , L_11 ,
F_51 ( V_168 -> V_180 ) ,
F_46 ( V_168 -> V_182 ) ,
V_178 ) ;
V_168 -> V_184 = F_35 ( 1 ) ;
} else {
V_168 -> V_184 = F_35 ( 0 ) ;
V_97 . V_143 |= F_35 ( V_157 ) ;
}
V_168 -> V_185 = F_35 ( V_4 -> V_16 . V_17 ) ;
V_168 -> V_186 =
F_35 ( F_52 ( V_4 -> V_16 . V_17 ) ) ;
V_168 -> V_187 = F_35 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_177 ) ;
V_168 -> V_188 =
F_35 ( F_52 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_177 ) ) ;
V_168 -> V_189 = F_35 ( V_35 -> V_40 -> V_190 . V_189 ) ;
V_168 -> V_191 = F_35 ( V_4 -> V_16 . V_192 ) ;
if ( V_4 -> V_193 && V_4 -> V_16 . V_176 && V_4 -> V_50 )
V_97 . V_143 |= F_35 ( V_154 ) ;
return F_44 ( V_35 , & V_97 ) ;
}
static int F_53 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_113 )
{
struct V_96 V_97 = {} ;
T_3 V_33 = 0 ;
int V_47 , V_48 ;
F_48 ( V_4 -> type != V_125 ) ;
F_36 ( V_35 , V_4 , & V_97 , NULL , V_113 ) ;
for ( V_48 = 0 ; V_48 < V_22 ; V_48 ++ )
if ( V_4 -> V_23 [ V_48 ] != V_24 )
V_33 |= F_7 ( V_4 -> V_23 [ V_48 ] ) ;
V_97 . V_143 = F_35 ( V_194 |
V_195 |
V_157 |
V_154 |
V_196 ) ;
F_54 ( V_35 -> V_40 , V_197 ) ;
V_47 = F_55 ( V_35 , & V_35 -> V_198 , V_33 ,
V_4 -> type ) ;
if ( V_47 )
return V_47 ;
return F_44 ( V_35 , & V_97 ) ;
}
static int F_56 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_113 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_96 V_97 = {} ;
F_48 ( V_4 -> type != V_49 ) ;
F_36 ( V_35 , V_4 , & V_97 , NULL , V_113 ) ;
V_97 . V_143 = F_35 ( V_157 |
V_154 ) ;
V_97 . V_199 . V_185 = F_35 ( V_4 -> V_16 . V_17 ) ;
V_97 . V_199 . V_186 =
F_35 ( F_52 ( V_4 -> V_16 . V_17 ) ) ;
V_97 . V_199 . V_200 = F_35 ( V_8 -> V_44 ) ;
return F_44 ( V_35 , & V_97 ) ;
}
static void F_57 ( void * V_1 , T_1 * V_2 , struct V_3 * V_4 )
{
struct V_201 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 -> type == V_11 && V_4 -> V_50 &&
V_8 -> V_202 )
V_6 -> V_203 = true ;
}
static int F_58 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_113 )
{
struct V_96 V_97 = {} ;
struct V_201 V_6 = {} ;
F_48 ( V_4 -> type != V_20 ) ;
F_36 ( V_35 , V_4 , & V_97 , NULL , V_113 ) ;
V_97 . V_107 |= F_35 ( V_162 ) ;
V_97 . V_143 = F_35 ( V_154 ) ;
F_13 (
V_35 -> V_40 , V_41 ,
F_57 , & V_6 ) ;
V_97 . V_204 . V_205 = F_35 ( V_6 . V_203 ? 1 : 0 ) ;
return F_44 ( V_35 , & V_97 ) ;
}
static void F_59 ( struct V_34 * V_35 ,
struct V_206 * V_207 ,
T_1 * V_208 , T_3 V_209 )
{
T_3 V_210 ;
struct V_211 * V_212 = (struct V_211 * ) V_208 ;
V_210 = V_212 -> V_213 . V_208 . V_214 - V_208 ;
while ( ( V_210 < ( V_209 - 2 ) ) &&
( V_208 [ V_210 ] != V_215 ) )
V_210 += V_208 [ V_210 + 1 ] + 2 ;
if ( ( V_210 < ( V_209 - 1 ) ) && ( V_208 [ V_210 ] == V_215 ) ) {
V_207 -> V_210 = F_35 ( V_210 ) ;
V_207 -> V_216 = F_35 ( ( T_3 ) V_208 [ V_210 + 1 ] ) ;
} else {
F_60 ( V_35 , L_12 ) ;
}
}
static int F_61 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
struct V_217 * V_208 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_218 V_97 = {
. V_44 = V_219 ,
. V_220 = V_221 ,
} ;
struct V_206 V_207 = {} ;
struct V_222 * V_223 ;
T_3 V_224 ;
T_3 V_225 , V_226 ;
if ( F_48 ( ! V_208 ) )
return - V_227 ;
V_224 = V_208 -> V_228 ;
V_207 . V_229 = F_35 ( ( T_3 ) V_8 -> V_44 ) ;
V_223 = F_62 ( V_208 ) ;
V_207 . V_230 . V_228 = F_42 ( ( T_2 ) V_224 ) ;
V_207 . V_230 . V_36 = V_8 -> V_62 . V_36 ;
V_207 . V_230 . V_231 = F_35 ( V_232 ) ;
V_226 = V_233 | V_234 ;
V_226 |=
F_63 ( V_35 , ( void * ) V_208 -> V_6 , V_223 , 0 ) <<
V_235 ;
V_207 . V_230 . V_226 = F_35 ( V_226 ) ;
if ( ! F_64 ( & V_35 -> V_236 -> V_237 ,
V_238 ) ) {
V_35 -> V_239 =
F_65 ( V_35 , F_66 ( V_35 ) ,
V_35 -> V_239 ) ;
}
V_207 . V_230 . V_240 =
F_35 ( F_7 ( V_35 -> V_239 ) <<
V_241 ) ;
if ( V_223 -> V_74 == V_242 || V_4 -> V_50 ) {
V_225 = V_89 ;
} else {
V_225 = V_90 ;
V_207 . V_230 . V_240 |= F_35 ( V_243 ) ;
}
V_207 . V_230 . V_240 |=
F_35 ( F_67 ( V_225 ) ) ;
if ( V_4 -> type == V_11 )
F_59 ( V_35 , & V_207 ,
V_208 -> V_6 ,
V_224 ) ;
V_97 . V_228 [ 0 ] = sizeof( V_207 ) ;
V_97 . V_6 [ 0 ] = & V_207 ;
V_97 . V_244 [ 0 ] = 0 ;
V_97 . V_228 [ 1 ] = V_224 ;
V_97 . V_6 [ 1 ] = V_208 -> V_6 ;
V_97 . V_244 [ 1 ] = V_245 ;
return F_68 ( V_35 , & V_97 ) ;
}
int F_69 ( struct V_34 * V_35 ,
struct V_3 * V_4 )
{
struct V_217 * V_208 ;
int V_47 ;
F_48 ( V_4 -> type != V_11 &&
V_4 -> type != V_49 ) ;
V_208 = F_70 ( V_35 -> V_40 , V_4 , NULL ) ;
if ( ! V_208 )
return - V_246 ;
V_47 = F_61 ( V_35 , V_4 , V_208 ) ;
F_71 ( V_208 ) ;
return V_47 ;
}
static void F_72 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_247 * V_6 = V_1 ;
if ( V_4 -> type != V_10 || ! V_4 -> V_16 . V_176 )
return;
if ( V_4 -> V_50 && V_6 -> V_248 )
return;
V_6 -> V_248 = V_4 -> V_16 . V_183 ;
V_6 -> V_17 = V_4 -> V_16 . V_17 ;
}
static void F_73 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
struct V_249 * V_250 ,
bool V_251 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_247 V_6 = {
. V_35 = V_35 ,
. V_4 = V_4 ,
. V_248 = 0
} ;
V_250 -> V_185 = F_35 ( V_4 -> V_16 . V_17 ) ;
V_250 -> V_186 =
F_35 ( F_52 ( V_4 -> V_16 . V_17 ) ) ;
V_250 -> V_187 = F_35 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_177 ) ;
V_250 -> V_188 =
F_35 ( F_52 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_177 ) ) ;
V_250 -> V_252 = F_35 ( V_4 -> V_25 ) ;
if ( V_251 ) {
F_13 (
V_35 -> V_40 , V_41 ,
F_72 , & V_6 ) ;
if ( V_6 . V_248 ) {
T_3 rand = ( F_74 () % ( 64 - 36 ) ) + 36 ;
V_8 -> V_253 = V_6 . V_248 +
F_75 ( V_6 . V_17 * rand /
100 ) ;
} else {
V_8 -> V_253 =
F_76 ( V_35 -> V_254 ,
V_255 ) ;
}
}
V_250 -> V_256 = F_35 ( V_8 -> V_253 ) ;
V_250 -> V_257 = 0 ;
V_250 -> V_200 = F_35 ( V_8 -> V_44 ) ;
}
static int F_77 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_113 )
{
struct V_96 V_97 = {} ;
F_48 ( V_4 -> type != V_11 || V_4 -> V_50 ) ;
F_36 ( V_35 , V_4 , & V_97 , NULL , V_113 ) ;
F_73 ( V_35 , V_4 , & V_97 . V_258 ,
V_113 == V_259 ) ;
return F_44 ( V_35 , & V_97 ) ;
}
static int F_78 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_113 )
{
struct V_96 V_97 = {} ;
struct V_169 * V_170 = & V_4 -> V_16 . V_171 ;
F_48 ( V_4 -> type != V_11 || ! V_4 -> V_50 ) ;
F_36 ( V_35 , V_4 , & V_97 , NULL , V_113 ) ;
F_73 ( V_35 , V_4 , & V_97 . V_260 . V_258 ,
V_113 == V_259 ) ;
V_97 . V_260 . V_173 = F_35 ( V_170 -> V_174 &
V_175 ) ;
V_97 . V_260 . V_261 =
F_35 ( ! ! ( V_170 -> V_174 &
V_262 ) ) ;
return F_44 ( V_35 , & V_97 ) ;
}
static int F_79 ( struct V_34 * V_35 , struct V_3 * V_4 ,
T_3 V_113 , bool V_166 ,
const T_1 * V_112 )
{
switch ( V_4 -> type ) {
case V_10 :
return F_47 ( V_35 , V_4 , V_113 ,
V_166 ,
V_112 ) ;
break;
case V_11 :
if ( ! V_4 -> V_50 )
return F_77 ( V_35 , V_4 , V_113 ) ;
else
return F_78 ( V_35 , V_4 , V_113 ) ;
break;
case V_125 :
return F_53 ( V_35 , V_4 , V_113 ) ;
case V_20 :
return F_58 ( V_35 , V_4 , V_113 ) ;
case V_49 :
return F_56 ( V_35 , V_4 , V_113 ) ;
default:
break;
}
return - V_263 ;
}
int F_80 ( struct V_34 * V_35 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_47 ;
if ( F_81 ( V_8 -> V_264 , L_13 ,
V_4 -> V_130 , F_82 ( V_4 ) ) )
return - V_54 ;
V_47 = F_79 ( V_35 , V_4 , V_259 ,
true , NULL ) ;
if ( V_47 )
return V_47 ;
F_83 ( V_35 , V_4 ) ;
V_8 -> V_264 = true ;
return 0 ;
}
int F_84 ( struct V_34 * V_35 , struct V_3 * V_4 ,
bool V_166 , const T_1 * V_112 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( F_81 ( ! V_8 -> V_264 , L_14 ,
V_4 -> V_130 , F_82 ( V_4 ) ) )
return - V_54 ;
return F_79 ( V_35 , V_4 , V_265 ,
V_166 , V_112 ) ;
}
int F_85 ( struct V_34 * V_35 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_96 V_97 ;
int V_47 ;
if ( F_81 ( ! V_8 -> V_264 , L_15 ,
V_4 -> V_130 , F_82 ( V_4 ) ) )
return - V_54 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_120 = F_35 ( F_37 ( V_8 -> V_44 ,
V_8 -> V_56 ) ) ;
V_97 . V_113 = F_35 ( V_266 ) ;
V_47 = F_45 ( V_35 , V_165 , 0 ,
sizeof( V_97 ) , & V_97 ) ;
if ( V_47 ) {
F_21 ( V_35 , L_16 , V_47 ) ;
return V_47 ;
}
V_8 -> V_264 = false ;
if ( V_4 -> type == V_125 ) {
F_5 ( V_267 , V_35 -> V_40 -> V_220 ) ;
F_86 ( V_35 ) ;
}
return 0 ;
}
static void F_87 ( struct V_34 * V_35 ,
struct V_3 * V_268 , T_3 V_269 ,
bool V_270 )
{
struct V_7 * V_8 =
F_2 ( V_268 ) ;
if ( ! V_270 && ! V_8 -> V_271 )
return;
V_8 -> V_271 = true ;
if ( ! F_88 ( V_268 ) ) {
int V_272 = F_89 ( V_268 ) ;
F_69 ( V_35 , V_268 ) ;
if ( V_268 -> V_50 &&
! F_90 ( & V_8 -> V_57 ) && V_269 &&
V_270 ) {
T_3 V_273 = ( V_272 + 1 ) *
V_268 -> V_16 . V_17 -
V_274 ;
T_3 V_275 = V_269 + V_273 * 1024 ;
F_91 ( V_35 , V_268 ,
V_274 -
V_276 ,
V_275 ) ;
}
} else if ( ! F_90 ( & V_8 -> V_57 ) ) {
F_92 ( V_268 ) ;
F_93 ( V_35 -> V_268 , NULL ) ;
}
}
void F_94 ( struct V_34 * V_35 ,
struct V_277 * V_278 )
{
struct V_279 * V_280 = F_95 ( V_278 ) ;
struct V_281 * V_208 = ( void * ) V_280 -> V_6 ;
struct V_282 * V_283 ;
struct V_3 * V_268 ;
struct V_3 * V_284 ;
T_2 V_52 ;
F_12 ( & V_35 -> V_39 ) ;
V_283 = & V_208 -> V_283 ;
V_35 -> V_285 = F_46 ( V_208 -> V_269 ) ;
V_52 = F_96 ( V_283 -> V_52 . V_52 ) & V_286 ;
F_97 ( V_35 ,
L_17 ,
V_52 , V_283 -> V_287 ,
F_51 ( V_208 -> V_288 ) ,
V_35 -> V_285 ,
F_46 ( V_283 -> V_289 ) ) ;
V_268 = F_98 ( V_35 -> V_268 ,
F_99 ( & V_35 -> V_39 ) ) ;
if ( F_100 ( V_268 && V_268 -> V_290 ) )
F_87 ( V_35 , V_268 , V_35 -> V_285 ,
( V_52 == V_291 ) ) ;
V_284 = F_98 ( V_35 -> V_292 ,
F_99 ( & V_35 -> V_39 ) ) ;
if ( F_100 ( V_284 ) ) {
struct V_7 * V_8 =
F_2 ( V_284 ) ;
if ( ! V_35 -> V_293 )
V_35 -> V_293 =
V_294 ;
else
V_35 -> V_293 -- ;
if ( V_35 -> V_293 == 0 ) {
F_101 ( V_35 , V_8 , false ) ;
F_93 ( V_35 -> V_292 , NULL ) ;
}
}
}
static void F_102 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_295 * V_296 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_34 * V_35 = V_8 -> V_35 ;
struct V_297 * V_298 ;
struct V_299 * V_300 ;
T_3 V_301 , V_302 ;
T_3 V_303 , V_304 ;
if ( V_8 -> V_44 != ( T_2 ) F_46 ( V_296 -> V_305 ) )
return;
V_303 = F_46 ( V_296 -> V_306 ) ;
V_304 =
F_46 ( V_296 -> V_307 ) ;
if ( F_46 ( V_296 -> V_307 ) >
V_308 )
F_103 ( V_4 ) ;
if ( ! F_104 ( V_35 -> V_236 ,
V_309 ) )
return;
V_300 = F_105 ( V_35 -> V_236 ,
V_309 ) ;
V_298 = ( void * ) V_300 -> V_6 ;
V_301 = F_46 ( V_298 -> V_310 ) ;
V_302 =
F_46 ( V_298 -> V_311 ) ;
if ( ! F_106 ( V_35 , V_4 , V_300 ) )
return;
if ( V_304 >= V_302 ||
V_303 >= V_301 )
F_107 ( V_35 , V_300 , NULL ) ;
}
void F_108 ( struct V_34 * V_35 ,
struct V_277 * V_278 )
{
struct V_279 * V_280 = F_95 ( V_278 ) ;
struct V_295 * V_312 = ( void * ) V_280 -> V_6 ;
F_50 ( V_35 ,
L_18 ,
F_46 ( V_312 -> V_305 ) ,
F_46 ( V_312 -> V_306 ) ,
F_46 ( V_312 -> V_307 ) ,
F_46 ( V_312 -> V_313 ) ,
F_46 ( V_312 -> V_314 ) ) ;
F_13 ( V_35 -> V_40 ,
V_315 ,
F_102 ,
V_312 ) ;
}
void F_109 ( struct V_34 * V_35 ,
struct V_277 * V_278 )
{
struct V_279 * V_280 = F_95 ( V_278 ) ;
struct V_316 * V_317 = ( void * ) V_280 -> V_6 ;
struct V_318 V_319 ;
struct V_217 * V_320 ;
T_3 V_321 = F_46 ( V_317 -> V_322 ) ;
if ( V_321 == 0 )
return;
V_320 = F_110 ( V_321 , V_323 ) ;
if ( ! V_320 ) {
F_21 ( V_35 , L_19 ) ;
return;
}
memset ( & V_319 , 0 , sizeof( V_319 ) ) ;
V_319 . V_324 = F_51 ( V_317 -> V_288 ) ;
V_319 . V_325 |= V_326 ;
V_319 . V_327 = F_46 ( V_317 -> V_328 ) ;
V_319 . V_74 =
( V_317 -> V_329 & F_42 ( V_330 ) ) ?
V_136 : V_242 ;
V_319 . V_331 =
F_111 ( F_96 ( V_317 -> V_332 ) ,
V_319 . V_74 ) ;
memcpy ( F_112 ( V_320 , V_321 ) , V_317 -> V_6 , V_321 ) ;
memcpy ( F_113 ( V_320 ) , & V_319 , sizeof( V_319 ) ) ;
F_114 ( V_35 -> V_40 , V_320 , NULL ) ;
}
