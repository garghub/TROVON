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
ASSERT ( ! F_22 ( & V_4 -> V_42 ) ) ;
F_23 ( & V_7 -> V_43 , & V_4 -> V_42 ) ;
F_24 ( V_44 ) ;
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
T_2 V_45 )
{
if ( V_45 & V_46 )
F_1 ( V_2 , V_47 , F_9 , NULL ) ;
if ( V_45 & V_48 )
F_1 ( V_2 , V_49 , F_9 , NULL ) ;
if ( V_45 & V_50 )
F_1 ( V_2 , V_51 , F_9 , NULL ) ;
}
void
F_28 (
struct V_1 * V_2 )
{
if ( V_2 -> V_8 ) {
F_27 ( V_2 , V_52 ) ;
F_29 ( V_2 ) ;
}
}
void
F_30 (
T_3 * V_2 )
{
int error = 0 ;
T_2 V_53 ;
if ( V_2 -> V_54 . V_55 ) {
F_31 ( V_2 , L_2 ) ;
V_2 -> V_56 = 0 ;
goto V_57;
}
ASSERT ( F_32 ( V_2 ) ) ;
error = F_33 ( V_2 ) ;
if ( error ) {
ASSERT ( V_2 -> V_8 == NULL ) ;
V_2 -> V_56 = 0 ;
goto V_57;
}
if ( F_34 ( V_2 ) ) {
error = F_35 ( V_2 ) ;
if ( error ) {
return;
}
}
if ( ! F_36 ( V_2 ) )
V_2 -> V_56 &= ~ V_58 ;
if ( ! F_37 ( V_2 ) )
V_2 -> V_56 &= ~ V_59 ;
if ( ! F_38 ( V_2 ) )
V_2 -> V_56 &= ~ V_60 ;
V_57:
F_39 ( & V_2 -> V_61 ) ;
V_53 = V_2 -> V_54 . V_62 ;
V_2 -> V_54 . V_62 = V_2 -> V_56 & V_63 ;
F_40 ( & V_2 -> V_61 ) ;
if ( V_53 != ( V_2 -> V_56 & V_63 ) ) {
if ( F_41 ( V_2 , V_64 ) ) {
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
ASSERT ( V_2 -> V_65 ) ;
F_44 ( V_2 -> V_65 ) ;
if ( V_2 -> V_66 )
F_44 ( V_2 -> V_66 ) ;
if ( V_2 -> V_67 )
F_44 ( V_2 -> V_67 ) ;
if ( V_2 -> V_8 ) {
if ( V_2 -> V_8 -> V_68 ) {
F_45 ( V_2 -> V_8 -> V_68 ) ;
V_2 -> V_8 -> V_68 = NULL ;
}
if ( V_2 -> V_8 -> V_69 ) {
F_45 ( V_2 -> V_8 -> V_69 ) ;
V_2 -> V_8 -> V_69 = NULL ;
}
if ( V_2 -> V_8 -> V_70 ) {
F_45 ( V_2 -> V_8 -> V_70 ) ;
V_2 -> V_8 -> V_70 = NULL ;
}
}
}
STATIC int
F_46 (
T_4 * V_71 ,
T_5 V_72 ,
T_2 type ,
T_2 V_73 ,
T_6 * V_74 ,
T_6 * * V_75 )
{
T_6 * V_4 ;
int error ;
ASSERT ( F_47 ( V_71 , V_76 ) ) ;
error = 0 ;
V_4 = * V_75 ;
if ( V_4 ) {
F_48 ( V_4 ) ;
return 0 ;
}
if ( V_74 ) {
ASSERT ( type == V_49 || type == V_51 ) ;
F_10 ( V_74 ) ;
if ( type == V_49 )
V_4 = V_74 -> V_30 ;
else
V_4 = V_74 -> V_31 ;
if ( V_4 && F_7 ( V_4 -> V_20 . V_21 ) == V_72 ) {
ASSERT ( * V_75 == NULL ) ;
* V_75 = F_49 ( V_4 ) ;
F_11 ( V_74 ) ;
return 0 ;
}
F_11 ( V_74 ) ;
}
error = F_50 ( V_71 -> V_77 , V_71 , V_72 , type ,
V_73 | V_78 , & V_4 ) ;
if ( error )
return error ;
F_51 ( V_4 ) ;
* V_75 = V_4 ;
F_11 ( V_4 ) ;
return 0 ;
}
STATIC void
F_52 (
struct V_79 * V_71 ,
int type )
{
struct V_3 * * V_80 ;
struct V_3 * V_4 ;
struct V_3 * V_81 = V_71 -> V_82 ;
ASSERT ( type == V_49 || type == V_51 ) ;
F_10 ( V_81 ) ;
if ( type == V_49 ) {
V_4 = V_71 -> V_83 ;
V_80 = & V_81 -> V_30 ;
} else {
V_4 = V_71 -> V_84 ;
V_80 = & V_81 -> V_31 ;
}
if ( * V_80 ) {
struct V_3 * V_85 ;
if ( * V_80 == V_4 )
goto V_86;
V_85 = * V_80 ;
* V_80 = NULL ;
F_53 ( V_85 ) ;
}
* V_80 = F_49 ( V_4 ) ;
V_86:
F_11 ( V_81 ) ;
}
static bool
F_54 (
struct V_79 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_77 ;
if ( ! F_32 ( V_2 ) )
return false ;
if ( ! F_55 ( V_2 ) )
return false ;
if ( ! F_56 ( V_2 , V_71 ) )
return false ;
if ( F_57 ( & V_2 -> V_54 , V_71 -> V_87 ) )
return false ;
return true ;
}
int
F_58 (
T_4 * V_71 ,
T_2 V_45 )
{
T_3 * V_2 = V_71 -> V_77 ;
T_2 V_88 = 0 ;
int error = 0 ;
if ( ! F_54 ( V_71 ) )
return 0 ;
ASSERT ( F_47 ( V_71 , V_76 ) ) ;
if ( F_36 ( V_2 ) ) {
error = F_46 ( V_71 , V_71 -> V_89 . V_90 , V_47 ,
V_45 & V_91 ,
NULL , & V_71 -> V_82 ) ;
if ( error )
goto V_86;
V_88 ++ ;
}
ASSERT ( F_47 ( V_71 , V_76 ) ) ;
if ( F_37 ( V_2 ) ) {
error = F_46 ( V_71 , V_71 -> V_89 . V_92 , V_49 ,
V_45 & V_91 ,
V_71 -> V_82 , & V_71 -> V_83 ) ;
if ( error )
goto V_86;
V_88 ++ ;
}
ASSERT ( F_47 ( V_71 , V_76 ) ) ;
if ( F_38 ( V_2 ) ) {
error = F_46 ( V_71 , F_59 ( V_71 ) , V_51 ,
V_45 & V_91 ,
V_71 -> V_82 , & V_71 -> V_84 ) ;
if ( error )
goto V_86;
V_88 ++ ;
}
if ( V_88 > 1 && V_71 -> V_82 ) {
ASSERT ( F_47 ( V_71 , V_76 ) ) ;
ASSERT ( V_71 -> V_83 || ! F_37 ( V_2 ) ) ;
ASSERT ( V_71 -> V_84 || ! F_38 ( V_2 ) ) ;
if ( V_71 -> V_82 -> V_30 != V_71 -> V_83 )
F_52 ( V_71 , V_49 ) ;
if ( V_71 -> V_82 -> V_31 != V_71 -> V_84 )
F_52 ( V_71 , V_51 ) ;
}
V_86:
#ifdef F_60
if ( ! error ) {
if ( F_36 ( V_2 ) )
ASSERT ( V_71 -> V_82 ) ;
if ( F_37 ( V_2 ) )
ASSERT ( V_71 -> V_83 ) ;
if ( F_38 ( V_2 ) )
ASSERT ( V_71 -> V_84 ) ;
}
ASSERT ( F_47 ( V_71 , V_76 ) ) ;
#endif
return error ;
}
int
F_61 (
struct V_79 * V_71 ,
T_2 V_45 )
{
int error ;
if ( ! F_54 ( V_71 ) )
return 0 ;
F_62 ( V_71 , V_76 ) ;
error = F_58 ( V_71 , V_45 ) ;
F_63 ( V_71 , V_76 ) ;
return error ;
}
void
F_44 (
T_4 * V_71 )
{
if ( ! ( V_71 -> V_82 || V_71 -> V_83 || V_71 -> V_84 ) )
return;
F_64 ( V_71 ) ;
ASSERT ( ! F_57 ( & V_71 -> V_77 -> V_54 , V_71 -> V_87 ) ) ;
if ( V_71 -> V_82 ) {
F_53 ( V_71 -> V_82 ) ;
V_71 -> V_82 = NULL ;
}
if ( V_71 -> V_83 ) {
F_53 ( V_71 -> V_83 ) ;
V_71 -> V_83 = NULL ;
}
if ( V_71 -> V_84 ) {
F_53 ( V_71 -> V_84 ) ;
V_71 -> V_84 = NULL ;
}
}
int
F_65 (
struct V_1 * V_2 ,
unsigned int V_93 )
{
unsigned int V_94 ;
ASSERT ( V_93 > 0 ) ;
V_94 = F_66 ( V_93 ) ;
F_67 ( V_94 , sizeof( V_95 ) ) ;
return V_94 ;
}
static enum V_96
F_68 (
struct V_97 * V_98 ,
T_7 * V_99 ,
void * V_100 )
{
struct V_3 * V_4 = F_69 ( V_98 ,
struct V_3 , V_42 ) ;
struct V_101 * V_102 = V_100 ;
if ( ! F_70 ( V_4 ) )
goto V_103;
if ( V_4 -> V_29 ) {
F_11 ( V_4 ) ;
F_71 ( V_104 ) ;
F_72 ( V_4 ) ;
F_73 ( & V_4 -> V_42 ) ;
F_24 ( V_44 ) ;
return V_105 ;
}
if ( ! F_74 ( V_4 ) ) {
F_11 ( V_4 ) ;
goto V_103;
}
if ( F_13 ( V_4 ) ) {
struct V_32 * V_33 = NULL ;
int error ;
F_75 ( V_4 ) ;
F_40 ( V_99 ) ;
error = F_14 ( V_4 , & V_33 ) ;
if ( error ) {
F_15 ( V_4 -> V_24 , L_1 ,
V_34 , V_4 ) ;
goto V_106;
}
F_76 ( V_33 , & V_102 -> V_107 ) ;
F_17 ( V_33 ) ;
goto V_106;
}
F_20 ( V_4 ) ;
V_4 -> V_27 |= V_28 ;
F_11 ( V_4 ) ;
ASSERT ( V_4 -> V_29 == 0 ) ;
F_77 ( & V_4 -> V_42 , & V_102 -> V_108 ) ;
F_24 ( V_44 ) ;
F_78 ( V_4 ) ;
F_71 ( V_109 ) ;
return V_105 ;
V_103:
F_79 ( V_4 ) ;
F_71 ( V_110 ) ;
return V_111 ;
V_106:
F_79 ( V_4 ) ;
F_71 ( V_110 ) ;
F_11 ( V_4 ) ;
F_39 ( V_99 ) ;
return V_112 ;
}
static unsigned long
F_80 (
struct V_113 * V_114 ,
struct V_115 * V_116 )
{
struct V_6 * V_7 = F_69 ( V_114 ,
struct V_6 , V_117 ) ;
struct V_101 V_102 ;
unsigned long V_118 ;
int error ;
unsigned long V_119 = V_116 -> V_119 ;
if ( ( V_116 -> V_120 & ( V_121 | V_122 ) ) != ( V_121 | V_122 ) )
return 0 ;
F_81 ( & V_102 . V_107 ) ;
F_81 ( & V_102 . V_108 ) ;
V_118 = F_82 ( & V_7 -> V_43 , V_116 -> V_123 , F_68 , & V_102 ,
& V_119 ) ;
error = F_83 ( & V_102 . V_107 ) ;
if ( error )
F_15 ( NULL , L_5 , V_34 ) ;
while ( ! F_22 ( & V_102 . V_108 ) ) {
struct V_3 * V_4 ;
V_4 = F_84 ( & V_102 . V_108 , struct V_3 , V_42 ) ;
F_73 ( & V_4 -> V_42 ) ;
F_85 ( V_4 ) ;
}
return V_118 ;
}
static unsigned long
F_86 (
struct V_113 * V_114 ,
struct V_115 * V_116 )
{
struct V_6 * V_7 = F_69 ( V_114 ,
struct V_6 , V_117 ) ;
return F_87 ( & V_7 -> V_43 , V_116 -> V_123 ) ;
}
STATIC int
F_33 (
T_3 * V_2 )
{
T_8 * V_124 ;
int error ;
T_6 * V_4 ;
ASSERT ( F_32 ( V_2 ) ) ;
V_124 = V_2 -> V_8 = F_88 ( sizeof( T_8 ) , V_125 ) ;
if ( ( error = F_89 ( & V_124 -> V_43 ) ) ) {
F_90 ( V_124 ) ;
V_2 -> V_8 = NULL ;
return error ;
}
if ( ( error = F_91 ( V_2 ) ) ) {
F_92 ( & V_124 -> V_43 ) ;
F_90 ( V_124 ) ;
V_2 -> V_8 = NULL ;
return error ;
}
F_93 ( & V_124 -> V_126 , V_127 ) ;
F_93 ( & V_124 -> V_128 , V_127 ) ;
F_93 ( & V_124 -> V_129 , V_127 ) ;
F_94 ( & V_124 -> V_19 ) ;
F_94 ( & V_124 -> V_130 ) ;
V_124 -> V_131 = F_95 ( V_2 , V_132 ) ;
V_124 -> V_133 = F_65 ( V_2 ,
V_124 -> V_131 ) ;
V_2 -> V_56 |= ( V_2 -> V_54 . V_62 & V_134 ) ;
error = F_96 ( V_2 , 0 ,
F_97 ( V_2 ) ? V_47 :
( F_98 ( V_2 ) ? V_49 :
V_51 ) ,
V_78 , & V_4 ) ;
if ( ! error ) {
T_9 * V_135 = & V_4 -> V_20 ;
V_124 -> V_136 = V_135 -> V_137 ?
F_7 ( V_135 -> V_137 ) : V_138 ;
V_124 -> V_139 = V_135 -> V_140 ?
F_7 ( V_135 -> V_140 ) : V_141 ;
V_124 -> V_142 = V_135 -> V_143 ?
F_7 ( V_135 -> V_143 ) : V_144 ;
V_124 -> V_145 = V_135 -> V_146 ?
F_99 ( V_135 -> V_146 ) : V_147 ;
V_124 -> V_148 = V_135 -> V_149 ?
F_99 ( V_135 -> V_149 ) : V_150 ;
V_124 -> V_151 = V_135 -> V_152 ?
F_99 ( V_135 -> V_152 ) : V_153 ;
V_124 -> V_154 = F_100 ( V_135 -> V_155 ) ;
V_124 -> V_156 = F_100 ( V_135 -> V_157 ) ;
V_124 -> V_158 = F_100 ( V_135 -> V_159 ) ;
V_124 -> V_160 = F_100 ( V_135 -> V_161 ) ;
V_124 -> V_162 = F_100 ( V_135 -> V_163 ) ;
V_124 -> V_164 = F_100 ( V_135 -> V_165 ) ;
F_25 ( V_4 ) ;
} else {
V_124 -> V_136 = V_138 ;
V_124 -> V_139 = V_141 ;
V_124 -> V_142 = V_144 ;
V_124 -> V_145 = V_147 ;
V_124 -> V_148 = V_150 ;
V_124 -> V_151 = V_153 ;
}
V_124 -> V_117 . V_166 = F_86 ;
V_124 -> V_117 . V_167 = F_80 ;
V_124 -> V_117 . V_168 = V_169 ;
V_124 -> V_117 . V_45 = V_170 ;
F_101 ( & V_124 -> V_117 ) ;
return 0 ;
}
void
F_29 (
T_3 * V_2 )
{
T_8 * V_7 ;
V_7 = V_2 -> V_8 ;
ASSERT ( V_7 != NULL ) ;
F_102 ( & V_7 -> V_117 ) ;
F_92 ( & V_7 -> V_43 ) ;
if ( V_7 -> V_68 ) {
F_45 ( V_7 -> V_68 ) ;
V_7 -> V_68 = NULL ;
}
if ( V_7 -> V_69 ) {
F_45 ( V_7 -> V_69 ) ;
V_7 -> V_69 = NULL ;
}
if ( V_7 -> V_70 ) {
F_45 ( V_7 -> V_70 ) ;
V_7 -> V_70 = NULL ;
}
F_103 ( & V_7 -> V_130 ) ;
F_90 ( V_7 ) ;
V_2 -> V_8 = NULL ;
}
STATIC int
F_104 (
T_3 * V_2 ,
T_4 * * V_71 ,
T_10 V_171 ,
T_2 V_45 )
{
T_11 * V_172 ;
int error ;
int V_173 ;
* V_71 = NULL ;
if ( ! F_105 ( & V_2 -> V_54 ) &&
( V_45 & ( V_50 | V_48 ) ) ) {
T_12 V_174 = V_175 ;
if ( ( V_45 & V_50 ) &&
( V_2 -> V_54 . V_176 != V_175 ) ) {
V_174 = V_2 -> V_54 . V_176 ;
ASSERT ( V_2 -> V_54 . V_177 == V_175 ) ;
} else if ( ( V_45 & V_48 ) &&
( V_2 -> V_54 . V_177 != V_175 ) ) {
V_174 = V_2 -> V_54 . V_177 ;
ASSERT ( V_2 -> V_54 . V_176 == V_175 ) ;
}
if ( V_174 != V_175 ) {
error = F_106 ( V_2 , NULL , V_174 , 0 , 0 , V_71 ) ;
if ( error )
return error ;
V_2 -> V_54 . V_176 = V_175 ;
V_2 -> V_54 . V_177 = V_175 ;
}
}
V_172 = F_107 ( V_2 , V_178 ) ;
error = F_108 ( V_172 , & F_109 ( V_2 ) -> V_179 ,
F_110 ( V_2 ) , 0 ) ;
if ( error ) {
F_111 ( V_172 , 0 ) ;
return error ;
}
if ( ! * V_71 ) {
error = F_112 ( & V_172 , NULL , V_180 , 1 , 0 , 0 , 1 , V_71 ,
& V_173 ) ;
if ( error ) {
F_111 ( V_172 , V_181 |
V_182 ) ;
return error ;
}
}
F_39 ( & V_2 -> V_61 ) ;
if ( V_45 & V_183 ) {
ASSERT ( ! F_113 ( & V_2 -> V_54 ) ) ;
ASSERT ( ( V_171 & ( V_184 | V_185 |
V_186 | V_187 | V_64 ) ) ==
( V_184 | V_185 |
V_186 | V_187 |
V_64 ) ) ;
F_114 ( & V_2 -> V_54 ) ;
V_2 -> V_54 . V_188 = V_175 ;
V_2 -> V_54 . V_176 = V_175 ;
V_2 -> V_54 . V_177 = V_175 ;
V_2 -> V_54 . V_62 = V_2 -> V_56 & V_189 ;
}
if ( V_45 & V_46 )
V_2 -> V_54 . V_188 = ( * V_71 ) -> V_87 ;
else if ( V_45 & V_48 )
V_2 -> V_54 . V_176 = ( * V_71 ) -> V_87 ;
else
V_2 -> V_54 . V_177 = ( * V_71 ) -> V_87 ;
F_40 ( & V_2 -> V_61 ) ;
F_115 ( V_172 , V_171 ) ;
if ( ( error = F_116 ( V_172 , V_181 ) ) ) {
F_42 ( V_2 , L_6 , V_34 , error ) ;
return error ;
}
return 0 ;
}
STATIC void
F_117 (
T_3 * V_2 ,
T_13 * V_33 ,
T_5 V_72 ,
T_2 type )
{
struct V_190 * V_191 ;
int V_192 ;
F_118 ( V_33 , V_193 ) ;
#ifdef F_60
V_192 = F_119 ( V_2 , V_132 ) ;
F_67 ( V_192 , sizeof( V_95 ) ) ;
ASSERT ( V_2 -> V_8 -> V_133 == V_192 ) ;
#endif
V_191 = V_33 -> V_194 ;
for ( V_192 = 0 ; V_192 < V_2 -> V_8 -> V_133 ; V_192 ++ ) {
struct V_195 * V_196 ;
V_196 = (struct V_195 * ) & V_191 [ V_192 ] ;
( void ) F_120 ( V_2 , V_196 , V_72 + V_192 , type , V_197 ,
L_7 ) ;
V_196 -> V_198 = 0 ;
V_196 -> V_199 = 0 ;
V_196 -> V_200 = 0 ;
V_196 -> V_137 = 0 ;
V_196 -> V_140 = 0 ;
V_196 -> V_143 = 0 ;
V_196 -> V_146 = 0 ;
V_196 -> V_149 = 0 ;
V_196 -> V_152 = 0 ;
if ( F_121 ( & V_2 -> V_54 ) ) {
F_122 ( ( char * ) & V_191 [ V_192 ] ,
sizeof( struct V_190 ) ,
V_201 ) ;
}
}
}
STATIC int
F_123 (
struct V_1 * V_2 ,
T_5 V_202 ,
T_14 V_203 ,
T_15 V_204 ,
T_2 V_45 ,
struct V_97 * V_205 )
{
struct V_32 * V_33 ;
int error ;
int type ;
ASSERT ( V_204 > 0 ) ;
type = V_45 & V_46 ? V_47 :
( V_45 & V_50 ? V_51 : V_49 ) ;
error = 0 ;
while ( V_204 -- ) {
error = F_124 ( V_2 , NULL , V_2 -> V_206 ,
F_125 ( V_2 , V_203 ) ,
V_2 -> V_8 -> V_131 , 0 , & V_33 ,
& V_207 ) ;
if ( error == V_23 ) {
error = F_124 ( V_2 , NULL , V_2 -> V_206 ,
F_125 ( V_2 , V_203 ) ,
V_2 -> V_8 -> V_131 , 0 , & V_33 ,
NULL ) ;
}
if ( error )
break;
F_117 ( V_2 , V_33 , V_202 , type ) ;
F_76 ( V_33 , V_205 ) ;
F_17 ( V_33 ) ;
V_203 ++ ;
V_202 += V_2 -> V_8 -> V_133 ;
}
return error ;
}
STATIC int
F_126 (
struct V_1 * V_2 ,
struct V_79 * V_208 ,
T_2 V_45 ,
struct V_97 * V_205 )
{
struct V_209 * V_210 ;
int V_18 , V_211 ;
int error ;
T_16 V_212 ;
T_15 V_213 ;
T_5 V_202 ;
T_14 V_214 ;
T_15 V_215 ;
error = 0 ;
if ( V_208 -> V_89 . V_216 == 0 )
return 0 ;
V_210 = F_127 ( V_217 * sizeof( * V_210 ) , V_125 ) ;
V_212 = 0 ;
V_213 = F_128 ( V_2 , V_2 -> V_218 -> V_219 ) ;
do {
V_211 = V_217 ;
F_62 ( V_208 , V_220 ) ;
error = F_129 ( V_208 , V_212 , V_213 - V_212 ,
V_210 , & V_211 , 0 ) ;
F_63 ( V_208 , V_220 ) ;
if ( error )
break;
ASSERT ( V_211 <= V_217 ) ;
for ( V_18 = 0 ; V_18 < V_211 ; V_18 ++ ) {
ASSERT ( V_210 [ V_18 ] . V_221 != V_222 ) ;
ASSERT ( V_210 [ V_18 ] . V_223 ) ;
V_212 += V_210 [ V_18 ] . V_223 ;
if ( V_210 [ V_18 ] . V_221 == V_224 )
continue;
V_202 = ( T_5 ) V_210 [ V_18 ] . V_225 *
V_2 -> V_8 -> V_133 ;
if ( ( V_18 + 1 < V_211 ) &&
( V_210 [ V_18 + 1 ] . V_221 != V_224 ) ) {
V_215 = V_210 [ V_18 + 1 ] . V_223 ;
V_214 = V_210 [ V_18 + 1 ] . V_221 ;
while ( V_215 -- ) {
F_130 ( V_2 -> V_206 ,
F_125 ( V_2 , V_214 ) ,
V_2 -> V_8 -> V_131 ,
NULL ) ;
V_214 ++ ;
}
}
error = F_123 ( V_2 , V_202 ,
V_210 [ V_18 ] . V_221 ,
V_210 [ V_18 ] . V_223 ,
V_45 , V_205 ) ;
if ( error )
goto V_226;
}
} while ( V_211 > 0 );
V_226:
F_90 ( V_210 ) ;
return error ;
}
STATIC int
F_131 (
struct V_79 * V_71 ,
T_5 V_72 ,
T_2 type ,
T_17 V_227 ,
T_17 V_228 )
{
struct V_1 * V_2 = V_71 -> V_77 ;
struct V_3 * V_4 ;
int error ;
error = F_50 ( V_2 , V_71 , V_72 , type ,
V_91 | V_78 , & V_4 ) ;
if ( error ) {
ASSERT ( error != V_229 ) ;
ASSERT ( error != V_230 ) ;
return error ;
}
F_132 ( V_4 ) ;
F_133 ( & V_4 -> V_20 . V_199 , 1 ) ;
V_4 -> V_231 ++ ;
if ( V_227 ) {
F_133 ( & V_4 -> V_20 . V_198 , V_227 ) ;
V_4 -> V_232 += V_227 ;
}
if ( V_228 ) {
F_133 ( & V_4 -> V_20 . V_200 , V_228 ) ;
V_4 -> V_233 += V_228 ;
}
if ( V_4 -> V_20 . V_21 ) {
F_134 ( V_2 , V_4 ) ;
F_135 ( V_2 , & V_4 -> V_20 ) ;
}
V_4 -> V_27 |= V_234 ;
F_26 ( V_4 ) ;
return 0 ;
}
STATIC int
F_136 (
T_4 * V_71 ,
T_17 * V_235 )
{
T_15 V_228 ;
T_18 V_236 ;
T_19 * V_237 ;
T_18 V_238 ;
int error ;
ASSERT ( F_137 ( V_71 ) ) ;
V_237 = F_138 ( V_71 , V_239 ) ;
if ( ! ( V_237 -> V_240 & V_241 ) ) {
if ( ( error = F_139 ( NULL , V_71 , V_239 ) ) )
return error ;
}
V_228 = 0 ;
V_238 = V_237 -> V_242 / ( T_2 ) sizeof( V_243 ) ;
for ( V_236 = 0 ; V_236 < V_238 ; V_236 ++ )
V_228 += F_140 ( F_141 ( V_237 , V_236 ) ) ;
* V_235 = ( T_17 ) V_228 ;
return 0 ;
}
STATIC int
F_142 (
T_3 * V_2 ,
T_12 V_174 ,
void T_20 * V_244 ,
int V_245 ,
int * V_246 ,
int * V_247 )
{
T_4 * V_71 ;
T_17 V_227 , V_228 = 0 ;
int error ;
ASSERT ( F_32 ( V_2 ) ) ;
if ( F_57 ( & V_2 -> V_54 , V_174 ) ) {
* V_247 = V_248 ;
return F_143 ( V_249 ) ;
}
error = F_106 ( V_2 , NULL , V_174 , 0 , V_76 , & V_71 ) ;
if ( error ) {
* V_247 = V_248 ;
return error ;
}
ASSERT ( V_71 -> V_250 == 0 ) ;
if ( F_137 ( V_71 ) ) {
error = F_136 ( V_71 , & V_228 ) ;
if ( error )
goto V_251;
}
V_227 = ( T_17 ) V_71 -> V_89 . V_216 - V_228 ;
if ( F_36 ( V_2 ) ) {
error = F_131 ( V_71 , V_71 -> V_89 . V_90 ,
V_47 , V_227 , V_228 ) ;
if ( error )
goto V_251;
}
if ( F_37 ( V_2 ) ) {
error = F_131 ( V_71 , V_71 -> V_89 . V_92 ,
V_49 , V_227 , V_228 ) ;
if ( error )
goto V_251;
}
if ( F_38 ( V_2 ) ) {
error = F_131 ( V_71 , F_59 ( V_71 ) ,
V_51 , V_227 , V_228 ) ;
if ( error )
goto V_251;
}
F_63 ( V_71 , V_76 ) ;
F_45 ( V_71 ) ;
* V_247 = V_252 ;
return 0 ;
V_251:
F_63 ( V_71 , V_76 ) ;
F_45 ( V_71 ) ;
* V_247 = V_253 ;
return error ;
}
STATIC int
F_144 (
struct V_3 * V_4 ,
void * V_5 )
{
struct V_97 * V_205 = V_5 ;
struct V_32 * V_33 = NULL ;
int error = 0 ;
F_10 ( V_4 ) ;
if ( V_4 -> V_27 & V_28 )
goto V_254;
if ( ! F_13 ( V_4 ) )
goto V_254;
F_12 ( V_4 ) ;
error = F_14 ( V_4 , & V_33 ) ;
if ( error )
goto V_254;
F_76 ( V_33 , V_205 ) ;
F_17 ( V_33 ) ;
V_254:
F_11 ( V_4 ) ;
return error ;
}
int
F_35 (
T_3 * V_2 )
{
int V_86 , V_255 , error , V_256 ;
T_12 V_257 ;
T_21 V_258 ;
T_2 V_45 ;
F_145 ( V_205 ) ;
struct V_79 * V_259 = V_2 -> V_8 -> V_68 ;
struct V_79 * V_260 = V_2 -> V_8 -> V_69 ;
struct V_79 * V_261 = V_2 -> V_8 -> V_70 ;
V_255 = V_262 ;
V_258 = 1 ;
V_257 = 0 ;
V_45 = 0 ;
ASSERT ( V_259 || V_260 || V_261 ) ;
ASSERT ( F_32 ( V_2 ) ) ;
F_31 ( V_2 , L_8 ) ;
if ( V_259 ) {
error = F_126 ( V_2 , V_259 , V_46 ,
& V_205 ) ;
if ( error )
goto V_263;
V_45 |= V_58 ;
}
if ( V_260 ) {
error = F_126 ( V_2 , V_260 , V_48 ,
& V_205 ) ;
if ( error )
goto V_263;
V_45 |= V_59 ;
}
if ( V_261 ) {
error = F_126 ( V_2 , V_261 , V_50 ,
& V_205 ) ;
if ( error )
goto V_263;
V_45 |= V_60 ;
}
do {
error = F_146 ( V_2 , & V_257 , & V_255 ,
F_142 ,
V_258 , NULL , & V_86 ) ;
if ( error )
break;
} while ( ! V_86 );
if ( F_36 ( V_2 ) ) {
error = F_1 ( V_2 , V_47 , F_144 ,
& V_205 ) ;
}
if ( F_37 ( V_2 ) ) {
V_256 = F_1 ( V_2 , V_49 , F_144 ,
& V_205 ) ;
if ( ! error )
error = V_256 ;
}
if ( F_38 ( V_2 ) ) {
V_256 = F_1 ( V_2 , V_51 , F_144 ,
& V_205 ) ;
if ( ! error )
error = V_256 ;
}
V_256 = F_83 ( & V_205 ) ;
if ( ! error )
error = V_256 ;
if ( error ) {
F_27 ( V_2 , V_52 ) ;
goto V_263;
}
V_2 -> V_56 &= ~ V_134 ;
V_2 -> V_56 |= V_45 ;
V_263:
while ( ! F_22 ( & V_205 ) ) {
struct V_32 * V_33 =
F_84 ( & V_205 , struct V_32 , V_264 ) ;
F_73 ( & V_33 -> V_264 ) ;
F_17 ( V_33 ) ;
}
if ( error ) {
F_15 ( V_2 ,
L_9 ,
error ) ;
ASSERT ( V_2 -> V_8 != NULL ) ;
F_29 ( V_2 ) ;
if ( F_147 ( V_2 ) ) {
F_15 ( V_2 ,
L_10 ) ;
}
} else
F_31 ( V_2 , L_11 ) ;
return ( error ) ;
}
STATIC int
F_91 (
T_3 * V_2 )
{
struct V_79 * V_259 = NULL ;
struct V_79 * V_260 = NULL ;
struct V_79 * V_261 = NULL ;
int error ;
T_10 V_265 = 0 ;
T_2 V_45 = 0 ;
ASSERT ( V_2 -> V_8 ) ;
if ( F_113 ( & V_2 -> V_54 ) ) {
if ( F_36 ( V_2 ) &&
V_2 -> V_54 . V_188 != V_175 ) {
ASSERT ( V_2 -> V_54 . V_188 > 0 ) ;
error = F_106 ( V_2 , NULL , V_2 -> V_54 . V_188 ,
0 , 0 , & V_259 ) ;
if ( error )
return F_143 ( error ) ;
}
if ( F_37 ( V_2 ) &&
V_2 -> V_54 . V_176 != V_175 ) {
ASSERT ( V_2 -> V_54 . V_176 > 0 ) ;
error = F_106 ( V_2 , NULL , V_2 -> V_54 . V_176 ,
0 , 0 , & V_260 ) ;
if ( error )
goto V_266;
}
if ( F_38 ( V_2 ) &&
V_2 -> V_54 . V_177 != V_175 ) {
ASSERT ( V_2 -> V_54 . V_177 > 0 ) ;
error = F_106 ( V_2 , NULL , V_2 -> V_54 . V_177 ,
0 , 0 , & V_261 ) ;
if ( error )
goto V_266;
}
} else {
V_45 |= V_183 ;
V_265 |= ( V_184 | V_185 |
V_186 | V_187 |
V_64 ) ;
}
if ( F_36 ( V_2 ) && V_259 == NULL ) {
error = F_104 ( V_2 , & V_259 ,
V_265 | V_185 ,
V_45 | V_46 ) ;
if ( error )
goto V_266;
V_45 &= ~ V_183 ;
}
if ( F_37 ( V_2 ) && V_260 == NULL ) {
error = F_104 ( V_2 , & V_260 ,
V_265 | V_186 ,
V_45 | V_48 ) ;
if ( error )
goto V_266;
V_45 &= ~ V_183 ;
}
if ( F_38 ( V_2 ) && V_261 == NULL ) {
error = F_104 ( V_2 , & V_261 ,
V_265 | V_187 ,
V_45 | V_50 ) ;
if ( error )
goto V_266;
}
V_2 -> V_8 -> V_68 = V_259 ;
V_2 -> V_8 -> V_69 = V_260 ;
V_2 -> V_8 -> V_70 = V_261 ;
return 0 ;
V_266:
if ( V_259 )
F_45 ( V_259 ) ;
if ( V_260 )
F_45 ( V_260 ) ;
if ( V_261 )
F_45 ( V_261 ) ;
return F_143 ( error ) ;
}
STATIC void
F_85 (
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
int
F_41 (
T_3 * V_2 ,
T_10 V_45 )
{
T_11 * V_172 ;
int error ;
V_172 = F_107 ( V_2 , V_267 ) ;
error = F_108 ( V_172 , & F_109 ( V_2 ) -> V_268 , 0 , 0 ) ;
if ( error ) {
F_111 ( V_172 , 0 ) ;
return error ;
}
F_115 ( V_172 , V_45 ) ;
error = F_116 ( V_172 , 0 ) ;
return error ;
}
int
F_148 (
struct V_79 * V_71 ,
T_5 V_269 ,
T_5 V_270 ,
T_22 V_271 ,
T_2 V_45 ,
struct V_3 * * V_272 ,
struct V_3 * * V_273 ,
struct V_3 * * V_274 )
{
struct V_1 * V_2 = V_71 -> V_77 ;
struct V_3 * V_275 = NULL ;
struct V_3 * V_276 = NULL ;
struct V_3 * V_277 = NULL ;
int error ;
T_2 V_278 ;
if ( ! F_32 ( V_2 ) || ! F_55 ( V_2 ) )
return 0 ;
V_278 = V_76 ;
F_62 ( V_71 , V_278 ) ;
if ( ( V_45 & V_279 ) && F_149 ( V_71 ) )
V_270 = V_71 -> V_89 . V_92 ;
if ( F_56 ( V_2 , V_71 ) ) {
error = F_58 ( V_71 , V_91 ) ;
if ( error ) {
F_63 ( V_71 , V_278 ) ;
return error ;
}
}
if ( ( V_45 & V_46 ) && F_36 ( V_2 ) ) {
if ( V_71 -> V_89 . V_90 != V_269 ) {
F_63 ( V_71 , V_278 ) ;
error = F_50 ( V_2 , NULL , V_269 ,
V_47 ,
V_91 |
V_78 ,
& V_275 ) ;
if ( error ) {
ASSERT ( error != V_230 ) ;
return error ;
}
F_11 ( V_275 ) ;
V_278 = V_220 ;
F_62 ( V_71 , V_278 ) ;
} else {
ASSERT ( V_71 -> V_82 ) ;
V_275 = F_49 ( V_71 -> V_82 ) ;
}
}
if ( ( V_45 & V_48 ) && F_37 ( V_2 ) ) {
if ( V_71 -> V_89 . V_92 != V_270 ) {
F_63 ( V_71 , V_278 ) ;
error = F_50 ( V_2 , NULL , V_270 ,
V_49 ,
V_91 |
V_78 ,
& V_276 ) ;
if ( error ) {
ASSERT ( error != V_230 ) ;
goto V_266;
}
F_11 ( V_276 ) ;
V_278 = V_220 ;
F_62 ( V_71 , V_278 ) ;
} else {
ASSERT ( V_71 -> V_83 ) ;
V_276 = F_49 ( V_71 -> V_83 ) ;
}
}
if ( ( V_45 & V_50 ) && F_38 ( V_2 ) ) {
if ( F_59 ( V_71 ) != V_271 ) {
F_63 ( V_71 , V_278 ) ;
error = F_50 ( V_2 , NULL , ( T_5 ) V_271 ,
V_51 ,
V_91 |
V_78 ,
& V_277 ) ;
if ( error ) {
ASSERT ( error != V_230 ) ;
goto V_266;
}
F_11 ( V_277 ) ;
V_278 = V_220 ;
F_62 ( V_71 , V_278 ) ;
} else {
ASSERT ( V_71 -> V_84 ) ;
V_277 = F_49 ( V_71 -> V_84 ) ;
}
}
if ( V_275 )
F_150 ( V_71 ) ;
F_63 ( V_71 , V_278 ) ;
if ( V_272 )
* V_272 = V_275 ;
else if ( V_275 )
F_53 ( V_275 ) ;
if ( V_273 )
* V_273 = V_276 ;
else if ( V_276 )
F_53 ( V_276 ) ;
if ( V_274 )
* V_274 = V_277 ;
else if ( V_277 )
F_53 ( V_277 ) ;
return 0 ;
V_266:
if ( V_276 )
F_53 ( V_276 ) ;
if ( V_275 )
F_53 ( V_275 ) ;
return error ;
}
T_6 *
F_151 (
T_11 * V_172 ,
T_4 * V_71 ,
T_6 * * V_280 ,
T_6 * V_281 )
{
T_6 * V_282 ;
T_2 V_283 = F_137 ( V_71 ) ?
V_284 : V_285 ;
ASSERT ( F_47 ( V_71 , V_76 ) ) ;
ASSERT ( F_32 ( V_71 -> V_77 ) ) ;
V_282 = * V_280 ;
ASSERT ( V_282 ) ;
ASSERT ( V_282 != V_281 ) ;
F_152 ( V_172 , V_282 , V_283 , - ( V_71 -> V_89 . V_216 ) ) ;
F_152 ( V_172 , V_282 , V_286 , - 1 ) ;
F_152 ( V_172 , V_281 , V_283 , V_71 -> V_89 . V_216 ) ;
F_152 ( V_172 , V_281 , V_286 , 1 ) ;
* V_280 = F_49 ( V_281 ) ;
return V_282 ;
}
int
F_153 (
struct V_287 * V_172 ,
struct V_79 * V_71 ,
struct V_3 * V_288 ,
struct V_3 * V_25 ,
struct V_3 * V_26 ,
T_2 V_45 )
{
struct V_1 * V_2 = V_71 -> V_77 ;
T_2 V_289 , V_290 , V_291 = 0 ;
struct V_3 * V_292 = NULL ;
struct V_3 * V_293 = NULL ;
struct V_3 * V_294 = NULL ;
struct V_3 * V_295 = NULL ;
struct V_3 * V_296 = NULL ;
struct V_3 * V_297 = NULL ;
int error ;
ASSERT ( F_47 ( V_71 , V_76 | V_220 ) ) ;
ASSERT ( F_32 ( V_2 ) ) ;
V_289 = V_71 -> V_250 ;
V_290 = F_137 ( V_71 ) ?
V_298 : V_299 ;
if ( F_36 ( V_2 ) && V_288 &&
V_71 -> V_89 . V_90 != F_7 ( V_288 -> V_20 . V_21 ) ) {
V_295 = V_288 ;
if ( V_289 ) {
ASSERT ( V_71 -> V_82 ) ;
V_292 = V_71 -> V_82 ;
}
}
if ( F_37 ( V_71 -> V_77 ) && V_25 &&
V_71 -> V_89 . V_92 != F_7 ( V_25 -> V_20 . V_21 ) ) {
V_296 = V_25 ;
if ( V_289 ) {
ASSERT ( V_71 -> V_83 ) ;
V_293 = V_71 -> V_83 ;
}
}
if ( F_38 ( V_71 -> V_77 ) && V_26 &&
F_59 ( V_71 ) != F_7 ( V_26 -> V_20 . V_21 ) ) {
V_291 = V_300 ;
V_297 = V_26 ;
if ( V_289 ) {
ASSERT ( V_71 -> V_84 ) ;
V_294 = V_71 -> V_84 ;
}
}
error = F_154 ( V_172 , V_71 -> V_77 ,
V_295 , V_296 , V_297 ,
V_71 -> V_89 . V_216 , 1 ,
V_45 | V_290 | V_291 ) ;
if ( error )
return error ;
if ( V_289 ) {
ASSERT ( V_295 || V_296 || V_297 ) ;
ASSERT ( V_292 || V_293 || V_294 ) ;
error = F_154 ( NULL , V_71 -> V_77 ,
V_295 , V_296 , V_297 ,
( T_17 ) V_289 , 0 ,
V_45 | V_290 | V_291 ) ;
if ( error )
return error ;
F_154 ( NULL , V_71 -> V_77 ,
V_292 , V_293 , V_294 ,
- ( ( T_17 ) V_289 ) , 0 , V_290 ) ;
}
return ( 0 ) ;
}
int
F_155 (
struct V_79 * * V_301 )
{
struct V_1 * V_2 = V_301 [ 0 ] -> V_77 ;
int V_18 ;
if ( ! F_32 ( V_2 ) || ! F_55 ( V_2 ) )
return 0 ;
for ( V_18 = 0 ; ( V_18 < 4 && V_301 [ V_18 ] ) ; V_18 ++ ) {
struct V_79 * V_71 = V_301 [ V_18 ] ;
int error ;
if ( V_18 == 0 || V_71 != V_301 [ V_18 - 1 ] ) {
if ( F_56 ( V_2 , V_71 ) ) {
error = F_61 ( V_71 , 0 ) ;
if ( error )
return error ;
}
}
}
return 0 ;
}
void
F_156 (
struct V_287 * V_172 ,
struct V_79 * V_71 ,
struct V_3 * V_288 ,
struct V_3 * V_25 ,
struct V_3 * V_26 )
{
struct V_1 * V_2 = V_172 -> V_302 ;
if ( ! F_32 ( V_2 ) || ! F_55 ( V_2 ) )
return;
ASSERT ( F_47 ( V_71 , V_76 ) ) ;
ASSERT ( F_32 ( V_2 ) ) ;
if ( V_288 ) {
ASSERT ( V_71 -> V_82 == NULL ) ;
ASSERT ( F_36 ( V_2 ) ) ;
ASSERT ( V_71 -> V_89 . V_90 == F_7 ( V_288 -> V_20 . V_21 ) ) ;
V_71 -> V_82 = F_49 ( V_288 ) ;
F_152 ( V_172 , V_288 , V_286 , 1 ) ;
}
if ( V_25 ) {
ASSERT ( V_71 -> V_83 == NULL ) ;
ASSERT ( F_37 ( V_2 ) ) ;
ASSERT ( V_71 -> V_89 . V_92 == F_7 ( V_25 -> V_20 . V_21 ) ) ;
V_71 -> V_83 = F_49 ( V_25 ) ;
F_152 ( V_172 , V_25 , V_286 , 1 ) ;
}
if ( V_26 ) {
ASSERT ( V_71 -> V_84 == NULL ) ;
ASSERT ( F_38 ( V_2 ) ) ;
ASSERT ( F_59 ( V_71 ) == F_7 ( V_26 -> V_20 . V_21 ) ) ;
V_71 -> V_84 = F_49 ( V_26 ) ;
F_152 ( V_172 , V_26 , V_286 , 1 ) ;
}
}
