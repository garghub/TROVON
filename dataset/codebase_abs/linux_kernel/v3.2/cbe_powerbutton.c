static void F_1 ( T_1 V_1 )
{
F_2 ( V_1 . type != V_2 ) ;
F_3 ( V_3 , V_4 , 1 ) ;
F_4 ( V_3 ) ;
F_3 ( V_3 , V_4 , 0 ) ;
F_4 ( V_3 ) ;
}
static int T_2 F_5 ( void )
{
int V_5 = 0 ;
struct V_6 * V_7 ;
if ( ! F_6 ( L_1 ) ) {
F_7 ( V_8 L_2 , V_9 ) ;
V_5 = - V_10 ;
goto V_11;
}
V_7 = F_8 () ;
if ( ! V_7 ) {
V_5 = - V_12 ;
F_7 ( V_8 L_3 , V_9 ) ;
goto V_11;
}
F_9 ( V_13 , V_7 -> V_14 ) ;
F_9 ( V_4 , V_7 -> V_15 ) ;
V_7 -> V_16 = L_4 ;
V_7 -> V_17 . V_18 = V_19 ;
V_7 -> V_17 . V_20 = 0x02 ;
V_7 -> V_21 = L_5 ;
V_22 = F_10 ( L_6 , 0 , NULL , 0 ) ;
if ( F_11 ( V_22 ) ) {
V_5 = F_12 ( V_22 ) ;
goto V_23;
}
V_7 -> V_7 . V_24 = & V_22 -> V_7 ;
V_5 = F_13 ( V_7 ) ;
if ( V_5 ) {
F_7 ( V_8 L_7 , V_9 ) ;
goto V_25;
}
V_3 = V_7 ;
V_5 = F_14 ( & V_26 ) ;
if ( V_5 ) {
F_7 ( V_8 L_8 , V_9 ) ;
goto V_25;
}
goto V_11;
V_25:
F_15 ( V_22 ) ;
V_23:
F_16 ( V_7 ) ;
V_11:
return V_5 ;
}
static void T_3 F_17 ( void )
{
F_18 ( & V_26 ) ;
F_15 ( V_22 ) ;
F_16 ( V_3 ) ;
}
