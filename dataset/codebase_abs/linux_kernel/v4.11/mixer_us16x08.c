static int F_1 ( struct V_1 * V_2 ,
unsigned char * V_3 , int V_4 )
{
F_2 ( & V_2 -> V_5 ) ;
F_3 ( V_2 -> V_6 ,
F_4 ( V_2 -> V_6 , 0 ) ,
V_7 ,
V_8 , 0 , 0 , V_3 , V_4 ) ;
F_5 ( & V_2 -> V_5 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , char * V_3 , int V_4 )
{
return F_3 ( V_2 -> V_6 , F_7 ( V_2 -> V_6 , 0 ) ,
V_9 , V_10 ,
0 , 0 , V_3 , V_4 ) ;
}
static int F_8 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
return F_9 ( V_14 , 1 , 10 , V_15 ) ;
}
static int F_10 ( struct V_11 * V_12 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_12 -> V_20 ;
int V_21 = V_17 -> V_22 . V_21 ;
V_17 -> V_23 . V_24 . V_25 [ 0 ] = V_19 -> V_26 [ V_21 ] ;
return 0 ;
}
static int F_11 ( struct V_11 * V_12 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_12 -> V_20 ;
struct V_1 * V_2 = V_19 -> V_27 . V_28 -> V_2 ;
int V_21 = V_17 -> V_22 . V_21 ;
char V_3 [ sizeof( V_29 ) ] ;
int V_30 , V_31 , V_32 ;
V_30 = V_17 -> V_23 . V_24 . V_25 [ 0 ] ;
if ( V_30 < 0 || V_30 > 9 )
return - V_33 ;
memcpy ( V_3 , V_29 , sizeof( V_29 ) ) ;
if ( V_30 < 2 ) {
V_31 = V_30 ;
V_3 [ 2 ] = 0x02 ;
} else {
V_3 [ 2 ] = 0x03 ;
V_31 = V_30 - 2 ;
}
V_3 [ 5 ] = ( unsigned char ) ( V_31 & 0x0f ) + 1 ;
V_3 [ 13 ] = V_21 + 1 ;
V_32 = F_6 ( V_2 , V_3 , sizeof( V_29 ) ) ;
if ( V_32 > 0 ) {
V_19 -> V_34 |= 1 << V_21 ;
V_19 -> V_26 [ V_21 ] = V_30 ;
} else {
F_12 ( V_2 , L_1 , V_32 ) ;
}
return V_32 > 0 ? 1 : 0 ;
}
static int F_13 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
V_14 -> V_35 = 1 ;
V_14 -> type = V_36 ;
V_14 -> V_23 . integer . V_37 = F_14 ( V_12 ) ;
V_14 -> V_23 . integer . V_38 = F_15 ( V_12 ) ;
V_14 -> V_23 . integer . V_39 = F_16 ( V_12 ) ;
return 0 ;
}
static int F_17 ( struct V_11 * V_12 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_12 -> V_20 ;
int V_21 = V_17 -> V_22 . V_21 ;
V_17 -> V_23 . integer . V_23 [ 0 ] = V_19 -> V_26 [ V_21 ] ;
return 0 ;
}
static int F_18 ( struct V_11 * V_12 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_12 -> V_20 ;
struct V_1 * V_2 = V_19 -> V_27 . V_28 -> V_2 ;
char V_3 [ sizeof( V_40 ) ] ;
int V_30 , V_32 ;
int V_21 = V_17 -> V_22 . V_21 ;
V_30 = V_17 -> V_23 . integer . V_23 [ 0 ] ;
if ( V_30 < F_15 ( V_12 )
|| V_30 > F_14 ( V_12 ) )
return - V_33 ;
memcpy ( V_3 , V_40 , sizeof( V_40 ) ) ;
V_3 [ 8 ] = V_30 - F_19 ( V_12 ) ;
V_3 [ 6 ] = V_19 -> V_27 . V_22 ;
V_3 [ 5 ] = V_21 + 1 ;
V_32 = F_6 ( V_2 , V_3 , sizeof( V_40 ) ) ;
if ( V_32 > 0 ) {
V_19 -> V_34 |= 1 << V_21 ;
V_19 -> V_26 [ V_21 ] = V_30 ;
} else {
F_12 ( V_2 , L_2 , V_32 ) ;
}
return V_32 > 0 ? 1 : 0 ;
}
static int F_20 ( struct V_11 * V_12 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_12 -> V_20 ;
struct V_1 * V_2 = V_19 -> V_27 . V_28 -> V_2 ;
char V_3 [ sizeof( V_40 ) ] ;
int V_30 , V_32 = 0 ;
V_30 = V_17 -> V_23 . integer . V_23 [ 0 ] ;
switch ( V_19 -> V_27 . V_22 ) {
case V_41 :
memcpy ( V_3 , V_42 , sizeof( V_42 ) ) ;
V_3 [ 2 ] = V_30 ;
V_32 = F_6 ( V_2 , V_3 , sizeof( V_42 ) ) ;
break;
case V_43 :
memcpy ( V_3 , V_44 , sizeof( V_44 ) ) ;
V_3 [ 2 ] = V_30 ;
V_32 = F_6 ( V_2 , V_3 , sizeof( V_44 ) ) ;
break;
case V_45 :
memcpy ( V_3 , V_40 , sizeof( V_40 ) ) ;
V_3 [ 8 ] = V_30 ;
V_3 [ 6 ] = V_19 -> V_27 . V_22 ;
V_3 [ 5 ] = 1 ;
V_32 = F_6 ( V_2 , V_3 , sizeof( V_40 ) ) ;
break;
}
if ( V_32 > 0 ) {
V_19 -> V_34 |= 1 ;
V_19 -> V_26 [ 0 ] = V_30 ;
} else {
F_12 ( V_2 , L_3 , V_32 ) ;
}
return V_32 > 0 ? 1 : 0 ;
}
static int F_21 ( struct V_11 * V_12 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_12 -> V_20 ;
switch ( V_19 -> V_27 . V_22 ) {
case V_43 :
V_17 -> V_23 . integer . V_23 [ 0 ] = V_19 -> V_26 [ 0 ] ;
break;
case V_41 :
V_17 -> V_23 . integer . V_23 [ 0 ] = V_19 -> V_26 [ 0 ] ;
break;
case V_45 :
V_17 -> V_23 . integer . V_23 [ 0 ] = V_19 -> V_26 [ 0 ] ;
break;
}
return 0 ;
}
static int F_22 ( struct V_11 * V_12 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_12 -> V_20 ;
int V_21 = V_17 -> V_22 . V_21 ;
V_17 -> V_23 . integer . V_23 [ 0 ] = V_19 -> V_26 [ V_21 ] ;
return 0 ;
}
static int F_23 ( struct V_11 * V_12 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_12 -> V_20 ;
struct V_1 * V_2 = V_19 -> V_27 . V_28 -> V_2 ;
char V_3 [ sizeof( V_46 ) ] ;
int V_30 , V_32 ;
int V_21 = V_17 -> V_22 . V_21 ;
V_30 = V_17 -> V_23 . integer . V_23 [ 0 ] ;
if ( V_30 < F_15 ( V_12 )
|| V_30 > F_14 ( V_12 ) )
return - V_33 ;
memcpy ( V_3 , V_46 , sizeof( V_46 ) ) ;
V_3 [ 8 ] = V_30 - F_19 ( V_12 ) ;
V_3 [ 6 ] = V_19 -> V_27 . V_22 ;
V_3 [ 5 ] = V_21 + 1 ;
V_32 = F_6 ( V_2 , V_3 , sizeof( V_46 ) ) ;
if ( V_32 > 0 ) {
V_19 -> V_34 |= 1 << V_21 ;
V_19 -> V_26 [ V_21 ] = V_30 ;
} else {
F_12 ( V_2 , L_4 , V_32 ) ;
}
return V_32 > 0 ? 1 : 0 ;
}
static int F_24 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
V_14 -> V_35 = 1 ;
V_14 -> type = V_36 ;
V_14 -> V_23 . integer . V_37 = F_14 ( V_12 ) ;
V_14 -> V_23 . integer . V_38 = F_15 ( V_12 ) ;
V_14 -> V_23 . integer . V_39 = F_16 ( V_12 ) ;
return 0 ;
}
static int F_25 ( struct V_11 * V_12 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_12 -> V_20 ;
struct V_47 * V_48 = V_19 -> V_20 ;
int V_21 = V_17 -> V_22 . V_21 ;
int V_49 = F_26 ( V_19 -> V_27 . V_22 ) ;
V_17 -> V_23 . integer . V_23 [ 0 ] = V_48 -> V_30 [ V_49 ] [ V_21 ] ;
return 0 ;
}
static int F_27 ( struct V_11 * V_12 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_12 -> V_20 ;
struct V_1 * V_2 = V_19 -> V_27 . V_28 -> V_2 ;
struct V_47 * V_48 = V_19 -> V_20 ;
int V_21 = V_17 -> V_22 . V_21 ;
char V_3 [ sizeof( V_50 ) ] ;
int V_49 , V_30 ;
int V_32 ;
V_30 = V_17 -> V_23 . integer . V_23 [ 0 ] ;
if ( V_30 < F_15 ( V_12 )
|| V_30 > F_14 ( V_12 ) )
return - V_33 ;
V_49 = V_19 -> V_27 . V_22 - V_51 ;
V_48 -> V_30 [ V_49 ] [ V_21 ] = V_17 -> V_23 . integer . V_23 [ 0 ] ;
memcpy ( V_3 , V_50 , sizeof( V_50 ) ) ;
V_3 [ 8 ] = V_48 -> V_30 [
F_26 ( V_52 ) ] [ V_21 ]
- V_53 ;
V_3 [ 11 ] = V_54 [ V_48 -> V_30 [
F_26 ( V_55 ) ] [ V_21 ] ] ;
V_3 [ 14 ] = V_48 -> V_30 [ F_26 ( V_56 ) ] [ V_21 ]
+ V_57 ;
V_3 [ 17 ] = V_48 -> V_30 [ F_26 ( V_58 ) ] [ V_21 ]
+ V_59 ;
V_3 [ 20 ] = V_48 -> V_30 [ F_26 ( V_60 ) ] [ V_21 ] ;
V_3 [ 26 ] = V_48 -> V_30 [ F_26 ( V_61 ) ] [ V_21 ] ;
V_3 [ 5 ] = V_21 + 1 ;
V_32 = F_6 ( V_2 , V_3 , sizeof( V_50 ) ) ;
if ( V_32 > 0 ) {
V_19 -> V_34 |= 1 << V_21 ;
V_19 -> V_26 [ V_21 ] = V_30 ;
} else {
F_12 ( V_2 , L_5 , V_32 ) ;
}
return 1 ;
}
static int F_28 ( struct V_11 * V_12 ,
struct V_16 * V_17 )
{
int V_30 ;
struct V_18 * V_19 = V_12 -> V_20 ;
struct V_62 * V_48 = V_19 -> V_20 ;
int V_21 = V_17 -> V_22 . V_21 ;
V_30 = V_48 -> V_30 [ F_29 ( V_19 -> V_27 . V_22 ) ]
[ F_30 ( V_19 -> V_27 . V_22 ) ] [ V_21 ] ;
V_17 -> V_23 . integer . V_23 [ 0 ] = V_30 ;
return 0 ;
}
static int F_31 ( struct V_11 * V_12 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_12 -> V_20 ;
struct V_1 * V_2 = V_19 -> V_27 . V_28 -> V_2 ;
struct V_62 * V_48 = V_19 -> V_20 ;
int V_21 = V_17 -> V_22 . V_21 ;
char V_3 [ sizeof( V_63 ) ] ;
int V_30 , V_32 = 0 ;
int V_64 ;
V_30 = V_17 -> V_23 . integer . V_23 [ 0 ] + F_19 ( V_12 ) ;
memcpy ( V_3 , V_63 , sizeof( V_63 ) ) ;
V_3 [ 5 ] = V_21 + 1 ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ ) {
V_3 [ 20 ] = V_30 ;
V_3 [ 17 ] = V_48 -> V_30 [ V_64 ] [ 2 ] [ V_21 ] ;
V_3 [ 14 ] = V_48 -> V_30 [ V_64 ] [ 1 ] [ V_21 ] ;
V_3 [ 11 ] = V_48 -> V_30 [ V_64 ] [ 0 ] [ V_21 ] ;
V_3 [ 8 ] = V_64 + 1 ;
V_32 = F_6 ( V_2 , V_3 , sizeof( V_63 ) ) ;
if ( V_32 < 0 )
break;
V_48 -> V_30 [ V_64 ] [ 3 ] [ V_21 ] = V_30 ;
F_32 ( 15 ) ;
}
if ( V_32 > 0 ) {
V_19 -> V_34 |= 1 << V_21 ;
V_19 -> V_26 [ V_21 ] = V_30 ;
} else {
F_12 ( V_2 , L_6 , V_32 ) ;
}
return 1 ;
}
static int F_33 ( struct V_11 * V_12 ,
struct V_16 * V_17 )
{
int V_30 ;
struct V_18 * V_19 = V_12 -> V_20 ;
struct V_62 * V_48 = V_19 -> V_20 ;
int V_21 = V_17 -> V_22 . V_21 ;
int V_64 = F_29 ( V_19 -> V_27 . V_22 ) - 1 ;
int V_66 = F_30 ( V_19 -> V_27 . V_22 ) ;
V_30 = V_48 -> V_30 [ V_64 ] [ V_66 ] [ V_21 ] ;
V_17 -> V_23 . integer . V_23 [ 0 ] = V_30 ;
return 0 ;
}
static int F_34 ( struct V_11 * V_12 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_12 -> V_20 ;
struct V_1 * V_2 = V_19 -> V_27 . V_28 -> V_2 ;
struct V_62 * V_48 = V_19 -> V_20 ;
int V_21 = V_17 -> V_22 . V_21 ;
char V_3 [ sizeof( V_63 ) ] ;
int V_30 , V_32 ;
int V_64 = F_29 ( V_19 -> V_27 . V_22 ) - 1 ;
int V_66 = F_30 ( V_19 -> V_27 . V_22 ) ;
V_30 = V_17 -> V_23 . integer . V_23 [ 0 ] ;
if ( V_30 < F_15 ( V_12 )
|| V_30 > F_14 ( V_12 ) )
return - V_33 ;
memcpy ( V_3 , V_63 , sizeof( V_63 ) ) ;
V_48 -> V_30 [ V_64 ] [ V_66 ] [ V_21 ] = V_30 ;
V_3 [ 20 ] = V_48 -> V_30 [ V_64 ] [ 3 ] [ V_21 ] ;
V_3 [ 17 ] = V_48 -> V_30 [ V_64 ] [ 2 ] [ V_21 ] ;
V_3 [ 14 ] = V_48 -> V_30 [ V_64 ] [ 1 ] [ V_21 ] ;
V_3 [ 11 ] = V_48 -> V_30 [ V_64 ] [ 0 ] [ V_21 ] ;
V_3 [ 5 ] = V_21 + 1 ;
V_3 [ 8 ] = V_64 + 1 ;
V_32 = F_6 ( V_2 , V_3 , sizeof( V_63 ) ) ;
if ( V_32 > 0 ) {
V_19 -> V_34 |= 1 << V_21 ;
V_19 -> V_26 [ V_21 ] = V_30 ;
} else {
F_12 ( V_2 , L_7 , V_32 ) ;
}
return 1 ;
}
static int F_35 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
V_14 -> V_35 = 1 ;
V_14 -> type = V_36 ;
V_14 -> V_23 . integer . V_37 = 0x7FFF ;
V_14 -> V_23 . integer . V_38 = 0 ;
return 0 ;
}
static int F_36 ( struct V_67 * V_48 )
{
int V_68 ;
if ( V_48 -> V_69 ) {
if ( V_48 -> V_69 & 0x20 ) {
if ( V_48 -> V_70 -
V_48 -> V_69 > 1 )
V_48 -> V_70 =
V_48 -> V_69 ;
V_68 = V_48 -> V_70 ++ & 0x1F ;
} else {
V_68 = V_48 -> V_69 ;
}
} else {
while ( ! V_48 -> V_71 -> V_30 [
F_26 ( V_61 ) ]
[ V_48 -> V_70 - 1 ]
&& V_48 -> V_70 <= V_72 ) {
V_48 -> V_70 ++ ;
}
V_68 = V_48 -> V_70 ++ ;
if ( V_48 -> V_70 > V_72 )
V_48 -> V_70 = 1 ;
}
return V_68 ;
}
static void F_37 ( int V_73 ,
struct V_67 * V_48 ,
T_1 * V_74 )
{
int V_30 = F_38 ( V_74 , V_73 ) + ( F_39 ( V_74 , V_73 ) << 8 ) ;
if ( F_40 ( V_74 , V_73 ) == 0x61 && F_41 ( V_74 , V_73 ) == 0x02 &&
F_42 ( V_74 , V_73 ) == 0x04 && F_43 ( V_74 , V_73 ) == 0x62 ) {
if ( F_44 ( V_74 , V_73 ) == 0x72 )
V_48 -> V_75 [ F_45 ( V_74 , V_73 ) - 1 ] = V_30 ;
if ( F_44 ( V_74 , V_73 ) == 0xb2 )
V_48 -> V_76 [ F_45 ( V_74 , V_73 ) - 1 ] = V_30 ;
}
if ( F_40 ( V_74 , V_73 ) == 0x61 && F_41 ( V_74 , V_73 ) == 0x02 &&
F_42 ( V_74 , V_73 ) == 0x02 && F_43 ( V_74 , V_73 ) == 0x62 )
V_48 -> V_77 [ F_45 ( V_74 , V_73 ) - 1 ] = V_30 ;
}
static int F_46 ( struct V_11 * V_12 ,
struct V_16 * V_17 )
{
int V_78 , V_79 ;
struct V_18 * V_19 = V_12 -> V_20 ;
struct V_1 * V_2 = V_19 -> V_27 . V_28 -> V_2 ;
struct V_67 * V_48 = V_19 -> V_20 ;
T_1 V_74 [ 64 ] ;
char V_80 [ sizeof( V_81 ) ] = { 0 } ;
switch ( V_12 -> V_82 ) {
case 0 :
F_6 ( V_2 , ( char * ) V_83 ,
sizeof( V_83 ) ) ;
F_1 ( V_2 , V_74 ,
sizeof( V_74 ) ) ;
V_12 -> V_82 ++ ;
break;
case 1 :
F_1 ( V_2 , V_74 ,
sizeof( V_74 ) ) ;
V_12 -> V_82 ++ ;
break;
case 2 :
F_1 ( V_2 , V_74 ,
sizeof( V_74 ) ) ;
V_12 -> V_82 ++ ;
break;
case 3 :
memcpy ( V_80 , V_81 , sizeof( V_81 ) ) ;
V_80 [ 2 ] = F_36 ( V_48 ) ;
F_6 ( V_2 , V_80 , sizeof( V_81 ) ) ;
F_1 ( V_2 , V_74 ,
sizeof( V_74 ) ) ;
V_12 -> V_82 = 0 ;
break;
}
for ( V_79 = 0 ; V_79 < 6 ; V_79 ++ )
F_37 ( V_79 , V_48 , V_74 ) ;
for ( V_78 = 0 ; V_78 < V_72 ; V_78 ++ ) {
V_17 -> V_23 . integer . V_23 [ V_78 ] =
V_48 ? V_48 -> V_75 [ V_78 ] : 0 ;
}
V_17 -> V_23 . integer . V_23 [ V_78 ++ ] = V_48 ? V_48 -> V_77 [ 0 ] : 0 ;
V_17 -> V_23 . integer . V_23 [ V_78 ++ ] = V_48 ? V_48 -> V_77 [ 1 ] : 0 ;
for ( V_78 = 2 ; V_78 < V_72 + 2 ; V_78 ++ )
V_17 -> V_23 . integer . V_23 [ V_78 + V_72 ] =
V_48 ? V_48 -> V_76 [ V_78 - 2 ] : 0 ;
return 1 ;
}
static int F_47 ( struct V_11 * V_12 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_12 -> V_20 ;
struct V_67 * V_48 = V_19 -> V_20 ;
int V_30 ;
V_30 = V_17 -> V_23 . integer . V_23 [ 0 ] ;
if ( V_30 < 0 || V_30 >= V_72 )
return - V_33 ;
V_48 -> V_69 = V_30 ;
V_48 -> V_70 = V_30 ;
return 1 ;
}
static struct V_47 * F_48 ( void )
{
int V_78 ;
struct V_47 * V_80 ;
V_80 = F_49 ( sizeof( * V_80 ) , V_84 ) ;
if ( ! V_80 )
return NULL ;
for ( V_78 = 0 ; V_78 < V_72 ; V_78 ++ ) {
V_80 -> V_30 [ F_26 ( V_52 ) ] [ V_78 ]
= 0x20 ;
V_80 -> V_30 [ F_26 ( V_55 ) ] [ V_78 ] = 0x00 ;
V_80 -> V_30 [ F_26 ( V_60 ) ] [ V_78 ] = 0x00 ;
V_80 -> V_30 [ F_26 ( V_61 ) ] [ V_78 ] = 0x00 ;
V_80 -> V_30 [ F_26 ( V_56 ) ] [ V_78 ] = 0x00 ;
V_80 -> V_30 [ F_26 ( V_58 ) ] [ V_78 ] = 0x00 ;
}
return V_80 ;
}
static struct V_62 * F_50 ( void )
{
int V_78 , V_64 ;
struct V_62 * V_80 ;
V_80 = F_49 ( sizeof( * V_80 ) , V_84 ) ;
if ( ! V_80 )
return NULL ;
for ( V_78 = 0 ; V_78 < V_72 ; V_78 ++ ) {
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ ) {
V_80 -> V_30 [ V_64 ] [ 0 ] [ V_78 ] = 0x0c ;
V_80 -> V_30 [ V_64 ] [ 3 ] [ V_78 ] = 0x00 ;
switch ( V_64 ) {
case 0 :
V_80 -> V_30 [ V_64 ] [ 1 ] [ V_78 ] = 0x05 ;
V_80 -> V_30 [ V_64 ] [ 2 ] [ V_78 ] = 0xff ;
break;
case 1 :
V_80 -> V_30 [ V_64 ] [ 1 ] [ V_78 ] = 0x0e ;
V_80 -> V_30 [ V_64 ] [ 2 ] [ V_78 ] = 0x02 ;
break;
case 2 :
V_80 -> V_30 [ V_64 ] [ 1 ] [ V_78 ] = 0x1b ;
V_80 -> V_30 [ V_64 ] [ 2 ] [ V_78 ] = 0x02 ;
break;
case 3 :
V_80 -> V_30 [ V_64 ] [ 1 ] [ V_78 ] = 0x2f
- V_85 ;
V_80 -> V_30 [ V_64 ] [ 2 ] [ V_78 ] = 0xff ;
break;
}
}
}
return V_80 ;
}
static struct V_67 * F_51 ( void )
{
struct V_67 * V_80 ;
V_80 = F_52 ( sizeof( * V_80 ) , V_84 ) ;
if ( ! V_80 )
return NULL ;
V_80 -> V_70 = 1 ;
V_80 -> V_69 = 0 ;
return V_80 ;
}
static void F_53 ( struct V_11 * V_86 )
{
struct V_18 * V_19 = V_86 -> V_20 ;
if ( V_19 )
F_54 ( V_19 -> V_20 ) ;
F_54 ( V_19 ) ;
V_86 -> V_20 = NULL ;
}
static int F_55 ( struct V_87 * V_28 ,
const struct V_88 * V_89 ,
int V_21 , int V_90 , int V_91 ,
const char * V_92 , void * V_93 ,
bool V_94 ,
struct V_18 * * V_95 )
{
struct V_11 * V_86 ;
struct V_18 * V_19 ;
int V_32 ;
F_12 ( V_28 -> V_2 , L_8 , V_92 ) ;
V_19 = F_52 ( sizeof( * V_19 ) , V_84 ) ;
if ( ! V_19 )
return - V_96 ;
V_19 -> V_27 . V_28 = V_28 ;
V_19 -> V_27 . V_97 = NULL ;
V_19 -> V_98 = 0 ;
V_19 -> V_99 = 0 ;
V_19 -> V_27 . V_22 = V_21 ;
V_19 -> V_90 = V_90 ;
V_19 -> V_91 = V_91 ;
V_19 -> V_20 = V_93 ;
V_86 = F_56 ( V_89 , V_19 ) ;
if ( ! V_86 ) {
F_54 ( V_19 ) ;
return - V_96 ;
}
if ( V_94 )
V_86 -> V_100 = F_53 ;
else
V_86 -> V_100 = V_101 ;
F_57 ( V_86 -> V_22 . V_92 , V_92 , sizeof( V_86 -> V_22 . V_92 ) ) ;
V_32 = F_58 ( & V_19 -> V_27 , V_86 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_95 )
* V_95 = V_19 ;
return 0 ;
}
int F_59 ( struct V_87 * V_28 )
{
int V_78 , V_102 ;
int V_32 ;
struct V_18 * V_19 ;
struct V_47 * V_71 ;
struct V_67 * V_103 ;
struct V_62 * V_104 ;
if ( V_28 -> V_105 -> V_106 . V_107 == 3 ) {
V_32 = F_55 ( V_28 , & V_108 ,
V_109 , V_110 , 8 , L_9 ,
NULL , false , & V_19 ) ;
if ( V_32 < 0 ) {
F_12 ( V_28 -> V_2 ,
L_10 ,
V_32 ) ;
return V_32 ;
}
for ( V_78 = 0 ; V_78 < 8 ; V_78 ++ )
V_19 -> V_26 [ V_78 ] = V_78 < 2 ? V_78 : V_78 + 2 ;
V_19 -> V_34 = 0xff ;
V_71 = F_48 () ;
if ( ! V_71 )
return - V_96 ;
for ( V_78 = 0 ; V_78 < F_60 ( V_111 ) ; V_78 ++ ) {
V_32 = F_55 ( V_28 ,
V_111 [ V_78 ] . V_112 ,
V_111 [ V_78 ] . V_113 ,
V_111 [ V_78 ] . type ,
V_111 [ V_78 ] . V_114 ,
V_111 [ V_78 ] . V_92 ,
V_71 ,
V_78 == 0 ,
& V_19 ) ;
if ( V_32 < 0 )
return V_32 ;
V_19 -> V_26 [ 0 ] = V_111 [ V_78 ] . V_115 ;
V_19 -> V_34 = 1 ;
}
for ( V_78 = 0 ; V_78 < F_60 ( V_116 ) ; V_78 ++ ) {
V_32 = F_55 ( V_28 ,
V_116 [ V_78 ] . V_112 ,
V_116 [ V_78 ] . V_113 ,
V_116 [ V_78 ] . type ,
V_116 [ V_78 ] . V_114 ,
V_116 [ V_78 ] . V_92 ,
V_71 ,
false , & V_19 ) ;
if ( V_32 < 0 )
return V_32 ;
for ( V_102 = 0 ; V_102 < V_72 ; V_102 ++ ) {
V_19 -> V_26 [ V_102 ] =
V_116 [ V_78 ] . V_115 ;
}
V_19 -> V_34 = 0xffff ;
}
V_104 = F_50 () ;
if ( ! V_104 )
return - V_96 ;
for ( V_78 = 0 ; V_78 < F_60 ( V_117 ) ; V_78 ++ ) {
V_32 = F_55 ( V_28 ,
V_117 [ V_78 ] . V_112 ,
V_117 [ V_78 ] . V_113 ,
V_117 [ V_78 ] . type ,
V_117 [ V_78 ] . V_114 ,
V_117 [ V_78 ] . V_92 ,
V_104 ,
V_78 == 0 ,
NULL ) ;
if ( V_32 < 0 )
return V_32 ;
}
for ( V_78 = 0 ; V_78 < F_60 ( V_118 ) ; V_78 ++ ) {
V_32 = F_55 ( V_28 ,
V_118 [ V_78 ] . V_112 ,
V_118 [ V_78 ] . V_113 ,
V_118 [ V_78 ] . type ,
V_118 [ V_78 ] . V_114 ,
V_118 [ V_78 ] . V_92 ,
V_71 ,
false , NULL ) ;
if ( V_32 < 0 )
return V_32 ;
}
V_103 = F_51 () ;
if ( ! V_103 )
return - V_96 ;
V_103 -> V_71 = V_71 ;
V_32 = F_55 ( V_28 , & V_119 ,
V_120 , V_121 , 0 , L_11 ,
V_103 , true , NULL ) ;
if ( V_32 < 0 )
return V_32 ;
}
return 0 ;
}
