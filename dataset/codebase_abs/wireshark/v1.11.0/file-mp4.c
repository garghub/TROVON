static T_1
F_1 ( T_2 * V_1 , T_1 V_2 , T_1 T_3 V_3 ,
T_4 * T_5 V_3 , T_6 * V_4 )
{
T_1 V_5 ;
V_5 = V_2 ;
F_2 ( V_4 , V_6 ,
V_1 , V_2 , 1 , V_7 ) ;
V_2 += 1 ;
V_2 += 3 ;
return V_2 - V_5 ;
}
static T_1
F_3 ( T_2 * V_1 , T_1 V_2 , T_1 T_3 V_3 ,
T_4 * T_5 V_3 , T_6 * V_4 )
{
T_1 V_5 ;
V_5 = V_2 ;
F_2 ( V_4 , V_6 ,
V_1 , V_2 , 1 , V_7 ) ;
V_2 += 1 ;
V_2 += 3 ;
F_2 ( V_4 , V_8 ,
V_1 , V_2 , 4 , V_7 ) ;
V_2 += 4 ;
return V_2 - V_5 ;
}
static T_1
F_4 ( T_2 * V_1 , T_1 V_2 , T_1 T_3 ,
T_4 * T_5 V_3 , T_6 * V_4 )
{
T_1 V_5 ;
V_5 = V_2 ;
F_2 ( V_4 , V_9 ,
V_1 , V_2 , 4 , V_10 | V_11 ) ;
V_2 += 4 ;
F_2 ( V_4 , V_12 ,
V_1 , V_2 , 4 , V_7 ) ;
V_2 += 4 ;
while ( ( V_2 - V_5 ) < T_3 ) {
F_2 ( V_4 , V_13 ,
V_1 , V_2 , 4 , V_10 | V_11 ) ;
V_2 += 4 ;
}
return V_2 - V_5 ;
}
static T_1
F_5 ( T_7 T_8 V_3 ,
T_2 * V_1 , T_1 V_2 , T_4 * T_5 , T_6 * V_4 )
{
T_1 V_5 ;
T_9 V_14 ;
T_7 V_15 ;
T_10 * V_16 ;
T_11 * V_17 , * V_18 , * V_19 = NULL ;
T_6 * V_20 ;
T_1 V_21 ;
T_1 V_22 ;
V_5 = V_2 ;
V_14 = ( T_9 ) F_6 ( V_1 , V_2 ) ;
if ( ( V_14 != V_23 ) && ( V_14 < V_24 ) )
return - 1 ;
V_15 = F_6 ( V_1 , V_2 + 4 ) ;
V_16 = F_7 ( F_8 () , V_1 , V_2 + 4 , 4 ) ;
V_17 = F_9 ( V_4 , V_1 , V_2 , - 1 , L_1 ,
F_10 ( V_15 , V_25 , L_2 ) , V_16 ) ;
V_20 = F_11 ( V_17 , V_26 ) ;
V_18 = F_2 ( V_20 , V_27 ,
V_1 , V_2 , 4 , V_7 ) ;
if ( V_14 == V_23 )
F_12 ( V_18 , L_3 ) ;
V_2 += 4 ;
F_2 ( V_20 , V_28 ,
V_1 , V_2 , 4 , V_10 | V_11 ) ;
V_2 += 4 ;
if ( V_14 == V_23 ) {
V_14 = F_13 ( V_1 , V_2 ) ;
V_19 = F_2 ( V_20 , V_29 ,
V_1 , V_2 , 8 , V_7 ) ;
V_2 += 8 ;
}
if ( V_14 > V_30 ) {
F_14 ( T_5 , V_19 , & V_31 ) ;
return - 1 ;
}
F_15 ( V_17 , ( T_1 ) V_14 ) ;
V_22 = ( T_1 ) V_14 - ( V_2 - V_5 ) ;
switch ( V_15 ) {
case V_32 :
F_4 ( V_1 , V_2 , V_22 , T_5 , V_20 ) ;
break;
case V_33 :
F_1 ( V_1 , V_2 , V_22 , T_5 , V_20 ) ;
break;
case V_34 :
F_3 ( V_1 , V_2 , V_22 , T_5 , V_20 ) ;
break;
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
while ( V_2 - V_5 < ( T_1 ) V_14 ) {
V_21 = F_5 ( V_15 , V_1 , V_2 , T_5 , V_20 ) ;
if ( V_21 <= 0 )
break;
V_2 += V_21 ;
}
break;
default:
break;
}
return ( T_1 ) V_14 ;
}
static int
F_16 ( T_2 * V_1 , T_4 * T_5 , T_6 * V_4 , void * T_12 V_3 )
{
T_1 V_2 = 0 ;
T_7 V_15 ;
T_11 * V_45 ;
T_6 * V_46 ;
T_1 V_21 ;
if ( F_17 ( V_1 ) < V_24 )
return 0 ;
V_15 = F_6 ( V_1 , 4 ) ;
if ( F_18 ( V_15 , V_25 ) == NULL )
return 0 ;
F_19 ( T_5 -> V_47 , V_48 , L_4 ) ;
F_20 ( T_5 -> V_47 , V_49 ) ;
V_45 = F_21 ( V_4 , V_50 ,
V_1 , 0 , ( T_1 ) F_17 ( V_1 ) , L_4 ) ;
V_46 = F_11 ( V_45 , V_51 ) ;
while ( F_22 ( V_1 , V_2 ) > 0 ) {
V_21 = F_5 ( V_52 , V_1 , V_2 , T_5 , V_46 ) ;
if ( V_21 <= 0 )
break;
V_2 += V_21 ;
}
return V_2 ;
}
void
F_23 ( void )
{
static T_13 V_53 [] = {
{ & V_27 ,
{ L_5 , L_6 , V_54 , V_55 ,
NULL , 0 , NULL , V_56 } } ,
{ & V_28 ,
{ L_7 , L_8 , V_57 , V_58 ,
NULL , 0 , NULL , V_56 } } ,
{ & V_29 ,
{ L_9 , L_10 , V_59 , V_55 ,
NULL , 0 , NULL , V_56 } } ,
{ & V_6 ,
{ L_11 , L_12 , V_60 , V_55 ,
NULL , 0 , NULL , V_56 } } ,
{ & V_9 ,
{ L_13 , L_14 , V_57 , V_58 ,
NULL , 0 , NULL , V_56 } } ,
{ & V_12 ,
{ L_15 , L_16 , V_54 , V_55 ,
NULL , 0 , NULL , V_56 } } ,
{ & V_13 ,
{ L_17 , L_18 , V_57 ,
V_58 , NULL , 0 , NULL , V_56 } } ,
{ & V_8 ,
{ L_19 , L_20 , V_54 ,
V_55 , NULL , 0 , NULL , V_56 } }
} ;
static T_1 * V_61 [] = {
& V_51 ,
& V_26
} ;
static T_14 V_62 [] = {
{ & V_31 ,
{ L_21 , V_63 , V_64 ,
L_22 , V_65 } }
} ;
T_15 * V_66 ;
V_50 = F_24 ( L_23 , L_24 , L_24 ) ;
F_25 ( V_50 , V_53 , F_26 ( V_53 ) ) ;
F_27 ( V_61 , F_26 ( V_61 ) ) ;
V_66 = F_28 ( V_50 ) ;
F_29 ( V_66 , V_62 , F_26 ( V_62 ) ) ;
}
void
F_30 ( void )
{
T_16 V_67 = F_31 ( F_16 , V_50 ) ;
F_32 ( L_25 , L_26 , V_67 ) ;
}
