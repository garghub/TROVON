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
}
STATIC int
F_9 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_16 ,
T_2 V_23 ,
bool tmpfile )
{
struct V_1 * V_1 ;
struct V_5 * V_6 = NULL ;
struct V_24 * V_25 , * V_26 ;
struct V_13 V_7 ;
int error ;
if ( F_10 ( V_16 ) || F_11 ( V_16 ) ) {
if ( F_12 ( ! F_13 ( V_23 ) || F_14 ( V_23 ) & ~ 0x1ff ) )
return - V_27 ;
V_23 = F_15 ( V_23 ) ;
} else {
V_23 = 0 ;
}
error = F_16 ( V_11 , & V_16 , & V_25 , & V_26 ) ;
if ( error )
return error ;
if ( ! tmpfile ) {
F_6 ( & V_7 , V_15 , V_16 ) ;
error = F_17 ( F_2 ( V_11 ) , & V_7 , V_16 , V_23 , & V_6 ) ;
} else {
error = F_18 ( F_2 ( V_11 ) , V_15 , V_16 , & V_6 ) ;
}
if ( F_12 ( error ) )
goto V_28;
V_1 = F_19 ( V_6 ) ;
error = F_4 ( V_1 , V_11 , & V_15 -> V_17 ) ;
if ( F_12 ( error ) )
goto V_29;
#ifdef F_20
if ( V_25 ) {
error = F_21 ( V_1 , V_25 , V_30 ) ;
if ( error )
goto V_29;
}
if ( V_26 ) {
error = F_21 ( V_1 , V_26 , V_31 ) ;
if ( error )
goto V_29;
}
#endif
if ( tmpfile )
F_22 ( V_15 , V_1 ) ;
else
F_23 ( V_15 , V_1 ) ;
F_24 ( V_6 ) ;
V_28:
if ( V_25 )
F_25 ( V_25 ) ;
if ( V_26 )
F_25 ( V_26 ) ;
return error ;
V_29:
F_24 ( V_6 ) ;
if ( ! tmpfile )
F_7 ( V_11 , V_1 , V_15 ) ;
F_26 ( V_1 ) ;
goto V_28;
}
STATIC int
F_27 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_16 ,
T_2 V_23 )
{
return F_9 ( V_11 , V_15 , V_16 , V_23 , false ) ;
}
STATIC int
F_28 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_16 ,
bool V_32 )
{
return F_27 ( V_11 , V_15 , V_16 , 0 ) ;
}
STATIC int
F_29 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_16 )
{
return F_27 ( V_11 , V_15 , V_16 | V_33 , 0 ) ;
}
STATIC struct V_15 *
F_30 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
unsigned int V_32 )
{
struct V_5 * V_34 ;
struct V_13 V_7 ;
int error ;
if ( V_15 -> V_17 . V_18 >= V_35 )
return F_31 ( - V_36 ) ;
F_6 ( & V_7 , V_15 , 0 ) ;
error = F_32 ( F_2 ( V_11 ) , & V_7 , & V_34 , NULL ) ;
if ( F_12 ( error ) ) {
if ( F_12 ( error != - V_37 ) )
return F_31 ( error ) ;
F_33 ( V_15 , NULL ) ;
return NULL ;
}
return F_34 ( F_19 ( V_34 ) , V_15 ) ;
}
STATIC struct V_15 *
F_35 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
unsigned int V_32 )
{
struct V_5 * V_6 ;
struct V_13 V_38 ;
struct V_13 V_39 ;
struct V_12 V_40 ;
int error ;
if ( V_15 -> V_17 . V_18 >= V_35 )
return F_31 ( - V_36 ) ;
F_6 ( & V_38 , V_15 , 0 ) ;
error = F_32 ( F_2 ( V_11 ) , & V_38 , & V_6 , & V_39 ) ;
if ( F_12 ( error ) ) {
if ( F_12 ( error != - V_37 ) )
return F_31 ( error ) ;
return NULL ;
}
if ( ! V_39 . V_7 )
return F_34 ( F_19 ( V_6 ) , V_15 ) ;
V_40 . V_7 = V_39 . V_7 ;
V_40 . V_18 = V_39 . V_18 ;
V_15 = F_36 ( V_15 , F_19 ( V_6 ) , & V_40 ) ;
F_37 ( V_39 . V_7 ) ;
return V_15 ;
}
STATIC int
F_38 (
struct V_15 * V_41 ,
struct V_1 * V_11 ,
struct V_15 * V_15 )
{
struct V_1 * V_1 = F_39 ( V_41 ) ;
struct V_13 V_7 ;
int error ;
F_6 ( & V_7 , V_15 , V_1 -> V_42 ) ;
error = F_40 ( F_2 ( V_11 ) , F_2 ( V_1 ) , & V_7 ) ;
if ( F_12 ( error ) )
return error ;
F_41 ( V_1 ) ;
F_23 ( V_15 , V_1 ) ;
return 0 ;
}
STATIC int
F_42 (
struct V_1 * V_11 ,
struct V_15 * V_15 )
{
struct V_13 V_7 ;
int error ;
F_6 ( & V_7 , V_15 , 0 ) ;
error = F_8 ( F_2 ( V_11 ) , & V_7 , F_2 ( F_39 ( V_15 ) ) ) ;
if ( error )
return error ;
if ( F_43 ( & F_44 ( V_11 -> V_43 ) -> V_44 ) )
F_45 ( V_15 ) ;
return 0 ;
}
STATIC int
F_46 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
const char * V_45 )
{
struct V_1 * V_1 ;
struct V_5 * V_34 = NULL ;
struct V_13 V_7 ;
int error ;
T_1 V_16 ;
V_16 = V_46 |
( V_47 ? 0777 & ~ F_47 () : V_48 ) ;
F_6 ( & V_7 , V_15 , V_16 ) ;
error = F_48 ( F_2 ( V_11 ) , & V_7 , V_45 , V_16 , & V_34 ) ;
if ( F_12 ( error ) )
goto V_49;
V_1 = F_19 ( V_34 ) ;
error = F_4 ( V_1 , V_11 , & V_15 -> V_17 ) ;
if ( F_12 ( error ) )
goto V_29;
F_23 ( V_15 , V_1 ) ;
F_24 ( V_34 ) ;
return 0 ;
V_29:
F_24 ( V_34 ) ;
F_7 ( V_11 , V_1 , V_15 ) ;
F_26 ( V_1 ) ;
V_49:
return error ;
}
STATIC int
F_49 (
struct V_1 * V_50 ,
struct V_15 * V_51 ,
struct V_1 * V_52 ,
struct V_15 * V_53 ,
unsigned int V_32 )
{
struct V_1 * V_54 = F_39 ( V_53 ) ;
int V_55 = 0 ;
struct V_13 V_56 ;
struct V_13 V_57 ;
if ( V_32 & ~ ( V_58 | V_59 | V_60 ) )
return - V_27 ;
if ( V_32 & V_59 )
V_55 = F_39 ( V_53 ) -> V_42 ;
F_6 ( & V_56 , V_51 , V_55 ) ;
F_6 ( & V_57 , V_53 , F_39 ( V_51 ) -> V_42 ) ;
return F_50 ( F_2 ( V_50 ) , & V_56 , F_2 ( F_39 ( V_51 ) ) ,
F_2 ( V_52 ) , & V_57 ,
V_54 ? F_2 ( V_54 ) : NULL , V_32 ) ;
}
STATIC const char *
F_51 (
struct V_15 * V_15 ,
struct V_1 * V_1 ,
struct V_61 * V_62 )
{
char * V_63 ;
int error = - V_64 ;
if ( ! V_15 )
return F_31 ( - V_65 ) ;
V_63 = F_52 ( V_66 + 1 , V_67 ) ;
if ( ! V_63 )
goto V_68;
error = F_53 ( F_2 ( F_39 ( V_15 ) ) , V_63 ) ;
if ( F_12 ( error ) )
goto V_69;
F_54 ( V_62 , V_70 , V_63 ) ;
return V_63 ;
V_69:
F_55 ( V_63 ) ;
V_68:
return F_31 ( error ) ;
}
STATIC int
F_56 (
struct V_71 * V_72 ,
struct V_15 * V_15 ,
struct V_73 * V_74 )
{
struct V_1 * V_1 = F_39 ( V_15 ) ;
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_75 * V_76 = V_6 -> V_77 ;
F_57 ( V_6 ) ;
if ( F_58 ( V_76 ) )
return - V_78 ;
V_74 -> V_79 = F_59 ( V_6 ) ;
V_74 -> V_80 = V_1 -> V_43 -> V_81 ;
V_74 -> V_16 = V_6 -> V_82 . V_83 ;
V_74 -> V_84 = V_6 -> V_82 . V_85 ;
V_74 -> V_86 = V_1 -> V_87 ;
V_74 -> V_88 = V_1 -> V_89 ;
V_74 -> V_90 = V_6 -> V_91 ;
V_74 -> V_92 = V_1 -> V_93 ;
V_74 -> V_94 = V_1 -> V_95 ;
V_74 -> ctime = V_1 -> V_96 ;
V_74 -> V_97 =
F_60 ( V_76 , V_6 -> V_82 . V_98 + V_6 -> V_99 ) ;
switch ( V_1 -> V_42 & V_20 ) {
case V_100 :
case V_101 :
V_74 -> V_102 = V_103 ;
V_74 -> V_23 = F_61 ( F_62 ( V_6 -> V_104 . V_105 . V_106 ) & 0x1ff ,
F_63 ( V_6 -> V_104 . V_105 . V_106 ) ) ;
break;
default:
if ( F_64 ( V_6 ) ) {
V_74 -> V_102 =
F_65 ( V_6 ) << V_76 -> V_44 . V_107 ;
} else
V_74 -> V_102 = F_66 ( V_76 ) ;
V_74 -> V_23 = 0 ;
break;
}
return 0 ;
}
static void
F_67 (
struct V_5 * V_6 ,
struct V_108 * V_108 )
{
struct V_1 * V_1 = F_19 ( V_6 ) ;
T_1 V_16 = V_108 -> V_109 ;
ASSERT ( F_68 ( V_6 , V_110 ) ) ;
V_6 -> V_82 . V_83 &= V_20 ;
V_6 -> V_82 . V_83 |= V_16 & ~ V_20 ;
V_1 -> V_42 &= V_20 ;
V_1 -> V_42 |= V_16 & ~ V_20 ;
}
void
F_69 (
struct V_5 * V_6 ,
struct V_108 * V_108 )
{
struct V_1 * V_1 = F_19 ( V_6 ) ;
ASSERT ( F_68 ( V_6 , V_110 ) ) ;
if ( V_108 -> V_111 & V_112 ) {
V_1 -> V_93 = V_108 -> V_113 ;
V_6 -> V_82 . V_114 . V_115 = V_108 -> V_113 . V_116 ;
V_6 -> V_82 . V_114 . V_117 = V_108 -> V_113 . V_118 ;
}
if ( V_108 -> V_111 & V_119 ) {
V_1 -> V_96 = V_108 -> V_120 ;
V_6 -> V_82 . V_121 . V_115 = V_108 -> V_120 . V_116 ;
V_6 -> V_82 . V_121 . V_117 = V_108 -> V_120 . V_118 ;
}
if ( V_108 -> V_111 & V_122 ) {
V_1 -> V_95 = V_108 -> V_123 ;
V_6 -> V_82 . V_124 . V_115 = V_108 -> V_123 . V_116 ;
V_6 -> V_82 . V_124 . V_117 = V_108 -> V_123 . V_118 ;
}
}
int
F_70 (
struct V_5 * V_6 ,
struct V_108 * V_108 ,
int V_32 )
{
T_3 * V_76 = V_6 -> V_77 ;
struct V_1 * V_1 = F_19 ( V_6 ) ;
int V_125 = V_108 -> V_111 ;
T_4 * V_126 ;
int error ;
T_5 V_86 = V_127 , V_128 = V_127 ;
T_6 V_88 = V_129 , V_130 = V_129 ;
struct V_131 * V_132 = NULL , * V_133 = NULL ;
struct V_131 * V_134 = NULL , * V_135 = NULL ;
F_71 ( V_6 ) ;
if ( ! ( V_32 & V_136 ) ) {
if ( V_76 -> V_137 & V_138 )
return - V_139 ;
if ( F_58 ( V_76 ) )
return - V_78 ;
error = F_72 ( V_1 , V_108 ) ;
if ( error )
return error ;
}
ASSERT ( ( V_125 & V_140 ) == 0 ) ;
if ( F_73 ( V_76 ) && ( V_125 & ( V_141 | V_142 ) ) ) {
T_7 V_143 = 0 ;
if ( ( V_125 & V_141 ) && F_74 ( V_76 ) ) {
V_86 = V_108 -> V_144 ;
V_143 |= V_145 ;
} else {
V_86 = V_1 -> V_87 ;
}
if ( ( V_125 & V_142 ) && F_75 ( V_76 ) ) {
V_88 = V_108 -> V_146 ;
V_143 |= V_147 ;
} else {
V_88 = V_1 -> V_89 ;
}
ASSERT ( V_132 == NULL ) ;
ASSERT ( V_133 == NULL ) ;
error = F_76 ( V_6 , F_77 ( V_86 ) ,
F_78 ( V_88 ) ,
F_79 ( V_6 ) ,
V_143 , & V_132 , & V_133 , NULL ) ;
if ( error )
return error ;
}
V_126 = F_80 ( V_76 , V_148 ) ;
error = F_81 ( V_126 , & F_82 ( V_76 ) -> V_149 , 0 , 0 ) ;
if ( error )
goto V_150;
F_83 ( V_6 , V_110 ) ;
if ( V_125 & ( V_141 | V_142 ) ) {
V_128 = V_1 -> V_87 ;
V_130 = V_1 -> V_89 ;
V_88 = ( V_125 & V_142 ) ? V_108 -> V_146 : V_130 ;
V_86 = ( V_125 & V_141 ) ? V_108 -> V_144 : V_128 ;
if ( F_84 ( V_76 ) &&
( ( F_74 ( V_76 ) && ! F_85 ( V_128 , V_86 ) ) ||
( F_75 ( V_76 ) && ! F_86 ( V_130 , V_88 ) ) ) ) {
ASSERT ( V_126 ) ;
error = F_87 ( V_126 , V_6 , V_132 , V_133 ,
NULL , F_88 ( V_151 ) ?
V_152 : 0 ) ;
if ( error )
goto V_153;
}
}
F_89 ( V_126 , V_6 , 0 ) ;
if ( V_125 & ( V_141 | V_142 ) ) {
if ( ( V_6 -> V_82 . V_83 & ( V_154 | V_155 ) ) &&
! F_88 ( V_156 ) )
V_6 -> V_82 . V_83 &= ~ ( V_154 | V_155 ) ;
if ( ! F_85 ( V_128 , V_86 ) ) {
if ( F_84 ( V_76 ) && F_74 ( V_76 ) ) {
ASSERT ( V_125 & V_141 ) ;
ASSERT ( V_132 ) ;
V_134 = F_90 ( V_126 , V_6 ,
& V_6 -> V_157 , V_132 ) ;
}
V_6 -> V_82 . V_158 = F_77 ( V_86 ) ;
V_1 -> V_87 = V_86 ;
}
if ( ! F_86 ( V_130 , V_88 ) ) {
if ( F_84 ( V_76 ) && F_75 ( V_76 ) ) {
ASSERT ( F_91 ( & V_76 -> V_44 ) ||
! F_92 ( V_76 ) ) ;
ASSERT ( V_125 & V_142 ) ;
ASSERT ( V_133 ) ;
V_135 = F_90 ( V_126 , V_6 ,
& V_6 -> V_159 , V_133 ) ;
}
V_6 -> V_82 . V_160 = F_78 ( V_88 ) ;
V_1 -> V_89 = V_88 ;
}
}
if ( V_125 & V_161 )
F_67 ( V_6 , V_108 ) ;
if ( V_125 & ( V_112 | V_119 | V_122 ) )
F_69 ( V_6 , V_108 ) ;
F_93 ( V_126 , V_6 , V_162 ) ;
F_94 ( V_76 , V_163 ) ;
if ( V_76 -> V_137 & V_164 )
F_95 ( V_126 ) ;
error = F_96 ( V_126 ) ;
F_97 ( V_6 , V_110 ) ;
F_98 ( V_134 ) ;
F_98 ( V_135 ) ;
F_98 ( V_132 ) ;
F_98 ( V_133 ) ;
if ( error )
return error ;
if ( ( V_125 & V_161 ) && ! ( V_32 & V_136 ) ) {
error = F_99 ( V_1 , V_1 -> V_42 ) ;
if ( error )
return error ;
}
return 0 ;
V_153:
F_97 ( V_6 , V_110 ) ;
V_150:
F_100 ( V_126 ) ;
F_98 ( V_132 ) ;
F_98 ( V_133 ) ;
return error ;
}
int
F_101 (
struct V_5 * V_6 ,
struct V_108 * V_108 )
{
struct V_75 * V_76 = V_6 -> V_77 ;
struct V_1 * V_1 = F_19 ( V_6 ) ;
T_8 V_165 , V_166 ;
struct V_167 * V_126 ;
int error ;
T_7 V_168 = 0 ;
bool V_169 = false ;
F_71 ( V_6 ) ;
if ( V_76 -> V_137 & V_138 )
return - V_139 ;
if ( F_58 ( V_76 ) )
return - V_78 ;
error = F_72 ( V_1 , V_108 ) ;
if ( error )
return error ;
ASSERT ( F_68 ( V_6 , V_170 ) ) ;
ASSERT ( F_68 ( V_6 , V_171 ) ) ;
ASSERT ( F_102 ( V_6 -> V_82 . V_83 ) ) ;
ASSERT ( ( V_108 -> V_111 & ( V_141 | V_142 | V_112 | V_172 |
V_173 | V_174 | V_175 ) ) == 0 ) ;
V_165 = V_1 -> V_176 ;
V_166 = V_108 -> V_177 ;
if ( V_166 == 0 && V_165 == 0 && V_6 -> V_82 . V_178 == 0 ) {
if ( ! ( V_108 -> V_111 & ( V_119 | V_122 ) ) )
return 0 ;
V_108 -> V_111 &= ~ V_140 ;
return F_70 ( V_6 , V_108 , 0 ) ;
}
error = F_103 ( V_6 , 0 ) ;
if ( error )
return error ;
if ( V_166 > V_165 ) {
error = F_104 ( V_6 , V_166 , V_165 , & V_169 ) ;
if ( error )
return error ;
}
if ( V_166 > V_6 -> V_82 . V_179 &&
( V_165 != V_6 -> V_82 . V_179 || V_169 ) ) {
error = F_105 ( F_19 ( V_6 ) -> V_180 ,
V_6 -> V_82 . V_179 , V_166 ) ;
if ( error )
return error ;
}
F_106 ( V_1 ) ;
if ( F_107 ( V_1 ) )
error = F_108 ( V_1 , V_166 , V_181 ) ;
else
error = F_109 ( V_1 -> V_180 , V_166 ,
V_182 ) ;
if ( error )
return error ;
F_110 ( V_1 , V_166 ) ;
V_126 = F_80 ( V_76 , V_183 ) ;
error = F_81 ( V_126 , & F_82 ( V_76 ) -> V_184 , 0 , 0 ) ;
if ( error )
goto V_150;
V_168 |= V_110 ;
F_83 ( V_6 , V_110 ) ;
F_89 ( V_126 , V_6 , 0 ) ;
if ( V_166 != V_165 &&
! ( V_108 -> V_111 & ( V_119 | V_122 ) ) ) {
V_108 -> V_120 = V_108 -> V_123 =
F_111 ( V_1 -> V_43 ) ;
V_108 -> V_111 |= V_119 | V_122 ;
}
V_6 -> V_82 . V_179 = V_166 ;
F_93 ( V_126 , V_6 , V_162 ) ;
if ( V_166 <= V_165 ) {
error = F_112 ( & V_126 , V_6 , V_185 , V_166 ) ;
if ( error )
goto V_150;
F_113 ( V_6 , V_186 ) ;
F_114 ( V_6 ) ;
}
if ( V_108 -> V_111 & V_161 )
F_67 ( V_6 , V_108 ) ;
if ( V_108 -> V_111 & ( V_112 | V_119 | V_122 ) )
F_69 ( V_6 , V_108 ) ;
F_93 ( V_126 , V_6 , V_162 ) ;
F_94 ( V_76 , V_163 ) ;
if ( V_76 -> V_137 & V_164 )
F_95 ( V_126 ) ;
error = F_96 ( V_126 ) ;
V_153:
if ( V_168 )
F_97 ( V_6 , V_168 ) ;
return error ;
V_150:
F_100 ( V_126 ) ;
goto V_153;
}
STATIC int
F_115 (
struct V_15 * V_15 ,
struct V_108 * V_108 )
{
struct V_5 * V_6 = F_2 ( F_39 ( V_15 ) ) ;
int error ;
if ( V_108 -> V_111 & V_140 ) {
T_7 V_187 = V_170 ;
F_83 ( V_6 , V_187 ) ;
error = F_116 ( F_39 ( V_15 ) , & V_187 , true ) ;
if ( ! error ) {
F_83 ( V_6 , V_171 ) ;
V_187 |= V_171 ;
error = F_101 ( V_6 , V_108 ) ;
}
F_97 ( V_6 , V_187 ) ;
} else {
error = F_70 ( V_6 , V_108 , 0 ) ;
}
return error ;
}
STATIC int
F_117 (
struct V_1 * V_1 ,
struct V_188 * V_189 ,
int V_32 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_75 * V_76 = V_6 -> V_77 ;
struct V_167 * V_126 ;
int error ;
F_118 ( V_6 ) ;
V_126 = F_80 ( V_76 , V_190 ) ;
error = F_81 ( V_126 , & F_82 ( V_76 ) -> V_191 , 0 , 0 ) ;
if ( error ) {
F_100 ( V_126 ) ;
return error ;
}
F_83 ( V_6 , V_110 ) ;
if ( V_32 & V_192 ) {
V_1 -> V_96 = * V_189 ;
V_6 -> V_82 . V_121 . V_115 = ( V_193 ) V_189 -> V_116 ;
V_6 -> V_82 . V_121 . V_117 = ( V_193 ) V_189 -> V_118 ;
}
if ( V_32 & V_194 ) {
V_1 -> V_95 = * V_189 ;
V_6 -> V_82 . V_124 . V_115 = ( V_193 ) V_189 -> V_116 ;
V_6 -> V_82 . V_124 . V_117 = ( V_193 ) V_189 -> V_118 ;
}
if ( V_32 & V_195 ) {
V_1 -> V_93 = * V_189 ;
V_6 -> V_82 . V_114 . V_115 = ( V_193 ) V_189 -> V_116 ;
V_6 -> V_82 . V_114 . V_117 = ( V_193 ) V_189 -> V_118 ;
}
F_89 ( V_126 , V_6 , V_110 ) ;
F_93 ( V_126 , V_6 , V_196 ) ;
return F_96 ( V_126 ) ;
}
STATIC int
F_119 (
void * * V_197 ,
struct V_198 * V_199 ,
int * V_200 )
{
int error ;
struct V_201 * V_202 = * V_197 ;
T_9 V_203 = 0 ;
T_10 V_204 , V_205 , V_206 ;
if ( V_199 -> V_207 == - 1LL )
return 0 ;
V_204 = F_120 ( V_199 -> V_208 ) ;
V_205 = F_120 ( V_199 -> V_207 ) ;
V_206 = F_120 ( V_199 -> V_209 ) ;
if ( V_199 -> V_210 & V_211 )
V_203 |= V_212 ;
else if ( V_199 -> V_210 & V_213 ) {
V_203 |= ( V_214 |
V_215 ) ;
V_205 = 0 ;
}
if ( V_199 -> V_210 & V_216 )
V_203 |= V_217 ;
error = F_121 ( V_202 , V_204 , V_205 ,
V_206 , V_203 ) ;
if ( error > 0 ) {
error = 0 ;
* V_200 = 1 ;
}
return error ;
}
STATIC int
F_122 (
struct V_1 * V_1 ,
struct V_201 * V_202 ,
T_10 V_218 ,
T_10 V_206 )
{
T_11 * V_6 = F_2 ( V_1 ) ;
struct V_198 V_219 ;
int error ;
error = F_123 ( V_202 , V_220 ) ;
if ( error )
return error ;
V_219 . V_208 = F_124 ( V_218 ) ;
if ( V_206 == V_221 )
V_219 . V_209 = - 1LL ;
else
V_219 . V_209 = F_125 ( V_218 + V_206 ) - V_219 . V_208 ;
V_219 . V_222 = ! V_202 -> V_223 ? V_224 :
V_202 -> V_223 + 1 ;
V_219 . V_222 = F_126 ( V_225 , V_219 . V_222 ,
( V_226 * 16 / sizeof( struct V_198 ) ) ) ;
V_219 . V_227 = V_228 | V_229 ;
if ( V_202 -> V_230 & V_231 )
V_219 . V_227 |= V_232 ;
if ( ! ( V_202 -> V_230 & V_233 ) )
V_219 . V_227 |= V_234 ;
error = F_127 ( V_6 , & V_219 , F_119 , V_202 ) ;
if ( error )
return error ;
return 0 ;
}
STATIC int
F_128 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_16 )
{
return F_9 ( V_11 , V_15 , V_16 , 0 , true ) ;
}
STATIC void
F_129 (
struct V_1 * V_1 ,
struct V_5 * V_6 )
{
T_12 V_32 = V_6 -> V_82 . V_235 ;
V_1 -> V_236 &= ~ ( V_237 | V_238 | V_239 |
V_240 | V_241 ) ;
if ( V_32 & V_242 )
V_1 -> V_236 |= V_237 ;
if ( V_32 & V_243 )
V_1 -> V_236 |= V_238 ;
if ( V_32 & V_244 )
V_1 -> V_236 |= V_239 ;
if ( V_32 & V_245 )
V_1 -> V_236 |= V_240 ;
if ( V_6 -> V_77 -> V_137 & V_246 ||
V_6 -> V_82 . V_247 & V_248 )
V_1 -> V_236 |= V_241 ;
}
void
F_130 (
struct V_5 * V_6 )
{
struct V_1 * V_1 = & V_6 -> V_249 ;
T_13 V_250 ;
V_1 -> V_91 = V_6 -> V_91 ;
V_1 -> V_251 = V_252 ;
F_131 ( V_1 ) ;
F_132 ( & V_1 -> V_253 ) ;
V_1 -> V_42 = V_6 -> V_82 . V_83 ;
F_133 ( V_1 , V_6 -> V_82 . V_85 ) ;
V_1 -> V_87 = F_134 ( V_6 -> V_82 . V_158 ) ;
V_1 -> V_89 = F_135 ( V_6 -> V_82 . V_160 ) ;
switch ( V_1 -> V_42 & V_20 ) {
case V_100 :
case V_101 :
V_1 -> V_254 =
F_61 ( F_62 ( V_6 -> V_104 . V_105 . V_106 ) & 0x1ff ,
F_63 ( V_6 -> V_104 . V_105 . V_106 ) ) ;
break;
default:
V_1 -> V_254 = 0 ;
break;
}
V_1 -> V_255 = V_6 -> V_82 . V_256 ;
F_136 ( V_1 , V_6 -> V_82 . V_179 ) ;
V_1 -> V_93 . V_116 = V_6 -> V_82 . V_114 . V_115 ;
V_1 -> V_93 . V_118 = V_6 -> V_82 . V_114 . V_117 ;
V_1 -> V_95 . V_116 = V_6 -> V_82 . V_124 . V_115 ;
V_1 -> V_95 . V_118 = V_6 -> V_82 . V_124 . V_117 ;
V_1 -> V_96 . V_116 = V_6 -> V_82 . V_121 . V_115 ;
V_1 -> V_96 . V_118 = V_6 -> V_82 . V_121 . V_117 ;
F_129 ( V_1 , V_6 ) ;
V_6 -> V_257 = V_6 -> V_77 -> V_258 ;
F_137 ( & V_6 -> V_259 . V_260 , & V_261 ) ;
switch ( V_1 -> V_42 & V_20 ) {
case V_262 :
V_1 -> V_263 = & V_264 ;
V_1 -> V_265 = & V_266 ;
V_1 -> V_180 -> V_267 = & V_268 ;
break;
case V_33 :
F_137 ( & V_6 -> V_259 . V_260 , & V_269 ) ;
if ( F_43 ( & F_44 ( V_1 -> V_43 ) -> V_44 ) )
V_1 -> V_263 = & V_270 ;
else
V_1 -> V_263 = & V_271 ;
V_1 -> V_265 = & V_272 ;
V_6 -> V_257 = V_6 -> V_77 -> V_273 ;
break;
case V_46 :
V_1 -> V_263 = & V_274 ;
if ( ! ( V_6 -> V_104 . V_275 & V_276 ) )
V_1 -> V_180 -> V_267 = & V_268 ;
break;
default:
V_1 -> V_263 = & V_264 ;
F_138 ( V_1 , V_1 -> V_42 , V_1 -> V_254 ) ;
break;
}
V_250 = F_139 ( V_1 -> V_180 ) ;
F_140 ( V_1 -> V_180 , ( V_250 & ~ ( V_277 ) ) ) ;
if ( ! F_141 ( V_6 ) ) {
F_142 ( V_1 ) ;
F_143 ( V_1 ) ;
}
}
