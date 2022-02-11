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
F_15 ( & V_31 . V_32 ) ;
F_15 ( & V_31 . V_33 ) ;
V_31 . V_34 = F_11 ( & V_2 -> V_29 ) ;
if ( ! V_31 . V_34 )
return;
V_31 . V_35 = 1 + F_16 ( V_17 , V_31 . V_34 , sizeof( V_36 ) ) ;
V_31 . V_37 = ( unsigned long ) F_17 ( 0 ) ;
F_18 ( V_17 -> V_38 ) ;
F_19 ( V_17 , V_31 . V_35 ) ;
F_20 ( V_39 -> V_40 ) ;
V_39 -> V_40 = & V_31 ;
F_5 ( V_2 , 0 , V_31 . V_34 ) ;
F_21 ( V_17 ) ;
F_22 ( V_17 , NULL ) ;
}
void F_23 ( struct V_1 * V_2 , bool V_14 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
unsigned int V_41 = F_11 ( & V_2 -> V_29 ) ;
unsigned int V_42 = ( V_17 -> V_43 . V_44 - sizeof( struct V_45 ) ) / sizeof( V_36 ) ;
int V_46 ;
if ( ! V_41 )
return;
while ( V_41 > V_42 )
V_42 += ( V_17 -> V_43 . V_44 - sizeof( struct V_47 ) ) / sizeof( V_36 ) ;
V_46 = F_24 ( V_17 , 0 , V_42 ) ;
if ( V_46 )
return;
F_5 ( V_2 , V_14 , V_42 ) ;
F_21 ( V_17 ) ;
F_22 ( V_17 , NULL ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_48 * V_9 = & V_17 -> V_49 ;
struct V_50 * V_51 ;
int error ;
if ( ! F_26 ( V_52 , & V_2 -> V_53 ) )
return;
F_10 ( V_2 , V_2 -> V_54 != V_55 ) ;
F_22 ( V_17 , V_2 ) ;
F_27 ( V_9 , V_2 -> V_56 . V_57 , V_2 -> V_56 . V_58 ) ;
error = F_28 ( V_9 , V_2 -> V_56 . V_57 , V_2 -> V_56 . V_58 ) ;
F_29 ( V_9 , error ) ;
F_14 ( V_2 ) ;
F_7 ( & V_2 -> V_59 ) ;
V_51 = V_2 -> V_60 ;
if ( V_51 )
F_30 ( V_51 ) ;
F_12 ( & V_2 -> V_59 ) ;
}
static void F_31 ( struct V_1 * V_2 , int V_10 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_48 * V_9 = & V_17 -> V_49 ;
F_20 ( ! ( V_10 & V_61 ) ) ;
F_32 ( V_17 , ! F_11 ( & V_2 -> V_29 ) ) ;
F_33 ( V_9 , V_2 -> V_56 . V_57 , V_2 -> V_56 . V_58 ) ;
if ( V_2 -> V_60 ) {
struct V_50 * V_51 = (struct V_50 * ) V_2 -> V_60 ;
V_51 -> V_62 &= ~ V_63 ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = V_2 -> V_60 ;
struct V_48 * V_66 = F_3 ( V_2 ) ;
int error ;
if ( V_65 && ! F_35 ( V_65 -> V_67 . V_68 ) )
V_65 = NULL ;
if ( V_65 ) {
if ( F_26 ( V_69 , & V_65 -> V_70 ) )
F_36 ( V_65 -> V_67 . V_71 , 0 , 0 ) ;
F_37 ( & V_65 -> V_67 ) ;
}
if ( ! F_26 ( V_52 , & V_2 -> V_53 ) )
return;
F_10 ( V_2 , V_2 -> V_54 != V_55 ) ;
F_22 ( V_2 -> V_5 , V_2 ) ;
F_38 ( V_66 ) ;
if ( V_65 ) {
struct V_48 * V_9 = V_65 -> V_67 . V_71 ;
F_38 ( V_9 ) ;
error = F_39 ( V_9 ) ;
F_29 ( V_9 , error ) ;
}
error = F_39 ( V_66 ) ;
F_29 ( V_66 , error ) ;
F_14 ( V_2 ) ;
F_40 () ;
F_41 ( V_52 , & V_2 -> V_53 ) ;
}
static void F_42 ( struct V_1 * V_2 , int V_10 )
{
struct V_64 * V_65 = V_2 -> V_60 ;
F_32 ( V_2 -> V_5 , ! F_11 ( & V_2 -> V_29 ) ) ;
if ( V_10 & V_61 ) {
struct V_48 * V_9 = F_3 ( V_2 ) ;
F_43 ( V_9 , 0 ) ;
if ( V_65 ) {
F_44 ( V_72 , & V_65 -> V_70 ) ;
F_45 ( & V_65 -> V_67 ) ;
F_46 ( V_65 ) ;
}
}
if ( V_65 == F_47 ( V_2 -> V_5 -> V_73 ) ) {
F_22 ( V_2 -> V_5 , NULL ) ;
V_2 -> V_5 -> V_74 = 0 ;
}
if ( V_65 && F_35 ( V_65 -> V_67 . V_68 ) )
F_43 ( V_65 -> V_67 . V_71 , 0 ) ;
}
static int F_48 ( const struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_75 * V_76 ;
if ( V_17 -> V_77 == V_2 -> V_60 || V_17 -> V_73 == V_2 -> V_60 )
return 0 ;
if ( ! F_49 ( & V_2 -> V_78 ) ) {
V_76 = F_50 ( V_2 -> V_78 . V_79 , struct V_75 , V_80 ) ;
if ( V_76 -> V_80 . V_79 != & V_2 -> V_78 )
return 0 ;
}
return 1 ;
}
static void F_51 ( struct V_81 * V_81 , T_1 V_82 )
{
if ( ( V_81 -> V_83 != V_82 ) && ( V_81 -> V_83 != 0 ) ) {
if ( V_82 == 0 )
F_52 ( V_81 ) ;
else
F_53 ( V_81 , V_82 ) ;
}
}
static int F_54 ( struct V_64 * V_65 , const void * V_84 )
{
const struct V_85 * V_86 = V_84 ;
struct V_87 V_88 ;
T_2 V_89 , V_90 ;
if ( F_55 ( V_65 -> V_91 != F_56 ( V_86 -> V_92 . V_93 ) ) )
goto V_94;
V_65 -> V_95 = F_56 ( V_86 -> V_92 . V_96 ) ;
V_65 -> V_67 . V_68 = F_57 ( V_86 -> V_97 ) ;
V_65 -> V_67 . V_98 = 0 ;
switch ( V_65 -> V_67 . V_68 & V_99 ) {
case V_100 :
case V_101 :
V_65 -> V_67 . V_98 = F_58 ( F_57 ( V_86 -> V_102 ) ,
F_57 ( V_86 -> V_103 ) ) ;
break;
} ;
F_59 ( & V_65 -> V_67 , F_57 ( V_86 -> V_104 ) ) ;
F_60 ( & V_65 -> V_67 , F_57 ( V_86 -> V_105 ) ) ;
F_51 ( & V_65 -> V_67 , F_57 ( V_86 -> V_106 ) ) ;
F_61 ( & V_65 -> V_67 , F_56 ( V_86 -> V_107 ) ) ;
F_62 ( & V_65 -> V_67 , F_56 ( V_86 -> V_108 ) ) ;
V_88 . V_109 = F_56 ( V_86 -> V_110 ) ;
V_88 . V_111 = F_57 ( V_86 -> V_112 ) ;
if ( F_63 ( & V_65 -> V_67 . V_113 , & V_88 ) < 0 )
V_65 -> V_67 . V_113 = V_88 ;
V_65 -> V_67 . V_114 . V_109 = F_56 ( V_86 -> V_115 ) ;
V_65 -> V_67 . V_114 . V_111 = F_57 ( V_86 -> V_116 ) ;
V_65 -> V_67 . V_117 . V_109 = F_56 ( V_86 -> V_118 ) ;
V_65 -> V_67 . V_117 . V_111 = F_57 ( V_86 -> V_119 ) ;
V_65 -> V_120 = F_56 ( V_86 -> V_121 ) ;
V_65 -> V_122 = F_56 ( V_86 -> V_123 ) ;
V_65 -> V_124 = F_57 ( V_86 -> V_125 ) ;
V_65 -> V_126 = F_56 ( V_86 -> V_127 ) ;
F_64 ( & V_65 -> V_67 ) ;
V_89 = F_65 ( V_86 -> V_128 ) ;
if ( F_55 ( V_89 > V_129 ) )
goto V_94;
V_65 -> V_130 = ( V_131 ) V_89 ;
V_90 = F_65 ( V_86 -> V_132 ) ;
if ( F_55 ( V_90 > V_133 ) )
goto V_94;
V_65 -> V_134 = ( V_131 ) V_90 ;
V_65 -> V_135 = F_57 ( V_86 -> V_136 ) ;
if ( F_35 ( V_65 -> V_67 . V_68 ) )
F_66 ( & V_65 -> V_67 ) ;
return 0 ;
V_94:
F_67 ( V_65 ) ;
return - V_137 ;
}
int F_68 ( struct V_64 * V_65 )
{
struct V_3 * V_138 ;
int error ;
error = F_69 ( V_65 , & V_138 ) ;
if ( error )
return error ;
error = F_54 ( V_65 , V_138 -> V_139 ) ;
F_70 ( V_138 ) ;
F_41 ( V_72 , & V_65 -> V_70 ) ;
return error ;
}
static int F_71 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = V_76 -> V_140 ;
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_64 * V_65 = V_2 -> V_60 ;
int error = 0 ;
if ( ! V_65 || ( V_76 -> V_141 & V_142 ) )
return 0 ;
if ( F_72 ( V_72 , & V_65 -> V_70 ) ) {
error = F_68 ( V_65 ) ;
if ( error )
return error ;
}
if ( V_76 -> V_143 != V_144 )
F_37 ( & V_65 -> V_67 ) ;
if ( ( V_65 -> V_124 & V_145 ) &&
( V_2 -> V_54 == V_55 ) &&
( V_76 -> V_143 == V_55 ) ) {
F_7 ( & V_17 -> V_146 ) ;
if ( F_49 ( & V_65 -> V_147 ) )
F_73 ( & V_17 -> V_148 , & V_65 -> V_147 ) ;
F_12 ( & V_17 -> V_146 ) ;
F_74 ( & V_17 -> V_149 ) ;
return 1 ;
}
return error ;
}
static void F_75 ( struct V_150 * V_151 , const struct V_1 * V_2 )
{
const struct V_64 * V_65 = V_2 -> V_60 ;
if ( V_65 == NULL )
return;
F_76 ( V_151 , L_4 ,
( unsigned long long ) V_65 -> V_95 ,
( unsigned long long ) V_65 -> V_91 ,
F_77 ( V_65 -> V_67 . V_68 ) , V_65 -> V_70 ,
( unsigned int ) V_65 -> V_124 ,
( unsigned long long ) F_78 ( & V_65 -> V_67 ) ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
if ( V_2 -> V_54 != V_152 &&
F_72 ( V_153 , & V_17 -> V_154 ) ) {
F_80 ( V_17 ) ;
F_81 ( V_17 ) ;
}
}
static int F_82 ( struct V_1 * V_2 , struct V_75 * V_76 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_64 * V_65 = F_47 ( V_17 -> V_155 -> V_156 ) ;
struct V_1 * V_157 = V_65 -> V_158 ;
struct V_159 V_19 ;
int error ;
if ( F_72 ( V_153 , & V_17 -> V_154 ) ) {
V_157 -> V_160 -> V_161 ( V_157 , V_61 ) ;
error = F_83 ( V_17 -> V_155 , & V_19 ) ;
if ( error )
F_84 ( V_17 ) ;
if ( ! ( V_19 . V_162 & V_163 ) )
F_84 ( V_17 ) ;
if ( ! F_72 ( V_164 , & V_17 -> V_154 ) ) {
V_17 -> V_165 = V_19 . V_166 + 1 ;
F_85 ( V_17 , V_19 . V_167 ) ;
}
}
return 0 ;
}
static int F_86 ( const struct V_1 * V_2 )
{
return 0 ;
}
static void F_87 ( struct V_1 * V_2 , bool V_168 )
{
struct V_64 * V_65 = (struct V_64 * ) V_2 -> V_60 ;
struct V_16 * V_17 = V_2 -> V_5 ;
if ( ! V_168 || ( V_17 -> V_38 -> V_169 & V_170 ) )
return;
if ( V_2 -> V_171 == V_152 &&
V_2 -> V_54 == V_172 && V_65 ) {
V_2 -> V_173 . V_174 ++ ;
if ( F_88 ( V_175 , & V_2 -> V_176 ) == 0 )
V_2 -> V_173 . V_174 -- ;
}
}
