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
STATIC int
F_26 (
struct V_3 * V_4 ,
void * V_5 )
{
struct V_3 * V_41 = NULL ;
struct V_3 * V_42 = NULL ;
T_2 V_43 = * ( ( T_2 * ) V_5 ) ;
F_10 ( V_4 ) ;
if ( V_4 -> V_25 & V_26 ) {
F_11 ( V_4 ) ;
return V_22 ;
}
V_41 = V_4 -> V_44 ;
if ( V_41 )
V_4 -> V_44 = NULL ;
V_42 = V_4 -> V_45 ;
if ( V_42 )
V_4 -> V_45 = NULL ;
F_11 ( V_4 ) ;
if ( V_41 )
F_27 ( V_41 ) ;
if ( V_42 )
F_27 ( V_42 ) ;
if ( V_43 & V_46 )
return F_9 ( V_4 , NULL ) ;
return 0 ;
}
void
F_28 (
struct V_1 * V_2 ,
T_2 V_43 )
{
F_1 ( V_2 , V_47 , F_26 , & V_43 ) ;
if ( V_43 & V_48 )
F_1 ( V_2 , V_49 , F_9 , NULL ) ;
if ( V_43 & V_50 )
F_1 ( V_2 , V_51 , F_9 , NULL ) ;
}
void
F_29 (
struct V_1 * V_2 )
{
if ( V_2 -> V_8 ) {
F_28 ( V_2 , V_52 ) ;
F_30 ( V_2 ) ;
}
}
void
F_31 (
T_3 * V_2 )
{
int error = 0 ;
T_2 V_53 ;
if ( V_2 -> V_54 . V_55 ) {
F_32 ( V_2 , L_2 ) ;
V_2 -> V_56 = 0 ;
goto V_57;
}
ASSERT ( F_33 ( V_2 ) ) ;
error = F_34 ( V_2 ) ;
if ( error ) {
ASSERT ( V_2 -> V_8 == NULL ) ;
V_2 -> V_56 = 0 ;
goto V_57;
}
if ( F_35 ( V_2 ) ) {
error = F_36 ( V_2 ) ;
if ( error ) {
return;
}
}
if ( ! F_37 ( V_2 ) )
V_2 -> V_56 &= ~ V_58 ;
if ( ! F_38 ( V_2 ) )
V_2 -> V_56 &= ~ V_59 ;
if ( ! F_39 ( V_2 ) )
V_2 -> V_56 &= ~ V_60 ;
V_57:
F_40 ( & V_2 -> V_61 ) ;
V_53 = V_2 -> V_54 . V_62 ;
V_2 -> V_54 . V_62 = V_2 -> V_56 & V_63 ;
F_41 ( & V_2 -> V_61 ) ;
if ( V_53 != ( V_2 -> V_56 & V_63 ) ) {
if ( F_42 ( V_2 , V_64 ) ) {
ASSERT ( ! ( F_33 ( V_2 ) ) ) ;
F_43 ( V_2 , L_3 ,
V_30 ) ;
}
}
if ( error ) {
F_15 ( V_2 , L_4 ) ;
return;
}
}
void
F_44 (
T_3 * V_2 )
{
ASSERT ( V_2 -> V_65 ) ;
F_45 ( V_2 -> V_65 ) ;
if ( V_2 -> V_66 )
F_45 ( V_2 -> V_66 ) ;
if ( V_2 -> V_67 )
F_45 ( V_2 -> V_67 ) ;
if ( V_2 -> V_8 ) {
if ( V_2 -> V_8 -> V_68 ) {
F_46 ( V_2 -> V_8 -> V_68 ) ;
V_2 -> V_8 -> V_68 = NULL ;
}
if ( V_2 -> V_8 -> V_69 ) {
F_46 ( V_2 -> V_8 -> V_69 ) ;
V_2 -> V_8 -> V_69 = NULL ;
}
if ( V_2 -> V_8 -> V_70 ) {
F_46 ( V_2 -> V_8 -> V_70 ) ;
V_2 -> V_8 -> V_70 = NULL ;
}
}
}
STATIC int
F_47 (
T_4 * V_71 ,
T_5 V_72 ,
T_2 type ,
T_2 V_73 ,
T_6 * V_74 ,
T_6 * * V_75 )
{
T_6 * V_4 ;
int error ;
ASSERT ( F_48 ( V_71 , V_76 ) ) ;
error = 0 ;
V_4 = * V_75 ;
if ( V_4 ) {
F_49 ( V_4 ) ;
return 0 ;
}
if ( V_74 ) {
ASSERT ( type == V_49 || type == V_51 ) ;
F_10 ( V_74 ) ;
if ( type == V_49 )
V_4 = V_74 -> V_44 ;
else
V_4 = V_74 -> V_45 ;
if ( V_4 && F_7 ( V_4 -> V_20 . V_21 ) == V_72 ) {
ASSERT ( * V_75 == NULL ) ;
* V_75 = F_50 ( V_4 ) ;
F_11 ( V_74 ) ;
return 0 ;
}
F_11 ( V_74 ) ;
}
error = F_51 ( V_71 -> V_77 , V_71 , V_72 , type ,
V_73 | V_78 , & V_4 ) ;
if ( error )
return error ;
F_52 ( V_4 ) ;
* V_75 = V_4 ;
F_11 ( V_4 ) ;
return 0 ;
}
STATIC void
F_53 (
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
V_80 = & V_81 -> V_44 ;
} else {
V_4 = V_71 -> V_84 ;
V_80 = & V_81 -> V_45 ;
}
if ( * V_80 ) {
struct V_3 * V_85 ;
if ( * V_80 == V_4 )
goto V_86;
V_85 = * V_80 ;
* V_80 = NULL ;
F_27 ( V_85 ) ;
}
* V_80 = F_50 ( V_4 ) ;
V_86:
F_11 ( V_81 ) ;
}
static bool
F_54 (
struct V_79 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_77 ;
if ( ! F_33 ( V_2 ) )
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
T_2 V_43 )
{
T_3 * V_2 = V_71 -> V_77 ;
T_2 V_88 = 0 ;
int error = 0 ;
if ( ! F_54 ( V_71 ) )
return 0 ;
ASSERT ( F_48 ( V_71 , V_76 ) ) ;
if ( F_37 ( V_2 ) ) {
error = F_47 ( V_71 , V_71 -> V_89 . V_90 , V_47 ,
V_43 & V_91 ,
NULL , & V_71 -> V_82 ) ;
if ( error )
goto V_86;
V_88 ++ ;
}
ASSERT ( F_48 ( V_71 , V_76 ) ) ;
if ( F_38 ( V_2 ) ) {
error = F_47 ( V_71 , V_71 -> V_89 . V_92 , V_49 ,
V_43 & V_91 ,
V_71 -> V_82 , & V_71 -> V_83 ) ;
if ( error )
goto V_86;
V_88 ++ ;
}
ASSERT ( F_48 ( V_71 , V_76 ) ) ;
if ( F_39 ( V_2 ) ) {
error = F_47 ( V_71 , F_59 ( V_71 ) , V_51 ,
V_43 & V_91 ,
V_71 -> V_82 , & V_71 -> V_84 ) ;
if ( error )
goto V_86;
V_88 ++ ;
}
if ( V_88 > 1 && V_71 -> V_82 ) {
ASSERT ( F_48 ( V_71 , V_76 ) ) ;
ASSERT ( V_71 -> V_83 || ! F_38 ( V_2 ) ) ;
ASSERT ( V_71 -> V_84 || ! F_39 ( V_2 ) ) ;
if ( V_71 -> V_82 -> V_44 != V_71 -> V_83 )
F_53 ( V_71 , V_49 ) ;
if ( V_71 -> V_82 -> V_45 != V_71 -> V_84 )
F_53 ( V_71 , V_51 ) ;
}
V_86:
#ifdef F_60
if ( ! error ) {
if ( F_37 ( V_2 ) )
ASSERT ( V_71 -> V_82 ) ;
if ( F_38 ( V_2 ) )
ASSERT ( V_71 -> V_83 ) ;
if ( F_39 ( V_2 ) )
ASSERT ( V_71 -> V_84 ) ;
}
ASSERT ( F_48 ( V_71 , V_76 ) ) ;
#endif
return error ;
}
int
F_61 (
struct V_79 * V_71 ,
T_2 V_43 )
{
int error ;
if ( ! F_54 ( V_71 ) )
return 0 ;
F_62 ( V_71 , V_76 ) ;
error = F_58 ( V_71 , V_43 ) ;
F_63 ( V_71 , V_76 ) ;
return error ;
}
void
F_45 (
T_4 * V_71 )
{
if ( ! ( V_71 -> V_82 || V_71 -> V_83 || V_71 -> V_84 ) )
return;
F_64 ( V_71 ) ;
ASSERT ( ! F_57 ( & V_71 -> V_77 -> V_54 , V_71 -> V_87 ) ) ;
if ( V_71 -> V_82 ) {
F_27 ( V_71 -> V_82 ) ;
V_71 -> V_82 = NULL ;
}
if ( V_71 -> V_83 ) {
F_27 ( V_71 -> V_83 ) ;
V_71 -> V_83 = NULL ;
}
if ( V_71 -> V_84 ) {
F_27 ( V_71 -> V_84 ) ;
V_71 -> V_84 = NULL ;
}
}
static enum V_93
F_65 (
struct V_94 * V_95 ,
T_7 * V_96 ,
void * V_97 )
{
struct V_3 * V_4 = F_66 ( V_95 ,
struct V_3 , V_38 ) ;
struct V_98 * V_99 = V_97 ;
if ( ! F_67 ( V_4 ) )
goto V_100;
if ( V_4 -> V_27 ) {
F_11 ( V_4 ) ;
F_68 ( V_101 ) ;
F_69 ( V_4 ) ;
F_70 ( & V_4 -> V_38 ) ;
F_24 ( V_40 ) ;
return V_102 ;
}
if ( ! F_71 ( V_4 ) ) {
F_11 ( V_4 ) ;
goto V_100;
}
if ( F_13 ( V_4 ) ) {
struct V_28 * V_29 = NULL ;
int error ;
F_72 ( V_4 ) ;
F_41 ( V_96 ) ;
error = F_14 ( V_4 , & V_29 ) ;
if ( error ) {
F_15 ( V_4 -> V_24 , L_1 ,
V_30 , V_4 ) ;
goto V_103;
}
F_73 ( V_29 , & V_99 -> V_104 ) ;
F_17 ( V_29 ) ;
goto V_103;
}
F_20 ( V_4 ) ;
V_4 -> V_25 |= V_26 ;
F_11 ( V_4 ) ;
ASSERT ( V_4 -> V_27 == 0 ) ;
F_74 ( & V_4 -> V_38 , & V_99 -> V_105 ) ;
F_24 ( V_40 ) ;
F_75 ( V_4 ) ;
F_68 ( V_106 ) ;
return V_102 ;
V_100:
F_76 ( V_4 ) ;
F_68 ( V_107 ) ;
return V_108 ;
V_103:
F_76 ( V_4 ) ;
F_68 ( V_107 ) ;
F_11 ( V_4 ) ;
F_40 ( V_96 ) ;
return V_109 ;
}
static unsigned long
F_77 (
struct V_110 * V_111 ,
struct V_112 * V_113 )
{
struct V_6 * V_7 = F_66 ( V_111 ,
struct V_6 , V_114 ) ;
struct V_98 V_99 ;
unsigned long V_115 ;
int error ;
unsigned long V_116 = V_113 -> V_116 ;
if ( ( V_113 -> V_117 & ( V_118 | V_119 ) ) != ( V_118 | V_119 ) )
return 0 ;
F_78 ( & V_99 . V_104 ) ;
F_78 ( & V_99 . V_105 ) ;
V_115 = F_79 ( & V_7 -> V_39 , V_113 -> V_120 , F_65 , & V_99 ,
& V_116 ) ;
error = F_80 ( & V_99 . V_104 ) ;
if ( error )
F_15 ( NULL , L_5 , V_30 ) ;
while ( ! F_22 ( & V_99 . V_105 ) ) {
struct V_3 * V_4 ;
V_4 = F_81 ( & V_99 . V_105 , struct V_3 , V_38 ) ;
F_70 ( & V_4 -> V_38 ) ;
F_82 ( V_4 ) ;
}
return V_115 ;
}
static unsigned long
F_83 (
struct V_110 * V_111 ,
struct V_112 * V_113 )
{
struct V_6 * V_7 = F_66 ( V_111 ,
struct V_6 , V_114 ) ;
return F_84 ( & V_7 -> V_39 , V_113 -> V_120 ) ;
}
STATIC int
F_34 (
T_3 * V_2 )
{
T_8 * V_121 ;
int error ;
T_6 * V_4 ;
ASSERT ( F_33 ( V_2 ) ) ;
V_121 = V_2 -> V_8 = F_85 ( sizeof( T_8 ) , V_122 ) ;
if ( ( error = F_86 ( & V_121 -> V_39 ) ) ) {
F_87 ( V_121 ) ;
V_2 -> V_8 = NULL ;
return error ;
}
if ( ( error = F_88 ( V_2 ) ) ) {
F_89 ( & V_121 -> V_39 ) ;
F_87 ( V_121 ) ;
V_2 -> V_8 = NULL ;
return error ;
}
F_90 ( & V_121 -> V_123 , V_124 ) ;
F_90 ( & V_121 -> V_125 , V_124 ) ;
F_90 ( & V_121 -> V_126 , V_124 ) ;
F_91 ( & V_121 -> V_19 ) ;
F_91 ( & V_121 -> V_127 ) ;
V_121 -> V_128 = F_92 ( V_2 , V_129 ) ;
V_121 -> V_130 = F_93 ( V_2 ,
V_121 -> V_128 ) ;
V_2 -> V_56 |= ( V_2 -> V_54 . V_62 & V_131 ) ;
error = F_94 ( V_2 , 0 ,
F_95 ( V_2 ) ? V_47 :
( F_96 ( V_2 ) ? V_49 :
V_51 ) ,
V_78 , & V_4 ) ;
if ( ! error ) {
T_9 * V_132 = & V_4 -> V_20 ;
V_121 -> V_133 = V_132 -> V_134 ?
F_7 ( V_132 -> V_134 ) : V_135 ;
V_121 -> V_136 = V_132 -> V_137 ?
F_7 ( V_132 -> V_137 ) : V_138 ;
V_121 -> V_139 = V_132 -> V_140 ?
F_7 ( V_132 -> V_140 ) : V_141 ;
V_121 -> V_142 = V_132 -> V_143 ?
F_97 ( V_132 -> V_143 ) : V_144 ;
V_121 -> V_145 = V_132 -> V_146 ?
F_97 ( V_132 -> V_146 ) : V_147 ;
V_121 -> V_148 = V_132 -> V_149 ?
F_97 ( V_132 -> V_149 ) : V_150 ;
V_121 -> V_151 = F_98 ( V_132 -> V_152 ) ;
V_121 -> V_153 = F_98 ( V_132 -> V_154 ) ;
V_121 -> V_155 = F_98 ( V_132 -> V_156 ) ;
V_121 -> V_157 = F_98 ( V_132 -> V_158 ) ;
V_121 -> V_159 = F_98 ( V_132 -> V_160 ) ;
V_121 -> V_161 = F_98 ( V_132 -> V_162 ) ;
F_25 ( V_4 ) ;
} else {
V_121 -> V_133 = V_135 ;
V_121 -> V_136 = V_138 ;
V_121 -> V_139 = V_141 ;
V_121 -> V_142 = V_144 ;
V_121 -> V_145 = V_147 ;
V_121 -> V_148 = V_150 ;
}
V_121 -> V_114 . V_163 = F_83 ;
V_121 -> V_114 . V_164 = F_77 ;
V_121 -> V_114 . V_165 = V_166 ;
V_121 -> V_114 . V_43 = V_167 ;
F_99 ( & V_121 -> V_114 ) ;
return 0 ;
}
void
F_30 (
T_3 * V_2 )
{
T_8 * V_7 ;
V_7 = V_2 -> V_8 ;
ASSERT ( V_7 != NULL ) ;
F_100 ( & V_7 -> V_114 ) ;
F_89 ( & V_7 -> V_39 ) ;
if ( V_7 -> V_68 ) {
F_46 ( V_7 -> V_68 ) ;
V_7 -> V_68 = NULL ;
}
if ( V_7 -> V_69 ) {
F_46 ( V_7 -> V_69 ) ;
V_7 -> V_69 = NULL ;
}
if ( V_7 -> V_70 ) {
F_46 ( V_7 -> V_70 ) ;
V_7 -> V_70 = NULL ;
}
F_101 ( & V_7 -> V_127 ) ;
F_87 ( V_7 ) ;
V_2 -> V_8 = NULL ;
}
STATIC int
F_102 (
T_3 * V_2 ,
T_4 * * V_71 ,
T_10 V_168 ,
T_2 V_43 )
{
T_11 * V_169 ;
int error ;
int V_170 ;
* V_71 = NULL ;
if ( ! F_103 ( & V_2 -> V_54 ) &&
( V_43 & ( V_50 | V_48 ) ) ) {
T_12 V_171 = V_172 ;
if ( ( V_43 & V_50 ) &&
( V_2 -> V_54 . V_173 != V_172 ) ) {
V_171 = V_2 -> V_54 . V_173 ;
ASSERT ( V_2 -> V_54 . V_174 == V_172 ) ;
} else if ( ( V_43 & V_48 ) &&
( V_2 -> V_54 . V_174 != V_172 ) ) {
V_171 = V_2 -> V_54 . V_174 ;
ASSERT ( V_2 -> V_54 . V_173 == V_172 ) ;
}
if ( V_171 != V_172 ) {
error = F_104 ( V_2 , NULL , V_171 , 0 , 0 , V_71 ) ;
if ( error )
return error ;
V_2 -> V_54 . V_173 = V_172 ;
V_2 -> V_54 . V_174 = V_172 ;
}
}
V_169 = F_105 ( V_2 , V_175 ) ;
error = F_106 ( V_169 , & F_107 ( V_2 ) -> V_176 ,
F_108 ( V_2 ) , 0 ) ;
if ( error ) {
F_109 ( V_169 , 0 ) ;
return error ;
}
if ( ! * V_71 ) {
error = F_110 ( & V_169 , NULL , V_177 , 1 , 0 , 0 , 1 , V_71 ,
& V_170 ) ;
if ( error ) {
F_109 ( V_169 , V_178 |
V_179 ) ;
return error ;
}
}
F_40 ( & V_2 -> V_61 ) ;
if ( V_43 & V_180 ) {
ASSERT ( ! F_111 ( & V_2 -> V_54 ) ) ;
ASSERT ( ( V_168 & ( V_181 | V_182 |
V_183 | V_184 | V_64 ) ) ==
( V_181 | V_182 |
V_183 | V_184 |
V_64 ) ) ;
F_112 ( & V_2 -> V_54 ) ;
V_2 -> V_54 . V_185 = V_172 ;
V_2 -> V_54 . V_173 = V_172 ;
V_2 -> V_54 . V_174 = V_172 ;
V_2 -> V_54 . V_62 = V_2 -> V_56 & V_186 ;
}
if ( V_43 & V_46 )
V_2 -> V_54 . V_185 = ( * V_71 ) -> V_87 ;
else if ( V_43 & V_48 )
V_2 -> V_54 . V_173 = ( * V_71 ) -> V_87 ;
else
V_2 -> V_54 . V_174 = ( * V_71 ) -> V_87 ;
F_41 ( & V_2 -> V_61 ) ;
F_113 ( V_169 , V_168 ) ;
if ( ( error = F_114 ( V_169 , V_178 ) ) ) {
F_43 ( V_2 , L_6 , V_30 , error ) ;
return error ;
}
return 0 ;
}
STATIC void
F_115 (
T_3 * V_2 ,
T_13 * V_29 ,
T_5 V_72 ,
T_2 type )
{
struct V_187 * V_188 ;
int V_189 ;
F_116 ( V_29 , V_190 ) ;
#ifdef F_60
V_189 = F_117 ( V_2 , V_129 ) ;
F_118 ( V_189 , sizeof( V_191 ) ) ;
ASSERT ( V_2 -> V_8 -> V_130 == V_189 ) ;
#endif
V_188 = V_29 -> V_192 ;
for ( V_189 = 0 ; V_189 < V_2 -> V_8 -> V_130 ; V_189 ++ ) {
struct V_193 * V_194 ;
V_194 = (struct V_193 * ) & V_188 [ V_189 ] ;
F_119 ( V_2 , V_194 , V_72 + V_189 , type , V_195 ,
L_7 ) ;
V_194 -> V_196 = 0 ;
V_194 -> V_197 = 0 ;
V_194 -> V_198 = 0 ;
V_194 -> V_134 = 0 ;
V_194 -> V_137 = 0 ;
V_194 -> V_140 = 0 ;
V_194 -> V_143 = 0 ;
V_194 -> V_146 = 0 ;
V_194 -> V_149 = 0 ;
if ( F_120 ( & V_2 -> V_54 ) ) {
F_121 ( ( char * ) & V_188 [ V_189 ] ,
sizeof( struct V_187 ) ,
V_199 ) ;
}
}
}
STATIC int
F_122 (
struct V_1 * V_2 ,
T_5 V_200 ,
T_14 V_201 ,
T_15 V_202 ,
T_2 V_43 ,
struct V_94 * V_203 )
{
struct V_28 * V_29 ;
int error ;
int type ;
ASSERT ( V_202 > 0 ) ;
type = V_43 & V_46 ? V_47 :
( V_43 & V_50 ? V_51 : V_49 ) ;
error = 0 ;
while ( V_202 -- ) {
error = F_123 ( V_2 , NULL , V_2 -> V_204 ,
F_124 ( V_2 , V_201 ) ,
V_2 -> V_8 -> V_128 , 0 , & V_29 ,
& V_205 ) ;
if ( error == V_23 ) {
error = F_123 ( V_2 , NULL , V_2 -> V_204 ,
F_124 ( V_2 , V_201 ) ,
V_2 -> V_8 -> V_128 , 0 , & V_29 ,
NULL ) ;
}
if ( error )
break;
F_115 ( V_2 , V_29 , V_200 , type ) ;
F_73 ( V_29 , V_203 ) ;
F_17 ( V_29 ) ;
V_201 ++ ;
V_200 += V_2 -> V_8 -> V_130 ;
}
return error ;
}
STATIC int
F_125 (
struct V_1 * V_2 ,
struct V_79 * V_206 ,
T_2 V_43 ,
struct V_94 * V_203 )
{
struct V_207 * V_208 ;
int V_18 , V_209 ;
int error ;
T_16 V_210 ;
T_15 V_211 ;
T_5 V_200 ;
T_14 V_212 ;
T_15 V_213 ;
error = 0 ;
if ( V_206 -> V_89 . V_214 == 0 )
return 0 ;
V_208 = F_126 ( V_215 * sizeof( * V_208 ) , V_122 ) ;
V_210 = 0 ;
V_211 = F_127 ( V_2 , V_2 -> V_216 -> V_217 ) ;
do {
T_2 V_218 ;
V_209 = V_215 ;
V_218 = F_128 ( V_206 ) ;
error = F_129 ( V_206 , V_210 , V_211 - V_210 ,
V_208 , & V_209 , 0 ) ;
F_63 ( V_206 , V_218 ) ;
if ( error )
break;
ASSERT ( V_209 <= V_215 ) ;
for ( V_18 = 0 ; V_18 < V_209 ; V_18 ++ ) {
ASSERT ( V_208 [ V_18 ] . V_219 != V_220 ) ;
ASSERT ( V_208 [ V_18 ] . V_221 ) ;
V_210 += V_208 [ V_18 ] . V_221 ;
if ( V_208 [ V_18 ] . V_219 == V_222 )
continue;
V_200 = ( T_5 ) V_208 [ V_18 ] . V_223 *
V_2 -> V_8 -> V_130 ;
if ( ( V_18 + 1 < V_209 ) &&
( V_208 [ V_18 + 1 ] . V_219 != V_222 ) ) {
V_213 = V_208 [ V_18 + 1 ] . V_221 ;
V_212 = V_208 [ V_18 + 1 ] . V_219 ;
while ( V_213 -- ) {
F_130 ( V_2 -> V_204 ,
F_124 ( V_2 , V_212 ) ,
V_2 -> V_8 -> V_128 ,
NULL ) ;
V_212 ++ ;
}
}
error = F_122 ( V_2 , V_200 ,
V_208 [ V_18 ] . V_219 ,
V_208 [ V_18 ] . V_221 ,
V_43 , V_203 ) ;
if ( error )
goto V_224;
}
} while ( V_209 > 0 );
V_224:
F_87 ( V_208 ) ;
return error ;
}
STATIC int
F_131 (
struct V_79 * V_71 ,
T_5 V_72 ,
T_2 type ,
T_17 V_225 ,
T_17 V_226 )
{
struct V_1 * V_2 = V_71 -> V_77 ;
struct V_3 * V_4 ;
int error ;
error = F_51 ( V_2 , V_71 , V_72 , type ,
V_91 | V_78 , & V_4 ) ;
if ( error ) {
ASSERT ( error != V_227 ) ;
ASSERT ( error != V_228 ) ;
return error ;
}
F_132 ( V_4 ) ;
F_133 ( & V_4 -> V_20 . V_197 , 1 ) ;
V_4 -> V_229 ++ ;
if ( V_225 ) {
F_133 ( & V_4 -> V_20 . V_196 , V_225 ) ;
V_4 -> V_230 += V_225 ;
}
if ( V_226 ) {
F_133 ( & V_4 -> V_20 . V_198 , V_226 ) ;
V_4 -> V_231 += V_226 ;
}
if ( V_4 -> V_20 . V_21 ) {
F_134 ( V_2 , V_4 ) ;
F_135 ( V_2 , & V_4 -> V_20 ) ;
}
V_4 -> V_25 |= V_232 ;
F_136 ( V_4 ) ;
return 0 ;
}
STATIC int
F_137 (
T_4 * V_71 ,
T_17 * V_233 )
{
T_15 V_226 ;
T_18 V_234 ;
T_19 * V_235 ;
T_18 V_236 ;
int error ;
ASSERT ( F_138 ( V_71 ) ) ;
V_235 = F_139 ( V_71 , V_237 ) ;
if ( ! ( V_235 -> V_238 & V_239 ) ) {
if ( ( error = F_140 ( NULL , V_71 , V_237 ) ) )
return error ;
}
V_226 = 0 ;
V_236 = V_235 -> V_240 / ( T_2 ) sizeof( V_241 ) ;
for ( V_234 = 0 ; V_234 < V_236 ; V_234 ++ )
V_226 += F_141 ( F_142 ( V_235 , V_234 ) ) ;
* V_233 = ( T_17 ) V_226 ;
return 0 ;
}
STATIC int
F_143 (
T_3 * V_2 ,
T_12 V_171 ,
void T_20 * V_242 ,
int V_243 ,
int * V_244 ,
int * V_245 )
{
T_4 * V_71 ;
T_17 V_225 , V_226 = 0 ;
int error ;
ASSERT ( F_33 ( V_2 ) ) ;
if ( F_57 ( & V_2 -> V_54 , V_171 ) ) {
* V_245 = V_246 ;
return F_144 ( V_247 ) ;
}
error = F_104 ( V_2 , NULL , V_171 , 0 , V_76 , & V_71 ) ;
if ( error ) {
* V_245 = V_246 ;
return error ;
}
ASSERT ( V_71 -> V_248 == 0 ) ;
if ( F_138 ( V_71 ) ) {
error = F_137 ( V_71 , & V_226 ) ;
if ( error )
goto V_249;
}
V_225 = ( T_17 ) V_71 -> V_89 . V_214 - V_226 ;
if ( F_37 ( V_2 ) ) {
error = F_131 ( V_71 , V_71 -> V_89 . V_90 ,
V_47 , V_225 , V_226 ) ;
if ( error )
goto V_249;
}
if ( F_38 ( V_2 ) ) {
error = F_131 ( V_71 , V_71 -> V_89 . V_92 ,
V_49 , V_225 , V_226 ) ;
if ( error )
goto V_249;
}
if ( F_39 ( V_2 ) ) {
error = F_131 ( V_71 , F_59 ( V_71 ) ,
V_51 , V_225 , V_226 ) ;
if ( error )
goto V_249;
}
F_63 ( V_71 , V_76 ) ;
F_46 ( V_71 ) ;
* V_245 = V_250 ;
return 0 ;
V_249:
F_63 ( V_71 , V_76 ) ;
F_46 ( V_71 ) ;
* V_245 = V_251 ;
return error ;
}
STATIC int
F_145 (
struct V_3 * V_4 ,
void * V_5 )
{
struct V_94 * V_203 = V_5 ;
struct V_28 * V_29 = NULL ;
int error = 0 ;
F_10 ( V_4 ) ;
if ( V_4 -> V_25 & V_26 )
goto V_252;
if ( ! F_13 ( V_4 ) )
goto V_252;
F_12 ( V_4 ) ;
error = F_14 ( V_4 , & V_29 ) ;
if ( error )
goto V_252;
F_73 ( V_29 , V_203 ) ;
F_17 ( V_29 ) ;
V_252:
F_11 ( V_4 ) ;
return error ;
}
int
F_36 (
T_3 * V_2 )
{
int V_86 , V_253 , error , V_254 ;
T_12 V_255 ;
T_21 V_256 ;
T_2 V_43 ;
F_146 ( V_203 ) ;
struct V_79 * V_257 = V_2 -> V_8 -> V_68 ;
struct V_79 * V_258 = V_2 -> V_8 -> V_69 ;
struct V_79 * V_259 = V_2 -> V_8 -> V_70 ;
V_253 = V_260 ;
V_256 = 1 ;
V_255 = 0 ;
V_43 = 0 ;
ASSERT ( V_257 || V_258 || V_259 ) ;
ASSERT ( F_33 ( V_2 ) ) ;
F_32 ( V_2 , L_8 ) ;
if ( V_257 ) {
error = F_125 ( V_2 , V_257 , V_46 ,
& V_203 ) ;
if ( error )
goto V_261;
V_43 |= V_58 ;
}
if ( V_258 ) {
error = F_125 ( V_2 , V_258 , V_48 ,
& V_203 ) ;
if ( error )
goto V_261;
V_43 |= V_59 ;
}
if ( V_259 ) {
error = F_125 ( V_2 , V_259 , V_50 ,
& V_203 ) ;
if ( error )
goto V_261;
V_43 |= V_60 ;
}
do {
error = F_147 ( V_2 , & V_255 , & V_253 ,
F_143 ,
V_256 , NULL , & V_86 ) ;
if ( error )
break;
} while ( ! V_86 );
if ( F_37 ( V_2 ) ) {
error = F_1 ( V_2 , V_47 , F_145 ,
& V_203 ) ;
}
if ( F_38 ( V_2 ) ) {
V_254 = F_1 ( V_2 , V_49 , F_145 ,
& V_203 ) ;
if ( ! error )
error = V_254 ;
}
if ( F_39 ( V_2 ) ) {
V_254 = F_1 ( V_2 , V_51 , F_145 ,
& V_203 ) ;
if ( ! error )
error = V_254 ;
}
V_254 = F_80 ( & V_203 ) ;
if ( ! error )
error = V_254 ;
if ( error ) {
F_28 ( V_2 , V_52 ) ;
goto V_261;
}
V_2 -> V_56 &= ~ V_131 ;
V_2 -> V_56 |= V_43 ;
V_261:
while ( ! F_22 ( & V_203 ) ) {
struct V_28 * V_29 =
F_81 ( & V_203 , struct V_28 , V_262 ) ;
F_70 ( & V_29 -> V_262 ) ;
F_17 ( V_29 ) ;
}
if ( error ) {
F_15 ( V_2 ,
L_9 ,
error ) ;
ASSERT ( V_2 -> V_8 != NULL ) ;
F_30 ( V_2 ) ;
if ( F_148 ( V_2 ) ) {
F_15 ( V_2 ,
L_10 ) ;
}
} else
F_32 ( V_2 , L_11 ) ;
return ( error ) ;
}
STATIC int
F_88 (
T_3 * V_2 )
{
struct V_79 * V_257 = NULL ;
struct V_79 * V_258 = NULL ;
struct V_79 * V_259 = NULL ;
int error ;
T_10 V_263 = 0 ;
T_2 V_43 = 0 ;
ASSERT ( V_2 -> V_8 ) ;
if ( F_111 ( & V_2 -> V_54 ) ) {
if ( F_37 ( V_2 ) &&
V_2 -> V_54 . V_185 != V_172 ) {
ASSERT ( V_2 -> V_54 . V_185 > 0 ) ;
error = F_104 ( V_2 , NULL , V_2 -> V_54 . V_185 ,
0 , 0 , & V_257 ) ;
if ( error )
return F_144 ( error ) ;
}
if ( F_38 ( V_2 ) &&
V_2 -> V_54 . V_173 != V_172 ) {
ASSERT ( V_2 -> V_54 . V_173 > 0 ) ;
error = F_104 ( V_2 , NULL , V_2 -> V_54 . V_173 ,
0 , 0 , & V_258 ) ;
if ( error )
goto V_264;
}
if ( F_39 ( V_2 ) &&
V_2 -> V_54 . V_174 != V_172 ) {
ASSERT ( V_2 -> V_54 . V_174 > 0 ) ;
error = F_104 ( V_2 , NULL , V_2 -> V_54 . V_174 ,
0 , 0 , & V_259 ) ;
if ( error )
goto V_264;
}
} else {
V_43 |= V_180 ;
V_263 |= ( V_181 | V_182 |
V_183 | V_184 |
V_64 ) ;
}
if ( F_37 ( V_2 ) && V_257 == NULL ) {
error = F_102 ( V_2 , & V_257 ,
V_263 | V_182 ,
V_43 | V_46 ) ;
if ( error )
goto V_264;
V_43 &= ~ V_180 ;
}
if ( F_38 ( V_2 ) && V_258 == NULL ) {
error = F_102 ( V_2 , & V_258 ,
V_263 | V_183 ,
V_43 | V_48 ) ;
if ( error )
goto V_264;
V_43 &= ~ V_180 ;
}
if ( F_39 ( V_2 ) && V_259 == NULL ) {
error = F_102 ( V_2 , & V_259 ,
V_263 | V_184 ,
V_43 | V_50 ) ;
if ( error )
goto V_264;
}
V_2 -> V_8 -> V_68 = V_257 ;
V_2 -> V_8 -> V_69 = V_258 ;
V_2 -> V_8 -> V_70 = V_259 ;
return 0 ;
V_264:
if ( V_257 )
F_46 ( V_257 ) ;
if ( V_258 )
F_46 ( V_258 ) ;
if ( V_259 )
F_46 ( V_259 ) ;
return F_144 ( error ) ;
}
STATIC void
F_82 (
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
F_42 (
T_3 * V_2 ,
T_10 V_43 )
{
T_11 * V_169 ;
int error ;
V_169 = F_105 ( V_2 , V_265 ) ;
error = F_106 ( V_169 , & F_107 ( V_2 ) -> V_266 , 0 , 0 ) ;
if ( error ) {
F_109 ( V_169 , 0 ) ;
return error ;
}
F_113 ( V_169 , V_43 ) ;
error = F_114 ( V_169 , 0 ) ;
return error ;
}
int
F_149 (
struct V_79 * V_71 ,
T_5 V_267 ,
T_5 V_268 ,
T_22 V_269 ,
T_2 V_43 ,
struct V_3 * * V_270 ,
struct V_3 * * V_271 ,
struct V_3 * * V_272 )
{
struct V_1 * V_2 = V_71 -> V_77 ;
struct V_3 * V_273 = NULL ;
struct V_3 * V_274 = NULL ;
struct V_3 * V_275 = NULL ;
int error ;
T_2 V_276 ;
if ( ! F_33 ( V_2 ) || ! F_55 ( V_2 ) )
return 0 ;
V_276 = V_76 ;
F_62 ( V_71 , V_276 ) ;
if ( ( V_43 & V_277 ) && F_150 ( V_71 ) )
V_268 = V_71 -> V_89 . V_92 ;
if ( F_56 ( V_2 , V_71 ) ) {
error = F_58 ( V_71 , V_91 ) ;
if ( error ) {
F_63 ( V_71 , V_276 ) ;
return error ;
}
}
if ( ( V_43 & V_46 ) && F_37 ( V_2 ) ) {
if ( V_71 -> V_89 . V_90 != V_267 ) {
F_63 ( V_71 , V_276 ) ;
error = F_51 ( V_2 , NULL , V_267 ,
V_47 ,
V_91 |
V_78 ,
& V_273 ) ;
if ( error ) {
ASSERT ( error != V_228 ) ;
return error ;
}
F_11 ( V_273 ) ;
V_276 = V_278 ;
F_62 ( V_71 , V_276 ) ;
} else {
ASSERT ( V_71 -> V_82 ) ;
V_273 = F_50 ( V_71 -> V_82 ) ;
}
}
if ( ( V_43 & V_48 ) && F_38 ( V_2 ) ) {
if ( V_71 -> V_89 . V_92 != V_268 ) {
F_63 ( V_71 , V_276 ) ;
error = F_51 ( V_2 , NULL , V_268 ,
V_49 ,
V_91 |
V_78 ,
& V_274 ) ;
if ( error ) {
ASSERT ( error != V_228 ) ;
goto V_264;
}
F_11 ( V_274 ) ;
V_276 = V_278 ;
F_62 ( V_71 , V_276 ) ;
} else {
ASSERT ( V_71 -> V_83 ) ;
V_274 = F_50 ( V_71 -> V_83 ) ;
}
}
if ( ( V_43 & V_50 ) && F_39 ( V_2 ) ) {
if ( F_59 ( V_71 ) != V_269 ) {
F_63 ( V_71 , V_276 ) ;
error = F_51 ( V_2 , NULL , ( T_5 ) V_269 ,
V_51 ,
V_91 |
V_78 ,
& V_275 ) ;
if ( error ) {
ASSERT ( error != V_228 ) ;
goto V_264;
}
F_11 ( V_275 ) ;
V_276 = V_278 ;
F_62 ( V_71 , V_276 ) ;
} else {
ASSERT ( V_71 -> V_84 ) ;
V_275 = F_50 ( V_71 -> V_84 ) ;
}
}
if ( V_273 )
F_151 ( V_71 ) ;
F_63 ( V_71 , V_276 ) ;
if ( V_270 )
* V_270 = V_273 ;
else if ( V_273 )
F_27 ( V_273 ) ;
if ( V_271 )
* V_271 = V_274 ;
else if ( V_274 )
F_27 ( V_274 ) ;
if ( V_272 )
* V_272 = V_275 ;
else if ( V_275 )
F_27 ( V_275 ) ;
return 0 ;
V_264:
if ( V_274 )
F_27 ( V_274 ) ;
if ( V_273 )
F_27 ( V_273 ) ;
return error ;
}
T_6 *
F_152 (
T_11 * V_169 ,
T_4 * V_71 ,
T_6 * * V_279 ,
T_6 * V_280 )
{
T_6 * V_281 ;
T_2 V_282 = F_138 ( V_71 ) ?
V_283 : V_284 ;
ASSERT ( F_48 ( V_71 , V_76 ) ) ;
ASSERT ( F_33 ( V_71 -> V_77 ) ) ;
V_281 = * V_279 ;
ASSERT ( V_281 ) ;
ASSERT ( V_281 != V_280 ) ;
F_153 ( V_169 , V_281 , V_282 , - ( V_71 -> V_89 . V_214 ) ) ;
F_153 ( V_169 , V_281 , V_285 , - 1 ) ;
F_153 ( V_169 , V_280 , V_282 , V_71 -> V_89 . V_214 ) ;
F_153 ( V_169 , V_280 , V_285 , 1 ) ;
* V_279 = F_50 ( V_280 ) ;
return V_281 ;
}
int
F_154 (
struct V_286 * V_169 ,
struct V_79 * V_71 ,
struct V_3 * V_287 ,
struct V_3 * V_41 ,
struct V_3 * V_42 ,
T_2 V_43 )
{
struct V_1 * V_2 = V_71 -> V_77 ;
T_2 V_288 , V_289 , V_290 = 0 ;
struct V_3 * V_291 = NULL ;
struct V_3 * V_292 = NULL ;
struct V_3 * V_293 = NULL ;
struct V_3 * V_294 = NULL ;
struct V_3 * V_295 = NULL ;
struct V_3 * V_296 = NULL ;
int error ;
ASSERT ( F_48 ( V_71 , V_76 | V_278 ) ) ;
ASSERT ( F_33 ( V_2 ) ) ;
V_288 = V_71 -> V_248 ;
V_289 = F_138 ( V_71 ) ?
V_297 : V_298 ;
if ( F_37 ( V_2 ) && V_287 &&
V_71 -> V_89 . V_90 != F_7 ( V_287 -> V_20 . V_21 ) ) {
V_294 = V_287 ;
if ( V_288 ) {
ASSERT ( V_71 -> V_82 ) ;
V_291 = V_71 -> V_82 ;
}
}
if ( F_38 ( V_71 -> V_77 ) && V_41 &&
V_71 -> V_89 . V_92 != F_7 ( V_41 -> V_20 . V_21 ) ) {
V_295 = V_41 ;
if ( V_288 ) {
ASSERT ( V_71 -> V_83 ) ;
V_292 = V_71 -> V_83 ;
}
}
if ( F_39 ( V_71 -> V_77 ) && V_42 &&
F_59 ( V_71 ) != F_7 ( V_42 -> V_20 . V_21 ) ) {
V_290 = V_299 ;
V_296 = V_42 ;
if ( V_288 ) {
ASSERT ( V_71 -> V_84 ) ;
V_293 = V_71 -> V_84 ;
}
}
error = F_155 ( V_169 , V_71 -> V_77 ,
V_294 , V_295 , V_296 ,
V_71 -> V_89 . V_214 , 1 ,
V_43 | V_289 | V_290 ) ;
if ( error )
return error ;
if ( V_288 ) {
ASSERT ( V_294 || V_295 || V_296 ) ;
ASSERT ( V_291 || V_292 || V_293 ) ;
error = F_155 ( NULL , V_71 -> V_77 ,
V_294 , V_295 , V_296 ,
( T_17 ) V_288 , 0 ,
V_43 | V_289 | V_290 ) ;
if ( error )
return error ;
F_155 ( NULL , V_71 -> V_77 ,
V_291 , V_292 , V_293 ,
- ( ( T_17 ) V_288 ) , 0 , V_289 ) ;
}
return ( 0 ) ;
}
int
F_156 (
struct V_79 * * V_300 )
{
struct V_1 * V_2 = V_300 [ 0 ] -> V_77 ;
int V_18 ;
if ( ! F_33 ( V_2 ) || ! F_55 ( V_2 ) )
return 0 ;
for ( V_18 = 0 ; ( V_18 < 4 && V_300 [ V_18 ] ) ; V_18 ++ ) {
struct V_79 * V_71 = V_300 [ V_18 ] ;
int error ;
if ( V_18 == 0 || V_71 != V_300 [ V_18 - 1 ] ) {
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
F_157 (
struct V_286 * V_169 ,
struct V_79 * V_71 ,
struct V_3 * V_287 ,
struct V_3 * V_41 ,
struct V_3 * V_42 )
{
struct V_1 * V_2 = V_169 -> V_301 ;
if ( ! F_33 ( V_2 ) || ! F_55 ( V_2 ) )
return;
ASSERT ( F_48 ( V_71 , V_76 ) ) ;
ASSERT ( F_33 ( V_2 ) ) ;
if ( V_287 && F_37 ( V_2 ) ) {
ASSERT ( V_71 -> V_82 == NULL ) ;
ASSERT ( V_71 -> V_89 . V_90 == F_7 ( V_287 -> V_20 . V_21 ) ) ;
V_71 -> V_82 = F_50 ( V_287 ) ;
F_153 ( V_169 , V_287 , V_285 , 1 ) ;
}
if ( V_41 && F_38 ( V_2 ) ) {
ASSERT ( V_71 -> V_83 == NULL ) ;
ASSERT ( V_71 -> V_89 . V_92 == F_7 ( V_41 -> V_20 . V_21 ) ) ;
V_71 -> V_83 = F_50 ( V_41 ) ;
F_153 ( V_169 , V_41 , V_285 , 1 ) ;
}
if ( V_42 && F_39 ( V_2 ) ) {
ASSERT ( V_71 -> V_84 == NULL ) ;
ASSERT ( F_59 ( V_71 ) == F_7 ( V_42 -> V_20 . V_21 ) ) ;
V_71 -> V_84 = F_50 ( V_42 ) ;
F_153 ( V_169 , V_42 , V_285 , 1 ) ;
}
}
