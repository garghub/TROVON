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
static int F_5 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
V_12 -> type = V_13 ;
V_12 -> V_14 = 2 ;
V_12 -> V_15 . integer . V_16 = 0 ;
V_12 -> V_15 . integer . V_17 = V_18 ;
return 0 ;
}
static int F_6 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
unsigned short V_6 ;
int V_21 ;
F_8 ( & V_2 -> V_22 ) ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
V_6 = F_1 ( V_2 , V_23 + V_21 ) & 0xff ;
V_6 = V_6 > V_24 ? ( V_6 - V_24 ) : 0 ;
V_20 -> V_15 . integer . V_15 [ V_21 ] = V_6 ;
}
F_9 ( & V_2 -> V_22 ) ;
return 0 ;
}
static int F_10 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
unsigned short V_25 , V_26 ;
int V_21 , V_27 , V_28 = 0 ;
F_8 ( & V_2 -> V_22 ) ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
V_26 = V_20 -> V_15 . integer . V_15 [ V_21 ] ;
V_26 = ( V_26 ? ( V_26 + V_24 ) : 0 ) & 0xff ;
V_27 = V_23 + V_21 ;
V_25 = F_1 ( V_2 , V_27 ) & 0xff ;
if ( V_25 != V_26 ) {
F_4 ( V_2 , V_27 , V_26 ) ;
F_2 ( V_2 , V_27 , V_26 | 0x100 ) ;
V_28 = 1 ;
}
}
F_9 ( & V_2 -> V_22 ) ;
return V_28 ;
}
static int F_11 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
V_12 -> type = V_13 ;
V_12 -> V_14 = 2 ;
V_12 -> V_15 . integer . V_16 = 0 ;
V_12 -> V_15 . integer . V_17 = V_29 ;
return 0 ;
}
static int F_12 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
unsigned short V_6 ;
int V_21 ;
F_8 ( & V_2 -> V_22 ) ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
V_6 = F_1 ( V_2 , V_30 + V_21 ) & 0xff ;
V_6 = V_6 > V_31 ? ( V_6 - V_31 ) : 0 ;
V_20 -> V_15 . integer . V_15 [ V_21 ] = V_6 ;
}
F_9 ( & V_2 -> V_22 ) ;
return 0 ;
}
static int F_13 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
unsigned short V_32 , V_33 ;
int V_21 , V_27 , V_28 = 0 ;
F_8 ( & V_2 -> V_22 ) ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
V_33 = V_20 -> V_15 . integer . V_15 [ V_21 ] ;
V_33 = V_33 ? ( V_33 + V_31 ) : 0 ;
V_27 = V_30 + V_21 ;
V_32 = F_1 ( V_2 , V_27 ) & 0xff ;
if ( V_32 != V_33 ) {
F_4 ( V_2 , V_27 , V_33 ) ;
V_28 = 1 ;
}
}
F_9 ( & V_2 -> V_22 ) ;
return V_28 ;
}
static int F_14 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
int V_34 = V_10 -> V_35 ;
F_8 ( & V_2 -> V_22 ) ;
V_20 -> V_15 . integer . V_15 [ 0 ] = ( F_1 ( V_2 , V_36 ) & ( 1 << V_34 ) ) ? 1 : 0 ;
F_9 ( & V_2 -> V_22 ) ;
return 0 ;
}
static int F_15 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
int V_34 = V_10 -> V_35 ;
unsigned short V_25 , V_26 ;
int V_28 ;
F_8 ( & V_2 -> V_22 ) ;
V_26 = V_25 = F_1 ( V_2 , V_36 ) ;
if ( V_20 -> V_15 . integer . V_15 [ 0 ] )
V_26 |= ( 1 << V_34 ) ;
else
V_26 &= ~ ( 1 << V_34 ) ;
V_28 = V_26 != V_25 ;
if ( V_28 ) {
F_4 ( V_2 , V_36 , V_26 ) ;
}
F_9 ( & V_2 -> V_22 ) ;
return V_28 ;
}
static int F_16 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
F_8 ( & V_2 -> V_22 ) ;
V_20 -> V_15 . integer . V_15 [ 0 ] = ( F_1 ( V_2 , V_37 ) & 0x04 ) ? 1 : 0 ;
F_9 ( & V_2 -> V_22 ) ;
return 0 ;
}
static int F_17 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
unsigned short V_6 , V_25 ;
int V_28 = 0 ;
F_8 ( & V_2 -> V_22 ) ;
V_6 = V_25 = F_1 ( V_2 , V_37 ) ;
if ( V_20 -> V_15 . integer . V_15 [ 0 ] )
V_6 |= 0x04 ;
else
V_6 &= ~ 0x04 ;
if ( V_6 != V_25 ) {
F_4 ( V_2 , V_37 , V_6 ) ;
V_28 = 1 ;
}
F_9 ( & V_2 -> V_22 ) ;
return V_28 ;
}
static int F_18 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
F_8 ( & V_2 -> V_22 ) ;
V_20 -> V_15 . integer . V_15 [ 0 ] = ( F_1 ( V_2 , V_38 ) & 0xf0 ) != 0x90 ;
F_9 ( & V_2 -> V_22 ) ;
return 0 ;
}
static int F_19 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
unsigned short V_6 , V_25 ;
int V_28 = 0 ;
F_8 ( & V_2 -> V_22 ) ;
V_25 = F_1 ( V_2 , V_38 ) ;
V_6 = V_25 & 0x0f ;
if ( V_20 -> V_15 . integer . V_15 [ 0 ] )
V_6 |= 0x60 ;
else
V_6 |= 0x90 ;
if ( V_6 != V_25 ) {
F_4 ( V_2 , V_38 , V_6 ) ;
F_2 ( V_2 , V_38 , V_6 ) ;
V_28 = 1 ;
}
F_9 ( & V_2 -> V_22 ) ;
return V_28 ;
}
static void F_20 ( struct V_1 * V_2 , unsigned int V_34 , int V_6 )
{
unsigned int V_39 = F_21 ( V_2 ) ;
if ( V_6 )
V_39 |= V_34 ;
else
V_39 &= ~ V_34 ;
F_22 ( V_2 , V_39 ) ;
}
static void F_23 ( struct V_1 * V_2 , unsigned char V_40 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ ) {
F_20 ( V_2 , V_41 , 0 ) ;
F_24 ( 1 ) ;
F_20 ( V_2 , V_42 , V_40 & 0x80 ) ;
F_24 ( 1 ) ;
F_20 ( V_2 , V_41 , 1 ) ;
F_24 ( 1 ) ;
V_40 <<= 1 ;
}
}
static unsigned int F_25 ( struct V_1 * V_2 )
{
int V_21 ;
unsigned int V_6 = 0 ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ ) {
V_6 <<= 1 ;
F_20 ( V_2 , V_41 , 0 ) ;
F_24 ( 1 ) ;
if ( F_21 ( V_2 ) & V_43 )
V_6 |= 1 ;
F_24 ( 1 ) ;
F_20 ( V_2 , V_41 , 1 ) ;
F_24 ( 1 ) ;
}
return V_6 ;
}
static void F_26 ( struct V_1 * V_2 , unsigned int V_44 , unsigned int V_3 , unsigned int V_40 )
{
F_27 ( V_2 , V_45 | V_42 | V_41 ) ;
F_28 ( V_2 , ~ ( V_45 | V_42 | V_41 ) ) ;
F_20 ( V_2 , V_45 , 0 ) ;
F_23 ( V_2 , V_44 & ~ 1 ) ;
F_23 ( V_2 , V_3 ) ;
F_23 ( V_2 , V_40 ) ;
F_20 ( V_2 , V_45 , 1 ) ;
F_24 ( 1 ) ;
F_28 ( V_2 , V_2 -> V_46 . V_47 ) ;
F_27 ( V_2 , V_2 -> V_46 . V_48 ) ;
}
static unsigned int F_29 ( struct V_1 * V_2 , unsigned int V_44 , unsigned int V_3 )
{
unsigned int V_6 ;
F_27 ( V_2 , V_45 | V_42 | V_41 ) ;
F_28 ( V_2 , ~ ( V_45 | V_42 | V_41 ) ) ;
F_20 ( V_2 , V_45 , 0 ) ;
F_23 ( V_2 , V_44 & ~ 1 ) ;
F_23 ( V_2 , V_3 ) ;
F_20 ( V_2 , V_45 , 1 ) ;
F_24 ( 1 ) ;
F_20 ( V_2 , V_45 , 0 ) ;
F_23 ( V_2 , V_44 | 1 ) ;
V_6 = F_25 ( V_2 ) ;
F_20 ( V_2 , V_45 , 1 ) ;
F_24 ( 1 ) ;
F_28 ( V_2 , V_2 -> V_46 . V_47 ) ;
F_27 ( V_2 , V_2 -> V_46 . V_48 ) ;
return V_6 ;
}
static int F_30 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
static const char * const V_49 [] = {
L_1 ,
L_2 ,
L_3 ,
} ;
return F_31 ( V_12 , 1 , 3 , V_49 ) ;
}
static int F_32 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
F_8 ( & V_2 -> V_22 ) ;
V_20 -> V_15 . V_50 . V_51 [ 0 ] = V_2 -> V_46 . V_52 [ 0 ] ;
F_9 ( & V_2 -> V_22 ) ;
return 0 ;
}
static int F_33 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
unsigned char V_6 ;
int V_28 = 0 ;
F_8 ( & V_2 -> V_22 ) ;
if ( V_20 -> V_15 . V_50 . V_51 [ 0 ] != V_2 -> V_46 . V_52 [ 0 ] ) {
V_2 -> V_46 . V_52 [ 0 ] = V_20 -> V_15 . V_50 . V_51 [ 0 ] & 3 ;
V_6 = 0x80 | ( V_2 -> V_46 . V_52 [ 0 ] << 3 ) ;
F_26 ( V_2 , V_53 , 0x04 , V_6 ) ;
V_28 = 1 ;
}
F_9 ( & V_2 -> V_22 ) ;
return V_28 ;
}
static int F_34 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
V_12 -> type = V_13 ;
V_12 -> V_14 = 1 ;
V_12 -> V_15 . integer . V_16 = 0 ;
V_12 -> V_15 . integer . V_17 = 0xffff ;
return 0 ;
}
static int F_35 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
F_8 ( & V_2 -> V_22 ) ;
V_20 -> V_15 . integer . V_15 [ 0 ] = ( ~ V_2 -> V_46 . V_47 & 0xffff ) | 0x00f0 ;
F_9 ( & V_2 -> V_22 ) ;
return 0 ;
}
static int F_36 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
unsigned int V_6 ;
int V_54 ;
F_8 ( & V_2 -> V_22 ) ;
V_6 = ( ~ V_20 -> V_15 . integer . V_15 [ 0 ] & 0xffff ) | 0x00f0 ;
V_54 = V_6 != V_2 -> V_46 . V_47 ;
V_2 -> V_46 . V_47 = V_6 ;
F_9 ( & V_2 -> V_22 ) ;
return V_54 ;
}
static int F_37 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
F_8 ( & V_2 -> V_22 ) ;
V_20 -> V_15 . integer . V_15 [ 0 ] = V_2 -> V_46 . V_48 & 0xff0f ;
F_9 ( & V_2 -> V_22 ) ;
return 0 ;
}
static int F_38 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
unsigned int V_6 ;
int V_54 ;
F_8 ( & V_2 -> V_22 ) ;
V_6 = V_20 -> V_15 . integer . V_15 [ 0 ] & 0xff0f ;
V_54 = ( V_6 != V_2 -> V_46 . V_48 ) ;
V_2 -> V_46 . V_48 = V_6 ;
F_9 ( & V_2 -> V_22 ) ;
return V_54 ;
}
static int F_39 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
F_8 ( & V_2 -> V_22 ) ;
F_27 ( V_2 , V_2 -> V_46 . V_48 ) ;
F_28 ( V_2 , V_2 -> V_46 . V_47 ) ;
V_20 -> V_15 . integer . V_15 [ 0 ] = F_21 ( V_2 ) & 0xffff ;
F_9 ( & V_2 -> V_22 ) ;
return 0 ;
}
static int F_40 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
unsigned int V_6 , V_26 ;
int V_54 = 0 ;
F_8 ( & V_2 -> V_22 ) ;
F_27 ( V_2 , V_2 -> V_46 . V_48 ) ;
F_28 ( V_2 , V_2 -> V_46 . V_47 ) ;
V_6 = F_21 ( V_2 ) & 0xffff ;
V_26 = V_20 -> V_15 . integer . V_15 [ 0 ] & 0xffff ;
if ( V_6 != V_26 ) {
F_22 ( V_2 , V_26 ) ;
V_54 = 1 ;
}
F_9 ( & V_2 -> V_22 ) ;
return V_54 ;
}
static void F_41 ( struct V_55 * V_56 , struct V_57 * V_58 )
{
struct V_1 * V_2 = V_56 -> V_59 ;
char line [ 64 ] ;
unsigned int V_3 , V_6 ;
F_8 ( & V_2 -> V_22 ) ;
while ( ! F_42 ( V_58 , line , sizeof( line ) ) ) {
if ( sscanf ( line , L_4 , & V_3 , & V_6 ) != 2 )
continue;
if ( V_3 <= 0x17 && V_6 <= 0xffff )
F_4 ( V_2 , V_3 , V_6 ) ;
}
F_9 ( & V_2 -> V_22 ) ;
}
static void F_43 ( struct V_55 * V_56 , struct V_57 * V_58 )
{
struct V_1 * V_2 = V_56 -> V_59 ;
int V_3 , V_6 ;
F_8 ( & V_2 -> V_22 ) ;
for ( V_3 = 0 ; V_3 <= 0x17 ; V_3 ++ ) {
V_6 = F_1 ( V_2 , V_3 ) ;
F_44 ( V_58 , L_5 , V_3 , V_6 ) ;
}
F_9 ( & V_2 -> V_22 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_55 * V_56 ;
if ( ! F_46 ( V_2 -> V_60 , L_6 , & V_56 ) ) {
F_47 ( V_56 , V_2 , F_43 ) ;
V_56 -> V_61 |= V_62 ;
V_56 -> V_63 . V_64 . V_65 = F_41 ;
}
}
static void F_48 ( struct V_55 * V_56 , struct V_57 * V_58 )
{
struct V_1 * V_2 = V_56 -> V_59 ;
int V_3 , V_6 ;
F_8 ( & V_2 -> V_22 ) ;
for ( V_3 = 0 ; V_3 <= 0x26 ; V_3 ++ ) {
V_6 = F_29 ( V_2 , V_53 , V_3 ) ;
F_44 ( V_58 , L_7 , V_3 , V_6 ) ;
}
V_6 = F_29 ( V_2 , V_53 , 0x7f ) ;
F_44 ( V_58 , L_7 , 0x7f , V_6 ) ;
F_9 ( & V_2 -> V_22 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_55 * V_56 ;
if ( ! F_46 ( V_2 -> V_60 , L_8 , & V_56 ) )
F_47 ( V_56 , V_2 , F_48 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
unsigned int V_21 ;
int V_66 ;
for ( V_21 = 0 ; V_21 < F_51 ( V_67 ) ; V_21 ++ ) {
V_66 = F_52 ( V_2 -> V_60 , F_53 ( & V_67 [ V_21 ] , V_2 ) ) ;
if ( V_66 < 0 )
return V_66 ;
}
F_45 ( V_2 ) ;
F_49 ( V_2 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
static const unsigned short V_68 [] = {
V_36 , 0x00c0 ,
V_69 , 0x0001 ,
V_38 , 0x0000 ,
V_70 , 0x0008 ,
V_71 , 0x0000 ,
} ;
static const unsigned short V_72 [] = {
V_73 , 0x0022 ,
V_74 , 0x0022 ,
V_75 , 0x0022 ,
V_38 , 0x0090 ,
V_37 , 0x0001 ,
V_76 , 0x0179 ,
V_77 , 0x0179 ,
V_23 , 0x0000 ,
V_23 , 0x0100 ,
V_78 , 0x0000 ,
V_78 , 0x0100 ,
V_79 , 0x0000 ,
V_80 , 0x0000 ,
V_30 , 0x0000 ,
V_81 , 0x0000 ,
#if 0
WM_ALC_CTRL1, 0x007b,
WM_ALC_CTRL2, 0x0000,
WM_ALC_CTRL3, 0x0000,
WM_NOISE_GATE, 0x0000,
#endif
V_69 , 0x0000 ,
V_36 , 0x0003 ,
} ;
static const unsigned char V_82 [] = {
0x04 , 0x80 ,
0x05 , 0x05 ,
0x01 , 0x00 ,
0x02 , 0x00 ,
0x03 , 0x00 ,
} ;
unsigned int V_21 ;
V_2 -> V_83 = 1 ;
V_2 -> V_84 = 2 ;
V_2 -> V_85 = 2 ;
V_2 -> V_4 = F_55 ( sizeof( struct V_86 ) , V_87 ) ;
if ( ! V_2 -> V_4 )
return - V_88 ;
V_2 -> V_89 = 1 ;
V_2 -> V_46 . V_52 [ 0 ] = 0 ;
for ( V_21 = 0 ; V_21 < F_51 ( V_68 ) ; V_21 += 2 )
F_4 ( V_2 , V_68 [ V_21 ] , V_68 [ V_21 + 1 ] ) ;
F_56 ( 1 ) ;
for ( V_21 = 0 ; V_21 < F_51 ( V_72 ) ; V_21 += 2 )
F_4 ( V_2 , V_72 [ V_21 ] , V_72 [ V_21 + 1 ] ) ;
F_57 ( F_58 ( F_59 ( V_2 , V_90 ) ) | 0x80 , F_59 ( V_2 , V_90 ) ) ;
F_60 ( 5 ) ;
F_57 ( F_58 ( F_59 ( V_2 , V_90 ) ) & ~ 0x80 , F_59 ( V_2 , V_90 ) ) ;
for ( V_21 = 0 ; V_21 < F_51 ( V_82 ) ; V_21 += 2 )
F_26 ( V_2 , V_53 , V_82 [ V_21 ] , V_82 [ V_21 + 1 ] ) ;
return 0 ;
}
