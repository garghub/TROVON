static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_2 -> V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
F_2 ( & V_4 -> V_13 ) ;
while ( ! F_3 ( V_7 ) ) {
V_10 = F_4 ( V_7 -> V_14 , struct V_9 ,
V_15 ) ;
V_12 = V_10 -> V_16 ;
F_5 ( V_10 ) ;
V_10 -> V_16 = NULL ;
V_12 -> V_17 = NULL ;
F_6 ( & V_4 -> V_13 ) ;
V_10 -> V_18 = V_12 -> V_19 ;
F_7 ( V_4 ) ;
F_8 ( V_4 , ! F_9 ( V_12 ) ) ;
F_10 ( V_4 , V_10 ) ;
F_11 ( V_4 ) ;
F_2 ( & V_4 -> V_13 ) ;
}
F_8 ( V_4 , ! F_12 ( & V_2 -> V_20 ) ) ;
F_6 ( & V_4 -> V_13 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_21 V_22 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_22 . V_23 = F_12 ( & V_2 -> V_20 ) ;
if ( ! V_22 . V_23 )
return;
V_22 . V_24 = 1 + F_14 ( V_4 , V_22 . V_23 , sizeof( V_25 ) ) ;
V_22 . V_26 = ( unsigned long ) F_15 ( 0 ) ;
F_16 ( & V_22 . V_27 ) ;
F_17 ( V_4 , V_22 . V_24 ) ;
F_18 ( V_28 -> V_29 ) ;
V_28 -> V_29 = & V_22 ;
F_1 ( V_2 ) ;
F_19 ( V_4 ) ;
F_20 ( V_4 , NULL ) ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_30 = F_12 ( & V_2 -> V_20 ) ;
int V_31 ;
if ( ! V_30 )
return;
V_31 = F_22 ( V_4 , 0 , V_30 ) ;
if ( V_31 )
return;
F_1 ( V_2 ) ;
F_19 ( V_4 ) ;
F_20 ( V_4 , NULL ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_24 ( V_2 ) ;
int error ;
if ( ! F_25 ( V_34 , & V_2 -> V_35 ) )
return;
F_18 ( V_2 -> V_36 != V_37 ) ;
F_20 ( V_2 -> V_5 , V_2 ) ;
F_26 ( V_33 ) ;
error = F_27 ( V_33 ) ;
F_28 ( V_33 , error ) ;
F_13 ( V_2 ) ;
}
static void F_29 ( struct V_1 * V_2 , int V_38 )
{
struct V_32 * V_39 = F_24 ( V_2 ) ;
F_18 ( ! ( V_38 & V_40 ) ) ;
F_8 ( V_2 -> V_5 , ! F_12 ( & V_2 -> V_20 ) ) ;
F_30 ( V_39 , 0 ) ;
if ( V_2 -> V_41 ) {
struct V_42 * V_43 = (struct V_42 * ) V_2 -> V_41 ;
V_43 -> V_44 &= ~ V_45 ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_41 ;
struct V_32 * V_33 = F_24 ( V_2 ) ;
int error ;
if ( V_47 && ! F_32 ( V_47 -> V_48 . V_49 ) )
V_47 = NULL ;
if ( V_47 && F_25 ( V_50 , & V_47 -> V_51 ) )
F_33 ( V_47 -> V_48 . V_52 , 0 , 0 ) ;
if ( ! F_25 ( V_34 , & V_2 -> V_35 ) )
return;
F_18 ( V_2 -> V_36 != V_37 ) ;
F_20 ( V_2 -> V_5 , V_2 ) ;
F_26 ( V_33 ) ;
if ( V_47 ) {
struct V_32 * V_39 = V_47 -> V_48 . V_52 ;
F_26 ( V_39 ) ;
error = F_27 ( V_39 ) ;
F_28 ( V_39 , error ) ;
}
error = F_27 ( V_33 ) ;
F_28 ( V_33 , error ) ;
F_13 ( V_2 ) ;
F_34 () ;
F_35 ( V_34 , & V_2 -> V_35 ) ;
}
static void F_36 ( struct V_1 * V_2 , int V_38 )
{
struct V_46 * V_47 = V_2 -> V_41 ;
F_8 ( V_2 -> V_5 , ! F_12 ( & V_2 -> V_20 ) ) ;
if ( V_38 & V_40 ) {
struct V_32 * V_39 = F_24 ( V_2 ) ;
F_30 ( V_39 , 0 ) ;
if ( V_47 ) {
F_37 ( V_53 , & V_47 -> V_51 ) ;
F_38 ( & V_47 -> V_48 ) ;
F_39 ( V_47 ) ;
}
}
if ( V_47 == F_40 ( V_2 -> V_5 -> V_54 ) ) {
F_20 ( V_2 -> V_5 , NULL ) ;
V_2 -> V_5 -> V_55 = 0 ;
}
if ( V_47 && F_32 ( V_47 -> V_48 . V_49 ) )
F_30 ( V_47 -> V_48 . V_52 , 0 ) ;
}
static int F_41 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_56 * V_57 ;
if ( V_4 -> V_58 == V_2 -> V_41 || V_4 -> V_54 == V_2 -> V_41 )
return 0 ;
if ( ! F_3 ( & V_2 -> V_59 ) ) {
V_57 = F_4 ( V_2 -> V_59 . V_14 , struct V_56 , V_60 ) ;
if ( V_57 -> V_60 . V_14 != & V_2 -> V_59 )
return 0 ;
}
return 1 ;
}
static void F_42 ( struct V_61 * V_61 , T_1 V_62 )
{
if ( ( V_61 -> V_63 != V_62 ) && ( V_61 -> V_63 != 0 ) ) {
if ( V_62 == 0 )
F_43 ( V_61 ) ;
else
V_61 -> V_63 = V_62 ;
}
}
static int F_44 ( struct V_46 * V_47 , const void * V_64 )
{
const struct V_65 * V_66 = V_64 ;
struct V_67 V_68 ;
T_2 V_69 , V_70 ;
if ( F_45 ( V_47 -> V_71 != F_46 ( V_66 -> V_72 . V_73 ) ) )
goto V_74;
V_47 -> V_75 = F_46 ( V_66 -> V_72 . V_76 ) ;
V_47 -> V_48 . V_49 = F_47 ( V_66 -> V_77 ) ;
V_47 -> V_48 . V_78 = 0 ;
switch ( V_47 -> V_48 . V_49 & V_79 ) {
case V_80 :
case V_81 :
V_47 -> V_48 . V_78 = F_48 ( F_47 ( V_66 -> V_82 ) ,
F_47 ( V_66 -> V_83 ) ) ;
break;
} ;
V_47 -> V_48 . V_84 = F_47 ( V_66 -> V_85 ) ;
V_47 -> V_48 . V_86 = F_47 ( V_66 -> V_87 ) ;
F_42 ( & V_47 -> V_48 , F_47 ( V_66 -> V_88 ) ) ;
F_49 ( & V_47 -> V_48 , F_46 ( V_66 -> V_89 ) ) ;
F_50 ( & V_47 -> V_48 , F_46 ( V_66 -> V_90 ) ) ;
V_68 . V_91 = F_46 ( V_66 -> V_92 ) ;
V_68 . V_93 = F_47 ( V_66 -> V_94 ) ;
if ( F_51 ( & V_47 -> V_48 . V_95 , & V_68 ) < 0 )
V_47 -> V_48 . V_95 = V_68 ;
V_47 -> V_48 . V_96 . V_91 = F_46 ( V_66 -> V_97 ) ;
V_47 -> V_48 . V_96 . V_93 = F_47 ( V_66 -> V_98 ) ;
V_47 -> V_48 . V_99 . V_91 = F_46 ( V_66 -> V_100 ) ;
V_47 -> V_48 . V_99 . V_93 = F_47 ( V_66 -> V_101 ) ;
V_47 -> V_102 = F_46 ( V_66 -> V_103 ) ;
V_47 -> V_104 = F_46 ( V_66 -> V_105 ) ;
V_47 -> V_106 = F_47 ( V_66 -> V_107 ) ;
V_47 -> V_108 = F_46 ( V_66 -> V_109 ) ;
F_52 ( & V_47 -> V_48 ) ;
V_69 = F_53 ( V_66 -> V_110 ) ;
if ( F_45 ( V_69 > V_111 ) )
goto V_74;
V_47 -> V_112 = ( V_113 ) V_69 ;
V_70 = F_53 ( V_66 -> V_114 ) ;
if ( F_45 ( V_70 > V_115 ) )
goto V_74;
V_47 -> V_116 = ( V_113 ) V_70 ;
V_47 -> V_117 = F_47 ( V_66 -> V_118 ) ;
if ( F_32 ( V_47 -> V_48 . V_49 ) )
F_54 ( & V_47 -> V_48 ) ;
return 0 ;
V_74:
F_55 ( V_47 ) ;
return - V_119 ;
}
int F_56 ( struct V_46 * V_47 )
{
struct V_11 * V_120 ;
int error ;
error = F_57 ( V_47 , & V_120 ) ;
if ( error )
return error ;
if ( F_58 ( F_59 ( & V_47 -> V_48 ) , V_120 , V_121 ) ) {
F_60 ( V_120 ) ;
return - V_119 ;
}
error = F_44 ( V_47 , V_120 -> V_122 ) ;
F_60 ( V_120 ) ;
F_35 ( V_53 , & V_47 -> V_51 ) ;
return error ;
}
static int F_61 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = V_57 -> V_123 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_46 * V_47 = V_2 -> V_41 ;
int error = 0 ;
if ( ! V_47 || ( V_57 -> V_124 & V_125 ) )
return 0 ;
if ( F_62 ( V_53 , & V_47 -> V_51 ) ) {
error = F_56 ( V_47 ) ;
if ( error )
return error ;
}
if ( ( V_47 -> V_106 & V_126 ) &&
( V_2 -> V_36 == V_37 ) &&
( V_57 -> V_127 == V_37 ) ) {
F_2 ( & V_4 -> V_128 ) ;
if ( F_3 ( & V_47 -> V_129 ) )
F_63 ( & V_4 -> V_130 , & V_47 -> V_129 ) ;
F_6 ( & V_4 -> V_128 ) ;
F_64 ( & V_4 -> V_131 ) ;
return 1 ;
}
return error ;
}
static int F_65 ( struct V_132 * V_133 , const struct V_1 * V_2 )
{
const struct V_46 * V_47 = V_2 -> V_41 ;
if ( V_47 == NULL )
return 0 ;
F_66 ( V_133 , L_1 ,
( unsigned long long ) V_47 -> V_75 ,
( unsigned long long ) V_47 -> V_71 ,
F_67 ( V_47 -> V_48 . V_49 ) , V_47 -> V_51 ,
( unsigned int ) V_47 -> V_106 ,
( unsigned long long ) F_68 ( & V_47 -> V_48 ) ) ;
return 0 ;
}
static int F_69 ( struct V_56 * V_57 )
{
return F_70 ( V_57 -> V_123 -> V_41 ) ;
}
static void F_71 ( struct V_56 * V_57 )
{
F_72 ( V_57 -> V_123 -> V_41 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_2 -> V_36 != V_134 &&
F_62 ( V_135 , & V_4 -> V_136 ) ) {
F_74 ( V_4 ) ;
F_75 ( V_4 ) ;
}
}
static int F_76 ( struct V_1 * V_2 , struct V_56 * V_57 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_46 * V_47 = F_40 ( V_4 -> V_137 -> V_138 ) ;
struct V_1 * V_139 = V_47 -> V_140 ;
struct V_141 V_7 ;
int error ;
if ( F_62 ( V_135 , & V_4 -> V_136 ) ) {
V_139 -> V_142 -> V_143 ( V_139 , V_40 ) ;
error = F_77 ( V_4 -> V_137 , & V_7 ) ;
if ( error )
F_78 ( V_4 ) ;
if ( ! ( V_7 . V_144 & V_145 ) )
F_78 ( V_4 ) ;
if ( ! F_62 ( V_146 , & V_4 -> V_136 ) ) {
V_4 -> V_147 = V_7 . V_148 + 1 ;
F_79 ( V_4 , V_7 . V_149 ) ;
}
}
return 0 ;
}
static int F_80 ( const struct V_1 * V_2 )
{
return 0 ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = (struct V_46 * ) V_2 -> V_41 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_150 -> V_151 & V_152 )
return;
if ( V_2 -> V_153 == V_134 &&
V_2 -> V_36 == V_154 && V_47 ) {
F_82 ( V_2 ) ;
if ( F_83 ( V_155 , & V_2 -> V_156 ) == 0 )
F_84 ( V_2 ) ;
}
}
