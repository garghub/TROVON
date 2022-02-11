static inline void
F_1 ( struct V_1 * V_2 )
{
int V_3 = 50 ;
while ( ( F_2 ( & V_2 -> V_4 -> V_5 ) & V_6 ) && V_3 -- )
F_3 ( 1 ) ;
if ( V_3 < 0 )
F_4 ( V_7 L_1 ) ;
}
static inline void
F_5 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = 50 ;
while ( ! ( F_2 ( & V_2 -> V_4 -> V_8 ) & V_9 ) && V_3 -- )
F_3 ( 1 ) ;
if ( V_3 < 0 )
F_4 ( V_7 L_2 ) ;
V_3 = 50 ;
while ( ( F_2 ( & V_2 -> V_4 -> V_8 ) & V_9 ) && V_3 -- )
F_3 ( 1 ) ;
if ( V_3 < 0 )
F_4 ( V_7 L_3 ) ;
}
static void
F_6 ( struct V_1 * V_2 , unsigned V_10 , unsigned V_11 )
{
F_7 ( & V_2 -> V_4 -> V_5 , V_10 + 0x200c00 + ( V_11 & 0xff ) ) ;
F_1 ( V_2 ) ;
F_7 ( & V_2 -> V_4 -> V_5 , V_10 + 0x200d00 + ( ( V_11 >> 8 ) & 0xff ) ) ;
F_1 ( V_2 ) ;
F_7 ( & V_2 -> V_4 -> V_5 , V_10 + 0x200e00 + ( ( V_11 >> 16 ) & 0xff ) ) ;
F_1 ( V_2 ) ;
F_7 ( & V_2 -> V_4 -> V_5 , V_10 + 0x200f00 + ( ( V_11 >> 24 ) & 0xff ) ) ;
F_1 ( V_2 ) ;
}
static unsigned
F_8 ( struct V_1 * V_2 , unsigned V_10 )
{
unsigned V_11 = 0 ;
unsigned long V_12 ;
F_9 ( & V_2 -> V_13 , V_12 ) ;
F_7 ( & V_2 -> V_4 -> V_5 , V_10 + 0x100000 ) ;
F_1 ( V_2 ) ;
F_5 ( V_2 ) ;
V_11 += ( F_2 ( & V_2 -> V_4 -> V_8 ) >> 4 ) & 0xff ;
F_7 ( & V_2 -> V_4 -> V_5 , V_10 + 0x100100 ) ;
F_1 ( V_2 ) ;
F_5 ( V_2 ) ;
V_11 += ( ( F_2 ( & V_2 -> V_4 -> V_8 ) >> 4 ) & 0xff ) << 8 ;
F_7 ( & V_2 -> V_4 -> V_5 , V_10 + 0x100200 ) ;
F_1 ( V_2 ) ;
F_5 ( V_2 ) ;
V_11 += ( ( F_2 ( & V_2 -> V_4 -> V_8 ) >> 4 ) & 0xff ) << 16 ;
F_7 ( & V_2 -> V_4 -> V_5 , V_10 + 0x100300 ) ;
F_1 ( V_2 ) ;
F_5 ( V_2 ) ;
V_11 += ( ( F_2 ( & V_2 -> V_4 -> V_8 ) >> 4 ) & 0xff ) << 24 ;
F_10 ( & V_2 -> V_13 , V_12 ) ;
return V_11 ;
}
static void
F_11 ( struct V_1 * V_2 , unsigned int V_10 ,
unsigned int V_11 )
{
F_7 ( & V_2 -> V_4 -> V_5 , V_10 + 0x300000 + ( V_11 & 0xff ) ) ;
F_1 ( V_2 ) ;
}
static unsigned
F_12 ( struct V_1 * V_2 , unsigned int V_10 )
{
unsigned V_11 = 0 ;
unsigned long V_12 ;
F_9 ( & V_2 -> V_13 , V_12 ) ;
F_7 ( & V_2 -> V_4 -> V_5 , V_10 + 0x100000 ) ;
F_1 ( V_2 ) ;
F_5 ( V_2 ) ;
V_11 += ( F_2 ( & V_2 -> V_4 -> V_8 ) >> 4 ) & 0xff ;
F_10 ( & V_2 -> V_13 , V_12 ) ;
return V_11 ;
}
static void
F_13 ( struct V_1 * V_2 , unsigned int V_14 ,
long * V_15 , int V_16 )
{
int V_17 , V_18 , V_19 ;
if ( V_15 [ 0 ] < 0 || V_15 [ 0 ] > 100 ||
V_15 [ 1 ] < 0 || V_15 [ 1 ] > 100 )
return;
V_18 = V_15 [ 0 ] ? V_15 [ 0 ] + V_20 : 0 ;
V_19 = V_15 [ 1 ] ? V_15 [ 1 ] + V_20 : 0 ;
V_17 = V_18 + ( V_19 << V_16 ) ;
if ( V_16 == 8 )
V_17 |= V_17 << 16 ;
F_6 ( V_2 , V_14 , V_17 ) ;
}
static void
F_14 ( struct V_1 * V_2 , unsigned int V_14 ,
long * V_15 , int V_16 )
{
int V_21 ;
V_21 = F_8 ( V_2 , V_14 ) ;
V_15 [ 0 ] = V_21 & 0xff ;
if ( V_15 [ 0 ] >= V_20 )
V_15 [ 0 ] -= V_20 ;
else
V_15 [ 0 ] = 0 ;
V_15 [ 1 ] = ( V_21 >> V_16 ) & 0xff ;
if ( V_15 [ 1 ] >= V_20 )
V_15 [ 1 ] -= V_20 ;
else
V_15 [ 1 ] = 0 ;
}
static int F_15 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
V_25 -> type = V_26 ;
V_25 -> V_27 = 2 ;
V_25 -> V_28 . integer . V_29 = 0 ;
V_25 -> V_28 . integer . V_30 = 100 ;
return 0 ;
}
static int F_16 ( struct V_22 * V_23 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_17 ( V_23 ) ;
unsigned int V_10 = F_18 ( V_23 -> V_33 & 0xff ) ;
int V_16 = ( V_23 -> V_33 >> 8 ) & 0xff ;
F_14 ( V_2 , V_10 ,
V_32 -> V_28 . integer . V_28 , V_16 ) ;
return 0 ;
}
static int F_19 ( struct V_22 * V_23 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_17 ( V_23 ) ;
unsigned int V_10 = F_18 ( V_23 -> V_33 & 0xff ) ;
int V_16 = ( V_23 -> V_33 >> 8 ) & 0xff ;
long V_34 [ 2 ] ;
F_13 ( V_2 , V_10 ,
V_32 -> V_28 . integer . V_28 , V_16 ) ;
F_14 ( V_2 , V_10 , V_34 , V_16 ) ;
return ( V_34 [ 0 ] != V_32 -> V_28 . integer . V_28 [ 0 ] ||
V_34 [ 1 ] != V_32 -> V_28 . integer . V_28 [ 1 ] ) ;
}
static void
F_20 ( struct V_1 * V_2 , unsigned int V_14 ,
long * V_15 , int V_35 )
{
int V_18 , V_19 ;
V_35 |= V_35 << 2 ;
V_18 = V_15 [ 0 ] ? V_15 [ 0 ] + V_20 : 0 ;
V_19 = V_15 [ 1 ] ? V_15 [ 1 ] + V_20 : 0 ;
F_11 ( V_2 , V_14 + V_35 , V_18 ) ;
F_11 ( V_2 , V_14 + V_35 + 0x500 , V_19 ) ;
}
static void
F_21 ( struct V_1 * V_2 , unsigned int V_14 ,
long * V_15 , int V_35 )
{
V_15 [ 0 ] = F_12 ( V_2 , V_14 + V_35 ) ;
if ( V_15 [ 0 ] >= V_20 )
V_15 [ 0 ] -= V_20 ;
else
V_15 [ 0 ] = 0 ;
V_15 [ 1 ] = F_12 ( V_2 , V_14 + V_35 + 0x100 ) ;
if ( V_15 [ 1 ] >= V_20 )
V_15 [ 1 ] -= V_20 ;
else
V_15 [ 1 ] = 0 ;
}
static int F_22 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
V_25 -> type = V_26 ;
V_25 -> V_27 = 2 ;
V_25 -> V_28 . integer . V_29 = 0 ;
V_25 -> V_28 . integer . V_30 = 100 ;
return 0 ;
}
static int F_23 ( struct V_22 * V_23 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_17 ( V_23 ) ;
unsigned int V_10 = F_18 ( V_23 -> V_33 & 0xff ) ;
int V_35 = V_23 -> V_33 & 0x300 ;
F_21 ( V_2 , V_10 ,
V_32 -> V_28 . integer . V_28 , V_35 ) ;
return 0 ;
}
static int F_24 ( struct V_22 * V_23 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_17 ( V_23 ) ;
unsigned int V_10 = F_18 ( V_23 -> V_33 & 0xff ) ;
int V_35 = V_23 -> V_33 & 0x300 ;
long V_34 [ 2 ] ;
F_20 ( V_2 , V_10 ,
V_32 -> V_28 . integer . V_28 , V_35 ) ;
F_21 ( V_2 , V_10 , V_34 , V_35 ) ;
return ( V_34 [ 0 ] != V_32 -> V_28 . integer . V_28 [ 0 ] ||
V_34 [ 1 ] != V_32 -> V_28 . integer . V_28 [ 1 ] ) ;
}
static int F_25 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
int V_36 = ( V_23 -> V_33 >> 24 ) & 1 ;
V_25 -> type = V_26 ;
V_25 -> V_27 = V_36 + 1 ;
V_25 -> V_28 . integer . V_29 = 0 ;
V_25 -> V_28 . integer . V_30 = 15 ;
return 0 ;
}
static int F_26 ( struct V_22 * V_23 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_17 ( V_23 ) ;
unsigned int V_10 = F_18 ( V_23 -> V_33 & 0xff ) ;
int V_36 = ( V_23 -> V_33 >> 24 ) & 1 ;
int V_37 = ( V_23 -> V_33 >> 25 ) & 1 ;
int V_38 ;
V_38 = F_12 ( V_2 , V_10 ) ;
if ( V_37 )
V_38 = ~ V_38 & 0xff ;
V_32 -> V_28 . integer . V_28 [ 0 ] = V_38 & 0xf ;
if ( V_36 )
V_32 -> V_28 . integer . V_28 [ 1 ] = ( V_38 >> 4 ) & 0xf ;
return 0 ;
}
static int F_27 ( struct V_22 * V_23 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_17 ( V_23 ) ;
unsigned int V_10 = F_18 ( V_23 -> V_33 & 0xff ) ;
int V_36 = ( V_23 -> V_33 >> 24 ) & 1 ;
int V_37 = ( V_23 -> V_33 >> 25 ) & 1 ;
int V_38 , V_11 ;
V_38 = F_12 ( V_2 , V_10 ) ;
if ( V_37 )
V_38 = ~ V_38 & 0xff ;
V_11 = V_32 -> V_28 . integer . V_28 [ 0 ] ;
if ( V_36 )
V_11 |= V_32 -> V_28 . integer . V_28 [ 1 ] << 4 ;
else
V_11 |= V_32 -> V_28 . integer . V_28 [ 0 ] << 4 ;
if ( V_37 )
V_11 = ~ V_11 & 0xff ;
F_11 ( V_2 , V_10 , V_11 ) ;
return V_11 != V_38 ;
}
static int F_28 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
int V_36 = ( V_23 -> V_33 >> 24 ) & 1 ;
V_25 -> type = V_39 ;
V_25 -> V_27 = V_36 + 1 ;
V_25 -> V_28 . integer . V_29 = 0 ;
V_25 -> V_28 . integer . V_30 = 1 ;
return 0 ;
}
static int F_29 ( struct V_22 * V_23 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_17 ( V_23 ) ;
unsigned int V_10 = F_18 ( ( V_23 -> V_33 >> 16 ) & 0xff ) ;
int V_40 = 1 << ( V_23 -> V_33 & 0xff ) ;
int V_41 = 1 << ( ( V_23 -> V_33 >> 8 ) & 0xff ) ;
int V_36 = ( V_23 -> V_33 >> 24 ) & 1 ;
int V_11 = F_8 ( V_2 , V_10 ) ;
V_32 -> V_28 . integer . V_28 [ 0 ] = ( V_11 & V_40 ) ? 1 : 0 ;
if ( V_36 )
V_32 -> V_28 . integer . V_28 [ 1 ] = ( V_11 & V_41 ) ? 1 : 0 ;
return 0 ;
}
static int F_30 ( struct V_22 * V_23 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_17 ( V_23 ) ;
unsigned int V_10 = F_18 ( ( V_23 -> V_33 >> 16 ) & 0xff ) ;
int V_40 = 1 << ( V_23 -> V_33 & 0xff ) ;
int V_41 = 1 << ( ( V_23 -> V_33 >> 8 ) & 0xff ) ;
int V_36 = ( V_23 -> V_33 >> 24 ) & 1 ;
int V_11 , V_38 ;
V_38 = F_8 ( V_2 , V_10 ) ;
V_11 = V_38 & ~ ( V_40 | ( V_36 ? V_41 : 0 ) ) ;
if ( V_32 -> V_28 . integer . V_28 [ 0 ] )
V_11 |= V_40 ;
if ( V_36 && V_32 -> V_28 . integer . V_28 [ 1 ] )
V_11 |= V_41 ;
F_6 ( V_2 , V_10 , V_11 ) ;
return V_11 != V_38 ;
}
static int F_31 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
int V_36 = ( V_23 -> V_33 >> 24 ) & 1 ;
V_25 -> type = V_39 ;
V_25 -> V_27 = V_36 + 1 ;
V_25 -> V_28 . integer . V_29 = 0 ;
V_25 -> V_28 . integer . V_30 = 1 ;
return 0 ;
}
static int F_32 ( struct V_22 * V_23 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_17 ( V_23 ) ;
unsigned int V_10 = F_18 ( ( V_23 -> V_33 >> 16 ) & 0xff ) ;
int V_40 = V_23 -> V_33 & 0xff ;
int V_41 = ( V_23 -> V_33 >> 8 ) & 0xff ;
int V_36 = ( V_23 -> V_33 >> 24 ) & 1 ;
int V_11 = F_12 ( V_2 , V_10 ) ;
V_32 -> V_28 . integer . V_28 [ 0 ] = ( V_11 & V_40 ) ? 1 : 0 ;
if ( V_36 )
V_32 -> V_28 . integer . V_28 [ 1 ] = ( V_11 & V_41 ) ? 1 : 0 ;
return 0 ;
}
static int F_33 ( struct V_22 * V_23 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_17 ( V_23 ) ;
unsigned int V_10 = F_18 ( ( V_23 -> V_33 >> 16 ) & 0xff ) ;
int V_40 = V_23 -> V_33 & 0xff ;
int V_41 = ( V_23 -> V_33 >> 8 ) & 0xff ;
int V_36 = ( V_23 -> V_33 >> 24 ) & 1 ;
int V_11 , V_38 ;
V_38 = F_12 ( V_2 , V_10 ) ;
V_11 = V_38 & ~ ( V_40 | V_41 ) ;
if ( V_32 -> V_28 . integer . V_28 [ 0 ] )
V_11 |= V_40 ;
if ( V_36 && V_32 -> V_28 . integer . V_28 [ 1 ] )
V_11 |= V_41 ;
F_11 ( V_2 , V_10 , V_11 ) ;
return V_11 != V_38 ;
}
static int F_34 ( struct V_1 * V_2 )
{
return ( F_2 ( & V_2 -> V_4 -> V_8 ) & V_2 -> V_42 ) ? 1 : 0 ;
}
static void F_35 ( struct V_1 * V_2 , int V_43 )
{
if ( V_2 -> V_44 ) {
int V_45 = F_36 ( L_4 ) ;
int V_46 , V_47 ;
V_46 = V_47 = F_12 ( V_2 ,
V_48 ) ;
V_46 &= V_45 ? ~ ( V_49 | V_50
| V_51 | V_52 )
: ~ ( V_49 | V_50
| V_53 ) ;
if ( F_34 ( V_2 ) )
V_46 |= V_45 ? ( V_51 | V_52 )
: ( V_49
| V_50 ) ;
else
V_46 |= V_45 ? ( V_49
| V_50 )
: ( V_53 ) ;
if ( V_43 && V_46 == V_47 )
return;
F_11 ( V_2 ,
V_48 , V_46 ) ;
if ( V_43 ) {
F_37 ( V_2 -> V_54 , V_55 ,
& V_2 -> V_56 -> V_57 ) ;
F_37 ( V_2 -> V_54 , V_55 ,
& V_2 -> V_58 -> V_57 ) ;
F_37 ( V_2 -> V_54 , V_55 ,
& V_2 -> V_59 -> V_57 ) ;
}
}
}
int F_38 ( struct V_1 * V_2 )
{
int V_45 = F_36 ( L_4 ) ;
int V_60 , V_61 ;
if ( ( F_2 ( & V_2 -> V_4 -> V_5 ) & V_62 ) == 0xf0000 ) {
F_4 ( V_63 L_5 ) ;
return 1 ;
}
F_6 ( V_2 , V_64 ,
V_65 ) ;
F_11 ( V_2 , V_48 ,
V_66 ) ;
F_6 ( V_2 , V_67 ,
V_68 ) ;
F_11 ( V_2 , V_69 ,
V_70 ) ;
F_11 ( V_2 , V_71 ,
V_45 ? V_72
: V_73 ) ;
F_11 ( V_2 , V_74 ,
V_75 ) ;
F_11 ( V_2 , V_76 ,
V_77 ) ;
F_11 ( V_2 , V_78 ,
V_79 ) ;
F_11 ( V_2 , V_80 ,
V_81 ) ;
F_11 ( V_2 , V_82 ,
V_83 ) ;
F_11 ( V_2 , V_84 ,
V_85 ) ;
F_11 ( V_2 , V_86 ,
V_87 ) ;
F_6 ( V_2 , V_88 ,
V_89 ) ;
F_6 ( V_2 , V_90 ,
V_91 ) ;
F_6 ( V_2 , V_92 ,
V_93 ) ;
F_6 ( V_2 , V_94 ,
V_95 ) ;
if ( V_2 -> V_42 == 0 ) {
if ( V_45 )
V_2 -> V_42 = V_96
| V_97
| V_98 ;
else
V_2 -> V_42 = V_99 ;
}
strcpy ( V_2 -> V_54 -> V_100 , L_6 ) ;
for ( V_60 = 0 ; V_60 < F_39 ( V_101 ) ; V_60 ++ ) {
V_61 = F_40 ( V_2 -> V_54 ,
F_41 ( & V_101 [ V_60 ] , V_2 ) ) ;
if ( V_61 < 0 )
return V_61 ;
}
for ( V_60 = 0 ; V_60 < ( V_45 ? F_39 ( V_102 )
: F_39 ( V_103 ) ) ; V_60 ++ ) {
V_61 = F_40 ( V_2 -> V_54 ,
F_41 ( V_45 ? & V_102 [ V_60 ]
: & V_103 [ V_60 ] , V_2 ) ) ;
if ( V_61 < 0 )
return V_61 ;
}
V_2 -> V_56 = F_41 ( V_45
? & V_104
: & V_105 , V_2 ) ;
V_61 = F_40 ( V_2 -> V_54 , V_2 -> V_56 ) ;
if ( V_61 < 0 )
return V_61 ;
V_2 -> V_56 = F_41 ( V_45
? & V_106
: & V_107 , V_2 ) ;
V_61 = F_40 ( V_2 -> V_54 , V_2 -> V_56 ) ;
if ( V_61 < 0 )
return V_61 ;
if ( V_45 ) {
V_2 -> V_56 = F_41 (
& V_108 , V_2 ) ;
V_61 = F_40 ( V_2 -> V_54 , V_2 -> V_56 ) ;
if ( V_61 < 0 )
return V_61 ;
}
V_2 -> V_58 = F_41 ( V_45
? & V_109
: & V_110 , V_2 ) ;
V_61 = F_40 ( V_2 -> V_54 , V_2 -> V_58 ) ;
if ( V_61 < 0 )
return V_61 ;
#ifdef F_42
V_61 = F_43 ( V_2 ) ;
if ( V_61 < 0 )
return V_61 ;
V_2 -> V_111 = F_34 ;
V_2 -> V_112 = F_35 ;
F_35 ( V_2 , 0 ) ;
#endif
return 0 ;
}
