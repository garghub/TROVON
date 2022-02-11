static T_1 F_1 ( bool V_1 ,
T_2 V_2 ,
T_2 V_3 ,
T_1 V_4 ,
T_2 V_5 )
{
return ( ( V_1 & 1 ) << 31 ) | ( ( V_2 & 0x7 ) << 28 ) |
( ( V_3 & 1 ) << 27 ) | ( 1 << 26 ) |
( ( V_4 & 0x1FFFF ) << 9 ) | ( 1 << 8 ) |
( V_5 & 0xFF ) ;
}
static int F_2 ( struct V_6 * V_7 ,
T_1 V_4 ,
T_2 V_8 )
{
struct V_9 V_10 ;
T_1 V_11 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_11 = F_1 ( 1 , 0 , 0 , V_4 , V_8 ) ;
V_10 . V_12 = V_13 ;
V_10 . V_11 = V_11 ;
V_10 . V_14 = V_15 | V_16 ;
return F_3 ( V_7 -> V_17 , & V_10 , 0 ) ;
}
static int F_4 ( struct V_6 * V_7 ,
T_1 V_4 ,
T_2 * V_8 )
{
struct V_9 V_10 ;
T_1 V_11 ;
int V_18 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_11 = F_1 ( 0 , 0 , 0 , V_4 , 0 ) ;
V_10 . V_12 = V_13 ;
V_10 . V_11 = V_11 ;
V_10 . V_14 = V_15 | V_16 ;
V_18 = F_3 ( V_7 -> V_17 , & V_10 , 0 ) ;
if ( ( ! V_18 ) && ( V_8 ) )
* V_8 = V_10 . V_19 [ 0 ] & 0xFF ;
return V_18 ;
}
static int F_5 ( struct V_20 * V_2 ,
T_1 V_12 ,
T_1 V_11 ,
T_1 V_14 ,
T_1 * V_19 )
{
struct V_9 V_21 ;
struct V_22 * V_17 ;
int V_18 ;
V_17 = V_2 -> V_7 -> V_17 ;
memset ( & V_21 , 0 , sizeof( struct V_9 ) ) ;
V_21 . V_12 = V_12 ;
V_21 . V_11 = V_11 ;
V_21 . V_14 = V_14 ;
V_18 = F_3 ( V_17 , & V_21 , 3 ) ;
if ( ( ! V_18 ) && ( V_19 ) )
* V_19 = V_21 . V_19 [ 0 ] ;
return V_18 ;
}
static void F_6 ( struct V_20 * V_23 )
{
struct V_24 * V_25 = F_7 ( V_23 ) ;
F_8 ( V_23 ) ;
F_9 ( V_25 ) ;
F_10 ( V_23 ) ;
}
static void F_11 ( struct V_20 * V_26 )
{
int V_27 = 0 ;
int V_18 ;
struct V_6 * V_7 = V_26 -> V_7 ;
struct V_22 * V_17 = V_7 -> V_17 ;
T_3 V_28 = ( F_12 ( V_17 -> V_29 ) - 1 ) ;
T_2 V_30 ;
T_1 clock , V_19 , V_31 ;
T_4 V_32 ;
V_27 = F_2 ( V_26 -> V_7 ,
V_33 ,
( 1 << 3 ) ) ;
if ( V_27 != - V_34 )
F_13 ( V_35 , L_1 , V_36 , V_27 ) ;
F_14 ( 20 ) ;
V_17 -> V_37 . V_38 = V_28 ;
V_17 -> V_37 . V_39 = V_40 ;
V_17 -> V_37 . V_41 = V_42 ;
V_17 -> V_37 . V_43 = V_44 ;
V_17 -> V_37 . V_45 = V_46 ;
V_17 -> V_37 . V_47 = V_48 ;
V_17 -> V_49 -> V_50 ( V_17 , & V_17 -> V_37 ) ;
F_14 ( 20 ) ;
V_17 -> V_37 . clock = V_17 -> V_51 ;
V_17 -> V_37 . V_43 = V_52 ;
V_17 -> V_49 -> V_50 ( V_17 , & V_17 -> V_37 ) ;
F_14 ( 20 ) ;
V_17 -> V_37 . V_39 = V_53 ;
V_17 -> V_49 -> V_50 ( V_17 , & V_17 -> V_37 ) ;
F_14 ( 20 ) ;
V_18 = F_5 ( V_26 ,
V_54 ,
0 ,
( V_55 | V_56 ) ,
NULL ) ;
V_17 -> V_37 . V_39 = V_40 ;
V_17 -> V_49 -> V_50 ( V_17 , & V_17 -> V_37 ) ;
F_14 ( 20 ) ;
V_17 -> V_57 = 0 ;
if ( V_18 )
F_13 ( V_35 , L_2 , V_36 , V_18 ) ;
if ( ! V_17 -> V_29 ) {
V_18 = F_5 ( V_26 ,
V_58 ,
0 ,
( V_59 | V_60 ) ,
& V_19 ) ;
if ( V_18 )
F_13 ( V_35 , L_3 ,
V_36 , V_18 ) ;
V_17 -> V_29 = V_19 ;
}
for ( V_31 = 0 ; V_31 < 100 ; V_31 ++ ) {
V_18 = F_5 ( V_26 ,
V_58 ,
V_17 -> V_29 ,
( V_59 | V_60 ) ,
& V_19 ) ;
if ( V_18 ) {
F_13 ( V_35 , L_3 ,
V_36 , V_18 ) ;
break;
}
if ( V_19 & V_61 )
break;
F_14 ( 20 ) ;
}
if ( ( V_31 == 100 ) || ( V_18 ) ) {
F_13 ( V_35 , L_4 ,
V_36 , V_31 , V_18 ) ;
return;
}
V_18 = F_5 ( V_26 ,
V_62 ,
0 ,
( V_63 | V_60 ) ,
& V_19 ) ;
if ( V_18 ) {
F_13 ( V_35 , L_5 , V_36 , V_18 ) ;
return;
}
V_32 = V_19 >> 16 ;
V_17 -> V_37 . V_41 = V_64 ;
V_17 -> V_49 -> V_50 ( V_17 , & V_17 -> V_37 ) ;
V_18 = F_5 ( V_26 ,
V_65 ,
( V_32 << 16 ) ,
( V_66 | V_16 ) ,
NULL ) ;
if ( V_18 ) {
F_13 ( V_35 , L_6 , V_36 , V_18 ) ;
return;
}
if ( V_7 -> V_17 -> V_67 & V_68 ) {
F_13 ( V_35 , L_7 , V_36 ) ;
V_18 = F_4 ( V_7 , V_69 , & V_30 ) ;
if ( V_18 ) {
F_13 ( V_35 , L_8 ,
V_36 , V_18 ) ;
V_7 -> V_70 &= ~ V_71 ;
} else {
V_18 = F_2 ( V_7 ,
V_69 ,
( V_30 | V_72 ) ) ;
if ( V_18 ) {
F_13 ( V_35 ,
L_9 ,
V_36 , V_18 ) ;
return;
}
F_15 ( V_7 ) ;
V_17 -> V_37 . V_47 = V_73 ;
V_17 -> V_49 -> V_50 ( V_17 , & V_17 -> V_37 ) ;
}
}
if ( F_16 ( V_7 ) )
clock = 50000000 ;
else
clock = V_7 -> V_74 . V_75 ;
if ( clock > V_17 -> V_76 )
clock = V_17 -> V_76 ;
V_17 -> V_37 . clock = clock ;
V_17 -> V_49 -> V_50 ( V_17 , & V_17 -> V_37 ) ;
if ( V_7 -> V_17 -> V_67 & V_77 ) {
V_18 = F_2 ( V_7 ,
V_78 ,
( V_79 |
V_80 ) ) ;
if ( V_18 ) {
F_13 ( V_35 , L_10 ,
V_36 , V_18 ) ;
return;
}
V_17 -> V_37 . V_45 = V_81 ;
V_17 -> V_49 -> V_50 ( V_17 , & V_17 -> V_37 ) ;
}
}
static void F_17 ( struct V_24 * V_25 , T_1 V_82 )
{
struct V_83 * V_84 =
(struct V_83 * ) V_25 -> V_85 ;
struct V_22 * V_17 = V_84 -> V_26 -> V_7 -> V_17 ;
T_1 clock ;
clock = V_82 * 1000 ;
if ( clock > V_17 -> V_76 )
clock = V_17 -> V_76 ;
V_17 -> V_37 . clock = clock ;
V_17 -> V_49 -> V_50 ( V_17 , & V_17 -> V_37 ) ;
}
static int F_18 ( struct V_24 * V_25 , T_1 V_86 )
{
struct V_83 * V_84 =
(struct V_83 * ) V_25 -> V_85 ;
int V_87 ;
F_13 ( V_88 , L_11 , V_36 ) ;
V_87 = F_19 ( V_84 -> V_26 , V_86 ) ;
V_84 -> V_26 -> V_89 = 256 ;
F_13 ( V_90 ,
L_12 , V_36 , V_86 ) ;
return V_87 ;
}
static int F_20 ( struct V_24 * V_25 )
{
struct V_83 * V_84 =
(struct V_83 * ) V_25 -> V_85 ;
int V_87 = 0 ;
F_17 ( V_25 , 50000 ) ;
V_84 -> V_91 = 256 ;
V_87 = F_18 ( V_25 , V_84 -> V_91 ) ;
if ( V_87 )
F_13 ( V_35 ,
L_13 , V_36 ) ;
return V_87 ;
}
int F_21 ( struct V_24 * V_25 ,
T_1 V_92 ,
T_2 * V_93 )
{
struct V_83 * V_84 =
(struct V_83 * ) V_25 -> V_85 ;
T_2 V_94 = 0 ;
int V_87 ;
F_10 ( V_84 -> V_26 ) ;
if ( V_94 == 0 )
* V_93 = F_22 ( V_84 -> V_26 , V_92 , & V_87 ) ;
else
* V_93 = F_23 ( V_84 -> V_26 , V_92 , & V_87 ) ;
F_8 ( V_84 -> V_26 ) ;
return V_87 ;
}
int F_24 ( struct V_24 * V_25 ,
T_2 V_23 ,
T_1 V_92 ,
T_2 * V_93 )
{
struct V_83 * V_84 =
(struct V_83 * ) V_25 -> V_85 ;
int V_87 = 0 ;
F_10 ( V_84 -> V_26 ) ;
if ( V_23 == 0 )
F_25 ( V_84 -> V_26 , * V_93 , V_92 , & V_87 ) ;
else
F_26 ( V_84 -> V_26 , * V_93 , V_92 , & V_87 ) ;
F_8 ( V_84 -> V_26 ) ;
return V_87 ;
}
void F_27 ( struct V_24 * V_25 , T_2 V_95 )
{
int V_87 ;
V_87 = F_24 ( V_25 ,
1 ,
( V_96 |
V_97 ) ,
& V_95 ) ;
if ( V_87 )
F_13 ( V_35 , L_14 , V_36 ) ;
}
static int F_28 ( struct V_24 * V_25 ,
T_1 V_92 ,
T_1 V_98 ,
T_2 * V_93 )
{
struct V_83 * V_84 =
(struct V_83 * ) V_25 -> V_85 ;
T_1 V_87 ;
F_10 ( V_84 -> V_26 ) ;
V_87 = F_29 ( V_84 -> V_26 , V_93 , V_92 , V_98 ) ;
F_8 ( V_84 -> V_26 ) ;
if ( V_87 != 0 )
F_13 ( V_35 , L_15 , V_36 ) ;
return V_87 ;
}
int F_30 ( struct V_24 * V_25 ,
T_1 V_92 ,
T_2 * V_93 ,
T_1 V_98 )
{
struct V_83 * V_84 =
(struct V_83 * ) V_25 -> V_85 ;
int V_87 ;
if ( V_84 -> V_99 > 1 ) {
F_13 ( V_35 , L_16 , V_36 ) ;
return 0 ;
} else if ( V_84 -> V_99 == 1 ) {
F_13 ( V_35 , L_17 , V_36 ) ;
V_84 -> V_99 ++ ;
}
F_10 ( V_84 -> V_26 ) ;
V_87 = F_31 ( V_84 -> V_26 , V_92 , V_93 , V_98 ) ;
F_8 ( V_84 -> V_26 ) ;
if ( V_87 ) {
F_13 ( V_35 , L_18 ,
V_36 , V_87 ) ;
V_84 -> V_99 = 2 ;
} else {
memcpy ( V_84 -> V_100 , V_93 , V_101 ) ;
}
return V_87 ;
}
static int F_32 ( struct V_24 * V_25 ,
T_2 * V_102 ,
T_1 V_103 )
{
struct V_83 * V_84 =
(struct V_83 * ) V_25 -> V_85 ;
T_1 V_104 = V_84 -> V_91 ;
T_1 V_105 , V_4 , V_86 ;
T_1 V_106 ;
int V_87 ;
V_106 = ( ( V_102 [ 1 ] >> 4 ) & 0xf ) ;
V_105 = V_103 / V_104 ;
if ( V_103 % V_104 )
V_105 ++ ;
V_4 = ( V_105 * V_104 | ( V_106 << 12 ) ) ;
V_86 = V_105 * V_104 ;
V_87 = F_30 ( V_25 ,
V_4 ,
( T_2 * ) V_102 ,
V_86 ) ;
if ( V_87 )
F_13 ( V_35 , L_19 ,
V_36 , V_87 ) ;
F_13 ( V_107 , L_20 , V_36 ) ;
return V_87 ;
}
int F_33 ( struct V_24 * V_25 ,
T_2 * V_102 ,
T_1 V_86 )
{
int V_87 = - V_108 ;
if ( ! V_86 ) {
F_13 ( V_35 , L_21 , V_36 ) ;
return V_87 ;
}
V_87 = F_28 ( V_25 ,
V_86 ,
V_86 ,
( T_2 * ) V_102 ) ;
if ( V_87 )
F_13 ( V_35 , L_22 , V_36 ,
V_87 ) ;
return V_87 ;
}
static int F_34 ( struct V_24 * V_25 ,
struct V_20 * V_26 )
{
struct V_83 * V_109 ;
int V_87 = - V_110 ;
V_109 = F_35 ( sizeof( * V_109 ) , V_111 ) ;
if ( ! V_109 )
return V_87 ;
V_25 -> V_85 = V_109 ;
F_10 ( V_26 ) ;
V_26 -> V_112 = 100 ;
V_87 = F_36 ( V_26 ) ;
if ( V_87 ) {
F_13 ( V_35 , L_23 , V_36 ) ;
F_8 ( V_26 ) ;
return V_87 ;
}
F_13 ( V_88 , L_24 , V_36 ) ;
V_109 -> V_26 = V_26 ;
V_25 -> V_113 = & V_26 -> V_84 ;
F_37 ( V_26 , V_25 ) ;
V_87 = F_20 ( V_25 ) ;
if ( V_87 ) {
F_13 ( V_35 , L_25 , V_36 ) ;
goto V_114;
}
F_13 ( V_88 , L_26 , V_36 ) ;
V_87 = F_38 ( V_25 ) ;
if ( V_87 ) {
F_13 ( V_35 , L_27 , V_36 ) ;
goto V_114;
}
F_8 ( V_26 ) ;
V_25 -> V_115 = F_32 ;
V_25 -> V_116 = F_33 ;
V_25 -> V_117 = V_118 ;
V_25 -> V_119 = V_120 ;
#ifdef F_39
V_25 -> V_121 = V_122 ;
#endif
return V_87 ;
V_114:
F_40 ( V_26 ) ;
F_8 ( V_26 ) ;
return V_87 ;
}
static int F_41 ( struct V_20 * V_26 ,
const struct V_123 * V_124 )
{
struct V_24 * V_25 ;
F_13 ( V_88 , L_28 , V_36 ) ;
V_25 = F_42 () ;
if ( ! V_25 ) {
F_13 ( V_35 , L_29 ,
V_36 ) ;
return 1 ;
}
if ( F_34 ( V_25 , V_26 ) ) {
F_13 ( V_35 , L_30 ,
V_36 ) ;
goto V_114;
}
if ( F_43 ( V_25 -> V_125 ) ) {
F_13 ( V_35 , L_31 , V_36 ) ;
F_10 ( V_26 ) ;
F_40 ( V_26 ) ;
F_8 ( V_26 ) ;
goto V_114;
}
F_10 ( V_26 ) ;
if ( F_44 ( V_26 , F_6 ) ) {
F_13 ( V_35 , L_32 , V_36 ) ;
F_8 ( V_26 ) ;
goto V_114;
}
F_8 ( V_26 ) ;
F_13 ( V_88 , L_33 , V_36 ) ;
return 0 ;
V_114:
F_45 ( V_25 ) ;
F_13 ( V_35 , L_34 , V_36 ) ;
return 1 ;
}
static void F_46 ( struct V_20 * V_26 )
{
struct V_24 * V_25 = F_7 ( V_26 ) ;
struct V_83 * V_84 ;
if ( ! V_25 )
return;
V_84 = (struct V_83 * ) V_25 -> V_85 ;
V_84 -> V_99 = 2 ;
F_47 ( V_25 ) ;
F_10 ( V_26 ) ;
F_48 ( V_26 ) ;
F_40 ( V_26 ) ;
F_45 ( V_25 ) ;
F_11 ( V_26 ) ;
F_8 ( V_26 ) ;
}
static int F_49 ( struct V_113 * V_84 )
{
return - V_126 ;
}
static int F_50 ( struct V_113 * V_84 )
{
return - V_126 ;
}
static int F_51 ( void )
{
F_52 ( & V_127 ) ;
F_13 ( V_88 , L_35 , V_36 ) ;
return 0 ;
}
static void F_53 ( void )
{
F_54 ( & V_127 ) ;
F_13 ( V_90 , L_36 , V_36 ) ;
}
