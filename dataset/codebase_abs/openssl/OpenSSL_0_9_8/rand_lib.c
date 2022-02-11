int F_1 ( const T_1 * V_1 )
{
#ifndef F_2
if( V_2 )
{
F_3 ( V_2 ) ;
V_2 = NULL ;
}
#endif
V_3 = V_1 ;
return 1 ;
}
const T_1 * F_4 ( void )
{
if ( ! V_3 )
{
#ifndef F_2
T_2 * V_4 = F_5 () ;
if( V_4 )
{
V_3 = F_6 ( V_4 ) ;
if( ! V_3 )
{
F_3 ( V_4 ) ;
V_4 = NULL ;
}
}
if( V_4 )
V_2 = V_4 ;
else
#endif
V_3 = F_7 () ;
}
return V_3 ;
}
int F_8 ( T_2 * V_5 )
{
const T_1 * V_6 = NULL ;
if( V_5 )
{
if( ! F_9 ( V_5 ) )
return 0 ;
V_6 = F_6 ( V_5 ) ;
if( ! V_6 )
{
F_3 ( V_5 ) ;
return 0 ;
}
}
F_1 ( V_6 ) ;
V_2 = V_5 ;
return 1 ;
}
void F_10 ( void )
{
const T_1 * V_1 = F_4 () ;
if ( V_1 && V_1 -> V_7 )
V_1 -> V_7 () ;
F_1 ( NULL ) ;
}
void F_11 ( const void * V_8 , int V_9 )
{
const T_1 * V_1 = F_4 () ;
if ( V_1 && V_1 -> V_10 )
V_1 -> V_10 ( V_8 , V_9 ) ;
}
void F_12 ( const void * V_8 , int V_9 , double V_11 )
{
const T_1 * V_1 = F_4 () ;
if ( V_1 && V_1 -> V_12 )
V_1 -> V_12 ( V_8 , V_9 , V_11 ) ;
}
int F_13 ( unsigned char * V_8 , int V_9 )
{
const T_1 * V_1 = F_4 () ;
if ( V_1 && V_1 -> V_13 )
return V_1 -> V_13 ( V_8 , V_9 ) ;
return ( - 1 ) ;
}
int F_14 ( unsigned char * V_8 , int V_9 )
{
const T_1 * V_1 = F_4 () ;
if ( V_1 && V_1 -> V_14 )
return V_1 -> V_14 ( V_8 , V_9 ) ;
return ( - 1 ) ;
}
int F_15 ( void )
{
const T_1 * V_1 = F_4 () ;
if ( V_1 && V_1 -> V_15 )
return V_1 -> V_15 () ;
return 0 ;
}
