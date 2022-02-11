static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
const struct V_4 * V_5 = & V_2 -> V_6 -> V_7 [ V_3 ] ;
void T_1 * V_8 = V_2 -> V_9 + V_5 -> V_8 ;
unsigned int V_10 ;
V_10 = V_5 -> V_11 -> V_12 << V_13 ;
F_2 ( V_10 , V_8 + V_14 ) ;
V_10 = ( V_5 -> V_11 -> V_15 - 1 ) << V_16 ;
V_10 |= V_5 -> V_11 -> V_17 << V_18 ;
V_10 |= V_5 -> V_11 -> V_19 << V_20 ;
V_10 |= V_21 ;
F_2 ( V_10 , V_8 + V_22 ) ;
F_2 ( V_2 -> V_23 [ V_3 ] , V_8 + V_24 ) ;
}
static int F_3 ( T_2 V_10 )
{
int V_25 ;
V_25 = ( ( V_10 & V_26 ) >> V_27 ) * 1000 ;
if ( V_10 & V_28 )
V_25 += 500 ;
if ( V_10 & V_29 )
V_25 *= - 1 ;
return V_25 ;
}
static int F_4 ( void * V_30 , int * V_31 )
{
struct V_32 * V_33 = V_30 ;
T_3 V_10 ;
V_10 = F_5 ( V_33 -> V_34 ) ;
V_10 = F_6 ( V_10 , V_33 -> V_35 -> V_36 ) ;
* V_31 = F_3 ( V_10 ) ;
return 0 ;
}
static int F_7 ( void * V_30 , int V_37 , int V_38 )
{
struct V_32 * V_33 = V_30 ;
struct V_39 * V_40 = V_33 -> V_40 ;
const struct V_41 * V_35 = V_33 -> V_35 ;
struct V_42 * V_43 = V_33 -> V_43 ;
enum V_44 type ;
int V_45 ;
if ( ! V_40 )
return - V_46 ;
V_45 = V_40 -> V_47 -> V_48 ( V_40 , V_37 , & type ) ;
if ( V_45 )
return V_45 ;
if ( type != V_49 )
return 0 ;
return F_8 ( V_43 , V_35 , V_38 ) ;
}
static int F_9 ( struct V_42 * V_43 , int V_50 )
{
int V_38 ;
V_38 = F_10 ( V_50 , V_51 , V_52 ) ;
if ( V_38 != V_50 )
F_11 ( V_43 , L_1 ,
V_50 , V_38 ) ;
return V_38 ;
}
static int F_8 ( struct V_42 * V_43 ,
const struct V_41 * V_35 ,
int V_50 )
{
struct V_1 * V_53 = F_12 ( V_43 ) ;
int V_38 ;
T_3 V_54 ;
if ( ! V_35 || ! V_35 -> V_55 )
return - V_46 ;
V_38 = F_9 ( V_43 , V_50 ) / V_53 -> V_6 -> V_56 ;
V_54 = F_5 ( V_53 -> V_9 + V_57 ) ;
V_54 = F_13 ( V_54 , V_35 -> V_55 , V_38 ) ;
V_54 = F_13 ( V_54 , V_35 -> V_58 , 1 ) ;
V_54 = F_13 ( V_54 , V_35 -> V_59 , 0 ) ;
F_2 ( V_54 , V_53 -> V_9 + V_57 ) ;
return 0 ;
}
static int F_14 ( struct V_42 * V_43 ,
const struct V_41 * V_35 ,
struct V_39 * V_40 )
{
int V_60 ;
int V_45 ;
V_45 = V_40 -> V_47 -> V_61 ( V_40 , & V_60 ) ;
if ( V_45 ) {
F_15 ( V_43 , L_2 ,
V_35 -> V_62 ) ;
return V_45 ;
}
V_45 = F_8 ( V_43 , V_35 , V_60 ) ;
if ( V_45 ) {
F_16 ( V_43 , L_3 ,
V_35 -> V_62 ) ;
return V_45 ;
}
F_11 ( V_43 ,
L_4 ,
V_35 -> V_62 , V_60 ) ;
return 0 ;
}
static int F_17 ( struct V_63 * V_64 , void * V_30 )
{
struct V_65 * V_66 = V_64 -> V_67 ;
struct V_1 * V_53 = F_18 ( V_66 ) ;
const struct V_4 * V_7 = V_53 -> V_6 -> V_7 ;
const struct V_41 * * V_68 = V_53 -> V_6 -> V_68 ;
T_3 V_54 , V_69 ;
int V_3 ;
F_19 ( V_64 , L_5 ) ;
for ( V_3 = 0 ; V_3 < V_53 -> V_6 -> V_70 ; V_3 ++ ) {
V_54 = F_5 ( V_53 -> V_9 + V_7 [ V_3 ] . V_8 + V_22 ) ;
V_69 = F_6 ( V_54 , V_21 ) ;
F_20 ( V_64 , L_6 , V_7 [ V_3 ] . V_62 ) ;
F_20 ( V_64 , L_7 , V_69 ) ;
if ( ! V_69 ) {
F_19 ( V_64 , L_8 ) ;
continue;
}
V_69 = F_6 ( V_54 , V_71 ) ;
F_20 ( V_64 , L_9 , V_69 ) ;
V_69 = F_6 ( V_54 , V_72 ) ;
F_20 ( V_64 , L_10 , V_69 ) ;
V_69 = F_6 ( V_54 , V_73 ) ;
F_20 ( V_64 , L_11 , V_69 + 1 ) ;
V_54 = F_5 ( V_53 -> V_9 + V_7 [ V_3 ] . V_8 + V_74 ) ;
V_69 = F_6 ( V_54 , V_75 ) ;
F_20 ( V_64 , L_12 , V_69 ) ;
V_69 = F_6 ( V_54 , V_76 ) ;
F_20 ( V_64 , L_13 , F_3 ( V_69 ) ) ;
V_54 = F_5 ( V_53 -> V_9 + V_7 [ V_3 ] . V_8 + V_77 ) ;
V_69 = F_6 ( V_54 , V_78 ) ;
F_20 ( V_64 , L_14 , V_69 ) ;
V_69 = F_6 ( V_54 , V_79 ) ;
F_20 ( V_64 , L_13 , V_69 ) ;
V_54 = F_5 ( V_53 -> V_9 + V_7 [ V_3 ] . V_8 + V_14 ) ;
V_69 = F_6 ( V_54 , V_80 ) ;
F_20 ( V_64 , L_15 , V_69 ) ;
V_69 = F_6 ( V_54 , V_81 ) ;
F_20 ( V_64 , L_16 , V_69 ) ;
V_69 = F_6 ( V_54 , V_82 ) ;
F_20 ( V_64 , L_17 , V_69 ) ;
V_69 = F_6 ( V_54 , V_83 ) ;
F_20 ( V_64 , L_18 , V_69 ) ;
V_69 = F_6 ( V_54 , V_84 ) ;
F_20 ( V_64 , L_13 , V_69 ) ;
V_54 = F_5 ( V_53 -> V_9 + V_7 [ V_3 ] . V_8 + V_24 ) ;
V_69 = F_6 ( V_54 , V_85 ) ;
F_20 ( V_64 , L_19 , V_69 ) ;
V_69 = F_6 ( V_54 , V_86 ) ;
F_20 ( V_64 , L_20 , ( V_87 ) V_69 ) ;
}
V_54 = F_5 ( V_53 -> V_9 + V_88 ) ;
F_20 ( V_64 , L_21 , V_54 ) ;
V_54 = F_5 ( V_53 -> V_9 + V_89 ) ;
F_20 ( V_64 , L_22 , V_54 ) ;
F_19 ( V_64 , L_8 ) ;
F_19 ( V_64 , L_23 ) ;
V_54 = F_5 ( V_53 -> V_9 + V_90 ) ;
V_69 = F_6 ( V_54 , V_91 ) ;
F_20 ( V_64 , L_24 , F_3 ( V_69 ) ) ;
V_69 = F_6 ( V_54 , V_92 ) ;
F_20 ( V_64 , L_25 , F_3 ( V_69 ) ) ;
V_54 = F_5 ( V_53 -> V_9 + V_93 ) ;
V_69 = F_6 ( V_54 , V_94 ) ;
F_20 ( V_64 , L_26 , F_3 ( V_69 ) ) ;
V_69 = F_6 ( V_54 , V_95 ) ;
F_20 ( V_64 , L_27 , F_3 ( V_69 ) ) ;
V_54 = F_5 ( V_53 -> V_9 + V_57 ) ;
V_69 = F_6 ( V_54 , V_68 [ 0 ] -> V_59 ) ;
F_20 ( V_64 , L_28 , V_69 ) ;
for ( V_3 = 0 ; V_3 < V_53 -> V_6 -> V_96 ; V_3 ++ ) {
V_69 = F_6 ( V_54 , V_68 [ V_3 ] -> V_58 ) ;
F_20 ( V_64 , L_29 , V_68 [ V_3 ] -> V_62 , V_69 ) ;
V_69 = F_6 ( V_54 , V_68 [ V_3 ] -> V_55 ) ;
V_69 *= V_53 -> V_6 -> V_56 ;
F_20 ( V_64 , L_30 , V_69 ) ;
}
return 0 ;
}
static int F_21 ( struct V_97 * V_97 , struct V_98 * V_98 )
{
return F_22 ( V_98 , F_17 , V_97 -> V_99 ) ;
}
static void F_23 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_18 ( V_66 ) ;
struct V_100 * V_101 , * V_98 ;
V_101 = F_24 ( L_31 , NULL ) ;
if ( ! V_101 ) {
F_16 ( & V_66 -> V_43 , L_32 ) ;
return;
}
V_2 -> V_102 = V_101 ;
V_98 = F_25 ( L_33 , 0644 , V_101 ,
V_66 , & V_103 ) ;
if ( ! V_98 ) {
F_16 ( & V_66 -> V_43 , L_34 ) ;
F_26 ( V_2 -> V_102 ) ;
V_2 -> V_102 = NULL ;
}
}
static inline void F_23 ( struct V_65 * V_66 ) {}
static int F_27 ( struct V_65 * V_66 , bool V_104 )
{
struct V_1 * V_2 = F_18 ( V_66 ) ;
int V_105 ;
if ( ! V_2 -> V_106 || ! V_2 -> V_107 )
return - V_46 ;
F_28 ( V_2 -> V_108 ) ;
if ( V_104 ) {
V_105 = F_29 ( V_2 -> V_106 ) ;
if ( V_105 ) {
F_30 ( V_2 -> V_108 ) ;
return V_105 ;
}
V_105 = F_29 ( V_2 -> V_107 ) ;
if ( V_105 ) {
F_31 ( V_2 -> V_106 ) ;
F_30 ( V_2 -> V_108 ) ;
return V_105 ;
}
} else {
F_31 ( V_2 -> V_107 ) ;
F_31 ( V_2 -> V_106 ) ;
}
F_30 ( V_2 -> V_108 ) ;
return 0 ;
}
static void F_32 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_18 ( V_66 ) ;
const struct V_41 * * V_68 = V_2 -> V_6 -> V_68 ;
int V_3 ;
T_3 V_109 , V_110 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_6 -> V_70 ; ++ V_3 )
F_1 ( V_2 , V_3 ) ;
V_109 = F_5 ( V_2 -> V_9 + V_88 ) ;
V_110 = F_5 ( V_2 -> V_9 + V_89 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_6 -> V_96 ; ++ V_3 ) {
V_109 = F_13 ( V_109 , V_68 [ V_3 ] -> V_111 ,
V_68 [ V_3 ] -> V_109 ) ;
if ( V_68 [ V_3 ] -> V_112 == V_113 )
continue;
V_110 = F_13 ( V_110 ,
V_68 [ V_3 ] -> V_114 ,
V_68 [ V_3 ] -> V_115 ) ;
}
F_2 ( V_109 , V_2 -> V_9 + V_88 ) ;
F_2 ( V_110 , V_2 -> V_9 + V_89 ) ;
}
static int F_33 ( struct V_65 * V_66 )
{
const struct V_116 * V_117 ;
struct V_1 * V_2 ;
struct V_39 * V_118 ;
struct V_119 V_120 ;
struct V_121 * V_122 ;
struct V_123 * V_6 ;
unsigned int V_3 ;
int V_105 ;
V_117 = F_34 ( V_124 , V_66 -> V_43 . V_125 ) ;
if ( ! V_117 )
return - V_126 ;
V_6 = (struct V_123 * ) V_117 -> V_30 ;
if ( V_6 -> V_96 > V_127 )
return - V_46 ;
V_2 = F_35 ( & V_66 -> V_43 , sizeof( * V_2 ) , V_128 ) ;
if ( ! V_2 )
return - V_129 ;
F_36 ( & V_66 -> V_43 , V_2 ) ;
V_2 -> V_6 = V_6 ;
V_122 = F_37 ( V_66 , V_130 , 0 ) ;
V_2 -> V_9 = F_38 ( & V_66 -> V_43 , V_122 ) ;
if ( F_39 ( V_2 -> V_9 ) )
return F_40 ( V_2 -> V_9 ) ;
V_2 -> V_108 = F_41 ( & V_66 -> V_43 , L_31 ) ;
if ( F_39 ( V_2 -> V_108 ) ) {
F_16 ( & V_66 -> V_43 , L_35 ) ;
return F_40 ( V_2 -> V_108 ) ;
}
V_2 -> V_107 = F_42 ( & V_66 -> V_43 , L_36 ) ;
if ( F_39 ( V_2 -> V_107 ) ) {
F_16 ( & V_66 -> V_43 , L_37 ) ;
return F_40 ( V_2 -> V_107 ) ;
}
V_2 -> V_106 = F_42 ( & V_66 -> V_43 , L_31 ) ;
if ( F_39 ( V_2 -> V_106 ) ) {
F_16 ( & V_66 -> V_43 , L_38 ) ;
return F_40 ( V_2 -> V_106 ) ;
}
V_2 -> V_23 = F_35 ( & V_66 -> V_43 ,
sizeof( T_3 ) * V_6 -> V_70 ,
V_128 ) ;
if ( ! V_2 -> V_23 )
return - V_129 ;
V_105 = F_43 ( V_6 -> V_131 , & V_120 ) ;
if ( V_105 )
return V_105 ;
for ( V_3 = 0 ; V_3 < V_6 -> V_70 ; ++ V_3 ) {
V_105 = F_44 ( & V_6 -> V_7 [ V_3 ] ,
& V_120 ,
& V_2 -> V_23 [ V_3 ] ) ;
if ( V_105 )
return V_105 ;
}
V_2 -> V_132 = F_35 ( & V_66 -> V_43 ,
sizeof( * V_118 ) * V_6 -> V_96 ,
V_128 ) ;
if ( ! V_2 -> V_132 )
return - V_129 ;
V_105 = F_27 ( V_66 , true ) ;
if ( V_105 )
return V_105 ;
F_32 ( V_66 ) ;
for ( V_3 = 0 ; V_3 < V_6 -> V_96 ; ++ V_3 ) {
struct V_32 * V_33 =
F_35 ( & V_66 -> V_43 , sizeof( * V_33 ) , V_128 ) ;
if ( ! V_33 ) {
V_105 = - V_129 ;
goto V_133;
}
V_33 -> V_34 = V_2 -> V_9 + V_6 -> V_68 [ V_3 ] -> V_134 ;
V_33 -> V_43 = & V_66 -> V_43 ;
V_33 -> V_35 = V_6 -> V_68 [ V_3 ] ;
V_118 = F_45 ( & V_66 -> V_43 ,
V_6 -> V_68 [ V_3 ] -> V_112 , V_33 ,
& V_135 ) ;
if ( F_39 ( V_118 ) ) {
V_105 = F_40 ( V_118 ) ;
F_16 ( & V_66 -> V_43 , L_39 ,
V_105 ) ;
goto V_133;
}
V_33 -> V_40 = V_118 ;
V_2 -> V_132 [ V_6 -> V_68 [ V_3 ] -> V_112 ] = V_118 ;
F_14 ( & V_66 -> V_43 , V_6 -> V_68 [ V_3 ] , V_118 ) ;
}
F_23 ( V_66 ) ;
return 0 ;
V_133:
F_27 ( V_66 , false ) ;
return V_105 ;
}
static int F_46 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_18 ( V_66 ) ;
F_26 ( V_2 -> V_102 ) ;
F_27 ( V_66 , false ) ;
return 0 ;
}
static int T_4 F_47 ( struct V_42 * V_43 )
{
struct V_65 * V_66 = F_48 ( V_43 ) ;
F_27 ( V_66 , false ) ;
return 0 ;
}
static int T_4 F_49 ( struct V_42 * V_43 )
{
struct V_65 * V_66 = F_48 ( V_43 ) ;
struct V_1 * V_2 = F_18 ( V_66 ) ;
struct V_123 * V_6 = V_2 -> V_6 ;
int V_105 , V_3 ;
V_105 = F_27 ( V_66 , true ) ;
if ( V_105 ) {
F_16 ( & V_66 -> V_43 ,
L_40 ) ;
return V_105 ;
}
F_32 ( V_66 ) ;
for ( V_3 = 0 ; V_3 < V_6 -> V_96 ; ++ V_3 ) {
struct V_39 * V_40 ;
V_40 = V_2 -> V_132 [ V_6 -> V_68 [ V_3 ] -> V_112 ] ;
F_14 ( V_43 , V_6 -> V_68 [ V_3 ] , V_40 ) ;
}
return 0 ;
}
