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
F_6 ( L_2
L_3 ) ;
V_9 -> V_36 ++ ;
return V_37 ;
}
if ( F_2 ( V_5 -> V_10 . V_34 . V_12 ) ) {
if ( F_2 ( V_5 -> V_10 . V_34 . V_38 ) )
V_3 -> V_39 ++ ;
if ( F_2 ( V_5 -> V_10 . V_34 . V_40 ) )
V_3 -> V_40 ++ ;
if ( F_2 ( V_5 -> V_10 . V_34 . V_41 ) )
V_3 -> V_41 ++ ;
if ( F_2 ( V_5 -> V_10 . V_34 . V_42 ) )
V_3 -> V_42 ++ ;
if ( F_2 ( V_5 -> V_10 . V_34 . V_43 ) ) {
V_3 -> V_44 ++ ;
V_9 -> V_24 ++ ;
}
if ( F_2 ( V_5 -> V_10 . V_34 . V_45 ) ) {
V_3 -> V_46 ++ ;
V_9 -> V_47 ++ ;
}
V_7 = V_37 ;
}
if ( F_2 ( V_5 -> V_10 . V_34 . V_48 ) )
V_3 -> V_49 ++ ;
if ( F_2 ( V_5 -> V_10 . V_34 . V_50 ) ) {
V_3 -> V_51 ++ ;
V_7 = V_37 ;
}
if ( F_2 ( V_5 -> V_10 . V_34 . V_52 ) ) {
V_3 -> V_53 ++ ;
V_7 = V_37 ;
}
#ifdef F_7
if ( V_5 -> V_10 . V_34 . V_54 )
V_3 -> V_54 ++ ;
#endif
return V_7 ;
}
static void F_8 ( struct V_4 * V_5 , unsigned int V_55 ,
int V_56 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_55 ; V_57 ++ ) {
V_5 -> V_10 . V_34 . V_58 = 1 ;
V_5 -> V_10 . V_34 . V_32 = V_59 - 1 ;
F_9 ( V_5 , ( V_57 == V_55 - 1 ) ) ;
if ( V_56 )
V_5 -> V_10 . V_34 . V_60 = 1 ;
V_5 ++ ;
}
}
static void F_10 ( struct V_4 * V_5 , unsigned int V_55 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_55 ; V_57 ++ ) {
V_5 -> V_10 . V_11 . V_58 = 0 ;
F_11 ( V_5 , ( V_57 == ( V_55 - 1 ) ) ) ;
V_5 ++ ;
}
}
static int F_12 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_11 . V_58 ;
}
static int F_13 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_34 . V_58 ;
}
static void F_14 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_11 . V_58 = 1 ;
}
static void F_15 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_34 . V_58 = 1 ;
}
static int F_16 ( struct V_4 * V_5 )
{
return V_5 -> V_10 . V_11 . V_61 ;
}
static void F_17 ( struct V_4 * V_5 )
{
int V_62 = V_5 -> V_10 . V_11 . V_63 ;
memset ( V_5 , 0 , F_18 ( struct V_4 , V_64 ) ) ;
F_19 ( V_5 , V_62 ) ;
}
static void F_20 ( struct V_4 * V_5 , int V_65 , int V_66 ,
int V_67 )
{
V_5 -> V_10 . V_11 . V_68 = V_65 ;
F_21 ( V_5 , V_66 ) ;
if ( F_22 ( V_67 ) )
V_5 -> V_10 . V_11 . V_69 = V_70 ;
}
static void F_23 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_11 . V_71 = 0 ;
}
static void F_24 ( struct V_4 * V_5 )
{
V_5 -> V_10 . V_11 . V_61 = 1 ;
V_5 -> V_10 . V_11 . V_71 = 1 ;
}
static int F_25 ( struct V_4 * V_5 , int V_72 )
{
if ( V_72 == V_73 )
return V_5 -> V_10 . V_34 . V_74 - 2 ;
else
return V_5 -> V_10 . V_34 . V_74 ;
}
