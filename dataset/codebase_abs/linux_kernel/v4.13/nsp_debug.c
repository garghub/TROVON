static void F_1 ( unsigned char V_1 )
{
const char * * V_2 = V_3 [ F_2 ( V_1 ) ] ;
switch ( ( unsigned long ) V_2 ) {
case V_4 :
F_3 ( L_1 , V_5 , V_1 ) ;
break;
case V_6 :
F_3 ( L_2 , V_7 , V_1 ) ;
break;
case V_8 :
F_3 ( L_1 , V_9 , V_1 ) ;
break;
default:
if ( V_2 [ V_1 & 0x1f ] != V_7 )
F_3 ( L_1 , V_2 [ V_1 & 0x1f ] , V_1 ) ;
else
F_3 ( L_1 , V_7 , V_1 ) ;
break;
}
}
static void F_4 ( unsigned char * V_10 )
{
int V_11 , V_12 ;
F_3 ( V_13 ) ;
F_1 ( V_10 [ 0 ] ) ;
if ( ( V_10 [ 0 ] >> 5 ) == 6 ||
( V_10 [ 0 ] >> 5 ) == 7 ) {
V_12 = 12 ;
} else {
V_12 = F_5 ( V_10 [ 0 ] ) ;
}
for ( V_11 = 1 ; V_11 < V_12 ; ++ V_11 ) {
F_3 ( L_3 , V_10 [ V_11 ] ) ;
}
switch ( V_12 ) {
case 6 :
F_3 ( L_4 ,
( ( ( unsigned int ) V_10 [ 1 ] & 0x0f ) << 16 ) |
( ( unsigned int ) V_10 [ 2 ] << 8 ) |
( ( unsigned int ) V_10 [ 3 ] ) ,
( unsigned int ) V_10 [ 4 ]
) ;
break;
case 10 :
F_3 ( L_4 ,
( ( unsigned int ) V_10 [ 2 ] << 24 ) |
( ( unsigned int ) V_10 [ 3 ] << 16 ) |
( ( unsigned int ) V_10 [ 4 ] << 8 ) |
( ( unsigned int ) V_10 [ 5 ] ) ,
( ( unsigned int ) V_10 [ 7 ] << 8 ) |
( ( unsigned int ) V_10 [ 8 ] )
) ;
break;
case 12 :
F_3 ( L_4 ,
( ( unsigned int ) V_10 [ 2 ] << 24 ) |
( ( unsigned int ) V_10 [ 3 ] << 16 ) |
( ( unsigned int ) V_10 [ 4 ] << 8 ) |
( ( unsigned int ) V_10 [ 5 ] ) ,
( ( unsigned int ) V_10 [ 6 ] << 24 ) |
( ( unsigned int ) V_10 [ 7 ] << 16 ) |
( ( unsigned int ) V_10 [ 8 ] << 8 ) |
( ( unsigned int ) V_10 [ 9 ] )
) ;
break;
default:
break;
}
F_3 ( L_5 ) ;
}
static void F_6 ( struct V_14 * V_15 )
{
F_4 ( V_15 -> V_16 ) ;
}
static void F_7 ( struct V_14 * V_15 )
{
int V_11 = V_15 -> V_17 . V_18 ;
char * V_19 [] = {
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 ,
L_11 ,
L_12 ,
L_13 ,
L_14 ,
L_15 ,
L_16
} ;
if ( V_11 < V_20 || V_11 > V_21 ) {
F_3 ( V_13 L_17 , V_11 ) ;
return;
}
F_3 ( V_13 L_18 , V_19 [ V_11 ] ) ;
return;
}
static void F_8 ( unsigned char V_22 )
{
switch( V_22 ) {
case V_23 :
F_3 ( V_13 L_19 ) ;
break;
case V_24 :
F_3 ( V_13 L_20 ) ;
break;
case V_25 :
F_3 ( V_13 L_21 ) ;
break;
case V_26 :
F_3 ( V_13 L_22 ) ;
break;
case V_27 :
F_3 ( V_13 L_23 ) ;
break;
case V_28 :
F_3 ( V_13 L_24 ) ;
break;
case V_29 :
F_3 ( V_13 L_25 ) ;
break;
default:
F_3 ( V_13 L_26 ) ;
break;
}
}
static void F_9 ( T_1 * V_30 )
{
int V_11 ;
F_3 ( V_13 L_27 ) ;
for( V_11 = 0 ; V_11 < V_30 -> V_31 ; V_11 ++ ) {
F_3 ( L_28 , V_30 -> V_32 [ V_11 ] ) ;
}
F_3 ( L_5 ) ;
}
