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
if ( V_97 . V_99 > V_100 )
return - F_4 ( V_78 ) ;
if ( V_97 . V_101 & ~ ( V_102 | V_103 ) )
return - F_4 ( V_78 ) ;
V_92 = F_25 ( V_94 , & V_97 . V_83 ) ;
if ( F_28 ( V_92 ) )
return F_29 ( V_92 ) ;
error = - V_62 ;
V_98 = F_30 ( V_97 . V_99 , V_104 ) ;
if ( ! V_98 )
goto V_105;
V_96 = ( T_22 * ) & V_97 . V_106 ;
error = - F_31 ( F_32 ( V_92 -> V_107 ) , V_98 , V_97 . V_99 ,
V_97 . V_101 , V_96 ) ;
if ( error )
goto V_108;
if ( F_7 ( F_21 ( V_97 . V_23 ) , V_98 , V_97 . V_99 ) )
error = - V_11 ;
V_108:
F_33 ( V_98 ) ;
V_105:
F_34 ( V_92 ) ;
return error ;
}
STATIC int
F_35 (
struct V_93 * V_94 ,
void T_3 * V_95 )
{
int error ;
T_24 * V_109 ;
T_25 V_110 ;
struct V_92 * V_92 ;
unsigned int V_27 , V_111 ;
unsigned char * V_112 ;
if ( ! F_19 ( V_71 ) )
return - F_4 ( V_72 ) ;
if ( F_3 ( & V_110 , V_95 ,
sizeof( T_25 ) ) )
return - F_4 ( V_11 ) ;
if ( V_110 . V_113 >= V_114 / sizeof( T_24 ) )
return - V_115 ;
V_92 = F_25 ( V_94 , & V_110 . V_83 ) ;
if ( F_28 ( V_92 ) )
return F_29 ( V_92 ) ;
error = V_115 ;
V_111 = V_110 . V_113 * sizeof( T_24 ) ;
if ( ! V_111 || V_111 > 16 * V_116 )
goto V_105;
V_109 = F_36 ( F_21 ( V_110 . V_109 ) , V_111 ) ;
if ( F_28 ( V_109 ) ) {
error = F_29 ( V_109 ) ;
goto V_105;
}
V_112 = F_30 ( V_117 , V_104 ) ;
if ( ! V_112 )
goto V_118;
error = 0 ;
for ( V_27 = 0 ; V_27 < V_110 . V_113 ; V_27 ++ ) {
V_109 [ V_27 ] . V_119 = F_37 ( ( char * ) V_112 ,
F_21 ( V_109 [ V_27 ] . V_120 ) ,
V_117 ) ;
if ( V_109 [ V_27 ] . V_119 == 0 || V_109 [ V_27 ] . V_119 == V_117 )
error = - V_121 ;
if ( V_109 [ V_27 ] . V_119 < 0 )
break;
switch ( V_109 [ V_27 ] . V_122 ) {
case V_123 :
V_109 [ V_27 ] . V_119 = F_38 (
V_92 -> V_107 , V_112 ,
F_21 ( V_109 [ V_27 ] . V_124 ) ,
& V_109 [ V_27 ] . V_125 , V_109 [ V_27 ] . V_126 ) ;
break;
case V_127 :
V_109 [ V_27 ] . V_119 = F_39 ( V_94 ) ;
if ( V_109 [ V_27 ] . V_119 )
break;
V_109 [ V_27 ] . V_119 = F_40 (
V_92 -> V_107 , V_112 ,
F_21 ( V_109 [ V_27 ] . V_124 ) ,
V_109 [ V_27 ] . V_125 , V_109 [ V_27 ] . V_126 ) ;
F_41 ( V_94 ) ;
break;
case V_128 :
V_109 [ V_27 ] . V_119 = F_39 ( V_94 ) ;
if ( V_109 [ V_27 ] . V_119 )
break;
V_109 [ V_27 ] . V_119 = F_42 (
V_92 -> V_107 , V_112 ,
V_109 [ V_27 ] . V_126 ) ;
F_41 ( V_94 ) ;
break;
default:
V_109 [ V_27 ] . V_119 = V_78 ;
}
}
if ( F_7 ( F_21 ( V_110 . V_109 ) , V_109 , V_111 ) )
error = F_4 ( V_11 ) ;
F_33 ( V_112 ) ;
V_118:
F_33 ( V_109 ) ;
V_105:
F_34 ( V_92 ) ;
return - error ;
}
STATIC int
F_43 (
struct V_93 * V_94 ,
void T_3 * V_95 )
{
int error ;
struct V_129 V_130 ;
T_26 V_131 ;
struct V_92 * V_92 ;
if ( ! F_19 ( V_132 ) )
return - F_4 ( V_72 ) ;
if ( F_3 ( & V_131 , V_95 ,
sizeof( T_26 ) ) )
return - F_4 ( V_11 ) ;
V_92 = F_25 ( V_94 , & V_131 . V_83 ) ;
if ( F_28 ( V_92 ) )
return F_29 ( V_92 ) ;
if ( F_44 ( V_92 -> V_107 ) || F_45 ( V_92 -> V_107 ) ) {
error = - F_4 ( V_72 ) ;
goto V_133;
}
if ( F_3 ( & V_130 , F_21 ( V_131 . V_134 ) , sizeof( V_130 ) ) ) {
error = - F_4 ( V_11 ) ;
goto V_133;
}
error = - F_46 ( F_32 ( V_92 -> V_107 ) , V_130 . V_135 ,
V_130 . V_136 ) ;
V_133:
F_34 ( V_92 ) ;
return error ;
}
long
F_47 (
struct V_93 * V_137 ,
unsigned V_66 ,
unsigned long V_59 )
{
struct V_138 * V_138 = V_137 -> V_139 . V_92 -> V_107 ;
struct V_140 * V_141 = F_32 ( V_138 ) ;
struct V_12 * V_13 = V_141 -> V_142 ;
void T_3 * V_95 = ( void T_3 * ) V_59 ;
int V_143 = 0 ;
int error ;
if ( V_137 -> V_144 & V_145 )
V_143 |= V_146 ;
F_48 ( V_141 ) ;
switch ( V_66 ) {
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
case V_162 :
return F_49 ( V_137 , V_66 , V_59 ) ;
#ifndef F_50
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
case V_174 :
return F_49 ( V_137 , V_66 , V_59 ) ;
#else
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 : {
struct V_184 V_1 ;
if ( F_1 ( & V_1 , V_95 ) )
return - F_4 ( V_11 ) ;
V_66 = F_51 ( V_66 , struct V_184 ) ;
return F_52 ( V_141 , V_138 , V_137 , V_143 , V_66 , & V_1 ) ;
}
case V_185 :
return F_5 ( V_13 , V_95 ) ;
case V_186 : {
struct V_16 V_17 ;
if ( F_8 ( & V_17 , V_95 ) )
return - F_4 ( V_11 ) ;
error = V_16 ( V_13 , & V_17 ) ;
return - error ;
}
case V_187 : {
struct V_20 V_17 ;
if ( F_9 ( & V_17 , V_95 ) )
return - F_4 ( V_11 ) ;
error = V_20 ( V_13 , & V_17 ) ;
return - error ;
}
#endif
case V_188 :
case V_189 :
case V_190 :
V_66 = F_51 ( V_66 , long ) ;
return F_49 ( V_137 , V_66 , V_59 ) ;
case V_191 : {
struct V_192 V_193 ;
struct V_194 T_3 * V_195 = V_95 ;
if ( F_3 ( & V_193 , V_195 ,
F_53 ( struct V_192 , V_196 ) ) ||
F_13 ( & V_193 . V_196 , & V_195 -> V_196 ) )
return - F_4 ( V_11 ) ;
error = V_192 ( & V_193 ) ;
return - error ;
}
case V_82 :
case V_80 :
case V_79 :
return F_18 ( V_13 , V_66 , V_95 ) ;
case V_197 :
case V_198 :
case V_199 : {
struct V_200 V_83 ;
if ( F_24 ( & V_83 , V_95 ) )
return - F_4 ( V_11 ) ;
V_66 = F_51 ( V_66 , struct V_200 ) ;
return F_54 ( V_66 , & V_83 ) ;
}
case V_201 : {
struct V_200 V_83 ;
if ( F_24 ( & V_83 , V_95 ) )
return - F_4 ( V_11 ) ;
return F_55 ( V_137 , & V_83 ) ;
}
case V_202 : {
struct V_200 V_83 ;
if ( F_24 ( & V_83 , V_95 ) )
return - F_4 ( V_11 ) ;
return F_56 ( V_137 , & V_83 ) ;
}
case V_203 :
return F_27 ( V_137 , V_95 ) ;
case V_204 :
return F_35 ( V_137 , V_95 ) ;
case V_205 :
return F_43 ( V_137 , V_95 ) ;
default:
return - F_4 ( V_206 ) ;
}
}
