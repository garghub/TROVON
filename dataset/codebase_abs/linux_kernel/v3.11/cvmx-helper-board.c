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
}
F_3
( L_1 ,
F_2 () -> V_2 ) ;
return - 1 ;
}
T_1 F_4 ( int V_1 )
{
T_1 V_32 ;
int V_33 ;
int V_34 = 0 ;
if ( V_35 )
return V_35 ( V_1 ) ;
V_32 . V_36 = 0 ;
switch ( F_2 () -> V_2 ) {
case V_3 :
V_32 . V_37 . V_38 = 1 ;
V_32 . V_37 . V_39 = 1 ;
V_32 . V_37 . V_40 = 1000 ;
return V_32 ;
case V_9 :
case V_11 :
case V_12 :
case V_13 :
if ( V_1 == 1 ) {
V_32 . V_37 . V_38 = 1 ;
V_32 . V_37 . V_39 = 1 ;
V_32 . V_37 . V_40 = 1000 ;
return V_32 ;
}
break;
case V_23 :
if ( V_1 == 1 ) {
V_32 . V_37 . V_38 = 1 ;
V_32 . V_37 . V_39 = 1 ;
V_32 . V_37 . V_40 = 1000 ;
return V_32 ;
} else
V_34 = 1 ;
break;
case V_29 :
if ( V_1 == 2 ) {
V_32 . V_36 = 0 ;
return V_32 ;
} else {
V_32 . V_37 . V_38 = 1 ;
V_32 . V_37 . V_39 = 1 ;
V_32 . V_37 . V_40 = 1000 ;
return V_32 ;
}
break;
}
V_33 = F_1 ( V_1 ) ;
if ( V_33 != - 1 ) {
if ( V_34 ) {
int V_41 =
F_5 ( V_33 >> 8 , V_33 & 0xff ,
0x19 ) ;
switch ( ( V_41 >> 8 ) & 0x7 ) {
case 0 :
V_32 . V_36 = 0 ;
break;
case 1 :
V_32 . V_37 . V_38 = 1 ;
V_32 . V_37 . V_39 = 0 ;
V_32 . V_37 . V_40 = 10 ;
break;
case 2 :
V_32 . V_37 . V_38 = 1 ;
V_32 . V_37 . V_39 = 1 ;
V_32 . V_37 . V_40 = 10 ;
break;
case 3 :
V_32 . V_37 . V_38 = 1 ;
V_32 . V_37 . V_39 = 0 ;
V_32 . V_37 . V_40 = 100 ;
break;
case 4 :
V_32 . V_37 . V_38 = 1 ;
V_32 . V_37 . V_39 = 1 ;
V_32 . V_37 . V_40 = 100 ;
break;
case 5 :
V_32 . V_37 . V_38 = 1 ;
V_32 . V_37 . V_39 = 1 ;
V_32 . V_37 . V_40 = 100 ;
break;
case 6 :
V_32 . V_37 . V_38 = 1 ;
V_32 . V_37 . V_39 = 0 ;
V_32 . V_37 . V_40 = 1000 ;
break;
case 7 :
V_32 . V_37 . V_38 = 1 ;
V_32 . V_37 . V_39 = 1 ;
V_32 . V_37 . V_40 = 1000 ;
break;
}
} else {
int V_41 =
F_5 ( V_33 >> 8 , V_33 & 0xff , 17 ) ;
if ( ( V_41 & ( 1 << 11 ) ) == 0 ) {
int V_42 =
F_5 ( V_33 >> 8 ,
V_33 & 0xff , 0 ) ;
if ( ( V_42 & ( 1 << 12 ) ) == 0 )
V_41 |= 1 << 11 ;
}
if ( V_41 & ( 1 << 11 ) ) {
V_32 . V_37 . V_38 = 1 ;
V_32 . V_37 . V_39 = ( ( V_41 >> 13 ) & 1 ) ;
switch ( ( V_41 >> 14 ) & 3 ) {
case 0 :
V_32 . V_37 . V_40 = 10 ;
break;
case 1 :
V_32 . V_37 . V_40 = 100 ;
break;
case 2 :
V_32 . V_37 . V_40 = 1000 ;
break;
case 3 :
V_32 . V_36 = 0 ;
break;
}
}
}
} else if ( F_6 ( V_43 )
|| F_6 ( V_44 )
|| F_6 ( V_45 ) ) {
union V_46 V_47 ;
int V_48 = F_7 ( V_1 ) ;
int V_49 = F_8 ( V_1 ) ;
V_47 . V_36 =
F_9 ( F_10 ( V_49 , V_48 ) ) ;
V_32 . V_37 . V_38 = V_47 . V_37 . V_50 ;
V_32 . V_37 . V_39 = V_47 . V_37 . V_51 ;
switch ( V_47 . V_37 . V_40 ) {
case 0 :
V_32 . V_37 . V_40 = 10 ;
break;
case 1 :
V_32 . V_37 . V_40 = 100 ;
break;
case 2 :
V_32 . V_37 . V_40 = 1000 ;
break;
case 3 :
V_32 . V_36 = 0 ;
break;
}
} else {
V_32 . V_36 = 0 ;
}
if ( ! V_32 . V_37 . V_38 )
V_32 . V_36 = 0 ;
return V_32 ;
}
int F_11 ( int V_33 ,
T_2
V_52 ,
T_1 V_53 )
{
if ( ( V_52 & V_54 ) !=
V_55 ) {
T_3 V_56 ;
V_56 . V_57 =
F_5 ( V_33 >> 8 , V_33 & 0xff ,
V_58 ) ;
V_56 . V_37 . V_59 =
( V_52 & V_54 ) ==
V_60 ;
V_56 . V_37 . V_61 =
( V_52 & V_54 ) ==
V_60 ;
F_12 ( V_33 >> 8 , V_33 & 0xff ,
V_58 ,
V_56 . V_57 ) ;
}
if ( ( V_52 & V_62 )
&& ( V_53 . V_37 . V_40 == 0 ) ) {
T_4 V_63 ;
T_5 V_64 ;
T_3 V_56 ;
T_6 V_65 ;
T_7 V_66 ;
V_64 . V_57 =
F_5 ( V_33 >> 8 , V_33 & 0xff ,
V_67 ) ;
V_56 . V_57 =
F_5 ( V_33 >> 8 , V_33 & 0xff ,
V_58 ) ;
V_56 . V_37 . V_68 =
V_64 . V_37 . V_69 ;
V_56 . V_37 . V_70 =
V_64 . V_37 . V_71 ;
V_56 . V_37 . V_72 =
V_64 . V_37 . V_73 ;
V_56 . V_37 . V_74 =
V_64 . V_37 . V_75 ;
V_56 . V_37 . V_76 =
V_64 . V_37 . V_77 ;
F_12 ( V_33 >> 8 , V_33 & 0xff ,
V_58 ,
V_56 . V_57 ) ;
if ( V_64 . V_37 . V_78 ) {
V_65 . V_57 =
F_5 ( V_33 >> 8 , V_33 & 0xff ,
V_79 ) ;
V_66 . V_57 =
F_5 ( V_33 >> 8 , V_33 & 0xff ,
V_80 ) ;
V_66 . V_37 . V_81 =
V_65 . V_37 . V_82 ;
V_66 . V_37 . V_83 =
V_65 . V_37 . V_84 ;
F_12 ( V_33 >> 8 , V_33 & 0xff ,
V_80 ,
V_66 . V_57 ) ;
}
V_63 . V_57 =
F_5 ( V_33 >> 8 , V_33 & 0xff ,
V_85 ) ;
V_63 . V_37 . V_86 = 1 ;
V_63 . V_37 . V_87 = 1 ;
F_12 ( V_33 >> 8 , V_33 & 0xff ,
V_85 , V_63 . V_57 ) ;
} else if ( ( V_52 & V_62 ) ) {
T_4 V_63 ;
T_5 V_64 ;
T_3 V_56 ;
T_7 V_66 ;
V_64 . V_57 =
F_5 ( V_33 >> 8 , V_33 & 0xff ,
V_67 ) ;
V_56 . V_57 =
F_5 ( V_33 >> 8 , V_33 & 0xff ,
V_58 ) ;
V_56 . V_37 . V_68 = 0 ;
V_56 . V_37 . V_70 = 0 ;
V_56 . V_37 . V_72 = 0 ;
V_56 . V_37 . V_74 = 0 ;
V_56 . V_37 . V_76 = 0 ;
if ( V_64 . V_37 . V_78 ) {
V_66 . V_57 =
F_5 ( V_33 >> 8 , V_33 & 0xff ,
V_80 ) ;
V_66 . V_37 . V_81 = 0 ;
V_66 . V_37 . V_83 = 0 ;
}
switch ( V_53 . V_37 . V_40 ) {
case 10 :
V_56 . V_37 . V_70 =
V_53 . V_37 . V_39 ;
V_56 . V_37 . V_72 =
! V_53 . V_37 . V_39 ;
break;
case 100 :
V_56 . V_37 . V_74 =
V_53 . V_37 . V_39 ;
V_56 . V_37 . V_76 =
! V_53 . V_37 . V_39 ;
break;
case 1000 :
V_66 . V_37 . V_81 =
V_53 . V_37 . V_39 ;
V_66 . V_37 . V_83 =
! V_53 . V_37 . V_39 ;
break;
}
F_12 ( V_33 >> 8 , V_33 & 0xff ,
V_58 ,
V_56 . V_57 ) ;
if ( V_64 . V_37 . V_78 )
F_12 ( V_33 >> 8 , V_33 & 0xff ,
V_80 ,
V_66 . V_57 ) ;
V_63 . V_57 =
F_5 ( V_33 >> 8 , V_33 & 0xff ,
V_85 ) ;
V_63 . V_37 . V_86 = 1 ;
V_63 . V_37 . V_87 = 1 ;
F_12 ( V_33 >> 8 , V_33 & 0xff ,
V_85 , V_63 . V_57 ) ;
} else {
T_4 V_63 ;
V_63 . V_57 =
F_5 ( V_33 >> 8 , V_33 & 0xff ,
V_85 ) ;
V_63 . V_37 . V_86 = 0 ;
V_63 . V_37 . V_87 = 1 ;
V_63 . V_37 . V_51 = V_53 . V_37 . V_39 ;
if ( V_53 . V_37 . V_40 == 1000 ) {
V_63 . V_37 . V_88 = 1 ;
V_63 . V_37 . V_89 = 0 ;
} else if ( V_53 . V_37 . V_40 == 100 ) {
V_63 . V_37 . V_88 = 0 ;
V_63 . V_37 . V_89 = 1 ;
} else if ( V_53 . V_37 . V_40 == 10 ) {
V_63 . V_37 . V_88 = 0 ;
V_63 . V_37 . V_89 = 0 ;
}
F_12 ( V_33 >> 8 , V_33 & 0xff ,
V_85 , V_63 . V_57 ) ;
}
return 0 ;
}
int F_13 ( int V_48 , int V_90 )
{
switch ( F_2 () -> V_2 ) {
case V_12 :
if ( V_48 == 0 )
return 2 ;
break;
case V_29 :
if ( V_48 == 0 )
return 2 ;
break;
case V_24 :
if ( V_48 == 0 )
return 0 ;
break;
case V_20 :
if ( V_48 == 1 )
return 0 ;
break;
}
return V_90 ;
}
int F_14 ( int V_48 )
{
if ( F_2 () -> V_2 == V_12 ) {
if ( V_48 == 0 ) {
F_15 ( F_16 ( 1 , V_48 ) , 0 ) ;
F_15 ( F_17 ( 1 , V_48 ) , 0 ) ;
F_15 ( F_16 ( 0 , V_48 ) ,
0xc ) ;
F_15 ( F_17 ( 0 , V_48 ) ,
0xc ) ;
}
} else if ( F_2 () -> V_2 ==
V_11 ) {
if ( V_48 == 0 ) {
int V_33 = F_1 ( 0 ) ;
if ( V_33 != - 1 ) {
int V_91 =
F_5 ( V_33 >> 8 ,
V_33 & 0xff , 0x2 ) ;
if ( V_91 == 0x0143 ) {
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
( 0 , V_48 ) , 5 ) ;
F_15 ( F_16
( 0 , V_48 ) , 5 ) ;
}
}
}
} else if ( F_2 () -> V_2 ==
V_31 ) {
F_15 ( F_17 ( 0 , V_48 ) , 0 ) ;
F_15 ( F_16 ( 0 , V_48 ) , 0x10 ) ;
F_15 ( F_17 ( 1 , V_48 ) , 0 ) ;
F_15 ( F_16 ( 1 , V_48 ) , 0x10 ) ;
F_15 ( F_17 ( 2 , V_48 ) , 0 ) ;
F_15 ( F_16 ( 2 , V_48 ) , 0x10 ) ;
}
return 0 ;
}
