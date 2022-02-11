STATIC int
F_1 (
struct V_1 * V_2 ,
int type ,
int (* F_2)( struct V_3 * V_4 , void * V_5 ) ,
void * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 , type ) ;
T_1 V_11 ;
int V_12 = 0 ;
int V_13 ;
int V_14 ;
V_15:
V_13 = 0 ;
V_11 = 0 ;
V_14 = 0 ;
while ( 1 ) {
struct V_3 * V_16 [ V_17 ] ;
int error = 0 ;
int V_18 ;
F_4 ( & V_7 -> V_19 ) ;
V_14 = F_5 ( V_10 , ( void * * ) V_16 ,
V_11 , V_17 ) ;
if ( ! V_14 ) {
F_6 ( & V_7 -> V_19 ) ;
break;
}
for ( V_18 = 0 ; V_18 < V_14 ; V_18 ++ ) {
struct V_3 * V_4 = V_16 [ V_18 ] ;
V_11 = F_7 ( V_4 -> V_20 . V_21 ) + 1 ;
error = F_2 ( V_16 [ V_18 ] , V_5 ) ;
if ( error == - V_22 ) {
V_13 ++ ;
continue;
}
if ( error && V_12 != - V_23 )
V_12 = error ;
}
F_6 ( & V_7 -> V_19 ) ;
if ( V_12 == - V_23 ) {
V_13 = 0 ;
break;
}
}
if ( V_13 ) {
F_8 ( 1 ) ;
goto V_15;
}
return V_12 ;
}
STATIC int
F_9 (
struct V_3 * V_4 ,
void * V_5 )
{
struct V_1 * V_2 = V_4 -> V_24 ;
struct V_6 * V_7 = V_2 -> V_8 ;
F_10 ( V_4 ) ;
if ( ( V_4 -> V_25 & V_26 ) || V_4 -> V_27 != 0 ) {
F_11 ( V_4 ) ;
return - V_22 ;
}
V_4 -> V_25 |= V_26 ;
F_12 ( V_4 ) ;
if ( F_13 ( V_4 ) ) {
struct V_28 * V_29 = NULL ;
int error ;
error = F_14 ( V_4 , & V_29 ) ;
if ( error ) {
F_15 ( V_2 , L_1 ,
V_30 , V_4 ) ;
} else {
error = F_16 ( V_29 ) ;
F_17 ( V_29 ) ;
}
F_12 ( V_4 ) ;
}
ASSERT ( F_18 ( & V_4 -> V_31 ) == 0 ) ;
ASSERT ( F_19 ( V_2 ) ||
! ( V_4 -> V_32 . V_33 . V_34 & V_35 ) ) ;
F_20 ( V_4 ) ;
F_11 ( V_4 ) ;
F_21 ( F_3 ( V_7 , V_4 -> V_20 . V_36 ) ,
F_7 ( V_4 -> V_20 . V_21 ) ) ;
V_7 -> V_37 -- ;
ASSERT ( ! F_22 ( & V_4 -> V_38 ) ) ;
F_23 ( & V_7 -> V_39 , & V_4 -> V_38 ) ;
F_24 ( V_40 ) ;
F_25 ( V_4 ) ;
return 0 ;
}
void
F_26 (
struct V_1 * V_2 ,
T_2 V_41 )
{
if ( V_41 & V_42 )
F_1 ( V_2 , V_43 , F_9 , NULL ) ;
if ( V_41 & V_44 )
F_1 ( V_2 , V_45 , F_9 , NULL ) ;
if ( V_41 & V_46 )
F_1 ( V_2 , V_47 , F_9 , NULL ) ;
}
void
F_27 (
struct V_1 * V_2 )
{
if ( V_2 -> V_8 ) {
F_26 ( V_2 , V_48 ) ;
F_28 ( V_2 ) ;
}
}
void
F_29 (
T_3 * V_2 )
{
ASSERT ( V_2 -> V_49 ) ;
F_30 ( V_2 -> V_49 ) ;
if ( V_2 -> V_50 )
F_30 ( V_2 -> V_50 ) ;
if ( V_2 -> V_51 )
F_30 ( V_2 -> V_51 ) ;
if ( V_2 -> V_8 ) {
if ( V_2 -> V_8 -> V_52 ) {
F_31 ( V_2 -> V_8 -> V_52 ) ;
V_2 -> V_8 -> V_52 = NULL ;
}
if ( V_2 -> V_8 -> V_53 ) {
F_31 ( V_2 -> V_8 -> V_53 ) ;
V_2 -> V_8 -> V_53 = NULL ;
}
if ( V_2 -> V_8 -> V_54 ) {
F_31 ( V_2 -> V_8 -> V_54 ) ;
V_2 -> V_8 -> V_54 = NULL ;
}
}
}
STATIC int
F_32 (
T_4 * V_55 ,
T_5 V_56 ,
T_2 type ,
T_2 V_57 ,
T_6 * * V_58 )
{
T_6 * V_4 ;
int error ;
ASSERT ( F_33 ( V_55 , V_59 ) ) ;
error = 0 ;
V_4 = * V_58 ;
if ( V_4 ) {
F_34 ( V_4 ) ;
return 0 ;
}
error = F_35 ( V_55 -> V_60 , V_55 , V_56 , type ,
V_57 | V_61 , & V_4 ) ;
if ( error )
return error ;
F_36 ( V_4 ) ;
* V_58 = V_4 ;
F_11 ( V_4 ) ;
return 0 ;
}
static bool
F_37 (
struct V_62 * V_55 )
{
struct V_1 * V_2 = V_55 -> V_60 ;
if ( ! F_38 ( V_2 ) )
return false ;
if ( ! F_39 ( V_2 ) )
return false ;
if ( ! F_40 ( V_2 , V_55 ) )
return false ;
if ( F_41 ( & V_2 -> V_63 , V_55 -> V_64 ) )
return false ;
return true ;
}
int
F_42 (
T_4 * V_55 ,
T_2 V_41 )
{
T_3 * V_2 = V_55 -> V_60 ;
int error = 0 ;
if ( ! F_37 ( V_55 ) )
return 0 ;
ASSERT ( F_33 ( V_55 , V_59 ) ) ;
if ( F_43 ( V_2 ) && ! V_55 -> V_65 ) {
error = F_32 ( V_55 , V_55 -> V_66 . V_67 , V_43 ,
V_41 & V_68 ,
& V_55 -> V_65 ) ;
if ( error )
goto V_69;
ASSERT ( V_55 -> V_65 ) ;
}
if ( F_44 ( V_2 ) && ! V_55 -> V_70 ) {
error = F_32 ( V_55 , V_55 -> V_66 . V_71 , V_45 ,
V_41 & V_68 ,
& V_55 -> V_70 ) ;
if ( error )
goto V_69;
ASSERT ( V_55 -> V_70 ) ;
}
if ( F_45 ( V_2 ) && ! V_55 -> V_72 ) {
error = F_32 ( V_55 , F_46 ( V_55 ) , V_47 ,
V_41 & V_68 ,
& V_55 -> V_72 ) ;
if ( error )
goto V_69;
ASSERT ( V_55 -> V_72 ) ;
}
V_69:
ASSERT ( F_33 ( V_55 , V_59 ) ) ;
return error ;
}
int
F_47 (
struct V_62 * V_55 ,
T_2 V_41 )
{
int error ;
if ( ! F_37 ( V_55 ) )
return 0 ;
F_48 ( V_55 , V_59 ) ;
error = F_42 ( V_55 , V_41 ) ;
F_49 ( V_55 , V_59 ) ;
return error ;
}
void
F_30 (
T_4 * V_55 )
{
if ( ! ( V_55 -> V_65 || V_55 -> V_70 || V_55 -> V_72 ) )
return;
F_50 ( V_55 ) ;
ASSERT ( ! F_41 ( & V_55 -> V_60 -> V_63 , V_55 -> V_64 ) ) ;
if ( V_55 -> V_65 ) {
F_51 ( V_55 -> V_65 ) ;
V_55 -> V_65 = NULL ;
}
if ( V_55 -> V_70 ) {
F_51 ( V_55 -> V_70 ) ;
V_55 -> V_70 = NULL ;
}
if ( V_55 -> V_72 ) {
F_51 ( V_55 -> V_72 ) ;
V_55 -> V_72 = NULL ;
}
}
static enum V_73
F_52 (
struct V_74 * V_75 ,
T_7 * V_76 ,
void * V_77 )
{
struct V_3 * V_4 = F_53 ( V_75 ,
struct V_3 , V_38 ) ;
struct V_78 * V_79 = V_77 ;
if ( ! F_54 ( V_4 ) )
goto V_80;
if ( V_4 -> V_27 ) {
F_11 ( V_4 ) ;
F_55 ( V_81 ) ;
F_56 ( V_4 ) ;
F_57 ( & V_4 -> V_38 ) ;
F_24 ( V_40 ) ;
return V_82 ;
}
if ( ! F_58 ( V_4 ) ) {
F_11 ( V_4 ) ;
goto V_80;
}
if ( F_13 ( V_4 ) ) {
struct V_28 * V_29 = NULL ;
int error ;
F_59 ( V_4 ) ;
F_60 ( V_76 ) ;
error = F_14 ( V_4 , & V_29 ) ;
if ( error ) {
F_15 ( V_4 -> V_24 , L_1 ,
V_30 , V_4 ) ;
goto V_83;
}
F_61 ( V_29 , & V_79 -> V_84 ) ;
F_17 ( V_29 ) ;
goto V_83;
}
F_20 ( V_4 ) ;
V_4 -> V_25 |= V_26 ;
F_11 ( V_4 ) ;
ASSERT ( V_4 -> V_27 == 0 ) ;
F_62 ( & V_4 -> V_38 , & V_79 -> V_85 ) ;
F_24 ( V_40 ) ;
F_63 ( V_4 ) ;
F_55 ( V_86 ) ;
return V_82 ;
V_80:
F_64 ( V_4 ) ;
F_55 ( V_87 ) ;
return V_88 ;
V_83:
F_64 ( V_4 ) ;
F_55 ( V_87 ) ;
F_11 ( V_4 ) ;
F_65 ( V_76 ) ;
return V_89 ;
}
static unsigned long
F_66 (
struct V_90 * V_91 ,
struct V_92 * V_93 )
{
struct V_6 * V_7 = F_53 ( V_91 ,
struct V_6 , V_94 ) ;
struct V_78 V_79 ;
unsigned long V_95 ;
int error ;
unsigned long V_96 = V_93 -> V_96 ;
if ( ( V_93 -> V_97 & ( V_98 | V_99 ) ) != ( V_98 | V_99 ) )
return 0 ;
F_67 ( & V_79 . V_84 ) ;
F_67 ( & V_79 . V_85 ) ;
V_95 = F_68 ( & V_7 -> V_39 , V_93 -> V_100 , F_52 , & V_79 ,
& V_96 ) ;
error = F_69 ( & V_79 . V_84 ) ;
if ( error )
F_15 ( NULL , L_2 , V_30 ) ;
while ( ! F_22 ( & V_79 . V_85 ) ) {
struct V_3 * V_4 ;
V_4 = F_70 ( & V_79 . V_85 , struct V_3 , V_38 ) ;
F_57 ( & V_4 -> V_38 ) ;
F_71 ( V_4 ) ;
}
return V_95 ;
}
static unsigned long
F_72 (
struct V_90 * V_91 ,
struct V_92 * V_93 )
{
struct V_6 * V_7 = F_53 ( V_91 ,
struct V_6 , V_94 ) ;
return F_73 ( & V_7 -> V_39 , V_93 -> V_100 ) ;
}
STATIC int
F_74 (
T_3 * V_2 )
{
T_8 * V_101 ;
int error ;
T_6 * V_4 ;
ASSERT ( F_38 ( V_2 ) ) ;
V_101 = V_2 -> V_8 = F_75 ( sizeof( T_8 ) , V_102 ) ;
error = F_76 ( & V_101 -> V_39 ) ;
if ( error )
goto V_103;
error = F_77 ( V_2 ) ;
if ( error )
goto V_104;
F_78 ( & V_101 -> V_105 , V_106 ) ;
F_78 ( & V_101 -> V_107 , V_106 ) ;
F_78 ( & V_101 -> V_108 , V_106 ) ;
F_79 ( & V_101 -> V_19 ) ;
F_79 ( & V_101 -> V_109 ) ;
V_101 -> V_110 = F_80 ( V_2 , V_111 ) ;
V_101 -> V_112 = F_81 ( V_101 -> V_110 ) ;
V_2 -> V_113 |= ( V_2 -> V_63 . V_114 & V_115 ) ;
error = F_82 ( V_2 , 0 ,
F_83 ( V_2 ) ? V_43 :
( F_84 ( V_2 ) ? V_45 :
V_47 ) ,
V_61 , & V_4 ) ;
if ( ! error ) {
T_9 * V_116 = & V_4 -> V_20 ;
V_101 -> V_117 = V_116 -> V_118 ?
F_7 ( V_116 -> V_118 ) : V_119 ;
V_101 -> V_120 = V_116 -> V_121 ?
F_7 ( V_116 -> V_121 ) : V_122 ;
V_101 -> V_123 = V_116 -> V_124 ?
F_7 ( V_116 -> V_124 ) : V_125 ;
V_101 -> V_126 = V_116 -> V_127 ?
F_85 ( V_116 -> V_127 ) : V_128 ;
V_101 -> V_129 = V_116 -> V_130 ?
F_85 ( V_116 -> V_130 ) : V_131 ;
V_101 -> V_132 = V_116 -> V_133 ?
F_85 ( V_116 -> V_133 ) : V_134 ;
V_101 -> V_135 = F_86 ( V_116 -> V_136 ) ;
V_101 -> V_137 = F_86 ( V_116 -> V_138 ) ;
V_101 -> V_139 = F_86 ( V_116 -> V_140 ) ;
V_101 -> V_141 = F_86 ( V_116 -> V_142 ) ;
V_101 -> V_143 = F_86 ( V_116 -> V_144 ) ;
V_101 -> V_145 = F_86 ( V_116 -> V_146 ) ;
F_25 ( V_4 ) ;
} else {
V_101 -> V_117 = V_119 ;
V_101 -> V_120 = V_122 ;
V_101 -> V_123 = V_125 ;
V_101 -> V_126 = V_128 ;
V_101 -> V_129 = V_131 ;
V_101 -> V_132 = V_134 ;
}
V_101 -> V_94 . V_147 = F_72 ;
V_101 -> V_94 . V_148 = F_66 ;
V_101 -> V_94 . V_149 = V_150 ;
V_101 -> V_94 . V_41 = V_151 ;
F_87 ( & V_101 -> V_94 ) ;
return 0 ;
V_104:
F_88 ( & V_101 -> V_39 ) ;
V_103:
F_89 ( V_101 ) ;
V_2 -> V_8 = NULL ;
return error ;
}
void
F_28 (
T_3 * V_2 )
{
T_8 * V_7 ;
V_7 = V_2 -> V_8 ;
ASSERT ( V_7 != NULL ) ;
F_90 ( & V_7 -> V_94 ) ;
F_88 ( & V_7 -> V_39 ) ;
if ( V_7 -> V_52 ) {
F_31 ( V_7 -> V_52 ) ;
V_7 -> V_52 = NULL ;
}
if ( V_7 -> V_53 ) {
F_31 ( V_7 -> V_53 ) ;
V_7 -> V_53 = NULL ;
}
if ( V_7 -> V_54 ) {
F_31 ( V_7 -> V_54 ) ;
V_7 -> V_54 = NULL ;
}
F_91 ( & V_7 -> V_109 ) ;
F_89 ( V_7 ) ;
V_2 -> V_8 = NULL ;
}
STATIC int
F_92 (
T_3 * V_2 ,
T_4 * * V_55 ,
T_10 V_152 ,
T_2 V_41 )
{
T_11 * V_153 ;
int error ;
int V_154 ;
* V_55 = NULL ;
if ( ! F_93 ( & V_2 -> V_63 ) &&
( V_41 & ( V_46 | V_44 ) ) ) {
T_12 V_155 = V_156 ;
if ( ( V_41 & V_46 ) &&
( V_2 -> V_63 . V_157 != V_156 ) ) {
V_155 = V_2 -> V_63 . V_157 ;
ASSERT ( V_2 -> V_63 . V_158 == V_156 ) ;
} else if ( ( V_41 & V_44 ) &&
( V_2 -> V_63 . V_158 != V_156 ) ) {
V_155 = V_2 -> V_63 . V_158 ;
ASSERT ( V_2 -> V_63 . V_157 == V_156 ) ;
}
if ( V_155 != V_156 ) {
error = F_94 ( V_2 , NULL , V_155 , 0 , 0 , V_55 ) ;
if ( error )
return error ;
V_2 -> V_63 . V_157 = V_156 ;
V_2 -> V_63 . V_158 = V_156 ;
}
}
V_153 = F_95 ( V_2 , V_159 ) ;
error = F_96 ( V_153 , & F_97 ( V_2 ) -> V_160 ,
F_98 ( V_2 ) , 0 ) ;
if ( error ) {
F_99 ( V_153 , 0 ) ;
return error ;
}
if ( ! * V_55 ) {
error = F_100 ( & V_153 , NULL , V_161 , 1 , 0 , 0 , 1 , V_55 ,
& V_154 ) ;
if ( error ) {
F_99 ( V_153 , V_162 |
V_163 ) ;
return error ;
}
}
F_65 ( & V_2 -> V_164 ) ;
if ( V_41 & V_165 ) {
ASSERT ( ! F_101 ( & V_2 -> V_63 ) ) ;
ASSERT ( ( V_152 & ( V_166 | V_167 |
V_168 | V_169 | V_170 ) ) ==
( V_166 | V_167 |
V_168 | V_169 |
V_170 ) ) ;
F_102 ( & V_2 -> V_63 ) ;
V_2 -> V_63 . V_171 = V_156 ;
V_2 -> V_63 . V_157 = V_156 ;
V_2 -> V_63 . V_158 = V_156 ;
V_2 -> V_63 . V_114 = V_2 -> V_113 & V_172 ;
}
if ( V_41 & V_42 )
V_2 -> V_63 . V_171 = ( * V_55 ) -> V_64 ;
else if ( V_41 & V_44 )
V_2 -> V_63 . V_157 = ( * V_55 ) -> V_64 ;
else
V_2 -> V_63 . V_158 = ( * V_55 ) -> V_64 ;
F_60 ( & V_2 -> V_164 ) ;
F_103 ( V_153 , V_152 ) ;
if ( ( error = F_104 ( V_153 , V_162 ) ) ) {
F_105 ( V_2 , L_3 , V_30 , error ) ;
return error ;
}
return 0 ;
}
STATIC void
F_106 (
T_3 * V_2 ,
T_13 * V_29 ,
T_5 V_56 ,
T_2 type )
{
struct V_173 * V_174 ;
int V_175 ;
F_107 ( V_29 , V_176 ) ;
#ifdef F_108
V_175 = F_109 ( V_2 , V_111 ) ;
F_110 ( V_175 , sizeof( V_177 ) ) ;
ASSERT ( V_2 -> V_8 -> V_112 == V_175 ) ;
#endif
V_174 = V_29 -> V_178 ;
for ( V_175 = 0 ; V_175 < V_2 -> V_8 -> V_112 ; V_175 ++ ) {
struct V_179 * V_180 ;
V_180 = (struct V_179 * ) & V_174 [ V_175 ] ;
F_111 ( V_2 , V_180 , V_56 + V_175 , type , V_181 ,
L_4 ) ;
V_180 -> V_182 = 0 ;
V_180 -> V_183 = 0 ;
V_180 -> V_184 = 0 ;
V_180 -> V_118 = 0 ;
V_180 -> V_121 = 0 ;
V_180 -> V_124 = 0 ;
V_180 -> V_127 = 0 ;
V_180 -> V_130 = 0 ;
V_180 -> V_133 = 0 ;
if ( F_112 ( & V_2 -> V_63 ) ) {
F_113 ( ( char * ) & V_174 [ V_175 ] ,
sizeof( struct V_173 ) ,
V_185 ) ;
}
}
}
STATIC int
F_114 (
struct V_1 * V_2 ,
T_5 V_186 ,
T_14 V_187 ,
T_15 V_188 ,
T_2 V_41 ,
struct V_74 * V_189 )
{
struct V_28 * V_29 ;
int error ;
int type ;
ASSERT ( V_188 > 0 ) ;
type = V_41 & V_42 ? V_43 :
( V_41 & V_46 ? V_47 : V_45 ) ;
error = 0 ;
while ( V_188 -- ) {
error = F_115 ( V_2 , NULL , V_2 -> V_190 ,
F_116 ( V_2 , V_187 ) ,
V_2 -> V_8 -> V_110 , 0 , & V_29 ,
& V_191 ) ;
if ( error == - V_23 ) {
error = F_115 ( V_2 , NULL , V_2 -> V_190 ,
F_116 ( V_2 , V_187 ) ,
V_2 -> V_8 -> V_110 , 0 , & V_29 ,
NULL ) ;
}
if ( error )
break;
V_29 -> V_192 = & V_191 ;
F_106 ( V_2 , V_29 , V_186 , type ) ;
F_61 ( V_29 , V_189 ) ;
F_17 ( V_29 ) ;
V_187 ++ ;
V_186 += V_2 -> V_8 -> V_112 ;
}
return error ;
}
STATIC int
F_117 (
struct V_1 * V_2 ,
struct V_62 * V_193 ,
T_2 V_41 ,
struct V_74 * V_189 )
{
struct V_194 * V_195 ;
int V_18 , V_196 ;
int error ;
T_16 V_197 ;
T_15 V_198 ;
T_5 V_186 ;
T_14 V_199 ;
T_15 V_200 ;
error = 0 ;
if ( V_193 -> V_66 . V_201 == 0 )
return 0 ;
V_195 = F_118 ( V_202 * sizeof( * V_195 ) , V_102 ) ;
V_197 = 0 ;
V_198 = F_119 ( V_2 , V_2 -> V_203 -> V_204 ) ;
do {
T_2 V_205 ;
V_196 = V_202 ;
V_205 = F_120 ( V_193 ) ;
error = F_121 ( V_193 , V_197 , V_198 - V_197 ,
V_195 , & V_196 , 0 ) ;
F_49 ( V_193 , V_205 ) ;
if ( error )
break;
ASSERT ( V_196 <= V_202 ) ;
for ( V_18 = 0 ; V_18 < V_196 ; V_18 ++ ) {
ASSERT ( V_195 [ V_18 ] . V_206 != V_207 ) ;
ASSERT ( V_195 [ V_18 ] . V_208 ) ;
V_197 += V_195 [ V_18 ] . V_208 ;
if ( V_195 [ V_18 ] . V_206 == V_209 )
continue;
V_186 = ( T_5 ) V_195 [ V_18 ] . V_210 *
V_2 -> V_8 -> V_112 ;
if ( ( V_18 + 1 < V_196 ) &&
( V_195 [ V_18 + 1 ] . V_206 != V_209 ) ) {
V_200 = V_195 [ V_18 + 1 ] . V_208 ;
V_199 = V_195 [ V_18 + 1 ] . V_206 ;
while ( V_200 -- ) {
F_122 ( V_2 -> V_190 ,
F_116 ( V_2 , V_199 ) ,
V_2 -> V_8 -> V_110 ,
& V_191 ) ;
V_199 ++ ;
}
}
error = F_114 ( V_2 , V_186 ,
V_195 [ V_18 ] . V_206 ,
V_195 [ V_18 ] . V_208 ,
V_41 , V_189 ) ;
if ( error )
goto V_211;
}
} while ( V_196 > 0 );
V_211:
F_89 ( V_195 ) ;
return error ;
}
STATIC int
F_123 (
struct V_62 * V_55 ,
T_5 V_56 ,
T_2 type ,
T_17 V_212 ,
T_17 V_213 )
{
struct V_1 * V_2 = V_55 -> V_60 ;
struct V_3 * V_4 ;
int error ;
error = F_35 ( V_2 , V_55 , V_56 , type ,
V_68 | V_61 , & V_4 ) ;
if ( error ) {
ASSERT ( error != - V_214 ) ;
ASSERT ( error != - V_215 ) ;
return error ;
}
F_124 ( V_4 ) ;
F_125 ( & V_4 -> V_20 . V_183 , 1 ) ;
V_4 -> V_216 ++ ;
if ( V_212 ) {
F_125 ( & V_4 -> V_20 . V_182 , V_212 ) ;
V_4 -> V_217 += V_212 ;
}
if ( V_213 ) {
F_125 ( & V_4 -> V_20 . V_184 , V_213 ) ;
V_4 -> V_218 += V_213 ;
}
if ( V_4 -> V_20 . V_21 ) {
F_126 ( V_2 , V_4 ) ;
F_127 ( V_2 , & V_4 -> V_20 ) ;
}
V_4 -> V_25 |= V_219 ;
F_128 ( V_4 ) ;
return 0 ;
}
STATIC int
F_129 (
T_4 * V_55 ,
T_17 * V_220 )
{
T_15 V_213 ;
T_18 V_221 ;
T_19 * V_222 ;
T_18 V_223 ;
int error ;
ASSERT ( F_130 ( V_55 ) ) ;
V_222 = F_131 ( V_55 , V_224 ) ;
if ( ! ( V_222 -> V_225 & V_226 ) ) {
if ( ( error = F_132 ( NULL , V_55 , V_224 ) ) )
return error ;
}
V_213 = 0 ;
V_223 = V_222 -> V_227 / ( T_2 ) sizeof( V_228 ) ;
for ( V_221 = 0 ; V_221 < V_223 ; V_221 ++ )
V_213 += F_133 ( F_134 ( V_222 , V_221 ) ) ;
* V_220 = ( T_17 ) V_213 ;
return 0 ;
}
STATIC int
F_135 (
T_3 * V_2 ,
T_12 V_155 ,
void T_20 * V_229 ,
int V_230 ,
int * V_231 ,
int * V_232 )
{
T_4 * V_55 ;
T_17 V_212 , V_213 = 0 ;
int error ;
ASSERT ( F_38 ( V_2 ) ) ;
if ( F_41 ( & V_2 -> V_63 , V_155 ) ) {
* V_232 = V_233 ;
return - V_234 ;
}
error = F_94 ( V_2 , NULL , V_155 , 0 , V_59 , & V_55 ) ;
if ( error ) {
* V_232 = V_233 ;
return error ;
}
ASSERT ( V_55 -> V_235 == 0 ) ;
if ( F_130 ( V_55 ) ) {
error = F_129 ( V_55 , & V_213 ) ;
if ( error )
goto V_236;
}
V_212 = ( T_17 ) V_55 -> V_66 . V_201 - V_213 ;
if ( F_43 ( V_2 ) ) {
error = F_123 ( V_55 , V_55 -> V_66 . V_67 ,
V_43 , V_212 , V_213 ) ;
if ( error )
goto V_236;
}
if ( F_44 ( V_2 ) ) {
error = F_123 ( V_55 , V_55 -> V_66 . V_71 ,
V_45 , V_212 , V_213 ) ;
if ( error )
goto V_236;
}
if ( F_45 ( V_2 ) ) {
error = F_123 ( V_55 , F_46 ( V_55 ) ,
V_47 , V_212 , V_213 ) ;
if ( error )
goto V_236;
}
F_49 ( V_55 , V_59 ) ;
F_31 ( V_55 ) ;
* V_232 = V_237 ;
return 0 ;
V_236:
F_49 ( V_55 , V_59 ) ;
F_31 ( V_55 ) ;
* V_232 = V_238 ;
return error ;
}
STATIC int
F_136 (
struct V_3 * V_4 ,
void * V_5 )
{
struct V_74 * V_189 = V_5 ;
struct V_28 * V_29 = NULL ;
int error = 0 ;
F_10 ( V_4 ) ;
if ( V_4 -> V_25 & V_26 )
goto V_239;
if ( ! F_13 ( V_4 ) )
goto V_239;
F_12 ( V_4 ) ;
error = F_14 ( V_4 , & V_29 ) ;
if ( error )
goto V_239;
F_61 ( V_29 , V_189 ) ;
F_17 ( V_29 ) ;
V_239:
F_11 ( V_4 ) ;
return error ;
}
STATIC int
F_137 (
T_3 * V_2 )
{
int V_69 , V_240 , error , V_241 ;
T_12 V_242 ;
T_21 V_243 ;
T_2 V_41 ;
F_138 ( V_189 ) ;
struct V_62 * V_244 = V_2 -> V_8 -> V_52 ;
struct V_62 * V_245 = V_2 -> V_8 -> V_53 ;
struct V_62 * V_246 = V_2 -> V_8 -> V_54 ;
V_240 = V_247 ;
V_243 = 1 ;
V_242 = 0 ;
V_41 = 0 ;
ASSERT ( V_244 || V_245 || V_246 ) ;
ASSERT ( F_38 ( V_2 ) ) ;
F_139 ( V_2 , L_5 ) ;
if ( V_244 ) {
error = F_117 ( V_2 , V_244 , V_42 ,
& V_189 ) ;
if ( error )
goto V_248;
V_41 |= V_249 ;
}
if ( V_245 ) {
error = F_117 ( V_2 , V_245 , V_44 ,
& V_189 ) ;
if ( error )
goto V_248;
V_41 |= V_250 ;
}
if ( V_246 ) {
error = F_117 ( V_2 , V_246 , V_46 ,
& V_189 ) ;
if ( error )
goto V_248;
V_41 |= V_251 ;
}
do {
error = F_140 ( V_2 , & V_242 , & V_240 ,
F_135 ,
V_243 , NULL , & V_69 ) ;
if ( error )
break;
} while ( ! V_69 );
if ( F_43 ( V_2 ) ) {
error = F_1 ( V_2 , V_43 , F_136 ,
& V_189 ) ;
}
if ( F_44 ( V_2 ) ) {
V_241 = F_1 ( V_2 , V_45 , F_136 ,
& V_189 ) ;
if ( ! error )
error = V_241 ;
}
if ( F_45 ( V_2 ) ) {
V_241 = F_1 ( V_2 , V_47 , F_136 ,
& V_189 ) ;
if ( ! error )
error = V_241 ;
}
V_241 = F_69 ( & V_189 ) ;
if ( ! error )
error = V_241 ;
if ( error ) {
F_26 ( V_2 , V_48 ) ;
goto V_248;
}
V_2 -> V_113 &= ~ V_115 ;
V_2 -> V_113 |= V_41 ;
V_248:
while ( ! F_22 ( & V_189 ) ) {
struct V_28 * V_29 =
F_70 ( & V_189 , struct V_28 , V_252 ) ;
F_57 ( & V_29 -> V_252 ) ;
F_17 ( V_29 ) ;
}
if ( error ) {
F_15 ( V_2 ,
L_6 ,
error ) ;
ASSERT ( V_2 -> V_8 != NULL ) ;
F_28 ( V_2 ) ;
if ( F_141 ( V_2 ) ) {
F_15 ( V_2 ,
L_7 ) ;
}
} else
F_139 ( V_2 , L_8 ) ;
return error ;
}
void
F_142 (
struct V_1 * V_2 )
{
int error = 0 ;
T_2 V_253 ;
if ( V_2 -> V_63 . V_254 ) {
F_139 ( V_2 , L_9 ) ;
V_2 -> V_113 = 0 ;
goto V_255;
}
ASSERT ( F_38 ( V_2 ) ) ;
error = F_74 ( V_2 ) ;
if ( error ) {
ASSERT ( V_2 -> V_8 == NULL ) ;
V_2 -> V_113 = 0 ;
goto V_255;
}
if ( F_143 ( V_2 ) ) {
error = F_137 ( V_2 ) ;
if ( error ) {
return;
}
}
if ( ! F_43 ( V_2 ) )
V_2 -> V_113 &= ~ V_249 ;
if ( ! F_44 ( V_2 ) )
V_2 -> V_113 &= ~ V_250 ;
if ( ! F_45 ( V_2 ) )
V_2 -> V_113 &= ~ V_251 ;
V_255:
F_65 ( & V_2 -> V_164 ) ;
V_253 = V_2 -> V_63 . V_114 ;
V_2 -> V_63 . V_114 = V_2 -> V_113 & V_256 ;
F_60 ( & V_2 -> V_164 ) ;
if ( V_253 != ( V_2 -> V_113 & V_256 ) ) {
if ( F_144 ( V_2 , V_170 ) ) {
ASSERT ( ! ( F_38 ( V_2 ) ) ) ;
F_105 ( V_2 , L_10 ,
V_30 ) ;
}
}
if ( error ) {
F_15 ( V_2 , L_11 ) ;
return;
}
}
STATIC int
F_77 (
T_3 * V_2 )
{
struct V_62 * V_244 = NULL ;
struct V_62 * V_245 = NULL ;
struct V_62 * V_246 = NULL ;
int error ;
T_10 V_257 = 0 ;
T_2 V_41 = 0 ;
ASSERT ( V_2 -> V_8 ) ;
if ( F_101 ( & V_2 -> V_63 ) ) {
if ( F_43 ( V_2 ) &&
V_2 -> V_63 . V_171 != V_156 ) {
ASSERT ( V_2 -> V_63 . V_171 > 0 ) ;
error = F_94 ( V_2 , NULL , V_2 -> V_63 . V_171 ,
0 , 0 , & V_244 ) ;
if ( error )
return error ;
}
if ( F_44 ( V_2 ) &&
V_2 -> V_63 . V_157 != V_156 ) {
ASSERT ( V_2 -> V_63 . V_157 > 0 ) ;
error = F_94 ( V_2 , NULL , V_2 -> V_63 . V_157 ,
0 , 0 , & V_245 ) ;
if ( error )
goto V_258;
}
if ( F_45 ( V_2 ) &&
V_2 -> V_63 . V_158 != V_156 ) {
ASSERT ( V_2 -> V_63 . V_158 > 0 ) ;
error = F_94 ( V_2 , NULL , V_2 -> V_63 . V_158 ,
0 , 0 , & V_246 ) ;
if ( error )
goto V_258;
}
} else {
V_41 |= V_165 ;
V_257 |= ( V_166 | V_167 |
V_168 | V_169 |
V_170 ) ;
}
if ( F_43 ( V_2 ) && V_244 == NULL ) {
error = F_92 ( V_2 , & V_244 ,
V_257 | V_167 ,
V_41 | V_42 ) ;
if ( error )
goto V_258;
V_41 &= ~ V_165 ;
}
if ( F_44 ( V_2 ) && V_245 == NULL ) {
error = F_92 ( V_2 , & V_245 ,
V_257 | V_168 ,
V_41 | V_44 ) ;
if ( error )
goto V_258;
V_41 &= ~ V_165 ;
}
if ( F_45 ( V_2 ) && V_246 == NULL ) {
error = F_92 ( V_2 , & V_246 ,
V_257 | V_169 ,
V_41 | V_46 ) ;
if ( error )
goto V_258;
}
V_2 -> V_8 -> V_52 = V_244 ;
V_2 -> V_8 -> V_53 = V_245 ;
V_2 -> V_8 -> V_54 = V_246 ;
return 0 ;
V_258:
if ( V_244 )
F_31 ( V_244 ) ;
if ( V_245 )
F_31 ( V_245 ) ;
if ( V_246 )
F_31 ( V_246 ) ;
return error ;
}
STATIC void
F_71 (
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_24 ;
struct V_6 * V_7 = V_2 -> V_8 ;
F_4 ( & V_7 -> V_19 ) ;
F_21 ( F_3 ( V_7 , V_4 -> V_20 . V_36 ) ,
F_7 ( V_4 -> V_20 . V_21 ) ) ;
V_7 -> V_37 -- ;
F_6 ( & V_7 -> V_19 ) ;
F_25 ( V_4 ) ;
}
int
F_144 (
T_3 * V_2 ,
T_10 V_41 )
{
T_11 * V_153 ;
int error ;
V_153 = F_95 ( V_2 , V_259 ) ;
error = F_96 ( V_153 , & F_97 ( V_2 ) -> V_260 , 0 , 0 ) ;
if ( error ) {
F_99 ( V_153 , 0 ) ;
return error ;
}
F_103 ( V_153 , V_41 ) ;
error = F_104 ( V_153 , 0 ) ;
return error ;
}
int
F_145 (
struct V_62 * V_55 ,
T_5 V_261 ,
T_5 V_262 ,
T_22 V_263 ,
T_2 V_41 ,
struct V_3 * * V_264 ,
struct V_3 * * V_265 ,
struct V_3 * * V_266 )
{
struct V_1 * V_2 = V_55 -> V_60 ;
struct V_3 * V_267 = NULL ;
struct V_3 * V_268 = NULL ;
struct V_3 * V_269 = NULL ;
int error ;
T_2 V_270 ;
if ( ! F_38 ( V_2 ) || ! F_39 ( V_2 ) )
return 0 ;
V_270 = V_59 ;
F_48 ( V_55 , V_270 ) ;
if ( ( V_41 & V_271 ) && F_146 ( V_55 ) )
V_262 = V_55 -> V_66 . V_71 ;
if ( F_40 ( V_2 , V_55 ) ) {
error = F_42 ( V_55 , V_68 ) ;
if ( error ) {
F_49 ( V_55 , V_270 ) ;
return error ;
}
}
if ( ( V_41 & V_42 ) && F_43 ( V_2 ) ) {
if ( V_55 -> V_66 . V_67 != V_261 ) {
F_49 ( V_55 , V_270 ) ;
error = F_35 ( V_2 , NULL , V_261 ,
V_43 ,
V_68 |
V_61 ,
& V_267 ) ;
if ( error ) {
ASSERT ( error != - V_215 ) ;
return error ;
}
F_11 ( V_267 ) ;
V_270 = V_272 ;
F_48 ( V_55 , V_270 ) ;
} else {
ASSERT ( V_55 -> V_65 ) ;
V_267 = F_147 ( V_55 -> V_65 ) ;
}
}
if ( ( V_41 & V_44 ) && F_44 ( V_2 ) ) {
if ( V_55 -> V_66 . V_71 != V_262 ) {
F_49 ( V_55 , V_270 ) ;
error = F_35 ( V_2 , NULL , V_262 ,
V_45 ,
V_68 |
V_61 ,
& V_268 ) ;
if ( error ) {
ASSERT ( error != - V_215 ) ;
goto V_258;
}
F_11 ( V_268 ) ;
V_270 = V_272 ;
F_48 ( V_55 , V_270 ) ;
} else {
ASSERT ( V_55 -> V_70 ) ;
V_268 = F_147 ( V_55 -> V_70 ) ;
}
}
if ( ( V_41 & V_46 ) && F_45 ( V_2 ) ) {
if ( F_46 ( V_55 ) != V_263 ) {
F_49 ( V_55 , V_270 ) ;
error = F_35 ( V_2 , NULL , ( T_5 ) V_263 ,
V_47 ,
V_68 |
V_61 ,
& V_269 ) ;
if ( error ) {
ASSERT ( error != - V_215 ) ;
goto V_258;
}
F_11 ( V_269 ) ;
V_270 = V_272 ;
F_48 ( V_55 , V_270 ) ;
} else {
ASSERT ( V_55 -> V_72 ) ;
V_269 = F_147 ( V_55 -> V_72 ) ;
}
}
if ( V_267 )
F_148 ( V_55 ) ;
F_49 ( V_55 , V_270 ) ;
if ( V_264 )
* V_264 = V_267 ;
else if ( V_267 )
F_51 ( V_267 ) ;
if ( V_265 )
* V_265 = V_268 ;
else if ( V_268 )
F_51 ( V_268 ) ;
if ( V_266 )
* V_266 = V_269 ;
else if ( V_269 )
F_51 ( V_269 ) ;
return 0 ;
V_258:
if ( V_268 )
F_51 ( V_268 ) ;
if ( V_267 )
F_51 ( V_267 ) ;
return error ;
}
T_6 *
F_149 (
T_11 * V_153 ,
T_4 * V_55 ,
T_6 * * V_273 ,
T_6 * V_274 )
{
T_6 * V_275 ;
T_2 V_276 = F_130 ( V_55 ) ?
V_277 : V_278 ;
ASSERT ( F_33 ( V_55 , V_59 ) ) ;
ASSERT ( F_38 ( V_55 -> V_60 ) ) ;
V_275 = * V_273 ;
ASSERT ( V_275 ) ;
ASSERT ( V_275 != V_274 ) ;
F_150 ( V_153 , V_275 , V_276 , - ( V_55 -> V_66 . V_201 ) ) ;
F_150 ( V_153 , V_275 , V_279 , - 1 ) ;
F_150 ( V_153 , V_274 , V_276 , V_55 -> V_66 . V_201 ) ;
F_150 ( V_153 , V_274 , V_279 , 1 ) ;
* V_273 = F_147 ( V_274 ) ;
return V_275 ;
}
int
F_151 (
struct V_280 * V_153 ,
struct V_62 * V_55 ,
struct V_3 * V_281 ,
struct V_3 * V_282 ,
struct V_3 * V_283 ,
T_2 V_41 )
{
struct V_1 * V_2 = V_55 -> V_60 ;
T_2 V_284 , V_285 , V_286 = 0 ;
struct V_3 * V_287 = NULL ;
struct V_3 * V_288 = NULL ;
struct V_3 * V_289 = NULL ;
struct V_3 * V_290 = NULL ;
struct V_3 * V_291 = NULL ;
struct V_3 * V_292 = NULL ;
int error ;
ASSERT ( F_33 ( V_55 , V_59 | V_272 ) ) ;
ASSERT ( F_38 ( V_2 ) ) ;
V_284 = V_55 -> V_235 ;
V_285 = F_130 ( V_55 ) ?
V_293 : V_294 ;
if ( F_43 ( V_2 ) && V_281 &&
V_55 -> V_66 . V_67 != F_7 ( V_281 -> V_20 . V_21 ) ) {
V_290 = V_281 ;
if ( V_284 ) {
ASSERT ( V_55 -> V_65 ) ;
V_287 = V_55 -> V_65 ;
}
}
if ( F_44 ( V_55 -> V_60 ) && V_282 &&
V_55 -> V_66 . V_71 != F_7 ( V_282 -> V_20 . V_21 ) ) {
V_291 = V_282 ;
if ( V_284 ) {
ASSERT ( V_55 -> V_70 ) ;
V_288 = V_55 -> V_70 ;
}
}
if ( F_45 ( V_55 -> V_60 ) && V_283 &&
F_46 ( V_55 ) != F_7 ( V_283 -> V_20 . V_21 ) ) {
V_286 = V_295 ;
V_292 = V_283 ;
if ( V_284 ) {
ASSERT ( V_55 -> V_72 ) ;
V_289 = V_55 -> V_72 ;
}
}
error = F_152 ( V_153 , V_55 -> V_60 ,
V_290 , V_291 , V_292 ,
V_55 -> V_66 . V_201 , 1 ,
V_41 | V_285 | V_286 ) ;
if ( error )
return error ;
if ( V_284 ) {
ASSERT ( V_290 || V_291 || V_292 ) ;
ASSERT ( V_287 || V_288 || V_289 ) ;
error = F_152 ( NULL , V_55 -> V_60 ,
V_290 , V_291 , V_292 ,
( T_17 ) V_284 , 0 ,
V_41 | V_285 | V_286 ) ;
if ( error )
return error ;
F_152 ( NULL , V_55 -> V_60 ,
V_287 , V_288 , V_289 ,
- ( ( T_17 ) V_284 ) , 0 , V_285 ) ;
}
return 0 ;
}
int
F_153 (
struct V_62 * * V_296 )
{
struct V_1 * V_2 = V_296 [ 0 ] -> V_60 ;
int V_18 ;
if ( ! F_38 ( V_2 ) || ! F_39 ( V_2 ) )
return 0 ;
for ( V_18 = 0 ; ( V_18 < 4 && V_296 [ V_18 ] ) ; V_18 ++ ) {
struct V_62 * V_55 = V_296 [ V_18 ] ;
int error ;
if ( V_18 == 0 || V_55 != V_296 [ V_18 - 1 ] ) {
if ( F_40 ( V_2 , V_55 ) ) {
error = F_47 ( V_55 , 0 ) ;
if ( error )
return error ;
}
}
}
return 0 ;
}
void
F_154 (
struct V_280 * V_153 ,
struct V_62 * V_55 ,
struct V_3 * V_281 ,
struct V_3 * V_282 ,
struct V_3 * V_283 )
{
struct V_1 * V_2 = V_153 -> V_297 ;
if ( ! F_38 ( V_2 ) || ! F_39 ( V_2 ) )
return;
ASSERT ( F_33 ( V_55 , V_59 ) ) ;
ASSERT ( F_38 ( V_2 ) ) ;
if ( V_281 && F_43 ( V_2 ) ) {
ASSERT ( V_55 -> V_65 == NULL ) ;
ASSERT ( V_55 -> V_66 . V_67 == F_7 ( V_281 -> V_20 . V_21 ) ) ;
V_55 -> V_65 = F_147 ( V_281 ) ;
F_150 ( V_153 , V_281 , V_279 , 1 ) ;
}
if ( V_282 && F_44 ( V_2 ) ) {
ASSERT ( V_55 -> V_70 == NULL ) ;
ASSERT ( V_55 -> V_66 . V_71 == F_7 ( V_282 -> V_20 . V_21 ) ) ;
V_55 -> V_70 = F_147 ( V_282 ) ;
F_150 ( V_153 , V_282 , V_279 , 1 ) ;
}
if ( V_283 && F_45 ( V_2 ) ) {
ASSERT ( V_55 -> V_72 == NULL ) ;
ASSERT ( F_46 ( V_55 ) == F_7 ( V_283 -> V_20 . V_21 ) ) ;
V_55 -> V_72 = F_147 ( V_283 ) ;
F_150 ( V_153 , V_283 , V_279 , 1 ) ;
}
}
