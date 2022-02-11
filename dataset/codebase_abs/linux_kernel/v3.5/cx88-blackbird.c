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
V_17 = F_21 ( * V_58 ) ;
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
static void F_22 ( struct V_40 * V_41 )
{
F_15 ( V_41 , V_69 , 2 , 0 ,
V_41 -> V_70 , V_41 -> V_71 ) ;
V_41 -> V_72 . V_71 = V_41 -> V_71 ;
V_41 -> V_72 . V_70 = V_41 -> V_70 ;
V_41 -> V_72 . V_73 = ( V_41 -> V_2 -> V_74 & V_75 ) != 0 ;
F_23 ( V_41 , F_13 , NULL , & V_41 -> V_72 ) ;
}
static int F_24 ( struct V_40 * V_41 )
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
F_25 ( V_82 , 0x100 ) ;
F_2 ( V_83 , 0x84A00 ) ;
F_25 ( V_84 , 0x0008 ) ;
F_22 ( V_41 ) ;
F_15 ( V_41 , V_85 , 2 , 0 ,
V_86 ,
V_87
) ;
F_15 ( V_41 , V_88 , 12 , 0 ,
V_89 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) ;
return 0 ;
}
static int F_26 ( struct V_90 * V_90 , void * V_34 )
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
F_25 ( V_96 , ( 1 << 6 ) ) ;
F_15 ( V_41 , V_97 , 0 , 0 ) ;
F_15 ( V_41 , V_98 , 0 , 0 ) ;
F_15 ( V_41 , V_99 , 2 , 0 ,
V_100 ,
V_101
) ;
V_41 -> V_78 = 1 ;
return 0 ;
}
static int F_27 ( struct V_40 * V_41 )
{
F_15 ( V_41 , V_102 , 3 , 0 ,
V_103 ,
V_100 ,
V_101
) ;
V_41 -> V_78 = 0 ;
return 0 ;
}
static int F_28 ( struct V_104 * V_105 ,
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
F_29 ( struct V_104 * V_105 , struct V_112 * V_113 ,
enum V_114 V_115 )
{
struct V_91 * V_107 = V_105 -> V_108 ;
return F_30 ( V_105 , V_107 -> V_41 , (struct V_116 * ) V_113 , V_115 ) ;
}
static void
F_31 ( struct V_104 * V_105 , struct V_112 * V_113 )
{
struct V_91 * V_107 = V_105 -> V_108 ;
F_32 ( V_107 -> V_41 , (struct V_116 * ) V_113 ) ;
}
static void
F_33 ( struct V_104 * V_105 , struct V_112 * V_113 )
{
F_34 ( V_105 , (struct V_116 * ) V_113 ) ;
}
static int F_35 ( struct V_40 * V_41 , struct V_117 * V_118 )
{
V_118 -> V_119 = F_36 ( V_120 , V_118 -> V_119 ) ;
if ( V_118 -> V_119 == 0 )
return - V_121 ;
if ( F_37 ( V_41 -> V_2 , V_118 ) == 0 )
return 0 ;
if ( F_38 ( & V_41 -> V_72 , V_118 ) )
V_118 -> V_122 |= V_123 ;
return 0 ;
}
static int F_39 ( struct V_90 * V_90 , void * V_34 ,
struct V_124 * V_125 )
{
struct V_40 * V_41 = ( (struct V_91 * ) V_34 ) -> V_41 ;
struct V_117 V_118 ;
V_118 . V_119 = V_125 -> V_119 ;
F_35 ( V_41 , & V_118 ) ;
return F_40 ( V_125 , & V_118 ,
F_41 ( & V_41 -> V_72 , V_125 -> V_119 ) ) ;
}
static int F_42 ( struct V_90 * V_90 , void * V_34 ,
struct V_126 * V_127 )
{
struct V_40 * V_41 = ( (struct V_91 * ) V_34 ) -> V_41 ;
struct V_1 * V_2 = V_41 -> V_2 ;
strcpy ( V_127 -> V_128 , L_24 ) ;
F_43 ( V_127 -> V_129 , V_2 -> V_130 . V_131 , sizeof( V_127 -> V_129 ) ) ;
sprintf ( V_127 -> V_132 , L_25 , F_44 ( V_41 -> V_66 ) ) ;
V_127 -> V_133 =
V_134 |
V_135 |
V_136 ;
if ( V_137 != V_2 -> V_130 . V_138 )
V_127 -> V_133 |= V_139 ;
return 0 ;
}
static int F_45 ( struct V_90 * V_90 , void * V_34 ,
struct V_140 * V_141 )
{
if ( V_141 -> V_142 != 0 )
return - V_121 ;
F_43 ( V_141 -> V_143 , L_26 , sizeof( V_141 -> V_143 ) ) ;
V_141 -> V_144 = V_145 ;
return 0 ;
}
static int F_46 ( struct V_90 * V_90 , void * V_34 ,
struct V_146 * V_141 )
{
struct V_91 * V_107 = V_34 ;
struct V_40 * V_41 = V_107 -> V_41 ;
V_141 -> V_147 . V_148 . V_144 = V_145 ;
V_141 -> V_147 . V_148 . V_149 = 0 ;
V_141 -> V_147 . V_148 . V_150 = V_41 -> V_109 * V_41 -> V_110 ;
V_141 -> V_147 . V_148 . V_151 = 0 ;
V_141 -> V_147 . V_148 . V_71 = V_41 -> V_71 ;
V_141 -> V_147 . V_148 . V_70 = V_41 -> V_70 ;
V_141 -> V_147 . V_148 . V_115 = V_107 -> V_152 . V_115 ;
F_14 ( 0 , L_27 ,
V_41 -> V_71 , V_41 -> V_70 , V_107 -> V_152 . V_115 ) ;
return 0 ;
}
static int F_47 ( struct V_90 * V_90 , void * V_34 ,
struct V_146 * V_141 )
{
struct V_91 * V_107 = V_34 ;
struct V_40 * V_41 = V_107 -> V_41 ;
V_141 -> V_147 . V_148 . V_144 = V_145 ;
V_141 -> V_147 . V_148 . V_149 = 0 ;
V_141 -> V_147 . V_148 . V_150 = V_41 -> V_109 * V_41 -> V_110 ; ;
V_141 -> V_147 . V_148 . V_151 = 0 ;
F_14 ( 0 , L_28 ,
V_41 -> V_71 , V_41 -> V_70 , V_107 -> V_152 . V_115 ) ;
return 0 ;
}
static int F_48 ( struct V_90 * V_90 , void * V_34 ,
struct V_146 * V_141 )
{
struct V_91 * V_107 = V_34 ;
struct V_40 * V_41 = V_107 -> V_41 ;
struct V_1 * V_2 = V_41 -> V_2 ;
V_141 -> V_147 . V_148 . V_144 = V_145 ;
V_141 -> V_147 . V_148 . V_149 = 0 ;
V_141 -> V_147 . V_148 . V_150 = V_41 -> V_109 * V_41 -> V_110 ; ;
V_141 -> V_147 . V_148 . V_151 = 0 ;
V_41 -> V_71 = V_141 -> V_147 . V_148 . V_71 ;
V_41 -> V_70 = V_141 -> V_147 . V_148 . V_70 ;
V_107 -> V_152 . V_115 = V_141 -> V_147 . V_148 . V_115 ;
F_49 ( V_2 , V_141 -> V_147 . V_148 . V_71 , V_141 -> V_147 . V_148 . V_70 , V_141 -> V_147 . V_148 . V_115 ) ;
F_15 ( V_41 , V_69 , 2 , 0 ,
V_141 -> V_147 . V_148 . V_70 , V_141 -> V_147 . V_148 . V_71 ) ;
F_14 ( 0 , L_29 ,
V_141 -> V_147 . V_148 . V_71 , V_141 -> V_147 . V_148 . V_70 , V_141 -> V_147 . V_148 . V_115 ) ;
return 0 ;
}
static int F_50 ( struct V_90 * V_90 , void * V_34 , struct V_153 * V_154 )
{
struct V_91 * V_107 = V_34 ;
return ( F_51 ( & V_107 -> V_152 , V_154 ) ) ;
}
static int F_52 ( struct V_90 * V_90 , void * V_34 , struct V_155 * V_154 )
{
struct V_91 * V_107 = V_34 ;
return ( F_53 ( & V_107 -> V_152 , V_154 ) ) ;
}
static int F_54 ( struct V_90 * V_90 , void * V_34 , struct V_155 * V_154 )
{
struct V_91 * V_107 = V_34 ;
return ( F_55 ( & V_107 -> V_152 , V_154 ) ) ;
}
static int F_56 ( struct V_90 * V_90 , void * V_34 , struct V_155 * V_154 )
{
struct V_91 * V_107 = V_34 ;
return ( F_57 ( & V_107 -> V_152 , V_154 ,
V_90 -> V_156 & V_157 ) ) ;
}
static int F_58 ( struct V_90 * V_90 , void * V_34 , enum V_158 V_43 )
{
struct V_91 * V_107 = V_34 ;
return F_59 ( & V_107 -> V_152 ) ;
}
static int F_60 ( struct V_90 * V_90 , void * V_34 , enum V_158 V_43 )
{
struct V_91 * V_107 = V_34 ;
return F_61 ( & V_107 -> V_152 ) ;
}
static int F_62 ( struct V_90 * V_90 , void * V_34 ,
struct V_159 * V_141 )
{
struct V_40 * V_41 = ( (struct V_91 * ) V_34 ) -> V_41 ;
if ( V_141 -> V_160 != V_161 )
return - V_121 ;
return F_63 ( & V_41 -> V_72 , 0 , V_141 , V_162 ) ;
}
static int F_64 ( struct V_90 * V_90 , void * V_34 ,
struct V_159 * V_141 )
{
struct V_40 * V_41 = ( (struct V_91 * ) V_34 ) -> V_41 ;
struct V_163 V_154 ;
int V_50 ;
if ( V_141 -> V_160 != V_161 )
return - V_121 ;
if ( V_41 -> V_78 )
F_27 ( V_41 ) ;
V_154 = V_41 -> V_72 ;
V_50 = F_63 ( & V_154 , 0 , V_141 , V_164 ) ;
if ( ! V_50 ) {
V_50 = F_23 ( V_41 , F_13 , & V_41 -> V_72 , & V_154 ) ;
V_41 -> V_72 = V_154 ;
}
return V_50 ;
}
static int F_65 ( struct V_90 * V_90 , void * V_34 ,
struct V_159 * V_141 )
{
struct V_40 * V_41 = ( (struct V_91 * ) V_34 ) -> V_41 ;
struct V_163 V_154 ;
int V_50 ;
if ( V_141 -> V_160 != V_161 )
return - V_121 ;
V_154 = V_41 -> V_72 ;
V_50 = F_63 ( & V_154 , 0 , V_141 , V_165 ) ;
return V_50 ;
}
static int F_66 ( struct V_90 * V_90 , void * V_34 ,
struct V_166 * V_141 )
{
struct V_91 * V_107 = V_34 ;
struct V_40 * V_41 = V_107 -> V_41 ;
struct V_1 * V_2 = V_41 -> V_2 ;
if ( V_41 -> V_78 )
F_27 ( V_41 ) ;
F_67 ( V_2 , V_141 ) ;
F_24 ( V_41 ) ;
F_49 ( V_41 -> V_2 , V_41 -> V_71 , V_41 -> V_70 ,
V_107 -> V_152 . V_115 ) ;
return 0 ;
}
static int F_68 ( struct V_90 * V_90 , void * V_34 )
{
struct V_40 * V_41 = ( (struct V_91 * ) V_34 ) -> V_41 ;
struct V_1 * V_2 = V_41 -> V_2 ;
char V_131 [ 32 + 2 ] ;
snprintf ( V_131 , sizeof( V_131 ) , L_30 , V_2 -> V_131 ) ;
F_69 ( L_31 ,
V_2 -> V_131 ) ;
F_70 ( V_2 , V_2 , V_167 ) ;
F_71 ( & V_41 -> V_72 , V_131 ) ;
F_69 ( L_32 ,
V_2 -> V_131 ) ;
return 0 ;
}
static int F_72 ( struct V_90 * V_90 , void * V_34 ,
struct V_117 * V_118 )
{
struct V_40 * V_41 = ( (struct V_91 * ) V_34 ) -> V_41 ;
if ( F_35 ( V_41 , V_118 ) == 0 )
return 0 ;
V_118 -> V_119 = F_36 ( V_120 , V_118 -> V_119 ) ;
if ( F_73 ( V_118 -> V_119 == 0 ) )
return - V_121 ;
return F_37 ( V_41 -> V_2 , V_118 ) ;
}
static int F_74 ( struct V_90 * V_90 , void * V_34 ,
struct V_168 * V_43 )
{
struct V_1 * V_2 = ( (struct V_91 * ) V_34 ) -> V_41 -> V_2 ;
return F_75 ( V_2 , V_43 ) ;
}
static int F_76 ( struct V_90 * V_90 , void * V_34 ,
struct V_169 * V_170 )
{
struct V_1 * V_2 = ( (struct V_91 * ) V_34 ) -> V_41 -> V_2 ;
return
F_77 ( V_2 , V_170 ) ;
}
static int F_78 ( struct V_90 * V_90 , void * V_34 ,
struct V_169 * V_170 )
{
struct V_1 * V_2 = ( (struct V_91 * ) V_34 ) -> V_41 -> V_2 ;
return
F_79 ( V_2 , V_170 ) ;
}
static int F_80 ( struct V_90 * V_90 , void * V_34 ,
struct V_166 * V_141 )
{
struct V_91 * V_107 = V_34 ;
struct V_1 * V_2 = V_107 -> V_41 -> V_2 ;
if ( F_73 ( V_137 == V_2 -> V_130 . V_138 ) )
return - V_121 ;
V_141 -> type = V_171 ;
V_141 -> V_172 = V_2 -> V_173 ;
F_70 ( V_2 , V_174 , V_175 , V_141 ) ;
return 0 ;
}
static int F_81 ( struct V_90 * V_90 , void * V_34 , unsigned int * V_43 )
{
struct V_1 * V_2 = ( (struct V_91 * ) V_34 ) -> V_41 -> V_2 ;
* V_43 = V_2 -> V_176 ;
return 0 ;
}
static int F_82 ( struct V_90 * V_90 , void * V_34 , unsigned int V_43 )
{
struct V_1 * V_2 = ( (struct V_91 * ) V_34 ) -> V_41 -> V_2 ;
if ( V_43 >= 4 )
return - V_121 ;
F_83 ( & V_2 -> V_177 ) ;
F_84 ( V_2 ) ;
F_85 ( V_2 , V_43 ) ;
F_86 ( & V_2 -> V_177 ) ;
return 0 ;
}
static int F_87 ( struct V_90 * V_90 , void * V_34 ,
struct V_178 * V_179 )
{
struct V_1 * V_2 = ( (struct V_91 * ) V_34 ) -> V_41 -> V_2 ;
T_1 V_92 ;
if ( F_73 ( V_137 == V_2 -> V_130 . V_138 ) )
return - V_121 ;
if ( 0 != V_179 -> V_142 )
return - V_121 ;
strcpy ( V_179 -> V_131 , L_33 ) ;
V_179 -> type = V_171 ;
V_179 -> V_180 = V_181 ;
V_179 -> V_182 = 0xffffffffUL ;
F_88 ( V_2 , V_179 ) ;
V_92 = F_6 ( V_183 ) ;
V_179 -> signal = ( V_92 & ( 1 << 5 ) ) ? 0xffff : 0x0000 ;
return 0 ;
}
static int F_89 ( struct V_90 * V_90 , void * V_34 ,
struct V_178 * V_179 )
{
struct V_1 * V_2 = ( (struct V_91 * ) V_34 ) -> V_41 -> V_2 ;
if ( V_137 == V_2 -> V_130 . V_138 )
return - V_121 ;
if ( 0 != V_179 -> V_142 )
return - V_121 ;
F_90 ( V_2 , V_179 -> V_184 , 1 ) ;
return 0 ;
}
static int F_91 ( struct V_90 * V_90 , void * V_34 , T_3 * V_119 )
{
struct V_1 * V_2 = ( (struct V_91 * ) V_34 ) -> V_41 -> V_2 ;
F_83 ( & V_2 -> V_177 ) ;
F_92 ( V_2 , * V_119 ) ;
F_86 ( & V_2 -> V_177 ) ;
return 0 ;
}
static int F_93 ( struct V_90 * V_90 )
{
struct V_185 * V_186 = F_94 ( V_90 ) ;
struct V_40 * V_41 = F_95 ( V_90 ) ;
struct V_91 * V_107 ;
struct V_187 * V_188 = NULL ;
int V_50 ;
F_14 ( 1 , L_34 , V_44 ) ;
F_83 ( & V_41 -> V_2 -> V_177 ) ;
V_188 = F_96 ( V_41 , V_189 ) ;
if ( ! V_188 ) {
F_14 ( 1 , L_35 , V_44 ) ;
F_86 ( & V_41 -> V_2 -> V_177 ) ;
return - V_190 ;
}
V_50 = V_188 -> V_191 ( V_188 ) ;
if ( V_50 != 0 ) {
F_14 ( 1 , L_36 , V_44 , V_50 ) ;
F_86 ( & V_41 -> V_2 -> V_177 ) ;
return V_50 ;
}
if ( ! V_41 -> V_2 -> V_192 && F_24 ( V_41 ) < 0 ) {
V_188 -> V_193 ( V_188 ) ;
F_86 ( & V_41 -> V_2 -> V_177 ) ;
return - V_121 ;
}
F_14 ( 1 , L_37 , F_97 ( V_186 ) ) ;
V_107 = F_98 ( sizeof( * V_107 ) , V_194 ) ;
if ( NULL == V_107 ) {
V_188 -> V_193 ( V_188 ) ;
F_86 ( & V_41 -> V_2 -> V_177 ) ;
return - V_195 ;
}
V_90 -> V_196 = V_107 ;
V_107 -> V_41 = V_41 ;
F_99 ( & V_107 -> V_152 , & V_197 ,
& V_41 -> V_66 -> V_41 , & V_41 -> V_198 ,
V_199 ,
V_200 ,
sizeof( struct V_116 ) ,
V_107 , NULL ) ;
F_49 ( V_41 -> V_2 , V_41 -> V_71 , V_41 -> V_70 ,
V_107 -> V_152 . V_115 ) ;
V_41 -> V_2 -> V_192 ++ ;
F_86 ( & V_41 -> V_2 -> V_177 ) ;
return 0 ;
}
static int F_100 ( struct V_90 * V_90 )
{
struct V_91 * V_107 = V_90 -> V_196 ;
struct V_40 * V_41 = V_107 -> V_41 ;
struct V_187 * V_188 = NULL ;
F_83 ( & V_41 -> V_2 -> V_177 ) ;
if ( V_41 -> V_78 && V_41 -> V_2 -> V_192 == 1 )
F_27 ( V_41 ) ;
F_101 ( V_107 -> V_41 ) ;
F_102 ( & V_107 -> V_152 ) ;
F_103 ( & V_107 -> V_152 ) ;
V_90 -> V_196 = NULL ;
F_104 ( V_107 ) ;
V_188 = F_96 ( V_41 , V_189 ) ;
F_105 ( ! V_188 ) ;
if ( V_188 )
V_188 -> V_193 ( V_188 ) ;
V_41 -> V_2 -> V_192 -- ;
F_86 ( & V_41 -> V_2 -> V_177 ) ;
return 0 ;
}
static T_4
F_106 ( struct V_90 * V_90 , char T_5 * V_38 , T_6 V_106 , T_7 * V_201 )
{
struct V_91 * V_107 = V_90 -> V_196 ;
struct V_40 * V_41 = V_107 -> V_41 ;
if ( ! V_41 -> V_78 )
F_26 ( V_90 , V_107 ) ;
return F_107 ( & V_107 -> V_152 , V_38 , V_106 , V_201 , 0 ,
V_90 -> V_156 & V_157 ) ;
}
static unsigned int
F_108 ( struct V_90 * V_90 , struct V_202 * V_203 )
{
struct V_91 * V_107 = V_90 -> V_196 ;
struct V_40 * V_41 = V_107 -> V_41 ;
if ( ! V_41 -> V_78 )
F_26 ( V_90 , V_107 ) ;
return F_109 ( V_90 , & V_107 -> V_152 , V_203 ) ;
}
static int
F_110 ( struct V_90 * V_90 , struct V_204 * V_205 )
{
struct V_91 * V_107 = V_90 -> V_196 ;
return F_111 ( & V_107 -> V_152 , V_205 ) ;
}
static int F_112 ( struct V_187 * V_188 )
{
struct V_1 * V_2 = V_188 -> V_2 ;
int V_50 = 0 ;
switch ( V_2 -> V_206 ) {
case V_207 :
F_113 ( V_15 , 0x00000080 ) ;
F_3 ( 1000 ) ;
F_25 ( V_15 , 0x00000080 ) ;
F_3 ( 50 ) ;
F_113 ( V_15 , 0x00000080 ) ;
F_3 ( 1000 ) ;
F_113 ( V_15 , 0x00000004 ) ;
F_3 ( 1000 ) ;
break;
default:
V_50 = - V_190 ;
}
return V_50 ;
}
static int F_114 ( struct V_187 * V_188 )
{
struct V_1 * V_2 = V_188 -> V_2 ;
int V_50 = 0 ;
switch ( V_2 -> V_206 ) {
case V_207 :
break;
default:
V_50 = - V_190 ;
}
return V_50 ;
}
static void F_115 ( struct V_40 * V_41 )
{
if ( V_41 -> V_208 ) {
if ( F_116 ( V_41 -> V_208 ) )
F_117 ( V_41 -> V_208 ) ;
else
F_118 ( V_41 -> V_208 ) ;
V_41 -> V_208 = NULL ;
}
}
static int F_119 ( struct V_40 * V_41 )
{
int V_50 ;
V_41 -> V_208 = F_120 ( V_41 -> V_2 , V_41 -> V_66 ,
& V_209 , L_38 ) ;
F_121 ( V_41 -> V_208 , V_41 ) ;
V_50 = F_122 ( V_41 -> V_208 , V_210 , - 1 ) ;
if ( V_50 < 0 ) {
F_69 ( V_211 L_39 ,
V_41 -> V_2 -> V_131 ) ;
return V_50 ;
}
F_69 ( V_211 L_40 ,
V_41 -> V_2 -> V_131 , F_97 ( V_41 -> V_208 ) ) ;
return 0 ;
}
static int F_123 ( struct V_187 * V_188 )
{
struct V_1 * V_2 = V_188 -> V_2 ;
struct V_40 * V_41 = V_2 -> V_212 ;
int V_50 ;
F_14 ( 1 , L_34 , V_44 ) ;
F_14 ( 1 , L_41 ,
V_2 -> V_206 ,
V_2 -> V_131 ,
V_2 -> V_213 ,
V_2 -> V_214 ) ;
V_50 = - V_190 ;
if ( ! ( V_2 -> V_130 . V_215 & V_189 ) )
goto V_216;
V_41 -> V_71 = 720 ;
V_41 -> V_70 = 576 ;
F_124 ( & V_41 -> V_72 ) ;
V_41 -> V_72 . V_217 = V_218 ;
V_209 . V_219 = V_2 -> V_74 ;
if ( V_2 -> V_74 & V_220 ) {
V_41 -> V_70 = 480 ;
} else {
V_41 -> V_70 = 576 ;
}
F_69 ( L_42 ,
V_2 -> V_131 ) ;
F_1 ( V_41 -> V_2 ) ;
F_24 ( V_41 ) ;
F_119 ( V_41 ) ;
F_92 ( V_2 , V_2 -> V_74 ) ;
F_85 ( V_2 , 0 ) ;
return 0 ;
V_216:
return V_50 ;
}
static int F_125 ( struct V_187 * V_188 )
{
F_115 ( V_188 -> V_2 -> V_212 ) ;
return 0 ;
}
static int T_8 F_126 ( void )
{
F_69 ( V_211 L_43 ,
V_221 ) ;
return F_127 ( & V_222 ) ;
}
static void T_9 F_128 ( void )
{
F_129 ( & V_222 ) ;
}
