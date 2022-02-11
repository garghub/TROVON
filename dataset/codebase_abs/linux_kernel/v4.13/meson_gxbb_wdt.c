static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( F_4 ( V_4 -> V_5 + V_6 ) | V_7 ,
V_4 -> V_5 + V_6 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( F_4 ( V_4 -> V_5 + V_6 ) & ~ V_7 ,
V_4 -> V_5 + V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 0 , V_4 -> V_5 + V_8 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_10 = V_9 * 1000 ;
if ( V_10 > V_11 )
V_10 = V_11 ;
V_2 -> V_9 = V_9 ;
F_6 ( V_2 ) ;
F_3 ( V_10 , V_4 -> V_5 + V_12 ) ;
return 0 ;
}
static unsigned int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_13 ;
V_13 = F_4 ( V_4 -> V_5 + V_12 ) ;
return ( ( V_13 >> V_14 ) -
( V_13 & V_11 ) ) / 1000 ;
}
static int T_1 F_9 ( struct V_15 * V_16 )
{
struct V_3 * V_4 = F_10 ( V_16 ) ;
if ( F_11 ( & V_4 -> V_2 ) )
F_1 ( & V_4 -> V_2 ) ;
return 0 ;
}
static int T_1 F_12 ( struct V_15 * V_16 )
{
struct V_3 * V_4 = F_10 ( V_16 ) ;
if ( F_11 ( & V_4 -> V_2 ) )
F_5 ( & V_4 -> V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_17 * V_18 )
{
struct V_3 * V_4 ;
struct V_19 * V_20 ;
int V_21 ;
V_4 = F_14 ( & V_18 -> V_16 , sizeof( * V_4 ) , V_22 ) ;
if ( ! V_4 )
return - V_23 ;
V_20 = F_15 ( V_18 , V_24 , 0 ) ;
V_4 -> V_5 = F_16 ( & V_18 -> V_16 , V_20 ) ;
if ( F_17 ( V_4 -> V_5 ) )
return F_18 ( V_4 -> V_5 ) ;
V_4 -> V_25 = F_19 ( & V_18 -> V_16 , NULL ) ;
if ( F_17 ( V_4 -> V_25 ) )
return F_18 ( V_4 -> V_25 ) ;
V_21 = F_20 ( V_4 -> V_25 ) ;
if ( V_21 )
return V_21 ;
F_21 ( V_18 , V_4 ) ;
V_4 -> V_2 . V_26 = & V_18 -> V_16 ;
V_4 -> V_2 . V_27 = & V_28 ;
V_4 -> V_2 . V_29 = & V_30 ;
V_4 -> V_2 . V_31 = V_11 ;
V_4 -> V_2 . V_32 = 1 ;
V_4 -> V_2 . V_9 = V_33 ;
F_22 ( & V_4 -> V_2 , V_4 ) ;
F_3 ( ( ( F_23 ( V_4 -> V_25 ) / 1000 ) & V_34 ) |
V_35 |
V_36 |
V_37 ,
V_4 -> V_5 + V_6 ) ;
F_7 ( & V_4 -> V_2 , V_4 -> V_2 . V_9 ) ;
V_21 = F_24 ( & V_4 -> V_2 ) ;
if ( V_21 ) {
F_25 ( V_4 -> V_25 ) ;
return V_21 ;
}
return 0 ;
}
static int F_26 ( struct V_17 * V_18 )
{
struct V_3 * V_4 = F_27 ( V_18 ) ;
F_28 ( & V_4 -> V_2 ) ;
F_25 ( V_4 -> V_25 ) ;
return 0 ;
}
static void F_29 ( struct V_17 * V_18 )
{
struct V_3 * V_4 = F_27 ( V_18 ) ;
F_5 ( & V_4 -> V_2 ) ;
}
