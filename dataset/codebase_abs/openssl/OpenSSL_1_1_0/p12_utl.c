unsigned char * F_1 ( const char * V_1 , int V_2 ,
unsigned char * * V_3 , int * V_4 )
{
int V_5 , V_6 ;
unsigned char * V_7 ;
if ( V_2 == - 1 )
V_2 = strlen ( V_1 ) ;
V_5 = V_2 * 2 + 2 ;
if ( ( V_7 = F_2 ( V_5 ) ) == NULL )
return NULL ;
for ( V_6 = 0 ; V_6 < V_5 - 2 ; V_6 += 2 ) {
V_7 [ V_6 ] = 0 ;
V_7 [ V_6 + 1 ] = V_1 [ V_6 >> 1 ] ;
}
V_7 [ V_5 - 2 ] = 0 ;
V_7 [ V_5 - 1 ] = 0 ;
if ( V_4 )
* V_4 = V_5 ;
if ( V_3 )
* V_3 = V_7 ;
return V_7 ;
}
char * F_3 ( const unsigned char * V_3 , int V_4 )
{
int V_2 , V_6 ;
char * V_8 ;
if ( V_4 & 1 )
return NULL ;
V_2 = V_4 / 2 ;
if ( ! V_4 || V_3 [ V_4 - 1 ] )
V_2 ++ ;
V_3 ++ ;
if ( ( V_8 = F_2 ( V_2 ) ) == NULL )
return NULL ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 += 2 )
V_8 [ V_6 >> 1 ] = V_3 [ V_6 ] ;
V_8 [ V_2 - 1 ] = 0 ;
return V_8 ;
}
unsigned char * F_4 ( const char * V_1 , int V_2 ,
unsigned char * * V_3 , int * V_4 )
{
int V_5 , V_6 , V_9 ;
unsigned char * V_7 , * V_10 ;
unsigned long V_11 = 0 ;
if ( V_2 == - 1 )
V_2 = strlen ( V_1 ) ;
for ( V_5 = 0 , V_6 = 0 ; V_6 < V_2 ; V_6 += V_9 ) {
V_9 = F_5 ( ( const unsigned char * ) V_1 + V_6 , V_2 - V_6 , & V_11 ) ;
if ( V_9 < 0 )
return F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
if ( V_11 > 0x10FFFF )
return NULL ;
if ( V_11 >= 0x10000 )
V_5 += 2 * 2 ;
else
V_5 += 2 ;
}
V_5 += 2 ;
if ( ( V_10 = F_2 ( V_5 ) ) == NULL )
return NULL ;
for ( V_7 = V_10 , V_6 = 0 ; V_6 < V_2 ; V_6 += V_9 ) {
V_9 = F_5 ( ( const unsigned char * ) V_1 + V_6 , V_2 - V_6 , & V_11 ) ;
if ( V_11 >= 0x10000 ) {
unsigned int V_12 , V_13 ;
V_11 -= 0x10000 ;
V_12 = 0xD800 + ( V_11 >> 10 ) ;
V_13 = 0xDC00 + ( V_11 & 0x3ff ) ;
* V_7 ++ = ( unsigned char ) ( V_12 >> 8 ) ;
* V_7 ++ = ( unsigned char ) ( V_12 ) ;
* V_7 ++ = ( unsigned char ) ( V_13 >> 8 ) ;
* V_7 ++ = ( unsigned char ) ( V_13 ) ;
} else {
* V_7 ++ = ( unsigned char ) ( V_11 >> 8 ) ;
* V_7 ++ = ( unsigned char ) ( V_11 ) ;
}
}
* V_7 ++ = 0 ;
* V_7 ++ = 0 ;
if ( V_4 )
* V_4 = V_5 ;
if ( V_3 )
* V_3 = V_10 ;
return V_10 ;
}
static int F_6 ( char * V_14 , const unsigned char * V_15 , int V_16 )
{
unsigned long V_11 ;
if ( V_16 == 0 ) return 0 ;
if ( V_16 < 2 ) return - 1 ;
V_11 = ( V_15 [ 0 ] << 8 ) | V_15 [ 1 ] ;
if ( V_11 >= 0xD800 && V_11 < 0xE000 ) {
unsigned int V_13 ;
if ( V_16 < 4 ) return - 1 ;
V_11 -= 0xD800 ;
V_11 <<= 10 ;
V_13 = ( V_15 [ 2 ] << 8 ) | V_15 [ 3 ] ;
if ( V_13 < 0xDC00 || V_13 >= 0xE000 ) return - 1 ;
V_11 |= V_13 - 0xDC00 ;
V_11 += 0x10000 ;
}
return F_7 ( ( unsigned char * ) V_14 , V_16 > 4 ? 4 : V_16 , V_11 ) ;
}
char * F_8 ( const unsigned char * V_3 , int V_4 )
{
int V_2 , V_6 , V_9 ;
char * V_8 ;
if ( V_4 & 1 )
return NULL ;
for ( V_2 = 0 , V_6 = 0 ; V_6 < V_4 ; ) {
V_9 = F_6 ( NULL , V_3 + V_6 , V_4 - V_6 ) ;
if ( V_9 < 0 ) return F_3 ( V_3 , V_4 ) ;
if ( V_9 == 4 ) V_6 += 4 ;
else V_6 += 2 ;
V_2 += V_9 ;
}
if ( ! V_4 || ( V_3 [ V_4 - 2 ] || V_3 [ V_4 - 1 ] ) )
V_2 ++ ;
if ( ( V_8 = F_2 ( V_2 ) ) == NULL )
return NULL ;
for ( V_2 = 0 , V_6 = 0 ; V_6 < V_4 ; ) {
V_9 = F_6 ( V_8 + V_2 , V_3 + V_6 , V_4 - V_6 ) ;
if ( V_9 == 4 ) V_6 += 4 ;
else V_6 += 2 ;
V_2 += V_9 ;
}
if ( ! V_4 || ( V_3 [ V_4 - 2 ] || V_3 [ V_4 - 1 ] ) )
V_8 [ V_2 ] = '\0' ;
return V_8 ;
}
int F_9 ( T_1 * V_17 , T_2 * V_18 )
{
return F_10 ( F_11 ( T_2 ) , V_17 , V_18 ) ;
}
int F_12 ( T_3 * V_19 , T_2 * V_18 )
{
return F_13 ( F_11 ( T_2 ) , V_19 , V_18 ) ;
}
T_2 * F_14 ( T_1 * V_17 , T_2 * * V_18 )
{
return F_15 ( F_11 ( T_2 ) , V_17 , V_18 ) ;
}
T_2 * F_16 ( T_3 * V_19 , T_2 * * V_18 )
{
return F_17 ( F_11 ( T_2 ) , V_19 , V_18 ) ;
}
