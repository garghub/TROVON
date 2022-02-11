static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_9 * V_10 ;
T_1 V_11 = V_4 -> V_11 >> 16 ;
T_1 V_12 = V_4 -> V_12 >> 16 ;
if ( ! V_8 || ! V_6 )
return 0 ;
V_10 = F_2 ( V_4 -> V_4 , V_8 ) ;
if ( F_3 ( V_10 ) )
return F_4 ( V_10 ) ;
if ( V_11 != V_4 -> V_13 || V_12 != V_4 -> V_14 ) {
F_5 ( L_1 ) ;
return - V_15 ;
}
if ( V_4 -> V_16 < 0 || V_4 -> V_17 < 0 ) {
F_5 ( L_2 ) ;
return - V_15 ;
}
if ( V_4 -> V_16 + V_4 -> V_13 >
V_10 -> V_18 . V_19 ||
V_4 -> V_17 + V_4 -> V_14 >
V_10 -> V_18 . V_20 ) {
F_5 ( L_3 ) ;
return - V_15 ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_21 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_22 ;
int V_23 ;
T_2 V_24 = 0 ;
unsigned int V_25 ;
struct V_26 * V_27 = V_2 -> V_28 -> V_29 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
if ( ! V_4 -> V_6 )
return;
V_31 = F_7 ( V_4 -> V_6 ) ;
V_33 = F_8 ( V_31 -> V_34 ) ;
V_23 = F_9 ( & V_33 -> V_33 , true , false , NULL ) ;
if ( V_23 ) {
F_10 ( L_4 , V_23 ) ;
return;
}
V_23 = F_11 ( V_33 , V_35 , & V_24 ) ;
F_12 ( & V_33 -> V_33 ) ;
if ( V_23 ) {
F_10 ( L_5 , V_23 ) ;
return;
}
F_13 ( V_24 , V_27 -> V_36 + V_37 ) ;
V_22 = V_4 -> V_6 -> V_38 * ( V_4 -> V_6 -> V_39 -> V_40 [ 0 ] ) ;
V_22 = F_14 ( 16 , V_22 ) ;
V_25 = V_4 -> V_6 -> V_38 * V_4 -> V_6 -> V_39 -> V_40 [ 0 ] ;
V_25 = F_14 ( 16 , V_25 ) ;
F_13 ( F_15 ( V_41 , V_22 ) |
F_15 ( V_42 , V_25 ) ,
V_27 -> V_36 + V_43 ) ;
V_22 = F_16 ( V_27 -> V_36 + V_44 ) ;
V_22 &= ~ V_45 ;
V_22 |= F_15 ( V_46 ,
V_4 -> V_6 -> V_39 -> V_40 [ 0 ] * 8 / 16 ) ;
F_13 ( V_22 , V_27 -> V_36 + V_44 ) ;
}
static struct V_1 * F_17 ( struct V_26 * V_27 )
{
struct V_47 * V_28 = V_27 -> V_28 ;
struct V_1 * V_2 ;
int V_23 = 0 ;
V_2 = F_18 ( V_28 -> V_28 , sizeof( * V_2 ) , V_48 ) ;
if ( ! V_2 ) {
F_10 ( L_6 ) ;
return F_19 ( - V_49 ) ;
}
V_23 = F_20 ( V_28 , V_2 , 1 , & V_50 ,
V_51 ,
F_21 ( V_51 ) ,
V_52 ,
NULL ) ;
if ( V_23 ) {
F_10 ( L_7 , V_23 ) ;
return F_19 ( V_23 ) ;
}
F_22 ( V_2 , & V_53 ) ;
return V_2 ;
}
static void F_23 ( struct V_7 * V_8 )
{
unsigned int V_22 ;
struct V_26 * V_27 = V_8 -> V_28 -> V_29 ;
F_24 ( V_27 , V_54 ) ;
V_22 = F_16 ( V_27 -> V_36 + V_55 ) ;
V_22 &= ~ V_56 ;
V_22 &= ~ V_57 ;
V_22 |= F_25 ( 1 ) ;
V_22 |= F_26 ( 1 ) ;
F_27 ( V_27 , V_22 ) ;
F_28 ( V_8 ) ;
}
static void F_29 ( struct V_7 * V_8 )
{
unsigned int V_22 ;
struct V_26 * V_27 = V_8 -> V_28 -> V_29 ;
F_30 ( V_8 ) ;
F_24 ( V_27 , V_58 ) ;
V_22 = F_16 ( V_27 -> V_36 + V_55 ) ;
V_22 &= ~ V_56 ;
V_22 &= ~ V_57 ;
V_22 |= F_25 ( 0 ) ;
V_22 |= F_26 ( 0 ) ;
F_27 ( V_27 , V_22 ) ;
}
static unsigned int F_31 ( void )
{
unsigned int V_59 = 0 ;
struct V_60 V_61 = { 0 } ;
V_59 |= F_15 ( V_62 , 0 ) ;
V_59 |= F_15 ( V_63 , 1 ) ;
V_59 |= F_15 ( V_64 , 0 ) ;
V_59 |= F_15 ( V_65 , V_61 . V_66 ) ;
V_59 |= F_15 ( V_67 , V_61 . V_68 ) ;
V_59 |= F_15 ( V_69 , V_61 . V_70 ) ;
V_59 |= F_15 ( V_71 , V_61 . V_72 ) ;
return V_59 ;
}
static void F_32 ( struct V_47 * V_28 , unsigned long V_61 )
{
T_1 V_73 ;
struct V_26 * V_27 = V_28 -> V_29 ;
V_73 = F_16 ( V_27 -> V_36 + V_74 ) ;
V_73 &= ~ ( F_33 ( 1 ) ) ;
F_13 ( V_73 , V_27 -> V_36 + V_74 ) ;
V_73 = F_34 ( 1 ) | F_35 ( 1 ) ;
F_13 ( V_73 , V_27 -> V_36 + V_74 ) ;
F_13 ( V_61 , V_27 -> V_36 + V_74 ) ;
F_36 ( 1000 , 2000 ) ;
V_73 = V_61 & ~ ( F_35 ( 1 ) ) ;
F_13 ( V_73 , V_27 -> V_36 + V_74 ) ;
F_36 ( 1000 , 2000 ) ;
V_73 &= ~ ( F_34 ( 1 ) ) ;
F_13 ( V_73 , V_27 -> V_36 + V_74 ) ;
F_36 ( 1000 , 2000 ) ;
V_73 |= F_33 ( 1 ) ;
F_13 ( V_73 , V_27 -> V_36 + V_74 ) ;
}
static void F_37 ( unsigned long V_75 , unsigned long V_76 ,
T_1 * V_77 , T_1 * V_78 )
{
int V_79 ;
int V_80 = F_21 ( V_81 ) ;
for ( V_79 = 0 ; V_79 < V_80 ; V_79 ++ ) {
if ( V_81 [ V_79 ] . V_19 == V_75 &&
V_81 [ V_79 ] . V_20 == V_76 ) {
* V_77 = V_81 [ V_79 ] . V_82 ;
* V_78 = V_81 [ V_79 ] . V_83 ;
return;
}
}
* V_77 = V_84 ;
* V_78 = V_85 ;
}
static unsigned int F_38 ( struct V_47 * V_28 ,
struct V_86 * V_87 ,
unsigned int V_88 )
{
unsigned long V_75 , V_76 ;
T_1 V_77 ;
T_1 V_78 ;
struct V_26 * V_27 = V_28 -> V_29 ;
V_75 = V_87 -> V_19 ;
V_76 = V_87 -> V_20 ;
F_37 ( V_75 , V_76 , & V_77 , & V_78 ) ;
F_13 ( V_78 , V_27 -> V_36 + V_89 ) ;
F_32 ( V_28 , V_77 ) ;
F_13 ( F_15 ( V_90 , 0 ) |
F_15 ( V_91 , 0 ) ,
V_27 -> V_36 + V_92 ) ;
F_13 ( F_15 ( V_93 , V_76 - 1 ) |
F_15 ( V_94 , V_75 - 1 ) ,
V_27 -> V_36 + V_95 ) ;
V_88 &= ~ V_96 ;
V_88 &= ~ V_97 ;
V_88 |= F_39 ( V_98 ) ;
V_88 |= F_40 ( 0 ) ;
F_13 ( V_88 , V_27 -> V_36 + V_44 ) ;
return V_88 ;
}
static void F_41 ( struct V_7 * V_8 )
{
unsigned int V_73 ;
struct V_86 * V_87 = & V_8 -> V_4 -> V_87 ;
struct V_47 * V_28 = V_8 -> V_28 ;
struct V_26 * V_27 = V_28 -> V_29 ;
int V_38 = V_87 -> V_99 - V_87 -> V_100 ;
int V_101 = V_87 -> V_102 - V_87 -> V_103 ;
F_13 ( F_31 () , V_27 -> V_36 + V_104 ) ;
F_13 ( F_15 ( V_105 , V_87 -> V_106 - 1 ) |
F_15 ( V_107 , V_87 -> V_19 - 1 ) ,
V_27 -> V_36 + V_108 ) ;
F_13 ( F_15 ( V_109 , V_38 ) |
F_15 ( V_110 , V_87 -> V_100 - 1 ) ,
V_27 -> V_36 + V_111 ) ;
F_13 ( F_15 ( V_112 , V_87 -> V_113 - 1 ) |
F_15 ( V_114 , V_87 -> V_20 - 1 ) ,
V_27 -> V_36 + V_115 ) ;
F_13 ( F_15 ( V_116 , V_101 ) |
F_15 ( V_117 , V_87 -> V_103 - 1 ) ,
V_27 -> V_36 + V_118 ) ;
V_73 = F_15 ( V_119 , 0 ) ;
V_73 |= F_15 ( V_120 , 0 ) ;
V_73 |= F_42 ( 1 ) ;
V_73 |= F_43 ( 1 ) ;
F_38 ( V_28 , V_87 , V_73 ) ;
}
static void F_44 ( struct V_7 * V_8 ,
struct V_9 * V_21 )
{
unsigned int V_22 ;
struct V_47 * V_28 = V_8 -> V_28 ;
struct V_26 * V_27 = V_28 -> V_29 ;
F_24 ( V_27 , V_54 ) ;
V_22 = F_16 ( V_27 -> V_36 + V_55 ) ;
V_22 &= ~ V_57 ;
V_22 &= ~ V_56 ;
V_22 |= F_26 ( 1 ) ;
V_22 |= F_25 ( 1 ) ;
F_27 ( V_27 , V_22 ) ;
}
static void F_45 ( struct V_7 * V_8 ,
struct V_9 * V_21 )
{
unsigned long V_121 ;
F_46 ( & V_8 -> V_28 -> V_122 , V_121 ) ;
if ( V_8 -> V_4 -> V_123 )
F_47 ( V_8 , V_8 -> V_4 -> V_123 ) ;
V_8 -> V_4 -> V_123 = NULL ;
F_48 ( & V_8 -> V_28 -> V_122 , V_121 ) ;
}
int F_49 ( struct V_26 * V_27 )
{
struct V_47 * V_28 = V_27 -> V_28 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
int V_23 ;
V_2 = F_17 ( V_27 ) ;
if ( F_3 ( V_2 ) ) {
F_10 ( L_8 , F_4 ( V_2 ) ) ;
return F_4 ( V_2 ) ;
}
V_8 = F_18 ( V_28 -> V_28 , sizeof( * V_8 ) , V_48 ) ;
if ( ! V_8 ) {
F_10 ( L_9 ) ;
return - V_49 ;
}
V_23 = F_50 ( V_28 , V_8 , V_2 ,
NULL , & V_124 , NULL ) ;
if ( V_23 ) {
F_10 ( L_10 , V_23 ) ;
return V_23 ;
}
V_23 = F_51 ( V_8 , 256 ) ;
if ( V_23 ) {
F_10 ( L_11 , V_23 ) ;
return V_23 ;
}
F_52 ( V_8 , & V_125 ) ;
return 0 ;
}
