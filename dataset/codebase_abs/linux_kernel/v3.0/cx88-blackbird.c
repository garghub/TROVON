static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , 1 ) ;
F_3 ( 100 ) ;
F_2 ( V_3 , 0 ) ;
F_3 ( 100 ) ;
F_2 ( V_4 , 0x44444444U ) ;
F_2 ( V_5 , 0 ) ;
F_2 ( V_6 , 15 ) ;
F_2 ( V_7 , 0 ) ;
F_2 ( V_8 , 0x44448888U ) ;
F_2 ( V_9 , 0 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_10 )
{
unsigned long V_11 = V_12 + F_5 ( 1 ) ;
T_1 V_13 , V_14 ;
V_14 = V_10 ? 2 : 0 ;
for (; ; ) {
V_13 = F_6 ( V_15 ) & 2 ;
if ( V_14 == V_13 )
return 0 ;
if ( F_7 ( V_12 , V_11 ) )
return - 1 ;
F_3 ( 1 ) ;
}
}
static int F_8 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_17 )
{
F_9 ( V_18 , ( unsigned int ) V_17 ) ;
F_9 ( V_19 , ( unsigned int ) ( V_17 >> 8 ) ) ;
F_9 ( V_20 , ( unsigned int ) ( V_17 >> 16 ) ) ;
F_9 ( V_21 , ( unsigned int ) ( V_17 >> 24 ) ) ;
F_9 ( V_22 , ( unsigned int ) ( V_16 >> 16 ) | 0x40 ) ;
F_9 ( V_23 , ( unsigned int ) ( V_16 >> 8 ) ) ;
F_9 ( V_24 , ( unsigned int ) V_16 ) ;
F_6 ( V_18 ) ;
F_6 ( V_24 ) ;
return F_4 ( V_2 , 1 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_16 , T_1 * V_17 )
{
int V_25 ;
T_1 V_26 ;
F_9 ( V_22 , ( unsigned int ) ( V_16 >> 16 ) & ~ 0xC0 ) ;
F_9 ( V_23 , ( unsigned int ) ( V_16 >> 8 ) ) ;
F_9 ( V_24 , ( unsigned int ) V_16 ) ;
F_6 ( V_24 ) ;
V_25 = F_4 ( V_2 , 1 ) ;
F_9 ( V_21 , 0 ) ;
V_26 = ( unsigned char ) F_6 ( V_21 ) << 24 ;
F_9 ( V_20 , 0 ) ;
V_26 |= ( unsigned char ) F_6 ( V_20 ) << 16 ;
F_9 ( V_19 , 0 ) ;
V_26 |= ( unsigned char ) F_6 ( V_19 ) << 8 ;
F_9 ( V_18 , 0 ) ;
V_26 |= ( unsigned char ) F_6 ( V_18 ) ;
* V_17 = V_26 ;
return V_25 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_17 )
{
F_9 ( V_27 , ( unsigned int ) V_17 ) ;
F_9 ( V_28 , ( unsigned int ) ( V_17 >> 8 ) ) ;
F_9 ( V_29 , ( unsigned int ) ( V_17 >> 16 ) ) ;
F_9 ( V_30 , ( unsigned int ) ( V_17 >> 24 ) ) ;
F_9 ( V_31 , ( unsigned int ) V_16 ) ;
F_9 ( V_32 , ( unsigned int ) ( V_16 >> 8 ) ) ;
F_9 ( V_33 , 1 ) ;
F_6 ( V_27 ) ;
F_6 ( V_31 ) ;
return F_4 ( V_2 , 1 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_16 , T_1 * V_17 )
{
int V_25 ;
T_1 V_26 ;
F_9 ( V_31 , ( unsigned int ) V_16 ) ;
F_9 ( V_32 , ( unsigned int ) ( V_16 >> 8 ) ) ;
F_9 ( V_33 , 0 ) ;
F_6 ( V_31 ) ;
V_25 = F_4 ( V_2 , 1 ) ;
V_26 = ( unsigned char ) F_6 ( V_27 ) ;
V_26 |= ( unsigned char ) F_6 ( V_28 ) << 8 ;
V_26 |= ( unsigned char ) F_6 ( V_29 ) << 16 ;
V_26 |= ( unsigned char ) F_6 ( V_30 ) << 24 ;
* V_17 = V_26 ;
return V_25 ;
}
static int F_13 ( void * V_34 , T_1 V_35 , int V_36 , int V_37 , T_1 V_38 [ V_39 ] )
{
struct V_40 * V_41 = V_34 ;
unsigned long V_11 ;
T_1 V_17 , V_42 , V_25 ;
int V_43 ;
F_14 ( 1 , L_1 , V_44 , V_35 ) ;
F_10 ( V_41 -> V_2 , V_41 -> V_45 - 4 , & V_17 ) ;
if ( V_17 != 0x12345678 ) {
F_14 ( 0 , L_2 ) ;
return - 1 ;
}
F_10 ( V_41 -> V_2 , V_41 -> V_45 , & V_42 ) ;
if ( V_42 ) {
F_14 ( 0 , L_3 , V_42 ) ;
return - 1 ;
}
V_42 |= 1 ;
F_8 ( V_41 -> V_2 , V_41 -> V_45 , V_42 ) ;
F_8 ( V_41 -> V_2 , V_41 -> V_45 + 1 , V_35 ) ;
F_8 ( V_41 -> V_2 , V_41 -> V_45 + 3 , V_46 ) ;
for ( V_43 = 0 ; V_43 < V_36 ; V_43 ++ ) {
F_8 ( V_41 -> V_2 , V_41 -> V_45 + 4 + V_43 , V_38 [ V_43 ] ) ;
F_14 ( 1 , L_4 , V_43 , V_38 [ V_43 ] ) ;
}
for (; V_43 < V_39 ; V_43 ++ )
F_8 ( V_41 -> V_2 , V_41 -> V_45 + 4 + V_43 , 0 ) ;
V_42 |= 3 ;
F_8 ( V_41 -> V_2 , V_41 -> V_45 , V_42 ) ;
V_11 = V_12 + F_5 ( 10 ) ;
for (; ; ) {
F_10 ( V_41 -> V_2 , V_41 -> V_45 , & V_42 ) ;
if ( 0 != ( V_42 & 4 ) )
break;
if ( F_7 ( V_12 , V_11 ) ) {
F_14 ( 0 , L_5 ) ;
return - 1 ;
}
F_3 ( 10 ) ;
}
for ( V_43 = 0 ; V_43 < V_37 ; V_43 ++ ) {
F_10 ( V_41 -> V_2 , V_41 -> V_45 + 4 + V_43 , V_38 + V_43 ) ;
F_14 ( 1 , L_6 , V_43 , V_38 [ V_43 ] ) ;
}
F_10 ( V_41 -> V_2 , V_41 -> V_45 + 2 , & V_25 ) ;
F_14 ( 1 , L_7 , V_25 ) ;
V_42 = 0 ;
F_8 ( V_41 -> V_2 , V_41 -> V_45 , V_42 ) ;
return V_25 ;
}
static int F_15 ( struct V_40 * V_41 , T_1 V_35 ,
T_1 V_47 , T_1 V_48 , ... )
{
T_1 V_38 [ V_39 ] ;
T_2 V_49 ;
int V_43 , V_50 ;
va_start ( V_49 , V_48 ) ;
for ( V_43 = 0 ; V_43 < V_47 ; V_43 ++ ) {
V_38 [ V_43 ] = va_arg ( V_49 , int ) ;
}
V_50 = F_13 ( V_41 , V_35 , V_47 , V_48 , V_38 ) ;
for ( V_43 = 0 ; V_43 < V_48 ; V_43 ++ ) {
int * V_51 = va_arg ( V_49 , int * ) ;
* V_51 = V_38 [ V_43 ] ;
}
va_end ( V_49 ) ;
return V_50 ;
}
static int F_16 ( struct V_40 * V_41 )
{
T_1 V_52 [ 4 ] = { 0x12345678 , 0x34567812 , 0x56781234 , 0x78123456 } ;
int V_53 = 0 ;
T_1 V_17 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_54 ; V_43 ++ ) {
F_10 ( V_41 -> V_2 , V_43 , & V_17 ) ;
if ( V_17 == V_52 [ V_53 ] )
V_53 ++ ;
else
V_53 = 0 ;
if ( 4 == V_53 ) {
F_14 ( 1 , L_8 ) ;
return V_43 + 1 ;
}
}
F_14 ( 0 , L_9 ) ;
return - 1 ;
}
static int F_17 ( struct V_40 * V_41 )
{
static const unsigned char V_55 [ 8 ] = {
0xa7 , 0x0d , 0x00 , 0x00 , 0x66 , 0xbb , 0x55 , 0xaa
} ;
const struct V_56 * V_56 ;
int V_43 , V_25 = 0 ;
T_1 V_17 = 0 ;
T_1 V_57 = 0 ;
T_1 * V_58 ;
V_25 = F_11 ( V_41 -> V_2 , V_59 , 0xFFFFFFED ) ;
V_25 |= F_11 ( V_41 -> V_2 , V_60 , V_61 ) ;
V_25 |= F_11 ( V_41 -> V_2 , V_62 , 0x80000640 ) ;
V_25 |= F_11 ( V_41 -> V_2 , V_63 , 0x1A ) ;
F_18 ( 1 ) ;
V_25 |= F_11 ( V_41 -> V_2 , V_64 , 0 ) ;
if ( V_25 < 0 )
F_14 ( 0 , L_10 ) ;
V_25 = F_19 ( & V_56 , V_65 ,
& V_41 -> V_66 -> V_41 ) ;
if ( V_25 != 0 ) {
F_14 ( 0 , L_11 ,
V_65 ) ;
F_14 ( 0 , L_12
L_13 ) ;
return - 1 ;
}
if ( V_56 -> V_67 != V_54 ) {
F_14 ( 0 , L_14 ,
V_56 -> V_67 , V_54 ) ;
F_20 ( V_56 ) ;
return - 1 ;
}
if ( 0 != memcmp ( V_56 -> V_38 , V_55 , 8 ) ) {
F_14 ( 0 , L_15 ) ;
F_20 ( V_56 ) ;
return - 1 ;
}
F_14 ( 1 , L_16 ) ;
V_58 = ( T_1 * ) V_56 -> V_38 ;
for ( V_43 = 0 ; V_43 < ( V_56 -> V_67 >> 2 ) ; V_43 ++ ) {
V_17 = * V_58 ;
V_57 += ~ V_17 ;
F_8 ( V_41 -> V_2 , V_43 , V_17 ) ;
V_58 ++ ;
}
for ( V_43 -- ; V_43 >= 0 ; V_43 -- ) {
F_10 ( V_41 -> V_2 , V_43 , & V_17 ) ;
V_57 -= ~ V_17 ;
}
if ( V_57 ) {
F_14 ( 0 , L_17 ) ;
F_20 ( V_56 ) ;
return - 1 ;
}
F_20 ( V_56 ) ;
F_14 ( 0 , L_18 ) ;
V_25 |= F_11 ( V_41 -> V_2 , V_60 , V_61 ) ;
V_25 |= F_12 ( V_41 -> V_2 , V_68 , & V_17 ) ;
V_25 |= F_11 ( V_41 -> V_2 , V_68 , V_17 & 0xFFFFFFFE ) ;
F_18 ( 1 ) ;
V_25 |= F_12 ( V_41 -> V_2 , V_59 , & V_17 ) ;
V_25 |= F_11 ( V_41 -> V_2 , V_59 , V_17 & 0xFFFFFFE8 ) ;
if ( V_25 < 0 )
F_14 ( 0 , L_10 ) ;
return 0 ;
}
static void F_21 ( struct V_40 * V_41 )
{
F_15 ( V_41 , V_69 , 2 , 0 ,
V_41 -> V_70 , V_41 -> V_71 ) ;
V_41 -> V_72 . V_71 = V_41 -> V_71 ;
V_41 -> V_72 . V_70 = V_41 -> V_70 ;
V_41 -> V_72 . V_73 = ( V_41 -> V_2 -> V_74 & V_75 ) != 0 ;
F_22 ( V_41 , F_13 , NULL , & V_41 -> V_72 ) ;
}
static int F_23 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_2 ;
int V_76 ;
int V_25 ;
F_14 ( 1 , L_19 ) ;
V_25 = F_15 ( V_41 , V_77 , 0 , 0 ) ;
if ( V_25 < 0 ) {
V_41 -> V_78 = 0 ;
F_2 ( V_79 , 0 ) ;
F_2 ( V_79 , 1 ) ;
V_25 = F_17 ( V_41 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_16 ( V_41 ) ;
if ( V_25 < 0 )
return - 1 ;
V_41 -> V_45 = V_25 ;
V_25 = F_15 ( V_41 , V_77 , 0 , 0 ) ;
if ( V_25 < 0 ) {
F_14 ( 0 , L_20 ) ;
return - 1 ;
}
V_25 = F_15 ( V_41 , V_80 , 0 , 1 , & V_76 ) ;
if ( V_25 < 0 ) {
F_14 ( 0 , L_21 ) ;
return - 1 ;
}
F_14 ( 0 , L_22 , V_76 ) ;
}
F_2 ( V_81 , 0x88 ) ;
F_24 ( V_82 , 0x100 ) ;
F_2 ( V_83 , 0x84A00 ) ;
F_24 ( V_84 , 0x0008 ) ;
F_21 ( V_41 ) ;
F_15 ( V_41 , V_85 , 2 , 0 ,
V_86 ,
V_87
) ;
F_15 ( V_41 , V_88 , 12 , 0 ,
V_89 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) ;
return 0 ;
}
static int F_25 ( struct V_90 * V_90 , void * V_34 )
{
struct V_40 * V_41 = ( (struct V_91 * ) V_34 ) -> V_41 ;
struct V_1 * V_2 = V_41 -> V_2 ;
T_1 V_92 ;
int V_43 ;
int V_93 = - 1 ;
int V_94 = 0 ;
for ( V_43 = 0 ; ( V_43 < 10 ) && ( V_43 < ( V_93 + 4 ) ) ; V_43 ++ ) {
V_92 = F_6 ( V_95 ) ;
F_14 ( 1 , L_23 , V_43 , V_92 ) ;
if ( ( V_92 & 0x0F ) != V_94 ) {
V_94 = V_92 & 0x0F ;
V_93 = V_43 ;
}
F_18 ( 100 ) ;
}
F_24 ( V_96 , ( 1 << 6 ) ) ;
F_15 ( V_41 , V_97 , 0 , 0 ) ;
F_15 ( V_41 , V_98 , 0 , 0 ) ;
F_15 ( V_41 , V_99 , 2 , 0 ,
V_100 ,
V_101
) ;
V_41 -> V_78 = 1 ;
return 0 ;
}
static int F_26 ( struct V_40 * V_41 )
{
F_15 ( V_41 , V_102 , 3 , 0 ,
V_103 ,
V_100 ,
V_101
) ;
V_41 -> V_78 = 0 ;
return 0 ;
}
static int F_27 ( struct V_104 * V_105 ,
unsigned int * V_106 , unsigned int * V_67 )
{
struct V_91 * V_107 = V_105 -> V_108 ;
V_107 -> V_41 -> V_109 = 188 * 4 ;
V_107 -> V_41 -> V_110 = V_111 ;
* V_67 = V_107 -> V_41 -> V_109 * V_107 -> V_41 -> V_110 ;
* V_106 = V_107 -> V_41 -> V_110 ;
return 0 ;
}
static int
F_28 ( struct V_104 * V_105 , struct V_112 * V_113 ,
enum V_114 V_115 )
{
struct V_91 * V_107 = V_105 -> V_108 ;
return F_29 ( V_105 , V_107 -> V_41 , (struct V_116 * ) V_113 , V_115 ) ;
}
static void
F_30 ( struct V_104 * V_105 , struct V_112 * V_113 )
{
struct V_91 * V_107 = V_105 -> V_108 ;
F_31 ( V_107 -> V_41 , (struct V_116 * ) V_113 ) ;
}
static void
F_32 ( struct V_104 * V_105 , struct V_112 * V_113 )
{
F_33 ( V_105 , (struct V_116 * ) V_113 ) ;
}
static int F_34 ( struct V_40 * V_41 , struct V_117 * V_118 )
{
V_118 -> V_119 = F_35 ( V_120 , V_118 -> V_119 ) ;
if ( V_118 -> V_119 == 0 )
return - V_121 ;
if ( F_36 ( V_41 -> V_2 , V_118 ) == 0 )
return 0 ;
if ( F_37 ( & V_41 -> V_72 , V_118 ) )
V_118 -> V_122 |= V_123 ;
return 0 ;
}
static int F_38 ( struct V_90 * V_90 , void * V_34 ,
struct V_124 * V_125 )
{
struct V_40 * V_41 = ( (struct V_91 * ) V_34 ) -> V_41 ;
struct V_117 V_118 ;
V_118 . V_119 = V_125 -> V_119 ;
F_34 ( V_41 , & V_118 ) ;
return F_39 ( V_125 , & V_118 ,
F_40 ( & V_41 -> V_72 , V_125 -> V_119 ) ) ;
}
static int F_41 ( struct V_90 * V_90 , void * V_34 ,
struct V_126 * V_127 )
{
struct V_40 * V_41 = ( (struct V_91 * ) V_34 ) -> V_41 ;
struct V_1 * V_2 = V_41 -> V_2 ;
strcpy ( V_127 -> V_128 , L_24 ) ;
F_42 ( V_127 -> V_129 , V_2 -> V_130 . V_131 , sizeof( V_127 -> V_129 ) ) ;
sprintf ( V_127 -> V_132 , L_25 , F_43 ( V_41 -> V_66 ) ) ;
V_127 -> V_76 = V_133 ;
V_127 -> V_134 =
V_135 |
V_136 |
V_137 ;
if ( V_138 != V_2 -> V_130 . V_139 )
V_127 -> V_134 |= V_140 ;
return 0 ;
}
static int F_44 ( struct V_90 * V_90 , void * V_34 ,
struct V_141 * V_142 )
{
if ( V_142 -> V_143 != 0 )
return - V_121 ;
F_42 ( V_142 -> V_144 , L_26 , sizeof( V_142 -> V_144 ) ) ;
V_142 -> V_145 = V_146 ;
return 0 ;
}
static int F_45 ( struct V_90 * V_90 , void * V_34 ,
struct V_147 * V_142 )
{
struct V_91 * V_107 = V_34 ;
struct V_40 * V_41 = V_107 -> V_41 ;
V_142 -> V_148 . V_149 . V_145 = V_146 ;
V_142 -> V_148 . V_149 . V_150 = 0 ;
V_142 -> V_148 . V_149 . V_151 = V_41 -> V_109 * V_41 -> V_110 ;
V_142 -> V_148 . V_149 . V_152 = 0 ;
V_142 -> V_148 . V_149 . V_71 = V_41 -> V_71 ;
V_142 -> V_148 . V_149 . V_70 = V_41 -> V_70 ;
V_142 -> V_148 . V_149 . V_115 = V_107 -> V_153 . V_115 ;
F_14 ( 0 , L_27 ,
V_41 -> V_71 , V_41 -> V_70 , V_107 -> V_153 . V_115 ) ;
return 0 ;
}
static int F_46 ( struct V_90 * V_90 , void * V_34 ,
struct V_147 * V_142 )
{
struct V_91 * V_107 = V_34 ;
struct V_40 * V_41 = V_107 -> V_41 ;
V_142 -> V_148 . V_149 . V_145 = V_146 ;
V_142 -> V_148 . V_149 . V_150 = 0 ;
V_142 -> V_148 . V_149 . V_151 = V_41 -> V_109 * V_41 -> V_110 ; ;
V_142 -> V_148 . V_149 . V_152 = 0 ;
F_14 ( 0 , L_28 ,
V_41 -> V_71 , V_41 -> V_70 , V_107 -> V_153 . V_115 ) ;
return 0 ;
}
static int F_47 ( struct V_90 * V_90 , void * V_34 ,
struct V_147 * V_142 )
{
struct V_91 * V_107 = V_34 ;
struct V_40 * V_41 = V_107 -> V_41 ;
struct V_1 * V_2 = V_41 -> V_2 ;
V_142 -> V_148 . V_149 . V_145 = V_146 ;
V_142 -> V_148 . V_149 . V_150 = 0 ;
V_142 -> V_148 . V_149 . V_151 = V_41 -> V_109 * V_41 -> V_110 ; ;
V_142 -> V_148 . V_149 . V_152 = 0 ;
V_41 -> V_71 = V_142 -> V_148 . V_149 . V_71 ;
V_41 -> V_70 = V_142 -> V_148 . V_149 . V_70 ;
V_107 -> V_153 . V_115 = V_142 -> V_148 . V_149 . V_115 ;
F_48 ( V_2 , V_142 -> V_148 . V_149 . V_71 , V_142 -> V_148 . V_149 . V_70 , V_142 -> V_148 . V_149 . V_115 ) ;
F_15 ( V_41 , V_69 , 2 , 0 ,
V_142 -> V_148 . V_149 . V_70 , V_142 -> V_148 . V_149 . V_71 ) ;
F_14 ( 0 , L_29 ,
V_142 -> V_148 . V_149 . V_71 , V_142 -> V_148 . V_149 . V_70 , V_142 -> V_148 . V_149 . V_115 ) ;
return 0 ;
}
static int F_49 ( struct V_90 * V_90 , void * V_34 , struct V_154 * V_155 )
{
struct V_91 * V_107 = V_34 ;
return ( F_50 ( & V_107 -> V_153 , V_155 ) ) ;
}
static int F_51 ( struct V_90 * V_90 , void * V_34 , struct V_156 * V_155 )
{
struct V_91 * V_107 = V_34 ;
return ( F_52 ( & V_107 -> V_153 , V_155 ) ) ;
}
static int F_53 ( struct V_90 * V_90 , void * V_34 , struct V_156 * V_155 )
{
struct V_91 * V_107 = V_34 ;
return ( F_54 ( & V_107 -> V_153 , V_155 ) ) ;
}
static int F_55 ( struct V_90 * V_90 , void * V_34 , struct V_156 * V_155 )
{
struct V_91 * V_107 = V_34 ;
return ( F_56 ( & V_107 -> V_153 , V_155 ,
V_90 -> V_157 & V_158 ) ) ;
}
static int F_57 ( struct V_90 * V_90 , void * V_34 , enum V_159 V_43 )
{
struct V_91 * V_107 = V_34 ;
return F_58 ( & V_107 -> V_153 ) ;
}
static int F_59 ( struct V_90 * V_90 , void * V_34 , enum V_159 V_43 )
{
struct V_91 * V_107 = V_34 ;
return F_60 ( & V_107 -> V_153 ) ;
}
static int F_61 ( struct V_90 * V_90 , void * V_34 ,
struct V_160 * V_142 )
{
struct V_40 * V_41 = ( (struct V_91 * ) V_34 ) -> V_41 ;
if ( V_142 -> V_161 != V_162 )
return - V_121 ;
return F_62 ( & V_41 -> V_72 , 0 , V_142 , V_163 ) ;
}
static int F_63 ( struct V_90 * V_90 , void * V_34 ,
struct V_160 * V_142 )
{
struct V_40 * V_41 = ( (struct V_91 * ) V_34 ) -> V_41 ;
struct V_164 V_155 ;
int V_50 ;
if ( V_142 -> V_161 != V_162 )
return - V_121 ;
if ( V_41 -> V_78 )
F_26 ( V_41 ) ;
V_155 = V_41 -> V_72 ;
V_50 = F_62 ( & V_155 , 0 , V_142 , V_165 ) ;
if ( ! V_50 ) {
V_50 = F_22 ( V_41 , F_13 , & V_41 -> V_72 , & V_155 ) ;
V_41 -> V_72 = V_155 ;
}
return V_50 ;
}
static int F_64 ( struct V_90 * V_90 , void * V_34 ,
struct V_160 * V_142 )
{
struct V_40 * V_41 = ( (struct V_91 * ) V_34 ) -> V_41 ;
struct V_164 V_155 ;
int V_50 ;
if ( V_142 -> V_161 != V_162 )
return - V_121 ;
V_155 = V_41 -> V_72 ;
V_50 = F_62 ( & V_155 , 0 , V_142 , V_166 ) ;
return V_50 ;
}
static int F_65 ( struct V_90 * V_90 , void * V_34 ,
struct V_167 * V_142 )
{
struct V_91 * V_107 = V_34 ;
struct V_40 * V_41 = V_107 -> V_41 ;
struct V_1 * V_2 = V_41 -> V_2 ;
if ( V_41 -> V_78 )
F_26 ( V_41 ) ;
F_66 ( V_2 , V_142 ) ;
F_23 ( V_41 ) ;
F_48 ( V_41 -> V_2 , V_41 -> V_71 , V_41 -> V_70 ,
V_107 -> V_153 . V_115 ) ;
return 0 ;
}
static int F_67 ( struct V_90 * V_90 , void * V_34 )
{
struct V_40 * V_41 = ( (struct V_91 * ) V_34 ) -> V_41 ;
struct V_1 * V_2 = V_41 -> V_2 ;
char V_131 [ 32 + 2 ] ;
snprintf ( V_131 , sizeof( V_131 ) , L_30 , V_2 -> V_131 ) ;
F_68 ( L_31 ,
V_2 -> V_131 ) ;
F_69 ( V_2 , V_2 , V_168 ) ;
F_70 ( & V_41 -> V_72 , V_131 ) ;
F_68 ( L_32 ,
V_2 -> V_131 ) ;
return 0 ;
}
static int F_71 ( struct V_90 * V_90 , void * V_34 ,
struct V_117 * V_118 )
{
struct V_40 * V_41 = ( (struct V_91 * ) V_34 ) -> V_41 ;
if ( F_34 ( V_41 , V_118 ) == 0 )
return 0 ;
V_118 -> V_119 = F_35 ( V_120 , V_118 -> V_119 ) ;
if ( F_72 ( V_118 -> V_119 == 0 ) )
return - V_121 ;
return F_36 ( V_41 -> V_2 , V_118 ) ;
}
static int F_73 ( struct V_90 * V_90 , void * V_34 ,
struct V_169 * V_43 )
{
struct V_1 * V_2 = ( (struct V_91 * ) V_34 ) -> V_41 -> V_2 ;
return F_74 ( V_2 , V_43 ) ;
}
static int F_75 ( struct V_90 * V_90 , void * V_34 ,
struct V_170 * V_171 )
{
struct V_1 * V_2 = ( (struct V_91 * ) V_34 ) -> V_41 -> V_2 ;
return
F_76 ( V_2 , V_171 ) ;
}
static int F_77 ( struct V_90 * V_90 , void * V_34 ,
struct V_170 * V_171 )
{
struct V_1 * V_2 = ( (struct V_91 * ) V_34 ) -> V_41 -> V_2 ;
return
F_78 ( V_2 , V_171 ) ;
}
static int F_79 ( struct V_90 * V_90 , void * V_34 ,
struct V_167 * V_142 )
{
struct V_91 * V_107 = V_34 ;
struct V_1 * V_2 = V_107 -> V_41 -> V_2 ;
if ( F_72 ( V_138 == V_2 -> V_130 . V_139 ) )
return - V_121 ;
V_142 -> type = V_172 ;
V_142 -> V_173 = V_2 -> V_174 ;
F_69 ( V_2 , V_175 , V_176 , V_142 ) ;
return 0 ;
}
static int F_80 ( struct V_90 * V_90 , void * V_34 , unsigned int * V_43 )
{
struct V_1 * V_2 = ( (struct V_91 * ) V_34 ) -> V_41 -> V_2 ;
* V_43 = V_2 -> V_177 ;
return 0 ;
}
static int F_81 ( struct V_90 * V_90 , void * V_34 , unsigned int V_43 )
{
struct V_1 * V_2 = ( (struct V_91 * ) V_34 ) -> V_41 -> V_2 ;
if ( V_43 >= 4 )
return - V_121 ;
F_82 ( & V_2 -> V_178 ) ;
F_83 ( V_2 ) ;
F_84 ( V_2 , V_43 ) ;
F_85 ( & V_2 -> V_178 ) ;
return 0 ;
}
static int F_86 ( struct V_90 * V_90 , void * V_34 ,
struct V_179 * V_180 )
{
struct V_1 * V_2 = ( (struct V_91 * ) V_34 ) -> V_41 -> V_2 ;
T_1 V_92 ;
if ( F_72 ( V_138 == V_2 -> V_130 . V_139 ) )
return - V_121 ;
if ( 0 != V_180 -> V_143 )
return - V_121 ;
strcpy ( V_180 -> V_131 , L_33 ) ;
V_180 -> type = V_172 ;
V_180 -> V_181 = V_182 ;
V_180 -> V_183 = 0xffffffffUL ;
F_87 ( V_2 , V_180 ) ;
V_92 = F_6 ( V_184 ) ;
V_180 -> signal = ( V_92 & ( 1 << 5 ) ) ? 0xffff : 0x0000 ;
return 0 ;
}
static int F_88 ( struct V_90 * V_90 , void * V_34 ,
struct V_179 * V_180 )
{
struct V_1 * V_2 = ( (struct V_91 * ) V_34 ) -> V_41 -> V_2 ;
if ( V_138 == V_2 -> V_130 . V_139 )
return - V_121 ;
if ( 0 != V_180 -> V_143 )
return - V_121 ;
F_89 ( V_2 , V_180 -> V_185 , 1 ) ;
return 0 ;
}
static int F_90 ( struct V_90 * V_90 , void * V_34 , T_3 * V_119 )
{
struct V_1 * V_2 = ( (struct V_91 * ) V_34 ) -> V_41 -> V_2 ;
F_82 ( & V_2 -> V_178 ) ;
F_91 ( V_2 , * V_119 ) ;
F_85 ( & V_2 -> V_178 ) ;
return 0 ;
}
static int F_92 ( struct V_90 * V_90 )
{
struct V_186 * V_187 = F_93 ( V_90 ) ;
struct V_40 * V_41 = F_94 ( V_90 ) ;
struct V_91 * V_107 ;
struct V_188 * V_189 = NULL ;
int V_50 ;
F_14 ( 1 , L_34 , V_44 ) ;
F_82 ( & V_41 -> V_2 -> V_178 ) ;
V_189 = F_95 ( V_41 , V_190 ) ;
if ( ! V_189 ) {
F_14 ( 1 , L_35 , V_44 ) ;
F_85 ( & V_41 -> V_2 -> V_178 ) ;
return - V_191 ;
}
V_50 = V_189 -> V_192 ( V_189 ) ;
if ( V_50 != 0 ) {
F_14 ( 1 , L_36 , V_44 , V_50 ) ;
F_85 ( & V_41 -> V_2 -> V_178 ) ;
return V_50 ;
}
if ( ! V_41 -> V_2 -> V_193 && F_23 ( V_41 ) < 0 ) {
V_189 -> V_194 ( V_189 ) ;
F_85 ( & V_41 -> V_2 -> V_178 ) ;
return - V_121 ;
}
F_14 ( 1 , L_37 , F_96 ( V_187 ) ) ;
V_107 = F_97 ( sizeof( * V_107 ) , V_195 ) ;
if ( NULL == V_107 ) {
V_189 -> V_194 ( V_189 ) ;
F_85 ( & V_41 -> V_2 -> V_178 ) ;
return - V_196 ;
}
V_90 -> V_197 = V_107 ;
V_107 -> V_41 = V_41 ;
F_98 ( & V_107 -> V_153 , & V_198 ,
& V_41 -> V_66 -> V_41 , & V_41 -> V_199 ,
V_200 ,
V_201 ,
sizeof( struct V_116 ) ,
V_107 , NULL ) ;
F_48 ( V_41 -> V_2 , V_41 -> V_71 , V_41 -> V_70 ,
V_107 -> V_153 . V_115 ) ;
V_41 -> V_2 -> V_193 ++ ;
F_85 ( & V_41 -> V_2 -> V_178 ) ;
return 0 ;
}
static int F_99 ( struct V_90 * V_90 )
{
struct V_91 * V_107 = V_90 -> V_197 ;
struct V_40 * V_41 = V_107 -> V_41 ;
struct V_188 * V_189 = NULL ;
F_82 ( & V_41 -> V_2 -> V_178 ) ;
if ( V_41 -> V_78 && V_41 -> V_2 -> V_193 == 1 )
F_26 ( V_41 ) ;
F_100 ( V_107 -> V_41 ) ;
F_101 ( & V_107 -> V_153 ) ;
F_102 ( & V_107 -> V_153 ) ;
V_90 -> V_197 = NULL ;
F_103 ( V_107 ) ;
V_189 = F_95 ( V_41 , V_190 ) ;
F_104 ( ! V_189 ) ;
if ( V_189 )
V_189 -> V_194 ( V_189 ) ;
V_41 -> V_2 -> V_193 -- ;
F_85 ( & V_41 -> V_2 -> V_178 ) ;
return 0 ;
}
static T_4
F_105 ( struct V_90 * V_90 , char T_5 * V_38 , T_6 V_106 , T_7 * V_202 )
{
struct V_91 * V_107 = V_90 -> V_197 ;
struct V_40 * V_41 = V_107 -> V_41 ;
if ( ! V_41 -> V_78 )
F_25 ( V_90 , V_107 ) ;
return F_106 ( & V_107 -> V_153 , V_38 , V_106 , V_202 , 0 ,
V_90 -> V_157 & V_158 ) ;
}
static unsigned int
F_107 ( struct V_90 * V_90 , struct V_203 * V_204 )
{
struct V_91 * V_107 = V_90 -> V_197 ;
struct V_40 * V_41 = V_107 -> V_41 ;
if ( ! V_41 -> V_78 )
F_25 ( V_90 , V_107 ) ;
return F_108 ( V_90 , & V_107 -> V_153 , V_204 ) ;
}
static int
F_109 ( struct V_90 * V_90 , struct V_205 * V_206 )
{
struct V_91 * V_107 = V_90 -> V_197 ;
return F_110 ( & V_107 -> V_153 , V_206 ) ;
}
static int F_111 ( struct V_188 * V_189 )
{
struct V_1 * V_2 = V_189 -> V_2 ;
int V_50 = 0 ;
switch ( V_2 -> V_207 ) {
case V_208 :
F_112 ( V_15 , 0x00000080 ) ;
F_3 ( 1000 ) ;
F_24 ( V_15 , 0x00000080 ) ;
F_3 ( 50 ) ;
F_112 ( V_15 , 0x00000080 ) ;
F_3 ( 1000 ) ;
F_112 ( V_15 , 0x00000004 ) ;
F_3 ( 1000 ) ;
break;
default:
V_50 = - V_191 ;
}
return V_50 ;
}
static int F_113 ( struct V_188 * V_189 )
{
struct V_1 * V_2 = V_189 -> V_2 ;
int V_50 = 0 ;
switch ( V_2 -> V_207 ) {
case V_208 :
break;
default:
V_50 = - V_191 ;
}
return V_50 ;
}
static void F_114 ( struct V_40 * V_41 )
{
if ( V_41 -> V_209 ) {
if ( F_115 ( V_41 -> V_209 ) )
F_116 ( V_41 -> V_209 ) ;
else
F_117 ( V_41 -> V_209 ) ;
V_41 -> V_209 = NULL ;
}
}
static int F_118 ( struct V_40 * V_41 )
{
int V_50 ;
V_41 -> V_209 = F_119 ( V_41 -> V_2 , V_41 -> V_66 ,
& V_210 , L_38 ) ;
F_120 ( V_41 -> V_209 , V_41 ) ;
V_50 = F_121 ( V_41 -> V_209 , V_211 , - 1 ) ;
if ( V_50 < 0 ) {
F_68 ( V_212 L_39 ,
V_41 -> V_2 -> V_131 ) ;
return V_50 ;
}
F_68 ( V_212 L_40 ,
V_41 -> V_2 -> V_131 , F_96 ( V_41 -> V_209 ) ) ;
return 0 ;
}
static int F_122 ( struct V_188 * V_189 )
{
struct V_1 * V_2 = V_189 -> V_2 ;
struct V_40 * V_41 = V_2 -> V_213 ;
int V_50 ;
F_14 ( 1 , L_34 , V_44 ) ;
F_14 ( 1 , L_41 ,
V_2 -> V_207 ,
V_2 -> V_131 ,
V_2 -> V_214 ,
V_2 -> V_215 ) ;
V_50 = - V_191 ;
if ( ! ( V_2 -> V_130 . V_216 & V_190 ) )
goto V_217;
V_41 -> V_71 = 720 ;
V_41 -> V_70 = 576 ;
F_123 ( & V_41 -> V_72 ) ;
V_41 -> V_72 . V_218 = V_219 ;
V_210 . V_220 = V_2 -> V_74 ;
if ( V_2 -> V_74 & V_221 ) {
V_41 -> V_70 = 480 ;
} else {
V_41 -> V_70 = 576 ;
}
F_68 ( L_42 ,
V_2 -> V_131 ) ;
F_1 ( V_41 -> V_2 ) ;
F_23 ( V_41 ) ;
F_118 ( V_41 ) ;
F_91 ( V_2 , V_2 -> V_74 ) ;
F_84 ( V_2 , 0 ) ;
return 0 ;
V_217:
return V_50 ;
}
static int F_124 ( struct V_188 * V_189 )
{
F_114 ( V_189 -> V_2 -> V_213 ) ;
return 0 ;
}
static int T_8 F_125 ( void )
{
F_68 ( V_212 L_43 ,
( V_133 >> 16 ) & 0xff ,
( V_133 >> 8 ) & 0xff ,
V_133 & 0xff ) ;
#ifdef F_126
F_68 ( V_212 L_44 ,
F_126 / 10000 , ( F_126 / 100 ) % 100 , F_126 % 100 ) ;
#endif
return F_127 ( & V_222 ) ;
}
static void T_9 F_128 ( void )
{
F_129 ( & V_222 ) ;
}
