int T_1 F_1 ( bool V_1 )
{
static char V_2 [ 64 ] ;
struct V_3 * V_4 ;
T_2 V_5 ;
T_3 V_6 ;
char * V_7 ;
char * V_8 ;
int V_9 ;
int V_10 ;
if ( V_11 )
return - V_12 ;
V_6 = F_2 ( V_13 , 0 ,
(struct V_14 * * ) & V_4 ,
& V_5 ) ;
if ( F_3 ( V_6 ) )
return - V_15 ;
if ( V_4 -> V_16 . V_17 < 2 ) {
V_10 = - V_15 ;
F_4 ( L_1 ) ;
goto V_18;
}
V_8 = V_4 -> V_19 . V_20 == V_21 ?
L_2 : L_3 ;
switch ( V_4 -> V_22 ) {
case V_23 :
V_8 = L_4 ;
case V_24 :
case V_25 :
case V_26 :
V_7 = L_5 ;
break;
case V_27 :
case V_28 :
V_7 = L_6 ;
break;
default:
V_10 = - V_15 ;
goto V_18;
}
switch ( V_4 -> V_9 ) {
case 3 :
V_9 = 9600 ;
break;
case 4 :
V_9 = 19200 ;
break;
case 6 :
V_9 = 57600 ;
break;
case 7 :
V_9 = 115200 ;
break;
default:
V_10 = - V_15 ;
goto V_18;
}
snprintf ( V_2 , sizeof( V_2 ) , L_7 , V_7 , V_8 ,
V_4 -> V_19 . V_29 , V_9 ) ;
F_5 ( L_8 , V_2 ) ;
if ( V_1 )
F_6 ( V_2 ) ;
V_10 = F_7 ( V_7 , 0 , V_2 + strlen ( V_7 ) + 1 ) ;
V_18:
F_8 ( ( void V_30 * ) V_4 , V_5 ) ;
return V_10 ;
}
