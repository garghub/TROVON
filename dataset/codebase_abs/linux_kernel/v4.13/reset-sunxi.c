static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ,
struct V_4 ,
V_2 ) ;
int V_6 = sizeof( V_7 ) ;
int V_8 = V_3 / ( V_6 * V_9 ) ;
int V_10 = V_3 % ( V_6 * V_9 ) ;
unsigned long V_11 ;
V_7 V_12 ;
F_3 ( & V_5 -> V_13 , V_11 ) ;
V_12 = F_4 ( V_5 -> V_14 + ( V_8 * V_6 ) ) ;
F_5 ( V_12 & ~ F_6 ( V_10 ) , V_5 -> V_14 + ( V_8 * V_6 ) ) ;
F_7 ( & V_5 -> V_13 , V_11 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ,
struct V_4 ,
V_2 ) ;
int V_6 = sizeof( V_7 ) ;
int V_8 = V_3 / ( V_6 * V_9 ) ;
int V_10 = V_3 % ( V_6 * V_9 ) ;
unsigned long V_11 ;
V_7 V_12 ;
F_3 ( & V_5 -> V_13 , V_11 ) ;
V_12 = F_4 ( V_5 -> V_14 + ( V_8 * V_6 ) ) ;
F_5 ( V_12 | F_6 ( V_10 ) , V_5 -> V_14 + ( V_8 * V_6 ) ) ;
F_7 ( & V_5 -> V_13 , V_11 ) ;
return 0 ;
}
static int F_9 ( struct V_15 * V_16 )
{
struct V_4 * V_5 ;
struct V_17 V_18 ;
T_1 V_19 ;
int V_20 ;
V_5 = F_10 ( sizeof( * V_5 ) , V_21 ) ;
if ( ! V_5 )
return - V_22 ;
V_20 = F_11 ( V_16 , 0 , & V_18 ) ;
if ( V_20 )
goto V_23;
V_19 = F_12 ( & V_18 ) ;
if ( ! F_13 ( V_18 . V_24 , V_19 , V_16 -> V_25 ) ) {
V_20 = - V_26 ;
goto V_23;
}
V_5 -> V_14 = F_14 ( V_18 . V_24 , V_19 ) ;
if ( ! V_5 -> V_14 ) {
V_20 = - V_22 ;
goto V_23;
}
F_15 ( & V_5 -> V_13 ) ;
V_5 -> V_2 . V_27 = V_28 ;
V_5 -> V_2 . V_29 = V_19 * 32 ;
V_5 -> V_2 . V_30 = & V_31 ;
V_5 -> V_2 . V_32 = V_16 ;
return F_16 ( & V_5 -> V_2 ) ;
V_23:
F_17 ( V_5 ) ;
return V_20 ;
}
void T_2 F_18 ( void )
{
struct V_15 * V_16 ;
F_19 (np, sunxi_early_reset_dt_ids)
F_9 ( V_16 ) ;
}
static int F_20 ( struct V_33 * V_34 )
{
struct V_4 * V_5 ;
struct V_17 * V_18 ;
V_5 = F_21 ( & V_34 -> V_35 , sizeof( * V_5 ) , V_21 ) ;
if ( ! V_5 )
return - V_22 ;
V_18 = F_22 ( V_34 , V_36 , 0 ) ;
V_5 -> V_14 = F_23 ( & V_34 -> V_35 , V_18 ) ;
if ( F_24 ( V_5 -> V_14 ) )
return F_25 ( V_5 -> V_14 ) ;
F_15 ( & V_5 -> V_13 ) ;
V_5 -> V_2 . V_27 = V_28 ;
V_5 -> V_2 . V_29 = F_12 ( V_18 ) * 32 ;
V_5 -> V_2 . V_30 = & V_31 ;
V_5 -> V_2 . V_32 = V_34 -> V_35 . V_32 ;
return F_26 ( & V_34 -> V_35 , & V_5 -> V_2 ) ;
}
