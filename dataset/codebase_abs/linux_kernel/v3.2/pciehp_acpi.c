int F_1 ( struct V_1 * V_2 )
{
if ( V_3 != V_4 )
return 0 ;
if ( F_2 ( F_3 ( & V_2 -> V_2 ) ) )
return 0 ;
return - V_5 ;
}
static int T_1 F_4 ( void )
{
if ( ! V_6 )
return V_7 ;
if ( ! strcmp ( V_6 , L_1 ) )
return V_8 ;
if ( ! strcmp ( V_6 , L_2 ) )
return V_4 ;
if ( ! strcmp ( V_6 , L_3 ) )
return V_9 ;
F_5 ( L_4 ,
V_6 ) ;
return V_7 ;
}
static int T_1 F_6 ( struct V_10 * V_2 )
{
int V_11 ;
T_2 V_12 ;
T_3 V_13 ;
struct V_14 * V_15 , * V_16 ;
struct V_1 * V_17 = V_2 -> V_18 ;
V_11 = F_7 ( V_17 ) ;
if ( ! V_11 )
return - V_5 ;
F_8 ( V_17 , V_11 + V_19 , & V_12 ) ;
V_15 = F_9 ( sizeof( * V_15 ) , V_20 ) ;
if ( ! V_15 )
return - V_21 ;
V_15 -> V_22 = V_12 >> 19 ;
F_10 (tmp, &dummy_slots, list) {
if ( V_16 -> V_22 == V_15 -> V_22 )
V_23 ++ ;
}
F_11 ( & V_15 -> V_24 , & V_25 ) ;
V_13 = F_3 ( & V_17 -> V_2 ) ;
if ( ! V_26 && F_2 ( V_13 ) )
V_26 = 1 ;
return - V_5 ;
}
static int T_1 F_12 ( void )
{
struct V_14 * V_15 , * V_16 ;
if ( F_13 ( & V_27 ) )
return V_4 ;
F_14 ( & V_27 ) ;
F_15 (slot, tmp, &dummy_slots, list) {
F_16 ( & V_15 -> V_24 ) ;
F_17 ( V_15 ) ;
}
if ( V_26 && V_23 )
return V_4 ;
return V_8 ;
}
void T_1 F_18 ( void )
{
V_3 = F_4 () ;
if ( V_3 != V_9 )
goto V_28;
V_3 = F_12 () ;
V_28:
if ( V_3 == V_4 )
F_19 ( L_5 ) ;
}
