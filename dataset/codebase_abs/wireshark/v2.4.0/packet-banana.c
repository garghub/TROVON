static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , int V_4 ) {
T_4 * V_5 ;
T_3 * V_6 ;
T_5 V_7 = 0 ;
T_6 V_8 = 0 ;
T_7 V_9 = 0 ;
int V_10 = V_4 ;
int V_11 ;
int V_12 ;
while ( F_2 ( V_1 , V_4 ) > 0 ) {
V_7 = F_3 ( V_1 , V_4 ) ;
V_4 ++ ;
if ( V_7 & 0x80 ) {
if ( F_4 ( V_7 ) ) {
break;
} else {
F_5 ( V_2 , NULL , & V_13 , L_1 , V_7 ) ;
}
} else {
V_9 ++ ;
if ( V_9 > V_14 ) {
F_6 ( V_2 , NULL , & V_15 ) ;
}
V_8 += V_7 + ( V_8 << 7 ) ;
}
}
switch ( V_7 ) {
case V_16 :
if ( V_8 > V_17 ) {
F_5 ( V_2 , NULL , & V_18 , L_2 V_19 L_3 , V_8 ) ;
}
V_5 = F_7 ( V_3 , V_20 , V_1 , V_10 , V_4 - V_10 - 1 , ( V_21 ) V_8 , L_4 , ( T_7 ) V_8 ) ;
V_6 = F_8 ( V_5 , V_22 ) ;
for ( V_12 = 0 ; V_12 < V_8 ; V_12 ++ ) {
V_11 = V_4 ;
V_4 += F_1 ( V_1 , V_2 , V_6 , V_4 ) ;
if ( V_4 <= V_11 ) {
return V_4 - V_10 ;
}
}
break;
case V_23 :
if ( V_8 > V_17 ) {
F_5 ( V_2 , NULL , & V_24 , L_5 V_19 L_6 , V_8 ) ;
}
F_9 ( V_3 , V_25 , V_1 , V_10 , V_4 - V_10 , ( V_21 ) V_8 ) ;
break;
case V_26 :
if ( V_8 > V_17 ) {
F_5 ( V_2 , NULL , & V_18 , L_7 V_19 L_3 , V_8 ) ;
}
F_10 ( V_3 , V_27 , V_1 , V_4 , ( V_21 ) V_8 , V_28 | V_29 ) ;
V_4 += ( T_7 ) V_8 ;
break;
case V_30 :
if ( V_8 > V_17 ) {
F_5 ( V_2 , NULL , & V_24 , L_8 V_19 L_6 , V_8 ) ;
}
F_11 ( V_3 , V_31 , V_1 , V_10 , V_4 - V_10 , ( V_32 ) V_8 * - 1 ) ;
break;
case V_33 :
F_10 ( V_3 , V_34 , V_1 , V_4 , 8 , V_35 ) ;
V_4 += 8 ;
break;
case V_36 :
F_10 ( V_3 , V_37 , V_1 , V_10 , V_4 - V_10 , V_29 ) ;
break;
case V_38 :
F_10 ( V_3 , V_39 , V_1 , V_10 , V_4 - V_10 , V_29 ) ;
break;
case V_40 :
if ( V_9 > 1 ) {
F_6 ( V_2 , NULL , & V_41 ) ;
}
F_10 ( V_3 , V_42 , V_1 , V_4 - 2 , 1 , V_35 ) ;
break;
default:
return 0 ;
break;
}
return V_4 - V_10 ;
}
static int
F_12 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_8 V_43 ) {
T_5 V_7 = 0 ;
T_7 V_4 = 0 , V_11 ;
T_4 * V_5 ;
T_3 * V_44 ;
if ( F_13 ( V_1 ) < 2 )
return 0 ;
F_14 ( V_2 -> V_45 , V_46 , L_9 ) ;
while ( F_2 ( V_1 , V_4 ) > 0 && V_4 < V_14 ) {
V_7 = F_3 ( V_1 , V_4 ) ;
if ( F_4 ( V_7 ) )
break;
V_4 ++ ;
}
F_15 ( V_2 -> V_45 , V_47 , L_10 ,
F_16 ( V_7 , V_48 , L_11 ) ) ;
V_5 = F_10 ( V_3 , V_49 , V_1 , 0 , - 1 , V_29 ) ;
V_44 = F_8 ( V_5 , V_50 ) ;
V_4 = 0 ;
V_11 = - 1 ;
while ( V_4 > V_11 ) {
V_11 = V_4 ;
V_4 += F_1 ( V_1 , V_2 , V_44 , V_4 ) ;
}
return F_13 ( V_1 ) ;
}
void
F_17 ( void )
{
static T_9 V_51 [] = {
{ & V_20 ,
{ L_12 , L_13 ,
V_52 , V_53 , NULL , 0 ,
L_14 , V_54 }
} ,
{ & V_25 ,
{ L_15 , L_16 ,
V_52 , V_53 , NULL , 0 ,
L_17 , V_54 }
} ,
{ & V_27 ,
{ L_18 , L_19 ,
V_55 , V_56 , NULL , 0 ,
L_20 , V_54 }
} ,
{ & V_31 ,
{ L_21 , L_22 ,
V_57 , V_53 , NULL , 0 ,
L_23 , V_54 }
} ,
{ & V_34 ,
{ L_24 , L_25 ,
V_58 , V_56 , NULL , 0 ,
L_26 , V_54 }
} ,
{ & V_37 ,
{ L_24 , L_27 ,
V_59 , V_56 , NULL , 0 ,
L_28 , V_54 }
} ,
{ & V_39 ,
{ L_24 , L_29 ,
V_59 , V_56 , NULL , 0 ,
L_30 , V_54 }
} ,
{ & V_42 ,
{ L_31 , L_32 ,
V_60 , V_61 , F_18 ( V_62 ) , 0 ,
L_33 , V_54 }
}
} ;
T_10 * V_63 ;
static T_7 * V_64 [] = {
& V_50 ,
& V_22
} ;
static T_11 V_65 [] = {
{ & V_13 , { L_34 , V_66 , V_67 , L_35 , V_68 } } ,
{ & V_15 , { L_36 , V_66 , V_67 , L_37 , V_68 } } ,
{ & V_18 , { L_38 , V_66 , V_67 , L_39 , V_68 } } ,
{ & V_24 , { L_40 , V_69 , V_67 , L_41 , V_68 } } ,
{ & V_41 , { L_42 , V_69 , V_67 , L_43 , V_68 } } ,
} ;
V_49 = F_19 ( L_44 , L_9 , L_45 ) ;
F_20 ( V_49 , V_51 , F_21 ( V_51 ) ) ;
F_22 ( V_64 , F_21 ( V_64 ) ) ;
V_63 = F_23 ( V_49 ) ;
F_24 ( V_63 , V_65 , F_21 ( V_65 ) ) ;
}
void
F_25 ( void )
{
V_70 = F_26 ( F_12 , V_49 ) ;
F_27 ( L_46 , L_47 , V_70 ) ;
}
