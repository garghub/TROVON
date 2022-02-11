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
static int F_22 ( struct V_1 * V_2 )
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
static int F_23 ( struct V_1 * V_2 )
{
static const unsigned char V_105 [ 8 ] = {
0xa7 , 0x0d , 0x00 , 0x00 , 0x66 , 0xbb , 0x55 , 0xaa
} ;
const struct V_106 * V_106 ;
int V_93 , V_28 = 0 ;
T_1 V_19 = 0 ;
T_1 V_107 = 0 ;
T_1 V_108 = 0 ;
T_1 * V_109 ;
F_2 ( 2 , L_1 , V_4 ) ;
V_28 |= F_14 ( V_2 , 0x9020 , & V_107 ) ;
V_28 |= F_14 ( V_2 , 0x900C , & V_19 ) ;
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
F_20 ( V_95 L_55 ,
V_4 ) ;
return - 1 ;
}
V_28 = F_24 ( & V_106 , V_116 ,
& V_2 -> V_117 -> V_2 ) ;
if ( V_28 != 0 ) {
F_20 ( V_95
L_56 ,
V_116 ) ;
F_20 ( V_95 L_57
L_58 ) ;
return - 1 ;
}
if ( V_106 -> V_118 != V_104 ) {
F_20 ( V_95 L_59
L_60 ,
V_106 -> V_118 , V_104 ) ;
F_25 ( V_106 ) ;
return - 1 ;
}
if ( 0 != memcmp ( V_106 -> V_90 , V_105 , 8 ) ) {
F_20 ( V_95
L_61 ) ;
F_25 ( V_106 ) ;
return - 1 ;
}
F_2 ( 2 , L_62 ) ;
V_109 = ( T_1 * ) V_106 -> V_90 ;
for ( V_93 = 0 ; V_93 < ( V_106 -> V_118 >> 2 ) ; V_93 ++ ) {
V_19 = * V_109 ;
V_108 += ~ V_19 ;
if ( F_13 ( V_2 , V_93 , V_19 ) != 0 ) {
F_20 ( V_95 L_63 ) ;
F_25 ( V_106 ) ;
return - 1 ;
}
V_109 ++ ;
}
F_2 ( 1 , L_64 ) ;
for ( V_93 -- ; V_93 >= 0 ; V_93 -- ) {
if ( F_14 ( V_2 , V_93 , & V_19 ) != 0 ) {
F_20 ( V_95 L_65 ) ;
F_25 ( V_106 ) ;
return - 1 ;
}
V_108 -= ~ V_19 ;
}
if ( V_108 ) {
F_20 ( V_95
L_66 ) ;
F_25 ( V_106 ) ;
return - 1 ;
}
F_25 ( V_106 ) ;
F_2 ( 1 , L_67 ) ;
V_28 |= F_11 ( V_2 , V_111 ,
V_112 ) ;
V_28 |= F_11 ( V_2 , 0x9020 , V_107 ) ;
V_28 |= F_11 ( V_2 , 0x900C , V_19 ) ;
V_28 |= F_12 ( V_2 , V_110 , & V_19 ) ;
V_28 |= F_11 ( V_2 , V_110 , V_19 & 0xFFFFFFE8 ) ;
if ( V_28 < 0 )
F_20 ( V_95 L_55 ,
V_4 ) ;
return 0 ;
}
void F_26 ( struct V_1 * V_2 )
{
T_1 V_119 , V_120 ;
V_119 = V_120 = 0 ;
F_21 ( V_2 , V_68 , 0 , 2 , & V_119 , & V_120 ) ;
F_2 ( 1 , L_68 , V_4 , V_119 , V_120 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_2 ( 1 , L_1 , V_4 ) ;
F_21 ( V_2 , V_53 , 2 , 0 ,
V_2 -> V_121 . V_122 , V_2 -> V_121 . V_123 ) ;
V_2 -> V_124 . V_123 = V_2 -> V_121 . V_123 ;
V_2 -> V_124 . V_122 = V_2 -> V_121 . V_122 ;
V_2 -> V_124 . V_125 =
( V_2 -> V_126 . V_127 & V_128 ) != 0 ;
F_28 ( V_2 , F_19 , NULL , & V_2 -> V_124 ) ;
F_21 ( V_2 , V_85 , 2 , 0 , 3 , 1 ) ;
F_21 ( V_2 , V_85 , 2 , 0 , 4 , 1 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_129 ;
int V_28 ;
T_1 V_93 , V_90 [ 7 ] ;
F_2 ( 1 , L_1 , V_4 ) ;
V_28 = F_21 ( V_2 , V_46 , 0 , 0 ) ;
if ( V_28 < 0 ) {
F_2 ( 2 , L_69 , V_4 ) ;
V_28 = F_23 ( V_2 ) ;
if ( V_28 < 0 ) {
F_20 ( V_95 L_70 , V_4 ) ;
return V_28 ;
}
V_28 = F_22 ( V_2 ) ;
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
& V_129 ) ;
if ( V_28 < 0 ) {
F_20 ( V_95 L_73
L_74 ) ;
return - 1 ;
}
F_2 ( 1 , L_75 , V_129 ) ;
F_30 ( 200 ) ;
}
F_27 ( V_2 ) ;
F_30 ( 60 ) ;
F_21 ( V_2 , V_81 , 2 , 0 ,
V_130 , V_131 ) ;
F_21 ( V_2 , V_82 , 12 , 0 ,
V_132 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
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
int V_133 ;
V_133 = ( ( V_93 >= 19 ) && ( V_93 <= 21 ) ) ;
F_21 ( V_2 , V_61 , 5 , 0 , V_93 ,
V_133 , 0 , 0 , 0 ) ;
F_21 ( V_2 , V_61 , 5 , 0 ,
V_93 | 0x80000000 , V_133 , 0 , 0 , 0 ) ;
}
F_21 ( V_2 , V_84 , 1 , 0 , V_134 ) ;
F_30 ( 60 ) ;
F_21 ( V_2 , V_75 , 0 , 0 ) ;
F_30 ( 60 ) ;
F_13 ( V_2 , 2120 , 0x00000080 ) ;
F_21 ( V_2 , V_47 , 2 , 0 ,
V_135 , V_136 ) ;
F_30 ( 10 ) ;
return 0 ;
}
static int F_31 ( struct V_137 * V_138 ,
unsigned int * V_139 , unsigned int * V_118 )
{
struct V_140 * V_141 = V_138 -> V_142 ;
V_141 -> V_2 -> V_121 . V_143 = V_144 ;
V_141 -> V_2 -> V_121 . V_145 = V_146 ;
* V_118 = V_141 -> V_2 -> V_121 . V_143 * V_141 -> V_2 -> V_121 . V_145 ;
* V_139 = V_147 ;
return 0 ;
}
static int F_32 ( struct V_137 * V_138 ,
struct V_148 * V_149 , enum V_150 V_151 )
{
struct V_140 * V_141 = V_138 -> V_142 ;
return F_33 ( V_138 , & V_141 -> V_2 -> V_121 ,
(struct V_152 * ) V_149 ,
V_151 ) ;
}
static void F_34 ( struct V_137 * V_138 ,
struct V_148 * V_149 )
{
struct V_140 * V_141 = V_138 -> V_142 ;
F_35 ( & V_141 -> V_2 -> V_121 , (struct V_152 * ) V_149 ) ;
}
static void F_36 ( struct V_137 * V_138 ,
struct V_148 * V_149 )
{
F_37 ( V_138 , (struct V_152 * ) V_149 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_153 * V_154 )
{
V_154 -> V_127 = F_39 ( V_155 , V_154 -> V_127 ) ;
if ( V_154 -> V_127 == 0 )
return - V_156 ;
if ( F_40 ( & V_2 -> V_124 , V_154 ) )
V_154 -> V_157 |= V_158 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_159 * V_160 )
{
struct V_153 V_154 ;
V_154 . V_127 = V_160 -> V_127 ;
F_38 ( V_2 , & V_154 ) ;
return F_42 ( V_160 , & V_154 ,
F_43 ( & V_2 -> V_124 , V_160 -> V_127 ) ) ;
}
static int F_44 ( struct V_161 * V_161 , void * V_86 , T_4 * V_127 )
{
struct V_140 * V_141 = V_161 -> V_162 ;
struct V_1 * V_2 = V_141 -> V_2 ;
unsigned int V_93 ;
for ( V_93 = 0 ; V_93 < F_45 ( V_163 ) ; V_93 ++ )
if ( * V_127 & V_163 [ V_93 ] . V_127 )
break;
if ( V_93 == F_45 ( V_163 ) )
return - V_156 ;
V_2 -> V_126 = V_163 [ V_93 ] ;
return 0 ;
}
static int F_46 ( struct V_161 * V_161 , void * V_86 ,
struct V_164 * V_93 )
{
struct V_140 * V_141 = V_161 -> V_162 ;
struct V_1 * V_2 = V_141 -> V_2 ;
struct V_165 * V_166 ;
int V_167 ;
if ( V_93 -> V_168 >= 4 )
return - V_156 ;
V_166 = & V_169 [ V_2 -> V_170 ] . V_166 [ V_93 -> V_168 ] ;
if ( V_166 -> type == 0 )
return - V_156 ;
strcpy ( V_93 -> V_171 , L_76 ) ;
if ( V_166 -> type == V_172 ||
V_166 -> type == V_173 )
V_93 -> type = V_174 ;
else
V_93 -> type = V_175 ;
for ( V_167 = 0 ; V_167 < F_45 ( V_163 ) ; V_167 ++ )
V_93 -> V_176 |= V_163 [ V_167 ] . V_127 ;
return 0 ;
}
static int F_47 ( struct V_161 * V_161 , void * V_86 , unsigned int * V_93 )
{
struct V_140 * V_141 = V_161 -> V_162 ;
struct V_1 * V_2 = V_141 -> V_2 ;
* V_93 = V_2 -> V_166 ;
return 0 ;
}
static int F_48 ( struct V_161 * V_161 , void * V_86 , unsigned int V_93 )
{
if ( V_93 >= 4 )
return - V_156 ;
return 0 ;
}
static int F_49 ( struct V_161 * V_161 , void * V_86 ,
struct V_177 * V_178 )
{
struct V_140 * V_141 = V_161 -> V_162 ;
struct V_1 * V_2 = V_141 -> V_2 ;
if ( V_179 == V_2 -> V_180 )
return - V_156 ;
if ( 0 != V_178 -> V_168 )
return - V_156 ;
strcpy ( V_178 -> V_171 , L_77 ) ;
F_50 ( V_2 , V_181 , V_182 , V_178 ) ;
F_2 ( 1 , L_78 , V_178 -> type ) ;
return 0 ;
}
static int F_51 ( struct V_161 * V_161 , void * V_86 ,
struct V_177 * V_178 )
{
struct V_140 * V_141 = V_161 -> V_162 ;
struct V_1 * V_2 = V_141 -> V_2 ;
if ( V_179 == V_2 -> V_180 )
return - V_156 ;
F_50 ( V_2 , V_181 , V_183 , V_178 ) ;
return 0 ;
}
static int F_52 ( struct V_161 * V_161 , void * V_86 ,
struct V_184 * V_185 )
{
struct V_140 * V_141 = V_161 -> V_162 ;
struct V_1 * V_2 = V_141 -> V_2 ;
if ( V_179 == V_2 -> V_180 )
return - V_156 ;
V_185 -> type = V_186 ;
V_185 -> V_187 = V_2 -> V_188 ;
F_50 ( V_2 , V_181 , V_189 , V_185 ) ;
return 0 ;
}
static int F_53 ( struct V_161 * V_161 , void * V_86 ,
struct V_184 * V_185 )
{
struct V_140 * V_141 = V_161 -> V_162 ;
struct V_1 * V_2 = V_141 -> V_2 ;
F_21 ( V_141 -> V_2 , V_48 , 3 , 0 ,
V_190 , V_135 ,
V_136 ) ;
F_2 ( 1 , L_79 ,
V_2 -> V_180 ) ;
F_2 ( 1 , L_80 ,
V_185 -> V_181 , V_185 -> type ) ;
if ( V_179 == V_2 -> V_180 )
return - V_156 ;
if ( V_185 -> V_181 != 0 )
return - V_156 ;
if ( V_185 -> type != V_186 )
return - V_156 ;
V_2 -> V_188 = V_185 -> V_187 ;
F_50 ( V_2 , V_181 , V_191 , V_185 ) ;
F_29 ( V_2 ) ;
return 0 ;
}
static int F_54 ( struct V_161 * V_161 , void * V_86 ,
struct V_192 * V_193 )
{
struct V_140 * V_141 = V_161 -> V_162 ;
struct V_1 * V_2 = V_141 -> V_2 ;
F_50 ( V_2 , V_194 , V_195 , V_193 ) ;
return 0 ;
}
static int F_55 ( struct V_161 * V_161 , void * V_86 ,
struct V_196 * V_197 )
{
struct V_140 * V_141 = V_161 -> V_162 ;
struct V_1 * V_2 = V_141 -> V_2 ;
struct V_198 * V_199 = & V_2 -> V_121 ;
F_56 ( V_197 -> V_200 , V_2 -> V_171 , sizeof( V_197 -> V_200 ) ) ;
F_56 ( V_197 -> V_201 , V_169 [ V_199 -> V_2 -> V_170 ] . V_171 ,
sizeof( V_197 -> V_201 ) ) ;
sprintf ( V_197 -> V_202 , L_81 , F_57 ( V_2 -> V_117 ) ) ;
V_197 -> V_129 = V_203 ;
V_197 -> V_204 =
V_205 |
V_206 |
V_207 |
0 ;
if ( V_179 != V_2 -> V_180 )
V_197 -> V_204 |= V_208 ;
return 0 ;
}
static int F_58 ( struct V_161 * V_161 , void * V_86 ,
struct V_209 * V_185 )
{
if ( V_185 -> V_168 != 0 )
return - V_156 ;
F_56 ( V_185 -> V_210 , L_82 , sizeof( V_185 -> V_210 ) ) ;
V_185 -> V_211 = V_212 ;
return 0 ;
}
static int F_59 ( struct V_161 * V_161 , void * V_86 ,
struct V_213 * V_185 )
{
struct V_140 * V_141 = V_161 -> V_162 ;
struct V_1 * V_2 = V_141 -> V_2 ;
V_185 -> V_214 . V_215 . V_211 = V_212 ;
V_185 -> V_214 . V_215 . V_216 = 0 ;
V_185 -> V_214 . V_215 . V_217 =
V_2 -> V_121 . V_143 * V_2 -> V_121 . V_145 ;
V_185 -> V_214 . V_215 . V_218 = 0 ;
V_185 -> V_214 . V_215 . V_123 = V_2 -> V_121 . V_123 ;
V_185 -> V_214 . V_215 . V_122 = V_2 -> V_121 . V_122 ;
V_185 -> V_214 . V_215 . V_151 = V_141 -> V_219 . V_151 ;
F_2 ( 1 , L_83 ,
V_2 -> V_121 . V_123 , V_2 -> V_121 . V_122 , V_141 -> V_219 . V_151 ) ;
return 0 ;
}
static int F_60 ( struct V_161 * V_161 , void * V_86 ,
struct V_213 * V_185 )
{
struct V_140 * V_141 = V_161 -> V_162 ;
struct V_1 * V_2 = V_141 -> V_2 ;
V_185 -> V_214 . V_215 . V_211 = V_212 ;
V_185 -> V_214 . V_215 . V_216 = 0 ;
V_185 -> V_214 . V_215 . V_217 =
V_2 -> V_121 . V_143 * V_2 -> V_121 . V_145 ;
V_185 -> V_214 . V_215 . V_218 = 0 ;
F_2 ( 1 , L_84 ,
V_2 -> V_121 . V_123 , V_2 -> V_121 . V_122 , V_141 -> V_219 . V_151 ) ;
return 0 ;
}
static int F_61 ( struct V_161 * V_161 , void * V_86 ,
struct V_213 * V_185 )
{
struct V_140 * V_141 = V_161 -> V_162 ;
struct V_1 * V_2 = V_141 -> V_2 ;
V_185 -> V_214 . V_215 . V_211 = V_212 ;
V_185 -> V_214 . V_215 . V_216 = 0 ;
V_185 -> V_214 . V_215 . V_217 =
V_2 -> V_121 . V_143 * V_2 -> V_121 . V_145 ;
V_185 -> V_214 . V_215 . V_218 = 0 ;
F_2 ( 1 , L_85 ,
V_185 -> V_214 . V_215 . V_123 , V_185 -> V_214 . V_215 . V_122 , V_185 -> V_214 . V_215 . V_151 ) ;
return 0 ;
}
static int F_62 ( struct V_161 * V_161 , void * V_86 ,
struct V_220 * V_221 )
{
struct V_140 * V_141 = V_161 -> V_162 ;
return F_63 ( & V_141 -> V_219 , V_221 ) ;
}
static int F_64 ( struct V_161 * V_161 , void * V_86 ,
struct V_222 * V_221 )
{
struct V_140 * V_141 = V_161 -> V_162 ;
return F_65 ( & V_141 -> V_219 , V_221 ) ;
}
static int F_66 ( struct V_161 * V_161 , void * V_86 ,
struct V_222 * V_221 )
{
struct V_140 * V_141 = V_161 -> V_162 ;
return F_67 ( & V_141 -> V_219 , V_221 ) ;
}
static int F_68 ( struct V_161 * V_161 , void * V_86 , struct V_222 * V_223 )
{
struct V_140 * V_141 = V_86 ;
return F_69 ( & V_141 -> V_219 , V_223 , V_161 -> V_224 & V_225 ) ;
}
static int F_70 ( struct V_161 * V_161 , void * V_86 ,
enum V_226 V_93 )
{
struct V_140 * V_141 = V_161 -> V_162 ;
return F_71 ( & V_141 -> V_219 ) ;
}
static int F_72 ( struct V_161 * V_161 , void * V_86 , enum V_226 V_93 )
{
struct V_140 * V_141 = V_161 -> V_162 ;
return F_73 ( & V_141 -> V_219 ) ;
}
static int F_74 ( struct V_161 * V_161 , void * V_86 ,
struct V_227 * V_185 )
{
struct V_140 * V_141 = V_86 ;
struct V_1 * V_2 = V_141 -> V_2 ;
if ( V_185 -> V_228 != V_229 )
return - V_156 ;
return F_75 ( & V_2 -> V_124 , 0 , V_185 , V_230 ) ;
}
static int F_76 ( struct V_161 * V_161 , void * V_86 ,
struct V_227 * V_185 )
{
struct V_140 * V_141 = V_86 ;
struct V_1 * V_2 = V_141 -> V_2 ;
struct V_231 V_221 ;
int V_100 ;
if ( V_185 -> V_228 != V_229 )
return - V_156 ;
V_221 = V_2 -> V_124 ;
V_100 = F_75 ( & V_221 , 0 , V_185 , V_232 ) ;
if ( V_100 == 0 ) {
V_100 = F_28 ( V_2 , F_19 ,
& V_2 -> V_124 , & V_221 ) ;
V_2 -> V_124 = V_221 ;
}
return V_100 ;
}
static int F_77 ( struct V_161 * V_161 , void * V_86 ,
struct V_227 * V_185 )
{
struct V_140 * V_141 = V_86 ;
struct V_1 * V_2 = V_141 -> V_2 ;
struct V_231 V_221 ;
int V_100 ;
if ( V_185 -> V_228 != V_229 )
return - V_156 ;
V_221 = V_2 -> V_124 ;
V_100 = F_75 ( & V_221 , 0 , V_185 , V_233 ) ;
return V_100 ;
}
static int F_78 ( struct V_161 * V_161 , void * V_86 )
{
struct V_140 * V_141 = V_86 ;
struct V_1 * V_2 = V_141 -> V_2 ;
char V_171 [ 32 + 2 ] ;
snprintf ( V_171 , sizeof( V_171 ) , L_86 , V_2 -> V_171 ) ;
F_20 ( V_234
L_87 ,
V_2 -> V_171 ) ;
F_50 ( V_2 , V_194 , V_235 ) ;
F_79 ( & V_2 -> V_124 , V_171 ) ;
F_20 ( V_234
L_88 ,
V_2 -> V_171 ) ;
return 0 ;
}
static int F_80 ( struct V_161 * V_161 , void * V_86 ,
struct V_159 * V_236 )
{
struct V_140 * V_141 = V_86 ;
struct V_1 * V_2 = V_141 -> V_2 ;
return F_41 ( V_2 , V_236 ) ;
}
static int F_81 ( struct V_161 * V_161 , void * V_86 ,
struct V_153 * V_237 )
{
struct V_140 * V_141 = V_86 ;
struct V_1 * V_2 = V_141 -> V_2 ;
return F_38 ( V_2 , V_237 ) ;
}
static int F_82 ( struct V_161 * V_161 )
{
struct V_1 * V_2 = F_83 ( V_161 ) ;
struct V_140 * V_141 ;
F_2 ( 2 , L_1 , V_4 ) ;
V_141 = F_84 ( sizeof( * V_141 ) , V_238 ) ;
if ( ! V_141 )
return - V_239 ;
V_161 -> V_162 = V_141 ;
V_141 -> V_2 = V_2 ;
F_85 ( & V_141 -> V_219 , & V_240 ,
& V_2 -> V_117 -> V_2 , & V_2 -> V_121 . V_241 ,
V_242 ,
V_243 ,
sizeof( struct V_152 ) ,
V_141 , NULL ) ;
return 0 ;
}
static int F_86 ( struct V_161 * V_161 )
{
struct V_140 * V_141 = V_161 -> V_162 ;
struct V_1 * V_2 = V_141 -> V_2 ;
F_2 ( 2 , L_1 , V_4 ) ;
if ( F_87 ( & V_141 -> V_244 , 1 , 0 ) == 1 ) {
if ( F_88 ( & V_2 -> V_245 ) == 0 ) {
F_21 ( V_141 -> V_2 , V_48 , 3 , 0 ,
V_190 , V_135 ,
V_136 ) ;
F_30 ( 500 ) ;
F_26 ( V_2 ) ;
F_89 ( & V_141 -> V_2 -> V_121 ) ;
}
}
if ( V_141 -> V_219 . V_246 )
F_73 ( & V_141 -> V_219 ) ;
if ( V_141 -> V_219 . V_247 )
F_90 ( & V_141 -> V_219 ) ;
F_91 ( & V_141 -> V_219 ) ;
V_161 -> V_162 = NULL ;
F_92 ( V_141 ) ;
return 0 ;
}
static T_5 F_93 ( struct V_161 * V_161 , char T_6 * V_90 ,
T_7 V_139 , T_8 * V_248 )
{
struct V_140 * V_141 = V_161 -> V_162 ;
struct V_1 * V_2 = V_141 -> V_2 ;
F_2 ( 2 , L_1 , V_4 ) ;
if ( F_87 ( & V_141 -> V_244 , 0 , 1 ) == 0 ) {
if ( F_94 ( & V_2 -> V_245 ) == 1 ) {
if ( F_29 ( V_2 ) < 0 )
return - V_156 ;
}
}
return F_95 ( & V_141 -> V_219 , V_90 , V_139 , V_248 , 0 ,
V_161 -> V_224 & V_225 ) ;
}
static unsigned int F_96 ( struct V_161 * V_161 ,
struct V_249 * V_250 )
{
struct V_140 * V_141 = V_161 -> V_162 ;
struct V_1 * V_2 = V_141 -> V_2 ;
F_2 ( 2 , L_89 , V_4 ) ;
return F_97 ( V_161 , & V_141 -> V_219 , V_250 ) ;
}
static int F_98 ( struct V_161 * V_161 , struct V_251 * V_252 )
{
struct V_140 * V_141 = V_161 -> V_162 ;
struct V_1 * V_2 = V_141 -> V_2 ;
F_2 ( 2 , L_1 , V_4 ) ;
return F_99 ( & V_141 -> V_219 , V_252 ) ;
}
void F_100 ( struct V_1 * V_2 )
{
F_2 ( 1 , L_1 , V_4 ) ;
if ( V_2 -> V_253 ) {
if ( F_101 ( V_2 -> V_253 ) )
F_102 ( V_2 -> V_253 ) ;
else
F_103 ( V_2 -> V_253 ) ;
V_2 -> V_253 = NULL ;
}
}
static struct V_254 * F_104 (
struct V_198 * V_199 ,
struct V_255 * V_117 ,
struct V_254 * V_256 ,
char * type )
{
struct V_254 * V_257 ;
struct V_1 * V_2 = V_199 -> V_2 ;
F_2 ( 1 , L_1 , V_4 ) ;
V_257 = F_105 () ;
if ( NULL == V_257 )
return NULL ;
* V_257 = * V_256 ;
snprintf ( V_257 -> V_171 , sizeof( V_257 -> V_171 ) , L_90 , V_2 -> V_171 ,
type , V_169 [ V_199 -> V_2 -> V_170 ] . V_171 ) ;
V_257 -> V_258 = & V_117 -> V_2 ;
V_257 -> V_259 = F_103 ;
return V_257 ;
}
int F_106 ( struct V_1 * V_2 )
{
int V_100 = - V_260 ;
struct V_198 * V_199 = & V_2 -> V_121 ;
F_2 ( 1 , L_1 , V_4 ) ;
if ( V_169 [ V_2 -> V_170 ] . V_261 != V_262 )
return V_100 ;
V_2 -> V_126 = V_163 [ 0 ] ;
if ( V_2 -> V_126 . V_127 & V_263 )
V_199 -> V_122 = 480 ;
else
V_199 -> V_122 = 576 ;
V_199 -> V_123 = 720 ;
F_107 ( & V_2 -> V_124 ) ;
V_2 -> V_124 . V_264 = V_265 ;
V_2 -> V_253 = F_104 ( V_199 ,
V_2 -> V_117 , & V_266 , L_91 ) ;
F_108 ( V_2 -> V_253 , V_2 ) ;
V_100 = F_109 ( V_2 -> V_253 ,
V_267 , - 1 ) ;
if ( V_100 < 0 ) {
F_20 ( V_234 L_92 , V_2 -> V_171 ) ;
return V_100 ;
}
F_20 ( V_234 L_93 ,
V_2 -> V_171 , F_110 ( V_2 -> V_253 ) ) ;
return 0 ;
}
