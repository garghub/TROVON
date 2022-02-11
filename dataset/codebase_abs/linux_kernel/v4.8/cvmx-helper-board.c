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
int V_34 ;
int V_35 = 0 ;
if ( V_36 )
return V_36 ( V_1 ) ;
V_33 . V_37 = 0 ;
switch ( F_2 () -> V_2 ) {
case V_3 :
V_33 . V_38 . V_39 = 1 ;
V_33 . V_38 . V_40 = 1 ;
V_33 . V_38 . V_41 = 1000 ;
return V_33 ;
case V_9 :
case V_11 :
case V_12 :
case V_13 :
if ( V_1 == 1 ) {
V_33 . V_38 . V_39 = 1 ;
V_33 . V_38 . V_40 = 1 ;
V_33 . V_38 . V_41 = 1000 ;
return V_33 ;
}
break;
case V_23 :
if ( V_1 == 1 ) {
V_33 . V_38 . V_39 = 1 ;
V_33 . V_38 . V_40 = 1 ;
V_33 . V_38 . V_41 = 1000 ;
return V_33 ;
} else
V_35 = 1 ;
break;
case V_29 :
if ( V_1 == 2 ) {
V_33 . V_37 = 0 ;
return V_33 ;
} else {
V_33 . V_38 . V_39 = 1 ;
V_33 . V_38 . V_40 = 1 ;
V_33 . V_38 . V_41 = 1000 ;
return V_33 ;
}
break;
}
V_34 = F_1 ( V_1 ) ;
if ( V_34 != - 1 ) {
if ( V_35 ) {
int V_42 =
F_5 ( V_34 >> 8 , V_34 & 0xff ,
0x19 ) ;
switch ( ( V_42 >> 8 ) & 0x7 ) {
case 0 :
V_33 . V_37 = 0 ;
break;
case 1 :
V_33 . V_38 . V_39 = 1 ;
V_33 . V_38 . V_40 = 0 ;
V_33 . V_38 . V_41 = 10 ;
break;
case 2 :
V_33 . V_38 . V_39 = 1 ;
V_33 . V_38 . V_40 = 1 ;
V_33 . V_38 . V_41 = 10 ;
break;
case 3 :
V_33 . V_38 . V_39 = 1 ;
V_33 . V_38 . V_40 = 0 ;
V_33 . V_38 . V_41 = 100 ;
break;
case 4 :
V_33 . V_38 . V_39 = 1 ;
V_33 . V_38 . V_40 = 1 ;
V_33 . V_38 . V_41 = 100 ;
break;
case 5 :
V_33 . V_38 . V_39 = 1 ;
V_33 . V_38 . V_40 = 1 ;
V_33 . V_38 . V_41 = 100 ;
break;
case 6 :
V_33 . V_38 . V_39 = 1 ;
V_33 . V_38 . V_40 = 0 ;
V_33 . V_38 . V_41 = 1000 ;
break;
case 7 :
V_33 . V_38 . V_39 = 1 ;
V_33 . V_38 . V_40 = 1 ;
V_33 . V_38 . V_41 = 1000 ;
break;
}
} else {
int V_42 =
F_5 ( V_34 >> 8 , V_34 & 0xff , 17 ) ;
if ( ( V_42 & ( 1 << 11 ) ) == 0 ) {
int V_43 =
F_5 ( V_34 >> 8 ,
V_34 & 0xff , 0 ) ;
if ( ( V_43 & ( 1 << 12 ) ) == 0 )
V_42 |= 1 << 11 ;
}
if ( V_42 & ( 1 << 11 ) ) {
V_33 . V_38 . V_39 = 1 ;
V_33 . V_38 . V_40 = ( ( V_42 >> 13 ) & 1 ) ;
switch ( ( V_42 >> 14 ) & 3 ) {
case 0 :
V_33 . V_38 . V_41 = 10 ;
break;
case 1 :
V_33 . V_38 . V_41 = 100 ;
break;
case 2 :
V_33 . V_38 . V_41 = 1000 ;
break;
case 3 :
V_33 . V_37 = 0 ;
break;
}
}
}
} else if ( F_6 ( V_44 )
|| F_6 ( V_45 )
|| F_6 ( V_46 ) ) {
union V_47 V_48 ;
int V_49 = F_7 ( V_1 ) ;
int V_50 = F_8 ( V_1 ) ;
V_48 . V_37 =
F_9 ( F_10 ( V_50 , V_49 ) ) ;
V_33 . V_38 . V_39 = V_48 . V_38 . V_51 ;
V_33 . V_38 . V_40 = V_48 . V_38 . V_52 ;
switch ( V_48 . V_38 . V_41 ) {
case 0 :
V_33 . V_38 . V_41 = 10 ;
break;
case 1 :
V_33 . V_38 . V_41 = 100 ;
break;
case 2 :
V_33 . V_38 . V_41 = 1000 ;
break;
case 3 :
V_33 . V_37 = 0 ;
break;
}
} else {
V_33 . V_37 = 0 ;
}
if ( ! V_33 . V_38 . V_39 )
V_33 . V_37 = 0 ;
return V_33 ;
}
int F_11 ( int V_34 ,
T_2
V_53 ,
T_1 V_54 )
{
if ( ( V_53 & V_55 ) !=
V_56 ) {
T_3 V_57 ;
V_57 . V_58 =
F_5 ( V_34 >> 8 , V_34 & 0xff ,
V_59 ) ;
V_57 . V_38 . V_60 =
( V_53 & V_55 ) ==
V_61 ;
V_57 . V_38 . V_62 =
( V_53 & V_55 ) ==
V_61 ;
F_12 ( V_34 >> 8 , V_34 & 0xff ,
V_59 ,
V_57 . V_58 ) ;
}
if ( ( V_53 & V_63 )
&& ( V_54 . V_38 . V_41 == 0 ) ) {
T_4 V_64 ;
T_5 V_65 ;
T_3 V_57 ;
T_6 V_66 ;
T_7 V_67 ;
V_65 . V_58 =
F_5 ( V_34 >> 8 , V_34 & 0xff ,
V_68 ) ;
V_57 . V_58 =
F_5 ( V_34 >> 8 , V_34 & 0xff ,
V_59 ) ;
V_57 . V_38 . V_69 =
V_65 . V_38 . V_70 ;
V_57 . V_38 . V_71 =
V_65 . V_38 . V_72 ;
V_57 . V_38 . V_73 =
V_65 . V_38 . V_74 ;
V_57 . V_38 . V_75 =
V_65 . V_38 . V_76 ;
V_57 . V_38 . V_77 =
V_65 . V_38 . V_78 ;
F_12 ( V_34 >> 8 , V_34 & 0xff ,
V_59 ,
V_57 . V_58 ) ;
if ( V_65 . V_38 . V_79 ) {
V_66 . V_58 =
F_5 ( V_34 >> 8 , V_34 & 0xff ,
V_80 ) ;
V_67 . V_58 =
F_5 ( V_34 >> 8 , V_34 & 0xff ,
V_81 ) ;
V_67 . V_38 . V_82 =
V_66 . V_38 . V_83 ;
V_67 . V_38 . V_84 =
V_66 . V_38 . V_85 ;
F_12 ( V_34 >> 8 , V_34 & 0xff ,
V_81 ,
V_67 . V_58 ) ;
}
V_64 . V_58 =
F_5 ( V_34 >> 8 , V_34 & 0xff ,
V_86 ) ;
V_64 . V_38 . V_87 = 1 ;
V_64 . V_38 . V_88 = 1 ;
F_12 ( V_34 >> 8 , V_34 & 0xff ,
V_86 , V_64 . V_58 ) ;
} else if ( ( V_53 & V_63 ) ) {
T_4 V_64 ;
T_5 V_65 ;
T_3 V_57 ;
T_7 V_67 ;
V_65 . V_58 =
F_5 ( V_34 >> 8 , V_34 & 0xff ,
V_68 ) ;
V_57 . V_58 =
F_5 ( V_34 >> 8 , V_34 & 0xff ,
V_59 ) ;
V_57 . V_38 . V_69 = 0 ;
V_57 . V_38 . V_71 = 0 ;
V_57 . V_38 . V_73 = 0 ;
V_57 . V_38 . V_75 = 0 ;
V_57 . V_38 . V_77 = 0 ;
if ( V_65 . V_38 . V_79 ) {
V_67 . V_58 =
F_5 ( V_34 >> 8 , V_34 & 0xff ,
V_81 ) ;
V_67 . V_38 . V_82 = 0 ;
V_67 . V_38 . V_84 = 0 ;
}
switch ( V_54 . V_38 . V_41 ) {
case 10 :
V_57 . V_38 . V_71 =
V_54 . V_38 . V_40 ;
V_57 . V_38 . V_73 =
! V_54 . V_38 . V_40 ;
break;
case 100 :
V_57 . V_38 . V_75 =
V_54 . V_38 . V_40 ;
V_57 . V_38 . V_77 =
! V_54 . V_38 . V_40 ;
break;
case 1000 :
V_67 . V_38 . V_82 =
V_54 . V_38 . V_40 ;
V_67 . V_38 . V_84 =
! V_54 . V_38 . V_40 ;
break;
}
F_12 ( V_34 >> 8 , V_34 & 0xff ,
V_59 ,
V_57 . V_58 ) ;
if ( V_65 . V_38 . V_79 )
F_12 ( V_34 >> 8 , V_34 & 0xff ,
V_81 ,
V_67 . V_58 ) ;
V_64 . V_58 =
F_5 ( V_34 >> 8 , V_34 & 0xff ,
V_86 ) ;
V_64 . V_38 . V_87 = 1 ;
V_64 . V_38 . V_88 = 1 ;
F_12 ( V_34 >> 8 , V_34 & 0xff ,
V_86 , V_64 . V_58 ) ;
} else {
T_4 V_64 ;
V_64 . V_58 =
F_5 ( V_34 >> 8 , V_34 & 0xff ,
V_86 ) ;
V_64 . V_38 . V_87 = 0 ;
V_64 . V_38 . V_88 = 1 ;
V_64 . V_38 . V_52 = V_54 . V_38 . V_40 ;
if ( V_54 . V_38 . V_41 == 1000 ) {
V_64 . V_38 . V_89 = 1 ;
V_64 . V_38 . V_90 = 0 ;
} else if ( V_54 . V_38 . V_41 == 100 ) {
V_64 . V_38 . V_89 = 0 ;
V_64 . V_38 . V_90 = 1 ;
} else if ( V_54 . V_38 . V_41 == 10 ) {
V_64 . V_38 . V_89 = 0 ;
V_64 . V_38 . V_90 = 0 ;
}
F_12 ( V_34 >> 8 , V_34 & 0xff ,
V_86 , V_64 . V_58 ) ;
}
return 0 ;
}
int F_13 ( int V_49 , int V_91 )
{
switch ( F_2 () -> V_2 ) {
case V_12 :
if ( V_49 == 0 )
return 2 ;
break;
case V_29 :
if ( V_49 == 0 )
return 2 ;
break;
case V_24 :
if ( V_49 == 0 )
return 0 ;
break;
case V_20 :
if ( V_49 == 1 )
return 0 ;
break;
}
return V_91 ;
}
int F_14 ( int V_49 )
{
if ( F_2 () -> V_2 == V_12 ) {
if ( V_49 == 0 ) {
F_15 ( F_16 ( 1 , V_49 ) , 0 ) ;
F_15 ( F_17 ( 1 , V_49 ) , 0 ) ;
F_15 ( F_16 ( 0 , V_49 ) ,
0xc ) ;
F_15 ( F_17 ( 0 , V_49 ) ,
0xc ) ;
}
} else if ( F_2 () -> V_2 ==
V_11 ) {
if ( V_49 == 0 ) {
int V_34 = F_1 ( 0 ) ;
if ( V_34 != - 1 ) {
int V_92 =
F_5 ( V_34 >> 8 ,
V_34 & 0xff , 0x2 ) ;
if ( V_92 == 0x0143 ) {
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
( 0 , V_49 ) , 5 ) ;
F_15 ( F_16
( 0 , V_49 ) , 5 ) ;
}
}
}
} else if ( F_2 () -> V_2 ==
V_31 ) {
F_15 ( F_17 ( 0 , V_49 ) , 0 ) ;
F_15 ( F_16 ( 0 , V_49 ) , 0x10 ) ;
F_15 ( F_17 ( 1 , V_49 ) , 0 ) ;
F_15 ( F_16 ( 1 , V_49 ) , 0x10 ) ;
F_15 ( F_17 ( 2 , V_49 ) , 0 ) ;
F_15 ( F_16 ( 2 , V_49 ) , 0x10 ) ;
}
return 0 ;
}
enum V_93 F_19 ( void )
{
switch ( F_2 () -> V_2 ) {
case V_29 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_31 :
return V_98 ;
case V_26 :
return V_99 ;
default:
break;
}
if ( F_20 () )
return V_98 ;
return V_100 ;
}
