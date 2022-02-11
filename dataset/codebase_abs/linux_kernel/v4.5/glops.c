static void F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
F_2 ( V_2 -> V_5 . V_6 ,
L_1
L_2 ,
V_4 , ( unsigned long long ) V_4 -> V_7 , V_4 -> V_8 ,
V_4 -> V_9 -> V_10 , V_4 -> V_9 -> V_11 ) ;
F_2 ( V_2 -> V_5 . V_6 , L_3 ,
V_2 -> V_5 . V_12 , V_2 -> V_5 . V_13 ,
F_3 ( V_2 ) ) ;
F_4 ( V_2 -> V_5 . V_6 , L_4 ) ;
}
static void F_5 ( struct V_1 * V_2 , bool V_14 ,
unsigned int V_15 )
{
struct V_16 * V_17 = V_2 -> V_5 . V_6 ;
struct V_18 * V_19 = & V_2 -> V_20 ;
struct V_21 * V_22 , * V_23 ;
struct V_3 * V_4 ;
const unsigned long V_8 = ( 1UL << V_24 ) | ( 1UL << V_25 ) | ( 1UL << V_26 ) ;
F_6 ( V_17 ) ;
F_7 ( & V_17 -> V_27 ) ;
F_8 (bd, tmp, head, bd_ail_gl_list) {
if ( V_15 == 0 )
break;
V_4 = V_22 -> V_28 ;
if ( V_4 -> V_8 & V_8 ) {
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
struct V_16 * V_17 = V_2 -> V_5 . V_6 ;
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
struct V_16 * V_17 = V_2 -> V_5 . V_6 ;
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
struct V_16 * V_17 = V_2 -> V_5 . V_6 ;
struct V_49 * V_10 = & V_17 -> V_50 ;
struct V_51 * V_52 ;
int error ;
F_7 ( & V_2 -> V_53 . V_54 ) ;
V_52 = V_2 -> V_55 ;
if ( V_52 )
F_24 ( V_52 ) ;
F_12 ( & V_2 -> V_53 . V_54 ) ;
if ( ! F_25 ( V_56 , & V_2 -> V_57 ) )
return;
F_10 ( V_2 , V_2 -> V_58 != V_59 ) ;
F_20 ( V_17 , V_2 , V_41 ) ;
F_26 ( V_10 , V_2 -> V_60 . V_61 , V_2 -> V_60 . V_62 ) ;
error = F_27 ( V_10 , V_2 -> V_60 . V_61 , V_2 -> V_60 . V_62 ) ;
F_28 ( V_10 , error ) ;
F_14 ( V_2 ) ;
F_7 ( & V_2 -> V_53 . V_54 ) ;
V_52 = V_2 -> V_55 ;
if ( V_52 )
F_29 ( V_52 ) ;
F_12 ( & V_2 -> V_53 . V_54 ) ;
}
static void F_30 ( struct V_1 * V_2 , int V_11 )
{
struct V_16 * V_17 = V_2 -> V_5 . V_6 ;
struct V_49 * V_10 = & V_17 -> V_50 ;
struct V_51 * V_52 = V_2 -> V_55 ;
if ( V_52 )
F_24 ( V_52 ) ;
F_18 ( ! ( V_11 & V_63 ) ) ;
F_31 ( V_17 , ! F_11 ( & V_2 -> V_29 ) ) ;
F_32 ( V_10 , V_2 -> V_60 . V_61 , V_2 -> V_60 . V_62 ) ;
if ( V_52 )
V_52 -> V_64 &= ~ V_65 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_66 * V_67 = V_2 -> V_55 ;
struct V_49 * V_68 = F_3 ( V_2 ) ;
int error ;
if ( V_67 && ! F_34 ( V_67 -> V_69 . V_70 ) )
V_67 = NULL ;
if ( V_67 ) {
if ( F_25 ( V_71 , & V_67 -> V_72 ) )
F_35 ( V_67 -> V_69 . V_73 , 0 , 0 ) ;
F_36 ( & V_67 -> V_69 ) ;
}
if ( ! F_25 ( V_56 , & V_2 -> V_57 ) )
return;
F_10 ( V_2 , V_2 -> V_58 != V_59 ) ;
F_20 ( V_2 -> V_5 . V_6 , V_2 , V_41 ) ;
F_37 ( V_68 ) ;
if ( V_67 ) {
struct V_49 * V_10 = V_67 -> V_69 . V_73 ;
F_37 ( V_10 ) ;
error = F_38 ( V_10 ) ;
F_28 ( V_10 , error ) ;
}
error = F_38 ( V_68 ) ;
F_28 ( V_68 , error ) ;
F_14 ( V_2 ) ;
F_39 () ;
F_40 ( V_56 , & V_2 -> V_57 ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_11 )
{
struct V_66 * V_67 = V_2 -> V_55 ;
F_31 ( V_2 -> V_5 . V_6 , ! F_11 ( & V_2 -> V_29 ) ) ;
if ( V_11 & V_63 ) {
struct V_49 * V_10 = F_3 ( V_2 ) ;
F_42 ( V_10 , 0 ) ;
if ( V_67 ) {
F_43 ( V_74 , & V_67 -> V_72 ) ;
F_44 ( & V_67 -> V_69 ) ;
F_45 ( & V_67 -> V_69 ) ;
F_46 ( V_67 ) ;
}
}
if ( V_67 == F_47 ( V_2 -> V_5 . V_6 -> V_75 ) ) {
F_20 ( V_2 -> V_5 . V_6 , NULL , V_41 ) ;
V_2 -> V_5 . V_6 -> V_76 = 0 ;
}
if ( V_67 && F_34 ( V_67 -> V_69 . V_70 ) )
F_42 ( V_67 -> V_69 . V_73 , 0 ) ;
}
static int F_48 ( const struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_5 . V_6 ;
struct V_77 * V_78 ;
if ( V_17 -> V_79 == V_2 -> V_55 || V_17 -> V_75 == V_2 -> V_55 )
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
if ( F_34 ( V_67 -> V_69 . V_70 ) )
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
F_40 ( V_74 , & V_67 -> V_72 ) ;
return error ;
}
static int F_71 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = V_78 -> V_142 ;
struct V_16 * V_17 = V_2 -> V_5 . V_6 ;
struct V_66 * V_67 = V_2 -> V_55 ;
int error = 0 ;
if ( ! V_67 || ( V_78 -> V_143 & V_144 ) )
return 0 ;
if ( F_72 ( V_74 , & V_67 -> V_72 ) ) {
error = F_68 ( V_67 ) ;
if ( error )
return error ;
}
if ( V_78 -> V_145 != V_146 )
F_36 ( & V_67 -> V_69 ) ;
if ( ( V_67 -> V_126 & V_147 ) &&
( V_2 -> V_58 == V_59 ) &&
( V_78 -> V_145 == V_59 ) ) {
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
const struct V_66 * V_67 = V_2 -> V_55 ;
if ( V_67 == NULL )
return;
F_76 ( V_153 , L_5 ,
( unsigned long long ) V_67 -> V_97 ,
( unsigned long long ) V_67 -> V_93 ,
F_77 ( V_67 -> V_69 . V_70 ) , V_67 -> V_72 ,
( unsigned int ) V_67 -> V_126 ,
( unsigned long long ) F_78 ( & V_67 -> V_69 ) ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
int error = 0 ;
struct V_16 * V_17 = V_2 -> V_5 . V_6 ;
if ( V_2 -> V_58 == V_154 &&
F_72 ( V_155 , & V_17 -> V_156 ) ) {
F_80 ( & V_17 -> V_157 , V_158 ) ;
error = F_81 ( V_17 -> V_159 ) ;
if ( error ) {
F_82 ( V_160 L_6 , error ) ;
F_31 ( V_17 , 0 ) ;
}
F_83 ( V_161 , & V_17 -> V_162 ) ;
F_20 ( V_17 , NULL , V_163 ) ;
}
}
static int F_84 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
struct V_16 * V_17 = V_2 -> V_5 . V_6 ;
struct V_66 * V_67 = F_47 ( V_17 -> V_164 -> V_165 ) ;
struct V_1 * V_166 = V_67 -> V_167 ;
struct V_168 V_19 ;
int error ;
if ( F_72 ( V_155 , & V_17 -> V_156 ) ) {
V_166 -> V_169 -> V_170 ( V_166 , V_63 ) ;
error = F_85 ( V_17 -> V_164 , & V_19 ) ;
if ( error )
F_86 ( V_17 ) ;
if ( ! ( V_19 . V_171 & V_172 ) )
F_86 ( V_17 ) ;
if ( ! F_72 ( V_173 , & V_17 -> V_156 ) ) {
V_17 -> V_174 = V_19 . V_175 + 1 ;
F_87 ( V_17 , V_19 . V_176 ) ;
}
}
return 0 ;
}
static int F_88 ( const struct V_1 * V_2 )
{
return 0 ;
}
static void F_89 ( struct V_1 * V_2 , bool V_177 )
{
struct V_66 * V_67 = (struct V_66 * ) V_2 -> V_55 ;
struct V_16 * V_17 = V_2 -> V_5 . V_6 ;
if ( ! V_177 || ( V_17 -> V_159 -> V_178 & V_179 ) )
return;
if ( V_2 -> V_180 == V_181 &&
V_2 -> V_58 == V_154 && V_67 ) {
V_2 -> V_53 . V_182 ++ ;
if ( F_83 ( V_183 , & V_2 -> V_184 ) == 0 )
V_2 -> V_53 . V_182 -- ;
}
}
