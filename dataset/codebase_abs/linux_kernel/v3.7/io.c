static void T_1 * F_1 ( unsigned long V_1 ,
T_2 V_2 , unsigned int V_3 , void * V_4 )
{
void T_1 * V_5 ;
switch ( V_1 ) {
case V_6 ... V_7 :
if ( F_2 ( ! V_8 ) )
V_5 = NULL ;
else
V_5 = ( V_8 +
( V_1 - V_6 ) ) ;
break;
case V_9 ... V_10 :
if ( F_2 ( ! V_11 ) )
V_5 = NULL ;
else
V_5 = ( V_11 +
( V_1 - V_9 ) ) ;
break;
case V_12 ... V_13 :
V_5 = F_3 ( V_14 +
( V_1 - V_12 ) ,
V_2 , V_3 , F_4 ( 0 ) ) ;
break;
case V_15 ... V_16 :
V_5 = F_5 ( V_1 ) ;
break;
default:
V_5 = F_3 ( V_1 , V_2 , V_3 ,
V_4 ) ;
}
return V_5 ;
}
static void F_6 ( volatile void T_1 * V_17 )
{
if ( V_11 )
if ( V_17 >= ( void T_1 * ) V_11 &&
V_17 < ( void T_1 * ) ( V_11 +
V_18 ) )
goto V_19;
if ( V_8 )
if ( V_17 >= ( void T_1 * ) V_8 &&
V_17 < ( void T_1 * ) ( V_8 +
V_20 ) )
goto V_19;
switch ( ( V_21 ) V_17 ) {
case ( V_21 ) V_22 ... ( V_21 ) V_23 :
goto V_19;
}
F_7 ( V_17 ) ;
V_19:
return;
}
void T_3 F_8 ( void )
{
V_24 = F_1 ;
V_25 = F_6 ;
}
