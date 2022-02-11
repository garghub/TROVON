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
F_6 ( V_10 ,
L_4 ) ;
} else if ( ! strcmp ( V_15 , V_106 ) ) {
F_6 ( V_10 ,
L_5 ) ;
} else if ( ! strcmp ( V_15 , V_107 ) ) {
V_10 -> V_28 |= V_108 ;
} else if ( ! strcmp ( V_15 , V_109 ) ) {
V_10 -> V_28 &= ~ V_108 ;
} else if ( ! strcmp ( V_15 , L_6 ) ) {
F_6 ( V_10 ,
L_7 ) ;
} else if ( ! strcmp ( V_15 , L_8 ) ) {
F_6 ( V_10 ,
L_9 ) ;
} else if ( ! strcmp ( V_15 , L_10 ) ) {
F_6 ( V_10 ,
L_11 ) ;
} else if ( ! strcmp ( V_15 , L_12 ) ) {
F_6 ( V_10 ,
L_13 ) ;
} else {
F_6 ( V_10 , L_14 , V_15 ) ;
return - V_8 ;
}
}
if ( ( V_10 -> V_28 & V_55 ) &&
! ( V_10 -> V_28 & V_29 ) ) {
F_6 ( V_10 , L_15 ) ;
return - V_8 ;
}
if ( ( V_10 -> V_28 & V_57 ) && ( V_16 || V_17 ) ) {
F_6 ( V_10 ,
L_16 ) ;
return - V_8 ;
}
#ifndef F_8
if ( F_9 ( V_10 ) ) {
F_6 ( V_10 , L_17 ) ;
return - V_8 ;
}
#endif
if ( ( V_16 && ! V_17 ) || ( ! V_16 && V_17 ) ) {
F_6 ( V_10 , L_18 ) ;
return - V_8 ;
}
if ( V_16 && ( V_17 % V_16 != 0 ) ) {
F_6 ( V_10 ,
L_19 ,
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
F_6 ( V_10 , L_20 ,
V_10 -> V_36 , V_112 , V_113 ) ;
return - V_8 ;
}
if ( V_10 -> V_37 != - 1 &&
V_10 -> V_37 != 0 &&
( V_10 -> V_37 < V_114 ||
V_10 -> V_37 > V_115 ||
! F_10 ( V_10 -> V_37 ) ) ) {
F_6 ( V_10 ,
L_21 ,
V_10 -> V_37 ) ;
return - V_8 ;
}
if ( V_19 ) {
if ( V_19 > V_116 ||
V_19 < V_117 ) {
F_6 ( V_10 , L_22 ,
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
F_11 (
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
{ V_108 , L_1 V_107 } ,
{ V_63 , L_1 V_62 } ,
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
F_12 ( V_122 , V_126 -> V_128 ) ;
}
for ( V_126 = V_125 ; V_126 -> V_127 ; V_126 ++ ) {
if ( ! ( V_10 -> V_28 & V_126 -> V_127 ) )
F_12 ( V_122 , V_126 -> V_128 ) ;
}
if ( V_10 -> V_28 & V_118 )
F_13 ( V_122 , L_1 V_47 L_23 ,
( int ) ( 1 << V_10 -> V_120 ) >> 10 ) ;
if ( V_10 -> V_36 > 0 )
F_13 ( V_122 , L_1 V_39 L_24 , V_10 -> V_36 ) ;
if ( V_10 -> V_37 > 0 )
F_13 ( V_122 , L_1 V_40 L_23 , V_10 -> V_37 >> 10 ) ;
if ( V_10 -> V_42 )
F_13 ( V_122 , L_1 V_41 L_25 , V_10 -> V_42 ) ;
if ( V_10 -> V_45 )
F_13 ( V_122 , L_1 V_44 L_25 , V_10 -> V_45 ) ;
if ( V_10 -> V_110 > 0 )
F_13 ( V_122 , L_1 V_60 L_24 ,
( int ) F_14 ( V_10 , V_10 -> V_110 ) ) ;
if ( V_10 -> V_111 > 0 )
F_13 ( V_122 , L_1 V_61 L_24 ,
( int ) F_14 ( V_10 , V_10 -> V_111 ) ) ;
if ( V_10 -> V_81 & ( V_88 | V_90 ) )
F_12 ( V_122 , L_1 V_87 ) ;
else if ( V_10 -> V_81 & V_88 )
F_12 ( V_122 , L_1 V_92 ) ;
if ( V_10 -> V_81 & V_95 ) {
if ( V_10 -> V_81 & V_97 )
F_12 ( V_122 , L_1 V_94 ) ;
else
F_12 ( V_122 , L_1 V_98 ) ;
}
if ( V_10 -> V_81 & V_101 ) {
if ( V_10 -> V_81 & V_103 )
F_12 ( V_122 , L_1 V_100 ) ;
else
F_12 ( V_122 , L_1 V_104 ) ;
}
if ( ! ( V_10 -> V_81 & V_82 ) )
F_12 ( V_122 , L_1 V_80 ) ;
return 0 ;
}
T_2
F_15 (
unsigned int V_129 )
{
unsigned int V_130 = 1 ;
unsigned int V_131 = V_132 - 1 ;
#if V_132 == 32
# if F_16 ( V_133 )
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
F_17 ( struct V_9 * V_10 , T_3 V_137 )
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
F_18 ( V_147 , 100 ) ;
V_147 += V_140 -> V_150 - 1 ;
F_18 ( V_147 , V_140 -> V_150 ) ;
V_142 = V_147 ;
} else {
V_142 = V_137 ;
}
V_143 = F_19 ( V_10 , V_140 -> V_150 - 1 , 0 ) ;
for ( V_138 = 0 ; V_138 < V_137 ; V_138 ++ ) {
V_144 = F_20 ( V_10 , V_138 , V_143 ) ;
if ( V_144 > V_151 ) {
V_145 = F_21 ( V_10 , V_138 ) ;
V_145 -> V_152 = 0 ;
V_145 -> V_153 = 0 ;
F_22 ( V_145 ) ;
continue;
}
V_145 = F_21 ( V_10 , V_138 ) ;
V_145 -> V_152 = 1 ;
V_139 ++ ;
if ( V_138 < V_142 )
V_145 -> V_153 = 1 ;
F_22 ( V_145 ) ;
}
V_10 -> V_28 |= ( V_154 |
V_63 ) ;
return V_139 ;
}
T_3
F_23 ( struct V_9 * V_10 , T_3 V_137 )
{
T_3 V_138 = 0 ;
for ( V_138 = 0 ; V_138 < V_137 ; V_138 ++ ) {
struct V_155 * V_145 ;
V_145 = F_21 ( V_10 , V_138 ) ;
V_145 -> V_152 = 1 ;
V_145 -> V_153 = 0 ;
F_22 ( V_145 ) ;
}
V_10 -> V_28 &= ~ ( V_154 |
V_63 ) ;
return V_138 ;
}
STATIC int
F_24 (
T_8 * V_10 ,
const char * V_156 ,
struct V_157 * * V_158 )
{
int error = 0 ;
* V_158 = F_25 ( V_156 , V_159 | V_160 | V_161 ,
V_10 ) ;
if ( F_26 ( * V_158 ) ) {
error = F_27 ( * V_158 ) ;
F_6 ( V_10 , L_26 , V_156 , error ) ;
}
return error ;
}
STATIC void
F_28 (
struct V_157 * V_162 )
{
if ( V_162 )
F_29 ( V_162 , V_159 | V_160 | V_161 ) ;
}
void
F_30 (
T_9 * V_163 )
{
F_31 ( V_163 -> V_164 , V_165 , NULL ) ;
}
STATIC void
F_32 (
struct V_9 * V_10 )
{
if ( V_10 -> V_166 && V_10 -> V_166 != V_10 -> V_167 ) {
struct V_157 * V_168 = V_10 -> V_166 -> V_164 ;
F_33 ( V_10 , V_10 -> V_166 ) ;
F_28 ( V_168 ) ;
}
if ( V_10 -> V_169 ) {
struct V_157 * V_170 = V_10 -> V_169 -> V_164 ;
F_33 ( V_10 , V_10 -> V_169 ) ;
F_28 ( V_170 ) ;
}
F_33 ( V_10 , V_10 -> V_167 ) ;
}
STATIC int
F_34 (
struct V_9 * V_10 )
{
struct V_157 * V_171 = V_10 -> V_14 -> V_172 ;
struct V_157 * V_168 = NULL , * V_170 = NULL ;
int error ;
if ( V_10 -> V_42 ) {
error = F_24 ( V_10 , V_10 -> V_42 , & V_168 ) ;
if ( error )
goto V_173;
}
if ( V_10 -> V_45 ) {
error = F_24 ( V_10 , V_10 -> V_45 , & V_170 ) ;
if ( error )
goto V_174;
if ( V_170 == V_171 || V_170 == V_168 ) {
F_6 ( V_10 ,
L_27 ) ;
error = - V_8 ;
goto V_175;
}
}
error = - V_24 ;
V_10 -> V_167 = F_35 ( V_10 , V_171 ) ;
if ( ! V_10 -> V_167 )
goto V_175;
if ( V_170 ) {
V_10 -> V_169 = F_35 ( V_10 , V_170 ) ;
if ( ! V_10 -> V_169 )
goto V_176;
}
if ( V_168 && V_168 != V_171 ) {
V_10 -> V_166 = F_35 ( V_10 , V_168 ) ;
if ( ! V_10 -> V_166 )
goto V_177;
} else {
V_10 -> V_166 = V_10 -> V_167 ;
}
return 0 ;
V_177:
if ( V_10 -> V_169 )
F_33 ( V_10 , V_10 -> V_169 ) ;
V_176:
F_33 ( V_10 , V_10 -> V_167 ) ;
V_175:
F_28 ( V_170 ) ;
V_174:
if ( V_168 && V_168 != V_171 )
F_28 ( V_168 ) ;
V_173:
return error ;
}
STATIC int
F_36 (
struct V_9 * V_10 )
{
int error ;
error = F_37 ( V_10 -> V_167 , V_10 -> V_141 . V_178 ) ;
if ( error )
return error ;
if ( V_10 -> V_166 && V_10 -> V_166 != V_10 -> V_167 ) {
unsigned int V_179 = V_180 ;
if ( F_38 ( & V_10 -> V_141 ) )
V_179 = V_10 -> V_141 . V_181 ;
error = F_37 ( V_10 -> V_166 ,
V_179 ) ;
if ( error )
return error ;
}
if ( V_10 -> V_169 ) {
error = F_37 ( V_10 -> V_169 ,
V_10 -> V_141 . V_178 ) ;
if ( error )
return error ;
}
return 0 ;
}
STATIC int
F_39 (
struct V_9 * V_10 )
{
V_10 -> V_182 = F_40 ( L_28 ,
V_183 | V_184 , 1 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_182 )
goto V_173;
V_10 -> V_185 = F_40 ( L_29 ,
V_183 | V_184 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_185 )
goto V_186;
V_10 -> V_187 = F_40 ( L_30 ,
V_183 | V_184 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_187 )
goto V_188;
V_10 -> V_189 = F_40 ( L_31 ,
V_183 | V_184 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_189 )
goto V_190;
V_10 -> V_191 = F_40 ( L_32 ,
V_184 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_191 )
goto V_192;
V_10 -> V_193 = F_40 ( L_33 ,
V_184 | V_194 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_193 )
goto V_195;
V_10 -> V_196 = F_40 ( L_34 ,
V_184 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_196 )
goto V_197;
return 0 ;
V_197:
F_41 ( V_10 -> V_193 ) ;
V_195:
F_41 ( V_10 -> V_191 ) ;
V_192:
F_41 ( V_10 -> V_189 ) ;
V_190:
F_41 ( V_10 -> V_187 ) ;
V_188:
F_41 ( V_10 -> V_185 ) ;
V_186:
F_41 ( V_10 -> V_182 ) ;
V_173:
return - V_24 ;
}
STATIC void
F_42 (
struct V_9 * V_10 )
{
F_41 ( V_10 -> V_196 ) ;
F_41 ( V_10 -> V_193 ) ;
F_41 ( V_10 -> V_191 ) ;
F_41 ( V_10 -> V_189 ) ;
F_41 ( V_10 -> V_185 ) ;
F_41 ( V_10 -> V_187 ) ;
F_41 ( V_10 -> V_182 ) ;
}
void
F_43 (
struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
if ( F_44 ( & V_13 -> V_198 ) ) {
F_45 ( V_13 ) ;
F_46 ( & V_13 -> V_198 ) ;
}
}
STATIC struct V_199 *
F_47 (
struct V_12 * V_13 )
{
F_48 () ;
return NULL ;
}
STATIC void
F_49 (
struct V_199 * V_199 )
{
struct V_200 * V_201 = F_50 ( V_199 ) ;
F_51 ( V_201 ) ;
F_52 ( V_202 ) ;
ASSERT ( F_53 ( V_201 -> V_203 ) || V_201 -> V_204 == 0 ) ;
F_54 ( ! F_55 ( V_201 , V_205 ) ) ;
F_54 ( ! F_55 ( V_201 , V_206 ) ) ;
F_56 ( V_201 ) ;
}
STATIC void
F_57 (
void * V_199 )
{
struct V_200 * V_201 = V_199 ;
memset ( V_201 , 0 , sizeof( struct V_200 ) ) ;
F_58 ( F_59 ( V_201 ) ) ;
F_60 ( & V_201 -> V_207 , 0 ) ;
F_61 ( & V_201 -> V_208 ) ;
F_62 ( & V_201 -> V_209 , V_210 | V_211 ,
L_35 , V_201 -> V_212 ) ;
}
STATIC void
F_63 (
struct V_199 * V_199 )
{
T_10 * V_201 = F_50 ( V_199 ) ;
ASSERT ( ! F_64 ( & V_201 -> V_213 . V_214 ) ) ;
F_65 ( V_201 ) ;
F_66 ( & V_199 -> V_215 ) ;
F_67 ( V_199 ) ;
F_52 ( V_216 ) ;
F_52 ( V_217 ) ;
F_68 ( V_201 ) ;
}
STATIC int
F_69 (
struct V_199 * V_199 )
{
struct V_200 * V_201 = F_50 ( V_199 ) ;
return F_70 ( V_199 ) || ( V_201 -> V_218 & V_219 ) ;
}
STATIC void
F_71 (
struct V_9 * V_10 )
{
F_72 ( V_10 -> V_20 ) ;
F_72 ( V_10 -> V_45 ) ;
F_72 ( V_10 -> V_42 ) ;
}
STATIC void
F_73 (
struct V_12 * V_13 )
{
struct V_9 * V_10 = F_74 ( V_13 ) ;
F_75 ( V_10 ) ;
F_76 ( V_10 ) ;
F_77 ( V_10 ) ;
F_78 ( V_10 ) ;
F_42 ( V_10 ) ;
F_32 ( V_10 ) ;
F_71 ( V_10 ) ;
F_72 ( V_10 ) ;
}
STATIC int
F_79 (
struct V_12 * V_13 ,
int V_220 )
{
struct V_9 * V_10 = F_74 ( V_13 ) ;
if ( ! V_220 )
return 0 ;
F_80 ( V_10 , V_221 ) ;
if ( V_222 ) {
F_81 ( & V_10 -> V_223 -> V_224 ) ;
}
return 0 ;
}
STATIC int
F_82 (
struct V_225 * V_225 ,
struct V_226 * V_227 )
{
struct V_9 * V_10 = F_74 ( V_225 -> V_228 ) ;
T_4 * V_140 = & V_10 -> V_141 ;
struct V_200 * V_201 = F_50 ( V_225 -> V_229 ) ;
T_2 V_230 , V_231 ;
T_11 V_232 ;
T_12 V_233 ;
V_227 -> V_234 = V_235 ;
V_227 -> V_236 = V_22 - 1 ;
V_231 = F_83 ( V_10 -> V_167 -> V_237 ) ;
V_227 -> V_238 . V_239 [ 0 ] = ( V_240 ) V_231 ;
V_227 -> V_238 . V_239 [ 1 ] = ( V_240 ) ( V_231 >> 32 ) ;
F_84 ( V_10 , V_241 ) ;
F_85 ( & V_10 -> V_242 ) ;
V_227 -> V_243 = V_140 -> V_244 ;
V_232 = V_140 -> V_245 ? V_140 -> V_246 : 0 ;
V_227 -> V_247 = V_140 -> V_148 - V_232 ;
V_227 -> V_248 = V_227 -> V_249 =
V_140 -> V_250 - F_86 ( V_10 ) ;
V_230 = V_227 -> V_248 << V_140 -> V_251 ;
V_227 -> V_252 =
F_87 ( V_140 -> V_253 + V_230 , ( T_2 ) V_254 ) ;
if ( V_10 -> V_146 )
V_227 -> V_252 = F_88 ( F_89 ( V_227 -> V_252 ) ,
V_227 -> V_252 ,
V_10 -> V_146 ) ;
V_227 -> V_252 = F_90 ( F_89 ( V_227 -> V_252 ) ,
V_227 -> V_252 ,
V_140 -> V_253 ) ;
V_233 = V_227 -> V_252 - ( V_140 -> V_253 - V_140 -> V_255 ) ;
V_227 -> V_256 = F_90 ( T_12 , V_233 , 0 ) ;
F_91 ( & V_10 -> V_242 ) ;
if ( ( V_201 -> V_257 . V_258 & V_259 ) &&
( ( V_10 -> V_81 & ( V_95 | V_97 ) ) ) ==
( V_95 | V_97 ) )
F_92 ( V_201 , V_227 ) ;
return 0 ;
}
STATIC void
F_93 ( struct V_9 * V_10 )
{
T_2 V_260 = 0 ;
V_10 -> V_261 = V_10 -> V_262 ;
F_94 ( V_10 , & V_260 , NULL ) ;
}
STATIC void
F_95 ( struct V_9 * V_10 )
{
T_2 V_260 ;
if ( V_10 -> V_261 ) {
V_260 = V_10 -> V_261 ;
V_10 -> V_261 = 0 ;
} else
V_260 = F_96 ( V_10 ) ;
F_94 ( V_10 , & V_260 , NULL ) ;
}
static void
F_97 (
struct V_9 * V_10 )
{
int error = 0 ;
while ( F_98 ( & V_10 -> V_263 ) > 0 )
F_99 ( 100 ) ;
F_80 ( V_10 , V_221 ) ;
F_100 ( V_10 , 0 ) ;
F_100 ( V_10 , V_264 ) ;
error = F_101 ( V_10 ) ;
if ( error )
F_6 ( V_10 , L_36
L_37 ) ;
F_102 ( F_98 ( & V_10 -> V_263 ) != 0 ) ;
F_103 ( V_10 ) ;
}
STATIC int
F_104 (
struct V_12 * V_13 ,
int * V_265 ,
char * V_11 )
{
struct V_9 * V_10 = F_74 ( V_13 ) ;
T_4 * V_140 = & V_10 -> V_141 ;
T_13 args [ V_266 ] ;
char * V_267 ;
int error ;
F_105 ( V_13 ) ;
while ( ( V_267 = F_5 ( & V_11 , L_1 ) ) != NULL ) {
int V_268 ;
if ( ! * V_267 )
continue;
V_268 = F_106 ( V_267 , V_269 , args ) ;
switch ( V_268 ) {
case V_270 :
V_10 -> V_28 |= V_34 ;
break;
case V_271 :
V_10 -> V_28 &= ~ V_34 ;
break;
case V_272 :
V_10 -> V_273 = F_23 ( V_10 , V_140 -> V_274 ) ;
break;
case V_275 :
V_10 -> V_273 = F_17 ( V_10 , V_140 -> V_274 ) ;
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
V_10 -> V_28 &= ~ V_29 ;
if ( V_10 -> V_276 ) {
error = F_107 ( V_10 , false ) ;
if ( error ) {
F_6 ( V_10 , L_38 ) ;
return error ;
}
V_10 -> V_276 = false ;
}
F_95 ( V_10 ) ;
F_108 ( V_10 ) ;
}
if ( ! ( V_10 -> V_28 & V_29 ) && ( * V_265 & V_27 ) ) {
F_93 ( V_10 ) ;
F_97 ( V_10 ) ;
V_10 -> V_28 |= V_29 ;
}
return 0 ;
}
STATIC int
F_109 (
struct V_12 * V_13 )
{
struct V_9 * V_10 = F_74 ( V_13 ) ;
F_93 ( V_10 ) ;
F_97 ( V_10 ) ;
return F_107 ( V_10 , true ) ;
}
STATIC int
F_110 (
struct V_12 * V_13 )
{
struct V_9 * V_10 = F_74 ( V_13 ) ;
F_95 ( V_10 ) ;
F_108 ( V_10 ) ;
return 0 ;
}
STATIC int
F_111 (
struct V_121 * V_122 ,
struct V_225 * V_277 )
{
return F_11 ( F_74 ( V_277 -> V_228 ) , V_122 ) ;
}
STATIC int
F_112 (
struct V_9 * V_10 )
{
int V_278 = ( V_10 -> V_28 & V_29 ) ;
if ( F_113 ( & V_10 -> V_141 ) ) {
if ( V_10 -> V_37 <= 0 &&
V_10 -> V_141 . V_279 > V_280 ) {
V_10 -> V_37 = V_10 -> V_141 . V_279 ;
} else if ( V_10 -> V_37 > 0 &&
V_10 -> V_37 < V_10 -> V_141 . V_279 ) {
F_6 ( V_10 ,
L_39 ) ;
return - V_8 ;
}
} else {
if ( V_10 -> V_37 > V_280 ) {
F_6 ( V_10 ,
L_40 ) ;
return - V_8 ;
}
}
if ( F_114 ( & V_10 -> V_141 ) &&
( V_10 -> V_28 & V_77 ) ) {
F_6 ( V_10 ,
L_41 ,
V_76 , V_74 ) ;
return - V_8 ;
}
if ( F_115 ( & V_10 -> V_141 ) &&
! ( V_10 -> V_28 & V_77 ) )
V_10 -> V_28 |= V_75 ;
if ( ( V_10 -> V_141 . V_281 & V_282 ) && ! V_278 ) {
F_6 ( V_10 ,
L_42 ) ;
return - V_283 ;
}
if ( ( V_10 -> V_81 & ( V_101 | V_102 ) ) &&
( V_10 -> V_81 & ( V_95 | V_96 ) ) &&
! F_116 ( & V_10 -> V_141 ) ) {
F_6 ( V_10 ,
L_43 ) ;
return - V_8 ;
}
return 0 ;
}
STATIC int
F_117 (
struct V_12 * V_13 ,
void * V_284 ,
int V_285 )
{
struct V_199 * V_277 ;
struct V_9 * V_10 = NULL ;
int V_265 = 0 , error = - V_24 ;
V_10 = F_118 ( sizeof( struct V_9 ) , V_23 ) ;
if ( ! V_10 )
goto V_173;
F_61 ( & V_10 -> V_242 ) ;
F_119 ( & V_10 -> V_286 ) ;
F_60 ( & V_10 -> V_263 , 0 ) ;
F_120 ( & V_10 -> V_287 , V_288 ) ;
F_120 ( & V_10 -> V_289 , V_290 ) ;
V_10 -> V_291 . V_292 . V_293 = V_294 ;
V_10 -> V_14 = V_13 ;
V_13 -> V_295 = V_10 ;
error = F_3 ( V_10 , ( char * ) V_284 ) ;
if ( error )
goto V_296;
F_121 ( V_13 , V_180 ) ;
V_13 -> V_297 = V_298 ;
V_13 -> V_299 = & V_300 ;
#ifdef F_8
V_13 -> V_301 = & V_302 ;
V_13 -> V_303 = V_304 | V_305 | V_306 ;
#endif
V_13 -> V_307 = & V_308 ;
if ( V_285 )
V_265 |= V_309 ;
error = F_34 ( V_10 ) ;
if ( error )
goto V_296;
error = F_39 ( V_10 ) ;
if ( error )
goto V_310;
error = F_122 ( V_10 ) ;
if ( error )
goto V_311;
error = F_123 ( V_10 , V_265 ) ;
if ( error )
goto V_312;
error = F_112 ( V_10 ) ;
if ( error )
goto V_313;
error = F_36 ( V_10 ) ;
if ( error )
goto V_313;
error = F_124 ( V_10 ) ;
if ( error )
goto V_313;
V_13 -> V_314 = V_235 ;
V_13 -> V_315 = V_10 -> V_141 . V_244 ;
V_13 -> V_316 = F_7 ( V_13 -> V_315 ) - 1 ;
V_13 -> V_317 = F_15 ( V_13 -> V_316 ) ;
V_13 -> V_318 = V_319 ;
V_13 -> V_320 = 1 ;
F_125 ( V_13 ) ;
if ( F_126 ( & V_10 -> V_141 ) == V_321 )
V_13 -> V_26 |= V_322 ;
error = F_127 ( V_10 ) ;
if ( error )
goto V_323;
V_277 = F_128 ( F_59 ( V_10 -> V_324 ) ) ;
if ( ! V_277 ) {
error = - V_325 ;
goto V_326;
}
V_13 -> V_327 = F_129 ( V_277 ) ;
if ( ! V_13 -> V_327 ) {
error = - V_24 ;
goto V_326;
}
return 0 ;
V_323:
F_75 ( V_10 ) ;
V_313:
F_77 ( V_10 ) ;
V_312:
F_78 ( V_10 ) ;
V_311:
F_42 ( V_10 ) ;
V_310:
F_32 ( V_10 ) ;
V_296:
F_71 ( V_10 ) ;
F_72 ( V_10 ) ;
V_173:
return error ;
V_326:
F_75 ( V_10 ) ;
F_76 ( V_10 ) ;
goto V_313;
}
STATIC struct V_225 *
F_130 (
struct V_328 * V_329 ,
int V_265 ,
const char * V_330 ,
void * V_284 )
{
return F_131 ( V_329 , V_265 , V_330 , V_284 , F_117 ) ;
}
static long
F_132 (
struct V_12 * V_13 ,
struct V_331 * V_332 )
{
return F_133 ( F_74 ( V_13 ) ) ;
}
static long
F_134 (
struct V_12 * V_13 ,
struct V_331 * V_332 )
{
return F_135 ( F_74 ( V_13 ) , V_332 -> V_333 ) ;
}
STATIC int T_14
F_136 ( void )
{
V_334 = F_137 ( sizeof( V_335 ) , L_44 ) ;
if ( ! V_334 )
goto V_173;
V_336 = F_138 ( 4 * V_337 ,
V_334 ) ;
if ( ! V_336 )
goto V_338;
V_339 = F_137 ( sizeof( V_340 ) ,
L_45 ) ;
if ( ! V_339 )
goto V_341;
V_342 = F_137 ( sizeof( V_343 ) ,
L_46 ) ;
if ( ! V_342 )
goto V_344;
V_345 = F_137 ( sizeof( V_346 ) ,
L_47 ) ;
if ( ! V_345 )
goto V_347;
V_348 = F_137 ( sizeof( V_349 ) ,
L_48 ) ;
if ( ! V_348 )
goto V_350;
V_351 = F_137 ( sizeof( V_352 ) , L_49 ) ;
if ( ! V_351 )
goto V_353;
V_354 = F_137 ( sizeof( V_355 ) , L_50 ) ;
if ( ! V_354 )
goto V_356;
V_357 =
F_137 ( sizeof( struct V_358 ) ,
L_51 ) ;
if ( ! V_357 )
goto V_359;
V_360 = F_137 ( sizeof( struct V_361 ) ,
L_52 ) ;
if ( ! V_360 )
goto V_362;
V_363 = F_137 ( ( sizeof( V_364 ) +
( ( V_365 - 1 ) *
sizeof( V_366 ) ) ) , L_53 ) ;
if ( ! V_363 )
goto V_367;
V_368 = F_137 ( ( sizeof( V_369 ) +
( ( V_370 - 1 ) *
sizeof( V_366 ) ) ) , L_54 ) ;
if ( ! V_368 )
goto V_371;
V_372 =
F_139 ( sizeof( T_10 ) , L_55 ,
V_373 | V_374 | V_375 ,
F_57 ) ;
if ( ! V_372 )
goto V_376;
V_377 =
F_139 ( sizeof( V_378 ) , L_56 ,
V_375 , NULL ) ;
if ( ! V_377 )
goto V_379;
V_380 = F_137 ( sizeof( struct V_381 ) ,
L_57 ) ;
if ( ! V_380 )
goto V_382;
return 0 ;
V_382:
F_140 ( V_377 ) ;
V_379:
F_140 ( V_372 ) ;
V_376:
F_140 ( V_368 ) ;
V_371:
F_140 ( V_363 ) ;
V_367:
F_140 ( V_360 ) ;
V_362:
F_140 ( V_357 ) ;
V_359:
F_140 ( V_354 ) ;
V_356:
F_140 ( V_351 ) ;
V_353:
F_140 ( V_348 ) ;
V_350:
F_140 ( V_345 ) ;
V_347:
F_140 ( V_342 ) ;
V_344:
F_140 ( V_339 ) ;
V_341:
F_141 ( V_336 ) ;
V_338:
F_140 ( V_334 ) ;
V_173:
return - V_24 ;
}
STATIC void
F_142 ( void )
{
F_143 () ;
F_140 ( V_380 ) ;
F_140 ( V_377 ) ;
F_140 ( V_372 ) ;
F_140 ( V_368 ) ;
F_140 ( V_363 ) ;
F_140 ( V_360 ) ;
F_140 ( V_357 ) ;
F_140 ( V_354 ) ;
F_140 ( V_351 ) ;
F_140 ( V_348 ) ;
F_140 ( V_345 ) ;
F_140 ( V_342 ) ;
F_140 ( V_339 ) ;
F_141 ( V_336 ) ;
F_140 ( V_334 ) ;
}
STATIC int T_14
F_144 ( void )
{
V_383 = F_40 ( L_58 ,
V_183 | V_184 , 0 ) ;
if ( ! V_383 )
return - V_24 ;
return 0 ;
}
STATIC void
F_145 ( void )
{
F_41 ( V_383 ) ;
}
STATIC int T_14
F_146 ( void )
{
int error ;
F_147 (KERN_INFO XFS_VERSION_STRING L_59
XFS_BUILD_OPTIONS L_60 ) ;
F_148 () ;
error = F_136 () ;
if ( error )
goto V_173;
error = F_144 () ;
if ( error )
goto V_384;
error = F_149 () ;
if ( error )
goto V_385;
error = F_150 () ;
if ( error )
goto V_386;
error = F_151 () ;
if ( error )
goto V_387;
error = F_152 () ;
if ( error )
goto V_388;
V_294 = F_153 ( L_61 , NULL , V_389 ) ;
if ( ! V_294 ) {
error = - V_24 ;
goto V_390; ;
}
#ifdef F_154
V_391 . V_292 . V_293 = V_294 ;
error = F_155 ( & V_391 , & V_392 , NULL , L_62 ) ;
if ( error )
goto V_393;
#endif
error = F_156 () ;
if ( error )
goto V_394;
error = F_157 ( & V_395 ) ;
if ( error )
goto V_396;
return 0 ;
V_396:
F_158 () ;
V_394:
#ifdef F_154
F_159 ( & V_391 ) ;
V_393:
#endif
F_160 ( V_294 ) ;
V_390:
F_161 () ;
V_388:
F_162 () ;
V_387:
F_163 () ;
V_386:
F_164 () ;
V_385:
F_145 () ;
V_384:
F_142 () ;
V_173:
return error ;
}
STATIC void T_15
F_165 ( void )
{
F_158 () ;
F_166 ( & V_395 ) ;
#ifdef F_154
F_159 ( & V_391 ) ;
#endif
F_160 ( V_294 ) ;
F_161 () ;
F_162 () ;
F_163 () ;
F_164 () ;
F_145 () ;
F_142 () ;
}
