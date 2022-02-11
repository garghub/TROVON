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
void * * V_61 )
{
char * V_62 ;
int error = - V_63 ;
V_62 = F_52 ( V_64 + 1 , V_65 ) ;
if ( ! V_62 )
goto V_66;
error = F_53 ( F_2 ( F_39 ( V_15 ) ) , V_62 ) ;
if ( F_12 ( error ) )
goto V_67;
return * V_61 = V_62 ;
V_67:
F_54 ( V_62 ) ;
V_66:
return F_31 ( error ) ;
}
STATIC int
F_55 (
struct V_68 * V_69 ,
struct V_15 * V_15 ,
struct V_70 * V_71 )
{
struct V_1 * V_1 = F_39 ( V_15 ) ;
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_72 * V_73 = V_6 -> V_74 ;
F_56 ( V_6 ) ;
if ( F_57 ( V_73 ) )
return - V_75 ;
V_71 -> V_76 = F_58 ( V_6 ) ;
V_71 -> V_77 = V_1 -> V_43 -> V_78 ;
V_71 -> V_16 = V_6 -> V_79 . V_80 ;
V_71 -> V_81 = V_6 -> V_79 . V_82 ;
V_71 -> V_83 = V_1 -> V_84 ;
V_71 -> V_85 = V_1 -> V_86 ;
V_71 -> V_87 = V_6 -> V_88 ;
V_71 -> V_89 = V_1 -> V_90 ;
V_71 -> V_91 = V_1 -> V_92 ;
V_71 -> ctime = V_1 -> V_93 ;
V_71 -> V_94 =
F_59 ( V_73 , V_6 -> V_79 . V_95 + V_6 -> V_96 ) ;
switch ( V_1 -> V_42 & V_20 ) {
case V_97 :
case V_98 :
V_71 -> V_99 = V_100 ;
V_71 -> V_23 = F_60 ( F_61 ( V_6 -> V_101 . V_102 . V_103 ) & 0x1ff ,
F_62 ( V_6 -> V_101 . V_102 . V_103 ) ) ;
break;
default:
if ( F_63 ( V_6 ) ) {
V_71 -> V_99 =
F_64 ( V_6 ) << V_73 -> V_44 . V_104 ;
} else
V_71 -> V_99 = F_65 ( V_73 ) ;
V_71 -> V_23 = 0 ;
break;
}
return 0 ;
}
static void
F_66 (
struct V_5 * V_6 ,
struct V_105 * V_105 )
{
struct V_1 * V_1 = F_19 ( V_6 ) ;
T_1 V_16 = V_105 -> V_106 ;
ASSERT ( F_67 ( V_6 , V_107 ) ) ;
V_6 -> V_79 . V_80 &= V_20 ;
V_6 -> V_79 . V_80 |= V_16 & ~ V_20 ;
V_1 -> V_42 &= V_20 ;
V_1 -> V_42 |= V_16 & ~ V_20 ;
}
void
F_68 (
struct V_5 * V_6 ,
struct V_105 * V_105 )
{
struct V_1 * V_1 = F_19 ( V_6 ) ;
ASSERT ( F_67 ( V_6 , V_107 ) ) ;
if ( V_105 -> V_108 & V_109 ) {
V_1 -> V_90 = V_105 -> V_110 ;
V_6 -> V_79 . V_111 . V_112 = V_105 -> V_110 . V_113 ;
V_6 -> V_79 . V_111 . V_114 = V_105 -> V_110 . V_115 ;
}
if ( V_105 -> V_108 & V_116 ) {
V_1 -> V_93 = V_105 -> V_117 ;
V_6 -> V_79 . V_118 . V_112 = V_105 -> V_117 . V_113 ;
V_6 -> V_79 . V_118 . V_114 = V_105 -> V_117 . V_115 ;
}
if ( V_105 -> V_108 & V_119 ) {
V_1 -> V_92 = V_105 -> V_120 ;
V_6 -> V_79 . V_121 . V_112 = V_105 -> V_120 . V_113 ;
V_6 -> V_79 . V_121 . V_114 = V_105 -> V_120 . V_115 ;
}
}
int
F_69 (
struct V_5 * V_6 ,
struct V_105 * V_105 ,
int V_32 )
{
T_3 * V_73 = V_6 -> V_74 ;
struct V_1 * V_1 = F_19 ( V_6 ) ;
int V_122 = V_105 -> V_108 ;
T_4 * V_123 ;
int error ;
T_5 V_83 = V_124 , V_125 = V_124 ;
T_6 V_85 = V_126 , V_127 = V_126 ;
struct V_128 * V_129 = NULL , * V_130 = NULL ;
struct V_128 * V_131 = NULL , * V_132 = NULL ;
F_70 ( V_6 ) ;
if ( ! ( V_32 & V_133 ) ) {
if ( V_73 -> V_134 & V_135 )
return - V_136 ;
if ( F_57 ( V_73 ) )
return - V_75 ;
error = F_71 ( V_1 , V_105 ) ;
if ( error )
return error ;
}
ASSERT ( ( V_122 & V_137 ) == 0 ) ;
if ( F_72 ( V_73 ) && ( V_122 & ( V_138 | V_139 ) ) ) {
T_7 V_140 = 0 ;
if ( ( V_122 & V_138 ) && F_73 ( V_73 ) ) {
V_83 = V_105 -> V_141 ;
V_140 |= V_142 ;
} else {
V_83 = V_1 -> V_84 ;
}
if ( ( V_122 & V_139 ) && F_74 ( V_73 ) ) {
V_85 = V_105 -> V_143 ;
V_140 |= V_144 ;
} else {
V_85 = V_1 -> V_86 ;
}
ASSERT ( V_129 == NULL ) ;
ASSERT ( V_130 == NULL ) ;
error = F_75 ( V_6 , F_76 ( V_83 ) ,
F_77 ( V_85 ) ,
F_78 ( V_6 ) ,
V_140 , & V_129 , & V_130 , NULL ) ;
if ( error )
return error ;
}
V_123 = F_79 ( V_73 , V_145 ) ;
error = F_80 ( V_123 , & F_81 ( V_73 ) -> V_146 , 0 , 0 ) ;
if ( error )
goto V_147;
F_82 ( V_6 , V_107 ) ;
if ( V_122 & ( V_138 | V_139 ) ) {
V_125 = V_1 -> V_84 ;
V_127 = V_1 -> V_86 ;
V_85 = ( V_122 & V_139 ) ? V_105 -> V_143 : V_127 ;
V_83 = ( V_122 & V_138 ) ? V_105 -> V_141 : V_125 ;
if ( F_83 ( V_73 ) &&
( ( F_73 ( V_73 ) && ! F_84 ( V_125 , V_83 ) ) ||
( F_74 ( V_73 ) && ! F_85 ( V_127 , V_85 ) ) ) ) {
ASSERT ( V_123 ) ;
error = F_86 ( V_123 , V_6 , V_129 , V_130 ,
NULL , F_87 ( V_148 ) ?
V_149 : 0 ) ;
if ( error )
goto V_150;
}
}
F_88 ( V_123 , V_6 , 0 ) ;
if ( V_122 & ( V_138 | V_139 ) ) {
if ( ( V_6 -> V_79 . V_80 & ( V_151 | V_152 ) ) &&
! F_87 ( V_153 ) )
V_6 -> V_79 . V_80 &= ~ ( V_151 | V_152 ) ;
if ( ! F_84 ( V_125 , V_83 ) ) {
if ( F_83 ( V_73 ) && F_73 ( V_73 ) ) {
ASSERT ( V_122 & V_138 ) ;
ASSERT ( V_129 ) ;
V_131 = F_89 ( V_123 , V_6 ,
& V_6 -> V_154 , V_129 ) ;
}
V_6 -> V_79 . V_155 = F_76 ( V_83 ) ;
V_1 -> V_84 = V_83 ;
}
if ( ! F_85 ( V_127 , V_85 ) ) {
if ( F_83 ( V_73 ) && F_74 ( V_73 ) ) {
ASSERT ( F_90 ( & V_73 -> V_44 ) ||
! F_91 ( V_73 ) ) ;
ASSERT ( V_122 & V_139 ) ;
ASSERT ( V_130 ) ;
V_132 = F_89 ( V_123 , V_6 ,
& V_6 -> V_156 , V_130 ) ;
}
V_6 -> V_79 . V_157 = F_77 ( V_85 ) ;
V_1 -> V_86 = V_85 ;
}
}
if ( V_122 & V_158 )
F_66 ( V_6 , V_105 ) ;
if ( V_122 & ( V_109 | V_116 | V_119 ) )
F_68 ( V_6 , V_105 ) ;
F_92 ( V_123 , V_6 , V_159 ) ;
F_93 ( V_73 , V_160 ) ;
if ( V_73 -> V_134 & V_161 )
F_94 ( V_123 ) ;
error = F_95 ( V_123 ) ;
F_96 ( V_6 , V_107 ) ;
F_97 ( V_131 ) ;
F_97 ( V_132 ) ;
F_97 ( V_129 ) ;
F_97 ( V_130 ) ;
if ( error )
return error ;
if ( ( V_122 & V_158 ) && ! ( V_32 & V_133 ) ) {
error = F_98 ( V_1 , V_1 -> V_42 ) ;
if ( error )
return error ;
}
return 0 ;
V_150:
F_96 ( V_6 , V_107 ) ;
V_147:
F_99 ( V_123 ) ;
F_97 ( V_129 ) ;
F_97 ( V_130 ) ;
return error ;
}
int
F_100 (
struct V_5 * V_6 ,
struct V_105 * V_105 )
{
struct V_72 * V_73 = V_6 -> V_74 ;
struct V_1 * V_1 = F_19 ( V_6 ) ;
T_8 V_162 , V_163 ;
struct V_164 * V_123 ;
int error ;
T_7 V_165 = 0 ;
bool V_166 = false ;
F_70 ( V_6 ) ;
if ( V_73 -> V_134 & V_135 )
return - V_136 ;
if ( F_57 ( V_73 ) )
return - V_75 ;
error = F_71 ( V_1 , V_105 ) ;
if ( error )
return error ;
ASSERT ( F_67 ( V_6 , V_167 ) ) ;
ASSERT ( F_67 ( V_6 , V_168 ) ) ;
ASSERT ( F_101 ( V_6 -> V_79 . V_80 ) ) ;
ASSERT ( ( V_105 -> V_108 & ( V_138 | V_139 | V_109 | V_169 |
V_170 | V_171 | V_172 ) ) == 0 ) ;
V_162 = V_1 -> V_173 ;
V_163 = V_105 -> V_174 ;
if ( V_163 == 0 && V_162 == 0 && V_6 -> V_79 . V_175 == 0 ) {
if ( ! ( V_105 -> V_108 & ( V_116 | V_119 ) ) )
return 0 ;
V_105 -> V_108 &= ~ V_137 ;
return F_69 ( V_6 , V_105 , 0 ) ;
}
error = F_102 ( V_6 , 0 ) ;
if ( error )
return error ;
if ( V_163 > V_162 ) {
error = F_103 ( V_6 , V_163 , V_162 , & V_166 ) ;
if ( error )
return error ;
}
if ( V_163 > V_6 -> V_79 . V_176 &&
( V_162 != V_6 -> V_79 . V_176 || V_166 ) ) {
error = F_104 ( F_19 ( V_6 ) -> V_177 ,
V_6 -> V_79 . V_176 , V_163 ) ;
if ( error )
return error ;
}
F_105 ( V_1 ) ;
if ( F_106 ( V_1 ) )
error = F_107 ( V_1 , V_163 , V_178 ) ;
else
error = F_108 ( V_1 -> V_177 , V_163 ,
V_179 ) ;
if ( error )
return error ;
F_109 ( V_1 , V_163 ) ;
V_123 = F_79 ( V_73 , V_180 ) ;
error = F_80 ( V_123 , & F_81 ( V_73 ) -> V_181 , 0 , 0 ) ;
if ( error )
goto V_147;
V_165 |= V_107 ;
F_82 ( V_6 , V_107 ) ;
F_88 ( V_123 , V_6 , 0 ) ;
if ( V_163 != V_162 &&
! ( V_105 -> V_108 & ( V_116 | V_119 ) ) ) {
V_105 -> V_117 = V_105 -> V_120 =
F_110 ( V_1 -> V_43 ) ;
V_105 -> V_108 |= V_116 | V_119 ;
}
V_6 -> V_79 . V_176 = V_163 ;
F_92 ( V_123 , V_6 , V_159 ) ;
if ( V_163 <= V_162 ) {
error = F_111 ( & V_123 , V_6 , V_182 , V_163 ) ;
if ( error )
goto V_147;
F_112 ( V_6 , V_183 ) ;
F_113 ( V_6 ) ;
}
if ( V_105 -> V_108 & V_158 )
F_66 ( V_6 , V_105 ) ;
if ( V_105 -> V_108 & ( V_109 | V_116 | V_119 ) )
F_68 ( V_6 , V_105 ) ;
F_92 ( V_123 , V_6 , V_159 ) ;
F_93 ( V_73 , V_160 ) ;
if ( V_73 -> V_134 & V_161 )
F_94 ( V_123 ) ;
error = F_95 ( V_123 ) ;
V_150:
if ( V_165 )
F_96 ( V_6 , V_165 ) ;
return error ;
V_147:
F_99 ( V_123 ) ;
goto V_150;
}
STATIC int
F_114 (
struct V_15 * V_15 ,
struct V_105 * V_105 )
{
struct V_5 * V_6 = F_2 ( F_39 ( V_15 ) ) ;
int error ;
if ( V_105 -> V_108 & V_137 ) {
T_7 V_184 = V_167 ;
F_82 ( V_6 , V_184 ) ;
error = F_115 ( F_39 ( V_15 ) , & V_184 , true ) ;
if ( ! error ) {
F_82 ( V_6 , V_168 ) ;
V_184 |= V_168 ;
error = F_100 ( V_6 , V_105 ) ;
}
F_96 ( V_6 , V_184 ) ;
} else {
error = F_69 ( V_6 , V_105 , 0 ) ;
}
return error ;
}
STATIC int
F_116 (
struct V_1 * V_1 ,
struct V_185 * V_186 ,
int V_32 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_72 * V_73 = V_6 -> V_74 ;
struct V_164 * V_123 ;
int error ;
F_117 ( V_6 ) ;
V_123 = F_79 ( V_73 , V_187 ) ;
error = F_80 ( V_123 , & F_81 ( V_73 ) -> V_188 , 0 , 0 ) ;
if ( error ) {
F_99 ( V_123 ) ;
return error ;
}
F_82 ( V_6 , V_107 ) ;
if ( V_32 & V_189 ) {
V_1 -> V_93 = * V_186 ;
V_6 -> V_79 . V_118 . V_112 = ( V_190 ) V_186 -> V_113 ;
V_6 -> V_79 . V_118 . V_114 = ( V_190 ) V_186 -> V_115 ;
}
if ( V_32 & V_191 ) {
V_1 -> V_92 = * V_186 ;
V_6 -> V_79 . V_121 . V_112 = ( V_190 ) V_186 -> V_113 ;
V_6 -> V_79 . V_121 . V_114 = ( V_190 ) V_186 -> V_115 ;
}
if ( V_32 & V_192 ) {
V_1 -> V_90 = * V_186 ;
V_6 -> V_79 . V_111 . V_112 = ( V_190 ) V_186 -> V_113 ;
V_6 -> V_79 . V_111 . V_114 = ( V_190 ) V_186 -> V_115 ;
}
F_88 ( V_123 , V_6 , V_107 ) ;
F_92 ( V_123 , V_6 , V_193 ) ;
return F_95 ( V_123 ) ;
}
STATIC int
F_118 (
void * * V_194 ,
struct V_195 * V_196 ,
int * V_197 )
{
int error ;
struct V_198 * V_199 = * V_194 ;
T_9 V_200 = 0 ;
T_10 V_201 , V_202 , V_203 ;
if ( V_196 -> V_204 == - 1LL )
return 0 ;
V_201 = F_119 ( V_196 -> V_205 ) ;
V_202 = F_119 ( V_196 -> V_204 ) ;
V_203 = F_119 ( V_196 -> V_206 ) ;
if ( V_196 -> V_207 & V_208 )
V_200 |= V_209 ;
else if ( V_196 -> V_207 & V_210 ) {
V_200 |= ( V_211 |
V_212 ) ;
V_202 = 0 ;
}
if ( V_196 -> V_207 & V_213 )
V_200 |= V_214 ;
error = F_120 ( V_199 , V_201 , V_202 ,
V_203 , V_200 ) ;
if ( error > 0 ) {
error = 0 ;
* V_197 = 1 ;
}
return error ;
}
STATIC int
F_121 (
struct V_1 * V_1 ,
struct V_198 * V_199 ,
T_10 V_215 ,
T_10 V_203 )
{
T_11 * V_6 = F_2 ( V_1 ) ;
struct V_195 V_216 ;
int error ;
error = F_122 ( V_199 , V_217 ) ;
if ( error )
return error ;
V_216 . V_205 = F_123 ( V_215 ) ;
if ( V_203 == V_218 )
V_216 . V_206 = - 1LL ;
else
V_216 . V_206 = F_124 ( V_215 + V_203 ) - V_216 . V_205 ;
V_216 . V_219 = ! V_199 -> V_220 ? V_221 :
V_199 -> V_220 + 1 ;
V_216 . V_219 = F_125 ( V_222 , V_216 . V_219 ,
( V_223 * 16 / sizeof( struct V_195 ) ) ) ;
V_216 . V_224 = V_225 | V_226 ;
if ( V_199 -> V_227 & V_228 )
V_216 . V_224 |= V_229 ;
if ( ! ( V_199 -> V_227 & V_230 ) )
V_216 . V_224 |= V_231 ;
error = F_126 ( V_6 , & V_216 , F_118 , V_199 ) ;
if ( error )
return error ;
return 0 ;
}
STATIC int
F_127 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_16 )
{
return F_9 ( V_11 , V_15 , V_16 , 0 , true ) ;
}
STATIC void
F_128 (
struct V_1 * V_1 ,
struct V_5 * V_6 )
{
T_12 V_32 = V_6 -> V_79 . V_232 ;
V_1 -> V_233 &= ~ ( V_234 | V_235 | V_236 |
V_237 | V_238 ) ;
if ( V_32 & V_239 )
V_1 -> V_233 |= V_234 ;
if ( V_32 & V_240 )
V_1 -> V_233 |= V_235 ;
if ( V_32 & V_241 )
V_1 -> V_233 |= V_236 ;
if ( V_32 & V_242 )
V_1 -> V_233 |= V_237 ;
if ( V_6 -> V_74 -> V_134 & V_243 )
V_1 -> V_233 |= V_238 ;
}
void
F_129 (
struct V_5 * V_6 )
{
struct V_1 * V_1 = & V_6 -> V_244 ;
T_13 V_245 ;
V_1 -> V_88 = V_6 -> V_88 ;
V_1 -> V_246 = V_247 ;
F_130 ( V_1 ) ;
F_131 ( & V_1 -> V_248 ) ;
V_1 -> V_42 = V_6 -> V_79 . V_80 ;
F_132 ( V_1 , V_6 -> V_79 . V_82 ) ;
V_1 -> V_84 = F_133 ( V_6 -> V_79 . V_155 ) ;
V_1 -> V_86 = F_134 ( V_6 -> V_79 . V_157 ) ;
switch ( V_1 -> V_42 & V_20 ) {
case V_97 :
case V_98 :
V_1 -> V_249 =
F_60 ( F_61 ( V_6 -> V_101 . V_102 . V_103 ) & 0x1ff ,
F_62 ( V_6 -> V_101 . V_102 . V_103 ) ) ;
break;
default:
V_1 -> V_249 = 0 ;
break;
}
V_1 -> V_250 = V_6 -> V_79 . V_251 ;
F_135 ( V_1 , V_6 -> V_79 . V_176 ) ;
V_1 -> V_90 . V_113 = V_6 -> V_79 . V_111 . V_112 ;
V_1 -> V_90 . V_115 = V_6 -> V_79 . V_111 . V_114 ;
V_1 -> V_92 . V_113 = V_6 -> V_79 . V_121 . V_112 ;
V_1 -> V_92 . V_115 = V_6 -> V_79 . V_121 . V_114 ;
V_1 -> V_93 . V_113 = V_6 -> V_79 . V_118 . V_112 ;
V_1 -> V_93 . V_115 = V_6 -> V_79 . V_118 . V_114 ;
F_128 ( V_1 , V_6 ) ;
V_6 -> V_252 = V_6 -> V_74 -> V_253 ;
F_136 ( & V_6 -> V_254 . V_255 , & V_256 ) ;
switch ( V_1 -> V_42 & V_20 ) {
case V_257 :
V_1 -> V_258 = & V_259 ;
V_1 -> V_260 = & V_261 ;
V_1 -> V_177 -> V_262 = & V_263 ;
break;
case V_33 :
F_136 ( & V_6 -> V_254 . V_255 , & V_264 ) ;
if ( F_43 ( & F_44 ( V_1 -> V_43 ) -> V_44 ) )
V_1 -> V_258 = & V_265 ;
else
V_1 -> V_258 = & V_266 ;
V_1 -> V_260 = & V_267 ;
V_6 -> V_252 = V_6 -> V_74 -> V_268 ;
break;
case V_46 :
V_1 -> V_258 = & V_269 ;
if ( ! ( V_6 -> V_101 . V_270 & V_271 ) )
V_1 -> V_177 -> V_262 = & V_263 ;
break;
default:
V_1 -> V_258 = & V_259 ;
F_137 ( V_1 , V_1 -> V_42 , V_1 -> V_249 ) ;
break;
}
V_245 = F_138 ( V_1 -> V_177 ) ;
F_139 ( V_1 -> V_177 , ( V_245 & ~ ( V_272 ) ) ) ;
if ( ! F_140 ( V_6 ) ) {
F_141 ( V_1 ) ;
F_142 ( V_1 ) ;
}
}
