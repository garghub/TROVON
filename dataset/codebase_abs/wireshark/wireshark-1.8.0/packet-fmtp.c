static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 V_4 ;
T_5 V_5 ;
T_1 * V_6 ;
T_6 * V_7 = NULL ;
T_3 * V_8 = NULL ;
V_4 = F_2 ( V_1 , 4 ) ;
V_5 = F_3 ( V_1 , 2 ) ;
F_4 ( V_2 -> V_9 , V_10 , L_1 ) ;
F_5 ( V_2 -> V_9 , V_11 ) ;
V_7 = F_6 ( V_3 , V_12 , V_1 , 0 , - 1 , V_13 ) ;
F_7 ( V_7 , L_2 ,
F_8 ( V_4 , V_14 , L_3 ) ) ;
switch ( V_4 ) {
case V_15 :
F_7 ( V_7 , L_4 ,
F_9 ( V_1 , V_16 , V_5 - V_16 ) ) ;
F_10 ( V_2 -> V_9 , V_11 , L_5 ,
F_8 ( V_4 , V_14 , L_3 ) ,
F_9 ( V_1 , V_16 , V_5 - V_16 ) ) ;
break;
case V_17 :
F_7 ( V_7 , L_4 ,
F_9 ( V_1 , V_16 , V_5 - V_16 ) ) ;
F_10 ( V_2 -> V_9 , V_11 , L_5 ,
F_8 ( V_4 , V_14 , L_3 ) ,
F_8 ( F_3 ( V_1 , V_16 ) , V_18 , L_3 ) ) ;
break;
default:
F_10 ( V_2 -> V_9 , V_11 , L_6 ,
F_8 ( V_4 , V_14 , L_3 ) ) ;
break;
}
if ( V_3 ) {
V_8 = F_11 ( V_7 , V_19 ) ;
F_6 ( V_8 , V_20 , V_1 , 0 , 1 , V_21 ) ;
F_6 ( V_8 , V_22 , V_1 , 1 , 1 , V_21 ) ;
F_6 ( V_8 , V_23 , V_1 , 2 , 2 , V_21 ) ;
F_6 ( V_8 , V_24 , V_1 , 4 , 1 , V_21 ) ;
V_6 = F_12 ( V_1 , V_16 ) ;
F_13 ( V_25 , V_6 , V_2 , V_8 ) ;
}
}
static T_7
F_14 ( T_2 * V_2 V_26 , T_1 * V_1 , int V_27 )
{
return ( T_7 ) F_3 ( V_1 , V_27 + 2 ) ;
}
static T_8
F_15 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
if ( F_2 ( V_1 , 0 ) != 0x02 ) return ( FALSE ) ;
if ( F_2 ( V_1 , 1 ) != 0x00 ) return ( FALSE ) ;
if ( F_3 ( V_1 , 2 ) > V_28 ) return ( FALSE ) ;
if ( ( F_2 ( V_1 , 4 ) < 0x01 ) || ( F_2 ( V_1 , 4 ) > 0x04 ) )
return ( FALSE ) ;
F_16 ( V_1 , V_2 , V_3 , TRUE , V_16 ,
F_14 , F_1 ) ;
return ( TRUE ) ;
}
void
F_17 ( void )
{
static T_9 V_29 [] = {
{ & V_20 ,
{ L_7 , L_8 ,
V_30 , V_31 ,
NULL , 0x0 ,
NULL , V_32 }
} ,
{ & V_22 ,
{ L_9 , L_10 ,
V_30 , V_31 ,
NULL , 0x0 ,
NULL , V_32 }
} ,
{ & V_23 ,
{ L_11 , L_12 ,
V_33 , V_31 ,
NULL , 0x0 ,
NULL , V_32 }
} ,
{ & V_24 ,
{ L_13 , L_14 ,
V_30 , V_31 ,
F_18 ( V_14 ) , 0x0 ,
NULL , V_32 }
}
} ;
static T_10 * V_34 [] = {
& V_19
} ;
V_12 = F_19 (
L_15 ,
L_1 ,
L_16 ) ;
F_20 ( V_12 , V_29 , F_21 ( V_29 ) ) ;
F_22 ( V_34 , F_21 ( V_34 ) ) ;
}
void
F_23 ( void )
{
F_24 ( L_17 , F_15 , V_12 ) ;
V_25 = F_25 ( L_18 ) ;
}
