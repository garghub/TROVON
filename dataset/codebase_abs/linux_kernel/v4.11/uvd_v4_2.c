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
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
int V_9 ;
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
V_9 = F_13 ( V_4 , V_2 , 512 , & V_4 -> V_10 . V_11 , 0 ) ;
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
T_1 V_13 ;
int V_9 ;
F_18 ( V_4 , true ) ;
F_19 ( V_4 , 10000 , 10000 ) ;
V_2 -> V_14 = true ;
V_9 = F_20 ( V_2 ) ;
if ( V_9 ) {
V_2 -> V_14 = false ;
goto V_15;
}
V_9 = F_21 ( V_2 , 10 ) ;
if ( V_9 ) {
F_22 ( L_2 , V_9 ) ;
goto V_15;
}
V_13 = F_23 ( V_16 , 0 ) ;
F_24 ( V_2 , V_13 ) ;
F_24 ( V_2 , 0xFFFFF ) ;
V_13 = F_23 ( V_17 , 0 ) ;
F_24 ( V_2 , V_13 ) ;
F_24 ( V_2 , 0xFFFFF ) ;
V_13 = F_23 ( V_18 , 0 ) ;
F_24 ( V_2 , V_13 ) ;
F_24 ( V_2 , 0xFFFFF ) ;
F_24 ( V_2 , F_23 ( V_19 , 0 ) ) ;
F_24 ( V_2 , 0x8 ) ;
F_24 ( V_2 , F_23 ( V_20 , 0 ) ) ;
F_24 ( V_2 , 3 ) ;
F_25 ( V_2 ) ;
V_15:
if ( ! V_9 )
F_26 ( L_3 ) ;
return V_9 ;
}
static int F_27 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
if ( F_2 ( V_21 ) != 0 )
F_28 ( V_4 ) ;
V_2 -> V_14 = false ;
return 0 ;
}
static int F_29 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_9 = F_27 ( V_4 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_15 ( V_4 ) ;
if ( V_9 )
return V_9 ;
return V_9 ;
}
static int F_30 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_9 = F_12 ( V_4 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_17 ( V_4 ) ;
if ( V_9 )
return V_9 ;
return V_9 ;
}
static int F_31 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
T_1 V_22 ;
int V_23 , V_24 , V_9 ;
T_2 V_13 ;
T_2 V_25 = 0 ;
T_2 V_26 = 0 ;
F_32 ( V_21 , 1 << 2 , ~ ( 1 << 2 ) ) ;
F_33 ( V_4 , true ) ;
F_5 ( V_27 , 0 ) ;
F_32 ( V_28 , 0 , ~ V_29 ) ;
F_34 ( 5 ) ;
F_5 ( V_30 , 1 << 9 ) ;
F_32 ( V_31 , 0 , ~ ( 1 << 1 ) ) ;
#ifdef F_35
V_25 = 0xa ;
V_26 = 0 ;
#endif
F_5 ( V_32 , V_25 ) ;
F_5 ( V_33 , V_26 ) ;
F_5 ( V_34 , 0x203108 ) ;
V_13 = F_2 ( V_35 ) ;
F_5 ( V_35 , V_13 | 0x10 ) ;
F_5 ( V_36 , 0x40c2040 ) ;
F_5 ( V_37 , 0x0 ) ;
F_5 ( V_38 , 0x40c2040 ) ;
F_5 ( V_39 , 0x0 ) ;
F_5 ( V_40 , 0 ) ;
F_5 ( V_41 , 0x88 ) ;
F_36 ( V_4 ) ;
V_13 = F_37 ( V_42 ) ;
F_38 ( V_42 , V_13 & ( ~ 0x10 ) ) ;
F_32 ( V_43 , 0 , ~ ( 1 << 8 ) ) ;
F_32 ( V_44 , 0 , ~ V_45 ) ;
F_32 ( V_44 , 0 , ~ V_46 ) ;
F_32 ( V_44 , 0 , ~ V_47 ) ;
F_34 ( 10 ) ;
for ( V_23 = 0 ; V_23 < 10 ; ++ V_23 ) {
T_1 V_48 ;
for ( V_24 = 0 ; V_24 < 100 ; ++ V_24 ) {
V_48 = F_2 ( V_21 ) ;
if ( V_48 & 2 )
break;
F_34 ( 10 ) ;
}
V_9 = 0 ;
if ( V_48 & 2 )
break;
F_22 ( L_4 ) ;
F_32 ( V_44 , V_47 ,
~ V_47 ) ;
F_34 ( 10 ) ;
F_32 ( V_44 , 0 , ~ V_47 ) ;
F_34 ( 10 ) ;
V_9 = - 1 ;
}
if ( V_9 ) {
F_22 ( L_5 ) ;
return V_9 ;
}
F_32 ( V_31 , 3 << 1 , ~ ( 3 << 1 ) ) ;
F_32 ( V_21 , 0 , ~ ( 1 << 2 ) ) ;
F_5 ( V_49 , 0x11010101 ) ;
F_5 ( V_50 , 0 ) ;
F_5 ( V_51 , F_39 ( V_2 -> V_52 ) |
( 0x7 << 16 ) | ( 0x1 << 31 ) ) ;
F_5 ( V_5 , 0x0 ) ;
V_2 -> V_7 = F_2 ( V_5 ) ;
F_5 ( V_6 , V_2 -> V_7 ) ;
F_5 ( V_53 , V_2 -> V_52 ) ;
V_22 = F_40 ( V_2 -> V_54 ) ;
V_22 = ( 0x1 << 8 ) | V_22 ;
F_32 ( V_49 , V_22 , ~ 0x11f1f ) ;
return 0 ;
}
static void F_28 ( struct V_3 * V_4 )
{
T_1 V_23 , V_24 ;
T_1 V_48 ;
F_5 ( V_49 , 0x11010101 ) ;
for ( V_23 = 0 ; V_23 < 10 ; ++ V_23 ) {
for ( V_24 = 0 ; V_24 < 100 ; ++ V_24 ) {
V_48 = F_2 ( V_21 ) ;
if ( V_48 & 2 )
break;
F_34 ( 1 ) ;
}
if ( V_48 & 2 )
break;
}
for ( V_23 = 0 ; V_23 < 10 ; ++ V_23 ) {
for ( V_24 = 0 ; V_24 < 100 ; ++ V_24 ) {
V_48 = F_2 ( V_55 ) ;
if ( V_48 & 0xf )
break;
F_34 ( 1 ) ;
}
if ( V_48 & 0xf )
break;
}
F_32 ( V_43 , 1 << 8 , ~ ( 1 << 8 ) ) ;
for ( V_23 = 0 ; V_23 < 10 ; ++ V_23 ) {
for ( V_24 = 0 ; V_24 < 100 ; ++ V_24 ) {
V_48 = F_2 ( V_55 ) ;
if ( V_48 & 0x240 )
break;
F_34 ( 1 ) ;
}
if ( V_48 & 0x240 )
break;
}
F_32 ( 0x3D49 , 0 , ~ ( 1 << 2 ) ) ;
F_32 ( V_30 , 0 , ~ ( 1 << 9 ) ) ;
F_5 ( V_44 , V_45 |
V_47 |
V_46 ) ;
F_5 ( V_21 , 0 ) ;
F_33 ( V_4 , false ) ;
}
static void F_41 ( struct V_1 * V_2 , T_3 V_56 , T_3 V_57 ,
unsigned V_58 )
{
F_42 ( V_58 & V_59 ) ;
F_24 ( V_2 , F_23 ( V_60 , 0 ) ) ;
F_24 ( V_2 , V_57 ) ;
F_24 ( V_2 , F_23 ( V_61 , 0 ) ) ;
F_24 ( V_2 , V_56 & 0xffffffff ) ;
F_24 ( V_2 , F_23 ( V_62 , 0 ) ) ;
F_24 ( V_2 , F_39 ( V_56 ) & 0xff ) ;
F_24 ( V_2 , F_23 ( V_63 , 0 ) ) ;
F_24 ( V_2 , 0 ) ;
F_24 ( V_2 , F_23 ( V_61 , 0 ) ) ;
F_24 ( V_2 , 0 ) ;
F_24 ( V_2 , F_23 ( V_62 , 0 ) ) ;
F_24 ( V_2 , 0 ) ;
F_24 ( V_2 , F_23 ( V_63 , 0 ) ) ;
F_24 ( V_2 , 2 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_24 ( V_2 , F_23 ( V_64 , 0 ) ) ;
F_24 ( V_2 , 0 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_24 ( V_2 , F_23 ( V_65 , 0 ) ) ;
F_24 ( V_2 , 1 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_13 = 0 ;
unsigned V_23 ;
int V_9 ;
F_5 ( V_60 , 0xCAFEDEAD ) ;
V_9 = F_21 ( V_2 , 3 ) ;
if ( V_9 ) {
F_22 ( L_6 ,
V_2 -> V_66 , V_9 ) ;
return V_9 ;
}
F_24 ( V_2 , F_23 ( V_60 , 0 ) ) ;
F_24 ( V_2 , 0xDEADBEEF ) ;
F_25 ( V_2 ) ;
for ( V_23 = 0 ; V_23 < V_4 -> V_67 ; V_23 ++ ) {
V_13 = F_2 ( V_60 ) ;
if ( V_13 == 0xDEADBEEF )
break;
F_46 ( 1 ) ;
}
if ( V_23 < V_4 -> V_67 ) {
F_26 ( L_7 ,
V_2 -> V_66 , V_23 ) ;
} else {
F_22 ( L_8 ,
V_2 -> V_66 , V_13 ) ;
V_9 = - V_68 ;
}
return V_9 ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
unsigned V_71 , bool V_72 )
{
F_24 ( V_2 , F_23 ( V_73 , 0 ) ) ;
F_24 ( V_2 , V_70 -> V_52 ) ;
F_24 ( V_2 , F_23 ( V_74 , 0 ) ) ;
F_24 ( V_2 , V_70 -> V_75 ) ;
}
static void F_36 ( struct V_3 * V_4 )
{
T_4 V_56 ;
T_1 V_76 ;
V_56 = ( V_4 -> V_10 . V_52 + V_77 ) >> 3 ;
V_76 = F_48 ( V_4 -> V_10 . V_78 -> V_76 + 4 ) >> 3 ;
F_5 ( V_79 , V_56 ) ;
F_5 ( V_80 , V_76 ) ;
V_56 += V_76 ;
V_76 = V_81 >> 3 ;
F_5 ( V_82 , V_56 ) ;
F_5 ( V_83 , V_76 ) ;
V_56 += V_76 ;
V_76 = ( V_84 +
( V_85 * V_4 -> V_10 . V_86 ) ) >> 3 ;
F_5 ( V_87 , V_56 ) ;
F_5 ( V_88 , V_76 ) ;
V_56 = ( V_4 -> V_10 . V_52 >> 28 ) & 0xF ;
F_5 ( V_89 , ( V_56 << 12 ) | ( V_56 << 0 ) ) ;
V_56 = ( V_4 -> V_10 . V_52 >> 32 ) & 0xFF ;
F_5 ( V_51 , V_56 | ( 0x9 << 16 ) | ( 0x1 << 31 ) ) ;
F_5 ( V_90 , V_4 -> V_91 . V_92 . V_93 ) ;
F_5 ( V_94 , V_4 -> V_91 . V_92 . V_93 ) ;
F_5 ( V_95 , V_4 -> V_91 . V_92 . V_93 ) ;
}
static void F_18 ( struct V_3 * V_4 ,
bool V_96 )
{
T_2 V_97 , V_98 ;
if ( V_96 && ( V_4 -> V_99 & V_100 ) ) {
V_98 = F_37 ( V_101 ) ;
V_98 |= 0xfff ;
F_38 ( V_101 , V_98 ) ;
V_97 = V_98 = F_2 ( V_102 ) ;
V_98 |= V_103 ;
if ( V_97 != V_98 )
F_5 ( V_102 , V_98 ) ;
} else {
V_98 = F_37 ( V_101 ) ;
V_98 &= ~ 0xfff ;
F_38 ( V_101 , V_98 ) ;
V_97 = V_98 = F_2 ( V_102 ) ;
V_98 &= ~ V_103 ;
if ( V_97 != V_98 )
F_5 ( V_102 , V_98 ) ;
}
}
static void F_33 ( struct V_3 * V_4 ,
bool V_104 )
{
T_2 V_13 , V_105 ;
F_49 ( V_106 , V_107 , 0 ) ;
V_13 = F_2 ( V_102 ) ;
V_13 &= ~ ( V_108 | V_109 ) ;
V_13 |= V_103 |
( 1 << V_110 ) |
( 4 << V_111 ) ;
if ( V_104 ) {
V_13 &= ~ 0x7ffff800 ;
V_105 = V_112 |
V_113 |
( 7 << V_114 ) ;
} else {
V_13 |= 0x7ffff800 ;
V_105 = 0 ;
}
F_5 ( V_102 , V_13 ) ;
F_38 ( V_115 , V_105 ) ;
}
static bool F_50 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
return ! ( F_2 ( V_116 ) & V_117 ) ;
}
static int F_51 ( void * V_8 )
{
unsigned V_23 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
for ( V_23 = 0 ; V_23 < V_4 -> V_67 ; V_23 ++ ) {
if ( ! ( F_2 ( V_116 ) & V_117 ) )
return 0 ;
}
return - V_118 ;
}
static int F_52 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
F_28 ( V_4 ) ;
F_32 ( V_28 , V_29 ,
~ V_29 ) ;
F_34 ( 5 ) ;
return F_31 ( V_4 ) ;
}
static int F_53 ( struct V_3 * V_4 ,
struct V_119 * V_120 ,
unsigned type ,
enum V_121 V_122 )
{
return 0 ;
}
static int F_54 ( struct V_3 * V_4 ,
struct V_119 * V_120 ,
struct V_123 * V_124 )
{
F_55 ( L_9 ) ;
F_56 ( & V_4 -> V_10 . V_2 ) ;
return 0 ;
}
static int F_57 ( void * V_8 ,
enum V_125 V_122 )
{
return 0 ;
}
static int F_58 ( void * V_8 ,
enum V_126 V_122 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( V_122 == V_127 ) {
F_28 ( V_4 ) ;
if ( V_4 -> V_128 & V_129 && V_130 == 0 ) {
if ( ! ( F_59 ( V_131 ) &
V_132 ) ) {
F_5 ( V_133 , ( V_134 |
V_135 |
V_136 ) ) ;
F_34 ( 20 ) ;
}
}
return 0 ;
} else {
if ( V_4 -> V_128 & V_129 && V_130 == 0 ) {
if ( F_59 ( V_131 ) &
V_132 ) {
F_5 ( V_133 , ( V_134 |
V_137 |
V_136 ) ) ;
F_34 ( 30 ) ;
}
}
return F_31 ( V_4 ) ;
}
}
static void F_7 ( struct V_3 * V_4 )
{
V_4 -> V_10 . V_2 . V_138 = & V_139 ;
}
static void F_8 ( struct V_3 * V_4 )
{
V_4 -> V_10 . V_11 . V_140 = 1 ;
V_4 -> V_10 . V_11 . V_138 = & V_141 ;
}
