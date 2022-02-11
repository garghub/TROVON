int F_1 ( unsigned char * V_1 , int V_2 ,
unsigned char * V_3 , int V_4 )
{
int V_5 ;
unsigned char * V_6 ;
if ( V_4 > ( V_2 - 11 ) )
{
F_2 ( V_7 , V_8 ) ;
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
unsigned char * V_3 , int V_4 , int V_9 )
{
int V_10 , V_5 ;
unsigned char * V_6 ;
V_6 = V_3 ;
if ( ( V_9 != ( V_4 + 1 ) ) || ( * ( V_6 ++ ) != 01 ) )
{
F_2 ( V_11 , V_12 ) ;
return ( - 1 ) ;
}
V_5 = V_4 - 1 ;
for ( V_10 = 0 ; V_10 < V_5 ; V_10 ++ )
{
if ( * V_6 != 0xff )
{
if ( * V_6 == 0 )
{ V_6 ++ ; break; }
else {
F_2 ( V_11 , V_13 ) ;
return ( - 1 ) ;
}
}
V_6 ++ ;
}
if ( V_10 == V_5 )
{
F_2 ( V_11 , V_14 ) ;
return ( - 1 ) ;
}
if ( V_10 < 8 )
{
F_2 ( V_11 , V_15 ) ;
return ( - 1 ) ;
}
V_10 ++ ;
V_5 -= V_10 ;
if ( V_5 > V_2 )
{
F_2 ( V_11 , V_16 ) ;
return ( - 1 ) ;
}
memcpy ( V_1 , V_6 , ( unsigned int ) V_5 ) ;
return ( V_5 ) ;
}
int F_4 ( unsigned char * V_1 , int V_2 ,
unsigned char * V_3 , int V_4 )
{
int V_10 , V_5 ;
unsigned char * V_6 ;
if ( V_4 > ( V_2 - 11 ) )
{
F_2 ( V_17 , V_8 ) ;
return ( 0 ) ;
}
V_6 = ( unsigned char * ) V_1 ;
* ( V_6 ++ ) = 0 ;
* ( V_6 ++ ) = 2 ;
V_5 = V_2 - 3 - V_4 ;
if ( F_5 ( V_6 , V_5 ) <= 0 )
return ( 0 ) ;
for ( V_10 = 0 ; V_10 < V_5 ; V_10 ++ )
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
unsigned char * V_3 , int V_4 , int V_9 )
{
int V_10 , V_5 ;
unsigned char * V_6 ;
V_6 = V_3 ;
if ( ( V_9 != ( V_4 + 1 ) ) || ( * ( V_6 ++ ) != 02 ) )
{
F_2 ( V_18 , V_19 ) ;
return ( - 1 ) ;
}
#ifdef F_7
return ( V_9 - 11 ) ;
#endif
V_5 = V_4 - 1 ;
for ( V_10 = 0 ; V_10 < V_5 ; V_10 ++ )
if ( * ( V_6 ++ ) == 0 ) break;
if ( V_10 == V_5 )
{
F_2 ( V_18 , V_14 ) ;
return ( - 1 ) ;
}
if ( V_10 < 8 )
{
F_2 ( V_18 , V_15 ) ;
return ( - 1 ) ;
}
V_10 ++ ;
V_5 -= V_10 ;
if ( V_5 > V_2 )
{
F_2 ( V_18 , V_16 ) ;
return ( - 1 ) ;
}
memcpy ( V_1 , V_6 , ( unsigned int ) V_5 ) ;
return ( V_5 ) ;
}
