static int F_1 ( void * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , void T_1 * V_6 )
{
int V_7 = 0 ;
struct V_8 * V_9 = (struct V_8 * ) V_1 ;
if ( F_2 ( V_5 -> V_10 . V_11 . V_12 ) ) {
F_3 ( V_13 L_1 , V_5 -> V_10 . V_11 ) ;
if ( F_2 ( V_5 -> V_10 . V_11 . V_14 ) ) {
F_3 ( V_13 L_2 ) ;
V_3 -> V_15 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_16 ) ) {
F_3 ( V_13 L_3 ) ;
V_3 -> V_17 ++ ;
F_4 ( V_6 ) ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_18 ) ) {
F_3 ( V_13 L_4 ) ;
V_3 -> V_19 ++ ;
V_9 -> V_20 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_21 ) ) {
F_3 ( V_13 L_5 ) ;
V_3 -> V_22 ++ ;
V_9 -> V_20 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_23 ) ) {
F_3 ( V_13 L_6 ) ;
V_9 -> V_24 += V_5 -> V_10 . V_11 . V_25 ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_26 ) ) {
F_3 ( V_13 L_7 ) ;
V_9 -> V_24 += V_5 -> V_10 . V_11 . V_25 ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_27 ) ) {
F_3 ( V_28 L_8 ) ;
V_3 -> V_29 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_30 ) ) {
F_3 ( V_13 L_9 ) ;
F_4 ( V_6 ) ;
V_3 -> V_31 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_32 ) ) {
F_3 ( V_13 L_10 ) ;
V_3 -> V_33 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_34 ) ) {
F_3 ( V_13 L_11 ) ;
V_3 -> V_35 ++ ;
F_4 ( V_6 ) ;
}
V_7 = - 1 ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_36 ) ) {
F_3 ( V_28 L_12 ) ;
V_3 -> V_29 ++ ;
}
#ifdef F_5
if ( V_5 -> V_10 . V_11 . V_37 ) {
F_3 ( V_28 L_13 ) ;
V_3 -> V_38 ++ ;
}
#endif
return V_7 ;
}
static int F_6 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_11 . V_39 ;
}
static int F_7 ( int V_40 , int type , int V_41 )
{
int V_7 = V_42 ;
T_2 V_43 = ( type << 2 | V_40 << 1 | V_41 ) & 0x7 ;
if ( V_43 == 0x0 ) {
F_3 ( V_28 L_14 ) ;
V_7 = V_44 ;
} else if ( V_43 == 0x4 ) {
F_3 ( V_28 L_15 ) ;
V_7 = V_42 ;
} else if ( V_43 == 0x5 ) {
F_3 ( V_13 L_16 ) ;
V_7 = V_45 ;
} else if ( V_43 == 0x6 ) {
F_3 ( V_13 L_17 ) ;
V_7 = V_45 ;
} else if ( V_43 == 0x7 ) {
F_3 ( V_13
L_18 ) ;
V_7 = V_45 ;
} else if ( V_43 == 0x1 ) {
F_3 ( V_13
L_19 ) ;
V_7 = V_46 ;
} else if ( V_43 == 0x3 ) {
F_3 ( V_13 L_20 ) ;
V_7 = V_46 ;
}
return V_7 ;
}
static void F_8 ( void * V_1 , struct V_2 * V_3 ,
struct V_47 * V_5 )
{
if ( F_2 ( V_5 -> V_48 . V_10 . V_49 . V_50 ) ) {
if ( V_5 -> V_51 . V_49 . V_52 )
V_3 -> V_52 ++ ;
if ( V_5 -> V_51 . V_49 . V_53 )
V_3 -> V_53 ++ ;
if ( V_5 -> V_51 . V_49 . V_54 )
V_3 -> V_54 ++ ;
if ( V_5 -> V_51 . V_49 . V_55 )
V_3 -> V_55 ++ ;
if ( V_5 -> V_51 . V_49 . V_56 )
V_3 -> V_56 ++ ;
if ( V_5 -> V_51 . V_49 . V_57 == V_58 )
V_3 -> V_59 ++ ;
else if ( V_5 -> V_51 . V_49 . V_57 == V_60 )
V_3 -> V_61 ++ ;
else if ( V_5 -> V_51 . V_49 . V_57 == V_62 )
V_3 -> V_63 ++ ;
else if ( V_5 -> V_51 . V_49 . V_57 == V_64 )
V_3 -> V_65 ++ ;
else if ( V_5 -> V_51 . V_49 . V_57 == V_62 )
V_3 -> V_66 ++ ;
else if ( V_5 -> V_51 . V_49 . V_57 == V_67 )
V_3 -> V_68 ++ ;
else if ( V_5 -> V_51 . V_49 . V_57 == V_69 )
V_3 -> V_70 ++ ;
else
V_3 -> V_71 ++ ;
if ( V_5 -> V_51 . V_49 . V_72 )
V_3 -> V_72 ++ ;
if ( V_5 -> V_51 . V_49 . V_73 )
V_3 -> V_73 ++ ;
if ( V_5 -> V_51 . V_49 . V_74 )
V_3 -> V_74 ++ ;
if ( V_5 -> V_51 . V_49 . V_75 )
V_3 -> V_75 ++ ;
if ( V_5 -> V_51 . V_49 . V_76 )
V_3 -> V_76 ++ ;
if ( V_5 -> V_51 . V_49 . V_77 )
V_3 -> V_77 ++ ;
if ( V_5 -> V_51 . V_49 . V_78 )
V_3 -> V_78 ++ ;
if ( V_5 -> V_51 . V_49 . V_79 )
V_3 -> V_79 ++ ;
if ( V_5 -> V_51 . V_49 . V_80 )
V_3 -> V_80 ++ ;
}
}
static int F_9 ( void * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 )
{
int V_7 = V_42 ;
struct V_8 * V_9 = (struct V_8 * ) V_1 ;
if ( F_2 ( V_5 -> V_10 . V_49 . V_12 ) ) {
F_3 ( V_13 L_21 ,
V_5 -> V_10 . V_49 ) ;
if ( F_2 ( V_5 -> V_10 . V_49 . V_81 ) ) {
F_3 ( V_13 L_22 ) ;
V_3 -> V_82 ++ ;
V_9 -> V_83 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_49 . V_84 ) ) {
F_3 ( V_13 L_23 ) ;
V_3 -> V_85 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_49 . V_86 ) )
F_3 ( V_13 L_24 ) ;
if ( F_2 ( V_5 -> V_10 . V_49 . V_23 ) ) {
F_3 ( V_13 L_6 ) ;
V_9 -> V_24 ++ ;
V_9 -> V_24 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_49 . V_87 ) ) {
F_3 ( V_13 L_25 ) ;
V_3 -> V_88 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_49 . V_89 ) ) {
F_3 ( V_13 L_26 ) ;
V_3 -> V_90 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_49 . V_91 ) ) {
F_3 ( V_13 L_27 ) ;
V_3 -> V_92 ++ ;
V_9 -> V_93 ++ ;
}
V_7 = V_46 ;
}
V_7 = F_7 ( V_5 -> V_10 . V_49 . V_86 ,
V_5 -> V_10 . V_49 . V_94 , V_5 -> V_10 . V_49 . V_50 ) ;
if ( F_2 ( V_5 -> V_10 . V_49 . V_95 ) ) {
F_3 ( V_13 L_28 ) ;
V_3 -> V_96 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_49 . V_97 ) ) {
F_3 ( V_13 L_29 ) ;
V_3 -> V_98 ++ ;
V_7 = V_46 ;
}
if ( F_2 ( V_5 -> V_10 . V_49 . V_99 ) ) {
F_3 ( V_13 L_30 ) ;
V_3 -> V_100 ++ ;
V_7 = V_46 ;
}
if ( F_2 ( V_5 -> V_10 . V_49 . V_101 ) ) {
F_3 ( V_13 L_31 ) ;
V_3 -> V_102 ++ ;
V_7 = V_46 ;
}
#ifdef F_5
if ( V_5 -> V_10 . V_49 . V_103 ) {
F_3 ( V_28 L_32 ) ;
V_3 -> V_104 ++ ;
}
#endif
return V_7 ;
}
static void F_10 ( struct V_4 * V_5 , int V_105 ,
int V_106 , int V_107 )
{
V_5 -> V_10 . V_49 . V_108 = 1 ;
V_5 -> V_10 . V_49 . V_39 = V_109 - 1 ;
if ( V_106 == V_110 )
F_11 ( V_5 , V_107 ) ;
else
F_12 ( V_5 , V_107 ) ;
if ( V_105 )
V_5 -> V_10 . V_49 . V_111 = 1 ;
}
static void F_13 ( struct V_4 * V_5 , int V_106 , int V_107 )
{
V_5 -> V_10 . V_11 . V_108 = 0 ;
if ( V_106 == V_110 )
F_14 ( V_5 , V_107 ) ;
else
F_15 ( V_5 , V_107 ) ;
}
static int F_16 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_11 . V_108 ;
}
static int F_17 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_49 . V_108 ;
}
static void F_18 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_11 . V_108 = 1 ;
}
static void F_19 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_49 . V_108 = 1 ;
}
static int F_20 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_11 . V_112 ;
}
static void F_21 ( struct V_4 * V_5 , int V_106 )
{
int V_113 = V_5 -> V_10 . V_11 . V_114 ;
memset ( V_5 , 0 , F_22 ( struct V_4 , V_115 ) ) ;
if ( V_106 == V_110 )
F_23 ( V_5 , V_113 ) ;
else
F_24 ( V_5 , V_113 ) ;
}
static void F_25 ( struct V_4 * V_5 , int V_116 , int V_117 ,
int V_118 , int V_106 )
{
V_5 -> V_10 . V_11 . V_119 = V_116 ;
if ( V_106 == V_110 )
F_26 ( V_5 , V_117 ) ;
else
F_27 ( V_5 , V_117 ) ;
if ( F_28 ( V_118 ) )
V_5 -> V_10 . V_11 . V_120 = V_121 ;
}
static void F_29 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_11 . V_122 = 0 ;
}
static void F_30 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_11 . V_112 = 1 ;
V_5 -> V_10 . V_11 . V_122 = 1 ;
}
static int F_31 ( struct V_4 * V_5 , int V_123 )
{
if ( V_123 == V_124 )
return V_5 -> V_10 . V_49 . V_125 - 2 ;
else
return V_5 -> V_10 . V_49 . V_125 ;
}
static void F_32 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_11 . V_126 = 1 ;
}
static int F_33 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_11 . V_127 ;
}
static T_3 F_34 ( void * V_128 , T_2 V_129 )
{
T_3 V_130 ;
if ( V_129 ) {
struct V_47 * V_5 = (struct V_47 * ) V_128 ;
V_130 = V_5 -> V_131 ;
V_130 += V_5 -> V_132 * 1000000000ULL ;
} else {
struct V_4 * V_5 = (struct V_4 * ) V_128 ;
V_130 = V_5 -> V_115 ;
V_130 += V_5 -> V_133 * 1000000000ULL ;
}
return V_130 ;
}
static int F_35 ( void * V_128 , T_2 V_129 )
{
if ( V_129 ) {
struct V_47 * V_5 = (struct V_47 * ) V_128 ;
return V_5 -> V_48 . V_10 . V_49 . V_86 ;
} else {
struct V_4 * V_5 = (struct V_4 * ) V_128 ;
if ( ( V_5 -> V_115 == 0xffffffff ) && ( V_5 -> V_133 == 0xffffffff ) )
return 0 ;
else
return 1 ;
}
}
