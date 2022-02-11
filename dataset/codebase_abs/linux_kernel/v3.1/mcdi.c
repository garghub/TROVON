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
F_12 ( V_16 & 3 || V_16 >= 0x100 ) ;
V_23 = V_7 -> V_23 & V_24 ;
V_22 = 0 ;
if ( V_7 -> V_12 == V_25 )
V_22 |= V_26 ;
F_14 ( V_21 ,
V_27 , 0 ,
V_28 , 1 ,
V_29 , V_14 ,
V_30 , V_16 ,
V_31 , V_23 ,
V_32 , V_22 ) ;
F_15 ( V_3 , & V_21 , V_17 ) ;
for ( V_20 = 0 ; V_20 < V_16 ; V_20 += 4 )
F_16 ( V_3 , * ( ( V_33 * ) ( V_15 + V_20 ) ) , V_17 + 4 + V_20 ) ;
F_17 () ;
F_16 ( V_3 , ( V_34 V_33 ) 0x45789abc , V_19 ) ;
}
static void F_18 ( struct V_2 * V_3 , T_1 * V_35 , T_2 V_36 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_17 = V_18 + F_10 ( V_3 ) ;
int V_20 ;
F_12 ( F_13 ( & V_7 -> V_10 ) == V_11 ) ;
F_12 ( V_36 & 3 || V_36 >= 0x100 ) ;
for ( V_20 = 0 ; V_20 < V_36 ; V_20 += 4 )
* ( ( V_33 * ) ( V_35 + V_20 ) ) = F_19 ( V_3 , V_17 + 4 + V_20 ) ;
}
static int F_20 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int time , V_37 ;
unsigned int V_38 , V_39 , error ;
unsigned int V_17 = V_18 + F_10 ( V_3 ) ;
unsigned int V_40 , V_41 ;
T_3 V_42 ;
V_40 = - F_8 ( V_3 ) ;
if ( V_40 )
goto V_43;
V_41 = V_44 ;
V_37 = F_21 () + V_45 ;
while ( 1 ) {
if ( V_41 != 0 ) {
-- V_41 ;
F_22 ( 1 ) ;
} else {
F_23 ( 1 ) ;
}
time = F_21 () ;
F_24 () ;
F_25 ( V_3 , & V_42 , V_17 ) ;
if ( F_26 ( V_42 , V_46 ) != 0xffffffff &&
F_26 ( V_42 , V_27 ) )
break;
if ( time >= V_37 )
return - V_47 ;
}
V_7 -> V_48 = F_26 ( V_42 , V_30 ) ;
V_38 = F_26 ( V_42 , V_31 ) ;
V_39 = F_26 ( V_42 , V_29 ) ;
error = F_26 ( V_42 , V_49 ) ;
if ( error && V_7 -> V_48 == 0 ) {
F_27 ( V_3 , V_50 , V_3 -> V_51 , L_1 ) ;
V_40 = V_52 ;
} else if ( ( V_38 ^ V_7 -> V_23 ) & V_24 ) {
F_27 ( V_3 , V_50 , V_3 -> V_51 ,
L_2 ,
V_38 , V_7 -> V_23 ) ;
V_40 = V_52 ;
} else if ( error ) {
F_25 ( V_3 , & V_42 , V_17 + 4 ) ;
switch ( F_26 ( V_42 , V_46 ) ) {
#define F_28 ( T_5 ) \
case MC_CMD_ERR_ ## name: \
rc = name; \
break
F_28 ( V_53 ) ;
F_28 ( V_54 ) ;
F_28 ( V_55 ) ;
F_28 ( V_56 ) ;
F_28 ( V_57 ) ;
F_28 ( V_58 ) ;
F_28 ( V_59 ) ;
F_28 ( V_60 ) ;
#undef F_28
default:
V_40 = V_52 ;
break;
}
} else
V_40 = 0 ;
V_43:
V_7 -> V_61 = V_40 ;
if ( V_40 )
V_7 -> V_48 = 0 ;
return 0 ;
}
int F_8 ( struct V_2 * V_3 )
{
unsigned int V_62 = V_18 + F_29 ( V_3 ) ;
T_3 V_42 ;
T_6 V_63 ;
if ( F_3 ( V_3 ) < V_6 )
return false ;
F_25 ( V_3 , & V_42 , V_62 ) ;
V_63 = F_26 ( V_42 , V_46 ) ;
if ( V_63 == 0 )
return 0 ;
F_30 ( V_42 ) ;
F_15 ( V_3 , & V_42 , V_62 ) ;
if ( V_63 == V_64 )
return - V_54 ;
else
return - V_52 ;
}
static void F_31 ( struct V_1 * V_7 )
{
F_32 ( V_7 -> V_8 ,
F_33 ( & V_7 -> V_10 ,
V_11 ,
V_65 )
== V_11 ) ;
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( F_35 (
V_7 -> V_8 ,
F_13 ( & V_7 -> V_10 ) == V_66 ,
F_36 ( V_45 * 1000 ) ) == 0 )
return - V_47 ;
if ( V_7 -> V_12 == V_13 )
return F_20 ( V_3 ) ;
return 0 ;
}
static bool F_37 ( struct V_1 * V_7 )
{
if ( F_33 ( & V_7 -> V_10 ,
V_65 ,
V_66 ) == V_65 ) {
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
unsigned int V_67 , unsigned int V_68 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
bool V_69 = false ;
F_41 ( & V_7 -> V_9 ) ;
if ( ( V_23 ^ V_7 -> V_23 ) & V_24 ) {
if ( V_7 -> V_70 )
-- V_7 -> V_70 ;
else
F_27 ( V_3 , V_50 , V_3 -> V_51 ,
L_3
L_4 , V_23 , V_7 -> V_23 ) ;
} else {
V_7 -> V_61 = V_68 ;
V_7 -> V_48 = V_67 ;
V_69 = true ;
}
F_42 ( & V_7 -> V_9 ) ;
if ( V_69 )
F_37 ( V_7 ) ;
}
int F_43 ( struct V_2 * V_3 , unsigned V_14 ,
const T_1 * V_15 , T_2 V_16 , T_1 * V_35 , T_2 V_36 ,
T_2 * V_71 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_40 ;
F_12 ( F_3 ( V_3 ) < V_6 ) ;
F_31 ( V_7 ) ;
F_44 ( & V_7 -> V_9 ) ;
++ V_7 -> V_23 ;
F_45 ( & V_7 -> V_9 ) ;
F_9 ( V_3 , V_14 , V_15 , V_16 ) ;
if ( V_7 -> V_12 == V_13 )
V_40 = F_20 ( V_3 ) ;
else
V_40 = F_34 ( V_3 ) ;
if ( V_40 != 0 ) {
F_44 ( & V_7 -> V_9 ) ;
++ V_7 -> V_23 ;
++ V_7 -> V_70 ;
F_45 ( & V_7 -> V_9 ) ;
F_27 ( V_3 , V_50 , V_3 -> V_51 ,
L_5 ,
V_14 , ( int ) V_16 , V_7 -> V_12 ) ;
} else {
T_2 V_48 ;
F_44 ( & V_7 -> V_9 ) ;
V_40 = - V_7 -> V_61 ;
V_48 = V_7 -> V_48 ;
F_45 ( & V_7 -> V_9 ) ;
if ( V_40 == 0 ) {
F_18 ( V_3 , V_35 ,
F_46 ( V_36 , V_7 -> V_48 + 3 ) & ~ 0x3 ) ;
if ( V_71 != NULL )
* V_71 = V_48 ;
} else if ( V_14 == V_72 && V_40 == - V_52 )
;
else if ( V_40 == - V_52 || V_40 == - V_54 ) {
F_27 ( V_3 , V_50 , V_3 -> V_51 , L_6 ,
- V_40 ) ;
F_47 ( V_3 , V_73 ) ;
} else
F_48 ( V_3 , V_50 , V_3 -> V_51 ,
L_7 ,
V_14 , ( int ) V_16 , - V_40 ) ;
}
F_39 ( V_7 ) ;
return V_40 ;
}
void F_49 ( struct V_2 * V_3 )
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
void F_50 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
if ( F_3 ( V_3 ) < V_6 )
return;
V_7 = F_1 ( V_3 ) ;
if ( V_7 -> V_12 == V_25 )
return;
F_31 ( V_7 ) ;
V_7 -> V_12 = V_25 ;
F_39 ( V_7 ) ;
}
static void F_51 ( struct V_2 * V_3 , int V_40 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_41 ( & V_7 -> V_9 ) ;
if ( F_37 ( V_7 ) ) {
if ( V_7 -> V_12 == V_25 ) {
V_7 -> V_61 = V_40 ;
V_7 -> V_48 = 0 ;
++ V_7 -> V_70 ;
}
} else
F_47 ( V_3 , V_73 ) ;
F_42 ( & V_7 -> V_9 ) ;
}
static void F_52 ( struct V_2 * V_3 , T_7 * V_74 )
{
T_4 V_75 , V_76 , V_77 , V_78 ;
V_77 = F_53 ( * V_74 , V_79 ) ;
F_2 ( V_77 >= F_54 ( V_80 ) ) ;
V_77 = V_80 [ V_77 ] ;
V_75 = F_53 ( * V_74 , V_81 ) ;
V_76 = F_53 ( * V_74 , V_82 ) ;
V_78 = F_53 ( * V_74 , V_83 ) ;
F_55 ( V_3 , & V_3 -> V_84 , V_77 , V_75 , V_76 ) ;
F_56 ( V_3 , V_78 ) ;
F_57 ( V_3 ) ;
}
static void F_58 ( struct V_2 * V_3 , T_7 * V_74 )
{
unsigned int V_85 , V_10 , V_63 ;
const char * T_5 , * V_86 ;
V_85 = F_53 ( * V_74 , V_87 ) ;
V_10 = F_53 ( * V_74 , V_88 ) ;
V_63 = F_53 ( * V_74 , V_89 ) ;
T_5 = ( V_85 >= F_54 ( V_90 ) )
? L_8 :
V_90 [ V_85 ] ;
F_2 ( V_10 >= F_54 ( V_91 ) ) ;
V_86 = V_91 [ V_10 ] ;
F_27 ( V_3 , V_50 , V_3 -> V_51 ,
L_9 ,
V_85 , T_5 , V_86 , V_63 ) ;
}
void F_59 ( struct V_92 * V_93 ,
T_7 * V_94 )
{
struct V_2 * V_3 = V_93 -> V_3 ;
int V_95 = F_53 ( * V_94 , V_96 ) ;
T_4 V_97 = F_53 ( * V_94 , V_98 ) ;
switch ( V_95 ) {
case V_99 :
F_27 ( V_3 , V_50 , V_3 -> V_51 ,
L_10 , V_97 ) ;
F_51 ( V_3 , V_54 ) ;
break;
case V_100 :
F_60 ( V_3 , V_101 , V_3 -> V_51 , L_11 ) ;
break;
case V_102 :
F_40 ( V_3 ,
F_61 ( * V_94 , V_103 ) ,
F_61 ( * V_94 , V_104 ) ,
F_61 ( * V_94 , V_105 ) ) ;
break;
case V_106 :
F_52 ( V_3 , V_94 ) ;
break;
case V_107 :
F_58 ( V_3 , V_94 ) ;
break;
case V_108 :
F_60 ( V_3 , V_50 , V_3 -> V_51 ,
L_12 , V_97 ) ;
break;
case V_109 :
F_60 ( V_3 , V_50 , V_3 -> V_51 , L_13 ) ;
F_51 ( V_3 , V_52 ) ;
break;
case V_110 :
break;
default:
F_27 ( V_3 , V_50 , V_3 -> V_51 , L_14 ,
V_95 ) ;
}
}
void F_62 ( struct V_2 * V_3 , char * V_111 , T_2 V_112 )
{
T_1 V_35 [ F_63 ( V_113 , 4 ) ] ;
T_2 V_114 ;
const T_8 * V_115 ;
int V_40 ;
F_64 ( V_116 != 0 ) ;
V_40 = F_43 ( V_3 , V_117 , NULL , 0 ,
V_35 , sizeof( V_35 ) , & V_114 ) ;
if ( V_40 )
goto V_118;
if ( V_114 < V_113 ) {
V_40 = - V_52 ;
goto V_118;
}
V_115 = ( T_8 * ) F_65 ( V_35 , V_119 ) ;
snprintf ( V_111 , V_112 , L_15 ,
F_66 ( V_115 [ 0 ] ) , F_66 ( V_115 [ 1 ] ) ,
F_66 ( V_115 [ 2 ] ) , F_66 ( V_115 [ 3 ] ) ) ;
return;
V_118:
F_27 ( V_3 , V_120 , V_3 -> V_51 , L_16 , V_121 , V_40 ) ;
V_111 [ 0 ] = 0 ;
}
int F_67 ( struct V_2 * V_3 , bool V_122 ,
bool * V_123 )
{
T_1 V_15 [ V_124 ] ;
T_1 V_35 [ V_125 ] ;
T_2 V_36 ;
int V_40 ;
F_68 ( V_15 , V_126 ,
V_122 ? 1 : 0 ) ;
F_68 ( V_15 , V_127 , 1 ) ;
V_40 = F_43 ( V_3 , V_128 , V_15 , sizeof( V_15 ) ,
V_35 , sizeof( V_35 ) , & V_36 ) ;
if ( V_40 )
goto V_118;
if ( V_36 < V_125 ) {
V_40 = - V_52 ;
goto V_118;
}
if ( V_123 != NULL )
* V_123 = F_69 ( V_35 , V_129 ) ;
return 0 ;
V_118:
F_27 ( V_3 , V_120 , V_3 -> V_51 , L_16 , V_121 , V_40 ) ;
return V_40 ;
}
int F_70 ( struct V_2 * V_3 , T_1 * V_130 ,
T_9 * V_131 )
{
T_10 V_35 [ V_132 ] ;
T_2 V_36 ;
int V_133 = F_71 ( V_3 ) ;
int V_134 ;
int V_40 ;
F_64 ( V_135 != 0 ) ;
V_40 = F_43 ( V_3 , V_136 , NULL , 0 ,
V_35 , sizeof( V_35 ) , & V_36 ) ;
if ( V_40 )
goto V_118;
if ( V_36 < V_132 ) {
V_40 = - V_52 ;
goto V_118;
}
V_134 = ( V_133 )
? V_137
: V_138 ;
if ( V_130 )
memcpy ( V_130 , V_35 + V_134 , V_139 ) ;
if ( V_131 )
memcpy ( V_131 ,
V_35 + V_140 ,
V_141 ) ;
return 0 ;
V_118:
F_27 ( V_3 , V_50 , V_3 -> V_51 , L_17 ,
V_121 , V_40 , ( int ) V_36 ) ;
return V_40 ;
}
int F_72 ( struct V_2 * V_3 , bool V_142 , bool V_143 , T_4 V_144 )
{
T_1 V_15 [ V_145 ] ;
T_4 V_146 = 0 ;
int V_40 ;
if ( V_143 )
V_146 |= V_147 ;
if ( V_142 )
V_146 |= V_148 ;
F_68 ( V_15 , V_149 , V_146 ) ;
F_68 ( V_15 , V_150 , V_144 ) ;
F_64 ( V_151 != 0 ) ;
V_40 = F_43 ( V_3 , V_152 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_40 )
goto V_118;
return 0 ;
V_118:
F_27 ( V_3 , V_50 , V_3 -> V_51 , L_16 , V_121 , V_40 ) ;
return V_40 ;
}
int F_73 ( struct V_2 * V_3 , T_4 * V_153 )
{
T_1 V_35 [ V_154 ] ;
T_2 V_36 ;
int V_40 ;
F_64 ( V_155 != 0 ) ;
V_40 = F_43 ( V_3 , V_156 , NULL , 0 ,
V_35 , sizeof( V_35 ) , & V_36 ) ;
if ( V_40 )
goto V_118;
if ( V_36 < V_154 ) {
V_40 = - V_52 ;
goto V_118;
}
* V_153 = F_69 ( V_35 , V_157 ) ;
return 0 ;
V_118:
F_27 ( V_3 , V_50 , V_3 -> V_51 , L_16 ,
V_121 , V_40 ) ;
return V_40 ;
}
int F_74 ( struct V_2 * V_3 , unsigned int type ,
T_2 * V_158 , T_2 * V_159 ,
bool * V_160 )
{
T_1 V_15 [ V_161 ] ;
T_1 V_35 [ V_162 ] ;
T_2 V_36 ;
int V_40 ;
F_68 ( V_15 , V_163 , type ) ;
V_40 = F_43 ( V_3 , V_164 , V_15 , sizeof( V_15 ) ,
V_35 , sizeof( V_35 ) , & V_36 ) ;
if ( V_40 )
goto V_118;
if ( V_36 < V_162 ) {
V_40 = - V_52 ;
goto V_118;
}
* V_158 = F_69 ( V_35 , V_165 ) ;
* V_159 = F_69 ( V_35 , V_166 ) ;
* V_160 = ! ! ( F_69 ( V_35 , V_167 ) &
( 1 << V_168 ) ) ;
return 0 ;
V_118:
F_27 ( V_3 , V_50 , V_3 -> V_51 , L_16 , V_121 , V_40 ) ;
return V_40 ;
}
int F_75 ( struct V_2 * V_3 , unsigned int type )
{
T_1 V_15 [ V_169 ] ;
int V_40 ;
F_68 ( V_15 , V_170 , type ) ;
F_64 ( V_171 != 0 ) ;
V_40 = F_43 ( V_3 , V_172 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_40 )
goto V_118;
return 0 ;
V_118:
F_27 ( V_3 , V_50 , V_3 -> V_51 , L_16 , V_121 , V_40 ) ;
return V_40 ;
}
int F_76 ( struct V_2 * V_3 , unsigned int type ,
T_11 V_134 , T_1 * V_173 , T_2 V_174 )
{
T_1 V_15 [ V_175 ] ;
T_1 V_35 [ F_77 ( V_176 ) ] ;
T_2 V_36 ;
int V_40 ;
F_68 ( V_15 , V_177 , type ) ;
F_68 ( V_15 , V_178 , V_134 ) ;
F_68 ( V_15 , V_179 , V_174 ) ;
V_40 = F_43 ( V_3 , V_180 , V_15 , sizeof( V_15 ) ,
V_35 , sizeof( V_35 ) , & V_36 ) ;
if ( V_40 )
goto V_118;
memcpy ( V_173 , F_65 ( V_35 , V_181 ) , V_174 ) ;
return 0 ;
V_118:
F_27 ( V_3 , V_50 , V_3 -> V_51 , L_16 , V_121 , V_40 ) ;
return V_40 ;
}
int F_78 ( struct V_2 * V_3 , unsigned int type ,
T_11 V_134 , const T_1 * V_173 , T_2 V_174 )
{
T_1 V_15 [ F_79 ( V_176 ) ] ;
int V_40 ;
F_68 ( V_15 , V_182 , type ) ;
F_68 ( V_15 , V_183 , V_134 ) ;
F_68 ( V_15 , V_184 , V_174 ) ;
memcpy ( F_65 ( V_15 , V_185 ) , V_173 , V_174 ) ;
F_64 ( V_186 != 0 ) ;
V_40 = F_43 ( V_3 , V_187 , V_15 ,
F_63 ( F_79 ( V_174 ) , 4 ) ,
NULL , 0 , NULL ) ;
if ( V_40 )
goto V_118;
return 0 ;
V_118:
F_27 ( V_3 , V_50 , V_3 -> V_51 , L_16 , V_121 , V_40 ) ;
return V_40 ;
}
int F_80 ( struct V_2 * V_3 , unsigned int type ,
T_11 V_134 , T_2 V_174 )
{
T_1 V_15 [ V_188 ] ;
int V_40 ;
F_68 ( V_15 , V_189 , type ) ;
F_68 ( V_15 , V_190 , V_134 ) ;
F_68 ( V_15 , V_191 , V_174 ) ;
F_64 ( V_192 != 0 ) ;
V_40 = F_43 ( V_3 , V_193 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_40 )
goto V_118;
return 0 ;
V_118:
F_27 ( V_3 , V_50 , V_3 -> V_51 , L_16 , V_121 , V_40 ) ;
return V_40 ;
}
int F_81 ( struct V_2 * V_3 , unsigned int type )
{
T_1 V_15 [ V_194 ] ;
int V_40 ;
F_68 ( V_15 , V_195 , type ) ;
F_64 ( V_196 != 0 ) ;
V_40 = F_43 ( V_3 , V_197 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_40 )
goto V_118;
return 0 ;
V_118:
F_27 ( V_3 , V_50 , V_3 -> V_51 , L_16 , V_121 , V_40 ) ;
return V_40 ;
}
static int F_82 ( struct V_2 * V_3 , unsigned int type )
{
T_1 V_15 [ V_198 ] ;
T_1 V_35 [ V_199 ] ;
int V_40 ;
F_68 ( V_15 , V_200 , type ) ;
V_40 = F_43 ( V_3 , V_201 , V_15 , sizeof( V_15 ) ,
V_35 , sizeof( V_35 ) , NULL ) ;
if ( V_40 )
return V_40 ;
switch ( F_69 ( V_35 , V_202 ) ) {
case V_203 :
case V_204 :
return 0 ;
default:
return - V_52 ;
}
}
int F_83 ( struct V_2 * V_3 )
{
T_4 V_205 ;
unsigned int type ;
int V_40 ;
V_40 = F_73 ( V_3 , & V_205 ) ;
if ( V_40 )
goto V_206;
type = 0 ;
while ( V_205 != 0 ) {
if ( V_205 & 1 ) {
V_40 = F_82 ( V_3 , type ) ;
if ( V_40 )
goto V_207;
}
type ++ ;
V_205 >>= 1 ;
}
return 0 ;
V_207:
F_27 ( V_3 , V_50 , V_3 -> V_51 , L_18 ,
V_121 , type ) ;
V_206:
F_27 ( V_3 , V_50 , V_3 -> V_51 , L_16 , V_121 , V_40 ) ;
return V_40 ;
}
static int F_84 ( struct V_2 * V_3 )
{
T_1 V_15 [ V_208 ] ;
T_1 V_35 [ V_209 ] ;
unsigned int V_75 , V_210 , V_211 ;
const char * V_212 ;
T_2 V_36 ;
int V_213 ;
int V_40 ;
V_213 = 2 ;
do {
F_68 ( V_15 , V_214 , 1 ) ;
V_40 = F_43 ( V_3 , V_215 ,
V_15 , V_208 ,
V_35 , sizeof( V_35 ) , & V_36 ) ;
} while ( ( V_40 == - V_54 || V_40 == - V_52 ) && V_213 -- > 0 );
if ( V_40 )
return V_40 ;
if ( V_36 < V_209 )
return - V_52 ;
V_75 = F_69 ( V_35 , V_216 ) ;
if ( V_75 == V_217 )
return 0 ;
V_212 = ( V_75 == V_218 )
? L_19
: ( V_75 == V_219 )
? L_20
: ( V_75 == V_220 )
? L_21
: L_22 ;
F_27 ( V_3 , V_50 , V_3 -> V_51 ,
L_23 , V_212 ,
F_69 ( V_35 , V_221 ) ,
F_69 ( V_35 , V_222 ) ) ;
V_211 = V_223 ;
for ( V_210 = 1 ; V_210 < 32 ; V_210 ++ ) {
F_27 ( V_3 , V_50 , V_3 -> V_51 , L_24 , V_210 ,
F_85 ( V_35 , V_211 ) ) ;
V_211 += sizeof( T_3 ) ;
}
return 0 ;
}
static void F_86 ( struct V_2 * V_3 )
{
T_1 V_15 [ V_224 ] ;
F_64 ( V_225 != 0 ) ;
F_68 ( V_15 , V_226 ,
V_227 ) ;
F_43 ( V_3 , V_72 , V_15 , V_224 ,
NULL , 0 , NULL ) ;
}
int F_87 ( struct V_2 * V_3 )
{
int V_40 ;
V_40 = F_84 ( V_3 ) ;
if ( V_40 )
return V_40 ;
F_86 ( V_3 ) ;
return 0 ;
}
void F_88 ( struct V_2 * V_3 , enum V_228 V_12 )
{
T_1 V_15 [ V_229 ] ;
int V_40 ;
F_64 ( V_230 != V_231 ) ;
F_64 ( V_232 != V_233 ) ;
F_64 ( V_234 != V_235 ) ;
F_64 ( V_236 != 0 ) ;
F_68 ( V_15 , V_237 , V_12 ) ;
V_40 = F_43 ( V_3 , V_238 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_40 )
F_27 ( V_3 , V_50 , V_3 -> V_51 , L_16 ,
V_121 , V_40 ) ;
}
int F_89 ( struct V_2 * V_3 )
{
int V_40 = F_43 ( V_3 , V_239 , NULL , 0 , NULL , 0 , NULL ) ;
if ( V_40 )
F_27 ( V_3 , V_50 , V_3 -> V_51 , L_16 ,
V_121 , V_40 ) ;
return V_40 ;
}
int F_90 ( struct V_2 * V_3 )
{
T_1 V_15 [ V_224 ] ;
int V_40 ;
F_64 ( V_225 != 0 ) ;
F_68 ( V_15 , V_226 , 0 ) ;
V_40 = F_43 ( V_3 , V_72 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_40 == - V_52 )
return 0 ;
if ( V_40 == 0 )
V_40 = - V_52 ;
F_27 ( V_3 , V_50 , V_3 -> V_51 , L_16 , V_121 , V_40 ) ;
return V_40 ;
}
static int F_91 ( struct V_2 * V_3 , T_4 type ,
const T_1 * V_240 , int * V_241 )
{
T_1 V_15 [ V_242 ] ;
T_1 V_35 [ V_243 ] ;
T_2 V_36 ;
int V_40 ;
F_68 ( V_15 , V_244 , type ) ;
F_68 ( V_15 , V_245 ,
V_246 ) ;
memcpy ( F_65 ( V_15 , V_247 ) , V_240 , V_139 ) ;
V_40 = F_43 ( V_3 , V_248 , V_15 , sizeof( V_15 ) ,
V_35 , sizeof( V_35 ) , & V_36 ) ;
if ( V_40 )
goto V_118;
if ( V_36 < V_243 ) {
V_40 = - V_52 ;
goto V_118;
}
* V_241 = ( int ) F_69 ( V_35 , V_249 ) ;
return 0 ;
V_118:
* V_241 = - 1 ;
F_27 ( V_3 , V_50 , V_3 -> V_51 , L_16 , V_121 , V_40 ) ;
return V_40 ;
}
int
F_92 ( struct V_2 * V_3 , const T_1 * V_240 , int * V_241 )
{
return F_91 ( V_3 , V_250 , V_240 , V_241 ) ;
}
int F_93 ( struct V_2 * V_3 , int * V_241 )
{
T_1 V_35 [ V_251 ] ;
T_2 V_36 ;
int V_40 ;
V_40 = F_43 ( V_3 , V_252 , NULL , 0 ,
V_35 , sizeof( V_35 ) , & V_36 ) ;
if ( V_40 )
goto V_118;
if ( V_36 < V_251 ) {
V_40 = - V_52 ;
goto V_118;
}
* V_241 = ( int ) F_69 ( V_35 , V_253 ) ;
return 0 ;
V_118:
* V_241 = - 1 ;
F_27 ( V_3 , V_50 , V_3 -> V_51 , L_16 , V_121 , V_40 ) ;
return V_40 ;
}
int F_94 ( struct V_2 * V_3 , int V_254 )
{
T_1 V_15 [ V_255 ] ;
int V_40 ;
F_68 ( V_15 , V_256 , ( T_4 ) V_254 ) ;
V_40 = F_43 ( V_3 , V_257 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_40 )
goto V_118;
return 0 ;
V_118:
F_27 ( V_3 , V_50 , V_3 -> V_51 , L_16 , V_121 , V_40 ) ;
return V_40 ;
}
int F_95 ( struct V_2 * V_3 )
{
int V_40 ;
V_40 = F_43 ( V_3 , V_258 , NULL , 0 , NULL , 0 , NULL ) ;
if ( V_40 )
goto V_118;
return 0 ;
V_118:
F_27 ( V_3 , V_50 , V_3 -> V_51 , L_16 , V_121 , V_40 ) ;
return V_40 ;
}
