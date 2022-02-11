static int F_1 ( unsigned char * V_1 , int V_2 )
{
static unsigned char V_3 [ 16 ] = L_1 ;
do {
if ( V_1 [ V_2 ] == V_3 [ V_1 [ V_2 ] & 0xf ] )
V_1 [ V_2 ] = V_1 [ V_2 ] & 0xf ;
else
return - 1 ;
} while ( -- V_2 );
return 0 ;
}
static void F_2 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned char * V_1 = V_4 -> V_1 ;
int V_7 , V_8 ;
if ( ! V_4 -> V_9 ) return;
switch ( V_4 -> V_1 [ 0 ] ) {
case 'd' :
if ( V_4 -> V_9 != 25 ) return;
if ( F_1 ( V_1 , 24 ) ) return;
for ( V_7 = 0 ; V_7 < 6 ; V_7 ++ )
F_3 ( V_6 , V_10 [ V_7 ] ,
( V_1 [ ( V_7 << 2 ) + 1 ] << 12 | V_1 [ ( V_7 << 2 ) + 2 ] << 8 |
V_1 [ ( V_7 << 2 ) + 3 ] << 4 | V_1 [ ( V_7 << 2 ) + 4 ] ) - 32768 ) ;
break;
case 'k' :
if ( V_4 -> V_9 != 4 ) return;
if ( F_1 ( V_1 , 3 ) ) return;
V_8 = ( V_1 [ 1 ] << 1 ) | ( V_1 [ 2 ] << 5 ) | V_1 [ 3 ] ;
for ( V_7 = 0 ; V_7 < 9 ; V_7 ++ ) F_4 ( V_6 , V_11 [ V_7 ] , ( V_8 >> V_7 ) & 1 ) ;
break;
}
F_5 ( V_6 ) ;
}
static T_1 F_6 ( struct V_12 * V_12 ,
unsigned char V_1 , unsigned int V_13 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
if ( V_1 == '\r' ) {
F_2 ( V_4 ) ;
V_4 -> V_9 = 0 ;
} else {
if ( V_4 -> V_9 < V_14 )
V_4 -> V_1 [ V_4 -> V_9 ++ ] = V_1 ;
}
return V_15 ;
}
static void F_8 ( struct V_12 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
F_9 ( V_12 ) ;
F_10 ( V_12 , NULL ) ;
F_11 ( V_4 -> V_6 ) ;
F_12 ( V_4 ) ;
}
static int F_13 ( struct V_12 * V_12 , struct V_16 * V_17 )
{
struct V_4 * V_4 ;
struct V_5 * V_5 ;
int V_18 = - V_19 ;
int V_7 ;
V_4 = F_14 ( sizeof( struct V_4 ) , V_20 ) ;
V_5 = F_15 () ;
if ( ! V_4 || ! V_5 )
goto V_21;
V_4 -> V_6 = V_5 ;
snprintf ( V_4 -> V_22 , sizeof( V_4 -> V_22 ) , L_2 , V_12 -> V_22 ) ;
V_5 -> V_23 = L_3 ;
V_5 -> V_22 = V_4 -> V_22 ;
V_5 -> V_24 . V_25 = V_26 ;
V_5 -> V_24 . V_27 = V_28 ;
V_5 -> V_24 . V_29 = 0x0001 ;
V_5 -> V_24 . V_30 = 0x0100 ;
V_5 -> V_6 . V_31 = & V_12 -> V_6 ;
V_5 -> V_32 [ 0 ] = F_16 ( V_33 ) | F_16 ( V_34 ) ;
for ( V_7 = 0 ; V_7 < 9 ; V_7 ++ )
F_17 ( V_11 [ V_7 ] , V_5 -> V_35 ) ;
for ( V_7 = 0 ; V_7 < 6 ; V_7 ++ )
F_18 ( V_5 , V_10 [ V_7 ] , - 360 , 360 , 0 , 0 ) ;
F_10 ( V_12 , V_4 ) ;
V_18 = F_19 ( V_12 , V_17 ) ;
if ( V_18 )
goto V_36;
V_18 = F_20 ( V_4 -> V_6 ) ;
if ( V_18 )
goto V_37;
return 0 ;
V_37: F_9 ( V_12 ) ;
V_36: F_10 ( V_12 , NULL ) ;
V_21: F_21 ( V_5 ) ;
F_12 ( V_4 ) ;
return V_18 ;
}
