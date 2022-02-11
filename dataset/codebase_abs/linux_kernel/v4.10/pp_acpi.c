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
bool F_3 ( void * V_1 )
{
T_2 V_6 = 1 ;
return F_2 ( V_1 , V_7 ,
V_10 ,
& V_6 ,
NULL ,
0 ,
sizeof( V_6 ) ,
0 ) ;
}
int F_4 ( void * V_1 , T_3 V_11 , bool V_12 )
{
struct V_13 V_14 ;
struct V_15 V_16 ;
T_4 V_17 = 3 ;
int V_3 ;
struct V_18 V_19 = { 0 } ;
if ( F_3 ( V_1 ) )
return - V_20 ;
V_19 . V_21 = sizeof( struct V_18 ) ;
V_19 . V_22 = V_23 ;
V_3 = F_5 ( V_1 , & V_19 ) ;
if ( V_3 != 0 )
return - V_20 ;
V_14 . V_24 = ( V_25 ) V_19 . V_26 ;
V_14 . V_21 = sizeof( struct V_13 ) ;
V_14 . V_27 = V_28 ;
V_14 . V_29 = V_30 ;
if ( V_12 )
V_14 . V_29 |= V_31 ;
V_14 . V_32 = V_33 ;
V_14 . V_11 = V_11 ;
V_16 . V_21 = sizeof( struct V_13 ) ;
while ( V_17 -- ) {
V_3 = F_2 ( V_1 ,
V_7 ,
V_34 ,
& V_14 ,
& V_16 ,
1 ,
sizeof( V_14 ) ,
sizeof( V_16 ) ) ;
if ( V_3 != 0 )
return - V_35 ;
switch ( V_16 . V_36 ) {
case V_37 :
default:
return - V_20 ;
case V_38 :
return 0 ;
case V_39 :
F_6 ( 10 ) ;
break;
}
}
return 0 ;
}
