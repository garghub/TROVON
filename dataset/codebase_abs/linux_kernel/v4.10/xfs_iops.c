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
struct V_75 * V_76 ,
struct V_15 * V_15 ,
struct V_77 * V_78 )
{
struct V_1 * V_1 = F_42 ( V_15 ) ;
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_79 * V_80 = V_6 -> V_81 ;
F_61 ( V_6 ) ;
if ( F_62 ( V_80 ) )
return - V_82 ;
V_78 -> V_83 = F_63 ( V_6 ) ;
V_78 -> V_84 = V_1 -> V_42 -> V_85 ;
V_78 -> V_19 = V_1 -> V_41 ;
V_78 -> V_86 = V_1 -> V_87 ;
V_78 -> V_88 = V_1 -> V_89 ;
V_78 -> V_90 = V_1 -> V_91 ;
V_78 -> V_92 = V_6 -> V_93 ;
V_78 -> V_94 = V_1 -> V_95 ;
V_78 -> V_96 = V_1 -> V_97 ;
V_78 -> ctime = V_1 -> V_98 ;
V_78 -> V_99 =
F_64 ( V_80 , V_6 -> V_100 . V_101 + V_6 -> V_102 ) ;
switch ( V_1 -> V_41 & V_103 ) {
case V_104 :
case V_105 :
V_78 -> V_106 = V_107 ;
V_78 -> V_22 = F_65 ( F_66 ( V_6 -> V_70 . V_108 . V_109 ) & 0x1ff ,
F_67 ( V_6 -> V_70 . V_108 . V_109 ) ) ;
break;
default:
if ( F_68 ( V_6 ) ) {
V_78 -> V_106 =
F_69 ( V_6 ) << V_80 -> V_43 . V_110 ;
} else
V_78 -> V_106 = F_70 ( V_80 ) ;
V_78 -> V_22 = 0 ;
break;
}
return 0 ;
}
static void
F_71 (
struct V_5 * V_6 ,
struct V_111 * V_111 )
{
struct V_1 * V_1 = F_21 ( V_6 ) ;
T_1 V_19 = V_111 -> V_112 ;
ASSERT ( F_72 ( V_6 , V_113 ) ) ;
V_1 -> V_41 &= V_103 ;
V_1 -> V_41 |= V_19 & ~ V_103 ;
}
void
F_73 (
struct V_5 * V_6 ,
struct V_111 * V_111 )
{
struct V_1 * V_1 = F_21 ( V_6 ) ;
ASSERT ( F_72 ( V_6 , V_113 ) ) ;
if ( V_111 -> V_114 & V_115 )
V_1 -> V_95 = V_111 -> V_116 ;
if ( V_111 -> V_114 & V_117 )
V_1 -> V_98 = V_111 -> V_118 ;
if ( V_111 -> V_114 & V_119 )
V_1 -> V_97 = V_111 -> V_120 ;
}
static int
F_74 (
struct V_15 * V_15 ,
struct V_111 * V_111 )
{
struct V_79 * V_80 = F_2 ( F_42 ( V_15 ) ) -> V_81 ;
if ( V_80 -> V_121 & V_122 )
return - V_123 ;
if ( F_62 ( V_80 ) )
return - V_82 ;
return F_75 ( V_15 , V_111 ) ;
}
int
F_76 (
struct V_5 * V_6 ,
struct V_111 * V_111 ,
int V_31 )
{
T_3 * V_80 = V_6 -> V_81 ;
struct V_1 * V_1 = F_21 ( V_6 ) ;
int V_124 = V_111 -> V_114 ;
T_4 * V_125 ;
int error ;
T_5 V_88 = V_126 , V_127 = V_126 ;
T_6 V_90 = V_128 , V_129 = V_128 ;
struct V_130 * V_131 = NULL , * V_132 = NULL ;
struct V_130 * V_133 = NULL , * V_134 = NULL ;
ASSERT ( ( V_124 & V_135 ) == 0 ) ;
if ( F_77 ( V_80 ) && ( V_124 & ( V_136 | V_137 ) ) ) {
T_7 V_138 = 0 ;
if ( ( V_124 & V_136 ) && F_78 ( V_80 ) ) {
V_88 = V_111 -> V_139 ;
V_138 |= V_140 ;
} else {
V_88 = V_1 -> V_89 ;
}
if ( ( V_124 & V_137 ) && F_79 ( V_80 ) ) {
V_90 = V_111 -> V_141 ;
V_138 |= V_142 ;
} else {
V_90 = V_1 -> V_91 ;
}
ASSERT ( V_131 == NULL ) ;
ASSERT ( V_132 == NULL ) ;
error = F_80 ( V_6 , F_81 ( V_88 ) ,
F_82 ( V_90 ) ,
F_83 ( V_6 ) ,
V_138 , & V_131 , & V_132 , NULL ) ;
if ( error )
return error ;
}
error = F_84 ( V_80 , & F_85 ( V_80 ) -> V_143 , 0 , 0 , 0 , & V_125 ) ;
if ( error )
goto V_144;
F_86 ( V_6 , V_113 ) ;
F_87 ( V_125 , V_6 , 0 ) ;
if ( V_124 & ( V_136 | V_137 ) ) {
V_127 = V_1 -> V_89 ;
V_129 = V_1 -> V_91 ;
V_90 = ( V_124 & V_137 ) ? V_111 -> V_141 : V_129 ;
V_88 = ( V_124 & V_136 ) ? V_111 -> V_139 : V_127 ;
if ( F_88 ( V_80 ) &&
( ( F_78 ( V_80 ) && ! F_89 ( V_127 , V_88 ) ) ||
( F_79 ( V_80 ) && ! F_90 ( V_129 , V_90 ) ) ) ) {
ASSERT ( V_125 ) ;
error = F_91 ( V_125 , V_6 , V_131 , V_132 ,
NULL , F_92 ( V_145 ) ?
V_146 : 0 ) ;
if ( error )
goto V_147;
}
}
if ( V_124 & ( V_136 | V_137 ) ) {
if ( ( V_1 -> V_41 & ( V_148 | V_149 ) ) &&
! F_92 ( V_150 ) )
V_1 -> V_41 &= ~ ( V_148 | V_149 ) ;
if ( ! F_89 ( V_127 , V_88 ) ) {
if ( F_88 ( V_80 ) && F_78 ( V_80 ) ) {
ASSERT ( V_124 & V_136 ) ;
ASSERT ( V_131 ) ;
V_133 = F_93 ( V_125 , V_6 ,
& V_6 -> V_151 , V_131 ) ;
}
V_6 -> V_100 . V_152 = F_81 ( V_88 ) ;
V_1 -> V_89 = V_88 ;
}
if ( ! F_90 ( V_129 , V_90 ) ) {
if ( F_88 ( V_80 ) && F_79 ( V_80 ) ) {
ASSERT ( F_94 ( & V_80 -> V_43 ) ||
! F_95 ( V_80 ) ) ;
ASSERT ( V_124 & V_137 ) ;
ASSERT ( V_132 ) ;
V_134 = F_93 ( V_125 , V_6 ,
& V_6 -> V_153 , V_132 ) ;
}
V_6 -> V_100 . V_154 = F_82 ( V_90 ) ;
V_1 -> V_91 = V_90 ;
}
}
if ( V_124 & V_155 )
F_71 ( V_6 , V_111 ) ;
if ( V_124 & ( V_115 | V_117 | V_119 ) )
F_73 ( V_6 , V_111 ) ;
F_96 ( V_125 , V_6 , V_156 ) ;
F_97 ( V_80 , V_157 ) ;
if ( V_80 -> V_121 & V_158 )
F_98 ( V_125 ) ;
error = F_99 ( V_125 ) ;
F_100 ( V_6 , V_113 ) ;
F_101 ( V_133 ) ;
F_101 ( V_134 ) ;
F_101 ( V_131 ) ;
F_101 ( V_132 ) ;
if ( error )
return error ;
if ( ( V_124 & V_155 ) && ! ( V_31 & V_159 ) ) {
error = F_102 ( V_1 , V_1 -> V_41 ) ;
if ( error )
return error ;
}
return 0 ;
V_147:
F_103 ( V_125 ) ;
V_144:
F_101 ( V_131 ) ;
F_101 ( V_132 ) ;
return error ;
}
int
F_104 (
struct V_15 * V_15 ,
struct V_111 * V_111 )
{
struct V_5 * V_6 = F_2 ( F_42 ( V_15 ) ) ;
int error ;
F_105 ( V_6 ) ;
error = F_74 ( V_15 , V_111 ) ;
if ( error )
return error ;
return F_76 ( V_6 , V_111 , 0 ) ;
}
int
F_106 (
struct V_5 * V_6 ,
struct V_111 * V_111 )
{
struct V_79 * V_80 = V_6 -> V_81 ;
struct V_1 * V_1 = F_21 ( V_6 ) ;
T_8 V_160 , V_161 ;
struct V_162 * V_125 ;
int error ;
T_7 V_163 = 0 ;
bool V_164 = false ;
ASSERT ( F_72 ( V_6 , V_165 ) ) ;
ASSERT ( F_72 ( V_6 , V_166 ) ) ;
ASSERT ( F_107 ( V_1 -> V_41 ) ) ;
ASSERT ( ( V_111 -> V_114 & ( V_136 | V_137 | V_115 | V_167 |
V_168 | V_169 | V_170 ) ) == 0 ) ;
V_160 = V_1 -> V_171 ;
V_161 = V_111 -> V_172 ;
if ( V_161 == 0 && V_160 == 0 && V_6 -> V_100 . V_173 == 0 ) {
if ( ! ( V_111 -> V_114 & ( V_117 | V_119 ) ) )
return 0 ;
V_111 -> V_114 &= ~ V_135 ;
return F_76 ( V_6 , V_111 , 0 ) ;
}
error = F_108 ( V_6 , 0 ) ;
if ( error )
return error ;
F_109 ( V_1 ) ;
if ( V_161 > V_160 ) {
error = F_110 ( V_6 , V_161 , V_160 , & V_164 ) ;
} else {
error = F_111 ( V_1 , V_161 , & V_164 ,
& V_174 ) ;
}
if ( error )
return error ;
if ( V_164 ||
( V_161 > V_6 -> V_100 . V_175 && V_160 != V_6 -> V_100 . V_175 ) ) {
error = F_112 ( F_21 ( V_6 ) -> V_176 ,
V_6 -> V_100 . V_175 , V_161 ) ;
if ( error )
return error ;
}
F_113 ( V_1 , V_161 ) ;
error = F_84 ( V_80 , & F_85 ( V_80 ) -> V_177 , 0 , 0 , 0 , & V_125 ) ;
if ( error )
return error ;
V_163 |= V_113 ;
F_86 ( V_6 , V_113 ) ;
F_87 ( V_125 , V_6 , 0 ) ;
if ( V_161 != V_160 &&
! ( V_111 -> V_114 & ( V_117 | V_119 ) ) ) {
V_111 -> V_118 = V_111 -> V_120 =
F_114 ( V_1 ) ;
V_111 -> V_114 |= V_117 | V_119 ;
}
V_6 -> V_100 . V_175 = V_161 ;
F_96 ( V_125 , V_6 , V_156 ) ;
if ( V_161 <= V_160 ) {
error = F_115 ( & V_125 , V_6 , V_178 , V_161 ) ;
if ( error )
goto V_179;
F_116 ( V_6 , V_180 ) ;
F_117 ( V_6 ) ;
}
if ( V_111 -> V_114 & V_155 )
F_71 ( V_6 , V_111 ) ;
if ( V_111 -> V_114 & ( V_115 | V_117 | V_119 ) )
F_73 ( V_6 , V_111 ) ;
F_96 ( V_125 , V_6 , V_156 ) ;
F_97 ( V_80 , V_157 ) ;
if ( V_80 -> V_121 & V_158 )
F_98 ( V_125 ) ;
error = F_99 ( V_125 ) ;
V_181:
if ( V_163 )
F_100 ( V_6 , V_163 ) ;
return error ;
V_179:
F_103 ( V_125 ) ;
goto V_181;
}
int
F_118 (
struct V_15 * V_15 ,
struct V_111 * V_111 )
{
struct V_5 * V_6 = F_2 ( F_42 ( V_15 ) ) ;
int error ;
F_105 ( V_6 ) ;
error = F_74 ( V_15 , V_111 ) ;
if ( error )
return error ;
return F_106 ( V_6 , V_111 ) ;
}
STATIC int
F_119 (
struct V_15 * V_15 ,
struct V_111 * V_111 )
{
int error ;
if ( V_111 -> V_114 & V_135 ) {
struct V_5 * V_6 = F_2 ( F_42 ( V_15 ) ) ;
T_7 V_182 = V_165 ;
error = F_120 ( F_42 ( V_15 ) , & V_182 ) ;
if ( error )
return error ;
F_86 ( V_6 , V_166 ) ;
error = F_118 ( V_15 , V_111 ) ;
F_100 ( V_6 , V_166 ) ;
} else {
error = F_104 ( V_15 , V_111 ) ;
}
return error ;
}
STATIC int
F_121 (
struct V_1 * V_1 ,
struct V_183 * V_184 ,
int V_31 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_79 * V_80 = V_6 -> V_81 ;
struct V_162 * V_125 ;
int error ;
F_122 ( V_6 ) ;
error = F_84 ( V_80 , & F_85 ( V_80 ) -> V_185 , 0 , 0 , 0 , & V_125 ) ;
if ( error )
return error ;
F_86 ( V_6 , V_113 ) ;
if ( V_31 & V_186 )
V_1 -> V_98 = * V_184 ;
if ( V_31 & V_187 )
V_1 -> V_97 = * V_184 ;
if ( V_31 & V_188 )
V_1 -> V_95 = * V_184 ;
F_87 ( V_125 , V_6 , V_113 ) ;
F_96 ( V_125 , V_6 , V_189 ) ;
return F_99 ( V_125 ) ;
}
STATIC int
F_123 (
struct V_1 * V_1 ,
struct V_190 * V_191 ,
T_9 V_192 ,
T_9 V_193 )
{
int error ;
F_86 ( F_2 ( V_1 ) , V_194 ) ;
if ( V_191 -> V_195 & V_196 ) {
V_191 -> V_195 &= ~ V_196 ;
error = F_124 ( V_1 , V_191 , V_192 , V_193 ,
& V_197 ) ;
} else {
error = F_124 ( V_1 , V_191 , V_192 , V_193 ,
& V_174 ) ;
}
F_100 ( F_2 ( V_1 ) , V_194 ) ;
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
T_10 V_31 = V_6 -> V_100 . V_198 ;
V_1 -> V_199 &= ~ ( V_200 | V_201 | V_202 |
V_203 | V_204 ) ;
if ( V_31 & V_205 )
V_1 -> V_199 |= V_200 ;
if ( V_31 & V_206 )
V_1 -> V_199 |= V_201 ;
if ( V_31 & V_207 )
V_1 -> V_199 |= V_202 ;
if ( V_31 & V_208 )
V_1 -> V_199 |= V_203 ;
if ( F_107 ( V_1 -> V_41 ) &&
V_6 -> V_81 -> V_43 . V_209 == V_210 &&
! F_127 ( V_6 ) &&
( V_6 -> V_81 -> V_121 & V_211 ||
V_6 -> V_100 . V_212 & V_213 ) )
V_1 -> V_199 |= V_204 ;
}
void
F_128 (
struct V_5 * V_6 )
{
struct V_1 * V_1 = & V_6 -> V_214 ;
T_11 V_215 ;
V_1 -> V_93 = V_6 -> V_93 ;
V_1 -> V_216 = V_217 ;
F_129 ( V_1 ) ;
F_130 ( & V_1 -> V_218 ) ;
V_1 -> V_89 = F_131 ( V_6 -> V_100 . V_152 ) ;
V_1 -> V_91 = F_132 ( V_6 -> V_100 . V_154 ) ;
switch ( V_1 -> V_41 & V_103 ) {
case V_104 :
case V_105 :
V_1 -> V_219 =
F_65 ( F_66 ( V_6 -> V_70 . V_108 . V_109 ) & 0x1ff ,
F_67 ( V_6 -> V_70 . V_108 . V_109 ) ) ;
break;
default:
V_1 -> V_219 = 0 ;
break;
}
F_133 ( V_1 , V_6 -> V_100 . V_175 ) ;
F_126 ( V_1 , V_6 ) ;
if ( F_134 ( V_1 -> V_41 ) ) {
F_135 ( & V_6 -> V_220 . V_221 , & V_222 ) ;
V_6 -> V_223 = V_6 -> V_81 -> V_224 ;
} else {
V_6 -> V_223 = V_6 -> V_81 -> V_225 ;
F_135 ( & V_6 -> V_220 . V_221 , & V_226 ) ;
}
V_215 = F_136 ( V_1 -> V_176 ) ;
F_137 ( V_1 -> V_176 , ( V_215 & ~ ( V_227 ) ) ) ;
if ( ! F_138 ( V_6 ) ) {
F_139 ( V_1 ) ;
F_140 ( V_1 ) ;
}
}
void
F_24 (
struct V_5 * V_6 )
{
struct V_1 * V_1 = & V_6 -> V_214 ;
switch ( V_1 -> V_41 & V_103 ) {
case V_228 :
V_1 -> V_229 = & V_230 ;
V_1 -> V_231 = & V_232 ;
V_1 -> V_176 -> V_233 = & V_234 ;
break;
case V_32 :
if ( F_46 ( & F_47 ( V_1 -> V_42 ) -> V_43 ) )
V_1 -> V_229 = & V_235 ;
else
V_1 -> V_229 = & V_236 ;
V_1 -> V_231 = & V_237 ;
break;
case V_45 :
if ( V_6 -> V_70 . V_71 & V_72 )
V_1 -> V_229 = & V_238 ;
else
V_1 -> V_229 = & V_239 ;
break;
default:
V_1 -> V_229 = & V_230 ;
F_141 ( V_1 , V_1 -> V_41 , V_1 -> V_219 ) ;
break;
}
}
