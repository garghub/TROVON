static T_1
F_1 ( T_2 * V_1 ) {
T_3 * V_2 ;
T_3 * V_3 = F_2 ( F_3 ( V_4 ) , V_5 ) ;
V_2 = F_4 ( V_3 ) ;
while ( V_2 ) {
if ( V_2 -> V_6 && strcmp ( V_1 , V_2 -> V_6 ) == 0 ) {
V_3 = F_5 ( V_3 , V_2 -> V_6 ) ;
break;
}
V_2 = V_2 -> V_7 ;
}
V_3 = F_6 ( V_3 , V_1 ) ;
F_7 ( F_3 ( V_4 ) , V_5 , V_3 ) ;
return TRUE ;
}
void
F_8 ( T_4 * V_8 ) {
T_3 * V_9 = F_2 ( F_3 ( V_4 ) , V_5 ) ;
T_3 * V_2 ;
T_5 V_10 = 0 ;
V_2 = F_4 ( V_9 ) ;
while ( V_2 && ( V_10 ++ <= V_11 ) ) {
if ( V_2 -> V_6 && strlen ( V_2 -> V_6 ) ) {
fprintf ( V_8 , V_12 L_1 , ( char * ) V_2 -> V_6 ) ;
}
V_2 = V_2 -> V_7 ;
}
}
T_1
F_9 ( T_2 * V_1 ) {
T_2 * V_13 ;
if ( V_1 ) {
V_13 = F_10 ( V_1 ) ;
if ( ! F_1 ( V_13 ) ) {
F_11 ( V_13 ) ;
return FALSE ;
}
}
return TRUE ;
}
