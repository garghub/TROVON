static inline T_1
F_1 ( T_2 V_1 )
{
return ( V_1 == 0x04 || V_1 == 0x05 || V_1 == 0x06 || V_1 == 0x07 ) ;
}
static T_1
F_2 ( T_3 * V_2 , T_4 V_3 )
{
T_1 V_4 = TRUE ;
T_4 V_5 = F_3 ( V_2 ) ;
V_3 += 4 ;
while ( V_3 < V_5 )
{
T_2 V_1 = F_4 ( V_2 , V_3 ) ;
V_1 &= 0x0F ;
if ( F_1 ( V_1 ) )
{
V_4 = FALSE ;
break;
}
V_3 += 4 ;
}
return V_4 ;
}
static void
F_5 ( T_3 * V_2 , T_5 * V_6 ,
T_6 * V_7 , T_6 * V_8 ,
T_4 V_3 )
{
T_2 V_1 ;
T_2 V_9 ;
T_1 V_10 ;
T_6 * V_11 = NULL ;
F_6 ( V_6 -> V_12 , V_13 , L_1 ) ;
V_1 = F_4 ( V_2 , V_3 ) ;
V_9 = ( V_1 & 0xF0 ) >> 4 ;
V_1 &= 0x0F ;
if ( V_8 )
{
T_7 * V_14 ;
V_14 = F_7 ( V_7 , V_15 , V_2 , V_3 , 4 , L_2 ) ;
V_11 = F_8 ( V_14 , V_16 ) ;
F_9 ( V_11 , V_17 , V_2 , V_3 , 1 , V_18 ) ;
F_9 ( V_11 , V_19 , V_2 , V_3 , 1 , V_18 ) ;
F_9 ( V_11 , V_20 , V_2 , V_3 + 1 , 3 , V_18 ) ;
}
V_10 = V_6 -> V_21 ;
if ( F_1 ( V_1 ) )
{
T_3 * V_22 = NULL ;
T_8 * V_23 = NULL ;
V_6 -> V_21 = TRUE ;
if ( V_1 == 0x04 )
{
V_23 = F_10 ( & V_24 ,
V_2 , V_3 + 1 ,
V_6 ,
V_9 ,
NULL ,
3 ,
TRUE ) ;
}
else
{
V_23 = F_10 ( & V_24 ,
V_2 , V_3 + 1 ,
V_6 ,
V_9 ,
NULL ,
( T_4 ) ( V_1 - 4 ) ,
FALSE ) ;
}
if ( F_2 ( V_2 , V_3 ) )
{
V_22 = F_11 ( V_2 , V_3 + 1 , V_6 ,
L_3 , V_23 , & V_25 ,
NULL , V_7 ) ;
if ( V_1 != 0x04 ) {
F_12 ( V_6 -> V_12 , V_13 ,
L_4 ) ;
} else {
F_12 ( V_6 -> V_12 , V_13 ,
L_5 ) ;
}
if ( V_22 )
{
F_13 ( V_26 , V_22 , V_6 , V_8 ) ;
}
}
}
V_6 -> V_21 = V_10 ;
}
static T_4
F_14 ( T_3 * V_2 , T_5 * V_6 V_27 ,
T_6 * V_11 , void * T_9 V_27 )
{
T_4 V_3 = 0 ;
T_2 V_28 ;
T_2 V_29 ;
T_7 * V_30 = NULL ;
T_6 * V_31 ;
V_28 = F_4 ( V_2 , V_3 ) ;
V_29 = F_4 ( V_2 , V_3 + 1 ) ;
if ( V_29 == V_32 ) {
V_30 = F_15 ( V_11 , V_2 , V_3 , V_28 ,
L_6 ) ;
}
else if ( V_29 == V_33 ) {
V_30 = F_15 ( V_11 , V_2 , V_3 , V_28 ,
L_7 ) ;
}
else
return 0 ;
V_31 = F_8 ( V_30 , V_34 ) ;
F_16 ( V_31 , V_2 , V_3 ,
& V_35 ) ;
return V_28 ;
}
static int
F_17 ( T_3 * V_2 , T_5 * V_6 , T_6 * V_8 , void * T_9 )
{
T_10 * V_36 ;
T_6 * V_11 = NULL ;
T_11 V_3 ;
T_11 V_5 = F_3 ( V_2 ) ;
if ( T_9 == NULL )
return 0 ;
V_36 = ( T_10 * ) T_9 ;
F_6 ( V_6 -> V_12 , V_37 , L_8 ) ;
if ( V_8 )
{
T_7 * V_14 ;
V_14 = F_7 ( V_8 , V_15 , V_2 , 0 , - 1 , L_9 ) ;
V_11 = F_8 ( V_14 , V_16 ) ;
}
switch ( V_36 -> V_38 )
{
case V_39 :
V_3 = 0 ;
F_6 ( V_6 -> V_12 , V_13 , L_1 ) ;
while ( V_3 < V_5 )
{
F_5 ( V_2 , V_6 , V_11 , V_8 , V_3 ) ;
V_3 += 4 ;
}
break;
default:
V_3 = 0 ;
F_18 ( V_11 , V_6 , & V_40 , V_2 , V_3 , V_5 - V_3 ) ;
}
return F_3 ( V_2 ) ;
}
static void
F_19 ( void )
{
F_20 ( & V_24 ,
& V_41 ) ;
}
void
F_21 ( void )
{
static T_12 V_42 [] = {
{ & V_17 ,
{ L_10 , L_11 , V_43 , V_44 ,
NULL , 0xF0 , NULL , V_45 } } ,
{ & V_19 ,
{ L_12 , L_13 , V_43 , V_44 ,
F_22 ( V_46 ) , 0x0F , NULL , V_45 } } ,
{ & V_20 ,
{ L_14 , L_15 , V_47 , V_44 ,
NULL , 0 , NULL , V_45 } } ,
{ & V_48 ,
{ L_16 , L_17 ,
V_49 , V_50 , NULL , 0x00 , NULL , V_45 } } ,
{ & V_51 ,
{ L_18 , L_19 ,
V_52 , V_50 , NULL , 0x00 , NULL , V_45 } } ,
{ & V_53 ,
{ L_20 , L_21 ,
V_54 , 0 , NULL , 0x00 , NULL , V_45 } } ,
{ & V_55 ,
{ L_22 ,
L_23 ,
V_54 , 0 , NULL , 0x00 , NULL , V_45 } } ,
{ & V_56 ,
{ L_24 ,
L_25 ,
V_54 , 0 , NULL , 0x00 , NULL , V_45 } } ,
{ & V_57 ,
{ L_26 , L_27 ,
V_54 , 0 , NULL , 0x00 , NULL , V_45 } } ,
{ & V_58 ,
{ L_28 , L_29 ,
V_52 , V_50 , NULL , 0x00 , NULL , V_45 } } ,
{ & V_59 ,
{ L_30 , L_31 ,
V_60 , V_61 , NULL , 0x00 , NULL , V_45 } } ,
{ & V_62 ,
{ L_32 , L_33 ,
V_52 , V_50 , NULL , 0x00 , NULL , V_45 } } ,
{ & V_63 ,
{ L_34 , L_35 ,
V_60 , V_61 , NULL , 0x00 , NULL , V_45 } } ,
{ & V_64 ,
{ L_36 , L_37 ,
V_65 , V_50 , NULL , 0x00 , NULL , V_45 } } ,
} ;
static T_4 * V_66 [] = {
& V_16 ,
& V_34 ,
& V_67 ,
& V_68
} ;
static T_13 V_69 [] = {
{ & V_40 , { L_38 , V_70 , V_71 , L_39 , V_72 } } ,
} ;
T_14 * V_73 ;
V_15 = F_23 ( L_9 , L_8 , L_40 ) ;
F_24 ( V_15 , V_42 , F_25 ( V_42 ) ) ;
F_26 ( V_66 , F_25 ( V_66 ) ) ;
V_73 = F_27 ( V_15 ) ;
F_28 ( V_73 , V_69 , F_25 ( V_69 ) ) ;
F_29 ( & F_19 ) ;
F_30 ( L_40 , F_17 , V_15 ) ;
}
void
F_31 ( void )
{
T_15 V_74 , V_75 ;
V_75 = F_32 (
F_14 , V_15 ) ;
F_33 ( L_41 , V_76 , V_75 ) ;
V_74 = F_34 ( L_40 ) ;
F_33 ( L_42 , V_76 , V_74 ) ;
V_26 = F_34 ( L_43 ) ;
}
