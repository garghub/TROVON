static inline void F_1 ( void T_1 * V_1 )
{
F_2 ( 0 , V_1 + V_2 ) ;
}
static void F_3 ( struct V_3 * V_4 , T_2 * V_5 , int V_6 )
{
int V_7 ;
struct V_8 * V_9 = V_4 -> V_10 ;
T_3 * V_11 = ( T_3 * ) V_5 ;
V_6 >>= 1 ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ )
V_11 [ V_7 ] = F_4 ( V_9 -> V_12 ) ;
}
static void F_5 ( struct V_3 * V_4 , const T_2 * V_5 , int V_6 )
{
int V_7 ;
struct V_8 * V_9 = V_4 -> V_10 ;
T_3 * V_11 = ( T_3 * ) V_5 ;
V_6 >>= 1 ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ )
F_2 ( V_11 [ V_7 ] , V_9 -> V_13 ) ;
}
static int F_6 ( struct V_14 * V_15 )
{
T_3 V_16 ;
unsigned int V_17 ;
void T_1 * V_1 = V_15 -> V_18 ;
F_7 ( V_15 -> V_19 , L_1 , V_20 ) ;
V_16 = F_4 ( V_1 + V_21 ) ;
V_17 = 1000 ;
do {
F_8 () ;
V_16 = F_9 ( V_1 + V_21 ) ;
} while ( ! ( V_16 & V_22 ) && -- V_17 );
if ( ! V_17 ) {
F_10 ( V_15 -> V_19 , L_2 , V_20 ) ;
return V_23 ;
}
if ( F_11 ( V_17 < 50 ) )
F_12 ( V_15 -> V_19 , L_3 ,
V_20 , V_17 ) ;
return 0 ;
}
static int F_13 ( struct V_3 * V_4 , struct V_8 * V_9 )
{
struct V_14 * V_15 = V_9 -> V_10 ;
int V_24 = V_25 ;
F_7 ( V_15 -> V_19 , L_1 , V_20 ) ;
if ( V_15 -> V_24 ) {
V_24 |= V_15 -> V_24 ;
V_15 -> V_24 = 0 ;
return V_24 ;
}
V_24 |= F_6 ( V_15 ) ;
return V_24 ;
}
static void F_14 ( struct V_3 * V_4 , int V_26 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
F_7 ( V_15 -> V_19 , L_4 , V_20 , V_26 ) ;
if ( V_26 < 0 )
return;
if ( V_26 > 0 )
F_12 ( V_15 -> V_19 , L_5 ) ;
F_2 ( 0 , V_1 + V_27 ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
F_2 ( V_28 | V_29 ,
V_1 + V_30 ) ;
F_2 ( ~ ( V_28 | V_29 ) ,
V_1 + V_31 ) ;
F_1 ( V_1 ) ;
F_2 ( V_32 | V_29 ,
V_1 + V_30 ) ;
F_2 ( ~ ( V_32 | V_29 ) ,
V_1 + V_31 ) ;
F_2 ( V_33 , V_1 + V_34 ) ;
F_6 ( V_15 ) ;
}
static void F_16 ( void T_1 * V_1 , T_2 * V_35 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < 7 ; V_7 ++ ) {
V_35 [ V_7 ] = F_9 ( V_1 + F_17 ( V_7 ) ) ;
V_35 [ V_7 ] = F_9 ( V_1 + F_17 ( V_7 ) ) ;
}
}
static int F_18 ( struct V_3 * V_4 , T_2 * V_5 , int V_36 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
int V_7 , V_37 , V_38 [ 4 ] ;
const T_2 V_39 [ 8 ] = {
0xcf , 0x72 , 0xfc , 0x1b , 0xa9 , 0xc7 , 0xb9 , 0 } ;
F_16 ( V_1 , V_15 -> V_35 ) ;
if ( ! memcmp ( V_15 -> V_35 , V_39 , 7 ) )
return 0 ;
if ( V_40 == false ) {
if ( V_9 -> V_41 [ 15 ] ) {
int V_42 , V_43 = 0 ;
unsigned long V_44 = V_9 -> V_41 [ 15 ] ;
F_19 (bit, &written_flag, 8 )
V_43 ++ ;
if ( V_43 > 4 ) {
F_12 ( V_15 -> V_19 ,
L_6
L_7 ,
V_36 * V_45 ) ;
return 0 ;
}
}
}
for ( V_7 = 0 ; V_7 < 7 ; V_7 ++ )
V_15 -> V_35 [ V_7 ] = F_20 ( V_15 -> V_35 [ V_7 ] ) ;
V_37 = F_21 ( V_15 -> V_46 , NULL , V_47 , NULL ,
V_15 -> V_35 , NULL , V_38 ) ;
if ( V_37 == - V_48 ) {
F_12 ( V_15 -> V_19 , L_8 ,
V_36 * V_45 ) ;
return - V_48 ;
}
F_22 ( V_37 < 0 ) ;
for ( V_7 = 0 ; V_7 < V_37 ; V_7 ++ )
V_38 [ V_7 ] = ( V_38 [ V_7 ] & ~ 7 ) | ( 7 - ( V_38 [ V_7 ] & 7 ) ) ;
for ( V_7 = 0 ; V_7 < V_37 ; V_7 ++ ) {
if ( V_38 [ V_7 ] > V_47 * 8 )
continue;
if ( V_38 [ V_7 ] > V_45 * 8 )
F_23 ( V_38 [ V_7 ] - V_45 * 8 ,
( unsigned long * ) V_9 -> V_41 ) ;
else
F_23 ( V_38 [ V_7 ] , ( unsigned long * ) V_5 ) ;
}
F_24 ( V_15 -> V_19 , L_9 ,
V_37 , V_36 * V_45 ) ;
return V_37 ;
}
static T_2 F_25 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
F_7 ( V_15 -> V_19 , L_10 , V_20 ) ;
if ( V_15 -> V_49 . V_50 == V_51 ) {
int V_24 ;
V_15 -> V_49 . V_50 = 0 ;
if ( V_15 -> V_24 ) {
V_24 = V_15 -> V_24 ;
V_15 -> V_24 = 0 ;
}
else
V_24 = V_25 | V_52 ;
return V_24 ;
}
F_12 ( V_15 -> V_19 , L_11 ) ;
return 0 ;
}
static void F_26 ( struct V_14 * V_15 , T_4 V_53 )
{
void T_1 * V_1 = V_15 -> V_18 ;
F_27 ( V_53 & 0xff , V_1 + V_54 ) ;
V_53 >>= 8 ;
F_27 ( V_53 & 0xff , V_1 + V_54 ) ;
V_53 >>= 8 ;
F_27 ( V_53 & 0xff , V_1 + V_54 ) ;
V_53 >>= 8 ;
F_27 ( V_53 & 0xff , V_1 + V_54 ) ;
}
static int F_28 ( struct V_14 * V_15 )
{
void T_1 * V_1 = V_15 -> V_18 ;
T_3 V_55 = F_4 ( V_1 + V_56 ) ;
T_3 V_57 = F_4 ( V_1 + V_56 ) ;
T_3 V_58 = F_4 ( V_1 + V_59 ) ;
F_7 ( V_15 -> V_19 , L_12 ,
V_20 , V_55 , V_57 , V_58 ) ;
if ( V_55 != V_60
|| V_57 != V_61
|| V_58 != V_61 ) {
V_15 -> V_24 = V_23 ;
F_12 ( V_15 -> V_19 , L_13
L_14 , V_55 , V_57 , V_58 ) ;
return - V_62 ;
}
return 0 ;
}
static int F_29 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
int V_63 = 0 ;
F_7 ( V_15 -> V_19 , L_15 , V_20 ) ;
F_2 ( V_64 , V_1 + V_65 ) ;
F_2 ( V_66 , V_1 + V_67 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_6 ( V_15 ) ;
F_2 ( V_68 , V_1 + V_65 ) ;
F_2 ( V_69 , V_1 + V_67 ) ;
F_2 ( V_70 | 4 , V_1 + V_71 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
V_63 = F_28 ( V_15 ) ;
F_2 ( 0 , V_1 + V_72 ) ;
F_1 ( V_1 ) ;
F_6 ( V_15 ) ;
F_1 ( V_1 ) ;
return V_63 ;
}
static void F_30 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
F_2 ( V_73 | V_74 , V_1 + V_21 ) ;
F_2 ( V_75 , V_1 + V_65 ) ;
F_2 ( V_76 , V_1 + V_67 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_6 ( V_15 ) ;
F_1 ( V_1 ) ;
}
static void F_31 ( struct V_3 * V_4 , T_4 V_53 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
F_7 ( V_15 -> V_19 ,
L_16 , V_20 , V_53 ) ;
F_30 ( V_4 ) ;
F_2 ( V_77 , V_1 + V_65 ) ;
F_2 ( V_78 , V_1 + V_67 ) ;
F_1 ( V_1 ) ;
F_26 ( V_15 , V_53 ) ;
F_1 ( V_1 ) ;
F_2 ( V_79 , V_1 + V_67 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_6 ( V_15 ) ;
}
static void F_32 ( struct V_3 * V_4 , T_4 V_53 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
F_7 ( V_15 -> V_19 ,
L_17 , V_20 , V_53 ) ;
F_30 ( V_4 ) ;
if ( F_11 ( V_80 ) ) {
F_2 ( V_81 , V_1 + V_65 ) ;
F_2 ( V_82 , V_1 + V_67 ) ;
F_2 ( V_83 , V_1 + V_67 ) ;
F_1 ( V_1 ) ;
}
F_2 ( V_84 , V_1 + V_65 ) ;
F_2 ( V_85 , V_1 + V_67 ) ;
F_1 ( V_1 ) ;
F_26 ( V_15 , V_53 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_6 ( V_15 ) ;
}
static T_4 F_33 ( int V_36 , int V_86 )
{
int V_87 = V_36 / 4 ;
int V_88 = ( V_36 % 4 ) * 0x108 + V_86 / 2 ;
return ( V_87 << 16 ) | V_88 ;
}
static void F_34 ( struct V_3 * V_4 , unsigned V_50 , int V_86 ,
int V_89 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
T_4 V_90 = F_33 ( V_89 , V_86 ) ;
F_7 ( V_15 -> V_19 , L_18 ,
V_20 , V_50 , V_89 , V_86 ) ;
V_15 -> V_49 . V_50 = V_50 ;
V_15 -> V_49 . V_86 = V_86 ;
V_15 -> V_49 . V_36 = V_89 ;
switch ( V_50 ) {
case V_91 :
F_15 ( V_4 ) ;
break;
case V_92 :
F_31 ( V_4 , V_90 ) ;
break;
case V_51 :
break;
case V_93 :
if ( F_11 ( V_80 ) ) {
T_3 V_87 = V_90 >> 16 ;
if ( V_87 & 0x01 )
F_12 ( V_15 -> V_19 ,
L_19 ) ;
}
F_32 ( V_4 , V_90 ) ;
if ( V_15 -> V_94 == V_89 )
memcpy ( V_9 -> V_41 , V_15 -> V_95 , 16 ) ;
break;
case V_96 :
F_29 ( V_4 ) ;
break;
case V_97 :
case V_98 :
case V_99 :
case V_100 :
F_12 ( V_15 -> V_19 , L_20
L_21 , V_50 ) ;
break;
}
}
static int F_35 ( struct V_3 * V_4 , struct V_8 * V_9 ,
T_2 * V_5 , int V_36 , bool V_101 )
{
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
T_3 V_24 , V_102 , * V_103 ;
int V_104 = 0 ;
F_7 ( V_15 -> V_19 , L_22 , V_20 , V_36 ) ;
F_2 ( V_70 |
V_105 |
V_106 |
V_107 ,
V_1 + V_71 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
V_24 = F_4 ( V_1 + V_56 ) ;
if ( V_24 & V_108 ) {
F_10 ( V_15 -> V_19 ,
L_23 , V_24 ) ;
F_2 ( 0 , V_1 + V_72 ) ;
return - V_62 ;
}
F_7 ( V_15 -> V_19 , L_24 , V_20 , V_24 ) ;
F_3 ( V_4 , V_5 , V_45 ) ;
F_3 ( V_4 , V_9 -> V_41 , 14 ) ;
V_103 = ( T_3 * ) ( V_9 -> V_41 + 14 ) ;
* V_103 = F_4 ( V_1 + V_59 ) ;
F_1 ( V_1 ) ;
if ( F_36 ( V_101 == true ) ) {
V_102 = F_4 ( V_1 + V_34 ) ;
V_102 = F_4 ( V_1 + V_34 ) ;
F_7 ( V_15 -> V_19 , L_25 , V_20 , V_102 ) ;
if ( V_102 & V_109 ) {
V_104 = F_18 ( V_4 , V_5 , V_36 ) ;
if ( V_104 == - V_48 )
V_4 -> V_110 . V_111 ++ ;
else
V_4 -> V_110 . V_112 += V_104 ;
}
}
F_2 ( 0 , V_1 + V_72 ) ;
if ( V_104 == - V_48 )
return 0 ;
return V_104 ;
}
static int F_37 ( struct V_3 * V_4 , struct V_8 * V_9 ,
T_2 * V_5 , int V_113 , int V_36 )
{
return F_35 ( V_4 , V_9 , V_5 , V_36 , false ) ;
}
static int F_38 ( struct V_3 * V_4 , struct V_8 * V_9 ,
T_2 * V_5 , int V_113 , int V_36 )
{
return F_35 ( V_4 , V_9 , V_5 , V_36 , true ) ;
}
static int F_39 ( struct V_3 * V_4 , struct V_8 * V_9 ,
int V_36 )
{
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
T_3 V_24 ;
F_7 ( V_15 -> V_19 , L_26 , V_20 , V_36 ) ;
F_34 ( V_4 , V_92 , V_9 -> V_114 . V_115 , V_36 ) ;
F_2 ( V_70 | V_116 , V_1 + V_71 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
V_24 = F_4 ( V_1 + V_56 ) ;
if ( V_24 & V_108 ) {
F_12 ( V_15 -> V_19 ,
L_27 , V_24 ) ;
return - V_62 ;
}
F_7 ( V_15 -> V_19 , L_24 , V_20 , V_24 ) ;
F_3 ( V_4 , V_9 -> V_41 , 16 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_2 ( 0 , V_1 + V_72 ) ;
F_1 ( V_1 ) ;
return 0 ;
}
static void F_40 ( struct V_3 * V_4 , int V_36 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
T_3 V_87 ;
F_7 ( V_15 -> V_19 , L_28 , V_20 , V_36 ) ;
F_30 ( V_4 ) ;
F_2 ( V_117 , V_1 + V_65 ) ;
F_2 ( V_118 , V_1 + V_67 ) ;
F_1 ( V_1 ) ;
V_87 = ( T_3 ) ( V_36 / 4 ) ;
F_27 ( V_87 & 0xff , V_1 + V_54 ) ;
V_87 >>= 8 ;
F_27 ( V_87 & 0xff , V_1 + V_54 ) ;
F_1 ( V_1 ) ;
F_2 ( V_119 , V_1 + V_67 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_41 ( 500 , 1000 ) ;
F_6 ( V_15 ) ;
F_2 ( V_68 , V_1 + V_65 ) ;
F_2 ( V_69 , V_1 + V_67 ) ;
F_2 ( V_70 | 4 , V_1 + V_71 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_28 ( V_15 ) ;
F_2 ( 0 , V_1 + V_72 ) ;
F_1 ( V_1 ) ;
F_6 ( V_15 ) ;
F_1 ( V_1 ) ;
}
static int F_42 ( struct V_3 * V_4 , struct V_8 * V_9 ,
const T_2 * V_5 , bool V_101 )
{
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
T_2 V_35 [ 8 ] ;
F_7 ( V_15 -> V_19 , L_1 , V_20 ) ;
F_2 ( V_105 |
V_106 |
V_107 ,
V_1 + V_71 ) ;
F_1 ( V_1 ) ;
F_5 ( V_4 , V_5 , V_45 ) ;
F_5 ( V_4 , V_9 -> V_41 , 6 ) ;
F_2 ( V_9 -> V_41 [ 6 ] , V_1 + V_120 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
if ( F_36 ( V_101 == true ) ) {
T_2 V_121 = F_9 ( V_1 + V_122 ) ;
V_121 = F_9 ( V_1 + V_122 ) ;
F_2 ( V_121 , V_1 + V_120 ) ;
F_1 ( V_1 ) ;
F_16 ( V_1 , V_35 ) ;
V_35 [ 7 ] = 0 ;
}
else {
F_2 ( V_9 -> V_41 [ 7 ] , V_1 + V_120 ) ;
F_1 ( V_1 ) ;
memcpy ( V_35 , & V_9 -> V_41 [ 8 ] , 8 ) ;
}
F_5 ( V_4 , V_35 , 8 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_2 ( 0 , V_1 + V_72 ) ;
F_1 ( V_1 ) ;
return 0 ;
}
static int F_43 ( struct V_3 * V_4 , struct V_8 * V_9 ,
const T_2 * V_5 , int V_113 )
{
return F_42 ( V_4 , V_9 , V_5 , false ) ;
}
static int F_44 ( struct V_3 * V_4 , struct V_8 * V_9 ,
const T_2 * V_5 , int V_113 )
{
return F_42 ( V_4 , V_9 , V_5 , true ) ;
}
static int F_45 ( struct V_3 * V_4 , struct V_8 * V_9 ,
int V_36 )
{
struct V_14 * V_15 = V_9 -> V_10 ;
V_15 -> V_94 = V_36 ;
memcpy ( V_15 -> V_95 , V_9 -> V_41 , 16 ) ;
return 0 ;
}
static int T_5 F_46 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
T_4 V_90 = F_33 ( V_123 , 0 ) ;
T_2 * V_5 ;
int V_7 , V_124 ;
T_6 V_125 = V_4 -> V_110 . V_111 ;
V_5 = F_47 ( V_45 , V_126 ) ;
if ( V_5 == NULL )
return - V_127 ;
F_31 ( V_4 , V_90 ) ;
F_38 ( V_4 , V_9 , V_5 , 0 , V_123 ) ;
if ( V_9 -> V_128 == NULL )
goto exit;
if ( V_4 -> V_110 . V_111 > V_125 ) {
V_125 = V_4 -> V_110 . V_111 ;
F_38 ( V_4 , V_9 , V_5 , 0 , V_129 ) ;
if ( V_4 -> V_110 . V_111 > V_125 ) {
F_12 ( V_15 -> V_19 ,
L_29 ) ;
goto exit;
}
}
for ( V_7 = V_124 = 0 ; V_124 < V_130 ; V_124 += 8 , V_7 ++ ) {
int V_131 ;
unsigned long V_132 = ~ V_5 [ V_7 ] ;
F_19 (bitnum, &bits, 8 ) {
int V_133 = V_124 + 7 - V_131 ;
V_9 -> V_128 [ V_133 / 4 ] |=
0x03 << ( ( V_133 % 4 ) * 2 ) ;
V_4 -> V_110 . V_134 ++ ;
F_24 ( V_15 -> V_19 , L_30 ,
V_133 ) ;
}
}
exit:
F_48 ( V_5 ) ;
return 0 ;
}
static int F_49 ( struct V_3 * V_4 , T_7 V_135 )
{
int V_136 , V_7 ;
T_2 * V_5 ;
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
struct V_137 * V_138 = V_9 -> V_139 ;
int V_124 = ( int ) ( V_135 >> V_9 -> V_140 ) ;
int V_36 = ( int ) ( V_135 >> V_9 -> V_141 ) ;
T_4 V_90 = F_33 ( V_36 , 0 ) ;
F_7 ( V_15 -> V_19 , L_31 , V_20 , V_135 ) ;
if ( F_11 ( V_135 & ( V_142 - 1 ) ) )
F_12 ( V_15 -> V_19 , L_32 ,
V_20 , V_135 ) ;
V_5 = F_47 ( V_45 , V_126 ) ;
if ( V_5 == NULL )
return - V_127 ;
V_9 -> V_128 [ V_124 / 4 ] |= 0x01 << ( ( V_124 & 0x03 ) * 2 ) ;
memset ( V_9 -> V_41 , 0xff , V_4 -> V_143 ) ;
for ( V_7 = 0 ; V_7 < V_138 -> V_6 ; V_7 ++ )
V_9 -> V_41 [ V_138 -> V_144 + V_7 ] = ~ V_138 -> V_145 [ V_7 ] ;
F_32 ( V_4 , V_90 ) ;
F_44 ( V_4 , V_9 , V_5 , 1 ) ;
V_136 = F_29 ( V_4 ) ;
if ( ! V_136 )
V_4 -> V_110 . V_134 ++ ;
F_48 ( V_5 ) ;
return V_136 ;
}
static int F_50 ( struct V_3 * V_4 , T_7 V_135 , int V_146 )
{
return 0 ;
}
static int F_51 ( struct V_147 * V_148 , T_8 V_149 )
{
int V_7 ;
T_2 V_150 ;
struct V_14 * V_15 = F_52 ( V_148 ) ;
void T_1 * V_1 = V_15 -> V_18 ;
F_7 ( V_15 -> V_19 , L_1 , V_20 ) ;
for ( V_7 = 0 ; V_7 < 10 ; V_7 ++ ) {
V_150 = F_9 ( V_1 + V_151 ) ;
if ( V_150 & V_152 )
break;
F_41 ( 1000 , 4000 ) ;
}
if ( V_150 & V_152 ) {
F_10 ( V_15 -> V_19 , L_33
L_34 ) ;
return - V_62 ;
}
F_2 ( V_153 | V_29 ,
V_1 + V_30 ) ;
F_2 ( ~ ( V_153 | V_29 ) ,
V_1 + V_31 ) ;
F_1 ( V_1 ) ;
return 0 ;
}
static int F_53 ( struct V_147 * V_148 )
{
struct V_14 * V_15 = F_52 ( V_148 ) ;
void T_1 * V_1 = V_15 -> V_18 ;
int V_7 ;
F_7 ( V_15 -> V_19 , L_1 , V_20 ) ;
for ( V_7 = 0 ; V_7 < 12 ; V_7 ++ )
F_9 ( V_1 + 0x1fff ) ;
return 0 ;
}
static void T_5 F_54 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
V_4 -> V_115 = V_154 ;
V_4 -> V_155 = L_35 ;
V_4 -> V_156 = V_45 ;
V_4 -> V_157 = V_142 ;
V_4 -> V_143 = V_116 ;
V_9 -> V_158 = V_154 ;
V_9 -> V_159 = V_160 ;
V_9 -> V_140 = V_9 -> V_161 = V_162 ;
V_9 -> V_163 = 20 ;
V_9 -> V_141 = V_164 ;
V_9 -> V_165 = 0x3ffff ;
V_9 -> V_166 = V_167 ;
V_9 -> V_168 = 8 ;
V_9 -> V_114 . V_169 = & V_170 ;
V_9 -> V_114 . V_171 = V_172 ;
V_9 -> V_114 . V_115 = V_45 ;
V_9 -> V_114 . V_173 = 8 ;
V_9 -> V_114 . V_174 = 8 ;
V_9 -> V_114 . V_175 = V_176 ;
V_9 -> V_177 = V_178 | V_179 ;
V_9 -> V_12 = V_9 -> V_13 = V_15 -> V_18 + V_56 ;
V_9 -> V_180 = & V_9 -> V_181 ;
F_55 ( & V_9 -> V_180 -> V_182 ) ;
F_56 ( & V_9 -> V_180 -> V_183 ) ;
V_9 -> V_184 = F_34 ;
V_9 -> V_185 = F_13 ;
V_9 -> V_186 = F_14 ;
V_9 -> V_187 = F_25 ;
V_9 -> V_188 = F_49 ;
V_9 -> V_189 = F_3 ;
V_9 -> V_190 = F_5 ;
V_9 -> V_191 = V_192 ;
V_9 -> V_193 = F_40 ;
V_9 -> V_114 . F_35 = F_38 ;
V_9 -> V_114 . F_42 = F_44 ;
V_9 -> V_114 . V_194 = F_37 ;
V_9 -> V_114 . V_195 = F_43 ;
V_9 -> V_114 . V_196 = F_39 ;
V_9 -> V_114 . V_197 = F_45 ;
if ( V_40 ) {
V_9 -> V_177 |= V_198 ;
V_9 -> V_199 = F_50 ;
}
}
static int T_5 F_57 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
T_3 V_200 , V_201 ;
V_200 = F_4 ( V_1 + V_202 ) ;
V_200 = F_4 ( V_1 + V_59 ) ;
V_201 = F_4 ( V_1 + V_203 ) ;
V_201 = F_4 ( V_1 + V_59 ) ;
if ( V_200 == V_204 && V_201 == V_205 ) {
F_58 ( V_15 -> V_19 ,
L_36 ) ;
return 0 ;
}
return - V_206 ;
}
static int T_5 F_59 ( struct V_147 * V_148 )
{
struct V_3 * V_4 ;
struct V_8 * V_9 ;
void T_1 * V_18 ;
struct V_14 * V_15 ;
int V_6 , V_63 ;
struct V_207 * V_208 ;
struct V_209 * V_19 = & V_148 -> V_19 ;
V_208 = F_60 ( V_148 , V_210 , 0 ) ;
if ( V_208 == NULL ) {
F_10 ( V_19 , L_37 ) ;
return - V_206 ;
}
V_18 = F_61 ( V_208 -> V_211 , F_62 ( V_208 ) ) ;
if ( ! V_18 ) {
F_10 ( V_19 , L_38 , V_208 ) ;
return - V_62 ;
}
V_6 = sizeof( struct V_3 ) + sizeof( struct V_8 ) +
sizeof( struct V_14 ) ;
V_4 = F_47 ( V_6 , V_126 ) ;
if ( V_4 == NULL ) {
V_63 = - V_127 ;
goto V_212;
}
V_9 = (struct V_8 * ) ( V_4 + 1 ) ;
V_15 = (struct V_14 * ) ( V_9 + 1 ) ;
V_4 -> V_10 = V_9 ;
V_9 -> V_10 = V_15 ;
V_4 -> V_213 = V_214 ;
V_15 -> V_18 = V_18 ;
V_15 -> V_19 = V_19 ;
F_54 ( V_4 ) ;
V_15 -> V_46 = F_63 ( V_215 , V_176 , V_216 ) ;
if ( V_15 -> V_46 == NULL ) {
V_63 = - V_217 ;
goto V_212;
}
F_64 ( V_148 , V_15 ) ;
F_15 ( V_4 ) ;
V_63 = F_57 ( V_4 ) ;
if ( V_63 == - V_206 ) {
F_12 ( V_19 , L_39 ) ;
goto V_212;
}
V_63 = F_65 ( V_4 ) ;
if ( V_63 )
goto V_212;
V_63 = F_46 ( V_4 ) ;
if ( V_63 )
goto V_212;
V_63 = F_66 ( V_4 , V_218 , NULL , NULL , 0 ) ;
if ( V_63 )
goto V_212;
V_15 -> V_4 = V_4 ;
return 0 ;
V_212:
F_67 ( V_18 ) ;
if ( V_4 ) {
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
F_68 ( V_4 ) ;
F_64 ( V_148 , NULL ) ;
F_69 ( V_15 -> V_46 ) ;
F_48 ( V_4 ) ;
}
return V_63 ;
}
static int T_9 F_70 ( struct V_147 * V_148 )
{
struct V_14 * V_15 = F_52 ( V_148 ) ;
F_68 ( V_15 -> V_4 ) ;
F_64 ( V_148 , NULL ) ;
F_69 ( V_15 -> V_46 ) ;
F_48 ( V_15 -> V_4 ) ;
F_67 ( V_15 -> V_18 ) ;
return 0 ;
}
