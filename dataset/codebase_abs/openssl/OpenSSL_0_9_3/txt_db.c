T_1 * F_1 ( T_2 * V_1 , int V_2 )
{
T_1 * V_3 = NULL ;
int V_4 = 1 ;
int V_5 = 0 ;
long V_6 = 0 ;
int V_7 , V_8 , V_9 ;
int V_10 = V_11 ;
int V_12 = 0 ;
char * V_13 , * * V_14 , * V_15 ;
T_3 * V_16 = NULL ;
if ( ( V_16 = F_2 () ) == NULL ) goto V_17;
if ( ! F_3 ( V_16 , V_10 ) ) goto V_17;
if ( ( V_3 = ( T_1 * ) Malloc ( sizeof( T_1 ) ) ) == NULL )
goto V_17;
V_3 -> V_18 = V_2 ;
V_3 -> V_19 = NULL ;
V_3 -> V_20 = NULL ;
if ( ( V_3 -> V_21 = F_4 () ) == NULL )
goto V_17;
if ( ( V_3 -> V_19 = ( V_22 * * ) Malloc ( sizeof( V_22 * ) * V_2 ) ) == NULL )
goto V_17;
if ( ( V_3 -> V_20 = ( int ( * * ) () ) Malloc ( sizeof( int ( * * ) () ) * V_2 ) ) == NULL )
goto V_17;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ )
{
V_3 -> V_19 [ V_7 ] = NULL ;
V_3 -> V_20 [ V_7 ] = NULL ;
}
V_8 = ( V_2 + 1 ) * sizeof( char * ) ;
V_16 -> V_21 [ V_10 - 1 ] = '\0' ;
V_12 = 0 ;
for (; ; )
{
if ( V_12 != 0 )
{
V_10 += V_11 ;
if ( ! F_3 ( V_16 , V_10 ) ) goto V_17;
}
V_16 -> V_21 [ V_12 ] = '\0' ;
F_5 ( V_1 , & ( V_16 -> V_21 [ V_12 ] ) , V_10 - V_12 ) ;
V_6 ++ ;
if ( V_16 -> V_21 [ V_12 ] == '\0' ) break;
if ( ( V_12 == 0 ) && ( V_16 -> V_21 [ 0 ] == '#' ) ) continue;
V_7 = strlen ( & ( V_16 -> V_21 [ V_12 ] ) ) ;
V_12 += V_7 ;
if ( V_16 -> V_21 [ V_12 - 1 ] != '\n' )
continue;
else
{
V_16 -> V_21 [ V_12 - 1 ] = '\0' ;
V_13 = ( char * ) Malloc ( V_8 + V_12 ) ;
V_12 = 0 ;
}
V_14 = ( char * * ) V_13 ;
V_13 += V_8 ;
V_9 = 0 ;
V_14 [ V_9 ++ ] = V_13 ;
V_7 = 0 ;
V_15 = V_16 -> V_21 ;
V_5 = 0 ;
for (; ; )
{
if ( * V_15 == '\0' ) break;
if ( * V_15 == '\t' )
{
if ( V_5 )
V_13 -- ;
else
{
* ( V_13 ++ ) = '\0' ;
V_15 ++ ;
if ( V_9 >= V_2 ) break;
V_14 [ V_9 ++ ] = V_13 ;
continue;
}
}
V_5 = ( * V_15 == '\\' ) ;
* ( V_13 ++ ) = * ( V_15 ++ ) ;
}
* ( V_13 ++ ) = '\0' ;
if ( ( V_9 != V_2 ) || ( * V_15 != '\0' ) )
{
#if ! F_6 ( V_23 ) && ! F_6 ( V_24 )
fprintf ( V_25 , L_1 , V_6 , V_2 , V_9 , V_15 ) ;
#endif
V_4 = 2 ;
goto V_17;
}
V_14 [ V_9 ] = V_13 ;
if ( ! F_7 ( V_3 -> V_21 , ( char * ) V_14 ) )
{
#if ! F_6 ( V_23 ) && ! F_6 ( V_24 )
fprintf ( V_25 , L_2 ) ;
#endif
V_4 = 2 ;
goto V_17;
}
}
V_4 = 0 ;
V_17:
F_8 ( V_16 ) ;
if ( V_4 )
{
#if ! F_6 ( V_23 ) && ! F_6 ( V_24 )
if ( V_4 == 1 ) fprintf ( V_25 , L_3 ) ;
#endif
if ( V_3 -> V_21 != NULL ) F_9 ( V_3 -> V_21 ) ;
if ( V_3 -> V_19 != NULL ) Free ( V_3 -> V_19 ) ;
if ( V_3 -> V_20 != NULL ) Free ( ( char * ) V_3 -> V_20 ) ;
if ( V_3 != NULL ) Free ( V_3 ) ;
return ( NULL ) ;
}
else
return ( V_3 ) ;
}
char * * F_10 ( T_1 * V_26 , int V_27 , char * * V_28 )
{
char * * V_3 ;
V_22 * V_29 ;
if ( V_27 >= V_26 -> V_18 )
{
V_26 -> error = V_30 ;
return ( NULL ) ;
}
V_29 = V_26 -> V_19 [ V_27 ] ;
if ( V_29 == NULL )
{
V_26 -> error = V_31 ;
return ( NULL ) ;
}
V_3 = ( char * * ) F_11 ( V_29 , ( char * ) V_28 ) ;
V_26 -> error = V_32 ;
return ( V_3 ) ;
}
long F_12 ( T_2 * V_33 , T_1 * V_26 )
{
long V_7 , V_34 , V_9 , V_35 , V_36 , V_37 = 0 ;
char * V_13 , * * V_14 , * V_15 ;
T_3 * V_16 = NULL ;
long V_3 = - 1 ;
if ( ( V_16 = F_2 () ) == NULL )
goto V_17;
V_9 = F_13 ( V_26 -> V_21 ) ;
V_35 = V_26 -> V_18 ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ )
{
V_14 = ( char * * ) F_14 ( V_26 -> V_21 , V_7 ) ;
V_36 = 0 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ )
{
if ( V_14 [ V_34 ] != NULL )
V_36 += strlen ( V_14 [ V_34 ] ) ;
}
if ( ! F_3 ( V_16 , ( int ) ( V_36 * 2 + V_35 ) ) ) goto V_17;
V_13 = V_16 -> V_21 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ )
{
V_15 = V_14 [ V_34 ] ;
if ( V_15 != NULL )
for (; ; )
{
if ( * V_15 == '\0' ) break;
if ( * V_15 == '\t' ) * ( V_13 ++ ) = '\\' ;
* ( V_13 ++ ) = * ( V_15 ++ ) ;
}
* ( V_13 ++ ) = '\t' ;
}
V_13 [ - 1 ] = '\n' ;
V_34 = V_13 - V_16 -> V_21 ;
if ( F_15 ( V_33 , V_16 -> V_21 , ( int ) V_34 ) != V_34 )
goto V_17;
V_37 += V_34 ;
}
V_3 = V_37 ;
V_17:
if ( V_16 != NULL ) F_8 ( V_16 ) ;
return ( V_3 ) ;
}
int F_16 ( T_1 * V_26 , char * * V_38 )
{
int V_7 ;
char * * V_39 ;
for ( V_7 = 0 ; V_7 < V_26 -> V_18 ; V_7 ++ )
{
if ( V_26 -> V_19 [ V_7 ] != NULL )
{
if ( ( V_26 -> V_20 [ V_7 ] != NULL ) &&
( V_26 -> V_20 [ V_7 ] ( V_38 ) == 0 ) ) continue;
V_39 = ( char * * ) F_11 ( V_26 -> V_19 [ V_7 ] , ( char * ) V_38 ) ;
if ( V_39 != NULL )
{
V_26 -> error = V_40 ;
V_26 -> V_41 = V_7 ;
V_26 -> V_42 = V_39 ;
goto V_17;
}
}
}
if ( ! F_7 ( V_26 -> V_21 , ( char * ) V_38 ) )
{
V_26 -> error = V_43 ;
goto V_17;
}
for ( V_7 = 0 ; V_7 < V_26 -> V_18 ; V_7 ++ )
{
if ( V_26 -> V_19 [ V_7 ] != NULL )
{
if ( ( V_26 -> V_20 [ V_7 ] != NULL ) &&
( V_26 -> V_20 [ V_7 ] ( V_38 ) == 0 ) ) continue;
F_17 ( V_26 -> V_19 [ V_7 ] , ( char * ) V_38 ) ;
}
}
return ( 1 ) ;
V_17:
return ( 0 ) ;
}
void F_18 ( T_1 * V_26 )
{
int V_7 , V_9 ;
char * * V_13 , * V_44 ;
if( V_26 == NULL )
return;
if ( V_26 -> V_19 != NULL )
{
for ( V_7 = V_26 -> V_18 - 1 ; V_7 >= 0 ; V_7 -- )
if ( V_26 -> V_19 [ V_7 ] != NULL ) F_19 ( V_26 -> V_19 [ V_7 ] ) ;
Free ( V_26 -> V_19 ) ;
}
if ( V_26 -> V_20 != NULL )
Free ( V_26 -> V_20 ) ;
if ( V_26 -> V_21 != NULL )
{
for ( V_7 = F_13 ( V_26 -> V_21 ) - 1 ; V_7 >= 0 ; V_7 -- )
{
V_13 = ( char * * ) F_14 ( V_26 -> V_21 , V_7 ) ;
V_44 = V_13 [ V_26 -> V_18 ] ;
if ( V_44 == NULL )
{
for ( V_9 = 0 ; V_9 < V_26 -> V_18 ; V_9 ++ )
if ( V_13 [ V_9 ] != NULL ) Free ( V_13 [ V_9 ] ) ;
}
else
{
for ( V_9 = 0 ; V_9 < V_26 -> V_18 ; V_9 ++ )
{
if ( ( ( V_13 [ V_9 ] < ( char * ) V_13 ) || ( V_13 [ V_9 ] > V_44 ) )
&& ( V_13 [ V_9 ] != NULL ) )
Free ( V_13 [ V_9 ] ) ;
}
}
Free ( F_14 ( V_26 -> V_21 , V_7 ) ) ;
}
F_9 ( V_26 -> V_21 ) ;
}
Free ( V_26 ) ;
}
