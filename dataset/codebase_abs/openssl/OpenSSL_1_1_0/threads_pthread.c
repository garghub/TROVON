T_1 * F_1 ( void )
{
T_1 * V_1 = F_2 ( sizeof( V_2 ) ) ;
if ( V_1 == NULL )
return NULL ;
if ( F_3 ( V_1 , NULL ) != 0 ) {
F_4 ( V_1 ) ;
return NULL ;
}
return V_1 ;
}
int F_5 ( T_1 * V_1 )
{
if ( F_6 ( V_1 ) != 0 )
return 0 ;
return 1 ;
}
int F_7 ( T_1 * V_1 )
{
if ( F_8 ( V_1 ) != 0 )
return 0 ;
return 1 ;
}
int F_9 ( T_1 * V_1 )
{
if ( F_10 ( V_1 ) != 0 )
return 0 ;
return 1 ;
}
void F_11 ( T_1 * V_1 )
{
if ( V_1 == NULL )
return;
F_12 ( V_1 ) ;
F_4 ( V_1 ) ;
return;
}
int F_13 ( T_2 * V_3 , void (* F_14)( void ) )
{
if ( F_15 ( V_3 , F_14 ) != 0 )
return 0 ;
return 1 ;
}
int F_16 ( T_3 * V_4 , void (* F_17)( void * ) )
{
if ( F_18 ( V_4 , F_17 ) != 0 )
return 0 ;
return 1 ;
}
void * F_19 ( T_3 * V_4 )
{
return F_20 ( * V_4 ) ;
}
int F_21 ( T_3 * V_4 , void * V_5 )
{
if ( F_22 ( * V_4 , V_5 ) != 0 )
return 0 ;
return 1 ;
}
int F_23 ( T_3 * V_4 )
{
if ( F_24 ( * V_4 ) != 0 )
return 0 ;
return 1 ;
}
T_4 F_25 ( void )
{
return F_26 () ;
}
int F_27 ( T_4 V_6 , T_4 V_7 )
{
return F_28 ( V_6 , V_7 ) ;
}
int F_29 ( int * V_5 , int V_8 , int * V_9 , T_1 * V_1 )
{
# if F_30 ( V_10 ) && F_30 ( V_11 )
if ( F_31 ( sizeof( * V_5 ) , V_5 ) ) {
* V_9 = F_32 ( V_5 , V_8 , V_11 ) ;
return 1 ;
}
# endif
if ( ! F_7 ( V_1 ) )
return 0 ;
* V_5 += V_8 ;
* V_9 = * V_5 ;
if ( ! F_9 ( V_1 ) )
return 0 ;
return 1 ;
}
