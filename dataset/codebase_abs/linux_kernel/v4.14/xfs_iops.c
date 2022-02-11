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
struct V_15 * V_15 )
{
V_14 -> V_7 = V_15 -> V_16 . V_7 ;
V_14 -> V_17 = V_15 -> V_16 . V_17 ;
V_14 -> type = V_18 ;
}
static int
F_7 (
struct V_13 * V_14 ,
struct V_15 * V_15 ,
int V_19 )
{
V_14 -> V_7 = V_15 -> V_16 . V_7 ;
V_14 -> V_17 = V_15 -> V_16 . V_17 ;
V_14 -> type = F_8 ( V_19 ) ;
if ( F_9 ( V_14 -> type == V_18 ) )
return - V_20 ;
return 0 ;
}
STATIC void
F_10 (
struct V_1 * V_11 ,
struct V_1 * V_1 ,
struct V_15 * V_15 )
{
struct V_13 V_21 ;
F_6 ( & V_21 , V_15 ) ;
F_11 ( F_2 ( V_11 ) , & V_21 , F_2 ( V_1 ) ) ;
}
STATIC int
F_12 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_19 ,
T_2 V_22 ,
bool tmpfile )
{
struct V_1 * V_1 ;
struct V_5 * V_6 = NULL ;
struct V_23 * V_24 , * V_25 ;
struct V_13 V_7 ;
int error ;
if ( F_13 ( V_19 ) || F_14 ( V_19 ) ) {
if ( F_9 ( ! F_15 ( V_22 ) || F_16 ( V_22 ) & ~ 0x1ff ) )
return - V_26 ;
V_22 = F_17 ( V_22 ) ;
} else {
V_22 = 0 ;
}
error = F_18 ( V_11 , & V_19 , & V_24 , & V_25 ) ;
if ( error )
return error ;
error = F_7 ( & V_7 , V_15 , V_19 ) ;
if ( F_9 ( error ) )
goto V_27;
if ( ! tmpfile ) {
error = F_19 ( F_2 ( V_11 ) , & V_7 , V_19 , V_22 , & V_6 ) ;
} else {
error = F_20 ( F_2 ( V_11 ) , V_15 , V_19 , & V_6 ) ;
}
if ( F_9 ( error ) )
goto V_27;
V_1 = F_21 ( V_6 ) ;
error = F_4 ( V_1 , V_11 , & V_15 -> V_16 ) ;
if ( F_9 ( error ) )
goto V_28;
#ifdef F_22
if ( V_24 ) {
error = F_23 ( V_1 , V_24 , V_29 ) ;
if ( error )
goto V_28;
}
if ( V_25 ) {
error = F_23 ( V_1 , V_25 , V_30 ) ;
if ( error )
goto V_28;
}
#endif
F_24 ( V_6 ) ;
if ( tmpfile )
F_25 ( V_15 , V_1 ) ;
else
F_26 ( V_15 , V_1 ) ;
F_27 ( V_6 ) ;
V_27:
if ( V_24 )
F_28 ( V_24 ) ;
if ( V_25 )
F_28 ( V_25 ) ;
return error ;
V_28:
F_27 ( V_6 ) ;
if ( ! tmpfile )
F_10 ( V_11 , V_1 , V_15 ) ;
F_29 ( V_1 ) ;
goto V_27;
}
STATIC int
F_30 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_19 ,
T_2 V_22 )
{
return F_12 ( V_11 , V_15 , V_19 , V_22 , false ) ;
}
STATIC int
F_31 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_19 ,
bool V_31 )
{
return F_30 ( V_11 , V_15 , V_19 , 0 ) ;
}
STATIC int
F_32 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_19 )
{
return F_30 ( V_11 , V_15 , V_19 | V_32 , 0 ) ;
}
STATIC struct V_15 *
F_33 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
unsigned int V_31 )
{
struct V_5 * V_33 ;
struct V_13 V_7 ;
int error ;
if ( V_15 -> V_16 . V_17 >= V_34 )
return F_34 ( - V_35 ) ;
F_6 ( & V_7 , V_15 ) ;
error = F_35 ( F_2 ( V_11 ) , & V_7 , & V_33 , NULL ) ;
if ( F_9 ( error ) ) {
if ( F_9 ( error != - V_36 ) )
return F_34 ( error ) ;
F_36 ( V_15 , NULL ) ;
return NULL ;
}
return F_37 ( F_21 ( V_33 ) , V_15 ) ;
}
STATIC struct V_15 *
F_38 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
unsigned int V_31 )
{
struct V_5 * V_6 ;
struct V_13 V_37 ;
struct V_13 V_38 ;
struct V_12 V_39 ;
int error ;
if ( V_15 -> V_16 . V_17 >= V_34 )
return F_34 ( - V_35 ) ;
F_6 ( & V_37 , V_15 ) ;
error = F_35 ( F_2 ( V_11 ) , & V_37 , & V_6 , & V_38 ) ;
if ( F_9 ( error ) ) {
if ( F_9 ( error != - V_36 ) )
return F_34 ( error ) ;
return NULL ;
}
if ( ! V_38 . V_7 )
return F_37 ( F_21 ( V_6 ) , V_15 ) ;
V_39 . V_7 = V_38 . V_7 ;
V_39 . V_17 = V_38 . V_17 ;
V_15 = F_39 ( V_15 , F_21 ( V_6 ) , & V_39 ) ;
F_40 ( V_38 . V_7 ) ;
return V_15 ;
}
STATIC int
F_41 (
struct V_15 * V_40 ,
struct V_1 * V_11 ,
struct V_15 * V_15 )
{
struct V_1 * V_1 = F_42 ( V_40 ) ;
struct V_13 V_7 ;
int error ;
error = F_7 ( & V_7 , V_15 , V_1 -> V_41 ) ;
if ( F_9 ( error ) )
return error ;
error = F_43 ( F_2 ( V_11 ) , F_2 ( V_1 ) , & V_7 ) ;
if ( F_9 ( error ) )
return error ;
F_44 ( V_1 ) ;
F_26 ( V_15 , V_1 ) ;
return 0 ;
}
STATIC int
F_45 (
struct V_1 * V_11 ,
struct V_15 * V_15 )
{
struct V_13 V_7 ;
int error ;
F_6 ( & V_7 , V_15 ) ;
error = F_11 ( F_2 ( V_11 ) , & V_7 , F_2 ( F_42 ( V_15 ) ) ) ;
if ( error )
return error ;
if ( F_46 ( & F_47 ( V_11 -> V_42 ) -> V_43 ) )
F_48 ( V_15 ) ;
return 0 ;
}
STATIC int
F_49 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
const char * V_44 )
{
struct V_1 * V_1 ;
struct V_5 * V_33 = NULL ;
struct V_13 V_7 ;
int error ;
T_1 V_19 ;
V_19 = V_45 |
( V_46 ? 0777 & ~ F_50 () : V_47 ) ;
error = F_7 ( & V_7 , V_15 , V_19 ) ;
if ( F_9 ( error ) )
goto V_48;
error = F_51 ( F_2 ( V_11 ) , & V_7 , V_44 , V_19 , & V_33 ) ;
if ( F_9 ( error ) )
goto V_48;
V_1 = F_21 ( V_33 ) ;
error = F_4 ( V_1 , V_11 , & V_15 -> V_16 ) ;
if ( F_9 ( error ) )
goto V_28;
F_24 ( V_33 ) ;
F_26 ( V_15 , V_1 ) ;
F_27 ( V_33 ) ;
return 0 ;
V_28:
F_27 ( V_33 ) ;
F_10 ( V_11 , V_1 , V_15 ) ;
F_29 ( V_1 ) ;
V_48:
return error ;
}
STATIC int
F_52 (
struct V_1 * V_49 ,
struct V_15 * V_50 ,
struct V_1 * V_51 ,
struct V_15 * V_52 ,
unsigned int V_31 )
{
struct V_1 * V_53 = F_42 ( V_52 ) ;
int V_54 = 0 ;
int error ;
struct V_13 V_55 ;
struct V_13 V_56 ;
if ( V_31 & ~ ( V_57 | V_58 | V_59 ) )
return - V_26 ;
if ( V_31 & V_58 )
V_54 = F_42 ( V_52 ) -> V_41 ;
error = F_7 ( & V_55 , V_50 , V_54 ) ;
if ( V_54 && F_9 ( error ) )
return error ;
error = F_7 ( & V_56 , V_52 ,
F_42 ( V_50 ) -> V_41 ) ;
if ( F_9 ( error ) )
return error ;
return F_53 ( F_2 ( V_49 ) , & V_55 , F_2 ( F_42 ( V_50 ) ) ,
F_2 ( V_51 ) , & V_56 ,
V_53 ? F_2 ( V_53 ) : NULL , V_31 ) ;
}
STATIC const char *
F_54 (
struct V_15 * V_15 ,
struct V_1 * V_1 ,
struct V_60 * V_61 )
{
char * V_62 ;
int error = - V_63 ;
if ( ! V_15 )
return F_34 ( - V_64 ) ;
V_62 = F_55 ( V_65 + 1 , V_66 ) ;
if ( ! V_62 )
goto V_67;
error = F_56 ( F_2 ( F_42 ( V_15 ) ) , V_62 ) ;
if ( F_9 ( error ) )
goto V_68;
F_57 ( V_61 , V_69 , V_62 ) ;
return V_62 ;
V_68:
F_58 ( V_62 ) ;
V_67:
return F_34 ( error ) ;
}
STATIC const char *
F_59 (
struct V_15 * V_15 ,
struct V_1 * V_1 ,
struct V_60 * V_61 )
{
ASSERT ( F_2 ( V_1 ) -> V_70 . V_71 & V_72 ) ;
return F_2 ( V_1 ) -> V_70 . V_73 . V_74 ;
}
STATIC int
F_60 (
const struct V_75 * V_75 ,
struct V_76 * V_77 ,
T_3 V_78 ,
unsigned int V_79 )
{
struct V_1 * V_1 = F_42 ( V_75 -> V_15 ) ;
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_80 * V_81 = V_6 -> V_82 ;
F_61 ( V_6 ) ;
if ( F_62 ( V_81 ) )
return - V_83 ;
V_77 -> V_84 = F_63 ( V_6 ) ;
V_77 -> V_85 = V_1 -> V_42 -> V_86 ;
V_77 -> V_19 = V_1 -> V_41 ;
V_77 -> V_87 = V_1 -> V_88 ;
V_77 -> V_89 = V_1 -> V_90 ;
V_77 -> V_91 = V_1 -> V_92 ;
V_77 -> V_93 = V_6 -> V_94 ;
V_77 -> V_95 = V_1 -> V_96 ;
V_77 -> V_97 = V_1 -> V_98 ;
V_77 -> ctime = V_1 -> V_99 ;
V_77 -> V_100 =
F_64 ( V_81 , V_6 -> V_101 . V_102 + V_6 -> V_103 ) ;
if ( V_6 -> V_101 . V_104 == 3 ) {
if ( V_78 & V_105 ) {
V_77 -> V_106 |= V_105 ;
V_77 -> V_107 . V_108 = V_6 -> V_101 . V_109 . V_110 ;
V_77 -> V_107 . V_111 = V_6 -> V_101 . V_109 . V_112 ;
}
}
if ( V_6 -> V_101 . V_113 & V_114 )
V_77 -> V_115 |= V_116 ;
if ( V_6 -> V_101 . V_113 & V_117 )
V_77 -> V_115 |= V_118 ;
if ( V_6 -> V_101 . V_113 & V_119 )
V_77 -> V_115 |= V_120 ;
switch ( V_1 -> V_41 & V_121 ) {
case V_122 :
case V_123 :
V_77 -> V_124 = V_125 ;
V_77 -> V_22 = F_65 ( F_66 ( V_6 -> V_70 . V_126 . V_127 ) & 0x1ff ,
F_67 ( V_6 -> V_70 . V_126 . V_127 ) ) ;
break;
default:
if ( F_68 ( V_6 ) ) {
V_77 -> V_124 =
F_69 ( V_6 ) << V_81 -> V_43 . V_128 ;
} else
V_77 -> V_124 = F_70 ( V_81 ) ;
V_77 -> V_22 = 0 ;
break;
}
return 0 ;
}
static void
F_71 (
struct V_5 * V_6 ,
struct V_129 * V_129 )
{
struct V_1 * V_1 = F_21 ( V_6 ) ;
T_1 V_19 = V_129 -> V_130 ;
ASSERT ( F_72 ( V_6 , V_131 ) ) ;
V_1 -> V_41 &= V_121 ;
V_1 -> V_41 |= V_19 & ~ V_121 ;
}
void
F_73 (
struct V_5 * V_6 ,
struct V_129 * V_129 )
{
struct V_1 * V_1 = F_21 ( V_6 ) ;
ASSERT ( F_72 ( V_6 , V_131 ) ) ;
if ( V_129 -> V_132 & V_133 )
V_1 -> V_96 = V_129 -> V_134 ;
if ( V_129 -> V_132 & V_135 )
V_1 -> V_99 = V_129 -> V_136 ;
if ( V_129 -> V_132 & V_137 )
V_1 -> V_98 = V_129 -> V_138 ;
}
static int
F_74 (
struct V_15 * V_15 ,
struct V_129 * V_129 )
{
struct V_80 * V_81 = F_2 ( F_42 ( V_15 ) ) -> V_82 ;
if ( V_81 -> V_139 & V_140 )
return - V_141 ;
if ( F_62 ( V_81 ) )
return - V_83 ;
return F_75 ( V_15 , V_129 ) ;
}
int
F_76 (
struct V_5 * V_6 ,
struct V_129 * V_129 ,
int V_31 )
{
T_4 * V_81 = V_6 -> V_82 ;
struct V_1 * V_1 = F_21 ( V_6 ) ;
int V_142 = V_129 -> V_132 ;
T_5 * V_143 ;
int error ;
T_6 V_89 = V_144 , V_145 = V_144 ;
T_7 V_91 = V_146 , V_147 = V_146 ;
struct V_148 * V_149 = NULL , * V_150 = NULL ;
struct V_148 * V_151 = NULL , * V_152 = NULL ;
ASSERT ( ( V_142 & V_153 ) == 0 ) ;
if ( F_77 ( V_81 ) && ( V_142 & ( V_154 | V_155 ) ) ) {
T_8 V_156 = 0 ;
if ( ( V_142 & V_154 ) && F_78 ( V_81 ) ) {
V_89 = V_129 -> V_157 ;
V_156 |= V_158 ;
} else {
V_89 = V_1 -> V_90 ;
}
if ( ( V_142 & V_155 ) && F_79 ( V_81 ) ) {
V_91 = V_129 -> V_159 ;
V_156 |= V_160 ;
} else {
V_91 = V_1 -> V_92 ;
}
ASSERT ( V_149 == NULL ) ;
ASSERT ( V_150 == NULL ) ;
error = F_80 ( V_6 , F_81 ( V_89 ) ,
F_82 ( V_91 ) ,
F_83 ( V_6 ) ,
V_156 , & V_149 , & V_150 , NULL ) ;
if ( error )
return error ;
}
error = F_84 ( V_81 , & F_85 ( V_81 ) -> V_161 , 0 , 0 , 0 , & V_143 ) ;
if ( error )
goto V_162;
F_86 ( V_6 , V_131 ) ;
F_87 ( V_143 , V_6 , 0 ) ;
if ( V_142 & ( V_154 | V_155 ) ) {
V_145 = V_1 -> V_90 ;
V_147 = V_1 -> V_92 ;
V_91 = ( V_142 & V_155 ) ? V_129 -> V_159 : V_147 ;
V_89 = ( V_142 & V_154 ) ? V_129 -> V_157 : V_145 ;
if ( F_88 ( V_81 ) &&
( ( F_78 ( V_81 ) && ! F_89 ( V_145 , V_89 ) ) ||
( F_79 ( V_81 ) && ! F_90 ( V_147 , V_91 ) ) ) ) {
ASSERT ( V_143 ) ;
error = F_91 ( V_143 , V_6 , V_149 , V_150 ,
NULL , F_92 ( V_163 ) ?
V_164 : 0 ) ;
if ( error )
goto V_165;
}
}
if ( V_142 & ( V_154 | V_155 ) ) {
if ( ( V_1 -> V_41 & ( V_166 | V_167 ) ) &&
! F_92 ( V_168 ) )
V_1 -> V_41 &= ~ ( V_166 | V_167 ) ;
if ( ! F_89 ( V_145 , V_89 ) ) {
if ( F_88 ( V_81 ) && F_78 ( V_81 ) ) {
ASSERT ( V_142 & V_154 ) ;
ASSERT ( V_149 ) ;
V_151 = F_93 ( V_143 , V_6 ,
& V_6 -> V_169 , V_149 ) ;
}
V_6 -> V_101 . V_170 = F_81 ( V_89 ) ;
V_1 -> V_90 = V_89 ;
}
if ( ! F_90 ( V_147 , V_91 ) ) {
if ( F_88 ( V_81 ) && F_79 ( V_81 ) ) {
ASSERT ( F_94 ( & V_81 -> V_43 ) ||
! F_95 ( V_81 ) ) ;
ASSERT ( V_142 & V_155 ) ;
ASSERT ( V_150 ) ;
V_152 = F_93 ( V_143 , V_6 ,
& V_6 -> V_171 , V_150 ) ;
}
V_6 -> V_101 . V_172 = F_82 ( V_91 ) ;
V_1 -> V_92 = V_91 ;
}
}
if ( V_142 & V_173 )
F_71 ( V_6 , V_129 ) ;
if ( V_142 & ( V_133 | V_135 | V_137 ) )
F_73 ( V_6 , V_129 ) ;
F_96 ( V_143 , V_6 , V_174 ) ;
F_97 ( V_81 , V_175 ) ;
if ( V_81 -> V_139 & V_176 )
F_98 ( V_143 ) ;
error = F_99 ( V_143 ) ;
F_100 ( V_6 , V_131 ) ;
F_101 ( V_151 ) ;
F_101 ( V_152 ) ;
F_101 ( V_149 ) ;
F_101 ( V_150 ) ;
if ( error )
return error ;
if ( ( V_142 & V_173 ) && ! ( V_31 & V_177 ) ) {
error = F_102 ( V_1 , V_1 -> V_41 ) ;
if ( error )
return error ;
}
return 0 ;
V_165:
F_103 ( V_143 ) ;
V_162:
F_101 ( V_149 ) ;
F_101 ( V_150 ) ;
return error ;
}
int
F_104 (
struct V_15 * V_15 ,
struct V_129 * V_129 )
{
struct V_5 * V_6 = F_2 ( F_42 ( V_15 ) ) ;
int error ;
F_105 ( V_6 ) ;
error = F_74 ( V_15 , V_129 ) ;
if ( error )
return error ;
return F_76 ( V_6 , V_129 , 0 ) ;
}
STATIC int
F_106 (
struct V_5 * V_6 ,
struct V_129 * V_129 )
{
struct V_80 * V_81 = V_6 -> V_82 ;
struct V_1 * V_1 = F_21 ( V_6 ) ;
T_9 V_178 , V_179 ;
struct V_180 * V_143 ;
int error ;
T_8 V_181 = 0 ;
bool V_182 = false ;
ASSERT ( F_72 ( V_6 , V_183 ) ) ;
ASSERT ( F_72 ( V_6 , V_184 ) ) ;
ASSERT ( F_107 ( V_1 -> V_41 ) ) ;
ASSERT ( ( V_129 -> V_132 & ( V_154 | V_155 | V_133 | V_185 |
V_186 | V_187 | V_188 ) ) == 0 ) ;
V_178 = V_1 -> V_189 ;
V_179 = V_129 -> V_190 ;
if ( V_179 == 0 && V_178 == 0 && V_6 -> V_101 . V_191 == 0 ) {
if ( ! ( V_129 -> V_132 & ( V_135 | V_137 ) ) )
return 0 ;
V_129 -> V_132 &= ~ V_153 ;
return F_76 ( V_6 , V_129 , 0 ) ;
}
error = F_108 ( V_6 , 0 ) ;
if ( error )
return error ;
F_109 ( V_1 ) ;
if ( V_179 > V_178 ) {
error = F_110 ( V_6 , V_179 , V_178 , & V_182 ) ;
} else {
error = F_111 ( V_1 , V_179 , & V_182 ,
& V_192 ) ;
}
if ( error )
return error ;
if ( V_182 ||
( V_179 > V_6 -> V_101 . V_193 && V_178 != V_6 -> V_101 . V_193 ) ) {
error = F_112 ( F_21 ( V_6 ) -> V_194 ,
V_6 -> V_101 . V_193 , V_179 ) ;
if ( error )
return error ;
}
F_113 ( V_1 , V_179 ) ;
error = F_84 ( V_81 , & F_85 ( V_81 ) -> V_195 , 0 , 0 , 0 , & V_143 ) ;
if ( error )
return error ;
V_181 |= V_131 ;
F_86 ( V_6 , V_131 ) ;
F_87 ( V_143 , V_6 , 0 ) ;
if ( V_179 != V_178 &&
! ( V_129 -> V_132 & ( V_135 | V_137 ) ) ) {
V_129 -> V_136 = V_129 -> V_138 =
F_114 ( V_1 ) ;
V_129 -> V_132 |= V_135 | V_137 ;
}
V_6 -> V_101 . V_193 = V_179 ;
F_96 ( V_143 , V_6 , V_174 ) ;
if ( V_179 <= V_178 ) {
error = F_115 ( & V_143 , V_6 , V_196 , V_179 ) ;
if ( error )
goto V_197;
F_116 ( V_6 , V_198 ) ;
F_117 ( V_6 ) ;
}
if ( V_129 -> V_132 & V_173 )
F_71 ( V_6 , V_129 ) ;
if ( V_129 -> V_132 & ( V_133 | V_135 | V_137 ) )
F_73 ( V_6 , V_129 ) ;
F_96 ( V_143 , V_6 , V_174 ) ;
F_97 ( V_81 , V_175 ) ;
if ( V_81 -> V_139 & V_176 )
F_98 ( V_143 ) ;
error = F_99 ( V_143 ) ;
V_199:
if ( V_181 )
F_100 ( V_6 , V_181 ) ;
return error ;
V_197:
F_103 ( V_143 ) ;
goto V_199;
}
int
F_118 (
struct V_15 * V_15 ,
struct V_129 * V_129 )
{
struct V_5 * V_6 = F_2 ( F_42 ( V_15 ) ) ;
int error ;
F_105 ( V_6 ) ;
error = F_74 ( V_15 , V_129 ) ;
if ( error )
return error ;
return F_106 ( V_6 , V_129 ) ;
}
STATIC int
F_119 (
struct V_15 * V_15 ,
struct V_129 * V_129 )
{
int error ;
if ( V_129 -> V_132 & V_153 ) {
struct V_5 * V_6 = F_2 ( F_42 ( V_15 ) ) ;
T_8 V_200 = V_183 ;
error = F_120 ( F_42 ( V_15 ) , & V_200 ) ;
if ( error )
return error ;
F_86 ( V_6 , V_184 ) ;
error = F_118 ( V_15 , V_129 ) ;
F_100 ( V_6 , V_184 ) ;
} else {
error = F_104 ( V_15 , V_129 ) ;
}
return error ;
}
STATIC int
F_121 (
struct V_1 * V_1 ,
struct V_201 * V_202 ,
int V_31 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_80 * V_81 = V_6 -> V_82 ;
struct V_180 * V_143 ;
int error ;
F_122 ( V_6 ) ;
error = F_84 ( V_81 , & F_85 ( V_81 ) -> V_203 , 0 , 0 , 0 , & V_143 ) ;
if ( error )
return error ;
F_86 ( V_6 , V_131 ) ;
if ( V_31 & V_204 )
V_1 -> V_99 = * V_202 ;
if ( V_31 & V_205 )
V_1 -> V_98 = * V_202 ;
if ( V_31 & V_206 )
V_1 -> V_96 = * V_202 ;
F_87 ( V_143 , V_6 , V_131 ) ;
F_96 ( V_143 , V_6 , V_207 ) ;
return F_99 ( V_143 ) ;
}
STATIC int
F_123 (
struct V_1 * V_1 ,
struct V_208 * V_209 ,
T_10 V_210 ,
T_10 V_211 )
{
int error ;
F_86 ( F_2 ( V_1 ) , V_212 ) ;
if ( V_209 -> V_213 & V_214 ) {
V_209 -> V_213 &= ~ V_214 ;
error = F_124 ( V_1 , V_209 , V_210 , V_211 ,
& V_215 ) ;
} else {
error = F_124 ( V_1 , V_209 , V_210 , V_211 ,
& V_192 ) ;
}
F_100 ( F_2 ( V_1 ) , V_212 ) ;
return error ;
}
STATIC int
F_125 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_19 )
{
return F_12 ( V_11 , V_15 , V_19 , 0 , true ) ;
}
STATIC void
F_126 (
struct V_1 * V_1 ,
struct V_5 * V_6 )
{
T_11 V_31 = V_6 -> V_101 . V_113 ;
V_1 -> V_216 &= ~ ( V_217 | V_218 | V_219 |
V_220 | V_221 ) ;
if ( V_31 & V_114 )
V_1 -> V_216 |= V_217 ;
if ( V_31 & V_117 )
V_1 -> V_216 |= V_218 ;
if ( V_31 & V_222 )
V_1 -> V_216 |= V_219 ;
if ( V_31 & V_223 )
V_1 -> V_216 |= V_220 ;
if ( F_107 ( V_1 -> V_41 ) &&
V_6 -> V_82 -> V_43 . V_224 == V_225 &&
! F_127 ( V_6 ) &&
( V_6 -> V_82 -> V_139 & V_226 ||
V_6 -> V_101 . V_227 & V_228 ) )
V_1 -> V_216 |= V_221 ;
}
void
F_128 (
struct V_5 * V_6 )
{
struct V_1 * V_1 = & V_6 -> V_229 ;
T_12 V_230 ;
V_1 -> V_94 = V_6 -> V_94 ;
V_1 -> V_231 = V_232 ;
F_129 ( V_1 ) ;
F_130 ( & V_1 -> V_233 ) ;
V_1 -> V_90 = F_131 ( V_6 -> V_101 . V_170 ) ;
V_1 -> V_92 = F_132 ( V_6 -> V_101 . V_172 ) ;
switch ( V_1 -> V_41 & V_121 ) {
case V_122 :
case V_123 :
V_1 -> V_234 =
F_65 ( F_66 ( V_6 -> V_70 . V_126 . V_127 ) & 0x1ff ,
F_67 ( V_6 -> V_70 . V_126 . V_127 ) ) ;
break;
default:
V_1 -> V_234 = 0 ;
break;
}
F_133 ( V_1 , V_6 -> V_101 . V_193 ) ;
F_126 ( V_1 , V_6 ) ;
if ( F_134 ( V_1 -> V_41 ) ) {
F_135 ( & V_6 -> V_235 . V_236 , & V_237 ) ;
V_6 -> V_238 = V_6 -> V_82 -> V_239 ;
} else {
V_6 -> V_238 = V_6 -> V_82 -> V_240 ;
F_135 ( & V_6 -> V_235 . V_236 , & V_241 ) ;
}
V_230 = F_136 ( V_1 -> V_194 ) ;
F_137 ( V_1 -> V_194 , ( V_230 & ~ ( V_242 ) ) ) ;
if ( ! F_138 ( V_6 ) ) {
F_139 ( V_1 ) ;
F_140 ( V_1 ) ;
}
}
void
F_24 (
struct V_5 * V_6 )
{
struct V_1 * V_1 = & V_6 -> V_229 ;
switch ( V_1 -> V_41 & V_121 ) {
case V_243 :
V_1 -> V_244 = & V_245 ;
V_1 -> V_246 = & V_247 ;
V_1 -> V_194 -> V_248 = & V_249 ;
break;
case V_32 :
if ( F_46 ( & F_47 ( V_1 -> V_42 ) -> V_43 ) )
V_1 -> V_244 = & V_250 ;
else
V_1 -> V_244 = & V_251 ;
V_1 -> V_246 = & V_252 ;
break;
case V_45 :
if ( V_6 -> V_70 . V_71 & V_72 )
V_1 -> V_244 = & V_253 ;
else
V_1 -> V_244 = & V_254 ;
break;
default:
V_1 -> V_244 = & V_245 ;
F_141 ( V_1 , V_1 -> V_41 , V_1 -> V_234 ) ;
break;
}
}
