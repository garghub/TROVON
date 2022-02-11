static void F_1 ( unsigned char * V_1 , const unsigned char * V_2 , int V_3 )
{
int V_4 ;
unsigned char V_5 = V_2 [ 0 ] , V_6 = V_5 >> 7 , V_7 ;
for ( V_4 = 0 ; V_4 < V_3 - 1 ; V_4 ++ , V_5 = V_7 )
V_1 [ V_4 ] = ( V_5 << 1 ) | ( ( V_7 = V_2 [ V_4 + 1 ] ) >> 7 ) ;
V_1 [ V_4 ] = ( V_5 << 1 ) ^ ( ( 0 - V_6 ) & ( V_3 == 16 ? 0x87 : 0x1b ) ) ;
}
T_1 * F_2 ( void )
{
T_1 * V_8 ;
V_8 = F_3 ( sizeof( * V_8 ) ) ;
if ( V_8 == NULL )
return NULL ;
V_8 -> V_9 = F_4 () ;
if ( V_8 -> V_9 == NULL ) {
F_5 ( V_8 ) ;
return NULL ;
}
V_8 -> V_10 = - 1 ;
return V_8 ;
}
void F_6 ( T_1 * V_8 )
{
F_7 ( V_8 -> V_9 ) ;
F_8 ( V_8 -> V_11 , V_12 ) ;
F_8 ( V_8 -> V_1 , V_12 ) ;
F_8 ( V_8 -> V_13 , V_12 ) ;
F_8 ( V_8 -> V_14 , V_12 ) ;
V_8 -> V_10 = - 1 ;
}
T_2 * F_9 ( T_1 * V_8 )
{
return V_8 -> V_9 ;
}
void F_10 ( T_1 * V_8 )
{
if ( ! V_8 )
return;
F_6 ( V_8 ) ;
F_5 ( V_8 ) ;
}
int F_11 ( T_1 * V_15 , const T_1 * V_16 )
{
int V_3 ;
if ( V_16 -> V_10 == - 1 )
return 0 ;
if ( ! F_12 ( V_15 -> V_9 , V_16 -> V_9 ) )
return 0 ;
V_3 = F_13 ( V_16 -> V_9 ) ;
memcpy ( V_15 -> V_1 , V_16 -> V_1 , V_3 ) ;
memcpy ( V_15 -> V_13 , V_16 -> V_13 , V_3 ) ;
memcpy ( V_15 -> V_11 , V_16 -> V_11 , V_3 ) ;
memcpy ( V_15 -> V_14 , V_16 -> V_14 , V_3 ) ;
V_15 -> V_10 = V_16 -> V_10 ;
return 1 ;
}
int F_14 ( T_1 * V_8 , const void * V_17 , T_3 V_18 ,
const T_4 * V_19 , T_5 * V_20 )
{
static const unsigned char V_21 [ V_12 ] = { 0 } ;
if ( ! V_17 && ! V_19 && ! V_20 && V_18 == 0 ) {
if ( V_8 -> V_10 == - 1 )
return 0 ;
if ( ! F_15 ( V_8 -> V_9 , NULL , NULL , NULL , V_21 ) )
return 0 ;
memset ( V_8 -> V_11 , 0 , F_13 ( V_8 -> V_9 ) ) ;
V_8 -> V_10 = 0 ;
return 1 ;
}
if ( V_19 && ! F_15 ( V_8 -> V_9 , V_19 , V_20 , NULL , NULL ) )
return 0 ;
if ( V_17 ) {
int V_3 ;
if ( ! F_16 ( V_8 -> V_9 ) )
return 0 ;
if ( ! F_17 ( V_8 -> V_9 , V_18 ) )
return 0 ;
if ( ! F_15 ( V_8 -> V_9 , NULL , NULL , V_17 , V_21 ) )
return 0 ;
V_3 = F_13 ( V_8 -> V_9 ) ;
if ( ! F_18 ( V_8 -> V_9 , V_8 -> V_11 , V_21 , V_3 ) )
return 0 ;
F_1 ( V_8 -> V_1 , V_8 -> V_11 , V_3 ) ;
F_1 ( V_8 -> V_13 , V_8 -> V_1 , V_3 ) ;
F_8 ( V_8 -> V_11 , V_3 ) ;
if ( ! F_15 ( V_8 -> V_9 , NULL , NULL , NULL , V_21 ) )
return 0 ;
memset ( V_8 -> V_11 , 0 , V_3 ) ;
V_8 -> V_10 = 0 ;
}
return 1 ;
}
int F_19 ( T_1 * V_8 , const void * V_16 , T_3 V_22 )
{
const unsigned char * V_23 = V_16 ;
T_3 V_3 ;
if ( V_8 -> V_10 == - 1 )
return 0 ;
if ( V_22 == 0 )
return 1 ;
V_3 = F_13 ( V_8 -> V_9 ) ;
if ( V_8 -> V_10 > 0 ) {
T_3 V_24 ;
V_24 = V_3 - V_8 -> V_10 ;
if ( V_22 < V_24 )
V_24 = V_22 ;
memcpy ( V_8 -> V_14 + V_8 -> V_10 , V_23 , V_24 ) ;
V_22 -= V_24 ;
V_8 -> V_10 += V_24 ;
if ( V_22 == 0 )
return 1 ;
V_23 += V_24 ;
if ( ! F_18 ( V_8 -> V_9 , V_8 -> V_11 , V_8 -> V_14 , V_3 ) )
return 0 ;
}
while ( V_22 > V_3 ) {
if ( ! F_18 ( V_8 -> V_9 , V_8 -> V_11 , V_23 , V_3 ) )
return 0 ;
V_22 -= V_3 ;
V_23 += V_3 ;
}
memcpy ( V_8 -> V_14 , V_23 , V_22 ) ;
V_8 -> V_10 = V_22 ;
return 1 ;
}
int F_20 ( T_1 * V_8 , unsigned char * V_15 , T_3 * V_25 )
{
int V_4 , V_3 , V_26 ;
if ( V_8 -> V_10 == - 1 )
return 0 ;
V_3 = F_13 ( V_8 -> V_9 ) ;
* V_25 = ( T_3 ) V_3 ;
if ( ! V_15 )
return 1 ;
V_26 = V_8 -> V_10 ;
if ( V_26 == V_3 ) {
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
V_15 [ V_4 ] = V_8 -> V_14 [ V_4 ] ^ V_8 -> V_1 [ V_4 ] ;
} else {
V_8 -> V_14 [ V_26 ] = 0x80 ;
if ( V_3 - V_26 > 1 )
memset ( V_8 -> V_14 + V_26 + 1 , 0 , V_3 - V_26 - 1 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
V_15 [ V_4 ] = V_8 -> V_14 [ V_4 ] ^ V_8 -> V_13 [ V_4 ] ;
}
if ( ! F_18 ( V_8 -> V_9 , V_15 , V_15 , V_3 ) ) {
F_8 ( V_15 , V_3 ) ;
return 0 ;
}
return 1 ;
}
int F_21 ( T_1 * V_8 )
{
if ( V_8 -> V_10 == - 1 )
return 0 ;
return F_15 ( V_8 -> V_9 , NULL , NULL , NULL , V_8 -> V_11 ) ;
}
