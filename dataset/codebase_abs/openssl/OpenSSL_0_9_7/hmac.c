void F_1 ( T_1 * V_1 , const void * V_2 , int V_3 ,
const T_2 * V_4 , T_3 * V_5 )
{
int V_6 , V_7 , V_8 = 0 ;
unsigned char V_9 [ V_10 ] ;
if ( V_4 != NULL )
{
V_8 = 1 ;
V_1 -> V_4 = V_4 ;
}
else
V_4 = V_1 -> V_4 ;
if ( V_2 != NULL )
{
V_8 = 1 ;
V_7 = F_2 ( V_4 ) ;
F_3 ( V_7 <= sizeof V_1 -> V_2 ) ;
if ( V_7 < V_3 )
{
F_4 ( & V_1 -> V_11 , V_4 , V_5 ) ;
F_5 ( & V_1 -> V_11 , V_2 , V_3 ) ;
F_6 ( & ( V_1 -> V_11 ) , V_1 -> V_2 ,
& V_1 -> V_12 ) ;
}
else
{
F_3 ( V_3 <= sizeof V_1 -> V_2 ) ;
memcpy ( V_1 -> V_2 , V_2 , V_3 ) ;
V_1 -> V_12 = V_3 ;
}
if( V_1 -> V_12 != V_10 )
memset ( & V_1 -> V_2 [ V_1 -> V_12 ] , 0 ,
V_10 - V_1 -> V_12 ) ;
}
if ( V_8 )
{
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ )
V_9 [ V_6 ] = 0x36 ^ V_1 -> V_2 [ V_6 ] ;
F_4 ( & V_1 -> V_13 , V_4 , V_5 ) ;
F_5 ( & V_1 -> V_13 , V_9 , F_2 ( V_4 ) ) ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ )
V_9 [ V_6 ] = 0x5c ^ V_1 -> V_2 [ V_6 ] ;
F_4 ( & V_1 -> V_14 , V_4 , V_5 ) ;
F_5 ( & V_1 -> V_14 , V_9 , F_2 ( V_4 ) ) ;
}
F_7 ( & V_1 -> V_11 , & V_1 -> V_13 ) ;
}
void F_8 ( T_1 * V_1 , const void * V_2 , int V_3 ,
const T_2 * V_4 )
{
if( V_2 && V_4 )
F_9 ( V_1 ) ;
F_1 ( V_1 , V_2 , V_3 , V_4 , NULL ) ;
}
void F_10 ( T_1 * V_1 , const unsigned char * V_15 , int V_3 )
{
F_5 ( & V_1 -> V_11 , V_15 , V_3 ) ;
}
void F_11 ( T_1 * V_1 , unsigned char * V_4 , unsigned int * V_3 )
{
int V_7 ;
unsigned int V_6 ;
unsigned char V_16 [ V_17 ] ;
V_7 = F_2 ( V_1 -> V_4 ) ;
F_6 ( & V_1 -> V_11 , V_16 , & V_6 ) ;
F_7 ( & V_1 -> V_11 , & V_1 -> V_14 ) ;
F_5 ( & V_1 -> V_11 , V_16 , V_6 ) ;
F_6 ( & V_1 -> V_11 , V_4 , V_3 ) ;
}
void F_9 ( T_1 * V_1 )
{
F_12 ( & V_1 -> V_13 ) ;
F_12 ( & V_1 -> V_14 ) ;
F_12 ( & V_1 -> V_11 ) ;
}
void F_13 ( T_1 * V_1 )
{
F_14 ( & V_1 -> V_13 ) ;
F_14 ( & V_1 -> V_14 ) ;
F_14 ( & V_1 -> V_11 ) ;
memset ( V_1 , 0 , sizeof *V_1 ) ;
}
unsigned char * F_15 ( const T_2 * V_18 , const void * V_2 , int V_19 ,
const unsigned char * V_20 , int V_21 , unsigned char * V_4 ,
unsigned int * V_22 )
{
T_1 V_23 ;
static unsigned char V_24 [ V_17 ] ;
if ( V_4 == NULL ) V_4 = V_24 ;
F_9 ( & V_23 ) ;
F_8 ( & V_23 , V_2 , V_19 , V_18 ) ;
F_10 ( & V_23 , V_20 , V_21 ) ;
F_11 ( & V_23 , V_4 , V_22 ) ;
F_13 ( & V_23 ) ;
return ( V_4 ) ;
}
