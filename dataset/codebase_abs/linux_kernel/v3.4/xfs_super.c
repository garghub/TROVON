STATIC unsigned long
F_1 ( char * V_1 , char * * V_2 , unsigned int V_3 )
{
int V_4 , V_5 = 0 ;
char * V_6 = V_1 ;
V_4 = strlen ( V_6 ) - 1 ;
if ( V_6 [ V_4 ] == 'K' || V_6 [ V_4 ] == 'k' ) {
V_5 = 10 ;
V_6 [ V_4 ] = '\0' ;
}
if ( V_6 [ V_4 ] == 'M' || V_6 [ V_4 ] == 'm' ) {
V_5 = 20 ;
V_6 [ V_4 ] = '\0' ;
}
if ( V_6 [ V_4 ] == 'G' || V_6 [ V_4 ] == 'g' ) {
V_5 = 30 ;
V_6 [ V_4 ] = '\0' ;
}
return F_2 ( ( const char * ) V_1 , V_2 , V_3 ) << V_5 ;
}
STATIC int
F_3 (
struct V_7 * V_8 ,
char * V_9 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
char * V_13 , * V_6 , * V_14 ;
int V_15 = 0 ;
int V_16 = 0 ;
int V_17 = 0 ;
T_1 V_18 = 0 ;
V_8 -> V_19 = F_4 ( V_11 -> V_20 , V_21 , V_22 ) ;
if ( ! V_8 -> V_19 )
return V_23 ;
V_8 -> V_24 = strlen ( V_8 -> V_19 ) + 1 ;
if ( V_11 -> V_25 & V_26 )
V_8 -> V_27 |= V_28 ;
if ( V_11 -> V_25 & V_29 )
V_8 -> V_27 |= V_30 ;
if ( V_11 -> V_25 & V_31 )
V_8 -> V_27 |= V_32 ;
V_8 -> V_27 |= V_33 ;
V_8 -> V_27 |= V_34 ;
V_8 -> V_27 |= V_35 ;
V_8 -> V_36 = - 1 ;
V_8 -> V_37 = - 1 ;
if ( ! V_9 )
goto V_38;
while ( ( V_13 = F_5 ( & V_9 , L_1 ) ) != NULL ) {
if ( ! * V_13 )
continue;
if ( ( V_6 = strchr ( V_13 , '=' ) ) != NULL )
* V_6 ++ = 0 ;
if ( ! strcmp ( V_13 , V_39 ) ) {
if ( ! V_6 || ! * V_6 ) {
F_6 ( V_8 , L_2 ,
V_13 ) ;
return V_40 ;
}
V_8 -> V_36 = F_2 ( V_6 , & V_14 , 10 ) ;
} else if ( ! strcmp ( V_13 , V_41 ) ) {
if ( ! V_6 || ! * V_6 ) {
F_6 ( V_8 , L_2 ,
V_13 ) ;
return V_40 ;
}
V_8 -> V_37 = F_1 ( V_6 , & V_14 , 10 ) ;
} else if ( ! strcmp ( V_13 , V_42 ) ) {
if ( ! V_6 || ! * V_6 ) {
F_6 ( V_8 , L_2 ,
V_13 ) ;
return V_40 ;
}
V_8 -> V_43 = F_4 ( V_6 , V_21 , V_22 ) ;
if ( ! V_8 -> V_43 )
return V_23 ;
} else if ( ! strcmp ( V_13 , V_44 ) ) {
F_6 ( V_8 , L_3 ,
V_13 ) ;
return V_40 ;
} else if ( ! strcmp ( V_13 , V_45 ) ) {
if ( ! V_6 || ! * V_6 ) {
F_6 ( V_8 , L_2 ,
V_13 ) ;
return V_40 ;
}
V_8 -> V_46 = F_4 ( V_6 , V_21 , V_22 ) ;
if ( ! V_8 -> V_46 )
return V_23 ;
} else if ( ! strcmp ( V_13 , V_47 ) ) {
if ( ! V_6 || ! * V_6 ) {
F_6 ( V_8 , L_2 ,
V_13 ) ;
return V_40 ;
}
V_17 = F_2 ( V_6 , & V_14 , 10 ) ;
V_18 = F_7 ( V_17 ) - 1 ;
} else if ( ! strcmp ( V_13 , V_48 ) ) {
if ( ! V_6 || ! * V_6 ) {
F_6 ( V_8 , L_2 ,
V_13 ) ;
return V_40 ;
}
V_17 = F_1 ( V_6 , & V_14 , 10 ) ;
V_18 = F_7 ( V_17 ) - 1 ;
} else if ( ! strcmp ( V_13 , V_49 ) ||
! strcmp ( V_13 , V_50 ) ) {
V_8 -> V_27 |= V_51 ;
} else if ( ! strcmp ( V_13 , V_52 ) ||
! strcmp ( V_13 , V_53 ) ) {
V_8 -> V_27 &= ~ V_51 ;
} else if ( ! strcmp ( V_13 , V_54 ) ) {
V_8 -> V_27 |= V_32 ;
} else if ( ! strcmp ( V_13 , V_55 ) ) {
V_8 -> V_27 |= V_56 ;
} else if ( ! strcmp ( V_13 , V_57 ) ) {
V_8 -> V_27 |= V_58 ;
} else if ( ! strcmp ( V_13 , V_59 ) ) {
V_8 -> V_27 |= V_60 ;
} else if ( ! strcmp ( V_13 , V_61 ) ) {
if ( ! V_6 || ! * V_6 ) {
F_6 ( V_8 , L_2 ,
V_13 ) ;
return V_40 ;
}
V_15 = F_2 ( V_6 , & V_14 , 10 ) ;
} else if ( ! strcmp ( V_13 , V_62 ) ) {
if ( ! V_6 || ! * V_6 ) {
F_6 ( V_8 , L_2 ,
V_13 ) ;
return V_40 ;
}
V_16 = F_2 ( V_6 , & V_14 , 10 ) ;
} else if ( ! strcmp ( V_13 , V_63 ) ) {
V_8 -> V_27 &= ~ V_35 ;
#if ! V_64
F_6 ( V_8 , L_3 ,
V_13 ) ;
return V_40 ;
#endif
} else if ( ! strcmp ( V_13 , V_65 ) ) {
V_8 -> V_27 |= V_66 ;
} else if ( ! strcmp ( V_13 , V_67 ) ) {
V_8 -> V_27 |= V_33 ;
} else if ( ! strcmp ( V_13 , V_68 ) ) {
V_8 -> V_27 &= ~ V_33 ;
} else if ( ! strcmp ( V_13 , V_69 ) ) {
V_8 -> V_27 |= V_70 ;
} else if ( ! strcmp ( V_13 , V_71 ) ) {
V_8 -> V_27 &= ~ V_70 ;
} else if ( ! strcmp ( V_13 , V_72 ) ) {
V_8 -> V_27 &= ~ V_34 ;
} else if ( ! strcmp ( V_13 , V_73 ) ) {
V_8 -> V_27 |= V_34 ;
} else if ( ! strcmp ( V_13 , V_74 ) ) {
V_8 -> V_27 |= V_75 ;
} else if ( ! strcmp ( V_13 , V_76 ) ) {
V_8 -> V_27 &= ~ V_75 ;
V_8 -> V_27 |= V_77 ;
} else if ( ! strcmp ( V_13 , V_78 ) ) {
V_8 -> V_27 |= V_79 ;
} else if ( ! strcmp ( V_13 , V_80 ) ) {
V_8 -> V_81 &= ~ V_82 ;
V_8 -> V_81 &= ~ V_83 ;
V_8 -> V_81 &= ~ V_84 ;
} else if ( ! strcmp ( V_13 , V_85 ) ||
! strcmp ( V_13 , V_86 ) ||
! strcmp ( V_13 , V_87 ) ) {
V_8 -> V_81 |= ( V_88 | V_89 |
V_90 ) ;
} else if ( ! strcmp ( V_13 , V_91 ) ||
! strcmp ( V_13 , V_92 ) ) {
V_8 -> V_81 |= ( V_88 | V_89 ) ;
V_8 -> V_81 &= ~ V_90 ;
} else if ( ! strcmp ( V_13 , V_93 ) ||
! strcmp ( V_13 , V_94 ) ) {
V_8 -> V_81 |= ( V_95 | V_96 |
V_97 ) ;
} else if ( ! strcmp ( V_13 , V_98 ) ) {
V_8 -> V_81 |= ( V_95 | V_96 ) ;
V_8 -> V_81 &= ~ V_97 ;
} else if ( ! strcmp ( V_13 , V_99 ) ||
! strcmp ( V_13 , V_100 ) ) {
V_8 -> V_81 |= ( V_101 | V_102 |
V_97 ) ;
} else if ( ! strcmp ( V_13 , V_103 ) ) {
V_8 -> V_81 |= ( V_101 | V_102 ) ;
V_8 -> V_81 &= ~ V_97 ;
} else if ( ! strcmp ( V_13 , V_104 ) ) {
F_6 ( V_8 ,
L_4 ) ;
} else if ( ! strcmp ( V_13 , V_105 ) ) {
F_6 ( V_8 ,
L_5 ) ;
} else if ( ! strcmp ( V_13 , V_106 ) ) {
V_8 -> V_27 |= V_107 ;
} else if ( ! strcmp ( V_13 , V_108 ) ) {
V_8 -> V_27 &= ~ V_107 ;
} else if ( ! strcmp ( V_13 , L_6 ) ) {
F_6 ( V_8 ,
L_7 ) ;
} else if ( ! strcmp ( V_13 , L_8 ) ) {
F_6 ( V_8 ,
L_9 ) ;
} else if ( ! strcmp ( V_13 , L_10 ) ) {
F_6 ( V_8 ,
L_11 ) ;
} else if ( ! strcmp ( V_13 , L_12 ) ) {
F_6 ( V_8 ,
L_13 ) ;
} else {
F_6 ( V_8 , L_14 , V_13 ) ;
return V_40 ;
}
}
if ( ( V_8 -> V_27 & V_56 ) &&
! ( V_8 -> V_27 & V_28 ) ) {
F_6 ( V_8 , L_15 ) ;
return V_40 ;
}
if ( ( V_8 -> V_27 & V_58 ) && ( V_15 || V_16 ) ) {
F_6 ( V_8 ,
L_16 ) ;
return V_40 ;
}
#ifndef F_8
if ( F_9 ( V_8 ) ) {
F_6 ( V_8 , L_17 ) ;
return V_40 ;
}
#endif
if ( ( V_8 -> V_81 & ( V_101 | V_102 ) ) &&
( V_8 -> V_81 & ( V_95 | V_96 ) ) ) {
F_6 ( V_8 , L_18 ) ;
return V_40 ;
}
if ( ( V_15 && ! V_16 ) || ( ! V_15 && V_16 ) ) {
F_6 ( V_8 , L_19 ) ;
return V_40 ;
}
if ( V_15 && ( V_16 % V_15 != 0 ) ) {
F_6 ( V_8 ,
L_20 ,
V_16 , V_15 ) ;
return V_40 ;
}
V_38:
if ( ! ( V_8 -> V_27 & V_58 ) ) {
if ( V_15 ) {
V_8 -> V_109 = V_15 ;
V_8 -> V_27 |= V_110 ;
}
if ( V_16 )
V_8 -> V_111 = V_16 ;
}
if ( V_8 -> V_36 != - 1 &&
V_8 -> V_36 != 0 &&
( V_8 -> V_36 < V_112 ||
V_8 -> V_36 > V_113 ) ) {
F_6 ( V_8 , L_21 ,
V_8 -> V_36 , V_112 , V_113 ) ;
return F_10 ( V_40 ) ;
}
if ( V_8 -> V_37 != - 1 &&
V_8 -> V_37 != 0 &&
( V_8 -> V_37 < V_114 ||
V_8 -> V_37 > V_115 ||
! F_11 ( V_8 -> V_37 ) ) ) {
F_6 ( V_8 ,
L_22 ,
V_8 -> V_37 ) ;
return F_10 ( V_40 ) ;
}
if ( V_18 ) {
if ( V_18 > V_116 ||
V_18 < V_117 ) {
F_6 ( V_8 , L_23 ,
V_18 , V_117 ,
V_116 ) ;
return F_10 ( V_40 ) ;
}
V_8 -> V_27 |= V_118 ;
V_8 -> V_119 = V_18 ;
V_8 -> V_120 = V_18 ;
}
return 0 ;
}
STATIC int
F_12 (
struct V_7 * V_8 ,
struct V_121 * V_122 )
{
static struct V_123 V_124 [] = {
{ V_70 , L_1 V_69 } ,
{ V_32 , L_1 V_54 } ,
{ V_58 , L_1 V_57 } ,
{ V_60 , L_1 V_59 } ,
{ V_66 , L_1 V_65 } ,
{ V_56 , L_1 V_55 } ,
{ V_75 , L_1 V_74 } ,
{ V_79 , L_1 V_78 } ,
{ V_51 , L_1 V_49 } ,
{ V_107 , L_1 V_106 } ,
{ 0 , NULL }
} ;
static struct V_123 V_125 [] = {
{ V_34 , L_1 V_72 } ,
{ V_33 , L_1 V_68 } ,
{ V_35 , L_1 V_63 } ,
{ 0 , NULL }
} ;
struct V_123 * V_126 ;
for ( V_126 = V_124 ; V_126 -> V_127 ; V_126 ++ ) {
if ( V_8 -> V_27 & V_126 -> V_127 )
F_13 ( V_122 , V_126 -> V_128 ) ;
}
for ( V_126 = V_125 ; V_126 -> V_127 ; V_126 ++ ) {
if ( ! ( V_8 -> V_27 & V_126 -> V_127 ) )
F_13 ( V_122 , V_126 -> V_128 ) ;
}
if ( V_8 -> V_27 & V_118 )
F_14 ( V_122 , L_1 V_48 L_24 ,
( int ) ( 1 << V_8 -> V_120 ) >> 10 ) ;
if ( V_8 -> V_36 > 0 )
F_14 ( V_122 , L_1 V_39 L_25 , V_8 -> V_36 ) ;
if ( V_8 -> V_37 > 0 )
F_14 ( V_122 , L_1 V_41 L_24 , V_8 -> V_37 >> 10 ) ;
if ( V_8 -> V_43 )
F_14 ( V_122 , L_1 V_42 L_26 , V_8 -> V_43 ) ;
if ( V_8 -> V_46 )
F_14 ( V_122 , L_1 V_45 L_26 , V_8 -> V_46 ) ;
if ( V_8 -> V_109 > 0 )
F_14 ( V_122 , L_1 V_61 L_25 ,
( int ) F_15 ( V_8 , V_8 -> V_109 ) ) ;
if ( V_8 -> V_111 > 0 )
F_14 ( V_122 , L_1 V_62 L_25 ,
( int ) F_15 ( V_8 , V_8 -> V_111 ) ) ;
if ( V_8 -> V_81 & ( V_88 | V_90 ) )
F_13 ( V_122 , L_1 V_87 ) ;
else if ( V_8 -> V_81 & V_88 )
F_13 ( V_122 , L_1 V_92 ) ;
if ( V_8 -> V_81 & V_95 ) {
if ( V_8 -> V_81 & V_97 )
F_13 ( V_122 , L_1 V_94 ) ;
else
F_13 ( V_122 , L_1 V_98 ) ;
} else if ( V_8 -> V_81 & V_101 ) {
if ( V_8 -> V_81 & V_97 )
F_13 ( V_122 , L_1 V_100 ) ;
else
F_13 ( V_122 , L_1 V_103 ) ;
}
if ( ! ( V_8 -> V_81 & V_82 ) )
F_13 ( V_122 , L_1 V_80 ) ;
return 0 ;
}
T_2
F_16 (
unsigned int V_129 )
{
unsigned int V_130 = 1 ;
unsigned int V_131 = V_132 - 1 ;
#if V_132 == 32
# if F_17 ( V_133 )
ASSERT ( sizeof( V_134 ) == 8 ) ;
V_130 = V_135 ;
V_131 = V_132 ;
# else
V_130 = V_135 >> ( V_136 - V_129 ) ;
# endif
#endif
return ( ( ( T_2 ) V_130 ) << V_131 ) - 1 ;
}
STATIC int
F_18 (
T_3 * V_8 ,
const char * V_137 ,
struct V_138 * * V_139 )
{
int error = 0 ;
* V_139 = F_19 ( V_137 , V_140 | V_141 | V_142 ,
V_8 ) ;
if ( F_20 ( * V_139 ) ) {
error = F_21 ( * V_139 ) ;
F_6 ( V_8 , L_27 , V_137 , error ) ;
}
return - error ;
}
STATIC void
F_22 (
struct V_138 * V_143 )
{
if ( V_143 )
F_23 ( V_143 , V_140 | V_141 | V_142 ) ;
}
void
F_24 (
T_4 * V_144 )
{
F_25 ( V_144 -> V_145 , V_22 , NULL ) ;
}
STATIC void
F_26 (
struct V_7 * V_8 )
{
if ( V_8 -> V_146 && V_8 -> V_146 != V_8 -> V_147 ) {
struct V_138 * V_148 = V_8 -> V_146 -> V_145 ;
F_27 ( V_8 , V_8 -> V_146 ) ;
F_22 ( V_148 ) ;
}
if ( V_8 -> V_149 ) {
struct V_138 * V_150 = V_8 -> V_149 -> V_145 ;
F_27 ( V_8 , V_8 -> V_149 ) ;
F_22 ( V_150 ) ;
}
F_27 ( V_8 , V_8 -> V_147 ) ;
}
STATIC int
F_28 (
struct V_7 * V_8 )
{
struct V_138 * V_151 = V_8 -> V_12 -> V_152 ;
struct V_138 * V_148 = NULL , * V_150 = NULL ;
int error ;
if ( V_8 -> V_43 ) {
error = F_18 ( V_8 , V_8 -> V_43 , & V_148 ) ;
if ( error )
goto V_153;
}
if ( V_8 -> V_46 ) {
error = F_18 ( V_8 , V_8 -> V_46 , & V_150 ) ;
if ( error )
goto V_154;
if ( V_150 == V_151 || V_150 == V_148 ) {
F_6 ( V_8 ,
L_28 ) ;
error = V_40 ;
goto V_155;
}
}
error = V_23 ;
V_8 -> V_147 = F_29 ( V_8 , V_151 , 0 , V_8 -> V_19 ) ;
if ( ! V_8 -> V_147 )
goto V_155;
if ( V_150 ) {
V_8 -> V_149 = F_29 ( V_8 , V_150 , 1 ,
V_8 -> V_19 ) ;
if ( ! V_8 -> V_149 )
goto V_156;
}
if ( V_148 && V_148 != V_151 ) {
V_8 -> V_146 = F_29 ( V_8 , V_148 , 1 ,
V_8 -> V_19 ) ;
if ( ! V_8 -> V_146 )
goto V_157;
} else {
V_8 -> V_146 = V_8 -> V_147 ;
}
return 0 ;
V_157:
if ( V_8 -> V_149 )
F_27 ( V_8 , V_8 -> V_149 ) ;
V_156:
F_27 ( V_8 , V_8 -> V_147 ) ;
V_155:
if ( V_150 )
F_22 ( V_150 ) ;
V_154:
if ( V_148 && V_148 != V_151 )
F_22 ( V_148 ) ;
V_153:
return error ;
}
STATIC int
F_30 (
struct V_7 * V_8 )
{
int error ;
error = F_31 ( V_8 -> V_147 , V_8 -> V_158 . V_159 ,
V_8 -> V_158 . V_160 ) ;
if ( error )
return error ;
if ( V_8 -> V_146 && V_8 -> V_146 != V_8 -> V_147 ) {
unsigned int V_161 = V_162 ;
if ( F_32 ( & V_8 -> V_158 ) )
V_161 = V_8 -> V_158 . V_163 ;
error = F_31 ( V_8 -> V_146 ,
V_8 -> V_158 . V_159 ,
V_161 ) ;
if ( error )
return error ;
}
if ( V_8 -> V_149 ) {
error = F_31 ( V_8 -> V_149 ,
V_8 -> V_158 . V_159 ,
V_8 -> V_158 . V_160 ) ;
if ( error )
return error ;
}
return 0 ;
}
STATIC int
F_33 (
struct V_7 * V_8 )
{
V_8 -> V_164 = F_34 ( L_29 ,
V_165 , 0 , V_8 -> V_19 ) ;
if ( ! V_8 -> V_164 )
goto V_153;
V_8 -> V_166 = F_34 ( L_30 ,
V_165 , 0 , V_8 -> V_19 ) ;
if ( ! V_8 -> V_166 )
goto V_167;
return 0 ;
V_167:
F_35 ( V_8 -> V_164 ) ;
V_153:
return - V_23 ;
}
STATIC void
F_36 (
struct V_7 * V_8 )
{
F_35 ( V_8 -> V_164 ) ;
F_35 ( V_8 -> V_166 ) ;
}
STATIC struct V_168 *
F_37 (
struct V_10 * V_11 )
{
F_38 () ;
return NULL ;
}
STATIC void
F_39 (
struct V_168 * V_168 )
{
struct V_169 * V_170 = F_40 ( V_168 ) ;
F_41 ( V_170 ) ;
F_42 ( V_171 ) ;
if ( F_43 ( V_168 ) )
goto V_172;
ASSERT ( F_44 ( V_170 -> V_173 ) || V_170 -> V_174 == 0 ) ;
F_45 ( ! F_46 ( V_170 , V_175 ) ) ;
F_45 ( ! F_46 ( V_170 , V_176 ) ) ;
V_172:
F_47 ( V_170 ) ;
}
STATIC void
F_48 (
void * V_168 )
{
struct V_169 * V_170 = V_168 ;
memset ( V_170 , 0 , sizeof( struct V_169 ) ) ;
F_49 ( F_50 ( V_170 ) ) ;
F_51 ( & V_170 -> V_177 , 0 ) ;
F_52 ( & V_170 -> V_178 ) ;
F_53 ( & V_170 -> V_179 , V_180 | V_181 ,
L_31 , V_170 -> V_182 ) ;
}
STATIC void
F_54 (
struct V_168 * V_168 ,
int V_183 )
{
struct V_169 * V_170 = F_40 ( V_168 ) ;
struct V_7 * V_8 = V_170 -> V_173 ;
struct V_184 * V_185 ;
int error ;
if ( V_183 != V_186 )
return;
F_55 ( V_170 ) ;
V_185 = F_56 ( V_8 , V_187 ) ;
error = F_57 ( V_185 , 0 , F_58 ( V_8 ) , 0 , 0 , 0 ) ;
if ( error ) {
F_59 ( V_185 , 0 ) ;
goto V_188;
}
F_60 ( V_170 , V_189 ) ;
V_170 -> V_190 . V_191 . V_192 = ( V_193 ) V_168 -> V_194 . V_195 ;
V_170 -> V_190 . V_191 . V_196 = ( V_193 ) V_168 -> V_194 . V_197 ;
V_170 -> V_190 . V_198 . V_192 = ( V_193 ) V_168 -> V_199 . V_195 ;
V_170 -> V_190 . V_198 . V_196 = ( V_193 ) V_168 -> V_199 . V_197 ;
V_170 -> V_190 . V_200 . V_192 = ( V_193 ) V_168 -> V_201 . V_195 ;
V_170 -> V_190 . V_200 . V_196 = ( V_193 ) V_168 -> V_201 . V_197 ;
F_61 ( V_185 , V_170 , V_189 ) ;
F_62 ( V_185 , V_170 , V_202 ) ;
error = F_63 ( V_185 , 0 ) ;
if ( error )
goto V_188;
return;
V_188:
F_6 ( V_8 , L_32 , V_170 -> V_182 ) ;
}
STATIC void
F_64 (
struct V_168 * V_168 )
{
T_5 * V_170 = F_40 ( V_168 ) ;
F_65 ( V_170 ) ;
F_66 ( & V_168 -> V_203 , 0 ) ;
F_67 ( V_168 ) ;
F_42 ( V_204 ) ;
F_42 ( V_205 ) ;
F_68 ( V_206 ) ;
ASSERT ( ! F_69 ( & V_170 -> V_207 . V_208 ) ) ;
F_53 ( & V_170 -> V_207 , V_181 , L_33 , V_170 -> V_182 ) ;
F_70 ( & V_170 -> V_207 . V_208 ,
& V_209 , L_34 ) ;
F_71 ( V_170 ) ;
}
STATIC int
F_72 (
struct V_168 * V_168 )
{
struct V_169 * V_170 = F_40 ( V_168 ) ;
return F_73 ( V_168 ) || ( V_170 -> V_210 & V_211 ) ;
}
STATIC void
F_74 (
struct V_7 * V_8 )
{
F_75 ( V_8 -> V_19 ) ;
F_75 ( V_8 -> V_46 ) ;
F_75 ( V_8 -> V_43 ) ;
}
STATIC void
F_76 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_77 ( V_11 ) ;
F_78 ( V_8 ) ;
F_79 ( V_8 ) ;
F_80 ( V_8 -> V_147 , 1 ) ;
F_81 ( V_8 ) ;
F_82 ( V_8 ) ;
F_83 ( V_8 ) ;
F_36 ( V_8 ) ;
F_26 ( V_8 ) ;
F_74 ( V_8 ) ;
F_75 ( V_8 ) ;
}
STATIC int
F_84 (
struct V_10 * V_11 ,
int V_212 )
{
struct V_7 * V_8 = F_77 ( V_11 ) ;
int error ;
if ( ! V_212 )
return 0 ;
error = F_85 ( V_8 ) ;
if ( error )
return - error ;
if ( V_213 ) {
F_86 ( & V_8 -> V_214 ) ;
}
return 0 ;
}
STATIC int
F_87 (
struct V_215 * V_215 ,
struct V_216 * V_217 )
{
struct V_7 * V_8 = F_77 ( V_215 -> V_218 ) ;
T_6 * V_219 = & V_8 -> V_158 ;
struct V_169 * V_170 = F_40 ( V_215 -> V_220 ) ;
T_2 V_221 , V_222 ;
T_7 V_223 ;
T_8 V_224 ;
V_217 -> V_225 = V_226 ;
V_217 -> V_227 = V_21 - 1 ;
V_222 = F_88 ( V_8 -> V_147 -> V_228 ) ;
V_217 -> V_229 . V_230 [ 0 ] = ( V_231 ) V_222 ;
V_217 -> V_229 . V_230 [ 1 ] = ( V_231 ) ( V_222 >> 32 ) ;
F_89 ( V_8 , V_232 ) ;
F_90 ( & V_8 -> V_233 ) ;
V_217 -> V_234 = V_219 -> V_159 ;
V_223 = V_219 -> V_235 ? V_219 -> V_236 : 0 ;
V_217 -> V_237 = V_219 -> V_238 - V_223 ;
V_217 -> V_239 = V_217 -> V_240 =
V_219 -> V_241 - F_91 ( V_8 ) ;
V_221 = V_217 -> V_239 << V_219 -> V_242 ;
V_217 -> V_243 =
F_92 ( V_219 -> V_244 + V_221 , ( T_2 ) V_245 ) ;
if ( V_8 -> V_246 )
V_217 -> V_243 = F_93 ( F_94 ( V_217 -> V_243 ) ,
V_217 -> V_243 ,
V_8 -> V_246 ) ;
V_224 = V_217 -> V_243 - ( V_219 -> V_244 - V_219 -> V_247 ) ;
V_217 -> V_248 = F_95 ( T_8 , V_224 , 0 ) ;
F_96 ( & V_8 -> V_233 ) ;
if ( ( V_170 -> V_190 . V_249 & V_250 ) ||
( ( V_8 -> V_81 & ( V_95 | V_97 ) ) ) ==
( V_95 | V_97 ) )
F_97 ( V_170 , V_217 ) ;
return 0 ;
}
STATIC void
F_98 ( struct V_7 * V_8 )
{
T_2 V_251 = 0 ;
V_8 -> V_252 = V_8 -> V_253 ;
F_99 ( V_8 , & V_251 , NULL ) ;
}
STATIC void
F_100 ( struct V_7 * V_8 )
{
T_2 V_251 ;
if ( V_8 -> V_252 ) {
V_251 = V_8 -> V_252 ;
V_8 -> V_252 = 0 ;
} else
V_251 = F_101 ( V_8 ) ;
F_99 ( V_8 , & V_251 , NULL ) ;
}
STATIC int
F_102 (
struct V_10 * V_11 ,
int * V_183 ,
char * V_9 )
{
struct V_7 * V_8 = F_77 ( V_11 ) ;
T_9 args [ V_254 ] ;
char * V_255 ;
int error ;
while ( ( V_255 = F_5 ( & V_9 , L_1 ) ) != NULL ) {
int V_256 ;
if ( ! * V_255 )
continue;
V_256 = F_103 ( V_255 , V_257 , args ) ;
switch ( V_256 ) {
case V_258 :
V_8 -> V_27 |= V_33 ;
break;
case V_259 :
V_8 -> V_27 &= ~ V_33 ;
break;
default:
#if 0
xfs_info(mp,
"mount option \"%s\" not supported for remount\n", p);
return -EINVAL;
#else
break;
#endif
}
}
if ( ( V_8 -> V_27 & V_28 ) && ! ( * V_183 & V_26 ) ) {
V_8 -> V_27 &= ~ V_28 ;
if ( V_8 -> V_260 ) {
error = F_104 ( V_8 , V_8 -> V_260 ) ;
if ( error ) {
F_6 ( V_8 , L_35 ) ;
return error ;
}
V_8 -> V_260 = 0 ;
}
F_100 ( V_8 ) ;
}
if ( ! ( V_8 -> V_27 & V_28 ) && ( * V_183 & V_26 ) ) {
F_85 ( V_8 ) ;
F_98 ( V_8 ) ;
F_105 ( V_8 ) ;
V_8 -> V_27 |= V_28 ;
}
return 0 ;
}
STATIC int
F_106 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_77 ( V_11 ) ;
F_98 ( V_8 ) ;
F_105 ( V_8 ) ;
return - F_107 ( V_8 ) ;
}
STATIC int
F_108 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_77 ( V_11 ) ;
F_100 ( V_8 ) ;
return 0 ;
}
STATIC int
F_109 (
struct V_121 * V_122 ,
struct V_215 * V_261 )
{
return - F_12 ( F_77 ( V_261 -> V_218 ) , V_122 ) ;
}
STATIC int
F_110 (
struct V_7 * V_8 )
{
int V_262 = ( V_8 -> V_27 & V_28 ) ;
if ( F_111 ( & V_8 -> V_158 ) ) {
if ( V_8 -> V_37 <= 0 &&
V_8 -> V_158 . V_263 > V_264 ) {
V_8 -> V_37 = V_8 -> V_158 . V_263 ;
} else if ( V_8 -> V_37 > 0 &&
V_8 -> V_37 < V_8 -> V_158 . V_263 ) {
F_6 ( V_8 ,
L_36 ) ;
return F_10 ( V_40 ) ;
}
} else {
if ( V_8 -> V_37 > V_264 ) {
F_6 ( V_8 ,
L_37 ) ;
return F_10 ( V_40 ) ;
}
}
if ( F_112 ( & V_8 -> V_158 ) &&
! ( V_8 -> V_27 & V_77 ) )
V_8 -> V_27 |= V_75 ;
if ( ( V_8 -> V_158 . V_265 & V_266 ) && ! V_262 ) {
F_6 ( V_8 ,
L_38 ) ;
return F_10 ( V_267 ) ;
}
return 0 ;
}
STATIC int
F_113 (
struct V_10 * V_11 ,
void * V_268 ,
int V_269 )
{
struct V_168 * V_261 ;
struct V_7 * V_8 = NULL ;
int V_183 = 0 , error = V_23 ;
V_8 = F_114 ( sizeof( struct V_7 ) , V_22 ) ;
if ( ! V_8 )
goto V_153;
F_52 ( & V_8 -> V_233 ) ;
F_115 ( & V_8 -> V_270 ) ;
F_51 ( & V_8 -> V_271 , 0 ) ;
V_8 -> V_12 = V_11 ;
V_11 -> V_272 = V_8 ;
error = F_3 ( V_8 , ( char * ) V_268 ) ;
if ( error )
goto V_273;
F_116 ( V_11 , V_162 ) ;
V_11 -> V_274 = V_275 ;
V_11 -> V_276 = & V_277 ;
#ifdef F_8
V_11 -> V_278 = & V_279 ;
#endif
V_11 -> V_280 = & V_281 ;
if ( V_269 )
V_183 |= V_282 ;
error = F_28 ( V_8 ) ;
if ( error )
goto V_273;
error = F_33 ( V_8 ) ;
if ( error )
goto V_283;
error = F_117 ( V_8 ) ;
if ( error )
goto V_284;
error = F_118 ( V_8 , V_183 ) ;
if ( error )
goto V_285;
error = F_110 ( V_8 ) ;
if ( error )
goto V_286;
error = F_30 ( V_8 ) ;
if ( error )
goto V_286;
error = F_119 ( V_8 ) ;
if ( error )
goto V_286;
V_11 -> V_287 = V_226 ;
V_11 -> V_288 = V_8 -> V_158 . V_159 ;
V_11 -> V_289 = F_7 ( V_11 -> V_288 ) - 1 ;
V_11 -> V_290 = F_16 ( V_11 -> V_289 ) ;
V_11 -> V_291 = V_292 ;
V_11 -> V_293 = 1 ;
F_120 ( V_11 ) ;
error = F_121 ( V_8 ) ;
if ( error )
goto V_294;
error = F_122 ( V_8 ) ;
if ( error )
goto V_295;
V_261 = F_123 ( F_50 ( V_8 -> V_296 ) ) ;
if ( ! V_261 ) {
error = V_297 ;
goto V_298;
}
if ( F_43 ( V_261 ) ) {
error = V_40 ;
goto V_298;
}
V_11 -> V_299 = F_124 ( V_261 ) ;
if ( ! V_11 -> V_299 ) {
error = V_23 ;
goto V_298;
}
return 0 ;
V_294:
F_79 ( V_8 ) ;
V_286:
F_82 ( V_8 ) ;
V_285:
F_83 ( V_8 ) ;
V_284:
F_36 ( V_8 ) ;
V_283:
F_26 ( V_8 ) ;
V_273:
F_74 ( V_8 ) ;
F_75 ( V_8 ) ;
V_153:
return - error ;
V_298:
F_78 ( V_8 ) ;
V_295:
F_79 ( V_8 ) ;
F_80 ( V_8 -> V_147 , 1 ) ;
F_81 ( V_8 ) ;
goto V_286;
}
STATIC struct V_215 *
F_125 (
struct V_300 * V_301 ,
int V_183 ,
const char * V_302 ,
void * V_268 )
{
return F_126 ( V_301 , V_183 , V_302 , V_268 , F_113 ) ;
}
static int
F_127 (
struct V_10 * V_11 )
{
return F_128 ( F_77 ( V_11 ) ) ;
}
static void
F_129 (
struct V_10 * V_11 ,
int V_303 )
{
F_130 ( F_77 ( V_11 ) , V_303 ) ;
}
STATIC int T_10
F_131 ( void )
{
V_304 = F_132 ( sizeof( V_305 ) , L_39 ) ;
if ( ! V_304 )
goto V_153;
V_306 = F_133 ( 4 * V_307 ,
V_304 ) ;
if ( ! V_306 )
goto V_308;
V_309 = F_132 ( sizeof( V_310 ) ,
L_40 ) ;
if ( ! V_309 )
goto V_311;
V_312 = F_132 ( sizeof( V_313 ) ,
L_41 ) ;
if ( ! V_312 )
goto V_314;
V_315 = F_132 ( sizeof( V_316 ) ,
L_42 ) ;
if ( ! V_315 )
goto V_317;
V_318 = F_132 ( sizeof( V_319 ) ,
L_43 ) ;
if ( ! V_318 )
goto V_320;
V_321 = F_132 ( sizeof( V_322 ) , L_44 ) ;
if ( ! V_321 )
goto V_323;
V_324 = F_132 ( sizeof( V_325 ) , L_45 ) ;
if ( ! V_324 )
goto V_326;
V_327 = F_132 ( sizeof( V_328 ) , L_46 ) ;
if ( ! V_327 )
goto V_329;
V_330 =
F_132 ( sizeof( struct V_331 ) ,
L_47 ) ;
if ( ! V_330 )
goto V_332;
V_333 = F_132 ( ( sizeof( V_334 ) +
( ( ( V_335 / V_336 ) /
V_337 ) * sizeof( int ) ) ) , L_48 ) ;
if ( ! V_333 )
goto V_338;
V_339 = F_132 ( ( sizeof( V_340 ) +
( ( V_341 - 1 ) *
sizeof( V_342 ) ) ) , L_49 ) ;
if ( ! V_339 )
goto V_343;
V_344 = F_132 ( ( sizeof( V_345 ) +
( ( V_346 - 1 ) *
sizeof( V_342 ) ) ) , L_50 ) ;
if ( ! V_344 )
goto V_347;
V_348 =
F_134 ( sizeof( T_5 ) , L_51 ,
V_349 | V_350 | V_351 ,
F_48 ) ;
if ( ! V_348 )
goto V_352;
V_353 =
F_134 ( sizeof( V_354 ) , L_52 ,
V_351 , NULL ) ;
if ( ! V_353 )
goto V_355;
return 0 ;
V_355:
F_135 ( V_348 ) ;
V_352:
F_135 ( V_344 ) ;
V_347:
F_135 ( V_339 ) ;
V_343:
F_135 ( V_333 ) ;
V_338:
F_135 ( V_330 ) ;
V_332:
F_135 ( V_327 ) ;
V_329:
F_135 ( V_324 ) ;
V_326:
F_135 ( V_321 ) ;
V_323:
F_135 ( V_318 ) ;
V_320:
F_135 ( V_315 ) ;
V_317:
F_135 ( V_312 ) ;
V_314:
F_135 ( V_309 ) ;
V_311:
F_136 ( V_306 ) ;
V_308:
F_135 ( V_304 ) ;
V_153:
return - V_23 ;
}
STATIC void
F_137 ( void )
{
F_135 ( V_353 ) ;
F_135 ( V_348 ) ;
F_135 ( V_344 ) ;
F_135 ( V_339 ) ;
F_135 ( V_333 ) ;
F_135 ( V_330 ) ;
F_135 ( V_327 ) ;
F_135 ( V_324 ) ;
F_135 ( V_321 ) ;
F_135 ( V_318 ) ;
F_135 ( V_315 ) ;
F_135 ( V_312 ) ;
F_135 ( V_309 ) ;
F_136 ( V_306 ) ;
F_135 ( V_304 ) ;
}
STATIC int T_10
F_138 ( void )
{
V_356 = F_34 ( L_53 , V_357 , 0 ) ;
if ( ! V_356 )
return - V_23 ;
V_358 = F_34 ( L_54 , V_165 , 0 ) ;
if ( ! V_358 )
goto V_359;
return 0 ;
V_359:
F_35 ( V_356 ) ;
return - V_23 ;
}
STATIC void
F_139 ( void )
{
F_35 ( V_358 ) ;
F_35 ( V_356 ) ;
}
STATIC int T_10
F_140 ( void )
{
int error ;
F_141 (KERN_INFO XFS_VERSION_STRING L_55
XFS_BUILD_OPTIONS L_56 ) ;
F_142 () ;
error = F_131 () ;
if ( error )
goto V_153;
error = F_138 () ;
if ( error )
goto V_360;
error = F_143 () ;
if ( error )
goto V_361;
error = F_144 () ;
if ( error )
goto V_362;
error = F_145 () ;
if ( error )
goto V_363;
error = F_146 () ;
if ( error )
goto V_364;
error = F_147 () ;
if ( error )
goto V_365;
error = F_148 () ;
if ( error )
goto V_366;
error = F_149 ( & V_367 ) ;
if ( error )
goto V_368;
return 0 ;
V_368:
F_150 () ;
V_366:
F_151 () ;
V_365:
F_152 () ;
V_364:
F_153 () ;
V_363:
F_154 () ;
V_362:
F_155 () ;
V_361:
F_139 () ;
V_360:
F_137 () ;
V_153:
return error ;
}
STATIC void T_11
F_156 ( void )
{
F_150 () ;
F_157 ( & V_367 ) ;
F_151 () ;
F_152 () ;
F_153 () ;
F_154 () ;
F_155 () ;
F_139 () ;
F_137 () ;
}
