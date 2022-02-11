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
if ( V_4 -> type == V_11 ||
V_4 -> type == V_25 )
V_18 |= F_7 ( V_4 -> V_26 ) ;
return V_18 ;
}
static void F_8 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_27 * V_6 = V_1 ;
if ( V_4 == V_6 -> V_28 )
return;
V_6 -> V_29 |= F_6 ( V_4 ) ;
}
static void F_9 ( void * V_1 ,
struct V_30 * V_31 )
{
struct V_27 * V_6 = V_1 ;
struct V_32 * V_33 = F_10 ( V_31 ) ;
V_6 -> V_29 |= V_33 -> V_34 ;
}
unsigned long F_11 ( struct V_35 * V_36 ,
struct V_3 * V_28 )
{
T_1 V_37 ;
struct V_27 V_6 = {
. V_28 = V_28 ,
. V_29 =
F_7 ( V_21 ) |
F_7 ( V_36 -> V_38 ) ,
} ;
if ( F_12 ( V_36 ) )
V_6 . V_29 |= F_7 ( V_39 ) ;
else
V_6 . V_29 |= F_7 ( V_40 ) ;
F_13 ( & V_36 -> V_41 ) ;
F_14 (
V_36 -> V_42 , V_43 ,
F_8 , & V_6 ) ;
if ( F_12 ( V_36 ) )
return V_6 . V_29 ;
F_15 ( V_36 -> V_42 ,
F_9 ,
& V_6 ) ;
F_16 (sta_id, mvm->sta_drained, IWL_MVM_STATION_COUNT)
V_6 . V_29 |= V_36 -> V_44 [ V_37 ] ;
return V_6 . V_29 ;
}
static void F_17 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 == V_6 -> V_4 ) {
V_6 -> V_45 = true ;
return;
}
F_5 ( V_8 -> V_46 , V_6 -> V_47 ) ;
F_1 ( V_1 , V_2 , V_4 ) ;
}
void F_18 ( struct V_35 * V_36 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_5 V_6 = {
. V_36 = V_36 ,
. V_4 = V_4 ,
. V_15 = { ( 1 << V_13 ) - 1 } ,
. V_12 = V_13 ,
} ;
F_14 (
V_36 -> V_42 , V_43 ,
F_1 , & V_6 ) ;
if ( V_6 . V_12 != V_13 )
V_8 -> V_14 = V_6 . V_12 ;
else if ( ! F_3 ( V_8 -> V_14 , V_6 . V_15 ) )
V_8 -> V_14 = F_19 ( V_6 . V_15 ,
V_13 ) ;
}
static int F_20 ( struct V_35 * V_36 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_5 V_6 = {
. V_36 = V_36 ,
. V_4 = V_4 ,
. V_47 = { ( 1 << V_48 ) - 1 } ,
. V_15 = { ( 1 << V_13 ) - 1 } ,
. V_12 = V_13 ,
. V_45 = false ,
} ;
T_3 V_19 ;
int V_49 , V_50 , V_51 ;
unsigned long V_29 ;
switch ( V_4 -> type ) {
case V_25 :
break;
case V_10 :
if ( ! V_4 -> V_52 )
break;
default:
F_5 ( 0 , V_6 . V_47 ) ;
}
F_14 (
V_36 -> V_42 , V_43 ,
F_17 , & V_6 ) ;
V_29 = F_11 ( V_36 , V_4 ) ;
if ( V_6 . V_45 )
return 0 ;
if ( F_21 ( F_3 ( V_53 , & V_36 -> V_54 ) ) )
return - V_55 ;
V_8 -> V_46 = F_19 ( V_6 . V_47 ,
V_48 ) ;
if ( V_8 -> V_46 == V_48 ) {
F_22 ( V_36 , L_1 ) ;
V_49 = - V_56 ;
goto V_57;
}
if ( V_6 . V_12 != V_13 )
V_8 -> V_14 = V_6 . V_12 ;
else
V_8 -> V_14 = F_19 ( V_6 . V_15 ,
V_13 ) ;
if ( V_8 -> V_14 == V_13 ) {
F_22 ( V_36 , L_2 ) ;
V_49 = - V_56 ;
goto V_57;
}
V_8 -> V_58 = 0 ;
F_23 ( & V_8 -> V_59 . V_60 ) ;
V_8 -> V_59 . V_46 = V_61 ;
if ( V_4 -> type == V_20 ) {
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
V_4 -> V_23 [ V_19 ] = V_24 ;
return 0 ;
}
if ( F_12 ( V_36 ) ) {
V_51 = V_62 ;
F_24 ( V_62 >
V_63 *
sizeof( V_36 -> V_64 [ 0 ] ) ) ;
} else {
V_51 = V_36 -> V_65 ;
}
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
T_1 V_66 = F_25 ( & V_29 , V_51 ) ;
if ( V_66 >= V_51 ) {
F_22 ( V_36 , L_3 ) ;
V_49 = - V_56 ;
goto V_57;
}
F_26 ( V_66 , & V_29 ) ;
V_4 -> V_23 [ V_19 ] = V_66 ;
}
if ( V_4 -> type == V_11 ) {
T_1 V_66 ;
if ( ! F_12 ( V_36 ) ) {
V_66 = F_25 ( & V_29 ,
V_36 -> V_65 ) ;
if ( V_66 >= V_36 -> V_65 ) {
F_22 ( V_36 , L_4 ) ;
V_49 = - V_56 ;
goto V_57;
}
} else {
V_66 = V_39 ;
}
V_8 -> V_26 = V_66 ;
V_4 -> V_26 = V_66 ;
} else {
V_4 -> V_26 = V_24 ;
}
V_8 -> V_67 . V_37 = V_68 ;
V_8 -> V_69 . V_37 = V_68 ;
V_8 -> V_70 = V_68 ;
for ( V_50 = 0 ; V_50 < V_71 ; V_50 ++ )
V_8 -> V_72 [ V_50 ] = V_73 ;
return 0 ;
V_57:
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
memset ( V_4 -> V_23 , V_24 , sizeof( V_4 -> V_23 ) ) ;
V_4 -> V_26 = V_24 ;
return V_49 ;
}
int F_27 ( struct V_35 * V_36 , struct V_3 * V_4 )
{
unsigned int V_74 =
F_28 ( V_36 , V_4 , false , false ) ;
T_3 V_19 ;
int V_49 ;
F_13 ( & V_36 -> V_41 ) ;
V_49 = F_20 ( V_36 , V_4 ) ;
if ( V_49 )
return V_49 ;
if ( F_12 ( V_36 ) )
return 0 ;
switch ( V_4 -> type ) {
case V_20 :
F_29 ( V_36 , V_21 ,
V_21 ,
V_75 , 0 , V_74 ) ;
break;
case V_11 :
F_29 ( V_36 , V_4 -> V_26 , V_4 -> V_26 ,
V_76 , 0 , V_74 ) ;
default:
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
F_29 ( V_36 , V_4 -> V_23 [ V_19 ] ,
V_4 -> V_23 [ V_19 ] ,
V_77 [ V_19 ] , 0 ,
V_74 ) ;
break;
}
return 0 ;
}
void F_30 ( struct V_35 * V_36 , struct V_3 * V_4 )
{
int V_19 ;
F_13 ( & V_36 -> V_41 ) ;
if ( F_12 ( V_36 ) )
return;
switch ( V_4 -> type ) {
case V_20 :
F_31 ( V_36 , V_21 ,
V_21 ,
V_78 , 0 ) ;
break;
case V_11 :
F_31 ( V_36 , V_4 -> V_26 , V_4 -> V_26 ,
V_78 , 0 ) ;
default:
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
F_31 ( V_36 , V_4 -> V_23 [ V_19 ] ,
V_4 -> V_23 [ V_19 ] ,
V_78 , 0 ) ;
}
}
static void F_32 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
enum V_79 V_80 ,
T_1 * V_81 , T_1 * V_82 )
{
struct V_83 * V_84 ;
unsigned long V_85 = V_4 -> V_16 . V_86 ;
int V_87 = 100 ;
int V_88 = 100 ;
T_1 V_89 = 0 ;
T_1 V_90 = 0 ;
int V_50 ;
V_84 = V_36 -> V_42 -> V_91 -> V_92 [ V_80 ] ;
F_16 (i, &basic, BITS_PER_LONG) {
int V_42 = V_84 -> V_93 [ V_50 ] . V_94 ;
if ( V_42 >= V_95 ) {
V_90 |= F_7 ( V_42 - V_95 ) ;
if ( V_87 > V_42 )
V_87 = V_42 ;
} else {
F_24 ( V_96 != 0 ) ;
V_89 |= F_7 ( V_42 ) ;
if ( V_88 > V_42 )
V_88 = V_42 ;
}
}
if ( V_97 < V_87 )
V_90 |= F_33 ( 24 ) >> V_95 ;
if ( V_98 < V_87 )
V_90 |= F_33 ( 12 ) >> V_95 ;
V_90 |= F_33 ( 6 ) >> V_95 ;
if ( V_99 < V_88 )
V_89 |= F_33 ( 11 ) >> V_96 ;
if ( V_100 < V_88 )
V_89 |= F_33 ( 5 ) >> V_96 ;
if ( V_101 < V_88 )
V_89 |= F_33 ( 2 ) >> V_96 ;
V_89 |= F_33 ( 1 ) >> V_96 ;
* V_81 = V_89 ;
* V_82 = V_90 ;
}
static void F_34 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
struct V_102 * V_103 )
{
T_1 V_104 = V_4 -> V_16 . V_105 &
V_106 ;
T_3 V_107 = V_108 | V_109 ;
F_35 ( V_36 , L_5 , V_104 ) ;
switch ( V_104 ) {
case V_110 :
break;
case V_111 :
case V_112 :
V_103 -> V_113 |= F_36 ( V_107 ) ;
break;
case V_114 :
if ( V_4 -> V_16 . V_115 . V_116 > V_117 )
V_103 -> V_113 |= F_36 ( V_107 ) ;
break;
default:
F_22 ( V_36 , L_6 ,
V_104 ) ;
break;
}
}
static void F_37 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
struct V_102 * V_103 ,
const T_1 * V_118 ,
T_3 V_119 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_120 * V_121 ;
bool V_122 = ! ! ( V_4 -> V_16 . V_105 &
V_106 ) ;
T_1 V_123 , V_124 ;
const T_1 * V_125 = V_118 ? : V_4 -> V_16 . V_125 ;
int V_50 ;
V_103 -> V_126 = F_36 ( F_38 ( V_8 -> V_46 ,
V_8 -> V_58 ) ) ;
V_103 -> V_119 = F_36 ( V_119 ) ;
switch ( V_4 -> type ) {
case V_10 :
if ( V_4 -> V_52 )
V_103 -> V_127 = F_36 ( V_128 ) ;
else
V_103 -> V_127 = F_36 ( V_129 ) ;
break;
case V_11 :
V_103 -> V_127 = F_36 ( V_130 ) ;
break;
case V_131 :
V_103 -> V_127 = F_36 ( V_132 ) ;
break;
case V_20 :
V_103 -> V_127 = F_36 ( V_133 ) ;
break;
case V_25 :
V_103 -> V_127 = F_36 ( V_134 ) ;
break;
default:
F_21 ( 1 ) ;
}
V_103 -> V_14 = F_36 ( V_8 -> V_14 ) ;
memcpy ( V_103 -> V_135 , V_4 -> V_136 , V_137 ) ;
if ( V_125 )
memcpy ( V_103 -> V_138 , V_125 , V_137 ) ;
else
F_39 ( V_103 -> V_138 ) ;
F_40 () ;
V_121 = F_41 ( V_4 -> V_139 ) ;
F_32 ( V_36 , V_4 , V_121 ? V_121 -> V_140 . V_141 -> V_80
: V_142 ,
& V_123 , & V_124 ) ;
F_42 () ;
V_103 -> V_81 = F_36 ( ( T_3 ) V_123 ) ;
V_103 -> V_82 = F_36 ( ( T_3 ) V_124 ) ;
V_103 -> V_143 =
F_36 ( V_4 -> V_16 . V_144 ?
V_145 : 0 ) ;
V_103 -> V_146 =
F_36 ( V_4 -> V_16 . V_147 ?
V_148 : 0 ) ;
V_103 -> V_149 = F_36 ( V_150 ) ;
for ( V_50 = 0 ; V_50 < V_22 ; V_50 ++ ) {
T_1 V_151 = V_77 [ V_50 ] ;
V_103 -> V_19 [ V_151 ] . V_152 =
F_43 ( V_8 -> V_153 [ V_50 ] . V_152 ) ;
V_103 -> V_19 [ V_151 ] . V_154 =
F_43 ( V_8 -> V_153 [ V_50 ] . V_154 ) ;
V_103 -> V_19 [ V_151 ] . V_155 =
F_43 ( V_8 -> V_153 [ V_50 ] . V_156 * 32 ) ;
V_103 -> V_19 [ V_151 ] . V_157 = V_8 -> V_153 [ V_50 ] . V_158 ;
V_103 -> V_19 [ V_151 ] . V_159 = F_7 ( V_151 ) ;
}
if ( V_4 -> V_16 . V_160 )
V_103 -> V_161 |= F_36 ( V_162 ) ;
if ( V_4 -> V_16 . V_163 )
V_103 -> V_113 |= F_36 ( V_164 ) ;
F_35 ( V_36 , L_7 ,
V_4 -> V_16 . V_163 ,
V_4 -> V_16 . V_105 ) ;
if ( V_4 -> V_16 . V_115 . V_116 != V_165 )
V_103 -> V_161 |= F_36 ( V_166 ) ;
if ( V_122 )
F_34 ( V_36 , V_4 , V_103 ) ;
}
static int F_44 ( struct V_35 * V_36 ,
struct V_102 * V_103 )
{
int V_49 = F_45 ( V_36 , V_167 , 0 ,
sizeof( * V_103 ) , V_103 ) ;
if ( V_49 )
F_22 ( V_36 , L_8 ,
F_46 ( V_103 -> V_119 ) , V_49 ) ;
return V_49 ;
}
static int F_47 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
T_3 V_119 , bool V_168 ,
const T_1 * V_118 )
{
struct V_102 V_103 = {} ;
struct V_169 * V_170 ;
F_48 ( V_4 -> type != V_10 ) ;
F_37 ( V_36 , V_4 , & V_103 , V_118 , V_119 ) ;
if ( V_4 -> V_52 ) {
struct V_171 * V_172 =
& V_4 -> V_16 . V_173 ;
V_103 . V_174 . V_175 = F_36 ( V_172 -> V_176 &
V_177 ) ;
V_170 = & V_103 . V_174 . V_31 ;
} else {
V_170 = & V_103 . V_31 ;
}
if ( V_4 -> V_16 . V_178 && V_4 -> V_16 . V_179 &&
! V_168 ) {
T_3 V_180 ;
V_180 = V_4 -> V_16 . V_181 *
V_4 -> V_16 . V_17 ;
V_180 *= 1024 ;
V_170 -> V_182 =
F_49 ( V_4 -> V_16 . V_183 + V_180 ) ;
V_170 -> V_184 =
F_36 ( V_4 -> V_16 . V_185 + V_180 ) ;
V_170 -> V_186 =
F_36 ( V_4 -> V_16 . V_185 ) ;
F_50 ( V_36 , L_9 ,
F_51 ( V_170 -> V_182 ) ,
F_46 ( V_170 -> V_184 ) ,
V_180 ) ;
V_170 -> V_187 = F_36 ( 1 ) ;
} else {
V_170 -> V_187 = F_36 ( 0 ) ;
V_103 . V_149 |= F_36 ( V_188 ) ;
}
V_170 -> V_189 = F_36 ( V_4 -> V_16 . V_17 ) ;
V_170 -> V_190 =
F_36 ( F_52 ( V_4 -> V_16 . V_17 ) ) ;
V_170 -> V_191 = F_36 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_179 ) ;
V_170 -> V_192 =
F_36 ( F_52 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_179 ) ) ;
V_170 -> V_193 = F_36 ( V_36 -> V_42 -> V_194 . V_193 ) ;
V_170 -> V_195 = F_36 ( V_4 -> V_16 . V_196 ) ;
if ( V_4 -> V_197 && V_4 -> V_16 . V_178 && V_4 -> V_52 )
V_103 . V_149 |= F_36 ( V_198 ) ;
return F_44 ( V_36 , & V_103 ) ;
}
static int F_53 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
T_3 V_119 )
{
struct V_102 V_103 = {} ;
T_3 V_34 = 0 ;
int V_49 , V_50 ;
F_48 ( V_4 -> type != V_131 ) ;
F_37 ( V_36 , V_4 , & V_103 , NULL , V_119 ) ;
if ( ! F_12 ( V_36 ) ) {
for ( V_50 = 0 ; V_50 < V_22 ; V_50 ++ )
if ( V_4 -> V_23 [ V_50 ] != V_24 )
V_34 |= F_7 ( V_4 -> V_23 [ V_50 ] ) ;
}
V_103 . V_149 = F_36 ( V_199 |
V_200 |
V_188 |
V_198 |
V_201 ) ;
F_54 ( V_36 -> V_42 , V_202 ) ;
V_49 = F_55 ( V_36 , & V_36 -> V_203 , V_34 ,
V_4 -> type , V_204 ) ;
if ( V_49 )
return V_49 ;
return F_44 ( V_36 , & V_103 ) ;
}
static int F_56 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
T_3 V_119 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_102 V_103 = {} ;
F_48 ( V_4 -> type != V_25 ) ;
F_37 ( V_36 , V_4 , & V_103 , NULL , V_119 ) ;
V_103 . V_149 = F_36 ( V_188 |
V_198 ) ;
V_103 . V_205 . V_189 = F_36 ( V_4 -> V_16 . V_17 ) ;
V_103 . V_205 . V_190 =
F_36 ( F_52 ( V_4 -> V_16 . V_17 ) ) ;
V_103 . V_205 . V_206 = F_36 ( V_8 -> V_46 ) ;
return F_44 ( V_36 , & V_103 ) ;
}
static void F_57 ( void * V_1 , T_1 * V_2 , struct V_3 * V_4 )
{
struct V_207 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 -> type == V_11 && V_4 -> V_52 &&
V_8 -> V_208 )
V_6 -> V_209 = true ;
}
static int F_58 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
T_3 V_119 )
{
struct V_102 V_103 = {} ;
struct V_207 V_6 = {} ;
F_48 ( V_4 -> type != V_20 ) ;
F_37 ( V_36 , V_4 , & V_103 , NULL , V_119 ) ;
V_103 . V_113 |= F_36 ( V_164 ) ;
V_103 . V_149 = F_36 ( V_198 ) ;
F_14 (
V_36 -> V_42 , V_43 ,
F_57 , & V_6 ) ;
V_103 . V_210 . V_211 = F_36 ( V_6 . V_209 ? 1 : 0 ) ;
return F_44 ( V_36 , & V_103 ) ;
}
static void F_59 ( struct V_35 * V_36 ,
T_4 * V_212 , T_4 * V_213 ,
T_1 * V_214 , T_3 V_215 )
{
T_3 V_216 ;
struct V_217 * V_218 = (struct V_217 * ) V_214 ;
V_216 = V_218 -> V_219 . V_214 . V_220 - V_214 ;
while ( ( V_216 < ( V_215 - 2 ) ) &&
( V_214 [ V_216 ] != V_221 ) )
V_216 += V_214 [ V_216 + 1 ] + 2 ;
if ( ( V_216 < ( V_215 - 1 ) ) && ( V_214 [ V_216 ] == V_221 ) ) {
* V_212 = F_36 ( V_216 ) ;
* V_213 = F_36 ( ( T_3 ) V_214 [ V_216 + 1 ] ) ;
} else {
F_60 ( V_36 , L_10 ) ;
}
}
static T_3 F_61 ( T_1 * V_214 , T_1 V_222 , T_3 V_215 )
{
struct V_217 * V_218 = ( void * ) V_214 ;
const T_1 * V_223 ;
if ( F_21 ( V_215 <= ( V_218 -> V_219 . V_214 . V_220 - V_214 ) ) )
return 0 ;
V_215 -= V_218 -> V_219 . V_214 . V_220 - V_214 ;
V_223 = F_62 ( V_222 , V_218 -> V_219 . V_214 . V_220 , V_215 ) ;
if ( ! V_223 )
return 0 ;
return V_223 - V_214 ;
}
static int F_63 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
struct V_224 * V_214 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_225 V_103 = {
. V_46 = V_226 ,
. V_227 = V_228 ,
} ;
union {
struct V_229 V_230 ;
struct V_231 V_232 ;
} V_219 = {} ;
struct V_233 V_232 = {} ;
struct V_234 * V_235 ;
T_3 V_236 ;
T_3 V_237 , V_238 ;
if ( F_48 ( ! V_214 ) )
return - V_239 ;
V_236 = V_214 -> V_240 ;
if ( F_64 ( & V_36 -> V_241 -> V_242 ,
V_243 ) ) {
T_3 V_244 , V_245 ;
V_244 = F_61 ( V_214 -> V_6 ,
V_246 ,
V_236 ) ;
V_245 =
F_61 ( V_214 -> V_6 ,
V_247 ,
V_236 ) ;
if ( F_65 ( V_36 ) ) {
V_232 . V_6 . V_248 =
F_36 ( ( T_3 ) V_8 -> V_46 ) ;
V_232 . V_6 . V_245 = F_36 ( V_245 ) ;
V_232 . V_6 . V_244 = F_36 ( V_244 ) ;
V_232 . V_249 = F_43 ( ( T_2 ) V_236 ) ;
if ( V_4 -> type == V_11 )
F_59 ( V_36 ,
& V_232 . V_6 . V_216 ,
& V_232 . V_6 . V_213 ,
V_214 -> V_6 ,
V_236 ) ;
V_103 . V_240 [ 0 ] = sizeof( V_232 ) ;
V_103 . V_6 [ 0 ] = & V_232 ;
goto V_250;
} else {
V_219 . V_232 . V_6 . V_245 =
F_36 ( V_245 ) ;
V_219 . V_232 . V_6 . V_244 = F_36 ( V_244 ) ;
V_103 . V_240 [ 0 ] = sizeof( V_219 . V_232 ) ;
V_103 . V_6 [ 0 ] = & V_219 ;
}
} else {
V_103 . V_240 [ 0 ] = sizeof( V_219 . V_230 ) ;
V_103 . V_6 [ 0 ] = & V_219 ;
}
V_219 . V_230 . V_248 = F_36 ( ( T_3 ) V_8 -> V_46 ) ;
V_235 = F_66 ( V_214 ) ;
V_219 . V_230 . V_251 . V_240 = F_43 ( ( T_2 ) V_236 ) ;
V_219 . V_230 . V_251 . V_37 = V_8 -> V_67 . V_37 ;
V_219 . V_230 . V_251 . V_252 = F_36 ( V_253 ) ;
V_238 = V_254 | V_255 ;
V_238 |=
F_67 ( V_36 , ( void * ) V_214 -> V_6 , V_235 , 0 ) <<
V_256 ;
V_219 . V_230 . V_251 . V_238 = F_36 ( V_238 ) ;
if ( ! F_64 ( & V_36 -> V_241 -> V_242 ,
V_257 ) ) {
V_36 -> V_258 =
F_68 ( V_36 , F_69 ( V_36 ) ,
V_36 -> V_258 ) ;
}
V_219 . V_230 . V_251 . V_259 =
F_36 ( F_7 ( V_36 -> V_258 ) <<
V_260 ) ;
if ( V_235 -> V_80 == V_261 || V_4 -> V_52 ) {
V_237 = V_95 ;
} else {
V_237 = V_96 ;
V_219 . V_230 . V_251 . V_259 |=
F_36 ( V_262 ) ;
}
V_219 . V_230 . V_251 . V_259 |=
F_36 ( F_70 ( V_237 ) ) ;
if ( V_4 -> type == V_11 )
F_59 ( V_36 , & V_219 . V_230 . V_216 ,
& V_219 . V_230 . V_213 ,
V_214 -> V_6 ,
V_236 ) ;
V_250:
V_103 . V_263 [ 0 ] = 0 ;
V_103 . V_240 [ 1 ] = V_236 ;
V_103 . V_6 [ 1 ] = V_214 -> V_6 ;
V_103 . V_263 [ 1 ] = V_264 ;
return F_71 ( V_36 , & V_103 ) ;
}
int F_72 ( struct V_35 * V_36 ,
struct V_3 * V_4 )
{
struct V_224 * V_214 ;
int V_49 ;
F_48 ( V_4 -> type != V_11 &&
V_4 -> type != V_25 ) ;
V_214 = F_73 ( V_36 -> V_42 , V_4 , NULL ) ;
if ( ! V_214 )
return - V_265 ;
V_49 = F_63 ( V_36 , V_4 , V_214 ) ;
F_74 ( V_214 ) ;
return V_49 ;
}
static void F_75 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_266 * V_6 = V_1 ;
if ( V_4 -> type != V_10 || ! V_4 -> V_16 . V_178 )
return;
if ( V_4 -> V_52 && V_6 -> V_267 )
return;
V_6 -> V_267 = V_4 -> V_16 . V_185 ;
V_6 -> V_17 = V_4 -> V_16 . V_17 ;
}
static void F_76 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
struct V_102 * V_103 ,
struct V_268 * V_269 ,
bool V_270 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_266 V_6 = {
. V_36 = V_36 ,
. V_4 = V_4 ,
. V_267 = 0
} ;
V_103 -> V_19 [ V_75 ] . V_159 |= F_7 ( V_76 ) ;
V_103 -> V_149 |= F_36 ( V_198 ) ;
if ( V_8 -> V_271 || ! V_36 -> V_272 ) {
V_103 -> V_149 |= F_36 ( V_188 ) ;
F_77 ( V_36 , L_11 ) ;
} else {
F_77 ( V_36 , L_12 ) ;
}
V_269 -> V_189 = F_36 ( V_4 -> V_16 . V_17 ) ;
V_269 -> V_190 =
F_36 ( F_52 ( V_4 -> V_16 . V_17 ) ) ;
V_269 -> V_191 = F_36 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_179 ) ;
V_269 -> V_192 =
F_36 ( F_52 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_179 ) ) ;
if ( ! F_78 ( & V_36 -> V_241 -> V_242 ,
V_273 ) )
V_269 -> V_274 = F_36 ( V_4 -> V_26 ) ;
if ( V_270 ) {
F_14 (
V_36 -> V_42 , V_43 ,
F_75 , & V_6 ) ;
if ( V_6 . V_267 ) {
T_3 rand = ( F_79 () % ( 64 - 36 ) ) + 36 ;
V_8 -> V_275 = V_6 . V_267 +
F_80 ( V_6 . V_17 * rand /
100 ) ;
} else {
V_8 -> V_275 =
F_81 ( V_36 -> V_276 ,
V_277 ) ;
}
}
V_269 -> V_278 = F_36 ( V_8 -> V_275 ) ;
V_269 -> V_279 = 0 ;
V_269 -> V_206 = F_36 ( V_8 -> V_46 ) ;
}
static int F_82 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
T_3 V_119 )
{
struct V_102 V_103 = {} ;
F_48 ( V_4 -> type != V_11 || V_4 -> V_52 ) ;
F_37 ( V_36 , V_4 , & V_103 , NULL , V_119 ) ;
F_76 ( V_36 , V_4 , & V_103 , & V_103 . V_280 ,
V_119 == V_281 ) ;
return F_44 ( V_36 , & V_103 ) ;
}
static int F_83 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
T_3 V_119 )
{
struct V_102 V_103 = {} ;
struct V_171 * V_172 = & V_4 -> V_16 . V_173 ;
F_48 ( V_4 -> type != V_11 || ! V_4 -> V_52 ) ;
F_37 ( V_36 , V_4 , & V_103 , NULL , V_119 ) ;
F_76 ( V_36 , V_4 , & V_103 , & V_103 . V_282 . V_280 ,
V_119 == V_281 ) ;
V_103 . V_282 . V_175 = F_36 ( V_172 -> V_176 &
V_177 ) ;
V_103 . V_282 . V_283 =
F_36 ( ! ! ( V_172 -> V_176 &
V_284 ) ) ;
return F_44 ( V_36 , & V_103 ) ;
}
static int F_84 ( struct V_35 * V_36 , struct V_3 * V_4 ,
T_3 V_119 , bool V_168 ,
const T_1 * V_118 )
{
switch ( V_4 -> type ) {
case V_10 :
return F_47 ( V_36 , V_4 , V_119 ,
V_168 ,
V_118 ) ;
break;
case V_11 :
if ( ! V_4 -> V_52 )
return F_82 ( V_36 , V_4 , V_119 ) ;
else
return F_83 ( V_36 , V_4 , V_119 ) ;
break;
case V_131 :
return F_53 ( V_36 , V_4 , V_119 ) ;
case V_20 :
return F_58 ( V_36 , V_4 , V_119 ) ;
case V_25 :
return F_56 ( V_36 , V_4 , V_119 ) ;
default:
break;
}
return - V_285 ;
}
int F_85 ( struct V_35 * V_36 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_49 ;
if ( F_86 ( V_8 -> V_286 , L_13 ,
V_4 -> V_136 , F_87 ( V_4 ) ) )
return - V_56 ;
V_49 = F_84 ( V_36 , V_4 , V_281 ,
true , NULL ) ;
if ( V_49 )
return V_49 ;
F_88 ( V_36 , V_4 ) ;
V_8 -> V_286 = true ;
return 0 ;
}
int F_89 ( struct V_35 * V_36 , struct V_3 * V_4 ,
bool V_168 , const T_1 * V_118 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( F_86 ( ! V_8 -> V_286 , L_14 ,
V_4 -> V_136 , F_87 ( V_4 ) ) )
return - V_56 ;
return F_84 ( V_36 , V_4 , V_287 ,
V_168 , V_118 ) ;
}
int F_90 ( struct V_35 * V_36 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_102 V_103 ;
int V_49 ;
if ( F_86 ( ! V_8 -> V_286 , L_15 ,
V_4 -> V_136 , F_87 ( V_4 ) ) )
return - V_56 ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
V_103 . V_126 = F_36 ( F_38 ( V_8 -> V_46 ,
V_8 -> V_58 ) ) ;
V_103 . V_119 = F_36 ( V_288 ) ;
V_49 = F_45 ( V_36 , V_167 , 0 ,
sizeof( V_103 ) , & V_103 ) ;
if ( V_49 ) {
F_22 ( V_36 , L_16 , V_49 ) ;
return V_49 ;
}
V_8 -> V_286 = false ;
if ( V_4 -> type == V_131 ) {
F_5 ( V_289 , V_36 -> V_42 -> V_227 ) ;
F_91 ( V_36 ) ;
}
return 0 ;
}
static void F_92 ( struct V_35 * V_36 ,
struct V_3 * V_290 , T_3 V_291 ,
bool V_292 )
{
struct V_7 * V_8 =
F_2 ( V_290 ) ;
if ( ! V_292 && ! V_8 -> V_293 )
return;
V_8 -> V_293 = true ;
if ( ! F_93 ( V_290 ) ) {
int V_294 = F_94 ( V_290 ) ;
F_72 ( V_36 , V_290 ) ;
if ( V_290 -> V_52 &&
! F_95 ( & V_8 -> V_59 ) && V_291 &&
V_292 ) {
T_3 V_295 = ( V_294 + 1 ) *
V_290 -> V_16 . V_17 -
V_296 ;
T_3 V_297 = V_291 + V_295 * 1024 ;
F_96 ( V_36 , V_290 ,
V_296 -
V_298 ,
V_297 ) ;
}
} else if ( ! F_95 ( & V_8 -> V_59 ) ) {
F_97 ( V_290 ) ;
F_98 ( V_36 -> V_290 , NULL ) ;
}
}
void F_99 ( struct V_35 * V_36 ,
struct V_299 * V_300 )
{
struct V_301 * V_302 = F_100 ( V_300 ) ;
struct V_303 * V_214 = ( void * ) V_302 -> V_6 ;
struct V_304 * V_305 ;
struct V_3 * V_290 ;
struct V_3 * V_306 ;
struct V_307 * V_308 ;
T_2 V_54 ;
F_13 ( & V_36 -> V_41 ) ;
V_305 = & V_214 -> V_305 ;
V_36 -> V_309 = F_46 ( V_214 -> V_291 ) ;
V_36 -> V_310 = V_214 -> V_311 != 0 ;
V_308 = F_101 ( V_36 , V_305 ) ;
V_54 = F_102 ( V_308 -> V_54 ) & V_312 ;
F_103 ( V_36 ,
L_17 ,
V_54 , V_305 -> V_313 ,
F_51 ( V_214 -> V_314 ) ,
V_36 -> V_309 ,
F_46 ( V_305 -> V_315 ) ) ;
V_290 = F_104 ( V_36 -> V_290 ,
F_105 ( & V_36 -> V_41 ) ) ;
if ( F_106 ( V_290 && V_290 -> V_316 ) )
F_92 ( V_36 , V_290 , V_36 -> V_309 ,
( V_54 == V_317 ) ) ;
V_306 = F_104 ( V_36 -> V_318 ,
F_105 ( & V_36 -> V_41 ) ) ;
if ( F_106 ( V_306 ) ) {
struct V_7 * V_8 =
F_2 ( V_306 ) ;
if ( ! V_36 -> V_319 )
V_36 -> V_319 =
V_320 ;
else
V_36 -> V_319 -- ;
if ( V_36 -> V_319 == 0 ) {
F_107 ( V_36 , V_8 , false ) ;
F_98 ( V_36 -> V_318 , NULL ) ;
}
}
}
static void F_108 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_321 * V_322 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_35 * V_36 = V_8 -> V_36 ;
struct V_323 * V_324 ;
struct V_325 * V_326 ;
T_3 V_327 , V_328 ;
T_3 V_329 , V_330 ;
if ( V_8 -> V_46 != ( T_2 ) F_46 ( V_322 -> V_331 ) )
return;
V_329 = F_46 ( V_322 -> V_332 ) ;
V_330 =
F_46 ( V_322 -> V_333 ) ;
if ( F_46 ( V_322 -> V_333 ) >
V_334 )
F_109 ( V_4 ) ;
if ( ! F_110 ( V_36 -> V_241 ,
V_335 ) )
return;
V_326 = F_111 ( V_36 -> V_241 ,
V_335 ) ;
V_324 = ( void * ) V_326 -> V_6 ;
V_327 = F_46 ( V_324 -> V_336 ) ;
V_328 =
F_46 ( V_324 -> V_337 ) ;
if ( ! F_112 ( V_36 , V_4 , V_326 ) )
return;
if ( V_330 >= V_328 ||
V_329 >= V_327 )
F_113 ( V_36 , V_326 , NULL ) ;
}
void F_114 ( struct V_35 * V_36 ,
struct V_299 * V_300 )
{
struct V_301 * V_302 = F_100 ( V_300 ) ;
struct V_321 * V_338 = ( void * ) V_302 -> V_6 ;
F_50 ( V_36 ,
L_18 ,
F_46 ( V_338 -> V_331 ) ,
F_46 ( V_338 -> V_332 ) ,
F_46 ( V_338 -> V_333 ) ,
F_46 ( V_338 -> V_339 ) ,
F_46 ( V_338 -> V_340 ) ) ;
F_14 ( V_36 -> V_42 ,
V_341 ,
F_108 ,
V_338 ) ;
}
void F_115 ( struct V_35 * V_36 ,
struct V_299 * V_300 )
{
struct V_301 * V_302 = F_100 ( V_300 ) ;
struct V_342 * V_343 = ( void * ) V_302 -> V_6 ;
struct V_344 V_345 ;
struct V_224 * V_346 ;
T_3 V_347 = F_46 ( V_343 -> V_348 ) ;
if ( V_347 == 0 )
return;
V_346 = F_116 ( V_347 , V_349 ) ;
if ( ! V_346 ) {
F_22 ( V_36 , L_19 ) ;
return;
}
memset ( & V_345 , 0 , sizeof( V_345 ) ) ;
V_345 . V_350 = F_51 ( V_343 -> V_314 ) ;
V_345 . V_351 |= V_352 ;
V_345 . V_353 = F_46 ( V_343 -> V_354 ) ;
V_345 . V_80 =
( V_343 -> V_80 & F_43 ( V_355 ) ) ?
V_142 : V_261 ;
V_345 . V_356 =
F_117 ( F_102 ( V_343 -> V_357 ) ,
V_345 . V_80 ) ;
F_118 ( V_346 , V_343 -> V_6 , V_347 ) ;
memcpy ( F_119 ( V_346 ) , & V_345 , sizeof( V_345 ) ) ;
F_120 ( V_36 -> V_42 , NULL , V_346 , NULL ) ;
}
void F_121 ( struct V_35 * V_36 ,
struct V_299 * V_300 )
{
struct V_301 * V_302 = F_100 ( V_300 ) ;
struct V_358 * V_359 = ( void * ) V_302 -> V_6 ;
struct V_3 * V_290 ;
struct V_7 * V_8 ;
int V_240 = F_122 ( V_302 ) ;
T_3 V_360 ;
if ( F_21 ( V_240 < sizeof( * V_359 ) ) )
return;
F_40 () ;
V_290 = F_41 ( V_36 -> V_290 ) ;
if ( F_48 ( ! V_290 || ! V_290 -> V_316 ) )
goto V_361;
V_360 = F_46 ( V_359 -> V_126 ) ;
V_8 = F_2 ( V_290 ) ;
if ( F_123 ( F_38 ( V_8 -> V_46 , V_8 -> V_58 ) != V_360 ,
L_20 ,
F_38 ( V_8 -> V_46 , V_8 -> V_58 ) , V_360 ) )
goto V_361;
F_50 ( V_36 , L_21 ) ;
F_124 ( & V_36 -> V_362 ,
F_125 ( V_320 *
V_290 -> V_16 . V_17 ) ) ;
F_97 ( V_290 ) ;
F_42 () ;
F_98 ( V_36 -> V_290 , NULL ) ;
return;
V_361:
F_42 () ;
}
