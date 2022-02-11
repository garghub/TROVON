void * T_1 F_1 ( unsigned long V_1 )
{
void T_1 * V_2 ;
switch ( V_1 ) {
case V_3 ... V_4 :
V_2 = ( void * ) F_2 ( V_1 ) ;
break;
case V_5 ... V_6 :
V_2 = ( void * ) F_3 ( V_1 ) ;
break;
default:
F_4 () ;
}
return V_2 ;
}
static void T_1 * F_5 ( unsigned long V_7 ,
T_2 V_8 , unsigned int V_9 , void * V_10 )
{
void T_1 * V_11 ;
switch ( V_7 ) {
case V_12 ... V_13 :
if ( F_6 ( ! V_14 ) )
V_11 = NULL ;
else
V_11 = ( void * ) ( V_14 +
( V_7 - V_12 ) ) ;
break;
case V_15 ... V_16 :
if ( F_6 ( ! V_17 ) )
V_11 = NULL ;
else
V_11 = ( void * ) ( V_17 +
( V_7 - V_15 ) ) ;
break;
case V_18 ... V_19 :
V_11 = F_7 ( V_20 +
( V_7 - V_18 ) ,
V_8 , V_9 , F_8 ( 0 ) ) ;
break;
case V_3 ... V_4 :
V_11 = ( void * ) F_2 ( V_7 ) ;
break;
case V_5 ... V_6 :
V_11 = ( void * ) F_3 ( V_7 ) ;
break;
case V_21 ... V_22 :
V_11 = ( void * ) F_9 ( V_7 ) ;
break;
default:
V_11 = F_7 ( V_7 , V_8 , V_9 ,
V_10 ) ;
}
return V_11 ;
}
static void F_10 ( volatile void T_1 * V_23 )
{
if ( V_17 )
if ( V_23 >= ( void T_1 * ) V_17 &&
V_23 < ( void T_1 * ) ( V_17 +
V_24 ) )
goto V_25;
if ( V_14 )
if ( V_23 >= ( void T_1 * ) V_14 &&
V_23 < ( void T_1 * ) ( V_14 +
V_26 ) )
goto V_25;
switch ( ( V_27 ) V_23 ) {
case V_28 ... V_29 :
case V_30 ... V_31 :
case V_32 ... V_33 :
goto V_25;
}
F_11 ( V_23 ) ;
V_25:
return;
}
void T_3 F_12 ( void )
{
V_34 = F_5 ;
V_35 = F_10 ;
}
