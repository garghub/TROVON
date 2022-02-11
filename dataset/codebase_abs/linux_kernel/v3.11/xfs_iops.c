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
}
STATIC void
F_7 (
struct V_1 * V_11 ,
struct V_1 * V_1 ,
struct V_15 * V_15 )
{
struct V_13 V_18 ;
F_6 ( & V_18 , V_15 ) ;
F_8 ( F_2 ( V_11 ) , & V_18 , F_2 ( V_1 ) ) ;
F_9 ( V_1 ) ;
}
STATIC int
F_10 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_19 ,
T_2 V_20 )
{
struct V_1 * V_1 ;
struct V_5 * V_6 = NULL ;
struct V_21 * V_22 = NULL ;
struct V_13 V_7 ;
int error ;
if ( F_11 ( V_19 ) || F_12 ( V_19 ) ) {
if ( F_13 ( ! F_14 ( V_20 ) || F_15 ( V_20 ) & ~ 0x1ff ) )
return - V_23 ;
V_20 = F_16 ( V_20 ) ;
} else {
V_20 = 0 ;
}
if ( F_17 ( V_11 ) ) {
V_22 = F_18 ( V_11 , V_24 ) ;
if ( F_19 ( V_22 ) )
return F_20 ( V_22 ) ;
if ( ! V_22 )
V_19 &= ~ F_21 () ;
}
F_6 ( & V_7 , V_15 ) ;
error = F_22 ( F_2 ( V_11 ) , & V_7 , V_19 , V_20 , & V_6 ) ;
if ( F_13 ( error ) )
goto V_25;
V_1 = F_23 ( V_6 ) ;
error = F_4 ( V_1 , V_11 , & V_15 -> V_16 ) ;
if ( F_13 ( error ) )
goto V_26;
if ( V_22 ) {
error = - F_24 ( V_1 , V_22 ) ;
V_22 = NULL ;
if ( F_13 ( error ) )
goto V_26;
}
F_25 ( V_15 , V_1 ) ;
return - error ;
V_26:
F_7 ( V_11 , V_1 , V_15 ) ;
V_25:
F_26 ( V_22 ) ;
return - error ;
}
STATIC int
F_27 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_19 ,
bool V_27 )
{
return F_10 ( V_11 , V_15 , V_19 , 0 ) ;
}
STATIC int
F_28 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_19 )
{
return F_10 ( V_11 , V_15 , V_19 | V_28 , 0 ) ;
}
STATIC struct V_15 *
F_29 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
unsigned int V_27 )
{
struct V_5 * V_29 ;
struct V_13 V_7 ;
int error ;
if ( V_15 -> V_16 . V_17 >= V_30 )
return F_30 ( - V_31 ) ;
F_6 ( & V_7 , V_15 ) ;
error = F_31 ( F_2 ( V_11 ) , & V_7 , & V_29 , NULL ) ;
if ( F_13 ( error ) ) {
if ( F_13 ( error != V_32 ) )
return F_30 ( - error ) ;
F_32 ( V_15 , NULL ) ;
return NULL ;
}
return F_33 ( F_23 ( V_29 ) , V_15 ) ;
}
STATIC struct V_15 *
F_34 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
unsigned int V_27 )
{
struct V_5 * V_6 ;
struct V_13 V_33 ;
struct V_13 V_34 ;
struct V_12 V_35 ;
int error ;
if ( V_15 -> V_16 . V_17 >= V_30 )
return F_30 ( - V_31 ) ;
F_6 ( & V_33 , V_15 ) ;
error = F_31 ( F_2 ( V_11 ) , & V_33 , & V_6 , & V_34 ) ;
if ( F_13 ( error ) ) {
if ( F_13 ( error != V_32 ) )
return F_30 ( - error ) ;
return NULL ;
}
if ( ! V_34 . V_7 )
return F_33 ( F_23 ( V_6 ) , V_15 ) ;
V_35 . V_7 = V_34 . V_7 ;
V_35 . V_17 = V_34 . V_17 ;
V_15 = F_35 ( V_15 , F_23 ( V_6 ) , & V_35 ) ;
F_36 ( V_34 . V_7 ) ;
return V_15 ;
}
STATIC int
F_37 (
struct V_15 * V_36 ,
struct V_1 * V_11 ,
struct V_15 * V_15 )
{
struct V_1 * V_1 = V_36 -> V_37 ;
struct V_13 V_7 ;
int error ;
F_6 ( & V_7 , V_15 ) ;
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
F_6 ( & V_7 , V_15 ) ;
error = - F_8 ( F_2 ( V_11 ) , & V_7 , F_2 ( V_15 -> V_37 ) ) ;
if ( error )
return error ;
if ( F_41 ( & F_42 ( V_11 -> V_38 ) -> V_39 ) )
F_43 ( V_15 ) ;
return 0 ;
}
STATIC int
F_44 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
const char * V_40 )
{
struct V_1 * V_1 ;
struct V_5 * V_29 = NULL ;
struct V_13 V_7 ;
int error ;
T_1 V_19 ;
V_19 = V_41 |
( V_42 ? 0777 & ~ F_21 () : V_43 ) ;
F_6 ( & V_7 , V_15 ) ;
error = F_45 ( F_2 ( V_11 ) , & V_7 , V_40 , V_19 , & V_29 ) ;
if ( F_13 ( error ) )
goto V_44;
V_1 = F_23 ( V_29 ) ;
error = F_4 ( V_1 , V_11 , & V_15 -> V_16 ) ;
if ( F_13 ( error ) )
goto V_26;
F_25 ( V_15 , V_1 ) ;
return 0 ;
V_26:
F_7 ( V_11 , V_1 , V_15 ) ;
V_44:
return - error ;
}
STATIC int
F_46 (
struct V_1 * V_45 ,
struct V_15 * V_46 ,
struct V_1 * V_47 ,
struct V_15 * V_48 )
{
struct V_1 * V_49 = V_48 -> V_37 ;
struct V_13 V_50 ;
struct V_13 V_51 ;
F_6 ( & V_50 , V_46 ) ;
F_6 ( & V_51 , V_48 ) ;
return - F_47 ( F_2 ( V_45 ) , & V_50 , F_2 ( V_46 -> V_37 ) ,
F_2 ( V_47 ) , & V_51 , V_49 ?
F_2 ( V_49 ) : NULL ) ;
}
STATIC void *
F_48 (
struct V_15 * V_15 ,
struct V_52 * V_53 )
{
char * V_54 ;
int error = - V_55 ;
V_54 = F_49 ( V_56 + 1 , V_57 ) ;
if ( ! V_54 )
goto V_58;
error = - F_50 ( F_2 ( V_15 -> V_37 ) , V_54 ) ;
if ( F_13 ( error ) )
goto V_59;
F_51 ( V_53 , V_54 ) ;
return NULL ;
V_59:
F_52 ( V_54 ) ;
V_58:
F_51 ( V_53 , F_30 ( error ) ) ;
return NULL ;
}
STATIC void
F_53 (
struct V_15 * V_15 ,
struct V_52 * V_53 ,
void * V_60 )
{
char * V_61 = F_54 ( V_53 ) ;
if ( ! F_19 ( V_61 ) )
F_52 ( V_61 ) ;
}
STATIC int
F_55 (
struct V_62 * V_63 ,
struct V_15 * V_15 ,
struct V_64 * V_65 )
{
struct V_1 * V_1 = V_15 -> V_37 ;
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_66 * V_67 = V_6 -> V_68 ;
F_56 ( V_6 ) ;
if ( F_57 ( V_67 ) )
return - F_58 ( V_69 ) ;
V_65 -> V_70 = F_59 ( V_6 ) ;
V_65 -> V_71 = V_1 -> V_38 -> V_72 ;
V_65 -> V_19 = V_6 -> V_73 . V_74 ;
V_65 -> V_75 = V_6 -> V_73 . V_76 ;
V_65 -> V_77 = V_6 -> V_73 . V_78 ;
V_65 -> V_79 = V_6 -> V_73 . V_80 ;
V_65 -> V_81 = V_6 -> V_82 ;
V_65 -> V_83 = V_1 -> V_84 ;
V_65 -> V_85 = V_1 -> V_86 ;
V_65 -> ctime = V_1 -> V_87 ;
V_65 -> V_88 =
F_60 ( V_67 , V_6 -> V_73 . V_89 + V_6 -> V_90 ) ;
switch ( V_1 -> V_91 & V_92 ) {
case V_93 :
case V_94 :
V_65 -> V_95 = V_96 ;
V_65 -> V_20 = F_61 ( F_62 ( V_6 -> V_97 . V_98 . V_99 ) & 0x1ff ,
F_63 ( V_6 -> V_97 . V_98 . V_99 ) ) ;
break;
default:
if ( F_64 ( V_6 ) ) {
V_65 -> V_95 =
F_65 ( V_6 ) << V_67 -> V_39 . V_100 ;
} else
V_65 -> V_95 = F_66 ( V_67 ) ;
V_65 -> V_20 = 0 ;
break;
}
return 0 ;
}
static void
F_67 (
struct V_101 * V_102 ,
struct V_5 * V_6 ,
struct V_103 * V_103 )
{
struct V_1 * V_1 = F_23 ( V_6 ) ;
T_1 V_19 = V_103 -> V_104 ;
ASSERT ( V_102 ) ;
ASSERT ( F_68 ( V_6 , V_105 ) ) ;
V_6 -> V_73 . V_74 &= V_92 ;
V_6 -> V_73 . V_74 |= V_19 & ~ V_92 ;
V_1 -> V_91 &= V_92 ;
V_1 -> V_91 |= V_19 & ~ V_92 ;
}
int
F_69 (
struct V_5 * V_6 ,
struct V_103 * V_103 ,
int V_27 )
{
T_3 * V_67 = V_6 -> V_68 ;
struct V_1 * V_1 = F_23 ( V_6 ) ;
int V_106 = V_103 -> V_107 ;
T_4 * V_102 ;
int error ;
T_5 V_77 = 0 , V_108 = 0 ;
T_6 V_79 = 0 , V_109 = 0 ;
struct V_110 * V_111 = NULL , * V_112 = NULL ;
struct V_110 * V_113 = NULL , * V_114 = NULL ;
F_70 ( V_6 ) ;
if ( ! ( V_27 & V_115 ) ) {
if ( V_67 -> V_116 & V_117 )
return F_58 ( V_118 ) ;
if ( F_57 ( V_67 ) )
return F_58 ( V_69 ) ;
error = - F_71 ( V_1 , V_103 ) ;
if ( error )
return F_58 ( error ) ;
}
ASSERT ( ( V_106 & V_119 ) == 0 ) ;
if ( F_72 ( V_67 ) && ( V_106 & ( V_120 | V_121 ) ) ) {
T_7 V_122 = 0 ;
if ( ( V_106 & V_120 ) && F_73 ( V_67 ) ) {
V_77 = V_103 -> V_123 ;
V_122 |= V_124 ;
} else {
V_77 = V_6 -> V_73 . V_78 ;
}
if ( ( V_106 & V_121 ) && F_74 ( V_67 ) ) {
V_79 = V_103 -> V_125 ;
V_122 |= V_126 ;
} else {
V_79 = V_6 -> V_73 . V_80 ;
}
ASSERT ( V_111 == NULL ) ;
ASSERT ( V_112 == NULL ) ;
error = F_75 ( V_6 , V_77 , V_79 , F_76 ( V_6 ) ,
V_122 , & V_111 , & V_112 , NULL ) ;
if ( error )
return error ;
}
V_102 = F_77 ( V_67 , V_127 ) ;
error = F_78 ( V_102 , 0 , F_79 ( V_67 ) , 0 , 0 , 0 ) ;
if ( error )
goto V_128;
F_80 ( V_6 , V_105 ) ;
if ( V_106 & ( V_120 | V_121 ) ) {
V_108 = V_6 -> V_73 . V_78 ;
V_109 = V_6 -> V_73 . V_80 ;
V_79 = ( V_106 & V_121 ) ? V_103 -> V_125 : V_109 ;
V_77 = ( V_106 & V_120 ) ? V_103 -> V_123 : V_108 ;
if ( F_81 ( V_67 ) &&
( ( F_73 ( V_67 ) && V_108 != V_77 ) ||
( F_74 ( V_67 ) && V_109 != V_79 ) ) ) {
ASSERT ( V_102 ) ;
error = F_82 ( V_102 , V_6 , V_111 , V_112 ,
NULL , F_83 ( V_129 ) ?
V_130 : 0 ) ;
if ( error )
goto V_131;
}
}
F_84 ( V_102 , V_6 , 0 ) ;
if ( V_106 & ( V_120 | V_121 ) ) {
if ( ( V_6 -> V_73 . V_74 & ( V_132 | V_133 ) ) &&
! F_83 ( V_134 ) )
V_6 -> V_73 . V_74 &= ~ ( V_132 | V_133 ) ;
if ( V_108 != V_77 ) {
if ( F_81 ( V_67 ) && F_73 ( V_67 ) ) {
ASSERT ( V_106 & V_120 ) ;
ASSERT ( V_111 ) ;
V_113 = F_85 ( V_102 , V_6 ,
& V_6 -> V_135 , V_111 ) ;
}
V_6 -> V_73 . V_78 = V_77 ;
V_1 -> V_136 = V_77 ;
}
if ( V_109 != V_79 ) {
if ( F_81 ( V_67 ) && F_74 ( V_67 ) ) {
ASSERT ( ! F_86 ( V_67 ) ) ;
ASSERT ( V_106 & V_121 ) ;
ASSERT ( V_112 ) ;
V_114 = F_85 ( V_102 , V_6 ,
& V_6 -> V_137 , V_112 ) ;
}
V_6 -> V_73 . V_80 = V_79 ;
V_1 -> V_138 = V_79 ;
}
}
if ( V_106 & V_139 )
F_67 ( V_102 , V_6 , V_103 ) ;
if ( V_106 & V_140 ) {
V_1 -> V_84 = V_103 -> V_141 ;
V_6 -> V_73 . V_142 . V_143 = V_103 -> V_141 . V_144 ;
V_6 -> V_73 . V_142 . V_145 = V_103 -> V_141 . V_146 ;
}
if ( V_106 & V_147 ) {
V_1 -> V_87 = V_103 -> V_148 ;
V_6 -> V_73 . V_149 . V_143 = V_103 -> V_148 . V_144 ;
V_6 -> V_73 . V_149 . V_145 = V_103 -> V_148 . V_146 ;
}
if ( V_106 & V_150 ) {
V_1 -> V_86 = V_103 -> V_151 ;
V_6 -> V_73 . V_152 . V_143 = V_103 -> V_151 . V_144 ;
V_6 -> V_73 . V_152 . V_145 = V_103 -> V_151 . V_146 ;
}
F_87 ( V_102 , V_6 , V_153 ) ;
F_88 ( V_154 ) ;
if ( V_67 -> V_116 & V_155 )
F_89 ( V_102 ) ;
error = F_90 ( V_102 , 0 ) ;
F_91 ( V_6 , V_105 ) ;
F_92 ( V_113 ) ;
F_92 ( V_114 ) ;
F_92 ( V_111 ) ;
F_92 ( V_112 ) ;
if ( error )
return F_58 ( error ) ;
if ( ( V_106 & V_139 ) && ! ( V_27 & V_115 ) ) {
error = - F_93 ( V_1 ) ;
if ( error )
return F_58 ( error ) ;
}
return 0 ;
V_131:
F_94 ( V_102 , 0 ) ;
F_91 ( V_6 , V_105 ) ;
V_128:
F_92 ( V_111 ) ;
F_92 ( V_112 ) ;
return error ;
}
int
F_95 (
struct V_5 * V_6 ,
struct V_103 * V_103 ,
int V_27 )
{
struct V_66 * V_67 = V_6 -> V_68 ;
struct V_1 * V_1 = F_23 ( V_6 ) ;
int V_106 = V_103 -> V_107 ;
T_8 V_156 , V_157 ;
struct V_101 * V_102 ;
int error ;
T_7 V_158 = 0 ;
T_7 V_159 = 0 ;
F_70 ( V_6 ) ;
if ( V_67 -> V_116 & V_117 )
return F_58 ( V_118 ) ;
if ( F_57 ( V_67 ) )
return F_58 ( V_69 ) ;
error = - F_71 ( V_1 , V_103 ) ;
if ( error )
return F_58 ( error ) ;
ASSERT ( F_96 ( V_6 -> V_73 . V_74 ) ) ;
ASSERT ( ( V_106 & ( V_120 | V_121 | V_140 | V_160 |
V_161 | V_162 | V_163 ) ) == 0 ) ;
if ( ! ( V_27 & V_164 ) ) {
V_158 |= V_165 ;
F_80 ( V_6 , V_158 ) ;
}
V_156 = V_1 -> V_166 ;
V_157 = V_103 -> V_167 ;
if ( V_157 == 0 && V_156 == 0 && V_6 -> V_73 . V_168 == 0 ) {
if ( ! ( V_106 & ( V_147 | V_150 ) ) )
goto V_169;
F_91 ( V_6 , V_158 ) ;
V_103 -> V_107 &= ~ V_119 ;
return F_69 ( V_6 , V_103 , 0 ) ;
}
error = F_97 ( V_6 , 0 ) ;
if ( error )
goto V_169;
if ( V_157 > V_156 ) {
error = F_98 ( V_6 , V_157 , V_156 ) ;
if ( error )
goto V_169;
}
if ( V_156 != V_6 -> V_73 . V_170 && V_157 > V_6 -> V_73 . V_170 ) {
error = - F_99 ( F_23 ( V_6 ) -> V_171 ,
V_6 -> V_73 . V_170 , V_157 ) ;
if ( error )
goto V_169;
}
F_100 ( V_1 ) ;
error = - F_101 ( V_1 -> V_171 , V_157 , V_172 ) ;
if ( error )
goto V_169;
V_102 = F_77 ( V_67 , V_173 ) ;
error = F_78 ( V_102 , 0 , F_102 ( V_67 ) , 0 ,
V_174 ,
V_175 ) ;
if ( error )
goto V_131;
F_103 ( V_1 , V_157 ) ;
V_159 = V_176 ;
V_158 |= V_105 ;
F_80 ( V_6 , V_105 ) ;
F_84 ( V_102 , V_6 , 0 ) ;
if ( V_157 != V_156 && ( ! ( V_106 & ( V_147 | V_150 ) ) ) ) {
V_103 -> V_148 = V_103 -> V_151 =
F_104 ( V_1 -> V_38 ) ;
V_106 |= V_147 | V_150 ;
}
V_6 -> V_73 . V_170 = V_157 ;
F_87 ( V_102 , V_6 , V_153 ) ;
if ( V_157 <= V_156 ) {
error = F_105 ( & V_102 , V_6 , V_177 , V_157 ) ;
if ( error )
goto V_178;
F_106 ( V_6 , V_179 ) ;
F_107 ( V_6 ) ;
}
if ( V_106 & V_139 )
F_67 ( V_102 , V_6 , V_103 ) ;
if ( V_106 & V_147 ) {
V_1 -> V_87 = V_103 -> V_148 ;
V_6 -> V_73 . V_149 . V_143 = V_103 -> V_148 . V_144 ;
V_6 -> V_73 . V_149 . V_145 = V_103 -> V_148 . V_146 ;
}
if ( V_106 & V_150 ) {
V_1 -> V_86 = V_103 -> V_151 ;
V_6 -> V_73 . V_152 . V_143 = V_103 -> V_151 . V_144 ;
V_6 -> V_73 . V_152 . V_145 = V_103 -> V_151 . V_146 ;
}
F_87 ( V_102 , V_6 , V_153 ) ;
F_88 ( V_154 ) ;
if ( V_67 -> V_116 & V_155 )
F_89 ( V_102 ) ;
error = F_90 ( V_102 , V_176 ) ;
V_169:
if ( V_158 )
F_91 ( V_6 , V_158 ) ;
return error ;
V_178:
V_159 |= V_180 ;
V_131:
F_94 ( V_102 , V_159 ) ;
goto V_169;
}
STATIC int
F_108 (
struct V_15 * V_15 ,
struct V_103 * V_103 )
{
if ( V_103 -> V_107 & V_119 )
return - F_95 ( F_2 ( V_15 -> V_37 ) , V_103 , 0 ) ;
return - F_69 ( F_2 ( V_15 -> V_37 ) , V_103 , 0 ) ;
}
STATIC int
F_109 (
struct V_1 * V_1 ,
struct V_181 * V_182 ,
int V_27 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_66 * V_67 = V_6 -> V_68 ;
struct V_101 * V_102 ;
int error ;
F_110 ( V_6 ) ;
V_102 = F_77 ( V_67 , V_183 ) ;
error = F_78 ( V_102 , 0 , F_111 ( V_67 ) , 0 , 0 , 0 ) ;
if ( error ) {
F_94 ( V_102 , 0 ) ;
return - error ;
}
F_80 ( V_6 , V_105 ) ;
if ( V_27 & V_184 ) {
V_1 -> V_87 = * V_182 ;
V_6 -> V_73 . V_149 . V_143 = ( V_185 ) V_182 -> V_144 ;
V_6 -> V_73 . V_149 . V_145 = ( V_185 ) V_182 -> V_146 ;
}
if ( V_27 & V_186 ) {
V_1 -> V_86 = * V_182 ;
V_6 -> V_73 . V_152 . V_143 = ( V_185 ) V_182 -> V_144 ;
V_6 -> V_73 . V_152 . V_145 = ( V_185 ) V_182 -> V_146 ;
}
if ( V_27 & V_187 ) {
V_1 -> V_84 = * V_182 ;
V_6 -> V_73 . V_142 . V_143 = ( V_185 ) V_182 -> V_144 ;
V_6 -> V_73 . V_142 . V_145 = ( V_185 ) V_182 -> V_146 ;
}
F_84 ( V_102 , V_6 , V_105 ) ;
F_87 ( V_102 , V_6 , V_188 ) ;
return - F_90 ( V_102 , 0 ) ;
}
STATIC int
F_112 (
void * * V_189 ,
struct V_190 * V_191 ,
int * V_192 )
{
int error ;
struct V_193 * V_194 = * V_189 ;
T_9 V_195 = 0 ;
T_10 V_196 , V_197 , V_198 ;
if ( V_191 -> V_199 == - 1LL )
return 0 ;
V_196 = F_113 ( V_191 -> V_200 ) ;
V_197 = F_113 ( V_191 -> V_199 ) ;
V_198 = F_113 ( V_191 -> V_201 ) ;
if ( V_191 -> V_202 & V_203 )
V_195 |= V_204 ;
else if ( V_191 -> V_202 & V_205 ) {
V_195 |= ( V_206 |
V_207 ) ;
V_197 = 0 ;
}
if ( V_191 -> V_202 & V_208 )
V_195 |= V_209 ;
error = F_114 ( V_194 , V_196 , V_197 ,
V_198 , V_195 ) ;
if ( error > 0 ) {
error = 0 ;
* V_192 = 1 ;
}
return - error ;
}
STATIC int
F_115 (
struct V_1 * V_1 ,
struct V_193 * V_194 ,
T_10 V_210 ,
T_10 V_198 )
{
T_11 * V_6 = F_2 ( V_1 ) ;
struct V_190 V_211 ;
int error ;
error = F_116 ( V_194 , V_212 ) ;
if ( error )
return error ;
V_211 . V_200 = F_117 ( V_210 ) ;
if ( V_198 == V_213 )
V_211 . V_201 = - 1LL ;
else
V_211 . V_201 = F_117 ( V_198 ) ;
V_211 . V_214 = ! V_194 -> V_215 ? V_216 :
V_194 -> V_215 + 1 ;
V_211 . V_214 = F_118 ( V_217 , V_211 . V_214 ,
( V_218 * 16 / sizeof( struct V_190 ) ) ) ;
V_211 . V_219 = V_220 | V_221 ;
if ( V_194 -> V_222 & V_223 )
V_211 . V_219 |= V_224 ;
if ( ! ( V_194 -> V_222 & V_225 ) )
V_211 . V_219 |= V_226 ;
error = F_119 ( V_6 , & V_211 , F_112 , V_194 ) ;
if ( error )
return - error ;
return 0 ;
}
STATIC void
F_120 (
struct V_1 * V_1 ,
struct V_5 * V_6 )
{
if ( V_6 -> V_73 . V_227 & V_228 )
V_1 -> V_229 |= V_230 ;
else
V_1 -> V_229 &= ~ V_230 ;
if ( V_6 -> V_73 . V_227 & V_231 )
V_1 -> V_229 |= V_232 ;
else
V_1 -> V_229 &= ~ V_232 ;
if ( V_6 -> V_73 . V_227 & V_233 )
V_1 -> V_229 |= V_234 ;
else
V_1 -> V_229 &= ~ V_234 ;
if ( V_6 -> V_73 . V_227 & V_235 )
V_1 -> V_229 |= V_236 ;
else
V_1 -> V_229 &= ~ V_236 ;
}
void
F_121 (
struct V_5 * V_6 )
{
struct V_1 * V_1 = & V_6 -> V_237 ;
V_1 -> V_82 = V_6 -> V_82 ;
V_1 -> V_238 = V_239 ;
F_122 ( V_1 ) ;
F_123 ( & V_1 -> V_240 ) ;
V_1 -> V_91 = V_6 -> V_73 . V_74 ;
F_124 ( V_1 , V_6 -> V_73 . V_76 ) ;
V_1 -> V_136 = V_6 -> V_73 . V_78 ;
V_1 -> V_138 = V_6 -> V_73 . V_80 ;
switch ( V_1 -> V_91 & V_92 ) {
case V_93 :
case V_94 :
V_1 -> V_241 =
F_61 ( F_62 ( V_6 -> V_97 . V_98 . V_99 ) & 0x1ff ,
F_63 ( V_6 -> V_97 . V_98 . V_99 ) ) ;
break;
default:
V_1 -> V_241 = 0 ;
break;
}
V_1 -> V_242 = V_6 -> V_73 . V_243 ;
F_125 ( V_1 , V_6 -> V_73 . V_170 ) ;
V_1 -> V_84 . V_144 = V_6 -> V_73 . V_142 . V_143 ;
V_1 -> V_84 . V_146 = V_6 -> V_73 . V_142 . V_145 ;
V_1 -> V_86 . V_144 = V_6 -> V_73 . V_152 . V_143 ;
V_1 -> V_86 . V_146 = V_6 -> V_73 . V_152 . V_145 ;
V_1 -> V_87 . V_144 = V_6 -> V_73 . V_149 . V_143 ;
V_1 -> V_87 . V_146 = V_6 -> V_73 . V_149 . V_145 ;
F_120 ( V_1 , V_6 ) ;
switch ( V_1 -> V_91 & V_92 ) {
case V_244 :
V_1 -> V_245 = & V_246 ;
V_1 -> V_247 = & V_248 ;
V_1 -> V_171 -> V_249 = & V_250 ;
break;
case V_28 :
if ( F_41 ( & F_42 ( V_1 -> V_38 ) -> V_39 ) )
V_1 -> V_245 = & V_251 ;
else
V_1 -> V_245 = & V_252 ;
V_1 -> V_247 = & V_253 ;
break;
case V_41 :
V_1 -> V_245 = & V_254 ;
if ( ! ( V_6 -> V_97 . V_255 & V_256 ) )
V_1 -> V_171 -> V_249 = & V_250 ;
break;
default:
V_1 -> V_245 = & V_246 ;
F_126 ( V_1 , V_1 -> V_91 , V_1 -> V_241 ) ;
break;
}
if ( ! F_127 ( V_6 ) ) {
F_128 ( V_1 ) ;
F_129 ( V_1 ) ;
}
F_130 ( V_6 , V_257 ) ;
F_131 () ;
F_132 ( V_1 ) ;
}
