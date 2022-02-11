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
F_2 ( V_37 -> V_59 , & V_38 -> V_59 ) ||
F_2 ( V_37 -> V_60 , & V_38 -> V_60 ) )
return - V_11 ;
return 0 ;
}
STATIC int
F_13 (
T_10 T_3 * V_27 ,
const T_9 * V_61 )
{
T_14 V_34 ;
V_34 = V_61 -> V_35 ;
if ( F_10 ( V_34 , & V_27 -> V_35 ) ||
F_10 ( V_61 -> V_36 , & V_27 -> V_36 ) )
return - V_11 ;
return 0 ;
}
STATIC int
F_14 (
void T_3 * V_22 ,
int V_62 ,
int * V_63 ,
const T_12 * V_24 )
{
T_13 T_3 * V_27 = V_22 ;
if ( V_62 < sizeof( * V_27 ) )
return - V_64 ;
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
F_10 ( V_24 -> V_65 , & V_27 -> V_65 ) ||
F_10 ( V_24 -> V_56 , & V_27 -> V_56 ) ||
F_10 ( V_24 -> V_57 , & V_27 -> V_57 ) ||
F_10 ( V_24 -> V_58 , & V_27 -> V_58 ) ||
F_10 ( V_24 -> V_59 , & V_27 -> V_59 ) ||
F_10 ( V_24 -> V_60 , & V_27 -> V_60 ) )
return - V_11 ;
if ( V_63 )
* V_63 = sizeof( * V_27 ) ;
return 0 ;
}
STATIC int
F_15 (
T_15 * V_13 ,
T_16 V_66 ,
void T_3 * V_24 ,
int V_62 ,
int * V_63 ,
int * V_67 )
{
return F_16 ( V_13 , V_66 , V_24 , V_62 ,
F_14 ,
V_63 , V_67 ) ;
}
STATIC int
F_17 (
T_15 * V_13 ,
unsigned int V_68 ,
T_17 T_3 * V_27 )
{
V_10 V_69 ;
T_18 V_70 ;
int V_25 ;
T_16 V_71 ;
int V_72 ;
int error ;
if ( ! F_18 ( V_73 ) )
return - V_74 ;
if ( F_19 ( V_13 ) )
return - V_75 ;
if ( F_2 ( V_69 , & V_27 -> V_76 ) )
return - V_11 ;
V_70 . V_76 = F_20 ( V_69 ) ;
if ( F_2 ( V_70 . V_77 , & V_27 -> V_77 ) ||
F_2 ( V_69 , & V_27 -> V_22 ) )
return - V_11 ;
V_70 . V_22 = F_20 ( V_69 ) ;
if ( F_2 ( V_69 , & V_27 -> V_78 ) )
return - V_11 ;
V_70 . V_78 = F_20 ( V_69 ) ;
if ( F_3 ( & V_71 , V_70 . V_76 , sizeof( V_79 ) ) )
return - V_11 ;
if ( ( V_25 = V_70 . V_77 ) <= 0 )
return - V_80 ;
if ( V_70 . V_22 == NULL )
return - V_80 ;
if ( V_68 == V_81 ) {
error = F_21 ( V_13 , & V_71 , & V_25 ,
V_70 . V_22 , F_9 ) ;
} else if ( V_68 == V_82 ) {
int V_83 ;
error = F_15 ( V_13 , V_71 , V_70 . V_22 ,
sizeof( T_13 ) , NULL , & V_83 ) ;
} else if ( V_68 == V_84 ) {
error = F_22 ( V_13 , & V_71 , & V_25 ,
F_15 , sizeof( T_13 ) ,
V_70 . V_22 , & V_72 ) ;
} else
error = - V_80 ;
if ( error )
return error ;
if ( V_70 . V_78 != NULL ) {
if ( F_6 ( V_70 . V_76 , & V_71 ,
sizeof( T_16 ) ) )
return - V_11 ;
if ( F_6 ( V_70 . V_78 , & V_25 , sizeof( V_25 ) ) )
return - V_11 ;
}
return 0 ;
}
STATIC int
F_23 (
T_19 * V_85 ,
T_20 T_3 * V_2 )
{
T_20 V_86 ;
if ( F_3 ( & V_86 , V_2 , sizeof( T_20 ) ) )
return - V_11 ;
V_85 -> V_87 = V_86 . V_87 ;
V_85 -> V_88 = F_20 ( V_86 . V_88 ) ;
V_85 -> V_89 = V_86 . V_89 ;
V_85 -> V_90 = F_20 ( V_86 . V_90 ) ;
V_85 -> V_91 = V_86 . V_91 ;
V_85 -> V_92 = F_20 ( V_86 . V_92 ) ;
V_85 -> V_93 = F_20 ( V_86 . V_93 ) ;
return 0 ;
}
STATIC struct V_94 *
F_24 (
struct V_95 * V_96 ,
T_20 * V_85 )
{
return F_25 ( V_96 ,
F_20 ( V_85 -> V_90 ) , V_85 -> V_91 ) ;
}
STATIC int
F_26 (
struct V_95 * V_96 ,
void T_3 * V_97 )
{
int error ;
T_21 * V_98 ;
T_22 V_99 ;
struct V_94 * V_94 ;
char * V_100 ;
if ( ! F_18 ( V_73 ) )
return - V_74 ;
if ( F_3 ( & V_99 , V_97 ,
sizeof( T_22 ) ) )
return - V_11 ;
if ( V_99 . V_101 < sizeof( struct V_102 ) ||
V_99 . V_101 > V_103 )
return - V_80 ;
if ( V_99 . V_104 & ~ ( V_105 | V_106 ) )
return - V_80 ;
V_94 = F_24 ( V_96 , & V_99 . V_85 ) ;
if ( F_27 ( V_94 ) )
return F_28 ( V_94 ) ;
error = - V_64 ;
V_100 = F_29 ( V_99 . V_101 , V_107 ) ;
if ( ! V_100 )
goto V_108;
V_98 = ( T_21 * ) & V_99 . V_109 ;
error = F_30 ( F_31 ( F_32 ( V_94 ) ) , V_100 , V_99 . V_101 ,
V_99 . V_104 , V_98 ) ;
if ( error )
goto V_110;
if ( F_6 ( F_20 ( V_99 . V_24 ) , V_100 , V_99 . V_101 ) )
error = - V_11 ;
V_110:
F_33 ( V_100 ) ;
V_108:
F_34 ( V_94 ) ;
return error ;
}
STATIC int
F_35 (
struct V_95 * V_96 ,
void T_3 * V_97 )
{
int error ;
T_23 * V_111 ;
T_24 V_112 ;
struct V_94 * V_94 ;
unsigned int V_28 , V_113 ;
unsigned char * V_114 ;
if ( ! F_18 ( V_73 ) )
return - V_74 ;
if ( F_3 ( & V_112 , V_97 ,
sizeof( T_24 ) ) )
return - V_11 ;
if ( V_112 . V_115 >= V_116 / sizeof( T_23 ) )
return - V_117 ;
V_94 = F_24 ( V_96 , & V_112 . V_85 ) ;
if ( F_27 ( V_94 ) )
return F_28 ( V_94 ) ;
error = - V_117 ;
V_113 = V_112 . V_115 * sizeof( T_23 ) ;
if ( ! V_113 || V_113 > 16 * V_118 )
goto V_108;
V_111 = F_36 ( F_20 ( V_112 . V_111 ) , V_113 ) ;
if ( F_27 ( V_111 ) ) {
error = F_28 ( V_111 ) ;
goto V_108;
}
error = - V_64 ;
V_114 = F_37 ( V_119 , V_120 ) ;
if ( ! V_114 )
goto V_121;
error = 0 ;
for ( V_28 = 0 ; V_28 < V_112 . V_115 ; V_28 ++ ) {
V_111 [ V_28 ] . V_122 = F_38 ( ( char * ) V_114 ,
F_20 ( V_111 [ V_28 ] . V_123 ) ,
V_119 ) ;
if ( V_111 [ V_28 ] . V_122 == 0 || V_111 [ V_28 ] . V_122 == V_119 )
error = - V_124 ;
if ( V_111 [ V_28 ] . V_122 < 0 )
break;
switch ( V_111 [ V_28 ] . V_125 ) {
case V_126 :
V_111 [ V_28 ] . V_122 = F_39 (
F_32 ( V_94 ) , V_114 ,
F_20 ( V_111 [ V_28 ] . V_127 ) ,
& V_111 [ V_28 ] . V_128 , V_111 [ V_28 ] . V_129 ) ;
break;
case V_130 :
V_111 [ V_28 ] . V_122 = F_40 ( V_96 ) ;
if ( V_111 [ V_28 ] . V_122 )
break;
V_111 [ V_28 ] . V_122 = F_41 (
F_32 ( V_94 ) , V_114 ,
F_20 ( V_111 [ V_28 ] . V_127 ) ,
V_111 [ V_28 ] . V_128 , V_111 [ V_28 ] . V_129 ) ;
F_42 ( V_96 ) ;
break;
case V_131 :
V_111 [ V_28 ] . V_122 = F_40 ( V_96 ) ;
if ( V_111 [ V_28 ] . V_122 )
break;
V_111 [ V_28 ] . V_122 = F_43 (
F_32 ( V_94 ) , V_114 ,
V_111 [ V_28 ] . V_129 ) ;
F_42 ( V_96 ) ;
break;
default:
V_111 [ V_28 ] . V_122 = - V_80 ;
}
}
if ( F_6 ( F_20 ( V_112 . V_111 ) , V_111 , V_113 ) )
error = - V_11 ;
F_44 ( V_114 ) ;
V_121:
F_44 ( V_111 ) ;
V_108:
F_34 ( V_94 ) ;
return error ;
}
STATIC int
F_45 (
struct V_95 * V_96 ,
void T_3 * V_97 )
{
int error ;
struct V_132 V_133 ;
T_25 V_134 ;
struct V_94 * V_94 ;
if ( ! F_18 ( V_135 ) )
return - V_74 ;
if ( F_3 ( & V_134 , V_97 ,
sizeof( T_25 ) ) )
return - V_11 ;
V_94 = F_24 ( V_96 , & V_134 . V_85 ) ;
if ( F_27 ( V_94 ) )
return F_28 ( V_94 ) ;
if ( F_46 ( F_32 ( V_94 ) ) || F_47 ( F_32 ( V_94 ) ) ) {
error = - V_74 ;
goto V_136;
}
if ( F_3 ( & V_133 , F_20 ( V_134 . V_137 ) , sizeof( V_133 ) ) ) {
error = - V_11 ;
goto V_136;
}
error = F_48 ( F_31 ( F_32 ( V_94 ) ) , V_133 . V_138 ,
V_133 . V_139 ) ;
V_136:
F_34 ( V_94 ) ;
return error ;
}
long
F_49 (
struct V_95 * V_140 ,
unsigned V_68 ,
unsigned long V_61 )
{
struct V_141 * V_141 = F_50 ( V_140 ) ;
struct V_142 * V_143 = F_31 ( V_141 ) ;
struct V_12 * V_13 = V_143 -> V_144 ;
void T_3 * V_97 = ( void T_3 * ) V_61 ;
int error ;
F_51 ( V_143 ) ;
switch ( V_68 ) {
case V_145 :
case V_146 :
case V_147 :
case V_148 :
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
return F_52 ( V_140 , V_68 , V_61 ) ;
#ifndef F_53
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
return F_52 ( V_140 , V_68 , V_61 ) ;
#else
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 : {
struct V_183 V_1 ;
if ( F_1 ( & V_1 , V_97 ) )
return - V_11 ;
V_68 = F_54 ( V_68 , struct V_183 ) ;
return F_55 ( V_140 , V_68 , & V_1 ) ;
}
case V_184 :
return F_4 ( V_13 , V_97 ) ;
case V_185 : {
struct V_16 V_17 ;
if ( F_7 ( & V_17 , V_97 ) )
return - V_11 ;
error = F_40 ( V_140 ) ;
if ( error )
return error ;
error = V_16 ( V_13 , & V_17 ) ;
F_42 ( V_140 ) ;
return error ;
}
case V_186 : {
struct V_20 V_17 ;
if ( F_8 ( & V_17 , V_97 ) )
return - V_11 ;
error = F_40 ( V_140 ) ;
if ( error )
return error ;
error = V_20 ( V_13 , & V_17 ) ;
F_42 ( V_140 ) ;
return error ;
}
#endif
case V_187 :
case V_188 :
case V_189 :
V_68 = F_54 ( V_68 , long ) ;
return F_52 ( V_140 , V_68 , V_61 ) ;
case V_190 : {
struct V_191 V_192 ;
struct V_193 T_3 * V_194 = V_97 ;
if ( F_3 ( & V_192 , V_194 ,
F_56 ( struct V_191 , V_195 ) ) ||
F_12 ( & V_192 . V_195 , & V_194 -> V_195 ) )
return - V_11 ;
error = F_40 ( V_140 ) ;
if ( error )
return error ;
error = F_57 ( & V_192 ) ;
F_42 ( V_140 ) ;
return error ;
}
case V_84 :
case V_82 :
case V_81 :
return F_17 ( V_13 , V_68 , V_97 ) ;
case V_196 :
case V_197 :
case V_198 : {
struct V_199 V_85 ;
if ( F_23 ( & V_85 , V_97 ) )
return - V_11 ;
V_68 = F_54 ( V_68 , struct V_199 ) ;
return F_58 ( V_68 , & V_85 ) ;
}
case V_200 : {
struct V_199 V_85 ;
if ( F_23 ( & V_85 , V_97 ) )
return - V_11 ;
return F_59 ( V_140 , & V_85 ) ;
}
case V_201 : {
struct V_199 V_85 ;
if ( F_23 ( & V_85 , V_97 ) )
return - V_11 ;
return F_60 ( V_140 , & V_85 ) ;
}
case V_202 :
return F_26 ( V_140 , V_97 ) ;
case V_203 :
return F_35 ( V_140 , V_97 ) ;
case V_204 :
return F_45 ( V_140 , V_97 ) ;
default:
return - V_205 ;
}
}
