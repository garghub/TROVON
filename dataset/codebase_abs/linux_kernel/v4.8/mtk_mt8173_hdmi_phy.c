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
( V_27 << V_28 ) , V_29 ) ;
F_4 ( V_2 , V_17 , V_18 ) ;
F_5 ( V_2 , V_17 ,
( 0x1 << V_30 ) | ( 0x1 << V_31 ) ,
V_32 | V_33 ) ;
F_5 ( V_2 , V_15 ,
( div << V_34 ) , V_35 ) ;
F_5 ( V_2 , V_17 ,
( 0x1 << V_36 ) | ( 19 << V_37 ) ,
V_38 | V_39 ) ;
F_5 ( V_2 , V_15 ,
( 0x2 << V_40 ) , V_41 ) ;
F_5 ( V_2 , V_17 ,
( 0xc << V_42 ) | ( 0x2 << V_43 ) |
( 0x1 << V_44 ) ,
V_45 | V_46 |
V_47 ) ;
F_1 ( V_2 , V_19 , V_48 ) ;
F_5 ( V_2 , V_49 ,
( 0x3 << V_50 ) |
( 0x3 << V_51 ) |
( 0x3 << V_52 ) |
( 0x3 << V_53 ) ,
V_54 |
V_55 |
V_56 |
V_57 ) ;
F_5 ( V_2 , V_19 ,
( 0x0 << V_58 ) , V_59 ) ;
F_5 ( V_2 , V_60 ,
( V_2 -> V_61 << V_62 ) |
( V_2 -> V_63 << V_64 ) |
( V_2 -> V_65 << V_66 ) |
( V_2 -> V_67 << V_68 ) ,
V_69 | V_70 |
V_71 | V_72 ) ;
F_5 ( V_2 , V_73 ,
( V_2 -> V_74 << V_75 ) |
( V_2 -> V_74 << V_76 ) |
( V_2 -> V_74 << V_77 ) |
( V_2 -> V_74 << V_78 ) ,
V_79 | V_80 |
V_81 | V_82 ) ;
return 0 ;
}
static long F_13 ( struct V_10 * V_11 , unsigned long V_25 ,
unsigned long * V_26 )
{
struct V_1 * V_2 = F_6 ( V_11 ) ;
V_2 -> V_83 = V_25 ;
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
return V_2 -> V_83 ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_19 ,
V_84 | V_85 |
V_86 ) ;
F_10 ( 100 , 150 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_19 ,
V_86 | V_85 |
V_84 ) ;
}
static int F_17 ( struct V_87 * V_87 )
{
struct V_1 * V_2 = F_18 ( V_87 ) ;
int V_88 ;
V_88 = F_19 ( V_2 -> V_89 ) ;
if ( V_88 < 0 )
return V_88 ;
F_15 ( V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_87 * V_87 )
{
struct V_1 * V_2 = F_18 ( V_87 ) ;
F_16 ( V_2 ) ;
F_21 ( V_2 -> V_89 ) ;
return 0 ;
}
static int F_22 ( struct V_90 * V_91 )
{
struct V_92 * V_13 = & V_91 -> V_13 ;
struct V_1 * V_2 ;
struct V_93 * V_94 ;
struct V_95 * V_96 ;
const char * V_97 ;
struct V_98 V_99 = {
. V_100 = & V_101 ,
. V_102 = 1 ,
. V_103 = ( const char * const * ) & V_97 ,
. V_104 = V_105 | V_106 ,
} ;
struct V_87 * V_87 ;
struct V_107 * V_107 ;
int V_88 ;
V_2 = F_23 ( V_13 , sizeof( * V_2 ) , V_108 ) ;
if ( ! V_2 )
return - V_109 ;
V_94 = F_24 ( V_91 , V_110 , 0 ) ;
V_2 -> V_6 = F_25 ( V_13 , V_94 ) ;
if ( F_26 ( V_2 -> V_6 ) ) {
V_88 = F_27 ( V_2 -> V_6 ) ;
F_28 ( V_13 , L_3 , V_88 ) ;
return V_88 ;
}
V_96 = F_29 ( V_13 , L_4 ) ;
if ( F_26 ( V_96 ) ) {
V_88 = F_27 ( V_96 ) ;
F_28 ( & V_91 -> V_13 , L_5 ,
V_88 ) ;
return V_88 ;
}
V_97 = F_30 ( V_96 ) ;
V_88 = F_31 ( V_13 -> V_111 , L_6 ,
& V_99 . V_112 ) ;
if ( V_88 < 0 ) {
F_28 ( V_13 , L_7 , V_88 ) ;
return V_88 ;
}
V_2 -> V_12 . V_113 = & V_99 ;
V_2 -> V_89 = F_32 ( V_13 , & V_2 -> V_12 ) ;
if ( F_26 ( V_2 -> V_89 ) ) {
V_88 = F_27 ( V_2 -> V_89 ) ;
F_28 ( V_13 , L_8 , V_88 ) ;
return V_88 ;
}
V_88 = F_33 ( V_13 -> V_111 , L_9 ,
& V_2 -> V_74 ) ;
if ( V_88 < 0 ) {
F_28 ( & V_91 -> V_13 , L_10 , V_88 ) ;
return V_88 ;
}
V_88 = F_33 ( V_13 -> V_111 , L_11 ,
& V_2 -> V_114 ) ;
if ( V_88 < 0 ) {
F_28 ( & V_91 -> V_13 , L_12 , V_88 ) ;
return V_88 ;
}
F_34 ( V_13 , L_13 ) ;
V_2 -> V_61 = 0x30 ;
V_2 -> V_63 = 0x30 ;
V_2 -> V_65 = 0x30 ;
V_2 -> V_67 = 0x30 ;
V_87 = F_35 ( V_13 , NULL , & V_115 ) ;
if ( F_26 ( V_87 ) ) {
F_28 ( V_13 , L_14 ) ;
return F_27 ( V_87 ) ;
}
F_36 ( V_87 , V_2 ) ;
V_107 = F_37 ( V_13 , V_116 ) ;
if ( F_26 ( V_107 ) )
return F_27 ( V_107 ) ;
V_2 -> V_13 = V_13 ;
return F_38 ( V_13 -> V_111 , V_117 ,
V_2 -> V_89 ) ;
}
static int F_39 ( struct V_90 * V_91 )
{
return 0 ;
}
