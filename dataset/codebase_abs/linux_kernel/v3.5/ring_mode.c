static unsigned int F_1 ( void * V_1 , struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_1 ;
unsigned int V_7 = V_6 -> V_8 ;
unsigned int V_9 = V_6 -> V_10 % V_7 ;
struct V_11 * V_12 = V_6 -> V_13 + V_9 ;
unsigned int V_14 = F_2 ( V_3 ) ;
unsigned int V_15 , V_16 ;
if ( V_6 -> V_17 -> V_18 )
V_15 = V_19 ;
else
V_15 = V_20 ;
V_16 = V_14 - V_15 ;
if ( V_14 > V_19 ) {
V_12 -> V_21 = F_3 ( V_6 -> V_22 , V_3 -> V_23 ,
V_15 , V_24 ) ;
V_12 -> V_25 = V_12 -> V_21 + V_26 ;
V_6 -> V_27 -> V_12 -> V_28 ( V_12 , 1 , V_15 ,
V_4 ) ;
F_4 () ;
V_9 = ( ++ V_6 -> V_10 ) % V_7 ;
V_12 = V_6 -> V_13 + V_9 ;
V_12 -> V_21 = F_3 ( V_6 -> V_22 , V_3 -> V_23 + V_15 ,
V_16 , V_24 ) ;
V_12 -> V_25 = V_12 -> V_21 + V_26 ;
V_6 -> V_27 -> V_12 -> V_28 ( V_12 , 0 , V_16 , V_4 ) ;
F_4 () ;
V_6 -> V_27 -> V_12 -> V_29 ( V_12 ) ;
V_6 -> V_30 [ V_9 ] = NULL ;
} else {
V_12 -> V_21 = F_3 ( V_6 -> V_22 , V_3 -> V_23 ,
V_14 , V_24 ) ;
V_12 -> V_25 = V_12 -> V_21 + V_26 ;
V_6 -> V_27 -> V_12 -> V_28 ( V_12 , 1 , V_14 , V_4 ) ;
}
return V_9 ;
}
static unsigned int F_5 ( int V_16 , int V_18 )
{
unsigned int V_31 = 0 ;
if ( V_16 >= V_26 )
V_31 = 1 ;
return V_31 ;
}
static void F_6 ( int V_32 , struct V_11 * V_1 )
{
if ( V_32 >= V_19 )
V_1 -> V_25 = V_1 -> V_21 + V_19 ;
}
static void F_7 ( int V_33 , struct V_11 * V_1 )
{
if ( F_8 ( V_33 ) )
V_1 -> V_25 = V_1 -> V_21 + V_19 ;
}
static void F_9 ( struct V_11 * V_34 , T_1 V_35 ,
unsigned int V_36 )
{
}
static void F_10 ( struct V_11 * V_1 )
{
if ( F_8 ( V_1 -> V_25 ) )
V_1 -> V_25 = 0 ;
}
static int F_11 ( int V_37 )
{
int V_31 = 0 ;
if ( F_8 ( V_37 >= V_19 ) )
V_31 = V_38 ;
return V_31 ;
}
