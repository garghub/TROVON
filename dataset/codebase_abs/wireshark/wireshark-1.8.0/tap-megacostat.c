static void
F_1 ( void * V_1 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
int V_3 ;
printf ( L_1 ) ;
printf ( L_2 ) ;
printf ( L_3 ) ;
printf ( L_4 , V_2 -> V_4 ? V_2 -> V_4 : L_5 ) ;
printf ( L_6 , V_2 -> V_5 ) ;
printf ( L_7 , V_2 -> V_6 ) ;
printf ( L_8 , V_2 -> V_7 ) ;
printf ( L_9 , V_2 -> V_8 ) ;
printf ( L_10 ) ;
for( V_3 = 0 ; V_3 < V_9 ; V_3 ++ ) {
if( V_2 -> V_10 [ V_3 ] . V_11 ) {
printf ( L_11 ,
F_2 ( V_3 , V_12 , L_12 ) , V_2 -> V_10 [ V_3 ] . V_11 ,
F_3 ( & ( V_2 -> V_10 [ V_3 ] . V_13 ) ) , F_3 ( & ( V_2 -> V_10 [ V_3 ] . V_14 ) ) ,
F_4 ( & ( V_2 -> V_10 [ V_3 ] . V_15 ) , V_2 -> V_10 [ V_3 ] . V_11 ) ,
V_2 -> V_10 [ V_3 ] . V_16 , V_2 -> V_10 [ V_3 ] . V_17
) ;
}
}
printf ( L_2 ) ;
}
static void
F_5 ( const char * V_18 , void * T_2 V_19 )
{
T_1 * V_2 ;
int V_3 ;
T_3 * V_20 ;
T_4 * V_21 , * V_22 ;
V_21 = F_6 ( F_7 ( L_13 ) , L_14 ) ;
V_22 = F_6 ( F_7 ( L_15 ) , L_14 ) ;
if ( ! V_21 || ! V_22 ) {
return;
}
if ( ! * V_21 -> V_23 . V_24 || ! * V_22 -> V_23 . V_24 ) {
printf ( L_16 ) ;
printf ( L_17 ) ;
exit ( 1 ) ;
}
V_2 = F_8 ( sizeof( T_1 ) ) ;
if( ! strncmp ( V_18 , L_18 , 11 ) ) {
V_2 -> V_4 = F_9 ( V_18 + 11 ) ;
} else {
V_2 -> V_4 = NULL ;
}
for( V_3 = 0 ; V_3 < V_9 ; V_3 ++ ) {
V_2 -> V_10 [ V_3 ] . V_11 = 0 ;
V_2 -> V_10 [ V_3 ] . V_16 = 0 ;
V_2 -> V_10 [ V_3 ] . V_17 = 0 ;
V_2 -> V_10 [ V_3 ] . V_13 . V_25 = 0 ;
V_2 -> V_10 [ V_3 ] . V_13 . V_26 = 0 ;
V_2 -> V_10 [ V_3 ] . V_14 . V_25 = 0 ;
V_2 -> V_10 [ V_3 ] . V_14 . V_26 = 0 ;
V_2 -> V_10 [ V_3 ] . V_15 . V_25 = 0 ;
V_2 -> V_10 [ V_3 ] . V_15 . V_26 = 0 ;
}
V_2 -> V_7 = 0 ;
V_2 -> V_8 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = 0 ;
V_20 = F_10 ( L_13 , V_2 , V_2 -> V_4 , 0 , NULL , V_27 , F_1 ) ;
if( V_20 ) {
F_11 ( V_2 -> V_4 ) ;
F_11 ( V_2 ) ;
fprintf ( V_28 , L_19 ,
V_20 -> V_29 ) ;
F_12 ( V_20 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_13 ( void )
{
if ( F_14 ( L_13 ) ) {
F_15 ( L_20 , F_5 , NULL ) ;
}
}
