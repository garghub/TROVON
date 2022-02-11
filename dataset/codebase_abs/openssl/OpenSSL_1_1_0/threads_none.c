T_1 * F_1 ( void )
{
T_1 * V_1 = F_2 ( sizeof( unsigned int ) ) ;
if ( V_1 == NULL )
return NULL ;
* ( unsigned int * ) V_1 = 1 ;
return V_1 ;
}
int F_3 ( T_1 * V_1 )
{
F_4 ( * ( unsigned int * ) V_1 == 1 ) ;
return 1 ;
}
int F_5 ( T_1 * V_1 )
{
F_4 ( * ( unsigned int * ) V_1 == 1 ) ;
return 1 ;
}
int F_6 ( T_1 * V_1 )
{
F_4 ( * ( unsigned int * ) V_1 == 1 ) ;
return 1 ;
}
void F_7 ( T_1 * V_1 ) {
if ( V_1 == NULL )
return;
* ( unsigned int * ) V_1 = 0 ;
F_8 ( V_1 ) ;
return;
}
int F_9 ( T_2 * V_2 , void (* F_10)( void ) )
{
if ( * V_2 != 0 )
return 1 ;
F_10 () ;
* V_2 = 1 ;
return 1 ;
}
int F_11 ( T_3 * V_3 , void (* F_12)( void * ) )
{
static unsigned int V_4 = 0 ;
if ( V_4 >= V_5 )
return 0 ;
* V_3 = V_4 ++ ;
V_6 [ * V_3 ] = NULL ;
return 1 ;
}
void * F_13 ( T_3 * V_3 )
{
if ( * V_3 >= V_5 )
return NULL ;
return V_6 [ * V_3 ] ;
}
int F_14 ( T_3 * V_3 , void * V_7 )
{
if ( * V_3 >= V_5 )
return 0 ;
V_6 [ * V_3 ] = V_7 ;
return 1 ;
}
int F_15 ( T_3 * V_3 )
{
* V_3 = V_5 + 1 ;
return 1 ;
}
T_4 F_16 ( void )
{
return 0 ;
}
int F_17 ( T_4 V_8 , T_4 V_9 )
{
return ( V_8 == V_9 ) ;
}
int F_18 ( int * V_7 , int V_10 , int * V_11 , T_1 * V_1 )
{
* V_7 += V_10 ;
* V_11 = * V_7 ;
return 1 ;
}
