static int
F_1 ( void * V_1 , T_1 * V_2 , T_2 * T_3 V_3 , const void * V_4 )
{
const T_4 * V_5 = ( const T_4 * ) V_4 ;
F_2 ( ( V_6 * ) V_1 , & V_5 -> V_7 , & V_5 -> V_8 , V_5 -> V_9 , V_5 -> V_10 , 1 , V_2 -> V_11 -> V_12 , & V_2 -> V_13 , V_14 , V_15 ) ;
return 1 ;
}
static void
F_3 ( const char * V_16 , void * T_5 V_3 )
{
const char * V_17 = NULL ;
if( ! strncmp ( V_16 , L_1 , 9 ) ) {
V_17 = V_16 + 9 ;
} else {
V_17 = NULL ;
}
F_4 ( FALSE , L_2 , L_3 , V_17 , F_1 ) ;
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
F_8 ( FALSE , L_2 , L_3 , NULL , F_1 ) ;
}
