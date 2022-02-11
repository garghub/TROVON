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
struct V_3 * V_26 = NULL ;
F_10 ( V_4 ) ;
if ( ( V_4 -> V_27 & V_28 ) || V_4 -> V_29 != 0 ) {
F_11 ( V_4 ) ;
return V_22 ;
}
V_25 = V_4 -> V_30 ;
if ( V_25 ) {
F_10 ( V_25 ) ;
V_4 -> V_30 = NULL ;
}
V_26 = V_4 -> V_31 ;
if ( V_26 ) {
F_10 ( V_26 ) ;
V_4 -> V_31 = NULL ;
}
V_4 -> V_27 |= V_28 ;
F_12 ( V_4 ) ;
if ( F_13 ( V_4 ) ) {
struct V_32 * V_33 = NULL ;
int error ;
error = F_14 ( V_4 , & V_33 ) ;
if ( error ) {
F_15 ( V_2 , L_1 ,
V_34 , V_4 ) ;
} else {
error = F_16 ( V_33 ) ;
F_17 ( V_33 ) ;
}
F_12 ( V_4 ) ;
}
ASSERT ( F_18 ( & V_4 -> V_35 ) == 0 ) ;
ASSERT ( F_19 ( V_2 ) ||
! ( V_4 -> V_36 . V_37 . V_38 & V_39 ) ) ;
F_20 ( V_4 ) ;
F_11 ( V_4 ) ;
F_21 ( F_3 ( V_7 , V_4 -> V_20 . V_40 ) ,
F_7 ( V_4 -> V_20 . V_21 ) ) ;
V_7 -> V_41 -- ;
F_4 ( & V_7 -> V_42 ) ;
ASSERT ( ! F_22 ( & V_4 -> V_43 ) ) ;
F_23 ( & V_4 -> V_43 ) ;
V_7 -> V_44 -- ;
F_24 ( V_45 ) ;
F_6 ( & V_7 -> V_42 ) ;
F_25 ( V_4 ) ;
if ( V_25 )
F_26 ( V_25 ) ;
if ( V_26 )
F_26 ( V_26 ) ;
return 0 ;
}
void
F_27 (
struct V_1 * V_2 ,
T_2 V_46 )
{
if ( V_46 & V_47 )
F_1 ( V_2 , V_48 , F_9 , NULL ) ;
if ( V_46 & V_49 )
F_1 ( V_2 , V_50 , F_9 , NULL ) ;
if ( V_46 & V_51 )
F_1 ( V_2 , V_52 , F_9 , NULL ) ;
}
void
F_28 (
struct V_1 * V_2 )
{
if ( V_2 -> V_8 ) {
F_27 ( V_2 , V_53 ) ;
F_29 ( V_2 ) ;
}
}
void
F_30 (
T_3 * V_2 )
{
int error = 0 ;
T_2 V_54 ;
if ( V_2 -> V_55 . V_56 ) {
F_31 ( V_2 , L_2 ) ;
V_2 -> V_57 = 0 ;
goto V_58;
}
ASSERT ( F_32 ( V_2 ) ) ;
error = F_33 ( V_2 ) ;
if ( error ) {
ASSERT ( V_2 -> V_8 == NULL ) ;
V_2 -> V_57 = 0 ;
goto V_58;
}
if ( F_34 ( V_2 ) ) {
error = F_35 ( V_2 ) ;
if ( error ) {
return;
}
}
if ( ! F_36 ( V_2 ) )
V_2 -> V_57 &= ~ V_59 ;
if ( ! F_37 ( V_2 ) )
V_2 -> V_57 &= ~ V_60 ;
if ( ! F_38 ( V_2 ) )
V_2 -> V_57 &= ~ V_61 ;
V_58:
F_39 ( & V_2 -> V_62 ) ;
V_54 = V_2 -> V_55 . V_63 ;
V_2 -> V_55 . V_63 = V_2 -> V_57 & V_64 ;
F_40 ( & V_2 -> V_62 ) ;
if ( V_54 != ( V_2 -> V_57 & V_64 ) ) {
if ( F_41 ( V_2 , V_65 ) ) {
ASSERT ( ! ( F_32 ( V_2 ) ) ) ;
F_42 ( V_2 , L_3 ,
V_34 ) ;
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
ASSERT ( V_2 -> V_66 ) ;
F_44 ( V_2 -> V_66 ) ;
if ( V_2 -> V_67 )
F_44 ( V_2 -> V_67 ) ;
if ( V_2 -> V_68 )
F_44 ( V_2 -> V_68 ) ;
if ( V_2 -> V_8 ) {
if ( V_2 -> V_8 -> V_69 ) {
F_45 ( V_2 -> V_8 -> V_69 ) ;
V_2 -> V_8 -> V_69 = NULL ;
}
if ( V_2 -> V_8 -> V_70 ) {
F_45 ( V_2 -> V_8 -> V_70 ) ;
V_2 -> V_8 -> V_70 = NULL ;
}
if ( V_2 -> V_8 -> V_71 ) {
F_45 ( V_2 -> V_8 -> V_71 ) ;
V_2 -> V_8 -> V_71 = NULL ;
}
}
}
STATIC int
F_46 (
T_4 * V_72 ,
T_5 V_73 ,
T_2 type ,
T_2 V_74 ,
T_6 * V_75 ,
T_6 * * V_76 )
{
T_6 * V_4 ;
int error ;
ASSERT ( F_47 ( V_72 , V_77 ) ) ;
error = 0 ;
V_4 = * V_76 ;
if ( V_4 ) {
F_48 ( V_4 ) ;
return 0 ;
}
if ( V_75 ) {
ASSERT ( type == V_50 || type == V_52 ) ;
F_10 ( V_75 ) ;
if ( type == V_50 )
V_4 = V_75 -> V_30 ;
else
V_4 = V_75 -> V_31 ;
if ( V_4 && F_7 ( V_4 -> V_20 . V_21 ) == V_73 ) {
ASSERT ( * V_76 == NULL ) ;
* V_76 = F_49 ( V_4 ) ;
F_11 ( V_75 ) ;
return 0 ;
}
F_11 ( V_75 ) ;
}
error = F_50 ( V_72 -> V_78 , V_72 , V_73 , type ,
V_74 | V_79 , & V_4 ) ;
if ( error )
return error ;
F_51 ( V_4 ) ;
* V_76 = V_4 ;
F_11 ( V_4 ) ;
return 0 ;
}
STATIC void
F_52 (
struct V_80 * V_72 ,
int type )
{
struct V_3 * * V_81 ;
struct V_3 * V_4 ;
struct V_3 * V_82 = V_72 -> V_83 ;
ASSERT ( type == V_50 || type == V_52 ) ;
F_10 ( V_82 ) ;
if ( type == V_50 ) {
V_4 = V_72 -> V_84 ;
V_81 = & V_82 -> V_30 ;
} else {
V_4 = V_72 -> V_85 ;
V_81 = & V_82 -> V_31 ;
}
if ( * V_81 ) {
struct V_3 * V_86 ;
if ( * V_81 == V_4 )
goto V_87;
V_86 = * V_81 ;
* V_81 = NULL ;
F_53 ( V_86 ) ;
}
* V_81 = F_49 ( V_4 ) ;
V_87:
F_11 ( V_82 ) ;
}
static bool
F_54 (
struct V_80 * V_72 )
{
struct V_1 * V_2 = V_72 -> V_78 ;
if ( ! F_32 ( V_2 ) )
return false ;
if ( ! F_55 ( V_2 ) )
return false ;
if ( ! F_56 ( V_2 , V_72 ) )
return false ;
if ( F_57 ( & V_2 -> V_55 , V_72 -> V_88 ) )
return false ;
return true ;
}
int
F_58 (
T_4 * V_72 ,
T_2 V_46 )
{
T_3 * V_2 = V_72 -> V_78 ;
T_2 V_89 = 0 ;
int error = 0 ;
if ( ! F_54 ( V_72 ) )
return 0 ;
ASSERT ( F_47 ( V_72 , V_77 ) ) ;
if ( F_36 ( V_2 ) ) {
error = F_46 ( V_72 , V_72 -> V_90 . V_91 , V_48 ,
V_46 & V_92 ,
NULL , & V_72 -> V_83 ) ;
if ( error )
goto V_87;
V_89 ++ ;
}
ASSERT ( F_47 ( V_72 , V_77 ) ) ;
if ( F_37 ( V_2 ) ) {
error = F_46 ( V_72 , V_72 -> V_90 . V_93 , V_50 ,
V_46 & V_92 ,
V_72 -> V_83 , & V_72 -> V_84 ) ;
if ( error )
goto V_87;
V_89 ++ ;
}
ASSERT ( F_47 ( V_72 , V_77 ) ) ;
if ( F_38 ( V_2 ) ) {
error = F_46 ( V_72 , F_59 ( V_72 ) , V_52 ,
V_46 & V_92 ,
V_72 -> V_83 , & V_72 -> V_85 ) ;
if ( error )
goto V_87;
V_89 ++ ;
}
if ( V_89 > 1 && V_72 -> V_83 ) {
ASSERT ( F_47 ( V_72 , V_77 ) ) ;
ASSERT ( V_72 -> V_84 || ! F_37 ( V_2 ) ) ;
ASSERT ( V_72 -> V_85 || ! F_38 ( V_2 ) ) ;
if ( V_72 -> V_83 -> V_30 != V_72 -> V_84 )
F_52 ( V_72 , V_50 ) ;
if ( V_72 -> V_83 -> V_31 != V_72 -> V_85 )
F_52 ( V_72 , V_52 ) ;
}
V_87:
#ifdef F_60
if ( ! error ) {
if ( F_36 ( V_2 ) )
ASSERT ( V_72 -> V_83 ) ;
if ( F_37 ( V_2 ) )
ASSERT ( V_72 -> V_84 ) ;
if ( F_38 ( V_2 ) )
ASSERT ( V_72 -> V_85 ) ;
}
ASSERT ( F_47 ( V_72 , V_77 ) ) ;
#endif
return error ;
}
int
F_61 (
struct V_80 * V_72 ,
T_2 V_46 )
{
int error ;
if ( ! F_54 ( V_72 ) )
return 0 ;
F_62 ( V_72 , V_77 ) ;
error = F_58 ( V_72 , V_46 ) ;
F_63 ( V_72 , V_77 ) ;
return error ;
}
void
F_44 (
T_4 * V_72 )
{
if ( ! ( V_72 -> V_83 || V_72 -> V_84 || V_72 -> V_85 ) )
return;
F_64 ( V_72 ) ;
ASSERT ( ! F_57 ( & V_72 -> V_78 -> V_55 , V_72 -> V_88 ) ) ;
if ( V_72 -> V_83 ) {
F_53 ( V_72 -> V_83 ) ;
V_72 -> V_83 = NULL ;
}
if ( V_72 -> V_84 ) {
F_53 ( V_72 -> V_84 ) ;
V_72 -> V_84 = NULL ;
}
if ( V_72 -> V_85 ) {
F_53 ( V_72 -> V_85 ) ;
V_72 -> V_85 = NULL ;
}
}
int
F_65 (
struct V_1 * V_2 ,
unsigned int V_94 )
{
unsigned int V_95 ;
ASSERT ( V_94 > 0 ) ;
V_95 = F_66 ( V_94 ) ;
F_67 ( V_95 , sizeof( V_96 ) ) ;
return V_95 ;
}
STATIC int
F_33 (
T_3 * V_2 )
{
T_7 * V_97 ;
int error ;
T_6 * V_4 ;
ASSERT ( F_32 ( V_2 ) ) ;
V_97 = V_2 -> V_8 = F_68 ( sizeof( T_7 ) , V_98 ) ;
if ( ( error = F_69 ( V_2 ) ) ) {
F_70 ( V_97 ) ;
V_2 -> V_8 = NULL ;
return error ;
}
F_71 ( & V_97 -> V_99 , V_100 ) ;
F_71 ( & V_97 -> V_101 , V_100 ) ;
F_71 ( & V_97 -> V_102 , V_100 ) ;
F_72 ( & V_97 -> V_19 ) ;
F_73 ( & V_97 -> V_103 ) ;
V_97 -> V_44 = 0 ;
F_72 ( & V_97 -> V_42 ) ;
F_72 ( & V_97 -> V_104 ) ;
V_97 -> V_105 = F_74 ( V_2 , V_106 ) ;
V_97 -> V_107 = F_65 ( V_2 ,
V_97 -> V_105 ) ;
V_2 -> V_57 |= ( V_2 -> V_55 . V_63 & V_108 ) ;
error = F_75 ( V_2 , 0 ,
F_76 ( V_2 ) ? V_48 :
( F_77 ( V_2 ) ? V_50 :
V_52 ) ,
V_79 , & V_4 ) ;
if ( ! error ) {
T_8 * V_109 = & V_4 -> V_20 ;
V_97 -> V_110 = V_109 -> V_111 ?
F_7 ( V_109 -> V_111 ) : V_112 ;
V_97 -> V_113 = V_109 -> V_114 ?
F_7 ( V_109 -> V_114 ) : V_115 ;
V_97 -> V_116 = V_109 -> V_117 ?
F_7 ( V_109 -> V_117 ) : V_118 ;
V_97 -> V_119 = V_109 -> V_120 ?
F_78 ( V_109 -> V_120 ) : V_121 ;
V_97 -> V_122 = V_109 -> V_123 ?
F_78 ( V_109 -> V_123 ) : V_124 ;
V_97 -> V_125 = V_109 -> V_126 ?
F_78 ( V_109 -> V_126 ) : V_127 ;
V_97 -> V_128 = F_79 ( V_109 -> V_129 ) ;
V_97 -> V_130 = F_79 ( V_109 -> V_131 ) ;
V_97 -> V_132 = F_79 ( V_109 -> V_133 ) ;
V_97 -> V_134 = F_79 ( V_109 -> V_135 ) ;
V_97 -> V_136 = F_79 ( V_109 -> V_137 ) ;
V_97 -> V_138 = F_79 ( V_109 -> V_139 ) ;
F_25 ( V_4 ) ;
} else {
V_97 -> V_110 = V_112 ;
V_97 -> V_113 = V_115 ;
V_97 -> V_116 = V_118 ;
V_97 -> V_119 = V_121 ;
V_97 -> V_122 = V_124 ;
V_97 -> V_125 = V_127 ;
}
V_97 -> V_140 . V_141 = V_142 ;
V_97 -> V_140 . V_143 = V_144 ;
F_80 ( & V_97 -> V_140 ) ;
return 0 ;
}
void
F_29 (
T_3 * V_2 )
{
T_7 * V_7 ;
V_7 = V_2 -> V_8 ;
ASSERT ( V_7 != NULL ) ;
F_81 ( & V_7 -> V_140 ) ;
if ( V_7 -> V_69 ) {
F_45 ( V_7 -> V_69 ) ;
V_7 -> V_69 = NULL ;
}
if ( V_7 -> V_70 ) {
F_45 ( V_7 -> V_70 ) ;
V_7 -> V_70 = NULL ;
}
if ( V_7 -> V_71 ) {
F_45 ( V_7 -> V_71 ) ;
V_7 -> V_71 = NULL ;
}
F_82 ( & V_7 -> V_104 ) ;
F_70 ( V_7 ) ;
V_2 -> V_8 = NULL ;
}
STATIC int
F_83 (
T_3 * V_2 ,
T_4 * * V_72 ,
T_9 V_145 ,
T_2 V_46 )
{
T_10 * V_146 ;
int error ;
int V_147 ;
V_146 = F_84 ( V_2 , V_148 ) ;
if ( ( error = F_85 ( V_146 ,
F_86 ( V_2 ) ,
F_87 ( V_2 ) , 0 ,
V_149 ,
V_150 ) ) ) {
F_88 ( V_146 , 0 ) ;
return error ;
}
error = F_89 ( & V_146 , NULL , V_151 , 1 , 0 , 0 , 1 , V_72 , & V_147 ) ;
if ( error ) {
F_88 ( V_146 , V_152 |
V_153 ) ;
return error ;
}
F_39 ( & V_2 -> V_62 ) ;
if ( V_46 & V_154 ) {
ASSERT ( ! F_90 ( & V_2 -> V_55 ) ) ;
ASSERT ( ( V_145 & ( V_155 | V_156 |
V_157 | V_65 ) ) ==
( V_155 | V_156 |
V_157 | V_65 ) ) ;
F_91 ( & V_2 -> V_55 ) ;
V_2 -> V_55 . V_158 = V_159 ;
V_2 -> V_55 . V_160 = V_159 ;
V_2 -> V_55 . V_63 = 0 ;
}
if ( V_46 & V_47 )
V_2 -> V_55 . V_158 = ( * V_72 ) -> V_88 ;
else
V_2 -> V_55 . V_160 = ( * V_72 ) -> V_88 ;
F_40 ( & V_2 -> V_62 ) ;
F_92 ( V_146 , V_145 ) ;
if ( ( error = F_93 ( V_146 , V_152 ) ) ) {
F_42 ( V_2 , L_5 , V_34 , error ) ;
return error ;
}
return 0 ;
}
STATIC void
F_94 (
T_3 * V_2 ,
T_11 * V_33 ,
T_5 V_73 ,
T_2 type )
{
struct V_161 * V_162 ;
int V_163 ;
F_95 ( V_33 , V_164 ) ;
#ifdef F_60
V_163 = F_96 ( V_2 , V_106 ) ;
F_67 ( V_163 , sizeof( V_96 ) ) ;
ASSERT ( V_2 -> V_8 -> V_107 == V_163 ) ;
#endif
V_162 = V_33 -> V_165 ;
for ( V_163 = 0 ; V_163 < V_2 -> V_8 -> V_107 ; V_163 ++ ) {
struct V_166 * V_167 ;
V_167 = (struct V_166 * ) & V_162 [ V_163 ] ;
( void ) F_97 ( V_2 , V_167 , V_73 + V_163 , type , V_168 ,
L_6 ) ;
V_167 -> V_169 = 0 ;
V_167 -> V_170 = 0 ;
V_167 -> V_171 = 0 ;
V_167 -> V_111 = 0 ;
V_167 -> V_114 = 0 ;
V_167 -> V_117 = 0 ;
V_167 -> V_120 = 0 ;
V_167 -> V_123 = 0 ;
V_167 -> V_126 = 0 ;
if ( F_98 ( & V_2 -> V_55 ) ) {
F_99 ( ( char * ) & V_162 [ V_163 ] ,
sizeof( struct V_161 ) ,
V_172 ) ;
}
}
}
STATIC int
F_100 (
struct V_1 * V_2 ,
T_5 V_173 ,
T_12 V_174 ,
T_13 V_175 ,
T_2 V_46 ,
struct V_176 * V_177 )
{
struct V_32 * V_33 ;
int error ;
int type ;
ASSERT ( V_175 > 0 ) ;
type = V_46 & V_47 ? V_48 :
( V_46 & V_51 ? V_52 : V_50 ) ;
error = 0 ;
while ( V_175 -- ) {
error = F_101 ( V_2 , NULL , V_2 -> V_178 ,
F_102 ( V_2 , V_174 ) ,
V_2 -> V_8 -> V_105 , 0 , & V_33 ,
& V_179 ) ;
if ( error == V_23 ) {
error = F_101 ( V_2 , NULL , V_2 -> V_178 ,
F_102 ( V_2 , V_174 ) ,
V_2 -> V_8 -> V_105 , 0 , & V_33 ,
NULL ) ;
}
if ( error )
break;
F_94 ( V_2 , V_33 , V_173 , type ) ;
F_103 ( V_33 , V_177 ) ;
F_17 ( V_33 ) ;
V_174 ++ ;
V_173 += V_2 -> V_8 -> V_107 ;
}
return error ;
}
STATIC int
F_104 (
struct V_1 * V_2 ,
struct V_80 * V_180 ,
T_2 V_46 ,
struct V_176 * V_177 )
{
struct V_181 * V_182 ;
int V_18 , V_183 ;
int error ;
T_14 V_184 ;
T_13 V_185 ;
T_5 V_173 ;
T_12 V_186 ;
T_13 V_187 ;
error = 0 ;
if ( V_180 -> V_90 . V_188 == 0 )
return 0 ;
V_182 = F_105 ( V_189 * sizeof( * V_182 ) , V_98 ) ;
V_184 = 0 ;
V_185 = F_106 ( V_2 , V_2 -> V_190 -> V_191 ) ;
do {
V_183 = V_189 ;
F_62 ( V_180 , V_192 ) ;
error = F_107 ( V_180 , V_184 , V_185 - V_184 ,
V_182 , & V_183 , 0 ) ;
F_63 ( V_180 , V_192 ) ;
if ( error )
break;
ASSERT ( V_183 <= V_189 ) ;
for ( V_18 = 0 ; V_18 < V_183 ; V_18 ++ ) {
ASSERT ( V_182 [ V_18 ] . V_193 != V_194 ) ;
ASSERT ( V_182 [ V_18 ] . V_195 ) ;
V_184 += V_182 [ V_18 ] . V_195 ;
if ( V_182 [ V_18 ] . V_193 == V_196 )
continue;
V_173 = ( T_5 ) V_182 [ V_18 ] . V_197 *
V_2 -> V_8 -> V_107 ;
if ( ( V_18 + 1 < V_183 ) &&
( V_182 [ V_18 + 1 ] . V_193 != V_196 ) ) {
V_187 = V_182 [ V_18 + 1 ] . V_195 ;
V_186 = V_182 [ V_18 + 1 ] . V_193 ;
while ( V_187 -- ) {
F_108 ( V_2 -> V_178 ,
F_102 ( V_2 , V_186 ) ,
V_2 -> V_8 -> V_105 ,
NULL ) ;
V_186 ++ ;
}
}
error = F_100 ( V_2 , V_173 ,
V_182 [ V_18 ] . V_193 ,
V_182 [ V_18 ] . V_195 ,
V_46 , V_177 ) ;
if ( error )
goto V_198;
}
} while ( V_183 > 0 );
V_198:
F_70 ( V_182 ) ;
return error ;
}
STATIC int
F_109 (
struct V_80 * V_72 ,
T_5 V_73 ,
T_2 type ,
T_15 V_199 ,
T_15 V_200 )
{
struct V_1 * V_2 = V_72 -> V_78 ;
struct V_3 * V_4 ;
int error ;
error = F_50 ( V_2 , V_72 , V_73 , type ,
V_92 | V_79 , & V_4 ) ;
if ( error ) {
ASSERT ( error != V_201 ) ;
ASSERT ( error != V_202 ) ;
return error ;
}
F_110 ( V_4 ) ;
F_111 ( & V_4 -> V_20 . V_170 , 1 ) ;
V_4 -> V_203 ++ ;
if ( V_199 ) {
F_111 ( & V_4 -> V_20 . V_169 , V_199 ) ;
V_4 -> V_204 += V_199 ;
}
if ( V_200 ) {
F_111 ( & V_4 -> V_20 . V_171 , V_200 ) ;
V_4 -> V_205 += V_200 ;
}
if ( V_4 -> V_20 . V_21 ) {
F_112 ( V_2 , V_4 ) ;
F_113 ( V_2 , & V_4 -> V_20 ) ;
}
V_4 -> V_27 |= V_206 ;
F_26 ( V_4 ) ;
return 0 ;
}
STATIC int
F_114 (
T_4 * V_72 ,
T_15 * V_207 )
{
T_13 V_200 ;
T_16 V_208 ;
T_17 * V_209 ;
T_16 V_210 ;
int error ;
ASSERT ( F_115 ( V_72 ) ) ;
V_209 = F_116 ( V_72 , V_211 ) ;
if ( ! ( V_209 -> V_212 & V_213 ) ) {
if ( ( error = F_117 ( NULL , V_72 , V_211 ) ) )
return error ;
}
V_200 = 0 ;
V_210 = V_209 -> V_214 / ( T_2 ) sizeof( V_215 ) ;
for ( V_208 = 0 ; V_208 < V_210 ; V_208 ++ )
V_200 += F_118 ( F_119 ( V_209 , V_208 ) ) ;
* V_207 = ( T_15 ) V_200 ;
return 0 ;
}
STATIC int
F_120 (
T_3 * V_2 ,
T_18 V_216 ,
void T_19 * V_217 ,
int V_218 ,
int * V_219 ,
int * V_220 )
{
T_4 * V_72 ;
T_15 V_199 , V_200 = 0 ;
int error ;
ASSERT ( F_32 ( V_2 ) ) ;
if ( F_57 ( & V_2 -> V_55 , V_216 ) ) {
* V_220 = V_221 ;
return F_121 ( V_222 ) ;
}
error = F_122 ( V_2 , NULL , V_216 , 0 , V_77 , & V_72 ) ;
if ( error ) {
* V_220 = V_221 ;
return error ;
}
ASSERT ( V_72 -> V_223 == 0 ) ;
if ( F_115 ( V_72 ) ) {
error = F_114 ( V_72 , & V_200 ) ;
if ( error )
goto V_224;
}
V_199 = ( T_15 ) V_72 -> V_90 . V_188 - V_200 ;
if ( F_36 ( V_2 ) ) {
error = F_109 ( V_72 , V_72 -> V_90 . V_91 ,
V_48 , V_199 , V_200 ) ;
if ( error )
goto V_224;
}
if ( F_37 ( V_2 ) ) {
error = F_109 ( V_72 , V_72 -> V_90 . V_93 ,
V_50 , V_199 , V_200 ) ;
if ( error )
goto V_224;
}
if ( F_38 ( V_2 ) ) {
error = F_109 ( V_72 , F_59 ( V_72 ) ,
V_52 , V_199 , V_200 ) ;
if ( error )
goto V_224;
}
F_63 ( V_72 , V_77 ) ;
F_45 ( V_72 ) ;
* V_220 = V_225 ;
return 0 ;
V_224:
F_63 ( V_72 , V_77 ) ;
F_45 ( V_72 ) ;
* V_220 = V_226 ;
return error ;
}
STATIC int
F_123 (
struct V_3 * V_4 ,
void * V_5 )
{
struct V_176 * V_177 = V_5 ;
struct V_32 * V_33 = NULL ;
int error = 0 ;
F_10 ( V_4 ) ;
if ( V_4 -> V_27 & V_28 )
goto V_227;
if ( ! F_13 ( V_4 ) )
goto V_227;
F_12 ( V_4 ) ;
error = F_14 ( V_4 , & V_33 ) ;
if ( error )
goto V_227;
F_103 ( V_33 , V_177 ) ;
F_17 ( V_33 ) ;
V_227:
F_11 ( V_4 ) ;
return error ;
}
int
F_35 (
T_3 * V_2 )
{
int V_87 , V_228 , error , V_229 ;
T_18 V_230 ;
T_20 V_231 ;
T_2 V_46 ;
F_124 ( V_177 ) ;
struct V_80 * V_232 = V_2 -> V_8 -> V_69 ;
struct V_80 * V_233 = V_2 -> V_8 -> V_70 ;
struct V_80 * V_234 = V_2 -> V_8 -> V_71 ;
V_228 = V_235 ;
V_231 = 1 ;
V_230 = 0 ;
V_46 = 0 ;
ASSERT ( V_232 || V_233 || V_234 ) ;
ASSERT ( F_32 ( V_2 ) ) ;
F_31 ( V_2 , L_7 ) ;
if ( V_232 ) {
error = F_104 ( V_2 , V_232 , V_47 ,
& V_177 ) ;
if ( error )
goto V_236;
V_46 |= V_59 ;
}
if ( V_233 ) {
error = F_104 ( V_2 , V_233 , V_49 ,
& V_177 ) ;
if ( error )
goto V_236;
V_46 |= V_60 ;
}
if ( V_234 ) {
error = F_104 ( V_2 , V_234 , V_51 ,
& V_177 ) ;
if ( error )
goto V_236;
V_46 |= V_61 ;
}
do {
error = F_125 ( V_2 , & V_230 , & V_228 ,
F_120 ,
V_231 , NULL , & V_87 ) ;
if ( error )
break;
} while ( ! V_87 );
if ( F_36 ( V_2 ) ) {
error = F_1 ( V_2 , V_48 , F_123 ,
& V_177 ) ;
}
if ( F_37 ( V_2 ) ) {
V_229 = F_1 ( V_2 , V_50 , F_123 ,
& V_177 ) ;
if ( ! error )
error = V_229 ;
}
if ( F_38 ( V_2 ) ) {
V_229 = F_1 ( V_2 , V_52 , F_123 ,
& V_177 ) ;
if ( ! error )
error = V_229 ;
}
V_229 = F_126 ( & V_177 ) ;
if ( ! error )
error = V_229 ;
if ( error ) {
F_27 ( V_2 , V_53 ) ;
goto V_236;
}
V_2 -> V_57 &= ~ V_108 ;
V_2 -> V_57 |= V_46 ;
V_236:
while ( ! F_22 ( & V_177 ) ) {
struct V_32 * V_33 =
F_127 ( & V_177 , struct V_32 , V_237 ) ;
F_23 ( & V_33 -> V_237 ) ;
F_17 ( V_33 ) ;
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
struct V_80 * V_232 = NULL ;
struct V_80 * V_233 = NULL ;
struct V_80 * V_234 = NULL ;
int error ;
T_9 V_238 = 0 ;
T_2 V_46 = 0 ;
ASSERT ( V_2 -> V_8 ) ;
if ( F_90 ( & V_2 -> V_55 ) ) {
if ( F_36 ( V_2 ) &&
V_2 -> V_55 . V_158 != V_159 ) {
ASSERT ( V_2 -> V_55 . V_158 > 0 ) ;
error = F_122 ( V_2 , NULL , V_2 -> V_55 . V_158 ,
0 , 0 , & V_232 ) ;
if ( error )
return F_121 ( error ) ;
}
if ( F_37 ( V_2 ) &&
V_2 -> V_55 . V_160 != V_159 ) {
ASSERT ( V_2 -> V_55 . V_160 > 0 ) ;
error = F_122 ( V_2 , NULL , V_2 -> V_55 . V_160 ,
0 , 0 , & V_233 ) ;
if ( error )
goto V_239;
}
if ( F_38 ( V_2 ) &&
V_2 -> V_55 . V_160 != V_159 ) {
ASSERT ( V_2 -> V_55 . V_160 > 0 ) ;
error = F_122 ( V_2 , NULL , V_2 -> V_55 . V_160 ,
0 , 0 , & V_234 ) ;
if ( error )
goto V_239;
}
} else {
V_46 |= V_154 ;
V_238 |= ( V_155 | V_156 |
V_157 | V_65 ) ;
}
if ( F_36 ( V_2 ) && V_232 == NULL ) {
error = F_83 ( V_2 , & V_232 ,
V_238 | V_156 ,
V_46 | V_47 ) ;
if ( error )
goto V_239;
V_46 &= ~ V_154 ;
}
if ( F_37 ( V_2 ) && V_233 == NULL ) {
error = F_83 ( V_2 , & V_233 ,
V_238 | V_157 ,
V_46 | V_49 ) ;
if ( error )
goto V_239;
V_46 &= ~ V_154 ;
}
if ( F_38 ( V_2 ) && V_234 == NULL ) {
error = F_83 ( V_2 , & V_234 ,
V_238 | V_157 ,
V_46 | V_51 ) ;
if ( error )
goto V_239;
}
V_2 -> V_8 -> V_69 = V_232 ;
V_2 -> V_8 -> V_70 = V_233 ;
V_2 -> V_8 -> V_71 = V_234 ;
return 0 ;
V_239:
if ( V_232 )
F_45 ( V_232 ) ;
if ( V_233 )
F_45 ( V_233 ) ;
if ( V_234 )
F_45 ( V_234 ) ;
return F_121 ( error ) ;
}
STATIC void
F_129 (
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_24 ;
struct V_6 * V_7 = V_2 -> V_8 ;
F_4 ( & V_7 -> V_19 ) ;
F_21 ( F_3 ( V_7 , V_4 -> V_20 . V_40 ) ,
F_7 ( V_4 -> V_20 . V_21 ) ) ;
V_7 -> V_41 -- ;
F_6 ( & V_7 -> V_19 ) ;
F_25 ( V_4 ) ;
}
STATIC void
F_130 (
struct V_3 * V_4 ,
struct V_176 * V_177 ,
struct V_176 * V_240 )
{
struct V_1 * V_2 = V_4 -> V_24 ;
struct V_6 * V_7 = V_2 -> V_8 ;
int error ;
if ( ! F_131 ( V_4 ) )
goto V_241;
if ( V_4 -> V_29 ) {
F_11 ( V_4 ) ;
F_132 ( V_4 ) ;
F_133 ( V_242 ) ;
F_23 ( & V_4 -> V_43 ) ;
V_7 -> V_44 -- ;
F_24 ( V_45 ) ;
return;
}
if ( ! F_134 ( V_4 ) )
goto V_243;
if ( F_13 ( V_4 ) ) {
struct V_32 * V_33 = NULL ;
F_135 ( V_4 ) ;
error = F_14 ( V_4 , & V_33 ) ;
if ( error ) {
F_15 ( V_2 , L_1 ,
V_34 , V_4 ) ;
goto V_243;
}
F_103 ( V_33 , V_177 ) ;
F_17 ( V_33 ) ;
goto V_243;
}
F_20 ( V_4 ) ;
V_4 -> V_27 |= V_28 ;
F_11 ( V_4 ) ;
ASSERT ( V_4 -> V_29 == 0 ) ;
F_136 ( & V_4 -> V_43 , V_240 ) ;
V_7 -> V_44 -- ;
F_24 ( V_45 ) ;
F_137 ( V_4 ) ;
F_133 ( V_244 ) ;
return;
V_243:
F_11 ( V_4 ) ;
V_241:
F_136 ( & V_4 -> V_43 , & V_7 -> V_103 ) ;
F_138 ( V_4 ) ;
F_133 ( V_245 ) ;
}
STATIC int
V_142 (
struct V_246 * V_141 ,
struct V_247 * V_248 )
{
struct V_6 * V_7 =
F_139 ( V_141 , struct V_6 , V_140 ) ;
int V_249 = V_248 -> V_249 ;
F_124 ( V_177 ) ;
F_124 ( V_240 ) ;
struct V_3 * V_4 ;
int error ;
if ( ( V_248 -> V_250 & ( V_251 | V_252 ) ) != ( V_251 | V_252 ) )
return 0 ;
if ( ! V_249 )
goto V_198;
F_4 ( & V_7 -> V_42 ) ;
while ( ! F_22 ( & V_7 -> V_103 ) ) {
if ( V_249 -- <= 0 )
break;
V_4 = F_127 ( & V_7 -> V_103 , struct V_3 ,
V_43 ) ;
F_130 ( V_4 , & V_177 , & V_240 ) ;
}
F_6 ( & V_7 -> V_42 ) ;
error = F_126 ( & V_177 ) ;
if ( error )
F_15 ( NULL , L_11 , V_34 ) ;
while ( ! F_22 ( & V_240 ) ) {
V_4 = F_127 ( & V_240 , struct V_3 , V_43 ) ;
F_23 ( & V_4 -> V_43 ) ;
F_129 ( V_4 ) ;
}
V_198:
return ( V_7 -> V_44 / 100 ) * V_253 ;
}
int
F_41 (
T_3 * V_2 ,
T_9 V_46 )
{
T_10 * V_146 ;
int error ;
V_146 = F_84 ( V_2 , V_254 ) ;
error = F_85 ( V_146 , 0 , F_140 ( V_2 ) ,
0 , 0 , V_255 ) ;
if ( error ) {
F_88 ( V_146 , 0 ) ;
return error ;
}
F_92 ( V_146 , V_46 ) ;
error = F_93 ( V_146 , 0 ) ;
return error ;
}
int
F_141 (
struct V_80 * V_72 ,
T_21 V_256 ,
T_22 V_257 ,
T_23 V_258 ,
T_2 V_46 ,
struct V_3 * * V_259 ,
struct V_3 * * V_260 ,
struct V_3 * * V_261 )
{
struct V_1 * V_2 = V_72 -> V_78 ;
struct V_3 * V_262 = NULL ;
struct V_3 * V_263 = NULL ;
struct V_3 * V_264 = NULL ;
int error ;
T_2 V_265 ;
if ( ! F_32 ( V_2 ) || ! F_55 ( V_2 ) )
return 0 ;
V_265 = V_77 ;
F_62 ( V_72 , V_265 ) ;
if ( ( V_46 & V_266 ) && F_142 ( V_72 ) )
V_257 = V_72 -> V_90 . V_93 ;
if ( F_56 ( V_2 , V_72 ) ) {
error = F_58 ( V_72 , V_92 ) ;
if ( error ) {
F_63 ( V_72 , V_265 ) ;
return error ;
}
}
if ( ( V_46 & V_47 ) && F_36 ( V_2 ) ) {
if ( V_72 -> V_90 . V_91 != V_256 ) {
F_63 ( V_72 , V_265 ) ;
error = F_50 ( V_2 , NULL , ( T_5 ) V_256 ,
V_48 ,
V_92 |
V_79 ,
& V_262 ) ;
if ( error ) {
ASSERT ( error != V_202 ) ;
return error ;
}
F_11 ( V_262 ) ;
V_265 = V_192 ;
F_62 ( V_72 , V_265 ) ;
} else {
ASSERT ( V_72 -> V_83 ) ;
V_262 = F_49 ( V_72 -> V_83 ) ;
}
}
if ( ( V_46 & V_49 ) && F_37 ( V_2 ) ) {
if ( V_72 -> V_90 . V_93 != V_257 ) {
F_63 ( V_72 , V_265 ) ;
error = F_50 ( V_2 , NULL , ( T_5 ) V_257 ,
V_50 ,
V_92 |
V_79 ,
& V_263 ) ;
if ( error ) {
ASSERT ( error != V_202 ) ;
goto V_239;
}
F_11 ( V_263 ) ;
V_265 = V_192 ;
F_62 ( V_72 , V_265 ) ;
} else {
ASSERT ( V_72 -> V_84 ) ;
V_263 = F_49 ( V_72 -> V_84 ) ;
}
}
if ( ( V_46 & V_51 ) && F_38 ( V_2 ) ) {
if ( F_59 ( V_72 ) != V_258 ) {
F_63 ( V_72 , V_265 ) ;
error = F_50 ( V_2 , NULL , ( T_5 ) V_258 ,
V_52 ,
V_92 |
V_79 ,
& V_264 ) ;
if ( error ) {
ASSERT ( error != V_202 ) ;
goto V_239;
}
F_11 ( V_264 ) ;
V_265 = V_192 ;
F_62 ( V_72 , V_265 ) ;
} else {
ASSERT ( V_72 -> V_85 ) ;
V_264 = F_49 ( V_72 -> V_85 ) ;
}
}
if ( V_262 )
F_143 ( V_72 ) ;
F_63 ( V_72 , V_265 ) ;
if ( V_259 )
* V_259 = V_262 ;
else if ( V_262 )
F_53 ( V_262 ) ;
if ( V_260 )
* V_260 = V_263 ;
else if ( V_263 )
F_53 ( V_263 ) ;
if ( V_261 )
* V_261 = V_264 ;
else if ( V_264 )
F_53 ( V_264 ) ;
return 0 ;
V_239:
if ( V_263 )
F_53 ( V_263 ) ;
if ( V_262 )
F_53 ( V_262 ) ;
return error ;
}
T_6 *
F_144 (
T_10 * V_146 ,
T_4 * V_72 ,
T_6 * * V_267 ,
T_6 * V_268 )
{
T_6 * V_269 ;
T_2 V_270 = F_115 ( V_72 ) ?
V_271 : V_272 ;
ASSERT ( F_47 ( V_72 , V_77 ) ) ;
ASSERT ( F_32 ( V_72 -> V_78 ) ) ;
V_269 = * V_267 ;
ASSERT ( V_269 ) ;
ASSERT ( V_269 != V_268 ) ;
F_145 ( V_146 , V_269 , V_270 , - ( V_72 -> V_90 . V_188 ) ) ;
F_145 ( V_146 , V_269 , V_273 , - 1 ) ;
F_145 ( V_146 , V_268 , V_270 , V_72 -> V_90 . V_188 ) ;
F_145 ( V_146 , V_268 , V_273 , 1 ) ;
* V_267 = F_49 ( V_268 ) ;
return V_269 ;
}
int
F_146 (
struct V_274 * V_146 ,
struct V_80 * V_72 ,
struct V_3 * V_275 ,
struct V_3 * V_25 ,
struct V_3 * V_26 ,
T_2 V_46 )
{
struct V_1 * V_2 = V_72 -> V_78 ;
T_2 V_276 , V_277 , V_278 = 0 ;
struct V_3 * V_279 = NULL ;
struct V_3 * V_280 = NULL ;
struct V_3 * V_281 = NULL ;
struct V_3 * V_282 = NULL ;
struct V_3 * V_283 = NULL ;
struct V_3 * V_284 = NULL ;
int error ;
ASSERT ( F_47 ( V_72 , V_77 | V_192 ) ) ;
ASSERT ( F_32 ( V_2 ) ) ;
V_276 = V_72 -> V_223 ;
V_277 = F_115 ( V_72 ) ?
V_285 : V_286 ;
if ( F_36 ( V_2 ) && V_275 &&
V_72 -> V_90 . V_91 != ( T_21 ) F_7 ( V_275 -> V_20 . V_21 ) ) {
V_282 = V_275 ;
if ( V_276 ) {
ASSERT ( V_72 -> V_83 ) ;
V_279 = V_72 -> V_83 ;
}
}
if ( F_37 ( V_72 -> V_78 ) && V_25 &&
V_72 -> V_90 . V_93 != F_7 ( V_25 -> V_20 . V_21 ) ) {
V_283 = V_25 ;
if ( V_276 ) {
ASSERT ( V_72 -> V_84 ) ;
V_280 = V_72 -> V_84 ;
}
}
if ( F_38 ( V_72 -> V_78 ) && V_26 &&
F_59 ( V_72 ) != F_7 ( V_26 -> V_20 . V_21 ) ) {
V_278 = V_287 ;
V_284 = V_26 ;
if ( V_276 ) {
ASSERT ( V_72 -> V_85 ) ;
V_281 = V_72 -> V_85 ;
}
}
error = F_147 ( V_146 , V_72 -> V_78 ,
V_282 , V_283 , V_284 ,
V_72 -> V_90 . V_188 , 1 ,
V_46 | V_277 | V_278 ) ;
if ( error )
return error ;
if ( V_276 ) {
ASSERT ( V_282 || V_283 || V_284 ) ;
ASSERT ( V_279 || V_280 || V_281 ) ;
error = F_147 ( NULL , V_72 -> V_78 ,
V_282 , V_283 , V_284 ,
( T_15 ) V_276 , 0 ,
V_46 | V_277 | V_278 ) ;
if ( error )
return error ;
F_147 ( NULL , V_72 -> V_78 ,
V_279 , V_280 , V_281 ,
- ( ( T_15 ) V_276 ) , 0 , V_277 ) ;
}
return ( 0 ) ;
}
int
F_148 (
struct V_80 * * V_288 )
{
struct V_1 * V_2 = V_288 [ 0 ] -> V_78 ;
int V_18 ;
if ( ! F_32 ( V_2 ) || ! F_55 ( V_2 ) )
return 0 ;
for ( V_18 = 0 ; ( V_18 < 4 && V_288 [ V_18 ] ) ; V_18 ++ ) {
struct V_80 * V_72 = V_288 [ V_18 ] ;
int error ;
if ( V_18 == 0 || V_72 != V_288 [ V_18 - 1 ] ) {
if ( F_56 ( V_2 , V_72 ) ) {
error = F_61 ( V_72 , 0 ) ;
if ( error )
return error ;
}
}
}
return 0 ;
}
void
F_149 (
struct V_274 * V_146 ,
struct V_80 * V_72 ,
struct V_3 * V_275 ,
struct V_3 * V_25 ,
struct V_3 * V_26 )
{
struct V_1 * V_2 = V_146 -> V_289 ;
if ( ! F_32 ( V_2 ) || ! F_55 ( V_2 ) )
return;
ASSERT ( F_47 ( V_72 , V_77 ) ) ;
ASSERT ( F_32 ( V_2 ) ) ;
if ( V_275 ) {
ASSERT ( V_72 -> V_83 == NULL ) ;
ASSERT ( F_36 ( V_2 ) ) ;
ASSERT ( V_72 -> V_90 . V_91 == F_7 ( V_275 -> V_20 . V_21 ) ) ;
V_72 -> V_83 = F_49 ( V_275 ) ;
F_145 ( V_146 , V_275 , V_273 , 1 ) ;
}
if ( V_25 ) {
ASSERT ( V_72 -> V_84 == NULL ) ;
ASSERT ( F_37 ( V_2 ) ) ;
ASSERT ( V_72 -> V_90 . V_93 == F_7 ( V_25 -> V_20 . V_21 ) ) ;
V_72 -> V_84 = F_49 ( V_25 ) ;
F_145 ( V_146 , V_25 , V_273 , 1 ) ;
}
if ( V_26 ) {
ASSERT ( V_72 -> V_85 == NULL ) ;
ASSERT ( F_38 ( V_2 ) ) ;
ASSERT ( F_59 ( V_72 ) == F_7 ( V_26 -> V_20 . V_21 ) ) ;
V_72 -> V_85 = F_49 ( V_26 ) ;
F_145 ( V_146 , V_26 , V_273 , 1 ) ;
}
}
