static void
F_1 ( void * V_1 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
T_2 * V_3 = ( T_2 * ) V_2 -> V_4 ;
T_3 * V_5 ;
T_4 V_6 , V_7 ;
T_5 V_8 ;
T_6 V_9 = ( ! strncmp ( V_3 -> type , L_1 , 3 ) || ! strncmp ( V_3 -> type , L_2 , 3 ) || ! strncmp ( V_3 -> type , L_3 , 4 ) ) ? TRUE : FALSE ;
printf ( L_4 ) ;
printf ( L_5 , V_3 -> type ) ;
printf ( L_6 , V_3 -> V_10 ? V_3 -> V_10 : L_7 ) ;
printf ( L_8 ,
V_9 ? L_9 : L_10 ) ;
V_7 = V_11 ;
do {
V_6 = 0 ;
for ( V_8 = 0 ; ( V_3 -> V_2 . V_12 && V_8 < V_3 -> V_2 . V_12 -> V_13 ) ; V_8 ++ ) {
T_4 V_14 ;
V_5 = & F_2 ( V_3 -> V_2 . V_12 , T_3 , V_8 ) ;
V_14 = V_5 -> V_15 + V_5 -> V_16 ;
if ( ( V_14 > V_6 ) && ( V_14 < V_7 ) ) {
V_6 = V_14 ;
}
}
for ( V_8 = 0 ; ( V_3 -> V_2 . V_12 && V_8 < V_3 -> V_2 . V_12 -> V_13 ) ; V_8 ++ ) {
T_4 V_14 ;
T_7 * V_17 , * V_18 ;
V_5 = & F_2 ( V_3 -> V_2 . V_12 , T_3 , V_8 ) ;
V_14 = V_5 -> V_15 + V_5 -> V_16 ;
if ( V_14 == V_6 ) {
V_17 = ( char * ) F_3 ( NULL , & V_5 -> V_19 , TRUE ) ;
if ( V_9 ) {
V_18 = ( char * ) F_4 ( NULL , V_5 -> V_20 , V_5 -> V_21 , TRUE ) ;
printf ( L_11 V_22 L_12 V_22
L_13 V_22 L_14 V_22 L_15
V_22 L_14 V_22 L_16 ,
V_17 ,
V_18 ,
V_5 -> V_16 + V_5 -> V_15 , V_5 -> V_23 + V_5 -> V_24 ,
V_5 -> V_16 , V_5 -> V_23 ,
V_5 -> V_15 , V_5 -> V_24 ) ;
F_5 ( NULL , V_18 ) ;
} else {
printf ( L_17 V_22 L_12 V_22
L_13 V_22 L_14 V_22 L_15
V_22 L_14 V_22 L_16 ,
V_17 ,
V_5 -> V_16 + V_5 -> V_15 , V_5 -> V_23 + V_5 -> V_24 ,
V_5 -> V_16 , V_5 -> V_23 ,
V_5 -> V_15 , V_5 -> V_24 ) ;
}
F_5 ( NULL , V_17 ) ;
}
}
V_7 = V_6 ;
} while ( V_6 );
printf ( L_4 ) ;
}
void F_6 ( struct V_25 * V_26 , const char * V_10 )
{
T_2 * V_3 ;
T_8 * V_27 ;
V_3 = F_7 ( T_2 , 1 ) ;
V_3 -> type = F_8 ( F_9 ( F_10 ( V_26 ) ) ) ;
V_3 -> V_10 = F_11 ( V_10 ) ;
V_3 -> V_2 . V_4 = V_3 ;
V_27 = F_12 ( F_13 ( F_10 ( V_26 ) ) , & V_3 -> V_2 , V_10 , 0 , NULL , F_14 ( V_26 ) , F_1 ) ;
if ( V_27 ) {
F_15 ( V_3 ) ;
fprintf ( V_28 , L_18 ,
V_27 -> V_29 ) ;
F_16 ( V_27 , TRUE ) ;
exit ( 1 ) ;
}
}
