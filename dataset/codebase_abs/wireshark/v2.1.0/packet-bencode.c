static int F_1 ( T_1 * V_1 , T_2 * V_2 ,
int V_3 , int V_4 , T_3 * V_5 , T_4 * V_6 , int V_7 )
{
T_5 V_8 ;
int V_9 = 0 , V_10 ;
int V_11 ;
int V_12 = 0 ;
if ( V_4 < 2 ) {
F_2 ( V_5 , V_2 , & V_13 , V_1 , V_3 , V_4 ) ;
return - 1 ;
}
V_11 = 0 ;
while ( V_4 >= 1 ) {
V_8 = F_3 ( V_1 , V_3 + V_11 ) ;
V_4 -- ;
V_11 ++ ;
if ( ( V_8 == ':' ) && ( V_11 > 1 ) ) {
if ( ( V_9 > V_4 ) || ( V_9 < 0 ) ) {
F_2 ( V_5 , V_2 , & V_14 , V_1 , V_3 , V_4 ) ;
return - 1 ;
}
if ( V_5 ) {
F_4 ( V_5 , V_15 , V_1 , V_3 , V_11 , V_9 ) ;
F_5 ( V_5 , V_16 , V_1 , V_3 + V_11 , V_9 , V_17 | V_18 ) ;
if ( V_7 == 1 ) {
F_6 ( V_6 , L_1 ,
F_7 ( ( V_19 * ) F_8 ( F_9 () ,
V_1 , V_3 + V_11 , V_9 ) , V_9 ) ) ;
}
if ( V_7 == 2 ) {
F_6 ( V_6 , L_2 ,
F_7 ( ( V_19 * ) F_8 ( F_9 () ,
V_1 , V_3 + V_11 , V_9 ) , V_9 ) ) ;
}
}
return V_11 + V_9 ;
}
if ( ! V_12 && ( V_8 >= '0' ) && ( V_8 <= '9' ) ) {
if ( ( V_8 == '0' ) && ( V_11 == 1 ) ) {
V_12 = 1 ;
}
V_10 = ( V_9 * 10 ) + ( V_8 - '0' ) ;
if ( V_10 >= V_9 ) {
V_9 = V_10 ;
continue;
}
}
F_2 ( V_5 , V_2 , & V_13 , V_1 , V_3 , V_4 ) ;
return - 1 ;
}
F_5 ( V_5 , V_20 , V_1 , V_3 , V_4 , V_18 ) ;
return - 1 ;
}
static int F_10 ( T_1 * V_1 , T_2 * V_2 ,
int V_3 , int V_4 , T_3 * V_5 , T_4 * V_6 , int V_7 )
{
T_6 V_21 = 0 ;
int V_22 = 0 ;
int V_12 = 0 ;
int V_11 ;
T_5 V_8 ;
if ( V_4 < 3 ) {
F_2 ( V_5 , V_2 , & V_23 , V_1 , V_3 , V_4 ) ;
return - 1 ;
}
V_4 -- ;
V_11 = 1 ;
while ( V_4 >= 1 ) {
V_8 = F_3 ( V_1 , V_3 + V_11 ) ;
V_4 -- ;
V_11 ++ ;
switch ( V_8 ) {
case 'e' :
if ( V_5 ) {
if ( V_22 ) V_21 = - V_21 ;
F_11 ( V_5 , V_24 , V_1 , V_3 , V_11 , V_21 ) ;
if ( V_7 == 2 ) {
F_6 ( V_6 , L_3 , V_21 ) ;
}
}
return V_11 ;
case '-' :
if ( V_11 == 2 ) {
V_22 = 1 ;
break;
}
default:
if ( ! ( ( V_8 == '0' ) && ( V_11 == 3 ) && V_22 ) ) {
if ( ( V_8 == '0' ) && ( V_11 == 2 ) ) {
V_12 = 1 ;
break;
}
if ( ! V_12 && ( V_8 >= '0' ) && ( V_8 <= '9' ) ) {
V_21 = ( V_21 * 10 ) + ( V_8 - '0' ) ;
break;
}
}
F_2 ( V_5 , V_2 , & V_23 , V_1 , V_3 , V_4 ) ;
return - 1 ;
}
}
F_5 ( V_5 , V_20 , V_1 , V_3 , V_4 , V_18 ) ;
return - 1 ;
}
static int F_12 ( T_1 * V_1 , T_2 * V_2 ,
int V_3 , int V_4 , T_3 * V_5 , int V_25 , T_4 * V_26 , int V_7 )
{
T_5 V_27 ;
int V_28 = 0 , V_29 , V_30 ;
int V_11 ;
T_4 * V_6 = NULL , * V_31 = NULL ;
T_3 * V_32 = NULL , * V_33 = NULL ;
if ( V_25 > 10 ) {
F_2 ( V_5 , V_2 , & V_34 , V_1 , V_3 , - 1 ) ;
return - 1 ;
}
if ( V_4 < 1 ) {
F_5 ( V_5 , V_20 , V_1 , V_3 , - 1 , V_18 ) ;
return V_4 ;
}
V_27 = F_3 ( V_1 , V_3 ) ;
V_28 = F_12 ( V_1 , V_2 , V_3 , V_4 , NULL , V_25 + 1 , NULL , 0 ) ;
if ( V_28 < 0 )
V_28 = V_4 ;
switch ( V_27 ) {
case 'd' :
V_31 = F_5 ( V_5 , V_35 , V_1 , V_3 , V_28 , V_18 ) ;
V_33 = F_13 ( V_31 , V_36 ) ;
V_11 = 1 ;
V_4 -- ;
while ( V_4 >= 1 ) {
V_27 = F_3 ( V_1 , V_3 + V_11 ) ;
if ( V_27 == 'e' ) {
return V_11 + 1 ;
}
V_29 = F_1 ( V_1 , V_2 , V_3 + V_11 , V_4 , NULL , NULL , 0 ) ;
if ( V_29 < 0 ) {
F_2 ( V_33 , V_2 , & V_37 , V_1 , V_3 + V_11 , - 1 ) ;
return V_29 ;
}
V_30 = - 1 ;
if ( ( V_4 - V_29 ) > 2 )
V_30 = F_12 ( V_1 , V_2 , V_3 + V_11 + V_29 , V_4 - V_29 , NULL , V_25 + 1 , NULL , 0 ) ;
if ( V_30 < 0 ) {
F_2 ( V_33 , V_2 , & V_38 , V_1 , V_3 + V_11 + V_29 , - 1 ) ;
return V_30 ;
}
V_6 = F_5 ( V_33 , V_39 , V_1 , V_3 + V_11 , V_29 + V_30 , V_18 ) ;
V_32 = F_13 ( V_6 , V_40 ) ;
F_1 ( V_1 , V_2 , V_3 + V_11 , V_4 , V_32 , V_6 , 1 ) ;
F_12 ( V_1 , V_2 , V_3 + V_11 + V_29 , V_4 - V_29 , V_32 , V_25 + 1 , V_6 , 2 ) ;
V_11 += V_29 + V_30 ;
V_4 -= V_29 + V_30 ;
}
F_5 ( V_33 , V_20 , V_1 , V_3 + V_11 , - 1 , V_18 ) ;
return - 1 ;
case 'l' :
V_6 = F_5 ( V_5 , V_41 , V_1 , V_3 , V_28 , V_18 ) ;
V_32 = F_13 ( V_6 , V_42 ) ;
V_11 = 1 ;
V_4 -- ;
while ( V_4 >= 1 ) {
V_27 = F_3 ( V_1 , V_3 + V_11 ) ;
if ( V_27 == 'e' ) {
return V_11 + 1 ;
}
V_28 = F_12 ( V_1 , V_2 , V_3 + V_11 , V_4 , V_32 , V_25 + 1 , V_6 , 0 ) ;
if ( V_28 < 1 ) return V_28 ;
V_11 += V_28 ;
V_4 -= V_28 ;
}
F_5 ( V_32 , V_20 , V_1 , V_3 + V_11 , - 1 , V_18 ) ;
return - 1 ;
case 'i' :
return F_10 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_26 , V_7 ) ;
default:
if ( ( V_27 >= '1' ) && ( V_27 <= '9' ) ) {
return F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_26 , V_7 ) ;
}
F_2 ( V_5 , V_2 , & V_43 , V_1 , V_3 , - 1 ) ;
}
return - 1 ;
}
static int F_14 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_5 , void * T_7 V_44 )
{
F_12 ( V_1 , V_2 , 0 , F_15 ( V_1 ) , V_5 , 0 , NULL , 0 ) ;
return F_16 ( V_1 ) ;
}
void
F_17 ( void )
{
static T_8 V_45 [] = {
{ & V_15 ,
{ L_4 , L_5 , V_46 , V_47 , NULL , 0x0 , NULL , V_48 }
} ,
{ & V_16 ,
{ L_6 , L_7 , V_49 , V_50 , NULL , 0x0 , NULL , V_48 }
} ,
{ & V_24 ,
{ L_8 , L_9 , V_51 , V_47 , NULL , 0x0 , NULL , V_48 }
} ,
{ & V_35 ,
{ L_10 , L_11 , V_52 , V_50 , NULL , 0x0 , NULL , V_48 }
} ,
{ & V_39 ,
{ L_12 , L_13 , V_52 , V_50 , NULL , 0x0 , NULL , V_48 }
} ,
{ & V_41 ,
{ L_14 , L_15 , V_52 , V_50 , NULL , 0x0 , NULL , V_48 }
} ,
{ & V_20 ,
{ L_16 , L_17 , V_53 , V_50 , NULL , 0x0 , NULL , V_48 }
} ,
} ;
static T_9 * V_54 [] = {
& V_36 ,
& V_40 ,
& V_42 ,
} ;
static T_10 V_55 [] = {
{ & V_13 , { L_18 , V_56 , V_57 , L_19 , V_58 } } ,
{ & V_14 , { L_20 , V_56 , V_57 , L_21 , V_58 } } ,
{ & V_23 , { L_22 , V_56 , V_57 , L_23 , V_58 } } ,
{ & V_34 , { L_24 , V_56 , V_57 , L_25 , V_58 } } ,
{ & V_37 , { L_26 , V_56 , V_57 , L_27 , V_58 } } ,
{ & V_38 , { L_28 , V_56 , V_57 , L_29 , V_58 } } ,
{ & V_43 , { L_30 , V_56 , V_57 , L_31 , V_58 } } ,
} ;
T_11 * V_59 ;
V_60 = F_18 ( L_32 , L_32 , L_33 ) ;
F_19 ( L_33 , F_14 , V_60 ) ;
F_20 ( V_60 , V_45 , F_21 ( V_45 ) ) ;
F_22 ( V_54 , F_21 ( V_54 ) ) ;
V_59 = F_23 ( V_60 ) ;
F_24 ( V_59 , V_55 , F_21 ( V_55 ) ) ;
}
