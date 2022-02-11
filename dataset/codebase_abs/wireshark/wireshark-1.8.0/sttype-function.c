static T_1
F_1 ( T_1 V_1 )
{
T_2 * V_2 ;
F_2 ( V_1 != NULL ) ;
V_2 = F_3 ( T_2 , 1 ) ;
V_2 -> V_3 = V_4 ;
V_2 -> V_1 = ( V_5 * ) V_1 ;
V_2 -> V_6 = NULL ;
return ( T_1 ) V_2 ;
}
static void
F_4 ( T_1 V_7 , T_1 T_3 V_8 )
{
F_5 ( ( V_9 * ) V_7 ) ;
}
void
F_6 ( T_4 * V_6 )
{
F_7 ( V_6 , F_4 , NULL ) ;
F_8 ( V_6 ) ;
}
static void
F_9 ( T_1 V_10 )
{
T_2 * V_2 = ( T_2 * ) V_10 ;
F_10 ( V_2 , V_4 ) ;
F_6 ( V_2 -> V_6 ) ;
F_11 ( V_2 ) ;
}
void
F_12 ( V_9 * V_11 , T_4 * V_6 )
{
T_2 * V_2 ;
V_2 = ( T_2 * ) F_13 ( V_11 ) ;
F_10 ( V_2 , V_4 ) ;
V_2 -> V_6 = V_6 ;
}
V_5 *
F_14 ( V_9 * V_11 )
{
T_2 * V_2 ;
V_2 = ( T_2 * ) F_13 ( V_11 ) ;
F_10 ( V_2 , V_4 ) ;
return V_2 -> V_1 ;
}
T_4 *
F_15 ( V_9 * V_11 )
{
T_2 * V_2 ;
V_2 = ( T_2 * ) F_13 ( V_11 ) ;
F_10 ( V_2 , V_4 ) ;
return V_2 -> V_6 ;
}
void
F_16 ( void )
{
static T_5 V_12 = {
V_13 ,
L_1 ,
F_1 ,
F_9 ,
} ;
F_17 ( & V_12 ) ;
}
