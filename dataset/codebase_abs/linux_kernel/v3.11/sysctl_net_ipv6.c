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
V_3 [ 0 ] . V_11 = & V_1 -> V_12 . V_13 . V_14 ;
V_4 = F_3 ( V_1 ) ;
if ( ! V_4 )
goto V_15;
V_5 = F_4 ( V_1 ) ;
if ( ! V_5 )
goto V_16;
V_1 -> V_12 . V_13 . V_17 = F_5 ( V_1 , L_1 , V_3 ) ;
if ( ! V_1 -> V_12 . V_13 . V_17 )
goto V_18;
V_1 -> V_12 . V_13 . V_19 =
F_5 ( V_1 , L_2 , V_4 ) ;
if ( ! V_1 -> V_12 . V_13 . V_19 )
goto V_20;
V_1 -> V_12 . V_13 . V_21 =
F_5 ( V_1 , L_3 , V_5 ) ;
if ( ! V_1 -> V_12 . V_13 . V_21 )
goto V_22;
V_6 = 0 ;
V_10:
return V_6 ;
V_22:
F_6 ( V_1 -> V_12 . V_13 . V_19 ) ;
V_20:
F_6 ( V_1 -> V_12 . V_13 . V_17 ) ;
V_18:
F_7 ( V_5 ) ;
V_16:
F_7 ( V_4 ) ;
V_15:
F_7 ( V_3 ) ;
goto V_10;
}
static void T_2 F_8 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
struct V_2 * V_4 ;
struct V_2 * V_5 ;
V_3 = V_1 -> V_12 . V_13 . V_17 -> V_23 ;
V_4 = V_1 -> V_12 . V_13 . V_19 -> V_23 ;
V_5 = V_1 -> V_12 . V_13 . V_21 -> V_23 ;
F_6 ( V_1 -> V_12 . V_13 . V_21 ) ;
F_6 ( V_1 -> V_12 . V_13 . V_19 ) ;
F_6 ( V_1 -> V_12 . V_13 . V_17 ) ;
F_7 ( V_3 ) ;
F_7 ( V_4 ) ;
F_7 ( V_5 ) ;
}
int F_9 ( void )
{
int V_6 = - V_7 ;
V_24 = F_5 ( & V_25 , L_1 , V_26 ) ;
if ( V_24 == NULL )
goto V_10;
V_6 = F_10 ( & V_27 ) ;
if ( V_6 )
goto V_28;
V_10:
return V_6 ;
V_28:
F_6 ( V_24 ) ;
goto V_10;
}
void F_11 ( void )
{
F_6 ( V_24 ) ;
F_12 ( & V_27 ) ;
}
