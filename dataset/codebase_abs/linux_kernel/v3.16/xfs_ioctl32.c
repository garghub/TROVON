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
return - F_4 ( V_11 ) ;
return 0 ;
}
STATIC int
F_5 (
struct V_12 * V_13 ,
T_4 T_3 * V_2 )
{
T_5 V_14 ;
int error ;
error = F_6 ( V_13 , & V_14 , 3 ) ;
if ( error )
return - error ;
if ( F_7 ( V_2 , & V_14 , sizeof( struct V_15 ) ) )
return - F_4 ( V_11 ) ;
return 0 ;
}
STATIC int
F_8 (
struct V_16 * V_17 ,
T_6 T_3 * V_2 )
{
if ( F_2 ( V_17 -> V_18 , & V_2 -> V_18 ) ||
F_2 ( V_17 -> V_19 , & V_2 -> V_19 ) )
return - F_4 ( V_11 ) ;
return 0 ;
}
STATIC int
F_9 (
struct V_20 * V_17 ,
T_7 T_3 * V_2 )
{
if ( F_2 ( V_17 -> V_18 , & V_2 -> V_18 ) ||
F_2 ( V_17 -> V_21 , & V_2 -> V_21 ) )
return - F_4 ( V_11 ) ;
return 0 ;
}
STATIC int
F_10 (
void T_3 * V_22 ,
const T_8 * V_23 ,
long V_24 ,
long * V_25 )
{
T_9 T_3 * V_26 = V_22 ;
long V_27 ;
for ( V_27 = 0 ; V_27 < V_24 ; V_27 ++ ) {
if ( F_11 ( V_23 [ V_27 ] . V_28 , & V_26 [ V_27 ] . V_28 ) ||
F_11 ( V_23 [ V_27 ] . V_29 , & V_26 [ V_27 ] . V_29 ) ||
F_11 ( V_23 [ V_27 ] . V_30 , & V_26 [ V_27 ] . V_30 ) )
return - F_4 ( V_11 ) ;
}
* V_25 = V_24 * sizeof( * V_26 ) ;
return 0 ;
}
STATIC int
F_12 (
T_10 * V_31 ,
T_11 T_3 * V_32 )
{
T_12 V_33 ;
if ( F_2 ( V_33 , & V_32 -> V_34 ) ||
F_2 ( V_31 -> V_35 , & V_32 -> V_35 ) )
return - F_4 ( V_11 ) ;
V_31 -> V_34 = V_33 ;
return 0 ;
}
STATIC int
F_13 (
T_13 * V_36 ,
T_14 T_3 * V_37 )
{
if ( F_2 ( V_36 -> V_38 , & V_37 -> V_38 ) ||
F_2 ( V_36 -> V_39 , & V_37 -> V_39 ) ||
F_2 ( V_36 -> V_40 , & V_37 -> V_40 ) ||
F_2 ( V_36 -> V_41 , & V_37 -> V_41 ) ||
F_2 ( V_36 -> V_42 , & V_37 -> V_42 ) ||
F_2 ( V_36 -> V_43 , & V_37 -> V_43 ) ||
F_2 ( V_36 -> V_44 , & V_37 -> V_44 ) ||
F_2 ( V_36 -> V_45 , & V_37 -> V_45 ) ||
F_12 ( & V_36 -> V_46 , & V_37 -> V_46 ) ||
F_12 ( & V_36 -> V_47 , & V_37 -> V_47 ) ||
F_12 ( & V_36 -> V_48 , & V_37 -> V_48 ) ||
F_2 ( V_36 -> V_49 , & V_37 -> V_45 ) ||
F_2 ( V_36 -> V_50 , & V_37 -> V_45 ) ||
F_2 ( V_36 -> V_51 , & V_37 -> V_51 ) ||
F_2 ( V_36 -> V_52 , & V_37 -> V_52 ) ||
F_2 ( V_36 -> V_53 , & V_37 -> V_53 ) ||
F_2 ( V_36 -> V_54 , & V_37 -> V_54 ) ||
F_2 ( V_36 -> V_55 , & V_37 -> V_55 ) ||
F_2 ( V_36 -> V_56 , & V_37 -> V_56 ) ||
F_2 ( V_36 -> V_57 , & V_37 -> V_57 ) ||
F_2 ( V_36 -> V_58 , & V_37 -> V_58 ) )
return - F_4 ( V_11 ) ;
return 0 ;
}
STATIC int
F_14 (
T_11 T_3 * V_26 ,
const T_10 * V_59 )
{
T_15 V_33 ;
V_33 = V_59 -> V_34 ;
if ( F_11 ( V_33 , & V_26 -> V_34 ) ||
F_11 ( V_59 -> V_35 , & V_26 -> V_35 ) )
return - F_4 ( V_11 ) ;
return 0 ;
}
STATIC int
F_15 (
void T_3 * V_22 ,
int V_60 ,
int * V_61 ,
const T_13 * V_23 )
{
T_14 T_3 * V_26 = V_22 ;
if ( V_60 < sizeof( * V_26 ) )
return F_4 ( V_62 ) ;
if ( F_11 ( V_23 -> V_38 , & V_26 -> V_38 ) ||
F_11 ( V_23 -> V_39 , & V_26 -> V_39 ) ||
F_11 ( V_23 -> V_40 , & V_26 -> V_40 ) ||
F_11 ( V_23 -> V_41 , & V_26 -> V_41 ) ||
F_11 ( V_23 -> V_42 , & V_26 -> V_42 ) ||
F_11 ( V_23 -> V_43 , & V_26 -> V_43 ) ||
F_11 ( V_23 -> V_44 , & V_26 -> V_44 ) ||
F_11 ( V_23 -> V_45 , & V_26 -> V_45 ) ||
F_14 ( & V_26 -> V_46 , & V_23 -> V_46 ) ||
F_14 ( & V_26 -> V_47 , & V_23 -> V_47 ) ||
F_14 ( & V_26 -> V_48 , & V_23 -> V_48 ) ||
F_11 ( V_23 -> V_49 , & V_26 -> V_49 ) ||
F_11 ( V_23 -> V_50 , & V_26 -> V_50 ) ||
F_11 ( V_23 -> V_51 , & V_26 -> V_51 ) ||
F_11 ( V_23 -> V_52 , & V_26 -> V_52 ) ||
F_11 ( V_23 -> V_53 , & V_26 -> V_53 ) ||
F_11 ( V_23 -> V_63 , & V_26 -> V_63 ) ||
F_11 ( V_23 -> V_55 , & V_26 -> V_55 ) ||
F_11 ( V_23 -> V_56 , & V_26 -> V_56 ) ||
F_11 ( V_23 -> V_57 , & V_26 -> V_57 ) ||
F_11 ( V_23 -> V_58 , & V_26 -> V_58 ) )
return F_4 ( V_11 ) ;
if ( V_61 )
* V_61 = sizeof( * V_26 ) ;
return 0 ;
}
STATIC int
F_16 (
T_16 * V_13 ,
T_17 V_64 ,
void T_3 * V_23 ,
int V_60 ,
int * V_61 ,
int * V_65 )
{
return F_17 ( V_13 , V_64 , V_23 , V_60 ,
F_15 ,
V_61 , V_65 ) ;
}
STATIC int
F_18 (
T_16 * V_13 ,
unsigned int V_66 ,
T_18 T_3 * V_26 )
{
V_10 V_67 ;
T_19 V_68 ;
int V_24 ;
T_17 V_69 ;
int V_70 ;
int error ;
if ( ! F_19 ( V_71 ) )
return - F_4 ( V_72 ) ;
if ( F_20 ( V_13 ) )
return - F_4 ( V_73 ) ;
if ( F_2 ( V_67 , & V_26 -> V_74 ) )
return - F_4 ( V_11 ) ;
V_68 . V_74 = F_21 ( V_67 ) ;
if ( F_2 ( V_68 . V_75 , & V_26 -> V_75 ) ||
F_2 ( V_67 , & V_26 -> V_22 ) )
return - F_4 ( V_11 ) ;
V_68 . V_22 = F_21 ( V_67 ) ;
if ( F_2 ( V_67 , & V_26 -> V_76 ) )
return - F_4 ( V_11 ) ;
V_68 . V_76 = F_21 ( V_67 ) ;
if ( F_3 ( & V_69 , V_68 . V_74 , sizeof( V_77 ) ) )
return - F_4 ( V_11 ) ;
if ( ( V_24 = V_68 . V_75 ) <= 0 )
return - F_4 ( V_78 ) ;
if ( V_68 . V_22 == NULL )
return - F_4 ( V_78 ) ;
if ( V_66 == V_79 ) {
error = F_22 ( V_13 , & V_69 , & V_24 ,
V_68 . V_22 , F_10 ) ;
} else if ( V_66 == V_80 ) {
int V_81 ;
error = F_16 ( V_13 , V_69 , V_68 . V_22 ,
sizeof( T_14 ) , NULL , & V_81 ) ;
} else if ( V_66 == V_82 ) {
error = F_23 ( V_13 , & V_69 , & V_24 ,
F_16 , sizeof( T_14 ) ,
V_68 . V_22 , & V_70 ) ;
} else
error = F_4 ( V_78 ) ;
if ( error )
return - error ;
if ( V_68 . V_76 != NULL ) {
if ( F_7 ( V_68 . V_74 , & V_69 ,
sizeof( T_17 ) ) )
return - F_4 ( V_11 ) ;
if ( F_7 ( V_68 . V_76 , & V_24 , sizeof( V_24 ) ) )
return - F_4 ( V_11 ) ;
}
return 0 ;
}
STATIC int
F_24 (
T_20 * V_83 ,
T_21 T_3 * V_2 )
{
T_21 V_84 ;
if ( F_3 ( & V_84 , V_2 , sizeof( T_21 ) ) )
return - F_4 ( V_11 ) ;
V_83 -> V_85 = V_84 . V_85 ;
V_83 -> V_86 = F_21 ( V_84 . V_86 ) ;
V_83 -> V_87 = V_84 . V_87 ;
V_83 -> V_88 = F_21 ( V_84 . V_88 ) ;
V_83 -> V_89 = V_84 . V_89 ;
V_83 -> V_90 = F_21 ( V_84 . V_90 ) ;
V_83 -> V_91 = F_21 ( V_84 . V_91 ) ;
return 0 ;
}
STATIC struct V_92 *
F_25 (
struct V_93 * V_94 ,
T_21 * V_83 )
{
return F_26 ( V_94 ,
F_21 ( V_83 -> V_88 ) , V_83 -> V_89 ) ;
}
STATIC int
F_27 (
struct V_93 * V_94 ,
void T_3 * V_95 )
{
int error ;
T_22 * V_96 ;
T_23 V_97 ;
struct V_92 * V_92 ;
char * V_98 ;
if ( ! F_19 ( V_71 ) )
return - F_4 ( V_72 ) ;
if ( F_3 ( & V_97 , V_95 ,
sizeof( T_23 ) ) )
return - F_4 ( V_11 ) ;
if ( V_97 . V_99 < sizeof( struct V_100 ) ||
V_97 . V_99 > V_101 )
return - F_4 ( V_78 ) ;
if ( V_97 . V_102 & ~ ( V_103 | V_104 ) )
return - F_4 ( V_78 ) ;
V_92 = F_25 ( V_94 , & V_97 . V_83 ) ;
if ( F_28 ( V_92 ) )
return F_29 ( V_92 ) ;
error = - V_62 ;
V_98 = F_30 ( V_97 . V_99 , V_105 ) ;
if ( ! V_98 )
goto V_106;
V_96 = ( T_22 * ) & V_97 . V_107 ;
error = - F_31 ( F_32 ( V_92 -> V_108 ) , V_98 , V_97 . V_99 ,
V_97 . V_102 , V_96 ) ;
if ( error )
goto V_109;
if ( F_7 ( F_21 ( V_97 . V_23 ) , V_98 , V_97 . V_99 ) )
error = - V_11 ;
V_109:
F_33 ( V_98 ) ;
V_106:
F_34 ( V_92 ) ;
return error ;
}
STATIC int
F_35 (
struct V_93 * V_94 ,
void T_3 * V_95 )
{
int error ;
T_24 * V_110 ;
T_25 V_111 ;
struct V_92 * V_92 ;
unsigned int V_27 , V_112 ;
unsigned char * V_113 ;
if ( ! F_19 ( V_71 ) )
return - F_4 ( V_72 ) ;
if ( F_3 ( & V_111 , V_95 ,
sizeof( T_25 ) ) )
return - F_4 ( V_11 ) ;
if ( V_111 . V_114 >= V_115 / sizeof( T_24 ) )
return - V_116 ;
V_92 = F_25 ( V_94 , & V_111 . V_83 ) ;
if ( F_28 ( V_92 ) )
return F_29 ( V_92 ) ;
error = V_116 ;
V_112 = V_111 . V_114 * sizeof( T_24 ) ;
if ( ! V_112 || V_112 > 16 * V_117 )
goto V_106;
V_110 = F_36 ( F_21 ( V_111 . V_110 ) , V_112 ) ;
if ( F_28 ( V_110 ) ) {
error = - F_29 ( V_110 ) ;
goto V_106;
}
error = V_62 ;
V_113 = F_37 ( V_118 , V_119 ) ;
if ( ! V_113 )
goto V_120;
error = 0 ;
for ( V_27 = 0 ; V_27 < V_111 . V_114 ; V_27 ++ ) {
V_110 [ V_27 ] . V_121 = F_38 ( ( char * ) V_113 ,
F_21 ( V_110 [ V_27 ] . V_122 ) ,
V_118 ) ;
if ( V_110 [ V_27 ] . V_121 == 0 || V_110 [ V_27 ] . V_121 == V_118 )
error = V_123 ;
if ( V_110 [ V_27 ] . V_121 < 0 )
break;
switch ( V_110 [ V_27 ] . V_124 ) {
case V_125 :
V_110 [ V_27 ] . V_121 = F_39 (
V_92 -> V_108 , V_113 ,
F_21 ( V_110 [ V_27 ] . V_126 ) ,
& V_110 [ V_27 ] . V_127 , V_110 [ V_27 ] . V_128 ) ;
break;
case V_129 :
V_110 [ V_27 ] . V_121 = F_40 ( V_94 ) ;
if ( V_110 [ V_27 ] . V_121 )
break;
V_110 [ V_27 ] . V_121 = F_41 (
V_92 -> V_108 , V_113 ,
F_21 ( V_110 [ V_27 ] . V_126 ) ,
V_110 [ V_27 ] . V_127 , V_110 [ V_27 ] . V_128 ) ;
F_42 ( V_94 ) ;
break;
case V_130 :
V_110 [ V_27 ] . V_121 = F_40 ( V_94 ) ;
if ( V_110 [ V_27 ] . V_121 )
break;
V_110 [ V_27 ] . V_121 = F_43 (
V_92 -> V_108 , V_113 ,
V_110 [ V_27 ] . V_128 ) ;
F_42 ( V_94 ) ;
break;
default:
V_110 [ V_27 ] . V_121 = V_78 ;
}
}
if ( F_7 ( F_21 ( V_111 . V_110 ) , V_110 , V_112 ) )
error = F_4 ( V_11 ) ;
F_44 ( V_113 ) ;
V_120:
F_44 ( V_110 ) ;
V_106:
F_34 ( V_92 ) ;
return - error ;
}
STATIC int
F_45 (
struct V_93 * V_94 ,
void T_3 * V_95 )
{
int error ;
struct V_131 V_132 ;
T_26 V_133 ;
struct V_92 * V_92 ;
if ( ! F_19 ( V_134 ) )
return - F_4 ( V_72 ) ;
if ( F_3 ( & V_133 , V_95 ,
sizeof( T_26 ) ) )
return - F_4 ( V_11 ) ;
V_92 = F_25 ( V_94 , & V_133 . V_83 ) ;
if ( F_28 ( V_92 ) )
return F_29 ( V_92 ) ;
if ( F_46 ( V_92 -> V_108 ) || F_47 ( V_92 -> V_108 ) ) {
error = - F_4 ( V_72 ) ;
goto V_135;
}
if ( F_3 ( & V_132 , F_21 ( V_133 . V_136 ) , sizeof( V_132 ) ) ) {
error = - F_4 ( V_11 ) ;
goto V_135;
}
error = - F_48 ( F_32 ( V_92 -> V_108 ) , V_132 . V_137 ,
V_132 . V_138 ) ;
V_135:
F_34 ( V_92 ) ;
return error ;
}
long
F_49 (
struct V_93 * V_139 ,
unsigned V_66 ,
unsigned long V_59 )
{
struct V_140 * V_140 = F_50 ( V_139 ) ;
struct V_141 * V_142 = F_32 ( V_140 ) ;
struct V_12 * V_13 = V_142 -> V_143 ;
void T_3 * V_95 = ( void T_3 * ) V_59 ;
int V_144 = 0 ;
int error ;
if ( V_139 -> V_145 & V_146 )
V_144 |= V_147 ;
F_51 ( V_142 ) ;
switch ( V_66 ) {
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
case V_162 :
case V_163 :
return F_52 ( V_139 , V_66 , V_59 ) ;
#ifndef F_53
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
case V_174 :
case V_175 :
return F_52 ( V_139 , V_66 , V_59 ) ;
#else
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 : {
struct V_185 V_1 ;
if ( F_1 ( & V_1 , V_95 ) )
return - F_4 ( V_11 ) ;
V_66 = F_54 ( V_66 , struct V_185 ) ;
return F_55 ( V_142 , V_140 , V_139 , V_144 , V_66 , & V_1 ) ;
}
case V_186 :
return F_5 ( V_13 , V_95 ) ;
case V_187 : {
struct V_16 V_17 ;
if ( F_8 ( & V_17 , V_95 ) )
return - F_4 ( V_11 ) ;
error = F_40 ( V_139 ) ;
if ( error )
return error ;
error = V_16 ( V_13 , & V_17 ) ;
F_42 ( V_139 ) ;
return - error ;
}
case V_188 : {
struct V_20 V_17 ;
if ( F_9 ( & V_17 , V_95 ) )
return - F_4 ( V_11 ) ;
error = F_40 ( V_139 ) ;
if ( error )
return error ;
error = V_20 ( V_13 , & V_17 ) ;
F_42 ( V_139 ) ;
return - error ;
}
#endif
case V_189 :
case V_190 :
case V_191 :
V_66 = F_54 ( V_66 , long ) ;
return F_52 ( V_139 , V_66 , V_59 ) ;
case V_192 : {
struct V_193 V_194 ;
struct V_195 T_3 * V_196 = V_95 ;
if ( F_3 ( & V_194 , V_196 ,
F_56 ( struct V_193 , V_197 ) ) ||
F_13 ( & V_194 . V_197 , & V_196 -> V_197 ) )
return - F_4 ( V_11 ) ;
error = F_40 ( V_139 ) ;
if ( error )
return error ;
error = F_57 ( & V_194 ) ;
F_42 ( V_139 ) ;
return - error ;
}
case V_82 :
case V_80 :
case V_79 :
return F_18 ( V_13 , V_66 , V_95 ) ;
case V_198 :
case V_199 :
case V_200 : {
struct V_201 V_83 ;
if ( F_24 ( & V_83 , V_95 ) )
return - F_4 ( V_11 ) ;
V_66 = F_54 ( V_66 , struct V_201 ) ;
return F_58 ( V_66 , & V_83 ) ;
}
case V_202 : {
struct V_201 V_83 ;
if ( F_24 ( & V_83 , V_95 ) )
return - F_4 ( V_11 ) ;
return F_59 ( V_139 , & V_83 ) ;
}
case V_203 : {
struct V_201 V_83 ;
if ( F_24 ( & V_83 , V_95 ) )
return - F_4 ( V_11 ) ;
return F_60 ( V_139 , & V_83 ) ;
}
case V_204 :
return F_27 ( V_139 , V_95 ) ;
case V_205 :
return F_35 ( V_139 , V_95 ) ;
case V_206 :
return F_45 ( V_139 , V_95 ) ;
default:
return - F_4 ( V_207 ) ;
}
}
