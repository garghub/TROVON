static int
F_1 ( void * V_1 , T_1 * V_2 , T_2 * T_3 V_3 , const void * V_4 )
{
T_4 * V_5 = ( T_4 * ) V_1 ;
const struct V_6 * V_7 = (struct V_6 * ) V_4 ;
T_5 V_8 ;
T_5 V_9 ;
F_2 ( & V_8 , V_10 , sizeof( struct V_11 ) , & V_7 -> V_12 ) ;
F_2 ( & V_9 , V_10 , sizeof( struct V_11 ) , & V_7 -> V_13 ) ;
F_3 ( V_5 , & V_8 , 0 , TRUE , 1 , V_2 -> V_14 -> V_15 , V_16 , V_17 ) ;
F_3 ( V_5 , & V_9 , 0 , FALSE , 1 , V_2 -> V_14 -> V_15 , V_16 , V_17 ) ;
return 1 ;
}
static void
F_4 ( const char * V_18 , void * T_6 V_3 )
{
const char * V_19 = NULL ;
if( ! strncmp ( V_18 , L_1 , 10 ) ) {
V_19 = V_18 + 10 ;
} else {
V_19 = NULL ;
}
F_5 ( TRUE , L_2 , L_3 , V_19 , F_1 ) ;
}
void
F_6 ( T_7 * T_8 V_3 , T_9 T_10 V_3 )
{
F_4 ( L_4 , NULL ) ;
}
void
F_7 ( void )
{
F_8 ( L_4 , F_4 , NULL ) ;
F_9 ( TRUE , L_2 , L_3 , NULL , F_1 ) ;
}
