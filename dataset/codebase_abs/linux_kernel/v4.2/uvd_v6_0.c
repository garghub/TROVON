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
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
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
V_9 = F_18 ( V_4 ) ;
if ( V_9 )
goto V_16;
V_2 -> V_17 = true ;
V_9 = F_19 ( V_2 ) ;
if ( V_9 ) {
V_2 -> V_17 = false ;
goto V_16;
}
V_9 = F_20 ( V_2 , 10 ) ;
if ( V_9 ) {
F_21 ( L_2 , V_9 ) ;
goto V_16;
}
V_15 = F_22 ( V_18 , 0 ) ;
F_23 ( V_2 , V_15 ) ;
F_23 ( V_2 , 0xFFFFF ) ;
V_15 = F_22 ( V_19 , 0 ) ;
F_23 ( V_2 , V_15 ) ;
F_23 ( V_2 , 0xFFFFF ) ;
V_15 = F_22 ( V_20 , 0 ) ;
F_23 ( V_2 , V_15 ) ;
F_23 ( V_2 , 0xFFFFF ) ;
F_23 ( V_2 , F_22 ( V_21 , 0 ) ) ;
F_23 ( V_2 , 0x8 ) ;
F_23 ( V_2 , F_22 ( V_22 , 0 ) ) ;
F_23 ( V_2 , 3 ) ;
F_24 ( V_2 ) ;
V_16:
if ( ! V_9 )
F_25 ( L_3 ) ;
return V_9 ;
}
static int F_26 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
F_27 ( V_4 ) ;
V_2 -> V_17 = false ;
return 0 ;
}
static int F_28 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_9 = F_26 ( V_4 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_15 ( V_4 ) ;
if ( V_9 )
return V_9 ;
return V_9 ;
}
static int F_29 ( void * V_8 )
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
static void F_30 ( struct V_3 * V_4 )
{
T_2 V_23 ;
T_1 V_24 ;
F_5 ( V_25 ,
F_31 ( V_4 -> V_10 . V_26 ) ) ;
F_5 ( V_27 ,
F_32 ( V_4 -> V_10 . V_26 ) ) ;
V_23 = V_28 ;
V_24 = F_33 ( V_4 -> V_10 . V_29 -> V_24 + 4 ) ;
F_5 ( V_30 , V_23 >> 3 ) ;
F_5 ( V_31 , V_24 ) ;
V_23 += V_24 ;
V_24 = V_32 ;
F_5 ( V_33 , V_23 >> 3 ) ;
F_5 ( V_34 , V_24 ) ;
V_23 += V_24 ;
V_24 = V_35 ;
F_5 ( V_36 , V_23 >> 3 ) ;
F_5 ( V_37 , V_24 ) ;
}
static int F_18 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
T_1 V_38 , V_15 ;
T_1 V_39 ;
T_1 V_40 ;
int V_41 , V_42 , V_9 ;
F_34 ( V_43 , 0 , ~ ( 1 << 2 ) ) ;
V_39 = 0 ;
V_40 = 0 ;
F_30 ( V_4 ) ;
F_5 ( V_44 , 0 ) ;
F_34 ( V_45 , 0 , ~ ( 1 << 1 ) ) ;
F_34 ( V_46 , 1 << 8 , ~ ( 1 << 8 ) ) ;
F_35 ( 1 ) ;
F_5 ( V_47 , V_48 |
V_49 | V_50 |
V_51 | V_52 |
V_53 | V_54 |
V_55 ) ;
F_35 ( 5 ) ;
F_34 ( V_56 , 0 , ~ V_57 ) ;
F_35 ( 5 ) ;
F_5 ( V_58 , 0x40 | ( 1 << 8 ) | ( 1 << 13 ) |
( 1 << 21 ) | ( 1 << 9 ) | ( 1 << 20 ) ) ;
#ifdef F_36
V_39 = 0xa ;
V_40 = 0 ;
#endif
F_5 ( V_59 , V_39 ) ;
F_5 ( V_60 , V_40 ) ;
F_5 ( V_61 , 0x40c2040 ) ;
F_5 ( V_62 , 0x0 ) ;
F_5 ( V_63 , 0x40c2040 ) ;
F_5 ( V_64 , 0x0 ) ;
F_5 ( V_65 , 0 ) ;
F_5 ( V_66 , 0x88 ) ;
F_5 ( V_47 , V_49 ) ;
F_35 ( 5 ) ;
F_5 ( V_67 , 1 << 9 ) ;
F_34 ( V_46 , 0 , ~ ( 1 << 8 ) ) ;
F_5 ( V_47 , 0 ) ;
F_35 ( 10 ) ;
for ( V_41 = 0 ; V_41 < 10 ; ++ V_41 ) {
T_1 V_68 ;
for ( V_42 = 0 ; V_42 < 100 ; ++ V_42 ) {
V_68 = F_2 ( V_69 ) ;
if ( V_68 & 2 )
break;
F_35 ( 10 ) ;
}
V_9 = 0 ;
if ( V_68 & 2 )
break;
F_21 ( L_4 ) ;
F_34 ( V_47 , V_49 ,
~ V_49 ) ;
F_35 ( 10 ) ;
F_34 ( V_47 , 0 ,
~ V_49 ) ;
F_35 ( 10 ) ;
V_9 = - 1 ;
}
if ( V_9 ) {
F_21 ( L_5 ) ;
return V_9 ;
}
F_34 ( V_45 , 3 << 1 , ~ ( 3 << 1 ) ) ;
F_34 ( V_69 , 0 , ~ ( 2 << 1 ) ) ;
V_38 = F_37 ( V_2 -> V_70 ) ;
V_15 = 0 ;
V_15 = F_38 ( V_15 , V_71 , V_72 , V_38 ) ;
V_15 = F_38 ( V_15 , V_71 , V_73 , 1 ) ;
V_15 = F_38 ( V_15 , V_71 , V_74 , 1 ) ;
V_15 = F_38 ( V_15 , V_71 , V_75 , 0 ) ;
V_15 = F_38 ( V_15 , V_71 , V_76 , 1 ) ;
V_15 = F_38 ( V_15 , V_71 , V_77 , 1 ) ;
F_5 ( V_78 , V_15 ) ;
F_5 ( V_79 , 0 ) ;
F_5 ( V_80 , ( F_32 ( V_2 -> V_26 ) >> 2 ) ) ;
F_5 ( V_81 ,
F_31 ( V_2 -> V_26 ) ) ;
F_5 ( V_82 ,
F_32 ( V_2 -> V_26 ) ) ;
F_5 ( V_5 , 0 ) ;
V_2 -> V_7 = F_2 ( V_5 ) ;
F_5 ( V_6 , V_2 -> V_7 ) ;
F_34 ( V_78 , 0 , ~ V_83 ) ;
return 0 ;
}
static void F_27 ( struct V_3 * V_4 )
{
F_5 ( V_78 , 0x11010101 ) ;
F_34 ( V_46 , 1 << 8 , ~ ( 1 << 8 ) ) ;
F_35 ( 1 ) ;
F_5 ( V_47 , V_49 ) ;
F_35 ( 5 ) ;
F_5 ( V_67 , 0x0 ) ;
F_34 ( V_46 , 0 , ~ ( 1 << 8 ) ) ;
}
static void F_39 ( struct V_1 * V_2 , T_3 V_84 , T_3 V_85 ,
unsigned V_86 )
{
F_40 ( V_86 & V_87 ) ;
F_23 ( V_2 , F_22 ( V_88 , 0 ) ) ;
F_23 ( V_2 , V_85 ) ;
F_23 ( V_2 , F_22 ( V_89 , 0 ) ) ;
F_23 ( V_2 , V_84 & 0xffffffff ) ;
F_23 ( V_2 , F_22 ( V_90 , 0 ) ) ;
F_23 ( V_2 , F_32 ( V_84 ) & 0xff ) ;
F_23 ( V_2 , F_22 ( V_91 , 0 ) ) ;
F_23 ( V_2 , 0 ) ;
F_23 ( V_2 , F_22 ( V_89 , 0 ) ) ;
F_23 ( V_2 , 0 ) ;
F_23 ( V_2 , F_22 ( V_90 , 0 ) ) ;
F_23 ( V_2 , 0 ) ;
F_23 ( V_2 , F_22 ( V_91 , 0 ) ) ;
F_23 ( V_2 , 2 ) ;
}
static bool F_41 ( struct V_1 * V_2 ,
struct V_92 * V_93 ,
bool V_94 )
{
T_2 V_84 = V_93 -> V_26 ;
F_23 ( V_2 , F_22 ( V_95 , 0 ) ) ;
F_23 ( V_2 , ( V_84 >> 3 ) & 0x000FFFFF ) ;
F_23 ( V_2 , F_22 ( V_96 , 0 ) ) ;
F_23 ( V_2 , ( V_84 >> 23 ) & 0x000FFFFF ) ;
F_23 ( V_2 , F_22 ( V_97 , 0 ) ) ;
F_23 ( V_2 , 0x80 | ( V_94 ? 1 : 0 ) ) ;
return true ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_15 = 0 ;
unsigned V_41 ;
int V_9 ;
F_5 ( V_88 , 0xCAFEDEAD ) ;
V_9 = F_20 ( V_2 , 3 ) ;
if ( V_9 ) {
F_21 ( L_6 ,
V_2 -> V_98 , V_9 ) ;
return V_9 ;
}
F_23 ( V_2 , F_22 ( V_88 , 0 ) ) ;
F_23 ( V_2 , 0xDEADBEEF ) ;
F_24 ( V_2 ) ;
for ( V_41 = 0 ; V_41 < V_4 -> V_99 ; V_41 ++ ) {
V_15 = F_2 ( V_88 ) ;
if ( V_15 == 0xDEADBEEF )
break;
F_43 ( 1 ) ;
}
if ( V_41 < V_4 -> V_99 ) {
F_25 ( L_7 ,
V_2 -> V_98 , V_41 ) ;
} else {
F_21 ( L_8 ,
V_2 -> V_98 , V_15 ) ;
V_9 = - V_100 ;
}
return V_9 ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_101 * V_102 )
{
F_23 ( V_2 , F_22 ( V_103 , 0 ) ) ;
F_23 ( V_2 , F_31 ( V_102 -> V_26 ) ) ;
F_23 ( V_2 , F_22 ( V_104 , 0 ) ) ;
F_23 ( V_2 , F_32 ( V_102 -> V_26 ) ) ;
F_23 ( V_2 , F_22 ( V_105 , 0 ) ) ;
F_23 ( V_2 , V_102 -> V_106 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_107 * V_108 = NULL ;
int V_9 ;
V_9 = F_46 ( V_2 , 1 , NULL ) ;
if ( V_9 ) {
F_21 ( L_9 , V_9 ) ;
goto error;
}
V_9 = F_47 ( V_2 , 1 , & V_108 ) ;
if ( V_9 ) {
F_21 ( L_10 , V_9 ) ;
goto error;
}
V_9 = F_48 ( V_108 , false ) ;
if ( V_9 ) {
F_21 ( L_11 , V_9 ) ;
goto error;
}
F_25 ( L_12 , V_2 -> V_98 ) ;
error:
F_49 ( & V_108 ) ;
return V_9 ;
}
static bool F_50 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
return ! ( F_2 ( V_109 ) & V_110 ) ;
}
static int F_51 ( void * V_8 )
{
unsigned V_41 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
for ( V_41 = 0 ; V_41 < V_4 -> V_99 ; V_41 ++ ) {
if ( ! ( F_2 ( V_109 ) & V_110 ) )
return 0 ;
}
return - V_111 ;
}
static int F_52 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
F_27 ( V_4 ) ;
F_34 ( V_56 , V_57 ,
~ V_57 ) ;
F_35 ( 5 ) ;
return F_18 ( V_4 ) ;
}
static void F_53 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
F_54 ( V_4 -> V_112 , L_13 ) ;
F_54 ( V_4 -> V_112 , L_14 ,
F_2 ( V_95 ) ) ;
F_54 ( V_4 -> V_112 , L_15 ,
F_2 ( V_96 ) ) ;
F_54 ( V_4 -> V_112 , L_16 ,
F_2 ( V_97 ) ) ;
F_54 ( V_4 -> V_112 , L_17 ,
F_2 ( V_91 ) ) ;
F_54 ( V_4 -> V_112 , L_18 ,
F_2 ( V_89 ) ) ;
F_54 ( V_4 -> V_112 , L_19 ,
F_2 ( V_90 ) ) ;
F_54 ( V_4 -> V_112 , L_20 ,
F_2 ( V_113 ) ) ;
F_54 ( V_4 -> V_112 , L_21 ,
F_2 ( V_114 ) ) ;
F_54 ( V_4 -> V_112 , L_22 ,
F_2 ( V_115 ) ) ;
F_54 ( V_4 -> V_112 , L_23 ,
F_2 ( V_116 ) ) ;
F_54 ( V_4 -> V_112 , L_24 ,
F_2 ( V_22 ) ) ;
F_54 ( V_4 -> V_112 , L_25 ,
F_2 ( V_117 ) ) ;
F_54 ( V_4 -> V_112 , L_26 ,
F_2 ( V_118 ) ) ;
F_54 ( V_4 -> V_112 , L_27 ,
F_2 ( V_119 ) ) ;
F_54 ( V_4 -> V_112 , L_28 ,
F_2 ( V_44 ) ) ;
F_54 ( V_4 -> V_112 , L_29 ,
F_2 ( V_120 ) ) ;
F_54 ( V_4 -> V_112 , L_30 ,
F_2 ( V_46 ) ) ;
F_54 ( V_4 -> V_112 , L_31 ,
F_2 ( V_45 ) ) ;
F_54 ( V_4 -> V_112 , L_32 ,
F_2 ( V_121 ) ) ;
F_54 ( V_4 -> V_112 , L_33 ,
F_2 ( V_58 ) ) ;
F_54 ( V_4 -> V_112 , L_34 ,
F_2 ( V_59 ) ) ;
F_54 ( V_4 -> V_112 , L_35 ,
F_2 ( V_60 ) ) ;
F_54 ( V_4 -> V_112 , L_36 ,
F_2 ( V_61 ) ) ;
F_54 ( V_4 -> V_112 , L_37 ,
F_2 ( V_62 ) ) ;
F_54 ( V_4 -> V_112 , L_38 ,
F_2 ( V_63 ) ) ;
F_54 ( V_4 -> V_112 , L_39 ,
F_2 ( V_64 ) ) ;
F_54 ( V_4 -> V_112 , L_40 ,
F_2 ( V_66 ) ) ;
F_54 ( V_4 -> V_112 , L_41 ,
F_2 ( V_65 ) ) ;
F_54 ( V_4 -> V_112 , L_42 ,
F_2 ( V_30 ) ) ;
F_54 ( V_4 -> V_112 , L_43 ,
F_2 ( V_31 ) ) ;
F_54 ( V_4 -> V_112 , L_44 ,
F_2 ( V_33 ) ) ;
F_54 ( V_4 -> V_112 , L_45 ,
F_2 ( V_34 ) ) ;
F_54 ( V_4 -> V_112 , L_46 ,
F_2 ( V_36 ) ) ;
F_54 ( V_4 -> V_112 , L_47 ,
F_2 ( V_37 ) ) ;
F_54 ( V_4 -> V_112 , L_48 ,
F_2 ( V_67 ) ) ;
F_54 ( V_4 -> V_112 , L_49 ,
F_2 ( V_47 ) ) ;
F_54 ( V_4 -> V_112 , L_50 ,
F_2 ( V_105 ) ) ;
F_54 ( V_4 -> V_112 , L_51 ,
F_2 ( V_5 ) ) ;
F_54 ( V_4 -> V_112 , L_52 ,
F_2 ( V_6 ) ) ;
F_54 ( V_4 -> V_112 , L_53 ,
F_2 ( V_79 ) ) ;
F_54 ( V_4 -> V_112 , L_54 ,
F_2 ( V_78 ) ) ;
F_54 ( V_4 -> V_112 , L_55 ,
F_2 ( V_69 ) ) ;
F_54 ( V_4 -> V_112 , L_56 ,
F_2 ( V_21 ) ) ;
F_54 ( V_4 -> V_112 , L_57 ,
F_2 ( V_19 ) ) ;
F_54 ( V_4 -> V_112 , L_58 ,
F_2 ( V_18 ) ) ;
F_54 ( V_4 -> V_112 , L_59 ,
F_2 ( V_20 ) ) ;
F_54 ( V_4 -> V_112 , L_60 ,
F_2 ( V_88 ) ) ;
}
static int F_55 ( struct V_3 * V_4 ,
struct V_122 * V_123 ,
unsigned type ,
enum V_124 V_125 )
{
return 0 ;
}
static int F_56 ( struct V_3 * V_4 ,
struct V_122 * V_123 ,
struct V_126 * V_127 )
{
F_57 ( L_61 ) ;
F_58 ( & V_4 -> V_10 . V_2 ) ;
return 0 ;
}
static int F_59 ( void * V_8 ,
enum V_128 V_125 )
{
return 0 ;
}
static int F_60 ( void * V_8 ,
enum V_129 V_125 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( V_125 == V_130 ) {
F_27 ( V_4 ) ;
return 0 ;
} else {
return F_18 ( V_4 ) ;
}
}
static void F_7 ( struct V_3 * V_4 )
{
V_4 -> V_10 . V_2 . V_131 = & V_132 ;
}
static void F_8 ( struct V_3 * V_4 )
{
V_4 -> V_10 . V_11 . V_133 = 1 ;
V_4 -> V_10 . V_11 . V_131 = & V_134 ;
}
