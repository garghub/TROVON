void
F_1 (
T_1 * V_1 )
{
struct V_2 * V_2 = F_2 ( V_1 ) ;
V_1 -> V_3 . V_4 . V_5 = ( V_6 ) V_2 -> V_7 . V_8 ;
V_1 -> V_3 . V_4 . V_9 = ( V_6 ) V_2 -> V_7 . V_10 ;
V_1 -> V_3 . V_11 . V_5 = ( V_6 ) V_2 -> V_12 . V_8 ;
V_1 -> V_3 . V_11 . V_9 = ( V_6 ) V_2 -> V_12 . V_10 ;
V_1 -> V_3 . V_13 . V_5 = ( V_6 ) V_2 -> V_14 . V_8 ;
V_1 -> V_3 . V_13 . V_9 = ( V_6 ) V_2 -> V_14 . V_10 ;
}
void
F_3 (
T_1 * V_1 )
{
struct V_2 * V_2 = F_2 ( V_1 ) ;
if ( ! ( V_2 -> V_15 & ( V_16 | V_17 ) ) )
F_4 ( V_2 ) ;
else {
F_5 () ;
V_1 -> V_18 = 1 ;
}
}
void
F_6 (
T_1 * V_1 )
{
struct V_2 * V_2 = F_2 ( V_1 ) ;
if ( ! ( V_2 -> V_15 & ( V_16 | V_17 ) ) )
F_7 ( V_2 ) ;
else {
F_5 () ;
V_1 -> V_18 = 1 ;
}
}
int F_8 ( struct V_2 * V_2 , const struct V_19 * V_20 ,
void * V_21 )
{
const struct V_19 * V_19 ;
struct V_22 * V_1 = F_9 ( V_2 ) ;
int error = 0 ;
for ( V_19 = V_20 ; V_19 -> V_23 != NULL ; V_19 ++ ) {
error = F_10 ( V_1 , V_19 -> V_23 , V_19 -> V_24 ,
V_19 -> V_25 , V_26 ) ;
if ( error < 0 )
break;
}
return error ;
}
STATIC int
F_11 (
struct V_2 * V_2 ,
struct V_2 * V_27 ,
const struct V_28 * V_28 )
{
return F_12 ( V_2 , V_27 , V_28 ,
& F_8 , NULL ) ;
}
static void
F_13 (
struct V_29 * V_30 ,
struct V_31 * V_31 )
{
V_30 -> V_23 = V_31 -> V_32 . V_23 ;
V_30 -> V_33 = V_31 -> V_32 . V_33 ;
}
STATIC void
F_14 (
struct V_2 * V_27 ,
struct V_2 * V_2 ,
struct V_31 * V_31 )
{
struct V_29 V_34 ;
F_13 ( & V_34 , V_31 ) ;
F_15 ( F_9 ( V_27 ) , & V_34 , F_9 ( V_2 ) ) ;
F_16 ( V_2 ) ;
}
STATIC int
F_17 (
struct V_2 * V_27 ,
struct V_31 * V_31 ,
T_2 V_35 ,
T_3 V_36 )
{
struct V_2 * V_2 ;
struct V_22 * V_1 = NULL ;
struct V_37 * V_38 = NULL ;
struct V_29 V_23 ;
int error ;
if ( F_18 ( V_35 ) || F_19 ( V_35 ) ) {
if ( F_20 ( ! F_21 ( V_36 ) || F_22 ( V_36 ) & ~ 0x1ff ) )
return - V_39 ;
V_36 = F_23 ( V_36 ) ;
} else {
V_36 = 0 ;
}
if ( F_24 ( V_27 ) ) {
V_38 = F_25 ( V_27 , V_40 ) ;
if ( F_26 ( V_38 ) )
return F_27 ( V_38 ) ;
if ( ! V_38 )
V_35 &= ~ F_28 () ;
}
F_13 ( & V_23 , V_31 ) ;
error = F_29 ( F_9 ( V_27 ) , & V_23 , V_35 , V_36 , & V_1 ) ;
if ( F_20 ( error ) )
goto V_41;
V_2 = F_2 ( V_1 ) ;
error = F_11 ( V_2 , V_27 , & V_31 -> V_32 ) ;
if ( F_20 ( error ) )
goto V_42;
if ( V_38 ) {
error = - F_30 ( V_2 , V_38 ) ;
V_38 = NULL ;
if ( F_20 ( error ) )
goto V_42;
}
F_31 ( V_31 , V_2 ) ;
return - error ;
V_42:
F_14 ( V_27 , V_2 , V_31 ) ;
V_41:
F_32 ( V_38 ) ;
return - error ;
}
STATIC int
F_33 (
struct V_2 * V_27 ,
struct V_31 * V_31 ,
T_2 V_35 ,
struct V_43 * V_44 )
{
return F_17 ( V_27 , V_31 , V_35 , 0 ) ;
}
STATIC int
F_34 (
struct V_2 * V_27 ,
struct V_31 * V_31 ,
T_2 V_35 )
{
return F_17 ( V_27 , V_31 , V_35 | V_45 , 0 ) ;
}
STATIC struct V_31 *
F_35 (
struct V_2 * V_27 ,
struct V_31 * V_31 ,
struct V_43 * V_44 )
{
struct V_22 * V_46 ;
struct V_29 V_23 ;
int error ;
if ( V_31 -> V_32 . V_33 >= V_47 )
return F_36 ( - V_48 ) ;
F_13 ( & V_23 , V_31 ) ;
error = F_37 ( F_9 ( V_27 ) , & V_23 , & V_46 , NULL ) ;
if ( F_20 ( error ) ) {
if ( F_20 ( error != V_49 ) )
return F_36 ( - error ) ;
F_38 ( V_31 , NULL ) ;
return NULL ;
}
return F_39 ( F_2 ( V_46 ) , V_31 ) ;
}
STATIC struct V_31 *
F_40 (
struct V_2 * V_27 ,
struct V_31 * V_31 ,
struct V_43 * V_44 )
{
struct V_22 * V_1 ;
struct V_29 V_50 ;
struct V_29 V_51 ;
struct V_28 V_52 ;
int error ;
if ( V_31 -> V_32 . V_33 >= V_47 )
return F_36 ( - V_48 ) ;
F_13 ( & V_50 , V_31 ) ;
error = F_37 ( F_9 ( V_27 ) , & V_50 , & V_1 , & V_51 ) ;
if ( F_20 ( error ) ) {
if ( F_20 ( error != V_49 ) )
return F_36 ( - error ) ;
return NULL ;
}
if ( ! V_51 . V_23 )
return F_39 ( F_2 ( V_1 ) , V_31 ) ;
V_52 . V_23 = V_51 . V_23 ;
V_52 . V_33 = V_51 . V_33 ;
V_31 = F_41 ( V_31 , F_2 ( V_1 ) , & V_52 ) ;
F_42 ( V_51 . V_23 ) ;
return V_31 ;
}
STATIC int
F_43 (
struct V_31 * V_53 ,
struct V_2 * V_27 ,
struct V_31 * V_31 )
{
struct V_2 * V_2 = V_53 -> V_54 ;
struct V_29 V_23 ;
int error ;
F_13 ( & V_23 , V_31 ) ;
error = F_44 ( F_9 ( V_27 ) , F_9 ( V_2 ) , & V_23 ) ;
if ( F_20 ( error ) )
return - error ;
F_45 ( V_2 ) ;
F_31 ( V_31 , V_2 ) ;
return 0 ;
}
STATIC int
F_46 (
struct V_2 * V_27 ,
struct V_31 * V_31 )
{
struct V_29 V_23 ;
int error ;
F_13 ( & V_23 , V_31 ) ;
error = - F_15 ( F_9 ( V_27 ) , & V_23 , F_9 ( V_31 -> V_54 ) ) ;
if ( error )
return error ;
if ( F_47 ( & F_48 ( V_27 -> V_55 ) -> V_56 ) )
F_49 ( V_31 ) ;
return 0 ;
}
STATIC int
F_50 (
struct V_2 * V_27 ,
struct V_31 * V_31 ,
const char * V_57 )
{
struct V_2 * V_2 ;
struct V_22 * V_46 = NULL ;
struct V_29 V_23 ;
int error ;
T_2 V_35 ;
V_35 = V_58 |
( V_59 ? 0777 & ~ F_28 () : V_60 ) ;
F_13 ( & V_23 , V_31 ) ;
error = F_51 ( F_9 ( V_27 ) , & V_23 , V_57 , V_35 , & V_46 ) ;
if ( F_20 ( error ) )
goto V_61;
V_2 = F_2 ( V_46 ) ;
error = F_11 ( V_2 , V_27 , & V_31 -> V_32 ) ;
if ( F_20 ( error ) )
goto V_42;
F_31 ( V_31 , V_2 ) ;
return 0 ;
V_42:
F_14 ( V_27 , V_2 , V_31 ) ;
V_61:
return - error ;
}
STATIC int
F_52 (
struct V_2 * V_62 ,
struct V_31 * V_63 ,
struct V_2 * V_64 ,
struct V_31 * V_65 )
{
struct V_2 * V_66 = V_65 -> V_54 ;
struct V_29 V_67 ;
struct V_29 V_68 ;
F_13 ( & V_67 , V_63 ) ;
F_13 ( & V_68 , V_65 ) ;
return - F_53 ( F_9 ( V_62 ) , & V_67 , F_9 ( V_63 -> V_54 ) ,
F_9 ( V_64 ) , & V_68 , V_66 ?
F_9 ( V_66 ) : NULL ) ;
}
STATIC void *
F_54 (
struct V_31 * V_31 ,
struct V_43 * V_44 )
{
char * V_69 ;
int error = - V_70 ;
V_69 = F_55 ( V_71 + 1 , V_72 ) ;
if ( ! V_69 )
goto V_73;
error = - F_56 ( F_9 ( V_31 -> V_54 ) , V_69 ) ;
if ( F_20 ( error ) )
goto V_74;
F_57 ( V_44 , V_69 ) ;
return NULL ;
V_74:
F_58 ( V_69 ) ;
V_73:
F_57 ( V_44 , F_36 ( error ) ) ;
return NULL ;
}
STATIC void
F_59 (
struct V_31 * V_31 ,
struct V_43 * V_44 ,
void * V_75 )
{
char * V_76 = F_60 ( V_44 ) ;
if ( ! F_26 ( V_76 ) )
F_58 ( V_76 ) ;
}
STATIC int
F_61 (
struct V_77 * V_78 ,
struct V_31 * V_31 ,
struct V_79 * V_80 )
{
struct V_2 * V_2 = V_31 -> V_54 ;
struct V_22 * V_1 = F_9 ( V_2 ) ;
struct V_81 * V_82 = V_1 -> V_83 ;
F_62 ( V_1 ) ;
if ( F_63 ( V_82 ) )
return - F_64 ( V_84 ) ;
V_80 -> V_85 = F_65 ( V_1 ) ;
V_80 -> V_86 = V_2 -> V_55 -> V_87 ;
V_80 -> V_35 = V_1 -> V_3 . V_88 ;
V_80 -> V_89 = V_1 -> V_3 . V_90 ;
V_80 -> V_91 = V_1 -> V_3 . V_92 ;
V_80 -> V_93 = V_1 -> V_3 . V_94 ;
V_80 -> V_95 = V_1 -> V_96 ;
V_80 -> V_97 = V_2 -> V_7 ;
V_80 -> V_98 = V_2 -> V_14 ;
V_80 -> ctime = V_2 -> V_12 ;
V_80 -> V_99 =
F_66 ( V_82 , V_1 -> V_3 . V_100 + V_1 -> V_101 ) ;
switch ( V_2 -> V_102 & V_103 ) {
case V_104 :
case V_105 :
V_80 -> V_106 = V_107 ;
V_80 -> V_36 = F_67 ( F_68 ( V_1 -> V_108 . V_109 . V_110 ) & 0x1ff ,
F_69 ( V_1 -> V_108 . V_109 . V_110 ) ) ;
break;
default:
if ( F_70 ( V_1 ) ) {
V_80 -> V_106 =
F_71 ( V_1 ) << V_82 -> V_56 . V_111 ;
} else
V_80 -> V_106 = F_72 ( V_82 ) ;
V_80 -> V_36 = 0 ;
break;
}
return 0 ;
}
int
F_73 (
struct V_22 * V_1 ,
struct V_112 * V_112 ,
int V_113 )
{
T_4 * V_82 = V_1 -> V_83 ;
struct V_2 * V_2 = F_2 ( V_1 ) ;
int V_114 = V_112 -> V_115 ;
T_5 * V_116 ;
int error ;
T_6 V_91 = 0 , V_117 = 0 ;
T_7 V_93 = 0 , V_118 = 0 ;
struct V_119 * V_120 = NULL , * V_121 = NULL ;
struct V_119 * V_122 = NULL , * V_123 = NULL ;
F_74 ( V_1 ) ;
if ( V_82 -> V_124 & V_125 )
return F_64 ( V_126 ) ;
if ( F_63 ( V_82 ) )
return F_64 ( V_84 ) ;
error = - F_75 ( V_2 , V_112 ) ;
if ( error )
return F_64 ( error ) ;
ASSERT ( ( V_114 & V_127 ) == 0 ) ;
if ( F_76 ( V_82 ) && ( V_114 & ( V_128 | V_129 ) ) ) {
T_8 V_130 = 0 ;
if ( ( V_114 & V_128 ) && F_77 ( V_82 ) ) {
V_91 = V_112 -> V_131 ;
V_130 |= V_132 ;
} else {
V_91 = V_1 -> V_3 . V_92 ;
}
if ( ( V_114 & V_129 ) && F_78 ( V_82 ) ) {
V_93 = V_112 -> V_133 ;
V_130 |= V_134 ;
} else {
V_93 = V_1 -> V_3 . V_94 ;
}
ASSERT ( V_120 == NULL ) ;
ASSERT ( V_121 == NULL ) ;
error = F_79 ( V_1 , V_91 , V_93 , F_80 ( V_1 ) ,
V_130 , & V_120 , & V_121 ) ;
if ( error )
return error ;
}
V_116 = F_81 ( V_82 , V_135 ) ;
error = F_82 ( V_116 , 0 , F_83 ( V_82 ) , 0 , 0 , 0 ) ;
if ( error )
goto V_136;
F_84 ( V_1 , V_137 ) ;
if ( V_114 & ( V_128 | V_129 ) ) {
V_117 = V_1 -> V_3 . V_92 ;
V_118 = V_1 -> V_3 . V_94 ;
V_93 = ( V_114 & V_129 ) ? V_112 -> V_133 : V_118 ;
V_91 = ( V_114 & V_128 ) ? V_112 -> V_131 : V_117 ;
if ( F_85 ( V_82 ) &&
( ( F_77 ( V_82 ) && V_117 != V_91 ) ||
( F_78 ( V_82 ) && V_118 != V_93 ) ) ) {
ASSERT ( V_116 ) ;
error = F_86 ( V_116 , V_1 , V_120 , V_121 ,
F_87 ( V_138 ) ?
V_139 : 0 ) ;
if ( error )
goto V_140;
}
}
F_88 ( V_116 , V_1 , 0 ) ;
if ( V_114 & ( V_128 | V_129 ) ) {
if ( ( V_1 -> V_3 . V_88 & ( V_141 | V_142 ) ) &&
! F_87 ( V_143 ) )
V_1 -> V_3 . V_88 &= ~ ( V_141 | V_142 ) ;
if ( V_117 != V_91 ) {
if ( F_85 ( V_82 ) && F_77 ( V_82 ) ) {
ASSERT ( V_114 & V_128 ) ;
ASSERT ( V_120 ) ;
V_122 = F_89 ( V_116 , V_1 ,
& V_1 -> V_144 , V_120 ) ;
}
V_1 -> V_3 . V_92 = V_91 ;
V_2 -> V_145 = V_91 ;
}
if ( V_118 != V_93 ) {
if ( F_85 ( V_82 ) && F_78 ( V_82 ) ) {
ASSERT ( ! F_90 ( V_82 ) ) ;
ASSERT ( V_114 & V_129 ) ;
ASSERT ( V_121 ) ;
V_123 = F_89 ( V_116 , V_1 ,
& V_1 -> V_146 , V_121 ) ;
}
V_1 -> V_3 . V_94 = V_93 ;
V_2 -> V_147 = V_93 ;
}
}
if ( V_114 & V_148 ) {
T_2 V_35 = V_112 -> V_149 ;
if ( ! F_91 ( V_2 -> V_147 ) && ! F_87 ( V_143 ) )
V_35 &= ~ V_142 ;
V_1 -> V_3 . V_88 &= V_103 ;
V_1 -> V_3 . V_88 |= V_35 & ~ V_103 ;
V_2 -> V_102 &= V_103 ;
V_2 -> V_102 |= V_35 & ~ V_103 ;
}
if ( V_114 & V_150 ) {
V_2 -> V_7 = V_112 -> V_151 ;
V_1 -> V_3 . V_4 . V_5 = V_112 -> V_151 . V_8 ;
V_1 -> V_3 . V_4 . V_9 = V_112 -> V_151 . V_10 ;
V_1 -> V_18 = 1 ;
}
if ( V_114 & V_152 ) {
V_2 -> V_12 = V_112 -> V_153 ;
V_1 -> V_3 . V_11 . V_5 = V_112 -> V_153 . V_8 ;
V_1 -> V_3 . V_11 . V_9 = V_112 -> V_153 . V_10 ;
V_1 -> V_18 = 1 ;
}
if ( V_114 & V_154 ) {
V_2 -> V_14 = V_112 -> V_155 ;
V_1 -> V_3 . V_13 . V_5 = V_112 -> V_155 . V_8 ;
V_1 -> V_3 . V_13 . V_9 = V_112 -> V_155 . V_10 ;
V_1 -> V_18 = 1 ;
}
F_92 ( V_116 , V_1 , V_156 ) ;
F_93 ( V_157 ) ;
if ( V_82 -> V_124 & V_158 )
F_94 ( V_116 ) ;
error = F_95 ( V_116 , 0 ) ;
F_96 ( V_1 , V_137 ) ;
F_97 ( V_122 ) ;
F_97 ( V_123 ) ;
F_97 ( V_120 ) ;
F_97 ( V_121 ) ;
if ( error )
return F_64 ( error ) ;
if ( ( V_114 & V_148 ) && ! ( V_113 & V_159 ) ) {
error = - F_98 ( V_2 ) ;
if ( error )
return F_64 ( error ) ;
}
return 0 ;
V_140:
F_99 ( V_116 , 0 ) ;
F_96 ( V_1 , V_137 ) ;
V_136:
F_97 ( V_120 ) ;
F_97 ( V_121 ) ;
return error ;
}
int
F_100 (
struct V_22 * V_1 ,
struct V_112 * V_112 ,
int V_113 )
{
struct V_81 * V_82 = V_1 -> V_83 ;
struct V_2 * V_2 = F_2 ( V_1 ) ;
int V_114 = V_112 -> V_115 ;
T_9 V_160 , V_161 ;
struct V_162 * V_116 ;
int error ;
T_8 V_163 ;
T_8 V_164 = 0 ;
F_74 ( V_1 ) ;
if ( V_82 -> V_124 & V_125 )
return F_64 ( V_126 ) ;
if ( F_63 ( V_82 ) )
return F_64 ( V_84 ) ;
error = - F_75 ( V_2 , V_112 ) ;
if ( error )
return F_64 ( error ) ;
ASSERT ( F_101 ( V_1 -> V_3 . V_88 ) ) ;
ASSERT ( ( V_114 & ( V_148 | V_128 | V_129 | V_150 | V_165 |
V_166 | V_167 | V_168 |
V_169 | V_170 ) ) == 0 ) ;
V_163 = V_137 ;
if ( ! ( V_113 & V_171 ) )
V_163 |= V_172 ;
F_84 ( V_1 , V_163 ) ;
V_160 = V_2 -> V_173 ;
V_161 = V_112 -> V_174 ;
if ( V_161 == 0 && V_160 == 0 && V_1 -> V_3 . V_175 == 0 ) {
if ( ! ( V_114 & ( V_152 | V_154 ) ) )
goto V_176;
F_96 ( V_1 , V_163 ) ;
V_112 -> V_115 &= ~ V_127 ;
return F_73 ( V_1 , V_112 , 0 ) ;
}
error = F_102 ( V_1 , 0 ) ;
if ( error )
goto V_176;
if ( V_161 > V_160 ) {
error = F_103 ( V_1 , V_161 , V_160 ) ;
if ( error )
goto V_176;
}
F_96 ( V_1 , V_137 ) ;
V_163 &= ~ V_137 ;
if ( V_160 != V_1 -> V_3 . V_177 && V_161 > V_1 -> V_3 . V_177 ) {
error = F_104 ( V_1 , V_1 -> V_3 . V_177 , V_161 , 0 ,
V_178 ) ;
if ( error )
goto V_176;
}
F_105 ( V_2 ) ;
error = - F_106 ( V_2 -> V_179 , V_161 , V_180 ) ;
if ( error )
goto V_176;
V_116 = F_81 ( V_82 , V_181 ) ;
error = F_82 ( V_116 , 0 , F_107 ( V_82 ) , 0 ,
V_182 ,
V_183 ) ;
if ( error )
goto V_140;
F_108 ( V_2 , V_161 ) ;
V_164 = V_184 ;
V_163 |= V_137 ;
F_84 ( V_1 , V_137 ) ;
F_88 ( V_116 , V_1 , 0 ) ;
if ( V_161 != V_160 && ( ! ( V_114 & ( V_152 | V_154 ) ) ) ) {
V_112 -> V_153 = V_112 -> V_155 =
F_109 ( V_2 -> V_55 ) ;
V_114 |= V_152 | V_154 ;
}
V_1 -> V_3 . V_177 = V_161 ;
F_92 ( V_116 , V_1 , V_156 ) ;
if ( V_161 <= V_160 ) {
error = F_110 ( & V_116 , V_1 , V_185 , V_161 ) ;
if ( error )
goto V_186;
F_111 ( V_1 , V_187 ) ;
}
if ( V_114 & V_152 ) {
V_2 -> V_12 = V_112 -> V_153 ;
V_1 -> V_3 . V_11 . V_5 = V_112 -> V_153 . V_8 ;
V_1 -> V_3 . V_11 . V_9 = V_112 -> V_153 . V_10 ;
V_1 -> V_18 = 1 ;
}
if ( V_114 & V_154 ) {
V_2 -> V_14 = V_112 -> V_155 ;
V_1 -> V_3 . V_13 . V_5 = V_112 -> V_155 . V_8 ;
V_1 -> V_3 . V_13 . V_9 = V_112 -> V_155 . V_10 ;
V_1 -> V_18 = 1 ;
}
F_92 ( V_116 , V_1 , V_156 ) ;
F_93 ( V_157 ) ;
if ( V_82 -> V_124 & V_158 )
F_94 ( V_116 ) ;
error = F_95 ( V_116 , V_184 ) ;
V_176:
if ( V_163 )
F_96 ( V_1 , V_163 ) ;
return error ;
V_186:
V_164 |= V_188 ;
V_140:
F_99 ( V_116 , V_164 ) ;
goto V_176;
}
STATIC int
F_112 (
struct V_31 * V_31 ,
struct V_112 * V_112 )
{
if ( V_112 -> V_115 & V_127 )
return - F_100 ( F_9 ( V_31 -> V_54 ) , V_112 , 0 ) ;
return - F_73 ( F_9 ( V_31 -> V_54 ) , V_112 , 0 ) ;
}
STATIC int
F_113 (
void * * V_189 ,
struct V_190 * V_191 ,
int * V_192 )
{
int error ;
struct V_193 * V_194 = * V_189 ;
T_10 V_195 = 0 ;
T_11 V_196 , V_197 , V_198 ;
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
struct V_2 * V_2 ,
struct V_193 * V_194 ,
T_11 V_209 ,
T_11 V_198 )
{
T_1 * V_1 = F_9 ( V_2 ) ;
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
error = F_120 ( V_1 , & V_210 , F_113 , V_194 ) ;
if ( error )
return - error ;
return 0 ;
}
STATIC void
F_121 (
struct V_2 * V_2 ,
struct V_22 * V_1 )
{
if ( V_1 -> V_3 . V_226 & V_227 )
V_2 -> V_228 |= V_229 ;
else
V_2 -> V_228 &= ~ V_229 ;
if ( V_1 -> V_3 . V_226 & V_230 )
V_2 -> V_228 |= V_231 ;
else
V_2 -> V_228 &= ~ V_231 ;
if ( V_1 -> V_3 . V_226 & V_232 )
V_2 -> V_228 |= V_233 ;
else
V_2 -> V_228 &= ~ V_233 ;
if ( V_1 -> V_3 . V_226 & V_234 )
V_2 -> V_228 |= V_235 ;
else
V_2 -> V_228 &= ~ V_235 ;
}
void
F_122 (
struct V_22 * V_1 )
{
struct V_2 * V_2 = & V_1 -> V_236 ;
V_2 -> V_96 = V_1 -> V_96 ;
V_2 -> V_15 = V_237 ;
F_123 ( V_2 ) ;
F_124 ( & V_2 -> V_238 ) ;
V_2 -> V_102 = V_1 -> V_3 . V_88 ;
F_125 ( V_2 , V_1 -> V_3 . V_90 ) ;
V_2 -> V_145 = V_1 -> V_3 . V_92 ;
V_2 -> V_147 = V_1 -> V_3 . V_94 ;
switch ( V_2 -> V_102 & V_103 ) {
case V_104 :
case V_105 :
V_2 -> V_239 =
F_67 ( F_68 ( V_1 -> V_108 . V_109 . V_110 ) & 0x1ff ,
F_69 ( V_1 -> V_108 . V_109 . V_110 ) ) ;
break;
default:
V_2 -> V_239 = 0 ;
break;
}
V_2 -> V_240 = V_1 -> V_3 . V_241 ;
F_126 ( V_2 , V_1 -> V_3 . V_177 ) ;
V_2 -> V_7 . V_8 = V_1 -> V_3 . V_4 . V_5 ;
V_2 -> V_7 . V_10 = V_1 -> V_3 . V_4 . V_9 ;
V_2 -> V_14 . V_8 = V_1 -> V_3 . V_13 . V_5 ;
V_2 -> V_14 . V_10 = V_1 -> V_3 . V_13 . V_9 ;
V_2 -> V_12 . V_8 = V_1 -> V_3 . V_11 . V_5 ;
V_2 -> V_12 . V_10 = V_1 -> V_3 . V_11 . V_9 ;
F_121 ( V_2 , V_1 ) ;
switch ( V_2 -> V_102 & V_103 ) {
case V_242 :
V_2 -> V_243 = & V_244 ;
V_2 -> V_245 = & V_246 ;
V_2 -> V_179 -> V_247 = & V_248 ;
break;
case V_45 :
if ( F_47 ( & F_48 ( V_2 -> V_55 ) -> V_56 ) )
V_2 -> V_243 = & V_249 ;
else
V_2 -> V_243 = & V_250 ;
V_2 -> V_245 = & V_251 ;
break;
case V_58 :
V_2 -> V_243 = & V_252 ;
if ( ! ( V_1 -> V_108 . V_253 & V_254 ) )
V_2 -> V_179 -> V_247 = & V_248 ;
break;
default:
V_2 -> V_243 = & V_244 ;
F_127 ( V_2 , V_2 -> V_102 , V_2 -> V_239 ) ;
break;
}
if ( ! F_128 ( V_1 ) ) {
F_129 ( V_2 ) ;
F_130 ( V_2 ) ;
}
F_131 ( V_1 , V_255 ) ;
F_5 () ;
F_132 ( V_2 ) ;
}
