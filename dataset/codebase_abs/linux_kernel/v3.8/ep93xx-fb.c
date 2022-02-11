static inline unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
unsigned int V_5 , unsigned int V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 ,
unsigned int V_5 , unsigned int V_6 )
{
F_3 ( V_2 , 0xaa , V_7 ) ;
F_3 ( V_2 , V_5 , V_6 ) ;
}
static void F_6 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_10 ;
unsigned int V_11 ;
V_11 = V_12 ;
V_11 |= V_2 -> V_13 -> V_14 ;
F_5 ( V_2 , V_11 , V_15 ) ;
}
static int F_7 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_10 ;
unsigned int V_5 ;
V_9 -> V_16 . V_17 . V_18 = 0 ;
V_9 -> V_16 . V_17 . V_19 = 0 ;
switch ( V_9 -> V_16 . V_20 ) {
case 8 :
V_5 = V_21 | V_22 |
V_23 ;
V_9 -> V_16 . V_24 . V_18 = 0 ;
V_9 -> V_16 . V_24 . V_19 = 8 ;
V_9 -> V_16 . V_25 . V_18 = 0 ;
V_9 -> V_16 . V_25 . V_19 = 8 ;
V_9 -> V_16 . V_26 . V_18 = 0 ;
V_9 -> V_16 . V_26 . V_19 = 8 ;
V_9 -> V_27 . V_28 = V_29 ;
break;
case 16 :
V_5 = V_30 | V_31 |
V_23 ;
V_9 -> V_16 . V_24 . V_18 = 11 ;
V_9 -> V_16 . V_24 . V_19 = 5 ;
V_9 -> V_16 . V_25 . V_18 = 5 ;
V_9 -> V_16 . V_25 . V_19 = 6 ;
V_9 -> V_16 . V_26 . V_18 = 0 ;
V_9 -> V_16 . V_26 . V_19 = 5 ;
V_9 -> V_27 . V_28 = V_32 ;
break;
case 24 :
V_5 = V_33 | V_34 |
V_35 ;
V_9 -> V_16 . V_24 . V_18 = 16 ;
V_9 -> V_16 . V_24 . V_19 = 8 ;
V_9 -> V_16 . V_25 . V_18 = 8 ;
V_9 -> V_16 . V_25 . V_19 = 8 ;
V_9 -> V_16 . V_26 . V_18 = 0 ;
V_9 -> V_16 . V_26 . V_19 = 8 ;
V_9 -> V_27 . V_28 = V_32 ;
break;
case 32 :
V_5 = V_36 | V_34 |
V_35 ;
V_9 -> V_16 . V_24 . V_18 = 16 ;
V_9 -> V_16 . V_24 . V_19 = 8 ;
V_9 -> V_16 . V_25 . V_18 = 8 ;
V_9 -> V_16 . V_25 . V_19 = 8 ;
V_9 -> V_16 . V_26 . V_18 = 0 ;
V_9 -> V_16 . V_26 . V_19 = 8 ;
V_9 -> V_27 . V_28 = V_32 ;
break;
default:
return - V_37 ;
}
F_3 ( V_2 , V_5 , V_38 ) ;
return 0 ;
}
static void F_8 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_10 ;
unsigned int V_39 , V_40 , V_41 , V_42 ;
V_39 = V_9 -> V_16 . V_43 + V_9 -> V_16 . V_44 +
V_9 -> V_16 . V_45 + V_9 -> V_16 . V_46 - 1 ;
V_40 = V_9 -> V_16 . V_47 + V_9 -> V_16 . V_48 +
V_9 -> V_16 . V_49 + V_9 -> V_16 . V_50 - 1 ;
F_5 ( V_2 , V_39 , V_51 ) ;
F_5 ( V_2 , V_40 , V_52 ) ;
V_41 = V_39 ;
V_42 = V_39 - V_9 -> V_16 . V_46 ;
F_5 ( V_2 , V_41 | ( V_42 << 16 ) , V_53 ) ;
V_41 = V_39 - V_9 -> V_16 . V_46 - V_9 -> V_16 . V_44 ;
V_42 = V_9 -> V_16 . V_45 - 1 ;
F_5 ( V_2 , V_41 | ( V_42 << 16 ) , V_54 ) ;
F_5 ( V_2 , V_41 | ( V_42 << 16 ) , V_55 ) ;
V_41 = V_39 ;
V_42 = V_39 + 1 ;
F_5 ( V_2 , V_41 | ( V_42 << 16 ) , V_56 ) ;
V_41 = V_40 ;
V_42 = V_40 - V_9 -> V_16 . V_50 ;
F_5 ( V_2 , V_41 | ( V_42 << 16 ) , V_57 ) ;
V_41 = V_40 - V_9 -> V_16 . V_50 - V_9 -> V_16 . V_48 ;
V_42 = V_9 -> V_16 . V_49 - 1 ;
F_5 ( V_2 , V_41 | ( V_42 << 16 ) , V_58 ) ;
F_5 ( V_2 , V_41 | ( V_42 << 16 ) , V_59 ) ;
V_41 = V_40 ;
V_42 = V_40 ;
F_5 ( V_2 , V_41 | ( V_42 << 16 ) , V_60 ) ;
F_5 ( V_2 , 0x0 , V_61 ) ;
}
static int F_9 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_10 ;
F_10 ( V_2 -> V_62 , 1000 * F_11 ( V_9 -> V_16 . V_63 ) ) ;
F_8 ( V_9 ) ;
V_9 -> V_27 . V_64 = V_9 -> V_16 . V_65 *
V_9 -> V_16 . V_20 / 8 ;
F_3 ( V_2 , V_9 -> V_27 . V_66 , V_67 ) ;
F_3 ( V_2 , V_9 -> V_16 . V_43 - 1 , V_68 ) ;
F_3 ( V_2 , ( ( V_9 -> V_16 . V_47 * V_9 -> V_16 . V_20 )
/ 32 ) - 1 , V_69 ) ;
F_3 ( V_2 , V_9 -> V_27 . V_64 / 4 , V_70 ) ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_12 ( struct V_71 * V_16 ,
struct V_8 * V_9 )
{
int V_72 ;
V_72 = F_7 ( V_9 ) ;
if ( V_72 )
return V_72 ;
V_16 -> V_47 = F_13 (unsigned int, var->xres, EP93XXFB_MIN_XRES) ;
V_16 -> V_47 = F_14 (unsigned int, var->xres, EP93XXFB_MAX_XRES) ;
V_16 -> V_65 = F_15 ( V_16 -> V_65 , V_16 -> V_47 ) ;
V_16 -> V_43 = F_13 (unsigned int, var->yres, EP93XXFB_MIN_YRES) ;
V_16 -> V_43 = F_14 (unsigned int, var->yres, EP93XXFB_MAX_YRES) ;
V_16 -> V_73 = F_15 ( V_16 -> V_73 , V_16 -> V_43 ) ;
return 0 ;
}
static int F_16 ( struct V_8 * V_9 , struct V_74 * V_75 )
{
unsigned int V_18 = V_75 -> V_76 << V_77 ;
if ( V_18 < V_9 -> V_27 . V_78 ) {
return F_17 ( V_9 -> V_79 , V_75 , V_9 -> V_80 ,
V_9 -> V_27 . V_66 ,
V_9 -> V_27 . V_78 ) ;
}
return - V_37 ;
}
static int F_18 ( int V_81 , struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_10 ;
unsigned int V_11 = F_1 ( V_2 , V_15 ) ;
if ( V_81 ) {
if ( V_2 -> V_13 -> V_82 )
V_2 -> V_13 -> V_82 ( V_81 , V_9 ) ;
F_5 ( V_2 , V_11 & ~ V_12 ,
V_15 ) ;
F_19 ( V_2 -> V_62 ) ;
} else {
F_20 ( V_2 -> V_62 ) ;
F_5 ( V_2 , V_11 | V_12 ,
V_15 ) ;
if ( V_2 -> V_13 -> V_82 )
V_2 -> V_13 -> V_82 ( V_81 , V_9 ) ;
}
return 0 ;
}
static inline int F_21 ( int V_5 , int V_83 )
{
return ( ( V_5 << V_83 ) + 0x7fff - V_5 ) >> 16 ;
}
static int F_22 ( unsigned int V_84 , unsigned int V_24 ,
unsigned int V_25 , unsigned int V_26 ,
unsigned int V_17 , struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_10 ;
unsigned int * V_85 = V_9 -> V_86 ;
unsigned int V_87 , V_88 , V_89 , V_90 , V_91 ;
switch ( V_9 -> V_27 . V_28 ) {
case V_29 :
if ( V_84 > 255 )
return 1 ;
V_89 = ( ( V_24 & 0xff00 ) << 8 ) | ( V_25 & 0xff00 ) |
( ( V_26 & 0xff00 ) >> 8 ) ;
V_85 [ V_84 ] = V_89 ;
F_3 ( V_2 , V_89 , ( V_92 + ( V_84 << 2 ) ) ) ;
V_87 = F_1 ( V_2 , V_93 ) ;
V_91 = ! ! ( V_87 & V_94 ) ;
V_90 = ! ! ( V_87 & V_95 ) ;
if ( V_91 == V_90 ) {
for ( V_88 = 0 ; V_88 < 256 ; V_88 ++ ) {
F_3 ( V_2 , V_85 [ V_88 ] ,
V_92 + ( V_88 << 2 ) ) ;
}
F_3 ( V_2 ,
V_87 ^ V_95 ,
V_93 ) ;
}
break;
case V_32 :
if ( V_84 > 16 )
return 1 ;
V_24 = F_21 ( V_24 , V_9 -> V_16 . V_24 . V_19 ) ;
V_25 = F_21 ( V_25 , V_9 -> V_16 . V_25 . V_19 ) ;
V_26 = F_21 ( V_26 , V_9 -> V_16 . V_26 . V_19 ) ;
V_17 = F_21 ( V_17 ,
V_9 -> V_16 . V_17 . V_19 ) ;
V_85 [ V_84 ] = ( V_24 << V_9 -> V_16 . V_24 . V_18 ) |
( V_25 << V_9 -> V_16 . V_25 . V_18 ) |
( V_26 << V_9 -> V_16 . V_26 . V_18 ) |
( V_17 << V_9 -> V_16 . V_17 . V_18 ) ;
break;
default:
return 1 ;
}
return 0 ;
}
static int T_1 F_23 ( struct V_96 * V_13 )
{
int V_88 , V_97 = 0 ;
if ( V_13 -> V_98 == V_99 ) {
V_97 = V_100 * V_101 *
V_13 -> V_102 / 8 ;
} else {
for ( V_88 = 0 ; V_88 < V_13 -> V_98 ; V_88 ++ ) {
const struct V_103 * V_104 ;
int V_105 ;
V_104 = & V_13 -> V_106 [ V_88 ] ;
V_105 = V_104 -> V_47 * V_104 -> V_43 * V_13 -> V_102 / 8 ;
if ( V_105 > V_97 )
V_97 = V_105 ;
}
}
return V_97 ;
}
static int T_1 F_24 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_10 ;
char T_2 * V_107 ;
T_3 V_108 ;
unsigned int V_97 ;
V_97 = F_23 ( V_2 -> V_13 ) ;
V_107 = F_25 ( V_9 -> V_79 , V_97 ,
& V_108 , V_109 ) ;
if ( ! V_107 )
return - V_110 ;
if ( V_111 && V_108 & ( 1 << 27 ) ) {
F_26 ( V_9 -> V_79 , L_1
L_2 ,
V_108 ) ;
F_27 ( V_9 -> V_79 , V_97 , V_107 , V_108 ) ;
return - V_110 ;
}
V_9 -> V_27 . V_66 = V_108 ;
V_9 -> V_27 . V_78 = V_97 ;
V_9 -> V_80 = V_107 ;
return 0 ;
}
static void F_28 ( struct V_8 * V_9 )
{
if ( V_9 -> V_80 )
F_27 ( V_9 -> V_79 , V_9 -> V_27 . V_78 ,
V_9 -> V_80 , V_9 -> V_27 . V_66 ) ;
}
static int F_29 ( struct V_112 * V_113 )
{
struct V_96 * V_13 = V_113 -> V_79 . V_114 ;
struct V_8 * V_9 ;
struct V_1 * V_2 ;
struct V_115 * V_116 ;
char * V_117 ;
int V_72 ;
if ( ! V_13 )
return - V_37 ;
V_9 = F_30 ( sizeof( struct V_1 ) , & V_113 -> V_79 ) ;
if ( ! V_9 )
return - V_110 ;
V_9 -> V_79 = & V_113 -> V_79 ;
F_31 ( V_113 , V_9 ) ;
V_2 = V_9 -> V_10 ;
V_2 -> V_13 = V_13 ;
V_72 = F_32 ( & V_9 -> V_118 , 256 , 0 ) ;
if ( V_72 )
goto V_119;
V_72 = F_24 ( V_9 ) ;
if ( V_72 )
goto V_120;
V_116 = F_33 ( V_113 , V_121 , 0 ) ;
if ( ! V_116 ) {
V_72 = - V_122 ;
goto V_123;
}
V_2 -> V_116 = V_116 ;
V_2 -> V_4 = F_34 ( & V_113 -> V_79 , V_116 -> V_41 ,
F_35 ( V_116 ) ) ;
if ( ! V_2 -> V_4 ) {
V_72 = - V_122 ;
goto V_123;
}
strcpy ( V_9 -> V_27 . V_124 , V_113 -> V_125 ) ;
V_9 -> V_126 = & V_127 ;
V_9 -> V_27 . type = V_128 ;
V_9 -> V_27 . V_129 = V_130 ;
V_9 -> V_16 . V_131 = V_132 ;
V_9 -> V_16 . V_133 = V_134 ;
V_9 -> V_14 = V_135 ;
V_9 -> V_136 = - 1 ;
V_9 -> V_137 = V_138 ;
V_9 -> V_86 = & V_2 -> V_86 ;
F_36 ( L_3 , & V_117 ) ;
V_72 = F_37 ( & V_9 -> V_16 , V_9 , V_117 ,
V_2 -> V_13 -> V_106 , V_2 -> V_13 -> V_98 ,
V_2 -> V_13 -> V_139 , V_2 -> V_13 -> V_102 ) ;
if ( V_72 == 0 ) {
F_26 ( V_9 -> V_79 , L_4 ) ;
V_72 = - V_37 ;
goto V_123;
}
if ( V_13 -> V_140 ) {
V_72 = V_13 -> V_140 ( V_113 ) ;
if ( V_72 )
goto V_123;
}
V_72 = F_12 ( & V_9 -> V_16 , V_9 ) ;
if ( V_72 )
goto V_141;
V_2 -> V_62 = F_38 ( & V_113 -> V_79 , NULL ) ;
if ( F_39 ( V_2 -> V_62 ) ) {
V_72 = F_40 ( V_2 -> V_62 ) ;
V_2 -> V_62 = NULL ;
goto V_141;
}
F_9 ( V_9 ) ;
F_20 ( V_2 -> V_62 ) ;
V_72 = F_41 ( V_9 ) ;
if ( V_72 )
goto V_141;
F_42 ( V_9 -> V_79 , L_5 ,
V_9 -> V_16 . V_47 , V_9 -> V_16 . V_43 , V_9 -> V_16 . V_20 ) ;
return 0 ;
V_141:
if ( V_2 -> V_13 -> V_142 )
V_2 -> V_13 -> V_142 ( V_113 ) ;
V_123:
F_28 ( V_9 ) ;
V_120:
F_43 ( & V_9 -> V_118 ) ;
V_119:
F_44 ( V_9 ) ;
F_31 ( V_113 , NULL ) ;
return V_72 ;
}
static int F_45 ( struct V_112 * V_113 )
{
struct V_8 * V_9 = F_46 ( V_113 ) ;
struct V_1 * V_2 = V_9 -> V_10 ;
F_47 ( V_9 ) ;
F_19 ( V_2 -> V_62 ) ;
F_28 ( V_9 ) ;
F_43 ( & V_9 -> V_118 ) ;
if ( V_2 -> V_13 -> V_142 )
V_2 -> V_13 -> V_142 ( V_113 ) ;
F_44 ( V_9 ) ;
F_31 ( V_113 , NULL ) ;
return 0 ;
}
static int F_48 ( void )
{
return F_49 ( & V_143 ) ;
}
static void T_4 F_50 ( void )
{
F_51 ( & V_143 ) ;
}
