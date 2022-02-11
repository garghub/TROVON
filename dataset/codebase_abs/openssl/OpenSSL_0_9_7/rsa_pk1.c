int F_1 ( unsigned char * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 )
{
int V_5 ;
unsigned char * V_6 ;
if ( V_4 > ( V_2 - V_7 ) )
{
F_2 ( V_8 , V_9 ) ;
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
const unsigned char * V_3 , int V_4 , int V_10 )
{
int V_11 , V_5 ;
const unsigned char * V_6 ;
V_6 = V_3 ;
if ( ( V_10 != ( V_4 + 1 ) ) || ( * ( V_6 ++ ) != 01 ) )
{
F_2 ( V_12 , V_13 ) ;
return ( - 1 ) ;
}
V_5 = V_4 - 1 ;
for ( V_11 = 0 ; V_11 < V_5 ; V_11 ++ )
{
if ( * V_6 != 0xff )
{
if ( * V_6 == 0 )
{ V_6 ++ ; break; }
else {
F_2 ( V_12 , V_14 ) ;
return ( - 1 ) ;
}
}
V_6 ++ ;
}
if ( V_11 == V_5 )
{
F_2 ( V_12 , V_15 ) ;
return ( - 1 ) ;
}
if ( V_11 < 8 )
{
F_2 ( V_12 , V_16 ) ;
return ( - 1 ) ;
}
V_11 ++ ;
V_5 -= V_11 ;
if ( V_5 > V_2 )
{
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
if ( V_4 > ( V_2 - 11 ) )
{
F_2 ( V_18 , V_9 ) ;
return ( 0 ) ;
}
V_6 = ( unsigned char * ) V_1 ;
* ( V_6 ++ ) = 0 ;
* ( V_6 ++ ) = 2 ;
V_5 = V_2 - 3 - V_4 ;
if ( F_5 ( V_6 , V_5 ) <= 0 )
return ( 0 ) ;
for ( V_11 = 0 ; V_11 < V_5 ; V_11 ++ )
{
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
const unsigned char * V_3 , int V_4 , int V_10 )
{
int V_11 , V_5 ;
const unsigned char * V_6 ;
V_6 = V_3 ;
if ( ( V_10 != ( V_4 + 1 ) ) || ( * ( V_6 ++ ) != 02 ) )
{
F_2 ( V_19 , V_20 ) ;
return ( - 1 ) ;
}
#ifdef F_7
return ( V_10 - 11 ) ;
#endif
V_5 = V_4 - 1 ;
for ( V_11 = 0 ; V_11 < V_5 ; V_11 ++ )
if ( * ( V_6 ++ ) == 0 ) break;
if ( V_11 == V_5 )
{
F_2 ( V_19 , V_15 ) ;
return ( - 1 ) ;
}
if ( V_11 < 8 )
{
F_2 ( V_19 , V_16 ) ;
return ( - 1 ) ;
}
V_11 ++ ;
V_5 -= V_11 ;
if ( V_5 > V_2 )
{
F_2 ( V_19 , V_17 ) ;
return ( - 1 ) ;
}
memcpy ( V_1 , V_6 , ( unsigned int ) V_5 ) ;
return ( V_5 ) ;
}
