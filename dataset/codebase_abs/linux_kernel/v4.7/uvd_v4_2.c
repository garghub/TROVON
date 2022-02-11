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
F_18 ( V_4 , 53300 , 40000 ) ;
V_9 = F_19 ( V_4 ) ;
if ( V_9 )
goto V_16;
V_2 -> V_17 = true ;
V_9 = F_20 ( V_2 ) ;
if ( V_9 ) {
V_2 -> V_17 = false ;
goto V_16;
}
V_9 = F_21 ( V_2 , 10 ) ;
if ( V_9 ) {
F_22 ( L_2 , V_9 ) ;
goto V_16;
}
V_15 = F_23 ( V_18 , 0 ) ;
F_24 ( V_2 , V_15 ) ;
F_24 ( V_2 , 0xFFFFF ) ;
V_15 = F_23 ( V_19 , 0 ) ;
F_24 ( V_2 , V_15 ) ;
F_24 ( V_2 , 0xFFFFF ) ;
V_15 = F_23 ( V_20 , 0 ) ;
F_24 ( V_2 , V_15 ) ;
F_24 ( V_2 , 0xFFFFF ) ;
F_24 ( V_2 , F_23 ( V_21 , 0 ) ) ;
F_24 ( V_2 , 0x8 ) ;
F_24 ( V_2 , F_23 ( V_22 , 0 ) ) ;
F_24 ( V_2 , 3 ) ;
F_25 ( V_2 ) ;
V_16:
F_18 ( V_4 , 0 , 0 ) ;
if ( ! V_9 )
F_26 ( L_3 ) ;
return V_9 ;
}
static int F_27 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
F_28 ( V_4 ) ;
V_2 -> V_17 = false ;
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
static int F_19 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
T_1 V_23 ;
int V_24 , V_25 , V_9 ;
T_2 V_26 = 0 ;
T_2 V_27 = 0 ;
F_31 ( V_4 ) ;
F_5 ( V_28 , 0 ) ;
F_32 ( V_29 , 0 , ~ ( 1 << 1 ) ) ;
F_32 ( V_30 , 1 << 8 , ~ ( 1 << 8 ) ) ;
F_33 ( 1 ) ;
F_5 ( V_31 , V_32 |
V_33 | V_34 |
V_35 | V_36 |
V_37 | V_38 |
V_39 ) ;
F_33 ( 5 ) ;
F_32 ( V_40 , 0 , ~ V_41 ) ;
F_33 ( 5 ) ;
F_5 ( V_42 , 0x40 | ( 1 << 8 ) | ( 1 << 13 ) |
( 1 << 21 ) | ( 1 << 9 ) | ( 1 << 20 ) ) ;
#ifdef F_34
V_26 = 0xa ;
V_27 = 0 ;
#endif
F_5 ( V_43 , V_26 ) ;
F_5 ( V_44 , V_27 ) ;
F_5 ( V_45 , 0x40c2040 ) ;
F_5 ( V_46 , 0x0 ) ;
F_5 ( V_47 , 0x40c2040 ) ;
F_5 ( V_48 , 0x0 ) ;
F_5 ( V_49 , 0 ) ;
F_5 ( V_50 , 0x88 ) ;
F_5 ( V_31 , V_33 ) ;
F_33 ( 5 ) ;
F_5 ( V_51 , 1 << 9 ) ;
F_32 ( V_30 , 0 , ~ ( 1 << 8 ) ) ;
F_5 ( V_31 , 0 ) ;
F_33 ( 10 ) ;
for ( V_24 = 0 ; V_24 < 10 ; ++ V_24 ) {
T_1 V_52 ;
for ( V_25 = 0 ; V_25 < 100 ; ++ V_25 ) {
V_52 = F_2 ( V_53 ) ;
if ( V_52 & 2 )
break;
F_33 ( 10 ) ;
}
V_9 = 0 ;
if ( V_52 & 2 )
break;
F_22 ( L_4 ) ;
F_32 ( V_31 , V_33 ,
~ V_33 ) ;
F_33 ( 10 ) ;
F_32 ( V_31 , 0 , ~ V_33 ) ;
F_33 ( 10 ) ;
V_9 = - 1 ;
}
if ( V_9 ) {
F_22 ( L_5 ) ;
return V_9 ;
}
F_32 ( V_29 , 3 << 1 , ~ ( 3 << 1 ) ) ;
F_5 ( V_54 , 0x11010101 ) ;
F_5 ( V_55 , 0 ) ;
F_5 ( V_56 , F_35 ( V_2 -> V_57 ) |
( 0x7 << 16 ) | ( 0x1 << 31 ) ) ;
F_5 ( V_5 , 0x0 ) ;
V_2 -> V_7 = F_2 ( V_5 ) ;
F_5 ( V_6 , V_2 -> V_7 ) ;
F_5 ( V_58 , V_2 -> V_57 ) ;
V_23 = F_36 ( V_2 -> V_59 ) ;
V_23 = ( 0x1 << 8 ) | V_23 ;
F_32 ( V_54 , V_23 , ~ 0x11f1f ) ;
return 0 ;
}
static void F_28 ( struct V_3 * V_4 )
{
F_5 ( V_54 , 0x11010101 ) ;
F_32 ( V_30 , 1 << 8 , ~ ( 1 << 8 ) ) ;
F_33 ( 1 ) ;
F_5 ( V_31 , V_33 ) ;
F_33 ( 5 ) ;
F_5 ( V_51 , 0x0 ) ;
F_32 ( V_30 , 0 , ~ ( 1 << 8 ) ) ;
}
static void F_37 ( struct V_1 * V_2 , T_3 V_60 , T_3 V_61 ,
unsigned V_62 )
{
F_38 ( V_62 & V_63 ) ;
F_24 ( V_2 , F_23 ( V_64 , 0 ) ) ;
F_24 ( V_2 , V_61 ) ;
F_24 ( V_2 , F_23 ( V_65 , 0 ) ) ;
F_24 ( V_2 , V_60 & 0xffffffff ) ;
F_24 ( V_2 , F_23 ( V_66 , 0 ) ) ;
F_24 ( V_2 , F_35 ( V_60 ) & 0xff ) ;
F_24 ( V_2 , F_23 ( V_67 , 0 ) ) ;
F_24 ( V_2 , 0 ) ;
F_24 ( V_2 , F_23 ( V_65 , 0 ) ) ;
F_24 ( V_2 , 0 ) ;
F_24 ( V_2 , F_23 ( V_66 , 0 ) ) ;
F_24 ( V_2 , 0 ) ;
F_24 ( V_2 , F_23 ( V_67 , 0 ) ) ;
F_24 ( V_2 , 2 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_15 = 0 ;
unsigned V_24 ;
int V_9 ;
F_5 ( V_64 , 0xCAFEDEAD ) ;
V_9 = F_21 ( V_2 , 3 ) ;
if ( V_9 ) {
F_22 ( L_6 ,
V_2 -> V_68 , V_9 ) ;
return V_9 ;
}
F_24 ( V_2 , F_23 ( V_64 , 0 ) ) ;
F_24 ( V_2 , 0xDEADBEEF ) ;
F_25 ( V_2 ) ;
for ( V_24 = 0 ; V_24 < V_4 -> V_69 ; V_24 ++ ) {
V_15 = F_2 ( V_64 ) ;
if ( V_15 == 0xDEADBEEF )
break;
F_40 ( 1 ) ;
}
if ( V_24 < V_4 -> V_69 ) {
F_26 ( L_7 ,
V_2 -> V_68 , V_24 ) ;
} else {
F_22 ( L_8 ,
V_2 -> V_68 , V_15 ) ;
V_9 = - V_70 ;
}
return V_9 ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_71 * V_72 ,
unsigned V_73 , bool V_74 )
{
F_24 ( V_2 , F_23 ( V_75 , 0 ) ) ;
F_24 ( V_2 , V_72 -> V_57 ) ;
F_24 ( V_2 , F_23 ( V_76 , 0 ) ) ;
F_24 ( V_2 , V_72 -> V_77 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_78 * V_78 = NULL ;
int V_9 ;
V_9 = F_18 ( V_4 , 53300 , 40000 ) ;
if ( V_9 ) {
F_22 ( L_9 , V_9 ) ;
return V_9 ;
}
V_9 = F_43 ( V_2 , 1 , NULL ) ;
if ( V_9 ) {
F_22 ( L_10 , V_9 ) ;
goto error;
}
V_9 = F_44 ( V_2 , 1 , true , & V_78 ) ;
if ( V_9 ) {
F_22 ( L_11 , V_9 ) ;
goto error;
}
V_9 = F_45 ( V_78 , false ) ;
if ( V_9 ) {
F_22 ( L_12 , V_9 ) ;
goto error;
}
F_26 ( L_13 , V_2 -> V_68 ) ;
error:
F_46 ( V_78 ) ;
F_18 ( V_4 , 0 , 0 ) ;
return V_9 ;
}
static void F_31 ( struct V_3 * V_4 )
{
T_4 V_60 ;
T_1 V_79 ;
V_60 = ( V_4 -> V_10 . V_57 + V_80 ) >> 3 ;
V_79 = F_47 ( V_4 -> V_10 . V_81 -> V_79 + 4 ) >> 3 ;
F_5 ( V_82 , V_60 ) ;
F_5 ( V_83 , V_79 ) ;
V_60 += V_79 ;
V_79 = V_84 >> 3 ;
F_5 ( V_85 , V_60 ) ;
F_5 ( V_86 , V_79 ) ;
V_60 += V_79 ;
V_79 = ( V_87 +
( V_88 * V_4 -> V_10 . V_89 ) ) >> 3 ;
F_5 ( V_90 , V_60 ) ;
F_5 ( V_91 , V_79 ) ;
V_60 = ( V_4 -> V_10 . V_57 >> 28 ) & 0xF ;
F_5 ( V_92 , ( V_60 << 12 ) | ( V_60 << 0 ) ) ;
V_60 = ( V_4 -> V_10 . V_57 >> 32 ) & 0xFF ;
F_5 ( V_56 , V_60 | ( 0x9 << 16 ) | ( 0x1 << 31 ) ) ;
F_5 ( V_93 , V_4 -> V_94 . V_95 . V_96 ) ;
F_5 ( V_97 , V_4 -> V_94 . V_95 . V_96 ) ;
F_5 ( V_98 , V_4 -> V_94 . V_95 . V_96 ) ;
F_48 ( V_4 ) ;
}
static void F_49 ( struct V_3 * V_4 ,
bool V_99 )
{
T_2 V_100 , V_101 ;
if ( V_99 && ( V_4 -> V_102 & V_103 ) ) {
V_101 = F_50 ( V_104 ) ;
V_101 = 0xfff ;
F_51 ( V_104 , V_101 ) ;
V_100 = V_101 = F_2 ( V_105 ) ;
V_101 |= V_106 ;
if ( V_100 != V_101 )
F_5 ( V_105 , V_101 ) ;
} else {
V_101 = F_50 ( V_104 ) ;
V_101 &= ~ 0xfff ;
F_51 ( V_104 , V_101 ) ;
V_100 = V_101 = F_2 ( V_105 ) ;
V_101 &= ~ V_106 ;
if ( V_100 != V_101 )
F_5 ( V_105 , V_101 ) ;
}
}
static void F_52 ( struct V_3 * V_4 ,
bool V_107 )
{
T_2 V_15 , V_108 ;
V_15 = F_2 ( V_105 ) ;
V_15 &= ~ ( V_109 | V_110 ) ;
V_15 |= V_106 |
( 1 << V_111 ) |
( 4 << V_112 ) ;
if ( V_107 ) {
V_15 &= ~ 0x7ffff800 ;
V_108 = V_113 |
V_114 |
( 7 << V_115 ) ;
} else {
V_15 |= 0x7ffff800 ;
V_108 = 0 ;
}
F_5 ( V_105 , V_15 ) ;
F_51 ( V_116 , V_108 ) ;
}
static void F_48 ( struct V_3 * V_4 )
{
bool V_117 = true ;
if ( V_117 ) {
F_52 ( V_4 , false ) ;
} else {
T_2 V_15 = F_2 ( V_105 ) ;
V_15 &= ~ V_106 ;
F_5 ( V_105 , V_15 ) ;
}
}
static bool F_53 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
return ! ( F_2 ( V_118 ) & V_119 ) ;
}
static int F_54 ( void * V_8 )
{
unsigned V_24 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
for ( V_24 = 0 ; V_24 < V_4 -> V_69 ; V_24 ++ ) {
if ( ! ( F_2 ( V_118 ) & V_119 ) )
return 0 ;
}
return - V_120 ;
}
static int F_55 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
F_28 ( V_4 ) ;
F_32 ( V_40 , V_41 ,
~ V_41 ) ;
F_33 ( 5 ) ;
return F_19 ( V_4 ) ;
}
static int F_56 ( struct V_3 * V_4 ,
struct V_121 * V_122 ,
unsigned type ,
enum V_123 V_124 )
{
return 0 ;
}
static int F_57 ( struct V_3 * V_4 ,
struct V_121 * V_122 ,
struct V_125 * V_126 )
{
F_58 ( L_14 ) ;
F_59 ( & V_4 -> V_10 . V_2 ) ;
return 0 ;
}
static int F_60 ( void * V_8 ,
enum V_127 V_124 )
{
bool V_128 = false ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( ! ( V_4 -> V_102 & V_103 ) )
return 0 ;
if ( V_124 == V_129 )
V_128 = true ;
F_49 ( V_4 , V_128 ) ;
return 0 ;
}
static int F_61 ( void * V_8 ,
enum V_130 V_124 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( ! ( V_4 -> V_131 & V_132 ) )
return 0 ;
if ( V_124 == V_133 ) {
F_28 ( V_4 ) ;
return 0 ;
} else {
return F_19 ( V_4 ) ;
}
}
static void F_7 ( struct V_3 * V_4 )
{
V_4 -> V_10 . V_2 . V_134 = & V_135 ;
}
static void F_8 ( struct V_3 * V_4 )
{
V_4 -> V_10 . V_11 . V_136 = 1 ;
V_4 -> V_10 . V_11 . V_134 = & V_137 ;
}
