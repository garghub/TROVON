static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 , T_1 V_6 )
{
F_2 ( V_4 , V_5 + V_2 -> V_7 . V_8 * V_9 , V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_10 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 ;
struct V_13 * V_15 ;
bool V_16 ;
int V_17 = 0 ;
V_16 = V_10 == 90 || V_10 == 270 ;
if ( V_16 == V_2 -> V_18 . V_16 )
return 0 ;
F_4 ( & V_12 -> V_19 ) ;
if ( F_5 ( & V_12 -> V_20 ) ) {
V_17 = - V_21 ;
goto V_22;
}
V_14 = F_6 ( & V_2 -> V_7 ,
V_2 -> V_7 . V_23 ,
V_24 ) ;
V_15 = F_6 ( & V_2 -> V_7 ,
V_2 -> V_7 . V_23 ,
V_25 ) ;
F_4 ( & V_2 -> V_7 . V_19 ) ;
if ( V_16 ) {
V_15 -> V_26 = V_14 -> V_27 ;
V_15 -> V_27 = V_14 -> V_26 ;
} else {
V_15 -> V_26 = V_14 -> V_26 ;
V_15 -> V_27 = V_14 -> V_27 ;
}
V_2 -> V_18 . V_16 = V_16 ;
F_7 ( & V_2 -> V_7 . V_19 ) ;
V_22:
F_7 ( & V_12 -> V_19 ) ;
return V_17 ;
}
static int F_8 ( struct V_28 * V_29 )
{
struct V_1 * V_2 =
F_9 ( V_29 -> V_30 , struct V_1 , V_31 ) ;
unsigned int V_10 ;
T_1 V_18 = 0 ;
int V_17 ;
V_10 = V_2 -> V_18 . V_31 . V_16 ? V_2 -> V_18 . V_31 . V_16 -> V_32 : 0 ;
V_17 = F_3 ( V_2 , V_10 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_2 -> V_18 . V_31 . V_33 -> V_32 )
V_18 |= F_10 ( V_34 ) ;
if ( V_2 -> V_18 . V_31 . V_35 && V_2 -> V_18 . V_31 . V_35 -> V_32 )
V_18 |= F_10 ( V_36 ) ;
if ( V_10 == 180 || V_10 == 270 )
V_18 ^= F_10 ( V_34 ) | F_10 ( V_36 ) ;
F_11 ( & V_2 -> V_18 . V_19 ) ;
V_2 -> V_18 . V_37 = V_18 ;
F_12 ( & V_2 -> V_18 . V_19 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_7 . V_39 ;
unsigned int V_40 ;
F_14 ( & V_2 -> V_18 . V_19 ) ;
if ( V_2 -> V_7 . V_8 != 0 ) {
V_40 = 0 ;
} else if ( V_39 -> V_41 -> V_42 & V_43 ) {
V_40 = 3 ;
} else if ( V_39 -> V_41 -> V_42 & V_44 ) {
V_40 = 1 ;
} else {
V_40 = 0 ;
}
F_15 ( V_2 , V_40 ) ;
if ( V_40 >= 1 ) {
V_2 -> V_18 . V_31 . V_33 =
F_16 ( & V_2 -> V_31 , & V_45 ,
V_46 , 0 , 1 , 1 , 0 ) ;
}
if ( V_40 == 3 ) {
V_2 -> V_18 . V_31 . V_35 =
F_16 ( & V_2 -> V_31 , & V_45 ,
V_47 , 0 , 1 , 1 , 0 ) ;
V_2 -> V_18 . V_31 . V_16 =
F_16 ( & V_2 -> V_31 , & V_45 ,
V_48 , 0 , 270 , 90 , 0 ) ;
F_17 ( 3 , & V_2 -> V_18 . V_31 . V_33 ) ;
}
if ( V_2 -> V_31 . error ) {
F_18 ( V_39 -> V_49 , L_1 ,
V_2 -> V_7 . V_8 ) ;
return V_2 -> V_31 . error ;
}
return 0 ;
}
static int F_19 ( struct V_50 * V_51 , int V_52 )
{
struct V_1 * V_2 = F_20 ( V_51 ) ;
struct V_38 * V_39 = V_2 -> V_7 . V_39 ;
if ( V_52 )
return 0 ;
F_21 ( V_39 , F_22 ( V_2 -> V_7 . V_8 ) , 0 ) ;
F_21 ( V_39 , V_2 -> V_7 . V_8 * V_9 +
V_53 , 0 ) ;
return 0 ;
}
static void F_23 ( struct V_54 * V_7 )
{
struct V_1 * V_2 = F_24 ( V_7 ) ;
F_25 ( V_2 -> V_55 ) ;
}
static void F_26 ( struct V_54 * V_7 ,
struct V_56 * V_57 ,
struct V_3 * V_4 ,
enum V_58 V_59 )
{
struct V_1 * V_2 = F_20 ( & V_7 -> V_51 ) ;
struct V_38 * V_39 = V_2 -> V_7 . V_39 ;
const struct V_13 * V_15 ;
const struct V_13 * V_14 ;
unsigned int V_60 ;
T_1 V_61 = 0 ;
T_1 V_62 = 0 ;
if ( V_59 == V_63 ) {
const unsigned int V_64 = F_10 ( V_34 )
| F_10 ( V_36 ) ;
unsigned long V_65 ;
F_27 ( & V_2 -> V_18 . V_19 , V_65 ) ;
V_2 -> V_18 . V_66 = ( V_2 -> V_18 . V_66 & ~ V_64 )
| ( V_2 -> V_18 . V_37 & V_64 ) ;
F_28 ( & V_2 -> V_18 . V_19 , V_65 ) ;
V_61 = ( V_2 -> V_67 << V_68 ) | V_2 -> V_61 ;
if ( V_2 -> V_18 . V_66 & F_10 ( V_34 ) )
V_61 |= V_69 ;
if ( V_2 -> V_18 . V_66 & F_10 ( V_36 ) )
V_61 |= V_70 ;
F_1 ( V_2 , V_4 , V_71 , V_61 ) ;
return;
}
V_14 = F_6 ( & V_2 -> V_7 ,
V_2 -> V_7 . V_23 ,
V_24 ) ;
V_15 = F_6 ( & V_2 -> V_7 ,
V_2 -> V_7 . V_23 ,
V_25 ) ;
if ( V_59 == V_72 ) {
const struct V_73 * V_74 = & V_2 -> V_74 ;
const struct V_75 * V_76 = V_2 -> V_76 ;
struct V_77 V_78 = V_2 -> V_78 ;
unsigned int V_18 = V_2 -> V_18 . V_66 ;
unsigned int V_26 = V_14 -> V_26 ;
unsigned int V_27 = V_14 -> V_27 ;
unsigned int V_79 ;
if ( V_57 -> V_80 > 1 )
V_26 = V_57 -> V_81 . V_26 ;
F_1 ( V_2 , V_4 , V_82 , V_83 |
( 0 << V_84 ) |
( V_26 << V_85 ) ) ;
F_1 ( V_2 , V_4 , V_86 , V_83 |
( 0 << V_84 ) |
( V_27 << V_85 ) ) ;
if ( V_57 -> V_87 )
return;
if ( V_18 & F_10 ( V_36 ) && ! V_2 -> V_18 . V_16 )
V_79 = V_74 -> V_26 - V_57 -> V_81 . V_88
- V_57 -> V_81 . V_26 ;
else if ( V_18 & F_10 ( V_34 ) && V_2 -> V_18 . V_16 )
V_79 = V_74 -> V_27 - V_57 -> V_81 . V_88
- V_57 -> V_81 . V_26 ;
else
V_79 = V_57 -> V_81 . V_88 ;
for ( V_60 = 0 ; V_60 < V_74 -> V_89 ; ++ V_60 ) {
unsigned int V_90 = V_60 > 0 ? V_76 -> V_90 : 1 ;
unsigned int V_91 = V_60 > 0 ? V_76 -> V_91 : 1 ;
if ( V_2 -> V_18 . V_16 )
V_78 . V_92 [ V_60 ] += V_79 / V_91
* V_74 -> V_93 [ V_60 ] . V_94 ;
else
V_78 . V_92 [ V_60 ] += V_79 / V_90
* V_76 -> V_95 [ V_60 ] / 8 ;
}
if ( V_18 & F_10 ( V_34 ) ) {
if ( V_2 -> V_18 . V_16 )
V_27 = V_57 -> V_81 . V_26 ;
else
V_27 = V_74 -> V_27 ;
V_78 . V_92 [ 0 ] += ( V_27 - 1 )
* V_74 -> V_93 [ 0 ] . V_94 ;
if ( V_74 -> V_89 > 1 ) {
V_79 = ( V_27 / V_76 -> V_91 - 1 )
* V_74 -> V_93 [ 1 ] . V_94 ;
V_78 . V_92 [ 1 ] += V_79 ;
V_78 . V_92 [ 2 ] += V_79 ;
}
}
if ( V_2 -> V_18 . V_16 && ! ( V_18 & F_10 ( V_36 ) ) ) {
unsigned int V_96 = F_29 ( 0 , ( int ) V_74 -> V_26 - 16 ) ;
for ( V_60 = 0 ; V_60 < V_74 -> V_89 ; ++ V_60 ) {
unsigned int V_90 = V_60 > 0 ? V_76 -> V_90 : 1 ;
V_78 . V_92 [ V_60 ] += V_96 / V_90
* V_76 -> V_95 [ V_60 ] / 8 ;
}
}
if ( V_39 -> V_41 -> V_97 == 3 && V_74 -> V_89 == 3 &&
V_76 -> V_98 )
F_30 ( V_78 . V_92 [ 1 ] , V_78 . V_92 [ 2 ] ) ;
F_1 ( V_2 , V_4 , V_99 , V_78 . V_92 [ 0 ] ) ;
F_1 ( V_2 , V_4 , V_100 , V_78 . V_92 [ 1 ] ) ;
F_1 ( V_2 , V_4 , V_101 , V_78 . V_92 [ 2 ] ) ;
return;
}
if ( ! V_57 -> V_87 ) {
const struct V_73 * V_74 = & V_2 -> V_74 ;
const struct V_75 * V_76 = V_2 -> V_76 ;
V_61 = V_76 -> V_102 << V_103 ;
if ( V_2 -> V_18 . V_16 )
V_61 |= V_104 ;
if ( V_76 -> V_67 )
V_61 |= V_105 ;
if ( V_76 -> V_106 )
V_61 |= V_107 ;
if ( V_76 -> V_98 )
V_61 |= V_108 ;
F_1 ( V_2 , V_4 , V_109 ,
V_74 -> V_93 [ 0 ] . V_94 ) ;
if ( V_74 -> V_89 > 1 )
F_1 ( V_2 , V_4 , V_110 ,
V_74 -> V_93 [ 1 ] . V_94 ) ;
F_1 ( V_2 , V_4 , V_111 , V_76 -> F_30 ) ;
if ( V_39 -> V_41 -> V_42 & V_43 &&
V_2 -> V_7 . V_8 == 0 )
F_1 ( V_2 , V_4 , V_112 ,
V_113 |
( 256 << V_114 ) ) ;
}
if ( V_14 -> V_115 != V_15 -> V_115 )
V_61 |= V_116 ;
V_2 -> V_61 = V_61 ;
F_2 ( V_4 , F_31 ( V_2 -> V_7 . V_8 ) ,
V_117 ) ;
F_2 ( V_4 , V_118 , 0 ) ;
for ( V_60 = 0 ; V_60 < V_39 -> V_41 -> V_119 ; ++ V_60 ) {
struct V_1 * V_120 = V_57 -> V_121 [ V_60 ] ;
if ( ! V_120 )
continue;
V_62 |= ( ! V_57 -> V_122 && V_57 -> V_123 == 1 )
? F_32 ( V_120 -> V_7 . V_8 )
: F_33 ( V_120 -> V_7 . V_8 ) ;
}
if ( V_57 -> V_122 || V_57 -> V_123 > 1 )
V_62 |= V_124 ;
F_1 ( V_2 , V_4 , V_53 , V_62 ) ;
F_2 ( V_4 , F_34 ( V_2 -> V_7 . V_8 ) , 0 ) ;
F_2 ( V_4 , F_22 ( V_2 -> V_7 . V_8 ) ,
V_125 ) ;
}
static unsigned int F_35 ( struct V_54 * V_7 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = F_20 ( & V_7 -> V_51 ) ;
return V_2 -> V_18 . V_16 ? 256 : V_2 -> V_126 ;
}
struct V_1 * F_36 ( struct V_38 * V_39 , unsigned int V_8 )
{
struct V_1 * V_2 ;
char V_127 [ 6 ] ;
int V_17 ;
V_2 = F_37 ( V_39 -> V_49 , sizeof( * V_2 ) , V_128 ) ;
if ( V_2 == NULL )
return F_38 ( - V_129 ) ;
if ( V_39 -> V_41 -> V_97 == 2 ) {
V_2 -> V_126 = V_130 ;
V_2 -> V_131 = V_132 ;
} else {
V_2 -> V_126 = V_133 ;
V_2 -> V_131 = V_134 ;
}
V_2 -> V_7 . V_135 = & V_136 ;
V_2 -> V_7 . type = V_137 ;
V_2 -> V_7 . V_8 = V_8 ;
sprintf ( V_127 , L_2 , V_8 ) ;
V_17 = F_39 ( V_39 , & V_2 -> V_7 , V_127 , 2 , & V_138 ,
V_139 ) ;
if ( V_17 < 0 )
return F_38 ( V_17 ) ;
V_2 -> V_55 = F_40 ( V_39 , V_8 , 64 ) ;
if ( ! V_2 -> V_55 ) {
V_17 = - V_129 ;
goto error;
}
V_17 = F_13 ( V_2 ) ;
if ( V_17 < 0 ) {
F_18 ( V_39 -> V_49 , L_1 ,
V_8 ) ;
goto error;
}
F_41 ( & V_2 -> V_31 ) ;
return V_2 ;
error:
F_42 ( & V_2 -> V_7 ) ;
return F_38 ( V_17 ) ;
}
