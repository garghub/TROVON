static int F_1 ( void * V_1 , struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_1 ;
unsigned int V_7 = V_6 -> V_8 ;
unsigned int V_9 = V_6 -> V_10 % V_7 ;
struct V_11 * V_12 ;
unsigned int V_13 = F_2 ( V_3 ) ;
unsigned int V_14 , V_15 ;
if ( V_6 -> V_16 )
V_12 = (struct V_11 * ) ( V_6 -> V_17 + V_9 ) ;
else
V_12 = V_6 -> V_18 + V_9 ;
if ( V_6 -> V_19 -> V_20 )
V_14 = V_21 ;
else
V_14 = V_22 ;
V_15 = V_13 - V_14 ;
if ( V_13 > V_21 ) {
V_12 -> V_23 = F_3 ( V_6 -> V_24 , V_3 -> V_25 ,
V_14 , V_26 ) ;
if ( F_4 ( V_6 -> V_24 , V_12 -> V_23 ) )
return - 1 ;
V_6 -> V_27 [ V_9 ] . V_28 = V_12 -> V_23 ;
V_12 -> V_29 = V_12 -> V_23 + V_30 ;
V_6 -> V_31 -> V_12 -> V_32 ( V_12 , 1 , V_14 , V_4 ,
V_33 ) ;
F_5 () ;
V_6 -> V_34 [ V_9 ] = NULL ;
V_9 = ( ++ V_6 -> V_10 ) % V_7 ;
if ( V_6 -> V_16 )
V_12 = (struct V_11 * ) ( V_6 -> V_17 + V_9 ) ;
else
V_12 = V_6 -> V_18 + V_9 ;
V_12 -> V_23 = F_3 ( V_6 -> V_24 , V_3 -> V_25 + V_14 ,
V_15 , V_26 ) ;
if ( F_4 ( V_6 -> V_24 , V_12 -> V_23 ) )
return - 1 ;
V_6 -> V_27 [ V_9 ] . V_28 = V_12 -> V_23 ;
V_12 -> V_29 = V_12 -> V_23 + V_30 ;
V_6 -> V_31 -> V_12 -> V_32 ( V_12 , 0 , V_15 , V_4 ,
V_33 ) ;
F_5 () ;
V_6 -> V_31 -> V_12 -> V_35 ( V_12 ) ;
} else {
V_12 -> V_23 = F_3 ( V_6 -> V_24 , V_3 -> V_25 ,
V_13 , V_26 ) ;
if ( F_4 ( V_6 -> V_24 , V_12 -> V_23 ) )
return - 1 ;
V_6 -> V_27 [ V_9 ] . V_28 = V_12 -> V_23 ;
V_12 -> V_29 = V_12 -> V_23 + V_30 ;
V_6 -> V_31 -> V_12 -> V_32 ( V_12 , 1 , V_13 , V_4 ,
V_33 ) ;
}
return V_9 ;
}
static unsigned int F_6 ( int V_15 , int V_20 )
{
unsigned int V_36 = 0 ;
if ( V_15 >= V_30 )
V_36 = 1 ;
return V_36 ;
}
static void F_7 ( void * V_37 , struct V_11 * V_1 )
{
struct V_5 * V_6 = (struct V_5 * ) V_37 ;
if ( V_6 -> V_38 >= V_21 )
V_1 -> V_29 = V_1 -> V_23 + V_21 ;
}
static void F_8 ( struct V_11 * V_1 )
{
V_1 -> V_29 = V_1 -> V_23 + V_21 ;
}
static void F_9 ( void * V_37 , struct V_11 * V_1 )
{
if ( F_10 ( V_1 -> V_29 ) )
V_1 -> V_29 = 0 ;
}
static int F_11 ( int V_39 )
{
int V_36 = 0 ;
if ( F_10 ( V_39 >= V_21 ) )
V_36 = V_40 ;
return V_36 ;
}
