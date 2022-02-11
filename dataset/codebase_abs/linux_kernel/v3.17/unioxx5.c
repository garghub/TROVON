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
static int F_4 ( struct V_11 * V_12 ,
unsigned int * V_13 , int V_4 , int V_14 )
{
struct V_2 * V_3 = V_12 -> V_15 ;
struct V_16 * V_17 = V_12 -> V_16 -> V_18 ;
int V_8 , V_19 = 1 << ( V_4 & 0x07 ) ;
V_8 = F_1 ( V_4 ) ;
if ( V_8 < 0 ) {
F_5 ( V_17 ,
L_1 ,
V_4 ) ;
return 0 ;
}
* V_13 = F_6 ( V_3 -> V_10 + V_8 ) ;
* V_13 &= V_19 ;
if ( V_8 > 1 )
V_4 -= 2 << V_8 ;
* V_13 >>= V_4 ;
return 1 ;
}
static int F_7 ( struct V_11 * V_12 ,
unsigned int * V_13 , int V_4 , int V_14 )
{
struct V_2 * V_3 = V_12 -> V_15 ;
struct V_16 * V_17 = V_12 -> V_16 -> V_18 ;
int V_20 , V_21 ;
char V_22 ;
V_20 = V_4 / 2 ;
V_21 = V_4 % 2 ;
if ( V_3 -> V_23 [ V_20 ] & V_24 ) {
F_5 ( V_17 ,
L_2 ,
V_20 , V_3 -> V_23 [ V_20 ] ) ;
return 0 ;
}
F_2 ( V_3 , V_4 ) ;
F_3 ( V_20 + 1 , V_3 -> V_10 + 5 ) ;
F_3 ( 'V' , V_3 -> V_10 + 6 ) ;
V_22 = F_6 ( V_3 -> V_10 ) ;
while ( ! ( ( V_22 = F_6 ( V_3 -> V_10 + 0 ) ) & V_25 ) )
;
if ( ( V_22 & V_26 ) ) {
F_5 ( V_17 , L_3 ) ;
return 0 ;
}
if ( V_21 )
* V_13 = F_8 ( V_3 -> V_10 + 6 ) ;
else
* V_13 = F_8 ( V_3 -> V_10 + 4 ) ;
return 1 ;
}
static int F_9 ( struct V_11 * V_12 ,
unsigned int * V_13 , int V_4 , int V_14 )
{
struct V_2 * V_3 = V_12 -> V_15 ;
struct V_16 * V_17 = V_12 -> V_16 -> V_18 ;
int V_8 , V_27 ;
int V_19 = 1 << ( V_4 & 0x07 ) ;
V_8 = F_1 ( V_4 ) ;
if ( V_8 < 0 ) {
F_5 ( V_17 ,
L_1 ,
V_4 ) ;
return 0 ;
}
V_27 = V_3 -> V_28 [ V_8 - 1 ] ;
if ( * V_13 )
V_27 |= V_19 ;
else
V_27 &= ~ V_19 ;
F_3 ( V_27 , V_3 -> V_10 + V_8 ) ;
V_3 -> V_28 [ V_8 - 1 ] = V_27 ;
return 1 ;
}
static int F_10 ( struct V_11 * V_12 ,
unsigned int * V_13 , int V_4 , int V_14 )
{
struct V_2 * V_3 = V_12 -> V_15 ;
struct V_16 * V_17 = V_12 -> V_16 -> V_18 ;
int V_29 , V_30 ;
V_29 = V_4 / 2 ;
V_30 = ( V_4 % 2 ) << 1 ;
if ( ! ( V_3 -> V_23 [ V_29 ] & V_24 ) ) {
F_5 ( V_17 ,
L_4 ,
V_29 , V_3 -> V_23 [ V_29 ] ) ;
return 0 ;
}
F_2 ( V_3 , V_4 ) ;
V_3 -> V_31 [ V_29 ] [ V_30 ++ ] = ( unsigned char ) ( * V_13 & 0x00FF ) ;
V_3 -> V_31 [ V_29 ] [ V_30 ] = ( unsigned char ) ( ( * V_13 & 0xFF00 ) >> 8 ) ;
F_3 ( V_29 + 1 , V_3 -> V_10 + 5 ) ;
F_3 ( 'W' , V_3 -> V_10 + 6 ) ;
for ( V_30 = 0 ; V_30 < 4 ; V_30 ++ ) {
while ( ! ( ( F_6 ( V_3 -> V_10 + 0 ) ) & V_32 ) )
;
F_3 ( V_3 -> V_31 [ V_29 ] [ V_30 ] , V_3 -> V_10 + 6 ) ;
}
return 1 ;
}
static int F_11 ( struct V_33 * V_34 ,
struct V_11 * V_35 ,
struct V_36 * V_37 , unsigned int * V_13 )
{
struct V_2 * V_3 = V_35 -> V_15 ;
int V_4 , type ;
V_4 = F_12 ( V_37 -> V_38 ) ;
type = V_3 -> V_23 [ V_4 / 2 ] ;
if ( type == V_39 ) {
if ( ! F_4 ( V_35 , V_13 , V_4 , V_34 -> V_14 ) )
return - 1 ;
} else {
if ( ! F_7 ( V_35 , V_13 , V_4 , V_34 -> V_14 ) )
return - 1 ;
}
return 1 ;
}
static int F_13 ( struct V_33 * V_34 ,
struct V_11 * V_35 ,
struct V_36 * V_37 , unsigned int * V_13 )
{
struct V_2 * V_3 = V_35 -> V_15 ;
int V_4 , type ;
V_4 = F_12 ( V_37 -> V_38 ) ;
type = V_3 -> V_23 [ V_4 / 2 ] ;
if ( type == V_39 ) {
if ( ! F_9 ( V_35 , V_13 , V_4 , V_34 -> V_14 ) )
return - 1 ;
} else {
if ( ! F_10 ( V_35 , V_13 , V_4 , V_34 -> V_14 ) )
return - 1 ;
}
return 1 ;
}
static int F_14 ( struct V_33 * V_34 ,
struct V_11 * V_35 ,
struct V_36 * V_37 , unsigned int * V_13 )
{
int V_8 , V_40 , V_4 = F_12 ( V_37 -> V_38 ) , type ;
struct V_2 * V_3 = V_35 -> V_15 ;
int V_19 = 1 << ( V_4 & 0x07 ) ;
type = V_3 -> V_23 [ V_4 / 2 ] ;
if ( type != V_39 ) {
F_5 ( V_34 -> V_18 ,
L_5 ) ;
return - 1 ;
}
V_8 = F_1 ( V_4 ) ;
if ( V_8 < 0 ) {
F_5 ( V_34 -> V_18 ,
L_1 ,
V_4 ) ;
return - 1 ;
}
V_40 = V_3 -> V_9 [ V_8 - 1 ] ;
switch ( * V_13 ) {
case V_41 :
V_40 &= ~ V_19 ;
break;
case V_42 :
V_40 |= V_19 ;
break;
default:
F_5 ( V_34 -> V_18 , L_6 ) ;
return - 1 ;
}
F_3 ( 1 , V_3 -> V_10 + 0 ) ;
F_3 ( V_40 , V_3 -> V_10 + V_8 ) ;
F_3 ( 0 , V_3 -> V_10 + 0 ) ;
V_3 -> V_9 [ V_8 - 1 ] = V_40 ;
return 0 ;
}
static int F_15 ( struct V_33 * V_34 ,
struct V_11 * V_12 ,
int V_43 )
{
struct V_2 * V_3 ;
int V_30 , V_44 , V_45 = 0 ;
int V_46 ;
V_3 = F_16 ( V_12 , sizeof( * V_3 ) ) ;
if ( ! V_3 )
return - V_47 ;
V_46 = F_17 ( V_34 , V_43 , V_48 ) ;
if ( V_46 )
return V_46 ;
V_3 -> V_10 = V_43 ;
for ( V_30 = 0 ; V_30 < 12 ; V_30 ++ ) {
V_44 = 10000 ;
F_2 ( V_3 , V_30 * 2 ) ;
F_3 ( V_30 + 1 , V_43 + 5 ) ;
F_3 ( 'H' , V_43 + 6 ) ;
while ( ! ( F_6 ( V_43 + 0 ) & V_32 ) )
;
F_3 ( 0 , V_43 + 6 ) ;
while ( ! ( F_6 ( V_43 + 0 ) & V_49 ) ) {
if ( -- V_44 <= 0 ) {
V_45 = 1 ;
break;
}
}
if ( V_45 ) {
V_3 -> V_23 [ V_30 ] = 0 ;
V_45 = 0 ;
} else
V_3 -> V_23 [ V_30 ] = F_6 ( V_43 + 6 ) ;
F_18 ( 1 ) ;
}
V_12 -> type = V_50 ;
V_12 -> V_51 = V_52 | V_53 ;
V_12 -> V_54 = V_55 ;
V_12 -> V_56 = 0xFFF ;
V_12 -> V_57 = & V_58 ;
V_12 -> V_59 = F_11 ;
V_12 -> V_60 = F_13 ;
V_12 -> V_61 = F_14 ;
return 0 ;
}
static int F_19 ( struct V_33 * V_34 ,
struct V_62 * V_63 )
{
struct V_11 * V_12 ;
int V_43 , V_30 , V_64 ;
int V_65 , V_66 , V_67 ;
int V_46 ;
V_43 = V_63 -> V_68 [ 0 ] ;
V_34 -> V_43 = V_43 ;
V_43 += V_69 ;
V_64 = 0 ;
for ( V_30 = 0 , V_67 = V_43 ; V_30 < 4 ; V_30 ++ , V_67 += V_70 ) {
V_65 = F_6 ( V_67 + 0xE ) ;
V_66 = F_6 ( V_67 + 0xF ) ;
if ( V_65 != 'g' || V_66 != 1 )
continue;
V_64 ++ ;
}
if ( V_64 < 2 ) {
F_5 ( V_34 -> V_18 ,
L_7 ) ;
return - 1 ;
}
V_46 = F_20 ( V_34 , V_64 ) ;
if ( V_46 )
return V_46 ;
for ( V_30 = 0 ; V_30 < V_64 ; V_30 ++ , V_43 += V_70 ) {
V_12 = & V_34 -> V_71 [ V_30 ] ;
V_46 = F_15 ( V_34 , V_12 , V_43 ) ;
if ( V_46 )
return V_46 ;
}
return 0 ;
}
static void F_21 ( struct V_33 * V_34 )
{
struct V_11 * V_12 ;
struct V_2 * V_72 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_34 -> V_73 ; V_30 ++ ) {
V_12 = & V_34 -> V_71 [ V_30 ] ;
V_72 = V_12 -> V_15 ;
if ( V_72 && V_72 -> V_10 )
F_22 ( V_72 -> V_10 , V_48 ) ;
}
}
