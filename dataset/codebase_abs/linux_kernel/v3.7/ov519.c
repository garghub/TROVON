static unsigned char F_1 ( unsigned char V_1 )
{
if ( V_1 > 127 )
return V_1 & 0x7f ;
return ( 128 - V_1 ) | 0x80 ;
}
static void F_2 ( struct V_2 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 , V_6 = 0 ;
if ( V_2 -> V_7 . V_8 < 0 )
return;
switch ( V_2 -> V_9 ) {
case V_10 :
case V_11 :
V_6 = 2 ;
break;
case V_12 :
V_6 = 0x0a ;
case V_13 :
F_3 ( V_14 , L_1 ,
V_6 , V_4 , V_3 ) ;
V_5 = F_4 ( V_2 -> V_7 . V_15 ,
F_5 ( V_2 -> V_7 . V_15 , 0 ) ,
V_6 ,
V_16 | V_17 | V_18 ,
V_4 , V_3 , NULL , 0 , 500 ) ;
goto V_19;
default:
V_6 = 1 ;
}
F_3 ( V_14 , L_2 ,
V_6 , V_3 , V_4 ) ;
V_2 -> V_7 . V_20 [ 0 ] = V_4 ;
V_5 = F_4 ( V_2 -> V_7 . V_15 ,
F_5 ( V_2 -> V_7 . V_15 , 0 ) ,
V_6 ,
V_16 | V_17 | V_18 ,
0 , V_3 ,
V_2 -> V_7 . V_20 , 1 , 500 ) ;
V_19:
if ( V_5 < 0 ) {
F_6 ( L_3 , V_3 , V_5 ) ;
V_2 -> V_7 . V_8 = V_5 ;
return;
}
}
static int F_7 ( struct V_2 * V_2 , T_1 V_3 )
{
int V_5 ;
int V_6 ;
if ( V_2 -> V_7 . V_8 < 0 )
return - 1 ;
switch ( V_2 -> V_9 ) {
case V_10 :
case V_11 :
V_6 = 3 ;
break;
case V_12 :
V_6 = 0x0b ;
break;
default:
V_6 = 1 ;
}
V_5 = F_4 ( V_2 -> V_7 . V_15 ,
F_8 ( V_2 -> V_7 . V_15 , 0 ) ,
V_6 ,
V_21 | V_17 | V_18 ,
0 , V_3 , V_2 -> V_7 . V_20 , 1 , 500 ) ;
if ( V_5 >= 0 ) {
V_5 = V_2 -> V_7 . V_20 [ 0 ] ;
F_3 ( V_22 , L_4 ,
V_6 , V_3 , V_5 ) ;
} else {
F_6 ( L_5 , V_3 , V_5 ) ;
V_2 -> V_7 . V_8 = V_5 ;
}
return V_5 ;
}
static int F_9 ( struct V_2 * V_2 ,
T_1 V_3 )
{
int V_5 ;
if ( V_2 -> V_7 . V_8 < 0 )
return - 1 ;
V_5 = F_4 ( V_2 -> V_7 . V_15 ,
F_8 ( V_2 -> V_7 . V_15 , 0 ) ,
1 ,
V_21 | V_17 | V_18 ,
0 , V_3 , V_2 -> V_7 . V_20 , 8 , 500 ) ;
if ( V_5 >= 0 ) {
V_5 = V_2 -> V_7 . V_20 [ 0 ] ;
} else {
F_6 ( L_6 , V_3 , V_5 ) ;
V_2 -> V_7 . V_8 = V_5 ;
}
return V_5 ;
}
static void F_10 ( struct V_2 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
T_2 V_23 )
{
int V_5 ;
T_2 V_24 ;
if ( V_23 != 0xff ) {
V_4 &= V_23 ;
V_5 = F_7 ( V_2 , V_3 ) ;
if ( V_5 < 0 )
return;
V_24 = V_5 & ~ V_23 ;
V_4 |= V_24 ;
}
F_2 ( V_2 , V_3 , V_4 ) ;
}
static void F_11 ( struct V_2 * V_2 , T_1 V_3 , T_3 V_4 , int V_25 )
{
int V_5 ;
if ( V_2 -> V_7 . V_8 < 0 )
return;
* ( ( V_26 * ) V_2 -> V_7 . V_20 ) = F_12 ( V_4 ) ;
V_5 = F_4 ( V_2 -> V_7 . V_15 ,
F_5 ( V_2 -> V_7 . V_15 , 0 ) ,
1 ,
V_16 | V_17 | V_18 ,
0 , V_3 ,
V_2 -> V_7 . V_20 , V_25 , 500 ) ;
if ( V_5 < 0 ) {
F_6 ( L_7 , V_3 , V_5 ) ;
V_2 -> V_7 . V_8 = V_5 ;
}
}
static void F_13 ( struct V_2 * V_2 , T_2 V_27 , T_2 V_4 )
{
int V_28 , V_29 ;
F_3 ( V_14 , L_8 , V_27 , V_4 ) ;
for ( V_29 = 6 ; ; ) {
F_2 ( V_2 , V_30 , V_27 ) ;
F_2 ( V_2 , V_31 , V_4 ) ;
F_2 ( V_2 , V_32 , 0x01 ) ;
do {
V_28 = F_7 ( V_2 , V_32 ) ;
} while ( V_28 > 0 && ( ( V_28 & 1 ) == 0 ) );
if ( V_28 < 0 )
return;
if ( ( V_28 & 2 ) == 0 )
break;
if ( -- V_29 < 0 ) {
F_3 ( V_14 , L_9 ) ;
return;
}
}
}
static int F_14 ( struct V_2 * V_2 , T_2 V_27 )
{
int V_28 , V_4 , V_29 ;
for ( V_29 = 6 ; ; ) {
F_2 ( V_2 , V_33 , V_27 ) ;
F_2 ( V_2 , V_32 , 0x03 ) ;
do {
V_28 = F_7 ( V_2 , V_32 ) ;
} while ( V_28 > 0 && ( ( V_28 & 1 ) == 0 ) );
if ( V_28 < 0 )
return V_28 ;
if ( ( V_28 & 2 ) == 0 )
break;
F_2 ( V_2 , V_32 , 0x10 ) ;
if ( -- V_29 < 0 ) {
F_3 ( V_22 , L_9 ) ;
return - 1 ;
}
}
for ( V_29 = 6 ; ; ) {
F_2 ( V_2 , V_32 , 0x05 ) ;
do {
V_28 = F_7 ( V_2 , V_32 ) ;
} while ( V_28 > 0 && ( ( V_28 & 1 ) == 0 ) );
if ( V_28 < 0 )
return V_28 ;
if ( ( V_28 & 2 ) == 0 )
break;
F_2 ( V_2 , V_32 , 0x10 ) ;
if ( -- V_29 < 0 ) {
F_3 ( V_22 , L_10 ) ;
return - 1 ;
}
}
V_4 = F_7 ( V_2 , V_31 ) ;
F_3 ( V_22 , L_11 , V_27 , V_4 ) ;
F_2 ( V_2 , V_32 , 0x05 ) ;
return V_4 ;
}
static void F_15 ( struct V_2 * V_2 ,
T_2 V_27 ,
T_2 V_4 )
{
F_3 ( V_14 , L_12 , V_27 , V_4 ) ;
F_2 ( V_2 , V_30 , V_27 ) ;
F_2 ( V_2 , V_31 , V_4 ) ;
F_2 ( V_2 , V_34 , 0x01 ) ;
F_16 ( 4 ) ;
F_9 ( V_2 , V_34 ) ;
}
static int F_17 ( struct V_2 * V_2 , T_2 V_27 )
{
int V_4 ;
F_2 ( V_2 , V_33 , V_27 ) ;
F_2 ( V_2 , V_34 , 0x03 ) ;
F_9 ( V_2 , V_34 ) ;
F_2 ( V_2 , V_34 , 0x05 ) ;
F_9 ( V_2 , V_34 ) ;
V_4 = F_7 ( V_2 , V_31 ) ;
F_3 ( V_22 , L_13 , V_27 , V_4 ) ;
return V_4 ;
}
static void F_18 ( struct V_2 * V_2 , T_2 V_27 , T_2 V_4 )
{
int V_5 ;
if ( V_2 -> V_7 . V_8 < 0 )
return;
V_5 = F_4 ( V_2 -> V_7 . V_15 ,
F_5 ( V_2 -> V_7 . V_15 , 0 ) ,
0x02 ,
V_16 | V_17 | V_18 ,
( T_1 ) V_4 , ( T_1 ) V_27 , NULL , 0 , 500 ) ;
if ( V_5 < 0 ) {
F_6 ( L_14 , V_27 , V_5 ) ;
V_2 -> V_7 . V_8 = V_5 ;
}
F_3 ( V_14 , L_15 , V_27 , V_4 ) ;
}
static int F_19 ( struct V_2 * V_2 , T_2 V_27 )
{
int V_5 ;
if ( V_2 -> V_7 . V_8 < 0 )
return - 1 ;
V_5 = F_4 ( V_2 -> V_7 . V_15 ,
F_8 ( V_2 -> V_7 . V_15 , 0 ) ,
0x03 ,
V_21 | V_17 | V_18 ,
0 , ( T_1 ) V_27 , V_2 -> V_7 . V_20 , 1 , 500 ) ;
if ( V_5 >= 0 ) {
V_5 = V_2 -> V_7 . V_20 [ 0 ] ;
F_3 ( V_22 , L_16 , V_27 , V_5 ) ;
} else {
F_6 ( L_17 , V_27 , V_5 ) ;
V_2 -> V_7 . V_8 = V_5 ;
}
return V_5 ;
}
static void F_20 ( struct V_2 * V_2 , T_2 V_27 , T_2 V_4 )
{
if ( V_2 -> V_35 [ V_27 ] == V_4 )
return;
switch ( V_2 -> V_9 ) {
case V_10 :
case V_11 :
F_13 ( V_2 , V_27 , V_4 ) ;
break;
case V_36 :
case V_37 :
case V_38 :
F_15 ( V_2 , V_27 , V_4 ) ;
break;
case V_12 :
F_18 ( V_2 , V_27 , V_4 ) ;
break;
case V_13 :
F_21 ( V_2 , V_27 , V_4 ) ;
break;
}
if ( V_2 -> V_7 . V_8 >= 0 ) {
if ( V_27 == 0x12 && ( V_4 & 0x80 ) )
memset ( V_2 -> V_35 , - 1 ,
sizeof( V_2 -> V_35 ) ) ;
else
V_2 -> V_35 [ V_27 ] = V_4 ;
}
}
static int F_22 ( struct V_2 * V_2 , T_2 V_27 )
{
int V_5 = - 1 ;
if ( V_2 -> V_35 [ V_27 ] != - 1 )
return V_2 -> V_35 [ V_27 ] ;
switch ( V_2 -> V_9 ) {
case V_10 :
case V_11 :
V_5 = F_14 ( V_2 , V_27 ) ;
break;
case V_36 :
case V_37 :
case V_38 :
V_5 = F_17 ( V_2 , V_27 ) ;
break;
case V_12 :
V_5 = F_19 ( V_2 , V_27 ) ;
break;
case V_13 :
V_5 = F_23 ( V_2 , V_27 ) ;
break;
}
if ( V_5 >= 0 )
V_2 -> V_35 [ V_27 ] = V_5 ;
return V_5 ;
}
static void F_24 ( struct V_2 * V_2 ,
T_2 V_27 ,
T_2 V_4 ,
T_2 V_23 )
{
int V_28 ;
T_2 V_24 ;
V_4 &= V_23 ;
V_28 = F_22 ( V_2 , V_27 ) ;
if ( V_28 < 0 )
return;
V_24 = V_28 & ~ V_23 ;
V_4 |= V_24 ;
F_20 ( V_2 , V_27 , V_4 ) ;
}
static inline void F_25 ( struct V_2 * V_2 )
{
F_3 ( V_39 , L_18 ) ;
V_2 -> V_40 = 1 ;
switch ( V_2 -> V_9 ) {
case V_10 :
case V_11 :
F_2 ( V_2 , V_41 , 0x3d ) ;
break;
case V_36 :
case V_37 :
F_10 ( V_2 , V_41 , 0x3a , 0x3a ) ;
break;
case V_38 :
F_2 ( V_2 , V_42 , 0x0f ) ;
F_2 ( V_2 , V_42 , 0x00 ) ;
F_2 ( V_2 , 0x22 , 0x00 ) ;
break;
case V_12 :
F_10 ( V_2 , 0x0f , 0x00 , 0x02 ) ;
break;
case V_13 :
F_2 ( V_2 , 0x3c , 0x0a05 ) ;
break;
}
}
static inline void F_26 ( struct V_2 * V_2 )
{
F_3 ( V_39 , L_19 ) ;
if ( ! V_2 -> V_40 )
return;
V_2 -> V_40 = 0 ;
switch ( V_2 -> V_9 ) {
case V_10 :
case V_11 :
F_2 ( V_2 , V_41 , 0x00 ) ;
break;
case V_36 :
case V_37 :
F_2 ( V_2 , 0x2f , 0x80 ) ;
F_2 ( V_2 , V_41 , 0x00 ) ;
break;
case V_38 :
F_2 ( V_2 , V_42 , 0x0f ) ;
F_2 ( V_2 , V_42 , 0x00 ) ;
F_2 ( V_2 , 0x22 , 0x1d ) ;
break;
case V_12 :
F_10 ( V_2 , 0x0f , 0x02 , 0x02 ) ;
break;
case V_13 :
F_2 ( V_2 , 0x3c , 0x8a05 ) ;
break;
}
}
static int F_27 ( struct V_2 * V_2 , T_2 V_43 )
{
int V_44 ;
F_28 ( V_2 , V_43 ) ;
F_20 ( V_2 , 0x12 , 0x80 ) ;
F_16 ( 150 ) ;
for ( V_44 = 0 ; V_44 < V_45 ; V_44 ++ ) {
if ( F_22 ( V_2 , V_46 ) == 0x7f &&
F_22 ( V_2 , V_47 ) == 0xa2 ) {
F_3 ( V_48 , L_20 , V_44 ) ;
return 0 ;
}
F_20 ( V_2 , 0x12 , 0x80 ) ;
F_16 ( 150 ) ;
if ( F_22 ( V_2 , 0x00 ) < 0 )
return - 1 ;
}
return - 1 ;
}
static void F_28 ( struct V_2 * V_2 ,
T_2 V_43 )
{
switch ( V_2 -> V_9 ) {
case V_12 :
F_2 ( V_2 , V_49 , V_43 ) ;
return;
case V_13 :
V_2 -> V_50 = V_43 ;
return;
}
F_2 ( V_2 , V_51 , V_43 ) ;
F_2 ( V_2 , V_52 , V_43 + 1 ) ;
}
static void F_29 ( struct V_2 * V_2 ,
const struct V_53 * V_54 ,
int V_25 )
{
while ( -- V_25 >= 0 ) {
F_2 ( V_2 , V_54 -> V_27 , V_54 -> V_55 ) ;
V_54 ++ ;
}
}
static void F_30 ( struct V_2 * V_2 ,
const struct V_56 * V_54 ,
int V_25 )
{
while ( -- V_25 >= 0 ) {
F_20 ( V_2 , V_54 -> V_27 , V_54 -> V_55 ) ;
V_54 ++ ;
}
}
static void F_31 ( struct V_2 * V_2 )
{
int V_57 , V_58 ;
if ( V_2 -> V_9 != V_12 ) {
F_6 ( L_21 ) ;
return;
}
F_3 ( V_48 , L_22 ) ;
V_57 = F_22 ( V_2 , 0x0a ) ;
V_58 = F_22 ( V_2 , 0x0b ) ;
switch ( V_57 ) {
case 0x96 :
switch ( V_58 ) {
case 0x40 :
F_3 ( V_48 , L_23 ) ;
V_2 -> V_59 = V_60 ;
return;
case 0x41 :
F_3 ( V_48 , L_24 ) ;
V_2 -> V_59 = V_61 ;
return;
case 0xb1 :
F_3 ( V_48 , L_25 ) ;
V_2 -> V_59 = V_62 ;
return;
}
break;
case 0x36 :
if ( ( V_58 & 0x0f ) == 0x00 ) {
F_3 ( V_48 , L_26 ) ;
V_2 -> V_59 = V_63 ;
return;
}
break;
}
F_6 ( L_27 , V_57 , V_58 ) ;
}
static void F_32 ( struct V_2 * V_2 )
{
int V_28 ;
F_3 ( V_48 , L_28 ) ;
V_28 = F_22 ( V_2 , V_64 ) ;
if ( V_28 < 0 ) {
F_3 ( V_65 , L_29 ) ;
return;
}
if ( ( V_28 & 3 ) == 1 )
V_2 -> V_59 = V_66 ;
else
F_6 ( L_30 , V_28 & 3 ) ;
}
static void F_33 ( struct V_2 * V_2 )
{
int V_28 , V_57 , V_58 ;
F_3 ( V_48 , L_31 ) ;
V_28 = F_22 ( V_2 , V_64 ) ;
if ( V_28 < 0 ) {
F_6 ( L_32 ) ;
return;
}
if ( ( V_28 & 3 ) == 3 ) {
V_57 = F_22 ( V_2 , 0x0a ) ;
V_58 = F_22 ( V_2 , 0x0b ) ;
if ( V_57 == 0x76 && ( V_58 & 0xf0 ) == 0x70 ) {
F_3 ( V_48 , L_33 , V_58 ) ;
V_2 -> V_59 = V_67 ;
} else {
F_3 ( V_48 , L_34 ) ;
V_2 -> V_59 = V_68 ;
}
} else if ( ( V_28 & 3 ) == 1 ) {
if ( F_22 ( V_2 , 0x15 ) & 1 ) {
F_3 ( V_48 , L_35 ) ;
V_2 -> V_59 = V_69 ;
} else {
F_3 ( V_48 , L_36 ) ;
V_2 -> V_59 = V_70 ;
}
} else if ( ( V_28 & 3 ) == 0 ) {
V_57 = F_22 ( V_2 , 0x0a ) ;
if ( V_57 < 0 ) {
F_6 ( L_37 ) ;
return;
}
V_58 = F_22 ( V_2 , 0x0b ) ;
if ( V_58 < 0 ) {
F_6 ( L_38 ) ;
return;
}
if ( V_57 == 0x76 ) {
switch ( V_58 ) {
case 0x30 :
F_6 ( L_39 ) ;
F_6 ( L_40 ) ;
return;
case 0x40 :
F_3 ( V_48 , L_41 ) ;
V_2 -> V_59 = V_71 ;
break;
case 0x45 :
F_3 ( V_48 , L_42 ) ;
V_2 -> V_59 = V_71 ;
break;
case 0x48 :
F_3 ( V_48 , L_43 ) ;
V_2 -> V_59 = V_72 ;
break;
case 0x60 :
F_3 ( V_48 , L_44 ) ;
V_2 -> V_59 = V_73 ;
break;
default:
F_6 ( L_45 , V_58 ) ;
return;
}
} else {
F_3 ( V_48 , L_46 ) ;
V_2 -> V_59 = V_74 ;
}
} else {
F_6 ( L_30 , V_28 & 3 ) ;
}
}
static void F_34 ( struct V_2 * V_2 )
{
int V_28 ;
F_3 ( V_48 , L_47 ) ;
V_28 = F_22 ( V_2 , V_64 ) ;
if ( V_28 < 0 ) {
F_6 ( L_32 ) ;
return;
}
switch ( V_28 ) {
case 0x00 :
V_2 -> V_59 = V_75 ;
F_35 ( L_48 ) ;
break;
case 0x01 :
V_2 -> V_59 = V_76 ;
F_3 ( V_48 , L_49 ) ;
break;
case 0x02 :
V_2 -> V_59 = V_75 ;
F_3 ( V_48 , L_50 ) ;
break;
case 0x03 :
V_2 -> V_59 = V_77 ;
F_3 ( V_48 , L_51 ) ;
break;
case 0x90 :
V_2 -> V_59 = V_75 ;
F_35 ( L_52 ) ;
break;
default:
F_6 ( L_53 , V_28 ) ;
return;
}
V_2 -> V_78 = 1 ;
}
static void F_36 ( struct V_2 * V_2 , int V_79 )
{
if ( V_2 -> V_80 )
V_79 = ! V_79 ;
switch ( V_2 -> V_9 ) {
case V_11 :
F_2 ( V_2 , V_81 , V_79 ) ;
break;
case V_36 :
case V_37 :
F_10 ( V_2 , V_82 , 0x02 * V_79 , 0x02 ) ;
break;
case V_38 :
F_10 ( V_2 , V_83 , V_79 , 1 ) ;
break;
}
}
static void F_37 ( struct V_7 * V_7 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
if ( ! V_2 -> V_84 )
return;
V_2 -> V_84 = 0 ;
switch ( V_2 -> V_9 ) {
case V_10 :
case V_11 :
F_2 ( V_2 , V_85 , 0x02 ) ;
F_2 ( V_2 , V_85 , 0x00 ) ;
break;
case V_36 :
case V_37 :
F_2 ( V_2 , V_85 , 0x02 ) ;
F_2 ( V_2 , V_85 , 0x01 ) ;
break;
case V_38 :
F_2 ( V_2 , V_41 , 0x40 ) ;
F_2 ( V_2 , V_41 , 0x00 ) ;
break;
}
}
static void F_38 ( struct V_2 * V_2 )
{
const unsigned char V_86 [] = {
0 , 1 , 1 , 2 , 2 , 3 , 3 , 4 ,
1 , 1 , 1 , 2 , 2 , 3 , 4 , 4 ,
1 , 1 , 2 , 2 , 3 , 4 , 4 , 4 ,
2 , 2 , 2 , 3 , 4 , 4 , 4 , 4 ,
2 , 2 , 3 , 4 , 4 , 5 , 5 , 5 ,
3 , 3 , 4 , 4 , 5 , 5 , 5 , 5 ,
3 , 4 , 4 , 4 , 5 , 5 , 5 , 5 ,
4 , 4 , 4 , 4 , 5 , 5 , 5 , 5
} ;
const unsigned char V_87 [] = {
0 , 2 , 2 , 3 , 4 , 4 , 4 , 4 ,
2 , 2 , 2 , 4 , 4 , 4 , 4 , 4 ,
2 , 2 , 3 , 4 , 4 , 4 , 4 , 4 ,
3 , 4 , 4 , 4 , 4 , 4 , 4 , 4 ,
4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 ,
4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 ,
4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 ,
4 , 4 , 4 , 4 , 4 , 4 , 4 , 4
} ;
const unsigned char V_88 [] = {
5 , 4 , 5 , 6 , 6 , 7 , 7 , 7 ,
5 , 5 , 5 , 5 , 6 , 7 , 7 , 7 ,
6 , 6 , 6 , 6 , 7 , 7 , 7 , 8 ,
7 , 7 , 6 , 7 , 7 , 7 , 8 , 8
} ;
const unsigned char V_89 [] = {
6 , 6 , 6 , 7 , 7 , 7 , 7 , 7 ,
6 , 6 , 6 , 7 , 7 , 7 , 7 , 7 ,
6 , 6 , 6 , 7 , 7 , 7 , 7 , 8 ,
7 , 7 , 7 , 7 , 7 , 7 , 8 , 8
} ;
const unsigned char * V_90 , * V_91 ;
unsigned char V_92 , V_93 ;
int V_44 , V_94 , V_27 = V_95 ;
F_3 ( V_48 , L_54 ) ;
if ( V_2 -> V_9 == V_10 || V_2 -> V_9 == V_11 ) {
V_90 = V_86 ;
V_91 = V_87 ;
V_94 = 32 ;
} else {
V_90 = V_88 ;
V_91 = V_89 ;
V_94 = 16 ;
}
for ( V_44 = 0 ; V_44 < V_94 ; V_44 ++ ) {
V_92 = * V_90 ++ ;
V_93 = * V_90 ++ ;
V_92 &= 0x0f ;
V_93 &= 0x0f ;
V_92 |= V_93 << 4 ;
F_2 ( V_2 , V_27 , V_92 ) ;
V_92 = * V_91 ++ ;
V_93 = * V_91 ++ ;
V_92 &= 0x0f ;
V_93 &= 0x0f ;
V_92 |= V_93 << 4 ;
F_2 ( V_2 , V_27 + V_94 , V_92 ) ;
V_27 ++ ;
}
}
static void F_39 ( struct V_7 * V_7 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
const struct V_53 V_96 [] = {
{ V_41 , 0x7f } ,
{ V_97 , 0x01 } ,
{ V_41 , 0x7f } ,
{ V_97 , 0x01 } ,
{ V_41 , 0x3f } ,
{ V_97 , 0x01 } ,
{ V_41 , 0x3d } ,
} ;
const struct V_53 V_98 [] = {
{ V_99 , 0x01 } ,
{ V_85 , 0x00 } ,
{ V_85 , 0x02 } ,
{ V_85 , 0x00 } ,
{ V_100 , 0x1f } ,
{ V_101 , 0x00 } ,
{ V_102 , 0x03 } ,
} ;
const struct V_53 V_103 [] = {
{ V_99 , 0xff } ,
{ V_85 , 0x00 } ,
{ V_85 , 0x02 } ,
{ V_85 , 0x00 } ,
{ V_100 , 0xff } ,
{ V_101 , 0x00 } ,
{ V_102 , 0x03 } ,
} ;
const struct V_53 V_104 [] = {
{ 0x70 , 0x1f } ,
{ 0x71 , 0x05 } ,
{ 0x72 , 0x06 } ,
{ 0x73 , 0x06 } ,
{ 0x74 , 0x14 } ,
{ 0x75 , 0x03 } ,
{ 0x76 , 0x04 } ,
{ 0x77 , 0x04 } ,
} ;
F_3 ( V_48 , L_55 , F_7 ( V_2 , V_105 ) ) ;
F_29 ( V_2 , V_96 , F_40 ( V_96 ) ) ;
switch ( V_2 -> V_9 ) {
case V_10 :
F_29 ( V_2 , V_98 , F_40 ( V_98 ) ) ;
break;
case V_11 :
F_29 ( V_2 , V_103 , F_40 ( V_103 ) ) ;
break;
}
F_29 ( V_2 , V_104 , F_40 ( V_104 ) ) ;
F_38 ( V_2 ) ;
}
static void F_41 ( struct V_7 * V_7 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
const struct V_53 V_106 [] = {
{ V_41 , 0x40 } ,
{ V_97 , 0xe1 } ,
{ V_41 , 0x3e } ,
{ V_97 , 0xe1 } ,
{ V_41 , 0x00 } ,
{ V_97 , 0xe1 } ,
{ 0x46 , 0x00 } ,
{ 0x5d , 0x03 } ,
} ;
const struct V_53 V_107 [] = {
{ V_85 , 0x02 } ,
{ V_85 , 0x01 } ,
{ 0x31 , 0x0f } ,
{ 0x5d , 0x03 } ,
{ 0x24 , 0x9f } ,
{ 0x25 , 0x90 } ,
{ 0x20 , 0x00 } ,
{ 0x51 , 0x04 } ,
{ 0x71 , 0x19 } ,
{ 0x2f , 0x80 } ,
} ;
const struct V_53 V_108 [] = {
{ V_85 , 0x02 } ,
{ V_85 , 0x01 } ,
{ 0x31 , 0x0f } ,
{ 0x5d , 0x03 } ,
{ 0x24 , 0x9f } ,
{ 0x25 , 0x90 } ,
{ 0x20 , 0x60 } ,
{ 0x51 , 0x02 } ,
{ 0x71 , 0x19 } ,
{ 0x40 , 0xff } ,
{ 0x41 , 0x42 } ,
{ 0x46 , 0x00 } ,
{ 0x33 , 0x04 } ,
{ 0x21 , 0x19 } ,
{ 0x3f , 0x10 } ,
{ 0x2f , 0x80 } ,
} ;
F_3 ( V_48 , L_56 ,
0x1f & F_7 ( V_2 , V_105 ) ) ;
F_29 ( V_2 , V_106 , F_40 ( V_106 ) ) ;
F_10 ( V_2 , V_109 , 0x00 , 0x02 ) ;
switch ( V_2 -> V_9 ) {
case V_36 :
F_29 ( V_2 , V_107 , F_40 ( V_107 ) ) ;
break;
case V_37 :
F_29 ( V_2 , V_108 , F_40 ( V_108 ) ) ;
break;
}
F_38 ( V_2 ) ;
F_2 ( V_2 , 0x2f , 0x80 ) ;
}
static void F_42 ( struct V_2 * V_2 )
{
static const struct V_53 V_110 [] = {
{ 0x5a , 0x6d } ,
{ 0x53 , 0x9b } ,
{ V_111 , 0xff } ,
{ 0x5d , 0x03 } ,
{ 0x49 , 0x01 } ,
{ 0x48 , 0x00 } ,
{ V_112 , 0xee } ,
{ V_42 , 0x0f } ,
{ V_42 , 0x00 } ,
{ 0x22 , 0x00 } ,
} ;
F_29 ( V_2 , V_110 , F_40 ( V_110 ) ) ;
}
static void F_43 ( struct V_2 * V_2 )
{
static const struct V_53 V_113 [] = {
{ 0x00 , 0x60 } ,
{ 0x02 , 0x01 } ,
{ 0x0f , 0x1d } ,
{ 0xe9 , 0x82 } ,
{ 0xea , 0xc7 } ,
{ 0xeb , 0x10 } ,
{ 0xec , 0xf6 } ,
} ;
V_2 -> V_40 = 1 ;
F_29 ( V_2 , V_113 , F_40 ( V_113 ) ) ;
}
static void F_44 ( struct V_2 * V_2 )
{
static const struct V_53 V_114 [ 2 ] [ 10 ] = {
{ { 0x10 , 0x14 } , { 0x11 , 0x1e } , { 0x12 , 0x00 } , { 0x13 , 0x00 } ,
{ 0x14 , 0x00 } , { 0x15 , 0x00 } , { 0x16 , 0x00 } , { 0x20 , 0x0c } ,
{ 0x25 , 0x01 } , { 0x26 , 0x00 } } ,
{ { 0x10 , 0x28 } , { 0x11 , 0x3c } , { 0x12 , 0x00 } , { 0x13 , 0x00 } ,
{ 0x14 , 0x00 } , { 0x15 , 0x00 } , { 0x16 , 0x00 } , { 0x20 , 0x0c } ,
{ 0x25 , 0x03 } , { 0x26 , 0x00 } }
} ;
static const struct V_56 V_115 [ 2 ] [ 3 ] = {
{ { 0x12 , 0x00 } , { 0x24 , 0x00 } , { 0x0c , 0x0c } } ,
{ { 0x12 , 0x00 } , { 0x04 , 0x00 } , { 0x0c , 0x00 } }
} ;
static const struct V_56 V_116 [] = {
{ V_117 , 0x13 } ,
{ V_118 , 0x01 } ,
{ V_119 , 0x92 } ,
{ V_120 , 0x02 } ,
{ V_121 , 0x7a } ,
{ V_122 , 0x00 } ,
} ;
F_29 ( V_2 , V_114 [ V_2 -> V_7 . V_123 ] ,
F_40 ( V_114 [ 0 ] ) ) ;
F_30 ( V_2 , V_115 [ V_2 -> V_7 . V_123 ] ,
F_40 ( V_115 [ 0 ] ) ) ;
F_30 ( V_2 , V_116 ,
F_40 ( V_116 ) ) ;
}
static void F_45 ( struct V_2 * V_2 )
{
int V_124 ;
T_2 clock ;
static const T_2 V_125 [ 2 ] [ 6 ] [ 3 ] = {
{ { 0x04 , 0xff , 0x00 } ,
{ 0x04 , 0x1f , 0x00 } ,
{ 0x04 , 0x1b , 0x00 } ,
{ 0x04 , 0x15 , 0x00 } ,
{ 0x04 , 0x09 , 0x00 } ,
{ 0x04 , 0x01 , 0x00 } } ,
{ { 0x0c , 0xff , 0x00 } ,
{ 0x0c , 0x1f , 0x00 } ,
{ 0x0c , 0x1b , 0x00 } ,
{ 0x04 , 0xff , 0x01 } ,
{ 0x04 , 0x1f , 0x01 } ,
{ 0x04 , 0x1b , 0x01 } } ,
} ;
if ( V_126 > 0 )
V_2 -> V_126 = V_126 ;
if ( V_2 -> V_126 >= 30 )
V_124 = 0 ;
else if ( V_2 -> V_126 >= 25 )
V_124 = 1 ;
else if ( V_2 -> V_126 >= 20 )
V_124 = 2 ;
else if ( V_2 -> V_126 >= 15 )
V_124 = 3 ;
else if ( V_2 -> V_126 >= 10 )
V_124 = 4 ;
else
V_124 = 5 ;
F_2 ( V_2 , 0xa4 , V_125 [ V_2 -> V_7 . V_123 ] [ V_124 ] [ 0 ] ) ;
F_2 ( V_2 , 0x23 , V_125 [ V_2 -> V_7 . V_123 ] [ V_124 ] [ 1 ] ) ;
clock = V_125 [ V_2 -> V_7 . V_123 ] [ V_124 ] [ 2 ] ;
if ( V_2 -> V_59 == V_73 )
clock |= 0x80 ;
F_15 ( V_2 , V_127 , clock ) ;
}
static void F_46 ( struct V_7 * V_7 , T_4 V_55 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
F_24 ( V_2 , 0x13 , V_55 ? 0x05 : 0x00 , 0x05 ) ;
}
static int F_47 ( struct V_7 * V_7 ,
const struct V_128 * V_129 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
struct V_130 * V_130 = & V_7 -> V_130 ;
V_2 -> V_9 = V_129 -> V_131 & V_132 ;
V_2 -> V_80 = ( V_129 -> V_131 & V_133 ) != 0 ;
switch ( V_2 -> V_9 ) {
case V_10 :
case V_11 :
V_130 -> V_134 = V_135 ;
V_130 -> V_136 = F_40 ( V_135 ) ;
break;
case V_36 :
case V_37 :
V_130 -> V_134 = V_137 ;
V_130 -> V_136 = F_40 ( V_137 ) ;
break;
case V_38 :
V_130 -> V_134 = V_138 ;
V_130 -> V_136 = F_40 ( V_138 ) ;
break;
case V_12 :
V_130 -> V_134 = V_138 ;
V_130 -> V_136 = F_40 ( V_138 ) ;
V_130 -> V_139 = V_140 ;
V_130 -> V_141 = V_142 ;
V_130 -> V_143 = 1 ;
break;
case V_13 :
V_130 -> V_134 = V_144 ;
V_130 -> V_136 = F_40 ( V_144 ) ;
break;
}
V_2 -> V_126 = 15 ;
return 0 ;
}
static int F_48 ( struct V_7 * V_7 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
struct V_130 * V_130 = & V_7 -> V_130 ;
switch ( V_2 -> V_9 ) {
case V_10 :
case V_11 :
F_39 ( V_7 ) ;
break;
case V_36 :
case V_37 :
F_41 ( V_7 ) ;
break;
case V_38 :
F_42 ( V_2 ) ;
break;
case V_12 :
F_43 ( V_2 ) ;
break;
case V_13 :
F_49 ( V_2 ) ;
break;
}
V_2 -> V_59 = - 1 ;
if ( F_27 ( V_2 , V_145 ) >= 0 ) {
F_33 ( V_2 ) ;
} else if ( F_27 ( V_2 , V_146 ) >= 0 ) {
F_34 ( V_2 ) ;
} else if ( F_27 ( V_2 , V_147 ) >= 0 ) {
F_32 ( V_2 ) ;
} else if ( F_27 ( V_2 , V_148 ) >= 0 ) {
F_31 ( V_2 ) ;
} else {
F_6 ( L_57 ) ;
goto error;
}
if ( V_2 -> V_59 < 0 )
goto error;
F_36 ( V_2 , 0 ) ;
switch ( V_2 -> V_9 ) {
case V_10 :
case V_11 :
if ( V_2 -> V_78 ) {
V_130 -> V_134 = V_149 ;
V_130 -> V_136 = F_40 ( V_149 ) ;
}
break;
case V_36 :
case V_37 :
if ( V_2 -> V_78 ) {
V_130 -> V_134 = V_150 ;
V_130 -> V_136 = F_40 ( V_150 ) ;
}
break;
case V_38 :
if ( V_2 -> V_78 ) {
V_130 -> V_134 = V_151 ;
V_130 -> V_136 = F_40 ( V_151 ) ;
}
break;
case V_12 :
switch ( V_2 -> V_59 ) {
case V_60 :
case V_61 :
V_130 -> V_134 = V_152 ;
V_130 -> V_136 = F_40 ( V_152 ) ;
break;
case V_63 :
V_130 -> V_134 = V_153 ;
V_130 -> V_136 = F_40 ( V_153 ) ;
break;
case V_62 :
V_130 -> V_134 = V_154 ;
V_130 -> V_136 = F_40 ( V_154 ) ;
break;
default:
if ( V_2 -> V_78 ) {
V_130 -> V_134 = V_151 ;
V_130 -> V_136 = F_40 ( V_151 ) ;
}
break;
}
break;
case V_13 :
if ( V_2 -> V_78 )
V_130 -> V_136 = F_40 ( V_144 ) - 1 ;
F_50 ( V_2 ) ;
break;
}
switch ( V_2 -> V_59 ) {
case V_60 :
F_30 ( V_2 , V_155 , F_40 ( V_155 ) ) ;
F_24 ( V_2 , 0x13 , 0x27 , 0x27 ) ;
break;
case V_61 :
F_30 ( V_2 , V_156 , F_40 ( V_156 ) ) ;
F_24 ( V_2 , 0x13 , 0x05 , 0x05 ) ;
break;
case V_63 :
F_30 ( V_2 , V_157 , F_40 ( V_157 ) ) ;
F_24 ( V_2 , 0x13 , 0x27 , 0x27 ) ;
break;
case V_76 :
F_30 ( V_2 , V_158 , F_40 ( V_158 ) ) ;
break;
case V_75 :
case V_77 :
F_30 ( V_2 , V_159 , F_40 ( V_159 ) ) ;
break;
default:
F_30 ( V_2 , V_160 , F_40 ( V_160 ) ) ;
F_24 ( V_2 , 0x0e , 0x00 , 0x40 ) ;
break;
case V_74 :
case V_69 :
F_30 ( V_2 , V_161 , F_40 ( V_161 ) ) ;
break;
case V_71 :
case V_72 :
F_30 ( V_2 , V_162 , F_40 ( V_162 ) ) ;
break;
case V_73 :
F_20 ( V_2 , V_163 , V_164 ) ;
F_16 ( 14 ) ;
F_2 ( V_2 , V_165 , 0x23 ) ;
F_29 ( V_2 , V_166 ,
F_40 ( V_166 ) ) ;
F_30 ( V_2 , V_167 , F_40 ( V_167 ) ) ;
V_2 -> V_7 . V_123 = 1 ;
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
F_37 ( V_7 ) ;
F_26 ( V_2 ) ;
F_25 ( V_2 ) ;
F_36 ( V_2 , 0 ) ;
break;
case V_67 :
F_30 ( V_2 , V_168 , F_40 ( V_168 ) ) ;
break;
case V_66 :
F_30 ( V_2 , V_169 , F_40 ( V_169 ) ) ;
break;
case V_62 :
F_30 ( V_2 , V_170 , F_40 ( V_170 ) ) ;
break;
}
return V_7 -> V_8 ;
error:
F_3 ( V_65 , L_58 ) ;
return - V_171 ;
}
static int F_51 ( struct V_7 * V_7 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
switch ( V_2 -> V_9 ) {
case V_12 :
if ( V_7 -> V_172 != 800 )
V_7 -> V_130 . V_139 = V_140 ;
else
V_7 -> V_130 . V_139 = 7 * 4096 ;
break;
}
return 0 ;
}
static void F_52 ( struct V_2 * V_2 )
{
int V_173 , V_174 , V_175 , V_176 , V_177 ;
int V_178 = 0 ;
struct V_179 * V_180 ;
struct V_181 * V_182 ;
V_182 = F_53 ( V_2 -> V_7 . V_15 , V_2 -> V_7 . V_183 ) ;
V_180 = F_54 ( V_182 , V_2 -> V_7 . V_180 ) ;
if ( ! V_180 ) {
F_6 ( L_59 ) ;
V_2 -> V_7 . V_8 = - V_184 ;
return;
}
V_175 = F_55 ( V_180 -> V_185 [ 0 ] . V_186 . V_187 ) ;
F_2 ( V_2 , V_188 , V_175 >> 5 ) ;
F_2 ( V_2 , V_189 , 0x01 ) ;
F_2 ( V_2 , V_190 , 0x01 ) ;
F_2 ( V_2 , V_191 , 0x03 ) ;
V_173 = ( V_2 -> V_7 . V_172 >> 3 ) - 1 ;
V_174 = ( V_2 -> V_7 . V_192 >> 3 ) - 1 ;
F_2 ( V_2 , V_193 , V_173 ) ;
F_2 ( V_2 , V_194 , V_174 ) ;
F_2 ( V_2 , V_195 , 0x00 ) ;
F_2 ( V_2 , V_196 , 0x00 ) ;
F_2 ( V_2 , V_197 , 0x03 ) ;
F_2 ( V_2 , V_198 , V_173 ) ;
F_2 ( V_2 , V_199 , V_174 ) ;
F_2 ( V_2 , V_200 , 0x00 ) ;
F_2 ( V_2 , V_201 , 0x00 ) ;
if ( V_126 > 0 )
V_2 -> V_126 = V_126 ;
switch ( V_2 -> V_59 ) {
case V_76 :
V_2 -> V_202 = 3 ;
break;
case V_74 :
case V_69 :
case V_71 :
case V_72 :
case V_70 :
if ( V_2 -> V_7 . V_172 == 320 )
V_178 = 1 ;
case V_75 :
case V_68 :
case V_67 :
switch ( V_2 -> V_126 ) {
case 30 :
case 25 :
if ( V_2 -> V_7 . V_172 != 640 ) {
V_2 -> V_202 = 0 ;
break;
}
default:
V_2 -> V_202 = 1 ;
break;
case 10 :
V_2 -> V_202 = 2 ;
break;
case 5 :
V_2 -> V_202 = 5 ;
break;
}
if ( V_178 ) {
V_2 -> V_202 = ( V_2 -> V_202 + 1 ) * 2 - 1 ;
if ( V_2 -> V_202 > 10 )
V_2 -> V_202 = 10 ;
}
break;
case V_66 :
V_2 -> V_202 = 0 ;
break;
}
V_176 = ( V_178 ? 60 : 30 ) / ( V_2 -> V_202 + 1 ) + 1 ;
V_177 = V_176 * V_2 -> V_7 . V_172 * V_2 -> V_7 . V_192 * 3 / 2 ;
if ( V_177 > 1000 * V_175 ) {
F_2 ( V_2 , V_101 , 0x07 ) ;
F_2 ( V_2 , V_102 , 0x03 ) ;
} else {
F_2 ( V_2 , V_101 , 0x06 ) ;
F_2 ( V_2 , V_102 , 0x00 ) ;
}
F_2 ( V_2 , V_41 , V_203 ) ;
F_2 ( V_2 , V_41 , 0 ) ;
}
static void F_56 ( struct V_2 * V_2 )
{
int V_173 , V_174 , V_175 ;
struct V_179 * V_180 ;
struct V_181 * V_182 ;
V_182 = F_53 ( V_2 -> V_7 . V_15 , V_2 -> V_7 . V_183 ) ;
V_180 = F_54 ( V_182 , V_2 -> V_7 . V_180 ) ;
if ( ! V_180 ) {
F_6 ( L_59 ) ;
V_2 -> V_7 . V_8 = - V_184 ;
return;
}
V_175 = F_55 ( V_180 -> V_185 [ 0 ] . V_186 . V_187 ) ;
F_11 ( V_2 , V_188 , V_175 & ~ 7 , 2 ) ;
F_2 ( V_2 , 0x2b , 0 ) ;
F_2 ( V_2 , 0x2c , 0 ) ;
F_2 ( V_2 , 0x2d , 0 ) ;
F_2 ( V_2 , 0x2e , 0 ) ;
F_2 ( V_2 , 0x3b , 0 ) ;
F_2 ( V_2 , 0x3c , 0 ) ;
F_2 ( V_2 , 0x3d , 0 ) ;
F_2 ( V_2 , 0x3e , 0 ) ;
if ( V_2 -> V_9 == V_36 ) {
F_10 ( V_2 , 0x20 , 0x08 , 0x08 ) ;
F_10 ( V_2 , 0x28 , 0x80 , 0xf0 ) ;
F_10 ( V_2 , 0x38 , 0x80 , 0xf0 ) ;
} else {
F_2 ( V_2 , 0x28 , 0x80 ) ;
F_2 ( V_2 , 0x38 , 0x80 ) ;
}
V_173 = V_2 -> V_7 . V_172 / 16 ;
V_174 = V_2 -> V_7 . V_192 / 4 ;
F_2 ( V_2 , 0x29 , V_173 ) ;
F_2 ( V_2 , 0x2a , V_174 ) ;
F_2 ( V_2 , 0x39 , V_173 ) ;
F_2 ( V_2 , 0x3a , V_174 ) ;
F_2 ( V_2 , 0x2f , 0x80 ) ;
V_2 -> V_202 = 1 ;
F_2 ( V_2 , 0x51 , 0x04 ) ;
F_2 ( V_2 , 0x22 , 0x18 ) ;
F_2 ( V_2 , 0x23 , 0xff ) ;
if ( V_2 -> V_9 == V_37 ) {
switch ( V_2 -> V_59 ) {
case V_69 :
if ( V_2 -> V_7 . V_172 == 320 ) {
F_2 ( V_2 , 0x20 , 0x00 ) ;
F_2 ( V_2 , 0x21 , 0x19 ) ;
} else {
F_2 ( V_2 , 0x20 , 0x60 ) ;
F_2 ( V_2 , 0x21 , 0x1f ) ;
}
break;
case V_74 :
F_2 ( V_2 , 0x20 , 0x00 ) ;
F_2 ( V_2 , 0x21 , 0x19 ) ;
break;
default:
F_2 ( V_2 , 0x21 , 0x19 ) ;
}
} else
F_2 ( V_2 , 0x71 , 0x17 ) ;
F_20 ( V_2 , 0x54 , 0x23 ) ;
F_2 ( V_2 , 0x2f , 0x80 ) ;
if ( V_2 -> V_9 == V_37 ) {
F_2 ( V_2 , 0x24 , 0x94 ) ;
F_2 ( V_2 , 0x25 , 0x90 ) ;
F_11 ( V_2 , 0xc4 , 400 , 2 ) ;
F_11 ( V_2 , 0xc6 , 540 , 2 ) ;
F_11 ( V_2 , 0xc7 , 540 , 2 ) ;
F_11 ( V_2 , 0xc8 , 108 , 2 ) ;
F_11 ( V_2 , 0xca , 131098 , 3 ) ;
F_11 ( V_2 , 0xcb , 532 , 2 ) ;
F_11 ( V_2 , 0xcc , 2400 , 2 ) ;
F_11 ( V_2 , 0xcd , 32 , 2 ) ;
F_11 ( V_2 , 0xce , 608 , 2 ) ;
} else {
F_2 ( V_2 , 0x24 , 0x9f ) ;
F_2 ( V_2 , 0x25 , 0x90 ) ;
F_11 ( V_2 , 0xc4 , 400 , 2 ) ;
F_11 ( V_2 , 0xc6 , 381 , 2 ) ;
F_11 ( V_2 , 0xc7 , 381 , 2 ) ;
F_11 ( V_2 , 0xc8 , 128 , 2 ) ;
F_11 ( V_2 , 0xca , 183331 , 3 ) ;
F_11 ( V_2 , 0xcb , 746 , 2 ) ;
F_11 ( V_2 , 0xcc , 1750 , 2 ) ;
F_11 ( V_2 , 0xcd , 45 , 2 ) ;
F_11 ( V_2 , 0xce , 851 , 2 ) ;
}
F_2 ( V_2 , 0x2f , 0x80 ) ;
}
static void F_57 ( struct V_2 * V_2 )
{
static const struct V_53 V_204 [] = {
{ 0x5d , 0x03 } ,
{ 0x53 , 0x9f } ,
{ V_111 , 0x0f } ,
{ 0xa2 , 0x20 } ,
{ 0xa3 , 0x18 } ,
{ 0xa4 , 0x04 } ,
{ 0xa5 , 0x28 } ,
{ 0x37 , 0x00 } ,
{ 0x55 , 0x02 } ,
{ 0x20 , 0x0c } ,
{ 0x21 , 0x38 } ,
{ 0x22 , 0x1d } ,
{ 0x17 , 0x50 } ,
{ 0x37 , 0x00 } ,
{ 0x40 , 0xff } ,
{ 0x46 , 0x00 } ,
{ 0x59 , 0x04 } ,
{ 0xff , 0x00 } ,
} ;
static const struct V_53 V_205 [] = {
{ 0x5d , 0x03 } ,
{ 0x53 , 0x9f } ,
{ V_111 , 0x0f } ,
{ 0xa2 , 0x20 } ,
{ 0xa3 , 0x18 } ,
{ 0xa4 , 0x04 } ,
{ 0xa5 , 0x28 } ,
{ 0x37 , 0x00 } ,
{ 0x55 , 0x02 } ,
{ 0x22 , 0x1d } ,
{ 0x17 , 0x50 } ,
{ 0x37 , 0x00 } ,
{ 0x40 , 0xff } ,
{ 0x46 , 0x00 } ,
{ 0x59 , 0x04 } ,
{ 0xff , 0x00 } ,
} ;
switch ( V_2 -> V_59 ) {
default:
F_29 ( V_2 , V_205 , F_40 ( V_205 ) ) ;
if ( V_2 -> V_59 == V_71 ||
V_2 -> V_59 == V_72 ) {
F_10 ( V_2 , V_206 , 0x10 , 0x10 ) ;
}
break;
case V_73 :
return;
case V_67 :
F_29 ( V_2 , V_204 ,
F_40 ( V_204 ) ) ;
break;
}
F_2 ( V_2 , V_207 , V_2 -> V_7 . V_172 >> 4 ) ;
F_2 ( V_2 , V_208 , V_2 -> V_7 . V_192 >> 3 ) ;
if ( V_2 -> V_59 == V_67 &&
V_2 -> V_7 . V_130 . V_134 [ V_2 -> V_7 . V_123 ] . V_209 )
F_2 ( V_2 , V_210 , 0x04 ) ;
else if ( V_2 -> V_59 == V_72 &&
V_2 -> V_7 . V_130 . V_134 [ V_2 -> V_7 . V_123 ] . V_209 )
F_2 ( V_2 , V_210 , 0x01 ) ;
else
F_2 ( V_2 , V_210 , 0x00 ) ;
F_2 ( V_2 , V_211 , 0x00 ) ;
F_2 ( V_2 , V_212 , 0x00 ) ;
F_2 ( V_2 , V_213 , 0x00 ) ;
F_2 ( V_2 , V_214 , 0x00 ) ;
F_2 ( V_2 , V_215 , 0x03 ) ;
F_2 ( V_2 , 0x26 , 0x00 ) ;
if ( V_126 > 0 )
V_2 -> V_126 = V_126 ;
V_2 -> V_202 = 0 ;
switch ( V_2 -> V_59 ) {
case V_71 :
case V_72 :
switch ( V_2 -> V_126 ) {
default:
F_2 ( V_2 , 0xa4 , 0x0c ) ;
F_2 ( V_2 , 0x23 , 0xff ) ;
break;
case 25 :
F_2 ( V_2 , 0xa4 , 0x0c ) ;
F_2 ( V_2 , 0x23 , 0x1f ) ;
break;
case 20 :
F_2 ( V_2 , 0xa4 , 0x0c ) ;
F_2 ( V_2 , 0x23 , 0x1b ) ;
break;
case 15 :
F_2 ( V_2 , 0xa4 , 0x04 ) ;
F_2 ( V_2 , 0x23 , 0xff ) ;
V_2 -> V_202 = 1 ;
break;
case 10 :
F_2 ( V_2 , 0xa4 , 0x04 ) ;
F_2 ( V_2 , 0x23 , 0x1f ) ;
V_2 -> V_202 = 1 ;
break;
case 5 :
F_2 ( V_2 , 0xa4 , 0x04 ) ;
F_2 ( V_2 , 0x23 , 0x1b ) ;
V_2 -> V_202 = 1 ;
break;
}
break;
case V_66 :
switch ( V_2 -> V_126 ) {
default:
F_2 ( V_2 , 0xa4 , 0x06 ) ;
F_2 ( V_2 , 0x23 , 0xff ) ;
break;
case 10 :
F_2 ( V_2 , 0xa4 , 0x06 ) ;
F_2 ( V_2 , 0x23 , 0x1f ) ;
break;
case 5 :
F_2 ( V_2 , 0xa4 , 0x06 ) ;
F_2 ( V_2 , 0x23 , 0x1b ) ;
break;
}
break;
case V_67 :
F_3 ( V_39 , L_60 ,
( V_2 -> V_126 == 0 ) ? 15 : V_2 -> V_126 ) ;
F_2 ( V_2 , 0xa4 , 0x10 ) ;
switch ( V_2 -> V_126 ) {
case 30 :
F_2 ( V_2 , 0x23 , 0xff ) ;
break;
case 20 :
F_2 ( V_2 , 0x23 , 0x1b ) ;
break;
default:
F_2 ( V_2 , 0x23 , 0xff ) ;
V_2 -> V_202 = 1 ;
break;
}
break;
}
}
static void F_58 ( struct V_2 * V_2 )
{
struct V_7 * V_7 ;
int V_216 , V_217 , V_218 , V_219 , V_220 ;
T_2 V_1 ;
V_7 = & V_2 -> V_7 ;
V_216 = V_7 -> V_130 . V_134 [ V_7 -> V_123 ] . V_209 & 1 ;
switch ( V_2 -> V_59 ) {
case V_60 :
F_24 ( V_2 , 0x14 , V_216 ? 0x20 : 0x00 , 0x20 ) ;
F_24 ( V_2 , 0x28 , V_216 ? 0x00 : 0x20 , 0x20 ) ;
F_20 ( V_2 , 0x24 , V_216 ? 0x20 : 0x3a ) ;
F_20 ( V_2 , 0x25 , V_216 ? 0x30 : 0x60 ) ;
F_24 ( V_2 , 0x2d , V_216 ? 0x40 : 0x00 , 0x40 ) ;
F_24 ( V_2 , 0x67 , V_216 ? 0xf0 : 0x90 , 0xf0 ) ;
F_24 ( V_2 , 0x74 , V_216 ? 0x20 : 0x00 , 0x20 ) ;
return;
case V_61 : {
T_2 V_1 ;
V_1 = 80 ;
if ( V_216 ) {
if ( V_2 -> V_126 < 25 )
V_1 = 0x81 ;
} else {
if ( V_2 -> V_126 < 10 )
V_1 = 0x81 ;
}
F_20 ( V_2 , 0x11 , V_1 ) ;
F_20 ( V_2 , 0x12 , V_216 ? 0x60 : 0x20 ) ;
return;
}
case V_63 :
if ( V_216 ) {
V_217 = ( 1040 - V_7 -> V_172 ) / 2 + ( 0x1f << 4 ) ;
V_219 = ( 776 - V_7 -> V_192 ) / 2 ;
} else {
V_217 = ( 2076 - V_7 -> V_172 ) / 2 + ( 0x10 << 4 ) ;
V_219 = ( 1544 - V_7 -> V_192 ) / 2 ;
}
V_218 = V_217 + V_7 -> V_172 ;
V_220 = V_219 + V_7 -> V_192 ;
F_24 ( V_2 , 0x12 , V_216 ? 0x40 : 0x00 , 0xf0 ) ;
F_24 ( V_2 , 0x32 ,
( ( ( V_218 >> 1 ) & 7 ) << 3 ) | ( ( V_217 >> 1 ) & 7 ) ,
0x3f ) ;
F_24 ( V_2 , 0x03 ,
( ( ( V_220 >> 1 ) & 3 ) << 2 ) | ( ( V_219 >> 1 ) & 3 ) ,
0x0f ) ;
F_20 ( V_2 , 0x17 , V_217 >> 4 ) ;
F_20 ( V_2 , 0x18 , V_218 >> 4 ) ;
F_20 ( V_2 , 0x19 , V_219 >> 3 ) ;
F_20 ( V_2 , 0x1a , V_220 >> 3 ) ;
return;
case V_66 :
F_24 ( V_2 , V_221 , V_216 ? ( 1 << 5 ) : 0 , 1 << 5 ) ;
F_24 ( V_2 , 0x13 , 0x00 , 0x20 ) ;
F_24 ( V_2 , 0x12 , 0x04 , 0x06 ) ;
F_24 ( V_2 , 0x2d , 0x00 , 0x40 ) ;
F_24 ( V_2 , 0x28 , 0x20 , 0x20 ) ;
break;
case V_68 :
F_24 ( V_2 , 0x14 , V_216 ? 0x20 : 0x00 , 0x20 ) ;
F_20 ( V_2 , 0x35 , V_216 ? 0x1e : 0x9e ) ;
F_24 ( V_2 , 0x13 , 0x00 , 0x20 ) ;
F_24 ( V_2 , 0x12 , 0x04 , 0x06 ) ;
break;
case V_74 :
case V_69 :
case V_70 :
F_24 ( V_2 , 0x14 , V_216 ? 0x20 : 0x00 , 0x20 ) ;
F_24 ( V_2 , 0x28 , V_216 ? 0x00 : 0x20 , 0x20 ) ;
F_20 ( V_2 , 0x24 , V_216 ? 0x20 : 0x3a ) ;
F_20 ( V_2 , 0x25 , V_216 ? 0x30 : 0x60 ) ;
F_24 ( V_2 , 0x2d , V_216 ? 0x40 : 0x00 , 0x40 ) ;
F_24 ( V_2 , 0x67 , V_216 ? 0xb0 : 0x90 , 0xf0 ) ;
F_24 ( V_2 , 0x74 , V_216 ? 0x20 : 0x00 , 0x20 ) ;
F_24 ( V_2 , 0x13 , 0x00 , 0x20 ) ;
F_24 ( V_2 , 0x12 , 0x04 , 0x06 ) ;
if ( V_2 -> V_59 == V_70 )
F_20 ( V_2 , 0x35 , V_216 ? 0x1e : 0x9e ) ;
break;
case V_71 :
case V_72 :
F_24 ( V_2 , 0x14 , V_216 ? 0x20 : 0x00 , 0x20 ) ;
F_24 ( V_2 , 0x28 , V_216 ? 0x00 : 0x20 , 0x20 ) ;
F_24 ( V_2 , 0x2d , V_216 ? 0x40 : 0x00 , 0x40 ) ;
F_24 ( V_2 , 0x67 , V_216 ? 0xf0 : 0x90 , 0xf0 ) ;
F_24 ( V_2 , 0x74 , V_216 ? 0x20 : 0x00 , 0x20 ) ;
F_24 ( V_2 , 0x12 , 0x04 , 0x04 ) ;
break;
case V_67 :
F_24 ( V_2 , V_163 ,
V_216 ? V_222 : V_223 ,
V_224 ) ;
F_24 ( V_2 , 0x13 , 0x00 , 0x20 ) ;
F_24 ( V_2 , V_225 , V_226 ,
V_226 ) ;
if ( V_216 ) {
V_217 = 164 ;
V_218 = 28 ;
V_219 = 14 ;
V_220 = 494 ;
} else {
V_217 = 158 ;
V_218 = 14 ;
V_219 = 10 ;
V_220 = 490 ;
}
F_20 ( V_2 , V_117 , V_217 >> 3 ) ;
F_20 ( V_2 , V_118 , V_218 >> 3 ) ;
V_1 = F_22 ( V_2 , V_119 ) ;
V_1 = ( V_1 & 0xc0 ) | ( ( V_218 & 0x7 ) << 3 ) | ( V_217 & 0x07 ) ;
F_16 ( 10 ) ;
F_20 ( V_2 , V_119 , V_1 ) ;
F_20 ( V_2 , V_120 , V_219 >> 2 ) ;
F_20 ( V_2 , V_121 , V_220 >> 2 ) ;
V_1 = F_22 ( V_2 , V_122 ) ;
V_1 = ( V_1 & 0xc0 ) | ( ( V_220 & 0x3 ) << 2 ) | ( V_219 & 0x03 ) ;
F_16 ( 10 ) ;
F_20 ( V_2 , V_122 , V_1 ) ;
break;
case V_76 :
F_24 ( V_2 , 0x14 , V_216 ? 0x20 : 0x00 , 0x20 ) ;
F_24 ( V_2 , 0x13 , 0x00 , 0x20 ) ;
F_24 ( V_2 , 0x12 , 0x04 , 0x06 ) ;
break;
case V_75 :
case V_77 :
F_24 ( V_2 , 0x14 , V_216 ? 0x20 : 0x00 , 0x20 ) ;
F_24 ( V_2 , 0x12 , 0x04 , 0x06 ) ;
break;
case V_62 : {
const struct V_56 * V_227 ;
static const struct V_56 V_228 [] = {
{ 0x11 , 0x80 } , { 0x14 , 0x3e } , { 0x24 , 0x85 } , { 0x25 , 0x75 }
} ;
static const struct V_56 V_229 [] = {
{ 0x11 , 0x81 } , { 0x14 , 0x3e } , { 0x24 , 0x85 } , { 0x25 , 0x75 }
} ;
static const struct V_56 V_230 [] = {
{ 0x11 , 0x81 } , { 0x14 , 0x7e } , { 0x24 , 0x70 } , { 0x25 , 0x60 }
} ;
static const struct V_56 V_231 [] = {
{ 0x11 , 0x83 } , { 0x14 , 0x3e } , { 0x24 , 0x80 } , { 0x25 , 0x70 }
} ;
F_24 ( V_2 , 0x12 , V_216 ? 0x40 : 0x00 , 0x40 ) ;
if ( V_216 )
V_227 = V_2 -> V_126 < 30 ? V_231 : V_230 ;
else
V_227 = V_2 -> V_126 < 15 ? V_229 : V_228 ;
F_30 ( V_2 , V_227 , F_40 ( V_228 ) ) ;
return;
}
default:
return;
}
F_20 ( V_2 , 0x11 , V_2 -> V_202 ) ;
}
static void F_59 ( struct V_7 * V_7 , T_4 V_232 , T_4 V_233 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
if ( V_2 -> V_7 . V_234 )
F_2 ( V_2 , V_42 , 0x0f ) ;
F_24 ( V_2 , V_235 ,
V_236 * V_232 | V_237 * V_233 ,
V_236 | V_237 ) ;
if ( V_2 -> V_7 . V_234 )
F_2 ( V_2 , V_42 , 0x00 ) ;
}
static void F_60 ( struct V_2 * V_2 )
{
struct V_7 * V_7 ;
int V_216 , V_238 ;
int V_239 , V_240 , V_241 , V_242 , V_243 , V_244 ;
switch ( V_2 -> V_59 ) {
case V_60 :
case V_61 :
case V_63 :
case V_67 :
case V_62 :
F_58 ( V_2 ) ;
return;
case V_73 :
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
return;
}
V_7 = & V_2 -> V_7 ;
V_216 = V_7 -> V_130 . V_134 [ V_7 -> V_123 ] . V_209 & 1 ;
V_238 = V_7 -> V_130 . V_134 [ V_7 -> V_123 ] . V_209 & 2 ;
switch ( V_2 -> V_59 ) {
case V_66 :
V_239 = 0x1e ;
V_240 = 0x1e ;
V_241 = 0x02 ;
V_242 = 0x02 ;
break;
case V_68 :
case V_70 :
V_239 = 0x38 ;
V_240 = 0x3a ;
V_241 = V_242 = 0x05 ;
break;
case V_76 :
case V_75 :
case V_77 :
V_239 = 0x38 ;
V_240 = 0x3a ;
V_241 = 0x05 ;
V_242 = 0x06 ;
if ( V_2 -> V_59 == V_77 && V_216 )
V_239 ++ ;
if ( V_238 ) {
V_239 += 8 ;
V_240 += 8 ;
V_241 += 11 ;
V_242 += 11 ;
}
break;
case V_74 :
case V_69 :
V_239 = 0x2f ;
V_240 = 0x2f ;
V_241 = V_242 = 0x05 ;
break;
case V_71 :
case V_72 :
V_239 = 0x1a ;
V_240 = 0x1a ;
V_241 = V_242 = 0x03 ;
break;
default:
return;
}
switch ( V_2 -> V_59 ) {
case V_76 :
case V_75 :
case V_77 :
if ( V_216 ) {
V_243 = 0 ;
V_244 = 0 ;
} else {
V_243 = 1 ;
V_244 = 1 ;
}
break;
case V_66 :
if ( V_216 ) {
V_243 = 1 ;
V_244 = 1 ;
} else {
V_243 = 2 ;
V_244 = 2 ;
}
break;
default:
if ( V_216 ) {
V_243 = 1 ;
V_244 = 0 ;
} else {
V_243 = 2 ;
V_244 = 1 ;
}
}
F_58 ( V_2 ) ;
F_20 ( V_2 , 0x17 , V_239 ) ;
F_20 ( V_2 , 0x18 , V_240 + ( V_2 -> V_245 >> V_243 ) ) ;
F_20 ( V_2 , 0x19 , V_241 ) ;
F_20 ( V_2 , 0x1a , V_242 + ( V_2 -> V_246 >> V_244 ) ) ;
}
static int F_61 ( struct V_7 * V_7 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
V_2 -> V_245 = V_2 -> V_7 . V_172 ;
V_2 -> V_246 = V_2 -> V_7 . V_192 ;
switch ( V_2 -> V_9 ) {
case V_10 :
case V_11 :
F_52 ( V_2 ) ;
break;
case V_36 :
case V_37 :
F_56 ( V_2 ) ;
break;
case V_38 :
F_57 ( V_2 ) ;
break;
case V_13 :
F_62 ( V_2 ) ;
break;
}
F_60 ( V_2 ) ;
V_2 -> V_84 = 1 ;
F_37 ( V_7 ) ;
V_2 -> V_247 = 3 ;
F_26 ( V_2 ) ;
F_36 ( V_2 , 1 ) ;
return V_7 -> V_8 ;
}
static void F_63 ( struct V_7 * V_7 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
F_25 ( V_2 ) ;
F_36 ( V_2 , 0 ) ;
}
static void F_64 ( struct V_7 * V_7 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
if ( ! V_2 -> V_7 . V_248 )
return;
if ( V_2 -> V_9 == V_13 )
F_65 ( V_2 ) ;
#if F_66 ( V_249 ) || F_66 ( V_250 )
if ( V_2 -> V_251 ) {
F_67 ( V_7 -> V_252 , V_253 , 0 ) ;
F_68 ( V_7 -> V_252 ) ;
V_2 -> V_251 = 0 ;
}
#endif
if ( V_2 -> V_9 == V_38 )
F_2 ( V_2 , V_165 , 0x23 ) ;
}
static void F_69 ( struct V_7 * V_7 , T_2 V_254 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
if ( V_2 -> V_251 != V_254 ) {
#if F_66 ( V_249 ) || F_66 ( V_250 )
F_67 ( V_7 -> V_252 , V_253 , V_254 ) ;
F_68 ( V_7 -> V_252 ) ;
#endif
if ( V_254 )
V_2 -> V_84 = 1 ;
V_2 -> V_251 = V_254 ;
} else {
switch ( V_2 -> V_9 ) {
case V_10 :
case V_11 :
case V_38 :
if ( V_254 )
V_2 -> V_84 = 1 ;
break;
}
}
}
static void F_70 ( struct V_7 * V_7 ,
T_2 * V_255 ,
int V_256 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
if ( ! ( V_255 [ 0 ] | V_255 [ 1 ] | V_255 [ 2 ] | V_255 [ 3 ] | V_255 [ 4 ] | V_255 [ 5 ] | V_255 [ 6 ] | V_255 [ 7 ] ) &&
( V_255 [ 8 ] & 0x08 ) ) {
F_69 ( V_7 , ( V_255 [ 8 ] >> 2 ) & 1 ) ;
if ( V_255 [ 8 ] & 0x80 ) {
if ( ( V_255 [ 9 ] + 1 ) * 8 != V_7 -> V_172 ||
( V_255 [ 10 ] + 1 ) * 8 != V_7 -> V_192 ) {
F_3 ( V_65 , L_61
L_62 ,
( V_255 [ 9 ] + 1 ) * 8 , ( V_255 [ 10 ] + 1 ) * 8 ,
V_7 -> V_172 , V_7 -> V_192 ) ;
V_7 -> V_257 = V_258 ;
return;
}
F_71 ( V_7 , V_259 , V_255 , 11 ) ;
return;
} else {
F_71 ( V_7 , V_260 , V_255 , 0 ) ;
V_2 -> V_261 = 0 ;
}
}
V_256 -- ;
F_71 ( V_7 , V_262 , V_255 , V_256 ) ;
}
static void F_72 ( struct V_7 * V_7 ,
T_2 * V_263 ,
int V_256 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
if ( ( ! ( V_263 [ 0 ] | V_263 [ 1 ] | V_263 [ 2 ] | V_263 [ 3 ] | V_263 [ 5 ] ) ) && V_263 [ 6 ] ) {
F_69 ( V_7 , ( V_263 [ 6 ] >> 1 ) & 1 ) ;
F_71 ( V_7 , V_259 , NULL , 0 ) ;
F_71 ( V_7 , V_260 , NULL , 0 ) ;
V_2 -> V_261 = 0 ;
}
if ( V_7 -> V_257 == V_258 )
return;
if ( V_256 & 7 ) {
V_256 -- ;
if ( V_2 -> V_261 == V_263 [ V_256 ] )
V_2 -> V_261 ++ ;
else if ( V_2 -> V_261 == 0 || V_263 [ V_256 ] ) {
F_3 ( V_65 , L_63 ,
( int ) V_263 [ V_256 ] , ( int ) V_2 -> V_261 ) ;
V_7 -> V_257 = V_258 ;
return;
}
}
F_71 ( V_7 , V_262 , V_263 , V_256 ) ;
}
static void F_73 ( struct V_7 * V_7 ,
T_2 * V_263 ,
int V_256 )
{
if ( V_263 [ 0 ] == 0xff && V_263 [ 1 ] == 0xff && V_263 [ 2 ] == 0xff ) {
switch ( V_263 [ 3 ] ) {
case 0x50 :
#define F_74 16
V_263 += F_74 ;
V_256 -= F_74 ;
#undef F_74
if ( V_263 [ 0 ] == 0xff || V_263 [ 1 ] == 0xd8 )
F_71 ( V_7 , V_260 ,
V_263 , V_256 ) ;
else
V_7 -> V_257 = V_258 ;
return;
case 0x51 :
F_69 ( V_7 , V_263 [ 11 ] & 1 ) ;
if ( V_263 [ 9 ] != 0 )
V_7 -> V_257 = V_258 ;
F_71 ( V_7 , V_259 ,
NULL , 0 ) ;
return;
}
}
F_71 ( V_7 , V_262 , V_263 , V_256 ) ;
}
static void F_75 ( struct V_7 * V_7 ,
T_2 * V_263 ,
int V_256 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
F_71 ( V_7 , V_262 , V_263 , V_256 ) ;
if ( V_256 < V_7 -> V_130 . V_139 ) {
if ( V_2 -> V_247 ) {
V_2 -> V_247 -- ;
if ( V_7 -> V_264 <
V_2 -> V_7 . V_172 * V_2 -> V_7 . V_192 )
V_7 -> V_257 = V_258 ;
}
F_71 ( V_7 , V_259 , NULL , 0 ) ;
F_71 ( V_7 , V_260 , NULL , 0 ) ;
}
}
static void F_76 ( struct V_7 * V_7 ,
T_2 * V_263 ,
int V_256 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
switch ( V_2 -> V_9 ) {
case V_10 :
case V_11 :
F_70 ( V_7 , V_263 , V_256 ) ;
break;
case V_36 :
case V_37 :
F_72 ( V_7 , V_263 , V_256 ) ;
break;
case V_38 :
F_73 ( V_7 , V_263 , V_256 ) ;
break;
case V_12 :
F_75 ( V_7 , V_263 , V_256 ) ;
break;
case V_13 :
F_77 ( V_7 , V_263 , V_256 ) ;
break;
}
}
static void F_78 ( struct V_7 * V_7 , T_4 V_55 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
static const struct V_56 V_265 [] [ 7 ] = {
{ { 0x0f , 0x6a } , { 0x24 , 0x40 } , { 0x25 , 0x2b } , { 0x26 , 0x90 } ,
{ 0x27 , 0xe0 } , { 0x28 , 0xe0 } , { 0x2c , 0xe0 } } ,
{ { 0x0f , 0x6a } , { 0x24 , 0x50 } , { 0x25 , 0x40 } , { 0x26 , 0xa1 } ,
{ 0x27 , 0xc0 } , { 0x28 , 0xc0 } , { 0x2c , 0xc0 } } ,
{ { 0x0f , 0x6a } , { 0x24 , 0x68 } , { 0x25 , 0x58 } , { 0x26 , 0xc2 } ,
{ 0x27 , 0xa0 } , { 0x28 , 0xa0 } , { 0x2c , 0xa0 } } ,
{ { 0x0f , 0x6a } , { 0x24 , 0x70 } , { 0x25 , 0x68 } , { 0x26 , 0xd3 } ,
{ 0x27 , 0x80 } , { 0x28 , 0x80 } , { 0x2c , 0x80 } } ,
{ { 0x0f , 0x6a } , { 0x24 , 0x80 } , { 0x25 , 0x70 } , { 0x26 , 0xd3 } ,
{ 0x27 , 0x20 } , { 0x28 , 0x20 } , { 0x2c , 0x20 } } ,
{ { 0x0f , 0x6a } , { 0x24 , 0x88 } , { 0x25 , 0x78 } , { 0x26 , 0xd3 } ,
{ 0x27 , 0x40 } , { 0x28 , 0x40 } , { 0x2c , 0x40 } } ,
{ { 0x0f , 0x6a } , { 0x24 , 0x90 } , { 0x25 , 0x80 } , { 0x26 , 0xd4 } ,
{ 0x27 , 0x60 } , { 0x28 , 0x60 } , { 0x2c , 0x60 } }
} ;
switch ( V_2 -> V_59 ) {
case V_66 :
case V_68 :
case V_70 :
case V_76 :
case V_75 :
case V_77 :
case V_71 :
case V_72 :
F_20 ( V_2 , V_266 , V_55 ) ;
break;
case V_74 :
case V_69 :
F_20 ( V_2 , V_266 , V_55 ) ;
break;
case V_73 :
F_30 ( V_2 , V_265 [ V_55 ] ,
F_40 ( V_265 [ 0 ] ) ) ;
break;
case V_67 :
F_20 ( V_2 , V_267 , F_1 ( V_55 ) ) ;
break;
}
}
static void F_79 ( struct V_7 * V_7 , T_4 V_55 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
static const struct V_56 V_268 [] [ 31 ] = {
{ { 0x6c , 0xf0 } , { 0x6d , 0xf0 } , { 0x6e , 0xf8 } , { 0x6f , 0xa0 } ,
{ 0x70 , 0x58 } , { 0x71 , 0x38 } , { 0x72 , 0x30 } , { 0x73 , 0x30 } ,
{ 0x74 , 0x28 } , { 0x75 , 0x28 } , { 0x76 , 0x24 } , { 0x77 , 0x24 } ,
{ 0x78 , 0x22 } , { 0x79 , 0x28 } , { 0x7a , 0x2a } , { 0x7b , 0x34 } ,
{ 0x7c , 0x0f } , { 0x7d , 0x1e } , { 0x7e , 0x3d } , { 0x7f , 0x65 } ,
{ 0x80 , 0x70 } , { 0x81 , 0x77 } , { 0x82 , 0x7d } , { 0x83 , 0x83 } ,
{ 0x84 , 0x88 } , { 0x85 , 0x8d } , { 0x86 , 0x96 } , { 0x87 , 0x9f } ,
{ 0x88 , 0xb0 } , { 0x89 , 0xc4 } , { 0x8a , 0xd9 } } ,
{ { 0x6c , 0xf0 } , { 0x6d , 0xf0 } , { 0x6e , 0xf8 } , { 0x6f , 0x94 } ,
{ 0x70 , 0x58 } , { 0x71 , 0x40 } , { 0x72 , 0x30 } , { 0x73 , 0x30 } ,
{ 0x74 , 0x30 } , { 0x75 , 0x30 } , { 0x76 , 0x2c } , { 0x77 , 0x24 } ,
{ 0x78 , 0x22 } , { 0x79 , 0x28 } , { 0x7a , 0x2a } , { 0x7b , 0x31 } ,
{ 0x7c , 0x0f } , { 0x7d , 0x1e } , { 0x7e , 0x3d } , { 0x7f , 0x62 } ,
{ 0x80 , 0x6d } , { 0x81 , 0x75 } , { 0x82 , 0x7b } , { 0x83 , 0x81 } ,
{ 0x84 , 0x87 } , { 0x85 , 0x8d } , { 0x86 , 0x98 } , { 0x87 , 0xa1 } ,
{ 0x88 , 0xb2 } , { 0x89 , 0xc6 } , { 0x8a , 0xdb } } ,
{ { 0x6c , 0xf0 } , { 0x6d , 0xf0 } , { 0x6e , 0xf0 } , { 0x6f , 0x84 } ,
{ 0x70 , 0x58 } , { 0x71 , 0x48 } , { 0x72 , 0x40 } , { 0x73 , 0x40 } ,
{ 0x74 , 0x28 } , { 0x75 , 0x28 } , { 0x76 , 0x28 } , { 0x77 , 0x24 } ,
{ 0x78 , 0x26 } , { 0x79 , 0x28 } , { 0x7a , 0x28 } , { 0x7b , 0x34 } ,
{ 0x7c , 0x0f } , { 0x7d , 0x1e } , { 0x7e , 0x3c } , { 0x7f , 0x5d } ,
{ 0x80 , 0x68 } , { 0x81 , 0x71 } , { 0x82 , 0x79 } , { 0x83 , 0x81 } ,
{ 0x84 , 0x86 } , { 0x85 , 0x8b } , { 0x86 , 0x95 } , { 0x87 , 0x9e } ,
{ 0x88 , 0xb1 } , { 0x89 , 0xc5 } , { 0x8a , 0xd9 } } ,
{ { 0x6c , 0xf0 } , { 0x6d , 0xf0 } , { 0x6e , 0xf0 } , { 0x6f , 0x70 } ,
{ 0x70 , 0x58 } , { 0x71 , 0x58 } , { 0x72 , 0x48 } , { 0x73 , 0x48 } ,
{ 0x74 , 0x38 } , { 0x75 , 0x40 } , { 0x76 , 0x34 } , { 0x77 , 0x34 } ,
{ 0x78 , 0x2e } , { 0x79 , 0x28 } , { 0x7a , 0x24 } , { 0x7b , 0x22 } ,
{ 0x7c , 0x0f } , { 0x7d , 0x1e } , { 0x7e , 0x3c } , { 0x7f , 0x58 } ,
{ 0x80 , 0x63 } , { 0x81 , 0x6e } , { 0x82 , 0x77 } , { 0x83 , 0x80 } ,
{ 0x84 , 0x87 } , { 0x85 , 0x8f } , { 0x86 , 0x9c } , { 0x87 , 0xa9 } ,
{ 0x88 , 0xc0 } , { 0x89 , 0xd4 } , { 0x8a , 0xe6 } } ,
{ { 0x6c , 0xa0 } , { 0x6d , 0xf0 } , { 0x6e , 0x90 } , { 0x6f , 0x80 } ,
{ 0x70 , 0x70 } , { 0x71 , 0x80 } , { 0x72 , 0x60 } , { 0x73 , 0x60 } ,
{ 0x74 , 0x58 } , { 0x75 , 0x60 } , { 0x76 , 0x4c } , { 0x77 , 0x38 } ,
{ 0x78 , 0x38 } , { 0x79 , 0x2a } , { 0x7a , 0x20 } , { 0x7b , 0x0e } ,
{ 0x7c , 0x0a } , { 0x7d , 0x14 } , { 0x7e , 0x26 } , { 0x7f , 0x46 } ,
{ 0x80 , 0x54 } , { 0x81 , 0x64 } , { 0x82 , 0x70 } , { 0x83 , 0x7c } ,
{ 0x84 , 0x87 } , { 0x85 , 0x93 } , { 0x86 , 0xa6 } , { 0x87 , 0xb4 } ,
{ 0x88 , 0xd0 } , { 0x89 , 0xe5 } , { 0x8a , 0xf5 } } ,
{ { 0x6c , 0x60 } , { 0x6d , 0x80 } , { 0x6e , 0x60 } , { 0x6f , 0x80 } ,
{ 0x70 , 0x80 } , { 0x71 , 0x80 } , { 0x72 , 0x88 } , { 0x73 , 0x30 } ,
{ 0x74 , 0x70 } , { 0x75 , 0x68 } , { 0x76 , 0x64 } , { 0x77 , 0x50 } ,
{ 0x78 , 0x3c } , { 0x79 , 0x22 } , { 0x7a , 0x10 } , { 0x7b , 0x08 } ,
{ 0x7c , 0x06 } , { 0x7d , 0x0e } , { 0x7e , 0x1a } , { 0x7f , 0x3a } ,
{ 0x80 , 0x4a } , { 0x81 , 0x5a } , { 0x82 , 0x6b } , { 0x83 , 0x7b } ,
{ 0x84 , 0x89 } , { 0x85 , 0x96 } , { 0x86 , 0xaf } , { 0x87 , 0xc3 } ,
{ 0x88 , 0xe1 } , { 0x89 , 0xf2 } , { 0x8a , 0xfa } } ,
{ { 0x6c , 0x20 } , { 0x6d , 0x40 } , { 0x6e , 0x20 } , { 0x6f , 0x60 } ,
{ 0x70 , 0x88 } , { 0x71 , 0xc8 } , { 0x72 , 0xc0 } , { 0x73 , 0xb8 } ,
{ 0x74 , 0xa8 } , { 0x75 , 0xb8 } , { 0x76 , 0x80 } , { 0x77 , 0x5c } ,
{ 0x78 , 0x26 } , { 0x79 , 0x10 } , { 0x7a , 0x08 } , { 0x7b , 0x04 } ,
{ 0x7c , 0x02 } , { 0x7d , 0x06 } , { 0x7e , 0x0a } , { 0x7f , 0x22 } ,
{ 0x80 , 0x33 } , { 0x81 , 0x4c } , { 0x82 , 0x64 } , { 0x83 , 0x7b } ,
{ 0x84 , 0x90 } , { 0x85 , 0xa7 } , { 0x86 , 0xc7 } , { 0x87 , 0xde } ,
{ 0x88 , 0xf1 } , { 0x89 , 0xf9 } , { 0x8a , 0xfd } } ,
} ;
switch ( V_2 -> V_59 ) {
case V_68 :
case V_76 :
F_20 ( V_2 , V_269 , V_55 ) ;
break;
case V_75 :
case V_77 :
F_24 ( V_2 , V_269 , V_55 >> 4 , 0x0f ) ;
break;
case V_66 : {
static const T_2 V_270 [] = {
0x03 , 0x09 , 0x0b , 0x0f , 0x53 , 0x6f , 0x35 , 0x7f
} ;
F_20 ( V_2 , 0x64 , V_270 [ V_55 >> 5 ] ) ;
break;
}
case V_74 :
case V_69 : {
static const T_2 V_270 [] = {
0x01 , 0x05 , 0x09 , 0x11 , 0x15 , 0x35 , 0x37 , 0x57 ,
0x5b , 0xa5 , 0xa7 , 0xc7 , 0xc9 , 0xcf , 0xef , 0xff
} ;
F_20 ( V_2 , 0x64 , V_270 [ V_55 >> 4 ] ) ;
break;
}
case V_73 :
F_30 ( V_2 , V_268 [ V_55 ] ,
F_40 ( V_268 [ 0 ] ) ) ;
break;
case V_67 :
F_20 ( V_2 , V_271 , V_55 >> 1 ) ;
break;
}
}
static void F_80 ( struct V_7 * V_7 , T_4 V_55 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
F_20 ( V_2 , 0x10 , V_55 ) ;
}
static void F_81 ( struct V_7 * V_7 , T_4 V_55 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
static const struct V_56 V_272 [] [ 6 ] = {
{ { 0x4f , 0x28 } , { 0x50 , 0x2a } , { 0x51 , 0x02 } , { 0x52 , 0x0a } ,
{ 0x53 , 0x19 } , { 0x54 , 0x23 } } ,
{ { 0x4f , 0x47 } , { 0x50 , 0x4a } , { 0x51 , 0x03 } , { 0x52 , 0x11 } ,
{ 0x53 , 0x2c } , { 0x54 , 0x3e } } ,
{ { 0x4f , 0x66 } , { 0x50 , 0x6b } , { 0x51 , 0x05 } , { 0x52 , 0x19 } ,
{ 0x53 , 0x40 } , { 0x54 , 0x59 } } ,
{ { 0x4f , 0x84 } , { 0x50 , 0x8b } , { 0x51 , 0x06 } , { 0x52 , 0x20 } ,
{ 0x53 , 0x53 } , { 0x54 , 0x73 } } ,
{ { 0x4f , 0xa3 } , { 0x50 , 0xab } , { 0x51 , 0x08 } , { 0x52 , 0x28 } ,
{ 0x53 , 0x66 } , { 0x54 , 0x8e } } ,
} ;
switch ( V_2 -> V_59 ) {
case V_66 :
case V_68 :
case V_70 :
case V_76 :
case V_75 :
case V_77 :
F_20 ( V_2 , V_273 , V_55 ) ;
break;
case V_74 :
case V_69 :
F_20 ( V_2 , V_273 , V_55 ) ;
break;
case V_71 :
case V_72 :
F_20 ( V_2 , V_273 , V_55 & 0xf0 ) ;
break;
case V_73 :
F_30 ( V_2 , V_272 [ V_55 ] ,
F_40 ( V_272 [ 0 ] ) ) ;
break;
case V_67 :
break;
}
}
static void F_82 ( struct V_7 * V_7 , T_4 V_55 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
F_24 ( V_2 , 0x2d , V_55 ? 0x10 : 0x00 , 0x10 ) ;
}
static void F_83 ( struct V_2 * V_2 , T_4 V_55 )
{
if ( V_2 -> V_59 == V_73
|| V_2 -> V_59 == V_67 ) {
switch ( V_55 ) {
case 0 :
F_24 ( V_2 , V_225 , 0 , V_274 ) ;
break;
case 1 :
F_24 ( V_2 , V_225 , V_274 ,
V_274 ) ;
F_24 ( V_2 , V_275 , 0x08 , 0x18 ) ;
break;
case 2 :
F_24 ( V_2 , V_225 , V_274 ,
V_274 ) ;
F_24 ( V_2 , V_275 , 0x00 , 0x18 ) ;
break;
case 3 :
F_24 ( V_2 , V_225 , V_274 ,
V_274 ) ;
F_24 ( V_2 , V_275 , V_276 ,
0x18 ) ;
break;
}
} else {
switch ( V_55 ) {
case 0 :
F_24 ( V_2 , 0x2d , 0x00 , 0x04 ) ;
F_24 ( V_2 , 0x2a , 0x00 , 0x80 ) ;
break;
case 1 :
F_24 ( V_2 , 0x2d , 0x04 , 0x04 ) ;
F_24 ( V_2 , 0x2a , 0x80 , 0x80 ) ;
if ( V_2 -> V_59 == V_76 ||
V_2 -> V_59 == V_75 ||
V_2 -> V_59 == V_77 )
F_20 ( V_2 , 0x2b , 0x5e ) ;
else
F_20 ( V_2 , 0x2b , 0xac ) ;
break;
case 2 :
F_24 ( V_2 , 0x2d , 0x04 , 0x04 ) ;
if ( V_2 -> V_59 == V_76 ||
V_2 -> V_59 == V_75 ||
V_2 -> V_59 == V_77 ) {
F_24 ( V_2 , 0x2a , 0x80 , 0x80 ) ;
F_20 ( V_2 , 0x2b , 0xa8 ) ;
} else {
F_24 ( V_2 , 0x2a , 0x00 , 0x80 ) ;
}
break;
}
}
}
static void F_84 ( struct V_7 * V_7 , T_4 V_55 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
F_83 ( V_2 , V_55 ) ;
if ( V_2 -> V_9 == V_13 )
F_85 ( V_2 ) ;
}
static int F_86 ( struct V_7 * V_7 ,
struct V_277 * V_278 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
if ( V_2 -> V_9 != V_13 )
return - V_279 ;
memset ( V_278 , 0 , sizeof *V_278 ) ;
V_278 -> V_280 = F_87 ( V_2 -> V_281 ) ;
V_278 -> V_282 = V_283 | V_284 |
V_285 ;
return 0 ;
}
static int F_88 ( struct V_7 * V_7 ,
const struct V_277 * V_278 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
if ( V_2 -> V_9 != V_13 )
return - V_279 ;
F_89 ( V_2 -> V_281 , V_278 -> V_280 ) ;
return 0 ;
}
static int F_90 ( struct V_286 * V_287 )
{
struct V_7 * V_7 =
F_91 ( V_287 -> V_288 , struct V_7 , V_289 ) ;
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
V_7 -> V_8 = 0 ;
switch ( V_287 -> V_129 ) {
case V_290 :
V_7 -> V_291 -> V_55 = F_22 ( V_2 , 0x10 ) ;
break;
}
return 0 ;
}
static int F_92 ( struct V_286 * V_287 )
{
struct V_7 * V_7 =
F_91 ( V_287 -> V_288 , struct V_7 , V_289 ) ;
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
V_7 -> V_8 = 0 ;
if ( ! V_7 -> V_234 )
return 0 ;
switch ( V_287 -> V_129 ) {
case V_292 :
F_78 ( V_7 , V_287 -> V_55 ) ;
break;
case V_293 :
F_79 ( V_7 , V_287 -> V_55 ) ;
break;
case V_294 :
F_84 ( V_7 , V_287 -> V_55 ) ;
break;
case V_295 :
if ( V_287 -> V_296 )
F_82 ( V_7 , V_287 -> V_55 ) ;
if ( ! V_287 -> V_55 && V_2 -> V_297 -> V_296 )
F_78 ( V_7 , V_2 -> V_297 -> V_55 ) ;
break;
case V_298 :
F_81 ( V_7 , V_287 -> V_55 ) ;
break;
case V_299 :
F_59 ( V_7 , V_287 -> V_55 , V_2 -> V_233 -> V_55 ) ;
break;
case V_290 :
if ( V_287 -> V_296 )
F_46 ( V_7 , V_287 -> V_55 ) ;
if ( ! V_287 -> V_55 && V_7 -> V_291 -> V_296 )
F_80 ( V_7 , V_7 -> V_291 -> V_55 ) ;
break;
case V_300 :
return - V_301 ;
}
return V_7 -> V_8 ;
}
static int F_93 ( struct V_7 * V_7 )
{
struct V_2 * V_2 = (struct V_2 * ) V_7 ;
struct V_302 * V_303 = & V_7 -> V_289 ;
V_7 -> V_304 . V_289 = V_303 ;
F_94 ( V_303 , 10 ) ;
if ( V_305 [ V_2 -> V_59 ] . V_306 )
V_2 -> V_297 = F_95 ( V_303 , & V_307 ,
V_292 , 0 ,
V_2 -> V_59 == V_73 ? 6 : 255 , 1 ,
V_2 -> V_59 == V_73 ? 3 : 127 ) ;
if ( V_305 [ V_2 -> V_59 ] . V_308 ) {
if ( V_2 -> V_59 == V_73 )
F_95 ( V_303 , & V_307 ,
V_293 , 0 , 6 , 1 , 3 ) ;
else
F_95 ( V_303 , & V_307 ,
V_293 , 0 , 255 , 1 ,
( V_2 -> V_59 == V_75 ||
V_2 -> V_59 == V_77 ) ? 200 : 127 ) ;
}
if ( V_305 [ V_2 -> V_59 ] . V_309 )
F_95 ( V_303 , & V_307 ,
V_298 , 0 ,
V_2 -> V_59 == V_73 ? 4 : 255 , 1 ,
V_2 -> V_59 == V_73 ? 2 : 127 ) ;
if ( V_305 [ V_2 -> V_59 ] . V_310 )
V_7 -> V_291 = F_95 ( V_303 , & V_307 ,
V_311 , 0 , 255 , 1 , 127 ) ;
if ( V_305 [ V_2 -> V_59 ] . V_312 ) {
V_2 -> V_232 = F_95 ( V_303 , & V_307 ,
V_299 , 0 , 1 , 1 , 0 ) ;
V_2 -> V_233 = F_95 ( V_303 , & V_307 ,
V_313 , 0 , 1 , 1 , 0 ) ;
}
if ( V_305 [ V_2 -> V_59 ] . V_314 )
V_2 -> V_315 = F_95 ( V_303 , & V_307 ,
V_295 , 0 , 1 , 1 , 1 ) ;
if ( V_305 [ V_2 -> V_59 ] . V_316 )
V_7 -> V_317 = F_95 ( V_303 , & V_307 ,
V_290 , 0 , 1 , 1 , 1 ) ;
if ( V_305 [ V_2 -> V_59 ] . V_318 ) {
if ( V_2 -> V_59 == V_67 )
V_2 -> V_319 = F_96 ( V_303 , & V_307 ,
V_294 ,
V_320 , 0 ,
V_320 ) ;
else
V_2 -> V_319 = F_96 ( V_303 , & V_307 ,
V_294 ,
V_321 , 0 , 0 ) ;
}
if ( V_2 -> V_9 == V_13 )
V_2 -> V_281 = F_95 ( V_303 , & V_307 ,
V_300 ,
V_322 , V_323 , 1 , V_324 ) ;
if ( V_303 -> error ) {
F_6 ( L_64 ) ;
return V_303 -> error ;
}
if ( V_7 -> V_317 )
F_97 ( 3 , & V_7 -> V_317 , 0 , true ) ;
if ( V_2 -> V_315 )
F_97 ( 2 , & V_2 -> V_315 , 0 , false ) ;
if ( V_2 -> V_232 )
F_98 ( 2 , & V_2 -> V_232 ) ;
return 0 ;
}
static int F_99 ( struct V_181 * V_182 ,
const struct V_128 * V_129 )
{
return F_100 ( V_182 , V_129 , & V_325 , sizeof( struct V_2 ) ,
V_326 ) ;
}
