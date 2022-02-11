static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * V_4 )
{
int V_5 = 0 ;
T_3 * V_6 ;
T_4 * V_7 ;
T_5 * V_8 ;
T_6 V_9 ;
T_6 V_10 ;
T_6 V_11 ;
T_7 V_12 ;
int V_13 ;
if ( V_4 == NULL )
return 0 ;
V_8 = ( T_5 * ) V_4 ;
F_2 ( V_2 -> V_14 , V_15 , L_1 ) ;
F_3 ( V_2 -> V_14 , V_16 ) ;
V_7 = F_4 ( V_3 , V_17 , V_1 , V_5 , - 1 , V_18 ) ;
V_6 = F_5 ( V_7 , V_19 ) ;
if ( * V_8 ) {
V_9 = F_6 ( V_1 , V_5 ) ;
F_7 ( V_2 -> V_14 , V_16 , L_2 ,
F_8 ( V_9 , V_20 ,
L_3 ) ) ;
F_9 ( V_6 , V_21 , V_1 ,
V_5 , 1 , V_9 ) ;
V_5 ++ ;
switch ( V_9 ) {
case V_22 :
case V_23 :
case V_24 :
case V_25 :
while ( F_10 ( V_1 , V_5 ) > 0 ) {
F_11 ( V_6 , V_1 , V_5 , 2 ,
L_4 ,
F_6 ( V_1 , V_5 ) ,
F_6 ( V_1 , V_5 + 1 ) ) ;
V_5 += 2 ;
}
break;
case V_26 :
break;
case V_27 :
V_10 = F_6 ( V_1 , V_5 ) ;
F_9 ( V_6 , V_28 , V_1 ,
V_5 , 1 , V_10 ) ;
V_5 ++ ;
if ( V_10 != 0 ) {
F_4 ( V_6 , V_29 ,
V_1 , V_5 , 1 , V_30 ) ;
}
break;
case V_31 :
if ( F_10 ( V_1 , V_5 ) > 0 ) {
V_11 = F_6 ( V_1 , V_5 ) ;
switch ( V_11 ) {
case 0x01 :
F_11 ( V_6 , V_1 ,
V_5 , 1 , L_5 ) ;
V_5 ++ ;
F_11 ( V_6 , V_1 ,
V_5 , 1 , L_6 ,
V_11 ) ;
V_5 ++ ;
break;
case 0x08 :
F_11 ( V_6 , V_1 ,
V_5 , 1 , L_7 ) ;
V_5 ++ ;
F_11 ( V_6 , V_1 ,
V_5 , 1 , L_8 ,
V_11 ) ;
V_5 ++ ;
break;
default:
F_11 ( V_6 , V_1 ,
V_5 , 1 , L_9 ,
V_11 ) ;
V_5 ++ ;
F_11 ( V_6 , V_1 ,
V_5 , 1 , L_10 ,
V_11 ) ;
V_5 ++ ;
break;
}
}
break;
case V_32 :
F_11 ( V_6 , V_1 , V_5 , - 1 ,
L_11 ) ;
break;
case V_33 :
F_11 ( V_6 , V_1 , V_5 , - 1 ,
L_11 ) ;
break;
default:
F_11 ( V_6 , V_1 , V_5 , - 1 ,
L_12 ) ;
break;
}
} else {
F_2 ( V_2 -> V_14 , V_16 , L_13 ) ;
if ( V_3 ) {
while ( F_12 ( V_1 , V_5 ) ) {
F_13 ( V_1 , V_5 , - 1 ,
& V_12 , FALSE ) ;
V_13 = V_12 - V_5 ;
F_11 ( V_6 , V_1 , V_5 ,
V_13 , L_14 ,
F_14 ( V_1 , V_5 , V_13 ) ) ;
V_5 = V_12 ;
}
}
}
return F_15 ( V_1 ) ;
}
void
F_16 ( void )
{
static T_8 V_34 [] = {
{ & V_21 ,
{ L_15 , L_16 , V_35 , V_36 ,
F_17 ( V_20 ) , 0x0 , L_17 ,
V_37 } } ,
{ & V_28 ,
{ L_18 , L_19 , V_35 , V_36 ,
F_17 ( V_38 ) , 0x0 , L_20 ,
V_37 } } ,
{ & V_29 ,
{ L_21 , L_22 , V_35 , V_36 ,
F_17 ( V_20 ) , 0x0 , L_23 ,
V_37 } } ,
} ;
static T_7 * V_39 [] = {
& V_19 ,
} ;
V_17 = F_18 ( L_1 , L_1 , L_24 ) ;
F_19 ( V_17 , V_34 , F_20 ( V_34 ) ) ;
F_21 ( V_39 , F_20 ( V_39 ) ) ;
}
void
F_22 ( void )
{
T_9 V_40 ;
V_40 = F_23 ( F_1 , V_17 ) ;
F_24 ( L_25 , V_41 , V_40 ) ;
}
