static int F_1 ( void * V_1 , const void * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
int V_8 ;
V_8 = F_3 ( V_7 , V_2 , V_3 ) ;
if ( V_8 == V_3 )
return 0 ;
else if ( V_8 < 0 )
return V_8 ;
else
return - V_9 ;
}
static int F_4 ( void * V_1 ,
const void * V_10 , T_1 V_11 ,
const void * V_12 , T_1 V_13 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_14 V_15 [ 2 ] ;
int V_8 ;
if ( ! F_5 ( V_7 -> V_16 , V_17 ) )
return - V_18 ;
V_15 [ 0 ] . V_19 = V_7 -> V_19 ;
V_15 [ 0 ] . V_20 = 0 ;
V_15 [ 0 ] . V_21 = V_11 ;
V_15 [ 0 ] . V_22 = ( void * ) V_10 ;
V_15 [ 1 ] . V_19 = V_7 -> V_19 ;
V_15 [ 1 ] . V_20 = V_23 ;
V_15 [ 1 ] . V_21 = V_13 ;
V_15 [ 1 ] . V_22 = ( void * ) V_12 ;
V_8 = F_6 ( V_7 -> V_16 , V_15 , 2 ) ;
if ( V_8 == 2 )
return 0 ;
if ( V_8 < 0 )
return V_8 ;
else
return - V_9 ;
}
static int F_7 ( void * V_1 ,
const void * V_10 , T_1 V_11 ,
void * V_12 , T_1 V_13 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_14 V_15 [ 2 ] ;
int V_8 ;
V_15 [ 0 ] . V_19 = V_7 -> V_19 ;
V_15 [ 0 ] . V_20 = 0 ;
V_15 [ 0 ] . V_21 = V_11 ;
V_15 [ 0 ] . V_22 = ( void * ) V_10 ;
V_15 [ 1 ] . V_19 = V_7 -> V_19 ;
V_15 [ 1 ] . V_20 = V_24 ;
V_15 [ 1 ] . V_21 = V_13 ;
V_15 [ 1 ] . V_22 = V_12 ;
V_8 = F_6 ( V_7 -> V_16 , V_15 , 2 ) ;
if ( V_8 == 2 )
return 0 ;
else if ( V_8 < 0 )
return V_8 ;
else
return - V_9 ;
}
struct V_25 * F_8 ( struct V_6 * V_7 ,
const struct V_26 * V_27 )
{
return F_9 ( & V_7 -> V_5 , & V_28 , & V_7 -> V_5 , V_27 ) ;
}
struct V_25 * F_10 ( struct V_6 * V_7 ,
const struct V_26 * V_27 )
{
return F_11 ( & V_7 -> V_5 , & V_28 , & V_7 -> V_5 , V_27 ) ;
}
