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
struct V_76 * V_77 ,
T_7 * V_78 ,
void * V_79 )
__releases( V_78 ) __acquires( V_78 )
{
struct V_3 * V_4 = F_53 ( V_75 ,
struct V_3 , V_38 ) ;
struct V_80 * V_81 = V_79 ;
if ( ! F_54 ( V_4 ) )
goto V_82;
if ( V_4 -> V_27 ) {
F_11 ( V_4 ) ;
F_55 ( V_83 ) ;
F_56 ( V_4 ) ;
F_57 ( V_77 , & V_4 -> V_38 ) ;
F_24 ( V_40 ) ;
return V_84 ;
}
if ( ! F_58 ( V_4 ) ) {
F_11 ( V_4 ) ;
goto V_82;
}
if ( F_13 ( V_4 ) ) {
struct V_28 * V_29 = NULL ;
int error ;
F_59 ( V_4 ) ;
F_60 ( V_78 ) ;
error = F_14 ( V_4 , & V_29 ) ;
if ( error ) {
F_15 ( V_4 -> V_24 , L_1 ,
V_30 , V_4 ) ;
goto V_85;
}
F_61 ( V_29 , & V_81 -> V_86 ) ;
F_17 ( V_29 ) ;
goto V_85;
}
F_20 ( V_4 ) ;
V_4 -> V_25 |= V_26 ;
F_11 ( V_4 ) ;
ASSERT ( V_4 -> V_27 == 0 ) ;
F_62 ( V_77 , & V_4 -> V_38 , & V_81 -> V_87 ) ;
F_24 ( V_40 ) ;
F_63 ( V_4 ) ;
F_55 ( V_88 ) ;
return V_84 ;
V_82:
F_64 ( V_4 ) ;
F_55 ( V_89 ) ;
return V_90 ;
V_85:
F_64 ( V_4 ) ;
F_55 ( V_89 ) ;
F_11 ( V_4 ) ;
F_65 ( V_78 ) ;
return V_91 ;
}
static unsigned long
F_66 (
struct V_92 * V_93 ,
struct V_94 * V_95 )
{
struct V_6 * V_7 = F_53 ( V_93 ,
struct V_6 , V_96 ) ;
struct V_80 V_81 ;
unsigned long V_97 ;
int error ;
if ( ( V_95 -> V_98 & ( V_99 | V_100 ) ) != ( V_99 | V_100 ) )
return 0 ;
F_67 ( & V_81 . V_86 ) ;
F_67 ( & V_81 . V_87 ) ;
V_97 = F_68 ( & V_7 -> V_39 , V_95 ,
F_52 , & V_81 ) ;
error = F_69 ( & V_81 . V_86 ) ;
if ( error )
F_15 ( NULL , L_2 , V_30 ) ;
while ( ! F_22 ( & V_81 . V_87 ) ) {
struct V_3 * V_4 ;
V_4 = F_70 ( & V_81 . V_87 , struct V_3 , V_38 ) ;
F_71 ( & V_4 -> V_38 ) ;
F_72 ( V_4 ) ;
}
return V_97 ;
}
static unsigned long
F_73 (
struct V_92 * V_93 ,
struct V_94 * V_95 )
{
struct V_6 * V_7 = F_53 ( V_93 ,
struct V_6 , V_96 ) ;
return F_74 ( & V_7 -> V_39 , V_95 ) ;
}
STATIC int
F_75 (
T_3 * V_2 )
{
T_8 * V_101 ;
int error ;
T_6 * V_4 ;
ASSERT ( F_38 ( V_2 ) ) ;
V_101 = V_2 -> V_8 = F_76 ( sizeof( T_8 ) , V_102 ) ;
error = F_77 ( & V_101 -> V_39 ) ;
if ( error )
goto V_103;
error = F_78 ( V_2 ) ;
if ( error )
goto V_104;
F_79 ( & V_101 -> V_105 , V_106 ) ;
F_79 ( & V_101 -> V_107 , V_106 ) ;
F_79 ( & V_101 -> V_108 , V_106 ) ;
F_80 ( & V_101 -> V_19 ) ;
F_80 ( & V_101 -> V_109 ) ;
V_101 -> V_110 = F_81 ( V_2 , V_111 ) ;
V_101 -> V_112 = F_82 ( V_101 -> V_110 ) ;
V_2 -> V_113 |= ( V_2 -> V_63 . V_114 & V_115 ) ;
error = F_83 ( V_2 , 0 ,
F_84 ( V_2 ) ? V_43 :
( F_85 ( V_2 ) ? V_45 :
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
F_86 ( V_116 -> V_127 ) : V_128 ;
V_101 -> V_129 = V_116 -> V_130 ?
F_86 ( V_116 -> V_130 ) : V_131 ;
V_101 -> V_132 = V_116 -> V_133 ?
F_86 ( V_116 -> V_133 ) : V_134 ;
V_101 -> V_135 = F_87 ( V_116 -> V_136 ) ;
V_101 -> V_137 = F_87 ( V_116 -> V_138 ) ;
V_101 -> V_139 = F_87 ( V_116 -> V_140 ) ;
V_101 -> V_141 = F_87 ( V_116 -> V_142 ) ;
V_101 -> V_143 = F_87 ( V_116 -> V_144 ) ;
V_101 -> V_145 = F_87 ( V_116 -> V_146 ) ;
F_25 ( V_4 ) ;
} else {
V_101 -> V_117 = V_119 ;
V_101 -> V_120 = V_122 ;
V_101 -> V_123 = V_125 ;
V_101 -> V_126 = V_128 ;
V_101 -> V_129 = V_131 ;
V_101 -> V_132 = V_134 ;
}
V_101 -> V_96 . V_147 = F_73 ;
V_101 -> V_96 . V_148 = F_66 ;
V_101 -> V_96 . V_149 = V_150 ;
V_101 -> V_96 . V_41 = V_151 ;
F_88 ( & V_101 -> V_96 ) ;
return 0 ;
V_104:
F_89 ( & V_101 -> V_39 ) ;
V_103:
F_90 ( V_101 ) ;
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
F_91 ( & V_7 -> V_96 ) ;
F_89 ( & V_7 -> V_39 ) ;
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
F_92 ( & V_7 -> V_109 ) ;
F_90 ( V_7 ) ;
V_2 -> V_8 = NULL ;
}
STATIC int
F_93 (
T_3 * V_2 ,
T_4 * * V_55 ,
T_2 V_41 )
{
T_10 * V_152 ;
int error ;
int V_153 ;
bool V_154 = true ;
* V_55 = NULL ;
if ( ! F_94 ( & V_2 -> V_63 ) &&
( V_41 & ( V_46 | V_44 ) ) ) {
T_11 V_155 = V_156 ;
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
error = F_95 ( V_2 , NULL , V_155 , 0 , 0 , V_55 ) ;
if ( error )
return error ;
V_2 -> V_63 . V_157 = V_156 ;
V_2 -> V_63 . V_158 = V_156 ;
V_154 = false ;
}
}
V_152 = F_96 ( V_2 , V_159 ) ;
error = F_97 ( V_152 , & F_98 ( V_2 ) -> V_160 ,
F_99 ( V_2 ) , 0 ) ;
if ( error ) {
F_100 ( V_152 ) ;
return error ;
}
if ( V_154 ) {
error = F_101 ( & V_152 , NULL , V_161 , 1 , 0 , 0 , 1 , V_55 ,
& V_153 ) ;
if ( error ) {
F_100 ( V_152 ) ;
return error ;
}
}
F_65 ( & V_2 -> V_162 ) ;
if ( V_41 & V_163 ) {
ASSERT ( ! F_102 ( & V_2 -> V_63 ) ) ;
F_103 ( & V_2 -> V_63 ) ;
V_2 -> V_63 . V_164 = V_156 ;
V_2 -> V_63 . V_157 = V_156 ;
V_2 -> V_63 . V_158 = V_156 ;
V_2 -> V_63 . V_114 = V_2 -> V_113 & V_165 ;
}
if ( V_41 & V_42 )
V_2 -> V_63 . V_164 = ( * V_55 ) -> V_64 ;
else if ( V_41 & V_44 )
V_2 -> V_63 . V_157 = ( * V_55 ) -> V_64 ;
else
V_2 -> V_63 . V_158 = ( * V_55 ) -> V_64 ;
F_60 ( & V_2 -> V_162 ) ;
F_104 ( V_152 ) ;
error = F_105 ( V_152 ) ;
if ( error ) {
ASSERT ( F_19 ( V_2 ) ) ;
F_106 ( V_2 , L_3 , V_30 , error ) ;
}
if ( V_154 )
F_107 ( * V_55 ) ;
return error ;
}
STATIC void
F_108 (
T_3 * V_2 ,
T_12 * V_29 ,
T_5 V_56 ,
T_2 type )
{
struct V_166 * V_167 ;
int V_168 ;
F_109 ( V_29 , V_169 ) ;
#ifdef F_110
V_168 = F_111 ( V_2 , V_111 ) ;
F_112 ( V_168 , sizeof( V_170 ) ) ;
ASSERT ( V_2 -> V_8 -> V_112 == V_168 ) ;
#endif
V_167 = V_29 -> V_171 ;
for ( V_168 = 0 ; V_168 < V_2 -> V_8 -> V_112 ; V_168 ++ ) {
struct V_172 * V_173 ;
V_173 = (struct V_172 * ) & V_167 [ V_168 ] ;
F_113 ( V_2 , V_173 , V_56 + V_168 , type , V_174 ,
L_4 ) ;
V_173 -> V_36 = type ;
V_173 -> V_175 = 0 ;
V_173 -> V_176 = 0 ;
V_173 -> V_177 = 0 ;
V_173 -> V_118 = 0 ;
V_173 -> V_121 = 0 ;
V_173 -> V_124 = 0 ;
V_173 -> V_127 = 0 ;
V_173 -> V_130 = 0 ;
V_173 -> V_133 = 0 ;
if ( F_114 ( & V_2 -> V_63 ) ) {
F_115 ( ( char * ) & V_167 [ V_168 ] ,
sizeof( struct V_166 ) ,
V_178 ) ;
}
}
}
STATIC int
F_116 (
struct V_1 * V_2 ,
T_5 V_179 ,
T_13 V_180 ,
T_14 V_181 ,
T_2 V_41 ,
struct V_74 * V_182 )
{
struct V_28 * V_29 ;
int error ;
int type ;
ASSERT ( V_181 > 0 ) ;
type = V_41 & V_42 ? V_43 :
( V_41 & V_46 ? V_47 : V_45 ) ;
error = 0 ;
while ( V_181 -- ) {
error = F_117 ( V_2 , NULL , V_2 -> V_183 ,
F_118 ( V_2 , V_180 ) ,
V_2 -> V_8 -> V_110 , 0 , & V_29 ,
& V_184 ) ;
if ( error == - V_23 ) {
error = F_117 ( V_2 , NULL , V_2 -> V_183 ,
F_118 ( V_2 , V_180 ) ,
V_2 -> V_8 -> V_110 , 0 , & V_29 ,
NULL ) ;
}
if ( error )
break;
V_29 -> V_185 = & V_184 ;
F_108 ( V_2 , V_29 , V_179 , type ) ;
F_61 ( V_29 , V_182 ) ;
F_17 ( V_29 ) ;
V_180 ++ ;
V_179 += V_2 -> V_8 -> V_112 ;
}
return error ;
}
STATIC int
F_119 (
struct V_1 * V_2 ,
struct V_62 * V_186 ,
T_2 V_41 ,
struct V_74 * V_182 )
{
struct V_187 * V_188 ;
int V_18 , V_189 ;
int error ;
T_15 V_190 ;
T_14 V_191 ;
T_5 V_179 ;
T_13 V_192 ;
T_14 V_193 ;
error = 0 ;
if ( V_186 -> V_66 . V_194 == 0 )
return 0 ;
V_188 = F_120 ( V_195 * sizeof( * V_188 ) , V_102 ) ;
V_190 = 0 ;
V_191 = F_121 ( V_2 , V_2 -> V_196 -> V_197 ) ;
do {
T_2 V_198 ;
V_189 = V_195 ;
V_198 = F_122 ( V_186 ) ;
error = F_123 ( V_186 , V_190 , V_191 - V_190 ,
V_188 , & V_189 , 0 ) ;
F_49 ( V_186 , V_198 ) ;
if ( error )
break;
ASSERT ( V_189 <= V_195 ) ;
for ( V_18 = 0 ; V_18 < V_189 ; V_18 ++ ) {
ASSERT ( V_188 [ V_18 ] . V_199 != V_200 ) ;
ASSERT ( V_188 [ V_18 ] . V_201 ) ;
V_190 += V_188 [ V_18 ] . V_201 ;
if ( V_188 [ V_18 ] . V_199 == V_202 )
continue;
V_179 = ( T_5 ) V_188 [ V_18 ] . V_203 *
V_2 -> V_8 -> V_112 ;
if ( ( V_18 + 1 < V_189 ) &&
( V_188 [ V_18 + 1 ] . V_199 != V_202 ) ) {
V_193 = V_188 [ V_18 + 1 ] . V_201 ;
V_192 = V_188 [ V_18 + 1 ] . V_199 ;
while ( V_193 -- ) {
F_124 ( V_2 -> V_183 ,
F_118 ( V_2 , V_192 ) ,
V_2 -> V_8 -> V_110 ,
& V_184 ) ;
V_192 ++ ;
}
}
error = F_116 ( V_2 , V_179 ,
V_188 [ V_18 ] . V_199 ,
V_188 [ V_18 ] . V_201 ,
V_41 , V_182 ) ;
if ( error )
goto V_204;
}
} while ( V_189 > 0 );
V_204:
F_90 ( V_188 ) ;
return error ;
}
STATIC int
F_125 (
struct V_62 * V_55 ,
T_5 V_56 ,
T_2 type ,
T_16 V_205 ,
T_16 V_206 )
{
struct V_1 * V_2 = V_55 -> V_60 ;
struct V_3 * V_4 ;
int error ;
error = F_35 ( V_2 , V_55 , V_56 , type ,
V_68 | V_61 , & V_4 ) ;
if ( error ) {
ASSERT ( error != - V_207 ) ;
ASSERT ( error != - V_208 ) ;
return error ;
}
F_126 ( V_4 ) ;
F_127 ( & V_4 -> V_20 . V_176 , 1 ) ;
V_4 -> V_209 ++ ;
if ( V_205 ) {
F_127 ( & V_4 -> V_20 . V_175 , V_205 ) ;
V_4 -> V_210 += V_205 ;
}
if ( V_206 ) {
F_127 ( & V_4 -> V_20 . V_177 , V_206 ) ;
V_4 -> V_211 += V_206 ;
}
if ( V_4 -> V_20 . V_21 ) {
F_128 ( V_2 , V_4 ) ;
F_129 ( V_2 , & V_4 -> V_20 ) ;
}
V_4 -> V_25 |= V_212 ;
F_130 ( V_4 ) ;
return 0 ;
}
STATIC int
F_131 (
T_4 * V_55 ,
T_16 * V_213 )
{
T_14 V_206 ;
T_17 V_214 ;
T_18 * V_215 ;
T_17 V_216 ;
int error ;
ASSERT ( F_132 ( V_55 ) ) ;
V_215 = F_133 ( V_55 , V_217 ) ;
if ( ! ( V_215 -> V_218 & V_219 ) ) {
if ( ( error = F_134 ( NULL , V_55 , V_217 ) ) )
return error ;
}
V_206 = 0 ;
V_216 = V_215 -> V_220 / ( T_2 ) sizeof( V_221 ) ;
for ( V_214 = 0 ; V_214 < V_216 ; V_214 ++ )
V_206 += F_135 ( F_136 ( V_215 , V_214 ) ) ;
* V_213 = ( T_16 ) V_206 ;
return 0 ;
}
STATIC int
F_137 (
T_3 * V_2 ,
T_11 V_155 ,
void T_19 * V_222 ,
int V_223 ,
int * V_224 ,
int * V_225 )
{
T_4 * V_55 ;
T_16 V_205 , V_206 = 0 ;
int error ;
ASSERT ( F_38 ( V_2 ) ) ;
if ( F_41 ( & V_2 -> V_63 , V_155 ) ) {
* V_225 = V_226 ;
return - V_227 ;
}
error = F_95 ( V_2 , NULL , V_155 , 0 , V_59 , & V_55 ) ;
if ( error ) {
* V_225 = V_226 ;
return error ;
}
ASSERT ( V_55 -> V_228 == 0 ) ;
if ( F_132 ( V_55 ) ) {
error = F_131 ( V_55 , & V_206 ) ;
if ( error )
goto V_229;
}
V_205 = ( T_16 ) V_55 -> V_66 . V_194 - V_206 ;
if ( F_43 ( V_2 ) ) {
error = F_125 ( V_55 , V_55 -> V_66 . V_67 ,
V_43 , V_205 , V_206 ) ;
if ( error )
goto V_229;
}
if ( F_44 ( V_2 ) ) {
error = F_125 ( V_55 , V_55 -> V_66 . V_71 ,
V_45 , V_205 , V_206 ) ;
if ( error )
goto V_229;
}
if ( F_45 ( V_2 ) ) {
error = F_125 ( V_55 , F_46 ( V_55 ) ,
V_47 , V_205 , V_206 ) ;
if ( error )
goto V_229;
}
F_49 ( V_55 , V_59 ) ;
F_31 ( V_55 ) ;
* V_225 = V_230 ;
return 0 ;
V_229:
F_49 ( V_55 , V_59 ) ;
F_31 ( V_55 ) ;
* V_225 = V_231 ;
return error ;
}
STATIC int
F_138 (
struct V_3 * V_4 ,
void * V_5 )
{
struct V_74 * V_182 = V_5 ;
struct V_28 * V_29 = NULL ;
int error = 0 ;
F_10 ( V_4 ) ;
if ( V_4 -> V_25 & V_26 )
goto V_232;
if ( ! F_13 ( V_4 ) )
goto V_232;
F_12 ( V_4 ) ;
error = F_14 ( V_4 , & V_29 ) ;
if ( error )
goto V_232;
F_61 ( V_29 , V_182 ) ;
F_17 ( V_29 ) ;
V_232:
F_11 ( V_4 ) ;
return error ;
}
STATIC int
F_139 (
T_3 * V_2 )
{
int V_69 , V_233 , error , V_234 ;
T_11 V_235 ;
T_20 V_236 ;
T_2 V_41 ;
F_140 ( V_182 ) ;
struct V_62 * V_237 = V_2 -> V_8 -> V_52 ;
struct V_62 * V_238 = V_2 -> V_8 -> V_53 ;
struct V_62 * V_239 = V_2 -> V_8 -> V_54 ;
V_233 = V_240 ;
V_236 = 1 ;
V_235 = 0 ;
V_41 = 0 ;
ASSERT ( V_237 || V_238 || V_239 ) ;
ASSERT ( F_38 ( V_2 ) ) ;
F_141 ( V_2 , L_5 ) ;
if ( V_237 ) {
error = F_119 ( V_2 , V_237 , V_42 ,
& V_182 ) ;
if ( error )
goto V_241;
V_41 |= V_242 ;
}
if ( V_238 ) {
error = F_119 ( V_2 , V_238 , V_44 ,
& V_182 ) ;
if ( error )
goto V_241;
V_41 |= V_243 ;
}
if ( V_239 ) {
error = F_119 ( V_2 , V_239 , V_46 ,
& V_182 ) ;
if ( error )
goto V_241;
V_41 |= V_244 ;
}
do {
error = F_142 ( V_2 , & V_235 , & V_233 ,
F_137 ,
V_236 , NULL , & V_69 ) ;
if ( error )
break;
} while ( ! V_69 );
if ( F_43 ( V_2 ) ) {
error = F_1 ( V_2 , V_43 , F_138 ,
& V_182 ) ;
}
if ( F_44 ( V_2 ) ) {
V_234 = F_1 ( V_2 , V_45 , F_138 ,
& V_182 ) ;
if ( ! error )
error = V_234 ;
}
if ( F_45 ( V_2 ) ) {
V_234 = F_1 ( V_2 , V_47 , F_138 ,
& V_182 ) ;
if ( ! error )
error = V_234 ;
}
V_234 = F_69 ( & V_182 ) ;
if ( ! error )
error = V_234 ;
if ( error ) {
F_26 ( V_2 , V_48 ) ;
goto V_241;
}
V_2 -> V_113 &= ~ V_115 ;
V_2 -> V_113 |= V_41 ;
V_241:
while ( ! F_22 ( & V_182 ) ) {
struct V_28 * V_29 =
F_70 ( & V_182 , struct V_28 , V_245 ) ;
F_71 ( & V_29 -> V_245 ) ;
F_17 ( V_29 ) ;
}
if ( error ) {
F_15 ( V_2 ,
L_6 ,
error ) ;
ASSERT ( V_2 -> V_8 != NULL ) ;
F_28 ( V_2 ) ;
if ( F_143 ( V_2 ) ) {
F_15 ( V_2 ,
L_7 ) ;
}
} else
F_141 ( V_2 , L_8 ) ;
return error ;
}
void
F_144 (
struct V_1 * V_2 )
{
int error = 0 ;
T_2 V_246 ;
if ( V_2 -> V_63 . V_247 ) {
F_141 ( V_2 , L_9 ) ;
V_2 -> V_113 = 0 ;
goto V_248;
}
ASSERT ( F_38 ( V_2 ) ) ;
error = F_75 ( V_2 ) ;
if ( error ) {
ASSERT ( V_2 -> V_8 == NULL ) ;
V_2 -> V_113 = 0 ;
goto V_248;
}
if ( F_145 ( V_2 ) ) {
error = F_139 ( V_2 ) ;
if ( error ) {
return;
}
}
if ( ! F_43 ( V_2 ) )
V_2 -> V_113 &= ~ V_242 ;
if ( ! F_44 ( V_2 ) )
V_2 -> V_113 &= ~ V_243 ;
if ( ! F_45 ( V_2 ) )
V_2 -> V_113 &= ~ V_244 ;
V_248:
F_65 ( & V_2 -> V_162 ) ;
V_246 = V_2 -> V_63 . V_114 ;
V_2 -> V_63 . V_114 = V_2 -> V_113 & V_249 ;
F_60 ( & V_2 -> V_162 ) ;
if ( V_246 != ( V_2 -> V_113 & V_249 ) ) {
if ( F_146 ( V_2 , false ) ) {
ASSERT ( ! ( F_38 ( V_2 ) ) ) ;
F_106 ( V_2 , L_10 ,
V_30 ) ;
}
}
if ( error ) {
F_15 ( V_2 , L_11 ) ;
return;
}
}
STATIC int
F_78 (
T_3 * V_2 )
{
struct V_62 * V_237 = NULL ;
struct V_62 * V_238 = NULL ;
struct V_62 * V_239 = NULL ;
int error ;
T_2 V_41 = 0 ;
ASSERT ( V_2 -> V_8 ) ;
if ( F_102 ( & V_2 -> V_63 ) ) {
if ( F_43 ( V_2 ) &&
V_2 -> V_63 . V_164 != V_156 ) {
ASSERT ( V_2 -> V_63 . V_164 > 0 ) ;
error = F_95 ( V_2 , NULL , V_2 -> V_63 . V_164 ,
0 , 0 , & V_237 ) ;
if ( error )
return error ;
}
if ( F_44 ( V_2 ) &&
V_2 -> V_63 . V_157 != V_156 ) {
ASSERT ( V_2 -> V_63 . V_157 > 0 ) ;
error = F_95 ( V_2 , NULL , V_2 -> V_63 . V_157 ,
0 , 0 , & V_238 ) ;
if ( error )
goto V_250;
}
if ( F_45 ( V_2 ) &&
V_2 -> V_63 . V_158 != V_156 ) {
ASSERT ( V_2 -> V_63 . V_158 > 0 ) ;
error = F_95 ( V_2 , NULL , V_2 -> V_63 . V_158 ,
0 , 0 , & V_239 ) ;
if ( error )
goto V_250;
}
} else {
V_41 |= V_163 ;
}
if ( F_43 ( V_2 ) && V_237 == NULL ) {
error = F_93 ( V_2 , & V_237 ,
V_41 | V_42 ) ;
if ( error )
goto V_250;
V_41 &= ~ V_163 ;
}
if ( F_44 ( V_2 ) && V_238 == NULL ) {
error = F_93 ( V_2 , & V_238 ,
V_41 | V_44 ) ;
if ( error )
goto V_250;
V_41 &= ~ V_163 ;
}
if ( F_45 ( V_2 ) && V_239 == NULL ) {
error = F_93 ( V_2 , & V_239 ,
V_41 | V_46 ) ;
if ( error )
goto V_250;
}
V_2 -> V_8 -> V_52 = V_237 ;
V_2 -> V_8 -> V_53 = V_238 ;
V_2 -> V_8 -> V_54 = V_239 ;
return 0 ;
V_250:
if ( V_237 )
F_31 ( V_237 ) ;
if ( V_238 )
F_31 ( V_238 ) ;
if ( V_239 )
F_31 ( V_239 ) ;
return error ;
}
STATIC void
F_72 (
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
F_147 (
struct V_62 * V_55 ,
T_5 V_251 ,
T_5 V_252 ,
T_21 V_253 ,
T_2 V_41 ,
struct V_3 * * V_254 ,
struct V_3 * * V_255 ,
struct V_3 * * V_256 )
{
struct V_1 * V_2 = V_55 -> V_60 ;
struct V_3 * V_257 = NULL ;
struct V_3 * V_258 = NULL ;
struct V_3 * V_259 = NULL ;
int error ;
T_2 V_260 ;
if ( ! F_38 ( V_2 ) || ! F_39 ( V_2 ) )
return 0 ;
V_260 = V_59 ;
F_48 ( V_55 , V_260 ) ;
if ( ( V_41 & V_261 ) && F_148 ( V_55 ) )
V_252 = V_55 -> V_66 . V_71 ;
if ( F_40 ( V_2 , V_55 ) ) {
error = F_42 ( V_55 , V_68 ) ;
if ( error ) {
F_49 ( V_55 , V_260 ) ;
return error ;
}
}
if ( ( V_41 & V_42 ) && F_43 ( V_2 ) ) {
if ( V_55 -> V_66 . V_67 != V_251 ) {
F_49 ( V_55 , V_260 ) ;
error = F_35 ( V_2 , NULL , V_251 ,
V_43 ,
V_68 |
V_61 ,
& V_257 ) ;
if ( error ) {
ASSERT ( error != - V_208 ) ;
return error ;
}
F_11 ( V_257 ) ;
V_260 = V_262 ;
F_48 ( V_55 , V_260 ) ;
} else {
ASSERT ( V_55 -> V_65 ) ;
V_257 = F_149 ( V_55 -> V_65 ) ;
}
}
if ( ( V_41 & V_44 ) && F_44 ( V_2 ) ) {
if ( V_55 -> V_66 . V_71 != V_252 ) {
F_49 ( V_55 , V_260 ) ;
error = F_35 ( V_2 , NULL , V_252 ,
V_45 ,
V_68 |
V_61 ,
& V_258 ) ;
if ( error ) {
ASSERT ( error != - V_208 ) ;
goto V_250;
}
F_11 ( V_258 ) ;
V_260 = V_262 ;
F_48 ( V_55 , V_260 ) ;
} else {
ASSERT ( V_55 -> V_70 ) ;
V_258 = F_149 ( V_55 -> V_70 ) ;
}
}
if ( ( V_41 & V_46 ) && F_45 ( V_2 ) ) {
if ( F_46 ( V_55 ) != V_253 ) {
F_49 ( V_55 , V_260 ) ;
error = F_35 ( V_2 , NULL , ( T_5 ) V_253 ,
V_47 ,
V_68 |
V_61 ,
& V_259 ) ;
if ( error ) {
ASSERT ( error != - V_208 ) ;
goto V_250;
}
F_11 ( V_259 ) ;
V_260 = V_262 ;
F_48 ( V_55 , V_260 ) ;
} else {
ASSERT ( V_55 -> V_72 ) ;
V_259 = F_149 ( V_55 -> V_72 ) ;
}
}
if ( V_257 )
F_150 ( V_55 ) ;
F_49 ( V_55 , V_260 ) ;
if ( V_254 )
* V_254 = V_257 ;
else
F_51 ( V_257 ) ;
if ( V_255 )
* V_255 = V_258 ;
else
F_51 ( V_258 ) ;
if ( V_256 )
* V_256 = V_259 ;
else
F_51 ( V_259 ) ;
return 0 ;
V_250:
F_51 ( V_258 ) ;
F_51 ( V_257 ) ;
return error ;
}
T_6 *
F_151 (
T_10 * V_152 ,
T_4 * V_55 ,
T_6 * * V_263 ,
T_6 * V_264 )
{
T_6 * V_265 ;
T_2 V_266 = F_132 ( V_55 ) ?
V_267 : V_268 ;
ASSERT ( F_33 ( V_55 , V_59 ) ) ;
ASSERT ( F_38 ( V_55 -> V_60 ) ) ;
V_265 = * V_263 ;
ASSERT ( V_265 ) ;
ASSERT ( V_265 != V_264 ) ;
F_152 ( V_152 , V_265 , V_266 , - ( V_55 -> V_66 . V_194 ) ) ;
F_152 ( V_152 , V_265 , V_269 , - 1 ) ;
F_152 ( V_152 , V_264 , V_266 , V_55 -> V_66 . V_194 ) ;
F_152 ( V_152 , V_264 , V_269 , 1 ) ;
* V_263 = F_149 ( V_264 ) ;
return V_265 ;
}
int
F_153 (
struct V_270 * V_152 ,
struct V_62 * V_55 ,
struct V_3 * V_271 ,
struct V_3 * V_272 ,
struct V_3 * V_273 ,
T_2 V_41 )
{
struct V_1 * V_2 = V_55 -> V_60 ;
T_2 V_274 , V_275 , V_276 = 0 ;
struct V_3 * V_277 = NULL ;
struct V_3 * V_278 = NULL ;
struct V_3 * V_279 = NULL ;
struct V_3 * V_280 = NULL ;
struct V_3 * V_281 = NULL ;
struct V_3 * V_282 = NULL ;
int error ;
ASSERT ( F_33 ( V_55 , V_59 | V_262 ) ) ;
ASSERT ( F_38 ( V_2 ) ) ;
V_274 = V_55 -> V_228 ;
V_275 = F_132 ( V_55 ) ?
V_283 : V_284 ;
if ( F_43 ( V_2 ) && V_271 &&
V_55 -> V_66 . V_67 != F_7 ( V_271 -> V_20 . V_21 ) ) {
V_280 = V_271 ;
if ( V_274 ) {
ASSERT ( V_55 -> V_65 ) ;
V_277 = V_55 -> V_65 ;
}
}
if ( F_44 ( V_55 -> V_60 ) && V_272 &&
V_55 -> V_66 . V_71 != F_7 ( V_272 -> V_20 . V_21 ) ) {
V_281 = V_272 ;
if ( V_274 ) {
ASSERT ( V_55 -> V_70 ) ;
V_278 = V_55 -> V_70 ;
}
}
if ( F_45 ( V_55 -> V_60 ) && V_273 &&
F_46 ( V_55 ) != F_7 ( V_273 -> V_20 . V_21 ) ) {
V_276 = V_285 ;
V_282 = V_273 ;
if ( V_274 ) {
ASSERT ( V_55 -> V_72 ) ;
V_279 = V_55 -> V_72 ;
}
}
error = F_154 ( V_152 , V_55 -> V_60 ,
V_280 , V_281 , V_282 ,
V_55 -> V_66 . V_194 , 1 ,
V_41 | V_275 | V_276 ) ;
if ( error )
return error ;
if ( V_274 ) {
ASSERT ( V_280 || V_281 || V_282 ) ;
ASSERT ( V_277 || V_278 || V_279 ) ;
error = F_154 ( NULL , V_55 -> V_60 ,
V_280 , V_281 , V_282 ,
( T_16 ) V_274 , 0 ,
V_41 | V_275 | V_276 ) ;
if ( error )
return error ;
F_154 ( NULL , V_55 -> V_60 ,
V_277 , V_278 , V_279 ,
- ( ( T_16 ) V_274 ) , 0 , V_275 ) ;
}
return 0 ;
}
int
F_155 (
struct V_62 * * V_286 )
{
struct V_1 * V_2 = V_286 [ 0 ] -> V_60 ;
int V_18 ;
if ( ! F_38 ( V_2 ) || ! F_39 ( V_2 ) )
return 0 ;
for ( V_18 = 0 ; ( V_18 < 4 && V_286 [ V_18 ] ) ; V_18 ++ ) {
struct V_62 * V_55 = V_286 [ V_18 ] ;
int error ;
if ( V_18 == 0 || V_55 != V_286 [ V_18 - 1 ] ) {
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
F_156 (
struct V_270 * V_152 ,
struct V_62 * V_55 ,
struct V_3 * V_271 ,
struct V_3 * V_272 ,
struct V_3 * V_273 )
{
struct V_1 * V_2 = V_152 -> V_287 ;
if ( ! F_38 ( V_2 ) || ! F_39 ( V_2 ) )
return;
ASSERT ( F_33 ( V_55 , V_59 ) ) ;
ASSERT ( F_38 ( V_2 ) ) ;
if ( V_271 && F_43 ( V_2 ) ) {
ASSERT ( V_55 -> V_65 == NULL ) ;
ASSERT ( V_55 -> V_66 . V_67 == F_7 ( V_271 -> V_20 . V_21 ) ) ;
V_55 -> V_65 = F_149 ( V_271 ) ;
F_152 ( V_152 , V_271 , V_269 , 1 ) ;
}
if ( V_272 && F_44 ( V_2 ) ) {
ASSERT ( V_55 -> V_70 == NULL ) ;
ASSERT ( V_55 -> V_66 . V_71 == F_7 ( V_272 -> V_20 . V_21 ) ) ;
V_55 -> V_70 = F_149 ( V_272 ) ;
F_152 ( V_152 , V_272 , V_269 , 1 ) ;
}
if ( V_273 && F_45 ( V_2 ) ) {
ASSERT ( V_55 -> V_72 == NULL ) ;
ASSERT ( F_46 ( V_55 ) == F_7 ( V_273 -> V_20 . V_21 ) ) ;
V_55 -> V_72 = F_149 ( V_273 ) ;
F_152 ( V_152 , V_273 , V_269 , 1 ) ;
}
}
