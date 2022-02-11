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
static void F_6 ( T_1 * V_13 )
{
F_4 ( V_13 -> V_14 ) ;
}
static void F_7 ( unsigned char V_15 )
{
switch( V_15 ) {
case V_16 :
F_3 ( L_6 ) ;
break;
case V_17 :
F_3 ( L_7 ) ;
break;
case V_18 :
F_3 ( L_8 ) ;
break;
case V_19 :
F_3 ( L_9 ) ;
break;
case V_20 :
F_3 ( L_10 ) ;
break;
case V_21 :
F_3 ( L_11 ) ;
break;
case V_22 :
F_3 ( L_12 ) ;
break;
default:
F_3 ( L_13 , V_15 ) ;
break;
}
}
static void F_8 ( unsigned short V_11 )
{
F_3 ( L_14 , V_11 ) ;
if( V_11 & V_23 ) {
F_3 ( L_15 ) ;
}
if( V_11 & V_24 ) {
F_3 ( L_16 ) ;
}
if( V_11 & V_25 ) {
F_3 ( L_17 ) ;
}
if( V_11 & V_26 ) {
F_3 ( L_18 ) ;
}
if( V_11 & V_27 ) {
F_3 ( L_19 ) ;
}
if( V_11 & V_28 ) {
F_3 ( L_20 ) ;
}
if( V_11 & V_29 ) {
F_3 ( L_21 ) ;
}
if( V_11 & V_30 ) {
F_3 ( L_22 ) ;
}
if( V_11 & V_31 ) {
F_3 ( L_23 ) ;
}
if( V_11 & V_32 ) {
F_3 ( L_24 ) ;
}
if( V_11 & V_33 ) {
F_3 ( L_25 ) ;
}
if( V_11 & V_34 ) {
F_3 ( L_26 ) ;
}
if( V_11 & V_35 ) {
F_3 ( L_27 ) ;
}
if( V_11 & V_36 ) {
F_3 ( L_28 ) ;
}
if( V_11 & V_37 ) {
F_3 ( L_29 ) ;
}
F_3 ( L_5 ) ;
}
static void F_9 ( int V_38 )
{
if ( ! ( V_39 & V_40 ) )
return;
F_3 ( L_30 , F_10 ( V_38 , V_41 ) ) ;
F_3 ( L_31 , F_11 ( V_38 , V_42 ) ) ;
F_3 ( L_32 , F_10 ( V_38 , V_43 ) ) ;
F_3 ( L_33 , F_10 ( V_38 , V_44 ) ) ;
F_3 ( L_34 , F_12 ( V_38 , V_45 ) ) ;
F_3 ( L_35 , F_10 ( V_38 , V_46 ) ) ;
F_3 ( L_36 , F_12 ( V_38 , V_47 ) ) ;
F_3 ( L_37 , F_13 ( V_38 , V_48 ) ) ;
F_3 ( L_38 , F_14 ( V_38 , V_49 ) ) ;
F_3 ( L_39 , F_10 ( V_38 , V_50 ) ) ;
F_3 ( L_40 , F_14 ( V_38 , V_51 ) ) ;
F_3 ( L_41 , F_14 ( V_38 , V_52 ) ) ;
F_3 ( L_42 , F_10 ( V_38 , V_53 ) ) ;
F_3 ( L_43 , F_12 ( V_38 , V_54 ) ) ;
F_3 ( L_44 , F_12 ( V_38 , V_55 ) ) ;
F_3 ( L_45 , F_12 ( V_38 , V_56 ) ) ;
F_3 ( L_46 , F_12 ( V_38 , V_57 ) ) ;
F_3 ( L_47 , F_12 ( V_38 , V_58 ) ) ;
F_3 ( L_48 , F_10 ( V_38 , V_59 ) ) ;
F_3 ( L_49 , F_14 ( V_38 , V_60 ) ) ;
F_3 ( L_50 , F_10 ( V_38 , V_61 ) ) ;
F_3 ( L_5 ) ;
if ( 0 ) {
F_3 ( L_51 , F_14 ( V_38 , V_62 ) ) ;
F_3 ( L_52 , F_14 ( V_38 , V_63 ) ) ;
F_3 ( L_5 ) ;
}
}
