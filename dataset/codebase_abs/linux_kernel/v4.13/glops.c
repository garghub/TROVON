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
struct V_51 * V_52 = F_31 ( V_2 ) ;
if ( V_52 )
F_24 ( V_52 ) ;
F_18 ( ! ( V_11 & V_63 ) ) ;
F_32 ( V_17 , ! F_11 ( & V_2 -> V_29 ) ) ;
F_33 ( V_10 , V_2 -> V_60 . V_61 , V_2 -> V_60 . V_62 ) ;
if ( V_52 )
V_52 -> V_64 &= ~ V_65 ;
}
static struct V_66 * F_34 ( struct V_1 * V_2 )
{
struct V_66 * V_67 ;
F_7 ( & V_2 -> V_53 . V_54 ) ;
V_67 = V_2 -> V_55 ;
if ( V_67 )
F_35 ( V_68 , & V_67 -> V_69 ) ;
F_12 ( & V_2 -> V_53 . V_54 ) ;
return V_67 ;
}
struct V_51 * F_31 ( struct V_1 * V_2 )
{
struct V_51 * V_52 ;
F_7 ( & V_2 -> V_53 . V_54 ) ;
V_52 = V_2 -> V_55 ;
F_12 ( & V_2 -> V_53 . V_54 ) ;
return V_52 ;
}
static void F_36 ( struct V_66 * V_67 )
{
if ( ! V_67 )
return;
F_37 ( V_68 , & V_67 -> V_69 ) ;
F_38 ( & V_67 -> V_69 , V_68 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_66 * V_67 = F_34 ( V_2 ) ;
int V_70 = V_67 && F_40 ( V_67 -> V_71 . V_72 ) ;
struct V_49 * V_73 = F_3 ( V_2 ) ;
int error ;
if ( V_70 ) {
if ( F_25 ( V_74 , & V_67 -> V_69 ) )
F_41 ( V_67 -> V_71 . V_75 , 0 , 0 ) ;
F_42 ( & V_67 -> V_71 ) ;
}
if ( ! F_25 ( V_56 , & V_2 -> V_57 ) )
goto V_76;
F_10 ( V_2 , V_2 -> V_58 != V_59 ) ;
F_20 ( V_2 -> V_5 . V_6 , V_2 , V_41 ) ;
F_43 ( V_73 ) ;
if ( V_70 ) {
struct V_49 * V_10 = V_67 -> V_71 . V_75 ;
F_43 ( V_10 ) ;
error = F_44 ( V_10 ) ;
F_28 ( V_10 , error ) ;
}
error = F_44 ( V_73 ) ;
F_28 ( V_73 , error ) ;
F_14 ( V_2 ) ;
F_45 () ;
F_46 ( V_56 , & V_2 -> V_57 ) ;
V_76:
F_36 ( V_67 ) ;
}
static void F_47 ( struct V_1 * V_2 , int V_11 )
{
struct V_66 * V_67 = F_34 ( V_2 ) ;
F_32 ( V_2 -> V_5 . V_6 , ! F_11 ( & V_2 -> V_29 ) ) ;
if ( V_11 & V_63 ) {
struct V_49 * V_10 = F_3 ( V_2 ) ;
F_48 ( V_10 , 0 ) ;
if ( V_67 ) {
F_35 ( V_77 , & V_67 -> V_69 ) ;
F_49 ( & V_67 -> V_71 ) ;
F_50 ( & V_67 -> V_71 ) ;
F_51 ( V_67 ) ;
}
}
if ( V_67 == F_52 ( V_2 -> V_5 . V_6 -> V_78 ) ) {
F_20 ( V_2 -> V_5 . V_6 , NULL , V_41 ) ;
V_2 -> V_5 . V_6 -> V_79 = 0 ;
}
if ( V_67 && F_40 ( V_67 -> V_71 . V_72 ) )
F_48 ( V_67 -> V_71 . V_75 , 0 ) ;
F_36 ( V_67 ) ;
}
static int F_53 ( const struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_5 . V_6 ;
if ( V_17 -> V_80 == V_2 -> V_55 || V_17 -> V_78 == V_2 -> V_55 )
return 0 ;
return 1 ;
}
static void F_54 ( struct V_81 * V_81 , T_1 V_82 )
{
if ( ( V_81 -> V_83 != V_82 ) && ( V_81 -> V_83 != 0 ) ) {
if ( V_82 == 0 )
F_55 ( V_81 ) ;
else
F_56 ( V_81 , V_82 ) ;
}
}
static int F_57 ( struct V_66 * V_67 , const void * V_84 )
{
const struct V_85 * V_86 = V_84 ;
struct V_87 V_88 ;
T_2 V_89 , V_90 ;
if ( F_58 ( V_67 -> V_91 != F_59 ( V_86 -> V_92 . V_93 ) ) )
goto V_94;
V_67 -> V_95 = F_59 ( V_86 -> V_92 . V_96 ) ;
V_67 -> V_71 . V_72 = F_60 ( V_86 -> V_97 ) ;
V_67 -> V_71 . V_98 = 0 ;
switch ( V_67 -> V_71 . V_72 & V_99 ) {
case V_100 :
case V_101 :
V_67 -> V_71 . V_98 = F_61 ( F_60 ( V_86 -> V_102 ) ,
F_60 ( V_86 -> V_103 ) ) ;
break;
} ;
F_62 ( & V_67 -> V_71 , F_60 ( V_86 -> V_104 ) ) ;
F_63 ( & V_67 -> V_71 , F_60 ( V_86 -> V_105 ) ) ;
F_54 ( & V_67 -> V_71 , F_60 ( V_86 -> V_106 ) ) ;
F_64 ( & V_67 -> V_71 , F_59 ( V_86 -> V_107 ) ) ;
F_65 ( & V_67 -> V_71 , F_59 ( V_86 -> V_108 ) ) ;
V_88 . V_109 = F_59 ( V_86 -> V_110 ) ;
V_88 . V_111 = F_60 ( V_86 -> V_112 ) ;
if ( F_66 ( & V_67 -> V_71 . V_113 , & V_88 ) < 0 )
V_67 -> V_71 . V_113 = V_88 ;
V_67 -> V_71 . V_114 . V_109 = F_59 ( V_86 -> V_115 ) ;
V_67 -> V_71 . V_114 . V_111 = F_60 ( V_86 -> V_116 ) ;
V_67 -> V_71 . V_117 . V_109 = F_59 ( V_86 -> V_118 ) ;
V_67 -> V_71 . V_117 . V_111 = F_60 ( V_86 -> V_119 ) ;
V_67 -> V_120 = F_59 ( V_86 -> V_121 ) ;
V_67 -> V_122 = F_59 ( V_86 -> V_123 ) ;
V_67 -> V_124 = F_60 ( V_86 -> V_125 ) ;
V_67 -> V_126 = F_59 ( V_86 -> V_127 ) ;
F_67 ( & V_67 -> V_71 ) ;
V_89 = F_68 ( V_86 -> V_128 ) ;
if ( F_58 ( V_89 > V_129 ) )
goto V_94;
V_67 -> V_130 = ( V_131 ) V_89 ;
V_90 = F_68 ( V_86 -> V_132 ) ;
if ( F_58 ( V_90 > V_133 ) )
goto V_94;
V_67 -> V_134 = ( V_131 ) V_90 ;
V_67 -> V_135 = F_60 ( V_86 -> V_136 ) ;
if ( F_40 ( V_67 -> V_71 . V_72 ) )
F_69 ( & V_67 -> V_71 ) ;
return 0 ;
V_94:
F_70 ( V_67 ) ;
return - V_137 ;
}
int F_71 ( struct V_66 * V_67 )
{
struct V_3 * V_138 ;
int error ;
error = F_72 ( V_67 , & V_138 ) ;
if ( error )
return error ;
error = F_57 ( V_67 , V_138 -> V_139 ) ;
F_73 ( V_138 ) ;
F_46 ( V_77 , & V_67 -> V_69 ) ;
return error ;
}
static int F_74 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = V_141 -> V_142 ;
struct V_16 * V_17 = V_2 -> V_5 . V_6 ;
struct V_66 * V_67 = V_2 -> V_55 ;
int error = 0 ;
if ( ! V_67 || ( V_141 -> V_143 & V_144 ) )
return 0 ;
if ( F_75 ( V_77 , & V_67 -> V_69 ) ) {
error = F_71 ( V_67 ) ;
if ( error )
return error ;
}
if ( V_141 -> V_145 != V_146 )
F_42 ( & V_67 -> V_71 ) ;
if ( ( V_67 -> V_124 & V_147 ) &&
( V_2 -> V_58 == V_59 ) &&
( V_141 -> V_145 == V_59 ) ) {
F_7 ( & V_17 -> V_148 ) ;
if ( F_76 ( & V_67 -> V_149 ) )
F_77 ( & V_17 -> V_150 , & V_67 -> V_149 ) ;
F_12 ( & V_17 -> V_148 ) ;
F_78 ( & V_17 -> V_151 ) ;
return 1 ;
}
return error ;
}
static void F_79 ( struct V_152 * V_153 , const struct V_1 * V_2 )
{
const struct V_66 * V_67 = V_2 -> V_55 ;
if ( V_67 == NULL )
return;
F_80 ( V_153 , L_5 ,
( unsigned long long ) V_67 -> V_95 ,
( unsigned long long ) V_67 -> V_91 ,
F_81 ( V_67 -> V_71 . V_72 ) , V_67 -> V_69 ,
( unsigned int ) V_67 -> V_124 ,
( unsigned long long ) F_82 ( & V_67 -> V_71 ) ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
int error = 0 ;
struct V_16 * V_17 = V_2 -> V_5 . V_6 ;
if ( V_2 -> V_58 == V_154 &&
F_75 ( V_155 , & V_17 -> V_156 ) ) {
F_84 ( & V_17 -> V_157 , V_158 ) ;
error = F_85 ( V_17 -> V_159 ) ;
if ( error ) {
F_86 ( V_160 L_6 , error ) ;
F_32 ( V_17 , 0 ) ;
}
F_87 ( V_161 , & V_17 -> V_162 ) ;
F_20 ( V_17 , NULL , V_163 ) ;
}
}
static int F_88 ( struct V_1 * V_2 , struct V_140 * V_141 )
{
struct V_16 * V_17 = V_2 -> V_5 . V_6 ;
struct V_66 * V_67 = F_52 ( V_17 -> V_164 -> V_165 ) ;
struct V_1 * V_166 = V_67 -> V_167 ;
struct V_168 V_19 ;
int error ;
if ( F_75 ( V_155 , & V_17 -> V_156 ) ) {
V_166 -> V_169 -> V_170 ( V_166 , V_63 ) ;
error = F_89 ( V_17 -> V_164 , & V_19 ) ;
if ( error )
F_90 ( V_17 ) ;
if ( ! ( V_19 . V_171 & V_172 ) )
F_90 ( V_17 ) ;
if ( ! F_75 ( V_173 , & V_17 -> V_156 ) ) {
V_17 -> V_174 = V_19 . V_175 + 1 ;
F_91 ( V_17 , V_19 . V_176 ) ;
}
}
return 0 ;
}
static int F_92 ( const struct V_1 * V_2 )
{
return 0 ;
}
static void F_93 ( struct V_1 * V_2 , bool V_177 )
{
struct V_66 * V_67 = V_2 -> V_55 ;
struct V_16 * V_17 = V_2 -> V_5 . V_6 ;
if ( ! V_177 || ( V_17 -> V_159 -> V_178 & V_179 ) )
return;
if ( V_2 -> V_180 == V_181 &&
V_2 -> V_58 == V_154 && V_67 ) {
V_2 -> V_53 . V_182 ++ ;
if ( F_87 ( V_183 , & V_2 -> V_184 ) == 0 )
V_2 -> V_53 . V_182 -- ;
}
}
