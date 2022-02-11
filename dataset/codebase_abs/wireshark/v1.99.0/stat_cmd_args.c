static T_1
F_1 ( T_2 V_1 , T_2 V_2 )
{
return strcmp ( ( ( const V_3 * ) V_1 ) -> V_4 , ( ( const V_3 * ) V_2 ) -> V_4 ) ;
}
void
F_2 ( const char * V_4 , void (* F_3)( const char * , void * ) , void * V_5 )
{
V_3 * V_6 ;
V_6 = ( V_3 * ) F_4 ( sizeof( V_3 ) ) ;
V_6 -> V_4 = V_4 ;
V_6 -> F_3 = F_3 ;
V_6 -> V_5 = V_5 ;
V_7 = F_5 ( V_7 , V_6 , F_1 ) ;
}
T_3
F_6 ( char * V_8 )
{
T_4 * V_9 ;
V_3 * V_10 ;
T_5 * V_11 ;
for( V_9 = V_7 ; V_9 ; V_9 = F_7 ( V_9 ) ) {
V_10 = ( V_3 * ) V_9 -> V_12 ;
if( ! strncmp ( V_10 -> V_4 , V_8 , strlen ( V_8 ) ) ) {
V_11 = ( T_5 * ) F_4 ( sizeof ( T_5 ) ) ;
V_11 -> V_10 = V_10 ;
V_11 -> V_13 = F_8 ( V_8 ) ;
V_14 = F_9 ( V_14 , V_11 ) ;
return TRUE ;
}
}
return FALSE ;
}
void
F_10 ( void )
{
T_4 * V_9 ;
V_3 * V_10 ;
for( V_9 = V_7 ; V_9 ; V_9 = F_7 ( V_9 ) ) {
V_10 = ( V_3 * ) V_9 -> V_12 ;
fprintf ( V_15 , L_1 , V_10 -> V_4 ) ;
}
}
void
F_11 ( void )
{
T_5 * V_16 ;
while( V_14 ) {
V_16 = ( T_5 * ) V_14 -> V_12 ;
(* V_16 -> V_10 -> F_3 )( V_16 -> V_13 , V_16 -> V_10 -> V_5 ) ;
F_12 ( V_16 -> V_13 ) ;
F_12 ( V_16 ) ;
V_14 = F_13 ( V_14 , V_16 ) ;
}
}
