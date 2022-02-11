static void
F_1 ( unsigned char * V_1 , unsigned char * V_2 )
{
int V_3 ;
V_2 [ 0 ] = V_1 [ 0 ] >> 1 ;
V_2 [ 1 ] = ( ( V_1 [ 0 ] & 0x01 ) << 6 ) | ( V_1 [ 1 ] >> 2 ) ;
V_2 [ 2 ] = ( ( V_1 [ 1 ] & 0x03 ) << 5 ) | ( V_1 [ 2 ] >> 3 ) ;
V_2 [ 3 ] = ( ( V_1 [ 2 ] & 0x07 ) << 4 ) | ( V_1 [ 3 ] >> 4 ) ;
V_2 [ 4 ] = ( ( V_1 [ 3 ] & 0x0F ) << 3 ) | ( V_1 [ 4 ] >> 5 ) ;
V_2 [ 5 ] = ( ( V_1 [ 4 ] & 0x1F ) << 2 ) | ( V_1 [ 5 ] >> 6 ) ;
V_2 [ 6 ] = ( ( V_1 [ 5 ] & 0x3F ) << 1 ) | ( V_1 [ 6 ] >> 7 ) ;
V_2 [ 7 ] = V_1 [ 6 ] & 0x7F ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
V_2 [ V_3 ] = ( V_2 [ V_3 ] << 1 ) ;
}
static int
F_2 ( unsigned char * V_4 , const unsigned char * V_5 , unsigned char * V_2 )
{
unsigned char V_6 [ 8 ] ;
struct V_7 * V_8 ;
F_1 ( V_2 , V_6 ) ;
V_8 = F_3 ( L_1 , 0 , 0 ) ;
if ( F_4 ( V_8 ) ) {
F_5 ( V_9 , L_2 ) ;
return F_6 ( V_8 ) ;
}
F_7 ( V_8 , V_6 , 8 ) ;
F_8 ( V_8 , V_4 , V_5 ) ;
F_9 ( V_8 ) ;
return 0 ;
}
static int
F_10 ( unsigned char * V_10 , unsigned char * V_11 )
{
int V_12 ;
unsigned char V_13 [ 8 ] =
{ 0x4b , 0x47 , 0x53 , 0x21 , 0x40 , 0x23 , 0x24 , 0x25 } ;
V_12 = F_2 ( V_11 , V_13 , V_10 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_2 ( V_11 + 8 , V_13 , V_10 + 7 ) ;
return V_12 ;
}
static int
F_11 ( unsigned char * V_14 , const unsigned char * V_15 , unsigned char * V_16 )
{
int V_12 ;
V_12 = F_2 ( V_16 , V_15 , V_14 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_2 ( V_16 + 8 , V_15 , V_14 + 7 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_2 ( V_16 + 16 , V_15 , V_14 + 14 ) ;
return V_12 ;
}
int
F_12 ( unsigned char * V_17 , unsigned char * V_18 , int V_19 )
{
int V_12 ;
unsigned int V_20 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
V_22 = F_13 ( L_3 , 0 , 0 ) ;
if ( F_4 ( V_22 ) ) {
V_12 = F_6 ( V_22 ) ;
F_5 ( V_9 , L_4 ,
V_25 , V_12 ) ;
return V_12 ;
}
V_20 = sizeof( struct V_26 ) + F_14 ( V_22 ) ;
V_24 = F_15 ( V_20 , V_27 ) ;
if ( ! V_24 ) {
V_12 = - V_28 ;
goto V_29;
}
V_24 -> V_30 . V_31 = V_22 ;
V_24 -> V_30 . V_32 = 0x0 ;
V_12 = F_16 ( & V_24 -> V_30 ) ;
if ( V_12 ) {
F_5 ( V_9 , L_5 , V_25 ) ;
goto V_29;
}
V_12 = F_17 ( & V_24 -> V_30 , V_18 , V_19 ) ;
if ( V_12 ) {
F_5 ( V_9 , L_6 , V_25 ) ;
goto V_29;
}
V_12 = F_18 ( & V_24 -> V_30 , V_17 ) ;
if ( V_12 )
F_5 ( V_9 , L_7 , V_25 ) ;
V_29:
F_19 ( V_22 ) ;
F_20 ( V_24 ) ;
return V_12 ;
}
int
F_21 ( unsigned char * V_33 , const unsigned char * V_15 , unsigned char * V_16 )
{
int V_12 ;
unsigned char V_10 [ 14 ] , V_11 [ 16 ] , V_14 [ 21 ] ;
memset ( V_10 , '\0' , 14 ) ;
memset ( V_11 , '\0' , 16 ) ;
memset ( V_14 , '\0' , 21 ) ;
memcpy ( V_10 , V_33 , 14 ) ;
V_12 = F_10 ( V_10 , V_11 ) ;
if ( V_12 )
return V_12 ;
memcpy ( V_14 , V_11 , 16 ) ;
V_12 = F_11 ( V_14 , V_15 , V_16 ) ;
return V_12 ;
}
int
F_22 ( const unsigned char * V_33 , unsigned char * V_11 ,
const struct V_34 * V_35 )
{
int V_12 ;
int V_36 ;
T_1 V_37 [ 129 ] ;
if ( V_33 )
V_36 = F_23 ( V_37 , V_33 , 128 , V_35 ) ;
else {
V_36 = 0 ;
* V_37 = 0 ;
}
V_12 = F_12 ( V_11 , ( unsigned char * ) V_37 , V_36 * sizeof( T_1 ) ) ;
F_24 ( V_37 , sizeof( V_37 ) ) ;
return V_12 ;
}
int
F_25 ( unsigned char * V_33 , unsigned char * V_15 , unsigned char * V_16 ,
const struct V_34 * V_35 )
{
int V_12 ;
unsigned char V_11 [ 16 ] , V_14 [ 21 ] ;
memset ( V_11 , '\0' , 16 ) ;
memset ( V_14 , '\0' , 21 ) ;
V_12 = F_22 ( V_33 , V_11 , V_35 ) ;
if ( V_12 ) {
F_5 ( V_38 , L_8 ,
V_25 , V_12 ) ;
return V_12 ;
}
memcpy ( V_14 , V_11 , 16 ) ;
V_12 = F_11 ( V_14 , V_15 , V_16 ) ;
return V_12 ;
}
