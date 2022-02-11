static T_1
F_1 ( T_1 V_1 )
{
T_2 * V_2 ;
F_2 ( V_1 == NULL ) ;
V_2 = F_3 ( T_2 , 1 ) ;
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = NULL ;
V_2 -> V_6 = NULL ;
return ( T_1 ) V_2 ;
}
static void
F_4 ( T_1 V_7 )
{
T_2 * V_2 = ( T_2 * ) V_7 ;
F_5 ( V_2 , V_4 ) ;
if ( V_2 -> V_6 )
F_6 ( V_2 -> V_6 ) ;
F_7 ( V_2 ) ;
}
void
F_8 ( T_3 * V_8 )
{
T_2 * V_2 ;
V_2 = ( T_2 * ) F_9 ( V_8 ) ;
F_5 ( V_2 , V_4 ) ;
V_2 -> V_6 = NULL ;
}
void
F_10 ( T_3 * V_8 , T_3 * V_9 , T_4 * V_10 )
{
T_2 * V_2 ;
V_2 = ( T_2 * ) F_9 ( V_8 ) ;
F_5 ( V_2 , V_4 ) ;
V_2 -> V_5 = ( V_11 * ) F_9 ( V_9 ) ;
F_11 ( V_9 ) ;
V_2 -> V_6 = F_12 ( V_10 ) ;
}
void
F_13 ( T_3 * V_8 , T_3 * V_9 , T_5 * V_12 )
{
F_10 ( V_8 , V_9 , F_14 ( NULL , V_12 ) ) ;
}
void
F_15 ( void )
{
static T_6 V_13 = {
V_14 ,
L_1 ,
F_1 ,
F_4 ,
} ;
F_16 ( & V_13 ) ;
}
