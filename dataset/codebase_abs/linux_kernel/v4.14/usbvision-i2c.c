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
V_3 = ( V_12 -> V_3 << 1 ) ;
if ( V_14 & V_15 )
V_3 |= 1 ;
V_13 [ 0 ] = V_3 ;
if ( V_14 & V_15 )
V_8 = F_6 ( V_2 , V_3 , V_4 ) ;
else
V_8 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_8 != 1 )
return - V_16 ;
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 , struct V_11 V_17 [] , int V_18 )
{
struct V_11 * V_19 ;
struct V_5 * V_6 ;
int V_7 , V_8 ;
unsigned char V_3 = 0 ;
V_6 = (struct V_5 * ) F_2 ( V_2 ) ;
for ( V_7 = 0 ; V_7 < V_18 ; V_7 ++ ) {
V_19 = & V_17 [ V_7 ] ;
V_8 = F_8 ( V_2 , V_19 , V_2 -> V_4 , & V_3 ) ;
if ( V_8 != 0 ) {
F_5 ( V_10 , L_3 , V_7 ) ;
return ( V_8 < 0 ) ? V_8 : - V_16 ;
}
if ( V_19 -> V_14 & V_15 ) {
V_8 = ( F_7 ( V_6 , V_3 , V_19 -> V_9 , V_19 -> V_20 ) ) ;
if ( V_8 < V_19 -> V_20 )
return ( V_8 < 0 ) ? V_8 : - V_16 ;
} else {
V_8 = ( F_3 ( V_6 , V_3 , V_19 -> V_9 , V_19 -> V_20 ) ) ;
if ( V_8 < V_19 -> V_20 )
return ( V_8 < 0 ) ? V_8 : - V_16 ;
}
}
return V_18 ;
}
static T_1 F_10 ( struct V_1 * V_21 )
{
return V_22 | V_23 ;
}
int F_11 ( struct V_5 * V_6 )
{
static unsigned short V_24 [] = {
0x4a >> 1 , 0x48 >> 1 ,
0x42 >> 1 , 0x40 >> 1 ,
V_25 } ;
if ( V_6 -> V_26 )
return 0 ;
V_6 -> V_2 = V_27 ;
snprintf ( V_6 -> V_2 . V_28 , sizeof( V_6 -> V_2 . V_28 ) ,
L_4 ,
V_6 -> V_29 -> V_30 -> V_31 , V_6 -> V_29 -> V_32 ) ;
F_5 ( V_10 , L_5 , V_6 -> V_2 . V_28 ) ;
V_6 -> V_2 . V_29 . V_33 = & V_6 -> V_29 -> V_29 ;
F_12 ( & V_6 -> V_2 , & V_6 -> V_34 ) ;
if ( F_13 ( V_6 , V_35 , V_36 ) < 0 ) {
F_14 ( V_37 L_6 ) ;
return - V_38 ;
}
F_5 ( V_10 , L_7 ) ;
F_5 ( V_10 , L_8 ) ;
V_6 -> V_2 . V_39 = & V_40 ;
V_6 -> V_2 . V_41 = 100 ;
V_6 -> V_2 . V_4 = 3 ;
F_15 ( & V_6 -> V_2 ) ;
F_5 ( V_10 , L_9 , V_6 -> V_2 . V_28 ) ;
switch ( V_42 [ V_6 -> V_43 ] . V_44 ) {
case V_45 :
case V_46 :
F_16 ( 10 ) ;
F_17 ( & V_6 -> V_34 ,
& V_6 -> V_2 ,
L_10 , 0 , V_24 ) ;
break;
}
if ( V_42 [ V_6 -> V_43 ] . V_47 == 1 ) {
struct V_48 * V_49 ;
enum V_50 type ;
struct V_51 V_52 ;
V_49 = F_17 ( & V_6 -> V_34 ,
& V_6 -> V_2 ,
L_11 , 0 , F_18 ( V_53 ) ) ;
type = V_49 ? V_54 : V_55 ;
V_49 = F_17 ( & V_6 -> V_34 ,
& V_6 -> V_2 ,
L_11 , 0 , F_18 ( type ) ) ;
if ( V_49 == NULL )
return - V_56 ;
if ( V_6 -> V_57 != - 1 ) {
V_52 . V_58 = V_59 | V_60 ;
V_52 . type = V_6 -> V_57 ;
V_52 . V_3 = F_19 ( V_49 ) ;
F_20 ( V_6 , V_47 , V_61 , & V_52 ) ;
}
}
V_6 -> V_26 = 1 ;
return 0 ;
}
int F_21 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_26 )
return 0 ;
F_22 ( & ( V_6 -> V_2 ) ) ;
V_6 -> V_26 = 0 ;
F_5 ( V_10 , L_12 , V_6 -> V_2 . V_28 ) ;
return 0 ;
}
static int
F_23 ( struct V_5 * V_6 , unsigned char V_3 ,
char * V_9 , short V_20 )
{
int V_62 , V_4 ;
for ( V_4 = 5 ; ; ) {
V_62 = F_13 ( V_6 , V_63 , V_3 ) ;
if ( V_62 < 0 )
return V_62 ;
V_62 = F_13 ( V_6 , V_64 ,
( V_20 & 0x07 ) | 0x18 ) ;
if ( V_62 < 0 )
return V_62 ;
do {
V_62 = F_24 ( V_6 , V_64 ) ;
} while ( V_62 > 0 && ( ( V_62 & 0x10 ) != 0 ) );
if ( V_62 < 0 )
return V_62 ;
if ( ( V_62 & 0x20 ) == 0 )
break;
V_62 = F_13 ( V_6 , V_64 , 0x00 ) ;
if ( V_62 < 0 )
return V_62 ;
if ( -- V_4 < 0 )
return - 1 ;
}
switch ( V_20 ) {
case 4 :
V_9 [ 3 ] = F_24 ( V_6 , V_65 ) ;
case 3 :
V_9 [ 2 ] = F_24 ( V_6 , V_66 ) ;
case 2 :
V_9 [ 1 ] = F_24 ( V_6 , V_67 ) ;
case 1 :
V_9 [ 0 ] = F_24 ( V_6 , V_68 ) ;
break;
default:
F_14 ( V_37
L_13 ) ;
}
if ( V_69 & V_10 ) {
int V_70 ;
for ( V_70 = 0 ; V_70 < V_20 ; V_70 ++ )
F_5 ( V_10 , L_14 , ( unsigned char ) V_9 [ V_70 ] , V_3 ) ;
}
return V_20 ;
}
static int F_25 ( struct V_5 * V_6 ,
unsigned char V_3 , const char * V_9 ,
short V_20 )
{
int V_62 , V_4 ;
int V_7 ;
unsigned char * V_71 = V_6 -> V_72 ;
unsigned char V_73 ;
V_73 = ( V_20 & 0x07 ) | 0x10 ;
V_71 [ 0 ] = V_3 ;
V_71 [ 1 ] = V_73 ;
for ( V_7 = 0 ; V_7 < V_20 ; V_7 ++ )
V_71 [ V_7 + 2 ] = V_9 [ V_7 ] ;
for ( V_4 = 5 ; ; ) {
V_62 = F_26 ( V_6 -> V_29 ,
F_27 ( V_6 -> V_29 , 1 ) ,
V_74 ,
V_75 | V_76 |
V_77 , 0 ,
( V_78 ) V_63 , V_71 ,
V_20 + 2 , V_79 ) ;
if ( V_62 < 0 )
return V_62 ;
V_62 = F_13 ( V_6 , V_64 ,
( V_20 & 0x07 ) | 0x10 ) ;
if ( V_62 < 0 )
return V_62 ;
do {
V_62 = F_24 ( V_6 , V_64 ) ;
} while ( V_62 > 0 && ( ( V_62 & 0x10 ) != 0 ) );
if ( V_62 < 0 )
return V_62 ;
if ( ( V_62 & 0x20 ) == 0 )
break;
F_13 ( V_6 , V_64 , 0x00 ) ;
if ( -- V_4 < 0 )
return - 1 ;
}
if ( V_69 & V_10 ) {
int V_70 ;
for ( V_70 = 0 ; V_70 < V_20 ; V_70 ++ )
F_5 ( V_10 , L_15 , ( unsigned char ) V_9 [ V_70 ] , V_3 ) ;
}
return V_20 ;
}
static int F_3 ( struct V_5 * V_6 , unsigned char V_3 , char * V_9 ,
short V_20 )
{
char * V_80 = V_9 ;
int V_81 ;
int V_82 = 0 ;
int V_83 ;
int V_84 = 4 ;
while ( V_20 > 0 ) {
V_83 = ( V_20 > V_84 ) ? V_84 : V_20 ;
V_81 = F_25 ( V_6 , V_3 , V_80 , V_83 ) ;
if ( V_81 > 0 ) {
V_20 -= V_83 ;
V_80 += V_83 ;
V_82 += V_83 ;
} else
return ( V_81 < 0 ) ? V_81 : - V_85 ;
}
return V_82 ;
}
static int F_7 ( struct V_5 * V_6 , unsigned char V_3 , char * V_9 ,
short V_20 )
{
char V_86 [ 4 ] ;
int V_81 , V_7 ;
int V_87 = 0 ;
int V_83 ;
while ( V_20 > 0 ) {
V_83 = ( V_20 > 3 ) ? 4 : V_20 ;
V_81 = F_23 ( V_6 , V_3 , V_86 , V_83 ) ;
if ( V_81 > 0 ) {
for ( V_7 = 0 ; V_7 < V_20 ; V_7 ++ )
V_9 [ V_87 + V_7 ] = V_86 [ V_7 ] ;
V_20 -= V_83 ;
V_87 += V_83 ;
} else
return ( V_81 < 0 ) ? V_81 : - V_85 ;
}
return V_87 ;
}
