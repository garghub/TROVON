int F_1 ( struct V_1 * V_1 , const T_1 * V_2 )
{
static const int V_3 [ 9 ] = { 0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 , 0 } ;
static const int V_4 [ 9 ] = { 99 , 99 , 12 , 31 , 23 , 59 , 59 , 12 , 59 } ;
char * V_5 ;
int V_6 , V_7 , V_8 , V_9 ;
if ( V_2 -> type != V_10 )
return ( 0 ) ;
V_8 = V_2 -> V_11 ;
V_5 = ( char * ) V_2 -> V_12 ;
V_9 = 0 ;
if ( V_8 < 13 )
goto V_13;
for ( V_7 = 0 ; V_7 < 7 ; V_7 ++ ) {
if ( ( V_7 == 6 ) && ( ( V_5 [ V_9 ] == 'Z' ) || ( V_5 [ V_9 ] == '+' ) || ( V_5 [ V_9 ] == '-' ) ) ) {
V_7 ++ ;
if ( V_1 )
V_1 -> V_14 = 0 ;
break;
}
if ( ( V_5 [ V_9 ] < '0' ) || ( V_5 [ V_9 ] > '9' ) )
goto V_13;
V_6 = V_5 [ V_9 ] - '0' ;
if ( ++ V_9 > V_8 )
goto V_13;
if ( ( V_5 [ V_9 ] < '0' ) || ( V_5 [ V_9 ] > '9' ) )
goto V_13;
V_6 = ( V_6 * 10 ) + V_5 [ V_9 ] - '0' ;
if ( ++ V_9 > V_8 )
goto V_13;
if ( ( V_6 < V_3 [ V_7 ] ) || ( V_6 > V_4 [ V_7 ] ) )
goto V_13;
if ( V_1 ) {
switch ( V_7 ) {
case 0 :
V_1 -> V_15 = V_6 * 100 - 1900 ;
break;
case 1 :
V_1 -> V_15 += V_6 ;
break;
case 2 :
V_1 -> V_16 = V_6 - 1 ;
break;
case 3 :
V_1 -> V_17 = V_6 ;
break;
case 4 :
V_1 -> V_18 = V_6 ;
break;
case 5 :
V_1 -> V_19 = V_6 ;
break;
case 6 :
V_1 -> V_14 = V_6 ;
break;
}
}
}
if ( V_5 [ V_9 ] == '.' ) {
if ( ++ V_9 > V_8 )
goto V_13;
V_7 = V_9 ;
while ( ( V_5 [ V_9 ] >= '0' ) && ( V_5 [ V_9 ] <= '9' ) && ( V_9 <= V_8 ) )
V_9 ++ ;
if ( V_7 == V_9 )
goto V_13;
}
if ( V_5 [ V_9 ] == 'Z' )
V_9 ++ ;
else if ( ( V_5 [ V_9 ] == '+' ) || ( V_5 [ V_9 ] == '-' ) ) {
int V_20 = V_5 [ V_9 ] == '-' ? - 1 : 1 , V_21 = 0 ;
V_9 ++ ;
if ( V_9 + 4 > V_8 )
goto V_13;
for ( V_7 = 7 ; V_7 < 9 ; V_7 ++ ) {
if ( ( V_5 [ V_9 ] < '0' ) || ( V_5 [ V_9 ] > '9' ) )
goto V_13;
V_6 = V_5 [ V_9 ] - '0' ;
V_9 ++ ;
if ( ( V_5 [ V_9 ] < '0' ) || ( V_5 [ V_9 ] > '9' ) )
goto V_13;
V_6 = ( V_6 * 10 ) + V_5 [ V_9 ] - '0' ;
if ( ( V_6 < V_3 [ V_7 ] ) || ( V_6 > V_4 [ V_7 ] ) )
goto V_13;
if ( V_1 ) {
if ( V_7 == 7 )
V_21 = V_6 * 3600 ;
else if ( V_7 == 8 )
V_21 += V_6 * 60 ;
}
V_9 ++ ;
}
if ( V_21 && ! F_2 ( V_1 , 0 , V_21 * V_20 ) )
return 0 ;
} else if ( V_5 [ V_9 ] ) {
goto V_13;
}
return ( V_9 == V_8 ) ;
V_13:
return ( 0 ) ;
}
int F_3 ( const T_1 * V_2 )
{
return F_1 ( NULL , V_2 ) ;
}
int F_4 ( T_1 * V_22 , const char * V_23 )
{
T_1 V_24 ;
V_24 . type = V_10 ;
V_24 . V_11 = strlen ( V_23 ) ;
V_24 . V_12 = ( unsigned char * ) V_23 ;
if ( F_3 ( & V_24 ) ) {
if ( V_22 != NULL ) {
if ( ! F_5 ( ( V_25 * ) V_22 ,
( unsigned char * ) V_23 , V_24 . V_11 ) )
return 0 ;
V_22 -> type = V_10 ;
}
return ( 1 ) ;
} else
return ( 0 ) ;
}
T_1 * F_6 ( T_1 * V_22 ,
T_2 V_24 )
{
return F_7 ( V_22 , V_24 , 0 , 0 ) ;
}
T_1 * F_7 ( T_1 * V_22 ,
T_2 V_24 , int V_26 ,
long V_27 )
{
char * V_28 ;
struct V_1 * V_29 ;
struct V_1 V_12 ;
T_3 V_30 = 20 ;
if ( V_22 == NULL )
V_22 = F_8 () ;
if ( V_22 == NULL )
return ( NULL ) ;
V_29 = F_9 ( & V_24 , & V_12 ) ;
if ( V_29 == NULL )
return ( NULL ) ;
if ( V_26 || V_27 ) {
if ( ! F_2 ( V_29 , V_26 , V_27 ) )
return NULL ;
}
V_28 = ( char * ) V_22 -> V_12 ;
if ( ( V_28 == NULL ) || ( ( T_3 ) V_22 -> V_11 < V_30 ) ) {
V_28 = F_10 ( V_30 ) ;
if ( V_28 == NULL ) {
F_11 ( V_31 , V_32 ) ;
return ( NULL ) ;
}
if ( V_22 -> V_12 != NULL )
F_12 ( V_22 -> V_12 ) ;
V_22 -> V_12 = ( unsigned char * ) V_28 ;
}
F_13 ( V_28 , V_30 , L_1 , V_29 -> V_15 + 1900 ,
V_29 -> V_16 + 1 , V_29 -> V_17 , V_29 -> V_18 , V_29 -> V_19 ,
V_29 -> V_14 ) ;
V_22 -> V_11 = strlen ( V_28 ) ;
V_22 -> type = V_10 ;
#ifdef F_14
F_15 ( V_22 -> V_12 , V_22 -> V_12 , V_22 -> V_11 ) ;
#endif
return ( V_22 ) ;
}
