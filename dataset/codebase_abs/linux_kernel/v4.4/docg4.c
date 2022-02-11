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
unsigned long V_17 ;
void T_1 * V_1 = V_15 -> V_18 ;
F_7 ( V_15 -> V_19 , L_1 , V_20 ) ;
V_16 = F_4 ( V_1 + V_21 ) ;
V_17 = V_22 + F_8 ( 200 ) ;
do {
F_9 () ;
V_16 = F_10 ( V_1 + V_21 ) ;
} while ( ! ( V_16 & V_23 ) &&
F_11 ( V_22 , V_17 ) );
if ( F_12 ( ! ( V_16 & V_23 ) ) ) {
F_13 ( V_15 -> V_19 , L_2 , V_20 ) ;
return V_24 ;
}
return 0 ;
}
static int F_14 ( struct V_3 * V_4 , struct V_8 * V_9 )
{
struct V_14 * V_15 = V_9 -> V_10 ;
int V_25 = V_26 ;
F_7 ( V_15 -> V_19 , L_1 , V_20 ) ;
if ( V_15 -> V_25 ) {
V_25 |= V_15 -> V_25 ;
V_15 -> V_25 = 0 ;
return V_25 ;
}
V_25 |= F_6 ( V_15 ) ;
return V_25 ;
}
static void F_15 ( struct V_3 * V_4 , int V_27 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
F_7 ( V_15 -> V_19 , L_3 , V_20 , V_27 ) ;
if ( V_27 < 0 )
return;
if ( V_27 > 0 )
F_16 ( V_15 -> V_19 , L_4 ) ;
F_2 ( 0 , V_1 + V_28 ) ;
}
static void F_17 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
F_2 ( V_29 | V_30 ,
V_1 + V_31 ) ;
F_2 ( ~ ( V_29 | V_30 ) ,
V_1 + V_32 ) ;
F_1 ( V_1 ) ;
F_2 ( V_33 | V_30 ,
V_1 + V_31 ) ;
F_2 ( ~ ( V_33 | V_30 ) ,
V_1 + V_32 ) ;
F_2 ( V_34 , V_1 + V_35 ) ;
F_6 ( V_15 ) ;
}
static void F_18 ( void T_1 * V_1 , T_2 * V_36 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < 7 ; V_7 ++ ) {
V_36 [ V_7 ] = F_10 ( V_1 + F_19 ( V_7 ) ) ;
V_36 [ V_7 ] = F_10 ( V_1 + F_19 ( V_7 ) ) ;
}
}
static int F_20 ( struct V_3 * V_4 , T_2 * V_5 , int V_37 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
int V_7 , V_38 , V_39 [ 4 ] ;
const T_2 V_40 [ 8 ] = {
0xcf , 0x72 , 0xfc , 0x1b , 0xa9 , 0xc7 , 0xb9 , 0 } ;
F_18 ( V_1 , V_15 -> V_36 ) ;
if ( ! memcmp ( V_15 -> V_36 , V_40 , 7 ) )
return 0 ;
if ( V_41 == false ) {
if ( V_9 -> V_42 [ 15 ] ) {
int V_43 , V_44 = 0 ;
unsigned long V_45 = V_9 -> V_42 [ 15 ] ;
F_21 (bit, &written_flag, 8 )
V_44 ++ ;
if ( V_44 > 4 ) {
F_16 ( V_15 -> V_19 ,
L_5
L_6 ,
V_37 * V_46 ) ;
return 0 ;
}
}
}
for ( V_7 = 0 ; V_7 < 7 ; V_7 ++ )
V_15 -> V_36 [ V_7 ] = F_22 ( V_15 -> V_36 [ V_7 ] ) ;
V_38 = F_23 ( V_15 -> V_47 , NULL , V_48 , NULL ,
V_15 -> V_36 , NULL , V_39 ) ;
if ( V_38 == - V_49 ) {
F_16 ( V_15 -> V_19 , L_7 ,
V_37 * V_46 ) ;
return - V_49 ;
}
F_24 ( V_38 < 0 ) ;
for ( V_7 = 0 ; V_7 < V_38 ; V_7 ++ )
V_39 [ V_7 ] = ( V_39 [ V_7 ] & ~ 7 ) | ( 7 - ( V_39 [ V_7 ] & 7 ) ) ;
for ( V_7 = 0 ; V_7 < V_38 ; V_7 ++ ) {
if ( V_39 [ V_7 ] > V_48 * 8 )
continue;
if ( V_39 [ V_7 ] > V_46 * 8 )
F_25 ( V_39 [ V_7 ] - V_46 * 8 ,
( unsigned long * ) V_9 -> V_42 ) ;
else
F_25 ( V_39 [ V_7 ] , ( unsigned long * ) V_5 ) ;
}
F_26 ( V_15 -> V_19 , L_8 ,
V_38 , V_37 * V_46 ) ;
return V_38 ;
}
static T_2 F_27 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
F_7 ( V_15 -> V_19 , L_9 , V_20 ) ;
if ( V_15 -> V_50 . V_51 == V_52 ) {
int V_25 ;
V_15 -> V_50 . V_51 = 0 ;
if ( V_15 -> V_25 ) {
V_25 = V_15 -> V_25 ;
V_15 -> V_25 = 0 ;
}
else
V_25 = V_26 | V_53 ;
return V_25 ;
}
F_16 ( V_15 -> V_19 , L_10 ) ;
return 0 ;
}
static void F_28 ( struct V_14 * V_15 , T_4 V_54 )
{
void T_1 * V_1 = V_15 -> V_18 ;
F_29 ( V_54 & 0xff , V_1 + V_55 ) ;
V_54 >>= 8 ;
F_29 ( V_54 & 0xff , V_1 + V_55 ) ;
V_54 >>= 8 ;
F_29 ( V_54 & 0xff , V_1 + V_55 ) ;
V_54 >>= 8 ;
F_29 ( V_54 & 0xff , V_1 + V_55 ) ;
}
static int F_30 ( struct V_14 * V_15 )
{
void T_1 * V_1 = V_15 -> V_18 ;
T_3 V_56 = F_4 ( V_1 + V_57 ) ;
T_3 V_58 = F_4 ( V_1 + V_57 ) ;
T_3 V_59 = F_4 ( V_1 + V_60 ) ;
F_7 ( V_15 -> V_19 , L_11 ,
V_20 , V_56 , V_58 , V_59 ) ;
if ( V_56 != V_61
|| V_58 != V_62
|| V_59 != V_62 ) {
V_15 -> V_25 = V_24 ;
F_16 ( V_15 -> V_19 , L_12
L_13 , V_56 , V_58 , V_59 ) ;
return - V_63 ;
}
return 0 ;
}
static int F_31 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
int V_64 = 0 ;
F_7 ( V_15 -> V_19 , L_14 , V_20 ) ;
F_2 ( V_65 , V_1 + V_66 ) ;
F_2 ( V_67 , V_1 + V_68 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_6 ( V_15 ) ;
F_2 ( V_69 , V_1 + V_66 ) ;
F_2 ( V_70 , V_1 + V_68 ) ;
F_2 ( V_71 | 4 , V_1 + V_72 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
V_64 = F_30 ( V_15 ) ;
F_2 ( 0 , V_1 + V_73 ) ;
F_1 ( V_1 ) ;
F_6 ( V_15 ) ;
F_1 ( V_1 ) ;
return V_64 ;
}
static void F_32 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
F_2 ( V_74 | V_75 , V_1 + V_21 ) ;
F_2 ( V_76 , V_1 + V_66 ) ;
F_2 ( V_77 , V_1 + V_68 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_6 ( V_15 ) ;
F_1 ( V_1 ) ;
}
static void F_33 ( struct V_3 * V_4 , T_4 V_54 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
F_7 ( V_15 -> V_19 ,
L_15 , V_20 , V_54 ) ;
F_32 ( V_4 ) ;
F_2 ( V_78 , V_1 + V_66 ) ;
F_2 ( V_79 , V_1 + V_68 ) ;
F_1 ( V_1 ) ;
F_28 ( V_15 , V_54 ) ;
F_1 ( V_1 ) ;
F_2 ( V_80 , V_1 + V_68 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_6 ( V_15 ) ;
}
static void F_34 ( struct V_3 * V_4 , T_4 V_54 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
F_7 ( V_15 -> V_19 ,
L_16 , V_20 , V_54 ) ;
F_32 ( V_4 ) ;
if ( F_12 ( V_81 ) ) {
F_2 ( V_82 , V_1 + V_66 ) ;
F_2 ( V_83 , V_1 + V_68 ) ;
F_2 ( V_84 , V_1 + V_68 ) ;
F_1 ( V_1 ) ;
}
F_2 ( V_85 , V_1 + V_66 ) ;
F_2 ( V_86 , V_1 + V_68 ) ;
F_1 ( V_1 ) ;
F_28 ( V_15 , V_54 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_6 ( V_15 ) ;
}
static T_4 F_35 ( int V_37 , int V_87 )
{
int V_88 = V_37 / 4 ;
int V_89 = ( V_37 % 4 ) * 0x108 + V_87 / 2 ;
return ( V_88 << 16 ) | V_89 ;
}
static void F_36 ( struct V_3 * V_4 , unsigned V_51 , int V_87 ,
int V_90 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
T_4 V_91 = F_35 ( V_90 , V_87 ) ;
F_7 ( V_15 -> V_19 , L_17 ,
V_20 , V_51 , V_90 , V_87 ) ;
V_15 -> V_50 . V_51 = V_51 ;
V_15 -> V_50 . V_87 = V_87 ;
V_15 -> V_50 . V_37 = V_90 ;
switch ( V_51 ) {
case V_92 :
F_17 ( V_4 ) ;
break;
case V_93 :
F_33 ( V_4 , V_91 ) ;
break;
case V_52 :
break;
case V_94 :
if ( F_12 ( V_81 ) ) {
T_3 V_88 = V_91 >> 16 ;
if ( V_88 & 0x01 )
F_16 ( V_15 -> V_19 ,
L_18 ) ;
}
F_34 ( V_4 , V_91 ) ;
if ( V_15 -> V_95 == V_90 )
memcpy ( V_9 -> V_42 , V_15 -> V_96 , 16 ) ;
break;
case V_97 :
F_31 ( V_4 ) ;
break;
case V_98 :
case V_99 :
case V_100 :
case V_101 :
F_16 ( V_15 -> V_19 , L_19
L_20 , V_51 ) ;
break;
}
}
static int F_37 ( struct V_3 * V_4 , struct V_8 * V_9 ,
T_2 * V_5 , int V_37 , bool V_102 )
{
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
T_3 V_25 , V_103 , * V_104 ;
int V_105 = 0 ;
F_7 ( V_15 -> V_19 , L_21 , V_20 , V_37 ) ;
F_2 ( V_71 |
V_106 |
V_107 |
V_108 ,
V_1 + V_72 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
V_25 = F_4 ( V_1 + V_57 ) ;
if ( V_25 & V_109 ) {
F_13 ( V_15 -> V_19 ,
L_22 , V_25 ) ;
F_2 ( 0 , V_1 + V_73 ) ;
return - V_63 ;
}
F_7 ( V_15 -> V_19 , L_23 , V_20 , V_25 ) ;
F_3 ( V_4 , V_5 , V_46 ) ;
F_3 ( V_4 , V_9 -> V_42 , 14 ) ;
V_104 = ( T_3 * ) ( V_9 -> V_42 + 14 ) ;
* V_104 = F_4 ( V_1 + V_60 ) ;
F_1 ( V_1 ) ;
if ( F_38 ( V_102 == true ) ) {
V_103 = F_4 ( V_1 + V_35 ) ;
V_103 = F_4 ( V_1 + V_35 ) ;
F_7 ( V_15 -> V_19 , L_24 , V_20 , V_103 ) ;
if ( V_103 & V_110 ) {
V_105 = F_20 ( V_4 , V_5 , V_37 ) ;
if ( V_105 == - V_49 )
V_4 -> V_111 . V_112 ++ ;
else
V_4 -> V_111 . V_113 += V_105 ;
}
}
F_2 ( 0 , V_1 + V_73 ) ;
if ( V_105 == - V_49 )
return 0 ;
return V_105 ;
}
static int F_39 ( struct V_3 * V_4 , struct V_8 * V_9 ,
T_2 * V_5 , int V_114 , int V_37 )
{
return F_37 ( V_4 , V_9 , V_5 , V_37 , false ) ;
}
static int F_40 ( struct V_3 * V_4 , struct V_8 * V_9 ,
T_2 * V_5 , int V_114 , int V_37 )
{
return F_37 ( V_4 , V_9 , V_5 , V_37 , true ) ;
}
static int F_41 ( struct V_3 * V_4 , struct V_8 * V_9 ,
int V_37 )
{
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
T_3 V_25 ;
F_7 ( V_15 -> V_19 , L_25 , V_20 , V_37 ) ;
F_36 ( V_4 , V_93 , V_9 -> V_115 . V_116 , V_37 ) ;
F_2 ( V_71 | V_117 , V_1 + V_72 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
V_25 = F_4 ( V_1 + V_57 ) ;
if ( V_25 & V_109 ) {
F_16 ( V_15 -> V_19 ,
L_26 , V_25 ) ;
return - V_63 ;
}
F_7 ( V_15 -> V_19 , L_23 , V_20 , V_25 ) ;
F_3 ( V_4 , V_9 -> V_42 , 16 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_2 ( 0 , V_1 + V_73 ) ;
F_1 ( V_1 ) ;
return 0 ;
}
static int F_42 ( struct V_3 * V_4 , int V_37 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
T_3 V_88 ;
F_7 ( V_15 -> V_19 , L_27 , V_20 , V_37 ) ;
F_32 ( V_4 ) ;
F_2 ( V_118 , V_1 + V_66 ) ;
F_2 ( V_119 , V_1 + V_68 ) ;
F_1 ( V_1 ) ;
V_88 = ( T_3 ) ( V_37 / 4 ) ;
F_29 ( V_88 & 0xff , V_1 + V_55 ) ;
V_88 >>= 8 ;
F_29 ( V_88 & 0xff , V_1 + V_55 ) ;
F_1 ( V_1 ) ;
F_2 ( V_120 , V_1 + V_68 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_43 ( 500 , 1000 ) ;
F_6 ( V_15 ) ;
F_2 ( V_69 , V_1 + V_66 ) ;
F_2 ( V_70 , V_1 + V_68 ) ;
F_2 ( V_71 | 4 , V_1 + V_72 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_30 ( V_15 ) ;
F_2 ( 0 , V_1 + V_73 ) ;
F_1 ( V_1 ) ;
F_6 ( V_15 ) ;
F_1 ( V_1 ) ;
return V_9 -> V_121 ( V_4 , V_9 ) ;
}
static int F_44 ( struct V_3 * V_4 , struct V_8 * V_9 ,
const T_2 * V_5 , bool V_102 )
{
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
T_2 V_36 [ 8 ] ;
F_7 ( V_15 -> V_19 , L_1 , V_20 ) ;
F_2 ( V_106 |
V_107 |
V_108 ,
V_1 + V_72 ) ;
F_1 ( V_1 ) ;
F_5 ( V_4 , V_5 , V_46 ) ;
F_5 ( V_4 , V_9 -> V_42 , 6 ) ;
F_2 ( V_9 -> V_42 [ 6 ] , V_1 + V_122 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
if ( F_38 ( V_102 == true ) ) {
T_2 V_123 = F_10 ( V_1 + V_124 ) ;
V_123 = F_10 ( V_1 + V_124 ) ;
F_2 ( V_123 , V_1 + V_122 ) ;
F_1 ( V_1 ) ;
F_18 ( V_1 , V_36 ) ;
V_36 [ 7 ] = 0 ;
}
else {
F_2 ( V_9 -> V_42 [ 7 ] , V_1 + V_122 ) ;
F_1 ( V_1 ) ;
memcpy ( V_36 , & V_9 -> V_42 [ 8 ] , 8 ) ;
}
F_5 ( V_4 , V_36 , 8 ) ;
F_1 ( V_1 ) ;
F_1 ( V_1 ) ;
F_2 ( 0 , V_1 + V_73 ) ;
F_1 ( V_1 ) ;
return 0 ;
}
static int F_45 ( struct V_3 * V_4 , struct V_8 * V_9 ,
const T_2 * V_5 , int V_114 , int V_37 )
{
return F_44 ( V_4 , V_9 , V_5 , false ) ;
}
static int F_46 ( struct V_3 * V_4 , struct V_8 * V_9 ,
const T_2 * V_5 , int V_114 , int V_37 )
{
return F_44 ( V_4 , V_9 , V_5 , true ) ;
}
static int F_47 ( struct V_3 * V_4 , struct V_8 * V_9 ,
int V_37 )
{
struct V_14 * V_15 = V_9 -> V_10 ;
V_15 -> V_95 = V_37 ;
memcpy ( V_15 -> V_96 , V_9 -> V_42 , 16 ) ;
return 0 ;
}
static int T_5 F_48 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
T_4 V_91 = F_35 ( V_125 , 0 ) ;
T_2 * V_5 ;
int V_7 , V_126 ;
T_6 V_127 = V_4 -> V_111 . V_112 ;
V_5 = F_49 ( V_46 , V_128 ) ;
if ( V_5 == NULL )
return - V_129 ;
F_33 ( V_4 , V_91 ) ;
F_40 ( V_4 , V_9 , V_5 , 0 , V_125 ) ;
if ( V_9 -> V_130 == NULL )
goto exit;
if ( V_4 -> V_111 . V_112 > V_127 ) {
V_127 = V_4 -> V_111 . V_112 ;
F_40 ( V_4 , V_9 , V_5 , 0 , V_131 ) ;
if ( V_4 -> V_111 . V_112 > V_127 ) {
F_16 ( V_15 -> V_19 ,
L_28 ) ;
goto exit;
}
}
for ( V_7 = V_126 = 0 ; V_126 < V_132 ; V_126 += 8 , V_7 ++ ) {
int V_133 ;
unsigned long V_134 = ~ V_5 [ V_7 ] ;
F_21 (bitnum, &bits, 8 ) {
int V_135 = V_126 + 7 - V_133 ;
V_9 -> V_130 [ V_135 / 4 ] |=
0x03 << ( ( V_135 % 4 ) * 2 ) ;
V_4 -> V_111 . V_136 ++ ;
F_26 ( V_15 -> V_19 , L_29 ,
V_135 ) ;
}
}
exit:
F_50 ( V_5 ) ;
return 0 ;
}
static int F_51 ( struct V_3 * V_4 , T_7 V_137 )
{
int V_138 , V_7 ;
T_2 * V_5 ;
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
struct V_139 * V_140 = V_9 -> V_141 ;
int V_37 = ( int ) ( V_137 >> V_9 -> V_142 ) ;
T_4 V_91 = F_35 ( V_37 , 0 ) ;
F_7 ( V_15 -> V_19 , L_30 , V_20 , V_137 ) ;
if ( F_12 ( V_137 & ( V_143 - 1 ) ) )
F_16 ( V_15 -> V_19 , L_31 ,
V_20 , V_137 ) ;
V_5 = F_49 ( V_46 , V_128 ) ;
if ( V_5 == NULL )
return - V_129 ;
memset ( V_9 -> V_42 , 0xff , V_4 -> V_144 ) ;
for ( V_7 = 0 ; V_7 < V_140 -> V_6 ; V_7 ++ )
V_9 -> V_42 [ V_140 -> V_145 + V_7 ] = ~ V_140 -> V_146 [ V_7 ] ;
F_34 ( V_4 , V_91 ) ;
F_46 ( V_4 , V_9 , V_5 , 1 , V_37 ) ;
V_138 = F_31 ( V_4 ) ;
F_50 ( V_5 ) ;
return V_138 ;
}
static int F_52 ( struct V_3 * V_4 , T_7 V_137 , int V_147 )
{
return 0 ;
}
static int F_53 ( struct V_148 * V_149 , T_8 V_150 )
{
int V_7 ;
T_2 V_151 ;
struct V_14 * V_15 = F_54 ( V_149 ) ;
void T_1 * V_1 = V_15 -> V_18 ;
F_7 ( V_15 -> V_19 , L_1 , V_20 ) ;
for ( V_7 = 0 ; V_7 < 10 ; V_7 ++ ) {
V_151 = F_10 ( V_1 + V_152 ) ;
if ( V_151 & V_153 )
break;
F_43 ( 1000 , 4000 ) ;
}
if ( V_151 & V_153 ) {
F_13 ( V_15 -> V_19 , L_32
L_33 ) ;
return - V_63 ;
}
F_2 ( V_154 | V_30 ,
V_1 + V_31 ) ;
F_2 ( ~ ( V_154 | V_30 ) ,
V_1 + V_32 ) ;
F_1 ( V_1 ) ;
return 0 ;
}
static int F_55 ( struct V_148 * V_149 )
{
struct V_14 * V_15 = F_54 ( V_149 ) ;
void T_1 * V_1 = V_15 -> V_18 ;
int V_7 ;
F_7 ( V_15 -> V_19 , L_1 , V_20 ) ;
for ( V_7 = 0 ; V_7 < 12 ; V_7 ++ )
F_10 ( V_1 + 0x1fff ) ;
return 0 ;
}
static void T_5 F_56 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
V_4 -> V_116 = V_155 ;
V_4 -> V_156 = L_34 ;
V_4 -> V_157 = V_46 ;
V_4 -> V_158 = V_143 ;
V_4 -> V_144 = V_117 ;
V_9 -> V_159 = V_155 ;
V_9 -> V_160 = V_161 ;
V_9 -> V_162 = V_9 -> V_163 = V_164 ;
V_9 -> V_165 = 20 ;
V_9 -> V_142 = V_166 ;
V_9 -> V_167 = 0x3ffff ;
V_9 -> V_168 = V_169 ;
V_9 -> V_170 = 8 ;
V_9 -> V_115 . V_171 = & V_172 ;
V_9 -> V_115 . V_173 = V_174 ;
V_9 -> V_115 . V_116 = V_46 ;
V_9 -> V_115 . V_175 = 8 ;
V_9 -> V_115 . V_176 = 8 ;
V_9 -> V_115 . V_177 = V_178 ;
V_9 -> V_179 = V_180 | V_181 ;
V_9 -> V_12 = V_9 -> V_13 = V_15 -> V_18 + V_57 ;
V_9 -> V_182 = & V_9 -> V_183 ;
F_57 ( & V_9 -> V_182 -> V_184 ) ;
F_58 ( & V_9 -> V_182 -> V_185 ) ;
V_9 -> V_186 = F_36 ;
V_9 -> V_121 = F_14 ;
V_9 -> V_187 = F_15 ;
V_9 -> V_188 = F_27 ;
V_9 -> V_189 = F_51 ;
V_9 -> V_190 = F_3 ;
V_9 -> V_191 = F_5 ;
V_9 -> V_192 = F_42 ;
V_9 -> V_115 . F_37 = F_40 ;
V_9 -> V_115 . F_44 = F_46 ;
V_9 -> V_115 . V_193 = F_39 ;
V_9 -> V_115 . V_194 = F_45 ;
V_9 -> V_115 . V_195 = F_41 ;
V_9 -> V_115 . V_196 = F_47 ;
if ( V_41 ) {
V_9 -> V_179 |= V_197 ;
V_9 -> V_198 = F_52 ;
}
}
static int T_5 F_59 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
void T_1 * V_1 = V_15 -> V_18 ;
T_3 V_199 , V_200 ;
V_199 = F_4 ( V_1 + V_201 ) ;
V_199 = F_4 ( V_1 + V_60 ) ;
V_200 = F_4 ( V_1 + V_202 ) ;
V_200 = F_4 ( V_1 + V_60 ) ;
if ( V_199 == V_203 && V_200 == V_204 ) {
F_60 ( V_15 -> V_19 ,
L_35 ) ;
return 0 ;
}
return - V_205 ;
}
static int T_5 F_61 ( struct V_148 * V_149 )
{
struct V_3 * V_4 ;
struct V_8 * V_9 ;
void T_1 * V_18 ;
struct V_14 * V_15 ;
int V_6 , V_64 ;
struct V_206 * V_207 ;
struct V_208 * V_19 = & V_149 -> V_19 ;
V_207 = F_62 ( V_149 , V_209 , 0 ) ;
if ( V_207 == NULL ) {
F_13 ( V_19 , L_36 ) ;
return - V_205 ;
}
V_18 = F_63 ( V_207 -> V_210 , F_64 ( V_207 ) ) ;
if ( ! V_18 ) {
F_13 ( V_19 , L_37 , V_207 ) ;
return - V_63 ;
}
V_6 = sizeof( struct V_3 ) + sizeof( struct V_8 ) +
sizeof( struct V_14 ) ;
V_4 = F_49 ( V_6 , V_128 ) ;
if ( V_4 == NULL ) {
V_64 = - V_129 ;
goto V_211;
}
V_9 = (struct V_8 * ) ( V_4 + 1 ) ;
V_15 = (struct V_14 * ) ( V_9 + 1 ) ;
V_4 -> V_10 = V_9 ;
V_9 -> V_10 = V_15 ;
V_4 -> V_19 . V_212 = & V_149 -> V_19 ;
V_15 -> V_18 = V_18 ;
V_15 -> V_19 = V_19 ;
F_56 ( V_4 ) ;
V_15 -> V_47 = F_65 ( V_213 , V_178 , V_214 ) ;
if ( V_15 -> V_47 == NULL ) {
V_64 = - V_215 ;
goto V_211;
}
F_66 ( V_149 , V_15 ) ;
F_17 ( V_4 ) ;
V_64 = F_59 ( V_4 ) ;
if ( V_64 == - V_205 ) {
F_16 ( V_19 , L_38 ) ;
goto V_211;
}
V_64 = F_67 ( V_4 ) ;
if ( V_64 )
goto V_211;
V_64 = F_48 ( V_4 ) ;
if ( V_64 )
goto V_211;
V_64 = F_68 ( V_4 , V_216 , NULL , NULL , 0 ) ;
if ( V_64 )
goto V_211;
V_15 -> V_4 = V_4 ;
return 0 ;
V_211:
F_69 ( V_18 ) ;
if ( V_4 ) {
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_14 * V_15 = V_9 -> V_10 ;
F_70 ( V_4 ) ;
F_71 ( V_15 -> V_47 ) ;
F_50 ( V_4 ) ;
}
return V_64 ;
}
static int T_9 F_72 ( struct V_148 * V_149 )
{
struct V_14 * V_15 = F_54 ( V_149 ) ;
F_70 ( V_15 -> V_4 ) ;
F_71 ( V_15 -> V_47 ) ;
F_50 ( V_15 -> V_4 ) ;
F_69 ( V_15 -> V_18 ) ;
return 0 ;
}
