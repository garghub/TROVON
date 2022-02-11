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
F_5 ( V_6 , F_6 ( V_2 -> V_7 ) ) ;
}
static int F_7 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
F_8 ( V_4 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_10 ( void * V_8 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
int V_9 ;
V_9 = F_11 ( V_4 , V_10 , 124 , & V_4 -> V_11 . V_12 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_12 ( V_4 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_13 ( V_4 ) ;
if ( V_9 )
return V_9 ;
V_2 = & V_4 -> V_11 . V_2 ;
sprintf ( V_2 -> V_13 , L_1 ) ;
V_9 = F_14 ( V_4 , V_2 , 512 , & V_4 -> V_11 . V_12 , 0 ) ;
return V_9 ;
}
static int F_15 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_9 = F_16 ( V_4 ) ;
if ( V_9 )
return V_9 ;
return F_17 ( V_4 ) ;
}
static int F_18 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
struct V_1 * V_2 = & V_4 -> V_11 . V_2 ;
T_2 V_14 ;
int V_9 ;
F_19 ( V_4 , true ) ;
F_20 ( V_4 , 10000 , 10000 ) ;
V_2 -> V_15 = true ;
V_9 = F_21 ( V_2 ) ;
if ( V_9 ) {
V_2 -> V_15 = false ;
goto V_16;
}
V_9 = F_22 ( V_2 , 10 ) ;
if ( V_9 ) {
F_23 ( L_2 , V_9 ) ;
goto V_16;
}
V_14 = F_24 ( V_17 , 0 ) ;
F_25 ( V_2 , V_14 ) ;
F_25 ( V_2 , 0xFFFFF ) ;
V_14 = F_24 ( V_18 , 0 ) ;
F_25 ( V_2 , V_14 ) ;
F_25 ( V_2 , 0xFFFFF ) ;
V_14 = F_24 ( V_19 , 0 ) ;
F_25 ( V_2 , V_14 ) ;
F_25 ( V_2 , 0xFFFFF ) ;
F_25 ( V_2 , F_24 ( V_20 , 0 ) ) ;
F_25 ( V_2 , 0x8 ) ;
F_25 ( V_2 , F_24 ( V_21 , 0 ) ) ;
F_25 ( V_2 , 3 ) ;
F_26 ( V_2 ) ;
V_16:
if ( ! V_9 )
F_27 ( L_3 ) ;
return V_9 ;
}
static int F_28 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
struct V_1 * V_2 = & V_4 -> V_11 . V_2 ;
if ( F_2 ( V_22 ) != 0 )
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
return F_16 ( V_4 ) ;
}
static int F_31 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_9 = F_13 ( V_4 ) ;
if ( V_9 )
return V_9 ;
return F_18 ( V_4 ) ;
}
static int F_32 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_11 . V_2 ;
T_2 V_23 ;
int V_24 , V_25 , V_9 ;
T_3 V_14 ;
T_3 V_26 = 0 ;
T_3 V_27 = 0 ;
F_33 ( V_22 , 1 << 2 , ~ ( 1 << 2 ) ) ;
F_34 ( V_4 , true ) ;
F_5 ( V_28 , 0 ) ;
F_33 ( V_29 , 0 , ~ V_30 ) ;
F_35 ( 5 ) ;
F_5 ( V_31 , 1 << 9 ) ;
F_33 ( V_32 , 0 , ~ ( 1 << 1 ) ) ;
#ifdef F_36
V_26 = 0xa ;
V_27 = 0 ;
#endif
F_5 ( V_33 , V_26 ) ;
F_5 ( V_34 , V_27 ) ;
F_5 ( V_35 , 0x203108 ) ;
V_14 = F_2 ( V_36 ) ;
F_5 ( V_36 , V_14 | 0x10 ) ;
F_5 ( V_37 , 0x40c2040 ) ;
F_5 ( V_38 , 0x0 ) ;
F_5 ( V_39 , 0x40c2040 ) ;
F_5 ( V_40 , 0x0 ) ;
F_5 ( V_41 , 0 ) ;
F_5 ( V_42 , 0x88 ) ;
F_37 ( V_4 ) ;
V_14 = F_38 ( V_43 ) ;
F_39 ( V_43 , V_14 & ( ~ 0x10 ) ) ;
F_33 ( V_44 , 0 , ~ ( 1 << 8 ) ) ;
F_33 ( V_45 , 0 , ~ V_46 ) ;
F_33 ( V_45 , 0 , ~ V_47 ) ;
F_33 ( V_45 , 0 , ~ V_48 ) ;
F_35 ( 10 ) ;
for ( V_24 = 0 ; V_24 < 10 ; ++ V_24 ) {
T_2 V_49 ;
for ( V_25 = 0 ; V_25 < 100 ; ++ V_25 ) {
V_49 = F_2 ( V_22 ) ;
if ( V_49 & 2 )
break;
F_35 ( 10 ) ;
}
V_9 = 0 ;
if ( V_49 & 2 )
break;
F_23 ( L_4 ) ;
F_33 ( V_45 , V_48 ,
~ V_48 ) ;
F_35 ( 10 ) ;
F_33 ( V_45 , 0 , ~ V_48 ) ;
F_35 ( 10 ) ;
V_9 = - 1 ;
}
if ( V_9 ) {
F_23 ( L_5 ) ;
return V_9 ;
}
F_33 ( V_32 , 3 << 1 , ~ ( 3 << 1 ) ) ;
F_33 ( V_22 , 0 , ~ ( 1 << 2 ) ) ;
F_5 ( V_50 , 0x11010101 ) ;
F_5 ( V_51 , 0 ) ;
F_5 ( V_52 , F_40 ( V_2 -> V_53 ) |
( 0x7 << 16 ) | ( 0x1 << 31 ) ) ;
F_5 ( V_5 , 0x0 ) ;
V_2 -> V_7 = F_2 ( V_5 ) ;
F_5 ( V_6 , F_6 ( V_2 -> V_7 ) ) ;
F_5 ( V_54 , V_2 -> V_53 ) ;
V_23 = F_41 ( V_2 -> V_55 ) ;
V_23 = ( 0x1 << 8 ) | V_23 ;
F_33 ( V_50 , V_23 , ~ 0x11f1f ) ;
return 0 ;
}
static void F_29 ( struct V_3 * V_4 )
{
T_2 V_24 , V_25 ;
T_2 V_49 ;
F_5 ( V_50 , 0x11010101 ) ;
for ( V_24 = 0 ; V_24 < 10 ; ++ V_24 ) {
for ( V_25 = 0 ; V_25 < 100 ; ++ V_25 ) {
V_49 = F_2 ( V_22 ) ;
if ( V_49 & 2 )
break;
F_35 ( 1 ) ;
}
if ( V_49 & 2 )
break;
}
for ( V_24 = 0 ; V_24 < 10 ; ++ V_24 ) {
for ( V_25 = 0 ; V_25 < 100 ; ++ V_25 ) {
V_49 = F_2 ( V_56 ) ;
if ( V_49 & 0xf )
break;
F_35 ( 1 ) ;
}
if ( V_49 & 0xf )
break;
}
F_33 ( V_44 , 1 << 8 , ~ ( 1 << 8 ) ) ;
for ( V_24 = 0 ; V_24 < 10 ; ++ V_24 ) {
for ( V_25 = 0 ; V_25 < 100 ; ++ V_25 ) {
V_49 = F_2 ( V_56 ) ;
if ( V_49 & 0x240 )
break;
F_35 ( 1 ) ;
}
if ( V_49 & 0x240 )
break;
}
F_33 ( 0x3D49 , 0 , ~ ( 1 << 2 ) ) ;
F_33 ( V_31 , 0 , ~ ( 1 << 9 ) ) ;
F_5 ( V_45 , V_46 |
V_48 |
V_47 ) ;
F_5 ( V_22 , 0 ) ;
F_34 ( V_4 , false ) ;
}
static void F_42 ( struct V_1 * V_2 , T_4 V_57 , T_4 V_58 ,
unsigned V_59 )
{
F_43 ( V_59 & V_60 ) ;
F_25 ( V_2 , F_24 ( V_61 , 0 ) ) ;
F_25 ( V_2 , V_58 ) ;
F_25 ( V_2 , F_24 ( V_62 , 0 ) ) ;
F_25 ( V_2 , V_57 & 0xffffffff ) ;
F_25 ( V_2 , F_24 ( V_63 , 0 ) ) ;
F_25 ( V_2 , F_40 ( V_57 ) & 0xff ) ;
F_25 ( V_2 , F_24 ( V_64 , 0 ) ) ;
F_25 ( V_2 , 0 ) ;
F_25 ( V_2 , F_24 ( V_62 , 0 ) ) ;
F_25 ( V_2 , 0 ) ;
F_25 ( V_2 , F_24 ( V_63 , 0 ) ) ;
F_25 ( V_2 , 0 ) ;
F_25 ( V_2 , F_24 ( V_64 , 0 ) ) ;
F_25 ( V_2 , 2 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_25 ( V_2 , F_24 ( V_65 , 0 ) ) ;
F_25 ( V_2 , 0 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_25 ( V_2 , F_24 ( V_66 , 0 ) ) ;
F_25 ( V_2 , 1 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_2 V_14 = 0 ;
unsigned V_24 ;
int V_9 ;
F_5 ( V_61 , 0xCAFEDEAD ) ;
V_9 = F_22 ( V_2 , 3 ) ;
if ( V_9 ) {
F_23 ( L_6 ,
V_2 -> V_67 , V_9 ) ;
return V_9 ;
}
F_25 ( V_2 , F_24 ( V_61 , 0 ) ) ;
F_25 ( V_2 , 0xDEADBEEF ) ;
F_26 ( V_2 ) ;
for ( V_24 = 0 ; V_24 < V_4 -> V_68 ; V_24 ++ ) {
V_14 = F_2 ( V_61 ) ;
if ( V_14 == 0xDEADBEEF )
break;
F_47 ( 1 ) ;
}
if ( V_24 < V_4 -> V_68 ) {
F_27 ( L_7 ,
V_2 -> V_67 , V_24 ) ;
} else {
F_23 ( L_8 ,
V_2 -> V_67 , V_14 ) ;
V_9 = - V_69 ;
}
return V_9 ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_70 * V_71 ,
unsigned V_72 , bool V_73 )
{
F_25 ( V_2 , F_24 ( V_74 , 0 ) ) ;
F_25 ( V_2 , V_71 -> V_53 ) ;
F_25 ( V_2 , F_24 ( V_75 , 0 ) ) ;
F_25 ( V_2 , V_71 -> V_76 ) ;
}
static void F_37 ( struct V_3 * V_4 )
{
T_1 V_57 ;
T_2 V_77 ;
V_57 = ( V_4 -> V_11 . V_53 + V_78 ) >> 3 ;
V_77 = F_49 ( V_4 -> V_11 . V_79 -> V_77 + 4 ) >> 3 ;
F_5 ( V_80 , V_57 ) ;
F_5 ( V_81 , V_77 ) ;
V_57 += V_77 ;
V_77 = V_82 >> 3 ;
F_5 ( V_83 , V_57 ) ;
F_5 ( V_84 , V_77 ) ;
V_57 += V_77 ;
V_77 = ( V_85 +
( V_86 * V_4 -> V_11 . V_87 ) ) >> 3 ;
F_5 ( V_88 , V_57 ) ;
F_5 ( V_89 , V_77 ) ;
V_57 = ( V_4 -> V_11 . V_53 >> 28 ) & 0xF ;
F_5 ( V_90 , ( V_57 << 12 ) | ( V_57 << 0 ) ) ;
V_57 = ( V_4 -> V_11 . V_53 >> 32 ) & 0xFF ;
F_5 ( V_52 , V_57 | ( 0x9 << 16 ) | ( 0x1 << 31 ) ) ;
F_5 ( V_91 , V_4 -> V_92 . V_93 . V_94 ) ;
F_5 ( V_95 , V_4 -> V_92 . V_93 . V_94 ) ;
F_5 ( V_96 , V_4 -> V_92 . V_93 . V_94 ) ;
}
static void F_19 ( struct V_3 * V_4 ,
bool V_97 )
{
T_3 V_98 , V_99 ;
if ( V_97 && ( V_4 -> V_100 & V_101 ) ) {
V_99 = F_38 ( V_102 ) ;
V_99 |= 0xfff ;
F_39 ( V_102 , V_99 ) ;
V_98 = V_99 = F_2 ( V_103 ) ;
V_99 |= V_104 ;
if ( V_98 != V_99 )
F_5 ( V_103 , V_99 ) ;
} else {
V_99 = F_38 ( V_102 ) ;
V_99 &= ~ 0xfff ;
F_39 ( V_102 , V_99 ) ;
V_98 = V_99 = F_2 ( V_103 ) ;
V_99 &= ~ V_104 ;
if ( V_98 != V_99 )
F_5 ( V_103 , V_99 ) ;
}
}
static void F_34 ( struct V_3 * V_4 ,
bool V_105 )
{
T_3 V_14 , V_106 ;
F_50 ( V_107 , V_108 , 0 ) ;
V_14 = F_2 ( V_103 ) ;
V_14 &= ~ ( V_109 | V_110 ) ;
V_14 |= V_104 |
( 1 << V_111 ) |
( 4 << V_112 ) ;
if ( V_105 ) {
V_14 &= ~ 0x7ffff800 ;
V_106 = V_113 |
V_114 |
( 7 << V_115 ) ;
} else {
V_14 |= 0x7ffff800 ;
V_106 = 0 ;
}
F_5 ( V_103 , V_14 ) ;
F_39 ( V_116 , V_106 ) ;
}
static bool F_51 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
return ! ( F_2 ( V_117 ) & V_118 ) ;
}
static int F_52 ( void * V_8 )
{
unsigned V_24 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
for ( V_24 = 0 ; V_24 < V_4 -> V_68 ; V_24 ++ ) {
if ( ! ( F_2 ( V_117 ) & V_118 ) )
return 0 ;
}
return - V_119 ;
}
static int F_53 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
F_29 ( V_4 ) ;
F_33 ( V_29 , V_30 ,
~ V_30 ) ;
F_35 ( 5 ) ;
return F_32 ( V_4 ) ;
}
static int F_54 ( struct V_3 * V_4 ,
struct V_120 * V_121 ,
unsigned type ,
enum V_122 V_123 )
{
return 0 ;
}
static int F_55 ( struct V_3 * V_4 ,
struct V_120 * V_121 ,
struct V_124 * V_125 )
{
F_56 ( L_9 ) ;
F_57 ( & V_4 -> V_11 . V_2 ) ;
return 0 ;
}
static int F_58 ( void * V_8 ,
enum V_126 V_123 )
{
return 0 ;
}
static int F_59 ( void * V_8 ,
enum V_127 V_123 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( V_123 == V_128 ) {
F_29 ( V_4 ) ;
if ( V_4 -> V_129 & V_130 && V_131 == 0 ) {
if ( ! ( F_60 ( V_132 ) &
V_133 ) ) {
F_5 ( V_134 , ( V_135 |
V_136 |
V_137 ) ) ;
F_35 ( 20 ) ;
}
}
return 0 ;
} else {
if ( V_4 -> V_129 & V_130 && V_131 == 0 ) {
if ( F_60 ( V_132 ) &
V_133 ) {
F_5 ( V_134 , ( V_135 |
V_138 |
V_137 ) ) ;
F_35 ( 30 ) ;
}
}
return F_32 ( V_4 ) ;
}
}
static void F_8 ( struct V_3 * V_4 )
{
V_4 -> V_11 . V_2 . V_139 = & V_140 ;
}
static void F_9 ( struct V_3 * V_4 )
{
V_4 -> V_11 . V_12 . V_141 = 1 ;
V_4 -> V_11 . V_12 . V_139 = & V_142 ;
}
