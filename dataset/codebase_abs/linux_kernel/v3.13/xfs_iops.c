static int
F_1 (
struct V_1 * V_1 ,
const struct V_2 * V_3 ,
void * V_4 )
{
const struct V_2 * V_2 ;
struct V_5 * V_6 = F_2 ( V_1 ) ;
int error = 0 ;
for ( V_2 = V_3 ; V_2 -> V_7 != NULL ; V_2 ++ ) {
error = F_3 ( V_6 , V_2 -> V_7 , V_2 -> V_8 ,
V_2 -> V_9 , V_10 ) ;
if ( error < 0 )
break;
}
return error ;
}
STATIC int
F_4 (
struct V_1 * V_1 ,
struct V_1 * V_11 ,
const struct V_12 * V_12 )
{
return F_5 ( V_1 , V_11 , V_12 ,
& F_1 , NULL ) ;
}
static void
F_6 (
struct V_13 * V_14 ,
struct V_15 * V_15 ,
int V_16 )
{
V_14 -> V_7 = V_15 -> V_17 . V_7 ;
V_14 -> V_18 = V_15 -> V_17 . V_18 ;
V_14 -> type = V_19 [ ( V_16 & V_20 ) >> V_21 ] ;
}
STATIC void
F_7 (
struct V_1 * V_11 ,
struct V_1 * V_1 ,
struct V_15 * V_15 )
{
struct V_13 V_22 ;
F_6 ( & V_22 , V_15 , 0 ) ;
F_8 ( F_2 ( V_11 ) , & V_22 , F_2 ( V_1 ) ) ;
F_9 ( V_1 ) ;
}
STATIC int
F_10 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_16 ,
T_2 V_23 )
{
struct V_1 * V_1 ;
struct V_5 * V_6 = NULL ;
struct V_24 * V_25 = NULL ;
struct V_13 V_7 ;
int error ;
if ( F_11 ( V_16 ) || F_12 ( V_16 ) ) {
if ( F_13 ( ! F_14 ( V_23 ) || F_15 ( V_23 ) & ~ 0x1ff ) )
return - V_26 ;
V_23 = F_16 ( V_23 ) ;
} else {
V_23 = 0 ;
}
if ( F_17 ( V_11 ) ) {
V_25 = F_18 ( V_11 , V_27 ) ;
if ( F_19 ( V_25 ) )
return F_20 ( V_25 ) ;
if ( ! V_25 )
V_16 &= ~ F_21 () ;
}
F_6 ( & V_7 , V_15 , V_16 ) ;
error = F_22 ( F_2 ( V_11 ) , & V_7 , V_16 , V_23 , & V_6 ) ;
if ( F_13 ( error ) )
goto V_28;
V_1 = F_23 ( V_6 ) ;
error = F_4 ( V_1 , V_11 , & V_15 -> V_17 ) ;
if ( F_13 ( error ) )
goto V_29;
if ( V_25 ) {
error = - F_24 ( V_1 , V_25 ) ;
V_25 = NULL ;
if ( F_13 ( error ) )
goto V_29;
}
F_25 ( V_15 , V_1 ) ;
return - error ;
V_29:
F_7 ( V_11 , V_1 , V_15 ) ;
V_28:
F_26 ( V_25 ) ;
return - error ;
}
STATIC int
F_27 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_16 ,
bool V_30 )
{
return F_10 ( V_11 , V_15 , V_16 , 0 ) ;
}
STATIC int
F_28 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_16 )
{
return F_10 ( V_11 , V_15 , V_16 | V_31 , 0 ) ;
}
STATIC struct V_15 *
F_29 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
unsigned int V_30 )
{
struct V_5 * V_32 ;
struct V_13 V_7 ;
int error ;
if ( V_15 -> V_17 . V_18 >= V_33 )
return F_30 ( - V_34 ) ;
F_6 ( & V_7 , V_15 , 0 ) ;
error = F_31 ( F_2 ( V_11 ) , & V_7 , & V_32 , NULL ) ;
if ( F_13 ( error ) ) {
if ( F_13 ( error != V_35 ) )
return F_30 ( - error ) ;
F_32 ( V_15 , NULL ) ;
return NULL ;
}
return F_33 ( F_23 ( V_32 ) , V_15 ) ;
}
STATIC struct V_15 *
F_34 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
unsigned int V_30 )
{
struct V_5 * V_6 ;
struct V_13 V_36 ;
struct V_13 V_37 ;
struct V_12 V_38 ;
int error ;
if ( V_15 -> V_17 . V_18 >= V_33 )
return F_30 ( - V_34 ) ;
F_6 ( & V_36 , V_15 , 0 ) ;
error = F_31 ( F_2 ( V_11 ) , & V_36 , & V_6 , & V_37 ) ;
if ( F_13 ( error ) ) {
if ( F_13 ( error != V_35 ) )
return F_30 ( - error ) ;
return NULL ;
}
if ( ! V_37 . V_7 )
return F_33 ( F_23 ( V_6 ) , V_15 ) ;
V_38 . V_7 = V_37 . V_7 ;
V_38 . V_18 = V_37 . V_18 ;
V_15 = F_35 ( V_15 , F_23 ( V_6 ) , & V_38 ) ;
F_36 ( V_37 . V_7 ) ;
return V_15 ;
}
STATIC int
F_37 (
struct V_15 * V_39 ,
struct V_1 * V_11 ,
struct V_15 * V_15 )
{
struct V_1 * V_1 = V_39 -> V_40 ;
struct V_13 V_7 ;
int error ;
F_6 ( & V_7 , V_15 , V_1 -> V_41 ) ;
error = F_38 ( F_2 ( V_11 ) , F_2 ( V_1 ) , & V_7 ) ;
if ( F_13 ( error ) )
return - error ;
F_39 ( V_1 ) ;
F_25 ( V_15 , V_1 ) ;
return 0 ;
}
STATIC int
F_40 (
struct V_1 * V_11 ,
struct V_15 * V_15 )
{
struct V_13 V_7 ;
int error ;
F_6 ( & V_7 , V_15 , 0 ) ;
error = - F_8 ( F_2 ( V_11 ) , & V_7 , F_2 ( V_15 -> V_40 ) ) ;
if ( error )
return error ;
if ( F_41 ( & F_42 ( V_11 -> V_42 ) -> V_43 ) )
F_43 ( V_15 ) ;
return 0 ;
}
STATIC int
F_44 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
const char * V_44 )
{
struct V_1 * V_1 ;
struct V_5 * V_32 = NULL ;
struct V_13 V_7 ;
int error ;
T_1 V_16 ;
V_16 = V_45 |
( V_46 ? 0777 & ~ F_21 () : V_47 ) ;
F_6 ( & V_7 , V_15 , V_16 ) ;
error = F_45 ( F_2 ( V_11 ) , & V_7 , V_44 , V_16 , & V_32 ) ;
if ( F_13 ( error ) )
goto V_48;
V_1 = F_23 ( V_32 ) ;
error = F_4 ( V_1 , V_11 , & V_15 -> V_17 ) ;
if ( F_13 ( error ) )
goto V_29;
F_25 ( V_15 , V_1 ) ;
return 0 ;
V_29:
F_7 ( V_11 , V_1 , V_15 ) ;
V_48:
return - error ;
}
STATIC int
F_46 (
struct V_1 * V_49 ,
struct V_15 * V_50 ,
struct V_1 * V_51 ,
struct V_15 * V_52 )
{
struct V_1 * V_53 = V_52 -> V_40 ;
struct V_13 V_54 ;
struct V_13 V_55 ;
F_6 ( & V_54 , V_50 , 0 ) ;
F_6 ( & V_55 , V_52 , V_50 -> V_40 -> V_41 ) ;
return - F_47 ( F_2 ( V_49 ) , & V_54 , F_2 ( V_50 -> V_40 ) ,
F_2 ( V_51 ) , & V_55 , V_53 ?
F_2 ( V_53 ) : NULL ) ;
}
STATIC void *
F_48 (
struct V_15 * V_15 ,
struct V_56 * V_57 )
{
char * V_58 ;
int error = - V_59 ;
V_58 = F_49 ( V_60 + 1 , V_61 ) ;
if ( ! V_58 )
goto V_62;
error = - F_50 ( F_2 ( V_15 -> V_40 ) , V_58 ) ;
if ( F_13 ( error ) )
goto V_63;
F_51 ( V_57 , V_58 ) ;
return NULL ;
V_63:
F_52 ( V_58 ) ;
V_62:
F_51 ( V_57 , F_30 ( error ) ) ;
return NULL ;
}
STATIC void
F_53 (
struct V_15 * V_15 ,
struct V_56 * V_57 ,
void * V_64 )
{
char * V_65 = F_54 ( V_57 ) ;
if ( ! F_19 ( V_65 ) )
F_52 ( V_65 ) ;
}
STATIC int
F_55 (
struct V_66 * V_67 ,
struct V_15 * V_15 ,
struct V_68 * V_69 )
{
struct V_1 * V_1 = V_15 -> V_40 ;
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_70 * V_71 = V_6 -> V_72 ;
F_56 ( V_6 ) ;
if ( F_57 ( V_71 ) )
return - F_58 ( V_73 ) ;
V_69 -> V_74 = F_59 ( V_6 ) ;
V_69 -> V_75 = V_1 -> V_42 -> V_76 ;
V_69 -> V_16 = V_6 -> V_77 . V_78 ;
V_69 -> V_79 = V_6 -> V_77 . V_80 ;
V_69 -> V_81 = V_1 -> V_82 ;
V_69 -> V_83 = V_1 -> V_84 ;
V_69 -> V_85 = V_6 -> V_86 ;
V_69 -> V_87 = V_1 -> V_88 ;
V_69 -> V_89 = V_1 -> V_90 ;
V_69 -> ctime = V_1 -> V_91 ;
V_69 -> V_92 =
F_60 ( V_71 , V_6 -> V_77 . V_93 + V_6 -> V_94 ) ;
switch ( V_1 -> V_41 & V_20 ) {
case V_95 :
case V_96 :
V_69 -> V_97 = V_98 ;
V_69 -> V_23 = F_61 ( F_62 ( V_6 -> V_99 . V_100 . V_101 ) & 0x1ff ,
F_63 ( V_6 -> V_99 . V_100 . V_101 ) ) ;
break;
default:
if ( F_64 ( V_6 ) ) {
V_69 -> V_97 =
F_65 ( V_6 ) << V_71 -> V_43 . V_102 ;
} else
V_69 -> V_97 = F_66 ( V_71 ) ;
V_69 -> V_23 = 0 ;
break;
}
return 0 ;
}
static void
F_67 (
struct V_103 * V_104 ,
struct V_5 * V_6 ,
struct V_105 * V_105 )
{
struct V_1 * V_1 = F_23 ( V_6 ) ;
T_1 V_16 = V_105 -> V_106 ;
ASSERT ( V_104 ) ;
ASSERT ( F_68 ( V_6 , V_107 ) ) ;
V_6 -> V_77 . V_78 &= V_20 ;
V_6 -> V_77 . V_78 |= V_16 & ~ V_20 ;
V_1 -> V_41 &= V_20 ;
V_1 -> V_41 |= V_16 & ~ V_20 ;
}
int
F_69 (
struct V_5 * V_6 ,
struct V_105 * V_105 ,
int V_30 )
{
T_3 * V_71 = V_6 -> V_72 ;
struct V_1 * V_1 = F_23 ( V_6 ) ;
int V_108 = V_105 -> V_109 ;
T_4 * V_104 ;
int error ;
T_5 V_81 = V_110 , V_111 = V_110 ;
T_6 V_83 = V_112 , V_113 = V_112 ;
struct V_114 * V_115 = NULL , * V_116 = NULL ;
struct V_114 * V_117 = NULL , * V_118 = NULL ;
F_70 ( V_6 ) ;
if ( ! ( V_30 & V_119 ) ) {
if ( V_71 -> V_120 & V_121 )
return F_58 ( V_122 ) ;
if ( F_57 ( V_71 ) )
return F_58 ( V_73 ) ;
error = - F_71 ( V_1 , V_105 ) ;
if ( error )
return F_58 ( error ) ;
}
ASSERT ( ( V_108 & V_123 ) == 0 ) ;
if ( F_72 ( V_71 ) && ( V_108 & ( V_124 | V_125 ) ) ) {
T_7 V_126 = 0 ;
if ( ( V_108 & V_124 ) && F_73 ( V_71 ) ) {
V_81 = V_105 -> V_127 ;
V_126 |= V_128 ;
} else {
V_81 = V_1 -> V_82 ;
}
if ( ( V_108 & V_125 ) && F_74 ( V_71 ) ) {
V_83 = V_105 -> V_129 ;
V_126 |= V_130 ;
} else {
V_83 = V_1 -> V_84 ;
}
ASSERT ( V_115 == NULL ) ;
ASSERT ( V_116 == NULL ) ;
error = F_75 ( V_6 , F_76 ( V_81 ) ,
F_77 ( V_83 ) ,
F_78 ( V_6 ) ,
V_126 , & V_115 , & V_116 , NULL ) ;
if ( error )
return error ;
}
V_104 = F_79 ( V_71 , V_131 ) ;
error = F_80 ( V_104 , & F_81 ( V_71 ) -> V_132 , 0 , 0 ) ;
if ( error )
goto V_133;
F_82 ( V_6 , V_107 ) ;
if ( V_108 & ( V_124 | V_125 ) ) {
V_111 = V_1 -> V_82 ;
V_113 = V_1 -> V_84 ;
V_83 = ( V_108 & V_125 ) ? V_105 -> V_129 : V_113 ;
V_81 = ( V_108 & V_124 ) ? V_105 -> V_127 : V_111 ;
if ( F_83 ( V_71 ) &&
( ( F_73 ( V_71 ) && ! F_84 ( V_111 , V_81 ) ) ||
( F_74 ( V_71 ) && ! F_85 ( V_113 , V_83 ) ) ) ) {
ASSERT ( V_104 ) ;
error = F_86 ( V_104 , V_6 , V_115 , V_116 ,
NULL , F_87 ( V_134 ) ?
V_135 : 0 ) ;
if ( error )
goto V_136;
}
}
F_88 ( V_104 , V_6 , 0 ) ;
if ( V_108 & ( V_124 | V_125 ) ) {
if ( ( V_6 -> V_77 . V_78 & ( V_137 | V_138 ) ) &&
! F_87 ( V_139 ) )
V_6 -> V_77 . V_78 &= ~ ( V_137 | V_138 ) ;
if ( ! F_84 ( V_111 , V_81 ) ) {
if ( F_83 ( V_71 ) && F_73 ( V_71 ) ) {
ASSERT ( V_108 & V_124 ) ;
ASSERT ( V_115 ) ;
V_117 = F_89 ( V_104 , V_6 ,
& V_6 -> V_140 , V_115 ) ;
}
V_6 -> V_77 . V_141 = F_76 ( V_81 ) ;
V_1 -> V_82 = V_81 ;
}
if ( ! F_85 ( V_113 , V_83 ) ) {
if ( F_83 ( V_71 ) && F_74 ( V_71 ) ) {
ASSERT ( F_90 ( & V_71 -> V_43 ) ||
! F_91 ( V_71 ) ) ;
ASSERT ( V_108 & V_125 ) ;
ASSERT ( V_116 ) ;
V_118 = F_89 ( V_104 , V_6 ,
& V_6 -> V_142 , V_116 ) ;
}
V_6 -> V_77 . V_143 = F_77 ( V_83 ) ;
V_1 -> V_84 = V_83 ;
}
}
if ( V_108 & V_144 )
F_67 ( V_104 , V_6 , V_105 ) ;
if ( V_108 & V_145 ) {
V_1 -> V_88 = V_105 -> V_146 ;
V_6 -> V_77 . V_147 . V_148 = V_105 -> V_146 . V_149 ;
V_6 -> V_77 . V_147 . V_150 = V_105 -> V_146 . V_151 ;
}
if ( V_108 & V_152 ) {
V_1 -> V_91 = V_105 -> V_153 ;
V_6 -> V_77 . V_154 . V_148 = V_105 -> V_153 . V_149 ;
V_6 -> V_77 . V_154 . V_150 = V_105 -> V_153 . V_151 ;
}
if ( V_108 & V_155 ) {
V_1 -> V_90 = V_105 -> V_156 ;
V_6 -> V_77 . V_157 . V_148 = V_105 -> V_156 . V_149 ;
V_6 -> V_77 . V_157 . V_150 = V_105 -> V_156 . V_151 ;
}
F_92 ( V_104 , V_6 , V_158 ) ;
F_93 ( V_159 ) ;
if ( V_71 -> V_120 & V_160 )
F_94 ( V_104 ) ;
error = F_95 ( V_104 , 0 ) ;
F_96 ( V_6 , V_107 ) ;
F_97 ( V_117 ) ;
F_97 ( V_118 ) ;
F_97 ( V_115 ) ;
F_97 ( V_116 ) ;
if ( error )
return F_58 ( error ) ;
if ( ( V_108 & V_144 ) && ! ( V_30 & V_119 ) ) {
error = - F_98 ( V_1 ) ;
if ( error )
return F_58 ( error ) ;
}
return 0 ;
V_136:
F_99 ( V_104 , 0 ) ;
F_96 ( V_6 , V_107 ) ;
V_133:
F_97 ( V_115 ) ;
F_97 ( V_116 ) ;
return error ;
}
int
F_100 (
struct V_5 * V_6 ,
struct V_105 * V_105 )
{
struct V_70 * V_71 = V_6 -> V_72 ;
struct V_1 * V_1 = F_23 ( V_6 ) ;
int V_108 = V_105 -> V_109 ;
T_8 V_161 , V_162 ;
struct V_103 * V_104 ;
int error ;
T_7 V_163 = 0 ;
T_7 V_164 = 0 ;
F_70 ( V_6 ) ;
if ( V_71 -> V_120 & V_121 )
return F_58 ( V_122 ) ;
if ( F_57 ( V_71 ) )
return F_58 ( V_73 ) ;
error = - F_71 ( V_1 , V_105 ) ;
if ( error )
return F_58 ( error ) ;
ASSERT ( F_68 ( V_6 , V_165 ) ) ;
ASSERT ( F_101 ( V_6 -> V_77 . V_78 ) ) ;
ASSERT ( ( V_108 & ( V_124 | V_125 | V_145 | V_166 |
V_167 | V_168 | V_169 ) ) == 0 ) ;
V_161 = V_1 -> V_170 ;
V_162 = V_105 -> V_171 ;
if ( V_162 == 0 && V_161 == 0 && V_6 -> V_77 . V_172 == 0 ) {
if ( ! ( V_108 & ( V_152 | V_155 ) ) )
return 0 ;
V_105 -> V_109 &= ~ V_123 ;
return F_69 ( V_6 , V_105 , 0 ) ;
}
error = F_102 ( V_6 , 0 ) ;
if ( error )
return error ;
if ( V_162 > V_161 ) {
error = F_103 ( V_6 , V_162 , V_161 ) ;
if ( error )
return error ;
}
if ( V_161 != V_6 -> V_77 . V_173 && V_162 > V_6 -> V_77 . V_173 ) {
error = - F_104 ( F_23 ( V_6 ) -> V_174 ,
V_6 -> V_77 . V_173 , V_162 ) ;
if ( error )
return error ;
}
F_105 ( V_1 ) ;
error = - F_106 ( V_1 -> V_174 , V_162 , V_175 ) ;
if ( error )
return error ;
V_104 = F_79 ( V_71 , V_176 ) ;
error = F_80 ( V_104 , & F_81 ( V_71 ) -> V_177 , 0 , 0 ) ;
if ( error )
goto V_136;
F_107 ( V_1 , V_162 ) ;
V_164 = V_178 ;
V_163 |= V_107 ;
F_82 ( V_6 , V_107 ) ;
F_88 ( V_104 , V_6 , 0 ) ;
if ( V_162 != V_161 && ( ! ( V_108 & ( V_152 | V_155 ) ) ) ) {
V_105 -> V_153 = V_105 -> V_156 =
F_108 ( V_1 -> V_42 ) ;
V_108 |= V_152 | V_155 ;
}
V_6 -> V_77 . V_173 = V_162 ;
F_92 ( V_104 , V_6 , V_158 ) ;
if ( V_162 <= V_161 ) {
error = F_109 ( & V_104 , V_6 , V_179 , V_162 ) ;
if ( error )
goto V_180;
F_110 ( V_6 , V_181 ) ;
F_111 ( V_6 ) ;
}
if ( V_108 & V_144 )
F_67 ( V_104 , V_6 , V_105 ) ;
if ( V_108 & V_152 ) {
V_1 -> V_91 = V_105 -> V_153 ;
V_6 -> V_77 . V_154 . V_148 = V_105 -> V_153 . V_149 ;
V_6 -> V_77 . V_154 . V_150 = V_105 -> V_153 . V_151 ;
}
if ( V_108 & V_155 ) {
V_1 -> V_90 = V_105 -> V_156 ;
V_6 -> V_77 . V_157 . V_148 = V_105 -> V_156 . V_149 ;
V_6 -> V_77 . V_157 . V_150 = V_105 -> V_156 . V_151 ;
}
F_92 ( V_104 , V_6 , V_158 ) ;
F_93 ( V_159 ) ;
if ( V_71 -> V_120 & V_160 )
F_94 ( V_104 ) ;
error = F_95 ( V_104 , V_178 ) ;
V_182:
if ( V_163 )
F_96 ( V_6 , V_163 ) ;
return error ;
V_180:
V_164 |= V_183 ;
V_136:
F_99 ( V_104 , V_164 ) ;
goto V_182;
}
STATIC int
F_112 (
struct V_15 * V_15 ,
struct V_105 * V_105 )
{
struct V_5 * V_6 = F_2 ( V_15 -> V_40 ) ;
int error ;
if ( V_105 -> V_109 & V_123 ) {
F_82 ( V_6 , V_165 ) ;
error = F_100 ( V_6 , V_105 ) ;
F_96 ( V_6 , V_165 ) ;
} else {
error = F_69 ( V_6 , V_105 , 0 ) ;
}
return - error ;
}
STATIC int
F_113 (
struct V_1 * V_1 ,
struct V_184 * V_185 ,
int V_30 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_70 * V_71 = V_6 -> V_72 ;
struct V_103 * V_104 ;
int error ;
F_114 ( V_6 ) ;
V_104 = F_79 ( V_71 , V_186 ) ;
error = F_80 ( V_104 , & F_81 ( V_71 ) -> V_187 , 0 , 0 ) ;
if ( error ) {
F_99 ( V_104 , 0 ) ;
return - error ;
}
F_82 ( V_6 , V_107 ) ;
if ( V_30 & V_188 ) {
V_1 -> V_91 = * V_185 ;
V_6 -> V_77 . V_154 . V_148 = ( V_189 ) V_185 -> V_149 ;
V_6 -> V_77 . V_154 . V_150 = ( V_189 ) V_185 -> V_151 ;
}
if ( V_30 & V_190 ) {
V_1 -> V_90 = * V_185 ;
V_6 -> V_77 . V_157 . V_148 = ( V_189 ) V_185 -> V_149 ;
V_6 -> V_77 . V_157 . V_150 = ( V_189 ) V_185 -> V_151 ;
}
if ( V_30 & V_191 ) {
V_1 -> V_88 = * V_185 ;
V_6 -> V_77 . V_147 . V_148 = ( V_189 ) V_185 -> V_149 ;
V_6 -> V_77 . V_147 . V_150 = ( V_189 ) V_185 -> V_151 ;
}
F_88 ( V_104 , V_6 , V_107 ) ;
F_92 ( V_104 , V_6 , V_192 ) ;
return - F_95 ( V_104 , 0 ) ;
}
STATIC int
F_115 (
void * * V_193 ,
struct V_194 * V_195 ,
int * V_196 )
{
int error ;
struct V_197 * V_198 = * V_193 ;
T_9 V_199 = 0 ;
T_10 V_200 , V_201 , V_202 ;
if ( V_195 -> V_203 == - 1LL )
return 0 ;
V_200 = F_116 ( V_195 -> V_204 ) ;
V_201 = F_116 ( V_195 -> V_203 ) ;
V_202 = F_116 ( V_195 -> V_205 ) ;
if ( V_195 -> V_206 & V_207 )
V_199 |= V_208 ;
else if ( V_195 -> V_206 & V_209 ) {
V_199 |= ( V_210 |
V_211 ) ;
V_201 = 0 ;
}
if ( V_195 -> V_206 & V_212 )
V_199 |= V_213 ;
error = F_117 ( V_198 , V_200 , V_201 ,
V_202 , V_199 ) ;
if ( error > 0 ) {
error = 0 ;
* V_196 = 1 ;
}
return - error ;
}
STATIC int
F_118 (
struct V_1 * V_1 ,
struct V_197 * V_198 ,
T_10 V_214 ,
T_10 V_202 )
{
T_11 * V_6 = F_2 ( V_1 ) ;
struct V_194 V_215 ;
int error ;
error = F_119 ( V_198 , V_216 ) ;
if ( error )
return error ;
V_215 . V_204 = F_120 ( V_214 ) ;
if ( V_202 == V_217 )
V_215 . V_205 = - 1LL ;
else
V_215 . V_205 = F_120 ( V_202 ) ;
V_215 . V_218 = ! V_198 -> V_219 ? V_220 :
V_198 -> V_219 + 1 ;
V_215 . V_218 = F_121 ( V_221 , V_215 . V_218 ,
( V_222 * 16 / sizeof( struct V_194 ) ) ) ;
V_215 . V_223 = V_224 | V_225 ;
if ( V_198 -> V_226 & V_227 )
V_215 . V_223 |= V_228 ;
if ( ! ( V_198 -> V_226 & V_229 ) )
V_215 . V_223 |= V_230 ;
error = F_122 ( V_6 , & V_215 , F_115 , V_198 ) ;
if ( error )
return - error ;
return 0 ;
}
STATIC void
F_123 (
struct V_1 * V_1 ,
struct V_5 * V_6 )
{
if ( V_6 -> V_77 . V_231 & V_232 )
V_1 -> V_233 |= V_234 ;
else
V_1 -> V_233 &= ~ V_234 ;
if ( V_6 -> V_77 . V_231 & V_235 )
V_1 -> V_233 |= V_236 ;
else
V_1 -> V_233 &= ~ V_236 ;
if ( V_6 -> V_77 . V_231 & V_237 )
V_1 -> V_233 |= V_238 ;
else
V_1 -> V_233 &= ~ V_238 ;
if ( V_6 -> V_77 . V_231 & V_239 )
V_1 -> V_233 |= V_240 ;
else
V_1 -> V_233 &= ~ V_240 ;
}
void
F_124 (
struct V_5 * V_6 )
{
struct V_1 * V_1 = & V_6 -> V_241 ;
T_12 V_242 ;
V_1 -> V_86 = V_6 -> V_86 ;
V_1 -> V_243 = V_244 ;
F_125 ( V_1 ) ;
F_126 ( & V_1 -> V_245 ) ;
V_1 -> V_41 = V_6 -> V_77 . V_78 ;
F_127 ( V_1 , V_6 -> V_77 . V_80 ) ;
V_1 -> V_82 = F_128 ( V_6 -> V_77 . V_141 ) ;
V_1 -> V_84 = F_129 ( V_6 -> V_77 . V_143 ) ;
switch ( V_1 -> V_41 & V_20 ) {
case V_95 :
case V_96 :
V_1 -> V_246 =
F_61 ( F_62 ( V_6 -> V_99 . V_100 . V_101 ) & 0x1ff ,
F_63 ( V_6 -> V_99 . V_100 . V_101 ) ) ;
break;
default:
V_1 -> V_246 = 0 ;
break;
}
V_1 -> V_247 = V_6 -> V_77 . V_248 ;
F_130 ( V_1 , V_6 -> V_77 . V_173 ) ;
V_1 -> V_88 . V_149 = V_6 -> V_77 . V_147 . V_148 ;
V_1 -> V_88 . V_151 = V_6 -> V_77 . V_147 . V_150 ;
V_1 -> V_90 . V_149 = V_6 -> V_77 . V_157 . V_148 ;
V_1 -> V_90 . V_151 = V_6 -> V_77 . V_157 . V_150 ;
V_1 -> V_91 . V_149 = V_6 -> V_77 . V_154 . V_148 ;
V_1 -> V_91 . V_151 = V_6 -> V_77 . V_154 . V_150 ;
F_123 ( V_1 , V_6 ) ;
V_6 -> V_249 = V_6 -> V_72 -> V_250 ;
switch ( V_1 -> V_41 & V_20 ) {
case V_251 :
V_1 -> V_252 = & V_253 ;
V_1 -> V_254 = & V_255 ;
V_1 -> V_174 -> V_256 = & V_257 ;
break;
case V_31 :
if ( F_41 ( & F_42 ( V_1 -> V_42 ) -> V_43 ) )
V_1 -> V_252 = & V_258 ;
else
V_1 -> V_252 = & V_259 ;
V_1 -> V_254 = & V_260 ;
V_6 -> V_249 = V_6 -> V_72 -> V_261 ;
break;
case V_45 :
V_1 -> V_252 = & V_262 ;
if ( ! ( V_6 -> V_99 . V_263 & V_264 ) )
V_1 -> V_174 -> V_256 = & V_257 ;
break;
default:
V_1 -> V_252 = & V_253 ;
F_131 ( V_1 , V_1 -> V_41 , V_1 -> V_246 ) ;
break;
}
V_242 = F_132 ( V_1 -> V_174 ) ;
F_133 ( V_1 -> V_174 , ( V_242 & ~ ( V_265 ) ) ) ;
if ( ! F_134 ( V_6 ) ) {
F_135 ( V_1 ) ;
F_136 ( V_1 ) ;
}
F_137 ( V_6 , V_266 ) ;
F_138 () ;
F_139 ( V_1 ) ;
}
