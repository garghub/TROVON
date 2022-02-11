static void
F_1 ( void * T_1 V_1 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
char V_8 [ V_9 ] ;
int V_10 , V_11 ;
printf ( L_1 ) ;
printf ( L_2 ) ;
printf ( L_3 , V_12 . V_13 ) ;
printf ( L_4 ) ;
for ( V_3 = F_2 () ; V_3 ; V_3 = V_3 -> V_14 ) {
if ( ! V_15 || V_3 -> V_16 != V_17 ) {
continue;
}
V_5 = (struct V_4 * ) ( void * ) V_3 -> V_18 ;
if ( F_3 ( V_17 , & ( V_5 -> V_19 . V_20 ) , V_8 , V_9 ) ) {
V_11 = ( V_21 - ( int ) strlen ( V_8 ) ) / 8 ;
printf ( L_5 , V_8 ) ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
printf ( L_6 ) ;
printf ( L_7 , V_3 -> V_22 ) ;
}
}
for ( V_3 = F_2 () ; V_3 ; V_3 = V_3 -> V_14 ) {
if ( ! V_23 || V_3 -> V_16 != V_24 ) {
continue;
}
V_7 = (struct V_6 * ) ( void * ) V_3 -> V_18 ;
if ( F_3 ( V_24 , V_7 -> V_25 . V_26 , V_8 , V_9 ) ) {
V_11 = ( V_21 - ( int ) strlen ( V_8 ) ) / 8 ;
printf ( L_5 , V_8 ) ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
printf ( L_6 ) ;
printf ( L_7 , V_3 -> V_22 ) ;
}
}
}
static void
F_4 ( const char * V_27 , void * T_2 V_1 )
{
T_3 * V_28 ;
T_4 * * V_29 ;
T_5 V_30 ;
V_15 = FALSE ;
V_23 = FALSE ;
if( strcmp ( V_31 , V_27 ) == 0 ) {
V_15 = TRUE ;
V_23 = TRUE ;
} else {
V_29 = F_5 ( V_27 , L_8 , 0 ) ;
V_30 = 0 ;
while ( V_29 [ V_30 ] ) {
if ( strcmp ( L_9 , V_29 [ V_30 ] ) == 0 ) {
V_15 = TRUE ;
} else if ( strcmp ( L_10 , V_29 [ V_30 ] ) == 0 ) {
V_23 = TRUE ;
} else if ( V_30 > 0 ) {
fprintf ( V_32 , L_11 V_31 L_12 ) ;
exit ( 1 ) ;
}
V_30 ++ ;
}
F_6 ( V_29 ) ;
}
V_28 = F_7 ( L_13 , NULL , NULL , V_33 ,
NULL , NULL , F_1 ) ;
if( V_28 ) {
fprintf ( V_32 , L_14 V_31 L_15 ,
V_28 -> V_34 ) ;
F_8 ( V_28 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_9 ( void )
{
F_10 ( V_31 , F_4 , NULL ) ;
}
