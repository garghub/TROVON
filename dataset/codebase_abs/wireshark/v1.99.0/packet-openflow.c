static T_1
F_1 ( T_2 * T_3 V_1 , T_4 * V_2 , int V_3 )
{
return F_2 ( V_2 , V_3 + 2 ) ;
}
static int
F_3 ( T_4 * V_2 , T_2 * T_3 , T_5 * V_4 , void * T_6 V_1 )
{
T_1 V_3 = 0 ;
T_7 V_5 ;
T_8 * V_6 ;
V_5 = F_4 ( V_2 , 0 ) ;
F_5 ( T_3 -> V_7 , V_8 , L_1 ) ;
F_6 ( T_3 -> V_7 , V_9 ) ;
switch( V_5 ) {
case V_10 :
F_7 ( V_11 , V_2 , T_3 , V_4 ) ;
break;
case V_12 :
F_7 ( V_13 , V_2 , T_3 , V_4 ) ;
break;
case V_14 :
F_7 ( V_15 , V_2 , T_3 , V_4 ) ;
break;
default:
V_6 = F_8 ( V_4 , V_16 , V_2 , V_3 , 1 , V_17 ) ;
F_9 ( T_3 , V_6 , & V_18 ) ;
break;
}
return F_10 ( V_2 ) ;
}
static int
F_11 ( T_4 * V_2 , T_2 * T_3 , T_5 * V_4 , void * T_6 )
{
F_12 ( V_2 , T_3 , V_4 , V_19 , V_20 ,
F_1 , F_3 , T_6 ) ;
return F_13 ( V_2 ) ;
}
static T_9
F_14 ( T_4 * V_2 , T_2 * T_3 ,
T_5 * V_4 , void * T_6 )
{
T_10 * V_21 = NULL ;
if ( ! V_22 ) {
return FALSE ;
}
if ( ( T_3 -> V_23 != V_24 ) &&
( T_3 -> V_23 != V_25 ) &&
( T_3 -> V_23 != V_26 ) &&
( T_3 -> V_23 != ( V_27 ) V_28 ) ) {
return FALSE ;
}
V_21 = F_15 ( T_3 ) ;
F_16 ( V_21 , V_29 ) ;
F_11 ( V_2 , T_3 , V_4 , T_6 ) ;
return TRUE ;
}
void
F_17 ( void )
{
static T_11 V_30 [] = {
{ & V_16 ,
{ L_2 , L_3 ,
V_31 , V_32 , F_18 ( V_33 ) , 0x7f ,
NULL , V_34 }
}
} ;
static T_12 V_35 [] = {
{ & V_18 , { L_4 , V_36 , V_37 , L_5 , V_38 } } ,
} ;
T_13 * V_39 ;
T_14 * V_40 ;
V_41 = F_19 ( L_1 ,
L_6 , L_6 ) ;
F_20 ( L_6 , F_11 , V_41 ) ;
F_21 ( V_41 , V_30 , F_22 ( V_30 ) ) ;
V_40 = F_23 ( V_41 ) ;
F_24 ( V_40 , V_35 , F_22 ( V_35 ) ) ;
V_39 = F_25 ( V_41 , V_42 ) ;
F_26 ( V_39 , L_7 , L_8 ,
L_9 ,
10 , & V_28 ) ;
F_27 ( V_39 , L_10 ,
L_11 ,
L_12
L_13
L_14 ,
& V_22 ) ;
F_27 ( V_39 , L_15 ,
L_16 ,
L_17
L_18 ,
& V_19 ) ;
}
void
V_42 ( void )
{
static T_9 V_43 = FALSE ;
static int V_44 ;
if ( ! V_43 ) {
V_29 = F_28 ( F_11 , V_41 ) ;
F_29 ( L_19 , F_14 , V_41 ) ;
V_43 = TRUE ;
} else {
F_30 ( L_7 , V_44 , V_29 ) ;
}
V_44 = V_28 ;
F_31 ( L_7 , V_44 , V_29 ) ;
V_11 = F_32 ( L_20 ) ;
V_13 = F_32 ( L_21 ) ;
V_15 = F_32 ( L_22 ) ;
}
