T_1 * F_1 ( char * type , char * V_1 , int V_2 )
{
T_1 * V_3 ;
if ( V_2 )
V_3 = F_2 () ;
else
V_3 = F_3 ( 0 ) ;
F_4 ( V_3 , type , ( void * ) V_1 ) ;
return ( V_3 ) ;
}
int F_5 ( char * V_1 , T_1 * V_4 , T_2 * V_5 , int V_6 , long V_7 ,
char * V_8 )
{
T_1 * V_9 ;
fprintf ( V_10 , L_1 , V_6 , V_1 , V_8 ) ;
V_9 = F_2 () ;
F_4 ( V_9 , V_8 , ( void * ) V_1 ) ;
F_6 ( V_5 , V_6 , ( char * ) V_9 ) ;
return ( 1 ) ;
}
void F_7 ( char * V_1 , T_1 * V_4 , T_2 * V_5 , int V_6 , long V_7 ,
char * V_8 )
{
F_8 ( L_2 ) ;
fprintf ( V_10 , L_3 , V_1 , V_8 ) ;
if ( V_4 != NULL )
F_9 ( ( T_1 * ) V_4 ) ;
}
