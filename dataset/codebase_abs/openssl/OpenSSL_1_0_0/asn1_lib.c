static int F_1 ( const unsigned char * * V_1 , long V_2 )
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
int F_2 ( unsigned char * * V_1 , long V_2 )
{
return F_1 ( ( const unsigned char * * ) V_1 , V_2 ) ;
}
int F_3 ( const unsigned char * * V_1 , long V_2 )
{
return F_1 ( V_1 , V_2 ) ;
}
int F_4 ( const unsigned char * * V_3 , long * V_4 , int * V_5 ,
int * V_6 , long V_7 )
{
int V_8 , V_9 ;
long V_10 ;
const unsigned char * V_1 = * V_3 ;
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
if ( V_10 > ( V_19 >> 7L ) ) goto V_15;
}
V_10 <<= 7L ;
V_10 |= * ( V_1 ++ ) & 0x7f ;
V_11 = ( int ) V_10 ;
if ( -- V_14 == 0 ) goto V_15;
}
else
{
V_11 = V_8 ;
V_1 ++ ;
if ( -- V_14 == 0 ) goto V_15;
}
* V_5 = V_11 ;
* V_6 = V_12 ;
if ( ! F_5 ( & V_1 , & V_13 , V_4 , ( int ) V_14 ) ) goto V_15;
#if 0
fprintf(stderr,"p=%d + *plength=%ld > omax=%ld + *pp=%d (%d > %d)\n",
(int)p,*plength,omax,(int)*pp,(int)(p+ *plength),
(int)(omax+ *pp));
#endif
if ( * V_4 > ( V_7 - ( V_1 - * V_3 ) ) )
{
F_6 ( V_20 , V_21 ) ;
V_9 |= 0x80 ;
}
* V_3 = V_1 ;
return ( V_9 | V_13 ) ;
V_15:
F_6 ( V_20 , V_22 ) ;
return ( 0x80 ) ;
}
static int F_5 ( const unsigned char * * V_3 , int * V_13 , long * V_23 , int V_14 )
{
const unsigned char * V_1 = * V_3 ;
unsigned long V_9 = 0 ;
unsigned int V_8 ;
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
if ( V_9 > V_24 )
return 0 ;
* V_3 = V_1 ;
* V_23 = ( long ) V_9 ;
return ( 1 ) ;
}
void F_7 ( unsigned char * * V_3 , int V_25 , int V_26 , int V_11 ,
int V_12 )
{
unsigned char * V_1 = * V_3 ;
int V_8 , V_27 ;
V_8 = ( V_25 ) ? V_16 : 0 ;
V_8 |= ( V_12 & V_17 ) ;
if ( V_11 < 31 )
* ( V_1 ++ ) = V_8 | ( V_11 & V_18 ) ;
else
{
* ( V_1 ++ ) = V_8 | V_18 ;
for( V_8 = 0 , V_27 = V_11 ; V_27 > 0 ; V_8 ++ ) V_27 >>= 7 ;
V_27 = V_8 ;
while( V_8 -- > 0 )
{
V_1 [ V_8 ] = V_11 & 0x7f ;
if( V_8 != ( V_27 - 1 ) ) V_1 [ V_8 ] |= 0x80 ;
V_11 >>= 7 ;
}
V_1 += V_27 ;
}
if ( V_25 == 2 )
* ( V_1 ++ ) = 0x80 ;
else
F_8 ( & V_1 , V_26 ) ;
* V_3 = V_1 ;
}
int F_9 ( unsigned char * * V_3 )
{
unsigned char * V_1 = * V_3 ;
* V_1 ++ = 0 ;
* V_1 ++ = 0 ;
* V_3 = V_1 ;
return 2 ;
}
static void F_8 ( unsigned char * * V_3 , int V_26 )
{
unsigned char * V_1 = * V_3 ;
int V_8 , V_10 ;
if ( V_26 <= 127 )
* ( V_1 ++ ) = ( unsigned char ) V_26 ;
else
{
V_10 = V_26 ;
for ( V_8 = 0 ; V_10 > 0 ; V_8 ++ )
V_10 >>= 8 ;
* ( V_1 ++ ) = V_8 | 0x80 ;
V_10 = V_8 ;
while ( V_8 -- > 0 )
{
V_1 [ V_8 ] = V_26 & 0xff ;
V_26 >>= 8 ;
}
V_1 += V_10 ;
}
* V_3 = V_1 ;
}
int F_10 ( int V_25 , int V_26 , int V_11 )
{
int V_9 ;
V_9 = V_26 ;
V_9 ++ ;
if ( V_11 >= 31 )
{
while ( V_11 > 0 )
{
V_11 >>= 7 ;
V_9 ++ ;
}
}
if ( V_25 == 2 )
return V_9 + 3 ;
V_9 ++ ;
if ( V_26 > 127 )
{
while ( V_26 > 0 )
{
V_26 >>= 8 ;
V_9 ++ ;
}
}
return ( V_9 ) ;
}
static int F_11 ( T_1 * V_28 )
{
if ( ( V_28 -> V_13 == ( 1 | V_16 ) ) && ( ! V_28 -> V_29 ) )
{
if ( ! F_3 ( & V_28 -> V_1 , V_28 -> V_30 ) )
{
V_28 -> error = V_31 ;
return ( 0 ) ;
}
}
if ( ( ( V_28 -> V_30 != 0 ) && ! ( V_28 -> V_13 & 1 ) ) ||
( ( V_28 -> V_30 < 0 ) && ( V_28 -> V_13 & 1 ) ) )
{
V_28 -> error = V_32 ;
return ( 0 ) ;
}
return ( 1 ) ;
}
int F_12 ( T_2 * V_28 )
{
return F_11 ( ( T_1 * ) V_28 ) ;
}
int F_13 ( T_1 * V_28 )
{
return F_11 ( V_28 ) ;
}
int F_14 ( T_1 * V_28 , long * V_26 )
{
const unsigned char * V_33 ;
V_33 = V_28 -> V_1 ;
V_28 -> V_13 = F_4 ( & ( V_28 -> V_1 ) , & ( V_28 -> V_30 ) , & ( V_28 -> V_11 ) , & ( V_28 -> V_12 ) ,
* V_26 ) ;
if ( V_28 -> V_13 & 0x80 )
{
V_28 -> error = V_34 ;
return ( 0 ) ;
}
if ( V_28 -> V_11 != V_35 )
{
V_28 -> error = V_36 ;
return ( 0 ) ;
}
( * V_26 ) -= ( V_28 -> V_1 - V_33 ) ;
if ( V_28 -> V_14 && ( * V_26 < 0 ) )
{
V_28 -> error = V_32 ;
return ( 0 ) ;
}
if ( V_28 -> V_13 == ( 1 | V_16 ) )
V_28 -> V_30 = * V_26 + * ( V_28 -> V_3 ) - V_28 -> V_1 ;
V_28 -> V_29 = 0 ;
return ( 1 ) ;
}
int F_15 ( T_3 * V_37 , const T_3 * V_38 )
{
if ( V_38 == NULL )
return 0 ;
V_37 -> type = V_38 -> type ;
if ( ! F_16 ( V_37 , V_38 -> V_39 , V_38 -> V_26 ) )
return 0 ;
V_37 -> V_40 = V_38 -> V_40 ;
return 1 ;
}
T_3 * F_17 ( const T_3 * V_38 )
{
T_3 * V_9 ;
if ( ! V_38 )
return NULL ;
V_9 = F_18 () ;
if ( ! V_9 )
return NULL ;
if ( ! F_15 ( V_9 , V_38 ) )
{
F_19 ( V_9 ) ;
return NULL ;
}
return V_9 ;
}
int F_16 ( T_3 * V_38 , const void * V_41 , int V_2 )
{
unsigned char * V_28 ;
const char * V_39 = V_41 ;
if ( V_2 < 0 )
{
if ( V_39 == NULL )
return ( 0 ) ;
else
V_2 = strlen ( V_39 ) ;
}
if ( ( V_38 -> V_26 < V_2 ) || ( V_38 -> V_39 == NULL ) )
{
V_28 = V_38 -> V_39 ;
if ( V_28 == NULL )
V_38 -> V_39 = F_20 ( V_2 + 1 ) ;
else
V_38 -> V_39 = F_21 ( V_28 , V_2 + 1 ) ;
if ( V_38 -> V_39 == NULL )
{
F_6 ( V_42 , V_43 ) ;
V_38 -> V_39 = V_28 ;
return ( 0 ) ;
}
}
V_38 -> V_26 = V_2 ;
if ( V_39 != NULL )
{
memcpy ( V_38 -> V_39 , V_39 , V_2 ) ;
V_38 -> V_39 [ V_2 ] = '\0' ;
}
return ( 1 ) ;
}
void F_22 ( T_3 * V_38 , void * V_39 , int V_2 )
{
if ( V_38 -> V_39 )
F_23 ( V_38 -> V_39 ) ;
V_38 -> V_39 = V_39 ;
V_38 -> V_26 = V_2 ;
}
T_3 * F_18 ( void )
{
return ( F_24 ( V_44 ) ) ;
}
T_3 * F_24 ( int type )
{
T_3 * V_9 ;
V_9 = ( T_3 * ) F_20 ( sizeof( T_3 ) ) ;
if ( V_9 == NULL )
{
F_6 ( V_45 , V_43 ) ;
return ( NULL ) ;
}
V_9 -> V_26 = 0 ;
V_9 -> type = type ;
V_9 -> V_39 = NULL ;
V_9 -> V_40 = 0 ;
return ( V_9 ) ;
}
void F_19 ( T_3 * V_46 )
{
if ( V_46 == NULL ) return;
if ( V_46 -> V_39 && ! ( V_46 -> V_40 & V_47 ) )
F_23 ( V_46 -> V_39 ) ;
F_23 ( V_46 ) ;
}
int F_25 ( const T_3 * V_46 , const T_3 * V_48 )
{
int V_8 ;
V_8 = ( V_46 -> V_26 - V_48 -> V_26 ) ;
if ( V_8 == 0 )
{
V_8 = memcmp ( V_46 -> V_39 , V_48 -> V_39 , V_46 -> V_26 ) ;
if ( V_8 == 0 )
return ( V_46 -> type - V_48 -> type ) ;
else
return ( V_8 ) ;
}
else
return ( V_8 ) ;
}
void F_26 ( const unsigned char * V_49 , int V_50 )
{
char V_51 [ F_27 ( V_49 ) + 1 ] , V_52 [ F_27 ( V_50 ) + 1 ] ;
F_28 ( V_51 , sizeof V_51 , L_1 , ( unsigned long ) V_49 ) ;
F_28 ( V_52 , sizeof V_52 , L_2 , V_50 ) ;
F_29 ( 4 , L_3 , V_51 , L_4 , V_52 ) ;
}
int F_30 ( const T_3 * V_53 )
{ return F_31 ( V_53 ) ; }
void F_32 ( T_3 * V_53 , int V_2 )
{ F_33 ( V_53 , V_2 ) ; return; }
int F_34 ( T_3 * V_53 )
{ return F_35 ( V_53 ) ; }
unsigned char * F_36 ( T_3 * V_53 )
{ return F_37 ( V_53 ) ; }
