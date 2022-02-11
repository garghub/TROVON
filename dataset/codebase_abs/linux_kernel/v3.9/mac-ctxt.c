static void F_1 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
T_2 V_9 ;
if ( V_4 == V_6 -> V_4 ) {
V_6 -> V_10 = true ;
return;
}
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ )
if ( V_4 -> V_12 [ V_9 ] != V_13 )
F_3 ( V_4 -> V_12 [ V_9 ] , V_6 -> V_14 ) ;
if ( V_4 -> V_15 != V_13 )
F_3 ( V_4 -> V_15 , V_6 -> V_14 ) ;
F_4 ( V_8 -> V_16 , V_6 -> V_17 ) ;
switch ( V_6 -> V_4 -> type ) {
case V_18 :
if ( V_4 -> type == V_19 ) {
if ( V_6 -> V_20 == V_21 &&
F_5 ( V_8 -> V_22 , V_6 -> V_23 ) )
V_6 -> V_20 = V_8 -> V_22 ;
return;
}
break;
case V_19 :
if ( V_4 -> type == V_18 ||
V_4 -> type == V_19 ) {
if ( V_6 -> V_20 == V_21 &&
F_5 ( V_8 -> V_22 , V_6 -> V_23 ) )
V_6 -> V_20 = V_8 -> V_22 ;
return;
}
break;
default:
break;
}
F_4 ( V_8 -> V_22 , V_6 -> V_23 ) ;
if ( V_6 -> V_20 == V_8 -> V_22 )
V_6 -> V_20 = V_21 ;
}
T_2 F_6 ( struct V_24 * V_25 ,
struct V_3 * V_4 )
{
T_2 V_26 , V_9 ;
if ( V_4 -> type == V_27 )
return F_7 ( V_28 ) ;
V_26 = ( V_4 -> V_15 != V_13 ) ?
F_7 ( V_4 -> V_15 ) : 0 ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ )
if ( V_4 -> V_12 [ V_9 ] != V_13 )
V_26 |= F_7 ( V_4 -> V_12 [ V_9 ] ) ;
return V_26 ;
}
static int F_8 ( struct V_24 * V_25 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_5 V_6 = {
. V_25 = V_25 ,
. V_4 = V_4 ,
. V_17 = { ( 1 << V_29 ) - 1 } ,
. V_23 = { ( 1 << V_21 ) - 1 } ,
. V_20 = V_21 ,
. V_14 = {
F_7 ( V_30 ) |
F_7 ( V_31 ) |
F_7 (IWL_MVM_CMD_QUEUE)
} ,
. V_10 = false ,
} ;
T_2 V_9 ;
int V_32 ;
if ( V_4 -> type != V_18 || V_4 -> V_33 )
F_4 ( 0 , V_6 . V_17 ) ;
F_9 (
V_25 -> V_34 , V_35 ,
F_1 , & V_6 ) ;
if ( V_6 . V_10 )
return 0 ;
F_10 ( F_5 ( V_36 , & V_25 -> V_37 ) ) ;
V_8 -> V_16 = F_11 ( V_6 . V_17 ,
V_29 ) ;
if ( V_8 -> V_16 == V_29 ) {
F_12 ( V_25 , L_1 ) ;
V_32 = - V_38 ;
goto V_39;
}
if ( V_6 . V_20 != V_21 )
V_8 -> V_22 = V_6 . V_20 ;
else
V_8 -> V_22 = F_11 ( V_6 . V_23 ,
V_21 ) ;
if ( V_8 -> V_22 == V_21 ) {
F_12 ( V_25 , L_2 ) ;
V_32 = - V_38 ;
goto V_39;
}
V_8 -> V_40 = 0 ;
F_13 ( & V_8 -> V_41 . V_42 ) ;
V_8 -> V_41 . V_16 = V_43 ;
if ( V_4 -> type == V_27 ) {
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ )
V_4 -> V_12 [ V_9 ] = V_13 ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
T_1 V_44 = F_14 ( V_6 . V_14 ,
V_45 ) ;
if ( V_44 >= V_45 ) {
F_12 ( V_25 , L_3 ) ;
V_32 = - V_38 ;
goto V_39;
}
F_3 ( V_44 , V_6 . V_14 ) ;
V_4 -> V_12 [ V_9 ] = V_44 ;
}
if ( V_4 -> type == V_19 ) {
T_1 V_44 = F_14 ( V_6 . V_14 ,
V_45 ) ;
if ( V_44 >= V_45 ) {
F_12 ( V_25 , L_4 ) ;
V_32 = - V_38 ;
goto V_39;
}
V_4 -> V_15 = V_44 ;
} else {
V_4 -> V_15 = V_13 ;
}
V_8 -> V_46 . V_47 = V_48 ;
V_8 -> V_49 = V_48 ;
return 0 ;
V_39:
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
memset ( V_4 -> V_12 , V_13 , sizeof( V_4 -> V_12 ) ) ;
V_4 -> V_15 = V_13 ;
return V_32 ;
}
int F_15 ( struct V_24 * V_25 , struct V_3 * V_4 )
{
T_2 V_9 ;
int V_32 ;
F_16 ( & V_25 -> V_50 ) ;
V_32 = F_8 ( V_25 , V_4 ) ;
if ( V_32 )
return V_32 ;
switch ( V_4 -> type ) {
case V_27 :
F_17 ( V_25 -> V_51 , V_30 ,
V_52 ) ;
break;
case V_19 :
F_17 ( V_25 -> V_51 , V_4 -> V_15 ,
V_52 ) ;
default:
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ )
F_17 ( V_25 -> V_51 , V_4 -> V_12 [ V_9 ] ,
V_53 [ V_9 ] ) ;
break;
}
return 0 ;
}
void F_18 ( struct V_24 * V_25 , struct V_3 * V_4 )
{
int V_9 ;
F_16 ( & V_25 -> V_50 ) ;
switch ( V_4 -> type ) {
case V_27 :
F_19 ( V_25 -> V_51 , V_30 ) ;
break;
case V_19 :
F_19 ( V_25 -> V_51 , V_4 -> V_15 ) ;
default:
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ )
F_19 ( V_25 -> V_51 , V_4 -> V_12 [ V_9 ] ) ;
}
}
static void F_20 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
enum V_54 V_55 ,
T_1 * V_56 , T_1 * V_57 )
{
struct V_58 * V_59 ;
unsigned long V_60 = V_4 -> V_61 . V_62 ;
int V_63 = 100 ;
int V_64 = 100 ;
T_1 V_65 = 0 ;
T_1 V_66 = 0 ;
int V_67 ;
V_59 = V_25 -> V_34 -> V_68 -> V_69 [ V_55 ] ;
F_21 (i, &basic, BITS_PER_LONG) {
int V_34 = V_59 -> V_70 [ V_67 ] . V_71 ;
if ( V_34 >= V_72 ) {
V_66 |= F_7 ( V_34 - V_72 ) ;
if ( V_63 > V_34 )
V_63 = V_34 ;
} else {
F_22 ( V_73 != 0 ) ;
V_65 |= F_7 ( V_34 ) ;
if ( V_64 > V_34 )
V_64 = V_34 ;
}
}
if ( V_74 < V_63 )
V_66 |= F_23 ( 24 ) >> V_72 ;
if ( V_75 < V_63 )
V_66 |= F_23 ( 12 ) >> V_72 ;
V_66 |= F_23 ( 6 ) >> V_72 ;
if ( V_76 < V_64 )
V_65 |= F_23 ( 11 ) >> V_73 ;
if ( V_77 < V_64 )
V_65 |= F_23 ( 5 ) >> V_73 ;
if ( V_78 < V_64 )
V_65 |= F_23 ( 2 ) >> V_73 ;
V_65 |= F_23 ( 1 ) >> V_73 ;
* V_56 = V_65 ;
* V_57 = V_66 ;
}
static void F_24 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
struct V_79 * V_80 ,
T_2 V_81 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_82 * V_83 ;
T_1 V_84 , V_85 ;
int V_67 ;
V_80 -> V_86 = F_25 ( F_26 ( V_8 -> V_16 ,
V_8 -> V_40 ) ) ;
V_80 -> V_81 = F_25 ( V_81 ) ;
switch ( V_4 -> type ) {
case V_18 :
if ( V_4 -> V_33 )
V_80 -> V_87 = F_25 ( V_88 ) ;
else
V_80 -> V_87 = F_25 ( V_89 ) ;
break;
case V_19 :
V_80 -> V_87 = F_25 ( V_90 ) ;
break;
case V_91 :
V_80 -> V_87 = F_25 ( V_92 ) ;
break;
case V_27 :
V_80 -> V_87 = F_25 ( V_93 ) ;
break;
case V_94 :
V_80 -> V_87 = F_25 ( V_95 ) ;
break;
default:
F_10 ( 1 ) ;
}
V_80 -> V_22 = F_25 ( V_8 -> V_22 ) ;
memcpy ( V_80 -> V_96 , V_4 -> V_97 , V_98 ) ;
if ( V_4 -> V_61 . V_99 )
memcpy ( V_80 -> V_100 , V_4 -> V_61 . V_99 , V_98 ) ;
else
F_27 ( V_80 -> V_100 ) ;
F_28 () ;
V_83 = F_29 ( V_4 -> V_101 ) ;
F_20 ( V_25 , V_4 , V_83 ? V_83 -> V_102 . V_103 -> V_55
: V_104 ,
& V_84 , & V_85 ) ;
F_30 () ;
V_80 -> V_56 = F_25 ( ( T_2 ) V_84 ) ;
V_80 -> V_57 = F_25 ( ( T_2 ) V_85 ) ;
V_80 -> V_105 =
F_25 ( V_4 -> V_61 . V_106 ?
V_107 : 0 ) ;
V_80 -> V_108 =
F_25 ( V_4 -> V_61 . V_109 ?
V_110 : 0 ) ;
for ( V_67 = 0 ; V_67 < V_111 ; V_67 ++ ) {
V_80 -> V_9 [ V_67 ] . V_112 = F_31 ( V_8 -> V_113 [ V_67 ] . V_112 ) ;
V_80 -> V_9 [ V_67 ] . V_114 = F_31 ( V_8 -> V_113 [ V_67 ] . V_114 ) ;
V_80 -> V_9 [ V_67 ] . V_115 = V_8 -> V_113 [ V_67 ] . V_116 ;
V_80 -> V_9 [ V_67 ] . V_117 =
F_31 ( V_8 -> V_113 [ V_67 ] . V_118 * 32 ) ;
V_80 -> V_9 [ V_67 ] . V_119 = F_7 ( V_53 [ V_67 ] ) ;
}
if ( V_4 -> V_61 . V_120 )
V_80 -> V_121 |= F_25 ( V_122 ) ;
if ( V_4 -> V_61 . V_123 )
V_80 -> V_124 |= F_25 ( V_125 |
V_126 ) ;
if ( V_4 -> V_61 . V_127 . V_128 != V_129 ) {
V_80 -> V_121 |= F_25 ( V_130 ) ;
V_80 -> V_124 |= F_25 ( V_131 |
V_132 ) ;
}
V_80 -> V_133 = F_25 ( V_134 ) ;
}
static int F_32 ( struct V_24 * V_25 ,
struct V_79 * V_80 )
{
int V_32 = F_33 ( V_25 , V_135 , V_136 ,
sizeof( * V_80 ) , V_80 ) ;
if ( V_32 )
F_12 ( V_25 , L_5 ,
F_34 ( V_80 -> V_81 ) , V_32 ) ;
return V_32 ;
}
static void F_35 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
struct V_137 * V_138 )
{
if ( V_4 -> V_61 . V_139 && V_4 -> V_61 . V_140 ) {
T_2 V_141 ;
V_141 = V_4 -> V_61 . V_142 *
V_4 -> V_61 . V_143 ;
V_141 *= 1024 ;
V_138 -> V_144 =
F_36 ( V_4 -> V_61 . V_145 + V_141 ) ;
V_138 -> V_146 =
F_25 ( V_4 -> V_61 . V_147 + V_141 ) ;
F_37 ( V_25 , L_6 ,
F_38 ( V_138 -> V_144 ) ,
F_34 ( V_138 -> V_146 ) ,
V_141 ) ;
V_138 -> V_148 = F_25 ( 1 ) ;
} else {
V_138 -> V_148 = F_25 ( 0 ) ;
}
V_138 -> V_149 = F_25 ( V_4 -> V_61 . V_143 ) ;
V_138 -> V_150 =
F_25 ( F_39 ( V_4 -> V_61 . V_143 ) ) ;
V_138 -> V_151 = F_25 ( V_4 -> V_61 . V_143 *
V_4 -> V_61 . V_140 ) ;
V_138 -> V_152 =
F_25 ( F_39 ( V_4 -> V_61 . V_143 *
V_4 -> V_61 . V_140 ) ) ;
V_138 -> V_153 = F_25 ( V_25 -> V_34 -> V_154 . V_153 ) ;
V_138 -> V_155 = F_25 ( V_4 -> V_61 . V_156 ) ;
}
static int F_40 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
T_2 V_81 )
{
struct V_79 V_80 = {} ;
F_41 ( V_4 -> type != V_18 || V_4 -> V_33 ) ;
F_24 ( V_25 , V_4 , & V_80 , V_81 ) ;
F_35 ( V_25 , V_4 , & V_80 . V_157 ) ;
return F_32 ( V_25 , & V_80 ) ;
}
static int F_42 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
T_2 V_81 )
{
struct V_79 V_80 = {} ;
F_41 ( V_4 -> type != V_18 || ! V_4 -> V_33 ) ;
F_24 ( V_25 , V_4 , & V_80 , V_81 ) ;
F_35 ( V_25 , V_4 , & V_80 . V_158 . V_157 ) ;
V_80 . V_158 . V_159 = F_25 ( V_4 -> V_61 . V_160 ) ;
return F_32 ( V_25 , & V_80 ) ;
}
static int F_43 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
T_2 V_81 )
{
struct V_79 V_80 = {} ;
F_41 ( V_4 -> type != V_91 ) ;
F_24 ( V_25 , V_4 , & V_80 , V_81 ) ;
return F_32 ( V_25 , & V_80 ) ;
}
static void F_44 ( void * V_1 , T_1 * V_2 , struct V_3 * V_4 )
{
struct V_161 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 -> type == V_19 && V_4 -> V_33 && V_8 -> V_162 )
V_6 -> V_163 = true ;
}
static int F_45 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
T_2 V_81 )
{
struct V_79 V_80 = {} ;
struct V_161 V_6 = {} ;
F_41 ( V_4 -> type != V_27 ) ;
F_24 ( V_25 , V_4 , & V_80 , V_81 ) ;
V_80 . V_124 |= F_25 ( V_125 ) ;
V_80 . V_133 |= F_25 ( V_164 ) ;
F_9 (
V_25 -> V_34 , V_35 ,
F_44 , & V_6 ) ;
V_80 . V_165 . V_166 = F_25 ( V_6 . V_163 ? 1 : 0 ) ;
return F_32 ( V_25 , & V_80 ) ;
}
static void F_46 ( struct V_24 * V_25 ,
struct V_167 * V_168 ,
T_1 * V_169 , T_2 V_170 )
{
T_2 V_171 ;
struct V_172 * V_173 = (struct V_172 * ) V_169 ;
V_171 = V_173 -> V_174 . V_169 . V_175 - V_169 ;
while ( ( V_171 < ( V_170 - 2 ) ) &&
( V_169 [ V_171 ] != V_176 ) )
V_171 += V_169 [ V_171 + 1 ] + 2 ;
if ( ( V_171 < ( V_170 - 1 ) ) && ( V_169 [ V_171 ] == V_176 ) ) {
V_168 -> V_171 = F_25 ( V_171 ) ;
V_168 -> V_177 = F_25 ( ( T_2 ) V_169 [ V_171 + 1 ] ) ;
} else {
F_47 ( V_25 , L_7 ) ;
}
}
static int F_48 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
struct V_178 * V_169 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_179 V_80 = {
. V_16 = V_180 ,
. V_181 = V_182 ,
} ;
struct V_167 V_168 = {} ;
struct V_183 * V_184 ;
T_2 V_185 ;
T_2 V_186 ;
if ( F_41 ( ! V_169 ) )
return - V_187 ;
V_185 = V_169 -> V_188 ;
V_168 . V_189 = F_25 ( ( T_2 ) V_8 -> V_16 ) ;
V_168 . V_190 . V_188 = F_31 ( ( V_191 ) V_185 ) ;
V_168 . V_190 . V_47 = V_8 -> V_46 . V_47 ;
V_168 . V_190 . V_192 = F_25 ( V_193 ) ;
V_168 . V_190 . V_194 = F_25 ( V_195 |
V_196 |
V_197 ) ;
V_25 -> V_198 =
F_49 ( V_25 , V_25 -> V_199 -> V_200 ,
V_25 -> V_198 ) ;
V_168 . V_190 . V_201 =
F_25 ( F_7 ( V_25 -> V_198 ) <<
V_202 ) ;
V_184 = F_50 ( V_169 ) ;
if ( V_184 -> V_55 == V_203 || V_4 -> V_33 ) {
V_186 = V_72 ;
} else {
V_186 = V_73 ;
V_168 . V_190 . V_201 |= F_25 ( V_204 ) ;
}
V_168 . V_190 . V_201 |=
F_25 ( F_51 ( V_186 ) ) ;
F_46 ( V_25 , & V_168 ,
V_169 -> V_6 ,
V_185 ) ;
V_80 . V_188 [ 0 ] = sizeof( V_168 ) ;
V_80 . V_6 [ 0 ] = & V_168 ;
V_80 . V_205 [ 0 ] = 0 ;
V_80 . V_188 [ 1 ] = V_185 ;
V_80 . V_6 [ 1 ] = V_169 -> V_6 ;
V_80 . V_205 [ 1 ] = V_206 ;
return F_52 ( V_25 , & V_80 ) ;
}
int F_53 ( struct V_24 * V_25 ,
struct V_3 * V_4 )
{
struct V_178 * V_169 ;
int V_32 ;
F_41 ( V_4 -> type != V_19 ) ;
V_169 = F_54 ( V_25 -> V_34 , V_4 ) ;
if ( ! V_169 )
return - V_207 ;
V_32 = F_48 ( V_25 , V_4 , V_169 ) ;
F_55 ( V_169 ) ;
return V_32 ;
}
static void F_56 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
struct V_208 * V_209 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
T_2 V_210 ;
V_209 -> V_149 = F_25 ( V_4 -> V_61 . V_143 ) ;
V_209 -> V_150 =
F_25 ( F_39 ( V_4 -> V_61 . V_143 ) ) ;
V_209 -> V_151 = F_25 ( V_4 -> V_61 . V_143 *
V_4 -> V_61 . V_140 ) ;
V_209 -> V_152 =
F_25 ( F_39 ( V_4 -> V_61 . V_143 *
V_4 -> V_61 . V_140 ) ) ;
V_209 -> V_211 = F_25 ( V_4 -> V_15 ) ;
V_210 = F_57 ( V_25 -> V_51 , V_212 ) ;
V_209 -> V_213 = F_25 ( V_210 ) ;
V_209 -> V_214 = F_36 ( V_210 ) ;
V_209 -> V_215 = F_25 ( V_8 -> V_16 ) ;
}
static int F_58 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
T_2 V_81 )
{
struct V_79 V_80 = {} ;
F_41 ( V_4 -> type != V_19 || V_4 -> V_33 ) ;
F_24 ( V_25 , V_4 , & V_80 , V_81 ) ;
F_56 ( V_25 , V_4 , & V_80 . V_216 ) ;
return F_32 ( V_25 , & V_80 ) ;
}
static int F_59 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
T_2 V_81 )
{
struct V_79 V_80 = {} ;
F_41 ( V_4 -> type != V_19 || ! V_4 -> V_33 ) ;
F_24 ( V_25 , V_4 , & V_80 , V_81 ) ;
F_56 ( V_25 , V_4 , & V_80 . V_217 . V_216 ) ;
V_80 . V_217 . V_159 = F_25 ( V_4 -> V_61 . V_160 ) ;
V_80 . V_217 . V_218 = F_25 ( ! ! V_4 -> V_61 . V_219 ) ;
return F_32 ( V_25 , & V_80 ) ;
}
static int F_60 ( struct V_24 * V_25 , struct V_3 * V_4 ,
T_2 V_81 )
{
switch ( V_4 -> type ) {
case V_18 :
if ( ! V_4 -> V_33 )
return F_40 ( V_25 , V_4 ,
V_81 ) ;
else
return F_42 ( V_25 , V_4 ,
V_81 ) ;
break;
case V_19 :
if ( ! V_4 -> V_33 )
return F_58 ( V_25 , V_4 , V_81 ) ;
else
return F_59 ( V_25 , V_4 , V_81 ) ;
break;
case V_91 :
return F_43 ( V_25 , V_4 , V_81 ) ;
case V_27 :
return F_45 ( V_25 , V_4 , V_81 ) ;
default:
break;
}
return - V_220 ;
}
int F_61 ( struct V_24 * V_25 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_32 ;
if ( F_62 ( V_8 -> V_221 , L_8 ,
V_4 -> V_97 , F_63 ( V_4 ) ) )
return - V_38 ;
V_32 = F_60 ( V_25 , V_4 , V_222 ) ;
if ( V_32 )
return V_32 ;
V_8 -> V_221 = true ;
return 0 ;
}
int F_64 ( struct V_24 * V_25 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( F_62 ( ! V_8 -> V_221 , L_9 ,
V_4 -> V_97 , F_63 ( V_4 ) ) )
return - V_38 ;
return F_60 ( V_25 , V_4 , V_223 ) ;
}
int F_65 ( struct V_24 * V_25 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_79 V_80 ;
int V_32 ;
if ( F_62 ( ! V_8 -> V_221 , L_10 ,
V_4 -> V_97 , F_63 ( V_4 ) ) )
return - V_38 ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
V_80 . V_86 = F_25 ( F_26 ( V_8 -> V_16 ,
V_8 -> V_40 ) ) ;
V_80 . V_81 = F_25 ( V_224 ) ;
V_32 = F_33 ( V_25 , V_135 , V_136 ,
sizeof( V_80 ) , & V_80 ) ;
if ( V_32 ) {
F_12 ( V_25 , L_11 , V_32 ) ;
return V_32 ;
}
V_8 -> V_221 = false ;
return 0 ;
}
