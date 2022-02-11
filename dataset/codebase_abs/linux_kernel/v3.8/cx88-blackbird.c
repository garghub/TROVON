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
F_23 ( & V_41 -> V_72 , V_41 -> V_2 -> V_73 & V_74 ) ;
F_24 ( & V_41 -> V_72 ) ;
}
static int F_25 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_2 ;
int V_75 ;
int V_25 ;
F_14 ( 1 , L_19 ) ;
V_25 = F_15 ( V_41 , V_76 , 0 , 0 ) ;
if ( V_25 < 0 ) {
V_41 -> V_77 = 0 ;
F_2 ( V_78 , 0 ) ;
F_2 ( V_78 , 1 ) ;
V_25 = F_17 ( V_41 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_16 ( V_41 ) ;
if ( V_25 < 0 )
return - 1 ;
V_41 -> V_45 = V_25 ;
V_25 = F_15 ( V_41 , V_76 , 0 , 0 ) ;
if ( V_25 < 0 ) {
F_14 ( 0 , L_20 ) ;
return - 1 ;
}
V_25 = F_15 ( V_41 , V_79 , 0 , 1 , & V_75 ) ;
if ( V_25 < 0 ) {
F_14 ( 0 , L_21 ) ;
return - 1 ;
}
F_14 ( 0 , L_22 , V_75 ) ;
}
F_2 ( V_80 , 0x88 ) ;
F_26 ( V_81 , 0x100 ) ;
F_2 ( V_82 , 0x84A00 ) ;
F_26 ( V_83 , 0x0008 ) ;
F_22 ( V_41 ) ;
F_15 ( V_41 , V_84 , 2 , 0 ,
V_85 ,
V_86
) ;
F_15 ( V_41 , V_87 , 12 , 0 ,
V_88 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) ;
return 0 ;
}
static int F_27 ( struct V_89 * V_89 , void * V_34 )
{
struct V_40 * V_41 = ( (struct V_90 * ) V_34 ) -> V_41 ;
struct V_1 * V_2 = V_41 -> V_2 ;
T_1 V_91 ;
int V_43 ;
int V_92 = - 1 ;
int V_93 = 0 ;
for ( V_43 = 0 ; ( V_43 < 10 ) && ( V_43 < ( V_92 + 4 ) ) ; V_43 ++ ) {
V_91 = F_6 ( V_94 ) ;
F_14 ( 1 , L_23 , V_43 , V_91 ) ;
if ( ( V_91 & 0x0F ) != V_93 ) {
V_93 = V_91 & 0x0F ;
V_92 = V_43 ;
}
F_18 ( 100 ) ;
}
F_26 ( V_95 , ( 1 << 6 ) ) ;
F_15 ( V_41 , V_96 , 0 , 0 ) ;
F_15 ( V_41 , V_97 , 0 , 0 ) ;
F_28 ( & V_41 -> V_72 , 1 ) ;
F_15 ( V_41 , V_98 , 2 , 0 ,
V_99 ,
V_100
) ;
V_41 -> V_77 = 1 ;
return 0 ;
}
static int F_29 ( struct V_40 * V_41 )
{
F_15 ( V_41 , V_101 , 3 , 0 ,
V_102 ,
V_99 ,
V_100
) ;
F_28 ( & V_41 -> V_72 , 0 ) ;
V_41 -> V_77 = 0 ;
return 0 ;
}
static int F_30 ( struct V_103 * V_104 ,
unsigned int * V_105 , unsigned int * V_67 )
{
struct V_90 * V_106 = V_104 -> V_107 ;
V_106 -> V_41 -> V_108 = 188 * 4 ;
V_106 -> V_41 -> V_109 = V_110 ;
* V_67 = V_106 -> V_41 -> V_108 * V_106 -> V_41 -> V_109 ;
* V_105 = V_106 -> V_41 -> V_109 ;
return 0 ;
}
static int
F_31 ( struct V_103 * V_104 , struct V_111 * V_112 ,
enum V_113 V_114 )
{
struct V_90 * V_106 = V_104 -> V_107 ;
return F_32 ( V_104 , V_106 -> V_41 , (struct V_115 * ) V_112 , V_114 ) ;
}
static void
F_33 ( struct V_103 * V_104 , struct V_111 * V_112 )
{
struct V_90 * V_106 = V_104 -> V_107 ;
F_34 ( V_106 -> V_41 , (struct V_115 * ) V_112 ) ;
}
static void
F_35 ( struct V_103 * V_104 , struct V_111 * V_112 )
{
F_36 ( V_104 , (struct V_115 * ) V_112 ) ;
}
static int F_37 ( struct V_89 * V_89 , void * V_34 ,
struct V_116 * V_117 )
{
struct V_40 * V_41 = ( (struct V_90 * ) V_34 ) -> V_41 ;
struct V_1 * V_2 = V_41 -> V_2 ;
strcpy ( V_117 -> V_118 , L_24 ) ;
sprintf ( V_117 -> V_119 , L_25 , F_38 ( V_41 -> V_66 ) ) ;
F_39 ( V_89 , V_2 , V_117 ) ;
return 0 ;
}
static int F_40 ( struct V_89 * V_89 , void * V_34 ,
struct V_120 * V_121 )
{
if ( V_121 -> V_122 != 0 )
return - V_123 ;
F_41 ( V_121 -> V_124 , L_26 , sizeof( V_121 -> V_124 ) ) ;
V_121 -> V_125 = V_126 ;
V_121 -> V_127 = V_128 ;
return 0 ;
}
static int F_42 ( struct V_89 * V_89 , void * V_34 ,
struct V_129 * V_121 )
{
struct V_90 * V_106 = V_34 ;
struct V_40 * V_41 = V_106 -> V_41 ;
V_121 -> V_130 . V_131 . V_125 = V_126 ;
V_121 -> V_130 . V_131 . V_132 = 0 ;
V_121 -> V_130 . V_131 . V_133 = 188 * 4 * V_110 ;
V_121 -> V_130 . V_131 . V_134 = V_135 ;
V_121 -> V_130 . V_131 . V_71 = V_41 -> V_71 ;
V_121 -> V_130 . V_131 . V_70 = V_41 -> V_70 ;
V_121 -> V_130 . V_131 . V_114 = V_106 -> V_136 . V_114 ;
F_14 ( 1 , L_27 ,
V_41 -> V_71 , V_41 -> V_70 , V_106 -> V_136 . V_114 ) ;
return 0 ;
}
static int F_43 ( struct V_89 * V_89 , void * V_34 ,
struct V_129 * V_121 )
{
struct V_90 * V_106 = V_34 ;
struct V_40 * V_41 = V_106 -> V_41 ;
V_121 -> V_130 . V_131 . V_125 = V_126 ;
V_121 -> V_130 . V_131 . V_132 = 0 ;
V_121 -> V_130 . V_131 . V_133 = 188 * 4 * V_110 ;
V_121 -> V_130 . V_131 . V_134 = V_135 ;
F_14 ( 1 , L_28 ,
V_41 -> V_71 , V_41 -> V_70 , V_106 -> V_136 . V_114 ) ;
return 0 ;
}
static int F_44 ( struct V_89 * V_89 , void * V_34 ,
struct V_129 * V_121 )
{
struct V_90 * V_106 = V_34 ;
struct V_40 * V_41 = V_106 -> V_41 ;
struct V_1 * V_2 = V_41 -> V_2 ;
V_121 -> V_130 . V_131 . V_125 = V_126 ;
V_121 -> V_130 . V_131 . V_132 = 0 ;
V_121 -> V_130 . V_131 . V_133 = 188 * 4 * V_110 ;
V_121 -> V_130 . V_131 . V_134 = V_135 ;
V_41 -> V_71 = V_121 -> V_130 . V_131 . V_71 ;
V_41 -> V_70 = V_121 -> V_130 . V_131 . V_70 ;
V_106 -> V_136 . V_114 = V_121 -> V_130 . V_131 . V_114 ;
F_45 ( V_2 , V_121 -> V_130 . V_131 . V_71 , V_121 -> V_130 . V_131 . V_70 , V_121 -> V_130 . V_131 . V_114 ) ;
F_15 ( V_41 , V_69 , 2 , 0 ,
V_121 -> V_130 . V_131 . V_70 , V_121 -> V_130 . V_131 . V_71 ) ;
F_14 ( 1 , L_29 ,
V_121 -> V_130 . V_131 . V_71 , V_121 -> V_130 . V_131 . V_70 , V_121 -> V_130 . V_131 . V_114 ) ;
return 0 ;
}
static int F_46 ( struct V_89 * V_89 , void * V_34 , struct V_137 * V_138 )
{
struct V_90 * V_106 = V_34 ;
return ( F_47 ( & V_106 -> V_136 , V_138 ) ) ;
}
static int F_48 ( struct V_89 * V_89 , void * V_34 , struct V_139 * V_138 )
{
struct V_90 * V_106 = V_34 ;
return ( F_49 ( & V_106 -> V_136 , V_138 ) ) ;
}
static int F_50 ( struct V_89 * V_89 , void * V_34 , struct V_139 * V_138 )
{
struct V_90 * V_106 = V_34 ;
return ( F_51 ( & V_106 -> V_136 , V_138 ) ) ;
}
static int F_52 ( struct V_89 * V_89 , void * V_34 , struct V_139 * V_138 )
{
struct V_90 * V_106 = V_34 ;
return ( F_53 ( & V_106 -> V_136 , V_138 ,
V_89 -> V_140 & V_141 ) ) ;
}
static int F_54 ( struct V_89 * V_89 , void * V_34 , enum V_142 V_43 )
{
struct V_90 * V_106 = V_34 ;
struct V_40 * V_41 = V_106 -> V_41 ;
if ( ! V_41 -> V_77 )
F_27 ( V_89 , V_106 ) ;
return F_55 ( & V_106 -> V_136 ) ;
}
static int F_56 ( struct V_89 * V_89 , void * V_34 , enum V_142 V_43 )
{
struct V_90 * V_106 = V_34 ;
struct V_40 * V_41 = V_106 -> V_41 ;
if ( V_41 -> V_77 )
F_29 ( V_41 ) ;
return F_57 ( & V_106 -> V_136 ) ;
}
static int F_58 ( struct V_89 * V_89 , void * V_34 ,
struct V_143 * V_121 )
{
struct V_90 * V_106 = V_34 ;
struct V_40 * V_41 = V_106 -> V_41 ;
struct V_1 * V_2 = V_41 -> V_2 ;
if ( F_59 ( V_144 == V_2 -> V_145 . V_146 ) )
return - V_123 ;
if ( F_59 ( V_121 -> V_147 != 0 ) )
return - V_123 ;
if ( V_41 -> V_77 )
F_29 ( V_41 ) ;
F_60 ( V_2 , V_121 ) ;
F_25 ( V_41 ) ;
F_45 ( V_41 -> V_2 , V_41 -> V_71 , V_41 -> V_70 ,
V_106 -> V_136 . V_114 ) ;
return 0 ;
}
static int F_61 ( struct V_89 * V_89 , void * V_34 )
{
struct V_40 * V_41 = ( (struct V_90 * ) V_34 ) -> V_41 ;
struct V_1 * V_2 = V_41 -> V_2 ;
char V_148 [ 32 + 2 ] ;
snprintf ( V_148 , sizeof( V_148 ) , L_30 , V_2 -> V_148 ) ;
F_62 ( V_2 , V_2 , V_149 ) ;
F_63 ( & V_41 -> V_72 . V_150 , V_148 ) ;
return 0 ;
}
static int F_64 ( struct V_89 * V_89 , void * V_34 ,
struct V_151 * V_43 )
{
struct V_1 * V_2 = ( (struct V_90 * ) V_34 ) -> V_41 -> V_2 ;
return F_65 ( V_2 , V_43 ) ;
}
static int F_66 ( struct V_89 * V_89 , void * V_34 ,
struct V_143 * V_121 )
{
struct V_90 * V_106 = V_34 ;
struct V_1 * V_2 = V_106 -> V_41 -> V_2 ;
if ( F_59 ( V_144 == V_2 -> V_145 . V_146 ) )
return - V_123 ;
if ( F_59 ( V_121 -> V_147 != 0 ) )
return - V_123 ;
V_121 -> V_152 = V_2 -> V_153 ;
F_62 ( V_2 , V_147 , V_154 , V_121 ) ;
return 0 ;
}
static int F_67 ( struct V_89 * V_89 , void * V_34 , unsigned int * V_43 )
{
struct V_1 * V_2 = ( (struct V_90 * ) V_34 ) -> V_41 -> V_2 ;
* V_43 = V_2 -> V_155 ;
return 0 ;
}
static int F_68 ( struct V_89 * V_89 , void * V_34 , unsigned int V_43 )
{
struct V_1 * V_2 = ( (struct V_90 * ) V_34 ) -> V_41 -> V_2 ;
if ( V_43 >= 4 )
return - V_123 ;
if ( 0 == F_69 ( V_43 ) . type )
return - V_123 ;
F_70 ( & V_2 -> V_156 ) ;
F_71 ( V_2 ) ;
F_72 ( V_2 , V_43 ) ;
F_73 ( & V_2 -> V_156 ) ;
return 0 ;
}
static int F_74 ( struct V_89 * V_89 , void * V_34 ,
struct V_157 * V_158 )
{
struct V_1 * V_2 = ( (struct V_90 * ) V_34 ) -> V_41 -> V_2 ;
T_1 V_91 ;
if ( F_59 ( V_144 == V_2 -> V_145 . V_146 ) )
return - V_123 ;
if ( 0 != V_158 -> V_122 )
return - V_123 ;
strcpy ( V_158 -> V_148 , L_31 ) ;
V_158 -> V_159 = V_160 ;
V_158 -> V_161 = 0xffffffffUL ;
F_62 ( V_2 , V_147 , V_162 , V_158 ) ;
F_75 ( V_2 , V_158 ) ;
V_91 = F_6 ( V_163 ) ;
V_158 -> signal = ( V_91 & ( 1 << 5 ) ) ? 0xffff : 0x0000 ;
return 0 ;
}
static int F_76 ( struct V_89 * V_89 , void * V_34 ,
struct V_157 * V_158 )
{
struct V_1 * V_2 = ( (struct V_90 * ) V_34 ) -> V_41 -> V_2 ;
if ( V_144 == V_2 -> V_145 . V_146 )
return - V_123 ;
if ( 0 != V_158 -> V_122 )
return - V_123 ;
F_77 ( V_2 , V_158 -> V_164 , 1 ) ;
return 0 ;
}
static int F_78 ( struct V_89 * V_89 , void * V_34 , T_3 * V_73 )
{
struct V_1 * V_2 = ( (struct V_90 * ) V_34 ) -> V_41 -> V_2 ;
* V_73 = V_2 -> V_73 ;
return 0 ;
}
static int F_79 ( struct V_89 * V_89 , void * V_34 , T_3 * V_165 )
{
struct V_1 * V_2 = ( (struct V_90 * ) V_34 ) -> V_41 -> V_2 ;
F_70 ( & V_2 -> V_156 ) ;
F_80 ( V_2 , * V_165 ) ;
F_73 ( & V_2 -> V_156 ) ;
return 0 ;
}
static int F_81 ( struct V_89 * V_89 )
{
struct V_166 * V_167 = F_82 ( V_89 ) ;
struct V_40 * V_41 = F_83 ( V_89 ) ;
struct V_90 * V_106 ;
struct V_168 * V_169 = NULL ;
int V_50 ;
F_14 ( 1 , L_32 , V_44 ) ;
F_70 ( & V_41 -> V_2 -> V_156 ) ;
V_169 = F_84 ( V_41 , V_170 ) ;
if ( ! V_169 ) {
F_14 ( 1 , L_33 , V_44 ) ;
F_73 ( & V_41 -> V_2 -> V_156 ) ;
return - V_171 ;
}
V_50 = V_169 -> V_172 ( V_169 ) ;
if ( V_50 != 0 ) {
F_14 ( 1 , L_34 , V_44 , V_50 ) ;
F_73 ( & V_41 -> V_2 -> V_156 ) ;
return V_50 ;
}
if ( ! V_41 -> V_2 -> V_173 && F_25 ( V_41 ) < 0 ) {
V_169 -> V_174 ( V_169 ) ;
F_73 ( & V_41 -> V_2 -> V_156 ) ;
return - V_123 ;
}
F_14 ( 1 , L_35 , F_85 ( V_167 ) ) ;
V_106 = F_86 ( sizeof( * V_106 ) , V_175 ) ;
if ( NULL == V_106 ) {
V_169 -> V_174 ( V_169 ) ;
F_73 ( & V_41 -> V_2 -> V_156 ) ;
return - V_176 ;
}
F_87 ( & V_106 -> V_106 , V_167 ) ;
V_89 -> V_177 = V_106 ;
V_106 -> V_41 = V_41 ;
F_88 ( & V_106 -> V_136 , & V_178 ,
& V_41 -> V_66 -> V_41 , & V_41 -> V_179 ,
V_180 ,
V_181 ,
sizeof( struct V_115 ) ,
V_106 , NULL ) ;
F_45 ( V_41 -> V_2 , V_41 -> V_71 , V_41 -> V_70 ,
V_106 -> V_136 . V_114 ) ;
V_41 -> V_2 -> V_173 ++ ;
F_73 ( & V_41 -> V_2 -> V_156 ) ;
F_89 ( & V_106 -> V_106 ) ;
return 0 ;
}
static int F_90 ( struct V_89 * V_89 )
{
struct V_90 * V_106 = V_89 -> V_177 ;
struct V_40 * V_41 = V_106 -> V_41 ;
struct V_168 * V_169 = NULL ;
F_70 ( & V_41 -> V_2 -> V_156 ) ;
if ( V_41 -> V_77 && V_41 -> V_2 -> V_173 == 1 )
F_29 ( V_41 ) ;
F_91 ( V_106 -> V_41 ) ;
F_92 ( & V_106 -> V_136 ) ;
F_93 ( & V_106 -> V_136 ) ;
F_94 ( & V_106 -> V_106 ) ;
F_95 ( & V_106 -> V_106 ) ;
V_89 -> V_177 = NULL ;
F_96 ( V_106 ) ;
V_169 = F_84 ( V_41 , V_170 ) ;
F_97 ( ! V_169 ) ;
if ( V_169 )
V_169 -> V_174 ( V_169 ) ;
V_41 -> V_2 -> V_173 -- ;
F_73 ( & V_41 -> V_2 -> V_156 ) ;
return 0 ;
}
static T_4
F_98 ( struct V_89 * V_89 , char T_5 * V_38 , T_6 V_105 , T_7 * V_182 )
{
struct V_90 * V_106 = V_89 -> V_177 ;
struct V_40 * V_41 = V_106 -> V_41 ;
if ( ! V_41 -> V_77 )
F_27 ( V_89 , V_106 ) ;
return F_99 ( & V_106 -> V_136 , V_38 , V_105 , V_182 , 0 ,
V_89 -> V_140 & V_141 ) ;
}
static unsigned int
F_100 ( struct V_89 * V_89 , struct V_183 * V_184 )
{
unsigned long V_185 = F_101 ( V_184 ) ;
struct V_90 * V_106 = V_89 -> V_177 ;
struct V_40 * V_41 = V_106 -> V_41 ;
if ( ! V_41 -> V_77 && ( V_185 & ( V_186 | V_187 ) ) )
F_27 ( V_89 , V_106 ) ;
return F_102 ( V_89 , V_184 ) | F_103 ( V_89 , & V_106 -> V_136 , V_184 ) ;
}
static int
F_104 ( struct V_89 * V_89 , struct V_188 * V_189 )
{
struct V_90 * V_106 = V_89 -> V_177 ;
return F_105 ( & V_106 -> V_136 , V_189 ) ;
}
static int F_106 ( struct V_168 * V_169 )
{
struct V_1 * V_2 = V_169 -> V_2 ;
int V_50 = 0 ;
switch ( V_2 -> V_190 ) {
case V_191 :
F_107 ( V_15 , 0x00000080 ) ;
F_3 ( 1000 ) ;
F_26 ( V_15 , 0x00000080 ) ;
F_3 ( 50 ) ;
F_107 ( V_15 , 0x00000080 ) ;
F_3 ( 1000 ) ;
F_107 ( V_15 , 0x00000004 ) ;
F_3 ( 1000 ) ;
break;
default:
V_50 = - V_171 ;
}
return V_50 ;
}
static int F_108 ( struct V_168 * V_169 )
{
struct V_1 * V_2 = V_169 -> V_2 ;
int V_50 = 0 ;
switch ( V_2 -> V_190 ) {
case V_191 :
break;
default:
V_50 = - V_171 ;
}
return V_50 ;
}
static void F_109 ( struct V_40 * V_41 )
{
if ( V_41 -> V_192 ) {
if ( F_110 ( V_41 -> V_192 ) )
F_111 ( V_41 -> V_192 ) ;
else
F_112 ( V_41 -> V_192 ) ;
V_41 -> V_192 = NULL ;
}
}
static int F_113 ( struct V_40 * V_41 )
{
int V_50 ;
V_41 -> V_192 = F_114 ( V_41 -> V_2 , V_41 -> V_66 ,
& V_193 , L_36 ) ;
V_41 -> V_192 -> V_194 = & V_41 -> V_72 . V_150 ;
F_115 ( V_41 -> V_192 , V_41 ) ;
V_50 = F_116 ( V_41 -> V_192 , V_195 , - 1 ) ;
if ( V_50 < 0 ) {
F_117 ( V_196 L_37 ,
V_41 -> V_2 -> V_148 ) ;
return V_50 ;
}
F_117 ( V_196 L_38 ,
V_41 -> V_2 -> V_148 , F_85 ( V_41 -> V_192 ) ) ;
return 0 ;
}
static int F_118 ( struct V_168 * V_169 )
{
struct V_1 * V_2 = V_169 -> V_2 ;
struct V_40 * V_41 = V_2 -> V_197 ;
int V_50 ;
F_14 ( 1 , L_32 , V_44 ) ;
F_14 ( 1 , L_39 ,
V_2 -> V_190 ,
V_2 -> V_148 ,
V_2 -> V_198 ,
V_2 -> V_199 ) ;
V_50 = - V_171 ;
if ( ! ( V_2 -> V_145 . V_200 & V_170 ) )
goto V_201;
V_41 -> V_71 = 720 ;
if ( V_2 -> V_73 & V_202 ) {
V_41 -> V_70 = 480 ;
} else {
V_41 -> V_70 = 576 ;
}
V_41 -> V_72 . V_203 = V_204 ;
V_41 -> V_72 . V_71 = V_41 -> V_71 ;
V_41 -> V_72 . V_70 = V_41 -> V_70 ;
V_41 -> V_72 . V_205 = F_13 ;
V_41 -> V_72 . V_34 = V_41 ;
V_50 = F_119 ( & V_41 -> V_72 , 36 ) ;
if ( V_50 )
goto V_201;
F_120 ( & V_41 -> V_72 . V_150 , & V_2 -> V_206 , NULL ) ;
F_117 ( L_40 ,
V_2 -> V_148 ) ;
F_1 ( V_41 -> V_2 ) ;
F_25 ( V_41 ) ;
F_80 ( V_2 , V_2 -> V_73 ) ;
F_72 ( V_2 , 0 ) ;
F_23 ( & V_41 -> V_72 , V_41 -> V_70 == 576 ) ;
F_24 ( & V_41 -> V_72 ) ;
F_113 ( V_41 ) ;
return 0 ;
V_201:
return V_50 ;
}
static int F_121 ( struct V_168 * V_169 )
{
struct V_1 * V_2 = V_169 -> V_2 ;
struct V_40 * V_41 = V_2 -> V_197 ;
F_109 ( V_169 -> V_2 -> V_197 ) ;
F_122 ( & V_41 -> V_72 . V_150 ) ;
return 0 ;
}
static int T_8 F_123 ( void )
{
F_117 ( V_196 L_41 ,
V_207 ) ;
return F_124 ( & V_208 ) ;
}
static void T_9 F_125 ( void )
{
F_126 ( & V_208 ) ;
}
