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
T_4 V_13 [ V_14 ] ;
T_4 V_15 [ V_14 ] ;
T_5 * V_16 ;
V_16 = fopen ( V_7 , L_7 ) ;
if ( ! V_16 ) {
F_3 ( L_8 ,
V_7 , strerror ( V_17 ) ) ;
return - 1 ;
}
V_1 = F_4 ( & V_11 , V_18 , V_19 ) ;
if ( V_1 != V_20 ) {
F_3 ( L_9 ,
F_1 ( V_1 ) , V_1 ) ;
return - 1 ;
}
V_11 . V_21 = NULL ;
V_11 . V_22 = 0 ;
V_11 . V_23 = V_15 ;
V_11 . V_24 = sizeof( V_15 ) ;
while ( 1 ) {
if ( V_11 . V_22 == 0 && ! feof ( V_16 ) ) {
V_11 . V_21 = V_13 ;
V_11 . V_22 = fread ( V_13 , 1 , sizeof( V_13 ) , V_16 ) ;
if ( ferror ( V_16 ) ) {
F_3 ( L_10 , strerror ( V_17 ) ) ;
return - 1 ;
}
if ( feof ( V_16 ) )
V_9 = V_25 ;
}
V_1 = F_5 ( & V_11 , V_9 ) ;
if ( V_11 . V_24 == 0 || V_1 == V_26 ) {
T_6 V_27 = sizeof( V_15 ) - V_11 . V_24 ;
if ( F_6 ( V_8 , V_15 , V_27 ) != V_27 ) {
F_3 ( L_11 , strerror ( V_17 ) ) ;
return - 1 ;
}
V_11 . V_23 = V_15 ;
V_11 . V_24 = sizeof( V_15 ) ;
}
if ( V_1 != V_20 ) {
if ( V_1 == V_26 )
return 0 ;
F_3 ( L_12 , F_1 ( V_1 ) ) ;
return - 1 ;
}
}
fclose ( V_16 ) ;
return 0 ;
}
