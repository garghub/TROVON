static int
F_1 ( void * V_1 , T_1 * T_2 V_2 , T_3 * T_4 V_2 , const void * V_3 )
{
const T_5 * V_4 = ( const T_5 * ) V_3 ;
F_2 ( ( V_5 * ) V_1 ,
& V_4 -> V_6 ,
& V_4 -> V_7 ,
0 ,
0 ,
1 ,
V_4 -> V_8 ,
NULL ,
V_9 ,
V_10 ) ;
return 1 ;
}
static void
F_3 ( const char * V_11 , void * T_6 V_2 )
{
const char * V_12 = NULL ;
if( ! strncmp ( V_11 , L_1 , 10 ) ) {
V_12 = V_11 + 10 ;
} else {
V_12 = NULL ;
}
F_4 ( TRUE , L_2 , L_3 , V_12 , F_1 ) ;
}
void
F_5 ( T_7 * T_8 V_2 , T_9 T_10 V_2 )
{
F_3 ( L_4 , NULL ) ;
}
void
F_6 ( void )
{
F_7 ( L_4 , F_3 , NULL ) ;
F_8 ( TRUE , L_2 , L_3 , NULL , F_1 ) ;
}
