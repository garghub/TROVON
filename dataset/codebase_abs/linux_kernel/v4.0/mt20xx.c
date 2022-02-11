static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_3 ;
* V_4 = V_6 -> V_4 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
int V_7 , int V_8 , int V_9 , int V_10 )
{
struct V_5 * V_6 = V_2 -> V_3 ;
int V_11 = 1 , V_12 , V_13 ;
V_7 = V_7 / 1000 ;
V_8 = V_8 / 1000 ;
V_9 /= 1000 ;
V_10 /= 1000 ;
F_5 ( L_1 ,
V_7 , V_8 , V_9 , V_10 ) ;
do {
V_12 = - V_11 ;
V_13 = V_11 * ( V_7 - V_8 ) ;
do {
V_12 -- ;
V_13 = V_13 - V_8 ;
F_5 ( L_2 , V_11 , V_12 , V_13 ) ;
if( ( V_13 > V_9 ) && ( V_13 < V_10 ) )
F_5 ( L_3 , V_11 ) ;
} while ( ( V_13 > ( V_8 - V_10 ) ) || ( V_12 > - 5 ) );
V_11 ++ ;
} while ( V_11 < 5 );
return 1 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_14 ,
unsigned int V_15 , unsigned int V_16 ,
unsigned int V_9 ,
unsigned int V_10 ,
unsigned char * V_17 ,
int * V_18 ,
unsigned int V_19 )
{
struct V_5 * V_6 = V_2 -> V_3 ;
unsigned int V_20 , V_21 , V_22 , V_23 , V_24 , V_25 , V_26 , V_27 ,
V_28 , V_29 , V_30 , V_31 , V_32 , V_33 ;
V_20 = 5250 * 1000 ;
V_27 = V_14 + V_15 ;
V_21 = ( 2 * ( V_27 / 1000 ) + ( V_20 / 1000 ) ) / ( 2 * V_20 / 1000 ) ;
V_22 = V_21 / 8 ;
V_23 = V_21 - ( V_22 * 8 ) ;
V_24 = V_14 / 1000 / 1000 + 1090 ;
if( V_34 ) {
if( V_24 > 1890 ) V_25 = 0 ;
else if( V_24 > 1720 ) V_25 = 1 ;
else if( V_24 > 1530 ) V_25 = 2 ;
else if( V_24 > 1370 ) V_25 = 3 ;
else V_25 = 4 ;
}
else {
if( V_24 > 1790 ) V_25 = 0 ;
else if( V_24 > 1617 ) V_25 = 1 ;
else if( V_24 > 1449 ) V_25 = 2 ;
else if( V_24 > 1291 ) V_25 = 3 ;
else V_25 = 4 ;
}
* V_18 = V_25 ;
V_26 = ( V_23 + 8 * V_22 ) * V_20 ;
F_5 ( L_4 ,
V_14 , V_21 , V_22 , V_23 , V_25 , V_26 ) ;
V_28 = V_26 - V_14 - V_16 ;
V_29 = ( V_28 ) / V_20 ;
V_30 = V_29 / 8 ;
V_31 = V_29 - ( V_30 * 8 ) ;
V_32 = ( ( V_28 / 1000 ) % ( V_20 / 1000 ) ) * 3780 / ( V_20 / 1000 ) ;
V_33 = ( V_31 + 8 * V_30 ) * V_20 + V_32 * ( V_20 / 1000 ) / 3780 * 1000 ;
F_5 ( L_5 ,
V_14 , V_29 , V_30 , V_31 , V_32 , V_33 ) ;
if ( V_23 > 7 || V_22 < 17 || V_22 > 48 || V_31 > 7 || V_30 < 17 ||
V_30 > 30 ) {
F_7 ( L_6 ,
V_23 , V_22 , V_31 , V_30 ) ;
return ( - 1 ) ;
}
F_4 ( V_2 , V_26 , V_28 , V_9 , V_10 ) ;
V_17 [ 0 ] = V_22 - 1 ;
V_17 [ 1 ] = V_23 | ( V_25 << 4 ) ;
V_17 [ 2 ] = 0x86 ;
V_17 [ 3 ] = 0x0f ;
V_17 [ 4 ] = 0x1f ;
V_17 [ 5 ] = ( V_30 - 1 ) | ( V_31 << 5 ) ;
if( V_14 > 400 * 1000 * 1000 )
V_17 [ 6 ] = 0xe4 ;
else
V_17 [ 6 ] = 0xf4 ;
V_17 [ 7 ] = 8 + V_19 ;
V_17 [ 8 ] = 0xc3 ;
V_17 [ 9 ] = 0x4e ;
V_17 [ 10 ] = 0xec ;
V_17 [ 11 ] = ( V_32 & 0xff ) ;
V_17 [ 12 ] = ( V_32 >> 8 ) | 0x80 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_3 ;
int V_35 , V_36 = 0 ;
unsigned char V_17 [ 2 ] ;
for( V_35 = 0 ; V_35 < 10 ; V_35 ++ ) {
V_17 [ 0 ] = 0x0e ;
F_9 ( & V_6 -> V_37 , V_17 , 1 ) ;
F_10 ( & V_6 -> V_37 , V_17 , 1 ) ;
F_5 ( L_7 , V_17 [ 0 ] ) ;
V_36 = V_17 [ 0 ] & 0x06 ;
if ( V_36 == 6 )
break;
F_5 ( L_8 , V_17 [ 0 ] ) ;
F_11 ( 1000 ) ;
}
return V_36 ;
}
static int F_12 ( struct V_1 * V_2 , int V_25 , int V_36 )
{
struct V_5 * V_6 = V_2 -> V_3 ;
unsigned char V_17 [ 2 ] ;
int V_38 ;
V_17 [ 0 ] = 0x0f ;
F_9 ( & V_6 -> V_37 , V_17 , 1 ) ;
F_10 ( & V_6 -> V_37 , V_17 , 1 ) ;
F_5 ( L_9 , V_17 [ 0 ] ) ;
V_38 = V_17 [ 0 ] & 0x07 ;
if( V_38 == 0 ) return V_36 ;
if( V_38 == 1 ) return V_36 ;
if( V_38 == 2 ) {
if( V_25 == 0 )
return V_36 ;
else V_25 -- ;
}
else {
if( V_25 < 4 )
V_25 ++ ;
else
return V_36 ;
}
F_5 ( L_10 , V_25 ) ;
V_17 [ 0 ] = 0x0f ;
V_17 [ 1 ] = V_25 ;
F_9 ( & V_6 -> V_37 , V_17 , 2 ) ;
V_36 = F_8 ( V_2 ) ;
return V_36 ;
}
static void F_13 ( struct V_1 * V_2 , unsigned int V_14 ,
unsigned int V_15 , unsigned int V_16 ,
unsigned int V_39 , unsigned int V_40 )
{
unsigned char V_17 [ 21 ] ;
int V_41 , V_42 , V_25 , V_36 = 0 ;
struct V_5 * V_6 = V_2 -> V_3 ;
F_5 ( L_11 ,
V_14 , V_15 , V_16 , V_39 , V_40 ) ;
V_17 [ 0 ] = 0 ;
V_42 = F_9 ( & V_6 -> V_37 , V_17 , 1 ) ;
F_10 ( & V_6 -> V_37 , V_17 , 21 ) ;
V_17 [ 0 ] = 0 ;
V_42 = F_6 ( V_2 , V_14 , V_15 , V_16 , V_39 , V_40 , & V_17 [ 1 ] , & V_25 , V_6 -> V_19 ) ;
if ( V_42 < 0 )
return;
V_17 [ 0 ] = 0 ;
V_42 = F_9 ( & V_6 -> V_37 , V_17 , 4 ) ;
V_17 [ 5 ] = 5 ;
V_42 = F_9 ( & V_6 -> V_37 , V_17 + 5 , 4 ) ;
V_17 [ 11 ] = 11 ;
V_42 = F_9 ( & V_6 -> V_37 , V_17 + 11 , 3 ) ;
if( V_42 != 3 )
F_14 ( L_12 , V_42 ) ;
for( V_41 = 0 ; V_41 < 2 ; V_41 ++ ) {
V_36 = F_8 ( V_2 ) ;
if( V_34 )
V_36 = F_12 ( V_2 , V_25 , V_36 ) ;
if( V_36 == 6 ) break;
F_5 ( L_13 ) ;
V_17 [ 0 ] = 7 ;
V_17 [ 1 ] = 0x80 + 8 + V_6 -> V_19 ;
F_9 ( & V_6 -> V_37 , V_17 , 2 ) ;
F_15 ( 10 ) ;
V_17 [ 1 ] = 8 + V_6 -> V_19 ;
F_9 ( & V_6 -> V_37 , V_17 , 2 ) ;
}
if ( V_36 != 6 )
F_14 ( L_14 ) ;
V_17 [ 0 ] = 2 ;
V_17 [ 1 ] = 0x20 ;
V_42 = F_9 ( & V_6 -> V_37 , V_17 , 2 ) ;
if ( V_42 != 2 )
F_14 ( L_15 , V_42 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
int V_16 , V_39 , V_40 ;
if ( V_44 -> V_45 & V_46 ) {
V_39 = 40750 * 1000 ;
V_40 = 46750 * 1000 ;
V_16 = 45750 * 1000 ;
} else {
V_39 = 32900 * 1000 ;
V_40 = 39900 * 1000 ;
V_16 = 38900 * 1000 ;
}
F_13 ( V_2 , V_44 -> V_4 * 62500 ,
1090 * 1000 * 1000 , V_16 , V_39 , V_40 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
struct V_5 * V_6 = V_2 -> V_3 ;
int V_16 ;
if ( V_44 -> V_45 & V_46 ) {
F_5 ( L_16 ) ;
V_16 = 41300 * 1000 ;
} else {
F_5 ( L_17 ) ;
V_16 = 33300 * 1000 ;
}
F_13 ( V_2 , V_44 -> V_4 * 125 / 2 ,
1085 * 1000 * 1000 , V_16 , V_16 , V_16 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
struct V_5 * V_6 = V_2 -> V_3 ;
int V_42 = - V_47 ;
switch ( V_44 -> V_48 ) {
case V_49 :
V_42 = F_17 ( V_2 , V_44 ) ;
V_6 -> V_4 = V_44 -> V_4 * 125 / 2 ;
break;
case V_50 :
case V_51 :
V_42 = F_16 ( V_2 , V_44 ) ;
V_6 -> V_4 = V_44 -> V_4 * 62500 ;
break;
}
return V_42 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_3 ;
unsigned char V_17 [ 21 ] ;
int V_42 , V_19 , V_52 = 0 ;
V_17 [ 1 ] = 2 ;
V_17 [ 2 ] = 0xff ;
V_17 [ 3 ] = 0x0f ;
V_17 [ 4 ] = 0x1f ;
V_42 = F_9 ( & V_6 -> V_37 , V_17 + 1 , 4 ) ;
V_17 [ 5 ] = 6 ;
V_17 [ 6 ] = 0xe4 ;
V_17 [ 7 ] = 0x8f ;
V_17 [ 8 ] = 0xc3 ;
V_17 [ 9 ] = 0x4e ;
V_17 [ 10 ] = 0xec ;
V_42 = F_9 ( & V_6 -> V_37 , V_17 + 5 , 6 ) ;
V_17 [ 12 ] = 13 ;
V_17 [ 13 ] = 0x32 ;
V_42 = F_9 ( & V_6 -> V_37 , V_17 + 12 , 2 ) ;
V_19 = 7 ;
do {
F_5 ( L_18 , V_19 & 0x07 ) ;
F_15 ( 10 ) ;
V_17 [ 0 ] = 0x0e ;
F_9 ( & V_6 -> V_37 , V_17 , 1 ) ;
F_10 ( & V_6 -> V_37 , V_17 , 1 ) ;
V_52 = V_17 [ 0 ] & 0x01 ;
F_5 ( L_19 , V_52 ) ;
if ( V_52 == 1 ) break;
V_19 -- ;
F_5 ( L_18 , V_19 & 0x07 ) ;
if ( V_19 == 3 ) {
V_19 = 4 ;
break;
}
V_17 [ 0 ] = 0x07 ;
V_17 [ 1 ] = 0x88 + V_19 ;
V_42 = F_9 ( & V_6 -> V_37 , V_17 , 2 ) ;
if ( V_42 != 2 )
F_14 ( L_15 , V_42 ) ;
} while ( V_52 != 1 );
V_6 -> V_19 = V_19 ;
memcpy ( & V_2 -> V_53 . V_54 , & V_55 , sizeof( struct V_56 ) ) ;
return ( 1 ) ;
}
static void F_20 ( struct V_1 * V_2 , unsigned char V_57 )
{
struct V_5 * V_6 = V_2 -> V_3 ;
unsigned char V_17 [ 2 ] ;
V_17 [ 0 ] = 6 ;
V_17 [ 1 ] = V_57 ? 0x11 : 0x10 ;
F_9 ( & V_6 -> V_37 , V_17 , 2 ) ;
F_5 ( L_20 , V_57 ) ;
}
static void F_21 ( struct V_1 * V_2 , unsigned int V_58 , unsigned int V_16 )
{
struct V_5 * V_6 = V_2 -> V_3 ;
unsigned int V_15 = 1218 * 1000 * 1000 ;
unsigned int V_59 , V_60 , V_21 , V_29 , V_61 , V_62 , V_63 , V_64 , V_65 , V_66 , V_67 , V_68 ;
int V_42 ;
unsigned char V_17 [ 6 ] ;
F_5 ( L_21 ,
V_58 , V_15 , V_16 ) ;
V_59 = V_58 + V_15 ;
V_59 = ( V_59 / 1000000 ) * 1000000 ;
V_60 = V_59 - V_58 - V_16 ;
V_60 = ( V_60 / 50000 ) * 50000 ;
V_21 = V_59 / 4000000 ;
V_29 = V_60 / 4000000 ;
V_61 = V_59 - ( V_21 * 4000000 ) ;
V_62 = V_60 - ( V_29 * 4000000 ) ;
V_63 = 4 * V_61 / 4000000 ;
V_64 = 4096 * ( V_62 / 1000 ) / 4000 ;
V_65 = ( V_21 / 12 ) - 1 ;
V_66 = V_21 - ( V_65 + 1 ) * 12 ;
V_67 = ( V_29 / 8 ) - 1 ;
V_68 = V_29 - ( V_67 + 1 ) * 8 ;
if ( V_69 > 1 ) {
F_5 ( L_22 , V_21 , V_29 ) ;
F_5 ( L_23 ,
V_63 , V_64 , V_65 , V_66 , V_67 , V_68 ) ;
}
V_17 [ 0 ] = 1 ;
V_17 [ 1 ] = 4 * V_66 + V_63 ;
if( V_58 < 275 * 1000 * 1000 ) V_17 [ 1 ] = V_17 [ 1 ] | 0x80 ;
V_17 [ 2 ] = V_65 ;
V_17 [ 3 ] = 32 * V_68 + V_64 / 256 ;
V_17 [ 4 ] = V_64 - ( V_64 / 256 ) * 256 ;
V_17 [ 5 ] = V_67 ;
if( V_64 != 0 ) V_17 [ 5 ] = V_17 [ 5 ] | 0x40 ;
if ( V_69 > 1 ) {
int V_70 ;
F_5 ( L_24 ) ;
for( V_70 = 0 ; V_70 < 6 ; V_70 ++ )
F_22 ( L_25 , V_17 [ V_70 ] ) ;
F_22 ( L_26 ) ;
}
V_42 = F_9 ( & V_6 -> V_37 , V_17 , 6 ) ;
if ( V_42 != 6 )
F_14 ( L_27 , V_42 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
unsigned int V_16 ;
if ( V_44 -> V_45 & V_46 ) {
V_16 = 45750 * 1000 ;
} else {
V_16 = 38900 * 1000 ;
}
if ( V_51 == V_44 -> V_48 ) {
V_16 = 36150 * 1000 ;
}
F_21 ( V_2 , V_44 -> V_4 * 62500 , V_16 ) ;
F_20 ( V_2 , V_71 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
struct V_5 * V_6 = V_2 -> V_3 ;
int V_16 ;
if ( V_44 -> V_45 & V_46 ) {
F_5 ( L_16 ) ;
V_16 = 41300 * 1000 ;
} else {
F_5 ( L_17 ) ;
V_16 = 33300 * 1000 ;
}
F_21 ( V_2 , V_44 -> V_4 * 125 / 2 , V_16 ) ;
F_20 ( V_2 , V_72 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
struct V_5 * V_6 = V_2 -> V_3 ;
int V_42 = - V_47 ;
switch ( V_44 -> V_48 ) {
case V_49 :
V_42 = F_24 ( V_2 , V_44 ) ;
V_6 -> V_4 = V_44 -> V_4 * 125 / 2 ;
break;
case V_50 :
case V_51 :
V_42 = F_23 ( V_2 , V_44 ) ;
V_6 -> V_4 = V_44 -> V_4 * 62500 ;
break;
}
return V_42 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_3 ;
unsigned char V_17 [ 2 ] ;
V_17 [ 0 ] = 6 ;
V_17 [ 1 ] = 0x10 ;
F_9 ( & V_6 -> V_37 , V_17 , 2 ) ;
V_17 [ 0 ] = 0x0f ;
V_17 [ 1 ] = 0x0f ;
F_9 ( & V_6 -> V_37 , V_17 , 2 ) ;
V_17 [ 0 ] = 0x0d ;
F_9 ( & V_6 -> V_37 , V_17 , 1 ) ;
F_10 ( & V_6 -> V_37 , V_17 , 1 ) ;
F_5 ( L_28 , V_17 [ 0 ] ) ;
memcpy ( & V_2 -> V_53 . V_54 , & V_73 , sizeof( struct V_56 ) ) ;
return 0 ;
}
struct V_1 * F_27 ( struct V_1 * V_2 ,
struct V_74 * V_75 ,
T_2 V_76 )
{
struct V_5 * V_6 = NULL ;
char * V_77 ;
unsigned char V_17 [ 21 ] ;
int V_78 ;
V_6 = F_28 ( sizeof( struct V_5 ) , V_79 ) ;
if ( V_6 == NULL )
return NULL ;
V_2 -> V_3 = V_6 ;
V_6 -> V_37 . V_80 = V_76 ;
V_6 -> V_37 . V_81 = V_75 ;
V_6 -> V_37 . V_77 = L_29 ;
memset ( V_17 , 0 , sizeof( V_17 ) ) ;
V_77 = L_30 ;
F_9 ( & V_6 -> V_37 , V_17 , 1 ) ;
F_10 ( & V_6 -> V_37 , V_17 , 21 ) ;
if ( V_69 ) {
int V_70 ;
F_5 ( L_31 ) ;
for( V_70 = 0 ; V_70 < 21 ; V_70 ++ ) {
F_22 ( L_32 , V_17 [ V_70 ] ) ;
if( ( ( V_70 + 1 ) % 8 ) == 0 ) F_22 ( L_33 ) ;
}
F_22 ( L_26 ) ;
}
V_78 = V_17 [ 0x11 ] << 8 | V_17 [ 0x12 ] ;
F_7 ( L_34 ,
V_78 , V_17 [ 0x13 ] , V_17 [ 0x14 ] ) ;
if ( V_17 [ 0x13 ] < F_29 ( V_82 ) &&
NULL != V_82 [ V_17 [ 0x13 ] ] )
V_77 = V_82 [ V_17 [ 0x13 ] ] ;
switch ( V_17 [ 0x13 ] ) {
case V_83 :
F_19 ( V_2 ) ;
break;
case V_84 :
F_26 ( V_2 ) ;
break;
default:
F_7 ( L_35 ,
V_77 ) ;
return NULL ;
}
F_30 ( V_2 -> V_53 . V_54 . V_85 . V_77 , V_77 ,
sizeof( V_2 -> V_53 . V_54 . V_85 . V_77 ) ) ;
F_7 ( L_36 , V_77 ) ;
return V_2 ;
}
