bool F_1 ( void * V_1 , T_1 V_2 )
{
T_2 V_3 ;
struct V_4 V_5 = { 0 } ;
T_2 V_6 = 1 ;
V_3 = F_2 ( V_1 , V_7 ,
V_8 ,
& V_6 ,
& V_5 ,
1 ,
sizeof( V_6 ) ,
sizeof( V_5 ) ) ;
return V_3 == 0 ? ( V_5 . V_9 & ( 1 << ( V_2 - 1 ) ) ) != 0 : false ;
}
int F_3 ( void * V_1 , T_3 V_10 , bool V_11 )
{
struct V_12 V_13 ;
struct V_14 V_15 ;
T_4 V_16 = 3 ;
int V_3 ;
struct V_17 V_18 = { 0 } ;
if ( ! F_1 ( V_1 , V_19 ) )
return - V_20 ;
V_18 . V_21 = sizeof( struct V_17 ) ;
V_18 . V_22 = V_23 ;
V_3 = F_4 ( V_1 , & V_18 ) ;
if ( V_3 != 0 )
return - V_20 ;
V_13 . V_24 = ( V_25 ) V_18 . V_26 ;
V_13 . V_21 = sizeof( struct V_12 ) ;
V_13 . V_27 = V_28 ;
V_13 . V_29 = V_30 ;
if ( V_11 )
V_13 . V_29 |= V_31 ;
V_13 . V_32 = V_33 ;
V_13 . V_10 = V_10 ;
V_15 . V_21 = sizeof( struct V_12 ) ;
while ( V_16 -- ) {
V_3 = F_2 ( V_1 ,
V_7 ,
V_19 ,
& V_13 ,
& V_15 ,
0 ,
sizeof( V_13 ) ,
sizeof( V_15 ) ) ;
if ( V_3 != 0 )
return - V_34 ;
switch ( V_15 . V_35 ) {
case V_36 :
default:
return - V_20 ;
case V_37 :
return 0 ;
case V_38 :
F_5 ( 10 ) ;
break;
}
}
return 0 ;
}
