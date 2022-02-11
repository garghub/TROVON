static int
F_1 ( void * V_1 , T_1 * V_2 , T_2 * T_3 V_3 , const void * T_4 V_3 )
{
F_2 ( ( V_4 * ) V_1 , & V_2 -> V_5 , & V_2 -> V_6 , 0 , 0 , 1 , V_2 -> V_7 -> V_8 , & V_2 -> V_9 , V_10 , V_11 ) ;
return 1 ;
}
static void
F_3 ( const char * V_12 , void * T_5 V_3 )
{
const char * V_13 = NULL ;
if ( ! strncmp ( V_12 , L_1 , 9 ) ) {
V_13 = V_12 + 9 ;
} else {
V_13 = NULL ;
}
F_4 ( TRUE , L_2 , L_3 , V_13 , F_1 ) ;
}
void
F_5 ( T_6 * T_7 V_3 , T_8 T_9 V_3 )
{
F_3 ( L_4 , NULL ) ;
}
void
F_6 ( void )
{
F_7 ( L_4 , F_3 , NULL ) ;
F_8 ( TRUE , L_2 , L_3 , NULL , F_1 ) ;
}
