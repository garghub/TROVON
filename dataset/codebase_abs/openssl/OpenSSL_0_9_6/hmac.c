void F_1 ( T_1 * V_1 , const void * V_2 , int V_3 ,
const T_2 * V_4 )
{
int V_5 , V_6 , V_7 = 0 ;
unsigned char V_8 [ V_9 ] ;
if ( V_4 != NULL )
{
V_7 = 1 ;
V_1 -> V_4 = V_4 ;
}
else
V_4 = V_1 -> V_4 ;
if ( V_2 != NULL )
{
V_7 = 1 ;
V_6 = F_2 ( V_4 ) ;
if ( V_6 < V_3 )
{
F_3 ( & V_1 -> V_10 , V_4 ) ;
F_4 ( & V_1 -> V_10 , V_2 , V_3 ) ;
F_5 ( & ( V_1 -> V_10 ) , V_1 -> V_2 ,
& V_1 -> V_11 ) ;
}
else
{
memcpy ( V_1 -> V_2 , V_2 , V_3 ) ;
V_1 -> V_11 = V_3 ;
}
if( V_1 -> V_11 != V_9 )
memset ( & V_1 -> V_2 [ V_1 -> V_11 ] , 0 ,
V_9 - V_1 -> V_11 ) ;
}
if ( V_7 )
{
for ( V_5 = 0 ; V_5 < V_9 ; V_5 ++ )
V_8 [ V_5 ] = 0x36 ^ V_1 -> V_2 [ V_5 ] ;
F_3 ( & V_1 -> V_12 , V_4 ) ;
F_4 ( & V_1 -> V_12 , V_8 , F_2 ( V_4 ) ) ;
for ( V_5 = 0 ; V_5 < V_9 ; V_5 ++ )
V_8 [ V_5 ] = 0x5c ^ V_1 -> V_2 [ V_5 ] ;
F_3 ( & V_1 -> V_13 , V_4 ) ;
F_4 ( & V_1 -> V_13 , V_8 , F_2 ( V_4 ) ) ;
}
memcpy ( & V_1 -> V_10 , & V_1 -> V_12 , sizeof( V_1 -> V_12 ) ) ;
}
void F_6 ( T_1 * V_1 , const unsigned char * V_14 , int V_3 )
{
F_4 ( & ( V_1 -> V_10 ) , V_14 , V_3 ) ;
}
void F_7 ( T_1 * V_1 , unsigned char * V_4 , unsigned int * V_3 )
{
int V_6 ;
unsigned int V_5 ;
unsigned char V_15 [ V_16 ] ;
V_6 = F_2 ( V_1 -> V_4 ) ;
F_5 ( & ( V_1 -> V_10 ) , V_15 , & V_5 ) ;
memcpy ( & ( V_1 -> V_10 ) , & ( V_1 -> V_13 ) , sizeof( V_1 -> V_13 ) ) ;
F_4 ( & ( V_1 -> V_10 ) , V_15 , V_5 ) ;
F_5 ( & ( V_1 -> V_10 ) , V_4 , V_3 ) ;
}
void F_8 ( T_1 * V_1 )
{
memset ( V_1 , 0 , sizeof( T_1 ) ) ;
}
unsigned char * F_9 ( const T_2 * V_17 , const void * V_2 , int V_18 ,
const unsigned char * V_19 , int V_20 , unsigned char * V_4 ,
unsigned int * V_21 )
{
T_1 V_22 ;
static unsigned char V_23 [ V_16 ] ;
if ( V_4 == NULL ) V_4 = V_23 ;
F_1 ( & V_22 , V_2 , V_18 , V_17 ) ;
F_6 ( & V_22 , V_19 , V_20 ) ;
F_7 ( & V_22 , V_4 , V_21 ) ;
F_8 ( & V_22 ) ;
return ( V_4 ) ;
}
