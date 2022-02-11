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
F_7 ( L_3 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
struct V_23 * V_24 , unsigned int * V_25 )
{
struct V_26 * V_27 = V_22 -> V_28 ;
int V_29 , type ;
V_29 = F_11 ( V_24 -> V_30 ) ;
type = V_27 -> V_31 [ V_29 / 2 ] ;
if ( type == V_32 ) {
if ( ! F_12 ( V_27 , V_25 , V_29 , V_3 -> V_20 ) )
return - 1 ;
} else {
if ( ! F_13 ( V_27 , V_25 , V_29 , V_3 -> V_20 ) )
return - 1 ;
}
return 1 ;
}
static int F_14 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
struct V_23 * V_24 , unsigned int * V_25 )
{
struct V_26 * V_27 = V_22 -> V_28 ;
int V_29 , type ;
V_29 = F_11 ( V_24 -> V_30 ) ;
type = V_27 -> V_31 [ V_29 / 2 ] ;
if ( type == V_32 ) {
if ( ! F_15 ( V_27 , V_25 , V_29 , V_3 -> V_20 ) )
return - 1 ;
} else {
if ( ! F_16 ( V_27 , V_25 , V_29 , V_3 -> V_20 ) )
return - 1 ;
}
return 1 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_21 * V_22 ,
struct V_23 * V_24 , unsigned int * V_25 )
{
int V_33 , V_34 , V_29 = F_11 ( V_24 -> V_30 ) , type ;
struct V_26 * V_27 = V_22 -> V_28 ;
int V_35 = 1 << ( V_29 & 0x07 ) ;
type = V_27 -> V_31 [ V_29 / 2 ] ;
if ( type != V_32 ) {
F_7 ( V_17
L_4 ,
V_3 -> V_20 ) ;
return - 1 ;
}
V_33 = F_18 ( V_29 ) ;
if ( V_33 < 0 ) {
F_7 ( V_17
L_5 ,
V_3 -> V_20 , V_29 ) ;
return - 1 ;
}
V_34 = V_27 -> V_36 [ V_33 - 1 ] ;
switch ( * V_25 ) {
case V_37 :
V_34 &= ~ V_35 ;
break;
case V_38 :
V_34 |= V_35 ;
break;
default:
F_7 ( V_17 L_6 , V_3 -> V_20 ) ;
return - 1 ;
}
F_19 ( 1 , V_27 -> V_39 + 0 ) ;
F_19 ( V_34 , V_27 -> V_39 + V_33 ) ;
F_19 ( 0 , V_27 -> V_39 + 0 ) ;
V_27 -> V_36 [ V_33 - 1 ] = V_34 ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 )
{
int V_7 ;
struct V_21 * V_22 ;
struct V_26 * V_27 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_40 ; V_7 ++ ) {
V_22 = & V_3 -> V_19 [ V_7 ] ;
V_27 = V_22 -> V_28 ;
F_21 ( V_27 -> V_39 , V_41 ) ;
F_22 ( V_22 -> V_28 ) ;
}
return 0 ;
}
static int F_9 ( struct V_21 * V_22 ,
int V_42 , int V_20 )
{
struct V_26 * V_27 ;
int V_7 , V_43 , V_44 = 0 ;
if ( ! F_23 ( V_42 , V_41 , V_14 ) ) {
F_7 ( V_17 L_7 , V_20 ) ;
return - V_45 ;
}
V_27 = F_24 ( sizeof( * V_27 ) , V_46 ) ;
if ( V_27 == NULL ) {
F_7 ( V_17 L_8 , V_20 ) ;
return - 1 ;
}
V_27 -> V_39 = V_42 ;
F_7 ( L_9 , V_20 ) ;
for ( V_7 = 0 ; V_7 < 12 ; V_7 ++ ) {
V_43 = 10000 ;
F_25 ( V_27 , V_7 * 2 ) ;
F_19 ( V_7 + 1 , V_42 + 5 ) ;
F_19 ( 'H' , V_42 + 6 ) ;
while ( ! ( F_6 ( V_42 + 0 ) & V_47 ) )
;
F_19 ( 0 , V_42 + 6 ) ;
while ( ! ( F_6 ( V_42 + 0 ) & V_48 ) ) {
if ( -- V_43 <= 0 ) {
V_44 = 1 ;
break;
}
}
if ( V_44 ) {
V_27 -> V_31 [ V_7 ] = 0 ;
V_44 = 0 ;
} else
V_27 -> V_31 [ V_7 ] = F_6 ( V_42 + 6 ) ;
F_7 ( L_10 , V_7 , V_27 -> V_31 [ V_7 ] ) ;
F_26 ( 1 ) ;
}
F_7 ( L_11 ) ;
V_22 -> type = V_49 ;
V_22 -> V_28 = V_27 ;
V_22 -> V_50 = V_51 | V_52 ;
V_22 -> V_53 = V_54 ;
V_22 -> V_55 = 0xFFF ;
V_22 -> V_56 = & V_57 ;
V_22 -> V_58 = F_10 ;
V_22 -> V_59 = F_14 ;
V_22 -> V_60 = F_17 ;
F_7 ( L_12 ) ;
return 0 ;
}
static int F_15 ( struct V_26 * V_27 ,
unsigned int * V_25 , int V_29 , int V_20 )
{
int V_33 , V_61 ;
int V_35 = 1 << ( V_29 & 0x07 ) ;
V_33 = F_18 ( V_29 ) ;
if ( V_33 < 0 ) {
F_7 ( V_17
L_5 ,
V_20 , V_29 ) ;
return 0 ;
}
V_61 = V_27 -> V_62 [ V_33 - 1 ] ;
if ( * V_25 )
V_61 |= V_35 ;
else
V_61 &= ~ V_35 ;
F_19 ( V_61 , V_27 -> V_39 + V_33 ) ;
V_27 -> V_62 [ V_33 - 1 ] = V_61 ;
return 1 ;
}
static int F_12 ( struct V_26 * V_27 ,
unsigned int * V_25 , int V_29 , int V_20 )
{
int V_33 , V_35 = 1 << ( V_29 & 0x07 ) ;
V_33 = F_18 ( V_29 ) ;
if ( V_33 < 0 ) {
F_7 ( V_17
L_5 ,
V_20 , V_29 ) ;
return 0 ;
}
* V_25 = F_6 ( V_27 -> V_39 + V_33 ) ;
* V_25 &= V_35 ;
if ( V_33 > 1 )
V_29 -= 2 << V_33 ;
* V_25 >>= V_29 ;
return 1 ;
}
static int F_16 ( struct V_26 * V_27 ,
unsigned int * V_25 , int V_29 , int V_20 )
{
int V_63 , V_7 ;
V_63 = V_29 / 2 ;
V_7 = ( V_29 % 2 ) << 1 ;
if ( ! ( V_27 -> V_31 [ V_63 ] & V_64 ) ) {
F_7 ( V_17
L_13 ,
V_20 , V_63 , V_27 -> V_31 [ V_63 ] ) ;
return 0 ;
}
F_25 ( V_27 , V_29 ) ;
V_27 -> V_65 [ V_63 ] [ V_7 ++ ] = ( unsigned char ) ( * V_25 & 0x00FF ) ;
V_27 -> V_65 [ V_63 ] [ V_7 ] = ( unsigned char ) ( ( * V_25 & 0xFF00 ) >> 8 ) ;
F_19 ( V_63 + 1 , V_27 -> V_39 + 5 ) ;
F_19 ( 'W' , V_27 -> V_39 + 6 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
while ( ! ( ( F_6 ( V_27 -> V_39 + 0 ) ) & V_47 ) )
;
F_19 ( V_27 -> V_65 [ V_63 ] [ V_7 ] , V_27 -> V_39 + 6 ) ;
}
return 1 ;
}
static int F_13 ( struct V_26 * V_27 ,
unsigned int * V_25 , int V_29 , int V_20 )
{
int V_66 , V_67 ;
char V_68 ;
V_66 = V_29 / 2 ;
V_67 = V_29 % 2 ;
if ( V_27 -> V_31 [ V_66 ] & V_64 ) {
F_7 ( V_17
L_14 ,
V_20 , V_66 , V_27 -> V_31 [ V_66 ] ) ;
return 0 ;
}
F_25 ( V_27 , V_29 ) ;
F_19 ( V_66 + 1 , V_27 -> V_39 + 5 ) ;
F_19 ( 'V' , V_27 -> V_39 + 6 ) ;
V_68 = F_6 ( V_27 -> V_39 ) ;
while ( ! ( ( V_68 = F_6 ( V_27 -> V_39 + 0 ) ) & V_69 ) )
;
if ( ( V_68 & V_70 ) ) {
F_7 ( L_15 ) ;
return 0 ;
}
if ( V_67 )
* V_25 = F_27 ( V_27 -> V_39 + 6 ) ;
else
* V_25 = F_27 ( V_27 -> V_39 + 4 ) ;
return 1 ;
}
static void F_25 ( struct V_26 * V_27 , int V_29 )
{
int V_71 , V_72 , V_73 , V_33 ;
V_33 = F_18 ( V_29 ) ;
V_73 = V_27 -> V_36 [ V_33 - 1 ] ;
V_71 = V_72 = 1 ;
if ( V_29 % 2 == 0 ) {
V_71 <<= V_29 & 0x07 ;
V_72 <<= ( V_29 + 1 ) & 0x07 ;
} else {
V_71 <<= ( V_29 - 1 ) & 0x07 ;
V_72 <<= V_29 & 0x07 ;
}
V_73 |= V_71 ;
V_73 &= ~ V_72 ;
F_19 ( 1 , V_27 -> V_39 + 0 ) ;
F_19 ( V_73 , V_27 -> V_39 + V_33 ) ;
F_19 ( 0 , V_27 -> V_39 + 0 ) ;
V_27 -> V_36 [ V_33 - 1 ] = V_73 ;
}
static int F_18 ( int V_74 )
{
if ( V_74 < 0 || V_74 > 23 )
return - 1 ;
return ( V_74 >> 3 ) + 1 ;
}
