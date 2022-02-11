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
unsigned long time , V_38 ;
unsigned int V_39 , V_40 , error ;
unsigned int V_17 = V_18 + F_10 ( V_3 ) ;
unsigned int V_41 , V_42 ;
T_3 V_43 ;
V_41 = - F_8 ( V_3 ) ;
if ( V_41 )
goto V_44;
V_42 = V_45 ;
V_38 = V_46 + V_47 ;
while ( 1 ) {
if ( V_42 != 0 ) {
-- V_42 ;
F_21 ( 1 ) ;
} else {
F_22 ( 1 ) ;
}
time = V_46 ;
F_23 () ;
F_24 ( V_3 , & V_43 , V_17 ) ;
if ( F_25 ( V_43 , V_48 ) != 0xffffffff &&
F_25 ( V_43 , V_28 ) )
break;
if ( F_26 ( time , V_38 ) )
return - V_49 ;
}
V_7 -> V_50 = F_25 ( V_43 , V_31 ) ;
V_39 = F_25 ( V_43 , V_32 ) ;
V_40 = F_25 ( V_43 , V_30 ) ;
error = F_25 ( V_43 , V_51 ) ;
if ( error && V_7 -> V_50 == 0 ) {
F_27 ( V_3 , V_52 , V_3 -> V_53 , L_1 ) ;
V_41 = V_54 ;
} else if ( ( V_39 ^ V_7 -> V_23 ) & V_25 ) {
F_27 ( V_3 , V_52 , V_3 -> V_53 ,
L_2 ,
V_39 , V_7 -> V_23 ) ;
V_41 = V_54 ;
} else if ( error ) {
F_24 ( V_3 , & V_43 , V_17 + 4 ) ;
switch ( F_25 ( V_43 , V_48 ) ) {
#define F_28 ( T_5 ) \
case MC_CMD_ERR_ ## name: \
rc = name; \
break
F_28 ( V_55 ) ;
F_28 ( V_56 ) ;
F_28 ( V_57 ) ;
F_28 ( V_58 ) ;
F_28 ( V_59 ) ;
F_28 ( V_60 ) ;
F_28 ( V_61 ) ;
F_28 ( V_62 ) ;
#undef F_28
default:
V_41 = V_54 ;
break;
}
} else
V_41 = 0 ;
V_44:
V_7 -> V_63 = V_41 ;
if ( V_41 )
V_7 -> V_50 = 0 ;
return 0 ;
}
int F_8 ( struct V_2 * V_3 )
{
unsigned int V_64 = V_18 + F_29 ( V_3 ) ;
T_3 V_43 ;
T_6 V_65 ;
if ( F_3 ( V_3 ) < V_6 )
return false ;
F_24 ( V_3 , & V_43 , V_64 ) ;
V_65 = F_25 ( V_43 , V_48 ) ;
if ( V_65 == 0 )
return 0 ;
memset ( & V_3 -> V_66 , 0 , sizeof( V_3 -> V_66 ) ) ;
F_30 ( V_43 ) ;
F_15 ( V_3 , & V_43 , V_64 ) ;
if ( V_65 == V_67 )
return - V_56 ;
else
return - V_54 ;
}
static void F_31 ( struct V_1 * V_7 )
{
F_32 ( V_7 -> V_8 ,
F_33 ( & V_7 -> V_10 ,
V_11 ,
V_68 )
== V_11 ) ;
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( F_35 (
V_7 -> V_8 ,
F_13 ( & V_7 -> V_10 ) == V_69 ,
V_47 ) == 0 )
return - V_49 ;
if ( V_7 -> V_12 == V_13 )
return F_20 ( V_3 ) ;
return 0 ;
}
static bool F_36 ( struct V_1 * V_7 )
{
if ( F_33 ( & V_7 -> V_10 ,
V_68 ,
V_69 ) == V_68 ) {
F_37 ( & V_7 -> V_8 ) ;
return true ;
}
return false ;
}
static void F_38 ( struct V_1 * V_7 )
{
F_7 ( & V_7 -> V_10 , V_11 ) ;
F_37 ( & V_7 -> V_8 ) ;
}
static void F_39 ( struct V_2 * V_3 , unsigned int V_23 ,
unsigned int V_70 , unsigned int V_71 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
bool V_72 = false ;
F_40 ( & V_7 -> V_9 ) ;
if ( ( V_23 ^ V_7 -> V_23 ) & V_25 ) {
if ( V_7 -> V_73 )
-- V_7 -> V_73 ;
else
F_27 ( V_3 , V_52 , V_3 -> V_53 ,
L_3
L_4 , V_23 , V_7 -> V_23 ) ;
} else {
V_7 -> V_63 = V_71 ;
V_7 -> V_50 = V_70 ;
V_72 = true ;
}
F_41 ( & V_7 -> V_9 ) ;
if ( V_72 )
F_36 ( V_7 ) ;
}
int F_42 ( struct V_2 * V_3 , unsigned V_14 ,
const T_1 * V_15 , T_2 V_16 , T_1 * V_36 , T_2 V_37 ,
T_2 * V_74 )
{
F_43 ( V_3 , V_14 , V_15 , V_16 ) ;
return F_44 ( V_3 , V_14 , V_16 ,
V_36 , V_37 , V_74 ) ;
}
void F_43 ( struct V_2 * V_3 , unsigned V_14 , const T_1 * V_15 ,
T_2 V_16 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_12 ( F_3 ( V_3 ) < V_6 ) ;
F_31 ( V_7 ) ;
F_45 ( & V_7 -> V_9 ) ;
++ V_7 -> V_23 ;
F_46 ( & V_7 -> V_9 ) ;
F_9 ( V_3 , V_14 , V_15 , V_16 ) ;
}
int F_44 ( struct V_2 * V_3 , unsigned V_14 , T_2 V_16 ,
T_1 * V_36 , T_2 V_37 , T_2 * V_74 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_41 ;
F_12 ( F_3 ( V_3 ) < V_6 ) ;
if ( V_7 -> V_12 == V_13 )
V_41 = F_20 ( V_3 ) ;
else
V_41 = F_34 ( V_3 ) ;
if ( V_41 != 0 ) {
F_45 ( & V_7 -> V_9 ) ;
++ V_7 -> V_23 ;
++ V_7 -> V_73 ;
F_46 ( & V_7 -> V_9 ) ;
F_27 ( V_3 , V_52 , V_3 -> V_53 ,
L_5 ,
V_14 , ( int ) V_16 , V_7 -> V_12 ) ;
} else {
T_2 V_50 ;
F_45 ( & V_7 -> V_9 ) ;
V_41 = - V_7 -> V_63 ;
V_50 = V_7 -> V_50 ;
F_46 ( & V_7 -> V_9 ) ;
if ( V_41 == 0 ) {
F_18 ( V_3 , V_36 ,
F_47 ( V_37 , V_7 -> V_50 + 3 ) & ~ 0x3 ) ;
if ( V_74 != NULL )
* V_74 = V_50 ;
} else if ( V_14 == V_75 && V_41 == - V_54 )
;
else if ( V_41 == - V_54 || V_41 == - V_56 ) {
F_27 ( V_3 , V_52 , V_3 -> V_53 , L_6 ,
- V_41 ) ;
F_48 ( V_3 , V_76 ) ;
} else
F_49 ( V_3 , V_52 , V_3 -> V_53 ,
L_7 ,
V_14 , ( int ) V_16 , - V_41 ) ;
if ( V_41 == - V_54 || V_41 == - V_56 ) {
F_50 ( V_77 ) ;
F_8 ( V_3 ) ;
}
}
F_38 ( V_7 ) ;
return V_41 ;
}
void F_51 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
if ( F_3 ( V_3 ) < V_6 )
return;
V_7 = F_1 ( V_3 ) ;
if ( V_7 -> V_12 == V_13 )
return;
V_7 -> V_12 = V_13 ;
F_36 ( V_7 ) ;
}
void F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
if ( F_3 ( V_3 ) < V_6 )
return;
V_7 = F_1 ( V_3 ) ;
if ( V_7 -> V_12 == V_26 )
return;
F_31 ( V_7 ) ;
V_7 -> V_12 = V_26 ;
F_38 ( V_7 ) ;
}
static void F_53 ( struct V_2 * V_3 , int V_41 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_40 ( & V_7 -> V_9 ) ;
if ( F_36 ( V_7 ) ) {
if ( V_7 -> V_12 == V_26 ) {
V_7 -> V_63 = V_41 ;
V_7 -> V_50 = 0 ;
++ V_7 -> V_73 ;
}
} else {
int V_78 ;
F_48 ( V_3 , V_76 ) ;
for ( V_78 = 0 ; V_78 < V_79 ; ++ V_78 ) {
if ( F_8 ( V_3 ) )
break;
F_21 ( V_80 ) ;
}
}
F_41 ( & V_7 -> V_9 ) ;
}
static void F_54 ( struct V_2 * V_3 , T_7 * V_81 )
{
T_4 V_82 , V_83 , V_84 , V_85 ;
V_84 = F_55 ( * V_81 , V_86 ) ;
F_2 ( V_84 >= F_56 ( V_87 ) ) ;
V_84 = V_87 [ V_84 ] ;
V_82 = F_55 ( * V_81 , V_88 ) ;
V_83 = F_55 ( * V_81 , V_89 ) ;
V_85 = F_55 ( * V_81 , V_90 ) ;
F_57 ( V_3 , & V_3 -> V_91 , V_84 , V_82 , V_83 ) ;
F_58 ( V_3 , V_85 ) ;
F_59 ( V_3 ) ;
}
void F_60 ( struct V_92 * V_93 ,
T_7 * V_94 )
{
struct V_2 * V_3 = V_93 -> V_3 ;
int V_95 = F_55 ( * V_94 , V_96 ) ;
T_4 V_97 = F_55 ( * V_94 , V_98 ) ;
switch ( V_95 ) {
case V_99 :
F_27 ( V_3 , V_52 , V_3 -> V_53 ,
L_8 , V_97 ) ;
F_53 ( V_3 , V_56 ) ;
break;
case V_100 :
F_61 ( V_3 , V_101 , V_3 -> V_53 , L_9 ) ;
break;
case V_102 :
F_39 ( V_3 ,
F_62 ( * V_94 , V_103 ) ,
F_62 ( * V_94 , V_104 ) ,
F_62 ( * V_94 , V_105 ) ) ;
break;
case V_106 :
F_54 ( V_3 , V_94 ) ;
break;
case V_107 :
F_63 ( V_3 , V_94 ) ;
break;
case V_108 :
F_61 ( V_3 , V_52 , V_3 -> V_53 ,
L_10 , V_97 ) ;
break;
case V_109 :
F_61 ( V_3 , V_52 , V_3 -> V_53 , L_11 ) ;
F_53 ( V_3 , V_54 ) ;
break;
case V_110 :
break;
case V_111 :
F_64 ( V_3 , F_62 ( * V_94 , V_112 ) ) ;
break;
case V_113 :
case V_114 :
case V_115 :
F_65 ( V_3 , V_94 ) ;
break;
default:
F_27 ( V_3 , V_52 , V_3 -> V_53 , L_12 ,
V_95 ) ;
}
}
void F_66 ( struct V_2 * V_3 , char * V_116 , T_2 V_117 )
{
T_1 V_36 [ F_67 ( V_118 , 4 ) ] ;
T_2 V_119 ;
const T_8 * V_120 ;
int V_41 ;
F_68 ( V_121 != 0 ) ;
V_41 = F_42 ( V_3 , V_122 , NULL , 0 ,
V_36 , sizeof( V_36 ) , & V_119 ) ;
if ( V_41 )
goto V_123;
if ( V_119 < V_118 ) {
V_41 = - V_54 ;
goto V_123;
}
V_120 = ( T_8 * ) F_69 ( V_36 , V_124 ) ;
snprintf ( V_116 , V_117 , L_13 ,
F_70 ( V_120 [ 0 ] ) , F_70 ( V_120 [ 1 ] ) ,
F_70 ( V_120 [ 2 ] ) , F_70 ( V_120 [ 3 ] ) ) ;
return;
V_123:
F_27 ( V_3 , V_125 , V_3 -> V_53 , L_14 , V_126 , V_41 ) ;
V_116 [ 0 ] = 0 ;
}
int F_71 ( struct V_2 * V_3 , bool V_127 ,
bool * V_128 )
{
T_1 V_15 [ V_129 ] ;
T_1 V_36 [ V_130 ] ;
T_2 V_37 ;
int V_41 ;
F_72 ( V_15 , V_131 ,
V_127 ? 1 : 0 ) ;
F_72 ( V_15 , V_132 , 1 ) ;
V_41 = F_42 ( V_3 , V_133 , V_15 , sizeof( V_15 ) ,
V_36 , sizeof( V_36 ) , & V_37 ) ;
if ( V_41 )
goto V_123;
if ( V_37 < V_130 ) {
V_41 = - V_54 ;
goto V_123;
}
if ( V_128 != NULL )
* V_128 = F_73 ( V_36 , V_134 ) ;
return 0 ;
V_123:
F_27 ( V_3 , V_125 , V_3 -> V_53 , L_14 , V_126 , V_41 ) ;
return V_41 ;
}
int F_74 ( struct V_2 * V_3 , T_1 * V_135 ,
T_9 * V_136 , T_4 * V_137 )
{
T_10 V_36 [ V_138 ] ;
T_2 V_37 , V_139 , V_20 ;
int V_140 = F_75 ( V_3 ) ;
int V_41 ;
F_68 ( V_141 != 0 ) ;
V_41 = F_42 ( V_3 , V_142 , NULL , 0 ,
V_36 , sizeof( V_36 ) , & V_37 ) ;
if ( V_41 )
goto V_123;
if ( V_37 < V_138 ) {
V_41 = - V_54 ;
goto V_123;
}
V_139 = ( V_140 )
? V_143
: V_144 ;
if ( V_135 )
memcpy ( V_135 , V_36 + V_139 , V_145 ) ;
if ( V_136 ) {
V_139 = V_146 ;
for ( V_20 = 0 ;
V_20 < V_147 ;
V_20 ++ ) {
V_136 [ V_20 ] =
( V_139 + 2 <= V_37 ) ?
F_76 ( ( T_8 * ) ( V_36 + V_139 ) ) : 0 ;
V_139 += 2 ;
}
}
if ( V_137 ) {
if ( V_140 )
* V_137 = F_73 ( V_36 ,
V_148 ) ;
else
* V_137 = F_73 ( V_36 ,
V_149 ) ;
}
return 0 ;
V_123:
F_27 ( V_3 , V_52 , V_3 -> V_53 , L_15 ,
V_126 , V_41 , ( int ) V_37 ) ;
return V_41 ;
}
int F_77 ( struct V_2 * V_3 , bool V_150 , bool V_151 , T_4 V_152 )
{
T_1 V_15 [ V_153 ] ;
T_4 V_154 = 0 ;
int V_41 ;
if ( V_151 )
V_154 |= V_155 ;
if ( V_150 )
V_154 |= V_156 ;
F_72 ( V_15 , V_157 , V_154 ) ;
F_72 ( V_15 , V_158 , V_152 ) ;
F_68 ( V_159 != 0 ) ;
V_41 = F_42 ( V_3 , V_160 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_41 )
goto V_123;
return 0 ;
V_123:
F_27 ( V_3 , V_52 , V_3 -> V_53 , L_14 , V_126 , V_41 ) ;
return V_41 ;
}
int F_78 ( struct V_2 * V_3 , T_4 * V_161 )
{
T_1 V_36 [ V_162 ] ;
T_2 V_37 ;
int V_41 ;
F_68 ( V_163 != 0 ) ;
V_41 = F_42 ( V_3 , V_164 , NULL , 0 ,
V_36 , sizeof( V_36 ) , & V_37 ) ;
if ( V_41 )
goto V_123;
if ( V_37 < V_162 ) {
V_41 = - V_54 ;
goto V_123;
}
* V_161 = F_73 ( V_36 , V_165 ) ;
return 0 ;
V_123:
F_27 ( V_3 , V_52 , V_3 -> V_53 , L_14 ,
V_126 , V_41 ) ;
return V_41 ;
}
int F_79 ( struct V_2 * V_3 , unsigned int type ,
T_2 * V_166 , T_2 * V_167 ,
bool * V_168 )
{
T_1 V_15 [ V_169 ] ;
T_1 V_36 [ V_170 ] ;
T_2 V_37 ;
int V_41 ;
F_72 ( V_15 , V_171 , type ) ;
V_41 = F_42 ( V_3 , V_172 , V_15 , sizeof( V_15 ) ,
V_36 , sizeof( V_36 ) , & V_37 ) ;
if ( V_41 )
goto V_123;
if ( V_37 < V_170 ) {
V_41 = - V_54 ;
goto V_123;
}
* V_166 = F_73 ( V_36 , V_173 ) ;
* V_167 = F_73 ( V_36 , V_174 ) ;
* V_168 = ! ! ( F_73 ( V_36 , V_175 ) &
( 1 << V_176 ) ) ;
return 0 ;
V_123:
F_27 ( V_3 , V_52 , V_3 -> V_53 , L_14 , V_126 , V_41 ) ;
return V_41 ;
}
int F_80 ( struct V_2 * V_3 , unsigned int type )
{
T_1 V_15 [ V_177 ] ;
int V_41 ;
F_72 ( V_15 , V_178 , type ) ;
F_68 ( V_179 != 0 ) ;
V_41 = F_42 ( V_3 , V_180 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_41 )
goto V_123;
return 0 ;
V_123:
F_27 ( V_3 , V_52 , V_3 -> V_53 , L_14 , V_126 , V_41 ) ;
return V_41 ;
}
int F_81 ( struct V_2 * V_3 , unsigned int type ,
T_11 V_139 , T_1 * V_181 , T_2 V_182 )
{
T_1 V_15 [ V_183 ] ;
T_1 V_36 [ F_82 ( V_184 ) ] ;
T_2 V_37 ;
int V_41 ;
F_72 ( V_15 , V_185 , type ) ;
F_72 ( V_15 , V_186 , V_139 ) ;
F_72 ( V_15 , V_187 , V_182 ) ;
V_41 = F_42 ( V_3 , V_188 , V_15 , sizeof( V_15 ) ,
V_36 , sizeof( V_36 ) , & V_37 ) ;
if ( V_41 )
goto V_123;
memcpy ( V_181 , F_69 ( V_36 , V_189 ) , V_182 ) ;
return 0 ;
V_123:
F_27 ( V_3 , V_52 , V_3 -> V_53 , L_14 , V_126 , V_41 ) ;
return V_41 ;
}
int F_83 ( struct V_2 * V_3 , unsigned int type ,
T_11 V_139 , const T_1 * V_181 , T_2 V_182 )
{
T_1 V_15 [ F_84 ( V_184 ) ] ;
int V_41 ;
F_72 ( V_15 , V_190 , type ) ;
F_72 ( V_15 , V_191 , V_139 ) ;
F_72 ( V_15 , V_192 , V_182 ) ;
memcpy ( F_69 ( V_15 , V_193 ) , V_181 , V_182 ) ;
F_68 ( V_194 != 0 ) ;
V_41 = F_42 ( V_3 , V_195 , V_15 ,
F_67 ( F_84 ( V_182 ) , 4 ) ,
NULL , 0 , NULL ) ;
if ( V_41 )
goto V_123;
return 0 ;
V_123:
F_27 ( V_3 , V_52 , V_3 -> V_53 , L_14 , V_126 , V_41 ) ;
return V_41 ;
}
int F_85 ( struct V_2 * V_3 , unsigned int type ,
T_11 V_139 , T_2 V_182 )
{
T_1 V_15 [ V_196 ] ;
int V_41 ;
F_72 ( V_15 , V_197 , type ) ;
F_72 ( V_15 , V_198 , V_139 ) ;
F_72 ( V_15 , V_199 , V_182 ) ;
F_68 ( V_200 != 0 ) ;
V_41 = F_42 ( V_3 , V_201 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_41 )
goto V_123;
return 0 ;
V_123:
F_27 ( V_3 , V_52 , V_3 -> V_53 , L_14 , V_126 , V_41 ) ;
return V_41 ;
}
int F_86 ( struct V_2 * V_3 , unsigned int type )
{
T_1 V_15 [ V_202 ] ;
int V_41 ;
F_72 ( V_15 , V_203 , type ) ;
F_68 ( V_204 != 0 ) ;
V_41 = F_42 ( V_3 , V_205 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_41 )
goto V_123;
return 0 ;
V_123:
F_27 ( V_3 , V_52 , V_3 -> V_53 , L_14 , V_126 , V_41 ) ;
return V_41 ;
}
static int F_87 ( struct V_2 * V_3 , unsigned int type )
{
T_1 V_15 [ V_206 ] ;
T_1 V_36 [ V_207 ] ;
int V_41 ;
F_72 ( V_15 , V_208 , type ) ;
V_41 = F_42 ( V_3 , V_209 , V_15 , sizeof( V_15 ) ,
V_36 , sizeof( V_36 ) , NULL ) ;
if ( V_41 )
return V_41 ;
switch ( F_73 ( V_36 , V_210 ) ) {
case V_211 :
case V_212 :
return 0 ;
default:
return - V_54 ;
}
}
int F_88 ( struct V_2 * V_3 )
{
T_4 V_213 ;
unsigned int type ;
int V_41 ;
V_41 = F_78 ( V_3 , & V_213 ) ;
if ( V_41 )
goto V_214;
type = 0 ;
while ( V_213 != 0 ) {
if ( V_213 & 1 ) {
V_41 = F_87 ( V_3 , type ) ;
if ( V_41 )
goto V_215;
}
type ++ ;
V_213 >>= 1 ;
}
return 0 ;
V_215:
F_27 ( V_3 , V_52 , V_3 -> V_53 , L_16 ,
V_126 , type ) ;
V_214:
F_27 ( V_3 , V_52 , V_3 -> V_53 , L_14 , V_126 , V_41 ) ;
return V_41 ;
}
static int F_89 ( struct V_2 * V_3 )
{
T_1 V_15 [ V_216 ] ;
T_1 V_36 [ V_217 ] ;
unsigned int V_82 , V_218 , V_219 ;
const char * V_220 ;
T_2 V_37 ;
int V_221 ;
int V_41 ;
V_221 = 2 ;
do {
F_72 ( V_15 , V_222 , 1 ) ;
V_41 = F_42 ( V_3 , V_223 ,
V_15 , V_216 ,
V_36 , sizeof( V_36 ) , & V_37 ) ;
} while ( ( V_41 == - V_56 || V_41 == - V_54 ) && V_221 -- > 0 );
if ( V_41 )
return V_41 ;
if ( V_37 < V_217 )
return - V_54 ;
V_82 = F_73 ( V_36 , V_224 ) ;
if ( V_82 == V_225 )
return 0 ;
V_220 = ( V_82 == V_226 )
? L_17
: ( V_82 == V_227 )
? L_18
: ( V_82 == V_228 )
? L_19
: L_20 ;
F_27 ( V_3 , V_52 , V_3 -> V_53 ,
L_21 , V_220 ,
F_73 ( V_36 , V_229 ) ,
F_73 ( V_36 , V_230 ) ) ;
V_219 = V_231 ;
for ( V_218 = 1 ; V_218 < 32 ; V_218 ++ ) {
F_27 ( V_3 , V_52 , V_3 -> V_53 , L_22 , V_218 ,
F_90 ( V_36 , V_219 ) ) ;
V_219 += sizeof( T_3 ) ;
}
return 0 ;
}
static void F_91 ( struct V_2 * V_3 )
{
T_1 V_15 [ V_232 ] ;
F_68 ( V_233 != 0 ) ;
F_72 ( V_15 , V_234 ,
V_235 ) ;
( void ) F_42 ( V_3 , V_75 , V_15 , V_232 ,
NULL , 0 , NULL ) ;
}
int F_92 ( struct V_2 * V_3 )
{
int V_41 ;
V_41 = F_89 ( V_3 ) ;
if ( V_41 )
return V_41 ;
F_91 ( V_3 ) ;
return 0 ;
}
void F_93 ( struct V_2 * V_3 , enum V_236 V_12 )
{
T_1 V_15 [ V_237 ] ;
int V_41 ;
F_68 ( V_238 != V_239 ) ;
F_68 ( V_240 != V_241 ) ;
F_68 ( V_242 != V_243 ) ;
F_68 ( V_244 != 0 ) ;
F_72 ( V_15 , V_245 , V_12 ) ;
V_41 = F_42 ( V_3 , V_246 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_41 )
F_27 ( V_3 , V_52 , V_3 -> V_53 , L_14 ,
V_126 , V_41 ) ;
}
int F_94 ( struct V_2 * V_3 )
{
int V_41 = F_42 ( V_3 , V_247 , NULL , 0 , NULL , 0 , NULL ) ;
if ( V_41 )
F_27 ( V_3 , V_52 , V_3 -> V_53 , L_14 ,
V_126 , V_41 ) ;
return V_41 ;
}
int F_95 ( struct V_2 * V_3 )
{
T_1 V_15 [ V_232 ] ;
int V_41 ;
F_68 ( V_233 != 0 ) ;
F_72 ( V_15 , V_234 , 0 ) ;
V_41 = F_42 ( V_3 , V_75 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_41 == - V_54 )
return 0 ;
if ( V_41 == 0 )
V_41 = - V_54 ;
F_27 ( V_3 , V_52 , V_3 -> V_53 , L_14 , V_126 , V_41 ) ;
return V_41 ;
}
static int F_96 ( struct V_2 * V_3 , T_4 type ,
const T_1 * V_248 , int * V_249 )
{
T_1 V_15 [ V_250 ] ;
T_1 V_36 [ V_251 ] ;
T_2 V_37 ;
int V_41 ;
F_72 ( V_15 , V_252 , type ) ;
F_72 ( V_15 , V_253 ,
V_254 ) ;
memcpy ( F_69 ( V_15 , V_255 ) , V_248 , V_145 ) ;
V_41 = F_42 ( V_3 , V_256 , V_15 , sizeof( V_15 ) ,
V_36 , sizeof( V_36 ) , & V_37 ) ;
if ( V_41 )
goto V_123;
if ( V_37 < V_251 ) {
V_41 = - V_54 ;
goto V_123;
}
* V_249 = ( int ) F_73 ( V_36 , V_257 ) ;
return 0 ;
V_123:
* V_249 = - 1 ;
F_27 ( V_3 , V_52 , V_3 -> V_53 , L_14 , V_126 , V_41 ) ;
return V_41 ;
}
int
F_97 ( struct V_2 * V_3 , const T_1 * V_248 , int * V_249 )
{
return F_96 ( V_3 , V_258 , V_248 , V_249 ) ;
}
int F_98 ( struct V_2 * V_3 , int * V_249 )
{
T_1 V_36 [ V_259 ] ;
T_2 V_37 ;
int V_41 ;
V_41 = F_42 ( V_3 , V_260 , NULL , 0 ,
V_36 , sizeof( V_36 ) , & V_37 ) ;
if ( V_41 )
goto V_123;
if ( V_37 < V_259 ) {
V_41 = - V_54 ;
goto V_123;
}
* V_249 = ( int ) F_73 ( V_36 , V_261 ) ;
return 0 ;
V_123:
* V_249 = - 1 ;
F_27 ( V_3 , V_52 , V_3 -> V_53 , L_14 , V_126 , V_41 ) ;
return V_41 ;
}
int F_99 ( struct V_2 * V_3 , int V_262 )
{
T_1 V_15 [ V_263 ] ;
int V_41 ;
F_72 ( V_15 , V_264 , ( T_4 ) V_262 ) ;
V_41 = F_42 ( V_3 , V_265 , V_15 , sizeof( V_15 ) ,
NULL , 0 , NULL ) ;
if ( V_41 )
goto V_123;
return 0 ;
V_123:
F_27 ( V_3 , V_52 , V_3 -> V_53 , L_14 , V_126 , V_41 ) ;
return V_41 ;
}
int F_100 ( struct V_2 * V_3 )
{
struct V_92 * V_93 ;
struct V_266 * V_267 ;
V_34 * V_268 ;
int V_41 , V_78 ;
F_68 ( V_269 >
V_270 ) ;
V_268 = F_101 ( V_269 * sizeof( * V_268 ) , V_271 ) ;
if ( V_268 == NULL )
return - V_272 ;
V_78 = 0 ;
F_102 (channel, efx) {
F_103 (rx_queue, channel) {
if ( V_267 -> V_273 ) {
V_267 -> V_273 = false ;
F_104 ( & V_3 -> V_274 ) ;
V_268 [ V_78 ++ ] = F_105 (
F_106 ( V_267 ) ) ;
}
}
}
V_41 = F_42 ( V_3 , V_275 , ( T_1 * ) V_268 ,
V_78 * sizeof( * V_268 ) , NULL , 0 , NULL ) ;
F_107 ( V_41 < 0 ) ;
F_108 ( V_268 ) ;
return V_41 ;
}
int F_109 ( struct V_2 * V_3 )
{
int V_41 ;
V_41 = F_42 ( V_3 , V_276 , NULL , 0 , NULL , 0 , NULL ) ;
if ( V_41 )
goto V_123;
return 0 ;
V_123:
F_27 ( V_3 , V_52 , V_3 -> V_53 , L_14 , V_126 , V_41 ) ;
return V_41 ;
}
