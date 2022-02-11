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
V_15 = F_8 ( & V_10 -> V_2 , F_9 ( 32 ) ) ;
if ( V_15 )
return V_15 ;
if ( ! V_10 -> V_2 . V_20 )
V_10 -> V_2 . V_20 = & V_10 -> V_2 . V_21 ;
else
F_10 ( & V_10 -> V_2 , F_9 ( 32 ) ) ;
V_8 = F_11 ( V_12 , & V_10 -> V_2 , F_12 ( & V_10 -> V_2 ) ) ;
if ( ! V_8 )
return - V_22 ;
V_8 -> V_23 = V_14 -> V_24 ;
V_8 -> V_25 = F_13 ( V_14 ) ;
if ( ! F_14 ( V_8 -> V_23 , V_8 -> V_25 ,
V_12 -> V_26 ) ) {
F_15 ( & V_10 -> V_2 , L_1 ) ;
V_15 = - V_27 ;
goto V_28;
}
V_8 -> V_29 = F_16 ( V_8 -> V_23 , V_8 -> V_25 ) ;
if ( ! V_8 -> V_29 ) {
F_15 ( & V_10 -> V_2 , L_2 ) ;
V_15 = - V_30 ;
goto V_31;
}
V_15 = F_17 ( V_8 , V_16 , V_32 ) ;
if ( V_15 )
goto V_33;
V_8 = F_18 ( V_10 ) ;
V_4 = F_19 ( V_8 ) ;
V_4 -> V_34 = F_20 ( V_12 , & V_10 -> V_2 ,
F_12 ( & V_10 -> V_2 ) , V_8 ) ;
if ( ! V_4 -> V_34 ) {
V_15 = - V_22 ;
goto V_35;
}
* ( (struct V_3 * * ) V_4 -> V_34 -> V_36 ) = V_4 ;
V_15 = F_17 ( V_4 -> V_34 , V_16 , V_32 ) ;
if ( V_15 )
goto V_37;
return 0 ;
V_37:
F_21 ( V_4 -> V_34 ) ;
V_35:
F_22 ( V_8 ) ;
V_33:
F_23 ( V_8 -> V_29 ) ;
V_31:
V_31 ( V_8 -> V_23 , V_8 -> V_25 ) ;
V_28:
F_21 ( V_8 ) ;
return V_15 ;
}
static int F_24 ( struct V_9 * V_2 )
{
struct V_7 * V_8 = F_18 ( V_2 ) ;
struct V_3 * V_4 = F_19 ( V_8 ) ;
F_22 ( V_4 -> V_34 ) ;
F_21 ( V_4 -> V_34 ) ;
F_22 ( V_8 ) ;
F_23 ( V_8 -> V_29 ) ;
V_31 ( V_8 -> V_23 , V_8 -> V_25 ) ;
F_21 ( V_8 ) ;
F_25 ( V_4 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_27 ( V_2 ) ;
struct V_3 * V_4 = F_19 ( V_8 ) ;
return F_28 ( V_4 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_27 ( V_2 ) ;
struct V_3 * V_4 = F_19 ( V_8 ) ;
return F_30 ( V_4 , 0 ) ;
}
int F_31 ( void )
{
return F_32 ( & V_38 ) ;
}
void F_33 ( void )
{
F_34 ( & V_38 ) ;
}
