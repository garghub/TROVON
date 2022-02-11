static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 = F_2 () ;
V_4 -> V_6 = V_5 . V_6 ;
V_4 -> V_7 = V_5 . V_7 ;
V_4 -> V_8 = V_5 . V_8 ;
V_4 -> V_9 = V_5 . V_9 ;
V_4 -> V_10 = V_5 . V_10 ;
V_4 -> V_11 = V_5 . V_11 ;
V_4 -> V_12 = 0 ;
V_4 -> V_13 = 0 ;
V_4 -> V_14 = 0 ;
if ( F_3 ( V_4 ) < 0 )
F_4 ( V_2 , L_1 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 ;
V_5 . V_6 = V_4 -> V_6 ;
V_5 . V_7 = V_4 -> V_7 ;
V_5 . V_8 = V_4 -> V_8 ;
V_5 . V_9 = V_4 -> V_9 ;
V_5 . V_10 = V_4 -> V_10 ;
V_5 . V_11 = V_4 -> V_11 ;
F_6 ( V_5 ) ;
return 0 ;
}
static int T_2 F_7 ( struct V_15 * V_2 )
{
struct V_16 * V_17 ;
V_17 = F_8 ( L_2 ,
& V_2 -> V_2 , & V_18 , V_19 ) ;
if ( F_9 ( V_17 ) )
return F_10 ( V_17 ) ;
F_11 ( V_2 , V_17 ) ;
return 0 ;
}
static int T_3 F_12 ( struct V_15 * V_2 )
{
struct V_16 * V_17 = F_13 ( V_2 ) ;
if ( V_17 )
F_14 ( V_17 ) ;
F_11 ( V_2 , NULL ) ;
return 0 ;
}
static int T_4 F_15 ( void )
{
int V_20 ;
V_20 = F_16 ( & V_21 ) ;
if ( V_20 )
return V_20 ;
V_22 = F_17 ( L_3 , 0 ) ;
if ( V_22 == NULL ) {
V_20 = - V_23 ;
goto V_24;
}
V_20 = F_18 ( V_22 ) ;
if ( V_20 )
goto V_25;
return 0 ;
V_25:
F_19 ( V_22 ) ;
V_24:
F_20 ( & V_21 ) ;
return V_20 ;
}
static void T_5 F_21 ( void )
{
F_20 ( & V_21 ) ;
}
