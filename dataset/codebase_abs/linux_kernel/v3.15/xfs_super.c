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
return V_24 ;
V_10 -> V_25 = strlen ( V_10 -> V_20 ) + 1 ;
if ( V_13 -> V_26 & V_27 )
V_10 -> V_28 |= V_29 ;
if ( V_13 -> V_26 & V_30 )
V_10 -> V_28 |= V_31 ;
if ( V_13 -> V_26 & V_32 )
V_10 -> V_28 |= V_33 ;
V_10 -> V_28 |= V_34 ;
V_10 -> V_28 |= V_35 ;
#if ! V_36
V_10 -> V_28 |= V_37 ;
#endif
V_10 -> V_38 = - 1 ;
V_10 -> V_39 = - 1 ;
if ( ! V_11 )
goto V_40;
while ( ( V_15 = F_5 ( & V_11 , L_1 ) ) != NULL ) {
if ( ! * V_15 )
continue;
if ( ( V_7 = strchr ( V_15 , '=' ) ) != NULL )
* V_7 ++ = 0 ;
if ( ! strcmp ( V_15 , V_41 ) ) {
if ( ! V_7 || ! * V_7 ) {
F_6 ( V_10 , L_2 ,
V_15 ) ;
return V_8 ;
}
if ( F_2 ( V_7 , 10 , & V_10 -> V_38 ) )
return V_8 ;
} else if ( ! strcmp ( V_15 , V_42 ) ) {
if ( ! V_7 || ! * V_7 ) {
F_6 ( V_10 , L_2 ,
V_15 ) ;
return V_8 ;
}
if ( F_1 ( V_7 , 10 , & V_10 -> V_39 ) )
return V_8 ;
} else if ( ! strcmp ( V_15 , V_43 ) ) {
if ( ! V_7 || ! * V_7 ) {
F_6 ( V_10 , L_2 ,
V_15 ) ;
return V_8 ;
}
V_10 -> V_44 = F_4 ( V_7 , V_22 , V_23 ) ;
if ( ! V_10 -> V_44 )
return V_24 ;
} else if ( ! strcmp ( V_15 , V_45 ) ) {
F_6 ( V_10 , L_3 ,
V_15 ) ;
return V_8 ;
} else if ( ! strcmp ( V_15 , V_46 ) ) {
if ( ! V_7 || ! * V_7 ) {
F_6 ( V_10 , L_2 ,
V_15 ) ;
return V_8 ;
}
V_10 -> V_47 = F_4 ( V_7 , V_22 , V_23 ) ;
if ( ! V_10 -> V_47 )
return V_24 ;
} else if ( ! strcmp ( V_15 , V_48 ) ) {
if ( ! V_7 || ! * V_7 ) {
F_6 ( V_10 , L_2 ,
V_15 ) ;
return V_8 ;
}
if ( F_2 ( V_7 , 10 , & V_18 ) )
return V_8 ;
V_19 = F_7 ( V_18 ) - 1 ;
} else if ( ! strcmp ( V_15 , V_49 ) ) {
if ( ! V_7 || ! * V_7 ) {
F_6 ( V_10 , L_2 ,
V_15 ) ;
return V_8 ;
}
if ( F_1 ( V_7 , 10 , & V_18 ) )
return V_8 ;
V_19 = F_7 ( V_18 ) - 1 ;
} else if ( ! strcmp ( V_15 , V_50 ) ||
! strcmp ( V_15 , V_51 ) ) {
V_10 -> V_28 |= V_52 ;
} else if ( ! strcmp ( V_15 , V_53 ) ||
! strcmp ( V_15 , V_54 ) ) {
V_10 -> V_28 &= ~ V_52 ;
} else if ( ! strcmp ( V_15 , V_55 ) ) {
V_10 -> V_28 |= V_33 ;
} else if ( ! strcmp ( V_15 , V_56 ) ) {
V_10 -> V_28 |= V_57 ;
} else if ( ! strcmp ( V_15 , V_58 ) ) {
V_10 -> V_28 |= V_59 ;
} else if ( ! strcmp ( V_15 , V_60 ) ) {
V_10 -> V_28 |= V_61 ;
} else if ( ! strcmp ( V_15 , V_62 ) ) {
if ( ! V_7 || ! * V_7 ) {
F_6 ( V_10 , L_2 ,
V_15 ) ;
return V_8 ;
}
if ( F_2 ( V_7 , 10 , & V_16 ) )
return V_8 ;
} else if ( ! strcmp ( V_15 , V_63 ) ) {
if ( ! V_7 || ! * V_7 ) {
F_6 ( V_10 , L_2 ,
V_15 ) ;
return V_8 ;
}
if ( F_2 ( V_7 , 10 , & V_17 ) )
return V_8 ;
} else if ( ! strcmp ( V_15 , V_64 ) ) {
V_10 -> V_28 |= V_37 ;
} else if ( ! strcmp ( V_15 , V_65 ) ) {
V_10 -> V_28 &= ~ V_37 ;
#if ! V_36
F_6 ( V_10 , L_3 ,
V_15 ) ;
return V_8 ;
#endif
} else if ( ! strcmp ( V_15 , V_66 ) ) {
V_10 -> V_28 |= V_67 ;
} else if ( ! strcmp ( V_15 , V_68 ) ) {
V_10 -> V_28 |= V_34 ;
} else if ( ! strcmp ( V_15 , V_69 ) ) {
V_10 -> V_28 &= ~ V_34 ;
} else if ( ! strcmp ( V_15 , V_70 ) ) {
V_10 -> V_28 |= V_71 ;
} else if ( ! strcmp ( V_15 , V_72 ) ) {
V_10 -> V_28 &= ~ V_71 ;
} else if ( ! strcmp ( V_15 , V_73 ) ) {
V_10 -> V_28 &= ~ V_35 ;
} else if ( ! strcmp ( V_15 , V_74 ) ) {
V_10 -> V_28 |= V_35 ;
} else if ( ! strcmp ( V_15 , V_75 ) ) {
V_10 -> V_28 |= V_76 ;
} else if ( ! strcmp ( V_15 , V_77 ) ) {
V_10 -> V_28 &= ~ V_76 ;
V_10 -> V_28 |= V_78 ;
} else if ( ! strcmp ( V_15 , V_79 ) ) {
V_10 -> V_28 |= V_80 ;
} else if ( ! strcmp ( V_15 , V_81 ) ) {
V_10 -> V_82 &= ~ V_83 ;
V_10 -> V_82 &= ~ V_84 ;
V_10 -> V_82 &= ~ V_85 ;
} else if ( ! strcmp ( V_15 , V_86 ) ||
! strcmp ( V_15 , V_87 ) ||
! strcmp ( V_15 , V_88 ) ) {
V_10 -> V_82 |= ( V_89 | V_90 |
V_91 ) ;
} else if ( ! strcmp ( V_15 , V_92 ) ||
! strcmp ( V_15 , V_93 ) ) {
V_10 -> V_82 |= ( V_89 | V_90 ) ;
V_10 -> V_82 &= ~ V_91 ;
} else if ( ! strcmp ( V_15 , V_94 ) ||
! strcmp ( V_15 , V_95 ) ) {
V_10 -> V_82 |= ( V_96 | V_97 |
V_98 ) ;
} else if ( ! strcmp ( V_15 , V_99 ) ) {
V_10 -> V_82 |= ( V_96 | V_97 ) ;
V_10 -> V_82 &= ~ V_98 ;
} else if ( ! strcmp ( V_15 , V_100 ) ||
! strcmp ( V_15 , V_101 ) ) {
V_10 -> V_82 |= ( V_102 | V_103 |
V_104 ) ;
} else if ( ! strcmp ( V_15 , V_105 ) ) {
V_10 -> V_82 |= ( V_102 | V_103 ) ;
V_10 -> V_82 &= ~ V_104 ;
} else if ( ! strcmp ( V_15 , V_106 ) ) {
F_6 ( V_10 ,
L_4 ) ;
} else if ( ! strcmp ( V_15 , V_107 ) ) {
F_6 ( V_10 ,
L_5 ) ;
} else if ( ! strcmp ( V_15 , V_108 ) ) {
V_10 -> V_28 |= V_109 ;
} else if ( ! strcmp ( V_15 , V_110 ) ) {
V_10 -> V_28 &= ~ V_109 ;
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
return V_8 ;
}
}
if ( ( V_10 -> V_28 & V_57 ) &&
! ( V_10 -> V_28 & V_29 ) ) {
F_6 ( V_10 , L_15 ) ;
return V_8 ;
}
if ( ( V_10 -> V_28 & V_59 ) && ( V_16 || V_17 ) ) {
F_6 ( V_10 ,
L_16 ) ;
return V_8 ;
}
#ifndef F_8
if ( F_9 ( V_10 ) ) {
F_6 ( V_10 , L_17 ) ;
return V_8 ;
}
#endif
if ( ( V_16 && ! V_17 ) || ( ! V_16 && V_17 ) ) {
F_6 ( V_10 , L_18 ) ;
return V_8 ;
}
if ( V_16 && ( V_17 % V_16 != 0 ) ) {
F_6 ( V_10 ,
L_19 ,
V_17 , V_16 ) ;
return V_8 ;
}
V_40:
if ( V_16 && ! ( V_10 -> V_28 & V_59 ) ) {
V_10 -> V_111 = V_16 ;
V_10 -> V_112 = V_17 ;
}
if ( V_10 -> V_38 != - 1 &&
V_10 -> V_38 != 0 &&
( V_10 -> V_38 < V_113 ||
V_10 -> V_38 > V_114 ) ) {
F_6 ( V_10 , L_20 ,
V_10 -> V_38 , V_113 , V_114 ) ;
return F_10 ( V_8 ) ;
}
if ( V_10 -> V_39 != - 1 &&
V_10 -> V_39 != 0 &&
( V_10 -> V_39 < V_115 ||
V_10 -> V_39 > V_116 ||
! F_11 ( V_10 -> V_39 ) ) ) {
F_6 ( V_10 ,
L_21 ,
V_10 -> V_39 ) ;
return F_10 ( V_8 ) ;
}
if ( V_19 ) {
if ( V_19 > V_117 ||
V_19 < V_118 ) {
F_6 ( V_10 , L_22 ,
V_19 , V_118 ,
V_117 ) ;
return F_10 ( V_8 ) ;
}
V_10 -> V_28 |= V_119 ;
V_10 -> V_120 = V_19 ;
V_10 -> V_121 = V_19 ;
}
return 0 ;
}
STATIC int
F_12 (
struct V_9 * V_10 ,
struct V_122 * V_123 )
{
static struct V_124 V_125 [] = {
{ V_71 , L_1 V_70 } ,
{ V_33 , L_1 V_55 } ,
{ V_59 , L_1 V_58 } ,
{ V_61 , L_1 V_60 } ,
{ V_67 , L_1 V_66 } ,
{ V_57 , L_1 V_56 } ,
{ V_76 , L_1 V_75 } ,
{ V_80 , L_1 V_79 } ,
{ V_52 , L_1 V_50 } ,
{ V_109 , L_1 V_108 } ,
{ V_37 , L_1 V_64 } ,
{ 0 , NULL }
} ;
static struct V_124 V_126 [] = {
{ V_35 , L_1 V_73 } ,
{ V_34 , L_1 V_69 } ,
{ V_37 , L_1 V_65 } ,
{ 0 , NULL }
} ;
struct V_124 * V_127 ;
for ( V_127 = V_125 ; V_127 -> V_128 ; V_127 ++ ) {
if ( V_10 -> V_28 & V_127 -> V_128 )
F_13 ( V_123 , V_127 -> V_129 ) ;
}
for ( V_127 = V_126 ; V_127 -> V_128 ; V_127 ++ ) {
if ( ! ( V_10 -> V_28 & V_127 -> V_128 ) )
F_13 ( V_123 , V_127 -> V_129 ) ;
}
if ( V_10 -> V_28 & V_119 )
F_14 ( V_123 , L_1 V_49 L_23 ,
( int ) ( 1 << V_10 -> V_121 ) >> 10 ) ;
if ( V_10 -> V_38 > 0 )
F_14 ( V_123 , L_1 V_41 L_24 , V_10 -> V_38 ) ;
if ( V_10 -> V_39 > 0 )
F_14 ( V_123 , L_1 V_42 L_23 , V_10 -> V_39 >> 10 ) ;
if ( V_10 -> V_44 )
F_14 ( V_123 , L_1 V_43 L_25 , V_10 -> V_44 ) ;
if ( V_10 -> V_47 )
F_14 ( V_123 , L_1 V_46 L_25 , V_10 -> V_47 ) ;
if ( V_10 -> V_111 > 0 )
F_14 ( V_123 , L_1 V_62 L_24 ,
( int ) F_15 ( V_10 , V_10 -> V_111 ) ) ;
if ( V_10 -> V_112 > 0 )
F_14 ( V_123 , L_1 V_63 L_24 ,
( int ) F_15 ( V_10 , V_10 -> V_112 ) ) ;
if ( V_10 -> V_82 & ( V_89 | V_91 ) )
F_13 ( V_123 , L_1 V_88 ) ;
else if ( V_10 -> V_82 & V_89 )
F_13 ( V_123 , L_1 V_93 ) ;
if ( V_10 -> V_82 & V_96 ) {
if ( V_10 -> V_82 & V_98 )
F_13 ( V_123 , L_1 V_95 ) ;
else
F_13 ( V_123 , L_1 V_99 ) ;
}
if ( V_10 -> V_82 & V_102 ) {
if ( V_10 -> V_82 & V_104 )
F_13 ( V_123 , L_1 V_101 ) ;
else
F_13 ( V_123 , L_1 V_105 ) ;
}
if ( ! ( V_10 -> V_82 & V_83 ) )
F_13 ( V_123 , L_1 V_81 ) ;
return 0 ;
}
T_2
F_16 (
unsigned int V_130 )
{
unsigned int V_131 = 1 ;
unsigned int V_132 = V_133 - 1 ;
#if V_133 == 32
# if F_17 ( V_134 )
ASSERT ( sizeof( V_135 ) == 8 ) ;
V_131 = V_136 ;
V_132 = V_133 ;
# else
V_131 = V_136 >> ( V_137 - V_130 ) ;
# endif
#endif
return ( ( ( T_2 ) V_131 ) << V_132 ) - 1 ;
}
T_3
F_18 ( struct V_9 * V_10 )
{
T_3 V_138 = 0 ;
T_3 V_139 = 0 ;
T_4 * V_140 = & V_10 -> V_141 ;
T_3 V_142 ;
T_5 V_143 = F_19 ( V_10 , V_140 -> V_144 - 1 , 0 ) ;
T_6 V_145 = F_20 ( V_10 , V_140 -> V_146 - 1 , V_143 ) ;
T_7 * V_147 ;
if ( V_10 -> V_148 ) {
T_2 V_149 ;
V_149 = V_140 -> V_150 * V_140 -> V_151 ;
F_21 ( V_149 , 100 ) ;
V_149 += V_140 -> V_144 - 1 ;
F_21 ( V_149 , V_140 -> V_144 ) ;
V_142 = V_149 ;
} else {
V_142 = V_140 -> V_146 ;
}
for ( V_138 = 0 ; V_138 < V_140 -> V_146 ; V_138 ++ ) {
V_145 = F_20 ( V_10 , V_138 , V_143 ) ;
if ( V_145 > V_152 ) {
V_147 = F_22 ( V_10 , V_138 ) ;
V_147 -> V_153 = 0 ;
V_147 -> V_154 = 0 ;
F_23 ( V_147 ) ;
continue;
}
V_147 = F_22 ( V_10 , V_138 ) ;
V_147 -> V_153 = 1 ;
V_139 ++ ;
if ( V_138 < V_142 )
V_147 -> V_154 = 1 ;
F_23 ( V_147 ) ;
}
V_10 -> V_28 |= ( V_155 |
V_37 ) ;
return V_139 ;
}
T_3
F_24 ( struct V_9 * V_10 )
{
T_3 V_138 = 0 ;
for ( V_138 = 0 ; V_138 < V_10 -> V_141 . V_146 ; V_138 ++ ) {
struct V_156 * V_147 ;
V_147 = F_22 ( V_10 , V_138 ) ;
V_147 -> V_153 = 1 ;
V_147 -> V_154 = 0 ;
F_23 ( V_147 ) ;
}
V_10 -> V_28 &= ~ ( V_155 |
V_37 ) ;
return V_138 ;
}
STATIC int
F_25 (
T_8 * V_10 ,
const char * V_157 ,
struct V_158 * * V_159 )
{
int error = 0 ;
* V_159 = F_26 ( V_157 , V_160 | V_161 | V_162 ,
V_10 ) ;
if ( F_27 ( * V_159 ) ) {
error = F_28 ( * V_159 ) ;
F_6 ( V_10 , L_26 , V_157 , error ) ;
}
return - error ;
}
STATIC void
F_29 (
struct V_158 * V_163 )
{
if ( V_163 )
F_30 ( V_163 , V_160 | V_161 | V_162 ) ;
}
void
F_31 (
T_9 * V_164 )
{
F_32 ( V_164 -> V_165 , V_166 , NULL ) ;
}
STATIC void
F_33 (
struct V_9 * V_10 )
{
if ( V_10 -> V_167 && V_10 -> V_167 != V_10 -> V_168 ) {
struct V_158 * V_169 = V_10 -> V_167 -> V_165 ;
F_34 ( V_10 , V_10 -> V_167 ) ;
F_29 ( V_169 ) ;
}
if ( V_10 -> V_170 ) {
struct V_158 * V_171 = V_10 -> V_170 -> V_165 ;
F_34 ( V_10 , V_10 -> V_170 ) ;
F_29 ( V_171 ) ;
}
F_34 ( V_10 , V_10 -> V_168 ) ;
}
STATIC int
F_35 (
struct V_9 * V_10 )
{
struct V_158 * V_172 = V_10 -> V_14 -> V_173 ;
struct V_158 * V_169 = NULL , * V_171 = NULL ;
int error ;
if ( V_10 -> V_44 ) {
error = F_25 ( V_10 , V_10 -> V_44 , & V_169 ) ;
if ( error )
goto V_174;
}
if ( V_10 -> V_47 ) {
error = F_25 ( V_10 , V_10 -> V_47 , & V_171 ) ;
if ( error )
goto V_175;
if ( V_171 == V_172 || V_171 == V_169 ) {
F_6 ( V_10 ,
L_27 ) ;
error = V_8 ;
goto V_176;
}
}
error = V_24 ;
V_10 -> V_168 = F_36 ( V_10 , V_172 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_168 )
goto V_176;
if ( V_171 ) {
V_10 -> V_170 = F_36 ( V_10 , V_171 , 1 ,
V_10 -> V_20 ) ;
if ( ! V_10 -> V_170 )
goto V_177;
}
if ( V_169 && V_169 != V_172 ) {
V_10 -> V_167 = F_36 ( V_10 , V_169 , 1 ,
V_10 -> V_20 ) ;
if ( ! V_10 -> V_167 )
goto V_178;
} else {
V_10 -> V_167 = V_10 -> V_168 ;
}
return 0 ;
V_178:
if ( V_10 -> V_170 )
F_34 ( V_10 , V_10 -> V_170 ) ;
V_177:
F_34 ( V_10 , V_10 -> V_168 ) ;
V_176:
if ( V_171 )
F_29 ( V_171 ) ;
V_175:
if ( V_169 && V_169 != V_172 )
F_29 ( V_169 ) ;
V_174:
return error ;
}
STATIC int
F_37 (
struct V_9 * V_10 )
{
int error ;
error = F_38 ( V_10 -> V_168 , V_10 -> V_141 . V_179 ,
V_10 -> V_141 . V_180 ) ;
if ( error )
return error ;
if ( V_10 -> V_167 && V_10 -> V_167 != V_10 -> V_168 ) {
unsigned int V_181 = V_182 ;
if ( F_39 ( & V_10 -> V_141 ) )
V_181 = V_10 -> V_141 . V_183 ;
error = F_38 ( V_10 -> V_167 ,
V_10 -> V_141 . V_179 ,
V_181 ) ;
if ( error )
return error ;
}
if ( V_10 -> V_170 ) {
error = F_38 ( V_10 -> V_170 ,
V_10 -> V_141 . V_179 ,
V_10 -> V_141 . V_180 ) ;
if ( error )
return error ;
}
return 0 ;
}
STATIC int
F_40 (
struct V_9 * V_10 )
{
V_10 -> V_184 = F_41 ( L_28 ,
V_185 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_184 )
goto V_174;
V_10 -> V_186 = F_41 ( L_29 ,
V_185 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_186 )
goto V_187;
V_10 -> V_188 = F_41 ( L_30 ,
V_185 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_188 )
goto V_189;
V_10 -> V_190 = F_41 ( L_31 ,
0 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_190 )
goto V_191;
V_10 -> V_192 = F_41 ( L_32 ,
0 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_192 )
goto V_193;
V_10 -> V_194 = F_41 ( L_33 ,
0 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_194 )
goto V_195;
return 0 ;
V_195:
F_42 ( V_10 -> V_192 ) ;
V_193:
F_42 ( V_10 -> V_190 ) ;
V_191:
F_42 ( V_10 -> V_188 ) ;
V_189:
F_42 ( V_10 -> V_186 ) ;
V_187:
F_42 ( V_10 -> V_184 ) ;
V_174:
return - V_24 ;
}
STATIC void
F_43 (
struct V_9 * V_10 )
{
F_42 ( V_10 -> V_194 ) ;
F_42 ( V_10 -> V_192 ) ;
F_42 ( V_10 -> V_190 ) ;
F_42 ( V_10 -> V_188 ) ;
F_42 ( V_10 -> V_184 ) ;
F_42 ( V_10 -> V_186 ) ;
}
void
F_44 (
struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
if ( F_45 ( & V_13 -> V_196 ) ) {
F_46 ( V_13 ) ;
F_47 ( & V_13 -> V_196 ) ;
}
}
STATIC struct V_197 *
F_48 (
struct V_12 * V_13 )
{
F_49 () ;
return NULL ;
}
STATIC void
F_50 (
struct V_197 * V_197 )
{
struct V_198 * V_199 = F_51 ( V_197 ) ;
F_52 ( V_199 ) ;
F_53 ( V_200 ) ;
ASSERT ( F_54 ( V_199 -> V_201 ) || V_199 -> V_202 == 0 ) ;
F_55 ( ! F_56 ( V_199 , V_203 ) ) ;
F_55 ( ! F_56 ( V_199 , V_204 ) ) ;
F_57 ( V_199 ) ;
}
STATIC void
F_58 (
void * V_197 )
{
struct V_198 * V_199 = V_197 ;
memset ( V_199 , 0 , sizeof( struct V_198 ) ) ;
F_59 ( F_60 ( V_199 ) ) ;
F_61 ( & V_199 -> V_205 , 0 ) ;
F_62 ( & V_199 -> V_206 ) ;
F_63 ( & V_199 -> V_207 , V_208 | V_209 ,
L_34 , V_199 -> V_210 ) ;
}
STATIC void
F_64 (
struct V_197 * V_197 )
{
T_10 * V_199 = F_51 ( V_197 ) ;
ASSERT ( ! F_65 ( & V_199 -> V_211 . V_212 ) ) ;
F_66 ( V_199 ) ;
F_67 ( & V_197 -> V_213 ) ;
F_68 ( V_197 ) ;
F_53 ( V_214 ) ;
F_53 ( V_215 ) ;
F_69 ( V_216 ) ;
F_70 ( V_199 ) ;
}
STATIC int
F_71 (
struct V_197 * V_197 )
{
struct V_198 * V_199 = F_51 ( V_197 ) ;
return F_72 ( V_197 ) || ( V_199 -> V_217 & V_218 ) ;
}
STATIC void
F_73 (
struct V_9 * V_10 )
{
F_74 ( V_10 -> V_20 ) ;
F_74 ( V_10 -> V_47 ) ;
F_74 ( V_10 -> V_44 ) ;
}
STATIC void
F_75 (
struct V_12 * V_13 )
{
struct V_9 * V_10 = F_76 ( V_13 ) ;
F_77 ( V_10 ) ;
F_78 ( V_10 ) ;
F_79 ( V_10 ) ;
F_80 ( V_10 ) ;
F_43 ( V_10 ) ;
F_33 ( V_10 ) ;
F_73 ( V_10 ) ;
F_74 ( V_10 ) ;
}
STATIC int
F_81 (
struct V_12 * V_13 ,
int V_219 )
{
struct V_9 * V_10 = F_76 ( V_13 ) ;
if ( ! V_219 )
return 0 ;
F_82 ( V_10 , V_220 ) ;
if ( V_221 ) {
F_83 ( & V_10 -> V_222 -> V_223 ) ;
}
return 0 ;
}
STATIC int
F_84 (
struct V_224 * V_224 ,
struct V_225 * V_226 )
{
struct V_9 * V_10 = F_76 ( V_224 -> V_227 ) ;
T_4 * V_140 = & V_10 -> V_141 ;
struct V_198 * V_199 = F_51 ( V_224 -> V_228 ) ;
T_2 V_229 , V_230 ;
T_11 V_231 ;
T_12 V_232 ;
V_226 -> V_233 = V_234 ;
V_226 -> V_235 = V_22 - 1 ;
V_230 = F_85 ( V_10 -> V_168 -> V_236 ) ;
V_226 -> V_237 . V_238 [ 0 ] = ( V_239 ) V_230 ;
V_226 -> V_237 . V_238 [ 1 ] = ( V_239 ) ( V_230 >> 32 ) ;
F_86 ( V_10 , V_240 ) ;
F_87 ( & V_10 -> V_241 ) ;
V_226 -> V_242 = V_140 -> V_179 ;
V_231 = V_140 -> V_243 ? V_140 -> V_244 : 0 ;
V_226 -> V_245 = V_140 -> V_150 - V_231 ;
V_226 -> V_246 = V_226 -> V_247 =
V_140 -> V_248 - F_88 ( V_10 ) ;
V_229 = V_226 -> V_246 << V_140 -> V_249 ;
V_226 -> V_250 =
F_89 ( V_140 -> V_251 + V_229 , ( T_2 ) V_252 ) ;
if ( V_10 -> V_148 )
V_226 -> V_250 = F_90 ( F_91 ( V_226 -> V_250 ) ,
V_226 -> V_250 ,
V_10 -> V_148 ) ;
V_232 = V_226 -> V_250 - ( V_140 -> V_251 - V_140 -> V_253 ) ;
V_226 -> V_254 = F_92 ( T_12 , V_232 , 0 ) ;
F_93 ( & V_10 -> V_241 ) ;
if ( ( V_199 -> V_255 . V_256 & V_257 ) &&
( ( V_10 -> V_82 & ( V_96 | V_98 ) ) ) ==
( V_96 | V_98 ) )
F_94 ( V_199 , V_226 ) ;
return 0 ;
}
STATIC void
F_95 ( struct V_9 * V_10 )
{
T_2 V_258 = 0 ;
V_10 -> V_259 = V_10 -> V_260 ;
F_96 ( V_10 , & V_258 , NULL ) ;
}
STATIC void
F_97 ( struct V_9 * V_10 )
{
T_2 V_258 ;
if ( V_10 -> V_259 ) {
V_258 = V_10 -> V_259 ;
V_10 -> V_259 = 0 ;
} else
V_258 = F_98 ( V_10 ) ;
F_96 ( V_10 , & V_258 , NULL ) ;
}
static void
F_99 (
struct V_9 * V_10 )
{
int error = 0 ;
while ( F_100 ( & V_10 -> V_261 ) > 0 )
F_101 ( 100 ) ;
F_82 ( V_10 , V_220 ) ;
F_102 ( V_10 , 0 ) ;
F_102 ( V_10 , V_262 ) ;
error = F_103 ( V_10 ) ;
if ( error )
F_6 ( V_10 , L_35
L_36 ) ;
F_104 ( F_100 ( & V_10 -> V_261 ) != 0 ) ;
F_105 ( V_10 ) ;
}
STATIC int
F_106 (
struct V_12 * V_13 ,
int * V_263 ,
char * V_11 )
{
struct V_9 * V_10 = F_76 ( V_13 ) ;
T_13 args [ V_264 ] ;
char * V_265 ;
int error ;
F_107 ( V_13 ) ;
while ( ( V_265 = F_5 ( & V_11 , L_1 ) ) != NULL ) {
int V_266 ;
if ( ! * V_265 )
continue;
V_266 = F_108 ( V_265 , V_267 , args ) ;
switch ( V_266 ) {
case V_268 :
V_10 -> V_28 |= V_34 ;
break;
case V_269 :
V_10 -> V_28 &= ~ V_34 ;
break;
case V_270 :
V_10 -> V_271 = F_24 ( V_10 ) ;
break;
case V_272 :
V_10 -> V_271 = F_18 ( V_10 ) ;
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
if ( ( V_10 -> V_28 & V_29 ) && ! ( * V_263 & V_27 ) ) {
V_10 -> V_28 &= ~ V_29 ;
if ( V_10 -> V_273 ) {
error = F_109 ( V_10 , V_10 -> V_273 ) ;
if ( error ) {
F_6 ( V_10 , L_37 ) ;
return error ;
}
V_10 -> V_273 = 0 ;
}
F_97 ( V_10 ) ;
F_110 ( V_10 ) ;
}
if ( ! ( V_10 -> V_28 & V_29 ) && ( * V_263 & V_27 ) ) {
F_95 ( V_10 ) ;
F_99 ( V_10 ) ;
V_10 -> V_28 |= V_29 ;
}
return 0 ;
}
STATIC int
F_111 (
struct V_12 * V_13 )
{
struct V_9 * V_10 = F_76 ( V_13 ) ;
F_95 ( V_10 ) ;
F_99 ( V_10 ) ;
return - F_112 ( V_10 ) ;
}
STATIC int
F_113 (
struct V_12 * V_13 )
{
struct V_9 * V_10 = F_76 ( V_13 ) ;
F_97 ( V_10 ) ;
F_110 ( V_10 ) ;
return 0 ;
}
STATIC int
F_114 (
struct V_122 * V_123 ,
struct V_224 * V_274 )
{
return - F_12 ( F_76 ( V_274 -> V_227 ) , V_123 ) ;
}
STATIC int
F_115 (
struct V_9 * V_10 )
{
int V_275 = ( V_10 -> V_28 & V_29 ) ;
if ( F_116 ( & V_10 -> V_141 ) ) {
if ( V_10 -> V_39 <= 0 &&
V_10 -> V_141 . V_276 > V_277 ) {
V_10 -> V_39 = V_10 -> V_141 . V_276 ;
} else if ( V_10 -> V_39 > 0 &&
V_10 -> V_39 < V_10 -> V_141 . V_276 ) {
F_6 ( V_10 ,
L_38 ) ;
return F_10 ( V_8 ) ;
}
} else {
if ( V_10 -> V_39 > V_277 ) {
F_6 ( V_10 ,
L_39 ) ;
return F_10 ( V_8 ) ;
}
}
if ( F_117 ( & V_10 -> V_141 ) &&
( V_10 -> V_28 & V_78 ) ) {
F_6 ( V_10 ,
L_40 ,
V_77 , V_75 ) ;
return F_10 ( V_8 ) ;
}
if ( F_118 ( & V_10 -> V_141 ) &&
! ( V_10 -> V_28 & V_78 ) )
V_10 -> V_28 |= V_76 ;
if ( ( V_10 -> V_141 . V_278 & V_279 ) && ! V_275 ) {
F_6 ( V_10 ,
L_41 ) ;
return F_10 ( V_280 ) ;
}
if ( ( V_10 -> V_82 & ( V_102 | V_103 ) ) &&
( V_10 -> V_82 & ( V_96 | V_97 ) ) &&
! F_119 ( & V_10 -> V_141 ) ) {
F_6 ( V_10 ,
L_42 ) ;
return F_10 ( V_8 ) ;
}
return 0 ;
}
STATIC int
F_120 (
struct V_12 * V_13 ,
void * V_281 ,
int V_282 )
{
struct V_197 * V_274 ;
struct V_9 * V_10 = NULL ;
int V_263 = 0 , error = V_24 ;
V_10 = F_121 ( sizeof( struct V_9 ) , V_23 ) ;
if ( ! V_10 )
goto V_174;
F_62 ( & V_10 -> V_241 ) ;
F_122 ( & V_10 -> V_283 ) ;
F_61 ( & V_10 -> V_261 , 0 ) ;
F_123 ( & V_10 -> V_284 , V_285 ) ;
F_123 ( & V_10 -> V_286 , V_287 ) ;
V_10 -> V_14 = V_13 ;
V_13 -> V_288 = V_10 ;
error = F_3 ( V_10 , ( char * ) V_281 ) ;
if ( error )
goto V_289;
F_124 ( V_13 , V_182 ) ;
V_13 -> V_290 = V_291 ;
V_13 -> V_292 = & V_293 ;
#ifdef F_8
V_13 -> V_294 = & V_295 ;
#endif
V_13 -> V_296 = & V_297 ;
if ( V_282 )
V_263 |= V_298 ;
error = F_35 ( V_10 ) ;
if ( error )
goto V_289;
error = - F_40 ( V_10 ) ;
if ( error )
goto V_299;
error = - F_125 ( V_10 ) ;
if ( error )
goto V_300;
error = F_126 ( V_10 , V_263 ) ;
if ( error )
goto V_301;
error = F_115 ( V_10 ) ;
if ( error )
goto V_302;
error = F_37 ( V_10 ) ;
if ( error )
goto V_302;
error = F_127 ( V_10 ) ;
if ( error )
goto V_302;
V_13 -> V_303 = V_234 ;
V_13 -> V_304 = V_10 -> V_141 . V_179 ;
V_13 -> V_305 = F_7 ( V_13 -> V_304 ) - 1 ;
V_13 -> V_306 = F_16 ( V_13 -> V_305 ) ;
V_13 -> V_307 = V_308 ;
V_13 -> V_309 = 1 ;
F_128 ( V_13 ) ;
if ( F_129 ( & V_10 -> V_141 ) == V_310 )
V_13 -> V_26 |= V_311 ;
error = F_130 ( V_10 ) ;
if ( error )
goto V_312;
V_274 = F_131 ( F_60 ( V_10 -> V_313 ) ) ;
if ( ! V_274 ) {
error = V_314 ;
goto V_315;
}
V_13 -> V_316 = F_132 ( V_274 ) ;
if ( ! V_13 -> V_316 ) {
error = V_24 ;
goto V_315;
}
return 0 ;
V_312:
F_77 ( V_10 ) ;
V_302:
F_79 ( V_10 ) ;
V_301:
F_80 ( V_10 ) ;
V_300:
F_43 ( V_10 ) ;
V_299:
F_33 ( V_10 ) ;
V_289:
F_73 ( V_10 ) ;
F_74 ( V_10 ) ;
V_174:
return - error ;
V_315:
F_77 ( V_10 ) ;
F_78 ( V_10 ) ;
goto V_302;
}
STATIC struct V_224 *
F_133 (
struct V_317 * V_318 ,
int V_263 ,
const char * V_319 ,
void * V_281 )
{
return F_134 ( V_318 , V_263 , V_319 , V_281 , F_120 ) ;
}
static long
F_135 (
struct V_12 * V_13 ,
int V_320 )
{
return F_136 ( F_76 ( V_13 ) ) ;
}
static long
F_137 (
struct V_12 * V_13 ,
long V_321 ,
int V_320 )
{
return F_138 ( F_76 ( V_13 ) , V_321 ) ;
}
STATIC int T_14
F_139 ( void )
{
V_322 = F_140 ( sizeof( V_323 ) , L_43 ) ;
if ( ! V_322 )
goto V_174;
V_324 = F_141 ( 4 * V_325 ,
V_322 ) ;
if ( ! V_324 )
goto V_326;
V_327 = F_140 ( sizeof( V_328 ) ,
L_44 ) ;
if ( ! V_327 )
goto V_329;
V_330 = F_140 ( sizeof( V_331 ) ,
L_45 ) ;
if ( ! V_330 )
goto V_332;
V_333 = F_140 ( sizeof( V_334 ) ,
L_46 ) ;
if ( ! V_333 )
goto V_335;
V_336 = F_140 ( sizeof( V_337 ) ,
L_47 ) ;
if ( ! V_336 )
goto V_338;
V_339 = F_140 ( sizeof( V_340 ) , L_48 ) ;
if ( ! V_339 )
goto V_341;
V_342 = F_140 ( sizeof( V_343 ) , L_49 ) ;
if ( ! V_342 )
goto V_344;
V_345 =
F_140 ( sizeof( struct V_346 ) ,
L_50 ) ;
if ( ! V_345 )
goto V_347;
V_348 = F_140 ( sizeof( struct V_349 ) ,
L_51 ) ;
if ( ! V_348 )
goto V_350;
V_351 = F_140 ( ( sizeof( V_352 ) +
( ( V_353 - 1 ) *
sizeof( V_354 ) ) ) , L_52 ) ;
if ( ! V_351 )
goto V_355;
V_356 = F_140 ( ( sizeof( V_357 ) +
( ( V_358 - 1 ) *
sizeof( V_354 ) ) ) , L_53 ) ;
if ( ! V_356 )
goto V_359;
V_360 =
F_142 ( sizeof( T_10 ) , L_54 ,
V_361 | V_362 | V_363 ,
F_58 ) ;
if ( ! V_360 )
goto V_364;
V_365 =
F_142 ( sizeof( V_366 ) , L_55 ,
V_363 , NULL ) ;
if ( ! V_365 )
goto V_367;
V_368 = F_140 ( sizeof( struct V_369 ) ,
L_56 ) ;
if ( ! V_368 )
goto V_370;
return 0 ;
V_370:
F_143 ( V_365 ) ;
V_367:
F_143 ( V_360 ) ;
V_364:
F_143 ( V_356 ) ;
V_359:
F_143 ( V_351 ) ;
V_355:
F_143 ( V_348 ) ;
V_350:
F_143 ( V_345 ) ;
V_347:
F_143 ( V_342 ) ;
V_344:
F_143 ( V_339 ) ;
V_341:
F_143 ( V_336 ) ;
V_338:
F_143 ( V_333 ) ;
V_335:
F_143 ( V_330 ) ;
V_332:
F_143 ( V_327 ) ;
V_329:
F_144 ( V_324 ) ;
V_326:
F_143 ( V_322 ) ;
V_174:
return - V_24 ;
}
STATIC void
F_145 ( void )
{
F_146 () ;
F_143 ( V_368 ) ;
F_143 ( V_365 ) ;
F_143 ( V_360 ) ;
F_143 ( V_356 ) ;
F_143 ( V_351 ) ;
F_143 ( V_348 ) ;
F_143 ( V_345 ) ;
F_143 ( V_342 ) ;
F_143 ( V_339 ) ;
F_143 ( V_336 ) ;
F_143 ( V_333 ) ;
F_143 ( V_330 ) ;
F_143 ( V_327 ) ;
F_144 ( V_324 ) ;
F_143 ( V_322 ) ;
}
STATIC int T_14
F_147 ( void )
{
V_371 = F_41 ( L_57 , V_185 , 0 ) ;
if ( ! V_371 )
return - V_24 ;
return 0 ;
}
STATIC void
F_148 ( void )
{
F_42 ( V_371 ) ;
}
STATIC int T_14
F_149 ( void )
{
int error ;
F_150 (KERN_INFO XFS_VERSION_STRING L_58
XFS_BUILD_OPTIONS L_59 ) ;
F_151 () ;
error = F_139 () ;
if ( error )
goto V_174;
error = F_147 () ;
if ( error )
goto V_372;
error = F_152 () ;
if ( error )
goto V_373;
error = F_153 () ;
if ( error )
goto V_374;
error = F_154 () ;
if ( error )
goto V_375;
error = F_155 () ;
if ( error )
goto V_376;
error = F_156 () ;
if ( error )
goto V_377;
error = F_157 () ;
if ( error )
goto V_378;
error = F_158 ( & V_379 ) ;
if ( error )
goto V_380;
return 0 ;
V_380:
F_159 () ;
V_378:
F_160 () ;
V_377:
F_161 () ;
V_376:
F_162 () ;
V_375:
F_163 () ;
V_374:
F_164 () ;
V_373:
F_148 () ;
V_372:
F_145 () ;
V_174:
return error ;
}
STATIC void T_15
F_165 ( void )
{
F_159 () ;
F_166 ( & V_379 ) ;
F_160 () ;
F_161 () ;
F_162 () ;
F_163 () ;
F_164 () ;
F_148 () ;
F_145 () ;
}
