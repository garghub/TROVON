static void F_1 ( int V_1 )
{
F_2 ( & V_2 ) ;
V_1 = V_1 & 0xff ;
F_3 ( V_3 , V_4 ) ;
F_4 ( 10 ) ;
F_3 ( V_5 , V_6 ) ;
F_4 ( 10 ) ;
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
static int F_7 ( struct V_19 * V_20 , T_1 V_21 )
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
static int F_12 ( struct V_19 * V_20 )
{
struct V_22 V_9 ;
struct V_23 * V_24 = V_20 -> V_25 . V_26 ;
V_16 = V_24 ;
if ( ! V_24 -> V_27 )
V_24 -> V_27 = - 1 ;
memset ( & V_9 , 0 , sizeof( struct V_22 ) ) ;
V_9 . type = V_28 ;
V_9 . V_29 = V_24 -> V_30 ;
V_31 = F_13 ( L_1 ,
& V_20 -> V_25 , NULL ,
& V_32 ,
& V_9 ) ;
if ( F_14 ( V_31 ) )
return F_15 ( V_31 ) ;
F_16 ( V_20 , V_31 ) ;
V_31 -> V_9 . V_11 = V_12 ;
V_31 -> V_9 . V_10 = V_24 -> V_33 ;
F_9 ( V_31 ) ;
return 0 ;
}
static int F_17 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = F_8 ( V_20 ) ;
F_18 ( V_8 ) ;
return 0 ;
}
static int T_2 F_19 ( void )
{
if ( ! F_20 ( V_34 ) )
return - V_35 ;
F_21 ( V_36 , F_22 ( V_36 ) ) ;
return F_23 ( & V_37 ) ;
}
static void T_3 F_24 ( void )
{
F_25 ( & V_37 ) ;
}
