static void F_1 ( void )
{
}
static void F_2 ( void )
{
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_4 ( V_2 ) ;
int V_5 ;
V_5 = F_5 ( V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_6 ( V_4 ) ;
if ( V_5 < 0 ) {
F_7 ( V_2 -> V_6 . V_7 , L_1 ,
V_2 -> V_6 . V_8 ) ;
F_8 ( V_2 ) ;
return V_5 ;
}
return 0 ;
}
static int F_9 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 = F_10 ( & V_10 -> V_13 ) ;
T_1 V_14 = { 0 } ;
int V_15 = F_11 () ;
int V_5 ;
if ( F_12 () )
return - V_16 ;
if ( F_13 ( & V_12 -> V_17 , V_12 -> V_18 , 0 ) != 0 )
return - V_19 ;
V_2 = F_14 ( & V_20 , & V_10 -> V_13 ,
F_15 ( & V_10 -> V_13 ) ) ;
if ( ! V_2 ) {
V_5 = - V_21 ;
goto V_22;
}
V_2 -> V_23 =
( V_24 ) F_16 ( & V_12 -> V_17 ) ;
V_2 -> V_25 = F_17 ( & V_12 -> V_17 ) ;
V_2 -> V_26 = F_16 ( & V_12 -> V_17 ) ;
F_1 () ;
V_12 -> V_27 = F_18 () ;
if ( V_12 -> V_27 < 0 ) {
V_5 = - V_19 ;
goto V_28;
}
F_19 ( V_12 -> V_27 , V_29 ) ;
V_5 = F_20 ( & V_12 -> V_17 ,
F_21 ( V_15 ) , F_22 ( V_15 ) ,
V_30 , V_12 -> V_27 ) ;
if ( V_5 ) {
V_5 = - V_19 ;
goto V_31;
}
V_14 = F_23 ( V_14 , V_32 ) ;
V_5 = F_24 ( & V_12 -> V_17 , V_14 , 0 ) ;
if ( V_5 ) {
V_5 = - V_19 ;
goto V_31;
}
F_25 ( F_4 ( V_2 ) ) ;
V_5 = F_26 ( V_2 , V_12 -> V_27 , V_33 ) ;
if ( V_5 == 0 ) {
F_27 ( V_10 , V_2 ) ;
F_28 ( V_2 -> V_6 . V_7 ) ;
return V_5 ;
}
V_31:
F_29 ( V_12 -> V_27 ) ;
V_28:
F_2 () ;
F_30 ( V_2 ) ;
V_22:
F_31 ( & V_12 -> V_17 ) ;
return V_5 ;
}
static int F_32 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_33 ( V_10 ) ;
struct V_11 * V_12 = F_10 ( & V_10 -> V_13 ) ;
F_34 ( V_2 ) ;
F_30 ( V_2 ) ;
F_2 () ;
F_31 ( & V_12 -> V_17 ) ;
F_29 ( V_12 -> V_27 ) ;
return 0 ;
}
static void F_35 ( struct V_9 * V_10 )
{
F_36 ( V_10 ) ;
F_32 ( V_10 ) ;
}
