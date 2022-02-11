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
if ( F_13 ( V_18 -> V_26 -> V_27 ) )
return V_28 ;
else
return V_29 ;
}
if ( F_8 ( V_30 ) & V_31 )
return V_28 ;
else
return V_29 ;
}
static void F_14 ( struct V_6 * V_7 )
{
F_15 ( V_7 ) ;
F_16 ( V_7 ) ;
}
static int F_17 ( struct V_6 * V_7 )
{
struct V_5 * V_32 =
F_3 ( V_7 ) ;
struct V_2 * V_3 = V_32 -> V_3 ;
struct V_1 * V_33 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_7 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_15 ) ;
int V_34 = 0 ;
struct V_35 * V_35 ;
V_35 = F_18 ( V_7 , V_18 -> V_26 -> V_36 ) ;
if ( ! V_35 )
return - V_37 ;
V_33 -> V_38 = F_19 ( V_35 ) ;
F_20 ( V_7 , V_35 ) ;
V_34 = F_21 ( V_7 , V_35 ) ;
return V_34 ;
}
static struct V_2 *
F_22 ( struct V_6 * V_7 )
{
struct V_5 * V_39 =
F_3 ( V_7 ) ;
return V_39 -> V_3 ;
}
static struct V_6 * F_23 ( struct V_14 * V_15 ,
struct V_2 * V_3 )
{
struct V_6 * V_7 = NULL ;
struct V_5 * V_39 ;
int V_34 = 0 ;
V_39 = F_24 ( V_15 -> V_15 , sizeof( * V_39 ) ,
V_40 ) ;
if ( ! V_39 ) {
V_34 = - V_41 ;
goto V_42;
}
V_7 = & V_39 -> V_4 ;
V_39 -> V_3 = V_3 ;
F_25 ( V_15 , V_7 , & V_43 ,
V_44 ) ;
F_26 ( V_7 , & V_45 ) ;
V_7 -> V_46 = ( V_47 |
V_48 ) ;
V_7 -> V_49 = 0 ;
V_7 -> V_50 = 0 ;
F_27 ( V_7 , V_3 ) ;
return V_7 ;
V_42:
if ( V_7 )
F_14 ( V_7 ) ;
return F_28 ( V_34 ) ;
}
static void F_29 ( struct V_2 * V_3 )
{
F_30 ( V_3 ) ;
}
static void F_31 ( struct V_2 * V_3 ,
struct V_51 * V_52 ,
struct V_51 * V_53 )
{
struct V_14 * V_15 = V_3 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_15 ) ;
bool V_54 = false ;
bool V_55 = V_53 -> V_56 & V_57 ;
bool V_58 = V_53 -> V_56 & V_59 ;
T_1 V_60 = ( V_53 -> V_61 >>
( ( V_53 -> V_56 & V_62 ) ? 1 : 0 ) ) ;
T_1 V_63 = ( F_32 ( V_53 -> V_64 - V_53 -> V_65 ,
V_66 ) |
F_32 ( V_53 -> V_65 - V_53 -> V_61 ,
V_67 ) |
F_32 ( V_60 , V_68 ) ) ;
T_1 V_69 = ( F_32 ( 0 , V_70 ) |
F_32 ( V_53 -> V_71 - V_53 -> V_64 ,
V_72 ) ) ;
if ( V_54 ) {
F_11 ( L_3 ) ;
F_10 ( V_15 ) ;
}
F_33 ( V_73 , 0 ) ;
F_34 ( V_18 -> V_26 -> V_74 , V_53 -> clock * 1000 ) ;
F_35 ( V_75 ,
F_8 ( V_75 ) |
V_76 |
V_77 ) ;
F_35 ( V_78 ,
( V_58 ? V_79 : 0 ) |
( V_55 ? V_80 : 0 ) |
F_32 ( V_53 -> V_81 , V_82 ) ) ;
F_35 ( V_83 ,
F_32 ( V_53 -> V_84 - V_53 -> V_85 ,
V_86 ) |
F_32 ( V_53 -> V_85 - V_53 -> V_87 ,
V_88 ) |
F_32 ( V_53 -> V_87 - V_53 -> V_81 ,
V_89 ) ) ;
F_35 ( V_90 , V_63 ) ;
F_35 ( V_91 , V_63 ) ;
F_35 ( V_92 , V_69 ) ;
F_35 ( V_93 , V_69 ) ;
F_33 ( V_73 ,
( V_58 ? 0 : V_94 ) |
( V_55 ? 0 : V_95 ) ) ;
F_33 ( V_96 , F_32 ( V_97 ,
V_98 ) ) ;
F_35 ( V_99 , V_100 ) ;
if ( V_54 ) {
F_11 ( L_4 ) ;
F_10 ( V_15 ) ;
}
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = V_3 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_15 ) ;
F_35 ( V_101 , 0xf << 16 ) ;
F_33 ( V_73 ,
F_9 ( V_73 ) & ~ V_102 ) ;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_1 * V_33 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_3 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_15 ) ;
int V_34 ;
F_35 ( V_101 , 0 ) ;
F_33 ( V_73 ,
F_9 ( V_73 ) |
V_102 |
V_103 |
V_104 ) ;
if ( V_33 -> V_38 ) {
F_35 ( V_75 ,
F_8 ( V_75 ) |
V_105 ) ;
V_34 = F_38 ( F_8 ( V_75 ) &
V_106 , 1 ) ;
F_39 ( V_34 , L_5
L_6 ) ;
} else {
F_35 ( V_107 ,
F_8 ( V_107 ) &
~ ( V_108 ) ) ;
F_35 ( V_75 ,
F_8 ( V_75 ) &
~ V_105 ) ;
V_34 = F_38 ( ! ( F_8 ( V_75 ) &
V_106 ) , 1 ) ;
F_39 ( V_34 , L_5
L_7 ) ;
}
if ( V_33 -> V_38 ) {
T_1 V_109 ;
F_40 ( ! ( F_8 ( V_75 ) &
V_106 ) ) ;
F_35 ( V_75 ,
F_8 ( V_75 ) |
V_110 ) ;
V_109 = F_8 ( V_99 ) ;
V_109 &= V_111 ;
F_35 ( V_99 ,
V_109 & ~ V_112 ) ;
F_35 ( V_99 ,
V_109 | V_112 ) ;
F_41 ( 1000 ) ;
F_35 ( V_99 ,
V_109 & ~ V_112 ) ;
F_35 ( V_99 ,
V_109 | V_112 ) ;
V_34 = F_38 ( F_8 ( V_99 ) &
V_113 , 1 ) ;
F_39 ( V_34 , L_5
L_8 ) ;
}
}
static int F_42 ( struct V_114 * V_15 , struct V_114 * V_115 , void * V_116 )
{
struct V_117 * V_118 = F_43 ( V_15 ) ;
struct V_14 * V_119 = F_44 ( V_115 ) ;
struct V_17 * V_18 = V_119 -> V_120 ;
struct V_121 * V_26 ;
struct V_1 * V_1 ;
struct V_122 * V_123 ;
T_1 V_124 ;
int V_34 ;
V_26 = F_24 ( V_15 , sizeof( * V_26 ) , V_40 ) ;
if ( ! V_26 )
return - V_41 ;
V_1 = F_24 ( V_15 , sizeof( * V_1 ) ,
V_40 ) ;
if ( ! V_1 )
return - V_41 ;
V_1 -> V_4 . type = V_125 ;
V_26 -> V_3 = & V_1 -> V_4 . V_4 ;
V_26 -> V_118 = V_118 ;
V_26 -> V_126 = F_45 ( V_118 , 0 ) ;
if ( F_46 ( V_26 -> V_126 ) )
return F_47 ( V_26 -> V_126 ) ;
V_26 -> V_23 = F_45 ( V_118 , 1 ) ;
if ( F_46 ( V_26 -> V_23 ) )
return F_47 ( V_26 -> V_23 ) ;
V_123 = F_48 ( V_15 -> V_127 , L_9 , 0 ) ;
if ( ! V_123 ) {
F_49 ( L_10 ) ;
return - V_37 ;
}
V_26 -> V_74 = F_50 ( V_15 , L_11 ) ;
if ( F_46 ( V_26 -> V_74 ) ) {
F_49 ( L_12 ) ;
return F_47 ( V_26 -> V_74 ) ;
}
V_26 -> V_128 = F_50 ( V_15 , L_13 ) ;
if ( F_46 ( V_26 -> V_128 ) ) {
F_49 ( L_14 ) ;
return F_47 ( V_26 -> V_128 ) ;
}
V_26 -> V_36 = F_51 ( V_123 ) ;
if ( ! V_26 -> V_36 ) {
F_52 ( L_15 ) ;
return - V_129 ;
}
V_34 = F_53 ( V_26 -> V_74 ) ;
if ( V_34 ) {
F_49 ( L_16 , V_34 ) ;
goto V_130;
}
V_34 = F_53 ( V_26 -> V_128 ) ;
if ( V_34 ) {
F_49 ( L_17 ,
V_34 ) ;
goto V_131;
}
if ( F_54 ( V_15 -> V_127 , L_18 , & V_124 ) ) {
V_26 -> V_27 = F_55 ( V_15 -> V_127 , L_18 , 0 ) ;
if ( V_26 -> V_27 < 0 ) {
V_34 = V_26 -> V_27 ;
goto V_132;
}
}
V_18 -> V_26 = V_26 ;
F_56 ( ( F_9 ( V_133 ) & V_134 ) == 0 ) ;
F_57 ( V_119 , V_26 -> V_3 , & V_135 ,
V_136 ) ;
F_58 ( V_26 -> V_3 , & V_137 ) ;
V_26 -> V_7 = F_23 ( V_119 , V_26 -> V_3 ) ;
if ( F_46 ( V_26 -> V_7 ) ) {
V_34 = F_47 ( V_26 -> V_7 ) ;
goto V_138;
}
return 0 ;
V_138:
F_29 ( V_26 -> V_3 ) ;
V_132:
F_59 ( V_26 -> V_128 ) ;
V_131:
F_59 ( V_26 -> V_74 ) ;
V_130:
F_60 ( & V_18 -> V_26 -> V_36 -> V_15 ) ;
return V_34 ;
}
static void F_61 ( struct V_114 * V_15 , struct V_114 * V_115 ,
void * V_116 )
{
struct V_14 * V_119 = F_44 ( V_115 ) ;
struct V_17 * V_18 = V_119 -> V_120 ;
struct V_121 * V_26 = V_18 -> V_26 ;
F_14 ( V_26 -> V_7 ) ;
F_29 ( V_26 -> V_3 ) ;
F_59 ( V_26 -> V_74 ) ;
F_59 ( V_26 -> V_128 ) ;
F_60 ( & V_26 -> V_36 -> V_15 ) ;
V_18 -> V_26 = NULL ;
}
static int F_62 ( struct V_117 * V_118 )
{
return F_63 ( & V_118 -> V_15 , & V_139 ) ;
}
static int F_64 ( struct V_117 * V_118 )
{
F_65 ( & V_118 -> V_15 , & V_139 ) ;
return 0 ;
}
