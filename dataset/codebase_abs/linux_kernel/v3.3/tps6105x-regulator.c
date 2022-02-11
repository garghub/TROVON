static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 ;
V_4 = F_3 ( V_3 , V_5 ,
V_6 ,
V_7 << V_8 ) ;
if ( V_4 )
return V_4 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 ;
V_4 = F_3 ( V_3 , V_5 ,
V_6 ,
V_9 << V_8 ) ;
if ( V_4 )
return V_4 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_10 ;
int V_4 ;
V_4 = F_6 ( V_3 , V_5 , & V_10 ) ;
if ( V_4 )
return V_4 ;
V_10 &= V_6 ;
V_10 >>= V_8 ;
if ( V_10 == V_7 )
return 1 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_10 ;
int V_4 ;
V_4 = F_6 ( V_3 , V_5 , & V_10 ) ;
if ( V_4 )
return V_4 ;
V_10 &= V_11 ;
V_10 >>= V_12 ;
return ( int ) V_10 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned V_13 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 ;
V_4 = F_3 ( V_3 , V_5 ,
V_11 ,
V_13 << V_12 ) ;
if ( V_4 )
return V_4 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned V_13 )
{
if ( V_13 >= F_10 ( V_14 ) )
return - V_15 ;
return V_14 [ V_13 ] ;
}
static int T_2 F_11 ( struct V_16 * V_17 )
{
struct V_3 * V_3 = F_12 ( & V_17 -> V_18 ) ;
struct V_19 * V_20 = V_3 -> V_20 ;
int V_4 ;
if ( V_20 -> V_21 != V_22 ) {
F_13 ( & V_17 -> V_18 ,
L_1 ) ;
return 0 ;
}
V_3 -> V_23 = F_14 ( & V_24 ,
& V_3 -> V_25 -> V_18 ,
V_20 -> V_26 , V_3 ,
NULL ) ;
if ( F_15 ( V_3 -> V_23 ) ) {
V_4 = F_16 ( V_3 -> V_23 ) ;
F_17 ( & V_3 -> V_25 -> V_18 ,
L_2 ) ;
return V_4 ;
}
F_18 ( V_17 , V_3 ) ;
return 0 ;
}
static int T_3 F_19 ( struct V_16 * V_17 )
{
struct V_3 * V_3 = F_12 ( & V_17 -> V_18 ) ;
F_20 ( V_3 -> V_23 ) ;
return 0 ;
}
static T_4 int F_21 ( void )
{
return F_22 ( & V_27 ) ;
}
static T_5 void F_23 ( void )
{
F_24 ( & V_27 ) ;
}
