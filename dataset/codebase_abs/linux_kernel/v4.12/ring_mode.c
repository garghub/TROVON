static int F_1 ( void * V_1 , struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_1 ;
unsigned int V_7 = F_2 ( V_3 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_11 = V_6 -> V_12 ;
unsigned int V_13 , V_14 , V_15 ;
struct V_16 * V_17 ;
if ( V_9 -> V_18 )
V_17 = (struct V_16 * ) ( V_6 -> V_19 + V_11 ) ;
else
V_17 = V_6 -> V_20 + V_11 ;
if ( V_9 -> V_21 -> V_22 )
V_13 = V_23 ;
else
V_13 = V_24 ;
V_14 = V_7 - V_13 ;
if ( V_7 > V_23 ) {
V_15 = F_3 ( V_9 -> V_25 , V_3 -> V_26 , V_13 ,
V_27 ) ;
V_17 -> V_15 = F_4 ( V_15 ) ;
if ( F_5 ( V_9 -> V_25 , V_15 ) )
return - 1 ;
V_6 -> V_28 [ V_11 ] . V_29 = V_15 ;
V_6 -> V_28 [ V_11 ] . V_14 = V_13 ;
V_6 -> V_28 [ V_11 ] . V_30 = true ;
V_17 -> V_31 = F_4 ( V_15 + V_32 ) ;
V_9 -> V_33 -> V_17 -> V_34 ( V_17 , 1 , V_13 , V_4 ,
V_35 , 0 ,
false , V_3 -> V_14 ) ;
V_6 -> V_36 [ V_11 ] = NULL ;
V_11 = F_6 ( V_11 , V_37 ) ;
if ( V_9 -> V_18 )
V_17 = (struct V_16 * ) ( V_6 -> V_19 + V_11 ) ;
else
V_17 = V_6 -> V_20 + V_11 ;
V_15 = F_3 ( V_9 -> V_25 , V_3 -> V_26 + V_13 , V_14 ,
V_27 ) ;
V_17 -> V_15 = F_4 ( V_15 ) ;
if ( F_5 ( V_9 -> V_25 , V_15 ) )
return - 1 ;
V_6 -> V_28 [ V_11 ] . V_29 = V_15 ;
V_6 -> V_28 [ V_11 ] . V_14 = V_14 ;
V_6 -> V_28 [ V_11 ] . V_30 = true ;
V_17 -> V_31 = F_4 ( V_15 + V_32 ) ;
V_9 -> V_33 -> V_17 -> V_34 ( V_17 , 0 , V_14 , V_4 ,
V_35 , 1 ,
true , V_3 -> V_14 ) ;
} else {
V_15 = F_3 ( V_9 -> V_25 , V_3 -> V_26 ,
V_7 , V_27 ) ;
V_17 -> V_15 = F_4 ( V_15 ) ;
if ( F_5 ( V_9 -> V_25 , V_15 ) )
return - 1 ;
V_6 -> V_28 [ V_11 ] . V_29 = V_15 ;
V_6 -> V_28 [ V_11 ] . V_14 = V_7 ;
V_6 -> V_28 [ V_11 ] . V_30 = true ;
V_17 -> V_31 = F_4 ( V_15 + V_32 ) ;
V_9 -> V_33 -> V_17 -> V_34 ( V_17 , 1 , V_7 , V_4 ,
V_35 , 0 ,
true , V_3 -> V_14 ) ;
}
V_6 -> V_12 = V_11 ;
return V_11 ;
}
static unsigned int F_7 ( int V_14 , int V_22 )
{
unsigned int V_38 = 0 ;
if ( V_14 >= V_32 )
V_38 = 1 ;
return V_38 ;
}
static void F_8 ( void * V_39 , struct V_16 * V_1 )
{
struct V_8 * V_9 = (struct V_8 * ) V_39 ;
if ( V_9 -> V_40 >= V_23 )
V_1 -> V_31 = F_4 ( F_9 ( V_1 -> V_15 ) + V_23 ) ;
}
static void F_10 ( struct V_16 * V_1 )
{
V_1 -> V_31 = F_4 ( F_9 ( V_1 -> V_15 ) + V_23 ) ;
}
static void F_11 ( void * V_39 , struct V_16 * V_1 )
{
struct V_5 * V_6 = (struct V_5 * ) V_39 ;
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_11 = V_6 -> V_41 ;
if ( F_12 ( V_6 -> V_28 [ V_11 ] . V_30 ||
( V_6 -> V_28 [ V_11 ] . V_42 &&
! V_9 -> V_18 && V_9 -> V_43 ) ) )
V_1 -> V_31 = 0 ;
}
static int F_13 ( int V_44 )
{
int V_38 = 0 ;
if ( F_12 ( V_44 >= V_23 ) )
V_38 = V_45 ;
return V_38 ;
}
