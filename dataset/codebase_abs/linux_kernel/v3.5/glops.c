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
F_11 ( ! V_14 && F_12 ( & V_2 -> V_31 ) ) ;
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
F_18 ( V_16 , V_33 . V_35 ) ;
F_11 ( V_38 -> V_39 ) ;
V_38 -> V_39 = & V_33 ;
F_5 ( V_2 , 0 ) ;
F_19 ( V_16 ) ;
F_20 ( V_16 , NULL ) ;
}
void F_21 ( struct V_1 * V_2 , bool V_14 )
{
struct V_15 * V_16 = V_2 -> V_5 ;
unsigned int V_40 = F_12 ( & V_2 -> V_31 ) ;
int V_41 ;
if ( ! V_40 )
return;
V_41 = F_22 ( V_16 , 0 , V_40 ) ;
if ( V_41 )
return;
F_5 ( V_2 , V_14 ) ;
F_19 ( V_16 ) ;
F_20 ( V_16 , NULL ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_3 ( V_2 ) ;
struct V_44 * V_45 ;
int error ;
if ( ! F_24 ( V_46 , & V_2 -> V_47 ) )
return;
F_11 ( V_2 -> V_48 != V_49 ) ;
F_20 ( V_2 -> V_5 , V_2 ) ;
F_25 ( V_43 ) ;
error = F_26 ( V_43 ) ;
F_27 ( V_43 , error ) ;
F_15 ( V_2 ) ;
F_7 ( & V_2 -> V_50 ) ;
V_45 = V_2 -> V_51 ;
if ( V_45 )
F_28 ( V_45 ) ;
F_13 ( & V_2 -> V_50 ) ;
}
static void F_29 ( struct V_1 * V_2 , int V_10 )
{
struct V_42 * V_9 = F_3 ( V_2 ) ;
F_11 ( ! ( V_10 & V_52 ) ) ;
F_30 ( V_2 -> V_5 , ! F_12 ( & V_2 -> V_31 ) ) ;
F_31 ( V_9 , 0 ) ;
if ( V_2 -> V_51 ) {
struct V_44 * V_45 = (struct V_44 * ) V_2 -> V_51 ;
V_45 -> V_53 &= ~ V_54 ;
}
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = V_2 -> V_51 ;
struct V_42 * V_43 = F_3 ( V_2 ) ;
int error ;
if ( V_56 && ! F_33 ( V_56 -> V_57 . V_58 ) )
V_56 = NULL ;
if ( V_56 && F_24 ( V_59 , & V_56 -> V_60 ) )
F_34 ( V_56 -> V_57 . V_61 , 0 , 0 ) ;
if ( ! F_24 ( V_46 , & V_2 -> V_47 ) )
return;
F_11 ( V_2 -> V_48 != V_49 ) ;
F_20 ( V_2 -> V_5 , V_2 ) ;
F_25 ( V_43 ) ;
if ( V_56 ) {
struct V_42 * V_9 = V_56 -> V_57 . V_61 ;
F_25 ( V_9 ) ;
error = F_26 ( V_9 ) ;
F_27 ( V_9 , error ) ;
}
error = F_26 ( V_43 ) ;
F_27 ( V_43 , error ) ;
F_15 ( V_2 ) ;
F_35 () ;
F_36 ( V_46 , & V_2 -> V_47 ) ;
}
static void F_37 ( struct V_1 * V_2 , int V_10 )
{
struct V_55 * V_56 = V_2 -> V_51 ;
F_30 ( V_2 -> V_5 , ! F_12 ( & V_2 -> V_31 ) ) ;
if ( V_10 & V_52 ) {
struct V_42 * V_9 = F_3 ( V_2 ) ;
F_31 ( V_9 , 0 ) ;
if ( V_56 ) {
F_38 ( V_62 , & V_56 -> V_60 ) ;
F_39 ( & V_56 -> V_57 ) ;
F_40 ( V_56 ) ;
}
}
if ( V_56 == F_41 ( V_2 -> V_5 -> V_63 ) ) {
F_20 ( V_2 -> V_5 , NULL ) ;
V_2 -> V_5 -> V_64 = 0 ;
}
if ( V_56 && F_33 ( V_56 -> V_57 . V_58 ) )
F_31 ( V_56 -> V_57 . V_61 , 0 ) ;
}
static int F_42 ( const struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_5 ;
struct V_65 * V_66 ;
if ( V_16 -> V_67 == V_2 -> V_51 || V_16 -> V_63 == V_2 -> V_51 )
return 0 ;
if ( ! F_43 ( & V_2 -> V_68 ) ) {
V_66 = F_44 ( V_2 -> V_68 . V_69 , struct V_65 , V_70 ) ;
if ( V_66 -> V_70 . V_69 != & V_2 -> V_68 )
return 0 ;
}
return 1 ;
}
static void F_45 ( struct V_71 * V_71 , T_2 V_72 )
{
if ( ( V_71 -> V_73 != V_72 ) && ( V_71 -> V_73 != 0 ) ) {
if ( V_72 == 0 )
F_46 ( V_71 ) ;
else
F_47 ( V_71 , V_72 ) ;
}
}
static int F_48 ( struct V_55 * V_56 , const void * V_74 )
{
const struct V_75 * V_76 = V_74 ;
struct V_77 V_78 ;
T_3 V_79 , V_80 ;
if ( F_49 ( V_56 -> V_81 != F_50 ( V_76 -> V_82 . V_83 ) ) )
goto V_84;
V_56 -> V_85 = F_50 ( V_76 -> V_82 . V_86 ) ;
V_56 -> V_57 . V_58 = F_51 ( V_76 -> V_87 ) ;
V_56 -> V_57 . V_88 = 0 ;
switch ( V_56 -> V_57 . V_58 & V_89 ) {
case V_90 :
case V_91 :
V_56 -> V_57 . V_88 = F_52 ( F_51 ( V_76 -> V_92 ) ,
F_51 ( V_76 -> V_93 ) ) ;
break;
} ;
V_56 -> V_57 . V_94 = F_51 ( V_76 -> V_95 ) ;
V_56 -> V_57 . V_96 = F_51 ( V_76 -> V_97 ) ;
F_45 ( & V_56 -> V_57 , F_51 ( V_76 -> V_98 ) ) ;
F_53 ( & V_56 -> V_57 , F_50 ( V_76 -> V_99 ) ) ;
F_54 ( & V_56 -> V_57 , F_50 ( V_76 -> V_100 ) ) ;
V_78 . V_101 = F_50 ( V_76 -> V_102 ) ;
V_78 . V_103 = F_51 ( V_76 -> V_104 ) ;
if ( F_55 ( & V_56 -> V_57 . V_105 , & V_78 ) < 0 )
V_56 -> V_57 . V_105 = V_78 ;
V_56 -> V_57 . V_106 . V_101 = F_50 ( V_76 -> V_107 ) ;
V_56 -> V_57 . V_106 . V_103 = F_51 ( V_76 -> V_108 ) ;
V_56 -> V_57 . V_109 . V_101 = F_50 ( V_76 -> V_110 ) ;
V_56 -> V_57 . V_109 . V_103 = F_51 ( V_76 -> V_111 ) ;
V_56 -> V_112 = F_50 ( V_76 -> V_113 ) ;
V_56 -> V_114 = F_50 ( V_76 -> V_115 ) ;
V_56 -> V_116 = F_51 ( V_76 -> V_117 ) ;
V_56 -> V_118 = F_50 ( V_76 -> V_119 ) ;
F_56 ( & V_56 -> V_57 ) ;
V_79 = F_57 ( V_76 -> V_120 ) ;
if ( F_49 ( V_79 > V_121 ) )
goto V_84;
V_56 -> V_122 = ( V_123 ) V_79 ;
V_80 = F_57 ( V_76 -> V_124 ) ;
if ( F_49 ( V_80 > V_125 ) )
goto V_84;
V_56 -> V_126 = ( V_123 ) V_80 ;
V_56 -> V_127 = F_51 ( V_76 -> V_128 ) ;
if ( F_33 ( V_56 -> V_57 . V_58 ) )
F_58 ( & V_56 -> V_57 ) ;
return 0 ;
V_84:
F_59 ( V_56 ) ;
return - V_129 ;
}
int F_60 ( struct V_55 * V_56 )
{
struct V_3 * V_130 ;
int error ;
error = F_61 ( V_56 , & V_130 ) ;
if ( error )
return error ;
error = F_48 ( V_56 , V_130 -> V_131 ) ;
F_62 ( V_130 ) ;
F_36 ( V_62 , & V_56 -> V_60 ) ;
return error ;
}
static int F_63 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_132 ;
struct V_15 * V_16 = V_2 -> V_5 ;
struct V_55 * V_56 = V_2 -> V_51 ;
int error = 0 ;
if ( ! V_56 || ( V_66 -> V_133 & V_134 ) )
return 0 ;
if ( F_64 ( V_62 , & V_56 -> V_60 ) ) {
error = F_60 ( V_56 ) ;
if ( error )
return error ;
}
if ( ( V_56 -> V_116 & V_135 ) &&
( V_2 -> V_48 == V_49 ) &&
( V_66 -> V_136 == V_49 ) ) {
F_7 ( & V_16 -> V_137 ) ;
if ( F_43 ( & V_56 -> V_138 ) )
F_65 ( & V_16 -> V_139 , & V_56 -> V_138 ) ;
F_13 ( & V_16 -> V_137 ) ;
F_66 ( & V_16 -> V_140 ) ;
return 1 ;
}
return error ;
}
static int F_67 ( struct V_141 * V_142 , const struct V_1 * V_2 )
{
const struct V_55 * V_56 = V_2 -> V_51 ;
if ( V_56 == NULL )
return 0 ;
F_68 ( V_142 , L_4 ,
( unsigned long long ) V_56 -> V_85 ,
( unsigned long long ) V_56 -> V_81 ,
F_69 ( V_56 -> V_57 . V_58 ) , V_56 -> V_60 ,
( unsigned int ) V_56 -> V_116 ,
( unsigned long long ) F_70 ( & V_56 -> V_57 ) ) ;
return 0 ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_5 ;
if ( V_2 -> V_48 != V_143 &&
F_64 ( V_144 , & V_16 -> V_145 ) ) {
F_72 ( V_16 ) ;
F_73 ( V_16 ) ;
}
}
static int F_74 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
struct V_15 * V_16 = V_2 -> V_5 ;
struct V_55 * V_56 = F_41 ( V_16 -> V_146 -> V_147 ) ;
struct V_1 * V_148 = V_56 -> V_149 ;
struct V_150 V_18 ;
int error ;
if ( F_64 ( V_144 , & V_16 -> V_145 ) ) {
V_148 -> V_151 -> V_152 ( V_148 , V_52 ) ;
error = F_75 ( V_16 -> V_146 , & V_18 ) ;
if ( error )
F_76 ( V_16 ) ;
if ( ! ( V_18 . V_153 & V_154 ) )
F_76 ( V_16 ) ;
if ( ! F_64 ( V_155 , & V_16 -> V_145 ) ) {
V_16 -> V_156 = V_18 . V_157 + 1 ;
F_77 ( V_16 , V_18 . V_158 ) ;
}
}
return 0 ;
}
static int F_78 ( const struct V_1 * V_2 )
{
return 0 ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = (struct V_55 * ) V_2 -> V_51 ;
struct V_15 * V_16 = V_2 -> V_5 ;
if ( V_16 -> V_159 -> V_160 & V_161 )
return;
if ( V_2 -> V_162 == V_143 &&
V_2 -> V_48 == V_163 && V_56 ) {
F_80 ( V_2 ) ;
if ( F_81 ( V_164 , & V_2 -> V_165 ) == 0 )
F_82 ( V_2 ) ;
}
}
