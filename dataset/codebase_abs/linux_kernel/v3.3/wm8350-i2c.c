static int F_1 ( struct V_1 * V_1 , char V_2 ,
int V_3 , void * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_1 -> V_6 , & V_2 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_3 ( V_1 -> V_6 , V_4 , V_3 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 != V_3 )
return - V_7 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_1 , char V_2 ,
int V_3 , void * V_8 )
{
T_1 V_9 [ ( V_10 << 1 ) + 1 ] ;
int V_5 ;
if ( V_3 > ( ( V_10 << 1 ) + 1 ) )
return - V_11 ;
V_9 [ 0 ] = V_2 ;
memcpy ( & V_9 [ 1 ] , V_8 , V_3 ) ;
V_5 = F_2 ( V_1 -> V_6 , V_9 , V_3 + 1 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 != V_3 + 1 )
return - V_7 ;
return 0 ;
}
static int F_5 ( struct V_6 * V_12 ,
const struct V_13 * V_14 )
{
struct V_1 * V_1 ;
int V_5 = 0 ;
V_1 = F_6 ( & V_12 -> V_15 , sizeof( struct V_1 ) , V_16 ) ;
if ( V_1 == NULL )
return - V_17 ;
F_7 ( V_12 , V_1 ) ;
V_1 -> V_15 = & V_12 -> V_15 ;
V_1 -> V_6 = V_12 ;
V_1 -> V_18 = F_1 ;
V_1 -> V_19 = F_4 ;
V_5 = F_8 ( V_1 , V_12 -> V_20 , V_12 -> V_15 . V_21 ) ;
if ( V_5 < 0 )
goto V_22;
return V_5 ;
V_22:
return V_5 ;
}
static int F_9 ( struct V_6 * V_12 )
{
struct V_1 * V_1 = F_10 ( V_12 ) ;
F_11 ( V_1 ) ;
return 0 ;
}
static int T_2 F_12 ( void )
{
return F_13 ( & V_23 ) ;
}
static void T_3 F_14 ( void )
{
F_15 ( & V_23 ) ;
}
