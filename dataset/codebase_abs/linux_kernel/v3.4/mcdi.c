static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
F_2 ( F_3 ( V_3 ) < V_6 ) ;
V_5 = V_3 -> V_5 ;
return & V_5 -> V_7 ;
}
void F_4 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
if ( F_3 ( V_3 ) < V_6 )
return;
V_7 = F_1 ( V_3 ) ;
F_5 ( & V_7 -> V_8 ) ;
F_6 ( & V_7 -> V_9 ) ;
F_7 ( & V_7 -> V_10 , V_11 ) ;
V_7 -> V_12 = V_13 ;
( void ) F_8 ( V_3 ) ;
}
static void F_9 ( struct V_2 * V_3 , unsigned V_14 ,
const T_1 * V_15 , T_2 V_16 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned V_17 = V_18 + F_10 ( V_3 ) ;
unsigned V_19 = V_18 + F_11 ( V_3 ) ;
unsigned int V_20 ;
T_3 V_21 ;
T_4 V_22 , V_23 ;
F_12 ( F_13 ( & V_7 -> V_10 ) == V_11 ) ;
F_12 ( V_16 & 3 || V_16 >= V_24 ) ;
V_23 = V_7 -> V_23 & V_25 ;
V_22 = 0 ;
if ( V_7 -> V_12 == V_26 )
V_22 |= V_27 ;
F_14 ( V_21 ,
V_28 , 0 ,
V_29 , 1 ,
V_30 , V_14 ,
V_31 , V_16 ,
V_32 , V_23 ,
V_33 , V_22 ) ;
F_15 ( V_3 , & V_21 , V_17 ) ;
for ( V_20 = 0 ; V_20 < V_16 ; V_20 += 4 )
F_16 ( V_3 , * ( ( V_34 * ) ( V_15 + V_20 ) ) , V_17 + 4 + V_20 ) ;
F_17 () ;
F_16 ( V_3 , ( V_35 V_34 ) 0x45789abc , V_19 ) ;
}
static void F_18 ( struct V_2 * V_3 , T_1 * V_36 , T_2 V_37 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_17 = V_18 + F_10 ( V_3 ) ;
int V_20 ;
F_12 ( F_13 ( & V_7 -> V_10 ) == V_11 ) ;
F_12 ( V_37 & 3 || V_37 >= V_24 ) ;
for ( V_20 = 0 ; V_20 < V_37 ; V_20 += 4 )
* ( ( V_34 * ) ( V_36 + V_20 ) ) = F_19 ( V_3 , V_17 + 4 + V_20 ) ;
}
static int F_20 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int time , V_38 ;
unsigned int V_39 , V_40 , error ;
unsigned int V_17 = V_18 + F_10 ( V_3 ) ;
unsigned int V_41 , V_42 ;
T_3 V_43 ;
V_41 = - F_8 ( V_3 ) ;
if ( V_41 )
goto V_44;
V_42 = V_45 ;
V_38 = F_21 () + V_46 ;
while ( 1 ) {
if ( V_42 != 0 ) {
-- V_42 ;
F_22 ( 1 ) ;
} else {
F_23 ( 1 ) ;
}
time = F_21 () ;
F_24 () ;
F_25 ( V_3 , & V_43 , V_17 ) ;
if ( F_26 ( V_43 , V_47 ) != 0xffffffff &&
F_26 ( V_43 , V_28 ) )
break;
if ( time >= V_38 )
return - V_48 ;
}
V_7 -> V_49 = F_26 ( V_43 , V_31 ) ;
V_39 = F_26 ( V_43 , V_32 ) ;
V_40 = F_26 ( V_43 , V_30 ) ;
error = F_26 ( V_43 , V_50 ) ;
if ( error && V_7 -> V_49 == 0 ) {
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_1 ) ;
V_41 = V_53 ;
} else if ( ( V_39 ^ V_7 -> V_23 ) & V_25 ) {
F_27 ( V_3 , V_51 , V_3 -> V_52 ,
L_2 ,
V_39 , V_7 -> V_23 ) ;
V_41 = V_53 ;
} else if ( error ) {
F_25 ( V_3 , & V_43 , V_17 + 4 ) ;
switch ( F_26 ( V_43 , V_47 ) ) {
#define F_28 ( T_5 ) \
case MC_CMD_ERR_ ## name: \
rc = name; \
break
F_28 ( V_54 ) ;
F_28 ( V_55 ) ;
F_28 ( V_56 ) ;
F_28 ( V_57 ) ;
F_28 ( V_58 ) ;
F_28 ( V_59 ) ;
F_28 ( V_60 ) ;
F_28 ( V_61 ) ;
#undef F_28
default:
V_41 = V_53 ;
break;
}
} else
V_41 = 0 ;
V_44:
V_7 -> V_62 = V_41 ;
if ( V_41 )
V_7 -> V_49 = 0 ;
return 0 ;
}
int F_8 ( struct V_2 * V_3 )
{
unsigned int V_63 = V_18 + F_29 ( V_3 ) ;
T_3 V_43 ;
T_6 V_64 ;
if ( F_3 ( V_3 ) < V_6 )
return false ;
F_25 ( V_3 , & V_43 , V_63 ) ;
V_64 = F_26 ( V_43 , V_47 ) ;
if ( V_64 == 0 )
return 0 ;
F_30 ( V_43 ) ;
F_15 ( V_3 , & V_43 , V_63 ) ;
if ( V_64 == V_65 )
return - V_55 ;
else
return - V_53 ;
}
static void F_31 ( struct V_1 * V_7 )
{
F_32 ( V_7 -> V_8 ,
F_33 ( & V_7 -> V_10 ,
V_11 ,
V_66 )
== V_11 ) ;
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( F_35 (
V_7 -> V_8 ,
F_13 ( & V_7 -> V_10 ) == V_67 ,
F_36 ( V_46 * 1000 ) ) == 0 )
return - V_48 ;
if ( V_7 -> V_12 == V_13 )
return F_20 ( V_3 ) ;
return 0 ;
}
static bool F_37 ( struct V_1 * V_7 )
{
if ( F_33 ( & V_7 -> V_10 ,
V_66 ,
V_67 ) == V_66 ) {
F_38 ( & V_7 -> V_8 ) ;
return true ;
}
return false ;
}
static void F_39 ( struct V_1 * V_7 )
{
F_7 ( & V_7 -> V_10 , V_11 ) ;
F_38 ( & V_7 -> V_8 ) ;
}
static void F_40 ( struct V_2 * V_3 , unsigned int V_23 ,
unsigned int V_68 , unsigned int V_69 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
bool V_70 = false ;
F_41 ( & V_7 -> V_9 ) ;
if ( ( V_23 ^ V_7 -> V_23 ) & V_25 ) {
if ( V_7 -> V_71 )
-- V_7 -> V_71 ;
else
F_27 ( V_3 , V_51 , V_3 -> V_52 ,
L_3
L_4 , V_23 , V_7 -> V_23 ) ;
} else {
V_7 -> V_62 = V_69 ;
V_7 -> V_49 = V_68 ;
V_70 = true ;
}
F_42 ( & V_7 -> V_9 ) ;
if ( V_70 )
F_37 ( V_7 ) ;
}
int F_43 ( struct V_2 * V_3 , unsigned V_14 ,
const T_1 * V_15 , T_2 V_16 , T_1 * V_36 , T_2 V_37 ,
T_2 * V_72 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_41 ;
F_12 ( F_3 ( V_3 ) < V_6 ) ;
F_31 ( V_7 ) ;
F_44 ( & V_7 -> V_9 ) ;
++ V_7 -> V_23 ;
F_45 ( & V_7 -> V_9 ) ;
F_9 ( V_3 , V_14 , V_15 , V_16 ) ;
if ( V_7 -> V_12 == V_13 )
V_41 = F_20 ( V_3 ) ;
else
V_41 = F_34 ( V_3 ) ;
if ( V_41 != 0 ) {
F_44 ( & V_7 -> V_9 ) ;
++ V_7 -> V_23 ;
++ V_7 -> V_71 ;
F_45 ( & V_7 -> V_9 ) ;
F_27 ( V_3 , V_51 , V_3 -> V_52 ,
L_5 ,
V_14 , ( int ) V_16 , V_7 -> V_12 ) ;
} else {
T_2 V_49 ;
F_44 ( & V_7 -> V_9 ) ;
V_41 = - V_7 -> V_62 ;
V_49 = V_7 -> V_49 ;
F_45 ( & V_7 -> V_9 ) ;
if ( V_41 == 0 ) {
F_18 ( V_3 , V_36 ,
F_46 ( V_37 , V_7 -> V_49 + 3 ) & ~ 0x3 ) ;
if ( V_72 != NULL )
* V_72 = V_49 ;
} else if ( V_14 == V_73 && V_41 == - V_53 )
;
else if ( V_41 == - V_53 || V_41 == - V_55 ) {
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_6 ,
- V_41 ) ;
F_47 ( V_3 , V_74 ) ;
} else
F_48 ( V_3 , V_51 , V_3 -> V_52 ,
L_7 ,
V_14 , ( int ) V_16 , - V_41 ) ;
if ( V_41 == - V_53 || V_41 == - V_55 ) {
F_49 ( V_75 ) ;
F_8 ( V_3 ) ;
}
}
F_39 ( V_7 ) ;
return V_41 ;
}
void F_50 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
if ( F_3 ( V_3 ) < V_6 )
return;
V_7 = F_1 ( V_3 ) ;
if ( V_7 -> V_12 == V_13 )
return;
V_7 -> V_12 = V_13 ;
F_37 ( V_7 ) ;
}
void F_51 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
if ( F_3 ( V_3 ) < V_6 )
return;
V_7 = F_1 ( V_3 ) ;
if ( V_7 -> V_12 == V_26 )
return;
F_31 ( V_7 ) ;
V_7 -> V_12 = V_26 ;
F_39 ( V_7 ) ;
}
static void F_52 ( struct V_2 * V_3 , int V_41 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_41 ( & V_7 -> V_9 ) ;
if ( F_37 ( V_7 ) ) {
if ( V_7 -> V_12 == V_26 ) {
V_7 -> V_62 = V_41 ;
V_7 -> V_49 = 0 ;
++ V_7 -> V_71 ;
}
} else {
int V_76 ;
F_47 ( V_3 , V_74 ) ;
for ( V_76 = 0 ; V_76 < V_77 ; ++ V_76 ) {
if ( F_8 ( V_3 ) )
break;
F_22 ( V_78 ) ;
}
}
F_42 ( & V_7 -> V_9 ) ;
}
static void F_53 ( struct V_2 * V_3 , T_7 * V_79 )
{
T_4 V_80 , V_81 , V_82 , V_83 ;
V_82 = F_54 ( * V_79 , V_84 ) ;
F_2 ( V_82 >= F_55 ( V_85 ) ) ;
V_82 = V_85 [ V_82 ] ;
V_80 = F_54 ( * V_79 , V_86 ) ;
V_81 = F_54 ( * V_79 , V_87 ) ;
V_83 = F_54 ( * V_79 , V_88 ) ;
F_56 ( V_3 , & V_3 -> V_89 , V_82 , V_80 , V_81 ) ;
F_57 ( V_3 , V_83 ) ;
F_58 ( V_3 ) ;
}
void F_59 ( struct V_90 * V_91 ,
T_7 * V_92 )
{
struct V_2 * V_3 = V_91 -> V_3 ;
int V_93 = F_54 ( * V_92 , V_94 ) ;
T_4 V_95 = F_54 ( * V_92 , V_96 ) ;
switch ( V_93 ) {
case V_97 :
F_27 ( V_3 , V_51 , V_3 -> V_52 ,
L_8 , V_95 ) ;
F_52 ( V_3 , V_55 ) ;
break;
case V_98 :
F_60 ( V_3 , V_99 , V_3 -> V_52 , L_9 ) ;
break;
case V_100 :
F_40 ( V_3 ,
F_61 ( * V_92 , V_101 ) ,
F_61 ( * V_92 , V_102 ) ,
F_61 ( * V_92 , V_103 ) ) ;
break;
case V_104 :
F_53 ( V_3 , V_92 ) ;
break;
case V_105 :
F_62 ( V_3 , V_92 ) ;
break;
case V_106 :
F_60 ( V_3 , V_51 , V_3 -> V_52 ,
L_10 , V_95 ) ;
break;
case V_107 :
F_60 ( V_3 , V_51 , V_3 -> V_52 , L_11 ) ;
F_52 ( V_3 , V_53 ) ;
break;
case V_108 :
break;
case V_109 :
F_63 ( V_3 , F_61 ( * V_92 , V_110 ) ) ;
break;
default:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_12 ,
V_93 ) ;
}
}
void F_64 ( struct V_2 * V_3 , char * V_111 , T_2 V_112 )
{
T_1 V_36 [ F_65 ( V_113 , 4 ) ] ;
T_2 V_114 ;
const T_8 * V_115 ;
int V_41 ;
F_66 ( V_116 != 0 ) ;
V_41 = F_43 ( V_3 , V_117 , NULL , 0 ,
V_36 , sizeof( V_36 ) , & V_114 ) ;
if ( V_41 )
goto V_118;
if ( V_114 < V_113 ) {
V_41 = - V_53 ;
goto V_118;
}
V_115 = ( T_8 * ) F_67 ( V_36 , V_119 ) ;
snprintf ( V_111 , V_112 , L_13 ,
F_68 ( V_115 [ 0 ] ) , F_68 ( V_115 [ 1 ] ) ,
F_68 ( V_115 [ 2 ] ) , F_68 ( V_115 [ 3 ] ) ) ;
return;
V_118:
F_27 ( V_3 , V_120 , V_3 -> V_52 , L_14 , V_121 , V_41 ) ;
V_111 [ 0 ] = 0 ;
}
int F_69 ( struct V_2 * V_3 , bool V_122 ,
bool * V_123 )
{
T_1 V_15 [ V_124 ] ;
T_1 V_36 [ V_125 ] ;
T_2 V_37 ;
int V_41 ;
F_70 ( V_15 , V_126 ,
V_122 ? 1 : 0 ) ;
F_70 ( V_15 , V_127 , 1 ) ;
V_41 = F_43 ( V_3 , V_128 , V_15 , sizeof( V_15 ) ,
V_36 , sizeof( V_36 ) , & V_37 ) ;
if ( V_41 )
goto V_118;
if ( V_37 < V_125 ) {
V_41 = - V_53 ;
goto V_118;
}
if ( V_123 != NULL )
* V_123 = F_71 ( V_36 , V_129 ) ;
return 0 ;
V_118:
F_27 ( V_3 , V_120 , V_3 -> V_52 , L_14 , V_121 , V_41 ) ;
return V_41 ;
}
int F_72 ( struct V_2 * V_3 , T_1 * V_130 ,
T_9 * V_131 , T_4 * V_132 )
{
T_10 V_36 [ V_133 ] ;
T_2 V_37 ;
int V_134 = F_73 ( V_3 ) ;
int V_135 ;
int V_41 ;
F_66 ( V_136 != 0 ) ;
V_41 = F_43 ( V_3 , V_137 , NULL , 0 ,
V_36 , sizeof( V_36 ) , & V_37 ) ;
if ( V_41 )
goto V_118;
if ( V_37 < V_133 ) {
V_41 = - V_53 ;
goto V_118;
}
V_135 = ( V_134 )
? V_138
: V_139 ;
if ( V_130 )
memcpy ( V_130 , V_36 + V_135 , V_140 ) ;
if ( V_131 )
memcpy ( V_131 ,
V_36 + V_141 ,
V_142 *
sizeof( V_131 [ 0 ] ) ) ;
if ( V_132 ) {
if ( V_134 )
* V_132 = F_71 ( V_36 ,
V_143 ) ;
else
* V_132 = F_71 ( V_36 ,
V_144 ) ;
}
return 0 ;
V_118:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_15 ,
V_121 , V_41 , ( int ) V_37 ) ;
return V_41 ;
}
int F_74 ( struct V_2 * V_3 , bool V_145 , bool V_146 , T_4 V_147 )
{
T_1 V_15 [ V_148 ] ;
T_4 V_149 = 0 ;
int V_41 ;
if ( V_146 )
V_149 |= V_150 ;
if ( V_145 )
V_149 |= V_151 ;
F_70 ( V_15 , V_152 , V_149 ) ;
F_70 ( V_15 , V_153 , V_147 ) ;
F_66 ( V_154 != 0 ) ;
V_41 = F_43 ( V_3 , V_155 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_41 )
goto V_118;
return 0 ;
V_118:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_121 , V_41 ) ;
return V_41 ;
}
int F_75 ( struct V_2 * V_3 , T_4 * V_156 )
{
T_1 V_36 [ V_157 ] ;
T_2 V_37 ;
int V_41 ;
F_66 ( V_158 != 0 ) ;
V_41 = F_43 ( V_3 , V_159 , NULL , 0 ,
V_36 , sizeof( V_36 ) , & V_37 ) ;
if ( V_41 )
goto V_118;
if ( V_37 < V_157 ) {
V_41 = - V_53 ;
goto V_118;
}
* V_156 = F_71 ( V_36 , V_160 ) ;
return 0 ;
V_118:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 ,
V_121 , V_41 ) ;
return V_41 ;
}
int F_76 ( struct V_2 * V_3 , unsigned int type ,
T_2 * V_161 , T_2 * V_162 ,
bool * V_163 )
{
T_1 V_15 [ V_164 ] ;
T_1 V_36 [ V_165 ] ;
T_2 V_37 ;
int V_41 ;
F_70 ( V_15 , V_166 , type ) ;
V_41 = F_43 ( V_3 , V_167 , V_15 , sizeof( V_15 ) ,
V_36 , sizeof( V_36 ) , & V_37 ) ;
if ( V_41 )
goto V_118;
if ( V_37 < V_165 ) {
V_41 = - V_53 ;
goto V_118;
}
* V_161 = F_71 ( V_36 , V_168 ) ;
* V_162 = F_71 ( V_36 , V_169 ) ;
* V_163 = ! ! ( F_71 ( V_36 , V_170 ) &
( 1 << V_171 ) ) ;
return 0 ;
V_118:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_121 , V_41 ) ;
return V_41 ;
}
int F_77 ( struct V_2 * V_3 , unsigned int type )
{
T_1 V_15 [ V_172 ] ;
int V_41 ;
F_70 ( V_15 , V_173 , type ) ;
F_66 ( V_174 != 0 ) ;
V_41 = F_43 ( V_3 , V_175 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_41 )
goto V_118;
return 0 ;
V_118:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_121 , V_41 ) ;
return V_41 ;
}
int F_78 ( struct V_2 * V_3 , unsigned int type ,
T_11 V_135 , T_1 * V_176 , T_2 V_177 )
{
T_1 V_15 [ V_178 ] ;
T_1 V_36 [ F_79 ( V_179 ) ] ;
T_2 V_37 ;
int V_41 ;
F_70 ( V_15 , V_180 , type ) ;
F_70 ( V_15 , V_181 , V_135 ) ;
F_70 ( V_15 , V_182 , V_177 ) ;
V_41 = F_43 ( V_3 , V_183 , V_15 , sizeof( V_15 ) ,
V_36 , sizeof( V_36 ) , & V_37 ) ;
if ( V_41 )
goto V_118;
memcpy ( V_176 , F_67 ( V_36 , V_184 ) , V_177 ) ;
return 0 ;
V_118:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_121 , V_41 ) ;
return V_41 ;
}
int F_80 ( struct V_2 * V_3 , unsigned int type ,
T_11 V_135 , const T_1 * V_176 , T_2 V_177 )
{
T_1 V_15 [ F_81 ( V_179 ) ] ;
int V_41 ;
F_70 ( V_15 , V_185 , type ) ;
F_70 ( V_15 , V_186 , V_135 ) ;
F_70 ( V_15 , V_187 , V_177 ) ;
memcpy ( F_67 ( V_15 , V_188 ) , V_176 , V_177 ) ;
F_66 ( V_189 != 0 ) ;
V_41 = F_43 ( V_3 , V_190 , V_15 ,
F_65 ( F_81 ( V_177 ) , 4 ) ,
NULL , 0 , NULL ) ;
if ( V_41 )
goto V_118;
return 0 ;
V_118:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_121 , V_41 ) ;
return V_41 ;
}
int F_82 ( struct V_2 * V_3 , unsigned int type ,
T_11 V_135 , T_2 V_177 )
{
T_1 V_15 [ V_191 ] ;
int V_41 ;
F_70 ( V_15 , V_192 , type ) ;
F_70 ( V_15 , V_193 , V_135 ) ;
F_70 ( V_15 , V_194 , V_177 ) ;
F_66 ( V_195 != 0 ) ;
V_41 = F_43 ( V_3 , V_196 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_41 )
goto V_118;
return 0 ;
V_118:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_121 , V_41 ) ;
return V_41 ;
}
int F_83 ( struct V_2 * V_3 , unsigned int type )
{
T_1 V_15 [ V_197 ] ;
int V_41 ;
F_70 ( V_15 , V_198 , type ) ;
F_66 ( V_199 != 0 ) ;
V_41 = F_43 ( V_3 , V_200 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_41 )
goto V_118;
return 0 ;
V_118:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_121 , V_41 ) ;
return V_41 ;
}
static int F_84 ( struct V_2 * V_3 , unsigned int type )
{
T_1 V_15 [ V_201 ] ;
T_1 V_36 [ V_202 ] ;
int V_41 ;
F_70 ( V_15 , V_203 , type ) ;
V_41 = F_43 ( V_3 , V_204 , V_15 , sizeof( V_15 ) ,
V_36 , sizeof( V_36 ) , NULL ) ;
if ( V_41 )
return V_41 ;
switch ( F_71 ( V_36 , V_205 ) ) {
case V_206 :
case V_207 :
return 0 ;
default:
return - V_53 ;
}
}
int F_85 ( struct V_2 * V_3 )
{
T_4 V_208 ;
unsigned int type ;
int V_41 ;
V_41 = F_75 ( V_3 , & V_208 ) ;
if ( V_41 )
goto V_209;
type = 0 ;
while ( V_208 != 0 ) {
if ( V_208 & 1 ) {
V_41 = F_84 ( V_3 , type ) ;
if ( V_41 )
goto V_210;
}
type ++ ;
V_208 >>= 1 ;
}
return 0 ;
V_210:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_16 ,
V_121 , type ) ;
V_209:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_121 , V_41 ) ;
return V_41 ;
}
static int F_86 ( struct V_2 * V_3 )
{
T_1 V_15 [ V_211 ] ;
T_1 V_36 [ V_212 ] ;
unsigned int V_80 , V_213 , V_214 ;
const char * V_215 ;
T_2 V_37 ;
int V_216 ;
int V_41 ;
V_216 = 2 ;
do {
F_70 ( V_15 , V_217 , 1 ) ;
V_41 = F_43 ( V_3 , V_218 ,
V_15 , V_211 ,
V_36 , sizeof( V_36 ) , & V_37 ) ;
} while ( ( V_41 == - V_55 || V_41 == - V_53 ) && V_216 -- > 0 );
if ( V_41 )
return V_41 ;
if ( V_37 < V_212 )
return - V_53 ;
V_80 = F_71 ( V_36 , V_219 ) ;
if ( V_80 == V_220 )
return 0 ;
V_215 = ( V_80 == V_221 )
? L_17
: ( V_80 == V_222 )
? L_18
: ( V_80 == V_223 )
? L_19
: L_20 ;
F_27 ( V_3 , V_51 , V_3 -> V_52 ,
L_21 , V_215 ,
F_71 ( V_36 , V_224 ) ,
F_71 ( V_36 , V_225 ) ) ;
V_214 = V_226 ;
for ( V_213 = 1 ; V_213 < 32 ; V_213 ++ ) {
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_22 , V_213 ,
F_87 ( V_36 , V_214 ) ) ;
V_214 += sizeof( T_3 ) ;
}
return 0 ;
}
static void F_88 ( struct V_2 * V_3 )
{
T_1 V_15 [ V_227 ] ;
F_66 ( V_228 != 0 ) ;
F_70 ( V_15 , V_229 ,
V_230 ) ;
F_43 ( V_3 , V_73 , V_15 , V_227 ,
NULL , 0 , NULL ) ;
}
int F_89 ( struct V_2 * V_3 )
{
int V_41 ;
V_41 = F_86 ( V_3 ) ;
if ( V_41 )
return V_41 ;
F_88 ( V_3 ) ;
return 0 ;
}
void F_90 ( struct V_2 * V_3 , enum V_231 V_12 )
{
T_1 V_15 [ V_232 ] ;
int V_41 ;
F_66 ( V_233 != V_234 ) ;
F_66 ( V_235 != V_236 ) ;
F_66 ( V_237 != V_238 ) ;
F_66 ( V_239 != 0 ) ;
F_70 ( V_15 , V_240 , V_12 ) ;
V_41 = F_43 ( V_3 , V_241 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_41 )
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 ,
V_121 , V_41 ) ;
}
int F_91 ( struct V_2 * V_3 )
{
int V_41 = F_43 ( V_3 , V_242 , NULL , 0 , NULL , 0 , NULL ) ;
if ( V_41 )
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 ,
V_121 , V_41 ) ;
return V_41 ;
}
int F_92 ( struct V_2 * V_3 )
{
T_1 V_15 [ V_227 ] ;
int V_41 ;
F_66 ( V_228 != 0 ) ;
F_70 ( V_15 , V_229 , 0 ) ;
V_41 = F_43 ( V_3 , V_73 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_41 == - V_53 )
return 0 ;
if ( V_41 == 0 )
V_41 = - V_53 ;
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_121 , V_41 ) ;
return V_41 ;
}
static int F_93 ( struct V_2 * V_3 , T_4 type ,
const T_1 * V_243 , int * V_244 )
{
T_1 V_15 [ V_245 ] ;
T_1 V_36 [ V_246 ] ;
T_2 V_37 ;
int V_41 ;
F_70 ( V_15 , V_247 , type ) ;
F_70 ( V_15 , V_248 ,
V_249 ) ;
memcpy ( F_67 ( V_15 , V_250 ) , V_243 , V_140 ) ;
V_41 = F_43 ( V_3 , V_251 , V_15 , sizeof( V_15 ) ,
V_36 , sizeof( V_36 ) , & V_37 ) ;
if ( V_41 )
goto V_118;
if ( V_37 < V_246 ) {
V_41 = - V_53 ;
goto V_118;
}
* V_244 = ( int ) F_71 ( V_36 , V_252 ) ;
return 0 ;
V_118:
* V_244 = - 1 ;
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_121 , V_41 ) ;
return V_41 ;
}
int
F_94 ( struct V_2 * V_3 , const T_1 * V_243 , int * V_244 )
{
return F_93 ( V_3 , V_253 , V_243 , V_244 ) ;
}
int F_95 ( struct V_2 * V_3 , int * V_244 )
{
T_1 V_36 [ V_254 ] ;
T_2 V_37 ;
int V_41 ;
V_41 = F_43 ( V_3 , V_255 , NULL , 0 ,
V_36 , sizeof( V_36 ) , & V_37 ) ;
if ( V_41 )
goto V_118;
if ( V_37 < V_254 ) {
V_41 = - V_53 ;
goto V_118;
}
* V_244 = ( int ) F_71 ( V_36 , V_256 ) ;
return 0 ;
V_118:
* V_244 = - 1 ;
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_121 , V_41 ) ;
return V_41 ;
}
int F_96 ( struct V_2 * V_3 , int V_257 )
{
T_1 V_15 [ V_258 ] ;
int V_41 ;
F_70 ( V_15 , V_259 , ( T_4 ) V_257 ) ;
V_41 = F_43 ( V_3 , V_260 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_41 )
goto V_118;
return 0 ;
V_118:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_121 , V_41 ) ;
return V_41 ;
}
int F_97 ( struct V_2 * V_3 )
{
struct V_90 * V_91 ;
struct V_261 * V_262 ;
V_34 * V_263 ;
int V_41 , V_76 ;
V_263 = F_98 ( V_264 * sizeof( * V_263 ) , V_265 ) ;
if ( V_263 == NULL )
return - V_266 ;
V_76 = 0 ;
F_99 (channel, efx) {
F_100 (rx_queue, channel) {
if ( V_262 -> V_267 ) {
V_262 -> V_267 = false ;
F_101 ( & V_3 -> V_268 ) ;
V_263 [ V_76 ++ ] = F_102 (
F_103 ( V_262 ) ) ;
}
}
}
V_41 = F_43 ( V_3 , V_269 , ( T_1 * ) V_263 ,
V_76 * sizeof( * V_263 ) , NULL , 0 , NULL ) ;
F_104 ( V_41 > 0 ) ;
F_105 ( V_263 ) ;
return V_41 ;
}
int F_106 ( struct V_2 * V_3 )
{
int V_41 ;
V_41 = F_43 ( V_3 , V_270 , NULL , 0 , NULL , 0 , NULL ) ;
if ( V_41 )
goto V_118;
return 0 ;
V_118:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_121 , V_41 ) ;
return V_41 ;
}
