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
if ( ! F_69 ( V_1 -> V_106 ) && ! F_70 ( V_107 ) )
V_19 &= ~ V_108 ;
V_6 -> V_73 . V_74 &= V_92 ;
V_6 -> V_73 . V_74 |= V_19 & ~ V_92 ;
V_1 -> V_91 &= V_92 ;
V_1 -> V_91 |= V_19 & ~ V_92 ;
}
int
F_71 (
struct V_5 * V_6 ,
struct V_103 * V_103 ,
int V_27 )
{
T_3 * V_67 = V_6 -> V_68 ;
struct V_1 * V_1 = F_23 ( V_6 ) ;
int V_109 = V_103 -> V_110 ;
T_4 * V_102 ;
int error ;
T_5 V_77 = 0 , V_111 = 0 ;
T_6 V_79 = 0 , V_112 = 0 ;
struct V_113 * V_114 = NULL , * V_115 = NULL ;
struct V_113 * V_116 = NULL , * V_117 = NULL ;
F_72 ( V_6 ) ;
if ( V_67 -> V_118 & V_119 )
return F_58 ( V_120 ) ;
if ( F_57 ( V_67 ) )
return F_58 ( V_69 ) ;
error = - F_73 ( V_1 , V_103 ) ;
if ( error )
return F_58 ( error ) ;
ASSERT ( ( V_109 & V_121 ) == 0 ) ;
if ( F_74 ( V_67 ) && ( V_109 & ( V_122 | V_123 ) ) ) {
T_7 V_124 = 0 ;
if ( ( V_109 & V_122 ) && F_75 ( V_67 ) ) {
V_77 = V_103 -> V_125 ;
V_124 |= V_126 ;
} else {
V_77 = V_6 -> V_73 . V_78 ;
}
if ( ( V_109 & V_123 ) && F_76 ( V_67 ) ) {
V_79 = V_103 -> V_127 ;
V_124 |= V_128 ;
} else {
V_79 = V_6 -> V_73 . V_80 ;
}
ASSERT ( V_114 == NULL ) ;
ASSERT ( V_115 == NULL ) ;
error = F_77 ( V_6 , V_77 , V_79 , F_78 ( V_6 ) ,
V_124 , & V_114 , & V_115 ) ;
if ( error )
return error ;
}
V_102 = F_79 ( V_67 , V_129 ) ;
error = F_80 ( V_102 , 0 , F_81 ( V_67 ) , 0 , 0 , 0 ) ;
if ( error )
goto V_130;
F_82 ( V_6 , V_105 ) ;
if ( V_109 & ( V_122 | V_123 ) ) {
V_111 = V_6 -> V_73 . V_78 ;
V_112 = V_6 -> V_73 . V_80 ;
V_79 = ( V_109 & V_123 ) ? V_103 -> V_127 : V_112 ;
V_77 = ( V_109 & V_122 ) ? V_103 -> V_125 : V_111 ;
if ( F_83 ( V_67 ) &&
( ( F_75 ( V_67 ) && V_111 != V_77 ) ||
( F_76 ( V_67 ) && V_112 != V_79 ) ) ) {
ASSERT ( V_102 ) ;
error = F_84 ( V_102 , V_6 , V_114 , V_115 ,
F_70 ( V_131 ) ?
V_132 : 0 ) ;
if ( error )
goto V_133;
}
}
F_85 ( V_102 , V_6 , 0 ) ;
if ( V_109 & ( V_122 | V_123 ) ) {
if ( ( V_6 -> V_73 . V_74 & ( V_134 | V_108 ) ) &&
! F_70 ( V_107 ) )
V_6 -> V_73 . V_74 &= ~ ( V_134 | V_108 ) ;
if ( V_111 != V_77 ) {
if ( F_83 ( V_67 ) && F_75 ( V_67 ) ) {
ASSERT ( V_109 & V_122 ) ;
ASSERT ( V_114 ) ;
V_116 = F_86 ( V_102 , V_6 ,
& V_6 -> V_135 , V_114 ) ;
}
V_6 -> V_73 . V_78 = V_77 ;
V_1 -> V_136 = V_77 ;
}
if ( V_112 != V_79 ) {
if ( F_83 ( V_67 ) && F_76 ( V_67 ) ) {
ASSERT ( ! F_87 ( V_67 ) ) ;
ASSERT ( V_109 & V_123 ) ;
ASSERT ( V_115 ) ;
V_117 = F_86 ( V_102 , V_6 ,
& V_6 -> V_137 , V_115 ) ;
}
V_6 -> V_73 . V_80 = V_79 ;
V_1 -> V_106 = V_79 ;
}
}
if ( V_109 & V_138 )
F_67 ( V_102 , V_6 , V_103 ) ;
if ( V_109 & V_139 ) {
V_1 -> V_84 = V_103 -> V_140 ;
V_6 -> V_73 . V_141 . V_142 = V_103 -> V_140 . V_143 ;
V_6 -> V_73 . V_141 . V_144 = V_103 -> V_140 . V_145 ;
}
if ( V_109 & V_146 ) {
V_1 -> V_87 = V_103 -> V_147 ;
V_6 -> V_73 . V_148 . V_142 = V_103 -> V_147 . V_143 ;
V_6 -> V_73 . V_148 . V_144 = V_103 -> V_147 . V_145 ;
}
if ( V_109 & V_149 ) {
V_1 -> V_86 = V_103 -> V_150 ;
V_6 -> V_73 . V_151 . V_142 = V_103 -> V_150 . V_143 ;
V_6 -> V_73 . V_151 . V_144 = V_103 -> V_150 . V_145 ;
}
F_88 ( V_102 , V_6 , V_152 ) ;
F_89 ( V_153 ) ;
if ( V_67 -> V_118 & V_154 )
F_90 ( V_102 ) ;
error = F_91 ( V_102 , 0 ) ;
F_92 ( V_6 , V_105 ) ;
F_93 ( V_116 ) ;
F_93 ( V_117 ) ;
F_93 ( V_114 ) ;
F_93 ( V_115 ) ;
if ( error )
return F_58 ( error ) ;
if ( ( V_109 & V_138 ) && ! ( V_27 & V_155 ) ) {
error = - F_94 ( V_1 ) ;
if ( error )
return F_58 ( error ) ;
}
return 0 ;
V_133:
F_95 ( V_102 , 0 ) ;
F_92 ( V_6 , V_105 ) ;
V_130:
F_93 ( V_114 ) ;
F_93 ( V_115 ) ;
return error ;
}
int
F_96 (
struct V_5 * V_6 ,
struct V_103 * V_103 ,
int V_27 )
{
struct V_66 * V_67 = V_6 -> V_68 ;
struct V_1 * V_1 = F_23 ( V_6 ) ;
int V_109 = V_103 -> V_110 ;
T_8 V_156 , V_157 ;
struct V_101 * V_102 ;
int error ;
T_7 V_158 = 0 ;
T_7 V_159 = 0 ;
F_72 ( V_6 ) ;
if ( V_67 -> V_118 & V_119 )
return F_58 ( V_120 ) ;
if ( F_57 ( V_67 ) )
return F_58 ( V_69 ) ;
error = - F_73 ( V_1 , V_103 ) ;
if ( error )
return F_58 ( error ) ;
ASSERT ( F_97 ( V_6 -> V_73 . V_74 ) ) ;
ASSERT ( ( V_109 & ( V_122 | V_123 | V_139 | V_160 |
V_161 | V_162 | V_163 ) ) == 0 ) ;
if ( ! ( V_27 & V_164 ) ) {
V_158 |= V_165 ;
F_82 ( V_6 , V_158 ) ;
}
V_156 = V_1 -> V_166 ;
V_157 = V_103 -> V_167 ;
if ( V_157 == 0 && V_156 == 0 && V_6 -> V_73 . V_168 == 0 ) {
if ( ! ( V_109 & ( V_146 | V_149 ) ) )
goto V_169;
F_92 ( V_6 , V_158 ) ;
V_103 -> V_110 &= ~ V_121 ;
return F_71 ( V_6 , V_103 , 0 ) ;
}
error = F_98 ( V_6 , 0 ) ;
if ( error )
goto V_169;
if ( V_157 > V_156 ) {
error = F_99 ( V_6 , V_157 , V_156 ) ;
if ( error )
goto V_169;
}
if ( V_156 != V_6 -> V_73 . V_170 && V_157 > V_6 -> V_73 . V_170 ) {
error = - F_100 ( F_23 ( V_6 ) -> V_171 ,
V_6 -> V_73 . V_170 , V_157 ) ;
if ( error )
goto V_169;
}
F_101 ( V_1 ) ;
error = - F_102 ( V_1 -> V_171 , V_157 , V_172 ) ;
if ( error )
goto V_169;
V_102 = F_79 ( V_67 , V_173 ) ;
error = F_80 ( V_102 , 0 , F_103 ( V_67 ) , 0 ,
V_174 ,
V_175 ) ;
if ( error )
goto V_133;
F_104 ( V_1 , V_157 ) ;
V_159 = V_176 ;
V_158 |= V_105 ;
F_82 ( V_6 , V_105 ) ;
F_85 ( V_102 , V_6 , 0 ) ;
if ( V_157 != V_156 && ( ! ( V_109 & ( V_146 | V_149 ) ) ) ) {
V_103 -> V_147 = V_103 -> V_150 =
F_105 ( V_1 -> V_38 ) ;
V_109 |= V_146 | V_149 ;
}
V_6 -> V_73 . V_170 = V_157 ;
F_88 ( V_102 , V_6 , V_152 ) ;
if ( V_157 <= V_156 ) {
error = F_106 ( & V_102 , V_6 , V_177 , V_157 ) ;
if ( error )
goto V_178;
F_107 ( V_6 , V_179 ) ;
F_108 ( V_6 ) ;
}
if ( V_109 & V_138 )
F_67 ( V_102 , V_6 , V_103 ) ;
if ( V_109 & V_146 ) {
V_1 -> V_87 = V_103 -> V_147 ;
V_6 -> V_73 . V_148 . V_142 = V_103 -> V_147 . V_143 ;
V_6 -> V_73 . V_148 . V_144 = V_103 -> V_147 . V_145 ;
}
if ( V_109 & V_149 ) {
V_1 -> V_86 = V_103 -> V_150 ;
V_6 -> V_73 . V_151 . V_142 = V_103 -> V_150 . V_143 ;
V_6 -> V_73 . V_151 . V_144 = V_103 -> V_150 . V_145 ;
}
F_88 ( V_102 , V_6 , V_152 ) ;
F_89 ( V_153 ) ;
if ( V_67 -> V_118 & V_154 )
F_90 ( V_102 ) ;
error = F_91 ( V_102 , V_176 ) ;
V_169:
if ( V_158 )
F_92 ( V_6 , V_158 ) ;
return error ;
V_178:
V_159 |= V_180 ;
V_133:
F_95 ( V_102 , V_159 ) ;
goto V_169;
}
STATIC int
F_109 (
struct V_15 * V_15 ,
struct V_103 * V_103 )
{
if ( V_103 -> V_110 & V_121 )
return - F_96 ( F_2 ( V_15 -> V_37 ) , V_103 , 0 ) ;
return - F_71 ( F_2 ( V_15 -> V_37 ) , V_103 , 0 ) ;
}
STATIC int
F_110 (
struct V_1 * V_1 ,
struct V_181 * V_182 ,
int V_27 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_66 * V_67 = V_6 -> V_68 ;
struct V_101 * V_102 ;
int error ;
F_111 ( V_6 ) ;
V_102 = F_79 ( V_67 , V_183 ) ;
error = F_80 ( V_102 , 0 , F_112 ( V_67 ) , 0 , 0 , 0 ) ;
if ( error ) {
F_95 ( V_102 , 0 ) ;
return - error ;
}
F_82 ( V_6 , V_105 ) ;
if ( V_27 & V_184 ) {
V_1 -> V_87 = * V_182 ;
V_6 -> V_73 . V_148 . V_142 = ( V_185 ) V_182 -> V_143 ;
V_6 -> V_73 . V_148 . V_144 = ( V_185 ) V_182 -> V_145 ;
}
if ( V_27 & V_186 ) {
V_1 -> V_86 = * V_182 ;
V_6 -> V_73 . V_151 . V_142 = ( V_185 ) V_182 -> V_143 ;
V_6 -> V_73 . V_151 . V_144 = ( V_185 ) V_182 -> V_145 ;
}
if ( V_27 & V_187 ) {
V_1 -> V_84 = * V_182 ;
V_6 -> V_73 . V_141 . V_142 = ( V_185 ) V_182 -> V_143 ;
V_6 -> V_73 . V_141 . V_144 = ( V_185 ) V_182 -> V_145 ;
}
F_85 ( V_102 , V_6 , V_105 ) ;
F_88 ( V_102 , V_6 , V_188 ) ;
return - F_91 ( V_102 , 0 ) ;
}
STATIC int
F_113 (
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
V_196 = F_114 ( V_191 -> V_200 ) ;
V_197 = F_114 ( V_191 -> V_199 ) ;
V_198 = F_114 ( V_191 -> V_201 ) ;
if ( V_191 -> V_202 & V_203 )
V_195 |= V_204 ;
else if ( V_191 -> V_202 & V_205 ) {
V_195 |= V_206 ;
V_197 = 0 ;
}
if ( V_191 -> V_202 & V_207 )
V_195 |= V_208 ;
error = F_115 ( V_194 , V_196 , V_197 ,
V_198 , V_195 ) ;
if ( error > 0 ) {
error = 0 ;
* V_192 = 1 ;
}
return - error ;
}
STATIC int
F_116 (
struct V_1 * V_1 ,
struct V_193 * V_194 ,
T_10 V_209 ,
T_10 V_198 )
{
T_11 * V_6 = F_2 ( V_1 ) ;
struct V_190 V_210 ;
int error ;
error = F_117 ( V_194 , V_211 ) ;
if ( error )
return error ;
V_210 . V_200 = F_118 ( V_209 ) ;
if ( V_198 == V_212 )
V_210 . V_201 = - 1LL ;
else
V_210 . V_201 = F_118 ( V_198 ) ;
V_210 . V_213 = ! V_194 -> V_214 ? V_215 :
V_194 -> V_214 + 1 ;
V_210 . V_213 = F_119 ( V_216 , V_210 . V_213 ,
( V_217 * 16 / sizeof( struct V_190 ) ) ) ;
V_210 . V_218 = V_219 | V_220 ;
if ( V_194 -> V_221 & V_222 )
V_210 . V_218 |= V_223 ;
if ( ! ( V_194 -> V_221 & V_224 ) )
V_210 . V_218 |= V_225 ;
error = F_120 ( V_6 , & V_210 , F_113 , V_194 ) ;
if ( error )
return - error ;
return 0 ;
}
STATIC void
F_121 (
struct V_1 * V_1 ,
struct V_5 * V_6 )
{
if ( V_6 -> V_73 . V_226 & V_227 )
V_1 -> V_228 |= V_229 ;
else
V_1 -> V_228 &= ~ V_229 ;
if ( V_6 -> V_73 . V_226 & V_230 )
V_1 -> V_228 |= V_231 ;
else
V_1 -> V_228 &= ~ V_231 ;
if ( V_6 -> V_73 . V_226 & V_232 )
V_1 -> V_228 |= V_233 ;
else
V_1 -> V_228 &= ~ V_233 ;
if ( V_6 -> V_73 . V_226 & V_234 )
V_1 -> V_228 |= V_235 ;
else
V_1 -> V_228 &= ~ V_235 ;
}
void
F_122 (
struct V_5 * V_6 )
{
struct V_1 * V_1 = & V_6 -> V_236 ;
V_1 -> V_82 = V_6 -> V_82 ;
V_1 -> V_237 = V_238 ;
F_123 ( V_1 ) ;
F_124 ( & V_1 -> V_239 ) ;
V_1 -> V_91 = V_6 -> V_73 . V_74 ;
F_125 ( V_1 , V_6 -> V_73 . V_76 ) ;
V_1 -> V_136 = V_6 -> V_73 . V_78 ;
V_1 -> V_106 = V_6 -> V_73 . V_80 ;
switch ( V_1 -> V_91 & V_92 ) {
case V_93 :
case V_94 :
V_1 -> V_240 =
F_61 ( F_62 ( V_6 -> V_97 . V_98 . V_99 ) & 0x1ff ,
F_63 ( V_6 -> V_97 . V_98 . V_99 ) ) ;
break;
default:
V_1 -> V_240 = 0 ;
break;
}
V_1 -> V_241 = V_6 -> V_73 . V_242 ;
F_126 ( V_1 , V_6 -> V_73 . V_170 ) ;
V_1 -> V_84 . V_143 = V_6 -> V_73 . V_141 . V_142 ;
V_1 -> V_84 . V_145 = V_6 -> V_73 . V_141 . V_144 ;
V_1 -> V_86 . V_143 = V_6 -> V_73 . V_151 . V_142 ;
V_1 -> V_86 . V_145 = V_6 -> V_73 . V_151 . V_144 ;
V_1 -> V_87 . V_143 = V_6 -> V_73 . V_148 . V_142 ;
V_1 -> V_87 . V_145 = V_6 -> V_73 . V_148 . V_144 ;
F_121 ( V_1 , V_6 ) ;
switch ( V_1 -> V_91 & V_92 ) {
case V_243 :
V_1 -> V_244 = & V_245 ;
V_1 -> V_246 = & V_247 ;
V_1 -> V_171 -> V_248 = & V_249 ;
break;
case V_28 :
if ( F_41 ( & F_42 ( V_1 -> V_38 ) -> V_39 ) )
V_1 -> V_244 = & V_250 ;
else
V_1 -> V_244 = & V_251 ;
V_1 -> V_246 = & V_252 ;
break;
case V_41 :
V_1 -> V_244 = & V_253 ;
if ( ! ( V_6 -> V_97 . V_254 & V_255 ) )
V_1 -> V_171 -> V_248 = & V_249 ;
break;
default:
V_1 -> V_244 = & V_245 ;
F_127 ( V_1 , V_1 -> V_91 , V_1 -> V_240 ) ;
break;
}
if ( ! F_128 ( V_6 ) ) {
F_129 ( V_1 ) ;
F_130 ( V_1 ) ;
}
F_131 ( V_6 , V_256 ) ;
F_132 () ;
F_133 ( V_1 ) ;
}
