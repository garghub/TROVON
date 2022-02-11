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
V_2 -> V_8 -> V_98 , 0 , & V_31 ) ;
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
struct V_80 * V_167 ,
T_2 V_44 ,
struct V_164 * V_165 )
{
struct V_168 * V_169 ;
int V_18 , V_170 ;
int error ;
T_14 V_171 ;
T_13 V_172 ;
T_5 V_161 ;
T_12 V_173 ;
T_13 V_174 ;
error = 0 ;
if ( V_167 -> V_85 . V_175 == 0 )
return 0 ;
V_169 = F_102 ( V_176 * sizeof( * V_169 ) , V_92 ) ;
V_171 = 0 ;
V_172 = F_103 ( V_2 , ( V_177 ) F_104 ( V_2 ) ) ;
do {
V_170 = V_176 ;
F_62 ( V_167 , V_178 ) ;
error = F_105 ( V_167 , V_171 , V_172 - V_171 ,
V_169 , & V_170 , 0 ) ;
F_63 ( V_167 , V_178 ) ;
if ( error )
break;
ASSERT ( V_170 <= V_176 ) ;
for ( V_18 = 0 ; V_18 < V_170 ; V_18 ++ ) {
ASSERT ( V_169 [ V_18 ] . V_179 != V_180 ) ;
ASSERT ( V_169 [ V_18 ] . V_181 ) ;
V_171 += V_169 [ V_18 ] . V_181 ;
if ( V_169 [ V_18 ] . V_179 == V_182 )
continue;
V_161 = ( T_5 ) V_169 [ V_18 ] . V_183 *
V_2 -> V_8 -> V_100 ;
if ( ( V_18 + 1 < V_170 ) &&
( V_169 [ V_18 + 1 ] . V_179 != V_182 ) ) {
V_174 = V_169 [ V_18 + 1 ] . V_181 ;
V_173 = V_169 [ V_18 + 1 ] . V_179 ;
while ( V_174 -- ) {
F_106 ( V_2 -> V_166 ,
F_99 ( V_2 , V_173 ) ,
V_2 -> V_8 -> V_98 ) ;
V_173 ++ ;
}
}
error = F_97 ( V_2 , V_161 ,
V_169 [ V_18 ] . V_179 ,
V_169 [ V_18 ] . V_181 ,
V_44 , V_165 ) ;
if ( error )
goto V_184;
}
} while ( V_170 > 0 );
V_184:
F_67 ( V_169 ) ;
return error ;
}
STATIC int
F_107 (
struct V_80 * V_68 ,
T_5 V_69 ,
T_2 type ,
T_15 V_185 ,
T_15 V_186 )
{
struct V_1 * V_2 = V_68 -> V_74 ;
struct V_3 * V_4 ;
int error ;
error = F_50 ( V_2 , V_68 , V_69 , type ,
V_87 | V_75 , & V_4 ) ;
if ( error ) {
ASSERT ( error != V_187 ) ;
ASSERT ( error != V_188 ) ;
return error ;
}
F_108 ( V_4 ) ;
F_109 ( & V_4 -> V_20 . V_159 , 1 ) ;
V_4 -> V_189 ++ ;
if ( V_185 ) {
F_109 ( & V_4 -> V_20 . V_158 , V_185 ) ;
V_4 -> V_190 += V_185 ;
}
if ( V_186 ) {
F_109 ( & V_4 -> V_20 . V_160 , V_186 ) ;
V_4 -> V_191 += V_186 ;
}
if ( V_4 -> V_20 . V_21 ) {
F_110 ( V_2 , & V_4 -> V_20 ) ;
F_111 ( V_2 , & V_4 -> V_20 ) ;
}
V_4 -> V_26 |= V_192 ;
F_26 ( V_4 ) ;
return 0 ;
}
STATIC int
F_112 (
T_4 * V_68 ,
T_15 * V_193 )
{
T_13 V_186 ;
T_16 V_194 ;
T_17 * V_195 ;
T_16 V_196 ;
int error ;
ASSERT ( F_113 ( V_68 ) ) ;
V_195 = F_114 ( V_68 , V_197 ) ;
if ( ! ( V_195 -> V_198 & V_199 ) ) {
if ( ( error = F_115 ( NULL , V_68 , V_197 ) ) )
return error ;
}
V_186 = 0 ;
V_196 = V_195 -> V_200 / ( T_2 ) sizeof( V_201 ) ;
for ( V_194 = 0 ; V_194 < V_196 ; V_194 ++ )
V_186 += F_116 ( F_117 ( V_195 , V_194 ) ) ;
* V_193 = ( T_15 ) V_186 ;
return 0 ;
}
STATIC int
F_118 (
T_3 * V_2 ,
T_18 V_202 ,
void T_19 * V_203 ,
int V_204 ,
int * V_205 ,
int * V_206 )
{
T_4 * V_68 ;
T_15 V_185 , V_186 = 0 ;
int error ;
ASSERT ( F_32 ( V_2 ) ) ;
if ( V_202 == V_2 -> V_53 . V_82 || V_202 == V_2 -> V_53 . V_83 ) {
* V_206 = V_207 ;
return F_119 ( V_208 ) ;
}
error = F_120 ( V_2 , NULL , V_202 , 0 , V_73 , & V_68 ) ;
if ( error ) {
* V_206 = V_207 ;
return error ;
}
ASSERT ( V_68 -> V_209 == 0 ) ;
if ( F_113 ( V_68 ) ) {
error = F_112 ( V_68 , & V_186 ) ;
if ( error )
goto V_210;
}
V_185 = ( T_15 ) V_68 -> V_85 . V_175 - V_186 ;
if ( F_36 ( V_2 ) ) {
error = F_107 ( V_68 , V_68 -> V_85 . V_86 ,
V_46 , V_185 , V_186 ) ;
if ( error )
goto V_210;
}
if ( F_37 ( V_2 ) ) {
error = F_107 ( V_68 , V_68 -> V_85 . V_89 ,
V_48 , V_185 , V_186 ) ;
if ( error )
goto V_210;
}
if ( F_38 ( V_2 ) ) {
error = F_107 ( V_68 , F_59 ( V_68 ) ,
V_50 , V_185 , V_186 ) ;
if ( error )
goto V_210;
}
F_63 ( V_68 , V_73 ) ;
F_45 ( V_68 ) ;
* V_206 = V_211 ;
return 0 ;
V_210:
F_63 ( V_68 , V_73 ) ;
F_45 ( V_68 ) ;
* V_206 = V_212 ;
return error ;
}
STATIC int
F_121 (
struct V_3 * V_4 ,
void * V_5 )
{
struct V_164 * V_165 = V_5 ;
struct V_30 * V_31 = NULL ;
int error = 0 ;
F_10 ( V_4 ) ;
if ( V_4 -> V_26 & V_27 )
goto V_213;
if ( ! F_13 ( V_4 ) )
goto V_213;
F_12 ( V_4 ) ;
error = F_14 ( V_4 , & V_31 ) ;
if ( error )
goto V_213;
F_100 ( V_31 , V_165 ) ;
F_17 ( V_31 ) ;
V_213:
F_11 ( V_4 ) ;
return error ;
}
int
F_35 (
T_3 * V_2 )
{
int V_79 , V_214 , error , V_215 ;
T_18 V_216 ;
T_20 V_217 ;
T_4 * V_218 , * V_219 ;
T_2 V_44 ;
F_122 ( V_165 ) ;
V_214 = V_220 ;
V_217 = 1 ;
V_216 = 0 ;
V_44 = 0 ;
ASSERT ( V_2 -> V_8 -> V_66 || V_2 -> V_8 -> V_67 ) ;
ASSERT ( F_32 ( V_2 ) ) ;
F_31 ( V_2 , L_7 ) ;
V_218 = V_2 -> V_8 -> V_66 ;
if ( V_218 ) {
error = F_101 ( V_2 , V_218 , V_45 ,
& V_165 ) ;
if ( error )
goto V_221;
V_44 |= V_57 ;
}
V_219 = V_2 -> V_8 -> V_67 ;
if ( V_219 ) {
error = F_101 ( V_2 , V_219 , F_37 ( V_2 ) ?
V_47 : V_49 ,
& V_165 ) ;
if ( error )
goto V_221;
V_44 |= V_58 ;
}
do {
error = F_123 ( V_2 , & V_216 , & V_214 ,
F_118 ,
V_217 , NULL , & V_79 ) ;
if ( error )
break;
} while ( ! V_79 );
if ( F_36 ( V_2 ) ) {
error = F_1 ( V_2 , V_46 , F_121 ,
& V_165 ) ;
}
if ( F_37 ( V_2 ) ) {
V_215 = F_1 ( V_2 , V_48 , F_121 ,
& V_165 ) ;
if ( ! error )
error = V_215 ;
}
if ( F_38 ( V_2 ) ) {
V_215 = F_1 ( V_2 , V_50 , F_121 ,
& V_165 ) ;
if ( ! error )
error = V_215 ;
}
V_215 = F_124 ( & V_165 ) ;
if ( ! error )
error = V_215 ;
if ( error ) {
F_27 ( V_2 , V_51 ) ;
goto V_221;
}
V_2 -> V_55 &= ~ V_102 ;
V_2 -> V_55 |= V_44 ;
V_221:
while ( ! F_22 ( & V_165 ) ) {
struct V_30 * V_31 =
F_125 ( & V_165 , struct V_30 , V_222 ) ;
F_23 ( & V_31 -> V_222 ) ;
F_17 ( V_31 ) ;
}
if ( error ) {
F_15 ( V_2 ,
L_8 ,
error ) ;
ASSERT ( V_2 -> V_8 != NULL ) ;
F_29 ( V_2 ) ;
if ( F_126 ( V_2 ) ) {
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
T_4 * V_218 , * V_219 ;
int error ;
T_9 V_223 ;
T_2 V_44 ;
ASSERT ( V_2 -> V_8 ) ;
V_218 = V_219 = NULL ;
V_223 = 0 ;
V_44 = 0 ;
if ( F_89 ( & V_2 -> V_53 ) ) {
if ( F_36 ( V_2 ) &&
V_2 -> V_53 . V_82 != V_152 ) {
ASSERT ( V_2 -> V_53 . V_82 > 0 ) ;
if ( ( error = F_120 ( V_2 , NULL , V_2 -> V_53 . V_82 ,
0 , 0 , & V_218 ) ) )
return F_119 ( error ) ;
}
if ( F_58 ( V_2 ) &&
V_2 -> V_53 . V_83 != V_152 ) {
ASSERT ( V_2 -> V_53 . V_83 > 0 ) ;
if ( ( error = F_120 ( V_2 , NULL , V_2 -> V_53 . V_83 ,
0 , 0 , & V_219 ) ) ) {
if ( V_218 )
F_45 ( V_218 ) ;
return F_119 ( error ) ;
}
}
} else {
V_44 |= V_148 ;
V_223 |= ( V_149 | V_150 |
V_151 | V_62 ) ;
}
if ( F_36 ( V_2 ) && V_218 == NULL ) {
if ( ( error = F_82 ( V_2 , & V_218 ,
V_223 | V_150 ,
V_44 | V_45 ) ) )
return F_119 ( error ) ;
V_44 &= ~ V_148 ;
}
if ( F_58 ( V_2 ) && V_219 == NULL ) {
V_44 |= ( F_37 ( V_2 ) ?
V_47 : V_49 ) ;
error = F_82 ( V_2 , & V_219 ,
V_223 | V_151 , V_44 ) ;
if ( error ) {
if ( V_218 )
F_45 ( V_218 ) ;
return F_119 ( error ) ;
}
}
V_2 -> V_8 -> V_66 = V_218 ;
V_2 -> V_8 -> V_67 = V_219 ;
return 0 ;
}
STATIC void
F_127 (
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
F_128 (
struct V_3 * V_4 ,
struct V_164 * V_165 ,
struct V_164 * V_224 )
{
struct V_1 * V_2 = V_4 -> V_24 ;
struct V_6 * V_7 = V_2 -> V_8 ;
int error ;
if ( ! F_129 ( V_4 ) )
goto V_225;
if ( V_4 -> V_28 ) {
F_11 ( V_4 ) ;
F_130 ( V_4 ) ;
F_131 ( V_226 ) ;
F_23 ( & V_4 -> V_41 ) ;
V_7 -> V_42 -- ;
F_24 ( V_43 ) ;
return;
}
if ( ! F_132 ( V_4 ) )
goto V_225;
if ( F_13 ( V_4 ) ) {
struct V_30 * V_31 = NULL ;
F_133 ( V_4 ) ;
error = F_14 ( V_4 , & V_31 ) ;
if ( error ) {
F_15 ( V_2 , L_1 ,
V_32 , V_4 ) ;
goto V_225;
}
F_100 ( V_31 , V_165 ) ;
F_17 ( V_31 ) ;
goto V_225;
}
F_20 ( V_4 ) ;
V_4 -> V_26 |= V_27 ;
F_11 ( V_4 ) ;
ASSERT ( V_4 -> V_28 == 0 ) ;
F_134 ( & V_4 -> V_41 , V_224 ) ;
V_7 -> V_42 -- ;
F_24 ( V_43 ) ;
F_135 ( V_4 ) ;
F_131 ( V_227 ) ;
return;
V_225:
F_11 ( V_4 ) ;
F_134 ( & V_4 -> V_41 , & V_7 -> V_96 ) ;
F_136 ( V_4 ) ;
F_131 ( V_228 ) ;
}
STATIC int
V_136 (
struct V_229 * V_135 ,
struct V_230 * V_231 )
{
struct V_6 * V_7 =
F_137 ( V_135 , struct V_6 , V_134 ) ;
int V_232 = V_231 -> V_232 ;
F_122 ( V_165 ) ;
F_122 ( V_224 ) ;
struct V_3 * V_4 ;
int error ;
if ( ( V_231 -> V_233 & ( V_234 | V_235 ) ) != ( V_234 | V_235 ) )
return 0 ;
if ( ! V_232 )
goto V_184;
F_4 ( & V_7 -> V_40 ) ;
while ( ! F_22 ( & V_7 -> V_96 ) ) {
if ( V_232 -- <= 0 )
break;
V_4 = F_125 ( & V_7 -> V_96 , struct V_3 ,
V_41 ) ;
F_128 ( V_4 , & V_165 , & V_224 ) ;
}
F_6 ( & V_7 -> V_40 ) ;
error = F_124 ( & V_165 ) ;
if ( error )
F_15 ( NULL , L_11 , V_32 ) ;
while ( ! F_22 ( & V_224 ) ) {
V_4 = F_125 ( & V_224 , struct V_3 , V_41 ) ;
F_23 ( & V_4 -> V_41 ) ;
F_127 ( V_4 ) ;
}
V_184:
return ( V_7 -> V_42 / 100 ) * V_236 ;
}
int
F_41 (
T_3 * V_2 ,
T_9 V_44 )
{
T_10 * V_140 ;
int error ;
V_140 = F_83 ( V_2 , V_237 ) ;
if ( ( error = F_84 ( V_140 , 0 ,
V_2 -> V_53 . V_238 + 128 , 0 ,
0 ,
V_239 ) ) ) {
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
T_21 V_240 ,
T_22 V_241 ,
T_23 V_242 ,
T_2 V_44 ,
struct V_3 * * V_243 ,
struct V_3 * * V_244 )
{
struct V_1 * V_2 = V_68 -> V_74 ;
struct V_3 * V_245 , * V_246 ;
int error ;
T_2 V_247 ;
if ( ! F_32 ( V_2 ) || ! F_55 ( V_2 ) )
return 0 ;
V_247 = V_73 ;
F_62 ( V_68 , V_247 ) ;
if ( ( V_44 & V_248 ) && F_139 ( V_68 ) )
V_241 = V_68 -> V_85 . V_89 ;
if ( F_56 ( V_2 , V_68 ) ) {
error = F_57 ( V_68 , V_87 ) ;
if ( error ) {
F_63 ( V_68 , V_247 ) ;
return error ;
}
}
V_245 = V_246 = NULL ;
if ( ( V_44 & V_45 ) && F_36 ( V_2 ) ) {
if ( V_68 -> V_85 . V_86 != V_240 ) {
F_63 ( V_68 , V_247 ) ;
if ( ( error = F_50 ( V_2 , NULL , ( T_5 ) V_240 ,
V_46 ,
V_87 |
V_75 ,
& V_245 ) ) ) {
ASSERT ( error != V_188 ) ;
return error ;
}
F_11 ( V_245 ) ;
V_247 = V_178 ;
F_62 ( V_68 , V_247 ) ;
} else {
ASSERT ( V_68 -> V_88 ) ;
V_245 = F_49 ( V_68 -> V_88 ) ;
}
}
if ( ( V_44 & V_47 ) && F_37 ( V_2 ) ) {
if ( V_68 -> V_85 . V_89 != V_241 ) {
F_63 ( V_68 , V_247 ) ;
if ( ( error = F_50 ( V_2 , NULL , ( T_5 ) V_241 ,
V_48 ,
V_87 |
V_75 ,
& V_246 ) ) ) {
if ( V_245 )
F_53 ( V_245 ) ;
ASSERT ( error != V_188 ) ;
return error ;
}
F_11 ( V_246 ) ;
V_247 = V_178 ;
F_62 ( V_68 , V_247 ) ;
} else {
ASSERT ( V_68 -> V_90 ) ;
V_246 = F_49 ( V_68 -> V_90 ) ;
}
} else if ( ( V_44 & V_49 ) && F_38 ( V_2 ) ) {
if ( F_59 ( V_68 ) != V_242 ) {
F_63 ( V_68 , V_247 ) ;
if ( ( error = F_50 ( V_2 , NULL , ( T_5 ) V_242 ,
V_50 ,
V_87 |
V_75 ,
& V_246 ) ) ) {
if ( V_245 )
F_53 ( V_245 ) ;
ASSERT ( error != V_188 ) ;
return ( error ) ;
}
F_11 ( V_246 ) ;
V_247 = V_178 ;
F_62 ( V_68 , V_247 ) ;
} else {
ASSERT ( V_68 -> V_90 ) ;
V_246 = F_49 ( V_68 -> V_90 ) ;
}
}
if ( V_245 )
F_140 ( V_68 ) ;
F_63 ( V_68 , V_247 ) ;
if ( V_243 )
* V_243 = V_245 ;
else if ( V_245 )
F_53 ( V_245 ) ;
if ( V_244 )
* V_244 = V_246 ;
else if ( V_246 )
F_53 ( V_246 ) ;
return 0 ;
}
T_6 *
F_141 (
T_10 * V_140 ,
T_4 * V_68 ,
T_6 * * V_249 ,
T_6 * V_250 )
{
T_6 * V_251 ;
T_2 V_252 = F_113 ( V_68 ) ?
V_253 : V_254 ;
ASSERT ( F_47 ( V_68 , V_73 ) ) ;
ASSERT ( F_32 ( V_68 -> V_74 ) ) ;
V_251 = * V_249 ;
ASSERT ( V_251 ) ;
ASSERT ( V_251 != V_250 ) ;
F_142 ( V_140 , V_251 , V_252 , - ( V_68 -> V_85 . V_175 ) ) ;
F_142 ( V_140 , V_251 , V_255 , - 1 ) ;
F_142 ( V_140 , V_250 , V_252 , V_68 -> V_85 . V_175 ) ;
F_142 ( V_140 , V_250 , V_255 , 1 ) ;
* V_249 = F_49 ( V_250 ) ;
return V_251 ;
}
int
F_143 (
T_10 * V_140 ,
T_4 * V_68 ,
T_6 * V_256 ,
T_6 * V_25 ,
T_2 V_44 )
{
T_3 * V_2 = V_68 -> V_74 ;
T_2 V_257 , V_258 , V_259 = 0 ;
T_6 * V_260 , * V_261 , * V_262 , * V_263 ;
int error ;
ASSERT ( F_47 ( V_68 , V_73 | V_178 ) ) ;
ASSERT ( F_32 ( V_2 ) ) ;
V_257 = V_68 -> V_209 ;
V_262 = V_263 = V_260 = V_261 = NULL ;
V_258 = F_113 ( V_68 ) ?
V_264 : V_265 ;
if ( F_36 ( V_2 ) && V_256 &&
V_68 -> V_85 . V_86 != ( T_21 ) F_7 ( V_256 -> V_20 . V_21 ) ) {
V_262 = V_256 ;
if ( V_257 ) {
ASSERT ( V_68 -> V_88 ) ;
V_260 = V_68 -> V_88 ;
}
}
if ( F_58 ( V_68 -> V_74 ) && V_25 ) {
if ( F_38 ( V_68 -> V_74 ) &&
F_59 ( V_68 ) != F_7 ( V_25 -> V_20 . V_21 ) )
V_259 = V_266 ;
if ( V_259 ||
( F_37 ( V_68 -> V_74 ) &&
V_68 -> V_85 . V_89 != F_7 ( V_25 -> V_20 . V_21 ) ) ) {
V_263 = V_25 ;
if ( V_257 ) {
ASSERT ( V_68 -> V_90 ) ;
V_261 = V_68 -> V_90 ;
}
}
}
if ( ( error = F_144 ( V_140 , V_68 -> V_74 ,
V_262 , V_263 , V_68 -> V_85 . V_175 , 1 ,
V_44 | V_258 | V_259 ) ) )
return ( error ) ;
if ( V_257 ) {
ASSERT ( V_262 || V_263 ) ;
ASSERT ( V_260 || V_261 ) ;
if ( ( error = F_144 ( NULL , V_68 -> V_74 ,
V_262 , V_263 , ( T_15 ) V_257 , 0 ,
V_44 | V_258 | V_259 ) ) )
return ( error ) ;
F_144 ( NULL , V_68 -> V_74 ,
V_260 , V_261 , - ( ( T_15 ) V_257 ) , 0 ,
V_258 ) ;
}
return ( 0 ) ;
}
int
F_145 (
struct V_80 * * V_267 )
{
struct V_1 * V_2 = V_267 [ 0 ] -> V_74 ;
int V_18 ;
if ( ! F_32 ( V_2 ) || ! F_55 ( V_2 ) )
return 0 ;
for ( V_18 = 0 ; ( V_18 < 4 && V_267 [ V_18 ] ) ; V_18 ++ ) {
struct V_80 * V_68 = V_267 [ V_18 ] ;
int error ;
if ( V_18 == 0 || V_68 != V_267 [ V_18 - 1 ] ) {
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
struct V_268 * V_140 ,
struct V_80 * V_68 ,
struct V_3 * V_256 ,
struct V_3 * V_25 )
{
struct V_1 * V_2 = V_140 -> V_269 ;
if ( ! F_32 ( V_2 ) || ! F_55 ( V_2 ) )
return;
ASSERT ( F_47 ( V_68 , V_73 ) ) ;
ASSERT ( F_32 ( V_2 ) ) ;
if ( V_256 ) {
ASSERT ( V_68 -> V_88 == NULL ) ;
ASSERT ( F_36 ( V_2 ) ) ;
ASSERT ( V_68 -> V_85 . V_86 == F_7 ( V_256 -> V_20 . V_21 ) ) ;
V_68 -> V_88 = F_49 ( V_256 ) ;
F_142 ( V_140 , V_256 , V_255 , 1 ) ;
}
if ( V_25 ) {
ASSERT ( V_68 -> V_90 == NULL ) ;
ASSERT ( F_58 ( V_2 ) ) ;
ASSERT ( ( F_37 ( V_2 ) ?
V_68 -> V_85 . V_89 : F_59 ( V_68 ) ) ==
F_7 ( V_25 -> V_20 . V_21 ) ) ;
V_68 -> V_90 = F_49 ( V_25 ) ;
F_142 ( V_140 , V_25 , V_255 , 1 ) ;
}
}
