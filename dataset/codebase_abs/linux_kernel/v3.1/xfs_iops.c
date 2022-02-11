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
STATIC int
F_8 (
struct V_2 * V_2 ,
struct V_2 * V_19 ,
const struct V_20 * V_20 )
{
struct V_21 * V_1 = F_9 ( V_2 ) ;
T_2 V_22 ;
void * V_23 ;
unsigned char * V_24 ;
int error ;
error = F_10 ( V_2 , V_19 , V_20 , ( char * * ) & V_24 ,
& V_23 , & V_22 ) ;
if ( error ) {
if ( error == - V_25 )
return 0 ;
return - error ;
}
error = F_11 ( V_1 , V_24 , V_23 , V_22 , V_26 ) ;
F_12 ( V_24 ) ;
F_12 ( V_23 ) ;
return error ;
}
static void
F_13 (
struct V_27 * V_28 ,
struct V_29 * V_29 )
{
V_28 -> V_24 = V_29 -> V_30 . V_24 ;
V_28 -> V_31 = V_29 -> V_30 . V_31 ;
}
STATIC void
F_14 (
struct V_2 * V_19 ,
struct V_2 * V_2 ,
struct V_29 * V_29 )
{
struct V_27 V_32 ;
F_13 ( & V_32 , V_29 ) ;
F_15 ( F_9 ( V_19 ) , & V_32 , F_9 ( V_2 ) ) ;
F_16 ( V_2 ) ;
}
STATIC int
F_17 (
struct V_2 * V_19 ,
struct V_29 * V_29 ,
int V_33 ,
T_3 V_34 )
{
struct V_2 * V_2 ;
struct V_21 * V_1 = NULL ;
struct V_35 * V_36 = NULL ;
struct V_27 V_24 ;
int error ;
if ( F_18 ( V_33 ) || F_19 ( V_33 ) ) {
if ( F_20 ( ! F_21 ( V_34 ) || F_22 ( V_34 ) & ~ 0x1ff ) )
return - V_37 ;
V_34 = F_23 ( V_34 ) ;
} else {
V_34 = 0 ;
}
if ( F_24 ( V_19 ) ) {
V_36 = F_25 ( V_19 , V_38 ) ;
if ( F_26 ( V_36 ) )
return F_27 ( V_36 ) ;
if ( ! V_36 )
V_33 &= ~ F_28 () ;
}
F_13 ( & V_24 , V_29 ) ;
error = F_29 ( F_9 ( V_19 ) , & V_24 , V_33 , V_34 , & V_1 ) ;
if ( F_20 ( error ) )
goto V_39;
V_2 = F_2 ( V_1 ) ;
error = F_8 ( V_2 , V_19 , & V_29 -> V_30 ) ;
if ( F_20 ( error ) )
goto V_40;
if ( V_36 ) {
error = - F_30 ( V_2 , V_36 ) ;
V_36 = NULL ;
if ( F_20 ( error ) )
goto V_40;
}
F_31 ( V_29 , V_2 ) ;
return - error ;
V_40:
F_14 ( V_19 , V_2 , V_29 ) ;
V_39:
F_32 ( V_36 ) ;
return - error ;
}
STATIC int
F_33 (
struct V_2 * V_19 ,
struct V_29 * V_29 ,
int V_33 ,
struct V_41 * V_42 )
{
return F_17 ( V_19 , V_29 , V_33 , 0 ) ;
}
STATIC int
F_34 (
struct V_2 * V_19 ,
struct V_29 * V_29 ,
int V_33 )
{
return F_17 ( V_19 , V_29 , V_33 | V_43 , 0 ) ;
}
STATIC struct V_29 *
F_35 (
struct V_2 * V_19 ,
struct V_29 * V_29 ,
struct V_41 * V_42 )
{
struct V_21 * V_44 ;
struct V_27 V_24 ;
int error ;
if ( V_29 -> V_30 . V_31 >= V_45 )
return F_36 ( - V_46 ) ;
F_13 ( & V_24 , V_29 ) ;
error = F_37 ( F_9 ( V_19 ) , & V_24 , & V_44 , NULL ) ;
if ( F_20 ( error ) ) {
if ( F_20 ( error != V_47 ) )
return F_36 ( - error ) ;
F_38 ( V_29 , NULL ) ;
return NULL ;
}
return F_39 ( F_2 ( V_44 ) , V_29 ) ;
}
STATIC struct V_29 *
F_40 (
struct V_2 * V_19 ,
struct V_29 * V_29 ,
struct V_41 * V_42 )
{
struct V_21 * V_1 ;
struct V_27 V_48 ;
struct V_27 V_49 ;
struct V_20 V_50 ;
int error ;
if ( V_29 -> V_30 . V_31 >= V_45 )
return F_36 ( - V_46 ) ;
F_13 ( & V_48 , V_29 ) ;
error = F_37 ( F_9 ( V_19 ) , & V_48 , & V_1 , & V_49 ) ;
if ( F_20 ( error ) ) {
if ( F_20 ( error != V_47 ) )
return F_36 ( - error ) ;
return NULL ;
}
if ( ! V_49 . V_24 )
return F_39 ( F_2 ( V_1 ) , V_29 ) ;
V_50 . V_24 = V_49 . V_24 ;
V_50 . V_31 = V_49 . V_31 ;
V_29 = F_41 ( V_29 , F_2 ( V_1 ) , & V_50 ) ;
F_42 ( V_49 . V_24 ) ;
return V_29 ;
}
STATIC int
F_43 (
struct V_29 * V_51 ,
struct V_2 * V_19 ,
struct V_29 * V_29 )
{
struct V_2 * V_2 = V_51 -> V_52 ;
struct V_27 V_24 ;
int error ;
F_13 ( & V_24 , V_29 ) ;
error = F_44 ( F_9 ( V_19 ) , F_9 ( V_2 ) , & V_24 ) ;
if ( F_20 ( error ) )
return - error ;
F_45 ( V_2 ) ;
F_31 ( V_29 , V_2 ) ;
return 0 ;
}
STATIC int
F_46 (
struct V_2 * V_19 ,
struct V_29 * V_29 )
{
struct V_27 V_24 ;
int error ;
F_13 ( & V_24 , V_29 ) ;
error = - F_15 ( F_9 ( V_19 ) , & V_24 , F_9 ( V_29 -> V_52 ) ) ;
if ( error )
return error ;
if ( F_47 ( & F_48 ( V_19 -> V_53 ) -> V_54 ) )
F_49 ( V_29 ) ;
return 0 ;
}
STATIC int
F_50 (
struct V_2 * V_19 ,
struct V_29 * V_29 ,
const char * V_55 )
{
struct V_2 * V_2 ;
struct V_21 * V_44 = NULL ;
struct V_27 V_24 ;
int error ;
T_4 V_33 ;
V_33 = V_56 |
( V_57 ? 0777 & ~ F_28 () : V_58 ) ;
F_13 ( & V_24 , V_29 ) ;
error = F_51 ( F_9 ( V_19 ) , & V_24 , V_55 , V_33 , & V_44 ) ;
if ( F_20 ( error ) )
goto V_59;
V_2 = F_2 ( V_44 ) ;
error = F_8 ( V_2 , V_19 , & V_29 -> V_30 ) ;
if ( F_20 ( error ) )
goto V_40;
F_31 ( V_29 , V_2 ) ;
return 0 ;
V_40:
F_14 ( V_19 , V_2 , V_29 ) ;
V_59:
return - error ;
}
STATIC int
F_52 (
struct V_2 * V_60 ,
struct V_29 * V_61 ,
struct V_2 * V_62 ,
struct V_29 * V_63 )
{
struct V_2 * V_64 = V_63 -> V_52 ;
struct V_27 V_65 ;
struct V_27 V_66 ;
F_13 ( & V_65 , V_61 ) ;
F_13 ( & V_66 , V_63 ) ;
return - F_53 ( F_9 ( V_60 ) , & V_65 , F_9 ( V_61 -> V_52 ) ,
F_9 ( V_62 ) , & V_66 , V_64 ?
F_9 ( V_64 ) : NULL ) ;
}
STATIC void *
F_54 (
struct V_29 * V_29 ,
struct V_41 * V_42 )
{
char * V_67 ;
int error = - V_68 ;
V_67 = F_55 ( V_69 + 1 , V_70 ) ;
if ( ! V_67 )
goto V_71;
error = - F_56 ( F_9 ( V_29 -> V_52 ) , V_67 ) ;
if ( F_20 ( error ) )
goto V_72;
F_57 ( V_42 , V_67 ) ;
return NULL ;
V_72:
F_12 ( V_67 ) ;
V_71:
F_57 ( V_42 , F_36 ( error ) ) ;
return NULL ;
}
STATIC void
F_58 (
struct V_29 * V_29 ,
struct V_41 * V_42 ,
void * V_73 )
{
char * V_74 = F_59 ( V_42 ) ;
if ( ! F_26 ( V_74 ) )
F_12 ( V_74 ) ;
}
STATIC int
F_60 (
struct V_75 * V_76 ,
struct V_29 * V_29 ,
struct V_77 * V_78 )
{
struct V_2 * V_2 = V_29 -> V_52 ;
struct V_21 * V_1 = F_9 ( V_2 ) ;
struct V_79 * V_80 = V_1 -> V_81 ;
F_61 ( V_1 ) ;
if ( F_62 ( V_80 ) )
return F_63 ( V_82 ) ;
V_78 -> V_83 = F_64 ( V_1 ) ;
V_78 -> V_84 = V_2 -> V_53 -> V_85 ;
V_78 -> V_33 = V_1 -> V_3 . V_86 ;
V_78 -> V_87 = V_1 -> V_3 . V_88 ;
V_78 -> V_89 = V_1 -> V_3 . V_90 ;
V_78 -> V_91 = V_1 -> V_3 . V_92 ;
V_78 -> V_93 = V_1 -> V_94 ;
V_78 -> V_95 = V_2 -> V_7 ;
V_78 -> V_96 = V_2 -> V_14 ;
V_78 -> ctime = V_2 -> V_12 ;
V_78 -> V_97 =
F_65 ( V_80 , V_1 -> V_3 . V_98 + V_1 -> V_99 ) ;
switch ( V_2 -> V_100 & V_101 ) {
case V_102 :
case V_103 :
V_78 -> V_104 = V_105 ;
V_78 -> V_34 = F_66 ( F_67 ( V_1 -> V_106 . V_107 . V_108 ) & 0x1ff ,
F_68 ( V_1 -> V_106 . V_107 . V_108 ) ) ;
break;
default:
if ( F_69 ( V_1 ) ) {
V_78 -> V_104 =
F_70 ( V_1 ) << V_80 -> V_54 . V_109 ;
} else
V_78 -> V_104 = F_71 ( V_80 ) ;
V_78 -> V_34 = 0 ;
break;
}
return 0 ;
}
int
F_72 (
struct V_21 * V_1 ,
struct V_110 * V_110 ,
int V_111 )
{
T_5 * V_80 = V_1 -> V_81 ;
struct V_2 * V_2 = F_2 ( V_1 ) ;
int V_112 = V_110 -> V_113 ;
T_6 * V_114 ;
int error ;
T_7 V_89 = 0 , V_115 = 0 ;
T_8 V_91 = 0 , V_116 = 0 ;
struct V_117 * V_118 = NULL , * V_119 = NULL ;
struct V_117 * V_120 = NULL , * V_121 = NULL ;
F_73 ( V_1 ) ;
if ( V_80 -> V_122 & V_123 )
return F_63 ( V_124 ) ;
if ( F_62 ( V_80 ) )
return F_63 ( V_82 ) ;
error = - F_74 ( V_2 , V_110 ) ;
if ( error )
return F_63 ( error ) ;
ASSERT ( ( V_112 & V_125 ) == 0 ) ;
if ( F_75 ( V_80 ) && ( V_112 & ( V_126 | V_127 ) ) ) {
T_9 V_128 = 0 ;
if ( ( V_112 & V_126 ) && F_76 ( V_80 ) ) {
V_89 = V_110 -> V_129 ;
V_128 |= V_130 ;
} else {
V_89 = V_1 -> V_3 . V_90 ;
}
if ( ( V_112 & V_127 ) && F_77 ( V_80 ) ) {
V_91 = V_110 -> V_131 ;
V_128 |= V_132 ;
} else {
V_91 = V_1 -> V_3 . V_92 ;
}
ASSERT ( V_118 == NULL ) ;
ASSERT ( V_119 == NULL ) ;
error = F_78 ( V_1 , V_89 , V_91 , F_79 ( V_1 ) ,
V_128 , & V_118 , & V_119 ) ;
if ( error )
return error ;
}
V_114 = F_80 ( V_80 , V_133 ) ;
error = F_81 ( V_114 , 0 , F_82 ( V_80 ) , 0 , 0 , 0 ) ;
if ( error )
goto V_134;
F_83 ( V_1 , V_135 ) ;
if ( V_112 & ( V_126 | V_127 ) ) {
V_115 = V_1 -> V_3 . V_90 ;
V_116 = V_1 -> V_3 . V_92 ;
V_91 = ( V_112 & V_127 ) ? V_110 -> V_131 : V_116 ;
V_89 = ( V_112 & V_126 ) ? V_110 -> V_129 : V_115 ;
if ( F_84 ( V_80 ) &&
( ( F_76 ( V_80 ) && V_115 != V_89 ) ||
( F_77 ( V_80 ) && V_116 != V_91 ) ) ) {
ASSERT ( V_114 ) ;
error = F_85 ( V_114 , V_1 , V_118 , V_119 ,
F_86 ( V_136 ) ?
V_137 : 0 ) ;
if ( error )
goto V_138;
}
}
F_87 ( V_114 , V_1 ) ;
if ( V_112 & ( V_126 | V_127 ) ) {
if ( ( V_1 -> V_3 . V_86 & ( V_139 | V_140 ) ) &&
! F_86 ( V_141 ) )
V_1 -> V_3 . V_86 &= ~ ( V_139 | V_140 ) ;
if ( V_115 != V_89 ) {
if ( F_84 ( V_80 ) && F_76 ( V_80 ) ) {
ASSERT ( V_112 & V_126 ) ;
ASSERT ( V_118 ) ;
V_120 = F_88 ( V_114 , V_1 ,
& V_1 -> V_142 , V_118 ) ;
}
V_1 -> V_3 . V_90 = V_89 ;
V_2 -> V_143 = V_89 ;
}
if ( V_116 != V_91 ) {
if ( F_84 ( V_80 ) && F_77 ( V_80 ) ) {
ASSERT ( ! F_89 ( V_80 ) ) ;
ASSERT ( V_112 & V_127 ) ;
ASSERT ( V_119 ) ;
V_121 = F_88 ( V_114 , V_1 ,
& V_1 -> V_144 , V_119 ) ;
}
V_1 -> V_3 . V_92 = V_91 ;
V_2 -> V_145 = V_91 ;
}
}
if ( V_112 & V_146 ) {
T_10 V_33 = V_110 -> V_147 ;
if ( ! F_90 ( V_2 -> V_145 ) && ! F_86 ( V_141 ) )
V_33 &= ~ V_140 ;
V_1 -> V_3 . V_86 &= V_101 ;
V_1 -> V_3 . V_86 |= V_33 & ~ V_101 ;
V_2 -> V_100 &= V_101 ;
V_2 -> V_100 |= V_33 & ~ V_101 ;
}
if ( V_112 & V_148 ) {
V_2 -> V_7 = V_110 -> V_149 ;
V_1 -> V_3 . V_4 . V_5 = V_110 -> V_149 . V_8 ;
V_1 -> V_3 . V_4 . V_9 = V_110 -> V_149 . V_10 ;
V_1 -> V_18 = 1 ;
}
if ( V_112 & V_150 ) {
V_2 -> V_12 = V_110 -> V_151 ;
V_1 -> V_3 . V_11 . V_5 = V_110 -> V_151 . V_8 ;
V_1 -> V_3 . V_11 . V_9 = V_110 -> V_151 . V_10 ;
V_1 -> V_18 = 1 ;
}
if ( V_112 & V_152 ) {
V_2 -> V_14 = V_110 -> V_153 ;
V_1 -> V_3 . V_13 . V_5 = V_110 -> V_153 . V_8 ;
V_1 -> V_3 . V_13 . V_9 = V_110 -> V_153 . V_10 ;
V_1 -> V_18 = 1 ;
}
F_91 ( V_114 , V_1 , V_154 ) ;
F_92 ( V_155 ) ;
if ( V_80 -> V_122 & V_156 )
F_93 ( V_114 ) ;
error = F_94 ( V_114 , 0 ) ;
F_95 ( V_1 , V_135 ) ;
F_96 ( V_120 ) ;
F_96 ( V_121 ) ;
F_96 ( V_118 ) ;
F_96 ( V_119 ) ;
if ( error )
return F_63 ( error ) ;
if ( ( V_112 & V_146 ) && ! ( V_111 & V_157 ) ) {
error = - F_97 ( V_2 ) ;
if ( error )
return F_63 ( error ) ;
}
return 0 ;
V_138:
F_98 ( V_114 , 0 ) ;
F_95 ( V_1 , V_135 ) ;
V_134:
F_96 ( V_118 ) ;
F_96 ( V_119 ) ;
return error ;
}
int
F_99 (
struct V_21 * V_1 ,
struct V_110 * V_110 ,
int V_111 )
{
struct V_79 * V_80 = V_1 -> V_81 ;
struct V_2 * V_2 = F_2 ( V_1 ) ;
int V_112 = V_110 -> V_113 ;
struct V_158 * V_114 ;
int error ;
T_9 V_159 ;
T_9 V_160 = 0 ;
F_73 ( V_1 ) ;
if ( V_80 -> V_122 & V_123 )
return F_63 ( V_124 ) ;
if ( F_62 ( V_80 ) )
return F_63 ( V_82 ) ;
error = - F_74 ( V_2 , V_110 ) ;
if ( error )
return F_63 ( error ) ;
ASSERT ( F_100 ( V_1 -> V_3 . V_86 ) ) ;
ASSERT ( ( V_112 & ( V_146 | V_126 | V_127 | V_148 | V_161 |
V_162 | V_163 | V_164 |
V_165 | V_166 ) ) == 0 ) ;
V_159 = V_135 ;
if ( ! ( V_111 & V_167 ) )
V_159 |= V_168 ;
F_83 ( V_1 , V_159 ) ;
if ( V_110 -> V_169 == 0 &&
V_1 -> V_170 == 0 && V_1 -> V_3 . V_171 == 0 ) {
if ( ! ( V_112 & ( V_150 | V_152 ) ) )
goto V_172;
F_95 ( V_1 , V_159 ) ;
V_110 -> V_113 &= ~ V_125 ;
return F_72 ( V_1 , V_110 , 0 ) ;
}
error = F_101 ( V_1 , 0 ) ;
if ( error )
goto V_172;
if ( V_110 -> V_169 > V_1 -> V_170 ) {
error = F_102 ( V_1 , V_110 -> V_169 , V_1 -> V_170 ) ;
if ( error )
goto V_172;
}
F_95 ( V_1 , V_135 ) ;
V_159 &= ~ V_135 ;
if ( V_1 -> V_170 != V_1 -> V_3 . V_173 && V_110 -> V_169 > V_1 -> V_3 . V_173 ) {
error = F_103 ( V_1 , V_1 -> V_3 . V_173 , V_110 -> V_169 ,
V_174 , V_175 ) ;
if ( error )
goto V_172;
}
F_104 ( V_1 ) ;
error = - F_105 ( V_2 -> V_176 , V_110 -> V_169 ,
V_177 ) ;
if ( error )
goto V_172;
V_114 = F_80 ( V_80 , V_178 ) ;
error = F_81 ( V_114 , 0 , F_106 ( V_80 ) , 0 ,
V_179 ,
V_180 ) ;
if ( error )
goto V_138;
F_107 ( V_2 , V_110 -> V_169 ) ;
V_160 = V_181 ;
V_159 |= V_135 ;
F_83 ( V_1 , V_135 ) ;
F_87 ( V_114 , V_1 ) ;
if ( V_110 -> V_169 != V_1 -> V_170 &&
( ! ( V_112 & ( V_150 | V_152 ) ) ) ) {
V_110 -> V_151 = V_110 -> V_153 =
F_108 ( V_2 -> V_53 ) ;
V_112 |= V_150 | V_152 ;
}
if ( V_110 -> V_169 > V_1 -> V_170 ) {
V_1 -> V_3 . V_173 = V_110 -> V_169 ;
V_1 -> V_170 = V_110 -> V_169 ;
} else if ( V_110 -> V_169 <= V_1 -> V_170 ||
( V_110 -> V_169 == 0 && V_1 -> V_3 . V_171 ) ) {
error = F_109 ( & V_114 , V_1 , V_110 -> V_169 ) ;
if ( error )
goto V_182;
F_110 ( V_1 , V_183 ) ;
}
if ( V_112 & V_150 ) {
V_2 -> V_12 = V_110 -> V_151 ;
V_1 -> V_3 . V_11 . V_5 = V_110 -> V_151 . V_8 ;
V_1 -> V_3 . V_11 . V_9 = V_110 -> V_151 . V_10 ;
V_1 -> V_18 = 1 ;
}
if ( V_112 & V_152 ) {
V_2 -> V_14 = V_110 -> V_153 ;
V_1 -> V_3 . V_13 . V_5 = V_110 -> V_153 . V_8 ;
V_1 -> V_3 . V_13 . V_9 = V_110 -> V_153 . V_10 ;
V_1 -> V_18 = 1 ;
}
F_91 ( V_114 , V_1 , V_154 ) ;
F_92 ( V_155 ) ;
if ( V_80 -> V_122 & V_156 )
F_93 ( V_114 ) ;
error = F_94 ( V_114 , V_181 ) ;
V_172:
if ( V_159 )
F_95 ( V_1 , V_159 ) ;
return error ;
V_182:
V_160 |= V_184 ;
V_138:
F_98 ( V_114 , V_160 ) ;
goto V_172;
}
STATIC int
F_111 (
struct V_29 * V_29 ,
struct V_110 * V_110 )
{
if ( V_110 -> V_113 & V_125 )
return - F_99 ( F_9 ( V_29 -> V_52 ) , V_110 , 0 ) ;
return - F_72 ( F_9 ( V_29 -> V_52 ) , V_110 , 0 ) ;
}
STATIC int
F_112 (
void * * V_185 ,
struct V_186 * V_187 ,
int * V_188 )
{
int error ;
struct V_189 * V_190 = * V_185 ;
T_11 V_191 = 0 ;
T_12 V_192 , V_193 , V_22 ;
if ( V_187 -> V_194 == - 1LL )
return 0 ;
V_192 = F_113 ( V_187 -> V_195 ) ;
V_193 = F_113 ( V_187 -> V_194 ) ;
V_22 = F_113 ( V_187 -> V_196 ) ;
if ( V_187 -> V_197 & V_198 )
V_191 |= V_199 ;
else if ( V_187 -> V_197 & V_200 ) {
V_191 |= V_201 ;
V_193 = 0 ;
}
if ( V_187 -> V_197 & V_202 )
V_191 |= V_203 ;
error = F_114 ( V_190 , V_192 , V_193 ,
V_22 , V_191 ) ;
if ( error > 0 ) {
error = 0 ;
* V_188 = 1 ;
}
return - error ;
}
STATIC int
F_115 (
struct V_2 * V_2 ,
struct V_189 * V_190 ,
T_12 V_204 ,
T_12 V_22 )
{
T_1 * V_1 = F_9 ( V_2 ) ;
struct V_186 V_205 ;
int error ;
error = F_116 ( V_190 , V_206 ) ;
if ( error )
return error ;
V_205 . V_195 = F_117 ( V_204 ) ;
if ( V_22 == V_207 )
V_205 . V_196 = - 1LL ;
else
V_205 . V_196 = F_117 ( V_22 ) ;
V_205 . V_208 = ! V_190 -> V_209 ? V_210 :
V_190 -> V_209 + 1 ;
V_205 . V_208 = F_118 ( V_211 , V_205 . V_208 ,
( V_212 * 16 / sizeof( struct V_186 ) ) ) ;
V_205 . V_213 = V_214 | V_215 ;
if ( V_190 -> V_216 & V_217 )
V_205 . V_213 |= V_218 ;
if ( ! ( V_190 -> V_216 & V_219 ) )
V_205 . V_213 |= V_220 ;
error = F_119 ( V_1 , & V_205 , F_112 , V_190 ) ;
if ( error )
return - error ;
return 0 ;
}
STATIC void
F_120 (
struct V_2 * V_2 ,
struct V_21 * V_1 )
{
if ( V_1 -> V_3 . V_221 & V_222 )
V_2 -> V_223 |= V_224 ;
else
V_2 -> V_223 &= ~ V_224 ;
if ( V_1 -> V_3 . V_221 & V_225 )
V_2 -> V_223 |= V_226 ;
else
V_2 -> V_223 &= ~ V_226 ;
if ( V_1 -> V_3 . V_221 & V_227 )
V_2 -> V_223 |= V_228 ;
else
V_2 -> V_223 &= ~ V_228 ;
if ( V_1 -> V_3 . V_221 & V_229 )
V_2 -> V_223 |= V_230 ;
else
V_2 -> V_223 &= ~ V_230 ;
}
void
F_121 (
struct V_21 * V_1 )
{
struct V_2 * V_2 = & V_1 -> V_231 ;
V_2 -> V_94 = V_1 -> V_94 ;
V_2 -> V_15 = V_232 ;
F_122 ( V_2 ) ;
F_123 ( & V_2 -> V_233 ) ;
V_2 -> V_100 = V_1 -> V_3 . V_86 ;
V_2 -> V_234 = V_1 -> V_3 . V_88 ;
V_2 -> V_143 = V_1 -> V_3 . V_90 ;
V_2 -> V_145 = V_1 -> V_3 . V_92 ;
switch ( V_2 -> V_100 & V_101 ) {
case V_102 :
case V_103 :
V_2 -> V_235 =
F_66 ( F_67 ( V_1 -> V_106 . V_107 . V_108 ) & 0x1ff ,
F_68 ( V_1 -> V_106 . V_107 . V_108 ) ) ;
break;
default:
V_2 -> V_235 = 0 ;
break;
}
V_2 -> V_236 = V_1 -> V_3 . V_237 ;
F_124 ( V_2 , V_1 -> V_3 . V_173 ) ;
V_2 -> V_7 . V_8 = V_1 -> V_3 . V_4 . V_5 ;
V_2 -> V_7 . V_10 = V_1 -> V_3 . V_4 . V_9 ;
V_2 -> V_14 . V_8 = V_1 -> V_3 . V_13 . V_5 ;
V_2 -> V_14 . V_10 = V_1 -> V_3 . V_13 . V_9 ;
V_2 -> V_12 . V_8 = V_1 -> V_3 . V_11 . V_5 ;
V_2 -> V_12 . V_10 = V_1 -> V_3 . V_11 . V_9 ;
F_120 ( V_2 , V_1 ) ;
switch ( V_2 -> V_100 & V_101 ) {
case V_238 :
V_2 -> V_239 = & V_240 ;
V_2 -> V_241 = & V_242 ;
V_2 -> V_176 -> V_243 = & V_244 ;
break;
case V_43 :
if ( F_47 ( & F_48 ( V_2 -> V_53 ) -> V_54 ) )
V_2 -> V_239 = & V_245 ;
else
V_2 -> V_239 = & V_246 ;
V_2 -> V_241 = & V_247 ;
break;
case V_56 :
V_2 -> V_239 = & V_248 ;
if ( ! ( V_1 -> V_106 . V_249 & V_250 ) )
V_2 -> V_176 -> V_243 = & V_244 ;
break;
default:
V_2 -> V_239 = & V_240 ;
F_125 ( V_2 , V_2 -> V_100 , V_2 -> V_235 ) ;
break;
}
if ( ! F_126 ( V_1 ) ) {
F_127 ( V_2 ) ;
F_128 ( V_2 ) ;
}
F_129 ( V_1 , V_251 ) ;
F_5 () ;
F_130 ( V_2 ) ;
}
