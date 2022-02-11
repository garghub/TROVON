static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 V_5 ;
T_6 V_6 ;
T_1 * V_7 ;
T_7 * V_8 = NULL ;
T_3 * V_9 = NULL ;
V_5 = F_2 ( V_1 , 4 ) ;
V_6 = F_3 ( V_1 , 2 ) ;
F_4 ( V_2 -> V_10 , V_11 , L_1 ) ;
F_5 ( V_2 -> V_10 , V_12 ) ;
V_8 = F_6 ( V_3 , V_13 , V_1 , 0 , - 1 , V_14 ) ;
F_7 ( V_8 , L_2 ,
F_8 ( V_5 , V_15 , L_3 ) ) ;
switch ( V_5 ) {
case V_16 :
F_7 ( V_8 , L_4 ,
F_9 ( F_10 () , V_1 , V_17 , V_6 - V_17 , V_18 ) ) ;
F_11 ( V_2 -> V_10 , V_12 , L_5 ,
F_8 ( V_5 , V_15 , L_3 ) ,
F_9 ( F_10 () , V_1 , V_17 , V_6 - V_17 , V_18 ) ) ;
break;
case V_19 :
F_7 ( V_8 , L_4 ,
F_9 ( F_10 () , V_1 , V_17 , V_6 - V_17 , V_18 ) ) ;
F_11 ( V_2 -> V_10 , V_12 , L_5 ,
F_8 ( V_5 , V_15 , L_3 ) ,
F_8 ( F_3 ( V_1 , V_17 ) , V_20 , L_3 ) ) ;
break;
default:
F_11 ( V_2 -> V_10 , V_12 , L_6 ,
F_8 ( V_5 , V_15 , L_3 ) ) ;
break;
}
if ( V_3 ) {
V_9 = F_12 ( V_8 , V_21 ) ;
F_6 ( V_9 , V_22 , V_1 , 0 , 1 , V_14 ) ;
F_6 ( V_9 , V_23 , V_1 , 1 , 1 , V_14 ) ;
F_6 ( V_9 , V_24 , V_1 , 2 , 2 , V_25 ) ;
F_6 ( V_9 , V_26 , V_1 , 4 , 1 , V_14 ) ;
V_7 = F_13 ( V_1 , V_17 ) ;
F_14 ( V_27 , V_7 , V_2 , V_9 ) ;
}
return F_15 ( V_1 ) ;
}
static T_8
F_16 ( T_2 * V_2 V_4 , T_1 * V_1 , int V_28 )
{
return ( T_8 ) F_3 ( V_1 , V_28 + 2 ) ;
}
static T_9
F_17 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 )
{
if ( F_2 ( V_1 , 0 ) != 0x02 ) return ( FALSE ) ;
if ( F_2 ( V_1 , 1 ) != 0x00 ) return ( FALSE ) ;
if ( F_3 ( V_1 , 2 ) > V_29 ) return ( FALSE ) ;
if ( ( F_2 ( V_1 , 4 ) < 0x01 ) || ( F_2 ( V_1 , 4 ) > 0x04 ) )
return ( FALSE ) ;
F_18 ( V_1 , V_2 , V_3 , TRUE , V_17 ,
F_16 , F_1 , T_4 ) ;
return ( TRUE ) ;
}
void
F_19 ( void )
{
static T_10 V_30 [] = {
{ & V_22 ,
{ L_7 , L_8 ,
V_31 , V_32 ,
NULL , 0x0 ,
NULL , V_33 }
} ,
{ & V_23 ,
{ L_9 , L_10 ,
V_31 , V_32 ,
NULL , 0x0 ,
NULL , V_33 }
} ,
{ & V_24 ,
{ L_11 , L_12 ,
V_34 , V_32 ,
NULL , 0x0 ,
NULL , V_33 }
} ,
{ & V_26 ,
{ L_13 , L_14 ,
V_31 , V_32 ,
F_20 ( V_15 ) , 0x0 ,
NULL , V_33 }
}
} ;
static T_11 * V_35 [] = {
& V_21
} ;
V_13 = F_21 (
L_15 ,
L_1 ,
L_16 ) ;
F_22 ( V_13 , V_30 , F_23 ( V_30 ) ) ;
F_24 ( V_35 , F_23 ( V_35 ) ) ;
}
void
F_25 ( void )
{
F_26 ( L_17 , F_17 , V_13 ) ;
V_27 = F_27 ( L_18 ) ;
}
