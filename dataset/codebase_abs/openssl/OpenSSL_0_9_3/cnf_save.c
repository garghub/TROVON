main ()
{
T_1 * V_1 ;
long V_2 ;
V_1 = F_1 ( NULL , L_1 , & V_2 ) ;
if ( V_1 == NULL )
{
fprintf ( V_3 , L_2 , V_2 ) ;
exit ( 1 ) ;
}
F_2 ( V_1 , V_4 ) ;
}
void V_4 ( T_2 * V_5 )
{
int V_6 ;
T_2 * V_7 ;
char * V_8 ;
char * V_9 ;
char * V_10 ;
T_3 * V_11 ;
if ( V_5 -> V_9 != NULL ) return;
printf ( L_3 , V_5 -> V_8 ) ;
V_11 = ( T_3 * ) V_5 -> V_10 ;
for ( V_6 = 0 ; V_6 < F_3 ( V_11 ) ; V_6 ++ )
{
V_7 = ( T_2 * ) F_4 ( V_11 , V_6 ) ;
V_8 = ( V_7 -> V_8 == NULL ) ? L_4 : V_7 -> V_8 ;
V_9 = ( V_7 -> V_9 == NULL ) ? L_4 : V_7 -> V_9 ;
V_10 = ( V_7 -> V_10 == NULL ) ? L_4 : V_7 -> V_10 ;
printf ( L_5 , V_9 , V_10 ) ;
}
printf ( L_6 ) ;
}
