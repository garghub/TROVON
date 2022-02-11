STATIC int
F_1 (
struct V_1 * V_2 ,
int type ,
int (* F_2)( struct V_3 * V_4 ) )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = F_3 ( V_6 , type ) ;
T_1 V_10 ;
int V_11 = 0 ;
int V_12 ;
int V_13 ;
V_14:
V_12 = 0 ;
V_10 = 0 ;
V_13 = 0 ;
while ( 1 ) {
struct V_3 * V_15 [ V_16 ] ;
int error = 0 ;
int V_17 ;
F_4 ( & V_6 -> V_18 ) ;
V_13 = F_5 ( V_9 , ( void * * ) V_15 ,
V_10 , V_16 ) ;
if ( ! V_13 ) {
F_6 ( & V_6 -> V_18 ) ;
break;
}
for ( V_17 = 0 ; V_17 < V_13 ; V_17 ++ ) {
struct V_3 * V_4 = V_15 [ V_17 ] ;
V_10 = F_7 ( V_4 -> V_19 . V_20 ) + 1 ;
error = F_2 ( V_15 [ V_17 ] ) ;
if ( error == V_21 ) {
V_12 ++ ;
continue;
}
if ( error && V_11 != V_22 )
V_11 = error ;
}
F_6 ( & V_6 -> V_18 ) ;
if ( V_11 == V_22 ) {
V_12 = 0 ;
break;
}
}
if ( V_12 ) {
F_8 ( 1 ) ;
goto V_14;
}
return V_11 ;
}
STATIC int
F_9 (
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_23 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_3 * V_24 = NULL ;
F_10 ( V_4 ) ;
if ( ( V_4 -> V_25 & V_26 ) || V_4 -> V_27 != 0 ) {
F_11 ( V_4 ) ;
return V_21 ;
}
V_24 = V_4 -> V_28 ;
if ( V_24 ) {
F_10 ( V_24 ) ;
V_4 -> V_28 = NULL ;
}
V_4 -> V_25 |= V_26 ;
if ( ! F_12 ( V_4 ) ) {
F_13 ( V_4 ) ;
}
if ( F_14 ( V_4 ) ) {
int error ;
error = F_15 ( V_4 , V_29 ) ;
if ( error )
F_16 ( V_2 , L_1 ,
V_30 , V_4 ) ;
F_17 ( V_4 ) ;
}
ASSERT ( F_18 ( & V_4 -> V_31 ) == 0 ) ;
ASSERT ( F_19 ( V_2 ) ||
! ( V_4 -> V_32 . V_33 . V_34 & V_35 ) ) ;
F_20 ( V_4 ) ;
F_11 ( V_4 ) ;
F_21 ( F_3 ( V_6 , V_4 -> V_19 . V_36 ) ,
F_7 ( V_4 -> V_19 . V_20 ) ) ;
V_6 -> V_37 -- ;
F_4 ( & V_6 -> V_38 ) ;
ASSERT ( ! F_22 ( & V_4 -> V_39 ) ) ;
F_23 ( & V_4 -> V_39 ) ;
V_6 -> V_40 -- ;
F_24 ( V_41 ) ;
F_6 ( & V_6 -> V_38 ) ;
F_25 ( V_4 ) ;
if ( V_24 )
F_26 ( V_24 ) ;
return 0 ;
}
void
F_27 (
struct V_1 * V_2 ,
T_2 V_42 )
{
if ( V_42 & V_43 )
F_1 ( V_2 , V_44 , F_9 ) ;
if ( V_42 & V_45 )
F_1 ( V_2 , V_46 , F_9 ) ;
if ( V_42 & V_47 )
F_1 ( V_2 , V_48 , F_9 ) ;
}
void
F_28 (
struct V_1 * V_2 )
{
if ( V_2 -> V_7 ) {
F_27 ( V_2 , V_49 ) ;
F_29 ( V_2 ) ;
}
}
void
F_30 (
T_3 * V_2 )
{
int error = 0 ;
T_2 V_50 ;
if ( V_2 -> V_51 . V_52 ) {
F_31 ( V_2 , L_2 ) ;
V_2 -> V_53 = 0 ;
goto V_54;
}
ASSERT ( F_32 ( V_2 ) ) ;
error = F_33 ( V_2 ) ;
if ( error ) {
ASSERT ( V_2 -> V_7 == NULL ) ;
V_2 -> V_53 = 0 ;
goto V_54;
}
if ( F_34 ( V_2 ) ) {
error = F_35 ( V_2 ) ;
if ( error ) {
return;
}
}
if ( ! F_36 ( V_2 ) )
V_2 -> V_53 &= ~ V_55 ;
if ( ! ( F_37 ( V_2 ) || F_38 ( V_2 ) ) )
V_2 -> V_53 &= ~ V_56 ;
V_54:
F_39 ( & V_2 -> V_57 ) ;
V_50 = V_2 -> V_51 . V_58 ;
V_2 -> V_51 . V_58 = V_2 -> V_53 & V_59 ;
F_40 ( & V_2 -> V_57 ) ;
if ( V_50 != ( V_2 -> V_53 & V_59 ) ) {
if ( F_41 ( V_2 , V_60 ) ) {
ASSERT ( ! ( F_32 ( V_2 ) ) ) ;
F_42 ( V_2 , L_3 ,
V_30 ) ;
}
}
if ( error ) {
F_16 ( V_2 , L_4 ) ;
return;
}
}
void
F_43 (
T_3 * V_2 )
{
ASSERT ( V_2 -> V_61 ) ;
F_44 ( V_2 -> V_61 ) ;
if ( V_2 -> V_62 )
F_44 ( V_2 -> V_62 ) ;
if ( V_2 -> V_63 )
F_44 ( V_2 -> V_63 ) ;
if ( V_2 -> V_7 ) {
if ( V_2 -> V_7 -> V_64 ) {
F_45 ( V_2 -> V_7 -> V_64 ) ;
V_2 -> V_7 -> V_64 = NULL ;
}
if ( V_2 -> V_7 -> V_65 ) {
F_45 ( V_2 -> V_7 -> V_65 ) ;
V_2 -> V_7 -> V_65 = NULL ;
}
}
}
STATIC int
F_46 (
T_4 * V_66 ,
T_5 V_67 ,
T_2 type ,
T_2 V_68 ,
T_6 * V_69 ,
T_6 * * V_70 )
{
T_6 * V_4 ;
int error ;
ASSERT ( F_47 ( V_66 , V_71 ) ) ;
error = 0 ;
V_4 = * V_70 ;
if ( V_4 ) {
F_48 ( V_4 ) ;
return 0 ;
}
if ( V_69 ) {
ASSERT ( type == V_46 || type == V_48 ) ;
F_10 ( V_69 ) ;
V_4 = V_69 -> V_28 ;
if ( V_4 && F_7 ( V_4 -> V_19 . V_20 ) == V_67 ) {
ASSERT ( * V_70 == NULL ) ;
* V_70 = F_49 ( V_4 ) ;
F_11 ( V_69 ) ;
return 0 ;
}
F_11 ( V_69 ) ;
}
error = F_50 ( V_66 -> V_72 , V_66 , V_67 , type ,
V_68 | V_73 , & V_4 ) ;
if ( error )
return error ;
F_51 ( V_4 ) ;
* V_70 = V_4 ;
F_11 ( V_4 ) ;
return 0 ;
}
STATIC void
F_52 (
T_6 * V_74 ,
T_6 * V_75 )
{
T_6 * V_76 ;
F_10 ( V_74 ) ;
V_76 = V_74 -> V_28 ;
if ( V_76 ) {
if ( V_76 == V_75 )
goto V_77;
V_74 -> V_28 = NULL ;
F_53 ( V_76 ) ;
}
V_74 -> V_28 = F_49 ( V_75 ) ;
V_77:
F_11 ( V_74 ) ;
}
int
F_54 (
T_4 * V_66 ,
T_2 V_42 )
{
T_3 * V_2 = V_66 -> V_72 ;
T_2 V_78 = 0 ;
int error = 0 ;
if ( ! F_32 ( V_2 ) ||
! F_55 ( V_2 ) ||
! F_56 ( V_2 , V_66 ) ||
V_66 -> V_79 == V_2 -> V_51 . V_80 ||
V_66 -> V_79 == V_2 -> V_51 . V_81 )
return 0 ;
ASSERT ( F_47 ( V_66 , V_71 ) ) ;
if ( F_36 ( V_2 ) ) {
error = F_46 ( V_66 , V_66 -> V_82 . V_83 , V_44 ,
V_42 & V_84 ,
NULL , & V_66 -> V_85 ) ;
if ( error )
goto V_77;
V_78 ++ ;
}
ASSERT ( F_47 ( V_66 , V_71 ) ) ;
if ( F_57 ( V_2 ) ) {
error = F_37 ( V_2 ) ?
F_46 ( V_66 , V_66 -> V_82 . V_86 , V_46 ,
V_42 & V_84 ,
V_66 -> V_85 , & V_66 -> V_87 ) :
F_46 ( V_66 , F_58 ( V_66 ) , V_48 ,
V_42 & V_84 ,
V_66 -> V_85 , & V_66 -> V_87 ) ;
if ( error )
goto V_77;
V_78 ++ ;
}
if ( V_78 == 2 ) {
ASSERT ( F_47 ( V_66 , V_71 ) ) ;
ASSERT ( V_66 -> V_85 ) ;
ASSERT ( V_66 -> V_87 ) ;
if ( V_66 -> V_85 -> V_28 != V_66 -> V_87 )
F_52 ( V_66 -> V_85 , V_66 -> V_87 ) ;
}
V_77:
#ifdef F_59
if ( ! error ) {
if ( F_36 ( V_2 ) )
ASSERT ( V_66 -> V_85 ) ;
if ( F_57 ( V_2 ) )
ASSERT ( V_66 -> V_87 ) ;
}
ASSERT ( F_47 ( V_66 , V_71 ) ) ;
#endif
return error ;
}
int
F_60 (
struct V_88 * V_66 ,
T_2 V_42 )
{
int error ;
F_61 ( V_66 , V_71 ) ;
error = F_54 ( V_66 , V_42 ) ;
F_62 ( V_66 , V_71 ) ;
return error ;
}
void
F_44 (
T_4 * V_66 )
{
if ( ! ( V_66 -> V_85 || V_66 -> V_87 ) )
return;
F_63 ( V_66 ) ;
ASSERT ( V_66 -> V_79 != V_66 -> V_72 -> V_51 . V_80 ) ;
ASSERT ( V_66 -> V_79 != V_66 -> V_72 -> V_51 . V_81 ) ;
if ( V_66 -> V_85 ) {
F_53 ( V_66 -> V_85 ) ;
V_66 -> V_85 = NULL ;
}
if ( V_66 -> V_87 ) {
F_53 ( V_66 -> V_87 ) ;
V_66 -> V_87 = NULL ;
}
}
STATIC int
F_33 (
T_3 * V_2 )
{
T_7 * V_89 ;
int error ;
T_6 * V_4 ;
ASSERT ( F_32 ( V_2 ) ) ;
V_89 = V_2 -> V_7 = F_64 ( sizeof( T_7 ) , V_90 ) ;
if ( ( error = F_65 ( V_2 ) ) ) {
F_66 ( V_89 ) ;
V_2 -> V_7 = NULL ;
return error ;
}
F_67 ( & V_89 -> V_91 , V_92 ) ;
F_67 ( & V_89 -> V_93 , V_92 ) ;
F_68 ( & V_89 -> V_18 ) ;
F_69 ( & V_89 -> V_94 ) ;
V_89 -> V_40 = 0 ;
F_68 ( & V_89 -> V_38 ) ;
F_68 ( & V_89 -> V_95 ) ;
V_89 -> V_96 = F_70 ( V_2 , V_97 ) ;
ASSERT ( V_89 -> V_96 ) ;
V_89 -> V_98 = F_71 ( V_89 -> V_96 ) ;
F_72 ( V_89 -> V_98 , sizeof( V_99 ) ) ;
V_2 -> V_53 |= ( V_2 -> V_51 . V_58 & V_100 ) ;
error = F_73 ( V_2 , 0 ,
F_74 ( V_2 ) ? V_44 :
( F_75 ( V_2 ) ? V_46 :
V_48 ) ,
V_73 , & V_4 ) ;
if ( ! error ) {
T_8 * V_101 = & V_4 -> V_19 ;
V_89 -> V_102 = V_101 -> V_103 ?
F_7 ( V_101 -> V_103 ) : V_104 ;
V_89 -> V_105 = V_101 -> V_106 ?
F_7 ( V_101 -> V_106 ) : V_107 ;
V_89 -> V_108 = V_101 -> V_109 ?
F_7 ( V_101 -> V_109 ) : V_110 ;
V_89 -> V_111 = V_101 -> V_112 ?
F_76 ( V_101 -> V_112 ) : V_113 ;
V_89 -> V_114 = V_101 -> V_115 ?
F_76 ( V_101 -> V_115 ) : V_116 ;
V_89 -> V_117 = V_101 -> V_118 ?
F_76 ( V_101 -> V_118 ) : V_119 ;
V_89 -> V_120 = F_77 ( V_101 -> V_121 ) ;
V_89 -> V_122 = F_77 ( V_101 -> V_123 ) ;
V_89 -> V_124 = F_77 ( V_101 -> V_125 ) ;
V_89 -> V_126 = F_77 ( V_101 -> V_127 ) ;
V_89 -> V_128 = F_77 ( V_101 -> V_129 ) ;
V_89 -> V_130 = F_77 ( V_101 -> V_131 ) ;
F_25 ( V_4 ) ;
} else {
V_89 -> V_102 = V_104 ;
V_89 -> V_105 = V_107 ;
V_89 -> V_108 = V_110 ;
V_89 -> V_111 = V_113 ;
V_89 -> V_114 = V_116 ;
V_89 -> V_117 = V_119 ;
}
V_89 -> V_132 . V_133 = V_134 ;
V_89 -> V_132 . V_135 = V_136 ;
F_78 ( & V_89 -> V_132 ) ;
return 0 ;
}
void
F_29 (
T_3 * V_2 )
{
T_7 * V_6 ;
V_6 = V_2 -> V_7 ;
ASSERT ( V_6 != NULL ) ;
F_79 ( & V_6 -> V_132 ) ;
if ( V_6 -> V_64 ) {
F_45 ( V_6 -> V_64 ) ;
V_6 -> V_64 = NULL ;
}
if ( V_6 -> V_65 ) {
F_45 ( V_6 -> V_65 ) ;
V_6 -> V_65 = NULL ;
}
F_80 ( & V_6 -> V_95 ) ;
F_66 ( V_6 ) ;
V_2 -> V_7 = NULL ;
}
STATIC int
F_81 (
T_3 * V_2 ,
T_4 * * V_66 ,
T_9 V_137 ,
T_2 V_42 )
{
T_10 * V_138 ;
int error ;
int V_139 ;
V_138 = F_82 ( V_2 , V_140 ) ;
if ( ( error = F_83 ( V_138 ,
F_84 ( V_2 ) ,
F_85 ( V_2 ) , 0 ,
V_141 ,
V_142 ) ) ) {
F_86 ( V_138 , 0 ) ;
return error ;
}
error = F_87 ( & V_138 , NULL , V_143 , 1 , 0 , 0 , 1 , V_66 , & V_139 ) ;
if ( error ) {
F_86 ( V_138 , V_144 |
V_145 ) ;
return error ;
}
F_39 ( & V_2 -> V_57 ) ;
if ( V_42 & V_146 ) {
ASSERT ( ! F_88 ( & V_2 -> V_51 ) ) ;
ASSERT ( ( V_137 & ( V_147 | V_148 |
V_149 | V_60 ) ) ==
( V_147 | V_148 |
V_149 | V_60 ) ) ;
F_89 ( & V_2 -> V_51 ) ;
V_2 -> V_51 . V_80 = V_150 ;
V_2 -> V_51 . V_81 = V_150 ;
V_2 -> V_51 . V_58 = 0 ;
}
if ( V_42 & V_43 )
V_2 -> V_51 . V_80 = ( * V_66 ) -> V_79 ;
else
V_2 -> V_51 . V_81 = ( * V_66 ) -> V_79 ;
F_40 ( & V_2 -> V_57 ) ;
F_90 ( V_138 , V_137 ) ;
if ( ( error = F_91 ( V_138 , V_144 ) ) ) {
F_42 ( V_2 , L_5 , V_30 , error ) ;
return error ;
}
return 0 ;
}
STATIC void
F_92 (
T_3 * V_2 ,
T_11 * V_151 ,
T_5 V_67 ,
T_2 type )
{
T_8 * V_152 ;
int V_153 ;
F_93 ( V_151 , V_154 ) ;
#ifdef F_59
V_153 = F_94 ( V_2 , V_97 ) ;
F_72 ( V_153 , sizeof( V_99 ) ) ;
ASSERT ( V_2 -> V_7 -> V_98 == V_153 ) ;
#endif
V_152 = V_151 -> V_155 ;
for ( V_153 = 0 ; V_153 < V_2 -> V_7 -> V_98 ; V_153 ++ ) {
( void ) F_95 ( V_2 , V_152 , V_67 + V_153 , type , V_156 ,
L_6 ) ;
V_152 -> V_157 = 0 ;
V_152 -> V_158 = 0 ;
V_152 -> V_159 = 0 ;
V_152 -> V_103 = 0 ;
V_152 -> V_106 = 0 ;
V_152 -> V_109 = 0 ;
V_152 -> V_112 = 0 ;
V_152 -> V_115 = 0 ;
V_152 -> V_118 = 0 ;
V_152 = ( T_8 * ) ( ( V_99 * ) V_152 + 1 ) ;
}
}
STATIC int
F_96 (
T_3 * V_2 ,
T_5 V_160 ,
T_12 V_161 ,
T_13 V_162 ,
T_2 V_42 )
{
T_11 * V_151 ;
int error ;
int type ;
ASSERT ( V_162 > 0 ) ;
type = V_42 & V_43 ? V_44 :
( V_42 & V_47 ? V_48 : V_46 ) ;
error = 0 ;
while ( V_162 -- ) {
error = F_97 ( V_2 , NULL , V_2 -> V_163 ,
F_98 ( V_2 , V_161 ) ,
V_2 -> V_7 -> V_96 , 0 , & V_151 ) ;
if ( error )
break;
F_92 ( V_2 , V_151 , V_160 , type ) ;
F_99 ( V_151 ) ;
F_100 ( V_151 ) ;
V_161 ++ ;
V_160 += V_2 -> V_7 -> V_98 ;
}
return error ;
}
STATIC int
F_101 (
T_3 * V_2 ,
T_4 * V_164 ,
T_2 V_42 )
{
T_14 * V_165 ;
int V_17 , V_166 ;
int error ;
T_15 V_167 ;
T_13 V_168 ;
T_5 V_160 ;
T_12 V_169 ;
T_13 V_170 ;
error = 0 ;
if ( V_164 -> V_82 . V_171 == 0 )
return 0 ;
V_165 = F_102 ( V_172 * sizeof( * V_165 ) , V_90 ) ;
V_167 = 0 ;
V_168 = F_103 ( V_2 , ( V_173 ) F_104 ( V_2 ) ) ;
do {
V_166 = V_172 ;
F_61 ( V_164 , V_174 ) ;
error = F_105 ( V_164 , V_167 , V_168 - V_167 ,
V_165 , & V_166 , 0 ) ;
F_62 ( V_164 , V_174 ) ;
if ( error )
break;
ASSERT ( V_166 <= V_172 ) ;
for ( V_17 = 0 ; V_17 < V_166 ; V_17 ++ ) {
ASSERT ( V_165 [ V_17 ] . V_175 != V_176 ) ;
ASSERT ( V_165 [ V_17 ] . V_177 ) ;
V_167 += V_165 [ V_17 ] . V_177 ;
if ( V_165 [ V_17 ] . V_175 == V_178 )
continue;
V_160 = ( T_5 ) V_165 [ V_17 ] . V_179 *
V_2 -> V_7 -> V_98 ;
if ( ( V_17 + 1 < V_166 ) &&
( V_165 [ V_17 + 1 ] . V_175 != V_178 ) ) {
V_170 = V_165 [ V_17 + 1 ] . V_177 ;
V_169 = V_165 [ V_17 + 1 ] . V_175 ;
while ( V_170 -- ) {
F_106 ( V_2 -> V_163 ,
F_98 ( V_2 , V_169 ) ,
V_2 -> V_7 -> V_96 ) ;
V_169 ++ ;
}
}
if ( ( error = F_96 ( V_2 ,
V_160 ,
V_165 [ V_17 ] . V_175 ,
V_165 [ V_17 ] . V_177 ,
V_42 ) ) ) {
break;
}
}
if ( error )
break;
} while ( V_166 > 0 );
F_66 ( V_165 ) ;
return error ;
}
STATIC int
F_107 (
struct V_88 * V_66 ,
T_5 V_67 ,
T_2 type ,
T_16 V_180 ,
T_16 V_181 )
{
struct V_1 * V_2 = V_66 -> V_72 ;
struct V_3 * V_4 ;
int error ;
error = F_50 ( V_2 , V_66 , V_67 , type ,
V_84 | V_73 , & V_4 ) ;
if ( error ) {
ASSERT ( error != V_182 ) ;
ASSERT ( error != V_183 ) ;
return error ;
}
F_108 ( V_4 ) ;
F_109 ( & V_4 -> V_19 . V_158 , 1 ) ;
V_4 -> V_184 ++ ;
if ( V_180 ) {
F_109 ( & V_4 -> V_19 . V_157 , V_180 ) ;
V_4 -> V_185 += V_180 ;
}
if ( V_181 ) {
F_109 ( & V_4 -> V_19 . V_159 , V_181 ) ;
V_4 -> V_186 += V_181 ;
}
if ( V_4 -> V_19 . V_20 ) {
F_110 ( V_2 , & V_4 -> V_19 ) ;
F_111 ( V_2 , & V_4 -> V_19 ) ;
}
V_4 -> V_25 |= V_187 ;
F_26 ( V_4 ) ;
return 0 ;
}
STATIC int
F_112 (
T_4 * V_66 ,
T_16 * V_188 )
{
T_13 V_181 ;
T_17 V_189 ;
T_18 * V_190 ;
T_17 V_191 ;
int error ;
ASSERT ( F_113 ( V_66 ) ) ;
V_190 = F_114 ( V_66 , V_192 ) ;
if ( ! ( V_190 -> V_193 & V_194 ) ) {
if ( ( error = F_115 ( NULL , V_66 , V_192 ) ) )
return error ;
}
V_181 = 0 ;
V_191 = V_190 -> V_195 / ( T_2 ) sizeof( V_196 ) ;
for ( V_189 = 0 ; V_189 < V_191 ; V_189 ++ )
V_181 += F_116 ( F_117 ( V_190 , V_189 ) ) ;
* V_188 = ( T_16 ) V_181 ;
return 0 ;
}
STATIC int
F_118 (
T_3 * V_2 ,
T_19 V_197 ,
void T_20 * V_198 ,
int V_199 ,
int * V_200 ,
int * V_201 )
{
T_4 * V_66 ;
T_16 V_180 , V_181 = 0 ;
int error ;
ASSERT ( F_32 ( V_2 ) ) ;
if ( V_197 == V_2 -> V_51 . V_80 || V_197 == V_2 -> V_51 . V_81 ) {
* V_201 = V_202 ;
return F_119 ( V_203 ) ;
}
error = F_120 ( V_2 , NULL , V_197 , 0 , V_71 , & V_66 ) ;
if ( error ) {
* V_201 = V_202 ;
return error ;
}
ASSERT ( V_66 -> V_204 == 0 ) ;
if ( F_113 ( V_66 ) ) {
error = F_112 ( V_66 , & V_181 ) ;
if ( error )
goto V_205;
}
V_180 = ( T_16 ) V_66 -> V_82 . V_171 - V_181 ;
if ( F_36 ( V_2 ) ) {
error = F_107 ( V_66 , V_66 -> V_82 . V_83 ,
V_44 , V_180 , V_181 ) ;
if ( error )
goto V_205;
}
if ( F_37 ( V_2 ) ) {
error = F_107 ( V_66 , V_66 -> V_82 . V_86 ,
V_46 , V_180 , V_181 ) ;
if ( error )
goto V_205;
}
if ( F_38 ( V_2 ) ) {
error = F_107 ( V_66 , F_58 ( V_66 ) ,
V_48 , V_180 , V_181 ) ;
if ( error )
goto V_205;
}
F_62 ( V_66 , V_71 ) ;
F_45 ( V_66 ) ;
* V_201 = V_206 ;
return 0 ;
V_205:
F_62 ( V_66 , V_71 ) ;
F_45 ( V_66 ) ;
* V_201 = V_207 ;
return error ;
}
STATIC int
F_121 (
struct V_3 * V_4 )
{
int error = 0 ;
F_10 ( V_4 ) ;
if ( V_4 -> V_25 & V_26 )
goto V_208;
if ( ! F_14 ( V_4 ) )
goto V_208;
if ( ! F_12 ( V_4 ) )
F_13 ( V_4 ) ;
error = F_15 ( V_4 , 0 ) ;
V_208:
F_11 ( V_4 ) ;
return error ;
}
int
F_35 (
T_3 * V_2 )
{
int V_77 , V_209 , error , V_210 ;
T_19 V_211 ;
T_21 V_212 ;
T_4 * V_213 , * V_214 ;
T_2 V_42 ;
V_209 = V_215 ;
V_212 = 1 ;
V_211 = 0 ;
V_42 = 0 ;
ASSERT ( V_2 -> V_7 -> V_64 || V_2 -> V_7 -> V_65 ) ;
ASSERT ( F_32 ( V_2 ) ) ;
F_31 ( V_2 , L_7 ) ;
V_213 = V_2 -> V_7 -> V_64 ;
if ( V_213 ) {
error = F_101 ( V_2 , V_213 , V_43 ) ;
if ( error )
goto V_216;
V_42 |= V_55 ;
}
V_214 = V_2 -> V_7 -> V_65 ;
if ( V_214 ) {
error = F_101 ( V_2 , V_214 , F_37 ( V_2 ) ?
V_45 : V_47 ) ;
if ( error )
goto V_216;
V_42 |= V_56 ;
}
do {
error = F_122 ( V_2 , & V_211 , & V_209 ,
F_118 ,
V_212 , NULL , & V_77 ) ;
if ( error )
break;
} while ( ! V_77 );
if ( F_36 ( V_2 ) )
error = F_1 ( V_2 , V_44 , F_121 ) ;
if ( F_37 ( V_2 ) ) {
V_210 = F_1 ( V_2 , V_46 , F_121 ) ;
if ( ! error )
error = V_210 ;
}
if ( F_38 ( V_2 ) ) {
V_210 = F_1 ( V_2 , V_48 , F_121 ) ;
if ( ! error )
error = V_210 ;
}
if ( error ) {
F_27 ( V_2 , V_49 ) ;
goto V_216;
}
F_123 ( V_2 -> V_163 , 1 ) ;
V_2 -> V_53 &= ~ V_100 ;
V_2 -> V_53 |= V_42 ;
V_216:
if ( error ) {
F_16 ( V_2 ,
L_8 ,
error ) ;
ASSERT ( V_2 -> V_7 != NULL ) ;
F_29 ( V_2 ) ;
if ( F_124 ( V_2 ) ) {
F_16 ( V_2 ,
L_9 ) ;
}
} else
F_31 ( V_2 , L_10 ) ;
return ( error ) ;
}
STATIC int
F_65 (
T_3 * V_2 )
{
T_4 * V_213 , * V_214 ;
int error ;
T_9 V_217 ;
T_2 V_42 ;
ASSERT ( V_2 -> V_7 ) ;
V_213 = V_214 = NULL ;
V_217 = 0 ;
V_42 = 0 ;
if ( F_88 ( & V_2 -> V_51 ) ) {
if ( F_36 ( V_2 ) &&
V_2 -> V_51 . V_80 != V_150 ) {
ASSERT ( V_2 -> V_51 . V_80 > 0 ) ;
if ( ( error = F_120 ( V_2 , NULL , V_2 -> V_51 . V_80 ,
0 , 0 , & V_213 ) ) )
return F_119 ( error ) ;
}
if ( F_57 ( V_2 ) &&
V_2 -> V_51 . V_81 != V_150 ) {
ASSERT ( V_2 -> V_51 . V_81 > 0 ) ;
if ( ( error = F_120 ( V_2 , NULL , V_2 -> V_51 . V_81 ,
0 , 0 , & V_214 ) ) ) {
if ( V_213 )
F_45 ( V_213 ) ;
return F_119 ( error ) ;
}
}
} else {
V_42 |= V_146 ;
V_217 |= ( V_147 | V_148 |
V_149 | V_60 ) ;
}
if ( F_36 ( V_2 ) && V_213 == NULL ) {
if ( ( error = F_81 ( V_2 , & V_213 ,
V_217 | V_148 ,
V_42 | V_43 ) ) )
return F_119 ( error ) ;
V_42 &= ~ V_146 ;
}
if ( F_57 ( V_2 ) && V_214 == NULL ) {
V_42 |= ( F_37 ( V_2 ) ?
V_45 : V_47 ) ;
error = F_81 ( V_2 , & V_214 ,
V_217 | V_149 , V_42 ) ;
if ( error ) {
if ( V_213 )
F_45 ( V_213 ) ;
return F_119 ( error ) ;
}
}
V_2 -> V_7 -> V_64 = V_213 ;
V_2 -> V_7 -> V_65 = V_214 ;
return 0 ;
}
STATIC void
F_125 (
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_23 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_4 ( & V_6 -> V_18 ) ;
F_21 ( F_3 ( V_6 , V_4 -> V_19 . V_36 ) ,
F_7 ( V_4 -> V_19 . V_20 ) ) ;
V_6 -> V_37 -- ;
F_6 ( & V_6 -> V_18 ) ;
F_25 ( V_4 ) ;
}
STATIC void
F_126 (
struct V_3 * V_4 ,
struct V_218 * V_219 )
{
struct V_1 * V_2 = V_4 -> V_23 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int error ;
if ( ! F_127 ( V_4 ) )
goto V_220;
if ( V_4 -> V_27 ) {
F_11 ( V_4 ) ;
F_128 ( V_4 ) ;
F_129 ( V_221 ) ;
F_23 ( & V_4 -> V_39 ) ;
V_6 -> V_40 -- ;
F_24 ( V_41 ) ;
return;
}
if ( ! F_12 ( V_4 ) )
goto V_220;
if ( F_14 ( V_4 ) ) {
F_130 ( V_4 ) ;
error = F_15 ( V_4 , 0 ) ;
if ( error ) {
F_16 ( V_2 , L_1 ,
V_30 , V_4 ) ;
}
goto V_220;
}
F_20 ( V_4 ) ;
V_4 -> V_25 |= V_26 ;
F_11 ( V_4 ) ;
ASSERT ( V_4 -> V_27 == 0 ) ;
F_131 ( & V_4 -> V_39 , V_219 ) ;
V_6 -> V_40 -- ;
F_24 ( V_41 ) ;
F_132 ( V_4 ) ;
F_129 ( V_222 ) ;
return;
V_220:
F_11 ( V_4 ) ;
F_131 ( & V_4 -> V_39 , & V_6 -> V_94 ) ;
F_133 ( V_4 ) ;
F_129 ( V_223 ) ;
}
STATIC int
V_134 (
struct V_224 * V_133 ,
struct V_225 * V_226 )
{
struct V_5 * V_6 =
F_134 ( V_133 , struct V_5 , V_132 ) ;
int V_227 = V_226 -> V_227 ;
F_135 ( V_219 ) ;
struct V_3 * V_4 ;
if ( ( V_226 -> V_228 & ( V_229 | V_230 ) ) != ( V_229 | V_230 ) )
return 0 ;
if ( ! V_227 )
goto V_231;
F_4 ( & V_6 -> V_38 ) ;
while ( ! F_22 ( & V_6 -> V_94 ) ) {
if ( V_227 -- <= 0 )
break;
V_4 = F_136 ( & V_6 -> V_94 , struct V_3 ,
V_39 ) ;
F_126 ( V_4 , & V_219 ) ;
}
F_6 ( & V_6 -> V_38 ) ;
while ( ! F_22 ( & V_219 ) ) {
V_4 = F_136 ( & V_219 , struct V_3 , V_39 ) ;
F_23 ( & V_4 -> V_39 ) ;
F_125 ( V_4 ) ;
}
V_231:
return ( V_6 -> V_40 / 100 ) * V_232 ;
}
int
F_41 (
T_3 * V_2 ,
T_9 V_42 )
{
T_10 * V_138 ;
int error ;
V_138 = F_82 ( V_2 , V_233 ) ;
if ( ( error = F_83 ( V_138 , 0 ,
V_2 -> V_51 . V_234 + 128 , 0 ,
0 ,
V_235 ) ) ) {
F_86 ( V_138 , 0 ) ;
return error ;
}
F_90 ( V_138 , V_42 ) ;
error = F_91 ( V_138 , 0 ) ;
return error ;
}
int
F_137 (
struct V_88 * V_66 ,
T_22 V_236 ,
T_23 V_237 ,
T_24 V_238 ,
T_2 V_42 ,
struct V_3 * * V_239 ,
struct V_3 * * V_240 )
{
struct V_1 * V_2 = V_66 -> V_72 ;
struct V_3 * V_241 , * V_242 ;
int error ;
T_2 V_243 ;
if ( ! F_32 ( V_2 ) || ! F_55 ( V_2 ) )
return 0 ;
V_243 = V_71 ;
F_61 ( V_66 , V_243 ) ;
if ( ( V_42 & V_244 ) && F_138 ( V_66 ) )
V_237 = V_66 -> V_82 . V_86 ;
if ( F_56 ( V_2 , V_66 ) ) {
error = F_54 ( V_66 , V_84 ) ;
if ( error ) {
F_62 ( V_66 , V_243 ) ;
return error ;
}
}
V_241 = V_242 = NULL ;
if ( ( V_42 & V_43 ) && F_36 ( V_2 ) ) {
if ( V_66 -> V_82 . V_83 != V_236 ) {
F_62 ( V_66 , V_243 ) ;
if ( ( error = F_50 ( V_2 , NULL , ( T_5 ) V_236 ,
V_44 ,
V_84 |
V_73 ,
& V_241 ) ) ) {
ASSERT ( error != V_183 ) ;
return error ;
}
F_11 ( V_241 ) ;
V_243 = V_174 ;
F_61 ( V_66 , V_243 ) ;
} else {
ASSERT ( V_66 -> V_85 ) ;
V_241 = F_49 ( V_66 -> V_85 ) ;
}
}
if ( ( V_42 & V_45 ) && F_37 ( V_2 ) ) {
if ( V_66 -> V_82 . V_86 != V_237 ) {
F_62 ( V_66 , V_243 ) ;
if ( ( error = F_50 ( V_2 , NULL , ( T_5 ) V_237 ,
V_46 ,
V_84 |
V_73 ,
& V_242 ) ) ) {
if ( V_241 )
F_53 ( V_241 ) ;
ASSERT ( error != V_183 ) ;
return error ;
}
F_11 ( V_242 ) ;
V_243 = V_174 ;
F_61 ( V_66 , V_243 ) ;
} else {
ASSERT ( V_66 -> V_87 ) ;
V_242 = F_49 ( V_66 -> V_87 ) ;
}
} else if ( ( V_42 & V_47 ) && F_38 ( V_2 ) ) {
if ( F_58 ( V_66 ) != V_238 ) {
F_62 ( V_66 , V_243 ) ;
if ( ( error = F_50 ( V_2 , NULL , ( T_5 ) V_238 ,
V_48 ,
V_84 |
V_73 ,
& V_242 ) ) ) {
if ( V_241 )
F_53 ( V_241 ) ;
ASSERT ( error != V_183 ) ;
return ( error ) ;
}
F_11 ( V_242 ) ;
V_243 = V_174 ;
F_61 ( V_66 , V_243 ) ;
} else {
ASSERT ( V_66 -> V_87 ) ;
V_242 = F_49 ( V_66 -> V_87 ) ;
}
}
if ( V_241 )
F_139 ( V_66 ) ;
F_62 ( V_66 , V_243 ) ;
if ( V_239 )
* V_239 = V_241 ;
else if ( V_241 )
F_53 ( V_241 ) ;
if ( V_240 )
* V_240 = V_242 ;
else if ( V_242 )
F_53 ( V_242 ) ;
return 0 ;
}
T_6 *
F_140 (
T_10 * V_138 ,
T_4 * V_66 ,
T_6 * * V_245 ,
T_6 * V_246 )
{
T_6 * V_247 ;
T_2 V_248 = F_113 ( V_66 ) ?
V_249 : V_250 ;
ASSERT ( F_47 ( V_66 , V_71 ) ) ;
ASSERT ( F_32 ( V_66 -> V_72 ) ) ;
V_247 = * V_245 ;
ASSERT ( V_247 ) ;
ASSERT ( V_247 != V_246 ) ;
F_141 ( V_138 , V_247 , V_248 , - ( V_66 -> V_82 . V_171 ) ) ;
F_141 ( V_138 , V_247 , V_251 , - 1 ) ;
F_141 ( V_138 , V_246 , V_248 , V_66 -> V_82 . V_171 ) ;
F_141 ( V_138 , V_246 , V_251 , 1 ) ;
* V_245 = F_49 ( V_246 ) ;
return V_247 ;
}
int
F_142 (
T_10 * V_138 ,
T_4 * V_66 ,
T_6 * V_252 ,
T_6 * V_24 ,
T_2 V_42 )
{
T_3 * V_2 = V_66 -> V_72 ;
T_2 V_253 , V_254 , V_255 = 0 ;
T_6 * V_256 , * V_257 , * V_258 , * V_259 ;
int error ;
ASSERT ( F_47 ( V_66 , V_71 | V_174 ) ) ;
ASSERT ( F_32 ( V_2 ) ) ;
V_253 = V_66 -> V_204 ;
V_258 = V_259 = V_256 = V_257 = NULL ;
V_254 = F_113 ( V_66 ) ?
V_260 : V_261 ;
if ( F_36 ( V_2 ) && V_252 &&
V_66 -> V_82 . V_83 != ( T_22 ) F_7 ( V_252 -> V_19 . V_20 ) ) {
V_258 = V_252 ;
if ( V_253 ) {
ASSERT ( V_66 -> V_85 ) ;
V_256 = V_66 -> V_85 ;
}
}
if ( F_57 ( V_66 -> V_72 ) && V_24 ) {
if ( F_38 ( V_66 -> V_72 ) &&
F_58 ( V_66 ) != F_7 ( V_24 -> V_19 . V_20 ) )
V_255 = V_262 ;
if ( V_255 ||
( F_37 ( V_66 -> V_72 ) &&
V_66 -> V_82 . V_86 != F_7 ( V_24 -> V_19 . V_20 ) ) ) {
V_259 = V_24 ;
if ( V_253 ) {
ASSERT ( V_66 -> V_87 ) ;
V_257 = V_66 -> V_87 ;
}
}
}
if ( ( error = F_143 ( V_138 , V_66 -> V_72 ,
V_258 , V_259 , V_66 -> V_82 . V_171 , 1 ,
V_42 | V_254 | V_255 ) ) )
return ( error ) ;
if ( V_253 ) {
ASSERT ( V_258 || V_259 ) ;
ASSERT ( V_256 || V_257 ) ;
if ( ( error = F_143 ( NULL , V_66 -> V_72 ,
V_258 , V_259 , ( T_16 ) V_253 , 0 ,
V_42 | V_254 | V_255 ) ) )
return ( error ) ;
F_143 ( NULL , V_66 -> V_72 ,
V_256 , V_257 , - ( ( T_16 ) V_253 ) , 0 ,
V_254 ) ;
}
return ( 0 ) ;
}
int
F_144 (
struct V_88 * * V_263 )
{
struct V_1 * V_2 = V_263 [ 0 ] -> V_72 ;
int V_17 ;
if ( ! F_32 ( V_2 ) || ! F_55 ( V_2 ) )
return 0 ;
for ( V_17 = 0 ; ( V_17 < 4 && V_263 [ V_17 ] ) ; V_17 ++ ) {
struct V_88 * V_66 = V_263 [ V_17 ] ;
int error ;
if ( V_17 == 0 || V_66 != V_263 [ V_17 - 1 ] ) {
if ( F_56 ( V_2 , V_66 ) ) {
error = F_60 ( V_66 , 0 ) ;
if ( error )
return error ;
}
}
}
return 0 ;
}
void
F_145 (
struct V_264 * V_138 ,
struct V_88 * V_66 ,
struct V_3 * V_252 ,
struct V_3 * V_24 )
{
struct V_1 * V_2 = V_138 -> V_265 ;
if ( ! F_32 ( V_2 ) || ! F_55 ( V_2 ) )
return;
ASSERT ( F_47 ( V_66 , V_71 ) ) ;
ASSERT ( F_32 ( V_2 ) ) ;
if ( V_252 ) {
ASSERT ( V_66 -> V_85 == NULL ) ;
ASSERT ( F_36 ( V_2 ) ) ;
ASSERT ( V_66 -> V_82 . V_83 == F_7 ( V_252 -> V_19 . V_20 ) ) ;
V_66 -> V_85 = F_49 ( V_252 ) ;
F_141 ( V_138 , V_252 , V_251 , 1 ) ;
}
if ( V_24 ) {
ASSERT ( V_66 -> V_87 == NULL ) ;
ASSERT ( F_57 ( V_2 ) ) ;
ASSERT ( ( F_37 ( V_2 ) ?
V_66 -> V_82 . V_86 : F_58 ( V_66 ) ) ==
F_7 ( V_24 -> V_19 . V_20 ) ) ;
V_66 -> V_87 = F_49 ( V_24 ) ;
F_141 ( V_138 , V_24 , V_251 , 1 ) ;
}
}
