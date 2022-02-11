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
static void F_5 ( struct V_1 * V_2 , bool V_14 ,
unsigned int V_15 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_18 * V_19 = & V_2 -> V_20 ;
struct V_21 * V_22 , * V_23 ;
struct V_3 * V_4 ;
const unsigned long V_7 = ( 1UL << V_24 ) | ( 1UL << V_25 ) | ( 1UL << V_26 ) ;
F_6 ( V_17 ) ;
F_7 ( & V_17 -> V_27 ) ;
F_8 (bd, tmp, head, bd_ail_gl_list) {
if ( V_15 == 0 )
break;
V_4 = V_22 -> V_28 ;
if ( V_4 -> V_7 & V_7 ) {
if ( V_14 )
continue;
F_1 ( V_2 , V_4 ) ;
}
F_9 ( V_17 , V_22 ) ;
V_15 -- ;
}
F_10 ( V_2 , ! V_14 && F_11 ( & V_2 -> V_29 ) ) ;
F_12 ( & V_17 -> V_27 ) ;
F_13 ( V_17 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_30 V_31 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_32 = F_11 ( & V_2 -> V_29 ) ;
if ( ! V_31 . V_32 )
return;
V_31 . V_33 = 1 + F_15 ( V_17 , V_31 . V_32 , sizeof( V_34 ) ) ;
V_31 . V_35 = ( unsigned long ) F_16 ( 0 ) ;
F_17 ( V_17 -> V_36 ) ;
F_18 ( V_17 , V_31 . V_33 ) ;
F_19 ( V_37 -> V_38 ) ;
V_37 -> V_38 = & V_31 ;
F_5 ( V_2 , 0 , V_31 . V_32 ) ;
F_20 ( V_17 ) ;
F_21 ( V_17 , NULL ) ;
}
void F_22 ( struct V_1 * V_2 , bool V_14 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
unsigned int V_39 = F_11 ( & V_2 -> V_29 ) ;
unsigned int V_40 = ( V_17 -> V_41 . V_42 - sizeof( struct V_43 ) ) / sizeof( V_34 ) ;
int V_44 ;
if ( ! V_39 )
return;
while ( V_39 > V_40 )
V_40 += ( V_17 -> V_41 . V_42 - sizeof( struct V_45 ) ) / sizeof( V_34 ) ;
V_44 = F_23 ( V_17 , 0 , V_40 ) ;
if ( V_44 )
return;
F_5 ( V_2 , V_14 , V_40 ) ;
F_20 ( V_17 ) ;
F_21 ( V_17 , NULL ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = F_3 ( V_2 ) ;
struct V_48 * V_49 ;
int error ;
if ( ! F_25 ( V_50 , & V_2 -> V_51 ) )
return;
F_10 ( V_2 , V_2 -> V_52 != V_53 ) ;
F_21 ( V_2 -> V_5 , V_2 ) ;
F_26 ( V_47 ) ;
error = F_27 ( V_47 ) ;
F_28 ( V_47 , error ) ;
F_14 ( V_2 ) ;
F_7 ( & V_2 -> V_54 ) ;
V_49 = V_2 -> V_55 ;
if ( V_49 )
F_29 ( V_49 ) ;
F_12 ( & V_2 -> V_54 ) ;
}
static void F_30 ( struct V_1 * V_2 , int V_10 )
{
struct V_46 * V_9 = F_3 ( V_2 ) ;
F_19 ( ! ( V_10 & V_56 ) ) ;
F_31 ( V_2 -> V_5 , ! F_11 ( & V_2 -> V_29 ) ) ;
F_32 ( V_9 , 0 ) ;
if ( V_2 -> V_55 ) {
struct V_48 * V_49 = (struct V_48 * ) V_2 -> V_55 ;
V_49 -> V_57 &= ~ V_58 ;
}
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = V_2 -> V_55 ;
struct V_46 * V_47 = F_3 ( V_2 ) ;
int error ;
if ( V_60 && ! F_34 ( V_60 -> V_61 . V_62 ) )
V_60 = NULL ;
if ( V_60 ) {
if ( F_25 ( V_63 , & V_60 -> V_64 ) )
F_35 ( V_60 -> V_61 . V_65 , 0 , 0 ) ;
F_36 ( & V_60 -> V_61 ) ;
}
if ( ! F_25 ( V_50 , & V_2 -> V_51 ) )
return;
F_10 ( V_2 , V_2 -> V_52 != V_53 ) ;
F_21 ( V_2 -> V_5 , V_2 ) ;
F_26 ( V_47 ) ;
if ( V_60 ) {
struct V_46 * V_9 = V_60 -> V_61 . V_65 ;
F_26 ( V_9 ) ;
error = F_27 ( V_9 ) ;
F_28 ( V_9 , error ) ;
}
error = F_27 ( V_47 ) ;
F_28 ( V_47 , error ) ;
F_14 ( V_2 ) ;
F_37 () ;
F_38 ( V_50 , & V_2 -> V_51 ) ;
}
static void F_39 ( struct V_1 * V_2 , int V_10 )
{
struct V_59 * V_60 = V_2 -> V_55 ;
F_31 ( V_2 -> V_5 , ! F_11 ( & V_2 -> V_29 ) ) ;
if ( V_10 & V_56 ) {
struct V_46 * V_9 = F_3 ( V_2 ) ;
F_32 ( V_9 , 0 ) ;
if ( V_60 ) {
F_40 ( V_66 , & V_60 -> V_64 ) ;
F_41 ( & V_60 -> V_61 ) ;
F_42 ( V_60 ) ;
}
}
if ( V_60 == F_43 ( V_2 -> V_5 -> V_67 ) ) {
F_21 ( V_2 -> V_5 , NULL ) ;
V_2 -> V_5 -> V_68 = 0 ;
}
if ( V_60 && F_34 ( V_60 -> V_61 . V_62 ) )
F_32 ( V_60 -> V_61 . V_65 , 0 ) ;
}
static int F_44 ( const struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_69 * V_70 ;
if ( V_17 -> V_71 == V_2 -> V_55 || V_17 -> V_67 == V_2 -> V_55 )
return 0 ;
if ( ! F_45 ( & V_2 -> V_72 ) ) {
V_70 = F_46 ( V_2 -> V_72 . V_73 , struct V_69 , V_74 ) ;
if ( V_70 -> V_74 . V_73 != & V_2 -> V_72 )
return 0 ;
}
return 1 ;
}
static void F_47 ( struct V_75 * V_75 , T_1 V_76 )
{
if ( ( V_75 -> V_77 != V_76 ) && ( V_75 -> V_77 != 0 ) ) {
if ( V_76 == 0 )
F_48 ( V_75 ) ;
else
F_49 ( V_75 , V_76 ) ;
}
}
static int F_50 ( struct V_59 * V_60 , const void * V_78 )
{
const struct V_79 * V_80 = V_78 ;
struct V_81 V_82 ;
T_2 V_83 , V_84 ;
if ( F_51 ( V_60 -> V_85 != F_52 ( V_80 -> V_86 . V_87 ) ) )
goto V_88;
V_60 -> V_89 = F_52 ( V_80 -> V_86 . V_90 ) ;
V_60 -> V_61 . V_62 = F_53 ( V_80 -> V_91 ) ;
V_60 -> V_61 . V_92 = 0 ;
switch ( V_60 -> V_61 . V_62 & V_93 ) {
case V_94 :
case V_95 :
V_60 -> V_61 . V_92 = F_54 ( F_53 ( V_80 -> V_96 ) ,
F_53 ( V_80 -> V_97 ) ) ;
break;
} ;
F_55 ( & V_60 -> V_61 , F_53 ( V_80 -> V_98 ) ) ;
F_56 ( & V_60 -> V_61 , F_53 ( V_80 -> V_99 ) ) ;
F_47 ( & V_60 -> V_61 , F_53 ( V_80 -> V_100 ) ) ;
F_57 ( & V_60 -> V_61 , F_52 ( V_80 -> V_101 ) ) ;
F_58 ( & V_60 -> V_61 , F_52 ( V_80 -> V_102 ) ) ;
V_82 . V_103 = F_52 ( V_80 -> V_104 ) ;
V_82 . V_105 = F_53 ( V_80 -> V_106 ) ;
if ( F_59 ( & V_60 -> V_61 . V_107 , & V_82 ) < 0 )
V_60 -> V_61 . V_107 = V_82 ;
V_60 -> V_61 . V_108 . V_103 = F_52 ( V_80 -> V_109 ) ;
V_60 -> V_61 . V_108 . V_105 = F_53 ( V_80 -> V_110 ) ;
V_60 -> V_61 . V_111 . V_103 = F_52 ( V_80 -> V_112 ) ;
V_60 -> V_61 . V_111 . V_105 = F_53 ( V_80 -> V_113 ) ;
V_60 -> V_114 = F_52 ( V_80 -> V_115 ) ;
V_60 -> V_116 = F_52 ( V_80 -> V_117 ) ;
V_60 -> V_118 = F_53 ( V_80 -> V_119 ) ;
V_60 -> V_120 = F_52 ( V_80 -> V_121 ) ;
F_60 ( & V_60 -> V_61 ) ;
V_83 = F_61 ( V_80 -> V_122 ) ;
if ( F_51 ( V_83 > V_123 ) )
goto V_88;
V_60 -> V_124 = ( V_125 ) V_83 ;
V_84 = F_61 ( V_80 -> V_126 ) ;
if ( F_51 ( V_84 > V_127 ) )
goto V_88;
V_60 -> V_128 = ( V_125 ) V_84 ;
V_60 -> V_129 = F_53 ( V_80 -> V_130 ) ;
if ( F_34 ( V_60 -> V_61 . V_62 ) )
F_62 ( & V_60 -> V_61 ) ;
return 0 ;
V_88:
F_63 ( V_60 ) ;
return - V_131 ;
}
int F_64 ( struct V_59 * V_60 )
{
struct V_3 * V_132 ;
int error ;
error = F_65 ( V_60 , & V_132 ) ;
if ( error )
return error ;
error = F_50 ( V_60 , V_132 -> V_133 ) ;
F_66 ( V_132 ) ;
F_38 ( V_66 , & V_60 -> V_64 ) ;
return error ;
}
static int F_67 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = V_70 -> V_134 ;
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_59 * V_60 = V_2 -> V_55 ;
int error = 0 ;
if ( ! V_60 || ( V_70 -> V_135 & V_136 ) )
return 0 ;
if ( F_68 ( V_66 , & V_60 -> V_64 ) ) {
error = F_64 ( V_60 ) ;
if ( error )
return error ;
}
if ( V_70 -> V_137 != V_138 )
F_36 ( & V_60 -> V_61 ) ;
if ( ( V_60 -> V_118 & V_139 ) &&
( V_2 -> V_52 == V_53 ) &&
( V_70 -> V_137 == V_53 ) ) {
F_7 ( & V_17 -> V_140 ) ;
if ( F_45 ( & V_60 -> V_141 ) )
F_69 ( & V_17 -> V_142 , & V_60 -> V_141 ) ;
F_12 ( & V_17 -> V_140 ) ;
F_70 ( & V_17 -> V_143 ) ;
return 1 ;
}
return error ;
}
static int F_71 ( struct V_144 * V_145 , const struct V_1 * V_2 )
{
const struct V_59 * V_60 = V_2 -> V_55 ;
if ( V_60 == NULL )
return 0 ;
F_72 ( V_145 , L_4 ,
( unsigned long long ) V_60 -> V_89 ,
( unsigned long long ) V_60 -> V_85 ,
F_73 ( V_60 -> V_61 . V_62 ) , V_60 -> V_64 ,
( unsigned int ) V_60 -> V_118 ,
( unsigned long long ) F_74 ( & V_60 -> V_61 ) ) ;
return 0 ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
if ( V_2 -> V_52 != V_146 &&
F_68 ( V_147 , & V_17 -> V_148 ) ) {
F_76 ( V_17 ) ;
F_77 ( V_17 ) ;
}
}
static int F_78 ( struct V_1 * V_2 , struct V_69 * V_70 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_59 * V_60 = F_43 ( V_17 -> V_149 -> V_150 ) ;
struct V_1 * V_151 = V_60 -> V_152 ;
struct V_153 V_19 ;
int error ;
if ( F_68 ( V_147 , & V_17 -> V_148 ) ) {
V_151 -> V_154 -> V_155 ( V_151 , V_56 ) ;
error = F_79 ( V_17 -> V_149 , & V_19 ) ;
if ( error )
F_80 ( V_17 ) ;
if ( ! ( V_19 . V_156 & V_157 ) )
F_80 ( V_17 ) ;
if ( ! F_68 ( V_158 , & V_17 -> V_148 ) ) {
V_17 -> V_159 = V_19 . V_160 + 1 ;
F_81 ( V_17 , V_19 . V_161 ) ;
}
}
return 0 ;
}
static int F_82 ( const struct V_1 * V_2 )
{
return 0 ;
}
static void F_83 ( struct V_1 * V_2 , bool V_162 )
{
struct V_59 * V_60 = (struct V_59 * ) V_2 -> V_55 ;
struct V_16 * V_17 = V_2 -> V_5 ;
if ( ! V_162 || ( V_17 -> V_36 -> V_163 & V_164 ) )
return;
if ( V_2 -> V_165 == V_146 &&
V_2 -> V_52 == V_166 && V_60 ) {
V_2 -> V_167 . V_168 ++ ;
if ( F_84 ( V_169 , & V_2 -> V_170 ) == 0 )
V_2 -> V_167 . V_168 -- ;
}
}
