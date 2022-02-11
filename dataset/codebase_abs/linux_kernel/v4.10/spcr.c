int T_1 F_1 ( bool V_1 )
{
static char V_2 [ 64 ] ;
struct V_3 * V_4 ;
T_2 V_5 ;
char * V_6 ;
char * V_7 ;
int V_8 ;
int V_9 ;
if ( V_10 )
return - V_11 ;
V_5 = F_2 ( V_12 , 0 ,
(struct V_13 * * ) & V_4 ) ;
if ( F_3 ( V_5 ) )
return - V_14 ;
if ( V_4 -> V_15 . V_16 < 2 ) {
V_9 = - V_14 ;
F_4 ( L_1 ) ;
goto V_17;
}
V_7 = V_4 -> V_18 . V_19 == V_20 ?
L_2 : L_3 ;
switch ( V_4 -> V_21 ) {
case V_22 :
V_7 = L_4 ;
case V_23 :
case V_24 :
case V_25 :
V_6 = L_5 ;
break;
case V_26 :
case V_27 :
V_6 = L_6 ;
break;
default:
V_9 = - V_14 ;
goto V_17;
}
switch ( V_4 -> V_8 ) {
case 3 :
V_8 = 9600 ;
break;
case 4 :
V_8 = 19200 ;
break;
case 6 :
V_8 = 57600 ;
break;
case 7 :
V_8 = 115200 ;
break;
default:
V_9 = - V_14 ;
goto V_17;
}
snprintf ( V_2 , sizeof( V_2 ) , L_7 , V_6 , V_7 ,
V_4 -> V_18 . V_28 , V_8 ) ;
F_5 ( L_8 , V_2 ) ;
if ( V_1 )
F_6 ( V_2 ) ;
V_9 = F_7 ( V_6 , 0 , V_2 + strlen ( V_6 ) + 1 ) ;
V_17:
F_8 ( (struct V_13 * ) V_4 ) ;
return V_9 ;
}
