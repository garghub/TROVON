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
static const char * const V_57 [ 32 ] = {
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
return F_33 ( V_27 , 1 , 32 , V_57 ) ;
}
static int F_34 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
F_19 ( & V_2 -> V_39 ) ;
V_34 -> V_30 . integer . V_30 [ 0 ] = F_1 ( V_2 , V_63 ) & 0x1f ;
F_20 ( & V_2 -> V_39 ) ;
return 0 ;
}
static int F_35 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
unsigned short V_64 , V_65 ;
int V_38 = 0 ;
F_19 ( & V_2 -> V_39 ) ;
V_64 = F_1 ( V_2 , V_63 ) ;
V_65 = ( V_64 & 0xe0 ) | V_34 -> V_30 . integer . V_30 [ 0 ] ;
if ( V_65 != V_64 ) {
F_4 ( V_2 , V_63 , V_65 ) ;
V_38 = 1 ;
}
F_20 ( & V_2 -> V_39 ) ;
return V_38 ;
}
static int F_36 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
V_27 -> type = V_28 ;
V_27 -> V_29 = 2 ;
V_27 -> V_30 . integer . V_31 = 0 ;
V_27 -> V_30 . integer . V_32 = V_66 ;
return 0 ;
}
static int F_37 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
unsigned short V_6 ;
int V_12 ;
F_19 ( & V_2 -> V_39 ) ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ ) {
V_6 = F_1 ( V_2 , V_67 + V_12 ) & 0xff ;
V_6 = V_6 > V_68 ? ( V_6 - V_68 ) : 0 ;
V_34 -> V_30 . integer . V_30 [ V_12 ] = V_6 ;
}
F_20 ( & V_2 -> V_39 ) ;
return 0 ;
}
static int F_38 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
unsigned short V_69 , V_43 ;
int V_12 , V_48 , V_38 = 0 ;
F_19 ( & V_2 -> V_39 ) ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ ) {
V_43 = V_34 -> V_30 . integer . V_30 [ V_12 ] ;
V_43 = V_43 ? ( V_43 + V_68 ) : 0 ;
V_48 = V_67 + V_12 ;
V_69 = F_1 ( V_2 , V_48 ) & 0xff ;
if ( V_69 != V_43 ) {
F_4 ( V_2 , V_48 , V_43 ) ;
V_38 = 1 ;
}
}
F_20 ( & V_2 -> V_39 ) ;
return V_38 ;
}
static int F_39 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
int V_9 = V_25 -> V_51 ;
F_19 ( & V_2 -> V_39 ) ;
V_34 -> V_30 . integer . V_30 [ 0 ] =
( F_1 ( V_2 , V_63 ) & ( 1 << V_9 ) ) ? 1 : 0 ;
F_20 ( & V_2 -> V_39 ) ;
return 0 ;
}
static int F_40 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
int V_9 = V_25 -> V_51 ;
unsigned short V_64 , V_65 ;
int V_38 ;
F_19 ( & V_2 -> V_39 ) ;
V_65 = V_64 = F_1 ( V_2 , V_63 ) ;
if ( V_34 -> V_30 . integer . V_30 [ 0 ] )
V_65 |= ( 1 << V_9 ) ;
else
V_65 &= ~ ( 1 << V_9 ) ;
V_38 = V_65 != V_64 ;
if ( V_38 ) {
F_4 ( V_2 , V_63 , V_65 ) ;
}
F_20 ( & V_2 -> V_39 ) ;
return 0 ;
}
static int F_41 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
F_19 ( & V_2 -> V_39 ) ;
V_34 -> V_30 . integer . V_30 [ 0 ] =
( F_1 ( V_2 , V_70 ) & 0x04 ) ? 1 : 0 ;
F_20 ( & V_2 -> V_39 ) ;
return 0 ;
}
static int F_42 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
unsigned short V_6 , V_64 ;
int V_38 = 0 ;
F_19 ( & V_2 -> V_39 ) ;
V_6 = V_64 = F_1 ( V_2 , V_70 ) ;
if ( V_34 -> V_30 . integer . V_30 [ 0 ] )
V_6 |= 0x04 ;
else
V_6 &= ~ 0x04 ;
if ( V_6 != V_64 ) {
F_4 ( V_2 , V_70 , V_6 ) ;
V_38 = 1 ;
}
F_20 ( & V_2 -> V_39 ) ;
return V_38 ;
}
static int F_43 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
F_19 ( & V_2 -> V_39 ) ;
V_34 -> V_30 . integer . V_30 [ 0 ] =
( F_1 ( V_2 , V_71 ) & 0xf0 ) != 0x90 ;
F_20 ( & V_2 -> V_39 ) ;
return 0 ;
}
static int F_44 ( struct V_24 * V_25 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
unsigned short V_6 , V_64 ;
int V_38 = 0 ;
F_19 ( & V_2 -> V_39 ) ;
V_64 = F_1 ( V_2 , V_71 ) ;
V_6 = V_64 & 0x0f ;
if ( V_34 -> V_30 . integer . V_30 [ 0 ] )
V_6 |= 0x60 ;
else
V_6 |= 0x90 ;
if ( V_6 != V_64 ) {
F_4 ( V_2 , V_71 , V_6 ) ;
F_2 ( V_2 , V_71 , V_6 ) ;
V_38 = 1 ;
}
F_20 ( & V_2 -> V_39 ) ;
return V_38 ;
}
static void F_45 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
struct V_1 * V_2 = V_73 -> V_76 ;
char line [ 64 ] ;
unsigned int V_3 , V_6 ;
F_19 ( & V_2 -> V_39 ) ;
while ( ! F_46 ( V_75 , line , sizeof( line ) ) ) {
if ( sscanf ( line , L_3 , & V_3 , & V_6 ) != 2 )
continue;
if ( V_3 <= 0x17 && V_6 <= 0xffff )
F_4 ( V_2 , V_3 , V_6 ) ;
}
F_20 ( & V_2 -> V_39 ) ;
}
static void F_47 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
struct V_1 * V_2 = V_73 -> V_76 ;
int V_3 , V_6 ;
F_19 ( & V_2 -> V_39 ) ;
for ( V_3 = 0 ; V_3 <= 0x17 ; V_3 ++ ) {
V_6 = F_1 ( V_2 , V_3 ) ;
F_48 ( V_75 , L_4 , V_3 , V_6 ) ;
}
F_20 ( & V_2 -> V_39 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_72 * V_73 ;
if ( ! F_50 ( V_2 -> V_77 , L_5 , & V_73 ) ) {
F_51 ( V_73 , V_2 , F_47 ) ;
V_73 -> V_78 |= V_79 ;
V_73 -> V_80 . V_81 . V_82 = F_45 ;
}
}
static int F_52 ( struct V_1 * V_2 )
{
unsigned int V_12 ;
int V_83 ;
for ( V_12 = 0 ; V_12 < F_53 ( V_84 ) ; V_12 ++ ) {
V_83 = F_54 ( V_2 -> V_77 ,
F_55 ( & V_84 [ V_12 ] , V_2 ) ) ;
if ( V_83 < 0 )
return V_83 ;
}
F_49 ( V_2 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
unsigned int V_12 ;
int V_83 ;
for ( V_12 = 0 ; V_12 < F_53 ( V_85 ) ; V_12 ++ ) {
V_83 = F_54 ( V_2 -> V_77 ,
F_55 ( & V_85 [ V_12 ] , V_2 ) ) ;
if ( V_83 < 0 )
return V_83 ;
}
F_49 ( V_2 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
static unsigned short V_86 [] = {
V_63 , 0x0003 ,
V_87 , 0x0001 ,
V_71 , 0x0000 ,
V_88 , 0x0008 ,
V_89 , 0x0000 ,
} ;
static unsigned short V_90 [] = {
V_91 , 0x0022 ,
V_92 , 0x0022 ,
V_93 , 0x0022 ,
V_71 , 0x0090 ,
V_70 , 0x0001 ,
V_94 , 0x0179 ,
V_95 , 0x0179 ,
V_49 , 0x0000 ,
V_49 , 0x0100 ,
V_96 , 0x0000 ,
V_96 , 0x0100 ,
V_97 , 0x0000 ,
#if 0
WM_DAC_MASTER, 0x0100,
#endif
V_98 , 0x0000 ,
V_67 , 0x0000 ,
V_99 , 0x0000 ,
#if 1
V_100 , 0x007b ,
V_101 , 0x0000 ,
V_102 , 0x0000 ,
V_103 , 0x0000 ,
#endif
V_87 , 0x0000 ,
V_63 , 0x0003 ,
} ;
static unsigned short V_104 [] = {
V_105 , 0x0000 ,
V_106 , 0x0120 ,
V_107 , 0x0022 ,
V_108 , 0x0001 ,
V_109 , 0x0080 ,
V_53 , 0x0100 ,
V_55 , 0x0100 ,
V_56 , 0x0100 ,
V_110 , 0x0100 ,
V_111 , 0x0100 ,
V_112 , 0x0100 ,
V_113 , 0x0000 ,
V_114 , 0x0000 ,
} ;
struct V_35 * V_36 ;
unsigned int V_12 ;
V_2 -> V_115 = 0 ;
V_2 -> V_116 = 1 ;
V_2 -> V_117 = 8 ;
V_2 -> V_118 = 1 ;
V_2 -> V_17 . V_119 [ 0 ] = 0 ;
V_2 -> V_4 = F_58 ( sizeof( struct V_120 ) , V_121 ) ;
if ( ! V_2 -> V_4 )
return - V_122 ;
V_2 -> V_123 = 1 ;
V_36 = F_58 ( sizeof( * V_36 ) , V_121 ) ;
if ( ! V_36 )
return - V_122 ;
V_2 -> V_36 = V_36 ;
for ( V_12 = 0 ; V_12 < F_53 ( V_86 ) ; V_12 += 2 )
F_4 ( V_2 , V_86 [ V_12 ] , V_86 [ V_12 + 1 ] ) ;
F_59 ( 1 ) ;
for ( V_12 = 0 ; V_12 < F_53 ( V_90 ) ; V_12 += 2 )
F_4 ( V_2 , V_90 [ V_12 ] , V_90 [ V_12 + 1 ] ) ;
for ( V_12 = 0 ; V_12 < F_53 ( V_104 ) ; V_12 += 2 )
F_10 ( V_2 , V_104 [ V_12 ] , V_104 [ V_12 + 1 ] ) ;
return 0 ;
}
static void F_60 ( struct V_1 * V_2 )
{
static unsigned short V_124 [] = {
V_125 , 0x87 ,
V_126 , 0x02 ,
V_127 , 0x00 ,
V_40 , 0x00 ,
V_128 , 0x00 ,
} ;
unsigned int V_12 ;
F_14 ( V_2 , V_125 , 0x86 ) ;
F_61 ( 100 ) ;
F_14 ( V_2 , V_125 , 0x87 ) ;
for ( V_12 = 0 ; V_12 < F_53 ( V_124 ) ; V_12 += 2 )
F_14 ( V_2 , V_124 [ V_12 ] , V_124 [ V_12 + 1 ] ) ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
int V_12 ;
F_19 ( & V_2 -> V_39 ) ;
F_60 ( V_2 ) ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ )
F_14 ( V_2 , V_40 + V_12 , V_36 -> V_37 [ V_12 ] & 0xff ) ;
F_20 ( & V_2 -> V_39 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_35 * V_36 ;
V_2 -> V_115 = 0 ;
V_2 -> V_116 = 1 ;
V_2 -> V_117 = 1 ;
V_2 -> V_118 = 1 ;
V_2 -> V_17 . V_119 [ 0 ] = 0 ;
V_2 -> V_4 = F_58 ( sizeof( struct V_120 ) , V_121 ) ;
if ( ! V_2 -> V_4 )
return - V_122 ;
V_2 -> V_123 = 1 ;
V_36 = F_58 ( sizeof( * V_36 ) , V_121 ) ;
if ( ! V_36 )
return - V_122 ;
V_2 -> V_36 = V_36 ;
#ifdef F_64
V_2 -> V_129 = & F_62 ;
V_2 -> V_130 = 1 ;
#endif
F_60 ( V_2 ) ;
return 0 ;
}
