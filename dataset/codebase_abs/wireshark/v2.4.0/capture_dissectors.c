static void
F_1 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( V_3 -> V_4 ) ;
F_3 ( V_1 ) ;
}
void F_4 ( void )
{
V_5 = F_5 ( V_6 , V_7 , NULL , NULL ) ;
V_8 = F_5 ( V_6 , V_7 , NULL , F_1 ) ;
}
void F_6 ( void )
{
F_2 ( V_8 ) ;
F_2 ( V_5 ) ;
}
void F_7 ( const char * V_9 , const char * V_10 )
{
struct V_2 * V_11 ;
if( F_8 ( V_8 , V_9 ) ) {
F_9 ( L_1 , V_9 , V_10 ) ;
}
V_11 = F_10 ( struct V_2 , 1 ) ;
V_11 -> V_4 = F_5 ( V_12 , V_13 , NULL , NULL ) ;
V_11 -> V_10 = V_10 ;
F_11 ( V_8 , ( V_14 ) V_9 , ( V_14 ) V_11 ) ;
}
static T_1
F_12 ( T_2 V_15 , int V_16 , const char * V_9 )
{
struct V_17 * V_18 ;
V_18 = F_13 ( F_14 () , struct V_17 ) ;
V_18 -> V_9 = V_9 ;
V_18 -> V_15 = V_15 ;
V_18 -> V_19 = F_15 ( V_16 ) ;
return V_18 ;
}
T_1
F_16 ( T_2 V_15 , const int V_16 )
{
return F_12 ( V_15 , V_16 , NULL ) ;
}
T_1 F_17 ( const char * V_9 )
{
return ( T_1 ) F_8 ( V_5 , V_9 ) ;
}
T_1 F_18 ( const char * V_9 , T_2 V_15 , int V_16 )
{
T_1 V_18 ;
F_19 ( F_8 ( V_5 , V_9 ) == NULL ) ;
V_18 = F_12 ( V_15 , V_16 , V_9 ) ;
F_11 ( V_5 , ( V_14 ) V_9 , V_18 ) ;
return V_18 ;
}
void F_20 ( const char * V_9 , const T_3 V_20 , T_1 V_18 )
{
struct V_2 * V_11 ;
if ( V_18 == NULL )
return;
V_11 = (struct V_2 * ) F_8 ( V_8 , V_9 ) ;
if ( V_11 == NULL ) {
fprintf ( V_21 , L_2 , V_9 ) ;
if ( getenv ( L_3 ) != NULL )
abort () ;
return;
}
F_19 ( V_11 != NULL ) ;
F_19 ( F_8 ( V_11 -> V_4 , F_21 ( V_20 ) ) == NULL ) ;
F_11 ( V_11 -> V_4 , F_21 ( V_20 ) , ( V_14 ) V_18 ) ;
}
T_4 F_22 ( const char * V_9 , const T_3 V_20 , const T_5 * V_22 , int V_23 , int V_24 , T_6 * V_25 , const union V_26 * V_27 )
{
struct V_2 * V_11 ;
T_1 V_18 ;
V_11 = (struct V_2 * ) F_8 ( V_8 , V_9 ) ;
if ( V_11 == NULL )
{
return FALSE ;
}
V_18 = ( T_1 ) F_8 ( V_11 -> V_4 , F_21 ( V_20 ) ) ;
if ( V_18 == NULL )
return FALSE ;
return V_18 -> V_15 ( V_22 , V_23 , V_24 , V_25 , V_27 ) ;
}
T_4 F_23 ( T_1 V_18 , const T_5 * V_22 , int V_23 , int V_24 , T_6 * V_25 , const union V_26 * V_27 )
{
if ( V_18 == NULL )
return FALSE ;
return V_18 -> V_15 ( V_22 , V_23 , V_24 , V_25 , V_27 ) ;
}
T_3 F_24 ( T_7 * V_28 , const int V_16 )
{
T_8 * V_29 = ( T_8 * ) F_8 ( V_28 -> V_30 , F_21 ( V_16 ) ) ;
if ( V_29 == NULL )
return 0 ;
return V_29 -> V_31 ;
}
void F_25 ( T_6 * V_25 , const int V_16 )
{
T_8 * V_29 = ( T_8 * ) F_8 ( V_25 -> V_28 , F_21 ( V_16 ) ) ;
if ( V_29 == NULL )
{
V_29 = F_26 ( T_8 , 1 ) ;
F_11 ( V_25 -> V_28 , F_21 ( V_16 ) , ( V_14 ) V_29 ) ;
}
V_29 -> V_31 ++ ;
}
