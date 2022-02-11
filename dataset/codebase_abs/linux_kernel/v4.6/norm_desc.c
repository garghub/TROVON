static int F_1 ( void * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , void T_1 * V_6 )
{
struct V_7 * V_8 = (struct V_7 * ) V_1 ;
unsigned int V_9 = V_5 -> V_10 ;
unsigned int V_11 = V_5 -> V_12 ;
int V_13 = V_14 ;
if ( F_2 ( V_9 & V_15 ) )
return V_16 ;
if ( F_3 ( ! ( V_11 & V_17 ) ) )
return V_18 ;
if ( F_2 ( V_9 & V_19 ) ) {
if ( F_2 ( V_9 & V_20 ) ) {
V_3 -> V_21 ++ ;
V_8 -> V_22 ++ ;
}
if ( F_2 ( V_9 & V_23 ) ) {
V_3 -> V_24 ++ ;
V_8 -> V_25 ++ ;
}
if ( F_2 ( V_9 & V_26 ) ) {
V_3 -> V_27 ++ ;
V_8 -> V_25 ++ ;
}
if ( F_2 ( ( V_9 & V_28 ) ||
( V_9 & V_29 ) ||
( V_9 & V_30 ) ) ) {
unsigned int V_31 ;
V_31 = ( V_9 & V_32 ) >> 3 ;
V_8 -> V_31 += V_31 ;
}
V_13 = V_33 ;
}
if ( V_9 & V_34 )
V_3 -> V_35 ++ ;
if ( F_2 ( V_9 & V_36 ) )
V_3 -> V_37 ++ ;
return V_13 ;
}
static int F_4 ( struct V_4 * V_5 )
{
return ( V_5 -> V_12 & V_38 ) ;
}
static int F_5 ( void * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 )
{
int V_13 = V_39 ;
unsigned int V_40 = V_5 -> V_10 ;
struct V_7 * V_8 = (struct V_7 * ) V_1 ;
if ( F_2 ( V_40 & V_41 ) )
return V_42 ;
if ( F_2 ( ! ( V_40 & V_43 ) ) ) {
F_6 ( L_1 ,
V_44 ) ;
V_8 -> V_45 ++ ;
return V_46 ;
}
if ( F_2 ( V_40 & V_47 ) ) {
if ( F_2 ( V_40 & V_48 ) )
V_3 -> V_49 ++ ;
if ( F_2 ( V_40 & V_50 ) )
V_3 -> V_51 ++ ;
if ( F_2 ( V_40 & V_52 ) )
V_3 -> V_53 ++ ;
if ( F_2 ( V_40 & V_54 ) )
V_3 -> V_55 ++ ;
if ( F_2 ( V_40 & V_56 ) ) {
V_3 -> V_57 ++ ;
V_8 -> V_31 ++ ;
}
if ( F_2 ( V_40 & V_58 ) ) {
V_3 -> V_59 ++ ;
V_8 -> V_60 ++ ;
}
V_13 = V_46 ;
}
if ( F_2 ( V_40 & V_61 ) )
V_3 -> V_62 ++ ;
if ( F_2 ( V_40 & V_63 ) ) {
V_3 -> V_64 ++ ;
V_13 = V_46 ;
}
if ( F_2 ( V_40 & V_65 ) ) {
V_3 -> V_66 ++ ;
V_13 = V_46 ;
}
#ifdef F_7
if ( V_40 & V_67 )
V_3 -> V_68 ++ ;
#endif
return V_13 ;
}
static void F_8 ( struct V_4 * V_5 , int V_69 , int V_70 ,
int V_71 )
{
V_5 -> V_10 |= V_41 ;
V_5 -> V_12 |= ( V_72 - 1 ) & V_38 ;
if ( V_70 == V_73 )
F_9 ( V_5 , V_71 ) ;
else
F_10 ( V_5 , V_71 ) ;
if ( V_69 )
V_5 -> V_12 |= V_74 ;
}
static void F_11 ( struct V_4 * V_5 , int V_70 , int V_71 )
{
V_5 -> V_10 &= ~ V_15 ;
if ( V_70 == V_73 )
F_12 ( V_5 ) ;
else
F_13 ( V_5 , V_71 ) ;
}
static int F_14 ( struct V_4 * V_5 )
{
return ( V_5 -> V_10 & V_15 ) >> 31 ;
}
static void F_15 ( struct V_4 * V_5 )
{
V_5 -> V_10 |= V_15 ;
}
static void F_16 ( struct V_4 * V_5 )
{
V_5 -> V_10 |= V_41 ;
}
static int F_17 ( struct V_4 * V_5 )
{
return ( V_5 -> V_12 & V_17 ) >> 30 ;
}
static void F_18 ( struct V_4 * V_5 , int V_70 )
{
int V_75 = ( V_5 -> V_12 & V_76 ) >> 25 ;
memset ( V_5 , 0 , F_19 ( struct V_4 , V_77 ) ) ;
if ( V_70 == V_73 )
F_12 ( V_5 ) ;
else
F_13 ( V_5 , V_75 ) ;
}
static void F_20 ( struct V_4 * V_5 , int V_78 , int V_79 ,
bool V_80 , int V_70 , bool V_81 ,
bool V_82 )
{
unsigned int V_11 = V_5 -> V_12 ;
if ( V_78 )
V_11 |= V_83 ;
else
V_11 &= ~ V_83 ;
if ( F_3 ( V_80 ) )
V_11 |= ( V_84 ) << V_85 ;
else
V_11 &= ~ ( V_84 << V_85 ) ;
if ( V_82 )
V_11 |= V_17 ;
V_5 -> V_12 = V_11 ;
if ( V_70 == V_73 )
F_21 ( V_5 , V_79 ) ;
else
F_22 ( V_5 , V_79 ) ;
if ( V_81 )
V_5 -> V_10 |= V_15 ;
}
static void F_23 ( struct V_4 * V_5 )
{
V_5 -> V_12 |= V_86 ;
}
static int F_24 ( struct V_4 * V_5 , int V_87 )
{
unsigned int V_88 = 0 ;
if ( V_87 == V_89 )
V_88 = 2 ;
return ( ( ( V_5 -> V_10 & V_90 ) >> V_91 ) -
V_88 ) ;
}
static void F_25 ( struct V_4 * V_5 )
{
V_5 -> V_12 |= V_92 ;
}
static int F_26 ( struct V_4 * V_5 )
{
return ( V_5 -> V_10 & V_93 ) >> 17 ;
}
static T_2 F_27 ( void * V_94 , T_3 V_95 )
{
struct V_4 * V_5 = (struct V_4 * ) V_94 ;
T_2 V_96 ;
V_96 = V_5 -> V_77 ;
V_96 += V_5 -> V_97 * 1000000000ULL ;
return V_96 ;
}
static int F_28 ( void * V_94 , T_3 V_95 )
{
struct V_4 * V_5 = (struct V_4 * ) V_94 ;
if ( ( V_5 -> V_77 == 0xffffffff ) && ( V_5 -> V_97 == 0xffffffff ) )
return 0 ;
else
return 1 ;
}
