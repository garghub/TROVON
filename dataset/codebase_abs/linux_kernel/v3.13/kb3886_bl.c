static void F_1 ( int V_1 )
{
F_2 ( & V_2 ) ;
V_1 = V_1 & 0xff ;
F_3 ( V_3 , V_4 ) ;
F_4 ( 10000 , 11000 ) ;
F_3 ( V_5 , V_6 ) ;
F_4 ( 10000 , 11000 ) ;
F_3 ( V_1 , V_6 ) ;
F_5 ( & V_2 ) ;
}
static int F_6 ( struct V_7 * V_8 )
{
int V_1 = V_8 -> V_9 . V_10 ;
if ( V_8 -> V_9 . V_11 != V_12 )
V_1 = 0 ;
if ( V_8 -> V_9 . V_13 != V_12 )
V_1 = 0 ;
if ( V_14 & V_15 )
V_1 = 0 ;
V_16 -> V_17 ( V_1 ) ;
V_18 = V_1 ;
return 0 ;
}
static int F_7 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = F_8 ( V_20 ) ;
V_14 |= V_15 ;
F_9 ( V_8 ) ;
return 0 ;
}
static int F_10 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = F_8 ( V_20 ) ;
V_14 &= ~ V_15 ;
F_9 ( V_8 ) ;
return 0 ;
}
static int F_11 ( struct V_7 * V_8 )
{
return V_18 ;
}
static int F_12 ( struct V_21 * V_22 )
{
struct V_23 V_9 ;
struct V_24 * V_25 = F_13 ( & V_22 -> V_20 ) ;
V_16 = V_25 ;
if ( ! V_25 -> V_26 )
V_25 -> V_26 = - 1 ;
memset ( & V_9 , 0 , sizeof( struct V_23 ) ) ;
V_9 . type = V_27 ;
V_9 . V_28 = V_25 -> V_29 ;
V_30 = F_14 ( & V_22 -> V_20 ,
L_1 , & V_22 -> V_20 ,
NULL , & V_31 ,
& V_9 ) ;
if ( F_15 ( V_30 ) )
return F_16 ( V_30 ) ;
F_17 ( V_22 , V_30 ) ;
V_30 -> V_9 . V_11 = V_12 ;
V_30 -> V_9 . V_10 = V_25 -> V_32 ;
F_9 ( V_30 ) ;
return 0 ;
}
static int T_1 F_18 ( void )
{
if ( ! F_19 ( V_33 ) )
return - V_34 ;
F_20 ( V_35 , F_21 ( V_35 ) ) ;
return F_22 ( & V_36 ) ;
}
static void T_2 F_23 ( void )
{
F_24 ( & V_36 ) ;
}
