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
void * F_9 ( const void * V_5 , T_4 V_2 , T_5 * V_6 ) {
void * V_7 ;
if ( V_2 == 0 ) {
return NULL ;
}
V_7 = F_10 ( V_6 , V_2 ) ;
if ( V_7 == NULL ) {
return NULL ;
}
memcpy ( V_7 , V_5 , V_2 ) ;
return V_7 ;
}
void F_11 ( T_1 * V_8 , T_4 V_9 ) {
T_4 V_10 ;
for ( V_10 = 0 ; V_10 < V_9 ; ++ V_10 ) {
V_8 [ V_10 ] = V_11 [ V_8 [ V_10 ] ] ;
}
}
int F_12 ( T_6 * V_12 ,
T_6 * V_13 ,
T_6 * V_14 ,
T_6 * V_15 ) {
if ( * V_15 > 0 ) {
T_6 V_16 ;
T_6 V_17 ;
T_6 V_18 =
F_13 ( 0 , * V_13 ) - * V_15 ;
if ( V_18 >= 0 ) {
* V_13 = V_18 ;
return 0 ;
}
V_17 = - V_18 ;
if ( * V_12 > V_19 - V_17 ) {
return V_20 ;
}
* V_12 += V_17 ;
V_16 = F_14 ( * V_14 , V_17 ) ;
* V_14 -= V_16 ;
if ( * V_13 < 0 ) {
* V_13 += V_16 ;
} else {
* V_13 = V_16 ;
}
* V_15 -= V_16 ;
return 0 ;
}
if ( * V_12 + * V_15 < 0 ||
* V_13 < V_21 - * V_15 ||
* V_14 > V_22 + * V_15 ) {
return V_20 ;
}
* V_12 += * V_15 ;
* V_13 += * V_15 ;
* V_14 -= * V_15 ;
* V_15 = 0 ;
return 0 ;
}
int F_15 ( T_6 V_23 ,
T_6 V_24 ) {
return V_24 >= V_23 / 2 ;
}
const char * F_16 ( int V_25 ) {
switch ( V_25 ) {
case 0 :
return L_1 ;
case V_26 :
return L_2 ;
case V_27 :
return L_3 ;
case V_28 :
return L_4 ;
case V_29 :
return L_5 ;
case V_30 :
return L_6 ;
case V_31 :
return L_7 ;
case V_32 :
return L_8 ;
case V_33 :
return L_9 ;
case V_34 :
return L_10 ;
case V_35 :
return L_11 ;
case V_36 :
return L_12 ;
case V_37 :
return L_13 ;
case V_38 :
return L_14 ;
case V_39 :
return L_15 ;
case V_40 :
return L_16 ;
case V_41 :
return L_17 ;
case V_42 :
return L_18 ;
case V_43 :
return L_19 ;
case V_44 :
return L_20 ;
case V_45 :
return L_21 ;
case V_46 :
return L_22 ;
case V_47 :
return L_23 ;
case V_20 :
return L_24 ;
case V_48 :
return L_25 ;
case V_49 :
return L_26 ;
case V_50 :
return L_27 ;
case V_51 :
return L_28 ;
case V_52 :
return L_29 ;
case V_53 :
return L_30 ;
case V_54 :
return L_31 ;
case V_55 :
return L_32 ;
case V_56 :
return L_33 ;
case V_57 :
return L_34 ;
case V_58 :
return L_35 ;
case V_59 :
return L_36 ;
case V_60 :
return L_37 ;
default:
return L_38 ;
}
}
int F_17 ( const T_1 * V_61 , T_4 V_9 ) {
const T_1 * V_62 ;
if ( V_9 == 0 ) {
return 0 ;
}
if ( * V_61 == ':' ) {
if ( V_9 == 1 ) {
return 0 ;
}
++ V_61 ;
-- V_9 ;
}
for ( V_62 = V_61 + V_9 ; V_61 != V_62 ; ++ V_61 ) {
if ( ! V_63 [ * V_61 ] ) {
return 0 ;
}
}
return 1 ;
}
int F_18 ( const T_1 * V_64 , T_4 V_9 ) {
const T_1 * V_62 ;
for ( V_62 = V_64 + V_9 ; V_64 != V_62 ; ++ V_64 ) {
if ( ! V_65 [ * V_64 ] ) {
return 0 ;
}
}
return 1 ;
}
T_1 * F_19 ( T_1 * V_7 , const void * V_5 , T_4 V_9 ) {
memcpy ( V_7 , V_5 , V_9 ) ;
return V_7 + V_9 ;
}
