static void F_1 ( T_1 * V_1 , T_2 V_2 , unsigned V_3 )
{
while ( V_3 -- )
* V_1 ++ = ( V_2 & ( 1 << V_3 ) ) ? 0xc0 : 0x10 ;
}
static void F_2 ( const struct V_4 * V_5 ,
T_1 * V_6 , unsigned V_7 )
{
const unsigned V_8 = 5000000 ;
T_1 V_1 [ 29 + 24 + 24 + 24 + 18 + 18 ] = { 0 } ;
const unsigned V_9 = 0x07 ;
const unsigned V_10 = 0x38 ;
unsigned V_11 = 0 ;
T_3 V_12 ;
int V_13 ;
F_1 ( V_1 + V_11 , 0x1f1c71c7 , 29 ) ; V_11 += 29 ;
F_1 ( V_1 + V_11 , 0x1e3c1f , 24 ) ; V_11 += 24 ;
V_12 = ( V_5 -> V_5 [ 1 ] << 8 ) | V_5 -> V_5 [ 0 ] ;
for ( V_13 = 0 ; V_13 <= 13 ; V_13 ++ , V_11 += 6 )
F_1 ( V_1 + V_11 , ( V_12 & ( 1 << V_13 ) ) ? V_10 : V_9 , 6 ) ;
for ( V_13 = 0 , V_11 = 0 ; V_11 < sizeof( V_1 ) ; V_11 ++ ) {
unsigned V_14 = ( ( V_11 + 1 ) * V_7 ) / V_8 ;
while ( V_13 < V_14 )
V_6 [ V_13 ++ ] = V_1 [ V_11 ] ;
}
}
static void F_3 ( const struct V_4 * V_5 ,
T_1 * V_6 , unsigned V_7 )
{
const unsigned V_8 = 6937500 / 10 ;
T_1 V_15 [ 45 ] = { 0x55 , 0x55 , 0x27 } ;
unsigned V_11 = 0 ;
int V_13 ;
memcpy ( V_15 + 3 , V_5 -> V_5 , sizeof( V_15 ) - 3 ) ;
V_7 /= 10 ;
for ( V_13 = 0 , V_11 = 0 ; V_11 < sizeof( V_15 ) * 8 ; V_11 ++ ) {
unsigned V_14 = ( ( V_11 + 1 ) * V_7 ) / V_8 ;
T_1 V_2 = ( V_15 [ V_11 / 8 ] & ( 1 << ( V_11 & 7 ) ) ) ? 0xc0 : 0x10 ;
while ( V_13 < V_14 )
V_6 [ V_13 ++ ] = V_2 ;
}
}
static void F_4 ( T_1 * V_16 , T_1 V_17 )
{
unsigned V_18 = 0 ;
unsigned V_13 ;
for ( V_13 = 0 ; V_13 < 7 ; V_13 ++ ) {
V_16 [ 2 * V_13 ] = V_16 [ 2 * V_13 + 1 ] = ( V_17 & ( 1 << V_13 ) ) ? 1 : 0 ;
V_18 += V_16 [ 2 * V_13 ] ;
}
V_16 [ 14 ] = V_16 [ 15 ] = ! ( V_18 & 1 ) ;
}
static void F_5 ( const struct V_4 * V_5 ,
T_1 * V_6 , unsigned V_7 )
{
const unsigned V_8 = 1000000 ;
T_1 V_16 [ V_19 + 2 * 16 ] = {
0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 ,
0 , 0 , 0 , 0 ,
1 , 1
} ;
unsigned V_11 , V_13 ;
F_4 ( V_16 + V_19 , V_5 -> V_5 [ 0 ] ) ;
F_4 ( V_16 + V_19 + 16 , V_5 -> V_5 [ 1 ] ) ;
for ( V_13 = 0 , V_11 = 0 ; V_11 < sizeof( V_16 ) ; V_11 ++ ) {
unsigned V_14 = ( ( V_11 + 1 ) * V_7 ) / V_8 ;
while ( V_13 < V_14 )
V_6 [ V_13 ++ ] = V_16 [ V_11 ] ? 0xc0 : 0x10 ;
}
}
void F_6 ( const struct V_20 * V_21 ,
const struct V_22 * V_23 , T_1 * V_6 )
{
unsigned V_24 ;
for ( V_24 = 0 ; V_24 < 25 ; V_24 ++ ) {
const struct V_4 * V_5 = V_21 -> V_5 + V_24 ;
unsigned V_25 ;
unsigned line = V_5 -> line ;
T_1 * V_26 = V_6 ;
V_25 = ( V_5 -> V_27 & V_28 ) ? 263 : 313 ;
if ( V_5 -> V_29 )
line += V_25 ;
line -= V_23 -> V_30 [ V_5 -> V_29 ] ;
if ( V_23 -> V_31 & V_32 )
V_26 += ( line * 2 + V_5 -> V_29 ) *
V_23 -> V_33 ;
else
V_26 += ( line + V_5 -> V_29 * V_23 -> V_34 [ 0 ] ) *
V_23 -> V_33 ;
if ( V_5 -> V_27 == V_35 )
F_5 ( V_5 , V_26 , V_23 -> V_7 ) ;
else if ( V_5 -> V_27 == V_36 )
F_2 ( V_5 , V_26 , V_23 -> V_7 ) ;
else if ( V_5 -> V_27 == V_37 )
F_3 ( V_5 , V_26 , V_23 -> V_7 ) ;
}
}
static T_1 F_7 ( T_1 V_2 )
{
unsigned V_13 ;
unsigned V_18 = 0 ;
for ( V_13 = 0 ; V_13 < 7 ; V_13 ++ )
V_18 += ( V_2 & ( 1 << V_13 ) ) ? 1 : 0 ;
return V_2 | ( ( V_18 & 1 ) ? 0 : 0x80 ) ;
}
static void F_8 ( T_1 * V_38 )
{
struct V_39 V_39 ;
T_1 V_40 , V_13 ;
F_9 ( F_10 () , 0 , & V_39 ) ;
V_38 [ 0 ] = F_7 ( 0x07 ) ;
V_38 [ 1 ] = F_7 ( 0x01 ) ;
V_38 [ 2 ] = F_7 ( 0x40 | V_39 . V_41 ) ;
V_38 [ 3 ] = F_7 ( 0x40 | V_39 . V_42 ) ;
V_38 [ 4 ] = F_7 ( 0x40 | V_39 . V_43 ) ;
if ( V_39 . V_43 == 1 && V_39 . V_44 == 2 &&
V_45 . V_46 > V_39 . V_41 + V_39 . V_42 * 60 )
V_38 [ 4 ] = F_7 ( 0x60 | V_39 . V_43 ) ;
V_38 [ 5 ] = F_7 ( 0x40 | ( 1 + V_39 . V_44 ) ) ;
V_38 [ 6 ] = F_7 ( 0x40 | ( 1 + V_39 . V_47 ) ) ;
V_38 [ 7 ] = F_7 ( 0x40 | ( ( V_39 . V_48 - 90 ) & 0x3f ) ) ;
V_38 [ 8 ] = F_7 ( 0x0f ) ;
for ( V_40 = V_13 = 0 ; V_13 <= 8 ; V_13 ++ )
V_40 += V_38 [ V_13 ] & 0x7f ;
V_38 [ 9 ] = F_7 ( 0x100 - V_40 ) ;
V_40 = 0 ;
V_38 [ 10 ] = F_7 ( 0x07 ) ;
V_38 [ 11 ] = F_7 ( 0x04 ) ;
if ( V_45 . V_46 >= 0 )
V_38 [ 12 ] = F_7 ( 0x40 | ( ( V_45 . V_46 / 60 ) & 0x1f ) ) ;
else
V_38 [ 12 ] = F_7 ( 0x40 | ( ( 24 + V_45 . V_46 / 60 ) & 0x1f ) ) ;
V_38 [ 13 ] = F_7 ( 0 ) ;
V_38 [ 14 ] = F_7 ( 0x0f ) ;
for ( V_40 = 0 , V_13 = 10 ; V_13 <= 14 ; V_13 ++ )
V_40 += V_38 [ V_13 ] & 0x7f ;
V_38 [ 15 ] = F_7 ( 0x100 - V_40 ) ;
}
static void F_11 ( T_1 * V_38 , unsigned line , unsigned V_49 )
{
unsigned V_50 = 2 ;
unsigned V_13 ;
V_38 [ 0 ] = V_51 [ 1 + ( ( line & 1 ) << 3 ) ] ;
V_38 [ 1 ] = V_51 [ line >> 1 ] ;
memset ( V_38 + 2 , 0x20 , 40 ) ;
if ( line == 0 ) {
V_38 [ 2 ] = V_51 [ V_49 % 10 ] ;
V_38 [ 3 ] = V_51 [ V_49 / 10 ] ;
V_38 [ 4 ] = V_51 [ 0 ] ;
V_38 [ 5 ] = V_51 [ 0 ] ;
V_38 [ 6 ] = V_51 [ 0 ] ;
V_38 [ 7 ] = V_51 [ 0 ] ;
V_38 [ 8 ] = V_51 [ 0 ] ;
V_38 [ 9 ] = V_51 [ 1 ] ;
V_50 = 10 ;
}
V_38 += V_50 ;
memcpy ( V_38 , L_1 , 17 ) ;
V_38 [ 7 ] = '0' + V_49 / 10 ;
V_38 [ 8 ] = '0' + V_49 % 10 ;
V_38 [ 15 ] = '0' + line / 10 ;
V_38 [ 16 ] = '0' + line % 10 ;
for ( V_13 = 0 ; V_13 < 42 - V_50 ; V_13 ++ )
V_38 [ V_13 ] = F_7 ( V_38 [ V_13 ] ) ;
}
void F_12 ( struct V_20 * V_21 ,
bool V_52 , unsigned V_53 )
{
struct V_4 * V_54 = V_21 -> V_5 ;
struct V_4 * V_55 = V_21 -> V_5 + 1 ;
unsigned V_49 = V_53 % 60 ;
memset ( V_21 -> V_5 , 0 , sizeof( V_21 -> V_5 ) ) ;
if ( ! V_52 ) {
unsigned V_13 ;
for ( V_13 = 0 ; V_13 <= 11 ; V_13 ++ ) {
V_54 -> V_27 = V_37 ;
V_54 -> line = 7 + V_13 ;
F_11 ( V_54 -> V_5 , V_13 , V_49 ) ;
V_54 ++ ;
}
V_54 -> V_27 = V_36 ;
V_54 -> line = 23 ;
V_54 -> V_5 [ 0 ] = 0x08 ;
V_54 ++ ;
for ( V_13 = 0 ; V_13 <= 11 ; V_13 ++ ) {
V_54 -> V_27 = V_37 ;
V_54 -> V_29 = 1 ;
V_54 -> line = 7 + V_13 ;
F_11 ( V_54 -> V_5 , 12 + V_13 , V_49 ) ;
V_54 ++ ;
}
return;
}
V_54 -> V_27 = V_35 ;
V_54 -> line = 21 ;
V_55 -> V_27 = V_35 ;
V_55 -> V_29 = 1 ;
V_55 -> line = 21 ;
if ( V_49 < 15 ) {
V_54 -> V_5 [ 0 ] = F_7 ( V_56 [ 2 * V_49 ] ) ;
V_54 -> V_5 [ 1 ] = F_7 ( V_56 [ 2 * V_49 + 1 ] ) ;
} else if ( V_49 >= 30 && V_49 < 45 ) {
V_49 -= 30 ;
V_54 -> V_5 [ 0 ] = F_7 ( V_57 [ 2 * V_49 ] ) ;
V_54 -> V_5 [ 1 ] = F_7 ( V_57 [ 2 * V_49 + 1 ] ) ;
} else {
V_54 -> V_5 [ 0 ] = F_7 ( 0 ) ;
V_54 -> V_5 [ 1 ] = F_7 ( 0 ) ;
}
V_49 = V_53 % ( 30 * 60 ) ;
switch ( V_49 ) {
case 0 :
F_8 ( V_21 -> V_58 ) ;
case 1 ... 7 :
V_55 -> V_5 [ 0 ] = V_21 -> V_58 [ V_49 * 2 ] ;
V_55 -> V_5 [ 1 ] = V_21 -> V_58 [ V_49 * 2 + 1 ] ;
break;
default:
V_55 -> V_5 [ 0 ] = F_7 ( 0 ) ;
V_55 -> V_5 [ 1 ] = F_7 ( 0 ) ;
break;
}
}
