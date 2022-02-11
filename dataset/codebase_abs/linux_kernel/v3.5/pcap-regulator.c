static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 )
{
struct V_4 * V_5 = & V_6 [ F_2 ( V_2 ) ] ;
void * V_7 = F_3 ( V_2 ) ;
if ( V_5 -> V_8 == 1 )
return - V_9 ;
return F_4 ( V_7 , V_5 -> V_10 ,
( V_5 -> V_8 - 1 ) << V_5 -> V_11 ,
V_3 << V_5 -> V_11 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_6 [ F_2 ( V_2 ) ] ;
void * V_7 = F_3 ( V_2 ) ;
T_1 V_12 ;
if ( V_5 -> V_8 == 1 )
return 0 ;
F_6 ( V_7 , V_5 -> V_10 , & V_12 ) ;
V_12 = ( ( V_12 >> V_5 -> V_11 ) & ( V_5 -> V_8 - 1 ) ) ;
return V_12 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_6 [ F_2 ( V_2 ) ] ;
void * V_7 = F_3 ( V_2 ) ;
if ( V_5 -> V_13 == V_14 )
return - V_9 ;
return F_4 ( V_7 , V_5 -> V_10 , 1 << V_5 -> V_13 , 1 << V_5 -> V_13 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_6 [ F_2 ( V_2 ) ] ;
void * V_7 = F_3 ( V_2 ) ;
if ( V_5 -> V_13 == V_14 )
return - V_9 ;
return F_4 ( V_7 , V_5 -> V_10 , 1 << V_5 -> V_13 , 0 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_6 [ F_2 ( V_2 ) ] ;
void * V_7 = F_3 ( V_2 ) ;
T_1 V_12 ;
if ( V_5 -> V_13 == V_14 )
return - V_9 ;
F_6 ( V_7 , V_5 -> V_10 , & V_12 ) ;
return ( V_12 >> V_5 -> V_13 ) & 1 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int V_11 )
{
struct V_4 * V_5 = & V_6 [ F_2 ( V_2 ) ] ;
return V_5 -> V_15 [ V_11 ] * 1000 ;
}
static int T_2 F_11 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
void * V_7 = F_12 ( V_17 -> V_18 . V_19 ) ;
struct V_20 V_21 = { } ;
V_21 . V_18 = & V_17 -> V_18 ;
V_21 . V_22 = V_17 -> V_18 . V_23 ;
V_21 . V_24 = V_7 ;
V_2 = F_13 ( & V_25 [ V_17 -> V_26 ] , & V_21 ) ;
if ( F_14 ( V_2 ) )
return F_15 ( V_2 ) ;
F_16 ( V_17 , V_2 ) ;
return 0 ;
}
static int T_3 F_17 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_18 ( V_17 ) ;
F_19 ( V_2 ) ;
F_16 ( V_17 , NULL ) ;
return 0 ;
}
static int T_4 F_20 ( void )
{
return F_21 ( & V_27 ) ;
}
static void T_5 F_22 ( void )
{
F_23 ( & V_27 ) ;
}
