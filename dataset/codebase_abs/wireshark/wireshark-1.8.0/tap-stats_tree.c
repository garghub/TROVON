static void
F_1 ( void * V_1 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
T_2 * V_3 ;
T_3 * V_4 ;
T_4 * V_5 ;
V_3 = F_2 ( L_1 ) ;
V_4 = F_3 ( L_2 , F_4 ( & V_2 -> V_6 , 0 ) ) ;
F_5 ( V_3 , V_4 , L_3 , V_2 -> V_7 -> V_8 , L_4 , L_5 , L_6 ) ;
F_6 ( V_4 ) ;
F_5 ( V_3 , L_7 ) ;
for ( V_5 = V_2 -> V_6 . V_9 ; V_5 ; V_5 = V_5 -> V_10 ) {
F_7 ( V_5 , V_3 , 0 ) ;
}
V_3 = F_8 ( V_3 , L_1 ) ;
printf ( L_8 , V_3 -> V_11 ) ;
}
static void
F_9 ( const char * V_12 , void * T_5 V_13 )
{
char * V_14 = F_10 ( V_12 ) ;
T_2 * V_15 ;
T_6 * V_7 = NULL ;
T_1 * V_2 = NULL ;
if ( V_14 ) {
V_7 = F_11 ( V_14 ) ;
if ( V_7 != NULL ) {
if ( strncmp ( V_12 , V_7 -> V_16 -> V_17 , strlen ( V_7 -> V_16 -> V_17 ) ) == 0 ) {
V_2 = F_12 ( V_7 , NULL , V_12 + strlen ( V_7 -> V_16 -> V_17 ) ) ;
} else {
F_13 ( L_9 , V_14 ) ;
return;
}
} else {
F_13 ( L_10 , V_14 ) ;
return;
}
F_6 ( V_14 ) ;
} else {
F_13 ( L_11 , V_14 , V_12 ) ;
return;
}
V_15 = F_14 ( V_2 -> V_7 -> V_18 ,
V_2 ,
V_2 -> V_19 ,
V_2 -> V_7 -> V_20 ,
V_21 ,
V_22 ,
F_1 ) ;
if ( V_15 ) {
F_13 ( L_12 , V_7 -> V_8 , V_15 -> V_11 ) ;
return;
}
if ( V_7 -> V_23 ) V_7 -> V_23 ( V_2 ) ;
}
void
F_15 ( T_7 T_8 V_13 , T_7 V_24 , T_7 T_9 V_13 )
{
T_6 * V_7 = ( T_6 * ) V_24 ;
V_7 -> V_16 = ( V_25 * ) F_16 ( sizeof( V_25 ) ) ;
V_7 -> V_16 -> V_17 = F_3 ( L_13 , V_7 -> V_14 ) ;
F_17 ( V_7 -> V_16 -> V_17 , F_9 , NULL ) ;
}
static void
F_18 ( T_1 * V_2 )
{
F_6 ( V_2 -> V_16 ) ;
}
void
F_19 ( void )
{
F_20 ( F_15 , NULL , NULL , NULL , NULL ,
NULL , F_18 , NULL , NULL , NULL ) ;
}
