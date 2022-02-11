static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 V_5 = 0 , type , V_6 ;
T_3 * V_7 ;
T_6 * V_8 ;
V_8 = F_2 ( V_3 , V_1 , V_5 , - 1 , L_1 ) ;
V_7 = F_3 ( V_8 , V_9 ) ;
F_4 ( V_7 , V_1 , 0 , & V_10 ) ;
type = F_5 ( V_1 , 1 ) ;
switch ( type ) {
case V_11 :
V_6 = F_5 ( V_1 , 2 ) ;
F_6 ( V_7 , V_12 , V_1 , 2 , 1 , V_6 ) ;
switch ( V_6 ) {
case 0x00 :
F_7 ( V_7 , V_13 , V_1 , 3 , 2 , V_14 ) ;
V_5 = 5 ;
break;
case 0x1b :
case 0x1c :
V_5 = F_8 ( V_15 , V_1 , V_2 , V_7 , NULL ) ;
break;
default:
break;
}
break;
case V_16 :
default:
break;
}
if ( F_9 ( V_1 , V_5 ) != 0 ) {
F_7 ( V_7 , V_17 , V_1 , V_5 , - 1 , V_18 ) ;
}
return F_10 ( V_1 ) ;
}
static int
F_11 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_7 * V_19 ;
T_3 * V_7 ;
T_6 * V_8 ;
T_8 V_5 = 0 ;
V_19 = ( T_7 * ) V_2 -> V_19 ;
F_12 ( V_2 -> V_20 , V_21 , L_2 ) ;
V_8 = F_7 ( V_3 , V_22 , V_1 , 0 , - 1 , V_18 ) ;
V_7 = F_3 ( V_8 , V_9 ) ;
if ( V_19 ) {
V_8 = F_6 ( V_7 , V_23 , V_1 , 0 , 0 ,
V_19 -> V_24 ) ;
F_13 ( V_8 ) ;
switch ( V_19 -> V_24 )
{
case V_25 :
V_5 = F_8 ( V_26 , V_1 , V_2 , V_3 , NULL ) ;
break;
default:
break;
}
}
if ( F_9 ( V_1 , V_5 ) != 0 ) {
F_7 ( V_7 , V_27 , V_1 , V_5 , - 1 , V_18 ) ;
}
return F_10 ( V_1 ) ;
}
static int
F_14 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_7 * V_19 ;
V_19 = ( T_7 * ) V_2 -> V_19 ;
if ( V_19 ) {
switch ( V_19 -> V_28 )
{
case 0x01 :
case 0x02 :
return F_8 ( V_29 , V_1 , V_2 , V_3 , NULL ) ;
break;
default:
break;
}
}
return F_8 ( V_30 , V_1 , V_2 , V_3 , NULL ) ;
}
void
F_15 ( void )
{
static T_9 V_31 [] = {
{ & V_12 ,
{ L_3 , L_4 , V_32 , V_33 | V_34 ,
& V_35 , 0 , NULL , V_36 } } ,
{ & V_13 ,
{ L_5 , L_6 , V_37 , V_33 ,
NULL , 0 , NULL , V_36 } } ,
{ & V_17 ,
{ L_7 , L_8 , V_38 , V_39 ,
NULL , 0 , NULL , V_36 } } ,
{ & V_23 ,
{ L_9 , L_10 , V_32 , V_33 ,
F_16 ( V_40 ) , 0 , NULL , V_36 } } ,
{ & V_27 ,
{ L_7 , L_11 , V_38 , V_39 ,
NULL , 0 , NULL , V_36 } }
} ;
static T_8 * V_41 [] = {
& V_9
} ;
V_22 = F_17 ( L_12 , L_2 , L_13 ) ;
F_18 ( V_22 , V_31 , F_19 ( V_31 ) ) ;
F_20 ( V_41 , F_19 ( V_41 ) ) ;
}
void
F_21 ( void )
{
T_10 V_42 , V_43 , V_44 ;
V_42 = F_22 ( F_1 , V_22 ) ;
F_23 ( L_14 , V_45 , V_42 ) ;
V_43 = F_22 ( F_11 , V_22 ) ;
F_23 ( L_15 , V_45 , V_43 ) ;
V_44 = F_22 ( F_14 , V_22 ) ;
F_23 ( L_16 , V_46 , V_44 ) ;
V_26 = F_24 ( L_17 ) ;
V_15 = F_24 ( L_18 ) ;
V_29 = F_24 ( L_19 ) ;
V_30 = F_24 ( L_20 ) ;
}
