void F_1 ( void )
{
T_1 * V_1 ;
T_2 * V_2 ;
if ( V_3 != NULL ) {
for ( V_1 = V_4 ; V_1 != NULL ;
V_1 = F_2 ( V_1 ) )
{
V_2 = ( T_2 * ) V_1 -> V_5 ;
F_3 ( V_2 -> V_6 , V_2 -> V_7 ) ;
}
}
}
void
F_4 ( T_3 V_8 )
{
char * V_9 ;
V_9 = F_5 ( V_8 ) ;
if( V_9 != NULL ) {
F_6 ( V_9 ) ;
F_7 ( V_9 ) ;
}
}
void
F_8 ( T_4 * T_5 V_10 , T_3 V_8 )
{
F_4 ( V_8 ) ;
}
T_6
F_9 ( T_4 * T_5 V_10 , T_7 * T_8 V_10 , T_9 V_11 )
{
F_4 ( ( T_3 ) F_10 ( V_11 ) ) ;
return TRUE ;
}
