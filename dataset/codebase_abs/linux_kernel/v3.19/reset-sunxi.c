static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ,
struct V_4 ,
V_2 ) ;
int V_6 = V_3 / V_7 ;
int V_8 = V_3 % V_7 ;
unsigned long V_9 ;
T_1 V_10 ;
F_3 ( & V_5 -> V_11 , V_9 ) ;
V_10 = F_4 ( V_5 -> V_12 + ( V_6 * 4 ) ) ;
F_5 ( V_10 & ~ F_6 ( V_8 ) , V_5 -> V_12 + ( V_6 * 4 ) ) ;
F_7 ( & V_5 -> V_11 , V_9 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ,
struct V_4 ,
V_2 ) ;
int V_6 = V_3 / V_7 ;
int V_8 = V_3 % V_7 ;
unsigned long V_9 ;
T_1 V_10 ;
F_3 ( & V_5 -> V_11 , V_9 ) ;
V_10 = F_4 ( V_5 -> V_12 + ( V_6 * 4 ) ) ;
F_5 ( V_10 | F_6 ( V_8 ) , V_5 -> V_12 + ( V_6 * 4 ) ) ;
F_7 ( & V_5 -> V_11 , V_9 ) ;
return 0 ;
}
static int F_9 ( struct V_13 * V_14 )
{
struct V_4 * V_5 ;
struct V_15 V_16 ;
T_2 V_17 ;
int V_18 ;
V_5 = F_10 ( sizeof( * V_5 ) , V_19 ) ;
if ( ! V_5 )
return - V_20 ;
V_18 = F_11 ( V_14 , 0 , & V_16 ) ;
if ( V_18 )
goto V_21;
V_17 = F_12 ( & V_16 ) ;
if ( ! F_13 ( V_16 . V_22 , V_17 , V_14 -> V_23 ) ) {
V_18 = - V_24 ;
goto V_21;
}
V_5 -> V_12 = F_14 ( V_16 . V_22 , V_17 ) ;
if ( ! V_5 -> V_12 ) {
V_18 = - V_20 ;
goto V_21;
}
F_15 ( & V_5 -> V_11 ) ;
V_5 -> V_2 . V_25 = V_26 ;
V_5 -> V_2 . V_27 = V_17 * 32 ;
V_5 -> V_2 . V_28 = & V_29 ;
V_5 -> V_2 . V_30 = V_14 ;
F_16 ( & V_5 -> V_2 ) ;
return 0 ;
V_21:
F_17 ( V_5 ) ;
return V_18 ;
}
void T_3 F_18 ( void )
{
struct V_13 * V_14 ;
F_19 (np, sunxi_early_reset_dt_ids)
F_9 ( V_14 ) ;
}
static int F_20 ( struct V_31 * V_32 )
{
struct V_4 * V_5 ;
struct V_15 * V_16 ;
V_5 = F_21 ( & V_32 -> V_33 , sizeof( * V_5 ) , V_19 ) ;
if ( ! V_5 )
return - V_20 ;
V_16 = F_22 ( V_32 , V_34 , 0 ) ;
V_5 -> V_12 = F_23 ( & V_32 -> V_33 , V_16 ) ;
if ( F_24 ( V_5 -> V_12 ) )
return F_25 ( V_5 -> V_12 ) ;
F_15 ( & V_5 -> V_11 ) ;
V_5 -> V_2 . V_25 = V_26 ;
V_5 -> V_2 . V_27 = F_12 ( V_16 ) * 32 ;
V_5 -> V_2 . V_28 = & V_29 ;
V_5 -> V_2 . V_30 = V_32 -> V_33 . V_30 ;
return F_16 ( & V_5 -> V_2 ) ;
}
static int F_26 ( struct V_31 * V_32 )
{
struct V_4 * V_5 = F_27 ( V_32 ) ;
F_28 ( & V_5 -> V_2 ) ;
return 0 ;
}
