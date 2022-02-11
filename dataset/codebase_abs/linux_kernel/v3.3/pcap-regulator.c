static int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 ,
unsigned * V_5 )
{
struct V_6 * V_7 = & V_8 [ F_2 ( V_2 ) ] ;
void * V_9 = F_3 ( V_2 ) ;
int V_10 ;
T_1 V_11 ;
if ( V_7 -> V_12 == 1 )
return - V_13 ;
for ( V_11 = 0 ; V_11 < V_7 -> V_12 ; V_11 ++ ) {
if ( V_11 == 0 && F_2 ( V_2 ) == V_14 )
V_11 = 1 ;
else if ( V_11 + 1 == V_7 -> V_12 && F_2 ( V_2 ) == V_14 )
V_11 = 0 ;
V_10 = V_7 -> V_15 [ V_11 ] * 1000 ;
if ( V_3 <= V_10 && V_10 <= V_4 ) {
* V_5 = V_11 ;
return F_4 ( V_9 , V_7 -> V_16 ,
( V_7 -> V_12 - 1 ) << V_7 -> V_17 ,
V_11 << V_7 -> V_17 ) ;
}
if ( V_11 == 0 && F_2 ( V_2 ) == V_14 )
V_11 = V_7 -> V_12 - 1 ;
}
return - V_13 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_8 [ F_2 ( V_2 ) ] ;
void * V_9 = F_3 ( V_2 ) ;
T_2 V_18 ;
int V_19 ;
if ( V_7 -> V_12 == 1 )
return V_7 -> V_15 [ 0 ] * 1000 ;
F_6 ( V_9 , V_7 -> V_16 , & V_18 ) ;
V_18 = ( ( V_18 >> V_7 -> V_17 ) & ( V_7 -> V_12 - 1 ) ) ;
V_19 = V_7 -> V_15 [ V_18 ] ;
return V_19 * 1000 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_8 [ F_2 ( V_2 ) ] ;
void * V_9 = F_3 ( V_2 ) ;
if ( V_7 -> V_20 == V_21 )
return - V_13 ;
return F_4 ( V_9 , V_7 -> V_16 , 1 << V_7 -> V_20 , 1 << V_7 -> V_20 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_8 [ F_2 ( V_2 ) ] ;
void * V_9 = F_3 ( V_2 ) ;
if ( V_7 -> V_20 == V_21 )
return - V_13 ;
return F_4 ( V_9 , V_7 -> V_16 , 1 << V_7 -> V_20 , 0 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_8 [ F_2 ( V_2 ) ] ;
void * V_9 = F_3 ( V_2 ) ;
T_2 V_18 ;
if ( V_7 -> V_20 == V_21 )
return - V_13 ;
F_6 ( V_9 , V_7 -> V_16 , & V_18 ) ;
return ( V_18 >> V_7 -> V_20 ) & 1 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int V_17 )
{
struct V_6 * V_7 = & V_8 [ F_2 ( V_2 ) ] ;
return V_7 -> V_15 [ V_17 ] * 1000 ;
}
static int T_3 F_11 ( struct V_22 * V_23 )
{
struct V_1 * V_2 ;
void * V_9 = F_12 ( V_23 -> V_24 . V_25 ) ;
V_2 = F_13 ( & V_26 [ V_23 -> V_27 ] , & V_23 -> V_24 ,
V_23 -> V_24 . V_28 , V_9 , NULL ) ;
if ( F_14 ( V_2 ) )
return F_15 ( V_2 ) ;
F_16 ( V_23 , V_2 ) ;
return 0 ;
}
static int T_4 F_17 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_18 ( V_23 ) ;
F_19 ( V_2 ) ;
F_16 ( V_23 , NULL ) ;
return 0 ;
}
static int T_5 F_20 ( void )
{
return F_21 ( & V_29 ) ;
}
static void T_6 F_22 ( void )
{
F_23 ( & V_29 ) ;
}
