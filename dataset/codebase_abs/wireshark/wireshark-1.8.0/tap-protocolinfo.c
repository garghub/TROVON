static int
F_1 ( void * V_1 , T_1 * V_2 , T_2 * V_3 , const void * T_3 V_4 )
{
T_4 * V_5 = V_1 ;
T_5 * V_6 ;
T_6 V_7 ;
char * V_8 ;
if ( ! F_2 ( V_2 -> V_9 , V_10 ) ) {
fprintf ( V_11 , L_1 ) ;
exit ( 1 ) ;
}
V_6 = F_3 ( V_3 -> V_12 , V_5 -> V_13 ) ;
if( ! V_6 ) {
return 0 ;
}
for( V_7 = 0 ; V_7 < V_6 -> V_14 ; V_7 ++ ) {
V_8 = F_4 ( V_6 -> V_15 [ V_7 ] , NULL ) ;
if( V_8 ) {
F_5 ( V_2 -> V_9 , V_10 , L_2 , V_8 ) ;
}
}
return 0 ;
}
static void
F_6 ( const char * V_16 , void * T_7 V_4 )
{
T_4 * V_5 ;
const char * V_17 = NULL ;
const char * V_18 = NULL ;
T_8 * V_19 ;
T_9 * V_20 ;
if( ! strncmp ( L_3 , V_16 , 14 ) ) {
V_18 = V_16 + 14 ;
V_17 = strchr ( V_18 , ',' ) ;
if( V_17 ) {
V_17 += 1 ;
}
}
if( ! V_17 ) {
fprintf ( V_11 , L_4 ) ;
exit ( 1 ) ;
}
V_19 = F_7 ( V_17 ) ;
if( ! V_19 ) {
fprintf ( V_11 , L_5 , V_17 ) ;
exit ( 1 ) ;
}
V_5 = F_8 ( sizeof( T_4 ) ) ;
V_5 -> V_13 = V_19 -> V_21 ;
if( ( V_17 - V_18 ) > 1 ) {
V_5 -> V_18 = F_8 ( V_17 - V_18 ) ;
F_9 ( V_5 -> V_18 , V_18 , ( V_17 - V_18 ) ) ;
} else {
V_5 -> V_18 = NULL ;
}
V_20 = F_10 ( L_6 , V_5 , V_5 -> V_18 , V_22 , NULL , F_1 , NULL ) ;
if( V_20 ) {
fprintf ( V_11 , L_7 ,
V_20 -> V_8 ) ;
F_11 ( V_20 , TRUE ) ;
F_12 ( V_5 -> V_18 ) ;
F_12 ( V_5 ) ;
exit ( 1 ) ;
}
}
void
F_13 ( void )
{
F_14 ( L_3 , F_6 , NULL ) ;
}
