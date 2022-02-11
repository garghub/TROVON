T_1 * F_1 ( void )
{ return F_2 () ; }
void F_3 ( T_1 * V_1 )
{ F_4 ( V_1 ) ; }
int F_5 ( T_1 * V_2 , unsigned char * * V_3 )
{ return ( F_6 ( V_2 , V_3 ) ) ; }
T_1 * F_7 ( T_1 * * V_2 , unsigned char * * V_3 ,
long V_4 )
{ return ( F_8 ( V_2 , V_3 , V_4 ) ) ; }
T_2 * F_9 ( void )
{ return F_10 () ; }
void F_11 ( T_2 * V_1 )
{ F_12 ( V_1 ) ; }
T_2 * F_13 ( T_2 * * V_2 , unsigned char * * V_3 ,
long V_4 )
{ return ( F_14 ( V_2 , V_3 , V_4 ) ) ; }
T_3 * F_15 ( void )
{ return F_16 () ; }
void F_17 ( T_3 * V_1 )
{ F_18 ( V_1 ) ; }
T_3 * F_19 ( T_3 * * V_2 ,
unsigned char * * V_3 , long V_4 )
{ return ( F_20 ( V_2 , V_3 ,
V_4 ) ) ; }
int F_21 ( T_3 * V_2 , unsigned char * * V_3 )
{ return ( F_22 ( V_2 , V_3 ) ) ; }
int F_23 ( T_4 * V_2 , unsigned char * * V_3 )
{ return ( F_24 ( V_2 , V_3 ) ) ; }
T_4 * F_25 ( T_4 * * V_2 , unsigned char * * V_3 ,
long V_4 )
{ return ( F_26 ( V_2 , V_3 , V_4 ) ) ; }
int F_27 ( unsigned char * V_5 , int V_6 )
{
int V_7 ;
int V_8 = 0 ;
int V_9 = 0 ;
if ( V_6 <= 0 ) V_6 = - 1 ;
if ( V_5 == NULL ) return ( V_10 ) ;
while ( ( * V_5 ) && ( V_6 -- != 0 ) )
{
V_7 = * ( V_5 ++ ) ;
#ifndef F_28
if ( ! ( ( ( V_7 >= 'a' ) && ( V_7 <= 'z' ) ) ||
( ( V_7 >= 'A' ) && ( V_7 <= 'Z' ) ) ||
( V_7 == ' ' ) ||
( ( V_7 >= '0' ) && ( V_7 <= '9' ) ) ||
( V_7 == ' ' ) || ( V_7 == '\'' ) ||
( V_7 == '(' ) || ( V_7 == ')' ) ||
( V_7 == '+' ) || ( V_7 == ',' ) ||
( V_7 == '-' ) || ( V_7 == '.' ) ||
( V_7 == '/' ) || ( V_7 == ':' ) ||
( V_7 == '=' ) || ( V_7 == '?' ) ) )
V_8 = 1 ;
if ( V_7 & 0x80 )
V_9 = 1 ;
#else
if ( ! isalnum ( V_7 ) && ( V_7 != ' ' ) &&
strchr ( L_1 , V_7 ) == NULL )
V_8 = 1 ;
if ( V_11 [ V_7 ] & 0x80 )
V_9 = 1 ;
#endif
}
if ( V_9 ) return ( V_12 ) ;
if ( V_8 ) return ( V_13 ) ;
return ( V_10 ) ;
}
int F_29 ( T_5 * V_5 )
{
int V_14 ;
unsigned char * V_15 ;
if ( V_5 -> type != V_16 ) return ( 0 ) ;
if ( ( V_5 -> V_17 % 4 ) != 0 ) return ( 0 ) ;
V_15 = V_5 -> V_18 ;
for ( V_14 = 0 ; V_14 < V_5 -> V_17 ; V_14 += 4 )
{
if ( ( V_15 [ 0 ] != '\0' ) || ( V_15 [ 1 ] != '\0' ) || ( V_15 [ 2 ] != '\0' ) )
break;
else
V_15 += 4 ;
}
if ( V_14 < V_5 -> V_17 ) return ( 0 ) ;
V_15 = V_5 -> V_18 ;
for ( V_14 = 3 ; V_14 < V_5 -> V_17 ; V_14 += 4 )
{
* ( V_15 ++ ) = V_5 -> V_18 [ V_14 ] ;
}
* ( V_15 ) = '\0' ;
V_5 -> V_17 /= 4 ;
V_5 -> type = F_27 ( V_5 -> V_18 , V_5 -> V_17 ) ;
return ( 1 ) ;
}
T_4 * F_30 ( void )
{ return F_31 () ; }
void F_32 ( T_4 * V_1 )
{ F_33 ( V_1 ) ; }
int F_34 ( T_4 * V_2 , unsigned char * * V_3 )
{ return ( F_35 ( V_2 , V_3 ) ) ; }
T_4 * F_36 ( T_4 * * V_2 , unsigned char * * V_3 ,
long V_4 )
{ return ( F_37 ( V_2 , V_3 , V_4 ) ) ; }
T_4 * F_38 ( void )
{ return F_39 () ; }
void F_40 ( T_4 * V_1 )
{ F_41 ( V_1 ) ; }
int F_42 ( T_4 * V_2 , unsigned char * * V_3 )
{ return ( F_43 ( V_2 , V_3 ) ) ; }
T_4 * F_44 ( T_4 * * V_2 , unsigned char * * V_3 ,
long V_4 )
{ return ( F_45 ( V_2 , V_3 , V_4 ) ) ; }
