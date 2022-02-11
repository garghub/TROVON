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
F_20 ( L_44 ,
V_19 , F_18 ( V_87 ) ) ;
return - 1 ;
}
F_14 ( V_2 , V_2 -> V_94 , & V_92 ) ;
if ( V_92 ) {
F_20 ( L_45 ,
V_92 , F_18 ( V_87 ) ) ;
return - 1 ;
}
V_92 |= 1 ;
F_13 ( V_2 , V_2 -> V_94 , V_92 ) ;
F_13 ( V_2 , V_2 -> V_94 + 1 , V_87 ) ;
F_13 ( V_2 , V_2 -> V_94 + 3 ,
V_95 ) ;
for ( V_93 = 0 ; V_93 < V_88 ; V_93 ++ ) {
F_13 ( V_2 , V_2 -> V_94 + 4 + V_93 , V_90 [ V_93 ] ) ;
F_2 ( 3 , L_46 , V_93 , V_90 [ V_93 ] ) ;
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
F_20 ( L_47 ) ;
return - 1 ;
}
F_10 ( 10 ) ;
}
for ( V_93 = 0 ; V_93 < V_89 ; V_93 ++ ) {
F_14 ( V_2 , V_2 -> V_94 + 4 + V_93 , V_90 + V_93 ) ;
F_2 ( 3 , L_48 , V_93 , V_90 [ V_93 ] ) ;
}
F_14 ( V_2 , V_2 -> V_94 + 2 , & V_28 ) ;
F_2 ( 3 , L_49 , V_28 ) ;
V_92 = 0 ;
F_13 ( V_2 , V_2 -> V_94 , V_92 ) ;
return V_28 ;
}
static int F_21 ( struct V_1 * V_2 ,
T_1 V_87 ,
T_1 V_96 ,
T_1 V_97 ,
... )
{
T_1 V_90 [ V_91 ] ;
T_3 V_98 ;
int V_93 , V_99 ;
F_2 ( 3 , L_50 , V_4 , V_87 ) ;
va_start ( V_98 , V_97 ) ;
for ( V_93 = 0 ; V_93 < V_96 ; V_93 ++ )
V_90 [ V_93 ] = va_arg ( V_98 , int ) ;
V_99 = F_19 ( V_2 , V_87 , V_96 , V_97 , V_90 ) ;
for ( V_93 = 0 ; V_93 < V_97 ; V_93 ++ ) {
int * V_100 = va_arg ( V_98 , int * ) ;
* V_100 = V_90 [ V_93 ] ;
}
va_end ( V_98 ) ;
return V_99 ;
}
static int F_22 ( void * V_86 , T_1 V_45 , int V_88 , int V_89 , T_1 V_90 [ V_91 ] )
{
return F_19 ( V_86 , V_45 , V_88 , V_89 , V_90 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
T_1 V_101 [ 4 ] = {
0x12345678 , 0x34567812 , 0x56781234 , 0x78123456
} ;
int V_102 = 0 ;
T_1 V_19 ;
int V_93 ;
F_2 ( 2 , L_1 , V_4 ) ;
for ( V_93 = 0 ; V_93 < V_103 ; V_93 ++ ) {
F_14 ( V_2 , V_93 , & V_19 ) ;
if ( V_19 == V_101 [ V_102 ] )
V_102 ++ ;
else
V_102 = 0 ;
if ( 4 == V_102 ) {
F_2 ( 1 , L_51 , V_93 + 1 ) ;
return V_93 + 1 ;
}
}
F_20 ( L_52 ) ;
return - 1 ;
}
static int F_24 ( struct V_1 * V_2 )
{
static const unsigned char V_104 [ 8 ] = {
0xa7 , 0x0d , 0x00 , 0x00 , 0x66 , 0xbb , 0x55 , 0xaa
} ;
const struct V_105 * V_105 ;
int V_93 , V_28 = 0 ;
T_1 V_19 = 0 ;
T_1 V_106 = 0 ;
T_1 V_107 ;
T_1 V_108 = 0 ;
T_1 * V_109 ;
F_2 ( 2 , L_1 , V_4 ) ;
V_28 |= F_14 ( V_2 , 0x9020 , & V_106 ) ;
V_28 |= F_14 ( V_2 , 0x900C , & V_107 ) ;
V_28 = F_11 ( V_2 ,
V_110 , 0xFFFFFFED ) ;
V_28 |= F_11 ( V_2 ,
V_111 , V_112 ) ;
V_28 |= F_11 ( V_2 ,
V_113 , 0x80000800 ) ;
V_28 |= F_11 ( V_2 ,
V_114 , 0x1A ) ;
V_28 |= F_11 ( V_2 ,
V_115 , 0 ) ;
if ( V_28 != 0 ) {
F_20 ( L_53 ,
V_4 ) ;
return - 1 ;
}
V_28 = F_25 ( & V_105 , V_116 ,
& V_2 -> V_117 -> V_2 ) ;
if ( V_28 != 0 ) {
F_20 ( L_54 ,
V_116 ) ;
F_20 ( L_55 ) ;
return - 1 ;
}
if ( V_105 -> V_118 != V_103 ) {
F_20 ( L_56 ,
V_105 -> V_118 , V_103 ) ;
F_26 ( V_105 ) ;
return - 1 ;
}
if ( 0 != memcmp ( V_105 -> V_90 , V_104 , 8 ) ) {
F_20 ( L_57 ) ;
F_26 ( V_105 ) ;
return - 1 ;
}
F_2 ( 2 , L_58 ) ;
V_109 = ( T_1 * ) V_105 -> V_90 ;
for ( V_93 = 0 ; V_93 < ( V_105 -> V_118 >> 2 ) ; V_93 ++ ) {
V_19 = * V_109 ;
V_108 += ~ V_19 ;
if ( F_13 ( V_2 , V_93 , V_19 ) != 0 ) {
F_20 ( L_59 ) ;
F_26 ( V_105 ) ;
return - 1 ;
}
V_109 ++ ;
}
F_2 ( 1 , L_60 ) ;
for ( V_93 -- ; V_93 >= 0 ; V_93 -- ) {
if ( F_14 ( V_2 , V_93 , & V_19 ) != 0 ) {
F_20 ( L_61 ) ;
F_26 ( V_105 ) ;
return - 1 ;
}
V_108 -= ~ V_19 ;
}
if ( V_108 ) {
F_20 ( L_62 ) ;
F_26 ( V_105 ) ;
return - 1 ;
}
F_26 ( V_105 ) ;
F_2 ( 1 , L_63 ) ;
V_28 |= F_11 ( V_2 , V_111 ,
V_112 ) ;
V_28 |= F_11 ( V_2 , 0x9020 , V_106 ) ;
V_28 |= F_11 ( V_2 , 0x900C , V_107 ) ;
V_28 |= F_12 ( V_2 , V_110 , & V_19 ) ;
V_28 |= F_11 ( V_2 , V_110 , V_19 & 0xFFFFFFE8 ) ;
V_28 |= F_11 ( V_2 , 0x9020 , 0x4000 ) ;
V_28 |= F_11 ( V_2 , 0x900C , 0x4000 ) ;
F_12 ( V_2 , 0x9020 , & V_106 ) ;
F_12 ( V_2 , 0x900C , & V_107 ) ;
if ( V_28 < 0 )
F_20 ( L_53 ,
V_4 ) ;
return 0 ;
}
void F_27 ( struct V_1 * V_2 )
{
T_1 V_119 , V_120 ;
V_119 = V_120 = 0 ;
F_21 ( V_2 , V_68 , 0 , 2 , & V_119 , & V_120 ) ;
F_2 ( 1 , L_64 , V_4 , V_119 , V_120 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_2 ( 1 , L_1 , V_4 ) ;
if ( V_2 -> V_121 . V_122 & V_123 )
V_2 -> V_124 . V_125 = 480 ;
else
V_2 -> V_124 . V_125 = 576 ;
F_21 ( V_2 , V_53 , 2 , 0 ,
V_2 -> V_124 . V_125 , V_2 -> V_124 . V_126 ) ;
V_2 -> V_127 . V_126 = V_2 -> V_124 . V_126 ;
V_2 -> V_127 . V_125 = V_2 -> V_124 . V_125 ;
V_2 -> V_127 . V_128 =
( V_2 -> V_121 . V_122 & V_129 ) != 0 ;
F_29 ( & V_2 -> V_127 ) ;
F_21 ( V_2 , V_85 , 2 , 0 , 3 , 1 ) ;
F_21 ( V_2 , V_85 , 2 , 0 , 4 , 1 ) ;
}
static int F_30 ( struct V_1 * V_2 , int V_130 )
{
int V_131 ;
int V_28 ;
T_1 V_93 , V_90 [ 7 ] ;
F_2 ( 1 , L_1 , V_4 ) ;
V_28 = F_21 ( V_2 , V_46 , 0 , 0 ) ;
if ( V_28 < 0 ) {
F_2 ( 2 , L_65 , V_4 ) ;
V_28 = F_24 ( V_2 ) ;
if ( V_28 < 0 ) {
F_20 ( L_66 , V_4 ) ;
return V_28 ;
}
V_28 = F_23 ( V_2 ) ;
if ( V_28 < 0 ) {
F_20 ( L_67 ,
V_4 ) ;
return - 1 ;
}
V_2 -> V_94 = V_28 ;
V_28 = F_21 ( V_2 , V_46 , 0 , 0 ) ;
if ( V_28 < 0 ) {
F_20 ( L_68 ) ;
return - 1 ;
}
V_28 = F_21 ( V_2 , V_66 , 0 , 1 ,
& V_131 ) ;
if ( V_28 < 0 ) {
F_20 ( L_69 ) ;
return - 1 ;
}
F_2 ( 1 , L_70 , V_131 ) ;
F_31 ( 200 ) ;
}
F_28 ( V_2 ) ;
F_31 ( 60 ) ;
F_21 ( V_2 , V_81 , 2 , 0 ,
V_132 , V_133 ) ;
F_21 ( V_2 , V_82 , 12 , 0 ,
V_134 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
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
int V_135 ;
V_135 = ( ( V_93 >= 19 ) && ( V_93 <= 21 ) ) ;
F_21 ( V_2 , V_61 , 5 , 0 , V_93 ,
V_135 , 0 , 0 , 0 ) ;
F_21 ( V_2 , V_61 , 5 , 0 ,
V_93 | 0x80000000 , V_135 , 0 , 0 , 0 ) ;
}
F_21 ( V_2 , V_84 , 1 , 0 , V_136 ) ;
F_31 ( 60 ) ;
F_21 ( V_2 , V_75 , 0 , 0 ) ;
F_31 ( 60 ) ;
F_13 ( V_2 , 2120 , 0x00000080 ) ;
if ( V_130 ) {
F_21 ( V_2 , V_47 , 2 , 0 ,
V_137 , V_138 ) ;
F_31 ( 10 ) ;
}
return 0 ;
}
static int F_32 ( struct V_139 * V_140 ,
unsigned int * V_141 , unsigned int * V_142 ,
unsigned int V_143 [] , struct V_144 * V_145 [] )
{
struct V_1 * V_2 = V_140 -> V_146 ;
V_2 -> V_124 . V_147 = V_148 ;
V_2 -> V_124 . V_149 = V_150 ;
* V_142 = 1 ;
V_143 [ 0 ] = V_148 * V_150 ;
* V_141 = V_151 ;
return 0 ;
}
static int F_33 ( struct V_152 * V_153 )
{
struct V_154 * V_155 = F_34 ( V_153 ) ;
struct V_1 * V_2 = V_153 -> V_139 -> V_146 ;
struct V_156 * V_157 =
F_35 ( V_155 , struct V_156 , V_153 ) ;
return F_36 ( V_157 , & V_2 -> V_124 ) ;
}
static void F_37 ( struct V_152 * V_153 )
{
struct V_154 * V_155 = F_34 ( V_153 ) ;
struct V_1 * V_2 = V_153 -> V_139 -> V_146 ;
struct V_156 * V_157 = F_35 ( V_155 ,
struct V_156 , V_153 ) ;
F_38 ( V_2 , V_157 ) ;
}
static void F_39 ( struct V_152 * V_153 )
{
struct V_154 * V_155 = F_34 ( V_153 ) ;
struct V_1 * V_2 = V_153 -> V_139 -> V_146 ;
struct V_156 * V_157 = F_35 ( V_155 ,
struct V_156 , V_153 ) ;
F_40 ( & V_2 -> V_124 , V_157 ) ;
}
static int F_41 ( struct V_139 * V_140 , unsigned int V_158 )
{
struct V_1 * V_2 = V_140 -> V_146 ;
struct V_159 * V_160 = & V_2 -> V_124 . V_161 ;
unsigned long V_162 ;
int V_163 ;
V_163 = F_30 ( V_2 , 1 ) ;
if ( V_163 == 0 ) {
struct V_156 * V_157 = F_42 ( V_160 -> V_164 . V_165 ,
struct V_156 , V_166 ) ;
F_43 ( & V_2 -> V_124 , V_160 , V_157 ) ;
return 0 ;
}
F_44 ( & V_2 -> V_167 , V_162 ) ;
while ( ! F_45 ( & V_160 -> V_164 ) ) {
struct V_156 * V_157 = F_42 ( V_160 -> V_164 . V_165 ,
struct V_156 , V_166 ) ;
F_46 ( & V_157 -> V_166 ) ;
F_47 ( & V_157 -> V_153 . V_168 , V_169 ) ;
}
F_48 ( & V_2 -> V_167 , V_162 ) ;
return V_163 ;
}
static void F_49 ( struct V_139 * V_140 )
{
struct V_1 * V_2 = V_140 -> V_146 ;
F_21 ( V_2 , V_48 , 3 , 0 ,
V_170 , V_137 ,
V_138 ) ;
F_31 ( 500 ) ;
F_27 ( V_2 ) ;
F_50 ( & V_2 -> V_124 ) ;
}
static int F_51 ( struct V_171 * V_171 , void * V_86 , T_4 * V_122 )
{
struct V_1 * V_2 = F_52 ( V_171 ) ;
* V_122 = V_2 -> V_172 ;
return 0 ;
}
static int F_53 ( struct V_171 * V_171 , void * V_86 , T_4 V_122 )
{
struct V_1 * V_2 = F_52 ( V_171 ) ;
unsigned int V_93 ;
int V_163 ;
for ( V_93 = 0 ; V_93 < F_54 ( V_173 ) ; V_93 ++ )
if ( V_122 & V_173 [ V_93 ] . V_122 )
break;
if ( V_93 == F_54 ( V_173 ) )
return - V_174 ;
V_163 = F_55 ( V_2 , V_122 ) ;
if ( ! V_163 )
V_2 -> V_121 = V_173 [ V_93 ] ;
return V_163 ;
}
static int F_56 ( struct V_171 * V_171 , void * V_86 ,
struct V_175 * V_93 )
{
struct V_1 * V_2 = F_52 ( V_171 ) ;
F_2 ( 1 , L_1 , V_4 ) ;
return F_57 ( V_2 , V_93 ) ;
}
static int F_58 ( struct V_171 * V_171 , void * V_86 , unsigned int * V_93 )
{
return F_59 ( V_171 , V_86 , V_93 ) ;
}
static int F_60 ( struct V_171 * V_171 , void * V_86 , unsigned int V_93 )
{
return F_61 ( V_171 , V_86 , V_93 ) ;
}
static int F_62 ( struct V_171 * V_171 , void * V_86 ,
struct V_176 * V_177 )
{
struct V_1 * V_2 = F_52 ( V_171 ) ;
if ( V_2 -> V_178 == V_179 )
return - V_174 ;
if ( 0 != V_177 -> V_180 )
return - V_174 ;
strcpy ( V_177 -> V_181 , L_71 ) ;
F_63 ( V_2 , V_182 , V_183 , V_177 ) ;
F_2 ( 1 , L_72 , V_177 -> type ) ;
return 0 ;
}
static int F_64 ( struct V_171 * V_171 , void * V_86 ,
const struct V_176 * V_177 )
{
struct V_1 * V_2 = F_52 ( V_171 ) ;
if ( V_2 -> V_178 == V_179 )
return - V_174 ;
F_63 ( V_2 , V_182 , V_184 , V_177 ) ;
return 0 ;
}
static int F_65 ( struct V_171 * V_171 , void * V_86 ,
struct V_185 * V_186 )
{
struct V_1 * V_2 = F_52 ( V_171 ) ;
if ( V_2 -> V_178 == V_179 )
return - V_174 ;
V_186 -> type = V_187 ;
V_186 -> V_188 = V_2 -> V_189 ;
F_63 ( V_2 , V_182 , V_190 , V_186 ) ;
return 0 ;
}
static int F_66 ( struct V_171 * V_171 , void * V_86 ,
const struct V_185 * V_186 )
{
return F_67 ( V_171 , V_86 , V_186 ) ;
}
static int F_68 ( struct V_171 * V_171 , void * V_86 ,
struct V_191 * V_192 )
{
struct V_1 * V_2 = F_52 ( V_171 ) ;
struct V_193 * V_194 = & V_2 -> V_124 ;
F_69 ( V_192 -> V_195 , V_2 -> V_181 , sizeof( V_192 -> V_195 ) ) ;
F_69 ( V_192 -> V_196 , V_197 [ V_194 -> V_2 -> V_198 ] . V_181 ,
sizeof( V_192 -> V_196 ) ) ;
sprintf ( V_192 -> V_199 , L_73 , F_70 ( V_2 -> V_117 ) ) ;
V_192 -> V_200 = V_201 | V_202 |
V_203 ;
if ( V_2 -> V_178 != V_179 )
V_192 -> V_200 |= V_204 ;
V_192 -> V_205 = V_192 -> V_200 | V_206 |
V_207 | V_208 ;
return 0 ;
}
static int F_71 ( struct V_171 * V_171 , void * V_86 ,
struct V_209 * V_186 )
{
if ( V_186 -> V_180 != 0 )
return - V_174 ;
F_69 ( V_186 -> V_210 , L_74 , sizeof( V_186 -> V_210 ) ) ;
V_186 -> V_211 = V_212 ;
return 0 ;
}
static int F_72 ( struct V_171 * V_171 , void * V_86 ,
struct V_213 * V_186 )
{
struct V_1 * V_2 = F_52 ( V_171 ) ;
V_186 -> V_214 . V_215 . V_211 = V_212 ;
V_186 -> V_214 . V_215 . V_216 = 0 ;
V_186 -> V_214 . V_215 . V_217 =
V_2 -> V_124 . V_147 * V_2 -> V_124 . V_149 ;
V_186 -> V_214 . V_215 . V_218 = 0 ;
V_186 -> V_214 . V_215 . V_126 = V_2 -> V_124 . V_126 ;
V_186 -> V_214 . V_215 . V_125 = V_2 -> V_124 . V_125 ;
V_186 -> V_214 . V_215 . V_219 = V_220 ;
F_2 ( 1 , L_75 ,
V_2 -> V_124 . V_126 , V_2 -> V_124 . V_125 ) ;
return 0 ;
}
static int F_73 ( struct V_171 * V_171 , void * V_86 ,
struct V_213 * V_186 )
{
struct V_1 * V_2 = F_52 ( V_171 ) ;
V_186 -> V_214 . V_215 . V_211 = V_212 ;
V_186 -> V_214 . V_215 . V_216 = 0 ;
V_186 -> V_214 . V_215 . V_217 =
V_2 -> V_124 . V_147 * V_2 -> V_124 . V_149 ;
V_186 -> V_214 . V_215 . V_218 = 0 ;
V_186 -> V_214 . V_215 . V_219 = V_220 ;
F_2 ( 1 , L_76 ,
V_2 -> V_124 . V_126 , V_2 -> V_124 . V_125 ) ;
return 0 ;
}
static int F_74 ( struct V_171 * V_171 , void * V_86 ,
struct V_213 * V_186 )
{
struct V_1 * V_2 = F_52 ( V_171 ) ;
V_186 -> V_214 . V_215 . V_211 = V_212 ;
V_186 -> V_214 . V_215 . V_216 = 0 ;
V_186 -> V_214 . V_215 . V_217 =
V_2 -> V_124 . V_147 * V_2 -> V_124 . V_149 ;
V_186 -> V_214 . V_215 . V_218 = 0 ;
V_186 -> V_214 . V_215 . V_219 = V_220 ;
F_2 ( 1 , L_77 ,
V_186 -> V_214 . V_215 . V_126 , V_186 -> V_214 . V_215 . V_125 , V_186 -> V_214 . V_215 . V_219 ) ;
return 0 ;
}
static int F_75 ( struct V_171 * V_171 , void * V_86 )
{
struct V_1 * V_2 = F_52 ( V_171 ) ;
char V_181 [ 32 + 2 ] ;
snprintf ( V_181 , sizeof( V_181 ) , L_78 , V_2 -> V_181 ) ;
F_63 ( V_2 , V_221 , V_222 ) ;
F_76 ( & V_2 -> V_127 . V_223 , V_181 ) ;
return 0 ;
}
void F_77 ( struct V_1 * V_2 )
{
F_2 ( 1 , L_1 , V_4 ) ;
if ( V_2 -> V_224 ) {
if ( F_78 ( V_2 -> V_224 ) )
F_79 ( V_2 -> V_224 ) ;
else
F_80 ( V_2 -> V_224 ) ;
F_81 ( & V_2 -> V_127 . V_223 ) ;
V_2 -> V_224 = NULL ;
}
}
static struct V_225 * F_82 (
struct V_193 * V_194 ,
struct V_226 * V_117 ,
struct V_225 * V_227 ,
char * type )
{
struct V_225 * V_228 ;
struct V_1 * V_2 = V_194 -> V_2 ;
F_2 ( 1 , L_1 , V_4 ) ;
V_228 = F_83 () ;
if ( NULL == V_228 )
return NULL ;
* V_228 = * V_227 ;
snprintf ( V_228 -> V_181 , sizeof( V_228 -> V_181 ) , L_79 ,
V_197 [ V_194 -> V_2 -> V_198 ] . V_181 , type ) ;
V_228 -> V_229 = & V_2 -> V_229 ;
V_228 -> V_230 = F_80 ;
return V_228 ;
}
int F_84 ( struct V_1 * V_2 )
{
int V_99 = - V_231 ;
struct V_193 * V_194 = & V_2 -> V_124 ;
struct V_139 * V_140 ;
F_2 ( 1 , L_1 , V_4 ) ;
if ( V_197 [ V_2 -> V_198 ] . V_232 != V_233 )
return V_99 ;
V_2 -> V_121 = V_173 [ 0 ] ;
if ( V_2 -> V_121 . V_122 & V_123 )
V_194 -> V_125 = 480 ;
else
V_194 -> V_125 = 576 ;
V_194 -> V_126 = 720 ;
V_2 -> V_127 . V_234 = V_235 ;
V_99 = F_85 ( & V_2 -> V_127 , 50 ) ;
if ( V_99 )
return V_99 ;
V_2 -> V_127 . V_86 = V_2 ;
V_2 -> V_127 . V_236 = F_22 ;
F_86 ( & V_2 -> V_127 , V_194 -> V_125 == 576 ) ;
F_87 ( & V_2 -> V_237 , & V_2 -> V_127 . V_223 , NULL ) ;
V_2 -> V_224 = F_82 ( V_194 ,
V_2 -> V_117 , & V_238 , L_80 ) ;
V_140 = & V_2 -> V_239 ;
V_140 -> type = V_240 ;
V_140 -> V_241 = V_242 | V_243 | V_244 | V_245 ;
V_140 -> V_246 = V_247 ;
V_140 -> V_248 = 2 ;
V_140 -> V_146 = V_2 ;
V_140 -> V_249 = sizeof( struct V_156 ) ;
V_140 -> V_250 = & V_251 ;
V_140 -> V_252 = & V_253 ;
V_140 -> V_254 = V_255 ;
V_140 -> V_256 = & V_2 -> V_256 ;
V_140 -> V_2 = & V_2 -> V_117 -> V_2 ;
V_99 = F_88 ( V_140 ) ;
if ( V_99 < 0 )
return V_99 ;
F_89 ( V_2 -> V_224 , V_2 ) ;
V_2 -> V_224 -> V_256 = & V_2 -> V_256 ;
V_2 -> V_224 -> V_166 = V_140 ;
V_99 = F_90 ( V_2 -> V_224 ,
V_257 , - 1 ) ;
if ( V_99 < 0 ) {
F_91 ( L_81 , V_2 -> V_181 ) ;
return V_99 ;
}
F_91 ( L_82 ,
V_2 -> V_181 , F_92 ( V_2 -> V_224 ) ) ;
F_30 ( V_2 , 0 ) ;
return 0 ;
}
