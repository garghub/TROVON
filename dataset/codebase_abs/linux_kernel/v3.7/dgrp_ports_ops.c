void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_2 -> V_6 = & V_7 ;
V_2 -> V_8 = & V_9 ;
V_4 -> V_10 = V_2 ;
}
static void * F_2 ( struct V_11 * V_12 , T_1 * V_13 )
{
if ( * V_13 == 0 )
F_3 ( V_12 , L_1 ) ;
return V_13 ;
}
static void * F_4 ( struct V_11 * V_12 , void * V_14 , T_1 * V_13 )
{
struct V_3 * V_15 = V_12 -> V_16 ;
if ( * V_13 >= V_15 -> V_17 )
return NULL ;
* V_13 += 1 ;
return V_13 ;
}
static void F_5 ( struct V_11 * V_12 , void * V_14 )
{
}
static int F_6 ( struct V_11 * V_12 , void * V_14 )
{
T_1 * V_13 = V_14 ;
struct V_3 * V_15 ;
struct V_18 * V_19 ;
struct V_20 * V_21 , * V_22 ;
unsigned int V_23 ;
V_15 = V_12 -> V_16 ;
if ( ! V_15 )
return 0 ;
if ( * V_13 >= V_15 -> V_17 )
return 0 ;
V_19 = & V_15 -> V_24 [ * V_13 ] ;
V_21 = & V_19 -> V_25 ;
V_22 = & V_19 -> V_26 ;
V_23 = V_21 -> V_27 +
V_22 -> V_27 +
V_19 -> V_28 [ 0 ] +
V_19 -> V_28 [ 1 ] +
V_19 -> V_28 [ 2 ] ;
F_7 ( V_12 , L_2 ,
( int ) * V_13 ,
V_21 -> V_27 ,
V_22 -> V_27 ,
V_19 -> V_28 [ 0 ] +
V_19 -> V_28 [ 1 ] +
V_19 -> V_28 [ 2 ] ,
( V_23 ? V_19 -> V_29 : 0 ) ,
V_19 -> V_30 ,
V_19 -> V_31 ,
V_19 -> V_32 ,
( V_19 -> V_33 ? ( 1843200 / V_19 -> V_33 ) : 0 ) ,
V_19 -> V_34 . V_35 ) ;
return 0 ;
}
static int F_8 ( struct V_36 * V_36 , struct V_37 * V_37 )
{
struct V_11 * V_12 ;
int V_38 ;
V_38 = F_9 ( V_37 , & V_39 ) ;
if ( ! V_38 ) {
V_12 = V_37 -> V_40 ;
V_12 -> V_16 = F_10 ( V_36 ) -> V_5 ;
}
return V_38 ;
}
