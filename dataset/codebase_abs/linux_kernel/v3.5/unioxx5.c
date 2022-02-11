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
F_5 ( V_14
L_1 ,
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
int V_15 , V_16 ;
char V_17 ;
V_15 = V_4 / 2 ;
V_16 = V_4 % 2 ;
if ( V_3 -> V_18 [ V_15 ] & V_19 ) {
F_5 ( V_14
L_2 ,
V_12 , V_15 , V_3 -> V_18 [ V_15 ] ) ;
return 0 ;
}
F_2 ( V_3 , V_4 ) ;
F_3 ( V_15 + 1 , V_3 -> V_10 + 5 ) ;
F_3 ( 'V' , V_3 -> V_10 + 6 ) ;
V_17 = F_6 ( V_3 -> V_10 ) ;
while ( ! ( ( V_17 = F_6 ( V_3 -> V_10 + 0 ) ) & V_20 ) )
;
if ( ( V_17 & V_21 ) ) {
F_5 ( L_3 ) ;
return 0 ;
}
if ( V_16 )
* V_11 = F_8 ( V_3 -> V_10 + 6 ) ;
else
* V_11 = F_8 ( V_3 -> V_10 + 4 ) ;
return 1 ;
}
static int F_9 ( struct V_2 * V_3 ,
unsigned int * V_11 , int V_4 , int V_12 )
{
int V_8 , V_22 ;
int V_13 = 1 << ( V_4 & 0x07 ) ;
V_8 = F_1 ( V_4 ) ;
if ( V_8 < 0 ) {
F_5 ( V_14
L_1 ,
V_12 , V_4 ) ;
return 0 ;
}
V_22 = V_3 -> V_23 [ V_8 - 1 ] ;
if ( * V_11 )
V_22 |= V_13 ;
else
V_22 &= ~ V_13 ;
F_3 ( V_22 , V_3 -> V_10 + V_8 ) ;
V_3 -> V_23 [ V_8 - 1 ] = V_22 ;
return 1 ;
}
static int F_10 ( struct V_2 * V_3 ,
unsigned int * V_11 , int V_4 , int V_12 )
{
int V_24 , V_25 ;
V_24 = V_4 / 2 ;
V_25 = ( V_4 % 2 ) << 1 ;
if ( ! ( V_3 -> V_18 [ V_24 ] & V_19 ) ) {
F_5 ( V_14
L_4 ,
V_12 , V_24 , V_3 -> V_18 [ V_24 ] ) ;
return 0 ;
}
F_2 ( V_3 , V_4 ) ;
V_3 -> V_26 [ V_24 ] [ V_25 ++ ] = ( unsigned char ) ( * V_11 & 0x00FF ) ;
V_3 -> V_26 [ V_24 ] [ V_25 ] = ( unsigned char ) ( ( * V_11 & 0xFF00 ) >> 8 ) ;
F_3 ( V_24 + 1 , V_3 -> V_10 + 5 ) ;
F_3 ( 'W' , V_3 -> V_10 + 6 ) ;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ ) {
while ( ! ( ( F_6 ( V_3 -> V_10 + 0 ) ) & V_27 ) )
;
F_3 ( V_3 -> V_26 [ V_24 ] [ V_25 ] , V_3 -> V_10 + 6 ) ;
}
return 1 ;
}
static int F_11 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_32 * V_33 , unsigned int * V_11 )
{
struct V_2 * V_3 = V_31 -> V_34 ;
int V_4 , type ;
V_4 = F_12 ( V_33 -> V_35 ) ;
type = V_3 -> V_18 [ V_4 / 2 ] ;
if ( type == V_36 ) {
if ( ! F_4 ( V_3 , V_11 , V_4 , V_29 -> V_12 ) )
return - 1 ;
} else {
if ( ! F_7 ( V_3 , V_11 , V_4 , V_29 -> V_12 ) )
return - 1 ;
}
return 1 ;
}
static int F_13 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_32 * V_33 , unsigned int * V_11 )
{
struct V_2 * V_3 = V_31 -> V_34 ;
int V_4 , type ;
V_4 = F_12 ( V_33 -> V_35 ) ;
type = V_3 -> V_18 [ V_4 / 2 ] ;
if ( type == V_36 ) {
if ( ! F_9 ( V_3 , V_11 , V_4 , V_29 -> V_12 ) )
return - 1 ;
} else {
if ( ! F_10 ( V_3 , V_11 , V_4 , V_29 -> V_12 ) )
return - 1 ;
}
return 1 ;
}
static int F_14 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
struct V_32 * V_33 , unsigned int * V_11 )
{
int V_8 , V_37 , V_4 = F_12 ( V_33 -> V_35 ) , type ;
struct V_2 * V_3 = V_31 -> V_34 ;
int V_13 = 1 << ( V_4 & 0x07 ) ;
type = V_3 -> V_18 [ V_4 / 2 ] ;
if ( type != V_36 ) {
F_5 ( V_14
L_5 ,
V_29 -> V_12 ) ;
return - 1 ;
}
V_8 = F_1 ( V_4 ) ;
if ( V_8 < 0 ) {
F_5 ( V_14
L_1 ,
V_29 -> V_12 , V_4 ) ;
return - 1 ;
}
V_37 = V_3 -> V_9 [ V_8 - 1 ] ;
switch ( * V_11 ) {
case V_38 :
V_37 &= ~ V_13 ;
break;
case V_39 :
V_37 |= V_13 ;
break;
default:
F_5 ( V_14 L_6 , V_29 -> V_12 ) ;
return - 1 ;
}
F_3 ( 1 , V_3 -> V_10 + 0 ) ;
F_3 ( V_37 , V_3 -> V_10 + V_8 ) ;
F_3 ( 0 , V_3 -> V_10 + 0 ) ;
V_3 -> V_9 [ V_8 - 1 ] = V_37 ;
return 0 ;
}
static int F_15 ( struct V_30 * V_31 ,
int V_40 , int V_12 )
{
struct V_2 * V_3 ;
int V_25 , V_41 , V_42 = 0 ;
if ( ! F_16 ( V_40 , V_43 , V_44 ) ) {
F_5 ( V_14 L_7 , V_12 ) ;
return - V_45 ;
}
V_3 = F_17 ( sizeof( * V_3 ) , V_46 ) ;
if ( V_3 == NULL ) {
F_5 ( V_14 L_8 , V_12 ) ;
return - 1 ;
}
V_3 -> V_10 = V_40 ;
F_5 ( V_47 L_9 , V_12 ) ;
for ( V_25 = 0 ; V_25 < 12 ; V_25 ++ ) {
V_41 = 10000 ;
F_2 ( V_3 , V_25 * 2 ) ;
F_3 ( V_25 + 1 , V_40 + 5 ) ;
F_3 ( 'H' , V_40 + 6 ) ;
while ( ! ( F_6 ( V_40 + 0 ) & V_27 ) )
;
F_3 ( 0 , V_40 + 6 ) ;
while ( ! ( F_6 ( V_40 + 0 ) & V_48 ) ) {
if ( -- V_41 <= 0 ) {
V_42 = 1 ;
break;
}
}
if ( V_42 ) {
V_3 -> V_18 [ V_25 ] = 0 ;
V_42 = 0 ;
} else
V_3 -> V_18 [ V_25 ] = F_6 ( V_40 + 6 ) ;
F_5 ( L_10 , V_25 , V_3 -> V_18 [ V_25 ] ) ;
F_18 ( 1 ) ;
}
F_5 ( L_11 ) ;
V_31 -> type = V_49 ;
V_31 -> V_34 = V_3 ;
V_31 -> V_50 = V_51 | V_52 ;
V_31 -> V_53 = V_54 ;
V_31 -> V_55 = 0xFFF ;
V_31 -> V_56 = & V_57 ;
V_31 -> V_58 = F_11 ;
V_31 -> V_59 = F_13 ;
V_31 -> V_60 = F_14 ;
F_5 ( V_47 L_12 ) ;
return 0 ;
}
static int F_19 ( struct V_28 * V_29 ,
struct V_61 * V_62 )
{
int V_63 , V_25 , V_64 ;
int V_65 , V_66 , V_67 ;
V_63 = V_62 -> V_68 [ 0 ] ;
V_29 -> V_69 = V_44 ;
V_29 -> V_63 = V_63 ;
V_63 += V_70 ;
for ( V_25 = V_64 = 0 , V_67 = V_63 ; V_25 < 4 ; V_25 ++ , V_67 += V_71 ) {
V_65 = F_6 ( V_67 + 0xE ) ;
V_66 = F_6 ( V_67 + 0xF ) ;
if ( V_65 != 'g' || V_66 != 1 )
continue;
V_64 ++ ;
}
if ( V_64 < 2 ) {
F_5 ( V_14
L_13 ) ;
return - 1 ;
}
if ( F_20 ( V_29 , V_64 ) < 0 ) {
F_5 ( V_14 L_14 ) ;
return - V_72 ;
}
for ( V_25 = 0 ; V_25 < V_64 ; V_25 ++ , V_63 += V_71 ) {
if ( F_15 ( & V_29 -> V_73 [ V_25 ] , V_63 ,
V_29 -> V_12 ) < 0 )
return - 1 ;
}
F_5 ( V_47 L_15 ) ;
return 0 ;
}
static void F_21 ( struct V_28 * V_29 )
{
int V_25 ;
struct V_30 * V_31 ;
struct V_2 * V_3 ;
for ( V_25 = 0 ; V_25 < V_29 -> V_74 ; V_25 ++ ) {
V_31 = & V_29 -> V_73 [ V_25 ] ;
V_3 = V_31 -> V_34 ;
F_22 ( V_3 -> V_10 , V_43 ) ;
F_23 ( V_31 -> V_34 ) ;
}
}
