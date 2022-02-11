STATIC int
F_1 (
T_1 * V_1 ,
T_2 T_3 * V_2 )
{
if ( F_2 ( V_1 -> V_3 , & V_2 -> V_3 ) ||
F_2 ( V_1 -> V_4 , & V_2 -> V_4 ) ||
F_2 ( V_1 -> V_5 , & V_2 -> V_5 ) ||
F_2 ( V_1 -> V_6 , & V_2 -> V_6 ) ||
F_2 ( V_1 -> V_7 , & V_2 -> V_7 ) ||
F_2 ( V_1 -> V_8 , & V_2 -> V_8 ) ||
F_3 ( V_1 -> V_9 , & V_2 -> V_9 , 4 * sizeof( V_10 ) ) )
return - V_11 ;
return 0 ;
}
STATIC int
F_4 (
struct V_12 * V_13 ,
T_4 T_3 * V_2 )
{
T_5 V_14 ;
int error ;
error = F_5 ( V_13 , & V_14 , 3 ) ;
if ( error )
return error ;
if ( F_6 ( V_2 , & V_14 , sizeof( struct V_15 ) ) )
return - V_11 ;
return 0 ;
}
STATIC int
F_7 (
struct V_16 * V_17 ,
T_6 T_3 * V_2 )
{
if ( F_2 ( V_17 -> V_18 , & V_2 -> V_18 ) ||
F_2 ( V_17 -> V_19 , & V_2 -> V_19 ) )
return - V_11 ;
return 0 ;
}
STATIC int
F_8 (
struct V_20 * V_17 ,
T_7 T_3 * V_2 )
{
if ( F_2 ( V_17 -> V_18 , & V_2 -> V_18 ) ||
F_2 ( V_17 -> V_21 , & V_2 -> V_21 ) )
return - V_11 ;
return 0 ;
}
STATIC int
F_9 (
void T_3 * V_22 ,
const struct V_23 * V_24 ,
long V_25 ,
long * V_26 )
{
T_8 T_3 * V_27 = V_22 ;
long V_28 ;
for ( V_28 = 0 ; V_28 < V_25 ; V_28 ++ ) {
if ( F_10 ( V_24 [ V_28 ] . V_29 , & V_27 [ V_28 ] . V_29 ) ||
F_10 ( V_24 [ V_28 ] . V_30 , & V_27 [ V_28 ] . V_30 ) ||
F_10 ( V_24 [ V_28 ] . V_31 , & V_27 [ V_28 ] . V_31 ) )
return - V_11 ;
}
* V_26 = V_25 * sizeof( * V_27 ) ;
return 0 ;
}
STATIC int
F_11 (
T_9 * V_32 ,
T_10 T_3 * V_33 )
{
T_11 V_34 ;
if ( F_2 ( V_34 , & V_33 -> V_35 ) ||
F_2 ( V_32 -> V_36 , & V_33 -> V_36 ) )
return - V_11 ;
V_32 -> V_35 = V_34 ;
return 0 ;
}
STATIC int
F_12 (
T_12 * V_37 ,
T_13 T_3 * V_38 )
{
if ( F_2 ( V_37 -> V_39 , & V_38 -> V_39 ) ||
F_2 ( V_37 -> V_40 , & V_38 -> V_40 ) ||
F_2 ( V_37 -> V_41 , & V_38 -> V_41 ) ||
F_2 ( V_37 -> V_42 , & V_38 -> V_42 ) ||
F_2 ( V_37 -> V_43 , & V_38 -> V_43 ) ||
F_2 ( V_37 -> V_44 , & V_38 -> V_44 ) ||
F_2 ( V_37 -> V_45 , & V_38 -> V_45 ) ||
F_2 ( V_37 -> V_46 , & V_38 -> V_46 ) ||
F_11 ( & V_37 -> V_47 , & V_38 -> V_47 ) ||
F_11 ( & V_37 -> V_48 , & V_38 -> V_48 ) ||
F_11 ( & V_37 -> V_49 , & V_38 -> V_49 ) ||
F_2 ( V_37 -> V_50 , & V_38 -> V_46 ) ||
F_2 ( V_37 -> V_51 , & V_38 -> V_46 ) ||
F_2 ( V_37 -> V_52 , & V_38 -> V_52 ) ||
F_2 ( V_37 -> V_53 , & V_38 -> V_53 ) ||
F_2 ( V_37 -> V_54 , & V_38 -> V_54 ) ||
F_2 ( V_37 -> V_55 , & V_38 -> V_55 ) ||
F_2 ( V_37 -> V_56 , & V_38 -> V_56 ) ||
F_2 ( V_37 -> V_57 , & V_38 -> V_57 ) ||
F_2 ( V_37 -> V_58 , & V_38 -> V_58 ) ||
F_2 ( V_37 -> V_59 , & V_38 -> V_59 ) )
return - V_11 ;
return 0 ;
}
STATIC int
F_13 (
T_10 T_3 * V_27 ,
const T_9 * V_60 )
{
T_14 V_34 ;
V_34 = V_60 -> V_35 ;
if ( F_10 ( V_34 , & V_27 -> V_35 ) ||
F_10 ( V_60 -> V_36 , & V_27 -> V_36 ) )
return - V_11 ;
return 0 ;
}
STATIC int
F_14 (
void T_3 * V_22 ,
int V_61 ,
int * V_62 ,
const T_12 * V_24 )
{
T_13 T_3 * V_27 = V_22 ;
if ( V_61 < sizeof( * V_27 ) )
return - V_63 ;
if ( F_10 ( V_24 -> V_39 , & V_27 -> V_39 ) ||
F_10 ( V_24 -> V_40 , & V_27 -> V_40 ) ||
F_10 ( V_24 -> V_41 , & V_27 -> V_41 ) ||
F_10 ( V_24 -> V_42 , & V_27 -> V_42 ) ||
F_10 ( V_24 -> V_43 , & V_27 -> V_43 ) ||
F_10 ( V_24 -> V_44 , & V_27 -> V_44 ) ||
F_10 ( V_24 -> V_45 , & V_27 -> V_45 ) ||
F_10 ( V_24 -> V_46 , & V_27 -> V_46 ) ||
F_13 ( & V_27 -> V_47 , & V_24 -> V_47 ) ||
F_13 ( & V_27 -> V_48 , & V_24 -> V_48 ) ||
F_13 ( & V_27 -> V_49 , & V_24 -> V_49 ) ||
F_10 ( V_24 -> V_50 , & V_27 -> V_50 ) ||
F_10 ( V_24 -> V_51 , & V_27 -> V_51 ) ||
F_10 ( V_24 -> V_52 , & V_27 -> V_52 ) ||
F_10 ( V_24 -> V_53 , & V_27 -> V_53 ) ||
F_10 ( V_24 -> V_54 , & V_27 -> V_54 ) ||
F_10 ( V_24 -> V_64 , & V_27 -> V_64 ) ||
F_10 ( V_24 -> V_56 , & V_27 -> V_56 ) ||
F_10 ( V_24 -> V_57 , & V_27 -> V_57 ) ||
F_10 ( V_24 -> V_58 , & V_27 -> V_58 ) ||
F_10 ( V_24 -> V_59 , & V_27 -> V_59 ) )
return - V_11 ;
if ( V_62 )
* V_62 = sizeof( * V_27 ) ;
return 0 ;
}
STATIC int
F_15 (
T_15 * V_13 ,
T_16 V_65 ,
void T_3 * V_24 ,
int V_61 ,
int * V_62 ,
int * V_66 )
{
return F_16 ( V_13 , V_65 , V_24 , V_61 ,
F_14 ,
V_62 , V_66 ) ;
}
STATIC int
F_17 (
T_15 * V_13 ,
unsigned int V_67 ,
T_17 T_3 * V_27 )
{
V_10 V_68 ;
T_18 V_69 ;
int V_25 ;
T_16 V_70 ;
int V_71 ;
int error ;
if ( ! F_18 ( V_72 ) )
return - V_73 ;
if ( F_19 ( V_13 ) )
return - V_74 ;
if ( F_2 ( V_68 , & V_27 -> V_75 ) )
return - V_11 ;
V_69 . V_75 = F_20 ( V_68 ) ;
if ( F_2 ( V_69 . V_76 , & V_27 -> V_76 ) ||
F_2 ( V_68 , & V_27 -> V_22 ) )
return - V_11 ;
V_69 . V_22 = F_20 ( V_68 ) ;
if ( F_2 ( V_68 , & V_27 -> V_77 ) )
return - V_11 ;
V_69 . V_77 = F_20 ( V_68 ) ;
if ( F_3 ( & V_70 , V_69 . V_75 , sizeof( V_78 ) ) )
return - V_11 ;
if ( ( V_25 = V_69 . V_76 ) <= 0 )
return - V_79 ;
if ( V_69 . V_22 == NULL )
return - V_79 ;
if ( V_67 == V_80 ) {
error = F_21 ( V_13 , & V_70 , & V_25 ,
V_69 . V_22 , F_9 ) ;
} else if ( V_67 == V_81 ) {
int V_82 ;
error = F_15 ( V_13 , V_70 , V_69 . V_22 ,
sizeof( T_13 ) , NULL , & V_82 ) ;
} else if ( V_67 == V_83 ) {
error = F_22 ( V_13 , & V_70 , & V_25 ,
F_15 , sizeof( T_13 ) ,
V_69 . V_22 , & V_71 ) ;
} else
error = - V_79 ;
if ( error )
return error ;
if ( V_69 . V_77 != NULL ) {
if ( F_6 ( V_69 . V_75 , & V_70 ,
sizeof( T_16 ) ) )
return - V_11 ;
if ( F_6 ( V_69 . V_77 , & V_25 , sizeof( V_25 ) ) )
return - V_11 ;
}
return 0 ;
}
STATIC int
F_23 (
T_19 * V_84 ,
T_20 T_3 * V_2 )
{
T_20 V_85 ;
if ( F_3 ( & V_85 , V_2 , sizeof( T_20 ) ) )
return - V_11 ;
V_84 -> V_86 = V_85 . V_86 ;
V_84 -> V_87 = F_20 ( V_85 . V_87 ) ;
V_84 -> V_88 = V_85 . V_88 ;
V_84 -> V_89 = F_20 ( V_85 . V_89 ) ;
V_84 -> V_90 = V_85 . V_90 ;
V_84 -> V_91 = F_20 ( V_85 . V_91 ) ;
V_84 -> V_92 = F_20 ( V_85 . V_92 ) ;
return 0 ;
}
STATIC struct V_93 *
F_24 (
struct V_94 * V_95 ,
T_20 * V_84 )
{
return F_25 ( V_95 ,
F_20 ( V_84 -> V_89 ) , V_84 -> V_90 ) ;
}
STATIC int
F_26 (
struct V_94 * V_95 ,
void T_3 * V_96 )
{
int error ;
T_21 * V_97 ;
T_22 V_98 ;
struct V_93 * V_93 ;
char * V_99 ;
if ( ! F_18 ( V_72 ) )
return - V_73 ;
if ( F_3 ( & V_98 , V_96 ,
sizeof( T_22 ) ) )
return - V_11 ;
if ( V_98 . V_100 < sizeof( struct V_101 ) ||
V_98 . V_100 > V_102 )
return - V_79 ;
if ( V_98 . V_103 & ~ ( V_104 | V_105 ) )
return - V_79 ;
V_93 = F_24 ( V_95 , & V_98 . V_84 ) ;
if ( F_27 ( V_93 ) )
return F_28 ( V_93 ) ;
error = - V_63 ;
V_99 = F_29 ( V_98 . V_100 , V_106 ) ;
if ( ! V_99 )
goto V_107;
V_97 = ( T_21 * ) & V_98 . V_108 ;
error = F_30 ( F_31 ( V_93 -> V_109 ) , V_99 , V_98 . V_100 ,
V_98 . V_103 , V_97 ) ;
if ( error )
goto V_110;
if ( F_6 ( F_20 ( V_98 . V_24 ) , V_99 , V_98 . V_100 ) )
error = - V_11 ;
V_110:
F_32 ( V_99 ) ;
V_107:
F_33 ( V_93 ) ;
return error ;
}
STATIC int
F_34 (
struct V_94 * V_95 ,
void T_3 * V_96 )
{
int error ;
T_23 * V_111 ;
T_24 V_112 ;
struct V_93 * V_93 ;
unsigned int V_28 , V_113 ;
unsigned char * V_114 ;
if ( ! F_18 ( V_72 ) )
return - V_73 ;
if ( F_3 ( & V_112 , V_96 ,
sizeof( T_24 ) ) )
return - V_11 ;
if ( V_112 . V_115 >= V_116 / sizeof( T_23 ) )
return - V_117 ;
V_93 = F_24 ( V_95 , & V_112 . V_84 ) ;
if ( F_27 ( V_93 ) )
return F_28 ( V_93 ) ;
error = - V_117 ;
V_113 = V_112 . V_115 * sizeof( T_23 ) ;
if ( ! V_113 || V_113 > 16 * V_118 )
goto V_107;
V_111 = F_35 ( F_20 ( V_112 . V_111 ) , V_113 ) ;
if ( F_27 ( V_111 ) ) {
error = - F_28 ( V_111 ) ;
goto V_107;
}
error = - V_63 ;
V_114 = F_36 ( V_119 , V_120 ) ;
if ( ! V_114 )
goto V_121;
error = 0 ;
for ( V_28 = 0 ; V_28 < V_112 . V_115 ; V_28 ++ ) {
V_111 [ V_28 ] . V_122 = F_37 ( ( char * ) V_114 ,
F_20 ( V_111 [ V_28 ] . V_123 ) ,
V_119 ) ;
if ( V_111 [ V_28 ] . V_122 == 0 || V_111 [ V_28 ] . V_122 == V_119 )
error = - V_124 ;
if ( V_111 [ V_28 ] . V_122 < 0 )
break;
switch ( V_111 [ V_28 ] . V_125 ) {
case V_126 :
V_111 [ V_28 ] . V_122 = F_38 (
V_93 -> V_109 , V_114 ,
F_20 ( V_111 [ V_28 ] . V_127 ) ,
& V_111 [ V_28 ] . V_128 , V_111 [ V_28 ] . V_129 ) ;
break;
case V_130 :
V_111 [ V_28 ] . V_122 = F_39 ( V_95 ) ;
if ( V_111 [ V_28 ] . V_122 )
break;
V_111 [ V_28 ] . V_122 = F_40 (
V_93 -> V_109 , V_114 ,
F_20 ( V_111 [ V_28 ] . V_127 ) ,
V_111 [ V_28 ] . V_128 , V_111 [ V_28 ] . V_129 ) ;
F_41 ( V_95 ) ;
break;
case V_131 :
V_111 [ V_28 ] . V_122 = F_39 ( V_95 ) ;
if ( V_111 [ V_28 ] . V_122 )
break;
V_111 [ V_28 ] . V_122 = F_42 (
V_93 -> V_109 , V_114 ,
V_111 [ V_28 ] . V_129 ) ;
F_41 ( V_95 ) ;
break;
default:
V_111 [ V_28 ] . V_122 = - V_79 ;
}
}
if ( F_6 ( F_20 ( V_112 . V_111 ) , V_111 , V_113 ) )
error = - V_11 ;
F_43 ( V_114 ) ;
V_121:
F_43 ( V_111 ) ;
V_107:
F_33 ( V_93 ) ;
return error ;
}
STATIC int
F_44 (
struct V_94 * V_95 ,
void T_3 * V_96 )
{
int error ;
struct V_132 V_133 ;
T_25 V_134 ;
struct V_93 * V_93 ;
if ( ! F_18 ( V_135 ) )
return - V_73 ;
if ( F_3 ( & V_134 , V_96 ,
sizeof( T_25 ) ) )
return - V_11 ;
V_93 = F_24 ( V_95 , & V_134 . V_84 ) ;
if ( F_27 ( V_93 ) )
return F_28 ( V_93 ) ;
if ( F_45 ( V_93 -> V_109 ) || F_46 ( V_93 -> V_109 ) ) {
error = - V_73 ;
goto V_136;
}
if ( F_3 ( & V_133 , F_20 ( V_134 . V_137 ) , sizeof( V_133 ) ) ) {
error = - V_11 ;
goto V_136;
}
error = F_47 ( F_31 ( V_93 -> V_109 ) , V_133 . V_138 ,
V_133 . V_139 ) ;
V_136:
F_33 ( V_93 ) ;
return error ;
}
long
F_48 (
struct V_94 * V_140 ,
unsigned V_67 ,
unsigned long V_60 )
{
struct V_141 * V_141 = F_49 ( V_140 ) ;
struct V_142 * V_143 = F_31 ( V_141 ) ;
struct V_12 * V_13 = V_143 -> V_144 ;
void T_3 * V_96 = ( void T_3 * ) V_60 ;
int V_145 = 0 ;
int error ;
if ( V_140 -> V_146 & V_147 )
V_145 |= V_148 ;
F_50 ( V_143 ) ;
switch ( V_67 ) {
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
return F_51 ( V_140 , V_67 , V_60 ) ;
#ifndef F_52
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
return F_51 ( V_140 , V_67 , V_60 ) ;
#else
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 : {
struct V_186 V_1 ;
if ( F_1 ( & V_1 , V_96 ) )
return - V_11 ;
V_67 = F_53 ( V_67 , struct V_186 ) ;
return F_54 ( V_143 , V_141 , V_140 , V_145 , V_67 , & V_1 ) ;
}
case V_187 :
return F_4 ( V_13 , V_96 ) ;
case V_188 : {
struct V_16 V_17 ;
if ( F_7 ( & V_17 , V_96 ) )
return - V_11 ;
error = F_39 ( V_140 ) ;
if ( error )
return error ;
error = V_16 ( V_13 , & V_17 ) ;
F_41 ( V_140 ) ;
return error ;
}
case V_189 : {
struct V_20 V_17 ;
if ( F_8 ( & V_17 , V_96 ) )
return - V_11 ;
error = F_39 ( V_140 ) ;
if ( error )
return error ;
error = V_20 ( V_13 , & V_17 ) ;
F_41 ( V_140 ) ;
return error ;
}
#endif
case V_190 :
case V_191 :
case V_192 :
V_67 = F_53 ( V_67 , long ) ;
return F_51 ( V_140 , V_67 , V_60 ) ;
case V_193 : {
struct V_194 V_195 ;
struct V_196 T_3 * V_197 = V_96 ;
if ( F_3 ( & V_195 , V_197 ,
F_55 ( struct V_194 , V_198 ) ) ||
F_12 ( & V_195 . V_198 , & V_197 -> V_198 ) )
return - V_11 ;
error = F_39 ( V_140 ) ;
if ( error )
return error ;
error = F_56 ( & V_195 ) ;
F_41 ( V_140 ) ;
return error ;
}
case V_83 :
case V_81 :
case V_80 :
return F_17 ( V_13 , V_67 , V_96 ) ;
case V_199 :
case V_200 :
case V_201 : {
struct V_202 V_84 ;
if ( F_23 ( & V_84 , V_96 ) )
return - V_11 ;
V_67 = F_53 ( V_67 , struct V_202 ) ;
return F_57 ( V_67 , & V_84 ) ;
}
case V_203 : {
struct V_202 V_84 ;
if ( F_23 ( & V_84 , V_96 ) )
return - V_11 ;
return F_58 ( V_140 , & V_84 ) ;
}
case V_204 : {
struct V_202 V_84 ;
if ( F_23 ( & V_84 , V_96 ) )
return - V_11 ;
return F_59 ( V_140 , & V_84 ) ;
}
case V_205 :
return F_26 ( V_140 , V_96 ) ;
case V_206 :
return F_34 ( V_140 , V_96 ) ;
case V_207 :
return F_44 ( V_140 , V_96 ) ;
default:
return - V_208 ;
}
}
