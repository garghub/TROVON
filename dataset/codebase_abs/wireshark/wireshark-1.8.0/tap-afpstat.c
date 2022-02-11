static int
F_1 ( void * V_1 , T_1 * V_2 , T_2 * T_3 V_3 , const void * V_4 )
{
T_4 * V_5 = ( T_4 * ) V_1 ;
const T_5 * V_6 = V_4 ;
T_6 V_7 , V_8 ;
T_7 * V_9 = NULL ;
if( ! V_6 ) {
return 0 ;
}
V_9 = & ( V_5 -> V_10 [ V_6 -> V_11 ] ) ;
V_7 = V_2 -> V_12 -> V_13 ;
F_2 ( & V_8 , & V_7 , & V_6 -> V_14 ) ;
if( V_9 ) {
F_3 ( V_9 , & V_8 , V_2 ) ;
}
return 1 ;
}
static void
F_4 ( void * V_1 )
{
T_4 * V_5 = ( T_4 * ) V_1 ;
T_8 V_15 ;
T_9 V_16 ;
printf ( L_1 ) ;
printf ( L_2 ) ;
printf ( L_3 ) ;
printf ( L_4 , V_5 -> V_17 ? V_5 -> V_17 : L_5 ) ;
printf ( L_6 ) ;
for( V_15 = 0 ; V_15 < 256 ; V_15 ++ ) {
if( V_5 -> V_10 [ V_15 ] . V_18 == 0 ) {
continue;
}
V_16 = V_5 -> V_10 [ V_15 ] . V_19 . V_20 ;
V_16 = V_16 * 100000 + ( int ) V_5 -> V_10 [ V_15 ] . V_19 . V_21 / 10000 ;
if( V_5 -> V_10 [ V_15 ] . V_18 ) {
V_16 /= V_5 -> V_10 [ V_15 ] . V_18 ;
} else {
V_16 = 0 ;
}
printf ( L_7 V_22 L_8 V_22 L_9 ,
F_5 ( V_15 , & V_23 , L_10 ) ,
V_5 -> V_10 [ V_15 ] . V_18 ,
( int ) V_5 -> V_10 [ V_15 ] . V_24 . V_20 , V_5 -> V_10 [ V_15 ] . V_24 . V_21 / 10000 ,
( int ) V_5 -> V_10 [ V_15 ] . V_25 . V_20 , V_5 -> V_10 [ V_15 ] . V_25 . V_21 / 10000 ,
V_16 / 100000 , V_16 % 100000
) ;
}
printf ( L_2 ) ;
}
static void
F_6 ( const char * V_26 , void * T_10 V_3 )
{
T_4 * V_5 ;
T_8 V_15 ;
const char * V_17 = NULL ;
T_11 * V_27 ;
if( ! strncmp ( V_26 , L_11 , 8 ) ) {
V_17 = V_26 + 8 ;
} else {
V_17 = NULL ;
}
V_5 = F_7 ( sizeof( T_4 ) ) ;
if( V_17 ) {
V_5 -> V_17 = F_8 ( V_17 ) ;
} else {
V_5 -> V_17 = NULL ;
}
for( V_15 = 0 ; V_15 < 256 ; V_15 ++ ) {
V_5 -> V_10 [ V_15 ] . V_18 = 0 ;
V_5 -> V_10 [ V_15 ] . V_28 = 0 ;
V_5 -> V_10 [ V_15 ] . V_29 = 0 ;
V_5 -> V_10 [ V_15 ] . V_24 . V_20 = 0 ;
V_5 -> V_10 [ V_15 ] . V_24 . V_21 = 0 ;
V_5 -> V_10 [ V_15 ] . V_25 . V_20 = 0 ;
V_5 -> V_10 [ V_15 ] . V_25 . V_21 = 0 ;
V_5 -> V_10 [ V_15 ] . V_19 . V_20 = 0 ;
V_5 -> V_10 [ V_15 ] . V_19 . V_21 = 0 ;
}
V_27 = F_9 ( L_12 , V_5 , V_17 , 0 , NULL , F_1 , F_4 ) ;
if( V_27 ) {
F_10 ( V_5 -> V_17 ) ;
F_10 ( V_5 ) ;
fprintf ( V_30 , L_13 ,
V_27 -> V_31 ) ;
F_11 ( V_27 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_12 ( void )
{
F_13 ( L_14 , F_6 , NULL ) ;
}
