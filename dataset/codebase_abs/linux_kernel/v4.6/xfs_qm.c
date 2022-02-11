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
F_24 ( V_2 , V_40 ) ;
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
F_55 ( V_4 -> V_24 , V_83 ) ;
F_56 ( V_4 ) ;
F_57 ( V_77 , & V_4 -> V_38 ) ;
F_24 ( V_4 -> V_24 , V_40 ) ;
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
F_24 ( V_4 -> V_24 , V_40 ) ;
F_63 ( V_4 ) ;
F_55 ( V_4 -> V_24 , V_88 ) ;
return V_84 ;
V_82:
F_64 ( V_4 ) ;
F_55 ( V_4 -> V_24 , V_89 ) ;
return V_90 ;
V_85:
F_64 ( V_4 ) ;
F_55 ( V_4 -> V_24 , V_89 ) ;
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
STATIC void
F_75 (
T_3 * V_2 ,
T_2 type ,
T_8 * V_101 )
{
T_6 * V_4 ;
struct V_102 * V_103 ;
int error ;
error = F_76 ( V_2 , 0 , type , V_61 , & V_4 ) ;
if ( ! error ) {
T_9 * V_104 = & V_4 -> V_20 ;
V_103 = F_77 ( V_4 , V_101 ) ;
V_103 -> V_105 = F_78 ( V_104 -> V_106 ) ;
V_103 -> V_107 = F_78 ( V_104 -> V_108 ) ;
V_103 -> V_109 = F_78 ( V_104 -> V_110 ) ;
V_103 -> V_111 = F_78 ( V_104 -> V_112 ) ;
V_103 -> V_113 = F_78 ( V_104 -> V_114 ) ;
V_103 -> V_115 = F_78 ( V_104 -> V_116 ) ;
F_25 ( V_4 ) ;
}
}
STATIC int
F_79 (
T_3 * V_2 )
{
T_8 * V_101 ;
int error ;
T_6 * V_4 ;
ASSERT ( F_38 ( V_2 ) ) ;
V_101 = V_2 -> V_8 = F_80 ( sizeof( T_8 ) , V_117 ) ;
error = F_81 ( & V_101 -> V_39 ) ;
if ( error )
goto V_118;
error = F_82 ( V_2 ) ;
if ( error )
goto V_119;
F_83 ( & V_101 -> V_120 , V_121 ) ;
F_83 ( & V_101 -> V_122 , V_121 ) ;
F_83 ( & V_101 -> V_123 , V_121 ) ;
F_84 ( & V_101 -> V_19 ) ;
F_84 ( & V_101 -> V_124 ) ;
V_101 -> V_125 = F_85 ( V_2 , V_126 ) ;
V_101 -> V_127 = F_86 ( V_101 -> V_125 ) ;
V_2 -> V_128 |= ( V_2 -> V_63 . V_129 & V_130 ) ;
error = F_76 ( V_2 , 0 ,
F_87 ( V_2 ) ? V_43 :
( F_88 ( V_2 ) ? V_45 :
V_47 ) ,
V_61 , & V_4 ) ;
if ( ! error ) {
T_9 * V_104 = & V_4 -> V_20 ;
V_101 -> V_131 = V_104 -> V_132 ?
F_7 ( V_104 -> V_132 ) : V_133 ;
V_101 -> V_134 = V_104 -> V_135 ?
F_7 ( V_104 -> V_135 ) : V_136 ;
V_101 -> V_137 = V_104 -> V_138 ?
F_7 ( V_104 -> V_138 ) : V_139 ;
V_101 -> V_140 = V_104 -> V_141 ?
F_89 ( V_104 -> V_141 ) : V_142 ;
V_101 -> V_143 = V_104 -> V_144 ?
F_89 ( V_104 -> V_144 ) : V_145 ;
V_101 -> V_146 = V_104 -> V_147 ?
F_89 ( V_104 -> V_147 ) : V_148 ;
F_25 ( V_4 ) ;
} else {
V_101 -> V_131 = V_133 ;
V_101 -> V_134 = V_136 ;
V_101 -> V_137 = V_139 ;
V_101 -> V_140 = V_142 ;
V_101 -> V_143 = V_145 ;
V_101 -> V_146 = V_148 ;
}
if ( F_87 ( V_2 ) )
F_75 ( V_2 , V_43 , V_101 ) ;
if ( F_88 ( V_2 ) )
F_75 ( V_2 , V_45 , V_101 ) ;
if ( F_90 ( V_2 ) )
F_75 ( V_2 , V_47 , V_101 ) ;
V_101 -> V_96 . V_149 = F_73 ;
V_101 -> V_96 . V_150 = F_66 ;
V_101 -> V_96 . V_151 = V_152 ;
V_101 -> V_96 . V_41 = V_153 ;
F_91 ( & V_101 -> V_96 ) ;
return 0 ;
V_119:
F_92 ( & V_101 -> V_39 ) ;
V_118:
F_93 ( V_101 ) ;
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
F_94 ( & V_7 -> V_96 ) ;
F_92 ( & V_7 -> V_39 ) ;
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
F_95 ( & V_7 -> V_124 ) ;
F_93 ( V_7 ) ;
V_2 -> V_8 = NULL ;
}
STATIC int
F_96 (
T_3 * V_2 ,
T_4 * * V_55 ,
T_2 V_41 )
{
T_10 * V_154 ;
int error ;
int V_155 ;
bool V_156 = true ;
* V_55 = NULL ;
if ( ! F_97 ( & V_2 -> V_63 ) &&
( V_41 & ( V_46 | V_44 ) ) ) {
T_11 V_157 = V_158 ;
if ( ( V_41 & V_46 ) &&
( V_2 -> V_63 . V_159 != V_158 ) ) {
V_157 = V_2 -> V_63 . V_159 ;
ASSERT ( V_2 -> V_63 . V_160 == V_158 ) ;
} else if ( ( V_41 & V_44 ) &&
( V_2 -> V_63 . V_160 != V_158 ) ) {
V_157 = V_2 -> V_63 . V_160 ;
ASSERT ( V_2 -> V_63 . V_159 == V_158 ) ;
}
if ( V_157 != V_158 ) {
error = F_98 ( V_2 , NULL , V_157 , 0 , 0 , V_55 ) ;
if ( error )
return error ;
V_2 -> V_63 . V_159 = V_158 ;
V_2 -> V_63 . V_160 = V_158 ;
V_156 = false ;
}
}
V_154 = F_99 ( V_2 , V_161 ) ;
error = F_100 ( V_154 , & F_101 ( V_2 ) -> V_162 ,
F_102 ( V_2 ) , 0 ) ;
if ( error ) {
F_103 ( V_154 ) ;
return error ;
}
if ( V_156 ) {
error = F_104 ( & V_154 , NULL , V_163 , 1 , 0 , 0 , 1 , V_55 ,
& V_155 ) ;
if ( error ) {
F_103 ( V_154 ) ;
return error ;
}
}
F_65 ( & V_2 -> V_164 ) ;
if ( V_41 & V_165 ) {
ASSERT ( ! F_105 ( & V_2 -> V_63 ) ) ;
F_106 ( & V_2 -> V_63 ) ;
V_2 -> V_63 . V_166 = V_158 ;
V_2 -> V_63 . V_159 = V_158 ;
V_2 -> V_63 . V_160 = V_158 ;
V_2 -> V_63 . V_129 = V_2 -> V_128 & V_167 ;
}
if ( V_41 & V_42 )
V_2 -> V_63 . V_166 = ( * V_55 ) -> V_64 ;
else if ( V_41 & V_44 )
V_2 -> V_63 . V_159 = ( * V_55 ) -> V_64 ;
else
V_2 -> V_63 . V_160 = ( * V_55 ) -> V_64 ;
F_60 ( & V_2 -> V_164 ) ;
F_107 ( V_154 ) ;
error = F_108 ( V_154 ) ;
if ( error ) {
ASSERT ( F_19 ( V_2 ) ) ;
F_109 ( V_2 , L_3 , V_30 , error ) ;
}
if ( V_156 )
F_110 ( * V_55 ) ;
return error ;
}
STATIC void
F_111 (
T_3 * V_2 ,
T_12 * V_29 ,
T_5 V_56 ,
T_2 type )
{
struct V_168 * V_169 ;
int V_170 ;
F_112 ( V_29 , V_171 ) ;
#ifdef F_113
V_170 = F_114 ( V_2 , V_126 ) ;
F_115 ( V_170 , sizeof( V_172 ) ) ;
ASSERT ( V_2 -> V_8 -> V_127 == V_170 ) ;
#endif
V_169 = V_29 -> V_173 ;
for ( V_170 = 0 ; V_170 < V_2 -> V_8 -> V_127 ; V_170 ++ ) {
struct V_174 * V_175 ;
V_175 = (struct V_174 * ) & V_169 [ V_170 ] ;
F_116 ( V_2 , V_175 , V_56 + V_170 , type , V_176 ,
L_4 ) ;
V_175 -> V_36 = type ;
V_175 -> V_177 = 0 ;
V_175 -> V_178 = 0 ;
V_175 -> V_179 = 0 ;
V_175 -> V_132 = 0 ;
V_175 -> V_135 = 0 ;
V_175 -> V_138 = 0 ;
V_175 -> V_141 = 0 ;
V_175 -> V_144 = 0 ;
V_175 -> V_147 = 0 ;
if ( F_117 ( & V_2 -> V_63 ) ) {
F_118 ( ( char * ) & V_169 [ V_170 ] ,
sizeof( struct V_168 ) ,
V_180 ) ;
}
}
}
STATIC int
F_119 (
struct V_1 * V_2 ,
T_5 V_181 ,
T_13 V_182 ,
T_14 V_183 ,
T_2 V_41 ,
struct V_74 * V_184 )
{
struct V_28 * V_29 ;
int error ;
int type ;
ASSERT ( V_183 > 0 ) ;
type = V_41 & V_42 ? V_43 :
( V_41 & V_46 ? V_47 : V_45 ) ;
error = 0 ;
while ( V_183 -- ) {
error = F_120 ( V_2 , NULL , V_2 -> V_185 ,
F_121 ( V_2 , V_182 ) ,
V_2 -> V_8 -> V_125 , 0 , & V_29 ,
& V_186 ) ;
if ( error == - V_23 ) {
error = F_120 ( V_2 , NULL , V_2 -> V_185 ,
F_121 ( V_2 , V_182 ) ,
V_2 -> V_8 -> V_125 , 0 , & V_29 ,
NULL ) ;
}
if ( error )
break;
V_29 -> V_187 = & V_186 ;
F_111 ( V_2 , V_29 , V_181 , type ) ;
F_61 ( V_29 , V_184 ) ;
F_17 ( V_29 ) ;
V_182 ++ ;
V_181 += V_2 -> V_8 -> V_127 ;
}
return error ;
}
STATIC int
F_122 (
struct V_1 * V_2 ,
struct V_62 * V_188 ,
T_2 V_41 ,
struct V_74 * V_184 )
{
struct V_189 * V_190 ;
int V_18 , V_191 ;
int error ;
T_15 V_192 ;
T_14 V_193 ;
T_5 V_181 ;
T_13 V_194 ;
T_14 V_195 ;
error = 0 ;
if ( V_188 -> V_66 . V_196 == 0 )
return 0 ;
V_190 = F_123 ( V_197 * sizeof( * V_190 ) , V_117 ) ;
V_192 = 0 ;
V_193 = F_124 ( V_2 , V_2 -> V_198 -> V_199 ) ;
do {
T_2 V_200 ;
V_191 = V_197 ;
V_200 = F_125 ( V_188 ) ;
error = F_126 ( V_188 , V_192 , V_193 - V_192 ,
V_190 , & V_191 , 0 ) ;
F_49 ( V_188 , V_200 ) ;
if ( error )
break;
ASSERT ( V_191 <= V_197 ) ;
for ( V_18 = 0 ; V_18 < V_191 ; V_18 ++ ) {
ASSERT ( V_190 [ V_18 ] . V_201 != V_202 ) ;
ASSERT ( V_190 [ V_18 ] . V_203 ) ;
V_192 += V_190 [ V_18 ] . V_203 ;
if ( V_190 [ V_18 ] . V_201 == V_204 )
continue;
V_181 = ( T_5 ) V_190 [ V_18 ] . V_205 *
V_2 -> V_8 -> V_127 ;
if ( ( V_18 + 1 < V_191 ) &&
( V_190 [ V_18 + 1 ] . V_201 != V_204 ) ) {
V_195 = V_190 [ V_18 + 1 ] . V_203 ;
V_194 = V_190 [ V_18 + 1 ] . V_201 ;
while ( V_195 -- ) {
F_127 ( V_2 -> V_185 ,
F_121 ( V_2 , V_194 ) ,
V_2 -> V_8 -> V_125 ,
& V_186 ) ;
V_194 ++ ;
}
}
error = F_119 ( V_2 , V_181 ,
V_190 [ V_18 ] . V_201 ,
V_190 [ V_18 ] . V_203 ,
V_41 , V_184 ) ;
if ( error )
goto V_206;
}
} while ( V_191 > 0 );
V_206:
F_93 ( V_190 ) ;
return error ;
}
STATIC int
F_128 (
struct V_62 * V_55 ,
T_5 V_56 ,
T_2 type ,
T_16 V_207 ,
T_16 V_208 )
{
struct V_1 * V_2 = V_55 -> V_60 ;
struct V_3 * V_4 ;
int error ;
error = F_35 ( V_2 , V_55 , V_56 , type ,
V_68 | V_61 , & V_4 ) ;
if ( error ) {
ASSERT ( error != - V_209 ) ;
ASSERT ( error != - V_210 ) ;
return error ;
}
F_129 ( V_4 ) ;
F_130 ( & V_4 -> V_20 . V_178 , 1 ) ;
V_4 -> V_211 ++ ;
if ( V_207 ) {
F_130 ( & V_4 -> V_20 . V_177 , V_207 ) ;
V_4 -> V_212 += V_207 ;
}
if ( V_208 ) {
F_130 ( & V_4 -> V_20 . V_179 , V_208 ) ;
V_4 -> V_213 += V_208 ;
}
if ( V_4 -> V_20 . V_21 ) {
F_131 ( V_2 , V_4 ) ;
F_132 ( V_2 , & V_4 -> V_20 ) ;
}
V_4 -> V_25 |= V_214 ;
F_133 ( V_4 ) ;
return 0 ;
}
STATIC int
F_134 (
T_4 * V_55 ,
T_16 * V_215 )
{
T_14 V_208 ;
T_17 V_216 ;
T_18 * V_217 ;
T_17 V_218 ;
int error ;
ASSERT ( F_135 ( V_55 ) ) ;
V_217 = F_136 ( V_55 , V_219 ) ;
if ( ! ( V_217 -> V_220 & V_221 ) ) {
if ( ( error = F_137 ( NULL , V_55 , V_219 ) ) )
return error ;
}
V_208 = 0 ;
V_218 = V_217 -> V_222 / ( T_2 ) sizeof( V_223 ) ;
for ( V_216 = 0 ; V_216 < V_218 ; V_216 ++ )
V_208 += F_138 ( F_139 ( V_217 , V_216 ) ) ;
* V_215 = ( T_16 ) V_208 ;
return 0 ;
}
STATIC int
F_140 (
T_3 * V_2 ,
T_11 V_157 ,
void T_19 * V_224 ,
int V_225 ,
int * V_226 ,
int * V_227 )
{
T_4 * V_55 ;
T_16 V_207 , V_208 = 0 ;
int error ;
ASSERT ( F_38 ( V_2 ) ) ;
if ( F_41 ( & V_2 -> V_63 , V_157 ) ) {
* V_227 = V_228 ;
return - V_229 ;
}
error = F_98 ( V_2 , NULL , V_157 , 0 , V_59 , & V_55 ) ;
if ( error ) {
* V_227 = V_228 ;
return error ;
}
ASSERT ( V_55 -> V_230 == 0 ) ;
if ( F_135 ( V_55 ) ) {
error = F_134 ( V_55 , & V_208 ) ;
if ( error )
goto V_231;
}
V_207 = ( T_16 ) V_55 -> V_66 . V_196 - V_208 ;
if ( F_43 ( V_2 ) ) {
error = F_128 ( V_55 , V_55 -> V_66 . V_67 ,
V_43 , V_207 , V_208 ) ;
if ( error )
goto V_231;
}
if ( F_44 ( V_2 ) ) {
error = F_128 ( V_55 , V_55 -> V_66 . V_71 ,
V_45 , V_207 , V_208 ) ;
if ( error )
goto V_231;
}
if ( F_45 ( V_2 ) ) {
error = F_128 ( V_55 , F_46 ( V_55 ) ,
V_47 , V_207 , V_208 ) ;
if ( error )
goto V_231;
}
F_49 ( V_55 , V_59 ) ;
F_31 ( V_55 ) ;
* V_227 = V_232 ;
return 0 ;
V_231:
F_49 ( V_55 , V_59 ) ;
F_31 ( V_55 ) ;
* V_227 = V_233 ;
return error ;
}
STATIC int
F_141 (
struct V_3 * V_4 ,
void * V_5 )
{
struct V_74 * V_184 = V_5 ;
struct V_28 * V_29 = NULL ;
int error = 0 ;
F_10 ( V_4 ) ;
if ( V_4 -> V_25 & V_26 )
goto V_234;
if ( ! F_13 ( V_4 ) )
goto V_234;
F_12 ( V_4 ) ;
error = F_14 ( V_4 , & V_29 ) ;
if ( error )
goto V_234;
F_61 ( V_29 , V_184 ) ;
F_17 ( V_29 ) ;
V_234:
F_11 ( V_4 ) ;
return error ;
}
STATIC int
F_142 (
T_3 * V_2 )
{
int V_69 , V_235 , error , V_236 ;
T_11 V_237 ;
T_20 V_238 ;
T_2 V_41 ;
F_143 ( V_184 ) ;
struct V_62 * V_239 = V_2 -> V_8 -> V_52 ;
struct V_62 * V_240 = V_2 -> V_8 -> V_53 ;
struct V_62 * V_241 = V_2 -> V_8 -> V_54 ;
V_235 = V_242 ;
V_238 = 1 ;
V_237 = 0 ;
V_41 = 0 ;
ASSERT ( V_239 || V_240 || V_241 ) ;
ASSERT ( F_38 ( V_2 ) ) ;
F_144 ( V_2 , L_5 ) ;
if ( V_239 ) {
error = F_122 ( V_2 , V_239 , V_42 ,
& V_184 ) ;
if ( error )
goto V_243;
V_41 |= V_244 ;
}
if ( V_240 ) {
error = F_122 ( V_2 , V_240 , V_44 ,
& V_184 ) ;
if ( error )
goto V_243;
V_41 |= V_245 ;
}
if ( V_241 ) {
error = F_122 ( V_2 , V_241 , V_46 ,
& V_184 ) ;
if ( error )
goto V_243;
V_41 |= V_246 ;
}
do {
error = F_145 ( V_2 , & V_237 , & V_235 ,
F_140 ,
V_238 , NULL , & V_69 ) ;
if ( error )
break;
} while ( ! V_69 );
if ( F_43 ( V_2 ) ) {
error = F_1 ( V_2 , V_43 , F_141 ,
& V_184 ) ;
}
if ( F_44 ( V_2 ) ) {
V_236 = F_1 ( V_2 , V_45 , F_141 ,
& V_184 ) ;
if ( ! error )
error = V_236 ;
}
if ( F_45 ( V_2 ) ) {
V_236 = F_1 ( V_2 , V_47 , F_141 ,
& V_184 ) ;
if ( ! error )
error = V_236 ;
}
V_236 = F_69 ( & V_184 ) ;
if ( ! error )
error = V_236 ;
if ( error ) {
F_26 ( V_2 , V_48 ) ;
goto V_243;
}
V_2 -> V_128 &= ~ V_130 ;
V_2 -> V_128 |= V_41 ;
V_243:
while ( ! F_22 ( & V_184 ) ) {
struct V_28 * V_29 =
F_70 ( & V_184 , struct V_28 , V_247 ) ;
F_71 ( & V_29 -> V_247 ) ;
F_17 ( V_29 ) ;
}
if ( error ) {
F_15 ( V_2 ,
L_6 ,
error ) ;
ASSERT ( V_2 -> V_8 != NULL ) ;
F_28 ( V_2 ) ;
if ( F_146 ( V_2 ) ) {
F_15 ( V_2 ,
L_7 ) ;
}
} else
F_144 ( V_2 , L_8 ) ;
return error ;
}
void
F_147 (
struct V_1 * V_2 )
{
int error = 0 ;
T_2 V_248 ;
if ( V_2 -> V_63 . V_249 ) {
F_144 ( V_2 , L_9 ) ;
V_2 -> V_128 = 0 ;
goto V_250;
}
ASSERT ( F_38 ( V_2 ) ) ;
error = F_79 ( V_2 ) ;
if ( error ) {
ASSERT ( V_2 -> V_8 == NULL ) ;
V_2 -> V_128 = 0 ;
goto V_250;
}
if ( F_148 ( V_2 ) ) {
error = F_142 ( V_2 ) ;
if ( error ) {
return;
}
}
if ( ! F_43 ( V_2 ) )
V_2 -> V_128 &= ~ V_244 ;
if ( ! F_44 ( V_2 ) )
V_2 -> V_128 &= ~ V_245 ;
if ( ! F_45 ( V_2 ) )
V_2 -> V_128 &= ~ V_246 ;
V_250:
F_65 ( & V_2 -> V_164 ) ;
V_248 = V_2 -> V_63 . V_129 ;
V_2 -> V_63 . V_129 = V_2 -> V_128 & V_251 ;
F_60 ( & V_2 -> V_164 ) ;
if ( V_248 != ( V_2 -> V_128 & V_251 ) ) {
if ( F_149 ( V_2 , false ) ) {
ASSERT ( ! ( F_38 ( V_2 ) ) ) ;
F_109 ( V_2 , L_10 ,
V_30 ) ;
}
}
if ( error ) {
F_15 ( V_2 , L_11 ) ;
return;
}
}
STATIC int
F_82 (
T_3 * V_2 )
{
struct V_62 * V_239 = NULL ;
struct V_62 * V_240 = NULL ;
struct V_62 * V_241 = NULL ;
int error ;
T_2 V_41 = 0 ;
ASSERT ( V_2 -> V_8 ) ;
if ( F_105 ( & V_2 -> V_63 ) ) {
if ( F_43 ( V_2 ) &&
V_2 -> V_63 . V_166 != V_158 ) {
ASSERT ( V_2 -> V_63 . V_166 > 0 ) ;
error = F_98 ( V_2 , NULL , V_2 -> V_63 . V_166 ,
0 , 0 , & V_239 ) ;
if ( error )
return error ;
}
if ( F_44 ( V_2 ) &&
V_2 -> V_63 . V_159 != V_158 ) {
ASSERT ( V_2 -> V_63 . V_159 > 0 ) ;
error = F_98 ( V_2 , NULL , V_2 -> V_63 . V_159 ,
0 , 0 , & V_240 ) ;
if ( error )
goto V_252;
}
if ( F_45 ( V_2 ) &&
V_2 -> V_63 . V_160 != V_158 ) {
ASSERT ( V_2 -> V_63 . V_160 > 0 ) ;
error = F_98 ( V_2 , NULL , V_2 -> V_63 . V_160 ,
0 , 0 , & V_241 ) ;
if ( error )
goto V_252;
}
} else {
V_41 |= V_165 ;
}
if ( F_43 ( V_2 ) && V_239 == NULL ) {
error = F_96 ( V_2 , & V_239 ,
V_41 | V_42 ) ;
if ( error )
goto V_252;
V_41 &= ~ V_165 ;
}
if ( F_44 ( V_2 ) && V_240 == NULL ) {
error = F_96 ( V_2 , & V_240 ,
V_41 | V_44 ) ;
if ( error )
goto V_252;
V_41 &= ~ V_165 ;
}
if ( F_45 ( V_2 ) && V_241 == NULL ) {
error = F_96 ( V_2 , & V_241 ,
V_41 | V_46 ) ;
if ( error )
goto V_252;
}
V_2 -> V_8 -> V_52 = V_239 ;
V_2 -> V_8 -> V_53 = V_240 ;
V_2 -> V_8 -> V_54 = V_241 ;
return 0 ;
V_252:
if ( V_239 )
F_31 ( V_239 ) ;
if ( V_240 )
F_31 ( V_240 ) ;
if ( V_241 )
F_31 ( V_241 ) ;
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
F_150 (
struct V_62 * V_55 ,
T_5 V_253 ,
T_5 V_254 ,
T_21 V_255 ,
T_2 V_41 ,
struct V_3 * * V_256 ,
struct V_3 * * V_257 ,
struct V_3 * * V_258 )
{
struct V_1 * V_2 = V_55 -> V_60 ;
struct V_3 * V_259 = NULL ;
struct V_3 * V_260 = NULL ;
struct V_3 * V_261 = NULL ;
int error ;
T_2 V_262 ;
if ( ! F_38 ( V_2 ) || ! F_39 ( V_2 ) )
return 0 ;
V_262 = V_59 ;
F_48 ( V_55 , V_262 ) ;
if ( ( V_41 & V_263 ) && F_151 ( V_55 ) )
V_254 = V_55 -> V_66 . V_71 ;
if ( F_40 ( V_2 , V_55 ) ) {
error = F_42 ( V_55 , V_68 ) ;
if ( error ) {
F_49 ( V_55 , V_262 ) ;
return error ;
}
}
if ( ( V_41 & V_42 ) && F_43 ( V_2 ) ) {
if ( V_55 -> V_66 . V_67 != V_253 ) {
F_49 ( V_55 , V_262 ) ;
error = F_35 ( V_2 , NULL , V_253 ,
V_43 ,
V_68 |
V_61 ,
& V_259 ) ;
if ( error ) {
ASSERT ( error != - V_210 ) ;
return error ;
}
F_11 ( V_259 ) ;
V_262 = V_264 ;
F_48 ( V_55 , V_262 ) ;
} else {
ASSERT ( V_55 -> V_65 ) ;
V_259 = F_152 ( V_55 -> V_65 ) ;
}
}
if ( ( V_41 & V_44 ) && F_44 ( V_2 ) ) {
if ( V_55 -> V_66 . V_71 != V_254 ) {
F_49 ( V_55 , V_262 ) ;
error = F_35 ( V_2 , NULL , V_254 ,
V_45 ,
V_68 |
V_61 ,
& V_260 ) ;
if ( error ) {
ASSERT ( error != - V_210 ) ;
goto V_252;
}
F_11 ( V_260 ) ;
V_262 = V_264 ;
F_48 ( V_55 , V_262 ) ;
} else {
ASSERT ( V_55 -> V_70 ) ;
V_260 = F_152 ( V_55 -> V_70 ) ;
}
}
if ( ( V_41 & V_46 ) && F_45 ( V_2 ) ) {
if ( F_46 ( V_55 ) != V_255 ) {
F_49 ( V_55 , V_262 ) ;
error = F_35 ( V_2 , NULL , ( T_5 ) V_255 ,
V_47 ,
V_68 |
V_61 ,
& V_261 ) ;
if ( error ) {
ASSERT ( error != - V_210 ) ;
goto V_252;
}
F_11 ( V_261 ) ;
V_262 = V_264 ;
F_48 ( V_55 , V_262 ) ;
} else {
ASSERT ( V_55 -> V_72 ) ;
V_261 = F_152 ( V_55 -> V_72 ) ;
}
}
if ( V_259 )
F_153 ( V_55 ) ;
F_49 ( V_55 , V_262 ) ;
if ( V_256 )
* V_256 = V_259 ;
else
F_51 ( V_259 ) ;
if ( V_257 )
* V_257 = V_260 ;
else
F_51 ( V_260 ) ;
if ( V_258 )
* V_258 = V_261 ;
else
F_51 ( V_261 ) ;
return 0 ;
V_252:
F_51 ( V_260 ) ;
F_51 ( V_259 ) ;
return error ;
}
T_6 *
F_154 (
T_10 * V_154 ,
T_4 * V_55 ,
T_6 * * V_265 ,
T_6 * V_266 )
{
T_6 * V_267 ;
T_2 V_268 = F_135 ( V_55 ) ?
V_269 : V_270 ;
ASSERT ( F_33 ( V_55 , V_59 ) ) ;
ASSERT ( F_38 ( V_55 -> V_60 ) ) ;
V_267 = * V_265 ;
ASSERT ( V_267 ) ;
ASSERT ( V_267 != V_266 ) ;
F_155 ( V_154 , V_267 , V_268 , - ( V_55 -> V_66 . V_196 ) ) ;
F_155 ( V_154 , V_267 , V_271 , - 1 ) ;
F_155 ( V_154 , V_266 , V_268 , V_55 -> V_66 . V_196 ) ;
F_155 ( V_154 , V_266 , V_271 , 1 ) ;
* V_265 = F_152 ( V_266 ) ;
return V_267 ;
}
int
F_156 (
struct V_272 * V_154 ,
struct V_62 * V_55 ,
struct V_3 * V_273 ,
struct V_3 * V_274 ,
struct V_3 * V_275 ,
T_2 V_41 )
{
struct V_1 * V_2 = V_55 -> V_60 ;
T_2 V_276 , V_277 , V_278 = 0 ;
struct V_3 * V_279 = NULL ;
struct V_3 * V_280 = NULL ;
struct V_3 * V_281 = NULL ;
struct V_3 * V_282 = NULL ;
struct V_3 * V_283 = NULL ;
struct V_3 * V_284 = NULL ;
int error ;
ASSERT ( F_33 ( V_55 , V_59 | V_264 ) ) ;
ASSERT ( F_38 ( V_2 ) ) ;
V_276 = V_55 -> V_230 ;
V_277 = F_135 ( V_55 ) ?
V_285 : V_286 ;
if ( F_43 ( V_2 ) && V_273 &&
V_55 -> V_66 . V_67 != F_7 ( V_273 -> V_20 . V_21 ) ) {
V_282 = V_273 ;
if ( V_276 ) {
ASSERT ( V_55 -> V_65 ) ;
V_279 = V_55 -> V_65 ;
}
}
if ( F_44 ( V_55 -> V_60 ) && V_274 &&
V_55 -> V_66 . V_71 != F_7 ( V_274 -> V_20 . V_21 ) ) {
V_283 = V_274 ;
if ( V_276 ) {
ASSERT ( V_55 -> V_70 ) ;
V_280 = V_55 -> V_70 ;
}
}
if ( F_45 ( V_55 -> V_60 ) && V_275 &&
F_46 ( V_55 ) != F_7 ( V_275 -> V_20 . V_21 ) ) {
V_278 = V_287 ;
V_284 = V_275 ;
if ( V_276 ) {
ASSERT ( V_55 -> V_72 ) ;
V_281 = V_55 -> V_72 ;
}
}
error = F_157 ( V_154 , V_55 -> V_60 ,
V_282 , V_283 , V_284 ,
V_55 -> V_66 . V_196 , 1 ,
V_41 | V_277 | V_278 ) ;
if ( error )
return error ;
if ( V_276 ) {
ASSERT ( V_282 || V_283 || V_284 ) ;
ASSERT ( V_279 || V_280 || V_281 ) ;
error = F_157 ( NULL , V_55 -> V_60 ,
V_282 , V_283 , V_284 ,
( T_16 ) V_276 , 0 ,
V_41 | V_277 | V_278 ) ;
if ( error )
return error ;
F_157 ( NULL , V_55 -> V_60 ,
V_279 , V_280 , V_281 ,
- ( ( T_16 ) V_276 ) , 0 , V_277 ) ;
}
return 0 ;
}
int
F_158 (
struct V_62 * * V_288 )
{
struct V_1 * V_2 = V_288 [ 0 ] -> V_60 ;
int V_18 ;
if ( ! F_38 ( V_2 ) || ! F_39 ( V_2 ) )
return 0 ;
for ( V_18 = 0 ; ( V_18 < 4 && V_288 [ V_18 ] ) ; V_18 ++ ) {
struct V_62 * V_55 = V_288 [ V_18 ] ;
int error ;
if ( V_18 == 0 || V_55 != V_288 [ V_18 - 1 ] ) {
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
F_159 (
struct V_272 * V_154 ,
struct V_62 * V_55 ,
struct V_3 * V_273 ,
struct V_3 * V_274 ,
struct V_3 * V_275 )
{
struct V_1 * V_2 = V_154 -> V_289 ;
if ( ! F_38 ( V_2 ) || ! F_39 ( V_2 ) )
return;
ASSERT ( F_33 ( V_55 , V_59 ) ) ;
ASSERT ( F_38 ( V_2 ) ) ;
if ( V_273 && F_43 ( V_2 ) ) {
ASSERT ( V_55 -> V_65 == NULL ) ;
ASSERT ( V_55 -> V_66 . V_67 == F_7 ( V_273 -> V_20 . V_21 ) ) ;
V_55 -> V_65 = F_152 ( V_273 ) ;
F_155 ( V_154 , V_273 , V_271 , 1 ) ;
}
if ( V_274 && F_44 ( V_2 ) ) {
ASSERT ( V_55 -> V_70 == NULL ) ;
ASSERT ( V_55 -> V_66 . V_71 == F_7 ( V_274 -> V_20 . V_21 ) ) ;
V_55 -> V_70 = F_152 ( V_274 ) ;
F_155 ( V_154 , V_274 , V_271 , 1 ) ;
}
if ( V_275 && F_45 ( V_2 ) ) {
ASSERT ( V_55 -> V_72 == NULL ) ;
ASSERT ( F_46 ( V_55 ) == F_7 ( V_275 -> V_20 . V_21 ) ) ;
V_55 -> V_72 = F_152 ( V_275 ) ;
F_155 ( V_154 , V_275 , V_271 , 1 ) ;
}
}
