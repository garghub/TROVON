static int F_1 ( void * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , void T_1 * V_6 )
{
int V_7 = 0 ;
struct V_8 * V_9 = (struct V_8 * ) V_1 ;
if ( F_2 ( V_5 -> V_10 . V_11 . V_12 ) ) {
if ( F_2 ( V_5 -> V_10 . V_11 . V_13 ) ) {
V_3 -> V_14 ++ ;
V_9 -> V_15 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_16 ) ) {
V_3 -> V_17 ++ ;
V_9 -> V_18 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_19 ) ) {
V_3 -> V_20 ++ ;
V_9 -> V_18 ++ ;
}
if ( F_2 ( ( V_5 -> V_10 . V_11 . V_21 ) ||
( V_5 -> V_10 . V_11 . V_22 ) ||
( V_5 -> V_10 . V_11 . V_23 ) ) )
V_9 -> V_24 += V_5 -> V_10 . V_11 . V_25 ;
V_7 = - 1 ;
}
if ( V_5 -> V_10 . V_26 . V_27 ) {
F_3 ( V_28 L_1 ) ;
V_3 -> V_29 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_11 . V_30 ) )
V_3 -> V_31 ++ ;
return V_7 ;
}
static int F_4 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_11 . V_32 ;
}
static int F_5 ( void * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 )
{
int V_7 = V_33 ;
struct V_8 * V_9 = (struct V_8 * ) V_1 ;
if ( F_2 ( V_5 -> V_10 . V_34 . V_35 == 0 ) ) {
F_6 ( L_2 ,
V_36 ) ;
V_9 -> V_37 ++ ;
return V_38 ;
}
if ( F_2 ( V_5 -> V_10 . V_34 . V_12 ) ) {
if ( F_2 ( V_5 -> V_10 . V_34 . V_39 ) )
V_3 -> V_40 ++ ;
if ( F_2 ( V_5 -> V_10 . V_34 . V_41 ) )
V_3 -> V_41 ++ ;
if ( F_2 ( V_5 -> V_10 . V_34 . V_42 ) )
V_3 -> V_42 ++ ;
if ( F_2 ( V_5 -> V_10 . V_34 . V_43 ) )
V_3 -> V_43 ++ ;
if ( F_2 ( V_5 -> V_10 . V_34 . V_44 ) ) {
V_3 -> V_45 ++ ;
V_9 -> V_24 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_34 . V_46 ) ) {
V_3 -> V_47 ++ ;
V_9 -> V_48 ++ ;
}
V_7 = V_38 ;
}
if ( F_2 ( V_5 -> V_10 . V_34 . V_49 ) )
V_3 -> V_50 ++ ;
if ( F_2 ( V_5 -> V_10 . V_34 . V_51 ) ) {
V_3 -> V_52 ++ ;
V_7 = V_38 ;
}
if ( F_2 ( V_5 -> V_10 . V_34 . V_53 ) ) {
V_3 -> V_54 ++ ;
V_7 = V_38 ;
}
#ifdef F_7
if ( V_5 -> V_10 . V_34 . V_55 )
V_3 -> V_55 ++ ;
#endif
return V_7 ;
}
static void F_8 ( struct V_4 * V_5 , int V_56 , int V_57 ,
int V_58 )
{
V_5 -> V_10 . V_34 . V_59 = 1 ;
V_5 -> V_10 . V_34 . V_32 = V_60 - 1 ;
if ( V_57 == V_61 )
F_9 ( V_5 , V_58 ) ;
else
F_10 ( V_5 , V_58 ) ;
if ( V_56 )
V_5 -> V_10 . V_34 . V_62 = 1 ;
}
static void F_11 ( struct V_4 * V_5 , int V_57 , int V_58 )
{
V_5 -> V_10 . V_11 . V_59 = 0 ;
if ( V_57 == V_61 )
F_12 ( V_5 , V_58 ) ;
else
F_13 ( V_5 , V_58 ) ;
}
static int F_14 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_11 . V_59 ;
}
static int F_15 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_34 . V_59 ;
}
static void F_16 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_11 . V_59 = 1 ;
}
static void F_17 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_34 . V_59 = 1 ;
}
static int F_18 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_11 . V_63 ;
}
static void F_19 ( struct V_4 * V_5 , int V_57 )
{
int V_64 = V_5 -> V_10 . V_11 . V_65 ;
memset ( V_5 , 0 , F_20 ( struct V_4 , V_66 ) ) ;
if ( V_57 == V_61 )
F_21 ( V_5 , V_64 ) ;
else
F_22 ( V_5 , V_64 ) ;
}
static void F_23 ( struct V_4 * V_5 , int V_67 , int V_68 ,
int V_69 , int V_57 )
{
V_5 -> V_10 . V_11 . V_70 = V_67 ;
if ( V_57 == V_61 )
F_24 ( V_5 , V_68 ) ;
else
F_25 ( V_5 , V_68 ) ;
if ( F_26 ( V_69 ) )
V_5 -> V_10 . V_11 . V_71 = V_72 ;
}
static void F_27 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_11 . V_73 = 0 ;
}
static void F_28 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_11 . V_63 = 1 ;
V_5 -> V_10 . V_11 . V_73 = 1 ;
}
static int F_29 ( struct V_4 * V_5 , int V_74 )
{
if ( V_74 == V_75 )
return V_5 -> V_10 . V_34 . V_76 - 2 ;
else
return V_5 -> V_10 . V_34 . V_76 ;
}
static void F_30 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_11 . V_77 = 1 ;
}
static int F_31 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_11 . V_78 ;
}
static T_2 F_32 ( void * V_79 , T_3 V_80 )
{
struct V_4 * V_5 = (struct V_4 * ) V_79 ;
T_2 V_81 ;
V_81 = V_5 -> V_66 ;
V_81 += V_5 -> V_82 * 1000000000ULL ;
return V_81 ;
}
static int F_33 ( void * V_79 , T_3 V_80 )
{
struct V_4 * V_5 = (struct V_4 * ) V_79 ;
if ( ( V_5 -> V_66 == 0xffffffff ) && ( V_5 -> V_82 == 0xffffffff ) )
return 0 ;
else
return 1 ;
}
