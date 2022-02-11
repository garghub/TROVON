static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
F_2 ( F_3 ( V_3 ) < V_6 ) ;
V_5 = V_3 -> V_5 ;
return & V_5 -> V_7 ;
}
static inline void
F_4 ( struct V_2 * V_3 , T_1 * V_8 , unsigned V_9 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
V_8 -> V_10 [ 0 ] = ( V_11 V_12 ) F_5 ( V_5 -> V_13 + V_9 ) ;
}
static inline void
F_6 ( struct V_2 * V_3 , const T_1 * V_8 , unsigned V_9 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
F_7 ( ( V_11 V_10 ) V_8 -> V_10 [ 0 ] , V_5 -> V_13 + V_9 ) ;
}
void F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
if ( F_3 ( V_3 ) < V_6 )
return;
V_7 = F_1 ( V_3 ) ;
F_9 ( & V_7 -> V_14 ) ;
F_10 ( & V_7 -> V_15 ) ;
F_11 ( & V_7 -> V_16 , V_17 ) ;
V_7 -> V_18 = V_19 ;
( void ) F_12 ( V_3 ) ;
}
static void F_13 ( struct V_2 * V_3 , unsigned V_20 ,
const T_2 * V_21 , T_3 V_22 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned V_23 = F_14 ( V_3 ) ;
unsigned V_24 = F_15 ( V_3 ) ;
unsigned int V_25 ;
T_1 V_26 ;
V_10 V_27 , V_28 ;
F_16 ( F_17 ( & V_7 -> V_16 ) == V_17 ) ;
F_16 ( V_22 & 3 || V_22 >= 0x100 ) ;
V_28 = V_7 -> V_28 & V_29 ;
V_27 = 0 ;
if ( V_7 -> V_18 == V_30 )
V_27 |= V_31 ;
F_18 ( V_26 ,
V_32 , 0 ,
V_33 , 1 ,
V_34 , V_20 ,
V_35 , V_22 ,
V_36 , V_28 ,
V_37 , V_27 ) ;
F_6 ( V_3 , & V_26 , V_23 ) ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 += 4 )
F_6 ( V_3 , ( const T_1 * ) ( V_21 + V_25 ) ,
V_23 + 4 + V_25 ) ;
F_19 ( V_26 , V_38 , 0x45789abc ) ;
F_6 ( V_3 , & V_26 , V_24 ) ;
}
static void F_20 ( struct V_2 * V_3 , T_2 * V_39 , T_3 V_40 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_23 = F_14 ( V_3 ) ;
int V_25 ;
F_16 ( F_17 ( & V_7 -> V_16 ) == V_17 ) ;
F_16 ( V_40 & 3 || V_40 >= 0x100 ) ;
for ( V_25 = 0 ; V_25 < V_40 ; V_25 += 4 )
F_4 ( V_3 , ( T_1 * ) ( V_39 + V_25 ) , V_23 + 4 + V_25 ) ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int time , V_41 ;
unsigned int V_42 , V_43 , error ;
unsigned int V_23 = F_14 ( V_3 ) ;
unsigned int V_44 , V_45 ;
T_1 V_9 ;
V_44 = - F_12 ( V_3 ) ;
if ( V_44 )
goto V_46;
V_45 = V_47 ;
V_41 = F_22 () + V_48 ;
while ( 1 ) {
if ( V_45 != 0 ) {
-- V_45 ;
F_23 ( 1 ) ;
} else {
F_24 ( 1 ) ;
}
time = F_22 () ;
F_4 ( V_3 , & V_9 , V_23 ) ;
if ( F_25 ( V_9 , V_38 ) != 0xffffffff &&
F_25 ( V_9 , V_32 ) )
break;
if ( time >= V_41 )
return - V_49 ;
}
V_7 -> V_50 = F_25 ( V_9 , V_35 ) ;
V_42 = F_25 ( V_9 , V_36 ) ;
V_43 = F_25 ( V_9 , V_34 ) ;
error = F_25 ( V_9 , V_51 ) ;
if ( error && V_7 -> V_50 == 0 ) {
F_26 ( V_3 , V_52 , V_3 -> V_53 , L_1 ) ;
V_44 = V_54 ;
} else if ( ( V_42 ^ V_7 -> V_28 ) & V_29 ) {
F_26 ( V_3 , V_52 , V_3 -> V_53 ,
L_2 ,
V_42 , V_7 -> V_28 ) ;
V_44 = V_54 ;
} else if ( error ) {
F_4 ( V_3 , & V_9 , V_23 + 4 ) ;
switch ( F_25 ( V_9 , V_38 ) ) {
#define F_27 ( T_4 ) \
case MC_CMD_ERR_ ## name: \
rc = name; \
break
F_27 ( V_55 ) ;
F_27 ( V_56 ) ;
F_27 ( V_57 ) ;
F_27 ( V_58 ) ;
F_27 ( V_59 ) ;
F_27 ( V_60 ) ;
F_27 ( V_61 ) ;
F_27 ( V_62 ) ;
#undef F_27
default:
V_44 = V_54 ;
break;
}
} else
V_44 = 0 ;
V_46:
V_7 -> V_63 = V_44 ;
if ( V_44 )
V_7 -> V_50 = 0 ;
return 0 ;
}
int F_12 ( struct V_2 * V_3 )
{
unsigned int V_64 = F_28 ( V_3 ) ;
T_1 V_9 ;
T_5 V_8 ;
if ( F_3 ( V_3 ) < V_6 )
return false ;
F_4 ( V_3 , & V_9 , V_64 ) ;
V_8 = F_25 ( V_9 , V_38 ) ;
if ( V_8 == 0 )
return 0 ;
F_29 ( V_9 ) ;
F_6 ( V_3 , & V_9 , V_64 ) ;
if ( V_8 == V_65 )
return - V_56 ;
else
return - V_54 ;
}
static void F_30 ( struct V_1 * V_7 )
{
F_31 ( V_7 -> V_14 ,
F_32 ( & V_7 -> V_16 ,
V_17 ,
V_66 )
== V_17 ) ;
}
static int F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( F_34 (
V_7 -> V_14 ,
F_17 ( & V_7 -> V_16 ) == V_67 ,
F_35 ( V_48 * 1000 ) ) == 0 )
return - V_49 ;
if ( V_7 -> V_18 == V_19 )
return F_21 ( V_3 ) ;
return 0 ;
}
static bool F_36 ( struct V_1 * V_7 )
{
if ( F_32 ( & V_7 -> V_16 ,
V_66 ,
V_67 ) == V_66 ) {
F_37 ( & V_7 -> V_14 ) ;
return true ;
}
return false ;
}
static void F_38 ( struct V_1 * V_7 )
{
F_11 ( & V_7 -> V_16 , V_17 ) ;
F_37 ( & V_7 -> V_14 ) ;
}
static void F_39 ( struct V_2 * V_3 , unsigned int V_28 ,
unsigned int V_68 , unsigned int V_69 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
bool V_70 = false ;
F_40 ( & V_7 -> V_15 ) ;
if ( ( V_28 ^ V_7 -> V_28 ) & V_29 ) {
if ( V_7 -> V_71 )
-- V_7 -> V_71 ;
else
F_26 ( V_3 , V_52 , V_3 -> V_53 ,
L_3
L_4 , V_28 , V_7 -> V_28 ) ;
} else {
V_7 -> V_63 = V_69 ;
V_7 -> V_50 = V_68 ;
V_70 = true ;
}
F_41 ( & V_7 -> V_15 ) ;
if ( V_70 )
F_36 ( V_7 ) ;
}
int F_42 ( struct V_2 * V_3 , unsigned V_20 ,
const T_2 * V_21 , T_3 V_22 , T_2 * V_39 , T_3 V_40 ,
T_3 * V_72 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_44 ;
F_16 ( F_3 ( V_3 ) < V_6 ) ;
F_30 ( V_7 ) ;
F_43 ( & V_7 -> V_15 ) ;
++ V_7 -> V_28 ;
F_44 ( & V_7 -> V_15 ) ;
F_13 ( V_3 , V_20 , V_21 , V_22 ) ;
if ( V_7 -> V_18 == V_19 )
V_44 = F_21 ( V_3 ) ;
else
V_44 = F_33 ( V_3 ) ;
if ( V_44 != 0 ) {
F_43 ( & V_7 -> V_15 ) ;
++ V_7 -> V_28 ;
++ V_7 -> V_71 ;
F_44 ( & V_7 -> V_15 ) ;
F_26 ( V_3 , V_52 , V_3 -> V_53 ,
L_5 ,
V_20 , ( int ) V_22 , V_7 -> V_18 ) ;
} else {
T_3 V_50 ;
F_43 ( & V_7 -> V_15 ) ;
V_44 = - V_7 -> V_63 ;
V_50 = V_7 -> V_50 ;
F_44 ( & V_7 -> V_15 ) ;
if ( V_44 == 0 ) {
F_20 ( V_3 , V_39 ,
F_45 ( V_40 , V_7 -> V_50 + 3 ) & ~ 0x3 ) ;
if ( V_72 != NULL )
* V_72 = V_50 ;
} else if ( V_20 == V_73 && V_44 == - V_54 )
;
else if ( V_44 == - V_54 || V_44 == - V_56 ) {
F_26 ( V_3 , V_52 , V_3 -> V_53 , L_6 ,
- V_44 ) ;
F_46 ( V_3 , V_74 ) ;
} else
F_47 ( V_3 , V_52 , V_3 -> V_53 ,
L_7 ,
V_20 , ( int ) V_22 , - V_44 ) ;
}
F_38 ( V_7 ) ;
return V_44 ;
}
void F_48 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
if ( F_3 ( V_3 ) < V_6 )
return;
V_7 = F_1 ( V_3 ) ;
if ( V_7 -> V_18 == V_19 )
return;
V_7 -> V_18 = V_19 ;
F_36 ( V_7 ) ;
}
void F_49 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
if ( F_3 ( V_3 ) < V_6 )
return;
V_7 = F_1 ( V_3 ) ;
if ( V_7 -> V_18 == V_30 )
return;
F_30 ( V_7 ) ;
V_7 -> V_18 = V_30 ;
F_38 ( V_7 ) ;
}
static void F_50 ( struct V_2 * V_3 , int V_44 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_40 ( & V_7 -> V_15 ) ;
if ( F_36 ( V_7 ) ) {
if ( V_7 -> V_18 == V_30 ) {
V_7 -> V_63 = V_44 ;
V_7 -> V_50 = 0 ;
++ V_7 -> V_71 ;
}
} else
F_46 ( V_3 , V_74 ) ;
F_41 ( & V_7 -> V_15 ) ;
}
static void F_51 ( struct V_2 * V_3 , T_6 * V_75 )
{
V_10 V_76 , V_77 , V_78 , V_79 ;
V_78 = F_52 ( * V_75 , V_80 ) ;
F_2 ( V_78 >= F_53 ( V_81 ) ) ;
V_78 = V_81 [ V_78 ] ;
V_76 = F_52 ( * V_75 , V_82 ) ;
V_77 = F_52 ( * V_75 , V_83 ) ;
V_79 = F_52 ( * V_75 , V_84 ) ;
F_54 ( V_3 , & V_3 -> V_85 , V_78 , V_76 , V_77 ) ;
F_55 ( V_3 , V_79 ) ;
F_56 ( V_3 ) ;
}
static void F_57 ( struct V_2 * V_3 , T_6 * V_75 )
{
unsigned int V_86 , V_16 , V_8 ;
const char * T_4 , * V_87 ;
V_86 = F_52 ( * V_75 , V_88 ) ;
V_16 = F_52 ( * V_75 , V_89 ) ;
V_8 = F_52 ( * V_75 , V_90 ) ;
T_4 = ( V_86 >= F_53 ( V_91 ) )
? L_8 :
V_91 [ V_86 ] ;
F_2 ( V_16 >= F_53 ( V_92 ) ) ;
V_87 = V_92 [ V_16 ] ;
F_26 ( V_3 , V_52 , V_3 -> V_53 ,
L_9 ,
V_86 , T_4 , V_87 , V_8 ) ;
}
void F_58 ( struct V_93 * V_94 ,
T_6 * V_95 )
{
struct V_2 * V_3 = V_94 -> V_3 ;
int V_96 = F_52 ( * V_95 , V_97 ) ;
V_10 V_98 = F_52 ( * V_95 , V_99 ) ;
switch ( V_96 ) {
case V_100 :
F_26 ( V_3 , V_52 , V_3 -> V_53 ,
L_10 , V_98 ) ;
F_50 ( V_3 , V_56 ) ;
break;
case V_101 :
F_59 ( V_3 , V_102 , V_3 -> V_53 , L_11 ) ;
break;
case V_103 :
F_39 ( V_3 ,
F_60 ( * V_95 , V_104 ) ,
F_60 ( * V_95 , V_105 ) ,
F_60 ( * V_95 , V_106 ) ) ;
break;
case V_107 :
F_51 ( V_3 , V_95 ) ;
break;
case V_108 :
F_57 ( V_3 , V_95 ) ;
break;
case V_109 :
F_59 ( V_3 , V_52 , V_3 -> V_53 ,
L_12 , V_98 ) ;
break;
case V_110 :
F_59 ( V_3 , V_52 , V_3 -> V_53 , L_13 ) ;
F_50 ( V_3 , V_54 ) ;
break;
case V_111 :
break;
default:
F_26 ( V_3 , V_52 , V_3 -> V_53 , L_14 ,
V_96 ) ;
}
}
void F_61 ( struct V_2 * V_3 , char * V_112 , T_3 V_113 )
{
T_2 V_39 [ F_62 ( V_114 , 4 ) ] ;
T_3 V_115 ;
const T_7 * V_116 ;
int V_44 ;
F_63 ( V_117 != 0 ) ;
V_44 = F_42 ( V_3 , V_118 , NULL , 0 ,
V_39 , sizeof( V_39 ) , & V_115 ) ;
if ( V_44 )
goto V_119;
if ( V_115 < V_114 ) {
V_44 = - V_54 ;
goto V_119;
}
V_116 = ( T_7 * ) F_64 ( V_39 , V_120 ) ;
snprintf ( V_112 , V_113 , L_15 ,
F_65 ( V_116 [ 0 ] ) , F_65 ( V_116 [ 1 ] ) ,
F_65 ( V_116 [ 2 ] ) , F_65 ( V_116 [ 3 ] ) ) ;
return;
V_119:
F_26 ( V_3 , V_121 , V_3 -> V_53 , L_16 , V_122 , V_44 ) ;
V_112 [ 0 ] = 0 ;
}
int F_66 ( struct V_2 * V_3 , bool V_123 ,
bool * V_124 )
{
T_2 V_21 [ V_125 ] ;
T_2 V_39 [ V_126 ] ;
T_3 V_40 ;
int V_44 ;
F_67 ( V_21 , V_127 ,
V_123 ? 1 : 0 ) ;
F_67 ( V_21 , V_128 , 1 ) ;
V_44 = F_42 ( V_3 , V_129 , V_21 , sizeof( V_21 ) ,
V_39 , sizeof( V_39 ) , & V_40 ) ;
if ( V_44 )
goto V_119;
if ( V_40 < V_126 ) {
V_44 = - V_54 ;
goto V_119;
}
if ( V_124 != NULL )
* V_124 = F_68 ( V_39 , V_130 ) ;
return 0 ;
V_119:
F_26 ( V_3 , V_121 , V_3 -> V_53 , L_16 , V_122 , V_44 ) ;
return V_44 ;
}
int F_69 ( struct V_2 * V_3 , T_2 * V_131 ,
T_8 * V_132 )
{
T_9 V_39 [ V_133 ] ;
T_3 V_40 ;
int V_134 = F_70 ( V_3 ) ;
int V_135 ;
int V_44 ;
F_63 ( V_136 != 0 ) ;
V_44 = F_42 ( V_3 , V_137 , NULL , 0 ,
V_39 , sizeof( V_39 ) , & V_40 ) ;
if ( V_44 )
goto V_119;
if ( V_40 < V_133 ) {
V_44 = - V_54 ;
goto V_119;
}
V_135 = ( V_134 )
? V_138
: V_139 ;
if ( V_131 )
memcpy ( V_131 , V_39 + V_135 , V_140 ) ;
if ( V_132 )
memcpy ( V_132 ,
V_39 + V_141 ,
V_142 ) ;
return 0 ;
V_119:
F_26 ( V_3 , V_52 , V_3 -> V_53 , L_17 ,
V_122 , V_44 , ( int ) V_40 ) ;
return V_44 ;
}
int F_71 ( struct V_2 * V_3 , bool V_143 , bool V_144 , V_10 V_145 )
{
T_2 V_21 [ V_146 ] ;
V_10 V_147 = 0 ;
int V_44 ;
if ( V_144 )
V_147 |= V_148 ;
if ( V_143 )
V_147 |= V_149 ;
F_67 ( V_21 , V_150 , V_147 ) ;
F_67 ( V_21 , V_151 , V_145 ) ;
F_63 ( V_152 != 0 ) ;
V_44 = F_42 ( V_3 , V_153 , V_21 , sizeof( V_21 ) ,
NULL , 0 , NULL ) ;
if ( V_44 )
goto V_119;
return 0 ;
V_119:
F_26 ( V_3 , V_52 , V_3 -> V_53 , L_16 , V_122 , V_44 ) ;
return V_44 ;
}
int F_72 ( struct V_2 * V_3 , V_10 * V_154 )
{
T_2 V_39 [ V_155 ] ;
T_3 V_40 ;
int V_44 ;
F_63 ( V_156 != 0 ) ;
V_44 = F_42 ( V_3 , V_157 , NULL , 0 ,
V_39 , sizeof( V_39 ) , & V_40 ) ;
if ( V_44 )
goto V_119;
if ( V_40 < V_155 ) {
V_44 = - V_54 ;
goto V_119;
}
* V_154 = F_68 ( V_39 , V_158 ) ;
return 0 ;
V_119:
F_26 ( V_3 , V_52 , V_3 -> V_53 , L_16 ,
V_122 , V_44 ) ;
return V_44 ;
}
int F_73 ( struct V_2 * V_3 , unsigned int type ,
T_3 * V_159 , T_3 * V_160 ,
bool * V_161 )
{
T_2 V_21 [ V_162 ] ;
T_2 V_39 [ V_163 ] ;
T_3 V_40 ;
int V_44 ;
F_67 ( V_21 , V_164 , type ) ;
V_44 = F_42 ( V_3 , V_165 , V_21 , sizeof( V_21 ) ,
V_39 , sizeof( V_39 ) , & V_40 ) ;
if ( V_44 )
goto V_119;
if ( V_40 < V_163 ) {
V_44 = - V_54 ;
goto V_119;
}
* V_159 = F_68 ( V_39 , V_166 ) ;
* V_160 = F_68 ( V_39 , V_167 ) ;
* V_161 = ! ! ( F_68 ( V_39 , V_168 ) &
( 1 << V_169 ) ) ;
return 0 ;
V_119:
F_26 ( V_3 , V_52 , V_3 -> V_53 , L_16 , V_122 , V_44 ) ;
return V_44 ;
}
int F_74 ( struct V_2 * V_3 , unsigned int type )
{
T_2 V_21 [ V_170 ] ;
int V_44 ;
F_67 ( V_21 , V_171 , type ) ;
F_63 ( V_172 != 0 ) ;
V_44 = F_42 ( V_3 , V_173 , V_21 , sizeof( V_21 ) ,
NULL , 0 , NULL ) ;
if ( V_44 )
goto V_119;
return 0 ;
V_119:
F_26 ( V_3 , V_52 , V_3 -> V_53 , L_16 , V_122 , V_44 ) ;
return V_44 ;
}
int F_75 ( struct V_2 * V_3 , unsigned int type ,
T_10 V_135 , T_2 * V_174 , T_3 V_175 )
{
T_2 V_21 [ V_176 ] ;
T_2 V_39 [ F_76 ( V_177 ) ] ;
T_3 V_40 ;
int V_44 ;
F_67 ( V_21 , V_178 , type ) ;
F_67 ( V_21 , V_179 , V_135 ) ;
F_67 ( V_21 , V_180 , V_175 ) ;
V_44 = F_42 ( V_3 , V_181 , V_21 , sizeof( V_21 ) ,
V_39 , sizeof( V_39 ) , & V_40 ) ;
if ( V_44 )
goto V_119;
memcpy ( V_174 , F_64 ( V_39 , V_182 ) , V_175 ) ;
return 0 ;
V_119:
F_26 ( V_3 , V_52 , V_3 -> V_53 , L_16 , V_122 , V_44 ) ;
return V_44 ;
}
int F_77 ( struct V_2 * V_3 , unsigned int type ,
T_10 V_135 , const T_2 * V_174 , T_3 V_175 )
{
T_2 V_21 [ F_78 ( V_177 ) ] ;
int V_44 ;
F_67 ( V_21 , V_183 , type ) ;
F_67 ( V_21 , V_184 , V_135 ) ;
F_67 ( V_21 , V_185 , V_175 ) ;
memcpy ( F_64 ( V_21 , V_186 ) , V_174 , V_175 ) ;
F_63 ( V_187 != 0 ) ;
V_44 = F_42 ( V_3 , V_188 , V_21 ,
F_62 ( F_78 ( V_175 ) , 4 ) ,
NULL , 0 , NULL ) ;
if ( V_44 )
goto V_119;
return 0 ;
V_119:
F_26 ( V_3 , V_52 , V_3 -> V_53 , L_16 , V_122 , V_44 ) ;
return V_44 ;
}
int F_79 ( struct V_2 * V_3 , unsigned int type ,
T_10 V_135 , T_3 V_175 )
{
T_2 V_21 [ V_189 ] ;
int V_44 ;
F_67 ( V_21 , V_190 , type ) ;
F_67 ( V_21 , V_191 , V_135 ) ;
F_67 ( V_21 , V_192 , V_175 ) ;
F_63 ( V_193 != 0 ) ;
V_44 = F_42 ( V_3 , V_194 , V_21 , sizeof( V_21 ) ,
NULL , 0 , NULL ) ;
if ( V_44 )
goto V_119;
return 0 ;
V_119:
F_26 ( V_3 , V_52 , V_3 -> V_53 , L_16 , V_122 , V_44 ) ;
return V_44 ;
}
int F_80 ( struct V_2 * V_3 , unsigned int type )
{
T_2 V_21 [ V_195 ] ;
int V_44 ;
F_67 ( V_21 , V_196 , type ) ;
F_63 ( V_197 != 0 ) ;
V_44 = F_42 ( V_3 , V_198 , V_21 , sizeof( V_21 ) ,
NULL , 0 , NULL ) ;
if ( V_44 )
goto V_119;
return 0 ;
V_119:
F_26 ( V_3 , V_52 , V_3 -> V_53 , L_16 , V_122 , V_44 ) ;
return V_44 ;
}
static int F_81 ( struct V_2 * V_3 , unsigned int type )
{
T_2 V_21 [ V_199 ] ;
T_2 V_39 [ V_200 ] ;
int V_44 ;
F_67 ( V_21 , V_201 , type ) ;
V_44 = F_42 ( V_3 , V_202 , V_21 , sizeof( V_21 ) ,
V_39 , sizeof( V_39 ) , NULL ) ;
if ( V_44 )
return V_44 ;
switch ( F_68 ( V_39 , V_203 ) ) {
case V_204 :
case V_205 :
return 0 ;
default:
return - V_54 ;
}
}
int F_82 ( struct V_2 * V_3 )
{
V_10 V_206 ;
unsigned int type ;
int V_44 ;
V_44 = F_72 ( V_3 , & V_206 ) ;
if ( V_44 )
goto V_207;
type = 0 ;
while ( V_206 != 0 ) {
if ( V_206 & 1 ) {
V_44 = F_81 ( V_3 , type ) ;
if ( V_44 )
goto V_208;
}
type ++ ;
V_206 >>= 1 ;
}
return 0 ;
V_208:
F_26 ( V_3 , V_52 , V_3 -> V_53 , L_18 ,
V_122 , type ) ;
V_207:
F_26 ( V_3 , V_52 , V_3 -> V_53 , L_16 , V_122 , V_44 ) ;
return V_44 ;
}
static int F_83 ( struct V_2 * V_3 )
{
T_2 V_21 [ V_209 ] ;
T_2 V_39 [ V_210 ] ;
unsigned int V_76 , V_211 , V_212 ;
const char * V_213 ;
T_3 V_40 ;
int V_214 ;
int V_44 ;
V_214 = 2 ;
do {
F_67 ( V_21 , V_215 , 1 ) ;
V_44 = F_42 ( V_3 , V_216 ,
V_21 , V_209 ,
V_39 , sizeof( V_39 ) , & V_40 ) ;
} while ( ( V_44 == - V_56 || V_44 == - V_54 ) && V_214 -- > 0 );
if ( V_44 )
return V_44 ;
if ( V_40 < V_210 )
return - V_54 ;
V_76 = F_68 ( V_39 , V_217 ) ;
if ( V_76 == V_218 )
return 0 ;
V_213 = ( V_76 == V_219 )
? L_19
: ( V_76 == V_220 )
? L_20
: ( V_76 == V_221 )
? L_21
: L_22 ;
F_26 ( V_3 , V_52 , V_3 -> V_53 ,
L_23 , V_213 ,
F_68 ( V_39 , V_222 ) ,
F_68 ( V_39 , V_223 ) ) ;
V_212 = V_224 ;
for ( V_211 = 1 ; V_211 < 32 ; V_211 ++ ) {
F_26 ( V_3 , V_52 , V_3 -> V_53 , L_24 , V_211 ,
F_84 ( V_39 , V_212 ) ) ;
V_212 += sizeof( T_1 ) ;
}
return 0 ;
}
static void F_85 ( struct V_2 * V_3 )
{
T_2 V_21 [ V_225 ] ;
F_63 ( V_226 != 0 ) ;
F_67 ( V_21 , V_227 ,
V_228 ) ;
F_42 ( V_3 , V_73 , V_21 , V_225 ,
NULL , 0 , NULL ) ;
}
int F_86 ( struct V_2 * V_3 )
{
int V_44 ;
V_44 = F_83 ( V_3 ) ;
if ( V_44 )
return V_44 ;
F_85 ( V_3 ) ;
return 0 ;
}
void F_87 ( struct V_2 * V_3 , enum V_229 V_18 )
{
T_2 V_21 [ V_230 ] ;
int V_44 ;
F_63 ( V_231 != V_232 ) ;
F_63 ( V_233 != V_234 ) ;
F_63 ( V_235 != V_236 ) ;
F_63 ( V_237 != 0 ) ;
F_67 ( V_21 , V_238 , V_18 ) ;
V_44 = F_42 ( V_3 , V_239 , V_21 , sizeof( V_21 ) ,
NULL , 0 , NULL ) ;
if ( V_44 )
F_26 ( V_3 , V_52 , V_3 -> V_53 , L_16 ,
V_122 , V_44 ) ;
}
int F_88 ( struct V_2 * V_3 )
{
int V_44 = F_42 ( V_3 , V_240 , NULL , 0 , NULL , 0 , NULL ) ;
if ( V_44 )
F_26 ( V_3 , V_52 , V_3 -> V_53 , L_16 ,
V_122 , V_44 ) ;
return V_44 ;
}
int F_89 ( struct V_2 * V_3 )
{
T_2 V_21 [ V_225 ] ;
int V_44 ;
F_63 ( V_226 != 0 ) ;
F_67 ( V_21 , V_227 , 0 ) ;
V_44 = F_42 ( V_3 , V_73 , V_21 , sizeof( V_21 ) ,
NULL , 0 , NULL ) ;
if ( V_44 == - V_54 )
return 0 ;
if ( V_44 == 0 )
V_44 = - V_54 ;
F_26 ( V_3 , V_52 , V_3 -> V_53 , L_16 , V_122 , V_44 ) ;
return V_44 ;
}
static int F_90 ( struct V_2 * V_3 , V_10 type ,
const T_2 * V_241 , int * V_242 )
{
T_2 V_21 [ V_243 ] ;
T_2 V_39 [ V_244 ] ;
T_3 V_40 ;
int V_44 ;
F_67 ( V_21 , V_245 , type ) ;
F_67 ( V_21 , V_246 ,
V_247 ) ;
memcpy ( F_64 ( V_21 , V_248 ) , V_241 , V_140 ) ;
V_44 = F_42 ( V_3 , V_249 , V_21 , sizeof( V_21 ) ,
V_39 , sizeof( V_39 ) , & V_40 ) ;
if ( V_44 )
goto V_119;
if ( V_40 < V_244 ) {
V_44 = - V_54 ;
goto V_119;
}
* V_242 = ( int ) F_68 ( V_39 , V_250 ) ;
return 0 ;
V_119:
* V_242 = - 1 ;
F_26 ( V_3 , V_52 , V_3 -> V_53 , L_16 , V_122 , V_44 ) ;
return V_44 ;
}
int
F_91 ( struct V_2 * V_3 , const T_2 * V_241 , int * V_242 )
{
return F_90 ( V_3 , V_251 , V_241 , V_242 ) ;
}
int F_92 ( struct V_2 * V_3 , int * V_242 )
{
T_2 V_39 [ V_252 ] ;
T_3 V_40 ;
int V_44 ;
V_44 = F_42 ( V_3 , V_253 , NULL , 0 ,
V_39 , sizeof( V_39 ) , & V_40 ) ;
if ( V_44 )
goto V_119;
if ( V_40 < V_252 ) {
V_44 = - V_54 ;
goto V_119;
}
* V_242 = ( int ) F_68 ( V_39 , V_254 ) ;
return 0 ;
V_119:
* V_242 = - 1 ;
F_26 ( V_3 , V_52 , V_3 -> V_53 , L_16 , V_122 , V_44 ) ;
return V_44 ;
}
int F_93 ( struct V_2 * V_3 , int V_255 )
{
T_2 V_21 [ V_256 ] ;
int V_44 ;
F_67 ( V_21 , V_257 , ( V_10 ) V_255 ) ;
V_44 = F_42 ( V_3 , V_258 , V_21 , sizeof( V_21 ) ,
NULL , 0 , NULL ) ;
if ( V_44 )
goto V_119;
return 0 ;
V_119:
F_26 ( V_3 , V_52 , V_3 -> V_53 , L_16 , V_122 , V_44 ) ;
return V_44 ;
}
int F_94 ( struct V_2 * V_3 )
{
int V_44 ;
V_44 = F_42 ( V_3 , V_259 , NULL , 0 , NULL , 0 , NULL ) ;
if ( V_44 )
goto V_119;
return 0 ;
V_119:
F_26 ( V_3 , V_52 , V_3 -> V_53 , L_16 , V_122 , V_44 ) ;
return V_44 ;
}
