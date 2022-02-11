static void F_1 ( struct V_1 * V_2 )
{
static const unsigned int V_3 [ 12 ] = {
- 0x526500 , - 0x221200 , 0x221200 , 0x526500 ,
- 0x3de200 , 0x3de200 ,
- 0x6db480 , - 0x2d5d00 , 0x2d5d00 , 0x6db480 ,
- 0x12c200 , 0x12c200
} ;
static const unsigned int V_4 [ 12 ] = {
0xa4ca , 0x4424 , - 0x4424 , - 0xa4ca ,
0x7bc4 , - 0x7bc4 ,
0xdb69 , 0x5aba , - 0x5aba , - 0xdb69 ,
0x2584 , - 0x2584
} ;
unsigned int V_5 [ 12 ] ;
int V_6 , V_7 ;
memcpy ( V_5 , V_3 , sizeof( V_3 ) ) ;
for ( V_6 = 0 ; V_6 < 256 ; V_6 ++ ) {
for ( V_7 = 0 ; V_7 < 12 ; V_7 ++ ) {
V_2 -> V_8 [ V_6 ] [ V_7 ] = V_5 [ V_7 ] ;
V_5 [ V_7 ] += V_4 [ V_7 ] ;
}
}
}
static void F_2 ( struct V_1 * V_2 )
{
unsigned char * V_9 ;
unsigned int V_10 , V_11 , V_12 , V_13 ;
unsigned int V_14 = 1 ;
for ( V_10 = 0 ; V_10 < 8 ; V_10 ++ ) {
V_12 = V_14 - 1 ;
V_9 = V_2 -> V_15 [ V_10 ] ;
for ( V_11 = 0 ; V_11 < 256 ; V_11 ++ ) {
V_13 = ( V_11 & V_12 ) ;
if ( V_11 & V_14 )
V_13 = - V_13 ;
* V_9 ++ = V_13 ;
}
V_14 <<= 1 ;
}
}
static void F_3 ( const unsigned int V_16 [ 16 ] [ 8 ] ,
unsigned char V_17 [ 16 ] [ 1024 ] ,
unsigned char V_18 [ 16 ] [ 256 ] )
{
int V_19 , V_7 , V_20 , V_10 , V_21 ;
unsigned char * V_22 , * V_23 ;
const unsigned int * V_24 ;
for ( V_19 = 0 ; V_19 < 16 ; V_19 ++ ) {
V_22 = V_17 [ V_19 ] ;
V_23 = V_18 [ V_19 ] ;
V_24 = V_16 [ V_19 ] ;
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ , V_24 ++ , V_22 += 128 ) {
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ ) {
if ( V_20 == 0 )
V_10 = 1 ;
else if ( V_20 >= 1 && V_20 < 3 )
V_10 = ( V_24 [ 0 ] >> 15 ) & 7 ;
else if ( V_20 >= 3 && V_20 < 6 )
V_10 = ( V_24 [ 0 ] >> 12 ) & 7 ;
else if ( V_20 >= 6 && V_20 < 10 )
V_10 = ( V_24 [ 0 ] >> 9 ) & 7 ;
else if ( V_20 >= 10 && V_20 < 13 )
V_10 = ( V_24 [ 0 ] >> 6 ) & 7 ;
else if ( V_20 >= 13 && V_20 < 15 )
V_10 = ( V_24 [ 0 ] >> 3 ) & 7 ;
else
V_10 = ( V_24 [ 0 ] ) & 7 ;
if ( V_20 == 0 )
* V_23 ++ = 8 ;
else
* V_23 ++ = V_7 - V_10 ;
* V_23 ++ = V_10 ;
V_21 = 1 << V_10 ;
V_22 [ V_20 + 0x00 ] = ( 1 * V_21 ) + 0x80 ;
V_22 [ V_20 + 0x10 ] = ( 2 * V_21 ) + 0x80 ;
V_22 [ V_20 + 0x20 ] = ( 3 * V_21 ) + 0x80 ;
V_22 [ V_20 + 0x30 ] = ( 4 * V_21 ) + 0x80 ;
V_22 [ V_20 + 0x40 ] = ( - 1 * V_21 ) + 0x80 ;
V_22 [ V_20 + 0x50 ] = ( - 2 * V_21 ) + 0x80 ;
V_22 [ V_20 + 0x60 ] = ( - 3 * V_21 ) + 0x80 ;
V_22 [ V_20 + 0x70 ] = ( - 4 * V_21 ) + 0x80 ;
}
}
}
}
static void F_4 ( struct V_1 * V_2 )
{
#define F_5 15
#define F_6 (1UL << (SCALEBITS - 1))
int V_6 ;
unsigned int V_25 = F_6 ;
unsigned int V_26 = 0x0000 ;
for ( V_6 = 0 ; V_6 < 256 ; V_6 ++ ) {
V_2 -> V_27 [ V_6 ] = V_25 & ~ ( F_6 ) ;
V_2 -> V_28 [ V_6 ] = V_26 ;
V_25 += 0x7bc4 ;
V_26 += 0x7bc4 ;
}
}
void F_7 ( struct V_29 * V_30 , const unsigned char * V_31 )
{
int V_32 , V_33 , V_34 , V_6 ;
struct V_1 * V_2 = & V_30 -> V_35 ;
F_8 ( & V_2 -> V_36 ) ;
if ( V_2 -> V_37 && V_2 -> V_38 == V_31 [ 2 ] )
return;
if ( F_9 ( V_30 -> type ) ) {
V_32 = V_31 [ 2 ] & 0x18 ;
if ( V_32 == 8 )
V_2 -> V_39 = 7 ;
else if ( V_32 == 0x10 )
V_2 -> V_39 = 8 ;
else
V_2 -> V_39 = 6 ;
V_33 = V_31 [ 2 ] >> 5 ;
F_3 ( V_40 [ V_33 ] [ 0 ] , V_2 -> V_41 , V_2 -> V_42 ) ;
F_3 ( V_40 [ V_33 ] [ 1 ] , V_2 -> V_43 , V_2 -> V_44 ) ;
} else {
V_32 = V_31 [ 2 ] & 6 ;
if ( V_32 == 2 )
V_2 -> V_39 = 7 ;
else if ( V_32 == 4 )
V_2 -> V_39 = 8 ;
else
V_2 -> V_39 = 6 ;
V_33 = V_31 [ 2 ] >> 3 ;
F_3 ( V_45 [ V_33 ] [ 0 ] , V_2 -> V_41 , V_2 -> V_42 ) ;
F_3 ( V_45 [ V_33 ] [ 1 ] , V_2 -> V_43 , V_2 -> V_44 ) ;
}
V_34 = 8 - V_2 -> V_39 ;
V_2 -> V_46 = F_5 - V_34 ;
V_2 -> V_47 = 0xFF >> V_34 ;
F_4 ( V_2 ) ;
F_1 ( V_2 ) ;
F_2 ( V_2 ) ;
#if V_48
for ( V_6 = 0 ; V_6 < V_49 ; V_6 ++ )
V_50 [ V_6 ] = 0 ;
for ( V_6 = 0 ; V_6 < 256 ; V_6 ++ )
V_50 [ V_49 + V_6 ] = V_6 ;
for ( V_6 = 0 ; V_6 < V_49 ; V_6 ++ )
V_50 [ V_49 + 256 + V_6 ] = 255 ;
#endif
V_2 -> V_38 = V_31 [ 2 ] ;
V_2 -> V_37 = 1 ;
}
static void F_10 ( const int * V_51 , unsigned char * V_52 , unsigned int V_53 , unsigned int V_46 )
{
#if V_54
const unsigned char * V_55 = V_50 + V_49 ;
const int * V_56 = V_51 ;
unsigned char * V_57 = V_52 ;
* V_57 ++ = V_55 [ V_56 [ 0 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 1 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 2 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 3 ] >> V_46 ] ;
V_57 = V_52 + V_53 ;
* V_57 ++ = V_55 [ V_56 [ 4 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 5 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 6 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 7 ] >> V_46 ] ;
V_57 = V_52 + V_53 * 2 ;
* V_57 ++ = V_55 [ V_56 [ 8 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 9 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 10 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 11 ] >> V_46 ] ;
V_57 = V_52 + V_53 * 3 ;
* V_57 ++ = V_55 [ V_56 [ 12 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 13 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 14 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 15 ] >> V_46 ] ;
#else
int V_6 ;
const int * V_56 = V_51 ;
unsigned char * V_57 = V_52 ;
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ , V_56 ++ )
* V_57 ++ = F_11 ( ( * V_56 ) >> V_46 ) ;
V_57 = V_52 + V_53 ;
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ , V_56 ++ )
* V_57 ++ = F_11 ( ( * V_56 ) >> V_46 ) ;
V_57 = V_52 + V_53 * 2 ;
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ , V_56 ++ )
* V_57 ++ = F_11 ( ( * V_56 ) >> V_46 ) ;
V_57 = V_52 + V_53 * 3 ;
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ , V_56 ++ )
* V_57 ++ = F_11 ( ( * V_56 ) >> V_46 ) ;
#endif
}
static void F_12 ( const int * V_51 , unsigned char * V_52 , unsigned int V_53 , unsigned int V_46 )
{
#if V_54
const unsigned char * V_55 = V_50 + V_49 ;
const int * V_56 = V_51 ;
unsigned char * V_57 = V_52 ;
* V_57 ++ = V_55 [ V_56 [ 0 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 4 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 1 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 5 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 2 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 6 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 3 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 7 ] >> V_46 ] ;
V_57 = V_52 + V_53 ;
* V_57 ++ = V_55 [ V_56 [ 12 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 8 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 13 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 9 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 14 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 10 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 15 ] >> V_46 ] ;
* V_57 ++ = V_55 [ V_56 [ 11 ] >> V_46 ] ;
#else
int V_6 ;
const int * V_58 = V_51 ;
const int * V_59 = V_51 + 4 ;
unsigned char * V_57 = V_52 ;
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ , V_58 ++ , V_59 ++ ) {
* V_57 ++ = F_11 ( ( * V_58 ) >> V_46 ) ;
* V_57 ++ = F_11 ( ( * V_59 ) >> V_46 ) ;
}
V_58 = V_51 + 12 ;
V_57 = V_52 + V_53 ;
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ , V_58 ++ , V_59 ++ ) {
* V_57 ++ = F_11 ( ( * V_58 ) >> V_46 ) ;
* V_57 ++ = F_11 ( ( * V_59 ) >> V_46 ) ;
}
#endif
}
static void F_13 ( struct V_1 * V_2 ,
const unsigned char * V_60 ,
const unsigned char * V_61 )
{
unsigned int V_62 ;
unsigned int V_63 , V_25 , V_64 ;
int V_6 ;
F_14 ( V_2 , 16 ) ;
F_15 ( V_2 , V_2 -> V_39 , V_62 ) ;
if ( F_16 ( V_2 , 2 ) == 0 ) {
F_17 ( V_2 , 2 ) ;
for ( V_6 = 0 ; V_6 < 16 ; V_6 ++ )
V_2 -> V_65 [ V_6 ] = V_2 -> V_27 [ V_62 ] ;
return;
}
for ( V_6 = 0 ; V_6 < 16 ; V_6 ++ )
V_2 -> V_65 [ V_6 ] = V_2 -> V_28 [ V_62 ] ;
F_15 ( V_2 , 3 , V_63 ) ;
V_63 = ( ( V_63 & 1 ) << 2 ) | ( V_63 & 2 ) | ( ( V_63 & 4 ) >> 2 ) ;
V_60 += ( V_63 * 128 ) ;
V_61 += ( V_63 * 32 ) ;
V_25 = 0 ;
do
{
unsigned int V_66 , V_67 = 0 ;
const unsigned int * V_68 ;
F_14 ( V_2 , 16 ) ;
V_66 = F_16 ( V_2 , 6 ) ;
V_64 = V_69 [ V_66 * 4 ] ;
if ( V_64 == 2 ) {
F_17 ( V_2 , 2 ) ;
} else if ( V_64 == 1 ) {
unsigned int V_12 , V_34 ;
unsigned int V_39 , V_70 ;
unsigned int V_71 ;
F_17 ( V_2 , 3 ) ;
F_15 ( V_2 , 4 , V_71 ) ;
V_25 += 1 + V_71 ;
V_25 &= 0x0F ;
V_39 = V_61 [ V_25 * 2 ] ;
F_15 ( V_2 , V_39 + 1 , V_70 ) ;
V_12 = V_2 -> V_15 [ V_39 ] [ V_70 ] ;
V_34 = V_61 [ V_25 * 2 + 1 ] ;
V_67 = ( ( V_12 << V_34 ) + 0x80 ) & 0xFF ;
V_68 = V_2 -> V_8 [ V_67 ] ;
for ( V_6 = 0 ; V_6 < 16 ; V_6 ++ )
V_2 -> V_65 [ V_6 ] += V_68 [ V_72 [ V_25 ] [ V_6 ] ] ;
} else {
unsigned int V_34 ;
V_25 += V_69 [ V_66 * 4 + 2 ] ;
V_25 &= 0x0F ;
V_67 = V_60 [ V_25 + V_69 [ V_66 * 4 + 3 ] ] ;
V_68 = V_2 -> V_8 [ V_67 ] ;
for ( V_6 = 0 ; V_6 < 16 ; V_6 ++ )
V_2 -> V_65 [ V_6 ] += V_68 [ V_72 [ V_25 ] [ V_6 ] ] ;
V_34 = V_69 [ V_66 * 4 + 1 ] ;
F_17 ( V_2 , V_34 ) ;
}
} while ( V_64 != 2 );
}
static void F_18 ( struct V_1 * V_2 ,
const unsigned char * V_73 ,
unsigned char * V_74 ,
unsigned char * V_75 ,
unsigned char * V_76 ,
unsigned int V_77 ,
unsigned int V_78 )
{
int V_79 , V_80 ;
const unsigned char * V_60 ;
const unsigned char * V_61 ;
V_2 -> V_81 = 0 ;
V_2 -> V_82 = 0 ;
V_2 -> V_83 = V_73 + 1 ;
F_19 ( V_2 , 4 , V_79 ) ;
V_80 = V_77 / 4 ;
V_60 = V_2 -> V_41 [ V_79 ] ;
V_61 = V_2 -> V_42 [ V_79 ] ;
while ( V_80 ) {
F_13 ( V_2 , V_60 , V_61 ) ;
F_10 ( V_2 -> V_65 , V_74 , V_78 , V_2 -> V_46 ) ;
V_74 += 4 ;
V_80 -- ;
}
V_80 = V_77 / 8 ;
V_60 = V_2 -> V_43 [ V_79 ] ;
V_61 = V_2 -> V_44 [ V_79 ] ;
while ( V_80 ) {
F_13 ( V_2 , V_60 , V_61 ) ;
F_12 ( V_2 -> V_65 , V_75 , V_78 / 2 , V_2 -> V_46 ) ;
F_13 ( V_2 , V_60 , V_61 ) ;
F_12 ( V_2 -> V_65 , V_76 , V_78 / 2 , V_2 -> V_46 ) ;
V_76 += 8 ;
V_75 += 8 ;
V_80 -= 2 ;
}
}
void F_20 ( struct V_29 * V_30 ,
const void * V_51 ,
void * V_52 )
{
int V_84 , V_85 ;
struct V_1 * V_2 = & V_30 -> V_35 ;
unsigned char * V_86 ;
unsigned char * V_87 ;
unsigned char * V_88 ;
unsigned int V_89 ;
F_21 ( & V_2 -> V_36 ) ;
V_84 = V_30 -> V_90 / 4 ;
V_85 = V_30 -> V_91 * 4 ;
V_89 = V_30 -> V_90 * V_30 -> V_91 ;
V_86 = V_52 ;
V_87 = V_52 + V_89 ;
V_88 = V_52 + V_89 + V_89 / 4 ;
while ( V_84 -- ) {
F_18 ( V_2 , V_51 ,
V_86 , V_87 , V_88 ,
V_30 -> V_91 , V_30 -> V_91 ) ;
V_51 += V_30 -> V_92 ;
V_86 += V_85 ;
V_87 += V_30 -> V_91 ;
V_88 += V_30 -> V_91 ;
}
F_22 ( & V_2 -> V_36 ) ;
}
