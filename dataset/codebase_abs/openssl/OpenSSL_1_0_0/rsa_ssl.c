int F_1 ( unsigned char * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 )
{
int V_5 , V_6 ;
unsigned char * V_7 ;
if ( V_4 > ( V_2 - 11 ) )
{
F_2 ( V_8 , V_9 ) ;
return ( 0 ) ;
}
V_7 = ( unsigned char * ) V_1 ;
* ( V_7 ++ ) = 0 ;
* ( V_7 ++ ) = 2 ;
V_6 = V_2 - 3 - 8 - V_4 ;
if ( F_3 ( V_7 , V_6 ) <= 0 )
return ( 0 ) ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
{
if ( * V_7 == '\0' )
do {
if ( F_3 ( V_7 , 1 ) <= 0 )
return ( 0 ) ;
} while ( * V_7 == '\0' );
V_7 ++ ;
}
memset ( V_7 , 3 , 8 ) ;
V_7 += 8 ;
* ( V_7 ++ ) = '\0' ;
memcpy ( V_7 , V_3 , ( unsigned int ) V_4 ) ;
return ( 1 ) ;
}
int F_4 ( unsigned char * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 , int V_10 )
{
int V_5 , V_6 , V_11 ;
const unsigned char * V_7 ;
V_7 = V_3 ;
if ( V_4 < 10 )
{
F_2 ( V_12 , V_13 ) ;
return ( - 1 ) ;
}
if ( ( V_10 != ( V_4 + 1 ) ) || ( * ( V_7 ++ ) != 02 ) )
{
F_2 ( V_12 , V_14 ) ;
return ( - 1 ) ;
}
V_6 = V_4 - 1 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
if ( * ( V_7 ++ ) == 0 ) break;
if ( ( V_5 == V_6 ) || ( V_5 < 8 ) )
{
F_2 ( V_12 , V_15 ) ;
return ( - 1 ) ;
}
for ( V_11 = - 9 ; V_11 < - 1 ; V_11 ++ )
{
if ( V_7 [ V_11 ] != 0x03 ) break;
}
if ( V_11 == - 1 )
{
F_2 ( V_12 , V_16 ) ;
return ( - 1 ) ;
}
V_5 ++ ;
V_6 -= V_5 ;
if ( V_6 > V_2 )
{
F_2 ( V_12 , V_17 ) ;
return ( - 1 ) ;
}
memcpy ( V_1 , V_7 , ( unsigned int ) V_6 ) ;
return ( V_6 ) ;
}
