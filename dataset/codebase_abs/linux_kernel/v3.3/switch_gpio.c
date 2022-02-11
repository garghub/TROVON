static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 =
F_2 ( V_2 , struct V_4 , V_2 ) ;
V_3 = F_3 ( V_5 -> V_6 ) ;
F_4 ( & V_5 -> V_7 , V_3 ) ;
}
static T_1 F_5 ( int V_8 , void * V_9 )
{
struct V_4 * V_10 =
(struct V_4 * ) V_9 ;
F_6 ( & V_10 -> V_2 ) ;
return V_11 ;
}
static T_2 F_7 ( struct V_12 * V_7 , char * V_13 )
{
struct V_4 * V_10 =
F_2 ( V_7 , struct V_4 , V_7 ) ;
const char * V_3 ;
if ( F_8 ( V_7 ) )
V_3 = V_10 -> V_14 ;
else
V_3 = V_10 -> V_15 ;
if ( V_3 )
return sprintf ( V_13 , L_1 , V_3 ) ;
return - 1 ;
}
static int F_9 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 . V_21 ;
struct V_4 * V_10 ;
int V_22 = 0 ;
if ( ! V_19 )
return - V_23 ;
V_10 = F_10 ( sizeof( struct V_4 ) , V_24 ) ;
if ( ! V_10 )
return - V_25 ;
V_10 -> V_7 . V_26 = V_19 -> V_26 ;
V_10 -> V_6 = V_19 -> V_6 ;
V_10 -> V_27 = V_19 -> V_27 ;
V_10 -> V_28 = V_19 -> V_28 ;
V_10 -> V_14 = V_19 -> V_14 ;
V_10 -> V_15 = V_19 -> V_15 ;
V_10 -> V_7 . V_29 = F_7 ;
V_22 = F_11 ( & V_10 -> V_7 ) ;
if ( V_22 < 0 )
goto V_30;
V_22 = F_12 ( V_10 -> V_6 , V_17 -> V_26 ) ;
if ( V_22 < 0 )
goto V_31;
V_22 = F_13 ( V_10 -> V_6 ) ;
if ( V_22 < 0 )
goto V_32;
F_14 ( & V_10 -> V_2 , F_1 ) ;
V_10 -> V_8 = F_15 ( V_10 -> V_6 ) ;
if ( V_10 -> V_8 < 0 ) {
V_22 = V_10 -> V_8 ;
goto V_33;
}
V_22 = F_16 ( V_10 -> V_8 , F_5 ,
V_34 , V_17 -> V_26 , V_10 ) ;
if ( V_22 < 0 )
goto V_35;
F_1 ( & V_10 -> V_2 ) ;
return 0 ;
V_35:
V_33:
V_32:
F_17 ( V_10 -> V_6 ) ;
V_31:
F_18 ( & V_10 -> V_7 ) ;
V_30:
F_19 ( V_10 ) ;
return V_22 ;
}
static int T_3 F_20 ( struct V_16 * V_17 )
{
struct V_4 * V_10 = F_21 ( V_17 ) ;
F_22 ( & V_10 -> V_2 ) ;
F_17 ( V_10 -> V_6 ) ;
F_18 ( & V_10 -> V_7 ) ;
F_19 ( V_10 ) ;
return 0 ;
}
static int T_4 F_23 ( void )
{
return F_24 ( & V_36 ) ;
}
static void T_5 F_25 ( void )
{
F_26 ( & V_36 ) ;
}
