static int F_1 ( struct V_1 * V_2 , const void * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
V_7 = F_3 ( V_6 , V_3 , V_4 ) ;
if ( V_7 == V_4 )
return 0 ;
else if ( V_7 < 0 )
return V_7 ;
else
return - V_8 ;
}
static int F_4 ( struct V_1 * V_2 ,
const void * V_9 , T_1 V_10 ,
const void * V_11 , T_1 V_12 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_13 V_14 [ 2 ] ;
int V_7 ;
if ( ! F_5 ( V_6 -> V_15 , V_16 ) )
return - V_17 ;
V_14 [ 0 ] . V_18 = V_6 -> V_18 ;
V_14 [ 0 ] . V_19 = 0 ;
V_14 [ 0 ] . V_20 = V_10 ;
V_14 [ 0 ] . V_21 = ( void * ) V_9 ;
V_14 [ 1 ] . V_18 = V_6 -> V_18 ;
V_14 [ 1 ] . V_19 = V_22 ;
V_14 [ 1 ] . V_20 = V_12 ;
V_14 [ 1 ] . V_21 = ( void * ) V_11 ;
V_7 = F_6 ( V_6 -> V_15 , V_14 , 2 ) ;
if ( V_7 == 2 )
return 0 ;
if ( V_7 < 0 )
return V_7 ;
else
return - V_8 ;
}
static int F_7 ( struct V_1 * V_2 ,
const void * V_9 , T_1 V_10 ,
void * V_11 , T_1 V_12 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_13 V_14 [ 2 ] ;
int V_7 ;
V_14 [ 0 ] . V_18 = V_6 -> V_18 ;
V_14 [ 0 ] . V_19 = 0 ;
V_14 [ 0 ] . V_20 = V_10 ;
V_14 [ 0 ] . V_21 = ( void * ) V_9 ;
V_14 [ 1 ] . V_18 = V_6 -> V_18 ;
V_14 [ 1 ] . V_19 = V_23 ;
V_14 [ 1 ] . V_20 = V_12 ;
V_14 [ 1 ] . V_21 = V_11 ;
V_7 = F_6 ( V_6 -> V_15 , V_14 , 2 ) ;
if ( V_7 == 2 )
return 0 ;
else if ( V_7 < 0 )
return V_7 ;
else
return - V_8 ;
}
struct V_24 * F_8 ( struct V_5 * V_6 ,
const struct V_25 * V_26 )
{
return F_9 ( & V_6 -> V_2 , & V_27 , V_26 ) ;
}
struct V_24 * F_10 ( struct V_5 * V_6 ,
const struct V_25 * V_26 )
{
return F_11 ( & V_6 -> V_2 , & V_27 , V_26 ) ;
}
