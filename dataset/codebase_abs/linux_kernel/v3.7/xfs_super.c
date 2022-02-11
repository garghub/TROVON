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
#if ! V_35
V_8 -> V_27 |= V_36 ;
#endif
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
V_8 -> V_27 |= V_36 ;
} else if ( ! strcmp ( V_13 , V_65 ) ) {
V_8 -> V_27 &= ~ V_36 ;
#if ! V_35
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
V_8 -> V_82 &= ~ V_83 ;
V_8 -> V_82 &= ~ V_84 ;
V_8 -> V_82 &= ~ V_85 ;
} else if ( ! strcmp ( V_13 , V_86 ) ||
! strcmp ( V_13 , V_87 ) ||
! strcmp ( V_13 , V_88 ) ) {
V_8 -> V_82 |= ( V_89 | V_90 |
V_91 ) ;
} else if ( ! strcmp ( V_13 , V_92 ) ||
! strcmp ( V_13 , V_93 ) ) {
V_8 -> V_82 |= ( V_89 | V_90 ) ;
V_8 -> V_82 &= ~ V_91 ;
} else if ( ! strcmp ( V_13 , V_94 ) ||
! strcmp ( V_13 , V_95 ) ) {
V_8 -> V_82 |= ( V_96 | V_97 |
V_98 ) ;
} else if ( ! strcmp ( V_13 , V_99 ) ) {
V_8 -> V_82 |= ( V_96 | V_97 ) ;
V_8 -> V_82 &= ~ V_98 ;
} else if ( ! strcmp ( V_13 , V_100 ) ||
! strcmp ( V_13 , V_101 ) ) {
V_8 -> V_82 |= ( V_102 | V_103 |
V_98 ) ;
} else if ( ! strcmp ( V_13 , V_104 ) ) {
V_8 -> V_82 |= ( V_102 | V_103 ) ;
V_8 -> V_82 &= ~ V_98 ;
} else if ( ! strcmp ( V_13 , V_105 ) ) {
F_6 ( V_8 ,
L_4 ) ;
} else if ( ! strcmp ( V_13 , V_106 ) ) {
F_6 ( V_8 ,
L_5 ) ;
} else if ( ! strcmp ( V_13 , V_107 ) ) {
V_8 -> V_27 |= V_108 ;
} else if ( ! strcmp ( V_13 , V_109 ) ) {
V_8 -> V_27 &= ~ V_108 ;
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
return V_41 ;
}
}
if ( ( V_8 -> V_27 & V_57 ) &&
! ( V_8 -> V_27 & V_28 ) ) {
F_6 ( V_8 , L_15 ) ;
return V_41 ;
}
if ( ( V_8 -> V_27 & V_59 ) && ( V_15 || V_16 ) ) {
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
if ( ( V_8 -> V_82 & ( V_102 | V_103 ) ) &&
( V_8 -> V_82 & ( V_96 | V_97 ) ) ) {
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
V_8 -> V_110 = V_15 ;
V_8 -> V_27 |= V_111 ;
}
if ( V_16 )
V_8 -> V_112 = V_16 ;
}
if ( V_8 -> V_37 != - 1 &&
V_8 -> V_37 != 0 &&
( V_8 -> V_37 < V_113 ||
V_8 -> V_37 > V_114 ) ) {
F_6 ( V_8 , L_21 ,
V_8 -> V_37 , V_113 , V_114 ) ;
return F_10 ( V_41 ) ;
}
if ( V_8 -> V_38 != - 1 &&
V_8 -> V_38 != 0 &&
( V_8 -> V_38 < V_115 ||
V_8 -> V_38 > V_116 ||
! F_11 ( V_8 -> V_38 ) ) ) {
F_6 ( V_8 ,
L_22 ,
V_8 -> V_38 ) ;
return F_10 ( V_41 ) ;
}
if ( V_18 ) {
if ( V_18 > V_117 ||
V_18 < V_118 ) {
F_6 ( V_8 , L_23 ,
V_18 , V_118 ,
V_117 ) ;
return F_10 ( V_41 ) ;
}
V_8 -> V_27 |= V_119 ;
V_8 -> V_120 = V_18 ;
V_8 -> V_121 = V_18 ;
}
return 0 ;
}
STATIC int
F_12 (
struct V_7 * V_8 ,
struct V_122 * V_123 )
{
static struct V_124 V_125 [] = {
{ V_71 , L_1 V_70 } ,
{ V_32 , L_1 V_55 } ,
{ V_59 , L_1 V_58 } ,
{ V_61 , L_1 V_60 } ,
{ V_67 , L_1 V_66 } ,
{ V_57 , L_1 V_56 } ,
{ V_76 , L_1 V_75 } ,
{ V_80 , L_1 V_79 } ,
{ V_52 , L_1 V_50 } ,
{ V_108 , L_1 V_107 } ,
{ V_36 , L_1 V_64 } ,
{ 0 , NULL }
} ;
static struct V_124 V_126 [] = {
{ V_34 , L_1 V_73 } ,
{ V_33 , L_1 V_69 } ,
{ V_36 , L_1 V_65 } ,
{ 0 , NULL }
} ;
struct V_124 * V_127 ;
for ( V_127 = V_125 ; V_127 -> V_128 ; V_127 ++ ) {
if ( V_8 -> V_27 & V_127 -> V_128 )
F_13 ( V_123 , V_127 -> V_129 ) ;
}
for ( V_127 = V_126 ; V_127 -> V_128 ; V_127 ++ ) {
if ( ! ( V_8 -> V_27 & V_127 -> V_128 ) )
F_13 ( V_123 , V_127 -> V_129 ) ;
}
if ( V_8 -> V_27 & V_119 )
F_14 ( V_123 , L_1 V_49 L_24 ,
( int ) ( 1 << V_8 -> V_121 ) >> 10 ) ;
if ( V_8 -> V_37 > 0 )
F_14 ( V_123 , L_1 V_40 L_25 , V_8 -> V_37 ) ;
if ( V_8 -> V_38 > 0 )
F_14 ( V_123 , L_1 V_42 L_24 , V_8 -> V_38 >> 10 ) ;
if ( V_8 -> V_44 )
F_14 ( V_123 , L_1 V_43 L_26 , V_8 -> V_44 ) ;
if ( V_8 -> V_47 )
F_14 ( V_123 , L_1 V_46 L_26 , V_8 -> V_47 ) ;
if ( V_8 -> V_110 > 0 )
F_14 ( V_123 , L_1 V_62 L_25 ,
( int ) F_15 ( V_8 , V_8 -> V_110 ) ) ;
if ( V_8 -> V_112 > 0 )
F_14 ( V_123 , L_1 V_63 L_25 ,
( int ) F_15 ( V_8 , V_8 -> V_112 ) ) ;
if ( V_8 -> V_82 & ( V_89 | V_91 ) )
F_13 ( V_123 , L_1 V_88 ) ;
else if ( V_8 -> V_82 & V_89 )
F_13 ( V_123 , L_1 V_93 ) ;
if ( V_8 -> V_82 & V_96 ) {
if ( V_8 -> V_82 & V_98 )
F_13 ( V_123 , L_1 V_95 ) ;
else
F_13 ( V_123 , L_1 V_99 ) ;
} else if ( V_8 -> V_82 & V_102 ) {
if ( V_8 -> V_82 & V_98 )
F_13 ( V_123 , L_1 V_101 ) ;
else
F_13 ( V_123 , L_1 V_104 ) ;
}
if ( ! ( V_8 -> V_82 & V_83 ) )
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
F_18 ( struct V_7 * V_8 )
{
T_3 V_138 = 0 ;
T_3 V_139 = 0 ;
T_4 * V_140 = & V_8 -> V_141 ;
T_3 V_142 ;
T_5 V_143 = F_19 ( V_8 , V_140 -> V_144 - 1 , 0 ) ;
T_6 V_145 = F_20 ( V_8 , V_140 -> V_146 - 1 , V_143 ) ;
T_7 * V_147 ;
if ( V_8 -> V_148 ) {
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
V_145 = F_20 ( V_8 , V_138 , V_143 ) ;
if ( V_145 > V_152 ) {
V_147 = F_22 ( V_8 , V_138 ) ;
V_147 -> V_153 = 0 ;
V_147 -> V_154 = 0 ;
F_23 ( V_147 ) ;
continue;
}
V_147 = F_22 ( V_8 , V_138 ) ;
V_147 -> V_153 = 1 ;
V_139 ++ ;
if ( V_138 < V_142 )
V_147 -> V_154 = 1 ;
F_23 ( V_147 ) ;
}
V_8 -> V_27 |= ( V_155 |
V_36 ) ;
return V_139 ;
}
T_3
F_24 ( struct V_7 * V_8 )
{
T_3 V_138 = 0 ;
for ( V_138 = 0 ; V_138 < V_8 -> V_141 . V_146 ; V_138 ++ ) {
struct V_156 * V_147 ;
V_147 = F_22 ( V_8 , V_138 ) ;
V_147 -> V_153 = 1 ;
V_147 -> V_154 = 0 ;
F_23 ( V_147 ) ;
}
V_8 -> V_27 &= ~ ( V_155 |
V_36 ) ;
return V_138 ;
}
STATIC int
F_25 (
T_8 * V_8 ,
const char * V_157 ,
struct V_158 * * V_159 )
{
int error = 0 ;
* V_159 = F_26 ( V_157 , V_160 | V_161 | V_162 ,
V_8 ) ;
if ( F_27 ( * V_159 ) ) {
error = F_28 ( * V_159 ) ;
F_6 ( V_8 , L_27 , V_157 , error ) ;
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
struct V_7 * V_8 )
{
if ( V_8 -> V_167 && V_8 -> V_167 != V_8 -> V_168 ) {
struct V_158 * V_169 = V_8 -> V_167 -> V_165 ;
F_34 ( V_8 , V_8 -> V_167 ) ;
F_29 ( V_169 ) ;
}
if ( V_8 -> V_170 ) {
struct V_158 * V_171 = V_8 -> V_170 -> V_165 ;
F_34 ( V_8 , V_8 -> V_170 ) ;
F_29 ( V_171 ) ;
}
F_34 ( V_8 , V_8 -> V_168 ) ;
}
STATIC int
F_35 (
struct V_7 * V_8 )
{
struct V_158 * V_172 = V_8 -> V_12 -> V_173 ;
struct V_158 * V_169 = NULL , * V_171 = NULL ;
int error ;
if ( V_8 -> V_44 ) {
error = F_25 ( V_8 , V_8 -> V_44 , & V_169 ) ;
if ( error )
goto V_174;
}
if ( V_8 -> V_47 ) {
error = F_25 ( V_8 , V_8 -> V_47 , & V_171 ) ;
if ( error )
goto V_175;
if ( V_171 == V_172 || V_171 == V_169 ) {
F_6 ( V_8 ,
L_28 ) ;
error = V_41 ;
goto V_176;
}
}
error = V_23 ;
V_8 -> V_168 = F_36 ( V_8 , V_172 , 0 , V_8 -> V_19 ) ;
if ( ! V_8 -> V_168 )
goto V_176;
if ( V_171 ) {
V_8 -> V_170 = F_36 ( V_8 , V_171 , 1 ,
V_8 -> V_19 ) ;
if ( ! V_8 -> V_170 )
goto V_177;
}
if ( V_169 && V_169 != V_172 ) {
V_8 -> V_167 = F_36 ( V_8 , V_169 , 1 ,
V_8 -> V_19 ) ;
if ( ! V_8 -> V_167 )
goto V_178;
} else {
V_8 -> V_167 = V_8 -> V_168 ;
}
return 0 ;
V_178:
if ( V_8 -> V_170 )
F_34 ( V_8 , V_8 -> V_170 ) ;
V_177:
F_34 ( V_8 , V_8 -> V_168 ) ;
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
struct V_7 * V_8 )
{
int error ;
error = F_38 ( V_8 -> V_168 , V_8 -> V_141 . V_179 ,
V_8 -> V_141 . V_180 ) ;
if ( error )
return error ;
if ( V_8 -> V_167 && V_8 -> V_167 != V_8 -> V_168 ) {
unsigned int V_181 = V_182 ;
if ( F_39 ( & V_8 -> V_141 ) )
V_181 = V_8 -> V_141 . V_183 ;
error = F_38 ( V_8 -> V_167 ,
V_8 -> V_141 . V_179 ,
V_181 ) ;
if ( error )
return error ;
}
if ( V_8 -> V_170 ) {
error = F_38 ( V_8 -> V_170 ,
V_8 -> V_141 . V_179 ,
V_8 -> V_141 . V_180 ) ;
if ( error )
return error ;
}
return 0 ;
}
STATIC int
F_40 (
struct V_7 * V_8 )
{
V_8 -> V_184 = F_41 ( L_29 ,
V_185 , 0 , V_8 -> V_19 ) ;
if ( ! V_8 -> V_184 )
goto V_174;
V_8 -> V_186 = F_41 ( L_30 ,
V_185 , 0 , V_8 -> V_19 ) ;
if ( ! V_8 -> V_186 )
goto V_187;
V_8 -> V_188 = F_41 ( L_31 ,
V_185 , 0 , V_8 -> V_19 ) ;
if ( ! V_8 -> V_188 )
goto V_189;
return 0 ;
V_189:
F_42 ( V_8 -> V_186 ) ;
V_187:
F_42 ( V_8 -> V_184 ) ;
V_174:
return - V_23 ;
}
STATIC void
F_43 (
struct V_7 * V_8 )
{
F_42 ( V_8 -> V_188 ) ;
F_42 ( V_8 -> V_184 ) ;
F_42 ( V_8 -> V_186 ) ;
}
STATIC struct V_190 *
F_44 (
struct V_10 * V_11 )
{
F_45 () ;
return NULL ;
}
STATIC void
F_46 (
struct V_190 * V_190 )
{
struct V_191 * V_192 = F_47 ( V_190 ) ;
F_48 ( V_192 ) ;
F_49 ( V_193 ) ;
if ( F_50 ( V_190 ) )
goto V_194;
ASSERT ( F_51 ( V_192 -> V_195 ) || V_192 -> V_196 == 0 ) ;
F_52 ( ! F_53 ( V_192 , V_197 ) ) ;
F_52 ( ! F_53 ( V_192 , V_198 ) ) ;
V_194:
F_54 ( V_192 ) ;
}
STATIC void
F_55 (
void * V_190 )
{
struct V_191 * V_192 = V_190 ;
memset ( V_192 , 0 , sizeof( struct V_191 ) ) ;
F_56 ( F_57 ( V_192 ) ) ;
F_58 ( & V_192 -> V_199 , 0 ) ;
F_59 ( & V_192 -> V_200 ) ;
F_60 ( & V_192 -> V_201 , V_202 | V_203 ,
L_32 , V_192 -> V_204 ) ;
}
STATIC void
F_61 (
struct V_190 * V_190 )
{
T_10 * V_192 = F_47 ( V_190 ) ;
ASSERT ( ! F_62 ( & V_192 -> V_205 . V_206 ) ) ;
F_63 ( V_192 ) ;
F_64 ( & V_190 -> V_207 , 0 ) ;
F_65 ( V_190 ) ;
F_49 ( V_208 ) ;
F_49 ( V_209 ) ;
F_66 ( V_210 ) ;
F_67 ( V_192 ) ;
}
STATIC int
F_68 (
struct V_190 * V_190 )
{
struct V_191 * V_192 = F_47 ( V_190 ) ;
return F_69 ( V_190 ) || ( V_192 -> V_211 & V_212 ) ;
}
STATIC void
F_70 (
struct V_7 * V_8 )
{
F_71 ( V_8 -> V_19 ) ;
F_71 ( V_8 -> V_47 ) ;
F_71 ( V_8 -> V_44 ) ;
}
STATIC void
F_72 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_73 ( V_11 ) ;
F_74 ( V_8 ) ;
F_75 ( & V_8 -> V_213 ) ;
F_76 ( V_8 ) ;
F_77 ( V_8 ) ;
F_78 ( V_8 ) ;
F_79 ( V_8 ) ;
F_43 ( V_8 ) ;
F_33 ( V_8 ) ;
F_70 ( V_8 ) ;
F_71 ( V_8 ) ;
}
STATIC int
F_80 (
struct V_10 * V_11 ,
int V_214 )
{
struct V_7 * V_8 = F_73 ( V_11 ) ;
int error ;
if ( ! V_214 )
return 0 ;
error = F_81 ( V_8 ) ;
if ( error )
return - error ;
if ( V_215 ) {
F_82 ( & V_8 -> V_213 ) ;
}
return 0 ;
}
STATIC int
F_83 (
struct V_216 * V_216 ,
struct V_217 * V_218 )
{
struct V_7 * V_8 = F_73 ( V_216 -> V_219 ) ;
T_4 * V_140 = & V_8 -> V_141 ;
struct V_191 * V_192 = F_47 ( V_216 -> V_220 ) ;
T_2 V_221 , V_222 ;
T_11 V_223 ;
T_12 V_224 ;
V_218 -> V_225 = V_226 ;
V_218 -> V_227 = V_21 - 1 ;
V_222 = F_84 ( V_8 -> V_168 -> V_228 ) ;
V_218 -> V_229 . V_230 [ 0 ] = ( V_231 ) V_222 ;
V_218 -> V_229 . V_230 [ 1 ] = ( V_231 ) ( V_222 >> 32 ) ;
F_85 ( V_8 , V_232 ) ;
F_86 ( & V_8 -> V_233 ) ;
V_218 -> V_234 = V_140 -> V_179 ;
V_223 = V_140 -> V_235 ? V_140 -> V_236 : 0 ;
V_218 -> V_237 = V_140 -> V_150 - V_223 ;
V_218 -> V_238 = V_218 -> V_239 =
V_140 -> V_240 - F_87 ( V_8 ) ;
V_221 = V_218 -> V_238 << V_140 -> V_241 ;
V_218 -> V_242 =
F_88 ( V_140 -> V_243 + V_221 , ( T_2 ) V_244 ) ;
if ( V_8 -> V_148 )
V_218 -> V_242 = F_89 ( F_90 ( V_218 -> V_242 ) ,
V_218 -> V_242 ,
V_8 -> V_148 ) ;
V_224 = V_218 -> V_242 - ( V_140 -> V_243 - V_140 -> V_245 ) ;
V_218 -> V_246 = F_91 ( T_12 , V_224 , 0 ) ;
F_92 ( & V_8 -> V_233 ) ;
if ( ( V_192 -> V_247 . V_248 & V_249 ) &&
( ( V_8 -> V_82 & ( V_96 | V_98 ) ) ) ==
( V_96 | V_98 ) )
F_93 ( V_192 , V_218 ) ;
return 0 ;
}
STATIC void
F_94 ( struct V_7 * V_8 )
{
T_2 V_250 = 0 ;
V_8 -> V_251 = V_8 -> V_252 ;
F_95 ( V_8 , & V_250 , NULL ) ;
}
STATIC void
F_96 ( struct V_7 * V_8 )
{
T_2 V_250 ;
if ( V_8 -> V_251 ) {
V_250 = V_8 -> V_251 ;
V_8 -> V_251 = 0 ;
} else
V_250 = F_97 ( V_8 ) ;
F_95 ( V_8 , & V_250 , NULL ) ;
}
STATIC int
F_98 (
struct V_10 * V_11 ,
int * V_253 ,
char * V_9 )
{
struct V_7 * V_8 = F_73 ( V_11 ) ;
T_13 args [ V_254 ] ;
char * V_255 ;
int error ;
while ( ( V_255 = F_5 ( & V_9 , L_1 ) ) != NULL ) {
int V_256 ;
if ( ! * V_255 )
continue;
V_256 = F_99 ( V_255 , V_257 , args ) ;
switch ( V_256 ) {
case V_258 :
V_8 -> V_27 |= V_33 ;
break;
case V_259 :
V_8 -> V_27 &= ~ V_33 ;
break;
case V_260 :
V_8 -> V_261 = F_24 ( V_8 ) ;
break;
case V_262 :
V_8 -> V_261 = F_18 ( V_8 ) ;
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
if ( ( V_8 -> V_27 & V_28 ) && ! ( * V_253 & V_26 ) ) {
V_8 -> V_27 &= ~ V_28 ;
if ( V_8 -> V_263 ) {
error = F_100 ( V_8 , V_8 -> V_263 ) ;
if ( error ) {
F_6 ( V_8 , L_33 ) ;
return error ;
}
V_8 -> V_263 = 0 ;
}
F_96 ( V_8 ) ;
}
if ( ! ( V_8 -> V_27 & V_28 ) && ( * V_253 & V_26 ) ) {
F_81 ( V_8 ) ;
F_94 ( V_8 ) ;
F_101 ( V_8 ) ;
V_8 -> V_27 |= V_28 ;
}
return 0 ;
}
STATIC int
F_102 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_73 ( V_11 ) ;
F_94 ( V_8 ) ;
F_101 ( V_8 ) ;
return - F_103 ( V_8 ) ;
}
STATIC int
F_104 (
struct V_10 * V_11 )
{
struct V_7 * V_8 = F_73 ( V_11 ) ;
F_96 ( V_8 ) ;
return 0 ;
}
STATIC int
F_105 (
struct V_122 * V_123 ,
struct V_216 * V_264 )
{
return - F_12 ( F_73 ( V_264 -> V_219 ) , V_123 ) ;
}
STATIC int
F_106 (
struct V_7 * V_8 )
{
int V_265 = ( V_8 -> V_27 & V_28 ) ;
if ( F_107 ( & V_8 -> V_141 ) ) {
if ( V_8 -> V_38 <= 0 &&
V_8 -> V_141 . V_266 > V_267 ) {
V_8 -> V_38 = V_8 -> V_141 . V_266 ;
} else if ( V_8 -> V_38 > 0 &&
V_8 -> V_38 < V_8 -> V_141 . V_266 ) {
F_6 ( V_8 ,
L_34 ) ;
return F_10 ( V_41 ) ;
}
} else {
if ( V_8 -> V_38 > V_267 ) {
F_6 ( V_8 ,
L_35 ) ;
return F_10 ( V_41 ) ;
}
}
if ( F_108 ( & V_8 -> V_141 ) &&
! ( V_8 -> V_27 & V_78 ) )
V_8 -> V_27 |= V_76 ;
if ( ( V_8 -> V_141 . V_268 & V_269 ) && ! V_265 ) {
F_6 ( V_8 ,
L_36 ) ;
return F_10 ( V_270 ) ;
}
return 0 ;
}
STATIC int
F_109 (
struct V_10 * V_11 ,
void * V_271 ,
int V_272 )
{
struct V_190 * V_264 ;
struct V_7 * V_8 = NULL ;
int V_253 = 0 , error = V_23 ;
V_8 = F_110 ( sizeof( struct V_7 ) , V_22 ) ;
if ( ! V_8 )
goto V_174;
F_59 ( & V_8 -> V_233 ) ;
F_111 ( & V_8 -> V_273 ) ;
F_58 ( & V_8 -> V_274 , 0 ) ;
V_8 -> V_12 = V_11 ;
V_11 -> V_275 = V_8 ;
error = F_3 ( V_8 , ( char * ) V_271 ) ;
if ( error )
goto V_276;
F_112 ( V_11 , V_182 ) ;
V_11 -> V_277 = V_278 ;
V_11 -> V_279 = & V_280 ;
#ifdef F_8
V_11 -> V_281 = & V_282 ;
#endif
V_11 -> V_283 = & V_284 ;
if ( V_272 )
V_253 |= V_285 ;
error = F_35 ( V_8 ) ;
if ( error )
goto V_276;
error = F_40 ( V_8 ) ;
if ( error )
goto V_286;
error = F_113 ( V_8 ) ;
if ( error )
goto V_287;
error = F_114 ( V_8 , V_253 ) ;
if ( error )
goto V_288;
error = F_106 ( V_8 ) ;
if ( error )
goto V_289;
error = F_37 ( V_8 ) ;
if ( error )
goto V_289;
error = F_115 ( V_8 ) ;
if ( error )
goto V_289;
V_11 -> V_290 = V_226 ;
V_11 -> V_291 = V_8 -> V_141 . V_179 ;
V_11 -> V_292 = F_7 ( V_11 -> V_291 ) - 1 ;
V_11 -> V_293 = F_16 ( V_11 -> V_292 ) ;
V_11 -> V_294 = V_295 ;
V_11 -> V_296 = 1 ;
F_116 ( V_11 ) ;
error = F_117 ( V_8 ) ;
if ( error )
goto V_297;
error = F_118 ( V_8 ) ;
if ( error )
goto V_298;
V_264 = F_119 ( F_57 ( V_8 -> V_299 ) ) ;
if ( ! V_264 ) {
error = V_300 ;
goto V_301;
}
if ( F_50 ( V_264 ) ) {
error = V_41 ;
goto V_301;
}
V_11 -> V_302 = F_120 ( V_264 ) ;
if ( ! V_11 -> V_302 ) {
error = V_23 ;
goto V_301;
}
return 0 ;
V_298:
F_77 ( V_8 ) ;
V_297:
F_74 ( V_8 ) ;
V_289:
F_78 ( V_8 ) ;
V_288:
F_79 ( V_8 ) ;
V_287:
F_43 ( V_8 ) ;
V_286:
F_33 ( V_8 ) ;
V_276:
F_70 ( V_8 ) ;
F_71 ( V_8 ) ;
V_174:
return - error ;
V_301:
F_74 ( V_8 ) ;
F_76 ( V_8 ) ;
F_77 ( V_8 ) ;
goto V_289;
}
STATIC struct V_216 *
F_121 (
struct V_303 * V_304 ,
int V_253 ,
const char * V_305 ,
void * V_271 )
{
return F_122 ( V_304 , V_253 , V_305 , V_271 , F_109 ) ;
}
static int
F_123 (
struct V_10 * V_11 )
{
return F_124 ( F_73 ( V_11 ) ) ;
}
static void
F_125 (
struct V_10 * V_11 ,
int V_306 )
{
F_126 ( F_73 ( V_11 ) , V_306 ) ;
}
STATIC int T_14
F_127 ( void )
{
V_307 = F_128 ( sizeof( V_308 ) , L_37 ) ;
if ( ! V_307 )
goto V_174;
V_309 = F_129 ( 4 * V_310 ,
V_307 ) ;
if ( ! V_309 )
goto V_311;
V_312 = F_128 ( sizeof( V_313 ) ,
L_38 ) ;
if ( ! V_312 )
goto V_314;
V_315 = F_128 ( sizeof( V_316 ) ,
L_39 ) ;
if ( ! V_315 )
goto V_317;
V_318 = F_128 ( sizeof( V_319 ) ,
L_40 ) ;
if ( ! V_318 )
goto V_320;
V_321 = F_128 ( sizeof( V_322 ) ,
L_41 ) ;
if ( ! V_321 )
goto V_323;
V_324 = F_128 ( sizeof( V_325 ) , L_42 ) ;
if ( ! V_324 )
goto V_326;
V_327 = F_128 ( sizeof( V_328 ) , L_43 ) ;
if ( ! V_327 )
goto V_329;
V_330 =
F_128 ( sizeof( struct V_331 ) ,
L_44 ) ;
if ( ! V_330 )
goto V_332;
V_333 = F_128 ( sizeof( struct V_334 ) ,
L_45 ) ;
if ( ! V_333 )
goto V_335;
V_336 = F_128 ( ( sizeof( V_337 ) +
( ( V_338 - 1 ) *
sizeof( V_339 ) ) ) , L_46 ) ;
if ( ! V_336 )
goto V_340;
V_341 = F_128 ( ( sizeof( V_342 ) +
( ( V_343 - 1 ) *
sizeof( V_339 ) ) ) , L_47 ) ;
if ( ! V_341 )
goto V_344;
V_345 =
F_130 ( sizeof( T_10 ) , L_48 ,
V_346 | V_347 | V_348 ,
F_55 ) ;
if ( ! V_345 )
goto V_349;
V_350 =
F_130 ( sizeof( V_351 ) , L_49 ,
V_348 , NULL ) ;
if ( ! V_350 )
goto V_352;
return 0 ;
V_352:
F_131 ( V_345 ) ;
V_349:
F_131 ( V_341 ) ;
V_344:
F_131 ( V_336 ) ;
V_340:
F_131 ( V_333 ) ;
V_335:
F_131 ( V_330 ) ;
V_332:
F_131 ( V_327 ) ;
V_329:
F_131 ( V_324 ) ;
V_326:
F_131 ( V_321 ) ;
V_323:
F_131 ( V_318 ) ;
V_320:
F_131 ( V_315 ) ;
V_317:
F_131 ( V_312 ) ;
V_314:
F_132 ( V_309 ) ;
V_311:
F_131 ( V_307 ) ;
V_174:
return - V_23 ;
}
STATIC void
F_133 ( void )
{
F_134 () ;
F_131 ( V_350 ) ;
F_131 ( V_345 ) ;
F_131 ( V_341 ) ;
F_131 ( V_336 ) ;
F_131 ( V_333 ) ;
F_131 ( V_330 ) ;
F_131 ( V_327 ) ;
F_131 ( V_324 ) ;
F_131 ( V_321 ) ;
F_131 ( V_318 ) ;
F_131 ( V_315 ) ;
F_131 ( V_312 ) ;
F_132 ( V_309 ) ;
F_131 ( V_307 ) ;
}
STATIC int T_14
F_135 ( void )
{
V_353 = F_41 ( L_50 , V_354 , 0 ) ;
if ( ! V_353 )
return - V_23 ;
V_355 = F_41 ( L_51 , V_185 , 0 ) ;
if ( ! V_355 )
goto V_356;
return 0 ;
V_356:
F_42 ( V_353 ) ;
return - V_23 ;
}
STATIC void
F_136 ( void )
{
F_42 ( V_355 ) ;
F_42 ( V_353 ) ;
}
STATIC int T_14
F_137 ( void )
{
int error ;
F_138 (KERN_INFO XFS_VERSION_STRING L_52
XFS_BUILD_OPTIONS L_53 ) ;
F_139 () ;
error = F_127 () ;
if ( error )
goto V_174;
error = F_135 () ;
if ( error )
goto V_357;
error = F_140 () ;
if ( error )
goto V_358;
error = F_141 () ;
if ( error )
goto V_359;
error = F_142 () ;
if ( error )
goto V_360;
error = F_143 () ;
if ( error )
goto V_361;
error = F_144 () ;
if ( error )
goto V_362;
error = F_145 () ;
if ( error )
goto V_363;
error = F_146 ( & V_364 ) ;
if ( error )
goto V_365;
return 0 ;
V_365:
F_147 () ;
V_363:
F_148 () ;
V_362:
F_149 () ;
V_361:
F_150 () ;
V_360:
F_151 () ;
V_359:
F_152 () ;
V_358:
F_136 () ;
V_357:
F_133 () ;
V_174:
return error ;
}
STATIC void T_15
F_153 ( void )
{
F_147 () ;
F_154 ( & V_364 ) ;
F_148 () ;
F_149 () ;
F_150 () ;
F_151 () ;
F_152 () ;
F_136 () ;
F_133 () ;
}
