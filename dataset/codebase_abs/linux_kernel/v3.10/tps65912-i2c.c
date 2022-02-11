static int F_1 ( struct V_1 * V_1 , T_1 V_2 ,
int V_3 , void * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 V_9 [ 2 ] ;
int V_10 ;
V_9 [ 0 ] . V_11 = V_6 -> V_11 ;
V_9 [ 0 ] . V_12 = 0 ;
V_9 [ 0 ] . V_13 = 1 ;
V_9 [ 0 ] . V_14 = & V_2 ;
V_9 [ 1 ] . V_11 = V_6 -> V_11 ;
V_9 [ 1 ] . V_12 = V_15 ;
V_9 [ 1 ] . V_13 = V_3 ;
V_9 [ 1 ] . V_14 = V_4 ;
V_10 = F_2 ( V_6 -> V_16 , V_9 , 2 ) ;
if ( V_10 == 2 )
V_10 = 0 ;
else if ( V_10 >= 0 )
V_10 = - V_17 ;
return V_10 ;
}
static int F_3 ( struct V_1 * V_1 , T_1 V_2 ,
int V_3 , void * V_18 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
T_1 V_19 [ V_20 + 1 ] ;
int V_10 ;
if ( V_3 > V_20 )
return - V_21 ;
V_19 [ 0 ] = V_2 ;
memcpy ( & V_19 [ 1 ] , V_18 , V_3 ) ;
V_10 = F_4 ( V_6 , V_19 , V_3 + 1 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_10 != V_3 + 1 )
return - V_17 ;
return 0 ;
}
static int F_5 ( struct V_5 * V_6 ,
const struct V_22 * V_23 )
{
struct V_1 * V_1 ;
V_1 = F_6 ( sizeof( struct V_1 ) , V_24 ) ;
if ( V_1 == NULL )
return - V_25 ;
F_7 ( V_6 , V_1 ) ;
V_1 -> V_26 = & V_6 -> V_26 ;
V_1 -> V_7 = V_6 ;
V_1 -> V_27 = F_1 ;
V_1 -> V_28 = F_3 ;
return F_8 ( V_1 ) ;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_10 ( V_6 ) ;
F_11 ( V_1 ) ;
return 0 ;
}
static int T_2 F_12 ( void )
{
int V_10 ;
V_10 = F_13 ( & V_29 ) ;
if ( V_10 != 0 )
F_14 ( L_1 , V_10 ) ;
return V_10 ;
}
static void T_3 F_15 ( void )
{
F_16 ( & V_29 ) ;
}
