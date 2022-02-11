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
F_6 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * V_3 , int type , int V_4 , int T_5 )
{
switch ( type ) {
case 2 :
F_3 ( V_3 , V_21 , V_1 , V_4 , 1 , V_7 ) ;
V_4 += 1 ;
break;
case 3 :
F_3 ( V_3 , V_22 , V_1 , V_4 , 1 , V_7 ) ;
V_4 += 1 ;
break;
case 4 :
F_3 ( V_3 , V_23 , V_1 , V_4 , 8 , V_7 ) ;
V_4 += 8 ;
break;
case 6 :
F_3 ( V_3 , V_24 , V_1 , V_4 , 2 , V_7 ) ;
V_4 += 2 ;
break;
case 8 :
F_3 ( V_3 , V_25 , V_1 , V_4 , 4 , V_7 ) ;
V_4 += 4 ;
break;
case 9 :
F_3 ( V_3 , V_26 , V_1 , V_4 , 8 , V_7 ) ;
V_4 += 8 ;
break;
case 10 :
F_3 ( V_3 , V_27 , V_1 , V_4 , 8 , V_7 ) ;
V_4 += 8 ;
break;
case 11 :
V_4 = F_1 ( V_1 , T_3 , V_3 , V_4 , T_5 ) ;
break;
case 12 :
V_4 = F_8 ( V_1 , T_3 , V_3 , V_4 , T_5 ) ;
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
F_10 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_3 )
{
T_4 * V_11 ;
int V_4 = 0 ;
T_6 V_5 ;
T_8 V_28 ;
T_9 V_29 ;
T_6 V_30 ;
T_8 * V_31 ;
int T_5 = F_11 ( V_1 ) ;
T_8 type ;
F_12 ( T_3 -> V_32 , V_33 , L_3 ) ;
F_13 ( T_3 -> V_32 , V_34 ) ;
V_29 = F_14 ( V_1 , 0 ) ;
V_28 = F_9 ( V_1 , 3 ) ;
V_5 = F_15 ( V_1 , 4 ) ;
V_30 = F_15 ( V_1 , V_5 + 8 ) ;
V_31 = F_16 ( F_17 () , V_1 , 8 , V_5 , V_35 ) ;
F_3 ( V_3 , V_36 , V_1 , 0 , - 1 , V_10 ) ;
V_11 = F_18 ( V_3 , V_1 , 0 , - 1 , V_16 , NULL , L_4 ,
F_19 ( V_28 , V_37 , L_5 ) ,
V_29 ,
V_30 ,
V_31 ) ;
F_20 ( T_3 -> V_32 , V_34 , L_6 , F_19 ( V_28 , V_37 , L_5 ) , V_31 ) ;
if ( V_3 ) {
F_3 ( V_11 , V_38 , V_1 , V_4 , 2 , V_7 ) ;
V_4 += 2 ;
V_4 ++ ;
F_3 ( V_11 , V_39 , V_1 , V_4 , 1 , V_7 ) ;
V_4 += 1 ;
F_3 ( V_11 , V_6 , V_1 , V_4 , 4 , V_7 ) ;
V_4 += 4 ;
F_3 ( V_11 , V_40 , V_1 , V_4 , V_5 , V_9 | V_10 ) ;
V_4 = V_4 + V_5 ;
F_3 ( V_11 , V_41 , V_1 , V_4 , 4 , V_7 ) ;
V_4 += 4 ;
}
else{
V_4 = 12 + V_5 ;
}
V_11 = F_5 ( V_3 , V_1 , V_4 , - 1 , V_16 , NULL , L_7 ) ;
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
F_21 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_3 , void * T_11 V_2 ) {
int V_4 = 0 ;
T_6 V_42 ;
int T_5 = F_22 ( V_1 ) ;
int V_43 ;
T_12 V_44 ;
if ( T_5 < 9 ) {
return FALSE ;
}
V_42 = F_15 ( V_1 , V_4 ) ;
if ( ( V_42 & V_45 ) != V_46 ) {
return FALSE ;
}
V_4 += 4 ;
V_43 = F_15 ( V_1 , V_4 ) ;
if ( ( V_43 < 1 ) || ( T_5 < V_43 + 8 ) ) {
return FALSE ;
}
V_4 += 4 ;
if ( T_5 < V_4 + V_43 ) {
return FALSE ;
}
while ( V_4 < ( V_43 + 8 ) ) {
V_44 = F_9 ( V_1 , V_4 ) ;
if ( ! F_23 ( V_44 ) ) {
return FALSE ;
}
V_4 ++ ;
}
F_10 ( V_1 , T_3 , V_3 ) ;
return TRUE ;
}
void F_24 ( void ) {
static T_13 V_47 [] = {
{ & V_38 ,
{ L_8 , L_9 ,
V_48 , V_49 , NULL , 0x0 ,
NULL , V_50 }
} ,
{ & V_39 ,
{ L_10 , L_11 ,
V_51 , V_52 , F_25 ( V_37 ) , 0x0 ,
NULL , V_50 }
} ,
{ & V_6 ,
{ L_12 , L_13 ,
V_53 , V_52 , NULL , 0x0 ,
NULL , V_50 }
} ,
{ & V_40 ,
{ L_14 , L_15 ,
V_54 , V_55 , NULL , 0x0 ,
NULL , V_50 }
} ,
{ & V_41 ,
{ L_16 , L_17 ,
V_53 , V_52 , NULL , 0x0 ,
NULL , V_50 }
} ,
{ & V_17 ,
{ L_18 , L_19 ,
V_51 , V_52 , F_25 ( V_56 ) , 0x0 ,
NULL , V_50 }
} ,
{ & V_20 ,
{ L_20 , L_21 ,
V_48 , V_52 , NULL , 0x0 ,
NULL , V_50 }
} ,
{ & V_24 ,
{ L_22 , L_23 ,
V_57 , V_52 , NULL , 0x0 ,
NULL , V_50 }
} ,
{ & V_25 ,
{ L_24 , L_25 ,
V_58 , V_52 , NULL , 0x0 ,
NULL , V_50 }
} ,
{ & V_8 ,
{ L_26 , L_27 ,
V_54 , V_55 , NULL , 0x0 ,
NULL , V_50 }
} ,
{ & V_18 ,
{ L_28 , L_29 ,
V_53 , V_52 , NULL , 0x0 ,
NULL , V_50 }
} ,
{ & V_21 ,
{ L_30 , L_31 ,
V_51 , V_52 , F_25 ( V_59 ) , 0x0 ,
NULL , V_50 }
} ,
{ & V_22 ,
{ L_32 , L_33 ,
V_51 , V_52 , NULL , 0x0 ,
NULL , V_50 }
} ,
{ & V_27 ,
{ L_34 , L_35 ,
V_60 , V_52 , NULL , 0x0 ,
NULL , V_50 }
} ,
{ & V_26 ,
{ L_34 , L_36 ,
V_61 , V_52 , NULL , 0x0 ,
NULL , V_50 }
} ,
{ & V_23 ,
{ L_37 , L_38 ,
V_62 , V_55 , NULL , 0x0 ,
NULL , V_50 }
} ,
} ;
static T_14 * V_63 [] = {
& V_16 ,
} ;
V_36 = F_26 ( L_39 , L_40 , L_41 ) ;
F_27 ( V_36 , V_47 , F_28 ( V_47 ) ) ;
F_29 ( V_63 , F_28 ( V_63 ) ) ;
}
void F_30 ( void ) {
F_31 ( L_42 , F_21 , L_43 , L_44 , V_36 , V_64 ) ;
}
