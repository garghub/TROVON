int F_1 ( T_1 * V_1 , int V_2 , char * V_3 , int V_4 )
{
T_2 * V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 == NULL )
return ( - 1 ) ;
return ( F_3 ( V_1 , V_5 , V_3 , V_4 ) ) ;
}
int F_3 ( T_1 * V_1 , T_2 * V_5 , char * V_3 ,
int V_4 )
{
int V_6 ;
T_3 * V_7 ;
V_6 = F_4 ( V_1 , V_5 , - 1 ) ;
if ( V_6 < 0 )
return ( - 1 ) ;
V_7 = F_5 ( F_6 ( V_1 , V_6 ) ) ;
V_6 = ( V_7 -> V_8 > ( V_4 - 1 ) ) ? ( V_4 - 1 ) : V_7 -> V_8 ;
if ( V_3 == NULL )
return ( V_7 -> V_8 ) ;
memcpy ( V_3 , V_7 -> V_7 , V_6 ) ;
V_3 [ V_6 ] = '\0' ;
return ( V_6 ) ;
}
int F_7 ( T_1 * V_1 )
{
if ( V_1 == NULL )
return ( 0 ) ;
return ( F_8 ( V_1 -> V_9 ) ) ;
}
int F_9 ( T_1 * V_1 , int V_2 , int V_10 )
{
T_2 * V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 == NULL )
return ( - 2 ) ;
return ( F_4 ( V_1 , V_5 , V_10 ) ) ;
}
int F_4 ( T_1 * V_1 , T_2 * V_5 , int V_10 )
{
int V_11 ;
T_4 * V_12 ;
F_10 ( T_4 ) * V_13 ;
if ( V_1 == NULL )
return ( - 1 ) ;
if ( V_10 < 0 )
V_10 = - 1 ;
V_13 = V_1 -> V_9 ;
V_11 = F_8 ( V_13 ) ;
for ( V_10 ++ ; V_10 < V_11 ; V_10 ++ ) {
V_12 = F_11 ( V_13 , V_10 ) ;
if ( F_12 ( V_12 -> V_14 , V_5 ) == 0 )
return ( V_10 ) ;
}
return ( - 1 ) ;
}
T_4 * F_6 ( T_1 * V_1 , int V_15 )
{
if ( V_1 == NULL || F_8 ( V_1 -> V_9 ) <= V_15
|| V_15 < 0 )
return ( NULL ) ;
else
return ( F_11 ( V_1 -> V_9 , V_15 ) ) ;
}
T_4 * F_13 ( T_1 * V_1 , int V_15 )
{
T_4 * V_16 ;
int V_6 , V_11 , V_17 , V_18 ;
F_10 ( T_4 ) * V_13 ;
if ( V_1 == NULL || F_8 ( V_1 -> V_9 ) <= V_15
|| V_15 < 0 )
return ( NULL ) ;
V_13 = V_1 -> V_9 ;
V_16 = F_14 ( V_13 , V_15 ) ;
V_11 = F_8 ( V_13 ) ;
V_1 -> V_19 = 1 ;
if ( V_15 == V_11 )
return ( V_16 ) ;
if ( V_15 != 0 )
V_17 = ( F_11 ( V_13 , V_15 - 1 ) ) -> V_20 ;
else
V_17 = V_16 -> V_20 - 1 ;
V_18 = F_11 ( V_13 , V_15 ) -> V_20 ;
if ( V_17 + 1 < V_18 )
for ( V_6 = V_15 ; V_6 < V_11 ; V_6 ++ )
F_11 ( V_13 , V_6 ) -> V_20 -- ;
return ( V_16 ) ;
}
int F_15 ( T_1 * V_1 , T_2 * V_5 , int type ,
unsigned char * V_21 , int V_4 , int V_15 ,
int V_20 )
{
T_4 * V_12 ;
int V_16 ;
V_12 = F_16 ( NULL , V_5 , type , V_21 , V_4 ) ;
if ( ! V_12 )
return 0 ;
V_16 = F_17 ( V_1 , V_12 , V_15 , V_20 ) ;
F_18 ( V_12 ) ;
return V_16 ;
}
int F_19 ( T_1 * V_1 , int V_2 , int type ,
unsigned char * V_21 , int V_4 , int V_15 ,
int V_20 )
{
T_4 * V_12 ;
int V_16 ;
V_12 = F_20 ( NULL , V_2 , type , V_21 , V_4 ) ;
if ( ! V_12 )
return 0 ;
V_16 = F_17 ( V_1 , V_12 , V_15 , V_20 ) ;
F_18 ( V_12 ) ;
return V_16 ;
}
int F_21 ( T_1 * V_1 , const char * V_22 , int type ,
const unsigned char * V_21 , int V_4 , int V_15 ,
int V_20 )
{
T_4 * V_12 ;
int V_16 ;
V_12 = F_22 ( NULL , V_22 , type , V_21 , V_4 ) ;
if ( ! V_12 )
return 0 ;
V_16 = F_17 ( V_1 , V_12 , V_15 , V_20 ) ;
F_18 ( V_12 ) ;
return V_16 ;
}
int F_17 ( T_1 * V_1 , T_4 * V_12 , int V_15 ,
int V_20 )
{
T_4 * V_23 = NULL ;
int V_11 , V_6 , V_24 ;
F_10 ( T_4 ) * V_13 ;
if ( V_1 == NULL )
return ( 0 ) ;
V_13 = V_1 -> V_9 ;
V_11 = F_8 ( V_13 ) ;
if ( V_15 > V_11 )
V_15 = V_11 ;
else if ( V_15 < 0 )
V_15 = V_11 ;
V_1 -> V_19 = 1 ;
if ( V_20 == - 1 ) {
if ( V_15 == 0 ) {
V_20 = 0 ;
V_24 = 1 ;
} else {
V_20 = F_11 ( V_13 , V_15 - 1 ) -> V_20 ;
V_24 = 0 ;
}
} else {
if ( V_15 >= V_11 ) {
if ( V_15 != 0 )
V_20 = F_11 ( V_13 , V_15 - 1 ) -> V_20 + 1 ;
else
V_20 = 0 ;
} else
V_20 = F_11 ( V_13 , V_15 ) -> V_20 ;
V_24 = ( V_20 == 0 ) ? 1 : 0 ;
}
if ( ( V_23 = F_23 ( V_12 ) ) == NULL )
goto V_25;
V_23 -> V_20 = V_20 ;
if ( ! F_24 ( V_13 , V_23 , V_15 ) ) {
F_25 ( V_26 , V_27 ) ;
goto V_25;
}
if ( V_24 ) {
V_11 = F_8 ( V_13 ) ;
for ( V_6 = V_15 + 1 ; V_6 < V_11 ; V_6 ++ )
F_11 ( V_13 , V_6 - 1 ) -> V_20 += 1 ;
}
return ( 1 ) ;
V_25:
if ( V_23 != NULL )
F_18 ( V_23 ) ;
return ( 0 ) ;
}
T_4 * F_22 ( T_4 * * V_12 ,
const char * V_22 , int type ,
const unsigned char * V_21 ,
int V_4 )
{
T_2 * V_5 ;
T_4 * V_28 ;
V_5 = F_26 ( V_22 , 0 ) ;
if ( V_5 == NULL ) {
F_25 ( V_29 ,
V_30 ) ;
F_27 ( 2 , L_1 , V_22 ) ;
return ( NULL ) ;
}
V_28 = F_16 ( V_12 , V_5 , type , V_21 , V_4 ) ;
F_28 ( V_5 ) ;
return V_28 ;
}
T_4 * F_20 ( T_4 * * V_12 , int V_2 ,
int type , unsigned char * V_21 ,
int V_4 )
{
T_2 * V_5 ;
T_4 * V_28 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 == NULL ) {
F_25 ( V_31 , V_32 ) ;
return ( NULL ) ;
}
V_28 = F_16 ( V_12 , V_5 , type , V_21 , V_4 ) ;
F_28 ( V_5 ) ;
return V_28 ;
}
T_4 * F_16 ( T_4 * * V_12 ,
T_2 * V_5 , int type ,
const unsigned char * V_21 ,
int V_4 )
{
T_4 * V_16 ;
if ( ( V_12 == NULL ) || ( * V_12 == NULL ) ) {
if ( ( V_16 = F_29 () ) == NULL )
return ( NULL ) ;
} else
V_16 = * V_12 ;
if ( ! F_30 ( V_16 , V_5 ) )
goto V_25;
if ( ! F_31 ( V_16 , type , V_21 , V_4 ) )
goto V_25;
if ( ( V_12 != NULL ) && ( * V_12 == NULL ) )
* V_12 = V_16 ;
return ( V_16 ) ;
V_25:
if ( ( V_12 == NULL ) || ( V_16 != * V_12 ) )
F_18 ( V_16 ) ;
return ( NULL ) ;
}
int F_30 ( T_4 * V_12 , T_2 * V_5 )
{
if ( ( V_12 == NULL ) || ( V_5 == NULL ) ) {
F_25 ( V_33 ,
V_34 ) ;
return ( 0 ) ;
}
F_28 ( V_12 -> V_14 ) ;
V_12 -> V_14 = F_32 ( V_5 ) ;
return ( ( V_12 -> V_14 == NULL ) ? 0 : 1 ) ;
}
int F_31 ( T_4 * V_12 , int type ,
const unsigned char * V_21 , int V_4 )
{
int V_6 ;
if ( ( V_12 == NULL ) || ( ( V_21 == NULL ) && ( V_4 != 0 ) ) )
return ( 0 ) ;
if ( ( type > 0 ) && ( type & V_35 ) )
return F_33 ( & V_12 -> V_36 , V_21 ,
V_4 , type ,
F_34 ( V_12 -> V_14 ) ) ? 1 : 0 ;
if ( V_4 < 0 )
V_4 = strlen ( ( const char * ) V_21 ) ;
V_6 = F_35 ( V_12 -> V_36 , V_21 , V_4 ) ;
if ( ! V_6 )
return ( 0 ) ;
if ( type != V_37 ) {
if ( type == V_38 )
V_12 -> V_36 -> type = F_36 ( V_21 , V_4 ) ;
else
V_12 -> V_36 -> type = type ;
}
return ( 1 ) ;
}
T_2 * F_37 ( T_4 * V_12 )
{
if ( V_12 == NULL )
return ( NULL ) ;
return ( V_12 -> V_14 ) ;
}
T_3 * F_5 ( T_4 * V_12 )
{
if ( V_12 == NULL )
return ( NULL ) ;
return ( V_12 -> V_36 ) ;
}
