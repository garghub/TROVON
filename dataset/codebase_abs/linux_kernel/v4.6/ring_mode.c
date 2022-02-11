static int F_1 ( void * V_1 , struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_1 ;
unsigned int V_7 = V_6 -> V_8 ;
struct V_9 * V_10 ;
unsigned int V_11 = F_2 ( V_3 ) ;
unsigned int V_12 , V_13 ;
if ( V_6 -> V_14 )
V_10 = (struct V_9 * ) ( V_6 -> V_15 + V_7 ) ;
else
V_10 = V_6 -> V_16 + V_7 ;
if ( V_6 -> V_17 -> V_18 )
V_12 = V_19 ;
else
V_12 = V_20 ;
V_13 = V_11 - V_12 ;
if ( V_11 > V_19 ) {
V_10 -> V_21 = F_3 ( V_6 -> V_22 , V_3 -> V_23 ,
V_12 , V_24 ) ;
if ( F_4 ( V_6 -> V_22 , V_10 -> V_21 ) )
return - 1 ;
V_6 -> V_25 [ V_7 ] . V_26 = V_10 -> V_21 ;
V_6 -> V_25 [ V_7 ] . V_13 = V_12 ;
V_6 -> V_25 [ V_7 ] . V_27 = true ;
V_10 -> V_28 = V_10 -> V_21 + V_29 ;
V_6 -> V_30 -> V_10 -> V_31 ( V_10 , 1 , V_12 , V_4 ,
V_32 , 0 , false ) ;
V_6 -> V_33 [ V_7 ] = NULL ;
V_7 = F_5 ( V_7 , V_34 ) ;
if ( V_6 -> V_14 )
V_10 = (struct V_9 * ) ( V_6 -> V_15 + V_7 ) ;
else
V_10 = V_6 -> V_16 + V_7 ;
V_10 -> V_21 = F_3 ( V_6 -> V_22 , V_3 -> V_23 + V_12 ,
V_13 , V_24 ) ;
if ( F_4 ( V_6 -> V_22 , V_10 -> V_21 ) )
return - 1 ;
V_6 -> V_25 [ V_7 ] . V_26 = V_10 -> V_21 ;
V_6 -> V_25 [ V_7 ] . V_13 = V_13 ;
V_6 -> V_25 [ V_7 ] . V_27 = true ;
V_10 -> V_28 = V_10 -> V_21 + V_29 ;
V_6 -> V_30 -> V_10 -> V_31 ( V_10 , 0 , V_13 , V_4 ,
V_32 , 1 , true ) ;
} else {
V_10 -> V_21 = F_3 ( V_6 -> V_22 , V_3 -> V_23 ,
V_11 , V_24 ) ;
if ( F_4 ( V_6 -> V_22 , V_10 -> V_21 ) )
return - 1 ;
V_6 -> V_25 [ V_7 ] . V_26 = V_10 -> V_21 ;
V_6 -> V_25 [ V_7 ] . V_13 = V_11 ;
V_6 -> V_25 [ V_7 ] . V_27 = true ;
V_10 -> V_28 = V_10 -> V_21 + V_29 ;
V_6 -> V_30 -> V_10 -> V_31 ( V_10 , 1 , V_11 , V_4 ,
V_32 , 0 , true ) ;
}
V_6 -> V_8 = V_7 ;
return V_7 ;
}
static unsigned int F_6 ( int V_13 , int V_18 )
{
unsigned int V_35 = 0 ;
if ( V_13 >= V_29 )
V_35 = 1 ;
return V_35 ;
}
static void F_7 ( void * V_36 , struct V_9 * V_1 )
{
struct V_5 * V_6 = (struct V_5 * ) V_36 ;
if ( V_6 -> V_37 >= V_19 )
V_1 -> V_28 = V_1 -> V_21 + V_19 ;
}
static void F_8 ( struct V_9 * V_1 )
{
V_1 -> V_28 = V_1 -> V_21 + V_19 ;
}
static void F_9 ( void * V_36 , struct V_9 * V_1 )
{
struct V_5 * V_6 = (struct V_5 * ) V_36 ;
unsigned int V_7 = V_6 -> V_38 ;
if ( F_10 ( V_6 -> V_25 [ V_7 ] . V_27 ||
( V_6 -> V_25 [ V_7 ] . V_39 &&
! V_6 -> V_14 && V_6 -> V_40 ) ) )
V_1 -> V_28 = 0 ;
}
static int F_11 ( int V_41 )
{
int V_35 = 0 ;
if ( F_10 ( V_41 >= V_19 ) )
V_35 = V_42 ;
return V_35 ;
}
