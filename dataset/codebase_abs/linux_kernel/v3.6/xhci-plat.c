static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 |= V_6 ;
}
static int F_2 ( struct V_7 * V_8 )
{
return F_3 ( V_8 , F_1 ) ;
}
static int F_4 ( struct V_9 * V_10 )
{
const struct V_11 * V_12 ;
struct V_3 * V_4 ;
struct V_13 * V_14 ;
struct V_7 * V_8 ;
int V_15 ;
int V_16 ;
if ( F_5 () )
return - V_17 ;
V_12 = & V_18 ;
V_16 = F_6 ( V_10 , 0 ) ;
if ( V_16 < 0 )
return - V_17 ;
V_14 = F_7 ( V_10 , V_19 , 0 ) ;
if ( ! V_14 )
return - V_17 ;
V_8 = F_8 ( V_12 , & V_10 -> V_2 , F_9 ( & V_10 -> V_2 ) ) ;
if ( ! V_8 )
return - V_20 ;
V_8 -> V_21 = V_14 -> V_22 ;
V_8 -> V_23 = F_10 ( V_14 ) ;
if ( ! F_11 ( V_8 -> V_21 , V_8 -> V_23 ,
V_12 -> V_24 ) ) {
F_12 ( & V_10 -> V_2 , L_1 ) ;
V_15 = - V_25 ;
goto V_26;
}
V_8 -> V_27 = F_13 ( V_8 -> V_21 , V_8 -> V_23 ) ;
if ( ! V_8 -> V_27 ) {
F_12 ( & V_10 -> V_2 , L_2 ) ;
V_15 = - V_28 ;
goto V_29;
}
V_15 = F_14 ( V_8 , V_16 , V_30 ) ;
if ( V_15 )
goto V_31;
V_8 = F_15 ( & V_10 -> V_2 ) ;
V_4 = F_16 ( V_8 ) ;
V_4 -> V_32 = F_17 ( V_12 , & V_10 -> V_2 ,
F_9 ( & V_10 -> V_2 ) , V_8 ) ;
if ( ! V_4 -> V_32 ) {
V_15 = - V_20 ;
goto V_33;
}
* ( (struct V_3 * * ) V_4 -> V_32 -> V_34 ) = V_4 ;
V_15 = F_14 ( V_4 -> V_32 , V_16 , V_30 ) ;
if ( V_15 )
goto V_35;
return 0 ;
V_35:
F_18 ( V_4 -> V_32 ) ;
V_33:
F_19 ( V_8 ) ;
V_31:
F_20 ( V_8 -> V_27 ) ;
V_29:
V_29 ( V_8 -> V_21 , V_8 -> V_23 ) ;
V_26:
F_18 ( V_8 ) ;
return V_15 ;
}
static int F_21 ( struct V_9 * V_2 )
{
struct V_7 * V_8 = F_22 ( V_2 ) ;
struct V_3 * V_4 = F_16 ( V_8 ) ;
F_19 ( V_4 -> V_32 ) ;
F_18 ( V_4 -> V_32 ) ;
F_19 ( V_8 ) ;
F_20 ( V_8 -> V_27 ) ;
F_18 ( V_8 ) ;
F_23 ( V_4 ) ;
return 0 ;
}
int F_24 ( void )
{
return F_25 ( & V_36 ) ;
}
void F_26 ( void )
{
F_27 ( & V_36 ) ;
}
