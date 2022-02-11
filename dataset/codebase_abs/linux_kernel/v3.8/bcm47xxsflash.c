static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 * V_5 , T_3 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( ( V_3 + V_4 ) > V_2 -> V_10 )
return - V_11 ;
F_2 ( V_6 , ( void V_12 * ) F_3 ( V_8 -> V_13 + V_3 ) ,
V_4 ) ;
return V_4 ;
}
static void F_4 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
V_2 -> V_9 = V_8 ;
V_2 -> V_14 = L_1 ;
V_2 -> V_15 = V_16 ;
V_2 -> type = V_17 ;
V_2 -> V_10 = V_8 -> V_10 ;
V_2 -> V_18 = F_1 ;
V_2 -> V_19 = V_20 ;
V_2 -> V_21 = V_2 -> V_22 = 1 ;
}
static int F_5 ( struct V_23 * V_24 )
{
struct V_7 * V_8 = F_6 ( & V_24 -> V_25 ) ;
int V_26 ;
V_8 -> V_2 = F_7 ( sizeof( struct V_1 ) , V_27 ) ;
if ( ! V_8 -> V_2 ) {
V_26 = - V_28 ;
goto V_29;
}
F_4 ( V_8 , V_8 -> V_2 ) ;
V_26 = F_8 ( V_8 -> V_2 , V_30 , NULL , NULL , 0 ) ;
if ( V_26 ) {
F_9 ( L_2 , V_26 ) ;
goto V_31;
}
return 0 ;
V_31:
F_10 ( V_8 -> V_2 ) ;
V_29:
return V_26 ;
}
static int F_11 ( struct V_23 * V_24 )
{
struct V_7 * V_8 = F_6 ( & V_24 -> V_25 ) ;
F_12 ( V_8 -> V_2 ) ;
F_10 ( V_8 -> V_2 ) ;
return 0 ;
}
static int T_4 F_13 ( void )
{
int V_26 ;
V_26 = F_14 ( & V_32 , F_5 ) ;
if ( V_26 )
F_9 ( L_3 ,
V_26 ) ;
return V_26 ;
}
static void T_5 F_15 ( void )
{
F_16 ( & V_32 ) ;
}
