static int
F_1 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * V_3 , int V_4 , int T_5 V_2 )
{
T_6 V_5 ;
F_2 ( V_3 , V_6 , V_1 , V_4 , 4 , V_7 , & V_5 ) ;
V_4 += 4 ;
F_3 ( V_3 , V_8 , V_1 , V_4 , V_5 , V_9 | V_10 ) ;
V_4 = V_4 + V_5 ;
return V_4 ;
}
static int
F_4 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * V_3 , int V_4 , int T_5 )
{
T_4 * V_11 ;
T_7 * V_12 ;
T_6 type ;
int V_13 = V_4 , V_14 ;
T_6 V_15 ;
V_11 = F_5 ( V_3 , V_1 , V_4 , - 1 , V_16 , & V_12 , L_1 ) ;
F_2 ( V_11 , V_17 , V_1 , V_4 , 1 , V_7 , & type ) ;
V_4 ++ ;
F_2 ( V_11 , V_18 , V_1 , V_4 , 4 , V_7 , & V_15 ) ;
V_4 += 4 ;
for ( V_14 = 0 ; V_14 < ( int ) V_15 ; ++ V_14 ) {
V_4 = F_6 ( V_1 , T_3 , V_11 , type , V_4 , T_5 ) ;
}
V_15 = V_4 - V_13 ;
F_7 ( V_12 , V_15 ) ;
return V_4 ;
}
static int
F_8 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * V_3 , int V_4 , int T_5 )
{
T_4 * V_11 ;
T_7 * V_12 ;
T_8 type ;
int V_13 = V_4 , V_19 ;
V_11 = F_5 ( V_3 , V_1 , V_4 , - 1 , V_16 , & V_12 , L_2 ) ;
if ( V_4 >= T_5 ) {
return T_5 ;
}
while ( V_4 < T_5 ) {
type = F_9 ( V_1 , V_4 ) ;
F_3 ( V_11 , V_17 , V_1 , V_4 , 1 , V_7 ) ;
V_4 ++ ;
if ( type == 0 ) {
V_19 = V_4 - V_13 ;
F_7 ( V_12 , V_19 ) ;
break;
}
F_3 ( V_11 , V_20 , V_1 , V_4 , 2 , V_7 ) ;
V_4 += 2 ;
V_4 = F_6 ( V_1 , T_3 , V_11 , type , V_4 , T_5 ) ;
}
return V_4 ;
}
static int
F_10 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * V_3 , int V_4 , int T_5 )
{
T_4 * V_11 ;
T_7 * V_12 ;
T_6 V_21 ;
T_6 V_22 ;
T_6 V_23 ;
int V_13 = V_4 , V_14 ;
V_11 = F_5 ( V_3 , V_1 , V_4 , - 1 , V_16 , & V_12 , L_3 ) ;
F_2 ( V_11 , V_17 , V_1 , V_4 , 1 , V_7 , & V_21 ) ;
V_4 ++ ;
F_2 ( V_11 , V_17 , V_1 , V_4 , 1 , V_7 , & V_22 ) ;
V_4 ++ ;
F_2 ( V_11 , V_24 , V_1 , V_4 , 4 , V_7 , & V_23 ) ;
V_4 += 4 ;
for ( V_14 = 0 ; V_14 < ( int ) V_23 ; ++ V_14 ) {
V_4 = F_6 ( V_1 , T_3 , V_11 , V_21 , V_4 , T_5 ) ;
V_4 = F_6 ( V_1 , T_3 , V_11 , V_22 , V_4 , T_5 ) ;
}
V_23 = V_4 - V_13 ;
F_7 ( V_12 , V_23 ) ;
return V_4 ;
}
static int
F_6 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * V_3 , int type , int V_4 , int T_5 )
{
switch ( type ) {
case 2 :
F_3 ( V_3 , V_25 , V_1 , V_4 , 1 , V_7 ) ;
V_4 += 1 ;
break;
case 3 :
F_3 ( V_3 , V_26 , V_1 , V_4 , 1 , V_7 ) ;
V_4 += 1 ;
break;
case 4 :
F_3 ( V_3 , V_27 , V_1 , V_4 , 8 , V_7 ) ;
V_4 += 8 ;
break;
case 6 :
F_3 ( V_3 , V_28 , V_1 , V_4 , 2 , V_7 ) ;
V_4 += 2 ;
break;
case 8 :
F_3 ( V_3 , V_29 , V_1 , V_4 , 4 , V_7 ) ;
V_4 += 4 ;
break;
case 9 :
F_3 ( V_3 , V_30 , V_1 , V_4 , 8 , V_7 ) ;
V_4 += 8 ;
break;
case 10 :
F_3 ( V_3 , V_31 , V_1 , V_4 , 8 , V_7 ) ;
V_4 += 8 ;
break;
case 11 :
V_4 = F_1 ( V_1 , T_3 , V_3 , V_4 , T_5 ) ;
break;
case 12 :
V_4 = F_8 ( V_1 , T_3 , V_3 , V_4 , T_5 ) ;
break;
case 13 :
V_4 = F_10 ( V_1 , T_3 , V_3 , V_4 , T_5 ) ;
break;
case 15 :
V_4 = F_4 ( V_1 , T_3 , V_3 , V_4 , T_5 ) ;
break;
default:
return T_5 ;
}
return V_4 ;
}
static void
F_11 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_3 )
{
T_4 * V_11 ;
int V_4 = 0 ;
T_6 V_5 ;
T_8 V_32 ;
T_9 V_33 ;
T_6 V_34 ;
T_8 * V_35 ;
int T_5 = F_12 ( V_1 ) ;
T_8 type ;
F_13 ( T_3 -> V_36 , V_37 , L_4 ) ;
F_14 ( T_3 -> V_36 , V_38 ) ;
V_33 = F_15 ( V_1 , 0 ) ;
V_32 = F_9 ( V_1 , 3 ) ;
V_5 = F_16 ( V_1 , 4 ) ;
V_34 = F_16 ( V_1 , V_5 + 8 ) ;
V_35 = F_17 ( F_18 () , V_1 , 8 , V_5 , V_39 ) ;
F_3 ( V_3 , V_40 , V_1 , 0 , - 1 , V_10 ) ;
V_11 = F_19 ( V_3 , V_1 , 0 , - 1 , V_16 , NULL , L_5 ,
F_20 ( V_32 , V_41 , L_6 ) ,
V_33 ,
V_34 ,
V_35 ) ;
F_21 ( T_3 -> V_36 , V_38 , L_7 , F_20 ( V_32 , V_41 , L_6 ) , V_35 ) ;
if ( V_3 ) {
F_3 ( V_11 , V_42 , V_1 , V_4 , 2 , V_7 ) ;
V_4 += 2 ;
V_4 ++ ;
F_3 ( V_11 , V_43 , V_1 , V_4 , 1 , V_7 ) ;
V_4 += 1 ;
F_3 ( V_11 , V_6 , V_1 , V_4 , 4 , V_7 ) ;
V_4 += 4 ;
F_3 ( V_11 , V_44 , V_1 , V_4 , V_5 , V_9 | V_10 ) ;
V_4 = V_4 + V_5 ;
F_3 ( V_11 , V_45 , V_1 , V_4 , 4 , V_7 ) ;
V_4 += 4 ;
}
else{
V_4 = 12 + V_5 ;
}
V_11 = F_5 ( V_3 , V_1 , V_4 , - 1 , V_16 , NULL , L_8 ) ;
if ( V_3 ) {
while ( V_4 < T_5 ) {
type = F_9 ( V_1 , V_4 ) ;
F_3 ( V_11 , V_17 , V_1 , V_4 , 1 , V_7 ) ;
if ( type == 0 ) {
return;
}
V_4 ++ ;
F_3 ( V_11 , V_20 , V_1 , V_4 , 2 , V_7 ) ;
V_4 += 2 ;
V_4 = F_6 ( V_1 , T_3 , V_11 , type , V_4 , T_5 ) ;
}
}
}
static T_10
F_22 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_3 , void * T_11 V_2 ) {
int V_4 = 0 ;
T_6 V_46 ;
T_12 V_47 ;
int T_5 = F_23 ( V_1 ) ;
int V_48 ;
T_13 V_49 ;
if ( T_5 < 9 ) {
return FALSE ;
}
V_46 = F_16 ( V_1 , V_4 ) ;
if ( ( V_46 & V_50 ) != V_51 ) {
V_47 = V_46 ;
V_4 += 4 ;
V_46 = F_16 ( V_1 , V_4 ) ;
if ( V_47 > ( T_5 - 4 ) ) {
return FALSE ;
}
else if ( ( V_46 & V_50 ) != V_51 ) {
return FALSE ;
}
else {
V_1 = F_24 ( V_1 , 4 ) ;
V_4 -= 4 ;
T_5 -= 4 ;
}
}
V_4 += 4 ;
V_48 = F_16 ( V_1 , V_4 ) ;
if ( ( V_48 < 1 ) || ( T_5 < V_48 + 8 ) ) {
return FALSE ;
}
V_4 += 4 ;
if ( T_5 < V_4 + V_48 ) {
return FALSE ;
}
while ( V_4 < ( V_48 + 8 ) ) {
V_49 = F_9 ( V_1 , V_4 ) ;
if ( ! F_25 ( V_49 ) ) {
return FALSE ;
}
V_4 ++ ;
}
F_11 ( V_1 , T_3 , V_3 ) ;
return TRUE ;
}
void F_26 ( void ) {
static T_14 V_52 [] = {
{ & V_42 ,
{ L_9 , L_10 ,
V_53 , V_54 , NULL , 0x0 ,
NULL , V_55 }
} ,
{ & V_43 ,
{ L_11 , L_12 ,
V_56 , V_57 , F_27 ( V_41 ) , 0x0 ,
NULL , V_55 }
} ,
{ & V_6 ,
{ L_13 , L_14 ,
V_58 , V_57 , NULL , 0x0 ,
NULL , V_55 }
} ,
{ & V_44 ,
{ L_15 , L_16 ,
V_59 , V_60 , NULL , 0x0 ,
NULL , V_55 }
} ,
{ & V_45 ,
{ L_17 , L_18 ,
V_58 , V_57 , NULL , 0x0 ,
NULL , V_55 }
} ,
{ & V_17 ,
{ L_19 , L_20 ,
V_56 , V_57 , F_27 ( V_61 ) , 0x0 ,
NULL , V_55 }
} ,
{ & V_20 ,
{ L_21 , L_22 ,
V_53 , V_57 , NULL , 0x0 ,
NULL , V_55 }
} ,
{ & V_28 ,
{ L_23 , L_24 ,
V_62 , V_57 , NULL , 0x0 ,
NULL , V_55 }
} ,
{ & V_29 ,
{ L_25 , L_26 ,
V_63 , V_57 , NULL , 0x0 ,
NULL , V_55 }
} ,
{ & V_8 ,
{ L_27 , L_28 ,
V_59 , V_60 , NULL , 0x0 ,
NULL , V_55 }
} ,
{ & V_18 ,
{ L_29 , L_30 ,
V_58 , V_57 , NULL , 0x0 ,
NULL , V_55 }
} ,
{ & V_24 ,
{ L_31 , L_32 ,
V_58 , V_57 , NULL , 0x0 ,
NULL , V_55 }
} ,
{ & V_25 ,
{ L_33 , L_34 ,
V_56 , V_57 , F_27 ( V_64 ) , 0x0 ,
NULL , V_55 }
} ,
{ & V_26 ,
{ L_35 , L_36 ,
V_56 , V_57 , NULL , 0x0 ,
NULL , V_55 }
} ,
{ & V_31 ,
{ L_37 , L_38 ,
V_65 , V_57 , NULL , 0x0 ,
NULL , V_55 }
} ,
{ & V_30 ,
{ L_37 , L_39 ,
V_66 , V_57 , NULL , 0x0 ,
NULL , V_55 }
} ,
{ & V_27 ,
{ L_40 , L_41 ,
V_67 , V_60 , NULL , 0x0 ,
NULL , V_55 }
} ,
} ;
static T_12 * V_68 [] = {
& V_16 ,
} ;
V_40 = F_28 ( L_42 , L_43 , L_44 ) ;
F_29 ( V_40 , V_52 , F_30 ( V_52 ) ) ;
F_31 ( V_68 , F_30 ( V_68 ) ) ;
}
void F_32 ( void ) {
F_33 ( L_45 , F_22 , L_46 , L_47 , V_40 , V_69 ) ;
}
