static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
unsigned char * V_4 = V_1 -> V_4 ;
unsigned char V_5 = 0 ;
int V_6 [ 6 ] ;
int V_7 ;
if ( V_1 -> V_8 < 2 ) return;
for ( V_7 = 0 ; V_7 < V_1 -> V_8 ; V_7 ++ ) V_5 ^= V_4 [ V_7 ] ;
if ( V_5 ) return;
switch ( V_4 [ 0 ] ) {
case 'R' :
V_1 -> V_4 [ V_1 -> V_8 - 1 ] = 0 ;
for ( V_7 = 1 ; V_7 < V_1 -> V_8 && V_1 -> V_4 [ V_7 ] == ' ' ; V_7 ++ ) ;
F_2 ( V_9 L_1 ,
V_3 -> V_10 , V_1 -> V_4 + V_7 , V_1 -> V_11 ) ;
break;
case 'D' :
if ( V_1 -> V_8 != 12 ) return;
for ( V_7 = 0 ; V_7 < 9 ; V_7 ++ ) V_1 -> V_4 [ V_7 + 2 ] ^= V_12 [ V_7 ] ;
V_6 [ 0 ] = ( V_4 [ 2 ] << 3 ) | ( V_4 [ 3 ] >> 4 ) ;
V_6 [ 1 ] = ( ( V_4 [ 3 ] & 0x0f ) << 6 ) | ( V_4 [ 4 ] >> 1 ) ;
V_6 [ 2 ] = ( ( V_4 [ 4 ] & 0x01 ) << 9 ) | ( V_4 [ 5 ] << 2 ) | ( V_4 [ 4 ] >> 5 ) ;
V_6 [ 3 ] = ( ( V_4 [ 6 ] & 0x1f ) << 5 ) | ( V_4 [ 7 ] >> 2 ) ;
V_6 [ 4 ] = ( ( V_4 [ 7 ] & 0x03 ) << 8 ) | ( V_4 [ 8 ] << 1 ) | ( V_4 [ 7 ] >> 6 ) ;
V_6 [ 5 ] = ( ( V_4 [ 9 ] & 0x3f ) << 4 ) | ( V_4 [ 10 ] >> 3 ) ;
for ( V_7 = 0 ; V_7 < 6 ; V_7 ++ )
F_3 ( V_3 , V_13 [ V_7 ] , V_6 [ V_7 ] - ( ( V_6 [ V_7 ] & 0x200 ) ? 1024 : 0 ) ) ;
for ( V_7 = 0 ; V_7 < 6 ; V_7 ++ )
F_4 ( V_3 , V_14 [ V_7 ] , ( V_4 [ 1 ] >> V_7 ) & 1 ) ;
break;
case 'K' :
if ( V_1 -> V_8 != 5 ) return;
for ( V_7 = 0 ; V_7 < 6 ; V_7 ++ )
F_4 ( V_3 , V_14 [ V_7 ] , ( V_4 [ 2 ] >> V_7 ) & 1 ) ;
break;
case 'E' :
if ( V_1 -> V_8 != 4 ) return;
F_2 ( V_15 L_2 ) ;
for ( V_7 = 0 ; V_7 < 7 ; V_7 ++ ) if ( V_4 [ 1 ] & ( 1 << V_7 ) ) F_2 ( L_3 , V_16 [ V_7 ] ) ;
F_2 ( L_4 ) ;
break;
}
F_5 ( V_3 ) ;
}
static T_1 F_6 ( struct V_17 * V_17 ,
unsigned char V_4 , unsigned int V_18 )
{
struct V_1 * V_1 = F_7 ( V_17 ) ;
if ( ~ V_4 & 0x80 ) {
if ( V_1 -> V_8 ) F_1 ( V_1 ) ;
V_1 -> V_8 = 0 ;
}
if ( V_1 -> V_8 < V_19 )
V_1 -> V_4 [ V_1 -> V_8 ++ ] = V_4 & 0x7f ;
return V_20 ;
}
static void F_8 ( struct V_17 * V_17 )
{
struct V_1 * V_1 = F_7 ( V_17 ) ;
F_9 ( V_17 ) ;
F_10 ( V_17 , NULL ) ;
F_11 ( V_1 -> V_3 ) ;
F_12 ( V_1 ) ;
}
static int F_13 ( struct V_17 * V_17 , struct V_21 * V_22 )
{
struct V_1 * V_1 ;
struct V_2 * V_2 ;
int V_23 = - V_24 ;
int V_7 ;
V_1 = F_14 ( sizeof( struct V_1 ) , V_25 ) ;
V_2 = F_15 () ;
if ( ! V_1 || ! V_2 )
goto V_26;
V_1 -> V_3 = V_2 ;
snprintf ( V_1 -> V_11 , sizeof( V_1 -> V_11 ) , L_5 , V_17 -> V_11 ) ;
V_2 -> V_10 = L_6 ;
V_2 -> V_11 = V_1 -> V_11 ;
V_2 -> V_27 . V_28 = V_29 ;
V_2 -> V_27 . V_30 = V_31 ;
V_2 -> V_27 . V_32 = 0x0001 ;
V_2 -> V_27 . V_33 = 0x0100 ;
V_2 -> V_3 . V_34 = & V_17 -> V_3 ;
V_2 -> V_35 [ 0 ] = F_16 ( V_36 ) | F_16 ( V_37 ) ;
for ( V_7 = 0 ; V_7 < 6 ; V_7 ++ )
F_17 ( V_14 [ V_7 ] , V_2 -> V_38 ) ;
for ( V_7 = 0 ; V_7 < 6 ; V_7 ++ )
F_18 ( V_2 , V_13 [ V_7 ] , - 508 , 508 , 0 , 0 ) ;
F_10 ( V_17 , V_1 ) ;
V_23 = F_19 ( V_17 , V_22 ) ;
if ( V_23 )
goto V_39;
V_23 = F_20 ( V_1 -> V_3 ) ;
if ( V_23 )
goto V_40;
return 0 ;
V_40: F_9 ( V_17 ) ;
V_39: F_10 ( V_17 , NULL ) ;
V_26: F_21 ( V_2 ) ;
F_12 ( V_1 ) ;
return V_23 ;
}
