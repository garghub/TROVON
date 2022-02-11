static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_4 ) ;
F_3 ( V_4 ) ;
F_4 ( V_4 ) ;
F_5 ( V_2 ) ;
F_6 ( V_4 ) ;
V_2 -> V_5 = NULL ;
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
F_18 ( & V_4 -> V_16 . V_18 , 1 ) ;
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
F_18 ( & V_4 -> V_16 . V_18 , 0 ) ;
F_19 () ;
}
F_22 ( V_15 ) ;
return 0 ;
}
static int F_23 ( struct V_13 * V_14 )
{
struct V_19 * V_20 ;
V_20 = F_24 ( 1 ) ;
if ( ! V_20 )
return - V_9 ;
V_20 -> V_21 [ 0 ] . V_22 = F_25 ( V_14 , 0 ) ;
V_20 -> V_21 [ 0 ] . V_23 = F_26 ( V_14 , 0 ) ;
F_27 ( V_20 , L_1 , false ) ;
F_6 ( V_20 ) ;
return 0 ;
}
static int F_28 ( struct V_13 * V_14 ,
const struct V_24 * V_25 )
{
unsigned long V_26 ;
int V_7 ;
V_26 = F_26 ( V_14 , 0 ) ;
if ( V_26 < 4 * 1024 * 1024 ) {
F_29 ( L_2 ) ;
return - V_9 ;
}
V_7 = F_23 ( V_14 ) ;
if ( V_7 )
return V_7 ;
return F_30 ( V_14 , V_25 , & V_27 ) ;
}
static void F_31 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_15 ( V_14 ) ;
F_32 ( V_2 ) ;
}
static int T_1 F_33 ( void )
{
if ( F_34 () && V_28 == - 1 )
return - V_29 ;
if ( V_28 == 0 )
return - V_29 ;
return F_35 ( & V_30 ) ;
}
static void T_2 F_36 ( void )
{
F_37 ( & V_30 ) ;
}
