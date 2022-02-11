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
bool V_10 = false ;
if ( V_9 -> V_11 != V_12 )
return false ;
if ( memcmp ( V_9 -> V_13 . V_3 , L_4 , V_4 ) &&
memcmp ( V_9 -> V_13 . V_3 , L_5 , V_4 ) )
return false ;
if ( ! memcmp ( V_9 -> V_13 . V_5 , L_6 ,
V_6 ) && V_9 -> V_13 . V_7 == 0 )
V_10 = true ;
if ( ! memcmp ( V_9 -> V_13 . V_5 , L_7 ,
V_6 ) && V_9 -> V_13 . V_7 == 1 )
V_10 = true ;
return V_10 ;
}
int T_1 F_3 ( bool V_14 )
{
static char V_15 [ 64 ] ;
struct V_8 * V_16 ;
T_2 V_17 ;
char * V_18 ;
char * V_19 ;
int V_20 ;
int V_21 ;
if ( V_22 )
return - V_23 ;
V_17 = F_4 ( V_24 , 0 ,
(struct V_1 * * ) & V_16 ) ;
if ( F_5 ( V_17 ) )
return - V_25 ;
if ( V_16 -> V_13 . V_26 < 2 ) {
V_21 = - V_25 ;
F_6 ( L_8 ) ;
goto V_27;
}
if ( V_16 -> V_28 . V_29 == V_30 ) {
switch ( F_7 ( (
V_16 -> V_28 . V_31 ) ) ) {
default:
F_6 ( L_9 ) ;
case 8 :
V_19 = L_10 ;
break;
case 16 :
V_19 = L_11 ;
break;
case 32 :
V_19 = L_12 ;
break;
}
} else
V_19 = L_13 ;
switch ( V_16 -> V_11 ) {
case V_32 :
V_19 = L_12 ;
case V_33 :
case V_34 :
case V_35 :
V_18 = L_14 ;
break;
case V_12 :
case V_36 :
V_18 = L_15 ;
break;
default:
V_21 = - V_25 ;
goto V_27;
}
switch ( V_16 -> V_20 ) {
case 3 :
V_20 = 9600 ;
break;
case 4 :
V_20 = 19200 ;
break;
case 6 :
V_20 = 57600 ;
break;
case 7 :
V_20 = 115200 ;
break;
default:
V_21 = - V_25 ;
goto V_27;
}
if ( F_1 ( & V_16 -> V_13 ) ) {
V_37 = true ;
if ( V_14 )
V_18 = L_16 ;
}
if ( F_2 ( V_16 ) ) {
V_19 = L_12 ;
snprintf ( V_15 , sizeof( V_15 ) , L_17 , V_18 , V_19 ,
V_16 -> V_28 . V_38 ) ;
} else {
snprintf ( V_15 , sizeof( V_15 ) , L_18 , V_18 , V_19 ,
V_16 -> V_28 . V_38 , V_20 ) ;
}
F_8 ( L_19 , V_15 ) ;
if ( V_14 )
F_9 ( V_15 ) ;
V_21 = F_10 ( V_18 , 0 , V_15 + strlen ( V_18 ) + 1 ) ;
V_27:
F_11 ( (struct V_1 * ) V_16 ) ;
return V_21 ;
}
