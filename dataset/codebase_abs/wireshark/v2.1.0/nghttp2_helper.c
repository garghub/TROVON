void F_1 ( T_1 * V_1 , T_2 V_2 ) {
T_2 V_3 = F_2 ( V_2 ) ;
memcpy ( V_1 , & V_3 , sizeof( T_2 ) ) ;
}
void F_3 ( T_1 * V_1 , T_3 V_2 ) {
T_3 V_3 = F_4 ( V_2 ) ;
memcpy ( V_1 , & V_3 , sizeof( T_3 ) ) ;
}
T_2 F_5 ( const T_1 * V_4 ) {
T_2 V_2 ;
memcpy ( & V_2 , V_4 , sizeof( T_2 ) ) ;
return F_6 ( V_2 ) ;
}
T_3 F_7 ( const T_1 * V_4 ) {
T_3 V_2 ;
memcpy ( & V_2 , V_4 , sizeof( T_3 ) ) ;
return F_8 ( V_2 ) ;
}
void F_9 ( T_1 * V_5 , T_4 V_6 ) {
T_4 V_7 ;
for ( V_7 = 0 ; V_7 < V_6 ; ++ V_7 ) {
V_5 [ V_7 ] = V_8 [ V_5 [ V_7 ] ] ;
}
}
int F_10 ( T_5 * V_9 ,
T_5 * V_10 ,
T_5 * V_11 ,
T_5 * V_12 ) {
if ( * V_12 > 0 ) {
T_5 V_13 ;
T_5 V_14 ;
T_5 V_15 =
F_11 ( 0 , * V_10 ) - * V_12 ;
if ( V_15 >= 0 ) {
* V_10 = V_15 ;
return 0 ;
}
V_14 = - V_15 ;
if ( * V_9 > V_16 - V_14 ) {
return V_17 ;
}
* V_9 += V_14 ;
V_13 = F_12 ( * V_11 , V_14 ) ;
* V_11 -= V_13 ;
if ( * V_10 < 0 ) {
* V_10 += V_13 ;
} else {
* V_10 = V_13 ;
}
* V_12 -= V_13 ;
return 0 ;
}
if ( * V_9 + * V_12 < 0 ||
* V_10 < V_18 - * V_12 ||
* V_11 > V_19 + * V_12 ) {
return V_17 ;
}
* V_9 += * V_12 ;
* V_10 += * V_12 ;
* V_11 -= * V_12 ;
* V_12 = 0 ;
return 0 ;
}
int F_13 ( T_5 V_20 ,
T_5 V_21 ) {
return V_21 > 0 && V_21 >= V_20 / 2 ;
}
const char * F_14 ( int V_22 ) {
switch ( V_22 ) {
case 0 :
return L_1 ;
case V_23 :
return L_2 ;
case V_24 :
return L_3 ;
case V_25 :
return L_4 ;
case V_26 :
return L_5 ;
case V_27 :
return L_6 ;
case V_28 :
return L_7 ;
case V_29 :
return L_8 ;
case V_30 :
return L_9 ;
case V_31 :
return L_10 ;
case V_32 :
return L_11 ;
case V_33 :
return L_12 ;
case V_34 :
return L_13 ;
case V_35 :
return L_14 ;
case V_36 :
return L_15 ;
case V_37 :
return L_16 ;
case V_38 :
return L_17 ;
case V_39 :
return L_18 ;
case V_40 :
return L_19 ;
case V_41 :
return L_20 ;
case V_42 :
return L_21 ;
case V_43 :
return L_22 ;
case V_44 :
return L_23 ;
case V_17 :
return L_24 ;
case V_45 :
return L_25 ;
case V_46 :
return L_26 ;
case V_47 :
return L_27 ;
case V_48 :
return L_28 ;
case V_49 :
return L_29 ;
case V_50 :
return L_30 ;
case V_51 :
return L_31 ;
case V_52 :
return L_32 ;
case V_53 :
return L_33 ;
case V_54 :
return L_34 ;
case V_55 :
return L_35 ;
case V_56 :
return L_36 ;
case V_57 :
return L_37 ;
case V_58 :
return L_38 ;
case V_59 :
return L_39
L_40 ;
default:
return L_41 ;
}
}
int F_15 ( const T_1 * V_60 , T_4 V_6 ) {
const T_1 * V_61 ;
if ( V_6 == 0 ) {
return 0 ;
}
if ( * V_60 == ':' ) {
if ( V_6 == 1 ) {
return 0 ;
}
++ V_60 ;
-- V_6 ;
}
for ( V_61 = V_60 + V_6 ; V_60 != V_61 ; ++ V_60 ) {
if ( ! V_62 [ * V_60 ] ) {
return 0 ;
}
}
return 1 ;
}
int F_16 ( const T_1 * V_63 , T_4 V_6 ) {
const T_1 * V_61 ;
for ( V_61 = V_63 + V_6 ; V_63 != V_61 ; ++ V_63 ) {
if ( ! V_64 [ * V_63 ] ) {
return 0 ;
}
}
return 1 ;
}
T_1 * F_17 ( T_1 * V_65 , const void * V_66 , T_4 V_6 ) {
memcpy ( V_65 , V_66 , V_6 ) ;
return V_65 + V_6 ;
}
const char * F_18 ( T_3 V_22 ) {
switch ( V_22 ) {
case V_67 :
return L_42 ;
case V_68 :
return L_43 ;
case V_69 :
return L_44 ;
case V_70 :
return L_45 ;
case V_71 :
return L_46 ;
case V_72 :
return L_47 ;
case V_73 :
return L_48 ;
case V_74 :
return L_49 ;
case V_75 :
return L_50 ;
case V_76 :
return L_51 ;
case V_77 :
return L_52 ;
case V_78 :
return L_53 ;
case V_79 :
return L_54 ;
case V_80 :
return L_55 ;
default:
return L_56 ;
}
}
