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
F_5 ( V_2 , NULL , V_13 , V_14 , L_1 , V_7 ) ;
}
} else {
V_9 ++ ;
if ( V_9 > V_15 ) {
F_5 ( V_2 , NULL , V_13 , V_14 , L_2 ) ;
}
V_8 += V_7 + ( V_8 << 7 ) ;
}
}
switch ( V_7 ) {
case V_16 :
if ( V_8 > V_17 ) {
F_5 ( V_2 , NULL , V_13 , V_14 , L_3 V_18 L_4 , V_8 ) ;
}
V_5 = F_6 ( V_3 , V_19 , V_1 , V_10 , V_4 - V_10 - 1 , ( V_20 ) V_8 , L_5 , ( T_7 ) V_8 ) ;
V_6 = F_7 ( V_5 , V_21 ) ;
for ( V_12 = 0 ; V_12 < V_8 ; V_12 ++ ) {
V_11 = V_4 ;
V_4 += F_1 ( V_1 , V_2 , V_6 , V_4 ) ;
if ( V_4 <= V_11 ) {
return V_4 - V_10 ;
}
}
break;
case V_22 :
if ( V_8 > V_17 ) {
F_5 ( V_2 , NULL , V_23 , V_14 , L_6 V_18 L_7 , V_8 ) ;
}
F_8 ( V_3 , V_24 , V_1 , V_10 , V_4 - V_10 , ( V_20 ) V_8 ) ;
break;
case V_25 :
if ( V_8 > V_17 ) {
F_5 ( V_2 , NULL , V_13 , V_14 , L_8 V_18 L_4 , V_8 ) ;
}
F_9 ( V_3 , V_26 , V_1 , V_4 , ( V_20 ) V_8 , V_27 | V_28 ) ;
V_4 += ( T_7 ) V_8 ;
break;
case V_29 :
if ( V_8 > V_17 ) {
F_5 ( V_2 , NULL , V_23 , V_14 , L_9 V_18 L_7 , V_8 ) ;
}
F_10 ( V_3 , V_30 , V_1 , V_10 , V_4 - V_10 , ( V_31 ) V_8 * - 1 ) ;
break;
case V_32 :
F_9 ( V_3 , V_33 , V_1 , V_4 , 8 , V_34 ) ;
V_4 += 8 ;
break;
case V_35 :
F_9 ( V_3 , V_36 , V_1 , V_10 , V_4 - V_10 , V_28 ) ;
break;
case V_37 :
F_9 ( V_3 , V_38 , V_1 , V_10 , V_4 - V_10 , V_28 ) ;
break;
case V_39 :
if ( V_9 > 1 ) {
F_5 ( V_2 , NULL , V_23 , V_14 , L_10 ) ;
}
F_9 ( V_3 , V_40 , V_1 , V_4 - 2 , 1 , V_34 ) ;
break;
default:
return 0 ;
break;
}
return V_4 - V_10 ;
}
static int
F_11 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 ) {
T_5 V_7 = 0 ;
T_7 V_4 = 0 , V_11 ;
T_4 * V_5 ;
T_3 * V_41 ;
if ( F_12 ( V_1 ) < 2 )
return 0 ;
F_13 ( V_2 -> V_42 , V_43 , L_11 ) ;
while ( F_2 ( V_1 , V_4 ) > 0 && V_4 < V_15 ) {
V_7 = F_3 ( V_1 , V_4 ) ;
if ( F_4 ( V_7 ) )
break;
V_4 ++ ;
}
F_14 ( V_2 -> V_42 , V_44 , L_12 ,
F_15 ( V_7 , V_45 , L_13 ) ) ;
V_5 = F_9 ( V_3 , V_46 , V_1 , 0 , - 1 , V_28 ) ;
V_41 = F_7 ( V_5 , V_47 ) ;
V_4 = 0 ;
V_11 = - 1 ;
while ( V_4 > V_11 ) {
V_11 = V_4 ;
V_4 += F_1 ( V_1 , V_2 , V_41 , V_4 ) ;
}
return F_12 ( V_1 ) ;
}
static void
F_16 ( V_20 V_48 ) {
F_17 ( L_14 , V_48 , V_49 ) ;
}
static void
F_18 ( V_20 V_48 ) {
F_19 ( L_14 , V_48 , V_49 ) ;
}
static void
F_20 ( void ) {
F_21 ( V_50 , F_16 ) ;
F_22 ( V_50 ) ;
V_50 = F_23 ( V_51 ) ;
F_21 ( V_50 , F_18 ) ;
}
void
F_24 ( void )
{
static T_8 V_52 [] = {
{ & V_19 ,
{ L_15 , L_16 ,
V_53 , V_54 , NULL , 0 ,
L_17 , V_55 }
} ,
{ & V_24 ,
{ L_18 , L_19 ,
V_53 , V_54 , NULL , 0 ,
L_20 , V_55 }
} ,
{ & V_26 ,
{ L_21 , L_22 ,
V_56 , V_57 , NULL , 0 ,
L_23 , V_55 }
} ,
{ & V_30 ,
{ L_24 , L_25 ,
V_58 , V_54 , NULL , 0 ,
L_26 , V_55 }
} ,
{ & V_33 ,
{ L_27 , L_28 ,
V_59 , V_57 , NULL , 0 ,
L_29 , V_55 }
} ,
{ & V_36 ,
{ L_27 , L_30 ,
V_60 , V_57 , NULL , 0 ,
L_31 , V_55 }
} ,
{ & V_38 ,
{ L_27 , L_32 ,
V_60 , V_57 , NULL , 0 ,
L_33 , V_55 }
} ,
{ & V_40 ,
{ L_34 , L_35 ,
V_61 , V_62 , F_25 ( V_63 ) , 0 ,
L_36 , V_55 }
}
} ;
T_9 * V_64 ;
static T_7 * V_65 [] = {
& V_47 ,
& V_21
} ;
V_46 = F_26 ( L_37 ,
L_11 , L_38 ) ;
F_27 ( V_46 , V_52 , F_28 ( V_52 ) ) ;
F_29 ( V_65 , F_28 ( V_65 ) ) ;
V_64 = F_30 ( V_46 , F_20 ) ;
V_50 = F_31 () ;
F_32 ( V_64 , L_14 , L_39 , L_40 , & V_51 , 65535 ) ;
}
void
F_33 ( void )
{
V_49 = F_34 ( F_11 , V_46 ) ;
}
