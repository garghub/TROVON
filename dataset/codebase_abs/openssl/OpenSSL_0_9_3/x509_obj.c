char * F_1 ( T_1 * V_1 , char * V_2 , int V_3 )
{
T_2 * V_4 ;
int V_5 ;
int V_6 , V_7 , V_8 , V_9 , V_10 , V_11 , V_12 , type ;
const char * V_13 ;
char * V_14 ;
unsigned char * V_15 ;
T_3 * V_16 = NULL ;
static char V_17 [ 17 ] = L_1 ;
int V_18 [ 4 ] ;
char V_19 [ 80 ] ;
if ( V_2 == NULL )
{
if ( ( V_16 = F_2 () ) == NULL ) goto V_20;
if ( ! F_3 ( V_16 , 200 ) ) goto V_20;
V_16 -> V_21 [ 0 ] = '\0' ;
V_3 = 200 ;
}
if ( V_1 == NULL )
{
if( V_16 )
{
V_2 = V_16 -> V_21 ;
Free ( V_16 ) ;
}
strncpy ( V_2 , L_2 , V_3 ) ;
return V_2 ;
}
V_3 -- ;
V_8 = 0 ;
for ( V_5 = 0 ; V_5 < F_4 ( V_1 -> V_22 ) ; V_5 ++ )
{
V_4 = F_5 ( V_1 -> V_22 , V_5 ) ;
V_6 = F_6 ( V_4 -> V_23 ) ;
if ( ( V_6 == V_24 ) || ( ( V_13 = F_7 ( V_6 ) ) == NULL ) )
{
F_8 ( V_19 , sizeof( V_19 ) , V_4 -> V_23 ) ;
V_13 = V_19 ;
}
V_9 = strlen ( V_13 ) ;
type = V_4 -> V_25 -> type ;
V_11 = V_4 -> V_25 -> V_26 ;
V_15 = V_4 -> V_25 -> V_21 ;
if ( ( type == V_27 ) && ( ( V_11 % 4 ) == 0 ) )
{
V_18 [ 0 ] = V_18 [ 1 ] = V_18 [ 2 ] = V_18 [ 3 ] = 0 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
if ( V_15 [ V_12 ] != 0 ) V_18 [ V_12 & 3 ] = 1 ;
if ( V_18 [ 0 ] | V_18 [ 1 ] | V_18 [ 2 ] )
V_18 [ 0 ] = V_18 [ 1 ] = V_18 [ 2 ] = V_18 [ 3 ] = 1 ;
else
{
V_18 [ 0 ] = V_18 [ 1 ] = V_18 [ 2 ] = 0 ;
V_18 [ 3 ] = 1 ;
}
}
else
V_18 [ 0 ] = V_18 [ 1 ] = V_18 [ 2 ] = V_18 [ 3 ] = 1 ;
for ( V_10 = V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
{
if ( ! V_18 [ V_12 & 3 ] ) continue;
V_10 ++ ;
if ( ( V_15 [ V_12 ] < ' ' ) || ( V_15 [ V_12 ] > '~' ) ) V_10 += 3 ;
}
V_7 = V_8 ;
V_8 += 1 + V_9 + 1 + V_10 ;
if ( V_16 != NULL )
{
if ( ! F_3 ( V_16 , V_8 + 1 ) ) goto V_20;
V_14 = & ( V_16 -> V_21 [ V_7 ] ) ;
}
else if ( V_8 > V_3 )
{
break;
}
else
V_14 = & ( V_2 [ V_7 ] ) ;
* ( V_14 ++ ) = '/' ;
memcpy ( V_14 , V_13 , ( unsigned int ) V_9 ) ; V_14 += V_9 ;
* ( V_14 ++ ) = '=' ;
V_15 = V_4 -> V_25 -> V_21 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
{
if ( ! V_18 [ V_12 & 3 ] ) continue;
V_6 = V_15 [ V_12 ] ;
if ( ( V_6 < ' ' ) || ( V_6 > '~' ) )
{
* ( V_14 ++ ) = '\\' ;
* ( V_14 ++ ) = 'x' ;
* ( V_14 ++ ) = V_17 [ ( V_6 >> 4 ) & 0x0f ] ;
* ( V_14 ++ ) = V_17 [ V_6 & 0x0f ] ;
}
else
* ( V_14 ++ ) = V_6 ;
}
* V_14 = '\0' ;
}
if ( V_16 != NULL )
{
V_14 = V_16 -> V_21 ;
Free ( V_16 ) ;
}
else
V_14 = V_2 ;
return ( V_14 ) ;
V_20:
F_9 ( V_28 , V_29 ) ;
if ( V_16 != NULL ) F_10 ( V_16 ) ;
return ( NULL ) ;
}
