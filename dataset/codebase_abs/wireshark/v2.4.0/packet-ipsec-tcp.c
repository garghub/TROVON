static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 V_3 )
{
if (
F_2 ( V_1 , V_3 + 0 ) != 0 ||
( F_3 ( V_1 , V_3 + 6 ) & 0xfff ) != 0 ||
( F_4 ( V_1 , V_3 + 13 ) != 17 &&
F_4 ( V_1 , V_3 + 13 ) != 50 )
) {
return FALSE ;
}
if( F_5 ( V_1 , V_2 ) ) {
return FALSE ;
}
return TRUE ;
}
static int
F_6 ( T_1 * V_1 , T_2 * V_2 , T_4 * V_4 , void * T_5 V_5 )
{
T_4 * V_6 = NULL ;
T_4 * V_7 = NULL ;
T_6 * V_8 = NULL ;
T_6 * V_9 = NULL ;
T_1 * V_10 ;
T_3 V_11 = F_7 ( V_1 ) ;
T_3 V_3 ;
T_7 V_12 ;
F_8 ( V_2 -> V_13 , V_14 , L_1 ) ;
F_9 ( V_2 -> V_13 , V_15 ) ;
if ( F_2 ( V_1 , 0 ) == 0x01f401f4 ) {
V_12 = V_16 ;
} else {
V_12 = V_17 ;
}
if ( V_4 ) {
V_8 = F_10 ( V_4 , V_18 , V_1 , 0 , - 1 , V_19 ) ;
V_6 = F_11 ( V_8 , V_20 ) ;
V_3 = V_11 - V_21 ;
V_9 = F_10 ( V_6 , V_22 , V_1 ,
V_3 , V_21 , V_19 ) ;
V_7 = F_11 ( V_9 , V_23 ) ;
F_10 ( V_7 , V_24 , V_1 , V_3 + 0 , 4 , V_19 ) ;
F_10 ( V_7 , V_25 , V_1 , V_3 + 4 , 2 , V_26 ) ;
if ( V_12 == V_16 ) {
F_10 ( V_7 , V_27 , V_1 , V_3 + 6 , 2 , V_26 ) ;
} else {
F_10 ( V_7 , V_28 , V_1 , V_3 + 6 , 2 , V_26 ) ;
}
F_10 ( V_7 , V_29 , V_1 , V_3 + 8 , 5 , V_19 ) ;
F_10 ( V_7 , V_30 , V_1 , V_3 + 13 , 1 , V_26 ) ;
F_10 ( V_7 , V_31 , V_1 , V_3 + 14 , 2 , V_19 ) ;
}
V_10 = F_12 ( V_1 , 0 , V_11 - V_21 , - 1 ) ;
if ( V_12 == V_16 ) {
F_13 ( V_32 , V_10 , V_2 , V_4 ) ;
} else {
F_13 ( V_33 , V_10 , V_2 , V_4 ) ;
}
return F_14 ( V_1 ) ;
}
static T_8
F_15 ( T_1 * V_1 , T_2 * V_2 , T_4 * V_4 , void * T_5 )
{
T_3 V_11 = F_7 ( V_1 ) ;
T_3 V_34 = F_14 ( V_1 ) ;
if ( V_11 <= V_21 + 8 ||
( V_11 - V_34 ) > ( V_21 - 13 ) ||
! F_1 ( V_1 , V_2 , V_11 - V_21 ) ) {
return FALSE ;
}
F_6 ( V_1 , V_2 , V_4 , T_5 ) ;
return TRUE ;
}
void
F_16 ( void )
{
static T_9 V_35 [] = {
{ & V_22 ,
{ L_2 , L_3 , V_36 , V_37 , NULL ,
0x0 , NULL , V_38 } } ,
{ & V_24 ,
{ L_4 , L_5 , V_36 , V_37 , NULL ,
0x0 , NULL , V_38 } } ,
{ & V_25 ,
{ L_6 , L_7 , V_39 , V_40 , NULL ,
0x0 , NULL , V_38 } } ,
{ & V_28 ,
{ L_8 , L_9 , V_39 , V_40 , NULL ,
0x0 , NULL , V_38 } } ,
{ & V_27 ,
{ L_10 , L_11 , V_39 , V_40 , F_17 ( V_41 ) ,
0x0 , NULL , V_38 } } ,
{ & V_29 ,
{ L_12 , L_13 , V_36 , V_37 , NULL ,
0x0 , NULL , V_38 } } ,
{ & V_30 ,
{ L_14 , L_15 , V_42 , V_40 , F_17 ( V_43 ) ,
0x0 , NULL , V_38 } } ,
{ & V_31 ,
{ L_16 , L_17 , V_36 , V_37 , NULL ,
0x0 , NULL , V_38 } } ,
} ;
static T_10 * V_44 [] = {
& V_20 ,
& V_23 ,
} ;
V_18 = F_18 ( L_18 , L_1 , L_19 ) ;
F_19 ( V_18 , V_35 , F_20 ( V_35 ) ) ;
F_21 ( V_44 , F_20 ( V_44 ) ) ;
}
void
F_22 ( void )
{
T_11 V_45 ;
V_45 = F_23 ( F_6 , V_18 ) ;
V_33 = F_24 ( L_20 , V_18 ) ;
V_32 = F_24 ( L_21 , V_18 ) ;
F_25 ( L_22 , F_15 , L_18 , L_23 , V_18 , V_46 ) ;
F_26 ( L_24 , V_45 ) ;
}
