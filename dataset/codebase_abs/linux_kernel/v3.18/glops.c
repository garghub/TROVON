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
F_17 ( V_17 -> V_39 ) ;
if ( F_18 ( V_17 , V_31 . V_35 ) < 0 ) {
F_19 ( V_17 -> V_39 ) ;
return;
}
F_20 ( V_40 -> V_41 ) ;
V_40 -> V_41 = & V_31 ;
F_5 ( V_2 , 0 , V_31 . V_34 ) ;
F_21 ( V_17 ) ;
F_22 ( V_17 , NULL , V_42 ) ;
}
void F_23 ( struct V_1 * V_2 , bool V_14 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
unsigned int V_43 = F_11 ( & V_2 -> V_29 ) ;
unsigned int V_44 = ( V_17 -> V_45 . V_46 - sizeof( struct V_47 ) ) / sizeof( V_36 ) ;
int V_48 ;
if ( ! V_43 )
return;
while ( V_43 > V_44 )
V_44 += ( V_17 -> V_45 . V_46 - sizeof( struct V_49 ) ) / sizeof( V_36 ) ;
V_48 = F_24 ( V_17 , 0 , V_44 ) ;
if ( V_48 )
return;
F_5 ( V_2 , V_14 , V_44 ) ;
F_21 ( V_17 ) ;
F_22 ( V_17 , NULL , V_42 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_50 * V_9 = & V_17 -> V_51 ;
struct V_52 * V_53 ;
int error ;
if ( ! F_26 ( V_54 , & V_2 -> V_55 ) )
return;
F_10 ( V_2 , V_2 -> V_56 != V_57 ) ;
F_22 ( V_17 , V_2 , V_42 ) ;
F_27 ( V_9 , V_2 -> V_58 . V_59 , V_2 -> V_58 . V_60 ) ;
error = F_28 ( V_9 , V_2 -> V_58 . V_59 , V_2 -> V_58 . V_60 ) ;
F_29 ( V_9 , error ) ;
F_14 ( V_2 ) ;
F_7 ( & V_2 -> V_61 ) ;
V_53 = V_2 -> V_62 ;
if ( V_53 )
F_30 ( V_53 ) ;
F_12 ( & V_2 -> V_61 ) ;
}
static void F_31 ( struct V_1 * V_2 , int V_10 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_50 * V_9 = & V_17 -> V_51 ;
F_20 ( ! ( V_10 & V_63 ) ) ;
F_32 ( V_17 , ! F_11 ( & V_2 -> V_29 ) ) ;
F_33 ( V_9 , V_2 -> V_58 . V_59 , V_2 -> V_58 . V_60 ) ;
if ( V_2 -> V_62 ) {
struct V_52 * V_53 = (struct V_52 * ) V_2 -> V_62 ;
V_53 -> V_64 &= ~ V_65 ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_66 * V_67 = V_2 -> V_62 ;
struct V_50 * V_68 = F_3 ( V_2 ) ;
int error ;
if ( V_67 && ! F_35 ( V_67 -> V_69 . V_70 ) )
V_67 = NULL ;
if ( V_67 ) {
if ( F_26 ( V_71 , & V_67 -> V_72 ) )
F_36 ( V_67 -> V_69 . V_73 , 0 , 0 ) ;
F_37 ( & V_67 -> V_69 ) ;
}
if ( ! F_26 ( V_54 , & V_2 -> V_55 ) )
return;
F_10 ( V_2 , V_2 -> V_56 != V_57 ) ;
F_22 ( V_2 -> V_5 , V_2 , V_42 ) ;
F_38 ( V_68 ) ;
if ( V_67 ) {
struct V_50 * V_9 = V_67 -> V_69 . V_73 ;
F_38 ( V_9 ) ;
error = F_39 ( V_9 ) ;
F_29 ( V_9 , error ) ;
}
error = F_39 ( V_68 ) ;
F_29 ( V_68 , error ) ;
F_14 ( V_2 ) ;
F_40 () ;
F_41 ( V_54 , & V_2 -> V_55 ) ;
}
static void F_42 ( struct V_1 * V_2 , int V_10 )
{
struct V_66 * V_67 = V_2 -> V_62 ;
F_32 ( V_2 -> V_5 , ! F_11 ( & V_2 -> V_29 ) ) ;
if ( V_10 & V_63 ) {
struct V_50 * V_9 = F_3 ( V_2 ) ;
F_43 ( V_9 , 0 ) ;
if ( V_67 ) {
F_44 ( V_74 , & V_67 -> V_72 ) ;
F_45 ( & V_67 -> V_69 ) ;
F_46 ( V_67 ) ;
}
}
if ( V_67 == F_47 ( V_2 -> V_5 -> V_75 ) ) {
F_22 ( V_2 -> V_5 , NULL , V_42 ) ;
V_2 -> V_5 -> V_76 = 0 ;
}
if ( V_67 && F_35 ( V_67 -> V_69 . V_70 ) )
F_43 ( V_67 -> V_69 . V_73 , 0 ) ;
}
static int F_48 ( const struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_77 * V_78 ;
if ( V_17 -> V_79 == V_2 -> V_62 || V_17 -> V_75 == V_2 -> V_62 )
return 0 ;
if ( ! F_49 ( & V_2 -> V_80 ) ) {
V_78 = F_50 ( V_2 -> V_80 . V_81 , struct V_77 , V_82 ) ;
if ( V_78 -> V_82 . V_81 != & V_2 -> V_80 )
return 0 ;
}
return 1 ;
}
static void F_51 ( struct V_83 * V_83 , T_1 V_84 )
{
if ( ( V_83 -> V_85 != V_84 ) && ( V_83 -> V_85 != 0 ) ) {
if ( V_84 == 0 )
F_52 ( V_83 ) ;
else
F_53 ( V_83 , V_84 ) ;
}
}
static int F_54 ( struct V_66 * V_67 , const void * V_86 )
{
const struct V_87 * V_88 = V_86 ;
struct V_89 V_90 ;
T_2 V_91 , V_92 ;
if ( F_55 ( V_67 -> V_93 != F_56 ( V_88 -> V_94 . V_95 ) ) )
goto V_96;
V_67 -> V_97 = F_56 ( V_88 -> V_94 . V_98 ) ;
V_67 -> V_69 . V_70 = F_57 ( V_88 -> V_99 ) ;
V_67 -> V_69 . V_100 = 0 ;
switch ( V_67 -> V_69 . V_70 & V_101 ) {
case V_102 :
case V_103 :
V_67 -> V_69 . V_100 = F_58 ( F_57 ( V_88 -> V_104 ) ,
F_57 ( V_88 -> V_105 ) ) ;
break;
} ;
F_59 ( & V_67 -> V_69 , F_57 ( V_88 -> V_106 ) ) ;
F_60 ( & V_67 -> V_69 , F_57 ( V_88 -> V_107 ) ) ;
F_51 ( & V_67 -> V_69 , F_57 ( V_88 -> V_108 ) ) ;
F_61 ( & V_67 -> V_69 , F_56 ( V_88 -> V_109 ) ) ;
F_62 ( & V_67 -> V_69 , F_56 ( V_88 -> V_110 ) ) ;
V_90 . V_111 = F_56 ( V_88 -> V_112 ) ;
V_90 . V_113 = F_57 ( V_88 -> V_114 ) ;
if ( F_63 ( & V_67 -> V_69 . V_115 , & V_90 ) < 0 )
V_67 -> V_69 . V_115 = V_90 ;
V_67 -> V_69 . V_116 . V_111 = F_56 ( V_88 -> V_117 ) ;
V_67 -> V_69 . V_116 . V_113 = F_57 ( V_88 -> V_118 ) ;
V_67 -> V_69 . V_119 . V_111 = F_56 ( V_88 -> V_120 ) ;
V_67 -> V_69 . V_119 . V_113 = F_57 ( V_88 -> V_121 ) ;
V_67 -> V_122 = F_56 ( V_88 -> V_123 ) ;
V_67 -> V_124 = F_56 ( V_88 -> V_125 ) ;
V_67 -> V_126 = F_57 ( V_88 -> V_127 ) ;
V_67 -> V_128 = F_56 ( V_88 -> V_129 ) ;
F_64 ( & V_67 -> V_69 ) ;
V_91 = F_65 ( V_88 -> V_130 ) ;
if ( F_55 ( V_91 > V_131 ) )
goto V_96;
V_67 -> V_132 = ( V_133 ) V_91 ;
V_92 = F_65 ( V_88 -> V_134 ) ;
if ( F_55 ( V_92 > V_135 ) )
goto V_96;
V_67 -> V_136 = ( V_133 ) V_92 ;
V_67 -> V_137 = F_57 ( V_88 -> V_138 ) ;
if ( F_35 ( V_67 -> V_69 . V_70 ) )
F_66 ( & V_67 -> V_69 ) ;
return 0 ;
V_96:
F_67 ( V_67 ) ;
return - V_139 ;
}
int F_68 ( struct V_66 * V_67 )
{
struct V_3 * V_140 ;
int error ;
error = F_69 ( V_67 , & V_140 ) ;
if ( error )
return error ;
error = F_54 ( V_67 , V_140 -> V_141 ) ;
F_70 ( V_140 ) ;
F_41 ( V_74 , & V_67 -> V_72 ) ;
return error ;
}
static int F_71 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = V_78 -> V_142 ;
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_66 * V_67 = V_2 -> V_62 ;
int error = 0 ;
if ( ! V_67 || ( V_78 -> V_143 & V_144 ) )
return 0 ;
if ( F_72 ( V_74 , & V_67 -> V_72 ) ) {
error = F_68 ( V_67 ) ;
if ( error )
return error ;
}
if ( V_78 -> V_145 != V_146 )
F_37 ( & V_67 -> V_69 ) ;
if ( ( V_67 -> V_126 & V_147 ) &&
( V_2 -> V_56 == V_57 ) &&
( V_78 -> V_145 == V_57 ) ) {
F_7 ( & V_17 -> V_148 ) ;
if ( F_49 ( & V_67 -> V_149 ) )
F_73 ( & V_17 -> V_150 , & V_67 -> V_149 ) ;
F_12 ( & V_17 -> V_148 ) ;
F_74 ( & V_17 -> V_151 ) ;
return 1 ;
}
return error ;
}
static void F_75 ( struct V_152 * V_153 , const struct V_1 * V_2 )
{
const struct V_66 * V_67 = V_2 -> V_62 ;
if ( V_67 == NULL )
return;
F_76 ( V_153 , L_4 ,
( unsigned long long ) V_67 -> V_97 ,
( unsigned long long ) V_67 -> V_93 ,
F_77 ( V_67 -> V_69 . V_70 ) , V_67 -> V_72 ,
( unsigned int ) V_67 -> V_126 ,
( unsigned long long ) F_78 ( & V_67 -> V_69 ) ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
F_80 ( V_154 ) ;
if ( V_2 -> V_56 == V_155 &&
F_72 ( V_156 , & V_17 -> V_157 ) ) {
F_81 ( & V_17 -> V_158 , 1 ) ;
F_74 ( & V_17 -> V_159 ) ;
do {
F_82 ( & V_17 -> V_160 , & V_154 ,
V_161 ) ;
if ( F_11 ( & V_17 -> V_158 ) )
F_83 () ;
} while( F_11 ( & V_17 -> V_158 ) );
F_84 ( & V_17 -> V_160 , & V_154 ) ;
}
}
static int F_85 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_66 * V_67 = F_47 ( V_17 -> V_162 -> V_163 ) ;
struct V_1 * V_164 = V_67 -> V_165 ;
struct V_166 V_19 ;
int error ;
if ( F_72 ( V_156 , & V_17 -> V_157 ) ) {
V_164 -> V_167 -> V_168 ( V_164 , V_63 ) ;
error = F_86 ( V_17 -> V_162 , & V_19 ) ;
if ( error )
F_87 ( V_17 ) ;
if ( ! ( V_19 . V_169 & V_170 ) )
F_87 ( V_17 ) ;
if ( ! F_72 ( V_171 , & V_17 -> V_157 ) ) {
V_17 -> V_172 = V_19 . V_173 + 1 ;
F_88 ( V_17 , V_19 . V_174 ) ;
}
}
return 0 ;
}
static int F_89 ( const struct V_1 * V_2 )
{
return 0 ;
}
static void F_90 ( struct V_1 * V_2 , bool V_175 )
{
struct V_66 * V_67 = (struct V_66 * ) V_2 -> V_62 ;
struct V_16 * V_17 = V_2 -> V_5 ;
if ( ! V_175 || ( V_17 -> V_39 -> V_176 & V_177 ) )
return;
if ( V_2 -> V_178 == V_179 &&
V_2 -> V_56 == V_155 && V_67 ) {
V_2 -> V_180 . V_181 ++ ;
if ( F_91 ( V_182 , & V_2 -> V_183 ) == 0 )
V_2 -> V_180 . V_181 -- ;
}
}
