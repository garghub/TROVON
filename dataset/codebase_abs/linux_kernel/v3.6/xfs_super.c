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
struct V_171 * V_171 )
{
T_5 * V_173 = F_40 ( V_171 ) ;
ASSERT ( ! F_55 ( & V_173 -> V_186 . V_187 ) ) ;
F_56 ( V_173 ) ;
F_57 ( & V_171 -> V_188 , 0 ) ;
F_58 ( V_171 ) ;
F_42 ( V_189 ) ;
F_42 ( V_190 ) ;
F_59 ( V_191 ) ;
F_60 ( V_173 ) ;
}
STATIC int
F_61 (
struct V_171 * V_171 )
{
struct V_172 * V_173 = F_40 ( V_171 ) ;
return F_62 ( V_171 ) || ( V_173 -> V_192 & V_193 ) ;
}
STATIC void
F_63 (
struct V_7 * V_8 )
{
F_64 ( V_8 -> V_19 ) ;
F_64 ( V_8 -> V_46 ) ;
F_64 ( V_8 -> V_43 ) ;
}
STATIC void
F_65 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_66 ( V_11 ) ;
F_67 ( V_8 ) ;
F_68 ( & V_8 -> V_194 ) ;
F_69 ( V_8 ) ;
F_70 ( V_8 ) ;
F_71 ( V_8 ) ;
F_72 ( V_8 ) ;
F_36 ( V_8 ) ;
F_26 ( V_8 ) ;
F_63 ( V_8 ) ;
F_64 ( V_8 ) ;
}
STATIC int
F_73 (
struct V_10 * V_11 ,
int V_195 )
{
struct V_7 * V_8 = F_66 ( V_11 ) ;
int error ;
if ( ! V_195 )
return 0 ;
error = F_74 ( V_8 ) ;
if ( error )
return - error ;
if ( V_196 ) {
F_75 ( & V_8 -> V_194 ) ;
}
return 0 ;
}
STATIC int
F_76 (
struct V_197 * V_197 ,
struct V_198 * V_199 )
{
struct V_7 * V_8 = F_66 ( V_197 -> V_200 ) ;
T_6 * V_201 = & V_8 -> V_159 ;
struct V_172 * V_173 = F_40 ( V_197 -> V_202 ) ;
T_2 V_203 , V_204 ;
T_7 V_205 ;
T_8 V_206 ;
V_199 -> V_207 = V_208 ;
V_199 -> V_209 = V_21 - 1 ;
V_204 = F_77 ( V_8 -> V_148 -> V_210 ) ;
V_199 -> V_211 . V_212 [ 0 ] = ( V_213 ) V_204 ;
V_199 -> V_211 . V_212 [ 1 ] = ( V_213 ) ( V_204 >> 32 ) ;
F_78 ( V_8 , V_214 ) ;
F_79 ( & V_8 -> V_215 ) ;
V_199 -> V_216 = V_201 -> V_160 ;
V_205 = V_201 -> V_217 ? V_201 -> V_218 : 0 ;
V_199 -> V_219 = V_201 -> V_220 - V_205 ;
V_199 -> V_221 = V_199 -> V_222 =
V_201 -> V_223 - F_80 ( V_8 ) ;
V_203 = V_199 -> V_221 << V_201 -> V_224 ;
V_199 -> V_225 =
F_81 ( V_201 -> V_226 + V_203 , ( T_2 ) V_227 ) ;
if ( V_8 -> V_228 )
V_199 -> V_225 = F_82 ( F_83 ( V_199 -> V_225 ) ,
V_199 -> V_225 ,
V_8 -> V_228 ) ;
V_206 = V_199 -> V_225 - ( V_201 -> V_226 - V_201 -> V_229 ) ;
V_199 -> V_230 = F_84 ( T_8 , V_206 , 0 ) ;
F_85 ( & V_8 -> V_215 ) ;
if ( ( V_173 -> V_231 . V_232 & V_233 ) &&
( ( V_8 -> V_81 & ( V_95 | V_97 ) ) ) ==
( V_95 | V_97 ) )
F_86 ( V_173 , V_199 ) ;
return 0 ;
}
STATIC void
F_87 ( struct V_7 * V_8 )
{
T_2 V_234 = 0 ;
V_8 -> V_235 = V_8 -> V_236 ;
F_88 ( V_8 , & V_234 , NULL ) ;
}
STATIC void
F_89 ( struct V_7 * V_8 )
{
T_2 V_234 ;
if ( V_8 -> V_235 ) {
V_234 = V_8 -> V_235 ;
V_8 -> V_235 = 0 ;
} else
V_234 = F_90 ( V_8 ) ;
F_88 ( V_8 , & V_234 , NULL ) ;
}
STATIC int
F_91 (
struct V_10 * V_11 ,
int * V_237 ,
char * V_9 )
{
struct V_7 * V_8 = F_66 ( V_11 ) ;
T_9 args [ V_238 ] ;
char * V_239 ;
int error ;
while ( ( V_239 = F_5 ( & V_9 , L_1 ) ) != NULL ) {
int V_240 ;
if ( ! * V_239 )
continue;
V_240 = F_92 ( V_239 , V_241 , args ) ;
switch ( V_240 ) {
case V_242 :
V_8 -> V_27 |= V_33 ;
break;
case V_243 :
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
if ( ( V_8 -> V_27 & V_28 ) && ! ( * V_237 & V_26 ) ) {
V_8 -> V_27 &= ~ V_28 ;
if ( V_8 -> V_244 ) {
error = F_93 ( V_8 , V_8 -> V_244 ) ;
if ( error ) {
F_6 ( V_8 , L_33 ) ;
return error ;
}
V_8 -> V_244 = 0 ;
}
F_89 ( V_8 ) ;
}
if ( ! ( V_8 -> V_27 & V_28 ) && ( * V_237 & V_26 ) ) {
F_74 ( V_8 ) ;
F_87 ( V_8 ) ;
F_94 ( V_8 ) ;
V_8 -> V_27 |= V_28 ;
}
return 0 ;
}
STATIC int
F_95 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_66 ( V_11 ) ;
F_87 ( V_8 ) ;
F_94 ( V_8 ) ;
return - F_96 ( V_8 ) ;
}
STATIC int
F_97 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_66 ( V_11 ) ;
F_89 ( V_8 ) ;
return 0 ;
}
STATIC int
F_98 (
struct V_121 * V_122 ,
struct V_197 * V_245 )
{
return - F_12 ( F_66 ( V_245 -> V_200 ) , V_122 ) ;
}
STATIC int
F_99 (
struct V_7 * V_8 )
{
int V_246 = ( V_8 -> V_27 & V_28 ) ;
if ( F_100 ( & V_8 -> V_159 ) ) {
if ( V_8 -> V_37 <= 0 &&
V_8 -> V_159 . V_247 > V_248 ) {
V_8 -> V_37 = V_8 -> V_159 . V_247 ;
} else if ( V_8 -> V_37 > 0 &&
V_8 -> V_37 < V_8 -> V_159 . V_247 ) {
F_6 ( V_8 ,
L_34 ) ;
return F_10 ( V_40 ) ;
}
} else {
if ( V_8 -> V_37 > V_248 ) {
F_6 ( V_8 ,
L_35 ) ;
return F_10 ( V_40 ) ;
}
}
if ( F_101 ( & V_8 -> V_159 ) &&
! ( V_8 -> V_27 & V_77 ) )
V_8 -> V_27 |= V_75 ;
if ( ( V_8 -> V_159 . V_249 & V_250 ) && ! V_246 ) {
F_6 ( V_8 ,
L_36 ) ;
return F_10 ( V_251 ) ;
}
return 0 ;
}
STATIC int
F_102 (
struct V_10 * V_11 ,
void * V_252 ,
int V_253 )
{
struct V_171 * V_245 ;
struct V_7 * V_8 = NULL ;
int V_237 = 0 , error = V_23 ;
V_8 = F_103 ( sizeof( struct V_7 ) , V_22 ) ;
if ( ! V_8 )
goto V_154;
F_52 ( & V_8 -> V_215 ) ;
F_104 ( & V_8 -> V_254 ) ;
F_51 ( & V_8 -> V_255 , 0 ) ;
V_8 -> V_12 = V_11 ;
V_11 -> V_256 = V_8 ;
error = F_3 ( V_8 , ( char * ) V_252 ) ;
if ( error )
goto V_257;
F_105 ( V_11 , V_163 ) ;
V_11 -> V_258 = V_259 ;
V_11 -> V_260 = & V_261 ;
#ifdef F_8
V_11 -> V_262 = & V_263 ;
#endif
V_11 -> V_264 = & V_265 ;
if ( V_253 )
V_237 |= V_266 ;
error = F_28 ( V_8 ) ;
if ( error )
goto V_257;
error = F_33 ( V_8 ) ;
if ( error )
goto V_267;
error = F_106 ( V_8 ) ;
if ( error )
goto V_268;
error = F_107 ( V_8 , V_237 ) ;
if ( error )
goto V_269;
error = F_99 ( V_8 ) ;
if ( error )
goto V_270;
error = F_30 ( V_8 ) ;
if ( error )
goto V_270;
error = F_108 ( V_8 ) ;
if ( error )
goto V_270;
V_11 -> V_271 = V_208 ;
V_11 -> V_272 = V_8 -> V_159 . V_160 ;
V_11 -> V_273 = F_7 ( V_11 -> V_272 ) - 1 ;
V_11 -> V_274 = F_16 ( V_11 -> V_273 ) ;
V_11 -> V_275 = V_276 ;
V_11 -> V_277 = 1 ;
F_109 ( V_11 ) ;
error = F_110 ( V_8 ) ;
if ( error )
goto V_278;
error = F_111 ( V_8 ) ;
if ( error )
goto V_279;
V_245 = F_112 ( F_50 ( V_8 -> V_280 ) ) ;
if ( ! V_245 ) {
error = V_281 ;
goto V_282;
}
if ( F_43 ( V_245 ) ) {
error = V_40 ;
goto V_282;
}
V_11 -> V_283 = F_113 ( V_245 ) ;
if ( ! V_11 -> V_283 ) {
error = V_23 ;
goto V_282;
}
return 0 ;
V_279:
F_70 ( V_8 ) ;
V_278:
F_67 ( V_8 ) ;
V_270:
F_71 ( V_8 ) ;
V_269:
F_72 ( V_8 ) ;
V_268:
F_36 ( V_8 ) ;
V_267:
F_26 ( V_8 ) ;
V_257:
F_63 ( V_8 ) ;
F_64 ( V_8 ) ;
V_154:
return - error ;
V_282:
F_67 ( V_8 ) ;
F_69 ( V_8 ) ;
F_70 ( V_8 ) ;
goto V_270;
}
STATIC struct V_197 *
F_114 (
struct V_284 * V_285 ,
int V_237 ,
const char * V_286 ,
void * V_252 )
{
return F_115 ( V_285 , V_237 , V_286 , V_252 , F_102 ) ;
}
static int
F_116 (
struct V_10 * V_11 )
{
return F_117 ( F_66 ( V_11 ) ) ;
}
static void
F_118 (
struct V_10 * V_11 ,
int V_287 )
{
F_119 ( F_66 ( V_11 ) , V_287 ) ;
}
STATIC int T_10
F_120 ( void )
{
V_288 = F_121 ( sizeof( V_289 ) , L_37 ) ;
if ( ! V_288 )
goto V_154;
V_290 = F_122 ( 4 * V_291 ,
V_288 ) ;
if ( ! V_290 )
goto V_292;
V_293 = F_121 ( sizeof( V_294 ) ,
L_38 ) ;
if ( ! V_293 )
goto V_295;
V_296 = F_121 ( sizeof( V_297 ) ,
L_39 ) ;
if ( ! V_296 )
goto V_298;
V_299 = F_121 ( sizeof( V_300 ) ,
L_40 ) ;
if ( ! V_299 )
goto V_301;
V_302 = F_121 ( sizeof( V_303 ) ,
L_41 ) ;
if ( ! V_302 )
goto V_304;
V_305 = F_121 ( sizeof( V_306 ) , L_42 ) ;
if ( ! V_305 )
goto V_307;
V_308 = F_121 ( sizeof( V_309 ) , L_43 ) ;
if ( ! V_308 )
goto V_310;
V_311 =
F_121 ( sizeof( struct V_312 ) ,
L_44 ) ;
if ( ! V_311 )
goto V_313;
V_314 = F_121 ( sizeof( struct V_315 ) ,
L_45 ) ;
if ( ! V_314 )
goto V_316;
V_317 = F_121 ( ( sizeof( V_318 ) +
( ( V_319 - 1 ) *
sizeof( V_320 ) ) ) , L_46 ) ;
if ( ! V_317 )
goto V_321;
V_322 = F_121 ( ( sizeof( V_323 ) +
( ( V_324 - 1 ) *
sizeof( V_320 ) ) ) , L_47 ) ;
if ( ! V_322 )
goto V_325;
V_326 =
F_123 ( sizeof( T_5 ) , L_48 ,
V_327 | V_328 | V_329 ,
F_48 ) ;
if ( ! V_326 )
goto V_330;
V_331 =
F_123 ( sizeof( V_332 ) , L_49 ,
V_329 , NULL ) ;
if ( ! V_331 )
goto V_333;
return 0 ;
V_333:
F_124 ( V_326 ) ;
V_330:
F_124 ( V_322 ) ;
V_325:
F_124 ( V_317 ) ;
V_321:
F_124 ( V_314 ) ;
V_316:
F_124 ( V_311 ) ;
V_313:
F_124 ( V_308 ) ;
V_310:
F_124 ( V_305 ) ;
V_307:
F_124 ( V_302 ) ;
V_304:
F_124 ( V_299 ) ;
V_301:
F_124 ( V_296 ) ;
V_298:
F_124 ( V_293 ) ;
V_295:
F_125 ( V_290 ) ;
V_292:
F_124 ( V_288 ) ;
V_154:
return - V_23 ;
}
STATIC void
F_126 ( void )
{
F_124 ( V_331 ) ;
F_124 ( V_326 ) ;
F_124 ( V_322 ) ;
F_124 ( V_317 ) ;
F_124 ( V_314 ) ;
F_124 ( V_311 ) ;
F_124 ( V_308 ) ;
F_124 ( V_305 ) ;
F_124 ( V_302 ) ;
F_124 ( V_299 ) ;
F_124 ( V_296 ) ;
F_124 ( V_293 ) ;
F_125 ( V_290 ) ;
F_124 ( V_288 ) ;
}
STATIC int T_10
F_127 ( void )
{
V_334 = F_34 ( L_50 , V_335 , 0 ) ;
if ( ! V_334 )
return - V_23 ;
V_336 = F_34 ( L_51 , V_166 , 0 ) ;
if ( ! V_336 )
goto V_337;
return 0 ;
V_337:
F_35 ( V_334 ) ;
return - V_23 ;
}
STATIC void
F_128 ( void )
{
F_35 ( V_336 ) ;
F_35 ( V_334 ) ;
}
STATIC int T_10
F_129 ( void )
{
int error ;
F_130 (KERN_INFO XFS_VERSION_STRING L_52
XFS_BUILD_OPTIONS L_53 ) ;
F_131 () ;
error = F_120 () ;
if ( error )
goto V_154;
error = F_127 () ;
if ( error )
goto V_338;
error = F_132 () ;
if ( error )
goto V_339;
error = F_133 () ;
if ( error )
goto V_340;
error = F_134 () ;
if ( error )
goto V_341;
error = F_135 () ;
if ( error )
goto V_342;
error = F_136 () ;
if ( error )
goto V_343;
error = F_137 () ;
if ( error )
goto V_344;
error = F_138 ( & V_345 ) ;
if ( error )
goto V_346;
return 0 ;
V_346:
F_139 () ;
V_344:
F_140 () ;
V_343:
F_141 () ;
V_342:
F_142 () ;
V_341:
F_143 () ;
V_340:
F_144 () ;
V_339:
F_128 () ;
V_338:
F_126 () ;
V_154:
return error ;
}
STATIC void T_11
F_145 ( void )
{
F_139 () ;
F_146 ( & V_345 ) ;
F_140 () ;
F_141 () ;
F_142 () ;
F_143 () ;
F_144 () ;
F_128 () ;
F_126 () ;
}
