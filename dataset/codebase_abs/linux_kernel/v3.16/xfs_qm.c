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
if ( error == V_22 ) {
V_13 ++ ;
continue;
}
if ( error && V_12 != V_23 )
V_12 = error ;
}
F_6 ( & V_7 -> V_19 ) ;
if ( V_12 == V_23 ) {
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
return V_22 ;
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
int error = 0 ;
T_2 V_49 ;
if ( V_2 -> V_50 . V_51 ) {
F_30 ( V_2 , L_2 ) ;
V_2 -> V_52 = 0 ;
goto V_53;
}
ASSERT ( F_31 ( V_2 ) ) ;
error = F_32 ( V_2 ) ;
if ( error ) {
ASSERT ( V_2 -> V_8 == NULL ) ;
V_2 -> V_52 = 0 ;
goto V_53;
}
if ( F_33 ( V_2 ) ) {
error = F_34 ( V_2 ) ;
if ( error ) {
return;
}
}
if ( ! F_35 ( V_2 ) )
V_2 -> V_52 &= ~ V_54 ;
if ( ! F_36 ( V_2 ) )
V_2 -> V_52 &= ~ V_55 ;
if ( ! F_37 ( V_2 ) )
V_2 -> V_52 &= ~ V_56 ;
V_53:
F_38 ( & V_2 -> V_57 ) ;
V_49 = V_2 -> V_50 . V_58 ;
V_2 -> V_50 . V_58 = V_2 -> V_52 & V_59 ;
F_39 ( & V_2 -> V_57 ) ;
if ( V_49 != ( V_2 -> V_52 & V_59 ) ) {
if ( F_40 ( V_2 , V_60 ) ) {
ASSERT ( ! ( F_31 ( V_2 ) ) ) ;
F_41 ( V_2 , L_3 ,
V_30 ) ;
}
}
if ( error ) {
F_15 ( V_2 , L_4 ) ;
return;
}
}
void
F_42 (
T_3 * V_2 )
{
ASSERT ( V_2 -> V_61 ) ;
F_43 ( V_2 -> V_61 ) ;
if ( V_2 -> V_62 )
F_43 ( V_2 -> V_62 ) ;
if ( V_2 -> V_63 )
F_43 ( V_2 -> V_63 ) ;
if ( V_2 -> V_8 ) {
if ( V_2 -> V_8 -> V_64 ) {
F_44 ( V_2 -> V_8 -> V_64 ) ;
V_2 -> V_8 -> V_64 = NULL ;
}
if ( V_2 -> V_8 -> V_65 ) {
F_44 ( V_2 -> V_8 -> V_65 ) ;
V_2 -> V_8 -> V_65 = NULL ;
}
if ( V_2 -> V_8 -> V_66 ) {
F_44 ( V_2 -> V_8 -> V_66 ) ;
V_2 -> V_8 -> V_66 = NULL ;
}
}
}
STATIC int
F_45 (
T_4 * V_67 ,
T_5 V_68 ,
T_2 type ,
T_2 V_69 ,
T_6 * * V_70 )
{
T_6 * V_4 ;
int error ;
ASSERT ( F_46 ( V_67 , V_71 ) ) ;
error = 0 ;
V_4 = * V_70 ;
if ( V_4 ) {
F_47 ( V_4 ) ;
return 0 ;
}
error = F_48 ( V_67 -> V_72 , V_67 , V_68 , type ,
V_69 | V_73 , & V_4 ) ;
if ( error )
return error ;
F_49 ( V_4 ) ;
* V_70 = V_4 ;
F_11 ( V_4 ) ;
return 0 ;
}
static bool
F_50 (
struct V_74 * V_67 )
{
struct V_1 * V_2 = V_67 -> V_72 ;
if ( ! F_31 ( V_2 ) )
return false ;
if ( ! F_51 ( V_2 ) )
return false ;
if ( ! F_52 ( V_2 , V_67 ) )
return false ;
if ( F_53 ( & V_2 -> V_50 , V_67 -> V_75 ) )
return false ;
return true ;
}
int
F_54 (
T_4 * V_67 ,
T_2 V_41 )
{
T_3 * V_2 = V_67 -> V_72 ;
int error = 0 ;
if ( ! F_50 ( V_67 ) )
return 0 ;
ASSERT ( F_46 ( V_67 , V_71 ) ) ;
if ( F_35 ( V_2 ) && ! V_67 -> V_76 ) {
error = F_45 ( V_67 , V_67 -> V_77 . V_78 , V_43 ,
V_41 & V_79 ,
& V_67 -> V_76 ) ;
if ( error )
goto V_80;
ASSERT ( V_67 -> V_76 ) ;
}
if ( F_36 ( V_2 ) && ! V_67 -> V_81 ) {
error = F_45 ( V_67 , V_67 -> V_77 . V_82 , V_45 ,
V_41 & V_79 ,
& V_67 -> V_81 ) ;
if ( error )
goto V_80;
ASSERT ( V_67 -> V_81 ) ;
}
if ( F_37 ( V_2 ) && ! V_67 -> V_83 ) {
error = F_45 ( V_67 , F_55 ( V_67 ) , V_47 ,
V_41 & V_79 ,
& V_67 -> V_83 ) ;
if ( error )
goto V_80;
ASSERT ( V_67 -> V_83 ) ;
}
V_80:
ASSERT ( F_46 ( V_67 , V_71 ) ) ;
return error ;
}
int
F_56 (
struct V_74 * V_67 ,
T_2 V_41 )
{
int error ;
if ( ! F_50 ( V_67 ) )
return 0 ;
F_57 ( V_67 , V_71 ) ;
error = F_54 ( V_67 , V_41 ) ;
F_58 ( V_67 , V_71 ) ;
return error ;
}
void
F_43 (
T_4 * V_67 )
{
if ( ! ( V_67 -> V_76 || V_67 -> V_81 || V_67 -> V_83 ) )
return;
F_59 ( V_67 ) ;
ASSERT ( ! F_53 ( & V_67 -> V_72 -> V_50 , V_67 -> V_75 ) ) ;
if ( V_67 -> V_76 ) {
F_60 ( V_67 -> V_76 ) ;
V_67 -> V_76 = NULL ;
}
if ( V_67 -> V_81 ) {
F_60 ( V_67 -> V_81 ) ;
V_67 -> V_81 = NULL ;
}
if ( V_67 -> V_83 ) {
F_60 ( V_67 -> V_83 ) ;
V_67 -> V_83 = NULL ;
}
}
static enum V_84
F_61 (
struct V_85 * V_86 ,
T_7 * V_87 ,
void * V_88 )
{
struct V_3 * V_4 = F_62 ( V_86 ,
struct V_3 , V_38 ) ;
struct V_89 * V_90 = V_88 ;
if ( ! F_63 ( V_4 ) )
goto V_91;
if ( V_4 -> V_27 ) {
F_11 ( V_4 ) ;
F_64 ( V_92 ) ;
F_65 ( V_4 ) ;
F_66 ( & V_4 -> V_38 ) ;
F_24 ( V_40 ) ;
return V_93 ;
}
if ( ! F_67 ( V_4 ) ) {
F_11 ( V_4 ) ;
goto V_91;
}
if ( F_13 ( V_4 ) ) {
struct V_28 * V_29 = NULL ;
int error ;
F_68 ( V_4 ) ;
F_39 ( V_87 ) ;
error = F_14 ( V_4 , & V_29 ) ;
if ( error ) {
F_15 ( V_4 -> V_24 , L_1 ,
V_30 , V_4 ) ;
goto V_94;
}
F_69 ( V_29 , & V_90 -> V_95 ) ;
F_17 ( V_29 ) ;
goto V_94;
}
F_20 ( V_4 ) ;
V_4 -> V_25 |= V_26 ;
F_11 ( V_4 ) ;
ASSERT ( V_4 -> V_27 == 0 ) ;
F_70 ( & V_4 -> V_38 , & V_90 -> V_96 ) ;
F_24 ( V_40 ) ;
F_71 ( V_4 ) ;
F_64 ( V_97 ) ;
return V_93 ;
V_91:
F_72 ( V_4 ) ;
F_64 ( V_98 ) ;
return V_99 ;
V_94:
F_72 ( V_4 ) ;
F_64 ( V_98 ) ;
F_11 ( V_4 ) ;
F_38 ( V_87 ) ;
return V_100 ;
}
static unsigned long
F_73 (
struct V_101 * V_102 ,
struct V_103 * V_104 )
{
struct V_6 * V_7 = F_62 ( V_102 ,
struct V_6 , V_105 ) ;
struct V_89 V_90 ;
unsigned long V_106 ;
int error ;
unsigned long V_107 = V_104 -> V_107 ;
if ( ( V_104 -> V_108 & ( V_109 | V_110 ) ) != ( V_109 | V_110 ) )
return 0 ;
F_74 ( & V_90 . V_95 ) ;
F_74 ( & V_90 . V_96 ) ;
V_106 = F_75 ( & V_7 -> V_39 , V_104 -> V_111 , F_61 , & V_90 ,
& V_107 ) ;
error = F_76 ( & V_90 . V_95 ) ;
if ( error )
F_15 ( NULL , L_5 , V_30 ) ;
while ( ! F_22 ( & V_90 . V_96 ) ) {
struct V_3 * V_4 ;
V_4 = F_77 ( & V_90 . V_96 , struct V_3 , V_38 ) ;
F_66 ( & V_4 -> V_38 ) ;
F_78 ( V_4 ) ;
}
return V_106 ;
}
static unsigned long
F_79 (
struct V_101 * V_102 ,
struct V_103 * V_104 )
{
struct V_6 * V_7 = F_62 ( V_102 ,
struct V_6 , V_105 ) ;
return F_80 ( & V_7 -> V_39 , V_104 -> V_111 ) ;
}
STATIC int
F_32 (
T_3 * V_2 )
{
T_8 * V_112 ;
int error ;
T_6 * V_4 ;
ASSERT ( F_31 ( V_2 ) ) ;
V_112 = V_2 -> V_8 = F_81 ( sizeof( T_8 ) , V_113 ) ;
error = - F_82 ( & V_112 -> V_39 ) ;
if ( error )
goto V_114;
error = F_83 ( V_2 ) ;
if ( error )
goto V_115;
F_84 ( & V_112 -> V_116 , V_117 ) ;
F_84 ( & V_112 -> V_118 , V_117 ) ;
F_84 ( & V_112 -> V_119 , V_117 ) ;
F_85 ( & V_112 -> V_19 ) ;
F_85 ( & V_112 -> V_120 ) ;
V_112 -> V_121 = F_86 ( V_2 , V_122 ) ;
V_112 -> V_123 = F_87 ( V_112 -> V_121 ) ;
V_2 -> V_52 |= ( V_2 -> V_50 . V_58 & V_124 ) ;
error = F_88 ( V_2 , 0 ,
F_89 ( V_2 ) ? V_43 :
( F_90 ( V_2 ) ? V_45 :
V_47 ) ,
V_73 , & V_4 ) ;
if ( ! error ) {
T_9 * V_125 = & V_4 -> V_20 ;
V_112 -> V_126 = V_125 -> V_127 ?
F_7 ( V_125 -> V_127 ) : V_128 ;
V_112 -> V_129 = V_125 -> V_130 ?
F_7 ( V_125 -> V_130 ) : V_131 ;
V_112 -> V_132 = V_125 -> V_133 ?
F_7 ( V_125 -> V_133 ) : V_134 ;
V_112 -> V_135 = V_125 -> V_136 ?
F_91 ( V_125 -> V_136 ) : V_137 ;
V_112 -> V_138 = V_125 -> V_139 ?
F_91 ( V_125 -> V_139 ) : V_140 ;
V_112 -> V_141 = V_125 -> V_142 ?
F_91 ( V_125 -> V_142 ) : V_143 ;
V_112 -> V_144 = F_92 ( V_125 -> V_145 ) ;
V_112 -> V_146 = F_92 ( V_125 -> V_147 ) ;
V_112 -> V_148 = F_92 ( V_125 -> V_149 ) ;
V_112 -> V_150 = F_92 ( V_125 -> V_151 ) ;
V_112 -> V_152 = F_92 ( V_125 -> V_153 ) ;
V_112 -> V_154 = F_92 ( V_125 -> V_155 ) ;
F_25 ( V_4 ) ;
} else {
V_112 -> V_126 = V_128 ;
V_112 -> V_129 = V_131 ;
V_112 -> V_132 = V_134 ;
V_112 -> V_135 = V_137 ;
V_112 -> V_138 = V_140 ;
V_112 -> V_141 = V_143 ;
}
V_112 -> V_105 . V_156 = F_79 ;
V_112 -> V_105 . V_157 = F_73 ;
V_112 -> V_105 . V_158 = V_159 ;
V_112 -> V_105 . V_41 = V_160 ;
F_93 ( & V_112 -> V_105 ) ;
return 0 ;
V_115:
F_94 ( & V_112 -> V_39 ) ;
V_114:
F_95 ( V_112 ) ;
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
F_96 ( & V_7 -> V_105 ) ;
F_94 ( & V_7 -> V_39 ) ;
if ( V_7 -> V_64 ) {
F_44 ( V_7 -> V_64 ) ;
V_7 -> V_64 = NULL ;
}
if ( V_7 -> V_65 ) {
F_44 ( V_7 -> V_65 ) ;
V_7 -> V_65 = NULL ;
}
if ( V_7 -> V_66 ) {
F_44 ( V_7 -> V_66 ) ;
V_7 -> V_66 = NULL ;
}
F_97 ( & V_7 -> V_120 ) ;
F_95 ( V_7 ) ;
V_2 -> V_8 = NULL ;
}
STATIC int
F_98 (
T_3 * V_2 ,
T_4 * * V_67 ,
T_10 V_161 ,
T_2 V_41 )
{
T_11 * V_162 ;
int error ;
int V_163 ;
* V_67 = NULL ;
if ( ! F_99 ( & V_2 -> V_50 ) &&
( V_41 & ( V_46 | V_44 ) ) ) {
T_12 V_164 = V_165 ;
if ( ( V_41 & V_46 ) &&
( V_2 -> V_50 . V_166 != V_165 ) ) {
V_164 = V_2 -> V_50 . V_166 ;
ASSERT ( V_2 -> V_50 . V_167 == V_165 ) ;
} else if ( ( V_41 & V_44 ) &&
( V_2 -> V_50 . V_167 != V_165 ) ) {
V_164 = V_2 -> V_50 . V_167 ;
ASSERT ( V_2 -> V_50 . V_166 == V_165 ) ;
}
if ( V_164 != V_165 ) {
error = F_100 ( V_2 , NULL , V_164 , 0 , 0 , V_67 ) ;
if ( error )
return error ;
V_2 -> V_50 . V_166 = V_165 ;
V_2 -> V_50 . V_167 = V_165 ;
}
}
V_162 = F_101 ( V_2 , V_168 ) ;
error = F_102 ( V_162 , & F_103 ( V_2 ) -> V_169 ,
F_104 ( V_2 ) , 0 ) ;
if ( error ) {
F_105 ( V_162 , 0 ) ;
return error ;
}
if ( ! * V_67 ) {
error = F_106 ( & V_162 , NULL , V_170 , 1 , 0 , 0 , 1 , V_67 ,
& V_163 ) ;
if ( error ) {
F_105 ( V_162 , V_171 |
V_172 ) ;
return error ;
}
}
F_38 ( & V_2 -> V_57 ) ;
if ( V_41 & V_173 ) {
ASSERT ( ! F_107 ( & V_2 -> V_50 ) ) ;
ASSERT ( ( V_161 & ( V_174 | V_175 |
V_176 | V_177 | V_60 ) ) ==
( V_174 | V_175 |
V_176 | V_177 |
V_60 ) ) ;
F_108 ( & V_2 -> V_50 ) ;
V_2 -> V_50 . V_178 = V_165 ;
V_2 -> V_50 . V_166 = V_165 ;
V_2 -> V_50 . V_167 = V_165 ;
V_2 -> V_50 . V_58 = V_2 -> V_52 & V_179 ;
}
if ( V_41 & V_42 )
V_2 -> V_50 . V_178 = ( * V_67 ) -> V_75 ;
else if ( V_41 & V_44 )
V_2 -> V_50 . V_166 = ( * V_67 ) -> V_75 ;
else
V_2 -> V_50 . V_167 = ( * V_67 ) -> V_75 ;
F_39 ( & V_2 -> V_57 ) ;
F_109 ( V_162 , V_161 ) ;
if ( ( error = F_110 ( V_162 , V_171 ) ) ) {
F_41 ( V_2 , L_6 , V_30 , error ) ;
return error ;
}
return 0 ;
}
STATIC void
F_111 (
T_3 * V_2 ,
T_13 * V_29 ,
T_5 V_68 ,
T_2 type )
{
struct V_180 * V_181 ;
int V_182 ;
F_112 ( V_29 , V_183 ) ;
#ifdef F_113
V_182 = F_114 ( V_2 , V_122 ) ;
F_115 ( V_182 , sizeof( V_184 ) ) ;
ASSERT ( V_2 -> V_8 -> V_123 == V_182 ) ;
#endif
V_181 = V_29 -> V_185 ;
for ( V_182 = 0 ; V_182 < V_2 -> V_8 -> V_123 ; V_182 ++ ) {
struct V_186 * V_187 ;
V_187 = (struct V_186 * ) & V_181 [ V_182 ] ;
F_116 ( V_2 , V_187 , V_68 + V_182 , type , V_188 ,
L_7 ) ;
V_187 -> V_189 = 0 ;
V_187 -> V_190 = 0 ;
V_187 -> V_191 = 0 ;
V_187 -> V_127 = 0 ;
V_187 -> V_130 = 0 ;
V_187 -> V_133 = 0 ;
V_187 -> V_136 = 0 ;
V_187 -> V_139 = 0 ;
V_187 -> V_142 = 0 ;
if ( F_117 ( & V_2 -> V_50 ) ) {
F_118 ( ( char * ) & V_181 [ V_182 ] ,
sizeof( struct V_180 ) ,
V_192 ) ;
}
}
}
STATIC int
F_119 (
struct V_1 * V_2 ,
T_5 V_193 ,
T_14 V_194 ,
T_15 V_195 ,
T_2 V_41 ,
struct V_85 * V_196 )
{
struct V_28 * V_29 ;
int error ;
int type ;
ASSERT ( V_195 > 0 ) ;
type = V_41 & V_42 ? V_43 :
( V_41 & V_46 ? V_47 : V_45 ) ;
error = 0 ;
while ( V_195 -- ) {
error = F_120 ( V_2 , NULL , V_2 -> V_197 ,
F_121 ( V_2 , V_194 ) ,
V_2 -> V_8 -> V_121 , 0 , & V_29 ,
& V_198 ) ;
if ( error == V_23 ) {
error = F_120 ( V_2 , NULL , V_2 -> V_197 ,
F_121 ( V_2 , V_194 ) ,
V_2 -> V_8 -> V_121 , 0 , & V_29 ,
NULL ) ;
}
if ( error )
break;
F_111 ( V_2 , V_29 , V_193 , type ) ;
F_69 ( V_29 , V_196 ) ;
F_17 ( V_29 ) ;
V_194 ++ ;
V_193 += V_2 -> V_8 -> V_123 ;
}
return error ;
}
STATIC int
F_122 (
struct V_1 * V_2 ,
struct V_74 * V_199 ,
T_2 V_41 ,
struct V_85 * V_196 )
{
struct V_200 * V_201 ;
int V_18 , V_202 ;
int error ;
T_16 V_203 ;
T_15 V_204 ;
T_5 V_193 ;
T_14 V_205 ;
T_15 V_206 ;
error = 0 ;
if ( V_199 -> V_77 . V_207 == 0 )
return 0 ;
V_201 = F_123 ( V_208 * sizeof( * V_201 ) , V_113 ) ;
V_203 = 0 ;
V_204 = F_124 ( V_2 , V_2 -> V_209 -> V_210 ) ;
do {
T_2 V_211 ;
V_202 = V_208 ;
V_211 = F_125 ( V_199 ) ;
error = F_126 ( V_199 , V_203 , V_204 - V_203 ,
V_201 , & V_202 , 0 ) ;
F_58 ( V_199 , V_211 ) ;
if ( error )
break;
ASSERT ( V_202 <= V_208 ) ;
for ( V_18 = 0 ; V_18 < V_202 ; V_18 ++ ) {
ASSERT ( V_201 [ V_18 ] . V_212 != V_213 ) ;
ASSERT ( V_201 [ V_18 ] . V_214 ) ;
V_203 += V_201 [ V_18 ] . V_214 ;
if ( V_201 [ V_18 ] . V_212 == V_215 )
continue;
V_193 = ( T_5 ) V_201 [ V_18 ] . V_216 *
V_2 -> V_8 -> V_123 ;
if ( ( V_18 + 1 < V_202 ) &&
( V_201 [ V_18 + 1 ] . V_212 != V_215 ) ) {
V_206 = V_201 [ V_18 + 1 ] . V_214 ;
V_205 = V_201 [ V_18 + 1 ] . V_212 ;
while ( V_206 -- ) {
F_127 ( V_2 -> V_197 ,
F_121 ( V_2 , V_205 ) ,
V_2 -> V_8 -> V_121 ,
NULL ) ;
V_205 ++ ;
}
}
error = F_119 ( V_2 , V_193 ,
V_201 [ V_18 ] . V_212 ,
V_201 [ V_18 ] . V_214 ,
V_41 , V_196 ) ;
if ( error )
goto V_217;
}
} while ( V_202 > 0 );
V_217:
F_95 ( V_201 ) ;
return error ;
}
STATIC int
F_128 (
struct V_74 * V_67 ,
T_5 V_68 ,
T_2 type ,
T_17 V_218 ,
T_17 V_219 )
{
struct V_1 * V_2 = V_67 -> V_72 ;
struct V_3 * V_4 ;
int error ;
error = F_48 ( V_2 , V_67 , V_68 , type ,
V_79 | V_73 , & V_4 ) ;
if ( error ) {
ASSERT ( error != V_220 ) ;
ASSERT ( error != V_221 ) ;
return error ;
}
F_129 ( V_4 ) ;
F_130 ( & V_4 -> V_20 . V_190 , 1 ) ;
V_4 -> V_222 ++ ;
if ( V_218 ) {
F_130 ( & V_4 -> V_20 . V_189 , V_218 ) ;
V_4 -> V_223 += V_218 ;
}
if ( V_219 ) {
F_130 ( & V_4 -> V_20 . V_191 , V_219 ) ;
V_4 -> V_224 += V_219 ;
}
if ( V_4 -> V_20 . V_21 ) {
F_131 ( V_2 , V_4 ) ;
F_132 ( V_2 , & V_4 -> V_20 ) ;
}
V_4 -> V_25 |= V_225 ;
F_133 ( V_4 ) ;
return 0 ;
}
STATIC int
F_134 (
T_4 * V_67 ,
T_17 * V_226 )
{
T_15 V_219 ;
T_18 V_227 ;
T_19 * V_228 ;
T_18 V_229 ;
int error ;
ASSERT ( F_135 ( V_67 ) ) ;
V_228 = F_136 ( V_67 , V_230 ) ;
if ( ! ( V_228 -> V_231 & V_232 ) ) {
if ( ( error = F_137 ( NULL , V_67 , V_230 ) ) )
return error ;
}
V_219 = 0 ;
V_229 = V_228 -> V_233 / ( T_2 ) sizeof( V_234 ) ;
for ( V_227 = 0 ; V_227 < V_229 ; V_227 ++ )
V_219 += F_138 ( F_139 ( V_228 , V_227 ) ) ;
* V_226 = ( T_17 ) V_219 ;
return 0 ;
}
STATIC int
F_140 (
T_3 * V_2 ,
T_12 V_164 ,
void T_20 * V_235 ,
int V_236 ,
int * V_237 ,
int * V_238 )
{
T_4 * V_67 ;
T_17 V_218 , V_219 = 0 ;
int error ;
ASSERT ( F_31 ( V_2 ) ) ;
if ( F_53 ( & V_2 -> V_50 , V_164 ) ) {
* V_238 = V_239 ;
return F_141 ( V_240 ) ;
}
error = F_100 ( V_2 , NULL , V_164 , 0 , V_71 , & V_67 ) ;
if ( error ) {
* V_238 = V_239 ;
return error ;
}
ASSERT ( V_67 -> V_241 == 0 ) ;
if ( F_135 ( V_67 ) ) {
error = F_134 ( V_67 , & V_219 ) ;
if ( error )
goto V_242;
}
V_218 = ( T_17 ) V_67 -> V_77 . V_207 - V_219 ;
if ( F_35 ( V_2 ) ) {
error = F_128 ( V_67 , V_67 -> V_77 . V_78 ,
V_43 , V_218 , V_219 ) ;
if ( error )
goto V_242;
}
if ( F_36 ( V_2 ) ) {
error = F_128 ( V_67 , V_67 -> V_77 . V_82 ,
V_45 , V_218 , V_219 ) ;
if ( error )
goto V_242;
}
if ( F_37 ( V_2 ) ) {
error = F_128 ( V_67 , F_55 ( V_67 ) ,
V_47 , V_218 , V_219 ) ;
if ( error )
goto V_242;
}
F_58 ( V_67 , V_71 ) ;
F_44 ( V_67 ) ;
* V_238 = V_243 ;
return 0 ;
V_242:
F_58 ( V_67 , V_71 ) ;
F_44 ( V_67 ) ;
* V_238 = V_244 ;
return error ;
}
STATIC int
F_142 (
struct V_3 * V_4 ,
void * V_5 )
{
struct V_85 * V_196 = V_5 ;
struct V_28 * V_29 = NULL ;
int error = 0 ;
F_10 ( V_4 ) ;
if ( V_4 -> V_25 & V_26 )
goto V_245;
if ( ! F_13 ( V_4 ) )
goto V_245;
F_12 ( V_4 ) ;
error = F_14 ( V_4 , & V_29 ) ;
if ( error )
goto V_245;
F_69 ( V_29 , V_196 ) ;
F_17 ( V_29 ) ;
V_245:
F_11 ( V_4 ) ;
return error ;
}
int
F_34 (
T_3 * V_2 )
{
int V_80 , V_246 , error , V_247 ;
T_12 V_248 ;
T_21 V_249 ;
T_2 V_41 ;
F_143 ( V_196 ) ;
struct V_74 * V_250 = V_2 -> V_8 -> V_64 ;
struct V_74 * V_251 = V_2 -> V_8 -> V_65 ;
struct V_74 * V_252 = V_2 -> V_8 -> V_66 ;
V_246 = V_253 ;
V_249 = 1 ;
V_248 = 0 ;
V_41 = 0 ;
ASSERT ( V_250 || V_251 || V_252 ) ;
ASSERT ( F_31 ( V_2 ) ) ;
F_30 ( V_2 , L_8 ) ;
if ( V_250 ) {
error = F_122 ( V_2 , V_250 , V_42 ,
& V_196 ) ;
if ( error )
goto V_254;
V_41 |= V_54 ;
}
if ( V_251 ) {
error = F_122 ( V_2 , V_251 , V_44 ,
& V_196 ) ;
if ( error )
goto V_254;
V_41 |= V_55 ;
}
if ( V_252 ) {
error = F_122 ( V_2 , V_252 , V_46 ,
& V_196 ) ;
if ( error )
goto V_254;
V_41 |= V_56 ;
}
do {
error = F_144 ( V_2 , & V_248 , & V_246 ,
F_140 ,
V_249 , NULL , & V_80 ) ;
if ( error )
break;
} while ( ! V_80 );
if ( F_35 ( V_2 ) ) {
error = F_1 ( V_2 , V_43 , F_142 ,
& V_196 ) ;
}
if ( F_36 ( V_2 ) ) {
V_247 = F_1 ( V_2 , V_45 , F_142 ,
& V_196 ) ;
if ( ! error )
error = V_247 ;
}
if ( F_37 ( V_2 ) ) {
V_247 = F_1 ( V_2 , V_47 , F_142 ,
& V_196 ) ;
if ( ! error )
error = V_247 ;
}
V_247 = F_76 ( & V_196 ) ;
if ( ! error )
error = V_247 ;
if ( error ) {
F_26 ( V_2 , V_48 ) ;
goto V_254;
}
V_2 -> V_52 &= ~ V_124 ;
V_2 -> V_52 |= V_41 ;
V_254:
while ( ! F_22 ( & V_196 ) ) {
struct V_28 * V_29 =
F_77 ( & V_196 , struct V_28 , V_255 ) ;
F_66 ( & V_29 -> V_255 ) ;
F_17 ( V_29 ) ;
}
if ( error ) {
F_15 ( V_2 ,
L_9 ,
error ) ;
ASSERT ( V_2 -> V_8 != NULL ) ;
F_28 ( V_2 ) ;
if ( F_145 ( V_2 ) ) {
F_15 ( V_2 ,
L_10 ) ;
}
} else
F_30 ( V_2 , L_11 ) ;
return ( error ) ;
}
STATIC int
F_83 (
T_3 * V_2 )
{
struct V_74 * V_250 = NULL ;
struct V_74 * V_251 = NULL ;
struct V_74 * V_252 = NULL ;
int error ;
T_10 V_256 = 0 ;
T_2 V_41 = 0 ;
ASSERT ( V_2 -> V_8 ) ;
if ( F_107 ( & V_2 -> V_50 ) ) {
if ( F_35 ( V_2 ) &&
V_2 -> V_50 . V_178 != V_165 ) {
ASSERT ( V_2 -> V_50 . V_178 > 0 ) ;
error = F_100 ( V_2 , NULL , V_2 -> V_50 . V_178 ,
0 , 0 , & V_250 ) ;
if ( error )
return F_141 ( error ) ;
}
if ( F_36 ( V_2 ) &&
V_2 -> V_50 . V_166 != V_165 ) {
ASSERT ( V_2 -> V_50 . V_166 > 0 ) ;
error = F_100 ( V_2 , NULL , V_2 -> V_50 . V_166 ,
0 , 0 , & V_251 ) ;
if ( error )
goto V_257;
}
if ( F_37 ( V_2 ) &&
V_2 -> V_50 . V_167 != V_165 ) {
ASSERT ( V_2 -> V_50 . V_167 > 0 ) ;
error = F_100 ( V_2 , NULL , V_2 -> V_50 . V_167 ,
0 , 0 , & V_252 ) ;
if ( error )
goto V_257;
}
} else {
V_41 |= V_173 ;
V_256 |= ( V_174 | V_175 |
V_176 | V_177 |
V_60 ) ;
}
if ( F_35 ( V_2 ) && V_250 == NULL ) {
error = F_98 ( V_2 , & V_250 ,
V_256 | V_175 ,
V_41 | V_42 ) ;
if ( error )
goto V_257;
V_41 &= ~ V_173 ;
}
if ( F_36 ( V_2 ) && V_251 == NULL ) {
error = F_98 ( V_2 , & V_251 ,
V_256 | V_176 ,
V_41 | V_44 ) ;
if ( error )
goto V_257;
V_41 &= ~ V_173 ;
}
if ( F_37 ( V_2 ) && V_252 == NULL ) {
error = F_98 ( V_2 , & V_252 ,
V_256 | V_177 ,
V_41 | V_46 ) ;
if ( error )
goto V_257;
}
V_2 -> V_8 -> V_64 = V_250 ;
V_2 -> V_8 -> V_65 = V_251 ;
V_2 -> V_8 -> V_66 = V_252 ;
return 0 ;
V_257:
if ( V_250 )
F_44 ( V_250 ) ;
if ( V_251 )
F_44 ( V_251 ) ;
if ( V_252 )
F_44 ( V_252 ) ;
return F_141 ( error ) ;
}
STATIC void
F_78 (
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
F_40 (
T_3 * V_2 ,
T_10 V_41 )
{
T_11 * V_162 ;
int error ;
V_162 = F_101 ( V_2 , V_258 ) ;
error = F_102 ( V_162 , & F_103 ( V_2 ) -> V_259 , 0 , 0 ) ;
if ( error ) {
F_105 ( V_162 , 0 ) ;
return error ;
}
F_109 ( V_162 , V_41 ) ;
error = F_110 ( V_162 , 0 ) ;
return error ;
}
int
F_146 (
struct V_74 * V_67 ,
T_5 V_260 ,
T_5 V_261 ,
T_22 V_262 ,
T_2 V_41 ,
struct V_3 * * V_263 ,
struct V_3 * * V_264 ,
struct V_3 * * V_265 )
{
struct V_1 * V_2 = V_67 -> V_72 ;
struct V_3 * V_266 = NULL ;
struct V_3 * V_267 = NULL ;
struct V_3 * V_268 = NULL ;
int error ;
T_2 V_269 ;
if ( ! F_31 ( V_2 ) || ! F_51 ( V_2 ) )
return 0 ;
V_269 = V_71 ;
F_57 ( V_67 , V_269 ) ;
if ( ( V_41 & V_270 ) && F_147 ( V_67 ) )
V_261 = V_67 -> V_77 . V_82 ;
if ( F_52 ( V_2 , V_67 ) ) {
error = F_54 ( V_67 , V_79 ) ;
if ( error ) {
F_58 ( V_67 , V_269 ) ;
return error ;
}
}
if ( ( V_41 & V_42 ) && F_35 ( V_2 ) ) {
if ( V_67 -> V_77 . V_78 != V_260 ) {
F_58 ( V_67 , V_269 ) ;
error = F_48 ( V_2 , NULL , V_260 ,
V_43 ,
V_79 |
V_73 ,
& V_266 ) ;
if ( error ) {
ASSERT ( error != V_221 ) ;
return error ;
}
F_11 ( V_266 ) ;
V_269 = V_271 ;
F_57 ( V_67 , V_269 ) ;
} else {
ASSERT ( V_67 -> V_76 ) ;
V_266 = F_148 ( V_67 -> V_76 ) ;
}
}
if ( ( V_41 & V_44 ) && F_36 ( V_2 ) ) {
if ( V_67 -> V_77 . V_82 != V_261 ) {
F_58 ( V_67 , V_269 ) ;
error = F_48 ( V_2 , NULL , V_261 ,
V_45 ,
V_79 |
V_73 ,
& V_267 ) ;
if ( error ) {
ASSERT ( error != V_221 ) ;
goto V_257;
}
F_11 ( V_267 ) ;
V_269 = V_271 ;
F_57 ( V_67 , V_269 ) ;
} else {
ASSERT ( V_67 -> V_81 ) ;
V_267 = F_148 ( V_67 -> V_81 ) ;
}
}
if ( ( V_41 & V_46 ) && F_37 ( V_2 ) ) {
if ( F_55 ( V_67 ) != V_262 ) {
F_58 ( V_67 , V_269 ) ;
error = F_48 ( V_2 , NULL , ( T_5 ) V_262 ,
V_47 ,
V_79 |
V_73 ,
& V_268 ) ;
if ( error ) {
ASSERT ( error != V_221 ) ;
goto V_257;
}
F_11 ( V_268 ) ;
V_269 = V_271 ;
F_57 ( V_67 , V_269 ) ;
} else {
ASSERT ( V_67 -> V_83 ) ;
V_268 = F_148 ( V_67 -> V_83 ) ;
}
}
if ( V_266 )
F_149 ( V_67 ) ;
F_58 ( V_67 , V_269 ) ;
if ( V_263 )
* V_263 = V_266 ;
else if ( V_266 )
F_60 ( V_266 ) ;
if ( V_264 )
* V_264 = V_267 ;
else if ( V_267 )
F_60 ( V_267 ) ;
if ( V_265 )
* V_265 = V_268 ;
else if ( V_268 )
F_60 ( V_268 ) ;
return 0 ;
V_257:
if ( V_267 )
F_60 ( V_267 ) ;
if ( V_266 )
F_60 ( V_266 ) ;
return error ;
}
T_6 *
F_150 (
T_11 * V_162 ,
T_4 * V_67 ,
T_6 * * V_272 ,
T_6 * V_273 )
{
T_6 * V_274 ;
T_2 V_275 = F_135 ( V_67 ) ?
V_276 : V_277 ;
ASSERT ( F_46 ( V_67 , V_71 ) ) ;
ASSERT ( F_31 ( V_67 -> V_72 ) ) ;
V_274 = * V_272 ;
ASSERT ( V_274 ) ;
ASSERT ( V_274 != V_273 ) ;
F_151 ( V_162 , V_274 , V_275 , - ( V_67 -> V_77 . V_207 ) ) ;
F_151 ( V_162 , V_274 , V_278 , - 1 ) ;
F_151 ( V_162 , V_273 , V_275 , V_67 -> V_77 . V_207 ) ;
F_151 ( V_162 , V_273 , V_278 , 1 ) ;
* V_272 = F_148 ( V_273 ) ;
return V_274 ;
}
int
F_152 (
struct V_279 * V_162 ,
struct V_74 * V_67 ,
struct V_3 * V_280 ,
struct V_3 * V_281 ,
struct V_3 * V_282 ,
T_2 V_41 )
{
struct V_1 * V_2 = V_67 -> V_72 ;
T_2 V_283 , V_284 , V_285 = 0 ;
struct V_3 * V_286 = NULL ;
struct V_3 * V_287 = NULL ;
struct V_3 * V_288 = NULL ;
struct V_3 * V_289 = NULL ;
struct V_3 * V_290 = NULL ;
struct V_3 * V_291 = NULL ;
int error ;
ASSERT ( F_46 ( V_67 , V_71 | V_271 ) ) ;
ASSERT ( F_31 ( V_2 ) ) ;
V_283 = V_67 -> V_241 ;
V_284 = F_135 ( V_67 ) ?
V_292 : V_293 ;
if ( F_35 ( V_2 ) && V_280 &&
V_67 -> V_77 . V_78 != F_7 ( V_280 -> V_20 . V_21 ) ) {
V_289 = V_280 ;
if ( V_283 ) {
ASSERT ( V_67 -> V_76 ) ;
V_286 = V_67 -> V_76 ;
}
}
if ( F_36 ( V_67 -> V_72 ) && V_281 &&
V_67 -> V_77 . V_82 != F_7 ( V_281 -> V_20 . V_21 ) ) {
V_290 = V_281 ;
if ( V_283 ) {
ASSERT ( V_67 -> V_81 ) ;
V_287 = V_67 -> V_81 ;
}
}
if ( F_37 ( V_67 -> V_72 ) && V_282 &&
F_55 ( V_67 ) != F_7 ( V_282 -> V_20 . V_21 ) ) {
V_285 = V_294 ;
V_291 = V_282 ;
if ( V_283 ) {
ASSERT ( V_67 -> V_83 ) ;
V_288 = V_67 -> V_83 ;
}
}
error = F_153 ( V_162 , V_67 -> V_72 ,
V_289 , V_290 , V_291 ,
V_67 -> V_77 . V_207 , 1 ,
V_41 | V_284 | V_285 ) ;
if ( error )
return error ;
if ( V_283 ) {
ASSERT ( V_289 || V_290 || V_291 ) ;
ASSERT ( V_286 || V_287 || V_288 ) ;
error = F_153 ( NULL , V_67 -> V_72 ,
V_289 , V_290 , V_291 ,
( T_17 ) V_283 , 0 ,
V_41 | V_284 | V_285 ) ;
if ( error )
return error ;
F_153 ( NULL , V_67 -> V_72 ,
V_286 , V_287 , V_288 ,
- ( ( T_17 ) V_283 ) , 0 , V_284 ) ;
}
return ( 0 ) ;
}
int
F_154 (
struct V_74 * * V_295 )
{
struct V_1 * V_2 = V_295 [ 0 ] -> V_72 ;
int V_18 ;
if ( ! F_31 ( V_2 ) || ! F_51 ( V_2 ) )
return 0 ;
for ( V_18 = 0 ; ( V_18 < 4 && V_295 [ V_18 ] ) ; V_18 ++ ) {
struct V_74 * V_67 = V_295 [ V_18 ] ;
int error ;
if ( V_18 == 0 || V_67 != V_295 [ V_18 - 1 ] ) {
if ( F_52 ( V_2 , V_67 ) ) {
error = F_56 ( V_67 , 0 ) ;
if ( error )
return error ;
}
}
}
return 0 ;
}
void
F_155 (
struct V_279 * V_162 ,
struct V_74 * V_67 ,
struct V_3 * V_280 ,
struct V_3 * V_281 ,
struct V_3 * V_282 )
{
struct V_1 * V_2 = V_162 -> V_296 ;
if ( ! F_31 ( V_2 ) || ! F_51 ( V_2 ) )
return;
ASSERT ( F_46 ( V_67 , V_71 ) ) ;
ASSERT ( F_31 ( V_2 ) ) ;
if ( V_280 && F_35 ( V_2 ) ) {
ASSERT ( V_67 -> V_76 == NULL ) ;
ASSERT ( V_67 -> V_77 . V_78 == F_7 ( V_280 -> V_20 . V_21 ) ) ;
V_67 -> V_76 = F_148 ( V_280 ) ;
F_151 ( V_162 , V_280 , V_278 , 1 ) ;
}
if ( V_281 && F_36 ( V_2 ) ) {
ASSERT ( V_67 -> V_81 == NULL ) ;
ASSERT ( V_67 -> V_77 . V_82 == F_7 ( V_281 -> V_20 . V_21 ) ) ;
V_67 -> V_81 = F_148 ( V_281 ) ;
F_151 ( V_162 , V_281 , V_278 , 1 ) ;
}
if ( V_282 && F_37 ( V_2 ) ) {
ASSERT ( V_67 -> V_83 == NULL ) ;
ASSERT ( F_55 ( V_67 ) == F_7 ( V_282 -> V_20 . V_21 ) ) ;
V_67 -> V_83 = F_148 ( V_282 ) ;
F_151 ( V_162 , V_282 , V_278 , 1 ) ;
}
}
