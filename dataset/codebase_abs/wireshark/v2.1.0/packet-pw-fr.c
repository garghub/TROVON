static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 V_5 ;
T_5 V_6 ;
T_5 V_7 ;
const int V_8 = 4 ;
enum {
V_9 = 0x001
, V_10 = 0x002
, V_11 = 0x004
, V_12 = 0x008
, V_13 = 0x010
, V_14 = 0x020
};
int V_15 ;
V_5 = F_2 ( V_1 , 0 ) ;
if ( V_5 < V_8 )
{
{
T_6 * V_16 ;
V_16 = F_3 ( V_3 , V_17 , V_1 , 0 , - 1 , V_18 ) ;
F_4 ( V_2 , V_16 , & V_19 ,
L_1 ,
( int ) V_5 , ( int ) V_8 ) ;
}
F_5 ( V_2 -> V_20 , V_21 , L_2 ) ;
F_5 ( V_2 -> V_20 , V_22 , L_3 ) ;
return 1 ;
}
if ( F_6 ( V_1 , V_2 , V_3 ) )
{
return F_7 ( V_1 ) ;
}
V_15 = 0 ;
if ( 0 != ( F_8 ( V_1 , 0 ) & 0xf0 ) )
{
V_15 |= V_9 + V_10 ;
}
{
int V_23 ;
T_5 V_24 ;
V_23 = F_8 ( V_1 , 1 ) & 0x3f ;
V_24 = V_5 - V_8 ;
V_6 = V_24 ;
V_7 = 0 ;
if ( V_24 < 64 )
{
T_5 V_25 ;
V_25 = V_23 ;
if ( V_25 == 0 )
{
V_15 |= V_9 + V_13 ;
}
else if ( V_25 > V_24 )
{
V_15 |= V_9 + V_11 ;
}
else
{
V_6 = V_25 ;
V_7 = V_24 - V_25 ;
}
}
else
{
if ( V_23 != 0 )
{
V_15 |= V_9 + V_12 ;
}
}
}
if ( V_6 == 0 )
{
V_15 |= V_14 ;
}
F_5 ( V_2 -> V_20 , V_21 , L_2 ) ;
F_9 ( V_2 -> V_20 , V_22 ) ;
if ( V_15 & V_9 )
{
F_5 ( V_2 -> V_20 , V_22 , L_4 ) ;
}
F_10 ( V_2 -> V_20 , V_22 , L_5 , ( int ) V_6 ) ;
if ( V_7 != 0 )
{
F_10 ( V_2 -> V_20 , V_22 , L_6 , ( int ) V_7 ) ;
}
{
T_3 * V_26 ;
T_6 * V_27 ;
T_6 * V_16 ;
V_27 = F_3 ( V_3 , V_17 , V_1 , 0 , 4 , V_18 ) ;
F_11 ( V_27 , L_7 V_28 L_8 , F_12 ( V_1 , 0 ) ) ;
V_26 = F_13 ( V_27 , V_29 ) ;
if ( V_15 & V_10 )
{
V_16 = F_3 ( V_26 , V_30 , V_1 , 0 , 1 , V_31 ) ;
F_14 ( V_2 , V_16 , & V_32 ) ;
}
F_3 ( V_26 , V_33 , V_1 , 0 , 1 , V_31 ) ;
F_3 ( V_26 , V_34 , V_1 , 0 , 1 , V_31 ) ;
F_3 ( V_26 , V_35 , V_1 , 0 , 1 , V_31 ) ;
F_3 ( V_26 , V_36 , V_1 , 0 , 1 , V_31 ) ;
F_3 ( V_26 , V_37 , V_1 , 1 , 1 , V_31 ) ;
V_16 = F_3 ( V_26 , V_38 , V_1 , 1 , 1 , V_31 ) ;
if ( V_15 & V_11 )
{
F_4 ( V_2 , V_16 , & V_39 ,
L_9 ,
( int ) V_6 ) ;
}
if ( V_15 & V_13 )
{
F_4 ( V_2 , V_16 , & V_39 ,
L_10 ,
( int ) ( V_6 + V_8 ) ) ;
}
if ( V_15 & V_12 )
{
F_4 ( V_2 , V_16 , & V_39 ,
L_11 ,
( int ) ( V_6 + V_8 ) ) ;
}
F_3 ( V_26 , V_40 , V_1 , 2 , 2 , V_31 ) ;
if ( V_7 > 0 )
{
F_3 ( V_26 , V_41 , V_1 ,
V_8 + V_6 , V_7 , V_18 ) ;
}
if ( V_15 & V_14 )
{
F_4 ( V_2 , V_27 , & V_39 ,
L_12 ) ;
}
}
if ( V_6 > 0 )
{
T_1 * V_42 ;
V_42 = F_15 ( V_1 , V_8 , V_6 ) ;
F_16 ( V_43 , V_42 , V_2 , V_3 ) ;
}
return F_7 ( V_1 ) ;
}
void
F_17 ( void )
{
static T_7 V_44 [] = {
{ & V_30 , { L_13 , L_14 , V_45 , V_46
, NULL , 0xf0 , NULL
, V_47 } } ,
{ & V_33 , { L_15 , L_16 , V_45 , V_48
, NULL , 0x08 , L_17
, V_47 } } ,
{ & V_34 , { L_18 , L_19 , V_45 , V_48
, NULL , 0x04 , L_20
, V_47 } } ,
{ & V_35 , { L_21 , L_22 , V_45 , V_48
, NULL , 0x02 , L_23
, V_47 } } ,
{ & V_36 , { L_24 , L_25 , V_45 , V_48
, NULL , 0x01 , L_26
, V_47 } } ,
{ & V_37 , { L_27 , L_28 , V_45 , V_48
, F_18 ( V_49 ) , 0xc0 , NULL
, V_47 } } ,
{ & V_38 , { L_29 , L_30 , V_45 , V_48
, NULL , 0x3f , NULL
, V_47 } } ,
{ & V_40 , { L_31 , L_30 , V_50 , V_48
, NULL , 0 , NULL
, V_47 } } ,
{ & V_41 , { L_32 , L_33 , V_51 , V_52
, NULL , 0 , NULL
, V_47 } }
} ;
static T_5 * V_53 [] = {
& V_29
} ;
static T_8 V_54 [] = {
{ & V_19 , { L_34 , V_55 , V_56 , L_35 , V_57 } } ,
{ & V_32 , { L_36 , V_55 , V_56 , L_37 , V_57 } } ,
{ & V_39 , { L_38 , V_55 , V_56 , L_39 , V_57 } } ,
} ;
T_9 * V_58 ;
V_17 = F_19 ( L_40 ,
L_41 ,
L_42 ) ;
F_20 ( V_17 , V_44 , F_21 ( V_44 ) ) ;
F_22 ( V_53 , F_21 ( V_53 ) ) ;
V_58 = F_23 ( V_17 ) ;
F_24 ( V_58 , V_54 , F_21 ( V_54 ) ) ;
}
void
F_25 ( void )
{
T_10 V_59 ;
V_59 = F_26 ( F_1 , V_17 ) ;
F_27 ( L_43 , V_59 ) ;
V_43 = F_28 ( L_44 , V_17 ) ;
}
