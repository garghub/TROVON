static unsigned short F_1 ( struct V_1 * V_2 , int V_3 )
{
V_3 <<= 1 ;
return ( ( unsigned short ) V_2 -> V_4 [ 0 ] . V_5 [ V_3 ] << 8 ) |
V_2 -> V_4 [ 0 ] . V_5 [ V_3 + 1 ] ;
}
static void F_2 ( struct V_1 * V_2 , int V_3 , unsigned short V_6 )
{
unsigned short V_7 ;
V_7 = ( V_3 << 9 ) | V_6 ;
F_3 ( V_2 , V_8 , V_7 >> 8 , V_7 & 0xff ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_3 , unsigned short V_6 )
{
F_2 ( V_2 , V_3 , V_6 ) ;
V_3 <<= 1 ;
V_2 -> V_4 [ 0 ] . V_5 [ V_3 ] = V_6 >> 8 ;
V_2 -> V_4 [ 0 ] . V_5 [ V_3 + 1 ] = V_6 ;
}
static void F_5 ( struct V_1 * V_2 , unsigned int V_9 , int V_6 )
{
unsigned int V_10 = F_6 ( V_2 ) ;
if ( V_6 )
V_10 |= V_9 ;
else
V_10 &= ~ V_9 ;
F_7 ( V_2 , V_10 ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned int V_11 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ ) {
F_5 ( V_2 , V_13 , 0 ) ;
F_9 ( 1 ) ;
F_5 ( V_2 , V_14 , V_11 & 0x8000 ) ;
F_9 ( 1 ) ;
F_5 ( V_2 , V_13 , 1 ) ;
F_9 ( 1 ) ;
V_11 <<= 1 ;
}
}
static void F_10 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_11 )
{
unsigned int V_15 ;
F_11 ( V_2 , V_14 |
V_13 | V_16 ) ;
F_12 ( V_2 , ~ ( V_14 |
V_13 | V_16 ) ) ;
F_5 ( V_2 , V_16 , 0 ) ;
V_15 = ( V_3 << 9 ) | ( V_11 & 0x1ff ) ;
F_8 ( V_2 , V_15 ) ;
F_5 ( V_2 , V_16 , 1 ) ;
F_9 ( 1 ) ;
F_12 ( V_2 , V_2 -> V_17 . V_18 ) ;
F_11 ( V_2 , V_2 -> V_17 . V_19 ) ;
}
static void F_13 ( struct V_1 * V_2 , unsigned int V_11 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ ) {
F_5 ( V_2 , V_20 , 0 ) ;
F_9 ( 1 ) ;
F_5 ( V_2 , V_21 , V_11 & 0x8000 ) ;
F_9 ( 1 ) ;
F_5 ( V_2 , V_20 , 1 ) ;
F_9 ( 1 ) ;
V_11 <<= 1 ;
}
}
static void F_14 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_11 )
{
unsigned int V_15 ;
F_11 ( V_2 , V_22 | V_20 | V_21 ) ;
F_12 ( V_2 , ~ ( V_22 | V_20 | V_21 ) ) ;
F_5 ( V_2 , V_22 , 0 ) ;
V_15 = ( ( V_23 & 0x03 ) << 14 ) | ( 1 << 13 ) |
( ( V_3 & 0x1f ) << 8 ) | ( V_11 & 0xff ) ;
F_13 ( V_2 , V_15 ) ;
F_5 ( V_2 , V_22 , 1 ) ;
F_9 ( 1 ) ;
F_12 ( V_2 , V_2 -> V_17 . V_18 ) ;
F_11 ( V_2 , V_2 -> V_17 . V_19 ) ;
}
static int F_15 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
V_27 -> type = V_28 ;
V_27 -> V_29 = 2 ;
V_27 -> V_30 . integer . V_31 = 0 ;
V_27 -> V_30 . integer . V_32 = 0xFF ;
return 0 ;
}
static int F_16 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
struct V_35 * V_36 = V_2 -> V_36 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ )
V_34 -> V_30 . integer . V_30 [ V_12 ] = V_36 -> V_37 [ V_12 ] ;
return 0 ;
}
static int F_18 ( struct V_24 * V_25 , struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
struct V_35 * V_36 = V_2 -> V_36 ;
int V_12 ;
int V_38 = 0 ;
F_19 ( & V_2 -> V_39 ) ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ ) {
if ( V_34 -> V_30 . integer . V_30 [ V_12 ] != V_36 -> V_37 [ V_12 ] ) {
V_36 -> V_37 [ V_12 ] = V_34 -> V_30 . integer . V_30 [ V_12 ] ;
F_14 ( V_2 , V_40 + V_12 ,
V_36 -> V_37 [ V_12 ] & 0xff ) ;
V_38 = 1 ;
}
}
F_20 ( & V_2 -> V_39 ) ;
return V_38 ;
}
static void F_21 ( struct V_1 * V_2 , unsigned int V_41 ,
unsigned short V_37 , unsigned short V_42 )
{
unsigned char V_43 ;
if ( ( V_42 & V_44 ) || ( V_37 & V_44 ) )
V_43 = 0 ;
else {
V_43 = ( ( ( V_37 & ~ V_44 ) * ( V_42 & ~ V_44 ) ) / 128 )
& V_45 ;
V_43 = ( V_43 ? ( V_43 + V_46 ) : 0 ) & 0xff ;
}
F_4 ( V_2 , V_41 , V_43 ) ;
F_2 ( V_2 , V_41 , 0x100 | V_43 ) ;
}
static void F_22 ( struct V_1 * V_2 , unsigned int V_41 ,
unsigned short V_37 , unsigned short V_42 )
{
unsigned char V_43 ;
if ( ( V_42 & V_44 ) || ( V_37 & V_44 ) )
V_43 = 0 ;
else {
V_43 = ( ( ( V_37 & ~ V_44 ) * ( V_42 & ~ V_44 ) ) / 128 )
& V_45 ;
V_43 = ( V_43 ? ( V_43 + V_46 ) : 0 ) & 0xff ;
}
F_10 ( V_2 , V_41 , ( 0x0100 | V_43 ) ) ;
}
static int F_23 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
V_27 -> type = V_28 ;
V_27 -> V_29 = 2 ;
V_27 -> V_30 . integer . V_31 = 0 ;
V_27 -> V_30 . integer . V_32 = V_47 ;
return 0 ;
}
static int F_24 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
struct V_35 * V_36 = V_2 -> V_36 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ )
V_34 -> V_30 . integer . V_30 [ V_12 ] =
V_36 -> V_37 [ 2 + V_12 ] & ~ V_44 ;
return 0 ;
}
static int F_25 ( struct V_24 * V_25 , struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
struct V_35 * V_36 = V_2 -> V_36 ;
int V_12 , V_48 , V_38 = 0 ;
F_19 ( & V_2 -> V_39 ) ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ ) {
if ( V_34 -> V_30 . integer . V_30 [ V_12 ] != V_36 -> V_37 [ 2 + V_12 ] ) {
V_48 = V_49 + V_12 ;
V_36 -> V_37 [ 2 + V_12 ] &= V_44 ;
V_36 -> V_37 [ 2 + V_12 ] |= V_34 -> V_30 . integer . V_30 [ V_12 ] ;
F_21 ( V_2 , V_48 , V_36 -> V_37 [ 2 + V_12 ] , V_36 -> V_42 [ V_12 ] ) ;
V_38 = 1 ;
}
}
F_20 ( & V_2 -> V_39 ) ;
return V_38 ;
}
static int F_26 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
int V_50 = V_25 -> V_51 >> 8 ;
V_27 -> type = V_28 ;
V_27 -> V_29 = V_50 ;
V_27 -> V_30 . integer . V_31 = 0 ;
V_27 -> V_30 . integer . V_32 = V_47 ;
return 0 ;
}
static int F_27 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
struct V_35 * V_36 = V_2 -> V_36 ;
int V_12 , V_52 , V_50 ;
V_50 = V_25 -> V_51 >> 8 ;
V_52 = V_25 -> V_51 & 0xff ;
for ( V_12 = 0 ; V_12 < V_50 ; V_12 ++ )
V_34 -> V_30 . integer . V_30 [ V_12 ] = V_36 -> V_37 [ V_52 + V_12 ] ;
return 0 ;
}
static int F_28 ( struct V_24 * V_25 , struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
struct V_35 * V_36 = V_2 -> V_36 ;
int V_12 , V_48 , V_52 , V_50 ;
int V_38 = 0 ;
V_50 = V_25 -> V_51 >> 8 ;
V_52 = V_25 -> V_51 & 0xff ;
F_19 ( & V_2 -> V_39 ) ;
for ( V_12 = 0 ; V_12 < V_50 ; V_12 ++ ) {
if ( V_34 -> V_30 . integer . V_30 [ V_12 ] != V_36 -> V_37 [ V_52 + V_12 ] ) {
V_48 = V_53 + V_52 + V_12 ;
V_36 -> V_37 [ V_52 + V_12 ] &= V_44 ;
V_36 -> V_37 [ V_52 + V_12 ] |= V_34 -> V_30 . integer . V_30 [ V_12 ] ;
F_22 ( V_2 , V_48 ,
V_36 -> V_37 [ V_52 + V_12 ] , V_36 -> V_42 [ V_12 ] ) ;
V_38 = 1 ;
}
}
F_20 ( & V_2 -> V_39 ) ;
return V_38 ;
}
static int F_29 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
V_27 -> type = V_28 ;
V_27 -> V_29 = 2 ;
V_27 -> V_30 . integer . V_31 = 0 ;
V_27 -> V_30 . integer . V_32 = V_47 ;
return 0 ;
}
static int F_30 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
struct V_35 * V_36 = V_2 -> V_36 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ )
V_34 -> V_30 . integer . V_30 [ V_12 ] = V_36 -> V_42 [ V_12 ] ;
return 0 ;
}
static int F_31 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
struct V_35 * V_36 = V_2 -> V_36 ;
int V_54 , V_38 = 0 ;
F_19 ( & V_2 -> V_39 ) ;
for ( V_54 = 0 ; V_54 < 2 ; V_54 ++ ) {
if ( V_34 -> V_30 . integer . V_30 [ V_54 ] != V_36 -> V_42 [ V_54 ] ) {
V_36 -> V_42 [ V_54 ] = V_34 -> V_30 . integer . V_30 [ V_54 ] ;
F_21 ( V_2 , V_49 + V_54 ,
V_36 -> V_37 [ 2 + V_54 ] , V_36 -> V_42 [ V_54 ] ) ;
F_22 ( V_2 , V_53 + V_54 ,
V_36 -> V_37 [ 0 + V_54 ] , V_36 -> V_42 [ V_54 ] ) ;
F_22 ( V_2 , V_55 + V_54 ,
V_36 -> V_37 [ 4 + V_54 ] , V_36 -> V_42 [ V_54 ] ) ;
F_22 ( V_2 , V_56 + V_54 ,
V_36 -> V_37 [ 6 + V_54 ] , V_36 -> V_42 [ V_54 ] ) ;
V_38 = 1 ;
}
}
F_20 ( & V_2 -> V_39 ) ;
return V_38 ;
}
static int F_32 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
static char * V_57 [ 32 ] = {
L_1 , V_58 , V_59 , V_58 L_2 V_59 ,
V_60 , V_58 L_2 V_60 , V_59 L_2 V_60 ,
V_58 L_2 V_59 L_2 V_60 ,
V_61 , V_58 L_2 V_61 , V_59 L_2 V_61 ,
V_58 L_2 V_59 L_2 V_61 ,
V_60 L_2 V_61 , V_58 L_2 V_60 L_2 V_61 ,
V_59 L_2 V_60 L_2 V_61 ,
V_58 L_2 V_59 L_2 V_60 L_2 V_61 ,
V_62 , V_58 L_2 V_62 , V_59 L_2 V_62 ,
V_58 L_2 V_59 L_2 V_62 ,
V_60 L_2 V_62 , V_58 L_2 V_60 L_2 V_62 ,
V_59 L_2 V_60 L_2 V_62 ,
V_58 L_2 V_59 L_2 V_60 L_2 V_62 ,
V_61 L_2 V_62 , V_58 L_2 V_61 L_2 V_62 ,
V_59 L_2 V_61 L_2 V_62 ,
V_58 L_2 V_59 L_2 V_61 L_2 V_62 ,
V_60 L_2 V_61 L_2 V_62 ,
V_58 L_2 V_60 L_2 V_61 L_2 V_62 ,
V_59 L_2 V_60 L_2 V_61 L_2 V_62 ,
V_58 L_2 V_59 L_2 V_60 L_2 V_61 L_2 V_62
} ;
V_27 -> type = V_63 ;
V_27 -> V_29 = 1 ;
V_27 -> V_30 . V_64 . V_65 = 32 ;
if ( V_27 -> V_30 . V_64 . V_66 > 31 )
V_27 -> V_30 . V_64 . V_66 = 31 ;
strcpy ( V_27 -> V_30 . V_64 . V_67 ,
V_57 [ V_27 -> V_30 . V_64 . V_66 ] ) ;
return 0 ;
}
static int F_33 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
F_19 ( & V_2 -> V_39 ) ;
V_34 -> V_30 . integer . V_30 [ 0 ] = F_1 ( V_2 , V_68 ) & 0x1f ;
F_20 ( & V_2 -> V_39 ) ;
return 0 ;
}
static int F_34 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
unsigned short V_69 , V_70 ;
int V_38 = 0 ;
F_19 ( & V_2 -> V_39 ) ;
V_69 = F_1 ( V_2 , V_68 ) ;
V_70 = ( V_69 & 0xe0 ) | V_34 -> V_30 . integer . V_30 [ 0 ] ;
if ( V_70 != V_69 ) {
F_4 ( V_2 , V_68 , V_70 ) ;
V_38 = 1 ;
}
F_20 ( & V_2 -> V_39 ) ;
return V_38 ;
}
static int F_35 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
V_27 -> type = V_28 ;
V_27 -> V_29 = 2 ;
V_27 -> V_30 . integer . V_31 = 0 ;
V_27 -> V_30 . integer . V_32 = V_71 ;
return 0 ;
}
static int F_36 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
unsigned short V_6 ;
int V_12 ;
F_19 ( & V_2 -> V_39 ) ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ ) {
V_6 = F_1 ( V_2 , V_72 + V_12 ) & 0xff ;
V_6 = V_6 > V_73 ? ( V_6 - V_73 ) : 0 ;
V_34 -> V_30 . integer . V_30 [ V_12 ] = V_6 ;
}
F_20 ( & V_2 -> V_39 ) ;
return 0 ;
}
static int F_37 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
unsigned short V_74 , V_43 ;
int V_12 , V_48 , V_38 = 0 ;
F_19 ( & V_2 -> V_39 ) ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ ) {
V_43 = V_34 -> V_30 . integer . V_30 [ V_12 ] ;
V_43 = V_43 ? ( V_43 + V_73 ) : 0 ;
V_48 = V_72 + V_12 ;
V_74 = F_1 ( V_2 , V_48 ) & 0xff ;
if ( V_74 != V_43 ) {
F_4 ( V_2 , V_48 , V_43 ) ;
V_38 = 1 ;
}
}
F_20 ( & V_2 -> V_39 ) ;
return V_38 ;
}
static int F_38 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
int V_9 = V_25 -> V_51 ;
F_19 ( & V_2 -> V_39 ) ;
V_34 -> V_30 . integer . V_30 [ 0 ] =
( F_1 ( V_2 , V_68 ) & ( 1 << V_9 ) ) ? 1 : 0 ;
F_20 ( & V_2 -> V_39 ) ;
return 0 ;
}
static int F_39 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
int V_9 = V_25 -> V_51 ;
unsigned short V_69 , V_70 ;
int V_38 ;
F_19 ( & V_2 -> V_39 ) ;
V_70 = V_69 = F_1 ( V_2 , V_68 ) ;
if ( V_34 -> V_30 . integer . V_30 [ 0 ] )
V_70 |= ( 1 << V_9 ) ;
else
V_70 &= ~ ( 1 << V_9 ) ;
V_38 = V_70 != V_69 ;
if ( V_38 ) {
F_4 ( V_2 , V_68 , V_70 ) ;
}
F_20 ( & V_2 -> V_39 ) ;
return 0 ;
}
static int F_40 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
F_19 ( & V_2 -> V_39 ) ;
V_34 -> V_30 . integer . V_30 [ 0 ] =
( F_1 ( V_2 , V_75 ) & 0x04 ) ? 1 : 0 ;
F_20 ( & V_2 -> V_39 ) ;
return 0 ;
}
static int F_41 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
unsigned short V_6 , V_69 ;
int V_38 = 0 ;
F_19 ( & V_2 -> V_39 ) ;
V_6 = V_69 = F_1 ( V_2 , V_75 ) ;
if ( V_34 -> V_30 . integer . V_30 [ 0 ] )
V_6 |= 0x04 ;
else
V_6 &= ~ 0x04 ;
if ( V_6 != V_69 ) {
F_4 ( V_2 , V_75 , V_6 ) ;
V_38 = 1 ;
}
F_20 ( & V_2 -> V_39 ) ;
return V_38 ;
}
static int F_42 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
F_19 ( & V_2 -> V_39 ) ;
V_34 -> V_30 . integer . V_30 [ 0 ] =
( F_1 ( V_2 , V_76 ) & 0xf0 ) != 0x90 ;
F_20 ( & V_2 -> V_39 ) ;
return 0 ;
}
static int F_43 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
unsigned short V_6 , V_69 ;
int V_38 = 0 ;
F_19 ( & V_2 -> V_39 ) ;
V_69 = F_1 ( V_2 , V_76 ) ;
V_6 = V_69 & 0x0f ;
if ( V_34 -> V_30 . integer . V_30 [ 0 ] )
V_6 |= 0x60 ;
else
V_6 |= 0x90 ;
if ( V_6 != V_69 ) {
F_4 ( V_2 , V_76 , V_6 ) ;
F_2 ( V_2 , V_76 , V_6 ) ;
V_38 = 1 ;
}
F_20 ( & V_2 -> V_39 ) ;
return V_38 ;
}
static void F_44 ( struct V_77 * V_78 ,
struct V_79 * V_80 )
{
struct V_1 * V_2 = V_78 -> V_81 ;
char line [ 64 ] ;
unsigned int V_3 , V_6 ;
F_19 ( & V_2 -> V_39 ) ;
while ( ! F_45 ( V_80 , line , sizeof( line ) ) ) {
if ( sscanf ( line , L_3 , & V_3 , & V_6 ) != 2 )
continue;
if ( V_3 <= 0x17 && V_6 <= 0xffff )
F_4 ( V_2 , V_3 , V_6 ) ;
}
F_20 ( & V_2 -> V_39 ) ;
}
static void F_46 ( struct V_77 * V_78 ,
struct V_79 * V_80 )
{
struct V_1 * V_2 = V_78 -> V_81 ;
int V_3 , V_6 ;
F_19 ( & V_2 -> V_39 ) ;
for ( V_3 = 0 ; V_3 <= 0x17 ; V_3 ++ ) {
V_6 = F_1 ( V_2 , V_3 ) ;
F_47 ( V_80 , L_4 , V_3 , V_6 ) ;
}
F_20 ( & V_2 -> V_39 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_77 * V_78 ;
if ( ! F_49 ( V_2 -> V_82 , L_5 , & V_78 ) ) {
F_50 ( V_78 , V_2 , F_46 ) ;
V_78 -> V_83 |= V_84 ;
V_78 -> V_85 . V_86 . V_87 = F_44 ;
}
}
static int F_51 ( struct V_1 * V_2 )
{
unsigned int V_12 ;
int V_88 ;
for ( V_12 = 0 ; V_12 < F_52 ( V_89 ) ; V_12 ++ ) {
V_88 = F_53 ( V_2 -> V_82 ,
F_54 ( & V_89 [ V_12 ] , V_2 ) ) ;
if ( V_88 < 0 )
return V_88 ;
}
F_48 ( V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
unsigned int V_12 ;
int V_88 ;
for ( V_12 = 0 ; V_12 < F_52 ( V_90 ) ; V_12 ++ ) {
V_88 = F_53 ( V_2 -> V_82 ,
F_54 ( & V_90 [ V_12 ] , V_2 ) ) ;
if ( V_88 < 0 )
return V_88 ;
}
F_48 ( V_2 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
static unsigned short V_91 [] = {
V_68 , 0x0003 ,
V_92 , 0x0001 ,
V_76 , 0x0000 ,
V_93 , 0x0008 ,
V_94 , 0x0000 ,
} ;
static unsigned short V_95 [] = {
V_96 , 0x0022 ,
V_97 , 0x0022 ,
V_98 , 0x0022 ,
V_76 , 0x0090 ,
V_75 , 0x0001 ,
V_99 , 0x0179 ,
V_100 , 0x0179 ,
V_49 , 0x0000 ,
V_49 , 0x0100 ,
V_101 , 0x0000 ,
V_101 , 0x0100 ,
V_102 , 0x0000 ,
#if 0
WM_DAC_MASTER, 0x0100,
#endif
V_103 , 0x0000 ,
V_72 , 0x0000 ,
V_104 , 0x0000 ,
#if 1
V_105 , 0x007b ,
V_106 , 0x0000 ,
V_107 , 0x0000 ,
V_108 , 0x0000 ,
#endif
V_92 , 0x0000 ,
V_68 , 0x0003 ,
} ;
static unsigned short V_109 [] = {
V_110 , 0x0000 ,
V_111 , 0x0120 ,
V_112 , 0x0022 ,
V_113 , 0x0001 ,
V_114 , 0x0080 ,
V_53 , 0x0100 ,
V_55 , 0x0100 ,
V_56 , 0x0100 ,
V_115 , 0x0100 ,
V_116 , 0x0100 ,
V_117 , 0x0100 ,
V_118 , 0x0000 ,
V_119 , 0x0000 ,
} ;
struct V_35 * V_36 ;
unsigned int V_12 ;
V_2 -> V_120 = 0 ;
V_2 -> V_121 = 1 ;
V_2 -> V_122 = 8 ;
V_2 -> V_123 = 1 ;
V_2 -> V_17 . V_124 [ 0 ] = 0 ;
V_2 -> V_4 = F_57 ( sizeof( struct V_125 ) , V_126 ) ;
if ( ! V_2 -> V_4 )
return - V_127 ;
V_2 -> V_128 = 1 ;
V_36 = F_57 ( sizeof( * V_36 ) , V_126 ) ;
if ( ! V_36 )
return - V_127 ;
V_2 -> V_36 = V_36 ;
for ( V_12 = 0 ; V_12 < F_52 ( V_91 ) ; V_12 += 2 )
F_4 ( V_2 , V_91 [ V_12 ] , V_91 [ V_12 + 1 ] ) ;
F_58 ( 1 ) ;
for ( V_12 = 0 ; V_12 < F_52 ( V_95 ) ; V_12 += 2 )
F_4 ( V_2 , V_95 [ V_12 ] , V_95 [ V_12 + 1 ] ) ;
for ( V_12 = 0 ; V_12 < F_52 ( V_109 ) ; V_12 += 2 )
F_10 ( V_2 , V_109 [ V_12 ] , V_109 [ V_12 + 1 ] ) ;
return 0 ;
}
static void F_59 ( struct V_1 * V_2 )
{
static unsigned short V_129 [] = {
V_130 , 0x87 ,
V_131 , 0x02 ,
V_132 , 0x00 ,
V_40 , 0x00 ,
V_133 , 0x00 ,
} ;
unsigned int V_12 ;
F_14 ( V_2 , V_130 , 0x86 ) ;
F_60 ( 100 ) ;
F_14 ( V_2 , V_130 , 0x87 ) ;
for ( V_12 = 0 ; V_12 < F_52 ( V_129 ) ; V_12 += 2 )
F_14 ( V_2 , V_129 [ V_12 ] , V_129 [ V_12 + 1 ] ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
int V_12 ;
F_19 ( & V_2 -> V_39 ) ;
F_59 ( V_2 ) ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ )
F_14 ( V_2 , V_40 + V_12 , V_36 -> V_37 [ V_12 ] & 0xff ) ;
F_20 ( & V_2 -> V_39 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_35 * V_36 ;
V_2 -> V_120 = 0 ;
V_2 -> V_121 = 1 ;
V_2 -> V_122 = 1 ;
V_2 -> V_123 = 1 ;
V_2 -> V_17 . V_124 [ 0 ] = 0 ;
V_2 -> V_4 = F_57 ( sizeof( struct V_125 ) , V_126 ) ;
if ( ! V_2 -> V_4 )
return - V_127 ;
V_2 -> V_128 = 1 ;
V_36 = F_57 ( sizeof( * V_36 ) , V_126 ) ;
if ( ! V_36 )
return - V_127 ;
V_2 -> V_36 = V_36 ;
#ifdef F_63
V_2 -> V_134 = & F_61 ;
V_2 -> V_135 = 1 ;
#endif
F_59 ( V_2 ) ;
return 0 ;
}
