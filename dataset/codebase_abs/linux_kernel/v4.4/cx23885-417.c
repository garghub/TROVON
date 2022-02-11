void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( 2 , L_1 , V_4 ) ;
V_3 = F_3 ( V_5 ) |
F_4 ( V_6 ) |
V_7 ;
F_5 ( V_8 , V_3 ) ;
V_3 = V_9 ;
F_5 ( V_10 , V_3 ) ;
V_3 = V_11 | V_12 | V_13 ;
F_5 ( V_14 , V_3 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
T_1 V_15 ;
unsigned long V_16 = V_17 + F_7 ( 1 ) ;
for (; ; ) {
V_15 = F_8 ( V_14 ) & V_9 ;
if ( V_15 != 0 )
return 0 ;
if ( F_9 ( V_17 , V_16 ) )
return - 1 ;
F_10 ( 1 ) ;
}
}
int F_11 ( struct V_1 * V_2 , T_2 V_18 , T_1 V_19 )
{
T_1 V_3 ;
F_5 ( V_10 , V_9 ) ;
V_3 = V_12 | V_9 | V_20 |
( V_19 & 0x000000FF ) ;
F_5 ( V_14 , V_3 ) ;
V_3 |= V_13 | V_11 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_12 | V_9 | V_21 |
( ( V_19 >> 8 ) & 0x000000FF ) ;
F_5 ( V_14 , V_3 ) ;
V_3 |= V_13 | V_11 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_12 | V_9 | V_22 |
( ( V_19 >> 16 ) & 0x000000FF ) ;
F_5 ( V_14 , V_3 ) ;
V_3 |= V_13 | V_11 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_12 | V_9 | V_23 |
( ( V_19 >> 24 ) & 0x000000FF ) ;
F_5 ( V_14 , V_3 ) ;
V_3 |= V_13 | V_11 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_12 | V_9 | V_24 |
( V_18 & 0xFF ) ;
F_5 ( V_14 , V_3 ) ;
V_3 |= V_13 | V_11 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_12 | V_9 | V_25 |
( ( V_18 >> 8 ) & 0xFF ) ;
F_5 ( V_14 , V_3 ) ;
V_3 |= V_13 | V_11 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_12 | V_9 | V_26 |
V_27 ;
F_5 ( V_14 , V_3 ) ;
V_3 |= V_13 | V_11 ;
F_5 ( V_14 , V_3 ) ;
return F_6 ( V_2 ) ;
}
int F_12 ( struct V_1 * V_2 , T_2 V_18 , T_1 * V_19 )
{
int V_28 ;
T_1 V_3 ;
T_1 V_29 ;
T_1 V_30 ;
F_5 ( V_10 , V_9 ) ;
V_3 = V_12 | V_9 | V_24 |
( ( V_18 & 0x00FF ) ) ;
F_5 ( V_14 , V_3 ) ;
V_3 |= V_13 | V_11 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_12 | V_9 | V_25 |
( ( V_18 >> 8 ) & 0xFF ) ;
F_5 ( V_14 , V_3 ) ;
V_3 |= V_13 | V_11 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_12 | V_9 | V_26 |
V_31 ;
F_5 ( V_14 , V_3 ) ;
V_3 |= V_13 | V_11 ;
F_5 ( V_14 , V_3 ) ;
V_28 = F_6 ( V_2 ) ;
F_5 ( V_10 , V_9 | V_32 ) ;
V_3 = V_12 | V_9 | V_20 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_11 | V_9 | V_20 ;
F_5 ( V_14 , V_3 ) ;
V_29 = F_8 ( V_14 ) ;
V_30 = V_29 & 0x000000FF ;
V_3 = V_11 | V_12 | V_13 | V_9 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_12 | V_9 | V_21 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_11 | V_9 | V_21 ;
F_5 ( V_14 , V_3 ) ;
V_29 = F_8 ( V_14 ) ;
V_30 |= ( ( V_29 & 0x000000FF ) << 8 ) ;
V_3 = V_11 | V_12 | V_13 | V_9 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_12 | V_9 | V_22 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_11 | V_9 | V_22 ;
F_5 ( V_14 , V_3 ) ;
V_29 = F_8 ( V_14 ) ;
V_30 |= ( ( V_29 & 0x000000FF ) << 16 ) ;
V_3 = V_11 | V_12 | V_13 | V_9 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_12 | V_9 | V_23 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_11 | V_9 | V_23 ;
F_5 ( V_14 , V_3 ) ;
V_29 = F_8 ( V_14 ) ;
V_30 |= ( ( V_29 & 0x000000FF ) << 24 ) ;
V_3 = V_11 | V_12 | V_13 | V_9 ;
F_5 ( V_14 , V_3 ) ;
* V_19 = V_30 ;
return V_28 ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_18 , T_1 V_19 )
{
T_1 V_3 ;
F_5 ( V_10 , V_9 ) ;
V_3 = V_12 | V_9 | V_33 |
( V_19 & 0x000000FF ) ;
F_5 ( V_14 , V_3 ) ;
V_3 |= V_13 | V_11 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_12 | V_9 | V_34 |
( ( V_19 >> 8 ) & 0x000000FF ) ;
F_5 ( V_14 , V_3 ) ;
V_3 |= V_13 | V_11 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_12 | V_9 | V_35 |
( ( V_19 >> 16 ) & 0x000000FF ) ;
F_5 ( V_14 , V_3 ) ;
V_3 |= V_13 | V_11 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_12 | V_9 | V_36 |
( ( V_19 >> 24 ) & 0x000000FF ) ;
F_5 ( V_14 , V_3 ) ;
V_3 |= V_13 | V_11 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_12 | V_9 | V_37 |
V_38 | ( ( V_18 >> 16 ) & 0x3F ) ;
F_5 ( V_14 , V_3 ) ;
V_3 |= V_13 | V_11 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_12 | V_9 | V_39 |
( ( V_18 >> 8 ) & 0xFF ) ;
F_5 ( V_14 , V_3 ) ;
V_3 |= V_13 | V_11 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_12 | V_9 | V_40 |
( V_18 & 0xFF ) ;
F_5 ( V_14 , V_3 ) ;
V_3 |= V_13 | V_11 ;
F_5 ( V_14 , V_3 ) ;
return F_6 ( V_2 ) ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_18 , T_1 * V_19 )
{
int V_28 ;
T_1 V_3 ;
T_1 V_29 ;
T_1 V_30 ;
F_5 ( V_10 , V_9 ) ;
V_3 = V_12 | V_9 | V_37 |
V_41 | ( ( V_18 >> 16 ) & 0x3F ) ;
F_5 ( V_14 , V_3 ) ;
V_3 |= V_13 | V_11 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_12 | V_9 | V_39 |
( ( V_18 >> 8 ) & 0xFF ) ;
F_5 ( V_14 , V_3 ) ;
V_3 |= V_13 | V_11 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_12 | V_9 | V_40 |
( V_18 & 0xFF ) ;
F_5 ( V_14 , V_3 ) ;
V_3 |= V_13 | V_11 ;
F_5 ( V_14 , V_3 ) ;
V_28 = F_6 ( V_2 ) ;
F_5 ( V_10 , V_9 | V_32 ) ;
V_3 = V_12 | V_9 | V_36 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_11 | V_9 | V_36 ;
F_5 ( V_14 , V_3 ) ;
V_29 = F_8 ( V_14 ) ;
V_30 = ( ( V_29 & 0x000000FF ) << 24 ) ;
V_3 = V_11 | V_12 | V_13 | V_9 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_12 | V_9 | V_35 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_11 | V_9 | V_35 ;
F_5 ( V_14 , V_3 ) ;
V_29 = F_8 ( V_14 ) ;
V_30 |= ( ( V_29 & 0x000000FF ) << 16 ) ;
V_3 = V_11 | V_12 | V_13 | V_9 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_12 | V_9 | V_34 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_11 | V_9 | V_34 ;
F_5 ( V_14 , V_3 ) ;
V_29 = F_8 ( V_14 ) ;
V_30 |= ( ( V_29 & 0x000000FF ) << 8 ) ;
V_3 = V_11 | V_12 | V_13 | V_9 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_12 | V_9 | V_33 ;
F_5 ( V_14 , V_3 ) ;
V_3 = V_11 | V_9 | V_33 ;
F_5 ( V_14 , V_3 ) ;
V_29 = F_8 ( V_14 ) ;
V_30 |= ( V_29 & 0x000000FF ) ;
V_3 = V_11 | V_12 | V_13 | V_9 ;
F_5 ( V_14 , V_3 ) ;
* V_19 = V_30 ;
return V_28 ;
}
void F_15 ( struct V_1 * V_2 , T_1 V_42 )
{
T_1 V_43 ;
F_12 ( V_2 , 0x900C , & V_43 ) ;
V_43 |= ( V_42 & 0x000ffff ) ;
F_11 ( V_2 , 0x900C , V_43 ) ;
}
void F_16 ( struct V_1 * V_2 , T_1 V_42 )
{
T_1 V_43 ;
F_12 ( V_2 , 0x900C , & V_43 ) ;
V_43 &= ~ ( V_42 & 0x0000ffff ) ;
F_11 ( V_2 , 0x900C , V_43 ) ;
}
void F_17 ( struct V_1 * V_2 , T_1 V_42 , int V_44 )
{
T_1 V_43 ;
F_12 ( V_2 , 0x9020 , & V_43 ) ;
if ( V_44 )
V_43 |= ( V_42 & 0x0000ffff ) ;
else
V_43 &= ~ ( V_42 & 0x0000ffff ) ;
F_11 ( V_2 , 0x9020 , V_43 ) ;
}
static char * F_18 ( int V_45 )
{
switch ( V_45 ) {
case V_46 :
return L_2 ;
case V_47 :
return L_3 ;
case V_48 :
return L_4 ;
case V_49 :
return L_5 ;
case V_50 :
return L_6 ;
case V_51 :
return L_7 ;
case V_52 :
return L_8 ;
case V_53 :
return L_9 ;
case V_54 :
return L_10 ;
case V_55 :
return L_11 ;
case V_56 :
return L_12 ;
case V_57 :
return L_13 ;
case V_58 :
return L_14 ;
case V_59 :
return L_15 ;
case V_60 :
return L_16 ;
case V_61 :
return L_17 ;
case V_62 :
return L_18 ;
case V_63 :
return L_19 ;
case V_64 :
return L_20 ;
case V_65 :
return L_21 ;
case V_66 :
return L_22 ;
case V_67 :
return L_23 ;
case V_68 :
return L_24 ;
case V_69 :
return L_25 ;
case V_70 :
return L_26 ;
case V_71 :
return L_27 ;
case V_72 :
return L_28 ;
case V_73 :
return L_29 ;
case V_74 :
return L_30 ;
case V_75 :
return L_31 ;
case V_76 :
return L_32 ;
case V_77 :
return L_33 ;
case V_78 :
return L_34 ;
case V_79 :
return L_35 ;
case V_80 :
return L_36 ;
case V_81 :
return L_37 ;
case V_82 :
return L_38 ;
case V_83 :
return L_39 ;
case V_84 :
return L_40 ;
case V_85 :
return L_41 ;
default:
return L_42 ;
}
}
static int F_19 ( void * V_86 ,
T_1 V_87 ,
int V_88 ,
int V_89 ,
T_1 V_90 [ V_91 ] )
{
struct V_1 * V_2 = V_86 ;
unsigned long V_16 ;
T_1 V_19 , V_92 , V_28 = 0 ;
int V_93 ;
F_2 ( 3 , L_43 , V_4 , V_87 ,
F_18 ( V_87 ) ) ;
F_14 ( V_2 , V_2 -> V_94 - 4 , & V_19 ) ;
if ( V_19 != 0x12345678 ) {
F_20 ( V_95
L_44
L_45 , V_19 ,
F_18 ( V_87 ) ) ;
return - 1 ;
}
F_14 ( V_2 , V_2 -> V_94 , & V_92 ) ;
if ( V_92 ) {
F_20 ( V_95 L_46
L_47 , V_92 , F_18 ( V_87 ) ) ;
return - 1 ;
}
V_92 |= 1 ;
F_13 ( V_2 , V_2 -> V_94 , V_92 ) ;
F_13 ( V_2 , V_2 -> V_94 + 1 , V_87 ) ;
F_13 ( V_2 , V_2 -> V_94 + 3 ,
V_96 ) ;
for ( V_93 = 0 ; V_93 < V_88 ; V_93 ++ ) {
F_13 ( V_2 , V_2 -> V_94 + 4 + V_93 , V_90 [ V_93 ] ) ;
F_2 ( 3 , L_48 , V_93 , V_90 [ V_93 ] ) ;
}
for (; V_93 < V_91 ; V_93 ++ )
F_13 ( V_2 , V_2 -> V_94 + 4 + V_93 , 0 ) ;
V_92 |= 3 ;
F_13 ( V_2 , V_2 -> V_94 , V_92 ) ;
V_16 = V_17 + F_7 ( 10 ) ;
for (; ; ) {
F_14 ( V_2 , V_2 -> V_94 , & V_92 ) ;
if ( 0 != ( V_92 & 4 ) )
break;
if ( F_9 ( V_17 , V_16 ) ) {
F_20 ( V_95 L_49 ) ;
return - 1 ;
}
F_10 ( 10 ) ;
}
for ( V_93 = 0 ; V_93 < V_89 ; V_93 ++ ) {
F_14 ( V_2 , V_2 -> V_94 + 4 + V_93 , V_90 + V_93 ) ;
F_2 ( 3 , L_50 , V_93 , V_90 [ V_93 ] ) ;
}
F_14 ( V_2 , V_2 -> V_94 + 2 , & V_28 ) ;
F_2 ( 3 , L_51 , V_28 ) ;
V_92 = 0 ;
F_13 ( V_2 , V_2 -> V_94 , V_92 ) ;
return V_28 ;
}
static int F_21 ( struct V_1 * V_2 ,
T_1 V_87 ,
T_1 V_97 ,
T_1 V_98 ,
... )
{
T_1 V_90 [ V_91 ] ;
T_3 V_99 ;
int V_93 , V_100 ;
F_2 ( 3 , L_52 , V_4 , V_87 ) ;
va_start ( V_99 , V_98 ) ;
for ( V_93 = 0 ; V_93 < V_97 ; V_93 ++ )
V_90 [ V_93 ] = va_arg ( V_99 , int ) ;
V_100 = F_19 ( V_2 , V_87 , V_97 , V_98 , V_90 ) ;
for ( V_93 = 0 ; V_93 < V_98 ; V_93 ++ ) {
int * V_101 = va_arg ( V_99 , int * ) ;
* V_101 = V_90 [ V_93 ] ;
}
va_end ( V_99 ) ;
return V_100 ;
}
static int F_22 ( void * V_86 , T_1 V_45 , int V_88 , int V_89 , T_1 V_90 [ V_91 ] )
{
return F_19 ( V_86 , V_45 , V_88 , V_89 , V_90 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
T_1 V_102 [ 4 ] = {
0x12345678 , 0x34567812 , 0x56781234 , 0x78123456
} ;
int V_103 = 0 ;
T_1 V_19 ;
int V_93 ;
F_2 ( 2 , L_1 , V_4 ) ;
for ( V_93 = 0 ; V_93 < V_104 ; V_93 ++ ) {
F_14 ( V_2 , V_93 , & V_19 ) ;
if ( V_19 == V_102 [ V_103 ] )
V_103 ++ ;
else
V_103 = 0 ;
if ( 4 == V_103 ) {
F_2 ( 1 , L_53 , V_93 + 1 ) ;
return V_93 + 1 ;
}
}
F_20 ( V_95 L_54 ) ;
return - 1 ;
}
static int F_24 ( struct V_1 * V_2 )
{
static const unsigned char V_105 [ 8 ] = {
0xa7 , 0x0d , 0x00 , 0x00 , 0x66 , 0xbb , 0x55 , 0xaa
} ;
const struct V_106 * V_106 ;
int V_93 , V_28 = 0 ;
T_1 V_19 = 0 ;
T_1 V_107 = 0 ;
T_1 V_108 ;
T_1 V_109 = 0 ;
T_1 * V_110 ;
F_2 ( 2 , L_1 , V_4 ) ;
V_28 |= F_14 ( V_2 , 0x9020 , & V_107 ) ;
V_28 |= F_14 ( V_2 , 0x900C , & V_108 ) ;
V_28 = F_11 ( V_2 ,
V_111 , 0xFFFFFFED ) ;
V_28 |= F_11 ( V_2 ,
V_112 , V_113 ) ;
V_28 |= F_11 ( V_2 ,
V_114 , 0x80000800 ) ;
V_28 |= F_11 ( V_2 ,
V_115 , 0x1A ) ;
V_28 |= F_11 ( V_2 ,
V_116 , 0 ) ;
if ( V_28 != 0 ) {
F_20 ( V_95 L_55 ,
V_4 ) ;
return - 1 ;
}
V_28 = F_25 ( & V_106 , V_117 ,
& V_2 -> V_118 -> V_2 ) ;
if ( V_28 != 0 ) {
F_20 ( V_95
L_56 ,
V_117 ) ;
F_20 ( V_95 L_57
L_58 ) ;
return - 1 ;
}
if ( V_106 -> V_119 != V_104 ) {
F_20 ( V_95 L_59
L_60 ,
V_106 -> V_119 , V_104 ) ;
F_26 ( V_106 ) ;
return - 1 ;
}
if ( 0 != memcmp ( V_106 -> V_90 , V_105 , 8 ) ) {
F_20 ( V_95
L_61 ) ;
F_26 ( V_106 ) ;
return - 1 ;
}
F_2 ( 2 , L_62 ) ;
V_110 = ( T_1 * ) V_106 -> V_90 ;
for ( V_93 = 0 ; V_93 < ( V_106 -> V_119 >> 2 ) ; V_93 ++ ) {
V_19 = * V_110 ;
V_109 += ~ V_19 ;
if ( F_13 ( V_2 , V_93 , V_19 ) != 0 ) {
F_20 ( V_95 L_63 ) ;
F_26 ( V_106 ) ;
return - 1 ;
}
V_110 ++ ;
}
F_2 ( 1 , L_64 ) ;
for ( V_93 -- ; V_93 >= 0 ; V_93 -- ) {
if ( F_14 ( V_2 , V_93 , & V_19 ) != 0 ) {
F_20 ( V_95 L_65 ) ;
F_26 ( V_106 ) ;
return - 1 ;
}
V_109 -= ~ V_19 ;
}
if ( V_109 ) {
F_20 ( V_95
L_66 ) ;
F_26 ( V_106 ) ;
return - 1 ;
}
F_26 ( V_106 ) ;
F_2 ( 1 , L_67 ) ;
V_28 |= F_11 ( V_2 , V_112 ,
V_113 ) ;
V_28 |= F_11 ( V_2 , 0x9020 , V_107 ) ;
V_28 |= F_11 ( V_2 , 0x900C , V_108 ) ;
V_28 |= F_12 ( V_2 , V_111 , & V_19 ) ;
V_28 |= F_11 ( V_2 , V_111 , V_19 & 0xFFFFFFE8 ) ;
V_28 |= F_11 ( V_2 , 0x9020 , 0x4000 ) ;
V_28 |= F_11 ( V_2 , 0x900C , 0x4000 ) ;
F_12 ( V_2 , 0x9020 , & V_107 ) ;
F_12 ( V_2 , 0x900C , & V_108 ) ;
if ( V_28 < 0 )
F_20 ( V_95 L_55 ,
V_4 ) ;
return 0 ;
}
void F_27 ( struct V_1 * V_2 )
{
T_1 V_120 , V_121 ;
V_120 = V_121 = 0 ;
F_21 ( V_2 , V_68 , 0 , 2 , & V_120 , & V_121 ) ;
F_2 ( 1 , L_68 , V_4 , V_120 , V_121 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_2 ( 1 , L_1 , V_4 ) ;
if ( V_2 -> V_122 . V_123 & V_124 )
V_2 -> V_125 . V_126 = 480 ;
else
V_2 -> V_125 . V_126 = 576 ;
F_21 ( V_2 , V_53 , 2 , 0 ,
V_2 -> V_125 . V_126 , V_2 -> V_125 . V_127 ) ;
V_2 -> V_128 . V_127 = V_2 -> V_125 . V_127 ;
V_2 -> V_128 . V_126 = V_2 -> V_125 . V_126 ;
V_2 -> V_128 . V_129 =
( V_2 -> V_122 . V_123 & V_130 ) != 0 ;
F_29 ( & V_2 -> V_128 ) ;
F_21 ( V_2 , V_85 , 2 , 0 , 3 , 1 ) ;
F_21 ( V_2 , V_85 , 2 , 0 , 4 , 1 ) ;
}
static int F_30 ( struct V_1 * V_2 , int V_131 )
{
int V_132 ;
int V_28 ;
T_1 V_93 , V_90 [ 7 ] ;
F_2 ( 1 , L_1 , V_4 ) ;
V_28 = F_21 ( V_2 , V_46 , 0 , 0 ) ;
if ( V_28 < 0 ) {
F_2 ( 2 , L_69 , V_4 ) ;
V_28 = F_24 ( V_2 ) ;
if ( V_28 < 0 ) {
F_20 ( V_95 L_70 , V_4 ) ;
return V_28 ;
}
V_28 = F_23 ( V_2 ) ;
if ( V_28 < 0 ) {
F_20 ( V_95 L_71 ,
V_4 ) ;
return - 1 ;
}
V_2 -> V_94 = V_28 ;
V_28 = F_21 ( V_2 , V_46 , 0 , 0 ) ;
if ( V_28 < 0 ) {
F_20 ( V_95
L_72 ) ;
return - 1 ;
}
V_28 = F_21 ( V_2 , V_66 , 0 , 1 ,
& V_132 ) ;
if ( V_28 < 0 ) {
F_20 ( V_95 L_73
L_74 ) ;
return - 1 ;
}
F_2 ( 1 , L_75 , V_132 ) ;
F_31 ( 200 ) ;
}
F_28 ( V_2 ) ;
F_31 ( 60 ) ;
F_21 ( V_2 , V_81 , 2 , 0 ,
V_133 , V_134 ) ;
F_21 ( V_2 , V_82 , 12 , 0 ,
V_135 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 ) ;
V_90 [ 0 ] = 0x0001BD00 ;
V_90 [ 1 ] = 1 ;
V_90 [ 2 ] = 4 ;
V_90 [ 3 ] = 0x91559155 ;
V_90 [ 4 ] = 0x206080C0 ;
V_90 [ 5 ] = 6 ;
V_90 [ 6 ] = 64 ;
F_21 ( V_2 , V_70 , 7 , 0 , V_90 [ 0 ] , V_90 [ 1 ] ,
V_90 [ 2 ] , V_90 [ 3 ] , V_90 [ 4 ] , V_90 [ 5 ] , V_90 [ 6 ] ) ;
for ( V_93 = 2 ; V_93 <= 24 ; V_93 ++ ) {
int V_136 ;
V_136 = ( ( V_93 >= 19 ) && ( V_93 <= 21 ) ) ;
F_21 ( V_2 , V_61 , 5 , 0 , V_93 ,
V_136 , 0 , 0 , 0 ) ;
F_21 ( V_2 , V_61 , 5 , 0 ,
V_93 | 0x80000000 , V_136 , 0 , 0 , 0 ) ;
}
F_21 ( V_2 , V_84 , 1 , 0 , V_137 ) ;
F_31 ( 60 ) ;
F_21 ( V_2 , V_75 , 0 , 0 ) ;
F_31 ( 60 ) ;
F_13 ( V_2 , 2120 , 0x00000080 ) ;
if ( V_131 ) {
F_21 ( V_2 , V_47 , 2 , 0 ,
V_138 , V_139 ) ;
F_31 ( 10 ) ;
}
return 0 ;
}
static int F_32 ( struct V_140 * V_141 , const void * V_142 ,
unsigned int * V_143 , unsigned int * V_144 ,
unsigned int V_145 [] , void * V_146 [] )
{
struct V_1 * V_2 = V_141 -> V_147 ;
V_2 -> V_125 . V_148 = V_149 ;
V_2 -> V_125 . V_150 = V_151 ;
* V_144 = 1 ;
V_145 [ 0 ] = V_149 * V_151 ;
V_146 [ 0 ] = V_2 -> V_152 ;
* V_143 = V_153 ;
return 0 ;
}
static int F_33 ( struct V_154 * V_155 )
{
struct V_156 * V_157 = F_34 ( V_155 ) ;
struct V_1 * V_2 = V_155 -> V_140 -> V_147 ;
struct V_158 * V_159 =
F_35 ( V_157 , struct V_158 , V_155 ) ;
return F_36 ( V_159 , & V_2 -> V_125 ) ;
}
static void F_37 ( struct V_154 * V_155 )
{
struct V_156 * V_157 = F_34 ( V_155 ) ;
struct V_1 * V_2 = V_155 -> V_140 -> V_147 ;
struct V_158 * V_159 = F_35 ( V_157 ,
struct V_158 , V_155 ) ;
F_38 ( V_2 , V_159 ) ;
}
static void F_39 ( struct V_154 * V_155 )
{
struct V_156 * V_157 = F_34 ( V_155 ) ;
struct V_1 * V_2 = V_155 -> V_140 -> V_147 ;
struct V_158 * V_159 = F_35 ( V_157 ,
struct V_158 , V_155 ) ;
F_40 ( & V_2 -> V_125 , V_159 ) ;
}
static int F_41 ( struct V_140 * V_141 , unsigned int V_160 )
{
struct V_1 * V_2 = V_141 -> V_147 ;
struct V_161 * V_162 = & V_2 -> V_125 . V_163 ;
unsigned long V_164 ;
int V_165 ;
V_165 = F_30 ( V_2 , 1 ) ;
if ( V_165 == 0 ) {
struct V_158 * V_159 = F_42 ( V_162 -> V_166 . V_167 ,
struct V_158 , V_168 ) ;
F_43 ( & V_2 -> V_125 , V_162 , V_159 ) ;
return 0 ;
}
F_44 ( & V_2 -> V_169 , V_164 ) ;
while ( ! F_45 ( & V_162 -> V_166 ) ) {
struct V_158 * V_159 = F_42 ( V_162 -> V_166 . V_167 ,
struct V_158 , V_168 ) ;
F_46 ( & V_159 -> V_168 ) ;
F_47 ( & V_159 -> V_155 . V_170 , V_171 ) ;
}
F_48 ( & V_2 -> V_169 , V_164 ) ;
return V_165 ;
}
static void F_49 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = V_141 -> V_147 ;
F_21 ( V_2 , V_48 , 3 , 0 ,
V_172 , V_138 ,
V_139 ) ;
F_31 ( 500 ) ;
F_27 ( V_2 ) ;
F_50 ( & V_2 -> V_125 ) ;
}
static int F_51 ( struct V_173 * V_173 , void * V_86 , T_4 * V_123 )
{
struct V_1 * V_2 = F_52 ( V_173 ) ;
* V_123 = V_2 -> V_174 ;
return 0 ;
}
static int F_53 ( struct V_173 * V_173 , void * V_86 , T_4 V_123 )
{
struct V_1 * V_2 = F_52 ( V_173 ) ;
unsigned int V_93 ;
int V_165 ;
for ( V_93 = 0 ; V_93 < F_54 ( V_175 ) ; V_93 ++ )
if ( V_123 & V_175 [ V_93 ] . V_123 )
break;
if ( V_93 == F_54 ( V_175 ) )
return - V_176 ;
V_165 = F_55 ( V_2 , V_123 ) ;
if ( ! V_165 )
V_2 -> V_122 = V_175 [ V_93 ] ;
return V_165 ;
}
static int F_56 ( struct V_173 * V_173 , void * V_86 ,
struct V_177 * V_93 )
{
struct V_1 * V_2 = F_52 ( V_173 ) ;
F_2 ( 1 , L_1 , V_4 ) ;
return F_57 ( V_2 , V_93 ) ;
}
static int F_58 ( struct V_173 * V_173 , void * V_86 , unsigned int * V_93 )
{
return F_59 ( V_173 , V_86 , V_93 ) ;
}
static int F_60 ( struct V_173 * V_173 , void * V_86 , unsigned int V_93 )
{
return F_61 ( V_173 , V_86 , V_93 ) ;
}
static int F_62 ( struct V_173 * V_173 , void * V_86 ,
struct V_178 * V_179 )
{
struct V_1 * V_2 = F_52 ( V_173 ) ;
if ( V_2 -> V_180 == V_181 )
return - V_176 ;
if ( 0 != V_179 -> V_182 )
return - V_176 ;
strcpy ( V_179 -> V_183 , L_76 ) ;
F_63 ( V_2 , V_184 , V_185 , V_179 ) ;
F_2 ( 1 , L_77 , V_179 -> type ) ;
return 0 ;
}
static int F_64 ( struct V_173 * V_173 , void * V_86 ,
const struct V_178 * V_179 )
{
struct V_1 * V_2 = F_52 ( V_173 ) ;
if ( V_2 -> V_180 == V_181 )
return - V_176 ;
F_63 ( V_2 , V_184 , V_186 , V_179 ) ;
return 0 ;
}
static int F_65 ( struct V_173 * V_173 , void * V_86 ,
struct V_187 * V_188 )
{
struct V_1 * V_2 = F_52 ( V_173 ) ;
if ( V_2 -> V_180 == V_181 )
return - V_176 ;
V_188 -> type = V_189 ;
V_188 -> V_190 = V_2 -> V_191 ;
F_63 ( V_2 , V_184 , V_192 , V_188 ) ;
return 0 ;
}
static int F_66 ( struct V_173 * V_173 , void * V_86 ,
const struct V_187 * V_188 )
{
return F_67 ( V_173 , V_86 , V_188 ) ;
}
static int F_68 ( struct V_173 * V_173 , void * V_86 ,
struct V_193 * V_194 )
{
struct V_1 * V_2 = F_52 ( V_173 ) ;
struct V_195 * V_196 = & V_2 -> V_125 ;
F_69 ( V_194 -> V_197 , V_2 -> V_183 , sizeof( V_194 -> V_197 ) ) ;
F_69 ( V_194 -> V_198 , V_199 [ V_196 -> V_2 -> V_200 ] . V_183 ,
sizeof( V_194 -> V_198 ) ) ;
sprintf ( V_194 -> V_201 , L_78 , F_70 ( V_2 -> V_118 ) ) ;
V_194 -> V_202 = V_203 | V_204 |
V_205 ;
if ( V_2 -> V_180 != V_181 )
V_194 -> V_202 |= V_206 ;
V_194 -> V_207 = V_194 -> V_202 | V_208 |
V_209 | V_210 ;
return 0 ;
}
static int F_71 ( struct V_173 * V_173 , void * V_86 ,
struct V_211 * V_188 )
{
if ( V_188 -> V_182 != 0 )
return - V_176 ;
F_69 ( V_188 -> V_212 , L_79 , sizeof( V_188 -> V_212 ) ) ;
V_188 -> V_213 = V_214 ;
return 0 ;
}
static int F_72 ( struct V_173 * V_173 , void * V_86 ,
struct V_215 * V_188 )
{
struct V_1 * V_2 = F_52 ( V_173 ) ;
V_188 -> V_216 . V_217 . V_213 = V_214 ;
V_188 -> V_216 . V_217 . V_218 = 0 ;
V_188 -> V_216 . V_217 . V_219 =
V_2 -> V_125 . V_148 * V_2 -> V_125 . V_150 ;
V_188 -> V_216 . V_217 . V_220 = 0 ;
V_188 -> V_216 . V_217 . V_127 = V_2 -> V_125 . V_127 ;
V_188 -> V_216 . V_217 . V_126 = V_2 -> V_125 . V_126 ;
V_188 -> V_216 . V_217 . V_221 = V_222 ;
F_2 ( 1 , L_80 ,
V_2 -> V_125 . V_127 , V_2 -> V_125 . V_126 ) ;
return 0 ;
}
static int F_73 ( struct V_173 * V_173 , void * V_86 ,
struct V_215 * V_188 )
{
struct V_1 * V_2 = F_52 ( V_173 ) ;
V_188 -> V_216 . V_217 . V_213 = V_214 ;
V_188 -> V_216 . V_217 . V_218 = 0 ;
V_188 -> V_216 . V_217 . V_219 =
V_2 -> V_125 . V_148 * V_2 -> V_125 . V_150 ;
V_188 -> V_216 . V_217 . V_220 = 0 ;
V_188 -> V_216 . V_217 . V_221 = V_222 ;
F_2 ( 1 , L_81 ,
V_2 -> V_125 . V_127 , V_2 -> V_125 . V_126 ) ;
return 0 ;
}
static int F_74 ( struct V_173 * V_173 , void * V_86 ,
struct V_215 * V_188 )
{
struct V_1 * V_2 = F_52 ( V_173 ) ;
V_188 -> V_216 . V_217 . V_213 = V_214 ;
V_188 -> V_216 . V_217 . V_218 = 0 ;
V_188 -> V_216 . V_217 . V_219 =
V_2 -> V_125 . V_148 * V_2 -> V_125 . V_150 ;
V_188 -> V_216 . V_217 . V_220 = 0 ;
V_188 -> V_216 . V_217 . V_221 = V_222 ;
F_2 ( 1 , L_82 ,
V_188 -> V_216 . V_217 . V_127 , V_188 -> V_216 . V_217 . V_126 , V_188 -> V_216 . V_217 . V_221 ) ;
return 0 ;
}
static int F_75 ( struct V_173 * V_173 , void * V_86 )
{
struct V_1 * V_2 = F_52 ( V_173 ) ;
char V_183 [ 32 + 2 ] ;
snprintf ( V_183 , sizeof( V_183 ) , L_83 , V_2 -> V_183 ) ;
F_63 ( V_2 , V_223 , V_224 ) ;
F_76 ( & V_2 -> V_128 . V_225 , V_183 ) ;
return 0 ;
}
void F_77 ( struct V_1 * V_2 )
{
F_2 ( 1 , L_1 , V_4 ) ;
if ( V_2 -> V_226 ) {
if ( F_78 ( V_2 -> V_226 ) )
F_79 ( V_2 -> V_226 ) ;
else
F_80 ( V_2 -> V_226 ) ;
F_81 ( & V_2 -> V_128 . V_225 ) ;
V_2 -> V_226 = NULL ;
}
}
static struct V_227 * F_82 (
struct V_195 * V_196 ,
struct V_228 * V_118 ,
struct V_227 * V_229 ,
char * type )
{
struct V_227 * V_230 ;
struct V_1 * V_2 = V_196 -> V_2 ;
F_2 ( 1 , L_1 , V_4 ) ;
V_230 = F_83 () ;
if ( NULL == V_230 )
return NULL ;
* V_230 = * V_229 ;
snprintf ( V_230 -> V_183 , sizeof( V_230 -> V_183 ) , L_84 ,
V_199 [ V_196 -> V_2 -> V_200 ] . V_183 , type ) ;
V_230 -> V_231 = & V_2 -> V_231 ;
V_230 -> V_232 = F_80 ;
return V_230 ;
}
int F_84 ( struct V_1 * V_2 )
{
int V_100 = - V_233 ;
struct V_195 * V_196 = & V_2 -> V_125 ;
struct V_140 * V_141 ;
F_2 ( 1 , L_1 , V_4 ) ;
if ( V_199 [ V_2 -> V_200 ] . V_234 != V_235 )
return V_100 ;
V_2 -> V_122 = V_175 [ 0 ] ;
if ( V_2 -> V_122 . V_123 & V_124 )
V_196 -> V_126 = 480 ;
else
V_196 -> V_126 = 576 ;
V_196 -> V_127 = 720 ;
V_2 -> V_128 . V_236 = V_237 ;
V_100 = F_85 ( & V_2 -> V_128 , 50 ) ;
if ( V_100 )
return V_100 ;
V_2 -> V_128 . V_86 = V_2 ;
V_2 -> V_128 . V_238 = F_22 ;
F_86 ( & V_2 -> V_128 , V_196 -> V_126 == 576 ) ;
F_87 ( & V_2 -> V_239 , & V_2 -> V_128 . V_225 , NULL ) ;
V_2 -> V_226 = F_82 ( V_196 ,
V_2 -> V_118 , & V_240 , L_85 ) ;
V_141 = & V_2 -> V_241 ;
V_141 -> type = V_242 ;
V_141 -> V_243 = V_244 | V_245 | V_246 | V_247 ;
V_141 -> V_248 = V_249 ;
V_141 -> V_250 = 2 ;
V_141 -> V_147 = V_2 ;
V_141 -> V_251 = sizeof( struct V_158 ) ;
V_141 -> V_252 = & V_253 ;
V_141 -> V_254 = & V_255 ;
V_141 -> V_256 = V_257 ;
V_141 -> V_258 = & V_2 -> V_258 ;
V_100 = F_88 ( V_141 ) ;
if ( V_100 < 0 )
return V_100 ;
F_89 ( V_2 -> V_226 , V_2 ) ;
V_2 -> V_226 -> V_258 = & V_2 -> V_258 ;
V_2 -> V_226 -> V_168 = V_141 ;
V_100 = F_90 ( V_2 -> V_226 ,
V_259 , - 1 ) ;
if ( V_100 < 0 ) {
F_20 ( V_260 L_86 , V_2 -> V_183 ) ;
return V_100 ;
}
F_20 ( V_260 L_87 ,
V_2 -> V_183 , F_91 ( V_2 -> V_226 ) ) ;
F_30 ( V_2 , 0 ) ;
return 0 ;
}
