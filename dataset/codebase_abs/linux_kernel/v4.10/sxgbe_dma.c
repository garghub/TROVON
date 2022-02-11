static int F_1 ( void T_1 * V_1 , int V_2 , int V_3 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 + V_5 ) ;
if ( ! V_2 )
V_4 |= V_6 ;
V_4 |= ( V_3 << V_7 ) ;
F_3 ( V_4 , V_1 + V_5 ) ;
return 0 ;
}
static void F_4 ( void T_1 * V_1 , int V_8 ,
int V_2 , int V_9 , T_3 V_10 ,
T_3 V_11 , int V_12 , int V_13 )
{
T_2 V_4 ;
T_3 V_14 ;
V_4 = F_2 ( V_1 + F_5 ( V_8 ) ) ;
if ( V_2 ) {
V_4 |= V_15 ;
F_3 ( V_4 , V_1 + F_5 ( V_8 ) ) ;
V_4 = F_2 ( V_1 + F_6 ( V_8 ) ) ;
V_4 |= ( V_9 << V_16 ) ;
F_3 ( V_4 , V_1 + F_6 ( V_8 ) ) ;
V_4 = F_2 ( V_1 + F_7 ( V_8 ) ) ;
V_4 |= ( V_9 << V_17 ) ;
F_3 ( V_4 , V_1 + F_7 ( V_8 ) ) ;
}
F_3 ( F_8 ( V_10 ) ,
V_1 + F_9 ( V_8 ) ) ;
F_3 ( F_10 ( V_10 ) ,
V_1 + F_11 ( V_8 ) ) ;
F_3 ( F_8 ( V_11 ) ,
V_1 + F_12 ( V_8 ) ) ;
F_3 ( F_10 ( V_11 ) ,
V_1 + F_13 ( V_8 ) ) ;
V_14 = V_10 + ( ( V_12 - 1 ) * V_18 ) ;
F_3 ( F_10 ( V_14 ) ,
V_1 + F_14 ( V_8 ) ) ;
V_14 = V_11 + ( ( V_13 - 1 ) * V_18 ) ;
F_3 ( F_10 ( V_14 ) ,
V_1 + F_13 ( V_8 ) ) ;
F_3 ( V_12 - 1 , V_1 + F_15 ( V_8 ) ) ;
F_3 ( V_13 - 1 , V_1 + F_16 ( V_8 ) ) ;
F_3 ( V_19 ,
V_1 + F_17 ( V_8 ) ) ;
}
static void F_18 ( void T_1 * V_1 , int V_8 )
{
T_2 V_20 ;
V_20 = F_2 ( V_1 + F_6 ( V_8 ) ) ;
V_20 |= V_21 ;
F_3 ( V_20 , V_1 + F_6 ( V_8 ) ) ;
}
static void F_19 ( void T_1 * V_1 , int V_22 )
{
F_3 ( V_19 ,
V_1 + F_17 ( V_22 ) ) ;
}
static void F_20 ( void T_1 * V_1 , int V_22 )
{
F_3 ( 0 , V_1 + F_17 ( V_22 ) ) ;
}
static void F_21 ( void T_1 * V_1 , int V_23 )
{
int V_24 ;
T_2 V_25 ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ ) {
V_25 = F_2 ( V_1 + F_6 ( V_24 ) ) ;
V_25 |= V_26 ;
F_3 ( V_25 ,
V_1 + F_6 ( V_24 ) ) ;
}
}
static void F_22 ( void T_1 * V_1 , int V_22 )
{
T_2 V_25 ;
V_25 = F_2 ( V_1 + F_6 ( V_22 ) ) ;
V_25 |= V_26 ;
F_3 ( V_25 , V_1 + F_6 ( V_22 ) ) ;
}
static void F_23 ( void T_1 * V_1 , int V_22 )
{
T_2 V_25 ;
V_25 = F_2 ( V_1 + F_6 ( V_22 ) ) ;
V_25 &= ~ ( V_26 ) ;
F_3 ( V_25 , V_1 + F_6 ( V_22 ) ) ;
}
static void F_24 ( void T_1 * V_1 , int V_23 )
{
int V_24 ;
T_2 V_25 ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ ) {
V_25 = F_2 ( V_1 + F_6 ( V_24 ) ) ;
V_25 &= ~ ( V_26 ) ;
F_3 ( V_25 , V_1 + F_6 ( V_24 ) ) ;
}
}
static void F_25 ( void T_1 * V_1 , int V_27 )
{
int V_24 ;
T_2 V_28 ;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
V_28 = F_2 ( V_1 + F_7 ( V_24 ) ) ;
V_28 |= V_29 ;
F_3 ( V_28 ,
V_1 + F_7 ( V_24 ) ) ;
}
}
static void F_26 ( void T_1 * V_1 , int V_27 )
{
int V_24 ;
T_2 V_28 ;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
V_28 = F_2 ( V_1 + F_7 ( V_24 ) ) ;
V_28 &= ~ ( V_29 ) ;
F_3 ( V_28 , V_1 + F_7 ( V_24 ) ) ;
}
}
static int F_27 ( void T_1 * V_1 , int V_30 ,
struct V_31 * V_32 )
{
T_2 V_33 = F_2 ( V_1 + F_28 ( V_30 ) ) ;
T_2 V_34 = 0 ;
T_2 V_35 = 0 ;
if ( F_29 ( V_33 & V_36 ) ) {
V_32 -> V_37 ++ ;
if ( V_33 & V_38 ) {
V_35 |= V_39 ;
V_32 -> V_40 ++ ;
V_34 |= V_38 ;
}
if ( V_33 & V_41 ) {
V_32 -> V_42 ++ ;
V_35 |= V_43 ;
V_34 |= V_41 ;
}
} else if ( F_30 ( V_33 & V_44 ) ) {
if ( V_33 & V_45 ) {
V_35 |= V_46 ;
V_34 |= V_45 ;
V_32 -> V_47 ++ ;
}
if ( V_33 & V_48 ) {
V_35 |= V_46 ;
V_32 -> V_49 ++ ;
if ( V_33 & V_50 ) {
V_32 -> V_51 ++ ;
V_34 |= V_50 ;
} else {
V_32 -> V_52 ++ ;
}
if ( V_33 & V_53 ) {
V_32 -> V_54 ++ ;
V_34 |= V_53 ;
} else {
V_32 -> V_55 ++ ;
}
if ( V_33 & V_56 ) {
V_32 -> V_57 ++ ;
V_34 |= V_56 ;
}
}
if ( V_33 & V_58 ) {
V_32 -> V_59 ++ ;
V_34 |= V_58 ;
}
}
F_3 ( V_34 , V_1 + F_28 ( V_30 ) ) ;
return V_35 ;
}
static int F_31 ( void T_1 * V_1 , int V_30 ,
struct V_31 * V_32 )
{
T_2 V_33 = F_2 ( V_1 + F_28 ( V_30 ) ) ;
T_2 V_34 = 0 ;
T_2 V_35 = 0 ;
if ( F_29 ( V_33 & V_36 ) ) {
V_32 -> V_37 ++ ;
if ( V_33 & V_60 ) {
V_35 |= V_61 ;
V_32 -> V_62 ++ ;
V_34 |= V_60 ;
}
} else if ( F_30 ( V_33 & V_44 ) ) {
if ( V_33 & V_63 ) {
V_35 |= V_64 ;
V_34 |= V_63 ;
V_32 -> V_65 ++ ;
}
if ( V_33 & V_66 ) {
V_35 |= V_67 ;
V_34 |= V_66 ;
V_32 -> V_68 ++ ;
}
if ( V_33 & V_48 ) {
V_35 |= V_67 ;
V_32 -> V_49 ++ ;
if ( V_33 & V_69 ) {
V_32 -> V_70 ++ ;
V_34 |= V_69 ;
} else {
V_32 -> V_71 ++ ;
}
if ( V_33 & V_72 ) {
V_32 -> V_73 ++ ;
V_34 |= V_72 ;
} else {
V_32 -> V_74 ++ ;
}
if ( V_33 & V_75 ) {
V_32 -> V_76 ++ ;
V_34 |= V_75 ;
}
}
}
F_3 ( V_34 , V_1 + F_28 ( V_30 ) ) ;
return V_35 ;
}
static void F_32 ( void T_1 * V_1 , T_2 V_77 )
{
T_2 V_78 ;
F_33 (SXGBE_RX_QUEUES, que_num) {
F_3 ( V_77 ,
V_1 + F_34 ( V_78 ) ) ;
}
}
static void F_35 ( void T_1 * V_1 , T_4 V_79 )
{
T_2 V_80 ;
V_80 = F_2 ( V_1 + F_6 ( V_79 ) ) ;
V_80 |= V_81 ;
F_3 ( V_80 , V_1 + F_6 ( V_79 ) ) ;
}
const struct V_82 * F_36 ( void )
{
return & V_82 ;
}
