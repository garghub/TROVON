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
if ( V_170 )
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
V_183 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_182 )
goto V_173;
V_10 -> V_184 = F_40 ( L_29 ,
V_183 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_184 )
goto V_185;
V_10 -> V_186 = F_40 ( L_30 ,
V_183 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_186 )
goto V_187;
V_10 -> V_188 = F_40 ( L_31 ,
0 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_188 )
goto V_189;
V_10 -> V_190 = F_40 ( L_32 ,
0 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_190 )
goto V_191;
V_10 -> V_192 = F_40 ( L_33 ,
0 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_192 )
goto V_193;
return 0 ;
V_193:
F_41 ( V_10 -> V_190 ) ;
V_191:
F_41 ( V_10 -> V_188 ) ;
V_189:
F_41 ( V_10 -> V_186 ) ;
V_187:
F_41 ( V_10 -> V_184 ) ;
V_185:
F_41 ( V_10 -> V_182 ) ;
V_173:
return - V_24 ;
}
STATIC void
F_42 (
struct V_9 * V_10 )
{
F_41 ( V_10 -> V_192 ) ;
F_41 ( V_10 -> V_190 ) ;
F_41 ( V_10 -> V_188 ) ;
F_41 ( V_10 -> V_186 ) ;
F_41 ( V_10 -> V_182 ) ;
F_41 ( V_10 -> V_184 ) ;
}
void
F_43 (
struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
if ( F_44 ( & V_13 -> V_194 ) ) {
F_45 ( V_13 ) ;
F_46 ( & V_13 -> V_194 ) ;
}
}
STATIC struct V_195 *
F_47 (
struct V_12 * V_13 )
{
F_48 () ;
return NULL ;
}
STATIC void
F_49 (
struct V_195 * V_195 )
{
struct V_196 * V_197 = F_50 ( V_195 ) ;
F_51 ( V_197 ) ;
F_52 ( V_198 ) ;
ASSERT ( F_53 ( V_197 -> V_199 ) || V_197 -> V_200 == 0 ) ;
F_54 ( ! F_55 ( V_197 , V_201 ) ) ;
F_54 ( ! F_55 ( V_197 , V_202 ) ) ;
F_56 ( V_197 ) ;
}
STATIC void
F_57 (
void * V_195 )
{
struct V_196 * V_197 = V_195 ;
memset ( V_197 , 0 , sizeof( struct V_196 ) ) ;
F_58 ( F_59 ( V_197 ) ) ;
F_60 ( & V_197 -> V_203 , 0 ) ;
F_61 ( & V_197 -> V_204 ) ;
F_62 ( & V_197 -> V_205 , V_206 | V_207 ,
L_34 , V_197 -> V_208 ) ;
}
STATIC void
F_63 (
struct V_195 * V_195 )
{
T_10 * V_197 = F_50 ( V_195 ) ;
ASSERT ( ! F_64 ( & V_197 -> V_209 . V_210 ) ) ;
F_65 ( V_197 ) ;
F_66 ( & V_195 -> V_211 ) ;
F_67 ( V_195 ) ;
F_52 ( V_212 ) ;
F_52 ( V_213 ) ;
F_68 ( V_214 ) ;
F_69 ( V_197 ) ;
}
STATIC int
F_70 (
struct V_195 * V_195 )
{
struct V_196 * V_197 = F_50 ( V_195 ) ;
return F_71 ( V_195 ) || ( V_197 -> V_215 & V_216 ) ;
}
STATIC void
F_72 (
struct V_9 * V_10 )
{
F_73 ( V_10 -> V_20 ) ;
F_73 ( V_10 -> V_45 ) ;
F_73 ( V_10 -> V_42 ) ;
}
STATIC void
F_74 (
struct V_12 * V_13 )
{
struct V_9 * V_10 = F_75 ( V_13 ) ;
F_76 ( V_10 ) ;
F_77 ( V_10 ) ;
F_78 ( V_10 ) ;
F_79 ( V_10 ) ;
F_42 ( V_10 ) ;
F_32 ( V_10 ) ;
F_72 ( V_10 ) ;
F_73 ( V_10 ) ;
}
STATIC int
F_80 (
struct V_12 * V_13 ,
int V_217 )
{
struct V_9 * V_10 = F_75 ( V_13 ) ;
if ( ! V_217 )
return 0 ;
F_81 ( V_10 , V_218 ) ;
if ( V_219 ) {
F_82 ( & V_10 -> V_220 -> V_221 ) ;
}
return 0 ;
}
STATIC int
F_83 (
struct V_222 * V_222 ,
struct V_223 * V_224 )
{
struct V_9 * V_10 = F_75 ( V_222 -> V_225 ) ;
T_4 * V_140 = & V_10 -> V_141 ;
struct V_196 * V_197 = F_50 ( V_222 -> V_226 ) ;
T_2 V_227 , V_228 ;
T_11 V_229 ;
T_12 V_230 ;
V_224 -> V_231 = V_232 ;
V_224 -> V_233 = V_22 - 1 ;
V_228 = F_84 ( V_10 -> V_167 -> V_234 ) ;
V_224 -> V_235 . V_236 [ 0 ] = ( V_237 ) V_228 ;
V_224 -> V_235 . V_236 [ 1 ] = ( V_237 ) ( V_228 >> 32 ) ;
F_85 ( V_10 , V_238 ) ;
F_86 ( & V_10 -> V_239 ) ;
V_224 -> V_240 = V_140 -> V_241 ;
V_229 = V_140 -> V_242 ? V_140 -> V_243 : 0 ;
V_224 -> V_244 = V_140 -> V_148 - V_229 ;
V_224 -> V_245 = V_224 -> V_246 =
V_140 -> V_247 - F_87 ( V_10 ) ;
V_227 = V_224 -> V_245 << V_140 -> V_248 ;
V_224 -> V_249 =
F_88 ( V_140 -> V_250 + V_227 , ( T_2 ) V_251 ) ;
if ( V_10 -> V_146 )
V_224 -> V_249 = F_89 ( F_90 ( V_224 -> V_249 ) ,
V_224 -> V_249 ,
V_10 -> V_146 ) ;
V_230 = V_224 -> V_249 - ( V_140 -> V_250 - V_140 -> V_252 ) ;
V_224 -> V_253 = F_91 ( T_12 , V_230 , 0 ) ;
F_92 ( & V_10 -> V_239 ) ;
if ( ( V_197 -> V_254 . V_255 & V_256 ) &&
( ( V_10 -> V_81 & ( V_95 | V_97 ) ) ) ==
( V_95 | V_97 ) )
F_93 ( V_197 , V_224 ) ;
return 0 ;
}
STATIC void
F_94 ( struct V_9 * V_10 )
{
T_2 V_257 = 0 ;
V_10 -> V_258 = V_10 -> V_259 ;
F_95 ( V_10 , & V_257 , NULL ) ;
}
STATIC void
F_96 ( struct V_9 * V_10 )
{
T_2 V_257 ;
if ( V_10 -> V_258 ) {
V_257 = V_10 -> V_258 ;
V_10 -> V_258 = 0 ;
} else
V_257 = F_97 ( V_10 ) ;
F_95 ( V_10 , & V_257 , NULL ) ;
}
static void
F_98 (
struct V_9 * V_10 )
{
int error = 0 ;
while ( F_99 ( & V_10 -> V_260 ) > 0 )
F_100 ( 100 ) ;
F_81 ( V_10 , V_218 ) ;
F_101 ( V_10 , 0 ) ;
F_101 ( V_10 , V_261 ) ;
error = F_102 ( V_10 ) ;
if ( error )
F_6 ( V_10 , L_35
L_36 ) ;
F_103 ( F_99 ( & V_10 -> V_260 ) != 0 ) ;
F_104 ( V_10 ) ;
}
STATIC int
F_105 (
struct V_12 * V_13 ,
int * V_262 ,
char * V_11 )
{
struct V_9 * V_10 = F_75 ( V_13 ) ;
T_4 * V_140 = & V_10 -> V_141 ;
T_13 args [ V_263 ] ;
char * V_264 ;
int error ;
F_106 ( V_13 ) ;
while ( ( V_264 = F_5 ( & V_11 , L_1 ) ) != NULL ) {
int V_265 ;
if ( ! * V_264 )
continue;
V_265 = F_107 ( V_264 , V_266 , args ) ;
switch ( V_265 ) {
case V_267 :
V_10 -> V_28 |= V_34 ;
break;
case V_268 :
V_10 -> V_28 &= ~ V_34 ;
break;
case V_269 :
V_10 -> V_270 = F_23 ( V_10 , V_140 -> V_271 ) ;
break;
case V_272 :
V_10 -> V_270 = F_17 ( V_10 , V_140 -> V_271 ) ;
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
if ( ( V_10 -> V_28 & V_29 ) && ! ( * V_262 & V_27 ) ) {
V_10 -> V_28 &= ~ V_29 ;
if ( V_10 -> V_273 ) {
error = F_108 ( V_10 , V_10 -> V_273 ) ;
if ( error ) {
F_6 ( V_10 , L_37 ) ;
return error ;
}
V_10 -> V_273 = 0 ;
}
F_96 ( V_10 ) ;
F_109 ( V_10 ) ;
}
if ( ! ( V_10 -> V_28 & V_29 ) && ( * V_262 & V_27 ) ) {
F_94 ( V_10 ) ;
F_98 ( V_10 ) ;
V_10 -> V_28 |= V_29 ;
}
return 0 ;
}
STATIC int
F_110 (
struct V_12 * V_13 )
{
struct V_9 * V_10 = F_75 ( V_13 ) ;
F_94 ( V_10 ) ;
F_98 ( V_10 ) ;
return F_111 ( V_10 ) ;
}
STATIC int
F_112 (
struct V_12 * V_13 )
{
struct V_9 * V_10 = F_75 ( V_13 ) ;
F_96 ( V_10 ) ;
F_109 ( V_10 ) ;
return 0 ;
}
STATIC int
F_113 (
struct V_121 * V_122 ,
struct V_222 * V_274 )
{
return F_11 ( F_75 ( V_274 -> V_225 ) , V_122 ) ;
}
STATIC int
F_114 (
struct V_9 * V_10 )
{
int V_275 = ( V_10 -> V_28 & V_29 ) ;
if ( F_115 ( & V_10 -> V_141 ) ) {
if ( V_10 -> V_37 <= 0 &&
V_10 -> V_141 . V_276 > V_277 ) {
V_10 -> V_37 = V_10 -> V_141 . V_276 ;
} else if ( V_10 -> V_37 > 0 &&
V_10 -> V_37 < V_10 -> V_141 . V_276 ) {
F_6 ( V_10 ,
L_38 ) ;
return - V_8 ;
}
} else {
if ( V_10 -> V_37 > V_277 ) {
F_6 ( V_10 ,
L_39 ) ;
return - V_8 ;
}
}
if ( F_116 ( & V_10 -> V_141 ) &&
( V_10 -> V_28 & V_77 ) ) {
F_6 ( V_10 ,
L_40 ,
V_76 , V_74 ) ;
return - V_8 ;
}
if ( F_117 ( & V_10 -> V_141 ) &&
! ( V_10 -> V_28 & V_77 ) )
V_10 -> V_28 |= V_75 ;
if ( ( V_10 -> V_141 . V_278 & V_279 ) && ! V_275 ) {
F_6 ( V_10 ,
L_41 ) ;
return - V_280 ;
}
if ( ( V_10 -> V_81 & ( V_101 | V_102 ) ) &&
( V_10 -> V_81 & ( V_95 | V_96 ) ) &&
! F_118 ( & V_10 -> V_141 ) ) {
F_6 ( V_10 ,
L_42 ) ;
return - V_8 ;
}
return 0 ;
}
STATIC int
F_119 (
struct V_12 * V_13 ,
void * V_281 ,
int V_282 )
{
struct V_195 * V_274 ;
struct V_9 * V_10 = NULL ;
int V_262 = 0 , error = - V_24 ;
V_10 = F_120 ( sizeof( struct V_9 ) , V_23 ) ;
if ( ! V_10 )
goto V_173;
F_61 ( & V_10 -> V_239 ) ;
F_121 ( & V_10 -> V_283 ) ;
F_60 ( & V_10 -> V_260 , 0 ) ;
F_122 ( & V_10 -> V_284 , V_285 ) ;
F_122 ( & V_10 -> V_286 , V_287 ) ;
V_10 -> V_14 = V_13 ;
V_13 -> V_288 = V_10 ;
error = F_3 ( V_10 , ( char * ) V_281 ) ;
if ( error )
goto V_289;
F_123 ( V_13 , V_180 ) ;
V_13 -> V_290 = V_291 ;
V_13 -> V_292 = & V_293 ;
#ifdef F_8
V_13 -> V_294 = & V_295 ;
#endif
V_13 -> V_296 = & V_297 ;
if ( V_282 )
V_262 |= V_298 ;
error = F_34 ( V_10 ) ;
if ( error )
goto V_289;
error = F_39 ( V_10 ) ;
if ( error )
goto V_299;
error = F_124 ( V_10 ) ;
if ( error )
goto V_300;
error = F_125 ( V_10 , V_262 ) ;
if ( error )
goto V_301;
error = F_114 ( V_10 ) ;
if ( error )
goto V_302;
error = F_36 ( V_10 ) ;
if ( error )
goto V_302;
error = F_126 ( V_10 ) ;
if ( error )
goto V_302;
V_13 -> V_303 = V_232 ;
V_13 -> V_304 = V_10 -> V_141 . V_241 ;
V_13 -> V_305 = F_7 ( V_13 -> V_304 ) - 1 ;
V_13 -> V_306 = F_15 ( V_13 -> V_305 ) ;
V_13 -> V_307 = V_308 ;
V_13 -> V_309 = 1 ;
F_127 ( V_13 ) ;
if ( F_128 ( & V_10 -> V_141 ) == V_310 )
V_13 -> V_26 |= V_311 ;
error = F_129 ( V_10 ) ;
if ( error )
goto V_312;
V_274 = F_130 ( F_59 ( V_10 -> V_313 ) ) ;
if ( ! V_274 ) {
error = - V_314 ;
goto V_315;
}
V_13 -> V_316 = F_131 ( V_274 ) ;
if ( ! V_13 -> V_316 ) {
error = - V_24 ;
goto V_315;
}
return 0 ;
V_312:
F_76 ( V_10 ) ;
V_302:
F_78 ( V_10 ) ;
V_301:
F_79 ( V_10 ) ;
V_300:
F_42 ( V_10 ) ;
V_299:
F_32 ( V_10 ) ;
V_289:
F_72 ( V_10 ) ;
F_73 ( V_10 ) ;
V_173:
return error ;
V_315:
F_76 ( V_10 ) ;
F_77 ( V_10 ) ;
goto V_302;
}
STATIC struct V_222 *
F_132 (
struct V_317 * V_318 ,
int V_262 ,
const char * V_319 ,
void * V_281 )
{
return F_133 ( V_318 , V_262 , V_319 , V_281 , F_119 ) ;
}
static long
F_134 (
struct V_12 * V_13 ,
int V_320 )
{
return F_135 ( F_75 ( V_13 ) ) ;
}
static long
F_136 (
struct V_12 * V_13 ,
long V_321 ,
int V_320 )
{
return F_137 ( F_75 ( V_13 ) , V_321 ) ;
}
STATIC int T_14
F_138 ( void )
{
V_322 = F_139 ( sizeof( V_323 ) , L_43 ) ;
if ( ! V_322 )
goto V_173;
V_324 = F_140 ( 4 * V_325 ,
V_322 ) ;
if ( ! V_324 )
goto V_326;
V_327 = F_139 ( sizeof( V_328 ) ,
L_44 ) ;
if ( ! V_327 )
goto V_329;
V_330 = F_139 ( sizeof( V_331 ) ,
L_45 ) ;
if ( ! V_330 )
goto V_332;
V_333 = F_139 ( sizeof( V_334 ) ,
L_46 ) ;
if ( ! V_333 )
goto V_335;
V_336 = F_139 ( sizeof( V_337 ) ,
L_47 ) ;
if ( ! V_336 )
goto V_338;
V_339 = F_139 ( sizeof( V_340 ) , L_48 ) ;
if ( ! V_339 )
goto V_341;
V_342 = F_139 ( sizeof( V_343 ) , L_49 ) ;
if ( ! V_342 )
goto V_344;
V_345 =
F_139 ( sizeof( struct V_346 ) ,
L_50 ) ;
if ( ! V_345 )
goto V_347;
V_348 = F_139 ( sizeof( struct V_349 ) ,
L_51 ) ;
if ( ! V_348 )
goto V_350;
V_351 = F_139 ( ( sizeof( V_352 ) +
( ( V_353 - 1 ) *
sizeof( V_354 ) ) ) , L_52 ) ;
if ( ! V_351 )
goto V_355;
V_356 = F_139 ( ( sizeof( V_357 ) +
( ( V_358 - 1 ) *
sizeof( V_354 ) ) ) , L_53 ) ;
if ( ! V_356 )
goto V_359;
V_360 =
F_141 ( sizeof( T_10 ) , L_54 ,
V_361 | V_362 | V_363 ,
F_57 ) ;
if ( ! V_360 )
goto V_364;
V_365 =
F_141 ( sizeof( V_366 ) , L_55 ,
V_363 , NULL ) ;
if ( ! V_365 )
goto V_367;
V_368 = F_139 ( sizeof( struct V_369 ) ,
L_56 ) ;
if ( ! V_368 )
goto V_370;
return 0 ;
V_370:
F_142 ( V_365 ) ;
V_367:
F_142 ( V_360 ) ;
V_364:
F_142 ( V_356 ) ;
V_359:
F_142 ( V_351 ) ;
V_355:
F_142 ( V_348 ) ;
V_350:
F_142 ( V_345 ) ;
V_347:
F_142 ( V_342 ) ;
V_344:
F_142 ( V_339 ) ;
V_341:
F_142 ( V_336 ) ;
V_338:
F_142 ( V_333 ) ;
V_335:
F_142 ( V_330 ) ;
V_332:
F_142 ( V_327 ) ;
V_329:
F_143 ( V_324 ) ;
V_326:
F_142 ( V_322 ) ;
V_173:
return - V_24 ;
}
STATIC void
F_144 ( void )
{
F_145 () ;
F_142 ( V_368 ) ;
F_142 ( V_365 ) ;
F_142 ( V_360 ) ;
F_142 ( V_356 ) ;
F_142 ( V_351 ) ;
F_142 ( V_348 ) ;
F_142 ( V_345 ) ;
F_142 ( V_342 ) ;
F_142 ( V_339 ) ;
F_142 ( V_336 ) ;
F_142 ( V_333 ) ;
F_142 ( V_330 ) ;
F_142 ( V_327 ) ;
F_143 ( V_324 ) ;
F_142 ( V_322 ) ;
}
STATIC int T_14
F_146 ( void )
{
V_371 = F_40 ( L_57 , V_183 , 0 ) ;
if ( ! V_371 )
return - V_24 ;
return 0 ;
}
STATIC void
F_147 ( void )
{
F_41 ( V_371 ) ;
}
STATIC int T_14
F_148 ( void )
{
int error ;
F_149 (KERN_INFO XFS_VERSION_STRING L_58
XFS_BUILD_OPTIONS L_59 ) ;
F_150 () ;
error = F_138 () ;
if ( error )
goto V_173;
error = F_146 () ;
if ( error )
goto V_372;
error = F_151 () ;
if ( error )
goto V_373;
error = F_152 () ;
if ( error )
goto V_374;
error = F_153 () ;
if ( error )
goto V_375;
error = F_154 () ;
if ( error )
goto V_376;
V_377 = F_155 ( L_60 , NULL , V_378 ) ;
if ( ! V_377 ) {
error = - V_24 ;
goto V_379; ;
}
error = F_156 () ;
if ( error )
goto V_380;
error = F_157 ( & V_381 ) ;
if ( error )
goto V_382;
return 0 ;
V_382:
F_158 () ;
V_380:
F_159 ( V_377 ) ;
V_379:
F_160 () ;
V_376:
F_161 () ;
V_375:
F_162 () ;
V_374:
F_163 () ;
V_373:
F_147 () ;
V_372:
F_144 () ;
V_173:
return error ;
}
STATIC void T_15
F_164 ( void )
{
F_158 () ;
F_165 ( & V_381 ) ;
F_159 ( V_377 ) ;
F_160 () ;
F_161 () ;
F_162 () ;
F_163 () ;
F_147 () ;
F_144 () ;
}
