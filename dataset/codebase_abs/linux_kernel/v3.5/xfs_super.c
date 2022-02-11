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
F_25 ( V_144 -> V_145 , V_146 , NULL ) ;
}
STATIC void
F_26 (
struct V_7 * V_8 )
{
if ( V_8 -> V_147 && V_8 -> V_147 != V_8 -> V_148 ) {
struct V_138 * V_149 = V_8 -> V_147 -> V_145 ;
F_27 ( V_8 , V_8 -> V_147 ) ;
F_22 ( V_149 ) ;
}
if ( V_8 -> V_150 ) {
struct V_138 * V_151 = V_8 -> V_150 -> V_145 ;
F_27 ( V_8 , V_8 -> V_150 ) ;
F_22 ( V_151 ) ;
}
F_27 ( V_8 , V_8 -> V_148 ) ;
}
STATIC int
F_28 (
struct V_7 * V_8 )
{
struct V_138 * V_152 = V_8 -> V_12 -> V_153 ;
struct V_138 * V_149 = NULL , * V_151 = NULL ;
int error ;
if ( V_8 -> V_43 ) {
error = F_18 ( V_8 , V_8 -> V_43 , & V_149 ) ;
if ( error )
goto V_154;
}
if ( V_8 -> V_46 ) {
error = F_18 ( V_8 , V_8 -> V_46 , & V_151 ) ;
if ( error )
goto V_155;
if ( V_151 == V_152 || V_151 == V_149 ) {
F_6 ( V_8 ,
L_28 ) ;
error = V_40 ;
goto V_156;
}
}
error = V_23 ;
V_8 -> V_148 = F_29 ( V_8 , V_152 , 0 , V_8 -> V_19 ) ;
if ( ! V_8 -> V_148 )
goto V_156;
if ( V_151 ) {
V_8 -> V_150 = F_29 ( V_8 , V_151 , 1 ,
V_8 -> V_19 ) ;
if ( ! V_8 -> V_150 )
goto V_157;
}
if ( V_149 && V_149 != V_152 ) {
V_8 -> V_147 = F_29 ( V_8 , V_149 , 1 ,
V_8 -> V_19 ) ;
if ( ! V_8 -> V_147 )
goto V_158;
} else {
V_8 -> V_147 = V_8 -> V_148 ;
}
return 0 ;
V_158:
if ( V_8 -> V_150 )
F_27 ( V_8 , V_8 -> V_150 ) ;
V_157:
F_27 ( V_8 , V_8 -> V_148 ) ;
V_156:
if ( V_151 )
F_22 ( V_151 ) ;
V_155:
if ( V_149 && V_149 != V_152 )
F_22 ( V_149 ) ;
V_154:
return error ;
}
STATIC int
F_30 (
struct V_7 * V_8 )
{
int error ;
error = F_31 ( V_8 -> V_148 , V_8 -> V_159 . V_160 ,
V_8 -> V_159 . V_161 ) ;
if ( error )
return error ;
if ( V_8 -> V_147 && V_8 -> V_147 != V_8 -> V_148 ) {
unsigned int V_162 = V_163 ;
if ( F_32 ( & V_8 -> V_159 ) )
V_162 = V_8 -> V_159 . V_164 ;
error = F_31 ( V_8 -> V_147 ,
V_8 -> V_159 . V_160 ,
V_162 ) ;
if ( error )
return error ;
}
if ( V_8 -> V_150 ) {
error = F_31 ( V_8 -> V_150 ,
V_8 -> V_159 . V_160 ,
V_8 -> V_159 . V_161 ) ;
if ( error )
return error ;
}
return 0 ;
}
STATIC int
F_33 (
struct V_7 * V_8 )
{
V_8 -> V_165 = F_34 ( L_29 ,
V_166 , 0 , V_8 -> V_19 ) ;
if ( ! V_8 -> V_165 )
goto V_154;
V_8 -> V_167 = F_34 ( L_30 ,
V_166 , 0 , V_8 -> V_19 ) ;
if ( ! V_8 -> V_167 )
goto V_168;
V_8 -> V_169 = F_34 ( L_31 ,
V_166 , 0 , V_8 -> V_19 ) ;
if ( ! V_8 -> V_169 )
goto V_170;
return 0 ;
V_170:
F_35 ( V_8 -> V_167 ) ;
V_168:
F_35 ( V_8 -> V_165 ) ;
V_154:
return - V_23 ;
}
STATIC void
F_36 (
struct V_7 * V_8 )
{
F_35 ( V_8 -> V_169 ) ;
F_35 ( V_8 -> V_165 ) ;
F_35 ( V_8 -> V_167 ) ;
}
STATIC struct V_171 *
F_37 (
struct V_10 * V_11 )
{
F_38 () ;
return NULL ;
}
STATIC void
F_39 (
struct V_171 * V_171 )
{
struct V_172 * V_173 = F_40 ( V_171 ) ;
F_41 ( V_173 ) ;
F_42 ( V_174 ) ;
if ( F_43 ( V_171 ) )
goto V_175;
ASSERT ( F_44 ( V_173 -> V_176 ) || V_173 -> V_177 == 0 ) ;
F_45 ( ! F_46 ( V_173 , V_178 ) ) ;
F_45 ( ! F_46 ( V_173 , V_179 ) ) ;
V_175:
F_47 ( V_173 ) ;
}
STATIC void
F_48 (
void * V_171 )
{
struct V_172 * V_173 = V_171 ;
memset ( V_173 , 0 , sizeof( struct V_172 ) ) ;
F_49 ( F_50 ( V_173 ) ) ;
F_51 ( & V_173 -> V_180 , 0 ) ;
F_52 ( & V_173 -> V_181 ) ;
F_53 ( & V_173 -> V_182 , V_183 | V_184 ,
L_32 , V_173 -> V_185 ) ;
}
STATIC void
F_54 (
struct V_171 * V_171 ,
int V_186 )
{
struct V_172 * V_173 = F_40 ( V_171 ) ;
struct V_7 * V_8 = V_173 -> V_176 ;
struct V_187 * V_188 ;
int error ;
if ( V_186 != V_189 )
return;
F_55 ( V_173 ) ;
V_188 = F_56 ( V_8 , V_190 ) ;
error = F_57 ( V_188 , 0 , F_58 ( V_8 ) , 0 , 0 , 0 ) ;
if ( error ) {
F_59 ( V_188 , 0 ) ;
goto V_191;
}
F_60 ( V_173 , V_192 ) ;
V_173 -> V_193 . V_194 . V_195 = ( V_196 ) V_171 -> V_197 . V_198 ;
V_173 -> V_193 . V_194 . V_199 = ( V_196 ) V_171 -> V_197 . V_200 ;
V_173 -> V_193 . V_201 . V_195 = ( V_196 ) V_171 -> V_202 . V_198 ;
V_173 -> V_193 . V_201 . V_199 = ( V_196 ) V_171 -> V_202 . V_200 ;
V_173 -> V_193 . V_203 . V_195 = ( V_196 ) V_171 -> V_204 . V_198 ;
V_173 -> V_193 . V_203 . V_199 = ( V_196 ) V_171 -> V_204 . V_200 ;
F_61 ( V_188 , V_173 , V_192 ) ;
F_62 ( V_188 , V_173 , V_205 ) ;
error = F_63 ( V_188 , 0 ) ;
if ( error )
goto V_191;
return;
V_191:
F_6 ( V_8 , L_33 , V_173 -> V_185 ) ;
}
STATIC void
F_64 (
struct V_171 * V_171 )
{
T_5 * V_173 = F_40 ( V_171 ) ;
F_65 ( V_173 ) ;
F_66 ( & V_171 -> V_206 , 0 ) ;
F_67 ( V_171 ) ;
F_42 ( V_207 ) ;
F_42 ( V_208 ) ;
F_68 ( V_209 ) ;
ASSERT ( ! F_69 ( & V_173 -> V_210 . V_211 ) ) ;
F_53 ( & V_173 -> V_210 , V_184 , L_34 , V_173 -> V_185 ) ;
F_70 ( & V_173 -> V_210 . V_211 ,
& V_212 , L_35 ) ;
F_71 ( V_173 ) ;
}
STATIC int
F_72 (
struct V_171 * V_171 )
{
struct V_172 * V_173 = F_40 ( V_171 ) ;
return F_73 ( V_171 ) || ( V_173 -> V_213 & V_214 ) ;
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
F_80 ( V_8 ) ;
F_81 ( V_8 ) ;
F_82 ( V_8 ) ;
F_36 ( V_8 ) ;
F_26 ( V_8 ) ;
F_74 ( V_8 ) ;
F_75 ( V_8 ) ;
}
STATIC int
F_83 (
struct V_10 * V_11 ,
int V_215 )
{
struct V_7 * V_8 = F_77 ( V_11 ) ;
int error ;
if ( ! V_215 )
return 0 ;
error = F_84 ( V_8 ) ;
if ( error )
return - error ;
if ( V_216 ) {
F_85 ( & V_8 -> V_217 ) ;
}
return 0 ;
}
STATIC int
F_86 (
struct V_218 * V_218 ,
struct V_219 * V_220 )
{
struct V_7 * V_8 = F_77 ( V_218 -> V_221 ) ;
T_6 * V_222 = & V_8 -> V_159 ;
struct V_172 * V_173 = F_40 ( V_218 -> V_223 ) ;
T_2 V_224 , V_225 ;
T_7 V_226 ;
T_8 V_227 ;
V_220 -> V_228 = V_229 ;
V_220 -> V_230 = V_21 - 1 ;
V_225 = F_87 ( V_8 -> V_148 -> V_231 ) ;
V_220 -> V_232 . V_233 [ 0 ] = ( V_234 ) V_225 ;
V_220 -> V_232 . V_233 [ 1 ] = ( V_234 ) ( V_225 >> 32 ) ;
F_88 ( V_8 , V_235 ) ;
F_89 ( & V_8 -> V_236 ) ;
V_220 -> V_237 = V_222 -> V_160 ;
V_226 = V_222 -> V_238 ? V_222 -> V_239 : 0 ;
V_220 -> V_240 = V_222 -> V_241 - V_226 ;
V_220 -> V_242 = V_220 -> V_243 =
V_222 -> V_244 - F_90 ( V_8 ) ;
V_224 = V_220 -> V_242 << V_222 -> V_245 ;
V_220 -> V_246 =
F_91 ( V_222 -> V_247 + V_224 , ( T_2 ) V_248 ) ;
if ( V_8 -> V_249 )
V_220 -> V_246 = F_92 ( F_93 ( V_220 -> V_246 ) ,
V_220 -> V_246 ,
V_8 -> V_249 ) ;
V_227 = V_220 -> V_246 - ( V_222 -> V_247 - V_222 -> V_250 ) ;
V_220 -> V_251 = F_94 ( T_8 , V_227 , 0 ) ;
F_95 ( & V_8 -> V_236 ) ;
if ( ( V_173 -> V_193 . V_252 & V_253 ) &&
( ( V_8 -> V_81 & ( V_95 | V_97 ) ) ) ==
( V_95 | V_97 ) )
F_96 ( V_173 , V_220 ) ;
return 0 ;
}
STATIC void
F_97 ( struct V_7 * V_8 )
{
T_2 V_254 = 0 ;
V_8 -> V_255 = V_8 -> V_256 ;
F_98 ( V_8 , & V_254 , NULL ) ;
}
STATIC void
F_99 ( struct V_7 * V_8 )
{
T_2 V_254 ;
if ( V_8 -> V_255 ) {
V_254 = V_8 -> V_255 ;
V_8 -> V_255 = 0 ;
} else
V_254 = F_100 ( V_8 ) ;
F_98 ( V_8 , & V_254 , NULL ) ;
}
STATIC int
F_101 (
struct V_10 * V_11 ,
int * V_186 ,
char * V_9 )
{
struct V_7 * V_8 = F_77 ( V_11 ) ;
T_9 args [ V_257 ] ;
char * V_258 ;
int error ;
while ( ( V_258 = F_5 ( & V_9 , L_1 ) ) != NULL ) {
int V_259 ;
if ( ! * V_258 )
continue;
V_259 = F_102 ( V_258 , V_260 , args ) ;
switch ( V_259 ) {
case V_261 :
V_8 -> V_27 |= V_33 ;
break;
case V_262 :
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
if ( ( V_8 -> V_27 & V_28 ) && ! ( * V_186 & V_26 ) ) {
V_8 -> V_27 &= ~ V_28 ;
if ( V_8 -> V_263 ) {
error = F_103 ( V_8 , V_8 -> V_263 ) ;
if ( error ) {
F_6 ( V_8 , L_36 ) ;
return error ;
}
V_8 -> V_263 = 0 ;
}
F_99 ( V_8 ) ;
}
if ( ! ( V_8 -> V_27 & V_28 ) && ( * V_186 & V_26 ) ) {
F_84 ( V_8 ) ;
F_97 ( V_8 ) ;
F_104 ( V_8 ) ;
V_8 -> V_27 |= V_28 ;
}
return 0 ;
}
STATIC int
F_105 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_77 ( V_11 ) ;
F_97 ( V_8 ) ;
F_104 ( V_8 ) ;
return - F_106 ( V_8 ) ;
}
STATIC int
F_107 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_77 ( V_11 ) ;
F_99 ( V_8 ) ;
return 0 ;
}
STATIC int
F_108 (
struct V_121 * V_122 ,
struct V_218 * V_264 )
{
return - F_12 ( F_77 ( V_264 -> V_221 ) , V_122 ) ;
}
STATIC int
F_109 (
struct V_7 * V_8 )
{
int V_265 = ( V_8 -> V_27 & V_28 ) ;
if ( F_110 ( & V_8 -> V_159 ) ) {
if ( V_8 -> V_37 <= 0 &&
V_8 -> V_159 . V_266 > V_267 ) {
V_8 -> V_37 = V_8 -> V_159 . V_266 ;
} else if ( V_8 -> V_37 > 0 &&
V_8 -> V_37 < V_8 -> V_159 . V_266 ) {
F_6 ( V_8 ,
L_37 ) ;
return F_10 ( V_40 ) ;
}
} else {
if ( V_8 -> V_37 > V_267 ) {
F_6 ( V_8 ,
L_38 ) ;
return F_10 ( V_40 ) ;
}
}
if ( F_111 ( & V_8 -> V_159 ) &&
! ( V_8 -> V_27 & V_77 ) )
V_8 -> V_27 |= V_75 ;
if ( ( V_8 -> V_159 . V_268 & V_269 ) && ! V_265 ) {
F_6 ( V_8 ,
L_39 ) ;
return F_10 ( V_270 ) ;
}
return 0 ;
}
STATIC int
F_112 (
struct V_10 * V_11 ,
void * V_271 ,
int V_272 )
{
struct V_171 * V_264 ;
struct V_7 * V_8 = NULL ;
int V_186 = 0 , error = V_23 ;
V_8 = F_113 ( sizeof( struct V_7 ) , V_22 ) ;
if ( ! V_8 )
goto V_154;
F_52 ( & V_8 -> V_236 ) ;
F_114 ( & V_8 -> V_273 ) ;
F_51 ( & V_8 -> V_274 , 0 ) ;
V_8 -> V_12 = V_11 ;
V_11 -> V_275 = V_8 ;
error = F_3 ( V_8 , ( char * ) V_271 ) ;
if ( error )
goto V_276;
F_115 ( V_11 , V_163 ) ;
V_11 -> V_277 = V_278 ;
V_11 -> V_279 = & V_280 ;
#ifdef F_8
V_11 -> V_281 = & V_282 ;
#endif
V_11 -> V_283 = & V_284 ;
if ( V_272 )
V_186 |= V_285 ;
error = F_28 ( V_8 ) ;
if ( error )
goto V_276;
error = F_33 ( V_8 ) ;
if ( error )
goto V_286;
error = F_116 ( V_8 ) ;
if ( error )
goto V_287;
error = F_117 ( V_8 , V_186 ) ;
if ( error )
goto V_288;
error = F_109 ( V_8 ) ;
if ( error )
goto V_289;
error = F_30 ( V_8 ) ;
if ( error )
goto V_289;
error = F_118 ( V_8 ) ;
if ( error )
goto V_289;
V_11 -> V_290 = V_229 ;
V_11 -> V_291 = V_8 -> V_159 . V_160 ;
V_11 -> V_292 = F_7 ( V_11 -> V_291 ) - 1 ;
V_11 -> V_293 = F_16 ( V_11 -> V_292 ) ;
V_11 -> V_294 = V_295 ;
V_11 -> V_296 = 1 ;
F_119 ( V_11 ) ;
error = F_120 ( V_8 ) ;
if ( error )
goto V_297;
error = F_121 ( V_8 ) ;
if ( error )
goto V_298;
V_264 = F_122 ( F_50 ( V_8 -> V_299 ) ) ;
if ( ! V_264 ) {
error = V_300 ;
goto V_301;
}
if ( F_43 ( V_264 ) ) {
error = V_40 ;
goto V_301;
}
V_11 -> V_302 = F_123 ( V_264 ) ;
if ( ! V_11 -> V_302 ) {
error = V_23 ;
goto V_301;
}
return 0 ;
V_298:
F_80 ( V_8 ) ;
V_297:
F_78 ( V_8 ) ;
V_289:
F_81 ( V_8 ) ;
V_288:
F_82 ( V_8 ) ;
V_287:
F_36 ( V_8 ) ;
V_286:
F_26 ( V_8 ) ;
V_276:
F_74 ( V_8 ) ;
F_75 ( V_8 ) ;
V_154:
return - error ;
V_301:
F_78 ( V_8 ) ;
F_79 ( V_8 ) ;
F_80 ( V_8 ) ;
goto V_289;
}
STATIC struct V_218 *
F_124 (
struct V_303 * V_304 ,
int V_186 ,
const char * V_305 ,
void * V_271 )
{
return F_125 ( V_304 , V_186 , V_305 , V_271 , F_112 ) ;
}
static int
F_126 (
struct V_10 * V_11 )
{
return F_127 ( F_77 ( V_11 ) ) ;
}
static void
F_128 (
struct V_10 * V_11 ,
int V_306 )
{
F_129 ( F_77 ( V_11 ) , V_306 ) ;
}
STATIC int T_10
F_130 ( void )
{
V_307 = F_131 ( sizeof( V_308 ) , L_40 ) ;
if ( ! V_307 )
goto V_154;
V_309 = F_132 ( 4 * V_310 ,
V_307 ) ;
if ( ! V_309 )
goto V_311;
V_312 = F_131 ( sizeof( V_313 ) ,
L_41 ) ;
if ( ! V_312 )
goto V_314;
V_315 = F_131 ( sizeof( V_316 ) ,
L_42 ) ;
if ( ! V_315 )
goto V_317;
V_318 = F_131 ( sizeof( V_319 ) ,
L_43 ) ;
if ( ! V_318 )
goto V_320;
V_321 = F_131 ( sizeof( V_322 ) ,
L_44 ) ;
if ( ! V_321 )
goto V_323;
V_324 = F_131 ( sizeof( V_325 ) , L_45 ) ;
if ( ! V_324 )
goto V_326;
V_327 = F_131 ( sizeof( V_328 ) , L_46 ) ;
if ( ! V_327 )
goto V_329;
V_330 = F_131 ( sizeof( V_331 ) , L_47 ) ;
if ( ! V_330 )
goto V_332;
V_333 =
F_131 ( sizeof( struct V_334 ) ,
L_48 ) ;
if ( ! V_333 )
goto V_335;
V_336 = F_131 ( ( sizeof( V_337 ) +
( ( ( V_338 / V_339 ) /
V_340 ) * sizeof( int ) ) ) , L_49 ) ;
if ( ! V_336 )
goto V_341;
V_342 = F_131 ( ( sizeof( V_343 ) +
( ( V_344 - 1 ) *
sizeof( V_345 ) ) ) , L_50 ) ;
if ( ! V_342 )
goto V_346;
V_347 = F_131 ( ( sizeof( V_348 ) +
( ( V_349 - 1 ) *
sizeof( V_345 ) ) ) , L_51 ) ;
if ( ! V_347 )
goto V_350;
V_351 =
F_133 ( sizeof( T_5 ) , L_52 ,
V_352 | V_353 | V_354 ,
F_48 ) ;
if ( ! V_351 )
goto V_355;
V_356 =
F_133 ( sizeof( V_357 ) , L_53 ,
V_354 , NULL ) ;
if ( ! V_356 )
goto V_358;
return 0 ;
V_358:
F_134 ( V_351 ) ;
V_355:
F_134 ( V_347 ) ;
V_350:
F_134 ( V_342 ) ;
V_346:
F_134 ( V_336 ) ;
V_341:
F_134 ( V_333 ) ;
V_335:
F_134 ( V_330 ) ;
V_332:
F_134 ( V_327 ) ;
V_329:
F_134 ( V_324 ) ;
V_326:
F_134 ( V_321 ) ;
V_323:
F_134 ( V_318 ) ;
V_320:
F_134 ( V_315 ) ;
V_317:
F_134 ( V_312 ) ;
V_314:
F_135 ( V_309 ) ;
V_311:
F_134 ( V_307 ) ;
V_154:
return - V_23 ;
}
STATIC void
F_136 ( void )
{
F_134 ( V_356 ) ;
F_134 ( V_351 ) ;
F_134 ( V_347 ) ;
F_134 ( V_342 ) ;
F_134 ( V_336 ) ;
F_134 ( V_333 ) ;
F_134 ( V_330 ) ;
F_134 ( V_327 ) ;
F_134 ( V_324 ) ;
F_134 ( V_321 ) ;
F_134 ( V_318 ) ;
F_134 ( V_315 ) ;
F_134 ( V_312 ) ;
F_135 ( V_309 ) ;
F_134 ( V_307 ) ;
}
STATIC int T_10
F_137 ( void )
{
V_359 = F_34 ( L_54 , V_360 , 0 ) ;
if ( ! V_359 )
return - V_23 ;
V_361 = F_34 ( L_55 , V_166 , 0 ) ;
if ( ! V_361 )
goto V_362;
return 0 ;
V_362:
F_35 ( V_359 ) ;
return - V_23 ;
}
STATIC void
F_138 ( void )
{
F_35 ( V_361 ) ;
F_35 ( V_359 ) ;
}
STATIC int T_10
F_139 ( void )
{
int error ;
F_140 (KERN_INFO XFS_VERSION_STRING L_56
XFS_BUILD_OPTIONS L_57 ) ;
F_141 () ;
error = F_130 () ;
if ( error )
goto V_154;
error = F_137 () ;
if ( error )
goto V_363;
error = F_142 () ;
if ( error )
goto V_364;
error = F_143 () ;
if ( error )
goto V_365;
error = F_144 () ;
if ( error )
goto V_366;
error = F_145 () ;
if ( error )
goto V_367;
error = F_146 () ;
if ( error )
goto V_368;
error = F_147 () ;
if ( error )
goto V_369;
error = F_148 ( & V_370 ) ;
if ( error )
goto V_371;
return 0 ;
V_371:
F_149 () ;
V_369:
F_150 () ;
V_368:
F_151 () ;
V_367:
F_152 () ;
V_366:
F_153 () ;
V_365:
F_154 () ;
V_364:
F_138 () ;
V_363:
F_136 () ;
V_154:
return error ;
}
STATIC void T_11
F_155 ( void )
{
F_149 () ;
F_156 ( & V_370 ) ;
F_150 () ;
F_151 () ;
F_152 () ;
F_153 () ;
F_154 () ;
F_138 () ;
F_136 () ;
}
