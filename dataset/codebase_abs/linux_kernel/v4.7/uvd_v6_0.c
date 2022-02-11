static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
return F_2 ( V_5 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
return F_2 ( V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_5 ( V_6 , V_2 -> V_7 ) ;
}
static int F_6 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
F_7 ( V_4 ) ;
F_8 ( V_4 ) ;
return 0 ;
}
static int F_9 ( void * V_8 )
{
struct V_1 * V_2 ;
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_9 = F_10 ( V_4 , 124 , & V_4 -> V_10 . V_11 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_11 ( V_4 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_12 ( V_4 ) ;
if ( V_9 )
return V_9 ;
V_2 = & V_4 -> V_10 . V_2 ;
sprintf ( V_2 -> V_12 , L_1 ) ;
V_9 = F_13 ( V_4 , V_2 , 512 , V_13 , 0xf ,
& V_4 -> V_10 . V_11 , 0 , V_14 ) ;
return V_9 ;
}
static int F_14 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_9 = F_15 ( V_4 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_16 ( V_4 ) ;
if ( V_9 )
return V_9 ;
return V_9 ;
}
static int F_17 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
T_1 V_15 ;
int V_9 ;
V_9 = F_18 ( V_4 ) ;
if ( V_9 )
goto V_16;
V_2 -> V_17 = true ;
V_9 = F_19 ( V_2 ) ;
if ( V_9 ) {
V_2 -> V_17 = false ;
goto V_16;
}
V_9 = F_20 ( V_2 , 10 ) ;
if ( V_9 ) {
F_21 ( L_2 , V_9 ) ;
goto V_16;
}
V_15 = F_22 ( V_18 , 0 ) ;
F_23 ( V_2 , V_15 ) ;
F_23 ( V_2 , 0xFFFFF ) ;
V_15 = F_22 ( V_19 , 0 ) ;
F_23 ( V_2 , V_15 ) ;
F_23 ( V_2 , 0xFFFFF ) ;
V_15 = F_22 ( V_20 , 0 ) ;
F_23 ( V_2 , V_15 ) ;
F_23 ( V_2 , 0xFFFFF ) ;
F_23 ( V_2 , F_22 ( V_21 , 0 ) ) ;
F_23 ( V_2 , 0x8 ) ;
F_23 ( V_2 , F_22 ( V_22 , 0 ) ) ;
F_23 ( V_2 , 3 ) ;
F_24 ( V_2 ) ;
V_16:
if ( ! V_9 )
F_25 ( L_3 ) ;
return V_9 ;
}
static int F_26 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
F_27 ( V_4 ) ;
V_2 -> V_17 = false ;
return 0 ;
}
static int F_28 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_9 = F_26 ( V_4 ) ;
if ( V_9 )
return V_9 ;
if ( ! ( V_4 -> V_23 & V_24 ) ) {
V_9 = F_15 ( V_4 ) ;
if ( V_9 )
return V_9 ;
}
return V_9 ;
}
static int F_29 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( ! ( V_4 -> V_23 & V_24 ) ) {
V_9 = F_12 ( V_4 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_17 ( V_4 ) ;
if ( V_9 )
return V_9 ;
return V_9 ;
}
static void F_30 ( struct V_3 * V_4 )
{
T_2 V_25 ;
T_1 V_26 ;
F_5 ( V_27 ,
F_31 ( V_4 -> V_10 . V_28 ) ) ;
F_5 ( V_29 ,
F_32 ( V_4 -> V_10 . V_28 ) ) ;
V_25 = V_30 ;
V_26 = F_33 ( V_4 -> V_10 . V_31 -> V_26 + 4 ) ;
F_5 ( V_32 , V_25 >> 3 ) ;
F_5 ( V_33 , V_26 ) ;
V_25 += V_26 ;
V_26 = V_34 ;
F_5 ( V_35 , V_25 >> 3 ) ;
F_5 ( V_36 , V_26 ) ;
V_25 += V_26 ;
V_26 = V_37 +
( V_38 * V_4 -> V_10 . V_39 ) ;
F_5 ( V_40 , V_25 >> 3 ) ;
F_5 ( V_41 , V_26 ) ;
F_5 ( V_42 , V_4 -> V_43 . V_44 . V_45 ) ;
F_5 ( V_46 , V_4 -> V_43 . V_44 . V_45 ) ;
F_5 ( V_47 , V_4 -> V_43 . V_44 . V_45 ) ;
F_5 ( V_48 , V_4 -> V_10 . V_39 ) ;
}
static int F_18 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
T_1 V_49 , V_15 ;
T_1 V_50 ;
T_1 V_51 ;
int V_52 , V_53 , V_9 ;
F_34 ( V_54 , 0 , ~ ( 1 << 2 ) ) ;
V_50 = 0 ;
V_51 = 0 ;
F_30 ( V_4 ) ;
if ( V_4 -> V_55 & V_56 ) {
F_35 ( V_4 ) ;
} else {
T_1 V_57 = F_2 ( V_58 ) ;
V_57 &= ~ V_59 ;
F_5 ( V_58 , V_57 ) ;
}
F_34 ( V_60 , 0 , ~ ( 1 << 1 ) ) ;
F_34 ( V_61 , 1 << 8 , ~ ( 1 << 8 ) ) ;
F_36 ( 1 ) ;
F_5 ( V_62 , V_63 |
V_64 | V_65 |
V_66 | V_67 |
V_68 | V_69 |
V_70 ) ;
F_36 ( 5 ) ;
F_34 ( V_71 , 0 , ~ V_72 ) ;
F_36 ( 5 ) ;
F_5 ( V_73 , 0x40 | ( 1 << 8 ) | ( 1 << 13 ) |
( 1 << 21 ) | ( 1 << 9 ) | ( 1 << 20 ) ) ;
#ifdef F_37
V_50 = 0xa ;
V_51 = 0 ;
#endif
F_5 ( V_74 , V_50 ) ;
F_5 ( V_75 , V_51 ) ;
F_5 ( V_76 , 0x40c2040 ) ;
F_5 ( V_77 , 0x0 ) ;
F_5 ( V_78 , 0x40c2040 ) ;
F_5 ( V_79 , 0x0 ) ;
F_5 ( V_80 , 0 ) ;
F_5 ( V_81 , 0x88 ) ;
F_5 ( V_62 , V_64 ) ;
F_36 ( 5 ) ;
F_5 ( V_82 , 1 << 9 ) ;
F_34 ( V_61 , 0 , ~ ( 1 << 8 ) ) ;
F_5 ( V_62 , 0 ) ;
F_36 ( 10 ) ;
for ( V_52 = 0 ; V_52 < 10 ; ++ V_52 ) {
T_1 V_83 ;
for ( V_53 = 0 ; V_53 < 100 ; ++ V_53 ) {
V_83 = F_2 ( V_84 ) ;
if ( V_83 & 2 )
break;
F_36 ( 10 ) ;
}
V_9 = 0 ;
if ( V_83 & 2 )
break;
F_21 ( L_4 ) ;
F_34 ( V_62 , V_64 ,
~ V_64 ) ;
F_36 ( 10 ) ;
F_34 ( V_62 , 0 ,
~ V_64 ) ;
F_36 ( 10 ) ;
V_9 = - 1 ;
}
if ( V_9 ) {
F_21 ( L_5 ) ;
return V_9 ;
}
F_34 ( V_60 , 3 << 1 , ~ ( 3 << 1 ) ) ;
F_34 ( V_84 , 0 , ~ ( 2 << 1 ) ) ;
V_49 = F_38 ( V_2 -> V_85 ) ;
V_15 = 0 ;
V_15 = F_39 ( V_15 , V_86 , V_87 , V_49 ) ;
V_15 = F_39 ( V_15 , V_86 , V_88 , 1 ) ;
V_15 = F_39 ( V_15 , V_86 , V_89 , 1 ) ;
V_15 = F_39 ( V_15 , V_86 , V_90 , 0 ) ;
V_15 = F_39 ( V_15 , V_86 , V_91 , 1 ) ;
V_15 = F_39 ( V_15 , V_86 , V_92 , 1 ) ;
F_5 ( V_93 , V_15 ) ;
F_5 ( V_94 , 0 ) ;
F_5 ( V_95 , ( F_32 ( V_2 -> V_28 ) >> 2 ) ) ;
F_5 ( V_96 ,
F_31 ( V_2 -> V_28 ) ) ;
F_5 ( V_97 ,
F_32 ( V_2 -> V_28 ) ) ;
F_5 ( V_5 , 0 ) ;
V_2 -> V_7 = F_2 ( V_5 ) ;
F_5 ( V_6 , V_2 -> V_7 ) ;
F_34 ( V_93 , 0 , ~ V_98 ) ;
return 0 ;
}
static void F_27 ( struct V_3 * V_4 )
{
F_5 ( V_93 , 0x11010101 ) ;
F_34 ( V_61 , 1 << 8 , ~ ( 1 << 8 ) ) ;
F_36 ( 1 ) ;
F_5 ( V_62 , V_64 ) ;
F_36 ( 5 ) ;
F_5 ( V_82 , 0x0 ) ;
F_34 ( V_61 , 0 , ~ ( 1 << 8 ) ) ;
}
static void F_40 ( struct V_1 * V_2 , T_3 V_99 , T_3 V_100 ,
unsigned V_23 )
{
F_41 ( V_23 & V_101 ) ;
F_23 ( V_2 , F_22 ( V_102 , 0 ) ) ;
F_23 ( V_2 , V_100 ) ;
F_23 ( V_2 , F_22 ( V_103 , 0 ) ) ;
F_23 ( V_2 , V_99 & 0xffffffff ) ;
F_23 ( V_2 , F_22 ( V_104 , 0 ) ) ;
F_23 ( V_2 , F_32 ( V_99 ) & 0xff ) ;
F_23 ( V_2 , F_22 ( V_105 , 0 ) ) ;
F_23 ( V_2 , 0 ) ;
F_23 ( V_2 , F_22 ( V_103 , 0 ) ) ;
F_23 ( V_2 , 0 ) ;
F_23 ( V_2 , F_22 ( V_104 , 0 ) ) ;
F_23 ( V_2 , 0 ) ;
F_23 ( V_2 , F_22 ( V_105 , 0 ) ) ;
F_23 ( V_2 , 2 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_15 = 0 ;
unsigned V_52 ;
int V_9 ;
F_5 ( V_102 , 0xCAFEDEAD ) ;
V_9 = F_20 ( V_2 , 3 ) ;
if ( V_9 ) {
F_21 ( L_6 ,
V_2 -> V_106 , V_9 ) ;
return V_9 ;
}
F_23 ( V_2 , F_22 ( V_102 , 0 ) ) ;
F_23 ( V_2 , 0xDEADBEEF ) ;
F_24 ( V_2 ) ;
for ( V_52 = 0 ; V_52 < V_4 -> V_107 ; V_52 ++ ) {
V_15 = F_2 ( V_102 ) ;
if ( V_15 == 0xDEADBEEF )
break;
F_43 ( 1 ) ;
}
if ( V_52 < V_4 -> V_107 ) {
F_25 ( L_7 ,
V_2 -> V_106 , V_52 ) ;
} else {
F_21 ( L_8 ,
V_2 -> V_106 , V_15 ) ;
V_9 = - V_108 ;
}
return V_9 ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_109 * V_110 ,
unsigned V_111 , bool V_112 )
{
F_23 ( V_2 , F_22 ( V_113 , 0 ) ) ;
F_23 ( V_2 , F_31 ( V_110 -> V_28 ) ) ;
F_23 ( V_2 , F_22 ( V_114 , 0 ) ) ;
F_23 ( V_2 , F_32 ( V_110 -> V_28 ) ) ;
F_23 ( V_2 , F_22 ( V_115 , 0 ) ) ;
F_23 ( V_2 , V_110 -> V_116 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_117 * V_117 = NULL ;
int V_9 ;
V_9 = F_46 ( V_2 , 1 , NULL ) ;
if ( V_9 ) {
F_21 ( L_9 , V_9 ) ;
goto error;
}
V_9 = F_47 ( V_2 , 1 , true , & V_117 ) ;
if ( V_9 ) {
F_21 ( L_10 , V_9 ) ;
goto error;
}
V_9 = F_48 ( V_117 , false ) ;
if ( V_9 ) {
F_21 ( L_11 , V_9 ) ;
goto error;
}
F_25 ( L_12 , V_2 -> V_106 ) ;
error:
F_49 ( V_117 ) ;
return V_9 ;
}
static bool F_50 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
return ! ( F_2 ( V_118 ) & V_119 ) ;
}
static int F_51 ( void * V_8 )
{
unsigned V_52 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
for ( V_52 = 0 ; V_52 < V_4 -> V_107 ; V_52 ++ ) {
if ( ! ( F_2 ( V_118 ) & V_119 ) )
return 0 ;
}
return - V_120 ;
}
static int F_52 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
F_27 ( V_4 ) ;
F_34 ( V_71 , V_72 ,
~ V_72 ) ;
F_36 ( 5 ) ;
return F_18 ( V_4 ) ;
}
static int F_53 ( struct V_3 * V_4 ,
struct V_121 * V_122 ,
unsigned type ,
enum V_123 V_124 )
{
return 0 ;
}
static int F_54 ( struct V_3 * V_4 ,
struct V_121 * V_122 ,
struct V_125 * V_126 )
{
F_55 ( L_13 ) ;
F_56 ( & V_4 -> V_10 . V_2 ) ;
return 0 ;
}
static void F_35 ( struct V_3 * V_4 )
{
T_1 V_57 , V_127 , V_128 , V_129 ;
V_57 = F_2 ( V_58 ) ;
V_127 = F_2 ( V_130 ) ;
V_128 = F_2 ( V_131 ) ;
V_57 &= ~ ( V_132 |
V_133 ) ;
V_129 = V_134 |
V_135 |
V_136 |
V_137 |
V_138 ;
V_57 |= V_59 |
( 1 << F_57 ( V_139 , V_140 ) ) |
( 4 << F_57 ( V_139 , V_141 ) ) ;
V_57 &= ~ ( V_142 |
V_143 |
V_144 |
V_145 |
V_146 |
V_147 |
V_148 |
V_149 |
V_150 |
V_151 |
V_152 |
V_153 |
V_154 |
V_155 |
V_156 |
V_157 |
V_158 |
V_159 |
V_160 |
V_161 |
V_162 |
V_163 ) ;
V_128 &= ~ ( V_164 |
V_165 |
V_166 |
V_167 |
V_168 ) ;
V_127 |= V_129 ;
F_5 ( V_58 , V_57 ) ;
F_5 ( V_169 , 0 ) ;
F_5 ( V_130 , V_127 ) ;
F_5 ( V_131 , V_128 ) ;
}
static void F_58 ( struct V_3 * V_4 , bool V_170 )
{
T_4 V_15 = F_59 ( V_171 ) ;
if ( V_170 )
V_15 |= ( V_172 |
V_173 ) ;
else
V_15 &= ~ ( V_172 |
V_173 ) ;
F_60 ( V_171 , V_15 ) ;
}
static int F_61 ( void * V_8 ,
enum V_174 V_124 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
bool V_170 = ( V_124 == V_175 ) ? true : false ;
static int V_176 = - 1 ;
if ( V_4 -> V_177 == V_178 )
F_58 ( V_4 , V_170 ) ;
if ( ! ( V_4 -> V_55 & V_56 ) )
return 0 ;
if ( V_176 == V_124 )
return 0 ;
V_176 = V_124 ;
if ( V_170 ) {
F_35 ( V_4 ) ;
} else {
if ( F_51 ( V_8 ) )
return - V_179 ;
}
return 0 ;
}
static int F_62 ( void * V_8 ,
enum V_180 V_124 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( ! ( V_4 -> V_181 & V_182 ) )
return 0 ;
if ( V_124 == V_183 ) {
F_27 ( V_4 ) ;
return 0 ;
} else {
return F_18 ( V_4 ) ;
}
}
static void F_7 ( struct V_3 * V_4 )
{
V_4 -> V_10 . V_2 . V_184 = & V_185 ;
}
static void F_8 ( struct V_3 * V_4 )
{
V_4 -> V_10 . V_11 . V_186 = 1 ;
V_4 -> V_10 . V_11 . V_184 = & V_187 ;
}
