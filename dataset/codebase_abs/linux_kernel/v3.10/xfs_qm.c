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
int
F_65 (
struct V_1 * V_2 ,
unsigned int V_91 )
{
unsigned int V_92 ;
ASSERT ( V_91 > 0 ) ;
V_92 = F_66 ( V_91 ) ;
F_67 ( V_92 , sizeof( V_93 ) ) ;
return V_92 ;
}
STATIC int
F_33 (
T_3 * V_2 )
{
T_7 * V_94 ;
int error ;
T_6 * V_4 ;
ASSERT ( F_32 ( V_2 ) ) ;
V_94 = V_2 -> V_8 = F_68 ( sizeof( T_7 ) , V_95 ) ;
if ( ( error = F_69 ( V_2 ) ) ) {
F_70 ( V_94 ) ;
V_2 -> V_8 = NULL ;
return error ;
}
F_71 ( & V_94 -> V_96 , V_97 ) ;
F_71 ( & V_94 -> V_98 , V_97 ) ;
F_72 ( & V_94 -> V_19 ) ;
F_73 ( & V_94 -> V_99 ) ;
V_94 -> V_42 = 0 ;
F_72 ( & V_94 -> V_40 ) ;
F_72 ( & V_94 -> V_100 ) ;
V_94 -> V_101 = F_74 ( V_2 , V_102 ) ;
V_94 -> V_103 = F_65 ( V_2 ,
V_94 -> V_101 ) ;
V_2 -> V_55 |= ( V_2 -> V_53 . V_60 & V_104 ) ;
error = F_75 ( V_2 , 0 ,
F_76 ( V_2 ) ? V_46 :
( F_77 ( V_2 ) ? V_48 :
V_50 ) ,
V_75 , & V_4 ) ;
if ( ! error ) {
T_8 * V_105 = & V_4 -> V_20 ;
V_94 -> V_106 = V_105 -> V_107 ?
F_7 ( V_105 -> V_107 ) : V_108 ;
V_94 -> V_109 = V_105 -> V_110 ?
F_7 ( V_105 -> V_110 ) : V_111 ;
V_94 -> V_112 = V_105 -> V_113 ?
F_7 ( V_105 -> V_113 ) : V_114 ;
V_94 -> V_115 = V_105 -> V_116 ?
F_78 ( V_105 -> V_116 ) : V_117 ;
V_94 -> V_118 = V_105 -> V_119 ?
F_78 ( V_105 -> V_119 ) : V_120 ;
V_94 -> V_121 = V_105 -> V_122 ?
F_78 ( V_105 -> V_122 ) : V_123 ;
V_94 -> V_124 = F_79 ( V_105 -> V_125 ) ;
V_94 -> V_126 = F_79 ( V_105 -> V_127 ) ;
V_94 -> V_128 = F_79 ( V_105 -> V_129 ) ;
V_94 -> V_130 = F_79 ( V_105 -> V_131 ) ;
V_94 -> V_132 = F_79 ( V_105 -> V_133 ) ;
V_94 -> V_134 = F_79 ( V_105 -> V_135 ) ;
F_25 ( V_4 ) ;
} else {
V_94 -> V_106 = V_108 ;
V_94 -> V_109 = V_111 ;
V_94 -> V_112 = V_114 ;
V_94 -> V_115 = V_117 ;
V_94 -> V_118 = V_120 ;
V_94 -> V_121 = V_123 ;
}
V_94 -> V_136 . V_137 = V_138 ;
V_94 -> V_136 . V_139 = V_140 ;
F_80 ( & V_94 -> V_136 ) ;
return 0 ;
}
void
F_29 (
T_3 * V_2 )
{
T_7 * V_7 ;
V_7 = V_2 -> V_8 ;
ASSERT ( V_7 != NULL ) ;
F_81 ( & V_7 -> V_136 ) ;
if ( V_7 -> V_66 ) {
F_45 ( V_7 -> V_66 ) ;
V_7 -> V_66 = NULL ;
}
if ( V_7 -> V_67 ) {
F_45 ( V_7 -> V_67 ) ;
V_7 -> V_67 = NULL ;
}
F_82 ( & V_7 -> V_100 ) ;
F_70 ( V_7 ) ;
V_2 -> V_8 = NULL ;
}
STATIC int
F_83 (
T_3 * V_2 ,
T_4 * * V_68 ,
T_9 V_141 ,
T_2 V_44 )
{
T_10 * V_142 ;
int error ;
int V_143 ;
V_142 = F_84 ( V_2 , V_144 ) ;
if ( ( error = F_85 ( V_142 ,
F_86 ( V_2 ) ,
F_87 ( V_2 ) , 0 ,
V_145 ,
V_146 ) ) ) {
F_88 ( V_142 , 0 ) ;
return error ;
}
error = F_89 ( & V_142 , NULL , V_147 , 1 , 0 , 0 , 1 , V_68 , & V_143 ) ;
if ( error ) {
F_88 ( V_142 , V_148 |
V_149 ) ;
return error ;
}
F_39 ( & V_2 -> V_59 ) ;
if ( V_44 & V_150 ) {
ASSERT ( ! F_90 ( & V_2 -> V_53 ) ) ;
ASSERT ( ( V_141 & ( V_151 | V_152 |
V_153 | V_62 ) ) ==
( V_151 | V_152 |
V_153 | V_62 ) ) ;
F_91 ( & V_2 -> V_53 ) ;
V_2 -> V_53 . V_82 = V_154 ;
V_2 -> V_53 . V_83 = V_154 ;
V_2 -> V_53 . V_60 = 0 ;
}
if ( V_44 & V_45 )
V_2 -> V_53 . V_82 = ( * V_68 ) -> V_81 ;
else
V_2 -> V_53 . V_83 = ( * V_68 ) -> V_81 ;
F_40 ( & V_2 -> V_59 ) ;
F_92 ( V_142 , V_141 ) ;
if ( ( error = F_93 ( V_142 , V_148 ) ) ) {
F_42 ( V_2 , L_5 , V_32 , error ) ;
return error ;
}
return 0 ;
}
STATIC void
F_94 (
T_3 * V_2 ,
T_11 * V_31 ,
T_5 V_69 ,
T_2 type )
{
struct V_155 * V_156 ;
int V_157 ;
F_95 ( V_31 , V_158 ) ;
#ifdef F_60
V_157 = F_96 ( V_2 , V_102 ) ;
F_67 ( V_157 , sizeof( V_93 ) ) ;
ASSERT ( V_2 -> V_8 -> V_103 == V_157 ) ;
#endif
V_156 = V_31 -> V_159 ;
for ( V_157 = 0 ; V_157 < V_2 -> V_8 -> V_103 ; V_157 ++ ) {
struct V_160 * V_161 ;
V_161 = (struct V_160 * ) & V_156 [ V_157 ] ;
( void ) F_97 ( V_2 , V_161 , V_69 + V_157 , type , V_162 ,
L_6 ) ;
V_161 -> V_163 = 0 ;
V_161 -> V_164 = 0 ;
V_161 -> V_165 = 0 ;
V_161 -> V_107 = 0 ;
V_161 -> V_110 = 0 ;
V_161 -> V_113 = 0 ;
V_161 -> V_116 = 0 ;
V_161 -> V_119 = 0 ;
V_161 -> V_122 = 0 ;
if ( F_98 ( & V_2 -> V_53 ) ) {
F_99 ( ( char * ) & V_156 [ V_157 ] ,
sizeof( struct V_155 ) ,
V_166 ) ;
}
}
}
STATIC int
F_100 (
struct V_1 * V_2 ,
T_5 V_167 ,
T_12 V_168 ,
T_13 V_169 ,
T_2 V_44 ,
struct V_170 * V_171 )
{
struct V_30 * V_31 ;
int error ;
int type ;
ASSERT ( V_169 > 0 ) ;
type = V_44 & V_45 ? V_46 :
( V_44 & V_49 ? V_50 : V_48 ) ;
error = 0 ;
while ( V_169 -- ) {
error = F_101 ( V_2 , NULL , V_2 -> V_172 ,
F_102 ( V_2 , V_168 ) ,
V_2 -> V_8 -> V_101 , 0 , & V_31 ,
& V_173 ) ;
if ( error == V_23 ) {
error = F_101 ( V_2 , NULL , V_2 -> V_172 ,
F_102 ( V_2 , V_168 ) ,
V_2 -> V_8 -> V_101 , 0 , & V_31 ,
NULL ) ;
}
if ( error )
break;
F_94 ( V_2 , V_31 , V_167 , type ) ;
F_103 ( V_31 , V_171 ) ;
F_17 ( V_31 ) ;
V_168 ++ ;
V_167 += V_2 -> V_8 -> V_103 ;
}
return error ;
}
STATIC int
F_104 (
struct V_1 * V_2 ,
struct V_80 * V_174 ,
T_2 V_44 ,
struct V_170 * V_171 )
{
struct V_175 * V_176 ;
int V_18 , V_177 ;
int error ;
T_14 V_178 ;
T_13 V_179 ;
T_5 V_167 ;
T_12 V_180 ;
T_13 V_181 ;
error = 0 ;
if ( V_174 -> V_85 . V_182 == 0 )
return 0 ;
V_176 = F_105 ( V_183 * sizeof( * V_176 ) , V_95 ) ;
V_178 = 0 ;
V_179 = F_106 ( V_2 , V_2 -> V_184 -> V_185 ) ;
do {
V_177 = V_183 ;
F_62 ( V_174 , V_186 ) ;
error = F_107 ( V_174 , V_178 , V_179 - V_178 ,
V_176 , & V_177 , 0 ) ;
F_63 ( V_174 , V_186 ) ;
if ( error )
break;
ASSERT ( V_177 <= V_183 ) ;
for ( V_18 = 0 ; V_18 < V_177 ; V_18 ++ ) {
ASSERT ( V_176 [ V_18 ] . V_187 != V_188 ) ;
ASSERT ( V_176 [ V_18 ] . V_189 ) ;
V_178 += V_176 [ V_18 ] . V_189 ;
if ( V_176 [ V_18 ] . V_187 == V_190 )
continue;
V_167 = ( T_5 ) V_176 [ V_18 ] . V_191 *
V_2 -> V_8 -> V_103 ;
if ( ( V_18 + 1 < V_177 ) &&
( V_176 [ V_18 + 1 ] . V_187 != V_190 ) ) {
V_181 = V_176 [ V_18 + 1 ] . V_189 ;
V_180 = V_176 [ V_18 + 1 ] . V_187 ;
while ( V_181 -- ) {
F_108 ( V_2 -> V_172 ,
F_102 ( V_2 , V_180 ) ,
V_2 -> V_8 -> V_101 ,
NULL ) ;
V_180 ++ ;
}
}
error = F_100 ( V_2 , V_167 ,
V_176 [ V_18 ] . V_187 ,
V_176 [ V_18 ] . V_189 ,
V_44 , V_171 ) ;
if ( error )
goto V_192;
}
} while ( V_177 > 0 );
V_192:
F_70 ( V_176 ) ;
return error ;
}
STATIC int
F_109 (
struct V_80 * V_68 ,
T_5 V_69 ,
T_2 type ,
T_15 V_193 ,
T_15 V_194 )
{
struct V_1 * V_2 = V_68 -> V_74 ;
struct V_3 * V_4 ;
int error ;
error = F_50 ( V_2 , V_68 , V_69 , type ,
V_87 | V_75 , & V_4 ) ;
if ( error ) {
ASSERT ( error != V_195 ) ;
ASSERT ( error != V_196 ) ;
return error ;
}
F_110 ( V_4 ) ;
F_111 ( & V_4 -> V_20 . V_164 , 1 ) ;
V_4 -> V_197 ++ ;
if ( V_193 ) {
F_111 ( & V_4 -> V_20 . V_163 , V_193 ) ;
V_4 -> V_198 += V_193 ;
}
if ( V_194 ) {
F_111 ( & V_4 -> V_20 . V_165 , V_194 ) ;
V_4 -> V_199 += V_194 ;
}
if ( V_4 -> V_20 . V_21 ) {
F_112 ( V_2 , V_4 ) ;
F_113 ( V_2 , & V_4 -> V_20 ) ;
}
V_4 -> V_26 |= V_200 ;
F_26 ( V_4 ) ;
return 0 ;
}
STATIC int
F_114 (
T_4 * V_68 ,
T_15 * V_201 )
{
T_13 V_194 ;
T_16 V_202 ;
T_17 * V_203 ;
T_16 V_204 ;
int error ;
ASSERT ( F_115 ( V_68 ) ) ;
V_203 = F_116 ( V_68 , V_205 ) ;
if ( ! ( V_203 -> V_206 & V_207 ) ) {
if ( ( error = F_117 ( NULL , V_68 , V_205 ) ) )
return error ;
}
V_194 = 0 ;
V_204 = V_203 -> V_208 / ( T_2 ) sizeof( V_209 ) ;
for ( V_202 = 0 ; V_202 < V_204 ; V_202 ++ )
V_194 += F_118 ( F_119 ( V_203 , V_202 ) ) ;
* V_201 = ( T_15 ) V_194 ;
return 0 ;
}
STATIC int
F_120 (
T_3 * V_2 ,
T_18 V_210 ,
void T_19 * V_211 ,
int V_212 ,
int * V_213 ,
int * V_214 )
{
T_4 * V_68 ;
T_15 V_193 , V_194 = 0 ;
int error ;
ASSERT ( F_32 ( V_2 ) ) ;
if ( V_210 == V_2 -> V_53 . V_82 || V_210 == V_2 -> V_53 . V_83 ) {
* V_214 = V_215 ;
return F_121 ( V_216 ) ;
}
error = F_122 ( V_2 , NULL , V_210 , 0 , V_73 , & V_68 ) ;
if ( error ) {
* V_214 = V_215 ;
return error ;
}
ASSERT ( V_68 -> V_217 == 0 ) ;
if ( F_115 ( V_68 ) ) {
error = F_114 ( V_68 , & V_194 ) ;
if ( error )
goto V_218;
}
V_193 = ( T_15 ) V_68 -> V_85 . V_182 - V_194 ;
if ( F_36 ( V_2 ) ) {
error = F_109 ( V_68 , V_68 -> V_85 . V_86 ,
V_46 , V_193 , V_194 ) ;
if ( error )
goto V_218;
}
if ( F_37 ( V_2 ) ) {
error = F_109 ( V_68 , V_68 -> V_85 . V_89 ,
V_48 , V_193 , V_194 ) ;
if ( error )
goto V_218;
}
if ( F_38 ( V_2 ) ) {
error = F_109 ( V_68 , F_59 ( V_68 ) ,
V_50 , V_193 , V_194 ) ;
if ( error )
goto V_218;
}
F_63 ( V_68 , V_73 ) ;
F_45 ( V_68 ) ;
* V_214 = V_219 ;
return 0 ;
V_218:
F_63 ( V_68 , V_73 ) ;
F_45 ( V_68 ) ;
* V_214 = V_220 ;
return error ;
}
STATIC int
F_123 (
struct V_3 * V_4 ,
void * V_5 )
{
struct V_170 * V_171 = V_5 ;
struct V_30 * V_31 = NULL ;
int error = 0 ;
F_10 ( V_4 ) ;
if ( V_4 -> V_26 & V_27 )
goto V_221;
if ( ! F_13 ( V_4 ) )
goto V_221;
F_12 ( V_4 ) ;
error = F_14 ( V_4 , & V_31 ) ;
if ( error )
goto V_221;
F_103 ( V_31 , V_171 ) ;
F_17 ( V_31 ) ;
V_221:
F_11 ( V_4 ) ;
return error ;
}
int
F_35 (
T_3 * V_2 )
{
int V_79 , V_222 , error , V_223 ;
T_18 V_224 ;
T_20 V_225 ;
T_4 * V_226 , * V_227 ;
T_2 V_44 ;
F_124 ( V_171 ) ;
V_222 = V_228 ;
V_225 = 1 ;
V_224 = 0 ;
V_44 = 0 ;
ASSERT ( V_2 -> V_8 -> V_66 || V_2 -> V_8 -> V_67 ) ;
ASSERT ( F_32 ( V_2 ) ) ;
F_31 ( V_2 , L_7 ) ;
V_226 = V_2 -> V_8 -> V_66 ;
if ( V_226 ) {
error = F_104 ( V_2 , V_226 , V_45 ,
& V_171 ) ;
if ( error )
goto V_229;
V_44 |= V_57 ;
}
V_227 = V_2 -> V_8 -> V_67 ;
if ( V_227 ) {
error = F_104 ( V_2 , V_227 , F_37 ( V_2 ) ?
V_47 : V_49 ,
& V_171 ) ;
if ( error )
goto V_229;
V_44 |= V_58 ;
}
do {
error = F_125 ( V_2 , & V_224 , & V_222 ,
F_120 ,
V_225 , NULL , & V_79 ) ;
if ( error )
break;
} while ( ! V_79 );
if ( F_36 ( V_2 ) ) {
error = F_1 ( V_2 , V_46 , F_123 ,
& V_171 ) ;
}
if ( F_37 ( V_2 ) ) {
V_223 = F_1 ( V_2 , V_48 , F_123 ,
& V_171 ) ;
if ( ! error )
error = V_223 ;
}
if ( F_38 ( V_2 ) ) {
V_223 = F_1 ( V_2 , V_50 , F_123 ,
& V_171 ) ;
if ( ! error )
error = V_223 ;
}
V_223 = F_126 ( & V_171 ) ;
if ( ! error )
error = V_223 ;
if ( error ) {
F_27 ( V_2 , V_51 ) ;
goto V_229;
}
V_2 -> V_55 &= ~ V_104 ;
V_2 -> V_55 |= V_44 ;
V_229:
while ( ! F_22 ( & V_171 ) ) {
struct V_30 * V_31 =
F_127 ( & V_171 , struct V_30 , V_230 ) ;
F_23 ( & V_31 -> V_230 ) ;
F_17 ( V_31 ) ;
}
if ( error ) {
F_15 ( V_2 ,
L_8 ,
error ) ;
ASSERT ( V_2 -> V_8 != NULL ) ;
F_29 ( V_2 ) ;
if ( F_128 ( V_2 ) ) {
F_15 ( V_2 ,
L_9 ) ;
}
} else
F_31 ( V_2 , L_10 ) ;
return ( error ) ;
}
STATIC int
F_69 (
T_3 * V_2 )
{
T_4 * V_226 , * V_227 ;
int error ;
T_9 V_231 ;
T_2 V_44 ;
ASSERT ( V_2 -> V_8 ) ;
V_226 = V_227 = NULL ;
V_231 = 0 ;
V_44 = 0 ;
if ( F_90 ( & V_2 -> V_53 ) ) {
if ( F_36 ( V_2 ) &&
V_2 -> V_53 . V_82 != V_154 ) {
ASSERT ( V_2 -> V_53 . V_82 > 0 ) ;
if ( ( error = F_122 ( V_2 , NULL , V_2 -> V_53 . V_82 ,
0 , 0 , & V_226 ) ) )
return F_121 ( error ) ;
}
if ( F_58 ( V_2 ) &&
V_2 -> V_53 . V_83 != V_154 ) {
ASSERT ( V_2 -> V_53 . V_83 > 0 ) ;
if ( ( error = F_122 ( V_2 , NULL , V_2 -> V_53 . V_83 ,
0 , 0 , & V_227 ) ) ) {
if ( V_226 )
F_45 ( V_226 ) ;
return F_121 ( error ) ;
}
}
} else {
V_44 |= V_150 ;
V_231 |= ( V_151 | V_152 |
V_153 | V_62 ) ;
}
if ( F_36 ( V_2 ) && V_226 == NULL ) {
if ( ( error = F_83 ( V_2 , & V_226 ,
V_231 | V_152 ,
V_44 | V_45 ) ) )
return F_121 ( error ) ;
V_44 &= ~ V_150 ;
}
if ( F_58 ( V_2 ) && V_227 == NULL ) {
V_44 |= ( F_37 ( V_2 ) ?
V_47 : V_49 ) ;
error = F_83 ( V_2 , & V_227 ,
V_231 | V_153 , V_44 ) ;
if ( error ) {
if ( V_226 )
F_45 ( V_226 ) ;
return F_121 ( error ) ;
}
}
V_2 -> V_8 -> V_66 = V_226 ;
V_2 -> V_8 -> V_67 = V_227 ;
return 0 ;
}
STATIC void
F_129 (
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
F_130 (
struct V_3 * V_4 ,
struct V_170 * V_171 ,
struct V_170 * V_232 )
{
struct V_1 * V_2 = V_4 -> V_24 ;
struct V_6 * V_7 = V_2 -> V_8 ;
int error ;
if ( ! F_131 ( V_4 ) )
goto V_233;
if ( V_4 -> V_28 ) {
F_11 ( V_4 ) ;
F_132 ( V_4 ) ;
F_133 ( V_234 ) ;
F_23 ( & V_4 -> V_41 ) ;
V_7 -> V_42 -- ;
F_24 ( V_43 ) ;
return;
}
if ( ! F_134 ( V_4 ) )
goto V_235;
if ( F_13 ( V_4 ) ) {
struct V_30 * V_31 = NULL ;
F_135 ( V_4 ) ;
error = F_14 ( V_4 , & V_31 ) ;
if ( error ) {
F_15 ( V_2 , L_1 ,
V_32 , V_4 ) ;
goto V_235;
}
F_103 ( V_31 , V_171 ) ;
F_17 ( V_31 ) ;
goto V_235;
}
F_20 ( V_4 ) ;
V_4 -> V_26 |= V_27 ;
F_11 ( V_4 ) ;
ASSERT ( V_4 -> V_28 == 0 ) ;
F_136 ( & V_4 -> V_41 , V_232 ) ;
V_7 -> V_42 -- ;
F_24 ( V_43 ) ;
F_137 ( V_4 ) ;
F_133 ( V_236 ) ;
return;
V_235:
F_11 ( V_4 ) ;
V_233:
F_136 ( & V_4 -> V_41 , & V_7 -> V_99 ) ;
F_138 ( V_4 ) ;
F_133 ( V_237 ) ;
}
STATIC int
V_138 (
struct V_238 * V_137 ,
struct V_239 * V_240 )
{
struct V_6 * V_7 =
F_139 ( V_137 , struct V_6 , V_136 ) ;
int V_241 = V_240 -> V_241 ;
F_124 ( V_171 ) ;
F_124 ( V_232 ) ;
struct V_3 * V_4 ;
int error ;
if ( ( V_240 -> V_242 & ( V_243 | V_244 ) ) != ( V_243 | V_244 ) )
return 0 ;
if ( ! V_241 )
goto V_192;
F_4 ( & V_7 -> V_40 ) ;
while ( ! F_22 ( & V_7 -> V_99 ) ) {
if ( V_241 -- <= 0 )
break;
V_4 = F_127 ( & V_7 -> V_99 , struct V_3 ,
V_41 ) ;
F_130 ( V_4 , & V_171 , & V_232 ) ;
}
F_6 ( & V_7 -> V_40 ) ;
error = F_126 ( & V_171 ) ;
if ( error )
F_15 ( NULL , L_11 , V_32 ) ;
while ( ! F_22 ( & V_232 ) ) {
V_4 = F_127 ( & V_232 , struct V_3 , V_41 ) ;
F_23 ( & V_4 -> V_41 ) ;
F_129 ( V_4 ) ;
}
V_192:
return ( V_7 -> V_42 / 100 ) * V_245 ;
}
int
F_41 (
T_3 * V_2 ,
T_9 V_44 )
{
T_10 * V_142 ;
int error ;
V_142 = F_84 ( V_2 , V_246 ) ;
error = F_85 ( V_142 , 0 , F_140 ( V_2 ) ,
0 , 0 , V_247 ) ;
if ( error ) {
F_88 ( V_142 , 0 ) ;
return error ;
}
F_92 ( V_142 , V_44 ) ;
error = F_93 ( V_142 , 0 ) ;
return error ;
}
int
F_141 (
struct V_80 * V_68 ,
T_21 V_248 ,
T_22 V_249 ,
T_23 V_250 ,
T_2 V_44 ,
struct V_3 * * V_251 ,
struct V_3 * * V_252 )
{
struct V_1 * V_2 = V_68 -> V_74 ;
struct V_3 * V_253 , * V_254 ;
int error ;
T_2 V_255 ;
if ( ! F_32 ( V_2 ) || ! F_55 ( V_2 ) )
return 0 ;
V_255 = V_73 ;
F_62 ( V_68 , V_255 ) ;
if ( ( V_44 & V_256 ) && F_142 ( V_68 ) )
V_249 = V_68 -> V_85 . V_89 ;
if ( F_56 ( V_2 , V_68 ) ) {
error = F_57 ( V_68 , V_87 ) ;
if ( error ) {
F_63 ( V_68 , V_255 ) ;
return error ;
}
}
V_253 = V_254 = NULL ;
if ( ( V_44 & V_45 ) && F_36 ( V_2 ) ) {
if ( V_68 -> V_85 . V_86 != V_248 ) {
F_63 ( V_68 , V_255 ) ;
if ( ( error = F_50 ( V_2 , NULL , ( T_5 ) V_248 ,
V_46 ,
V_87 |
V_75 ,
& V_253 ) ) ) {
ASSERT ( error != V_196 ) ;
return error ;
}
F_11 ( V_253 ) ;
V_255 = V_186 ;
F_62 ( V_68 , V_255 ) ;
} else {
ASSERT ( V_68 -> V_88 ) ;
V_253 = F_49 ( V_68 -> V_88 ) ;
}
}
if ( ( V_44 & V_47 ) && F_37 ( V_2 ) ) {
if ( V_68 -> V_85 . V_89 != V_249 ) {
F_63 ( V_68 , V_255 ) ;
if ( ( error = F_50 ( V_2 , NULL , ( T_5 ) V_249 ,
V_48 ,
V_87 |
V_75 ,
& V_254 ) ) ) {
if ( V_253 )
F_53 ( V_253 ) ;
ASSERT ( error != V_196 ) ;
return error ;
}
F_11 ( V_254 ) ;
V_255 = V_186 ;
F_62 ( V_68 , V_255 ) ;
} else {
ASSERT ( V_68 -> V_90 ) ;
V_254 = F_49 ( V_68 -> V_90 ) ;
}
} else if ( ( V_44 & V_49 ) && F_38 ( V_2 ) ) {
if ( F_59 ( V_68 ) != V_250 ) {
F_63 ( V_68 , V_255 ) ;
if ( ( error = F_50 ( V_2 , NULL , ( T_5 ) V_250 ,
V_50 ,
V_87 |
V_75 ,
& V_254 ) ) ) {
if ( V_253 )
F_53 ( V_253 ) ;
ASSERT ( error != V_196 ) ;
return ( error ) ;
}
F_11 ( V_254 ) ;
V_255 = V_186 ;
F_62 ( V_68 , V_255 ) ;
} else {
ASSERT ( V_68 -> V_90 ) ;
V_254 = F_49 ( V_68 -> V_90 ) ;
}
}
if ( V_253 )
F_143 ( V_68 ) ;
F_63 ( V_68 , V_255 ) ;
if ( V_251 )
* V_251 = V_253 ;
else if ( V_253 )
F_53 ( V_253 ) ;
if ( V_252 )
* V_252 = V_254 ;
else if ( V_254 )
F_53 ( V_254 ) ;
return 0 ;
}
T_6 *
F_144 (
T_10 * V_142 ,
T_4 * V_68 ,
T_6 * * V_257 ,
T_6 * V_258 )
{
T_6 * V_259 ;
T_2 V_260 = F_115 ( V_68 ) ?
V_261 : V_262 ;
ASSERT ( F_47 ( V_68 , V_73 ) ) ;
ASSERT ( F_32 ( V_68 -> V_74 ) ) ;
V_259 = * V_257 ;
ASSERT ( V_259 ) ;
ASSERT ( V_259 != V_258 ) ;
F_145 ( V_142 , V_259 , V_260 , - ( V_68 -> V_85 . V_182 ) ) ;
F_145 ( V_142 , V_259 , V_263 , - 1 ) ;
F_145 ( V_142 , V_258 , V_260 , V_68 -> V_85 . V_182 ) ;
F_145 ( V_142 , V_258 , V_263 , 1 ) ;
* V_257 = F_49 ( V_258 ) ;
return V_259 ;
}
int
F_146 (
T_10 * V_142 ,
T_4 * V_68 ,
T_6 * V_264 ,
T_6 * V_25 ,
T_2 V_44 )
{
T_3 * V_2 = V_68 -> V_74 ;
T_2 V_265 , V_266 , V_267 = 0 ;
T_6 * V_268 , * V_269 , * V_270 , * V_271 ;
int error ;
ASSERT ( F_47 ( V_68 , V_73 | V_186 ) ) ;
ASSERT ( F_32 ( V_2 ) ) ;
V_265 = V_68 -> V_217 ;
V_270 = V_271 = V_268 = V_269 = NULL ;
V_266 = F_115 ( V_68 ) ?
V_272 : V_273 ;
if ( F_36 ( V_2 ) && V_264 &&
V_68 -> V_85 . V_86 != ( T_21 ) F_7 ( V_264 -> V_20 . V_21 ) ) {
V_270 = V_264 ;
if ( V_265 ) {
ASSERT ( V_68 -> V_88 ) ;
V_268 = V_68 -> V_88 ;
}
}
if ( F_58 ( V_68 -> V_74 ) && V_25 ) {
if ( F_38 ( V_68 -> V_74 ) &&
F_59 ( V_68 ) != F_7 ( V_25 -> V_20 . V_21 ) )
V_267 = V_274 ;
if ( V_267 ||
( F_37 ( V_68 -> V_74 ) &&
V_68 -> V_85 . V_89 != F_7 ( V_25 -> V_20 . V_21 ) ) ) {
V_271 = V_25 ;
if ( V_265 ) {
ASSERT ( V_68 -> V_90 ) ;
V_269 = V_68 -> V_90 ;
}
}
}
if ( ( error = F_147 ( V_142 , V_68 -> V_74 ,
V_270 , V_271 , V_68 -> V_85 . V_182 , 1 ,
V_44 | V_266 | V_267 ) ) )
return ( error ) ;
if ( V_265 ) {
ASSERT ( V_270 || V_271 ) ;
ASSERT ( V_268 || V_269 ) ;
if ( ( error = F_147 ( NULL , V_68 -> V_74 ,
V_270 , V_271 , ( T_15 ) V_265 , 0 ,
V_44 | V_266 | V_267 ) ) )
return ( error ) ;
F_147 ( NULL , V_68 -> V_74 ,
V_268 , V_269 , - ( ( T_15 ) V_265 ) , 0 ,
V_266 ) ;
}
return ( 0 ) ;
}
int
F_148 (
struct V_80 * * V_275 )
{
struct V_1 * V_2 = V_275 [ 0 ] -> V_74 ;
int V_18 ;
if ( ! F_32 ( V_2 ) || ! F_55 ( V_2 ) )
return 0 ;
for ( V_18 = 0 ; ( V_18 < 4 && V_275 [ V_18 ] ) ; V_18 ++ ) {
struct V_80 * V_68 = V_275 [ V_18 ] ;
int error ;
if ( V_18 == 0 || V_68 != V_275 [ V_18 - 1 ] ) {
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
F_149 (
struct V_276 * V_142 ,
struct V_80 * V_68 ,
struct V_3 * V_264 ,
struct V_3 * V_25 )
{
struct V_1 * V_2 = V_142 -> V_277 ;
if ( ! F_32 ( V_2 ) || ! F_55 ( V_2 ) )
return;
ASSERT ( F_47 ( V_68 , V_73 ) ) ;
ASSERT ( F_32 ( V_2 ) ) ;
if ( V_264 ) {
ASSERT ( V_68 -> V_88 == NULL ) ;
ASSERT ( F_36 ( V_2 ) ) ;
ASSERT ( V_68 -> V_85 . V_86 == F_7 ( V_264 -> V_20 . V_21 ) ) ;
V_68 -> V_88 = F_49 ( V_264 ) ;
F_145 ( V_142 , V_264 , V_263 , 1 ) ;
}
if ( V_25 ) {
ASSERT ( V_68 -> V_90 == NULL ) ;
ASSERT ( F_58 ( V_2 ) ) ;
ASSERT ( ( F_37 ( V_2 ) ?
V_68 -> V_85 . V_89 : F_59 ( V_68 ) ) ==
F_7 ( V_25 -> V_20 . V_21 ) ) ;
V_68 -> V_90 = F_49 ( V_25 ) ;
F_145 ( V_142 , V_25 , V_263 , 1 ) ;
}
}
