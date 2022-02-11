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
return - V_46 ;
}
F_10 ( V_41 -> V_2 , V_41 -> V_45 , & V_42 ) ;
if ( V_42 ) {
F_14 ( 0 , L_3 , V_42 ) ;
return - V_46 ;
}
V_42 |= 1 ;
F_8 ( V_41 -> V_2 , V_41 -> V_45 , V_42 ) ;
F_8 ( V_41 -> V_2 , V_41 -> V_45 + 1 , V_35 ) ;
F_8 ( V_41 -> V_2 , V_41 -> V_45 + 3 , V_47 ) ;
for ( V_43 = 0 ; V_43 < V_36 ; V_43 ++ ) {
F_8 ( V_41 -> V_2 , V_41 -> V_45 + 4 + V_43 , V_38 [ V_43 ] ) ;
F_14 ( 1 , L_4 , V_43 , V_38 [ V_43 ] ) ;
}
for (; V_43 < V_39 ; V_43 ++ )
F_8 ( V_41 -> V_2 , V_41 -> V_45 + 4 + V_43 , 0 ) ;
V_42 |= 3 ;
F_8 ( V_41 -> V_2 , V_41 -> V_45 , V_42 ) ;
V_11 = V_12 + F_5 ( 1000 ) ;
for (; ; ) {
F_10 ( V_41 -> V_2 , V_41 -> V_45 , & V_42 ) ;
if ( 0 != ( V_42 & 4 ) )
break;
if ( F_7 ( V_12 , V_11 ) ) {
F_14 ( 0 , L_5 , V_35 ) ;
return - V_46 ;
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
T_1 V_48 , T_1 V_49 , ... )
{
T_1 V_38 [ V_39 ] ;
T_2 V_50 ;
int V_43 , V_51 ;
va_start ( V_50 , V_49 ) ;
for ( V_43 = 0 ; V_43 < V_48 ; V_43 ++ ) {
V_38 [ V_43 ] = va_arg ( V_50 , int ) ;
}
V_51 = F_13 ( V_41 , V_35 , V_48 , V_49 , V_38 ) ;
for ( V_43 = 0 ; V_43 < V_49 ; V_43 ++ ) {
int * V_52 = va_arg ( V_50 , int * ) ;
* V_52 = V_38 [ V_43 ] ;
}
va_end ( V_50 ) ;
return V_51 ;
}
static int F_16 ( struct V_40 * V_41 )
{
T_1 V_53 [ 4 ] = { 0x12345678 , 0x34567812 , 0x56781234 , 0x78123456 } ;
int V_54 = 0 ;
T_1 V_17 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_55 ; V_43 ++ ) {
F_10 ( V_41 -> V_2 , V_43 , & V_17 ) ;
if ( V_17 == V_53 [ V_54 ] )
V_54 ++ ;
else
V_54 = 0 ;
if ( 4 == V_54 ) {
F_14 ( 1 , L_8 ) ;
return V_43 + 1 ;
}
}
F_14 ( 0 , L_9 ) ;
return - V_46 ;
}
static int F_17 ( struct V_40 * V_41 )
{
static const unsigned char V_56 [ 8 ] = {
0xa7 , 0x0d , 0x00 , 0x00 , 0x66 , 0xbb , 0x55 , 0xaa
} ;
const struct V_57 * V_57 ;
int V_43 , V_25 = 0 ;
T_1 V_17 = 0 ;
T_1 V_58 = 0 ;
T_3 * V_59 ;
V_25 = F_11 ( V_41 -> V_2 , V_60 , 0xFFFFFFED ) ;
V_25 |= F_11 ( V_41 -> V_2 , V_61 , V_62 ) ;
V_25 |= F_11 ( V_41 -> V_2 , V_63 , 0x80000640 ) ;
V_25 |= F_11 ( V_41 -> V_2 , V_64 , 0x1A ) ;
F_18 ( 1 ) ;
V_25 |= F_11 ( V_41 -> V_2 , V_65 , 0 ) ;
if ( V_25 < 0 )
F_14 ( 0 , L_10 ) ;
V_25 = F_19 ( & V_57 , V_66 ,
& V_41 -> V_67 -> V_41 ) ;
if ( V_25 != 0 ) {
F_20 ( L_11 ,
V_66 ) ;
F_20 ( L_12 ) ;
return - V_46 ;
}
if ( V_57 -> V_68 != V_55 ) {
F_20 ( L_13 ,
V_57 -> V_68 , V_55 ) ;
F_21 ( V_57 ) ;
return - V_69 ;
}
if ( 0 != memcmp ( V_57 -> V_38 , V_56 , 8 ) ) {
F_20 ( L_14 ) ;
F_21 ( V_57 ) ;
return - V_69 ;
}
F_14 ( 1 , L_15 ) ;
V_59 = ( T_3 * ) V_57 -> V_38 ;
for ( V_43 = 0 ; V_43 < ( V_57 -> V_68 >> 2 ) ; V_43 ++ ) {
V_17 = F_22 ( * V_59 ) ;
V_58 += ~ V_17 ;
F_8 ( V_41 -> V_2 , V_43 , V_17 ) ;
V_59 ++ ;
}
for ( V_43 -- ; V_43 >= 0 ; V_43 -- ) {
F_10 ( V_41 -> V_2 , V_43 , & V_17 ) ;
V_58 -= ~ V_17 ;
}
F_21 ( V_57 ) ;
if ( V_58 ) {
F_20 ( L_16 ) ;
return - V_46 ;
}
F_14 ( 0 , L_17 ) ;
V_25 |= F_11 ( V_41 -> V_2 , V_61 , V_62 ) ;
V_25 |= F_12 ( V_41 -> V_2 , V_70 , & V_17 ) ;
V_25 |= F_11 ( V_41 -> V_2 , V_70 , V_17 & 0xFFFFFFFE ) ;
F_18 ( 1 ) ;
V_25 |= F_12 ( V_41 -> V_2 , V_60 , & V_17 ) ;
V_25 |= F_11 ( V_41 -> V_2 , V_60 , V_17 & 0xFFFFFFE8 ) ;
if ( V_25 < 0 )
F_14 ( 0 , L_10 ) ;
return 0 ;
}
static void F_23 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_2 ;
F_15 ( V_41 , V_71 , 2 , 0 ,
V_2 -> V_72 , V_2 -> V_73 ) ;
V_41 -> V_74 . V_73 = V_2 -> V_73 ;
V_41 -> V_74 . V_72 = V_2 -> V_72 ;
F_24 ( & V_41 -> V_74 , V_41 -> V_2 -> V_75 & V_76 ) ;
F_25 ( & V_41 -> V_74 ) ;
}
static int F_26 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_2 ;
int V_77 ;
int V_25 ;
F_14 ( 1 , L_18 ) ;
V_25 = F_15 ( V_41 , V_78 , 0 , 0 ) ;
if ( V_25 < 0 ) {
F_2 ( V_79 , 0 ) ;
F_2 ( V_79 , 1 ) ;
V_25 = F_17 ( V_41 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_16 ( V_41 ) ;
if ( V_25 < 0 )
return - 1 ;
V_41 -> V_45 = V_25 ;
V_25 = F_15 ( V_41 , V_78 , 0 , 0 ) ;
if ( V_25 < 0 ) {
F_14 ( 0 , L_19 ) ;
return - 1 ;
}
V_25 = F_15 ( V_41 , V_80 , 0 , 1 , & V_77 ) ;
if ( V_25 < 0 ) {
F_14 ( 0 , L_20 ) ;
return - 1 ;
}
F_14 ( 0 , L_21 , V_77 ) ;
}
F_2 ( V_81 , 0x88 ) ;
F_27 ( V_82 , 0x100 ) ;
F_2 ( V_83 , 0x84A00 ) ;
F_27 ( V_84 , 0x0008 ) ;
F_23 ( V_41 ) ;
F_15 ( V_41 , V_85 , 2 , 0 ,
V_86 ,
V_87
) ;
F_15 ( V_41 , V_88 , 12 , 0 ,
V_89 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) ;
return 0 ;
}
static int F_28 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_2 ;
T_1 V_90 ;
int V_43 ;
int V_91 = - 1 ;
int V_92 = 0 ;
for ( V_43 = 0 ; ( V_43 < 10 ) && ( V_43 < ( V_91 + 4 ) ) ; V_43 ++ ) {
V_90 = F_6 ( V_93 ) ;
F_14 ( 1 , L_22 , V_43 , V_90 ) ;
if ( ( V_90 & 0x0F ) != V_92 ) {
V_92 = V_90 & 0x0F ;
V_91 = V_43 ;
}
F_18 ( 100 ) ;
}
F_27 ( V_94 , ( 1 << 6 ) ) ;
F_15 ( V_41 , V_95 , 0 , 0 ) ;
F_15 ( V_41 , V_96 , 0 , 0 ) ;
F_29 ( & V_41 -> V_74 , 1 ) ;
F_15 ( V_41 , V_97 , 2 , 0 ,
V_98 ,
V_99
) ;
return 0 ;
}
static int F_30 ( struct V_40 * V_41 )
{
F_15 ( V_41 , V_100 , 3 , 0 ,
V_101 ,
V_98 ,
V_99
) ;
F_29 ( & V_41 -> V_74 , 0 ) ;
return 0 ;
}
static int F_31 ( struct V_102 * V_103 , const struct V_104 * V_105 ,
unsigned int * V_106 , unsigned int * V_107 ,
unsigned int V_108 [] , void * V_109 [] )
{
struct V_40 * V_41 = V_103 -> V_110 ;
* V_107 = 1 ;
V_41 -> V_111 = 188 * 4 ;
V_41 -> V_112 = 32 ;
V_108 [ 0 ] = V_41 -> V_111 * V_41 -> V_112 ;
V_109 [ 0 ] = V_41 -> V_113 ;
return 0 ;
}
static int F_32 ( struct V_114 * V_115 )
{
struct V_40 * V_41 = V_115 -> V_102 -> V_110 ;
struct V_116 * V_117 = F_33 ( V_115 , struct V_116 , V_115 ) ;
return F_34 ( V_115 -> V_102 , V_41 , V_117 ) ;
}
static void F_35 ( struct V_114 * V_115 )
{
struct V_40 * V_41 = V_115 -> V_102 -> V_110 ;
struct V_116 * V_117 = F_33 ( V_115 , struct V_116 , V_115 ) ;
struct V_118 * V_119 = & V_117 -> V_119 ;
if ( V_119 -> V_120 )
F_36 ( V_41 -> V_67 , V_119 -> V_68 , V_119 -> V_120 , V_119 -> V_121 ) ;
memset ( V_119 , 0 , sizeof( * V_119 ) ) ;
}
static void F_37 ( struct V_114 * V_115 )
{
struct V_40 * V_41 = V_115 -> V_102 -> V_110 ;
struct V_116 * V_117 = F_33 ( V_115 , struct V_116 , V_115 ) ;
F_38 ( V_41 , V_117 ) ;
}
static int F_39 ( struct V_102 * V_103 , unsigned int V_122 )
{
struct V_40 * V_41 = V_103 -> V_110 ;
struct V_123 * V_124 = & V_41 -> V_125 ;
struct V_126 * V_127 ;
struct V_116 * V_117 ;
unsigned long V_128 ;
int V_51 ;
V_127 = F_40 ( V_41 , V_129 ) ;
if ( ! V_127 ) {
F_14 ( 1 , L_23 , V_44 ) ;
V_51 = - V_130 ;
goto V_131;
}
V_51 = V_127 -> V_132 ( V_127 ) ;
if ( V_51 != 0 ) {
F_14 ( 1 , L_24 , V_44 , V_51 ) ;
goto V_131;
}
if ( F_26 ( V_41 ) < 0 ) {
V_127 -> V_133 ( V_127 ) ;
V_51 = - V_69 ;
goto V_131;
}
V_51 = F_28 ( V_41 ) ;
if ( V_51 == 0 ) {
V_117 = F_41 ( V_124 -> V_134 . V_135 , struct V_116 , V_136 ) ;
F_42 ( V_41 , V_124 , V_117 ) ;
return 0 ;
}
V_131:
F_43 ( & V_41 -> V_137 , V_128 ) ;
while ( ! F_44 ( & V_124 -> V_134 ) ) {
struct V_116 * V_117 = F_41 ( V_124 -> V_134 . V_135 ,
struct V_116 , V_136 ) ;
F_45 ( & V_117 -> V_136 ) ;
F_46 ( & V_117 -> V_115 , V_138 ) ;
}
F_47 ( & V_41 -> V_137 , V_128 ) ;
return V_51 ;
}
static void F_48 ( struct V_102 * V_103 )
{
struct V_40 * V_41 = V_103 -> V_110 ;
struct V_123 * V_124 = & V_41 -> V_125 ;
struct V_126 * V_127 = NULL ;
unsigned long V_128 ;
F_49 ( V_41 ) ;
F_30 ( V_41 ) ;
V_127 = F_40 ( V_41 , V_129 ) ;
F_50 ( ! V_127 ) ;
if ( V_127 )
V_127 -> V_133 ( V_127 ) ;
F_43 ( & V_41 -> V_137 , V_128 ) ;
while ( ! F_44 ( & V_124 -> V_134 ) ) {
struct V_116 * V_117 = F_41 ( V_124 -> V_134 . V_135 ,
struct V_116 , V_136 ) ;
F_45 ( & V_117 -> V_136 ) ;
F_46 ( & V_117 -> V_115 , V_139 ) ;
}
F_47 ( & V_41 -> V_137 , V_128 ) ;
}
static int F_51 ( struct V_140 * V_140 , void * V_34 ,
struct V_141 * V_142 )
{
struct V_40 * V_41 = F_52 ( V_140 ) ;
struct V_1 * V_2 = V_41 -> V_2 ;
strcpy ( V_142 -> V_143 , L_25 ) ;
sprintf ( V_142 -> V_144 , L_26 , F_53 ( V_41 -> V_67 ) ) ;
F_54 ( V_140 , V_2 , V_142 ) ;
return 0 ;
}
static int F_55 ( struct V_140 * V_140 , void * V_34 ,
struct V_145 * V_146 )
{
if ( V_146 -> V_147 != 0 )
return - V_69 ;
F_56 ( V_146 -> V_148 , L_27 , sizeof( V_146 -> V_148 ) ) ;
V_146 -> V_149 = V_150 ;
V_146 -> V_128 = V_151 ;
return 0 ;
}
static int F_57 ( struct V_140 * V_140 , void * V_34 ,
struct V_104 * V_146 )
{
struct V_40 * V_41 = F_52 ( V_140 ) ;
struct V_1 * V_2 = V_41 -> V_2 ;
V_146 -> V_105 . V_152 . V_149 = V_150 ;
V_146 -> V_105 . V_152 . V_153 = 0 ;
V_146 -> V_105 . V_152 . V_154 = V_41 -> V_111 * V_41 -> V_112 ;
V_146 -> V_105 . V_152 . V_155 = V_156 ;
V_146 -> V_105 . V_152 . V_73 = V_2 -> V_73 ;
V_146 -> V_105 . V_152 . V_72 = V_2 -> V_72 ;
V_146 -> V_105 . V_152 . V_157 = V_2 -> V_157 ;
return 0 ;
}
static int F_58 ( struct V_140 * V_140 , void * V_34 ,
struct V_104 * V_146 )
{
struct V_40 * V_41 = F_52 ( V_140 ) ;
struct V_1 * V_2 = V_41 -> V_2 ;
unsigned V_158 , V_159 ;
enum V_160 V_157 ;
V_146 -> V_105 . V_152 . V_149 = V_150 ;
V_146 -> V_105 . V_152 . V_153 = 0 ;
V_146 -> V_105 . V_152 . V_154 = V_41 -> V_111 * V_41 -> V_112 ;
V_146 -> V_105 . V_152 . V_155 = V_156 ;
V_158 = F_59 ( V_2 -> V_75 ) ;
V_159 = F_60 ( V_2 -> V_75 ) ;
V_157 = V_146 -> V_105 . V_152 . V_157 ;
switch ( V_157 ) {
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
break;
default:
V_157 = ( V_146 -> V_105 . V_152 . V_72 > V_159 / 2 )
? V_163
: V_162 ;
break;
}
if ( F_61 ( V_157 ) )
V_159 /= 2 ;
F_62 ( & V_146 -> V_105 . V_152 . V_73 , 48 , V_158 , 2 ,
& V_146 -> V_105 . V_152 . V_72 , 32 , V_159 , 0 , 0 ) ;
V_146 -> V_105 . V_152 . V_157 = V_157 ;
return 0 ;
}
static int F_63 ( struct V_140 * V_140 , void * V_34 ,
struct V_104 * V_146 )
{
struct V_40 * V_41 = F_52 ( V_140 ) ;
struct V_1 * V_2 = V_41 -> V_2 ;
if ( F_64 ( & V_41 -> V_166 ) )
return - V_167 ;
if ( V_2 -> V_168 && ( F_64 ( & V_2 -> V_168 -> V_169 ) ||
F_64 ( & V_2 -> V_168 -> V_170 ) ) )
return - V_167 ;
F_58 ( V_140 , V_34 , V_146 ) ;
V_2 -> V_73 = V_146 -> V_105 . V_152 . V_73 ;
V_2 -> V_72 = V_146 -> V_105 . V_152 . V_72 ;
V_2 -> V_157 = V_146 -> V_105 . V_152 . V_157 ;
F_65 ( V_2 , V_146 -> V_105 . V_152 . V_73 , V_146 -> V_105 . V_152 . V_72 , V_146 -> V_105 . V_152 . V_157 ) ;
F_15 ( V_41 , V_71 , 2 , 0 ,
V_146 -> V_105 . V_152 . V_72 , V_146 -> V_105 . V_152 . V_73 ) ;
return 0 ;
}
static int F_66 ( struct V_140 * V_140 , void * V_34 ,
const struct V_171 * V_146 )
{
struct V_40 * V_41 = F_52 ( V_140 ) ;
struct V_1 * V_2 = V_41 -> V_2 ;
bool V_172 ;
if ( F_67 ( V_173 == V_2 -> V_174 . V_175 ) )
return - V_69 ;
if ( F_67 ( V_146 -> V_176 != 0 ) )
return - V_69 ;
V_172 = F_68 ( & V_41 -> V_166 ) ;
if ( V_172 )
F_30 ( V_41 ) ;
F_69 ( V_2 , V_146 ) ;
F_26 ( V_41 ) ;
F_65 ( V_2 , V_2 -> V_73 , V_2 -> V_72 ,
V_2 -> V_157 ) ;
if ( V_172 )
F_28 ( V_41 ) ;
return 0 ;
}
static int F_70 ( struct V_140 * V_140 , void * V_34 )
{
struct V_40 * V_41 = F_52 ( V_140 ) ;
struct V_1 * V_2 = V_41 -> V_2 ;
char V_177 [ 32 + 2 ] ;
snprintf ( V_177 , sizeof( V_177 ) , L_28 , V_2 -> V_177 ) ;
F_71 ( V_2 , V_2 , V_178 ) ;
F_72 ( & V_41 -> V_74 . V_179 , V_177 ) ;
return 0 ;
}
static int F_73 ( struct V_140 * V_140 , void * V_34 ,
struct V_180 * V_43 )
{
struct V_40 * V_41 = F_52 ( V_140 ) ;
struct V_1 * V_2 = V_41 -> V_2 ;
return F_74 ( V_2 , V_43 ) ;
}
static int F_75 ( struct V_140 * V_140 , void * V_34 ,
struct V_171 * V_146 )
{
struct V_40 * V_41 = F_52 ( V_140 ) ;
struct V_1 * V_2 = V_41 -> V_2 ;
if ( F_67 ( V_173 == V_2 -> V_174 . V_175 ) )
return - V_69 ;
if ( F_67 ( V_146 -> V_176 != 0 ) )
return - V_69 ;
V_146 -> V_181 = V_2 -> V_182 ;
F_71 ( V_2 , V_176 , V_183 , V_146 ) ;
return 0 ;
}
static int F_76 ( struct V_140 * V_140 , void * V_34 , unsigned int * V_43 )
{
struct V_40 * V_41 = F_52 ( V_140 ) ;
struct V_1 * V_2 = V_41 -> V_2 ;
* V_43 = V_2 -> V_184 ;
return 0 ;
}
static int F_77 ( struct V_140 * V_140 , void * V_34 , unsigned int V_43 )
{
struct V_40 * V_41 = F_52 ( V_140 ) ;
struct V_1 * V_2 = V_41 -> V_2 ;
if ( V_43 >= 4 )
return - V_69 ;
if ( 0 == F_78 ( V_43 ) . type )
return - V_69 ;
F_79 ( V_2 ) ;
F_80 ( V_2 , V_43 ) ;
return 0 ;
}
static int F_81 ( struct V_140 * V_140 , void * V_34 ,
struct V_185 * V_186 )
{
struct V_40 * V_41 = F_52 ( V_140 ) ;
struct V_1 * V_2 = V_41 -> V_2 ;
T_1 V_90 ;
if ( F_67 ( V_173 == V_2 -> V_174 . V_175 ) )
return - V_69 ;
if ( 0 != V_186 -> V_147 )
return - V_69 ;
strcpy ( V_186 -> V_177 , L_29 ) ;
V_186 -> V_187 = V_188 ;
V_186 -> V_189 = 0xffffffffUL ;
F_71 ( V_2 , V_176 , V_190 , V_186 ) ;
F_82 ( V_2 , V_186 ) ;
V_90 = F_6 ( V_191 ) ;
V_186 -> signal = ( V_90 & ( 1 << 5 ) ) ? 0xffff : 0x0000 ;
return 0 ;
}
static int F_83 ( struct V_140 * V_140 , void * V_34 ,
const struct V_185 * V_186 )
{
struct V_40 * V_41 = F_52 ( V_140 ) ;
struct V_1 * V_2 = V_41 -> V_2 ;
if ( V_173 == V_2 -> V_174 . V_175 )
return - V_69 ;
if ( 0 != V_186 -> V_147 )
return - V_69 ;
F_84 ( V_2 , V_186 -> V_192 , 1 ) ;
return 0 ;
}
static int F_85 ( struct V_140 * V_140 , void * V_34 , T_4 * V_75 )
{
struct V_40 * V_41 = F_52 ( V_140 ) ;
struct V_1 * V_2 = V_41 -> V_2 ;
* V_75 = V_2 -> V_75 ;
return 0 ;
}
static int F_86 ( struct V_140 * V_140 , void * V_34 , T_4 V_193 )
{
struct V_40 * V_41 = F_52 ( V_140 ) ;
struct V_1 * V_2 = V_41 -> V_2 ;
return F_87 ( V_2 , V_193 ) ;
}
static int F_88 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
int V_51 = 0 ;
switch ( V_2 -> V_194 ) {
case V_195 :
F_89 ( V_15 , 0x00000080 ) ;
F_3 ( 1000 ) ;
F_27 ( V_15 , 0x00000080 ) ;
F_3 ( 50 ) ;
F_89 ( V_15 , 0x00000080 ) ;
F_3 ( 1000 ) ;
F_89 ( V_15 , 0x00000004 ) ;
F_3 ( 1000 ) ;
break;
default:
V_51 = - V_130 ;
}
return V_51 ;
}
static int F_90 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
int V_51 = 0 ;
switch ( V_2 -> V_194 ) {
case V_195 :
break;
default:
V_51 = - V_130 ;
}
return V_51 ;
}
static void F_91 ( struct V_40 * V_41 )
{
F_92 ( & V_41 -> V_196 ) ;
}
static int F_93 ( struct V_40 * V_41 )
{
int V_51 ;
F_94 ( V_41 -> V_2 , V_41 -> V_67 , & V_41 -> V_196 ,
& V_197 , L_30 ) ;
V_41 -> V_196 . V_198 = & V_41 -> V_74 . V_179 ;
F_95 ( & V_41 -> V_196 , V_41 ) ;
V_41 -> V_196 . V_199 = & V_41 -> V_166 ;
V_51 = F_96 ( & V_41 -> V_196 , V_200 , - 1 ) ;
if ( V_51 < 0 ) {
F_97 ( V_201 L_31 ,
V_41 -> V_2 -> V_177 ) ;
return V_51 ;
}
F_97 ( V_201 L_32 ,
V_41 -> V_2 -> V_177 , F_98 ( & V_41 -> V_196 ) ) ;
return 0 ;
}
static int F_99 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
struct V_40 * V_41 = V_2 -> V_202 ;
struct V_102 * V_103 ;
int V_51 ;
F_14 ( 1 , L_33 , V_44 ) ;
F_14 ( 1 , L_34 ,
V_2 -> V_194 ,
V_2 -> V_177 ,
V_2 -> V_203 ,
V_2 -> V_204 ) ;
V_51 = - V_130 ;
if ( ! ( V_2 -> V_174 . V_205 & V_129 ) )
goto V_206;
V_41 -> V_74 . V_207 = V_208 ;
V_41 -> V_74 . V_73 = V_2 -> V_73 ;
V_41 -> V_74 . V_72 = V_2 -> V_72 ;
V_41 -> V_74 . V_209 = F_13 ;
V_41 -> V_74 . V_34 = V_41 ;
V_51 = F_100 ( & V_41 -> V_74 , 36 ) ;
if ( V_51 )
goto V_206;
F_101 ( & V_41 -> V_74 . V_179 , & V_2 -> V_210 , NULL ) ;
F_97 ( L_35 ,
V_2 -> V_177 ) ;
F_1 ( V_41 -> V_2 ) ;
F_26 ( V_41 ) ;
F_87 ( V_2 , V_2 -> V_75 ) ;
F_80 ( V_2 , 0 ) ;
F_24 ( & V_41 -> V_74 , V_2 -> V_72 == 576 ) ;
F_25 ( & V_41 -> V_74 ) ;
V_103 = & V_41 -> V_166 ;
V_103 -> type = V_211 ;
V_103 -> V_212 = V_213 | V_214 | V_215 | V_216 ;
V_103 -> V_217 = V_218 ;
V_103 -> V_219 = 2 ;
V_103 -> V_110 = V_41 ;
V_103 -> V_220 = sizeof( struct V_116 ) ;
V_103 -> V_221 = & V_222 ;
V_103 -> V_223 = & V_224 ;
V_103 -> V_225 = V_226 ;
V_103 -> V_227 = & V_2 -> V_227 ;
V_51 = F_102 ( V_103 ) ;
if ( V_51 < 0 )
goto V_206;
F_93 ( V_41 ) ;
return 0 ;
V_206:
return V_51 ;
}
static int F_103 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
struct V_40 * V_41 = V_2 -> V_202 ;
F_91 ( V_127 -> V_2 -> V_202 ) ;
F_104 ( & V_41 -> V_74 . V_179 ) ;
return 0 ;
}
static int T_5 F_105 ( void )
{
F_97 ( V_201 L_36 ,
V_228 ) ;
return F_106 ( & V_229 ) ;
}
static void T_6 F_107 ( void )
{
F_108 ( & V_229 ) ;
}
