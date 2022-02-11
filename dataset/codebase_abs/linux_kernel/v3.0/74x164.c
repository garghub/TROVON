static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static int F_3 ( struct V_1 * V_4 )
{
return F_4 ( V_4 -> V_5 ,
& V_4 -> V_6 , sizeof( V_4 -> V_6 ) ) ;
}
static int F_5 ( struct V_2 * V_3 ,
unsigned V_7 , int V_8 )
{
F_6 ( V_3 , V_7 , V_8 ) ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 , unsigned V_7 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_9 ;
F_8 ( & V_4 -> V_10 ) ;
V_9 = ( V_4 -> V_6 >> V_7 ) & 0x1 ;
F_9 ( & V_4 -> V_10 ) ;
return V_9 ;
}
static void F_6 ( struct V_2 * V_3 ,
unsigned V_7 , int V_8 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_8 ( & V_4 -> V_10 ) ;
if ( V_8 )
V_4 -> V_6 |= ( 1 << V_7 ) ;
else
V_4 -> V_6 &= ~ ( 1 << V_7 ) ;
F_3 ( V_4 ) ;
F_9 ( & V_4 -> V_10 ) ;
}
static int T_1 F_10 ( struct V_11 * V_5 )
{
struct V_1 * V_4 ;
struct V_12 * V_13 ;
int V_9 ;
V_13 = V_5 -> V_14 . V_15 ;
if ( ! V_13 || ! V_13 -> V_16 ) {
F_11 ( & V_5 -> V_14 , L_1 ) ;
return - V_17 ;
}
V_5 -> V_18 = 8 ;
V_9 = F_12 ( V_5 ) ;
if ( V_9 < 0 )
return V_9 ;
V_4 = F_13 ( sizeof( * V_4 ) , V_19 ) ;
if ( ! V_4 )
return - V_20 ;
F_14 ( & V_4 -> V_10 ) ;
F_15 ( & V_5 -> V_14 , V_4 ) ;
V_4 -> V_5 = V_5 ;
V_4 -> V_2 . V_21 = V_22 ,
V_4 -> V_2 . V_23 = F_5 ;
V_4 -> V_2 . V_24 = F_7 ;
V_4 -> V_2 . V_25 = F_6 ;
V_4 -> V_2 . V_16 = V_13 -> V_16 ;
V_4 -> V_2 . V_26 = V_27 ;
V_4 -> V_2 . V_28 = 1 ;
V_4 -> V_2 . V_14 = & V_5 -> V_14 ;
V_4 -> V_2 . V_29 = V_30 ;
V_9 = F_3 ( V_4 ) ;
if ( V_9 ) {
F_16 ( & V_5 -> V_14 , L_2 , V_9 ) ;
goto V_31;
}
V_9 = F_17 ( & V_4 -> V_2 ) ;
if ( V_9 )
goto V_31;
return V_9 ;
V_31:
F_15 ( & V_5 -> V_14 , NULL ) ;
F_18 ( & V_4 -> V_10 ) ;
F_19 ( V_4 ) ;
return V_9 ;
}
static int T_2 F_20 ( struct V_11 * V_5 )
{
struct V_1 * V_4 ;
int V_9 ;
V_4 = F_21 ( & V_5 -> V_14 ) ;
if ( V_4 == NULL )
return - V_32 ;
F_15 ( & V_5 -> V_14 , NULL ) ;
V_9 = F_22 ( & V_4 -> V_2 ) ;
if ( ! V_9 ) {
F_18 ( & V_4 -> V_10 ) ;
F_19 ( V_4 ) ;
} else
F_16 ( & V_5 -> V_14 , L_3 ,
V_9 ) ;
return V_9 ;
}
static int T_3 F_23 ( void )
{
return F_24 ( & V_33 ) ;
}
static void T_4 F_25 ( void )
{
F_26 ( & V_33 ) ;
}
