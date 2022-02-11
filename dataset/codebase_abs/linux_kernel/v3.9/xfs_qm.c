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
struct V_3 * V_25 = NULL ;
F_10 ( V_4 ) ;
if ( ( V_4 -> V_26 & V_27 ) || V_4 -> V_28 != 0 ) {
F_11 ( V_4 ) ;
return V_22 ;
}
V_25 = V_4 -> V_29 ;
if ( V_25 ) {
F_10 ( V_25 ) ;
V_4 -> V_29 = NULL ;
}
V_4 -> V_26 |= V_27 ;
F_12 ( V_4 ) ;
if ( F_13 ( V_4 ) ) {
struct V_30 * V_31 = NULL ;
int error ;
error = F_14 ( V_4 , & V_31 ) ;
if ( error ) {
F_15 ( V_2 , L_1 ,
V_32 , V_4 ) ;
} else {
error = F_16 ( V_31 ) ;
F_17 ( V_31 ) ;
}
F_12 ( V_4 ) ;
}
ASSERT ( F_18 ( & V_4 -> V_33 ) == 0 ) ;
ASSERT ( F_19 ( V_2 ) ||
! ( V_4 -> V_34 . V_35 . V_36 & V_37 ) ) ;
F_20 ( V_4 ) ;
F_11 ( V_4 ) ;
F_21 ( F_3 ( V_7 , V_4 -> V_20 . V_38 ) ,
F_7 ( V_4 -> V_20 . V_21 ) ) ;
V_7 -> V_39 -- ;
F_4 ( & V_7 -> V_40 ) ;
ASSERT ( ! F_22 ( & V_4 -> V_41 ) ) ;
F_23 ( & V_4 -> V_41 ) ;
V_7 -> V_42 -- ;
F_24 ( V_43 ) ;
F_6 ( & V_7 -> V_40 ) ;
F_25 ( V_4 ) ;
if ( V_25 )
F_26 ( V_25 ) ;
return 0 ;
}
void
F_27 (
struct V_1 * V_2 ,
T_2 V_44 )
{
if ( V_44 & V_45 )
F_1 ( V_2 , V_46 , F_9 , NULL ) ;
if ( V_44 & V_47 )
F_1 ( V_2 , V_48 , F_9 , NULL ) ;
if ( V_44 & V_49 )
F_1 ( V_2 , V_50 , F_9 , NULL ) ;
}
void
F_28 (
struct V_1 * V_2 )
{
if ( V_2 -> V_8 ) {
F_27 ( V_2 , V_51 ) ;
F_29 ( V_2 ) ;
}
}
void
F_30 (
T_3 * V_2 )
{
int error = 0 ;
T_2 V_52 ;
if ( V_2 -> V_53 . V_54 ) {
F_31 ( V_2 , L_2 ) ;
V_2 -> V_55 = 0 ;
goto V_56;
}
ASSERT ( F_32 ( V_2 ) ) ;
error = F_33 ( V_2 ) ;
if ( error ) {
ASSERT ( V_2 -> V_8 == NULL ) ;
V_2 -> V_55 = 0 ;
goto V_56;
}
if ( F_34 ( V_2 ) ) {
error = F_35 ( V_2 ) ;
if ( error ) {
return;
}
}
if ( ! F_36 ( V_2 ) )
V_2 -> V_55 &= ~ V_57 ;
if ( ! ( F_37 ( V_2 ) || F_38 ( V_2 ) ) )
V_2 -> V_55 &= ~ V_58 ;
V_56:
F_39 ( & V_2 -> V_59 ) ;
V_52 = V_2 -> V_53 . V_60 ;
V_2 -> V_53 . V_60 = V_2 -> V_55 & V_61 ;
F_40 ( & V_2 -> V_59 ) ;
if ( V_52 != ( V_2 -> V_55 & V_61 ) ) {
if ( F_41 ( V_2 , V_62 ) ) {
ASSERT ( ! ( F_32 ( V_2 ) ) ) ;
F_42 ( V_2 , L_3 ,
V_32 ) ;
}
}
if ( error ) {
F_15 ( V_2 , L_4 ) ;
return;
}
}
void
F_43 (
T_3 * V_2 )
{
ASSERT ( V_2 -> V_63 ) ;
F_44 ( V_2 -> V_63 ) ;
if ( V_2 -> V_64 )
F_44 ( V_2 -> V_64 ) ;
if ( V_2 -> V_65 )
F_44 ( V_2 -> V_65 ) ;
if ( V_2 -> V_8 ) {
if ( V_2 -> V_8 -> V_66 ) {
F_45 ( V_2 -> V_8 -> V_66 ) ;
V_2 -> V_8 -> V_66 = NULL ;
}
if ( V_2 -> V_8 -> V_67 ) {
F_45 ( V_2 -> V_8 -> V_67 ) ;
V_2 -> V_8 -> V_67 = NULL ;
}
}
}
STATIC int
F_46 (
T_4 * V_68 ,
T_5 V_69 ,
T_2 type ,
T_2 V_70 ,
T_6 * V_71 ,
T_6 * * V_72 )
{
T_6 * V_4 ;
int error ;
ASSERT ( F_47 ( V_68 , V_73 ) ) ;
error = 0 ;
V_4 = * V_72 ;
if ( V_4 ) {
F_48 ( V_4 ) ;
return 0 ;
}
if ( V_71 ) {
ASSERT ( type == V_48 || type == V_50 ) ;
F_10 ( V_71 ) ;
V_4 = V_71 -> V_29 ;
if ( V_4 && F_7 ( V_4 -> V_20 . V_21 ) == V_69 ) {
ASSERT ( * V_72 == NULL ) ;
* V_72 = F_49 ( V_4 ) ;
F_11 ( V_71 ) ;
return 0 ;
}
F_11 ( V_71 ) ;
}
error = F_50 ( V_68 -> V_74 , V_68 , V_69 , type ,
V_70 | V_75 , & V_4 ) ;
if ( error )
return error ;
F_51 ( V_4 ) ;
* V_72 = V_4 ;
F_11 ( V_4 ) ;
return 0 ;
}
STATIC void
F_52 (
T_6 * V_76 ,
T_6 * V_77 )
{
T_6 * V_78 ;
F_10 ( V_76 ) ;
V_78 = V_76 -> V_29 ;
if ( V_78 ) {
if ( V_78 == V_77 )
goto V_79;
V_76 -> V_29 = NULL ;
F_53 ( V_78 ) ;
}
V_76 -> V_29 = F_49 ( V_77 ) ;
V_79:
F_11 ( V_76 ) ;
}
static bool
F_54 (
struct V_80 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_74 ;
if ( ! F_32 ( V_2 ) )
return false ;
if ( ! F_55 ( V_2 ) )
return false ;
if ( ! F_56 ( V_2 , V_68 ) )
return false ;
if ( V_68 -> V_81 == V_2 -> V_53 . V_82 ||
V_68 -> V_81 == V_2 -> V_53 . V_83 )
return false ;
return true ;
}
int
F_57 (
T_4 * V_68 ,
T_2 V_44 )
{
T_3 * V_2 = V_68 -> V_74 ;
T_2 V_84 = 0 ;
int error = 0 ;
if ( ! F_54 ( V_68 ) )
return 0 ;
ASSERT ( F_47 ( V_68 , V_73 ) ) ;
if ( F_36 ( V_2 ) ) {
error = F_46 ( V_68 , V_68 -> V_85 . V_86 , V_46 ,
V_44 & V_87 ,
NULL , & V_68 -> V_88 ) ;
if ( error )
goto V_79;
V_84 ++ ;
}
ASSERT ( F_47 ( V_68 , V_73 ) ) ;
if ( F_58 ( V_2 ) ) {
error = F_37 ( V_2 ) ?
F_46 ( V_68 , V_68 -> V_85 . V_89 , V_48 ,
V_44 & V_87 ,
V_68 -> V_88 , & V_68 -> V_90 ) :
F_46 ( V_68 , F_59 ( V_68 ) , V_50 ,
V_44 & V_87 ,
V_68 -> V_88 , & V_68 -> V_90 ) ;
if ( error )
goto V_79;
V_84 ++ ;
}
if ( V_84 == 2 ) {
ASSERT ( F_47 ( V_68 , V_73 ) ) ;
ASSERT ( V_68 -> V_88 ) ;
ASSERT ( V_68 -> V_90 ) ;
if ( V_68 -> V_88 -> V_29 != V_68 -> V_90 )
F_52 ( V_68 -> V_88 , V_68 -> V_90 ) ;
}
V_79:
#ifdef F_60
if ( ! error ) {
if ( F_36 ( V_2 ) )
ASSERT ( V_68 -> V_88 ) ;
if ( F_58 ( V_2 ) )
ASSERT ( V_68 -> V_90 ) ;
}
ASSERT ( F_47 ( V_68 , V_73 ) ) ;
#endif
return error ;
}
int
F_61 (
struct V_80 * V_68 ,
T_2 V_44 )
{
int error ;
if ( ! F_54 ( V_68 ) )
return 0 ;
F_62 ( V_68 , V_73 ) ;
error = F_57 ( V_68 , V_44 ) ;
F_63 ( V_68 , V_73 ) ;
return error ;
}
void
F_44 (
T_4 * V_68 )
{
if ( ! ( V_68 -> V_88 || V_68 -> V_90 ) )
return;
F_64 ( V_68 ) ;
ASSERT ( V_68 -> V_81 != V_68 -> V_74 -> V_53 . V_82 ) ;
ASSERT ( V_68 -> V_81 != V_68 -> V_74 -> V_53 . V_83 ) ;
if ( V_68 -> V_88 ) {
F_53 ( V_68 -> V_88 ) ;
V_68 -> V_88 = NULL ;
}
if ( V_68 -> V_90 ) {
F_53 ( V_68 -> V_90 ) ;
V_68 -> V_90 = NULL ;
}
}
STATIC int
F_33 (
T_3 * V_2 )
{
T_7 * V_91 ;
int error ;
T_6 * V_4 ;
ASSERT ( F_32 ( V_2 ) ) ;
V_91 = V_2 -> V_8 = F_65 ( sizeof( T_7 ) , V_92 ) ;
if ( ( error = F_66 ( V_2 ) ) ) {
F_67 ( V_91 ) ;
V_2 -> V_8 = NULL ;
return error ;
}
F_68 ( & V_91 -> V_93 , V_94 ) ;
F_68 ( & V_91 -> V_95 , V_94 ) ;
F_69 ( & V_91 -> V_19 ) ;
F_70 ( & V_91 -> V_96 ) ;
V_91 -> V_42 = 0 ;
F_69 ( & V_91 -> V_40 ) ;
F_69 ( & V_91 -> V_97 ) ;
V_91 -> V_98 = F_71 ( V_2 , V_99 ) ;
ASSERT ( V_91 -> V_98 ) ;
V_91 -> V_100 = F_72 ( V_91 -> V_98 ) ;
F_73 ( V_91 -> V_100 , sizeof( V_101 ) ) ;
V_2 -> V_55 |= ( V_2 -> V_53 . V_60 & V_102 ) ;
error = F_74 ( V_2 , 0 ,
F_75 ( V_2 ) ? V_46 :
( F_76 ( V_2 ) ? V_48 :
V_50 ) ,
V_75 , & V_4 ) ;
if ( ! error ) {
T_8 * V_103 = & V_4 -> V_20 ;
V_91 -> V_104 = V_103 -> V_105 ?
F_7 ( V_103 -> V_105 ) : V_106 ;
V_91 -> V_107 = V_103 -> V_108 ?
F_7 ( V_103 -> V_108 ) : V_109 ;
V_91 -> V_110 = V_103 -> V_111 ?
F_7 ( V_103 -> V_111 ) : V_112 ;
V_91 -> V_113 = V_103 -> V_114 ?
F_77 ( V_103 -> V_114 ) : V_115 ;
V_91 -> V_116 = V_103 -> V_117 ?
F_77 ( V_103 -> V_117 ) : V_118 ;
V_91 -> V_119 = V_103 -> V_120 ?
F_77 ( V_103 -> V_120 ) : V_121 ;
V_91 -> V_122 = F_78 ( V_103 -> V_123 ) ;
V_91 -> V_124 = F_78 ( V_103 -> V_125 ) ;
V_91 -> V_126 = F_78 ( V_103 -> V_127 ) ;
V_91 -> V_128 = F_78 ( V_103 -> V_129 ) ;
V_91 -> V_130 = F_78 ( V_103 -> V_131 ) ;
V_91 -> V_132 = F_78 ( V_103 -> V_133 ) ;
F_25 ( V_4 ) ;
} else {
V_91 -> V_104 = V_106 ;
V_91 -> V_107 = V_109 ;
V_91 -> V_110 = V_112 ;
V_91 -> V_113 = V_115 ;
V_91 -> V_116 = V_118 ;
V_91 -> V_119 = V_121 ;
}
V_91 -> V_134 . V_135 = V_136 ;
V_91 -> V_134 . V_137 = V_138 ;
F_79 ( & V_91 -> V_134 ) ;
return 0 ;
}
void
F_29 (
T_3 * V_2 )
{
T_7 * V_7 ;
V_7 = V_2 -> V_8 ;
ASSERT ( V_7 != NULL ) ;
F_80 ( & V_7 -> V_134 ) ;
if ( V_7 -> V_66 ) {
F_45 ( V_7 -> V_66 ) ;
V_7 -> V_66 = NULL ;
}
if ( V_7 -> V_67 ) {
F_45 ( V_7 -> V_67 ) ;
V_7 -> V_67 = NULL ;
}
F_81 ( & V_7 -> V_97 ) ;
F_67 ( V_7 ) ;
V_2 -> V_8 = NULL ;
}
STATIC int
F_82 (
T_3 * V_2 ,
T_4 * * V_68 ,
T_9 V_139 ,
T_2 V_44 )
{
T_10 * V_140 ;
int error ;
int V_141 ;
V_140 = F_83 ( V_2 , V_142 ) ;
if ( ( error = F_84 ( V_140 ,
F_85 ( V_2 ) ,
F_86 ( V_2 ) , 0 ,
V_143 ,
V_144 ) ) ) {
F_87 ( V_140 , 0 ) ;
return error ;
}
error = F_88 ( & V_140 , NULL , V_145 , 1 , 0 , 0 , 1 , V_68 , & V_141 ) ;
if ( error ) {
F_87 ( V_140 , V_146 |
V_147 ) ;
return error ;
}
F_39 ( & V_2 -> V_59 ) ;
if ( V_44 & V_148 ) {
ASSERT ( ! F_89 ( & V_2 -> V_53 ) ) ;
ASSERT ( ( V_139 & ( V_149 | V_150 |
V_151 | V_62 ) ) ==
( V_149 | V_150 |
V_151 | V_62 ) ) ;
F_90 ( & V_2 -> V_53 ) ;
V_2 -> V_53 . V_82 = V_152 ;
V_2 -> V_53 . V_83 = V_152 ;
V_2 -> V_53 . V_60 = 0 ;
}
if ( V_44 & V_45 )
V_2 -> V_53 . V_82 = ( * V_68 ) -> V_81 ;
else
V_2 -> V_53 . V_83 = ( * V_68 ) -> V_81 ;
F_40 ( & V_2 -> V_59 ) ;
F_91 ( V_140 , V_139 ) ;
if ( ( error = F_92 ( V_140 , V_146 ) ) ) {
F_42 ( V_2 , L_5 , V_32 , error ) ;
return error ;
}
return 0 ;
}
STATIC void
F_93 (
T_3 * V_2 ,
T_11 * V_31 ,
T_5 V_69 ,
T_2 type )
{
T_8 * V_153 ;
int V_154 ;
F_94 ( V_31 , V_155 ) ;
#ifdef F_60
V_154 = F_95 ( V_2 , V_99 ) ;
F_73 ( V_154 , sizeof( V_101 ) ) ;
ASSERT ( V_2 -> V_8 -> V_100 == V_154 ) ;
#endif
V_153 = V_31 -> V_156 ;
for ( V_154 = 0 ; V_154 < V_2 -> V_8 -> V_100 ; V_154 ++ ) {
( void ) F_96 ( V_2 , V_153 , V_69 + V_154 , type , V_157 ,
L_6 ) ;
V_153 -> V_158 = 0 ;
V_153 -> V_159 = 0 ;
V_153 -> V_160 = 0 ;
V_153 -> V_105 = 0 ;
V_153 -> V_108 = 0 ;
V_153 -> V_111 = 0 ;
V_153 -> V_114 = 0 ;
V_153 -> V_117 = 0 ;
V_153 -> V_120 = 0 ;
V_153 = ( T_8 * ) ( ( V_101 * ) V_153 + 1 ) ;
}
}
STATIC int
F_97 (
struct V_1 * V_2 ,
T_5 V_161 ,
T_12 V_162 ,
T_13 V_163 ,
T_2 V_44 ,
struct V_164 * V_165 )
{
struct V_30 * V_31 ;
int error ;
int type ;
ASSERT ( V_163 > 0 ) ;
type = V_44 & V_45 ? V_46 :
( V_44 & V_49 ? V_50 : V_48 ) ;
error = 0 ;
while ( V_163 -- ) {
error = F_98 ( V_2 , NULL , V_2 -> V_166 ,
F_99 ( V_2 , V_162 ) ,
V_2 -> V_8 -> V_98 , 0 , & V_31 ,
& V_167 ) ;
if ( error )
break;
F_93 ( V_2 , V_31 , V_161 , type ) ;
F_100 ( V_31 , V_165 ) ;
F_17 ( V_31 ) ;
V_162 ++ ;
V_161 += V_2 -> V_8 -> V_100 ;
}
return error ;
}
STATIC int
F_101 (
struct V_1 * V_2 ,
struct V_80 * V_168 ,
T_2 V_44 ,
struct V_164 * V_165 )
{
struct V_169 * V_170 ;
int V_18 , V_171 ;
int error ;
T_14 V_172 ;
T_13 V_173 ;
T_5 V_161 ;
T_12 V_174 ;
T_13 V_175 ;
error = 0 ;
if ( V_168 -> V_85 . V_176 == 0 )
return 0 ;
V_170 = F_102 ( V_177 * sizeof( * V_170 ) , V_92 ) ;
V_172 = 0 ;
V_173 = F_103 ( V_2 , V_2 -> V_178 -> V_179 ) ;
do {
V_171 = V_177 ;
F_62 ( V_168 , V_180 ) ;
error = F_104 ( V_168 , V_172 , V_173 - V_172 ,
V_170 , & V_171 , 0 ) ;
F_63 ( V_168 , V_180 ) ;
if ( error )
break;
ASSERT ( V_171 <= V_177 ) ;
for ( V_18 = 0 ; V_18 < V_171 ; V_18 ++ ) {
ASSERT ( V_170 [ V_18 ] . V_181 != V_182 ) ;
ASSERT ( V_170 [ V_18 ] . V_183 ) ;
V_172 += V_170 [ V_18 ] . V_183 ;
if ( V_170 [ V_18 ] . V_181 == V_184 )
continue;
V_161 = ( T_5 ) V_170 [ V_18 ] . V_185 *
V_2 -> V_8 -> V_100 ;
if ( ( V_18 + 1 < V_171 ) &&
( V_170 [ V_18 + 1 ] . V_181 != V_184 ) ) {
V_175 = V_170 [ V_18 + 1 ] . V_183 ;
V_174 = V_170 [ V_18 + 1 ] . V_181 ;
while ( V_175 -- ) {
F_105 ( V_2 -> V_166 ,
F_99 ( V_2 , V_174 ) ,
V_2 -> V_8 -> V_98 ,
NULL ) ;
V_174 ++ ;
}
}
error = F_97 ( V_2 , V_161 ,
V_170 [ V_18 ] . V_181 ,
V_170 [ V_18 ] . V_183 ,
V_44 , V_165 ) ;
if ( error )
goto V_186;
}
} while ( V_171 > 0 );
V_186:
F_67 ( V_170 ) ;
return error ;
}
STATIC int
F_106 (
struct V_80 * V_68 ,
T_5 V_69 ,
T_2 type ,
T_15 V_187 ,
T_15 V_188 )
{
struct V_1 * V_2 = V_68 -> V_74 ;
struct V_3 * V_4 ;
int error ;
error = F_50 ( V_2 , V_68 , V_69 , type ,
V_87 | V_75 , & V_4 ) ;
if ( error ) {
ASSERT ( error != V_189 ) ;
ASSERT ( error != V_190 ) ;
return error ;
}
F_107 ( V_4 ) ;
F_108 ( & V_4 -> V_20 . V_159 , 1 ) ;
V_4 -> V_191 ++ ;
if ( V_187 ) {
F_108 ( & V_4 -> V_20 . V_158 , V_187 ) ;
V_4 -> V_192 += V_187 ;
}
if ( V_188 ) {
F_108 ( & V_4 -> V_20 . V_160 , V_188 ) ;
V_4 -> V_193 += V_188 ;
}
if ( V_4 -> V_20 . V_21 ) {
F_109 ( V_2 , & V_4 -> V_20 ) ;
F_110 ( V_2 , & V_4 -> V_20 ) ;
}
V_4 -> V_26 |= V_194 ;
F_26 ( V_4 ) ;
return 0 ;
}
STATIC int
F_111 (
T_4 * V_68 ,
T_15 * V_195 )
{
T_13 V_188 ;
T_16 V_196 ;
T_17 * V_197 ;
T_16 V_198 ;
int error ;
ASSERT ( F_112 ( V_68 ) ) ;
V_197 = F_113 ( V_68 , V_199 ) ;
if ( ! ( V_197 -> V_200 & V_201 ) ) {
if ( ( error = F_114 ( NULL , V_68 , V_199 ) ) )
return error ;
}
V_188 = 0 ;
V_198 = V_197 -> V_202 / ( T_2 ) sizeof( V_203 ) ;
for ( V_196 = 0 ; V_196 < V_198 ; V_196 ++ )
V_188 += F_115 ( F_116 ( V_197 , V_196 ) ) ;
* V_195 = ( T_15 ) V_188 ;
return 0 ;
}
STATIC int
F_117 (
T_3 * V_2 ,
T_18 V_204 ,
void T_19 * V_205 ,
int V_206 ,
int * V_207 ,
int * V_208 )
{
T_4 * V_68 ;
T_15 V_187 , V_188 = 0 ;
int error ;
ASSERT ( F_32 ( V_2 ) ) ;
if ( V_204 == V_2 -> V_53 . V_82 || V_204 == V_2 -> V_53 . V_83 ) {
* V_208 = V_209 ;
return F_118 ( V_210 ) ;
}
error = F_119 ( V_2 , NULL , V_204 , 0 , V_73 , & V_68 ) ;
if ( error ) {
* V_208 = V_209 ;
return error ;
}
ASSERT ( V_68 -> V_211 == 0 ) ;
if ( F_112 ( V_68 ) ) {
error = F_111 ( V_68 , & V_188 ) ;
if ( error )
goto V_212;
}
V_187 = ( T_15 ) V_68 -> V_85 . V_176 - V_188 ;
if ( F_36 ( V_2 ) ) {
error = F_106 ( V_68 , V_68 -> V_85 . V_86 ,
V_46 , V_187 , V_188 ) ;
if ( error )
goto V_212;
}
if ( F_37 ( V_2 ) ) {
error = F_106 ( V_68 , V_68 -> V_85 . V_89 ,
V_48 , V_187 , V_188 ) ;
if ( error )
goto V_212;
}
if ( F_38 ( V_2 ) ) {
error = F_106 ( V_68 , F_59 ( V_68 ) ,
V_50 , V_187 , V_188 ) ;
if ( error )
goto V_212;
}
F_63 ( V_68 , V_73 ) ;
F_45 ( V_68 ) ;
* V_208 = V_213 ;
return 0 ;
V_212:
F_63 ( V_68 , V_73 ) ;
F_45 ( V_68 ) ;
* V_208 = V_214 ;
return error ;
}
STATIC int
F_120 (
struct V_3 * V_4 ,
void * V_5 )
{
struct V_164 * V_165 = V_5 ;
struct V_30 * V_31 = NULL ;
int error = 0 ;
F_10 ( V_4 ) ;
if ( V_4 -> V_26 & V_27 )
goto V_215;
if ( ! F_13 ( V_4 ) )
goto V_215;
F_12 ( V_4 ) ;
error = F_14 ( V_4 , & V_31 ) ;
if ( error )
goto V_215;
F_100 ( V_31 , V_165 ) ;
F_17 ( V_31 ) ;
V_215:
F_11 ( V_4 ) ;
return error ;
}
int
F_35 (
T_3 * V_2 )
{
int V_79 , V_216 , error , V_217 ;
T_18 V_218 ;
T_20 V_219 ;
T_4 * V_220 , * V_221 ;
T_2 V_44 ;
F_121 ( V_165 ) ;
V_216 = V_222 ;
V_219 = 1 ;
V_218 = 0 ;
V_44 = 0 ;
ASSERT ( V_2 -> V_8 -> V_66 || V_2 -> V_8 -> V_67 ) ;
ASSERT ( F_32 ( V_2 ) ) ;
F_31 ( V_2 , L_7 ) ;
V_220 = V_2 -> V_8 -> V_66 ;
if ( V_220 ) {
error = F_101 ( V_2 , V_220 , V_45 ,
& V_165 ) ;
if ( error )
goto V_223;
V_44 |= V_57 ;
}
V_221 = V_2 -> V_8 -> V_67 ;
if ( V_221 ) {
error = F_101 ( V_2 , V_221 , F_37 ( V_2 ) ?
V_47 : V_49 ,
& V_165 ) ;
if ( error )
goto V_223;
V_44 |= V_58 ;
}
do {
error = F_122 ( V_2 , & V_218 , & V_216 ,
F_117 ,
V_219 , NULL , & V_79 ) ;
if ( error )
break;
} while ( ! V_79 );
if ( F_36 ( V_2 ) ) {
error = F_1 ( V_2 , V_46 , F_120 ,
& V_165 ) ;
}
if ( F_37 ( V_2 ) ) {
V_217 = F_1 ( V_2 , V_48 , F_120 ,
& V_165 ) ;
if ( ! error )
error = V_217 ;
}
if ( F_38 ( V_2 ) ) {
V_217 = F_1 ( V_2 , V_50 , F_120 ,
& V_165 ) ;
if ( ! error )
error = V_217 ;
}
V_217 = F_123 ( & V_165 ) ;
if ( ! error )
error = V_217 ;
if ( error ) {
F_27 ( V_2 , V_51 ) ;
goto V_223;
}
V_2 -> V_55 &= ~ V_102 ;
V_2 -> V_55 |= V_44 ;
V_223:
while ( ! F_22 ( & V_165 ) ) {
struct V_30 * V_31 =
F_124 ( & V_165 , struct V_30 , V_224 ) ;
F_23 ( & V_31 -> V_224 ) ;
F_17 ( V_31 ) ;
}
if ( error ) {
F_15 ( V_2 ,
L_8 ,
error ) ;
ASSERT ( V_2 -> V_8 != NULL ) ;
F_29 ( V_2 ) ;
if ( F_125 ( V_2 ) ) {
F_15 ( V_2 ,
L_9 ) ;
}
} else
F_31 ( V_2 , L_10 ) ;
return ( error ) ;
}
STATIC int
F_66 (
T_3 * V_2 )
{
T_4 * V_220 , * V_221 ;
int error ;
T_9 V_225 ;
T_2 V_44 ;
ASSERT ( V_2 -> V_8 ) ;
V_220 = V_221 = NULL ;
V_225 = 0 ;
V_44 = 0 ;
if ( F_89 ( & V_2 -> V_53 ) ) {
if ( F_36 ( V_2 ) &&
V_2 -> V_53 . V_82 != V_152 ) {
ASSERT ( V_2 -> V_53 . V_82 > 0 ) ;
if ( ( error = F_119 ( V_2 , NULL , V_2 -> V_53 . V_82 ,
0 , 0 , & V_220 ) ) )
return F_118 ( error ) ;
}
if ( F_58 ( V_2 ) &&
V_2 -> V_53 . V_83 != V_152 ) {
ASSERT ( V_2 -> V_53 . V_83 > 0 ) ;
if ( ( error = F_119 ( V_2 , NULL , V_2 -> V_53 . V_83 ,
0 , 0 , & V_221 ) ) ) {
if ( V_220 )
F_45 ( V_220 ) ;
return F_118 ( error ) ;
}
}
} else {
V_44 |= V_148 ;
V_225 |= ( V_149 | V_150 |
V_151 | V_62 ) ;
}
if ( F_36 ( V_2 ) && V_220 == NULL ) {
if ( ( error = F_82 ( V_2 , & V_220 ,
V_225 | V_150 ,
V_44 | V_45 ) ) )
return F_118 ( error ) ;
V_44 &= ~ V_148 ;
}
if ( F_58 ( V_2 ) && V_221 == NULL ) {
V_44 |= ( F_37 ( V_2 ) ?
V_47 : V_49 ) ;
error = F_82 ( V_2 , & V_221 ,
V_225 | V_151 , V_44 ) ;
if ( error ) {
if ( V_220 )
F_45 ( V_220 ) ;
return F_118 ( error ) ;
}
}
V_2 -> V_8 -> V_66 = V_220 ;
V_2 -> V_8 -> V_67 = V_221 ;
return 0 ;
}
STATIC void
F_126 (
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_24 ;
struct V_6 * V_7 = V_2 -> V_8 ;
F_4 ( & V_7 -> V_19 ) ;
F_21 ( F_3 ( V_7 , V_4 -> V_20 . V_38 ) ,
F_7 ( V_4 -> V_20 . V_21 ) ) ;
V_7 -> V_39 -- ;
F_6 ( & V_7 -> V_19 ) ;
F_25 ( V_4 ) ;
}
STATIC void
F_127 (
struct V_3 * V_4 ,
struct V_164 * V_165 ,
struct V_164 * V_226 )
{
struct V_1 * V_2 = V_4 -> V_24 ;
struct V_6 * V_7 = V_2 -> V_8 ;
int error ;
if ( ! F_128 ( V_4 ) )
goto V_227;
if ( V_4 -> V_28 ) {
F_11 ( V_4 ) ;
F_129 ( V_4 ) ;
F_130 ( V_228 ) ;
F_23 ( & V_4 -> V_41 ) ;
V_7 -> V_42 -- ;
F_24 ( V_43 ) ;
return;
}
if ( ! F_131 ( V_4 ) )
goto V_229;
if ( F_13 ( V_4 ) ) {
struct V_30 * V_31 = NULL ;
F_132 ( V_4 ) ;
error = F_14 ( V_4 , & V_31 ) ;
if ( error ) {
F_15 ( V_2 , L_1 ,
V_32 , V_4 ) ;
goto V_229;
}
F_100 ( V_31 , V_165 ) ;
F_17 ( V_31 ) ;
goto V_229;
}
F_20 ( V_4 ) ;
V_4 -> V_26 |= V_27 ;
F_11 ( V_4 ) ;
ASSERT ( V_4 -> V_28 == 0 ) ;
F_133 ( & V_4 -> V_41 , V_226 ) ;
V_7 -> V_42 -- ;
F_24 ( V_43 ) ;
F_134 ( V_4 ) ;
F_130 ( V_230 ) ;
return;
V_229:
F_11 ( V_4 ) ;
V_227:
F_133 ( & V_4 -> V_41 , & V_7 -> V_96 ) ;
F_135 ( V_4 ) ;
F_130 ( V_231 ) ;
}
STATIC int
V_136 (
struct V_232 * V_135 ,
struct V_233 * V_234 )
{
struct V_6 * V_7 =
F_136 ( V_135 , struct V_6 , V_134 ) ;
int V_235 = V_234 -> V_235 ;
F_121 ( V_165 ) ;
F_121 ( V_226 ) ;
struct V_3 * V_4 ;
int error ;
if ( ( V_234 -> V_236 & ( V_237 | V_238 ) ) != ( V_237 | V_238 ) )
return 0 ;
if ( ! V_235 )
goto V_186;
F_4 ( & V_7 -> V_40 ) ;
while ( ! F_22 ( & V_7 -> V_96 ) ) {
if ( V_235 -- <= 0 )
break;
V_4 = F_124 ( & V_7 -> V_96 , struct V_3 ,
V_41 ) ;
F_127 ( V_4 , & V_165 , & V_226 ) ;
}
F_6 ( & V_7 -> V_40 ) ;
error = F_123 ( & V_165 ) ;
if ( error )
F_15 ( NULL , L_11 , V_32 ) ;
while ( ! F_22 ( & V_226 ) ) {
V_4 = F_124 ( & V_226 , struct V_3 , V_41 ) ;
F_23 ( & V_4 -> V_41 ) ;
F_126 ( V_4 ) ;
}
V_186:
return ( V_7 -> V_42 / 100 ) * V_239 ;
}
int
F_41 (
T_3 * V_2 ,
T_9 V_44 )
{
T_10 * V_140 ;
int error ;
V_140 = F_83 ( V_2 , V_240 ) ;
error = F_84 ( V_140 , 0 , F_137 ( V_2 ) ,
0 , 0 , V_241 ) ;
if ( error ) {
F_87 ( V_140 , 0 ) ;
return error ;
}
F_91 ( V_140 , V_44 ) ;
error = F_92 ( V_140 , 0 ) ;
return error ;
}
int
F_138 (
struct V_80 * V_68 ,
T_21 V_242 ,
T_22 V_243 ,
T_23 V_244 ,
T_2 V_44 ,
struct V_3 * * V_245 ,
struct V_3 * * V_246 )
{
struct V_1 * V_2 = V_68 -> V_74 ;
struct V_3 * V_247 , * V_248 ;
int error ;
T_2 V_249 ;
if ( ! F_32 ( V_2 ) || ! F_55 ( V_2 ) )
return 0 ;
V_249 = V_73 ;
F_62 ( V_68 , V_249 ) ;
if ( ( V_44 & V_250 ) && F_139 ( V_68 ) )
V_243 = V_68 -> V_85 . V_89 ;
if ( F_56 ( V_2 , V_68 ) ) {
error = F_57 ( V_68 , V_87 ) ;
if ( error ) {
F_63 ( V_68 , V_249 ) ;
return error ;
}
}
V_247 = V_248 = NULL ;
if ( ( V_44 & V_45 ) && F_36 ( V_2 ) ) {
if ( V_68 -> V_85 . V_86 != V_242 ) {
F_63 ( V_68 , V_249 ) ;
if ( ( error = F_50 ( V_2 , NULL , ( T_5 ) V_242 ,
V_46 ,
V_87 |
V_75 ,
& V_247 ) ) ) {
ASSERT ( error != V_190 ) ;
return error ;
}
F_11 ( V_247 ) ;
V_249 = V_180 ;
F_62 ( V_68 , V_249 ) ;
} else {
ASSERT ( V_68 -> V_88 ) ;
V_247 = F_49 ( V_68 -> V_88 ) ;
}
}
if ( ( V_44 & V_47 ) && F_37 ( V_2 ) ) {
if ( V_68 -> V_85 . V_89 != V_243 ) {
F_63 ( V_68 , V_249 ) ;
if ( ( error = F_50 ( V_2 , NULL , ( T_5 ) V_243 ,
V_48 ,
V_87 |
V_75 ,
& V_248 ) ) ) {
if ( V_247 )
F_53 ( V_247 ) ;
ASSERT ( error != V_190 ) ;
return error ;
}
F_11 ( V_248 ) ;
V_249 = V_180 ;
F_62 ( V_68 , V_249 ) ;
} else {
ASSERT ( V_68 -> V_90 ) ;
V_248 = F_49 ( V_68 -> V_90 ) ;
}
} else if ( ( V_44 & V_49 ) && F_38 ( V_2 ) ) {
if ( F_59 ( V_68 ) != V_244 ) {
F_63 ( V_68 , V_249 ) ;
if ( ( error = F_50 ( V_2 , NULL , ( T_5 ) V_244 ,
V_50 ,
V_87 |
V_75 ,
& V_248 ) ) ) {
if ( V_247 )
F_53 ( V_247 ) ;
ASSERT ( error != V_190 ) ;
return ( error ) ;
}
F_11 ( V_248 ) ;
V_249 = V_180 ;
F_62 ( V_68 , V_249 ) ;
} else {
ASSERT ( V_68 -> V_90 ) ;
V_248 = F_49 ( V_68 -> V_90 ) ;
}
}
if ( V_247 )
F_140 ( V_68 ) ;
F_63 ( V_68 , V_249 ) ;
if ( V_245 )
* V_245 = V_247 ;
else if ( V_247 )
F_53 ( V_247 ) ;
if ( V_246 )
* V_246 = V_248 ;
else if ( V_248 )
F_53 ( V_248 ) ;
return 0 ;
}
T_6 *
F_141 (
T_10 * V_140 ,
T_4 * V_68 ,
T_6 * * V_251 ,
T_6 * V_252 )
{
T_6 * V_253 ;
T_2 V_254 = F_112 ( V_68 ) ?
V_255 : V_256 ;
ASSERT ( F_47 ( V_68 , V_73 ) ) ;
ASSERT ( F_32 ( V_68 -> V_74 ) ) ;
V_253 = * V_251 ;
ASSERT ( V_253 ) ;
ASSERT ( V_253 != V_252 ) ;
F_142 ( V_140 , V_253 , V_254 , - ( V_68 -> V_85 . V_176 ) ) ;
F_142 ( V_140 , V_253 , V_257 , - 1 ) ;
F_142 ( V_140 , V_252 , V_254 , V_68 -> V_85 . V_176 ) ;
F_142 ( V_140 , V_252 , V_257 , 1 ) ;
* V_251 = F_49 ( V_252 ) ;
return V_253 ;
}
int
F_143 (
T_10 * V_140 ,
T_4 * V_68 ,
T_6 * V_258 ,
T_6 * V_25 ,
T_2 V_44 )
{
T_3 * V_2 = V_68 -> V_74 ;
T_2 V_259 , V_260 , V_261 = 0 ;
T_6 * V_262 , * V_263 , * V_264 , * V_265 ;
int error ;
ASSERT ( F_47 ( V_68 , V_73 | V_180 ) ) ;
ASSERT ( F_32 ( V_2 ) ) ;
V_259 = V_68 -> V_211 ;
V_264 = V_265 = V_262 = V_263 = NULL ;
V_260 = F_112 ( V_68 ) ?
V_266 : V_267 ;
if ( F_36 ( V_2 ) && V_258 &&
V_68 -> V_85 . V_86 != ( T_21 ) F_7 ( V_258 -> V_20 . V_21 ) ) {
V_264 = V_258 ;
if ( V_259 ) {
ASSERT ( V_68 -> V_88 ) ;
V_262 = V_68 -> V_88 ;
}
}
if ( F_58 ( V_68 -> V_74 ) && V_25 ) {
if ( F_38 ( V_68 -> V_74 ) &&
F_59 ( V_68 ) != F_7 ( V_25 -> V_20 . V_21 ) )
V_261 = V_268 ;
if ( V_261 ||
( F_37 ( V_68 -> V_74 ) &&
V_68 -> V_85 . V_89 != F_7 ( V_25 -> V_20 . V_21 ) ) ) {
V_265 = V_25 ;
if ( V_259 ) {
ASSERT ( V_68 -> V_90 ) ;
V_263 = V_68 -> V_90 ;
}
}
}
if ( ( error = F_144 ( V_140 , V_68 -> V_74 ,
V_264 , V_265 , V_68 -> V_85 . V_176 , 1 ,
V_44 | V_260 | V_261 ) ) )
return ( error ) ;
if ( V_259 ) {
ASSERT ( V_264 || V_265 ) ;
ASSERT ( V_262 || V_263 ) ;
if ( ( error = F_144 ( NULL , V_68 -> V_74 ,
V_264 , V_265 , ( T_15 ) V_259 , 0 ,
V_44 | V_260 | V_261 ) ) )
return ( error ) ;
F_144 ( NULL , V_68 -> V_74 ,
V_262 , V_263 , - ( ( T_15 ) V_259 ) , 0 ,
V_260 ) ;
}
return ( 0 ) ;
}
int
F_145 (
struct V_80 * * V_269 )
{
struct V_1 * V_2 = V_269 [ 0 ] -> V_74 ;
int V_18 ;
if ( ! F_32 ( V_2 ) || ! F_55 ( V_2 ) )
return 0 ;
for ( V_18 = 0 ; ( V_18 < 4 && V_269 [ V_18 ] ) ; V_18 ++ ) {
struct V_80 * V_68 = V_269 [ V_18 ] ;
int error ;
if ( V_18 == 0 || V_68 != V_269 [ V_18 - 1 ] ) {
if ( F_56 ( V_2 , V_68 ) ) {
error = F_61 ( V_68 , 0 ) ;
if ( error )
return error ;
}
}
}
return 0 ;
}
void
F_146 (
struct V_270 * V_140 ,
struct V_80 * V_68 ,
struct V_3 * V_258 ,
struct V_3 * V_25 )
{
struct V_1 * V_2 = V_140 -> V_271 ;
if ( ! F_32 ( V_2 ) || ! F_55 ( V_2 ) )
return;
ASSERT ( F_47 ( V_68 , V_73 ) ) ;
ASSERT ( F_32 ( V_2 ) ) ;
if ( V_258 ) {
ASSERT ( V_68 -> V_88 == NULL ) ;
ASSERT ( F_36 ( V_2 ) ) ;
ASSERT ( V_68 -> V_85 . V_86 == F_7 ( V_258 -> V_20 . V_21 ) ) ;
V_68 -> V_88 = F_49 ( V_258 ) ;
F_142 ( V_140 , V_258 , V_257 , 1 ) ;
}
if ( V_25 ) {
ASSERT ( V_68 -> V_90 == NULL ) ;
ASSERT ( F_58 ( V_2 ) ) ;
ASSERT ( ( F_37 ( V_2 ) ?
V_68 -> V_85 . V_89 : F_59 ( V_68 ) ) ==
F_7 ( V_25 -> V_20 . V_21 ) ) ;
V_68 -> V_90 = F_49 ( V_25 ) ;
F_142 ( V_140 , V_25 , V_257 , 1 ) ;
}
}
