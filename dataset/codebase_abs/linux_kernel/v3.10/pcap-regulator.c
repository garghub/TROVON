static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 )
{
struct V_4 * V_5 = & V_6 [ F_2 ( V_2 ) ] ;
void * V_7 = F_3 ( V_2 ) ;
if ( V_2 -> V_8 -> V_9 == 1 )
return - V_10 ;
return F_4 ( V_7 , V_5 -> V_11 ,
( V_2 -> V_8 -> V_9 - 1 ) << V_5 -> V_12 ,
V_3 << V_5 -> V_12 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_6 [ F_2 ( V_2 ) ] ;
void * V_7 = F_3 ( V_2 ) ;
T_1 V_13 ;
if ( V_2 -> V_8 -> V_9 == 1 )
return 0 ;
F_6 ( V_7 , V_5 -> V_11 , & V_13 ) ;
V_13 = ( ( V_13 >> V_5 -> V_12 ) & ( V_2 -> V_8 -> V_9 - 1 ) ) ;
return V_13 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_6 [ F_2 ( V_2 ) ] ;
void * V_7 = F_3 ( V_2 ) ;
if ( V_5 -> V_14 == V_15 )
return - V_10 ;
return F_4 ( V_7 , V_5 -> V_11 , 1 << V_5 -> V_14 , 1 << V_5 -> V_14 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_6 [ F_2 ( V_2 ) ] ;
void * V_7 = F_3 ( V_2 ) ;
if ( V_5 -> V_14 == V_15 )
return - V_10 ;
return F_4 ( V_7 , V_5 -> V_11 , 1 << V_5 -> V_14 , 0 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_6 [ F_2 ( V_2 ) ] ;
void * V_7 = F_3 ( V_2 ) ;
T_1 V_13 ;
if ( V_5 -> V_14 == V_15 )
return - V_10 ;
F_6 ( V_7 , V_5 -> V_11 , & V_13 ) ;
return ( V_13 >> V_5 -> V_14 ) & 1 ;
}
static int F_10 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
void * V_7 = F_11 ( V_17 -> V_18 . V_19 ) ;
struct V_20 V_21 = { } ;
V_21 . V_18 = & V_17 -> V_18 ;
V_21 . V_22 = V_17 -> V_18 . V_23 ;
V_21 . V_24 = V_7 ;
V_2 = F_12 ( & V_25 [ V_17 -> V_26 ] , & V_21 ) ;
if ( F_13 ( V_2 ) )
return F_14 ( V_2 ) ;
F_15 ( V_17 , V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_17 ( V_17 ) ;
F_18 ( V_2 ) ;
F_15 ( V_17 , NULL ) ;
return 0 ;
}
static int T_2 F_19 ( void )
{
return F_20 ( & V_27 ) ;
}
static void T_3 F_21 ( void )
{
F_22 ( & V_27 ) ;
}
