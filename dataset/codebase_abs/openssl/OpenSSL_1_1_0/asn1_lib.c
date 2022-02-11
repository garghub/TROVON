static int F_1 ( const unsigned char * * V_1 , long V_2 )
{
if ( V_2 <= 0 )
return ( 1 ) ;
else if ( ( V_2 >= 2 ) && ( ( * V_1 ) [ 0 ] == 0 ) && ( ( * V_1 ) [ 1 ] == 0 ) ) {
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
if ( ! V_14 )
goto V_15;
V_9 = ( * V_1 & V_16 ) ;
V_12 = ( * V_1 & V_17 ) ;
V_8 = * V_1 & V_18 ;
if ( V_8 == V_18 ) {
V_1 ++ ;
if ( -- V_14 == 0 )
goto V_15;
V_10 = 0 ;
while ( * V_1 & 0x80 ) {
V_10 <<= 7L ;
V_10 |= * ( V_1 ++ ) & 0x7f ;
if ( -- V_14 == 0 )
goto V_15;
if ( V_10 > ( V_19 >> 7L ) )
goto V_15;
}
V_10 <<= 7L ;
V_10 |= * ( V_1 ++ ) & 0x7f ;
V_11 = ( int ) V_10 ;
if ( -- V_14 == 0 )
goto V_15;
} else {
V_11 = V_8 ;
V_1 ++ ;
if ( -- V_14 == 0 )
goto V_15;
}
* V_5 = V_11 ;
* V_6 = V_12 ;
if ( ! F_5 ( & V_1 , & V_13 , V_4 , V_14 ) )
goto V_15;
if ( V_13 && ! ( V_9 & V_16 ) )
goto V_15;
if ( * V_4 > ( V_7 - ( V_1 - * V_3 ) ) ) {
F_6 ( V_20 , V_21 ) ;
V_9 |= 0x80 ;
}
* V_3 = V_1 ;
return ( V_9 | V_13 ) ;
V_15:
F_6 ( V_20 , V_22 ) ;
return ( 0x80 ) ;
}
static int F_5 ( const unsigned char * * V_3 , int * V_13 , long * V_23 ,
long V_14 )
{
const unsigned char * V_1 = * V_3 ;
unsigned long V_9 = 0 ;
unsigned long V_8 ;
if ( V_14 -- < 1 )
return 0 ;
if ( * V_1 == 0x80 ) {
* V_13 = 1 ;
V_9 = 0 ;
V_1 ++ ;
} else {
* V_13 = 0 ;
V_8 = * V_1 & 0x7f ;
if ( * ( V_1 ++ ) & 0x80 ) {
if ( V_14 < ( long ) V_8 + 1 )
return 0 ;
while ( V_8 && * V_1 == 0 ) {
V_1 ++ ;
V_8 -- ;
}
if ( V_8 > sizeof( long ) )
return 0 ;
while ( V_8 -- > 0 ) {
V_9 <<= 8L ;
V_9 |= * ( V_1 ++ ) ;
}
} else
V_9 = V_8 ;
}
if ( V_9 > V_24 )
return 0 ;
* V_3 = V_1 ;
* V_23 = ( long ) V_9 ;
return 1 ;
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
else {
* ( V_1 ++ ) = V_8 | V_18 ;
for ( V_8 = 0 , V_27 = V_11 ; V_27 > 0 ; V_8 ++ )
V_27 >>= 7 ;
V_27 = V_8 ;
while ( V_8 -- > 0 ) {
V_1 [ V_8 ] = V_11 & 0x7f ;
if ( V_8 != ( V_27 - 1 ) )
V_1 [ V_8 ] |= 0x80 ;
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
else {
V_10 = V_26 ;
for ( V_8 = 0 ; V_10 > 0 ; V_8 ++ )
V_10 >>= 8 ;
* ( V_1 ++ ) = V_8 | 0x80 ;
V_10 = V_8 ;
while ( V_8 -- > 0 ) {
V_1 [ V_8 ] = V_26 & 0xff ;
V_26 >>= 8 ;
}
V_1 += V_10 ;
}
* V_3 = V_1 ;
}
int F_10 ( int V_25 , int V_26 , int V_11 )
{
int V_9 = 1 ;
if ( V_26 < 0 )
return - 1 ;
if ( V_11 >= 31 ) {
while ( V_11 > 0 ) {
V_11 >>= 7 ;
V_9 ++ ;
}
}
if ( V_25 == 2 ) {
V_9 += 3 ;
} else {
V_9 ++ ;
if ( V_26 > 127 ) {
int V_28 = V_26 ;
while ( V_28 > 0 ) {
V_28 >>= 8 ;
V_9 ++ ;
}
}
}
if ( V_9 >= V_19 - V_26 )
return - 1 ;
return V_9 + V_26 ;
}
int F_11 ( T_1 * V_29 , const T_1 * V_30 )
{
if ( V_30 == NULL )
return 0 ;
V_29 -> type = V_30 -> type ;
if ( ! F_12 ( V_29 , V_30 -> V_31 , V_30 -> V_26 ) )
return 0 ;
V_29 -> V_32 &= V_33 ;
V_29 -> V_32 |= V_30 -> V_32 & ~ V_33 ;
return 1 ;
}
T_1 * F_13 ( const T_1 * V_30 )
{
T_1 * V_9 ;
if ( ! V_30 )
return NULL ;
V_9 = F_14 () ;
if ( V_9 == NULL )
return NULL ;
if ( ! F_11 ( V_9 , V_30 ) ) {
F_15 ( V_9 ) ;
return NULL ;
}
return V_9 ;
}
int F_12 ( T_1 * V_30 , const void * V_34 , int V_2 )
{
unsigned char * V_35 ;
const char * V_31 = V_34 ;
if ( V_2 < 0 ) {
if ( V_31 == NULL )
return ( 0 ) ;
else
V_2 = strlen ( V_31 ) ;
}
if ( ( V_30 -> V_26 <= V_2 ) || ( V_30 -> V_31 == NULL ) ) {
V_35 = V_30 -> V_31 ;
V_30 -> V_31 = F_16 ( V_35 , V_2 + 1 ) ;
if ( V_30 -> V_31 == NULL ) {
F_6 ( V_36 , V_37 ) ;
V_30 -> V_31 = V_35 ;
return ( 0 ) ;
}
}
V_30 -> V_26 = V_2 ;
if ( V_31 != NULL ) {
memcpy ( V_30 -> V_31 , V_31 , V_2 ) ;
V_30 -> V_31 [ V_2 ] = '\0' ;
}
return ( 1 ) ;
}
void F_17 ( T_1 * V_30 , void * V_31 , int V_2 )
{
F_18 ( V_30 -> V_31 ) ;
V_30 -> V_31 = V_31 ;
V_30 -> V_26 = V_2 ;
}
T_1 * F_14 ( void )
{
return ( F_19 ( V_38 ) ) ;
}
T_1 * F_19 ( int type )
{
T_1 * V_9 ;
V_9 = F_20 ( sizeof( * V_9 ) ) ;
if ( V_9 == NULL ) {
F_6 ( V_39 , V_37 ) ;
return ( NULL ) ;
}
V_9 -> type = type ;
return ( V_9 ) ;
}
void F_15 ( T_1 * V_40 )
{
if ( V_40 == NULL )
return;
if ( ! ( V_40 -> V_32 & V_41 ) )
F_18 ( V_40 -> V_31 ) ;
if ( ! ( V_40 -> V_32 & V_33 ) )
F_18 ( V_40 ) ;
}
void F_21 ( T_1 * V_40 )
{
if ( V_40 == NULL )
return;
if ( V_40 -> V_31 && ! ( V_40 -> V_32 & V_41 ) )
F_22 ( V_40 -> V_31 , V_40 -> V_26 ) ;
F_15 ( V_40 ) ;
}
int F_23 ( const T_1 * V_40 , const T_1 * V_42 )
{
int V_8 ;
V_8 = ( V_40 -> V_26 - V_42 -> V_26 ) ;
if ( V_8 == 0 ) {
V_8 = memcmp ( V_40 -> V_31 , V_42 -> V_31 , V_40 -> V_26 ) ;
if ( V_8 == 0 )
return ( V_40 -> type - V_42 -> type ) ;
else
return ( V_8 ) ;
} else
return ( V_8 ) ;
}
int F_24 ( const T_1 * V_43 )
{
return V_43 -> V_26 ;
}
void F_25 ( T_1 * V_43 , int V_2 )
{
V_43 -> V_26 = V_2 ;
}
int F_26 ( const T_1 * V_43 )
{
return V_43 -> type ;
}
const unsigned char * F_27 ( const T_1 * V_43 )
{
return V_43 -> V_31 ;
}
unsigned char * F_28 ( T_1 * V_43 )
{
return V_43 -> V_31 ;
}
