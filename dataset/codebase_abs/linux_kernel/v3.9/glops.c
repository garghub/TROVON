static void F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
F_2 ( V_2 -> V_5 , L_1 ,
V_4 , ( unsigned long long ) V_4 -> V_6 , V_4 -> V_7 ,
V_4 -> V_8 -> V_9 , V_4 -> V_8 -> V_10 ) ;
F_2 ( V_2 -> V_5 , L_2 ,
V_2 -> V_11 . V_12 , V_2 -> V_11 . V_13 ,
F_3 ( V_2 ) ) ;
F_4 ( V_2 -> V_5 , L_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , bool V_14 )
{
struct V_15 * V_16 = V_2 -> V_5 ;
struct V_17 * V_18 = & V_2 -> V_19 ;
struct V_20 * V_21 , * V_22 ;
struct V_3 * V_4 ;
const unsigned long V_7 = ( 1UL << V_23 ) | ( 1UL << V_24 ) | ( 1UL << V_25 ) ;
T_1 V_26 ;
F_6 ( V_16 ) ;
F_7 ( & V_16 -> V_27 ) ;
F_8 (bd, tmp, head, bd_ail_gl_list) {
V_4 = V_21 -> V_28 ;
if ( V_4 -> V_7 & V_7 ) {
if ( V_14 )
continue;
F_1 ( V_2 , V_4 ) ;
}
V_26 = V_4 -> V_6 ;
V_4 -> V_29 = NULL ;
F_9 ( V_21 ) ;
V_21 -> V_28 = NULL ;
V_21 -> V_30 = V_26 ;
F_10 ( V_16 , V_21 ) ;
}
F_11 ( V_2 , ! V_14 && F_12 ( & V_2 -> V_31 ) ) ;
F_13 ( & V_16 -> V_27 ) ;
F_14 ( V_16 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_5 ;
struct V_32 V_33 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_34 = F_12 ( & V_2 -> V_31 ) ;
if ( ! V_33 . V_34 )
return;
V_33 . V_35 = 1 + F_16 ( V_16 , V_33 . V_34 , sizeof( V_36 ) ) ;
V_33 . V_37 = ( unsigned long ) F_17 ( 0 ) ;
F_18 ( V_16 -> V_38 ) ;
F_19 ( V_16 , V_33 . V_35 ) ;
F_20 ( V_39 -> V_40 ) ;
V_39 -> V_40 = & V_33 ;
F_5 ( V_2 , 0 ) ;
F_21 ( V_16 ) ;
F_22 ( V_16 , NULL ) ;
}
void F_23 ( struct V_1 * V_2 , bool V_14 )
{
struct V_15 * V_16 = V_2 -> V_5 ;
unsigned int V_41 = F_12 ( & V_2 -> V_31 ) ;
int V_42 ;
if ( ! V_41 )
return;
V_42 = F_24 ( V_16 , 0 , V_41 ) ;
if ( V_42 )
return;
F_5 ( V_2 , V_14 ) ;
F_21 ( V_16 ) ;
F_22 ( V_16 , NULL ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = F_3 ( V_2 ) ;
struct V_45 * V_46 ;
int error ;
if ( ! F_26 ( V_47 , & V_2 -> V_48 ) )
return;
F_11 ( V_2 , V_2 -> V_49 != V_50 ) ;
F_22 ( V_2 -> V_5 , V_2 ) ;
F_27 ( V_44 ) ;
error = F_28 ( V_44 ) ;
F_29 ( V_44 , error ) ;
F_15 ( V_2 ) ;
F_7 ( & V_2 -> V_51 ) ;
V_46 = V_2 -> V_52 ;
if ( V_46 )
F_30 ( V_46 ) ;
F_13 ( & V_2 -> V_51 ) ;
}
static void F_31 ( struct V_1 * V_2 , int V_10 )
{
struct V_43 * V_9 = F_3 ( V_2 ) ;
F_20 ( ! ( V_10 & V_53 ) ) ;
F_32 ( V_2 -> V_5 , ! F_12 ( & V_2 -> V_31 ) ) ;
F_33 ( V_9 , 0 ) ;
if ( V_2 -> V_52 ) {
struct V_45 * V_46 = (struct V_45 * ) V_2 -> V_52 ;
V_46 -> V_54 &= ~ V_55 ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = V_2 -> V_52 ;
struct V_43 * V_44 = F_3 ( V_2 ) ;
int error ;
if ( V_57 && ! F_35 ( V_57 -> V_58 . V_59 ) )
V_57 = NULL ;
if ( V_57 && F_26 ( V_60 , & V_57 -> V_61 ) )
F_36 ( V_57 -> V_58 . V_62 , 0 , 0 ) ;
if ( ! F_26 ( V_47 , & V_2 -> V_48 ) )
return;
F_11 ( V_2 , V_2 -> V_49 != V_50 ) ;
F_22 ( V_2 -> V_5 , V_2 ) ;
F_27 ( V_44 ) ;
if ( V_57 ) {
struct V_43 * V_9 = V_57 -> V_58 . V_62 ;
F_27 ( V_9 ) ;
error = F_28 ( V_9 ) ;
F_29 ( V_9 , error ) ;
}
error = F_28 ( V_44 ) ;
F_29 ( V_44 , error ) ;
F_15 ( V_2 ) ;
F_37 () ;
F_38 ( V_47 , & V_2 -> V_48 ) ;
}
static void F_39 ( struct V_1 * V_2 , int V_10 )
{
struct V_56 * V_57 = V_2 -> V_52 ;
F_32 ( V_2 -> V_5 , ! F_12 ( & V_2 -> V_31 ) ) ;
if ( V_10 & V_53 ) {
struct V_43 * V_9 = F_3 ( V_2 ) ;
F_33 ( V_9 , 0 ) ;
if ( V_57 ) {
F_40 ( V_63 , & V_57 -> V_61 ) ;
F_41 ( & V_57 -> V_58 ) ;
F_42 ( V_57 ) ;
}
}
if ( V_57 == F_43 ( V_2 -> V_5 -> V_64 ) ) {
F_22 ( V_2 -> V_5 , NULL ) ;
V_2 -> V_5 -> V_65 = 0 ;
}
if ( V_57 && F_35 ( V_57 -> V_58 . V_59 ) )
F_33 ( V_57 -> V_58 . V_62 , 0 ) ;
}
static int F_44 ( const struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_5 ;
struct V_66 * V_67 ;
if ( V_16 -> V_68 == V_2 -> V_52 || V_16 -> V_64 == V_2 -> V_52 )
return 0 ;
if ( ! F_45 ( & V_2 -> V_69 ) ) {
V_67 = F_46 ( V_2 -> V_69 . V_70 , struct V_66 , V_71 ) ;
if ( V_67 -> V_71 . V_70 != & V_2 -> V_69 )
return 0 ;
}
return 1 ;
}
static void F_47 ( struct V_72 * V_72 , T_2 V_73 )
{
if ( ( V_72 -> V_74 != V_73 ) && ( V_72 -> V_74 != 0 ) ) {
if ( V_73 == 0 )
F_48 ( V_72 ) ;
else
F_49 ( V_72 , V_73 ) ;
}
}
static int F_50 ( struct V_56 * V_57 , const void * V_75 )
{
const struct V_76 * V_77 = V_75 ;
struct V_78 V_79 ;
T_3 V_80 , V_81 ;
if ( F_51 ( V_57 -> V_82 != F_52 ( V_77 -> V_83 . V_84 ) ) )
goto V_85;
V_57 -> V_86 = F_52 ( V_77 -> V_83 . V_87 ) ;
V_57 -> V_58 . V_59 = F_53 ( V_77 -> V_88 ) ;
V_57 -> V_58 . V_89 = 0 ;
switch ( V_57 -> V_58 . V_59 & V_90 ) {
case V_91 :
case V_92 :
V_57 -> V_58 . V_89 = F_54 ( F_53 ( V_77 -> V_93 ) ,
F_53 ( V_77 -> V_94 ) ) ;
break;
} ;
F_55 ( & V_57 -> V_58 , F_53 ( V_77 -> V_95 ) ) ;
F_56 ( & V_57 -> V_58 , F_53 ( V_77 -> V_96 ) ) ;
F_47 ( & V_57 -> V_58 , F_53 ( V_77 -> V_97 ) ) ;
F_57 ( & V_57 -> V_58 , F_52 ( V_77 -> V_98 ) ) ;
F_58 ( & V_57 -> V_58 , F_52 ( V_77 -> V_99 ) ) ;
V_79 . V_100 = F_52 ( V_77 -> V_101 ) ;
V_79 . V_102 = F_53 ( V_77 -> V_103 ) ;
if ( F_59 ( & V_57 -> V_58 . V_104 , & V_79 ) < 0 )
V_57 -> V_58 . V_104 = V_79 ;
V_57 -> V_58 . V_105 . V_100 = F_52 ( V_77 -> V_106 ) ;
V_57 -> V_58 . V_105 . V_102 = F_53 ( V_77 -> V_107 ) ;
V_57 -> V_58 . V_108 . V_100 = F_52 ( V_77 -> V_109 ) ;
V_57 -> V_58 . V_108 . V_102 = F_53 ( V_77 -> V_110 ) ;
V_57 -> V_111 = F_52 ( V_77 -> V_112 ) ;
V_57 -> V_113 = F_52 ( V_77 -> V_114 ) ;
V_57 -> V_115 = F_53 ( V_77 -> V_116 ) ;
V_57 -> V_117 = F_52 ( V_77 -> V_118 ) ;
F_60 ( & V_57 -> V_58 ) ;
V_80 = F_61 ( V_77 -> V_119 ) ;
if ( F_51 ( V_80 > V_120 ) )
goto V_85;
V_57 -> V_121 = ( V_122 ) V_80 ;
V_81 = F_61 ( V_77 -> V_123 ) ;
if ( F_51 ( V_81 > V_124 ) )
goto V_85;
V_57 -> V_125 = ( V_122 ) V_81 ;
V_57 -> V_126 = F_53 ( V_77 -> V_127 ) ;
if ( F_35 ( V_57 -> V_58 . V_59 ) )
F_62 ( & V_57 -> V_58 ) ;
return 0 ;
V_85:
F_63 ( V_57 ) ;
return - V_128 ;
}
int F_64 ( struct V_56 * V_57 )
{
struct V_3 * V_129 ;
int error ;
error = F_65 ( V_57 , & V_129 ) ;
if ( error )
return error ;
error = F_50 ( V_57 , V_129 -> V_130 ) ;
F_66 ( V_129 ) ;
F_38 ( V_63 , & V_57 -> V_61 ) ;
return error ;
}
static int F_67 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = V_67 -> V_131 ;
struct V_15 * V_16 = V_2 -> V_5 ;
struct V_56 * V_57 = V_2 -> V_52 ;
int error = 0 ;
if ( ! V_57 || ( V_67 -> V_132 & V_133 ) )
return 0 ;
if ( F_68 ( V_63 , & V_57 -> V_61 ) ) {
error = F_64 ( V_57 ) ;
if ( error )
return error ;
}
if ( ( V_57 -> V_115 & V_134 ) &&
( V_2 -> V_49 == V_50 ) &&
( V_67 -> V_135 == V_50 ) ) {
F_7 ( & V_16 -> V_136 ) ;
if ( F_45 ( & V_57 -> V_137 ) )
F_69 ( & V_16 -> V_138 , & V_57 -> V_137 ) ;
F_13 ( & V_16 -> V_136 ) ;
F_70 ( & V_16 -> V_139 ) ;
return 1 ;
}
return error ;
}
static int F_71 ( struct V_140 * V_141 , const struct V_1 * V_2 )
{
const struct V_56 * V_57 = V_2 -> V_52 ;
if ( V_57 == NULL )
return 0 ;
F_72 ( V_141 , L_4 ,
( unsigned long long ) V_57 -> V_86 ,
( unsigned long long ) V_57 -> V_82 ,
F_73 ( V_57 -> V_58 . V_59 ) , V_57 -> V_61 ,
( unsigned int ) V_57 -> V_115 ,
( unsigned long long ) F_74 ( & V_57 -> V_58 ) ) ;
return 0 ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_5 ;
if ( V_2 -> V_49 != V_142 &&
F_68 ( V_143 , & V_16 -> V_144 ) ) {
F_76 ( V_16 ) ;
F_77 ( V_16 ) ;
}
}
static int F_78 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
struct V_15 * V_16 = V_2 -> V_5 ;
struct V_56 * V_57 = F_43 ( V_16 -> V_145 -> V_146 ) ;
struct V_1 * V_147 = V_57 -> V_148 ;
struct V_149 V_18 ;
int error ;
if ( F_68 ( V_143 , & V_16 -> V_144 ) ) {
V_147 -> V_150 -> V_151 ( V_147 , V_53 ) ;
error = F_79 ( V_16 -> V_145 , & V_18 ) ;
if ( error )
F_80 ( V_16 ) ;
if ( ! ( V_18 . V_152 & V_153 ) )
F_80 ( V_16 ) ;
if ( ! F_68 ( V_154 , & V_16 -> V_144 ) ) {
V_16 -> V_155 = V_18 . V_156 + 1 ;
F_81 ( V_16 , V_18 . V_157 ) ;
}
}
return 0 ;
}
static int F_82 ( const struct V_1 * V_2 )
{
return 0 ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = (struct V_56 * ) V_2 -> V_52 ;
struct V_15 * V_16 = V_2 -> V_5 ;
if ( V_16 -> V_38 -> V_158 & V_159 )
return;
if ( V_2 -> V_160 == V_142 &&
V_2 -> V_49 == V_161 && V_57 ) {
F_84 ( V_2 ) ;
if ( F_85 ( V_162 , & V_2 -> V_163 ) == 0 )
F_86 ( V_2 ) ;
}
}
