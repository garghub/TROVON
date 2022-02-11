static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 ;
V_4 = F_3 ( V_3 -> V_5 , V_6 ,
V_7 ,
V_8 << V_9 ) ;
if ( V_4 )
return V_4 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 ;
V_4 = F_3 ( V_3 -> V_5 , V_6 ,
V_7 ,
V_10 << V_9 ) ;
if ( V_4 )
return V_4 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
unsigned int V_11 ;
int V_4 ;
V_4 = F_6 ( V_3 -> V_5 , V_6 , & V_11 ) ;
if ( V_4 )
return V_4 ;
V_11 &= V_7 ;
V_11 >>= V_9 ;
if ( V_11 == V_8 )
return 1 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
unsigned int V_11 ;
int V_4 ;
V_4 = F_6 ( V_3 -> V_5 , V_6 , & V_11 ) ;
if ( V_4 )
return V_4 ;
V_11 &= V_12 ;
V_11 >>= V_13 ;
return ( int ) V_11 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned V_14 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 ;
V_4 = F_3 ( V_3 -> V_5 , V_6 ,
V_12 ,
V_14 << V_13 ) ;
if ( V_4 )
return V_4 ;
return 0 ;
}
static int F_9 ( struct V_15 * V_16 )
{
struct V_3 * V_3 = F_10 ( & V_16 -> V_17 ) ;
struct V_18 * V_19 = V_3 -> V_19 ;
struct V_20 V_21 = { } ;
int V_4 ;
if ( V_19 -> V_22 != V_23 ) {
F_11 ( & V_16 -> V_17 ,
L_1 ) ;
return 0 ;
}
V_21 . V_17 = & V_3 -> V_24 -> V_17 ;
V_21 . V_25 = V_19 -> V_26 ;
V_21 . V_27 = V_3 ;
V_3 -> V_28 = F_12 ( & V_16 -> V_17 ,
& V_29 ,
& V_21 ) ;
if ( F_13 ( V_3 -> V_28 ) ) {
V_4 = F_14 ( V_3 -> V_28 ) ;
F_15 ( & V_3 -> V_24 -> V_17 ,
L_2 ) ;
return V_4 ;
}
F_16 ( V_16 , V_3 ) ;
return 0 ;
}
static T_1 int F_17 ( void )
{
return F_18 ( & V_30 ) ;
}
static T_2 void F_19 ( void )
{
F_20 ( & V_30 ) ;
}
