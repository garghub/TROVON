void F_1 ( T_1 * V_1 )
{
V_2 = V_1 ;
}
T_1 * F_2 ( void )
{
if( ! V_2 ) V_2 = F_3 () ;
return V_2 ;
}
T_1 * F_4 ( T_2 * V_3 , T_1 * V_1 )
{
T_1 * V_4 ;
V_4 = V_3 -> V_1 ;
if ( V_4 -> V_5 ) V_4 -> V_5 ( V_3 ) ;
V_3 -> V_1 = V_1 ;
if ( V_1 -> V_6 ) V_1 -> V_6 ( V_3 ) ;
return V_4 ;
}
T_2 * F_5 ( void )
{
return F_6 ( NULL ) ;
}
T_2 * F_6 ( T_1 * V_1 )
{
T_2 * V_7 ;
V_7 = ( T_2 * ) Malloc ( sizeof( T_2 ) ) ;
if ( V_7 == NULL )
{
F_7 ( V_8 , V_9 ) ;
return ( NULL ) ;
}
if( ! V_2 ) V_2 = F_3 () ;
if( V_1 ) V_7 -> V_1 = V_1 ;
else V_7 -> V_1 = V_2 ;
V_7 -> V_10 = 0 ;
V_7 -> V_11 = 0 ;
V_7 -> V_12 = NULL ;
V_7 -> V_13 = NULL ;
V_7 -> V_14 = 0 ;
V_7 -> V_15 = NULL ;
V_7 -> V_16 = NULL ;
V_7 -> V_17 = NULL ;
V_7 -> V_18 = NULL ;
V_7 -> V_19 = NULL ;
V_7 -> V_20 = 0 ;
V_7 -> V_21 = NULL ;
V_7 -> V_22 = NULL ;
V_7 -> V_23 = 1 ;
V_7 -> V_24 = V_7 -> V_1 -> V_24 ;
if ( ( V_7 -> V_1 -> V_6 != NULL ) && ! V_7 -> V_1 -> V_6 ( V_7 ) )
{
Free ( V_7 ) ;
V_7 = NULL ;
}
else
F_8 ( V_25 , V_7 , & V_7 -> V_26 ) ;
return ( V_7 ) ;
}
void F_9 ( T_2 * V_27 )
{
int V_28 ;
if( V_27 == NULL ) return;
V_28 = F_10 ( & V_27 -> V_23 , - 1 , V_29 ) ;
#ifdef F_11
F_11 ( L_1 , V_27 ) ;
#endif
if ( V_28 > 0 ) return;
#ifdef F_12
if ( V_28 < 0 )
{
fprintf ( V_30 , L_2 ) ;
abort () ;
}
#endif
F_13 ( V_25 , V_27 , & V_27 -> V_26 ) ;
if( V_27 -> V_1 -> V_5 ) V_27 -> V_1 -> V_5 ( V_27 ) ;
if ( V_27 -> V_12 != NULL ) F_14 ( V_27 -> V_12 ) ;
if ( V_27 -> V_13 != NULL ) F_14 ( V_27 -> V_13 ) ;
if ( V_27 -> V_17 != NULL ) F_14 ( V_27 -> V_17 ) ;
if ( V_27 -> V_18 != NULL ) F_14 ( V_27 -> V_18 ) ;
if ( V_27 -> V_19 ) Free ( V_27 -> V_19 ) ;
if ( V_27 -> V_21 != NULL ) F_14 ( V_27 -> V_21 ) ;
if ( V_27 -> V_15 != NULL ) F_14 ( V_27 -> V_15 ) ;
if ( V_27 -> V_16 != NULL ) F_14 ( V_27 -> V_16 ) ;
Free ( V_27 ) ;
}
int F_15 ( long V_31 , void * V_32 , T_3 * V_33 ,
T_4 * V_34 , T_5 * V_35 )
{
V_36 ++ ;
return ( F_16 ( V_36 - 1 ,
& V_25 , V_31 , V_32 , V_33 , V_34 , V_35 ) ) ;
}
int F_17 ( T_2 * V_37 , int V_38 , void * V_39 )
{
return ( F_18 ( & V_37 -> V_26 , V_38 , V_39 ) ) ;
}
void * F_19 ( T_2 * V_37 , int V_38 )
{
return ( F_20 ( & V_37 -> V_26 , V_38 ) ) ;
}
int F_21 ( T_2 * V_3 )
{
return ( F_22 ( V_3 -> V_12 ) ) ;
}
