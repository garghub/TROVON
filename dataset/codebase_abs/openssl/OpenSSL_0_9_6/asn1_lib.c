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
#if 0
if ((p+ *plength) > (omax+ *pp))
{
ASN1err(ASN1_F_ASN1_GET_OBJECT,ASN1_R_TOO_LONG);
ret|=0x80;
}
#endif
* V_3 = V_1 ;
return ( V_9 | V_13 ) ;
V_15:
F_4 ( V_19 , V_20 ) ;
return ( 0x80 ) ;
}
static int F_3 ( unsigned char * * V_3 , int * V_13 , long * V_21 , int V_14 )
{
unsigned char * V_1 = * V_3 ;
long V_9 = 0 ;
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
* V_3 = V_1 ;
* V_21 = V_9 ;
return ( 1 ) ;
}
void F_5 ( unsigned char * * V_3 , int V_22 , int V_23 , int V_11 ,
int V_12 )
{
unsigned char * V_1 = * V_3 ;
int V_8 , V_24 ;
V_8 = ( V_22 ) ? V_16 : 0 ;
V_8 |= ( V_12 & V_17 ) ;
if ( V_11 < 31 )
* ( V_1 ++ ) = V_8 | ( V_11 & V_18 ) ;
else
{
* ( V_1 ++ ) = V_8 | V_18 ;
for( V_8 = 0 , V_24 = V_11 ; V_24 > 0 ; V_8 ++ ) V_24 >>= 7 ;
V_24 = V_8 ;
while( V_8 -- > 0 )
{
V_1 [ V_8 ] = V_11 & 0x7f ;
if( V_8 != ( V_24 - 1 ) ) V_1 [ V_8 ] |= 0x80 ;
V_11 >>= 7 ;
}
V_1 += V_24 ;
}
if ( ( V_22 == 2 ) && ( V_23 == 0 ) )
* ( V_1 ++ ) = 0x80 ;
else
F_6 ( & V_1 , V_23 ) ;
* V_3 = V_1 ;
}
static void F_6 ( unsigned char * * V_3 , int V_23 )
{
unsigned char * V_1 = * V_3 ;
int V_8 , V_10 ;
if ( V_23 <= 127 )
* ( V_1 ++ ) = ( unsigned char ) V_23 ;
else
{
V_10 = V_23 ;
for ( V_8 = 0 ; V_10 > 0 ; V_8 ++ )
V_10 >>= 8 ;
* ( V_1 ++ ) = V_8 | 0x80 ;
V_10 = V_8 ;
while ( V_8 -- > 0 )
{
V_1 [ V_8 ] = V_23 & 0xff ;
V_23 >>= 8 ;
}
V_1 += V_10 ;
}
* V_3 = V_1 ;
}
int F_7 ( int V_22 , int V_23 , int V_11 )
{
int V_9 ;
V_9 = V_23 ;
V_9 ++ ;
if ( V_11 >= 31 )
{
while ( V_11 > 0 )
{
V_11 >>= 7 ;
V_9 ++ ;
}
}
if ( ( V_23 == 0 ) && ( V_22 == 2 ) )
V_9 += 2 ;
V_9 ++ ;
if ( V_23 > 127 )
{
while ( V_23 > 0 )
{
V_23 >>= 8 ;
V_9 ++ ;
}
}
return ( V_9 ) ;
}
int F_8 ( T_1 * V_25 )
{
if ( ( V_25 -> V_13 == ( 1 | V_16 ) ) && ( ! V_25 -> V_26 ) )
{
if ( ! F_1 ( & V_25 -> V_1 , V_25 -> V_27 ) )
{
V_25 -> error = V_28 ;
return ( 0 ) ;
}
}
if ( ( ( V_25 -> V_27 != 0 ) && ! ( V_25 -> V_13 & 1 ) ) ||
( ( V_25 -> V_27 < 0 ) && ( V_25 -> V_13 & 1 ) ) )
{
V_25 -> error = V_29 ;
return ( 0 ) ;
}
return ( 1 ) ;
}
int F_9 ( T_1 * V_25 , long * V_23 )
{
unsigned char * V_30 ;
V_30 = V_25 -> V_1 ;
V_25 -> V_13 = F_2 ( & ( V_25 -> V_1 ) , & ( V_25 -> V_27 ) , & ( V_25 -> V_11 ) , & ( V_25 -> V_12 ) ,
* V_23 ) ;
if ( V_25 -> V_13 & 0x80 )
{
V_25 -> error = V_31 ;
return ( 0 ) ;
}
if ( V_25 -> V_11 != V_32 )
{
V_25 -> error = V_33 ;
return ( 0 ) ;
}
( * V_23 ) -= ( V_25 -> V_1 - V_30 ) ;
if ( V_25 -> V_14 && ( * V_23 < 0 ) )
{
V_25 -> error = V_29 ;
return ( 0 ) ;
}
if ( V_25 -> V_13 == ( 1 | V_16 ) )
V_25 -> V_27 = * V_23 + * ( V_25 -> V_3 ) - V_25 -> V_1 ;
V_25 -> V_26 = 0 ;
return ( 1 ) ;
}
T_2 * F_10 ( T_2 * V_34 )
{
T_2 * V_9 ;
if ( V_34 == NULL ) return ( NULL ) ;
if ( ( V_9 = F_11 ( V_34 -> type ) ) == NULL )
return ( NULL ) ;
if ( ! F_12 ( V_9 , V_34 -> V_35 , V_34 -> V_23 ) )
{
F_13 ( V_9 ) ;
return ( NULL ) ;
}
V_9 -> V_36 = V_34 -> V_36 ;
return ( V_9 ) ;
}
int F_12 ( T_2 * V_34 , const void * V_37 , int V_2 )
{
unsigned char * V_25 ;
const char * V_35 = V_37 ;
if ( V_2 < 0 )
{
if ( V_35 == NULL )
return ( 0 ) ;
else
V_2 = strlen ( V_35 ) ;
}
if ( ( V_34 -> V_23 < V_2 ) || ( V_34 -> V_35 == NULL ) )
{
V_25 = V_34 -> V_35 ;
if ( V_25 == NULL )
V_34 -> V_35 = F_14 ( V_2 + 1 ) ;
else
V_34 -> V_35 = F_15 ( V_25 , V_2 + 1 ) ;
if ( V_34 -> V_35 == NULL )
{
V_34 -> V_35 = V_25 ;
return ( 0 ) ;
}
}
V_34 -> V_23 = V_2 ;
if ( V_35 != NULL )
{
memcpy ( V_34 -> V_35 , V_35 , V_2 ) ;
V_34 -> V_35 [ V_2 ] = '\0' ;
}
return ( 1 ) ;
}
T_2 * F_16 ( void )
{
return ( F_11 ( V_38 ) ) ;
}
T_2 * F_11 ( int type )
{
T_2 * V_9 ;
V_9 = ( T_2 * ) F_14 ( sizeof( T_2 ) ) ;
if ( V_9 == NULL )
{
F_4 ( V_39 , V_40 ) ;
return ( NULL ) ;
}
V_9 -> V_23 = 0 ;
V_9 -> type = type ;
V_9 -> V_35 = NULL ;
V_9 -> V_36 = 0 ;
return ( V_9 ) ;
}
void F_13 ( T_2 * V_41 )
{
if ( V_41 == NULL ) return;
if ( V_41 -> V_35 != NULL ) F_17 ( V_41 -> V_35 ) ;
F_17 ( V_41 ) ;
}
int F_18 ( T_2 * V_41 , T_2 * V_42 )
{
int V_8 ;
V_8 = ( V_41 -> V_23 - V_42 -> V_23 ) ;
if ( V_8 == 0 )
{
V_8 = memcmp ( V_41 -> V_35 , V_42 -> V_35 , V_41 -> V_23 ) ;
if ( V_8 == 0 )
return ( V_41 -> type - V_42 -> type ) ;
else
return ( V_8 ) ;
}
else
return ( V_8 ) ;
}
void F_19 ( unsigned char * V_43 , int V_44 )
{
char V_45 [ 16 ] , V_46 [ 16 ] ;
sprintf ( V_45 , L_1 , ( unsigned long ) V_43 ) ;
sprintf ( V_46 , L_2 , V_44 ) ;
F_20 ( 4 , L_3 , V_45 , L_4 , V_46 ) ;
}
int F_21 ( T_2 * V_47 )
{ return F_22 ( V_47 ) ; }
void F_23 ( T_2 * V_47 , int V_2 )
{ F_24 ( V_47 , V_2 ) ; return; }
int F_25 ( T_2 * V_47 )
{ return F_26 ( V_47 ) ; }
unsigned char * F_27 ( T_2 * V_47 )
{ return F_28 ( V_47 ) ; }
