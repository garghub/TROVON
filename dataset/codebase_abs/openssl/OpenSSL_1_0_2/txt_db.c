T_1 * F_1 ( T_2 * V_1 , int V_2 )
{
T_1 * V_3 = NULL ;
int V_4 = 1 ;
int V_5 = 0 ;
long V_6 = 0 ;
int V_7 , V_8 , V_9 ;
int V_10 = V_11 ;
int V_12 = 0 ;
char * V_13 , * V_14 ;
T_3 * V_15 ;
T_4 * V_16 = NULL ;
if ( ( V_16 = F_2 () ) == NULL )
goto V_17;
if ( ! F_3 ( V_16 , V_10 ) )
goto V_17;
if ( ( V_3 = F_4 ( sizeof( T_1 ) ) ) == NULL )
goto V_17;
V_3 -> V_18 = V_2 ;
V_3 -> V_19 = NULL ;
V_3 -> V_20 = NULL ;
if ( ( V_3 -> V_21 = F_5 () ) == NULL )
goto V_17;
if ( ( V_3 -> V_19 = F_4 ( sizeof( * V_3 -> V_19 ) * V_2 ) ) == NULL )
goto V_17;
if ( ( V_3 -> V_20 = F_4 ( sizeof( * ( V_3 -> V_20 ) ) * V_2 ) ) == NULL )
goto V_17;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ ) {
V_3 -> V_19 [ V_7 ] = NULL ;
V_3 -> V_20 [ V_7 ] = NULL ;
}
V_8 = ( V_2 + 1 ) * sizeof( char * ) ;
V_16 -> V_21 [ V_10 - 1 ] = '\0' ;
V_12 = 0 ;
for (; ; ) {
if ( V_12 != 0 ) {
V_10 += V_11 ;
if ( ! F_6 ( V_16 , V_10 ) )
goto V_17;
}
V_16 -> V_21 [ V_12 ] = '\0' ;
F_7 ( V_1 , & ( V_16 -> V_21 [ V_12 ] ) , V_10 - V_12 ) ;
V_6 ++ ;
if ( V_16 -> V_21 [ V_12 ] == '\0' )
break;
if ( ( V_12 == 0 ) && ( V_16 -> V_21 [ 0 ] == '#' ) )
continue;
V_7 = strlen ( & ( V_16 -> V_21 [ V_12 ] ) ) ;
V_12 += V_7 ;
if ( V_16 -> V_21 [ V_12 - 1 ] != '\n' )
continue;
else {
V_16 -> V_21 [ V_12 - 1 ] = '\0' ;
if ( ! ( V_13 = F_4 ( V_8 + V_12 ) ) )
goto V_17;
V_12 = 0 ;
}
V_15 = ( char * * ) V_13 ;
V_13 += V_8 ;
V_9 = 0 ;
V_15 [ V_9 ++ ] = V_13 ;
V_7 = 0 ;
V_14 = V_16 -> V_21 ;
V_5 = 0 ;
for (; ; ) {
if ( * V_14 == '\0' )
break;
if ( * V_14 == '\t' ) {
if ( V_5 )
V_13 -- ;
else {
* ( V_13 ++ ) = '\0' ;
V_14 ++ ;
if ( V_9 >= V_2 )
break;
V_15 [ V_9 ++ ] = V_13 ;
continue;
}
}
V_5 = ( * V_14 == '\\' ) ;
* ( V_13 ++ ) = * ( V_14 ++ ) ;
}
* ( V_13 ++ ) = '\0' ;
if ( ( V_9 != V_2 ) || ( * V_14 != '\0' ) ) {
#if ! F_8 ( V_22 ) && ! F_8 ( V_23 )
fprintf ( V_24 ,
L_1 ,
V_6 , V_2 , V_9 , V_14 ) ;
#endif
V_4 = 2 ;
goto V_17;
}
V_15 [ V_9 ] = V_13 ;
if ( ! F_9 ( V_3 -> V_21 , V_15 ) ) {
#if ! F_8 ( V_22 ) && ! F_8 ( V_23 )
fprintf ( V_24 , L_2 ) ;
#endif
V_4 = 2 ;
goto V_17;
}
}
V_4 = 0 ;
V_17:
F_10 ( V_16 ) ;
if ( V_4 ) {
#if ! F_8 ( V_22 ) && ! F_8 ( V_23 )
if ( V_4 == 1 )
fprintf ( V_24 , L_3 ) ;
#endif
if ( V_3 != NULL ) {
if ( V_3 -> V_21 != NULL )
F_11 ( V_3 -> V_21 ) ;
if ( V_3 -> V_19 != NULL )
F_12 ( V_3 -> V_19 ) ;
if ( V_3 -> V_20 != NULL )
F_12 ( V_3 -> V_20 ) ;
if ( V_3 != NULL )
F_12 ( V_3 ) ;
}
return ( NULL ) ;
} else
return ( V_3 ) ;
}
T_3 * F_13 ( T_1 * V_25 , int V_26 ,
T_3 * V_27 )
{
T_3 * V_3 ;
F_14 ( T_3 ) * V_28 ;
if ( V_26 >= V_25 -> V_18 ) {
V_25 -> error = V_29 ;
return ( NULL ) ;
}
V_28 = V_25 -> V_19 [ V_26 ] ;
if ( V_28 == NULL ) {
V_25 -> error = V_30 ;
return ( NULL ) ;
}
V_3 = F_15 ( V_28 , V_27 ) ;
V_25 -> error = V_31 ;
return ( V_3 ) ;
}
int F_16 ( T_1 * V_25 , int V_32 , int (* V_20) ( T_3 * ) ,
T_5 V_33 , T_6 V_34 )
{
F_14 ( T_3 ) * V_26 ;
T_3 * V_35 ;
int V_7 , V_9 ;
if ( V_32 >= V_25 -> V_18 ) {
V_25 -> error = V_29 ;
return ( 0 ) ;
}
if ( ( V_26 = ( F_14 ( T_3 ) * ) F_17 ( V_33 , V_34 ) ) == NULL ) {
V_25 -> error = V_36 ;
return ( 0 ) ;
}
V_9 = F_18 ( V_25 -> V_21 ) ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
V_35 = F_19 ( V_25 -> V_21 , V_7 ) ;
if ( ( V_20 != NULL ) && ( V_20 ( V_35 ) == 0 ) )
continue;
if ( ( V_35 = F_20 ( V_26 , V_35 ) ) != NULL ) {
V_25 -> error = V_37 ;
V_25 -> V_38 = F_21 ( V_25 -> V_21 , V_35 ) ;
V_25 -> V_39 = V_7 ;
F_22 ( V_26 ) ;
return ( 0 ) ;
}
}
if ( V_25 -> V_19 [ V_32 ] != NULL )
F_22 ( V_25 -> V_19 [ V_32 ] ) ;
V_25 -> V_19 [ V_32 ] = V_26 ;
V_25 -> V_20 [ V_32 ] = V_20 ;
return ( 1 ) ;
}
long F_23 ( T_2 * V_40 , T_1 * V_25 )
{
long V_7 , V_41 , V_9 , V_42 , V_43 , V_44 = 0 ;
char * V_13 , * * V_15 , * V_14 ;
T_4 * V_16 = NULL ;
long V_3 = - 1 ;
if ( ( V_16 = F_2 () ) == NULL )
goto V_17;
V_9 = F_18 ( V_25 -> V_21 ) ;
V_42 = V_25 -> V_18 ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
V_15 = F_19 ( V_25 -> V_21 , V_7 ) ;
V_43 = 0 ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ ) {
if ( V_15 [ V_41 ] != NULL )
V_43 += strlen ( V_15 [ V_41 ] ) ;
}
if ( ! F_6 ( V_16 , ( int ) ( V_43 * 2 + V_42 ) ) )
goto V_17;
V_13 = V_16 -> V_21 ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ ) {
V_14 = V_15 [ V_41 ] ;
if ( V_14 != NULL )
for (; ; ) {
if ( * V_14 == '\0' )
break;
if ( * V_14 == '\t' )
* ( V_13 ++ ) = '\\' ;
* ( V_13 ++ ) = * ( V_14 ++ ) ;
}
* ( V_13 ++ ) = '\t' ;
}
V_13 [ - 1 ] = '\n' ;
V_41 = V_13 - V_16 -> V_21 ;
if ( F_24 ( V_40 , V_16 -> V_21 , ( int ) V_41 ) != V_41 )
goto V_17;
V_44 += V_41 ;
}
V_3 = V_44 ;
V_17:
if ( V_16 != NULL )
F_10 ( V_16 ) ;
return ( V_3 ) ;
}
int F_25 ( T_1 * V_25 , T_3 * V_45 )
{
int V_7 ;
T_3 * V_35 ;
for ( V_7 = 0 ; V_7 < V_25 -> V_18 ; V_7 ++ ) {
if ( V_25 -> V_19 [ V_7 ] != NULL ) {
if ( ( V_25 -> V_20 [ V_7 ] != NULL ) && ( V_25 -> V_20 [ V_7 ] ( V_45 ) == 0 ) )
continue;
V_35 = F_15 ( V_25 -> V_19 [ V_7 ] , V_45 ) ;
if ( V_35 != NULL ) {
V_25 -> error = V_37 ;
V_25 -> V_38 = V_7 ;
V_25 -> V_46 = V_35 ;
goto V_17;
}
}
}
if ( ! F_9 ( V_25 -> V_21 , V_45 ) ) {
V_25 -> error = V_36 ;
goto V_17;
}
for ( V_7 = 0 ; V_7 < V_25 -> V_18 ; V_7 ++ ) {
if ( V_25 -> V_19 [ V_7 ] != NULL ) {
if ( ( V_25 -> V_20 [ V_7 ] != NULL ) && ( V_25 -> V_20 [ V_7 ] ( V_45 ) == 0 ) )
continue;
( void ) F_20 ( V_25 -> V_19 [ V_7 ] , V_45 ) ;
}
}
return ( 1 ) ;
V_17:
return ( 0 ) ;
}
void F_26 ( T_1 * V_25 )
{
int V_7 , V_9 ;
char * * V_13 , * V_47 ;
if ( V_25 == NULL )
return;
if ( V_25 -> V_19 != NULL ) {
for ( V_7 = V_25 -> V_18 - 1 ; V_7 >= 0 ; V_7 -- )
if ( V_25 -> V_19 [ V_7 ] != NULL )
F_22 ( V_25 -> V_19 [ V_7 ] ) ;
F_12 ( V_25 -> V_19 ) ;
}
if ( V_25 -> V_20 != NULL )
F_12 ( V_25 -> V_20 ) ;
if ( V_25 -> V_21 != NULL ) {
for ( V_7 = F_18 ( V_25 -> V_21 ) - 1 ; V_7 >= 0 ; V_7 -- ) {
V_13 = F_19 ( V_25 -> V_21 , V_7 ) ;
V_47 = V_13 [ V_25 -> V_18 ] ;
if ( V_47 == NULL ) {
for ( V_9 = 0 ; V_9 < V_25 -> V_18 ; V_9 ++ )
if ( V_13 [ V_9 ] != NULL )
F_12 ( V_13 [ V_9 ] ) ;
} else {
for ( V_9 = 0 ; V_9 < V_25 -> V_18 ; V_9 ++ ) {
if ( ( ( V_13 [ V_9 ] < ( char * ) V_13 ) || ( V_13 [ V_9 ] > V_47 ) )
&& ( V_13 [ V_9 ] != NULL ) )
F_12 ( V_13 [ V_9 ] ) ;
}
}
F_12 ( F_19 ( V_25 -> V_21 , V_7 ) ) ;
}
F_11 ( V_25 -> V_21 ) ;
}
F_12 ( V_25 ) ;
}
