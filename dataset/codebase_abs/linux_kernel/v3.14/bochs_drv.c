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
static int F_13 ( struct V_12 * V_13 )
{
struct V_14 * V_15 ;
V_15 = F_14 ( 1 ) ;
if ( ! V_15 )
return - V_9 ;
V_15 -> V_16 [ 0 ] . V_17 = F_15 ( V_13 , 0 ) ;
V_15 -> V_16 [ 0 ] . V_18 = F_16 ( V_13 , 0 ) ;
F_17 ( V_15 , L_1 , false ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_18 ( struct V_12 * V_13 ,
const struct V_19 * V_20 )
{
int V_7 ;
V_7 = F_13 ( V_13 ) ;
if ( V_7 )
return V_7 ;
return F_19 ( V_13 , V_20 , & V_21 ) ;
}
static void F_20 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_21 ( V_13 ) ;
F_22 ( V_2 ) ;
}
static int T_1 F_23 ( void )
{
return F_24 ( & V_21 , & V_22 ) ;
}
static void T_2 F_25 ( void )
{
F_26 ( & V_21 , & V_22 ) ;
}
