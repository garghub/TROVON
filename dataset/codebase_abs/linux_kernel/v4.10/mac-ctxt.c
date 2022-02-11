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
F_7 ( V_35 -> V_37 ) ,
} ;
if ( F_12 ( V_35 ) )
V_6 . V_28 |= F_7 ( V_38 ) ;
else
V_6 . V_28 |= F_7 ( V_39 ) ;
F_13 ( & V_35 -> V_40 ) ;
F_14 (
V_35 -> V_41 , V_42 ,
F_8 , & V_6 ) ;
F_15 ( V_35 -> V_41 ,
F_9 ,
& V_6 ) ;
F_16 (sta_id, mvm->sta_drained, IWL_MVM_STATION_COUNT)
V_6 . V_28 |= V_35 -> V_43 [ V_36 ] ;
return V_6 . V_28 ;
}
static void F_17 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 == V_6 -> V_4 ) {
V_6 -> V_44 = true ;
return;
}
F_5 ( V_8 -> V_45 , V_6 -> V_46 ) ;
F_1 ( V_1 , V_2 , V_4 ) ;
}
void F_18 ( struct V_34 * V_35 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_5 V_6 = {
. V_35 = V_35 ,
. V_4 = V_4 ,
. V_15 = { ( 1 << V_13 ) - 1 } ,
. V_12 = V_13 ,
} ;
F_14 (
V_35 -> V_41 , V_42 ,
F_1 , & V_6 ) ;
if ( V_6 . V_12 != V_13 )
V_8 -> V_14 = V_6 . V_12 ;
else if ( ! F_3 ( V_8 -> V_14 , V_6 . V_15 ) )
V_8 -> V_14 = F_19 ( V_6 . V_15 ,
V_13 ) ;
}
static int F_20 ( struct V_34 * V_35 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_5 V_6 = {
. V_35 = V_35 ,
. V_4 = V_4 ,
. V_46 = { ( 1 << V_47 ) - 1 } ,
. V_15 = { ( 1 << V_13 ) - 1 } ,
. V_12 = V_13 ,
. V_44 = false ,
} ;
T_3 V_19 ;
int V_48 , V_49 ;
unsigned long V_28 ;
switch ( V_4 -> type ) {
case V_50 :
break;
case V_10 :
if ( ! V_4 -> V_51 )
break;
default:
F_5 ( 0 , V_6 . V_46 ) ;
}
F_14 (
V_35 -> V_41 , V_42 ,
F_17 , & V_6 ) ;
V_28 = F_11 ( V_35 , V_4 ) ;
if ( V_6 . V_44 )
return 0 ;
if ( F_21 ( F_3 ( V_52 , & V_35 -> V_53 ) ) )
return - V_54 ;
V_8 -> V_45 = F_19 ( V_6 . V_46 ,
V_47 ) ;
if ( V_8 -> V_45 == V_47 ) {
F_22 ( V_35 , L_1 ) ;
V_48 = - V_55 ;
goto V_56;
}
if ( V_6 . V_12 != V_13 )
V_8 -> V_14 = V_6 . V_12 ;
else
V_8 -> V_14 = F_19 ( V_6 . V_15 ,
V_13 ) ;
if ( V_8 -> V_14 == V_13 ) {
F_22 ( V_35 , L_2 ) ;
V_48 = - V_55 ;
goto V_56;
}
V_8 -> V_57 = 0 ;
F_23 ( & V_8 -> V_58 . V_59 ) ;
V_8 -> V_58 . V_45 = V_60 ;
if ( V_4 -> type == V_20 ) {
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
V_4 -> V_23 [ V_19 ] = V_24 ;
return 0 ;
}
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
T_1 V_61 = F_24 ( & V_28 ,
V_35 -> V_62 ) ;
if ( ! F_12 ( V_35 ) &&
V_61 >= V_35 -> V_62 ) {
F_22 ( V_35 , L_3 ) ;
V_48 = - V_55 ;
goto V_56;
}
F_25 ( V_61 , & V_28 ) ;
V_4 -> V_23 [ V_19 ] = V_61 ;
}
if ( V_4 -> type == V_11 ) {
T_1 V_61 ;
if ( ! F_12 ( V_35 ) ) {
V_61 = F_24 ( & V_28 ,
V_35 -> V_62 ) ;
if ( V_61 >= V_35 -> V_62 ) {
F_22 ( V_35 , L_4 ) ;
V_48 = - V_55 ;
goto V_56;
}
} else {
V_61 = V_63 ;
}
V_4 -> V_25 = V_61 ;
} else {
V_4 -> V_25 = V_24 ;
}
V_8 -> V_64 . V_36 = V_65 ;
V_8 -> V_66 = V_65 ;
for ( V_49 = 0 ; V_49 < V_67 ; V_49 ++ )
V_8 -> V_68 [ V_49 ] = V_69 ;
return 0 ;
V_56:
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
memset ( V_4 -> V_23 , V_24 , sizeof( V_4 -> V_23 ) ) ;
V_4 -> V_25 = V_24 ;
return V_48 ;
}
int F_26 ( struct V_34 * V_35 , struct V_3 * V_4 )
{
unsigned int V_70 =
F_27 ( V_35 , V_4 , false , false ) ;
T_3 V_19 ;
int V_48 ;
F_13 ( & V_35 -> V_40 ) ;
V_48 = F_20 ( V_35 , V_4 ) ;
if ( V_48 )
return V_48 ;
if ( F_12 ( V_35 ) )
return 0 ;
switch ( V_4 -> type ) {
case V_20 :
F_28 ( V_35 , V_21 ,
V_21 ,
V_71 , 0 , V_70 ) ;
break;
case V_11 :
F_28 ( V_35 , V_4 -> V_25 , V_4 -> V_25 ,
V_72 , 0 , V_70 ) ;
default:
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
F_28 ( V_35 , V_4 -> V_23 [ V_19 ] ,
V_4 -> V_23 [ V_19 ] ,
V_73 [ V_19 ] , 0 ,
V_70 ) ;
break;
}
return 0 ;
}
void F_29 ( struct V_34 * V_35 , struct V_3 * V_4 )
{
int V_19 ;
F_13 ( & V_35 -> V_40 ) ;
switch ( V_4 -> type ) {
case V_20 :
if ( ! F_12 ( V_35 ) )
F_30 ( V_35 , V_21 ,
V_21 ,
V_74 , 0 ) ;
else
F_30 ( V_35 ,
V_75 ,
V_4 -> V_23 [ 0 ] , V_74 ,
0 ) ;
break;
case V_11 :
F_30 ( V_35 , V_4 -> V_25 , V_4 -> V_25 ,
V_74 , 0 ) ;
if ( F_12 ( V_35 ) )
F_30 ( V_35 ,
V_76 ,
V_4 -> V_23 [ 0 ] , V_74 ,
0 ) ;
default:
if ( F_12 ( V_35 ) )
break;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
F_30 ( V_35 , V_4 -> V_23 [ V_19 ] ,
V_4 -> V_23 [ V_19 ] ,
V_74 , 0 ) ;
}
}
static void F_31 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
enum V_77 V_78 ,
T_1 * V_79 , T_1 * V_80 )
{
struct V_81 * V_82 ;
unsigned long V_83 = V_4 -> V_16 . V_84 ;
int V_85 = 100 ;
int V_86 = 100 ;
T_1 V_87 = 0 ;
T_1 V_88 = 0 ;
int V_49 ;
V_82 = V_35 -> V_41 -> V_89 -> V_90 [ V_78 ] ;
F_16 (i, &basic, BITS_PER_LONG) {
int V_41 = V_82 -> V_91 [ V_49 ] . V_92 ;
if ( V_41 >= V_93 ) {
V_88 |= F_7 ( V_41 - V_93 ) ;
if ( V_85 > V_41 )
V_85 = V_41 ;
} else {
F_32 ( V_94 != 0 ) ;
V_87 |= F_7 ( V_41 ) ;
if ( V_86 > V_41 )
V_86 = V_41 ;
}
}
if ( V_95 < V_85 )
V_88 |= F_33 ( 24 ) >> V_93 ;
if ( V_96 < V_85 )
V_88 |= F_33 ( 12 ) >> V_93 ;
V_88 |= F_33 ( 6 ) >> V_93 ;
if ( V_97 < V_86 )
V_87 |= F_33 ( 11 ) >> V_94 ;
if ( V_98 < V_86 )
V_87 |= F_33 ( 5 ) >> V_94 ;
if ( V_99 < V_86 )
V_87 |= F_33 ( 2 ) >> V_94 ;
V_87 |= F_33 ( 1 ) >> V_94 ;
* V_79 = V_87 ;
* V_80 = V_88 ;
}
static void F_34 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
struct V_100 * V_101 )
{
T_1 V_102 = V_4 -> V_16 . V_103 &
V_104 ;
T_3 V_105 = V_106 | V_107 ;
F_35 ( V_35 , L_5 , V_102 ) ;
switch ( V_102 ) {
case V_108 :
break;
case V_109 :
case V_110 :
V_101 -> V_111 |= F_36 ( V_105 ) ;
break;
case V_112 :
if ( V_4 -> V_16 . V_113 . V_114 > V_115 )
V_101 -> V_111 |= F_36 ( V_105 ) ;
break;
default:
F_22 ( V_35 , L_6 ,
V_102 ) ;
break;
}
}
static void F_37 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
struct V_100 * V_101 ,
const T_1 * V_116 ,
T_3 V_117 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_118 * V_119 ;
bool V_120 = ! ! ( V_4 -> V_16 . V_103 &
V_104 ) ;
T_1 V_121 , V_122 ;
const T_1 * V_123 = V_116 ? : V_4 -> V_16 . V_123 ;
int V_49 ;
V_101 -> V_124 = F_36 ( F_38 ( V_8 -> V_45 ,
V_8 -> V_57 ) ) ;
V_101 -> V_117 = F_36 ( V_117 ) ;
switch ( V_4 -> type ) {
case V_10 :
if ( V_4 -> V_51 )
V_101 -> V_125 = F_36 ( V_126 ) ;
else
V_101 -> V_125 = F_36 ( V_127 ) ;
break;
case V_11 :
V_101 -> V_125 = F_36 ( V_128 ) ;
break;
case V_129 :
V_101 -> V_125 = F_36 ( V_130 ) ;
break;
case V_20 :
V_101 -> V_125 = F_36 ( V_131 ) ;
break;
case V_50 :
V_101 -> V_125 = F_36 ( V_132 ) ;
break;
default:
F_21 ( 1 ) ;
}
V_101 -> V_14 = F_36 ( V_8 -> V_14 ) ;
memcpy ( V_101 -> V_133 , V_4 -> V_134 , V_135 ) ;
if ( V_123 )
memcpy ( V_101 -> V_136 , V_123 , V_135 ) ;
else
F_39 ( V_101 -> V_136 ) ;
F_40 () ;
V_119 = F_41 ( V_4 -> V_137 ) ;
F_31 ( V_35 , V_4 , V_119 ? V_119 -> V_138 . V_139 -> V_78
: V_140 ,
& V_121 , & V_122 ) ;
F_42 () ;
V_101 -> V_79 = F_36 ( ( T_3 ) V_121 ) ;
V_101 -> V_80 = F_36 ( ( T_3 ) V_122 ) ;
V_101 -> V_141 =
F_36 ( V_4 -> V_16 . V_142 ?
V_143 : 0 ) ;
V_101 -> V_144 =
F_36 ( V_4 -> V_16 . V_145 ?
V_146 : 0 ) ;
V_101 -> V_147 = F_36 ( V_148 ) ;
for ( V_49 = 0 ; V_49 < V_22 ; V_49 ++ ) {
T_1 V_149 = V_73 [ V_49 ] ;
V_101 -> V_19 [ V_149 ] . V_150 =
F_43 ( V_8 -> V_151 [ V_49 ] . V_150 ) ;
V_101 -> V_19 [ V_149 ] . V_152 =
F_43 ( V_8 -> V_151 [ V_49 ] . V_152 ) ;
V_101 -> V_19 [ V_149 ] . V_153 =
F_43 ( V_8 -> V_151 [ V_49 ] . V_154 * 32 ) ;
V_101 -> V_19 [ V_149 ] . V_155 = V_8 -> V_151 [ V_49 ] . V_156 ;
V_101 -> V_19 [ V_149 ] . V_157 = F_7 ( V_149 ) ;
}
if ( V_4 -> V_16 . V_158 )
V_101 -> V_159 |= F_36 ( V_160 ) ;
if ( V_4 -> V_16 . V_161 )
V_101 -> V_111 |= F_36 ( V_162 ) ;
F_35 ( V_35 , L_7 ,
V_4 -> V_16 . V_161 ,
V_4 -> V_16 . V_103 ) ;
if ( V_4 -> V_16 . V_113 . V_114 != V_163 )
V_101 -> V_159 |= F_36 ( V_164 ) ;
if ( V_120 )
F_34 ( V_35 , V_4 , V_101 ) ;
}
static int F_44 ( struct V_34 * V_35 ,
struct V_100 * V_101 )
{
int V_48 = F_45 ( V_35 , V_165 , 0 ,
sizeof( * V_101 ) , V_101 ) ;
if ( V_48 )
F_22 ( V_35 , L_8 ,
F_46 ( V_101 -> V_117 ) , V_48 ) ;
return V_48 ;
}
static int F_47 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_117 , bool V_166 ,
const T_1 * V_116 )
{
struct V_100 V_101 = {} ;
struct V_167 * V_168 ;
F_48 ( V_4 -> type != V_10 ) ;
F_37 ( V_35 , V_4 , & V_101 , V_116 , V_117 ) ;
if ( V_4 -> V_51 ) {
struct V_169 * V_170 =
& V_4 -> V_16 . V_171 ;
V_101 . V_172 . V_173 = F_36 ( V_170 -> V_174 &
V_175 ) ;
V_168 = & V_101 . V_172 . V_30 ;
} else {
V_168 = & V_101 . V_30 ;
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
F_36 ( V_4 -> V_16 . V_183 + V_178 ) ;
F_50 ( V_35 , L_9 ,
F_51 ( V_168 -> V_180 ) ,
F_46 ( V_168 -> V_182 ) ,
V_178 ) ;
V_168 -> V_184 = F_36 ( 1 ) ;
} else {
V_168 -> V_184 = F_36 ( 0 ) ;
V_101 . V_147 |= F_36 ( V_185 ) ;
}
V_168 -> V_186 = F_36 ( V_4 -> V_16 . V_17 ) ;
V_168 -> V_187 =
F_36 ( F_52 ( V_4 -> V_16 . V_17 ) ) ;
V_168 -> V_188 = F_36 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_177 ) ;
V_168 -> V_189 =
F_36 ( F_52 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_177 ) ) ;
V_168 -> V_190 = F_36 ( V_35 -> V_41 -> V_191 . V_190 ) ;
V_168 -> V_192 = F_36 ( V_4 -> V_16 . V_193 ) ;
if ( V_4 -> V_194 && V_4 -> V_16 . V_176 && V_4 -> V_51 )
V_101 . V_147 |= F_36 ( V_195 ) ;
return F_44 ( V_35 , & V_101 ) ;
}
static int F_53 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_117 )
{
struct V_100 V_101 = {} ;
T_3 V_33 = 0 ;
int V_48 , V_49 ;
F_48 ( V_4 -> type != V_129 ) ;
F_37 ( V_35 , V_4 , & V_101 , NULL , V_117 ) ;
if ( ! F_12 ( V_35 ) ) {
for ( V_49 = 0 ; V_49 < V_22 ; V_49 ++ )
if ( V_4 -> V_23 [ V_49 ] != V_24 )
V_33 |= F_7 ( V_4 -> V_23 [ V_49 ] ) ;
}
V_101 . V_147 = F_36 ( V_196 |
V_197 |
V_185 |
V_195 |
V_198 ) ;
F_54 ( V_35 -> V_41 , V_199 ) ;
V_48 = F_55 ( V_35 , & V_35 -> V_200 , V_33 ,
V_4 -> type ) ;
if ( V_48 )
return V_48 ;
return F_44 ( V_35 , & V_101 ) ;
}
static int F_56 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_117 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_100 V_101 = {} ;
F_48 ( V_4 -> type != V_50 ) ;
F_37 ( V_35 , V_4 , & V_101 , NULL , V_117 ) ;
V_101 . V_147 = F_36 ( V_185 |
V_195 ) ;
V_101 . V_201 . V_186 = F_36 ( V_4 -> V_16 . V_17 ) ;
V_101 . V_201 . V_187 =
F_36 ( F_52 ( V_4 -> V_16 . V_17 ) ) ;
V_101 . V_201 . V_202 = F_36 ( V_8 -> V_45 ) ;
return F_44 ( V_35 , & V_101 ) ;
}
static void F_57 ( void * V_1 , T_1 * V_2 , struct V_3 * V_4 )
{
struct V_203 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 -> type == V_11 && V_4 -> V_51 &&
V_8 -> V_204 )
V_6 -> V_205 = true ;
}
static int F_58 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_117 )
{
struct V_100 V_101 = {} ;
struct V_203 V_6 = {} ;
F_48 ( V_4 -> type != V_20 ) ;
F_37 ( V_35 , V_4 , & V_101 , NULL , V_117 ) ;
V_101 . V_111 |= F_36 ( V_162 ) ;
V_101 . V_147 = F_36 ( V_195 ) ;
F_14 (
V_35 -> V_41 , V_42 ,
F_57 , & V_6 ) ;
V_101 . V_206 . V_207 = F_36 ( V_6 . V_205 ? 1 : 0 ) ;
return F_44 ( V_35 , & V_101 ) ;
}
static void F_59 ( struct V_34 * V_35 ,
struct V_208 * V_209 ,
T_1 * V_210 , T_3 V_211 )
{
T_3 V_212 ;
struct V_213 * V_214 = (struct V_213 * ) V_210 ;
V_212 = V_214 -> V_215 . V_210 . V_216 - V_210 ;
while ( ( V_212 < ( V_211 - 2 ) ) &&
( V_210 [ V_212 ] != V_217 ) )
V_212 += V_210 [ V_212 + 1 ] + 2 ;
if ( ( V_212 < ( V_211 - 1 ) ) && ( V_210 [ V_212 ] == V_217 ) ) {
V_209 -> V_212 = F_36 ( V_212 ) ;
V_209 -> V_218 = F_36 ( ( T_3 ) V_210 [ V_212 + 1 ] ) ;
} else {
F_60 ( V_35 , L_10 ) ;
}
}
static T_3 F_61 ( T_1 * V_210 , T_1 V_219 , T_3 V_211 )
{
struct V_213 * V_214 = ( void * ) V_210 ;
const T_1 * V_220 ;
if ( F_21 ( V_211 <= ( V_214 -> V_215 . V_210 . V_216 - V_210 ) ) )
return 0 ;
V_211 -= V_214 -> V_215 . V_210 . V_216 - V_210 ;
V_220 = F_62 ( V_219 , V_214 -> V_215 . V_210 . V_216 , V_211 ) ;
if ( ! V_220 )
return 0 ;
return V_220 - V_210 ;
}
static int F_63 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
struct V_221 * V_210 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_222 V_101 = {
. V_45 = V_223 ,
. V_224 = V_225 ,
} ;
union {
struct V_208 V_226 ;
struct V_227 V_209 ;
} V_215 = {} ;
struct V_228 * V_229 ;
T_3 V_230 ;
T_3 V_231 , V_232 ;
if ( F_48 ( ! V_210 ) )
return - V_233 ;
V_230 = V_210 -> V_234 ;
V_215 . V_226 . V_235 = F_36 ( ( T_3 ) V_8 -> V_45 ) ;
V_229 = F_64 ( V_210 ) ;
V_215 . V_226 . V_236 . V_234 = F_43 ( ( T_2 ) V_230 ) ;
V_215 . V_226 . V_236 . V_36 = V_8 -> V_64 . V_36 ;
V_215 . V_226 . V_236 . V_237 = F_36 ( V_238 ) ;
V_232 = V_239 | V_240 ;
V_232 |=
F_65 ( V_35 , ( void * ) V_210 -> V_6 , V_229 , 0 ) <<
V_241 ;
V_215 . V_226 . V_236 . V_232 = F_36 ( V_232 ) ;
if ( ! F_66 ( & V_35 -> V_242 -> V_243 ,
V_244 ) ) {
V_35 -> V_245 =
F_67 ( V_35 , F_68 ( V_35 ) ,
V_35 -> V_245 ) ;
}
V_215 . V_226 . V_236 . V_246 =
F_36 ( F_7 ( V_35 -> V_245 ) <<
V_247 ) ;
if ( V_229 -> V_78 == V_248 || V_4 -> V_51 ) {
V_231 = V_93 ;
} else {
V_231 = V_94 ;
V_215 . V_226 . V_236 . V_246 |=
F_36 ( V_249 ) ;
}
V_215 . V_226 . V_236 . V_246 |=
F_36 ( F_69 ( V_231 ) ) ;
if ( V_4 -> type == V_11 )
F_59 ( V_35 , & V_215 . V_226 ,
V_210 -> V_6 ,
V_230 ) ;
if ( F_66 ( & V_35 -> V_242 -> V_243 ,
V_250 ) ) {
V_215 . V_209 . V_251 =
F_36 ( F_61 ( V_210 -> V_6 ,
V_252 ,
V_230 ) ) ;
V_215 . V_209 . V_253 =
F_36 ( F_61 ( V_210 -> V_6 ,
V_254 ,
V_230 ) ) ;
V_101 . V_234 [ 0 ] = sizeof( V_215 . V_209 ) ;
} else {
V_101 . V_234 [ 0 ] = sizeof( V_215 . V_226 ) ;
}
V_101 . V_6 [ 0 ] = & V_215 ;
V_101 . V_255 [ 0 ] = 0 ;
V_101 . V_234 [ 1 ] = V_230 ;
V_101 . V_6 [ 1 ] = V_210 -> V_6 ;
V_101 . V_255 [ 1 ] = V_256 ;
return F_70 ( V_35 , & V_101 ) ;
}
int F_71 ( struct V_34 * V_35 ,
struct V_3 * V_4 )
{
struct V_221 * V_210 ;
int V_48 ;
F_48 ( V_4 -> type != V_11 &&
V_4 -> type != V_50 ) ;
V_210 = F_72 ( V_35 -> V_41 , V_4 , NULL ) ;
if ( ! V_210 )
return - V_257 ;
V_48 = F_63 ( V_35 , V_4 , V_210 ) ;
F_73 ( V_210 ) ;
return V_48 ;
}
static void F_74 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_258 * V_6 = V_1 ;
if ( V_4 -> type != V_10 || ! V_4 -> V_16 . V_176 )
return;
if ( V_4 -> V_51 && V_6 -> V_259 )
return;
V_6 -> V_259 = V_4 -> V_16 . V_183 ;
V_6 -> V_17 = V_4 -> V_16 . V_17 ;
}
static void F_75 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
struct V_100 * V_101 ,
struct V_260 * V_261 ,
bool V_262 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_258 V_6 = {
. V_35 = V_35 ,
. V_4 = V_4 ,
. V_259 = 0
} ;
V_101 -> V_19 [ V_71 ] . V_157 |= F_7 ( V_72 ) ;
V_101 -> V_147 |= F_36 ( V_195 ) ;
if ( V_8 -> V_263 || ! V_35 -> V_264 ) {
V_101 -> V_147 |= F_36 ( V_185 ) ;
F_76 ( V_35 , L_11 ) ;
} else {
F_76 ( V_35 , L_12 ) ;
}
V_261 -> V_186 = F_36 ( V_4 -> V_16 . V_17 ) ;
V_261 -> V_187 =
F_36 ( F_52 ( V_4 -> V_16 . V_17 ) ) ;
V_261 -> V_188 = F_36 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_177 ) ;
V_261 -> V_189 =
F_36 ( F_52 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_177 ) ) ;
V_261 -> V_265 = F_36 ( V_4 -> V_25 ) ;
if ( V_262 ) {
F_14 (
V_35 -> V_41 , V_42 ,
F_74 , & V_6 ) ;
if ( V_6 . V_259 ) {
T_3 rand = ( F_77 () % ( 64 - 36 ) ) + 36 ;
V_8 -> V_266 = V_6 . V_259 +
F_78 ( V_6 . V_17 * rand /
100 ) ;
} else {
V_8 -> V_266 =
F_79 ( V_35 -> V_267 ,
V_268 ) ;
}
}
V_261 -> V_269 = F_36 ( V_8 -> V_266 ) ;
V_261 -> V_270 = 0 ;
V_261 -> V_202 = F_36 ( V_8 -> V_45 ) ;
}
static int F_80 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_117 )
{
struct V_100 V_101 = {} ;
F_48 ( V_4 -> type != V_11 || V_4 -> V_51 ) ;
F_37 ( V_35 , V_4 , & V_101 , NULL , V_117 ) ;
F_75 ( V_35 , V_4 , & V_101 , & V_101 . V_271 ,
V_117 == V_272 ) ;
return F_44 ( V_35 , & V_101 ) ;
}
static int F_81 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_117 )
{
struct V_100 V_101 = {} ;
struct V_169 * V_170 = & V_4 -> V_16 . V_171 ;
F_48 ( V_4 -> type != V_11 || ! V_4 -> V_51 ) ;
F_37 ( V_35 , V_4 , & V_101 , NULL , V_117 ) ;
F_75 ( V_35 , V_4 , & V_101 , & V_101 . V_273 . V_271 ,
V_117 == V_272 ) ;
V_101 . V_273 . V_173 = F_36 ( V_170 -> V_174 &
V_175 ) ;
V_101 . V_273 . V_274 =
F_36 ( ! ! ( V_170 -> V_174 &
V_275 ) ) ;
return F_44 ( V_35 , & V_101 ) ;
}
static int F_82 ( struct V_34 * V_35 , struct V_3 * V_4 ,
T_3 V_117 , bool V_166 ,
const T_1 * V_116 )
{
switch ( V_4 -> type ) {
case V_10 :
return F_47 ( V_35 , V_4 , V_117 ,
V_166 ,
V_116 ) ;
break;
case V_11 :
if ( ! V_4 -> V_51 )
return F_80 ( V_35 , V_4 , V_117 ) ;
else
return F_81 ( V_35 , V_4 , V_117 ) ;
break;
case V_129 :
return F_53 ( V_35 , V_4 , V_117 ) ;
case V_20 :
return F_58 ( V_35 , V_4 , V_117 ) ;
case V_50 :
return F_56 ( V_35 , V_4 , V_117 ) ;
default:
break;
}
return - V_276 ;
}
int F_83 ( struct V_34 * V_35 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_48 ;
if ( F_84 ( V_8 -> V_277 , L_13 ,
V_4 -> V_134 , F_85 ( V_4 ) ) )
return - V_55 ;
V_48 = F_82 ( V_35 , V_4 , V_272 ,
true , NULL ) ;
if ( V_48 )
return V_48 ;
F_86 ( V_35 , V_4 ) ;
V_8 -> V_277 = true ;
return 0 ;
}
int F_87 ( struct V_34 * V_35 , struct V_3 * V_4 ,
bool V_166 , const T_1 * V_116 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( F_84 ( ! V_8 -> V_277 , L_14 ,
V_4 -> V_134 , F_85 ( V_4 ) ) )
return - V_55 ;
return F_82 ( V_35 , V_4 , V_278 ,
V_166 , V_116 ) ;
}
int F_88 ( struct V_34 * V_35 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_100 V_101 ;
int V_48 ;
if ( F_84 ( ! V_8 -> V_277 , L_15 ,
V_4 -> V_134 , F_85 ( V_4 ) ) )
return - V_55 ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
V_101 . V_124 = F_36 ( F_38 ( V_8 -> V_45 ,
V_8 -> V_57 ) ) ;
V_101 . V_117 = F_36 ( V_279 ) ;
V_48 = F_45 ( V_35 , V_165 , 0 ,
sizeof( V_101 ) , & V_101 ) ;
if ( V_48 ) {
F_22 ( V_35 , L_16 , V_48 ) ;
return V_48 ;
}
V_8 -> V_277 = false ;
if ( V_4 -> type == V_129 ) {
F_5 ( V_280 , V_35 -> V_41 -> V_224 ) ;
F_89 ( V_35 ) ;
}
return 0 ;
}
static void F_90 ( struct V_34 * V_35 ,
struct V_3 * V_281 , T_3 V_282 ,
bool V_283 )
{
struct V_7 * V_8 =
F_2 ( V_281 ) ;
if ( ! V_283 && ! V_8 -> V_284 )
return;
V_8 -> V_284 = true ;
if ( ! F_91 ( V_281 ) ) {
int V_285 = F_92 ( V_281 ) ;
F_71 ( V_35 , V_281 ) ;
if ( V_281 -> V_51 &&
! F_93 ( & V_8 -> V_58 ) && V_282 &&
V_283 ) {
T_3 V_286 = ( V_285 + 1 ) *
V_281 -> V_16 . V_17 -
V_287 ;
T_3 V_288 = V_282 + V_286 * 1024 ;
F_94 ( V_35 , V_281 ,
V_287 -
V_289 ,
V_288 ) ;
}
} else if ( ! F_93 ( & V_8 -> V_58 ) ) {
F_95 ( V_281 ) ;
F_96 ( V_35 -> V_281 , NULL ) ;
}
}
void F_97 ( struct V_34 * V_35 ,
struct V_290 * V_291 )
{
struct V_292 * V_293 = F_98 ( V_291 ) ;
struct V_294 * V_210 = ( void * ) V_293 -> V_6 ;
struct V_295 * V_296 ;
struct V_3 * V_281 ;
struct V_3 * V_297 ;
T_2 V_53 ;
F_13 ( & V_35 -> V_40 ) ;
V_296 = & V_210 -> V_296 ;
V_35 -> V_298 = F_46 ( V_210 -> V_282 ) ;
V_53 = F_99 ( V_296 -> V_53 . V_53 ) & V_299 ;
F_100 ( V_35 ,
L_17 ,
V_53 , V_296 -> V_300 ,
F_51 ( V_210 -> V_301 ) ,
V_35 -> V_298 ,
F_46 ( V_296 -> V_302 ) ) ;
V_281 = F_101 ( V_35 -> V_281 ,
F_102 ( & V_35 -> V_40 ) ) ;
if ( F_103 ( V_281 && V_281 -> V_303 ) )
F_90 ( V_35 , V_281 , V_35 -> V_298 ,
( V_53 == V_304 ) ) ;
V_297 = F_101 ( V_35 -> V_305 ,
F_102 ( & V_35 -> V_40 ) ) ;
if ( F_103 ( V_297 ) ) {
struct V_7 * V_8 =
F_2 ( V_297 ) ;
if ( ! V_35 -> V_306 )
V_35 -> V_306 =
V_307 ;
else
V_35 -> V_306 -- ;
if ( V_35 -> V_306 == 0 ) {
F_104 ( V_35 , V_8 , false ) ;
F_96 ( V_35 -> V_305 , NULL ) ;
}
}
}
static void F_105 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_308 * V_309 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_34 * V_35 = V_8 -> V_35 ;
struct V_310 * V_311 ;
struct V_312 * V_313 ;
T_3 V_314 , V_315 ;
T_3 V_316 , V_317 ;
if ( V_8 -> V_45 != ( T_2 ) F_46 ( V_309 -> V_318 ) )
return;
V_316 = F_46 ( V_309 -> V_319 ) ;
V_317 =
F_46 ( V_309 -> V_320 ) ;
if ( F_46 ( V_309 -> V_320 ) >
V_321 )
F_106 ( V_4 ) ;
if ( ! F_107 ( V_35 -> V_242 ,
V_322 ) )
return;
V_313 = F_108 ( V_35 -> V_242 ,
V_322 ) ;
V_311 = ( void * ) V_313 -> V_6 ;
V_314 = F_46 ( V_311 -> V_323 ) ;
V_315 =
F_46 ( V_311 -> V_324 ) ;
if ( ! F_109 ( V_35 , V_4 , V_313 ) )
return;
if ( V_317 >= V_315 ||
V_316 >= V_314 )
F_110 ( V_35 , V_313 , NULL ) ;
}
void F_111 ( struct V_34 * V_35 ,
struct V_290 * V_291 )
{
struct V_292 * V_293 = F_98 ( V_291 ) ;
struct V_308 * V_325 = ( void * ) V_293 -> V_6 ;
F_50 ( V_35 ,
L_18 ,
F_46 ( V_325 -> V_318 ) ,
F_46 ( V_325 -> V_319 ) ,
F_46 ( V_325 -> V_320 ) ,
F_46 ( V_325 -> V_326 ) ,
F_46 ( V_325 -> V_327 ) ) ;
F_14 ( V_35 -> V_41 ,
V_328 ,
F_105 ,
V_325 ) ;
}
void F_112 ( struct V_34 * V_35 ,
struct V_290 * V_291 )
{
struct V_292 * V_293 = F_98 ( V_291 ) ;
struct V_329 * V_330 = ( void * ) V_293 -> V_6 ;
struct V_331 V_332 ;
struct V_221 * V_333 ;
T_3 V_334 = F_46 ( V_330 -> V_335 ) ;
if ( V_334 == 0 )
return;
V_333 = F_113 ( V_334 , V_336 ) ;
if ( ! V_333 ) {
F_22 ( V_35 , L_19 ) ;
return;
}
memset ( & V_332 , 0 , sizeof( V_332 ) ) ;
V_332 . V_337 = F_51 ( V_330 -> V_301 ) ;
V_332 . V_338 |= V_339 ;
V_332 . V_340 = F_46 ( V_330 -> V_341 ) ;
V_332 . V_78 =
( V_330 -> V_342 & F_43 ( V_343 ) ) ?
V_140 : V_248 ;
V_332 . V_344 =
F_114 ( F_99 ( V_330 -> V_345 ) ,
V_332 . V_78 ) ;
memcpy ( F_115 ( V_333 , V_334 ) , V_330 -> V_6 , V_334 ) ;
memcpy ( F_116 ( V_333 ) , & V_332 , sizeof( V_332 ) ) ;
F_117 ( V_35 -> V_41 , NULL , V_333 , NULL ) ;
}
void F_118 ( struct V_34 * V_35 ,
struct V_290 * V_291 )
{
struct V_292 * V_293 = F_98 ( V_291 ) ;
struct V_346 * V_347 = ( void * ) V_293 -> V_6 ;
struct V_3 * V_281 ;
struct V_7 * V_8 ;
int V_234 = F_119 ( V_293 ) ;
T_3 V_348 ;
if ( F_21 ( V_234 < sizeof( * V_347 ) ) )
return;
F_40 () ;
V_281 = F_41 ( V_35 -> V_281 ) ;
if ( F_48 ( ! V_281 || ! V_281 -> V_303 ) )
goto V_349;
V_348 = F_46 ( V_347 -> V_124 ) ;
V_8 = F_2 ( V_281 ) ;
if ( F_120 ( F_38 ( V_8 -> V_45 , V_8 -> V_57 ) != V_348 ,
L_20 ,
F_38 ( V_8 -> V_45 , V_8 -> V_57 ) , V_348 ) )
goto V_349;
F_50 ( V_35 , L_21 ) ;
F_121 ( V_350 , & V_35 -> V_351 ,
F_122 ( V_307 *
V_281 -> V_16 . V_17 ) ) ;
F_95 ( V_281 ) ;
F_42 () ;
F_96 ( V_35 -> V_281 , NULL ) ;
return;
V_349:
F_42 () ;
}
