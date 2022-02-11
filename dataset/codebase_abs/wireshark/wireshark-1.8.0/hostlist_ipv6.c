static int
F_1 ( void * V_1 , T_1 * V_2 , T_2 * T_3 V_3 , const void * V_4 )
{
T_4 * V_5 = ( T_4 * ) V_1 ;
const struct V_6 * V_7 = V_4 ;
T_5 V_8 ;
T_5 V_9 ;
V_8 . type = V_9 . type = V_10 ;
V_8 . V_11 = V_9 . V_11 = sizeof( struct V_12 ) ;
V_8 . V_13 = & V_7 -> V_14 ;
V_9 . V_13 = & V_7 -> V_15 ;
F_2 ( V_5 , & V_8 , 0 , TRUE , 1 , V_2 -> V_16 -> V_17 , V_18 , V_19 ) ;
F_2 ( V_5 , & V_9 , 0 , FALSE , 1 , V_2 -> V_16 -> V_17 , V_18 , V_19 ) ;
return 1 ;
}
static void
F_3 ( const char * V_20 , void * T_6 V_3 )
{
const char * V_21 = NULL ;
if( ! strncmp ( V_20 , L_1 , 10 ) ) {
V_21 = V_20 + 10 ;
} else {
V_21 = NULL ;
}
F_4 ( TRUE , L_2 , L_3 , V_21 , F_1 ) ;
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
