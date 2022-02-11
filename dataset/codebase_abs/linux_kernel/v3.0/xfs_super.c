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
} else if ( ! strcmp ( V_13 , V_104 ) ) {
V_8 -> V_27 |= V_105 ;
} else if ( ! strcmp ( V_13 , V_106 ) ) {
V_8 -> V_27 &= ~ V_105 ;
} else if ( ! strcmp ( V_13 , L_4 ) ) {
F_6 ( V_8 ,
L_5 ) ;
} else if ( ! strcmp ( V_13 , L_6 ) ) {
F_6 ( V_8 ,
L_7 ) ;
} else if ( ! strcmp ( V_13 , L_8 ) ) {
F_6 ( V_8 ,
L_9 ) ;
} else if ( ! strcmp ( V_13 , L_10 ) ) {
F_6 ( V_8 ,
L_11 ) ;
} else {
F_6 ( V_8 , L_12 , V_13 ) ;
return V_41 ;
}
}
if ( ( V_8 -> V_27 & V_57 ) &&
! ( V_8 -> V_27 & V_28 ) ) {
F_6 ( V_8 , L_13 ) ;
return V_41 ;
}
if ( ( V_8 -> V_27 & V_59 ) && ( V_15 || V_16 ) ) {
F_6 ( V_8 ,
L_14 ) ;
return V_41 ;
}
if ( ( V_8 -> V_27 & V_105 ) &&
! ( V_8 -> V_27 & V_36 ) ) {
F_6 ( V_8 ,
L_15 ) ;
return V_41 ;
}
#ifndef F_8
if ( F_9 ( V_8 ) ) {
F_6 ( V_8 , L_16 ) ;
return V_41 ;
}
#endif
if ( ( V_8 -> V_82 & ( V_85 | V_86 ) ) &&
( V_8 -> V_82 & ( V_87 | V_88 ) ) ) {
F_6 ( V_8 , L_17 ) ;
return V_41 ;
}
if ( ( V_15 && ! V_16 ) || ( ! V_15 && V_16 ) ) {
F_6 ( V_8 , L_18 ) ;
return V_41 ;
}
if ( V_15 && ( V_16 % V_15 != 0 ) ) {
F_6 ( V_8 ,
L_19 ,
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
F_6 ( V_8 , L_20 ,
V_8 -> V_37 , V_110 , V_111 ) ;
return F_10 ( V_41 ) ;
}
if ( V_8 -> V_38 != - 1 &&
V_8 -> V_38 != 0 &&
( V_8 -> V_38 < V_112 ||
V_8 -> V_38 > V_113 ||
! F_11 ( V_8 -> V_38 ) ) ) {
F_6 ( V_8 ,
L_21 ,
V_8 -> V_38 ) ;
return F_10 ( V_41 ) ;
}
if ( V_18 ) {
if ( V_18 > V_114 ||
V_18 < V_115 ) {
F_6 ( V_8 , L_22 ,
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
F_14 ( V_120 , L_1 V_49 L_23 ,
( int ) ( 1 << V_8 -> V_118 ) >> 10 ) ;
if ( V_8 -> V_37 > 0 )
F_14 ( V_120 , L_1 V_40 L_24 , V_8 -> V_37 ) ;
if ( V_8 -> V_38 > 0 )
F_14 ( V_120 , L_1 V_42 L_23 , V_8 -> V_38 >> 10 ) ;
if ( V_8 -> V_44 )
F_14 ( V_120 , L_1 V_43 L_25 , V_8 -> V_44 ) ;
if ( V_8 -> V_47 )
F_14 ( V_120 , L_1 V_46 L_25 , V_8 -> V_47 ) ;
if ( V_8 -> V_107 > 0 )
F_14 ( V_120 , L_1 V_62 L_24 ,
( int ) F_15 ( V_8 , V_8 -> V_107 ) ) ;
if ( V_8 -> V_109 > 0 )
F_14 ( V_120 , L_1 V_63 L_24 ,
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
F_6 ( V_8 , L_26 , V_136 , error ) ;
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
L_27 ) ;
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
L_28 , V_165 -> V_180 ) ;
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
F_57 ( V_165 , V_185 ) ;
V_184 = F_58 ( V_8 , V_186 ) ;
error = F_59 ( V_184 , 0 , F_60 ( V_8 ) , 0 , 0 , 0 ) ;
if ( error ) {
F_61 ( V_184 , 0 ) ;
F_62 ( V_165 , V_185 ) ;
return error ;
}
F_62 ( V_165 , V_187 ) ;
F_63 ( V_184 , V_165 ) ;
F_64 ( V_184 , V_165 , V_188 ) ;
error = F_65 ( V_184 , 0 ) ;
F_66 ( V_165 , V_187 ) ;
return error ;
}
STATIC int
F_67 (
struct V_163 * V_163 ,
struct V_189 * V_190 )
{
struct V_164 * V_165 = F_36 ( V_163 ) ;
struct V_7 * V_8 = V_165 -> V_168 ;
int error = V_191 ;
F_68 ( V_165 ) ;
if ( F_41 ( V_8 ) )
return F_10 ( V_192 ) ;
if ( V_190 -> V_193 == V_194 ) {
F_40 ( V_165 ) ;
F_62 ( V_165 , V_185 ) ;
if ( V_165 -> V_182 ) {
error = F_56 ( V_165 ) ;
if ( error )
goto V_195;
}
} else {
if ( ! F_69 ( V_165 , V_185 ) )
goto V_152;
if ( F_70 ( V_165 ) || ! F_71 ( V_165 ) )
goto V_195;
if ( F_72 ( V_165 ) ) {
F_73 ( V_165 ) ;
error = 0 ;
goto V_195;
}
error = F_74 ( V_165 , V_196 ) ;
}
V_195:
F_57 ( V_165 , V_185 ) ;
V_152:
if ( error )
F_75 ( V_165 ) ;
return - error ;
}
STATIC void
F_76 (
struct V_163 * V_163 )
{
T_5 * V_165 = F_36 ( V_163 ) ;
F_77 ( V_165 ) ;
F_78 ( & V_163 -> V_197 , 0 ) ;
F_79 ( V_163 ) ;
F_38 ( V_198 ) ;
F_38 ( V_199 ) ;
F_80 ( V_200 ) ;
ASSERT ( ! F_81 ( & V_165 -> V_201 . V_202 ) ) ;
F_53 ( & V_165 -> V_201 , V_179 , L_29 , V_165 -> V_180 ) ;
F_82 ( & V_165 -> V_201 . V_202 ,
& V_203 , L_30 ) ;
F_83 ( V_165 ) ;
}
STATIC void
F_84 (
struct V_7 * V_8 )
{
F_85 ( V_8 -> V_19 ) ;
F_85 ( V_8 -> V_47 ) ;
F_85 ( V_8 -> V_44 ) ;
}
STATIC void
F_86 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_87 ( V_11 ) ;
F_88 ( V_8 ) ;
F_89 ( V_8 ) ;
F_90 ( V_8 ) ;
F_91 ( V_8 -> V_146 ) ;
F_92 ( V_8 ) ;
F_93 ( V_8 ) ;
F_94 ( V_8 ) ;
F_26 ( V_8 ) ;
F_84 ( V_8 ) ;
F_85 ( V_8 ) ;
}
STATIC int
F_95 (
struct V_10 * V_11 ,
int V_204 )
{
struct V_7 * V_8 = F_87 ( V_11 ) ;
int error ;
if ( ! V_204 ) {
F_96 ( V_8 , V_196 ) ;
return 0 ;
}
error = F_97 ( V_8 ) ;
if ( error )
return - error ;
if ( V_205 ) {
F_98 ( & V_8 -> V_206 ) ;
}
return 0 ;
}
STATIC int
F_99 (
struct V_207 * V_207 ,
struct V_208 * V_209 )
{
struct V_7 * V_8 = F_87 ( V_207 -> V_210 ) ;
T_6 * V_211 = & V_8 -> V_157 ;
struct V_164 * V_165 = F_36 ( V_207 -> V_212 ) ;
T_2 V_213 , V_214 ;
T_7 V_215 ;
T_8 V_216 ;
V_209 -> V_217 = V_218 ;
V_209 -> V_219 = V_21 - 1 ;
V_214 = F_100 ( V_8 -> V_146 -> V_220 ) ;
V_209 -> V_221 . V_222 [ 0 ] = ( V_223 ) V_214 ;
V_209 -> V_221 . V_222 [ 1 ] = ( V_223 ) ( V_214 >> 32 ) ;
F_101 ( V_8 , V_224 ) ;
F_102 ( & V_8 -> V_225 ) ;
V_209 -> V_226 = V_211 -> V_158 ;
V_215 = V_211 -> V_227 ? V_211 -> V_228 : 0 ;
V_209 -> V_229 = V_211 -> V_230 - V_215 ;
V_209 -> V_231 = V_209 -> V_232 =
V_211 -> V_233 - F_103 ( V_8 ) ;
V_213 = V_209 -> V_231 << V_211 -> V_234 ;
V_209 -> V_235 =
F_104 ( V_211 -> V_236 + V_213 , ( T_2 ) V_237 ) ;
if ( V_8 -> V_238 )
V_209 -> V_235 = F_105 ( F_106 ( V_209 -> V_235 ) ,
V_209 -> V_235 ,
V_8 -> V_238 ) ;
V_216 = V_209 -> V_235 - ( V_211 -> V_236 - V_211 -> V_239 ) ;
V_209 -> V_240 = F_107 ( T_8 , V_216 , 0 ) ;
F_108 ( & V_8 -> V_225 ) ;
if ( ( V_165 -> V_241 . V_242 & V_243 ) ||
( ( V_8 -> V_82 & ( V_87 | V_90 ) ) ) ==
( V_87 | V_90 ) )
F_109 ( V_165 , V_209 ) ;
return 0 ;
}
STATIC void
F_110 ( struct V_7 * V_8 )
{
T_2 V_244 = 0 ;
V_8 -> V_245 = V_8 -> V_246 ;
F_111 ( V_8 , & V_244 , NULL ) ;
}
STATIC void
F_112 ( struct V_7 * V_8 )
{
T_2 V_244 ;
if ( V_8 -> V_245 ) {
V_244 = V_8 -> V_245 ;
V_8 -> V_245 = 0 ;
} else
V_244 = F_113 ( V_8 ) ;
F_111 ( V_8 , & V_244 , NULL ) ;
}
STATIC int
F_114 (
struct V_10 * V_11 ,
int * V_181 ,
char * V_9 )
{
struct V_7 * V_8 = F_87 ( V_11 ) ;
T_9 args [ V_247 ] ;
char * V_248 ;
int error ;
while ( ( V_248 = F_5 ( & V_9 , L_1 ) ) != NULL ) {
int V_249 ;
if ( ! * V_248 )
continue;
V_249 = F_115 ( V_248 , V_250 , args ) ;
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
error = F_116 ( V_8 , V_8 -> V_253 ) ;
if ( error ) {
F_6 ( V_8 , L_31 ) ;
return error ;
}
V_8 -> V_253 = 0 ;
}
F_112 ( V_8 ) ;
}
if ( ! ( V_8 -> V_27 & V_28 ) && ( * V_181 & V_26 ) ) {
F_97 ( V_8 ) ;
F_110 ( V_8 ) ;
F_117 ( V_8 ) ;
V_8 -> V_27 |= V_28 ;
}
return 0 ;
}
STATIC int
F_118 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_87 ( V_11 ) ;
F_110 ( V_8 ) ;
F_117 ( V_8 ) ;
return - F_119 ( V_8 ) ;
}
STATIC int
F_120 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_87 ( V_11 ) ;
F_112 ( V_8 ) ;
return 0 ;
}
STATIC int
F_121 (
struct V_119 * V_120 ,
struct V_254 * V_255 )
{
return - F_12 ( F_87 ( V_255 -> V_256 ) , V_120 ) ;
}
STATIC int
F_122 (
struct V_7 * V_8 )
{
int V_257 = ( V_8 -> V_27 & V_28 ) ;
if ( F_123 ( & V_8 -> V_157 ) ) {
if ( V_8 -> V_38 <= 0 &&
V_8 -> V_157 . V_258 > V_259 ) {
V_8 -> V_38 = V_8 -> V_157 . V_258 ;
} else if ( V_8 -> V_38 > 0 &&
V_8 -> V_38 < V_8 -> V_157 . V_258 ) {
F_6 ( V_8 ,
L_32 ) ;
return F_10 ( V_41 ) ;
}
} else {
if ( V_8 -> V_38 > V_259 ) {
F_6 ( V_8 ,
L_33 ) ;
return F_10 ( V_41 ) ;
}
}
if ( F_124 ( & V_8 -> V_157 ) &&
! ( V_8 -> V_27 & V_78 ) )
V_8 -> V_27 |= V_76 ;
if ( ( V_8 -> V_157 . V_260 & V_261 ) && ! V_257 ) {
F_6 ( V_8 ,
L_34 ) ;
return F_10 ( V_262 ) ;
}
return 0 ;
}
STATIC int
F_125 (
struct V_10 * V_11 ,
void * V_263 ,
int V_264 )
{
struct V_163 * V_265 ;
struct V_7 * V_8 = NULL ;
int V_181 = 0 , error = V_23 ;
V_8 = F_126 ( sizeof( struct V_7 ) , V_22 ) ;
if ( ! V_8 )
goto V_152;
F_49 ( & V_8 -> V_225 ) ;
F_127 ( & V_8 -> V_266 ) ;
F_48 ( & V_8 -> V_267 , 0 ) ;
V_8 -> V_12 = V_11 ;
V_11 -> V_268 = V_8 ;
error = F_3 ( V_8 , ( char * ) V_263 ) ;
if ( error )
goto V_269;
F_128 ( V_11 , V_161 ) ;
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
error = F_129 ( V_8 ) ;
if ( error )
goto V_279;
error = F_130 ( V_8 , V_181 ) ;
if ( error )
goto V_280;
error = F_122 ( V_8 ) ;
if ( error )
goto V_281;
error = F_30 ( V_8 ) ;
if ( error )
goto V_281;
error = F_131 ( V_8 ) ;
if ( error )
goto V_281;
V_11 -> V_282 = V_218 ;
V_11 -> V_283 = V_8 -> V_157 . V_158 ;
V_11 -> V_284 = F_7 ( V_11 -> V_283 ) - 1 ;
V_11 -> V_285 = F_16 ( V_11 -> V_284 ) ;
V_11 -> V_286 = 1 ;
F_132 ( V_11 ) ;
error = F_133 ( V_8 ) ;
if ( error )
goto V_287;
F_134 ( V_8 ) ;
error = F_135 ( V_8 ) ;
if ( error )
goto V_288;
V_265 = F_136 ( F_47 ( V_8 -> V_289 ) ) ;
if ( ! V_265 ) {
error = V_290 ;
goto V_291;
}
if ( F_39 ( V_265 ) ) {
error = V_41 ;
goto V_292;
}
V_11 -> V_293 = F_137 ( V_265 ) ;
if ( ! V_11 -> V_293 ) {
error = V_23 ;
goto V_292;
}
return 0 ;
V_288:
F_88 ( V_8 ) ;
F_89 ( V_8 ) ;
V_287:
F_90 ( V_8 ) ;
V_281:
F_93 ( V_8 ) ;
V_280:
F_94 ( V_8 ) ;
V_279:
F_26 ( V_8 ) ;
V_269:
F_84 ( V_8 ) ;
F_85 ( V_8 ) ;
V_152:
return - error ;
V_292:
if ( V_11 -> V_293 ) {
F_138 ( V_11 -> V_293 ) ;
V_11 -> V_293 = NULL ;
} else {
F_139 ( V_265 ) ;
}
V_291:
F_88 ( V_8 ) ;
F_89 ( V_8 ) ;
F_90 ( V_8 ) ;
F_91 ( V_8 -> V_146 ) ;
F_92 ( V_8 ) ;
goto V_281;
}
STATIC struct V_207 *
F_140 (
struct V_294 * V_295 ,
int V_181 ,
const char * V_296 ,
void * V_263 )
{
return F_141 ( V_295 , V_181 , V_296 , V_263 , F_125 ) ;
}
STATIC int T_10
F_142 ( void )
{
V_297 = F_143 ( sizeof( V_298 ) , L_35 ) ;
if ( ! V_297 )
goto V_152;
V_299 = F_144 ( 4 * V_300 ,
V_297 ) ;
if ( ! V_299 )
goto V_301;
V_302 = F_143 ( sizeof( V_303 ) ,
L_36 ) ;
if ( ! V_302 )
goto V_304;
V_305 = F_143 ( sizeof( V_306 ) ,
L_37 ) ;
if ( ! V_305 )
goto V_307;
V_308 = F_143 ( sizeof( V_309 ) ,
L_38 ) ;
if ( ! V_308 )
goto V_310;
V_311 = F_143 ( sizeof( V_312 ) ,
L_39 ) ;
if ( ! V_311 )
goto V_313;
V_314 = F_143 ( sizeof( V_315 ) , L_40 ) ;
if ( ! V_314 )
goto V_316;
V_317 = F_143 ( sizeof( V_318 ) , L_41 ) ;
if ( ! V_317 )
goto V_319;
V_320 = F_143 ( sizeof( V_321 ) , L_42 ) ;
if ( ! V_320 )
goto V_322;
V_323 =
F_143 ( sizeof( struct V_324 ) ,
L_43 ) ;
if ( ! V_323 )
goto V_325;
V_326 = F_143 ( ( sizeof( V_327 ) +
( ( ( V_328 / V_329 ) /
V_330 ) * sizeof( int ) ) ) , L_44 ) ;
if ( ! V_326 )
goto V_331;
V_332 = F_143 ( ( sizeof( V_333 ) +
( ( V_334 - 1 ) *
sizeof( V_335 ) ) ) , L_45 ) ;
if ( ! V_332 )
goto V_336;
V_337 = F_143 ( ( sizeof( V_338 ) +
( ( V_339 - 1 ) *
sizeof( V_335 ) ) ) , L_46 ) ;
if ( ! V_337 )
goto V_340;
V_341 =
F_145 ( sizeof( T_5 ) , L_47 ,
V_342 | V_343 | V_344 ,
F_45 ) ;
if ( ! V_341 )
goto V_345;
V_346 =
F_145 ( sizeof( V_347 ) , L_48 ,
V_344 , NULL ) ;
if ( ! V_346 )
goto V_348;
return 0 ;
V_348:
F_146 ( V_341 ) ;
V_345:
F_146 ( V_337 ) ;
V_340:
F_146 ( V_332 ) ;
V_336:
F_146 ( V_326 ) ;
V_331:
F_146 ( V_323 ) ;
V_325:
F_146 ( V_320 ) ;
V_322:
F_146 ( V_317 ) ;
V_319:
F_146 ( V_314 ) ;
V_316:
F_146 ( V_311 ) ;
V_313:
F_146 ( V_308 ) ;
V_310:
F_146 ( V_305 ) ;
V_307:
F_146 ( V_302 ) ;
V_304:
F_147 ( V_299 ) ;
V_301:
F_146 ( V_297 ) ;
V_152:
return - V_23 ;
}
STATIC void
F_148 ( void )
{
F_146 ( V_346 ) ;
F_146 ( V_341 ) ;
F_146 ( V_337 ) ;
F_146 ( V_332 ) ;
F_146 ( V_326 ) ;
F_146 ( V_323 ) ;
F_146 ( V_320 ) ;
F_146 ( V_317 ) ;
F_146 ( V_314 ) ;
F_146 ( V_311 ) ;
F_146 ( V_308 ) ;
F_146 ( V_305 ) ;
F_146 ( V_302 ) ;
F_147 ( V_299 ) ;
F_146 ( V_297 ) ;
}
STATIC int T_10
F_149 ( void )
{
V_349 = F_150 ( L_49 , V_350 , 8 ) ;
if ( ! V_349 )
goto V_152;
V_351 = F_150 ( L_50 , V_350 , 8 ) ;
if ( ! V_351 )
goto V_352;
return 0 ;
V_352:
F_151 ( V_349 ) ;
V_152:
return - V_23 ;
}
STATIC void
F_152 ( void )
{
F_151 ( V_351 ) ;
F_151 ( V_349 ) ;
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
goto V_353;
error = F_157 () ;
if ( error )
goto V_354;
error = F_158 () ;
if ( error )
goto V_355;
error = F_159 () ;
if ( error )
goto V_356;
error = F_160 () ;
if ( error )
goto V_357;
error = F_161 () ;
if ( error )
goto V_358;
F_162 () ;
error = F_163 ( & V_359 ) ;
if ( error )
goto V_360;
return 0 ;
V_360:
F_164 () ;
V_358:
F_165 () ;
V_357:
F_166 () ;
V_356:
F_167 () ;
V_355:
F_168 () ;
V_354:
F_152 () ;
V_353:
F_148 () ;
V_152:
return error ;
}
STATIC void T_11
F_169 ( void )
{
F_170 () ;
F_171 ( & V_359 ) ;
F_164 () ;
F_165 () ;
F_166 () ;
F_167 () ;
F_168 () ;
F_152 () ;
F_148 () ;
}
