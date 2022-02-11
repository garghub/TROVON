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
if ( ( V_1 >= 0 ) && ( V_1 < 4 ) )
return V_1 + 2 ;
else
return - 1 ;
case V_19 :
case V_20 :
case V_21 :
if ( ( V_1 >= 0 ) && ( V_1 < 4 ) )
return V_1 + 1 ;
else
return - 1 ;
case V_22 :
if ( V_1 == 2 )
return 4 ;
else
return - 1 ;
case V_23 :
if ( ( V_1 >= 16 ) && ( V_1 < 20 ) )
return V_1 - 16 + 1 ;
else
return - 1 ;
case V_24 :
return - 1 ;
case V_25 :
if ( V_1 >= 0 && V_1 <= 3 )
return V_1 ;
else if ( V_1 >= 16 && V_1 <= 19 )
return V_1 - 16 + 4 ;
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
T_1 V_26 ;
int V_27 ;
int V_28 = 0 ;
if ( V_29 )
return V_29 ( V_1 ) ;
V_26 . V_30 = 0 ;
switch ( F_2 () -> V_2 ) {
case V_3 :
V_26 . V_31 . V_32 = 1 ;
V_26 . V_31 . V_33 = 1 ;
V_26 . V_31 . V_34 = 1000 ;
return V_26 ;
case V_9 :
case V_11 :
case V_12 :
case V_13 :
if ( V_1 == 1 ) {
V_26 . V_31 . V_32 = 1 ;
V_26 . V_31 . V_33 = 1 ;
V_26 . V_31 . V_34 = 1000 ;
return V_26 ;
}
break;
case V_22 :
if ( V_1 == 1 ) {
V_26 . V_31 . V_32 = 1 ;
V_26 . V_31 . V_33 = 1 ;
V_26 . V_31 . V_34 = 1000 ;
return V_26 ;
} else
V_28 = 1 ;
break;
case V_24 :
if ( V_1 == 2 ) {
V_26 . V_30 = 0 ;
return V_26 ;
} else {
V_26 . V_31 . V_32 = 1 ;
V_26 . V_31 . V_33 = 1 ;
V_26 . V_31 . V_34 = 1000 ;
return V_26 ;
}
break;
}
V_27 = F_1 ( V_1 ) ;
if ( V_27 != - 1 ) {
if ( V_28 ) {
int V_35 =
F_5 ( V_27 >> 8 , V_27 & 0xff ,
0x19 ) ;
switch ( ( V_35 >> 8 ) & 0x7 ) {
case 0 :
V_26 . V_30 = 0 ;
break;
case 1 :
V_26 . V_31 . V_32 = 1 ;
V_26 . V_31 . V_33 = 0 ;
V_26 . V_31 . V_34 = 10 ;
break;
case 2 :
V_26 . V_31 . V_32 = 1 ;
V_26 . V_31 . V_33 = 1 ;
V_26 . V_31 . V_34 = 10 ;
break;
case 3 :
V_26 . V_31 . V_32 = 1 ;
V_26 . V_31 . V_33 = 0 ;
V_26 . V_31 . V_34 = 100 ;
break;
case 4 :
V_26 . V_31 . V_32 = 1 ;
V_26 . V_31 . V_33 = 1 ;
V_26 . V_31 . V_34 = 100 ;
break;
case 5 :
V_26 . V_31 . V_32 = 1 ;
V_26 . V_31 . V_33 = 1 ;
V_26 . V_31 . V_34 = 100 ;
break;
case 6 :
V_26 . V_31 . V_32 = 1 ;
V_26 . V_31 . V_33 = 0 ;
V_26 . V_31 . V_34 = 1000 ;
break;
case 7 :
V_26 . V_31 . V_32 = 1 ;
V_26 . V_31 . V_33 = 1 ;
V_26 . V_31 . V_34 = 1000 ;
break;
}
} else {
int V_35 =
F_5 ( V_27 >> 8 , V_27 & 0xff , 17 ) ;
if ( ( V_35 & ( 1 << 11 ) ) == 0 ) {
int V_36 =
F_5 ( V_27 >> 8 ,
V_27 & 0xff , 0 ) ;
if ( ( V_36 & ( 1 << 12 ) ) == 0 )
V_35 |= 1 << 11 ;
}
if ( V_35 & ( 1 << 11 ) ) {
V_26 . V_31 . V_32 = 1 ;
V_26 . V_31 . V_33 = ( ( V_35 >> 13 ) & 1 ) ;
switch ( ( V_35 >> 14 ) & 3 ) {
case 0 :
V_26 . V_31 . V_34 = 10 ;
break;
case 1 :
V_26 . V_31 . V_34 = 100 ;
break;
case 2 :
V_26 . V_31 . V_34 = 1000 ;
break;
case 3 :
V_26 . V_30 = 0 ;
break;
}
}
}
} else if ( F_6 ( V_37 )
|| F_6 ( V_38 )
|| F_6 ( V_39 ) ) {
union V_40 V_41 ;
int V_42 = F_7 ( V_1 ) ;
int V_43 = F_8 ( V_1 ) ;
V_41 . V_30 =
F_9 ( F_10 ( V_43 , V_42 ) ) ;
V_26 . V_31 . V_32 = V_41 . V_31 . V_44 ;
V_26 . V_31 . V_33 = V_41 . V_31 . V_45 ;
switch ( V_41 . V_31 . V_34 ) {
case 0 :
V_26 . V_31 . V_34 = 10 ;
break;
case 1 :
V_26 . V_31 . V_34 = 100 ;
break;
case 2 :
V_26 . V_31 . V_34 = 1000 ;
break;
case 3 :
V_26 . V_30 = 0 ;
break;
}
} else {
V_26 . V_30 = 0 ;
}
if ( ! V_26 . V_31 . V_32 )
V_26 . V_30 = 0 ;
return V_26 ;
}
int F_11 ( int V_27 ,
T_2
V_46 ,
T_1 V_47 )
{
if ( ( V_46 & V_48 ) !=
V_49 ) {
T_3 V_50 ;
V_50 . V_51 =
F_5 ( V_27 >> 8 , V_27 & 0xff ,
V_52 ) ;
V_50 . V_31 . V_53 =
( V_46 & V_48 ) ==
V_54 ;
V_50 . V_31 . V_55 =
( V_46 & V_48 ) ==
V_54 ;
F_12 ( V_27 >> 8 , V_27 & 0xff ,
V_52 ,
V_50 . V_51 ) ;
}
if ( ( V_46 & V_56 )
&& ( V_47 . V_31 . V_34 == 0 ) ) {
T_4 V_57 ;
T_5 V_58 ;
T_3 V_50 ;
T_6 V_59 ;
T_7 V_60 ;
V_58 . V_51 =
F_5 ( V_27 >> 8 , V_27 & 0xff ,
V_61 ) ;
V_50 . V_51 =
F_5 ( V_27 >> 8 , V_27 & 0xff ,
V_52 ) ;
V_50 . V_31 . V_62 =
V_58 . V_31 . V_63 ;
V_50 . V_31 . V_64 =
V_58 . V_31 . V_65 ;
V_50 . V_31 . V_66 =
V_58 . V_31 . V_67 ;
V_50 . V_31 . V_68 =
V_58 . V_31 . V_69 ;
V_50 . V_31 . V_70 =
V_58 . V_31 . V_71 ;
F_12 ( V_27 >> 8 , V_27 & 0xff ,
V_52 ,
V_50 . V_51 ) ;
if ( V_58 . V_31 . V_72 ) {
V_59 . V_51 =
F_5 ( V_27 >> 8 , V_27 & 0xff ,
V_73 ) ;
V_60 . V_51 =
F_5 ( V_27 >> 8 , V_27 & 0xff ,
V_74 ) ;
V_60 . V_31 . V_75 =
V_59 . V_31 . V_76 ;
V_60 . V_31 . V_77 =
V_59 . V_31 . V_78 ;
F_12 ( V_27 >> 8 , V_27 & 0xff ,
V_74 ,
V_60 . V_51 ) ;
}
V_57 . V_51 =
F_5 ( V_27 >> 8 , V_27 & 0xff ,
V_79 ) ;
V_57 . V_31 . V_80 = 1 ;
V_57 . V_31 . V_81 = 1 ;
F_12 ( V_27 >> 8 , V_27 & 0xff ,
V_79 , V_57 . V_51 ) ;
} else if ( ( V_46 & V_56 ) ) {
T_4 V_57 ;
T_5 V_58 ;
T_3 V_50 ;
T_6 V_59 ;
T_7 V_60 ;
V_58 . V_51 =
F_5 ( V_27 >> 8 , V_27 & 0xff ,
V_61 ) ;
V_50 . V_51 =
F_5 ( V_27 >> 8 , V_27 & 0xff ,
V_52 ) ;
V_50 . V_31 . V_62 = 0 ;
V_50 . V_31 . V_64 = 0 ;
V_50 . V_31 . V_66 = 0 ;
V_50 . V_31 . V_68 = 0 ;
V_50 . V_31 . V_70 = 0 ;
if ( V_58 . V_31 . V_72 ) {
V_59 . V_51 =
F_5 ( V_27 >> 8 , V_27 & 0xff ,
V_73 ) ;
V_60 . V_51 =
F_5 ( V_27 >> 8 , V_27 & 0xff ,
V_74 ) ;
V_60 . V_31 . V_75 = 0 ;
V_60 . V_31 . V_77 = 0 ;
}
switch ( V_47 . V_31 . V_34 ) {
case 10 :
V_50 . V_31 . V_64 =
V_47 . V_31 . V_33 ;
V_50 . V_31 . V_66 =
! V_47 . V_31 . V_33 ;
break;
case 100 :
V_50 . V_31 . V_68 =
V_47 . V_31 . V_33 ;
V_50 . V_31 . V_70 =
! V_47 . V_31 . V_33 ;
break;
case 1000 :
V_60 . V_31 . V_75 =
V_47 . V_31 . V_33 ;
V_60 . V_31 . V_77 =
! V_47 . V_31 . V_33 ;
break;
}
F_12 ( V_27 >> 8 , V_27 & 0xff ,
V_52 ,
V_50 . V_51 ) ;
if ( V_58 . V_31 . V_72 )
F_12 ( V_27 >> 8 , V_27 & 0xff ,
V_74 ,
V_60 . V_51 ) ;
V_57 . V_51 =
F_5 ( V_27 >> 8 , V_27 & 0xff ,
V_79 ) ;
V_57 . V_31 . V_80 = 1 ;
V_57 . V_31 . V_81 = 1 ;
F_12 ( V_27 >> 8 , V_27 & 0xff ,
V_79 , V_57 . V_51 ) ;
} else {
T_4 V_57 ;
V_57 . V_51 =
F_5 ( V_27 >> 8 , V_27 & 0xff ,
V_79 ) ;
V_57 . V_31 . V_80 = 0 ;
V_57 . V_31 . V_81 = 1 ;
V_57 . V_31 . V_45 = V_47 . V_31 . V_33 ;
if ( V_47 . V_31 . V_34 == 1000 ) {
V_57 . V_31 . V_82 = 1 ;
V_57 . V_31 . V_83 = 0 ;
} else if ( V_47 . V_31 . V_34 == 100 ) {
V_57 . V_31 . V_82 = 0 ;
V_57 . V_31 . V_83 = 1 ;
} else if ( V_47 . V_31 . V_34 == 10 ) {
V_57 . V_31 . V_82 = 0 ;
V_57 . V_31 . V_83 = 0 ;
}
F_12 ( V_27 >> 8 , V_27 & 0xff ,
V_79 , V_57 . V_51 ) ;
}
return 0 ;
}
int F_13 ( int V_42 , int V_84 )
{
switch ( F_2 () -> V_2 ) {
case V_12 :
if ( V_42 == 0 )
return 2 ;
break;
case V_24 :
if ( V_42 == 0 )
return 2 ;
break;
case V_23 :
if ( V_42 == 0 )
return 0 ;
break;
case V_19 :
if ( V_42 == 1 )
return 0 ;
break;
}
return V_84 ;
}
int F_14 ( int V_42 )
{
if ( F_2 () -> V_2 == V_12 ) {
if ( V_42 == 0 ) {
F_15 ( F_16 ( 1 , V_42 ) , 0 ) ;
F_15 ( F_17 ( 1 , V_42 ) , 0 ) ;
F_15 ( F_16 ( 0 , V_42 ) ,
0xc ) ;
F_15 ( F_17 ( 0 , V_42 ) ,
0xc ) ;
}
} else if ( F_2 () -> V_2 ==
V_11 ) {
if ( V_42 == 0 ) {
int V_27 = F_1 ( 0 ) ;
if ( V_27 != - 1 ) {
int V_85 =
F_5 ( V_27 >> 8 ,
V_27 & 0xff , 0x2 ) ;
if ( V_85 == 0x0143 ) {
F_3 ( L_2 ) ;
F_3 ( L_3 ) ;
F_3
( L_4 ) ;
F_3
( L_5 ) ;
F_3
( L_6 ) ;
F_3 ( L_3 ) ;
F_3 ( L_2 ) ;
F_18 ( 1000000000 ) ;
F_15 ( F_17
( 0 , V_42 ) , 5 ) ;
F_15 ( F_16
( 0 , V_42 ) , 5 ) ;
}
}
}
}
return 0 ;
}
