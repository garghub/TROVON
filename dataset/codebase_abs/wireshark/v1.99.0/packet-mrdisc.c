static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , int V_4 )
{
T_4 V_5 ;
F_2 ( V_3 , V_6 , V_1 , V_4 , 1 , V_7 ) ;
V_4 += 1 ;
F_3 ( V_3 , V_1 , V_8 , V_9 , V_2 , 0 ) ;
V_4 += 2 ;
V_4 += 2 ;
V_5 = F_4 ( V_1 , V_4 ) ;
F_5 ( V_3 , V_10 , V_1 ,
V_4 , 2 , V_5 ) ;
V_4 += 2 ;
while ( V_5 -- ) {
T_3 * V_11 ;
T_5 * V_12 ;
T_6 type , V_13 ;
int V_14 = V_4 ;
V_12 = F_2 ( V_3 , V_15 ,
V_1 , V_4 , - 1 , V_16 ) ;
V_11 = F_6 ( V_12 , V_17 ) ;
type = F_7 ( V_1 , V_4 ) ;
F_5 ( V_11 , V_18 , V_1 , V_4 , 1 , type ) ;
V_4 += 1 ;
V_13 = F_7 ( V_1 , V_4 ) ;
F_5 ( V_11 , V_19 , V_1 , V_4 , 1 , V_13 ) ;
V_4 += 1 ;
switch ( type ) {
case V_20 :
if ( V_12 ) {
F_8 ( V_12 , L_1 ,
F_9 ( type , V_21 , L_2 ) ,
F_4 ( V_1 , V_4 ) ) ;
}
if ( V_13 != 2 )
F_10 ( V_22 ) ;
F_2 ( V_11 , V_23 , V_1 , V_4 , V_13 ,
V_7 ) ;
V_4 += V_13 ;
break;
case V_24 :
if ( V_12 ) {
F_8 ( V_12 , L_1 ,
F_9 ( type , V_21 , L_2 ) ,
F_4 ( V_1 , V_4 ) ) ;
}
if ( V_13 != 2 )
F_10 ( V_22 ) ;
F_2 ( V_11 , V_25 , V_1 , V_4 , V_13 ,
V_7 ) ;
V_4 += V_13 ;
break;
default:
if ( V_12 ) {
F_8 ( V_12 , L_3 ) ;
}
F_2 ( V_11 , V_26 ,
V_1 , V_4 , V_13 , V_16 ) ;
V_4 += V_13 ;
}
if ( V_12 ) {
F_11 ( V_12 , V_4 - V_14 ) ;
}
}
return V_4 ;
}
static int
F_12 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , int V_4 )
{
V_4 += 1 ;
F_3 ( V_3 , V_1 , V_8 , V_9 , V_2 , 0 ) ;
V_4 += 2 ;
return V_4 ;
}
int
F_13 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , int V_4 )
{
T_3 * V_11 ;
T_5 * V_12 ;
T_6 type ;
if ( ! F_14 ( F_15 ( V_27 ) ) ) {
return V_4 + F_16 ( V_1 , V_4 ) ;
}
V_12 = F_2 ( V_3 , V_27 , V_1 , V_4 , 0 , V_16 ) ;
V_11 = F_6 ( V_12 , V_28 ) ;
F_17 ( V_2 -> V_29 , V_30 , L_4 ) ;
F_18 ( V_2 -> V_29 , V_31 ) ;
type = F_7 ( V_1 , V_4 ) ;
F_19 ( V_2 -> V_29 , V_31 ,
F_9 ( type , V_32 ,
L_5 ) ) ;
F_5 ( V_11 , V_33 , V_1 , V_4 , 1 , type ) ;
V_4 += 1 ;
switch ( type ) {
case V_34 :
V_4 = F_1 ( V_1 , V_2 , V_11 , V_4 ) ;
break;
case V_35 :
case V_36 :
V_4 = F_12 ( V_1 , V_2 , V_11 , V_4 ) ;
break;
}
return V_4 ;
}
void
F_20 ( void )
{
static T_7 V_37 [] = {
{ & V_33 ,
{ L_6 , L_7 , V_38 , V_39 ,
F_21 ( V_32 ) , 0 , L_8 , V_40 } } ,
{ & V_8 ,
{ L_9 , L_10 , V_41 , V_39 ,
NULL , 0 , L_11 , V_40 } } ,
{ & V_9 ,
{ L_12 , L_13 , V_42 , V_43 ,
NULL , 0x0 , L_14 , V_40 } } ,
{ & V_6 ,
{ L_15 , L_16 , V_38 , V_44 ,
NULL , 0 , L_17 , V_40 } } ,
{ & V_10 ,
{ L_18 , L_19 , V_41 , V_44 ,
NULL , 0 , L_20 , V_40 } } ,
{ & V_15 ,
{ L_21 , L_22 , V_45 , V_43 ,
NULL , 0 , L_23 , V_40 } } ,
{ & V_18 ,
{ L_24 , L_25 , V_38 , V_44 ,
F_21 ( V_21 ) , 0 , L_26 , V_40 } } ,
{ & V_19 ,
{ L_27 , L_28 , V_38 , V_44 ,
NULL , 0 , L_29 , V_40 } } ,
{ & V_23 ,
{ L_30 , L_31 , V_41 , V_44 ,
NULL , 0 , L_32 , V_40 } } ,
{ & V_25 ,
{ L_33 , L_34 , V_41 , V_44 ,
NULL , 0 , L_35 , V_40 } } ,
{ & V_26 ,
{ L_36 , L_37 , V_46 , V_43 ,
NULL , 0 , L_38 , V_40 } } ,
} ;
static T_8 * V_47 [] = {
& V_28 ,
& V_17 ,
} ;
V_27 = F_22 ( L_39 ,
L_4 , L_40 ) ;
F_23 ( V_27 , V_37 , F_24 ( V_37 ) ) ;
F_25 ( V_47 , F_24 ( V_47 ) ) ;
}
