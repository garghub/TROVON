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
} else if ( ! strcmp ( V_15 , V_46 ) ) {
if ( ! V_7 || ! * V_7 ) {
F_6 ( V_10 , L_2 ,
V_15 ) ;
return - V_8 ;
}
if ( F_2 ( V_7 , 10 , & V_18 ) )
return - V_8 ;
V_19 = F_7 ( V_18 ) - 1 ;
} else if ( ! strcmp ( V_15 , V_47 ) ) {
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
#ifndef F_8
if ( F_9 ( V_10 ) ) {
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
V_10 -> V_108 = V_16 ;
V_10 -> V_109 = V_17 ;
}
if ( V_10 -> V_36 != - 1 &&
V_10 -> V_36 != 0 &&
( V_10 -> V_36 < V_110 ||
V_10 -> V_36 > V_111 ) ) {
F_6 ( V_10 , L_10 ,
V_10 -> V_36 , V_110 , V_111 ) ;
return - V_8 ;
}
if ( V_10 -> V_37 != - 1 &&
V_10 -> V_37 != 0 &&
( V_10 -> V_37 < V_112 ||
V_10 -> V_37 > V_113 ||
! F_10 ( V_10 -> V_37 ) ) ) {
F_6 ( V_10 ,
L_11 ,
V_10 -> V_37 ) ;
return - V_8 ;
}
if ( V_19 ) {
if ( V_19 > V_114 ||
V_19 < V_115 ) {
F_6 ( V_10 , L_12 ,
V_19 , V_115 ,
V_114 ) ;
return - V_8 ;
}
V_10 -> V_28 |= V_116 ;
V_10 -> V_117 = V_19 ;
V_10 -> V_118 = V_19 ;
}
return 0 ;
}
STATIC int
F_11 (
struct V_9 * V_10 ,
struct V_119 * V_120 )
{
static struct V_121 V_122 [] = {
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
{ 0 , NULL }
} ;
static struct V_121 V_123 [] = {
{ V_35 , L_1 V_72 } ,
{ V_34 , L_1 V_68 } ,
{ V_63 , L_1 V_64 } ,
{ 0 , NULL }
} ;
struct V_121 * V_124 ;
for ( V_124 = V_122 ; V_124 -> V_125 ; V_124 ++ ) {
if ( V_10 -> V_28 & V_124 -> V_125 )
F_12 ( V_120 , V_124 -> V_126 ) ;
}
for ( V_124 = V_123 ; V_124 -> V_125 ; V_124 ++ ) {
if ( ! ( V_10 -> V_28 & V_124 -> V_125 ) )
F_12 ( V_120 , V_124 -> V_126 ) ;
}
if ( V_10 -> V_28 & V_116 )
F_13 ( V_120 , L_1 V_47 L_13 ,
( int ) ( 1 << V_10 -> V_118 ) >> 10 ) ;
if ( V_10 -> V_36 > 0 )
F_13 ( V_120 , L_1 V_39 L_14 , V_10 -> V_36 ) ;
if ( V_10 -> V_37 > 0 )
F_13 ( V_120 , L_1 V_40 L_13 , V_10 -> V_37 >> 10 ) ;
if ( V_10 -> V_42 )
F_13 ( V_120 , L_1 V_41 L_15 , V_10 -> V_42 ) ;
if ( V_10 -> V_45 )
F_13 ( V_120 , L_1 V_44 L_15 , V_10 -> V_45 ) ;
if ( V_10 -> V_108 > 0 )
F_13 ( V_120 , L_1 V_60 L_14 ,
( int ) F_14 ( V_10 , V_10 -> V_108 ) ) ;
if ( V_10 -> V_109 > 0 )
F_13 ( V_120 , L_1 V_61 L_14 ,
( int ) F_14 ( V_10 , V_10 -> V_109 ) ) ;
if ( V_10 -> V_81 & ( V_88 | V_90 ) )
F_12 ( V_120 , L_1 V_87 ) ;
else if ( V_10 -> V_81 & V_88 )
F_12 ( V_120 , L_1 V_92 ) ;
if ( V_10 -> V_81 & V_95 ) {
if ( V_10 -> V_81 & V_97 )
F_12 ( V_120 , L_1 V_94 ) ;
else
F_12 ( V_120 , L_1 V_98 ) ;
}
if ( V_10 -> V_81 & V_101 ) {
if ( V_10 -> V_81 & V_103 )
F_12 ( V_120 , L_1 V_100 ) ;
else
F_12 ( V_120 , L_1 V_104 ) ;
}
if ( ! ( V_10 -> V_81 & V_82 ) )
F_12 ( V_120 , L_1 V_80 ) ;
return 0 ;
}
T_2
F_15 (
unsigned int V_127 )
{
unsigned int V_128 = 1 ;
unsigned int V_129 = V_130 - 1 ;
#if V_130 == 32
# if F_16 ( V_131 )
ASSERT ( sizeof( V_132 ) == 8 ) ;
V_128 = V_133 ;
V_129 = V_130 ;
# else
V_128 = V_133 >> ( V_134 - V_127 ) ;
# endif
#endif
return ( ( ( T_2 ) V_128 ) << V_129 ) - 1 ;
}
T_3
F_17 ( struct V_9 * V_10 , T_3 V_135 )
{
T_3 V_136 = 0 ;
T_3 V_137 = 0 ;
T_4 * V_138 = & V_10 -> V_139 ;
T_3 V_140 ;
T_5 V_141 ;
T_6 V_142 ;
T_7 * V_143 ;
if ( V_10 -> V_144 ) {
T_2 V_145 ;
V_145 = V_138 -> V_146 * V_138 -> V_147 ;
F_18 ( V_145 , 100 ) ;
V_145 += V_138 -> V_148 - 1 ;
F_18 ( V_145 , V_138 -> V_148 ) ;
V_140 = V_145 ;
} else {
V_140 = V_135 ;
}
V_141 = F_19 ( V_10 , V_138 -> V_148 - 1 , 0 ) ;
for ( V_136 = 0 ; V_136 < V_135 ; V_136 ++ ) {
V_142 = F_20 ( V_10 , V_136 , V_141 ) ;
if ( V_142 > V_149 ) {
V_143 = F_21 ( V_10 , V_136 ) ;
V_143 -> V_150 = 0 ;
V_143 -> V_151 = 0 ;
F_22 ( V_143 ) ;
continue;
}
V_143 = F_21 ( V_10 , V_136 ) ;
V_143 -> V_150 = 1 ;
V_137 ++ ;
if ( V_136 < V_140 )
V_143 -> V_151 = 1 ;
F_22 ( V_143 ) ;
}
V_10 -> V_28 |= ( V_152 |
V_63 ) ;
return V_137 ;
}
T_3
F_23 ( struct V_9 * V_10 , T_3 V_135 )
{
T_3 V_136 = 0 ;
for ( V_136 = 0 ; V_136 < V_135 ; V_136 ++ ) {
struct V_153 * V_143 ;
V_143 = F_21 ( V_10 , V_136 ) ;
V_143 -> V_150 = 1 ;
V_143 -> V_151 = 0 ;
F_22 ( V_143 ) ;
}
V_10 -> V_28 &= ~ ( V_152 |
V_63 ) ;
return V_136 ;
}
STATIC int
F_24 (
T_8 * V_10 ,
const char * V_154 ,
struct V_155 * * V_156 )
{
int error = 0 ;
* V_156 = F_25 ( V_154 , V_157 | V_158 | V_159 ,
V_10 ) ;
if ( F_26 ( * V_156 ) ) {
error = F_27 ( * V_156 ) ;
F_6 ( V_10 , L_16 , V_154 , error ) ;
}
return error ;
}
STATIC void
F_28 (
struct V_155 * V_160 )
{
if ( V_160 )
F_29 ( V_160 , V_157 | V_158 | V_159 ) ;
}
void
F_30 (
T_9 * V_161 )
{
F_31 ( V_161 -> V_162 , V_163 , NULL ) ;
}
STATIC void
F_32 (
struct V_9 * V_10 )
{
if ( V_10 -> V_164 && V_10 -> V_164 != V_10 -> V_165 ) {
struct V_155 * V_166 = V_10 -> V_164 -> V_162 ;
F_33 ( V_10 , V_10 -> V_164 ) ;
F_28 ( V_166 ) ;
}
if ( V_10 -> V_167 ) {
struct V_155 * V_168 = V_10 -> V_167 -> V_162 ;
F_33 ( V_10 , V_10 -> V_167 ) ;
F_28 ( V_168 ) ;
}
F_33 ( V_10 , V_10 -> V_165 ) ;
}
STATIC int
F_34 (
struct V_9 * V_10 )
{
struct V_155 * V_169 = V_10 -> V_14 -> V_170 ;
struct V_155 * V_166 = NULL , * V_168 = NULL ;
int error ;
if ( V_10 -> V_42 ) {
error = F_24 ( V_10 , V_10 -> V_42 , & V_166 ) ;
if ( error )
goto V_171;
}
if ( V_10 -> V_45 ) {
error = F_24 ( V_10 , V_10 -> V_45 , & V_168 ) ;
if ( error )
goto V_172;
if ( V_168 == V_169 || V_168 == V_166 ) {
F_6 ( V_10 ,
L_17 ) ;
error = - V_8 ;
goto V_173;
}
}
error = - V_24 ;
V_10 -> V_165 = F_35 ( V_10 , V_169 ) ;
if ( ! V_10 -> V_165 )
goto V_173;
if ( V_168 ) {
V_10 -> V_167 = F_35 ( V_10 , V_168 ) ;
if ( ! V_10 -> V_167 )
goto V_174;
}
if ( V_166 && V_166 != V_169 ) {
V_10 -> V_164 = F_35 ( V_10 , V_166 ) ;
if ( ! V_10 -> V_164 )
goto V_175;
} else {
V_10 -> V_164 = V_10 -> V_165 ;
}
return 0 ;
V_175:
if ( V_10 -> V_167 )
F_33 ( V_10 , V_10 -> V_167 ) ;
V_174:
F_33 ( V_10 , V_10 -> V_165 ) ;
V_173:
F_28 ( V_168 ) ;
V_172:
if ( V_166 && V_166 != V_169 )
F_28 ( V_166 ) ;
V_171:
return error ;
}
STATIC int
F_36 (
struct V_9 * V_10 )
{
int error ;
error = F_37 ( V_10 -> V_165 , V_10 -> V_139 . V_176 ) ;
if ( error )
return error ;
if ( V_10 -> V_164 && V_10 -> V_164 != V_10 -> V_165 ) {
unsigned int V_177 = V_178 ;
if ( F_38 ( & V_10 -> V_139 ) )
V_177 = V_10 -> V_139 . V_179 ;
error = F_37 ( V_10 -> V_164 ,
V_177 ) ;
if ( error )
return error ;
}
if ( V_10 -> V_167 ) {
error = F_37 ( V_10 -> V_167 ,
V_10 -> V_139 . V_176 ) ;
if ( error )
return error ;
}
return 0 ;
}
STATIC int
F_39 (
struct V_9 * V_10 )
{
V_10 -> V_180 = F_40 ( L_18 ,
V_181 | V_182 , 1 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_180 )
goto V_171;
V_10 -> V_183 = F_40 ( L_19 ,
V_181 | V_182 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_183 )
goto V_184;
V_10 -> V_185 = F_40 ( L_20 ,
V_181 | V_182 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_185 )
goto V_186;
V_10 -> V_187 = F_40 ( L_21 ,
V_181 | V_182 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_187 )
goto V_188;
V_10 -> V_189 = F_40 ( L_22 ,
V_182 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_189 )
goto V_190;
V_10 -> V_191 = F_40 ( L_23 ,
V_182 | V_192 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_191 )
goto V_193;
V_10 -> V_194 = F_40 ( L_24 ,
V_182 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_194 )
goto V_195;
return 0 ;
V_195:
F_41 ( V_10 -> V_191 ) ;
V_193:
F_41 ( V_10 -> V_189 ) ;
V_190:
F_41 ( V_10 -> V_187 ) ;
V_188:
F_41 ( V_10 -> V_185 ) ;
V_186:
F_41 ( V_10 -> V_183 ) ;
V_184:
F_41 ( V_10 -> V_180 ) ;
V_171:
return - V_24 ;
}
STATIC void
F_42 (
struct V_9 * V_10 )
{
F_41 ( V_10 -> V_194 ) ;
F_41 ( V_10 -> V_191 ) ;
F_41 ( V_10 -> V_189 ) ;
F_41 ( V_10 -> V_187 ) ;
F_41 ( V_10 -> V_183 ) ;
F_41 ( V_10 -> V_185 ) ;
F_41 ( V_10 -> V_180 ) ;
}
void
F_43 (
struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
if ( F_44 ( & V_13 -> V_196 ) ) {
F_45 ( V_13 ) ;
F_46 ( & V_13 -> V_196 ) ;
}
}
STATIC struct V_197 *
F_47 (
struct V_12 * V_13 )
{
F_48 () ;
return NULL ;
}
STATIC void
F_49 (
struct V_197 * V_197 )
{
struct V_198 * V_199 = F_50 ( V_197 ) ;
F_51 ( V_199 ) ;
F_52 ( V_200 ) ;
ASSERT ( F_53 ( V_199 -> V_201 ) || V_199 -> V_202 == 0 ) ;
F_54 ( ! F_55 ( V_199 , V_203 ) ) ;
F_54 ( ! F_55 ( V_199 , V_204 ) ) ;
F_56 ( V_199 ) ;
}
STATIC void
F_57 (
void * V_197 )
{
struct V_198 * V_199 = V_197 ;
memset ( V_199 , 0 , sizeof( struct V_198 ) ) ;
F_58 ( F_59 ( V_199 ) ) ;
F_60 ( & V_199 -> V_205 , 0 ) ;
F_61 ( & V_199 -> V_206 ) ;
F_62 ( & V_199 -> V_207 , V_208 | V_209 ,
L_25 , V_199 -> V_210 ) ;
F_62 ( & V_199 -> V_211 , V_208 | V_209 ,
L_25 , V_199 -> V_210 ) ;
}
STATIC void
F_63 (
struct V_197 * V_197 )
{
T_10 * V_199 = F_50 ( V_197 ) ;
ASSERT ( ! F_64 ( & V_199 -> V_212 . V_213 ) ) ;
F_65 ( V_199 ) ;
F_66 ( & V_197 -> V_214 ) ;
F_67 ( V_197 ) ;
F_52 ( V_215 ) ;
F_52 ( V_216 ) ;
F_68 ( V_199 ) ;
}
STATIC int
F_69 (
struct V_197 * V_197 )
{
struct V_198 * V_199 = F_50 ( V_197 ) ;
return F_70 ( V_197 ) || ( V_199 -> V_217 & V_218 ) ;
}
STATIC void
F_71 (
struct V_9 * V_10 )
{
F_72 ( V_10 -> V_20 ) ;
F_72 ( V_10 -> V_45 ) ;
F_72 ( V_10 -> V_42 ) ;
}
STATIC int
F_73 (
struct V_12 * V_13 ,
int V_219 )
{
struct V_9 * V_10 = F_74 ( V_13 ) ;
if ( ! V_219 )
return 0 ;
F_75 ( V_10 , V_220 ) ;
if ( V_221 ) {
F_76 ( & V_10 -> V_222 -> V_223 ) ;
}
return 0 ;
}
STATIC int
F_77 (
struct V_224 * V_224 ,
struct V_225 * V_226 )
{
struct V_9 * V_10 = F_74 ( V_224 -> V_227 ) ;
T_4 * V_138 = & V_10 -> V_139 ;
struct V_198 * V_199 = F_50 ( F_78 ( V_224 ) ) ;
T_2 V_228 , V_229 ;
T_2 V_145 ;
T_2 V_230 ;
T_2 V_231 ;
T_11 V_232 ;
T_12 V_233 ;
V_226 -> V_234 = V_235 ;
V_226 -> V_236 = V_22 - 1 ;
V_229 = F_79 ( V_10 -> V_165 -> V_237 ) ;
V_226 -> V_238 . V_239 [ 0 ] = ( V_240 ) V_229 ;
V_226 -> V_238 . V_239 [ 1 ] = ( V_240 ) ( V_229 >> 32 ) ;
V_145 = F_80 ( & V_10 -> V_241 ) ;
V_230 = F_80 ( & V_10 -> V_242 ) ;
V_231 = F_80 ( & V_10 -> V_243 ) ;
F_81 ( & V_10 -> V_244 ) ;
V_226 -> V_245 = V_138 -> V_246 ;
V_232 = V_138 -> V_247 ? V_138 -> V_248 : 0 ;
V_226 -> V_249 = V_138 -> V_146 - V_232 ;
F_82 ( & V_10 -> V_244 ) ;
V_226 -> V_250 = V_231 - F_83 ( V_10 ) ;
V_226 -> V_251 = V_226 -> V_250 ;
V_228 = V_226 -> V_250 << V_138 -> V_252 ;
V_226 -> V_253 = F_84 ( V_145 + V_228 , ( T_2 ) V_254 ) ;
if ( V_10 -> V_144 )
V_226 -> V_253 = F_85 ( F_86 ( V_226 -> V_253 ) ,
V_226 -> V_253 ,
V_10 -> V_144 ) ;
V_226 -> V_253 = F_87 ( F_86 ( V_226 -> V_253 ) ,
V_226 -> V_253 ,
V_138 -> V_255 ) ;
V_233 = V_226 -> V_253 - ( V_145 - V_230 ) ;
V_226 -> V_256 = F_87 ( T_12 , V_233 , 0 ) ;
if ( ( V_199 -> V_257 . V_258 & V_259 ) &&
( ( V_10 -> V_81 & ( V_95 | V_97 ) ) ) ==
( V_95 | V_97 ) )
F_88 ( V_199 , V_226 ) ;
return 0 ;
}
STATIC void
F_89 ( struct V_9 * V_10 )
{
T_2 V_260 = 0 ;
V_10 -> V_261 = V_10 -> V_262 ;
F_90 ( V_10 , & V_260 , NULL ) ;
}
STATIC void
F_91 ( struct V_9 * V_10 )
{
T_2 V_260 ;
if ( V_10 -> V_261 ) {
V_260 = V_10 -> V_261 ;
V_10 -> V_261 = 0 ;
} else
V_260 = F_92 ( V_10 ) ;
F_90 ( V_10 , & V_260 , NULL ) ;
}
static void
F_93 (
struct V_9 * V_10 )
{
int error = 0 ;
while ( F_94 ( & V_10 -> V_263 ) > 0 )
F_95 ( 100 ) ;
F_75 ( V_10 , V_220 ) ;
F_96 ( V_10 , 0 ) ;
F_96 ( V_10 , V_264 ) ;
error = F_97 ( V_10 ) ;
if ( error )
F_6 ( V_10 , L_26
L_27 ) ;
F_98 ( F_94 ( & V_10 -> V_263 ) != 0 ) ;
F_99 ( V_10 ) ;
}
STATIC int
F_100 (
struct V_12 * V_13 ,
int * V_265 ,
char * V_11 )
{
struct V_9 * V_10 = F_74 ( V_13 ) ;
T_4 * V_138 = & V_10 -> V_139 ;
T_13 args [ V_266 ] ;
char * V_267 ;
int error ;
F_101 ( V_13 ) ;
while ( ( V_267 = F_5 ( & V_11 , L_1 ) ) != NULL ) {
int V_268 ;
if ( ! * V_267 )
continue;
V_268 = F_102 ( V_267 , V_269 , args ) ;
switch ( V_268 ) {
case V_270 :
V_10 -> V_28 |= V_34 ;
break;
case V_271 :
V_10 -> V_28 &= ~ V_34 ;
break;
case V_272 :
V_10 -> V_273 = F_23 ( V_10 , V_138 -> V_274 ) ;
break;
case V_275 :
V_10 -> V_273 = F_17 ( V_10 , V_138 -> V_274 ) ;
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
if ( ( V_10 -> V_28 & V_29 ) && ! ( * V_265 & V_27 ) ) {
if ( V_10 -> V_28 & V_55 ) {
F_6 ( V_10 ,
L_28 ) ;
return - V_8 ;
}
V_10 -> V_28 &= ~ V_29 ;
if ( V_10 -> V_276 ) {
error = F_103 ( V_10 , false ) ;
if ( error ) {
F_6 ( V_10 , L_29 ) ;
return error ;
}
V_10 -> V_276 = false ;
}
F_91 ( V_10 ) ;
F_104 ( V_10 ) ;
}
if ( ! ( V_10 -> V_28 & V_29 ) && ( * V_265 & V_27 ) ) {
F_89 ( V_10 ) ;
F_93 ( V_10 ) ;
V_10 -> V_28 |= V_29 ;
}
return 0 ;
}
STATIC int
F_105 (
struct V_12 * V_13 )
{
struct V_9 * V_10 = F_74 ( V_13 ) ;
F_89 ( V_10 ) ;
F_93 ( V_10 ) ;
return F_103 ( V_10 , true ) ;
}
STATIC int
F_106 (
struct V_12 * V_13 )
{
struct V_9 * V_10 = F_74 ( V_13 ) ;
F_91 ( V_10 ) ;
F_104 ( V_10 ) ;
return 0 ;
}
STATIC int
F_107 (
struct V_119 * V_120 ,
struct V_224 * V_277 )
{
return F_11 ( F_74 ( V_277 -> V_227 ) , V_120 ) ;
}
STATIC int
F_108 (
struct V_9 * V_10 )
{
int V_278 = ( V_10 -> V_28 & V_29 ) ;
if ( F_109 ( & V_10 -> V_139 ) ) {
if ( V_10 -> V_37 <= 0 &&
V_10 -> V_139 . V_279 > V_280 ) {
V_10 -> V_37 = V_10 -> V_139 . V_279 ;
} else if ( V_10 -> V_37 > 0 &&
V_10 -> V_37 < V_10 -> V_139 . V_279 ) {
F_6 ( V_10 ,
L_30 ) ;
return - V_8 ;
}
} else {
if ( V_10 -> V_37 > V_280 ) {
F_6 ( V_10 ,
L_31 ) ;
return - V_8 ;
}
}
if ( F_110 ( & V_10 -> V_139 ) &&
( V_10 -> V_28 & V_77 ) ) {
F_6 ( V_10 ,
L_32 ,
V_76 , V_74 ) ;
return - V_8 ;
}
if ( F_111 ( & V_10 -> V_139 ) &&
! ( V_10 -> V_28 & V_77 ) )
V_10 -> V_28 |= V_75 ;
if ( ( V_10 -> V_139 . V_281 & V_282 ) && ! V_278 ) {
F_6 ( V_10 ,
L_33 ) ;
return - V_283 ;
}
if ( ( V_10 -> V_81 & ( V_101 | V_102 ) ) &&
( V_10 -> V_81 & ( V_95 | V_96 ) ) &&
! F_112 ( & V_10 -> V_139 ) ) {
F_6 ( V_10 ,
L_34 ) ;
return - V_8 ;
}
return 0 ;
}
static int
F_113 (
struct V_9 * V_10 )
{
int error ;
error = F_114 ( & V_10 -> V_241 , 0 , V_23 ) ;
if ( error )
return - V_24 ;
error = F_114 ( & V_10 -> V_242 , 0 , V_23 ) ;
if ( error )
goto V_284;
error = F_114 ( & V_10 -> V_243 , 0 , V_23 ) ;
if ( error )
goto V_285;
return 0 ;
V_285:
F_115 ( & V_10 -> V_242 ) ;
V_284:
F_115 ( & V_10 -> V_241 ) ;
return - V_24 ;
}
void
F_116 (
struct V_9 * V_10 )
{
F_117 ( & V_10 -> V_241 , V_10 -> V_139 . V_255 ) ;
F_117 ( & V_10 -> V_242 , V_10 -> V_139 . V_286 ) ;
F_117 ( & V_10 -> V_243 , V_10 -> V_139 . V_287 ) ;
}
static void
F_118 (
struct V_9 * V_10 )
{
F_115 ( & V_10 -> V_241 ) ;
F_115 ( & V_10 -> V_242 ) ;
F_115 ( & V_10 -> V_243 ) ;
}
STATIC int
F_119 (
struct V_12 * V_13 ,
void * V_288 ,
int V_289 )
{
struct V_197 * V_277 ;
struct V_9 * V_10 = NULL ;
int V_265 = 0 , error = - V_24 ;
V_10 = F_120 ( sizeof( struct V_9 ) , V_23 ) ;
if ( ! V_10 )
goto V_171;
F_61 ( & V_10 -> V_244 ) ;
F_121 ( & V_10 -> V_290 ) ;
F_60 ( & V_10 -> V_263 , 0 ) ;
F_122 ( & V_10 -> V_291 , V_292 ) ;
F_122 ( & V_10 -> V_293 , V_294 ) ;
V_10 -> V_295 . V_296 . V_297 = V_298 ;
V_10 -> V_14 = V_13 ;
V_13 -> V_299 = V_10 ;
error = F_3 ( V_10 , ( char * ) V_288 ) ;
if ( error )
goto V_300;
F_123 ( V_13 , V_178 ) ;
V_13 -> V_301 = V_302 ;
V_13 -> V_303 = & V_304 ;
#ifdef F_8
V_13 -> V_305 = & V_306 ;
V_13 -> V_307 = V_308 | V_309 | V_310 ;
#endif
V_13 -> V_311 = & V_312 ;
if ( V_289 )
V_265 |= V_313 ;
error = F_34 ( V_10 ) ;
if ( error )
goto V_300;
error = F_39 ( V_10 ) ;
if ( error )
goto V_314;
error = F_113 ( V_10 ) ;
if ( error )
goto V_315;
error = F_124 ( V_10 , V_265 ) ;
if ( error )
goto V_316;
error = F_108 ( V_10 ) ;
if ( error )
goto V_317;
error = F_36 ( V_10 ) ;
if ( error )
goto V_317;
error = F_125 ( V_10 ) ;
if ( error )
goto V_317;
V_13 -> V_318 = V_235 ;
V_13 -> V_319 = V_10 -> V_139 . V_246 ;
V_13 -> V_320 = F_7 ( V_13 -> V_319 ) - 1 ;
V_13 -> V_321 = F_15 ( V_13 -> V_320 ) ;
V_13 -> V_322 = V_323 ;
V_13 -> V_324 = 1 ;
F_126 ( V_13 ) ;
if ( F_127 ( & V_10 -> V_139 ) == V_325 )
V_13 -> V_26 |= V_326 ;
error = F_128 ( V_10 ) ;
if ( error )
goto V_327;
V_277 = F_129 ( F_59 ( V_10 -> V_328 ) ) ;
if ( ! V_277 ) {
error = - V_329 ;
goto V_330;
}
V_13 -> V_331 = F_130 ( V_277 ) ;
if ( ! V_13 -> V_331 ) {
error = - V_24 ;
goto V_330;
}
return 0 ;
V_327:
F_131 ( V_10 ) ;
V_317:
F_132 ( V_10 ) ;
V_316:
F_118 ( V_10 ) ;
V_315:
F_42 ( V_10 ) ;
V_314:
F_32 ( V_10 ) ;
V_300:
F_71 ( V_10 ) ;
F_72 ( V_10 ) ;
V_171:
return error ;
V_330:
F_131 ( V_10 ) ;
F_133 ( V_10 ) ;
goto V_317;
}
STATIC void
F_134 (
struct V_12 * V_13 )
{
struct V_9 * V_10 = F_74 ( V_13 ) ;
F_135 ( V_10 , L_35 ) ;
F_131 ( V_10 ) ;
F_133 ( V_10 ) ;
F_132 ( V_10 ) ;
F_118 ( V_10 ) ;
F_42 ( V_10 ) ;
F_32 ( V_10 ) ;
F_71 ( V_10 ) ;
F_72 ( V_10 ) ;
}
STATIC struct V_224 *
F_136 (
struct V_332 * V_333 ,
int V_265 ,
const char * V_334 ,
void * V_288 )
{
return F_137 ( V_333 , V_265 , V_334 , V_288 , F_119 ) ;
}
static long
F_138 (
struct V_12 * V_13 ,
struct V_335 * V_336 )
{
return F_139 ( F_74 ( V_13 ) ) ;
}
static long
F_140 (
struct V_12 * V_13 ,
struct V_335 * V_336 )
{
return F_141 ( F_74 ( V_13 ) , V_336 -> V_337 ) ;
}
STATIC int T_14
F_142 ( void )
{
V_338 = F_143 ( sizeof( V_339 ) , L_36 ) ;
if ( ! V_338 )
goto V_171;
V_340 = F_144 ( 4 * V_341 ,
V_338 ) ;
if ( ! V_340 )
goto V_342;
V_343 = F_143 ( sizeof( V_344 ) ,
L_37 ) ;
if ( ! V_343 )
goto V_345;
V_346 = F_143 ( sizeof( V_347 ) ,
L_38 ) ;
if ( ! V_346 )
goto V_348;
V_349 = F_143 ( sizeof( V_350 ) ,
L_39 ) ;
if ( ! V_349 )
goto V_351;
V_352 = F_143 ( sizeof( V_353 ) ,
L_40 ) ;
if ( ! V_352 )
goto V_354;
V_355 = F_143 ( sizeof( V_356 ) , L_41 ) ;
if ( ! V_355 )
goto V_357;
V_358 = F_143 ( sizeof( V_359 ) , L_42 ) ;
if ( ! V_358 )
goto V_360;
V_361 =
F_143 ( sizeof( struct V_362 ) ,
L_43 ) ;
if ( ! V_361 )
goto V_363;
V_364 = F_143 ( sizeof( struct V_365 ) ,
L_44 ) ;
if ( ! V_364 )
goto V_366;
V_367 = F_143 ( ( sizeof( V_368 ) +
( ( V_369 - 1 ) *
sizeof( V_370 ) ) ) , L_45 ) ;
if ( ! V_367 )
goto V_371;
V_372 = F_143 ( ( sizeof( V_373 ) +
( ( V_374 - 1 ) *
sizeof( V_370 ) ) ) , L_46 ) ;
if ( ! V_372 )
goto V_375;
V_376 =
F_145 ( sizeof( T_10 ) , L_47 ,
V_377 | V_378 | V_379 ,
F_57 ) ;
if ( ! V_376 )
goto V_380;
V_381 =
F_145 ( sizeof( V_382 ) , L_48 ,
V_379 , NULL ) ;
if ( ! V_381 )
goto V_383;
V_384 = F_143 ( sizeof( struct V_385 ) ,
L_49 ) ;
if ( ! V_384 )
goto V_386;
return 0 ;
V_386:
F_146 ( V_381 ) ;
V_383:
F_146 ( V_376 ) ;
V_380:
F_146 ( V_372 ) ;
V_375:
F_146 ( V_367 ) ;
V_371:
F_146 ( V_364 ) ;
V_366:
F_146 ( V_361 ) ;
V_363:
F_146 ( V_358 ) ;
V_360:
F_146 ( V_355 ) ;
V_357:
F_146 ( V_352 ) ;
V_354:
F_146 ( V_349 ) ;
V_351:
F_146 ( V_346 ) ;
V_348:
F_146 ( V_343 ) ;
V_345:
F_147 ( V_340 ) ;
V_342:
F_146 ( V_338 ) ;
V_171:
return - V_24 ;
}
STATIC void
F_148 ( void )
{
F_149 () ;
F_146 ( V_384 ) ;
F_146 ( V_381 ) ;
F_146 ( V_376 ) ;
F_146 ( V_372 ) ;
F_146 ( V_367 ) ;
F_146 ( V_364 ) ;
F_146 ( V_361 ) ;
F_146 ( V_358 ) ;
F_146 ( V_355 ) ;
F_146 ( V_352 ) ;
F_146 ( V_349 ) ;
F_146 ( V_346 ) ;
F_146 ( V_343 ) ;
F_147 ( V_340 ) ;
F_146 ( V_338 ) ;
}
STATIC int T_14
F_150 ( void )
{
V_387 = F_40 ( L_50 ,
V_181 | V_182 , 0 ) ;
if ( ! V_387 )
return - V_24 ;
return 0 ;
}
STATIC void
F_151 ( void )
{
F_41 ( V_387 ) ;
}
STATIC int T_14
F_152 ( void )
{
int error ;
F_153 (KERN_INFO XFS_VERSION_STRING L_51
XFS_BUILD_OPTIONS L_52 ) ;
F_154 () ;
error = F_142 () ;
if ( error )
goto V_171;
error = F_150 () ;
if ( error )
goto V_388;
error = F_155 () ;
if ( error )
goto V_389;
error = F_156 () ;
if ( error )
goto V_390;
error = F_157 () ;
if ( error )
goto V_391;
error = F_158 () ;
if ( error )
goto V_392;
V_298 = F_159 ( L_53 , NULL , V_393 ) ;
if ( ! V_298 ) {
error = - V_24 ;
goto V_394; ;
}
#ifdef F_160
V_395 . V_296 . V_297 = V_298 ;
error = F_161 ( & V_395 , & V_396 , NULL , L_54 ) ;
if ( error )
goto V_397;
#endif
error = F_162 () ;
if ( error )
goto V_398;
error = F_163 ( & V_399 ) ;
if ( error )
goto V_400;
return 0 ;
V_400:
F_164 () ;
V_398:
#ifdef F_160
F_165 ( & V_395 ) ;
V_397:
#endif
F_166 ( V_298 ) ;
V_394:
F_167 () ;
V_392:
F_168 () ;
V_391:
F_169 () ;
V_390:
F_170 () ;
V_389:
F_151 () ;
V_388:
F_148 () ;
V_171:
return error ;
}
STATIC void T_15
F_171 ( void )
{
F_164 () ;
F_172 ( & V_399 ) ;
#ifdef F_160
F_165 ( & V_395 ) ;
#endif
F_166 ( V_298 ) ;
F_167 () ;
F_168 () ;
F_169 () ;
F_170 () ;
F_151 () ;
F_148 () ;
}
