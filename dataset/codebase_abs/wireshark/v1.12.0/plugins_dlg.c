static T_1
F_1 ( T_2 * V_1 , T_3 * V_2 , T_4 T_5 V_3 )
{
T_6 * V_4 ;
T_7 * V_5 ;
T_8 V_6 ;
T_9 * type ;
T_9 * V_7 ;
V_4 = F_2 ( F_3 ( V_1 ) ) ;
if ( F_4 ( V_4 ) == 0 )
return FALSE ;
if ( V_2 -> type != V_8 )
return FALSE ;
if ( F_5 ( V_4 , & V_5 , & V_6 ) ) {
F_6 ( V_5 , & V_6 , 2 , & type , - 1 ) ;
if ( strcmp ( type , L_1 ) == 0 ) {
F_6 ( V_5 , & V_6 , 3 , & V_7 , - 1 ) ;
F_7 ( V_7 ) ;
F_8 ( V_7 ) ;
}
F_8 ( type ) ;
}
return TRUE ;
}
static void
F_9 ( const char * V_9 , const char * V_10 ,
const char * V_11 , const char * V_12 ,
void * V_13 )
{
T_2 * V_14 = ( T_2 * ) V_13 ;
F_10 ( V_14 , 0 , V_9 , 1 , V_10 ,
2 , V_11 , 3 , V_12 , - 1 ) ;
}
static void
F_11 ( T_2 * V_14 )
{
#ifdef F_12
F_13 ( F_9 , V_14 ) ;
#endif
#ifdef F_14
F_15 ( F_9 , V_14 ) ;
#endif
}
T_2 *
F_16 ( void )
{
T_2 * V_15 ;
T_2 * V_16 ;
static const T_9 * V_17 [] = { L_2 , L_3 , L_4 , L_5 } ;
V_15 = F_17 ( NULL , NULL ) ;
F_18 ( F_19 ( V_15 ) ,
V_18 ) ;
V_16 = F_20 ( 4 , V_17 ) ;
F_11 ( V_16 ) ;
F_21 ( V_16 , L_6 ,
F_22 ( F_1 ) , NULL ) ;
F_23 ( F_24 ( V_15 ) , V_16 ) ;
return V_15 ;
}
