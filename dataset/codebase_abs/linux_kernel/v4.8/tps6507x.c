static int F_1 ( struct V_1 * V_2 , char V_3 ,
int V_4 , void * V_5 )
{
struct V_6 * V_7 = V_2 -> V_6 ;
struct V_8 V_9 [ 2 ] ;
int V_10 ;
V_9 [ 0 ] . V_11 = V_7 -> V_11 ;
V_9 [ 0 ] . V_12 = 0 ;
V_9 [ 0 ] . V_13 = 1 ;
V_9 [ 0 ] . V_14 = & V_3 ;
V_9 [ 1 ] . V_11 = V_7 -> V_11 ;
V_9 [ 1 ] . V_12 = V_15 ;
V_9 [ 1 ] . V_13 = V_4 ;
V_9 [ 1 ] . V_14 = V_5 ;
V_10 = F_2 ( V_7 -> V_16 , V_9 , 2 ) ;
if ( V_10 == 2 )
V_10 = 0 ;
else if ( V_10 >= 0 )
V_10 = - V_17 ;
return V_10 ;
}
static int F_3 ( struct V_1 * V_2 , char V_3 ,
int V_4 , void * V_18 )
{
struct V_6 * V_7 = V_2 -> V_6 ;
T_1 V_19 [ V_20 + 1 ] ;
int V_10 ;
if ( V_4 > V_20 )
return - V_21 ;
V_19 [ 0 ] = V_3 ;
memcpy ( & V_19 [ 1 ] , V_18 , V_4 ) ;
V_10 = F_4 ( V_7 , V_19 , V_4 + 1 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_10 != V_4 + 1 )
return - V_17 ;
return 0 ;
}
static int F_5 ( struct V_6 * V_7 ,
const struct V_22 * V_23 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( & V_7 -> V_24 , sizeof( struct V_1 ) ,
V_25 ) ;
if ( V_2 == NULL )
return - V_26 ;
F_7 ( V_7 , V_2 ) ;
V_2 -> V_24 = & V_7 -> V_24 ;
V_2 -> V_6 = V_7 ;
V_2 -> V_27 = F_1 ;
V_2 -> V_28 = F_3 ;
return F_8 ( V_2 -> V_24 , - 1 , V_29 ,
F_9 ( V_29 ) , NULL , 0 , NULL ) ;
}
static int T_2 F_10 ( void )
{
return F_11 ( & V_30 ) ;
}
static void T_3 F_12 ( void )
{
F_13 ( & V_30 ) ;
}
