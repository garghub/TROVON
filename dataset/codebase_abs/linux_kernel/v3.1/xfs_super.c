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
F_40 ( V_165 ) ;
ASSERT ( F_41 ( V_165 -> V_168 ) || V_165 -> V_169 == 0 ) ;
F_42 ( ! F_43 ( V_165 , V_170 ) ) ;
F_42 ( ! F_43 ( V_165 , V_171 ) ) ;
V_167:
F_44 ( V_165 ) ;
}
STATIC void
F_45 (
void * V_163 )
{
struct V_164 * V_165 = V_163 ;
memset ( V_165 , 0 , sizeof( struct V_164 ) ) ;
F_46 ( F_47 ( V_165 ) ) ;
F_48 ( & V_165 -> V_172 , 0 ) ;
F_48 ( & V_165 -> V_173 , 0 ) ;
F_49 ( & V_165 -> V_174 ) ;
F_50 ( & V_165 -> V_175 ) ;
F_51 ( & V_165 -> V_176 ) ;
F_52 ( & V_165 -> V_176 ) ;
F_53 ( & V_165 -> V_177 , V_178 | V_179 ,
L_29 , V_165 -> V_180 ) ;
}
STATIC void
F_54 (
struct V_163 * V_163 ,
int V_181 )
{
F_55 () ;
F_36 ( V_163 ) -> V_182 = 1 ;
}
STATIC int
F_56 (
struct V_164 * V_165 )
{
struct V_7 * V_8 = V_165 -> V_168 ;
struct V_183 * V_184 ;
int error ;
V_184 = F_57 ( V_8 , V_185 ) ;
error = F_58 ( V_184 , 0 , F_59 ( V_8 ) , 0 , 0 , 0 ) ;
if ( error ) {
F_60 ( V_184 , 0 ) ;
return error ;
}
F_61 ( V_165 , V_186 ) ;
F_62 ( V_184 , V_165 , V_186 ) ;
F_63 ( V_184 , V_165 , V_187 ) ;
return F_64 ( V_184 , 0 ) ;
}
STATIC int
F_65 (
struct V_163 * V_163 ,
struct V_188 * V_189 )
{
struct V_164 * V_165 = F_36 ( V_163 ) ;
struct V_7 * V_8 = V_165 -> V_168 ;
int error = V_190 ;
F_66 ( V_165 ) ;
if ( F_41 ( V_8 ) )
return - F_10 ( V_191 ) ;
if ( ! V_165 -> V_182 )
return 0 ;
if ( V_189 -> V_192 == V_193 ) {
F_40 ( V_165 ) ;
error = F_56 ( V_165 ) ;
if ( error )
goto V_152;
return 0 ;
} else {
if ( ! F_67 ( V_165 , V_194 ) )
goto V_152;
if ( F_68 ( V_165 ) || ! F_69 ( V_165 ) )
goto V_195;
if ( F_70 ( V_165 ) ) {
F_71 ( V_165 ) ;
error = 0 ;
goto V_195;
}
error = F_72 ( V_165 , V_196 ) ;
}
V_195:
F_73 ( V_165 , V_194 ) ;
V_152:
if ( error )
F_74 ( V_165 ) ;
return - error ;
}
STATIC void
F_75 (
struct V_163 * V_163 )
{
T_5 * V_165 = F_36 ( V_163 ) ;
F_76 ( V_165 ) ;
F_77 ( & V_163 -> V_197 , 0 ) ;
F_78 ( V_163 ) ;
F_38 ( V_198 ) ;
F_38 ( V_199 ) ;
F_79 ( V_200 ) ;
ASSERT ( ! F_80 ( & V_165 -> V_201 . V_202 ) ) ;
F_53 ( & V_165 -> V_201 , V_179 , L_30 , V_165 -> V_180 ) ;
F_81 ( & V_165 -> V_201 . V_202 ,
& V_203 , L_31 ) ;
F_82 ( V_165 ) ;
}
STATIC void
F_83 (
struct V_7 * V_8 )
{
F_84 ( V_8 -> V_19 ) ;
F_84 ( V_8 -> V_47 ) ;
F_84 ( V_8 -> V_44 ) ;
}
STATIC void
F_85 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_86 ( V_11 ) ;
F_87 ( V_8 ) ;
F_88 ( V_8 ) ;
F_89 ( V_8 -> V_146 ) ;
F_90 ( V_8 ) ;
F_91 ( V_8 ) ;
F_92 ( V_8 ) ;
F_26 ( V_8 ) ;
F_83 ( V_8 ) ;
F_84 ( V_8 ) ;
}
STATIC int
F_93 (
struct V_10 * V_11 ,
int V_204 )
{
struct V_7 * V_8 = F_86 ( V_11 ) ;
int error ;
if ( ! V_204 ) {
F_94 ( V_8 , V_196 ) ;
return 0 ;
}
error = F_95 ( V_8 ) ;
if ( error )
return - error ;
if ( V_205 ) {
F_96 ( & V_8 -> V_206 ) ;
}
return 0 ;
}
STATIC int
F_97 (
struct V_207 * V_207 ,
struct V_208 * V_209 )
{
struct V_7 * V_8 = F_86 ( V_207 -> V_210 ) ;
T_6 * V_211 = & V_8 -> V_157 ;
struct V_164 * V_165 = F_36 ( V_207 -> V_212 ) ;
T_2 V_213 , V_214 ;
T_7 V_215 ;
T_8 V_216 ;
V_209 -> V_217 = V_218 ;
V_209 -> V_219 = V_21 - 1 ;
V_214 = F_98 ( V_8 -> V_146 -> V_220 ) ;
V_209 -> V_221 . V_222 [ 0 ] = ( V_223 ) V_214 ;
V_209 -> V_221 . V_222 [ 1 ] = ( V_223 ) ( V_214 >> 32 ) ;
F_99 ( V_8 , V_224 ) ;
F_100 ( & V_8 -> V_225 ) ;
V_209 -> V_226 = V_211 -> V_158 ;
V_215 = V_211 -> V_227 ? V_211 -> V_228 : 0 ;
V_209 -> V_229 = V_211 -> V_230 - V_215 ;
V_209 -> V_231 = V_209 -> V_232 =
V_211 -> V_233 - F_101 ( V_8 ) ;
V_213 = V_209 -> V_231 << V_211 -> V_234 ;
V_209 -> V_235 =
F_102 ( V_211 -> V_236 + V_213 , ( T_2 ) V_237 ) ;
if ( V_8 -> V_238 )
V_209 -> V_235 = F_103 ( F_104 ( V_209 -> V_235 ) ,
V_209 -> V_235 ,
V_8 -> V_238 ) ;
V_216 = V_209 -> V_235 - ( V_211 -> V_236 - V_211 -> V_239 ) ;
V_209 -> V_240 = F_105 ( T_8 , V_216 , 0 ) ;
F_106 ( & V_8 -> V_225 ) ;
if ( ( V_165 -> V_241 . V_242 & V_243 ) ||
( ( V_8 -> V_82 & ( V_87 | V_90 ) ) ) ==
( V_87 | V_90 ) )
F_107 ( V_165 , V_209 ) ;
return 0 ;
}
STATIC void
F_108 ( struct V_7 * V_8 )
{
T_2 V_244 = 0 ;
V_8 -> V_245 = V_8 -> V_246 ;
F_109 ( V_8 , & V_244 , NULL ) ;
}
STATIC void
F_110 ( struct V_7 * V_8 )
{
T_2 V_244 ;
if ( V_8 -> V_245 ) {
V_244 = V_8 -> V_245 ;
V_8 -> V_245 = 0 ;
} else
V_244 = F_111 ( V_8 ) ;
F_109 ( V_8 , & V_244 , NULL ) ;
}
STATIC int
F_112 (
struct V_10 * V_11 ,
int * V_181 ,
char * V_9 )
{
struct V_7 * V_8 = F_86 ( V_11 ) ;
T_9 args [ V_247 ] ;
char * V_248 ;
int error ;
while ( ( V_248 = F_5 ( & V_9 , L_1 ) ) != NULL ) {
int V_249 ;
if ( ! * V_248 )
continue;
V_249 = F_113 ( V_248 , V_250 , args ) ;
switch ( V_249 ) {
case V_251 :
V_8 -> V_27 |= V_33 ;
break;
case V_252 :
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
if ( ( V_8 -> V_27 & V_28 ) && ! ( * V_181 & V_26 ) ) {
V_8 -> V_27 &= ~ V_28 ;
if ( V_8 -> V_253 ) {
error = F_114 ( V_8 , V_8 -> V_253 ) ;
if ( error ) {
F_6 ( V_8 , L_32 ) ;
return error ;
}
V_8 -> V_253 = 0 ;
}
F_110 ( V_8 ) ;
}
if ( ! ( V_8 -> V_27 & V_28 ) && ( * V_181 & V_26 ) ) {
F_95 ( V_8 ) ;
F_108 ( V_8 ) ;
F_115 ( V_8 ) ;
V_8 -> V_27 |= V_28 ;
}
return 0 ;
}
STATIC int
F_116 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_86 ( V_11 ) ;
F_108 ( V_8 ) ;
F_115 ( V_8 ) ;
return - F_117 ( V_8 ) ;
}
STATIC int
F_118 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_86 ( V_11 ) ;
F_110 ( V_8 ) ;
return 0 ;
}
STATIC int
F_119 (
struct V_119 * V_120 ,
struct V_254 * V_255 )
{
return - F_12 ( F_86 ( V_255 -> V_256 ) , V_120 ) ;
}
STATIC int
F_120 (
struct V_7 * V_8 )
{
int V_257 = ( V_8 -> V_27 & V_28 ) ;
if ( F_121 ( & V_8 -> V_157 ) ) {
if ( V_8 -> V_38 <= 0 &&
V_8 -> V_157 . V_258 > V_259 ) {
V_8 -> V_38 = V_8 -> V_157 . V_258 ;
} else if ( V_8 -> V_38 > 0 &&
V_8 -> V_38 < V_8 -> V_157 . V_258 ) {
F_6 ( V_8 ,
L_33 ) ;
return F_10 ( V_41 ) ;
}
} else {
if ( V_8 -> V_38 > V_259 ) {
F_6 ( V_8 ,
L_34 ) ;
return F_10 ( V_41 ) ;
}
}
if ( F_122 ( & V_8 -> V_157 ) &&
! ( V_8 -> V_27 & V_78 ) )
V_8 -> V_27 |= V_76 ;
if ( ( V_8 -> V_157 . V_260 & V_261 ) && ! V_257 ) {
F_6 ( V_8 ,
L_35 ) ;
return F_10 ( V_262 ) ;
}
return 0 ;
}
STATIC int
F_123 (
struct V_10 * V_11 ,
void * V_263 ,
int V_264 )
{
struct V_163 * V_265 ;
struct V_7 * V_8 = NULL ;
int V_181 = 0 , error = V_23 ;
V_8 = F_124 ( sizeof( struct V_7 ) , V_22 ) ;
if ( ! V_8 )
goto V_152;
F_49 ( & V_8 -> V_225 ) ;
F_125 ( & V_8 -> V_266 ) ;
F_48 ( & V_8 -> V_267 , 0 ) ;
V_8 -> V_12 = V_11 ;
V_11 -> V_268 = V_8 ;
error = F_3 ( V_8 , ( char * ) V_263 ) ;
if ( error )
goto V_269;
F_126 ( V_11 , V_161 ) ;
V_11 -> V_270 = V_271 ;
V_11 -> V_272 = & V_273 ;
#ifdef F_8
V_11 -> V_274 = & V_275 ;
#endif
V_11 -> V_276 = & V_277 ;
if ( V_264 )
V_181 |= V_278 ;
error = F_28 ( V_8 ) ;
if ( error )
goto V_269;
error = F_127 ( V_8 ) ;
if ( error )
goto V_279;
error = F_128 ( V_8 , V_181 ) ;
if ( error )
goto V_280;
error = F_120 ( V_8 ) ;
if ( error )
goto V_281;
error = F_30 ( V_8 ) ;
if ( error )
goto V_281;
error = F_129 ( V_8 ) ;
if ( error )
goto V_281;
V_11 -> V_282 = V_218 ;
V_11 -> V_283 = V_8 -> V_157 . V_158 ;
V_11 -> V_284 = F_7 ( V_11 -> V_283 ) - 1 ;
V_11 -> V_285 = F_16 ( V_11 -> V_284 ) ;
V_11 -> V_286 = 1 ;
F_130 ( V_11 ) ;
error = F_131 ( V_8 ) ;
if ( error )
goto V_287;
error = F_132 ( V_8 ) ;
if ( error )
goto V_288;
V_265 = F_133 ( F_47 ( V_8 -> V_289 ) ) ;
if ( ! V_265 ) {
error = V_290 ;
goto V_291;
}
if ( F_39 ( V_265 ) ) {
error = V_41 ;
goto V_291;
}
V_11 -> V_292 = F_134 ( V_265 ) ;
if ( ! V_11 -> V_292 ) {
error = V_23 ;
goto V_293;
}
return 0 ;
V_287:
F_88 ( V_8 ) ;
V_281:
F_91 ( V_8 ) ;
V_280:
F_92 ( V_8 ) ;
V_279:
F_26 ( V_8 ) ;
V_269:
F_83 ( V_8 ) ;
F_84 ( V_8 ) ;
V_152:
return - error ;
V_293:
F_135 ( V_265 ) ;
V_291:
F_87 ( V_8 ) ;
V_288:
F_88 ( V_8 ) ;
F_89 ( V_8 -> V_146 ) ;
F_90 ( V_8 ) ;
goto V_281;
}
STATIC struct V_207 *
F_136 (
struct V_294 * V_295 ,
int V_181 ,
const char * V_296 ,
void * V_263 )
{
return F_137 ( V_295 , V_181 , V_296 , V_263 , F_123 ) ;
}
static int
F_138 (
struct V_10 * V_11 )
{
return F_139 ( F_86 ( V_11 ) ) ;
}
static void
F_140 (
struct V_10 * V_11 ,
int V_297 )
{
F_141 ( F_86 ( V_11 ) , V_297 ) ;
}
STATIC int T_10
F_142 ( void )
{
V_298 = F_143 ( sizeof( V_299 ) , L_36 ) ;
if ( ! V_298 )
goto V_152;
V_300 = F_144 ( 4 * V_301 ,
V_298 ) ;
if ( ! V_300 )
goto V_302;
V_303 = F_143 ( sizeof( V_304 ) ,
L_37 ) ;
if ( ! V_303 )
goto V_305;
V_306 = F_143 ( sizeof( V_307 ) ,
L_38 ) ;
if ( ! V_306 )
goto V_308;
V_309 = F_143 ( sizeof( V_310 ) ,
L_39 ) ;
if ( ! V_309 )
goto V_311;
V_312 = F_143 ( sizeof( V_313 ) ,
L_40 ) ;
if ( ! V_312 )
goto V_314;
V_315 = F_143 ( sizeof( V_316 ) , L_41 ) ;
if ( ! V_315 )
goto V_317;
V_318 = F_143 ( sizeof( V_319 ) , L_42 ) ;
if ( ! V_318 )
goto V_320;
V_321 = F_143 ( sizeof( V_322 ) , L_43 ) ;
if ( ! V_321 )
goto V_323;
V_324 =
F_143 ( sizeof( struct V_325 ) ,
L_44 ) ;
if ( ! V_324 )
goto V_326;
V_327 = F_143 ( ( sizeof( V_328 ) +
( ( ( V_329 / V_330 ) /
V_331 ) * sizeof( int ) ) ) , L_45 ) ;
if ( ! V_327 )
goto V_332;
V_333 = F_143 ( ( sizeof( V_334 ) +
( ( V_335 - 1 ) *
sizeof( V_336 ) ) ) , L_46 ) ;
if ( ! V_333 )
goto V_337;
V_338 = F_143 ( ( sizeof( V_339 ) +
( ( V_340 - 1 ) *
sizeof( V_336 ) ) ) , L_47 ) ;
if ( ! V_338 )
goto V_341;
V_342 =
F_145 ( sizeof( T_5 ) , L_48 ,
V_343 | V_344 | V_345 ,
F_45 ) ;
if ( ! V_342 )
goto V_346;
V_347 =
F_145 ( sizeof( V_348 ) , L_49 ,
V_345 , NULL ) ;
if ( ! V_347 )
goto V_349;
return 0 ;
V_349:
F_146 ( V_342 ) ;
V_346:
F_146 ( V_338 ) ;
V_341:
F_146 ( V_333 ) ;
V_337:
F_146 ( V_327 ) ;
V_332:
F_146 ( V_324 ) ;
V_326:
F_146 ( V_321 ) ;
V_323:
F_146 ( V_318 ) ;
V_320:
F_146 ( V_315 ) ;
V_317:
F_146 ( V_312 ) ;
V_314:
F_146 ( V_309 ) ;
V_311:
F_146 ( V_306 ) ;
V_308:
F_146 ( V_303 ) ;
V_305:
F_147 ( V_300 ) ;
V_302:
F_146 ( V_298 ) ;
V_152:
return - V_23 ;
}
STATIC void
F_148 ( void )
{
F_146 ( V_347 ) ;
F_146 ( V_342 ) ;
F_146 ( V_338 ) ;
F_146 ( V_333 ) ;
F_146 ( V_327 ) ;
F_146 ( V_324 ) ;
F_146 ( V_321 ) ;
F_146 ( V_318 ) ;
F_146 ( V_315 ) ;
F_146 ( V_312 ) ;
F_146 ( V_309 ) ;
F_146 ( V_306 ) ;
F_146 ( V_303 ) ;
F_147 ( V_300 ) ;
F_146 ( V_298 ) ;
}
STATIC int T_10
F_149 ( void )
{
V_350 = F_150 ( L_50 , V_351 , 8 ) ;
if ( ! V_350 )
return - V_23 ;
return 0 ;
}
STATIC void
F_151 ( void )
{
F_152 ( V_350 ) ;
}
STATIC int T_10
F_153 ( void )
{
int error ;
F_154 (KERN_INFO XFS_VERSION_STRING L_51
XFS_BUILD_OPTIONS L_52 ) ;
F_155 () ;
F_156 () ;
error = F_142 () ;
if ( error )
goto V_152;
error = F_149 () ;
if ( error )
goto V_352;
error = F_157 () ;
if ( error )
goto V_353;
error = F_158 () ;
if ( error )
goto V_354;
error = F_159 () ;
if ( error )
goto V_355;
error = F_160 () ;
if ( error )
goto V_356;
error = F_161 () ;
if ( error )
goto V_357;
F_162 () ;
error = F_163 ( & V_358 ) ;
if ( error )
goto V_359;
return 0 ;
V_359:
F_164 () ;
V_357:
F_165 () ;
V_356:
F_166 () ;
V_355:
F_167 () ;
V_354:
F_168 () ;
V_353:
F_151 () ;
V_352:
F_148 () ;
V_152:
return error ;
}
STATIC void T_11
F_169 ( void )
{
F_170 () ;
F_171 ( & V_358 ) ;
F_164 () ;
F_165 () ;
F_166 () ;
F_167 () ;
F_168 () ;
F_151 () ;
F_148 () ;
}
