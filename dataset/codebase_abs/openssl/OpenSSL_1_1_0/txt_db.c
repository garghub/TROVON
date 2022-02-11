T_1 * F_1 ( T_2 * V_1 , int V_2 )
{
T_1 * V_3 = NULL ;
int V_4 = 0 ;
long V_5 = 0 ;
int V_6 , V_7 , V_8 ;
int V_9 = V_10 ;
int V_11 = 0 ;
char * V_12 , * V_13 ;
T_3 * V_14 ;
T_4 * V_15 = NULL ;
if ( ( V_15 = F_2 () ) == NULL )
goto V_16;
if ( ! F_3 ( V_15 , V_9 ) )
goto V_16;
if ( ( V_3 = F_4 ( sizeof( * V_3 ) ) ) == NULL )
goto V_16;
V_3 -> V_17 = V_2 ;
V_3 -> V_18 = NULL ;
V_3 -> V_19 = NULL ;
if ( ( V_3 -> V_20 = F_5 () ) == NULL )
goto V_16;
if ( ( V_3 -> V_18 = F_4 ( sizeof( * V_3 -> V_18 ) * V_2 ) ) == NULL )
goto V_16;
if ( ( V_3 -> V_19 = F_4 ( sizeof( * ( V_3 -> V_19 ) ) * V_2 ) ) == NULL )
goto V_16;
for ( V_6 = 0 ; V_6 < V_2 ; V_6 ++ ) {
V_3 -> V_18 [ V_6 ] = NULL ;
V_3 -> V_19 [ V_6 ] = NULL ;
}
V_7 = ( V_2 + 1 ) * sizeof( char * ) ;
V_15 -> V_20 [ V_9 - 1 ] = '\0' ;
V_11 = 0 ;
for (; ; ) {
if ( V_11 != 0 ) {
V_9 += V_10 ;
if ( ! F_6 ( V_15 , V_9 ) )
goto V_16;
}
V_15 -> V_20 [ V_11 ] = '\0' ;
F_7 ( V_1 , & ( V_15 -> V_20 [ V_11 ] ) , V_9 - V_11 ) ;
V_5 ++ ;
if ( V_15 -> V_20 [ V_11 ] == '\0' )
break;
if ( ( V_11 == 0 ) && ( V_15 -> V_20 [ 0 ] == '#' ) )
continue;
V_6 = strlen ( & ( V_15 -> V_20 [ V_11 ] ) ) ;
V_11 += V_6 ;
if ( V_15 -> V_20 [ V_11 - 1 ] != '\n' )
continue;
else {
V_15 -> V_20 [ V_11 - 1 ] = '\0' ;
if ( ( V_12 = F_4 ( V_7 + V_11 ) ) == NULL )
goto V_16;
V_11 = 0 ;
}
V_14 = ( char * * ) V_12 ;
V_12 += V_7 ;
V_8 = 0 ;
V_14 [ V_8 ++ ] = V_12 ;
V_6 = 0 ;
V_13 = V_15 -> V_20 ;
V_4 = 0 ;
for (; ; ) {
if ( * V_13 == '\0' )
break;
if ( * V_13 == '\t' ) {
if ( V_4 )
V_12 -- ;
else {
* ( V_12 ++ ) = '\0' ;
V_13 ++ ;
if ( V_8 >= V_2 )
break;
V_14 [ V_8 ++ ] = V_12 ;
continue;
}
}
V_4 = ( * V_13 == '\\' ) ;
* ( V_12 ++ ) = * ( V_13 ++ ) ;
}
* ( V_12 ++ ) = '\0' ;
if ( ( V_8 != V_2 ) || ( * V_13 != '\0' ) ) {
V_3 -> error = V_21 ;
goto V_16;
}
V_14 [ V_8 ] = V_12 ;
if ( ! F_8 ( V_3 -> V_20 , V_14 ) )
goto V_16;
}
F_9 ( V_15 ) ;
return V_3 ;
V_16:
F_9 ( V_15 ) ;
if ( V_3 != NULL ) {
F_10 ( V_3 -> V_20 ) ;
F_11 ( V_3 -> V_18 ) ;
F_11 ( V_3 -> V_19 ) ;
F_11 ( V_3 ) ;
}
return ( NULL ) ;
}
T_3 * F_12 ( T_1 * V_22 , int V_23 ,
T_3 * V_24 )
{
T_3 * V_3 ;
F_13 ( T_3 ) * V_25 ;
if ( V_23 >= V_22 -> V_17 ) {
V_22 -> error = V_26 ;
return ( NULL ) ;
}
V_25 = V_22 -> V_18 [ V_23 ] ;
if ( V_25 == NULL ) {
V_22 -> error = V_27 ;
return ( NULL ) ;
}
V_3 = F_14 ( V_25 , V_24 ) ;
V_22 -> error = V_28 ;
return ( V_3 ) ;
}
int F_15 ( T_1 * V_22 , int V_29 , int (* V_19) ( T_3 * ) ,
T_5 V_30 , T_6 V_31 )
{
F_13 ( T_3 ) * V_23 ;
T_3 * V_32 ;
int V_6 , V_8 ;
if ( V_29 >= V_22 -> V_17 ) {
V_22 -> error = V_26 ;
return ( 0 ) ;
}
if ( ( V_23 = ( F_13 ( T_3 ) * ) F_16 ( V_30 , V_31 ) ) == NULL ) {
V_22 -> error = V_33 ;
return ( 0 ) ;
}
V_8 = F_17 ( V_22 -> V_20 ) ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ ) {
V_32 = F_18 ( V_22 -> V_20 , V_6 ) ;
if ( ( V_19 != NULL ) && ( V_19 ( V_32 ) == 0 ) )
continue;
if ( ( V_32 = F_19 ( V_23 , V_32 ) ) != NULL ) {
V_22 -> error = V_34 ;
V_22 -> V_35 = F_20 ( V_22 -> V_20 , V_32 ) ;
V_22 -> V_36 = V_6 ;
F_21 ( V_23 ) ;
return ( 0 ) ;
}
}
F_21 ( V_22 -> V_18 [ V_29 ] ) ;
V_22 -> V_18 [ V_29 ] = V_23 ;
V_22 -> V_19 [ V_29 ] = V_19 ;
return ( 1 ) ;
}
long F_22 ( T_2 * V_37 , T_1 * V_22 )
{
long V_6 , V_38 , V_8 , V_39 , V_40 , V_41 = 0 ;
char * V_12 , * * V_14 , * V_13 ;
T_4 * V_15 = NULL ;
long V_3 = - 1 ;
if ( ( V_15 = F_2 () ) == NULL )
goto V_16;
V_8 = F_17 ( V_22 -> V_20 ) ;
V_39 = V_22 -> V_17 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ ) {
V_14 = F_18 ( V_22 -> V_20 , V_6 ) ;
V_40 = 0 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
if ( V_14 [ V_38 ] != NULL )
V_40 += strlen ( V_14 [ V_38 ] ) ;
}
if ( ! F_6 ( V_15 , ( int ) ( V_40 * 2 + V_39 ) ) )
goto V_16;
V_12 = V_15 -> V_20 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
V_13 = V_14 [ V_38 ] ;
if ( V_13 != NULL )
for (; ; ) {
if ( * V_13 == '\0' )
break;
if ( * V_13 == '\t' )
* ( V_12 ++ ) = '\\' ;
* ( V_12 ++ ) = * ( V_13 ++ ) ;
}
* ( V_12 ++ ) = '\t' ;
}
V_12 [ - 1 ] = '\n' ;
V_38 = V_12 - V_15 -> V_20 ;
if ( F_23 ( V_37 , V_15 -> V_20 , ( int ) V_38 ) != V_38 )
goto V_16;
V_41 += V_38 ;
}
V_3 = V_41 ;
V_16:
F_9 ( V_15 ) ;
return ( V_3 ) ;
}
int F_24 ( T_1 * V_22 , T_3 * V_42 )
{
int V_6 ;
T_3 * V_32 ;
for ( V_6 = 0 ; V_6 < V_22 -> V_17 ; V_6 ++ ) {
if ( V_22 -> V_18 [ V_6 ] != NULL ) {
if ( ( V_22 -> V_19 [ V_6 ] != NULL ) && ( V_22 -> V_19 [ V_6 ] ( V_42 ) == 0 ) )
continue;
V_32 = F_14 ( V_22 -> V_18 [ V_6 ] , V_42 ) ;
if ( V_32 != NULL ) {
V_22 -> error = V_34 ;
V_22 -> V_35 = V_6 ;
V_22 -> V_43 = V_32 ;
goto V_16;
}
}
}
if ( ! F_8 ( V_22 -> V_20 , V_42 ) ) {
V_22 -> error = V_33 ;
goto V_16;
}
for ( V_6 = 0 ; V_6 < V_22 -> V_17 ; V_6 ++ ) {
if ( V_22 -> V_18 [ V_6 ] != NULL ) {
if ( ( V_22 -> V_19 [ V_6 ] != NULL ) && ( V_22 -> V_19 [ V_6 ] ( V_42 ) == 0 ) )
continue;
( void ) F_19 ( V_22 -> V_18 [ V_6 ] , V_42 ) ;
}
}
return ( 1 ) ;
V_16:
return ( 0 ) ;
}
void F_25 ( T_1 * V_22 )
{
int V_6 , V_8 ;
char * * V_12 , * V_44 ;
if ( V_22 == NULL )
return;
if ( V_22 -> V_18 != NULL ) {
for ( V_6 = V_22 -> V_17 - 1 ; V_6 >= 0 ; V_6 -- )
F_21 ( V_22 -> V_18 [ V_6 ] ) ;
F_11 ( V_22 -> V_18 ) ;
}
F_11 ( V_22 -> V_19 ) ;
if ( V_22 -> V_20 != NULL ) {
for ( V_6 = F_17 ( V_22 -> V_20 ) - 1 ; V_6 >= 0 ; V_6 -- ) {
V_12 = F_18 ( V_22 -> V_20 , V_6 ) ;
V_44 = V_12 [ V_22 -> V_17 ] ;
if ( V_44 == NULL ) {
for ( V_8 = 0 ; V_8 < V_22 -> V_17 ; V_8 ++ )
F_11 ( V_12 [ V_8 ] ) ;
} else {
for ( V_8 = 0 ; V_8 < V_22 -> V_17 ; V_8 ++ ) {
if ( ( ( V_12 [ V_8 ] < ( char * ) V_12 ) || ( V_12 [ V_8 ] > V_44 ) ) )
F_11 ( V_12 [ V_8 ] ) ;
}
}
F_11 ( F_18 ( V_22 -> V_20 , V_6 ) ) ;
}
F_10 ( V_22 -> V_20 ) ;
}
F_11 ( V_22 ) ;
}
