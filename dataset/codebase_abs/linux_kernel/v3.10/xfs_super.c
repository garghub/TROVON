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
V_98 ) ;
} else if ( ! strcmp ( V_15 , V_104 ) ) {
V_10 -> V_82 |= ( V_102 | V_103 ) ;
V_10 -> V_82 &= ~ V_98 ;
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
if ( ( V_10 -> V_82 & ( V_102 | V_103 ) ) &&
( V_10 -> V_82 & ( V_96 | V_97 ) ) ) {
F_6 ( V_10 , L_18 ) ;
return V_8 ;
}
if ( ( V_16 && ! V_17 ) || ( ! V_16 && V_17 ) ) {
F_6 ( V_10 , L_19 ) ;
return V_8 ;
}
if ( V_16 && ( V_17 % V_16 != 0 ) ) {
F_6 ( V_10 ,
L_20 ,
V_17 , V_16 ) ;
return V_8 ;
}
V_40:
if ( ! ( V_10 -> V_28 & V_59 ) ) {
if ( V_16 ) {
V_10 -> V_110 = V_16 ;
V_10 -> V_28 |= V_111 ;
}
if ( V_17 )
V_10 -> V_112 = V_17 ;
}
if ( V_10 -> V_38 != - 1 &&
V_10 -> V_38 != 0 &&
( V_10 -> V_38 < V_113 ||
V_10 -> V_38 > V_114 ) ) {
F_6 ( V_10 , L_21 ,
V_10 -> V_38 , V_113 , V_114 ) ;
return F_10 ( V_8 ) ;
}
if ( V_10 -> V_39 != - 1 &&
V_10 -> V_39 != 0 &&
( V_10 -> V_39 < V_115 ||
V_10 -> V_39 > V_116 ||
! F_11 ( V_10 -> V_39 ) ) ) {
F_6 ( V_10 ,
L_22 ,
V_10 -> V_39 ) ;
return F_10 ( V_8 ) ;
}
if ( V_19 ) {
if ( V_19 > V_117 ||
V_19 < V_118 ) {
F_6 ( V_10 , L_23 ,
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
{ V_108 , L_1 V_107 } ,
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
F_14 ( V_123 , L_1 V_49 L_24 ,
( int ) ( 1 << V_10 -> V_121 ) >> 10 ) ;
if ( V_10 -> V_38 > 0 )
F_14 ( V_123 , L_1 V_41 L_25 , V_10 -> V_38 ) ;
if ( V_10 -> V_39 > 0 )
F_14 ( V_123 , L_1 V_42 L_24 , V_10 -> V_39 >> 10 ) ;
if ( V_10 -> V_44 )
F_14 ( V_123 , L_1 V_43 L_26 , V_10 -> V_44 ) ;
if ( V_10 -> V_47 )
F_14 ( V_123 , L_1 V_46 L_26 , V_10 -> V_47 ) ;
if ( V_10 -> V_110 > 0 )
F_14 ( V_123 , L_1 V_62 L_25 ,
( int ) F_15 ( V_10 , V_10 -> V_110 ) ) ;
if ( V_10 -> V_112 > 0 )
F_14 ( V_123 , L_1 V_63 L_25 ,
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
} else if ( V_10 -> V_82 & V_102 ) {
if ( V_10 -> V_82 & V_98 )
F_13 ( V_123 , L_1 V_101 ) ;
else
F_13 ( V_123 , L_1 V_104 ) ;
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
F_6 ( V_10 , L_27 , V_157 , error ) ;
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
L_28 ) ;
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
V_10 -> V_184 = F_41 ( L_29 ,
V_185 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_184 )
goto V_174;
V_10 -> V_186 = F_41 ( L_30 ,
V_185 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_186 )
goto V_187;
V_10 -> V_188 = F_41 ( L_31 ,
V_185 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_188 )
goto V_189;
V_10 -> V_190 = F_41 ( L_32 ,
V_191 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_190 )
goto V_192;
V_10 -> V_193 = F_41 ( L_33 ,
V_191 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_193 )
goto V_194;
V_10 -> V_195 = F_41 ( L_34 ,
V_191 , 0 , V_10 -> V_20 ) ;
if ( ! V_10 -> V_195 )
goto V_196;
return 0 ;
V_196:
F_42 ( V_10 -> V_193 ) ;
V_194:
F_42 ( V_10 -> V_190 ) ;
V_192:
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
F_42 ( V_10 -> V_195 ) ;
F_42 ( V_10 -> V_193 ) ;
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
if ( F_45 ( & V_13 -> V_197 ) ) {
F_46 ( V_13 ) ;
F_47 ( & V_13 -> V_197 ) ;
}
}
STATIC struct V_198 *
F_48 (
struct V_12 * V_13 )
{
F_49 () ;
return NULL ;
}
STATIC void
F_50 (
struct V_198 * V_198 )
{
struct V_199 * V_200 = F_51 ( V_198 ) ;
F_52 ( V_200 ) ;
F_53 ( V_201 ) ;
if ( F_54 ( V_198 ) )
goto V_202;
ASSERT ( F_55 ( V_200 -> V_203 ) || V_200 -> V_204 == 0 ) ;
F_56 ( ! F_57 ( V_200 , V_205 ) ) ;
F_56 ( ! F_57 ( V_200 , V_206 ) ) ;
V_202:
F_58 ( V_200 ) ;
}
STATIC void
F_59 (
void * V_198 )
{
struct V_199 * V_200 = V_198 ;
memset ( V_200 , 0 , sizeof( struct V_199 ) ) ;
F_60 ( F_61 ( V_200 ) ) ;
F_62 ( & V_200 -> V_207 , 0 ) ;
F_63 ( & V_200 -> V_208 ) ;
F_64 ( & V_200 -> V_209 , V_210 | V_211 ,
L_35 , V_200 -> V_212 ) ;
}
STATIC void
F_65 (
struct V_198 * V_198 )
{
T_10 * V_200 = F_51 ( V_198 ) ;
ASSERT ( ! F_66 ( & V_200 -> V_213 . V_214 ) ) ;
F_67 ( V_200 ) ;
F_68 ( & V_198 -> V_215 , 0 ) ;
F_69 ( V_198 ) ;
F_53 ( V_216 ) ;
F_53 ( V_217 ) ;
F_70 ( V_218 ) ;
F_71 ( V_200 ) ;
}
STATIC int
F_72 (
struct V_198 * V_198 )
{
struct V_199 * V_200 = F_51 ( V_198 ) ;
return F_73 ( V_198 ) || ( V_200 -> V_219 & V_220 ) ;
}
STATIC void
F_74 (
struct V_9 * V_10 )
{
F_75 ( V_10 -> V_20 ) ;
F_75 ( V_10 -> V_47 ) ;
F_75 ( V_10 -> V_44 ) ;
}
STATIC void
F_76 (
struct V_12 * V_13 )
{
struct V_9 * V_10 = F_77 ( V_13 ) ;
F_78 ( V_10 ) ;
F_79 ( V_10 ) ;
F_80 ( V_10 ) ;
F_81 ( V_10 ) ;
F_43 ( V_10 ) ;
F_33 ( V_10 ) ;
F_74 ( V_10 ) ;
F_75 ( V_10 ) ;
}
STATIC int
F_82 (
struct V_12 * V_13 ,
int V_221 )
{
struct V_9 * V_10 = F_77 ( V_13 ) ;
if ( ! V_221 )
return 0 ;
F_83 ( V_10 , V_222 ) ;
if ( V_223 ) {
F_84 ( & V_10 -> V_224 -> V_225 ) ;
}
return 0 ;
}
STATIC int
F_85 (
struct V_226 * V_226 ,
struct V_227 * V_228 )
{
struct V_9 * V_10 = F_77 ( V_226 -> V_229 ) ;
T_4 * V_140 = & V_10 -> V_141 ;
struct V_199 * V_200 = F_51 ( V_226 -> V_230 ) ;
T_2 V_231 , V_232 ;
T_11 V_233 ;
T_12 V_234 ;
V_228 -> V_235 = V_236 ;
V_228 -> V_237 = V_22 - 1 ;
V_232 = F_86 ( V_10 -> V_168 -> V_238 ) ;
V_228 -> V_239 . V_240 [ 0 ] = ( V_241 ) V_232 ;
V_228 -> V_239 . V_240 [ 1 ] = ( V_241 ) ( V_232 >> 32 ) ;
F_87 ( V_10 , V_242 ) ;
F_88 ( & V_10 -> V_243 ) ;
V_228 -> V_244 = V_140 -> V_179 ;
V_233 = V_140 -> V_245 ? V_140 -> V_246 : 0 ;
V_228 -> V_247 = V_140 -> V_150 - V_233 ;
V_228 -> V_248 = V_228 -> V_249 =
V_140 -> V_250 - F_89 ( V_10 ) ;
V_231 = V_228 -> V_248 << V_140 -> V_251 ;
V_228 -> V_252 =
F_90 ( V_140 -> V_253 + V_231 , ( T_2 ) V_254 ) ;
if ( V_10 -> V_148 )
V_228 -> V_252 = F_91 ( F_92 ( V_228 -> V_252 ) ,
V_228 -> V_252 ,
V_10 -> V_148 ) ;
V_234 = V_228 -> V_252 - ( V_140 -> V_253 - V_140 -> V_255 ) ;
V_228 -> V_256 = F_93 ( T_12 , V_234 , 0 ) ;
F_94 ( & V_10 -> V_243 ) ;
if ( ( V_200 -> V_257 . V_258 & V_259 ) &&
( ( V_10 -> V_82 & ( V_96 | V_98 ) ) ) ==
( V_96 | V_98 ) )
F_95 ( V_200 , V_228 ) ;
return 0 ;
}
STATIC void
F_96 ( struct V_9 * V_10 )
{
T_2 V_260 = 0 ;
V_10 -> V_261 = V_10 -> V_262 ;
F_97 ( V_10 , & V_260 , NULL ) ;
}
STATIC void
F_98 ( struct V_9 * V_10 )
{
T_2 V_260 ;
if ( V_10 -> V_261 ) {
V_260 = V_10 -> V_261 ;
V_10 -> V_261 = 0 ;
} else
V_260 = F_99 ( V_10 ) ;
F_97 ( V_10 , & V_260 , NULL ) ;
}
void
F_100 (
struct V_9 * V_10 )
{
int error = 0 ;
while ( F_101 ( & V_10 -> V_263 ) > 0 )
F_102 ( 100 ) ;
F_83 ( V_10 , V_222 ) ;
F_103 ( V_10 , 0 ) ;
F_103 ( V_10 , V_264 ) ;
error = F_104 ( V_10 ) ;
if ( error )
F_6 ( V_10 , L_36
L_37 ) ;
F_105 ( F_101 ( & V_10 -> V_263 ) != 0 ) ;
F_106 ( V_10 ) ;
}
STATIC int
F_107 (
struct V_12 * V_13 ,
int * V_265 ,
char * V_11 )
{
struct V_9 * V_10 = F_77 ( V_13 ) ;
T_13 args [ V_266 ] ;
char * V_267 ;
int error ;
while ( ( V_267 = F_5 ( & V_11 , L_1 ) ) != NULL ) {
int V_268 ;
if ( ! * V_267 )
continue;
V_268 = F_108 ( V_267 , V_269 , args ) ;
switch ( V_268 ) {
case V_270 :
V_10 -> V_28 |= V_34 ;
break;
case V_271 :
V_10 -> V_28 &= ~ V_34 ;
break;
case V_272 :
V_10 -> V_273 = F_24 ( V_10 ) ;
break;
case V_274 :
V_10 -> V_273 = F_18 ( V_10 ) ;
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
if ( ( V_10 -> V_28 & V_29 ) && ! ( * V_265 & V_27 ) ) {
V_10 -> V_28 &= ~ V_29 ;
if ( V_10 -> V_275 ) {
error = F_109 ( V_10 , V_10 -> V_275 ) ;
if ( error ) {
F_6 ( V_10 , L_38 ) ;
return error ;
}
V_10 -> V_275 = 0 ;
}
F_98 ( V_10 ) ;
F_110 ( V_10 ) ;
}
if ( ! ( V_10 -> V_28 & V_29 ) && ( * V_265 & V_27 ) ) {
F_96 ( V_10 ) ;
F_100 ( V_10 ) ;
V_10 -> V_28 |= V_29 ;
}
return 0 ;
}
STATIC int
F_111 (
struct V_12 * V_13 )
{
struct V_9 * V_10 = F_77 ( V_13 ) ;
F_96 ( V_10 ) ;
F_100 ( V_10 ) ;
return - F_112 ( V_10 ) ;
}
STATIC int
F_113 (
struct V_12 * V_13 )
{
struct V_9 * V_10 = F_77 ( V_13 ) ;
F_98 ( V_10 ) ;
F_110 ( V_10 ) ;
return 0 ;
}
STATIC int
F_114 (
struct V_122 * V_123 ,
struct V_226 * V_276 )
{
return - F_12 ( F_77 ( V_276 -> V_229 ) , V_123 ) ;
}
STATIC int
F_115 (
struct V_9 * V_10 )
{
int V_277 = ( V_10 -> V_28 & V_29 ) ;
if ( F_116 ( & V_10 -> V_141 ) ) {
if ( V_10 -> V_39 <= 0 &&
V_10 -> V_141 . V_278 > V_279 ) {
V_10 -> V_39 = V_10 -> V_141 . V_278 ;
} else if ( V_10 -> V_39 > 0 &&
V_10 -> V_39 < V_10 -> V_141 . V_278 ) {
F_6 ( V_10 ,
L_39 ) ;
return F_10 ( V_8 ) ;
}
} else {
if ( V_10 -> V_39 > V_279 ) {
F_6 ( V_10 ,
L_40 ) ;
return F_10 ( V_8 ) ;
}
}
if ( F_117 ( & V_10 -> V_141 ) &&
( V_10 -> V_28 & V_78 ) ) {
F_6 ( V_10 ,
L_41 ,
V_77 , V_75 ) ;
return F_10 ( V_8 ) ;
}
if ( F_118 ( & V_10 -> V_141 ) &&
! ( V_10 -> V_28 & V_78 ) )
V_10 -> V_28 |= V_76 ;
if ( ( V_10 -> V_141 . V_280 & V_281 ) && ! V_277 ) {
F_6 ( V_10 ,
L_42 ) ;
return F_10 ( V_282 ) ;
}
return 0 ;
}
STATIC int
F_119 (
struct V_12 * V_13 ,
void * V_283 ,
int V_284 )
{
struct V_198 * V_276 ;
struct V_9 * V_10 = NULL ;
int V_265 = 0 , error = V_24 ;
V_10 = F_120 ( sizeof( struct V_9 ) , V_23 ) ;
if ( ! V_10 )
goto V_174;
F_63 ( & V_10 -> V_243 ) ;
F_121 ( & V_10 -> V_285 ) ;
F_62 ( & V_10 -> V_263 , 0 ) ;
F_122 ( & V_10 -> V_286 , V_287 ) ;
F_122 ( & V_10 -> V_288 , V_289 ) ;
V_10 -> V_14 = V_13 ;
V_13 -> V_290 = V_10 ;
error = F_3 ( V_10 , ( char * ) V_283 ) ;
if ( error )
goto V_291;
F_123 ( V_13 , V_182 ) ;
V_13 -> V_292 = V_293 ;
V_13 -> V_294 = & V_295 ;
#ifdef F_8
V_13 -> V_296 = & V_297 ;
#endif
V_13 -> V_298 = & V_299 ;
if ( V_284 )
V_265 |= V_300 ;
error = F_35 ( V_10 ) ;
if ( error )
goto V_291;
error = F_40 ( V_10 ) ;
if ( error )
goto V_301;
error = F_124 ( V_10 ) ;
if ( error )
goto V_302;
error = F_125 ( V_10 , V_265 ) ;
if ( error )
goto V_303;
error = F_115 ( V_10 ) ;
if ( error )
goto V_304;
error = F_37 ( V_10 ) ;
if ( error )
goto V_304;
error = F_126 ( V_10 ) ;
if ( error )
goto V_304;
V_13 -> V_305 = V_236 ;
V_13 -> V_306 = V_10 -> V_141 . V_179 ;
V_13 -> V_307 = F_7 ( V_13 -> V_306 ) - 1 ;
V_13 -> V_308 = F_16 ( V_13 -> V_307 ) ;
V_13 -> V_309 = V_310 ;
V_13 -> V_311 = 1 ;
F_127 ( V_13 ) ;
error = F_128 ( V_10 ) ;
if ( error )
goto V_312;
V_276 = F_129 ( F_61 ( V_10 -> V_313 ) ) ;
if ( ! V_276 ) {
error = V_314 ;
goto V_315;
}
if ( F_54 ( V_276 ) ) {
error = V_8 ;
goto V_315;
}
V_13 -> V_316 = F_130 ( V_276 ) ;
if ( ! V_13 -> V_316 ) {
error = V_24 ;
goto V_315;
}
return 0 ;
V_312:
F_78 ( V_10 ) ;
V_304:
F_80 ( V_10 ) ;
V_303:
F_81 ( V_10 ) ;
V_302:
F_43 ( V_10 ) ;
V_301:
F_33 ( V_10 ) ;
V_291:
F_74 ( V_10 ) ;
F_75 ( V_10 ) ;
V_174:
return - error ;
V_315:
F_78 ( V_10 ) ;
F_79 ( V_10 ) ;
goto V_304;
}
STATIC struct V_226 *
F_131 (
struct V_317 * V_318 ,
int V_265 ,
const char * V_319 ,
void * V_283 )
{
return F_132 ( V_318 , V_265 , V_319 , V_283 , F_119 ) ;
}
static int
F_133 (
struct V_12 * V_13 )
{
return F_134 ( F_77 ( V_13 ) ) ;
}
static void
F_135 (
struct V_12 * V_13 ,
int V_320 )
{
F_136 ( F_77 ( V_13 ) , V_320 ) ;
}
STATIC int T_14
F_137 ( void )
{
V_321 = F_138 ( sizeof( V_322 ) , L_43 ) ;
if ( ! V_321 )
goto V_174;
V_323 = F_139 ( 4 * V_324 ,
V_321 ) ;
if ( ! V_323 )
goto V_325;
V_326 = F_138 ( sizeof( V_327 ) ,
L_44 ) ;
if ( ! V_326 )
goto V_328;
V_329 = F_138 ( sizeof( V_330 ) ,
L_45 ) ;
if ( ! V_329 )
goto V_331;
V_332 = F_138 ( sizeof( V_333 ) ,
L_46 ) ;
if ( ! V_332 )
goto V_334;
V_335 = F_138 ( sizeof( V_336 ) ,
L_47 ) ;
if ( ! V_335 )
goto V_337;
V_338 = F_138 ( sizeof( V_339 ) , L_48 ) ;
if ( ! V_338 )
goto V_340;
V_341 = F_138 ( sizeof( V_342 ) , L_49 ) ;
if ( ! V_341 )
goto V_343;
V_344 =
F_138 ( sizeof( struct V_345 ) ,
L_50 ) ;
if ( ! V_344 )
goto V_346;
V_347 = F_138 ( sizeof( struct V_348 ) ,
L_51 ) ;
if ( ! V_347 )
goto V_349;
V_350 = F_138 ( ( sizeof( V_351 ) +
( ( V_352 - 1 ) *
sizeof( V_353 ) ) ) , L_52 ) ;
if ( ! V_350 )
goto V_354;
V_355 = F_138 ( ( sizeof( V_356 ) +
( ( V_357 - 1 ) *
sizeof( V_353 ) ) ) , L_53 ) ;
if ( ! V_355 )
goto V_358;
V_359 =
F_140 ( sizeof( T_10 ) , L_54 ,
V_360 | V_361 | V_362 ,
F_59 ) ;
if ( ! V_359 )
goto V_363;
V_364 =
F_140 ( sizeof( V_365 ) , L_55 ,
V_362 , NULL ) ;
if ( ! V_364 )
goto V_366;
return 0 ;
V_366:
F_141 ( V_359 ) ;
V_363:
F_141 ( V_355 ) ;
V_358:
F_141 ( V_350 ) ;
V_354:
F_141 ( V_347 ) ;
V_349:
F_141 ( V_344 ) ;
V_346:
F_141 ( V_341 ) ;
V_343:
F_141 ( V_338 ) ;
V_340:
F_141 ( V_335 ) ;
V_337:
F_141 ( V_332 ) ;
V_334:
F_141 ( V_329 ) ;
V_331:
F_141 ( V_326 ) ;
V_328:
F_142 ( V_323 ) ;
V_325:
F_141 ( V_321 ) ;
V_174:
return - V_24 ;
}
STATIC void
F_143 ( void )
{
F_144 () ;
F_141 ( V_364 ) ;
F_141 ( V_359 ) ;
F_141 ( V_355 ) ;
F_141 ( V_350 ) ;
F_141 ( V_347 ) ;
F_141 ( V_344 ) ;
F_141 ( V_341 ) ;
F_141 ( V_338 ) ;
F_141 ( V_335 ) ;
F_141 ( V_332 ) ;
F_141 ( V_329 ) ;
F_141 ( V_326 ) ;
F_142 ( V_323 ) ;
F_141 ( V_321 ) ;
}
STATIC int T_14
F_145 ( void )
{
V_367 = F_41 ( L_56 , V_185 , 0 ) ;
if ( ! V_367 )
return - V_24 ;
return 0 ;
}
STATIC void
F_146 ( void )
{
F_42 ( V_367 ) ;
}
STATIC int T_14
F_147 ( void )
{
int error ;
F_148 (KERN_INFO XFS_VERSION_STRING L_57
XFS_BUILD_OPTIONS L_58 ) ;
F_149 () ;
error = F_137 () ;
if ( error )
goto V_174;
error = F_145 () ;
if ( error )
goto V_368;
error = F_150 () ;
if ( error )
goto V_369;
error = F_151 () ;
if ( error )
goto V_370;
error = F_152 () ;
if ( error )
goto V_371;
error = F_153 () ;
if ( error )
goto V_372;
error = F_154 () ;
if ( error )
goto V_373;
error = F_155 () ;
if ( error )
goto V_374;
error = F_156 ( & V_375 ) ;
if ( error )
goto V_376;
return 0 ;
V_376:
F_157 () ;
V_374:
F_158 () ;
V_373:
F_159 () ;
V_372:
F_160 () ;
V_371:
F_161 () ;
V_370:
F_162 () ;
V_369:
F_146 () ;
V_368:
F_143 () ;
V_174:
return error ;
}
STATIC void T_15
F_163 ( void )
{
F_157 () ;
F_164 ( & V_375 ) ;
F_158 () ;
F_159 () ;
F_160 () ;
F_161 () ;
F_162 () ;
F_146 () ;
F_143 () ;
}
