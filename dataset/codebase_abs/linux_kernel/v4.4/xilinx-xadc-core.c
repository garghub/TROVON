static void F_1 ( struct V_1 * V_1 , unsigned int V_2 ,
T_1 V_3 )
{
F_2 ( V_3 , V_1 -> V_4 + V_2 ) ;
}
static void F_3 ( struct V_1 * V_1 , unsigned int V_2 ,
T_1 * V_3 )
{
* V_3 = F_4 ( V_1 -> V_4 + V_2 ) ;
}
static void F_5 ( struct V_1 * V_1 , T_1 * V_5 ,
unsigned int V_6 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ )
F_1 ( V_1 , V_8 , V_5 [ V_7 ] ) ;
}
static void F_6 ( struct V_1 * V_1 )
{
T_1 V_9 , V_10 ;
F_3 ( V_1 , V_11 , & V_9 ) ;
while ( ! ( V_9 & V_12 ) ) {
F_3 ( V_1 , V_13 , & V_10 ) ;
F_3 ( V_1 , V_11 , & V_9 ) ;
}
}
static void F_7 ( struct V_1 * V_1 , unsigned int V_14 ,
unsigned int V_3 )
{
V_1 -> V_15 &= ~ V_14 ;
V_1 -> V_15 |= V_3 ;
F_1 ( V_1 , V_16 ,
V_1 -> V_15 | V_1 -> V_17 ) ;
}
static int F_8 ( struct V_1 * V_1 , unsigned int V_2 ,
T_2 V_3 )
{
T_1 V_5 [ 1 ] ;
T_1 V_10 ;
int V_18 ;
F_9 ( & V_1 -> V_19 ) ;
F_7 ( V_1 , V_20 ,
V_20 ) ;
F_10 ( & V_1 -> V_21 ) ;
V_5 [ 0 ] = F_11 ( V_22 , V_2 , V_3 ) ;
F_5 ( V_1 , V_5 , F_12 ( V_5 ) ) ;
F_3 ( V_1 , V_23 , & V_10 ) ;
V_10 &= ~ V_24 ;
V_10 |= 0 << V_25 ;
F_1 ( V_1 , V_23 , V_10 ) ;
F_7 ( V_1 , V_20 , 0 ) ;
F_13 ( & V_1 -> V_19 ) ;
V_18 = F_14 ( & V_1 -> V_21 , V_26 ) ;
if ( V_18 == 0 )
V_18 = - V_27 ;
else
V_18 = 0 ;
F_3 ( V_1 , V_13 , & V_10 ) ;
return V_18 ;
}
static int F_15 ( struct V_1 * V_1 , unsigned int V_2 ,
T_2 * V_3 )
{
T_1 V_5 [ 2 ] ;
T_1 V_28 , V_10 ;
int V_18 ;
V_5 [ 0 ] = F_11 ( V_29 , V_2 , 0 ) ;
V_5 [ 1 ] = F_11 ( V_30 , 0 , 0 ) ;
F_9 ( & V_1 -> V_19 ) ;
F_7 ( V_1 , V_20 ,
V_20 ) ;
F_6 ( V_1 ) ;
F_10 ( & V_1 -> V_21 ) ;
F_5 ( V_1 , V_5 , F_12 ( V_5 ) ) ;
F_3 ( V_1 , V_23 , & V_10 ) ;
V_10 &= ~ V_24 ;
V_10 |= 1 << V_25 ;
F_1 ( V_1 , V_23 , V_10 ) ;
F_7 ( V_1 , V_20 , 0 ) ;
F_13 ( & V_1 -> V_19 ) ;
V_18 = F_14 ( & V_1 -> V_21 , V_26 ) ;
if ( V_18 == 0 )
V_18 = - V_27 ;
if ( V_18 < 0 )
return V_18 ;
F_3 ( V_1 , V_13 , & V_28 ) ;
F_3 ( V_1 , V_13 , & V_28 ) ;
* V_3 = V_28 & 0xffff ;
return 0 ;
}
static unsigned int F_16 ( unsigned int V_31 )
{
return ( ( V_31 & 0x80 ) >> 4 ) |
( ( V_31 & 0x78 ) << 1 ) |
( V_31 & 0x07 ) ;
}
static void F_17 ( struct V_32 * V_33 )
{
struct V_1 * V_1 = F_18 ( V_33 , struct V_1 , V_34 . V_33 ) ;
unsigned int V_35 , V_36 ;
F_3 ( V_1 , V_11 , & V_35 ) ;
V_35 &= V_37 ;
F_9 ( & V_1 -> V_19 ) ;
V_36 = ( V_1 -> V_17 ^ V_35 ) & V_1 -> V_17 ;
V_1 -> V_17 &= V_35 ;
V_1 -> V_17 &= ~ V_1 -> V_15 ;
F_1 ( V_1 , V_38 , V_36 ) ;
F_7 ( V_1 , 0 , 0 ) ;
F_13 ( & V_1 -> V_19 ) ;
if ( V_1 -> V_17 ) {
F_19 ( & V_1 -> V_34 ,
F_20 ( V_39 ) ) ;
}
}
static T_3 F_21 ( int V_40 , void * V_41 )
{
struct V_42 * V_43 = V_41 ;
struct V_1 * V_1 = F_22 ( V_43 ) ;
T_1 V_9 ;
F_3 ( V_1 , V_38 , & V_9 ) ;
V_9 &= ~ ( V_1 -> V_15 | V_1 -> V_17 ) ;
if ( ! V_9 )
return V_44 ;
F_23 ( & V_1 -> V_19 ) ;
F_1 ( V_1 , V_38 , V_9 ) ;
if ( V_9 & V_20 ) {
F_7 ( V_1 , V_20 ,
V_20 ) ;
F_24 ( & V_1 -> V_21 ) ;
}
V_9 &= V_37 ;
if ( V_9 ) {
V_1 -> V_17 |= V_9 ;
F_7 ( V_1 , 0 , 0 ) ;
F_25 ( V_43 ,
F_16 ( V_9 ) ) ;
F_19 ( & V_1 -> V_34 ,
F_20 ( V_39 ) ) ;
}
F_26 ( & V_1 -> V_19 ) ;
return V_45 ;
}
static int F_27 ( struct V_46 * V_47 ,
struct V_42 * V_43 , int V_40 )
{
struct V_1 * V_1 = F_22 ( V_43 ) ;
unsigned long V_48 ;
unsigned int V_49 ;
unsigned int div ;
unsigned int V_50 ;
unsigned int V_51 ;
V_50 = V_52 ;
V_51 = V_53 ;
V_1 -> V_15 = ~ 0 ;
V_48 = F_28 ( V_1 -> V_54 ) ;
if ( V_51 > V_53 )
V_51 = V_53 ;
if ( V_51 > V_48 / 2 ) {
div = 2 ;
} else {
div = V_48 / V_51 ;
if ( V_48 / div > V_53 )
div ++ ;
}
if ( div <= 3 )
V_49 = V_55 ;
else if ( div <= 7 )
V_49 = V_56 ;
else if ( div <= 15 )
V_49 = V_57 ;
else
V_49 = V_58 ;
F_1 ( V_1 , V_59 , V_60 ) ;
F_1 ( V_1 , V_59 , 0 ) ;
F_1 ( V_1 , V_38 , ~ 0 ) ;
F_1 ( V_1 , V_16 , V_1 -> V_15 ) ;
F_1 ( V_1 , V_23 , V_61 |
V_62 | V_63 |
V_49 | F_29 ( V_50 ) ) ;
return 0 ;
}
static unsigned long F_30 ( struct V_1 * V_1 )
{
unsigned int div ;
T_1 V_3 ;
F_3 ( V_1 , V_23 , & V_3 ) ;
switch ( V_3 & V_64 ) {
case V_56 :
div = 4 ;
break;
case V_57 :
div = 8 ;
break;
case V_58 :
div = 16 ;
break;
default:
div = 2 ;
break;
}
return F_28 ( V_1 -> V_54 ) / div ;
}
static void F_31 ( struct V_1 * V_1 , unsigned int V_31 )
{
unsigned long V_65 ;
T_1 V_9 ;
V_31 = ( ( V_31 & 0x08 ) << 4 ) | ( ( V_31 & 0xf0 ) >> 1 ) | ( V_31 & 0x07 ) ;
F_32 ( & V_1 -> V_19 , V_65 ) ;
F_3 ( V_1 , V_38 , & V_9 ) ;
F_1 ( V_1 , V_38 , V_9 & V_31 ) ;
F_7 ( V_1 , V_37 ,
~ V_31 & V_37 ) ;
F_33 ( & V_1 -> V_19 , V_65 ) ;
}
static int F_34 ( struct V_1 * V_1 , unsigned int V_2 ,
T_2 * V_3 )
{
T_1 V_66 ;
F_3 ( V_1 , V_67 + V_2 * 4 , & V_66 ) ;
* V_3 = V_66 & 0xffff ;
return 0 ;
}
static int F_35 ( struct V_1 * V_1 , unsigned int V_2 ,
T_2 V_3 )
{
F_1 ( V_1 , V_67 + V_2 * 4 , V_3 ) ;
return 0 ;
}
static int F_36 ( struct V_46 * V_47 ,
struct V_42 * V_43 , int V_40 )
{
struct V_1 * V_1 = F_22 ( V_43 ) ;
F_1 ( V_1 , V_68 , V_69 ) ;
F_1 ( V_1 , V_70 , V_71 ) ;
return 0 ;
}
static T_3 F_37 ( int V_40 , void * V_41 )
{
struct V_42 * V_43 = V_41 ;
struct V_1 * V_1 = F_22 ( V_43 ) ;
T_1 V_9 , V_14 ;
unsigned int V_72 ;
F_3 ( V_1 , V_73 , & V_9 ) ;
F_3 ( V_1 , V_74 , & V_14 ) ;
V_9 &= V_14 ;
if ( ! V_9 )
return V_44 ;
if ( ( V_9 & V_75 ) && V_1 -> V_76 )
F_38 ( V_1 -> V_76 ) ;
if ( V_9 & V_77 ) {
V_72 = ( V_9 & 0x000e ) >> 1 ;
V_72 |= ( V_9 & 0x0001 ) << 3 ;
V_72 |= ( V_9 & 0x3c00 ) >> 6 ;
F_25 ( V_43 , V_72 ) ;
}
F_1 ( V_1 , V_73 , V_9 ) ;
return V_45 ;
}
static void F_39 ( struct V_1 * V_1 , unsigned int V_31 )
{
T_1 V_3 ;
unsigned long V_65 ;
V_31 = ( ( V_31 & 0x07 ) << 1 ) | ( ( V_31 & 0x08 ) >> 3 ) |
( ( V_31 & 0xf0 ) << 6 ) ;
F_32 ( & V_1 -> V_19 , V_65 ) ;
F_3 ( V_1 , V_74 , & V_3 ) ;
V_3 &= ~ V_77 ;
V_3 |= V_31 ;
F_1 ( V_1 , V_74 , V_3 ) ;
F_33 ( & V_1 -> V_19 , V_65 ) ;
}
static unsigned long F_40 ( struct V_1 * V_1 )
{
return F_28 ( V_1 -> V_54 ) ;
}
static int F_41 ( struct V_1 * V_1 , unsigned int V_2 ,
T_2 V_14 , T_2 V_3 )
{
T_2 V_10 ;
int V_18 ;
V_18 = F_42 ( V_1 , V_2 , & V_10 ) ;
if ( V_18 )
return V_18 ;
return F_43 ( V_1 , V_2 , ( V_10 & ~ V_14 ) | V_3 ) ;
}
static int F_44 ( struct V_1 * V_1 , unsigned int V_2 ,
T_2 V_14 , T_2 V_3 )
{
int V_18 ;
F_45 ( & V_1 -> V_78 ) ;
V_18 = F_41 ( V_1 , V_2 , V_14 , V_3 ) ;
F_46 ( & V_1 -> V_78 ) ;
return V_18 ;
}
static unsigned long F_47 ( struct V_1 * V_1 )
{
return V_1 -> V_79 -> V_80 ( V_1 ) ;
}
static int F_48 ( struct V_42 * V_43 ,
const unsigned long * V_14 )
{
struct V_1 * V_1 = F_22 ( V_43 ) ;
unsigned int V_6 ;
V_6 = F_49 ( V_14 , V_43 -> V_81 ) ;
F_50 ( V_1 -> V_82 ) ;
V_1 -> V_82 = F_51 ( V_6 , sizeof( * V_1 -> V_82 ) , V_83 ) ;
if ( ! V_1 -> V_82 )
return - V_84 ;
return 0 ;
}
static unsigned int F_52 ( unsigned int V_85 )
{
switch ( V_85 ) {
case 5 :
return V_86 ;
case 6 :
return V_87 ;
case 7 :
return V_88 ;
case 8 :
return V_89 ;
case 9 :
return V_90 ;
case 10 :
return V_91 ;
case 11 :
return V_92 ;
case 12 :
return V_93 ;
case 13 :
return V_94 ;
case 14 :
return V_95 ;
default:
return F_53 ( V_85 - 16 ) ;
}
}
static T_3 F_54 ( int V_40 , void * V_96 )
{
struct V_97 * V_98 = V_96 ;
struct V_42 * V_43 = V_98 -> V_43 ;
struct V_1 * V_1 = F_22 ( V_43 ) ;
unsigned int V_99 ;
int V_7 , V_100 ;
if ( ! V_1 -> V_82 )
goto V_101;
V_100 = 0 ;
F_55 (i, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_99 = F_52 ( V_7 ) ;
F_56 ( V_1 , V_99 , & V_1 -> V_82 [ V_100 ] ) ;
V_100 ++ ;
}
F_57 ( V_43 , V_1 -> V_82 ) ;
V_101:
F_58 ( V_43 -> V_102 ) ;
return V_45 ;
}
static int F_59 ( struct V_103 * V_76 , bool V_104 )
{
struct V_1 * V_1 = F_60 ( V_76 ) ;
unsigned long V_65 ;
unsigned int V_105 ;
unsigned int V_3 ;
int V_18 = 0 ;
F_45 ( & V_1 -> V_78 ) ;
if ( V_104 ) {
if ( V_1 -> V_76 != NULL ) {
V_18 = - V_106 ;
goto V_107;
} else {
V_1 -> V_76 = V_76 ;
if ( V_76 == V_1 -> V_108 )
V_105 = V_109 ;
else
V_105 = 0 ;
}
V_18 = F_41 ( V_1 , V_110 , V_109 ,
V_105 ) ;
if ( V_18 )
goto V_107;
} else {
V_1 -> V_76 = NULL ;
}
F_32 ( & V_1 -> V_19 , V_65 ) ;
F_3 ( V_1 , V_74 , & V_3 ) ;
F_1 ( V_1 , V_73 , V_3 & V_75 ) ;
if ( V_104 )
V_3 |= V_75 ;
else
V_3 &= ~ V_75 ;
F_1 ( V_1 , V_74 , V_3 ) ;
F_33 ( & V_1 -> V_19 , V_65 ) ;
V_107:
F_46 ( & V_1 -> V_78 ) ;
return V_18 ;
}
static struct V_103 * F_61 ( struct V_42 * V_43 ,
const char * V_111 )
{
struct V_103 * V_102 ;
int V_18 ;
V_102 = F_62 ( L_1 , V_43 -> V_111 ,
V_43 -> V_112 , V_111 ) ;
if ( V_102 == NULL )
return F_63 ( - V_84 ) ;
V_102 -> V_113 . V_114 = V_43 -> V_113 . V_114 ;
V_102 -> V_79 = & V_115 ;
F_64 ( V_102 , F_22 ( V_43 ) ) ;
V_18 = F_65 ( V_102 ) ;
if ( V_18 )
goto V_116;
return V_102 ;
V_116:
F_66 ( V_102 ) ;
return F_63 ( V_18 ) ;
}
static int F_67 ( struct V_1 * V_1 , unsigned int V_117 )
{
T_2 V_3 ;
switch ( V_117 ) {
case V_118 :
case V_119 :
V_3 = V_120 ;
break;
default:
V_3 = 0 ;
break;
}
return F_44 ( V_1 , V_121 , V_122 ,
V_3 ) ;
}
static int F_68 ( struct V_1 * V_1 , unsigned long V_123 )
{
unsigned int V_124 = V_123 >> 16 ;
if ( V_1 -> V_125 == V_126 )
return V_118 ;
if ( ( V_124 & 0xff00 ) == 0 ||
( V_124 & 0x00ff ) == 0 )
return V_127 ;
return V_118 ;
}
static int F_69 ( struct V_42 * V_43 )
{
struct V_1 * V_1 = F_22 ( V_43 ) ;
unsigned long V_128 ;
int V_18 ;
int V_7 ;
V_128 = 1 ;
for ( V_7 = 0 ; V_7 < V_43 -> V_129 ; V_7 ++ )
V_128 |= F_70 ( V_43 -> V_130 [ V_7 ] . V_85 ) ;
V_18 = F_71 ( V_1 , F_72 ( 0 ) , V_128 & 0xffff ) ;
if ( V_18 )
return V_18 ;
V_18 = F_71 ( V_1 , F_72 ( 1 ) , V_128 >> 16 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_44 ( V_1 , V_110 , V_131 ,
V_127 ) ;
if ( V_18 )
return V_18 ;
return F_67 ( V_1 , V_127 ) ;
}
static int F_73 ( struct V_42 * V_43 )
{
struct V_1 * V_1 = F_22 ( V_43 ) ;
unsigned long V_128 ;
int V_117 ;
int V_18 ;
V_18 = F_44 ( V_1 , V_110 , V_131 ,
V_132 ) ;
if ( V_18 )
goto V_133;
V_128 = * V_43 -> V_134 ;
V_117 = F_68 ( V_1 , V_128 ) ;
V_18 = F_71 ( V_1 , F_72 ( 0 ) , V_128 & 0xffff ) ;
if ( V_18 )
goto V_133;
V_18 = F_71 ( V_1 , F_72 ( 1 ) , V_128 >> 16 ) ;
if ( V_18 )
goto V_133;
V_18 = F_67 ( V_1 , V_117 ) ;
if ( V_18 )
goto V_133;
V_18 = F_44 ( V_1 , V_110 , V_131 ,
V_117 ) ;
if ( V_18 )
goto V_133;
return 0 ;
V_133:
F_69 ( V_43 ) ;
return V_18 ;
}
static int F_74 ( struct V_42 * V_43 ,
struct V_135 const * V_99 , int * V_3 , int * V_136 , long V_137 )
{
struct V_1 * V_1 = F_22 ( V_43 ) ;
unsigned int div ;
T_2 V_138 ;
int V_18 ;
switch ( V_137 ) {
case V_139 :
if ( F_75 ( V_43 ) )
return - V_106 ;
V_18 = F_56 ( V_1 , V_99 -> V_140 , & V_138 ) ;
if ( V_18 < 0 )
return V_18 ;
V_138 >>= 4 ;
if ( V_99 -> V_141 . V_142 == 'u' )
* V_3 = V_138 ;
else
* V_3 = F_76 ( V_138 , 11 ) ;
return V_143 ;
case V_144 :
switch ( V_99 -> type ) {
case V_145 :
switch ( V_99 -> V_140 ) {
case V_90 :
case V_91 :
case V_93 :
case V_94 :
case V_95 :
case V_86 :
case V_87 :
case V_88 :
* V_3 = 3000 ;
break;
default:
* V_3 = 1000 ;
break;
}
* V_136 = 12 ;
return V_146 ;
case V_147 :
* V_3 = 503975 ;
* V_136 = 12 ;
return V_146 ;
default:
return - V_148 ;
}
case V_149 :
* V_3 = - ( ( 273150 << 12 ) / 503975 ) ;
return V_143 ;
case V_150 :
V_18 = F_56 ( V_1 , V_121 , & V_138 ) ;
if ( V_18 )
return V_18 ;
div = ( V_138 & V_151 ) >> V_152 ;
if ( div < 2 )
div = 2 ;
* V_3 = F_47 ( V_1 ) / div / 26 ;
return V_143 ;
default:
return - V_148 ;
}
}
static int F_77 ( struct V_42 * V_43 ,
struct V_135 const * V_99 , int V_3 , int V_136 , long V_137 )
{
struct V_1 * V_1 = F_22 ( V_43 ) ;
unsigned long V_153 = F_47 ( V_1 ) ;
unsigned int div ;
if ( V_137 != V_150 )
return - V_148 ;
if ( V_3 <= 0 )
return - V_148 ;
if ( V_3 > 150000 )
V_3 = 150000 ;
V_3 *= 26 ;
if ( V_3 < 1000000 )
V_3 = 1000000 ;
div = V_153 / V_3 ;
if ( V_153 / div / 26 > 150000 )
div ++ ;
if ( div < 2 )
div = 2 ;
else if ( div > 0xff )
div = 0xff ;
return F_44 ( V_1 , V_121 , V_151 ,
div << V_152 ) ;
}
static int F_78 ( struct V_42 * V_43 , struct V_154 * V_155 ,
unsigned int * V_156 )
{
struct V_1 * V_1 = F_22 ( V_43 ) ;
struct V_135 * V_130 , * V_99 ;
struct V_154 * V_157 , * V_158 ;
unsigned int V_129 ;
const char * V_159 ;
T_4 V_160 ;
int V_2 ;
int V_18 ;
* V_156 = 0 ;
V_18 = F_79 ( V_155 , L_2 , & V_159 ) ;
if ( V_18 < 0 || strcasecmp ( V_159 , L_3 ) == 0 )
V_1 -> V_125 = V_161 ;
else if ( strcasecmp ( V_159 , L_4 ) == 0 )
V_1 -> V_125 = V_162 ;
else if ( strcasecmp ( V_159 , L_5 ) == 0 )
V_1 -> V_125 = V_126 ;
else
return - V_148 ;
if ( V_1 -> V_125 != V_161 ) {
V_18 = F_80 ( V_155 , L_6 ,
& V_160 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_1 -> V_125 == V_162 ) {
if ( V_160 == 0 )
V_160 = V_92 ;
else if ( V_160 <= 16 )
V_160 = F_53 ( V_160 - 1 ) ;
else
return - V_148 ;
} else {
if ( V_160 > 0 && V_160 <= 8 )
V_160 = F_53 ( V_160 - 1 ) ;
else
return - V_148 ;
}
* V_156 |= V_163 | F_81 ( V_160 ) ;
}
V_130 = F_82 ( V_164 , sizeof( V_164 ) , V_83 ) ;
if ( ! V_130 )
return - V_84 ;
V_129 = 9 ;
V_99 = & V_130 [ 9 ] ;
V_157 = F_83 ( V_155 , L_7 ) ;
if ( V_157 ) {
F_84 (chan_node, child) {
if ( V_129 >= F_12 ( V_164 ) ) {
F_85 ( V_158 ) ;
break;
}
V_18 = F_80 ( V_158 , L_8 , & V_2 ) ;
if ( V_18 || V_2 > 16 )
continue;
if ( F_86 ( V_158 , L_9 ) )
V_99 -> V_141 . V_142 = 's' ;
if ( V_2 == 0 ) {
V_99 -> V_85 = 11 ;
V_99 -> V_140 = V_92 ;
} else {
V_99 -> V_85 = 15 + V_2 ;
V_99 -> V_140 = F_53 ( V_2 - 1 ) ;
}
V_129 ++ ;
V_99 ++ ;
}
}
F_85 ( V_157 ) ;
V_43 -> V_129 = V_129 ;
V_43 -> V_130 = F_87 ( V_130 , sizeof( * V_130 ) *
V_129 , V_83 ) ;
if ( ! V_43 -> V_130 )
V_43 -> V_130 = V_130 ;
return 0 ;
}
static int F_88 ( struct V_46 * V_47 )
{
const struct V_165 * V_112 ;
struct V_42 * V_43 ;
unsigned int V_166 ;
struct V_167 * V_168 ;
unsigned int V_169 ;
struct V_1 * V_1 ;
int V_18 ;
int V_40 ;
int V_7 ;
if ( ! V_47 -> V_113 . V_170 )
return - V_171 ;
V_112 = F_89 ( V_172 , V_47 -> V_113 . V_170 ) ;
if ( ! V_112 )
return - V_148 ;
V_40 = F_90 ( V_47 , 0 ) ;
if ( V_40 <= 0 )
return - V_173 ;
V_43 = F_91 ( & V_47 -> V_113 , sizeof( * V_1 ) ) ;
if ( ! V_43 )
return - V_84 ;
V_1 = F_22 ( V_43 ) ;
V_1 -> V_79 = V_112 -> V_82 ;
F_92 ( & V_1 -> V_21 ) ;
F_93 ( & V_1 -> V_78 ) ;
F_94 ( & V_1 -> V_19 ) ;
F_95 ( & V_1 -> V_34 , F_17 ) ;
V_168 = F_96 ( V_47 , V_174 , 0 ) ;
V_1 -> V_4 = F_97 ( & V_47 -> V_113 , V_168 ) ;
if ( F_98 ( V_1 -> V_4 ) )
return F_99 ( V_1 -> V_4 ) ;
V_43 -> V_113 . V_114 = & V_47 -> V_113 ;
V_43 -> V_113 . V_170 = V_47 -> V_113 . V_170 ;
V_43 -> V_111 = L_10 ;
V_43 -> V_175 = V_176 ;
V_43 -> V_137 = & V_177 ;
V_18 = F_78 ( V_43 , V_47 -> V_113 . V_170 , & V_169 ) ;
if ( V_18 )
goto V_178;
if ( V_1 -> V_79 -> V_65 & V_179 ) {
V_18 = F_100 ( V_43 ,
& V_180 , & F_54 ,
& V_181 ) ;
if ( V_18 )
goto V_178;
V_1 -> V_108 = F_61 ( V_43 , L_11 ) ;
if ( F_98 ( V_1 -> V_108 ) ) {
V_18 = F_99 ( V_1 -> V_108 ) ;
goto V_182;
}
V_1 -> V_183 = F_61 ( V_43 ,
L_12 ) ;
if ( F_98 ( V_1 -> V_183 ) ) {
V_18 = F_99 ( V_1 -> V_183 ) ;
goto V_184;
}
}
V_1 -> V_54 = F_101 ( & V_47 -> V_113 , NULL ) ;
if ( F_98 ( V_1 -> V_54 ) ) {
V_18 = F_99 ( V_1 -> V_54 ) ;
goto V_185;
}
F_102 ( V_1 -> V_54 ) ;
V_18 = V_1 -> V_79 -> V_186 ( V_47 , V_43 , V_40 ) ;
if ( V_18 )
goto V_185;
V_18 = F_103 ( V_40 , V_1 -> V_79 -> V_187 , 0 ,
F_104 ( & V_47 -> V_113 ) , V_43 ) ;
if ( V_18 )
goto V_188;
for ( V_7 = 0 ; V_7 < 16 ; V_7 ++ )
F_56 ( V_1 , F_105 ( V_7 ) ,
& V_1 -> V_189 [ V_7 ] ) ;
V_18 = F_71 ( V_1 , V_190 , V_169 ) ;
if ( V_18 )
goto V_191;
V_166 = 0 ;
for ( V_7 = 0 ; V_7 < V_43 -> V_129 ; V_7 ++ ) {
if ( V_43 -> V_130 [ V_7 ] . V_141 . V_142 == 's' )
V_166 |= F_70 ( V_43 -> V_130 [ V_7 ] . V_85 ) ;
}
V_18 = F_71 ( V_1 , F_106 ( 0 ) , V_166 ) ;
if ( V_18 )
goto V_191;
V_18 = F_71 ( V_1 , F_106 ( 1 ) ,
V_166 >> 16 ) ;
if ( V_18 )
goto V_191;
F_44 ( V_1 , V_110 , V_192 ,
V_192 ) ;
for ( V_7 = 0 ; V_7 < 16 ; V_7 ++ ) {
if ( V_7 % 8 < 4 || V_7 == 7 )
V_1 -> V_189 [ V_7 ] = 0xffff ;
else
V_1 -> V_189 [ V_7 ] = 0 ;
F_71 ( V_1 , F_105 ( V_7 ) ,
V_1 -> V_189 [ V_7 ] ) ;
}
F_69 ( V_43 ) ;
V_18 = F_107 ( V_43 ) ;
if ( V_18 )
goto V_191;
F_108 ( V_47 , V_43 ) ;
return 0 ;
V_191:
F_109 ( V_40 , V_43 ) ;
V_185:
if ( V_1 -> V_79 -> V_65 & V_179 )
F_66 ( V_1 -> V_183 ) ;
V_184:
if ( V_1 -> V_79 -> V_65 & V_179 )
F_66 ( V_1 -> V_108 ) ;
V_182:
if ( V_1 -> V_79 -> V_65 & V_179 )
F_110 ( V_43 ) ;
V_188:
F_111 ( V_1 -> V_54 ) ;
V_178:
F_50 ( V_43 -> V_130 ) ;
return V_18 ;
}
static int F_112 ( struct V_46 * V_47 )
{
struct V_42 * V_43 = F_113 ( V_47 ) ;
struct V_1 * V_1 = F_22 ( V_43 ) ;
int V_40 = F_90 ( V_47 , 0 ) ;
F_114 ( V_43 ) ;
if ( V_1 -> V_79 -> V_65 & V_179 ) {
F_66 ( V_1 -> V_183 ) ;
F_66 ( V_1 -> V_108 ) ;
F_110 ( V_43 ) ;
}
F_109 ( V_40 , V_43 ) ;
F_111 ( V_1 -> V_54 ) ;
F_115 ( & V_1 -> V_34 ) ;
F_50 ( V_1 -> V_82 ) ;
F_50 ( V_43 -> V_130 ) ;
return 0 ;
}
