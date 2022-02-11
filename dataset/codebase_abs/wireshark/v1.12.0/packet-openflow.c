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
V_5 = F_4 ( V_2 , 0 ) ;
F_5 ( T_3 -> V_6 , V_7 , L_1 ) ;
F_6 ( T_3 -> V_6 , V_8 ) ;
switch( V_5 ) {
case V_9 :
F_7 ( V_10 , V_2 , T_3 , V_4 ) ;
break;
case V_11 :
F_7 ( V_12 , V_2 , T_3 , V_4 ) ;
break;
case V_13 :
F_7 ( V_14 , V_2 , T_3 , V_4 ) ;
break;
default:
F_8 ( V_4 , V_15 , V_2 , V_3 , 1 , V_16 ) ;
F_9 ( V_4 , V_2 , V_3 , - 1 , L_2 ) ;
break;
}
return F_10 ( V_2 ) ;
}
static int
F_11 ( T_4 * V_2 , T_2 * T_3 , T_5 * V_4 , void * T_6 )
{
F_12 ( V_2 , T_3 , V_4 , V_17 , V_18 ,
F_1 , F_3 , T_6 ) ;
return F_13 ( V_2 ) ;
}
static T_8
F_14 ( T_4 * V_2 , T_2 * T_3 ,
T_5 * V_4 , void * T_6 )
{
T_9 * V_19 = NULL ;
if ( ! V_20 ) {
return FALSE ;
}
if ( ( T_3 -> V_21 != V_22 ) &&
( T_3 -> V_21 != V_23 ) &&
( T_3 -> V_21 != V_24 ) &&
( T_3 -> V_21 != ( V_25 ) V_26 ) ) {
return FALSE ;
}
V_19 = F_15 ( T_3 ) ;
F_16 ( V_19 , V_27 ) ;
F_11 ( V_2 , T_3 , V_4 , T_6 ) ;
return TRUE ;
}
void
F_17 ( void )
{
static T_10 V_28 [] = {
{ & V_15 ,
{ L_3 , L_4 ,
V_29 , V_30 , F_18 ( V_31 ) , 0x7f ,
NULL , V_32 }
}
} ;
T_11 * V_33 ;
V_34 = F_19 ( L_1 ,
L_5 , L_5 ) ;
F_20 ( L_5 , F_11 , V_34 ) ;
F_21 ( V_34 , V_28 , F_22 ( V_28 ) ) ;
V_33 = F_23 ( V_34 , V_35 ) ;
F_24 ( V_33 , L_6 , L_7 ,
L_8 ,
10 , & V_26 ) ;
F_25 ( V_33 , L_9 ,
L_10 ,
L_11
L_12
L_13 ,
& V_20 ) ;
F_25 ( V_33 , L_14 ,
L_15 ,
L_16
L_17 ,
& V_17 ) ;
}
void
V_35 ( void )
{
static T_8 V_36 = FALSE ;
static int V_37 ;
if ( ! V_36 ) {
V_27 = F_26 ( F_11 , V_34 ) ;
F_27 ( L_18 , F_14 , V_34 ) ;
V_36 = TRUE ;
} else {
F_28 ( L_6 , V_37 , V_27 ) ;
}
V_37 = V_26 ;
F_29 ( L_6 , V_37 , V_27 ) ;
V_10 = F_30 ( L_19 ) ;
V_12 = F_30 ( L_20 ) ;
V_14 = F_30 ( L_21 ) ;
}
