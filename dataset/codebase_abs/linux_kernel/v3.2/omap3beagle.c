static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
unsigned int V_11 ;
int V_12 ;
switch ( F_2 ( V_4 ) ) {
case 2 :
V_11 = V_13 |
V_14 |
V_15 ;
break;
case 4 :
V_11 = V_16 |
V_17 |
V_15 ;
break;
default:
return - V_18 ;
}
V_12 = F_3 ( V_9 , V_11 ) ;
if ( V_12 < 0 ) {
F_4 ( V_19 L_1 ) ;
return V_12 ;
}
V_12 = F_3 ( V_10 , V_11 ) ;
if ( V_12 < 0 ) {
F_4 ( V_19 L_2 ) ;
return V_12 ;
}
V_12 = F_5 ( V_9 , 0 , 26000000 ,
V_20 ) ;
if ( V_12 < 0 ) {
F_4 ( V_19 L_3 ) ;
return V_12 ;
}
return 0 ;
}
static int T_1 F_6 ( void )
{
int V_12 ;
if ( ! ( F_7 () || F_8 () ) )
return - V_21 ;
F_9 ( L_4 ) ;
V_22 = F_10 ( L_5 , - 1 ) ;
if ( ! V_22 ) {
F_4 ( V_19 L_6 ) ;
return - V_23 ;
}
F_11 ( V_22 , & V_24 ) ;
V_12 = F_12 ( V_22 ) ;
if ( V_12 )
goto V_25;
return 0 ;
V_25:
F_4 ( V_19 L_7 ) ;
F_13 ( V_22 ) ;
return V_12 ;
}
static void T_2 F_14 ( void )
{
F_15 ( V_22 ) ;
}
