static int F_1 ( void * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , void T_1 * V_6 )
{
int V_7 = 0 ;
struct V_8 * V_9 = (struct V_8 * ) V_1 ;
if ( F_2 ( V_5 -> V_10 . V_11 . V_12 ) ) {
if ( F_2 ( V_5 -> V_10 . V_11 . V_13 ) )
V_3 -> V_14 ++ ;
if ( F_2 ( V_5 -> V_10 . V_11 . V_15 ) ) {
V_3 -> V_16 ++ ;
F_3 ( V_6 ) ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_17 ) ) {
V_3 -> V_18 ++ ;
V_9 -> V_19 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_20 ) ) {
V_3 -> V_21 ++ ;
V_9 -> V_19 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_22 ) )
V_9 -> V_23 += V_5 -> V_10 . V_11 . V_24 ;
if ( F_2 ( V_5 -> V_10 . V_11 . V_25 ) )
V_9 -> V_23 += V_5 -> V_10 . V_11 . V_24 ;
if ( F_2 ( V_5 -> V_10 . V_11 . V_26 ) )
V_3 -> V_27 ++ ;
if ( F_2 ( V_5 -> V_10 . V_11 . V_28 ) ) {
F_3 ( V_6 ) ;
V_3 -> V_29 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_30 ) )
V_3 -> V_31 ++ ;
if ( F_2 ( V_5 -> V_10 . V_11 . V_32 ) ) {
V_3 -> V_33 ++ ;
F_3 ( V_6 ) ;
}
V_7 = - 1 ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_34 ) )
V_3 -> V_27 ++ ;
#ifdef F_4
if ( V_5 -> V_10 . V_11 . V_35 )
V_3 -> V_36 ++ ;
#endif
return V_7 ;
}
static int F_5 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_11 . V_37 ;
}
static int F_6 ( int V_38 , int type , int V_39 )
{
int V_7 = V_40 ;
T_2 V_41 = ( type << 2 | V_38 << 1 | V_39 ) & 0x7 ;
if ( V_41 == 0x0 )
V_7 = V_42 ;
else if ( V_41 == 0x4 )
V_7 = V_40 ;
else if ( V_41 == 0x5 )
V_7 = V_43 ;
else if ( V_41 == 0x6 )
V_7 = V_43 ;
else if ( V_41 == 0x7 )
V_7 = V_43 ;
else if ( V_41 == 0x1 )
V_7 = V_44 ;
else if ( V_41 == 0x3 )
V_7 = V_44 ;
return V_7 ;
}
static void F_7 ( void * V_1 , struct V_2 * V_3 ,
struct V_45 * V_5 )
{
if ( F_2 ( V_5 -> V_46 . V_10 . V_47 . V_48 ) ) {
if ( V_5 -> V_49 . V_47 . V_50 )
V_3 -> V_50 ++ ;
if ( V_5 -> V_49 . V_47 . V_51 )
V_3 -> V_51 ++ ;
if ( V_5 -> V_49 . V_47 . V_52 )
V_3 -> V_52 ++ ;
if ( V_5 -> V_49 . V_47 . V_53 )
V_3 -> V_53 ++ ;
if ( V_5 -> V_49 . V_47 . V_54 )
V_3 -> V_54 ++ ;
if ( V_5 -> V_49 . V_47 . V_55 == V_56 )
V_3 -> V_57 ++ ;
else if ( V_5 -> V_49 . V_47 . V_55 == V_58 )
V_3 -> V_59 ++ ;
else if ( V_5 -> V_49 . V_47 . V_55 == V_60 )
V_3 -> V_61 ++ ;
else if ( V_5 -> V_49 . V_47 . V_55 == V_62 )
V_3 -> V_63 ++ ;
else if ( V_5 -> V_49 . V_47 . V_55 == V_64 )
V_3 -> V_65 ++ ;
else if ( V_5 -> V_49 . V_47 . V_55 == V_66 )
V_3 -> V_67 ++ ;
else if ( V_5 -> V_49 . V_47 . V_55 == V_68 )
V_3 -> V_69 ++ ;
else
V_3 -> V_70 ++ ;
if ( V_5 -> V_49 . V_47 . V_71 )
V_3 -> V_71 ++ ;
if ( V_5 -> V_49 . V_47 . V_72 )
V_3 -> V_72 ++ ;
if ( V_5 -> V_49 . V_47 . V_73 )
V_3 -> V_73 ++ ;
if ( V_5 -> V_49 . V_47 . V_74 )
V_3 -> V_74 ++ ;
if ( V_5 -> V_49 . V_47 . V_75 )
V_3 -> V_75 ++ ;
if ( V_5 -> V_49 . V_47 . V_76 )
V_3 -> V_76 ++ ;
if ( V_5 -> V_49 . V_47 . V_77 )
V_3 -> V_77 ++ ;
if ( V_5 -> V_49 . V_47 . V_78 )
V_3 -> V_78 ++ ;
if ( V_5 -> V_49 . V_47 . V_79 )
V_3 -> V_79 ++ ;
}
}
static int F_8 ( void * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 )
{
int V_7 = V_40 ;
struct V_8 * V_9 = (struct V_8 * ) V_1 ;
if ( F_2 ( V_5 -> V_10 . V_47 . V_12 ) ) {
if ( F_2 ( V_5 -> V_10 . V_47 . V_80 ) ) {
V_3 -> V_81 ++ ;
V_9 -> V_82 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_47 . V_83 ) )
V_3 -> V_84 ++ ;
if ( F_2 ( V_5 -> V_10 . V_47 . V_85 ) )
F_9 ( L_1 ) ;
if ( F_2 ( V_5 -> V_10 . V_47 . V_22 ) ) {
V_9 -> V_23 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_47 . V_86 ) )
V_3 -> V_87 ++ ;
if ( F_2 ( V_5 -> V_10 . V_47 . V_88 ) )
V_3 -> V_89 ++ ;
if ( F_2 ( V_5 -> V_10 . V_47 . V_90 ) ) {
V_3 -> V_91 ++ ;
V_9 -> V_92 ++ ;
}
V_7 = V_44 ;
}
V_7 = F_6 ( V_5 -> V_10 . V_47 . V_85 ,
V_5 -> V_10 . V_47 . V_93 , V_5 -> V_10 . V_47 . V_48 ) ;
if ( F_2 ( V_5 -> V_10 . V_47 . V_94 ) )
V_3 -> V_95 ++ ;
if ( F_2 ( V_5 -> V_10 . V_47 . V_96 ) ) {
V_3 -> V_97 ++ ;
V_7 = V_44 ;
}
if ( F_2 ( V_5 -> V_10 . V_47 . V_98 ) ) {
V_3 -> V_99 ++ ;
V_7 = V_44 ;
}
if ( F_2 ( V_5 -> V_10 . V_47 . V_100 ) ) {
V_3 -> V_101 ++ ;
V_7 = V_44 ;
}
#ifdef F_4
if ( V_5 -> V_10 . V_47 . V_102 )
V_3 -> V_103 ++ ;
#endif
return V_7 ;
}
static void F_10 ( struct V_4 * V_5 , int V_104 ,
int V_105 , int V_106 )
{
V_5 -> V_10 . V_47 . V_107 = 1 ;
V_5 -> V_10 . V_47 . V_37 = V_108 - 1 ;
if ( V_105 == V_109 )
F_11 ( V_5 , V_106 ) ;
else
F_12 ( V_5 , V_106 ) ;
if ( V_104 )
V_5 -> V_10 . V_47 . V_110 = 1 ;
}
static void F_13 ( struct V_4 * V_5 , int V_105 , int V_106 )
{
V_5 -> V_10 . V_11 . V_107 = 0 ;
if ( V_105 == V_109 )
F_14 ( V_5 , V_106 ) ;
else
F_15 ( V_5 , V_106 ) ;
}
static int F_16 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_11 . V_107 ;
}
static int F_17 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_47 . V_107 ;
}
static void F_18 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_11 . V_107 = 1 ;
}
static void F_19 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_47 . V_107 = 1 ;
}
static int F_20 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_11 . V_111 ;
}
static void F_21 ( struct V_4 * V_5 , int V_105 )
{
int V_112 = V_5 -> V_10 . V_11 . V_113 ;
memset ( V_5 , 0 , F_22 ( struct V_4 , V_114 ) ) ;
if ( V_105 == V_109 )
F_23 ( V_5 , V_112 ) ;
else
F_24 ( V_5 , V_112 ) ;
}
static void F_25 ( struct V_4 * V_5 , int V_115 , int V_116 ,
int V_117 , int V_105 )
{
V_5 -> V_10 . V_11 . V_118 = V_115 ;
if ( V_105 == V_109 )
F_26 ( V_5 , V_116 ) ;
else
F_27 ( V_5 , V_116 ) ;
if ( F_28 ( V_117 ) )
V_5 -> V_10 . V_11 . V_119 = V_120 ;
}
static void F_29 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_11 . V_121 = 0 ;
}
static void F_30 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_11 . V_111 = 1 ;
V_5 -> V_10 . V_11 . V_121 = 1 ;
}
static int F_31 ( struct V_4 * V_5 , int V_122 )
{
if ( V_122 == V_123 )
return V_5 -> V_10 . V_47 . V_124 - 2 ;
else
return V_5 -> V_10 . V_47 . V_124 ;
}
static void F_32 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_11 . V_125 = 1 ;
}
static int F_33 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_11 . V_126 ;
}
static T_3 F_34 ( void * V_127 , T_2 V_128 )
{
T_3 V_129 ;
if ( V_128 ) {
struct V_45 * V_5 = (struct V_45 * ) V_127 ;
V_129 = V_5 -> V_130 ;
V_129 += V_5 -> V_131 * 1000000000ULL ;
} else {
struct V_4 * V_5 = (struct V_4 * ) V_127 ;
V_129 = V_5 -> V_114 ;
V_129 += V_5 -> V_132 * 1000000000ULL ;
}
return V_129 ;
}
static int F_35 ( void * V_127 , T_2 V_128 )
{
if ( V_128 ) {
struct V_45 * V_5 = (struct V_45 * ) V_127 ;
return V_5 -> V_46 . V_10 . V_47 . V_85 ;
} else {
struct V_4 * V_5 = (struct V_4 * ) V_127 ;
if ( ( V_5 -> V_114 == 0xffffffff ) && ( V_5 -> V_132 == 0xffffffff ) )
return 0 ;
else
return 1 ;
}
}
