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
F_10 ( L_7 , V_27 , V_23 ,
V_24 , V_25 , V_26 ) ;
F_10 ( L_8 , V_28 , V_23 ,
V_24 , V_25 , V_26 ) ;
F_10 ( L_9 , V_29 , V_23 ,
V_24 , V_25 , V_26 ) ;
F_10 ( L_10 , V_30 , V_23 ,
V_24 , V_25 , V_26 ) ;
F_10 ( L_11 , V_31 , V_23 ,
V_24 , V_25 , V_26 ) ;
F_10 ( L_12 , V_32 , V_23 ,
V_24 , V_25 , V_26 ) ;
F_10 ( L_13 , V_33 , V_23 ,
V_24 , V_25 , V_26 ) ;
#endif
#ifdef F_12
F_10 ( L_14 , V_34 , V_35 ,
V_36 , V_37 , V_38 ) ;
#endif
#ifdef F_13
F_14 ( V_4 , F_8 , NULL ) ;
#endif
}
T_6
F_15 ( const char * V_39 )
{
return ( V_40 ) ? ( T_6 ) F_16 ( V_40 , V_39 ) : NULL ;
}
T_1
F_10 ( const char * V_39 , T_7 V_41 , T_8 V_42 ,
T_9 V_43 , T_10 V_44 ,
T_11 V_45 )
{
struct V_46 * V_1 ;
if ( V_40 == NULL )
V_40 = F_17 ( V_47 , V_48 ) ;
if ( F_16 ( V_40 , V_39 ) != NULL )
return FALSE ;
V_1 = (struct V_46 * ) F_4 ( sizeof ( struct V_46 ) ) ;
V_1 -> V_39 = V_39 ;
V_1 -> V_41 = V_41 ;
V_1 -> V_42 = V_42 ;
V_1 -> V_43 = V_43 ;
V_1 -> V_44 = V_44 ;
V_1 -> V_45 = V_45 ;
F_18 ( V_40 , ( T_3 ) V_39 , ( T_3 ) V_1 ) ;
return TRUE ;
}
T_1
F_19 ( const char * V_39 )
{
T_3 V_49 , V_50 ;
if ( V_40 && F_20 ( V_40 , V_39 , & V_49 , & V_50 ) ) {
F_21 ( V_40 , V_39 ) ;
F_22 ( V_50 ) ;
return TRUE ;
}
return FALSE ;
}
void * F_23 ( T_6 V_51 )
{
if ( ! V_51 ) return NULL ;
return ( V_51 -> V_41 ) ( ) ;
}
void F_24 ( T_6 V_51 , void * V_52 )
{
if ( ! V_51 ) return;
( V_51 -> V_42 ) ( V_52 ) ;
}
unsigned F_25 ( T_6 V_51 , void * V_52 )
{
if ( ! V_51 ) return 0 ;
return ( V_51 -> V_43 ) ( V_52 ) ;
}
unsigned F_26 ( T_6 V_51 , void * V_52 )
{
if ( ! V_51 ) return 0 ;
return ( V_51 -> V_44 ) ( V_52 ) ;
}
T_12 F_27 ( T_6 V_51 , void * V_52 , const void * V_53 , T_12 V_54 , void * V_55 , T_12 * V_56 )
{
if ( ! V_51 ) return 0 ;
return ( V_51 -> V_45 ) ( V_52 , V_53 , V_54 , V_55 , V_56 ) ;
}
void F_28 ( T_13 * V_57 )
{
#ifdef F_12
F_29 ( V_57 , L_15 ) ;
#else
F_29 ( V_57 , L_16 ) ;
#endif
#ifdef F_11
F_29 ( V_57 , L_17 ) ;
#else
F_29 ( V_57 , L_18 ) ;
#endif
}
