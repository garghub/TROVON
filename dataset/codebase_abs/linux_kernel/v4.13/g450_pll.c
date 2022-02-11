static inline unsigned int F_1 ( unsigned char V_1 , unsigned int V_2 ) {
return ( V_1 & 0x40 ) ? V_2 : V_2 >> ( ( V_1 & 3 ) + 1 ) ;
}
static inline unsigned int F_2 ( unsigned char V_1 , unsigned int V_3 ) {
return ( V_1 & 0x40 ) ? V_3 : V_3 << ( ( V_1 & 3 ) + 1 ) ;
}
static unsigned int F_3 ( const struct V_4 * V_5 ,
unsigned int V_6 )
{
unsigned int V_7 , V_8 ;
V_7 = ( ( V_6 >> 16 ) & 0x0FF ) + 1 ;
V_8 = ( ( V_6 >> 7 ) & 0x1FE ) + 4 ;
return ( V_5 -> V_9 . V_10 . V_11 * V_8 + ( V_7 >> 1 ) ) / V_7 ;
}
unsigned int F_4 ( const struct V_4 * V_5 , unsigned int V_6 )
{
return F_1 ( V_6 , F_3 ( V_5 , V_6 ) ) ;
}
static inline unsigned int F_5 ( unsigned int V_12 , unsigned int V_13 ) {
if ( V_13 < V_12 ) {
V_13 = V_12 - V_13 ;
} else {
V_13 = V_13 - V_12 ;
}
return V_13 ;
}
static unsigned int F_6 ( const struct V_4 * V_5 ,
const struct V_14 * V_15 ,
unsigned int * V_2 , unsigned int V_6 )
{
unsigned int V_7 , V_8 , V_1 ;
unsigned int V_16 = * V_2 ;
V_7 = ( V_6 >> 16 ) & 0xFF ;
V_1 = V_6 & 0xFF ;
do {
if ( V_7 == 0 || V_7 == 0xFF ) {
if ( V_7 == 0 ) {
if ( V_1 & 0x40 ) {
return V_17 ;
}
if ( V_1 & 3 ) {
V_1 -- ;
} else {
V_1 = 0x40 ;
}
V_16 >>= 1 ;
if ( V_16 < V_15 -> V_18 ) {
return V_17 ;
}
* V_2 = V_16 ;
}
V_1 &= 0x43 ;
if ( V_16 < 550000 ) {
} else if ( V_16 < 700000 ) {
V_1 |= 0x08 ;
} else if ( V_16 < 1000000 ) {
V_1 |= 0x10 ;
} else if ( V_16 < 1150000 ) {
V_1 |= 0x18 ;
} else {
V_1 |= 0x20 ;
}
V_7 = 9 ;
} else {
V_7 -- ;
}
V_8 = ( ( V_16 * ( V_7 + 1 ) + V_5 -> V_9 . V_10 . V_11 ) / ( V_5 -> V_9 . V_10 . V_11 * 2 ) ) - 2 ;
} while ( V_8 < 0x03 || V_8 > 0x7A );
return ( V_7 << 16 ) | ( V_8 << 8 ) | V_1 ;
}
static unsigned int F_7 ( const struct V_4 * V_5 ,
const struct V_14 * V_15 ,
unsigned int * V_19 , unsigned int V_20 )
{
unsigned int V_1 ;
unsigned int V_21 ;
V_21 = V_15 -> V_21 ;
if ( V_20 > ( V_21 / 2 ) ) {
if ( V_20 > V_21 ) {
* V_19 = V_21 ;
} else {
* V_19 = V_20 ;
}
V_1 = 0x40 ;
} else {
unsigned int V_16 ;
V_1 = 3 ;
V_16 = F_2 ( V_1 , V_20 ) ;
while ( V_1 && ( V_16 > V_21 ) ) {
V_1 -- ;
V_16 >>= 1 ;
}
if ( V_16 < V_15 -> V_18 ) {
V_16 = V_15 -> V_18 ;
}
* V_19 = V_16 ;
}
return F_6 ( V_5 , V_15 , V_19 , 0xFF0000 | V_1 ) ;
}
static inline unsigned int F_8 ( const struct V_4 * V_5 ,
unsigned int V_6 , unsigned int V_10 )
{
switch ( V_10 ) {
case V_22 :
F_9 ( V_5 , V_23 , V_6 >> 16 ) ;
F_9 ( V_5 , V_24 , V_6 >> 8 ) ;
F_9 ( V_5 , V_25 , V_6 ) ;
return V_26 ;
case V_27 :
F_9 ( V_5 , V_28 , V_6 >> 16 ) ;
F_9 ( V_5 , V_29 , V_6 >> 8 ) ;
F_9 ( V_5 , V_30 , V_6 ) ;
return V_26 ;
case V_31 :
F_9 ( V_5 , V_32 , V_6 >> 16 ) ;
F_9 ( V_5 , V_33 , V_6 >> 8 ) ;
F_9 ( V_5 , V_34 , V_6 ) ;
return V_26 ;
case V_35 :
F_9 ( V_5 , V_36 , V_6 >> 16 ) ;
F_9 ( V_5 , V_37 , V_6 >> 8 ) ;
F_9 ( V_5 , V_38 , V_6 ) ;
return V_39 ;
case V_40 :
F_9 ( V_5 , V_41 , V_6 >> 16 ) ;
F_9 ( V_5 , V_42 , V_6 >> 8 ) ;
F_9 ( V_5 , V_43 , V_6 ) ;
return V_44 ;
}
return 0 ;
}
static inline unsigned int F_10 ( const struct V_4 * V_5 ,
unsigned int V_6 , unsigned int V_10 )
{
unsigned char V_7 = V_6 >> 16 ;
unsigned char V_8 = V_6 >> 8 ;
unsigned char V_1 = V_6 ;
switch ( V_10 ) {
case V_22 :
return ( F_11 ( V_5 , V_23 ) != V_7 ||
F_11 ( V_5 , V_24 ) != V_8 ||
F_11 ( V_5 , V_25 ) != V_1 ) ;
case V_27 :
return ( F_11 ( V_5 , V_28 ) != V_7 ||
F_11 ( V_5 , V_29 ) != V_8 ||
F_11 ( V_5 , V_30 ) != V_1 ) ;
case V_31 :
return ( F_11 ( V_5 , V_32 ) != V_7 ||
F_11 ( V_5 , V_33 ) != V_8 ||
F_11 ( V_5 , V_34 ) != V_1 ) ;
case V_35 :
return ( F_11 ( V_5 , V_36 ) != V_7 ||
F_11 ( V_5 , V_37 ) != V_8 ||
F_11 ( V_5 , V_38 ) != V_1 ) ;
case V_40 :
return ( F_11 ( V_5 , V_41 ) != V_7 ||
F_11 ( V_5 , V_42 ) != V_8 ||
F_11 ( V_5 , V_43 ) != V_1 ) ;
}
return 1 ;
}
static inline int F_12 ( const struct V_4 * V_5 ,
unsigned int V_45 )
{
unsigned int V_46 ;
for ( V_46 = 0 ; V_46 < 1000 ; V_46 ++ ) {
if ( F_11 ( V_5 , V_45 ) & 0x40 ) {
unsigned int V_47 = 0 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < 100 ; V_48 ++ ) {
V_47 += F_11 ( V_5 , V_45 ) & 0x40 ;
}
return V_47 >= ( 90 * 0x40 ) ;
}
}
return 0 ;
}
static int F_13 ( const struct V_4 * V_5 , unsigned int V_6 ,
unsigned int V_10 )
{
return F_12 ( V_5 , F_8 ( V_5 , V_6 , V_10 ) ) ;
}
static void F_14 ( struct V_49 * V_50 , unsigned int V_6 , unsigned int V_10 ) {
switch ( V_10 ) {
case V_35 :
V_50 -> V_51 [ 3 ] = V_6 >> 16 ;
V_50 -> V_51 [ 4 ] = V_6 >> 8 ;
V_50 -> V_51 [ 5 ] = V_6 ;
break;
}
}
void F_15 ( struct V_4 * V_5 , unsigned int V_6 ,
unsigned int V_10 )
{
if ( F_10 ( V_5 , V_6 , V_10 ) ) {
F_8 ( V_5 , V_6 , V_10 ) ;
}
}
static inline unsigned int F_16 ( struct V_4 * V_5 ,
unsigned int V_10 ,
unsigned int * V_52 ,
unsigned int V_53 )
{
unsigned int V_54 = 0 ;
unsigned int V_55 ;
unsigned int V_56 = V_52 [ 0 ] ;
for ( V_55 = 0 ; V_55 < V_53 ; V_55 ++ ) {
unsigned int V_57 [ 3 ] ;
unsigned int * V_58 ;
{
unsigned int V_6 ;
V_58 = V_57 ;
V_6 = V_52 [ V_55 ] ;
if ( V_6 & 0x38 ) {
* V_58 ++ = V_6 - 8 ;
}
if ( ( V_6 & 0x38 ) != 0x38 ) {
* V_58 ++ = V_6 + 8 ;
}
* V_58 = V_6 ;
}
while ( V_58 >= V_57 ) {
unsigned int V_6 = * V_58 -- ;
if ( F_13 ( V_5 , V_6 - 0x0300 , V_10 ) &&
F_13 ( V_5 , V_6 + 0x0300 , V_10 ) &&
F_13 ( V_5 , V_6 - 0x0200 , V_10 ) &&
F_13 ( V_5 , V_6 + 0x0200 , V_10 ) &&
F_13 ( V_5 , V_6 - 0x0100 , V_10 ) &&
F_13 ( V_5 , V_6 + 0x0100 , V_10 ) ) {
if ( F_13 ( V_5 , V_6 , V_10 ) ) {
return V_6 ;
}
} else if ( ! V_54 && F_13 ( V_5 , V_6 , V_10 ) ) {
V_56 = V_6 ;
V_54 = 1 ;
}
}
}
F_8 ( V_5 , V_56 , V_10 ) ;
return V_56 ;
}
static void F_17 ( struct V_59 * V_60 , unsigned int V_61 , unsigned int V_62 ) {
if ( ++ V_60 -> V_63 > F_18 ( V_60 -> V_64 ) ) {
V_60 -> V_63 = F_18 ( V_60 -> V_64 ) ;
}
memmove ( V_60 -> V_64 + 1 , V_60 -> V_64 , ( V_60 -> V_63 - 1 ) * sizeof( * V_60 -> V_64 ) ) ;
V_60 -> V_64 [ 0 ] . V_61 = V_61 & V_65 ;
V_60 -> V_64 [ 0 ] . V_62 = V_62 ;
}
static int F_19 ( struct V_4 * V_5 ,
struct V_59 * V_60 , unsigned int V_61 )
{
unsigned int V_48 ;
V_61 &= V_65 ;
for ( V_48 = 0 ; V_48 < V_60 -> V_63 ; V_48 ++ ) {
if ( V_60 -> V_64 [ V_48 ] . V_61 == V_61 ) {
unsigned int V_6 ;
V_6 = V_60 -> V_64 [ V_48 ] . V_62 ;
if ( V_48 ) {
memmove ( V_60 -> V_64 + 1 , V_60 -> V_64 , V_48 * sizeof( * V_60 -> V_64 ) ) ;
V_60 -> V_64 [ 0 ] . V_61 = V_61 ;
V_60 -> V_64 [ 0 ] . V_62 = V_6 ;
}
return V_6 ;
}
}
return V_17 ;
}
static int F_20 ( struct V_4 * V_5 , unsigned int V_20 ,
unsigned int V_10 , unsigned int * V_52 ,
unsigned int * V_66 )
{
unsigned int V_53 ;
unsigned int V_67 ;
const struct V_14 * V_15 ;
struct V_59 * V_60 ;
V_67 = 0 ;
switch ( V_10 ) {
case V_22 :
case V_27 :
case V_31 :
{
T_1 V_68 , V_69 ;
unsigned long V_70 ;
F_21 ( V_70 ) ;
V_69 = F_11 ( V_5 , V_71 ) ;
F_9 ( V_5 , V_71 , V_69 & ~ V_72 ) ;
F_22 ( V_73 , V_74 ) ;
F_22 ( V_75 , F_23 ( V_75 ) | V_76 ) ;
V_68 = F_11 ( V_5 , V_77 ) ;
V_68 |= V_78 ;
if ( ! ( V_68 & V_79 ) ) {
V_68 |= V_79 ;
}
F_9 ( V_5 , V_77 , V_68 ) ;
if ( V_20 >= V_5 -> V_80 )
V_68 = 0 ;
else V_68 =
V_81 |
V_82 |
V_83 |
V_84 |
V_85 ;
F_9 ( V_5 , V_71 ,
V_69 ) ;
F_24 ( V_70 ) ;
}
{
T_1 V_86 ;
V_86 = F_23 ( V_87 ) & ~ 0x0C ;
switch ( V_10 ) {
case V_22 :
break;
case V_27 :
V_86 |= 0x04 ;
break;
default:
V_86 |= 0x0C ;
break;
}
F_22 ( V_88 , V_86 ) ;
}
V_15 = & V_5 -> V_89 . V_90 ;
V_60 = & V_5 -> V_91 . V_90 ;
break;
case V_35 :
{
T_2 V_92 ;
F_25 ( V_5 -> V_93 , V_94 , & V_92 ) ;
if ( ! ( V_92 & 0x20 ) ) {
F_26 ( V_5 -> V_93 , V_94 , V_92 | 0x20 ) ;
}
}
V_15 = & V_5 -> V_89 . system ;
V_60 = & V_5 -> V_91 . system ;
break;
case V_40 :
{
T_1 V_68 ;
unsigned int V_6 ;
unsigned long V_70 ;
F_21 ( V_70 ) ;
V_68 = F_11 ( V_5 , V_71 ) ;
if ( ! ( V_68 & 2 ) ) {
F_9 ( V_5 , V_71 , V_68 | 2 ) ;
}
V_6 = F_11 ( V_5 , V_32 ) << 16 ;
V_6 |= F_11 ( V_5 , V_33 ) << 8 ;
V_67 = F_3 ( V_5 , V_6 ) ;
F_24 ( V_70 ) ;
}
V_15 = & V_5 -> V_89 . V_95 ;
V_60 = & V_5 -> V_91 . V_95 ;
break;
default:
return - V_96 ;
}
V_53 = 0 ;
{
unsigned int V_6 ;
unsigned int V_97 ;
for ( V_6 = F_7 ( V_5 , V_15 , & V_97 , V_20 ) ; V_6 != V_17 ; V_6 = F_6 ( V_5 , V_15 , & V_97 , V_6 ) ) {
unsigned int V_55 ;
unsigned int V_19 ;
unsigned int V_98 ;
V_19 = F_3 ( V_5 , V_6 ) ;
#if 0
if (pll == M_VIDEO_PLL) {
unsigned int big, small;
if (vco < pixel_vco) {
small = vco;
big = pixel_vco;
} else {
small = pixel_vco;
big = vco;
}
while (big > small) {
big >>= 1;
}
if (big == small) {
continue;
}
}
#endif
V_98 = F_5 ( V_20 , F_1 ( V_6 , V_19 ) ) ;
for ( V_55 = V_53 ; V_55 > 0 ; V_55 -- ) {
if ( V_98 <= V_66 [ V_55 - 1 ] ) {
if ( V_98 == V_66 [ V_55 - 1 ]
&& V_19 != F_3 ( V_5 , V_52 [ V_55 - 1 ] )
&& V_19 < ( V_15 -> V_18 * 17 / 16 ) ) {
break;
}
V_52 [ V_55 ] = V_52 [ V_55 - 1 ] ;
V_66 [ V_55 ] = V_66 [ V_55 - 1 ] ;
} else {
break;
}
}
V_52 [ V_55 ] = V_6 ;
V_66 [ V_55 ] = V_98 ;
V_53 ++ ;
}
}
if ( ! V_53 ) {
return - V_99 ;
}
{
unsigned long V_70 ;
unsigned int V_6 ;
F_21 ( V_70 ) ;
V_6 = F_19 ( V_5 , V_60 , V_52 [ 0 ] ) ;
if ( V_6 != V_17 ) {
F_15 ( V_5 , V_6 , V_10 ) ;
} else {
V_6 = F_16 ( V_5 , V_10 , V_52 , V_53 ) ;
F_17 ( V_60 , V_52 [ 0 ] , V_6 ) ;
}
F_14 ( & V_5 -> V_50 , V_6 , V_10 ) ;
F_24 ( V_70 ) ;
return V_6 ;
}
}
int F_27 ( struct V_4 * V_5 , unsigned int V_20 ,
unsigned int V_10 )
{
unsigned int * V_100 ;
V_100 = F_28 ( sizeof( * V_100 ) * V_101 * 2 , V_102 ) ;
if ( V_100 ) {
int V_47 ;
V_47 = F_20 ( V_5 , V_20 , V_10 , V_100 , V_100 + V_101 ) ;
F_29 ( V_100 ) ;
return V_47 ;
}
return - V_103 ;
}
