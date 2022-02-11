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
V_2 -> V_5 = F_5 ( V_8 -> V_5 ) ;
V_2 -> V_6 = F_6 ( V_8 -> V_6 ) ;
return ( T_1 ) V_2 ;
}
static void
F_7 ( T_1 V_9 )
{
T_2 * V_2 = ( T_2 * ) V_9 ;
F_8 ( V_2 , V_4 ) ;
if ( V_2 -> V_6 )
F_9 ( V_2 -> V_6 ) ;
if ( V_2 -> V_5 )
F_10 ( V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
}
void
F_12 ( T_4 * V_10 )
{
T_2 * V_2 ;
V_2 = ( T_2 * ) F_13 ( V_10 ) ;
F_8 ( V_2 , V_4 ) ;
V_2 -> V_6 = NULL ;
}
void
F_14 ( T_4 * V_10 , T_4 * V_5 , T_5 * V_11 )
{
T_2 * V_2 ;
V_2 = ( T_2 * ) F_13 ( V_10 ) ;
F_8 ( V_2 , V_4 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = F_15 ( V_11 ) ;
}
void
F_16 ( T_4 * V_10 , T_4 * V_5 , T_6 * V_12 )
{
F_14 ( V_10 , V_5 , F_17 ( NULL , V_12 ) ) ;
}
void
F_18 ( void )
{
static T_7 V_13 = {
V_14 ,
L_1 ,
F_1 ,
F_7 ,
F_4
} ;
F_19 ( & V_13 ) ;
}
