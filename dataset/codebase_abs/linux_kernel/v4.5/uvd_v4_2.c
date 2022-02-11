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
V_9 = F_13 ( V_4 , V_2 , 4096 , V_13 , 0xf ,
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
V_9 = F_15 ( V_4 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_27 ( V_4 ) ;
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
static bool F_39 ( struct V_1 * V_2 ,
struct V_68 * V_69 ,
bool V_70 )
{
T_4 V_60 = V_69 -> V_57 ;
F_24 ( V_2 , F_23 ( V_71 , 0 ) ) ;
F_24 ( V_2 , ( V_60 >> 3 ) & 0x000FFFFF ) ;
F_24 ( V_2 , F_23 ( V_72 , 0 ) ) ;
F_24 ( V_2 , ( V_60 >> 23 ) & 0x000FFFFF ) ;
F_24 ( V_2 , F_23 ( V_73 , 0 ) ) ;
F_24 ( V_2 , 0x80 | ( V_70 ? 1 : 0 ) ) ;
return true ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_15 = 0 ;
unsigned V_24 ;
int V_9 ;
F_5 ( V_64 , 0xCAFEDEAD ) ;
V_9 = F_21 ( V_2 , 3 ) ;
if ( V_9 ) {
F_22 ( L_6 ,
V_2 -> V_74 , V_9 ) ;
return V_9 ;
}
F_24 ( V_2 , F_23 ( V_64 , 0 ) ) ;
F_24 ( V_2 , 0xDEADBEEF ) ;
F_25 ( V_2 ) ;
for ( V_24 = 0 ; V_24 < V_4 -> V_75 ; V_24 ++ ) {
V_15 = F_2 ( V_64 ) ;
if ( V_15 == 0xDEADBEEF )
break;
F_41 ( 1 ) ;
}
if ( V_24 < V_4 -> V_75 ) {
F_26 ( L_7 ,
V_2 -> V_74 , V_24 ) ;
} else {
F_22 ( L_8 ,
V_2 -> V_74 , V_15 ) ;
V_9 = - V_76 ;
}
return V_9 ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_77 * V_78 )
{
F_24 ( V_2 , F_23 ( V_79 , 0 ) ) ;
F_24 ( V_2 , V_78 -> V_57 ) ;
F_24 ( V_2 , F_23 ( V_80 , 0 ) ) ;
F_24 ( V_2 , V_78 -> V_81 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_82 * V_82 = NULL ;
int V_9 ;
V_9 = F_18 ( V_4 , 53300 , 40000 ) ;
if ( V_9 ) {
F_22 ( L_9 , V_9 ) ;
return V_9 ;
}
V_9 = F_44 ( V_2 , 1 , NULL ) ;
if ( V_9 ) {
F_22 ( L_10 , V_9 ) ;
goto error;
}
V_9 = F_45 ( V_2 , 1 , & V_82 ) ;
if ( V_9 ) {
F_22 ( L_11 , V_9 ) ;
goto error;
}
V_9 = F_46 ( V_82 , false ) ;
if ( V_9 ) {
F_22 ( L_12 , V_9 ) ;
goto error;
}
F_26 ( L_13 , V_2 -> V_74 ) ;
error:
F_47 ( V_82 ) ;
F_18 ( V_4 , 0 , 0 ) ;
return V_9 ;
}
static void F_31 ( struct V_3 * V_4 )
{
T_4 V_60 ;
T_1 V_83 ;
V_60 = ( V_4 -> V_10 . V_57 + V_84 ) >> 3 ;
V_83 = F_48 ( V_4 -> V_10 . V_85 -> V_83 + 4 ) >> 3 ;
F_5 ( V_86 , V_60 ) ;
F_5 ( V_87 , V_83 ) ;
V_60 += V_83 ;
V_83 = V_88 >> 3 ;
F_5 ( V_89 , V_60 ) ;
F_5 ( V_90 , V_83 ) ;
V_60 += V_83 ;
V_83 = V_91 >> 3 ;
F_5 ( V_92 , V_60 ) ;
F_5 ( V_93 , V_83 ) ;
V_60 = ( V_4 -> V_10 . V_57 >> 28 ) & 0xF ;
F_5 ( V_94 , ( V_60 << 12 ) | ( V_60 << 0 ) ) ;
V_60 = ( V_4 -> V_10 . V_57 >> 32 ) & 0xFF ;
F_5 ( V_56 , V_60 | ( 0x9 << 16 ) | ( 0x1 << 31 ) ) ;
F_49 ( V_4 ) ;
}
static void F_50 ( struct V_3 * V_4 ,
bool V_95 )
{
T_2 V_96 , V_97 ;
if ( V_95 && ( V_4 -> V_98 & V_99 ) ) {
V_97 = F_51 ( V_100 ) ;
V_97 = 0xfff ;
F_52 ( V_100 , V_97 ) ;
V_96 = V_97 = F_2 ( V_101 ) ;
V_97 |= V_102 ;
if ( V_96 != V_97 )
F_5 ( V_101 , V_97 ) ;
} else {
V_97 = F_51 ( V_100 ) ;
V_97 &= ~ 0xfff ;
F_52 ( V_100 , V_97 ) ;
V_96 = V_97 = F_2 ( V_101 ) ;
V_97 &= ~ V_102 ;
if ( V_96 != V_97 )
F_5 ( V_101 , V_97 ) ;
}
}
static void F_53 ( struct V_3 * V_4 ,
bool V_103 )
{
T_2 V_15 , V_104 ;
V_15 = F_2 ( V_101 ) ;
V_15 &= ~ ( V_105 | V_106 ) ;
V_15 |= V_102 |
( 1 << V_107 ) |
( 4 << V_108 ) ;
if ( V_103 ) {
V_15 &= ~ 0x7ffff800 ;
V_104 = V_109 |
V_110 |
( 7 << V_111 ) ;
} else {
V_15 |= 0x7ffff800 ;
V_104 = 0 ;
}
F_5 ( V_101 , V_15 ) ;
F_52 ( V_112 , V_104 ) ;
}
static void F_49 ( struct V_3 * V_4 )
{
bool V_113 = true ;
if ( V_113 ) {
F_53 ( V_4 , false ) ;
} else {
T_2 V_15 = F_2 ( V_101 ) ;
V_15 &= ~ V_102 ;
F_5 ( V_101 , V_15 ) ;
}
}
static bool F_54 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
return ! ( F_2 ( V_114 ) & V_115 ) ;
}
static int F_55 ( void * V_8 )
{
unsigned V_24 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
for ( V_24 = 0 ; V_24 < V_4 -> V_75 ; V_24 ++ ) {
if ( ! ( F_2 ( V_114 ) & V_115 ) )
return 0 ;
}
return - V_116 ;
}
static int F_56 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
F_28 ( V_4 ) ;
F_32 ( V_40 , V_41 ,
~ V_41 ) ;
F_33 ( 5 ) ;
return F_19 ( V_4 ) ;
}
static void F_57 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
F_58 ( V_4 -> V_117 , L_14 ) ;
F_58 ( V_4 -> V_117 , L_15 ,
F_2 ( V_71 ) ) ;
F_58 ( V_4 -> V_117 , L_16 ,
F_2 ( V_72 ) ) ;
F_58 ( V_4 -> V_117 , L_17 ,
F_2 ( V_73 ) ) ;
F_58 ( V_4 -> V_117 , L_18 ,
F_2 ( V_67 ) ) ;
F_58 ( V_4 -> V_117 , L_19 ,
F_2 ( V_65 ) ) ;
F_58 ( V_4 -> V_117 , L_20 ,
F_2 ( V_66 ) ) ;
F_58 ( V_4 -> V_117 , L_21 ,
F_2 ( V_118 ) ) ;
F_58 ( V_4 -> V_117 , L_22 ,
F_2 ( V_119 ) ) ;
F_58 ( V_4 -> V_117 , L_23 ,
F_2 ( V_120 ) ) ;
F_58 ( V_4 -> V_117 , L_24 ,
F_2 ( V_121 ) ) ;
F_58 ( V_4 -> V_117 , L_25 ,
F_2 ( V_22 ) ) ;
F_58 ( V_4 -> V_117 , L_26 ,
F_2 ( V_56 ) ) ;
F_58 ( V_4 -> V_117 , L_27 ,
F_2 ( V_122 ) ) ;
F_58 ( V_4 -> V_117 , L_28 ,
F_2 ( V_123 ) ) ;
F_58 ( V_4 -> V_117 , L_29 ,
F_2 ( V_28 ) ) ;
F_58 ( V_4 -> V_117 , L_30 ,
F_2 ( V_101 ) ) ;
F_58 ( V_4 -> V_117 , L_31 ,
F_2 ( V_30 ) ) ;
F_58 ( V_4 -> V_117 , L_32 ,
F_2 ( V_29 ) ) ;
F_58 ( V_4 -> V_117 , L_33 ,
F_2 ( V_94 ) ) ;
F_58 ( V_4 -> V_117 , L_34 ,
F_2 ( V_42 ) ) ;
F_58 ( V_4 -> V_117 , L_35 ,
F_2 ( V_43 ) ) ;
F_58 ( V_4 -> V_117 , L_36 ,
F_2 ( V_44 ) ) ;
F_58 ( V_4 -> V_117 , L_37 ,
F_2 ( V_45 ) ) ;
F_58 ( V_4 -> V_117 , L_38 ,
F_2 ( V_46 ) ) ;
F_58 ( V_4 -> V_117 , L_39 ,
F_2 ( V_47 ) ) ;
F_58 ( V_4 -> V_117 , L_40 ,
F_2 ( V_48 ) ) ;
F_58 ( V_4 -> V_117 , L_41 ,
F_2 ( V_50 ) ) ;
F_58 ( V_4 -> V_117 , L_42 ,
F_2 ( V_49 ) ) ;
F_58 ( V_4 -> V_117 , L_43 ,
F_2 ( V_86 ) ) ;
F_58 ( V_4 -> V_117 , L_44 ,
F_2 ( V_87 ) ) ;
F_58 ( V_4 -> V_117 , L_45 ,
F_2 ( V_89 ) ) ;
F_58 ( V_4 -> V_117 , L_46 ,
F_2 ( V_90 ) ) ;
F_58 ( V_4 -> V_117 , L_47 ,
F_2 ( V_92 ) ) ;
F_58 ( V_4 -> V_117 , L_48 ,
F_2 ( V_93 ) ) ;
F_58 ( V_4 -> V_117 , L_49 ,
F_2 ( V_51 ) ) ;
F_58 ( V_4 -> V_117 , L_50 ,
F_2 ( V_31 ) ) ;
F_58 ( V_4 -> V_117 , L_51 ,
F_2 ( V_79 ) ) ;
F_58 ( V_4 -> V_117 , L_52 ,
F_2 ( V_80 ) ) ;
F_58 ( V_4 -> V_117 , L_53 ,
F_2 ( V_58 ) ) ;
F_58 ( V_4 -> V_117 , L_54 ,
F_2 ( V_5 ) ) ;
F_58 ( V_4 -> V_117 , L_55 ,
F_2 ( V_6 ) ) ;
F_58 ( V_4 -> V_117 , L_56 ,
F_2 ( V_55 ) ) ;
F_58 ( V_4 -> V_117 , L_57 ,
F_2 ( V_54 ) ) ;
F_58 ( V_4 -> V_117 , L_58 ,
F_2 ( V_53 ) ) ;
F_58 ( V_4 -> V_117 , L_59 ,
F_2 ( V_21 ) ) ;
F_58 ( V_4 -> V_117 , L_60 ,
F_2 ( V_19 ) ) ;
F_58 ( V_4 -> V_117 , L_61 ,
F_2 ( V_18 ) ) ;
F_58 ( V_4 -> V_117 , L_62 ,
F_2 ( V_20 ) ) ;
F_58 ( V_4 -> V_117 , L_63 ,
F_2 ( V_64 ) ) ;
}
static int F_59 ( struct V_3 * V_4 ,
struct V_124 * V_125 ,
unsigned type ,
enum V_126 V_127 )
{
return 0 ;
}
static int F_60 ( struct V_3 * V_4 ,
struct V_124 * V_125 ,
struct V_128 * V_129 )
{
F_61 ( L_64 ) ;
F_62 ( & V_4 -> V_10 . V_2 ) ;
return 0 ;
}
static int F_63 ( void * V_8 ,
enum V_130 V_127 )
{
bool V_131 = false ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( ! ( V_4 -> V_98 & V_99 ) )
return 0 ;
if ( V_127 == V_132 )
V_131 = true ;
F_50 ( V_4 , V_131 ) ;
return 0 ;
}
static int F_64 ( void * V_8 ,
enum V_133 V_127 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( ! ( V_4 -> V_134 & V_135 ) )
return 0 ;
if ( V_127 == V_136 ) {
F_28 ( V_4 ) ;
return 0 ;
} else {
return F_19 ( V_4 ) ;
}
}
static void F_7 ( struct V_3 * V_4 )
{
V_4 -> V_10 . V_2 . V_137 = & V_138 ;
}
static void F_8 ( struct V_3 * V_4 )
{
V_4 -> V_10 . V_11 . V_139 = 1 ;
V_4 -> V_10 . V_11 . V_137 = & V_140 ;
}
