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
static int F_9 ( struct V_14 * V_15 )
{
struct V_3 * V_3 = F_10 ( & V_15 -> V_16 ) ;
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_19 V_20 = { } ;
int V_4 ;
if ( V_18 -> V_21 != V_22 ) {
F_11 ( & V_15 -> V_16 ,
L_1 ) ;
return 0 ;
}
V_20 . V_16 = & V_3 -> V_23 -> V_16 ;
V_20 . V_24 = V_18 -> V_25 ;
V_20 . V_26 = V_3 ;
V_3 -> V_27 = F_12 ( & V_28 ,
& V_20 ) ;
if ( F_13 ( V_3 -> V_27 ) ) {
V_4 = F_14 ( V_3 -> V_27 ) ;
F_15 ( & V_3 -> V_23 -> V_16 ,
L_2 ) ;
return V_4 ;
}
F_16 ( V_15 , V_3 ) ;
return 0 ;
}
static int F_17 ( struct V_14 * V_15 )
{
struct V_3 * V_3 = F_10 ( & V_15 -> V_16 ) ;
F_18 ( V_3 -> V_27 ) ;
return 0 ;
}
static T_2 int F_19 ( void )
{
return F_20 ( & V_29 ) ;
}
static T_3 void F_21 ( void )
{
F_22 ( & V_29 ) ;
}
