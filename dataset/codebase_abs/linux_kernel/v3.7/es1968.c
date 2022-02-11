static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_6 ) ;
F_2 ( V_4 , V_2 -> V_5 + V_7 ) ;
V_2 -> V_8 [ V_3 ] = V_4 ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
unsigned long V_9 ;
F_4 ( & V_2 -> V_10 , V_9 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_11 & ( 1 << V_3 ) ) {
F_2 ( V_3 , V_2 -> V_5 + V_6 ) ;
V_2 -> V_8 [ V_3 ] = F_7 ( V_2 -> V_5 + V_7 ) ;
}
return V_2 -> V_8 [ V_3 ] ;
}
static inline T_1 F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_9 ;
T_1 V_12 ;
F_4 ( & V_2 -> V_10 , V_9 ) ;
V_12 = F_6 ( V_2 , V_3 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
return V_12 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_13 = 100000 ;
while ( V_13 -- > 0 ) {
if ( ! ( F_10 ( V_2 -> V_5 + V_14 ) & 1 ) )
return 0 ;
F_11 () ;
}
F_12 ( L_1 ) ;
return 1 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_13 = 100000 ;
while ( V_13 -- > 0 ) {
if ( ! ( F_10 ( V_2 -> V_5 + V_14 ) & 1 ) )
return 0 ;
}
F_12 ( L_1 ) ;
return 1 ;
}
static void F_14 ( struct V_15 * V_16 , unsigned short V_3 , unsigned short V_17 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
F_9 ( V_2 ) ;
F_2 ( V_17 , V_2 -> V_5 + V_19 ) ;
F_15 ( V_3 , V_2 -> V_5 + V_14 ) ;
}
static unsigned short F_16 ( struct V_15 * V_16 , unsigned short V_3 )
{
T_1 V_4 = 0 ;
struct V_1 * V_2 = V_16 -> V_18 ;
F_9 ( V_2 ) ;
F_15 ( V_3 | 0x80 , V_2 -> V_5 + V_14 ) ;
if ( ! F_13 ( V_2 ) ) {
V_4 = F_7 ( V_2 -> V_5 + V_19 ) ;
}
return V_4 ;
}
static void F_17 ( struct V_1 * V_2 , T_1 V_20 )
{
int V_21 ;
F_1 ( V_2 , V_22 , V_20 ) ;
for ( V_21 = 0 ; V_21 < 1000 ; V_21 ++ )
if ( F_6 ( V_2 , V_22 ) == V_20 )
return;
F_12 ( L_2 ) ;
}
static void F_18 ( struct V_1 * V_2 , T_1 V_4 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < 1000 ; V_21 ++ ) {
if ( F_6 ( V_2 , V_23 ) == V_4 )
return;
F_1 ( V_2 , V_23 , V_4 ) ;
}
F_12 ( L_3 ) ;
}
static void F_19 ( struct V_1 * V_2 , T_1 V_24 , T_2 V_3 , T_1 V_4 )
{
if ( F_20 ( V_24 >= V_25 ) )
return;
#ifdef F_21
V_2 -> V_26 [ V_24 ] [ V_3 ] = V_4 ;
#endif
V_3 |= ( V_24 << 4 ) ;
F_17 ( V_2 , V_3 ) ;
F_18 ( V_2 , V_4 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_1 V_24 , T_2 V_3 , T_1 V_4 )
{
unsigned long V_9 ;
F_4 ( & V_2 -> V_10 , V_9 ) ;
F_19 ( V_2 , V_24 , V_3 , V_4 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
}
static T_1 F_23 ( struct V_1 * V_2 , T_1 V_24 , T_2 V_3 )
{
if ( F_20 ( V_24 >= V_25 ) )
return 0 ;
V_3 |= ( V_24 << 4 ) ;
F_17 ( V_2 , V_3 ) ;
return F_6 ( V_2 , V_23 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 , T_1 V_24 , T_2 V_3 )
{
unsigned long V_9 ;
T_1 V_27 ;
F_4 ( & V_2 -> V_10 , V_9 ) ;
V_27 = F_23 ( V_2 , V_24 , V_3 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
return V_27 ;
}
static void F_25 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_28 )
{
unsigned long V_9 ;
F_4 ( & V_2 -> V_10 , V_9 ) ;
F_2 ( V_3 , V_2 -> V_5 + V_29 ) ;
F_2 ( V_28 , V_2 -> V_5 + V_30 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
}
static T_1 F_26 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_9 ;
T_1 V_28 ;
F_4 ( & V_2 -> V_10 , V_9 ) ;
F_2 ( V_3 , V_2 -> V_5 + V_29 ) ;
V_28 = F_7 ( V_2 -> V_5 + V_30 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
return V_28 ;
}
static void F_27 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_6 ( V_2 , 0x11 ) ;
V_3 &= ~ V_31 ;
F_1 ( V_2 , 0x11 , V_3 ) ;
V_3 = F_6 ( V_2 , 0x17 ) ;
V_3 &= ~ V_32 ;
F_1 ( V_2 , 0x17 , V_3 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
int V_33 ;
int V_34 ;
for ( V_33 = 5 ; V_33 < 12 ; V_33 ++ )
if ( V_2 -> V_35 > ( V_36 >> ( V_33 + 9 ) ) )
break;
V_34 = 1 ;
while ( ( V_33 > 5 ) && ( V_34 < 32 ) ) {
V_33 -- ;
V_34 <<= 1 ;
}
V_34 >>= 1 ;
for (; V_34 < 31 ; V_34 ++ )
if ( V_2 -> V_35 >
( ( V_36 >> ( V_33 + 9 ) ) / ( V_34 + 1 ) ) ) break;
if ( V_34 == 0 ) {
V_34 ++ ;
if ( V_33 > 5 )
V_33 -- ;
} else if ( V_34 > 1 )
V_34 -- ;
F_1 ( V_2 , 6 , 0x9000 | ( V_33 << 5 ) | V_34 ) ;
F_1 ( V_2 , 0x11 , F_6 ( V_2 , 0x11 ) | 1 ) ;
F_1 ( V_2 , 0x17 , F_6 ( V_2 , 0x17 ) | 1 ) ;
}
static void F_29 ( struct V_1 * V_2 , int V_37 )
{
V_2 -> V_38 ++ ;
if ( V_2 -> V_38 == 1 ) {
V_2 -> V_35 = V_37 ;
F_28 ( V_2 ) ;
} else if ( V_2 -> V_35 < V_37 ) {
F_27 ( V_2 ) ;
V_2 -> V_35 = V_37 ;
F_28 ( V_2 ) ;
}
}
static void F_30 ( struct V_1 * V_2 )
{
V_2 -> V_38 -- ;
if ( V_2 -> V_38 <= 0 )
F_27 ( V_2 ) ;
else if ( V_2 -> V_35 > V_39 ) {
int V_40 = V_39 ;
struct V_41 * V_42 ;
F_31 (es, &chip->substream_list, list) {
if ( V_40 < V_42 -> V_35 )
V_40 = V_42 -> V_35 ;
}
if ( V_40 != V_2 -> V_35 ) {
F_27 ( V_2 ) ;
V_2 -> V_35 = V_40 ;
F_28 ( V_2 ) ;
}
}
}
static int
F_32 ( struct V_1 * V_2 , struct V_41 * V_42 ,
struct V_43 * V_44 )
{
int V_37 = V_44 -> V_45 * 4 ;
if ( V_42 -> V_46 & V_47 )
V_37 <<= 1 ;
if ( V_42 -> V_46 & V_48 )
V_37 <<= 1 ;
V_37 /= V_42 -> V_49 ;
if ( V_37 < V_39 )
V_37 = V_39 ;
else if ( V_37 > V_50 )
V_37 = V_50 ;
return V_37 ;
}
static T_3 F_33 ( struct V_1 * V_2 , T_3 V_37 )
{
T_3 V_45 = ( V_37 << 16 ) / V_2 -> clock ;
#if 0
if (rate > 0x10000)
rate = 0x10000;
#endif
return V_45 ;
}
static inline unsigned int
F_34 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
unsigned int V_51 ;
V_51 = F_24 ( V_2 , V_42 -> V_52 [ 0 ] , 5 ) ;
V_51 -= V_42 -> V_53 [ 0 ] ;
return ( V_51 & 0xFFFE ) ;
}
static void F_35 ( struct V_1 * V_2 , int V_52 , int V_37 )
{
F_22 ( V_2 , V_52 , 2 ,
( F_24 ( V_2 , V_52 , 2 ) & 0x00FF ) |
( ( V_37 & 0xff ) << 8 ) | 0x10 ) ;
F_22 ( V_2 , V_52 , 3 , V_37 >> 8 ) ;
}
static inline void F_36 ( struct V_1 * V_54 , int V_52 , int V_55 )
{
F_19 ( V_54 , V_52 , 0 ,
( F_23 ( V_54 , V_52 , 0 ) & 0xff0f ) |
( V_55 << 4 ) ) ;
}
static void F_37 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
F_38 ( & V_2 -> V_10 ) ;
F_19 ( V_2 , V_42 -> V_52 [ 0 ] , 5 , V_42 -> V_53 [ 0 ] ) ;
F_36 ( V_2 , V_42 -> V_52 [ 0 ] , V_42 -> V_56 [ 0 ] ) ;
if ( V_42 -> V_55 == V_57 ) {
F_19 ( V_2 , V_42 -> V_52 [ 2 ] , 5 , V_42 -> V_53 [ 2 ] ) ;
F_36 ( V_2 , V_42 -> V_52 [ 2 ] , V_42 -> V_56 [ 2 ] ) ;
}
if ( V_42 -> V_46 & V_47 ) {
F_19 ( V_2 , V_42 -> V_52 [ 1 ] , 5 , V_42 -> V_53 [ 1 ] ) ;
F_36 ( V_2 , V_42 -> V_52 [ 1 ] , V_42 -> V_56 [ 1 ] ) ;
if ( V_42 -> V_55 == V_57 ) {
F_19 ( V_2 , V_42 -> V_52 [ 3 ] , 5 , V_42 -> V_53 [ 3 ] ) ;
F_36 ( V_2 , V_42 -> V_52 [ 3 ] , V_42 -> V_56 [ 3 ] ) ;
}
}
F_39 ( & V_2 -> V_10 ) ;
}
static void F_40 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
F_38 ( & V_2 -> V_10 ) ;
F_36 ( V_2 , V_42 -> V_52 [ 0 ] , 0 ) ;
F_36 ( V_2 , V_42 -> V_52 [ 1 ] , 0 ) ;
if ( V_42 -> V_55 == V_57 ) {
F_36 ( V_2 , V_42 -> V_52 [ 2 ] , 0 ) ;
F_36 ( V_2 , V_42 -> V_52 [ 3 ] , 0 ) ;
}
F_39 ( & V_2 -> V_10 ) ;
}
static void F_41 ( struct V_1 * V_2 , struct V_41 * V_42 ,
int V_24 , T_3 V_58 , int V_59 )
{
T_3 V_60 = ( V_58 - 0x10 ) & 0xFFF8 ;
if ( ! V_59 ) {
if ( ! ( V_42 -> V_46 & V_48 ) )
V_60 |= 4 ;
if ( V_42 -> V_46 & V_47 )
V_60 |= 2 ;
}
F_25 ( V_2 , V_42 -> V_52 [ V_24 ] << 3 , V_60 ) ;
#ifdef F_21
V_42 -> V_61 [ V_24 ] = V_60 ;
#endif
}
static void F_42 ( struct V_1 * V_2 , struct V_41 * V_42 ,
struct V_43 * V_44 )
{
T_3 V_62 ;
int V_63 = 0 ;
int V_24 , V_52 ;
int V_21 , V_64 ;
unsigned long V_9 ;
T_3 V_37 ;
V_64 = V_42 -> V_65 >> V_42 -> V_66 ;
if ( V_42 -> V_46 & V_47 )
V_63 ++ ;
for ( V_24 = 0 ; V_24 <= V_63 ; V_24 ++ ) {
V_52 = V_42 -> V_52 [ V_24 ] ;
F_41 ( V_2 , V_42 , V_24 , V_42 -> V_67 -> V_68 . V_58 , 0 ) ;
V_62 = V_42 -> V_67 -> V_68 . V_58 ;
V_62 -= V_2 -> V_69 . V_58 ;
V_62 >>= 1 ;
V_62 |= 0x00400000 ;
if ( V_42 -> V_46 & V_47 ) {
if ( V_24 )
V_62 |= 0x00800000 ;
if ( V_42 -> V_46 & V_48 )
V_62 >>= 1 ;
}
V_42 -> V_53 [ V_24 ] = V_62 & 0xFFFF ;
for ( V_21 = 0 ; V_21 < 16 ; V_21 ++ )
F_22 ( V_2 , V_52 , V_21 , 0x0000 ) ;
F_22 ( V_2 , V_52 , 4 , ( ( V_62 >> 16 ) & 0xFF ) << 8 ) ;
F_22 ( V_2 , V_52 , 5 , V_62 & 0xFFFF ) ;
F_22 ( V_2 , V_52 , 6 , ( V_62 + V_64 ) & 0xFFFF ) ;
F_22 ( V_2 , V_52 , 7 , V_64 ) ;
F_22 ( V_2 , V_52 , 8 , 0x0000 ) ;
F_22 ( V_2 , V_52 , 9 , 0xD000 ) ;
F_22 ( V_2 , V_52 , 11 , 0x0000 ) ;
F_22 ( V_2 , V_52 , 0 , 0x400F ) ;
if ( V_42 -> V_46 & V_48 )
V_42 -> V_56 [ V_24 ] = V_70 ;
else
V_42 -> V_56 [ V_24 ] = V_71 ;
if ( V_42 -> V_46 & V_47 ) {
F_22 ( V_2 , V_52 , 10 ,
0x8F00 | ( V_24 ? 0 : 0x10 ) ) ;
V_42 -> V_56 [ V_24 ] += 1 ;
} else
F_22 ( V_2 , V_52 , 10 , 0x8F08 ) ;
}
F_4 ( & V_2 -> V_10 , V_9 ) ;
F_2 ( 1 , V_2 -> V_5 + 0x04 ) ;
F_2 ( F_7 ( V_2 -> V_5 + V_72 ) | V_73 , V_2 -> V_5 + V_72 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
V_37 = V_44 -> V_45 ;
if ( V_37 > 48000 )
V_37 = 48000 ;
if ( V_37 < 4000 )
V_37 = 4000 ;
if ( ! ( V_42 -> V_46 & V_48 ) && ! ( V_42 -> V_46 & V_47 ) )
V_37 >>= 1 ;
V_37 = F_33 ( V_2 , V_37 ) ;
F_35 ( V_2 , V_42 -> V_52 [ 0 ] , V_37 ) ;
F_35 ( V_2 , V_42 -> V_52 [ 1 ] , V_37 ) ;
}
static void F_43 ( struct V_1 * V_2 , struct V_41 * V_42 , int V_24 ,
unsigned int V_62 , unsigned int V_74 ,
int V_55 , int V_75 )
{
int V_21 , V_52 = V_42 -> V_52 [ V_24 ] ;
V_42 -> V_56 [ V_24 ] = V_55 ;
F_41 ( V_2 , V_42 , V_24 , V_62 , 1 ) ;
V_62 -= V_2 -> V_69 . V_58 ;
V_62 >>= 1 ;
V_42 -> V_53 [ V_24 ] = V_62 & 0xFFFF ;
V_62 |= 0x00400000 ;
for ( V_21 = 0 ; V_21 < 16 ; V_21 ++ )
F_22 ( V_2 , V_52 , V_21 , 0x0000 ) ;
F_22 ( V_2 , V_52 , 2 , 0x8 ) ;
F_22 ( V_2 , V_52 , 4 , ( ( V_62 >> 16 ) & 0xFF ) << 8 ) ;
F_22 ( V_2 , V_52 , 5 , V_62 & 0xFFFF ) ;
F_22 ( V_2 , V_52 , 6 , ( V_62 + V_74 ) & 0xFFFF ) ;
F_22 ( V_2 , V_52 , 7 , V_74 ) ;
F_22 ( V_2 , V_52 , 8 , 0x00F0 ) ;
F_22 ( V_2 , V_52 , 9 , 0x0000 ) ;
F_22 ( V_2 , V_52 , 10 , 0x8F08 ) ;
F_22 ( V_2 , V_52 , 11 , V_75 ) ;
F_22 ( V_2 , V_52 , 0 , 0x400F ) ;
}
static void F_44 ( struct V_1 * V_2 , struct V_41 * V_42 ,
struct V_43 * V_44 )
{
int V_64 ;
T_3 V_37 ;
unsigned long V_9 ;
V_64 = V_42 -> V_65 >> V_42 -> V_66 ;
F_43 ( V_2 , V_42 , 2 ,
V_42 -> V_76 -> V_68 . V_58 , V_77 / 4 ,
V_78 , 0x14 ) ;
F_43 ( V_2 , V_42 , 0 , V_42 -> V_67 -> V_68 . V_58 , V_64 ,
V_79 , V_42 -> V_52 [ 2 ] ) ;
if ( V_42 -> V_46 & V_47 ) {
F_43 ( V_2 , V_42 , 3 ,
V_42 -> V_76 -> V_68 . V_58 + V_77 / 2 ,
V_77 / 4 ,
V_78 , 0x15 ) ;
F_43 ( V_2 , V_42 , 1 ,
V_42 -> V_67 -> V_68 . V_58 + V_64 * 2 , V_64 ,
V_79 , V_42 -> V_52 [ 3 ] ) ;
}
V_37 = V_44 -> V_45 ;
if ( V_37 > 47999 )
V_37 = 47999 ;
if ( V_37 < 4000 )
V_37 = 4000 ;
V_37 = F_33 ( V_2 , V_37 ) ;
F_35 ( V_2 , V_42 -> V_52 [ 0 ] , V_37 ) ;
F_35 ( V_2 , V_42 -> V_52 [ 1 ] , V_37 ) ;
V_37 = 0x10000 ;
F_35 ( V_2 , V_42 -> V_52 [ 2 ] , V_37 ) ;
F_35 ( V_2 , V_42 -> V_52 [ 3 ] , V_37 ) ;
F_4 ( & V_2 -> V_10 , V_9 ) ;
F_2 ( 1 , V_2 -> V_5 + 0x04 ) ;
F_2 ( F_7 ( V_2 -> V_5 + V_72 ) | V_73 , V_2 -> V_5 + V_72 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
}
static int F_45 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_46 ( V_81 ) ;
struct V_43 * V_44 = V_81 -> V_44 ;
struct V_41 * V_42 = V_44 -> V_18 ;
V_42 -> V_65 = F_47 ( V_81 ) ;
V_42 -> V_49 = F_48 ( V_81 ) ;
V_42 -> V_66 = 1 ;
V_42 -> V_46 = 0 ;
if ( F_49 ( V_44 -> V_82 ) == 16 )
V_42 -> V_46 |= V_48 ;
if ( V_44 -> V_83 > 1 ) {
V_42 -> V_46 |= V_47 ;
if ( V_42 -> V_46 & V_48 )
V_42 -> V_66 ++ ;
}
V_42 -> V_35 = F_32 ( V_2 , V_42 , V_44 ) ;
switch ( V_42 -> V_55 ) {
case V_84 :
F_42 ( V_2 , V_42 , V_44 ) ;
break;
case V_57 :
F_44 ( V_2 , V_42 , V_44 ) ;
break;
}
return 0 ;
}
static int F_50 ( struct V_80 * V_81 , int V_85 )
{
struct V_1 * V_2 = F_46 ( V_81 ) ;
struct V_41 * V_42 = V_81 -> V_44 -> V_18 ;
F_38 ( & V_2 -> V_86 ) ;
switch ( V_85 ) {
case V_87 :
case V_88 :
if ( V_42 -> V_89 )
break;
F_29 ( V_2 , V_42 -> V_35 ) ;
V_42 -> V_90 = 0 ;
V_42 -> V_91 = 0 ;
F_37 ( V_2 , V_42 ) ;
V_42 -> V_89 = 1 ;
break;
case V_92 :
case V_93 :
if ( ! V_42 -> V_89 )
break;
F_40 ( V_2 , V_42 ) ;
V_42 -> V_89 = 0 ;
F_30 ( V_2 ) ;
break;
}
F_39 ( & V_2 -> V_86 ) ;
return 0 ;
}
static T_4 F_51 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_46 ( V_81 ) ;
struct V_41 * V_42 = V_81 -> V_44 -> V_18 ;
unsigned int V_94 ;
V_94 = F_34 ( V_2 , V_42 ) << V_42 -> V_66 ;
return F_52 ( V_81 -> V_44 , V_94 % V_42 -> V_65 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_95 = 0 ;
struct V_96 * V_68 ;
F_54 ( & V_2 -> V_97 ) ;
F_31 (buf, &chip->buf_list, list) {
if ( V_68 -> V_98 && V_68 -> V_68 . V_99 > V_95 )
V_95 = V_68 -> V_68 . V_99 ;
}
F_55 ( & V_2 -> V_97 ) ;
if ( V_95 >= 128 * 1024 )
V_95 = 127 * 1024 ;
return V_95 ;
}
static struct V_96 * F_56 ( struct V_1 * V_2 , int V_64 )
{
struct V_96 * V_68 ;
V_64 = F_57 ( V_64 , V_100 ) ;
F_54 ( & V_2 -> V_97 ) ;
F_31 (buf, &chip->buf_list, list) {
if ( V_68 -> V_98 && V_68 -> V_68 . V_99 >= V_64 )
goto V_101;
}
F_55 ( & V_2 -> V_97 ) ;
return NULL ;
V_101:
if ( V_68 -> V_68 . V_99 > V_64 ) {
struct V_96 * V_102 = F_58 ( sizeof( * V_102 ) , V_103 ) ;
if ( V_102 == NULL ) {
F_55 ( & V_2 -> V_97 ) ;
return NULL ;
}
V_102 -> V_68 = V_68 -> V_68 ;
V_102 -> V_68 . V_99 -= V_64 ;
V_102 -> V_68 . V_104 += V_64 ;
V_102 -> V_68 . V_58 += V_64 ;
V_102 -> V_98 = 1 ;
V_68 -> V_68 . V_99 = V_64 ;
F_59 ( & V_102 -> V_105 , & V_68 -> V_105 ) ;
}
V_68 -> V_98 = 0 ;
F_55 ( & V_2 -> V_97 ) ;
return V_68 ;
}
static void F_60 ( struct V_1 * V_2 , struct V_96 * V_68 )
{
struct V_96 * V_102 ;
F_54 ( & V_2 -> V_97 ) ;
V_68 -> V_98 = 1 ;
if ( V_68 -> V_105 . V_106 != & V_2 -> V_107 ) {
V_102 = F_61 ( V_68 -> V_105 . V_106 , struct V_96 , V_105 ) ;
if ( V_102 -> V_98 ) {
V_102 -> V_68 . V_99 += V_68 -> V_68 . V_99 ;
F_62 ( & V_68 -> V_105 ) ;
F_63 ( V_68 ) ;
V_68 = V_102 ;
}
}
if ( V_68 -> V_105 . V_108 != & V_2 -> V_107 ) {
V_102 = F_61 ( V_68 -> V_105 . V_108 , struct V_96 , V_105 ) ;
if ( V_102 -> V_98 ) {
V_68 -> V_68 . V_99 += V_102 -> V_68 . V_99 ;
F_62 ( & V_102 -> V_105 ) ;
F_63 ( V_102 ) ;
}
}
F_55 ( & V_2 -> V_97 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_109 * V_110 ;
if ( ! V_2 -> V_69 . V_104 )
return;
F_65 ( & V_2 -> V_69 , F_66 ( V_2 -> V_111 ) ) ;
while ( ( V_110 = V_2 -> V_107 . V_108 ) != & V_2 -> V_107 ) {
struct V_96 * V_102 = F_61 ( V_110 , struct V_96 , V_105 ) ;
F_62 ( V_110 ) ;
F_63 ( V_102 ) ;
}
}
static int T_5
F_67 ( struct V_1 * V_2 )
{
int V_112 ;
struct V_96 * V_102 ;
V_2 -> V_69 . V_113 . type = V_114 ;
V_2 -> V_69 . V_113 . V_113 = F_68 ( V_2 -> V_111 ) ;
if ( ! F_69 ( & V_2 -> V_69 , F_66 ( V_2 -> V_111 ) ) ) {
V_112 = F_70 ( V_114 ,
F_68 ( V_2 -> V_111 ) ,
V_2 -> V_115 , & V_2 -> V_69 ) ;
if ( V_112 < 0 || ! V_2 -> V_69 . V_104 ) {
F_71 ( V_116 L_4 ,
V_2 -> V_115 ) ;
return - V_117 ;
}
if ( ( V_2 -> V_69 . V_58 + V_2 -> V_69 . V_99 - 1 ) & ~ ( ( 1 << 28 ) - 1 ) ) {
F_72 ( & V_2 -> V_69 ) ;
F_71 ( V_116 L_5 ) ;
return - V_117 ;
}
}
F_73 ( & V_2 -> V_107 ) ;
V_102 = F_58 ( sizeof( * V_102 ) , V_103 ) ;
if ( V_102 == NULL ) {
F_64 ( V_2 ) ;
return - V_117 ;
}
memset ( V_2 -> V_69 . V_104 , 0 , V_100 ) ;
V_102 -> V_68 = V_2 -> V_69 ;
V_102 -> V_68 . V_104 += V_100 ;
V_102 -> V_68 . V_58 += V_100 ;
V_102 -> V_68 . V_99 -= V_100 ;
V_102 -> V_98 = 1 ;
F_59 ( & V_102 -> V_105 , & V_2 -> V_107 ) ;
return 0 ;
}
static int F_74 ( struct V_80 * V_81 ,
struct V_118 * V_119 )
{
struct V_1 * V_2 = F_46 ( V_81 ) ;
struct V_43 * V_44 = V_81 -> V_44 ;
struct V_41 * V_120 = V_44 -> V_18 ;
int V_64 = F_75 ( V_119 ) ;
if ( V_120 -> V_67 ) {
if ( V_120 -> V_67 -> V_68 . V_99 >= V_64 ) {
V_44 -> V_121 = V_64 ;
return 0 ;
}
F_60 ( V_2 , V_120 -> V_67 ) ;
}
V_120 -> V_67 = F_56 ( V_2 , V_64 ) ;
if ( V_120 -> V_67 == NULL ) {
return - V_117 ;
}
F_76 ( V_81 , & V_120 -> V_67 -> V_68 ) ;
return 1 ;
}
static int F_77 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_46 ( V_81 ) ;
struct V_43 * V_44 = V_81 -> V_44 ;
struct V_41 * V_120 ;
if ( V_44 -> V_18 == NULL )
return 0 ;
V_120 = V_44 -> V_18 ;
if ( V_120 -> V_67 ) {
F_60 ( V_2 , V_120 -> V_67 ) ;
V_120 -> V_67 = NULL ;
}
return 0 ;
}
static int F_78 ( struct V_1 * V_2 , int type )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < V_25 ; V_52 += 2 ) {
if ( V_2 -> V_52 [ V_52 ] == V_122 &&
V_2 -> V_52 [ V_52 + 1 ] == V_122 ) {
V_2 -> V_52 [ V_52 ] = V_2 -> V_52 [ V_52 + 1 ] = type ;
return V_52 ;
}
}
return - V_123 ;
}
static void F_79 ( struct V_1 * V_2 , int V_52 )
{
V_2 -> V_52 [ V_52 ] = V_2 -> V_52 [ V_52 + 1 ] = V_122 ;
}
static int F_80 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_46 ( V_81 ) ;
struct V_43 * V_44 = V_81 -> V_44 ;
struct V_41 * V_42 ;
int V_124 ;
V_124 = F_78 ( V_2 , V_125 ) ;
if ( V_124 < 0 )
return V_124 ;
V_42 = F_81 ( sizeof( * V_42 ) , V_103 ) ;
if ( ! V_42 ) {
F_79 ( V_2 , V_124 ) ;
return - V_117 ;
}
V_42 -> V_52 [ 0 ] = V_124 ;
V_42 -> V_52 [ 1 ] = V_124 + 1 ;
V_42 -> V_56 [ 0 ] = 0 ;
V_42 -> V_56 [ 1 ] = 0 ;
V_42 -> V_89 = 0 ;
V_42 -> V_81 = V_81 ;
V_42 -> V_55 = V_84 ;
V_44 -> V_18 = V_42 ;
V_44 -> V_126 = V_127 ;
V_44 -> V_126 . V_128 = V_44 -> V_126 . V_129 =
F_53 ( V_2 ) ;
F_82 ( & V_2 -> V_86 ) ;
F_59 ( & V_42 -> V_105 , & V_2 -> V_130 ) ;
F_83 ( & V_2 -> V_86 ) ;
return 0 ;
}
static int F_84 ( struct V_80 * V_81 )
{
struct V_43 * V_44 = V_81 -> V_44 ;
struct V_1 * V_2 = F_46 ( V_81 ) ;
struct V_41 * V_42 ;
int V_124 , V_131 ;
V_124 = F_78 ( V_2 , V_132 ) ;
if ( V_124 < 0 )
return V_124 ;
V_131 = F_78 ( V_2 , V_133 ) ;
if ( V_131 < 0 ) {
F_79 ( V_2 , V_124 ) ;
return V_131 ;
}
V_42 = F_81 ( sizeof( * V_42 ) , V_103 ) ;
if ( ! V_42 ) {
F_79 ( V_2 , V_124 ) ;
F_79 ( V_2 , V_131 ) ;
return - V_117 ;
}
V_42 -> V_52 [ 0 ] = V_124 ;
V_42 -> V_52 [ 1 ] = V_124 + 1 ;
V_42 -> V_52 [ 2 ] = V_131 ;
V_42 -> V_52 [ 3 ] = V_131 + 1 ;
V_42 -> V_56 [ 0 ] = 0 ;
V_42 -> V_56 [ 1 ] = 0 ;
V_42 -> V_56 [ 2 ] = 0 ;
V_42 -> V_56 [ 3 ] = 0 ;
V_42 -> V_89 = 0 ;
V_42 -> V_81 = V_81 ;
V_42 -> V_55 = V_57 ;
if ( ( V_42 -> V_76 = F_56 ( V_2 , V_77 ) ) == NULL ) {
F_79 ( V_2 , V_124 ) ;
F_79 ( V_2 , V_131 ) ;
F_63 ( V_42 ) ;
return - V_117 ;
}
memset ( V_42 -> V_76 -> V_68 . V_104 , 0 , V_77 ) ;
V_44 -> V_18 = V_42 ;
V_44 -> V_126 = V_134 ;
V_44 -> V_126 . V_128 = V_44 -> V_126 . V_129 =
F_53 ( V_2 ) - 1024 ;
F_85 ( V_44 , 0 , V_135 ) ;
F_82 ( & V_2 -> V_86 ) ;
F_59 ( & V_42 -> V_105 , & V_2 -> V_130 ) ;
F_83 ( & V_2 -> V_86 ) ;
return 0 ;
}
static int F_86 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_46 ( V_81 ) ;
struct V_41 * V_42 ;
if ( V_81 -> V_44 -> V_18 == NULL )
return 0 ;
V_42 = V_81 -> V_44 -> V_18 ;
F_82 ( & V_2 -> V_86 ) ;
F_62 ( & V_42 -> V_105 ) ;
F_83 ( & V_2 -> V_86 ) ;
F_79 ( V_2 , V_42 -> V_52 [ 0 ] ) ;
F_63 ( V_42 ) ;
return 0 ;
}
static int F_87 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_46 ( V_81 ) ;
struct V_41 * V_42 ;
if ( V_81 -> V_44 -> V_18 == NULL )
return 0 ;
V_42 = V_81 -> V_44 -> V_18 ;
F_82 ( & V_2 -> V_86 ) ;
F_62 ( & V_42 -> V_105 ) ;
F_83 ( & V_2 -> V_86 ) ;
F_60 ( V_2 , V_42 -> V_76 ) ;
F_79 ( V_2 , V_42 -> V_52 [ 0 ] ) ;
F_79 ( V_2 , V_42 -> V_52 [ 2 ] ) ;
F_63 ( V_42 ) ;
return 0 ;
}
static void T_5 F_88 ( struct V_1 * V_2 )
{
int V_21 , V_52 ;
unsigned int V_62 , V_51 , V_136 ;
struct V_96 * V_67 ;
struct V_137 V_138 , V_139 ;
if ( V_2 -> clock == 0 )
V_2 -> clock = 48000 ;
if ( ( V_52 = F_78 ( V_2 , V_125 ) ) < 0 ) {
F_71 ( V_116 L_6 ) ;
return;
}
if ( ( V_67 = F_56 ( V_2 , V_140 ) ) == NULL ) {
F_71 ( V_116 L_7 , V_2 -> clock ) ;
F_79 ( V_2 , V_52 ) ;
return;
}
memset ( V_67 -> V_68 . V_104 , 0 , V_140 ) ;
F_25 ( V_2 , V_52 << 3 , ( V_67 -> V_68 . V_58 - 0x10 ) & 0xfff8 ) ;
V_62 = ( unsigned int ) ( ( V_67 -> V_68 . V_58 - V_2 -> V_69 . V_58 ) >> 1 ) ;
V_62 |= 0x00400000 ;
for ( V_21 = 0 ; V_21 < 16 ; V_21 ++ )
F_22 ( V_2 , V_52 , V_21 , 0x0000 ) ;
F_22 ( V_2 , V_52 , 0 , 0x400f ) ;
F_22 ( V_2 , V_52 , 4 , ( ( V_62 >> 16 ) & 0xff ) << 8 ) ;
F_22 ( V_2 , V_52 , 5 , V_62 & 0xffff ) ;
F_22 ( V_2 , V_52 , 6 , ( V_62 + V_140 / 2 ) & 0xffff ) ;
F_22 ( V_2 , V_52 , 7 , V_140 / 2 ) ;
F_22 ( V_2 , V_52 , 8 , 0x0000 ) ;
F_22 ( V_2 , V_52 , 9 , 0xD000 ) ;
F_22 ( V_2 , V_52 , 10 , 0x8F08 ) ;
F_22 ( V_2 , V_52 , 11 , 0x0000 ) ;
F_82 ( & V_2 -> V_10 ) ;
F_2 ( 1 , V_2 -> V_5 + 0x04 ) ;
F_2 ( F_7 ( V_2 -> V_5 + V_72 ) | V_73 , V_2 -> V_5 + V_72 ) ;
F_83 ( & V_2 -> V_10 ) ;
F_35 ( V_2 , V_52 , ( ( unsigned int ) 48000 << 16 ) / V_2 -> clock ) ;
V_2 -> V_141 = 1 ;
V_2 -> V_142 = V_52 ;
F_82 ( & V_2 -> V_10 ) ;
F_29 ( V_2 , V_39 ) ;
F_19 ( V_2 , V_52 , 5 , V_62 & 0xffff ) ;
F_36 ( V_2 , V_52 , V_70 ) ;
F_89 ( & V_138 ) ;
F_83 ( & V_2 -> V_10 ) ;
F_90 ( 50 ) ;
F_82 ( & V_2 -> V_10 ) ;
V_51 = F_23 ( V_2 , V_52 , 5 ) ;
F_89 ( & V_139 ) ;
F_36 ( V_2 , V_52 , 0 ) ;
F_30 ( V_2 ) ;
V_2 -> V_141 = 0 ;
F_83 ( & V_2 -> V_10 ) ;
V_51 -= ( V_62 & 0xffff ) ;
V_51 &= 0xfffe ;
V_51 += V_2 -> V_143 * ( V_140 / 2 ) ;
V_136 = V_139 . V_144 - V_138 . V_144 ;
V_136 *= 1000000 ;
if ( V_139 . V_145 < V_138 . V_145 )
V_136 -= V_138 . V_145 - V_139 . V_145 ;
else
V_136 += V_139 . V_145 - V_138 . V_145 ;
if ( V_136 == 0 ) {
F_71 ( V_116 L_8 ) ;
} else {
V_51 *= 1000 ;
V_51 = ( V_51 / V_136 ) * 1000 + ( ( V_51 % V_136 ) * 1000 ) / V_136 ;
if ( V_51 < 47500 || V_51 > 48500 ) {
if ( V_51 >= 40000 && V_51 <= 50000 )
V_2 -> clock = ( V_2 -> clock * V_51 ) / 48000 ;
}
F_91 ( V_146 L_9 , V_2 -> clock ) ;
}
F_60 ( V_2 , V_67 ) ;
F_79 ( V_2 , V_52 ) ;
}
static void F_92 ( struct V_147 * V_148 )
{
struct V_1 * V_54 = V_148 -> V_18 ;
F_64 ( V_54 ) ;
V_54 -> V_148 = NULL ;
}
static int T_5
F_93 ( struct V_1 * V_2 , int V_149 )
{
struct V_147 * V_148 ;
int V_112 ;
if ( ( V_112 = F_67 ( V_2 ) ) < 0 )
return V_112 ;
F_25 ( V_2 , 0x01FC , V_2 -> V_69 . V_58 >> 12 ) ;
F_25 ( V_2 , 0x01FD , V_2 -> V_69 . V_58 >> 12 ) ;
F_25 ( V_2 , 0x01FE , V_2 -> V_69 . V_58 >> 12 ) ;
F_25 ( V_2 , 0x01FF , V_2 -> V_69 . V_58 >> 12 ) ;
if ( ( V_112 = F_94 ( V_2 -> V_150 , L_10 , V_149 ,
V_2 -> V_151 ,
V_2 -> V_152 , & V_148 ) ) < 0 )
return V_112 ;
V_148 -> V_18 = V_2 ;
V_148 -> V_153 = F_92 ;
F_95 ( V_148 , V_154 , & V_155 ) ;
F_95 ( V_148 , V_156 , & V_157 ) ;
V_148 -> V_158 = 0 ;
strcpy ( V_148 -> V_159 , L_10 ) ;
V_2 -> V_148 = V_148 ;
return 0 ;
}
static void F_96 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
unsigned int V_160 ;
unsigned int V_161 ;
unsigned int V_162 ;
V_160 = F_23 ( V_2 , 0 , 5 ) ;
V_161 = F_23 ( V_2 , 1 , 5 ) ;
V_162 = ( V_160 > V_161 ? V_160 - V_161 : V_161 - V_160 ) ;
if ( V_162 > 1 )
F_1 ( V_2 , V_23 , V_160 ) ;
}
static void F_97 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
unsigned int V_91 ;
unsigned int V_162 ;
struct V_80 * V_163 = V_42 -> V_81 ;
if ( V_163 == NULL || ! V_42 -> V_89 )
return;
V_91 = F_34 ( V_2 , V_42 ) << V_42 -> V_66 ;
V_91 %= V_42 -> V_65 ;
V_162 = ( V_42 -> V_65 + V_91 - V_42 -> V_91 ) % V_42 -> V_65 ;
V_42 -> V_91 = V_91 ;
V_42 -> V_90 += V_162 ;
if ( V_42 -> V_90 > V_42 -> V_49 ) {
F_39 ( & V_2 -> V_86 ) ;
F_98 ( V_163 ) ;
F_38 ( & V_2 -> V_86 ) ;
V_42 -> V_90 %= V_42 -> V_49 ;
}
}
static void F_99 ( struct V_164 * V_165 )
{
struct V_1 * V_2 = F_100 ( V_165 , struct V_1 , V_166 ) ;
int V_167 , V_17 ;
V_167 = F_10 ( V_2 -> V_5 + 0x1c ) & 0xee ;
F_15 ( 0x88 , V_2 -> V_5 + 0x1c ) ;
F_15 ( 0x88 , V_2 -> V_5 + 0x1d ) ;
F_15 ( 0x88 , V_2 -> V_5 + 0x1e ) ;
F_15 ( 0x88 , V_2 -> V_5 + 0x1f ) ;
if ( V_2 -> V_168 )
return;
#ifndef F_101
if ( ! V_2 -> V_169 || ! V_2 -> V_170 )
return;
V_17 = F_102 ( V_2 -> V_16 , V_171 ) ;
switch ( V_167 ) {
case 0x88 :
V_17 ^= 0x8000 ;
break;
case 0xaa :
if ( ( V_17 & 0x7f ) > 0 )
V_17 -- ;
if ( ( V_17 & 0x7f00 ) > 0 )
V_17 -= 0x0100 ;
break;
case 0x66 :
if ( ( V_17 & 0x7f ) < 0x1f )
V_17 ++ ;
if ( ( V_17 & 0x7f00 ) < 0x1f00 )
V_17 += 0x0100 ;
break;
}
if ( F_103 ( V_2 -> V_16 , V_171 , V_17 ) )
F_104 ( V_2 -> V_150 , V_172 ,
& V_2 -> V_170 -> V_173 ) ;
#else
if ( ! V_2 -> V_174 )
return;
V_17 = 0 ;
switch ( V_167 ) {
case 0x88 :
V_17 = V_175 ;
break;
case 0xaa :
V_17 = V_176 ;
break;
case 0x66 :
V_17 = V_177 ;
break;
}
if ( V_17 ) {
F_105 ( V_2 -> V_174 , V_17 , 1 ) ;
F_106 ( V_2 -> V_174 ) ;
F_105 ( V_2 -> V_174 , V_17 , 0 ) ;
F_106 ( V_2 -> V_174 ) ;
}
#endif
}
static T_6 F_107 ( int V_178 , void * V_179 )
{
struct V_1 * V_2 = V_179 ;
T_3 V_180 ;
if ( ! ( V_180 = F_10 ( V_2 -> V_5 + 0x1A ) ) )
return V_181 ;
F_2 ( F_7 ( V_2 -> V_5 + 4 ) & 1 , V_2 -> V_5 + 4 ) ;
if ( V_180 & V_182 )
F_108 ( & V_2 -> V_166 ) ;
F_15 ( 0xFF , V_2 -> V_5 + 0x1A ) ;
if ( ( V_180 & V_183 ) && V_2 -> V_184 ) {
F_109 ( V_178 , V_2 -> V_184 -> V_18 ) ;
}
if ( V_180 & V_185 ) {
struct V_41 * V_42 ;
F_38 ( & V_2 -> V_86 ) ;
F_31 (es, &chip->substream_list, list) {
if ( V_42 -> V_89 ) {
F_97 ( V_2 , V_42 ) ;
if ( V_42 -> V_46 & V_47 )
F_96 ( V_2 , V_42 ) ;
}
}
F_39 ( & V_2 -> V_86 ) ;
if ( V_2 -> V_141 ) {
unsigned int V_186 = F_23 ( V_2 , V_2 -> V_142 , 5 ) ;
if ( V_186 < V_2 -> V_187 )
V_2 -> V_143 ++ ;
V_2 -> V_187 = V_186 ;
}
}
return V_188 ;
}
static int T_5
F_110 ( struct V_1 * V_2 )
{
struct V_189 * V_190 ;
struct V_191 V_16 ;
#ifndef F_101
struct V_192 V_193 ;
#endif
int V_112 ;
static struct V_194 V_195 = {
. V_196 = F_14 ,
. V_197 = F_16 ,
} ;
if ( ( V_112 = V_189 ( V_2 -> V_150 , 0 , & V_195 , NULL , & V_190 ) ) < 0 )
return V_112 ;
V_190 -> V_198 = 1 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_18 = V_2 ;
if ( ( V_112 = F_111 ( V_190 , & V_16 , & V_2 -> V_16 ) ) < 0 )
return V_112 ;
#ifndef F_101
memset ( & V_193 , 0 , sizeof( V_193 ) ) ;
V_193 . V_199 = V_200 ;
strcpy ( V_193 . V_159 , L_11 ) ;
V_2 -> V_169 = F_112 ( V_2 -> V_150 , & V_193 ) ;
memset ( & V_193 , 0 , sizeof( V_193 ) ) ;
V_193 . V_199 = V_200 ;
strcpy ( V_193 . V_159 , L_12 ) ;
V_2 -> V_170 = F_112 ( V_2 -> V_150 , & V_193 ) ;
#endif
return 0 ;
}
static void F_113 ( struct V_1 * V_2 )
{
unsigned long V_201 = V_2 -> V_5 ;
unsigned short V_202 ;
unsigned short V_203 ;
unsigned short V_204 ;
unsigned int V_205 ;
V_202 = F_7 ( V_201 + 0x36 ) ;
F_2 ( F_7 ( V_201 + 0x3a ) & 0xfffc , V_201 + 0x3a ) ;
F_2 ( F_7 ( V_201 + 0x3c ) & 0xfffc , V_201 + 0x3c ) ;
F_2 ( 0x0000 , V_201 + 0x36 ) ;
V_203 = F_7 ( V_201 + 0x68 ) ;
F_114 ( V_2 -> V_111 , 0x58 , & V_204 ) ;
F_115 ( V_2 -> V_111 , V_206 , & V_205 ) ;
if ( V_204 & 1 )
V_203 |= 0x10 ;
F_2 ( 0xfffe , V_201 + 0x64 ) ;
F_2 ( 0x0001 , V_201 + 0x68 ) ;
F_2 ( 0x0000 , V_201 + 0x60 ) ;
F_116 ( 20 ) ;
F_2 ( 0x0001 , V_201 + 0x60 ) ;
F_90 ( 20 ) ;
F_2 ( V_203 | 0x1 , V_201 + 0x68 ) ;
F_2 ( ( F_7 ( V_201 + 0x38 ) & 0xfffc ) | 0x1 , V_201 + 0x38 ) ;
F_2 ( ( F_7 ( V_201 + 0x3a ) & 0xfffc ) | 0x1 , V_201 + 0x3a ) ;
F_2 ( ( F_7 ( V_201 + 0x3c ) & 0xfffc ) | 0x1 , V_201 + 0x3c ) ;
F_2 ( 0x0000 , V_201 + 0x36 ) ;
F_2 ( 0xfff7 , V_201 + 0x64 ) ;
V_203 = F_7 ( V_201 + 0x68 ) ;
F_2 ( 0x0009 , V_201 + 0x68 ) ;
F_2 ( 0x0001 , V_201 + 0x60 ) ;
F_116 ( 20 ) ;
F_2 ( 0x0009 , V_201 + 0x60 ) ;
F_90 ( 500 ) ;
F_2 ( F_7 ( V_201 + 0x3a ) & 0xfffc , V_201 + 0x3a ) ;
F_2 ( F_7 ( V_201 + 0x3c ) & 0xfffc , V_201 + 0x3c ) ;
#if 0
snd_printk(KERN_INFO "trying software reset\n");
outb(0x80 | 0x7c, ioaddr + 0x30);
for (w = 0;; w++) {
if ((inw(ioaddr + 0x30) & 1) == 0) {
if (inb(ioaddr + 0x32) != 0)
break;
outb(0x80 | 0x7d, ioaddr + 0x30);
if (((inw(ioaddr + 0x30) & 1) == 0)
&& (inb(ioaddr + 0x32) != 0))
break;
outb(0x80 | 0x7f, ioaddr + 0x30);
if (((inw(ioaddr + 0x30) & 1) == 0)
&& (inb(ioaddr + 0x32) != 0))
break;
}
if (w > 10000) {
outb(inb(ioaddr + 0x37) | 0x08, ioaddr + 0x37);
msleep(500);
outb(inb(ioaddr + 0x37) & ~0x08,
ioaddr + 0x37);
udelay(1);
outw(0x80, ioaddr + 0x30);
for (w = 0; w < 10000; w++) {
if ((inw(ioaddr + 0x30) & 1) == 0)
break;
}
}
}
#endif
if ( V_205 == V_207 || V_205 == V_208 ) {
F_2 ( 0xf9ff , V_201 + 0x64 ) ;
F_2 ( F_7 ( V_201 + 0x68 ) | 0x600 , V_201 + 0x68 ) ;
F_2 ( 0x0209 , V_201 + 0x60 ) ;
}
F_2 ( V_202 , V_201 + 0x36 ) ;
F_15 ( F_10 ( V_201 + 0xc0 ) | ( 1 << 5 ) , V_201 + 0xc0 ) ;
F_15 ( 0xff , V_201 + 0xc3 ) ;
F_15 ( 0xff , V_201 + 0xc4 ) ;
F_15 ( 0xff , V_201 + 0xc6 ) ;
F_15 ( 0xff , V_201 + 0xc8 ) ;
F_15 ( 0x3f , V_201 + 0xcf ) ;
F_15 ( 0x3f , V_201 + 0xd0 ) ;
}
static void F_117 ( struct V_1 * V_2 )
{
F_2 ( V_209 | V_210 ,
V_2 -> V_5 + V_72 ) ;
F_116 ( 10 ) ;
F_2 ( 0x0000 , V_2 -> V_5 + V_72 ) ;
F_116 ( 10 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
struct V_211 * V_111 = V_2 -> V_111 ;
int V_21 ;
unsigned long V_212 = V_2 -> V_5 ;
T_1 V_204 ;
T_3 V_213 ;
F_114 ( V_111 , V_214 , & V_204 ) ;
V_204 &= ~ V_215 ;
V_204 &= ~ ( V_216 | V_217 ) ;
V_204 &= ~ V_218 ;
V_204 |= V_219 ;
V_204 |= V_220 ;
V_204 &= ~ V_221 ;
V_204 &= ~ V_222 ;
F_119 ( V_111 , V_214 , V_204 ) ;
F_114 ( V_111 , V_223 , & V_204 ) ;
V_204 &= ~ ( 1 << 15 ) ;
V_204 &= ~ ( 1 << 14 ) ;
V_204 &= ~ V_224 ;
V_204 |= V_225 ;
V_204 |= V_226 ;
V_204 &= ~ V_227 ;
V_204 |= V_228 ;
V_204 &= ~ V_229 ;
V_204 &= ~ V_230 ;
V_204 &= ~ ( 1 << 1 ) ;
V_204 &= ~ V_231 ;
F_119 ( V_111 , V_223 , V_204 ) ;
F_114 ( V_111 , V_232 , & V_204 ) ;
V_204 &= ~ ( 1 << 0 ) ;
F_119 ( V_111 , V_232 , V_204 ) ;
F_114 ( V_111 , V_233 , & V_204 ) ;
V_204 |= V_234 ;
V_204 &= ~ V_235 ;
V_204 &= ~ ( 0x1f ) ;
F_119 ( V_111 , V_233 , V_204 ) ;
F_114 ( V_111 , 0x58 , & V_204 ) ;
V_204 |= 1 << 2 ;
V_204 |= 1 << 3 ;
V_204 &= ~ ( 1 << 11 ) ;
F_119 ( V_111 , 0x58 , V_204 ) ;
F_117 ( V_2 ) ;
F_2 ( 0xC090 , V_212 + V_236 ) ;
F_116 ( 20 ) ;
F_2 ( 0x3000 , V_212 + V_237 ) ;
F_116 ( 20 ) ;
F_113 ( V_2 ) ;
V_213 = F_120 ( V_212 + V_238 ) ;
V_213 &= ~ V_239 ;
F_121 ( V_213 , V_212 + V_238 ) ;
F_15 ( 0x88 , V_212 + 0x1c ) ;
F_15 ( 0x88 , V_212 + 0x1d ) ;
F_15 ( 0x88 , V_212 + 0x1e ) ;
F_15 ( 0x88 , V_212 + 0x1f ) ;
F_15 ( 0 , V_212 + V_240 ) ;
F_15 ( 3 , V_212 + V_241 ) ;
F_15 ( 0 , V_212 + V_242 ) ;
for ( V_21 = 0 ; V_21 < 16 ; V_21 ++ ) {
F_2 ( 0x01E0 + V_21 , V_212 + V_29 ) ;
F_2 ( 0x0000 , V_212 + V_30 ) ;
F_2 ( 0x01D0 + V_21 , V_212 + V_29 ) ;
F_2 ( 0x0000 , V_212 + V_30 ) ;
}
F_25 ( V_2 , V_243 ,
( F_26 ( V_2 , V_243 ) & 0xFF00 ) ) ;
F_25 ( V_2 , V_243 ,
F_26 ( V_2 , V_243 ) | 0x100 ) ;
F_25 ( V_2 , V_243 ,
F_26 ( V_2 , V_243 ) & ~ 0x200 ) ;
F_25 ( V_2 , V_243 ,
F_26 ( V_2 , V_243 ) | ~ 0x400 ) ;
F_3 ( V_2 , V_244 , 0x0000 ) ;
F_3 ( V_2 , 0x08 , 0xB004 ) ;
F_3 ( V_2 , 0x09 , 0x001B ) ;
F_3 ( V_2 , 0x0A , 0x8000 ) ;
F_3 ( V_2 , 0x0B , 0x3F37 ) ;
F_3 ( V_2 , 0x0C , 0x0098 ) ;
F_3 ( V_2 , 0x0C ,
( F_8 ( V_2 , 0x0C ) & ~ 0xF000 ) | 0x8000 ) ;
F_3 ( V_2 , 0x0C ,
( F_8 ( V_2 , 0x0C ) & ~ 0x0F00 ) | 0x0500 ) ;
F_3 ( V_2 , 0x0D , 0x7632 ) ;
V_204 = F_7 ( V_212 + V_245 ) ;
V_204 &= ~ 0xFA00 ;
V_204 |= 0xA000 ;
V_204 &= ~ 0x0200 ;
V_204 |= 0x0100 ;
V_204 |= 0x0080 ;
V_204 &= ~ 0x0060 ;
V_204 |= 0x0020 ;
V_204 &= ~ 0x000C ;
V_204 &= ~ 0x0001 ;
F_2 ( V_204 , V_212 + V_245 ) ;
for ( V_21 = 0 ; V_21 < V_25 ; V_21 ++ ) {
for ( V_204 = 0 ; V_204 < V_246 ; V_204 ++ )
F_22 ( V_2 , V_21 , V_204 , 0 ) ;
}
}
static void F_122 ( struct V_1 * V_2 )
{
unsigned short V_204 ;
V_204 = V_73 | V_247 ;
if ( V_2 -> V_184 )
V_204 |= V_248 ;
F_15 ( V_204 , V_2 -> V_5 + 0x1A ) ;
F_2 ( V_204 , V_2 -> V_5 + V_72 ) ;
}
static int F_123 ( struct V_149 * V_113 )
{
struct V_211 * V_111 = F_124 ( V_113 ) ;
struct V_249 * V_150 = F_125 ( V_113 ) ;
struct V_1 * V_2 = V_150 -> V_18 ;
if ( ! V_2 -> V_250 )
return 0 ;
V_2 -> V_168 = 1 ;
F_126 ( & V_2 -> V_166 ) ;
F_127 ( V_150 , V_251 ) ;
F_128 ( V_2 -> V_148 ) ;
F_129 ( V_2 -> V_16 ) ;
F_27 ( V_2 ) ;
F_130 ( V_111 ) ;
F_131 ( V_111 ) ;
F_132 ( V_111 , V_252 ) ;
return 0 ;
}
static int F_133 ( struct V_149 * V_113 )
{
struct V_211 * V_111 = F_124 ( V_113 ) ;
struct V_249 * V_150 = F_125 ( V_113 ) ;
struct V_1 * V_2 = V_150 -> V_18 ;
struct V_41 * V_42 ;
if ( ! V_2 -> V_250 )
return 0 ;
F_132 ( V_111 , V_253 ) ;
F_134 ( V_111 ) ;
if ( F_135 ( V_111 ) < 0 ) {
F_91 ( V_116 L_13
L_14 ) ;
F_136 ( V_150 ) ;
return - V_254 ;
}
F_137 ( V_111 ) ;
F_118 ( V_2 ) ;
if ( V_2 -> V_69 . V_58 ) {
F_25 ( V_2 , 0x01FC , V_2 -> V_69 . V_58 >> 12 ) ;
}
F_122 ( V_2 ) ;
F_138 ( V_2 -> V_16 ) ;
F_31 (es, &chip->substream_list, list) {
switch ( V_42 -> V_55 ) {
case V_84 :
F_42 ( V_2 , V_42 , V_42 -> V_81 -> V_44 ) ;
break;
case V_57 :
F_44 ( V_2 , V_42 , V_42 -> V_81 -> V_44 ) ;
break;
}
}
if ( V_2 -> V_38 )
F_28 ( V_2 ) ;
F_127 ( V_150 , V_255 ) ;
V_2 -> V_168 = 0 ;
return 0 ;
}
static int T_5 F_139 ( struct V_1 * V_2 , int V_113 )
{
struct V_256 * V_257 ;
struct V_258 * V_259 ;
T_1 V_17 ;
if ( ! V_260 [ V_113 ] )
return - V_261 ;
V_259 = F_140 ( V_262 , 8 , L_15 ) ;
if ( ! V_259 )
return - V_123 ;
V_2 -> V_256 = V_257 = F_141 () ;
if ( ! V_257 ) {
F_91 ( V_116 L_16 ) ;
F_142 ( V_259 ) ;
return - V_117 ;
}
F_114 ( V_2 -> V_111 , V_233 , & V_17 ) ;
F_119 ( V_2 -> V_111 , V_233 , V_17 | 0x04 ) ;
F_143 ( V_257 , L_17 ) ;
F_144 ( V_257 , L_18 , F_145 ( V_2 -> V_111 ) ) ;
F_146 ( V_257 , & V_2 -> V_111 -> V_113 ) ;
V_257 -> V_263 = V_262 ;
F_147 ( V_257 , V_259 ) ;
F_148 ( V_257 ) ;
return 0 ;
}
static void F_149 ( struct V_1 * V_2 )
{
if ( V_2 -> V_256 ) {
struct V_258 * V_259 = F_150 ( V_2 -> V_256 ) ;
F_151 ( V_2 -> V_256 ) ;
V_2 -> V_256 = NULL ;
F_142 ( V_259 ) ;
}
}
static inline int F_139 ( struct V_1 * V_2 , int V_113 ) { return - V_264 ; }
static inline void F_149 ( struct V_1 * V_2 ) { }
static int T_5 F_152 ( struct V_1 * V_2 )
{
struct V_174 * V_174 ;
int V_112 ;
V_174 = F_153 () ;
if ( ! V_174 )
return - V_117 ;
snprintf ( V_2 -> V_265 , sizeof( V_2 -> V_265 ) , L_19 ,
F_145 ( V_2 -> V_111 ) ) ;
V_174 -> V_159 = V_2 -> V_150 -> V_266 ;
V_174 -> V_265 = V_2 -> V_265 ;
V_174 -> V_173 . V_267 = V_268 ;
V_174 -> V_173 . V_269 = V_2 -> V_111 -> V_269 ;
V_174 -> V_173 . V_270 = V_2 -> V_111 -> V_149 ;
V_174 -> V_113 . V_271 = & V_2 -> V_111 -> V_113 ;
F_154 ( V_272 , V_174 -> V_273 ) ;
F_154 ( V_175 , V_174 -> V_274 ) ;
F_154 ( V_177 , V_174 -> V_274 ) ;
F_154 ( V_176 , V_174 -> V_274 ) ;
V_112 = F_155 ( V_174 ) ;
if ( V_112 ) {
F_156 ( V_174 ) ;
return V_112 ;
}
V_2 -> V_174 = V_174 ;
return 0 ;
}
static void F_157 ( struct V_275 * V_276 , T_2 V_277 )
{
struct V_1 * V_2 = V_276 -> V_18 ;
unsigned long V_263 = V_2 -> V_5 + V_278 ;
T_1 V_17 = 0 ;
V_17 |= ( V_277 & V_279 ) ? V_280 : 0 ;
V_17 |= ( V_277 & V_281 ) ? V_282 : 0 ;
V_17 |= ( V_277 & V_283 ) ? V_284 : 0 ;
F_2 ( V_17 , V_263 ) ;
}
static T_2 F_158 ( struct V_275 * V_276 )
{
struct V_1 * V_2 = V_276 -> V_18 ;
unsigned long V_263 = V_2 -> V_5 + V_278 ;
T_1 V_17 = F_7 ( V_263 ) ;
T_2 V_285 ;
V_285 = 0 ;
if ( V_17 & V_280 )
V_285 |= V_279 ;
if ( V_17 & V_286 )
V_285 |= V_287 ;
return V_285 ;
}
static void F_159 ( struct V_275 * V_276 , bool V_288 )
{
struct V_1 * V_2 = V_276 -> V_18 ;
unsigned long V_263 = V_2 -> V_5 + V_278 ;
T_1 V_289 = F_7 ( V_263 + V_290 ) ;
if ( V_288 ) {
F_2 ( ~ ( V_280 | V_282 | V_284 ) , V_263 + V_291 ) ;
F_2 ( V_289 | V_280 | V_282 | V_284 , V_263 + V_290 ) ;
} else {
F_2 ( ~ ( V_282 | V_284 | V_280 | V_286 ) , V_263 + V_291 ) ;
F_2 ( ( V_289 & ~ ( V_280 | V_286 ) ) | V_282 | V_284 , V_263 + V_290 ) ;
}
}
static int F_160 ( struct V_1 * V_2 )
{
F_126 ( & V_2 -> V_166 ) ;
#ifdef F_101
if ( V_2 -> V_174 )
F_161 ( V_2 -> V_174 ) ;
#endif
if ( V_2 -> V_5 ) {
if ( V_2 -> V_178 >= 0 )
F_162 ( V_2 -> V_178 ) ;
F_2 ( 1 , V_2 -> V_5 + 0x04 ) ;
F_2 ( 0 , V_2 -> V_5 + V_72 ) ;
}
#ifdef F_163
F_164 ( & V_2 -> V_276 ) ;
F_165 ( & V_2 -> V_292 ) ;
#endif
if ( V_2 -> V_178 >= 0 )
F_166 ( V_2 -> V_178 , V_2 ) ;
F_149 ( V_2 ) ;
F_167 ( V_2 -> V_111 ) ;
F_130 ( V_2 -> V_111 ) ;
F_63 ( V_2 ) ;
return 0 ;
}
static int F_168 ( struct V_293 * V_149 )
{
struct V_1 * V_2 = V_149 -> V_294 ;
return F_160 ( V_2 ) ;
}
static int T_5 F_169 ( struct V_249 * V_150 ,
struct V_211 * V_111 ,
int V_115 ,
int V_295 ,
int V_296 ,
int V_297 ,
int V_250 ,
int V_298 ,
struct V_1 * * V_299 )
{
static struct V_300 V_195 = {
. V_301 = F_168 ,
} ;
struct V_1 * V_2 ;
int V_21 , V_112 ;
* V_299 = NULL ;
if ( ( V_112 = F_135 ( V_111 ) ) < 0 )
return V_112 ;
if ( F_170 ( V_111 , F_171 ( 28 ) ) < 0 ||
F_172 ( V_111 , F_171 ( 28 ) ) < 0 ) {
F_71 ( V_116 L_20 ) ;
F_130 ( V_111 ) ;
return - V_302 ;
}
V_2 = F_81 ( sizeof( * V_2 ) , V_103 ) ;
if ( ! V_2 ) {
F_130 ( V_111 ) ;
return - V_117 ;
}
V_2 -> type = V_297 ;
F_173 ( & V_2 -> V_10 ) ;
F_173 ( & V_2 -> V_86 ) ;
F_73 ( & V_2 -> V_107 ) ;
F_73 ( & V_2 -> V_130 ) ;
F_174 ( & V_2 -> V_97 ) ;
F_175 ( & V_2 -> V_166 , F_99 ) ;
V_2 -> V_150 = V_150 ;
V_2 -> V_111 = V_111 ;
V_2 -> V_178 = - 1 ;
V_2 -> V_115 = V_115 ;
V_2 -> V_151 = V_295 ;
V_2 -> V_152 = V_296 ;
if ( ( V_112 = F_176 ( V_111 , L_10 ) ) < 0 ) {
F_63 ( V_2 ) ;
F_130 ( V_111 ) ;
return V_112 ;
}
V_2 -> V_5 = F_177 ( V_111 , 0 ) ;
if ( F_178 ( V_111 -> V_178 , F_107 , V_303 ,
V_304 , V_2 ) ) {
F_71 ( V_116 L_21 , V_111 -> V_178 ) ;
F_160 ( V_2 ) ;
return - V_123 ;
}
V_2 -> V_178 = V_111 -> V_178 ;
for ( V_21 = 0 ; V_21 < 32 ; V_21 ++ )
V_2 -> V_8 [ V_21 ] = 0 ;
for ( V_21 = 0 ; V_21 < V_25 ; V_21 ++ )
V_2 -> V_52 [ V_21 ] = V_122 ;
F_137 ( V_111 ) ;
if ( V_250 > 1 ) {
unsigned short V_205 ;
F_114 ( V_2 -> V_111 , V_206 , & V_205 ) ;
for ( V_21 = 0 ; V_21 < ( int ) F_179 ( V_305 ) ; V_21 ++ ) {
if ( V_2 -> type == V_305 [ V_21 ] . type &&
V_205 == V_305 [ V_21 ] . V_269 ) {
V_250 = 1 ;
break;
}
}
if ( V_250 > 1 ) {
F_91 ( V_146 L_22 ) ;
V_250 = 0 ;
}
}
V_2 -> V_250 = V_250 ;
F_118 ( V_2 ) ;
if ( ( V_112 = F_180 ( V_150 , V_306 , V_2 , & V_195 ) ) < 0 ) {
F_160 ( V_2 ) ;
return V_112 ;
}
F_181 ( V_150 , & V_111 -> V_113 ) ;
#ifdef F_163
V_112 = F_182 ( & V_111 -> V_113 , & V_2 -> V_292 ) ;
if ( V_112 < 0 ) {
F_160 ( V_2 ) ;
return V_112 ;
}
V_2 -> V_276 . V_292 = & V_2 -> V_292 ;
V_2 -> V_276 . V_18 = V_2 ;
V_2 -> V_276 . V_298 = V_298 ;
V_2 -> V_276 . V_195 = & V_307 ;
F_183 ( V_2 -> V_276 . V_150 , L_23 , sizeof( V_2 -> V_276 . V_150 ) ) ;
sprintf ( V_2 -> V_276 . V_308 , L_24 , F_145 ( V_111 ) ) ;
if ( ! F_184 ( & V_2 -> V_276 , V_309 ) )
F_91 ( V_146 L_25 ) ;
#endif
* V_299 = V_2 ;
return 0 ;
}
static int T_5 F_185 ( struct V_211 * V_111 ,
const struct V_310 * V_311 )
{
static int V_113 ;
struct V_249 * V_150 ;
struct V_1 * V_2 ;
unsigned int V_21 ;
int V_112 ;
if ( V_113 >= V_312 )
return - V_261 ;
if ( ! V_313 [ V_113 ] ) {
V_113 ++ ;
return - V_314 ;
}
V_112 = F_186 ( V_20 [ V_113 ] , V_173 [ V_113 ] , V_309 , 0 , & V_150 ) ;
if ( V_112 < 0 )
return V_112 ;
if ( V_115 [ V_113 ] < 128 )
V_115 [ V_113 ] = 128 ;
if ( V_115 [ V_113 ] > 4096 )
V_115 [ V_113 ] = 4096 ;
if ( ( V_112 = F_169 ( V_150 , V_111 ,
V_115 [ V_113 ] * 1024 ,
V_315 [ V_113 ] ,
V_316 [ V_113 ] ,
V_311 -> V_317 ,
V_318 [ V_113 ] ,
V_298 [ V_113 ] ,
& V_2 ) ) < 0 ) {
F_187 ( V_150 ) ;
return V_112 ;
}
V_150 -> V_18 = V_2 ;
switch ( V_2 -> type ) {
case V_319 :
strcpy ( V_150 -> V_266 , L_26 ) ;
strcpy ( V_150 -> V_320 , L_27 ) ;
break;
case V_321 :
strcpy ( V_150 -> V_266 , L_28 ) ;
strcpy ( V_150 -> V_320 , L_29 ) ;
break;
case V_322 :
strcpy ( V_150 -> V_266 , L_30 ) ;
strcpy ( V_150 -> V_320 , L_31 ) ;
break;
}
if ( ( V_112 = F_93 ( V_2 , 0 ) ) < 0 ) {
F_187 ( V_150 ) ;
return V_112 ;
}
if ( ( V_112 = F_110 ( V_2 ) ) < 0 ) {
F_187 ( V_150 ) ;
return V_112 ;
}
if ( V_323 [ V_113 ] == 2 ) {
unsigned short V_205 ;
F_114 ( V_2 -> V_111 , V_206 , & V_205 ) ;
for ( V_21 = 0 ; V_21 < F_179 ( V_324 ) ; V_21 ++ ) {
if ( V_2 -> type == V_324 [ V_21 ] . type &&
V_205 == V_324 [ V_21 ] . V_269 ) {
V_323 [ V_113 ] = 0 ;
break;
}
}
}
if ( V_323 [ V_113 ] ) {
if ( ( V_112 = F_188 ( V_150 , 0 , V_325 ,
V_2 -> V_5 + V_326 ,
V_327 |
V_328 ,
- 1 , & V_2 -> V_184 ) ) < 0 ) {
F_91 ( V_329 L_32 ) ;
}
}
F_139 ( V_2 , V_113 ) ;
#ifdef F_101
V_112 = F_152 ( V_2 ) ;
if ( V_112 )
F_71 ( V_329 L_33
L_34 , V_112 ) ;
#endif
F_122 ( V_2 ) ;
V_2 -> clock = clock [ V_113 ] ;
if ( ! V_2 -> clock )
F_88 ( V_2 ) ;
sprintf ( V_150 -> V_330 , L_35 ,
V_150 -> V_320 , V_2 -> V_5 , V_2 -> V_178 ) ;
if ( ( V_112 = F_189 ( V_150 ) ) < 0 ) {
F_187 ( V_150 ) ;
return V_112 ;
}
F_190 ( V_111 , V_150 ) ;
V_113 ++ ;
return 0 ;
}
static void T_7 F_191 ( struct V_211 * V_111 )
{
F_187 ( F_192 ( V_111 ) ) ;
F_190 ( V_111 , NULL ) ;
}
