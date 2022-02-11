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
STATIC void *
F_51 (
struct V_15 * V_15 ,
struct V_61 * V_62 )
{
char * V_63 ;
int error = - V_64 ;
V_63 = F_52 ( V_65 + 1 , V_66 ) ;
if ( ! V_63 )
goto V_67;
error = F_53 ( F_2 ( F_39 ( V_15 ) ) , V_63 ) ;
if ( F_12 ( error ) )
goto V_68;
F_54 ( V_62 , V_63 ) ;
return NULL ;
V_68:
F_55 ( V_63 ) ;
V_67:
F_54 ( V_62 , F_31 ( error ) ) ;
return NULL ;
}
STATIC int
F_56 (
struct V_69 * V_70 ,
struct V_15 * V_15 ,
struct V_71 * V_72 )
{
struct V_1 * V_1 = F_39 ( V_15 ) ;
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_73 * V_74 = V_6 -> V_75 ;
F_57 ( V_6 ) ;
if ( F_58 ( V_74 ) )
return - V_76 ;
V_72 -> V_77 = F_59 ( V_6 ) ;
V_72 -> V_78 = V_1 -> V_43 -> V_79 ;
V_72 -> V_16 = V_6 -> V_80 . V_81 ;
V_72 -> V_82 = V_6 -> V_80 . V_83 ;
V_72 -> V_84 = V_1 -> V_85 ;
V_72 -> V_86 = V_1 -> V_87 ;
V_72 -> V_88 = V_6 -> V_89 ;
V_72 -> V_90 = V_1 -> V_91 ;
V_72 -> V_92 = V_1 -> V_93 ;
V_72 -> ctime = V_1 -> V_94 ;
V_72 -> V_95 =
F_60 ( V_74 , V_6 -> V_80 . V_96 + V_6 -> V_97 ) ;
switch ( V_1 -> V_42 & V_20 ) {
case V_98 :
case V_99 :
V_72 -> V_100 = V_101 ;
V_72 -> V_23 = F_61 ( F_62 ( V_6 -> V_102 . V_103 . V_104 ) & 0x1ff ,
F_63 ( V_6 -> V_102 . V_103 . V_104 ) ) ;
break;
default:
if ( F_64 ( V_6 ) ) {
V_72 -> V_100 =
F_65 ( V_6 ) << V_74 -> V_44 . V_105 ;
} else
V_72 -> V_100 = F_66 ( V_74 ) ;
V_72 -> V_23 = 0 ;
break;
}
return 0 ;
}
static void
F_67 (
struct V_5 * V_6 ,
struct V_106 * V_106 )
{
struct V_1 * V_1 = F_19 ( V_6 ) ;
T_1 V_16 = V_106 -> V_107 ;
ASSERT ( F_68 ( V_6 , V_108 ) ) ;
V_6 -> V_80 . V_81 &= V_20 ;
V_6 -> V_80 . V_81 |= V_16 & ~ V_20 ;
V_1 -> V_42 &= V_20 ;
V_1 -> V_42 |= V_16 & ~ V_20 ;
}
void
F_69 (
struct V_5 * V_6 ,
struct V_106 * V_106 )
{
struct V_1 * V_1 = F_19 ( V_6 ) ;
ASSERT ( F_68 ( V_6 , V_108 ) ) ;
if ( V_106 -> V_109 & V_110 ) {
V_1 -> V_91 = V_106 -> V_111 ;
V_6 -> V_80 . V_112 . V_113 = V_106 -> V_111 . V_114 ;
V_6 -> V_80 . V_112 . V_115 = V_106 -> V_111 . V_116 ;
}
if ( V_106 -> V_109 & V_117 ) {
V_1 -> V_94 = V_106 -> V_118 ;
V_6 -> V_80 . V_119 . V_113 = V_106 -> V_118 . V_114 ;
V_6 -> V_80 . V_119 . V_115 = V_106 -> V_118 . V_116 ;
}
if ( V_106 -> V_109 & V_120 ) {
V_1 -> V_93 = V_106 -> V_121 ;
V_6 -> V_80 . V_122 . V_113 = V_106 -> V_121 . V_114 ;
V_6 -> V_80 . V_122 . V_115 = V_106 -> V_121 . V_116 ;
}
}
int
F_70 (
struct V_5 * V_6 ,
struct V_106 * V_106 ,
int V_32 )
{
T_3 * V_74 = V_6 -> V_75 ;
struct V_1 * V_1 = F_19 ( V_6 ) ;
int V_123 = V_106 -> V_109 ;
T_4 * V_124 ;
int error ;
T_5 V_84 = V_125 , V_126 = V_125 ;
T_6 V_86 = V_127 , V_128 = V_127 ;
struct V_129 * V_130 = NULL , * V_131 = NULL ;
struct V_129 * V_132 = NULL , * V_133 = NULL ;
F_71 ( V_6 ) ;
if ( ! ( V_32 & V_134 ) ) {
if ( V_74 -> V_135 & V_136 )
return - V_137 ;
if ( F_58 ( V_74 ) )
return - V_76 ;
error = F_72 ( V_1 , V_106 ) ;
if ( error )
return error ;
}
ASSERT ( ( V_123 & V_138 ) == 0 ) ;
if ( F_73 ( V_74 ) && ( V_123 & ( V_139 | V_140 ) ) ) {
T_7 V_141 = 0 ;
if ( ( V_123 & V_139 ) && F_74 ( V_74 ) ) {
V_84 = V_106 -> V_142 ;
V_141 |= V_143 ;
} else {
V_84 = V_1 -> V_85 ;
}
if ( ( V_123 & V_140 ) && F_75 ( V_74 ) ) {
V_86 = V_106 -> V_144 ;
V_141 |= V_145 ;
} else {
V_86 = V_1 -> V_87 ;
}
ASSERT ( V_130 == NULL ) ;
ASSERT ( V_131 == NULL ) ;
error = F_76 ( V_6 , F_77 ( V_84 ) ,
F_78 ( V_86 ) ,
F_79 ( V_6 ) ,
V_141 , & V_130 , & V_131 , NULL ) ;
if ( error )
return error ;
}
V_124 = F_80 ( V_74 , V_146 ) ;
error = F_81 ( V_124 , & F_82 ( V_74 ) -> V_147 , 0 , 0 ) ;
if ( error )
goto V_148;
F_83 ( V_6 , V_108 ) ;
if ( V_123 & ( V_139 | V_140 ) ) {
V_126 = V_1 -> V_85 ;
V_128 = V_1 -> V_87 ;
V_86 = ( V_123 & V_140 ) ? V_106 -> V_144 : V_128 ;
V_84 = ( V_123 & V_139 ) ? V_106 -> V_142 : V_126 ;
if ( F_84 ( V_74 ) &&
( ( F_74 ( V_74 ) && ! F_85 ( V_126 , V_84 ) ) ||
( F_75 ( V_74 ) && ! F_86 ( V_128 , V_86 ) ) ) ) {
ASSERT ( V_124 ) ;
error = F_87 ( V_124 , V_6 , V_130 , V_131 ,
NULL , F_88 ( V_149 ) ?
V_150 : 0 ) ;
if ( error )
goto V_151;
}
}
F_89 ( V_124 , V_6 , 0 ) ;
if ( V_123 & ( V_139 | V_140 ) ) {
if ( ( V_6 -> V_80 . V_81 & ( V_152 | V_153 ) ) &&
! F_88 ( V_154 ) )
V_6 -> V_80 . V_81 &= ~ ( V_152 | V_153 ) ;
if ( ! F_85 ( V_126 , V_84 ) ) {
if ( F_84 ( V_74 ) && F_74 ( V_74 ) ) {
ASSERT ( V_123 & V_139 ) ;
ASSERT ( V_130 ) ;
V_132 = F_90 ( V_124 , V_6 ,
& V_6 -> V_155 , V_130 ) ;
}
V_6 -> V_80 . V_156 = F_77 ( V_84 ) ;
V_1 -> V_85 = V_84 ;
}
if ( ! F_86 ( V_128 , V_86 ) ) {
if ( F_84 ( V_74 ) && F_75 ( V_74 ) ) {
ASSERT ( F_91 ( & V_74 -> V_44 ) ||
! F_92 ( V_74 ) ) ;
ASSERT ( V_123 & V_140 ) ;
ASSERT ( V_131 ) ;
V_133 = F_90 ( V_124 , V_6 ,
& V_6 -> V_157 , V_131 ) ;
}
V_6 -> V_80 . V_158 = F_78 ( V_86 ) ;
V_1 -> V_87 = V_86 ;
}
}
if ( V_123 & V_159 )
F_67 ( V_6 , V_106 ) ;
if ( V_123 & ( V_110 | V_117 | V_120 ) )
F_69 ( V_6 , V_106 ) ;
F_93 ( V_124 , V_6 , V_160 ) ;
F_94 ( V_161 ) ;
if ( V_74 -> V_135 & V_162 )
F_95 ( V_124 ) ;
error = F_96 ( V_124 , 0 ) ;
F_97 ( V_6 , V_108 ) ;
F_98 ( V_132 ) ;
F_98 ( V_133 ) ;
F_98 ( V_130 ) ;
F_98 ( V_131 ) ;
if ( error )
return error ;
if ( ( V_123 & V_159 ) && ! ( V_32 & V_134 ) ) {
error = F_99 ( V_1 , V_1 -> V_42 ) ;
if ( error )
return error ;
}
return 0 ;
V_151:
F_100 ( V_124 , 0 ) ;
F_97 ( V_6 , V_108 ) ;
V_148:
F_98 ( V_130 ) ;
F_98 ( V_131 ) ;
return error ;
}
int
F_101 (
struct V_5 * V_6 ,
struct V_106 * V_106 )
{
struct V_73 * V_74 = V_6 -> V_75 ;
struct V_1 * V_1 = F_19 ( V_6 ) ;
T_8 V_163 , V_164 ;
struct V_165 * V_124 ;
int error ;
T_7 V_166 = 0 ;
T_7 V_167 = 0 ;
bool V_168 = false ;
F_71 ( V_6 ) ;
if ( V_74 -> V_135 & V_136 )
return - V_137 ;
if ( F_58 ( V_74 ) )
return - V_76 ;
error = F_72 ( V_1 , V_106 ) ;
if ( error )
return error ;
ASSERT ( F_68 ( V_6 , V_169 ) ) ;
ASSERT ( F_68 ( V_6 , V_170 ) ) ;
ASSERT ( F_102 ( V_6 -> V_80 . V_81 ) ) ;
ASSERT ( ( V_106 -> V_109 & ( V_139 | V_140 | V_110 | V_171 |
V_172 | V_173 | V_174 ) ) == 0 ) ;
V_163 = V_1 -> V_175 ;
V_164 = V_106 -> V_176 ;
if ( V_164 == 0 && V_163 == 0 && V_6 -> V_80 . V_177 == 0 ) {
if ( ! ( V_106 -> V_109 & ( V_117 | V_120 ) ) )
return 0 ;
V_106 -> V_109 &= ~ V_138 ;
return F_70 ( V_6 , V_106 , 0 ) ;
}
error = F_103 ( V_6 , 0 ) ;
if ( error )
return error ;
if ( V_164 > V_163 ) {
error = F_104 ( V_6 , V_164 , V_163 , & V_168 ) ;
if ( error )
return error ;
}
if ( V_164 > V_6 -> V_80 . V_178 &&
( V_163 != V_6 -> V_80 . V_178 || V_168 ) ) {
error = F_105 ( F_19 ( V_6 ) -> V_179 ,
V_6 -> V_80 . V_178 , V_164 ) ;
if ( error )
return error ;
}
F_106 ( V_1 ) ;
error = F_107 ( V_1 -> V_179 , V_164 , V_180 ) ;
if ( error )
return error ;
F_108 ( V_1 , V_164 ) ;
V_124 = F_80 ( V_74 , V_181 ) ;
error = F_81 ( V_124 , & F_82 ( V_74 ) -> V_182 , 0 , 0 ) ;
if ( error )
goto V_151;
V_167 = V_183 ;
V_166 |= V_108 ;
F_83 ( V_6 , V_108 ) ;
F_89 ( V_124 , V_6 , 0 ) ;
if ( V_164 != V_163 &&
! ( V_106 -> V_109 & ( V_117 | V_120 ) ) ) {
V_106 -> V_118 = V_106 -> V_121 =
F_109 ( V_1 -> V_43 ) ;
V_106 -> V_109 |= V_117 | V_120 ;
}
V_6 -> V_80 . V_178 = V_164 ;
F_93 ( V_124 , V_6 , V_160 ) ;
if ( V_164 <= V_163 ) {
error = F_110 ( & V_124 , V_6 , V_184 , V_164 ) ;
if ( error )
goto V_185;
F_111 ( V_6 , V_186 ) ;
F_112 ( V_6 ) ;
}
if ( V_106 -> V_109 & V_159 )
F_67 ( V_6 , V_106 ) ;
if ( V_106 -> V_109 & ( V_110 | V_117 | V_120 ) )
F_69 ( V_6 , V_106 ) ;
F_93 ( V_124 , V_6 , V_160 ) ;
F_94 ( V_161 ) ;
if ( V_74 -> V_135 & V_162 )
F_95 ( V_124 ) ;
error = F_96 ( V_124 , V_183 ) ;
V_187:
if ( V_166 )
F_97 ( V_6 , V_166 ) ;
return error ;
V_185:
V_167 |= V_188 ;
V_151:
F_100 ( V_124 , V_167 ) ;
goto V_187;
}
STATIC int
F_113 (
struct V_15 * V_15 ,
struct V_106 * V_106 )
{
struct V_5 * V_6 = F_2 ( F_39 ( V_15 ) ) ;
int error ;
if ( V_106 -> V_109 & V_138 ) {
T_7 V_189 = V_169 ;
F_83 ( V_6 , V_189 ) ;
error = F_114 ( F_39 ( V_15 ) , & V_189 , true ) ;
if ( ! error ) {
F_83 ( V_6 , V_170 ) ;
V_189 |= V_170 ;
error = F_101 ( V_6 , V_106 ) ;
}
F_97 ( V_6 , V_189 ) ;
} else {
error = F_70 ( V_6 , V_106 , 0 ) ;
}
return error ;
}
STATIC int
F_115 (
struct V_1 * V_1 ,
struct V_190 * V_191 ,
int V_32 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_73 * V_74 = V_6 -> V_75 ;
struct V_165 * V_124 ;
int error ;
F_116 ( V_6 ) ;
V_124 = F_80 ( V_74 , V_192 ) ;
error = F_81 ( V_124 , & F_82 ( V_74 ) -> V_193 , 0 , 0 ) ;
if ( error ) {
F_100 ( V_124 , 0 ) ;
return error ;
}
F_83 ( V_6 , V_108 ) ;
if ( V_32 & V_194 ) {
V_1 -> V_94 = * V_191 ;
V_6 -> V_80 . V_119 . V_113 = ( V_195 ) V_191 -> V_114 ;
V_6 -> V_80 . V_119 . V_115 = ( V_195 ) V_191 -> V_116 ;
}
if ( V_32 & V_196 ) {
V_1 -> V_93 = * V_191 ;
V_6 -> V_80 . V_122 . V_113 = ( V_195 ) V_191 -> V_114 ;
V_6 -> V_80 . V_122 . V_115 = ( V_195 ) V_191 -> V_116 ;
}
if ( V_32 & V_197 ) {
V_1 -> V_91 = * V_191 ;
V_6 -> V_80 . V_112 . V_113 = ( V_195 ) V_191 -> V_114 ;
V_6 -> V_80 . V_112 . V_115 = ( V_195 ) V_191 -> V_116 ;
}
F_89 ( V_124 , V_6 , V_108 ) ;
F_93 ( V_124 , V_6 , V_198 ) ;
return F_96 ( V_124 , 0 ) ;
}
STATIC int
F_117 (
void * * V_199 ,
struct V_200 * V_201 ,
int * V_202 )
{
int error ;
struct V_203 * V_204 = * V_199 ;
T_9 V_205 = 0 ;
T_10 V_206 , V_207 , V_208 ;
if ( V_201 -> V_209 == - 1LL )
return 0 ;
V_206 = F_118 ( V_201 -> V_210 ) ;
V_207 = F_118 ( V_201 -> V_209 ) ;
V_208 = F_118 ( V_201 -> V_211 ) ;
if ( V_201 -> V_212 & V_213 )
V_205 |= V_214 ;
else if ( V_201 -> V_212 & V_215 ) {
V_205 |= ( V_216 |
V_217 ) ;
V_207 = 0 ;
}
if ( V_201 -> V_212 & V_218 )
V_205 |= V_219 ;
error = F_119 ( V_204 , V_206 , V_207 ,
V_208 , V_205 ) ;
if ( error > 0 ) {
error = 0 ;
* V_202 = 1 ;
}
return error ;
}
STATIC int
F_120 (
struct V_1 * V_1 ,
struct V_203 * V_204 ,
T_10 V_220 ,
T_10 V_208 )
{
T_11 * V_6 = F_2 ( V_1 ) ;
struct V_200 V_221 ;
int error ;
error = F_121 ( V_204 , V_222 ) ;
if ( error )
return error ;
V_221 . V_210 = F_122 ( V_220 ) ;
if ( V_208 == V_223 )
V_221 . V_211 = - 1LL ;
else
V_221 . V_211 = F_123 ( V_220 + V_208 ) - V_221 . V_210 ;
V_221 . V_224 = ! V_204 -> V_225 ? V_226 :
V_204 -> V_225 + 1 ;
V_221 . V_224 = F_124 ( V_227 , V_221 . V_224 ,
( V_228 * 16 / sizeof( struct V_200 ) ) ) ;
V_221 . V_229 = V_230 | V_231 ;
if ( V_204 -> V_232 & V_233 )
V_221 . V_229 |= V_234 ;
if ( ! ( V_204 -> V_232 & V_235 ) )
V_221 . V_229 |= V_236 ;
error = F_125 ( V_6 , & V_221 , F_117 , V_204 ) ;
if ( error )
return error ;
return 0 ;
}
STATIC int
F_126 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_16 )
{
return F_9 ( V_11 , V_15 , V_16 , 0 , true ) ;
}
STATIC void
F_127 (
struct V_1 * V_1 ,
struct V_5 * V_6 )
{
if ( V_6 -> V_80 . V_237 & V_238 )
V_1 -> V_239 |= V_240 ;
else
V_1 -> V_239 &= ~ V_240 ;
if ( V_6 -> V_80 . V_237 & V_241 )
V_1 -> V_239 |= V_242 ;
else
V_1 -> V_239 &= ~ V_242 ;
if ( V_6 -> V_80 . V_237 & V_243 )
V_1 -> V_239 |= V_244 ;
else
V_1 -> V_239 &= ~ V_244 ;
if ( V_6 -> V_80 . V_237 & V_245 )
V_1 -> V_239 |= V_246 ;
else
V_1 -> V_239 &= ~ V_246 ;
}
void
F_128 (
struct V_5 * V_6 )
{
struct V_1 * V_1 = & V_6 -> V_247 ;
T_12 V_248 ;
V_1 -> V_89 = V_6 -> V_89 ;
V_1 -> V_249 = V_250 ;
F_129 ( V_1 ) ;
F_130 ( & V_1 -> V_251 ) ;
V_1 -> V_42 = V_6 -> V_80 . V_81 ;
F_131 ( V_1 , V_6 -> V_80 . V_83 ) ;
V_1 -> V_85 = F_132 ( V_6 -> V_80 . V_156 ) ;
V_1 -> V_87 = F_133 ( V_6 -> V_80 . V_158 ) ;
switch ( V_1 -> V_42 & V_20 ) {
case V_98 :
case V_99 :
V_1 -> V_252 =
F_61 ( F_62 ( V_6 -> V_102 . V_103 . V_104 ) & 0x1ff ,
F_63 ( V_6 -> V_102 . V_103 . V_104 ) ) ;
break;
default:
V_1 -> V_252 = 0 ;
break;
}
V_1 -> V_253 = V_6 -> V_80 . V_254 ;
F_134 ( V_1 , V_6 -> V_80 . V_178 ) ;
V_1 -> V_91 . V_114 = V_6 -> V_80 . V_112 . V_113 ;
V_1 -> V_91 . V_116 = V_6 -> V_80 . V_112 . V_115 ;
V_1 -> V_93 . V_114 = V_6 -> V_80 . V_122 . V_113 ;
V_1 -> V_93 . V_116 = V_6 -> V_80 . V_122 . V_115 ;
V_1 -> V_94 . V_114 = V_6 -> V_80 . V_119 . V_113 ;
V_1 -> V_94 . V_116 = V_6 -> V_80 . V_119 . V_115 ;
F_127 ( V_1 , V_6 ) ;
V_6 -> V_255 = V_6 -> V_75 -> V_256 ;
F_135 ( & V_6 -> V_257 . V_258 , & V_259 ) ;
switch ( V_1 -> V_42 & V_20 ) {
case V_260 :
V_1 -> V_261 = & V_262 ;
V_1 -> V_263 = & V_264 ;
V_1 -> V_179 -> V_265 = & V_266 ;
break;
case V_33 :
F_135 ( & V_6 -> V_257 . V_258 , & V_267 ) ;
if ( F_43 ( & F_44 ( V_1 -> V_43 ) -> V_44 ) )
V_1 -> V_261 = & V_268 ;
else
V_1 -> V_261 = & V_269 ;
V_1 -> V_263 = & V_270 ;
V_6 -> V_255 = V_6 -> V_75 -> V_271 ;
break;
case V_46 :
V_1 -> V_261 = & V_272 ;
if ( ! ( V_6 -> V_102 . V_273 & V_274 ) )
V_1 -> V_179 -> V_265 = & V_266 ;
break;
default:
V_1 -> V_261 = & V_262 ;
F_136 ( V_1 , V_1 -> V_42 , V_1 -> V_252 ) ;
break;
}
V_248 = F_137 ( V_1 -> V_179 ) ;
F_138 ( V_1 -> V_179 , ( V_248 & ~ ( V_275 ) ) ) ;
if ( ! F_139 ( V_6 ) ) {
F_140 ( V_1 ) ;
F_141 ( V_1 ) ;
}
}
