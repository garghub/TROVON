static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
int V_6 , V_7 , V_8 ;
int V_9 , V_10 , V_11 ;
V_6 = V_5 -> V_12 [ 0 ] ;
V_3 -> V_13 = V_14 ;
V_3 -> V_6 = V_6 ;
V_6 += V_15 ;
for ( V_7 = V_8 = 0 , V_11 = V_6 ; V_7 < 4 ; V_7 ++ , V_11 += V_16 ) {
V_9 = F_6 ( V_11 + 0xE ) ;
V_10 = F_6 ( V_11 + 0xF ) ;
if ( V_9 != 'g' || V_10 != 1 )
continue;
V_8 ++ ;
}
if ( V_8 < 2 ) {
F_7 ( V_17
L_1 ) ;
return - 1 ;
}
if ( F_8 ( V_3 , V_8 ) < 0 ) {
F_7 ( V_17 L_2 ) ;
return - V_18 ;
}
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ , V_6 += V_16 ) {
if ( F_9 ( & V_3 -> V_19 [ V_7 ] , V_6 ,
V_3 -> V_20 ) < 0 )
return - 1 ;
}
F_7 ( V_21 L_3 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 ,
struct V_22 * V_23 ,
struct V_24 * V_25 , unsigned int * V_26 )
{
struct V_27 * V_28 = V_23 -> V_29 ;
int V_30 , type ;
V_30 = F_11 ( V_25 -> V_31 ) ;
type = V_28 -> V_32 [ V_30 / 2 ] ;
if ( type == V_33 ) {
if ( ! F_12 ( V_28 , V_26 , V_30 , V_3 -> V_20 ) )
return - 1 ;
} else {
if ( ! F_13 ( V_28 , V_26 , V_30 , V_3 -> V_20 ) )
return - 1 ;
}
return 1 ;
}
static int F_14 ( struct V_2 * V_3 ,
struct V_22 * V_23 ,
struct V_24 * V_25 , unsigned int * V_26 )
{
struct V_27 * V_28 = V_23 -> V_29 ;
int V_30 , type ;
V_30 = F_11 ( V_25 -> V_31 ) ;
type = V_28 -> V_32 [ V_30 / 2 ] ;
if ( type == V_33 ) {
if ( ! F_15 ( V_28 , V_26 , V_30 , V_3 -> V_20 ) )
return - 1 ;
} else {
if ( ! F_16 ( V_28 , V_26 , V_30 , V_3 -> V_20 ) )
return - 1 ;
}
return 1 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_22 * V_23 ,
struct V_24 * V_25 , unsigned int * V_26 )
{
int V_34 , V_35 , V_30 = F_11 ( V_25 -> V_31 ) , type ;
struct V_27 * V_28 = V_23 -> V_29 ;
int V_36 = 1 << ( V_30 & 0x07 ) ;
type = V_28 -> V_32 [ V_30 / 2 ] ;
if ( type != V_33 ) {
F_7 ( V_17
L_4 ,
V_3 -> V_20 ) ;
return - 1 ;
}
V_34 = F_18 ( V_30 ) ;
if ( V_34 < 0 ) {
F_7 ( V_17
L_5 ,
V_3 -> V_20 , V_30 ) ;
return - 1 ;
}
V_35 = V_28 -> V_37 [ V_34 - 1 ] ;
switch ( * V_26 ) {
case V_38 :
V_35 &= ~ V_36 ;
break;
case V_39 :
V_35 |= V_36 ;
break;
default:
F_7 ( V_17 L_6 , V_3 -> V_20 ) ;
return - 1 ;
}
F_19 ( 1 , V_28 -> V_40 + 0 ) ;
F_19 ( V_35 , V_28 -> V_40 + V_34 ) ;
F_19 ( 0 , V_28 -> V_40 + 0 ) ;
V_28 -> V_37 [ V_34 - 1 ] = V_35 ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 )
{
int V_7 ;
struct V_22 * V_23 ;
struct V_27 * V_28 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_41 ; V_7 ++ ) {
V_23 = & V_3 -> V_19 [ V_7 ] ;
V_28 = V_23 -> V_29 ;
F_21 ( V_28 -> V_40 , V_42 ) ;
F_22 ( V_23 -> V_29 ) ;
}
return 0 ;
}
static int F_9 ( struct V_22 * V_23 ,
int V_43 , int V_20 )
{
struct V_27 * V_28 ;
int V_7 , V_44 , V_45 = 0 ;
if ( ! F_23 ( V_43 , V_42 , V_14 ) ) {
F_7 ( V_17 L_7 , V_20 ) ;
return - V_46 ;
}
V_28 = F_24 ( sizeof( * V_28 ) , V_47 ) ;
if ( V_28 == NULL ) {
F_7 ( V_17 L_8 , V_20 ) ;
return - 1 ;
}
V_28 -> V_40 = V_43 ;
F_7 ( V_21 L_9 , V_20 ) ;
for ( V_7 = 0 ; V_7 < 12 ; V_7 ++ ) {
V_44 = 10000 ;
F_25 ( V_28 , V_7 * 2 ) ;
F_19 ( V_7 + 1 , V_43 + 5 ) ;
F_19 ( 'H' , V_43 + 6 ) ;
while ( ! ( F_6 ( V_43 + 0 ) & V_48 ) )
;
F_19 ( 0 , V_43 + 6 ) ;
while ( ! ( F_6 ( V_43 + 0 ) & V_49 ) ) {
if ( -- V_44 <= 0 ) {
V_45 = 1 ;
break;
}
}
if ( V_45 ) {
V_28 -> V_32 [ V_7 ] = 0 ;
V_45 = 0 ;
} else
V_28 -> V_32 [ V_7 ] = F_6 ( V_43 + 6 ) ;
F_7 ( L_10 , V_7 , V_28 -> V_32 [ V_7 ] ) ;
F_26 ( 1 ) ;
}
F_7 ( L_11 ) ;
V_23 -> type = V_50 ;
V_23 -> V_29 = V_28 ;
V_23 -> V_51 = V_52 | V_53 ;
V_23 -> V_54 = V_55 ;
V_23 -> V_56 = 0xFFF ;
V_23 -> V_57 = & V_58 ;
V_23 -> V_59 = F_10 ;
V_23 -> V_60 = F_14 ;
V_23 -> V_61 = F_17 ;
F_7 ( V_21 L_12 ) ;
return 0 ;
}
static int F_15 ( struct V_27 * V_28 ,
unsigned int * V_26 , int V_30 , int V_20 )
{
int V_34 , V_62 ;
int V_36 = 1 << ( V_30 & 0x07 ) ;
V_34 = F_18 ( V_30 ) ;
if ( V_34 < 0 ) {
F_7 ( V_17
L_5 ,
V_20 , V_30 ) ;
return 0 ;
}
V_62 = V_28 -> V_63 [ V_34 - 1 ] ;
if ( * V_26 )
V_62 |= V_36 ;
else
V_62 &= ~ V_36 ;
F_19 ( V_62 , V_28 -> V_40 + V_34 ) ;
V_28 -> V_63 [ V_34 - 1 ] = V_62 ;
return 1 ;
}
static int F_12 ( struct V_27 * V_28 ,
unsigned int * V_26 , int V_30 , int V_20 )
{
int V_34 , V_36 = 1 << ( V_30 & 0x07 ) ;
V_34 = F_18 ( V_30 ) ;
if ( V_34 < 0 ) {
F_7 ( V_17
L_5 ,
V_20 , V_30 ) ;
return 0 ;
}
* V_26 = F_6 ( V_28 -> V_40 + V_34 ) ;
* V_26 &= V_36 ;
if ( V_34 > 1 )
V_30 -= 2 << V_34 ;
* V_26 >>= V_30 ;
return 1 ;
}
static int F_16 ( struct V_27 * V_28 ,
unsigned int * V_26 , int V_30 , int V_20 )
{
int V_64 , V_7 ;
V_64 = V_30 / 2 ;
V_7 = ( V_30 % 2 ) << 1 ;
if ( ! ( V_28 -> V_32 [ V_64 ] & V_65 ) ) {
F_7 ( V_17
L_13 ,
V_20 , V_64 , V_28 -> V_32 [ V_64 ] ) ;
return 0 ;
}
F_25 ( V_28 , V_30 ) ;
V_28 -> V_66 [ V_64 ] [ V_7 ++ ] = ( unsigned char ) ( * V_26 & 0x00FF ) ;
V_28 -> V_66 [ V_64 ] [ V_7 ] = ( unsigned char ) ( ( * V_26 & 0xFF00 ) >> 8 ) ;
F_19 ( V_64 + 1 , V_28 -> V_40 + 5 ) ;
F_19 ( 'W' , V_28 -> V_40 + 6 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
while ( ! ( ( F_6 ( V_28 -> V_40 + 0 ) ) & V_48 ) )
;
F_19 ( V_28 -> V_66 [ V_64 ] [ V_7 ] , V_28 -> V_40 + 6 ) ;
}
return 1 ;
}
static int F_13 ( struct V_27 * V_28 ,
unsigned int * V_26 , int V_30 , int V_20 )
{
int V_67 , V_68 ;
char V_69 ;
V_67 = V_30 / 2 ;
V_68 = V_30 % 2 ;
if ( V_28 -> V_32 [ V_67 ] & V_65 ) {
F_7 ( V_17
L_14 ,
V_20 , V_67 , V_28 -> V_32 [ V_67 ] ) ;
return 0 ;
}
F_25 ( V_28 , V_30 ) ;
F_19 ( V_67 + 1 , V_28 -> V_40 + 5 ) ;
F_19 ( 'V' , V_28 -> V_40 + 6 ) ;
V_69 = F_6 ( V_28 -> V_40 ) ;
while ( ! ( ( V_69 = F_6 ( V_28 -> V_40 + 0 ) ) & V_70 ) )
;
if ( ( V_69 & V_71 ) ) {
F_7 ( L_15 ) ;
return 0 ;
}
if ( V_68 )
* V_26 = F_27 ( V_28 -> V_40 + 6 ) ;
else
* V_26 = F_27 ( V_28 -> V_40 + 4 ) ;
return 1 ;
}
static void F_25 ( struct V_27 * V_28 , int V_30 )
{
int V_72 , V_73 , V_74 , V_34 ;
V_34 = F_18 ( V_30 ) ;
V_74 = V_28 -> V_37 [ V_34 - 1 ] ;
V_72 = V_73 = 1 ;
if ( V_30 % 2 == 0 ) {
V_72 <<= V_30 & 0x07 ;
V_73 <<= ( V_30 + 1 ) & 0x07 ;
} else {
V_72 <<= ( V_30 - 1 ) & 0x07 ;
V_73 <<= V_30 & 0x07 ;
}
V_74 |= V_72 ;
V_74 &= ~ V_73 ;
F_19 ( 1 , V_28 -> V_40 + 0 ) ;
F_19 ( V_74 , V_28 -> V_40 + V_34 ) ;
F_19 ( 0 , V_28 -> V_40 + 0 ) ;
V_28 -> V_37 [ V_34 - 1 ] = V_74 ;
}
static int F_18 ( int V_75 )
{
if ( V_75 < 0 || V_75 > 23 )
return - 1 ;
return ( V_75 >> 3 ) + 1 ;
}
