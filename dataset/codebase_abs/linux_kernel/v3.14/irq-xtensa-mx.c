static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_4 )
{
if ( V_4 < V_5 ) {
struct V_6 * V_6 = V_2 -> V_7 ;
F_2 ( V_3 , V_6 ,
V_8 , L_1 ) ;
F_3 ( V_3 , V_9 ) ;
return 0 ;
}
return F_4 ( V_2 , V_3 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
const T_2 * V_12 , unsigned int V_13 ,
unsigned long * V_14 , unsigned int * V_15 )
{
return F_6 ( V_12 , V_13 ,
V_12 [ 0 ] , V_12 [ 0 ] + V_16 ,
V_14 , V_15 ) ;
}
void F_7 ( void )
{
F_8 ( V_17 ,
V_18 |
V_19 ) ;
F_9 ( V_18 |
V_19 , V_20 ) ;
}
static void F_10 ( struct V_21 * V_2 )
{
unsigned int V_22 = 1u << V_2 -> V_23 ;
if ( V_22 & ( V_18 |
V_19 ) ) {
F_11 ( 1u << ( F_12 ( V_2 -> V_23 ) -
V_24 ) , V_25 ) ;
} else {
V_22 = F_13 ( V_17 ) & ~ V_22 ;
F_8 ( V_17 , V_22 ) ;
F_9 ( V_22 , V_20 ) ;
}
}
static void F_14 ( struct V_21 * V_2 )
{
unsigned int V_22 = 1u << V_2 -> V_23 ;
if ( V_22 & ( V_18 |
V_19 ) ) {
F_11 ( 1u << ( F_12 ( V_2 -> V_23 ) -
V_24 ) , V_26 ) ;
} else {
V_22 |= F_13 ( V_17 ) ;
F_8 ( V_17 , V_22 ) ;
F_9 ( V_22 , V_20 ) ;
}
}
static void F_15 ( struct V_21 * V_2 )
{
F_16 ( V_2 -> V_23 ) ;
F_14 ( V_2 ) ;
}
static void F_17 ( struct V_21 * V_2 )
{
F_10 ( V_2 ) ;
F_18 ( V_2 -> V_23 ) ;
}
static void F_19 ( struct V_21 * V_2 )
{
F_9 ( 1 << V_2 -> V_23 , V_27 ) ;
}
static int F_20 ( struct V_21 * V_2 )
{
F_9 ( 1 << V_2 -> V_23 , V_28 ) ;
return 1 ;
}
static int F_21 ( struct V_21 * V_2 ,
const struct V_29 * V_30 , bool V_31 )
{
unsigned V_22 = 1u << F_22 ( V_30 ) ;
F_11 ( V_22 , F_23 ( V_2 -> V_23 - V_24 ) ) ;
return 0 ;
}
int T_3 F_24 ( struct V_10 * V_32 )
{
struct V_1 * V_33 =
F_25 ( NULL , V_34 , 0 , 0 ,
& V_35 ,
& V_36 ) ;
F_26 ( V_33 ) ;
F_7 () ;
return 0 ;
}
static int T_3 F_27 ( struct V_10 * V_37 ,
struct V_10 * V_32 )
{
struct V_1 * V_33 =
F_28 ( V_37 , V_34 , & V_35 ,
& V_36 ) ;
F_26 ( V_33 ) ;
F_7 () ;
return 0 ;
}
