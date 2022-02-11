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
int V_49 , V_50 ;
unsigned long V_29 ;
switch ( V_4 -> type ) {
case V_25 :
break;
case V_10 :
if ( ! V_4 -> V_51 )
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
if ( F_21 ( F_3 ( V_52 , & V_36 -> V_53 ) ) )
return - V_54 ;
V_8 -> V_46 = F_19 ( V_6 . V_47 ,
V_48 ) ;
if ( V_8 -> V_46 == V_48 ) {
F_22 ( V_36 , L_1 ) ;
V_49 = - V_55 ;
goto V_56;
}
if ( V_6 . V_12 != V_13 )
V_8 -> V_14 = V_6 . V_12 ;
else
V_8 -> V_14 = F_19 ( V_6 . V_15 ,
V_13 ) ;
if ( V_8 -> V_14 == V_13 ) {
F_22 ( V_36 , L_2 ) ;
V_49 = - V_55 ;
goto V_56;
}
V_8 -> V_57 = 0 ;
F_23 ( & V_8 -> V_58 . V_59 ) ;
V_8 -> V_58 . V_46 = V_60 ;
if ( V_4 -> type == V_20 ) {
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
V_4 -> V_23 [ V_19 ] = V_24 ;
return 0 ;
}
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
T_1 V_61 = F_24 ( & V_29 ,
V_36 -> V_62 ) ;
if ( ! F_12 ( V_36 ) &&
V_61 >= V_36 -> V_62 ) {
F_22 ( V_36 , L_3 ) ;
V_49 = - V_55 ;
goto V_56;
}
F_25 ( V_61 , & V_29 ) ;
V_4 -> V_23 [ V_19 ] = V_61 ;
}
if ( V_4 -> type == V_11 ) {
T_1 V_61 ;
if ( ! F_12 ( V_36 ) ) {
V_61 = F_24 ( & V_29 ,
V_36 -> V_62 ) ;
if ( V_61 >= V_36 -> V_62 ) {
F_22 ( V_36 , L_4 ) ;
V_49 = - V_55 ;
goto V_56;
}
} else {
V_61 = V_63 ;
}
V_4 -> V_26 = V_61 ;
} else {
V_4 -> V_26 = V_24 ;
}
V_8 -> V_64 . V_37 = V_65 ;
V_8 -> V_66 = V_65 ;
for ( V_50 = 0 ; V_50 < V_67 ; V_50 ++ )
V_8 -> V_68 [ V_50 ] = V_69 ;
return 0 ;
V_56:
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
memset ( V_4 -> V_23 , V_24 , sizeof( V_4 -> V_23 ) ) ;
V_4 -> V_26 = V_24 ;
return V_49 ;
}
int F_26 ( struct V_35 * V_36 , struct V_3 * V_4 )
{
unsigned int V_70 =
F_27 ( V_36 , V_4 , false , false ) ;
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
F_28 ( V_36 , V_21 ,
V_21 ,
V_71 , 0 , V_70 ) ;
break;
case V_11 :
F_28 ( V_36 , V_4 -> V_26 , V_4 -> V_26 ,
V_72 , 0 , V_70 ) ;
default:
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
F_28 ( V_36 , V_4 -> V_23 [ V_19 ] ,
V_4 -> V_23 [ V_19 ] ,
V_73 [ V_19 ] , 0 ,
V_70 ) ;
break;
}
return 0 ;
}
void F_29 ( struct V_35 * V_36 , struct V_3 * V_4 )
{
int V_19 ;
F_13 ( & V_36 -> V_41 ) ;
if ( F_12 ( V_36 ) )
return;
switch ( V_4 -> type ) {
case V_20 :
F_30 ( V_36 , V_21 ,
V_21 ,
V_74 , 0 ) ;
break;
case V_11 :
F_30 ( V_36 , V_4 -> V_26 , V_4 -> V_26 ,
V_74 , 0 ) ;
default:
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
F_30 ( V_36 , V_4 -> V_23 [ V_19 ] ,
V_4 -> V_23 [ V_19 ] ,
V_74 , 0 ) ;
}
}
static void F_31 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
enum V_75 V_76 ,
T_1 * V_77 , T_1 * V_78 )
{
struct V_79 * V_80 ;
unsigned long V_81 = V_4 -> V_16 . V_82 ;
int V_83 = 100 ;
int V_84 = 100 ;
T_1 V_85 = 0 ;
T_1 V_86 = 0 ;
int V_50 ;
V_80 = V_36 -> V_42 -> V_87 -> V_88 [ V_76 ] ;
F_16 (i, &basic, BITS_PER_LONG) {
int V_42 = V_80 -> V_89 [ V_50 ] . V_90 ;
if ( V_42 >= V_91 ) {
V_86 |= F_7 ( V_42 - V_91 ) ;
if ( V_83 > V_42 )
V_83 = V_42 ;
} else {
F_32 ( V_92 != 0 ) ;
V_85 |= F_7 ( V_42 ) ;
if ( V_84 > V_42 )
V_84 = V_42 ;
}
}
if ( V_93 < V_83 )
V_86 |= F_33 ( 24 ) >> V_91 ;
if ( V_94 < V_83 )
V_86 |= F_33 ( 12 ) >> V_91 ;
V_86 |= F_33 ( 6 ) >> V_91 ;
if ( V_95 < V_84 )
V_85 |= F_33 ( 11 ) >> V_92 ;
if ( V_96 < V_84 )
V_85 |= F_33 ( 5 ) >> V_92 ;
if ( V_97 < V_84 )
V_85 |= F_33 ( 2 ) >> V_92 ;
V_85 |= F_33 ( 1 ) >> V_92 ;
* V_77 = V_85 ;
* V_78 = V_86 ;
}
static void F_34 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
struct V_98 * V_99 )
{
T_1 V_100 = V_4 -> V_16 . V_101 &
V_102 ;
T_3 V_103 = V_104 | V_105 ;
F_35 ( V_36 , L_5 , V_100 ) ;
switch ( V_100 ) {
case V_106 :
break;
case V_107 :
case V_108 :
V_99 -> V_109 |= F_36 ( V_103 ) ;
break;
case V_110 :
if ( V_4 -> V_16 . V_111 . V_112 > V_113 )
V_99 -> V_109 |= F_36 ( V_103 ) ;
break;
default:
F_22 ( V_36 , L_6 ,
V_100 ) ;
break;
}
}
static void F_37 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
struct V_98 * V_99 ,
const T_1 * V_114 ,
T_3 V_115 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_116 * V_117 ;
bool V_118 = ! ! ( V_4 -> V_16 . V_101 &
V_102 ) ;
T_1 V_119 , V_120 ;
const T_1 * V_121 = V_114 ? : V_4 -> V_16 . V_121 ;
int V_50 ;
V_99 -> V_122 = F_36 ( F_38 ( V_8 -> V_46 ,
V_8 -> V_57 ) ) ;
V_99 -> V_115 = F_36 ( V_115 ) ;
switch ( V_4 -> type ) {
case V_10 :
if ( V_4 -> V_51 )
V_99 -> V_123 = F_36 ( V_124 ) ;
else
V_99 -> V_123 = F_36 ( V_125 ) ;
break;
case V_11 :
V_99 -> V_123 = F_36 ( V_126 ) ;
break;
case V_127 :
V_99 -> V_123 = F_36 ( V_128 ) ;
break;
case V_20 :
V_99 -> V_123 = F_36 ( V_129 ) ;
break;
case V_25 :
V_99 -> V_123 = F_36 ( V_130 ) ;
break;
default:
F_21 ( 1 ) ;
}
V_99 -> V_14 = F_36 ( V_8 -> V_14 ) ;
memcpy ( V_99 -> V_131 , V_4 -> V_132 , V_133 ) ;
if ( V_121 )
memcpy ( V_99 -> V_134 , V_121 , V_133 ) ;
else
F_39 ( V_99 -> V_134 ) ;
F_40 () ;
V_117 = F_41 ( V_4 -> V_135 ) ;
F_31 ( V_36 , V_4 , V_117 ? V_117 -> V_136 . V_137 -> V_76
: V_138 ,
& V_119 , & V_120 ) ;
F_42 () ;
V_99 -> V_77 = F_36 ( ( T_3 ) V_119 ) ;
V_99 -> V_78 = F_36 ( ( T_3 ) V_120 ) ;
V_99 -> V_139 =
F_36 ( V_4 -> V_16 . V_140 ?
V_141 : 0 ) ;
V_99 -> V_142 =
F_36 ( V_4 -> V_16 . V_143 ?
V_144 : 0 ) ;
V_99 -> V_145 = F_36 ( V_146 ) ;
for ( V_50 = 0 ; V_50 < V_22 ; V_50 ++ ) {
T_1 V_147 = V_73 [ V_50 ] ;
V_99 -> V_19 [ V_147 ] . V_148 =
F_43 ( V_8 -> V_149 [ V_50 ] . V_148 ) ;
V_99 -> V_19 [ V_147 ] . V_150 =
F_43 ( V_8 -> V_149 [ V_50 ] . V_150 ) ;
V_99 -> V_19 [ V_147 ] . V_151 =
F_43 ( V_8 -> V_149 [ V_50 ] . V_152 * 32 ) ;
V_99 -> V_19 [ V_147 ] . V_153 = V_8 -> V_149 [ V_50 ] . V_154 ;
V_99 -> V_19 [ V_147 ] . V_155 = F_7 ( V_147 ) ;
}
if ( V_4 -> V_16 . V_156 )
V_99 -> V_157 |= F_36 ( V_158 ) ;
if ( V_4 -> V_16 . V_159 )
V_99 -> V_109 |= F_36 ( V_160 ) ;
F_35 ( V_36 , L_7 ,
V_4 -> V_16 . V_159 ,
V_4 -> V_16 . V_101 ) ;
if ( V_4 -> V_16 . V_111 . V_112 != V_161 )
V_99 -> V_157 |= F_36 ( V_162 ) ;
if ( V_118 )
F_34 ( V_36 , V_4 , V_99 ) ;
}
static int F_44 ( struct V_35 * V_36 ,
struct V_98 * V_99 )
{
int V_49 = F_45 ( V_36 , V_163 , 0 ,
sizeof( * V_99 ) , V_99 ) ;
if ( V_49 )
F_22 ( V_36 , L_8 ,
F_46 ( V_99 -> V_115 ) , V_49 ) ;
return V_49 ;
}
static int F_47 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
T_3 V_115 , bool V_164 ,
const T_1 * V_114 )
{
struct V_98 V_99 = {} ;
struct V_165 * V_166 ;
F_48 ( V_4 -> type != V_10 ) ;
F_37 ( V_36 , V_4 , & V_99 , V_114 , V_115 ) ;
if ( V_4 -> V_51 ) {
struct V_167 * V_168 =
& V_4 -> V_16 . V_169 ;
V_99 . V_170 . V_171 = F_36 ( V_168 -> V_172 &
V_173 ) ;
V_166 = & V_99 . V_170 . V_31 ;
} else {
V_166 = & V_99 . V_31 ;
}
if ( V_4 -> V_16 . V_174 && V_4 -> V_16 . V_175 &&
! V_164 ) {
T_3 V_176 ;
V_176 = V_4 -> V_16 . V_177 *
V_4 -> V_16 . V_17 ;
V_176 *= 1024 ;
V_166 -> V_178 =
F_49 ( V_4 -> V_16 . V_179 + V_176 ) ;
V_166 -> V_180 =
F_36 ( V_4 -> V_16 . V_181 + V_176 ) ;
F_50 ( V_36 , L_9 ,
F_51 ( V_166 -> V_178 ) ,
F_46 ( V_166 -> V_180 ) ,
V_176 ) ;
V_166 -> V_182 = F_36 ( 1 ) ;
} else {
V_166 -> V_182 = F_36 ( 0 ) ;
V_99 . V_145 |= F_36 ( V_183 ) ;
}
V_166 -> V_184 = F_36 ( V_4 -> V_16 . V_17 ) ;
V_166 -> V_185 =
F_36 ( F_52 ( V_4 -> V_16 . V_17 ) ) ;
V_166 -> V_186 = F_36 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_175 ) ;
V_166 -> V_187 =
F_36 ( F_52 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_175 ) ) ;
V_166 -> V_188 = F_36 ( V_36 -> V_42 -> V_189 . V_188 ) ;
V_166 -> V_190 = F_36 ( V_4 -> V_16 . V_191 ) ;
if ( V_4 -> V_192 && V_4 -> V_16 . V_174 && V_4 -> V_51 )
V_99 . V_145 |= F_36 ( V_193 ) ;
return F_44 ( V_36 , & V_99 ) ;
}
static int F_53 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
T_3 V_115 )
{
struct V_98 V_99 = {} ;
T_3 V_34 = 0 ;
int V_49 , V_50 ;
F_48 ( V_4 -> type != V_127 ) ;
F_37 ( V_36 , V_4 , & V_99 , NULL , V_115 ) ;
if ( ! F_12 ( V_36 ) ) {
for ( V_50 = 0 ; V_50 < V_22 ; V_50 ++ )
if ( V_4 -> V_23 [ V_50 ] != V_24 )
V_34 |= F_7 ( V_4 -> V_23 [ V_50 ] ) ;
}
V_99 . V_145 = F_36 ( V_194 |
V_195 |
V_183 |
V_193 |
V_196 ) ;
F_54 ( V_36 -> V_42 , V_197 ) ;
V_49 = F_55 ( V_36 , & V_36 -> V_198 , V_34 ,
V_4 -> type ) ;
if ( V_49 )
return V_49 ;
return F_44 ( V_36 , & V_99 ) ;
}
static int F_56 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
T_3 V_115 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_98 V_99 = {} ;
F_48 ( V_4 -> type != V_25 ) ;
F_37 ( V_36 , V_4 , & V_99 , NULL , V_115 ) ;
V_99 . V_145 = F_36 ( V_183 |
V_193 ) ;
V_99 . V_199 . V_184 = F_36 ( V_4 -> V_16 . V_17 ) ;
V_99 . V_199 . V_185 =
F_36 ( F_52 ( V_4 -> V_16 . V_17 ) ) ;
V_99 . V_199 . V_200 = F_36 ( V_8 -> V_46 ) ;
return F_44 ( V_36 , & V_99 ) ;
}
static void F_57 ( void * V_1 , T_1 * V_2 , struct V_3 * V_4 )
{
struct V_201 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 -> type == V_11 && V_4 -> V_51 &&
V_8 -> V_202 )
V_6 -> V_203 = true ;
}
static int F_58 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
T_3 V_115 )
{
struct V_98 V_99 = {} ;
struct V_201 V_6 = {} ;
F_48 ( V_4 -> type != V_20 ) ;
F_37 ( V_36 , V_4 , & V_99 , NULL , V_115 ) ;
V_99 . V_109 |= F_36 ( V_160 ) ;
V_99 . V_145 = F_36 ( V_193 ) ;
F_14 (
V_36 -> V_42 , V_43 ,
F_57 , & V_6 ) ;
V_99 . V_204 . V_205 = F_36 ( V_6 . V_203 ? 1 : 0 ) ;
return F_44 ( V_36 , & V_99 ) ;
}
static void F_59 ( struct V_35 * V_36 ,
T_4 * V_206 , T_4 * V_207 ,
T_1 * V_208 , T_3 V_209 )
{
T_3 V_210 ;
struct V_211 * V_212 = (struct V_211 * ) V_208 ;
V_210 = V_212 -> V_213 . V_208 . V_214 - V_208 ;
while ( ( V_210 < ( V_209 - 2 ) ) &&
( V_208 [ V_210 ] != V_215 ) )
V_210 += V_208 [ V_210 + 1 ] + 2 ;
if ( ( V_210 < ( V_209 - 1 ) ) && ( V_208 [ V_210 ] == V_215 ) ) {
* V_206 = F_36 ( V_210 ) ;
* V_207 = F_36 ( ( T_3 ) V_208 [ V_210 + 1 ] ) ;
} else {
F_60 ( V_36 , L_10 ) ;
}
}
static T_3 F_61 ( T_1 * V_208 , T_1 V_216 , T_3 V_209 )
{
struct V_211 * V_212 = ( void * ) V_208 ;
const T_1 * V_217 ;
if ( F_21 ( V_209 <= ( V_212 -> V_213 . V_208 . V_214 - V_208 ) ) )
return 0 ;
V_209 -= V_212 -> V_213 . V_208 . V_214 - V_208 ;
V_217 = F_62 ( V_216 , V_212 -> V_213 . V_208 . V_214 , V_209 ) ;
if ( ! V_217 )
return 0 ;
return V_217 - V_208 ;
}
static int F_63 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
struct V_218 * V_208 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_219 V_99 = {
. V_46 = V_220 ,
. V_221 = V_222 ,
} ;
union {
struct V_223 V_224 ;
struct V_225 V_226 ;
} V_213 = {} ;
struct V_227 V_226 ;
struct V_228 * V_229 ;
T_3 V_230 ;
T_3 V_231 , V_232 ;
if ( F_48 ( ! V_208 ) )
return - V_233 ;
V_230 = V_208 -> V_234 ;
if ( F_64 ( & V_36 -> V_235 -> V_236 ,
V_237 ) ) {
T_3 V_238 , V_239 ;
V_238 = F_61 ( V_208 -> V_6 ,
V_240 ,
V_230 ) ;
V_239 =
F_61 ( V_208 -> V_6 ,
V_241 ,
V_230 ) ;
if ( F_65 ( V_36 ) ) {
V_226 . V_6 . V_242 =
F_36 ( ( T_3 ) V_8 -> V_46 ) ;
V_226 . V_6 . V_239 = F_36 ( V_239 ) ;
V_226 . V_6 . V_238 = F_36 ( V_238 ) ;
V_226 . V_243 = F_43 ( ( T_2 ) V_230 ) ;
if ( V_4 -> type == V_11 )
F_59 ( V_36 ,
& V_226 . V_6 . V_210 ,
& V_226 . V_6 . V_207 ,
V_208 -> V_6 ,
V_230 ) ;
V_99 . V_234 [ 0 ] = sizeof( V_226 ) ;
V_99 . V_6 [ 0 ] = & V_226 ;
goto V_244;
} else {
V_213 . V_226 . V_6 . V_239 =
F_36 ( V_239 ) ;
V_213 . V_226 . V_6 . V_238 = F_36 ( V_238 ) ;
V_99 . V_234 [ 0 ] = sizeof( V_213 . V_226 ) ;
V_99 . V_6 [ 0 ] = & V_213 ;
}
} else {
V_99 . V_234 [ 0 ] = sizeof( V_213 . V_224 ) ;
V_99 . V_6 [ 0 ] = & V_213 ;
}
V_213 . V_224 . V_242 = F_36 ( ( T_3 ) V_8 -> V_46 ) ;
V_229 = F_66 ( V_208 ) ;
V_213 . V_224 . V_245 . V_234 = F_43 ( ( T_2 ) V_230 ) ;
V_213 . V_224 . V_245 . V_37 = V_8 -> V_64 . V_37 ;
V_213 . V_224 . V_245 . V_246 = F_36 ( V_247 ) ;
V_232 = V_248 | V_249 ;
V_232 |=
F_67 ( V_36 , ( void * ) V_208 -> V_6 , V_229 , 0 ) <<
V_250 ;
V_213 . V_224 . V_245 . V_232 = F_36 ( V_232 ) ;
if ( ! F_64 ( & V_36 -> V_235 -> V_236 ,
V_251 ) ) {
V_36 -> V_252 =
F_68 ( V_36 , F_69 ( V_36 ) ,
V_36 -> V_252 ) ;
}
V_213 . V_224 . V_245 . V_253 =
F_36 ( F_7 ( V_36 -> V_252 ) <<
V_254 ) ;
if ( V_229 -> V_76 == V_255 || V_4 -> V_51 ) {
V_231 = V_91 ;
} else {
V_231 = V_92 ;
V_213 . V_224 . V_245 . V_253 |=
F_36 ( V_256 ) ;
}
V_213 . V_224 . V_245 . V_253 |=
F_36 ( F_70 ( V_231 ) ) ;
if ( V_4 -> type == V_11 )
F_59 ( V_36 , & V_213 . V_224 . V_210 ,
& V_213 . V_224 . V_207 ,
V_208 -> V_6 ,
V_230 ) ;
V_244:
V_99 . V_257 [ 0 ] = 0 ;
V_99 . V_234 [ 1 ] = V_230 ;
V_99 . V_6 [ 1 ] = V_208 -> V_6 ;
V_99 . V_257 [ 1 ] = V_258 ;
return F_71 ( V_36 , & V_99 ) ;
}
int F_72 ( struct V_35 * V_36 ,
struct V_3 * V_4 )
{
struct V_218 * V_208 ;
int V_49 ;
F_48 ( V_4 -> type != V_11 &&
V_4 -> type != V_25 ) ;
V_208 = F_73 ( V_36 -> V_42 , V_4 , NULL ) ;
if ( ! V_208 )
return - V_259 ;
V_49 = F_63 ( V_36 , V_4 , V_208 ) ;
F_74 ( V_208 ) ;
return V_49 ;
}
static void F_75 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_260 * V_6 = V_1 ;
if ( V_4 -> type != V_10 || ! V_4 -> V_16 . V_174 )
return;
if ( V_4 -> V_51 && V_6 -> V_261 )
return;
V_6 -> V_261 = V_4 -> V_16 . V_181 ;
V_6 -> V_17 = V_4 -> V_16 . V_17 ;
}
static void F_76 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
struct V_98 * V_99 ,
struct V_262 * V_263 ,
bool V_264 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_260 V_6 = {
. V_36 = V_36 ,
. V_4 = V_4 ,
. V_261 = 0
} ;
V_99 -> V_19 [ V_71 ] . V_155 |= F_7 ( V_72 ) ;
V_99 -> V_145 |= F_36 ( V_193 ) ;
if ( V_8 -> V_265 || ! V_36 -> V_266 ) {
V_99 -> V_145 |= F_36 ( V_183 ) ;
F_77 ( V_36 , L_11 ) ;
} else {
F_77 ( V_36 , L_12 ) ;
}
V_263 -> V_184 = F_36 ( V_4 -> V_16 . V_17 ) ;
V_263 -> V_185 =
F_36 ( F_52 ( V_4 -> V_16 . V_17 ) ) ;
V_263 -> V_186 = F_36 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_175 ) ;
V_263 -> V_187 =
F_36 ( F_52 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_175 ) ) ;
V_263 -> V_267 = F_36 ( V_4 -> V_26 ) ;
if ( V_264 ) {
F_14 (
V_36 -> V_42 , V_43 ,
F_75 , & V_6 ) ;
if ( V_6 . V_261 ) {
T_3 rand = ( F_78 () % ( 64 - 36 ) ) + 36 ;
V_8 -> V_268 = V_6 . V_261 +
F_79 ( V_6 . V_17 * rand /
100 ) ;
} else {
V_8 -> V_268 =
F_80 ( V_36 -> V_269 ,
V_270 ) ;
}
}
V_263 -> V_271 = F_36 ( V_8 -> V_268 ) ;
V_263 -> V_272 = 0 ;
V_263 -> V_200 = F_36 ( V_8 -> V_46 ) ;
}
static int F_81 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
T_3 V_115 )
{
struct V_98 V_99 = {} ;
F_48 ( V_4 -> type != V_11 || V_4 -> V_51 ) ;
F_37 ( V_36 , V_4 , & V_99 , NULL , V_115 ) ;
F_76 ( V_36 , V_4 , & V_99 , & V_99 . V_273 ,
V_115 == V_274 ) ;
return F_44 ( V_36 , & V_99 ) ;
}
static int F_82 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
T_3 V_115 )
{
struct V_98 V_99 = {} ;
struct V_167 * V_168 = & V_4 -> V_16 . V_169 ;
F_48 ( V_4 -> type != V_11 || ! V_4 -> V_51 ) ;
F_37 ( V_36 , V_4 , & V_99 , NULL , V_115 ) ;
F_76 ( V_36 , V_4 , & V_99 , & V_99 . V_275 . V_273 ,
V_115 == V_274 ) ;
V_99 . V_275 . V_171 = F_36 ( V_168 -> V_172 &
V_173 ) ;
V_99 . V_275 . V_276 =
F_36 ( ! ! ( V_168 -> V_172 &
V_277 ) ) ;
return F_44 ( V_36 , & V_99 ) ;
}
static int F_83 ( struct V_35 * V_36 , struct V_3 * V_4 ,
T_3 V_115 , bool V_164 ,
const T_1 * V_114 )
{
switch ( V_4 -> type ) {
case V_10 :
return F_47 ( V_36 , V_4 , V_115 ,
V_164 ,
V_114 ) ;
break;
case V_11 :
if ( ! V_4 -> V_51 )
return F_81 ( V_36 , V_4 , V_115 ) ;
else
return F_82 ( V_36 , V_4 , V_115 ) ;
break;
case V_127 :
return F_53 ( V_36 , V_4 , V_115 ) ;
case V_20 :
return F_58 ( V_36 , V_4 , V_115 ) ;
case V_25 :
return F_56 ( V_36 , V_4 , V_115 ) ;
default:
break;
}
return - V_278 ;
}
int F_84 ( struct V_35 * V_36 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_49 ;
if ( F_85 ( V_8 -> V_279 , L_13 ,
V_4 -> V_132 , F_86 ( V_4 ) ) )
return - V_55 ;
V_49 = F_83 ( V_36 , V_4 , V_274 ,
true , NULL ) ;
if ( V_49 )
return V_49 ;
F_87 ( V_36 , V_4 ) ;
V_8 -> V_279 = true ;
return 0 ;
}
int F_88 ( struct V_35 * V_36 , struct V_3 * V_4 ,
bool V_164 , const T_1 * V_114 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( F_85 ( ! V_8 -> V_279 , L_14 ,
V_4 -> V_132 , F_86 ( V_4 ) ) )
return - V_55 ;
return F_83 ( V_36 , V_4 , V_280 ,
V_164 , V_114 ) ;
}
int F_89 ( struct V_35 * V_36 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_98 V_99 ;
int V_49 ;
if ( F_85 ( ! V_8 -> V_279 , L_15 ,
V_4 -> V_132 , F_86 ( V_4 ) ) )
return - V_55 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . V_122 = F_36 ( F_38 ( V_8 -> V_46 ,
V_8 -> V_57 ) ) ;
V_99 . V_115 = F_36 ( V_281 ) ;
V_49 = F_45 ( V_36 , V_163 , 0 ,
sizeof( V_99 ) , & V_99 ) ;
if ( V_49 ) {
F_22 ( V_36 , L_16 , V_49 ) ;
return V_49 ;
}
V_8 -> V_279 = false ;
if ( V_4 -> type == V_127 ) {
F_5 ( V_282 , V_36 -> V_42 -> V_221 ) ;
F_90 ( V_36 ) ;
}
return 0 ;
}
static void F_91 ( struct V_35 * V_36 ,
struct V_3 * V_283 , T_3 V_284 ,
bool V_285 )
{
struct V_7 * V_8 =
F_2 ( V_283 ) ;
if ( ! V_285 && ! V_8 -> V_286 )
return;
V_8 -> V_286 = true ;
if ( ! F_92 ( V_283 ) ) {
int V_287 = F_93 ( V_283 ) ;
F_72 ( V_36 , V_283 ) ;
if ( V_283 -> V_51 &&
! F_94 ( & V_8 -> V_58 ) && V_284 &&
V_285 ) {
T_3 V_288 = ( V_287 + 1 ) *
V_283 -> V_16 . V_17 -
V_289 ;
T_3 V_290 = V_284 + V_288 * 1024 ;
F_95 ( V_36 , V_283 ,
V_289 -
V_291 ,
V_290 ) ;
}
} else if ( ! F_94 ( & V_8 -> V_58 ) ) {
F_96 ( V_283 ) ;
F_97 ( V_36 -> V_283 , NULL ) ;
}
}
void F_98 ( struct V_35 * V_36 ,
struct V_292 * V_293 )
{
struct V_294 * V_295 = F_99 ( V_293 ) ;
struct V_296 * V_208 = ( void * ) V_295 -> V_6 ;
struct V_297 * V_298 ;
struct V_3 * V_283 ;
struct V_3 * V_299 ;
T_2 V_53 ;
F_13 ( & V_36 -> V_41 ) ;
V_298 = & V_208 -> V_298 ;
V_36 -> V_300 = F_46 ( V_208 -> V_284 ) ;
V_53 = F_100 ( V_298 -> V_53 . V_53 ) & V_301 ;
F_101 ( V_36 ,
L_17 ,
V_53 , V_298 -> V_302 ,
F_51 ( V_208 -> V_303 ) ,
V_36 -> V_300 ,
F_46 ( V_298 -> V_304 ) ) ;
V_283 = F_102 ( V_36 -> V_283 ,
F_103 ( & V_36 -> V_41 ) ) ;
if ( F_104 ( V_283 && V_283 -> V_305 ) )
F_91 ( V_36 , V_283 , V_36 -> V_300 ,
( V_53 == V_306 ) ) ;
V_299 = F_102 ( V_36 -> V_307 ,
F_103 ( & V_36 -> V_41 ) ) ;
if ( F_104 ( V_299 ) ) {
struct V_7 * V_8 =
F_2 ( V_299 ) ;
if ( ! V_36 -> V_308 )
V_36 -> V_308 =
V_309 ;
else
V_36 -> V_308 -- ;
if ( V_36 -> V_308 == 0 ) {
F_105 ( V_36 , V_8 , false ) ;
F_97 ( V_36 -> V_307 , NULL ) ;
}
}
}
static void F_106 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_310 * V_311 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_35 * V_36 = V_8 -> V_36 ;
struct V_312 * V_313 ;
struct V_314 * V_315 ;
T_3 V_316 , V_317 ;
T_3 V_318 , V_319 ;
if ( V_8 -> V_46 != ( T_2 ) F_46 ( V_311 -> V_320 ) )
return;
V_318 = F_46 ( V_311 -> V_321 ) ;
V_319 =
F_46 ( V_311 -> V_322 ) ;
if ( F_46 ( V_311 -> V_322 ) >
V_323 )
F_107 ( V_4 ) ;
if ( ! F_108 ( V_36 -> V_235 ,
V_324 ) )
return;
V_315 = F_109 ( V_36 -> V_235 ,
V_324 ) ;
V_313 = ( void * ) V_315 -> V_6 ;
V_316 = F_46 ( V_313 -> V_325 ) ;
V_317 =
F_46 ( V_313 -> V_326 ) ;
if ( ! F_110 ( V_36 , V_4 , V_315 ) )
return;
if ( V_319 >= V_317 ||
V_318 >= V_316 )
F_111 ( V_36 , V_315 , NULL ) ;
}
void F_112 ( struct V_35 * V_36 ,
struct V_292 * V_293 )
{
struct V_294 * V_295 = F_99 ( V_293 ) ;
struct V_310 * V_327 = ( void * ) V_295 -> V_6 ;
F_50 ( V_36 ,
L_18 ,
F_46 ( V_327 -> V_320 ) ,
F_46 ( V_327 -> V_321 ) ,
F_46 ( V_327 -> V_322 ) ,
F_46 ( V_327 -> V_328 ) ,
F_46 ( V_327 -> V_329 ) ) ;
F_14 ( V_36 -> V_42 ,
V_330 ,
F_106 ,
V_327 ) ;
}
void F_113 ( struct V_35 * V_36 ,
struct V_292 * V_293 )
{
struct V_294 * V_295 = F_99 ( V_293 ) ;
struct V_331 * V_332 = ( void * ) V_295 -> V_6 ;
struct V_333 V_334 ;
struct V_218 * V_335 ;
T_3 V_336 = F_46 ( V_332 -> V_337 ) ;
if ( V_336 == 0 )
return;
V_335 = F_114 ( V_336 , V_338 ) ;
if ( ! V_335 ) {
F_22 ( V_36 , L_19 ) ;
return;
}
memset ( & V_334 , 0 , sizeof( V_334 ) ) ;
V_334 . V_339 = F_51 ( V_332 -> V_303 ) ;
V_334 . V_340 |= V_341 ;
V_334 . V_342 = F_46 ( V_332 -> V_343 ) ;
V_334 . V_76 =
( V_332 -> V_76 & F_43 ( V_344 ) ) ?
V_138 : V_255 ;
V_334 . V_345 =
F_115 ( F_100 ( V_332 -> V_346 ) ,
V_334 . V_76 ) ;
memcpy ( F_116 ( V_335 , V_336 ) , V_332 -> V_6 , V_336 ) ;
memcpy ( F_117 ( V_335 ) , & V_334 , sizeof( V_334 ) ) ;
F_118 ( V_36 -> V_42 , NULL , V_335 , NULL ) ;
}
void F_119 ( struct V_35 * V_36 ,
struct V_292 * V_293 )
{
struct V_294 * V_295 = F_99 ( V_293 ) ;
struct V_347 * V_348 = ( void * ) V_295 -> V_6 ;
struct V_3 * V_283 ;
struct V_7 * V_8 ;
int V_234 = F_120 ( V_295 ) ;
T_3 V_349 ;
if ( F_21 ( V_234 < sizeof( * V_348 ) ) )
return;
F_40 () ;
V_283 = F_41 ( V_36 -> V_283 ) ;
if ( F_48 ( ! V_283 || ! V_283 -> V_305 ) )
goto V_350;
V_349 = F_46 ( V_348 -> V_122 ) ;
V_8 = F_2 ( V_283 ) ;
if ( F_121 ( F_38 ( V_8 -> V_46 , V_8 -> V_57 ) != V_349 ,
L_20 ,
F_38 ( V_8 -> V_46 , V_8 -> V_57 ) , V_349 ) )
goto V_350;
F_50 ( V_36 , L_21 ) ;
F_122 ( V_351 , & V_36 -> V_352 ,
F_123 ( V_309 *
V_283 -> V_16 . V_17 ) ) ;
F_96 ( V_283 ) ;
F_42 () ;
F_97 ( V_36 -> V_283 , NULL ) ;
return;
V_350:
F_42 () ;
}
