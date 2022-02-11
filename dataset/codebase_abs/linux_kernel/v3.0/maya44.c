static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned char V_5 , unsigned short V_6 )
{
F_2 ( V_2 , V_4 -> V_7 ,
( V_5 << 1 ) | ( ( V_6 >> 8 ) & 1 ) ,
V_6 & 0xff ) ;
V_4 -> V_8 [ V_5 ] = V_6 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned char V_5 ,
unsigned short V_9 , unsigned short V_6 )
{
V_6 |= V_4 -> V_8 [ V_5 ] & ~ V_9 ;
if ( V_6 != V_4 -> V_8 [ V_5 ] ) {
F_1 ( V_2 , V_4 , V_5 , V_6 ) ;
return 1 ;
}
return 0 ;
}
static int F_4 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
unsigned int V_14 = V_11 -> V_15 ;
struct F_4 * V_16 = & V_17 [ V_14 ] ;
V_13 -> type = V_18 ;
V_13 -> V_19 = 2 ;
V_13 -> V_20 . integer . V_21 = 0 ;
V_13 -> V_20 . integer . V_22 = V_16 -> V_23 ;
return 0 ;
}
static int F_5 ( struct V_10 * V_11 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = F_6 ( V_11 ) ;
struct V_3 * V_4 =
& V_27 -> V_4 [ F_7 ( V_11 , & V_25 -> V_28 ) ] ;
unsigned int V_14 = V_11 -> V_15 ;
F_8 ( & V_27 -> V_29 ) ;
V_25 -> V_20 . integer . V_20 [ 0 ] = V_4 -> V_30 [ V_14 ] [ 0 ] ;
V_25 -> V_20 . integer . V_20 [ 1 ] = V_4 -> V_30 [ V_14 ] [ 1 ] ;
F_9 ( & V_27 -> V_29 ) ;
return 0 ;
}
static int F_10 ( struct V_10 * V_11 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = F_6 ( V_11 ) ;
struct V_3 * V_4 =
& V_27 -> V_4 [ F_7 ( V_11 , & V_25 -> V_28 ) ] ;
unsigned int V_14 = V_11 -> V_15 ;
struct F_4 * V_16 = & V_17 [ V_14 ] ;
unsigned int V_6 , V_31 ;
int V_32 , V_33 = 0 ;
F_8 ( & V_27 -> V_29 ) ;
for ( V_32 = 0 ; V_32 < 2 ; V_32 ++ ) {
V_6 = V_25 -> V_20 . integer . V_20 [ V_32 ] ;
if ( V_6 > V_16 -> V_23 )
V_6 = V_16 -> V_23 ;
if ( V_6 == V_4 -> V_30 [ V_14 ] [ V_32 ] )
continue;
if ( ! V_6 )
V_31 = V_16 -> V_34 ;
else
V_31 = ( V_6 - 1 ) + V_16 -> V_35 ;
V_31 |= V_16 -> V_36 ;
V_33 |= F_3 ( V_27 -> V_2 , V_4 , V_16 -> V_8 [ V_32 ] ,
V_16 -> V_9 | V_16 -> V_36 , V_31 ) ;
if ( V_16 -> V_37 [ V_32 ] )
F_3 ( V_27 -> V_2 , V_4 , V_38 ,
V_16 -> V_37 [ V_32 ] ,
V_6 ? 0 : V_16 -> V_37 [ V_32 ] ) ;
V_4 -> V_30 [ V_14 ] [ V_32 ] = V_6 ;
}
F_9 ( & V_27 -> V_29 ) ;
return V_33 ;
}
static int F_11 ( struct V_10 * V_11 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = F_6 ( V_11 ) ;
struct V_3 * V_4 =
& V_27 -> V_4 [ F_7 ( V_11 , & V_25 -> V_28 ) ] ;
unsigned int V_14 = F_12 ( V_11 -> V_15 ) ;
V_25 -> V_20 . integer . V_20 [ 0 ] = ( V_4 -> V_39 >> V_14 ) & 1 ;
return 0 ;
}
static int F_13 ( struct V_10 * V_11 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = F_6 ( V_11 ) ;
struct V_3 * V_4 =
& V_27 -> V_4 [ F_7 ( V_11 , & V_25 -> V_28 ) ] ;
unsigned int V_14 = F_12 ( V_11 -> V_15 ) ;
unsigned int V_9 , V_6 ;
int V_33 ;
F_8 ( & V_27 -> V_29 ) ;
V_9 = 1 << V_14 ;
V_4 -> V_39 &= ~ V_9 ;
V_6 = V_25 -> V_20 . integer . V_20 [ 0 ] ;
if ( V_6 )
V_4 -> V_39 |= V_9 ;
V_9 = F_14 ( V_11 -> V_15 ) ;
V_33 = F_3 ( V_27 -> V_2 , V_4 ,
F_15 ( V_11 -> V_15 ) ,
V_9 , V_6 ? V_9 : 0 ) ;
F_9 ( & V_27 -> V_29 ) ;
return V_33 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned int V_9 ,
unsigned int V_40 )
{
unsigned int V_31 ;
V_31 = F_17 ( V_2 ) ;
if ( ( V_31 & V_9 ) == V_40 )
return 0 ;
F_18 ( V_2 , ( V_31 & ~ V_9 ) | V_40 ) ;
return 1 ;
}
static int F_19 ( struct V_10 * V_11 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = F_6 ( V_11 ) ;
unsigned int V_41 = F_20 ( V_11 -> V_15 ) ;
unsigned int V_6 ;
V_6 = ( F_17 ( V_27 -> V_2 ) >> V_41 ) & 1 ;
if ( F_21 ( V_11 -> V_15 ) )
V_6 = ! V_6 ;
V_25 -> V_20 . integer . V_20 [ 0 ] = V_6 ;
return 0 ;
}
static int F_22 ( struct V_10 * V_11 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = F_6 ( V_11 ) ;
unsigned int V_41 = F_20 ( V_11 -> V_15 ) ;
unsigned int V_6 , V_9 ;
int V_33 ;
F_8 ( & V_27 -> V_29 ) ;
V_9 = 1 << V_41 ;
V_6 = V_25 -> V_20 . integer . V_20 [ 0 ] ;
if ( F_21 ( V_11 -> V_15 ) )
V_6 = ! V_6 ;
V_6 = V_6 ? V_9 : 0 ;
V_33 = F_16 ( V_27 -> V_2 , V_9 , V_6 ) ;
F_9 ( & V_27 -> V_29 ) ;
return V_33 ;
}
static void F_23 ( struct V_26 * V_27 , int V_14 , int line )
{
F_3 ( V_27 -> V_2 , & V_27 -> V_4 [ V_14 ] , V_38 ,
0x1f , 1 << line ) ;
}
static int F_24 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
static char * V_42 [] = { L_1 , L_2 } ;
V_13 -> type = V_43 ;
V_13 -> V_19 = 1 ;
V_13 -> V_20 . V_44 . V_45 = F_25 ( V_42 ) ;
if ( V_13 -> V_20 . V_44 . V_46 >= V_13 -> V_20 . V_44 . V_45 )
V_13 -> V_20 . V_44 . V_46 =
V_13 -> V_20 . V_44 . V_45 - 1 ;
strcpy ( V_13 -> V_20 . V_44 . V_47 ,
V_42 [ V_13 -> V_20 . V_44 . V_46 ] ) ;
return 0 ;
}
static int F_26 ( struct V_10 * V_11 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = F_6 ( V_11 ) ;
int V_48 ;
if ( F_17 ( V_27 -> V_2 ) & ( 1 << V_49 ) )
V_48 = 1 ;
else
V_48 = 0 ;
V_25 -> V_20 . V_44 . V_46 [ 0 ] = V_48 ;
return 0 ;
}
static int F_27 ( struct V_10 * V_11 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = F_6 ( V_11 ) ;
int V_48 = V_25 -> V_20 . V_44 . V_46 [ 0 ] ;
int V_33 ;
F_8 ( & V_27 -> V_29 ) ;
V_33 = F_16 ( V_27 -> V_2 , 1 << V_49 ,
V_48 ? ( 1 << V_49 ) : 0 ) ;
F_23 ( V_27 , 0 , V_48 ? V_50 : V_51 ) ;
F_9 ( & V_27 -> V_29 ) ;
return V_33 ;
}
static int F_28 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
static char * V_42 [] = {
L_3 ,
L_4 , L_5 , L_6 , L_7
} ;
V_13 -> type = V_43 ;
V_13 -> V_19 = 1 ;
V_13 -> V_20 . V_44 . V_45 = F_25 ( V_42 ) ;
if ( V_13 -> V_20 . V_44 . V_46 >= V_13 -> V_20 . V_44 . V_45 )
V_13 -> V_20 . V_44 . V_46 =
V_13 -> V_20 . V_44 . V_45 - 1 ;
strcpy ( V_13 -> V_20 . V_44 . V_47 ,
V_42 [ V_13 -> V_20 . V_44 . V_46 ] ) ;
return 0 ;
}
static int F_29 ( int V_14 )
{
static const unsigned char V_41 [ 10 ] =
{ 8 , 20 , 0 , 3 , 11 , 23 , 14 , 26 , 17 , 29 } ;
return V_41 [ V_14 % 10 ] ;
}
static int F_30 ( struct V_10 * V_11 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = F_6 ( V_11 ) ;
int V_14 = F_31 ( V_11 , & V_25 -> V_28 ) ;
V_25 -> V_20 . V_44 . V_46 [ 0 ] =
F_32 ( V_27 -> V_2 , F_29 ( V_14 ) ) ;
return 0 ;
}
static int F_33 ( struct V_10 * V_11 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = F_6 ( V_11 ) ;
int V_14 = F_31 ( V_11 , & V_25 -> V_28 ) ;
return F_34 ( V_27 -> V_2 ,
V_25 -> V_20 . V_44 . V_46 [ 0 ] ,
F_29 ( V_14 ) ) ;
}
static int T_1 F_35 ( struct V_1 * V_2 )
{
int V_52 , V_53 ;
for ( V_53 = 0 ; V_53 < F_25 ( V_54 ) ; V_53 ++ ) {
V_52 = F_36 ( V_2 -> V_55 , F_37 ( & V_54 [ V_53 ] ,
V_2 -> V_56 ) ) ;
if ( V_52 < 0 )
return V_52 ;
}
return 0 ;
}
static void T_1 F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_7 )
{
static const unsigned short V_57 [] = {
0x02 , 0x100 ,
0x05 , 0x100 ,
0x06 , 0x000 ,
0x07 , 0x091 ,
0x08 , 0x000 ,
0x09 , 0x000 ,
0x0a , 0x022 ,
0x0b , 0x022 ,
0x0c , 0x042 ,
0x0d , 0x000 ,
0x0e , 0x100 ,
0x0f , 0x100 ,
0x11 , 0x000 ,
0x15 , 0x000 ,
0x16 , 0x001 ,
0xff , 0xff
} ;
const unsigned short * V_58 ;
unsigned char V_5 ;
unsigned short V_31 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_39 = ( 1 << V_59 ) ;
V_58 = V_57 ;
while ( * V_58 != 0xff ) {
V_5 = * V_58 ++ ;
V_31 = * V_58 ++ ;
F_1 ( V_2 , V_4 , V_5 , V_31 ) ;
}
}
static void F_39 ( struct V_1 * V_2 , unsigned int V_60 )
{
struct V_26 * V_27 = V_2 -> V_56 ;
unsigned int V_61 , V_62 , V_6 ;
int V_53 ;
switch ( V_60 ) {
case 192000 :
V_61 = V_63 ;
break;
case 176400 :
V_61 = V_63 ;
break;
case 96000 :
V_61 = V_64 ;
break;
case 88200 :
V_61 = V_65 ;
break;
case 48000 :
V_61 = V_66 ;
break;
case 44100 :
V_61 = V_66 ;
break;
case 32000 :
V_61 = V_67 ;
break;
case 0 :
return;
default:
F_40 () ;
return;
}
V_62 = V_61 ;
if ( V_62 < V_64 )
V_62 = V_64 ;
V_6 = V_62 ;
if ( V_62 == V_64 )
V_6 |= 8 ;
V_6 |= V_61 << 4 ;
F_8 ( & V_27 -> V_29 ) ;
for ( V_53 = 0 ; V_53 < 2 ; V_53 ++ )
F_3 ( V_2 , & V_27 -> V_4 [ V_53 ] ,
V_68 ,
0x180 , V_6 ) ;
F_9 ( & V_27 -> V_29 ) ;
}
static int T_1 F_41 ( struct V_1 * V_2 )
{
int V_53 ;
struct V_26 * V_27 ;
V_27 = F_42 ( sizeof( * V_27 ) , V_69 ) ;
if ( ! V_27 )
return - V_70 ;
F_43 ( & V_27 -> V_29 ) ;
V_27 -> V_2 = V_2 ;
V_2 -> V_56 = V_27 ;
V_2 -> V_71 = 4 ;
V_2 -> V_72 = 4 ;
V_2 -> V_73 = 0 ;
for ( V_53 = 0 ; V_53 < 2 ; V_53 ++ ) {
F_38 ( V_2 , & V_27 -> V_4 [ V_53 ] , V_74 [ V_53 ] ) ;
F_23 ( V_27 , V_53 , V_51 ) ;
}
V_2 -> V_75 = & V_76 ;
V_2 -> V_77 . V_78 = F_39 ;
V_2 -> V_79 = 1 ;
V_2 -> V_80 = 1 ;
return 0 ;
}
