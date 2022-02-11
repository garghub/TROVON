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
V_74 -> V_16 = V_1 -> V_42 ;
V_74 -> V_82 = V_1 -> V_83 ;
V_74 -> V_84 = V_1 -> V_85 ;
V_74 -> V_86 = V_1 -> V_87 ;
V_74 -> V_88 = V_6 -> V_89 ;
V_74 -> V_90 = V_1 -> V_91 ;
V_74 -> V_92 = V_1 -> V_93 ;
V_74 -> ctime = V_1 -> V_94 ;
V_74 -> V_95 =
F_60 ( V_76 , V_6 -> V_96 . V_97 + V_6 -> V_98 ) ;
switch ( V_1 -> V_42 & V_20 ) {
case V_99 :
case V_100 :
V_74 -> V_101 = V_102 ;
V_74 -> V_23 = F_61 ( F_62 ( V_6 -> V_103 . V_104 . V_105 ) & 0x1ff ,
F_63 ( V_6 -> V_103 . V_104 . V_105 ) ) ;
break;
default:
if ( F_64 ( V_6 ) ) {
V_74 -> V_101 =
F_65 ( V_6 ) << V_76 -> V_44 . V_106 ;
} else
V_74 -> V_101 = F_66 ( V_76 ) ;
V_74 -> V_23 = 0 ;
break;
}
return 0 ;
}
static void
F_67 (
struct V_5 * V_6 ,
struct V_107 * V_107 )
{
struct V_1 * V_1 = F_19 ( V_6 ) ;
T_1 V_16 = V_107 -> V_108 ;
ASSERT ( F_68 ( V_6 , V_109 ) ) ;
V_1 -> V_42 &= V_20 ;
V_1 -> V_42 |= V_16 & ~ V_20 ;
}
void
F_69 (
struct V_5 * V_6 ,
struct V_107 * V_107 )
{
struct V_1 * V_1 = F_19 ( V_6 ) ;
ASSERT ( F_68 ( V_6 , V_109 ) ) ;
if ( V_107 -> V_110 & V_111 )
V_1 -> V_91 = V_107 -> V_112 ;
if ( V_107 -> V_110 & V_113 )
V_1 -> V_94 = V_107 -> V_114 ;
if ( V_107 -> V_110 & V_115 )
V_1 -> V_93 = V_107 -> V_116 ;
}
int
F_70 (
struct V_5 * V_6 ,
struct V_107 * V_107 ,
int V_32 )
{
T_3 * V_76 = V_6 -> V_77 ;
struct V_1 * V_1 = F_19 ( V_6 ) ;
int V_117 = V_107 -> V_110 ;
T_4 * V_118 ;
int error ;
T_5 V_84 = V_119 , V_120 = V_119 ;
T_6 V_86 = V_121 , V_122 = V_121 ;
struct V_123 * V_124 = NULL , * V_125 = NULL ;
struct V_123 * V_126 = NULL , * V_127 = NULL ;
F_71 ( V_6 ) ;
if ( ! ( V_32 & V_128 ) ) {
if ( V_76 -> V_129 & V_130 )
return - V_131 ;
if ( F_58 ( V_76 ) )
return - V_78 ;
error = F_72 ( V_1 , V_107 ) ;
if ( error )
return error ;
}
ASSERT ( ( V_117 & V_132 ) == 0 ) ;
if ( F_73 ( V_76 ) && ( V_117 & ( V_133 | V_134 ) ) ) {
T_7 V_135 = 0 ;
if ( ( V_117 & V_133 ) && F_74 ( V_76 ) ) {
V_84 = V_107 -> V_136 ;
V_135 |= V_137 ;
} else {
V_84 = V_1 -> V_85 ;
}
if ( ( V_117 & V_134 ) && F_75 ( V_76 ) ) {
V_86 = V_107 -> V_138 ;
V_135 |= V_139 ;
} else {
V_86 = V_1 -> V_87 ;
}
ASSERT ( V_124 == NULL ) ;
ASSERT ( V_125 == NULL ) ;
error = F_76 ( V_6 , F_77 ( V_84 ) ,
F_78 ( V_86 ) ,
F_79 ( V_6 ) ,
V_135 , & V_124 , & V_125 , NULL ) ;
if ( error )
return error ;
}
V_118 = F_80 ( V_76 , V_140 ) ;
error = F_81 ( V_118 , & F_82 ( V_76 ) -> V_141 , 0 , 0 ) ;
if ( error )
goto V_142;
F_83 ( V_6 , V_109 ) ;
if ( V_117 & ( V_133 | V_134 ) ) {
V_120 = V_1 -> V_85 ;
V_122 = V_1 -> V_87 ;
V_86 = ( V_117 & V_134 ) ? V_107 -> V_138 : V_122 ;
V_84 = ( V_117 & V_133 ) ? V_107 -> V_136 : V_120 ;
if ( F_84 ( V_76 ) &&
( ( F_74 ( V_76 ) && ! F_85 ( V_120 , V_84 ) ) ||
( F_75 ( V_76 ) && ! F_86 ( V_122 , V_86 ) ) ) ) {
ASSERT ( V_118 ) ;
error = F_87 ( V_118 , V_6 , V_124 , V_125 ,
NULL , F_88 ( V_143 ) ?
V_144 : 0 ) ;
if ( error )
goto V_145;
}
}
F_89 ( V_118 , V_6 , 0 ) ;
if ( V_117 & ( V_133 | V_134 ) ) {
if ( ( V_1 -> V_42 & ( V_146 | V_147 ) ) &&
! F_88 ( V_148 ) )
V_1 -> V_42 &= ~ ( V_146 | V_147 ) ;
if ( ! F_85 ( V_120 , V_84 ) ) {
if ( F_84 ( V_76 ) && F_74 ( V_76 ) ) {
ASSERT ( V_117 & V_133 ) ;
ASSERT ( V_124 ) ;
V_126 = F_90 ( V_118 , V_6 ,
& V_6 -> V_149 , V_124 ) ;
}
V_6 -> V_96 . V_150 = F_77 ( V_84 ) ;
V_1 -> V_85 = V_84 ;
}
if ( ! F_86 ( V_122 , V_86 ) ) {
if ( F_84 ( V_76 ) && F_75 ( V_76 ) ) {
ASSERT ( F_91 ( & V_76 -> V_44 ) ||
! F_92 ( V_76 ) ) ;
ASSERT ( V_117 & V_134 ) ;
ASSERT ( V_125 ) ;
V_127 = F_90 ( V_118 , V_6 ,
& V_6 -> V_151 , V_125 ) ;
}
V_6 -> V_96 . V_152 = F_78 ( V_86 ) ;
V_1 -> V_87 = V_86 ;
}
}
if ( V_117 & V_153 )
F_67 ( V_6 , V_107 ) ;
if ( V_117 & ( V_111 | V_113 | V_115 ) )
F_69 ( V_6 , V_107 ) ;
F_93 ( V_118 , V_6 , V_154 ) ;
F_94 ( V_76 , V_155 ) ;
if ( V_76 -> V_129 & V_156 )
F_95 ( V_118 ) ;
error = F_96 ( V_118 ) ;
F_97 ( V_6 , V_109 ) ;
F_98 ( V_126 ) ;
F_98 ( V_127 ) ;
F_98 ( V_124 ) ;
F_98 ( V_125 ) ;
if ( error )
return error ;
if ( ( V_117 & V_153 ) && ! ( V_32 & V_128 ) ) {
error = F_99 ( V_1 , V_1 -> V_42 ) ;
if ( error )
return error ;
}
return 0 ;
V_145:
F_97 ( V_6 , V_109 ) ;
V_142:
F_100 ( V_118 ) ;
F_98 ( V_124 ) ;
F_98 ( V_125 ) ;
return error ;
}
int
F_101 (
struct V_5 * V_6 ,
struct V_107 * V_107 )
{
struct V_75 * V_76 = V_6 -> V_77 ;
struct V_1 * V_1 = F_19 ( V_6 ) ;
T_8 V_157 , V_158 ;
struct V_159 * V_118 ;
int error ;
T_7 V_160 = 0 ;
bool V_161 = false ;
F_71 ( V_6 ) ;
if ( V_76 -> V_129 & V_130 )
return - V_131 ;
if ( F_58 ( V_76 ) )
return - V_78 ;
error = F_72 ( V_1 , V_107 ) ;
if ( error )
return error ;
ASSERT ( F_68 ( V_6 , V_162 ) ) ;
ASSERT ( F_68 ( V_6 , V_163 ) ) ;
ASSERT ( F_102 ( V_1 -> V_42 ) ) ;
ASSERT ( ( V_107 -> V_110 & ( V_133 | V_134 | V_111 | V_164 |
V_165 | V_166 | V_167 ) ) == 0 ) ;
V_157 = V_1 -> V_168 ;
V_158 = V_107 -> V_169 ;
if ( V_158 == 0 && V_157 == 0 && V_6 -> V_96 . V_170 == 0 ) {
if ( ! ( V_107 -> V_110 & ( V_113 | V_115 ) ) )
return 0 ;
V_107 -> V_110 &= ~ V_132 ;
return F_70 ( V_6 , V_107 , 0 ) ;
}
error = F_103 ( V_6 , 0 ) ;
if ( error )
return error ;
if ( V_158 > V_157 ) {
error = F_104 ( V_6 , V_158 , V_157 , & V_161 ) ;
if ( error )
return error ;
}
if ( V_158 > V_6 -> V_96 . V_171 &&
( V_157 != V_6 -> V_96 . V_171 || V_161 ) ) {
error = F_105 ( F_19 ( V_6 ) -> V_172 ,
V_6 -> V_96 . V_171 , V_158 ) ;
if ( error )
return error ;
}
F_106 ( V_1 ) ;
if ( F_107 ( V_1 ) )
error = F_108 ( V_1 , V_158 , V_173 ) ;
else
error = F_109 ( V_1 -> V_172 , V_158 ,
V_174 ) ;
if ( error )
return error ;
F_110 ( V_1 , V_158 ) ;
V_118 = F_80 ( V_76 , V_175 ) ;
error = F_81 ( V_118 , & F_82 ( V_76 ) -> V_176 , 0 , 0 ) ;
if ( error )
goto V_142;
V_160 |= V_109 ;
F_83 ( V_6 , V_109 ) ;
F_89 ( V_118 , V_6 , 0 ) ;
if ( V_158 != V_157 &&
! ( V_107 -> V_110 & ( V_113 | V_115 ) ) ) {
V_107 -> V_114 = V_107 -> V_116 =
F_111 ( V_1 -> V_43 ) ;
V_107 -> V_110 |= V_113 | V_115 ;
}
V_6 -> V_96 . V_171 = V_158 ;
F_93 ( V_118 , V_6 , V_154 ) ;
if ( V_158 <= V_157 ) {
error = F_112 ( & V_118 , V_6 , V_177 , V_158 ) ;
if ( error )
goto V_142;
F_113 ( V_6 , V_178 ) ;
F_114 ( V_6 ) ;
}
if ( V_107 -> V_110 & V_153 )
F_67 ( V_6 , V_107 ) ;
if ( V_107 -> V_110 & ( V_111 | V_113 | V_115 ) )
F_69 ( V_6 , V_107 ) ;
F_93 ( V_118 , V_6 , V_154 ) ;
F_94 ( V_76 , V_155 ) ;
if ( V_76 -> V_129 & V_156 )
F_95 ( V_118 ) ;
error = F_96 ( V_118 ) ;
V_145:
if ( V_160 )
F_97 ( V_6 , V_160 ) ;
return error ;
V_142:
F_100 ( V_118 ) ;
goto V_145;
}
STATIC int
F_115 (
struct V_15 * V_15 ,
struct V_107 * V_107 )
{
struct V_5 * V_6 = F_2 ( F_39 ( V_15 ) ) ;
int error ;
if ( V_107 -> V_110 & V_132 ) {
T_7 V_179 = V_162 ;
F_83 ( V_6 , V_179 ) ;
error = F_116 ( F_39 ( V_15 ) , & V_179 , true ) ;
if ( ! error ) {
F_83 ( V_6 , V_163 ) ;
V_179 |= V_163 ;
error = F_101 ( V_6 , V_107 ) ;
}
F_97 ( V_6 , V_179 ) ;
} else {
error = F_70 ( V_6 , V_107 , 0 ) ;
}
return error ;
}
STATIC int
F_117 (
struct V_1 * V_1 ,
struct V_180 * V_181 ,
int V_32 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_75 * V_76 = V_6 -> V_77 ;
struct V_159 * V_118 ;
int error ;
F_118 ( V_6 ) ;
V_118 = F_80 ( V_76 , V_182 ) ;
error = F_81 ( V_118 , & F_82 ( V_76 ) -> V_183 , 0 , 0 ) ;
if ( error ) {
F_100 ( V_118 ) ;
return error ;
}
F_83 ( V_6 , V_109 ) ;
if ( V_32 & V_184 )
V_1 -> V_94 = * V_181 ;
if ( V_32 & V_185 )
V_1 -> V_93 = * V_181 ;
if ( V_32 & V_186 )
V_1 -> V_91 = * V_181 ;
F_89 ( V_118 , V_6 , V_109 ) ;
F_93 ( V_118 , V_6 , V_187 ) ;
return F_96 ( V_118 ) ;
}
STATIC int
F_119 (
void * * V_188 ,
struct V_189 * V_190 ,
int * V_191 )
{
int error ;
struct V_192 * V_193 = * V_188 ;
T_9 V_194 = 0 ;
T_10 V_195 , V_196 , V_197 ;
if ( V_190 -> V_198 == - 1LL )
return 0 ;
V_195 = F_120 ( V_190 -> V_199 ) ;
V_196 = F_120 ( V_190 -> V_198 ) ;
V_197 = F_120 ( V_190 -> V_200 ) ;
if ( V_190 -> V_201 & V_202 )
V_194 |= V_203 ;
else if ( V_190 -> V_201 & V_204 ) {
V_194 |= ( V_205 |
V_206 ) ;
V_196 = 0 ;
}
if ( V_190 -> V_201 & V_207 )
V_194 |= V_208 ;
error = F_121 ( V_193 , V_195 , V_196 ,
V_197 , V_194 ) ;
if ( error > 0 ) {
error = 0 ;
* V_191 = 1 ;
}
return error ;
}
STATIC int
F_122 (
struct V_1 * V_1 ,
struct V_192 * V_193 ,
T_10 V_209 ,
T_10 V_197 )
{
T_11 * V_6 = F_2 ( V_1 ) ;
struct V_189 V_210 ;
int error ;
error = F_123 ( V_193 , V_211 ) ;
if ( error )
return error ;
V_210 . V_199 = F_124 ( V_209 ) ;
if ( V_197 == V_212 )
V_210 . V_200 = - 1LL ;
else
V_210 . V_200 = F_125 ( V_209 + V_197 ) - V_210 . V_199 ;
V_210 . V_213 = ! V_193 -> V_214 ? V_215 :
V_193 -> V_214 + 1 ;
V_210 . V_213 = F_126 ( V_216 , V_210 . V_213 ,
( V_217 * 16 / sizeof( struct V_189 ) ) ) ;
V_210 . V_218 = V_219 | V_220 ;
if ( V_193 -> V_221 & V_222 )
V_210 . V_218 |= V_223 ;
if ( ! ( V_193 -> V_221 & V_224 ) )
V_210 . V_218 |= V_225 ;
error = F_127 ( V_6 , & V_210 , F_119 , V_193 ) ;
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
T_12 V_32 = V_6 -> V_96 . V_226 ;
V_1 -> V_227 &= ~ ( V_228 | V_229 | V_230 |
V_231 | V_232 ) ;
if ( V_32 & V_233 )
V_1 -> V_227 |= V_228 ;
if ( V_32 & V_234 )
V_1 -> V_227 |= V_229 ;
if ( V_32 & V_235 )
V_1 -> V_227 |= V_230 ;
if ( V_32 & V_236 )
V_1 -> V_227 |= V_231 ;
if ( F_102 ( V_1 -> V_42 ) &&
V_6 -> V_77 -> V_44 . V_237 == V_217 &&
( V_6 -> V_77 -> V_129 & V_238 ||
V_6 -> V_96 . V_239 & V_240 ) )
V_1 -> V_227 |= V_232 ;
}
void
F_130 (
struct V_5 * V_6 )
{
struct V_1 * V_1 = & V_6 -> V_241 ;
T_13 V_242 ;
V_1 -> V_89 = V_6 -> V_89 ;
V_1 -> V_243 = V_244 ;
F_131 ( V_1 ) ;
F_132 ( & V_1 -> V_245 ) ;
V_1 -> V_85 = F_133 ( V_6 -> V_96 . V_150 ) ;
V_1 -> V_87 = F_134 ( V_6 -> V_96 . V_152 ) ;
switch ( V_1 -> V_42 & V_20 ) {
case V_99 :
case V_100 :
V_1 -> V_246 =
F_61 ( F_62 ( V_6 -> V_103 . V_104 . V_105 ) & 0x1ff ,
F_63 ( V_6 -> V_103 . V_104 . V_105 ) ) ;
break;
default:
V_1 -> V_246 = 0 ;
break;
}
F_135 ( V_1 , V_6 -> V_96 . V_171 ) ;
F_129 ( V_1 , V_6 ) ;
V_6 -> V_247 = V_6 -> V_77 -> V_248 ;
F_136 ( & V_6 -> V_249 . V_250 , & V_251 ) ;
switch ( V_1 -> V_42 & V_20 ) {
case V_252 :
V_1 -> V_253 = & V_254 ;
V_1 -> V_255 = & V_256 ;
V_1 -> V_172 -> V_257 = & V_258 ;
break;
case V_33 :
F_136 ( & V_6 -> V_249 . V_250 , & V_259 ) ;
if ( F_43 ( & F_44 ( V_1 -> V_43 ) -> V_44 ) )
V_1 -> V_253 = & V_260 ;
else
V_1 -> V_253 = & V_261 ;
V_1 -> V_255 = & V_262 ;
V_6 -> V_247 = V_6 -> V_77 -> V_263 ;
break;
case V_46 :
V_1 -> V_253 = & V_264 ;
if ( ! ( V_6 -> V_103 . V_265 & V_266 ) )
V_1 -> V_172 -> V_257 = & V_258 ;
break;
default:
V_1 -> V_253 = & V_254 ;
F_137 ( V_1 , V_1 -> V_42 , V_1 -> V_246 ) ;
break;
}
V_242 = F_138 ( V_1 -> V_172 ) ;
F_139 ( V_1 -> V_172 , ( V_242 & ~ ( V_267 ) ) ) ;
if ( ! F_140 ( V_6 ) ) {
F_141 ( V_1 ) ;
F_142 ( V_1 ) ;
}
}
