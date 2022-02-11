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
struct V_8 * V_9 = V_5 -> V_10 . V_11 ;
T_1 V_12 = { 0 } ;
int V_13 = F_6 () ;
int V_3 ;
if ( F_7 () )
return - V_14 ;
if ( F_8 ( & V_9 -> V_15 , V_9 -> V_16 , 1 ) != 0 )
return - V_17 ;
V_2 = F_9 ( & V_18 , & V_5 -> V_10 ,
F_10 ( & V_5 -> V_10 ) ) ;
if ( ! V_2 )
return - V_19 ;
V_2 -> V_20 =
( V_21 ) F_11 ( & V_9 -> V_15 ) ;
V_2 -> V_22 = F_12 ( & V_9 -> V_15 ) ;
V_2 -> V_23 = F_11 ( & V_9 -> V_15 ) ;
F_1 () ;
V_7 = F_13 ( V_2 ) ;
V_7 -> V_24 = V_2 -> V_23 ;
V_7 -> V_23 =
V_2 -> V_23 + F_14 ( V_7 , F_15 ( & V_7 -> V_24 -> V_25 ) ) ;
V_7 -> V_26 = F_15 ( & V_7 -> V_24 -> V_26 ) ;
V_9 -> V_27 = F_16 () ;
if ( V_9 -> V_27 < 0 ) {
V_3 = - V_17 ;
goto V_28;
}
F_17 ( V_9 -> V_27 , V_29 ) ;
V_3 = F_18 ( & V_9 -> V_15 ,
F_19 ( V_13 ) , F_20 ( V_13 ) ,
V_30 , V_9 -> V_27 ) ;
if ( V_3 ) {
V_3 = - V_17 ;
goto V_31;
}
V_12 = F_21 ( V_12 , V_32 ) ;
V_3 = F_22 ( & V_9 -> V_15 , V_12 , 0 ) ;
if ( V_3 ) {
V_3 = - V_17 ;
goto V_31;
}
V_3 = F_23 ( V_2 , V_9 -> V_27 , V_33 ) ;
if ( V_3 == 0 ) {
F_24 ( V_5 , V_2 ) ;
return V_3 ;
}
V_31:
F_25 ( V_9 -> V_27 ) ;
V_28:
F_2 () ;
F_26 ( V_2 ) ;
F_27 ( & V_9 -> V_15 ) ;
return V_3 ;
}
static int F_28 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_29 ( V_5 ) ;
struct V_8 * V_9 = V_5 -> V_10 . V_11 ;
F_30 ( V_2 ) ;
F_26 ( V_2 ) ;
F_2 () ;
F_27 ( & V_9 -> V_15 ) ;
F_25 ( V_9 -> V_27 ) ;
F_24 ( V_5 , NULL ) ;
return 0 ;
}
static void F_31 ( struct V_4 * V_5 )
{
F_32 ( V_5 ) ;
F_28 ( V_5 ) ;
}
