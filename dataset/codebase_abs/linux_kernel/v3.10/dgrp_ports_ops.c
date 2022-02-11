static void * F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
if ( * V_3 == 0 )
F_2 ( V_2 , L_1 ) ;
return V_3 ;
}
static void * F_3 ( struct V_1 * V_2 , void * V_4 , T_1 * V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( * V_3 >= V_6 -> V_8 )
return NULL ;
* V_3 += 1 ;
return V_3 ;
}
static void F_4 ( struct V_1 * V_2 , void * V_4 )
{
}
static int F_5 ( struct V_1 * V_2 , void * V_4 )
{
T_1 * V_3 = V_4 ;
struct V_5 * V_6 ;
struct V_9 * V_10 ;
struct V_11 * V_12 , * V_13 ;
unsigned int V_14 ;
V_6 = V_2 -> V_7 ;
if ( ! V_6 )
return 0 ;
if ( * V_3 >= V_6 -> V_8 )
return 0 ;
V_10 = & V_6 -> V_15 [ * V_3 ] ;
V_12 = & V_10 -> V_16 ;
V_13 = & V_10 -> V_17 ;
V_14 = V_12 -> V_18 +
V_13 -> V_18 +
V_10 -> V_19 [ 0 ] +
V_10 -> V_19 [ 1 ] +
V_10 -> V_19 [ 2 ] ;
F_6 ( V_2 , L_2 ,
( int ) * V_3 ,
V_12 -> V_18 ,
V_13 -> V_18 ,
V_10 -> V_19 [ 0 ] +
V_10 -> V_19 [ 1 ] +
V_10 -> V_19 [ 2 ] ,
( V_14 ? V_10 -> V_20 : 0 ) ,
V_10 -> V_21 ,
V_10 -> V_22 ,
V_10 -> V_23 ,
( V_10 -> V_24 ? ( 1843200 / V_10 -> V_24 ) : 0 ) ,
V_10 -> V_25 . V_26 ) ;
return 0 ;
}
static int F_7 ( struct V_27 * V_27 , struct V_28 * V_28 )
{
struct V_1 * V_2 ;
int V_29 ;
V_29 = F_8 ( V_28 , & V_30 ) ;
if ( ! V_29 ) {
V_2 = V_28 -> V_31 ;
V_2 -> V_7 = F_9 ( V_27 ) ;
}
return V_29 ;
}
