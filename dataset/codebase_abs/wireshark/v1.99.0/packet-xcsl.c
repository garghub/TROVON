static T_1 F_1 ( T_2 * V_1 , T_3 V_2 , T_3 V_3 , T_4 * V_4 , T_3 * V_5 , T_5 * V_6 )
{
T_5 V_7 = 0 ;
T_4 V_8 ;
while ( V_3 > 1 ) {
V_8 = F_2 ( V_1 , V_2 + V_7 ) ;
if ( V_8 == ';' || V_8 == '\r' || V_8 == '\n' )
break;
if ( V_7 == V_9 ) {
* V_5 = V_2 + V_7 ;
* V_6 = V_7 ;
return FALSE ;
}
V_4 [ V_7 ++ ] = V_8 ;
V_3 -- ;
}
V_4 [ V_7 ] = '\0' ;
* V_5 = V_2 + V_7 ;
* V_6 = V_7 ;
return TRUE ;
}
static void F_3 ( T_2 * V_1 , T_6 * V_10 , T_7 * V_11 ) {
T_5 V_2 = 0 ;
T_3 V_12 ;
T_4 V_7 ;
T_1 V_13 ;
T_4 V_14 ;
T_4 V_4 [ V_9 ] ;
T_4 V_15 ;
const T_8 * V_16 ;
T_5 V_6 ;
T_3 V_5 ;
T_7 * V_17 = NULL ;
F_4 ( V_10 -> V_18 , V_19 , L_1 ) ;
F_5 ( V_10 -> V_18 , V_20 ) ;
if ( V_11 ) {
T_9 * V_21 ;
V_21 = F_6 ( V_11 , V_22 , V_1 , V_2 , - 1 , V_23 ) ;
V_17 = F_7 ( V_21 , V_24 ) ;
}
V_7 = 0 ;
V_14 = 0 ;
V_13 = FALSE ;
while ( F_8 ( V_1 , V_2 ) != 0 ) {
V_12 = F_9 ( V_1 , V_2 ) ;
if ( V_12 == - 1 ) {
return;
}
if ( ! ( F_1 ( V_1 , V_2 , V_12 , V_4 , & V_5 , & V_6 ) ) ) {
return;
}
if ( strlen ( V_4 ) == 0 ) {
V_2 = V_5 + 1 ;
continue;
}
switch ( V_7 ) {
case 0 :
F_6 ( V_17 , & V_25 , V_1 , V_2 , V_6 , V_26 | V_23 ) ;
break;
case 1 :
if ( isdigit ( V_4 [ 0 ] ) ) {
F_6 ( V_17 , & V_27 , V_1 , V_2 , V_6 , V_26 | V_23 ) ;
} else {
F_6 ( V_17 , & V_28 , V_1 , V_2 , V_6 , V_26 | V_23 ) ;
}
F_10 ( V_10 -> V_18 , V_20 , L_2 , V_4 ) ;
break;
case 2 :
if ( isdigit ( V_4 [ 0 ] ) ) {
T_9 * V_21 ;
V_13 = FALSE ;
V_15 = atoi ( V_4 ) ;
if ( V_15 >= V_29 ) {
V_15 = V_30 ;
}
V_16 = F_11 ( V_15 , V_31 , L_3 ) ;
V_21 = F_6 ( V_17 , & V_32 , V_1 , V_2 , V_6 , V_26 | V_23 ) ;
F_12 ( V_21 , L_4 , V_16 ) ;
if ( V_15 != 0 )
F_10 ( V_10 -> V_18 , V_20 , L_5 , V_16 ) ;
} else {
V_13 = TRUE ;
F_6 ( V_17 , & V_33 , V_1 , V_2 , V_6 , V_26 | V_23 ) ;
F_10 ( V_10 -> V_18 , V_20 , L_2 , V_4 ) ;
}
break;
default:
F_6 ( V_17 , & V_34 , V_1 , V_2 , V_6 , V_26 | V_23 ) ;
if ( V_13 == TRUE ) {
F_10 ( V_10 -> V_18 , V_20 , L_6 , V_4 ) ;
} else {
if ( V_14 == 0 ) {
F_10 ( V_10 -> V_18 , V_20 , L_7 , V_4 ) ;
} else {
F_10 ( V_10 -> V_18 , V_20 , L_6 , V_4 ) ;
}
}
V_14 ++ ;
break;
}
V_2 = V_5 + 1 ;
V_7 ++ ;
}
return;
}
static T_1 F_13 ( T_2 * V_1 , T_6 * V_10 , T_7 * V_11 , void * T_10 V_35 ) {
T_3 V_2 = 0 ;
T_4 * V_36 ;
if ( F_14 ( V_1 , V_2 ) >= 5 ) {
V_36 = F_15 ( F_16 () , V_1 , V_2 , 5 , V_26 ) ;
if ( strncmp ( V_36 , L_8 , 4 ) == 0 && ( V_36 [ 4 ] == ';' || V_36 [ 4 ] == '-' ) ) {
F_3 ( V_1 , V_10 , V_11 ) ;
return TRUE ;
}
}
return FALSE ;
}
void F_17 ( void ) {
#ifndef F_18
static T_11 * V_37 [] = {
& V_25 ,
& V_27 ,
& V_33 ,
& V_32 ,
& V_34 ,
& V_28 ,
} ;
#endif
static T_3 * V_38 [] = {
& V_24
} ;
int V_39 ;
V_39 = F_19 ( L_9 , L_10 , L_8 ) ;
V_22 = F_20 ( V_39 ) ;
F_21 ( V_39 , V_37 , F_22 ( V_37 ) ) ;
F_23 ( V_38 , F_22 ( V_38 ) ) ;
}
void F_24 ( void ) {
F_25 ( L_11 , F_13 , V_22 -> V_40 ) ;
}
