static int
F_1 ( void * T_1 V_1 , T_2 * T_3 V_1 , T_4 * T_5 V_1 , const void * T_6 V_1 )
{
return 1 ;
}
static void
F_2 ( T_7 T_8 V_1 , T_7 V_2 , T_7 T_9 V_1 )
{
T_10 * V_3 = ( T_10 * ) V_2 ;
printf ( L_1 , V_3 -> V_4 , V_3 -> V_5 ) ;
return;
}
static void
F_3 ( void * T_1 V_1 )
{
printf ( L_2 ) ;
printf ( L_3 ) ;
printf ( L_4 ) ;
F_4 ( V_6 , F_2 , NULL ) ;
printf ( L_3 ) ;
}
static void
F_5 ( const char * T_11 V_1 , void * T_9 V_1 )
{
T_12 * V_7 ;
if ( ! V_8 ) {
fprintf ( V_9 , L_5 ) ;
fprintf ( V_9 , L_6 ) ;
fprintf ( V_9 , L_7 ) ;
fprintf ( V_9 , L_8 ) ;
fprintf ( V_9 , L_9 ) ;
exit ( 1 ) ;
}
V_7 = F_6 ( L_10 , NULL , NULL , 0 , NULL , F_1 , F_3 ) ;
if ( V_7 ) {
fprintf ( V_9 , L_11 ,
V_7 -> V_10 ) ;
F_7 ( V_7 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_8 ( void )
{
F_9 ( & V_11 , NULL ) ;
}
