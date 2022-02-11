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
void * T_1 F_5 ( unsigned long V_7 , T_2 V_8 ,
unsigned int V_9 )
{
void T_1 * V_10 ;
switch ( V_7 ) {
case V_11 ... V_12 :
if ( F_6 ( ! V_13 ) )
V_10 = NULL ;
else
V_10 = ( void * ) ( V_13 +
( V_7 - V_11 ) ) ;
break;
case V_14 ... V_15 :
if ( F_6 ( ! V_16 ) )
V_10 = NULL ;
else
V_10 = ( void * ) ( V_16 +
( V_7 - V_14 ) ) ;
break;
case V_17 ... V_18 :
V_10 = F_7 ( V_19 +
( V_7 - V_17 ) ,
V_8 , V_9 , F_8 ( 0 ) ) ;
break;
case V_3 ... V_4 :
V_10 = ( void * ) F_2 ( V_7 ) ;
break;
case V_5 ... V_6 :
V_10 = ( void * ) F_3 ( V_7 ) ;
break;
case V_20 ... V_21 :
V_10 = ( void * ) F_9 ( V_7 ) ;
break;
default:
V_10 = F_7 ( V_7 , V_8 , V_9 ,
F_8 ( 0 ) ) ;
}
return V_10 ;
}
void F_10 ( void T_1 * V_22 )
{
extern void V_23 ( volatile void T_1 * V_22 ) ;
if ( V_16 )
if ( V_22 >= ( void T_1 * ) V_16 &&
V_22 < ( void T_1 * ) ( V_16 +
V_24 ) )
goto V_25;
if ( V_13 )
if ( V_22 >= ( void T_1 * ) V_13 &&
V_22 < ( void T_1 * ) ( V_13 +
V_26 ) )
goto V_25;
switch ( ( V_27 ) V_22 ) {
case V_28 ... V_29 :
case V_30 ... V_31 :
case V_32 ... V_33 :
goto V_25;
}
V_23 ( V_22 ) ;
V_25:
return;
}
