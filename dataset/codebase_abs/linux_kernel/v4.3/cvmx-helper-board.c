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
if ( V_1 == 2 )
return 8 ;
else
return - 1 ;
case V_33 :
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
T_1 V_34 ;
int V_35 ;
int V_36 = 0 ;
if ( V_37 )
return V_37 ( V_1 ) ;
V_34 . V_38 = 0 ;
switch ( F_2 () -> V_2 ) {
case V_3 :
V_34 . V_39 . V_40 = 1 ;
V_34 . V_39 . V_41 = 1 ;
V_34 . V_39 . V_42 = 1000 ;
return V_34 ;
case V_9 :
case V_11 :
case V_12 :
case V_13 :
if ( V_1 == 1 ) {
V_34 . V_39 . V_40 = 1 ;
V_34 . V_39 . V_41 = 1 ;
V_34 . V_39 . V_42 = 1000 ;
return V_34 ;
}
break;
case V_23 :
if ( V_1 == 1 ) {
V_34 . V_39 . V_40 = 1 ;
V_34 . V_39 . V_41 = 1 ;
V_34 . V_39 . V_42 = 1000 ;
return V_34 ;
} else
V_36 = 1 ;
break;
case V_29 :
if ( V_1 == 2 ) {
V_34 . V_38 = 0 ;
return V_34 ;
} else {
V_34 . V_39 . V_40 = 1 ;
V_34 . V_39 . V_41 = 1 ;
V_34 . V_39 . V_42 = 1000 ;
return V_34 ;
}
break;
case V_32 :
if ( V_1 == 0 || V_1 == 1 ) {
V_34 . V_39 . V_40 = 1 ;
V_34 . V_39 . V_41 = 1 ;
V_34 . V_39 . V_42 = 1000 ;
return V_34 ;
} else {
V_36 = 1 ;
}
break;
}
V_35 = F_1 ( V_1 ) ;
if ( V_35 != - 1 ) {
if ( V_36 ) {
int V_43 =
F_5 ( V_35 >> 8 , V_35 & 0xff ,
0x19 ) ;
switch ( ( V_43 >> 8 ) & 0x7 ) {
case 0 :
V_34 . V_38 = 0 ;
break;
case 1 :
V_34 . V_39 . V_40 = 1 ;
V_34 . V_39 . V_41 = 0 ;
V_34 . V_39 . V_42 = 10 ;
break;
case 2 :
V_34 . V_39 . V_40 = 1 ;
V_34 . V_39 . V_41 = 1 ;
V_34 . V_39 . V_42 = 10 ;
break;
case 3 :
V_34 . V_39 . V_40 = 1 ;
V_34 . V_39 . V_41 = 0 ;
V_34 . V_39 . V_42 = 100 ;
break;
case 4 :
V_34 . V_39 . V_40 = 1 ;
V_34 . V_39 . V_41 = 1 ;
V_34 . V_39 . V_42 = 100 ;
break;
case 5 :
V_34 . V_39 . V_40 = 1 ;
V_34 . V_39 . V_41 = 1 ;
V_34 . V_39 . V_42 = 100 ;
break;
case 6 :
V_34 . V_39 . V_40 = 1 ;
V_34 . V_39 . V_41 = 0 ;
V_34 . V_39 . V_42 = 1000 ;
break;
case 7 :
V_34 . V_39 . V_40 = 1 ;
V_34 . V_39 . V_41 = 1 ;
V_34 . V_39 . V_42 = 1000 ;
break;
}
} else {
int V_43 =
F_5 ( V_35 >> 8 , V_35 & 0xff , 17 ) ;
if ( ( V_43 & ( 1 << 11 ) ) == 0 ) {
int V_44 =
F_5 ( V_35 >> 8 ,
V_35 & 0xff , 0 ) ;
if ( ( V_44 & ( 1 << 12 ) ) == 0 )
V_43 |= 1 << 11 ;
}
if ( V_43 & ( 1 << 11 ) ) {
V_34 . V_39 . V_40 = 1 ;
V_34 . V_39 . V_41 = ( ( V_43 >> 13 ) & 1 ) ;
switch ( ( V_43 >> 14 ) & 3 ) {
case 0 :
V_34 . V_39 . V_42 = 10 ;
break;
case 1 :
V_34 . V_39 . V_42 = 100 ;
break;
case 2 :
V_34 . V_39 . V_42 = 1000 ;
break;
case 3 :
V_34 . V_38 = 0 ;
break;
}
}
}
} else if ( F_6 ( V_45 )
|| F_6 ( V_46 )
|| F_6 ( V_47 ) ) {
union V_48 V_49 ;
int V_50 = F_7 ( V_1 ) ;
int V_51 = F_8 ( V_1 ) ;
V_49 . V_38 =
F_9 ( F_10 ( V_51 , V_50 ) ) ;
V_34 . V_39 . V_40 = V_49 . V_39 . V_52 ;
V_34 . V_39 . V_41 = V_49 . V_39 . V_53 ;
switch ( V_49 . V_39 . V_42 ) {
case 0 :
V_34 . V_39 . V_42 = 10 ;
break;
case 1 :
V_34 . V_39 . V_42 = 100 ;
break;
case 2 :
V_34 . V_39 . V_42 = 1000 ;
break;
case 3 :
V_34 . V_38 = 0 ;
break;
}
} else {
V_34 . V_38 = 0 ;
}
if ( ! V_34 . V_39 . V_40 )
V_34 . V_38 = 0 ;
return V_34 ;
}
int F_11 ( int V_35 ,
T_2
V_54 ,
T_1 V_55 )
{
if ( ( V_54 & V_56 ) !=
V_57 ) {
T_3 V_58 ;
V_58 . V_59 =
F_5 ( V_35 >> 8 , V_35 & 0xff ,
V_60 ) ;
V_58 . V_39 . V_61 =
( V_54 & V_56 ) ==
V_62 ;
V_58 . V_39 . V_63 =
( V_54 & V_56 ) ==
V_62 ;
F_12 ( V_35 >> 8 , V_35 & 0xff ,
V_60 ,
V_58 . V_59 ) ;
}
if ( ( V_54 & V_64 )
&& ( V_55 . V_39 . V_42 == 0 ) ) {
T_4 V_65 ;
T_5 V_66 ;
T_3 V_58 ;
T_6 V_67 ;
T_7 V_68 ;
V_66 . V_59 =
F_5 ( V_35 >> 8 , V_35 & 0xff ,
V_69 ) ;
V_58 . V_59 =
F_5 ( V_35 >> 8 , V_35 & 0xff ,
V_60 ) ;
V_58 . V_39 . V_70 =
V_66 . V_39 . V_71 ;
V_58 . V_39 . V_72 =
V_66 . V_39 . V_73 ;
V_58 . V_39 . V_74 =
V_66 . V_39 . V_75 ;
V_58 . V_39 . V_76 =
V_66 . V_39 . V_77 ;
V_58 . V_39 . V_78 =
V_66 . V_39 . V_79 ;
F_12 ( V_35 >> 8 , V_35 & 0xff ,
V_60 ,
V_58 . V_59 ) ;
if ( V_66 . V_39 . V_80 ) {
V_67 . V_59 =
F_5 ( V_35 >> 8 , V_35 & 0xff ,
V_81 ) ;
V_68 . V_59 =
F_5 ( V_35 >> 8 , V_35 & 0xff ,
V_82 ) ;
V_68 . V_39 . V_83 =
V_67 . V_39 . V_84 ;
V_68 . V_39 . V_85 =
V_67 . V_39 . V_86 ;
F_12 ( V_35 >> 8 , V_35 & 0xff ,
V_82 ,
V_68 . V_59 ) ;
}
V_65 . V_59 =
F_5 ( V_35 >> 8 , V_35 & 0xff ,
V_87 ) ;
V_65 . V_39 . V_88 = 1 ;
V_65 . V_39 . V_89 = 1 ;
F_12 ( V_35 >> 8 , V_35 & 0xff ,
V_87 , V_65 . V_59 ) ;
} else if ( ( V_54 & V_64 ) ) {
T_4 V_65 ;
T_5 V_66 ;
T_3 V_58 ;
T_7 V_68 ;
V_66 . V_59 =
F_5 ( V_35 >> 8 , V_35 & 0xff ,
V_69 ) ;
V_58 . V_59 =
F_5 ( V_35 >> 8 , V_35 & 0xff ,
V_60 ) ;
V_58 . V_39 . V_70 = 0 ;
V_58 . V_39 . V_72 = 0 ;
V_58 . V_39 . V_74 = 0 ;
V_58 . V_39 . V_76 = 0 ;
V_58 . V_39 . V_78 = 0 ;
if ( V_66 . V_39 . V_80 ) {
V_68 . V_59 =
F_5 ( V_35 >> 8 , V_35 & 0xff ,
V_82 ) ;
V_68 . V_39 . V_83 = 0 ;
V_68 . V_39 . V_85 = 0 ;
}
switch ( V_55 . V_39 . V_42 ) {
case 10 :
V_58 . V_39 . V_72 =
V_55 . V_39 . V_41 ;
V_58 . V_39 . V_74 =
! V_55 . V_39 . V_41 ;
break;
case 100 :
V_58 . V_39 . V_76 =
V_55 . V_39 . V_41 ;
V_58 . V_39 . V_78 =
! V_55 . V_39 . V_41 ;
break;
case 1000 :
V_68 . V_39 . V_83 =
V_55 . V_39 . V_41 ;
V_68 . V_39 . V_85 =
! V_55 . V_39 . V_41 ;
break;
}
F_12 ( V_35 >> 8 , V_35 & 0xff ,
V_60 ,
V_58 . V_59 ) ;
if ( V_66 . V_39 . V_80 )
F_12 ( V_35 >> 8 , V_35 & 0xff ,
V_82 ,
V_68 . V_59 ) ;
V_65 . V_59 =
F_5 ( V_35 >> 8 , V_35 & 0xff ,
V_87 ) ;
V_65 . V_39 . V_88 = 1 ;
V_65 . V_39 . V_89 = 1 ;
F_12 ( V_35 >> 8 , V_35 & 0xff ,
V_87 , V_65 . V_59 ) ;
} else {
T_4 V_65 ;
V_65 . V_59 =
F_5 ( V_35 >> 8 , V_35 & 0xff ,
V_87 ) ;
V_65 . V_39 . V_88 = 0 ;
V_65 . V_39 . V_89 = 1 ;
V_65 . V_39 . V_53 = V_55 . V_39 . V_41 ;
if ( V_55 . V_39 . V_42 == 1000 ) {
V_65 . V_39 . V_90 = 1 ;
V_65 . V_39 . V_91 = 0 ;
} else if ( V_55 . V_39 . V_42 == 100 ) {
V_65 . V_39 . V_90 = 0 ;
V_65 . V_39 . V_91 = 1 ;
} else if ( V_55 . V_39 . V_42 == 10 ) {
V_65 . V_39 . V_90 = 0 ;
V_65 . V_39 . V_91 = 0 ;
}
F_12 ( V_35 >> 8 , V_35 & 0xff ,
V_87 , V_65 . V_59 ) ;
}
return 0 ;
}
int F_13 ( int V_50 , int V_92 )
{
switch ( F_2 () -> V_2 ) {
case V_12 :
if ( V_50 == 0 )
return 2 ;
break;
case V_29 :
if ( V_50 == 0 )
return 2 ;
break;
case V_24 :
if ( V_50 == 0 )
return 0 ;
break;
case V_20 :
if ( V_50 == 1 )
return 0 ;
break;
}
return V_92 ;
}
int F_14 ( int V_50 )
{
if ( F_2 () -> V_2 == V_12 ) {
if ( V_50 == 0 ) {
F_15 ( F_16 ( 1 , V_50 ) , 0 ) ;
F_15 ( F_17 ( 1 , V_50 ) , 0 ) ;
F_15 ( F_16 ( 0 , V_50 ) ,
0xc ) ;
F_15 ( F_17 ( 0 , V_50 ) ,
0xc ) ;
}
} else if ( F_2 () -> V_2 ==
V_11 ) {
if ( V_50 == 0 ) {
int V_35 = F_1 ( 0 ) ;
if ( V_35 != - 1 ) {
int V_93 =
F_5 ( V_35 >> 8 ,
V_35 & 0xff , 0x2 ) ;
if ( V_93 == 0x0143 ) {
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
( 0 , V_50 ) , 5 ) ;
F_15 ( F_16
( 0 , V_50 ) , 5 ) ;
}
}
}
} else if ( F_2 () -> V_2 ==
V_31 ) {
F_15 ( F_17 ( 0 , V_50 ) , 0 ) ;
F_15 ( F_16 ( 0 , V_50 ) , 0x10 ) ;
F_15 ( F_17 ( 1 , V_50 ) , 0 ) ;
F_15 ( F_16 ( 1 , V_50 ) , 0x10 ) ;
F_15 ( F_17 ( 2 , V_50 ) , 0 ) ;
F_15 ( F_16 ( 2 , V_50 ) , 0x10 ) ;
}
return 0 ;
}
enum V_94 F_19 ( void )
{
switch ( F_2 () -> V_2 ) {
case V_29 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_31 :
case V_32 :
return V_99 ;
case V_26 :
return V_100 ;
default:
break;
}
if ( F_20 () )
return V_99 ;
return V_101 ;
}
