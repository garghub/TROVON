static struct V_1 * * F_1 ( struct V_1 * * V_2 ,
struct V_1 * V_3 )
{
int V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_1 V_9 ;
T_1 V_10 ;
int V_11 ;
F_3 ( V_3 , V_4 ) ;
if ( ( V_11 = F_4 ( V_3 , V_12 , & V_10 , & V_9 ) ) != 0 )
goto V_13;
V_11 = F_5 ( V_3 ) ;
if ( V_11 )
goto V_13;
if ( V_3 -> V_14 -> V_15 == V_16 )
goto V_13;
V_8 = F_6 ( F_7 ( V_3 -> V_17 ) , V_3 -> V_18 ,
( V_19 * ) & F_8 ( V_3 ) -> V_20 ,
V_10 , V_12 , V_21 ) ;
if ( ! V_8 )
goto V_13;
V_3 -> V_14 -> V_22 [ V_3 -> V_14 -> V_15 ++ ] = V_8 ;
V_3 -> V_14 -> V_23 ++ ;
V_6 = V_5 ( V_3 ) ;
if ( ! V_6 ) {
F_9 ( V_8 ) ;
goto V_13;
}
V_6 -> V_24 |= V_25 ;
F_10 ( V_3 ) -> V_26 . V_27 = NULL ;
F_11 ( V_3 ) -> V_28 = V_21 ;
F_11 ( V_3 ) -> V_29 = F_12 ( struct V_30 , V_20 ) ;
F_11 ( V_3 ) -> V_9 = V_9 ;
F_13 ( V_3 , V_12 , V_10 , - 2 ) ;
return F_14 ( - V_31 ) ;
V_13:
F_15 ( V_3 , V_4 ) ;
F_16 ( V_3 ) -> V_32 = 0 ;
F_16 ( V_3 ) -> V_33 = 1 ;
return NULL ;
}
static int T_2 F_17 ( void )
{
return F_18 ( & V_34 , V_12 ) ;
}
static void T_3 F_19 ( void )
{
F_20 ( & V_34 , V_12 ) ;
}
