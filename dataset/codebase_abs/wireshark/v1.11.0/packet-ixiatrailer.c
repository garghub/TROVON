static int
F_1 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * V_3 , void * T_5 V_2 )
{
T_4 * V_4 ;
T_6 V_5 , V_6 , V_7 ;
T_4 * V_8 = NULL ;
T_6 V_9 = 0 ;
T_7 V_10 , V_11 ;
T_8 V_12 ;
T_9 V_13 ;
V_5 = F_2 ( V_1 ) ;
if ( V_5 < 5 ) {
return 0 ;
}
if ( V_5 == 19 ) {
V_5 = 15 ;
}
if ( F_3 ( V_1 , V_5 - 4 ) != V_14 ) {
return 0 ;
}
V_6 = F_4 ( V_1 , V_5 - 5 ) ;
if ( ( V_5 - 5 ) != V_6 ) {
return 0 ;
}
V_10 = F_3 ( V_1 , V_5 - 2 ) ;
V_12 . V_15 = V_6 + 3 ;
V_12 . V_16 = F_5 ( V_1 , V_9 , V_12 . V_15 ) ;
V_11 = F_6 ( & V_12 , 1 ) ;
if ( F_7 ( & V_11 ) != V_10 ) {
return 0 ;
}
V_4 = F_8 ( V_3 , V_17 , V_1 , V_9 , V_6 + 5 , V_18 ) ;
if ( V_19 ) {
F_9 ( V_4 , L_1 , V_6 , V_10 ) ;
}
V_8 = F_10 ( V_4 , V_20 ) ;
V_13 = F_4 ( V_1 , V_9 ++ ) ;
V_7 = F_4 ( V_1 , V_9 ++ ) ;
switch ( V_13 ) {
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
if ( V_7 != 8 ) {
F_11 ( T_3 , V_4 , & V_26 , L_2 , V_7 ) ;
break;
}
V_4 = F_8 ( V_8 , V_27 , V_1 , V_9 , V_7 , V_28 | V_29 ) ;
F_9 ( V_4 , L_3 , F_12 ( V_13 , V_30 , L_4 ) ) ;
break;
default:
V_4 = F_8 ( V_8 , V_31 , V_1 , V_9 , V_7 , V_18 ) ;
F_9 ( V_4 , L_5 , V_13 , V_7 ) ;
break;
}
return V_5 ;
}
void
F_13 ( void )
{
static T_10 V_32 [] = {
{ & V_27 , {
L_6 , L_7 , V_33 , V_34 ,
NULL , 0x0 , NULL , V_35 } } ,
{ & V_31 , {
L_8 , L_9 , V_36 , V_37 ,
NULL , 0x0 , NULL , V_35 } } ,
} ;
static T_11 * V_38 [] = {
& V_20
} ;
static T_12 V_39 [] = {
{ & V_26 , { L_10 , V_40 , V_41 , L_11 , V_42 } } ,
} ;
T_13 * V_43 ;
T_14 * V_44 ;
V_17 = F_14 ( L_12 , L_13 , L_14 ) ;
F_15 ( V_17 , V_32 , F_16 ( V_32 ) ) ;
F_17 ( V_38 , F_16 ( V_38 ) ) ;
V_44 = F_18 ( V_17 ) ;
F_19 ( V_44 , V_39 , F_16 ( V_39 ) ) ;
V_43 = F_20 ( V_17 , NULL ) ;
F_21 ( V_43 , L_15 ,
L_16 ,
L_17 ,
& V_19 ) ;
}
void
F_22 ( void )
{
F_23 ( L_18 , F_1 , V_17 ) ;
}
