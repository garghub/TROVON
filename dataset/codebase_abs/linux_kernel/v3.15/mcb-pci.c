static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_5 ;
T_1 V_6 ;
int V_7 ;
int V_8 ;
unsigned long V_9 ;
V_5 = F_2 ( & V_2 -> V_10 , sizeof( struct V_5 ) , V_11 ) ;
if ( ! V_5 )
return - V_12 ;
V_7 = F_3 ( V_2 ) ;
if ( V_7 ) {
F_4 ( & V_2 -> V_10 , L_1 ) ;
return - V_13 ;
}
V_6 = F_5 ( V_2 , 0 ) ;
if ( ! V_6 ) {
F_4 ( & V_2 -> V_10 , L_2 ) ;
goto V_14;
}
V_7 = F_6 ( V_2 , 0 , V_15 ) ;
if ( V_7 ) {
F_4 ( & V_2 -> V_10 , L_3 ) ;
goto V_14;
}
V_5 -> V_16 = F_7 ( V_2 , 0 , 0 ) ;
if ( ! V_5 -> V_16 ) {
F_4 ( & V_2 -> V_10 , L_4 ) ;
V_7 = - V_12 ;
goto V_17;
}
V_9 = F_8 ( V_2 , 0 ) ;
if ( V_9 & V_18 ) {
V_7 = - V_19 ;
F_4 ( & V_2 -> V_10 ,
L_5 ) ;
goto V_17;
}
F_9 ( V_2 , V_5 ) ;
V_5 -> V_20 = F_10 () ;
V_7 = F_11 ( V_5 -> V_20 , V_6 , V_5 -> V_16 ) ;
if ( V_7 < 0 )
goto V_21;
V_8 = V_7 ;
F_12 ( & V_2 -> V_10 , L_6 , V_8 ) ;
F_13 ( V_5 -> V_20 ) ;
V_21:
F_14 ( V_2 , V_5 -> V_16 ) ;
V_17:
F_15 ( V_2 , 0 ) ;
V_14:
F_16 ( V_2 ) ;
return V_7 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_18 ( V_2 ) ;
F_19 ( V_5 -> V_20 ) ;
}
