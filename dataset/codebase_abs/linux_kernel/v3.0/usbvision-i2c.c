static inline int F_1 ( struct V_1 * V_2 ,
unsigned char V_3 , int V_4 )
{
struct V_5 * V_6 ;
int V_7 , V_8 = - 1 ;
char V_9 [ 4 ] ;
V_6 = (struct V_5 * ) F_2 ( V_2 ) ;
V_9 [ 0 ] = 0x00 ;
for ( V_7 = 0 ; V_7 <= V_4 ; V_7 ++ ) {
V_8 = ( F_3 ( V_6 , V_3 , V_9 , 1 ) ) ;
if ( V_8 == 1 )
break;
F_4 ( 5 ) ;
if ( V_7 == V_4 )
break;
F_4 ( 10 ) ;
}
if ( V_7 ) {
F_5 ( V_10 , L_1 , V_7 , V_3 ) ;
F_5 ( V_10 , L_2 ) ;
}
return V_8 ;
}
static inline int F_6 ( struct V_1 * V_2 ,
unsigned char V_3 , int V_4 )
{
struct V_5 * V_6 ;
int V_7 , V_8 = - 1 ;
char V_9 [ 4 ] ;
V_6 = (struct V_5 * ) F_2 ( V_2 ) ;
for ( V_7 = 0 ; V_7 <= V_4 ; V_7 ++ ) {
V_8 = ( F_7 ( V_6 , V_3 , V_9 , 1 ) ) ;
if ( V_8 == 1 )
break;
F_4 ( 5 ) ;
if ( V_7 == V_4 )
break;
F_4 ( 10 ) ;
}
if ( V_7 ) {
F_5 ( V_10 , L_1 , V_7 , V_3 ) ;
F_5 ( V_10 , L_2 ) ;
}
return V_8 ;
}
static inline int F_8 ( struct V_1 * V_2 ,
struct V_11 * V_12 , int V_4 ,
unsigned char * V_13 )
{
unsigned short V_14 = V_12 -> V_14 ;
unsigned char V_3 ;
int V_8 ;
if ( ( V_14 & V_15 ) ) {
V_3 = 0xf0 | ( ( V_12 -> V_3 >> 7 ) & 0x03 ) ;
V_8 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_8 != 1 ) {
F_9 ( & V_2 -> V_16 ,
L_3 ) ;
return - V_17 ;
}
V_13 [ 0 ] = V_3 ;
if ( V_14 & V_18 ) {
V_3 |= 0x01 ;
V_8 = F_6 ( V_2 , V_3 , V_4 ) ;
if ( V_8 != 1 ) {
F_9 ( & V_2 -> V_16 ,
L_4 ) ;
return - V_17 ;
}
}
} else {
V_3 = ( V_12 -> V_3 << 1 ) ;
if ( V_14 & V_18 )
V_3 |= 1 ;
V_13 [ 0 ] = V_3 ;
if ( V_14 & V_18 )
V_8 = F_6 ( V_2 , V_3 , V_4 ) ;
else
V_8 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_8 != 1 )
return - V_17 ;
}
return 0 ;
}
static int
F_10 ( struct V_1 * V_2 , struct V_11 V_19 [] , int V_20 )
{
struct V_11 * V_21 ;
struct V_5 * V_6 ;
int V_7 , V_8 ;
unsigned char V_3 = 0 ;
V_6 = (struct V_5 * ) F_2 ( V_2 ) ;
for ( V_7 = 0 ; V_7 < V_20 ; V_7 ++ ) {
V_21 = & V_19 [ V_7 ] ;
V_8 = F_8 ( V_2 , V_21 , V_2 -> V_4 , & V_3 ) ;
if ( V_8 != 0 ) {
F_5 ( V_10 , L_5 , V_7 ) ;
return ( V_8 < 0 ) ? V_8 : - V_17 ;
}
if ( V_21 -> V_14 & V_18 ) {
V_8 = ( F_7 ( V_6 , V_3 , V_21 -> V_9 , V_21 -> V_22 ) ) ;
if ( V_8 < V_21 -> V_22 )
return ( V_8 < 0 ) ? V_8 : - V_17 ;
} else {
V_8 = ( F_3 ( V_6 , V_3 , V_21 -> V_9 , V_21 -> V_22 ) ) ;
if ( V_8 < V_21 -> V_22 )
return ( V_8 < 0 ) ? V_8 : - V_17 ;
}
}
return V_20 ;
}
static T_1 F_11 ( struct V_1 * V_23 )
{
return V_24 | V_25 ;
}
int F_12 ( struct V_5 * V_6 )
{
static unsigned short V_26 [] = {
0x4a >> 1 , 0x48 >> 1 ,
0x42 >> 1 , 0x40 >> 1 ,
V_27 } ;
if ( V_6 -> V_28 )
return 0 ;
memcpy ( & V_6 -> V_2 , & V_29 ,
sizeof( struct V_1 ) ) ;
sprintf ( V_6 -> V_2 . V_30 , L_6 , V_29 . V_30 ,
V_6 -> V_16 -> V_31 -> V_32 , V_6 -> V_16 -> V_33 ) ;
F_5 ( V_10 , L_7 , V_6 -> V_2 . V_30 ) ;
V_6 -> V_2 . V_16 . V_34 = & V_6 -> V_16 -> V_16 ;
F_13 ( & V_6 -> V_2 , & V_6 -> V_35 ) ;
if ( F_14 ( V_6 , V_36 , V_37 ) < 0 ) {
F_15 ( V_38 L_8 ) ;
return - V_39 ;
}
F_5 ( V_10 , L_9 ) ;
F_5 ( V_10 , L_10 ) ;
V_6 -> V_2 . V_40 = & V_41 ;
V_6 -> V_2 . V_42 = 100 ;
V_6 -> V_2 . V_4 = 3 ;
F_16 ( & V_6 -> V_2 ) ;
F_5 ( V_10 , L_11 , V_6 -> V_2 . V_30 ) ;
switch ( V_43 [ V_6 -> V_44 ] . V_45 ) {
case V_46 :
case V_47 :
F_17 ( 10 ) ;
F_18 ( & V_6 -> V_35 ,
& V_6 -> V_2 ,
L_12 , 0 , V_26 ) ;
break;
}
if ( V_43 [ V_6 -> V_44 ] . V_48 == 1 ) {
struct V_49 * V_50 ;
enum V_51 type ;
struct V_52 V_53 ;
V_50 = F_18 ( & V_6 -> V_35 ,
& V_6 -> V_2 ,
L_13 , 0 , F_19 ( V_54 ) ) ;
type = V_50 ? V_55 : V_56 ;
V_50 = F_18 ( & V_6 -> V_35 ,
& V_6 -> V_2 ,
L_13 , 0 , F_19 ( type ) ) ;
if ( V_50 == NULL )
return - V_57 ;
if ( V_6 -> V_58 != - 1 ) {
V_53 . V_59 = V_60 | V_61 ;
V_53 . type = V_6 -> V_58 ;
V_53 . V_3 = F_20 ( V_50 ) ;
F_21 ( V_6 , V_48 , V_62 , & V_53 ) ;
}
}
V_6 -> V_28 = 1 ;
return 0 ;
}
int F_22 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_28 )
return 0 ;
F_23 ( & ( V_6 -> V_2 ) ) ;
V_6 -> V_28 = 0 ;
F_5 ( V_10 , L_14 , V_6 -> V_2 . V_30 ) ;
return 0 ;
}
static int
F_24 ( struct V_5 * V_6 , unsigned char V_3 ,
char * V_9 , short V_22 )
{
int V_63 , V_4 ;
for ( V_4 = 5 ; ; ) {
V_63 = F_14 ( V_6 , V_64 , V_3 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_14 ( V_6 , V_65 ,
( V_22 & 0x07 ) | 0x18 ) ;
if ( V_63 < 0 )
return V_63 ;
do {
V_63 = F_25 ( V_6 , V_65 ) ;
} while ( V_63 > 0 && ( ( V_63 & 0x10 ) != 0 ) );
if ( V_63 < 0 )
return V_63 ;
if ( ( V_63 & 0x20 ) == 0 )
break;
V_63 = F_14 ( V_6 , V_65 , 0x00 ) ;
if ( V_63 < 0 )
return V_63 ;
if ( -- V_4 < 0 )
return - 1 ;
}
switch ( V_22 ) {
case 4 :
V_9 [ 3 ] = F_25 ( V_6 , V_66 ) ;
case 3 :
V_9 [ 2 ] = F_25 ( V_6 , V_67 ) ;
case 2 :
V_9 [ 1 ] = F_25 ( V_6 , V_68 ) ;
case 1 :
V_9 [ 0 ] = F_25 ( V_6 , V_69 ) ;
break;
default:
F_15 ( V_38
L_15 ) ;
}
if ( V_70 & V_10 ) {
int V_71 ;
for ( V_71 = 0 ; V_71 < V_22 ; V_71 ++ )
F_5 ( V_10 , L_16 , ( unsigned char ) V_9 [ V_71 ] , V_3 ) ;
}
return V_22 ;
}
static int F_26 ( struct V_5 * V_6 ,
unsigned char V_3 , const char * V_9 ,
short V_22 )
{
int V_63 , V_4 ;
int V_7 ;
unsigned char V_72 [ 6 ] ;
unsigned char V_73 ;
V_73 = ( V_22 & 0x07 ) | 0x10 ;
V_72 [ 0 ] = V_3 ;
V_72 [ 1 ] = V_73 ;
for ( V_7 = 0 ; V_7 < V_22 ; V_7 ++ )
V_72 [ V_7 + 2 ] = V_9 [ V_7 ] ;
for ( V_4 = 5 ; ; ) {
V_63 = F_27 ( V_6 -> V_16 ,
F_28 ( V_6 -> V_16 , 1 ) ,
V_74 ,
V_75 | V_76 |
V_77 , 0 ,
( V_78 ) V_64 , V_72 ,
V_22 + 2 , V_79 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_14 ( V_6 , V_65 ,
( V_22 & 0x07 ) | 0x10 ) ;
if ( V_63 < 0 )
return V_63 ;
do {
V_63 = F_25 ( V_6 , V_65 ) ;
} while ( V_63 > 0 && ( ( V_63 & 0x10 ) != 0 ) );
if ( V_63 < 0 )
return V_63 ;
if ( ( V_63 & 0x20 ) == 0 )
break;
F_14 ( V_6 , V_65 , 0x00 ) ;
if ( -- V_4 < 0 )
return - 1 ;
}
if ( V_70 & V_10 ) {
int V_71 ;
for ( V_71 = 0 ; V_71 < V_22 ; V_71 ++ )
F_5 ( V_10 , L_17 , ( unsigned char ) V_9 [ V_71 ] , V_3 ) ;
}
return V_22 ;
}
static int F_3 ( struct V_5 * V_6 , unsigned char V_3 , char * V_9 ,
short V_22 )
{
char * V_80 = V_9 ;
int V_81 ;
int V_82 = 0 ;
int V_83 ;
int V_84 = 4 ;
while ( V_22 > 0 ) {
V_83 = ( V_22 > V_84 ) ? V_84 : V_22 ;
V_81 = F_26 ( V_6 , V_3 , V_80 , V_83 ) ;
if ( V_81 > 0 ) {
V_22 -= V_83 ;
V_80 += V_83 ;
V_82 += V_83 ;
} else
return ( V_81 < 0 ) ? V_81 : - V_85 ;
}
return V_82 ;
}
static int F_7 ( struct V_5 * V_6 , unsigned char V_3 , char * V_9 ,
short V_22 )
{
char V_86 [ 4 ] ;
int V_81 , V_7 ;
int V_87 = 0 ;
int V_83 ;
while ( V_22 > 0 ) {
V_83 = ( V_22 > 3 ) ? 4 : V_22 ;
V_81 = F_24 ( V_6 , V_3 , V_86 , V_83 ) ;
if ( V_81 > 0 ) {
for ( V_7 = 0 ; V_7 < V_22 ; V_7 ++ )
V_9 [ V_87 + V_7 ] = V_86 [ V_7 ] ;
V_22 -= V_83 ;
V_87 += V_83 ;
} else
return ( V_81 < 0 ) ? V_81 : - V_85 ;
}
return V_87 ;
}
