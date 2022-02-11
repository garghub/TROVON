int F_1 ( int V_1 )
{
switch ( F_2 () -> V_2 ) {
case V_3 :
return - 1 ;
case V_4 :
case V_5 :
case V_6 :
case V_7 :
if ( ( V_1 >= 16 ) && ( V_1 < 20 ) )
return V_1 - 16 ;
else
return - 1 ;
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
if ( V_1 == 0 )
return 4 ;
else if ( V_1 == 1 )
return 9 ;
else
return - 1 ;
case V_14 :
if ( ( V_1 >= 0 ) && ( V_1 < 4 ) )
return V_1 ;
else if ( ( V_1 >= 16 ) && ( V_1 < 20 ) )
return V_1 - 16 + 4 ;
else
return - 1 ;
case V_15 :
return - 1 ;
case V_16 :
case V_17 :
case V_18 :
if ( ( V_1 >= V_19 ) &&
( V_1 < ( V_19 + 2 ) ) )
return V_1 - V_19 ;
if ( ( V_1 >= 0 ) && ( V_1 < 4 ) )
return V_1 + 2 ;
else
return - 1 ;
case V_20 :
case V_21 :
case V_22 :
if ( V_1 == V_19 )
return 0 ;
if ( ( V_1 >= 0 ) && ( V_1 < 4 ) )
return V_1 + 1 ;
else
return - 1 ;
case V_23 :
if ( V_1 == 2 )
return 4 ;
else
return - 1 ;
case V_24 :
if ( ( V_1 >= 16 ) && ( V_1 < 20 ) )
return V_1 - 16 + 1 ;
else
return - 1 ;
case V_25 :
case V_26 :
return - 1 ;
case V_27 :
if ( V_1 >= 0 && V_1 <= 3 )
return ( V_1 + 0x1f ) & 0x1f ;
else
return - 1 ;
case V_28 :
if ( V_1 >= 0 && V_1 <= 1 )
return V_1 + 1 ;
else
return - 1 ;
case V_29 :
return - 1 ;
case V_30 :
if ( V_1 >= 0 && V_1 <= 3 )
return V_1 ;
else if ( V_1 >= 16 && V_1 <= 19 )
return V_1 - 16 + 4 ;
else
return - 1 ;
case V_31 :
if ( V_1 >= 0 && V_1 <= 2 )
return 7 - V_1 ;
else
return - 1 ;
case V_32 :
if ( V_1 == V_19 )
return 1 ;
else
return - 1 ;
}
F_3
( L_1 ,
F_2 () -> V_2 ) ;
return - 1 ;
}
T_1 F_4 ( int V_1 )
{
T_1 V_33 ;
V_33 . V_34 = 0 ;
switch ( F_2 () -> V_2 ) {
case V_3 :
V_33 . V_35 . V_36 = 1 ;
V_33 . V_35 . V_37 = 1 ;
V_33 . V_35 . V_38 = 1000 ;
return V_33 ;
case V_9 :
case V_11 :
case V_12 :
case V_13 :
if ( V_1 == 1 ) {
V_33 . V_35 . V_36 = 1 ;
V_33 . V_35 . V_37 = 1 ;
V_33 . V_35 . V_38 = 1000 ;
return V_33 ;
}
break;
case V_23 :
if ( V_1 == 1 ) {
V_33 . V_35 . V_36 = 1 ;
V_33 . V_35 . V_37 = 1 ;
V_33 . V_35 . V_38 = 1000 ;
return V_33 ;
}
break;
case V_29 :
if ( V_1 == 2 ) {
V_33 . V_34 = 0 ;
return V_33 ;
} else {
V_33 . V_35 . V_36 = 1 ;
V_33 . V_35 . V_37 = 1 ;
V_33 . V_35 . V_38 = 1000 ;
return V_33 ;
}
break;
}
if ( F_5 ( V_39 )
|| F_5 ( V_40 )
|| F_5 ( V_41 ) ) {
union V_42 V_43 ;
int V_44 = F_6 ( V_1 ) ;
int V_45 = F_7 ( V_1 ) ;
V_43 . V_34 =
F_8 ( F_9 ( V_45 , V_44 ) ) ;
V_33 . V_35 . V_36 = V_43 . V_35 . V_46 ;
V_33 . V_35 . V_37 = V_43 . V_35 . V_47 ;
switch ( V_43 . V_35 . V_38 ) {
case 0 :
V_33 . V_35 . V_38 = 10 ;
break;
case 1 :
V_33 . V_35 . V_38 = 100 ;
break;
case 2 :
V_33 . V_35 . V_38 = 1000 ;
break;
case 3 :
V_33 . V_34 = 0 ;
break;
}
} else {
V_33 . V_34 = 0 ;
}
if ( ! V_33 . V_35 . V_36 )
V_33 . V_34 = 0 ;
return V_33 ;
}
int F_10 ( int V_44 , int V_48 )
{
switch ( F_2 () -> V_2 ) {
case V_12 :
if ( V_44 == 0 )
return 2 ;
break;
case V_29 :
if ( V_44 == 0 )
return 2 ;
break;
case V_24 :
if ( V_44 == 0 )
return 0 ;
break;
case V_20 :
if ( V_44 == 1 )
return 0 ;
break;
}
return V_48 ;
}
int F_11 ( int V_44 )
{
if ( F_2 () -> V_2 == V_12 ) {
if ( V_44 == 0 ) {
F_12 ( F_13 ( 1 , V_44 ) , 0 ) ;
F_12 ( F_14 ( 1 , V_44 ) , 0 ) ;
F_12 ( F_13 ( 0 , V_44 ) ,
0xc ) ;
F_12 ( F_14 ( 0 , V_44 ) ,
0xc ) ;
}
} else if ( F_2 () -> V_2 ==
V_31 ) {
F_12 ( F_14 ( 0 , V_44 ) , 0 ) ;
F_12 ( F_13 ( 0 , V_44 ) , 0x10 ) ;
F_12 ( F_14 ( 1 , V_44 ) , 0 ) ;
F_12 ( F_13 ( 1 , V_44 ) , 0x10 ) ;
F_12 ( F_14 ( 2 , V_44 ) , 0 ) ;
F_12 ( F_13 ( 2 , V_44 ) , 0x10 ) ;
}
return 0 ;
}
enum V_49 F_15 ( void )
{
switch ( F_2 () -> V_2 ) {
case V_29 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_31 :
return V_54 ;
case V_26 :
return V_55 ;
default:
break;
}
if ( F_16 () )
return V_54 ;
return V_56 ;
}
