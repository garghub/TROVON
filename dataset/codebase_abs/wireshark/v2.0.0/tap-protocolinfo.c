static int
F_1 ( void * V_1 , T_1 * V_2 , T_2 * V_3 , const void * T_3 V_4 )
{
T_4 * V_5 = ( T_4 * ) V_1 ;
T_5 * V_6 ;
T_6 V_7 ;
char * V_8 ;
if ( ! F_2 ( V_2 -> V_9 ) ) {
fprintf ( V_10 , L_1 ) ;
exit ( 1 ) ;
}
V_6 = F_3 ( V_3 -> V_11 , V_5 -> V_12 ) ;
if ( ! V_6 ) {
return 0 ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_13 ; V_7 ++ ) {
V_8 = ( char * ) F_4 ( ( V_14 * ) V_6 -> V_15 [ V_7 ] , NULL ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_9 , V_16 , L_2 , V_8 ) ;
F_6 ( NULL , V_8 ) ;
}
}
return 0 ;
}
static void
F_7 ( const char * V_17 , void * T_7 V_4 )
{
T_4 * V_5 ;
const char * V_18 = NULL ;
const char * V_19 = NULL ;
T_8 * V_20 ;
T_9 * V_21 ;
if ( ! strncmp ( L_3 , V_17 , 14 ) ) {
V_19 = V_17 + 14 ;
V_18 = strchr ( V_19 , ',' ) ;
if ( V_18 ) {
V_18 += 1 ;
}
}
if ( ! V_18 ) {
fprintf ( V_10 , L_4 ) ;
exit ( 1 ) ;
}
V_20 = F_8 ( V_18 ) ;
if ( ! V_20 ) {
fprintf ( V_10 , L_5 , V_18 ) ;
exit ( 1 ) ;
}
V_5 = F_9 ( T_4 , 1 ) ;
V_5 -> V_12 = V_20 -> V_22 ;
if ( ( V_18 - V_19 ) > 1 ) {
V_5 -> V_19 = ( char * ) F_10 ( V_18 - V_19 ) ;
F_11 ( V_5 -> V_19 , V_19 , ( V_18 - V_19 ) ) ;
} else {
V_5 -> V_19 = NULL ;
}
V_21 = F_12 ( L_6 , V_5 , V_5 -> V_19 , V_23 , NULL , F_1 , NULL ) ;
if ( V_21 ) {
fprintf ( V_10 , L_7 ,
V_21 -> V_8 ) ;
F_13 ( V_21 , TRUE ) ;
F_14 ( V_5 -> V_19 ) ;
F_14 ( V_5 ) ;
exit ( 1 ) ;
}
}
void
F_15 ( void )
{
F_16 ( & V_24 , NULL ) ;
}
