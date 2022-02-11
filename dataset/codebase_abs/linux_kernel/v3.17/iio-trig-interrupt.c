static T_1 F_1 ( int V_1 , void * V_2 )
{
F_2 ( V_2 ) ;
return V_3 ;
}
static int F_3 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
unsigned long V_10 ;
struct V_11 * V_12 ;
int V_1 , V_13 = 0 ;
V_12 = F_4 ( V_5 , V_14 , 0 ) ;
if ( V_12 == NULL )
return - V_15 ;
V_10 = ( V_12 -> V_16 & V_17 ) | V_18 ;
V_1 = V_12 -> V_19 ;
V_9 = F_5 ( L_1 , V_1 ) ;
if ( ! V_9 ) {
V_13 = - V_20 ;
goto V_21;
}
V_7 = F_6 ( sizeof( * V_7 ) , V_22 ) ;
if ( ! V_7 ) {
V_13 = - V_20 ;
goto V_23;
}
F_7 ( V_9 , V_7 ) ;
V_7 -> V_1 = V_1 ;
V_9 -> V_24 = & V_25 ;
V_13 = F_8 ( V_1 , F_1 ,
V_10 , V_9 -> V_26 , V_9 ) ;
if ( V_13 ) {
F_9 ( & V_5 -> V_27 ,
L_2 , V_1 ) ;
goto V_28;
}
V_13 = F_10 ( V_9 ) ;
if ( V_13 )
goto V_29;
F_11 ( V_5 , V_9 ) ;
return 0 ;
V_29:
F_12 ( V_1 , V_9 ) ;
V_28:
F_13 ( V_7 ) ;
V_23:
F_14 ( V_9 ) ;
V_21:
return V_13 ;
}
static int F_15 ( struct V_4 * V_5 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
V_9 = F_16 ( V_5 ) ;
V_7 = F_17 ( V_9 ) ;
F_18 ( V_9 ) ;
F_12 ( V_7 -> V_1 , V_9 ) ;
F_13 ( V_7 ) ;
F_14 ( V_9 ) ;
return 0 ;
}
