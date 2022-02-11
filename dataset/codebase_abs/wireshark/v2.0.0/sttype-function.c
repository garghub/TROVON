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
static T_1
F_4 ( T_3 V_7 )
{
const T_2 * V_8 = ( const T_2 * ) V_7 ;
T_2 * V_2 ;
T_4 * V_9 ;
V_2 = ( T_2 * ) F_1 ( V_8 -> V_1 ) ;
for ( V_9 = V_8 -> V_6 ; V_9 ; V_9 = V_9 -> V_10 ) {
const T_5 * V_11 = ( const T_5 * ) V_9 -> V_7 ;
V_2 -> V_6 = F_5 ( V_2 -> V_6 , F_6 ( V_11 ) ) ;
}
return ( T_1 ) V_2 ;
}
static void
F_7 ( T_1 V_7 , T_1 T_6 V_12 )
{
F_8 ( ( T_5 * ) V_7 ) ;
}
void
F_9 ( T_4 * V_6 )
{
F_10 ( V_6 , F_7 , NULL ) ;
F_11 ( V_6 ) ;
}
static void
F_12 ( T_1 V_13 )
{
T_2 * V_2 = ( T_2 * ) V_13 ;
F_13 ( V_2 , V_4 ) ;
F_9 ( V_2 -> V_6 ) ;
F_14 ( V_2 ) ;
}
void
F_15 ( T_5 * V_14 , T_4 * V_6 )
{
T_2 * V_2 ;
V_2 = ( T_2 * ) F_16 ( V_14 ) ;
F_13 ( V_2 , V_4 ) ;
V_2 -> V_6 = V_6 ;
}
V_5 *
F_17 ( T_5 * V_14 )
{
T_2 * V_2 ;
V_2 = ( T_2 * ) F_16 ( V_14 ) ;
F_13 ( V_2 , V_4 ) ;
return V_2 -> V_1 ;
}
T_4 *
F_18 ( T_5 * V_14 )
{
T_2 * V_2 ;
V_2 = ( T_2 * ) F_16 ( V_14 ) ;
F_13 ( V_2 , V_4 ) ;
return V_2 -> V_6 ;
}
void
F_19 ( void )
{
static T_7 V_15 = {
V_16 ,
L_1 ,
F_1 ,
F_12 ,
F_4
} ;
F_20 ( & V_15 ) ;
}
