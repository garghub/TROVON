STATIC unsigned long
F_1 ( char * V_1 , unsigned int V_2 , int * V_3 )
{
int V_4 , V_5 = 0 , V_6 ;
char * V_7 = V_1 ;
V_4 = strlen ( V_7 ) - 1 ;
if ( V_7 [ V_4 ] == 'K' || V_7 [ V_4 ] == 'k' ) {
V_5 = 10 ;
V_7 [ V_4 ] = '\0' ;
}
if ( V_7 [ V_4 ] == 'M' || V_7 [ V_4 ] == 'm' ) {
V_5 = 20 ;
V_7 [ V_4 ] = '\0' ;
}
if ( V_7 [ V_4 ] == 'G' || V_7 [ V_4 ] == 'g' ) {
V_5 = 30 ;
V_7 [ V_4 ] = '\0' ;
}
if ( F_2 ( V_1 , V_2 , & V_6 ) )
return - V_8 ;
* V_3 = V_6 << V_5 ;
return 0 ;
}
STATIC int
F_3 (
struct V_9 * V_10 ,
char * V_11 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
char * V_15 , * V_7 ;
int V_16 = 0 ;
int V_17 = 0 ;
int V_18 = 0 ;
T_1 V_19 = 0 ;
V_10 -> V_20 = F_4 ( V_13 -> V_21 , V_22 , V_23 ) ;
if ( ! V_10 -> V_20 )
return - V_24 ;
V_10 -> V_25 = strlen ( V_10 -> V_20 ) + 1 ;
if ( V_13 -> V_26 & V_27 )
V_10 -> V_28 |= V_29 ;
if ( V_13 -> V_26 & V_30 )
V_10 -> V_28 |= V_31 ;
if ( V_13 -> V_26 & V_32 )
V_10 -> V_28 |= V_33 ;
V_10 -> V_28 |= V_34 ;
V_10 -> V_28 |= V_35 ;
V_10 -> V_36 = - 1 ;
V_10 -> V_37 = - 1 ;
if ( ! V_11 )
goto V_38;
while ( ( V_15 = F_5 ( & V_11 , L_1 ) ) != NULL ) {
if ( ! * V_15 )
continue;
if ( ( V_7 = strchr ( V_15 , '=' ) ) != NULL )
* V_7 ++ = 0 ;
if ( ! strcmp ( V_15 , V_39 ) ) {
if ( ! V_7 || ! * V_7 ) {
F_6 ( V_10 , L_2 ,
V_15 ) ;
return - V_8 ;
}
if ( F_2 ( V_7 , 10 , & V_10 -> V_36 ) )
return - V_8 ;
} else if ( ! strcmp ( V_15 , V_40 ) ) {
if ( ! V_7 || ! * V_7 ) {
F_6 ( V_10 , L_2 ,
V_15 ) ;
return - V_8 ;
}
if ( F_1 ( V_7 , 10 , & V_10 -> V_37 ) )
return - V_8 ;
} else if ( ! strcmp ( V_15 , V_41 ) ) {
if ( ! V_7 || ! * V_7 ) {
F_6 ( V_10 , L_2 ,
V_15 ) ;
return - V_8 ;
}
V_10 -> V_42 = F_4 ( V_7 , V_22 , V_23 ) ;
if ( ! V_10 -> V_42 )
return - V_24 ;
} else if ( ! strcmp ( V_15 , V_43 ) ) {
F_6 ( V_10 , L_3 ,
V_15 ) ;
return - V_8 ;
} else if ( ! strcmp ( V_15 , V_44 ) ) {
if ( ! V_7 || ! * V_7 ) {
F_6 ( V_10 , L_2 ,
V_15 ) ;
return - V_8 ;
}
V_10 -> V_45 = F_4 ( V_7 , V_22 , V_23 ) ;
if ( ! V_10 -> V_45 )
return - V_24 ;
} else if ( ! strcmp ( V_15 , V_46 ) ||
! strcmp ( V_15 , V_47 ) ) {
if ( ! V_7 || ! * V_7 ) {
F_6 ( V_10 , L_2 ,
V_15 ) ;
return - V_8 ;
}
if ( F_1 ( V_7 , 10 , & V_18 ) )
return - V_8 ;
V_19 = F_7 ( V_18 ) - 1 ;
} else if ( ! strcmp ( V_15 , V_48 ) ||
! strcmp ( V_15 , V_49 ) ) {
V_10 -> V_28 |= V_50 ;
} else if ( ! strcmp ( V_15 , V_51 ) ||
! strcmp ( V_15 , V_52 ) ) {
V_10 -> V_28 &= ~ V_50 ;
} else if ( ! strcmp ( V_15 , V_53 ) ) {
V_10 -> V_28 |= V_33 ;
} else if ( ! strcmp ( V_15 , V_54 ) ) {
V_10 -> V_28 |= V_55 ;
} else if ( ! strcmp ( V_15 , V_56 ) ) {
V_10 -> V_28 |= V_57 ;
} else if ( ! strcmp ( V_15 , V_58 ) ) {
V_10 -> V_28 |= V_59 ;
} else if ( ! strcmp ( V_15 , V_60 ) ) {
if ( ! V_7 || ! * V_7 ) {
F_6 ( V_10 , L_2 ,
V_15 ) ;
return - V_8 ;
}
if ( F_2 ( V_7 , 10 , & V_16 ) )
return - V_8 ;
} else if ( ! strcmp ( V_15 , V_61 ) ) {
if ( ! V_7 || ! * V_7 ) {
F_6 ( V_10 , L_2 ,
V_15 ) ;
return - V_8 ;
}
if ( F_2 ( V_7 , 10 , & V_17 ) )
return - V_8 ;
} else if ( ! strcmp ( V_15 , V_62 ) ) {
V_10 -> V_28 |= V_63 ;
} else if ( ! strcmp ( V_15 , V_64 ) ) {
V_10 -> V_28 &= ~ V_63 ;
} else if ( ! strcmp ( V_15 , V_65 ) ) {
V_10 -> V_28 |= V_66 ;
} else if ( ! strcmp ( V_15 , V_67 ) ) {
V_10 -> V_28 |= V_34 ;
} else if ( ! strcmp ( V_15 , V_68 ) ) {
V_10 -> V_28 &= ~ V_34 ;
} else if ( ! strcmp ( V_15 , V_69 ) ) {
V_10 -> V_28 |= V_70 ;
} else if ( ! strcmp ( V_15 , V_71 ) ) {
V_10 -> V_28 &= ~ V_70 ;
} else if ( ! strcmp ( V_15 , V_72 ) ) {
V_10 -> V_28 &= ~ V_35 ;
} else if ( ! strcmp ( V_15 , V_73 ) ) {
V_10 -> V_28 |= V_35 ;
} else if ( ! strcmp ( V_15 , V_74 ) ) {
V_10 -> V_28 |= V_75 ;
} else if ( ! strcmp ( V_15 , V_76 ) ) {
V_10 -> V_28 &= ~ V_75 ;
V_10 -> V_28 |= V_77 ;
} else if ( ! strcmp ( V_15 , V_78 ) ) {
V_10 -> V_28 |= V_79 ;
} else if ( ! strcmp ( V_15 , V_80 ) ) {
V_10 -> V_81 &= ~ V_82 ;
V_10 -> V_81 &= ~ V_83 ;
V_10 -> V_81 &= ~ V_84 ;
} else if ( ! strcmp ( V_15 , V_85 ) ||
! strcmp ( V_15 , V_86 ) ||
! strcmp ( V_15 , V_87 ) ) {
V_10 -> V_81 |= ( V_88 | V_89 |
V_90 ) ;
} else if ( ! strcmp ( V_15 , V_91 ) ||
! strcmp ( V_15 , V_92 ) ) {
V_10 -> V_81 |= ( V_88 | V_89 ) ;
V_10 -> V_81 &= ~ V_90 ;
} else if ( ! strcmp ( V_15 , V_93 ) ||
! strcmp ( V_15 , V_94 ) ) {
V_10 -> V_81 |= ( V_95 | V_96 |
V_97 ) ;
} else if ( ! strcmp ( V_15 , V_98 ) ) {
V_10 -> V_81 |= ( V_95 | V_96 ) ;
V_10 -> V_81 &= ~ V_97 ;
} else if ( ! strcmp ( V_15 , V_99 ) ||
! strcmp ( V_15 , V_100 ) ) {
V_10 -> V_81 |= ( V_101 | V_102 |
V_103 ) ;
} else if ( ! strcmp ( V_15 , V_104 ) ) {
V_10 -> V_81 |= ( V_101 | V_102 ) ;
V_10 -> V_81 &= ~ V_103 ;
} else if ( ! strcmp ( V_15 , V_105 ) ) {
V_10 -> V_28 |= V_106 ;
} else if ( ! strcmp ( V_15 , V_107 ) ) {
V_10 -> V_28 &= ~ V_106 ;
#ifdef F_8
} else if ( ! strcmp ( V_15 , V_108 ) ) {
V_10 -> V_28 |= V_109 ;
#endif
} else {
F_6 ( V_10 , L_4 , V_15 ) ;
return - V_8 ;
}
}
if ( ( V_10 -> V_28 & V_55 ) &&
! ( V_10 -> V_28 & V_29 ) ) {
F_6 ( V_10 , L_5 ) ;
return - V_8 ;
}
if ( ( V_10 -> V_28 & V_57 ) && ( V_16 || V_17 ) ) {
F_6 ( V_10 ,
L_6 ) ;
return - V_8 ;
}
#ifndef F_9
if ( F_10 ( V_10 ) ) {
F_6 ( V_10 , L_7 ) ;
return - V_8 ;
}
#endif
if ( ( V_16 && ! V_17 ) || ( ! V_16 && V_17 ) ) {
F_6 ( V_10 , L_8 ) ;
return - V_8 ;
}
if ( V_16 && ( V_17 % V_16 != 0 ) ) {
F_6 ( V_10 ,
L_9 ,
V_17 , V_16 ) ;
return - V_8 ;
}
V_38:
if ( V_16 && ! ( V_10 -> V_28 & V_57 ) ) {
V_10 -> V_110 = V_16 ;
V_10 -> V_111 = V_17 ;
}
if ( V_10 -> V_36 != - 1 &&
V_10 -> V_36 != 0 &&
( V_10 -> V_36 < V_112 ||
V_10 -> V_36 > V_113 ) ) {
F_6 ( V_10 , L_10 ,
V_10 -> V_36 , V_112 , V_113 ) ;
return - V_8 ;
}
if ( V_10 -> V_37 != - 1 &&
V_10 -> V_37 != 0 &&
( V_10 -> V_37 < V_114 ||
V_10 -> V_37 > V_115 ||
! F_11 ( V_10 -> V_37 ) ) ) {
F_6 ( V_10 ,
L_11 ,
V_10 -> V_37 ) ;
return - V_8 ;
}
if ( V_19 ) {
if ( V_19 > V_116 ||
V_19 < V_117 ) {
F_6 ( V_10 , L_12 ,
V_19 , V_117 ,
V_116 ) ;
return - V_8 ;
}
V_10 -> V_28 |= V_118 ;
V_10 -> V_119 = V_19 ;
V_10 -> V_120 = V_19 ;
}
return 0 ;
}
STATIC int
F_12 (
struct V_9 * V_10 ,
struct V_121 * V_122 )
{
static struct V_123 V_124 [] = {
{ V_70 , L_1 V_69 } ,
{ V_33 , L_1 V_53 } ,
{ V_57 , L_1 V_56 } ,
{ V_59 , L_1 V_58 } ,
{ V_66 , L_1 V_65 } ,
{ V_55 , L_1 V_54 } ,
{ V_75 , L_1 V_74 } ,
{ V_79 , L_1 V_78 } ,
{ V_50 , L_1 V_48 } ,
{ V_106 , L_1 V_105 } ,
{ V_63 , L_1 V_62 } ,
{ V_109 , L_1 V_108 } ,
{ 0 , NULL }
} ;
static struct V_123 V_125 [] = {
{ V_35 , L_1 V_72 } ,
{ V_34 , L_1 V_68 } ,
{ V_63 , L_1 V_64 } ,
{ 0 , NULL }
} ;
struct V_123 * V_126 ;
for ( V_126 = V_124 ; V_126 -> V_127 ; V_126 ++ ) {
if ( V_10 -> V_28 & V_126 -> V_127 )
F_13 ( V_122 , V_126 -> V_128 ) ;
}
for ( V_126 = V_125 ; V_126 -> V_127 ; V_126 ++ ) {
if ( ! ( V_10 -> V_28 & V_126 -> V_127 ) )
F_13 ( V_122 , V_126 -> V_128 ) ;
}
if ( V_10 -> V_28 & V_118 )
F_14 ( V_122 , L_1 V_46 L_13 ,
( int ) ( 1 << V_10 -> V_120 ) >> 10 ) ;
if ( V_10 -> V_36 > 0 )
F_14 ( V_122 , L_1 V_39 L_14 , V_10 -> V_36 ) ;
if ( V_10 -> V_37 > 0 )
F_14 ( V_122 , L_1 V_40 L_13 , V_10 -> V_37 >> 10 ) ;
if ( V_10 -> V_42 )
F_15 ( V_122 , V_41 , V_10 -> V_42 ) ;
if ( V_10 -> V_45 )
F_15 ( V_122 , V_44 , V_10 -> V_45 ) ;
if ( V_10 -> V_110 > 0 )
F_14 ( V_122 , L_1 V_60 L_14 ,
( int ) F_16 ( V_10 , V_10 -> V_110 ) ) ;
if ( V_10 -> V_111 > 0 )
F_14 ( V_122 , L_1 V_61 L_14 ,
( int ) F_16 ( V_10 , V_10 -> V_111 ) ) ;
if ( V_10 -> V_81 & ( V_88 | V_90 ) )
F_13 ( V_122 , L_1 V_87 ) ;
else if ( V_10 -> V_81 & V_88 )
F_13 ( V_122 , L_1 V_92 ) ;
if ( V_10 -> V_81 & V_95 ) {
if ( V_10 -> V_81 & V_97 )
F_13 ( V_122 , L_1 V_94 ) ;
else
F_13 ( V_122 , L_1 V_98 ) ;
}
if ( V_10 -> V_81 & V_101 ) {
if ( V_10 -> V_81 & V_103 )
F_13 ( V_122 , L_1 V_100 ) ;
else
F_13 ( V_122 , L_1 V_104 ) ;
}
if ( ! ( V_10 -> V_81 & V_82 ) )
F_13 ( V_122 , L_1 V_80 ) ;
return 0 ;
}
T_2
F_17 (
unsigned int V_129 )
{
unsigned int V_130 = 1 ;
unsigned int V_131 = V_132 - 1 ;
#if V_132 == 32
# if F_18 ( V_133 )
ASSERT ( sizeof( V_134 ) == 8 ) ;
V_130 = V_135 ;
V_131 = V_132 ;
# else
V_130 = V_135 >> ( V_136 - V_129 ) ;
# endif
#endif
return ( ( ( T_2 ) V_130 ) << V_131 ) - 1 ;
}
T_3
F_19 ( struct V_9 * V_10 , T_3 V_137 )
{
T_3 V_138 = 0 ;
T_3 V_139 = 0 ;
T_4 * V_140 = & V_10 -> V_141 ;
T_3 V_142 ;
T_5 V_143 ;
T_6 V_144 ;
T_7 * V_145 ;
if ( V_10 -> V_146 ) {
T_2 V_147 ;
V_147 = V_140 -> V_148 * V_140 -> V_149 ;
F_20 ( V_147 , 100 ) ;
V_147 += V_140 -> V_150 - 1 ;
F_20 ( V_147 , V_140 -> V_150 ) ;
V_142 = V_147 ;
} else {
V_142 = V_137 ;
}
V_143 = F_21 ( V_10 , V_140 -> V_150 - 1 , 0 ) ;
for ( V_138 = 0 ; V_138 < V_137 ; V_138 ++ ) {
V_144 = F_22 ( V_10 , V_138 , V_143 ) ;
if ( V_144 > V_151 ) {
V_145 = F_23 ( V_10 , V_138 ) ;
V_145 -> V_152 = 0 ;
V_145 -> V_153 = 0 ;
F_24 ( V_145 ) ;
continue;
}
V_145 = F_23 ( V_10 , V_138 ) ;
V_145 -> V_152 = 1 ;
V_139 ++ ;
if ( V_138 < V_142 )
V_145 -> V_153 = 1 ;
F_24 ( V_145 ) ;
}
V_10 -> V_28 |= ( V_154 |
V_63 ) ;
return V_139 ;
}
T_3
F_25 ( struct V_9 * V_10 , T_3 V_137 )
{
T_3 V_138 = 0 ;
for ( V_138 = 0 ; V_138 < V_137 ; V_138 ++ ) {
struct V_155 * V_145 ;
V_145 = F_23 ( V_10 , V_138 ) ;
V_145 -> V_152 = 1 ;
V_145 -> V_153 = 0 ;
F_24 ( V_145 ) ;
}
V_10 -> V_28 &= ~ ( V_154 |
V_63 ) ;
return V_138 ;
}
STATIC int
F_26 (
T_8 * V_10 ,
const char * V_156 ,
struct V_157 * * V_158 )
{
int error = 0 ;
* V_158 = F_27 ( V_156 , V_159 | V_160 | V_161 ,
V_10 ) ;
if ( F_28 ( * V_158 ) ) {
error = F_29 ( * V_158 ) ;
F_6 ( V_10 , L_15 , V_156 , error ) ;
}
return error ;
}
STATIC void
F_30 (
struct V_157 * V_162 )
{
if ( V_162 )
F_31 ( V_162 , V_159 | V_160 | V_161 ) ;
}
void
F_32 (
T_9 * V_163 )
{
F_33 ( V_163 -> V_164 , V_165 , NULL ) ;
}
STATIC void
F_34 (
struct V_9 * V_10 )
{
if ( V_10 -> V_166 && V_10 -> V_166 != V_10 -> V_167 ) {
struct V_157 * V_168 = V_10 -> V_166 -> V_164 ;
F_35 ( V_10 , V_10 -> V_166 ) ;
F_30 ( V_168 ) ;
}
if ( V_10 -> V_169 ) {
struct V_157 * V_170 = V_10 -> V_169 -> V_164 ;
F_35 ( V_10 , V_10 -> V_169 ) ;
F_30 ( V_170 ) ;
}
F_35 ( V_10 , V_10 -> V_167 ) ;
}
STATIC int
F_36 (
struct V_9 * V_10 )
{
struct V_157 * V_171 = V_10 -> V_14 -> V_172 ;
struct V_157 * V_168 = NULL , * V_170 = NULL ;
int error ;
if ( V_10 -> V_42 ) {
error = F_26 ( V_10 , V_10 -> V_42 , & V_168 ) ;
if ( error )
goto V_173;
}
if ( V_10 -> V_45 ) {
error = F_26 ( V_10 , V_10 -> V_45 , & V_170 ) ;
if ( error )
goto V_174;
if ( V_170 == V_171 || V_170 == V_168 ) {
F_6 ( V_10 ,
L_16 ) ;
error = - V_8 ;
goto V_175;
}
}
error = - V_24 ;
V_10 -> V_167 = F_37 ( V_10 , V_171 ) ;
if ( ! V_10 -> V_167 )
goto V_175;
if ( V_170 ) {
V_10 -> V_169 = F_37 ( V_10 , V_170 ) ;
if ( ! V_10 -> V_169 )
goto V_176;
}
if ( V_168 && V_168 != V_171 ) {
V_10 -> V_166 = F_37 ( V_10 , V_168 ) ;
if ( ! V_10 -> V_166 )
goto V_177;
} else {
V_10 -> V_166 = V_10 -> V_167 ;
}
return 0 ;
V_177:
if ( V_10 -> V_169 )
F_35 ( V_10 , V_10 -> V_169 ) ;
V_176:
F_35 ( V_10 , V_10 -> V_167 ) ;
V_175:
F_30 ( V_170 ) ;
V_174:
if ( V_168 && V_168 != V_171 )
F_30 ( V_168 ) ;
V_173:
return error ;
}
STATIC int
F_38 (
struct V_9 * V_10 )
{
int error ;
error = F_39 ( V_10 -> V_167 , V_10 -> V_141 . V_178 ) ;
if ( error )
return error ;
if ( V_10 -> V_166 && V_10 -> V_166 != V_10 -> V_167 ) {
unsigned int V_179 = V_180 ;
if ( F_40 ( & V_10 -> V_141 ) )
V_179 = V_10 -> V_141 . V_181 ;
error = F_39 ( V_10 -> V_166 ,
V_179 ) ;
if ( error )
return error ;
}
if ( V_10 -> V_169 ) {
error = F_39 ( V_10 -> V_169 ,
V_10 -> V_141 . V_178 ) ;
if ( error )
return error ;
}
return 0 ;
}
STATIC int
F_41 (
struct V_9 * V_10 )
{
V_10 -> V_182 = F_42 ( L_17 ,
V_183 | V_184 , 1 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_182 )
goto V_173;
V_10 -> V_185 = F_42 ( L_18 ,
V_183 | V_184 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_185 )
goto V_186;
V_10 -> V_187 = F_42 ( L_19 ,
V_183 | V_184 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_187 )
goto V_188;
V_10 -> V_189 = F_42 ( L_20 ,
V_183 | V_184 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_189 )
goto V_190;
V_10 -> V_191 = F_42 ( L_21 ,
V_184 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_191 )
goto V_192;
V_10 -> V_193 = F_42 ( L_22 ,
V_184 | V_194 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_193 )
goto V_195;
V_10 -> V_196 = F_42 ( L_23 ,
V_184 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_196 )
goto V_197;
return 0 ;
V_197:
F_43 ( V_10 -> V_193 ) ;
V_195:
F_43 ( V_10 -> V_191 ) ;
V_192:
F_43 ( V_10 -> V_189 ) ;
V_190:
F_43 ( V_10 -> V_187 ) ;
V_188:
F_43 ( V_10 -> V_185 ) ;
V_186:
F_43 ( V_10 -> V_182 ) ;
V_173:
return - V_24 ;
}
STATIC void
F_44 (
struct V_9 * V_10 )
{
F_43 ( V_10 -> V_196 ) ;
F_43 ( V_10 -> V_193 ) ;
F_43 ( V_10 -> V_191 ) ;
F_43 ( V_10 -> V_189 ) ;
F_43 ( V_10 -> V_185 ) ;
F_43 ( V_10 -> V_187 ) ;
F_43 ( V_10 -> V_182 ) ;
}
void
F_45 (
struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
if ( F_46 ( & V_13 -> V_198 ) ) {
F_47 ( V_13 ) ;
F_48 ( & V_13 -> V_198 ) ;
}
}
STATIC struct V_199 *
F_49 (
struct V_12 * V_13 )
{
F_50 () ;
return NULL ;
}
STATIC void
F_51 (
struct V_199 * V_199 )
{
struct V_200 * V_201 = F_52 ( V_199 ) ;
F_53 ( V_201 ) ;
F_54 ( V_202 ) ;
ASSERT ( F_55 ( V_201 -> V_203 ) || V_201 -> V_204 == 0 ) ;
F_56 ( ! F_57 ( V_201 , V_205 ) ) ;
F_56 ( ! F_57 ( V_201 , V_206 ) ) ;
F_58 ( V_201 ) ;
}
STATIC void
F_59 (
void * V_199 )
{
struct V_200 * V_201 = V_199 ;
memset ( V_201 , 0 , sizeof( struct V_200 ) ) ;
F_60 ( F_61 ( V_201 ) ) ;
F_62 ( & V_201 -> V_207 , 0 ) ;
F_63 ( & V_201 -> V_208 ) ;
F_64 ( & V_201 -> V_209 , V_210 | V_211 ,
L_24 , V_201 -> V_212 ) ;
F_64 ( & V_201 -> V_213 , V_210 | V_211 ,
L_24 , V_201 -> V_212 ) ;
}
STATIC void
F_65 (
struct V_199 * V_199 )
{
T_10 * V_201 = F_52 ( V_199 ) ;
ASSERT ( ! F_66 ( & V_201 -> V_214 . V_215 ) ) ;
F_67 ( V_201 ) ;
F_68 ( & V_199 -> V_216 ) ;
F_69 ( V_199 ) ;
F_54 ( V_217 ) ;
F_54 ( V_218 ) ;
F_70 ( V_201 ) ;
}
STATIC int
F_71 (
struct V_199 * V_199 )
{
struct V_200 * V_201 = F_52 ( V_199 ) ;
return F_72 ( V_199 ) || ( V_201 -> V_219 & V_220 ) ;
}
STATIC void
F_73 (
struct V_9 * V_10 )
{
F_74 ( V_10 -> V_20 ) ;
F_74 ( V_10 -> V_45 ) ;
F_74 ( V_10 -> V_42 ) ;
}
STATIC int
F_75 (
struct V_12 * V_13 ,
int V_221 )
{
struct V_9 * V_10 = F_76 ( V_13 ) ;
if ( ! V_221 )
return 0 ;
F_77 ( V_10 , V_222 ) ;
if ( V_223 ) {
F_78 ( & V_10 -> V_224 -> V_225 ) ;
}
return 0 ;
}
STATIC int
F_79 (
struct V_226 * V_226 ,
struct V_227 * V_228 )
{
struct V_9 * V_10 = F_76 ( V_226 -> V_229 ) ;
T_4 * V_140 = & V_10 -> V_141 ;
struct V_200 * V_201 = F_52 ( F_80 ( V_226 ) ) ;
T_2 V_230 , V_231 ;
T_2 V_147 ;
T_2 V_232 ;
T_2 V_233 ;
T_11 V_234 ;
T_12 V_235 ;
V_228 -> V_236 = V_237 ;
V_228 -> V_238 = V_22 - 1 ;
V_231 = F_81 ( V_10 -> V_167 -> V_239 ) ;
V_228 -> V_240 . V_241 [ 0 ] = ( V_242 ) V_231 ;
V_228 -> V_240 . V_241 [ 1 ] = ( V_242 ) ( V_231 >> 32 ) ;
V_147 = F_82 ( & V_10 -> V_243 ) ;
V_232 = F_82 ( & V_10 -> V_244 ) ;
V_233 = F_82 ( & V_10 -> V_245 ) ;
F_83 ( & V_10 -> V_246 ) ;
V_228 -> V_247 = V_140 -> V_248 ;
V_234 = V_140 -> V_249 ? V_140 -> V_250 : 0 ;
V_228 -> V_251 = V_140 -> V_148 - V_234 ;
F_84 ( & V_10 -> V_246 ) ;
V_228 -> V_252 = V_233 - F_85 ( V_10 ) ;
V_228 -> V_253 = V_228 -> V_252 ;
V_230 = V_228 -> V_252 << V_140 -> V_254 ;
V_228 -> V_255 = F_86 ( V_147 + V_230 , ( T_2 ) V_256 ) ;
if ( V_10 -> V_146 )
V_228 -> V_255 = F_87 ( F_88 ( V_228 -> V_255 ) ,
V_228 -> V_255 ,
V_10 -> V_146 ) ;
V_228 -> V_255 = F_89 ( F_88 ( V_228 -> V_255 ) ,
V_228 -> V_255 ,
V_140 -> V_257 ) ;
V_235 = V_228 -> V_255 - ( V_147 - V_232 ) ;
V_228 -> V_258 = F_89 ( T_12 , V_235 , 0 ) ;
if ( ( V_201 -> V_259 . V_260 & V_261 ) &&
( ( V_10 -> V_81 & ( V_95 | V_97 ) ) ) ==
( V_95 | V_97 ) )
F_90 ( V_201 , V_228 ) ;
return 0 ;
}
STATIC void
F_91 ( struct V_9 * V_10 )
{
T_2 V_262 = 0 ;
V_10 -> V_263 = V_10 -> V_264 ;
F_92 ( V_10 , & V_262 , NULL ) ;
}
STATIC void
F_93 ( struct V_9 * V_10 )
{
T_2 V_262 ;
if ( V_10 -> V_263 ) {
V_262 = V_10 -> V_263 ;
V_10 -> V_263 = 0 ;
} else
V_262 = F_94 ( V_10 ) ;
F_92 ( V_10 , & V_262 , NULL ) ;
}
static void
F_95 (
struct V_9 * V_10 )
{
int error = 0 ;
while ( F_96 ( & V_10 -> V_265 ) > 0 )
F_97 ( 100 ) ;
F_77 ( V_10 , V_222 ) ;
F_98 ( V_10 , 0 ) ;
F_98 ( V_10 , V_266 ) ;
error = F_99 ( V_10 ) ;
if ( error )
F_6 ( V_10 , L_25
L_26 ) ;
F_100 ( F_96 ( & V_10 -> V_265 ) != 0 ) ;
F_101 ( V_10 ) ;
}
STATIC int
F_102 (
struct V_12 * V_13 ,
int * V_267 ,
char * V_11 )
{
struct V_9 * V_10 = F_76 ( V_13 ) ;
T_4 * V_140 = & V_10 -> V_141 ;
T_13 args [ V_268 ] ;
char * V_269 ;
int error ;
F_103 ( V_13 ) ;
while ( ( V_269 = F_5 ( & V_11 , L_1 ) ) != NULL ) {
int V_270 ;
if ( ! * V_269 )
continue;
V_270 = F_104 ( V_269 , V_271 , args ) ;
switch ( V_270 ) {
case V_272 :
V_10 -> V_28 |= V_34 ;
break;
case V_273 :
V_10 -> V_28 &= ~ V_34 ;
break;
case V_274 :
V_10 -> V_275 = F_25 ( V_10 , V_140 -> V_276 ) ;
break;
case V_277 :
V_10 -> V_275 = F_19 ( V_10 , V_140 -> V_276 ) ;
break;
default:
#if 0
xfs_info(mp,
"mount option \"%s\" not supported for remount", p);
return -EINVAL;
#else
break;
#endif
}
}
if ( ( V_10 -> V_28 & V_29 ) && ! ( * V_267 & V_27 ) ) {
if ( V_10 -> V_28 & V_55 ) {
F_6 ( V_10 ,
L_27 ) ;
return - V_8 ;
}
V_10 -> V_28 &= ~ V_29 ;
if ( V_10 -> V_278 ) {
error = F_105 ( V_10 , false ) ;
if ( error ) {
F_6 ( V_10 , L_28 ) ;
return error ;
}
V_10 -> V_278 = false ;
}
F_93 ( V_10 ) ;
F_106 ( V_10 ) ;
}
if ( ! ( V_10 -> V_28 & V_29 ) && ( * V_267 & V_27 ) ) {
F_91 ( V_10 ) ;
F_95 ( V_10 ) ;
V_10 -> V_28 |= V_29 ;
}
return 0 ;
}
STATIC int
F_107 (
struct V_12 * V_13 )
{
struct V_9 * V_10 = F_76 ( V_13 ) ;
F_91 ( V_10 ) ;
F_95 ( V_10 ) ;
return F_105 ( V_10 , true ) ;
}
STATIC int
F_108 (
struct V_12 * V_13 )
{
struct V_9 * V_10 = F_76 ( V_13 ) ;
F_93 ( V_10 ) ;
F_106 ( V_10 ) ;
return 0 ;
}
STATIC int
F_109 (
struct V_121 * V_122 ,
struct V_226 * V_279 )
{
return F_12 ( F_76 ( V_279 -> V_229 ) , V_122 ) ;
}
STATIC int
F_110 (
struct V_9 * V_10 )
{
int V_280 = ( V_10 -> V_28 & V_29 ) ;
if ( F_111 ( & V_10 -> V_141 ) ) {
if ( V_10 -> V_37 <= 0 &&
V_10 -> V_141 . V_281 > V_282 ) {
V_10 -> V_37 = V_10 -> V_141 . V_281 ;
} else if ( V_10 -> V_37 > 0 &&
V_10 -> V_37 < V_10 -> V_141 . V_281 ) {
F_6 ( V_10 ,
L_29 ) ;
return - V_8 ;
}
} else {
if ( V_10 -> V_37 > V_282 ) {
F_6 ( V_10 ,
L_30 ) ;
return - V_8 ;
}
}
if ( F_112 ( & V_10 -> V_141 ) &&
( V_10 -> V_28 & V_77 ) ) {
F_6 ( V_10 ,
L_31 ,
V_76 , V_74 ) ;
return - V_8 ;
}
if ( F_113 ( & V_10 -> V_141 ) &&
! ( V_10 -> V_28 & V_77 ) )
V_10 -> V_28 |= V_75 ;
if ( ( V_10 -> V_141 . V_283 & V_284 ) && ! V_280 ) {
F_6 ( V_10 ,
L_32 ) ;
return - V_285 ;
}
if ( ( V_10 -> V_81 & ( V_101 | V_102 ) ) &&
( V_10 -> V_81 & ( V_95 | V_96 ) ) &&
! F_114 ( & V_10 -> V_141 ) ) {
F_6 ( V_10 ,
L_33 ) ;
return - V_8 ;
}
return 0 ;
}
static int
F_115 (
struct V_9 * V_10 )
{
int error ;
error = F_116 ( & V_10 -> V_243 , 0 , V_23 ) ;
if ( error )
return - V_24 ;
error = F_116 ( & V_10 -> V_244 , 0 , V_23 ) ;
if ( error )
goto V_286;
error = F_116 ( & V_10 -> V_245 , 0 , V_23 ) ;
if ( error )
goto V_287;
return 0 ;
V_287:
F_117 ( & V_10 -> V_244 ) ;
V_286:
F_117 ( & V_10 -> V_243 ) ;
return - V_24 ;
}
void
F_118 (
struct V_9 * V_10 )
{
F_119 ( & V_10 -> V_243 , V_10 -> V_141 . V_257 ) ;
F_119 ( & V_10 -> V_244 , V_10 -> V_141 . V_288 ) ;
F_119 ( & V_10 -> V_245 , V_10 -> V_141 . V_289 ) ;
}
static void
F_120 (
struct V_9 * V_10 )
{
F_117 ( & V_10 -> V_243 ) ;
F_117 ( & V_10 -> V_244 ) ;
F_117 ( & V_10 -> V_245 ) ;
}
STATIC int
F_121 (
struct V_12 * V_13 ,
void * V_290 ,
int V_291 )
{
struct V_199 * V_279 ;
struct V_9 * V_10 = NULL ;
int V_267 = 0 , error = - V_24 ;
V_10 = F_122 ( sizeof( struct V_9 ) , V_23 ) ;
if ( ! V_10 )
goto V_173;
F_63 ( & V_10 -> V_246 ) ;
F_123 ( & V_10 -> V_292 ) ;
F_62 ( & V_10 -> V_265 , 0 ) ;
F_124 ( & V_10 -> V_293 , V_294 ) ;
F_124 ( & V_10 -> V_295 , V_296 ) ;
V_10 -> V_297 . V_298 . V_299 = V_300 ;
V_10 -> V_14 = V_13 ;
V_13 -> V_301 = V_10 ;
error = F_3 ( V_10 , ( char * ) V_290 ) ;
if ( error )
goto V_302;
F_125 ( V_13 , V_180 ) ;
V_13 -> V_303 = V_304 ;
V_13 -> V_305 = & V_306 ;
#ifdef F_9
V_13 -> V_307 = & V_308 ;
V_13 -> V_309 = V_310 | V_311 | V_312 ;
#endif
V_13 -> V_313 = & V_314 ;
if ( V_291 )
V_267 |= V_315 ;
error = F_36 ( V_10 ) ;
if ( error )
goto V_302;
error = F_41 ( V_10 ) ;
if ( error )
goto V_316;
error = F_115 ( V_10 ) ;
if ( error )
goto V_317;
error = F_126 ( V_10 , V_267 ) ;
if ( error )
goto V_318;
error = F_110 ( V_10 ) ;
if ( error )
goto V_319;
error = F_38 ( V_10 ) ;
if ( error )
goto V_319;
error = F_127 ( V_10 ) ;
if ( error )
goto V_319;
V_13 -> V_320 = V_237 ;
V_13 -> V_321 = V_10 -> V_141 . V_248 ;
V_13 -> V_322 = F_7 ( V_13 -> V_321 ) - 1 ;
V_13 -> V_323 = F_17 ( V_13 -> V_322 ) ;
V_13 -> V_324 = V_325 ;
V_13 -> V_326 = 1 ;
F_128 ( V_13 ) ;
if ( F_129 ( & V_10 -> V_141 ) == V_327 )
V_13 -> V_26 |= V_328 ;
if ( V_10 -> V_28 & V_109 ) {
F_6 ( V_10 ,
L_34 ) ;
if ( V_13 -> V_321 != V_329 ) {
F_130 ( V_10 ,
L_35 ) ;
V_10 -> V_28 &= ~ V_109 ;
} else if ( ! V_13 -> V_172 -> V_330 -> V_331 -> V_332 ) {
F_130 ( V_10 ,
L_36 ) ;
V_10 -> V_28 &= ~ V_109 ;
}
}
if ( F_131 ( & V_10 -> V_141 ) )
F_130 ( V_10 ,
L_37 ) ;
error = F_132 ( V_10 ) ;
if ( error )
goto V_333;
V_279 = F_133 ( F_61 ( V_10 -> V_334 ) ) ;
if ( ! V_279 ) {
error = - V_335 ;
goto V_336;
}
V_13 -> V_337 = F_134 ( V_279 ) ;
if ( ! V_13 -> V_337 ) {
error = - V_24 ;
goto V_336;
}
return 0 ;
V_333:
F_135 ( V_10 ) ;
V_319:
F_136 ( V_10 ) ;
V_318:
F_120 ( V_10 ) ;
V_317:
F_44 ( V_10 ) ;
V_316:
F_34 ( V_10 ) ;
V_302:
F_73 ( V_10 ) ;
F_74 ( V_10 ) ;
V_173:
return error ;
V_336:
F_135 ( V_10 ) ;
F_137 ( V_10 ) ;
goto V_319;
}
STATIC void
F_138 (
struct V_12 * V_13 )
{
struct V_9 * V_10 = F_76 ( V_13 ) ;
F_139 ( V_10 , L_38 ) ;
F_135 ( V_10 ) ;
F_137 ( V_10 ) ;
F_136 ( V_10 ) ;
F_120 ( V_10 ) ;
F_44 ( V_10 ) ;
F_34 ( V_10 ) ;
F_73 ( V_10 ) ;
F_74 ( V_10 ) ;
}
STATIC struct V_226 *
F_140 (
struct V_338 * V_339 ,
int V_267 ,
const char * V_340 ,
void * V_290 )
{
return F_141 ( V_339 , V_267 , V_340 , V_290 , F_121 ) ;
}
static long
F_142 (
struct V_12 * V_13 ,
struct V_341 * V_342 )
{
return F_143 ( F_76 ( V_13 ) ) ;
}
static long
F_144 (
struct V_12 * V_13 ,
struct V_341 * V_342 )
{
return F_145 ( F_76 ( V_13 ) , V_342 -> V_343 ) ;
}
STATIC int T_14
F_146 ( void )
{
V_344 = F_147 ( sizeof( V_345 ) , L_39 ) ;
if ( ! V_344 )
goto V_173;
V_346 = F_148 ( 4 * V_347 ,
V_344 ) ;
if ( ! V_346 )
goto V_348;
V_349 = F_147 ( sizeof( V_350 ) ,
L_40 ) ;
if ( ! V_349 )
goto V_351;
V_352 = F_147 ( sizeof( V_353 ) ,
L_41 ) ;
if ( ! V_352 )
goto V_354;
V_355 = F_147 ( sizeof( V_356 ) ,
L_42 ) ;
if ( ! V_355 )
goto V_357;
V_358 = F_147 ( sizeof( V_359 ) ,
L_43 ) ;
if ( ! V_358 )
goto V_360;
V_361 = F_147 ( sizeof( V_362 ) , L_44 ) ;
if ( ! V_361 )
goto V_363;
V_364 = F_147 ( sizeof( V_365 ) , L_45 ) ;
if ( ! V_364 )
goto V_366;
V_367 =
F_147 ( sizeof( struct V_368 ) ,
L_46 ) ;
if ( ! V_367 )
goto V_369;
V_370 = F_147 ( sizeof( struct V_371 ) ,
L_47 ) ;
if ( ! V_370 )
goto V_372;
V_373 = F_147 ( ( sizeof( V_374 ) +
( ( V_375 - 1 ) *
sizeof( V_376 ) ) ) , L_48 ) ;
if ( ! V_373 )
goto V_377;
V_378 = F_147 ( ( sizeof( V_379 ) +
( ( V_380 - 1 ) *
sizeof( V_376 ) ) ) , L_49 ) ;
if ( ! V_378 )
goto V_381;
V_382 =
F_149 ( sizeof( T_10 ) , L_50 ,
V_383 | V_384 | V_385 ,
F_59 ) ;
if ( ! V_382 )
goto V_386;
V_387 =
F_149 ( sizeof( V_388 ) , L_51 ,
V_385 , NULL ) ;
if ( ! V_387 )
goto V_389;
V_390 = F_147 ( sizeof( struct V_391 ) ,
L_52 ) ;
if ( ! V_390 )
goto V_392;
return 0 ;
V_392:
F_150 ( V_387 ) ;
V_389:
F_150 ( V_382 ) ;
V_386:
F_150 ( V_378 ) ;
V_381:
F_150 ( V_373 ) ;
V_377:
F_150 ( V_370 ) ;
V_372:
F_150 ( V_367 ) ;
V_369:
F_150 ( V_364 ) ;
V_366:
F_150 ( V_361 ) ;
V_363:
F_150 ( V_358 ) ;
V_360:
F_150 ( V_355 ) ;
V_357:
F_150 ( V_352 ) ;
V_354:
F_150 ( V_349 ) ;
V_351:
F_151 ( V_346 ) ;
V_348:
F_150 ( V_344 ) ;
V_173:
return - V_24 ;
}
STATIC void
F_152 ( void )
{
F_153 () ;
F_150 ( V_390 ) ;
F_150 ( V_387 ) ;
F_150 ( V_382 ) ;
F_150 ( V_378 ) ;
F_150 ( V_373 ) ;
F_150 ( V_370 ) ;
F_150 ( V_367 ) ;
F_150 ( V_364 ) ;
F_150 ( V_361 ) ;
F_150 ( V_358 ) ;
F_150 ( V_355 ) ;
F_150 ( V_352 ) ;
F_150 ( V_349 ) ;
F_151 ( V_346 ) ;
F_150 ( V_344 ) ;
}
STATIC int T_14
F_154 ( void )
{
V_393 = F_42 ( L_53 ,
V_183 | V_184 , 0 ) ;
if ( ! V_393 )
return - V_24 ;
return 0 ;
}
STATIC void
F_155 ( void )
{
F_43 ( V_393 ) ;
}
STATIC int T_14
F_156 ( void )
{
int error ;
F_157 (KERN_INFO XFS_VERSION_STRING L_54
XFS_BUILD_OPTIONS L_55 ) ;
F_158 () ;
error = F_146 () ;
if ( error )
goto V_173;
error = F_154 () ;
if ( error )
goto V_394;
error = F_159 () ;
if ( error )
goto V_395;
error = F_160 () ;
if ( error )
goto V_396;
error = F_161 () ;
if ( error )
goto V_397;
error = F_162 () ;
if ( error )
goto V_398;
V_300 = F_163 ( L_56 , NULL , V_399 ) ;
if ( ! V_300 ) {
error = - V_24 ;
goto V_400; ;
}
#ifdef F_164
V_401 . V_298 . V_299 = V_300 ;
error = F_165 ( & V_401 , & V_402 , NULL , L_57 ) ;
if ( error )
goto V_403;
#endif
error = F_166 () ;
if ( error )
goto V_404;
error = F_167 ( & V_405 ) ;
if ( error )
goto V_406;
return 0 ;
V_406:
F_168 () ;
V_404:
#ifdef F_164
F_169 ( & V_401 ) ;
V_403:
#endif
F_170 ( V_300 ) ;
V_400:
F_171 () ;
V_398:
F_172 () ;
V_397:
F_173 () ;
V_396:
F_174 () ;
V_395:
F_155 () ;
V_394:
F_152 () ;
V_173:
return error ;
}
STATIC void T_15
F_175 ( void )
{
F_168 () ;
F_176 ( & V_405 ) ;
#ifdef F_164
F_169 ( & V_401 ) ;
#endif
F_170 ( V_300 ) ;
F_171 () ;
F_172 () ;
F_173 () ;
F_174 () ;
F_155 () ;
F_152 () ;
}
