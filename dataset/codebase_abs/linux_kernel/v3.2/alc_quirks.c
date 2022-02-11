static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_3 ( V_6 , V_4 , V_8 -> V_9 ,
V_8 -> V_10 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_5 ( V_6 , V_12 , V_8 -> V_9 ,
V_8 -> V_10 ,
V_8 -> V_13 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_14 = F_7 ( V_6 , V_12 , V_8 -> V_9 ,
V_8 -> V_10 ,
& V_8 -> V_13 ) ;
if ( V_14 >= 0 && ! V_8 -> V_15 ) {
V_8 -> V_16 . V_17 = V_8 -> V_13 ;
if ( V_8 -> V_18 )
V_8 -> V_16 . V_19 = V_8 -> V_16 . V_17 / 2 ;
}
return V_14 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_20 = V_4 -> V_21 . V_22 . V_23 ;
unsigned char V_24 = ( V_2 -> V_25 >> 16 ) & 0xff ;
V_4 -> type = V_26 ;
V_4 -> V_27 = 1 ;
V_4 -> V_21 . V_22 . V_28 = F_9 ( V_24 ) ;
if ( V_20 < V_29 ( V_24 ) || V_20 > F_10 ( V_24 ) )
V_20 = V_29 ( V_24 ) ;
strcpy ( V_4 -> V_21 . V_22 . V_30 , V_31 [ V_20 ] ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
unsigned int V_32 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_33 = V_2 -> V_25 & 0xffff ;
unsigned char V_24 = ( V_2 -> V_25 >> 16 ) & 0xff ;
long * V_34 = V_12 -> V_21 . integer . V_21 ;
unsigned int V_35 = F_12 ( V_6 , V_33 , 0 ,
V_36 ,
0x00 ) ;
V_32 = V_29 ( V_24 ) ;
while ( V_32 <= F_10 ( V_24 ) && V_37 [ V_32 ] != V_35 )
V_32 ++ ;
* V_34 = V_32 <= F_10 ( V_24 ) ? V_32 : V_29 ( V_24 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
signed int V_38 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_33 = V_2 -> V_25 & 0xffff ;
unsigned char V_24 = ( V_2 -> V_25 >> 16 ) & 0xff ;
long V_39 = * V_12 -> V_21 . integer . V_21 ;
unsigned int V_35 = F_12 ( V_6 , V_33 , 0 ,
V_36 ,
0x00 ) ;
if ( V_39 < V_29 ( V_24 ) || V_39 > F_10 ( V_24 ) )
V_39 = V_29 ( V_24 ) ;
V_38 = V_35 != V_37 [ V_39 ] ;
if ( V_38 ) {
F_14 ( V_6 , V_33 , 0 ,
V_40 ,
V_37 [ V_39 ] ) ;
if ( V_39 <= 2 ) {
F_15 ( V_6 , V_33 , V_41 , 0 ,
V_42 , V_42 ) ;
F_15 ( V_6 , V_33 , V_43 , 0 ,
V_42 , 0 ) ;
} else {
F_15 ( V_6 , V_33 , V_43 , 0 ,
V_42 , V_42 ) ;
F_15 ( V_6 , V_33 , V_41 , 0 ,
V_42 , 0 ) ;
}
}
return V_38 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_33 = V_2 -> V_25 & 0xffff ;
unsigned char V_44 = ( V_2 -> V_25 >> 16 ) & 0xff ;
long * V_34 = V_12 -> V_21 . integer . V_21 ;
unsigned int V_39 = F_12 ( V_6 , V_33 , 0 ,
V_45 , 0x00 ) ;
* V_34 = ( V_39 & V_44 ) != 0 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
signed int V_38 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_33 = V_2 -> V_25 & 0xffff ;
unsigned char V_44 = ( V_2 -> V_25 >> 16 ) & 0xff ;
long V_39 = * V_12 -> V_21 . integer . V_21 ;
unsigned int V_46 = F_12 ( V_6 , V_33 , 0 ,
V_45 ,
0x00 ) ;
V_38 = ( V_39 == 0 ? 0 : V_44 ) != ( V_46 & V_44 ) ;
if ( V_39 == 0 )
V_46 &= ~ V_44 ;
else
V_46 |= V_44 ;
F_14 ( V_6 , V_33 , 0 ,
V_47 , V_46 ) ;
return V_38 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_33 = V_2 -> V_25 & 0xffff ;
unsigned char V_44 = ( V_2 -> V_25 >> 16 ) & 0xff ;
long * V_34 = V_12 -> V_21 . integer . V_21 ;
unsigned int V_39 = F_12 ( V_6 , V_33 , 0 ,
V_48 , 0x00 ) ;
* V_34 = ( V_39 & V_44 ) != 0 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
signed int V_38 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_33 = V_2 -> V_25 & 0xffff ;
unsigned char V_44 = ( V_2 -> V_25 >> 16 ) & 0xff ;
long V_39 = * V_12 -> V_21 . integer . V_21 ;
unsigned int V_49 = F_12 ( V_6 , V_33 , 0 ,
V_48 ,
0x00 ) ;
V_38 = ( V_39 == 0 ? 0 : V_44 ) != ( V_49 & V_44 ) ;
if ( V_39 == 0 )
V_49 &= ~ V_44 ;
else
V_49 |= V_44 ;
F_14 ( V_6 , V_33 , 0 , V_50 ,
V_49 ) ;
return V_38 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_33 = V_2 -> V_25 & 0xffff ;
unsigned char V_44 = ( V_2 -> V_25 >> 16 ) & 0xff ;
long * V_34 = V_12 -> V_21 . integer . V_21 ;
unsigned int V_39 = F_12 ( V_6 , V_33 , 0 ,
V_51 , 0x00 ) ;
* V_34 = ( V_39 & V_44 ) != 0 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
int V_38 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_33 = V_2 -> V_25 & 0xffff ;
unsigned char V_44 = ( V_2 -> V_25 >> 16 ) & 0xff ;
long V_39 = * V_12 -> V_21 . integer . V_21 ;
unsigned int V_49 = F_12 ( V_6 , V_33 , 0 ,
V_51 ,
0x00 ) ;
V_38 = ( ! V_39 ? 0 : V_44 ) != ( V_49 & V_44 ) ;
if ( ! V_39 )
V_49 &= ~ V_44 ;
else
V_49 |= V_44 ;
F_14 ( V_6 , V_33 , 0 , V_52 ,
V_49 ) ;
return V_38 ;
}
static void F_22 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_53 * V_54 = & V_8 -> V_55 ;
if ( ! V_54 -> V_56 ) {
while ( V_54 -> V_56 < V_57 &&
V_54 -> V_58 [ V_54 -> V_56 ] )
V_54 -> V_56 ++ ;
}
if ( ! V_54 -> V_59 ) {
while ( V_54 -> V_59 < V_57 &&
V_54 -> V_60 [ V_54 -> V_59 ] )
V_54 -> V_59 ++ ;
}
if ( ! V_54 -> V_61 ) {
while ( V_54 -> V_61 < V_57 &&
V_54 -> V_62 [ V_54 -> V_61 ] )
V_54 -> V_61 ++ ;
}
}
static void F_23 ( struct V_5 * V_6 ,
const struct V_63 * V_64 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < F_24 ( V_64 -> V_65 ) && V_64 -> V_65 [ V_32 ] ; V_32 ++ )
F_25 ( V_8 , V_64 -> V_65 [ V_32 ] ) ;
V_8 -> V_66 = V_64 -> V_66 ;
for ( V_32 = 0 ; V_32 < F_24 ( V_64 -> V_67 ) && V_64 -> V_67 [ V_32 ] ;
V_32 ++ )
F_26 ( V_8 , V_64 -> V_67 [ V_32 ] ) ;
V_8 -> V_9 = V_64 -> V_9 ;
V_8 -> V_10 = V_64 -> V_10 ;
V_8 -> V_18 = V_64 -> V_18 ;
V_8 -> V_15 = V_64 -> V_15 ;
if ( V_64 -> V_15 )
V_8 -> V_16 . V_17 = V_64 -> V_15 ;
else
V_8 -> V_16 . V_17 = V_8 -> V_9 [ 0 ] . V_68 ;
V_8 -> V_13 = V_8 -> V_9 [ 0 ] . V_68 ;
V_8 -> V_16 . V_19 = V_64 -> V_19 ;
V_8 -> V_16 . V_69 = V_64 -> V_69 ;
V_8 -> V_16 . V_70 = V_64 -> V_70 ;
V_8 -> V_16 . V_71 = V_64 -> V_71 ;
V_8 -> V_16 . V_72 = V_64 -> V_72 ;
V_8 -> V_73 = V_64 -> V_73 ;
if ( ! V_8 -> V_73 )
V_8 -> V_73 = 1 ;
V_8 -> V_74 = V_64 -> V_74 ;
V_8 -> V_75 = V_64 -> V_75 ;
V_8 -> V_76 = V_64 -> V_76 ;
V_8 -> V_77 = V_64 -> V_77 ;
V_8 -> V_78 = V_64 -> V_78 ;
V_8 -> V_79 = V_64 -> V_79 ;
V_8 -> V_80 = V_64 -> V_80 ;
#ifdef F_27
V_8 -> V_81 = V_64 -> V_81 ;
V_8 -> V_82 . V_83 = V_64 -> V_84 ;
#endif
if ( V_64 -> V_85 )
V_64 -> V_85 ( V_6 ) ;
F_22 ( V_6 ) ;
}
static void F_28 ( struct V_7 * V_8 , int V_86 )
{
int V_87 = V_8 -> V_55 . V_58 [ 0 ] ;
if ( V_87 == V_8 -> V_55 . V_60 [ 0 ] ||
V_87 == V_8 -> V_55 . V_62 [ 0 ] )
V_87 = 0 ;
V_8 -> V_88 = V_86 ;
V_8 -> V_89 = ! ! V_8 -> V_55 . V_62 [ 0 ] ;
V_8 -> V_90 = ! ! V_87 ;
V_8 -> V_91 = V_8 -> V_92 = ! ! V_87 ;
V_8 -> V_93 = V_8 -> V_94 = ! ! V_8 -> V_55 . V_60 [ 0 ] ;
}
static void F_29 ( struct V_5 * V_6 )
{
unsigned int V_95 ;
unsigned char V_96 ;
V_95 = F_30 ( V_6 , 0x18 ) ;
V_96 = V_95 ? V_42 : 0 ;
F_15 ( V_6 , 0x0b , V_43 , 1 , V_42 , V_96 ) ;
}
