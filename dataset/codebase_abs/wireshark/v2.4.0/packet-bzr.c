static T_1 F_1 ( T_2 * V_1 , int V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_1 , V_2 ) ;
return 4 + V_3 ;
}
static T_1
F_3 ( T_3 * T_4 V_4 , T_2 * V_1 , int V_2 )
{
int V_5 ;
T_5 V_6 = 0 , V_7 ;
T_5 V_8 ;
T_6 V_9 = 0 ;
V_8 = F_4 ( V_1 , V_2 , - 1 , & V_5 ,
TRUE ) ;
if ( V_8 == - 1 )
return - 1 ;
V_6 += V_8 + 1 ;
V_7 = V_6 ;
V_6 += F_1 ( V_1 , V_5 ) ;
if ( V_7 > V_6 )
return - 1 ;
while ( F_5 ( V_1 , V_2 + V_6 ) > 0 ) {
V_9 = F_6 ( V_1 , V_2 + V_6 ) ;
V_6 += 1 ;
switch ( V_9 ) {
case 's' :
case 'b' :
V_7 = V_6 ;
V_6 += F_1 ( V_1 , V_2 + V_6 ) ;
if ( V_7 > V_6 )
return - 1 ;
break;
case 'o' :
V_6 += 1 ;
break;
case 'e' :
return V_6 ;
}
}
return - 1 ;
}
static T_5
F_7 ( T_2 * V_1 , T_5 V_2 , T_3 * T_4 ,
T_7 * V_10 )
{
T_8 V_11 ;
T_7 * V_12 ;
T_9 * V_13 ;
T_2 * V_14 ;
V_11 = F_2 ( V_1 , V_2 ) ;
V_13 = F_8 ( V_10 , V_15 , V_1 , V_2 , 4 +
V_11 , V_16 ) ;
V_12 = F_9 ( V_13 , V_17 ) ;
F_8 ( V_12 , V_18 ,
V_1 , V_2 , 4 , V_19 ) ;
V_14 = F_10 ( V_1 , V_2 + 4 , V_11 ) ;
F_11 ( V_20 , V_14 , T_4 , V_12 ) ;
return 4 + V_11 ;
}
static T_5
F_12 ( T_2 * V_1 , T_5 V_2 , T_3 * T_4 V_4 ,
T_7 * V_10 )
{
T_8 V_11 ;
T_7 * V_21 ;
T_9 * V_13 ;
V_11 = F_2 ( V_1 , V_2 ) ;
V_13 = F_8 ( V_10 , V_22 , V_1 , V_2 , 4 +
V_11 , V_16 ) ;
V_21 = F_9 ( V_13 , V_23 ) ;
if ( V_21 )
{
F_8 ( V_21 , V_24 ,
V_1 , V_2 , 4 , V_19 ) ;
F_8 ( V_21 , V_25 ,
V_1 , V_2 + 4 , V_11 , V_16 ) ;
}
return 4 + V_11 ;
}
static T_5
F_13 ( T_2 * V_1 , T_5 V_2 , T_3 * T_4 , T_7 * V_10 )
{
T_6 V_9 = 0 ;
while ( F_5 ( V_1 , V_2 ) > 0 ) {
V_9 = F_6 ( V_1 , V_2 ) ;
F_8 ( V_10 , V_26 , V_1 , V_2 , 1 , V_27 | V_16 ) ;
V_2 += 1 ;
switch ( V_9 ) {
case 's' :
V_2 += F_7 ( V_1 , V_2 , T_4 , V_10 ) ;
break;
case 'b' :
V_2 += F_12 ( V_1 , V_2 , T_4 , V_10 ) ;
break;
case 'o' :
F_8 ( V_10 , V_28 , V_1 , V_2 , 1 ,
V_27 | V_16 ) ;
V_2 += 1 ;
break;
case 'e' :
break;
}
}
return V_2 ;
}
static void
F_14 ( T_2 * V_1 , T_3 * T_4 , T_7 * V_10 )
{
T_7 * V_29 ;
T_9 * V_13 ;
int V_2 = 0 ;
T_5 V_8 ;
V_13 = F_8 ( V_10 , V_30 , V_1 , V_2 , - 1 , V_16 ) ;
V_29 = F_9 ( V_13 , V_31 ) ;
V_8 = F_4 ( V_1 , V_2 , - 1 , & V_2 , TRUE ) ;
if ( V_8 == - 1 )
return;
if ( V_29 )
{
F_8 ( V_29 , V_32 , V_1 , 0 ,
V_8 + 1 , V_27 | V_16 ) ;
}
V_2 += F_7 ( V_1 , V_2 , T_4 , V_29 ) ;
F_13 ( V_1 , V_2 , T_4 , V_29 ) ;
}
static int
F_15 ( T_2 * V_1 , T_3 * T_4 , T_7 * V_10 , void * T_10 V_4 )
{
T_5 V_2 = 0 , V_33 ;
T_2 * V_34 ;
F_16 ( T_4 -> V_35 , V_36 , L_1 ) ;
F_16 ( T_4 -> V_35 , V_37 , L_2 ) ;
while ( F_5 ( V_1 , V_2 ) > 0 ) {
V_33 = F_3 ( T_4 , V_1 , V_2 ) ;
if ( V_33 == - 1 ) {
if ( T_4 -> V_38 && V_39 ) {
T_4 -> V_40 = V_2 ;
T_4 -> V_41 = V_42 ;
return F_17 ( V_1 ) ;
} else {
V_33 = F_5 ( V_1 , V_2 ) ;
}
}
V_34 = F_10 ( V_1 , V_2 , V_33 ) ;
F_14 ( V_34 , T_4 , V_10 ) ;
V_2 += V_33 ;
}
return F_17 ( V_1 ) ;
}
void
F_18 ( void )
{
static T_11 V_43 [] = {
{ & V_26 ,
{ L_3 , L_4 , V_44 , V_45 ,
F_19 ( V_46 ) , 0x0 , NULL , V_47 } ,
} ,
{ & V_32 ,
{ L_5 , L_6 , V_48 , V_49 ,
NULL , 0x0 , NULL , V_47 } ,
} ,
{ & V_15 ,
{ L_7 , L_8 , V_50 , V_49 , NULL , 0x0 ,
L_9
L_10 , V_47 } ,
} ,
{ & V_18 ,
{ L_11 , L_12 , V_51 ,
V_45 , NULL , 0x0 , NULL , V_47 } ,
} ,
{ & V_22 ,
{ L_13 , L_14 , V_50 , V_49 , NULL , 0x0 ,
L_15 , V_47 } ,
} ,
{ & V_25 ,
{ L_16 , L_17 , V_50 , V_49 ,
NULL , 0x0 , NULL , V_47 } ,
} ,
{ & V_24 ,
{ L_18 , L_19 , V_51 , V_45 ,
NULL , 0x0 , NULL , V_47 } ,
} ,
{ & V_28 ,
{ L_20 , L_21 , V_44 , V_45 ,
F_19 ( V_52 ) , 0x0 ,
L_22 , V_47
} ,
} ,
} ;
static T_5 * V_53 [] = {
& V_31 ,
& V_17 ,
& V_23 ,
} ;
T_12 * V_54 ;
V_30 = F_20 ( L_2 , L_23 , L_24 ) ;
V_55 = F_21 ( L_24 , F_15 , V_30 ) ;
F_22 ( V_30 , V_43 , F_23 ( V_43 ) ) ;
F_24 ( V_53 , F_23 ( V_53 ) ) ;
V_54 = F_25 ( V_30 , NULL ) ;
F_26 ( V_54 , L_25 ,
L_26 ,
L_27
L_28
L_29 ,
& V_39 ) ;
}
void
F_27 ( void )
{
V_20 = F_28 ( L_30 , V_30 ) ;
F_29 ( L_31 , V_56 , V_55 ) ;
}
