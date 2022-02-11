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
unsigned int V_31 ;
F_9 ( & V_1 -> V_19 ) ;
V_31 = V_1 -> V_44 ;
V_1 -> V_44 = 0 ;
F_13 ( & V_1 -> V_19 ) ;
F_23 ( V_43 , F_16 ( V_31 ) ) ;
F_19 ( & V_1 -> V_34 ,
F_20 ( V_39 ) ) ;
return V_45 ;
}
static T_3 F_24 ( int V_40 , void * V_41 )
{
struct V_42 * V_43 = V_41 ;
struct V_1 * V_1 = F_22 ( V_43 ) ;
T_3 V_18 = V_45 ;
T_1 V_9 ;
F_3 ( V_1 , V_38 , & V_9 ) ;
V_9 &= ~ ( V_1 -> V_15 | V_1 -> V_17 ) ;
if ( ! V_9 )
return V_46 ;
F_25 ( & V_1 -> V_19 ) ;
F_1 ( V_1 , V_38 , V_9 ) ;
if ( V_9 & V_20 ) {
F_7 ( V_1 , V_20 ,
V_20 ) ;
F_26 ( & V_1 -> V_21 ) ;
}
V_9 &= V_37 ;
if ( V_9 ) {
V_1 -> V_44 |= V_9 ;
V_1 -> V_17 |= V_9 ;
F_7 ( V_1 , 0 , 0 ) ;
V_18 = V_47 ;
}
F_27 ( & V_1 -> V_19 ) ;
return V_18 ;
}
static int F_28 ( struct V_48 * V_49 ,
struct V_42 * V_43 , int V_40 )
{
struct V_1 * V_1 = F_22 ( V_43 ) ;
unsigned long V_50 ;
unsigned int V_51 ;
unsigned int div ;
unsigned int V_52 ;
unsigned int V_53 ;
V_52 = V_54 ;
V_53 = V_55 ;
V_1 -> V_15 = ~ 0 ;
V_50 = F_29 ( V_1 -> V_56 ) ;
if ( V_53 > V_55 )
V_53 = V_55 ;
if ( V_53 > V_50 / 2 ) {
div = 2 ;
} else {
div = V_50 / V_53 ;
if ( V_50 / div > V_55 )
div ++ ;
}
if ( div <= 3 )
V_51 = V_57 ;
else if ( div <= 7 )
V_51 = V_58 ;
else if ( div <= 15 )
V_51 = V_59 ;
else
V_51 = V_60 ;
F_1 ( V_1 , V_61 , V_62 ) ;
F_1 ( V_1 , V_61 , 0 ) ;
F_1 ( V_1 , V_38 , ~ 0 ) ;
F_1 ( V_1 , V_16 , V_1 -> V_15 ) ;
F_1 ( V_1 , V_23 , V_63 |
V_64 | V_65 |
V_51 | F_30 ( V_52 ) ) ;
return 0 ;
}
static unsigned long F_31 ( struct V_1 * V_1 )
{
unsigned int div ;
T_1 V_3 ;
F_3 ( V_1 , V_23 , & V_3 ) ;
switch ( V_3 & V_66 ) {
case V_58 :
div = 4 ;
break;
case V_59 :
div = 8 ;
break;
case V_60 :
div = 16 ;
break;
default:
div = 2 ;
break;
}
return F_29 ( V_1 -> V_56 ) / div ;
}
static void F_32 ( struct V_1 * V_1 , unsigned int V_31 )
{
unsigned long V_67 ;
T_1 V_9 ;
V_31 = ( ( V_31 & 0x08 ) << 4 ) | ( ( V_31 & 0xf0 ) >> 1 ) | ( V_31 & 0x07 ) ;
F_33 ( & V_1 -> V_19 , V_67 ) ;
F_3 ( V_1 , V_38 , & V_9 ) ;
F_1 ( V_1 , V_38 , V_9 & V_31 ) ;
F_7 ( V_1 , V_37 ,
~ V_31 & V_37 ) ;
F_34 ( & V_1 -> V_19 , V_67 ) ;
}
static int F_35 ( struct V_1 * V_1 , unsigned int V_2 ,
T_2 * V_3 )
{
T_1 V_68 ;
F_3 ( V_1 , V_69 + V_2 * 4 , & V_68 ) ;
* V_3 = V_68 & 0xffff ;
return 0 ;
}
static int F_36 ( struct V_1 * V_1 , unsigned int V_2 ,
T_2 V_3 )
{
F_1 ( V_1 , V_69 + V_2 * 4 , V_3 ) ;
return 0 ;
}
static int F_37 ( struct V_48 * V_49 ,
struct V_42 * V_43 , int V_40 )
{
struct V_1 * V_1 = F_22 ( V_43 ) ;
F_1 ( V_1 , V_70 , V_71 ) ;
F_1 ( V_1 , V_72 , V_73 ) ;
return 0 ;
}
static T_3 F_38 ( int V_40 , void * V_41 )
{
struct V_42 * V_43 = V_41 ;
struct V_1 * V_1 = F_22 ( V_43 ) ;
T_1 V_9 , V_14 ;
unsigned int V_74 ;
F_3 ( V_1 , V_75 , & V_9 ) ;
F_3 ( V_1 , V_76 , & V_14 ) ;
V_9 &= V_14 ;
if ( ! V_9 )
return V_46 ;
if ( ( V_9 & V_77 ) && V_1 -> V_78 )
F_39 ( V_1 -> V_78 ) ;
if ( V_9 & V_79 ) {
V_74 = ( V_9 & 0x000e ) >> 1 ;
V_74 |= ( V_9 & 0x0001 ) << 3 ;
V_74 |= ( V_9 & 0x3c00 ) >> 6 ;
F_23 ( V_43 , V_74 ) ;
}
F_1 ( V_1 , V_75 , V_9 ) ;
return V_45 ;
}
static void F_40 ( struct V_1 * V_1 , unsigned int V_31 )
{
T_1 V_3 ;
unsigned long V_67 ;
V_31 = ( ( V_31 & 0x07 ) << 1 ) | ( ( V_31 & 0x08 ) >> 3 ) |
( ( V_31 & 0xf0 ) << 6 ) ;
F_33 ( & V_1 -> V_19 , V_67 ) ;
F_3 ( V_1 , V_76 , & V_3 ) ;
V_3 &= ~ V_79 ;
V_3 |= V_31 ;
F_1 ( V_1 , V_76 , V_3 ) ;
F_34 ( & V_1 -> V_19 , V_67 ) ;
}
static unsigned long F_41 ( struct V_1 * V_1 )
{
return F_29 ( V_1 -> V_56 ) ;
}
static int F_42 ( struct V_1 * V_1 , unsigned int V_2 ,
T_2 V_14 , T_2 V_3 )
{
T_2 V_10 ;
int V_18 ;
V_18 = F_43 ( V_1 , V_2 , & V_10 ) ;
if ( V_18 )
return V_18 ;
return F_44 ( V_1 , V_2 , ( V_10 & ~ V_14 ) | V_3 ) ;
}
static int F_45 ( struct V_1 * V_1 , unsigned int V_2 ,
T_2 V_14 , T_2 V_3 )
{
int V_18 ;
F_46 ( & V_1 -> V_80 ) ;
V_18 = F_42 ( V_1 , V_2 , V_14 , V_3 ) ;
F_47 ( & V_1 -> V_80 ) ;
return V_18 ;
}
static unsigned long F_48 ( struct V_1 * V_1 )
{
return V_1 -> V_81 -> V_82 ( V_1 ) ;
}
static int F_49 ( struct V_42 * V_43 ,
const unsigned long * V_14 )
{
struct V_1 * V_1 = F_22 ( V_43 ) ;
unsigned int V_6 ;
V_6 = F_50 ( V_14 , V_43 -> V_83 ) ;
F_51 ( V_1 -> V_84 ) ;
V_1 -> V_84 = F_52 ( V_6 , sizeof( * V_1 -> V_84 ) , V_85 ) ;
if ( ! V_1 -> V_84 )
return - V_86 ;
return 0 ;
}
static unsigned int F_53 ( unsigned int V_87 )
{
switch ( V_87 ) {
case 5 :
return V_88 ;
case 6 :
return V_89 ;
case 7 :
return V_90 ;
case 8 :
return V_91 ;
case 9 :
return V_92 ;
case 10 :
return V_93 ;
case 11 :
return V_94 ;
case 12 :
return V_95 ;
case 13 :
return V_96 ;
case 14 :
return V_97 ;
default:
return F_54 ( V_87 - 16 ) ;
}
}
static T_3 F_55 ( int V_40 , void * V_98 )
{
struct V_99 * V_100 = V_98 ;
struct V_42 * V_43 = V_100 -> V_43 ;
struct V_1 * V_1 = F_22 ( V_43 ) ;
unsigned int V_101 ;
int V_7 , V_102 ;
if ( ! V_1 -> V_84 )
goto V_103;
V_102 = 0 ;
F_56 (i, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_101 = F_53 ( V_7 ) ;
F_57 ( V_1 , V_101 , & V_1 -> V_84 [ V_102 ] ) ;
V_102 ++ ;
}
F_58 ( V_43 , V_1 -> V_84 ) ;
V_103:
F_59 ( V_43 -> V_104 ) ;
return V_45 ;
}
static int F_60 ( struct V_105 * V_78 , bool V_106 )
{
struct V_1 * V_1 = F_61 ( V_78 ) ;
unsigned long V_67 ;
unsigned int V_107 ;
unsigned int V_3 ;
int V_18 = 0 ;
F_46 ( & V_1 -> V_80 ) ;
if ( V_106 ) {
if ( V_1 -> V_78 != NULL ) {
V_18 = - V_108 ;
goto V_109;
} else {
V_1 -> V_78 = V_78 ;
if ( V_78 == V_1 -> V_110 )
V_107 = V_111 ;
else
V_107 = 0 ;
}
V_18 = F_42 ( V_1 , V_112 , V_111 ,
V_107 ) ;
if ( V_18 )
goto V_109;
} else {
V_1 -> V_78 = NULL ;
}
F_33 ( & V_1 -> V_19 , V_67 ) ;
F_3 ( V_1 , V_76 , & V_3 ) ;
F_1 ( V_1 , V_75 , V_3 & V_77 ) ;
if ( V_106 )
V_3 |= V_77 ;
else
V_3 &= ~ V_77 ;
F_1 ( V_1 , V_76 , V_3 ) ;
F_34 ( & V_1 -> V_19 , V_67 ) ;
V_109:
F_47 ( & V_1 -> V_80 ) ;
return V_18 ;
}
static struct V_105 * F_62 ( struct V_42 * V_43 ,
const char * V_113 )
{
struct V_105 * V_104 ;
int V_18 ;
V_104 = F_63 ( L_1 , V_43 -> V_113 ,
V_43 -> V_114 , V_113 ) ;
if ( V_104 == NULL )
return F_64 ( - V_86 ) ;
V_104 -> V_115 . V_116 = V_43 -> V_115 . V_116 ;
V_104 -> V_81 = & V_117 ;
F_65 ( V_104 , F_22 ( V_43 ) ) ;
V_18 = F_66 ( V_104 ) ;
if ( V_18 )
goto V_118;
return V_104 ;
V_118:
F_67 ( V_104 ) ;
return F_64 ( V_18 ) ;
}
static int F_68 ( struct V_1 * V_1 , unsigned int V_119 )
{
T_2 V_3 ;
switch ( V_119 ) {
case V_120 :
case V_121 :
V_3 = V_122 ;
break;
default:
V_3 = 0 ;
break;
}
return F_45 ( V_1 , V_123 , V_124 ,
V_3 ) ;
}
static int F_69 ( struct V_1 * V_1 , unsigned long V_125 )
{
unsigned int V_126 = V_125 >> 16 ;
if ( V_1 -> V_127 == V_128 )
return V_120 ;
if ( ( V_126 & 0xff00 ) == 0 ||
( V_126 & 0x00ff ) == 0 )
return V_129 ;
return V_120 ;
}
static int F_70 ( struct V_42 * V_43 )
{
struct V_1 * V_1 = F_22 ( V_43 ) ;
unsigned long V_130 ;
int V_18 ;
int V_7 ;
V_130 = 1 ;
for ( V_7 = 0 ; V_7 < V_43 -> V_131 ; V_7 ++ )
V_130 |= F_71 ( V_43 -> V_132 [ V_7 ] . V_87 ) ;
V_18 = F_72 ( V_1 , F_73 ( 0 ) , V_130 & 0xffff ) ;
if ( V_18 )
return V_18 ;
V_18 = F_72 ( V_1 , F_73 ( 1 ) , V_130 >> 16 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_45 ( V_1 , V_112 , V_133 ,
V_129 ) ;
if ( V_18 )
return V_18 ;
return F_68 ( V_1 , V_129 ) ;
}
static int F_74 ( struct V_42 * V_43 )
{
struct V_1 * V_1 = F_22 ( V_43 ) ;
unsigned long V_130 ;
int V_119 ;
int V_18 ;
V_18 = F_45 ( V_1 , V_112 , V_133 ,
V_134 ) ;
if ( V_18 )
goto V_135;
V_130 = * V_43 -> V_136 ;
V_119 = F_69 ( V_1 , V_130 ) ;
V_18 = F_72 ( V_1 , F_73 ( 0 ) , V_130 & 0xffff ) ;
if ( V_18 )
goto V_135;
V_18 = F_72 ( V_1 , F_73 ( 1 ) , V_130 >> 16 ) ;
if ( V_18 )
goto V_135;
V_18 = F_68 ( V_1 , V_119 ) ;
if ( V_18 )
goto V_135;
V_18 = F_45 ( V_1 , V_112 , V_133 ,
V_119 ) ;
if ( V_18 )
goto V_135;
return 0 ;
V_135:
F_70 ( V_43 ) ;
return V_18 ;
}
static int F_75 ( struct V_42 * V_43 ,
struct V_137 const * V_101 , int * V_3 , int * V_138 , long V_139 )
{
struct V_1 * V_1 = F_22 ( V_43 ) ;
unsigned int div ;
T_2 V_140 ;
int V_18 ;
switch ( V_139 ) {
case V_141 :
if ( F_76 ( V_43 ) )
return - V_108 ;
V_18 = F_57 ( V_1 , V_101 -> V_142 , & V_140 ) ;
if ( V_18 < 0 )
return V_18 ;
V_140 >>= 4 ;
if ( V_101 -> V_143 . V_144 == 'u' )
* V_3 = V_140 ;
else
* V_3 = F_77 ( V_140 , 11 ) ;
return V_145 ;
case V_146 :
switch ( V_101 -> type ) {
case V_147 :
switch ( V_101 -> V_142 ) {
case V_92 :
case V_93 :
case V_95 :
case V_97 :
case V_88 :
case V_89 :
case V_90 :
* V_3 = 3000 ;
break;
default:
* V_3 = 1000 ;
break;
}
* V_138 = 12 ;
return V_148 ;
case V_149 :
* V_3 = 503975 ;
* V_138 = 12 ;
return V_148 ;
default:
return - V_150 ;
}
case V_151 :
* V_3 = - ( ( 273150 << 12 ) / 503975 ) ;
return V_145 ;
case V_152 :
V_18 = F_57 ( V_1 , V_123 , & V_140 ) ;
if ( V_18 )
return V_18 ;
div = ( V_140 & V_153 ) >> V_154 ;
if ( div < 2 )
div = 2 ;
* V_3 = F_48 ( V_1 ) / div / 26 ;
return V_145 ;
default:
return - V_150 ;
}
}
static int F_78 ( struct V_42 * V_43 ,
struct V_137 const * V_101 , int V_3 , int V_138 , long V_139 )
{
struct V_1 * V_1 = F_22 ( V_43 ) ;
unsigned long V_155 = F_48 ( V_1 ) ;
unsigned int div ;
if ( V_139 != V_152 )
return - V_150 ;
if ( V_3 <= 0 )
return - V_150 ;
if ( V_3 > 150000 )
V_3 = 150000 ;
V_3 *= 26 ;
if ( V_3 < 1000000 )
V_3 = 1000000 ;
div = V_155 / V_3 ;
if ( V_155 / div / 26 > 150000 )
div ++ ;
if ( div < 2 )
div = 2 ;
else if ( div > 0xff )
div = 0xff ;
return F_45 ( V_1 , V_123 , V_153 ,
div << V_154 ) ;
}
static int F_79 ( struct V_42 * V_43 , struct V_156 * V_157 ,
unsigned int * V_158 )
{
struct V_1 * V_1 = F_22 ( V_43 ) ;
struct V_137 * V_132 , * V_101 ;
struct V_156 * V_159 , * V_160 ;
unsigned int V_131 ;
const char * V_161 ;
T_4 V_162 ;
int V_2 ;
int V_18 ;
* V_158 = 0 ;
V_18 = F_80 ( V_157 , L_2 , & V_161 ) ;
if ( V_18 < 0 || strcasecmp ( V_161 , L_3 ) == 0 )
V_1 -> V_127 = V_163 ;
else if ( strcasecmp ( V_161 , L_4 ) == 0 )
V_1 -> V_127 = V_164 ;
else if ( strcasecmp ( V_161 , L_5 ) == 0 )
V_1 -> V_127 = V_128 ;
else
return - V_150 ;
if ( V_1 -> V_127 != V_163 ) {
V_18 = F_81 ( V_157 , L_6 ,
& V_162 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_1 -> V_127 == V_164 ) {
if ( V_162 == 0 )
V_162 = V_94 ;
else if ( V_162 <= 16 )
V_162 = F_54 ( V_162 - 1 ) ;
else
return - V_150 ;
} else {
if ( V_162 > 0 && V_162 <= 8 )
V_162 = F_54 ( V_162 - 1 ) ;
else
return - V_150 ;
}
* V_158 |= V_165 | F_82 ( V_162 ) ;
}
V_132 = F_83 ( V_166 , sizeof( V_166 ) , V_85 ) ;
if ( ! V_132 )
return - V_86 ;
V_131 = 9 ;
V_101 = & V_132 [ 9 ] ;
V_159 = F_84 ( V_157 , L_7 ) ;
if ( V_159 ) {
F_85 (chan_node, child) {
if ( V_131 >= F_12 ( V_166 ) ) {
F_86 ( V_160 ) ;
break;
}
V_18 = F_81 ( V_160 , L_8 , & V_2 ) ;
if ( V_18 || V_2 > 16 )
continue;
if ( F_87 ( V_160 , L_9 ) )
V_101 -> V_143 . V_144 = 's' ;
if ( V_2 == 0 ) {
V_101 -> V_87 = 11 ;
V_101 -> V_142 = V_94 ;
} else {
V_101 -> V_87 = 15 + V_2 ;
V_101 -> V_142 = F_54 ( V_2 - 1 ) ;
}
V_131 ++ ;
V_101 ++ ;
}
}
F_86 ( V_159 ) ;
V_43 -> V_131 = V_131 ;
V_43 -> V_132 = F_88 ( V_132 , sizeof( * V_132 ) *
V_131 , V_85 ) ;
if ( ! V_43 -> V_132 )
V_43 -> V_132 = V_132 ;
return 0 ;
}
static int F_89 ( struct V_48 * V_49 )
{
const struct V_167 * V_114 ;
struct V_42 * V_43 ;
unsigned int V_168 ;
struct V_169 * V_170 ;
unsigned int V_171 ;
struct V_1 * V_1 ;
int V_18 ;
int V_40 ;
int V_7 ;
if ( ! V_49 -> V_115 . V_172 )
return - V_173 ;
V_114 = F_90 ( V_174 , V_49 -> V_115 . V_172 ) ;
if ( ! V_114 )
return - V_150 ;
V_40 = F_91 ( V_49 , 0 ) ;
if ( V_40 <= 0 )
return - V_175 ;
V_43 = F_92 ( & V_49 -> V_115 , sizeof( * V_1 ) ) ;
if ( ! V_43 )
return - V_86 ;
V_1 = F_22 ( V_43 ) ;
V_1 -> V_81 = V_114 -> V_84 ;
F_93 ( & V_1 -> V_21 ) ;
F_94 ( & V_1 -> V_80 ) ;
F_95 ( & V_1 -> V_19 ) ;
F_96 ( & V_1 -> V_34 , F_17 ) ;
V_170 = F_97 ( V_49 , V_176 , 0 ) ;
V_1 -> V_4 = F_98 ( & V_49 -> V_115 , V_170 ) ;
if ( F_99 ( V_1 -> V_4 ) )
return F_100 ( V_1 -> V_4 ) ;
V_43 -> V_115 . V_116 = & V_49 -> V_115 ;
V_43 -> V_115 . V_172 = V_49 -> V_115 . V_172 ;
V_43 -> V_113 = L_10 ;
V_43 -> V_177 = V_178 ;
V_43 -> V_139 = & V_179 ;
V_18 = F_79 ( V_43 , V_49 -> V_115 . V_172 , & V_171 ) ;
if ( V_18 )
goto V_180;
if ( V_1 -> V_81 -> V_67 & V_181 ) {
V_18 = F_101 ( V_43 ,
& V_182 , & F_55 ,
& V_183 ) ;
if ( V_18 )
goto V_180;
V_1 -> V_110 = F_62 ( V_43 , L_11 ) ;
if ( F_99 ( V_1 -> V_110 ) ) {
V_18 = F_100 ( V_1 -> V_110 ) ;
goto V_184;
}
V_1 -> V_185 = F_62 ( V_43 ,
L_12 ) ;
if ( F_99 ( V_1 -> V_185 ) ) {
V_18 = F_100 ( V_1 -> V_185 ) ;
goto V_186;
}
}
V_1 -> V_56 = F_102 ( & V_49 -> V_115 , NULL ) ;
if ( F_99 ( V_1 -> V_56 ) ) {
V_18 = F_100 ( V_1 -> V_56 ) ;
goto V_187;
}
F_103 ( V_1 -> V_56 ) ;
V_18 = V_1 -> V_81 -> V_188 ( V_49 , V_43 , V_40 ) ;
if ( V_18 )
goto V_187;
V_18 = F_104 ( V_40 , V_1 -> V_81 -> V_189 ,
V_1 -> V_81 -> V_190 ,
0 , F_105 ( & V_49 -> V_115 ) , V_43 ) ;
if ( V_18 )
goto V_191;
for ( V_7 = 0 ; V_7 < 16 ; V_7 ++ )
F_57 ( V_1 , F_106 ( V_7 ) ,
& V_1 -> V_192 [ V_7 ] ) ;
V_18 = F_72 ( V_1 , V_193 , V_171 ) ;
if ( V_18 )
goto V_194;
V_168 = 0 ;
for ( V_7 = 0 ; V_7 < V_43 -> V_131 ; V_7 ++ ) {
if ( V_43 -> V_132 [ V_7 ] . V_143 . V_144 == 's' )
V_168 |= F_71 ( V_43 -> V_132 [ V_7 ] . V_87 ) ;
}
V_18 = F_72 ( V_1 , F_107 ( 0 ) , V_168 ) ;
if ( V_18 )
goto V_194;
V_18 = F_72 ( V_1 , F_107 ( 1 ) ,
V_168 >> 16 ) ;
if ( V_18 )
goto V_194;
F_45 ( V_1 , V_112 , V_195 ,
V_195 ) ;
for ( V_7 = 0 ; V_7 < 16 ; V_7 ++ ) {
if ( V_7 % 8 < 4 || V_7 == 7 )
V_1 -> V_192 [ V_7 ] = 0xffff ;
else
V_1 -> V_192 [ V_7 ] = 0 ;
F_72 ( V_1 , F_106 ( V_7 ) ,
V_1 -> V_192 [ V_7 ] ) ;
}
F_70 ( V_43 ) ;
V_18 = F_108 ( V_43 ) ;
if ( V_18 )
goto V_194;
F_109 ( V_49 , V_43 ) ;
return 0 ;
V_194:
F_110 ( V_40 , V_43 ) ;
V_187:
if ( V_1 -> V_81 -> V_67 & V_181 )
F_67 ( V_1 -> V_185 ) ;
V_186:
if ( V_1 -> V_81 -> V_67 & V_181 )
F_67 ( V_1 -> V_110 ) ;
V_184:
if ( V_1 -> V_81 -> V_67 & V_181 )
F_111 ( V_43 ) ;
V_191:
F_112 ( V_1 -> V_56 ) ;
V_180:
F_51 ( V_43 -> V_132 ) ;
return V_18 ;
}
static int F_113 ( struct V_48 * V_49 )
{
struct V_42 * V_43 = F_114 ( V_49 ) ;
struct V_1 * V_1 = F_22 ( V_43 ) ;
int V_40 = F_91 ( V_49 , 0 ) ;
F_115 ( V_43 ) ;
if ( V_1 -> V_81 -> V_67 & V_181 ) {
F_67 ( V_1 -> V_185 ) ;
F_67 ( V_1 -> V_110 ) ;
F_111 ( V_43 ) ;
}
F_110 ( V_40 , V_43 ) ;
F_112 ( V_1 -> V_56 ) ;
F_116 ( & V_1 -> V_34 ) ;
F_51 ( V_1 -> V_84 ) ;
F_51 ( V_43 -> V_132 ) ;
return 0 ;
}
