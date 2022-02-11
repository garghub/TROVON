static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char V_7 [ 2 ] = { 0x21 , 0xC0 } ;
unsigned char V_8 [ 2 ] = { 0x21 , 0x00 } ;
unsigned char * V_9 ;
if ( V_3 ) {
V_9 = V_7 ;
F_2 ( & V_5 -> V_10 , V_9 , 2 ) ;
F_3 ( 20 ) ;
} else {
V_9 = V_8 ;
F_2 ( & V_5 -> V_10 , V_9 , 2 ) ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char V_7 [ 2 ] = { 0x45 , 0xc1 } ;
unsigned char V_8 [ 2 ] = { 0x46 , 0x00 } ;
unsigned char V_11 [ 3 ] = { 0x45 , 0x01 , 0x00 } ;
unsigned char * V_9 ;
if ( V_3 ) {
V_9 = V_7 ;
F_2 ( & V_5 -> V_10 , V_9 , 2 ) ;
F_3 ( 20 ) ;
} else {
V_9 = V_8 ;
F_5 ( & V_5 -> V_10 , V_9 , 1 , & V_9 [ 1 ] , 1 ) ;
V_11 [ 2 ] = V_9 [ 1 ] ;
V_11 [ 2 ] &= ~ 0x04 ;
F_2 ( & V_5 -> V_10 , V_11 , 3 ) ;
F_3 ( 5 ) ;
V_9 [ 1 ] |= 0x04 ;
F_2 ( & V_5 -> V_10 , V_9 , 2 ) ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
char * V_14 ;
if ( V_13 -> V_15 & V_16 ) {
V_5 -> V_17 = 0x01 ;
V_14 = L_1 ;
} else if ( V_13 -> V_15 & V_18 ) {
V_5 -> V_17 = 0x02 ;
V_14 = L_2 ;
} else if ( V_13 -> V_15 & V_19 ) {
V_5 -> V_17 = 0x04 ;
V_14 = L_3 ;
} else if ( V_13 -> V_15 & V_20 ) {
V_5 -> V_17 = 0x08 ;
V_14 = L_4 ;
} else if ( V_13 -> V_15 & V_21 ) {
V_5 -> V_17 = 0x10 ;
V_14 = L_5 ;
} else if ( V_13 -> V_15 & V_22 ) {
V_5 -> V_17 = 0x20 ;
V_14 = L_6 ;
} else if ( V_13 -> V_15 & V_23 ) {
V_5 -> V_17 = 0x40 ;
V_14 = L_7 ;
} else {
V_5 -> V_17 = 0x10 ;
V_14 = L_8 ;
}
if ( V_13 -> V_14 == V_24 ) {
V_5 -> V_17 = ( V_5 -> V_25 & V_26 ) ? 0x80 : 0x01 ;
F_7 ( L_9 ) ;
} else {
F_7 ( L_10 , V_14 ) ;
}
}
static void F_8 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char V_27 [] = { 0x00 , 0x00 } ;
unsigned char V_28 [] = { 0x01 , V_5 -> V_17 } ;
unsigned char V_29 [] = { 0x01 , 0x80 } ;
unsigned char V_30 [] = { 0x02 , 0x00 } ;
unsigned char V_31 [] = { 0x28 , 0x14 } ;
unsigned char V_32 [] = { 0x0f , 0x88 } ;
unsigned char V_33 [] = { 0x05 , 0x04 } ;
unsigned char V_34 [] = { 0x05 , 0x02 } ;
unsigned char V_35 [] = { 0x05 , 0x01 } ;
unsigned char V_36 [] = { 0x0d , 0x47 } ;
unsigned char V_37 [] = { 0x0d , 0x27 } ;
unsigned char V_38 [] = { 0x28 , 0x64 } ;
unsigned char V_39 [] = { 0x0e , 0x0b } ;
unsigned char V_40 [] = { 0x0e , 0x09 } ;
unsigned char V_41 [] = { 0x0f , 0x81 } ;
unsigned char V_42 = 0x1a ;
unsigned char V_43 = 0x1d ;
unsigned char V_44 = 0x1b ;
unsigned char V_45 , V_46 ,
V_47 ;
int V_48 ;
F_6 ( V_2 , V_13 ) ;
if ( V_5 -> V_49 . V_50 )
F_7 ( L_11 , V_5 -> V_49 . V_50 ) ;
F_2 ( & V_5 -> V_10 , V_28 , 2 ) ;
F_2 ( & V_5 -> V_10 , V_30 , 2 ) ;
F_2 ( & V_5 -> V_10 , V_27 , 2 ) ;
F_3 ( 1 ) ;
if ( V_13 -> V_14 == V_24 ) {
unsigned char V_51 [] = { 0x13 , 1 } ;
if ( V_52 )
V_51 [ 1 ] = 2 ;
for ( V_48 = 0 ; V_48 < F_9 ( V_53 ) ; V_48 ++ )
F_2 ( & V_5 -> V_10 , V_53 [ V_48 ] . V_54 , 2 ) ;
F_2 ( & V_5 -> V_10 , V_51 , 2 ) ;
} else {
V_29 [ 1 ] = V_5 -> V_17 + 0x80 ;
F_2 ( & V_5 -> V_10 , V_29 , 2 ) ;
F_2 ( & V_5 -> V_10 , V_31 , 2 ) ;
F_2 ( & V_5 -> V_10 , V_32 , 2 ) ;
if ( V_5 -> V_17 & 0x60 )
F_2 ( & V_5 -> V_10 , V_34 , 2 ) ;
else
F_2 ( & V_5 -> V_10 , V_33 , 2 ) ;
F_2 ( & V_5 -> V_10 , V_36 , 2 ) ;
}
F_1 ( V_2 , 1 ) ;
if ( V_2 -> V_55 . V_56 . V_57 )
V_2 -> V_55 . V_56 . V_57 ( V_2 , V_13 ) ;
for ( V_48 = 0 ; V_48 < 3 ; V_48 ++ ) {
F_5 ( & V_5 -> V_10 ,
& V_44 , 1 , & V_47 , 1 ) ;
if ( V_47 & 0x80 ) {
F_5 ( & V_5 -> V_10 ,
& V_42 , 1 ,
& V_45 , 1 ) ;
F_5 ( & V_5 -> V_10 ,
& V_43 , 1 ,
& V_46 , 1 ) ;
F_7 ( L_12 , V_46 ) ;
break;
} else {
F_7 ( L_13 ) ;
F_3 ( 100 ) ;
}
}
if ( ( V_46 > 115 ) || ( ! ( V_47 & 0x80 ) && ( V_45 < 20 ) ) ) {
F_7 ( L_14 ,
V_46 , V_45 , V_47 & 0x80 ) ;
F_2 ( & V_5 -> V_10 , V_38 , 2 ) ;
F_3 ( 100 ) ;
F_5 ( & V_5 -> V_10 ,
& V_43 , 1 , & V_46 , 1 ) ;
F_5 ( & V_5 -> V_10 ,
& V_44 , 1 , & V_47 , 1 ) ;
if ( ( V_46 > 115 ) || ! ( V_47 & 0x80 ) ) {
F_7 ( L_15 ,
V_46 , V_47 & 0x80 ) ;
if ( V_5 -> V_49 . V_58 )
V_5 -> V_49 . V_58 ( V_2 ) ;
F_3 ( 100 ) ;
F_5 ( & V_5 -> V_10 ,
& V_43 , 1 ,
& V_46 , 1 ) ;
F_5 ( & V_5 -> V_10 ,
& V_44 , 1 ,
& V_47 , 1 ) ;
if( ( V_46 > 115 ) || ! ( V_47 & 0x80 ) ) {
F_7 ( L_16 , V_46 ) ;
F_2 ( & V_5 -> V_10 , V_35 , 2 ) ;
F_2 ( & V_5 -> V_10 , V_37 , 2 ) ;
F_3 ( 100 ) ;
}
}
}
if( V_5 -> V_17 & 0x60 ) {
F_5 ( & V_5 -> V_10 ,
& V_42 , 1 ,
& V_45 , 1 ) ;
F_5 ( & V_5 -> V_10 ,
& V_44 , 1 ,
& V_47 , 1 ) ;
if ( ( V_45 > 20 ) || ! ( V_47 & 0x80 ) ) {
F_7 ( L_17 ) ;
F_2 ( & V_5 -> V_10 , V_39 , 2 ) ;
F_3 ( 40 ) ;
F_2 ( & V_5 -> V_10 , V_40 , 2 ) ;
}
}
F_1 ( V_2 , 0 ) ;
F_2 ( & V_5 -> V_10 , V_41 , 2 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_7 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char V_11 [] = { 0x30 , 0x00 } ;
F_5 ( & V_5 -> V_10 , & V_11 [ 0 ] , 1 , & V_11 [ 1 ] , 1 ) ;
if ( V_7 )
V_11 [ 1 ] = 0x01 ;
else
V_11 [ 1 ] = 0x03 ;
F_2 ( & V_5 -> V_10 , V_11 , 2 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_7 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char V_11 [] = { 0x01 , 0x00 } ;
F_5 ( & V_5 -> V_10 , & V_11 [ 0 ] , 1 , & V_11 [ 1 ] , 1 ) ;
if ( V_7 )
V_11 [ 1 ] = 0x01 ;
else
V_11 [ 1 ] = 0x00 ;
F_2 ( & V_5 -> V_10 , V_11 , 2 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char V_11 [] = { 0x00 , V_5 -> V_17 } ;
F_2 ( & V_5 -> V_10 , V_11 , 2 ) ;
F_11 ( V_2 , 1 ) ;
F_3 ( 20 ) ;
F_11 ( V_2 , 0 ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_7 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char V_11 [] = { 0x02 , 0x00 } ;
F_5 ( & V_5 -> V_10 , & V_11 [ 0 ] , 1 , & V_11 [ 1 ] , 1 ) ;
if ( V_7 )
V_11 [ 1 ] &= ~ 0x40 ;
else
V_11 [ 1 ] |= 0x40 ;
F_2 ( & V_5 -> V_10 , V_11 , 2 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_7 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char V_59 [] = { 0x44 , 0x00 } ;
unsigned char V_60 [] = { 0x46 , 0x00 } ;
F_5 ( & V_5 -> V_10 ,
& V_59 [ 0 ] , 1 , & V_59 [ 1 ] , 1 ) ;
F_5 ( & V_5 -> V_10 ,
& V_60 [ 0 ] , 1 , & V_60 [ 1 ] , 1 ) ;
V_59 [ 1 ] &= 0xf0 ;
if ( V_7 ) {
V_59 [ 1 ] |= 0x01 ;
V_60 [ 1 ] &= 0xfe ;
}
F_2 ( & V_5 -> V_10 , V_59 , 2 ) ;
F_2 ( & V_5 -> V_10 , V_60 , 2 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char V_61 = 0x26 ;
unsigned char V_62 ;
F_5 ( & V_5 -> V_10 , & V_61 , 1 , & V_62 , 1 ) ;
return ( V_62 & 0x01 ) ? 65535 : 0 ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char V_63 [] = { 0x1d , 0x00 } ;
F_6 ( V_2 , V_13 ) ;
F_7 ( L_18 , V_64 , V_13 -> V_65 ) ;
F_10 ( V_2 , 1 ) ;
F_13 ( V_2 , 1 ) ;
F_5 ( & V_5 -> V_10 ,
& V_63 [ 0 ] , 1 , & V_63 [ 1 ] , 1 ) ;
F_12 ( V_2 ) ;
V_63 [ 1 ] = 0x03 ;
F_2 ( & V_5 -> V_10 , V_63 , 2 ) ;
F_3 ( 20 ) ;
F_4 ( V_2 , 1 ) ;
if ( V_2 -> V_55 . V_56 . V_57 )
V_2 -> V_55 . V_56 . V_57 ( V_2 , V_13 ) ;
if ( V_5 -> V_49 . V_58 )
V_5 -> V_49 . V_58 ( V_2 ) ;
if ( F_15 ( V_2 ) )
F_7 ( L_19 ) ;
else
F_7 ( L_20 ) ;
F_4 ( V_2 , 0 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char V_66 [ 1 ] = { 0x1B } ;
unsigned char V_67 = 0 ;
F_5 ( & V_5 -> V_10 ,
V_66 , F_9 ( V_66 ) , & V_67 , 1 ) ;
return ( V_67 & 0x80 ) ? 65535 : 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char V_68 [] = { 0x30 , 0xD0 } ;
unsigned char F_18 [] = { 0x00 , 0x02 } ;
unsigned char V_69 [] = { 0x02 , 0x20 } ;
struct V_70 V_9 = { . V_71 = V_5 -> V_72 , . V_73 = 0 , . V_11 = V_68 , . V_74 = 2 } ;
F_1 ( V_2 , 1 ) ;
if ( V_5 -> V_25 & V_75 )
V_68 [ 1 ] = 0x90 ;
F_19 ( V_5 -> V_10 . V_76 , & V_9 , 1 ) ;
F_1 ( V_2 , 0 ) ;
F_2 ( & V_5 -> V_10 , V_69 , 2 ) ;
F_2 ( & V_5 -> V_10 , F_18 , 2 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_13 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char V_77 [] = { 0x30 , 0x6F } ;
unsigned char V_78 [] = { 0x20 , 0x01 } ;
unsigned char V_79 [] = { 0x20 , 0x0B } ;
if ( ( V_5 -> V_49 . V_50 == 1 ) || ( V_5 -> V_49 . V_50 == 2 ) )
F_2 ( & V_5 -> V_10 , V_78 , 2 ) ;
else
F_2 ( & V_5 -> V_10 , V_79 , 2 ) ;
F_2 ( & V_5 -> V_10 , V_77 , 2 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
static unsigned char V_80 [] = { 0x33 , 0x14 } ;
static unsigned char V_81 [] = { 0x34 , 0x00 } ;
static unsigned char V_82 [] = { 0x3e , 0x63 } ;
static unsigned char V_83 [] = { 0x38 , 0x23 } ;
static unsigned char V_84 [] = { 0x3f , 0x01 } ;
static unsigned char V_85 [] = { 0x42 , 0x61 } ;
static unsigned char V_86 [] = { 0x44 , 0x0b } ;
F_10 ( V_2 , 1 ) ;
F_11 ( V_2 , 0 ) ;
F_12 ( V_2 ) ;
F_2 ( & V_5 -> V_10 , V_80 , 2 ) ;
F_2 ( & V_5 -> V_10 , V_81 , 2 ) ;
F_2 ( & V_5 -> V_10 , V_82 , 2 ) ;
F_2 ( & V_5 -> V_10 , V_83 , 2 ) ;
F_2 ( & V_5 -> V_10 , V_84 , 2 ) ;
F_2 ( & V_5 -> V_10 , V_85 , 2 ) ;
F_2 ( & V_5 -> V_10 , V_86 , 2 ) ;
F_13 ( V_2 , 0 ) ;
F_14 ( V_2 , 0 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char V_87 [] = { 0x00 , 0x00 , 0x00 , 0x40 , 0xdC , 0x04 , 0xAf ,
0x3F , 0x2A , 0x04 , 0xFF , 0x00 , 0x00 , 0x40 } ;
unsigned char V_88 [] = { 0x00 , 0x00 , 0x00 , 0x00 , 0xdC , 0x05 , 0x8b ,
0x0c , 0x04 , 0x20 , 0xFF , 0x00 , 0x00 , 0x4b } ;
struct V_70 V_9 = { . V_71 = V_5 -> V_72 , . V_73 = 0 ,
. V_11 = V_87 , . V_74 = 14 } ;
if ( V_5 -> V_25 & V_75 )
V_9 . V_11 = V_88 ;
F_1 ( V_2 , 1 ) ;
F_19 ( V_5 -> V_10 . V_76 , & V_9 , 1 ) ;
F_1 ( V_2 , 0 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_25 & ( V_89 | V_90 | V_75 ) )
if ( V_2 -> V_55 . V_56 . V_91 )
V_2 -> V_55 . V_56 . V_91 ( V_2 ) ;
F_25 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_92 * V_93 = & V_2 -> V_55 . V_93 ;
int V_48 , V_62 , V_94 ;
T_1 V_95 ;
T_2 V_96 ;
struct V_70 V_9 = { . V_73 = V_97 , . V_11 = & V_96 , . V_74 = 1 } ;
if ( ! V_93 -> V_98 ) {
F_27 ( V_99 L_21 ) ;
return - V_100 ;
}
V_93 -> V_98 ( V_2 , 1 ) ;
V_94 = 0 ;
V_95 = 0 ;
for ( V_48 = 0x60 ; V_48 <= 0x63 ; V_48 ++ ) {
V_9 . V_71 = V_48 ;
V_62 = F_19 ( V_5 -> V_10 . V_76 , & V_9 , 1 ) ;
if ( V_62 == 1 ) {
V_94 ++ ;
V_95 = ( V_95 << 8 ) + V_48 ;
}
}
V_93 -> V_98 ( V_2 , 0 ) ;
if ( V_94 > 1 )
for ( V_48 = 0 ; V_48 < V_94 ; V_48 ++ ) {
V_9 . V_71 = V_95 & 0xff ;
V_62 = F_19 ( V_5 -> V_10 . V_76 , & V_9 , 1 ) ;
if ( V_62 == 1 )
V_95 = V_95 >> 8 ;
else
break;
}
if ( V_95 == 0 ) {
V_95 = 0x60 ;
F_28 ( L_22
L_23 , V_95 ) ;
} else {
V_95 = V_95 & 0xff ;
F_28 ( L_24 , V_95 ) ;
}
V_5 -> V_72 = V_95 ;
V_9 . V_71 = V_95 ;
V_93 -> V_98 ( V_2 , 1 ) ;
V_62 = F_19 ( V_5 -> V_10 . V_76 , & V_9 , 1 ) ;
if ( V_62 != 1 ) {
F_29 ( L_25 ) ;
V_93 -> V_98 ( V_2 , 0 ) ;
return - V_101 ;
}
if ( ( V_96 == 0x83 ) || ( V_96 == 0x84 ) ) {
V_5 -> V_25 |= V_89 ;
V_102 . V_50 = V_5 -> V_49 . V_50 ;
F_30 ( V_103 , V_2 , V_5 -> V_72 ,
V_5 -> V_10 . V_76 , & V_102 ) ;
} else {
if ( ( V_96 & 0x3c ) == 0 )
V_5 -> V_25 |= V_90 ;
else
V_5 -> V_25 |= V_75 ;
F_30 ( V_104 , V_2 , V_5 -> V_72 ,
V_5 -> V_10 . V_76 , & V_5 -> V_49 ) ;
V_5 -> V_49 . V_105 = V_5 -> V_10 . V_71 ;
}
if ( V_2 -> V_55 . V_56 . V_106 )
V_2 -> V_55 . V_56 . V_106 ( V_2 ) ;
if ( V_2 -> V_55 . V_56 . V_107 )
V_2 -> V_55 . V_56 . V_107 ( V_2 ) ;
V_93 -> V_98 ( V_2 , 0 ) ;
return 0 ;
}
static int F_31 ( struct V_108 * V_10 )
{
#define F_32 0x89
T_2 V_109 = 0x1f , V_110 ;
struct V_70 V_111 [] = {
{ . V_71 = V_10 -> V_71 , . V_73 = 0 , . V_74 = 1 , . V_11 = & V_109 } ,
{ . V_71 = V_10 -> V_71 , . V_73 = V_97 , . V_74 = 1 , . V_11 = & V_110 } ,
} ;
if ( F_19 ( V_10 -> V_76 , V_111 , 2 ) != 2 ) {
F_27 ( V_112 L_26 ,
V_64 , V_109 ) ;
return - V_113 ;
}
if ( V_110 == F_32 ) {
if ( V_114 )
F_27 ( V_115 L_27 ,
V_64 , F_33 ( V_10 -> V_76 ) ,
V_10 -> V_71 ) ;
return 0 ;
}
return - V_113 ;
}
static int F_34 ( struct V_108 * V_10 )
{
#define F_35 0x8a
#define F_36 0x8b
T_2 V_109 = 0x2f , V_110 ;
struct V_70 V_111 [] = {
{ . V_71 = V_10 -> V_71 , . V_73 = 0 , . V_74 = 1 , . V_11 = & V_109 } ,
{ . V_71 = V_10 -> V_71 , . V_73 = V_97 , . V_74 = 1 , . V_11 = & V_110 } ,
} ;
if ( F_19 ( V_10 -> V_76 , V_111 , 2 ) != 2 ) {
F_27 ( V_112 L_26 ,
V_64 , V_109 ) ;
return - V_113 ;
}
if ( ( V_110 & 0xfe ) == F_35 ) {
if ( V_114 )
F_27 ( V_115 L_28 ,
V_64 , ( V_110 == F_35 ) ?
L_29 : L_30 ,
F_33 ( V_10 -> V_76 ) ,
V_10 -> V_71 ) ;
return 0 ;
}
return - V_113 ;
}
struct V_1 * F_37 ( struct V_1 * V_2 ,
struct V_116 * V_117 , T_2 V_118 ,
struct V_119 * V_49 )
{
struct V_4 * V_5 = NULL ;
char * V_120 ;
V_5 = F_38 ( sizeof( struct V_4 ) , V_121 ) ;
if ( V_5 == NULL )
return NULL ;
V_2 -> V_6 = V_5 ;
V_5 -> V_10 . V_71 = V_118 ;
V_5 -> V_10 . V_76 = V_117 ;
V_5 -> V_10 . V_120 = L_31 ;
if ( V_49 )
V_5 -> V_49 . V_50 = V_49 -> V_122 ;
if ( F_31 ( & V_5 -> V_10 ) == 0 ) {
V_5 -> V_25 = V_123 ;
memcpy ( & V_2 -> V_55 . V_93 , & V_124 ,
sizeof( struct V_92 ) ) ;
}
if ( F_34 ( & V_5 -> V_10 ) == 0 ) {
V_5 -> V_25 = V_26 ;
memcpy ( & V_2 -> V_55 . V_93 , & V_125 ,
sizeof( struct V_92 ) ) ;
}
if ( ! ( V_49 ) || ( V_126 == V_49 -> V_127 ) ) {
F_10 ( V_2 , 1 ) ;
if ( F_26 ( V_2 ) < 0 )
goto V_128;
}
switch ( V_5 -> V_25 ) {
case V_123 :
V_120 = L_32 ;
break;
case V_26 :
V_120 = L_33 ;
break;
case V_123 | V_90 :
V_120 = L_34 ;
break;
case V_26 | V_90 :
V_120 = L_35 ;
break;
case V_123 | V_75 :
V_120 = L_36 ;
break;
case V_26 | V_75 :
V_120 = L_37 ;
break;
case V_123 | V_89 :
V_120 = L_38 ;
break;
case V_26 | V_89 :
V_120 = L_39 ;
break;
default:
goto V_128;
}
F_28 ( L_40 , V_120 ) ;
V_2 -> V_55 . V_93 . V_129 . V_120 = V_120 ;
if ( V_5 -> V_25 & V_123 ) {
if ( V_5 -> V_25 & ( V_90 | V_75 ) )
F_23 ( V_2 ) ;
F_21 ( V_2 ) ;
} else if ( V_5 -> V_25 & V_26 )
F_22 ( V_2 ) ;
return V_2 ;
V_128:
memset ( & V_2 -> V_55 . V_93 , 0 , sizeof( struct V_92 ) ) ;
F_24 ( V_2 ) ;
return NULL ;
}
int F_39 ( struct V_116 * V_117 , T_2 V_118 )
{
struct V_108 V_10 = {
. V_76 = V_117 ,
. V_71 = V_118 ,
} ;
unsigned char V_27 [] = { 0x00 , 0x00 } ;
unsigned char V_130 [] = { 0x01 , 0x02 } ;
unsigned char V_131 [] = { 0x01 , 0x04 } ;
unsigned char V_132 [] = { 0x00 , 0xd6 , 0x30 } ;
unsigned char V_133 = 0x07 ;
unsigned char V_96 ;
#define F_40 8
unsigned char V_11 [ F_40 ] ;
int V_48 ;
F_5 ( & V_10 ,
V_27 , 1 , V_11 , F_40 ) ;
for ( V_48 = 1 ; V_48 < F_40 ; V_48 ++ ) {
if ( V_11 [ V_48 ] != V_11 [ 0 ] )
break;
}
if ( V_48 == F_40 )
return - V_113 ;
if ( ( F_31 ( & V_10 ) == 0 ) ||
( F_34 ( & V_10 ) == 0 ) )
return 0 ;
F_2 ( & V_10 , V_130 , 2 ) ;
F_2 ( & V_10 , V_27 , 2 ) ;
F_5 ( & V_10 , & V_133 , 1 , & V_96 , 1 ) ;
if ( V_96 == 0 ) {
F_2 ( & V_10 , V_131 , 2 ) ;
F_2 ( & V_10 , V_27 , 2 ) ;
F_5 ( & V_10 ,
& V_133 , 1 , & V_96 , 1 ) ;
if ( V_96 == 0x7b ) {
return 0 ;
}
}
F_2 ( & V_10 , V_132 , 3 ) ;
return - V_113 ;
}
