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
V_28:
if ( V_25 )
F_24 ( V_25 ) ;
if ( V_26 )
F_24 ( V_26 ) ;
return error ;
V_29:
if ( ! tmpfile )
F_7 ( V_11 , V_1 , V_15 ) ;
F_25 ( V_1 ) ;
goto V_28;
}
STATIC int
F_26 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_16 ,
T_2 V_23 )
{
return F_9 ( V_11 , V_15 , V_16 , V_23 , false ) ;
}
STATIC int
F_27 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_16 ,
bool V_32 )
{
return F_26 ( V_11 , V_15 , V_16 , 0 ) ;
}
STATIC int
F_28 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
T_1 V_16 )
{
return F_26 ( V_11 , V_15 , V_16 | V_33 , 0 ) ;
}
STATIC struct V_15 *
F_29 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
unsigned int V_32 )
{
struct V_5 * V_34 ;
struct V_13 V_7 ;
int error ;
if ( V_15 -> V_17 . V_18 >= V_35 )
return F_30 ( - V_36 ) ;
F_6 ( & V_7 , V_15 , 0 ) ;
error = F_31 ( F_2 ( V_11 ) , & V_7 , & V_34 , NULL ) ;
if ( F_12 ( error ) ) {
if ( F_12 ( error != - V_37 ) )
return F_30 ( error ) ;
F_32 ( V_15 , NULL ) ;
return NULL ;
}
return F_33 ( F_19 ( V_34 ) , V_15 ) ;
}
STATIC struct V_15 *
F_34 (
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
return F_30 ( - V_36 ) ;
F_6 ( & V_38 , V_15 , 0 ) ;
error = F_31 ( F_2 ( V_11 ) , & V_38 , & V_6 , & V_39 ) ;
if ( F_12 ( error ) ) {
if ( F_12 ( error != - V_37 ) )
return F_30 ( error ) ;
return NULL ;
}
if ( ! V_39 . V_7 )
return F_33 ( F_19 ( V_6 ) , V_15 ) ;
V_40 . V_7 = V_39 . V_7 ;
V_40 . V_18 = V_39 . V_18 ;
V_15 = F_35 ( V_15 , F_19 ( V_6 ) , & V_40 ) ;
F_36 ( V_39 . V_7 ) ;
return V_15 ;
}
STATIC int
F_37 (
struct V_15 * V_41 ,
struct V_1 * V_11 ,
struct V_15 * V_15 )
{
struct V_1 * V_1 = V_41 -> V_42 ;
struct V_13 V_7 ;
int error ;
F_6 ( & V_7 , V_15 , V_1 -> V_43 ) ;
error = F_38 ( F_2 ( V_11 ) , F_2 ( V_1 ) , & V_7 ) ;
if ( F_12 ( error ) )
return error ;
F_39 ( V_1 ) ;
F_23 ( V_15 , V_1 ) ;
return 0 ;
}
STATIC int
F_40 (
struct V_1 * V_11 ,
struct V_15 * V_15 )
{
struct V_13 V_7 ;
int error ;
F_6 ( & V_7 , V_15 , 0 ) ;
error = F_8 ( F_2 ( V_11 ) , & V_7 , F_2 ( V_15 -> V_42 ) ) ;
if ( error )
return error ;
if ( F_41 ( & F_42 ( V_11 -> V_44 ) -> V_45 ) )
F_43 ( V_15 ) ;
return 0 ;
}
STATIC int
F_44 (
struct V_1 * V_11 ,
struct V_15 * V_15 ,
const char * V_46 )
{
struct V_1 * V_1 ;
struct V_5 * V_34 = NULL ;
struct V_13 V_7 ;
int error ;
T_1 V_16 ;
V_16 = V_47 |
( V_48 ? 0777 & ~ F_45 () : V_49 ) ;
F_6 ( & V_7 , V_15 , V_16 ) ;
error = F_46 ( F_2 ( V_11 ) , & V_7 , V_46 , V_16 , & V_34 ) ;
if ( F_12 ( error ) )
goto V_50;
V_1 = F_19 ( V_34 ) ;
error = F_4 ( V_1 , V_11 , & V_15 -> V_17 ) ;
if ( F_12 ( error ) )
goto V_29;
F_23 ( V_15 , V_1 ) ;
return 0 ;
V_29:
F_7 ( V_11 , V_1 , V_15 ) ;
F_25 ( V_1 ) ;
V_50:
return error ;
}
STATIC int
F_47 (
struct V_1 * V_51 ,
struct V_15 * V_52 ,
struct V_1 * V_53 ,
struct V_15 * V_54 )
{
struct V_1 * V_55 = V_54 -> V_42 ;
struct V_13 V_56 ;
struct V_13 V_57 ;
F_6 ( & V_56 , V_52 , 0 ) ;
F_6 ( & V_57 , V_54 , V_52 -> V_42 -> V_43 ) ;
return F_48 ( F_2 ( V_51 ) , & V_56 , F_2 ( V_52 -> V_42 ) ,
F_2 ( V_53 ) , & V_57 , V_55 ?
F_2 ( V_55 ) : NULL ) ;
}
STATIC void *
F_49 (
struct V_15 * V_15 ,
struct V_58 * V_59 )
{
char * V_60 ;
int error = - V_61 ;
V_60 = F_50 ( V_62 + 1 , V_63 ) ;
if ( ! V_60 )
goto V_64;
error = F_51 ( F_2 ( V_15 -> V_42 ) , V_60 ) ;
if ( F_12 ( error ) )
goto V_65;
F_52 ( V_59 , V_60 ) ;
return NULL ;
V_65:
F_53 ( V_60 ) ;
V_64:
F_52 ( V_59 , F_30 ( error ) ) ;
return NULL ;
}
STATIC int
F_54 (
struct V_66 * V_67 ,
struct V_15 * V_15 ,
struct V_68 * V_69 )
{
struct V_1 * V_1 = V_15 -> V_42 ;
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_70 * V_71 = V_6 -> V_72 ;
F_55 ( V_6 ) ;
if ( F_56 ( V_71 ) )
return - V_73 ;
V_69 -> V_74 = F_57 ( V_6 ) ;
V_69 -> V_75 = V_1 -> V_44 -> V_76 ;
V_69 -> V_16 = V_6 -> V_77 . V_78 ;
V_69 -> V_79 = V_6 -> V_77 . V_80 ;
V_69 -> V_81 = V_1 -> V_82 ;
V_69 -> V_83 = V_1 -> V_84 ;
V_69 -> V_85 = V_6 -> V_86 ;
V_69 -> V_87 = V_1 -> V_88 ;
V_69 -> V_89 = V_1 -> V_90 ;
V_69 -> ctime = V_1 -> V_91 ;
V_69 -> V_92 =
F_58 ( V_71 , V_6 -> V_77 . V_93 + V_6 -> V_94 ) ;
switch ( V_1 -> V_43 & V_20 ) {
case V_95 :
case V_96 :
V_69 -> V_97 = V_98 ;
V_69 -> V_23 = F_59 ( F_60 ( V_6 -> V_99 . V_100 . V_101 ) & 0x1ff ,
F_61 ( V_6 -> V_99 . V_100 . V_101 ) ) ;
break;
default:
if ( F_62 ( V_6 ) ) {
V_69 -> V_97 =
F_63 ( V_6 ) << V_71 -> V_45 . V_102 ;
} else
V_69 -> V_97 = F_64 ( V_71 ) ;
V_69 -> V_23 = 0 ;
break;
}
return 0 ;
}
static void
F_65 (
struct V_5 * V_6 ,
struct V_103 * V_103 )
{
struct V_1 * V_1 = F_19 ( V_6 ) ;
T_1 V_16 = V_103 -> V_104 ;
ASSERT ( F_66 ( V_6 , V_105 ) ) ;
V_6 -> V_77 . V_78 &= V_20 ;
V_6 -> V_77 . V_78 |= V_16 & ~ V_20 ;
V_1 -> V_43 &= V_20 ;
V_1 -> V_43 |= V_16 & ~ V_20 ;
}
static void
F_67 (
struct V_5 * V_6 ,
struct V_103 * V_103 )
{
struct V_1 * V_1 = F_19 ( V_6 ) ;
ASSERT ( F_66 ( V_6 , V_105 ) ) ;
if ( V_103 -> V_106 & V_107 ) {
V_1 -> V_88 = V_103 -> V_108 ;
V_6 -> V_77 . V_109 . V_110 = V_103 -> V_108 . V_111 ;
V_6 -> V_77 . V_109 . V_112 = V_103 -> V_108 . V_113 ;
}
if ( V_103 -> V_106 & V_114 ) {
V_1 -> V_91 = V_103 -> V_115 ;
V_6 -> V_77 . V_116 . V_110 = V_103 -> V_115 . V_111 ;
V_6 -> V_77 . V_116 . V_112 = V_103 -> V_115 . V_113 ;
}
if ( V_103 -> V_106 & V_117 ) {
V_1 -> V_90 = V_103 -> V_118 ;
V_6 -> V_77 . V_119 . V_110 = V_103 -> V_118 . V_111 ;
V_6 -> V_77 . V_119 . V_112 = V_103 -> V_118 . V_113 ;
}
}
int
F_68 (
struct V_5 * V_6 ,
struct V_103 * V_103 ,
int V_32 )
{
T_3 * V_71 = V_6 -> V_72 ;
struct V_1 * V_1 = F_19 ( V_6 ) ;
int V_120 = V_103 -> V_106 ;
T_4 * V_121 ;
int error ;
T_5 V_81 = V_122 , V_123 = V_122 ;
T_6 V_83 = V_124 , V_125 = V_124 ;
struct V_126 * V_127 = NULL , * V_128 = NULL ;
struct V_126 * V_129 = NULL , * V_130 = NULL ;
F_69 ( V_6 ) ;
if ( ! ( V_32 & V_131 ) ) {
if ( V_71 -> V_132 & V_133 )
return - V_134 ;
if ( F_56 ( V_71 ) )
return - V_73 ;
error = F_70 ( V_1 , V_103 ) ;
if ( error )
return error ;
}
ASSERT ( ( V_120 & V_135 ) == 0 ) ;
if ( F_71 ( V_71 ) && ( V_120 & ( V_136 | V_137 ) ) ) {
T_7 V_138 = 0 ;
if ( ( V_120 & V_136 ) && F_72 ( V_71 ) ) {
V_81 = V_103 -> V_139 ;
V_138 |= V_140 ;
} else {
V_81 = V_1 -> V_82 ;
}
if ( ( V_120 & V_137 ) && F_73 ( V_71 ) ) {
V_83 = V_103 -> V_141 ;
V_138 |= V_142 ;
} else {
V_83 = V_1 -> V_84 ;
}
ASSERT ( V_127 == NULL ) ;
ASSERT ( V_128 == NULL ) ;
error = F_74 ( V_6 , F_75 ( V_81 ) ,
F_76 ( V_83 ) ,
F_77 ( V_6 ) ,
V_138 , & V_127 , & V_128 , NULL ) ;
if ( error )
return error ;
}
V_121 = F_78 ( V_71 , V_143 ) ;
error = F_79 ( V_121 , & F_80 ( V_71 ) -> V_144 , 0 , 0 ) ;
if ( error )
goto V_145;
F_81 ( V_6 , V_105 ) ;
if ( V_120 & ( V_136 | V_137 ) ) {
V_123 = V_1 -> V_82 ;
V_125 = V_1 -> V_84 ;
V_83 = ( V_120 & V_137 ) ? V_103 -> V_141 : V_125 ;
V_81 = ( V_120 & V_136 ) ? V_103 -> V_139 : V_123 ;
if ( F_82 ( V_71 ) &&
( ( F_72 ( V_71 ) && ! F_83 ( V_123 , V_81 ) ) ||
( F_73 ( V_71 ) && ! F_84 ( V_125 , V_83 ) ) ) ) {
ASSERT ( V_121 ) ;
error = F_85 ( V_121 , V_6 , V_127 , V_128 ,
NULL , F_86 ( V_146 ) ?
V_147 : 0 ) ;
if ( error )
goto V_148;
}
}
F_87 ( V_121 , V_6 , 0 ) ;
if ( V_120 & ( V_136 | V_137 ) ) {
if ( ( V_6 -> V_77 . V_78 & ( V_149 | V_150 ) ) &&
! F_86 ( V_151 ) )
V_6 -> V_77 . V_78 &= ~ ( V_149 | V_150 ) ;
if ( ! F_83 ( V_123 , V_81 ) ) {
if ( F_82 ( V_71 ) && F_72 ( V_71 ) ) {
ASSERT ( V_120 & V_136 ) ;
ASSERT ( V_127 ) ;
V_129 = F_88 ( V_121 , V_6 ,
& V_6 -> V_152 , V_127 ) ;
}
V_6 -> V_77 . V_153 = F_75 ( V_81 ) ;
V_1 -> V_82 = V_81 ;
}
if ( ! F_84 ( V_125 , V_83 ) ) {
if ( F_82 ( V_71 ) && F_73 ( V_71 ) ) {
ASSERT ( F_89 ( & V_71 -> V_45 ) ||
! F_90 ( V_71 ) ) ;
ASSERT ( V_120 & V_137 ) ;
ASSERT ( V_128 ) ;
V_130 = F_88 ( V_121 , V_6 ,
& V_6 -> V_154 , V_128 ) ;
}
V_6 -> V_77 . V_155 = F_76 ( V_83 ) ;
V_1 -> V_84 = V_83 ;
}
}
if ( V_120 & V_156 )
F_65 ( V_6 , V_103 ) ;
if ( V_120 & ( V_107 | V_114 | V_117 ) )
F_67 ( V_6 , V_103 ) ;
F_91 ( V_121 , V_6 , V_157 ) ;
F_92 ( V_158 ) ;
if ( V_71 -> V_132 & V_159 )
F_93 ( V_121 ) ;
error = F_94 ( V_121 , 0 ) ;
F_95 ( V_6 , V_105 ) ;
F_96 ( V_129 ) ;
F_96 ( V_130 ) ;
F_96 ( V_127 ) ;
F_96 ( V_128 ) ;
if ( error )
return error ;
if ( ( V_120 & V_156 ) && ! ( V_32 & V_131 ) ) {
error = F_97 ( V_1 , V_1 -> V_43 ) ;
if ( error )
return error ;
}
return 0 ;
V_148:
F_98 ( V_121 , 0 ) ;
F_95 ( V_6 , V_105 ) ;
V_145:
F_96 ( V_127 ) ;
F_96 ( V_128 ) ;
return error ;
}
int
F_99 (
struct V_5 * V_6 ,
struct V_103 * V_103 )
{
struct V_70 * V_71 = V_6 -> V_72 ;
struct V_1 * V_1 = F_19 ( V_6 ) ;
T_8 V_160 , V_161 ;
struct V_162 * V_121 ;
int error ;
T_7 V_163 = 0 ;
T_7 V_164 = 0 ;
F_69 ( V_6 ) ;
if ( V_71 -> V_132 & V_133 )
return - V_134 ;
if ( F_56 ( V_71 ) )
return - V_73 ;
error = F_70 ( V_1 , V_103 ) ;
if ( error )
return error ;
ASSERT ( F_66 ( V_6 , V_165 ) ) ;
ASSERT ( F_100 ( V_6 -> V_77 . V_78 ) ) ;
ASSERT ( ( V_103 -> V_106 & ( V_136 | V_137 | V_107 | V_166 |
V_167 | V_168 | V_169 ) ) == 0 ) ;
V_160 = V_1 -> V_170 ;
V_161 = V_103 -> V_171 ;
if ( V_161 == 0 && V_160 == 0 && V_6 -> V_77 . V_172 == 0 ) {
if ( ! ( V_103 -> V_106 & ( V_114 | V_117 ) ) )
return 0 ;
V_103 -> V_106 &= ~ V_135 ;
return F_68 ( V_6 , V_103 , 0 ) ;
}
error = F_101 ( V_6 , 0 ) ;
if ( error )
return error ;
if ( V_161 > V_160 ) {
error = F_102 ( V_6 , V_161 , V_160 ) ;
if ( error )
return error ;
}
if ( V_160 != V_6 -> V_77 . V_173 && V_161 > V_6 -> V_77 . V_173 ) {
error = F_103 ( F_19 ( V_6 ) -> V_174 ,
V_6 -> V_77 . V_173 , V_161 ) ;
if ( error )
return error ;
}
F_104 ( V_1 ) ;
error = F_105 ( V_1 -> V_174 , V_161 , V_175 ) ;
if ( error )
return error ;
F_106 ( V_1 , V_161 ) ;
if ( V_161 > V_160 && F_107 ( F_19 ( V_6 ) -> V_174 ) ) {
error = F_103 (
F_19 ( V_6 ) -> V_174 ,
F_108 ( V_160 , V_176 ) ,
F_109 ( V_160 , V_176 ) - 1 ) ;
if ( error )
return error ;
}
V_121 = F_78 ( V_71 , V_177 ) ;
error = F_79 ( V_121 , & F_80 ( V_71 ) -> V_178 , 0 , 0 ) ;
if ( error )
goto V_148;
V_164 = V_179 ;
V_163 |= V_105 ;
F_81 ( V_6 , V_105 ) ;
F_87 ( V_121 , V_6 , 0 ) ;
if ( V_161 != V_160 &&
! ( V_103 -> V_106 & ( V_114 | V_117 ) ) ) {
V_103 -> V_115 = V_103 -> V_118 =
F_110 ( V_1 -> V_44 ) ;
V_103 -> V_106 |= V_114 | V_117 ;
}
V_6 -> V_77 . V_173 = V_161 ;
F_91 ( V_121 , V_6 , V_157 ) ;
if ( V_161 <= V_160 ) {
error = F_111 ( & V_121 , V_6 , V_180 , V_161 ) ;
if ( error )
goto V_181;
F_112 ( V_6 , V_182 ) ;
F_113 ( V_6 ) ;
}
if ( V_103 -> V_106 & V_156 )
F_65 ( V_6 , V_103 ) ;
if ( V_103 -> V_106 & ( V_107 | V_114 | V_117 ) )
F_67 ( V_6 , V_103 ) ;
F_91 ( V_121 , V_6 , V_157 ) ;
F_92 ( V_158 ) ;
if ( V_71 -> V_132 & V_159 )
F_93 ( V_121 ) ;
error = F_94 ( V_121 , V_179 ) ;
V_183:
if ( V_163 )
F_95 ( V_6 , V_163 ) ;
return error ;
V_181:
V_164 |= V_184 ;
V_148:
F_98 ( V_121 , V_164 ) ;
goto V_183;
}
STATIC int
F_114 (
struct V_15 * V_15 ,
struct V_103 * V_103 )
{
struct V_5 * V_6 = F_2 ( V_15 -> V_42 ) ;
int error ;
if ( V_103 -> V_106 & V_135 ) {
F_81 ( V_6 , V_165 ) ;
error = F_99 ( V_6 , V_103 ) ;
F_95 ( V_6 , V_165 ) ;
} else {
error = F_68 ( V_6 , V_103 , 0 ) ;
}
return error ;
}
STATIC int
F_115 (
struct V_1 * V_1 ,
struct V_185 * V_186 ,
int V_32 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_70 * V_71 = V_6 -> V_72 ;
struct V_162 * V_121 ;
int error ;
F_116 ( V_6 ) ;
V_121 = F_78 ( V_71 , V_187 ) ;
error = F_79 ( V_121 , & F_80 ( V_71 ) -> V_188 , 0 , 0 ) ;
if ( error ) {
F_98 ( V_121 , 0 ) ;
return error ;
}
F_81 ( V_6 , V_105 ) ;
if ( V_32 & V_189 ) {
V_1 -> V_91 = * V_186 ;
V_6 -> V_77 . V_116 . V_110 = ( V_190 ) V_186 -> V_111 ;
V_6 -> V_77 . V_116 . V_112 = ( V_190 ) V_186 -> V_113 ;
}
if ( V_32 & V_191 ) {
V_1 -> V_90 = * V_186 ;
V_6 -> V_77 . V_119 . V_110 = ( V_190 ) V_186 -> V_111 ;
V_6 -> V_77 . V_119 . V_112 = ( V_190 ) V_186 -> V_113 ;
}
if ( V_32 & V_192 ) {
V_1 -> V_88 = * V_186 ;
V_6 -> V_77 . V_109 . V_110 = ( V_190 ) V_186 -> V_111 ;
V_6 -> V_77 . V_109 . V_112 = ( V_190 ) V_186 -> V_113 ;
}
F_87 ( V_121 , V_6 , V_105 ) ;
F_91 ( V_121 , V_6 , V_193 ) ;
return F_94 ( V_121 , 0 ) ;
}
STATIC int
F_117 (
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
V_201 = F_118 ( V_196 -> V_205 ) ;
V_202 = F_118 ( V_196 -> V_204 ) ;
V_203 = F_118 ( V_196 -> V_206 ) ;
if ( V_196 -> V_207 & V_208 )
V_200 |= V_209 ;
else if ( V_196 -> V_207 & V_210 ) {
V_200 |= ( V_211 |
V_212 ) ;
V_202 = 0 ;
}
if ( V_196 -> V_207 & V_213 )
V_200 |= V_214 ;
error = F_119 ( V_199 , V_201 , V_202 ,
V_203 , V_200 ) ;
if ( error > 0 ) {
error = 0 ;
* V_197 = 1 ;
}
return error ;
}
STATIC int
F_120 (
struct V_1 * V_1 ,
struct V_198 * V_199 ,
T_10 V_215 ,
T_10 V_203 )
{
T_11 * V_6 = F_2 ( V_1 ) ;
struct V_195 V_216 ;
int error ;
error = F_121 ( V_199 , V_217 ) ;
if ( error )
return error ;
V_216 . V_205 = F_122 ( V_215 ) ;
if ( V_203 == V_218 )
V_216 . V_206 = - 1LL ;
else
V_216 . V_206 = F_123 ( V_215 + V_203 ) - V_216 . V_205 ;
V_216 . V_219 = ! V_199 -> V_220 ? V_221 :
V_199 -> V_220 + 1 ;
V_216 . V_219 = F_124 ( V_222 , V_216 . V_219 ,
( V_223 * 16 / sizeof( struct V_195 ) ) ) ;
V_216 . V_224 = V_225 | V_226 ;
if ( V_199 -> V_227 & V_228 )
V_216 . V_224 |= V_229 ;
if ( ! ( V_199 -> V_227 & V_230 ) )
V_216 . V_224 |= V_231 ;
error = F_125 ( V_6 , & V_216 , F_117 , V_199 ) ;
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
if ( V_6 -> V_77 . V_232 & V_233 )
V_1 -> V_234 |= V_235 ;
else
V_1 -> V_234 &= ~ V_235 ;
if ( V_6 -> V_77 . V_232 & V_236 )
V_1 -> V_234 |= V_237 ;
else
V_1 -> V_234 &= ~ V_237 ;
if ( V_6 -> V_77 . V_232 & V_238 )
V_1 -> V_234 |= V_239 ;
else
V_1 -> V_234 &= ~ V_239 ;
if ( V_6 -> V_77 . V_232 & V_240 )
V_1 -> V_234 |= V_241 ;
else
V_1 -> V_234 &= ~ V_241 ;
}
void
F_128 (
struct V_5 * V_6 )
{
struct V_1 * V_1 = & V_6 -> V_242 ;
T_12 V_243 ;
V_1 -> V_86 = V_6 -> V_86 ;
V_1 -> V_244 = V_245 ;
F_129 ( V_1 ) ;
F_130 ( & V_1 -> V_246 ) ;
V_1 -> V_43 = V_6 -> V_77 . V_78 ;
F_131 ( V_1 , V_6 -> V_77 . V_80 ) ;
V_1 -> V_82 = F_132 ( V_6 -> V_77 . V_153 ) ;
V_1 -> V_84 = F_133 ( V_6 -> V_77 . V_155 ) ;
switch ( V_1 -> V_43 & V_20 ) {
case V_95 :
case V_96 :
V_1 -> V_247 =
F_59 ( F_60 ( V_6 -> V_99 . V_100 . V_101 ) & 0x1ff ,
F_61 ( V_6 -> V_99 . V_100 . V_101 ) ) ;
break;
default:
V_1 -> V_247 = 0 ;
break;
}
V_1 -> V_248 = V_6 -> V_77 . V_249 ;
F_134 ( V_1 , V_6 -> V_77 . V_173 ) ;
V_1 -> V_88 . V_111 = V_6 -> V_77 . V_109 . V_110 ;
V_1 -> V_88 . V_113 = V_6 -> V_77 . V_109 . V_112 ;
V_1 -> V_90 . V_111 = V_6 -> V_77 . V_119 . V_110 ;
V_1 -> V_90 . V_113 = V_6 -> V_77 . V_119 . V_112 ;
V_1 -> V_91 . V_111 = V_6 -> V_77 . V_116 . V_110 ;
V_1 -> V_91 . V_113 = V_6 -> V_77 . V_116 . V_112 ;
F_127 ( V_1 , V_6 ) ;
V_6 -> V_250 = V_6 -> V_72 -> V_251 ;
F_135 ( & V_6 -> V_252 . V_253 , & V_254 ) ;
switch ( V_1 -> V_43 & V_20 ) {
case V_255 :
V_1 -> V_256 = & V_257 ;
V_1 -> V_258 = & V_259 ;
V_1 -> V_174 -> V_260 = & V_261 ;
break;
case V_33 :
F_135 ( & V_6 -> V_252 . V_253 , & V_262 ) ;
if ( F_41 ( & F_42 ( V_1 -> V_44 ) -> V_45 ) )
V_1 -> V_256 = & V_263 ;
else
V_1 -> V_256 = & V_264 ;
V_1 -> V_258 = & V_265 ;
V_6 -> V_250 = V_6 -> V_72 -> V_266 ;
break;
case V_47 :
V_1 -> V_256 = & V_267 ;
if ( ! ( V_6 -> V_99 . V_268 & V_269 ) )
V_1 -> V_174 -> V_260 = & V_261 ;
break;
default:
V_1 -> V_256 = & V_257 ;
F_136 ( V_1 , V_1 -> V_43 , V_1 -> V_247 ) ;
break;
}
V_243 = F_137 ( V_1 -> V_174 ) ;
F_138 ( V_1 -> V_174 , ( V_243 & ~ ( V_270 ) ) ) ;
if ( ! F_139 ( V_6 ) ) {
F_140 ( V_1 ) ;
F_141 ( V_1 ) ;
}
F_142 ( V_6 , V_271 ) ;
F_143 () ;
F_144 ( V_1 ) ;
}
