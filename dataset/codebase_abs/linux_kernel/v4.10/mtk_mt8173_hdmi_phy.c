static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
void T_2 * V_5 = V_2 -> V_6 + V_3 ;
T_1 V_7 ;
V_7 = F_2 ( V_5 ) ;
V_7 &= ~ V_4 ;
F_3 ( V_7 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
void T_2 * V_5 = V_2 -> V_6 + V_3 ;
T_1 V_7 ;
V_7 = F_2 ( V_5 ) ;
V_7 |= V_4 ;
F_3 ( V_7 , V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_8 , T_1 V_9 )
{
void T_2 * V_5 = V_2 -> V_6 + V_3 ;
T_1 V_7 ;
V_7 = F_2 ( V_5 ) ;
V_7 = ( V_7 & ~ V_9 ) | ( V_8 & V_9 ) ;
F_3 ( V_7 , V_5 ) ;
}
static inline struct V_1 * F_6 ( struct V_10 * V_11 )
{
return F_7 ( V_11 , struct V_1 , V_12 ) ;
}
static int F_8 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_6 ( V_11 ) ;
F_9 ( V_2 -> V_13 , L_1 , V_14 ) ;
F_4 ( V_2 , V_15 , V_16 ) ;
F_4 ( V_2 , V_17 , V_18 ) ;
F_1 ( V_2 , V_19 , V_20 ) ;
F_4 ( V_2 , V_15 , V_21 ) ;
F_10 ( 100 , 150 ) ;
F_4 ( V_2 , V_17 , V_22 ) ;
F_10 ( 100 , 150 ) ;
F_4 ( V_2 , V_15 , V_23 ) ;
F_4 ( V_2 , V_15 , V_24 ) ;
return 0 ;
}
static void F_11 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_6 ( V_11 ) ;
F_9 ( V_2 -> V_13 , L_1 , V_14 ) ;
F_1 ( V_2 , V_15 , V_24 ) ;
F_1 ( V_2 , V_15 , V_23 ) ;
F_10 ( 100 , 150 ) ;
F_1 ( V_2 , V_17 , V_22 ) ;
F_10 ( 100 , 150 ) ;
F_1 ( V_2 , V_15 , V_21 ) ;
F_1 ( V_2 , V_17 , V_18 ) ;
F_1 ( V_2 , V_15 , V_16 ) ;
F_10 ( 100 , 150 ) ;
}
static int F_12 ( struct V_10 * V_11 , unsigned long V_25 ,
unsigned long V_26 )
{
struct V_1 * V_2 = F_6 ( V_11 ) ;
unsigned int V_27 ;
unsigned int div ;
unsigned int V_28 ;
unsigned int V_29 ;
unsigned int V_30 ;
F_9 ( V_2 -> V_13 , L_2 , V_14 ,
V_25 , V_26 ) ;
if ( V_25 <= 27000000 ) {
V_27 = 0 ;
div = 3 ;
} else if ( V_25 <= 74250000 ) {
V_27 = 1 ;
div = 2 ;
} else {
V_27 = 1 ;
div = 1 ;
}
F_5 ( V_2 , V_17 ,
( V_27 << V_31 ) , V_32 ) ;
F_4 ( V_2 , V_17 , V_18 ) ;
F_5 ( V_2 , V_17 ,
( 0x1 << V_33 ) | ( 0x1 << V_34 ) ,
V_35 | V_36 ) ;
F_5 ( V_2 , V_15 ,
( div << V_37 ) , V_38 ) ;
F_5 ( V_2 , V_17 ,
( 0x1 << V_39 ) | ( 19 << V_40 ) ,
V_41 | V_42 ) ;
F_5 ( V_2 , V_15 ,
( 0x2 << V_43 ) , V_44 ) ;
F_5 ( V_2 , V_17 ,
( 0xc << V_45 ) | ( 0x2 << V_46 ) |
( 0x1 << V_47 ) ,
V_48 | V_49 |
V_50 ) ;
if ( V_25 < 165000000 ) {
F_1 ( V_2 , V_19 ,
V_51 ) ;
V_28 = 0x3 ;
V_30 = 0x0 ;
V_29 = V_2 -> V_52 ;
} else {
F_4 ( V_2 , V_19 ,
V_51 ) ;
V_28 = 0x6 ;
V_30 = 0xf ;
V_29 = V_2 -> V_53 ;
}
F_5 ( V_2 , V_54 ,
( V_28 << V_55 ) |
( V_28 << V_56 ) |
( V_28 << V_57 ) |
( V_28 << V_58 ) ,
V_59 |
V_60 |
V_61 |
V_62 ) ;
F_5 ( V_2 , V_19 ,
( V_30 << V_63 ) ,
V_64 ) ;
F_5 ( V_2 , V_65 ,
( V_2 -> V_66 << V_67 ) |
( V_2 -> V_68 << V_69 ) |
( V_2 -> V_70 << V_71 ) |
( V_2 -> V_72 << V_73 ) ,
V_74 | V_75 |
V_76 | V_77 ) ;
F_5 ( V_2 , V_78 ,
( V_29 << V_79 ) |
( V_29 << V_80 ) |
( V_29 << V_81 ) |
( V_29 << V_82 ) ,
V_83 |
V_84 |
V_85 |
V_86 ) ;
return 0 ;
}
static long F_13 ( struct V_10 * V_11 , unsigned long V_25 ,
unsigned long * V_26 )
{
struct V_1 * V_2 = F_6 ( V_11 ) ;
V_2 -> V_87 = V_25 ;
if ( V_25 <= 74250000 )
* V_26 = V_25 ;
else
* V_26 = V_25 / 2 ;
return V_25 ;
}
static unsigned long F_14 ( struct V_10 * V_11 ,
unsigned long V_26 )
{
struct V_1 * V_2 = F_6 ( V_11 ) ;
return V_2 -> V_87 ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_19 ,
V_88 | V_89 |
V_90 ) ;
F_10 ( 100 , 150 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_19 ,
V_90 | V_89 |
V_88 ) ;
}
static int F_17 ( struct V_91 * V_91 )
{
struct V_1 * V_2 = F_18 ( V_91 ) ;
int V_92 ;
V_92 = F_19 ( V_2 -> V_93 ) ;
if ( V_92 < 0 )
return V_92 ;
F_15 ( V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_91 * V_91 )
{
struct V_1 * V_2 = F_18 ( V_91 ) ;
F_16 ( V_2 ) ;
F_21 ( V_2 -> V_93 ) ;
return 0 ;
}
static int F_22 ( struct V_94 * V_95 )
{
struct V_96 * V_13 = & V_95 -> V_13 ;
struct V_1 * V_2 ;
struct V_97 * V_98 ;
struct V_99 * V_100 ;
const char * V_101 ;
struct V_102 V_103 = {
. V_104 = & V_105 ,
. V_106 = 1 ,
. V_107 = ( const char * const * ) & V_101 ,
. V_108 = V_109 | V_110 ,
} ;
struct V_91 * V_91 ;
struct V_111 * V_111 ;
int V_92 ;
V_2 = F_23 ( V_13 , sizeof( * V_2 ) , V_112 ) ;
if ( ! V_2 )
return - V_113 ;
V_98 = F_24 ( V_95 , V_114 , 0 ) ;
V_2 -> V_6 = F_25 ( V_13 , V_98 ) ;
if ( F_26 ( V_2 -> V_6 ) ) {
V_92 = F_27 ( V_2 -> V_6 ) ;
F_28 ( V_13 , L_3 , V_92 ) ;
return V_92 ;
}
V_100 = F_29 ( V_13 , L_4 ) ;
if ( F_26 ( V_100 ) ) {
V_92 = F_27 ( V_100 ) ;
F_28 ( & V_95 -> V_13 , L_5 ,
V_92 ) ;
return V_92 ;
}
V_101 = F_30 ( V_100 ) ;
V_92 = F_31 ( V_13 -> V_115 , L_6 ,
& V_103 . V_116 ) ;
if ( V_92 < 0 ) {
F_28 ( V_13 , L_7 , V_92 ) ;
return V_92 ;
}
V_2 -> V_12 . V_117 = & V_103 ;
V_2 -> V_93 = F_32 ( V_13 , & V_2 -> V_12 ) ;
if ( F_26 ( V_2 -> V_93 ) ) {
V_92 = F_27 ( V_2 -> V_93 ) ;
F_28 ( V_13 , L_8 , V_92 ) ;
return V_92 ;
}
V_92 = F_33 ( V_13 -> V_115 , L_9 ,
& V_2 -> V_52 ) ;
if ( V_92 < 0 ) {
F_28 ( & V_95 -> V_13 , L_10 , V_92 ) ;
return V_92 ;
}
V_92 = F_33 ( V_13 -> V_115 , L_11 ,
& V_2 -> V_53 ) ;
if ( V_92 < 0 ) {
F_28 ( & V_95 -> V_13 , L_12 , V_92 ) ;
return V_92 ;
}
F_34 ( V_13 , L_13 ) ;
V_2 -> V_66 = 0x30 ;
V_2 -> V_68 = 0x30 ;
V_2 -> V_70 = 0x30 ;
V_2 -> V_72 = 0x30 ;
V_91 = F_35 ( V_13 , NULL , & V_118 ) ;
if ( F_26 ( V_91 ) ) {
F_28 ( V_13 , L_14 ) ;
return F_27 ( V_91 ) ;
}
F_36 ( V_91 , V_2 ) ;
V_111 = F_37 ( V_13 , V_119 ) ;
if ( F_26 ( V_111 ) )
return F_27 ( V_111 ) ;
V_2 -> V_13 = V_13 ;
return F_38 ( V_13 -> V_115 , V_120 ,
V_2 -> V_93 ) ;
}
static int F_39 ( struct V_94 * V_95 )
{
return 0 ;
}
