static int
F_1 ( void * V_1 , T_1 * V_2 , T_2 * T_3 V_3 , const void * V_4 )
{
T_4 * V_5 = ( T_4 * ) V_1 ;
const T_5 * V_6 = V_4 ;
F_2 ( V_5 , & V_6 -> V_7 , 0 , TRUE , 1 , V_2 -> V_8 -> V_9 , V_10 , V_11 ) ;
F_2 ( V_5 , & V_6 -> V_12 , 0 , FALSE , 1 , V_2 -> V_8 -> V_9 , V_10 , V_11 ) ;
return 1 ;
}
static void
F_3 ( const char * V_13 ,
void * T_6 V_3 )
{
const char * V_14 = NULL ;
if( ! strncmp ( V_13 , L_1 , 10 ) ) {
V_14 = V_13 + 10 ;
} else {
V_14 = NULL ;
}
F_4 ( TRUE , L_2 , L_3 , V_14 , F_1 ) ;
}
void
F_5 ( T_7 * T_8 V_3 , T_9 T_10 V_3 )
{
F_3 ( L_4 , NULL ) ;
}
void
F_6 ( void )
{
F_7 ( L_4 , F_3 , NULL ) ;
F_8 ( TRUE , L_2 , L_3 , NULL , F_1 ) ;
}
