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
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_46 * V_9 = & V_17 -> V_47 ;
struct V_48 * V_49 ;
int error ;
if ( ! F_25 ( V_50 , & V_2 -> V_51 ) )
return;
F_10 ( V_2 , V_2 -> V_52 != V_53 ) ;
F_21 ( V_17 , V_2 ) ;
F_26 ( V_9 , V_2 -> V_54 . V_55 , V_2 -> V_54 . V_56 ) ;
error = F_27 ( V_9 , V_2 -> V_54 . V_55 , V_2 -> V_54 . V_56 ) ;
F_28 ( V_9 , error ) ;
F_14 ( V_2 ) ;
F_7 ( & V_2 -> V_57 ) ;
V_49 = V_2 -> V_58 ;
if ( V_49 )
F_29 ( V_49 ) ;
F_12 ( & V_2 -> V_57 ) ;
}
static void F_30 ( struct V_1 * V_2 , int V_10 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_46 * V_9 = & V_17 -> V_47 ;
F_19 ( ! ( V_10 & V_59 ) ) ;
F_31 ( V_17 , ! F_11 ( & V_2 -> V_29 ) ) ;
F_32 ( V_9 , V_2 -> V_54 . V_55 , V_2 -> V_54 . V_56 ) ;
if ( V_2 -> V_58 ) {
struct V_48 * V_49 = (struct V_48 * ) V_2 -> V_58 ;
V_49 -> V_60 &= ~ V_61 ;
}
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_62 * V_63 = V_2 -> V_58 ;
struct V_46 * V_64 = F_3 ( V_2 ) ;
int error ;
if ( V_63 && ! F_34 ( V_63 -> V_65 . V_66 ) )
V_63 = NULL ;
if ( V_63 ) {
if ( F_25 ( V_67 , & V_63 -> V_68 ) )
F_35 ( V_63 -> V_65 . V_69 , 0 , 0 ) ;
F_36 ( & V_63 -> V_65 ) ;
}
if ( ! F_25 ( V_50 , & V_2 -> V_51 ) )
return;
F_10 ( V_2 , V_2 -> V_52 != V_53 ) ;
F_21 ( V_2 -> V_5 , V_2 ) ;
F_37 ( V_64 ) ;
if ( V_63 ) {
struct V_46 * V_9 = V_63 -> V_65 . V_69 ;
F_37 ( V_9 ) ;
error = F_38 ( V_9 ) ;
F_28 ( V_9 , error ) ;
}
error = F_38 ( V_64 ) ;
F_28 ( V_64 , error ) ;
F_14 ( V_2 ) ;
F_39 () ;
F_40 ( V_50 , & V_2 -> V_51 ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_10 )
{
struct V_62 * V_63 = V_2 -> V_58 ;
F_31 ( V_2 -> V_5 , ! F_11 ( & V_2 -> V_29 ) ) ;
if ( V_10 & V_59 ) {
struct V_46 * V_9 = F_3 ( V_2 ) ;
F_42 ( V_9 , 0 ) ;
if ( V_63 ) {
F_43 ( V_70 , & V_63 -> V_68 ) ;
F_44 ( & V_63 -> V_65 ) ;
F_45 ( V_63 ) ;
}
}
if ( V_63 == F_46 ( V_2 -> V_5 -> V_71 ) ) {
F_21 ( V_2 -> V_5 , NULL ) ;
V_2 -> V_5 -> V_72 = 0 ;
}
if ( V_63 && F_34 ( V_63 -> V_65 . V_66 ) )
F_42 ( V_63 -> V_65 . V_69 , 0 ) ;
}
static int F_47 ( const struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_73 * V_74 ;
if ( V_17 -> V_75 == V_2 -> V_58 || V_17 -> V_71 == V_2 -> V_58 )
return 0 ;
if ( ! F_48 ( & V_2 -> V_76 ) ) {
V_74 = F_49 ( V_2 -> V_76 . V_77 , struct V_73 , V_78 ) ;
if ( V_74 -> V_78 . V_77 != & V_2 -> V_76 )
return 0 ;
}
return 1 ;
}
static void F_50 ( struct V_79 * V_79 , T_1 V_80 )
{
if ( ( V_79 -> V_81 != V_80 ) && ( V_79 -> V_81 != 0 ) ) {
if ( V_80 == 0 )
F_51 ( V_79 ) ;
else
F_52 ( V_79 , V_80 ) ;
}
}
static int F_53 ( struct V_62 * V_63 , const void * V_82 )
{
const struct V_83 * V_84 = V_82 ;
struct V_85 V_86 ;
T_2 V_87 , V_88 ;
if ( F_54 ( V_63 -> V_89 != F_55 ( V_84 -> V_90 . V_91 ) ) )
goto V_92;
V_63 -> V_93 = F_55 ( V_84 -> V_90 . V_94 ) ;
V_63 -> V_65 . V_66 = F_56 ( V_84 -> V_95 ) ;
V_63 -> V_65 . V_96 = 0 ;
switch ( V_63 -> V_65 . V_66 & V_97 ) {
case V_98 :
case V_99 :
V_63 -> V_65 . V_96 = F_57 ( F_56 ( V_84 -> V_100 ) ,
F_56 ( V_84 -> V_101 ) ) ;
break;
} ;
F_58 ( & V_63 -> V_65 , F_56 ( V_84 -> V_102 ) ) ;
F_59 ( & V_63 -> V_65 , F_56 ( V_84 -> V_103 ) ) ;
F_50 ( & V_63 -> V_65 , F_56 ( V_84 -> V_104 ) ) ;
F_60 ( & V_63 -> V_65 , F_55 ( V_84 -> V_105 ) ) ;
F_61 ( & V_63 -> V_65 , F_55 ( V_84 -> V_106 ) ) ;
V_86 . V_107 = F_55 ( V_84 -> V_108 ) ;
V_86 . V_109 = F_56 ( V_84 -> V_110 ) ;
if ( F_62 ( & V_63 -> V_65 . V_111 , & V_86 ) < 0 )
V_63 -> V_65 . V_111 = V_86 ;
V_63 -> V_65 . V_112 . V_107 = F_55 ( V_84 -> V_113 ) ;
V_63 -> V_65 . V_112 . V_109 = F_56 ( V_84 -> V_114 ) ;
V_63 -> V_65 . V_115 . V_107 = F_55 ( V_84 -> V_116 ) ;
V_63 -> V_65 . V_115 . V_109 = F_56 ( V_84 -> V_117 ) ;
V_63 -> V_118 = F_55 ( V_84 -> V_119 ) ;
V_63 -> V_120 = F_55 ( V_84 -> V_121 ) ;
V_63 -> V_122 = F_56 ( V_84 -> V_123 ) ;
V_63 -> V_124 = F_55 ( V_84 -> V_125 ) ;
F_63 ( & V_63 -> V_65 ) ;
V_87 = F_64 ( V_84 -> V_126 ) ;
if ( F_54 ( V_87 > V_127 ) )
goto V_92;
V_63 -> V_128 = ( V_129 ) V_87 ;
V_88 = F_64 ( V_84 -> V_130 ) ;
if ( F_54 ( V_88 > V_131 ) )
goto V_92;
V_63 -> V_132 = ( V_129 ) V_88 ;
V_63 -> V_133 = F_56 ( V_84 -> V_134 ) ;
if ( F_34 ( V_63 -> V_65 . V_66 ) )
F_65 ( & V_63 -> V_65 ) ;
return 0 ;
V_92:
F_66 ( V_63 ) ;
return - V_135 ;
}
int F_67 ( struct V_62 * V_63 )
{
struct V_3 * V_136 ;
int error ;
error = F_68 ( V_63 , & V_136 ) ;
if ( error )
return error ;
error = F_53 ( V_63 , V_136 -> V_137 ) ;
F_69 ( V_136 ) ;
F_40 ( V_70 , & V_63 -> V_68 ) ;
return error ;
}
static int F_70 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = V_74 -> V_138 ;
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_62 * V_63 = V_2 -> V_58 ;
int error = 0 ;
if ( ! V_63 || ( V_74 -> V_139 & V_140 ) )
return 0 ;
if ( F_71 ( V_70 , & V_63 -> V_68 ) ) {
error = F_67 ( V_63 ) ;
if ( error )
return error ;
}
if ( V_74 -> V_141 != V_142 )
F_36 ( & V_63 -> V_65 ) ;
if ( ( V_63 -> V_122 & V_143 ) &&
( V_2 -> V_52 == V_53 ) &&
( V_74 -> V_141 == V_53 ) ) {
F_7 ( & V_17 -> V_144 ) ;
if ( F_48 ( & V_63 -> V_145 ) )
F_72 ( & V_17 -> V_146 , & V_63 -> V_145 ) ;
F_12 ( & V_17 -> V_144 ) ;
F_73 ( & V_17 -> V_147 ) ;
return 1 ;
}
return error ;
}
static void F_74 ( struct V_148 * V_149 , const struct V_1 * V_2 )
{
const struct V_62 * V_63 = V_2 -> V_58 ;
if ( V_63 == NULL )
return;
F_75 ( V_149 , L_4 ,
( unsigned long long ) V_63 -> V_93 ,
( unsigned long long ) V_63 -> V_89 ,
F_76 ( V_63 -> V_65 . V_66 ) , V_63 -> V_68 ,
( unsigned int ) V_63 -> V_122 ,
( unsigned long long ) F_77 ( & V_63 -> V_65 ) ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
if ( V_2 -> V_52 != V_150 &&
F_71 ( V_151 , & V_17 -> V_152 ) ) {
F_79 ( V_17 ) ;
F_80 ( V_17 ) ;
}
}
static int F_81 ( struct V_1 * V_2 , struct V_73 * V_74 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_62 * V_63 = F_46 ( V_17 -> V_153 -> V_154 ) ;
struct V_1 * V_155 = V_63 -> V_156 ;
struct V_157 V_19 ;
int error ;
if ( F_71 ( V_151 , & V_17 -> V_152 ) ) {
V_155 -> V_158 -> V_159 ( V_155 , V_59 ) ;
error = F_82 ( V_17 -> V_153 , & V_19 ) ;
if ( error )
F_83 ( V_17 ) ;
if ( ! ( V_19 . V_160 & V_161 ) )
F_83 ( V_17 ) ;
if ( ! F_71 ( V_162 , & V_17 -> V_152 ) ) {
V_17 -> V_163 = V_19 . V_164 + 1 ;
F_84 ( V_17 , V_19 . V_165 ) ;
}
}
return 0 ;
}
static int F_85 ( const struct V_1 * V_2 )
{
return 0 ;
}
static void F_86 ( struct V_1 * V_2 , bool V_166 )
{
struct V_62 * V_63 = (struct V_62 * ) V_2 -> V_58 ;
struct V_16 * V_17 = V_2 -> V_5 ;
if ( ! V_166 || ( V_17 -> V_36 -> V_167 & V_168 ) )
return;
if ( V_2 -> V_169 == V_150 &&
V_2 -> V_52 == V_170 && V_63 ) {
V_2 -> V_171 . V_172 ++ ;
if ( F_87 ( V_173 , & V_2 -> V_174 ) == 0 )
V_2 -> V_171 . V_172 -- ;
}
}
