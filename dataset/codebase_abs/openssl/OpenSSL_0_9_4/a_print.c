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
#ifndef F_14
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
#else
if ( ! isalnum ( V_6 ) && ( V_6 != ' ' ) &&
strchr ( L_1 , V_6 ) == NULL )
V_7 = 1 ;
if ( V_10 [ V_6 ] & 0x80 )
V_8 = 1 ;
#endif
}
if ( V_8 ) return ( V_11 ) ;
if ( V_7 ) return ( V_12 ) ;
return ( V_9 ) ;
}
int F_15 ( T_5 * V_4 )
{
int V_13 ;
unsigned char * V_14 ;
if ( V_4 -> type != V_15 ) return ( 0 ) ;
if ( ( V_4 -> V_16 % 4 ) != 0 ) return ( 0 ) ;
V_14 = V_4 -> V_17 ;
for ( V_13 = 0 ; V_13 < V_4 -> V_16 ; V_13 += 4 )
{
if ( ( V_14 [ 0 ] != '\0' ) || ( V_14 [ 1 ] != '\0' ) || ( V_14 [ 2 ] != '\0' ) )
break;
else
V_14 += 4 ;
}
if ( V_13 < V_4 -> V_16 ) return ( 0 ) ;
V_14 = V_4 -> V_17 ;
for ( V_13 = 3 ; V_13 < V_4 -> V_16 ; V_13 += 4 )
{
* ( V_14 ++ ) = V_4 -> V_17 [ V_13 ] ;
}
* ( V_14 ) = '\0' ;
V_4 -> V_16 /= 4 ;
V_4 -> type = F_13 ( V_4 -> V_17 , V_4 -> V_16 ) ;
return ( 1 ) ;
}
int F_16 ( T_4 * V_1 , unsigned char * * V_2 )
{ return ( F_17 ( V_1 , V_2 ) ) ; }
T_4 * F_18 ( T_4 * * V_1 , unsigned char * * V_2 ,
long V_3 )
{ return ( F_19 ( V_1 , V_2 , V_3 ) ) ; }
int F_20 ( T_4 * V_1 , unsigned char * * V_2 )
{ return ( F_21 ( V_1 , V_2 ) ) ; }
T_4 * F_22 ( T_4 * * V_1 , unsigned char * * V_2 ,
long V_3 )
{ return ( F_23 ( V_1 , V_2 , V_3 ) ) ; }
