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
switch ( V_4 -> type ) {
case V_20 :
if ( ! F_12 ( V_35 ) )
F_28 ( V_35 , V_21 ,
V_21 ,
V_71 , 0 ,
V_70 ) ;
break;
case V_11 :
F_28 ( V_35 , V_4 -> V_25 , V_4 -> V_25 ,
V_72 , 0 , V_70 ) ;
default:
if ( F_12 ( V_35 ) )
break;
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
break;
case V_11 :
F_30 ( V_35 , V_4 -> V_25 , V_4 -> V_25 ,
V_74 , 0 ) ;
if ( F_12 ( V_35 ) )
F_30 ( V_35 ,
V_75 ,
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
enum V_76 V_77 ,
T_1 * V_78 , T_1 * V_79 )
{
struct V_80 * V_81 ;
unsigned long V_82 = V_4 -> V_16 . V_83 ;
int V_84 = 100 ;
int V_85 = 100 ;
T_1 V_86 = 0 ;
T_1 V_87 = 0 ;
int V_49 ;
V_81 = V_35 -> V_41 -> V_88 -> V_89 [ V_77 ] ;
F_16 (i, &basic, BITS_PER_LONG) {
int V_41 = V_81 -> V_90 [ V_49 ] . V_91 ;
if ( V_41 >= V_92 ) {
V_87 |= F_7 ( V_41 - V_92 ) ;
if ( V_84 > V_41 )
V_84 = V_41 ;
} else {
F_32 ( V_93 != 0 ) ;
V_86 |= F_7 ( V_41 ) ;
if ( V_85 > V_41 )
V_85 = V_41 ;
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
static void F_34 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
struct V_99 * V_100 )
{
T_1 V_101 = V_4 -> V_16 . V_102 &
V_103 ;
T_3 V_104 = V_105 | V_106 ;
F_35 ( V_35 , L_5 , V_101 ) ;
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
F_22 ( V_35 , L_6 ,
V_101 ) ;
break;
}
}
static void F_37 ( struct V_34 * V_35 ,
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
int V_49 ;
V_100 -> V_123 = F_36 ( F_38 ( V_8 -> V_45 ,
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
case V_50 :
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
F_31 ( V_35 , V_4 , V_118 ? V_118 -> V_137 . V_138 -> V_77
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
for ( V_49 = 0 ; V_49 < V_22 ; V_49 ++ ) {
T_1 V_148 = V_73 [ V_49 ] ;
V_100 -> V_19 [ V_148 ] . V_149 =
F_43 ( V_8 -> V_150 [ V_49 ] . V_149 ) ;
V_100 -> V_19 [ V_148 ] . V_151 =
F_43 ( V_8 -> V_150 [ V_49 ] . V_151 ) ;
V_100 -> V_19 [ V_148 ] . V_152 =
F_43 ( V_8 -> V_150 [ V_49 ] . V_153 * 32 ) ;
V_100 -> V_19 [ V_148 ] . V_154 = V_8 -> V_150 [ V_49 ] . V_155 ;
V_100 -> V_19 [ V_148 ] . V_156 = F_7 ( V_148 ) ;
}
if ( V_4 -> type == V_11 ) {
V_100 -> V_19 [ V_71 ] . V_156 |=
F_7 ( V_72 ) ;
V_100 -> V_146 |= F_36 ( V_157 ) ;
if ( V_8 -> V_158 || ! V_35 -> V_159 ) {
V_100 -> V_146 |= F_36 ( V_160 ) ;
F_44 ( V_35 , L_7 ) ;
} else {
F_44 ( V_35 , L_8 ) ;
}
}
if ( V_4 -> V_16 . V_161 )
V_100 -> V_162 |= F_36 ( V_163 ) ;
if ( V_4 -> V_16 . V_164 )
V_100 -> V_110 |= F_36 ( V_165 ) ;
F_35 ( V_35 , L_9 ,
V_4 -> V_16 . V_164 ,
V_4 -> V_16 . V_102 ) ;
if ( V_4 -> V_16 . V_112 . V_113 != V_166 )
V_100 -> V_162 |= F_36 ( V_167 ) ;
if ( V_119 )
F_34 ( V_35 , V_4 , V_100 ) ;
}
static int F_45 ( struct V_34 * V_35 ,
struct V_99 * V_100 )
{
int V_48 = F_46 ( V_35 , V_168 , 0 ,
sizeof( * V_100 ) , V_100 ) ;
if ( V_48 )
F_22 ( V_35 , L_10 ,
F_47 ( V_100 -> V_116 ) , V_48 ) ;
return V_48 ;
}
static int F_48 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_116 , bool V_169 ,
const T_1 * V_115 )
{
struct V_99 V_100 = {} ;
struct V_170 * V_171 ;
F_49 ( V_4 -> type != V_10 ) ;
F_37 ( V_35 , V_4 , & V_100 , V_115 , V_116 ) ;
if ( V_4 -> V_51 ) {
struct V_172 * V_173 =
& V_4 -> V_16 . V_174 ;
V_100 . V_175 . V_176 = F_36 ( V_173 -> V_177 &
V_178 ) ;
V_171 = & V_100 . V_175 . V_30 ;
} else {
V_171 = & V_100 . V_30 ;
}
if ( V_4 -> V_16 . V_179 && V_4 -> V_16 . V_180 &&
! V_169 ) {
T_3 V_181 ;
V_181 = V_4 -> V_16 . V_182 *
V_4 -> V_16 . V_17 ;
V_181 *= 1024 ;
V_171 -> V_183 =
F_50 ( V_4 -> V_16 . V_184 + V_181 ) ;
V_171 -> V_185 =
F_36 ( V_4 -> V_16 . V_186 + V_181 ) ;
F_51 ( V_35 , L_11 ,
F_52 ( V_171 -> V_183 ) ,
F_47 ( V_171 -> V_185 ) ,
V_181 ) ;
V_171 -> V_187 = F_36 ( 1 ) ;
} else {
V_171 -> V_187 = F_36 ( 0 ) ;
V_100 . V_146 |= F_36 ( V_160 ) ;
}
V_171 -> V_188 = F_36 ( V_4 -> V_16 . V_17 ) ;
V_171 -> V_189 =
F_36 ( F_53 ( V_4 -> V_16 . V_17 ) ) ;
V_171 -> V_190 = F_36 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_180 ) ;
V_171 -> V_191 =
F_36 ( F_53 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_180 ) ) ;
V_171 -> V_192 = F_36 ( V_35 -> V_41 -> V_193 . V_192 ) ;
V_171 -> V_194 = F_36 ( V_4 -> V_16 . V_195 ) ;
if ( V_4 -> V_196 && V_4 -> V_16 . V_179 && V_4 -> V_51 )
V_100 . V_146 |= F_36 ( V_157 ) ;
return F_45 ( V_35 , & V_100 ) ;
}
static int F_54 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_116 )
{
struct V_99 V_100 = {} ;
T_3 V_33 = 0 ;
int V_48 , V_49 ;
F_49 ( V_4 -> type != V_128 ) ;
F_37 ( V_35 , V_4 , & V_100 , NULL , V_116 ) ;
for ( V_49 = 0 ; V_49 < V_22 ; V_49 ++ )
if ( V_4 -> V_23 [ V_49 ] != V_24 )
V_33 |= F_7 ( V_4 -> V_23 [ V_49 ] ) ;
V_100 . V_146 = F_36 ( V_197 |
V_198 |
V_160 |
V_157 |
V_199 ) ;
F_55 ( V_35 -> V_41 , V_200 ) ;
V_48 = F_56 ( V_35 , & V_35 -> V_201 , V_33 ,
V_4 -> type ) ;
if ( V_48 )
return V_48 ;
return F_45 ( V_35 , & V_100 ) ;
}
static int F_57 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_116 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_99 V_100 = {} ;
F_49 ( V_4 -> type != V_50 ) ;
F_37 ( V_35 , V_4 , & V_100 , NULL , V_116 ) ;
V_100 . V_146 = F_36 ( V_160 |
V_157 ) ;
V_100 . V_202 . V_188 = F_36 ( V_4 -> V_16 . V_17 ) ;
V_100 . V_202 . V_189 =
F_36 ( F_53 ( V_4 -> V_16 . V_17 ) ) ;
V_100 . V_202 . V_203 = F_36 ( V_8 -> V_45 ) ;
return F_45 ( V_35 , & V_100 ) ;
}
static void F_58 ( void * V_1 , T_1 * V_2 , struct V_3 * V_4 )
{
struct V_204 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 -> type == V_11 && V_4 -> V_51 &&
V_8 -> V_205 )
V_6 -> V_206 = true ;
}
static int F_59 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_116 )
{
struct V_99 V_100 = {} ;
struct V_204 V_6 = {} ;
F_49 ( V_4 -> type != V_20 ) ;
F_37 ( V_35 , V_4 , & V_100 , NULL , V_116 ) ;
V_100 . V_110 |= F_36 ( V_165 ) ;
V_100 . V_146 = F_36 ( V_157 ) ;
F_14 (
V_35 -> V_41 , V_42 ,
F_58 , & V_6 ) ;
V_100 . V_207 . V_208 = F_36 ( V_6 . V_206 ? 1 : 0 ) ;
return F_45 ( V_35 , & V_100 ) ;
}
static void F_60 ( struct V_34 * V_35 ,
struct V_209 * V_210 ,
T_1 * V_211 , T_3 V_212 )
{
T_3 V_213 ;
struct V_214 * V_215 = (struct V_214 * ) V_211 ;
V_213 = V_215 -> V_216 . V_211 . V_217 - V_211 ;
while ( ( V_213 < ( V_212 - 2 ) ) &&
( V_211 [ V_213 ] != V_218 ) )
V_213 += V_211 [ V_213 + 1 ] + 2 ;
if ( ( V_213 < ( V_212 - 1 ) ) && ( V_211 [ V_213 ] == V_218 ) ) {
V_210 -> V_213 = F_36 ( V_213 ) ;
V_210 -> V_219 = F_36 ( ( T_3 ) V_211 [ V_213 + 1 ] ) ;
} else {
F_61 ( V_35 , L_12 ) ;
}
}
static T_3 F_62 ( T_1 * V_211 , T_1 V_220 , T_3 V_212 )
{
struct V_214 * V_215 = ( void * ) V_211 ;
const T_1 * V_221 ;
if ( F_21 ( V_212 <= ( V_215 -> V_216 . V_211 . V_217 - V_211 ) ) )
return 0 ;
V_212 -= V_215 -> V_216 . V_211 . V_217 - V_211 ;
V_221 = F_63 ( V_220 , V_215 -> V_216 . V_211 . V_217 , V_212 ) ;
if ( ! V_221 )
return 0 ;
return V_221 - V_211 ;
}
static int F_64 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
struct V_222 * V_211 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_223 V_100 = {
. V_45 = V_224 ,
. V_225 = V_226 ,
} ;
union {
struct V_209 V_227 ;
struct V_228 V_210 ;
} V_216 = {} ;
struct V_229 * V_230 ;
T_3 V_231 ;
T_3 V_232 , V_233 ;
if ( F_49 ( ! V_211 ) )
return - V_234 ;
V_231 = V_211 -> V_235 ;
V_216 . V_227 . V_236 = F_36 ( ( T_3 ) V_8 -> V_45 ) ;
V_230 = F_65 ( V_211 ) ;
V_216 . V_227 . V_237 . V_235 = F_43 ( ( T_2 ) V_231 ) ;
V_216 . V_227 . V_237 . V_36 = V_8 -> V_64 . V_36 ;
V_216 . V_227 . V_237 . V_238 = F_36 ( V_239 ) ;
V_233 = V_240 | V_241 ;
V_233 |=
F_66 ( V_35 , ( void * ) V_211 -> V_6 , V_230 , 0 ) <<
V_242 ;
V_216 . V_227 . V_237 . V_233 = F_36 ( V_233 ) ;
if ( ! F_67 ( & V_35 -> V_243 -> V_244 ,
V_245 ) ) {
V_35 -> V_246 =
F_68 ( V_35 , F_69 ( V_35 ) ,
V_35 -> V_246 ) ;
}
V_216 . V_227 . V_237 . V_247 =
F_36 ( F_7 ( V_35 -> V_246 ) <<
V_248 ) ;
if ( V_230 -> V_77 == V_249 || V_4 -> V_51 ) {
V_232 = V_92 ;
} else {
V_232 = V_93 ;
V_216 . V_227 . V_237 . V_247 |=
F_36 ( V_250 ) ;
}
V_216 . V_227 . V_237 . V_247 |=
F_36 ( F_70 ( V_232 ) ) ;
if ( V_4 -> type == V_11 )
F_60 ( V_35 , & V_216 . V_227 ,
V_211 -> V_6 ,
V_231 ) ;
if ( F_67 ( & V_35 -> V_243 -> V_244 ,
V_251 ) ) {
V_216 . V_210 . V_252 =
F_36 ( F_62 ( V_211 -> V_6 ,
V_253 ,
V_231 ) ) ;
V_216 . V_210 . V_254 =
F_36 ( F_62 ( V_211 -> V_6 ,
V_255 ,
V_231 ) ) ;
V_100 . V_235 [ 0 ] = sizeof( V_216 . V_210 ) ;
} else {
V_100 . V_235 [ 0 ] = sizeof( V_216 . V_227 ) ;
}
V_100 . V_6 [ 0 ] = & V_216 ;
V_100 . V_256 [ 0 ] = 0 ;
V_100 . V_235 [ 1 ] = V_231 ;
V_100 . V_6 [ 1 ] = V_211 -> V_6 ;
V_100 . V_256 [ 1 ] = V_257 ;
return F_71 ( V_35 , & V_100 ) ;
}
int F_72 ( struct V_34 * V_35 ,
struct V_3 * V_4 )
{
struct V_222 * V_211 ;
int V_48 ;
F_49 ( V_4 -> type != V_11 &&
V_4 -> type != V_50 ) ;
V_211 = F_73 ( V_35 -> V_41 , V_4 , NULL ) ;
if ( ! V_211 )
return - V_258 ;
V_48 = F_64 ( V_35 , V_4 , V_211 ) ;
F_74 ( V_211 ) ;
return V_48 ;
}
static void F_75 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_259 * V_6 = V_1 ;
if ( V_4 -> type != V_10 || ! V_4 -> V_16 . V_179 )
return;
if ( V_4 -> V_51 && V_6 -> V_260 )
return;
V_6 -> V_260 = V_4 -> V_16 . V_186 ;
V_6 -> V_17 = V_4 -> V_16 . V_17 ;
}
static void F_76 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
struct V_261 * V_262 ,
bool V_263 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_259 V_6 = {
. V_35 = V_35 ,
. V_4 = V_4 ,
. V_260 = 0
} ;
V_262 -> V_188 = F_36 ( V_4 -> V_16 . V_17 ) ;
V_262 -> V_189 =
F_36 ( F_53 ( V_4 -> V_16 . V_17 ) ) ;
V_262 -> V_190 = F_36 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_180 ) ;
V_262 -> V_191 =
F_36 ( F_53 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_180 ) ) ;
V_262 -> V_264 = F_36 ( V_4 -> V_25 ) ;
if ( V_263 ) {
F_14 (
V_35 -> V_41 , V_42 ,
F_75 , & V_6 ) ;
if ( V_6 . V_260 ) {
T_3 rand = ( F_77 () % ( 64 - 36 ) ) + 36 ;
V_8 -> V_265 = V_6 . V_260 +
F_78 ( V_6 . V_17 * rand /
100 ) ;
} else {
V_8 -> V_265 =
F_79 ( V_35 -> V_266 ,
V_267 ) ;
}
}
V_262 -> V_268 = F_36 ( V_8 -> V_265 ) ;
V_262 -> V_269 = 0 ;
V_262 -> V_203 = F_36 ( V_8 -> V_45 ) ;
}
static int F_80 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_116 )
{
struct V_99 V_100 = {} ;
F_49 ( V_4 -> type != V_11 || V_4 -> V_51 ) ;
F_37 ( V_35 , V_4 , & V_100 , NULL , V_116 ) ;
F_76 ( V_35 , V_4 , & V_100 . V_270 ,
V_116 == V_271 ) ;
return F_45 ( V_35 , & V_100 ) ;
}
static int F_81 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_116 )
{
struct V_99 V_100 = {} ;
struct V_172 * V_173 = & V_4 -> V_16 . V_174 ;
F_49 ( V_4 -> type != V_11 || ! V_4 -> V_51 ) ;
F_37 ( V_35 , V_4 , & V_100 , NULL , V_116 ) ;
F_76 ( V_35 , V_4 , & V_100 . V_272 . V_270 ,
V_116 == V_271 ) ;
V_100 . V_272 . V_176 = F_36 ( V_173 -> V_177 &
V_178 ) ;
V_100 . V_272 . V_273 =
F_36 ( ! ! ( V_173 -> V_177 &
V_274 ) ) ;
return F_45 ( V_35 , & V_100 ) ;
}
static int F_82 ( struct V_34 * V_35 , struct V_3 * V_4 ,
T_3 V_116 , bool V_169 ,
const T_1 * V_115 )
{
switch ( V_4 -> type ) {
case V_10 :
return F_48 ( V_35 , V_4 , V_116 ,
V_169 ,
V_115 ) ;
break;
case V_11 :
if ( ! V_4 -> V_51 )
return F_80 ( V_35 , V_4 , V_116 ) ;
else
return F_81 ( V_35 , V_4 , V_116 ) ;
break;
case V_128 :
return F_54 ( V_35 , V_4 , V_116 ) ;
case V_20 :
return F_59 ( V_35 , V_4 , V_116 ) ;
case V_50 :
return F_57 ( V_35 , V_4 , V_116 ) ;
default:
break;
}
return - V_275 ;
}
int F_83 ( struct V_34 * V_35 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_48 ;
if ( F_84 ( V_8 -> V_276 , L_13 ,
V_4 -> V_133 , F_85 ( V_4 ) ) )
return - V_55 ;
V_48 = F_82 ( V_35 , V_4 , V_271 ,
true , NULL ) ;
if ( V_48 )
return V_48 ;
F_86 ( V_35 , V_4 ) ;
V_8 -> V_276 = true ;
return 0 ;
}
int F_87 ( struct V_34 * V_35 , struct V_3 * V_4 ,
bool V_169 , const T_1 * V_115 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( F_84 ( ! V_8 -> V_276 , L_14 ,
V_4 -> V_133 , F_85 ( V_4 ) ) )
return - V_55 ;
return F_82 ( V_35 , V_4 , V_277 ,
V_169 , V_115 ) ;
}
int F_88 ( struct V_34 * V_35 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_99 V_100 ;
int V_48 ;
if ( F_84 ( ! V_8 -> V_276 , L_15 ,
V_4 -> V_133 , F_85 ( V_4 ) ) )
return - V_55 ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . V_123 = F_36 ( F_38 ( V_8 -> V_45 ,
V_8 -> V_57 ) ) ;
V_100 . V_116 = F_36 ( V_278 ) ;
V_48 = F_46 ( V_35 , V_168 , 0 ,
sizeof( V_100 ) , & V_100 ) ;
if ( V_48 ) {
F_22 ( V_35 , L_16 , V_48 ) ;
return V_48 ;
}
V_8 -> V_276 = false ;
if ( V_4 -> type == V_128 ) {
F_5 ( V_279 , V_35 -> V_41 -> V_225 ) ;
F_89 ( V_35 ) ;
}
return 0 ;
}
static void F_90 ( struct V_34 * V_35 ,
struct V_3 * V_280 , T_3 V_281 ,
bool V_282 )
{
struct V_7 * V_8 =
F_2 ( V_280 ) ;
if ( ! V_282 && ! V_8 -> V_283 )
return;
V_8 -> V_283 = true ;
if ( ! F_91 ( V_280 ) ) {
int V_284 = F_92 ( V_280 ) ;
F_72 ( V_35 , V_280 ) ;
if ( V_280 -> V_51 &&
! F_93 ( & V_8 -> V_58 ) && V_281 &&
V_282 ) {
T_3 V_285 = ( V_284 + 1 ) *
V_280 -> V_16 . V_17 -
V_286 ;
T_3 V_287 = V_281 + V_285 * 1024 ;
F_94 ( V_35 , V_280 ,
V_286 -
V_288 ,
V_287 ) ;
}
} else if ( ! F_93 ( & V_8 -> V_58 ) ) {
F_95 ( V_280 ) ;
F_96 ( V_35 -> V_280 , NULL ) ;
}
}
void F_97 ( struct V_34 * V_35 ,
struct V_289 * V_290 )
{
struct V_291 * V_292 = F_98 ( V_290 ) ;
struct V_293 * V_211 = ( void * ) V_292 -> V_6 ;
struct V_294 * V_295 ;
struct V_3 * V_280 ;
struct V_3 * V_296 ;
T_2 V_53 ;
F_13 ( & V_35 -> V_40 ) ;
V_295 = & V_211 -> V_295 ;
V_35 -> V_297 = F_47 ( V_211 -> V_281 ) ;
V_53 = F_99 ( V_295 -> V_53 . V_53 ) & V_298 ;
F_100 ( V_35 ,
L_17 ,
V_53 , V_295 -> V_299 ,
F_52 ( V_211 -> V_300 ) ,
V_35 -> V_297 ,
F_47 ( V_295 -> V_301 ) ) ;
V_280 = F_101 ( V_35 -> V_280 ,
F_102 ( & V_35 -> V_40 ) ) ;
if ( F_103 ( V_280 && V_280 -> V_302 ) )
F_90 ( V_35 , V_280 , V_35 -> V_297 ,
( V_53 == V_303 ) ) ;
V_296 = F_101 ( V_35 -> V_304 ,
F_102 ( & V_35 -> V_40 ) ) ;
if ( F_103 ( V_296 ) ) {
struct V_7 * V_8 =
F_2 ( V_296 ) ;
if ( ! V_35 -> V_305 )
V_35 -> V_305 =
V_306 ;
else
V_35 -> V_305 -- ;
if ( V_35 -> V_305 == 0 ) {
F_104 ( V_35 , V_8 , false ) ;
F_96 ( V_35 -> V_304 , NULL ) ;
}
}
}
static void F_105 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_307 * V_308 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_34 * V_35 = V_8 -> V_35 ;
struct V_309 * V_310 ;
struct V_311 * V_312 ;
T_3 V_313 , V_314 ;
T_3 V_315 , V_316 ;
if ( V_8 -> V_45 != ( T_2 ) F_47 ( V_308 -> V_317 ) )
return;
V_315 = F_47 ( V_308 -> V_318 ) ;
V_316 =
F_47 ( V_308 -> V_319 ) ;
if ( F_47 ( V_308 -> V_319 ) >
V_320 )
F_106 ( V_4 ) ;
if ( ! F_107 ( V_35 -> V_243 ,
V_321 ) )
return;
V_312 = F_108 ( V_35 -> V_243 ,
V_321 ) ;
V_310 = ( void * ) V_312 -> V_6 ;
V_313 = F_47 ( V_310 -> V_322 ) ;
V_314 =
F_47 ( V_310 -> V_323 ) ;
if ( ! F_109 ( V_35 , V_4 , V_312 ) )
return;
if ( V_316 >= V_314 ||
V_315 >= V_313 )
F_110 ( V_35 , V_312 , NULL ) ;
}
void F_111 ( struct V_34 * V_35 ,
struct V_289 * V_290 )
{
struct V_291 * V_292 = F_98 ( V_290 ) ;
struct V_307 * V_324 = ( void * ) V_292 -> V_6 ;
F_51 ( V_35 ,
L_18 ,
F_47 ( V_324 -> V_317 ) ,
F_47 ( V_324 -> V_318 ) ,
F_47 ( V_324 -> V_319 ) ,
F_47 ( V_324 -> V_325 ) ,
F_47 ( V_324 -> V_326 ) ) ;
F_14 ( V_35 -> V_41 ,
V_327 ,
F_105 ,
V_324 ) ;
}
void F_112 ( struct V_34 * V_35 ,
struct V_289 * V_290 )
{
struct V_291 * V_292 = F_98 ( V_290 ) ;
struct V_328 * V_329 = ( void * ) V_292 -> V_6 ;
struct V_330 V_331 ;
struct V_222 * V_332 ;
T_3 V_333 = F_47 ( V_329 -> V_334 ) ;
if ( V_333 == 0 )
return;
V_332 = F_113 ( V_333 , V_335 ) ;
if ( ! V_332 ) {
F_22 ( V_35 , L_19 ) ;
return;
}
memset ( & V_331 , 0 , sizeof( V_331 ) ) ;
V_331 . V_336 = F_52 ( V_329 -> V_300 ) ;
V_331 . V_337 |= V_338 ;
V_331 . V_339 = F_47 ( V_329 -> V_340 ) ;
V_331 . V_77 =
( V_329 -> V_341 & F_43 ( V_342 ) ) ?
V_139 : V_249 ;
V_331 . V_343 =
F_114 ( F_99 ( V_329 -> V_344 ) ,
V_331 . V_77 ) ;
memcpy ( F_115 ( V_332 , V_333 ) , V_329 -> V_6 , V_333 ) ;
memcpy ( F_116 ( V_332 ) , & V_331 , sizeof( V_331 ) ) ;
F_117 ( V_35 -> V_41 , NULL , V_332 , NULL ) ;
}
void F_118 ( struct V_34 * V_35 ,
struct V_289 * V_290 )
{
struct V_291 * V_292 = F_98 ( V_290 ) ;
struct V_345 * V_346 = ( void * ) V_292 -> V_6 ;
struct V_3 * V_280 ;
struct V_7 * V_8 ;
int V_235 = F_119 ( V_292 ) ;
T_3 V_347 ;
if ( F_21 ( V_235 < sizeof( * V_346 ) ) )
return;
F_40 () ;
V_280 = F_41 ( V_35 -> V_280 ) ;
if ( F_49 ( ! V_280 || ! V_280 -> V_302 ) )
goto V_348;
V_347 = F_47 ( V_346 -> V_123 ) ;
V_8 = F_2 ( V_280 ) ;
if ( F_120 ( F_38 ( V_8 -> V_45 , V_8 -> V_57 ) != V_347 ,
L_20 ,
F_38 ( V_8 -> V_45 , V_8 -> V_57 ) , V_347 ) )
goto V_348;
F_51 ( V_35 , L_21 ) ;
F_121 ( V_349 , & V_35 -> V_350 ,
F_122 ( V_306 *
V_280 -> V_16 . V_17 ) ) ;
F_95 ( V_280 ) ;
F_42 () ;
F_96 ( V_35 -> V_280 , NULL ) ;
return;
V_348:
F_42 () ;
}
