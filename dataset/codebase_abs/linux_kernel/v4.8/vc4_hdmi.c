static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_4 ) ;
}
static inline struct V_5 *
F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_4 ) ;
}
int F_4 ( struct V_8 * V_9 , void * V_10 )
{
struct V_11 * V_12 = (struct V_11 * ) V_9 -> V_13 ;
struct V_14 * V_15 = V_12 -> V_16 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_15 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < F_6 ( V_20 ) ; V_19 ++ ) {
F_7 ( V_9 , L_1 ,
V_20 [ V_19 ] . V_21 , V_20 [ V_19 ] . V_22 ,
F_8 ( V_20 [ V_19 ] . V_22 ) ) ;
}
for ( V_19 = 0 ; V_19 < F_6 ( V_23 ) ; V_19 ++ ) {
F_7 ( V_9 , L_1 ,
V_23 [ V_19 ] . V_21 , V_23 [ V_19 ] . V_22 ,
F_9 ( V_23 [ V_19 ] . V_22 ) ) ;
}
return 0 ;
}
static void F_10 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_5 ( V_15 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < F_6 ( V_20 ) ; V_19 ++ ) {
F_11 ( L_2 ,
V_20 [ V_19 ] . V_22 , V_20 [ V_19 ] . V_21 ,
F_8 ( V_20 [ V_19 ] . V_22 ) ) ;
}
for ( V_19 = 0 ; V_19 < F_6 ( V_23 ) ; V_19 ++ ) {
F_11 ( L_2 ,
V_23 [ V_19 ] . V_22 , V_23 [ V_19 ] . V_21 ,
F_9 ( V_23 [ V_19 ] . V_22 ) ) ;
}
}
static enum V_24
F_12 ( struct V_6 * V_7 , bool V_25 )
{
struct V_14 * V_15 = V_7 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_15 ) ;
if ( V_18 -> V_26 -> V_27 ) {
if ( F_13 ( V_18 -> V_26 -> V_27 ) ^
V_18 -> V_26 -> V_28 )
return V_29 ;
else
return V_30 ;
}
if ( F_8 ( V_31 ) & V_32 )
return V_29 ;
else
return V_30 ;
}
static void F_14 ( struct V_6 * V_7 )
{
F_15 ( V_7 ) ;
F_16 ( V_7 ) ;
}
static int F_17 ( struct V_6 * V_7 )
{
struct V_5 * V_33 =
F_3 ( V_7 ) ;
struct V_2 * V_3 = V_33 -> V_3 ;
struct V_1 * V_34 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_7 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_15 ) ;
int V_35 = 0 ;
struct V_36 * V_36 ;
V_36 = F_18 ( V_7 , V_18 -> V_26 -> V_37 ) ;
if ( ! V_36 )
return - V_38 ;
V_34 -> V_39 = F_19 ( V_36 ) ;
F_20 ( V_7 , V_36 ) ;
V_35 = F_21 ( V_7 , V_36 ) ;
return V_35 ;
}
static struct V_6 * F_22 ( struct V_14 * V_15 ,
struct V_2 * V_3 )
{
struct V_6 * V_7 = NULL ;
struct V_5 * V_40 ;
int V_35 = 0 ;
V_40 = F_23 ( V_15 -> V_15 , sizeof( * V_40 ) ,
V_41 ) ;
if ( ! V_40 ) {
V_35 = - V_42 ;
goto V_43;
}
V_7 = & V_40 -> V_4 ;
V_40 -> V_3 = V_3 ;
F_24 ( V_15 , V_7 , & V_44 ,
V_45 ) ;
F_25 ( V_7 , & V_46 ) ;
V_7 -> V_47 = ( V_48 |
V_49 ) ;
V_7 -> V_50 = 0 ;
V_7 -> V_51 = 0 ;
F_26 ( V_7 , V_3 ) ;
return V_7 ;
V_43:
if ( V_7 )
F_14 ( V_7 ) ;
return F_27 ( V_35 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
F_29 ( V_3 ) ;
}
static void F_30 ( struct V_2 * V_3 ,
struct V_52 * V_53 ,
struct V_52 * V_54 )
{
struct V_14 * V_15 = V_3 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_15 ) ;
bool V_55 = false ;
bool V_56 = V_54 -> V_57 & V_58 ;
bool V_59 = V_54 -> V_57 & V_60 ;
T_1 V_61 = ( V_54 -> V_62 >>
( ( V_54 -> V_57 & V_63 ) ? 1 : 0 ) ) ;
T_1 V_64 = ( F_31 ( V_54 -> V_65 - V_54 -> V_66 ,
V_67 ) |
F_31 ( V_54 -> V_66 - V_54 -> V_62 ,
V_68 ) |
F_31 ( V_61 , V_69 ) ) ;
T_1 V_70 = ( F_31 ( 0 , V_71 ) |
F_31 ( V_54 -> V_72 - V_54 -> V_65 ,
V_73 ) ) ;
if ( V_55 ) {
F_11 ( L_3 ) ;
F_10 ( V_15 ) ;
}
F_32 ( V_74 , 0 ) ;
F_33 ( V_18 -> V_26 -> V_75 , V_54 -> clock * 1000 ) ;
F_34 ( V_76 ,
F_8 ( V_76 ) |
V_77 |
V_78 ) ;
F_34 ( V_79 ,
( V_59 ? V_80 : 0 ) |
( V_56 ? V_81 : 0 ) |
F_31 ( V_54 -> V_82 , V_83 ) ) ;
F_34 ( V_84 ,
F_31 ( V_54 -> V_85 - V_54 -> V_86 ,
V_87 ) |
F_31 ( V_54 -> V_86 - V_54 -> V_88 ,
V_89 ) |
F_31 ( V_54 -> V_88 - V_54 -> V_82 ,
V_90 ) ) ;
F_34 ( V_91 , V_64 ) ;
F_34 ( V_92 , V_64 ) ;
F_34 ( V_93 , V_70 ) ;
F_34 ( V_94 , V_70 ) ;
F_32 ( V_74 ,
( V_59 ? 0 : V_95 ) |
( V_56 ? 0 : V_96 ) ) ;
F_32 ( V_97 , F_31 ( V_98 ,
V_99 ) ) ;
F_34 ( V_100 , V_101 ) ;
if ( V_55 ) {
F_11 ( L_4 ) ;
F_10 ( V_15 ) ;
}
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = V_3 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_15 ) ;
F_34 ( V_102 , 0xf << 16 ) ;
F_32 ( V_74 ,
F_9 ( V_74 ) & ~ V_103 ) ;
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_3 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_15 ) ;
int V_35 ;
F_34 ( V_102 , 0 ) ;
F_32 ( V_74 ,
F_9 ( V_74 ) |
V_103 |
V_104 |
V_105 ) ;
if ( V_34 -> V_39 ) {
F_34 ( V_76 ,
F_8 ( V_76 ) |
V_106 ) ;
V_35 = F_37 ( F_8 ( V_76 ) &
V_107 , 1 ) ;
F_38 ( V_35 , L_5
L_6 ) ;
} else {
F_34 ( V_108 ,
F_8 ( V_108 ) &
~ ( V_109 ) ) ;
F_34 ( V_76 ,
F_8 ( V_76 ) &
~ V_106 ) ;
V_35 = F_37 ( ! ( F_8 ( V_76 ) &
V_107 ) , 1 ) ;
F_38 ( V_35 , L_5
L_7 ) ;
}
if ( V_34 -> V_39 ) {
T_1 V_110 ;
F_39 ( ! ( F_8 ( V_76 ) &
V_107 ) ) ;
F_34 ( V_76 ,
F_8 ( V_76 ) |
V_111 ) ;
V_110 = F_8 ( V_100 ) ;
V_110 &= V_112 ;
F_34 ( V_100 ,
V_110 & ~ V_113 ) ;
F_34 ( V_100 ,
V_110 | V_113 ) ;
F_40 ( 1000 ) ;
F_34 ( V_100 ,
V_110 & ~ V_113 ) ;
F_34 ( V_100 ,
V_110 | V_113 ) ;
V_35 = F_37 ( F_8 ( V_100 ) &
V_114 , 1 ) ;
F_38 ( V_35 , L_5
L_8 ) ;
}
}
static int F_41 ( struct V_115 * V_15 , struct V_115 * V_116 , void * V_117 )
{
struct V_118 * V_119 = F_42 ( V_15 ) ;
struct V_14 * V_120 = F_43 ( V_116 ) ;
struct V_17 * V_18 = V_120 -> V_121 ;
struct V_122 * V_26 ;
struct V_1 * V_1 ;
struct V_123 * V_124 ;
T_1 V_125 ;
int V_35 ;
V_26 = F_23 ( V_15 , sizeof( * V_26 ) , V_41 ) ;
if ( ! V_26 )
return - V_42 ;
V_1 = F_23 ( V_15 , sizeof( * V_1 ) ,
V_41 ) ;
if ( ! V_1 )
return - V_42 ;
V_1 -> V_4 . type = V_126 ;
V_26 -> V_3 = & V_1 -> V_4 . V_4 ;
V_26 -> V_119 = V_119 ;
V_26 -> V_127 = F_44 ( V_119 , 0 ) ;
if ( F_45 ( V_26 -> V_127 ) )
return F_46 ( V_26 -> V_127 ) ;
V_26 -> V_23 = F_44 ( V_119 , 1 ) ;
if ( F_45 ( V_26 -> V_23 ) )
return F_46 ( V_26 -> V_23 ) ;
V_26 -> V_75 = F_47 ( V_15 , L_9 ) ;
if ( F_45 ( V_26 -> V_75 ) ) {
F_48 ( L_10 ) ;
return F_46 ( V_26 -> V_75 ) ;
}
V_26 -> V_128 = F_47 ( V_15 , L_11 ) ;
if ( F_45 ( V_26 -> V_128 ) ) {
F_48 ( L_12 ) ;
return F_46 ( V_26 -> V_128 ) ;
}
V_124 = F_49 ( V_15 -> V_129 , L_13 , 0 ) ;
if ( ! V_124 ) {
F_48 ( L_14 ) ;
return - V_38 ;
}
V_26 -> V_37 = F_50 ( V_124 ) ;
F_51 ( V_124 ) ;
if ( ! V_26 -> V_37 ) {
F_52 ( L_15 ) ;
return - V_130 ;
}
V_35 = F_53 ( V_26 -> V_75 ) ;
if ( V_35 ) {
F_48 ( L_16 , V_35 ) ;
goto V_131;
}
V_35 = F_33 ( V_26 -> V_128 , 163682864 ) ;
if ( V_35 ) {
F_48 ( L_17 , V_35 ) ;
goto V_132;
}
V_35 = F_53 ( V_26 -> V_128 ) ;
if ( V_35 ) {
F_48 ( L_18 ,
V_35 ) ;
goto V_132;
}
if ( F_54 ( V_15 -> V_129 , L_19 , & V_125 ) ) {
enum V_133 V_134 ;
V_26 -> V_27 = F_55 ( V_15 -> V_129 ,
L_19 , 0 ,
& V_134 ) ;
if ( V_26 -> V_27 < 0 ) {
V_35 = V_26 -> V_27 ;
goto V_135;
}
V_26 -> V_28 = V_134 & V_136 ;
}
V_18 -> V_26 = V_26 ;
if ( ! ( F_9 ( V_137 ) & V_138 ) ) {
F_32 ( V_137 , V_139 ) ;
F_40 ( 1 ) ;
F_32 ( V_137 , 0 ) ;
F_32 ( V_137 , V_138 ) ;
F_34 ( V_140 ,
V_141 |
V_142 ) ;
F_34 ( V_140 , 0 ) ;
F_34 ( V_102 , 0xf << 16 ) ;
}
F_56 ( V_120 , V_26 -> V_3 , & V_143 ,
V_144 , NULL ) ;
F_57 ( V_26 -> V_3 , & V_145 ) ;
V_26 -> V_7 = F_22 ( V_120 , V_26 -> V_3 ) ;
if ( F_45 ( V_26 -> V_7 ) ) {
V_35 = F_46 ( V_26 -> V_7 ) ;
goto V_146;
}
return 0 ;
V_146:
F_28 ( V_26 -> V_3 ) ;
V_135:
F_58 ( V_26 -> V_128 ) ;
V_132:
F_58 ( V_26 -> V_75 ) ;
V_131:
F_59 ( & V_26 -> V_37 -> V_15 ) ;
return V_35 ;
}
static void F_60 ( struct V_115 * V_15 , struct V_115 * V_116 ,
void * V_117 )
{
struct V_14 * V_120 = F_43 ( V_116 ) ;
struct V_17 * V_18 = V_120 -> V_121 ;
struct V_122 * V_26 = V_18 -> V_26 ;
F_14 ( V_26 -> V_7 ) ;
F_28 ( V_26 -> V_3 ) ;
F_58 ( V_26 -> V_75 ) ;
F_58 ( V_26 -> V_128 ) ;
F_59 ( & V_26 -> V_37 -> V_15 ) ;
V_18 -> V_26 = NULL ;
}
static int F_61 ( struct V_118 * V_119 )
{
return F_62 ( & V_119 -> V_15 , & V_147 ) ;
}
static int F_63 ( struct V_118 * V_119 )
{
F_64 ( & V_119 -> V_15 , & V_147 ) ;
return 0 ;
}
