static
void F_1 ( T_1 * V_1
, T_2 * V_2
, T_3 * V_3
, T_4 V_4 )
{
const int V_5 = 4 ;
T_5 V_6 ;
T_5 V_7 ;
T_5 V_8 ;
int V_9 ;
enum {
V_10 = 0
, V_11
, V_12
, V_13
, V_14
} V_15 ;
V_6 = F_2 ( V_1 , 0 ) ;
if ( V_6 < 4 )
{
T_6 * V_16 ;
V_16 = F_3 ( V_3 , V_17 , V_1 , 0 , - 1 , V_18 ) ;
F_4 ( V_2 , V_16 , & V_19 ,
L_1
, ( int ) V_6 ) ;
F_5 ( V_2 -> V_20 , V_21 , V_22 ) ;
F_5 ( V_2 -> V_20 , V_23 , L_2 ) ;
return;
}
switch ( V_4 )
{
case V_24 :
if ( F_6 ( V_1 , V_2 , V_3 ) )
{
return;
}
break;
case V_25 :
break;
default:
F_7 () ;
return;
}
V_9 = 0 ;
if ( 0 != ( F_8 ( V_1 , 0 ) & 0xf0 ) )
{
V_9 |= V_26 ;
}
if ( 0 != ( F_8 ( V_1 , 0 ) & 0x03 ) )
{
V_9 |= V_27 ;
}
if ( 0 != ( F_8 ( V_1 , 1 ) & 0xc0 ) )
{
V_9 |= V_28 ;
}
{
int V_29 ;
T_5 V_30 ;
V_29 = F_8 ( V_1 , 1 ) & 0x3f ;
V_30 = V_6 - V_5 ;
if ( V_29 != 0 )
{
T_5 V_31 ;
V_31 = V_29 - V_5 ;
V_7 = V_30 ;
V_8 = 0 ;
if ( V_31 < 0 )
{
V_9 |= V_32 ;
}
else if ( V_31 > V_30 )
{
V_9 |= V_33 ;
}
else if ( V_30 >= 64 )
{
V_9 |= V_34 ;
}
else
{
V_7 = V_31 ;
V_8 = V_30 - V_31 ;
}
}
else
{
V_7 = V_30 ;
V_8 = 0 ;
}
}
if ( V_7 == 0 )
{
if ( 0 == ( F_8 ( V_1 , 0 ) & 0x08 ) )
{
V_9 |= V_35 ;
}
}
if ( V_7 == 256 )
{
V_15 = V_11 ;
}
else if ( V_7 == 192 )
{
V_15 = V_12 ;
}
else if ( V_7 == 1024 )
{
V_15 = V_13 ;
}
else if ( ( V_7 != 0 ) && ( V_7 % 25 == 0 ) )
{
V_15 = V_14 ;
}
else
{
V_15 = V_10 ;
}
F_5 ( V_2 -> V_20 , V_21 , V_22 ) ;
F_9 ( V_2 -> V_20 , V_23 ) ;
if ( V_9 & V_36 )
{
F_10 ( V_2 -> V_20 , V_23 , L_3 ) ;
}
if ( V_9 & V_35 )
{
F_10 ( V_2 -> V_20 , V_23 , L_4 ) ;
}
else
{
F_11 ( V_2 -> V_20 , V_23 , L_5 , ( int ) V_7 ) ;
}
if ( V_8 != 0 )
{
F_11 ( V_2 -> V_20 , V_23 , L_6 , ( int ) V_8 ) ;
}
{
T_6 * V_16 ;
V_16 = F_3 ( V_3 , V_17 , V_1 , 0 , - 1 , V_18 ) ;
F_12 ( V_16 , F_13 ( V_1 , 0 ) , TRUE ) ;
F_14 ( V_16 , ( int ) V_7 , L_7 ) ;
{
T_3 * V_37 ;
V_37 = F_15 ( V_16 , V_38 ) ;
{
T_1 * V_39 ;
T_6 * V_40 ;
V_39 = F_16 ( V_1 , 0 , V_41 , V_41 ) ;
V_40 = F_3 ( V_37 , V_42 , V_39 , 0 , - 1 , V_18 ) ;
F_12 ( V_40 , F_13 ( V_39 , 0 ) , FALSE ) ;
{
T_3 * V_43 ;
V_43 = F_15 ( V_40 , V_38 ) ;
{
T_6 * V_44 ;
if ( V_9 & V_26 )
{
V_44 = F_3 ( V_43 , V_45 , V_39 , 0 , 1 , V_46 ) ;
F_17 ( V_2 , V_44 , & V_47 ) ;
}
F_3 ( V_43 , V_48 , V_39 , 0 , 1 , V_46 ) ;
F_3 ( V_43 , V_49 , V_39 , 0 , 1 , V_46 ) ;
V_44 = F_3 ( V_43 , V_50 , V_39 , 0 , 1 , V_46 ) ;
if ( V_9 & V_27 )
{
F_17 ( V_2 , V_44 , & V_51 ) ;
}
V_44 = F_3 ( V_43 , V_52 , V_39 , 1 , 1 , V_46 ) ;
if ( V_9 & V_28 )
{
F_17 ( V_2 , V_44 , & V_53 ) ;
}
V_44 = F_3 ( V_43 , V_54 , V_39 , 1 , 1 , V_46 ) ;
if ( V_9 & V_32 )
{
F_4 ( V_2 , V_44 , & V_55 ,
L_8 ,
( int ) V_5 ) ;
}
if ( V_9 & V_33 )
{
F_4 ( V_2 , V_44 , & V_55 ,
L_9 ,
( int ) V_6 ) ;
}
if ( V_9 & V_34 )
{
F_4 ( V_2 , V_44 , & V_55 ,
L_10 ,
( int ) V_6 ) ;
}
F_3 ( V_43 , V_56 , V_39 , 2 , 2 , V_46 ) ;
}
}
}
}
if ( V_9 & V_35 )
{
F_4 ( V_2 , V_16 , & V_55 ,
L_11 ) ;
}
else if ( V_7 == 0 )
{
F_17 ( V_2 , V_16 , & V_57 ) ;
}
else
{
T_3 * V_37 ;
V_37 = F_15 ( V_16 , V_38 ) ;
{
T_6 * V_40 ;
T_1 * V_39 ;
V_39 = F_16 ( V_1 , V_41 , V_7 , V_7 ) ;
V_40 = F_3 ( V_37 , V_58 , V_39 , 0 , - 1 , V_18 ) ;
F_14 ( V_40 , ( int ) V_7 , L_7 ) ;
{
T_3 * V_43 ;
const char * V_59 ;
switch( V_15 )
{
case V_11 :
V_59 = L_12 ;
break;
case V_12 :
V_59 = L_13 ;
break;
case V_13 :
V_59 = L_14 ;
break;
case V_14 :
V_59 = L_15 ;
break;
case V_10 :
default:
V_59 = L_16 ;
break;
}
F_18 ( V_40 , L_17 , V_59 ) ;
V_43 = F_15 ( V_40 , V_38 ) ;
F_19 ( V_60 , V_39 , V_2 , V_43 ) ;
V_40 = F_20 ( V_43 , V_61 , V_39 , 0 , 0
, ( int ) V_7 ) ;
F_21 ( V_40 ) ;
}
}
}
if ( V_8 > 0 )
{
T_3 * V_37 ;
V_37 = F_15 ( V_16 , V_38 ) ;
{
T_1 * V_39 ;
V_39 = F_16 ( V_1 , V_41 + V_7 , V_8 , - 1 ) ;
F_19 ( V_62 , V_39 , V_2 , V_37 ) ;
}
}
}
return;
}
static
void F_22 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
F_1 ( V_1 , V_2 , V_3 , V_24 ) ;
return;
}
static
void F_23 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
F_1 ( V_1 , V_2 , V_3 , V_25 ) ;
return;
}
void F_24 ( void )
{
static T_7 V_63 [] = {
{ & V_42 , { L_18 , L_19
, V_64 , V_65 , NULL
, 0 , NULL , V_66 } } ,
{ & V_45 , { L_20 , L_21
, V_67 , V_68 , NULL
, 0xf0 , NULL , V_66 } } ,
{ & V_48 , { L_22 , L_23
, V_67 , V_68 , F_25 ( V_69 )
, 0x08 , NULL , V_66 } } ,
{ & V_49 , { L_24 , L_25
, V_67 , V_68 , F_25 ( V_70 )
, 0x04 , NULL , V_66 } } ,
{ & V_50 , { L_26 , L_27
, V_67 , V_68 , NULL
, 0x03 , NULL , V_66 } } ,
{ & V_52 , { L_28 , L_29
, V_67 , V_68 , F_25 ( V_71 )
, 0xc0 , NULL , V_66 } } ,
{ & V_54 , { L_30 , L_31
, V_67 , V_68 , NULL
, 0x3f , NULL , V_66 } } ,
{ & V_56 , { L_32 , L_33
, V_72 , V_68 , NULL
, 0 , NULL , V_66 } } ,
{ & V_58 , { L_34 , L_35
, V_73 , V_65 , NULL
, 0 , NULL , V_66 } } ,
{ & V_61 , { L_36 , L_37
, V_74 , V_68 , NULL
, 0 , NULL , V_66 } }
} ;
static T_5 * V_75 [] = {
& V_38
} ;
static T_8 V_76 [] = {
{ & V_19 , { L_38 , V_77 , V_78 , L_1 , V_79 } } ,
{ & V_47 , { L_39 , V_77 , V_78 , L_40 , V_79 } } ,
{ & V_51 , { L_41 , V_77 , V_78 , L_42 , V_79 } } ,
{ & V_53 , { L_43 , V_77 , V_78 , L_44 , V_79 } } ,
{ & V_55 , { L_45 , V_77 , V_78 , L_46 , V_79 } } ,
{ & V_57 , { L_47 , V_80 , V_81 , L_48 , V_79 } } ,
} ;
T_9 * V_82 ;
V_17 = F_26 ( V_83 , V_22 , L_49 ) ;
F_27 ( V_17 , V_63 , F_28 ( V_63 ) ) ;
F_29 ( V_75 , F_28 ( V_75 ) ) ;
V_82 = F_30 ( V_17 ) ;
F_31 ( V_82 , V_76 , F_28 ( V_76 ) ) ;
F_32 ( L_50 , F_22 , V_17 ) ;
F_32 ( L_51 , F_23 , V_17 ) ;
return;
}
void F_33 ( void )
{
V_60 = F_34 ( L_52 ) ;
V_62 = F_34 ( L_53 ) ;
F_35 ( L_54 , V_84 , F_34 ( L_50 ) ) ;
F_36 ( L_55 , F_34 ( L_51 ) ) ;
}
