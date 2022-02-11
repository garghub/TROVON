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
T_7 * V_14 = NULL ;
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
static void
F_14 ( T_3 * V_2 , T_5 * V_6 , T_6 * V_8 )
{
T_9 * V_27 ;
T_6 * V_11 = NULL ;
T_10 V_3 ;
T_10 V_5 = F_3 ( V_2 ) ;
V_27 = ( T_9 * ) V_6 -> V_27 ;
F_6 ( V_6 -> V_12 , V_28 , L_6 ) ;
if ( V_8 )
{
T_7 * V_14 = NULL ;
V_14 = F_7 ( V_8 , V_15 , V_2 , 0 , - 1 , L_7 ) ;
V_11 = F_8 ( V_14 , V_16 ) ;
}
switch ( V_27 -> V_29 )
{
case V_30 :
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
F_15 ( V_2 , V_6 , V_11 , V_3 , V_5 - V_3 , V_31 ) ;
}
}
static void
F_16 ( void )
{
F_17 ( & V_24 ,
& V_32 ) ;
}
void
F_18 ( void )
{
static T_11 V_33 [] = {
{ & V_17 ,
{ L_8 , L_9 , V_34 , V_35 ,
NULL , 0xF0 , NULL , V_36 } } ,
{ & V_19 ,
{ L_10 , L_11 , V_34 , V_35 ,
F_19 ( V_37 ) , 0x0F , NULL , V_36 } } ,
{ & V_20 ,
{ L_12 , L_13 , V_38 , V_35 ,
NULL , 0 , NULL , V_36 } } ,
{ & V_39 ,
{ L_14 , L_15 ,
V_40 , V_41 , NULL , 0x00 , NULL , V_36 } } ,
{ & V_42 ,
{ L_16 , L_17 ,
V_43 , V_41 , NULL , 0x00 , NULL , V_36 } } ,
{ & V_44 ,
{ L_18 , L_19 ,
V_45 , 0 , NULL , 0x00 , NULL , V_36 } } ,
{ & V_46 ,
{ L_20 ,
L_21 ,
V_45 , 0 , NULL , 0x00 , NULL , V_36 } } ,
{ & V_47 ,
{ L_22 ,
L_23 ,
V_45 , 0 , NULL , 0x00 , NULL , V_36 } } ,
{ & V_48 ,
{ L_24 , L_25 ,
V_45 , 0 , NULL , 0x00 , NULL , V_36 } } ,
{ & V_49 ,
{ L_26 , L_27 ,
V_43 , V_41 , NULL , 0x00 , NULL , V_36 } } ,
{ & V_50 ,
{ L_28 , L_29 ,
V_51 , V_52 , NULL , 0x00 , NULL , V_36 } } ,
{ & V_53 ,
{ L_30 , L_31 ,
V_43 , V_41 , NULL , 0x00 , NULL , V_36 } } ,
{ & V_54 ,
{ L_32 , L_33 ,
V_51 , V_52 , NULL , 0x00 , NULL , V_36 } } ,
{ & V_55 ,
{ L_34 , L_35 ,
V_56 , V_41 , NULL , 0x00 , NULL , V_36 } } ,
} ;
static T_4 * V_57 [] = {
& V_16 ,
& V_58 ,
& V_59
} ;
V_15 = F_20 ( L_7 , L_6 , L_36 ) ;
F_21 ( V_15 , V_33 , F_22 ( V_33 ) ) ;
F_23 ( V_57 , F_22 ( V_57 ) ) ;
F_24 ( & F_16 ) ;
F_25 ( L_36 , F_14 , V_15 ) ;
}
void
F_26 ( void )
{
T_12 V_60 ;
V_60 = F_27 ( L_36 ) ;
F_28 ( L_37 , V_61 , V_60 ) ;
V_26 = F_27 ( L_38 ) ;
}
