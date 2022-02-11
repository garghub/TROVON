int F_1 ( T_1 * V_1 )
{
F_2 ( F_3 ( V_1 -> V_2 , V_1 -> V_3 ) ) ;
return ( V_1 -> V_2 == 0 ) ;
}
int F_4 ( T_1 * V_1 , char * V_4 , int V_2 )
{
F_2 ( V_1 ) ;
F_2 ( V_2 >= 0 ) ;
V_1 -> V_2 = V_2 ;
if ( V_2 ) {
F_5 ( V_1 -> V_3 , V_2 ) ;
if ( ! V_1 -> V_3 ) {
V_1 -> V_2 = 0 ;
return - V_5 ;
}
memcpy ( V_1 -> V_3 , V_4 , V_2 ) ;
} else
V_1 -> V_3 = NULL ;
return 0 ;
}
void F_6 ( T_1 * V_1 )
{
F_2 ( V_1 ) ;
if ( V_1 -> V_2 ) {
F_2 ( V_1 -> V_3 ) ;
F_7 ( V_1 -> V_3 , V_1 -> V_2 ) ;
V_1 -> V_2 = 0 ;
V_1 -> V_3 = NULL ;
} else
F_2 ( ! V_1 -> V_3 ) ;
}
int F_8 ( T_1 * V_6 , T_1 * V_7 )
{
F_2 ( V_6 && V_7 ) ;
return ( V_6 -> V_2 == V_7 -> V_2 &&
( ! V_6 -> V_2 || ! memcmp ( V_6 -> V_3 , V_7 -> V_3 , V_6 -> V_2 ) ) ) ;
}
int F_9 ( T_1 * V_8 , T_1 * V_9 )
{
F_2 ( V_9 && V_8 ) ;
V_8 -> V_2 = V_9 -> V_2 ;
if ( V_8 -> V_2 ) {
F_5 ( V_8 -> V_3 , V_8 -> V_2 ) ;
if ( ! V_8 -> V_3 ) {
V_8 -> V_2 = 0 ;
return - V_5 ;
}
memcpy ( V_8 -> V_3 , V_9 -> V_3 , V_8 -> V_2 ) ;
} else
V_8 -> V_3 = NULL ;
return 0 ;
}
int F_10 ( T_1 * V_1 , T_2 * * V_4 , T_2 * V_10 )
{
T_2 V_2 ;
F_2 ( V_1 ) ;
F_2 ( V_4 ) ;
F_2 ( V_10 ) ;
V_2 = F_11 ( V_1 -> V_2 ) ;
if ( * V_10 < 4 + V_2 ) {
F_12 ( L_1 , * V_10 , 4 + V_2 ) ;
return - V_11 ;
}
* ( * V_4 ) ++ = F_13 ( V_1 -> V_2 ) ;
memcpy ( * V_4 , V_1 -> V_3 , V_1 -> V_2 ) ;
* V_4 += ( V_2 >> 2 ) ;
* V_10 -= ( 4 + V_2 ) ;
return 0 ;
}
static int F_14 ( T_1 * V_1 , T_2 * * V_4 , T_2 * V_10 ,
int V_12 , int V_13 )
{
T_2 V_2 ;
if ( * V_10 < sizeof( T_2 ) ) {
F_12 ( L_2 , * V_10 ) ;
return - V_11 ;
}
V_1 -> V_2 = * ( * V_4 ) ++ ;
if ( ! V_13 )
V_1 -> V_2 = F_15 ( V_1 -> V_2 ) ;
* V_10 -= sizeof( T_2 ) ;
if ( ! V_1 -> V_2 ) {
V_1 -> V_3 = NULL ;
return 0 ;
}
V_2 = V_13 ? V_1 -> V_2 : F_11 ( V_1 -> V_2 ) ;
if ( * V_10 < V_2 ) {
F_12 ( L_3 , * V_10 , V_2 ) ;
V_1 -> V_2 = 0 ;
return - V_11 ;
}
if ( ! V_12 )
V_1 -> V_3 = ( V_14 * ) * V_4 ;
else {
F_5 ( V_1 -> V_3 , V_1 -> V_2 ) ;
if ( ! V_1 -> V_3 ) {
F_12 ( L_4 , V_1 -> V_2 ) ;
V_1 -> V_2 = 0 ;
return - V_5 ;
}
memcpy ( V_1 -> V_3 , * V_4 , V_1 -> V_2 ) ;
}
* ( ( char * * ) V_4 ) += V_2 ;
* V_10 -= V_2 ;
return 0 ;
}
int F_16 ( T_1 * V_1 , T_2 * * V_4 , T_2 * V_10 )
{
return F_14 ( V_1 , V_4 , V_10 , 0 , 0 ) ;
}
int F_17 ( T_1 * V_1 , T_2 * * V_4 , T_2 * V_10 )
{
return F_14 ( V_1 , V_4 , V_10 , 1 , 0 ) ;
}
int F_18 ( T_1 * V_1 , T_2 * * V_4 , T_2 * V_10 )
{
return F_14 ( V_1 , V_4 , V_10 , 0 , 1 ) ;
}
int F_19 ( T_1 * V_1 , T_2 * * V_4 , T_2 * V_10 )
{
return F_14 ( V_1 , V_4 , V_10 , 1 , 1 ) ;
}
int F_20 ( T_1 * V_15 , T_3 * V_16 )
{
V_15 -> V_2 = V_16 -> V_2 ;
V_15 -> V_3 = V_16 -> V_3 ;
return 0 ;
}
int F_21 ( T_1 * V_15 , T_3 * V_16 )
{
V_15 -> V_2 = 0 ;
V_15 -> V_3 = NULL ;
if ( V_16 -> V_2 == 0 )
return 0 ;
F_5 ( V_15 -> V_3 , V_16 -> V_2 ) ;
if ( V_15 -> V_3 == NULL )
return - V_5 ;
V_15 -> V_2 = V_16 -> V_2 ;
memcpy ( V_15 -> V_3 , V_16 -> V_3 , V_16 -> V_2 ) ;
return 0 ;
}
int F_22 ( const void * * V_4 , T_2 * V_10 ,
void * V_17 , T_2 V_18 )
{
if ( * V_10 < V_18 ) {
F_12 ( L_3 , * V_10 , V_18 ) ;
return - V_11 ;
}
memcpy ( V_17 , * V_4 , V_18 ) ;
* V_4 += V_18 ;
* V_10 -= V_18 ;
return 0 ;
}
