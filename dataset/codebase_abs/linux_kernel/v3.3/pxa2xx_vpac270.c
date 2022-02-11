static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_4 == 0 ) {
V_3 = F_2 ( V_5 ,
F_3 ( V_5 ) ) ;
V_2 -> V_6 . V_7 = F_4 ( V_8 ) ;
V_9 [ 0 ] . V_10 = F_4 ( V_11 ) ;
if ( ! V_3 )
V_3 = F_5 ( V_2 , & V_9 [ 0 ] , 1 ) ;
} else {
V_3 = F_2 ( V_12 ,
F_3 ( V_12 ) ) ;
V_2 -> V_6 . V_7 = F_4 ( V_13 ) ;
V_9 [ 1 ] . V_10 = F_4 ( V_14 ) ;
if ( ! V_3 )
V_3 = F_5 ( V_2 , & V_9 [ 1 ] , 1 ) ;
}
return V_3 ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 == 0 )
F_7 ( V_5 ,
F_3 ( V_5 ) ) ;
else
F_7 ( V_12 ,
F_3 ( V_12 ) ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
if ( V_2 -> V_4 == 0 ) {
V_16 -> V_17 = ! F_9 ( V_11 ) ;
V_16 -> V_18 = ! ! F_9 ( V_8 ) ;
} else {
V_16 -> V_17 = ! F_9 ( V_14 ) ;
V_16 -> V_18 = ! ! F_9 ( V_13 ) ;
}
V_16 -> V_19 = 1 ;
V_16 -> V_20 = 1 ;
V_16 -> V_21 = 0 ;
V_16 -> V_22 = 1 ;
V_16 -> V_23 = 0 ;
}
static int
F_10 ( struct V_1 * V_2 ,
const T_1 * V_16 )
{
if ( V_2 -> V_4 == 0 ) {
F_11 ( V_24 ,
( V_16 -> V_25 & V_26 ) ) ;
F_11 ( V_27 ,
! ( V_16 -> V_28 == 33 || V_16 -> V_28 == 50 ) ) ;
} else {
F_11 ( V_29 ,
( V_16 -> V_25 & V_26 ) ) ;
}
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
}
static void F_13 ( struct V_1 * V_2 )
{
}
static int T_2 F_14 ( void )
{
int V_3 ;
if ( ! F_15 () )
return - V_30 ;
V_31 = F_16 ( L_1 , - 1 ) ;
if ( ! V_31 )
return - V_32 ;
V_3 = F_17 ( V_31 ,
& V_33 , sizeof( V_33 ) ) ;
if ( ! V_3 )
V_3 = F_18 ( V_31 ) ;
if ( V_3 )
F_19 ( V_31 ) ;
return V_3 ;
}
static void T_3 F_20 ( void )
{
F_21 ( V_31 ) ;
}
