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
static void F_31 ( struct V_3 * V_4 )
{
T_2 V_23 ;
T_1 V_24 ;
F_5 ( V_25 ,
F_32 ( V_4 -> V_10 . V_26 ) ) ;
F_5 ( V_27 ,
F_33 ( V_4 -> V_10 . V_26 ) ) ;
V_23 = V_28 ;
V_24 = F_34 ( V_4 -> V_10 . V_29 -> V_24 + 4 ) ;
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
F_5 ( V_38 , V_4 -> V_39 . V_40 . V_41 ) ;
F_5 ( V_42 , V_4 -> V_39 . V_40 . V_41 ) ;
F_5 ( V_43 , V_4 -> V_39 . V_40 . V_41 ) ;
}
static int F_19 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
T_1 V_44 , V_15 ;
T_1 V_45 ;
T_1 V_46 ;
int V_47 , V_48 , V_9 ;
F_35 ( V_49 , 0 , ~ ( 1 << 2 ) ) ;
V_45 = 0 ;
V_46 = 0 ;
F_31 ( V_4 ) ;
F_5 ( V_50 , 0 ) ;
F_35 ( V_51 , 0 , ~ ( 1 << 1 ) ) ;
F_35 ( V_52 , 1 << 8 , ~ ( 1 << 8 ) ) ;
F_36 ( 1 ) ;
F_5 ( V_53 , V_54 |
V_55 | V_56 |
V_57 | V_58 |
V_59 | V_60 |
V_61 ) ;
F_36 ( 5 ) ;
F_35 ( V_62 , 0 , ~ V_63 ) ;
F_36 ( 5 ) ;
F_5 ( V_64 , 0x40 | ( 1 << 8 ) | ( 1 << 13 ) |
( 1 << 21 ) | ( 1 << 9 ) | ( 1 << 20 ) ) ;
#ifdef F_37
V_45 = 0xa ;
V_46 = 0 ;
#endif
F_5 ( V_65 , V_45 ) ;
F_5 ( V_66 , V_46 ) ;
F_5 ( V_67 , 0x40c2040 ) ;
F_5 ( V_68 , 0x0 ) ;
F_5 ( V_69 , 0x40c2040 ) ;
F_5 ( V_70 , 0x0 ) ;
F_5 ( V_71 , 0 ) ;
F_5 ( V_72 , 0x88 ) ;
F_5 ( V_53 , V_55 ) ;
F_36 ( 5 ) ;
F_5 ( V_73 , 1 << 9 ) ;
F_35 ( V_52 , 0 , ~ ( 1 << 8 ) ) ;
F_5 ( V_53 , 0 ) ;
F_36 ( 10 ) ;
for ( V_47 = 0 ; V_47 < 10 ; ++ V_47 ) {
T_1 V_74 ;
for ( V_48 = 0 ; V_48 < 100 ; ++ V_48 ) {
V_74 = F_2 ( V_75 ) ;
if ( V_74 & 2 )
break;
F_36 ( 10 ) ;
}
V_9 = 0 ;
if ( V_74 & 2 )
break;
F_22 ( L_4 ) ;
F_35 ( V_53 , V_55 ,
~ V_55 ) ;
F_36 ( 10 ) ;
F_35 ( V_53 , 0 , ~ V_55 ) ;
F_36 ( 10 ) ;
V_9 = - 1 ;
}
if ( V_9 ) {
F_22 ( L_5 ) ;
return V_9 ;
}
F_35 ( V_51 , 3 << 1 , ~ ( 3 << 1 ) ) ;
F_35 ( V_75 , 0 , ~ ( 2 << 1 ) ) ;
V_44 = F_38 ( V_2 -> V_76 ) ;
V_15 = 0 ;
V_15 = F_39 ( V_15 , V_77 , V_78 , V_44 ) ;
V_15 = F_39 ( V_15 , V_77 , V_79 , 1 ) ;
V_15 = F_39 ( V_15 , V_77 , V_80 , 1 ) ;
V_15 = F_39 ( V_15 , V_77 , V_81 , 0 ) ;
V_15 = F_39 ( V_15 , V_77 , V_82 , 1 ) ;
V_15 = F_39 ( V_15 , V_77 , V_83 , 1 ) ;
F_5 ( V_84 , V_15 ) ;
F_5 ( V_85 , 0 ) ;
F_5 ( V_86 , ( F_33 ( V_2 -> V_26 ) >> 2 ) ) ;
F_5 ( V_87 ,
F_32 ( V_2 -> V_26 ) ) ;
F_5 ( V_88 ,
F_33 ( V_2 -> V_26 ) ) ;
F_5 ( V_5 , 0 ) ;
V_2 -> V_7 = F_2 ( V_5 ) ;
F_5 ( V_6 , V_2 -> V_7 ) ;
F_35 ( V_84 , 0 , ~ V_89 ) ;
return 0 ;
}
static void F_28 ( struct V_3 * V_4 )
{
F_5 ( V_84 , 0x11010101 ) ;
F_35 ( V_52 , 1 << 8 , ~ ( 1 << 8 ) ) ;
F_36 ( 1 ) ;
F_5 ( V_53 , V_55 ) ;
F_36 ( 5 ) ;
F_5 ( V_73 , 0x0 ) ;
F_35 ( V_52 , 0 , ~ ( 1 << 8 ) ) ;
}
static void F_40 ( struct V_1 * V_2 , T_3 V_90 , T_3 V_91 ,
unsigned V_92 )
{
F_41 ( V_92 & V_93 ) ;
F_24 ( V_2 , F_23 ( V_94 , 0 ) ) ;
F_24 ( V_2 , V_91 ) ;
F_24 ( V_2 , F_23 ( V_95 , 0 ) ) ;
F_24 ( V_2 , V_90 & 0xffffffff ) ;
F_24 ( V_2 , F_23 ( V_96 , 0 ) ) ;
F_24 ( V_2 , F_33 ( V_90 ) & 0xff ) ;
F_24 ( V_2 , F_23 ( V_97 , 0 ) ) ;
F_24 ( V_2 , 0 ) ;
F_24 ( V_2 , F_23 ( V_95 , 0 ) ) ;
F_24 ( V_2 , 0 ) ;
F_24 ( V_2 , F_23 ( V_96 , 0 ) ) ;
F_24 ( V_2 , 0 ) ;
F_24 ( V_2 , F_23 ( V_97 , 0 ) ) ;
F_24 ( V_2 , 2 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_15 = 0 ;
unsigned V_47 ;
int V_9 ;
F_5 ( V_94 , 0xCAFEDEAD ) ;
V_9 = F_21 ( V_2 , 3 ) ;
if ( V_9 ) {
F_22 ( L_6 ,
V_2 -> V_98 , V_9 ) ;
return V_9 ;
}
F_24 ( V_2 , F_23 ( V_94 , 0 ) ) ;
F_24 ( V_2 , 0xDEADBEEF ) ;
F_25 ( V_2 ) ;
for ( V_47 = 0 ; V_47 < V_4 -> V_99 ; V_47 ++ ) {
V_15 = F_2 ( V_94 ) ;
if ( V_15 == 0xDEADBEEF )
break;
F_43 ( 1 ) ;
}
if ( V_47 < V_4 -> V_99 ) {
F_26 ( L_7 ,
V_2 -> V_98 , V_47 ) ;
} else {
F_22 ( L_8 ,
V_2 -> V_98 , V_15 ) ;
V_9 = - V_100 ;
}
return V_9 ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_101 * V_102 )
{
F_24 ( V_2 , F_23 ( V_103 , 0 ) ) ;
F_24 ( V_2 , F_32 ( V_102 -> V_26 ) ) ;
F_24 ( V_2 , F_23 ( V_104 , 0 ) ) ;
F_24 ( V_2 , F_33 ( V_102 -> V_26 ) ) ;
F_24 ( V_2 , F_23 ( V_105 , 0 ) ) ;
F_24 ( V_2 , V_102 -> V_106 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_107 * V_107 = NULL ;
int V_9 ;
V_9 = F_18 ( V_4 , 53300 , 40000 ) ;
if ( V_9 ) {
F_22 ( L_9 , V_9 ) ;
return V_9 ;
}
V_9 = F_46 ( V_2 , 1 , NULL ) ;
if ( V_9 ) {
F_22 ( L_10 , V_9 ) ;
goto error;
}
V_9 = F_47 ( V_2 , 1 , true , & V_107 ) ;
if ( V_9 ) {
F_22 ( L_11 , V_9 ) ;
goto error;
}
V_9 = F_48 ( V_107 , false ) ;
if ( V_9 ) {
F_22 ( L_12 , V_9 ) ;
goto error;
}
F_26 ( L_13 , V_2 -> V_98 ) ;
error:
F_49 ( V_107 ) ;
F_18 ( V_4 , 0 , 0 ) ;
return V_9 ;
}
static bool F_50 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
return ! ( F_2 ( V_108 ) & V_109 ) ;
}
static int F_51 ( void * V_8 )
{
unsigned V_47 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
for ( V_47 = 0 ; V_47 < V_4 -> V_99 ; V_47 ++ ) {
if ( ! ( F_2 ( V_108 ) & V_109 ) )
return 0 ;
}
return - V_110 ;
}
static int F_52 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
F_28 ( V_4 ) ;
F_35 ( V_62 , V_63 ,
~ V_63 ) ;
F_36 ( 5 ) ;
return F_19 ( V_4 ) ;
}
static void F_53 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
F_54 ( V_4 -> V_111 , L_14 ) ;
F_54 ( V_4 -> V_111 , L_15 ,
F_2 ( V_112 ) ) ;
F_54 ( V_4 -> V_111 , L_16 ,
F_2 ( V_113 ) ) ;
F_54 ( V_4 -> V_111 , L_17 ,
F_2 ( V_114 ) ) ;
F_54 ( V_4 -> V_111 , L_18 ,
F_2 ( V_97 ) ) ;
F_54 ( V_4 -> V_111 , L_19 ,
F_2 ( V_95 ) ) ;
F_54 ( V_4 -> V_111 , L_20 ,
F_2 ( V_96 ) ) ;
F_54 ( V_4 -> V_111 , L_21 ,
F_2 ( V_115 ) ) ;
F_54 ( V_4 -> V_111 , L_22 ,
F_2 ( V_38 ) ) ;
F_54 ( V_4 -> V_111 , L_23 ,
F_2 ( V_42 ) ) ;
F_54 ( V_4 -> V_111 , L_24 ,
F_2 ( V_43 ) ) ;
F_54 ( V_4 -> V_111 , L_25 ,
F_2 ( V_22 ) ) ;
F_54 ( V_4 -> V_111 , L_26 ,
F_2 ( V_116 ) ) ;
F_54 ( V_4 -> V_111 , L_27 ,
F_2 ( V_117 ) ) ;
F_54 ( V_4 -> V_111 , L_28 ,
F_2 ( V_118 ) ) ;
F_54 ( V_4 -> V_111 , L_29 ,
F_2 ( V_50 ) ) ;
F_54 ( V_4 -> V_111 , L_30 ,
F_2 ( V_119 ) ) ;
F_54 ( V_4 -> V_111 , L_31 ,
F_2 ( V_52 ) ) ;
F_54 ( V_4 -> V_111 , L_32 ,
F_2 ( V_51 ) ) ;
F_54 ( V_4 -> V_111 , L_33 ,
F_2 ( V_120 ) ) ;
F_54 ( V_4 -> V_111 , L_34 ,
F_2 ( V_64 ) ) ;
F_54 ( V_4 -> V_111 , L_35 ,
F_2 ( V_65 ) ) ;
F_54 ( V_4 -> V_111 , L_36 ,
F_2 ( V_66 ) ) ;
F_54 ( V_4 -> V_111 , L_37 ,
F_2 ( V_67 ) ) ;
F_54 ( V_4 -> V_111 , L_38 ,
F_2 ( V_68 ) ) ;
F_54 ( V_4 -> V_111 , L_39 ,
F_2 ( V_69 ) ) ;
F_54 ( V_4 -> V_111 , L_40 ,
F_2 ( V_70 ) ) ;
F_54 ( V_4 -> V_111 , L_41 ,
F_2 ( V_72 ) ) ;
F_54 ( V_4 -> V_111 , L_42 ,
F_2 ( V_71 ) ) ;
F_54 ( V_4 -> V_111 , L_43 ,
F_2 ( V_30 ) ) ;
F_54 ( V_4 -> V_111 , L_44 ,
F_2 ( V_31 ) ) ;
F_54 ( V_4 -> V_111 , L_45 ,
F_2 ( V_33 ) ) ;
F_54 ( V_4 -> V_111 , L_46 ,
F_2 ( V_34 ) ) ;
F_54 ( V_4 -> V_111 , L_47 ,
F_2 ( V_36 ) ) ;
F_54 ( V_4 -> V_111 , L_48 ,
F_2 ( V_37 ) ) ;
F_54 ( V_4 -> V_111 , L_49 ,
F_2 ( V_73 ) ) ;
F_54 ( V_4 -> V_111 , L_50 ,
F_2 ( V_53 ) ) ;
F_54 ( V_4 -> V_111 , L_51 ,
F_2 ( V_103 ) ) ;
F_54 ( V_4 -> V_111 , L_52 ,
F_2 ( V_104 ) ) ;
F_54 ( V_4 -> V_111 , L_53 ,
F_2 ( V_105 ) ) ;
F_54 ( V_4 -> V_111 , L_54 ,
F_2 ( V_87 ) ) ;
F_54 ( V_4 -> V_111 , L_55 ,
F_2 ( V_88 ) ) ;
F_54 ( V_4 -> V_111 , L_56 ,
F_2 ( V_5 ) ) ;
F_54 ( V_4 -> V_111 , L_57 ,
F_2 ( V_6 ) ) ;
F_54 ( V_4 -> V_111 , L_58 ,
F_2 ( V_85 ) ) ;
F_54 ( V_4 -> V_111 , L_59 ,
F_2 ( V_84 ) ) ;
F_54 ( V_4 -> V_111 , L_60 ,
F_2 ( V_75 ) ) ;
F_54 ( V_4 -> V_111 , L_61 ,
F_2 ( V_21 ) ) ;
F_54 ( V_4 -> V_111 , L_62 ,
F_2 ( V_19 ) ) ;
F_54 ( V_4 -> V_111 , L_63 ,
F_2 ( V_18 ) ) ;
F_54 ( V_4 -> V_111 , L_64 ,
F_2 ( V_20 ) ) ;
F_54 ( V_4 -> V_111 , L_65 ,
F_2 ( V_94 ) ) ;
F_54 ( V_4 -> V_111 , L_22 ,
F_2 ( V_38 ) ) ;
F_54 ( V_4 -> V_111 , L_23 ,
F_2 ( V_42 ) ) ;
F_54 ( V_4 -> V_111 , L_24 ,
F_2 ( V_43 ) ) ;
}
static int F_55 ( struct V_3 * V_4 ,
struct V_121 * V_122 ,
unsigned type ,
enum V_123 V_124 )
{
return 0 ;
}
static int F_56 ( struct V_3 * V_4 ,
struct V_121 * V_122 ,
struct V_125 * V_126 )
{
F_57 ( L_66 ) ;
F_58 ( & V_4 -> V_10 . V_2 ) ;
return 0 ;
}
static int F_59 ( void * V_8 ,
enum V_127 V_124 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
if ( ! ( V_4 -> V_128 & V_129 ) )
return 0 ;
return 0 ;
}
static int F_60 ( void * V_8 ,
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
