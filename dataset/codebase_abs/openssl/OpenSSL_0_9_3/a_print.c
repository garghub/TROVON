int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{ return ( F_2 ( V_1 , V_2 ) ) ; }
T_1 * F_3 ( T_1 * * V_1 , unsigned char * * V_2 ,
long V_3 )
{ return ( F_4 ( V_1 , V_2 , V_3 ) ) ; }
T_2 * F_5 ( T_2 * * V_1 , unsigned char * * V_2 ,
long V_3 )
{ return ( F_6 ( V_1 , V_2 , V_3 ) ) ; }
T_3 * F_7 ( T_3 * * V_1 ,
unsigned char * * V_2 , long V_3 )
{ return ( F_8 ( V_1 , V_2 ,
V_3 ) ) ; }
int F_9 ( T_4 * V_1 , unsigned char * * V_2 )
{ return ( F_10 ( V_1 , V_2 ) ) ; }
T_4 * F_11 ( T_4 * * V_1 , unsigned char * * V_2 ,
long V_3 )
{ return ( F_12 ( V_1 , V_2 , V_3 ) ) ; }
int F_13 ( unsigned char * V_4 , int V_5 )
{
int V_6 ;
int V_7 = 0 ;
int V_8 = 0 ;
if ( V_5 <= 0 ) V_5 = - 1 ;
if ( V_4 == NULL ) return ( V_9 ) ;
while ( ( * V_4 ) && ( V_5 -- != 0 ) )
{
V_6 = * ( V_4 ++ ) ;
if ( ! ( ( ( V_6 >= 'a' ) && ( V_6 <= 'z' ) ) ||
( ( V_6 >= 'A' ) && ( V_6 <= 'Z' ) ) ||
( V_6 == ' ' ) ||
( ( V_6 >= '0' ) && ( V_6 <= '9' ) ) ||
( V_6 == ' ' ) || ( V_6 == '\'' ) ||
( V_6 == '(' ) || ( V_6 == ')' ) ||
( V_6 == '+' ) || ( V_6 == ',' ) ||
( V_6 == '-' ) || ( V_6 == '.' ) ||
( V_6 == '/' ) || ( V_6 == ':' ) ||
( V_6 == '=' ) || ( V_6 == '?' ) ) )
V_7 = 1 ;
if ( V_6 & 0x80 )
V_8 = 1 ;
}
if ( V_8 ) return ( V_10 ) ;
if ( V_7 ) return ( V_11 ) ;
return ( V_9 ) ;
}
int F_14 ( T_5 * V_4 )
{
int V_12 ;
unsigned char * V_13 ;
if ( V_4 -> type != V_14 ) return ( 0 ) ;
if ( ( V_4 -> V_15 % 4 ) != 0 ) return ( 0 ) ;
V_13 = V_4 -> V_16 ;
for ( V_12 = 0 ; V_12 < V_4 -> V_15 ; V_12 += 4 )
{
if ( ( V_13 [ 0 ] != '\0' ) || ( V_13 [ 1 ] != '\0' ) || ( V_13 [ 2 ] != '\0' ) )
break;
else
V_13 += 4 ;
}
if ( V_12 < V_4 -> V_15 ) return ( 0 ) ;
V_13 = V_4 -> V_16 ;
for ( V_12 = 3 ; V_12 < V_4 -> V_15 ; V_12 += 4 )
{
* ( V_13 ++ ) = V_4 -> V_16 [ V_12 ] ;
}
* ( V_13 ) = '\0' ;
V_4 -> V_15 /= 4 ;
V_4 -> type = F_13 ( V_4 -> V_16 , V_4 -> V_15 ) ;
return ( 1 ) ;
}
int F_15 ( T_4 * V_1 , unsigned char * * V_2 )
{ return ( F_16 ( V_1 , V_2 ) ) ; }
T_4 * F_17 ( T_4 * * V_1 , unsigned char * * V_2 ,
long V_3 )
{ return ( F_18 ( V_1 , V_2 , V_3 ) ) ; }
int F_19 ( T_4 * V_1 , unsigned char * * V_2 )
{ return ( F_20 ( V_1 , V_2 ) ) ; }
T_4 * F_21 ( T_4 * * V_1 , unsigned char * * V_2 ,
long V_3 )
{ return ( F_22 ( V_1 , V_2 , V_3 ) ) ; }
