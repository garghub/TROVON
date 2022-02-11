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
V_8 -> V_27 |= V_36 ;
V_8 -> V_37 = - 1 ;
V_8 -> V_38 = - 1 ;
if ( ! V_9 )
goto V_39;
while ( ( V_13 = F_5 ( & V_9 , L_1 ) ) != NULL ) {
if ( ! * V_13 )
continue;
if ( ( V_6 = strchr ( V_13 , '=' ) ) != NULL )
* V_6 ++ = 0 ;
if ( ! strcmp ( V_13 , V_40 ) ) {
if ( ! V_6 || ! * V_6 ) {
F_6 ( V_8 , L_2 ,
V_13 ) ;
return V_41 ;
}
V_8 -> V_37 = F_2 ( V_6 , & V_14 , 10 ) ;
} else if ( ! strcmp ( V_13 , V_42 ) ) {
if ( ! V_6 || ! * V_6 ) {
F_6 ( V_8 , L_2 ,
V_13 ) ;
return V_41 ;
}
V_8 -> V_38 = F_1 ( V_6 , & V_14 , 10 ) ;
} else if ( ! strcmp ( V_13 , V_43 ) ) {
if ( ! V_6 || ! * V_6 ) {
F_6 ( V_8 , L_2 ,
V_13 ) ;
return V_41 ;
}
V_8 -> V_44 = F_4 ( V_6 , V_21 , V_22 ) ;
if ( ! V_8 -> V_44 )
return V_23 ;
} else if ( ! strcmp ( V_13 , V_45 ) ) {
F_6 ( V_8 , L_3 ,
V_13 ) ;
return V_41 ;
} else if ( ! strcmp ( V_13 , V_46 ) ) {
if ( ! V_6 || ! * V_6 ) {
F_6 ( V_8 , L_2 ,
V_13 ) ;
return V_41 ;
}
V_8 -> V_47 = F_4 ( V_6 , V_21 , V_22 ) ;
if ( ! V_8 -> V_47 )
return V_23 ;
} else if ( ! strcmp ( V_13 , V_48 ) ) {
if ( ! V_6 || ! * V_6 ) {
F_6 ( V_8 , L_2 ,
V_13 ) ;
return V_41 ;
}
V_17 = F_2 ( V_6 , & V_14 , 10 ) ;
V_18 = F_7 ( V_17 ) - 1 ;
} else if ( ! strcmp ( V_13 , V_49 ) ) {
if ( ! V_6 || ! * V_6 ) {
F_6 ( V_8 , L_2 ,
V_13 ) ;
return V_41 ;
}
V_17 = F_1 ( V_6 , & V_14 , 10 ) ;
V_18 = F_7 ( V_17 ) - 1 ;
} else if ( ! strcmp ( V_13 , V_50 ) ||
! strcmp ( V_13 , V_51 ) ) {
V_8 -> V_27 |= V_52 ;
} else if ( ! strcmp ( V_13 , V_53 ) ||
! strcmp ( V_13 , V_54 ) ) {
V_8 -> V_27 &= ~ V_52 ;
} else if ( ! strcmp ( V_13 , V_55 ) ) {
V_8 -> V_27 |= V_32 ;
} else if ( ! strcmp ( V_13 , V_56 ) ) {
V_8 -> V_27 |= V_57 ;
} else if ( ! strcmp ( V_13 , V_58 ) ) {
V_8 -> V_27 |= V_59 ;
} else if ( ! strcmp ( V_13 , V_60 ) ) {
V_8 -> V_27 |= V_61 ;
} else if ( ! strcmp ( V_13 , V_62 ) ) {
if ( ! V_6 || ! * V_6 ) {
F_6 ( V_8 , L_2 ,
V_13 ) ;
return V_41 ;
}
V_15 = F_2 ( V_6 , & V_14 , 10 ) ;
} else if ( ! strcmp ( V_13 , V_63 ) ) {
if ( ! V_6 || ! * V_6 ) {
F_6 ( V_8 , L_2 ,
V_13 ) ;
return V_41 ;
}
V_16 = F_2 ( V_6 , & V_14 , 10 ) ;
} else if ( ! strcmp ( V_13 , V_64 ) ) {
V_8 -> V_27 &= ~ V_35 ;
#if ! V_65
F_6 ( V_8 , L_3 ,
V_13 ) ;
return V_41 ;
#endif
} else if ( ! strcmp ( V_13 , V_66 ) ) {
V_8 -> V_27 |= V_67 ;
} else if ( ! strcmp ( V_13 , V_68 ) ) {
V_8 -> V_27 |= V_33 ;
} else if ( ! strcmp ( V_13 , V_69 ) ) {
V_8 -> V_27 &= ~ V_33 ;
} else if ( ! strcmp ( V_13 , V_70 ) ) {
V_8 -> V_27 |= V_71 ;
} else if ( ! strcmp ( V_13 , V_72 ) ) {
V_8 -> V_27 &= ~ V_71 ;
} else if ( ! strcmp ( V_13 , V_73 ) ) {
V_8 -> V_27 &= ~ V_34 ;
} else if ( ! strcmp ( V_13 , V_74 ) ) {
V_8 -> V_27 |= V_34 ;
} else if ( ! strcmp ( V_13 , V_75 ) ) {
V_8 -> V_27 |= V_76 ;
} else if ( ! strcmp ( V_13 , V_77 ) ) {
V_8 -> V_27 &= ~ V_76 ;
V_8 -> V_27 |= V_78 ;
} else if ( ! strcmp ( V_13 , V_79 ) ) {
V_8 -> V_27 |= V_80 ;
} else if ( ! strcmp ( V_13 , V_81 ) ) {
V_8 -> V_82 &= ~ ( V_83 | V_84 |
V_85 | V_86 |
V_87 | V_88 |
V_89 | V_90 ) ;
} else if ( ! strcmp ( V_13 , V_91 ) ||
! strcmp ( V_13 , V_92 ) ||
! strcmp ( V_13 , V_93 ) ) {
V_8 -> V_82 |= ( V_83 | V_84 |
V_89 ) ;
} else if ( ! strcmp ( V_13 , V_94 ) ||
! strcmp ( V_13 , V_95 ) ) {
V_8 -> V_82 |= ( V_83 | V_84 ) ;
V_8 -> V_82 &= ~ V_89 ;
} else if ( ! strcmp ( V_13 , V_96 ) ||
! strcmp ( V_13 , V_97 ) ) {
V_8 -> V_82 |= ( V_87 | V_88 |
V_90 ) ;
} else if ( ! strcmp ( V_13 , V_98 ) ) {
V_8 -> V_82 |= ( V_87 | V_88 ) ;
V_8 -> V_82 &= ~ V_90 ;
} else if ( ! strcmp ( V_13 , V_99 ) ||
! strcmp ( V_13 , V_100 ) ) {
V_8 -> V_82 |= ( V_85 | V_86 |
V_90 ) ;
} else if ( ! strcmp ( V_13 , V_101 ) ) {
V_8 -> V_82 |= ( V_85 | V_86 ) ;
V_8 -> V_82 &= ~ V_90 ;
} else if ( ! strcmp ( V_13 , V_102 ) ) {
V_8 -> V_27 |= V_36 ;
} else if ( ! strcmp ( V_13 , V_103 ) ) {
V_8 -> V_27 &= ~ V_36 ;
F_6 ( V_8 ,
L_4 ) ;
} else if ( ! strcmp ( V_13 , V_104 ) ) {
V_8 -> V_27 |= V_105 ;
} else if ( ! strcmp ( V_13 , V_106 ) ) {
V_8 -> V_27 &= ~ V_105 ;
} else if ( ! strcmp ( V_13 , L_5 ) ) {
F_6 ( V_8 ,
L_6 ) ;
} else if ( ! strcmp ( V_13 , L_7 ) ) {
F_6 ( V_8 ,
L_8 ) ;
} else if ( ! strcmp ( V_13 , L_9 ) ) {
F_6 ( V_8 ,
L_10 ) ;
} else if ( ! strcmp ( V_13 , L_11 ) ) {
F_6 ( V_8 ,
L_12 ) ;
} else {
F_6 ( V_8 , L_13 , V_13 ) ;
return V_41 ;
}
}
if ( ( V_8 -> V_27 & V_57 ) &&
! ( V_8 -> V_27 & V_28 ) ) {
F_6 ( V_8 , L_14 ) ;
return V_41 ;
}
if ( ( V_8 -> V_27 & V_59 ) && ( V_15 || V_16 ) ) {
F_6 ( V_8 ,
L_15 ) ;
return V_41 ;
}
if ( ( V_8 -> V_27 & V_105 ) &&
! ( V_8 -> V_27 & V_36 ) ) {
F_6 ( V_8 ,
L_16 ) ;
return V_41 ;
}
#ifndef F_8
if ( F_9 ( V_8 ) ) {
F_6 ( V_8 , L_17 ) ;
return V_41 ;
}
#endif
if ( ( V_8 -> V_82 & ( V_85 | V_86 ) ) &&
( V_8 -> V_82 & ( V_87 | V_88 ) ) ) {
F_6 ( V_8 , L_18 ) ;
return V_41 ;
}
if ( ( V_15 && ! V_16 ) || ( ! V_15 && V_16 ) ) {
F_6 ( V_8 , L_19 ) ;
return V_41 ;
}
if ( V_15 && ( V_16 % V_15 != 0 ) ) {
F_6 ( V_8 ,
L_20 ,
V_16 , V_15 ) ;
return V_41 ;
}
V_39:
if ( ! ( V_8 -> V_27 & V_59 ) ) {
if ( V_15 ) {
V_8 -> V_107 = V_15 ;
V_8 -> V_27 |= V_108 ;
}
if ( V_16 )
V_8 -> V_109 = V_16 ;
}
if ( V_8 -> V_37 != - 1 &&
V_8 -> V_37 != 0 &&
( V_8 -> V_37 < V_110 ||
V_8 -> V_37 > V_111 ) ) {
F_6 ( V_8 , L_21 ,
V_8 -> V_37 , V_110 , V_111 ) ;
return F_10 ( V_41 ) ;
}
if ( V_8 -> V_38 != - 1 &&
V_8 -> V_38 != 0 &&
( V_8 -> V_38 < V_112 ||
V_8 -> V_38 > V_113 ||
! F_11 ( V_8 -> V_38 ) ) ) {
F_6 ( V_8 ,
L_22 ,
V_8 -> V_38 ) ;
return F_10 ( V_41 ) ;
}
if ( V_18 ) {
if ( V_18 > V_114 ||
V_18 < V_115 ) {
F_6 ( V_8 , L_23 ,
V_18 , V_115 ,
V_114 ) ;
return F_10 ( V_41 ) ;
}
V_8 -> V_27 |= V_116 ;
V_8 -> V_117 = V_18 ;
V_8 -> V_118 = V_18 ;
}
return 0 ;
}
STATIC int
F_12 (
struct V_7 * V_8 ,
struct V_119 * V_120 )
{
static struct V_121 V_122 [] = {
{ V_71 , L_1 V_70 } ,
{ V_32 , L_1 V_55 } ,
{ V_59 , L_1 V_58 } ,
{ V_61 , L_1 V_60 } ,
{ V_67 , L_1 V_66 } ,
{ V_57 , L_1 V_56 } ,
{ V_76 , L_1 V_75 } ,
{ V_80 , L_1 V_79 } ,
{ V_52 , L_1 V_50 } ,
{ V_36 , L_1 V_102 } ,
{ V_105 , L_1 V_104 } ,
{ 0 , NULL }
} ;
static struct V_121 V_123 [] = {
{ V_34 , L_1 V_73 } ,
{ V_33 , L_1 V_69 } ,
{ V_35 , L_1 V_64 } ,
{ 0 , NULL }
} ;
struct V_121 * V_124 ;
for ( V_124 = V_122 ; V_124 -> V_125 ; V_124 ++ ) {
if ( V_8 -> V_27 & V_124 -> V_125 )
F_13 ( V_120 , V_124 -> V_126 ) ;
}
for ( V_124 = V_123 ; V_124 -> V_125 ; V_124 ++ ) {
if ( ! ( V_8 -> V_27 & V_124 -> V_125 ) )
F_13 ( V_120 , V_124 -> V_126 ) ;
}
if ( V_8 -> V_27 & V_116 )
F_14 ( V_120 , L_1 V_49 L_24 ,
( int ) ( 1 << V_8 -> V_118 ) >> 10 ) ;
if ( V_8 -> V_37 > 0 )
F_14 ( V_120 , L_1 V_40 L_25 , V_8 -> V_37 ) ;
if ( V_8 -> V_38 > 0 )
F_14 ( V_120 , L_1 V_42 L_24 , V_8 -> V_38 >> 10 ) ;
if ( V_8 -> V_44 )
F_14 ( V_120 , L_1 V_43 L_26 , V_8 -> V_44 ) ;
if ( V_8 -> V_47 )
F_14 ( V_120 , L_1 V_46 L_26 , V_8 -> V_47 ) ;
if ( V_8 -> V_107 > 0 )
F_14 ( V_120 , L_1 V_62 L_25 ,
( int ) F_15 ( V_8 , V_8 -> V_107 ) ) ;
if ( V_8 -> V_109 > 0 )
F_14 ( V_120 , L_1 V_63 L_25 ,
( int ) F_15 ( V_8 , V_8 -> V_109 ) ) ;
if ( V_8 -> V_82 & ( V_83 | V_89 ) )
F_13 ( V_120 , L_1 V_93 ) ;
else if ( V_8 -> V_82 & V_83 )
F_13 ( V_120 , L_1 V_95 ) ;
if ( V_8 -> V_82 & V_87 ) {
if ( V_8 -> V_82 & V_90 )
F_13 ( V_120 , L_1 V_97 ) ;
else
F_13 ( V_120 , L_1 V_98 ) ;
} else if ( V_8 -> V_82 & V_85 ) {
if ( V_8 -> V_82 & V_90 )
F_13 ( V_120 , L_1 V_100 ) ;
else
F_13 ( V_120 , L_1 V_101 ) ;
}
if ( ! ( V_8 -> V_82 & V_127 ) )
F_13 ( V_120 , L_1 V_81 ) ;
return 0 ;
}
T_2
F_16 (
unsigned int V_128 )
{
unsigned int V_129 = 1 ;
unsigned int V_130 = V_131 - 1 ;
#if V_131 == 32
# if F_17 ( V_132 )
ASSERT ( sizeof( V_133 ) == 8 ) ;
V_129 = V_134 ;
V_130 = V_131 ;
# else
V_129 = V_134 >> ( V_135 - V_128 ) ;
# endif
#endif
return ( ( ( T_2 ) V_129 ) << V_130 ) - 1 ;
}
STATIC int
F_18 (
T_3 * V_8 ,
const char * V_136 ,
struct V_137 * * V_138 )
{
int error = 0 ;
* V_138 = F_19 ( V_136 , V_139 | V_140 | V_141 ,
V_8 ) ;
if ( F_20 ( * V_138 ) ) {
error = F_21 ( * V_138 ) ;
F_6 ( V_8 , L_27 , V_136 , error ) ;
}
return - error ;
}
STATIC void
F_22 (
struct V_137 * V_142 )
{
if ( V_142 )
F_23 ( V_142 , V_139 | V_140 | V_141 ) ;
}
void
F_24 (
T_4 * V_143 )
{
F_25 ( V_143 -> V_144 , V_22 , NULL ) ;
}
STATIC void
F_26 (
struct V_7 * V_8 )
{
if ( V_8 -> V_145 && V_8 -> V_145 != V_8 -> V_146 ) {
struct V_137 * V_147 = V_8 -> V_145 -> V_144 ;
F_27 ( V_8 , V_8 -> V_145 ) ;
F_22 ( V_147 ) ;
}
if ( V_8 -> V_148 ) {
struct V_137 * V_149 = V_8 -> V_148 -> V_144 ;
F_27 ( V_8 , V_8 -> V_148 ) ;
F_22 ( V_149 ) ;
}
F_27 ( V_8 , V_8 -> V_146 ) ;
}
STATIC int
F_28 (
struct V_7 * V_8 )
{
struct V_137 * V_150 = V_8 -> V_12 -> V_151 ;
struct V_137 * V_147 = NULL , * V_149 = NULL ;
int error ;
if ( V_8 -> V_44 ) {
error = F_18 ( V_8 , V_8 -> V_44 , & V_147 ) ;
if ( error )
goto V_152;
}
if ( V_8 -> V_47 ) {
error = F_18 ( V_8 , V_8 -> V_47 , & V_149 ) ;
if ( error )
goto V_153;
if ( V_149 == V_150 || V_149 == V_147 ) {
F_6 ( V_8 ,
L_28 ) ;
error = V_41 ;
goto V_154;
}
}
error = V_23 ;
V_8 -> V_146 = F_29 ( V_8 , V_150 , 0 , V_8 -> V_19 ) ;
if ( ! V_8 -> V_146 )
goto V_154;
if ( V_149 ) {
V_8 -> V_148 = F_29 ( V_8 , V_149 , 1 ,
V_8 -> V_19 ) ;
if ( ! V_8 -> V_148 )
goto V_155;
}
if ( V_147 && V_147 != V_150 ) {
V_8 -> V_145 = F_29 ( V_8 , V_147 , 1 ,
V_8 -> V_19 ) ;
if ( ! V_8 -> V_145 )
goto V_156;
} else {
V_8 -> V_145 = V_8 -> V_146 ;
}
return 0 ;
V_156:
if ( V_8 -> V_148 )
F_27 ( V_8 , V_8 -> V_148 ) ;
V_155:
F_27 ( V_8 , V_8 -> V_146 ) ;
V_154:
if ( V_149 )
F_22 ( V_149 ) ;
V_153:
if ( V_147 && V_147 != V_150 )
F_22 ( V_147 ) ;
V_152:
return error ;
}
STATIC int
F_30 (
struct V_7 * V_8 )
{
int error ;
error = F_31 ( V_8 -> V_146 , V_8 -> V_157 . V_158 ,
V_8 -> V_157 . V_159 ) ;
if ( error )
return error ;
if ( V_8 -> V_145 && V_8 -> V_145 != V_8 -> V_146 ) {
unsigned int V_160 = V_161 ;
if ( F_32 ( & V_8 -> V_157 ) )
V_160 = V_8 -> V_157 . V_162 ;
error = F_31 ( V_8 -> V_145 ,
V_8 -> V_157 . V_158 ,
V_160 ) ;
if ( error )
return error ;
}
if ( V_8 -> V_148 ) {
error = F_31 ( V_8 -> V_148 ,
V_8 -> V_157 . V_158 ,
V_8 -> V_157 . V_159 ) ;
if ( error )
return error ;
}
return 0 ;
}
STATIC struct V_163 *
F_33 (
struct V_10 * V_11 )
{
F_34 () ;
return NULL ;
}
STATIC void
F_35 (
struct V_163 * V_163 )
{
struct V_164 * V_165 = F_36 ( V_163 ) ;
F_37 ( V_165 ) ;
F_38 ( V_166 ) ;
if ( F_39 ( V_163 ) )
goto V_167;
ASSERT ( F_40 ( V_165 -> V_168 ) || V_165 -> V_169 == 0 ) ;
F_41 ( ! F_42 ( V_165 , V_170 ) ) ;
F_41 ( ! F_42 ( V_165 , V_171 ) ) ;
V_167:
F_43 ( V_165 ) ;
}
STATIC void
F_44 (
void * V_163 )
{
struct V_164 * V_165 = V_163 ;
memset ( V_165 , 0 , sizeof( struct V_164 ) ) ;
F_45 ( F_46 ( V_165 ) ) ;
F_47 ( & V_165 -> V_172 , 0 ) ;
F_48 ( & V_165 -> V_173 ) ;
F_49 ( & V_165 -> V_174 ) ;
F_50 ( & V_165 -> V_175 ) ;
F_51 ( & V_165 -> V_175 ) ;
F_52 ( & V_165 -> V_176 , V_177 | V_178 ,
L_29 , V_165 -> V_179 ) ;
}
STATIC void
F_53 (
struct V_163 * V_163 ,
int V_180 )
{
F_54 () ;
F_36 ( V_163 ) -> V_181 = 1 ;
}
STATIC int
F_55 (
struct V_163 * V_163 ,
struct V_182 * V_183 )
{
struct V_164 * V_165 = F_36 ( V_163 ) ;
struct V_7 * V_8 = V_165 -> V_168 ;
int error = V_184 ;
F_56 ( V_165 ) ;
if ( F_40 ( V_8 ) )
return - F_10 ( V_185 ) ;
if ( V_183 -> V_186 == V_187 || V_183 -> V_188 ) {
error = F_57 ( V_165 , NULL , 0 ) ;
if ( error )
goto V_152;
return 0 ;
} else {
if ( ! V_165 -> V_181 )
return 0 ;
if ( ! F_58 ( V_165 , V_189 ) )
goto V_152;
if ( F_59 ( V_165 ) || ! F_60 ( V_165 ) )
goto V_190;
if ( F_61 ( V_165 ) ) {
F_62 ( V_165 ) ;
error = 0 ;
goto V_190;
}
error = F_63 ( V_165 , V_191 ) ;
}
V_190:
F_64 ( V_165 , V_189 ) ;
V_152:
if ( error )
F_65 ( V_165 ) ;
return - error ;
}
STATIC void
F_66 (
struct V_163 * V_163 )
{
T_5 * V_165 = F_36 ( V_163 ) ;
F_67 ( V_165 ) ;
F_68 ( & V_163 -> V_192 , 0 ) ;
F_69 ( V_163 ) ;
F_38 ( V_193 ) ;
F_38 ( V_194 ) ;
F_70 ( V_195 ) ;
ASSERT ( ! F_71 ( & V_165 -> V_196 . V_197 ) ) ;
F_52 ( & V_165 -> V_196 , V_178 , L_30 , V_165 -> V_179 ) ;
F_72 ( & V_165 -> V_196 . V_197 ,
& V_198 , L_31 ) ;
F_73 ( V_165 ) ;
}
STATIC void
F_74 (
struct V_7 * V_8 )
{
F_75 ( V_8 -> V_19 ) ;
F_75 ( V_8 -> V_47 ) ;
F_75 ( V_8 -> V_44 ) ;
}
STATIC void
F_76 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_77 ( V_11 ) ;
F_78 ( V_8 ) ;
F_79 ( V_8 ) ;
F_80 ( V_8 -> V_146 , 1 ) ;
F_81 ( V_8 ) ;
F_82 ( V_8 ) ;
F_83 ( V_8 ) ;
F_26 ( V_8 ) ;
F_74 ( V_8 ) ;
F_75 ( V_8 ) ;
}
STATIC int
F_84 (
struct V_10 * V_11 ,
int V_199 )
{
struct V_7 * V_8 = F_77 ( V_11 ) ;
int error ;
if ( ! V_199 ) {
F_85 ( V_8 , V_191 ) ;
return 0 ;
}
error = F_86 ( V_8 ) ;
if ( error )
return - error ;
if ( V_200 ) {
F_87 ( & V_8 -> V_201 ) ;
}
return 0 ;
}
STATIC int
F_88 (
struct V_202 * V_202 ,
struct V_203 * V_204 )
{
struct V_7 * V_8 = F_77 ( V_202 -> V_205 ) ;
T_6 * V_206 = & V_8 -> V_157 ;
struct V_164 * V_165 = F_36 ( V_202 -> V_207 ) ;
T_2 V_208 , V_209 ;
T_7 V_210 ;
T_8 V_211 ;
V_204 -> V_212 = V_213 ;
V_204 -> V_214 = V_21 - 1 ;
V_209 = F_89 ( V_8 -> V_146 -> V_215 ) ;
V_204 -> V_216 . V_217 [ 0 ] = ( V_218 ) V_209 ;
V_204 -> V_216 . V_217 [ 1 ] = ( V_218 ) ( V_209 >> 32 ) ;
F_90 ( V_8 , V_219 ) ;
F_91 ( & V_8 -> V_220 ) ;
V_204 -> V_221 = V_206 -> V_158 ;
V_210 = V_206 -> V_222 ? V_206 -> V_223 : 0 ;
V_204 -> V_224 = V_206 -> V_225 - V_210 ;
V_204 -> V_226 = V_204 -> V_227 =
V_206 -> V_228 - F_92 ( V_8 ) ;
V_208 = V_204 -> V_226 << V_206 -> V_229 ;
V_204 -> V_230 =
F_93 ( V_206 -> V_231 + V_208 , ( T_2 ) V_232 ) ;
if ( V_8 -> V_233 )
V_204 -> V_230 = F_94 ( F_95 ( V_204 -> V_230 ) ,
V_204 -> V_230 ,
V_8 -> V_233 ) ;
V_211 = V_204 -> V_230 - ( V_206 -> V_231 - V_206 -> V_234 ) ;
V_204 -> V_235 = F_96 ( T_8 , V_211 , 0 ) ;
F_97 ( & V_8 -> V_220 ) ;
if ( ( V_165 -> V_236 . V_237 & V_238 ) ||
( ( V_8 -> V_82 & ( V_87 | V_90 ) ) ) ==
( V_87 | V_90 ) )
F_98 ( V_165 , V_204 ) ;
return 0 ;
}
STATIC void
F_99 ( struct V_7 * V_8 )
{
T_2 V_239 = 0 ;
V_8 -> V_240 = V_8 -> V_241 ;
F_100 ( V_8 , & V_239 , NULL ) ;
}
STATIC void
F_101 ( struct V_7 * V_8 )
{
T_2 V_239 ;
if ( V_8 -> V_240 ) {
V_239 = V_8 -> V_240 ;
V_8 -> V_240 = 0 ;
} else
V_239 = F_102 ( V_8 ) ;
F_100 ( V_8 , & V_239 , NULL ) ;
}
STATIC int
F_103 (
struct V_10 * V_11 ,
int * V_180 ,
char * V_9 )
{
struct V_7 * V_8 = F_77 ( V_11 ) ;
T_9 args [ V_242 ] ;
char * V_243 ;
int error ;
while ( ( V_243 = F_5 ( & V_9 , L_1 ) ) != NULL ) {
int V_244 ;
if ( ! * V_243 )
continue;
V_244 = F_104 ( V_243 , V_245 , args ) ;
switch ( V_244 ) {
case V_246 :
V_8 -> V_27 |= V_33 ;
break;
case V_247 :
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
if ( ( V_8 -> V_27 & V_28 ) && ! ( * V_180 & V_26 ) ) {
V_8 -> V_27 &= ~ V_28 ;
if ( V_8 -> V_248 ) {
error = F_105 ( V_8 , V_8 -> V_248 ) ;
if ( error ) {
F_6 ( V_8 , L_32 ) ;
return error ;
}
V_8 -> V_248 = 0 ;
}
F_101 ( V_8 ) ;
}
if ( ! ( V_8 -> V_27 & V_28 ) && ( * V_180 & V_26 ) ) {
F_86 ( V_8 ) ;
F_99 ( V_8 ) ;
F_106 ( V_8 ) ;
V_8 -> V_27 |= V_28 ;
}
return 0 ;
}
STATIC int
F_107 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_77 ( V_11 ) ;
F_99 ( V_8 ) ;
F_106 ( V_8 ) ;
return - F_108 ( V_8 ) ;
}
STATIC int
F_109 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_77 ( V_11 ) ;
F_101 ( V_8 ) ;
return 0 ;
}
STATIC int
F_110 (
struct V_119 * V_120 ,
struct V_249 * V_250 )
{
return - F_12 ( F_77 ( V_250 -> V_251 ) , V_120 ) ;
}
STATIC int
F_111 (
struct V_7 * V_8 )
{
int V_252 = ( V_8 -> V_27 & V_28 ) ;
if ( F_112 ( & V_8 -> V_157 ) ) {
if ( V_8 -> V_38 <= 0 &&
V_8 -> V_157 . V_253 > V_254 ) {
V_8 -> V_38 = V_8 -> V_157 . V_253 ;
} else if ( V_8 -> V_38 > 0 &&
V_8 -> V_38 < V_8 -> V_157 . V_253 ) {
F_6 ( V_8 ,
L_33 ) ;
return F_10 ( V_41 ) ;
}
} else {
if ( V_8 -> V_38 > V_254 ) {
F_6 ( V_8 ,
L_34 ) ;
return F_10 ( V_41 ) ;
}
}
if ( F_113 ( & V_8 -> V_157 ) &&
! ( V_8 -> V_27 & V_78 ) )
V_8 -> V_27 |= V_76 ;
if ( ( V_8 -> V_157 . V_255 & V_256 ) && ! V_252 ) {
F_6 ( V_8 ,
L_35 ) ;
return F_10 ( V_257 ) ;
}
return 0 ;
}
STATIC int
F_114 (
struct V_10 * V_11 ,
void * V_258 ,
int V_259 )
{
struct V_163 * V_260 ;
struct V_7 * V_8 = NULL ;
int V_180 = 0 , error = V_23 ;
V_8 = F_115 ( sizeof( struct V_7 ) , V_22 ) ;
if ( ! V_8 )
goto V_152;
F_48 ( & V_8 -> V_220 ) ;
F_116 ( & V_8 -> V_261 ) ;
F_47 ( & V_8 -> V_262 , 0 ) ;
V_8 -> V_12 = V_11 ;
V_11 -> V_263 = V_8 ;
error = F_3 ( V_8 , ( char * ) V_258 ) ;
if ( error )
goto V_264;
F_117 ( V_11 , V_161 ) ;
V_11 -> V_265 = V_266 ;
V_11 -> V_267 = & V_268 ;
#ifdef F_8
V_11 -> V_269 = & V_270 ;
#endif
V_11 -> V_271 = & V_272 ;
if ( V_259 )
V_180 |= V_273 ;
error = F_28 ( V_8 ) ;
if ( error )
goto V_264;
error = F_118 ( V_8 ) ;
if ( error )
goto V_274;
error = F_119 ( V_8 , V_180 ) ;
if ( error )
goto V_275;
error = F_111 ( V_8 ) ;
if ( error )
goto V_276;
error = F_30 ( V_8 ) ;
if ( error )
goto V_276;
error = F_120 ( V_8 ) ;
if ( error )
goto V_276;
V_11 -> V_277 = V_213 ;
V_11 -> V_278 = V_8 -> V_157 . V_158 ;
V_11 -> V_279 = F_7 ( V_11 -> V_278 ) - 1 ;
V_11 -> V_280 = F_16 ( V_11 -> V_279 ) ;
V_11 -> V_281 = 1 ;
F_121 ( V_11 ) ;
error = F_122 ( V_8 ) ;
if ( error )
goto V_282;
error = F_123 ( V_8 ) ;
if ( error )
goto V_283;
V_260 = F_124 ( F_46 ( V_8 -> V_284 ) ) ;
if ( ! V_260 ) {
error = V_285 ;
goto V_286;
}
if ( F_39 ( V_260 ) ) {
error = V_41 ;
goto V_286;
}
V_11 -> V_287 = F_125 ( V_260 ) ;
if ( ! V_11 -> V_287 ) {
error = V_23 ;
goto V_288;
}
return 0 ;
V_282:
F_79 ( V_8 ) ;
V_276:
F_82 ( V_8 ) ;
V_275:
F_83 ( V_8 ) ;
V_274:
F_26 ( V_8 ) ;
V_264:
F_74 ( V_8 ) ;
F_75 ( V_8 ) ;
V_152:
return - error ;
V_288:
F_126 ( V_260 ) ;
V_286:
F_78 ( V_8 ) ;
V_283:
F_79 ( V_8 ) ;
F_80 ( V_8 -> V_146 , 1 ) ;
F_81 ( V_8 ) ;
goto V_276;
}
STATIC struct V_202 *
F_127 (
struct V_289 * V_290 ,
int V_180 ,
const char * V_291 ,
void * V_258 )
{
return F_128 ( V_290 , V_180 , V_291 , V_258 , F_114 ) ;
}
static int
F_129 (
struct V_10 * V_11 )
{
return F_130 ( F_77 ( V_11 ) ) ;
}
static void
F_131 (
struct V_10 * V_11 ,
int V_292 )
{
F_132 ( F_77 ( V_11 ) , V_292 ) ;
}
STATIC int T_10
F_133 ( void )
{
V_293 = F_134 ( sizeof( V_294 ) , L_36 ) ;
if ( ! V_293 )
goto V_152;
V_295 = F_135 ( 4 * V_296 ,
V_293 ) ;
if ( ! V_295 )
goto V_297;
V_298 = F_134 ( sizeof( V_299 ) ,
L_37 ) ;
if ( ! V_298 )
goto V_300;
V_301 = F_134 ( sizeof( V_302 ) ,
L_38 ) ;
if ( ! V_301 )
goto V_303;
V_304 = F_134 ( sizeof( V_305 ) ,
L_39 ) ;
if ( ! V_304 )
goto V_306;
V_307 = F_134 ( sizeof( V_308 ) ,
L_40 ) ;
if ( ! V_307 )
goto V_309;
V_310 = F_134 ( sizeof( V_311 ) , L_41 ) ;
if ( ! V_310 )
goto V_312;
V_313 = F_134 ( sizeof( V_314 ) , L_42 ) ;
if ( ! V_313 )
goto V_315;
V_316 = F_134 ( sizeof( V_317 ) , L_43 ) ;
if ( ! V_316 )
goto V_318;
V_319 =
F_134 ( sizeof( struct V_320 ) ,
L_44 ) ;
if ( ! V_319 )
goto V_321;
V_322 = F_134 ( ( sizeof( V_323 ) +
( ( ( V_324 / V_325 ) /
V_326 ) * sizeof( int ) ) ) , L_45 ) ;
if ( ! V_322 )
goto V_327;
V_328 = F_134 ( ( sizeof( V_329 ) +
( ( V_330 - 1 ) *
sizeof( V_331 ) ) ) , L_46 ) ;
if ( ! V_328 )
goto V_332;
V_333 = F_134 ( ( sizeof( V_334 ) +
( ( V_335 - 1 ) *
sizeof( V_331 ) ) ) , L_47 ) ;
if ( ! V_333 )
goto V_336;
V_337 =
F_136 ( sizeof( T_5 ) , L_48 ,
V_338 | V_339 | V_340 ,
F_44 ) ;
if ( ! V_337 )
goto V_341;
V_342 =
F_136 ( sizeof( V_343 ) , L_49 ,
V_340 , NULL ) ;
if ( ! V_342 )
goto V_344;
return 0 ;
V_344:
F_137 ( V_337 ) ;
V_341:
F_137 ( V_333 ) ;
V_336:
F_137 ( V_328 ) ;
V_332:
F_137 ( V_322 ) ;
V_327:
F_137 ( V_319 ) ;
V_321:
F_137 ( V_316 ) ;
V_318:
F_137 ( V_313 ) ;
V_315:
F_137 ( V_310 ) ;
V_312:
F_137 ( V_307 ) ;
V_309:
F_137 ( V_304 ) ;
V_306:
F_137 ( V_301 ) ;
V_303:
F_137 ( V_298 ) ;
V_300:
F_138 ( V_295 ) ;
V_297:
F_137 ( V_293 ) ;
V_152:
return - V_23 ;
}
STATIC void
F_139 ( void )
{
F_137 ( V_342 ) ;
F_137 ( V_337 ) ;
F_137 ( V_333 ) ;
F_137 ( V_328 ) ;
F_137 ( V_322 ) ;
F_137 ( V_319 ) ;
F_137 ( V_316 ) ;
F_137 ( V_313 ) ;
F_137 ( V_310 ) ;
F_137 ( V_307 ) ;
F_137 ( V_304 ) ;
F_137 ( V_301 ) ;
F_137 ( V_298 ) ;
F_138 ( V_295 ) ;
F_137 ( V_293 ) ;
}
STATIC int T_10
F_140 ( void )
{
V_345 = F_141 ( L_50 , V_346 , 8 ) ;
if ( ! V_345 )
return - V_23 ;
return 0 ;
}
STATIC void
F_142 ( void )
{
F_143 ( V_345 ) ;
}
STATIC int T_10
F_144 ( void )
{
int error ;
F_145 (KERN_INFO XFS_VERSION_STRING L_51
XFS_BUILD_OPTIONS L_52 ) ;
F_146 () ;
error = F_133 () ;
if ( error )
goto V_152;
error = F_140 () ;
if ( error )
goto V_347;
error = F_147 () ;
if ( error )
goto V_348;
error = F_148 () ;
if ( error )
goto V_349;
error = F_149 () ;
if ( error )
goto V_350;
error = F_150 () ;
if ( error )
goto V_351;
error = F_151 () ;
if ( error )
goto V_352;
F_152 () ;
error = F_153 ( & V_353 ) ;
if ( error )
goto V_354;
return 0 ;
V_354:
F_154 () ;
V_352:
F_155 () ;
V_351:
F_156 () ;
V_350:
F_157 () ;
V_349:
F_158 () ;
V_348:
F_142 () ;
V_347:
F_139 () ;
V_152:
return error ;
}
STATIC void T_11
F_159 ( void )
{
F_160 () ;
F_161 ( & V_353 ) ;
F_154 () ;
F_155 () ;
F_156 () ;
F_157 () ;
F_158 () ;
F_142 () ;
F_139 () ;
}
