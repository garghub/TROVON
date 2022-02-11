int F_1 ( int V_1 , T_1 * * V_2 , long V_3 , char * V_4 ,
int (* F_2)() , int (* F_3)() , void (* F_4)() )
{
int V_5 = - 1 ;
T_2 * V_6 ;
F_5 () ;
if ( * V_2 == NULL )
* V_2 = F_6 () ;
if ( * V_2 == NULL )
{
F_7 ( V_7 , V_8 ) ;
goto V_9;
}
V_6 = ( T_2 * ) Malloc ( sizeof( T_2 ) ) ;
if ( V_6 == NULL )
{
F_7 ( V_7 , V_8 ) ;
goto V_9;
}
V_6 -> V_3 = V_3 ;
V_6 -> V_4 = V_4 ;
V_6 -> F_2 = F_2 ;
V_6 -> F_3 = F_3 ;
V_6 -> F_4 = F_4 ;
while ( F_8 ( * V_2 ) <= V_1 )
{
if ( ! F_9 ( * V_2 , NULL ) )
{
F_7 ( V_7 , V_8 ) ;
Free ( V_6 ) ;
goto V_9;
}
}
F_10 ( * V_2 , V_1 , ( char * ) V_6 ) ;
V_5 = V_1 ;
V_9:
F_11 () ;
return ( V_1 ) ;
}
int F_12 ( T_3 * V_10 , int V_1 , char * V_11 )
{
int V_12 ;
if ( V_10 -> V_13 == NULL )
{
if ( ( V_10 -> V_13 = F_6 () ) == NULL )
{
F_7 ( V_14 , V_8 ) ;
return ( 0 ) ;
}
}
V_12 = F_8 ( V_10 -> V_13 ) ;
while ( V_12 <= V_1 )
{
if ( ! F_9 ( V_10 -> V_13 , NULL ) )
{
F_7 ( V_14 , V_8 ) ;
return ( 0 ) ;
}
V_12 ++ ;
}
F_10 ( V_10 -> V_13 , V_1 , V_11 ) ;
return ( 1 ) ;
}
char * F_13 ( T_3 * V_10 , int V_1 )
{
if ( V_10 -> V_13 == NULL )
return ( 0 ) ;
else if ( V_1 >= F_8 ( V_10 -> V_13 ) )
return ( 0 ) ;
else
return ( F_14 ( V_10 -> V_13 , V_1 ) ) ;
}
int F_15 ( T_1 * V_15 , T_3 * V_16 ,
T_3 * V_17 )
{
int V_12 , V_18 , V_19 , V_20 ;
T_2 * V_21 ;
char * V_22 ;
if ( V_15 == NULL ) return ( 1 ) ;
if ( V_17 -> V_13 == NULL ) return ( 1 ) ;
V_19 = F_8 ( V_15 ) ;
V_18 = F_8 ( V_17 -> V_13 ) ;
for ( V_12 = 0 ; V_12 < V_18 ; V_12 ++ )
{
V_22 = F_13 ( V_17 , V_12 ) ;
if ( V_12 < V_19 )
{
V_21 = ( T_2 * ) F_14 ( V_15 , V_12 ) ;
if ( V_21 -> F_3 != NULL )
V_20 = V_21 -> F_3 ( V_16 , V_17 , ( char * * ) & V_22 , V_12 ,
V_21 -> V_3 , V_21 -> V_4 ) ;
}
F_12 ( V_16 , V_12 , V_22 ) ;
}
return ( 1 ) ;
}
void F_16 ( T_1 * V_15 , char * V_23 , T_3 * V_10 )
{
T_2 * V_19 ;
char * V_24 ;
int V_12 , V_25 ;
if ( V_15 != NULL )
{
V_25 = F_8 ( V_15 ) ;
for ( V_12 = 0 ; V_12 < V_25 ; V_12 ++ )
{
V_19 = ( T_2 * ) F_14 ( V_15 , V_12 ) ;
if ( ( V_19 != NULL ) && ( V_19 -> F_4 != NULL ) )
{
V_24 = F_13 ( V_10 , V_12 ) ;
V_19 -> F_4 ( V_23 , V_24 , V_10 , V_12 , V_19 -> V_3 , V_19 -> V_4 ) ;
}
}
}
if ( V_10 -> V_13 != NULL )
{
F_17 ( V_10 -> V_13 ) ;
V_10 -> V_13 = NULL ;
}
}
void F_18 ( T_1 * V_15 , char * V_23 , T_3 * V_10 )
{
T_2 * V_19 ;
char * V_24 ;
int V_12 , V_25 ;
V_10 -> V_13 = NULL ;
if ( V_15 != NULL )
{
V_25 = F_8 ( V_15 ) ;
for ( V_12 = 0 ; V_12 < V_25 ; V_12 ++ )
{
V_19 = ( T_2 * ) F_14 ( V_15 , V_12 ) ;
if ( ( V_19 != NULL ) && ( V_19 -> F_2 != NULL ) )
{
V_24 = F_13 ( V_10 , V_12 ) ;
V_19 -> F_2 ( V_23 , V_24 , V_10 , V_12 , V_19 -> V_3 , V_19 -> V_4 ) ;
}
}
}
}
