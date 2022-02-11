static inline void F_1 ( struct V_1 * V_2 , int V_3 , unsigned char V_4 )
{
F_2 ( V_2 , V_5 , V_3 , V_4 ) ;
}
static inline unsigned char F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 , V_5 , V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_6 ,
unsigned char V_7 )
{
unsigned char V_8 , V_9 ;
int V_10 ;
V_9 = F_3 ( V_2 , V_6 ) ;
V_8 = ( ~ V_7 << 7 & 0x80 ) | ( V_9 & ~ 0x80 ) ;
V_10 = ( V_8 != V_9 ) ;
if ( V_10 )
F_1 ( V_2 , V_6 , V_8 ) ;
return V_10 ;
}
static int F_6 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
unsigned char V_4 ;
int V_6 ;
if ( V_12 -> V_15 )
V_6 = V_16 ;
else
V_6 = F_8 ( V_12 , & V_14 -> V_17 ) + V_18 ;
V_4 = F_3 ( V_2 , V_6 ) ;
V_14 -> V_19 . integer . V_19 [ 0 ] = ( ~ V_4 >> 7 ) & 0x1 ;
return 0 ;
}
static int F_9 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
struct V_20 * V_21 = V_2 -> V_21 ;
int V_6 , V_10 ;
if ( V_12 -> V_15 )
V_6 = V_16 ;
else
V_6 = F_8 ( V_12 , & V_14 -> V_17 ) + V_18 ;
F_10 ( & V_21 -> V_22 ) ;
V_10 = F_5 ( V_2 , V_6 , V_14 -> V_19 . integer . V_19 [ 0 ] ) ;
F_11 ( & V_21 -> V_22 ) ;
return V_10 ;
}
static int F_12 ( struct V_11 * V_12 , struct V_23 * V_24 )
{
V_24 -> type = V_25 ;
V_24 -> V_26 = 1 ;
V_24 -> V_19 . integer . V_27 = 0 ;
V_24 -> V_19 . integer . V_28 = 0x7f ;
return 0 ;
}
static int F_13 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_6 ;
unsigned char V_29 ;
if ( V_12 -> V_15 )
V_6 = V_16 ;
else
V_6 = F_8 ( V_12 , & V_14 -> V_17 ) + V_18 ;
V_29 = F_3 ( V_2 , V_6 ) & 0x7f ;
V_14 -> V_19 . integer . V_19 [ 0 ] = 0x7f - V_29 ;
return 0 ;
}
static int F_14 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_6 ;
unsigned char V_30 , V_31 , V_32 ;
int V_10 ;
if ( V_12 -> V_15 )
V_6 = V_16 ;
else
V_6 = F_8 ( V_12 , & V_14 -> V_17 ) + V_18 ;
V_32 = V_14 -> V_19 . integer . V_19 [ 0 ] ;
V_30 = F_3 ( V_2 , V_6 ) ;
V_31 = 0x7f - ( V_30 & 0x7f ) ;
V_10 = ( V_31 != V_32 ) ;
if ( V_10 ) {
V_31 = ( 0x7f - V_32 ) | ( V_30 & 0x80 ) ;
F_1 ( V_2 , V_6 , ( 0x7f - V_32 ) | ( V_30 & 0x80 ) ) ;
}
return V_10 ;
}
static int F_15 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
unsigned char V_4 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < 2 ; ++ V_33 ) {
V_4 = F_3 ( V_2 , V_34 + V_33 ) ;
V_14 -> V_19 . integer . V_19 [ V_33 ] = ~ V_4 >> 7 & 0x1 ;
}
return 0 ;
}
static int F_16 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
unsigned char V_8 , V_9 ;
int V_33 , V_3 ;
int V_10 ;
for ( V_33 = 0 ; V_33 < 2 ; ++ V_33 ) {
V_3 = V_34 + V_33 ;
V_9 = F_3 ( V_2 , V_3 ) ;
V_8 = ( ~ V_14 -> V_19 . integer . V_19 [ V_33 ] << 7 & 0x80 ) | ( V_9 & ~ 0x80 ) ;
V_10 = ( V_8 != V_9 ) ;
if ( V_10 )
F_1 ( V_2 , V_3 , V_8 ) ;
}
return V_10 ;
}
static int F_17 ( struct V_11 * V_12 , struct V_23 * V_24 )
{
V_24 -> type = V_25 ;
V_24 -> V_26 = 2 ;
V_24 -> V_19 . integer . V_27 = 0 ;
V_24 -> V_19 . integer . V_28 = 0x0f ;
return 0 ;
}
static int F_18 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_33 , V_3 ;
unsigned char V_29 ;
for ( V_33 = 0 ; V_33 < 2 ; ++ V_33 ) {
V_3 = V_34 + V_33 ;
V_29 = F_3 ( V_2 , V_3 ) & 0x0f ;
V_14 -> V_19 . integer . V_19 [ V_33 ] = 0x0f - V_29 ;
}
return 0 ;
}
static int F_19 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_33 , V_3 ;
unsigned char V_31 , V_32 ;
int V_10 ;
for ( V_33 = 0 ; V_33 < 2 ; ++ V_33 ) {
V_3 = V_34 + V_33 ;
V_32 = V_14 -> V_19 . integer . V_19 [ V_33 ] & 0x0f ;
V_31 = 0x0f - F_3 ( V_2 , V_3 ) ;
V_10 = ( ( V_31 & 0x0f ) != V_32 ) ;
if ( V_10 )
F_1 ( V_2 , V_3 , ( 0x0f - V_32 ) | ( V_31 & ~ 0x0f ) ) ;
}
return V_10 ;
}
static int F_20 ( struct V_11 * V_12 ,
struct V_23 * V_24 )
{
static const char * const V_35 [ 2 ] = { L_1 , L_2 } ;
return F_21 ( V_24 , 1 , 2 , V_35 ) ;
}
static int F_22 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
unsigned char V_4 ;
V_4 = F_3 ( V_2 , V_36 ) ;
V_14 -> V_19 . V_37 . V_38 [ 0 ] = ( V_4 >> 7 ) & 0x1 ;
return 0 ;
}
static int F_23 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
unsigned char V_8 , V_9 ;
int V_10 ;
V_9 = F_3 ( V_2 , V_36 ) ;
V_8 = ( V_14 -> V_19 . V_37 . V_38 [ 0 ] << 7 & 0x80 ) | ( V_9 & ~ 0x80 ) ;
V_10 = ( V_8 != V_9 ) ;
if ( V_10 )
F_1 ( V_2 , V_36 , V_8 ) ;
return V_10 ;
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_39 )
{
unsigned char V_9 , V_8 ;
int V_6 ;
unsigned char V_40 [ 7 ] ;
struct V_20 * V_21 = V_2 -> V_21 ;
if ( V_39 == 0 )
return;
else if ( V_39 <= 48000 )
V_8 = 0x08 ;
else if ( V_39 <= 96000 )
V_8 = 0x11 ;
else
V_8 = 0x12 ;
V_9 = F_3 ( V_2 , V_41 ) ;
if ( V_9 == V_8 )
return;
F_10 ( & V_21 -> V_22 ) ;
for ( V_6 = 0 ; V_6 < 7 ; ++ V_6 )
V_40 [ V_6 ] = F_5 ( V_2 ,
V_16 + V_6 , 0 ) ;
F_1 ( V_2 , V_41 , V_8 ) ;
F_25 ( 10 ) ;
for ( V_6 = 0 ; V_6 < 7 ; ++ V_6 ) {
if ( V_40 [ V_6 ] )
F_5 ( V_2 , V_16 + V_6 , 1 ) ;
}
F_11 ( & V_21 -> V_22 ) ;
}
static void F_26 ( struct V_1 * V_2 , unsigned int V_42 ,
unsigned int V_43 , int V_6 )
{
for (; V_6 >= 0 ; V_6 -- ) {
V_42 &= ~ V_44 ;
F_27 ( V_2 , V_42 ) ;
F_25 ( 1 ) ;
if ( V_43 & ( 1 << V_6 ) )
V_42 |= V_45 ;
else
V_42 &= ~ V_45 ;
F_27 ( V_2 , V_42 ) ;
F_25 ( 1 ) ;
V_42 |= V_44 ;
F_27 ( V_2 , V_42 ) ;
F_25 ( 1 ) ;
}
}
static unsigned char F_28 ( struct V_1 * V_2 , unsigned int V_42 ,
int V_6 )
{
unsigned char V_43 = 0 ;
for (; V_6 >= 0 ; V_6 -- ) {
V_42 &= ~ V_44 ;
F_27 ( V_2 , V_42 ) ;
F_25 ( 1 ) ;
if ( F_29 ( V_2 ) & V_46 )
V_43 |= ( 1 << V_6 ) ;
F_25 ( 1 ) ;
V_42 |= V_44 ;
F_27 ( V_2 , V_42 ) ;
F_25 ( 1 ) ;
}
return V_43 ;
}
static unsigned int F_30 ( struct V_1 * V_2 )
{
unsigned int V_30 ;
F_31 ( V_2 ) ;
V_30 = F_29 ( V_2 ) ;
V_30 |= V_44 ;
V_30 &= ~ V_47 ;
F_27 ( V_2 , V_30 ) ;
F_25 ( 1 ) ;
return V_30 ;
}
static void F_32 ( struct V_1 * V_2 , unsigned int V_30 )
{
V_30 |= V_47 ;
F_27 ( V_2 , V_30 ) ;
F_25 ( 1 ) ;
F_33 ( V_2 ) ;
}
static void F_34 ( void * V_48 , unsigned char V_49 ,
unsigned char V_43 )
{
struct V_1 * V_2 = V_48 ;
unsigned int V_30 , V_50 ;
V_30 = F_30 ( V_2 ) ;
V_50 = ( V_51 << 6 ) | 0x20 | ( V_49 & 0x1f ) ;
V_50 = ( V_50 << 8 ) | V_43 ;
F_26 ( V_2 , V_30 , V_50 , 15 ) ;
F_32 ( V_2 , V_30 ) ;
}
static unsigned char F_35 ( void * V_48 ,
unsigned char V_49 )
{
struct V_1 * V_2 = V_48 ;
unsigned int V_30 ;
unsigned char V_43 ;
V_30 = F_30 ( V_2 ) ;
F_26 ( V_2 , V_30 , ( V_51 << 6 ) | ( V_49 & 0x1f ) , 7 ) ;
V_43 = F_28 ( V_2 , V_30 , 7 ) ;
F_32 ( V_2 , V_30 ) ;
return V_43 ;
}
static int F_36 ( struct V_11 * V_12 ,
struct V_23 * V_24 )
{
static const char * const V_35 [ 2 ] = { L_3 , L_4 } ;
return F_21 ( V_24 , 1 , 2 , V_35 ) ;
}
static int F_37 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
unsigned char V_4 ;
V_4 = F_35 ( V_2 , V_52 ) ;
V_14 -> V_19 . V_37 . V_38 [ 0 ] = ( V_4 & V_53 ) ? 1 : 0 ;
return 0 ;
}
static int F_38 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
unsigned char V_8 , V_9 , V_54 ;
int V_10 ;
V_9 = F_35 ( V_2 , V_52 ) ;
V_54 = ( V_14 -> V_19 . V_37 . V_38 [ 0 ] ) ? 0xff : 0x00 ;
V_8 = ( V_54 & V_53 ) | ( V_9 & ~ V_53 ) ;
V_10 = ( V_8 != V_9 ) ;
if ( V_10 )
F_34 ( V_2 , V_52 , V_8 ) ;
return V_10 ;
}
static int F_39 ( struct V_1 * V_2 )
{
static const unsigned char V_55 [] = {
V_56 | V_57 | V_58 | V_59 ,
V_60 | V_61 ,
V_62 ,
V_63 | V_64 ,
0 ,
0
} ;
static const unsigned char V_65 [] = {
0x41 , 0x02 , 0x2c , 0x00 , 0x00
} ;
struct V_20 * V_21 = V_2 -> V_21 ;
int V_66 ;
V_66 = F_40 ( V_2 -> V_67 ,
F_35 ,
F_34 ,
V_55 , V_65 ,
V_2 , & V_21 -> V_68 ) ;
if ( V_66 < 0 )
return V_66 ;
V_21 -> V_68 -> V_69 = V_70 ;
return 0 ;
}
static void F_41 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = V_72 -> V_48 ;
int V_3 , V_4 ;
for ( V_3 = 0 ; V_3 <= 0x15 ; V_3 ++ ) {
V_4 = F_3 ( V_2 , V_3 ) ;
F_42 ( V_74 , L_5 , V_3 , V_4 ) ;
}
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_71 * V_72 ;
if ( ! F_44 ( V_2 -> V_67 , L_6 , & V_72 ) )
F_45 ( V_72 , V_2 , F_41 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = V_2 -> V_21 ;
unsigned int V_33 ;
int V_66 ;
for ( V_33 = 0 ; V_33 < F_47 ( V_75 ) ; V_33 ++ ) {
V_66 = F_48 ( V_2 -> V_67 ,
F_49 ( & V_75 [ V_33 ] , V_2 ) ) ;
if ( V_66 < 0 )
return V_66 ;
}
if ( V_21 -> V_68 ) {
for ( V_33 = 0 ; V_33 < F_47 ( V_76 ) ; V_33 ++ ) {
V_66 = F_48 ( V_2 -> V_67 ,
F_49 ( & V_76 [ V_33 ] ,
V_2 ) ) ;
if ( V_66 < 0 )
return V_66 ;
}
V_66 = F_50 ( V_21 -> V_68 ,
NULL ,
V_2 -> V_77 -> V_78 [ V_79 ] . V_80 ) ;
if ( V_66 < 0 )
return V_66 ;
}
F_43 ( V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
unsigned char V_81 ;
const unsigned char V_82 = 0xd1 ;
unsigned char V_49 = V_83 ;
int V_84 = 0 ;
V_81 = F_35 ( V_2 , V_49 ) ;
F_34 ( V_2 , V_49 , V_82 ) ;
if ( F_35 ( V_2 , V_49 ) == V_82 ) {
F_34 ( V_2 , V_49 , V_81 ) ;
V_84 = 1 ;
}
return V_84 ;
}
static int F_52 ( struct V_1 * V_2 )
{
static const unsigned short V_85 [] = {
V_86 , 0 ,
V_41 , 0x11 ,
( unsigned short ) - 1
} ;
const unsigned short * V_87 ;
int V_66 = 0 ;
struct V_20 * V_21 ;
V_2 -> V_88 = 6 ;
V_2 -> V_89 = 2 ;
V_2 -> V_90 = 0 ;
V_21 = F_53 ( sizeof( * V_21 ) , V_91 ) ;
if ( ! V_21 )
return - V_92 ;
V_2 -> V_21 = V_21 ;
F_54 ( & V_21 -> V_22 ) ;
V_87 = V_85 ;
for (; * V_87 != ( unsigned short ) - 1 ; V_87 += 2 )
F_1 ( V_2 , V_87 [ 0 ] , V_87 [ 1 ] ) ;
V_2 -> V_42 . V_93 = F_24 ;
if ( F_51 ( V_2 ) ) {
V_66 = F_39 ( V_2 ) ;
F_55 ( V_2 -> V_67 -> V_94 ,
L_7 , V_66 ) ;
} else
F_55 ( V_2 -> V_67 -> V_94 , L_8 ) ;
return V_66 ;
}
