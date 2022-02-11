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
int
F_67 (
struct V_5 * V_6 ,
struct V_101 * V_101 ,
int V_27 )
{
T_3 * V_67 = V_6 -> V_68 ;
struct V_1 * V_1 = F_23 ( V_6 ) ;
int V_102 = V_101 -> V_103 ;
T_4 * V_104 ;
int error ;
T_5 V_77 = 0 , V_105 = 0 ;
T_6 V_79 = 0 , V_106 = 0 ;
struct V_107 * V_108 = NULL , * V_109 = NULL ;
struct V_107 * V_110 = NULL , * V_111 = NULL ;
F_68 ( V_6 ) ;
if ( V_67 -> V_112 & V_113 )
return F_58 ( V_114 ) ;
if ( F_57 ( V_67 ) )
return F_58 ( V_69 ) ;
error = - F_69 ( V_1 , V_101 ) ;
if ( error )
return F_58 ( error ) ;
ASSERT ( ( V_102 & V_115 ) == 0 ) ;
if ( F_70 ( V_67 ) && ( V_102 & ( V_116 | V_117 ) ) ) {
T_7 V_118 = 0 ;
if ( ( V_102 & V_116 ) && F_71 ( V_67 ) ) {
V_77 = V_101 -> V_119 ;
V_118 |= V_120 ;
} else {
V_77 = V_6 -> V_73 . V_78 ;
}
if ( ( V_102 & V_117 ) && F_72 ( V_67 ) ) {
V_79 = V_101 -> V_121 ;
V_118 |= V_122 ;
} else {
V_79 = V_6 -> V_73 . V_80 ;
}
ASSERT ( V_108 == NULL ) ;
ASSERT ( V_109 == NULL ) ;
error = F_73 ( V_6 , V_77 , V_79 , F_74 ( V_6 ) ,
V_118 , & V_108 , & V_109 ) ;
if ( error )
return error ;
}
V_104 = F_75 ( V_67 , V_123 ) ;
error = F_76 ( V_104 , 0 , F_77 ( V_67 ) , 0 , 0 , 0 ) ;
if ( error )
goto V_124;
F_78 ( V_6 , V_125 ) ;
if ( V_102 & ( V_116 | V_117 ) ) {
V_105 = V_6 -> V_73 . V_78 ;
V_106 = V_6 -> V_73 . V_80 ;
V_79 = ( V_102 & V_117 ) ? V_101 -> V_121 : V_106 ;
V_77 = ( V_102 & V_116 ) ? V_101 -> V_119 : V_105 ;
if ( F_79 ( V_67 ) &&
( ( F_71 ( V_67 ) && V_105 != V_77 ) ||
( F_72 ( V_67 ) && V_106 != V_79 ) ) ) {
ASSERT ( V_104 ) ;
error = F_80 ( V_104 , V_6 , V_108 , V_109 ,
F_81 ( V_126 ) ?
V_127 : 0 ) ;
if ( error )
goto V_128;
}
}
F_82 ( V_104 , V_6 , 0 ) ;
if ( V_102 & ( V_116 | V_117 ) ) {
if ( ( V_6 -> V_73 . V_74 & ( V_129 | V_130 ) ) &&
! F_81 ( V_131 ) )
V_6 -> V_73 . V_74 &= ~ ( V_129 | V_130 ) ;
if ( V_105 != V_77 ) {
if ( F_79 ( V_67 ) && F_71 ( V_67 ) ) {
ASSERT ( V_102 & V_116 ) ;
ASSERT ( V_108 ) ;
V_110 = F_83 ( V_104 , V_6 ,
& V_6 -> V_132 , V_108 ) ;
}
V_6 -> V_73 . V_78 = V_77 ;
V_1 -> V_133 = V_77 ;
}
if ( V_106 != V_79 ) {
if ( F_79 ( V_67 ) && F_72 ( V_67 ) ) {
ASSERT ( ! F_84 ( V_67 ) ) ;
ASSERT ( V_102 & V_117 ) ;
ASSERT ( V_109 ) ;
V_111 = F_83 ( V_104 , V_6 ,
& V_6 -> V_134 , V_109 ) ;
}
V_6 -> V_73 . V_80 = V_79 ;
V_1 -> V_135 = V_79 ;
}
}
if ( V_102 & V_136 ) {
T_1 V_19 = V_101 -> V_137 ;
if ( ! F_85 ( V_1 -> V_135 ) && ! F_81 ( V_131 ) )
V_19 &= ~ V_130 ;
V_6 -> V_73 . V_74 &= V_92 ;
V_6 -> V_73 . V_74 |= V_19 & ~ V_92 ;
V_1 -> V_91 &= V_92 ;
V_1 -> V_91 |= V_19 & ~ V_92 ;
}
if ( V_102 & V_138 ) {
V_1 -> V_84 = V_101 -> V_139 ;
V_6 -> V_73 . V_140 . V_141 = V_101 -> V_139 . V_142 ;
V_6 -> V_73 . V_140 . V_143 = V_101 -> V_139 . V_144 ;
}
if ( V_102 & V_145 ) {
V_1 -> V_87 = V_101 -> V_146 ;
V_6 -> V_73 . V_147 . V_141 = V_101 -> V_146 . V_142 ;
V_6 -> V_73 . V_147 . V_143 = V_101 -> V_146 . V_144 ;
}
if ( V_102 & V_148 ) {
V_1 -> V_86 = V_101 -> V_149 ;
V_6 -> V_73 . V_150 . V_141 = V_101 -> V_149 . V_142 ;
V_6 -> V_73 . V_150 . V_143 = V_101 -> V_149 . V_144 ;
}
F_86 ( V_104 , V_6 , V_151 ) ;
F_87 ( V_152 ) ;
if ( V_67 -> V_112 & V_153 )
F_88 ( V_104 ) ;
error = F_89 ( V_104 , 0 ) ;
F_90 ( V_6 , V_125 ) ;
F_91 ( V_110 ) ;
F_91 ( V_111 ) ;
F_91 ( V_108 ) ;
F_91 ( V_109 ) ;
if ( error )
return F_58 ( error ) ;
if ( ( V_102 & V_136 ) && ! ( V_27 & V_154 ) ) {
error = - F_92 ( V_1 ) ;
if ( error )
return F_58 ( error ) ;
}
return 0 ;
V_128:
F_93 ( V_104 , 0 ) ;
F_90 ( V_6 , V_125 ) ;
V_124:
F_91 ( V_108 ) ;
F_91 ( V_109 ) ;
return error ;
}
int
F_94 (
struct V_5 * V_6 ,
struct V_101 * V_101 ,
int V_27 )
{
struct V_66 * V_67 = V_6 -> V_68 ;
struct V_1 * V_1 = F_23 ( V_6 ) ;
int V_102 = V_101 -> V_103 ;
T_8 V_155 , V_156 ;
struct V_157 * V_104 ;
int error ;
T_7 V_158 = 0 ;
T_7 V_159 = 0 ;
F_68 ( V_6 ) ;
if ( V_67 -> V_112 & V_113 )
return F_58 ( V_114 ) ;
if ( F_57 ( V_67 ) )
return F_58 ( V_69 ) ;
error = - F_69 ( V_1 , V_101 ) ;
if ( error )
return F_58 ( error ) ;
ASSERT ( F_95 ( V_6 -> V_73 . V_74 ) ) ;
ASSERT ( ( V_102 & ( V_136 | V_116 | V_117 | V_138 | V_160 |
V_161 | V_162 | V_163 |
V_164 | V_165 ) ) == 0 ) ;
if ( ! ( V_27 & V_166 ) ) {
V_158 |= V_167 ;
F_78 ( V_6 , V_158 ) ;
}
V_155 = V_1 -> V_168 ;
V_156 = V_101 -> V_169 ;
if ( V_156 == 0 && V_155 == 0 && V_6 -> V_73 . V_170 == 0 ) {
if ( ! ( V_102 & ( V_145 | V_148 ) ) )
goto V_171;
F_90 ( V_6 , V_158 ) ;
V_101 -> V_103 &= ~ V_115 ;
return F_67 ( V_6 , V_101 , 0 ) ;
}
error = F_96 ( V_6 , 0 ) ;
if ( error )
goto V_171;
if ( V_156 > V_155 ) {
error = F_97 ( V_6 , V_156 , V_155 ) ;
if ( error )
goto V_171;
}
if ( V_155 != V_6 -> V_73 . V_172 && V_156 > V_6 -> V_73 . V_172 ) {
error = - F_98 ( F_23 ( V_6 ) -> V_173 ,
V_6 -> V_73 . V_172 , V_156 ) ;
if ( error )
goto V_171;
}
F_99 ( V_1 ) ;
error = - F_100 ( V_1 -> V_173 , V_156 , V_174 ) ;
if ( error )
goto V_171;
V_104 = F_75 ( V_67 , V_175 ) ;
error = F_76 ( V_104 , 0 , F_101 ( V_67 ) , 0 ,
V_176 ,
V_177 ) ;
if ( error )
goto V_128;
F_102 ( V_1 , V_156 ) ;
V_159 = V_178 ;
V_158 |= V_125 ;
F_78 ( V_6 , V_125 ) ;
F_82 ( V_104 , V_6 , 0 ) ;
if ( V_156 != V_155 && ( ! ( V_102 & ( V_145 | V_148 ) ) ) ) {
V_101 -> V_146 = V_101 -> V_149 =
F_103 ( V_1 -> V_38 ) ;
V_102 |= V_145 | V_148 ;
}
V_6 -> V_73 . V_172 = V_156 ;
F_86 ( V_104 , V_6 , V_151 ) ;
if ( V_156 <= V_155 ) {
error = F_104 ( & V_104 , V_6 , V_179 , V_156 ) ;
if ( error )
goto V_180;
F_105 ( V_6 , V_181 ) ;
F_106 ( V_6 ) ;
}
if ( V_102 & V_145 ) {
V_1 -> V_87 = V_101 -> V_146 ;
V_6 -> V_73 . V_147 . V_141 = V_101 -> V_146 . V_142 ;
V_6 -> V_73 . V_147 . V_143 = V_101 -> V_146 . V_144 ;
}
if ( V_102 & V_148 ) {
V_1 -> V_86 = V_101 -> V_149 ;
V_6 -> V_73 . V_150 . V_141 = V_101 -> V_149 . V_142 ;
V_6 -> V_73 . V_150 . V_143 = V_101 -> V_149 . V_144 ;
}
F_86 ( V_104 , V_6 , V_151 ) ;
F_87 ( V_152 ) ;
if ( V_67 -> V_112 & V_153 )
F_88 ( V_104 ) ;
error = F_89 ( V_104 , V_178 ) ;
V_171:
if ( V_158 )
F_90 ( V_6 , V_158 ) ;
return error ;
V_180:
V_159 |= V_182 ;
V_128:
F_93 ( V_104 , V_159 ) ;
goto V_171;
}
STATIC int
F_107 (
struct V_15 * V_15 ,
struct V_101 * V_101 )
{
if ( V_101 -> V_103 & V_115 )
return - F_94 ( F_2 ( V_15 -> V_37 ) , V_101 , 0 ) ;
return - F_67 ( F_2 ( V_15 -> V_37 ) , V_101 , 0 ) ;
}
STATIC int
F_108 (
struct V_1 * V_1 ,
struct V_183 * V_184 ,
int V_27 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_66 * V_67 = V_6 -> V_68 ;
struct V_157 * V_104 ;
int error ;
F_109 ( V_6 ) ;
V_104 = F_75 ( V_67 , V_185 ) ;
error = F_76 ( V_104 , 0 , F_110 ( V_67 ) , 0 , 0 , 0 ) ;
if ( error ) {
F_93 ( V_104 , 0 ) ;
return - error ;
}
F_78 ( V_6 , V_125 ) ;
if ( V_27 & V_186 ) {
V_1 -> V_87 = * V_184 ;
V_6 -> V_73 . V_147 . V_141 = ( V_187 ) V_184 -> V_142 ;
V_6 -> V_73 . V_147 . V_143 = ( V_187 ) V_184 -> V_144 ;
}
if ( V_27 & V_188 ) {
V_1 -> V_86 = * V_184 ;
V_6 -> V_73 . V_150 . V_141 = ( V_187 ) V_184 -> V_142 ;
V_6 -> V_73 . V_150 . V_143 = ( V_187 ) V_184 -> V_144 ;
}
if ( V_27 & V_189 ) {
V_1 -> V_84 = * V_184 ;
V_6 -> V_73 . V_140 . V_141 = ( V_187 ) V_184 -> V_142 ;
V_6 -> V_73 . V_140 . V_143 = ( V_187 ) V_184 -> V_144 ;
}
F_82 ( V_104 , V_6 , V_125 ) ;
F_86 ( V_104 , V_6 , V_190 ) ;
return - F_89 ( V_104 , 0 ) ;
}
STATIC int
F_111 (
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
V_198 = F_112 ( V_193 -> V_202 ) ;
V_199 = F_112 ( V_193 -> V_201 ) ;
V_200 = F_112 ( V_193 -> V_203 ) ;
if ( V_193 -> V_204 & V_205 )
V_197 |= V_206 ;
else if ( V_193 -> V_204 & V_207 ) {
V_197 |= V_208 ;
V_199 = 0 ;
}
if ( V_193 -> V_204 & V_209 )
V_197 |= V_210 ;
error = F_113 ( V_196 , V_198 , V_199 ,
V_200 , V_197 ) ;
if ( error > 0 ) {
error = 0 ;
* V_194 = 1 ;
}
return - error ;
}
STATIC int
F_114 (
struct V_1 * V_1 ,
struct V_195 * V_196 ,
T_10 V_211 ,
T_10 V_200 )
{
T_11 * V_6 = F_2 ( V_1 ) ;
struct V_192 V_212 ;
int error ;
error = F_115 ( V_196 , V_213 ) ;
if ( error )
return error ;
V_212 . V_202 = F_116 ( V_211 ) ;
if ( V_200 == V_214 )
V_212 . V_203 = - 1LL ;
else
V_212 . V_203 = F_116 ( V_200 ) ;
V_212 . V_215 = ! V_196 -> V_216 ? V_217 :
V_196 -> V_216 + 1 ;
V_212 . V_215 = F_117 ( V_218 , V_212 . V_215 ,
( V_219 * 16 / sizeof( struct V_192 ) ) ) ;
V_212 . V_220 = V_221 | V_222 ;
if ( V_196 -> V_223 & V_224 )
V_212 . V_220 |= V_225 ;
if ( ! ( V_196 -> V_223 & V_226 ) )
V_212 . V_220 |= V_227 ;
error = F_118 ( V_6 , & V_212 , F_111 , V_196 ) ;
if ( error )
return - error ;
return 0 ;
}
STATIC void
F_119 (
struct V_1 * V_1 ,
struct V_5 * V_6 )
{
if ( V_6 -> V_73 . V_228 & V_229 )
V_1 -> V_230 |= V_231 ;
else
V_1 -> V_230 &= ~ V_231 ;
if ( V_6 -> V_73 . V_228 & V_232 )
V_1 -> V_230 |= V_233 ;
else
V_1 -> V_230 &= ~ V_233 ;
if ( V_6 -> V_73 . V_228 & V_234 )
V_1 -> V_230 |= V_235 ;
else
V_1 -> V_230 &= ~ V_235 ;
if ( V_6 -> V_73 . V_228 & V_236 )
V_1 -> V_230 |= V_237 ;
else
V_1 -> V_230 &= ~ V_237 ;
}
void
F_120 (
struct V_5 * V_6 )
{
struct V_1 * V_1 = & V_6 -> V_238 ;
V_1 -> V_82 = V_6 -> V_82 ;
V_1 -> V_239 = V_240 ;
F_121 ( V_1 ) ;
F_122 ( & V_1 -> V_241 ) ;
V_1 -> V_91 = V_6 -> V_73 . V_74 ;
F_123 ( V_1 , V_6 -> V_73 . V_76 ) ;
V_1 -> V_133 = V_6 -> V_73 . V_78 ;
V_1 -> V_135 = V_6 -> V_73 . V_80 ;
switch ( V_1 -> V_91 & V_92 ) {
case V_93 :
case V_94 :
V_1 -> V_242 =
F_61 ( F_62 ( V_6 -> V_97 . V_98 . V_99 ) & 0x1ff ,
F_63 ( V_6 -> V_97 . V_98 . V_99 ) ) ;
break;
default:
V_1 -> V_242 = 0 ;
break;
}
V_1 -> V_243 = V_6 -> V_73 . V_244 ;
F_124 ( V_1 , V_6 -> V_73 . V_172 ) ;
V_1 -> V_84 . V_142 = V_6 -> V_73 . V_140 . V_141 ;
V_1 -> V_84 . V_144 = V_6 -> V_73 . V_140 . V_143 ;
V_1 -> V_86 . V_142 = V_6 -> V_73 . V_150 . V_141 ;
V_1 -> V_86 . V_144 = V_6 -> V_73 . V_150 . V_143 ;
V_1 -> V_87 . V_142 = V_6 -> V_73 . V_147 . V_141 ;
V_1 -> V_87 . V_144 = V_6 -> V_73 . V_147 . V_143 ;
F_119 ( V_1 , V_6 ) ;
switch ( V_1 -> V_91 & V_92 ) {
case V_245 :
V_1 -> V_246 = & V_247 ;
V_1 -> V_248 = & V_249 ;
V_1 -> V_173 -> V_250 = & V_251 ;
break;
case V_28 :
if ( F_41 ( & F_42 ( V_1 -> V_38 ) -> V_39 ) )
V_1 -> V_246 = & V_252 ;
else
V_1 -> V_246 = & V_253 ;
V_1 -> V_248 = & V_254 ;
break;
case V_41 :
V_1 -> V_246 = & V_255 ;
if ( ! ( V_6 -> V_97 . V_256 & V_257 ) )
V_1 -> V_173 -> V_250 = & V_251 ;
break;
default:
V_1 -> V_246 = & V_247 ;
F_125 ( V_1 , V_1 -> V_91 , V_1 -> V_242 ) ;
break;
}
if ( ! F_126 ( V_6 ) ) {
F_127 ( V_1 ) ;
F_128 ( V_1 ) ;
}
F_129 ( V_6 , V_258 ) ;
F_130 () ;
F_131 ( V_1 ) ;
}
