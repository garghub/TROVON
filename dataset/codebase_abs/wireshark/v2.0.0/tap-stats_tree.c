static void
F_1 ( void * V_1 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
T_2 * V_3 ;
V_3 = F_2 ( V_2 , V_4 , F_3 ( V_2 ) ,
F_4 ( V_2 ) ) ;
printf ( L_1 , V_3 -> V_5 ) ;
F_5 ( V_3 , TRUE ) ;
}
static void
F_6 ( const char * V_6 , void * T_3 V_7 )
{
char * V_8 = F_7 ( V_6 ) ;
T_2 * V_9 ;
T_4 * V_10 = NULL ;
T_1 * V_2 = NULL ;
if ( V_8 ) {
V_10 = F_8 ( V_8 ) ;
if ( V_10 != NULL ) {
if ( strncmp ( V_6 , V_10 -> V_11 -> V_12 , strlen ( V_10 -> V_11 -> V_12 ) ) == 0 ) {
V_2 = F_9 ( V_10 , NULL , V_6 + strlen ( V_10 -> V_11 -> V_12 ) ) ;
} else {
F_10 ( L_2 , V_8 ) ;
return;
}
} else {
F_10 ( L_3 , V_8 ) ;
return;
}
F_11 ( V_8 ) ;
} else {
F_10 ( L_4 , V_8 , V_6 ) ;
return;
}
V_9 = F_12 ( V_2 -> V_10 -> V_13 ,
V_2 ,
V_2 -> V_14 ,
V_2 -> V_10 -> V_15 ,
V_16 ,
V_17 ,
F_1 ) ;
if ( V_9 ) {
F_10 ( L_5 , V_10 -> V_18 , V_9 -> V_5 ) ;
return;
}
if ( V_10 -> V_19 ) V_10 -> V_19 ( V_2 ) ;
}
static void
F_13 ( T_5 T_6 V_7 , T_5 V_20 , T_5 T_7 V_7 )
{
T_4 * V_10 = ( T_4 * ) V_20 ;
T_8 V_21 ;
V_10 -> V_11 = ( V_22 * ) F_14 ( sizeof( V_22 ) ) ;
V_10 -> V_11 -> V_12 = F_15 ( L_6 , V_10 -> V_8 ) ;
V_21 . V_23 = V_24 ;
V_21 . V_25 = NULL ;
V_21 . V_26 = V_10 -> V_11 -> V_12 ;
V_21 . V_27 = F_6 ;
V_21 . V_28 = 0 ;
V_21 . V_29 = NULL ;
F_16 ( & V_21 , NULL ) ;
}
static void
F_17 ( T_1 * V_2 )
{
F_11 ( V_2 -> V_11 ) ;
}
void
F_18 ( void )
{
F_19 ( F_13 , NULL ,
F_17 , NULL ) ;
}
