static int F_1 ( int V_1 )
{
if ( V_1 < 0 || V_1 > 23 )
return - 1 ;
return ( V_1 >> 3 ) + 1 ;
}
static void F_2 ( struct V_2 * V_3 , int V_4 )
{
int V_5 , V_6 , V_7 , V_8 ;
V_8 = F_1 ( V_4 ) ;
V_7 = V_3 -> V_9 [ V_8 - 1 ] ;
V_5 = V_6 = 1 ;
if ( V_4 % 2 == 0 ) {
V_5 <<= V_4 & 0x07 ;
V_6 <<= ( V_4 + 1 ) & 0x07 ;
} else {
V_5 <<= ( V_4 - 1 ) & 0x07 ;
V_6 <<= V_4 & 0x07 ;
}
V_7 |= V_5 ;
V_7 &= ~ V_6 ;
F_3 ( 1 , V_3 -> V_10 + 0 ) ;
F_3 ( V_7 , V_3 -> V_10 + V_8 ) ;
F_3 ( 0 , V_3 -> V_10 + 0 ) ;
V_3 -> V_9 [ V_8 - 1 ] = V_7 ;
}
static int F_4 ( struct V_2 * V_3 ,
unsigned int * V_11 , int V_4 , int V_12 )
{
int V_8 , V_13 = 1 << ( V_4 & 0x07 ) ;
V_8 = F_1 ( V_4 ) ;
if ( V_8 < 0 ) {
F_5 ( L_1 ,
V_12 , V_4 ) ;
return 0 ;
}
* V_11 = F_6 ( V_3 -> V_10 + V_8 ) ;
* V_11 &= V_13 ;
if ( V_8 > 1 )
V_4 -= 2 << V_8 ;
* V_11 >>= V_4 ;
return 1 ;
}
static int F_7 ( struct V_2 * V_3 ,
unsigned int * V_11 , int V_4 , int V_12 )
{
int V_14 , V_15 ;
char V_16 ;
V_14 = V_4 / 2 ;
V_15 = V_4 % 2 ;
if ( V_3 -> V_17 [ V_14 ] & V_18 ) {
F_5 ( L_2 ,
V_12 , V_14 , V_3 -> V_17 [ V_14 ] ) ;
return 0 ;
}
F_2 ( V_3 , V_4 ) ;
F_3 ( V_14 + 1 , V_3 -> V_10 + 5 ) ;
F_3 ( 'V' , V_3 -> V_10 + 6 ) ;
V_16 = F_6 ( V_3 -> V_10 ) ;
while ( ! ( ( V_16 = F_6 ( V_3 -> V_10 + 0 ) ) & V_19 ) )
;
if ( ( V_16 & V_20 ) ) {
F_8 ( L_3 ) ;
return 0 ;
}
if ( V_15 )
* V_11 = F_9 ( V_3 -> V_10 + 6 ) ;
else
* V_11 = F_9 ( V_3 -> V_10 + 4 ) ;
return 1 ;
}
static int F_10 ( struct V_2 * V_3 ,
unsigned int * V_11 , int V_4 , int V_12 )
{
int V_8 , V_21 ;
int V_13 = 1 << ( V_4 & 0x07 ) ;
V_8 = F_1 ( V_4 ) ;
if ( V_8 < 0 ) {
F_5 ( L_1 ,
V_12 , V_4 ) ;
return 0 ;
}
V_21 = V_3 -> V_22 [ V_8 - 1 ] ;
if ( * V_11 )
V_21 |= V_13 ;
else
V_21 &= ~ V_13 ;
F_3 ( V_21 , V_3 -> V_10 + V_8 ) ;
V_3 -> V_22 [ V_8 - 1 ] = V_21 ;
return 1 ;
}
static int F_11 ( struct V_2 * V_3 ,
unsigned int * V_11 , int V_4 , int V_12 )
{
int V_23 , V_24 ;
V_23 = V_4 / 2 ;
V_24 = ( V_4 % 2 ) << 1 ;
if ( ! ( V_3 -> V_17 [ V_23 ] & V_18 ) ) {
F_5 ( L_4 ,
V_12 , V_23 , V_3 -> V_17 [ V_23 ] ) ;
return 0 ;
}
F_2 ( V_3 , V_4 ) ;
V_3 -> V_25 [ V_23 ] [ V_24 ++ ] = ( unsigned char ) ( * V_11 & 0x00FF ) ;
V_3 -> V_25 [ V_23 ] [ V_24 ] = ( unsigned char ) ( ( * V_11 & 0xFF00 ) >> 8 ) ;
F_3 ( V_23 + 1 , V_3 -> V_10 + 5 ) ;
F_3 ( 'W' , V_3 -> V_10 + 6 ) ;
for ( V_24 = 0 ; V_24 < 4 ; V_24 ++ ) {
while ( ! ( ( F_6 ( V_3 -> V_10 + 0 ) ) & V_26 ) )
;
F_3 ( V_3 -> V_25 [ V_23 ] [ V_24 ] , V_3 -> V_10 + 6 ) ;
}
return 1 ;
}
static int F_12 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
struct V_31 * V_32 , unsigned int * V_11 )
{
struct V_2 * V_3 = V_30 -> V_33 ;
int V_4 , type ;
V_4 = F_13 ( V_32 -> V_34 ) ;
type = V_3 -> V_17 [ V_4 / 2 ] ;
if ( type == V_35 ) {
if ( ! F_4 ( V_3 , V_11 , V_4 , V_28 -> V_12 ) )
return - 1 ;
} else {
if ( ! F_7 ( V_3 , V_11 , V_4 , V_28 -> V_12 ) )
return - 1 ;
}
return 1 ;
}
static int F_14 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
struct V_31 * V_32 , unsigned int * V_11 )
{
struct V_2 * V_3 = V_30 -> V_33 ;
int V_4 , type ;
V_4 = F_13 ( V_32 -> V_34 ) ;
type = V_3 -> V_17 [ V_4 / 2 ] ;
if ( type == V_35 ) {
if ( ! F_10 ( V_3 , V_11 , V_4 , V_28 -> V_12 ) )
return - 1 ;
} else {
if ( ! F_11 ( V_3 , V_11 , V_4 , V_28 -> V_12 ) )
return - 1 ;
}
return 1 ;
}
static int F_15 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
struct V_31 * V_32 , unsigned int * V_11 )
{
int V_8 , V_36 , V_4 = F_13 ( V_32 -> V_34 ) , type ;
struct V_2 * V_3 = V_30 -> V_33 ;
int V_13 = 1 << ( V_4 & 0x07 ) ;
type = V_3 -> V_17 [ V_4 / 2 ] ;
if ( type != V_35 ) {
F_16 ( V_28 -> V_37 ,
L_5 ,
V_28 -> V_12 ) ;
return - 1 ;
}
V_8 = F_1 ( V_4 ) ;
if ( V_8 < 0 ) {
F_16 ( V_28 -> V_37 ,
L_1 ,
V_28 -> V_12 , V_4 ) ;
return - 1 ;
}
V_36 = V_3 -> V_9 [ V_8 - 1 ] ;
switch ( * V_11 ) {
case V_38 :
V_36 &= ~ V_13 ;
break;
case V_39 :
V_36 |= V_13 ;
break;
default:
F_16 ( V_28 -> V_37 ,
L_6 , V_28 -> V_12 ) ;
return - 1 ;
}
F_3 ( 1 , V_3 -> V_10 + 0 ) ;
F_3 ( V_36 , V_3 -> V_10 + V_8 ) ;
F_3 ( 0 , V_3 -> V_10 + 0 ) ;
V_3 -> V_9 [ V_8 - 1 ] = V_36 ;
return 0 ;
}
static int F_17 ( struct V_29 * V_30 ,
int V_40 , int V_12 )
{
struct V_2 * V_3 ;
int V_24 , V_41 , V_42 = 0 ;
if ( ! F_18 ( V_40 , V_43 , V_44 ) ) {
F_16 ( V_30 -> V_37 ,
L_7 , V_12 ) ;
return - V_45 ;
}
V_3 = F_19 ( sizeof( * V_3 ) , V_46 ) ;
if ( V_3 == NULL )
return - 1 ;
V_3 -> V_10 = V_40 ;
F_20 ( V_30 -> V_37 , L_8 , V_12 ) ;
for ( V_24 = 0 ; V_24 < 12 ; V_24 ++ ) {
V_41 = 10000 ;
F_2 ( V_3 , V_24 * 2 ) ;
F_3 ( V_24 + 1 , V_40 + 5 ) ;
F_3 ( 'H' , V_40 + 6 ) ;
while ( ! ( F_6 ( V_40 + 0 ) & V_26 ) )
;
F_3 ( 0 , V_40 + 6 ) ;
while ( ! ( F_6 ( V_40 + 0 ) & V_47 ) ) {
if ( -- V_41 <= 0 ) {
V_42 = 1 ;
break;
}
}
if ( V_42 ) {
V_3 -> V_17 [ V_24 ] = 0 ;
V_42 = 0 ;
} else
V_3 -> V_17 [ V_24 ] = F_6 ( V_40 + 6 ) ;
F_8 ( L_9 , V_24 , V_3 -> V_17 [ V_24 ] ) ;
F_21 ( 1 ) ;
}
F_8 ( L_10 ) ;
V_30 -> type = V_48 ;
V_30 -> V_33 = V_3 ;
V_30 -> V_49 = V_50 | V_51 ;
V_30 -> V_52 = V_53 ;
V_30 -> V_54 = 0xFFF ;
V_30 -> V_55 = & V_56 ;
V_30 -> V_57 = F_12 ;
V_30 -> V_58 = F_14 ;
V_30 -> V_59 = F_15 ;
return 0 ;
}
static int F_22 ( struct V_27 * V_28 ,
struct V_60 * V_61 )
{
int V_62 , V_24 , V_63 ;
int V_64 , V_65 , V_66 ;
int V_67 ;
V_62 = V_61 -> V_68 [ 0 ] ;
V_28 -> V_69 = V_44 ;
V_28 -> V_62 = V_62 ;
V_62 += V_70 ;
for ( V_24 = V_63 = 0 , V_66 = V_62 ; V_24 < 4 ; V_24 ++ , V_66 += V_71 ) {
V_64 = F_6 ( V_66 + 0xE ) ;
V_65 = F_6 ( V_66 + 0xF ) ;
if ( V_64 != 'g' || V_65 != 1 )
continue;
V_63 ++ ;
}
if ( V_63 < 2 ) {
F_16 ( V_28 -> V_37 ,
L_11 ) ;
return - 1 ;
}
V_67 = F_23 ( V_28 , V_63 ) ;
if ( V_67 )
return V_67 ;
for ( V_24 = 0 ; V_24 < V_63 ; V_24 ++ , V_62 += V_71 ) {
if ( F_17 ( & V_28 -> V_72 [ V_24 ] , V_62 ,
V_28 -> V_12 ) < 0 )
return - 1 ;
}
return 0 ;
}
static void F_24 ( struct V_27 * V_28 )
{
int V_24 ;
struct V_29 * V_30 ;
struct V_2 * V_3 ;
for ( V_24 = 0 ; V_24 < V_28 -> V_73 ; V_24 ++ ) {
V_30 = & V_28 -> V_72 [ V_24 ] ;
V_3 = V_30 -> V_33 ;
F_25 ( V_3 -> V_10 , V_43 ) ;
F_26 ( V_30 -> V_33 ) ;
}
}
