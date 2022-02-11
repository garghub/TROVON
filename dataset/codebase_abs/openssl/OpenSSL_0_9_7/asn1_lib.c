int F_1 ( unsigned char * * V_1 , long V_2 )
{
if ( V_2 <= 0 )
return ( 1 ) ;
else if ( ( V_2 >= 2 ) && ( ( * V_1 ) [ 0 ] == 0 ) && ( ( * V_1 ) [ 1 ] == 0 ) )
{
( * V_1 ) += 2 ;
return ( 1 ) ;
}
return ( 0 ) ;
}
int F_2 ( unsigned char * * V_3 , long * V_4 , int * V_5 , int * V_6 ,
long V_7 )
{
int V_8 , V_9 ;
long V_10 ;
unsigned char * V_1 = * V_3 ;
int V_11 , V_12 , V_13 ;
long V_14 = V_7 ;
if ( ! V_14 ) goto V_15;
V_9 = ( * V_1 & V_16 ) ;
V_12 = ( * V_1 & V_17 ) ;
V_8 = * V_1 & V_18 ;
if ( V_8 == V_18 )
{
V_1 ++ ;
if ( -- V_14 == 0 ) goto V_15;
V_10 = 0 ;
while ( * V_1 & 0x80 )
{
V_10 <<= 7L ;
V_10 |= * ( V_1 ++ ) & 0x7f ;
if ( -- V_14 == 0 ) goto V_15;
}
V_10 <<= 7L ;
V_10 |= * ( V_1 ++ ) & 0x7f ;
V_11 = ( int ) V_10 ;
}
else
{
V_11 = V_8 ;
V_1 ++ ;
if ( -- V_14 == 0 ) goto V_15;
}
* V_5 = V_11 ;
* V_6 = V_12 ;
if ( ! F_3 ( & V_1 , & V_13 , V_4 , ( int ) V_14 ) ) goto V_15;
#if 0
fprintf(stderr,"p=%d + *plength=%ld > omax=%ld + *pp=%d (%d > %d)\n",
(int)p,*plength,omax,(int)*pp,(int)(p+ *plength),
(int)(omax+ *pp));
#endif
if ( * V_4 > ( V_7 - ( V_1 - * V_3 ) ) )
{
F_4 ( V_19 , V_20 ) ;
V_9 |= 0x80 ;
}
* V_3 = V_1 ;
return ( V_9 | V_13 ) ;
V_15:
F_4 ( V_19 , V_21 ) ;
return ( 0x80 ) ;
}
static int F_3 ( unsigned char * * V_3 , int * V_13 , long * V_22 , int V_14 )
{
unsigned char * V_1 = * V_3 ;
unsigned long V_9 = 0 ;
int V_8 ;
if ( V_14 -- < 1 ) return ( 0 ) ;
if ( * V_1 == 0x80 )
{
* V_13 = 1 ;
V_9 = 0 ;
V_1 ++ ;
}
else
{
* V_13 = 0 ;
V_8 = * V_1 & 0x7f ;
if ( * ( V_1 ++ ) & 0x80 )
{
if ( V_8 > sizeof( long ) )
return 0 ;
if ( V_14 -- == 0 ) return ( 0 ) ;
while ( V_8 -- > 0 )
{
V_9 <<= 8L ;
V_9 |= * ( V_1 ++ ) ;
if ( V_14 -- == 0 ) return ( 0 ) ;
}
}
else
V_9 = V_8 ;
}
if ( V_9 > V_23 )
return 0 ;
* V_3 = V_1 ;
* V_22 = ( long ) V_9 ;
return ( 1 ) ;
}
void F_5 ( unsigned char * * V_3 , int V_24 , int V_25 , int V_11 ,
int V_12 )
{
unsigned char * V_1 = * V_3 ;
int V_8 , V_26 ;
V_8 = ( V_24 ) ? V_16 : 0 ;
V_8 |= ( V_12 & V_17 ) ;
if ( V_11 < 31 )
* ( V_1 ++ ) = V_8 | ( V_11 & V_18 ) ;
else
{
* ( V_1 ++ ) = V_8 | V_18 ;
for( V_8 = 0 , V_26 = V_11 ; V_26 > 0 ; V_8 ++ ) V_26 >>= 7 ;
V_26 = V_8 ;
while( V_8 -- > 0 )
{
V_1 [ V_8 ] = V_11 & 0x7f ;
if( V_8 != ( V_26 - 1 ) ) V_1 [ V_8 ] |= 0x80 ;
V_11 >>= 7 ;
}
V_1 += V_26 ;
}
if ( ( V_24 == 2 ) && ( V_25 == 0 ) )
* ( V_1 ++ ) = 0x80 ;
else
F_6 ( & V_1 , V_25 ) ;
* V_3 = V_1 ;
}
static void F_6 ( unsigned char * * V_3 , int V_25 )
{
unsigned char * V_1 = * V_3 ;
int V_8 , V_10 ;
if ( V_25 <= 127 )
* ( V_1 ++ ) = ( unsigned char ) V_25 ;
else
{
V_10 = V_25 ;
for ( V_8 = 0 ; V_10 > 0 ; V_8 ++ )
V_10 >>= 8 ;
* ( V_1 ++ ) = V_8 | 0x80 ;
V_10 = V_8 ;
while ( V_8 -- > 0 )
{
V_1 [ V_8 ] = V_25 & 0xff ;
V_25 >>= 8 ;
}
V_1 += V_10 ;
}
* V_3 = V_1 ;
}
int F_7 ( int V_24 , int V_25 , int V_11 )
{
int V_9 ;
V_9 = V_25 ;
V_9 ++ ;
if ( V_11 >= 31 )
{
while ( V_11 > 0 )
{
V_11 >>= 7 ;
V_9 ++ ;
}
}
if ( ( V_25 == 0 ) && ( V_24 == 2 ) )
V_9 += 2 ;
V_9 ++ ;
if ( V_25 > 127 )
{
while ( V_25 > 0 )
{
V_25 >>= 8 ;
V_9 ++ ;
}
}
return ( V_9 ) ;
}
int F_8 ( T_1 * V_27 )
{
if ( ( V_27 -> V_13 == ( 1 | V_16 ) ) && ( ! V_27 -> V_28 ) )
{
if ( ! F_1 ( & V_27 -> V_1 , V_27 -> V_29 ) )
{
V_27 -> error = V_30 ;
return ( 0 ) ;
}
}
if ( ( ( V_27 -> V_29 != 0 ) && ! ( V_27 -> V_13 & 1 ) ) ||
( ( V_27 -> V_29 < 0 ) && ( V_27 -> V_13 & 1 ) ) )
{
V_27 -> error = V_31 ;
return ( 0 ) ;
}
return ( 1 ) ;
}
int F_9 ( T_1 * V_27 , long * V_25 )
{
unsigned char * V_32 ;
V_32 = V_27 -> V_1 ;
V_27 -> V_13 = F_2 ( & ( V_27 -> V_1 ) , & ( V_27 -> V_29 ) , & ( V_27 -> V_11 ) , & ( V_27 -> V_12 ) ,
* V_25 ) ;
if ( V_27 -> V_13 & 0x80 )
{
V_27 -> error = V_33 ;
return ( 0 ) ;
}
if ( V_27 -> V_11 != V_34 )
{
V_27 -> error = V_35 ;
return ( 0 ) ;
}
( * V_25 ) -= ( V_27 -> V_1 - V_32 ) ;
if ( V_27 -> V_14 && ( * V_25 < 0 ) )
{
V_27 -> error = V_31 ;
return ( 0 ) ;
}
if ( V_27 -> V_13 == ( 1 | V_16 ) )
V_27 -> V_29 = * V_25 + * ( V_27 -> V_3 ) - V_27 -> V_1 ;
V_27 -> V_28 = 0 ;
return ( 1 ) ;
}
T_2 * F_10 ( T_2 * V_36 )
{
T_2 * V_9 ;
if ( V_36 == NULL ) return ( NULL ) ;
if ( ( V_9 = F_11 ( V_36 -> type ) ) == NULL )
return ( NULL ) ;
if ( ! F_12 ( V_9 , V_36 -> V_37 , V_36 -> V_25 ) )
{
F_13 ( V_9 ) ;
return ( NULL ) ;
}
V_9 -> V_38 = V_36 -> V_38 ;
return ( V_9 ) ;
}
int F_12 ( T_2 * V_36 , const void * V_39 , int V_2 )
{
unsigned char * V_27 ;
const char * V_37 = V_39 ;
if ( V_2 < 0 )
{
if ( V_37 == NULL )
return ( 0 ) ;
else
V_2 = strlen ( V_37 ) ;
}
if ( ( V_36 -> V_25 < V_2 ) || ( V_36 -> V_37 == NULL ) )
{
V_27 = V_36 -> V_37 ;
if ( V_27 == NULL )
V_36 -> V_37 = F_14 ( V_2 + 1 ) ;
else
V_36 -> V_37 = F_15 ( V_27 , V_2 + 1 ) ;
if ( V_36 -> V_37 == NULL )
{
V_36 -> V_37 = V_27 ;
return ( 0 ) ;
}
}
V_36 -> V_25 = V_2 ;
if ( V_37 != NULL )
{
memcpy ( V_36 -> V_37 , V_37 , V_2 ) ;
V_36 -> V_37 [ V_2 ] = '\0' ;
}
return ( 1 ) ;
}
T_2 * F_16 ( void )
{
return ( F_11 ( V_40 ) ) ;
}
T_2 * F_11 ( int type )
{
T_2 * V_9 ;
V_9 = ( T_2 * ) F_14 ( sizeof( T_2 ) ) ;
if ( V_9 == NULL )
{
F_4 ( V_41 , V_42 ) ;
return ( NULL ) ;
}
V_9 -> V_25 = 0 ;
V_9 -> type = type ;
V_9 -> V_37 = NULL ;
V_9 -> V_38 = 0 ;
return ( V_9 ) ;
}
void F_13 ( T_2 * V_43 )
{
if ( V_43 == NULL ) return;
if ( V_43 -> V_37 != NULL ) F_17 ( V_43 -> V_37 ) ;
F_17 ( V_43 ) ;
}
int F_18 ( T_2 * V_43 , T_2 * V_44 )
{
int V_8 ;
V_8 = ( V_43 -> V_25 - V_44 -> V_25 ) ;
if ( V_8 == 0 )
{
V_8 = memcmp ( V_43 -> V_37 , V_44 -> V_37 , V_43 -> V_25 ) ;
if ( V_8 == 0 )
return ( V_43 -> type - V_44 -> type ) ;
else
return ( V_8 ) ;
}
else
return ( V_8 ) ;
}
void F_19 ( unsigned char * V_45 , int V_46 )
{
char V_47 [ F_20 ( V_45 ) + 1 ] , V_48 [ F_20 ( V_46 ) + 1 ] ;
sprintf ( V_47 , L_1 , ( unsigned long ) V_45 ) ;
sprintf ( V_48 , L_2 , V_46 ) ;
F_21 ( 4 , L_3 , V_47 , L_4 , V_48 ) ;
}
int F_22 ( T_2 * V_49 )
{ return F_23 ( V_49 ) ; }
void F_24 ( T_2 * V_49 , int V_2 )
{ F_25 ( V_49 , V_2 ) ; return; }
int F_26 ( T_2 * V_49 )
{ return F_27 ( V_49 ) ; }
unsigned char * F_28 ( T_2 * V_49 )
{ return F_29 ( V_49 ) ; }
