static const char * F_1 ( T_1 V_1 )
{
switch ( ( int ) V_1 ) {
case V_2 :
return L_1 ;
case V_3 :
return L_2 ;
case V_4 :
return L_3 ;
case V_5 :
return L_4 ;
case V_6 :
return L_5 ;
default:
return L_6 ;
}
}
int F_2 ( const char * V_7 , int V_8 )
{
T_2 V_9 = V_10 ;
T_3 V_11 = V_12 ;
T_1 V_1 ;
int V_13 = - 1 ;
T_4 V_14 [ V_15 ] ;
T_4 V_16 [ V_15 ] ;
T_5 * V_17 ;
V_17 = fopen ( V_7 , L_7 ) ;
if ( ! V_17 ) {
F_3 ( L_8 ,
V_7 , strerror ( V_18 ) ) ;
return - 1 ;
}
V_1 = F_4 ( & V_11 , V_19 , V_20 ) ;
if ( V_1 != V_21 ) {
F_3 ( L_9 ,
F_1 ( V_1 ) , V_1 ) ;
goto V_22;
}
V_11 . V_23 = NULL ;
V_11 . V_24 = 0 ;
V_11 . V_25 = V_16 ;
V_11 . V_26 = sizeof( V_16 ) ;
while ( 1 ) {
if ( V_11 . V_24 == 0 && ! feof ( V_17 ) ) {
V_11 . V_23 = V_14 ;
V_11 . V_24 = fread ( V_14 , 1 , sizeof( V_14 ) , V_17 ) ;
if ( ferror ( V_17 ) ) {
F_3 ( L_10 , strerror ( V_18 ) ) ;
goto V_22;
}
if ( feof ( V_17 ) )
V_9 = V_27 ;
}
V_1 = F_5 ( & V_11 , V_9 ) ;
if ( V_11 . V_26 == 0 || V_1 == V_28 ) {
T_6 V_29 = sizeof( V_16 ) - V_11 . V_26 ;
if ( F_6 ( V_8 , V_16 , V_29 ) != V_29 ) {
F_3 ( L_11 , strerror ( V_18 ) ) ;
goto V_22;
}
V_11 . V_25 = V_16 ;
V_11 . V_26 = sizeof( V_16 ) ;
}
if ( V_1 != V_21 ) {
if ( V_1 == V_28 )
break;
F_3 ( L_12 , F_1 ( V_1 ) ) ;
goto V_22;
}
}
V_13 = 0 ;
V_22:
fclose ( V_17 ) ;
return V_13 ;
}
