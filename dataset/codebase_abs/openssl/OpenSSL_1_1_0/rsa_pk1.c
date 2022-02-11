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
if ( V_10 < 11 )
return - 1 ;
if ( V_10 == V_4 ) {
if ( ( * V_6 ++ ) != 0x00 ) {
F_2 ( V_12 ,
V_13 ) ;
return - 1 ;
}
V_4 -- ;
}
if ( ( V_10 != ( V_4 + 1 ) ) || ( * ( V_6 ++ ) != 0x01 ) ) {
F_2 ( V_12 ,
V_14 ) ;
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
V_15 ) ;
return ( - 1 ) ;
}
}
V_6 ++ ;
}
if ( V_11 == V_5 ) {
F_2 ( V_12 ,
V_16 ) ;
return ( - 1 ) ;
}
if ( V_11 < 8 ) {
F_2 ( V_12 ,
V_17 ) ;
return ( - 1 ) ;
}
V_11 ++ ;
V_5 -= V_11 ;
if ( V_5 > V_2 ) {
F_2 ( V_12 , V_18 ) ;
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
F_2 ( V_19 ,
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
unsigned char * V_20 = NULL ;
unsigned int V_21 , V_22 ;
int V_23 = 0 , V_24 , V_25 = - 1 ;
if ( V_2 < 0 || V_4 < 0 )
return - 1 ;
if ( V_4 > V_10 )
goto V_26;
if ( V_10 < 11 )
goto V_26;
V_20 = F_7 ( V_10 ) ;
if ( V_20 == NULL ) {
F_2 ( V_27 , V_28 ) ;
return - 1 ;
}
memcpy ( V_20 + V_10 - V_4 , V_3 , V_4 ) ;
V_21 = F_8 ( V_20 [ 0 ] ) ;
V_21 &= F_9 ( V_20 [ 1 ] , 2 ) ;
V_22 = 0 ;
for ( V_11 = 2 ; V_11 < V_10 ; V_11 ++ ) {
unsigned int V_29 = F_8 ( V_20 [ V_11 ] ) ;
V_23 =
F_10 ( ~ V_22 & V_29 , V_11 ,
V_23 ) ;
V_22 |= V_29 ;
}
V_21 &= F_11 ( ( unsigned int ) ( V_23 ) , 2 + 8 ) ;
V_24 = V_23 + 1 ;
V_25 = V_10 - V_24 ;
V_21 &= F_11 ( ( unsigned int ) ( V_2 ) , ( unsigned int ) ( V_25 ) ) ;
if ( ! V_21 ) {
V_25 = - 1 ;
goto V_26;
}
memcpy ( V_1 , V_20 + V_24 , V_25 ) ;
V_26:
F_12 ( V_20 ) ;
if ( V_25 == - 1 )
F_2 ( V_27 ,
V_30 ) ;
return V_25 ;
}
