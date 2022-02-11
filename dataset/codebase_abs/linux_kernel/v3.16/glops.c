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
if ( F_19 ( V_17 , V_31 . V_35 ) < 0 ) {
F_20 ( V_17 -> V_38 ) ;
return;
}
F_21 ( V_39 -> V_40 ) ;
V_39 -> V_40 = & V_31 ;
F_5 ( V_2 , 0 , V_31 . V_34 ) ;
F_22 ( V_17 ) ;
F_23 ( V_17 , NULL , V_41 ) ;
}
void F_24 ( struct V_1 * V_2 , bool V_14 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
unsigned int V_42 = F_11 ( & V_2 -> V_29 ) ;
unsigned int V_43 = ( V_17 -> V_44 . V_45 - sizeof( struct V_46 ) ) / sizeof( V_36 ) ;
int V_47 ;
if ( ! V_42 )
return;
while ( V_42 > V_43 )
V_43 += ( V_17 -> V_44 . V_45 - sizeof( struct V_48 ) ) / sizeof( V_36 ) ;
V_47 = F_25 ( V_17 , 0 , V_43 ) ;
if ( V_47 )
return;
F_5 ( V_2 , V_14 , V_43 ) ;
F_22 ( V_17 ) ;
F_23 ( V_17 , NULL , V_41 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_49 * V_9 = & V_17 -> V_50 ;
struct V_51 * V_52 ;
int error ;
if ( ! F_27 ( V_53 , & V_2 -> V_54 ) )
return;
F_10 ( V_2 , V_2 -> V_55 != V_56 ) ;
F_23 ( V_17 , V_2 , V_41 ) ;
F_28 ( V_9 , V_2 -> V_57 . V_58 , V_2 -> V_57 . V_59 ) ;
error = F_29 ( V_9 , V_2 -> V_57 . V_58 , V_2 -> V_57 . V_59 ) ;
F_30 ( V_9 , error ) ;
F_14 ( V_2 ) ;
F_7 ( & V_2 -> V_60 ) ;
V_52 = V_2 -> V_61 ;
if ( V_52 )
F_31 ( V_52 ) ;
F_12 ( & V_2 -> V_60 ) ;
}
static void F_32 ( struct V_1 * V_2 , int V_10 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_49 * V_9 = & V_17 -> V_50 ;
F_21 ( ! ( V_10 & V_62 ) ) ;
F_33 ( V_17 , ! F_11 ( & V_2 -> V_29 ) ) ;
F_34 ( V_9 , V_2 -> V_57 . V_58 , V_2 -> V_57 . V_59 ) ;
if ( V_2 -> V_61 ) {
struct V_51 * V_52 = (struct V_51 * ) V_2 -> V_61 ;
V_52 -> V_63 &= ~ V_64 ;
}
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = V_2 -> V_61 ;
struct V_49 * V_67 = F_3 ( V_2 ) ;
int error ;
if ( V_66 && ! F_36 ( V_66 -> V_68 . V_69 ) )
V_66 = NULL ;
if ( V_66 ) {
if ( F_27 ( V_70 , & V_66 -> V_71 ) )
F_37 ( V_66 -> V_68 . V_72 , 0 , 0 ) ;
F_38 ( & V_66 -> V_68 ) ;
}
if ( ! F_27 ( V_53 , & V_2 -> V_54 ) )
return;
F_10 ( V_2 , V_2 -> V_55 != V_56 ) ;
F_23 ( V_2 -> V_5 , V_2 , V_41 ) ;
F_39 ( V_67 ) ;
if ( V_66 ) {
struct V_49 * V_9 = V_66 -> V_68 . V_72 ;
F_39 ( V_9 ) ;
error = F_40 ( V_9 ) ;
F_30 ( V_9 , error ) ;
}
error = F_40 ( V_67 ) ;
F_30 ( V_67 , error ) ;
F_14 ( V_2 ) ;
F_41 () ;
F_42 ( V_53 , & V_2 -> V_54 ) ;
}
static void F_43 ( struct V_1 * V_2 , int V_10 )
{
struct V_65 * V_66 = V_2 -> V_61 ;
F_33 ( V_2 -> V_5 , ! F_11 ( & V_2 -> V_29 ) ) ;
if ( V_10 & V_62 ) {
struct V_49 * V_9 = F_3 ( V_2 ) ;
F_44 ( V_9 , 0 ) ;
if ( V_66 ) {
F_45 ( V_73 , & V_66 -> V_71 ) ;
F_46 ( & V_66 -> V_68 ) ;
F_47 ( V_66 ) ;
}
}
if ( V_66 == F_48 ( V_2 -> V_5 -> V_74 ) ) {
F_23 ( V_2 -> V_5 , NULL , V_41 ) ;
V_2 -> V_5 -> V_75 = 0 ;
}
if ( V_66 && F_36 ( V_66 -> V_68 . V_69 ) )
F_44 ( V_66 -> V_68 . V_72 , 0 ) ;
}
static int F_49 ( const struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_76 * V_77 ;
if ( V_17 -> V_78 == V_2 -> V_61 || V_17 -> V_74 == V_2 -> V_61 )
return 0 ;
if ( ! F_50 ( & V_2 -> V_79 ) ) {
V_77 = F_51 ( V_2 -> V_79 . V_80 , struct V_76 , V_81 ) ;
if ( V_77 -> V_81 . V_80 != & V_2 -> V_79 )
return 0 ;
}
return 1 ;
}
static void F_52 ( struct V_82 * V_82 , T_1 V_83 )
{
if ( ( V_82 -> V_84 != V_83 ) && ( V_82 -> V_84 != 0 ) ) {
if ( V_83 == 0 )
F_53 ( V_82 ) ;
else
F_54 ( V_82 , V_83 ) ;
}
}
static int F_55 ( struct V_65 * V_66 , const void * V_85 )
{
const struct V_86 * V_87 = V_85 ;
struct V_88 V_89 ;
T_2 V_90 , V_91 ;
if ( F_56 ( V_66 -> V_92 != F_57 ( V_87 -> V_93 . V_94 ) ) )
goto V_95;
V_66 -> V_96 = F_57 ( V_87 -> V_93 . V_97 ) ;
V_66 -> V_68 . V_69 = F_58 ( V_87 -> V_98 ) ;
V_66 -> V_68 . V_99 = 0 ;
switch ( V_66 -> V_68 . V_69 & V_100 ) {
case V_101 :
case V_102 :
V_66 -> V_68 . V_99 = F_59 ( F_58 ( V_87 -> V_103 ) ,
F_58 ( V_87 -> V_104 ) ) ;
break;
} ;
F_60 ( & V_66 -> V_68 , F_58 ( V_87 -> V_105 ) ) ;
F_61 ( & V_66 -> V_68 , F_58 ( V_87 -> V_106 ) ) ;
F_52 ( & V_66 -> V_68 , F_58 ( V_87 -> V_107 ) ) ;
F_62 ( & V_66 -> V_68 , F_57 ( V_87 -> V_108 ) ) ;
F_63 ( & V_66 -> V_68 , F_57 ( V_87 -> V_109 ) ) ;
V_89 . V_110 = F_57 ( V_87 -> V_111 ) ;
V_89 . V_112 = F_58 ( V_87 -> V_113 ) ;
if ( F_64 ( & V_66 -> V_68 . V_114 , & V_89 ) < 0 )
V_66 -> V_68 . V_114 = V_89 ;
V_66 -> V_68 . V_115 . V_110 = F_57 ( V_87 -> V_116 ) ;
V_66 -> V_68 . V_115 . V_112 = F_58 ( V_87 -> V_117 ) ;
V_66 -> V_68 . V_118 . V_110 = F_57 ( V_87 -> V_119 ) ;
V_66 -> V_68 . V_118 . V_112 = F_58 ( V_87 -> V_120 ) ;
V_66 -> V_121 = F_57 ( V_87 -> V_122 ) ;
V_66 -> V_123 = F_57 ( V_87 -> V_124 ) ;
V_66 -> V_125 = F_58 ( V_87 -> V_126 ) ;
V_66 -> V_127 = F_57 ( V_87 -> V_128 ) ;
F_65 ( & V_66 -> V_68 ) ;
V_90 = F_66 ( V_87 -> V_129 ) ;
if ( F_56 ( V_90 > V_130 ) )
goto V_95;
V_66 -> V_131 = ( V_132 ) V_90 ;
V_91 = F_66 ( V_87 -> V_133 ) ;
if ( F_56 ( V_91 > V_134 ) )
goto V_95;
V_66 -> V_135 = ( V_132 ) V_91 ;
V_66 -> V_136 = F_58 ( V_87 -> V_137 ) ;
if ( F_36 ( V_66 -> V_68 . V_69 ) )
F_67 ( & V_66 -> V_68 ) ;
return 0 ;
V_95:
F_68 ( V_66 ) ;
return - V_138 ;
}
int F_69 ( struct V_65 * V_66 )
{
struct V_3 * V_139 ;
int error ;
error = F_70 ( V_66 , & V_139 ) ;
if ( error )
return error ;
error = F_55 ( V_66 , V_139 -> V_140 ) ;
F_71 ( V_139 ) ;
F_42 ( V_73 , & V_66 -> V_71 ) ;
return error ;
}
static int F_72 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = V_77 -> V_141 ;
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_65 * V_66 = V_2 -> V_61 ;
int error = 0 ;
if ( ! V_66 || ( V_77 -> V_142 & V_143 ) )
return 0 ;
if ( F_73 ( V_73 , & V_66 -> V_71 ) ) {
error = F_69 ( V_66 ) ;
if ( error )
return error ;
}
if ( V_77 -> V_144 != V_145 )
F_38 ( & V_66 -> V_68 ) ;
if ( ( V_66 -> V_125 & V_146 ) &&
( V_2 -> V_55 == V_56 ) &&
( V_77 -> V_144 == V_56 ) ) {
F_7 ( & V_17 -> V_147 ) ;
if ( F_50 ( & V_66 -> V_148 ) )
F_74 ( & V_17 -> V_149 , & V_66 -> V_148 ) ;
F_12 ( & V_17 -> V_147 ) ;
F_75 ( & V_17 -> V_150 ) ;
return 1 ;
}
return error ;
}
static void F_76 ( struct V_151 * V_152 , const struct V_1 * V_2 )
{
const struct V_65 * V_66 = V_2 -> V_61 ;
if ( V_66 == NULL )
return;
F_77 ( V_152 , L_4 ,
( unsigned long long ) V_66 -> V_96 ,
( unsigned long long ) V_66 -> V_92 ,
F_78 ( V_66 -> V_68 . V_69 ) , V_66 -> V_71 ,
( unsigned int ) V_66 -> V_125 ,
( unsigned long long ) F_79 ( & V_66 -> V_68 ) ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
F_81 ( V_153 ) ;
if ( V_2 -> V_55 == V_154 &&
F_73 ( V_155 , & V_17 -> V_156 ) ) {
F_82 ( & V_17 -> V_157 , 1 ) ;
F_75 ( & V_17 -> V_158 ) ;
do {
F_83 ( & V_17 -> V_159 , & V_153 ,
V_160 ) ;
if ( F_11 ( & V_17 -> V_157 ) )
F_84 () ;
} while( F_11 ( & V_17 -> V_157 ) );
F_85 ( & V_17 -> V_159 , & V_153 ) ;
}
}
static int F_86 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_65 * V_66 = F_48 ( V_17 -> V_161 -> V_162 ) ;
struct V_1 * V_163 = V_66 -> V_164 ;
struct V_165 V_19 ;
int error ;
if ( F_73 ( V_155 , & V_17 -> V_156 ) ) {
V_163 -> V_166 -> V_167 ( V_163 , V_62 ) ;
error = F_87 ( V_17 -> V_161 , & V_19 ) ;
if ( error )
F_88 ( V_17 ) ;
if ( ! ( V_19 . V_168 & V_169 ) )
F_88 ( V_17 ) ;
if ( ! F_73 ( V_170 , & V_17 -> V_156 ) ) {
V_17 -> V_171 = V_19 . V_172 + 1 ;
F_89 ( V_17 , V_19 . V_173 ) ;
}
}
return 0 ;
}
static int F_90 ( const struct V_1 * V_2 )
{
return 0 ;
}
static void F_91 ( struct V_1 * V_2 , bool V_174 )
{
struct V_65 * V_66 = (struct V_65 * ) V_2 -> V_61 ;
struct V_16 * V_17 = V_2 -> V_5 ;
if ( ! V_174 || ( V_17 -> V_38 -> V_175 & V_176 ) )
return;
if ( V_2 -> V_177 == V_178 &&
V_2 -> V_55 == V_154 && V_66 ) {
V_2 -> V_179 . V_180 ++ ;
if ( F_92 ( V_181 , & V_2 -> V_182 ) == 0 )
V_2 -> V_179 . V_180 -- ;
}
}
