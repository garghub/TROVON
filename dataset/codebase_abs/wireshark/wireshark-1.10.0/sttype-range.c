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
static T_1
F_4 ( T_3 V_7 )
{
const T_2 * V_8 = ( const T_2 * ) V_7 ;
T_2 * V_2 ;
V_2 = ( T_2 * ) F_1 ( NULL ) ;
V_2 -> V_5 = V_8 -> V_5 ;
V_2 -> V_6 = F_5 ( V_8 -> V_6 ) ;
return ( T_1 ) V_2 ;
}
static void
F_6 ( T_1 V_9 )
{
T_2 * V_2 = ( T_2 * ) V_9 ;
F_7 ( V_2 , V_4 ) ;
if ( V_2 -> V_6 )
F_8 ( V_2 -> V_6 ) ;
F_9 ( V_2 ) ;
}
void
F_10 ( T_4 * V_10 )
{
T_2 * V_2 ;
V_2 = ( T_2 * ) F_11 ( V_10 ) ;
F_7 ( V_2 , V_4 ) ;
V_2 -> V_6 = NULL ;
}
void
F_12 ( T_4 * V_10 , T_4 * V_11 , T_5 * V_12 )
{
T_2 * V_2 ;
V_2 = ( T_2 * ) F_11 ( V_10 ) ;
F_7 ( V_2 , V_4 ) ;
V_2 -> V_5 = ( V_13 * ) F_11 ( V_11 ) ;
F_13 ( V_11 ) ;
V_2 -> V_6 = F_14 ( V_12 ) ;
}
void
F_15 ( T_4 * V_10 , T_4 * V_11 , T_6 * V_14 )
{
F_12 ( V_10 , V_11 , F_16 ( NULL , V_14 ) ) ;
}
void
F_17 ( void )
{
static T_7 V_15 = {
V_16 ,
L_1 ,
F_1 ,
F_6 ,
F_4
} ;
F_18 ( & V_15 ) ;
}
