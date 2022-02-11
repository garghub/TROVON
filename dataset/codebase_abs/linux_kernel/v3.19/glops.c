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
V_31 . V_37 = V_38 ;
if ( F_17 ( V_17 , V_31 . V_35 ) < 0 )
return;
F_18 ( V_39 -> V_40 ) ;
V_39 -> V_40 = & V_31 ;
F_5 ( V_2 , 0 , V_31 . V_34 ) ;
F_19 ( V_17 ) ;
F_20 ( V_17 , NULL , V_41 ) ;
}
void F_21 ( struct V_1 * V_2 , bool V_14 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
unsigned int V_42 = F_11 ( & V_2 -> V_29 ) ;
unsigned int V_43 = ( V_17 -> V_44 . V_45 - sizeof( struct V_46 ) ) / sizeof( V_36 ) ;
int V_47 ;
if ( ! V_42 )
return;
while ( V_42 > V_43 )
V_43 += ( V_17 -> V_44 . V_45 - sizeof( struct V_48 ) ) / sizeof( V_36 ) ;
V_47 = F_22 ( V_17 , 0 , V_43 ) ;
if ( V_47 )
return;
F_5 ( V_2 , V_14 , V_43 ) ;
F_19 ( V_17 ) ;
F_20 ( V_17 , NULL , V_41 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_49 * V_9 = & V_17 -> V_50 ;
struct V_51 * V_52 ;
int error ;
if ( ! F_24 ( V_53 , & V_2 -> V_54 ) )
return;
F_10 ( V_2 , V_2 -> V_55 != V_56 ) ;
F_20 ( V_17 , V_2 , V_41 ) ;
F_25 ( V_9 , V_2 -> V_57 . V_58 , V_2 -> V_57 . V_59 ) ;
error = F_26 ( V_9 , V_2 -> V_57 . V_58 , V_2 -> V_57 . V_59 ) ;
F_27 ( V_9 , error ) ;
F_14 ( V_2 ) ;
F_7 ( & V_2 -> V_60 ) ;
V_52 = V_2 -> V_61 ;
if ( V_52 )
F_28 ( V_52 ) ;
F_12 ( & V_2 -> V_60 ) ;
}
static void F_29 ( struct V_1 * V_2 , int V_10 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_49 * V_9 = & V_17 -> V_50 ;
F_18 ( ! ( V_10 & V_62 ) ) ;
F_30 ( V_17 , ! F_11 ( & V_2 -> V_29 ) ) ;
F_31 ( V_9 , V_2 -> V_57 . V_58 , V_2 -> V_57 . V_59 ) ;
if ( V_2 -> V_61 ) {
struct V_51 * V_52 = (struct V_51 * ) V_2 -> V_61 ;
V_52 -> V_63 &= ~ V_64 ;
}
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = V_2 -> V_61 ;
struct V_49 * V_67 = F_3 ( V_2 ) ;
int error ;
if ( V_66 && ! F_33 ( V_66 -> V_68 . V_69 ) )
V_66 = NULL ;
if ( V_66 ) {
if ( F_24 ( V_70 , & V_66 -> V_71 ) )
F_34 ( V_66 -> V_68 . V_72 , 0 , 0 ) ;
F_35 ( & V_66 -> V_68 ) ;
}
if ( ! F_24 ( V_53 , & V_2 -> V_54 ) )
return;
F_10 ( V_2 , V_2 -> V_55 != V_56 ) ;
F_20 ( V_2 -> V_5 , V_2 , V_41 ) ;
F_36 ( V_67 ) ;
if ( V_66 ) {
struct V_49 * V_9 = V_66 -> V_68 . V_72 ;
F_36 ( V_9 ) ;
error = F_37 ( V_9 ) ;
F_27 ( V_9 , error ) ;
}
error = F_37 ( V_67 ) ;
F_27 ( V_67 , error ) ;
F_14 ( V_2 ) ;
F_38 () ;
F_39 ( V_53 , & V_2 -> V_54 ) ;
}
static void F_40 ( struct V_1 * V_2 , int V_10 )
{
struct V_65 * V_66 = V_2 -> V_61 ;
F_30 ( V_2 -> V_5 , ! F_11 ( & V_2 -> V_29 ) ) ;
if ( V_10 & V_62 ) {
struct V_49 * V_9 = F_3 ( V_2 ) ;
F_41 ( V_9 , 0 ) ;
if ( V_66 ) {
F_42 ( V_73 , & V_66 -> V_71 ) ;
F_43 ( & V_66 -> V_68 ) ;
F_44 ( V_66 ) ;
}
}
if ( V_66 == F_45 ( V_2 -> V_5 -> V_74 ) ) {
F_20 ( V_2 -> V_5 , NULL , V_41 ) ;
V_2 -> V_5 -> V_75 = 0 ;
}
if ( V_66 && F_33 ( V_66 -> V_68 . V_69 ) )
F_41 ( V_66 -> V_68 . V_72 , 0 ) ;
}
static int F_46 ( const struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_76 * V_77 ;
if ( V_17 -> V_78 == V_2 -> V_61 || V_17 -> V_74 == V_2 -> V_61 )
return 0 ;
if ( ! F_47 ( & V_2 -> V_79 ) ) {
V_77 = F_48 ( V_2 -> V_79 . V_80 , struct V_76 , V_81 ) ;
if ( V_77 -> V_81 . V_80 != & V_2 -> V_79 )
return 0 ;
}
return 1 ;
}
static void F_49 ( struct V_82 * V_82 , T_1 V_83 )
{
if ( ( V_82 -> V_84 != V_83 ) && ( V_82 -> V_84 != 0 ) ) {
if ( V_83 == 0 )
F_50 ( V_82 ) ;
else
F_51 ( V_82 , V_83 ) ;
}
}
static int F_52 ( struct V_65 * V_66 , const void * V_85 )
{
const struct V_86 * V_87 = V_85 ;
struct V_88 V_89 ;
T_2 V_90 , V_91 ;
if ( F_53 ( V_66 -> V_92 != F_54 ( V_87 -> V_93 . V_94 ) ) )
goto V_95;
V_66 -> V_96 = F_54 ( V_87 -> V_93 . V_97 ) ;
V_66 -> V_68 . V_69 = F_55 ( V_87 -> V_98 ) ;
V_66 -> V_68 . V_99 = 0 ;
switch ( V_66 -> V_68 . V_69 & V_100 ) {
case V_101 :
case V_102 :
V_66 -> V_68 . V_99 = F_56 ( F_55 ( V_87 -> V_103 ) ,
F_55 ( V_87 -> V_104 ) ) ;
break;
} ;
F_57 ( & V_66 -> V_68 , F_55 ( V_87 -> V_105 ) ) ;
F_58 ( & V_66 -> V_68 , F_55 ( V_87 -> V_106 ) ) ;
F_49 ( & V_66 -> V_68 , F_55 ( V_87 -> V_107 ) ) ;
F_59 ( & V_66 -> V_68 , F_54 ( V_87 -> V_108 ) ) ;
F_60 ( & V_66 -> V_68 , F_54 ( V_87 -> V_109 ) ) ;
V_89 . V_110 = F_54 ( V_87 -> V_111 ) ;
V_89 . V_112 = F_55 ( V_87 -> V_113 ) ;
if ( F_61 ( & V_66 -> V_68 . V_114 , & V_89 ) < 0 )
V_66 -> V_68 . V_114 = V_89 ;
V_66 -> V_68 . V_115 . V_110 = F_54 ( V_87 -> V_116 ) ;
V_66 -> V_68 . V_115 . V_112 = F_55 ( V_87 -> V_117 ) ;
V_66 -> V_68 . V_118 . V_110 = F_54 ( V_87 -> V_119 ) ;
V_66 -> V_68 . V_118 . V_112 = F_55 ( V_87 -> V_120 ) ;
V_66 -> V_121 = F_54 ( V_87 -> V_122 ) ;
V_66 -> V_123 = F_54 ( V_87 -> V_124 ) ;
V_66 -> V_125 = F_55 ( V_87 -> V_126 ) ;
V_66 -> V_127 = F_54 ( V_87 -> V_128 ) ;
F_62 ( & V_66 -> V_68 ) ;
V_90 = F_63 ( V_87 -> V_129 ) ;
if ( F_53 ( V_90 > V_130 ) )
goto V_95;
V_66 -> V_131 = ( V_132 ) V_90 ;
V_91 = F_63 ( V_87 -> V_133 ) ;
if ( F_53 ( V_91 > V_134 ) )
goto V_95;
V_66 -> V_135 = ( V_132 ) V_91 ;
V_66 -> V_136 = F_55 ( V_87 -> V_137 ) ;
if ( F_33 ( V_66 -> V_68 . V_69 ) )
F_64 ( & V_66 -> V_68 ) ;
return 0 ;
V_95:
F_65 ( V_66 ) ;
return - V_138 ;
}
int F_66 ( struct V_65 * V_66 )
{
struct V_3 * V_139 ;
int error ;
error = F_67 ( V_66 , & V_139 ) ;
if ( error )
return error ;
error = F_52 ( V_66 , V_139 -> V_140 ) ;
F_68 ( V_139 ) ;
F_39 ( V_73 , & V_66 -> V_71 ) ;
return error ;
}
static int F_69 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = V_77 -> V_141 ;
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_65 * V_66 = V_2 -> V_61 ;
int error = 0 ;
if ( ! V_66 || ( V_77 -> V_142 & V_143 ) )
return 0 ;
if ( F_70 ( V_73 , & V_66 -> V_71 ) ) {
error = F_66 ( V_66 ) ;
if ( error )
return error ;
}
if ( V_77 -> V_144 != V_145 )
F_35 ( & V_66 -> V_68 ) ;
if ( ( V_66 -> V_125 & V_146 ) &&
( V_2 -> V_55 == V_56 ) &&
( V_77 -> V_144 == V_56 ) ) {
F_7 ( & V_17 -> V_147 ) ;
if ( F_47 ( & V_66 -> V_148 ) )
F_71 ( & V_17 -> V_149 , & V_66 -> V_148 ) ;
F_12 ( & V_17 -> V_147 ) ;
F_72 ( & V_17 -> V_150 ) ;
return 1 ;
}
return error ;
}
static void F_73 ( struct V_151 * V_152 , const struct V_1 * V_2 )
{
const struct V_65 * V_66 = V_2 -> V_61 ;
if ( V_66 == NULL )
return;
F_74 ( V_152 , L_4 ,
( unsigned long long ) V_66 -> V_96 ,
( unsigned long long ) V_66 -> V_92 ,
F_75 ( V_66 -> V_68 . V_69 ) , V_66 -> V_71 ,
( unsigned int ) V_66 -> V_125 ,
( unsigned long long ) F_76 ( & V_66 -> V_68 ) ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
int error = 0 ;
struct V_16 * V_17 = V_2 -> V_5 ;
if ( V_2 -> V_55 == V_153 &&
F_70 ( V_154 , & V_17 -> V_155 ) ) {
F_78 ( & V_17 -> V_156 , V_157 ) ;
error = F_79 ( V_17 -> V_158 ) ;
if ( error ) {
F_80 ( V_159 L_5 , error ) ;
F_30 ( V_17 , 0 ) ;
}
F_81 ( V_160 , & V_17 -> V_161 ) ;
F_20 ( V_17 , NULL , V_162 ) ;
}
}
static int F_82 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_65 * V_66 = F_45 ( V_17 -> V_163 -> V_164 ) ;
struct V_1 * V_165 = V_66 -> V_166 ;
struct V_167 V_19 ;
int error ;
if ( F_70 ( V_154 , & V_17 -> V_155 ) ) {
V_165 -> V_168 -> V_169 ( V_165 , V_62 ) ;
error = F_83 ( V_17 -> V_163 , & V_19 ) ;
if ( error )
F_84 ( V_17 ) ;
if ( ! ( V_19 . V_170 & V_171 ) )
F_84 ( V_17 ) ;
if ( ! F_70 ( V_172 , & V_17 -> V_155 ) ) {
V_17 -> V_173 = V_19 . V_174 + 1 ;
F_85 ( V_17 , V_19 . V_175 ) ;
}
}
return 0 ;
}
static int F_86 ( const struct V_1 * V_2 )
{
return 0 ;
}
static void F_87 ( struct V_1 * V_2 , bool V_176 )
{
struct V_65 * V_66 = (struct V_65 * ) V_2 -> V_61 ;
struct V_16 * V_17 = V_2 -> V_5 ;
if ( ! V_176 || ( V_17 -> V_158 -> V_177 & V_178 ) )
return;
if ( V_2 -> V_179 == V_180 &&
V_2 -> V_55 == V_153 && V_66 ) {
V_2 -> V_181 . V_182 ++ ;
if ( F_81 ( V_183 , & V_2 -> V_184 ) == 0 )
V_2 -> V_181 . V_182 -- ;
}
}
