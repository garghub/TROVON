static void F_1 ( T_1 * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_5 ;
do {
V_5 = F_2 ( V_4 ) ;
* ( V_2 ) = * V_1 ;
} while ( F_3 ( V_4 , V_5 ) );
}
static void F_4 ( struct V_6 * V_7 , T_1 * * V_8 )
{
const struct V_9 * V_9 ;
struct V_10 * V_11 ;
T_1 * V_12 ;
int V_13 , V_14 ;
for ( V_13 = 0 ; V_13 < V_7 -> V_15 ; V_13 ++ ) {
V_11 = & V_7 -> V_16 [ V_13 ] ;
for ( V_14 = 0 ; V_14 < V_17 ; V_14 ++ ) {
V_9 = & V_18 [ V_14 ] ;
V_12 = ( T_1 * ) ( ( V_19 ) & V_11 -> V_20 +
( V_19 ) V_9 -> V_21 ) ;
F_1 ( V_12 , ( * V_8 ) ++ , & V_11 -> V_4 ) ;
}
V_11 = & V_7 -> V_22 [ V_13 ] ;
for ( V_14 = 0 ; V_14 < V_23 ; V_14 ++ ) {
V_9 = & V_24 [ V_14 ] ;
V_12 = ( T_1 * ) ( ( V_19 ) & V_11 -> V_25 +
( V_19 ) V_9 -> V_21 ) ;
F_1 ( V_12 , ( * V_8 ) ++ , & V_11 -> V_4 ) ;
}
}
}
static void F_5 ( struct V_6 * V_7 , T_1 * * V_8 )
{
const struct V_9 * V_9 ;
T_2 * V_12 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_26 ; V_13 ++ ) {
V_9 = & V_27 [ V_13 ] ;
V_12 = ( T_2 * ) ( ( V_19 ) & V_7 -> V_28 -> V_29 . V_30 +
( V_19 ) V_9 -> V_21 ) ;
* ( * V_8 ) ++ = * V_12 ;
}
}
static void F_6 ( struct V_31 * V_32 ,
struct V_33 * V_30 ,
T_1 * V_8 )
{
struct V_6 * V_7 = F_7 ( V_32 ) ;
const struct V_9 * V_9 ;
T_1 * V_12 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_34 ; V_13 ++ ) {
V_9 = & V_35 [ V_13 ] ;
V_12 = ( T_1 * ) ( ( V_19 ) & V_7 -> V_36 +
( V_19 ) V_9 -> V_21 ) ;
F_1 ( V_12 , V_8 ++ , & V_7 -> V_4 ) ;
}
F_4 ( V_7 , & V_8 ) ;
F_5 ( V_7 , & V_8 ) ;
}
int F_8 ( struct V_31 * V_32 , int V_37 )
{
struct V_6 * V_7 = F_7 ( V_32 ) ;
if ( V_37 != V_38 )
return - V_39 ;
return V_7 -> V_15 * ( V_17 + V_23 )
+ V_34 + V_26 ;
}
static void F_9 ( struct V_6 * V_7 , T_3 * * V_8 )
{
const struct V_9 * V_9 ;
int V_13 , V_14 ;
for ( V_13 = 0 ; V_13 < V_7 -> V_15 ; V_13 ++ ) {
for ( V_14 = 0 ; V_14 < V_17 ; V_14 ++ ) {
V_9 = & V_18 [ V_14 ] ;
snprintf ( * V_8 , V_40 ,
L_1 , V_13 , V_9 -> V_41 ) ;
( * V_8 ) += V_40 ;
}
for ( V_14 = 0 ; V_14 < V_23 ; V_14 ++ ) {
V_9 = & V_24 [ V_14 ] ;
snprintf ( * V_8 , V_40 ,
L_2 , V_13 , V_9 -> V_41 ) ;
( * V_8 ) += V_40 ;
}
}
}
static void F_10 ( T_3 * * V_8 )
{
const struct V_9 * V_9 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_26 ; V_13 ++ ) {
V_9 = & V_27 [ V_13 ] ;
snprintf ( * V_8 , V_40 ,
L_3 , V_9 -> V_41 ) ;
( * V_8 ) += V_40 ;
}
}
static void F_11 ( struct V_31 * V_32 , T_2 V_37 , T_3 * V_8 )
{
struct V_6 * V_7 = F_7 ( V_32 ) ;
const struct V_9 * V_9 ;
int V_13 ;
if ( V_37 != V_38 )
return;
for ( V_13 = 0 ; V_13 < V_34 ; V_13 ++ ) {
V_9 = & V_35 [ V_13 ] ;
memcpy ( V_8 , V_9 -> V_41 , V_40 ) ;
V_8 += V_40 ;
}
F_9 ( V_7 , & V_8 ) ;
F_10 ( & V_8 ) ;
}
static int F_12 ( struct V_31 * V_32 ,
struct V_42 * V_43 )
{
struct V_6 * V_7 = F_7 ( V_32 ) ;
struct V_44 * V_28 = V_7 -> V_28 ;
struct V_45 * V_46 ;
struct V_47 V_48 ;
int V_49 ;
V_49 = F_13 ( V_28 , & V_48 ) ;
if ( V_49 )
return V_49 ;
V_46 = & V_48 . V_50 . V_46 ;
V_43 -> V_51 . V_52 = V_46 -> V_52 ;
if ( V_46 -> V_53 & V_54 ) {
F_14 ( V_43 ,
V_55 , V_56 ) ;
F_14 ( V_43 ,
V_55 , V_56 ) ;
}
V_43 -> V_51 . V_57 =
( V_46 -> V_53 & V_54 ) ?
V_58 : V_59 ;
V_43 -> V_51 . V_60 = V_61 ;
return 0 ;
}
static int F_15 ( struct V_31 * V_62 ,
struct V_63 * V_64 )
{
struct V_6 * V_7 = F_7 ( V_62 ) ;
struct V_44 * V_28 = V_7 -> V_28 ;
struct V_65 V_66 ;
if ( ! F_16 ( V_28 ) ) {
return - V_39 ;
}
V_64 -> V_67 =
F_17 ( V_28 ) /
V_28 -> V_68 ;
if ( ! F_18 ( V_28 ) ) {
V_64 -> V_69 =
F_19 ( V_28 )
/ V_28 -> V_68 ;
} else {
F_20 ( V_7 -> V_28 , V_70 , & V_66 ) ;
V_64 -> V_71 = V_66 . V_72 ;
V_64 -> V_73 = V_66 . V_74 ;
F_20 ( V_7 -> V_28 , V_75 , & V_66 ) ;
V_64 -> V_69 = V_66 . V_72 ;
V_64 -> V_76 = V_66 . V_74 ;
F_20 ( V_7 -> V_28 , V_77 , & V_66 ) ;
V_64 -> V_78 = V_66 . V_72 ;
V_64 -> V_79 = V_66 . V_74 ;
}
V_64 -> V_80 =
F_18 ( V_28 ) ;
return 0 ;
}
static void F_21 ( struct V_6 * V_7 )
{
unsigned int V_81 ;
int V_13 ;
V_81 = F_17 ( V_7 -> V_28 ) ;
for ( V_13 = 0 ; V_13 < V_7 -> V_15 ; V_13 ++ )
V_7 -> V_16 [ V_13 ] . V_82 = V_81 ;
}
static int F_22 ( struct V_31 * V_62 ,
struct V_63 * V_64 )
{
struct V_6 * V_7 = F_7 ( V_62 ) ;
struct V_44 * V_28 = V_7 -> V_28 ;
struct V_65 V_66 ;
int V_49 ;
if ( ! F_16 ( V_28 ) ) {
return - V_39 ;
}
if ( V_64 -> V_83 ||
V_64 -> V_84 ||
V_64 -> V_85 ||
V_64 -> V_86 ||
V_64 -> V_87 ||
V_64 -> V_88 ||
V_64 -> V_89 ||
V_64 -> V_90 ||
V_64 -> V_91 ||
V_64 -> V_92 ||
V_64 -> V_93 ||
V_64 -> V_94 ||
V_64 -> V_95 ||
V_64 -> V_96 )
return - V_97 ;
V_49 = F_23 ( V_28 ,
V_64 -> V_67 ) ;
if ( V_49 )
return V_49 ;
F_21 ( V_7 ) ;
if ( F_18 ( V_28 ) ) {
if ( ! V_64 -> V_80 ) {
F_24 ( V_28 ) ;
V_49 = F_25 ( V_28 ,
V_64 -> V_69 ) ;
return V_49 ;
}
} else {
if ( V_64 -> V_80 ) {
F_26 ( V_28 ) ;
} else {
V_49 = F_25 ( V_28 ,
V_64 -> V_69 ) ;
return V_49 ;
}
}
V_66 . V_72 = V_64 -> V_71 ;
V_66 . V_74 = V_64 -> V_73 ;
V_66 . V_98 = V_99 ;
F_27 ( V_7 -> V_28 , V_70 , & V_66 ) ;
V_66 . V_72 = V_64 -> V_69 ;
V_66 . V_74 = V_64 -> V_76 ;
V_66 . V_98 = V_99 ;
F_27 ( V_7 -> V_28 , V_75 , & V_66 ) ;
V_66 . V_72 = V_64 -> V_78 ;
V_66 . V_74 = V_64 -> V_79 ;
V_66 . V_98 = V_99 ;
F_27 ( V_7 -> V_28 , V_77 , & V_66 ) ;
return 0 ;
}
static T_2 F_28 ( struct V_31 * V_32 )
{
struct V_6 * V_7 = F_7 ( V_32 ) ;
return V_7 -> V_100 ;
}
static void F_29 ( struct V_31 * V_32 , T_2 V_101 )
{
struct V_6 * V_7 = F_7 ( V_32 ) ;
V_7 -> V_100 = V_101 ;
}
static void F_30 ( struct V_31 * V_102 ,
struct V_103 * V_104 )
{
struct V_6 * V_7 = F_7 ( V_102 ) ;
F_31 ( V_104 -> V_105 , V_106 , sizeof( V_104 -> V_105 ) ) ;
F_31 ( V_104 -> V_107 , V_108 , sizeof( V_104 -> V_107 ) ) ;
F_31 ( V_104 -> V_109 , F_32 ( V_7 -> V_110 ) ,
sizeof( V_104 -> V_109 ) ) ;
}
static void F_33 ( struct V_31 * V_32 ,
struct V_111 * V_11 )
{
struct V_6 * V_7 = F_7 ( V_32 ) ;
struct V_10 * V_16 = & V_7 -> V_16 [ 0 ] ;
struct V_10 * V_22 = & V_7 -> V_22 [ 0 ] ;
V_11 -> V_112 = V_22 -> V_113 ;
V_11 -> V_114 = V_16 -> V_113 ;
V_11 -> V_115 = V_22 -> V_113 ;
V_11 -> V_116 = V_16 -> V_113 ;
}
static T_2 F_34 ( T_4 V_117 )
{
T_2 V_8 = 0 ;
if ( V_117 & V_118 )
V_8 |= V_119 ;
if ( V_117 & V_120 )
V_8 |= V_121 ;
if ( V_117 & V_122 )
V_8 |= V_123 ;
if ( V_117 & V_124 )
V_8 |= V_125 ;
if ( V_117 & V_126 )
V_8 |= V_127 ;
return V_8 ;
}
static T_4 F_35 ( T_2 V_117 )
{
T_4 V_8 = 0 ;
if ( V_117 & V_119 )
V_8 |= V_118 ;
if ( V_117 & V_121 )
V_8 |= V_120 ;
if ( V_117 & V_123 )
V_8 |= V_122 ;
if ( V_117 & V_125 )
V_8 |= V_124 ;
if ( V_117 & V_127 )
V_8 |= V_126 ;
return V_8 ;
}
static int F_36 ( struct V_44 * V_28 ,
struct V_128 * V_129 )
{
enum V_130 V_131 ;
T_4 V_117 ;
int V_49 ;
V_129 -> V_8 = 0 ;
switch ( V_129 -> V_132 ) {
case V_133 :
V_131 = V_134 ;
break;
case V_135 :
V_131 = V_136 ;
break;
case V_137 :
V_131 = V_138 ;
break;
case V_139 :
V_131 = V_140 ;
break;
case V_141 :
V_131 = V_142 ;
break;
case V_143 :
V_131 = V_144 ;
break;
case V_145 :
V_131 = V_146 ;
break;
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
return - V_39 ;
default:
return - V_97 ;
}
V_49 = F_37 ( V_28 , V_131 , & V_117 ) ;
if ( V_49 ) {
if ( V_49 == - V_153 )
V_49 = - V_39 ;
return V_49 ;
}
V_129 -> V_8 = F_34 ( V_117 ) ;
return 0 ;
}
static int F_38 ( struct V_44 * V_28 ,
struct V_128 * V_129 )
{
enum V_130 V_131 ;
T_4 V_117 ;
switch ( V_129 -> V_132 ) {
case V_133 :
V_131 = V_134 ;
break;
case V_135 :
V_131 = V_136 ;
break;
case V_137 :
V_131 = V_138 ;
break;
case V_139 :
V_131 = V_140 ;
break;
case V_141 :
V_131 = V_142 ;
break;
case V_143 :
V_131 = V_144 ;
break;
case V_145 :
V_131 = V_146 ;
break;
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
return - V_39 ;
default:
return - V_97 ;
}
V_117 = F_35 ( V_129 -> V_8 ) ;
return F_39 ( V_28 , V_131 , V_117 ) ;
}
static int F_40 ( struct V_31 * V_32 , struct V_128 * V_104 )
{
struct V_6 * V_7 = F_7 ( V_32 ) ;
int V_49 = 0 ;
switch ( V_104 -> V_129 ) {
case V_154 :
V_49 = F_38 ( V_7 -> V_28 , V_104 ) ;
break;
case V_155 :
case V_156 :
default:
F_41 ( V_7 , V_157 , V_32 ,
L_4 , V_104 -> V_129 ) ;
V_49 = - V_39 ;
}
return ( V_49 == - V_153 ) ? - V_39 : V_49 ;
}
static int F_42 ( struct V_31 * V_32 , struct V_128 * V_104 ,
T_2 * V_158 )
{
struct V_6 * V_7 = F_7 ( V_32 ) ;
int V_49 = 0 ;
switch ( V_104 -> V_129 ) {
case V_159 :
V_104 -> V_8 = V_7 -> V_15 ;
V_49 = 0 ;
break;
case V_160 :
V_49 = F_36 ( V_7 -> V_28 , V_104 ) ;
break;
case V_161 :
case V_162 :
case V_163 :
default:
F_41 ( V_7 , V_157 , V_32 ,
L_4 , V_104 -> V_129 ) ;
V_49 = - V_39 ;
}
return ( V_49 == - V_153 ) ? - V_39 : V_49 ;
}
static T_2 F_43 ( struct V_31 * V_32 )
{
return V_164 ;
}
static T_2 F_44 ( struct V_31 * V_32 )
{
return V_165 ;
}
static int F_45 ( struct V_31 * V_32 , T_2 * V_166 , T_3 * V_167 ,
T_3 * V_168 )
{
struct V_6 * V_7 = F_7 ( V_32 ) ;
enum V_169 V_170 ;
T_3 V_171 ;
int V_49 ;
V_49 = F_46 ( V_7 -> V_28 , V_166 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_47 ( V_7 -> V_28 , & V_170 , V_167 ) ;
if ( V_49 )
return V_49 ;
switch ( V_170 ) {
case V_172 :
V_171 = V_173 ;
break;
case V_174 :
V_171 = V_175 ;
break;
default:
F_41 ( V_7 , V_157 , V_32 ,
L_5 ) ;
return - V_39 ;
}
if ( V_168 )
* V_168 = V_171 ;
return V_49 ;
}
static int F_48 ( struct V_31 * V_32 , const T_2 * V_166 ,
const T_3 * V_167 , const T_3 V_168 )
{
struct V_6 * V_7 = F_7 ( V_32 ) ;
struct V_44 * V_28 = V_7 -> V_28 ;
enum V_169 V_171 ;
int V_49 , V_13 ;
if ( V_166 ) {
for ( V_13 = 0 ; V_13 < V_164 ; V_13 ++ ) {
V_49 = F_49 ( V_28 ,
F_50 ( V_166 [ V_13 ] ) ,
V_13 ) ;
if ( F_51 ( V_49 ) ) {
F_41 ( V_7 , V_157 , V_32 ,
L_6 ) ;
return V_49 ;
}
}
V_49 = F_52 ( V_28 ) ;
if ( V_49 ) {
F_41 ( V_7 , V_157 , V_32 ,
L_7 ) ;
return V_49 == - V_153 ? - V_39 : V_49 ;
}
}
switch ( V_168 ) {
case V_173 :
V_171 = V_172 ;
break;
case V_175 :
V_171 = V_174 ;
break;
default:
F_41 ( V_7 , V_157 , V_32 , L_8 ,
V_168 ) ;
return - V_39 ;
}
if ( V_167 ) {
V_49 = F_53 ( V_28 , V_171 , V_167 ,
V_165 ,
0xFFFFFFFF ) ;
if ( F_51 ( V_49 ) ) {
F_41 ( V_7 , V_157 , V_32 , L_9 ) ;
return V_49 == - V_153 ? - V_39 : V_49 ;
}
}
return 0 ;
}
static void F_54 ( struct V_31 * V_32 ,
struct V_176 * V_177 )
{
struct V_6 * V_7 = F_7 ( V_32 ) ;
V_177 -> V_178 = V_179 ;
V_177 -> V_180 = V_179 ;
V_177 -> V_181 = 0 ;
V_177 -> V_182 = 0 ;
V_177 -> V_183 = V_7 -> V_15 ;
V_177 -> V_184 = V_7 -> V_15 ;
V_177 -> V_185 = 0 ;
V_177 -> V_186 = 0 ;
}
static int F_55 ( struct V_31 * V_32 ,
const struct V_187 * V_188 , void * V_8 )
{
struct V_6 * V_7 = F_7 ( V_32 ) ;
int V_189 = 0 ;
switch ( V_188 -> V_190 ) {
case V_191 :
* ( T_2 * ) V_8 = V_7 -> V_192 ;
break;
default:
V_189 = - V_97 ;
break;
}
return V_189 ;
}
static int F_56 ( struct V_31 * V_32 ,
const struct V_187 * V_188 ,
const void * V_8 )
{
struct V_6 * V_7 = F_7 ( V_32 ) ;
int V_189 = 0 ;
T_2 V_193 ;
switch ( V_188 -> V_190 ) {
case V_191 :
V_193 = * ( T_2 * ) V_8 ;
if ( V_193 > V_7 -> V_32 -> V_194 ) {
V_189 = - V_97 ;
break;
}
V_7 -> V_192 = V_193 ;
break;
default:
V_189 = - V_97 ;
break;
}
return V_189 ;
}
void F_57 ( struct V_31 * V_32 )
{
V_32 -> V_195 = & V_196 ;
}
static void F_58 ( struct V_6 * V_7 , T_3 * V_197 )
{
struct V_31 * V_32 = V_7 -> V_32 ;
T_3 * V_198 ;
T_1 * V_199 ;
int V_200 ;
int V_13 , V_49 ;
V_200 = F_8 ( V_32 , V_38 ) ;
if ( V_200 <= 0 ) {
F_41 ( V_7 , V_157 , V_32 , L_10 ) ;
return;
}
V_198 = F_59 ( & V_7 -> V_110 -> V_102 ,
V_200 * V_40 ,
V_201 ) ;
if ( ! V_198 ) {
F_41 ( V_7 , V_157 , V_32 ,
L_11 ) ;
return;
}
V_199 = F_59 ( & V_7 -> V_110 -> V_102 ,
V_200 * sizeof( T_1 ) ,
V_201 ) ;
if ( ! V_199 ) {
F_41 ( V_7 , V_157 , V_32 ,
L_12 ) ;
F_60 ( & V_7 -> V_110 -> V_102 , V_198 ) ;
return;
}
F_11 ( V_32 , V_38 , V_198 ) ;
F_6 ( V_32 , NULL , V_199 ) ;
if ( V_197 )
for ( V_13 = 0 ; V_13 < V_200 ; V_13 ++ ) {
V_49 = snprintf ( V_197 , V_40 + sizeof( T_1 ) ,
L_13 ,
V_198 + V_13 * V_40 ,
V_199 [ V_13 ] ) ;
V_197 += V_49 ;
}
else
for ( V_13 = 0 ; V_13 < V_200 ; V_13 ++ )
F_41 ( V_7 , V_157 , V_32 , L_14 ,
V_198 + V_13 * V_40 ,
V_199 [ V_13 ] ) ;
F_60 ( & V_7 -> V_110 -> V_102 , V_198 ) ;
F_60 ( & V_7 -> V_110 -> V_102 , V_199 ) ;
}
void F_61 ( struct V_6 * V_7 , T_3 * V_197 )
{
if ( ! V_197 )
return;
F_58 ( V_7 , V_197 ) ;
}
void F_62 ( struct V_6 * V_7 )
{
F_58 ( V_7 , NULL ) ;
}
