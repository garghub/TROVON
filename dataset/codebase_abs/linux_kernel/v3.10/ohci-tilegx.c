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
struct V_11 * V_12 = V_10 -> V_13 . V_14 ;
T_1 V_15 = { 0 } ;
int V_16 = F_10 () ;
int V_5 ;
if ( F_11 () )
return - V_17 ;
if ( F_12 ( & V_12 -> V_18 , V_12 -> V_19 , 0 ) != 0 )
return - V_20 ;
V_2 = F_13 ( & V_21 , & V_10 -> V_13 ,
F_14 ( & V_10 -> V_13 ) ) ;
if ( ! V_2 ) {
V_5 = - V_22 ;
goto V_23;
}
V_2 -> V_24 =
( V_25 ) F_15 ( & V_12 -> V_18 ) ;
V_2 -> V_26 = F_16 ( & V_12 -> V_18 ) ;
V_2 -> V_27 = F_15 ( & V_12 -> V_18 ) ;
F_1 () ;
V_12 -> V_28 = F_17 () ;
if ( V_12 -> V_28 < 0 ) {
V_5 = - V_20 ;
goto V_29;
}
F_18 ( V_12 -> V_28 , V_30 ) ;
V_5 = F_19 ( & V_12 -> V_18 ,
F_20 ( V_16 ) , F_21 ( V_16 ) ,
V_31 , V_12 -> V_28 ) ;
if ( V_5 ) {
V_5 = - V_20 ;
goto V_32;
}
V_15 = F_22 ( V_15 , V_33 ) ;
V_5 = F_23 ( & V_12 -> V_18 , V_15 , 0 ) ;
if ( V_5 ) {
V_5 = - V_20 ;
goto V_32;
}
F_24 ( F_4 ( V_2 ) ) ;
V_5 = F_25 ( V_2 , V_12 -> V_28 , V_34 ) ;
if ( V_5 == 0 ) {
F_26 ( V_10 , V_2 ) ;
return V_5 ;
}
V_32:
F_27 ( V_12 -> V_28 ) ;
V_29:
F_2 () ;
F_28 ( V_2 ) ;
V_23:
F_29 ( & V_12 -> V_18 ) ;
return V_5 ;
}
static int F_30 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_31 ( V_10 ) ;
struct V_11 * V_12 = V_10 -> V_13 . V_14 ;
F_32 ( V_2 ) ;
F_28 ( V_2 ) ;
F_2 () ;
F_29 ( & V_12 -> V_18 ) ;
F_27 ( V_12 -> V_28 ) ;
F_26 ( V_10 , NULL ) ;
return 0 ;
}
static void F_33 ( struct V_9 * V_10 )
{
F_34 ( V_10 ) ;
F_30 ( V_10 ) ;
}
