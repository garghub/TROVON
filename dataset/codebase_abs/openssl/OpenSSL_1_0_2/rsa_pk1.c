int F_1 ( unsigned char * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 )
{
int V_5 ;
unsigned char * V_6 ;
if ( V_4 > ( V_2 - V_7 ) ) {
F_2 ( V_8 ,
V_9 ) ;
return ( 0 ) ;
}
V_6 = ( unsigned char * ) V_1 ;
* ( V_6 ++ ) = 0 ;
* ( V_6 ++ ) = 1 ;
V_5 = V_2 - 3 - V_4 ;
memset ( V_6 , 0xff , V_5 ) ;
V_6 += V_5 ;
* ( V_6 ++ ) = '\0' ;
memcpy ( V_6 , V_3 , ( unsigned int ) V_4 ) ;
return ( 1 ) ;
}
int F_3 ( unsigned char * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 ,
int V_10 )
{
int V_11 , V_5 ;
const unsigned char * V_6 ;
V_6 = V_3 ;
if ( ( V_10 != ( V_4 + 1 ) ) || ( * ( V_6 ++ ) != 01 ) ) {
F_2 ( V_12 ,
V_13 ) ;
return ( - 1 ) ;
}
V_5 = V_4 - 1 ;
for ( V_11 = 0 ; V_11 < V_5 ; V_11 ++ ) {
if ( * V_6 != 0xff ) {
if ( * V_6 == 0 ) {
V_6 ++ ;
break;
} else {
F_2 ( V_12 ,
V_14 ) ;
return ( - 1 ) ;
}
}
V_6 ++ ;
}
if ( V_11 == V_5 ) {
F_2 ( V_12 ,
V_15 ) ;
return ( - 1 ) ;
}
if ( V_11 < 8 ) {
F_2 ( V_12 ,
V_16 ) ;
return ( - 1 ) ;
}
V_11 ++ ;
V_5 -= V_11 ;
if ( V_5 > V_2 ) {
F_2 ( V_12 , V_17 ) ;
return ( - 1 ) ;
}
memcpy ( V_1 , V_6 , ( unsigned int ) V_5 ) ;
return ( V_5 ) ;
}
int F_4 ( unsigned char * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 )
{
int V_11 , V_5 ;
unsigned char * V_6 ;
if ( V_4 > ( V_2 - 11 ) ) {
F_2 ( V_18 ,
V_9 ) ;
return ( 0 ) ;
}
V_6 = ( unsigned char * ) V_1 ;
* ( V_6 ++ ) = 0 ;
* ( V_6 ++ ) = 2 ;
V_5 = V_2 - 3 - V_4 ;
if ( F_5 ( V_6 , V_5 ) <= 0 )
return ( 0 ) ;
for ( V_11 = 0 ; V_11 < V_5 ; V_11 ++ ) {
if ( * V_6 == '\0' )
do {
if ( F_5 ( V_6 , 1 ) <= 0 )
return ( 0 ) ;
} while ( * V_6 == '\0' );
V_6 ++ ;
}
* ( V_6 ++ ) = '\0' ;
memcpy ( V_6 , V_3 , ( unsigned int ) V_4 ) ;
return ( 1 ) ;
}
int F_6 ( unsigned char * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 ,
int V_10 )
{
int V_11 ;
unsigned char * V_19 = NULL ;
unsigned int V_20 , V_21 ;
int V_22 = 0 , V_23 , V_24 = - 1 ;
if ( V_2 < 0 || V_4 < 0 )
return - 1 ;
if ( V_4 > V_10 )
goto V_25;
if ( V_10 < 11 )
goto V_25;
V_19 = F_7 ( V_10 ) ;
if ( V_19 == NULL ) {
F_2 ( V_26 , V_27 ) ;
return - 1 ;
}
memset ( V_19 , 0 , V_10 ) ;
memcpy ( V_19 + V_10 - V_4 , V_3 , V_4 ) ;
V_20 = F_8 ( V_19 [ 0 ] ) ;
V_20 &= F_9 ( V_19 [ 1 ] , 2 ) ;
V_21 = 0 ;
for ( V_11 = 2 ; V_11 < V_10 ; V_11 ++ ) {
unsigned int V_28 = F_8 ( V_19 [ V_11 ] ) ;
V_22 =
F_10 ( ~ V_21 & V_28 , V_11 ,
V_22 ) ;
V_21 |= V_28 ;
}
V_20 &= F_11 ( ( unsigned int ) ( V_22 ) , 2 + 8 ) ;
V_23 = V_22 + 1 ;
V_24 = V_10 - V_23 ;
V_20 &= F_11 ( ( unsigned int ) ( V_2 ) , ( unsigned int ) ( V_24 ) ) ;
if ( ! V_20 ) {
V_24 = - 1 ;
goto V_25;
}
memcpy ( V_1 , V_19 + V_23 , V_24 ) ;
V_25:
if ( V_19 != NULL )
F_12 ( V_19 ) ;
if ( V_24 == - 1 )
F_2 ( V_26 ,
V_29 ) ;
return V_24 ;
}
