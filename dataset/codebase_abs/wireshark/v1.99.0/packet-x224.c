static int
F_1 ( T_1 * T_2 V_1 , T_3 * V_2 , T_4 * V_3 , int V_4 , T_5 * T_6 V_1 )
{
T_7 V_5 , V_6 ;
V_4 += 2 ;
F_2 ( V_2 , V_7 , V_3 , V_4 , 2 , V_8 ) ;
V_4 += 2 ;
F_2 ( V_2 , V_9 , V_3 , V_4 , 1 , V_8 ) ;
V_4 += 1 ;
if( F_3 ( V_3 , V_4 ) > 0 ) {
V_5 = F_4 ( V_3 , V_4 , - 1 , & V_6 , TRUE ) ;
F_2 ( V_2 , V_10 , V_3 , V_4 , V_5 ,
V_11 | V_12 ) ;
V_4 = V_6 ;
}
return V_4 ;
}
static int
F_5 ( T_1 * T_2 V_1 , T_3 * V_2 , T_4 * V_3 , int V_4 , T_5 * T_6 )
{
T_8 V_13 ;
F_2 ( V_2 , V_14 , V_3 , V_4 , 2 , V_8 ) ;
V_4 += 2 ;
F_2 ( V_2 , V_7 , V_3 , V_4 , 2 , V_8 ) ;
V_4 += 2 ;
V_13 = F_6 ( V_3 , V_4 ) ;
F_2 ( V_2 , V_9 , V_3 , V_4 , 1 , V_8 ) ;
T_6 -> V_13 = V_13 ;
V_4 += 1 ;
return V_4 ;
}
static int
F_7 ( T_1 * T_2 V_1 , T_3 * V_2 , T_4 * V_3 , int V_4 , T_5 * T_6 , T_3 * V_15 )
{
T_9 * V_16 = NULL ;
T_4 * V_17 ;
switch ( T_6 -> V_13 >> 4 ) {
case 2 :
case 3 :
case 4 :
F_2 ( V_2 , V_14 , V_3 , V_4 , 2 , V_8 ) ;
V_4 += 2 ;
break;
}
V_16 = F_8 ( V_2 , V_9 , V_3 , 0 , 0 , T_6 -> V_13 ) ;
F_9 ( V_16 ) ;
F_2 ( V_2 , V_18 , V_3 , V_4 , 1 , V_8 ) ;
F_2 ( V_2 , V_19 , V_3 , V_4 , 1 , V_8 ) ;
V_4 += 1 ;
V_17 = F_10 ( V_3 , V_4 ) ;
F_11 ( V_20 , V_17 , T_2 , V_15 ) ;
return V_4 ;
}
static int
F_12 ( T_4 * V_3 , T_1 * T_2 , T_3 * V_15 , void * T_10 V_1 )
{
T_3 * V_2 = NULL ;
T_9 * V_16 = NULL ;
int V_4 = 0 ;
T_8 V_21 , V_22 ;
T_11 * V_23 ;
T_5 * T_6 ;
F_13 ( T_2 -> V_24 , V_25 , L_1 ) ;
F_14 ( T_2 -> V_24 , V_26 ) ;
V_22 = F_6 ( V_3 , V_4 ) ;
if ( V_15 ) {
V_16 = F_2 ( V_15 , V_27 , V_3 , V_4 , V_22 + 1 , V_12 ) ;
V_2 = F_15 ( V_16 , V_28 ) ;
}
F_2 ( V_2 , V_29 , V_3 , V_4 , 1 , V_8 ) ;
V_4 += 1 ;
V_21 = F_6 ( V_3 , V_4 ) ;
F_2 ( V_2 , V_30 , V_3 , V_4 , 1 , V_8 ) ;
V_4 += 1 ;
F_16 ( T_2 -> V_24 , V_26 , L_2 ,
F_17 ( V_21 >> 4 , V_31 , L_3 ) ,
V_21 ) ;
V_23 = F_18 ( T_2 ) ;
T_6 = ( T_5 * ) F_19 ( V_23 , V_27 ) ;
if ( ! T_6 ) {
T_6 = F_20 ( F_21 () , T_5 ) ;
T_6 -> V_13 = 0 ;
F_22 ( V_23 , V_27 , T_6 ) ;
}
switch ( V_21 >> 4 ) {
case V_32 :
V_4 = F_1 ( T_2 , V_2 , V_3 , V_4 , T_6 ) ;
break;
case V_33 :
V_4 = F_5 ( T_2 , V_2 , V_3 , V_4 , T_6 ) ;
break;
case V_34 :
break;
case V_35 :
break;
case V_36 :
V_4 = F_7 ( T_2 , V_2 , V_3 , V_4 , T_6 , V_15 ) ;
break;
case V_37 :
break;
case V_38 :
break;
case V_39 :
break;
case V_40 :
break;
case V_41 :
break;
}
return V_4 ;
}
void
F_23 ( void )
{
static T_12 V_42 [] =
{
{ & V_29 , {
L_4 , L_5 , V_43 , V_44 ,
NULL , 0 , NULL , V_45 } } ,
{ & V_30 , {
L_6 , L_7 , V_43 , V_46 ,
F_24 ( V_31 ) , 0xf0 , NULL , V_45 } } ,
{ & V_7 , {
L_8 , L_9 , V_47 , V_46 ,
NULL , 0 , NULL , V_45 } } ,
{ & V_14 , {
L_10 , L_11 , V_47 , V_46 ,
NULL , 0 , NULL , V_45 } } ,
{ & V_9 , {
L_12 , L_13 , V_43 , V_46 ,
F_24 ( V_48 ) , 0xf0 , NULL , V_45 } } ,
{ & V_10 , {
L_14 , L_15 , V_49 , V_50 , NULL , 0 ,
L_16 , V_45 } } ,
{ & V_19 , {
L_17 , L_18 , V_43 , V_46 ,
NULL , 0x7f , NULL , V_45 } } ,
{ & V_18 , {
L_19 , L_20 , V_51 , 8 ,
NULL , 0x80 , NULL , V_45 } } ,
} ;
static T_7 * V_52 [] =
{
& V_28 ,
} ;
V_27 = F_25 ( L_21 , L_1 , L_22 ) ;
F_26 ( V_27 , V_42 , F_27 ( V_42 ) ) ;
F_28 ( V_52 , F_27 ( V_52 ) ) ;
F_29 ( L_22 , F_12 , V_27 ) ;
}
void
F_30 ( void )
{
V_20 = F_31 ( L_23 ) ;
}
