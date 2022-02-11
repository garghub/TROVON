static void F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned int V_6 ;
F_2 ( & V_1 -> V_7 ) ;
if ( V_3 -> V_8 == V_9 || ! V_5 )
return;
F_3 ( & V_5 -> V_10 ) ;
F_4 ( V_3 -> V_8 , V_1 -> V_11 -> V_12 , & V_6 ) ;
F_5 ( F_6 ( V_6 , V_5 -> V_13 ) ) ;
V_5 -> V_14 ++ ;
F_7 ( & V_5 -> V_10 ) ;
V_1 -> V_15 [ V_3 -> V_8 - V_1 -> V_16 ] . V_8 = V_9 ;
}
static void F_8 ( struct V_1 * V_1 , T_1 V_17 ,
unsigned V_18 )
{
T_1 V_19 ;
F_3 ( & V_1 -> V_7 ) ;
for ( V_19 = V_17 ; V_19 < V_17 + V_18 ; V_19 ++ ) {
struct V_2 * V_20 = & V_1 -> V_21 [ V_19 ] ;
F_1 ( V_1 , V_20 ) ;
V_20 -> V_5 = NULL ;
}
F_7 ( & V_1 -> V_7 ) ;
}
static struct V_22 * F_9 ( struct V_1 * V_1 ,
T_1 V_23 , unsigned int V_24 )
{
struct V_22 * V_25 ;
struct V_26 * V_27 ;
V_25 = F_10 ( V_1 -> V_28 , V_29 ) ;
if ( ! V_25 )
return F_11 ( - V_30 ) ;
V_27 = F_12 ( V_25 ) ;
if ( F_13 ( V_1 , V_23 , V_24 , V_27 ) ) {
F_14 ( V_25 , V_1 -> V_28 ) ;
return NULL ;
}
return V_25 ;
}
static void F_15 ( struct V_1 * V_1 , struct V_22 * V_25 )
{
struct V_26 * V_27 = F_12 ( V_25 ) ;
F_16 ( V_1 , V_27 ) ;
F_14 ( V_25 , V_1 -> V_28 ) ;
}
static void F_17 ( struct V_1 * V_1 , struct V_31 * V_31 )
{
T_1 V_17 = V_31 -> V_32 . V_33 / V_34 ;
T_1 V_18 = V_31 -> V_32 . V_35 / V_36 ;
struct V_22 * V_25 ;
do {
V_25 = F_9 ( V_1 , V_17 , V_18 ) ;
F_18 () ;
} while ( ! V_25 );
if ( F_19 ( V_25 ) ) {
F_20 ( L_1 ) ;
F_21 ( V_31 ) ;
return;
}
F_8 ( V_1 , V_17 , V_18 ) ;
F_15 ( V_1 , V_25 ) ;
}
static int F_22 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
return ( V_5 -> V_37 == V_1 -> V_11 -> V_12 ) ;
}
static T_2 F_23 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
struct V_38 * V_39 = V_5 -> V_40 ;
return V_39 -> V_41 * V_1 -> V_11 -> V_12 ;
}
static struct V_42 F_24 ( struct V_43 * V_11 ,
struct V_42 V_44 )
{
struct V_42 V_45 ;
int V_46 , V_47 , V_48 , V_49 ;
T_1 V_50 = V_44 . V_50 ;
V_45 . V_50 = 0 ;
F_4 ( V_50 , V_11 -> V_51 , & V_46 ) ;
V_45 . V_52 . V_53 = V_46 ;
F_25 ( V_50 , V_11 -> V_51 ) ;
F_4 ( V_50 , V_11 -> V_54 , & V_47 ) ;
V_45 . V_52 . V_55 = V_47 ;
F_25 ( V_50 , V_11 -> V_12 ) ;
F_4 ( V_50 , V_11 -> V_56 , & V_48 ) ;
V_45 . V_52 . V_39 = V_48 ;
F_25 ( V_50 , V_11 -> V_56 ) ;
F_4 ( V_50 , V_11 -> V_57 , & V_49 ) ;
V_45 . V_52 . V_58 = V_49 ;
F_25 ( V_50 , V_11 -> V_57 ) ;
V_45 . V_52 . V_59 = V_50 ;
return V_45 ;
}
static struct V_42 F_26 ( struct V_43 * V_11 , T_2 V_8 )
{
struct V_42 V_60 ;
V_60 . V_50 = V_8 ;
return F_24 ( V_11 , V_60 ) ;
}
static void F_27 ( struct V_61 * V_62 , struct V_4 * V_5 )
{
struct V_1 * V_1 = V_62 -> V_1 ;
F_28 ( ! V_5 ) ;
if ( V_62 -> V_63 ) {
F_3 ( & V_62 -> V_63 -> V_10 ) ;
F_5 ( ! F_22 ( V_1 , V_62 -> V_63 ) ) ;
F_7 ( & V_62 -> V_63 -> V_10 ) ;
}
V_62 -> V_63 = V_5 ;
}
static struct V_4 * F_29 ( struct V_1 * V_1 , struct V_61 * V_62 ,
unsigned long V_64 )
{
struct V_65 * V_58 = V_62 -> V_40 ;
struct V_38 * V_39 ;
struct V_4 * V_5 ;
F_3 ( & V_58 -> V_10 ) ;
V_39 = F_30 ( V_1 -> V_11 , V_62 -> V_40 , V_64 ) ;
if ( ! V_39 ) {
F_20 ( L_2 ) ;
F_7 ( & V_58 -> V_10 ) ;
return NULL ;
}
V_5 = & V_62 -> V_66 [ V_39 -> V_41 ] ;
F_31 ( & V_5 -> V_67 , & V_62 -> V_68 ) ;
F_7 ( & V_58 -> V_10 ) ;
V_39 -> V_69 = V_5 ;
F_32 ( V_5 -> V_13 , V_1 -> V_11 -> V_12 ) ;
V_5 -> V_37 = 0 ;
V_5 -> V_14 = 0 ;
F_33 ( & V_5 -> V_70 , 0 ) ;
return V_5 ;
}
static void F_34 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
struct V_61 * V_62 = V_5 -> V_62 ;
struct V_65 * V_58 = V_62 -> V_40 ;
F_3 ( & V_58 -> V_10 ) ;
F_35 ( V_1 -> V_11 , V_5 -> V_40 ) ;
F_36 ( & V_5 -> V_67 ) ;
F_7 ( & V_58 -> V_10 ) ;
}
static void F_37 ( struct V_1 * V_1 )
{
struct V_61 * V_62 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_1 -> V_71 ; V_19 ++ ) {
V_62 = & V_1 -> V_49 [ V_19 ] ;
if ( V_62 -> V_63 )
F_34 ( V_1 , V_62 -> V_63 ) ;
if ( V_62 -> V_72 )
F_34 ( V_1 , V_62 -> V_72 ) ;
}
}
static struct V_61 * F_38 ( struct V_1 * V_1 )
{
int V_73 = F_39 ( & V_1 -> V_74 ) ;
return & V_1 -> V_49 [ V_73 % V_1 -> V_71 ] ;
}
static void F_40 ( struct V_1 * V_1 )
{
struct V_61 * V_62 ;
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_1 -> V_71 ; V_19 ++ ) {
V_62 = & V_1 -> V_49 [ V_19 ] ;
F_41 ( V_1 -> V_75 , & V_62 -> V_76 ) ;
}
}
static void F_42 ( unsigned long V_77 )
{
struct V_1 * V_1 = (struct V_1 * ) V_77 ;
F_40 ( V_1 ) ;
F_43 ( & V_1 -> V_78 , V_79 + F_44 ( 10 ) ) ;
}
static void F_45 ( struct V_31 * V_31 )
{
struct V_80 * V_81 = V_31 -> V_82 ;
if ( V_31 -> V_83 )
F_20 ( L_3 , V_31 -> V_83 ) ;
F_46 ( V_81 ) ;
}
static int F_47 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
struct V_84 * V_85 = V_1 -> V_11 -> V_85 ;
struct V_86 * V_87 ;
struct V_22 * V_25 ;
struct V_31 * V_31 ;
struct V_88 * V_88 ;
int V_89 ;
int V_90 = V_1 -> V_11 -> V_12 ;
T_2 V_91 ;
F_48 ( V_92 ) ;
if ( F_49 ( V_5 -> V_13 , V_90 ) )
return 0 ;
V_31 = F_50 ( V_93 , 1 ) ;
if ( ! V_31 ) {
F_20 ( L_4 ) ;
return - V_30 ;
}
V_88 = F_10 ( V_1 -> V_94 , V_93 ) ;
if ( ! V_88 ) {
F_51 ( V_31 ) ;
return - V_30 ;
}
while ( ( V_89 = F_52 ( V_5 -> V_13 ,
V_90 ) ) < V_90 ) {
V_91 = ( V_5 -> V_40 -> V_41 * V_90 ) + V_89 ;
V_95:
F_3 ( & V_1 -> V_7 ) ;
V_87 = & V_1 -> V_15 [ V_91 - V_1 -> V_16 ] ;
if ( V_87 -> V_8 == V_9 ) {
F_7 ( & V_1 -> V_7 ) ;
continue;
}
V_25 = F_9 ( V_1 , V_87 -> V_8 , 1 ) ;
if ( F_53 ( V_25 ) ) {
F_7 ( & V_1 -> V_7 ) ;
F_18 () ;
goto V_95;
}
F_7 ( & V_1 -> V_7 ) ;
V_31 -> V_32 . V_33 = F_54 ( V_87 -> V_8 ) ;
V_31 -> V_96 = V_97 ;
V_31 -> V_82 = & V_92 ;
V_31 -> V_98 = F_45 ;
F_55 ( V_85 , V_31 , V_88 , V_36 , 0 ) ;
if ( F_56 ( V_1 , V_31 , V_25 , V_99 ) ) {
F_20 ( L_5 ) ;
F_15 ( V_1 , V_25 ) ;
goto V_100;
}
F_57 ( & V_92 ) ;
if ( V_31 -> V_83 ) {
F_15 ( V_1 , V_25 ) ;
goto V_100;
}
F_58 ( V_31 ) ;
F_59 ( & V_92 ) ;
V_31 -> V_32 . V_33 = F_54 ( V_87 -> V_8 ) ;
V_31 -> V_96 = V_101 ;
V_31 -> V_82 = & V_92 ;
V_31 -> V_98 = F_45 ;
F_55 ( V_85 , V_31 , V_88 , V_36 , 0 ) ;
if ( F_56 ( V_1 , V_31 , V_25 , V_99 ) ) {
F_20 ( L_6 ) ;
F_15 ( V_1 , V_25 ) ;
goto V_100;
}
F_57 ( & V_92 ) ;
F_15 ( V_1 , V_25 ) ;
if ( V_31 -> V_83 )
goto V_100;
F_58 ( V_31 ) ;
}
V_100:
F_14 ( V_88 , V_1 -> V_94 ) ;
F_51 ( V_31 ) ;
if ( ! F_49 ( V_5 -> V_13 , V_90 ) ) {
F_20 ( L_7 ) ;
return - V_102 ;
}
return 0 ;
}
static void F_60 ( struct V_103 * V_104 )
{
struct F_60 * V_105 = F_61 ( V_104 , struct F_60 ,
V_76 ) ;
struct V_1 * V_1 = V_105 -> V_1 ;
struct V_4 * V_5 = V_105 -> V_5 ;
struct V_43 * V_11 = V_1 -> V_11 ;
struct V_65 * V_58 = V_5 -> V_40 -> V_58 ;
struct V_61 * V_62 = & V_1 -> V_49 [ V_58 -> V_41 - V_1 -> V_106 ] ;
F_14 ( V_105 , V_1 -> V_107 ) ;
F_62 ( L_8 , V_5 -> V_40 -> V_41 ) ;
if ( F_47 ( V_1 , V_5 ) )
goto V_108;
if ( F_63 ( V_11 , V_5 -> V_40 ) )
goto V_108;
F_34 ( V_1 , V_5 ) ;
return;
V_108:
F_3 ( & V_62 -> V_10 ) ;
F_31 ( & V_5 -> V_109 , & V_62 -> V_110 ) ;
F_7 ( & V_62 -> V_10 ) ;
}
static struct V_4 * F_64 ( struct V_4 * V_111 ,
struct V_4 * V_112 )
{
if ( V_111 -> V_14 == V_112 -> V_14 )
return V_111 ;
return ( V_111 -> V_14 < V_112 -> V_14 ) ? V_112 : V_111 ;
}
static struct V_4 * F_65 ( struct V_61 * V_62 )
{
struct V_113 * V_110 = & V_62 -> V_110 ;
struct V_4 * V_114 , * V_115 ;
F_28 ( F_66 ( V_110 ) ) ;
V_115 = F_67 ( V_110 , struct V_4 , V_109 ) ;
F_68 (rblock, prio_list, prio)
V_115 = F_64 ( V_115 , V_114 ) ;
return V_115 ;
}
static void F_69 ( struct V_103 * V_104 )
{
struct V_61 * V_62 = F_61 ( V_104 , struct V_61 , V_76 ) ;
struct V_1 * V_1 = V_62 -> V_1 ;
struct V_65 * V_58 = V_62 -> V_40 ;
struct F_60 * V_105 ;
unsigned int V_116 ;
V_116 = V_1 -> V_11 -> V_56 / V_117 ;
if ( V_116 < V_1 -> V_71 )
V_116 = V_1 -> V_71 ;
F_3 ( & V_62 -> V_10 ) ;
while ( V_116 > V_58 -> V_118 &&
! F_66 ( & V_62 -> V_110 ) ) {
struct V_4 * V_114 = F_65 ( V_62 ) ;
struct V_38 * V_119 = V_114 -> V_40 ;
if ( ! V_114 -> V_14 )
break;
V_105 = F_10 ( V_1 -> V_107 , V_29 ) ;
if ( ! V_105 )
break;
F_70 ( & V_114 -> V_109 ) ;
F_28 ( ! F_22 ( V_1 , V_114 ) ) ;
F_62 ( L_9 , V_119 -> V_41 ) ;
V_105 -> V_1 = V_1 ;
V_105 -> V_5 = V_114 ;
F_71 ( & V_105 -> V_76 , F_60 ) ;
F_41 ( V_1 -> V_120 , & V_105 -> V_76 ) ;
V_116 -- ;
}
F_7 ( & V_62 -> V_10 ) ;
}
static void F_72 ( struct V_103 * V_104 )
{
struct F_60 * V_105 = F_61 ( V_104 , struct F_60 ,
V_76 ) ;
struct V_1 * V_1 = V_105 -> V_1 ;
struct V_4 * V_5 = V_105 -> V_5 ;
struct V_65 * V_58 = V_5 -> V_40 -> V_58 ;
struct V_61 * V_62 = & V_1 -> V_49 [ V_58 -> V_41 - V_1 -> V_106 ] ;
F_3 ( & V_62 -> V_10 ) ;
F_31 ( & V_5 -> V_109 , & V_62 -> V_110 ) ;
F_7 ( & V_62 -> V_10 ) ;
F_14 ( V_105 , V_1 -> V_107 ) ;
F_62 ( L_10 ,
V_5 -> V_40 -> V_41 ) ;
}
static struct V_61 * F_73 ( struct V_1 * V_1 , int V_121 )
{
unsigned int V_19 ;
struct V_61 * V_62 , * V_122 ;
if ( ! V_121 )
return F_38 ( V_1 ) ;
V_122 = & V_1 -> V_49 [ 0 ] ;
F_74 (rrpc, rlun, i) {
if ( V_62 -> V_40 -> V_118 >
V_122 -> V_40 -> V_118 )
V_122 = V_62 ;
}
return V_122 ;
}
static struct V_2 * F_75 ( struct V_1 * V_1 , T_1 V_23 ,
struct V_4 * V_5 , T_2 V_60 )
{
struct V_2 * V_20 ;
struct V_86 * V_87 ;
F_28 ( V_23 >= V_1 -> V_123 ) ;
V_20 = & V_1 -> V_21 [ V_23 ] ;
F_3 ( & V_1 -> V_7 ) ;
if ( V_20 -> V_5 )
F_1 ( V_1 , V_20 ) ;
V_20 -> V_8 = V_60 ;
V_20 -> V_5 = V_5 ;
V_87 = & V_1 -> V_15 [ V_20 -> V_8 - V_1 -> V_16 ] ;
V_87 -> V_8 = V_23 ;
F_7 ( & V_1 -> V_7 ) ;
return V_20 ;
}
static T_2 F_76 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
T_2 V_8 = V_9 ;
F_3 ( & V_5 -> V_10 ) ;
if ( F_22 ( V_1 , V_5 ) )
goto V_124;
V_8 = F_23 ( V_1 , V_5 ) + V_5 -> V_37 ;
V_5 -> V_37 ++ ;
V_124:
F_7 ( & V_5 -> V_10 ) ;
return V_8 ;
}
static struct V_2 * F_77 ( struct V_1 * V_1 , T_1 V_23 ,
int V_121 )
{
struct V_61 * V_62 ;
struct V_4 * V_5 ;
struct V_65 * V_58 ;
T_2 V_60 ;
V_62 = F_73 ( V_1 , V_121 ) ;
V_58 = V_62 -> V_40 ;
if ( ! V_121 && V_58 -> V_118 < V_1 -> V_71 * 4 )
return NULL ;
F_3 ( & V_62 -> V_10 ) ;
V_5 = V_62 -> V_63 ;
V_125:
V_60 = F_76 ( V_1 , V_5 ) ;
if ( V_60 == V_9 ) {
V_5 = F_29 ( V_1 , V_62 , 0 ) ;
if ( V_5 ) {
F_27 ( V_62 , V_5 ) ;
goto V_125;
}
if ( V_121 ) {
V_60 = F_76 ( V_1 , V_62 -> V_72 ) ;
if ( V_60 == V_9 ) {
V_5 = F_29 ( V_1 , V_62 , 1 ) ;
if ( ! V_5 ) {
F_20 ( L_11 ) ;
goto V_126;
}
V_62 -> V_72 = V_5 ;
V_60 = F_76 ( V_1 , V_62 -> V_72 ) ;
}
V_5 = V_62 -> V_72 ;
}
}
F_7 ( & V_62 -> V_10 ) ;
return F_75 ( V_1 , V_23 , V_5 , V_60 ) ;
V_126:
F_7 ( & V_62 -> V_10 ) ;
return NULL ;
}
static void F_78 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
struct F_60 * V_105 ;
V_105 = F_10 ( V_1 -> V_107 , V_29 ) ;
if ( ! V_105 ) {
F_20 ( L_12 ) ;
return;
}
V_105 -> V_1 = V_1 ;
V_105 -> V_5 = V_5 ;
F_71 ( & V_105 -> V_76 , F_72 ) ;
F_41 ( V_1 -> V_120 , & V_105 -> V_76 ) ;
}
static void F_79 ( struct V_1 * V_1 , struct V_127 * V_128 ,
T_1 V_23 , T_3 V_129 )
{
struct V_2 * V_130 ;
struct V_4 * V_5 ;
struct V_65 * V_58 ;
int V_131 , V_19 ;
for ( V_19 = 0 ; V_19 < V_129 ; V_19 ++ ) {
V_130 = & V_1 -> V_21 [ V_23 + V_19 ] ;
V_5 = V_130 -> V_5 ;
V_58 = V_5 -> V_40 -> V_58 ;
V_131 = F_39 ( & V_5 -> V_70 ) ;
if ( F_80 ( V_131 == V_1 -> V_11 -> V_12 ) ) {
struct V_38 * V_39 = V_5 -> V_40 ;
struct V_61 * V_62 = V_5 -> V_62 ;
F_3 ( & V_58 -> V_10 ) ;
V_58 -> V_132 -- ;
V_58 -> V_133 ++ ;
V_39 -> V_134 &= ~ V_135 ;
V_39 -> V_134 |= V_136 ;
F_81 ( & V_5 -> V_67 , & V_62 -> V_137 ) ;
F_7 ( & V_58 -> V_10 ) ;
F_78 ( V_1 , V_5 ) ;
}
}
}
static void F_82 ( struct V_22 * V_25 )
{
struct V_1 * V_1 = F_61 ( V_25 -> V_138 , struct V_1 , V_139 ) ;
struct V_127 * V_128 = F_83 ( V_25 ) ;
T_3 V_129 = V_25 -> V_123 ;
T_1 V_23 = F_84 ( V_25 -> V_31 ) - V_129 ;
if ( F_85 ( V_25 -> V_31 ) == V_101 )
F_79 ( V_1 , V_128 , V_23 , V_129 ) ;
F_51 ( V_25 -> V_31 ) ;
if ( V_128 -> V_64 & V_99 )
return;
F_86 ( V_1 , V_25 ) ;
if ( V_129 > 1 )
F_87 ( V_1 -> V_11 , V_25 -> V_140 , V_25 -> V_141 ) ;
if ( V_25 -> V_142 )
F_87 ( V_1 -> V_11 , V_25 -> V_142 , V_25 -> V_143 ) ;
F_14 ( V_25 , V_1 -> V_28 ) ;
}
static int F_88 ( struct V_1 * V_1 , struct V_31 * V_31 ,
struct V_22 * V_25 , unsigned long V_64 , int V_129 )
{
struct V_26 * V_44 = F_12 ( V_25 ) ;
struct V_2 * V_20 ;
T_1 V_23 = F_84 ( V_31 ) ;
int V_121 = V_64 & V_99 ;
int V_19 ;
if ( ! V_121 && F_89 ( V_1 , V_31 , V_25 ) ) {
F_87 ( V_1 -> V_11 , V_25 -> V_140 , V_25 -> V_141 ) ;
return V_144 ;
}
for ( V_19 = 0 ; V_19 < V_129 ; V_19 ++ ) {
F_28 ( ! ( V_23 + V_19 >= 0 && V_23 + V_19 < V_1 -> V_123 ) ) ;
V_20 = & V_1 -> V_21 [ V_23 + V_19 ] ;
if ( V_20 -> V_5 ) {
V_25 -> V_140 [ V_19 ] = F_26 ( V_1 -> V_11 ,
V_20 -> V_8 ) ;
} else {
F_28 ( V_121 ) ;
F_16 ( V_1 , V_44 ) ;
F_87 ( V_1 -> V_11 , V_25 -> V_140 ,
V_25 -> V_141 ) ;
return V_145 ;
}
}
V_25 -> V_146 = V_147 ;
return V_148 ;
}
static int F_90 ( struct V_1 * V_1 , struct V_31 * V_31 , struct V_22 * V_25 ,
unsigned long V_64 )
{
struct V_127 * V_128 = F_83 ( V_25 ) ;
int V_121 = V_64 & V_99 ;
T_1 V_23 = F_84 ( V_31 ) ;
struct V_2 * V_20 ;
if ( ! V_121 && F_89 ( V_1 , V_31 , V_25 ) )
return V_144 ;
F_28 ( ! ( V_23 >= 0 && V_23 < V_1 -> V_123 ) ) ;
V_20 = & V_1 -> V_21 [ V_23 ] ;
if ( V_20 -> V_5 ) {
V_25 -> V_42 = F_26 ( V_1 -> V_11 , V_20 -> V_8 ) ;
} else {
F_28 ( V_121 ) ;
F_86 ( V_1 , V_25 ) ;
return V_145 ;
}
V_25 -> V_146 = V_147 ;
V_128 -> V_8 = V_20 ;
return V_148 ;
}
static int F_91 ( struct V_1 * V_1 , struct V_31 * V_31 ,
struct V_22 * V_25 , unsigned long V_64 , int V_129 )
{
struct V_26 * V_44 = F_12 ( V_25 ) ;
struct V_2 * V_130 ;
T_1 V_23 = F_84 ( V_31 ) ;
int V_121 = V_64 & V_99 ;
int V_19 ;
if ( ! V_121 && F_89 ( V_1 , V_31 , V_25 ) ) {
F_87 ( V_1 -> V_11 , V_25 -> V_140 , V_25 -> V_141 ) ;
return V_144 ;
}
for ( V_19 = 0 ; V_19 < V_129 ; V_19 ++ ) {
V_130 = F_77 ( V_1 , V_23 + V_19 , V_121 ) ;
if ( ! V_130 ) {
F_28 ( V_121 ) ;
F_16 ( V_1 , V_44 ) ;
F_87 ( V_1 -> V_11 , V_25 -> V_140 ,
V_25 -> V_141 ) ;
F_40 ( V_1 ) ;
return V_144 ;
}
V_25 -> V_140 [ V_19 ] = F_26 ( V_1 -> V_11 ,
V_130 -> V_8 ) ;
}
V_25 -> V_146 = V_149 ;
return V_148 ;
}
static int F_92 ( struct V_1 * V_1 , struct V_31 * V_31 ,
struct V_22 * V_25 , unsigned long V_64 )
{
struct V_127 * V_128 = F_83 ( V_25 ) ;
struct V_2 * V_130 ;
int V_121 = V_64 & V_99 ;
T_1 V_23 = F_84 ( V_31 ) ;
if ( ! V_121 && F_89 ( V_1 , V_31 , V_25 ) )
return V_144 ;
V_130 = F_77 ( V_1 , V_23 , V_121 ) ;
if ( ! V_130 ) {
F_28 ( V_121 ) ;
F_86 ( V_1 , V_25 ) ;
F_40 ( V_1 ) ;
return V_144 ;
}
V_25 -> V_42 = F_26 ( V_1 -> V_11 , V_130 -> V_8 ) ;
V_25 -> V_146 = V_149 ;
V_128 -> V_8 = V_130 ;
return V_148 ;
}
static int F_93 ( struct V_1 * V_1 , struct V_31 * V_31 ,
struct V_22 * V_25 , unsigned long V_64 , T_3 V_129 )
{
if ( V_129 > 1 ) {
V_25 -> V_140 = F_94 ( V_1 -> V_11 , V_150 ,
& V_25 -> V_141 ) ;
if ( ! V_25 -> V_140 ) {
F_20 ( L_13 ) ;
return V_151 ;
}
if ( F_95 ( V_31 ) == V_101 )
return F_91 ( V_1 , V_31 , V_25 , V_64 ,
V_129 ) ;
return F_88 ( V_1 , V_31 , V_25 , V_64 , V_129 ) ;
}
if ( F_95 ( V_31 ) == V_101 )
return F_92 ( V_1 , V_31 , V_25 , V_64 ) ;
return F_90 ( V_1 , V_31 , V_25 , V_64 ) ;
}
static int F_56 ( struct V_1 * V_1 , struct V_31 * V_31 ,
struct V_22 * V_25 , unsigned long V_64 )
{
int V_126 ;
struct V_127 * V_152 = F_83 ( V_25 ) ;
T_3 V_123 = F_96 ( V_31 ) ;
int V_153 = F_97 ( V_31 ) << 9 ;
if ( V_153 < V_1 -> V_11 -> V_154 )
return V_151 ;
else if ( V_153 > V_1 -> V_11 -> V_155 )
return V_151 ;
V_126 = F_93 ( V_1 , V_31 , V_25 , V_64 , V_123 ) ;
if ( V_126 )
return V_126 ;
F_98 ( V_31 ) ;
V_25 -> V_31 = V_31 ;
V_25 -> V_138 = & V_1 -> V_139 ;
V_25 -> V_123 = V_123 ;
V_152 -> V_64 = V_64 ;
V_126 = F_99 ( V_1 -> V_11 , V_25 ) ;
if ( V_126 ) {
F_20 ( L_14 , V_126 ) ;
F_51 ( V_31 ) ;
if ( ! ( V_64 & V_99 ) ) {
F_86 ( V_1 , V_25 ) ;
if ( V_25 -> V_123 > 1 )
F_87 ( V_1 -> V_11 ,
V_25 -> V_140 , V_25 -> V_141 ) ;
}
return V_151 ;
}
return V_148 ;
}
static T_4 F_100 ( struct V_84 * V_85 , struct V_31 * V_31 )
{
struct V_1 * V_1 = V_85 -> V_156 ;
struct V_22 * V_25 ;
int V_126 ;
if ( V_31 -> V_96 & V_157 ) {
F_17 ( V_1 , V_31 ) ;
return V_158 ;
}
V_25 = F_10 ( V_1 -> V_28 , V_150 ) ;
if ( ! V_25 ) {
F_101 ( L_15 ) ;
F_21 ( V_31 ) ;
return V_158 ;
}
memset ( V_25 , 0 , sizeof( struct V_22 ) ) ;
V_126 = F_56 ( V_1 , V_31 , V_25 , V_159 ) ;
switch ( V_126 ) {
case V_148 :
return V_158 ;
case V_151 :
F_21 ( V_31 ) ;
break;
case V_145 :
F_102 ( V_31 ) ;
break;
case V_144 :
F_3 ( & V_1 -> V_160 ) ;
F_103 ( & V_1 -> V_161 , V_31 ) ;
F_7 ( & V_1 -> V_160 ) ;
F_41 ( V_1 -> V_120 , & V_1 -> V_162 ) ;
break;
}
F_14 ( V_25 , V_1 -> V_28 ) ;
return V_158 ;
}
static void F_104 ( struct V_103 * V_104 )
{
struct V_1 * V_1 = F_61 ( V_104 , struct V_1 , V_162 ) ;
struct V_163 V_164 ;
struct V_31 * V_31 ;
F_105 ( & V_164 ) ;
F_3 ( & V_1 -> V_160 ) ;
F_106 ( & V_164 , & V_1 -> V_161 ) ;
F_105 ( & V_1 -> V_161 ) ;
F_7 ( & V_1 -> V_160 ) ;
while ( ( V_31 = F_107 ( & V_164 ) ) )
F_100 ( V_1 -> V_165 -> V_166 , V_31 ) ;
}
static void F_108 ( struct V_1 * V_1 )
{
struct V_61 * V_62 ;
int V_19 ;
if ( V_1 -> V_75 )
F_109 ( V_1 -> V_75 ) ;
if ( V_1 -> V_120 )
F_109 ( V_1 -> V_120 ) ;
if ( ! V_1 -> V_49 )
return;
for ( V_19 = 0 ; V_19 < V_1 -> V_71 ; V_19 ++ ) {
V_62 = & V_1 -> V_49 [ V_19 ] ;
if ( ! V_62 -> V_66 )
break;
F_110 ( V_62 -> V_66 ) ;
}
}
static int F_111 ( struct V_1 * V_1 )
{
V_1 -> V_75 = F_112 ( L_16 , V_167 | V_168 ,
V_1 -> V_71 ) ;
if ( ! V_1 -> V_75 )
return - V_30 ;
V_1 -> V_120 = F_112 ( L_17 , V_167 , 1 ) ;
if ( ! V_1 -> V_120 )
return - V_30 ;
F_113 ( & V_1 -> V_78 , F_42 , ( unsigned long ) V_1 ) ;
return 0 ;
}
static void F_114 ( struct V_1 * V_1 )
{
F_110 ( V_1 -> V_15 ) ;
F_110 ( V_1 -> V_21 ) ;
}
static int F_115 ( T_2 V_17 , T_5 V_169 , T_6 * V_170 , void * V_171 )
{
struct V_1 * V_1 = (struct V_1 * ) V_171 ;
struct V_43 * V_11 = V_1 -> V_11 ;
struct V_2 * V_8 = V_1 -> V_21 + V_17 ;
struct V_86 * V_172 = V_1 -> V_15 ;
T_1 V_173 = V_11 -> V_174 * ( V_11 -> V_154 >> 9 ) ;
T_2 V_175 = V_17 + V_169 ;
T_2 V_19 ;
if ( F_80 ( V_175 > V_11 -> V_174 ) ) {
F_20 ( L_18 ) ;
return - V_176 ;
}
for ( V_19 = 0 ; V_19 < V_169 ; V_19 ++ ) {
T_2 V_177 = F_116 ( V_170 [ V_19 ] ) ;
if ( F_80 ( V_177 >= V_173 && V_177 != V_178 ) ) {
F_20 ( L_19 ) ;
return - V_176 ;
}
if ( ! V_177 )
continue;
V_8 [ V_19 ] . V_8 = V_177 ;
V_172 [ V_177 ] . V_8 = V_17 + V_19 ;
}
return 0 ;
}
static int F_117 ( struct V_1 * V_1 )
{
struct V_43 * V_11 = V_1 -> V_11 ;
T_1 V_19 ;
int V_179 ;
V_1 -> V_21 = F_118 ( sizeof( struct V_2 ) * V_1 -> V_123 ) ;
if ( ! V_1 -> V_21 )
return - V_30 ;
V_1 -> V_15 = F_119 ( sizeof( struct V_86 )
* V_1 -> V_123 ) ;
if ( ! V_1 -> V_15 )
return - V_30 ;
for ( V_19 = 0 ; V_19 < V_1 -> V_123 ; V_19 ++ ) {
struct V_2 * V_130 = & V_1 -> V_21 [ V_19 ] ;
struct V_86 * V_44 = & V_1 -> V_15 [ V_19 ] ;
V_130 -> V_8 = V_9 ;
V_44 -> V_8 = V_9 ;
}
if ( ! V_11 -> V_180 -> V_181 )
return 0 ;
V_179 = V_11 -> V_180 -> V_181 ( V_11 , 0 , V_11 -> V_174 ,
F_115 , V_1 ) ;
if ( V_179 ) {
F_20 ( L_20 ) ;
return - V_176 ;
}
return 0 ;
}
static int F_120 ( struct V_1 * V_1 )
{
F_121 ( & V_182 ) ;
if ( ! V_183 ) {
V_183 = F_122 ( L_21 ,
sizeof( struct F_60 ) , 0 , 0 , NULL ) ;
if ( ! V_183 ) {
F_123 ( & V_182 ) ;
return - V_30 ;
}
V_184 = F_122 ( L_22 ,
sizeof( struct V_22 ) + sizeof( struct V_127 ) ,
0 , 0 , NULL ) ;
if ( ! V_184 ) {
F_124 ( V_183 ) ;
F_123 ( & V_182 ) ;
return - V_30 ;
}
}
F_123 ( & V_182 ) ;
V_1 -> V_94 = F_125 ( V_185 , 0 ) ;
if ( ! V_1 -> V_94 )
return - V_30 ;
V_1 -> V_107 = F_126 ( V_1 -> V_11 -> V_71 ,
V_183 ) ;
if ( ! V_1 -> V_107 )
return - V_30 ;
V_1 -> V_28 = F_126 ( 64 , V_184 ) ;
if ( ! V_1 -> V_28 )
return - V_30 ;
F_127 ( & V_1 -> V_186 . V_10 ) ;
F_128 ( & V_1 -> V_186 . V_187 ) ;
return 0 ;
}
static void F_129 ( struct V_1 * V_1 )
{
F_130 ( V_1 -> V_94 ) ;
F_130 ( V_1 -> V_107 ) ;
F_130 ( V_1 -> V_28 ) ;
}
static void F_131 ( struct V_1 * V_1 )
{
F_132 ( V_1 -> V_49 ) ;
}
static int F_133 ( struct V_1 * V_1 , int V_188 , int V_189 )
{
struct V_43 * V_11 = V_1 -> V_11 ;
struct V_61 * V_62 ;
int V_19 , V_190 ;
if ( V_11 -> V_12 > V_191 * V_192 ) {
F_20 ( L_23 ) ;
return - V_176 ;
}
F_127 ( & V_1 -> V_7 ) ;
V_1 -> V_49 = F_134 ( V_1 -> V_71 , sizeof( struct V_61 ) ,
V_150 ) ;
if ( ! V_1 -> V_49 )
return - V_30 ;
for ( V_19 = 0 ; V_19 < V_1 -> V_71 ; V_19 ++ ) {
struct V_65 * V_58 = V_11 -> V_193 -> V_194 ( V_11 , V_188 + V_19 ) ;
V_62 = & V_1 -> V_49 [ V_19 ] ;
V_62 -> V_1 = V_1 ;
V_62 -> V_40 = V_58 ;
F_128 ( & V_62 -> V_110 ) ;
F_128 ( & V_62 -> V_68 ) ;
F_128 ( & V_62 -> V_137 ) ;
F_71 ( & V_62 -> V_76 , F_69 ) ;
F_127 ( & V_62 -> V_10 ) ;
V_1 -> V_195 += V_11 -> V_56 ;
V_1 -> V_123 += V_11 -> V_196 ;
V_62 -> V_66 = F_118 ( sizeof( struct V_4 ) *
V_1 -> V_11 -> V_56 ) ;
if ( ! V_62 -> V_66 )
goto V_126;
for ( V_190 = 0 ; V_190 < V_1 -> V_11 -> V_56 ; V_190 ++ ) {
struct V_4 * V_5 = & V_62 -> V_66 [ V_190 ] ;
struct V_38 * V_39 = & V_58 -> V_66 [ V_190 ] ;
V_5 -> V_40 = V_39 ;
V_5 -> V_62 = V_62 ;
F_128 ( & V_5 -> V_109 ) ;
F_127 ( & V_5 -> V_10 ) ;
}
}
return 0 ;
V_126:
return - V_30 ;
}
static void F_135 ( struct V_1 * V_1 )
{
F_108 ( V_1 ) ;
F_114 ( V_1 ) ;
F_129 ( V_1 ) ;
F_131 ( V_1 ) ;
F_132 ( V_1 ) ;
}
static void F_136 ( void * V_171 )
{
struct V_1 * V_1 = V_171 ;
F_137 ( & V_1 -> V_78 ) ;
F_138 ( V_1 -> V_75 ) ;
F_138 ( V_1 -> V_120 ) ;
F_135 ( V_1 ) ;
}
static T_1 F_139 ( void * V_171 )
{
struct V_1 * V_1 = V_171 ;
struct V_43 * V_11 = V_1 -> V_11 ;
T_1 V_197 , V_198 ;
V_197 = V_1 -> V_71 * V_11 -> V_199 * 4 ;
V_198 = V_1 -> V_123 - V_197 ;
if ( V_197 > V_1 -> V_123 ) {
F_20 ( L_24 ) ;
return 0 ;
}
F_25 ( V_198 , 10 ) ;
return V_198 * 9 * V_34 ;
}
static void F_140 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
struct V_43 * V_11 = V_1 -> V_11 ;
int V_200 ;
struct V_2 * V_23 ;
T_2 V_60 , V_201 ;
for ( V_200 = 0 ; V_200 < V_11 -> V_12 ; V_200 ++ ) {
V_60 = F_23 ( V_1 , V_5 ) + V_200 ;
V_201 = V_1 -> V_15 [ V_60 ] . V_8 ;
if ( V_201 == V_9 )
continue;
V_23 = & V_1 -> V_21 [ V_201 ] ;
if ( V_60 == V_23 -> V_8 ) {
V_23 -> V_5 = V_5 ;
} else {
F_141 ( V_200 , V_5 -> V_13 ) ;
V_5 -> V_14 ++ ;
}
}
}
static int F_142 ( struct V_1 * V_1 )
{
struct V_61 * V_62 ;
struct V_4 * V_5 ;
int V_202 , V_203 ;
for ( V_202 = 0 ; V_202 < V_1 -> V_71 ; V_202 ++ ) {
V_62 = & V_1 -> V_49 [ V_202 ] ;
for ( V_203 = 0 ; V_203 < V_1 -> V_11 -> V_56 ;
V_203 ++ ) {
V_5 = & V_62 -> V_66 [ V_203 ] ;
F_140 ( V_1 , V_5 ) ;
}
}
return 0 ;
}
static int F_143 ( struct V_1 * V_1 )
{
struct V_61 * V_62 ;
struct V_4 * V_5 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_1 -> V_71 ; V_19 ++ ) {
V_62 = & V_1 -> V_49 [ V_19 ] ;
V_5 = F_29 ( V_1 , V_62 , 0 ) ;
if ( ! V_5 )
goto V_126;
F_27 ( V_62 , V_5 ) ;
V_5 = F_29 ( V_1 , V_62 , 1 ) ;
if ( ! V_5 )
goto V_126;
V_62 -> V_72 = V_5 ;
}
return 0 ;
V_126:
F_37 ( V_1 ) ;
return - V_176 ;
}
static void * F_144 ( struct V_43 * V_11 , struct V_204 * V_205 ,
int V_188 , int V_189 )
{
struct V_84 * V_206 = V_11 -> V_85 ;
struct V_84 * V_207 = V_205 -> V_166 ;
struct V_1 * V_1 ;
int V_179 ;
if ( ! ( V_11 -> V_208 . V_209 & V_210 ) ) {
F_20 ( L_25 ,
V_11 -> V_208 . V_209 ) ;
return F_11 ( - V_176 ) ;
}
V_1 = F_145 ( sizeof( struct V_1 ) , V_150 ) ;
if ( ! V_1 )
return F_11 ( - V_30 ) ;
V_1 -> V_139 . V_211 = & V_212 ;
V_1 -> V_11 = V_11 ;
V_1 -> V_165 = V_205 ;
F_105 ( & V_1 -> V_161 ) ;
F_127 ( & V_1 -> V_160 ) ;
F_71 ( & V_1 -> V_162 , F_104 ) ;
V_1 -> V_71 = V_189 - V_188 + 1 ;
F_33 ( & V_1 -> V_74 , - 1 ) ;
V_179 = F_133 ( V_1 , V_188 , V_189 ) ;
if ( V_179 ) {
F_20 ( L_26 ) ;
goto V_126;
}
V_1 -> V_16 = V_11 -> V_196 * V_188 ;
V_1 -> V_106 = V_188 ;
V_179 = F_120 ( V_1 ) ;
if ( V_179 ) {
F_20 ( L_27 ) ;
goto V_126;
}
V_179 = F_117 ( V_1 ) ;
if ( V_179 ) {
F_20 ( L_28 ) ;
goto V_126;
}
V_179 = F_142 ( V_1 ) ;
if ( V_179 ) {
F_20 ( L_29 ) ;
goto V_126;
}
V_179 = F_143 ( V_1 ) ;
if ( V_179 ) {
F_20 ( L_30 ) ;
goto V_126;
}
V_179 = F_111 ( V_1 ) ;
if ( V_179 ) {
F_20 ( L_31 ) ;
goto V_126;
}
F_146 ( V_207 , F_147 ( V_206 ) ) ;
F_148 ( V_207 , F_149 ( V_206 ) ) ;
F_150 ( L_32 ,
V_1 -> V_71 , ( unsigned long long ) V_1 -> V_123 ) ;
F_43 ( & V_1 -> V_78 , V_79 + F_44 ( 10 ) ) ;
return V_1 ;
V_126:
F_135 ( V_1 ) ;
return F_11 ( V_179 ) ;
}
static int T_7 F_151 ( void )
{
return F_152 ( & V_212 ) ;
}
static void F_153 ( void )
{
F_154 ( & V_212 ) ;
}
