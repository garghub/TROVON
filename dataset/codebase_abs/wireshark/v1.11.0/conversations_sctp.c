static int
F_1 ( void * V_1 , T_1 * V_2 , T_2 * T_3 V_3 , const void * V_4 )
{
const struct V_5 * V_6 = (struct V_5 * ) V_4 ;
F_2 ( ( V_7 * ) V_1 ,
& V_6 -> V_8 ,
& V_6 -> V_9 ,
V_6 -> V_10 ,
V_6 -> V_11 ,
1 ,
V_2 -> V_12 -> V_13 ,
& V_2 -> V_14 ,
V_15 ,
V_16 ) ;
return 1 ;
}
static void
F_3 ( const char * V_17 , void * T_4 V_3 )
{
const char * V_18 = NULL ;
if( ! strncmp ( V_17 , L_1 , 10 ) ) {
V_18 = V_17 + 10 ;
} else {
V_18 = NULL ;
}
F_4 ( FALSE , L_2 , L_3 , V_18 , F_1 ) ;
}
void
F_5 ( T_5 * T_6 V_3 , T_7 T_8 V_3 )
{
F_3 ( L_4 , NULL ) ;
}
void
F_6 ( void )
{
F_7 ( L_4 , F_3 , NULL ) ;
F_8 ( FALSE , L_2 , L_3 , NULL , F_1 ) ;
}
