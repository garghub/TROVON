void F_1 ( T_1 * V_1 ) {
V_1 -> V_2 = NULL ;
V_1 -> V_3 = NULL ;
V_1 -> V_4 = 0 ;
}
void F_2 ( T_1 * V_1 , T_2 * V_5 , T_3 * V_6 , T_4 V_7 ) {
T_5 * V_8 ;
V_8 = F_3 ( F_4 () , T_5 ) ;
V_8 -> type = V_9 ;
V_8 -> V_7 = V_7 ;
V_8 -> V_5 = V_5 ;
V_8 -> V_6 = V_6 ;
if ( V_1 -> V_3 ) {
V_1 -> V_3 -> V_10 = V_8 ;
} else {
V_1 -> V_2 = V_8 ;
}
V_8 -> V_10 = NULL ;
V_8 -> V_11 = V_1 -> V_3 ;
V_1 -> V_3 = V_8 ;
V_1 -> V_4 ++ ;
}
void F_5 ( T_1 * V_1 , T_2 * V_5 , T_3 * V_6 , T_6 V_12 , T_7 V_13 ) {
T_5 * V_8 ;
V_8 = F_3 ( F_4 () , T_5 ) ;
V_8 -> type = V_14 ;
V_8 -> V_12 = V_12 ;
V_8 -> V_13 = V_13 ;
V_8 -> V_5 = V_5 ;
V_8 -> V_6 = V_6 ;
if ( V_1 -> V_3 ) {
V_1 -> V_3 -> V_10 = V_8 ;
} else {
V_1 -> V_2 = V_8 ;
}
V_8 -> V_10 = NULL ;
V_8 -> V_11 = V_1 -> V_3 ;
V_1 -> V_3 = V_8 ;
V_1 -> V_4 ++ ;
}
void F_6 ( T_1 * V_1 , T_2 * V_5 , T_3 * V_6 , T_6 V_12 , const T_8 * string ) {
T_5 * V_8 ;
V_8 = F_3 ( F_4 () , T_5 ) ;
V_8 -> type = V_15 ;
V_8 -> V_12 = V_12 ;
V_8 -> string = string ;
V_8 -> V_5 = V_5 ;
V_8 -> V_6 = V_6 ;
if ( V_1 -> V_3 ) {
V_1 -> V_3 -> V_10 = V_8 ;
} else {
V_1 -> V_2 = V_8 ;
}
V_8 -> V_10 = NULL ;
V_8 -> V_11 = V_1 -> V_3 ;
V_1 -> V_3 = V_8 ;
V_1 -> V_4 ++ ;
}
void F_7 ( T_1 * V_1 , T_9 * V_16 , T_3 * V_6 , T_4 V_7 , T_4 V_17 ) {
T_5 * V_8 ;
V_8 = V_1 -> V_2 ;
while ( V_8 ) {
if ( V_8 -> V_5 && F_8 ( V_8 -> V_5 ) ) {
switch ( V_8 -> type ) {
case V_9 :
F_9 ( ( V_8 -> V_7 ) ? V_8 -> V_7 : ( ( V_7 ) ? V_7 : V_17 ) , V_8 -> V_5 , V_16 , ( V_8 -> V_6 ) ? V_8 -> V_6 : V_6 ) ;
break;
case V_14 :
F_10 ( V_8 -> V_12 , V_8 -> V_13 , V_8 -> V_5 , V_16 , ( V_8 -> V_6 ) ? V_8 -> V_6 : V_6 ) ;
break;
case V_15 :
F_11 ( V_8 -> V_12 , V_8 -> string , V_8 -> V_5 , V_16 , ( V_8 -> V_6 ) ? V_8 -> V_6 : V_6 , NULL ) ;
break;
}
}
V_8 = V_8 -> V_10 ;
}
}
