char * F_1 ( T_1 * V_1 , char * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1 -> V_4 ; V_3 ++ )
if ( V_1 -> V_5 [ V_3 ] == V_2 )
return ( F_2 ( V_1 , V_3 ) ) ;
return ( NULL ) ;
}
char * F_2 ( T_1 * V_1 , int V_6 )
{
char * V_7 ;
int V_3 , V_8 ;
if ( ( V_1 == NULL ) || ( V_1 -> V_4 == 0 ) || ( V_6 < 0 )
|| ( V_6 >= V_1 -> V_4 ) ) return ( NULL ) ;
V_7 = V_1 -> V_5 [ V_6 ] ;
if ( V_6 != V_1 -> V_4 - 1 )
{
V_8 = V_1 -> V_4 - 1 ;
for ( V_3 = V_6 ; V_3 < V_8 ; V_3 ++ )
V_1 -> V_5 [ V_3 ] = V_1 -> V_5 [ V_3 + 1 ] ;
}
V_1 -> V_4 -- ;
return ( V_7 ) ;
}
int F_3 ( T_1 * V_1 , char * V_5 )
{
char * * V_9 ;
int V_3 ;
int (* F_4)();
if( V_1 == NULL ) return - 1 ;
if ( V_1 -> V_10 == NULL )
{
for ( V_3 = 0 ; V_3 < V_1 -> V_4 ; V_3 ++ )
if ( V_1 -> V_5 [ V_3 ] == V_5 )
return ( V_3 ) ;
return ( - 1 ) ;
}
F_4 = ( int ( * ) () ) V_1 -> V_10 ;
if ( ! V_1 -> V_11 )
{
qsort ((char *)st->data,st->num,sizeof(char *),FP_ICC comp_func) ;
V_1 -> V_11 = 1 ;
}
if ( V_5 == NULL ) return ( - 1 ) ;
V_9 = ( char * * ) bsearch (&data,(char *)st->data,
st->num,sizeof(char *),FP_ICC comp_func) ;
if ( V_9 == NULL ) return ( - 1 ) ;
V_3 = ( int ) ( V_9 - V_1 -> V_5 ) ;
for ( ; V_3 > 0 ; V_3 -- )
if ( (* V_1 -> V_10 )( & ( V_1 -> V_5 [ V_3 - 1 ] ) , & V_5 ) < 0 )
break;
return ( V_3 ) ;
}
int F_5 ( T_1 * V_1 , char * V_5 )
{
return ( F_6 ( V_1 , V_5 , V_1 -> V_4 ) ) ;
}
int F_7 ( T_1 * V_1 , char * V_5 )
{
return ( F_6 ( V_1 , V_5 , 0 ) ) ;
}
char * F_8 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return ( NULL ) ;
if ( V_1 -> V_4 <= 0 ) return ( NULL ) ;
return ( F_2 ( V_1 , 0 ) ) ;
}
char * F_9 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return ( NULL ) ;
if ( V_1 -> V_4 <= 0 ) return ( NULL ) ;
return ( F_2 ( V_1 , V_1 -> V_4 - 1 ) ) ;
}
void F_10 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
if ( V_1 -> V_4 <= 0 ) return;
memset ( ( char * ) V_1 -> V_5 , 0 , sizeof( V_1 -> V_5 ) * V_1 -> V_4 ) ;
V_1 -> V_4 = 0 ;
}
void F_11 ( T_1 * V_1 , void (* F_12)() )
{
int V_3 ;
if ( V_1 == NULL ) return;
for ( V_3 = 0 ; V_3 < V_1 -> V_4 ; V_3 ++ )
if ( V_1 -> V_5 [ V_3 ] != NULL )
F_12 ( V_1 -> V_5 [ V_3 ] ) ;
F_13 ( V_1 ) ;
}
void F_13 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
if ( V_1 -> V_5 != NULL ) Free ( ( char * ) V_1 -> V_5 ) ;
Free ( ( char * ) V_1 ) ;
}
int F_14 ( T_1 * V_1 )
{
if( V_1 == NULL ) return - 1 ;
return V_1 -> V_4 ;
}
char * F_15 ( T_1 * V_1 , int V_3 )
{
if( V_1 == NULL ) return NULL ;
return V_1 -> V_5 [ V_3 ] ;
}
char * F_16 ( T_1 * V_1 , int V_3 , char * V_12 )
{
if( V_1 == NULL ) return NULL ;
return ( V_1 -> V_5 [ V_3 ] = V_12 ) ;
}
