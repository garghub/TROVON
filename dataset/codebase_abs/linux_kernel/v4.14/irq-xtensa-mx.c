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
F_4 ( F_5 ( F_6 ( V_3 ) ) ) ;
return F_7 ( V_2 , V_3 , V_4 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
const T_2 * V_12 , unsigned int V_13 ,
unsigned long * V_14 , unsigned int * V_15 )
{
return F_9 ( V_12 , V_13 ,
V_12 [ 0 ] , V_12 [ 0 ] + V_16 ,
V_14 , V_15 ) ;
}
void F_10 ( void )
{
F_11 ( V_17 ,
V_18 |
V_19 ) ;
F_12 ( V_18 |
V_19 , V_20 ) ;
}
static void F_13 ( struct V_21 * V_2 )
{
unsigned int V_22 = 1u << V_2 -> V_23 ;
if ( V_22 & ( V_18 |
V_19 ) ) {
F_14 ( 1u << ( F_15 ( V_2 -> V_23 ) -
V_24 ) , V_25 ) ;
} else {
V_22 = F_16 ( V_17 ) & ~ V_22 ;
F_11 ( V_17 , V_22 ) ;
F_12 ( V_22 , V_20 ) ;
}
}
static void F_17 ( struct V_21 * V_2 )
{
unsigned int V_22 = 1u << V_2 -> V_23 ;
if ( V_22 & ( V_18 |
V_19 ) ) {
F_14 ( 1u << ( F_15 ( V_2 -> V_23 ) -
V_24 ) , V_26 ) ;
} else {
V_22 |= F_16 ( V_17 ) ;
F_11 ( V_17 , V_22 ) ;
F_12 ( V_22 , V_20 ) ;
}
}
static void F_18 ( struct V_21 * V_2 )
{
F_19 ( V_2 -> V_23 ) ;
F_17 ( V_2 ) ;
}
static void F_20 ( struct V_21 * V_2 )
{
F_13 ( V_2 ) ;
F_21 ( V_2 -> V_23 ) ;
}
static void F_22 ( struct V_21 * V_2 )
{
F_12 ( 1 << V_2 -> V_23 , V_27 ) ;
}
static int F_23 ( struct V_21 * V_2 )
{
F_12 ( 1 << V_2 -> V_23 , V_28 ) ;
return 1 ;
}
static int F_24 ( struct V_21 * V_2 ,
const struct V_29 * V_30 , bool V_31 )
{
int V_32 = F_25 ( V_30 , V_33 ) ;
unsigned V_22 = 1u << V_32 ;
F_14 ( V_22 , F_26 ( V_2 -> V_23 - V_24 ) ) ;
F_27 ( V_2 , F_28 ( V_32 ) ) ;
return 0 ;
}
int T_3 F_29 ( struct V_10 * V_34 )
{
struct V_1 * V_35 =
F_30 ( NULL , V_36 - 1 , 1 , 0 ,
& V_37 ,
& V_38 ) ;
F_31 ( V_35 ) ;
F_10 () ;
return 0 ;
}
static int T_3 F_32 ( struct V_10 * V_39 ,
struct V_10 * V_34 )
{
struct V_1 * V_35 =
F_33 ( V_39 , V_36 , & V_37 ,
& V_38 ) ;
F_31 ( V_35 ) ;
F_10 () ;
return 0 ;
}
