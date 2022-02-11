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
}
F_3
( L_1 ,
F_2 () -> V_2 ) ;
return - 1 ;
}
T_1 F_4 ( int V_1 )
{
T_1 V_31 ;
int V_32 ;
int V_33 = 0 ;
if ( V_34 )
return V_34 ( V_1 ) ;
V_31 . V_35 = 0 ;
switch ( F_2 () -> V_2 ) {
case V_3 :
V_31 . V_36 . V_37 = 1 ;
V_31 . V_36 . V_38 = 1 ;
V_31 . V_36 . V_39 = 1000 ;
return V_31 ;
case V_9 :
case V_11 :
case V_12 :
case V_13 :
if ( V_1 == 1 ) {
V_31 . V_36 . V_37 = 1 ;
V_31 . V_36 . V_38 = 1 ;
V_31 . V_36 . V_39 = 1000 ;
return V_31 ;
}
break;
case V_23 :
if ( V_1 == 1 ) {
V_31 . V_36 . V_37 = 1 ;
V_31 . V_36 . V_38 = 1 ;
V_31 . V_36 . V_39 = 1000 ;
return V_31 ;
} else
V_33 = 1 ;
break;
case V_29 :
if ( V_1 == 2 ) {
V_31 . V_35 = 0 ;
return V_31 ;
} else {
V_31 . V_36 . V_37 = 1 ;
V_31 . V_36 . V_38 = 1 ;
V_31 . V_36 . V_39 = 1000 ;
return V_31 ;
}
break;
}
V_32 = F_1 ( V_1 ) ;
if ( V_32 != - 1 ) {
if ( V_33 ) {
int V_40 =
F_5 ( V_32 >> 8 , V_32 & 0xff ,
0x19 ) ;
switch ( ( V_40 >> 8 ) & 0x7 ) {
case 0 :
V_31 . V_35 = 0 ;
break;
case 1 :
V_31 . V_36 . V_37 = 1 ;
V_31 . V_36 . V_38 = 0 ;
V_31 . V_36 . V_39 = 10 ;
break;
case 2 :
V_31 . V_36 . V_37 = 1 ;
V_31 . V_36 . V_38 = 1 ;
V_31 . V_36 . V_39 = 10 ;
break;
case 3 :
V_31 . V_36 . V_37 = 1 ;
V_31 . V_36 . V_38 = 0 ;
V_31 . V_36 . V_39 = 100 ;
break;
case 4 :
V_31 . V_36 . V_37 = 1 ;
V_31 . V_36 . V_38 = 1 ;
V_31 . V_36 . V_39 = 100 ;
break;
case 5 :
V_31 . V_36 . V_37 = 1 ;
V_31 . V_36 . V_38 = 1 ;
V_31 . V_36 . V_39 = 100 ;
break;
case 6 :
V_31 . V_36 . V_37 = 1 ;
V_31 . V_36 . V_38 = 0 ;
V_31 . V_36 . V_39 = 1000 ;
break;
case 7 :
V_31 . V_36 . V_37 = 1 ;
V_31 . V_36 . V_38 = 1 ;
V_31 . V_36 . V_39 = 1000 ;
break;
}
} else {
int V_40 =
F_5 ( V_32 >> 8 , V_32 & 0xff , 17 ) ;
if ( ( V_40 & ( 1 << 11 ) ) == 0 ) {
int V_41 =
F_5 ( V_32 >> 8 ,
V_32 & 0xff , 0 ) ;
if ( ( V_41 & ( 1 << 12 ) ) == 0 )
V_40 |= 1 << 11 ;
}
if ( V_40 & ( 1 << 11 ) ) {
V_31 . V_36 . V_37 = 1 ;
V_31 . V_36 . V_38 = ( ( V_40 >> 13 ) & 1 ) ;
switch ( ( V_40 >> 14 ) & 3 ) {
case 0 :
V_31 . V_36 . V_39 = 10 ;
break;
case 1 :
V_31 . V_36 . V_39 = 100 ;
break;
case 2 :
V_31 . V_36 . V_39 = 1000 ;
break;
case 3 :
V_31 . V_35 = 0 ;
break;
}
}
}
} else if ( F_6 ( V_42 )
|| F_6 ( V_43 )
|| F_6 ( V_44 ) ) {
union V_45 V_46 ;
int V_47 = F_7 ( V_1 ) ;
int V_48 = F_8 ( V_1 ) ;
V_46 . V_35 =
F_9 ( F_10 ( V_48 , V_47 ) ) ;
V_31 . V_36 . V_37 = V_46 . V_36 . V_49 ;
V_31 . V_36 . V_38 = V_46 . V_36 . V_50 ;
switch ( V_46 . V_36 . V_39 ) {
case 0 :
V_31 . V_36 . V_39 = 10 ;
break;
case 1 :
V_31 . V_36 . V_39 = 100 ;
break;
case 2 :
V_31 . V_36 . V_39 = 1000 ;
break;
case 3 :
V_31 . V_35 = 0 ;
break;
}
} else {
V_31 . V_35 = 0 ;
}
if ( ! V_31 . V_36 . V_37 )
V_31 . V_35 = 0 ;
return V_31 ;
}
int F_11 ( int V_32 ,
T_2
V_51 ,
T_1 V_52 )
{
if ( ( V_51 & V_53 ) !=
V_54 ) {
T_3 V_55 ;
V_55 . V_56 =
F_5 ( V_32 >> 8 , V_32 & 0xff ,
V_57 ) ;
V_55 . V_36 . V_58 =
( V_51 & V_53 ) ==
V_59 ;
V_55 . V_36 . V_60 =
( V_51 & V_53 ) ==
V_59 ;
F_12 ( V_32 >> 8 , V_32 & 0xff ,
V_57 ,
V_55 . V_56 ) ;
}
if ( ( V_51 & V_61 )
&& ( V_52 . V_36 . V_39 == 0 ) ) {
T_4 V_62 ;
T_5 V_63 ;
T_3 V_55 ;
T_6 V_64 ;
T_7 V_65 ;
V_63 . V_56 =
F_5 ( V_32 >> 8 , V_32 & 0xff ,
V_66 ) ;
V_55 . V_56 =
F_5 ( V_32 >> 8 , V_32 & 0xff ,
V_57 ) ;
V_55 . V_36 . V_67 =
V_63 . V_36 . V_68 ;
V_55 . V_36 . V_69 =
V_63 . V_36 . V_70 ;
V_55 . V_36 . V_71 =
V_63 . V_36 . V_72 ;
V_55 . V_36 . V_73 =
V_63 . V_36 . V_74 ;
V_55 . V_36 . V_75 =
V_63 . V_36 . V_76 ;
F_12 ( V_32 >> 8 , V_32 & 0xff ,
V_57 ,
V_55 . V_56 ) ;
if ( V_63 . V_36 . V_77 ) {
V_64 . V_56 =
F_5 ( V_32 >> 8 , V_32 & 0xff ,
V_78 ) ;
V_65 . V_56 =
F_5 ( V_32 >> 8 , V_32 & 0xff ,
V_79 ) ;
V_65 . V_36 . V_80 =
V_64 . V_36 . V_81 ;
V_65 . V_36 . V_82 =
V_64 . V_36 . V_83 ;
F_12 ( V_32 >> 8 , V_32 & 0xff ,
V_79 ,
V_65 . V_56 ) ;
}
V_62 . V_56 =
F_5 ( V_32 >> 8 , V_32 & 0xff ,
V_84 ) ;
V_62 . V_36 . V_85 = 1 ;
V_62 . V_36 . V_86 = 1 ;
F_12 ( V_32 >> 8 , V_32 & 0xff ,
V_84 , V_62 . V_56 ) ;
} else if ( ( V_51 & V_61 ) ) {
T_4 V_62 ;
T_5 V_63 ;
T_3 V_55 ;
T_7 V_65 ;
V_63 . V_56 =
F_5 ( V_32 >> 8 , V_32 & 0xff ,
V_66 ) ;
V_55 . V_56 =
F_5 ( V_32 >> 8 , V_32 & 0xff ,
V_57 ) ;
V_55 . V_36 . V_67 = 0 ;
V_55 . V_36 . V_69 = 0 ;
V_55 . V_36 . V_71 = 0 ;
V_55 . V_36 . V_73 = 0 ;
V_55 . V_36 . V_75 = 0 ;
if ( V_63 . V_36 . V_77 ) {
V_65 . V_56 =
F_5 ( V_32 >> 8 , V_32 & 0xff ,
V_79 ) ;
V_65 . V_36 . V_80 = 0 ;
V_65 . V_36 . V_82 = 0 ;
}
switch ( V_52 . V_36 . V_39 ) {
case 10 :
V_55 . V_36 . V_69 =
V_52 . V_36 . V_38 ;
V_55 . V_36 . V_71 =
! V_52 . V_36 . V_38 ;
break;
case 100 :
V_55 . V_36 . V_73 =
V_52 . V_36 . V_38 ;
V_55 . V_36 . V_75 =
! V_52 . V_36 . V_38 ;
break;
case 1000 :
V_65 . V_36 . V_80 =
V_52 . V_36 . V_38 ;
V_65 . V_36 . V_82 =
! V_52 . V_36 . V_38 ;
break;
}
F_12 ( V_32 >> 8 , V_32 & 0xff ,
V_57 ,
V_55 . V_56 ) ;
if ( V_63 . V_36 . V_77 )
F_12 ( V_32 >> 8 , V_32 & 0xff ,
V_79 ,
V_65 . V_56 ) ;
V_62 . V_56 =
F_5 ( V_32 >> 8 , V_32 & 0xff ,
V_84 ) ;
V_62 . V_36 . V_85 = 1 ;
V_62 . V_36 . V_86 = 1 ;
F_12 ( V_32 >> 8 , V_32 & 0xff ,
V_84 , V_62 . V_56 ) ;
} else {
T_4 V_62 ;
V_62 . V_56 =
F_5 ( V_32 >> 8 , V_32 & 0xff ,
V_84 ) ;
V_62 . V_36 . V_85 = 0 ;
V_62 . V_36 . V_86 = 1 ;
V_62 . V_36 . V_50 = V_52 . V_36 . V_38 ;
if ( V_52 . V_36 . V_39 == 1000 ) {
V_62 . V_36 . V_87 = 1 ;
V_62 . V_36 . V_88 = 0 ;
} else if ( V_52 . V_36 . V_39 == 100 ) {
V_62 . V_36 . V_87 = 0 ;
V_62 . V_36 . V_88 = 1 ;
} else if ( V_52 . V_36 . V_39 == 10 ) {
V_62 . V_36 . V_87 = 0 ;
V_62 . V_36 . V_88 = 0 ;
}
F_12 ( V_32 >> 8 , V_32 & 0xff ,
V_84 , V_62 . V_56 ) ;
}
return 0 ;
}
int F_13 ( int V_47 , int V_89 )
{
switch ( F_2 () -> V_2 ) {
case V_12 :
if ( V_47 == 0 )
return 2 ;
break;
case V_29 :
if ( V_47 == 0 )
return 2 ;
break;
case V_24 :
if ( V_47 == 0 )
return 0 ;
break;
case V_20 :
if ( V_47 == 1 )
return 0 ;
break;
}
return V_89 ;
}
int F_14 ( int V_47 )
{
if ( F_2 () -> V_2 == V_12 ) {
if ( V_47 == 0 ) {
F_15 ( F_16 ( 1 , V_47 ) , 0 ) ;
F_15 ( F_17 ( 1 , V_47 ) , 0 ) ;
F_15 ( F_16 ( 0 , V_47 ) ,
0xc ) ;
F_15 ( F_17 ( 0 , V_47 ) ,
0xc ) ;
}
} else if ( F_2 () -> V_2 ==
V_11 ) {
if ( V_47 == 0 ) {
int V_32 = F_1 ( 0 ) ;
if ( V_32 != - 1 ) {
int V_90 =
F_5 ( V_32 >> 8 ,
V_32 & 0xff , 0x2 ) ;
if ( V_90 == 0x0143 ) {
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
( 0 , V_47 ) , 5 ) ;
F_15 ( F_16
( 0 , V_47 ) , 5 ) ;
}
}
}
}
return 0 ;
}
