static bool F_1 ( struct V_1 * V_2 )
{
if ( memcmp ( V_2 -> V_3 , L_1 , V_4 ) )
return false ;
if ( ! memcmp ( V_2 -> V_5 , L_2 , V_6 ) )
return true ;
if ( ! memcmp ( V_2 -> V_5 , L_3 , V_6 ) &&
V_2 -> V_7 == 1 )
return true ;
return false ;
}
int T_1 F_2 ( bool V_8 )
{
static char V_9 [ 64 ] ;
struct V_10 * V_11 ;
T_2 V_12 ;
char * V_13 ;
char * V_14 ;
int V_15 ;
int V_16 ;
if ( V_17 )
return - V_18 ;
V_12 = F_3 ( V_19 , 0 ,
(struct V_1 * * ) & V_11 ) ;
if ( F_4 ( V_12 ) )
return - V_20 ;
if ( V_11 -> V_21 . V_22 < 2 ) {
V_16 = - V_20 ;
F_5 ( L_4 ) ;
goto V_23;
}
V_14 = V_11 -> V_24 . V_25 == V_26 ?
L_5 : L_6 ;
switch ( V_11 -> V_27 ) {
case V_28 :
V_14 = L_7 ;
case V_29 :
case V_30 :
case V_31 :
V_13 = L_8 ;
break;
case V_32 :
case V_33 :
V_13 = L_9 ;
break;
default:
V_16 = - V_20 ;
goto V_23;
}
switch ( V_11 -> V_15 ) {
case 3 :
V_15 = 9600 ;
break;
case 4 :
V_15 = 19200 ;
break;
case 6 :
V_15 = 57600 ;
break;
case 7 :
V_15 = 115200 ;
break;
default:
V_16 = - V_20 ;
goto V_23;
}
if ( F_1 ( & V_11 -> V_21 ) )
V_13 = L_10 ;
snprintf ( V_9 , sizeof( V_9 ) , L_11 , V_13 , V_14 ,
V_11 -> V_24 . V_34 , V_15 ) ;
F_6 ( L_12 , V_9 ) ;
if ( V_8 )
F_7 ( V_9 ) ;
V_16 = F_8 ( V_13 , 0 , V_9 + strlen ( V_13 ) + 1 ) ;
V_23:
F_9 ( (struct V_1 * ) V_11 ) ;
return V_16 ;
}
