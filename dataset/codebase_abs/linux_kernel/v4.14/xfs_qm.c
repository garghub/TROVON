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
if ( ! V_11 )
break;
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
error = F_99 ( V_2 , & F_100 ( V_2 ) -> V_161 ,
F_101 ( V_2 ) , 0 , 0 , & V_154 ) ;
if ( error )
return error ;
if ( V_156 ) {
error = F_102 ( & V_154 , NULL , V_162 , 1 , 0 , 0 , 1 , V_55 ,
& V_155 ) ;
if ( error ) {
F_103 ( V_154 ) ;
return error ;
}
}
F_65 ( & V_2 -> V_163 ) ;
if ( V_41 & V_164 ) {
ASSERT ( ! F_104 ( & V_2 -> V_63 ) ) ;
F_105 ( & V_2 -> V_63 ) ;
V_2 -> V_63 . V_165 = V_158 ;
V_2 -> V_63 . V_159 = V_158 ;
V_2 -> V_63 . V_160 = V_158 ;
V_2 -> V_63 . V_129 = V_2 -> V_128 & V_166 ;
}
if ( V_41 & V_42 )
V_2 -> V_63 . V_165 = ( * V_55 ) -> V_64 ;
else if ( V_41 & V_44 )
V_2 -> V_63 . V_159 = ( * V_55 ) -> V_64 ;
else
V_2 -> V_63 . V_160 = ( * V_55 ) -> V_64 ;
F_60 ( & V_2 -> V_163 ) ;
F_106 ( V_154 ) ;
error = F_107 ( V_154 ) ;
if ( error ) {
ASSERT ( F_19 ( V_2 ) ) ;
F_108 ( V_2 , L_3 , V_30 , error ) ;
}
if ( V_156 )
F_109 ( * V_55 ) ;
return error ;
}
STATIC void
F_110 (
T_3 * V_2 ,
T_12 * V_29 ,
T_5 V_56 ,
T_2 type )
{
struct V_167 * V_168 ;
int V_169 ;
F_111 ( V_29 , V_170 ) ;
#ifdef F_112
V_169 = ( int ) F_113 ( V_2 , V_126 ) /
sizeof( V_171 ) ;
ASSERT ( V_2 -> V_8 -> V_127 == V_169 ) ;
#endif
V_168 = V_29 -> V_172 ;
for ( V_169 = 0 ; V_169 < V_2 -> V_8 -> V_127 ; V_169 ++ ) {
struct V_173 * V_174 ;
V_174 = (struct V_173 * ) & V_168 [ V_169 ] ;
F_114 ( V_2 , V_174 , V_56 + V_169 , type , V_175 ,
L_4 ) ;
V_174 -> V_36 = type ;
V_174 -> V_176 = 0 ;
V_174 -> V_177 = 0 ;
V_174 -> V_178 = 0 ;
V_174 -> V_132 = 0 ;
V_174 -> V_135 = 0 ;
V_174 -> V_138 = 0 ;
V_174 -> V_141 = 0 ;
V_174 -> V_144 = 0 ;
V_174 -> V_147 = 0 ;
if ( F_115 ( & V_2 -> V_63 ) ) {
F_116 ( ( char * ) & V_168 [ V_169 ] ,
sizeof( struct V_167 ) ,
V_179 ) ;
}
}
}
STATIC int
F_117 (
struct V_1 * V_2 ,
T_5 V_180 ,
T_13 V_181 ,
T_14 V_182 ,
T_2 V_41 ,
struct V_74 * V_183 )
{
struct V_28 * V_29 ;
int error ;
int type ;
ASSERT ( V_182 > 0 ) ;
type = V_41 & V_42 ? V_43 :
( V_41 & V_46 ? V_47 : V_45 ) ;
error = 0 ;
while ( V_182 -- ) {
error = F_118 ( V_2 , NULL , V_2 -> V_184 ,
F_119 ( V_2 , V_181 ) ,
V_2 -> V_8 -> V_125 , 0 , & V_29 ,
& V_185 ) ;
if ( error == - V_23 ) {
error = F_118 ( V_2 , NULL , V_2 -> V_184 ,
F_119 ( V_2 , V_181 ) ,
V_2 -> V_8 -> V_125 , 0 , & V_29 ,
NULL ) ;
}
if ( error )
break;
V_29 -> V_186 = & V_185 ;
F_110 ( V_2 , V_29 , V_180 , type ) ;
F_61 ( V_29 , V_183 ) ;
F_17 ( V_29 ) ;
V_181 ++ ;
V_180 += V_2 -> V_8 -> V_127 ;
}
return error ;
}
STATIC int
F_120 (
struct V_1 * V_2 ,
struct V_62 * V_187 ,
T_2 V_41 ,
struct V_74 * V_183 )
{
struct V_188 * V_189 ;
int V_18 , V_190 ;
int error ;
T_15 V_191 ;
T_14 V_192 ;
T_5 V_180 ;
T_13 V_193 ;
T_14 V_194 ;
error = 0 ;
if ( V_187 -> V_66 . V_195 == 0 )
return 0 ;
V_189 = F_121 ( V_196 * sizeof( * V_189 ) , V_117 ) ;
V_191 = 0 ;
V_192 = F_122 ( V_2 , V_2 -> V_197 -> V_198 ) ;
do {
T_2 V_199 ;
V_190 = V_196 ;
V_199 = F_123 ( V_187 ) ;
error = F_124 ( V_187 , V_191 , V_192 - V_191 ,
V_189 , & V_190 , 0 ) ;
F_49 ( V_187 , V_199 ) ;
if ( error )
break;
ASSERT ( V_190 <= V_196 ) ;
for ( V_18 = 0 ; V_18 < V_190 ; V_18 ++ ) {
ASSERT ( V_189 [ V_18 ] . V_200 != V_201 ) ;
ASSERT ( V_189 [ V_18 ] . V_202 ) ;
V_191 += V_189 [ V_18 ] . V_202 ;
if ( V_189 [ V_18 ] . V_200 == V_203 )
continue;
V_180 = ( T_5 ) V_189 [ V_18 ] . V_204 *
V_2 -> V_8 -> V_127 ;
if ( ( V_18 + 1 < V_190 ) &&
( V_189 [ V_18 + 1 ] . V_200 != V_203 ) ) {
V_194 = V_189 [ V_18 + 1 ] . V_202 ;
V_193 = V_189 [ V_18 + 1 ] . V_200 ;
while ( V_194 -- ) {
F_125 ( V_2 -> V_184 ,
F_119 ( V_2 , V_193 ) ,
V_2 -> V_8 -> V_125 ,
& V_185 ) ;
V_193 ++ ;
}
}
error = F_117 ( V_2 , V_180 ,
V_189 [ V_18 ] . V_200 ,
V_189 [ V_18 ] . V_202 ,
V_41 , V_183 ) ;
if ( error )
goto V_205;
}
} while ( V_190 > 0 );
V_205:
F_93 ( V_189 ) ;
return error ;
}
STATIC int
F_126 (
struct V_62 * V_55 ,
T_5 V_56 ,
T_2 type ,
T_16 V_206 ,
T_16 V_207 )
{
struct V_1 * V_2 = V_55 -> V_60 ;
struct V_3 * V_4 ;
int error ;
error = F_35 ( V_2 , V_55 , V_56 , type ,
V_68 | V_61 , & V_4 ) ;
if ( error ) {
ASSERT ( error != - V_208 ) ;
ASSERT ( error != - V_209 ) ;
return error ;
}
F_127 ( V_4 ) ;
F_128 ( & V_4 -> V_20 . V_177 , 1 ) ;
V_4 -> V_210 ++ ;
if ( V_206 ) {
F_128 ( & V_4 -> V_20 . V_176 , V_206 ) ;
V_4 -> V_211 += V_206 ;
}
if ( V_207 ) {
F_128 ( & V_4 -> V_20 . V_178 , V_207 ) ;
V_4 -> V_212 += V_207 ;
}
if ( V_4 -> V_20 . V_21 ) {
F_129 ( V_2 , V_4 ) ;
F_130 ( V_2 , & V_4 -> V_20 ) ;
}
V_4 -> V_25 |= V_213 ;
F_131 ( V_4 ) ;
return 0 ;
}
STATIC int
F_132 (
T_3 * V_2 ,
T_11 V_157 ,
void T_17 * V_214 ,
int V_215 ,
int * V_216 ,
int * V_217 )
{
T_4 * V_55 ;
T_16 V_206 ;
T_14 V_207 = 0 ;
int error ;
ASSERT ( F_38 ( V_2 ) ) ;
if ( F_41 ( & V_2 -> V_63 , V_157 ) ) {
* V_217 = V_218 ;
return - V_219 ;
}
error = F_98 ( V_2 , NULL , V_157 , V_220 , V_59 ,
& V_55 ) ;
if ( error ) {
* V_217 = V_218 ;
return error ;
}
ASSERT ( V_55 -> V_221 == 0 ) ;
if ( F_133 ( V_55 ) ) {
struct V_222 * V_223 = F_134 ( V_55 , V_224 ) ;
if ( ! ( V_223 -> V_225 & V_226 ) ) {
error = F_135 ( NULL , V_55 , V_224 ) ;
if ( error )
goto V_227;
}
F_136 ( V_223 , & V_207 ) ;
}
V_206 = ( T_16 ) V_55 -> V_66 . V_195 - V_207 ;
if ( F_43 ( V_2 ) ) {
error = F_126 ( V_55 , V_55 -> V_66 . V_67 ,
V_43 , V_206 , V_207 ) ;
if ( error )
goto V_227;
}
if ( F_44 ( V_2 ) ) {
error = F_126 ( V_55 , V_55 -> V_66 . V_71 ,
V_45 , V_206 , V_207 ) ;
if ( error )
goto V_227;
}
if ( F_45 ( V_2 ) ) {
error = F_126 ( V_55 , F_46 ( V_55 ) ,
V_47 , V_206 , V_207 ) ;
if ( error )
goto V_227;
}
F_49 ( V_55 , V_59 ) ;
F_31 ( V_55 ) ;
* V_217 = V_228 ;
return 0 ;
V_227:
F_49 ( V_55 , V_59 ) ;
F_31 ( V_55 ) ;
* V_217 = V_229 ;
return error ;
}
STATIC int
F_137 (
struct V_3 * V_4 ,
void * V_5 )
{
struct V_1 * V_2 = V_4 -> V_24 ;
struct V_74 * V_183 = V_5 ;
struct V_28 * V_29 = NULL ;
int error = 0 ;
F_10 ( V_4 ) ;
if ( V_4 -> V_25 & V_26 )
goto V_230;
if ( ! F_13 ( V_4 ) )
goto V_230;
if ( ! F_58 ( V_4 ) ) {
F_138 ( V_189 , V_4 -> V_231 ,
V_2 -> V_8 -> V_125 ) ;
V_29 = F_139 ( V_2 -> V_184 , & V_189 , 1 , 0 , NULL ) ;
if ( ! V_29 ) {
error = - V_219 ;
goto V_230;
}
F_140 ( V_29 ) ;
F_141 ( V_29 , V_183 ) ;
F_142 ( V_29 ) ;
error = - V_22 ;
goto V_230;
}
error = F_14 ( V_4 , & V_29 ) ;
if ( error )
goto V_230;
F_61 ( V_29 , V_183 ) ;
F_17 ( V_29 ) ;
V_230:
F_11 ( V_4 ) ;
return error ;
}
STATIC int
F_143 (
T_3 * V_2 )
{
int V_69 , V_232 , error , V_233 ;
T_11 V_234 ;
T_18 V_235 ;
T_2 V_41 ;
F_144 ( V_183 ) ;
struct V_62 * V_236 = V_2 -> V_8 -> V_52 ;
struct V_62 * V_237 = V_2 -> V_8 -> V_53 ;
struct V_62 * V_238 = V_2 -> V_8 -> V_54 ;
V_232 = V_239 ;
V_235 = 1 ;
V_234 = 0 ;
V_41 = 0 ;
ASSERT ( V_236 || V_237 || V_238 ) ;
ASSERT ( F_38 ( V_2 ) ) ;
F_145 ( V_2 , L_5 ) ;
if ( V_236 ) {
error = F_120 ( V_2 , V_236 , V_42 ,
& V_183 ) ;
if ( error )
goto V_240;
V_41 |= V_241 ;
}
if ( V_237 ) {
error = F_120 ( V_2 , V_237 , V_44 ,
& V_183 ) ;
if ( error )
goto V_240;
V_41 |= V_242 ;
}
if ( V_238 ) {
error = F_120 ( V_2 , V_238 , V_46 ,
& V_183 ) ;
if ( error )
goto V_240;
V_41 |= V_243 ;
}
do {
error = F_146 ( V_2 , & V_234 , & V_232 ,
F_132 ,
V_235 , NULL , & V_69 ) ;
if ( error )
break;
} while ( ! V_69 );
if ( F_43 ( V_2 ) ) {
error = F_1 ( V_2 , V_43 , F_137 ,
& V_183 ) ;
}
if ( F_44 ( V_2 ) ) {
V_233 = F_1 ( V_2 , V_45 , F_137 ,
& V_183 ) ;
if ( ! error )
error = V_233 ;
}
if ( F_45 ( V_2 ) ) {
V_233 = F_1 ( V_2 , V_47 , F_137 ,
& V_183 ) ;
if ( ! error )
error = V_233 ;
}
V_233 = F_69 ( & V_183 ) ;
if ( ! error )
error = V_233 ;
if ( error ) {
F_26 ( V_2 , V_48 ) ;
goto V_240;
}
V_2 -> V_128 &= ~ V_130 ;
V_2 -> V_128 |= V_41 ;
V_240:
F_147 ( & V_183 ) ;
if ( error ) {
F_15 ( V_2 ,
L_6 ,
error ) ;
ASSERT ( V_2 -> V_8 != NULL ) ;
F_28 ( V_2 ) ;
if ( F_148 ( V_2 ) ) {
F_15 ( V_2 ,
L_7 ) ;
}
} else
F_145 ( V_2 , L_8 ) ;
return error ;
}
void
F_149 (
struct V_1 * V_2 )
{
int error = 0 ;
T_2 V_244 ;
if ( V_2 -> V_63 . V_245 ) {
F_145 ( V_2 , L_9 ) ;
V_2 -> V_128 = 0 ;
goto V_246;
}
ASSERT ( F_38 ( V_2 ) ) ;
error = F_79 ( V_2 ) ;
if ( error ) {
ASSERT ( V_2 -> V_8 == NULL ) ;
V_2 -> V_128 = 0 ;
goto V_246;
}
if ( F_150 ( V_2 ) ) {
error = F_143 ( V_2 ) ;
if ( error ) {
return;
}
}
if ( ! F_43 ( V_2 ) )
V_2 -> V_128 &= ~ V_241 ;
if ( ! F_44 ( V_2 ) )
V_2 -> V_128 &= ~ V_242 ;
if ( ! F_45 ( V_2 ) )
V_2 -> V_128 &= ~ V_243 ;
V_246:
F_65 ( & V_2 -> V_163 ) ;
V_244 = V_2 -> V_63 . V_129 ;
V_2 -> V_63 . V_129 = V_2 -> V_128 & V_247 ;
F_60 ( & V_2 -> V_163 ) ;
if ( V_244 != ( V_2 -> V_128 & V_247 ) ) {
if ( F_151 ( V_2 , false ) ) {
ASSERT ( ! ( F_38 ( V_2 ) ) ) ;
F_108 ( V_2 , L_10 ,
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
struct V_62 * V_236 = NULL ;
struct V_62 * V_237 = NULL ;
struct V_62 * V_238 = NULL ;
int error ;
T_2 V_41 = 0 ;
ASSERT ( V_2 -> V_8 ) ;
if ( F_104 ( & V_2 -> V_63 ) ) {
if ( F_43 ( V_2 ) &&
V_2 -> V_63 . V_165 != V_158 ) {
ASSERT ( V_2 -> V_63 . V_165 > 0 ) ;
error = F_98 ( V_2 , NULL , V_2 -> V_63 . V_165 ,
0 , 0 , & V_236 ) ;
if ( error )
return error ;
}
if ( F_44 ( V_2 ) &&
V_2 -> V_63 . V_159 != V_158 ) {
ASSERT ( V_2 -> V_63 . V_159 > 0 ) ;
error = F_98 ( V_2 , NULL , V_2 -> V_63 . V_159 ,
0 , 0 , & V_237 ) ;
if ( error )
goto V_248;
}
if ( F_45 ( V_2 ) &&
V_2 -> V_63 . V_160 != V_158 ) {
ASSERT ( V_2 -> V_63 . V_160 > 0 ) ;
error = F_98 ( V_2 , NULL , V_2 -> V_63 . V_160 ,
0 , 0 , & V_238 ) ;
if ( error )
goto V_248;
}
} else {
V_41 |= V_164 ;
}
if ( F_43 ( V_2 ) && V_236 == NULL ) {
error = F_96 ( V_2 , & V_236 ,
V_41 | V_42 ) ;
if ( error )
goto V_248;
V_41 &= ~ V_164 ;
}
if ( F_44 ( V_2 ) && V_237 == NULL ) {
error = F_96 ( V_2 , & V_237 ,
V_41 | V_44 ) ;
if ( error )
goto V_248;
V_41 &= ~ V_164 ;
}
if ( F_45 ( V_2 ) && V_238 == NULL ) {
error = F_96 ( V_2 , & V_238 ,
V_41 | V_46 ) ;
if ( error )
goto V_248;
}
V_2 -> V_8 -> V_52 = V_236 ;
V_2 -> V_8 -> V_53 = V_237 ;
V_2 -> V_8 -> V_54 = V_238 ;
return 0 ;
V_248:
if ( V_236 )
F_31 ( V_236 ) ;
if ( V_237 )
F_31 ( V_237 ) ;
if ( V_238 )
F_31 ( V_238 ) ;
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
F_152 (
struct V_62 * V_55 ,
T_5 V_249 ,
T_5 V_250 ,
T_19 V_251 ,
T_2 V_41 ,
struct V_3 * * V_252 ,
struct V_3 * * V_253 ,
struct V_3 * * V_254 )
{
struct V_1 * V_2 = V_55 -> V_60 ;
struct V_3 * V_255 = NULL ;
struct V_3 * V_256 = NULL ;
struct V_3 * V_257 = NULL ;
int error ;
T_2 V_258 ;
if ( ! F_38 ( V_2 ) || ! F_39 ( V_2 ) )
return 0 ;
V_258 = V_59 ;
F_48 ( V_55 , V_258 ) ;
if ( ( V_41 & V_259 ) && F_153 ( V_55 ) )
V_250 = V_55 -> V_66 . V_71 ;
if ( F_40 ( V_2 , V_55 ) ) {
error = F_42 ( V_55 , V_68 ) ;
if ( error ) {
F_49 ( V_55 , V_258 ) ;
return error ;
}
}
if ( ( V_41 & V_42 ) && F_43 ( V_2 ) ) {
if ( V_55 -> V_66 . V_67 != V_249 ) {
F_49 ( V_55 , V_258 ) ;
error = F_35 ( V_2 , NULL , V_249 ,
V_43 ,
V_68 |
V_61 ,
& V_255 ) ;
if ( error ) {
ASSERT ( error != - V_209 ) ;
return error ;
}
F_11 ( V_255 ) ;
V_258 = V_260 ;
F_48 ( V_55 , V_258 ) ;
} else {
ASSERT ( V_55 -> V_65 ) ;
V_255 = F_154 ( V_55 -> V_65 ) ;
}
}
if ( ( V_41 & V_44 ) && F_44 ( V_2 ) ) {
if ( V_55 -> V_66 . V_71 != V_250 ) {
F_49 ( V_55 , V_258 ) ;
error = F_35 ( V_2 , NULL , V_250 ,
V_45 ,
V_68 |
V_61 ,
& V_256 ) ;
if ( error ) {
ASSERT ( error != - V_209 ) ;
goto V_248;
}
F_11 ( V_256 ) ;
V_258 = V_260 ;
F_48 ( V_55 , V_258 ) ;
} else {
ASSERT ( V_55 -> V_70 ) ;
V_256 = F_154 ( V_55 -> V_70 ) ;
}
}
if ( ( V_41 & V_46 ) && F_45 ( V_2 ) ) {
if ( F_46 ( V_55 ) != V_251 ) {
F_49 ( V_55 , V_258 ) ;
error = F_35 ( V_2 , NULL , ( T_5 ) V_251 ,
V_47 ,
V_68 |
V_61 ,
& V_257 ) ;
if ( error ) {
ASSERT ( error != - V_209 ) ;
goto V_248;
}
F_11 ( V_257 ) ;
V_258 = V_260 ;
F_48 ( V_55 , V_258 ) ;
} else {
ASSERT ( V_55 -> V_72 ) ;
V_257 = F_154 ( V_55 -> V_72 ) ;
}
}
if ( V_255 )
F_155 ( V_55 ) ;
F_49 ( V_55 , V_258 ) ;
if ( V_252 )
* V_252 = V_255 ;
else
F_51 ( V_255 ) ;
if ( V_253 )
* V_253 = V_256 ;
else
F_51 ( V_256 ) ;
if ( V_254 )
* V_254 = V_257 ;
else
F_51 ( V_257 ) ;
return 0 ;
V_248:
F_51 ( V_256 ) ;
F_51 ( V_255 ) ;
return error ;
}
T_6 *
F_156 (
T_10 * V_154 ,
T_4 * V_55 ,
T_6 * * V_261 ,
T_6 * V_262 )
{
T_6 * V_263 ;
T_2 V_264 = F_133 ( V_55 ) ?
V_265 : V_266 ;
ASSERT ( F_33 ( V_55 , V_59 ) ) ;
ASSERT ( F_38 ( V_55 -> V_60 ) ) ;
V_263 = * V_261 ;
ASSERT ( V_263 ) ;
ASSERT ( V_263 != V_262 ) ;
F_157 ( V_154 , V_263 , V_264 , - ( V_55 -> V_66 . V_195 ) ) ;
F_157 ( V_154 , V_263 , V_267 , - 1 ) ;
F_157 ( V_154 , V_262 , V_264 , V_55 -> V_66 . V_195 ) ;
F_157 ( V_154 , V_262 , V_267 , 1 ) ;
* V_261 = F_154 ( V_262 ) ;
return V_263 ;
}
int
F_158 (
struct V_268 * V_154 ,
struct V_62 * V_55 ,
struct V_3 * V_269 ,
struct V_3 * V_270 ,
struct V_3 * V_271 ,
T_2 V_41 )
{
struct V_1 * V_2 = V_55 -> V_60 ;
T_2 V_272 , V_273 , V_274 = 0 ;
struct V_3 * V_275 = NULL ;
struct V_3 * V_276 = NULL ;
struct V_3 * V_277 = NULL ;
struct V_3 * V_278 = NULL ;
struct V_3 * V_279 = NULL ;
struct V_3 * V_280 = NULL ;
int error ;
ASSERT ( F_33 ( V_55 , V_59 | V_260 ) ) ;
ASSERT ( F_38 ( V_2 ) ) ;
V_272 = V_55 -> V_221 ;
V_273 = F_133 ( V_55 ) ?
V_281 : V_282 ;
if ( F_43 ( V_2 ) && V_269 &&
V_55 -> V_66 . V_67 != F_7 ( V_269 -> V_20 . V_21 ) ) {
V_278 = V_269 ;
if ( V_272 ) {
ASSERT ( V_55 -> V_65 ) ;
V_275 = V_55 -> V_65 ;
}
}
if ( F_44 ( V_55 -> V_60 ) && V_270 &&
V_55 -> V_66 . V_71 != F_7 ( V_270 -> V_20 . V_21 ) ) {
V_279 = V_270 ;
if ( V_272 ) {
ASSERT ( V_55 -> V_70 ) ;
V_276 = V_55 -> V_70 ;
}
}
if ( F_45 ( V_55 -> V_60 ) && V_271 &&
F_46 ( V_55 ) != F_7 ( V_271 -> V_20 . V_21 ) ) {
V_274 = V_283 ;
V_280 = V_271 ;
if ( V_272 ) {
ASSERT ( V_55 -> V_72 ) ;
V_277 = V_55 -> V_72 ;
}
}
error = F_159 ( V_154 , V_55 -> V_60 ,
V_278 , V_279 , V_280 ,
V_55 -> V_66 . V_195 , 1 ,
V_41 | V_273 | V_274 ) ;
if ( error )
return error ;
if ( V_272 ) {
ASSERT ( V_278 || V_279 || V_280 ) ;
ASSERT ( V_275 || V_276 || V_277 ) ;
error = F_159 ( NULL , V_55 -> V_60 ,
V_278 , V_279 , V_280 ,
( T_16 ) V_272 , 0 ,
V_41 | V_273 | V_274 ) ;
if ( error )
return error ;
F_159 ( NULL , V_55 -> V_60 ,
V_275 , V_276 , V_277 ,
- ( ( T_16 ) V_272 ) , 0 , V_273 ) ;
}
return 0 ;
}
int
F_160 (
struct V_62 * * V_284 )
{
struct V_1 * V_2 = V_284 [ 0 ] -> V_60 ;
int V_18 ;
if ( ! F_38 ( V_2 ) || ! F_39 ( V_2 ) )
return 0 ;
for ( V_18 = 0 ; ( V_18 < 4 && V_284 [ V_18 ] ) ; V_18 ++ ) {
struct V_62 * V_55 = V_284 [ V_18 ] ;
int error ;
if ( V_18 == 0 || V_55 != V_284 [ V_18 - 1 ] ) {
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
F_161 (
struct V_268 * V_154 ,
struct V_62 * V_55 ,
struct V_3 * V_269 ,
struct V_3 * V_270 ,
struct V_3 * V_271 )
{
struct V_1 * V_2 = V_154 -> V_285 ;
if ( ! F_38 ( V_2 ) || ! F_39 ( V_2 ) )
return;
ASSERT ( F_33 ( V_55 , V_59 ) ) ;
ASSERT ( F_38 ( V_2 ) ) ;
if ( V_269 && F_43 ( V_2 ) ) {
ASSERT ( V_55 -> V_65 == NULL ) ;
ASSERT ( V_55 -> V_66 . V_67 == F_7 ( V_269 -> V_20 . V_21 ) ) ;
V_55 -> V_65 = F_154 ( V_269 ) ;
F_157 ( V_154 , V_269 , V_267 , 1 ) ;
}
if ( V_270 && F_44 ( V_2 ) ) {
ASSERT ( V_55 -> V_70 == NULL ) ;
ASSERT ( V_55 -> V_66 . V_71 == F_7 ( V_270 -> V_20 . V_21 ) ) ;
V_55 -> V_70 = F_154 ( V_270 ) ;
F_157 ( V_154 , V_270 , V_267 , 1 ) ;
}
if ( V_271 && F_45 ( V_2 ) ) {
ASSERT ( V_55 -> V_72 == NULL ) ;
ASSERT ( F_46 ( V_55 ) == F_7 ( V_271 -> V_20 . V_21 ) ) ;
V_55 -> V_72 = F_154 ( V_271 ) ;
F_157 ( V_154 , V_271 , V_267 , 1 ) ;
}
}
