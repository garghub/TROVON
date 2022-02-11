static int F_1 ( struct V_1 * V_2 , T_1 V_3 , void * V_4 ,
T_2 V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 V_10 [ 2 ] ;
int V_11 , V_12 = 0 ;
V_10 [ 0 ] . V_13 = V_2 -> V_13 ;
V_10 [ 0 ] . V_14 = 0 ;
V_10 [ 0 ] . V_5 = 1 ;
V_10 [ 0 ] . V_4 = & V_3 ;
V_10 [ 1 ] . V_13 = V_2 -> V_13 ;
V_10 [ 1 ] . V_14 = V_15 ;
V_10 [ 1 ] . V_5 = V_5 ;
V_10 [ 1 ] . V_4 = V_4 ;
F_2 ( V_7 ) ;
for ( V_11 = 0 ; V_11 < 2 ; V_11 ++ ) {
if ( F_3 ( V_7 , & V_10 [ V_11 ] , 1 ) < 0 ) {
V_12 = - V_16 ;
break;
}
}
F_4 ( V_7 ) ;
return V_12 ;
}
static int F_5 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_19 * V_20 = & V_2 -> V_20 ;
T_1 V_4 [ 33 ] ;
int V_21 ;
bool V_22 = false ;
bool V_23 = true ;
bool V_24 ;
T_1 V_25 , V_26 , V_27 ;
T_3 V_28 , V_29 , V_30 ;
T_3 V_31 ;
int V_32 = 0 , V_33 = 0 ;
int V_34 , V_35 ;
int V_36 , V_37 ;
int error , V_38 ;
int V_11 ;
V_28 = F_6 ( V_2 , V_39 ) ;
if ( V_28 < 0 )
return V_28 ;
V_29 = F_6 ( V_2 , V_40 ) ;
if ( V_29 < 0 )
return V_29 ;
V_30 = F_6 ( V_2 , V_41 ) ;
if ( V_30 < 0 )
return V_30 ;
error = F_7 ( V_2 , V_42 ,
V_43 | V_44 | V_45 |
V_46 ) ;
if ( error )
goto V_47;
error = F_7 ( V_2 , V_48 ,
V_49 ) ;
if ( error )
goto V_47;
for ( V_21 = 0 ; V_21 < V_50 ; V_21 ++ ) {
F_8 ( 2 * V_51 ) ;
#define F_9 ( T_4 ) buf[((reg) - PRM1_X_H)]
error = F_1 ( V_2 , V_52 , V_4 , sizeof( V_4 ) ) ;
if ( error )
goto V_47;
if ( F_9 ( V_53 ) & V_54 )
continue;
if ( V_23 ) {
V_32 = ( ( int ) F_9 ( V_52 ) << 2 |
F_9 ( V_55 ) ) - V_56 ;
V_33 = ( ( int ) F_9 ( V_57 ) << 2 |
F_9 ( V_58 ) ) - V_56 ;
error = F_7 ( V_2 , V_48 ,
V_49 | V_59 ) ;
if ( error )
goto V_47;
V_23 = false ;
} else {
V_36 = ( int ) F_9 ( V_52 ) << 2 |
F_9 ( V_55 ) ;
V_37 = ( int ) F_9 ( V_57 ) << 2 |
F_9 ( V_58 ) ;
if ( V_36 <= 4 )
V_32 -= V_60 ;
else if ( V_36 >= 60 )
V_32 += V_60 ;
if ( V_37 <= 4 )
V_33 -= V_60 ;
else if ( V_37 >= 60 )
V_33 += V_60 ;
}
V_34 = V_32 + ( ( V_32 & 0x200 ) << 1 ) ;
V_35 = V_33 + ( ( V_33 & 0x200 ) << 1 ) ;
V_25 = V_34 >> 3 ;
V_26 = ( V_35 & 0x7 ) << 4 | ( V_34 & 0x7 ) ;
V_27 = V_35 >> 3 ;
error = F_7 ( V_2 ,
V_39 , V_25 ) ;
if ( error )
goto V_47;
error = F_7 ( V_2 ,
V_40 , V_26 ) ;
if ( error )
goto V_47;
error = F_7 ( V_2 ,
V_41 , V_27 ) ;
if ( error )
goto V_47;
error = F_7 ( V_2 , V_61 ,
V_62 ) ;
if ( error )
goto V_47;
error = F_7 ( V_2 , V_61 ,
V_63 ) ;
if ( error )
goto V_47;
error = F_7 ( V_2 , V_64 , 0xff ) ;
if ( error )
goto V_47;
V_24 = false ;
for ( V_11 = 0 ; V_11 < 10 ; V_11 ++ ) {
F_8 ( V_51 ) ;
V_31 = F_6 ( V_2 , V_65 ) ;
if ( ! ( V_31 & V_66 ) ) {
V_24 = true ;
break;
} else if ( V_31 < 0 ) {
error = V_31 ;
goto V_47;
}
}
if ( V_24 ) {
V_31 = F_6 ( V_2 , V_67 ) ;
if ( V_31 == V_68 ) {
V_22 = true ;
break;
} else if ( V_31 < 0 ) {
error = V_31 ;
goto V_47;
}
} else {
F_10 ( V_20 , L_1 ) ;
}
}
if ( ! V_22 ) {
error = F_7 ( V_2 , V_39 ,
V_28 ) ;
if ( error )
goto V_47;
error = F_7 ( V_2 , V_40 ,
V_29 ) ;
if ( error )
goto V_47;
error = F_7 ( V_2 , V_41 ,
V_30 ) ;
if ( error )
goto V_47;
error = F_7 ( V_2 , V_48 ,
V_49 |
V_59 ) ;
if ( error )
goto V_47;
F_8 ( 10 * V_51 ) ;
error = - V_69 ;
}
V_47:
V_38 = F_7 ( V_2 , V_42 , V_70 ) ;
if ( ! V_38 )
V_38 = F_7 ( V_2 , V_64 , 0xff ) ;
return error ? error : V_38 ;
}
static T_5 F_11 ( int V_71 , void * V_72 )
{
struct V_17 * V_18 = V_72 ;
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_73 * V_73 = V_18 -> V_74 ;
struct V_19 * V_20 = & V_2 -> V_20 ;
T_1 V_4 [ 10 ] ;
struct V_75 V_76 [ V_77 ] ;
int V_78 [ V_77 ] ;
T_1 V_79 ;
unsigned int V_80 ;
int V_81 = - 1 ;
int V_82 = V_18 -> V_81 ;
int V_83 ;
int error ;
int V_11 ;
error = F_7 ( V_2 , V_42 , V_70 ) ;
if ( error )
return V_84 ;
error = F_7 ( V_2 , V_64 , 0xff ) ;
if ( error )
return V_84 ;
#define F_12 ( T_4 ) buf[((reg) - POS_X1_H)]
error = F_1 ( V_2 , V_85 , V_4 , sizeof( V_4 ) ) ;
if ( error )
return V_84 ;
V_79 = F_12 ( V_65 ) & V_86 ;
if ( V_79 ) {
V_76 [ 0 ] . V_87 = ( ( V_88 ) F_12 ( V_85 ) << 2 ) |
F_12 ( V_89 ) ;
V_76 [ 0 ] . V_90 = ( ( V_88 ) F_12 ( V_91 ) << 2 ) |
F_12 ( V_92 ) ;
V_76 [ 1 ] . V_87 = ( ( V_88 ) F_12 ( V_93 ) << 2 ) |
F_12 ( V_94 ) ;
V_76 [ 1 ] . V_90 = ( ( V_88 ) F_12 ( V_95 ) << 2 ) |
F_12 ( V_96 ) ;
}
switch ( V_79 ) {
case 0 :
V_80 = V_97 [ V_82 ] ;
if ( ++ V_18 -> V_98 [ 0 ] >= V_80 )
V_81 = 0 ;
break;
case V_99 :
V_80 = V_100 [ V_82 ] ;
if ( ++ V_18 -> V_98 [ 1 ] >= V_80 )
V_81 = 1 ;
if ( V_81 == 1 ) {
if ( V_76 [ 1 ] . V_87 != 0 && V_76 [ 1 ] . V_90 != 0 ) {
V_76 [ 0 ] . V_87 = V_76 [ 1 ] . V_87 ;
V_76 [ 0 ] . V_90 = V_76 [ 1 ] . V_90 ;
V_76 [ 1 ] . V_87 = 0 ;
V_76 [ 1 ] . V_90 = 0 ;
}
}
break;
case V_101 :
V_80 = V_102 [ V_82 ] ;
if ( ++ V_18 -> V_98 [ 2 ] >= V_80 )
V_81 = 2 ;
break;
default:
F_13 ( V_20 ,
L_2 ) ;
return V_84 ;
}
if ( V_81 >= 0 ) {
if ( V_82 != V_81 ) {
V_83 = V_18 -> V_98 [ V_81 ] ;
memset ( V_18 -> V_98 , 0 , sizeof( V_18 -> V_98 ) ) ;
V_18 -> V_98 [ V_81 ] = V_83 ;
}
F_14 ( V_73 , V_78 , V_76 ,
V_81 , V_103 ) ;
for ( V_11 = 0 ; V_11 < V_81 ; V_11 ++ ) {
F_15 ( V_73 , V_78 [ V_11 ] ) ;
F_16 ( V_73 ,
V_104 , true ) ;
F_17 ( V_73 ,
V_105 , V_76 [ V_11 ] . V_87 ) ;
F_17 ( V_73 ,
V_106 , V_76 [ V_11 ] . V_90 ) ;
}
F_18 ( V_73 ) ;
F_19 ( V_73 , true ) ;
F_20 ( V_73 ) ;
V_18 -> V_81 = V_81 ;
}
if ( F_12 ( V_65 ) & V_107 ) {
error = F_5 ( V_18 ) ;
if ( error )
F_10 ( V_20 , L_3 ,
error ) ;
}
F_7 ( V_2 , V_42 ,
V_68 | V_45 | V_44 |
V_46 ) ;
return V_84 ;
}
static int F_21 ( struct V_1 * V_2 ,
const char * V_108 )
{
struct V_19 * V_20 = & V_2 -> V_20 ;
const struct V_109 * V_110 ;
T_3 V_111 ;
unsigned int V_112 , V_5 , V_113 ;
unsigned int V_21 = 0 ;
int error , V_38 ;
error = F_22 ( & V_110 , V_108 , V_20 ) ;
if ( error ) {
F_23 ( V_20 , L_4 ,
V_108 , error ) ;
return error ;
}
error = F_7 ( V_2 , V_42 ,
V_43 | V_68 |
V_44 | V_45 ) ;
if ( error )
goto V_47;
do {
if ( V_21 ) {
F_10 ( V_20 , L_5 ) ;
error = F_7 ( V_2 , V_114 , 0 ) ;
if ( error )
goto V_47;
}
error = F_7 ( V_2 , V_115 , 0 ) ;
if ( error )
goto V_47;
error = F_7 ( V_2 , V_116 , 0 ) ;
if ( error )
goto V_47;
error = F_7 ( V_2 , V_117 ,
V_118 ) ;
if ( error )
goto V_47;
V_112 = 0 ;
V_5 = V_110 -> V_119 ;
while ( V_5 ) {
V_113 = F_24 ( V_120 , V_5 ) ;
error = F_25 ( V_2 , V_114 ,
V_113 , & V_110 -> V_121 [ V_112 ] ) ;
if ( error )
goto V_47;
V_5 -= V_113 ;
V_112 += V_113 ;
}
V_111 = F_6 ( V_2 , V_67 ) ;
if ( V_111 < 0 ) {
error = V_111 ;
goto V_47;
}
error = F_7 ( V_2 , V_64 , 0xff ) ;
if ( error )
goto V_47;
if ( V_111 == V_46 )
break;
error = - V_16 ;
} while ( ++ V_21 <= V_122 );
V_47:
V_38 = F_7 ( V_2 , V_42 , V_70 ) ;
F_26 ( V_110 ) ;
return error ? error : V_38 ;
}
static T_6 F_27 ( struct V_19 * V_20 , struct V_123 * V_124 ,
char * V_4 )
{
struct V_1 * V_2 = F_28 ( V_20 ) ;
struct V_17 * V_18 = F_29 ( V_2 ) ;
return sprintf ( V_4 , L_6 , ! ! ( V_18 -> V_125 & V_126 ) ) ;
}
static T_6 F_30 ( struct V_19 * V_20 , struct V_123 * V_124 ,
const char * V_4 , T_2 V_83 )
{
struct V_1 * V_2 = F_28 ( V_20 ) ;
struct V_17 * V_18 = F_29 ( V_2 ) ;
unsigned int V_31 ;
int error ;
error = F_31 ( V_4 , 0 , & V_31 ) ;
if ( error )
return error ;
error = F_32 ( & V_18 -> V_74 -> V_127 ) ;
if ( error )
return error ;
if ( V_31 )
V_18 -> V_125 |= V_126 ;
else
V_18 -> V_125 &= ~ V_126 ;
if ( V_18 -> V_128 )
error = F_7 ( V_18 -> V_2 , V_129 ,
V_18 -> V_125 ) ;
F_33 ( & V_18 -> V_74 -> V_127 ) ;
return error ? error : V_83 ;
}
static T_6 F_34 ( struct V_19 * V_20 , struct V_123 * V_124 ,
char * V_4 )
{
struct V_1 * V_2 = F_28 ( V_20 ) ;
struct V_17 * V_18 = F_29 ( V_2 ) ;
return sprintf ( V_4 , L_6 , ! ! ( V_18 -> V_125 & V_130 ) ) ;
}
static T_6 F_35 ( struct V_19 * V_20 , struct V_123 * V_124 ,
const char * V_4 , T_2 V_83 )
{
struct V_1 * V_2 = F_28 ( V_20 ) ;
struct V_17 * V_18 = F_29 ( V_2 ) ;
unsigned int V_31 ;
int error ;
error = F_31 ( V_4 , 0 , & V_31 ) ;
if ( error )
return error ;
error = F_32 ( & V_18 -> V_74 -> V_127 ) ;
if ( error )
return error ;
if ( V_31 )
V_18 -> V_125 |= V_130 ;
else
V_18 -> V_125 &= ~ V_130 ;
if ( V_18 -> V_128 )
error = F_7 ( V_18 -> V_2 , V_129 ,
V_18 -> V_125 ) ;
F_33 ( & V_18 -> V_74 -> V_127 ) ;
return error ? error : V_83 ;
}
static T_6 F_36 ( struct V_19 * V_20 , struct V_123 * V_124 ,
char * V_4 )
{
struct V_1 * V_2 = F_28 ( V_20 ) ;
struct V_17 * V_18 = F_29 ( V_2 ) ;
return sprintf ( V_4 , L_6 , ! ! ( V_18 -> V_125 & V_131 ) ) ;
}
static T_6 F_37 ( struct V_19 * V_20 , struct V_123 * V_124 ,
const char * V_4 , T_2 V_83 )
{
struct V_1 * V_2 = F_28 ( V_20 ) ;
struct V_17 * V_18 = F_29 ( V_2 ) ;
unsigned int V_31 ;
int error ;
error = F_31 ( V_4 , 0 , & V_31 ) ;
if ( error )
return error ;
error = F_32 ( & V_18 -> V_74 -> V_127 ) ;
if ( error )
return error ;
if ( V_31 )
V_18 -> V_125 |= V_131 ;
else
V_18 -> V_125 &= ~ V_131 ;
if ( V_18 -> V_128 )
error = F_7 ( V_2 , V_129 ,
V_18 -> V_125 ) ;
F_33 ( & V_18 -> V_74 -> V_127 ) ;
return error ? error : V_83 ;
}
static int F_38 ( struct V_1 * V_2 , T_1 V_125 )
{
struct V_19 * V_20 = & V_2 -> V_20 ;
int error ;
F_39 ( V_2 -> V_71 ) ;
F_40 ( 200 ) ;
error = F_7 ( V_2 , SYSTEM ,
V_132 | V_133 ) ;
if ( error )
return error ;
F_40 ( 200 ) ;
error = F_7 ( V_2 , V_64 , 0xff ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_114 , 0 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_117 , 0 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_129 , V_125 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_134 ,
V_135 | V_136 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_137 ,
V_138 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_139 ,
V_140 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_141 , V_142 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_143 ,
V_144 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_145 , V_146 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_147 , V_148 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_149 , V_150 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_151 , V_152 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_153 , V_154 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_155 , V_156 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_157 ,
V_158 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_159 , V_160 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_161 , V_162 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_163 , V_164 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_165 ,
V_166 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_167 , V_168 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_48 ,
V_49 |
V_59 ) ;
if ( error )
return error ;
error = F_21 ( V_2 , V_169 ) ;
if ( error ) {
F_23 ( V_20 , L_7 , error ) ;
return error ;
}
error = F_7 ( V_2 , V_39 ,
V_170 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_40 ,
V_171 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_41 ,
V_172 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_61 ,
V_62 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_61 ,
V_63 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_64 , 0xff ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_42 ,
V_68 | V_45 |
V_44 | V_46 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , V_173 ,
V_174 | V_175 |
V_176 ) ;
if ( error )
return error ;
error = F_7 ( V_2 , SYSTEM ,
V_132 | V_177 ) ;
F_41 ( V_2 -> V_71 ) ;
return error ;
}
static int F_42 ( struct V_1 * V_2 )
{
int error ;
error = F_7 ( V_2 , SYSTEM ,
V_132 | V_133 ) ;
if ( error ) {
F_23 ( & V_2 -> V_20 ,
L_8 , error ) ;
return error ;
}
error = F_7 ( V_2 , SYSTEM ,
V_178 | V_133 ) ;
if ( error )
F_23 ( & V_2 -> V_20 ,
L_9 , error ) ;
return error ;
}
static int F_43 ( struct V_73 * V_73 )
{
struct V_17 * V_18 = F_44 ( V_73 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
int error ;
if ( ! V_18 -> V_128 ) {
error = F_38 ( V_2 , V_18 -> V_125 ) ;
if ( error ) {
F_23 ( & V_2 -> V_20 ,
L_10 , error ) ;
return error ;
}
V_18 -> V_128 = true ;
}
return 0 ;
}
static void F_45 ( struct V_73 * V_73 )
{
struct V_17 * V_18 = F_44 ( V_73 ) ;
F_42 ( V_18 -> V_2 ) ;
V_18 -> V_128 = false ;
}
static void F_46 ( void * V_179 )
{
struct V_19 * V_20 = V_179 ;
F_47 ( & V_20 -> V_180 , & V_181 ) ;
}
static int F_48 ( struct V_1 * V_2 ,
const struct V_182 * V_183 )
{
struct V_19 * V_20 = & V_2 -> V_20 ;
struct V_17 * V_18 ;
struct V_73 * V_74 ;
int error ;
if ( ! V_2 -> V_71 ) {
F_23 ( V_20 , L_11 ) ;
return - V_184 ;
}
if ( ! V_2 -> V_8 -> V_185 -> V_186 ) {
F_23 ( V_20 , L_12 ) ;
return - V_187 ;
}
error = F_42 ( V_2 ) ;
if ( error )
return error ;
V_18 = F_49 ( V_20 , sizeof( struct V_17 ) , V_188 ) ;
if ( ! V_18 )
return - V_189 ;
V_18 -> V_2 = V_2 ;
V_18 -> V_125 = V_190 ;
F_50 ( V_2 , V_18 ) ;
V_74 = F_51 ( V_20 ) ;
if ( ! V_74 )
return - V_189 ;
V_74 -> V_191 = V_192 ;
V_74 -> V_183 . V_193 = V_194 ;
V_74 -> V_195 = F_43 ;
V_74 -> V_196 = F_45 ;
V_18 -> V_74 = V_74 ;
F_52 ( V_74 , V_18 ) ;
F_53 ( V_74 , V_105 ,
V_197 , V_198 , 0 , 0 ) ;
F_53 ( V_74 , V_106 ,
V_199 , V_200 , 0 , 0 ) ;
error = F_54 ( V_74 , V_77 ,
V_201 | V_202 |
V_203 ) ;
if ( error ) {
F_23 ( V_20 , L_13 ) ;
return error ;
}
error = F_55 ( V_20 , V_2 -> V_71 ,
NULL , F_11 ,
V_204 , V_2 -> V_191 , V_18 ) ;
if ( error ) {
F_23 ( V_20 , L_14 , error ) ;
return error ;
}
error = F_56 ( V_74 ) ;
if ( error ) {
F_23 ( V_20 , L_15 , error ) ;
return error ;
}
error = F_57 ( & V_20 -> V_180 , & V_181 ) ;
if ( error ) {
F_23 ( V_20 , L_16 , error ) ;
return error ;
}
error = F_58 ( V_20 , F_46 , V_20 ) ;
if ( error ) {
F_46 ( V_20 ) ;
F_23 ( & V_2 -> V_20 ,
L_17 ,
error ) ;
return error ;
}
return error ;
}
