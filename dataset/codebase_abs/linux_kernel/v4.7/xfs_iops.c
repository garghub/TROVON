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
F_22 ( V_6 ) ;
if ( tmpfile )
F_23 ( V_15 , V_1 ) ;
else
F_24 ( V_15 , V_1 ) ;
F_25 ( V_6 ) ;
V_28:
if ( V_25 )
F_26 ( V_25 ) ;
if ( V_26 )
F_26 ( V_26 ) ;
return error ;
V_29:
F_25 ( V_6 ) ;
if ( ! tmpfile )
F_7 ( V_11 , V_1 , V_15 ) ;
F_27 ( V_1 ) ;
goto V_28;
}
STATIC int
F_28 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_16 ,
T_2 V_23 )
{
return F_9 ( V_11 , V_15 , V_16 , V_23 , false ) ;
}
STATIC int
F_29 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_16 ,
bool V_32 )
{
return F_28 ( V_11 , V_15 , V_16 , 0 ) ;
}
STATIC int
F_30 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_16 )
{
return F_28 ( V_11 , V_15 , V_16 | V_33 , 0 ) ;
}
STATIC struct V_15 *
F_31 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
unsigned int V_32 )
{
struct V_5 * V_34 ;
struct V_13 V_7 ;
int error ;
if ( V_15 -> V_17 . V_18 >= V_35 )
return F_32 ( - V_36 ) ;
F_6 ( & V_7 , V_15 , 0 ) ;
error = F_33 ( F_2 ( V_11 ) , & V_7 , & V_34 , NULL ) ;
if ( F_12 ( error ) ) {
if ( F_12 ( error != - V_37 ) )
return F_32 ( error ) ;
F_34 ( V_15 , NULL ) ;
return NULL ;
}
return F_35 ( F_19 ( V_34 ) , V_15 ) ;
}
STATIC struct V_15 *
F_36 (
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
return F_32 ( - V_36 ) ;
F_6 ( & V_38 , V_15 , 0 ) ;
error = F_33 ( F_2 ( V_11 ) , & V_38 , & V_6 , & V_39 ) ;
if ( F_12 ( error ) ) {
if ( F_12 ( error != - V_37 ) )
return F_32 ( error ) ;
return NULL ;
}
if ( ! V_39 . V_7 )
return F_35 ( F_19 ( V_6 ) , V_15 ) ;
V_40 . V_7 = V_39 . V_7 ;
V_40 . V_18 = V_39 . V_18 ;
V_15 = F_37 ( V_15 , F_19 ( V_6 ) , & V_40 ) ;
F_38 ( V_39 . V_7 ) ;
return V_15 ;
}
STATIC int
F_39 (
struct V_15 * V_41 ,
struct V_1 * V_11 ,
struct V_15 * V_15 )
{
struct V_1 * V_1 = F_40 ( V_41 ) ;
struct V_13 V_7 ;
int error ;
F_6 ( & V_7 , V_15 , V_1 -> V_42 ) ;
error = F_41 ( F_2 ( V_11 ) , F_2 ( V_1 ) , & V_7 ) ;
if ( F_12 ( error ) )
return error ;
F_42 ( V_1 ) ;
F_24 ( V_15 , V_1 ) ;
return 0 ;
}
STATIC int
F_43 (
struct V_1 * V_11 ,
struct V_15 * V_15 )
{
struct V_13 V_7 ;
int error ;
F_6 ( & V_7 , V_15 , 0 ) ;
error = F_8 ( F_2 ( V_11 ) , & V_7 , F_2 ( F_40 ( V_15 ) ) ) ;
if ( error )
return error ;
if ( F_44 ( & F_45 ( V_11 -> V_43 ) -> V_44 ) )
F_46 ( V_15 ) ;
return 0 ;
}
STATIC int
F_47 (
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
( V_47 ? 0777 & ~ F_48 () : V_48 ) ;
F_6 ( & V_7 , V_15 , V_16 ) ;
error = F_49 ( F_2 ( V_11 ) , & V_7 , V_45 , V_16 , & V_34 ) ;
if ( F_12 ( error ) )
goto V_49;
V_1 = F_19 ( V_34 ) ;
error = F_4 ( V_1 , V_11 , & V_15 -> V_17 ) ;
if ( F_12 ( error ) )
goto V_29;
F_22 ( V_34 ) ;
F_24 ( V_15 , V_1 ) ;
F_25 ( V_34 ) ;
return 0 ;
V_29:
F_25 ( V_34 ) ;
F_7 ( V_11 , V_1 , V_15 ) ;
F_27 ( V_1 ) ;
V_49:
return error ;
}
STATIC int
F_50 (
struct V_1 * V_50 ,
struct V_15 * V_51 ,
struct V_1 * V_52 ,
struct V_15 * V_53 ,
unsigned int V_32 )
{
struct V_1 * V_54 = F_40 ( V_53 ) ;
int V_55 = 0 ;
struct V_13 V_56 ;
struct V_13 V_57 ;
if ( V_32 & ~ ( V_58 | V_59 | V_60 ) )
return - V_27 ;
if ( V_32 & V_59 )
V_55 = F_40 ( V_53 ) -> V_42 ;
F_6 ( & V_56 , V_51 , V_55 ) ;
F_6 ( & V_57 , V_53 , F_40 ( V_51 ) -> V_42 ) ;
return F_51 ( F_2 ( V_50 ) , & V_56 , F_2 ( F_40 ( V_51 ) ) ,
F_2 ( V_52 ) , & V_57 ,
V_54 ? F_2 ( V_54 ) : NULL , V_32 ) ;
}
STATIC const char *
F_52 (
struct V_15 * V_15 ,
struct V_1 * V_1 ,
struct V_61 * V_62 )
{
char * V_63 ;
int error = - V_64 ;
if ( ! V_15 )
return F_32 ( - V_65 ) ;
V_63 = F_53 ( V_66 + 1 , V_67 ) ;
if ( ! V_63 )
goto V_68;
error = F_54 ( F_2 ( F_40 ( V_15 ) ) , V_63 ) ;
if ( F_12 ( error ) )
goto V_69;
F_55 ( V_62 , V_70 , V_63 ) ;
return V_63 ;
V_69:
F_56 ( V_63 ) ;
V_68:
return F_32 ( error ) ;
}
STATIC const char *
F_57 (
struct V_15 * V_15 ,
struct V_1 * V_1 ,
struct V_61 * V_62 )
{
ASSERT ( F_2 ( V_1 ) -> V_71 . V_72 & V_73 ) ;
return F_2 ( V_1 ) -> V_71 . V_74 . V_75 ;
}
STATIC int
F_58 (
struct V_76 * V_77 ,
struct V_15 * V_15 ,
struct V_78 * V_79 )
{
struct V_1 * V_1 = F_40 ( V_15 ) ;
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_80 * V_81 = V_6 -> V_82 ;
F_59 ( V_6 ) ;
if ( F_60 ( V_81 ) )
return - V_83 ;
V_79 -> V_84 = F_61 ( V_6 ) ;
V_79 -> V_85 = V_1 -> V_43 -> V_86 ;
V_79 -> V_16 = V_1 -> V_42 ;
V_79 -> V_87 = V_1 -> V_88 ;
V_79 -> V_89 = V_1 -> V_90 ;
V_79 -> V_91 = V_1 -> V_92 ;
V_79 -> V_93 = V_6 -> V_94 ;
V_79 -> V_95 = V_1 -> V_96 ;
V_79 -> V_97 = V_1 -> V_98 ;
V_79 -> ctime = V_1 -> V_99 ;
V_79 -> V_100 =
F_62 ( V_81 , V_6 -> V_101 . V_102 + V_6 -> V_103 ) ;
switch ( V_1 -> V_42 & V_20 ) {
case V_104 :
case V_105 :
V_79 -> V_106 = V_107 ;
V_79 -> V_23 = F_63 ( F_64 ( V_6 -> V_71 . V_108 . V_109 ) & 0x1ff ,
F_65 ( V_6 -> V_71 . V_108 . V_109 ) ) ;
break;
default:
if ( F_66 ( V_6 ) ) {
V_79 -> V_106 =
F_67 ( V_6 ) << V_81 -> V_44 . V_110 ;
} else
V_79 -> V_106 = F_68 ( V_81 ) ;
V_79 -> V_23 = 0 ;
break;
}
return 0 ;
}
static void
F_69 (
struct V_5 * V_6 ,
struct V_111 * V_111 )
{
struct V_1 * V_1 = F_19 ( V_6 ) ;
T_1 V_16 = V_111 -> V_112 ;
ASSERT ( F_70 ( V_6 , V_113 ) ) ;
V_1 -> V_42 &= V_20 ;
V_1 -> V_42 |= V_16 & ~ V_20 ;
}
void
F_71 (
struct V_5 * V_6 ,
struct V_111 * V_111 )
{
struct V_1 * V_1 = F_19 ( V_6 ) ;
ASSERT ( F_70 ( V_6 , V_113 ) ) ;
if ( V_111 -> V_114 & V_115 )
V_1 -> V_96 = V_111 -> V_116 ;
if ( V_111 -> V_114 & V_117 )
V_1 -> V_99 = V_111 -> V_118 ;
if ( V_111 -> V_114 & V_119 )
V_1 -> V_98 = V_111 -> V_120 ;
}
int
F_72 (
struct V_5 * V_6 ,
struct V_111 * V_111 ,
int V_32 )
{
T_3 * V_81 = V_6 -> V_82 ;
struct V_1 * V_1 = F_19 ( V_6 ) ;
int V_121 = V_111 -> V_114 ;
T_4 * V_122 ;
int error ;
T_5 V_89 = V_123 , V_124 = V_123 ;
T_6 V_91 = V_125 , V_126 = V_125 ;
struct V_127 * V_128 = NULL , * V_129 = NULL ;
struct V_127 * V_130 = NULL , * V_131 = NULL ;
F_73 ( V_6 ) ;
if ( ! ( V_32 & V_132 ) ) {
if ( V_81 -> V_133 & V_134 )
return - V_135 ;
if ( F_60 ( V_81 ) )
return - V_83 ;
error = F_74 ( V_1 , V_111 ) ;
if ( error )
return error ;
}
ASSERT ( ( V_121 & V_136 ) == 0 ) ;
if ( F_75 ( V_81 ) && ( V_121 & ( V_137 | V_138 ) ) ) {
T_7 V_139 = 0 ;
if ( ( V_121 & V_137 ) && F_76 ( V_81 ) ) {
V_89 = V_111 -> V_140 ;
V_139 |= V_141 ;
} else {
V_89 = V_1 -> V_90 ;
}
if ( ( V_121 & V_138 ) && F_77 ( V_81 ) ) {
V_91 = V_111 -> V_142 ;
V_139 |= V_143 ;
} else {
V_91 = V_1 -> V_92 ;
}
ASSERT ( V_128 == NULL ) ;
ASSERT ( V_129 == NULL ) ;
error = F_78 ( V_6 , F_79 ( V_89 ) ,
F_80 ( V_91 ) ,
F_81 ( V_6 ) ,
V_139 , & V_128 , & V_129 , NULL ) ;
if ( error )
return error ;
}
error = F_82 ( V_81 , & F_83 ( V_81 ) -> V_144 , 0 , 0 , 0 , & V_122 ) ;
if ( error )
goto V_145;
F_84 ( V_6 , V_113 ) ;
F_85 ( V_122 , V_6 , 0 ) ;
if ( V_121 & ( V_137 | V_138 ) ) {
V_124 = V_1 -> V_90 ;
V_126 = V_1 -> V_92 ;
V_91 = ( V_121 & V_138 ) ? V_111 -> V_142 : V_126 ;
V_89 = ( V_121 & V_137 ) ? V_111 -> V_140 : V_124 ;
if ( F_86 ( V_81 ) &&
( ( F_76 ( V_81 ) && ! F_87 ( V_124 , V_89 ) ) ||
( F_77 ( V_81 ) && ! F_88 ( V_126 , V_91 ) ) ) ) {
ASSERT ( V_122 ) ;
error = F_89 ( V_122 , V_6 , V_128 , V_129 ,
NULL , F_90 ( V_146 ) ?
V_147 : 0 ) ;
if ( error )
goto V_148;
}
}
if ( V_121 & ( V_137 | V_138 ) ) {
if ( ( V_1 -> V_42 & ( V_149 | V_150 ) ) &&
! F_90 ( V_151 ) )
V_1 -> V_42 &= ~ ( V_149 | V_150 ) ;
if ( ! F_87 ( V_124 , V_89 ) ) {
if ( F_86 ( V_81 ) && F_76 ( V_81 ) ) {
ASSERT ( V_121 & V_137 ) ;
ASSERT ( V_128 ) ;
V_130 = F_91 ( V_122 , V_6 ,
& V_6 -> V_152 , V_128 ) ;
}
V_6 -> V_101 . V_153 = F_79 ( V_89 ) ;
V_1 -> V_90 = V_89 ;
}
if ( ! F_88 ( V_126 , V_91 ) ) {
if ( F_86 ( V_81 ) && F_77 ( V_81 ) ) {
ASSERT ( F_92 ( & V_81 -> V_44 ) ||
! F_93 ( V_81 ) ) ;
ASSERT ( V_121 & V_138 ) ;
ASSERT ( V_129 ) ;
V_131 = F_91 ( V_122 , V_6 ,
& V_6 -> V_154 , V_129 ) ;
}
V_6 -> V_101 . V_155 = F_80 ( V_91 ) ;
V_1 -> V_92 = V_91 ;
}
}
if ( V_121 & V_156 )
F_69 ( V_6 , V_111 ) ;
if ( V_121 & ( V_115 | V_117 | V_119 ) )
F_71 ( V_6 , V_111 ) ;
F_94 ( V_122 , V_6 , V_157 ) ;
F_95 ( V_81 , V_158 ) ;
if ( V_81 -> V_133 & V_159 )
F_96 ( V_122 ) ;
error = F_97 ( V_122 ) ;
F_98 ( V_6 , V_113 ) ;
F_99 ( V_130 ) ;
F_99 ( V_131 ) ;
F_99 ( V_128 ) ;
F_99 ( V_129 ) ;
if ( error )
return error ;
if ( ( V_121 & V_156 ) && ! ( V_32 & V_132 ) ) {
error = F_100 ( V_1 , V_1 -> V_42 ) ;
if ( error )
return error ;
}
return 0 ;
V_148:
F_101 ( V_122 ) ;
V_145:
F_99 ( V_128 ) ;
F_99 ( V_129 ) ;
return error ;
}
int
F_102 (
struct V_5 * V_6 ,
struct V_111 * V_111 )
{
struct V_80 * V_81 = V_6 -> V_82 ;
struct V_1 * V_1 = F_19 ( V_6 ) ;
T_8 V_160 , V_161 ;
struct V_162 * V_122 ;
int error ;
T_7 V_163 = 0 ;
bool V_164 = false ;
F_73 ( V_6 ) ;
if ( V_81 -> V_133 & V_134 )
return - V_135 ;
if ( F_60 ( V_81 ) )
return - V_83 ;
error = F_74 ( V_1 , V_111 ) ;
if ( error )
return error ;
ASSERT ( F_70 ( V_6 , V_165 ) ) ;
ASSERT ( F_70 ( V_6 , V_166 ) ) ;
ASSERT ( F_103 ( V_1 -> V_42 ) ) ;
ASSERT ( ( V_111 -> V_114 & ( V_137 | V_138 | V_115 | V_167 |
V_168 | V_169 | V_170 ) ) == 0 ) ;
V_160 = V_1 -> V_171 ;
V_161 = V_111 -> V_172 ;
if ( V_161 == 0 && V_160 == 0 && V_6 -> V_101 . V_173 == 0 ) {
if ( ! ( V_111 -> V_114 & ( V_117 | V_119 ) ) )
return 0 ;
V_111 -> V_114 &= ~ V_136 ;
return F_72 ( V_6 , V_111 , 0 ) ;
}
error = F_104 ( V_6 , 0 ) ;
if ( error )
return error ;
if ( V_161 > V_160 ) {
error = F_105 ( V_6 , V_161 , V_160 , & V_164 ) ;
if ( error )
return error ;
}
if ( V_161 > V_6 -> V_101 . V_174 &&
( V_160 != V_6 -> V_101 . V_174 || V_164 ) ) {
error = F_106 ( F_19 ( V_6 ) -> V_175 ,
V_6 -> V_101 . V_174 , V_161 ) ;
if ( error )
return error ;
}
F_107 ( V_1 ) ;
if ( F_108 ( V_1 ) )
error = F_109 ( V_1 , V_161 , V_176 ) ;
else
error = F_110 ( V_1 -> V_175 , V_161 ,
V_177 ) ;
if ( error )
return error ;
F_111 ( V_1 , V_161 ) ;
error = F_82 ( V_81 , & F_83 ( V_81 ) -> V_178 , 0 , 0 , 0 , & V_122 ) ;
if ( error )
return error ;
V_163 |= V_113 ;
F_84 ( V_6 , V_113 ) ;
F_85 ( V_122 , V_6 , 0 ) ;
if ( V_161 != V_160 &&
! ( V_111 -> V_114 & ( V_117 | V_119 ) ) ) {
V_111 -> V_118 = V_111 -> V_120 =
F_112 ( V_1 -> V_43 ) ;
V_111 -> V_114 |= V_117 | V_119 ;
}
V_6 -> V_101 . V_174 = V_161 ;
F_94 ( V_122 , V_6 , V_157 ) ;
if ( V_161 <= V_160 ) {
error = F_113 ( & V_122 , V_6 , V_179 , V_161 ) ;
if ( error )
goto V_180;
F_114 ( V_6 , V_181 ) ;
F_115 ( V_6 ) ;
}
if ( V_111 -> V_114 & V_156 )
F_69 ( V_6 , V_111 ) ;
if ( V_111 -> V_114 & ( V_115 | V_117 | V_119 ) )
F_71 ( V_6 , V_111 ) ;
F_94 ( V_122 , V_6 , V_157 ) ;
F_95 ( V_81 , V_158 ) ;
if ( V_81 -> V_133 & V_159 )
F_96 ( V_122 ) ;
error = F_97 ( V_122 ) ;
V_182:
if ( V_163 )
F_98 ( V_6 , V_163 ) ;
return error ;
V_180:
F_101 ( V_122 ) ;
goto V_182;
}
STATIC int
F_116 (
struct V_15 * V_15 ,
struct V_111 * V_111 )
{
struct V_5 * V_6 = F_2 ( F_40 ( V_15 ) ) ;
int error ;
if ( V_111 -> V_114 & V_136 ) {
T_7 V_183 = V_165 ;
F_84 ( V_6 , V_183 ) ;
error = F_117 ( F_40 ( V_15 ) , & V_183 , true ) ;
if ( ! error ) {
F_84 ( V_6 , V_166 ) ;
V_183 |= V_166 ;
error = F_102 ( V_6 , V_111 ) ;
}
F_98 ( V_6 , V_183 ) ;
} else {
error = F_72 ( V_6 , V_111 , 0 ) ;
}
return error ;
}
STATIC int
F_118 (
struct V_1 * V_1 ,
struct V_184 * V_185 ,
int V_32 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_80 * V_81 = V_6 -> V_82 ;
struct V_162 * V_122 ;
int error ;
F_119 ( V_6 ) ;
error = F_82 ( V_81 , & F_83 ( V_81 ) -> V_186 , 0 , 0 , 0 , & V_122 ) ;
if ( error )
return error ;
F_84 ( V_6 , V_113 ) ;
if ( V_32 & V_187 )
V_1 -> V_99 = * V_185 ;
if ( V_32 & V_188 )
V_1 -> V_98 = * V_185 ;
if ( V_32 & V_189 )
V_1 -> V_96 = * V_185 ;
F_85 ( V_122 , V_6 , V_113 ) ;
F_94 ( V_122 , V_6 , V_190 ) ;
return F_97 ( V_122 ) ;
}
STATIC int
F_120 (
void * * V_191 ,
struct V_192 * V_193 ,
int * V_194 )
{
int error ;
struct V_195 * V_196 = * V_191 ;
T_9 V_197 = 0 ;
T_10 V_198 , V_199 , V_200 ;
if ( V_193 -> V_201 == - 1LL )
return 0 ;
V_198 = F_121 ( V_193 -> V_202 ) ;
V_199 = F_121 ( V_193 -> V_201 ) ;
V_200 = F_121 ( V_193 -> V_203 ) ;
if ( V_193 -> V_204 & V_205 )
V_197 |= V_206 ;
else if ( V_193 -> V_204 & V_207 ) {
V_197 |= ( V_208 |
V_209 ) ;
V_199 = 0 ;
}
if ( V_193 -> V_204 & V_210 )
V_197 |= V_211 ;
error = F_122 ( V_196 , V_198 , V_199 ,
V_200 , V_197 ) ;
if ( error > 0 ) {
error = 0 ;
* V_194 = 1 ;
}
return error ;
}
STATIC int
F_123 (
struct V_1 * V_1 ,
struct V_195 * V_196 ,
T_10 V_212 ,
T_10 V_200 )
{
T_11 * V_6 = F_2 ( V_1 ) ;
struct V_192 V_213 ;
int error ;
error = F_124 ( V_196 , V_214 ) ;
if ( error )
return error ;
V_213 . V_202 = F_125 ( V_212 ) ;
if ( V_200 == V_215 )
V_213 . V_203 = - 1LL ;
else
V_213 . V_203 = F_126 ( V_212 + V_200 ) - V_213 . V_202 ;
V_213 . V_216 = ! V_196 -> V_217 ? V_218 :
V_196 -> V_217 + 1 ;
V_213 . V_216 = F_127 ( V_219 , V_213 . V_216 ,
( V_220 * 16 / sizeof( struct V_192 ) ) ) ;
V_213 . V_221 = V_222 | V_223 ;
if ( V_196 -> V_224 & V_225 )
V_213 . V_221 |= V_226 ;
if ( ! ( V_196 -> V_224 & V_227 ) )
V_213 . V_221 |= V_228 ;
error = F_128 ( V_6 , & V_213 , F_120 , V_196 ) ;
if ( error )
return error ;
return 0 ;
}
STATIC int
F_129 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_16 )
{
return F_9 ( V_11 , V_15 , V_16 , 0 , true ) ;
}
STATIC void
F_130 (
struct V_1 * V_1 ,
struct V_5 * V_6 )
{
T_12 V_32 = V_6 -> V_101 . V_229 ;
V_1 -> V_230 &= ~ ( V_231 | V_232 | V_233 |
V_234 | V_235 ) ;
if ( V_32 & V_236 )
V_1 -> V_230 |= V_231 ;
if ( V_32 & V_237 )
V_1 -> V_230 |= V_232 ;
if ( V_32 & V_238 )
V_1 -> V_230 |= V_233 ;
if ( V_32 & V_239 )
V_1 -> V_230 |= V_234 ;
if ( F_103 ( V_1 -> V_42 ) &&
V_6 -> V_82 -> V_44 . V_240 == V_220 &&
( V_6 -> V_82 -> V_133 & V_241 ||
V_6 -> V_101 . V_242 & V_243 ) )
V_1 -> V_230 |= V_235 ;
}
void
F_131 (
struct V_5 * V_6 )
{
struct V_1 * V_1 = & V_6 -> V_244 ;
T_13 V_245 ;
V_1 -> V_94 = V_6 -> V_94 ;
V_1 -> V_246 = V_247 ;
F_132 ( V_1 ) ;
F_133 ( & V_1 -> V_248 ) ;
V_1 -> V_90 = F_134 ( V_6 -> V_101 . V_153 ) ;
V_1 -> V_92 = F_135 ( V_6 -> V_101 . V_155 ) ;
switch ( V_1 -> V_42 & V_20 ) {
case V_104 :
case V_105 :
V_1 -> V_249 =
F_63 ( F_64 ( V_6 -> V_71 . V_108 . V_109 ) & 0x1ff ,
F_65 ( V_6 -> V_71 . V_108 . V_109 ) ) ;
break;
default:
V_1 -> V_249 = 0 ;
break;
}
F_136 ( V_1 , V_6 -> V_101 . V_174 ) ;
F_130 ( V_1 , V_6 ) ;
if ( F_137 ( V_1 -> V_42 ) ) {
F_138 ( & V_6 -> V_250 . V_251 , & V_252 ) ;
V_6 -> V_253 = V_6 -> V_82 -> V_254 ;
} else {
V_6 -> V_253 = V_6 -> V_82 -> V_255 ;
F_138 ( & V_6 -> V_250 . V_251 , & V_256 ) ;
}
V_245 = F_139 ( V_1 -> V_175 ) ;
F_140 ( V_1 -> V_175 , ( V_245 & ~ ( V_257 ) ) ) ;
if ( ! F_141 ( V_6 ) ) {
F_142 ( V_1 ) ;
F_143 ( V_1 ) ;
}
}
void
F_22 (
struct V_5 * V_6 )
{
struct V_1 * V_1 = & V_6 -> V_244 ;
switch ( V_1 -> V_42 & V_20 ) {
case V_258 :
V_1 -> V_259 = & V_260 ;
V_1 -> V_261 = & V_262 ;
V_1 -> V_175 -> V_263 = & V_264 ;
break;
case V_33 :
if ( F_44 ( & F_45 ( V_1 -> V_43 ) -> V_44 ) )
V_1 -> V_259 = & V_265 ;
else
V_1 -> V_259 = & V_266 ;
V_1 -> V_261 = & V_267 ;
break;
case V_46 :
if ( V_6 -> V_71 . V_72 & V_73 )
V_1 -> V_259 = & V_268 ;
else
V_1 -> V_259 = & V_269 ;
break;
default:
V_1 -> V_259 = & V_260 ;
F_144 ( V_1 , V_1 -> V_42 , V_1 -> V_249 ) ;
break;
}
}
