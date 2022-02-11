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
} else {
V_18 = F_2 ( V_7 ,
V_69 ,
( V_30 | V_70 ) ) ;
if ( V_18 ) {
F_13 ( V_35 ,
L_9 ,
V_36 , V_18 ) ;
return;
}
V_17 -> V_37 . V_47 = V_71 ;
V_17 -> V_49 -> V_50 ( V_17 , & V_17 -> V_37 ) ;
}
}
if ( F_15 ( V_7 ) )
clock = 50000000 ;
else
clock = V_7 -> V_72 . V_73 ;
if ( clock > V_17 -> V_74 )
clock = V_17 -> V_74 ;
V_17 -> V_37 . clock = clock ;
V_17 -> V_49 -> V_50 ( V_17 , & V_17 -> V_37 ) ;
if ( V_7 -> V_17 -> V_67 & V_75 ) {
V_18 = F_2 ( V_7 ,
V_76 ,
( V_77 |
V_78 ) ) ;
if ( V_18 ) {
F_13 ( V_35 , L_10 ,
V_36 , V_18 ) ;
return;
}
V_17 -> V_37 . V_45 = V_79 ;
V_17 -> V_49 -> V_50 ( V_17 , & V_17 -> V_37 ) ;
}
}
static void F_16 ( struct V_24 * V_25 , T_1 V_80 )
{
struct V_81 * V_82 =
(struct V_81 * ) V_25 -> V_83 ;
struct V_22 * V_17 = V_82 -> V_26 -> V_7 -> V_17 ;
T_1 clock ;
clock = V_80 * 1000 ;
if ( clock > V_17 -> V_74 )
clock = V_17 -> V_74 ;
V_17 -> V_37 . clock = clock ;
V_17 -> V_49 -> V_50 ( V_17 , & V_17 -> V_37 ) ;
}
static int F_17 ( struct V_24 * V_25 , T_1 V_84 )
{
struct V_81 * V_82 =
(struct V_81 * ) V_25 -> V_83 ;
int V_85 ;
F_13 ( V_86 , L_11 , V_36 ) ;
V_85 = F_18 ( V_82 -> V_26 , V_84 ) ;
V_82 -> V_26 -> V_87 = 256 ;
F_13 ( V_88 ,
L_12 , V_36 , V_84 ) ;
return V_85 ;
}
static int F_19 ( struct V_24 * V_25 )
{
struct V_81 * V_82 =
(struct V_81 * ) V_25 -> V_83 ;
int V_85 = 0 ;
F_16 ( V_25 , 50000 ) ;
V_82 -> V_89 = 256 ;
V_85 = F_17 ( V_25 , V_82 -> V_89 ) ;
if ( V_85 )
F_13 ( V_35 ,
L_13 , V_36 ) ;
return V_85 ;
}
int F_20 ( struct V_24 * V_25 ,
T_1 V_90 ,
T_2 * V_91 )
{
struct V_81 * V_82 =
(struct V_81 * ) V_25 -> V_83 ;
T_2 V_92 = 0 ;
int V_85 ;
F_10 ( V_82 -> V_26 ) ;
if ( V_92 == 0 )
* V_91 = F_21 ( V_82 -> V_26 , V_90 , & V_85 ) ;
else
* V_91 = F_22 ( V_82 -> V_26 , V_90 , & V_85 ) ;
F_8 ( V_82 -> V_26 ) ;
return V_85 ;
}
int F_23 ( struct V_24 * V_25 ,
T_2 V_23 ,
T_1 V_90 ,
T_2 * V_91 )
{
struct V_81 * V_82 =
(struct V_81 * ) V_25 -> V_83 ;
int V_85 = 0 ;
F_10 ( V_82 -> V_26 ) ;
if ( V_23 == 0 )
F_24 ( V_82 -> V_26 , * V_91 , V_90 , & V_85 ) ;
else
F_25 ( V_82 -> V_26 , * V_91 , V_90 , & V_85 ) ;
F_8 ( V_82 -> V_26 ) ;
return V_85 ;
}
void F_26 ( struct V_24 * V_25 , T_2 V_93 )
{
int V_85 ;
V_85 = F_23 ( V_25 ,
1 ,
( V_94 |
V_95 ) ,
& V_93 ) ;
if ( V_85 )
F_13 ( V_35 , L_14 , V_36 ) ;
}
static int F_27 ( struct V_24 * V_25 ,
T_1 V_90 ,
T_1 V_96 ,
T_2 * V_91 )
{
struct V_81 * V_82 =
(struct V_81 * ) V_25 -> V_83 ;
T_1 V_85 ;
F_10 ( V_82 -> V_26 ) ;
V_85 = F_28 ( V_82 -> V_26 , V_91 , V_90 , V_96 ) ;
F_8 ( V_82 -> V_26 ) ;
if ( V_85 != 0 )
F_13 ( V_35 , L_15 , V_36 ) ;
return V_85 ;
}
int F_29 ( struct V_24 * V_25 ,
T_1 V_90 ,
T_2 * V_91 ,
T_1 V_96 )
{
struct V_81 * V_82 =
(struct V_81 * ) V_25 -> V_83 ;
int V_85 ;
if ( V_82 -> V_97 > 1 ) {
F_13 ( V_35 , L_16 , V_36 ) ;
return 0 ;
} else if ( V_82 -> V_97 == 1 ) {
F_13 ( V_35 , L_17 , V_36 ) ;
V_82 -> V_97 ++ ;
}
F_10 ( V_82 -> V_26 ) ;
V_85 = F_30 ( V_82 -> V_26 , V_90 , V_91 , V_96 ) ;
F_8 ( V_82 -> V_26 ) ;
if ( V_85 ) {
F_13 ( V_35 , L_18 ,
V_36 , V_85 ) ;
V_82 -> V_97 = 2 ;
} else {
memcpy ( V_82 -> V_98 , V_91 , V_99 ) ;
}
return V_85 ;
}
static int F_31 ( struct V_24 * V_25 ,
T_2 * V_100 ,
T_1 V_101 )
{
struct V_81 * V_82 =
(struct V_81 * ) V_25 -> V_83 ;
T_1 V_102 = V_82 -> V_89 ;
T_1 V_103 , V_4 , V_84 ;
T_1 V_104 ;
int V_85 ;
V_104 = ( ( V_100 [ 1 ] >> 4 ) & 0xf ) ;
V_103 = V_101 / V_102 ;
if ( V_101 % V_102 )
V_103 ++ ;
V_4 = ( V_103 * V_102 | ( V_104 << 12 ) ) ;
V_84 = V_103 * V_102 ;
V_85 = F_29 ( V_25 ,
V_4 ,
( T_2 * ) V_100 ,
V_84 ) ;
if ( V_85 )
F_13 ( V_35 , L_19 ,
V_36 , V_85 ) ;
F_13 ( V_105 , L_20 , V_36 ) ;
return V_85 ;
}
int F_32 ( struct V_24 * V_25 ,
T_2 * V_100 ,
T_1 V_84 )
{
int V_85 = - V_106 ;
if ( ! V_84 ) {
F_13 ( V_35 , L_21 , V_36 ) ;
return V_85 ;
}
V_85 = F_27 ( V_25 ,
V_84 ,
V_84 ,
( T_2 * ) V_100 ) ;
if ( V_85 )
F_13 ( V_35 , L_22 , V_36 ,
V_85 ) ;
return V_85 ;
}
static int F_33 ( struct V_24 * V_25 ,
struct V_20 * V_26 )
{
struct V_81 * V_107 ;
int V_85 = - V_108 ;
V_107 = F_34 ( sizeof( * V_107 ) , V_109 ) ;
if ( ! V_107 )
return V_85 ;
V_25 -> V_83 = V_107 ;
F_10 ( V_26 ) ;
V_26 -> V_110 = 100 ;
V_85 = F_35 ( V_26 ) ;
if ( V_85 ) {
F_13 ( V_35 , L_23 , V_36 ) ;
F_8 ( V_26 ) ;
return V_85 ;
}
F_13 ( V_86 , L_24 , V_36 ) ;
V_107 -> V_26 = V_26 ;
V_25 -> V_111 = & V_26 -> V_82 ;
F_36 ( V_26 , V_25 ) ;
V_85 = F_19 ( V_25 ) ;
if ( V_85 ) {
F_13 ( V_35 , L_25 , V_36 ) ;
goto V_112;
}
F_13 ( V_86 , L_26 , V_36 ) ;
V_85 = F_37 ( V_25 ) ;
if ( V_85 ) {
F_13 ( V_35 , L_27 , V_36 ) ;
goto V_112;
}
F_8 ( V_26 ) ;
V_25 -> V_113 = F_31 ;
V_25 -> V_114 = F_32 ;
V_25 -> V_115 = V_116 ;
V_25 -> V_117 = V_118 ;
#ifdef F_38
V_25 -> V_119 = V_120 ;
#endif
return V_85 ;
V_112:
F_39 ( V_26 ) ;
F_8 ( V_26 ) ;
return V_85 ;
}
static int F_40 ( struct V_20 * V_26 ,
const struct V_121 * V_122 )
{
struct V_24 * V_25 ;
F_13 ( V_86 , L_28 , V_36 ) ;
V_25 = F_41 () ;
if ( ! V_25 ) {
F_13 ( V_35 , L_29 ,
V_36 ) ;
return 1 ;
}
if ( F_33 ( V_25 , V_26 ) ) {
F_13 ( V_35 , L_30 ,
V_36 ) ;
goto V_112;
}
if ( F_42 ( V_25 -> V_123 ) ) {
F_13 ( V_35 , L_31 , V_36 ) ;
F_10 ( V_26 ) ;
F_39 ( V_26 ) ;
F_8 ( V_26 ) ;
goto V_112;
}
F_10 ( V_26 ) ;
if ( F_43 ( V_26 , F_6 ) ) {
F_13 ( V_35 , L_32 , V_36 ) ;
F_8 ( V_26 ) ;
goto V_112;
}
F_8 ( V_26 ) ;
F_13 ( V_86 , L_33 , V_36 ) ;
return 0 ;
V_112:
F_44 ( V_25 ) ;
F_13 ( V_35 , L_34 , V_36 ) ;
return 1 ;
}
static void F_45 ( struct V_20 * V_26 )
{
struct V_24 * V_25 = F_7 ( V_26 ) ;
struct V_81 * V_82 ;
if ( ! V_25 )
return;
V_82 = (struct V_81 * ) V_25 -> V_83 ;
V_82 -> V_97 = 2 ;
F_46 ( V_25 ) ;
F_10 ( V_26 ) ;
F_47 ( V_26 ) ;
F_39 ( V_26 ) ;
F_44 ( V_25 ) ;
F_11 ( V_26 ) ;
F_8 ( V_26 ) ;
}
static int F_48 ( struct V_111 * V_82 )
{
return - V_124 ;
}
static int F_49 ( struct V_111 * V_82 )
{
return - V_124 ;
}
static int F_50 ( void )
{
F_51 ( & V_125 ) ;
F_13 ( V_86 , L_35 , V_36 ) ;
return 0 ;
}
static void F_52 ( void )
{
F_53 ( & V_125 ) ;
F_13 ( V_88 , L_36 , V_36 ) ;
}
