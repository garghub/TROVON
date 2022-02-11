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
F_44 ( V_3 , V_14 , V_15 , V_16 ) ;
return F_45 ( V_3 , V_14 , V_16 ,
V_36 , V_37 , V_72 ) ;
}
void F_44 ( struct V_2 * V_3 , unsigned V_14 , const T_1 * V_15 ,
T_2 V_16 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_12 ( F_3 ( V_3 ) < V_6 ) ;
F_31 ( V_7 ) ;
F_46 ( & V_7 -> V_9 ) ;
++ V_7 -> V_23 ;
F_47 ( & V_7 -> V_9 ) ;
F_9 ( V_3 , V_14 , V_15 , V_16 ) ;
}
int F_45 ( struct V_2 * V_3 , unsigned V_14 , T_2 V_16 ,
T_1 * V_36 , T_2 V_37 , T_2 * V_72 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_41 ;
F_12 ( F_3 ( V_3 ) < V_6 ) ;
if ( V_7 -> V_12 == V_13 )
V_41 = F_20 ( V_3 ) ;
else
V_41 = F_34 ( V_3 ) ;
if ( V_41 != 0 ) {
F_46 ( & V_7 -> V_9 ) ;
++ V_7 -> V_23 ;
++ V_7 -> V_71 ;
F_47 ( & V_7 -> V_9 ) ;
F_27 ( V_3 , V_51 , V_3 -> V_52 ,
L_5 ,
V_14 , ( int ) V_16 , V_7 -> V_12 ) ;
} else {
T_2 V_49 ;
F_46 ( & V_7 -> V_9 ) ;
V_41 = - V_7 -> V_62 ;
V_49 = V_7 -> V_49 ;
F_47 ( & V_7 -> V_9 ) ;
if ( V_41 == 0 ) {
F_18 ( V_3 , V_36 ,
F_48 ( V_37 , V_7 -> V_49 + 3 ) & ~ 0x3 ) ;
if ( V_72 != NULL )
* V_72 = V_49 ;
} else if ( V_14 == V_73 && V_41 == - V_53 )
;
else if ( V_41 == - V_53 || V_41 == - V_55 ) {
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_6 ,
- V_41 ) ;
F_49 ( V_3 , V_74 ) ;
} else
F_50 ( V_3 , V_51 , V_3 -> V_52 ,
L_7 ,
V_14 , ( int ) V_16 , - V_41 ) ;
if ( V_41 == - V_53 || V_41 == - V_55 ) {
F_51 ( V_75 ) ;
F_8 ( V_3 ) ;
}
}
F_39 ( V_7 ) ;
return V_41 ;
}
void F_52 ( struct V_2 * V_3 )
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
void F_53 ( struct V_2 * V_3 )
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
static void F_54 ( struct V_2 * V_3 , int V_41 )
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
F_49 ( V_3 , V_74 ) ;
for ( V_76 = 0 ; V_76 < V_77 ; ++ V_76 ) {
if ( F_8 ( V_3 ) )
break;
F_22 ( V_78 ) ;
}
}
F_42 ( & V_7 -> V_9 ) ;
}
static void F_55 ( struct V_2 * V_3 , T_7 * V_79 )
{
T_4 V_80 , V_81 , V_82 , V_83 ;
V_82 = F_56 ( * V_79 , V_84 ) ;
F_2 ( V_82 >= F_57 ( V_85 ) ) ;
V_82 = V_85 [ V_82 ] ;
V_80 = F_56 ( * V_79 , V_86 ) ;
V_81 = F_56 ( * V_79 , V_87 ) ;
V_83 = F_56 ( * V_79 , V_88 ) ;
F_58 ( V_3 , & V_3 -> V_89 , V_82 , V_80 , V_81 ) ;
F_59 ( V_3 , V_83 ) ;
F_60 ( V_3 ) ;
}
void F_61 ( struct V_90 * V_91 ,
T_7 * V_92 )
{
struct V_2 * V_3 = V_91 -> V_3 ;
int V_93 = F_56 ( * V_92 , V_94 ) ;
T_4 V_95 = F_56 ( * V_92 , V_96 ) ;
switch ( V_93 ) {
case V_97 :
F_27 ( V_3 , V_51 , V_3 -> V_52 ,
L_8 , V_95 ) ;
F_54 ( V_3 , V_55 ) ;
break;
case V_98 :
F_62 ( V_3 , V_99 , V_3 -> V_52 , L_9 ) ;
break;
case V_100 :
F_40 ( V_3 ,
F_63 ( * V_92 , V_101 ) ,
F_63 ( * V_92 , V_102 ) ,
F_63 ( * V_92 , V_103 ) ) ;
break;
case V_104 :
F_55 ( V_3 , V_92 ) ;
break;
case V_105 :
F_64 ( V_3 , V_92 ) ;
break;
case V_106 :
F_62 ( V_3 , V_51 , V_3 -> V_52 ,
L_10 , V_95 ) ;
break;
case V_107 :
F_62 ( V_3 , V_51 , V_3 -> V_52 , L_11 ) ;
F_54 ( V_3 , V_53 ) ;
break;
case V_108 :
break;
case V_109 :
F_65 ( V_3 , F_63 ( * V_92 , V_110 ) ) ;
break;
case V_111 :
case V_112 :
case V_113 :
F_66 ( V_3 , V_92 ) ;
break;
default:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_12 ,
V_93 ) ;
}
}
void F_67 ( struct V_2 * V_3 , char * V_114 , T_2 V_115 )
{
T_1 V_36 [ F_68 ( V_116 , 4 ) ] ;
T_2 V_117 ;
const T_8 * V_118 ;
int V_41 ;
F_69 ( V_119 != 0 ) ;
V_41 = F_43 ( V_3 , V_120 , NULL , 0 ,
V_36 , sizeof( V_36 ) , & V_117 ) ;
if ( V_41 )
goto V_121;
if ( V_117 < V_116 ) {
V_41 = - V_53 ;
goto V_121;
}
V_118 = ( T_8 * ) F_70 ( V_36 , V_122 ) ;
snprintf ( V_114 , V_115 , L_13 ,
F_71 ( V_118 [ 0 ] ) , F_71 ( V_118 [ 1 ] ) ,
F_71 ( V_118 [ 2 ] ) , F_71 ( V_118 [ 3 ] ) ) ;
return;
V_121:
F_27 ( V_3 , V_123 , V_3 -> V_52 , L_14 , V_124 , V_41 ) ;
V_114 [ 0 ] = 0 ;
}
int F_72 ( struct V_2 * V_3 , bool V_125 ,
bool * V_126 )
{
T_1 V_15 [ V_127 ] ;
T_1 V_36 [ V_128 ] ;
T_2 V_37 ;
int V_41 ;
F_73 ( V_15 , V_129 ,
V_125 ? 1 : 0 ) ;
F_73 ( V_15 , V_130 , 1 ) ;
V_41 = F_43 ( V_3 , V_131 , V_15 , sizeof( V_15 ) ,
V_36 , sizeof( V_36 ) , & V_37 ) ;
if ( V_41 )
goto V_121;
if ( V_37 < V_128 ) {
V_41 = - V_53 ;
goto V_121;
}
if ( V_126 != NULL )
* V_126 = F_74 ( V_36 , V_132 ) ;
return 0 ;
V_121:
F_27 ( V_3 , V_123 , V_3 -> V_52 , L_14 , V_124 , V_41 ) ;
return V_41 ;
}
int F_75 ( struct V_2 * V_3 , T_1 * V_133 ,
T_9 * V_134 , T_4 * V_135 )
{
T_10 V_36 [ V_136 ] ;
T_2 V_37 , V_137 , V_20 ;
int V_138 = F_76 ( V_3 ) ;
int V_41 ;
F_69 ( V_139 != 0 ) ;
V_41 = F_43 ( V_3 , V_140 , NULL , 0 ,
V_36 , sizeof( V_36 ) , & V_37 ) ;
if ( V_41 )
goto V_121;
if ( V_37 < V_136 ) {
V_41 = - V_53 ;
goto V_121;
}
V_137 = ( V_138 )
? V_141
: V_142 ;
if ( V_133 )
memcpy ( V_133 , V_36 + V_137 , V_143 ) ;
if ( V_134 ) {
V_137 = V_144 ;
for ( V_20 = 0 ;
V_20 < V_145 ;
V_20 ++ ) {
V_134 [ V_20 ] =
( V_137 + 2 <= V_37 ) ?
F_77 ( ( T_8 * ) ( V_36 + V_137 ) ) : 0 ;
V_137 += 2 ;
}
}
if ( V_135 ) {
if ( V_138 )
* V_135 = F_74 ( V_36 ,
V_146 ) ;
else
* V_135 = F_74 ( V_36 ,
V_147 ) ;
}
return 0 ;
V_121:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_15 ,
V_124 , V_41 , ( int ) V_37 ) ;
return V_41 ;
}
int F_78 ( struct V_2 * V_3 , bool V_148 , bool V_149 , T_4 V_150 )
{
T_1 V_15 [ V_151 ] ;
T_4 V_152 = 0 ;
int V_41 ;
if ( V_149 )
V_152 |= V_153 ;
if ( V_148 )
V_152 |= V_154 ;
F_73 ( V_15 , V_155 , V_152 ) ;
F_73 ( V_15 , V_156 , V_150 ) ;
F_69 ( V_157 != 0 ) ;
V_41 = F_43 ( V_3 , V_158 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_41 )
goto V_121;
return 0 ;
V_121:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_124 , V_41 ) ;
return V_41 ;
}
int F_79 ( struct V_2 * V_3 , T_4 * V_159 )
{
T_1 V_36 [ V_160 ] ;
T_2 V_37 ;
int V_41 ;
F_69 ( V_161 != 0 ) ;
V_41 = F_43 ( V_3 , V_162 , NULL , 0 ,
V_36 , sizeof( V_36 ) , & V_37 ) ;
if ( V_41 )
goto V_121;
if ( V_37 < V_160 ) {
V_41 = - V_53 ;
goto V_121;
}
* V_159 = F_74 ( V_36 , V_163 ) ;
return 0 ;
V_121:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 ,
V_124 , V_41 ) ;
return V_41 ;
}
int F_80 ( struct V_2 * V_3 , unsigned int type ,
T_2 * V_164 , T_2 * V_165 ,
bool * V_166 )
{
T_1 V_15 [ V_167 ] ;
T_1 V_36 [ V_168 ] ;
T_2 V_37 ;
int V_41 ;
F_73 ( V_15 , V_169 , type ) ;
V_41 = F_43 ( V_3 , V_170 , V_15 , sizeof( V_15 ) ,
V_36 , sizeof( V_36 ) , & V_37 ) ;
if ( V_41 )
goto V_121;
if ( V_37 < V_168 ) {
V_41 = - V_53 ;
goto V_121;
}
* V_164 = F_74 ( V_36 , V_171 ) ;
* V_165 = F_74 ( V_36 , V_172 ) ;
* V_166 = ! ! ( F_74 ( V_36 , V_173 ) &
( 1 << V_174 ) ) ;
return 0 ;
V_121:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_124 , V_41 ) ;
return V_41 ;
}
int F_81 ( struct V_2 * V_3 , unsigned int type )
{
T_1 V_15 [ V_175 ] ;
int V_41 ;
F_73 ( V_15 , V_176 , type ) ;
F_69 ( V_177 != 0 ) ;
V_41 = F_43 ( V_3 , V_178 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_41 )
goto V_121;
return 0 ;
V_121:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_124 , V_41 ) ;
return V_41 ;
}
int F_82 ( struct V_2 * V_3 , unsigned int type ,
T_11 V_137 , T_1 * V_179 , T_2 V_180 )
{
T_1 V_15 [ V_181 ] ;
T_1 V_36 [ F_83 ( V_182 ) ] ;
T_2 V_37 ;
int V_41 ;
F_73 ( V_15 , V_183 , type ) ;
F_73 ( V_15 , V_184 , V_137 ) ;
F_73 ( V_15 , V_185 , V_180 ) ;
V_41 = F_43 ( V_3 , V_186 , V_15 , sizeof( V_15 ) ,
V_36 , sizeof( V_36 ) , & V_37 ) ;
if ( V_41 )
goto V_121;
memcpy ( V_179 , F_70 ( V_36 , V_187 ) , V_180 ) ;
return 0 ;
V_121:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_124 , V_41 ) ;
return V_41 ;
}
int F_84 ( struct V_2 * V_3 , unsigned int type ,
T_11 V_137 , const T_1 * V_179 , T_2 V_180 )
{
T_1 V_15 [ F_85 ( V_182 ) ] ;
int V_41 ;
F_73 ( V_15 , V_188 , type ) ;
F_73 ( V_15 , V_189 , V_137 ) ;
F_73 ( V_15 , V_190 , V_180 ) ;
memcpy ( F_70 ( V_15 , V_191 ) , V_179 , V_180 ) ;
F_69 ( V_192 != 0 ) ;
V_41 = F_43 ( V_3 , V_193 , V_15 ,
F_68 ( F_85 ( V_180 ) , 4 ) ,
NULL , 0 , NULL ) ;
if ( V_41 )
goto V_121;
return 0 ;
V_121:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_124 , V_41 ) ;
return V_41 ;
}
int F_86 ( struct V_2 * V_3 , unsigned int type ,
T_11 V_137 , T_2 V_180 )
{
T_1 V_15 [ V_194 ] ;
int V_41 ;
F_73 ( V_15 , V_195 , type ) ;
F_73 ( V_15 , V_196 , V_137 ) ;
F_73 ( V_15 , V_197 , V_180 ) ;
F_69 ( V_198 != 0 ) ;
V_41 = F_43 ( V_3 , V_199 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_41 )
goto V_121;
return 0 ;
V_121:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_124 , V_41 ) ;
return V_41 ;
}
int F_87 ( struct V_2 * V_3 , unsigned int type )
{
T_1 V_15 [ V_200 ] ;
int V_41 ;
F_73 ( V_15 , V_201 , type ) ;
F_69 ( V_202 != 0 ) ;
V_41 = F_43 ( V_3 , V_203 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_41 )
goto V_121;
return 0 ;
V_121:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_124 , V_41 ) ;
return V_41 ;
}
static int F_88 ( struct V_2 * V_3 , unsigned int type )
{
T_1 V_15 [ V_204 ] ;
T_1 V_36 [ V_205 ] ;
int V_41 ;
F_73 ( V_15 , V_206 , type ) ;
V_41 = F_43 ( V_3 , V_207 , V_15 , sizeof( V_15 ) ,
V_36 , sizeof( V_36 ) , NULL ) ;
if ( V_41 )
return V_41 ;
switch ( F_74 ( V_36 , V_208 ) ) {
case V_209 :
case V_210 :
return 0 ;
default:
return - V_53 ;
}
}
int F_89 ( struct V_2 * V_3 )
{
T_4 V_211 ;
unsigned int type ;
int V_41 ;
V_41 = F_79 ( V_3 , & V_211 ) ;
if ( V_41 )
goto V_212;
type = 0 ;
while ( V_211 != 0 ) {
if ( V_211 & 1 ) {
V_41 = F_88 ( V_3 , type ) ;
if ( V_41 )
goto V_213;
}
type ++ ;
V_211 >>= 1 ;
}
return 0 ;
V_213:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_16 ,
V_124 , type ) ;
V_212:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_124 , V_41 ) ;
return V_41 ;
}
static int F_90 ( struct V_2 * V_3 )
{
T_1 V_15 [ V_214 ] ;
T_1 V_36 [ V_215 ] ;
unsigned int V_80 , V_216 , V_217 ;
const char * V_218 ;
T_2 V_37 ;
int V_219 ;
int V_41 ;
V_219 = 2 ;
do {
F_73 ( V_15 , V_220 , 1 ) ;
V_41 = F_43 ( V_3 , V_221 ,
V_15 , V_214 ,
V_36 , sizeof( V_36 ) , & V_37 ) ;
} while ( ( V_41 == - V_55 || V_41 == - V_53 ) && V_219 -- > 0 );
if ( V_41 )
return V_41 ;
if ( V_37 < V_215 )
return - V_53 ;
V_80 = F_74 ( V_36 , V_222 ) ;
if ( V_80 == V_223 )
return 0 ;
V_218 = ( V_80 == V_224 )
? L_17
: ( V_80 == V_225 )
? L_18
: ( V_80 == V_226 )
? L_19
: L_20 ;
F_27 ( V_3 , V_51 , V_3 -> V_52 ,
L_21 , V_218 ,
F_74 ( V_36 , V_227 ) ,
F_74 ( V_36 , V_228 ) ) ;
V_217 = V_229 ;
for ( V_216 = 1 ; V_216 < 32 ; V_216 ++ ) {
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_22 , V_216 ,
F_91 ( V_36 , V_217 ) ) ;
V_217 += sizeof( T_3 ) ;
}
return 0 ;
}
static void F_92 ( struct V_2 * V_3 )
{
T_1 V_15 [ V_230 ] ;
F_69 ( V_231 != 0 ) ;
F_73 ( V_15 , V_232 ,
V_233 ) ;
( void ) F_43 ( V_3 , V_73 , V_15 , V_230 ,
NULL , 0 , NULL ) ;
}
int F_93 ( struct V_2 * V_3 )
{
int V_41 ;
V_41 = F_90 ( V_3 ) ;
if ( V_41 )
return V_41 ;
F_92 ( V_3 ) ;
return 0 ;
}
void F_94 ( struct V_2 * V_3 , enum V_234 V_12 )
{
T_1 V_15 [ V_235 ] ;
int V_41 ;
F_69 ( V_236 != V_237 ) ;
F_69 ( V_238 != V_239 ) ;
F_69 ( V_240 != V_241 ) ;
F_69 ( V_242 != 0 ) ;
F_73 ( V_15 , V_243 , V_12 ) ;
V_41 = F_43 ( V_3 , V_244 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_41 )
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 ,
V_124 , V_41 ) ;
}
int F_95 ( struct V_2 * V_3 )
{
int V_41 = F_43 ( V_3 , V_245 , NULL , 0 , NULL , 0 , NULL ) ;
if ( V_41 )
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 ,
V_124 , V_41 ) ;
return V_41 ;
}
int F_96 ( struct V_2 * V_3 )
{
T_1 V_15 [ V_230 ] ;
int V_41 ;
F_69 ( V_231 != 0 ) ;
F_73 ( V_15 , V_232 , 0 ) ;
V_41 = F_43 ( V_3 , V_73 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_41 == - V_53 )
return 0 ;
if ( V_41 == 0 )
V_41 = - V_53 ;
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_124 , V_41 ) ;
return V_41 ;
}
static int F_97 ( struct V_2 * V_3 , T_4 type ,
const T_1 * V_246 , int * V_247 )
{
T_1 V_15 [ V_248 ] ;
T_1 V_36 [ V_249 ] ;
T_2 V_37 ;
int V_41 ;
F_73 ( V_15 , V_250 , type ) ;
F_73 ( V_15 , V_251 ,
V_252 ) ;
memcpy ( F_70 ( V_15 , V_253 ) , V_246 , V_143 ) ;
V_41 = F_43 ( V_3 , V_254 , V_15 , sizeof( V_15 ) ,
V_36 , sizeof( V_36 ) , & V_37 ) ;
if ( V_41 )
goto V_121;
if ( V_37 < V_249 ) {
V_41 = - V_53 ;
goto V_121;
}
* V_247 = ( int ) F_74 ( V_36 , V_255 ) ;
return 0 ;
V_121:
* V_247 = - 1 ;
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_124 , V_41 ) ;
return V_41 ;
}
int
F_98 ( struct V_2 * V_3 , const T_1 * V_246 , int * V_247 )
{
return F_97 ( V_3 , V_256 , V_246 , V_247 ) ;
}
int F_99 ( struct V_2 * V_3 , int * V_247 )
{
T_1 V_36 [ V_257 ] ;
T_2 V_37 ;
int V_41 ;
V_41 = F_43 ( V_3 , V_258 , NULL , 0 ,
V_36 , sizeof( V_36 ) , & V_37 ) ;
if ( V_41 )
goto V_121;
if ( V_37 < V_257 ) {
V_41 = - V_53 ;
goto V_121;
}
* V_247 = ( int ) F_74 ( V_36 , V_259 ) ;
return 0 ;
V_121:
* V_247 = - 1 ;
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_124 , V_41 ) ;
return V_41 ;
}
int F_100 ( struct V_2 * V_3 , int V_260 )
{
T_1 V_15 [ V_261 ] ;
int V_41 ;
F_73 ( V_15 , V_262 , ( T_4 ) V_260 ) ;
V_41 = F_43 ( V_3 , V_263 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_41 )
goto V_121;
return 0 ;
V_121:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_124 , V_41 ) ;
return V_41 ;
}
int F_101 ( struct V_2 * V_3 )
{
struct V_90 * V_91 ;
struct V_264 * V_265 ;
V_34 * V_266 ;
int V_41 , V_76 ;
F_69 ( V_267 >
V_268 ) ;
V_266 = F_102 ( V_267 * sizeof( * V_266 ) , V_269 ) ;
if ( V_266 == NULL )
return - V_270 ;
V_76 = 0 ;
F_103 (channel, efx) {
F_104 (rx_queue, channel) {
if ( V_265 -> V_271 ) {
V_265 -> V_271 = false ;
F_105 ( & V_3 -> V_272 ) ;
V_266 [ V_76 ++ ] = F_106 (
F_107 ( V_265 ) ) ;
}
}
}
V_41 = F_43 ( V_3 , V_273 , ( T_1 * ) V_266 ,
V_76 * sizeof( * V_266 ) , NULL , 0 , NULL ) ;
F_108 ( V_41 > 0 ) ;
F_109 ( V_266 ) ;
return V_41 ;
}
int F_110 ( struct V_2 * V_3 )
{
int V_41 ;
V_41 = F_43 ( V_3 , V_274 , NULL , 0 , NULL , 0 , NULL ) ;
if ( V_41 )
goto V_121;
return 0 ;
V_121:
F_27 ( V_3 , V_51 , V_3 -> V_52 , L_14 , V_124 , V_41 ) ;
return V_41 ;
}
