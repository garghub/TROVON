static void
F_1 ( const T_1 type , const T_1 V_1 , int V_2 ,
T_1 V_3 , T_2 * V_4 , T_3 * V_5 ) {
T_1 V_6 = 0 ;
T_4 * V_7 ;
T_3 * V_8 = NULL ;
V_7 = F_2 ( V_5 , V_4 , V_2 , V_3 ,
L_1 ,
F_3 ( type , V_9 , L_2 ) ) ;
V_8 = F_4 ( V_7 , V_10 ) ;
if ( V_11 == type ) {
V_6 = V_1 & V_12 ;
if ( V_6 ) {
F_2 ( V_8 , V_4 , V_2 , V_3 , L_3 ,
F_3 ( V_6 , V_13 , L_2 ) ) ;
}
V_6 = V_1 & V_14 ;
if ( V_6 ) {
F_2 ( V_8 , V_4 , V_2 , V_3 , L_3 ,
F_3 ( V_6 , V_13 , L_2 ) ) ;
}
V_6 = V_1 & V_15 ;
if ( V_6 ) {
F_2 ( V_8 , V_4 , V_2 , V_3 , L_3 ,
F_3 ( V_6 , V_13 , L_2 ) ) ;
}
V_6 = V_1 & V_16 ;
if ( V_6 ) {
F_2 ( V_8 , V_4 , V_2 , V_3 , L_3 ,
F_3 ( V_6 , V_13 , L_2 ) ) ;
}
V_6 = V_1 & V_17 ;
if ( V_6 ) {
F_2 ( V_8 , V_4 , V_2 , V_3 , L_3 ,
F_3 ( V_6 , V_13 , L_2 ) ) ;
}
V_6 = V_1 & V_18 ;
if ( V_6 ) {
F_2 ( V_8 , V_4 , V_2 , V_3 , L_3 ,
F_3 ( V_6 , V_13 , L_2 ) ) ;
}
}
}
static void
F_5 ( T_1 V_19 , int V_2 , T_1 V_20 ,
T_2 * V_4 , T_3 * V_5 ) {
T_1 V_21 = 0 ;
T_5 V_22 = 0 ;
T_1 V_23 = 0 ;
T_1 V_24 = 0 ;
T_1 V_25 = 0 ;
T_1 V_26 = 0 ;
T_4 * V_7 ;
T_3 * V_27 = NULL ;
if ( V_19 == V_28 ) {
V_21 = F_6 ( V_4 , V_2 + 1 ) ;
V_23 = F_6 ( V_4 , V_21 + 2 ) ;
V_22 = V_2 + 2 ;
F_2 ( V_5 , V_4 , V_2 + V_21 , V_23 ,
L_4 ,
( F_6 ( V_4 , V_2 ) == 0 ) ? L_5 :
L_6 ) ;
}
else if ( V_19 == V_29 ) {
V_26 = F_6 ( V_4 , V_2 ) ;
V_24 = F_6 ( V_4 , V_2 + 1 ) ;
V_7 = F_2 ( V_5 , V_4 , V_2 , V_20 ,
L_7 ,
( V_26 == 0 ) ? L_8 :
L_9 ) ;
V_27 = F_4 ( V_7 , V_30 ) ;
if ( V_26 == 0 )
F_2 ( V_27 , V_4 , V_2 , 1 ,
L_8 ) ;
if ( V_26 == 1 )
F_2 ( V_27 , V_4 , V_2 , 1 ,
L_9 ) ;
if ( V_24 == 0x03 )
F_2 ( V_27 , V_4 , V_2 + 1 , 1 ,
L_10 ) ;
if ( V_24 == 0xFF )
F_2 ( V_27 , V_4 , V_2 + 1 , 1 ,
L_11 ) ;
V_23 = F_6 ( V_4 , V_22 + 2 ) ;
if ( V_24 == 255 || V_24 == 0x03 )
V_22 = V_20 + 1 ;
else
V_22 = V_2 + 2 ;
}
while ( V_22 < V_2 + V_24 - 2 ) {
V_23 = F_6 ( V_4 , V_22 ) ;
F_2 ( V_27 , V_4 , V_22 , V_23 + 1 ,
L_12 ,
V_25 ++ ,
V_23 ,
F_7 ( F_8 ( V_4 , V_22 + 1 , V_23 ) , V_23 ) ) ;
V_22 += 1 + V_23 ;
}
}
static void
F_9 ( const T_1 error , const T_1 V_31 , int V_2 ,
T_1 V_3 , T_2 * V_4 , T_3 * V_5 ) {
T_1 V_32 = 0 ;
const char * V_33 [] =
{ L_13 ,
L_14 ,
L_15 ,
L_16 ,
L_17 ,
L_18
} ;
V_32 = error & V_34 ;
F_10 ( V_4 , V_2 + V_31 , 1 ) ;
if ( V_35 == V_32 ) {
F_2 ( V_5 , V_4 , V_2 + V_31 , 1 , V_33 [ 0 ] ,
F_3 ( error & V_36 ,
V_37 , L_2 ) , V_31 ) ;
}
else if ( V_38 == V_32 ) {
F_2 ( V_5 , V_4 , V_2 + V_31 , 1 , V_33 [ 1 ] ,
F_3 ( error & V_36 ,
V_39 , L_2 ) , V_31 ) ;
}
else if ( V_40 == V_32 ) {
F_2 ( V_5 , V_4 , V_2 + V_31 , 1 , V_33 [ 2 ] ,
F_3 ( error & V_36 ,
V_41 , L_2 ) , V_31 ) ;
}
else if ( V_42 == V_32 ) {
F_2 ( V_5 , V_4 , V_2 + V_31 , 1 , V_33 [ 3 ] ,
F_3 ( error & V_36 ,
V_43 , L_2 ) , V_31 ) ;
}
else if ( V_44 == V_32 ) {
F_2 ( V_5 , V_4 , V_2 + V_31 , 1 , V_33 [ 4 ] ,
F_3 ( error & V_36 ,
V_45 , L_2 ) , V_31 ) ;
}
else if ( V_46 == V_32 ) {
F_2 ( V_5 , V_4 , V_2 + V_31 , 1 , V_33 [ 5 ] ,
F_3 ( error & V_36 ,
V_47 , L_2 ) , V_31 ) ;
}
else {
F_2 ( V_5 , V_4 , V_2 , V_3 ,
L_19 ) ;
}
}
void
F_11 ( T_1 V_48 , T_2 * V_4 ,
int V_2 , T_3 * V_5 ) {
T_4 * V_7 ;
T_3 * V_49 = NULL ;
T_1 V_20 = 0 ;
T_1 V_19 = 0 ;
T_6 V_50 ;
if ( V_5 ) {
if ( 0 == V_48 ) {
F_2 ( V_5 , V_4 , V_2 , 0 ,
L_20 ) ;
return;
}
V_7 = F_2 ( V_5 , V_4 , V_2 , V_48 ,
L_21 ) ;
V_49 = F_4 ( V_7 , V_51 ) ;
while ( 0 < V_48 ) {
V_19 = ( int ) F_6 ( V_4 , V_2 ) ;
V_2 ++ ;
V_20 = ( int ) F_6 ( V_4 , V_2 ) ;
V_2 ++ ;
switch ( V_19 ) {
case V_52 :
V_50 = F_6 ( V_4 , V_2 ) ;
F_1 ( ( T_1 ) ( V_50 & V_53 ) ,
( T_1 ) ( V_50 & V_54 ) ,
V_2 , V_20 , V_4 , V_49 ) ;
break;
case V_55 :
V_50 = F_6 ( V_4 , V_2 ) ;
F_2 ( V_49 , V_4 , V_2 , V_20 ,
L_22 ,
F_3 ( V_50 & V_11 ,
V_56 , L_2 ) ) ;
break;
case V_57 :
V_50 = F_6 ( V_4 , V_2 ) ;
if ( V_58 >= V_50 ) {
F_2 ( V_49 , V_4 , V_2 , V_20 ,
L_23 , V_50 ) ;
}
else {
F_2 ( V_49 , V_4 , V_2 , V_20 ,
L_24 ,
V_50 ) ;
}
break;
case V_59 :
F_2 ( V_49 , V_4 , V_2 , V_20 ,
L_25 ,
F_12 ( F_8 ( V_4 , V_2 , V_20 ) , V_20 ) ) ;
break;
case V_60 :
F_2 ( V_49 , V_4 , V_2 , V_20 ,
L_26 ,
F_13 ( F_8 ( V_4 , V_2 , V_20 ) , V_20 ) ) ;
break;
case V_61 :
F_2 ( V_49 , V_4 , V_2 , V_20 ,
L_27 , F_14 ( V_4 , V_2 ) ) ;
break;
case V_62 :
F_2 ( V_49 , V_4 , V_2 , V_20 ,
L_28 , V_20 ) ;
break;
case V_28 :
case V_29 :
F_5 ( V_19 ,
V_2 , V_20 , V_4 , V_49 ) ;
break;
case V_63 :
F_9 ( F_6 ( V_4 , V_2 ) ,
F_6 ( V_4 , V_2 + 1 ) ,
V_2 , V_20 , V_4 , V_49 ) ;
break;
}
V_48 -= V_20 + 2 ;
V_2 += V_20 ;
}
}
}
void
F_15 ( void ) {
static T_7 * V_64 [] = {
& V_51 ,
& V_10 ,
& V_30 ,
& V_65 ,
} ;
F_16 ( V_64 , F_17 ( V_64 ) ) ;
}
