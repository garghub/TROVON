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
static bool F_2 ( struct V_8 * V_9 )
{
if ( V_9 -> V_10 != V_11 )
return false ;
if ( memcmp ( V_9 -> V_12 . V_3 , L_4 , V_4 ) )
return false ;
if ( ! memcmp ( V_9 -> V_12 . V_5 , L_5 ,
V_6 ) && V_9 -> V_12 . V_7 == 0 )
return true ;
return false ;
}
int T_1 F_3 ( bool V_13 )
{
static char V_14 [ 64 ] ;
struct V_8 * V_15 ;
T_2 V_16 ;
char * V_17 ;
char * V_18 ;
int V_19 ;
int V_20 ;
if ( V_21 )
return - V_22 ;
V_16 = F_4 ( V_23 , 0 ,
(struct V_1 * * ) & V_15 ) ;
if ( F_5 ( V_16 ) )
return - V_24 ;
if ( V_15 -> V_12 . V_25 < 2 ) {
V_20 = - V_24 ;
F_6 ( L_6 ) ;
goto V_26;
}
if ( V_15 -> V_27 . V_28 == V_29 ) {
switch ( V_15 -> V_27 . V_30 ) {
default:
F_6 ( L_7 ) ;
case V_31 :
V_18 = L_8 ;
break;
case V_32 :
V_18 = L_9 ;
break;
case V_33 :
V_18 = L_10 ;
break;
}
} else
V_18 = L_11 ;
switch ( V_15 -> V_10 ) {
case V_34 :
V_18 = L_10 ;
case V_35 :
case V_36 :
case V_37 :
V_17 = L_12 ;
break;
case V_11 :
case V_38 :
V_17 = L_13 ;
break;
default:
V_20 = - V_24 ;
goto V_26;
}
switch ( V_15 -> V_19 ) {
case 3 :
V_19 = 9600 ;
break;
case 4 :
V_19 = 19200 ;
break;
case 6 :
V_19 = 57600 ;
break;
case 7 :
V_19 = 115200 ;
break;
default:
V_20 = - V_24 ;
goto V_26;
}
if ( F_1 ( & V_15 -> V_12 ) ) {
V_39 = true ;
if ( V_13 )
V_17 = L_14 ;
}
if ( F_2 ( V_15 ) )
V_18 = L_10 ;
snprintf ( V_14 , sizeof( V_14 ) , L_15 , V_17 , V_18 ,
V_15 -> V_27 . V_40 , V_19 ) ;
F_7 ( L_16 , V_14 ) ;
if ( V_13 )
F_8 ( V_14 ) ;
V_20 = F_9 ( V_17 , 0 , V_14 + strlen ( V_17 ) + 1 ) ;
V_26:
F_10 ( (struct V_1 * ) V_15 ) ;
return V_20 ;
}
