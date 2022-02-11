static T_1
F_1 ( T_2 * V_1 )
{
T_3 V_2 ;
void (* F_2)( void );
T_4 * V_3 ;
if ( ! F_3 ( V_1 , L_1 , & V_2 ) ) {
return FALSE ;
}
F_2 = ( void ( * ) ( void ) ) V_2 ;
V_3 = ( T_4 * ) F_4 ( sizeof ( T_4 ) ) ;
V_3 -> F_2 = F_2 ;
V_4 = F_5 ( V_4 , V_3 ) ;
return TRUE ;
}
void
F_6 ( void )
{
F_7 ( L_2 , F_1 ) ;
}
static void
F_8 ( T_3 V_5 , T_3 T_5 V_6 )
{
T_4 * V_3 = ( T_4 * ) V_5 ;
( V_3 -> F_2 ) ( ) ;
}
void
F_9 ( void )
{
F_10 ( L_3 , V_7 , V_8 ,
V_9 , V_10 , V_11 ) ;
F_10 ( L_4 , V_12 , V_13 ,
V_14 , V_15 , V_16 ) ;
#ifdef F_11
F_10 ( L_5 , V_17 , V_18 ,
V_19 , V_20 , V_21 ) ;
F_10 ( L_6 , V_22 , V_23 ,
V_24 , V_25 , V_26 ) ;
#endif
#ifdef F_12
F_10 ( L_7 , V_27 , V_28 ,
V_29 , V_30 , V_31 ) ;
#endif
F_13 ( V_4 , F_8 , NULL ) ;
}
T_6
F_14 ( const char * V_32 )
{
return ( V_33 ) ? ( T_6 ) F_15 ( V_33 , V_32 ) : NULL ;
}
T_1
F_10 ( const char * V_32 , T_7 V_34 , T_8 V_35 ,
T_9 V_36 , T_10 V_37 ,
T_11 V_38 )
{
struct V_39 * V_1 ;
if ( V_33 == NULL )
V_33 = F_16 ( V_40 , V_41 ) ;
if ( F_15 ( V_33 , V_32 ) != NULL )
return FALSE ;
V_1 = (struct V_39 * ) F_4 ( sizeof ( struct V_39 ) ) ;
V_1 -> V_32 = V_32 ;
V_1 -> V_34 = V_34 ;
V_1 -> V_35 = V_35 ;
V_1 -> V_36 = V_36 ;
V_1 -> V_37 = V_37 ;
V_1 -> V_38 = V_38 ;
F_17 ( V_33 , ( T_3 ) V_32 , ( T_3 ) V_1 ) ;
return TRUE ;
}
void * F_18 ( T_6 V_42 )
{
if ( ! V_42 ) return NULL ;
return ( V_42 -> V_34 ) ( ) ;
}
void F_19 ( T_6 V_42 , void * V_43 )
{
if ( ! V_42 ) return;
( V_42 -> V_35 ) ( V_43 ) ;
}
unsigned F_20 ( T_6 V_42 , void * V_43 )
{
if ( ! V_42 ) return 0 ;
return ( V_42 -> V_36 ) ( V_43 ) ;
}
unsigned F_21 ( T_6 V_42 , void * V_43 )
{
if ( ! V_42 ) return 0 ;
return ( V_42 -> V_37 ) ( V_43 ) ;
}
T_12 F_22 ( T_6 V_42 , void * V_43 , const void * V_44 , T_12 V_45 , void * V_46 , T_12 * V_47 )
{
if ( ! V_42 ) return 0 ;
return ( V_42 -> V_38 ) ( V_43 , V_44 , V_45 , V_46 , V_47 ) ;
}
