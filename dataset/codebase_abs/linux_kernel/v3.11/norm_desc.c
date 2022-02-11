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
if ( V_5 -> V_10 . V_26 . V_27 )
V_3 -> V_28 ++ ;
if ( F_2 ( V_5 -> V_10 . V_11 . V_29 ) )
V_3 -> V_30 ++ ;
return V_7 ;
}
static int F_3 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_11 . V_31 ;
}
static int F_4 ( void * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 )
{
int V_7 = V_32 ;
struct V_8 * V_9 = (struct V_8 * ) V_1 ;
if ( F_2 ( V_5 -> V_10 . V_33 . V_34 == 0 ) ) {
F_5 ( L_1 ,
V_35 ) ;
V_9 -> V_36 ++ ;
return V_37 ;
}
if ( F_2 ( V_5 -> V_10 . V_33 . V_12 ) ) {
if ( F_2 ( V_5 -> V_10 . V_33 . V_38 ) )
V_3 -> V_39 ++ ;
if ( F_2 ( V_5 -> V_10 . V_33 . V_40 ) )
V_3 -> V_40 ++ ;
if ( F_2 ( V_5 -> V_10 . V_33 . V_41 ) )
V_3 -> V_41 ++ ;
if ( F_2 ( V_5 -> V_10 . V_33 . V_42 ) )
V_3 -> V_42 ++ ;
if ( F_2 ( V_5 -> V_10 . V_33 . V_43 ) ) {
V_3 -> V_44 ++ ;
V_9 -> V_24 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_33 . V_45 ) ) {
V_3 -> V_46 ++ ;
V_9 -> V_47 ++ ;
}
V_7 = V_37 ;
}
if ( F_2 ( V_5 -> V_10 . V_33 . V_48 ) )
V_3 -> V_49 ++ ;
if ( F_2 ( V_5 -> V_10 . V_33 . V_50 ) ) {
V_3 -> V_51 ++ ;
V_7 = V_37 ;
}
if ( F_2 ( V_5 -> V_10 . V_33 . V_52 ) ) {
V_3 -> V_53 ++ ;
V_7 = V_37 ;
}
#ifdef F_6
if ( V_5 -> V_10 . V_33 . V_54 )
V_3 -> V_54 ++ ;
#endif
return V_7 ;
}
static void F_7 ( struct V_4 * V_5 , int V_55 , int V_56 ,
int V_57 )
{
V_5 -> V_10 . V_33 . V_58 = 1 ;
V_5 -> V_10 . V_33 . V_31 = V_59 - 1 ;
if ( V_56 == V_60 )
F_8 ( V_5 , V_57 ) ;
else
F_9 ( V_5 , V_57 ) ;
if ( V_55 )
V_5 -> V_10 . V_33 . V_61 = 1 ;
}
static void F_10 ( struct V_4 * V_5 , int V_56 , int V_57 )
{
V_5 -> V_10 . V_11 . V_58 = 0 ;
if ( V_56 == V_60 )
F_11 ( V_5 , V_57 ) ;
else
F_12 ( V_5 , V_57 ) ;
}
static int F_13 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_11 . V_58 ;
}
static int F_14 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_33 . V_58 ;
}
static void F_15 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_11 . V_58 = 1 ;
}
static void F_16 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_33 . V_58 = 1 ;
}
static int F_17 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_11 . V_62 ;
}
static void F_18 ( struct V_4 * V_5 , int V_56 )
{
int V_63 = V_5 -> V_10 . V_11 . V_64 ;
memset ( V_5 , 0 , F_19 ( struct V_4 , V_65 ) ) ;
if ( V_56 == V_60 )
F_20 ( V_5 , V_63 ) ;
else
F_21 ( V_5 , V_63 ) ;
}
static void F_22 ( struct V_4 * V_5 , int V_66 , int V_67 ,
int V_68 , int V_56 )
{
V_5 -> V_10 . V_11 . V_69 = V_66 ;
if ( V_56 == V_60 )
F_23 ( V_5 , V_67 ) ;
else
F_24 ( V_5 , V_67 ) ;
if ( F_25 ( V_68 ) )
V_5 -> V_10 . V_11 . V_70 = V_71 ;
}
static void F_26 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_11 . V_72 = 0 ;
}
static void F_27 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_11 . V_62 = 1 ;
V_5 -> V_10 . V_11 . V_72 = 1 ;
}
static int F_28 ( struct V_4 * V_5 , int V_73 )
{
if ( V_73 == V_74 )
return V_5 -> V_10 . V_33 . V_75 - 2 ;
else
return V_5 -> V_10 . V_33 . V_75 ;
}
static void F_29 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_11 . V_76 = 1 ;
}
static int F_30 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_11 . V_77 ;
}
static T_2 F_31 ( void * V_78 , T_3 V_79 )
{
struct V_4 * V_5 = (struct V_4 * ) V_78 ;
T_2 V_80 ;
V_80 = V_5 -> V_65 ;
V_80 += V_5 -> V_81 * 1000000000ULL ;
return V_80 ;
}
static int F_32 ( void * V_78 , T_3 V_79 )
{
struct V_4 * V_5 = (struct V_4 * ) V_78 ;
if ( ( V_5 -> V_65 == 0xffffffff ) && ( V_5 -> V_81 == 0xffffffff ) )
return 0 ;
else
return 1 ;
}
