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
V_22 = V_4 -> V_6 -> V_38 * ( V_4 -> V_6 -> V_39 / 8 ) ;
V_22 = F_14 ( 16 , V_22 ) ;
V_25 = V_4 -> V_6 -> V_38 * V_4 -> V_6 -> V_39 / 8 ;
V_25 = F_14 ( 16 , V_25 ) ;
F_13 ( F_15 ( V_40 , V_22 ) |
F_15 ( V_41 , V_25 ) ,
V_27 -> V_36 + V_42 ) ;
V_22 = F_16 ( V_27 -> V_36 + V_43 ) ;
V_22 &= ~ V_44 ;
V_22 |= F_15 ( V_45 ,
V_4 -> V_6 -> V_39 / 16 ) ;
F_13 ( V_22 , V_27 -> V_36 + V_43 ) ;
}
static struct V_1 * F_17 ( struct V_26 * V_27 )
{
struct V_46 * V_28 = V_27 -> V_28 ;
struct V_1 * V_2 ;
int V_23 = 0 ;
V_2 = F_18 ( V_28 -> V_28 , sizeof( * V_2 ) , V_47 ) ;
if ( ! V_2 ) {
F_10 ( L_6 ) ;
return F_19 ( - V_48 ) ;
}
V_23 = F_20 ( V_28 , V_2 , 1 , & V_49 ,
V_50 ,
F_21 ( V_50 ) ,
V_51 ,
NULL ) ;
if ( V_23 ) {
F_10 ( L_7 , V_23 ) ;
return F_19 ( V_23 ) ;
}
F_22 ( V_2 , & V_52 ) ;
return V_2 ;
}
static void F_23 ( struct V_7 * V_8 )
{
unsigned int V_22 ;
struct V_26 * V_27 = V_8 -> V_28 -> V_29 ;
F_24 ( V_27 , V_53 ) ;
V_22 = F_16 ( V_27 -> V_36 + V_54 ) ;
V_22 &= ~ V_55 ;
V_22 &= ~ V_56 ;
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
F_24 ( V_27 , V_57 ) ;
V_22 = F_16 ( V_27 -> V_36 + V_54 ) ;
V_22 &= ~ V_55 ;
V_22 &= ~ V_56 ;
V_22 |= F_25 ( 0 ) ;
V_22 |= F_26 ( 0 ) ;
F_27 ( V_27 , V_22 ) ;
}
static unsigned int F_31 ( void )
{
unsigned int V_58 = 0 ;
struct V_59 V_60 = { 0 } ;
V_58 |= F_15 ( V_61 , 0 ) ;
V_58 |= F_15 ( V_62 , 1 ) ;
V_58 |= F_15 ( V_63 , 0 ) ;
V_58 |= F_15 ( V_64 , V_60 . V_65 ) ;
V_58 |= F_15 ( V_66 , V_60 . V_67 ) ;
V_58 |= F_15 ( V_68 , V_60 . V_69 ) ;
V_58 |= F_15 ( V_70 , V_60 . V_71 ) ;
return V_58 ;
}
static void F_32 ( struct V_46 * V_28 , unsigned long V_60 )
{
T_1 V_72 ;
struct V_26 * V_27 = V_28 -> V_29 ;
V_72 = F_16 ( V_27 -> V_36 + V_73 ) ;
V_72 &= ~ ( F_33 ( 1 ) ) ;
F_13 ( V_72 , V_27 -> V_36 + V_73 ) ;
V_72 = F_34 ( 1 ) | F_35 ( 1 ) ;
F_13 ( V_72 , V_27 -> V_36 + V_73 ) ;
F_13 ( V_60 , V_27 -> V_36 + V_73 ) ;
F_36 ( 1000 , 2000 ) ;
V_72 = V_60 & ~ ( F_35 ( 1 ) ) ;
F_13 ( V_72 , V_27 -> V_36 + V_73 ) ;
F_36 ( 1000 , 2000 ) ;
V_72 &= ~ ( F_34 ( 1 ) ) ;
F_13 ( V_72 , V_27 -> V_36 + V_73 ) ;
F_36 ( 1000 , 2000 ) ;
V_72 |= F_33 ( 1 ) ;
F_13 ( V_72 , V_27 -> V_36 + V_73 ) ;
}
static void F_37 ( unsigned long V_74 , unsigned long V_75 ,
T_1 * V_76 , T_1 * V_77 )
{
int V_78 ;
int V_79 = F_21 ( V_80 ) ;
for ( V_78 = 0 ; V_78 < V_79 ; V_78 ++ ) {
if ( V_80 [ V_78 ] . V_19 == V_74 &&
V_80 [ V_78 ] . V_20 == V_75 ) {
* V_76 = V_80 [ V_78 ] . V_81 ;
* V_77 = V_80 [ V_78 ] . V_82 ;
return;
}
}
* V_76 = V_83 ;
* V_77 = V_84 ;
}
static unsigned int F_38 ( struct V_46 * V_28 ,
struct V_85 * V_86 ,
unsigned int V_87 )
{
unsigned long V_74 , V_75 ;
T_1 V_76 ;
T_1 V_77 ;
struct V_26 * V_27 = V_28 -> V_29 ;
V_74 = V_86 -> V_19 ;
V_75 = V_86 -> V_20 ;
F_37 ( V_74 , V_75 , & V_76 , & V_77 ) ;
F_13 ( V_77 , V_27 -> V_36 + V_88 ) ;
F_32 ( V_28 , V_76 ) ;
F_13 ( F_15 ( V_89 , 0 ) |
F_15 ( V_90 , 0 ) ,
V_27 -> V_36 + V_91 ) ;
F_13 ( F_15 ( V_92 , V_75 - 1 ) |
F_15 ( V_93 , V_74 - 1 ) ,
V_27 -> V_36 + V_94 ) ;
V_87 &= ~ V_95 ;
V_87 &= ~ V_96 ;
V_87 |= F_39 ( V_97 ) ;
V_87 |= F_40 ( 0 ) ;
F_13 ( V_87 , V_27 -> V_36 + V_43 ) ;
return V_87 ;
}
static void F_41 ( struct V_7 * V_8 )
{
unsigned int V_72 ;
struct V_85 * V_86 = & V_8 -> V_4 -> V_86 ;
struct V_46 * V_28 = V_8 -> V_28 ;
struct V_26 * V_27 = V_28 -> V_29 ;
int V_38 = V_86 -> V_98 - V_86 -> V_99 ;
int V_100 = V_86 -> V_101 - V_86 -> V_102 ;
F_13 ( F_31 () , V_27 -> V_36 + V_103 ) ;
F_13 ( F_15 ( V_104 , V_86 -> V_105 - 1 ) |
F_15 ( V_106 , V_86 -> V_19 - 1 ) ,
V_27 -> V_36 + V_107 ) ;
F_13 ( F_15 ( V_108 , V_38 ) |
F_15 ( V_109 , V_86 -> V_99 - 1 ) ,
V_27 -> V_36 + V_110 ) ;
F_13 ( F_15 ( V_111 , V_86 -> V_112 - 1 ) |
F_15 ( V_113 , V_86 -> V_20 - 1 ) ,
V_27 -> V_36 + V_114 ) ;
F_13 ( F_15 ( V_115 , V_100 ) |
F_15 ( V_116 , V_86 -> V_102 - 1 ) ,
V_27 -> V_36 + V_117 ) ;
V_72 = F_15 ( V_118 , 0 ) ;
V_72 |= F_15 ( V_119 , 0 ) ;
V_72 |= F_42 ( 1 ) ;
V_72 |= F_43 ( 1 ) ;
F_38 ( V_28 , V_86 , V_72 ) ;
}
static void F_44 ( struct V_7 * V_8 ,
struct V_9 * V_21 )
{
unsigned int V_22 ;
struct V_46 * V_28 = V_8 -> V_28 ;
struct V_26 * V_27 = V_28 -> V_29 ;
F_24 ( V_27 , V_53 ) ;
V_22 = F_16 ( V_27 -> V_36 + V_54 ) ;
V_22 &= ~ V_56 ;
V_22 &= ~ V_55 ;
V_22 |= F_26 ( 1 ) ;
V_22 |= F_25 ( 1 ) ;
F_27 ( V_27 , V_22 ) ;
}
static void F_45 ( struct V_7 * V_8 ,
struct V_9 * V_21 )
{
unsigned long V_120 ;
F_46 ( & V_8 -> V_28 -> V_121 , V_120 ) ;
if ( V_8 -> V_4 -> V_122 )
F_47 ( V_8 , V_8 -> V_4 -> V_122 ) ;
V_8 -> V_4 -> V_122 = NULL ;
F_48 ( & V_8 -> V_28 -> V_121 , V_120 ) ;
}
int F_49 ( struct V_26 * V_27 )
{
struct V_46 * V_28 = V_27 -> V_28 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
int V_23 ;
V_2 = F_17 ( V_27 ) ;
if ( F_3 ( V_2 ) ) {
F_10 ( L_8 , F_4 ( V_2 ) ) ;
return F_4 ( V_2 ) ;
}
V_8 = F_18 ( V_28 -> V_28 , sizeof( * V_8 ) , V_47 ) ;
if ( ! V_8 ) {
F_10 ( L_9 ) ;
return - V_48 ;
}
V_23 = F_50 ( V_28 , V_8 , V_2 ,
NULL , & V_123 , NULL ) ;
if ( V_23 ) {
F_10 ( L_10 , V_23 ) ;
return V_23 ;
}
V_23 = F_51 ( V_8 , 256 ) ;
if ( V_23 ) {
F_10 ( L_11 , V_23 ) ;
return V_23 ;
}
F_52 ( V_8 , & V_124 ) ;
return 0 ;
}
