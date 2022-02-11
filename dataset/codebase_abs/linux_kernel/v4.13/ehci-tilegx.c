static void F_1 ( void )
{
}
static void F_2 ( void )
{
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 = F_4 ( V_2 ) ;
return V_3 ;
}
static int F_5 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_8 * V_9 = F_6 ( & V_5 -> V_10 ) ;
T_1 V_11 = { 0 } ;
int V_12 = F_7 () ;
int V_3 ;
if ( F_8 () )
return - V_13 ;
if ( F_9 ( & V_9 -> V_14 , V_9 -> V_15 , 1 ) != 0 )
return - V_16 ;
V_2 = F_10 ( & V_17 , & V_5 -> V_10 ,
F_11 ( & V_5 -> V_10 ) ) ;
if ( ! V_2 ) {
V_3 = - V_18 ;
goto V_19;
}
V_2 -> V_20 =
( V_21 ) F_12 ( & V_9 -> V_14 ) ;
V_2 -> V_22 = F_13 ( & V_9 -> V_14 ) ;
V_2 -> V_23 = F_12 ( & V_9 -> V_14 ) ;
F_1 () ;
V_7 = F_14 ( V_2 ) ;
V_7 -> V_24 = V_2 -> V_23 ;
V_7 -> V_23 =
V_2 -> V_23 + F_15 ( V_7 , F_16 ( & V_7 -> V_24 -> V_25 ) ) ;
V_7 -> V_26 = F_16 ( & V_7 -> V_24 -> V_26 ) ;
V_9 -> V_27 = F_17 ( - 1 ) ;
if ( ! V_9 -> V_27 ) {
V_3 = - V_16 ;
goto V_28;
}
F_18 ( V_9 -> V_27 , V_29 ) ;
V_3 = F_19 ( & V_9 -> V_14 ,
F_20 ( V_12 ) , F_21 ( V_12 ) ,
V_30 , V_9 -> V_27 ) ;
if ( V_3 ) {
V_3 = - V_16 ;
goto V_31;
}
V_11 = F_22 ( V_11 , V_32 ) ;
V_3 = F_23 ( & V_9 -> V_14 , V_11 , 0 ) ;
if ( V_3 ) {
V_3 = - V_16 ;
goto V_31;
}
V_3 = F_24 ( V_2 , V_9 -> V_27 , V_33 ) ;
if ( V_3 == 0 ) {
F_25 ( V_5 , V_2 ) ;
F_26 ( V_2 -> V_34 . V_35 ) ;
return V_3 ;
}
V_31:
F_27 ( V_9 -> V_27 ) ;
V_28:
F_2 () ;
F_28 ( V_2 ) ;
V_19:
F_29 ( & V_9 -> V_14 ) ;
return V_3 ;
}
static int F_30 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_31 ( V_5 ) ;
struct V_8 * V_9 = F_6 ( & V_5 -> V_10 ) ;
F_32 ( V_2 ) ;
F_28 ( V_2 ) ;
F_2 () ;
F_29 ( & V_9 -> V_14 ) ;
F_27 ( V_9 -> V_27 ) ;
return 0 ;
}
static void F_33 ( struct V_4 * V_5 )
{
F_34 ( V_5 ) ;
F_30 ( V_5 ) ;
}
