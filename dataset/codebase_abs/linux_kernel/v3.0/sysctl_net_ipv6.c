static int T_1 F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
struct V_2 * V_4 ;
struct V_2 * V_5 ;
int V_6 ;
V_6 = - V_7 ;
V_3 = F_2 ( V_8 , sizeof( V_8 ) ,
V_9 ) ;
if ( ! V_3 )
goto V_10;
V_4 = F_3 ( V_1 ) ;
if ( ! V_4 )
goto V_11;
V_3 [ 0 ] . V_12 = V_4 ;
V_5 = F_4 ( V_1 ) ;
if ( ! V_5 )
goto V_13;
V_3 [ 1 ] . V_12 = V_5 ;
V_3 [ 2 ] . V_14 = & V_1 -> V_15 . V_16 . V_17 ;
V_1 -> V_15 . V_16 . V_18 = F_5 ( V_1 , V_19 ,
V_3 ) ;
if ( ! V_1 -> V_15 . V_16 . V_18 )
goto V_20;
V_6 = 0 ;
V_10:
return V_6 ;
V_20:
F_6 ( V_5 ) ;
V_13:
F_6 ( V_4 ) ;
V_11:
F_6 ( V_3 ) ;
goto V_10;
}
static void T_2 F_7 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
struct V_2 * V_4 ;
struct V_2 * V_5 ;
V_3 = V_1 -> V_15 . V_16 . V_18 -> V_21 ;
V_4 = V_3 [ 0 ] . V_12 ;
V_5 = V_3 [ 1 ] . V_12 ;
F_8 ( V_1 -> V_15 . V_16 . V_18 ) ;
F_6 ( V_3 ) ;
F_6 ( V_4 ) ;
F_6 ( V_5 ) ;
}
int F_9 ( void )
{
int V_6 = - V_7 ;
V_22 = F_10 ( V_19 , V_23 ) ;
if ( V_22 == NULL )
goto V_10;
V_6 = F_11 ( & V_24 ) ;
if ( V_6 )
goto V_25;
V_10:
return V_6 ;
V_25:
F_8 ( V_22 ) ;
goto V_10;
}
void F_12 ( void )
{
F_8 ( V_22 ) ;
F_13 ( & V_24 ) ;
}
int F_14 ( void )
{
V_26 = F_15 ( V_19 , V_27 ) ;
if ( V_26 == NULL )
return - V_7 ;
return 0 ;
}
void F_16 ( void )
{
F_8 ( V_26 ) ;
}
