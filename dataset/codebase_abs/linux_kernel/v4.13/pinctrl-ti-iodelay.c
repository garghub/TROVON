static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return ( V_1 & V_2 ) >> F_2 ( V_2 ) ;
}
static inline T_1 F_3 ( T_2 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 )
{
T_3 V_7 , V_8 ;
V_7 = 10 * ( T_3 ) V_3 * ( T_3 ) V_4 ;
V_8 = 2 * ( T_3 ) V_5 * ( T_3 ) V_6 ;
return F_4 ( V_7 , V_8 ) ;
}
static int F_5 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
const struct V_13 * V_14 = V_10 -> V_15 ;
struct V_16 * V_17 = & V_10 -> V_18 ;
struct V_19 * V_20 = V_10 -> V_20 ;
T_1 V_21 , V_22 ;
T_1 V_23 , V_24 ;
T_1 V_25 , V_26 ;
T_1 V_27 ;
T_1 V_28 , V_29 , V_30 ;
int V_31 ;
V_21 = V_12 -> V_32 / 920 ;
V_22 = ( ( V_12 -> V_32 % 920 ) * 10 ) / 60 ;
V_23 = V_12 -> V_33 / V_17 -> V_34 ;
V_24 = ( ( V_12 -> V_33 % V_17 -> V_34 ) * 10 ) / V_17 -> V_35 ;
V_25 = V_21 + V_23 ;
V_26 = ( V_22 + V_24 ) / 10 ;
if ( V_26 > 22 ) {
V_27 = V_25 * V_17 -> V_34 + V_26 * V_17 -> V_35 ;
V_25 = V_27 / V_17 -> V_34 ;
V_26 = ( V_27 % V_17 -> V_34 ) / V_17 -> V_35 ;
}
V_28 = V_14 -> V_36 ;
V_29 = V_14 -> V_37 << F_2 ( V_14 -> V_36 ) ;
V_28 |= V_14 -> V_38 ;
V_30 = V_25 << F_2 ( V_14 -> V_38 ) ;
if ( V_30 & ~ V_14 -> V_38 ) {
F_6 ( V_20 , L_1 ,
V_30 ) ;
V_30 &= V_14 -> V_38 ;
}
V_29 |= V_30 ;
V_28 |= V_14 -> V_39 ;
V_30 = V_26 << F_2 ( V_14 -> V_39 ) ;
if ( V_30 & ~ V_14 -> V_39 ) {
F_6 ( V_20 , L_2 ,
V_30 ) ;
V_30 &= V_14 -> V_39 ;
}
V_29 |= V_30 ;
V_28 |= V_14 -> V_40 ;
V_29 |= V_14 -> V_41 << F_2 ( V_14 -> V_40 ) ;
V_31 = F_7 ( V_10 -> V_42 , V_12 -> V_43 , V_28 , V_29 ) ;
F_8 ( V_20 , L_3 ,
V_12 -> V_43 , V_12 -> V_33 , V_12 -> V_32 , V_25 ,
V_26 , V_29 ) ;
return V_31 ;
}
static int F_9 ( struct V_9 * V_10 )
{
const struct V_13 * V_14 = V_10 -> V_15 ;
struct V_19 * V_20 = V_10 -> V_20 ;
struct V_16 * V_17 = & V_10 -> V_18 ;
T_1 V_1 ;
int V_31 ;
V_31 = F_7 ( V_10 -> V_42 , V_14 -> V_44 ,
V_14 -> V_45 , V_14 -> V_46 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_10 ( V_10 -> V_42 , V_14 -> V_47 , & V_1 ) ;
if ( V_31 )
return V_31 ;
V_17 -> V_48 = F_1 ( V_1 , V_14 -> V_49 ) ;
F_11 ( V_20 , L_4 , V_17 -> V_48 ) ;
V_31 = F_10 ( V_10 -> V_42 , V_14 -> V_50 , & V_1 ) ;
if ( V_31 )
return V_31 ;
V_17 -> V_51 =
F_1 ( V_1 , V_14 -> V_52 ) ;
V_17 -> V_53 =
F_1 ( V_1 , V_14 -> V_54 ) ;
if ( ! V_17 -> V_53 ) {
F_6 ( V_20 , L_5 ,
V_1 ) ;
return - V_55 ;
}
V_17 -> V_34 = F_3 ( V_17 -> V_48 ,
V_17 -> V_51 ,
V_17 -> V_53 , 88 ) ;
if ( ! V_17 -> V_34 ) {
F_6 ( V_20 , L_6 ,
V_17 -> V_48 , V_17 -> V_51 ,
V_17 -> V_53 ) ;
return - V_55 ;
}
F_11 ( V_10 -> V_20 , L_7 ,
V_17 -> V_51 , V_17 -> V_53 , V_17 -> V_34 ) ;
V_31 = F_10 ( V_10 -> V_42 , V_14 -> V_56 , & V_1 ) ;
if ( V_31 )
return V_31 ;
V_17 -> V_57 =
F_1 ( V_1 , V_14 -> V_58 ) ;
V_17 -> V_59 =
F_1 ( V_1 , V_14 -> V_60 ) ;
if ( ! V_17 -> V_59 ) {
F_6 ( V_20 , L_8 ,
V_1 ) ;
return - V_55 ;
}
V_17 -> V_35 = F_3 ( V_17 -> V_48 ,
V_17 -> V_57 ,
V_17 -> V_59 , 264 ) ;
if ( ! V_17 -> V_35 ) {
F_6 ( V_20 , L_9 ,
V_17 -> V_48 , V_17 -> V_57 ,
V_17 -> V_59 ) ;
return - V_55 ;
}
F_11 ( V_10 -> V_20 , L_10 ,
V_17 -> V_57 , V_17 -> V_59 , V_17 -> V_35 ) ;
return 0 ;
}
static void F_12 ( struct V_9 * V_10 )
{
const struct V_13 * V_14 = V_10 -> V_15 ;
F_7 ( V_10 -> V_42 , V_14 -> V_44 ,
V_14 -> V_45 , V_14 -> V_61 ) ;
}
static struct V_62 *
F_13 ( struct V_9 * V_10 , unsigned int V_63 )
{
struct V_64 * V_65 ;
V_65 = F_14 ( V_10 -> V_66 , V_63 ) ;
if ( ! V_65 ) {
F_6 ( V_10 -> V_20 , L_11 , V_67 ,
V_63 ) ;
return NULL ;
}
return V_65 -> V_68 ;
}
static int F_15 ( struct V_9 * V_10 ,
unsigned int V_43 )
{
const struct V_13 * V_31 = V_10 -> V_15 ;
unsigned int V_69 ;
if ( V_43 > V_31 -> V_70 -> V_71 ) {
F_6 ( V_10 -> V_20 , L_12 ,
V_43 , V_31 -> V_70 -> V_71 ) ;
return - V_55 ;
}
V_69 = ( V_43 - V_31 -> V_72 ) / V_31 -> V_70 -> V_73 ;
V_69 /= V_31 -> V_74 ;
return V_69 ;
}
static int F_16 ( struct V_75 * V_76 ,
struct V_77 * V_78 ,
const struct V_79 * V_80 ,
int * V_81 , int V_82 , void * V_68 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 = V_68 ;
const struct V_13 * V_31 ;
struct V_83 * V_84 ;
int V_85 ;
V_10 = F_17 ( V_76 ) ;
if ( ! V_10 )
return - V_55 ;
V_31 = V_10 -> V_15 ;
if ( V_80 -> V_86 < V_31 -> V_74 ) {
F_6 ( V_10 -> V_20 , L_13 ,
V_80 -> V_86 ) ;
return - V_55 ;
}
V_12 [ V_82 ] . V_43 = V_80 -> args [ 0 ] ;
V_12 [ V_82 ] . V_33 = V_80 -> args [ 1 ] & 0xffff ;
V_12 [ V_82 ] . V_32 = V_80 -> args [ 2 ] & 0xffff ;
V_85 = F_15 ( V_10 , V_12 [ V_82 ] . V_43 ) ;
if ( V_85 < 0 ) {
F_6 ( V_10 -> V_20 , L_14 ,
V_78 -> V_87 , V_12 [ V_82 ] . V_43 ) ;
return - V_88 ;
}
V_81 [ V_82 ] = V_85 ;
V_84 = & V_10 -> V_89 [ V_85 ] ;
V_84 -> V_90 = & V_12 [ V_82 ] ;
F_11 ( V_10 -> V_20 , L_15 ,
V_78 -> V_87 , V_12 [ V_82 ] . V_43 , V_12 [ V_82 ] . V_33 ,
V_12 [ V_82 ] . V_32 ) ;
return 0 ;
}
static int F_18 ( struct V_75 * V_76 ,
struct V_77 * V_78 ,
struct V_91 * * V_92 ,
unsigned int * V_93 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_62 * V_65 ;
const char * V_87 = L_16 ;
int V_94 , * V_81 , error = - V_55 , V_95 ;
V_10 = F_17 ( V_76 ) ;
if ( ! V_10 )
return - V_55 ;
V_94 = F_19 ( V_78 , V_87 ) ;
if ( V_94 == - V_55 )
return V_94 ;
* V_92 = F_20 ( V_10 -> V_20 , sizeof( * * V_92 ) , V_96 ) ;
if ( ! * V_92 )
return - V_97 ;
* V_93 = 0 ;
V_65 = F_20 ( V_10 -> V_20 , sizeof( * V_65 ) , V_96 ) ;
if ( ! V_65 ) {
error = - V_97 ;
goto V_98;
}
V_81 = F_20 ( V_10 -> V_20 , sizeof( * V_81 ) * V_94 , V_96 ) ;
if ( ! V_81 )
goto V_99;
V_12 = F_20 ( V_10 -> V_20 , sizeof( * V_12 ) * V_94 , V_96 ) ;
if ( ! V_12 ) {
error = - V_97 ;
goto V_100;
}
for ( V_95 = 0 ; V_95 < V_94 ; V_95 ++ ) {
struct V_79 V_80 ;
error = F_21 ( V_78 , V_87 , V_95 ,
& V_80 ) ;
if ( error )
goto V_101;
error = F_16 ( V_76 , V_78 , & V_80 ,
V_81 , V_95 , V_12 ) ;
if ( error )
goto V_101;
}
V_65 -> V_12 = V_12 ;
V_65 -> V_102 = V_95 ;
V_65 -> V_103 = V_104 ;
error = F_22 ( V_10 -> V_66 , V_78 -> V_87 , V_81 , V_95 , V_65 ) ;
if ( error < 0 )
goto V_101;
( * V_92 ) -> type = V_105 ;
( * V_92 ) -> V_68 . V_106 . V_107 = V_78 -> V_87 ;
( * V_92 ) -> V_68 . V_106 . V_106 = & V_65 -> V_103 ;
( * V_92 ) -> V_68 . V_106 . V_108 = 1 ;
* V_93 = 1 ;
return 0 ;
V_101:
F_23 ( V_10 -> V_20 , V_12 ) ;
V_100:
F_23 ( V_10 -> V_20 , V_81 ) ;
V_99:
F_23 ( V_10 -> V_20 , V_65 ) ;
V_98:
F_23 ( V_10 -> V_20 , * V_92 ) ;
return error ;
}
static int F_24 ( struct V_75 * V_76 ,
unsigned int V_63 ,
unsigned long * V_103 )
{
struct V_9 * V_10 ;
struct V_19 * V_20 ;
struct V_62 * V_109 ;
V_10 = F_17 ( V_76 ) ;
V_20 = V_10 -> V_20 ;
V_109 = F_13 ( V_10 , V_63 ) ;
if ( ! V_109 )
return - V_55 ;
* V_103 = V_109 -> V_103 ;
return 0 ;
}
static int F_25 ( struct V_75 * V_76 ,
unsigned int V_63 ,
unsigned long * V_106 ,
unsigned int V_108 )
{
struct V_9 * V_10 ;
struct V_19 * V_20 ;
struct V_62 * V_109 ;
int V_95 ;
V_10 = F_17 ( V_76 ) ;
V_20 = V_10 -> V_20 ;
V_109 = F_13 ( V_10 , V_63 ) ;
if ( V_108 != 1 ) {
F_6 ( V_20 , L_17 ,
V_108 ) ;
return - V_55 ;
}
if ( * V_106 != V_104 ) {
F_6 ( V_20 , L_18 ) ;
return - V_55 ;
}
for ( V_95 = 0 ; V_95 < V_109 -> V_102 ; V_95 ++ ) {
if ( F_5 ( V_10 , & V_109 -> V_12 [ V_95 ] ) )
return - V_110 ;
}
return 0 ;
}
static unsigned int F_26 ( struct V_9 * V_10 ,
unsigned int V_63 )
{
const struct V_13 * V_31 = V_10 -> V_15 ;
unsigned int V_43 ;
V_43 = V_63 * V_31 -> V_70 -> V_73 ;
V_43 *= V_31 -> V_74 ;
V_43 += V_31 -> V_72 ;
return V_43 ;
}
static void F_27 ( struct V_75 * V_76 ,
struct V_111 * V_112 ,
unsigned int V_85 )
{
struct V_9 * V_10 ;
struct V_83 * V_84 ;
struct V_11 * V_12 ;
const struct V_13 * V_31 ;
unsigned long V_43 ;
T_1 V_113 , V_114 , V_115 ;
V_10 = F_17 ( V_76 ) ;
V_31 = V_10 -> V_15 ;
V_43 = F_26 ( V_10 , V_85 ) ;
V_84 = & V_10 -> V_89 [ V_85 ] ;
V_12 = V_84 -> V_90 ;
F_10 ( V_10 -> V_42 , V_43 , & V_113 ) ;
F_10 ( V_10 -> V_42 , V_43 + V_31 -> V_70 -> V_73 , & V_114 ) ;
F_10 ( V_10 -> V_42 , V_43 + V_31 -> V_70 -> V_73 * 2 ,
& V_115 ) ;
F_28 ( V_112 , L_19 ,
V_10 -> V_116 + V_43 ,
V_12 ? V_12 -> V_33 : - 1 ,
V_12 ? V_12 -> V_32 : - 1 ,
V_113 , V_114 , V_115 , V_117 ) ;
}
static void F_29 ( struct V_75 * V_76 ,
struct V_111 * V_112 ,
unsigned int V_63 )
{
struct V_9 * V_10 ;
struct V_19 * V_20 ;
struct V_62 * V_109 ;
int V_95 ;
V_10 = F_17 ( V_76 ) ;
V_20 = V_10 -> V_20 ;
V_109 = F_13 ( V_10 , V_63 ) ;
if ( ! V_109 )
return;
for ( V_95 = 0 ; V_95 < V_109 -> V_102 ; V_95 ++ ) {
struct V_11 * V_12 ;
T_1 V_14 = 0 ;
V_12 = & V_109 -> V_12 [ V_95 ] ;
F_10 ( V_10 -> V_42 , V_12 -> V_43 , & V_14 ) ,
F_28 ( V_112 , L_20 ,
V_12 -> V_43 , V_14 , V_12 -> V_33 ,
V_12 -> V_32 ) ;
}
}
static int F_30 ( struct V_19 * V_20 ,
struct V_9 * V_10 , T_1 V_118 )
{
const struct V_13 * V_31 = V_10 -> V_15 ;
struct V_83 * V_85 ;
T_1 V_119 ;
int V_120 , V_95 ;
V_120 = F_15 ( V_10 , V_31 -> V_70 -> V_71 ) ;
F_11 ( V_20 , L_21 , V_120 ) ;
V_10 -> V_89 = F_20 ( V_20 , sizeof( * V_10 -> V_89 ) * V_120 , V_96 ) ;
if ( ! V_10 -> V_89 )
return - V_97 ;
V_10 -> V_121 . V_81 = V_10 -> V_89 ;
V_10 -> V_121 . V_122 = V_120 ;
V_119 = V_31 -> V_72 + V_118 ;
for ( V_95 = 0 ; V_95 < V_120 ; V_95 ++ , V_119 += 4 ) {
V_85 = & V_10 -> V_89 [ V_95 ] ;
V_85 -> V_123 = V_95 ;
}
return 0 ;
}
static int F_31 ( struct V_124 * V_125 )
{
struct V_19 * V_20 = & V_125 -> V_20 ;
struct V_77 * V_78 = F_32 ( V_20 -> V_126 ) ;
const struct V_127 * V_128 ;
struct V_129 * V_130 ;
struct V_9 * V_10 ;
int V_131 = 0 ;
if ( ! V_78 ) {
V_131 = - V_55 ;
F_6 ( V_20 , L_22 ) ;
goto V_132;
}
V_128 = F_33 ( V_133 , V_20 ) ;
if ( ! V_128 ) {
V_131 = - V_55 ;
F_6 ( V_20 , L_23 ) ;
goto V_132;
}
V_10 = F_20 ( V_20 , sizeof( * V_10 ) , V_96 ) ;
if ( ! V_10 ) {
V_131 = - V_97 ;
goto V_132;
}
V_10 -> V_20 = V_20 ;
V_10 -> V_15 = V_128 -> V_68 ;
V_130 = F_34 ( V_125 , V_134 , 0 ) ;
if ( ! V_130 ) {
F_6 ( V_20 , L_24 ) ;
V_131 = - V_88 ;
goto V_132;
}
V_10 -> V_116 = V_130 -> V_135 ;
V_10 -> V_136 = F_35 ( V_20 , V_130 ) ;
if ( F_36 ( V_10 -> V_136 ) ) {
V_131 = F_37 ( V_10 -> V_136 ) ;
goto V_132;
}
V_10 -> V_42 = F_38 ( V_20 , V_10 -> V_136 ,
V_10 -> V_15 -> V_70 ) ;
if ( F_36 ( V_10 -> V_42 ) ) {
F_6 ( V_20 , L_25 ) ;
V_131 = F_37 ( V_10 -> V_42 ) ;
goto V_132;
}
if ( F_9 ( V_10 ) )
goto V_132;
V_131 = F_30 ( V_20 , V_10 , V_130 -> V_135 ) ;
if ( V_131 )
goto V_132;
V_10 -> V_121 . V_137 = & V_138 ;
V_10 -> V_121 . V_139 = & V_140 ;
V_10 -> V_121 . V_87 = F_39 ( V_20 ) ;
V_10 -> V_121 . V_141 = V_142 ;
V_131 = F_40 ( & V_10 -> V_121 , V_20 , V_10 , & V_10 -> V_66 ) ;
if ( V_131 ) {
F_6 ( V_20 , L_26 ) ;
goto V_132;
}
F_41 ( V_125 , V_10 ) ;
return F_42 ( V_10 -> V_66 ) ;
V_132:
F_43 ( V_78 ) ;
return V_131 ;
}
static int F_44 ( struct V_124 * V_125 )
{
struct V_9 * V_10 = F_45 ( V_125 ) ;
if ( ! V_10 )
return 0 ;
if ( V_10 -> V_66 )
F_46 ( V_10 -> V_66 ) ;
F_12 ( V_10 ) ;
return 0 ;
}
