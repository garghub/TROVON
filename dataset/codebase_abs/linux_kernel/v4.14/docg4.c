static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
if ( V_3 )
return - V_6 ;
V_5 -> V_7 = 7 ;
V_5 -> V_8 = 9 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
if ( V_3 )
return - V_6 ;
V_5 -> V_7 = 2 ;
V_5 -> V_8 = 5 ;
return 0 ;
}
static inline void F_3 ( void T_1 * V_9 )
{
F_4 ( 0 , V_9 + V_10 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_2 * V_11 , int V_12 )
{
int V_13 ;
struct V_14 * V_15 = F_6 ( V_2 ) ;
T_3 * V_16 = ( T_3 * ) V_11 ;
V_12 >>= 1 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ )
V_16 [ V_13 ] = F_7 ( V_15 -> V_17 ) ;
}
static void F_8 ( struct V_1 * V_2 , const T_2 * V_11 , int V_12 )
{
int V_13 ;
struct V_14 * V_15 = F_6 ( V_2 ) ;
T_3 * V_16 = ( T_3 * ) V_11 ;
V_12 >>= 1 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ )
F_4 ( V_16 [ V_13 ] , V_15 -> V_18 ) ;
}
static int F_9 ( struct V_19 * V_20 )
{
T_3 V_21 ;
unsigned long V_22 ;
void T_1 * V_9 = V_20 -> V_23 ;
F_10 ( V_20 -> V_24 , L_1 , V_25 ) ;
V_21 = F_7 ( V_9 + V_26 ) ;
V_22 = V_27 + F_11 ( 200 ) ;
do {
F_12 () ;
V_21 = F_13 ( V_9 + V_26 ) ;
} while ( ! ( V_21 & V_28 ) &&
F_14 ( V_27 , V_22 ) );
if ( F_15 ( ! ( V_21 & V_28 ) ) ) {
F_16 ( V_20 -> V_24 , L_2 , V_25 ) ;
return V_29 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_19 * V_20 = F_18 ( V_15 ) ;
int V_30 = V_31 ;
F_10 ( V_20 -> V_24 , L_1 , V_25 ) ;
if ( V_20 -> V_30 ) {
V_30 |= V_20 -> V_30 ;
V_20 -> V_30 = 0 ;
return V_30 ;
}
V_30 |= F_9 ( V_20 ) ;
return V_30 ;
}
static void F_19 ( struct V_1 * V_2 , int V_32 )
{
struct V_14 * V_15 = F_6 ( V_2 ) ;
struct V_19 * V_20 = F_18 ( V_15 ) ;
void T_1 * V_9 = V_20 -> V_23 ;
F_10 ( V_20 -> V_24 , L_3 , V_25 , V_32 ) ;
if ( V_32 < 0 )
return;
if ( V_32 > 0 )
F_20 ( V_20 -> V_24 , L_4 ) ;
F_4 ( 0 , V_9 + V_33 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_6 ( V_2 ) ;
struct V_19 * V_20 = F_18 ( V_15 ) ;
void T_1 * V_9 = V_20 -> V_23 ;
F_4 ( V_34 | V_35 ,
V_9 + V_36 ) ;
F_4 ( ~ ( V_34 | V_35 ) ,
V_9 + V_37 ) ;
F_3 ( V_9 ) ;
F_4 ( V_38 | V_35 ,
V_9 + V_36 ) ;
F_4 ( ~ ( V_38 | V_35 ) ,
V_9 + V_37 ) ;
F_4 ( V_39 , V_9 + V_40 ) ;
F_9 ( V_20 ) ;
}
static void F_22 ( void T_1 * V_9 , T_2 * V_41 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < 7 ; V_13 ++ ) {
V_41 [ V_13 ] = F_13 ( V_9 + F_23 ( V_13 ) ) ;
V_41 [ V_13 ] = F_13 ( V_9 + F_23 ( V_13 ) ) ;
}
}
static int F_24 ( struct V_1 * V_2 , T_2 * V_11 , int V_42 )
{
struct V_14 * V_15 = F_6 ( V_2 ) ;
struct V_19 * V_20 = F_18 ( V_15 ) ;
void T_1 * V_9 = V_20 -> V_23 ;
int V_13 , V_43 , V_44 [ 4 ] ;
const T_2 V_45 [ 8 ] = {
0xcf , 0x72 , 0xfc , 0x1b , 0xa9 , 0xc7 , 0xb9 , 0 } ;
F_22 ( V_9 , V_20 -> V_41 ) ;
if ( ! memcmp ( V_20 -> V_41 , V_45 , 7 ) )
return 0 ;
if ( V_46 == false ) {
if ( V_15 -> V_47 [ 15 ] ) {
int V_48 , V_49 = 0 ;
unsigned long V_50 = V_15 -> V_47 [ 15 ] ;
F_25 (bit, &written_flag, 8 )
V_49 ++ ;
if ( V_49 > 4 ) {
F_20 ( V_20 -> V_24 ,
L_5
L_6 ,
V_42 * V_51 ) ;
return 0 ;
}
}
}
for ( V_13 = 0 ; V_13 < 7 ; V_13 ++ )
V_20 -> V_41 [ V_13 ] = F_26 ( V_20 -> V_41 [ V_13 ] ) ;
V_43 = F_27 ( V_20 -> V_52 , NULL , V_53 , NULL ,
V_20 -> V_41 , NULL , V_44 ) ;
if ( V_43 == - V_54 ) {
F_20 ( V_20 -> V_24 , L_7 ,
V_42 * V_51 ) ;
return - V_54 ;
}
F_28 ( V_43 < 0 ) ;
for ( V_13 = 0 ; V_13 < V_43 ; V_13 ++ )
V_44 [ V_13 ] = ( V_44 [ V_13 ] & ~ 7 ) | ( 7 - ( V_44 [ V_13 ] & 7 ) ) ;
for ( V_13 = 0 ; V_13 < V_43 ; V_13 ++ ) {
if ( V_44 [ V_13 ] > V_53 * 8 )
continue;
if ( V_44 [ V_13 ] > V_51 * 8 )
F_29 ( V_44 [ V_13 ] - V_51 * 8 ,
( unsigned long * ) V_15 -> V_47 ) ;
else
F_29 ( V_44 [ V_13 ] , ( unsigned long * ) V_11 ) ;
}
F_30 ( V_20 -> V_24 , L_8 ,
V_43 , V_42 * V_51 ) ;
return V_43 ;
}
static T_2 F_31 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_6 ( V_2 ) ;
struct V_19 * V_20 = F_18 ( V_15 ) ;
F_10 ( V_20 -> V_24 , L_9 , V_25 ) ;
if ( V_20 -> V_55 . V_56 == V_57 ) {
int V_30 ;
V_20 -> V_55 . V_56 = 0 ;
if ( V_20 -> V_30 ) {
V_30 = V_20 -> V_30 ;
V_20 -> V_30 = 0 ;
}
else
V_30 = V_31 | V_58 ;
return V_30 ;
}
F_20 ( V_20 -> V_24 , L_10 ) ;
return 0 ;
}
static void F_32 ( struct V_19 * V_20 , T_4 V_59 )
{
void T_1 * V_9 = V_20 -> V_23 ;
F_33 ( V_59 & 0xff , V_9 + V_60 ) ;
V_59 >>= 8 ;
F_33 ( V_59 & 0xff , V_9 + V_60 ) ;
V_59 >>= 8 ;
F_33 ( V_59 & 0xff , V_9 + V_60 ) ;
V_59 >>= 8 ;
F_33 ( V_59 & 0xff , V_9 + V_60 ) ;
}
static int F_34 ( struct V_19 * V_20 )
{
void T_1 * V_9 = V_20 -> V_23 ;
T_3 V_61 = F_7 ( V_9 + V_62 ) ;
T_3 V_63 = F_7 ( V_9 + V_62 ) ;
T_3 V_64 = F_7 ( V_9 + V_65 ) ;
F_10 ( V_20 -> V_24 , L_11 ,
V_25 , V_61 , V_63 , V_64 ) ;
if ( V_61 != V_66
|| V_63 != V_67
|| V_64 != V_67 ) {
V_20 -> V_30 = V_29 ;
F_20 ( V_20 -> V_24 , L_12
L_13 , V_61 , V_63 , V_64 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_6 ( V_2 ) ;
struct V_19 * V_20 = F_18 ( V_15 ) ;
void T_1 * V_9 = V_20 -> V_23 ;
int V_69 = 0 ;
F_10 ( V_20 -> V_24 , L_14 , V_25 ) ;
F_4 ( V_70 , V_9 + V_71 ) ;
F_4 ( V_72 , V_9 + V_73 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
F_9 ( V_20 ) ;
F_4 ( V_74 , V_9 + V_71 ) ;
F_4 ( V_75 , V_9 + V_73 ) ;
F_4 ( V_76 | 4 , V_9 + V_77 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
V_69 = F_34 ( V_20 ) ;
F_4 ( 0 , V_9 + V_78 ) ;
F_3 ( V_9 ) ;
F_9 ( V_20 ) ;
F_3 ( V_9 ) ;
return V_69 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_6 ( V_2 ) ;
struct V_19 * V_20 = F_18 ( V_15 ) ;
void T_1 * V_9 = V_20 -> V_23 ;
F_4 ( V_79 | V_80 , V_9 + V_26 ) ;
F_4 ( V_81 , V_9 + V_71 ) ;
F_4 ( V_82 , V_9 + V_73 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
F_9 ( V_20 ) ;
F_3 ( V_9 ) ;
}
static void F_37 ( struct V_1 * V_2 , T_4 V_59 )
{
struct V_14 * V_15 = F_6 ( V_2 ) ;
struct V_19 * V_20 = F_18 ( V_15 ) ;
void T_1 * V_9 = V_20 -> V_23 ;
F_10 ( V_20 -> V_24 ,
L_15 , V_25 , V_59 ) ;
F_36 ( V_2 ) ;
F_4 ( V_83 , V_9 + V_71 ) ;
F_4 ( V_84 , V_9 + V_73 ) ;
F_3 ( V_9 ) ;
F_32 ( V_20 , V_59 ) ;
F_3 ( V_9 ) ;
F_4 ( V_85 , V_9 + V_73 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
F_9 ( V_20 ) ;
}
static void F_38 ( struct V_1 * V_2 , T_4 V_59 )
{
struct V_14 * V_15 = F_6 ( V_2 ) ;
struct V_19 * V_20 = F_18 ( V_15 ) ;
void T_1 * V_9 = V_20 -> V_23 ;
F_10 ( V_20 -> V_24 ,
L_16 , V_25 , V_59 ) ;
F_36 ( V_2 ) ;
if ( F_15 ( V_86 ) ) {
F_4 ( V_87 , V_9 + V_71 ) ;
F_4 ( V_88 , V_9 + V_73 ) ;
F_4 ( V_89 , V_9 + V_73 ) ;
F_3 ( V_9 ) ;
}
F_4 ( V_90 , V_9 + V_71 ) ;
F_4 ( V_91 , V_9 + V_73 ) ;
F_3 ( V_9 ) ;
F_32 ( V_20 , V_59 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
F_9 ( V_20 ) ;
}
static T_4 F_39 ( int V_42 , int V_92 )
{
int V_93 = V_42 / 4 ;
int V_94 = ( V_42 % 4 ) * 0x108 + V_92 / 2 ;
return ( V_93 << 16 ) | V_94 ;
}
static void F_40 ( struct V_1 * V_2 , unsigned V_56 , int V_92 ,
int V_95 )
{
struct V_14 * V_15 = F_6 ( V_2 ) ;
struct V_19 * V_20 = F_18 ( V_15 ) ;
T_4 V_96 = F_39 ( V_95 , V_92 ) ;
F_10 ( V_20 -> V_24 , L_17 ,
V_25 , V_56 , V_95 , V_92 ) ;
V_20 -> V_55 . V_56 = V_56 ;
V_20 -> V_55 . V_92 = V_92 ;
V_20 -> V_55 . V_42 = V_95 ;
switch ( V_56 ) {
case V_97 :
F_21 ( V_2 ) ;
break;
case V_98 :
F_37 ( V_2 , V_96 ) ;
break;
case V_57 :
break;
case V_99 :
if ( F_15 ( V_86 ) ) {
T_3 V_93 = V_96 >> 16 ;
if ( V_93 & 0x01 )
F_20 ( V_20 -> V_24 ,
L_18 ) ;
}
F_38 ( V_2 , V_96 ) ;
if ( V_20 -> V_100 == V_95 )
memcpy ( V_15 -> V_47 , V_20 -> V_101 , 16 ) ;
break;
case V_102 :
F_35 ( V_2 ) ;
break;
case V_103 :
case V_104 :
case V_105 :
case V_106 :
F_20 ( V_20 -> V_24 , L_19
L_20 , V_56 ) ;
break;
}
}
static int F_41 ( struct V_1 * V_2 , struct V_14 * V_15 ,
T_2 * V_11 , int V_42 , bool V_107 )
{
struct V_19 * V_20 = F_18 ( V_15 ) ;
void T_1 * V_9 = V_20 -> V_23 ;
T_3 V_30 , V_108 , * V_109 ;
int V_110 = 0 ;
F_10 ( V_20 -> V_24 , L_21 , V_25 , V_42 ) ;
F_4 ( V_76 |
V_111 |
V_112 |
V_113 ,
V_9 + V_77 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
V_30 = F_7 ( V_9 + V_62 ) ;
if ( V_30 & V_114 ) {
F_16 ( V_20 -> V_24 ,
L_22 , V_30 ) ;
F_4 ( 0 , V_9 + V_78 ) ;
return - V_68 ;
}
F_10 ( V_20 -> V_24 , L_23 , V_25 , V_30 ) ;
F_5 ( V_2 , V_11 , V_51 ) ;
F_5 ( V_2 , V_15 -> V_47 , 14 ) ;
V_109 = ( T_3 * ) ( V_15 -> V_47 + 14 ) ;
* V_109 = F_7 ( V_9 + V_65 ) ;
F_3 ( V_9 ) ;
if ( F_42 ( V_107 == true ) ) {
V_108 = F_7 ( V_9 + V_40 ) ;
V_108 = F_7 ( V_9 + V_40 ) ;
F_10 ( V_20 -> V_24 , L_24 , V_25 , V_108 ) ;
if ( V_108 & V_115 ) {
V_110 = F_24 ( V_2 , V_11 , V_42 ) ;
if ( V_110 == - V_54 )
V_2 -> V_116 . V_117 ++ ;
else
V_2 -> V_116 . V_118 += V_110 ;
}
}
F_4 ( 0 , V_9 + V_78 ) ;
if ( V_110 == - V_54 )
return 0 ;
return V_110 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_14 * V_15 ,
T_2 * V_11 , int V_119 , int V_42 )
{
return F_41 ( V_2 , V_15 , V_11 , V_42 , false ) ;
}
static int F_44 ( struct V_1 * V_2 , struct V_14 * V_15 ,
T_2 * V_11 , int V_119 , int V_42 )
{
return F_41 ( V_2 , V_15 , V_11 , V_42 , true ) ;
}
static int F_45 ( struct V_1 * V_2 , struct V_14 * V_15 ,
int V_42 )
{
struct V_19 * V_20 = F_18 ( V_15 ) ;
void T_1 * V_9 = V_20 -> V_23 ;
T_3 V_30 ;
F_10 ( V_20 -> V_24 , L_25 , V_25 , V_42 ) ;
F_40 ( V_2 , V_98 , V_15 -> V_120 . V_121 , V_42 ) ;
F_4 ( V_76 | V_122 , V_9 + V_77 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
V_30 = F_7 ( V_9 + V_62 ) ;
if ( V_30 & V_114 ) {
F_20 ( V_20 -> V_24 ,
L_26 , V_30 ) ;
return - V_68 ;
}
F_10 ( V_20 -> V_24 , L_23 , V_25 , V_30 ) ;
F_5 ( V_2 , V_15 -> V_47 , 16 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
F_4 ( 0 , V_9 + V_78 ) ;
F_3 ( V_9 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , int V_42 )
{
struct V_14 * V_15 = F_6 ( V_2 ) ;
struct V_19 * V_20 = F_18 ( V_15 ) ;
void T_1 * V_9 = V_20 -> V_23 ;
T_3 V_93 ;
F_10 ( V_20 -> V_24 , L_27 , V_25 , V_42 ) ;
F_36 ( V_2 ) ;
F_4 ( V_123 , V_9 + V_71 ) ;
F_4 ( V_124 , V_9 + V_73 ) ;
F_3 ( V_9 ) ;
V_93 = ( T_3 ) ( V_42 / 4 ) ;
F_33 ( V_93 & 0xff , V_9 + V_60 ) ;
V_93 >>= 8 ;
F_33 ( V_93 & 0xff , V_9 + V_60 ) ;
F_3 ( V_9 ) ;
F_4 ( V_125 , V_9 + V_73 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
F_47 ( 500 , 1000 ) ;
F_9 ( V_20 ) ;
F_4 ( V_74 , V_9 + V_71 ) ;
F_4 ( V_75 , V_9 + V_73 ) ;
F_4 ( V_76 | 4 , V_9 + V_77 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
F_34 ( V_20 ) ;
F_4 ( 0 , V_9 + V_78 ) ;
F_3 ( V_9 ) ;
F_9 ( V_20 ) ;
F_3 ( V_9 ) ;
return V_15 -> V_126 ( V_2 , V_15 ) ;
}
static int F_48 ( struct V_1 * V_2 , struct V_14 * V_15 ,
const T_2 * V_11 , bool V_107 )
{
struct V_19 * V_20 = F_18 ( V_15 ) ;
void T_1 * V_9 = V_20 -> V_23 ;
T_2 V_41 [ 8 ] ;
F_10 ( V_20 -> V_24 , L_1 , V_25 ) ;
F_4 ( V_111 |
V_112 |
V_113 ,
V_9 + V_77 ) ;
F_3 ( V_9 ) ;
F_8 ( V_2 , V_11 , V_51 ) ;
F_8 ( V_2 , V_15 -> V_47 , 6 ) ;
F_4 ( V_15 -> V_47 [ 6 ] , V_9 + V_127 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
if ( F_42 ( V_107 == true ) ) {
T_2 V_128 = F_13 ( V_9 + V_129 ) ;
V_128 = F_13 ( V_9 + V_129 ) ;
F_4 ( V_128 , V_9 + V_127 ) ;
F_3 ( V_9 ) ;
F_22 ( V_9 , V_41 ) ;
V_41 [ 7 ] = 0 ;
}
else {
F_4 ( V_15 -> V_47 [ 7 ] , V_9 + V_127 ) ;
F_3 ( V_9 ) ;
memcpy ( V_41 , & V_15 -> V_47 [ 8 ] , 8 ) ;
}
F_8 ( V_2 , V_41 , 8 ) ;
F_3 ( V_9 ) ;
F_3 ( V_9 ) ;
F_4 ( 0 , V_9 + V_78 ) ;
F_3 ( V_9 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_14 * V_15 ,
const T_2 * V_11 , int V_119 , int V_42 )
{
return F_48 ( V_2 , V_15 , V_11 , false ) ;
}
static int F_50 ( struct V_1 * V_2 , struct V_14 * V_15 ,
const T_2 * V_11 , int V_119 , int V_42 )
{
return F_48 ( V_2 , V_15 , V_11 , true ) ;
}
static int F_51 ( struct V_1 * V_2 , struct V_14 * V_15 ,
int V_42 )
{
struct V_19 * V_20 = F_18 ( V_15 ) ;
V_20 -> V_100 = V_42 ;
memcpy ( V_20 -> V_101 , V_15 -> V_47 , 16 ) ;
return 0 ;
}
static int T_5 F_52 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_6 ( V_2 ) ;
struct V_19 * V_20 = F_18 ( V_15 ) ;
T_4 V_96 = F_39 ( V_130 , 0 ) ;
T_2 * V_11 ;
int V_13 , V_131 ;
T_6 V_132 = V_2 -> V_116 . V_117 ;
V_11 = F_53 ( V_51 , V_133 ) ;
if ( V_11 == NULL )
return - V_134 ;
F_37 ( V_2 , V_96 ) ;
F_44 ( V_2 , V_15 , V_11 , 0 , V_130 ) ;
if ( V_15 -> V_135 == NULL )
goto exit;
if ( V_2 -> V_116 . V_117 > V_132 ) {
V_132 = V_2 -> V_116 . V_117 ;
F_44 ( V_2 , V_15 , V_11 , 0 , V_136 ) ;
if ( V_2 -> V_116 . V_117 > V_132 ) {
F_20 ( V_20 -> V_24 ,
L_28 ) ;
goto exit;
}
}
for ( V_13 = V_131 = 0 ; V_131 < V_137 ; V_131 += 8 , V_13 ++ ) {
int V_138 ;
unsigned long V_139 = ~ V_11 [ V_13 ] ;
F_25 (bitnum, &bits, 8 ) {
int V_140 = V_131 + 7 - V_138 ;
V_15 -> V_135 [ V_140 / 4 ] |=
0x03 << ( ( V_140 % 4 ) * 2 ) ;
V_2 -> V_116 . V_141 ++ ;
F_30 ( V_20 -> V_24 , L_29 ,
V_140 ) ;
}
}
exit:
F_54 ( V_11 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , T_7 V_142 )
{
int V_143 , V_13 ;
T_2 * V_11 ;
struct V_14 * V_15 = F_6 ( V_2 ) ;
struct V_19 * V_20 = F_18 ( V_15 ) ;
struct V_144 * V_145 = V_15 -> V_146 ;
int V_42 = ( int ) ( V_142 >> V_15 -> V_147 ) ;
T_4 V_96 = F_39 ( V_42 , 0 ) ;
F_10 ( V_20 -> V_24 , L_30 , V_25 , V_142 ) ;
if ( F_15 ( V_142 & ( V_148 - 1 ) ) )
F_20 ( V_20 -> V_24 , L_31 ,
V_25 , V_142 ) ;
V_11 = F_53 ( V_51 , V_133 ) ;
if ( V_11 == NULL )
return - V_134 ;
memset ( V_15 -> V_47 , 0xff , V_2 -> V_149 ) ;
for ( V_13 = 0 ; V_13 < V_145 -> V_12 ; V_13 ++ )
V_15 -> V_47 [ V_145 -> V_150 + V_13 ] = ~ V_145 -> V_151 [ V_13 ] ;
F_38 ( V_2 , V_96 ) ;
F_50 ( V_2 , V_15 , V_11 , 1 , V_42 ) ;
V_143 = F_35 ( V_2 ) ;
F_54 ( V_11 ) ;
return V_143 ;
}
static int F_56 ( struct V_1 * V_2 , T_7 V_142 )
{
return 0 ;
}
static int F_57 ( struct V_152 * V_153 , T_8 V_154 )
{
int V_13 ;
T_2 V_155 ;
struct V_19 * V_20 = F_58 ( V_153 ) ;
void T_1 * V_9 = V_20 -> V_23 ;
F_10 ( V_20 -> V_24 , L_1 , V_25 ) ;
for ( V_13 = 0 ; V_13 < 10 ; V_13 ++ ) {
V_155 = F_13 ( V_9 + V_156 ) ;
if ( V_155 & V_157 )
break;
F_47 ( 1000 , 4000 ) ;
}
if ( V_155 & V_157 ) {
F_16 ( V_20 -> V_24 , L_32
L_33 ) ;
return - V_68 ;
}
F_4 ( V_158 | V_35 ,
V_9 + V_36 ) ;
F_4 ( ~ ( V_158 | V_35 ) ,
V_9 + V_37 ) ;
F_3 ( V_9 ) ;
return 0 ;
}
static int F_59 ( struct V_152 * V_153 )
{
struct V_19 * V_20 = F_58 ( V_153 ) ;
void T_1 * V_9 = V_20 -> V_23 ;
int V_13 ;
F_10 ( V_20 -> V_24 , L_1 , V_25 ) ;
for ( V_13 = 0 ; V_13 < 12 ; V_13 ++ )
F_13 ( V_9 + 0x1fff ) ;
return 0 ;
}
static void T_5 F_60 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_6 ( V_2 ) ;
struct V_19 * V_20 = F_18 ( V_15 ) ;
V_2 -> V_121 = V_159 ;
V_2 -> V_160 = L_34 ;
V_2 -> V_161 = V_51 ;
V_2 -> V_162 = V_148 ;
V_2 -> V_149 = V_122 ;
F_61 ( V_2 , & V_163 ) ;
V_15 -> V_164 = V_159 ;
V_15 -> V_165 = V_166 ;
V_15 -> V_167 = V_15 -> V_168 = V_169 ;
V_15 -> V_170 = 20 ;
V_15 -> V_147 = V_171 ;
V_15 -> V_172 = 0x3ffff ;
V_15 -> V_173 = V_174 ;
V_15 -> V_175 = 8 ;
V_15 -> V_120 . V_176 = V_177 ;
V_15 -> V_120 . V_121 = V_51 ;
V_15 -> V_120 . V_178 = 8 ;
V_15 -> V_120 . V_179 = 8 ;
V_15 -> V_120 . V_180 = V_181 ;
V_15 -> V_182 = V_183 | V_184 ;
V_15 -> V_17 = V_15 -> V_18 = V_20 -> V_23 + V_62 ;
V_15 -> V_185 = & V_15 -> V_186 ;
F_62 ( V_15 -> V_185 ) ;
V_15 -> V_187 = F_40 ;
V_15 -> V_126 = F_17 ;
V_15 -> V_188 = F_19 ;
V_15 -> V_189 = F_31 ;
V_15 -> V_190 = F_55 ;
V_15 -> V_191 = F_5 ;
V_15 -> V_192 = F_8 ;
V_15 -> V_193 = F_46 ;
V_15 -> V_194 = V_195 ;
V_15 -> V_196 = V_195 ;
V_15 -> V_120 . F_41 = F_44 ;
V_15 -> V_120 . F_48 = F_50 ;
V_15 -> V_120 . V_197 = F_43 ;
V_15 -> V_120 . V_198 = F_49 ;
V_15 -> V_120 . V_199 = F_45 ;
V_15 -> V_120 . V_200 = F_51 ;
if ( V_46 ) {
V_15 -> V_182 |= V_201 ;
V_15 -> V_202 = F_56 ;
}
}
static int T_5 F_63 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_6 ( V_2 ) ;
struct V_19 * V_20 = F_18 ( V_15 ) ;
void T_1 * V_9 = V_20 -> V_23 ;
T_3 V_203 , V_204 ;
V_203 = F_7 ( V_9 + V_205 ) ;
V_203 = F_7 ( V_9 + V_65 ) ;
V_204 = F_7 ( V_9 + V_206 ) ;
V_204 = F_7 ( V_9 + V_65 ) ;
if ( V_203 == V_207 && V_204 == V_208 ) {
F_64 ( V_20 -> V_24 ,
L_35 ) ;
return 0 ;
}
return - V_209 ;
}
static int T_5 F_65 ( struct V_152 * V_153 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
void T_1 * V_23 ;
struct V_19 * V_20 ;
int V_12 , V_69 ;
struct V_210 * V_211 ;
struct V_212 * V_24 = & V_153 -> V_24 ;
V_211 = F_66 ( V_153 , V_213 , 0 ) ;
if ( V_211 == NULL ) {
F_16 ( V_24 , L_36 ) ;
return - V_209 ;
}
V_23 = F_67 ( V_211 -> V_214 , F_68 ( V_211 ) ) ;
if ( ! V_23 ) {
F_16 ( V_24 , L_37 , V_211 ) ;
return - V_68 ;
}
V_12 = sizeof( struct V_14 ) + sizeof( struct V_19 ) ;
V_15 = F_53 ( V_12 , V_133 ) ;
if ( V_15 == NULL ) {
V_69 = - V_134 ;
goto V_215;
}
V_2 = F_69 ( V_15 ) ;
V_20 = (struct V_19 * ) ( V_15 + 1 ) ;
F_70 ( V_15 , V_20 ) ;
V_2 -> V_24 . V_216 = & V_153 -> V_24 ;
V_20 -> V_23 = V_23 ;
V_20 -> V_24 = V_24 ;
F_60 ( V_2 ) ;
V_20 -> V_52 = F_71 ( V_217 , V_181 , V_218 ) ;
if ( V_20 -> V_52 == NULL ) {
V_69 = - V_219 ;
goto V_220;
}
F_72 ( V_153 , V_20 ) ;
F_21 ( V_2 ) ;
V_69 = F_63 ( V_2 ) ;
if ( V_69 == - V_209 ) {
F_20 ( V_24 , L_38 ) ;
goto V_220;
}
V_69 = F_73 ( V_2 ) ;
if ( V_69 )
goto V_220;
V_69 = F_52 ( V_2 ) ;
if ( V_69 )
goto V_220;
V_69 = F_74 ( V_2 , V_221 , NULL , NULL , 0 ) ;
if ( V_69 )
goto V_220;
V_20 -> V_2 = V_2 ;
return 0 ;
V_220:
F_75 ( V_2 ) ;
F_76 ( V_20 -> V_52 ) ;
F_54 ( V_15 ) ;
V_215:
F_77 ( V_23 ) ;
return V_69 ;
}
static int T_9 F_78 ( struct V_152 * V_153 )
{
struct V_19 * V_20 = F_58 ( V_153 ) ;
F_75 ( V_20 -> V_2 ) ;
F_76 ( V_20 -> V_52 ) ;
F_54 ( F_6 ( V_20 -> V_2 ) ) ;
F_77 ( V_20 -> V_23 ) ;
return 0 ;
}
