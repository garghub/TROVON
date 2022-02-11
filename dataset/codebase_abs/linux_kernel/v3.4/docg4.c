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
if ( V_15 -> V_41 [ 15 ] ) {
int V_42 , V_43 = 0 ;
unsigned long V_44 = V_15 -> V_41 [ 15 ] ;
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
( unsigned long * ) V_15 -> V_41 ) ;
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
F_2 ( V_80 , V_1 + V_65 ) ;
F_2 ( V_81 , V_1 + V_67 ) ;
F_1 ( V_1 ) ;
F_26 ( V_15 , V_53 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_6 ( V_15 ) ;
}
static T_4 F_33 ( int V_36 , int V_82 )
{
int V_83 = V_36 / 4 ;
int V_84 = ( V_36 % 4 ) * 0x108 + V_82 / 2 ;
return ( V_83 << 16 ) | V_84 ;
}
static void F_34 ( struct V_3 * V_4 , unsigned V_50 , int V_82 ,
int V_85 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
T_4 V_86 = F_33 ( V_85 , V_82 ) ;
F_7 ( V_15 -> V_19 , L_18 ,
V_20 , V_50 , V_85 , V_82 ) ;
V_15 -> V_49 . V_50 = V_50 ;
V_15 -> V_49 . V_82 = V_82 ;
V_15 -> V_49 . V_36 = V_85 ;
switch ( V_50 ) {
case V_87 :
F_15 ( V_4 ) ;
break;
case V_88 :
F_31 ( V_4 , V_86 ) ;
break;
case V_51 :
break;
case V_89 :
F_32 ( V_4 , V_86 ) ;
if ( V_15 -> V_90 == V_85 )
memcpy ( V_9 -> V_91 , V_15 -> V_41 , 16 ) ;
break;
case V_92 :
F_29 ( V_4 ) ;
break;
case V_93 :
case V_94 :
case V_95 :
case V_96 :
F_12 ( V_15 -> V_19 , L_19
L_20 , V_50 ) ;
break;
}
}
static int F_35 ( struct V_3 * V_4 , struct V_8 * V_9 ,
T_2 * V_5 , int V_36 , bool V_97 )
{
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
T_3 V_24 , V_98 , * V_99 ;
F_7 ( V_15 -> V_19 , L_21 , V_20 , V_36 ) ;
F_2 ( V_70 |
V_100 |
V_101 |
V_102 ,
V_1 + V_71 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
V_24 = F_4 ( V_1 + V_56 ) ;
if ( V_24 & V_103 ) {
F_10 ( V_15 -> V_19 ,
L_22 , V_24 ) ;
F_2 ( 0 , V_1 + V_72 ) ;
return - V_62 ;
}
F_7 ( V_15 -> V_19 , L_23 , V_20 , V_24 ) ;
F_3 ( V_4 , V_5 , V_45 ) ;
F_3 ( V_4 , V_15 -> V_41 , 14 ) ;
V_99 = ( T_3 * ) ( V_15 -> V_41 + 14 ) ;
* V_99 = F_4 ( V_1 + V_59 ) ;
F_1 ( V_1 ) ;
if ( F_36 ( V_97 == true ) ) {
V_98 = F_4 ( V_1 + V_34 ) ;
V_98 = F_4 ( V_1 + V_34 ) ;
F_7 ( V_15 -> V_19 , L_24 , V_20 , V_98 ) ;
if ( V_98 & V_104 ) {
int V_105 = F_18 ( V_4 , V_5 , V_36 ) ;
if ( V_105 == - V_48 )
V_4 -> V_106 . V_107 ++ ;
else
V_4 -> V_106 . V_108 += V_105 ;
}
}
F_2 ( 0 , V_1 + V_72 ) ;
return 0 ;
}
static int F_37 ( struct V_3 * V_4 , struct V_8 * V_9 ,
T_2 * V_5 , int V_36 )
{
return F_35 ( V_4 , V_9 , V_5 , V_36 , false ) ;
}
static int F_38 ( struct V_3 * V_4 , struct V_8 * V_9 ,
T_2 * V_5 , int V_36 )
{
return F_35 ( V_4 , V_9 , V_5 , V_36 , true ) ;
}
static int F_39 ( struct V_3 * V_4 , struct V_8 * V_9 ,
int V_36 , int V_109 )
{
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
T_3 V_24 ;
F_7 ( V_15 -> V_19 , L_25 , V_20 , V_36 ) ;
if ( V_15 -> V_49 . V_50 == V_88 &&
V_15 -> V_49 . V_36 == V_36 ) {
memcpy ( V_9 -> V_91 , V_15 -> V_41 , 16 ) ;
return 0 ;
}
F_34 ( V_4 , V_88 , V_9 -> V_110 . V_111 , V_36 ) ;
F_2 ( V_70 | V_112 , V_1 + V_71 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
V_24 = F_4 ( V_1 + V_56 ) ;
if ( V_24 & V_103 ) {
F_12 ( V_15 -> V_19 ,
L_26 , V_24 ) ;
return - V_62 ;
}
F_7 ( V_15 -> V_19 , L_23 , V_20 , V_24 ) ;
F_3 ( V_4 , V_9 -> V_91 , 16 ) ;
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
T_3 V_83 ;
F_7 ( V_15 -> V_19 , L_27 , V_20 , V_36 ) ;
F_30 ( V_4 ) ;
F_2 ( V_113 , V_1 + V_65 ) ;
F_2 ( V_114 , V_1 + V_67 ) ;
F_1 ( V_1 ) ;
V_83 = ( T_3 ) ( V_36 / 4 ) ;
F_27 ( V_83 & 0xff , V_1 + V_54 ) ;
V_83 >>= 8 ;
F_27 ( V_83 & 0xff , V_1 + V_54 ) ;
F_1 ( V_1 ) ;
F_2 ( V_115 , V_1 + V_67 ) ;
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
static void F_42 ( struct V_3 * V_4 , struct V_8 * V_9 ,
const T_2 * V_5 , bool V_97 )
{
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
T_2 V_35 [ 8 ] ;
F_7 ( V_15 -> V_19 , L_1 , V_20 ) ;
F_2 ( V_100 |
V_101 |
V_102 ,
V_1 + V_71 ) ;
F_1 ( V_1 ) ;
F_5 ( V_4 , V_5 , V_45 ) ;
F_5 ( V_4 , V_9 -> V_91 , 6 ) ;
F_2 ( V_9 -> V_91 [ 6 ] , V_1 + V_116 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
if ( F_36 ( V_97 == true ) ) {
T_2 V_117 = F_9 ( V_1 + V_118 ) ;
V_117 = F_9 ( V_1 + V_118 ) ;
F_2 ( V_117 , V_1 + V_116 ) ;
F_1 ( V_1 ) ;
F_16 ( V_1 , V_35 ) ;
V_35 [ 7 ] = 0 ;
}
else {
F_2 ( V_9 -> V_91 [ 7 ] , V_1 + V_116 ) ;
F_1 ( V_1 ) ;
memcpy ( V_35 , & V_9 -> V_91 [ 8 ] , 8 ) ;
}
F_5 ( V_4 , V_35 , 8 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_2 ( 0 , V_1 + V_72 ) ;
F_1 ( V_1 ) ;
}
static void F_43 ( struct V_3 * V_4 , struct V_8 * V_9 ,
const T_2 * V_5 )
{
return F_42 ( V_4 , V_9 , V_5 , false ) ;
}
static void F_44 ( struct V_3 * V_4 , struct V_8 * V_9 ,
const T_2 * V_5 )
{
return F_42 ( V_4 , V_9 , V_5 , true ) ;
}
static int F_45 ( struct V_3 * V_4 , struct V_8 * V_9 ,
int V_36 )
{
struct V_14 * V_15 = V_9 -> V_10 ;
V_15 -> V_90 = V_36 ;
memcpy ( V_15 -> V_41 , V_9 -> V_91 , 16 ) ;
return 0 ;
}
static int T_5 F_46 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
T_4 V_86 = F_33 ( V_119 , 0 ) ;
T_2 * V_5 ;
int V_7 , V_120 , V_24 ;
V_5 = F_47 ( V_45 , V_121 ) ;
if ( V_5 == NULL )
return - V_122 ;
F_31 ( V_4 , V_86 ) ;
V_24 = F_38 ( V_4 , V_9 , V_5 , V_119 ) ;
if ( V_24 )
goto exit;
if ( V_9 -> V_123 == NULL )
goto exit;
for ( V_7 = V_120 = 0 ; V_120 < V_124 ; V_120 += 8 , V_7 ++ ) {
int V_125 ;
unsigned long V_126 = ~ V_5 [ V_7 ] ;
F_19 (bitnum, &bits, 8 ) {
int V_127 = V_120 + 7 - V_125 ;
V_9 -> V_123 [ V_127 / 4 ] |=
0x03 << ( ( V_127 % 4 ) * 2 ) ;
V_4 -> V_106 . V_128 ++ ;
F_24 ( V_15 -> V_19 , L_28 ,
V_127 ) ;
}
}
exit:
F_48 ( V_5 ) ;
return V_24 ;
}
static int F_49 ( struct V_3 * V_4 , T_6 V_129 )
{
int V_130 , V_7 ;
T_2 * V_5 ;
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
struct V_131 * V_132 = V_9 -> V_133 ;
int V_120 = ( int ) ( V_129 >> V_9 -> V_134 ) ;
int V_36 = ( int ) ( V_129 >> V_9 -> V_135 ) ;
T_4 V_86 = F_33 ( V_36 , 0 ) ;
F_7 ( V_15 -> V_19 , L_29 , V_20 , V_129 ) ;
if ( F_11 ( V_129 & ( V_136 - 1 ) ) )
F_12 ( V_15 -> V_19 , L_30 ,
V_20 , V_129 ) ;
V_5 = F_47 ( V_45 , V_121 ) ;
if ( V_5 == NULL )
return - V_122 ;
V_9 -> V_123 [ V_120 / 4 ] |= 0x01 << ( ( V_120 & 0x03 ) * 2 ) ;
memset ( V_9 -> V_91 , 0xff , V_4 -> V_137 ) ;
for ( V_7 = 0 ; V_7 < V_132 -> V_6 ; V_7 ++ )
V_9 -> V_91 [ V_132 -> V_138 + V_7 ] = ~ V_132 -> V_139 [ V_7 ] ;
F_32 ( V_4 , V_86 ) ;
F_44 ( V_4 , V_9 , V_5 ) ;
V_130 = F_29 ( V_4 ) ;
if ( ! V_130 )
V_4 -> V_106 . V_128 ++ ;
F_48 ( V_5 ) ;
return V_130 ;
}
static int F_50 ( struct V_3 * V_4 , T_6 V_129 , int V_140 )
{
return 0 ;
}
static int F_51 ( struct V_141 * V_142 , T_7 V_143 )
{
int V_7 ;
T_2 V_144 ;
struct V_14 * V_15 = F_52 ( V_142 ) ;
void T_1 * V_1 = V_15 -> V_18 ;
F_7 ( V_15 -> V_19 , L_1 , V_20 ) ;
for ( V_7 = 0 ; V_7 < 10 ; V_7 ++ ) {
V_144 = F_9 ( V_1 + V_145 ) ;
if ( V_144 & V_146 )
break;
F_41 ( 1000 , 4000 ) ;
}
if ( V_144 & V_146 ) {
F_10 ( V_15 -> V_19 , L_31
L_32 ) ;
return - V_62 ;
}
F_2 ( V_147 | V_29 ,
V_1 + V_30 ) ;
F_2 ( ~ ( V_147 | V_29 ) ,
V_1 + V_31 ) ;
F_1 ( V_1 ) ;
return 0 ;
}
static int F_53 ( struct V_141 * V_142 )
{
struct V_14 * V_15 = F_52 ( V_142 ) ;
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
V_4 -> V_111 = V_148 ;
V_4 -> V_149 = L_33 ;
V_4 -> V_150 = V_45 ;
V_4 -> V_151 = V_136 ;
V_4 -> V_137 = V_112 ;
V_9 -> V_152 = V_148 ;
V_9 -> V_153 = V_154 ;
V_9 -> V_134 = V_9 -> V_155 = V_156 ;
V_9 -> V_157 = 20 ;
V_9 -> V_135 = V_158 ;
V_9 -> V_159 = 0x3ffff ;
V_9 -> V_160 = V_161 ;
V_9 -> V_162 = 8 ;
V_9 -> V_110 . V_163 = & V_164 ;
V_9 -> V_110 . V_165 = V_166 ;
V_9 -> V_110 . V_111 = V_45 ;
V_9 -> V_110 . V_167 = 8 ;
V_9 -> V_110 . V_168 = 8 ;
V_9 -> V_110 . V_169 = V_170 ;
V_9 -> V_171 =
V_172 | V_173 | V_174 ;
V_9 -> V_12 = V_9 -> V_13 = V_15 -> V_18 + V_56 ;
V_9 -> V_175 = & V_9 -> V_176 ;
F_55 ( & V_9 -> V_175 -> V_177 ) ;
F_56 ( & V_9 -> V_175 -> V_178 ) ;
V_9 -> V_179 = F_34 ;
V_9 -> V_180 = F_13 ;
V_9 -> V_181 = F_14 ;
V_9 -> V_182 = F_25 ;
V_9 -> V_183 = F_49 ;
V_9 -> V_184 = F_3 ;
V_9 -> V_185 = F_5 ;
V_9 -> V_186 = V_187 ;
V_9 -> V_188 = F_40 ;
V_9 -> V_110 . F_35 = F_38 ;
V_9 -> V_110 . F_42 = F_44 ;
V_9 -> V_110 . V_189 = F_37 ;
V_9 -> V_110 . V_190 = F_43 ;
V_9 -> V_110 . V_191 = F_39 ;
V_9 -> V_110 . V_192 = F_45 ;
if ( V_40 ) {
V_9 -> V_171 |= V_193 ;
V_9 -> V_194 = F_50 ;
}
}
static int T_5 F_57 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
T_3 V_195 , V_196 ;
V_195 = F_4 ( V_1 + V_197 ) ;
V_195 = F_4 ( V_1 + V_59 ) ;
V_196 = F_4 ( V_1 + V_198 ) ;
V_196 = F_4 ( V_1 + V_59 ) ;
if ( V_195 == V_199 && V_196 == V_200 ) {
F_58 ( V_15 -> V_19 ,
L_34 ) ;
return 0 ;
}
return - V_201 ;
}
static int T_5 F_59 ( struct V_141 * V_142 )
{
struct V_3 * V_4 ;
struct V_8 * V_9 ;
void T_1 * V_18 ;
struct V_14 * V_15 ;
int V_6 , V_63 ;
struct V_202 * V_203 ;
struct V_204 * V_19 = & V_142 -> V_19 ;
V_203 = F_60 ( V_142 , V_205 , 0 ) ;
if ( V_203 == NULL ) {
F_10 ( V_19 , L_35 ) ;
return - V_201 ;
}
V_18 = F_61 ( V_203 -> V_206 , F_62 ( V_203 ) ) ;
if ( ! V_18 ) {
F_10 ( V_19 , L_36 , V_203 ) ;
return - V_62 ;
}
V_6 = sizeof( struct V_3 ) + sizeof( struct V_8 ) +
sizeof( struct V_14 ) ;
V_4 = F_47 ( V_6 , V_121 ) ;
if ( V_4 == NULL ) {
V_63 = - V_122 ;
goto V_207;
}
V_9 = (struct V_8 * ) ( V_4 + 1 ) ;
V_15 = (struct V_14 * ) ( V_9 + 1 ) ;
V_4 -> V_10 = V_9 ;
V_9 -> V_10 = V_15 ;
V_4 -> V_208 = V_209 ;
V_15 -> V_18 = V_18 ;
V_15 -> V_19 = V_19 ;
F_54 ( V_4 ) ;
V_15 -> V_46 = F_63 ( V_210 , V_170 , V_211 ) ;
if ( V_15 -> V_46 == NULL ) {
V_63 = - V_212 ;
goto V_207;
}
F_64 ( V_142 , V_15 ) ;
F_15 ( V_4 ) ;
V_63 = F_57 ( V_4 ) ;
if ( V_63 == - V_201 ) {
F_12 ( V_19 , L_37 ) ;
goto V_207;
}
V_63 = F_65 ( V_4 ) ;
if ( V_63 )
goto V_207;
V_63 = F_46 ( V_4 ) ;
if ( V_63 )
goto V_207;
V_63 = F_66 ( V_4 , V_213 , NULL , NULL , 0 ) ;
if ( V_63 )
goto V_207;
V_15 -> V_4 = V_4 ;
return 0 ;
V_207:
F_67 ( V_18 ) ;
if ( V_4 ) {
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
F_68 ( V_4 ) ;
F_64 ( V_142 , NULL ) ;
F_69 ( V_15 -> V_46 ) ;
F_48 ( V_4 ) ;
}
return V_63 ;
}
static int T_8 F_70 ( struct V_141 * V_142 )
{
struct V_14 * V_15 = F_52 ( V_142 ) ;
F_68 ( V_15 -> V_4 ) ;
F_64 ( V_142 , NULL ) ;
F_69 ( V_15 -> V_46 ) ;
F_48 ( V_15 -> V_4 ) ;
F_67 ( V_15 -> V_18 ) ;
return 0 ;
}
static int T_5 F_71 ( void )
{
return F_72 ( & V_214 , F_59 ) ;
}
static void T_8 F_73 ( void )
{
F_74 ( & V_214 ) ;
}
