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
V_9 = F_20 ( V_4 ) ;
if ( V_9 )
goto V_14;
V_2 -> V_15 = true ;
V_9 = F_21 ( V_2 ) ;
if ( V_9 ) {
V_2 -> V_15 = false ;
goto V_14;
}
V_9 = F_22 ( V_2 , 10 ) ;
if ( V_9 ) {
F_23 ( L_2 , V_9 ) ;
goto V_14;
}
V_13 = F_24 ( V_16 , 0 ) ;
F_25 ( V_2 , V_13 ) ;
F_25 ( V_2 , 0xFFFFF ) ;
V_13 = F_24 ( V_17 , 0 ) ;
F_25 ( V_2 , V_13 ) ;
F_25 ( V_2 , 0xFFFFF ) ;
V_13 = F_24 ( V_18 , 0 ) ;
F_25 ( V_2 , V_13 ) ;
F_25 ( V_2 , 0xFFFFF ) ;
F_25 ( V_2 , F_24 ( V_19 , 0 ) ) ;
F_25 ( V_2 , 0x8 ) ;
F_25 ( V_2 , F_24 ( V_20 , 0 ) ) ;
F_25 ( V_2 , 3 ) ;
F_26 ( V_2 ) ;
V_14:
if ( ! V_9 )
F_27 ( L_3 ) ;
return V_9 ;
}
static int F_28 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
F_29 ( V_4 ) ;
V_2 -> V_15 = false ;
return 0 ;
}
static int F_30 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_9 = F_28 ( V_4 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_15 ( V_4 ) ;
if ( V_9 )
return V_9 ;
return V_9 ;
}
static int F_31 ( void * V_8 )
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
static int F_20 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
T_1 V_21 ;
int V_22 , V_23 , V_9 ;
T_2 V_24 = 0 ;
T_2 V_25 = 0 ;
F_5 ( V_26 , 0 ) ;
F_32 ( V_4 , true ) ;
F_33 ( V_4 ) ;
F_34 ( V_27 , 0 , ~ ( 1 << 1 ) ) ;
F_34 ( V_28 , 1 << 8 , ~ ( 1 << 8 ) ) ;
F_35 ( 1 ) ;
F_5 ( V_29 , V_30 |
V_31 | V_32 |
V_33 | V_34 |
V_35 | V_36 |
V_37 ) ;
F_35 ( 5 ) ;
F_34 ( V_38 , 0 , ~ V_39 ) ;
F_35 ( 5 ) ;
F_5 ( V_40 , 0x40 | ( 1 << 8 ) | ( 1 << 13 ) |
( 1 << 21 ) | ( 1 << 9 ) | ( 1 << 20 ) ) ;
#ifdef F_36
V_24 = 0xa ;
V_25 = 0 ;
#endif
F_5 ( V_41 , V_24 ) ;
F_5 ( V_42 , V_25 ) ;
F_5 ( V_43 , 0x40c2040 ) ;
F_5 ( V_44 , 0x0 ) ;
F_5 ( V_45 , 0x40c2040 ) ;
F_5 ( V_46 , 0x0 ) ;
F_5 ( V_47 , 0 ) ;
F_5 ( V_48 , 0x88 ) ;
F_5 ( V_29 , V_31 ) ;
F_35 ( 5 ) ;
F_5 ( V_49 , 1 << 9 ) ;
F_34 ( V_28 , 0 , ~ ( 1 << 8 ) ) ;
F_5 ( V_29 , 0 ) ;
F_35 ( 10 ) ;
for ( V_22 = 0 ; V_22 < 10 ; ++ V_22 ) {
T_1 V_50 ;
for ( V_23 = 0 ; V_23 < 100 ; ++ V_23 ) {
V_50 = F_2 ( V_51 ) ;
if ( V_50 & 2 )
break;
F_35 ( 10 ) ;
}
V_9 = 0 ;
if ( V_50 & 2 )
break;
F_23 ( L_4 ) ;
F_34 ( V_29 , V_31 ,
~ V_31 ) ;
F_35 ( 10 ) ;
F_34 ( V_29 , 0 , ~ V_31 ) ;
F_35 ( 10 ) ;
V_9 = - 1 ;
}
if ( V_9 ) {
F_23 ( L_5 ) ;
return V_9 ;
}
F_34 ( V_27 , 3 << 1 , ~ ( 3 << 1 ) ) ;
F_5 ( V_52 , 0x11010101 ) ;
F_5 ( V_53 , 0 ) ;
F_5 ( V_54 , F_37 ( V_2 -> V_55 ) |
( 0x7 << 16 ) | ( 0x1 << 31 ) ) ;
F_5 ( V_5 , 0x0 ) ;
V_2 -> V_7 = F_2 ( V_5 ) ;
F_5 ( V_6 , V_2 -> V_7 ) ;
F_5 ( V_56 , V_2 -> V_55 ) ;
V_21 = F_38 ( V_2 -> V_57 ) ;
V_21 = ( 0x1 << 8 ) | V_21 ;
F_34 ( V_52 , V_21 , ~ 0x11f1f ) ;
return 0 ;
}
static void F_29 ( struct V_3 * V_4 )
{
F_5 ( V_52 , 0x11010101 ) ;
F_34 ( V_28 , 1 << 8 , ~ ( 1 << 8 ) ) ;
F_35 ( 1 ) ;
F_5 ( V_29 , V_31 ) ;
F_35 ( 5 ) ;
F_5 ( V_49 , 0x0 ) ;
F_34 ( V_28 , 0 , ~ ( 1 << 8 ) ) ;
F_32 ( V_4 , false ) ;
}
static void F_39 ( struct V_1 * V_2 , T_3 V_58 , T_3 V_59 ,
unsigned V_60 )
{
F_40 ( V_60 & V_61 ) ;
F_25 ( V_2 , F_24 ( V_62 , 0 ) ) ;
F_25 ( V_2 , V_59 ) ;
F_25 ( V_2 , F_24 ( V_63 , 0 ) ) ;
F_25 ( V_2 , V_58 & 0xffffffff ) ;
F_25 ( V_2 , F_24 ( V_64 , 0 ) ) ;
F_25 ( V_2 , F_37 ( V_58 ) & 0xff ) ;
F_25 ( V_2 , F_24 ( V_65 , 0 ) ) ;
F_25 ( V_2 , 0 ) ;
F_25 ( V_2 , F_24 ( V_63 , 0 ) ) ;
F_25 ( V_2 , 0 ) ;
F_25 ( V_2 , F_24 ( V_64 , 0 ) ) ;
F_25 ( V_2 , 0 ) ;
F_25 ( V_2 , F_24 ( V_65 , 0 ) ) ;
F_25 ( V_2 , 2 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
F_25 ( V_2 , F_24 ( V_66 , 0 ) ) ;
F_25 ( V_2 , 0 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_25 ( V_2 , F_24 ( V_67 , 0 ) ) ;
F_25 ( V_2 , 1 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_13 = 0 ;
unsigned V_22 ;
int V_9 ;
F_5 ( V_62 , 0xCAFEDEAD ) ;
V_9 = F_22 ( V_2 , 3 ) ;
if ( V_9 ) {
F_23 ( L_6 ,
V_2 -> V_68 , V_9 ) ;
return V_9 ;
}
F_25 ( V_2 , F_24 ( V_62 , 0 ) ) ;
F_25 ( V_2 , 0xDEADBEEF ) ;
F_26 ( V_2 ) ;
for ( V_22 = 0 ; V_22 < V_4 -> V_69 ; V_22 ++ ) {
V_13 = F_2 ( V_62 ) ;
if ( V_13 == 0xDEADBEEF )
break;
F_44 ( 1 ) ;
}
if ( V_22 < V_4 -> V_69 ) {
F_27 ( L_7 ,
V_2 -> V_68 , V_22 ) ;
} else {
F_23 ( L_8 ,
V_2 -> V_68 , V_13 ) ;
V_9 = - V_70 ;
}
return V_9 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_71 * V_72 ,
unsigned V_73 , bool V_74 )
{
F_25 ( V_2 , F_24 ( V_75 , 0 ) ) ;
F_25 ( V_2 , V_72 -> V_55 ) ;
F_25 ( V_2 , F_24 ( V_76 , 0 ) ) ;
F_25 ( V_2 , V_72 -> V_77 ) ;
}
static void F_33 ( struct V_3 * V_4 )
{
T_4 V_58 ;
T_1 V_78 ;
V_58 = ( V_4 -> V_10 . V_55 + V_79 ) >> 3 ;
V_78 = F_46 ( V_4 -> V_10 . V_80 -> V_78 + 4 ) >> 3 ;
F_5 ( V_81 , V_58 ) ;
F_5 ( V_82 , V_78 ) ;
V_58 += V_78 ;
V_78 = V_83 >> 3 ;
F_5 ( V_84 , V_58 ) ;
F_5 ( V_85 , V_78 ) ;
V_58 += V_78 ;
V_78 = ( V_86 +
( V_87 * V_4 -> V_10 . V_88 ) ) >> 3 ;
F_5 ( V_89 , V_58 ) ;
F_5 ( V_90 , V_78 ) ;
V_58 = ( V_4 -> V_10 . V_55 >> 28 ) & 0xF ;
F_5 ( V_91 , ( V_58 << 12 ) | ( V_58 << 0 ) ) ;
V_58 = ( V_4 -> V_10 . V_55 >> 32 ) & 0xFF ;
F_5 ( V_54 , V_58 | ( 0x9 << 16 ) | ( 0x1 << 31 ) ) ;
F_5 ( V_92 , V_4 -> V_93 . V_94 . V_95 ) ;
F_5 ( V_96 , V_4 -> V_93 . V_94 . V_95 ) ;
F_5 ( V_97 , V_4 -> V_93 . V_94 . V_95 ) ;
}
static void F_18 ( struct V_3 * V_4 ,
bool V_98 )
{
T_2 V_99 , V_100 ;
if ( V_98 && ( V_4 -> V_101 & V_102 ) ) {
V_100 = F_47 ( V_103 ) ;
V_100 |= 0xfff ;
F_48 ( V_103 , V_100 ) ;
V_99 = V_100 = F_2 ( V_104 ) ;
V_100 |= V_105 ;
if ( V_99 != V_100 )
F_5 ( V_104 , V_100 ) ;
} else {
V_100 = F_47 ( V_103 ) ;
V_100 &= ~ 0xfff ;
F_48 ( V_103 , V_100 ) ;
V_99 = V_100 = F_2 ( V_104 ) ;
V_100 &= ~ V_105 ;
if ( V_99 != V_100 )
F_5 ( V_104 , V_100 ) ;
}
}
static void F_32 ( struct V_3 * V_4 ,
bool V_106 )
{
T_2 V_13 , V_107 ;
F_49 ( V_108 , V_109 , 0 ) ;
V_13 = F_2 ( V_104 ) ;
V_13 &= ~ ( V_110 | V_111 ) ;
V_13 |= V_105 |
( 1 << V_112 ) |
( 4 << V_113 ) ;
if ( V_106 ) {
V_13 &= ~ 0x7ffff800 ;
V_107 = V_114 |
V_115 |
( 7 << V_116 ) ;
} else {
V_13 |= 0x7ffff800 ;
V_107 = 0 ;
}
F_5 ( V_104 , V_13 ) ;
F_48 ( V_117 , V_107 ) ;
}
static bool F_50 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
return ! ( F_2 ( V_118 ) & V_119 ) ;
}
static int F_51 ( void * V_8 )
{
unsigned V_22 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
for ( V_22 = 0 ; V_22 < V_4 -> V_69 ; V_22 ++ ) {
if ( ! ( F_2 ( V_118 ) & V_119 ) )
return 0 ;
}
return - V_120 ;
}
static int F_52 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
F_29 ( V_4 ) ;
F_34 ( V_38 , V_39 ,
~ V_39 ) ;
F_35 ( 5 ) ;
return F_20 ( V_4 ) ;
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
F_55 ( L_9 ) ;
F_56 ( & V_4 -> V_10 . V_2 ) ;
return 0 ;
}
static int F_57 ( void * V_8 ,
enum V_127 V_124 )
{
return 0 ;
}
static int F_58 ( void * V_8 ,
enum V_128 V_124 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( V_124 == V_129 ) {
F_29 ( V_4 ) ;
return 0 ;
} else {
return F_20 ( V_4 ) ;
}
}
static void F_7 ( struct V_3 * V_4 )
{
V_4 -> V_10 . V_2 . V_130 = & V_131 ;
}
static void F_8 ( struct V_3 * V_4 )
{
V_4 -> V_10 . V_11 . V_132 = 1 ;
V_4 -> V_10 . V_11 . V_130 = & V_133 ;
}
