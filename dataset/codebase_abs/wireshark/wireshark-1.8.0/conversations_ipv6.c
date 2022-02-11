static int
F_1 ( void * V_1 , T_1 * V_2 , T_2 * T_3 V_3 , const void * V_4 )
{
const struct V_5 * V_6 = V_4 ;
T_4 V_7 ;
T_4 V_8 ;
V_7 . type = V_8 . type = V_9 ;
V_7 . V_10 = V_8 . V_10 = sizeof( struct V_11 ) ;
V_7 . V_12 = & V_6 -> V_13 ;
V_8 . V_12 = & V_6 -> V_14 ;
F_2 ( ( V_15 * ) V_1 , & V_7 , & V_8 , 0 , 0 , 1 , V_2 -> V_16 -> V_17 , & V_2 -> V_16 -> V_18 , V_19 , V_20 ) ;
return 1 ;
}
static void
F_3 ( const char * V_21 , void * T_5 V_3 )
{
const char * V_22 = NULL ;
if( ! strncmp ( V_21 , L_1 , 10 ) ) {
V_22 = V_21 + 10 ;
}
else {
V_22 = NULL ;
}
F_4 ( TRUE , L_2 , L_3 , V_22 , F_1 ) ;
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
