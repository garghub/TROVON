static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_3 * V_6 = V_2 -> V_7 ;
int V_8 ;
V_8 = F_2 ( V_4 , V_9 |
V_10 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_3 ( V_4 , 0 , 11289600 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_2 ( V_6 , V_9 |
V_11 ) ;
return V_8 ;
}
static int F_4 ( struct V_12 * V_13 )
{
int V_8 = - V_14 ;
const struct V_15 * V_16 ;
struct V_17 * V_18 ;
V_16 = V_13 -> V_16 ;
if ( ! V_16 ) {
F_5 ( & V_13 -> V_19 , L_1 ) ;
return - V_20 ;
}
V_18 = (struct V_17 * ) V_16 -> V_21 ;
V_22 = F_6 ( L_2 , V_18 -> V_23 ) ;
if ( ! V_22 )
goto V_24;
V_25 . V_26 = V_18 -> V_26 ;
V_25 . V_27 = V_18 -> V_26 ;
V_25 . V_28 = V_18 -> V_7 ;
V_25 . V_29 = V_18 -> V_30 ;
V_25 . V_31 = V_18 -> V_4 ;
V_32 . V_26 = V_18 -> V_33 ;
F_7 ( V_22 , & V_32 ) ;
V_8 = F_8 ( V_22 ) ;
if ( V_8 )
F_9 ( V_22 ) ;
V_24:
return V_8 ;
}
static int F_10 ( struct V_12 * V_13 )
{
F_11 ( V_22 ) ;
return 0 ;
}
static int T_1 F_12 ( void )
{
return F_13 ( & V_34 ) ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_34 ) ;
}
