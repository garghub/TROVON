static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_4 ) ;
F_3 ( V_4 ) ;
F_4 ( V_4 ) ;
F_5 ( V_2 ) ;
F_6 ( V_4 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned long V_6 )
{
struct V_3 * V_4 ;
int V_7 ;
V_4 = F_8 ( sizeof( * V_4 ) , V_8 ) ;
if ( V_4 == NULL )
return - V_9 ;
V_2 -> V_5 = V_4 ;
V_4 -> V_2 = V_2 ;
V_7 = F_9 ( V_2 , V_6 ) ;
if ( V_7 )
goto V_10;
V_7 = F_10 ( V_4 ) ;
if ( V_7 )
goto V_10;
V_7 = F_11 ( V_4 ) ;
if ( V_7 )
goto V_10;
if ( V_11 )
F_12 ( V_4 ) ;
return 0 ;
V_10:
F_1 ( V_2 ) ;
return V_7 ;
}
static int F_13 ( struct V_12 * V_2 )
{
struct V_13 * V_14 = F_14 ( V_2 ) ;
struct V_1 * V_15 = F_15 ( V_14 ) ;
struct V_3 * V_4 = V_15 -> V_5 ;
F_16 ( V_15 ) ;
if ( V_4 -> V_16 . V_17 ) {
F_17 () ;
F_18 ( V_4 -> V_16 . V_18 . V_19 , 1 ) ;
F_19 () ;
}
return 0 ;
}
static int F_20 ( struct V_12 * V_2 )
{
struct V_13 * V_14 = F_14 ( V_2 ) ;
struct V_1 * V_15 = F_15 ( V_14 ) ;
struct V_3 * V_4 = V_15 -> V_5 ;
F_21 ( V_15 ) ;
if ( V_4 -> V_16 . V_17 ) {
F_17 () ;
F_18 ( V_4 -> V_16 . V_18 . V_19 , 0 ) ;
F_19 () ;
}
F_22 ( V_15 ) ;
return 0 ;
}
static int F_23 ( struct V_13 * V_14 )
{
struct V_20 * V_21 ;
V_21 = F_24 ( 1 ) ;
if ( ! V_21 )
return - V_9 ;
V_21 -> V_22 [ 0 ] . V_23 = F_25 ( V_14 , 0 ) ;
V_21 -> V_22 [ 0 ] . V_24 = F_26 ( V_14 , 0 ) ;
F_27 ( V_21 , L_1 , false ) ;
F_6 ( V_21 ) ;
return 0 ;
}
static int F_28 ( struct V_13 * V_14 ,
const struct V_25 * V_26 )
{
int V_7 ;
V_7 = F_23 ( V_14 ) ;
if ( V_7 )
return V_7 ;
return F_29 ( V_14 , V_26 , & V_27 ) ;
}
static void F_30 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_15 ( V_14 ) ;
F_31 ( V_2 ) ;
}
static int T_1 F_32 ( void )
{
return F_33 ( & V_27 , & V_28 ) ;
}
static void T_2 F_34 ( void )
{
F_35 ( & V_27 , & V_28 ) ;
}
