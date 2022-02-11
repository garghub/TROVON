static void
F_1 ( T_1 * V_1 , T_2 V_2 )
{
int V_3 ;
T_3 V_4 ;
T_3 V_5 ;
if ( V_1 -> V_6 > 0 ) {
printf ( L_1 , V_1 -> V_7 ? V_1 -> V_7 : L_2 ) ;
printf ( L_3 , ( V_1 -> V_8 != NULL ) ? V_1 -> V_8 : L_4 ) ;
}
for( V_3 = 0 ; V_3 < V_1 -> V_6 ; V_3 ++ ) {
if( V_1 -> V_9 [ V_3 ] . V_10 . V_11 == 0 ) {
continue;
}
V_4 = ( ( T_3 ) ( V_1 -> V_9 [ V_3 ] . V_10 . V_12 . V_13 ) ) * V_14 + V_1 -> V_9 [ V_3 ] . V_10 . V_12 . V_15 ;
V_5 = ( V_4 + 500 ) / 1000 ;
V_4 = ( ( V_4 / V_1 -> V_9 [ V_3 ] . V_10 . V_11 ) + 500 ) / 1000 ;
printf ( L_5 ,
V_3 , V_1 -> V_9 [ V_3 ] . V_16 ,
V_1 -> V_9 [ V_3 ] . V_10 . V_11 ,
( int ) V_1 -> V_9 [ V_3 ] . V_10 . V_17 . V_13 , ( V_1 -> V_9 [ V_3 ] . V_10 . V_17 . V_15 + 500 ) / 1000 ,
( int ) V_1 -> V_9 [ V_3 ] . V_10 . V_18 . V_13 , ( V_1 -> V_9 [ V_3 ] . V_10 . V_18 . V_15 + 500 ) / 1000 ,
( int ) ( V_4 / 1000000 ) , ( int ) ( V_4 % 1000000 ) ,
( int ) ( V_5 / 1000000 ) , ( int ) ( V_5 % 1000000 )
) ;
}
if ( V_2 )
printf ( L_6 ) ;
}
static void
F_2 ( void * V_19 )
{
T_4 V_3 = 0 ;
T_5 * V_20 = ( T_5 * ) V_19 ;
T_6 * V_21 = ( T_6 * ) V_20 -> V_22 ;
T_1 * V_23 ;
T_2 V_24 = FALSE ;
printf ( L_7 ) ;
printf ( L_8 ) ;
printf ( L_9 , V_21 -> type ) ;
V_23 = F_3 ( V_20 -> V_25 , T_1 * , V_3 ) ;
F_1 ( V_23 , V_20 -> V_25 -> V_26 == 1 ) ;
if ( V_23 -> V_6 > 0 ) {
V_24 = TRUE ;
}
for ( V_3 = 1 ; V_3 < V_20 -> V_25 -> V_26 ; V_3 ++ )
{
if ( V_24 )
{
printf ( L_7 ) ;
V_24 = FALSE ;
}
V_23 = F_3 ( V_20 -> V_25 , T_1 * , V_3 ) ;
F_1 ( V_23 , V_3 == V_20 -> V_25 -> V_26 - 1 ) ;
if ( V_23 -> V_6 > 0 ) {
V_24 = TRUE ;
}
}
}
static void
F_4 ( T_7 * V_27 , const char * V_28 )
{
T_6 * V_21 ;
T_8 * V_29 ;
V_21 = F_5 ( T_6 , 1 ) ;
V_21 -> type = F_6 ( F_7 ( F_8 ( V_27 ) ) ) ;
V_21 -> V_28 = F_9 ( V_28 ) ;
V_21 -> V_20 . V_25 = V_30 ;
V_21 -> V_20 . V_22 = V_21 ;
V_29 = F_10 ( F_11 ( V_27 ) , & V_21 -> V_20 , V_28 , 0 , NULL , F_12 ( V_27 ) , F_2 ) ;
if ( V_29 ) {
F_13 ( V_27 , V_30 , NULL , NULL ) ;
F_14 ( V_21 ) ;
fprintf ( V_31 , L_10 , V_29 -> V_32 ) ;
F_15 ( V_29 , TRUE ) ;
exit ( 1 ) ;
}
}
static void
F_16 ( const char * V_33 , void * V_34 )
{
T_7 * V_27 = ( T_7 * ) V_34 ;
const char * V_28 = NULL ;
char * V_35 ;
F_17 ( V_27 , V_33 , & V_28 , & V_35 ) ;
if ( V_35 != NULL )
{
T_9 * V_36 = F_18 ( V_27 ) ;
fprintf ( V_31 , L_11 , V_36 , V_35 ) ;
F_14 ( V_36 ) ;
F_14 ( V_35 ) ;
exit ( 1 ) ;
}
V_30 = F_19 ( FALSE , TRUE , sizeof( T_1 * ) ) ;
F_20 ( V_27 , V_30 , NULL , NULL ) ;
F_4 ( V_27 , V_28 ) ;
}
void
F_21 ( T_10 V_20 , T_10 V_22 V_37 )
{
T_7 * V_27 = ( T_7 * ) V_20 ;
const char * V_38 = F_6 ( F_7 ( F_8 ( V_27 ) ) ) ;
T_11 V_39 ;
if ( strcmp ( V_38 , L_12 ) == 0 )
return;
V_39 . V_40 = V_41 ;
V_39 . V_42 = NULL ;
V_39 . V_43 = F_18 ( V_27 ) ;
V_39 . V_44 = F_16 ;
V_39 . V_45 = 0 ;
V_39 . V_46 = NULL ;
F_22 ( & V_39 , V_27 ) ;
}
