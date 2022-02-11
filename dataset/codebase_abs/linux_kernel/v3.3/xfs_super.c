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
V_8 -> V_81 &= ~ ( V_82 | V_83 |
V_84 | V_85 |
V_86 | V_87 |
V_88 | V_89 ) ;
} else if ( ! strcmp ( V_13 , V_90 ) ||
! strcmp ( V_13 , V_91 ) ||
! strcmp ( V_13 , V_92 ) ) {
V_8 -> V_81 |= ( V_82 | V_83 |
V_88 ) ;
} else if ( ! strcmp ( V_13 , V_93 ) ||
! strcmp ( V_13 , V_94 ) ) {
V_8 -> V_81 |= ( V_82 | V_83 ) ;
V_8 -> V_81 &= ~ V_88 ;
} else if ( ! strcmp ( V_13 , V_95 ) ||
! strcmp ( V_13 , V_96 ) ) {
V_8 -> V_81 |= ( V_86 | V_87 |
V_89 ) ;
} else if ( ! strcmp ( V_13 , V_97 ) ) {
V_8 -> V_81 |= ( V_86 | V_87 ) ;
V_8 -> V_81 &= ~ V_89 ;
} else if ( ! strcmp ( V_13 , V_98 ) ||
! strcmp ( V_13 , V_99 ) ) {
V_8 -> V_81 |= ( V_84 | V_85 |
V_89 ) ;
} else if ( ! strcmp ( V_13 , V_100 ) ) {
V_8 -> V_81 |= ( V_84 | V_85 ) ;
V_8 -> V_81 &= ~ V_89 ;
} else if ( ! strcmp ( V_13 , V_101 ) ) {
F_6 ( V_8 ,
L_4 ) ;
} else if ( ! strcmp ( V_13 , V_102 ) ) {
F_6 ( V_8 ,
L_5 ) ;
} else if ( ! strcmp ( V_13 , V_103 ) ) {
V_8 -> V_27 |= V_104 ;
} else if ( ! strcmp ( V_13 , V_105 ) ) {
V_8 -> V_27 &= ~ V_104 ;
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
if ( ( V_8 -> V_81 & ( V_84 | V_85 ) ) &&
( V_8 -> V_81 & ( V_86 | V_87 ) ) ) {
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
V_8 -> V_106 = V_15 ;
V_8 -> V_27 |= V_107 ;
}
if ( V_16 )
V_8 -> V_108 = V_16 ;
}
if ( V_8 -> V_36 != - 1 &&
V_8 -> V_36 != 0 &&
( V_8 -> V_36 < V_109 ||
V_8 -> V_36 > V_110 ) ) {
F_6 ( V_8 , L_21 ,
V_8 -> V_36 , V_109 , V_110 ) ;
return F_10 ( V_40 ) ;
}
if ( V_8 -> V_37 != - 1 &&
V_8 -> V_37 != 0 &&
( V_8 -> V_37 < V_111 ||
V_8 -> V_37 > V_112 ||
! F_11 ( V_8 -> V_37 ) ) ) {
F_6 ( V_8 ,
L_22 ,
V_8 -> V_37 ) ;
return F_10 ( V_40 ) ;
}
if ( V_18 ) {
if ( V_18 > V_113 ||
V_18 < V_114 ) {
F_6 ( V_8 , L_23 ,
V_18 , V_114 ,
V_113 ) ;
return F_10 ( V_40 ) ;
}
V_8 -> V_27 |= V_115 ;
V_8 -> V_116 = V_18 ;
V_8 -> V_117 = V_18 ;
}
return 0 ;
}
STATIC int
F_12 (
struct V_7 * V_8 ,
struct V_118 * V_119 )
{
static struct V_120 V_121 [] = {
{ V_70 , L_1 V_69 } ,
{ V_32 , L_1 V_54 } ,
{ V_58 , L_1 V_57 } ,
{ V_60 , L_1 V_59 } ,
{ V_66 , L_1 V_65 } ,
{ V_56 , L_1 V_55 } ,
{ V_75 , L_1 V_74 } ,
{ V_79 , L_1 V_78 } ,
{ V_51 , L_1 V_49 } ,
{ V_104 , L_1 V_103 } ,
{ 0 , NULL }
} ;
static struct V_120 V_122 [] = {
{ V_34 , L_1 V_72 } ,
{ V_33 , L_1 V_68 } ,
{ V_35 , L_1 V_63 } ,
{ 0 , NULL }
} ;
struct V_120 * V_123 ;
for ( V_123 = V_121 ; V_123 -> V_124 ; V_123 ++ ) {
if ( V_8 -> V_27 & V_123 -> V_124 )
F_13 ( V_119 , V_123 -> V_125 ) ;
}
for ( V_123 = V_122 ; V_123 -> V_124 ; V_123 ++ ) {
if ( ! ( V_8 -> V_27 & V_123 -> V_124 ) )
F_13 ( V_119 , V_123 -> V_125 ) ;
}
if ( V_8 -> V_27 & V_115 )
F_14 ( V_119 , L_1 V_48 L_24 ,
( int ) ( 1 << V_8 -> V_117 ) >> 10 ) ;
if ( V_8 -> V_36 > 0 )
F_14 ( V_119 , L_1 V_39 L_25 , V_8 -> V_36 ) ;
if ( V_8 -> V_37 > 0 )
F_14 ( V_119 , L_1 V_41 L_24 , V_8 -> V_37 >> 10 ) ;
if ( V_8 -> V_43 )
F_14 ( V_119 , L_1 V_42 L_26 , V_8 -> V_43 ) ;
if ( V_8 -> V_46 )
F_14 ( V_119 , L_1 V_45 L_26 , V_8 -> V_46 ) ;
if ( V_8 -> V_106 > 0 )
F_14 ( V_119 , L_1 V_61 L_25 ,
( int ) F_15 ( V_8 , V_8 -> V_106 ) ) ;
if ( V_8 -> V_108 > 0 )
F_14 ( V_119 , L_1 V_62 L_25 ,
( int ) F_15 ( V_8 , V_8 -> V_108 ) ) ;
if ( V_8 -> V_81 & ( V_82 | V_88 ) )
F_13 ( V_119 , L_1 V_92 ) ;
else if ( V_8 -> V_81 & V_82 )
F_13 ( V_119 , L_1 V_94 ) ;
if ( V_8 -> V_81 & V_86 ) {
if ( V_8 -> V_81 & V_89 )
F_13 ( V_119 , L_1 V_96 ) ;
else
F_13 ( V_119 , L_1 V_97 ) ;
} else if ( V_8 -> V_81 & V_84 ) {
if ( V_8 -> V_81 & V_89 )
F_13 ( V_119 , L_1 V_99 ) ;
else
F_13 ( V_119 , L_1 V_100 ) ;
}
if ( ! ( V_8 -> V_81 & V_126 ) )
F_13 ( V_119 , L_1 V_80 ) ;
return 0 ;
}
T_2
F_16 (
unsigned int V_127 )
{
unsigned int V_128 = 1 ;
unsigned int V_129 = V_130 - 1 ;
#if V_130 == 32
# if F_17 ( V_131 )
ASSERT ( sizeof( V_132 ) == 8 ) ;
V_128 = V_133 ;
V_129 = V_130 ;
# else
V_128 = V_133 >> ( V_134 - V_127 ) ;
# endif
#endif
return ( ( ( T_2 ) V_128 ) << V_129 ) - 1 ;
}
STATIC int
F_18 (
T_3 * V_8 ,
const char * V_135 ,
struct V_136 * * V_137 )
{
int error = 0 ;
* V_137 = F_19 ( V_135 , V_138 | V_139 | V_140 ,
V_8 ) ;
if ( F_20 ( * V_137 ) ) {
error = F_21 ( * V_137 ) ;
F_6 ( V_8 , L_27 , V_135 , error ) ;
}
return - error ;
}
STATIC void
F_22 (
struct V_136 * V_141 )
{
if ( V_141 )
F_23 ( V_141 , V_138 | V_139 | V_140 ) ;
}
void
F_24 (
T_4 * V_142 )
{
F_25 ( V_142 -> V_143 , V_22 , NULL ) ;
}
STATIC void
F_26 (
struct V_7 * V_8 )
{
if ( V_8 -> V_144 && V_8 -> V_144 != V_8 -> V_145 ) {
struct V_136 * V_146 = V_8 -> V_144 -> V_143 ;
F_27 ( V_8 , V_8 -> V_144 ) ;
F_22 ( V_146 ) ;
}
if ( V_8 -> V_147 ) {
struct V_136 * V_148 = V_8 -> V_147 -> V_143 ;
F_27 ( V_8 , V_8 -> V_147 ) ;
F_22 ( V_148 ) ;
}
F_27 ( V_8 , V_8 -> V_145 ) ;
}
STATIC int
F_28 (
struct V_7 * V_8 )
{
struct V_136 * V_149 = V_8 -> V_12 -> V_150 ;
struct V_136 * V_146 = NULL , * V_148 = NULL ;
int error ;
if ( V_8 -> V_43 ) {
error = F_18 ( V_8 , V_8 -> V_43 , & V_146 ) ;
if ( error )
goto V_151;
}
if ( V_8 -> V_46 ) {
error = F_18 ( V_8 , V_8 -> V_46 , & V_148 ) ;
if ( error )
goto V_152;
if ( V_148 == V_149 || V_148 == V_146 ) {
F_6 ( V_8 ,
L_28 ) ;
error = V_40 ;
goto V_153;
}
}
error = V_23 ;
V_8 -> V_145 = F_29 ( V_8 , V_149 , 0 , V_8 -> V_19 ) ;
if ( ! V_8 -> V_145 )
goto V_153;
if ( V_148 ) {
V_8 -> V_147 = F_29 ( V_8 , V_148 , 1 ,
V_8 -> V_19 ) ;
if ( ! V_8 -> V_147 )
goto V_154;
}
if ( V_146 && V_146 != V_149 ) {
V_8 -> V_144 = F_29 ( V_8 , V_146 , 1 ,
V_8 -> V_19 ) ;
if ( ! V_8 -> V_144 )
goto V_155;
} else {
V_8 -> V_144 = V_8 -> V_145 ;
}
return 0 ;
V_155:
if ( V_8 -> V_147 )
F_27 ( V_8 , V_8 -> V_147 ) ;
V_154:
F_27 ( V_8 , V_8 -> V_145 ) ;
V_153:
if ( V_148 )
F_22 ( V_148 ) ;
V_152:
if ( V_146 && V_146 != V_149 )
F_22 ( V_146 ) ;
V_151:
return error ;
}
STATIC int
F_30 (
struct V_7 * V_8 )
{
int error ;
error = F_31 ( V_8 -> V_145 , V_8 -> V_156 . V_157 ,
V_8 -> V_156 . V_158 ) ;
if ( error )
return error ;
if ( V_8 -> V_144 && V_8 -> V_144 != V_8 -> V_145 ) {
unsigned int V_159 = V_160 ;
if ( F_32 ( & V_8 -> V_156 ) )
V_159 = V_8 -> V_156 . V_161 ;
error = F_31 ( V_8 -> V_144 ,
V_8 -> V_156 . V_157 ,
V_159 ) ;
if ( error )
return error ;
}
if ( V_8 -> V_147 ) {
error = F_31 ( V_8 -> V_147 ,
V_8 -> V_156 . V_157 ,
V_8 -> V_156 . V_158 ) ;
if ( error )
return error ;
}
return 0 ;
}
STATIC struct V_162 *
F_33 (
struct V_10 * V_11 )
{
F_34 () ;
return NULL ;
}
STATIC void
F_35 (
struct V_162 * V_162 )
{
struct V_163 * V_164 = F_36 ( V_162 ) ;
F_37 ( V_164 ) ;
F_38 ( V_165 ) ;
if ( F_39 ( V_162 ) )
goto V_166;
ASSERT ( F_40 ( V_164 -> V_167 ) || V_164 -> V_168 == 0 ) ;
F_41 ( ! F_42 ( V_164 , V_169 ) ) ;
F_41 ( ! F_42 ( V_164 , V_170 ) ) ;
V_166:
F_43 ( V_164 ) ;
}
STATIC void
F_44 (
void * V_162 )
{
struct V_163 * V_164 = V_162 ;
memset ( V_164 , 0 , sizeof( struct V_163 ) ) ;
F_45 ( F_46 ( V_164 ) ) ;
F_47 ( & V_164 -> V_171 , 0 ) ;
F_48 ( & V_164 -> V_172 ) ;
F_49 ( & V_164 -> V_173 , V_174 | V_175 ,
L_29 , V_164 -> V_176 ) ;
}
STATIC void
F_50 (
struct V_162 * V_162 ,
int V_177 )
{
F_51 () ;
F_36 ( V_162 ) -> V_178 = 1 ;
}
STATIC int
F_52 (
struct V_162 * V_162 ,
struct V_179 * V_180 )
{
struct V_163 * V_164 = F_36 ( V_162 ) ;
struct V_7 * V_8 = V_164 -> V_167 ;
int error = V_181 ;
F_53 ( V_164 ) ;
if ( F_40 ( V_8 ) )
return - F_10 ( V_182 ) ;
if ( V_180 -> V_183 == V_184 || V_180 -> V_185 ) {
error = F_54 ( V_164 , NULL , 0 ) ;
if ( error )
goto V_151;
return 0 ;
} else {
if ( ! V_164 -> V_178 )
return 0 ;
if ( ! F_55 ( V_164 , V_186 ) )
goto V_151;
if ( F_56 ( V_164 ) || ! F_57 ( V_164 ) )
goto V_187;
if ( F_58 ( V_164 ) ) {
F_59 ( V_164 ) ;
error = 0 ;
goto V_187;
}
error = F_60 ( V_164 , V_188 ) ;
}
V_187:
F_61 ( V_164 , V_186 ) ;
V_151:
if ( error )
F_62 ( V_164 ) ;
return - error ;
}
STATIC void
F_63 (
struct V_162 * V_162 )
{
T_5 * V_164 = F_36 ( V_162 ) ;
F_64 ( V_164 ) ;
F_65 ( & V_162 -> V_189 , 0 ) ;
F_66 ( V_162 ) ;
F_38 ( V_190 ) ;
F_38 ( V_191 ) ;
F_67 ( V_192 ) ;
ASSERT ( ! F_68 ( & V_164 -> V_193 . V_194 ) ) ;
F_49 ( & V_164 -> V_193 , V_175 , L_30 , V_164 -> V_176 ) ;
F_69 ( & V_164 -> V_193 . V_194 ,
& V_195 , L_31 ) ;
F_70 ( V_164 ) ;
}
STATIC void
F_71 (
struct V_7 * V_8 )
{
F_72 ( V_8 -> V_19 ) ;
F_72 ( V_8 -> V_46 ) ;
F_72 ( V_8 -> V_43 ) ;
}
STATIC void
F_73 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_74 ( V_11 ) ;
F_75 ( V_8 ) ;
F_76 ( V_8 ) ;
F_77 ( V_8 -> V_145 , 1 ) ;
F_78 ( V_8 ) ;
F_79 ( V_8 ) ;
F_80 ( V_8 ) ;
F_26 ( V_8 ) ;
F_71 ( V_8 ) ;
F_72 ( V_8 ) ;
}
STATIC int
F_81 (
struct V_10 * V_11 ,
int V_196 )
{
struct V_7 * V_8 = F_74 ( V_11 ) ;
int error ;
if ( ! V_196 )
return 0 ;
error = F_82 ( V_8 ) ;
if ( error )
return - error ;
if ( V_197 ) {
F_83 ( & V_8 -> V_198 ) ;
}
return 0 ;
}
STATIC int
F_84 (
struct V_199 * V_199 ,
struct V_200 * V_201 )
{
struct V_7 * V_8 = F_74 ( V_199 -> V_202 ) ;
T_6 * V_203 = & V_8 -> V_156 ;
struct V_163 * V_164 = F_36 ( V_199 -> V_204 ) ;
T_2 V_205 , V_206 ;
T_7 V_207 ;
T_8 V_208 ;
V_201 -> V_209 = V_210 ;
V_201 -> V_211 = V_21 - 1 ;
V_206 = F_85 ( V_8 -> V_145 -> V_212 ) ;
V_201 -> V_213 . V_214 [ 0 ] = ( V_215 ) V_206 ;
V_201 -> V_213 . V_214 [ 1 ] = ( V_215 ) ( V_206 >> 32 ) ;
F_86 ( V_8 , V_216 ) ;
F_87 ( & V_8 -> V_217 ) ;
V_201 -> V_218 = V_203 -> V_157 ;
V_207 = V_203 -> V_219 ? V_203 -> V_220 : 0 ;
V_201 -> V_221 = V_203 -> V_222 - V_207 ;
V_201 -> V_223 = V_201 -> V_224 =
V_203 -> V_225 - F_88 ( V_8 ) ;
V_205 = V_201 -> V_223 << V_203 -> V_226 ;
V_201 -> V_227 =
F_89 ( V_203 -> V_228 + V_205 , ( T_2 ) V_229 ) ;
if ( V_8 -> V_230 )
V_201 -> V_227 = F_90 ( F_91 ( V_201 -> V_227 ) ,
V_201 -> V_227 ,
V_8 -> V_230 ) ;
V_208 = V_201 -> V_227 - ( V_203 -> V_228 - V_203 -> V_231 ) ;
V_201 -> V_232 = F_92 ( T_8 , V_208 , 0 ) ;
F_93 ( & V_8 -> V_217 ) ;
if ( ( V_164 -> V_233 . V_234 & V_235 ) ||
( ( V_8 -> V_81 & ( V_86 | V_89 ) ) ) ==
( V_86 | V_89 ) )
F_94 ( V_164 , V_201 ) ;
return 0 ;
}
STATIC void
F_95 ( struct V_7 * V_8 )
{
T_2 V_236 = 0 ;
V_8 -> V_237 = V_8 -> V_238 ;
F_96 ( V_8 , & V_236 , NULL ) ;
}
STATIC void
F_97 ( struct V_7 * V_8 )
{
T_2 V_236 ;
if ( V_8 -> V_237 ) {
V_236 = V_8 -> V_237 ;
V_8 -> V_237 = 0 ;
} else
V_236 = F_98 ( V_8 ) ;
F_96 ( V_8 , & V_236 , NULL ) ;
}
STATIC int
F_99 (
struct V_10 * V_11 ,
int * V_177 ,
char * V_9 )
{
struct V_7 * V_8 = F_74 ( V_11 ) ;
T_9 args [ V_239 ] ;
char * V_240 ;
int error ;
while ( ( V_240 = F_5 ( & V_9 , L_1 ) ) != NULL ) {
int V_241 ;
if ( ! * V_240 )
continue;
V_241 = F_100 ( V_240 , V_242 , args ) ;
switch ( V_241 ) {
case V_243 :
V_8 -> V_27 |= V_33 ;
break;
case V_244 :
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
if ( ( V_8 -> V_27 & V_28 ) && ! ( * V_177 & V_26 ) ) {
V_8 -> V_27 &= ~ V_28 ;
if ( V_8 -> V_245 ) {
error = F_101 ( V_8 , V_8 -> V_245 ) ;
if ( error ) {
F_6 ( V_8 , L_32 ) ;
return error ;
}
V_8 -> V_245 = 0 ;
}
F_97 ( V_8 ) ;
}
if ( ! ( V_8 -> V_27 & V_28 ) && ( * V_177 & V_26 ) ) {
F_82 ( V_8 ) ;
F_95 ( V_8 ) ;
F_102 ( V_8 ) ;
V_8 -> V_27 |= V_28 ;
}
return 0 ;
}
STATIC int
F_103 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_74 ( V_11 ) ;
F_95 ( V_8 ) ;
F_102 ( V_8 ) ;
return - F_104 ( V_8 ) ;
}
STATIC int
F_105 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_74 ( V_11 ) ;
F_97 ( V_8 ) ;
return 0 ;
}
STATIC int
F_106 (
struct V_118 * V_119 ,
struct V_199 * V_246 )
{
return - F_12 ( F_74 ( V_246 -> V_202 ) , V_119 ) ;
}
STATIC int
F_107 (
struct V_7 * V_8 )
{
int V_247 = ( V_8 -> V_27 & V_28 ) ;
if ( F_108 ( & V_8 -> V_156 ) ) {
if ( V_8 -> V_37 <= 0 &&
V_8 -> V_156 . V_248 > V_249 ) {
V_8 -> V_37 = V_8 -> V_156 . V_248 ;
} else if ( V_8 -> V_37 > 0 &&
V_8 -> V_37 < V_8 -> V_156 . V_248 ) {
F_6 ( V_8 ,
L_33 ) ;
return F_10 ( V_40 ) ;
}
} else {
if ( V_8 -> V_37 > V_249 ) {
F_6 ( V_8 ,
L_34 ) ;
return F_10 ( V_40 ) ;
}
}
if ( F_109 ( & V_8 -> V_156 ) &&
! ( V_8 -> V_27 & V_77 ) )
V_8 -> V_27 |= V_75 ;
if ( ( V_8 -> V_156 . V_250 & V_251 ) && ! V_247 ) {
F_6 ( V_8 ,
L_35 ) ;
return F_10 ( V_252 ) ;
}
return 0 ;
}
STATIC int
F_110 (
struct V_10 * V_11 ,
void * V_253 ,
int V_254 )
{
struct V_162 * V_246 ;
struct V_7 * V_8 = NULL ;
int V_177 = 0 , error = V_23 ;
V_8 = F_111 ( sizeof( struct V_7 ) , V_22 ) ;
if ( ! V_8 )
goto V_151;
F_48 ( & V_8 -> V_217 ) ;
F_112 ( & V_8 -> V_255 ) ;
F_47 ( & V_8 -> V_256 , 0 ) ;
V_8 -> V_12 = V_11 ;
V_11 -> V_257 = V_8 ;
error = F_3 ( V_8 , ( char * ) V_253 ) ;
if ( error )
goto V_258;
F_113 ( V_11 , V_160 ) ;
V_11 -> V_259 = V_260 ;
V_11 -> V_261 = & V_262 ;
#ifdef F_8
V_11 -> V_263 = & V_264 ;
#endif
V_11 -> V_265 = & V_266 ;
if ( V_254 )
V_177 |= V_267 ;
error = F_28 ( V_8 ) ;
if ( error )
goto V_258;
error = F_114 ( V_8 ) ;
if ( error )
goto V_268;
error = F_115 ( V_8 , V_177 ) ;
if ( error )
goto V_269;
error = F_107 ( V_8 ) ;
if ( error )
goto V_270;
error = F_30 ( V_8 ) ;
if ( error )
goto V_270;
error = F_116 ( V_8 ) ;
if ( error )
goto V_270;
V_11 -> V_271 = V_210 ;
V_11 -> V_272 = V_8 -> V_156 . V_157 ;
V_11 -> V_273 = F_7 ( V_11 -> V_272 ) - 1 ;
V_11 -> V_274 = F_16 ( V_11 -> V_273 ) ;
V_11 -> V_275 = 1 ;
F_117 ( V_11 ) ;
error = F_118 ( V_8 ) ;
if ( error )
goto V_276;
error = F_119 ( V_8 ) ;
if ( error )
goto V_277;
V_246 = F_120 ( F_46 ( V_8 -> V_278 ) ) ;
if ( ! V_246 ) {
error = V_279 ;
goto V_280;
}
if ( F_39 ( V_246 ) ) {
error = V_40 ;
goto V_280;
}
V_11 -> V_281 = F_121 ( V_246 ) ;
if ( ! V_11 -> V_281 ) {
error = V_23 ;
goto V_282;
}
return 0 ;
V_276:
F_76 ( V_8 ) ;
V_270:
F_79 ( V_8 ) ;
V_269:
F_80 ( V_8 ) ;
V_268:
F_26 ( V_8 ) ;
V_258:
F_71 ( V_8 ) ;
F_72 ( V_8 ) ;
V_151:
return - error ;
V_282:
F_122 ( V_246 ) ;
V_280:
F_75 ( V_8 ) ;
V_277:
F_76 ( V_8 ) ;
F_77 ( V_8 -> V_145 , 1 ) ;
F_78 ( V_8 ) ;
goto V_270;
}
STATIC struct V_199 *
F_123 (
struct V_283 * V_284 ,
int V_177 ,
const char * V_285 ,
void * V_253 )
{
return F_124 ( V_284 , V_177 , V_285 , V_253 , F_110 ) ;
}
static int
F_125 (
struct V_10 * V_11 )
{
return F_126 ( F_74 ( V_11 ) ) ;
}
static void
F_127 (
struct V_10 * V_11 ,
int V_286 )
{
F_128 ( F_74 ( V_11 ) , V_286 ) ;
}
STATIC int T_10
F_129 ( void )
{
V_287 = F_130 ( sizeof( V_288 ) , L_36 ) ;
if ( ! V_287 )
goto V_151;
V_289 = F_131 ( 4 * V_290 ,
V_287 ) ;
if ( ! V_289 )
goto V_291;
V_292 = F_130 ( sizeof( V_293 ) ,
L_37 ) ;
if ( ! V_292 )
goto V_294;
V_295 = F_130 ( sizeof( V_296 ) ,
L_38 ) ;
if ( ! V_295 )
goto V_297;
V_298 = F_130 ( sizeof( V_299 ) ,
L_39 ) ;
if ( ! V_298 )
goto V_300;
V_301 = F_130 ( sizeof( V_302 ) ,
L_40 ) ;
if ( ! V_301 )
goto V_303;
V_304 = F_130 ( sizeof( V_305 ) , L_41 ) ;
if ( ! V_304 )
goto V_306;
V_307 = F_130 ( sizeof( V_308 ) , L_42 ) ;
if ( ! V_307 )
goto V_309;
V_310 = F_130 ( sizeof( V_311 ) , L_43 ) ;
if ( ! V_310 )
goto V_312;
V_313 =
F_130 ( sizeof( struct V_314 ) ,
L_44 ) ;
if ( ! V_313 )
goto V_315;
V_316 = F_130 ( ( sizeof( V_317 ) +
( ( ( V_318 / V_319 ) /
V_320 ) * sizeof( int ) ) ) , L_45 ) ;
if ( ! V_316 )
goto V_321;
V_322 = F_130 ( ( sizeof( V_323 ) +
( ( V_324 - 1 ) *
sizeof( V_325 ) ) ) , L_46 ) ;
if ( ! V_322 )
goto V_326;
V_327 = F_130 ( ( sizeof( V_328 ) +
( ( V_329 - 1 ) *
sizeof( V_325 ) ) ) , L_47 ) ;
if ( ! V_327 )
goto V_330;
V_331 =
F_132 ( sizeof( T_5 ) , L_48 ,
V_332 | V_333 | V_334 ,
F_44 ) ;
if ( ! V_331 )
goto V_335;
V_336 =
F_132 ( sizeof( V_337 ) , L_49 ,
V_334 , NULL ) ;
if ( ! V_336 )
goto V_338;
return 0 ;
V_338:
F_133 ( V_331 ) ;
V_335:
F_133 ( V_327 ) ;
V_330:
F_133 ( V_322 ) ;
V_326:
F_133 ( V_316 ) ;
V_321:
F_133 ( V_313 ) ;
V_315:
F_133 ( V_310 ) ;
V_312:
F_133 ( V_307 ) ;
V_309:
F_133 ( V_304 ) ;
V_306:
F_133 ( V_301 ) ;
V_303:
F_133 ( V_298 ) ;
V_300:
F_133 ( V_295 ) ;
V_297:
F_133 ( V_292 ) ;
V_294:
F_134 ( V_289 ) ;
V_291:
F_133 ( V_287 ) ;
V_151:
return - V_23 ;
}
STATIC void
F_135 ( void )
{
F_133 ( V_336 ) ;
F_133 ( V_331 ) ;
F_133 ( V_327 ) ;
F_133 ( V_322 ) ;
F_133 ( V_316 ) ;
F_133 ( V_313 ) ;
F_133 ( V_310 ) ;
F_133 ( V_307 ) ;
F_133 ( V_304 ) ;
F_133 ( V_301 ) ;
F_133 ( V_298 ) ;
F_133 ( V_295 ) ;
F_133 ( V_292 ) ;
F_134 ( V_289 ) ;
F_133 ( V_287 ) ;
}
STATIC int T_10
F_136 ( void )
{
V_339 = F_137 ( L_50 , V_340 , 0 ) ;
if ( ! V_339 )
return - V_23 ;
return 0 ;
}
STATIC void
F_138 ( void )
{
F_139 ( V_339 ) ;
}
STATIC int T_10
F_140 ( void )
{
int error ;
F_141 (KERN_INFO XFS_VERSION_STRING L_51
XFS_BUILD_OPTIONS L_52 ) ;
F_142 () ;
error = F_129 () ;
if ( error )
goto V_151;
error = F_136 () ;
if ( error )
goto V_341;
error = F_143 () ;
if ( error )
goto V_342;
error = F_144 () ;
if ( error )
goto V_343;
error = F_145 () ;
if ( error )
goto V_344;
error = F_146 () ;
if ( error )
goto V_345;
error = F_147 () ;
if ( error )
goto V_346;
F_148 () ;
error = F_149 ( & V_347 ) ;
if ( error )
goto V_348;
return 0 ;
V_348:
F_150 () ;
V_346:
F_151 () ;
V_345:
F_152 () ;
V_344:
F_153 () ;
V_343:
F_154 () ;
V_342:
F_138 () ;
V_341:
F_135 () ;
V_151:
return error ;
}
STATIC void T_11
F_155 ( void )
{
F_156 () ;
F_157 ( & V_347 ) ;
F_150 () ;
F_151 () ;
F_152 () ;
F_153 () ;
F_154 () ;
F_138 () ;
F_135 () ;
}
