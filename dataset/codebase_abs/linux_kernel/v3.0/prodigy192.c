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
static char * V_35 [ 2 ] = { L_1 , L_2 } ;
V_24 -> type = V_36 ;
V_24 -> V_26 = 1 ;
V_24 -> V_19 . V_37 . V_38 = 2 ;
if ( V_24 -> V_19 . V_37 . V_39 >= V_24 -> V_19 . V_37 . V_38 )
V_24 -> V_19 . V_37 . V_39 = V_24 -> V_19 . V_37 . V_38 - 1 ;
strcpy ( V_24 -> V_19 . V_37 . V_40 , V_35 [ V_24 -> V_19 . V_37 . V_39 ] ) ;
return 0 ;
}
static int F_21 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
unsigned char V_4 ;
V_4 = F_3 ( V_2 , V_41 ) ;
V_14 -> V_19 . V_37 . V_39 [ 0 ] = ( V_4 >> 7 ) & 0x1 ;
return 0 ;
}
static int F_22 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
unsigned char V_8 , V_9 ;
int V_10 ;
V_9 = F_3 ( V_2 , V_41 ) ;
V_8 = ( V_14 -> V_19 . V_37 . V_39 [ 0 ] << 7 & 0x80 ) | ( V_9 & ~ 0x80 ) ;
V_10 = ( V_8 != V_9 ) ;
if ( V_10 )
F_1 ( V_2 , V_41 , V_8 ) ;
return V_10 ;
}
static void F_23 ( struct V_1 * V_2 , unsigned int V_42 )
{
unsigned char V_9 , V_8 ;
int V_6 ;
unsigned char V_43 [ 7 ] ;
struct V_20 * V_21 = V_2 -> V_21 ;
if ( V_42 == 0 )
return;
else if ( V_42 <= 48000 )
V_8 = 0x08 ;
else if ( V_42 <= 96000 )
V_8 = 0x11 ;
else
V_8 = 0x12 ;
V_9 = F_3 ( V_2 , V_44 ) ;
if ( V_9 == V_8 )
return;
F_10 ( & V_21 -> V_22 ) ;
for ( V_6 = 0 ; V_6 < 7 ; ++ V_6 )
V_43 [ V_6 ] = F_5 ( V_2 ,
V_16 + V_6 , 0 ) ;
F_1 ( V_2 , V_44 , V_8 ) ;
F_24 ( 10 ) ;
for ( V_6 = 0 ; V_6 < 7 ; ++ V_6 ) {
if ( V_43 [ V_6 ] )
F_5 ( V_2 , V_16 + V_6 , 1 ) ;
}
F_11 ( & V_21 -> V_22 ) ;
}
static void F_25 ( struct V_1 * V_2 , unsigned int V_45 ,
unsigned int V_46 , int V_6 )
{
for (; V_6 >= 0 ; V_6 -- ) {
V_45 &= ~ V_47 ;
F_26 ( V_2 , V_45 ) ;
F_24 ( 1 ) ;
if ( V_46 & ( 1 << V_6 ) )
V_45 |= V_48 ;
else
V_45 &= ~ V_48 ;
F_26 ( V_2 , V_45 ) ;
F_24 ( 1 ) ;
V_45 |= V_47 ;
F_26 ( V_2 , V_45 ) ;
F_24 ( 1 ) ;
}
}
static unsigned char F_27 ( struct V_1 * V_2 , unsigned int V_45 ,
int V_6 )
{
unsigned char V_46 = 0 ;
for (; V_6 >= 0 ; V_6 -- ) {
V_45 &= ~ V_47 ;
F_26 ( V_2 , V_45 ) ;
F_24 ( 1 ) ;
if ( F_28 ( V_2 ) & V_49 )
V_46 |= ( 1 << V_6 ) ;
F_24 ( 1 ) ;
V_45 |= V_47 ;
F_26 ( V_2 , V_45 ) ;
F_24 ( 1 ) ;
}
return V_46 ;
}
static unsigned int F_29 ( struct V_1 * V_2 )
{
unsigned int V_30 ;
F_30 ( V_2 ) ;
V_30 = F_28 ( V_2 ) ;
V_30 |= V_47 ;
V_30 &= ~ V_50 ;
F_26 ( V_2 , V_30 ) ;
F_24 ( 1 ) ;
return V_30 ;
}
static void F_31 ( struct V_1 * V_2 , unsigned int V_30 )
{
V_30 |= V_50 ;
F_26 ( V_2 , V_30 ) ;
F_24 ( 1 ) ;
F_32 ( V_2 ) ;
}
static void F_33 ( void * V_51 , unsigned char V_52 ,
unsigned char V_46 )
{
struct V_1 * V_2 = V_51 ;
unsigned int V_30 , V_53 ;
V_30 = F_29 ( V_2 ) ;
V_53 = ( V_54 << 6 ) | 0x20 | ( V_52 & 0x1f ) ;
V_53 = ( V_53 << 8 ) | V_46 ;
F_25 ( V_2 , V_30 , V_53 , 15 ) ;
F_31 ( V_2 , V_30 ) ;
}
static unsigned char F_34 ( void * V_51 ,
unsigned char V_52 )
{
struct V_1 * V_2 = V_51 ;
unsigned int V_30 ;
unsigned char V_46 ;
V_30 = F_29 ( V_2 ) ;
F_25 ( V_2 , V_30 , ( V_54 << 6 ) | ( V_52 & 0x1f ) , 7 ) ;
V_46 = F_27 ( V_2 , V_30 , 7 ) ;
F_31 ( V_2 , V_30 ) ;
return V_46 ;
}
static int F_35 ( struct V_11 * V_12 ,
struct V_23 * V_24 )
{
static char * V_35 [ 2 ] = { L_3 , L_4 } ;
V_24 -> type = V_36 ;
V_24 -> V_26 = 1 ;
V_24 -> V_19 . V_37 . V_38 = 2 ;
if ( V_24 -> V_19 . V_37 . V_39 >= V_24 -> V_19 . V_37 . V_38 )
V_24 -> V_19 . V_37 . V_39 = V_24 -> V_19 . V_37 . V_38 - 1 ;
strcpy ( V_24 -> V_19 . V_37 . V_40 , V_35 [ V_24 -> V_19 . V_37 . V_39 ] ) ;
return 0 ;
}
static int F_36 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
unsigned char V_4 ;
V_4 = F_34 ( V_2 , V_55 ) ;
V_14 -> V_19 . V_37 . V_39 [ 0 ] = ( V_4 & V_56 ) ? 1 : 0 ;
return 0 ;
}
static int F_37 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
unsigned char V_8 , V_9 , V_57 ;
int V_10 ;
V_9 = F_34 ( V_2 , V_55 ) ;
V_57 = ( V_14 -> V_19 . V_37 . V_39 [ 0 ] ) ? 0xff : 0x00 ;
V_8 = ( V_57 & V_56 ) | ( V_9 & ~ V_56 ) ;
V_10 = ( V_8 != V_9 ) ;
if ( V_10 )
F_33 ( V_2 , V_55 , V_8 ) ;
return V_10 ;
}
static int F_38 ( struct V_1 * V_2 )
{
static const unsigned char V_58 [] = {
V_59 | V_60 | V_61 | V_62 ,
V_63 | V_64 ,
V_65 ,
V_66 | V_67 ,
0 ,
0
} ;
static const unsigned char V_68 [] = {
0x41 , 0x02 , 0x2c , 0x00 , 0x00
} ;
struct V_20 * V_21 = V_2 -> V_21 ;
int V_69 ;
V_69 = F_39 ( V_2 -> V_70 ,
F_34 ,
F_33 ,
V_58 , V_68 ,
V_2 , & V_21 -> V_71 ) ;
if ( V_69 < 0 )
return V_69 ;
V_21 -> V_71 -> V_72 = V_73 ;
return 0 ;
}
static void F_40 ( struct V_74 * V_75 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 = V_75 -> V_51 ;
int V_3 , V_4 ;
for ( V_3 = 0 ; V_3 <= 0x15 ; V_3 ++ ) {
V_4 = F_3 ( V_2 , V_3 ) ;
F_41 ( V_77 , L_5 , V_3 , V_4 ) ;
}
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_74 * V_75 ;
if ( ! F_43 ( V_2 -> V_70 , L_6 , & V_75 ) )
F_44 ( V_75 , V_2 , F_40 ) ;
}
static int T_1 F_45 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = V_2 -> V_21 ;
unsigned int V_33 ;
int V_69 ;
for ( V_33 = 0 ; V_33 < F_46 ( V_78 ) ; V_33 ++ ) {
V_69 = F_47 ( V_2 -> V_70 ,
F_48 ( & V_78 [ V_33 ] , V_2 ) ) ;
if ( V_69 < 0 )
return V_69 ;
}
if ( V_21 -> V_71 ) {
for ( V_33 = 0 ; V_33 < F_46 ( V_79 ) ; V_33 ++ ) {
V_69 = F_47 ( V_2 -> V_70 ,
F_48 ( & V_79 [ V_33 ] ,
V_2 ) ) ;
if ( V_69 < 0 )
return V_69 ;
}
V_69 = F_49 ( V_21 -> V_71 ,
NULL ,
V_2 -> V_80 -> V_81 [ V_82 ] . V_83 ) ;
if ( V_69 < 0 )
return V_69 ;
}
F_42 ( V_2 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
unsigned char V_84 ;
const unsigned char V_85 = 0xd1 ;
unsigned char V_52 = V_86 ;
int V_87 = 0 ;
V_84 = F_34 ( V_2 , V_52 ) ;
F_33 ( V_2 , V_52 , V_85 ) ;
if ( F_34 ( V_2 , V_52 ) == V_85 ) {
F_33 ( V_2 , V_52 , V_84 ) ;
V_87 = 1 ;
}
return V_87 ;
}
static int T_1 F_51 ( struct V_1 * V_2 )
{
static const unsigned short V_88 [] = {
V_89 , 0 ,
V_44 , 0x11 ,
( unsigned short ) - 1
} ;
const unsigned short * V_90 ;
int V_69 = 0 ;
struct V_20 * V_21 ;
V_2 -> V_91 = 6 ;
V_2 -> V_92 = 2 ;
V_2 -> V_93 = 0 ;
V_21 = F_52 ( sizeof( * V_21 ) , V_94 ) ;
if ( ! V_21 )
return - V_95 ;
V_2 -> V_21 = V_21 ;
F_53 ( & V_21 -> V_22 ) ;
V_90 = V_88 ;
for (; * V_90 != ( unsigned short ) - 1 ; V_90 += 2 )
F_1 ( V_2 , V_90 [ 0 ] , V_90 [ 1 ] ) ;
V_2 -> V_45 . V_96 = F_23 ;
if ( F_50 ( V_2 ) ) {
V_69 = F_38 ( V_2 ) ;
F_54 ( L_7 , V_69 ) ;
} else
F_54 ( L_8 ) ;
if ( V_69 < 0 )
return V_69 ;
return 0 ;
}
