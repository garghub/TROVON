static int F_1 ( struct V_1 * V_1 , unsigned short V_2 ,
int V_3 , void * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
int V_8 ;
T_1 V_9 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_6 , ( unsigned char * ) & V_9 , 2 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 != 2 )
return - V_10 ;
V_8 = F_4 ( V_6 , V_4 , V_3 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 != V_3 )
return - V_10 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 , unsigned short V_2 ,
int V_3 , void * V_11 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_12 V_13 [ 2 ] ;
int V_8 ;
V_2 = F_2 ( V_2 ) ;
V_13 [ 0 ] . V_14 = V_6 -> V_14 ;
V_13 [ 0 ] . V_15 = 0 ;
V_13 [ 0 ] . V_16 = 2 ;
V_13 [ 0 ] . V_17 = ( char * ) & V_2 ;
V_13 [ 1 ] . V_14 = V_6 -> V_14 ;
V_13 [ 1 ] . V_15 = V_18 ;
V_13 [ 1 ] . V_16 = V_3 ;
V_13 [ 1 ] . V_17 = ( char * ) V_11 ;
V_8 = F_6 ( V_6 -> V_19 , V_13 , 2 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 != 2 )
return - V_10 ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 ,
const struct V_20 * V_21 )
{
struct V_1 * V_1 ;
V_1 = F_8 ( sizeof( struct V_1 ) , V_22 ) ;
if ( V_1 == NULL )
return - V_23 ;
F_9 ( V_6 , V_1 ) ;
V_1 -> V_24 = & V_6 -> V_24 ;
V_1 -> V_7 = V_6 ;
V_1 -> V_25 = F_1 ;
V_1 -> V_26 = F_5 ;
return F_10 ( V_1 , V_21 -> V_27 , V_6 -> V_28 ) ;
}
static int F_11 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_12 ( V_6 ) ;
F_13 ( V_1 ) ;
return 0 ;
}
static int F_14 ( struct V_29 * V_24 )
{
struct V_1 * V_1 = F_15 ( V_24 ) ;
return F_16 ( V_1 ) ;
}
static int T_2 F_17 ( void )
{
int V_8 ;
V_8 = F_18 ( & V_30 ) ;
if ( V_8 != 0 )
F_19 ( L_1 , V_8 ) ;
return V_8 ;
}
static void T_3 F_20 ( void )
{
F_21 ( & V_30 ) ;
}
