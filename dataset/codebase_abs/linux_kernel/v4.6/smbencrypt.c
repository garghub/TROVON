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
int V_6 ;
unsigned char V_7 [ 8 ] ;
struct V_8 * V_9 ;
struct V_10 V_11 , V_12 ;
struct V_13 * V_14 ;
F_1 ( V_2 , V_7 ) ;
V_9 = F_3 ( L_1 , 0 , V_15 ) ;
if ( F_4 ( V_9 ) ) {
V_6 = F_5 ( V_9 ) ;
F_6 ( V_16 , L_2 ) ;
goto V_17;
}
V_14 = F_7 ( V_9 , V_18 ) ;
if ( ! V_14 ) {
V_6 = - V_19 ;
F_6 ( V_16 , L_2 ) ;
goto V_20;
}
F_8 ( V_9 , V_7 , 8 ) ;
F_9 ( & V_11 , V_5 , 8 ) ;
F_9 ( & V_12 , V_4 , 8 ) ;
F_10 ( V_14 , 0 , NULL , NULL ) ;
F_11 ( V_14 , & V_11 , & V_12 , 8 , NULL ) ;
V_6 = F_12 ( V_14 ) ;
if ( V_6 )
F_6 ( V_16 , L_3 , V_6 ) ;
F_13 ( V_14 ) ;
V_20:
F_14 ( V_9 ) ;
V_17:
return V_6 ;
}
static int
F_15 ( unsigned char * V_21 , unsigned char * V_22 )
{
int V_6 ;
unsigned char V_23 [ 8 ] =
{ 0x4b , 0x47 , 0x53 , 0x21 , 0x40 , 0x23 , 0x24 , 0x25 } ;
V_6 = F_2 ( V_22 , V_23 , V_21 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_2 ( V_22 + 8 , V_23 , V_21 + 7 ) ;
return V_6 ;
}
static int
F_16 ( unsigned char * V_24 , const unsigned char * V_25 , unsigned char * V_26 )
{
int V_6 ;
V_6 = F_2 ( V_26 , V_25 , V_24 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_2 ( V_26 + 8 , V_25 , V_24 + 7 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_2 ( V_26 + 16 , V_25 , V_24 + 14 ) ;
return V_6 ;
}
int
F_17 ( unsigned char * V_27 , unsigned char * V_28 , int V_29 )
{
int V_6 ;
unsigned int V_30 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
V_32 = F_18 ( L_4 , 0 , 0 ) ;
if ( F_4 ( V_32 ) ) {
V_6 = F_5 ( V_32 ) ;
F_6 ( V_16 , L_5 ,
V_35 , V_6 ) ;
return V_6 ;
}
V_30 = sizeof( struct V_36 ) + F_19 ( V_32 ) ;
V_34 = F_20 ( V_30 , V_18 ) ;
if ( ! V_34 ) {
V_6 = - V_19 ;
goto V_37;
}
V_34 -> V_38 . V_39 = V_32 ;
V_34 -> V_38 . V_40 = 0x0 ;
V_6 = F_21 ( & V_34 -> V_38 ) ;
if ( V_6 ) {
F_6 ( V_16 , L_6 , V_35 ) ;
goto V_37;
}
V_6 = F_22 ( & V_34 -> V_38 , V_28 , V_29 ) ;
if ( V_6 ) {
F_6 ( V_16 , L_7 , V_35 ) ;
goto V_37;
}
V_6 = F_23 ( & V_34 -> V_38 , V_27 ) ;
if ( V_6 )
F_6 ( V_16 , L_8 , V_35 ) ;
V_37:
F_24 ( V_32 ) ;
F_25 ( V_34 ) ;
return V_6 ;
}
int
F_26 ( unsigned char * V_41 , const unsigned char * V_25 , unsigned char * V_26 )
{
int V_6 ;
unsigned char V_21 [ 14 ] , V_22 [ 16 ] , V_24 [ 21 ] ;
memset ( V_21 , '\0' , 14 ) ;
memset ( V_22 , '\0' , 16 ) ;
memset ( V_24 , '\0' , 21 ) ;
memcpy ( V_21 , V_41 , 14 ) ;
V_6 = F_15 ( V_21 , V_22 ) ;
if ( V_6 )
return V_6 ;
memcpy ( V_24 , V_22 , 16 ) ;
V_6 = F_16 ( V_24 , V_25 , V_26 ) ;
return V_6 ;
}
int
F_27 ( const unsigned char * V_41 , unsigned char * V_22 ,
const struct V_42 * V_43 )
{
int V_6 ;
int V_44 ;
T_1 V_45 [ 129 ] ;
if ( V_41 )
V_44 = F_28 ( V_45 , V_41 , 128 , V_43 ) ;
else {
V_44 = 0 ;
* V_45 = 0 ;
}
V_6 = F_17 ( V_22 , ( unsigned char * ) V_45 , V_44 * sizeof( T_1 ) ) ;
F_29 ( V_45 , sizeof( V_45 ) ) ;
return V_6 ;
}
int
F_30 ( unsigned char * V_41 , unsigned char * V_25 , unsigned char * V_26 ,
const struct V_42 * V_43 )
{
int V_6 ;
unsigned char V_22 [ 16 ] , V_24 [ 21 ] ;
memset ( V_22 , '\0' , 16 ) ;
memset ( V_24 , '\0' , 21 ) ;
V_6 = F_27 ( V_41 , V_22 , V_43 ) ;
if ( V_6 ) {
F_6 ( V_46 , L_9 ,
V_35 , V_6 ) ;
return V_6 ;
}
memcpy ( V_24 , V_22 , 16 ) ;
V_6 = F_16 ( V_24 , V_25 , V_26 ) ;
return V_6 ;
}
