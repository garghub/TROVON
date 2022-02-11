T_1 F_1 ( T_2 * V_1 , T_2 * V_2 , T_2 * V_3 ,
T_3 V_4 , T_3 V_5 , T_3 V_6 , T_4 * V_7 ,
T_2 V_8 )
{
T_2 V_9 [ V_10 ] ;
T_2 V_11 [ V_10 ] ;
int V_12 ;
if ( V_5 != V_10 )
return FALSE ;
for ( V_12 = 0 ; V_12 < V_10 ; V_12 ++ )
V_13 . V_14 [ V_12 ] = 0 ;
F_2 ( V_13 . V_14 , V_2 ) ;
F_3 ( V_13 . V_15 , V_13 . V_14 ) ;
F_3 ( V_13 . V_16 , V_13 . V_15 ) ;
F_4 ( V_9 , V_13 . V_15 ) ;
if ( V_8 == V_17 ) {
F_5 ( V_2 , V_9 , V_1 , V_4 , V_3 , V_6 ) ;
} else {
F_6 ( V_2 , V_9 , V_1 , V_4 ) ;
}
if ( V_8 == V_17 )
{
return ( memcmp ( V_7 , & V_9 [ V_10 - sizeof( * V_7 ) ] , sizeof( * V_7 ) ) ? FALSE : TRUE ) ;
}
else if ( V_8 == V_18 )
{
if ( V_6 == 0 )
return ( memcmp ( V_7 , & V_9 [ V_10 - sizeof( * V_7 ) ] , sizeof( * V_7 ) ) ? FALSE : TRUE ) ;
{
F_4 ( V_11 , V_13 . V_16 ) ;
F_6 ( V_2 , V_11 , V_3 , V_6 ) ;
F_7 ( V_11 , V_9 ) ;
}
if ( memcmp ( V_7 , & V_11 [ V_10 - sizeof( * V_7 ) ] , sizeof( * V_7 ) ) == 0 )
{
F_8 ( V_9 , V_2 , V_3 , V_6 ) ;
return TRUE ;
}
}
return FALSE ;
}
static void F_3 ( T_2 * V_19 , const T_2 * V_20 )
{
int V_12 ;
T_2 V_21 = 0 ;
for ( V_12 = 0 ; V_12 < V_10 ; V_12 ++ )
{
V_19 [ V_12 ] = ( V_20 [ V_12 ] << 1 ) | V_21 ;
V_21 = ( V_20 [ V_12 ] & 0x80 ) ? 1 : 0 ;
}
if ( V_21 )
V_19 [ 0 ] ^= 0x87 ;
}
static void F_6 ( T_2 * V_2 , T_2 * V_22 , const T_2 * V_1 , T_5 V_4 )
{
F_5 ( V_2 , V_22 , V_1 , V_4 , NULL , 0 ) ;
}
static void F_5 ( T_2 * V_2 , T_2 * V_22 , const T_2 * V_1 , T_5 V_4 , const T_2 * V_3 , T_5 V_6 )
{
T_6 V_23 ;
T_2 * V_24 ;
T_2 * V_25 ;
T_5 V_26 = V_4 + V_6 ;
T_5 V_27 = V_26 ;
if ( V_26 & 0xf ) {
V_27 += 0x10 - ( V_27 & 0xf ) ;
}
V_24 = F_9 ( V_27 ) ;
if ( V_24 == NULL ) {
return;
}
memcpy ( V_24 , V_1 , V_4 ) ;
if ( V_3 != NULL ) {
memcpy ( & V_24 [ V_4 ] , V_3 , V_6 ) ;
}
if ( V_27 != V_26 ) {
V_24 [ V_26 ] = 0x80 ;
for ( V_25 = & V_24 [ V_26 + 1 ] ; V_25 < & V_24 [ V_27 ] ; V_25 ++ )
* V_25 = 0 ;
V_25 = & V_24 [ V_27 - 0x10 ] ;
F_7 ( V_25 , V_13 . V_16 ) ;
} else {
V_25 = & V_24 [ V_27 - 0x10 ] ;
F_7 ( V_25 , V_13 . V_15 ) ;
}
if ( F_10 ( & V_23 , V_28 , V_29 , 0 ) ) {
F_11 ( V_24 ) ;
return;
}
if ( F_12 ( V_23 , V_2 , V_10 ) ) {
F_11 ( V_24 ) ;
F_13 ( V_23 ) ;
return;
}
if ( F_14 ( V_23 , V_22 , V_10 ) ) {
F_11 ( V_24 ) ;
F_13 ( V_23 ) ;
return;
}
if ( F_15 ( V_23 , V_24 , V_27 , V_24 , V_27 ) ) {
F_11 ( V_24 ) ;
F_13 ( V_23 ) ;
return;
}
memcpy ( V_22 , V_25 , V_10 ) ;
F_11 ( V_24 ) ;
F_13 ( V_23 ) ;
return;
}
static void F_8 ( const T_2 * V_22 , T_2 * V_2 , T_2 * V_1 , T_5 V_4 )
{
T_6 V_23 ;
T_2 V_30 [ V_10 ] ;
F_4 ( V_30 , V_22 ) ;
V_30 [ 12 ] &= 0x7f ;
V_30 [ 14 ] &= 0x7f ;
if ( F_10 ( & V_23 , V_28 , V_31 , 0 ) ) {
return;
}
if ( F_12 ( V_23 , V_2 , V_10 ) ) {
F_13 ( V_23 ) ;
return;
}
if ( F_16 ( V_23 , V_30 , V_10 ) ) {
F_13 ( V_23 ) ;
return;
}
if ( F_15 ( V_23 , V_1 , V_4 , V_1 , V_4 ) ) {
F_13 ( V_23 ) ;
return;
}
F_13 ( V_23 ) ;
return;
}
void F_2 ( unsigned char V_32 [ V_10 ] , unsigned char V_33 [ V_10 ] )
{
T_6 V_23 ;
if ( F_10 ( & V_23 , V_28 , V_34 , 0 ) ) {
return;
}
if ( F_12 ( V_23 , V_33 , V_10 ) ) {
F_13 ( V_23 ) ;
return;
}
if ( F_15 ( V_23 , V_32 , V_10 , V_32 , V_10 ) ) {
F_13 ( V_23 ) ;
return;
}
F_13 ( V_23 ) ;
return;
}
