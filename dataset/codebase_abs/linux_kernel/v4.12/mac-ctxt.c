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
V_8 -> V_26 = V_61 ;
V_4 -> V_26 = V_61 ;
} else {
V_4 -> V_26 = V_24 ;
}
V_8 -> V_64 . V_37 = V_65 ;
V_8 -> V_66 . V_37 = V_65 ;
V_8 -> V_67 = V_65 ;
for ( V_50 = 0 ; V_50 < V_68 ; V_50 ++ )
V_8 -> V_69 [ V_50 ] = V_70 ;
return 0 ;
V_56:
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
memset ( V_4 -> V_23 , V_24 , sizeof( V_4 -> V_23 ) ) ;
V_4 -> V_26 = V_24 ;
return V_49 ;
}
int F_26 ( struct V_35 * V_36 , struct V_3 * V_4 )
{
unsigned int V_71 =
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
V_72 , 0 , V_71 ) ;
break;
case V_11 :
F_28 ( V_36 , V_4 -> V_26 , V_4 -> V_26 ,
V_73 , 0 , V_71 ) ;
default:
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
F_28 ( V_36 , V_4 -> V_23 [ V_19 ] ,
V_4 -> V_23 [ V_19 ] ,
V_74 [ V_19 ] , 0 ,
V_71 ) ;
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
V_75 , 0 ) ;
break;
case V_11 :
F_30 ( V_36 , V_4 -> V_26 , V_4 -> V_26 ,
V_75 , 0 ) ;
default:
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
F_30 ( V_36 , V_4 -> V_23 [ V_19 ] ,
V_4 -> V_23 [ V_19 ] ,
V_75 , 0 ) ;
}
}
static void F_31 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
enum V_76 V_77 ,
T_1 * V_78 , T_1 * V_79 )
{
struct V_80 * V_81 ;
unsigned long V_82 = V_4 -> V_16 . V_83 ;
int V_84 = 100 ;
int V_85 = 100 ;
T_1 V_86 = 0 ;
T_1 V_87 = 0 ;
int V_50 ;
V_81 = V_36 -> V_42 -> V_88 -> V_89 [ V_77 ] ;
F_16 (i, &basic, BITS_PER_LONG) {
int V_42 = V_81 -> V_90 [ V_50 ] . V_91 ;
if ( V_42 >= V_92 ) {
V_87 |= F_7 ( V_42 - V_92 ) ;
if ( V_84 > V_42 )
V_84 = V_42 ;
} else {
F_32 ( V_93 != 0 ) ;
V_86 |= F_7 ( V_42 ) ;
if ( V_85 > V_42 )
V_85 = V_42 ;
}
}
if ( V_94 < V_84 )
V_87 |= F_33 ( 24 ) >> V_92 ;
if ( V_95 < V_84 )
V_87 |= F_33 ( 12 ) >> V_92 ;
V_87 |= F_33 ( 6 ) >> V_92 ;
if ( V_96 < V_85 )
V_86 |= F_33 ( 11 ) >> V_93 ;
if ( V_97 < V_85 )
V_86 |= F_33 ( 5 ) >> V_93 ;
if ( V_98 < V_85 )
V_86 |= F_33 ( 2 ) >> V_93 ;
V_86 |= F_33 ( 1 ) >> V_93 ;
* V_78 = V_86 ;
* V_79 = V_87 ;
}
static void F_34 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
struct V_99 * V_100 )
{
T_1 V_101 = V_4 -> V_16 . V_102 &
V_103 ;
T_3 V_104 = V_105 | V_106 ;
F_35 ( V_36 , L_5 , V_101 ) ;
switch ( V_101 ) {
case V_107 :
break;
case V_108 :
case V_109 :
V_100 -> V_110 |= F_36 ( V_104 ) ;
break;
case V_111 :
if ( V_4 -> V_16 . V_112 . V_113 > V_114 )
V_100 -> V_110 |= F_36 ( V_104 ) ;
break;
default:
F_22 ( V_36 , L_6 ,
V_101 ) ;
break;
}
}
static void F_37 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
struct V_99 * V_100 ,
const T_1 * V_115 ,
T_3 V_116 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_117 * V_118 ;
bool V_119 = ! ! ( V_4 -> V_16 . V_102 &
V_103 ) ;
T_1 V_120 , V_121 ;
const T_1 * V_122 = V_115 ? : V_4 -> V_16 . V_122 ;
int V_50 ;
V_100 -> V_123 = F_36 ( F_38 ( V_8 -> V_46 ,
V_8 -> V_57 ) ) ;
V_100 -> V_116 = F_36 ( V_116 ) ;
switch ( V_4 -> type ) {
case V_10 :
if ( V_4 -> V_51 )
V_100 -> V_124 = F_36 ( V_125 ) ;
else
V_100 -> V_124 = F_36 ( V_126 ) ;
break;
case V_11 :
V_100 -> V_124 = F_36 ( V_127 ) ;
break;
case V_128 :
V_100 -> V_124 = F_36 ( V_129 ) ;
break;
case V_20 :
V_100 -> V_124 = F_36 ( V_130 ) ;
break;
case V_25 :
V_100 -> V_124 = F_36 ( V_131 ) ;
break;
default:
F_21 ( 1 ) ;
}
V_100 -> V_14 = F_36 ( V_8 -> V_14 ) ;
memcpy ( V_100 -> V_132 , V_4 -> V_133 , V_134 ) ;
if ( V_122 )
memcpy ( V_100 -> V_135 , V_122 , V_134 ) ;
else
F_39 ( V_100 -> V_135 ) ;
F_40 () ;
V_118 = F_41 ( V_4 -> V_136 ) ;
F_31 ( V_36 , V_4 , V_118 ? V_118 -> V_137 . V_138 -> V_77
: V_139 ,
& V_120 , & V_121 ) ;
F_42 () ;
V_100 -> V_78 = F_36 ( ( T_3 ) V_120 ) ;
V_100 -> V_79 = F_36 ( ( T_3 ) V_121 ) ;
V_100 -> V_140 =
F_36 ( V_4 -> V_16 . V_141 ?
V_142 : 0 ) ;
V_100 -> V_143 =
F_36 ( V_4 -> V_16 . V_144 ?
V_145 : 0 ) ;
V_100 -> V_146 = F_36 ( V_147 ) ;
for ( V_50 = 0 ; V_50 < V_22 ; V_50 ++ ) {
T_1 V_148 = V_74 [ V_50 ] ;
V_100 -> V_19 [ V_148 ] . V_149 =
F_43 ( V_8 -> V_150 [ V_50 ] . V_149 ) ;
V_100 -> V_19 [ V_148 ] . V_151 =
F_43 ( V_8 -> V_150 [ V_50 ] . V_151 ) ;
V_100 -> V_19 [ V_148 ] . V_152 =
F_43 ( V_8 -> V_150 [ V_50 ] . V_153 * 32 ) ;
V_100 -> V_19 [ V_148 ] . V_154 = V_8 -> V_150 [ V_50 ] . V_155 ;
V_100 -> V_19 [ V_148 ] . V_156 = F_7 ( V_148 ) ;
}
if ( V_4 -> V_16 . V_157 )
V_100 -> V_158 |= F_36 ( V_159 ) ;
if ( V_4 -> V_16 . V_160 )
V_100 -> V_110 |= F_36 ( V_161 ) ;
F_35 ( V_36 , L_7 ,
V_4 -> V_16 . V_160 ,
V_4 -> V_16 . V_102 ) ;
if ( V_4 -> V_16 . V_112 . V_113 != V_162 )
V_100 -> V_158 |= F_36 ( V_163 ) ;
if ( V_119 )
F_34 ( V_36 , V_4 , V_100 ) ;
}
static int F_44 ( struct V_35 * V_36 ,
struct V_99 * V_100 )
{
int V_49 = F_45 ( V_36 , V_164 , 0 ,
sizeof( * V_100 ) , V_100 ) ;
if ( V_49 )
F_22 ( V_36 , L_8 ,
F_46 ( V_100 -> V_116 ) , V_49 ) ;
return V_49 ;
}
static int F_47 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
T_3 V_116 , bool V_165 ,
const T_1 * V_115 )
{
struct V_99 V_100 = {} ;
struct V_166 * V_167 ;
F_48 ( V_4 -> type != V_10 ) ;
F_37 ( V_36 , V_4 , & V_100 , V_115 , V_116 ) ;
if ( V_4 -> V_51 ) {
struct V_168 * V_169 =
& V_4 -> V_16 . V_170 ;
V_100 . V_171 . V_172 = F_36 ( V_169 -> V_173 &
V_174 ) ;
V_167 = & V_100 . V_171 . V_31 ;
} else {
V_167 = & V_100 . V_31 ;
}
if ( V_4 -> V_16 . V_175 && V_4 -> V_16 . V_176 &&
! V_165 ) {
T_3 V_177 ;
V_177 = V_4 -> V_16 . V_178 *
V_4 -> V_16 . V_17 ;
V_177 *= 1024 ;
V_167 -> V_179 =
F_49 ( V_4 -> V_16 . V_180 + V_177 ) ;
V_167 -> V_181 =
F_36 ( V_4 -> V_16 . V_182 + V_177 ) ;
F_50 ( V_36 , L_9 ,
F_51 ( V_167 -> V_179 ) ,
F_46 ( V_167 -> V_181 ) ,
V_177 ) ;
V_167 -> V_183 = F_36 ( 1 ) ;
} else {
V_167 -> V_183 = F_36 ( 0 ) ;
V_100 . V_146 |= F_36 ( V_184 ) ;
}
V_167 -> V_185 = F_36 ( V_4 -> V_16 . V_17 ) ;
V_167 -> V_186 =
F_36 ( F_52 ( V_4 -> V_16 . V_17 ) ) ;
V_167 -> V_187 = F_36 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_176 ) ;
V_167 -> V_188 =
F_36 ( F_52 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_176 ) ) ;
V_167 -> V_189 = F_36 ( V_36 -> V_42 -> V_190 . V_189 ) ;
V_167 -> V_191 = F_36 ( V_4 -> V_16 . V_192 ) ;
if ( V_4 -> V_193 && V_4 -> V_16 . V_175 && V_4 -> V_51 )
V_100 . V_146 |= F_36 ( V_194 ) ;
return F_44 ( V_36 , & V_100 ) ;
}
static int F_53 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
T_3 V_116 )
{
struct V_99 V_100 = {} ;
T_3 V_34 = 0 ;
int V_49 , V_50 ;
F_48 ( V_4 -> type != V_128 ) ;
F_37 ( V_36 , V_4 , & V_100 , NULL , V_116 ) ;
if ( ! F_12 ( V_36 ) ) {
for ( V_50 = 0 ; V_50 < V_22 ; V_50 ++ )
if ( V_4 -> V_23 [ V_50 ] != V_24 )
V_34 |= F_7 ( V_4 -> V_23 [ V_50 ] ) ;
}
V_100 . V_146 = F_36 ( V_195 |
V_196 |
V_184 |
V_194 |
V_197 ) ;
F_54 ( V_36 -> V_42 , V_198 ) ;
V_49 = F_55 ( V_36 , & V_36 -> V_199 , V_34 ,
V_4 -> type , V_200 ) ;
if ( V_49 )
return V_49 ;
return F_44 ( V_36 , & V_100 ) ;
}
static int F_56 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
T_3 V_116 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_99 V_100 = {} ;
F_48 ( V_4 -> type != V_25 ) ;
F_37 ( V_36 , V_4 , & V_100 , NULL , V_116 ) ;
V_100 . V_146 = F_36 ( V_184 |
V_194 ) ;
V_100 . V_201 . V_185 = F_36 ( V_4 -> V_16 . V_17 ) ;
V_100 . V_201 . V_186 =
F_36 ( F_52 ( V_4 -> V_16 . V_17 ) ) ;
V_100 . V_201 . V_202 = F_36 ( V_8 -> V_46 ) ;
return F_44 ( V_36 , & V_100 ) ;
}
static void F_57 ( void * V_1 , T_1 * V_2 , struct V_3 * V_4 )
{
struct V_203 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 -> type == V_11 && V_4 -> V_51 &&
V_8 -> V_204 )
V_6 -> V_205 = true ;
}
static int F_58 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
T_3 V_116 )
{
struct V_99 V_100 = {} ;
struct V_203 V_6 = {} ;
F_48 ( V_4 -> type != V_20 ) ;
F_37 ( V_36 , V_4 , & V_100 , NULL , V_116 ) ;
V_100 . V_110 |= F_36 ( V_161 ) ;
V_100 . V_146 = F_36 ( V_194 ) ;
F_14 (
V_36 -> V_42 , V_43 ,
F_57 , & V_6 ) ;
V_100 . V_206 . V_207 = F_36 ( V_6 . V_205 ? 1 : 0 ) ;
return F_44 ( V_36 , & V_100 ) ;
}
static void F_59 ( struct V_35 * V_36 ,
T_4 * V_208 , T_4 * V_209 ,
T_1 * V_210 , T_3 V_211 )
{
T_3 V_212 ;
struct V_213 * V_214 = (struct V_213 * ) V_210 ;
V_212 = V_214 -> V_215 . V_210 . V_216 - V_210 ;
while ( ( V_212 < ( V_211 - 2 ) ) &&
( V_210 [ V_212 ] != V_217 ) )
V_212 += V_210 [ V_212 + 1 ] + 2 ;
if ( ( V_212 < ( V_211 - 1 ) ) && ( V_210 [ V_212 ] == V_217 ) ) {
* V_208 = F_36 ( V_212 ) ;
* V_209 = F_36 ( ( T_3 ) V_210 [ V_212 + 1 ] ) ;
} else {
F_60 ( V_36 , L_10 ) ;
}
}
static T_3 F_61 ( T_1 * V_210 , T_1 V_218 , T_3 V_211 )
{
struct V_213 * V_214 = ( void * ) V_210 ;
const T_1 * V_219 ;
if ( F_21 ( V_211 <= ( V_214 -> V_215 . V_210 . V_216 - V_210 ) ) )
return 0 ;
V_211 -= V_214 -> V_215 . V_210 . V_216 - V_210 ;
V_219 = F_62 ( V_218 , V_214 -> V_215 . V_210 . V_216 , V_211 ) ;
if ( ! V_219 )
return 0 ;
return V_219 - V_210 ;
}
static int F_63 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
struct V_220 * V_210 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_221 V_100 = {
. V_46 = V_222 ,
. V_223 = V_224 ,
} ;
union {
struct V_225 V_226 ;
struct V_227 V_228 ;
} V_215 = {} ;
struct V_229 V_228 = {} ;
struct V_230 * V_231 ;
T_3 V_232 ;
T_3 V_233 , V_234 ;
if ( F_48 ( ! V_210 ) )
return - V_235 ;
V_232 = V_210 -> V_236 ;
if ( F_64 ( & V_36 -> V_237 -> V_238 ,
V_239 ) ) {
T_3 V_240 , V_241 ;
V_240 = F_61 ( V_210 -> V_6 ,
V_242 ,
V_232 ) ;
V_241 =
F_61 ( V_210 -> V_6 ,
V_243 ,
V_232 ) ;
if ( F_65 ( V_36 ) ) {
V_228 . V_6 . V_244 =
F_36 ( ( T_3 ) V_8 -> V_46 ) ;
V_228 . V_6 . V_241 = F_36 ( V_241 ) ;
V_228 . V_6 . V_240 = F_36 ( V_240 ) ;
V_228 . V_245 = F_43 ( ( T_2 ) V_232 ) ;
if ( V_4 -> type == V_11 )
F_59 ( V_36 ,
& V_228 . V_6 . V_212 ,
& V_228 . V_6 . V_209 ,
V_210 -> V_6 ,
V_232 ) ;
V_100 . V_236 [ 0 ] = sizeof( V_228 ) ;
V_100 . V_6 [ 0 ] = & V_228 ;
goto V_246;
} else {
V_215 . V_228 . V_6 . V_241 =
F_36 ( V_241 ) ;
V_215 . V_228 . V_6 . V_240 = F_36 ( V_240 ) ;
V_100 . V_236 [ 0 ] = sizeof( V_215 . V_228 ) ;
V_100 . V_6 [ 0 ] = & V_215 ;
}
} else {
V_100 . V_236 [ 0 ] = sizeof( V_215 . V_226 ) ;
V_100 . V_6 [ 0 ] = & V_215 ;
}
V_215 . V_226 . V_244 = F_36 ( ( T_3 ) V_8 -> V_46 ) ;
V_231 = F_66 ( V_210 ) ;
V_215 . V_226 . V_247 . V_236 = F_43 ( ( T_2 ) V_232 ) ;
V_215 . V_226 . V_247 . V_37 = V_8 -> V_64 . V_37 ;
V_215 . V_226 . V_247 . V_248 = F_36 ( V_249 ) ;
V_234 = V_250 | V_251 ;
V_234 |=
F_67 ( V_36 , ( void * ) V_210 -> V_6 , V_231 , 0 ) <<
V_252 ;
V_215 . V_226 . V_247 . V_234 = F_36 ( V_234 ) ;
if ( ! F_64 ( & V_36 -> V_237 -> V_238 ,
V_253 ) ) {
V_36 -> V_254 =
F_68 ( V_36 , F_69 ( V_36 ) ,
V_36 -> V_254 ) ;
}
V_215 . V_226 . V_247 . V_255 =
F_36 ( F_7 ( V_36 -> V_254 ) <<
V_256 ) ;
if ( V_231 -> V_77 == V_257 || V_4 -> V_51 ) {
V_233 = V_92 ;
} else {
V_233 = V_93 ;
V_215 . V_226 . V_247 . V_255 |=
F_36 ( V_258 ) ;
}
V_215 . V_226 . V_247 . V_255 |=
F_36 ( F_70 ( V_233 ) ) ;
if ( V_4 -> type == V_11 )
F_59 ( V_36 , & V_215 . V_226 . V_212 ,
& V_215 . V_226 . V_209 ,
V_210 -> V_6 ,
V_232 ) ;
V_246:
V_100 . V_259 [ 0 ] = 0 ;
V_100 . V_236 [ 1 ] = V_232 ;
V_100 . V_6 [ 1 ] = V_210 -> V_6 ;
V_100 . V_259 [ 1 ] = V_260 ;
return F_71 ( V_36 , & V_100 ) ;
}
int F_72 ( struct V_35 * V_36 ,
struct V_3 * V_4 )
{
struct V_220 * V_210 ;
int V_49 ;
F_48 ( V_4 -> type != V_11 &&
V_4 -> type != V_25 ) ;
V_210 = F_73 ( V_36 -> V_42 , V_4 , NULL ) ;
if ( ! V_210 )
return - V_261 ;
V_49 = F_63 ( V_36 , V_4 , V_210 ) ;
F_74 ( V_210 ) ;
return V_49 ;
}
static void F_75 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_262 * V_6 = V_1 ;
if ( V_4 -> type != V_10 || ! V_4 -> V_16 . V_175 )
return;
if ( V_4 -> V_51 && V_6 -> V_263 )
return;
V_6 -> V_263 = V_4 -> V_16 . V_182 ;
V_6 -> V_17 = V_4 -> V_16 . V_17 ;
}
static void F_76 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
struct V_99 * V_100 ,
struct V_264 * V_265 ,
bool V_266 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_262 V_6 = {
. V_36 = V_36 ,
. V_4 = V_4 ,
. V_263 = 0
} ;
V_100 -> V_19 [ V_72 ] . V_156 |= F_7 ( V_73 ) ;
V_100 -> V_146 |= F_36 ( V_194 ) ;
if ( V_8 -> V_267 || ! V_36 -> V_268 ) {
V_100 -> V_146 |= F_36 ( V_184 ) ;
F_77 ( V_36 , L_11 ) ;
} else {
F_77 ( V_36 , L_12 ) ;
}
V_265 -> V_185 = F_36 ( V_4 -> V_16 . V_17 ) ;
V_265 -> V_186 =
F_36 ( F_52 ( V_4 -> V_16 . V_17 ) ) ;
V_265 -> V_187 = F_36 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_176 ) ;
V_265 -> V_188 =
F_36 ( F_52 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_176 ) ) ;
if ( ! F_78 ( & V_36 -> V_237 -> V_238 ,
V_269 ) )
V_265 -> V_270 = F_36 ( V_4 -> V_26 ) ;
if ( V_266 ) {
F_14 (
V_36 -> V_42 , V_43 ,
F_75 , & V_6 ) ;
if ( V_6 . V_263 ) {
T_3 rand = ( F_79 () % ( 64 - 36 ) ) + 36 ;
V_8 -> V_271 = V_6 . V_263 +
F_80 ( V_6 . V_17 * rand /
100 ) ;
} else {
V_8 -> V_271 =
F_81 ( V_36 -> V_272 ,
V_273 ) ;
}
}
V_265 -> V_274 = F_36 ( V_8 -> V_271 ) ;
V_265 -> V_275 = 0 ;
V_265 -> V_202 = F_36 ( V_8 -> V_46 ) ;
}
static int F_82 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
T_3 V_116 )
{
struct V_99 V_100 = {} ;
F_48 ( V_4 -> type != V_11 || V_4 -> V_51 ) ;
F_37 ( V_36 , V_4 , & V_100 , NULL , V_116 ) ;
F_76 ( V_36 , V_4 , & V_100 , & V_100 . V_276 ,
V_116 == V_277 ) ;
return F_44 ( V_36 , & V_100 ) ;
}
static int F_83 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
T_3 V_116 )
{
struct V_99 V_100 = {} ;
struct V_168 * V_169 = & V_4 -> V_16 . V_170 ;
F_48 ( V_4 -> type != V_11 || ! V_4 -> V_51 ) ;
F_37 ( V_36 , V_4 , & V_100 , NULL , V_116 ) ;
F_76 ( V_36 , V_4 , & V_100 , & V_100 . V_278 . V_276 ,
V_116 == V_277 ) ;
V_100 . V_278 . V_172 = F_36 ( V_169 -> V_173 &
V_174 ) ;
V_100 . V_278 . V_279 =
F_36 ( ! ! ( V_169 -> V_173 &
V_280 ) ) ;
return F_44 ( V_36 , & V_100 ) ;
}
static int F_84 ( struct V_35 * V_36 , struct V_3 * V_4 ,
T_3 V_116 , bool V_165 ,
const T_1 * V_115 )
{
switch ( V_4 -> type ) {
case V_10 :
return F_47 ( V_36 , V_4 , V_116 ,
V_165 ,
V_115 ) ;
break;
case V_11 :
if ( ! V_4 -> V_51 )
return F_82 ( V_36 , V_4 , V_116 ) ;
else
return F_83 ( V_36 , V_4 , V_116 ) ;
break;
case V_128 :
return F_53 ( V_36 , V_4 , V_116 ) ;
case V_20 :
return F_58 ( V_36 , V_4 , V_116 ) ;
case V_25 :
return F_56 ( V_36 , V_4 , V_116 ) ;
default:
break;
}
return - V_281 ;
}
int F_85 ( struct V_35 * V_36 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_49 ;
if ( F_86 ( V_8 -> V_282 , L_13 ,
V_4 -> V_133 , F_87 ( V_4 ) ) )
return - V_55 ;
V_49 = F_84 ( V_36 , V_4 , V_277 ,
true , NULL ) ;
if ( V_49 )
return V_49 ;
F_88 ( V_36 , V_4 ) ;
V_8 -> V_282 = true ;
return 0 ;
}
int F_89 ( struct V_35 * V_36 , struct V_3 * V_4 ,
bool V_165 , const T_1 * V_115 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( F_86 ( ! V_8 -> V_282 , L_14 ,
V_4 -> V_133 , F_87 ( V_4 ) ) )
return - V_55 ;
return F_84 ( V_36 , V_4 , V_283 ,
V_165 , V_115 ) ;
}
int F_90 ( struct V_35 * V_36 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_99 V_100 ;
int V_49 ;
if ( F_86 ( ! V_8 -> V_282 , L_15 ,
V_4 -> V_133 , F_87 ( V_4 ) ) )
return - V_55 ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . V_123 = F_36 ( F_38 ( V_8 -> V_46 ,
V_8 -> V_57 ) ) ;
V_100 . V_116 = F_36 ( V_284 ) ;
V_49 = F_45 ( V_36 , V_164 , 0 ,
sizeof( V_100 ) , & V_100 ) ;
if ( V_49 ) {
F_22 ( V_36 , L_16 , V_49 ) ;
return V_49 ;
}
V_8 -> V_282 = false ;
if ( V_4 -> type == V_128 ) {
F_5 ( V_285 , V_36 -> V_42 -> V_223 ) ;
F_91 ( V_36 ) ;
}
return 0 ;
}
static void F_92 ( struct V_35 * V_36 ,
struct V_3 * V_286 , T_3 V_287 ,
bool V_288 )
{
struct V_7 * V_8 =
F_2 ( V_286 ) ;
if ( ! V_288 && ! V_8 -> V_289 )
return;
V_8 -> V_289 = true ;
if ( ! F_93 ( V_286 ) ) {
int V_290 = F_94 ( V_286 ) ;
F_72 ( V_36 , V_286 ) ;
if ( V_286 -> V_51 &&
! F_95 ( & V_8 -> V_58 ) && V_287 &&
V_288 ) {
T_3 V_291 = ( V_290 + 1 ) *
V_286 -> V_16 . V_17 -
V_292 ;
T_3 V_293 = V_287 + V_291 * 1024 ;
F_96 ( V_36 , V_286 ,
V_292 -
V_294 ,
V_293 ) ;
}
} else if ( ! F_95 ( & V_8 -> V_58 ) ) {
F_97 ( V_286 ) ;
F_98 ( V_36 -> V_286 , NULL ) ;
}
}
void F_99 ( struct V_35 * V_36 ,
struct V_295 * V_296 )
{
struct V_297 * V_298 = F_100 ( V_296 ) ;
struct V_299 * V_210 = ( void * ) V_298 -> V_6 ;
struct V_300 * V_301 ;
struct V_3 * V_286 ;
struct V_3 * V_302 ;
struct V_303 * V_304 ;
T_2 V_53 ;
F_13 ( & V_36 -> V_41 ) ;
V_301 = & V_210 -> V_301 ;
V_36 -> V_305 = F_46 ( V_210 -> V_287 ) ;
V_304 = F_101 ( V_36 , V_301 ) ;
V_53 = F_102 ( V_304 -> V_53 ) & V_306 ;
F_103 ( V_36 ,
L_17 ,
V_53 , V_301 -> V_307 ,
F_51 ( V_210 -> V_308 ) ,
V_36 -> V_305 ,
F_46 ( V_301 -> V_309 ) ) ;
V_286 = F_104 ( V_36 -> V_286 ,
F_105 ( & V_36 -> V_41 ) ) ;
if ( F_106 ( V_286 && V_286 -> V_310 ) )
F_92 ( V_36 , V_286 , V_36 -> V_305 ,
( V_53 == V_311 ) ) ;
V_302 = F_104 ( V_36 -> V_312 ,
F_105 ( & V_36 -> V_41 ) ) ;
if ( F_106 ( V_302 ) ) {
struct V_7 * V_8 =
F_2 ( V_302 ) ;
if ( ! V_36 -> V_313 )
V_36 -> V_313 =
V_314 ;
else
V_36 -> V_313 -- ;
if ( V_36 -> V_313 == 0 ) {
F_107 ( V_36 , V_8 , false ) ;
F_98 ( V_36 -> V_312 , NULL ) ;
}
}
}
static void F_108 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_315 * V_316 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_35 * V_36 = V_8 -> V_36 ;
struct V_317 * V_318 ;
struct V_319 * V_320 ;
T_3 V_321 , V_322 ;
T_3 V_323 , V_324 ;
if ( V_8 -> V_46 != ( T_2 ) F_46 ( V_316 -> V_325 ) )
return;
V_323 = F_46 ( V_316 -> V_326 ) ;
V_324 =
F_46 ( V_316 -> V_327 ) ;
if ( F_46 ( V_316 -> V_327 ) >
V_328 )
F_109 ( V_4 ) ;
if ( ! F_110 ( V_36 -> V_237 ,
V_329 ) )
return;
V_320 = F_111 ( V_36 -> V_237 ,
V_329 ) ;
V_318 = ( void * ) V_320 -> V_6 ;
V_321 = F_46 ( V_318 -> V_330 ) ;
V_322 =
F_46 ( V_318 -> V_331 ) ;
if ( ! F_112 ( V_36 , V_4 , V_320 ) )
return;
if ( V_324 >= V_322 ||
V_323 >= V_321 )
F_113 ( V_36 , V_320 , NULL ) ;
}
void F_114 ( struct V_35 * V_36 ,
struct V_295 * V_296 )
{
struct V_297 * V_298 = F_100 ( V_296 ) ;
struct V_315 * V_332 = ( void * ) V_298 -> V_6 ;
F_50 ( V_36 ,
L_18 ,
F_46 ( V_332 -> V_325 ) ,
F_46 ( V_332 -> V_326 ) ,
F_46 ( V_332 -> V_327 ) ,
F_46 ( V_332 -> V_333 ) ,
F_46 ( V_332 -> V_334 ) ) ;
F_14 ( V_36 -> V_42 ,
V_335 ,
F_108 ,
V_332 ) ;
}
void F_115 ( struct V_35 * V_36 ,
struct V_295 * V_296 )
{
struct V_297 * V_298 = F_100 ( V_296 ) ;
struct V_336 * V_337 = ( void * ) V_298 -> V_6 ;
struct V_338 V_339 ;
struct V_220 * V_340 ;
T_3 V_341 = F_46 ( V_337 -> V_342 ) ;
if ( V_341 == 0 )
return;
V_340 = F_116 ( V_341 , V_343 ) ;
if ( ! V_340 ) {
F_22 ( V_36 , L_19 ) ;
return;
}
memset ( & V_339 , 0 , sizeof( V_339 ) ) ;
V_339 . V_344 = F_51 ( V_337 -> V_308 ) ;
V_339 . V_345 |= V_346 ;
V_339 . V_347 = F_46 ( V_337 -> V_348 ) ;
V_339 . V_77 =
( V_337 -> V_77 & F_43 ( V_349 ) ) ?
V_139 : V_257 ;
V_339 . V_350 =
F_117 ( F_102 ( V_337 -> V_351 ) ,
V_339 . V_77 ) ;
memcpy ( F_118 ( V_340 , V_341 ) , V_337 -> V_6 , V_341 ) ;
memcpy ( F_119 ( V_340 ) , & V_339 , sizeof( V_339 ) ) ;
F_120 ( V_36 -> V_42 , NULL , V_340 , NULL ) ;
}
void F_121 ( struct V_35 * V_36 ,
struct V_295 * V_296 )
{
struct V_297 * V_298 = F_100 ( V_296 ) ;
struct V_352 * V_353 = ( void * ) V_298 -> V_6 ;
struct V_3 * V_286 ;
struct V_7 * V_8 ;
int V_236 = F_122 ( V_298 ) ;
T_3 V_354 ;
if ( F_21 ( V_236 < sizeof( * V_353 ) ) )
return;
F_40 () ;
V_286 = F_41 ( V_36 -> V_286 ) ;
if ( F_48 ( ! V_286 || ! V_286 -> V_310 ) )
goto V_355;
V_354 = F_46 ( V_353 -> V_123 ) ;
V_8 = F_2 ( V_286 ) ;
if ( F_123 ( F_38 ( V_8 -> V_46 , V_8 -> V_57 ) != V_354 ,
L_20 ,
F_38 ( V_8 -> V_46 , V_8 -> V_57 ) , V_354 ) )
goto V_355;
F_50 ( V_36 , L_21 ) ;
F_124 ( V_356 , & V_36 -> V_357 ,
F_125 ( V_314 *
V_286 -> V_16 . V_17 ) ) ;
F_97 ( V_286 ) ;
F_42 () ;
F_98 ( V_36 -> V_286 , NULL ) ;
return;
V_355:
F_42 () ;
}
