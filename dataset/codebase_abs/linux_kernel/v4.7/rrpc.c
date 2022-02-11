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
int V_41 = V_39 -> V_42 % ( V_1 -> V_11 -> V_43 * V_1 -> V_44 ) ;
return V_41 * V_1 -> V_11 -> V_12 ;
}
static T_2 F_24 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
struct V_38 * V_39 = V_5 -> V_40 ;
return V_39 -> V_42 * V_1 -> V_11 -> V_12 ;
}
static struct V_45 F_25 ( struct V_46 * V_11 ,
struct V_45 V_47 )
{
struct V_45 V_48 ;
int V_49 , V_50 , V_51 , V_52 ;
T_1 V_53 = V_47 . V_53 ;
V_48 . V_53 = 0 ;
F_4 ( V_53 , V_11 -> V_54 , & V_49 ) ;
V_48 . V_55 . V_56 = V_49 ;
F_26 ( V_53 , V_11 -> V_54 ) ;
F_4 ( V_53 , V_11 -> V_57 , & V_50 ) ;
V_48 . V_55 . V_58 = V_50 ;
F_26 ( V_53 , V_11 -> V_57 ) ;
F_4 ( V_53 , V_11 -> V_43 , & V_51 ) ;
V_48 . V_55 . V_39 = V_51 ;
F_26 ( V_53 , V_11 -> V_43 ) ;
F_4 ( V_53 , V_11 -> V_59 , & V_52 ) ;
V_48 . V_55 . V_60 = V_52 ;
F_26 ( V_53 , V_11 -> V_59 ) ;
V_48 . V_55 . V_61 = V_53 ;
return V_48 ;
}
static struct V_45 F_27 ( struct V_46 * V_11 , T_2 V_8 )
{
struct V_45 V_62 ;
V_62 . V_53 = V_8 ;
return F_25 ( V_11 , V_62 ) ;
}
static void F_28 ( struct V_63 * V_64 , struct V_4 * V_5 )
{
struct V_1 * V_1 = V_64 -> V_1 ;
F_29 ( ! V_5 ) ;
if ( V_64 -> V_65 ) {
F_3 ( & V_64 -> V_65 -> V_10 ) ;
F_5 ( ! F_22 ( V_1 , V_64 -> V_65 ) ) ;
F_7 ( & V_64 -> V_65 -> V_10 ) ;
}
V_64 -> V_65 = V_5 ;
}
static struct V_4 * F_30 ( struct V_1 * V_1 , struct V_63 * V_64 ,
unsigned long V_66 )
{
struct V_67 * V_60 = V_64 -> V_40 ;
struct V_38 * V_39 ;
struct V_4 * V_5 ;
F_3 ( & V_60 -> V_10 ) ;
V_39 = F_31 ( V_1 -> V_11 , V_64 -> V_40 , V_66 ) ;
if ( ! V_39 ) {
F_20 ( L_2 ) ;
F_7 ( & V_60 -> V_10 ) ;
return NULL ;
}
V_5 = F_32 ( V_64 , V_39 -> V_42 ) ;
F_33 ( & V_5 -> V_68 , & V_64 -> V_69 ) ;
F_7 ( & V_60 -> V_10 ) ;
V_39 -> V_70 = V_5 ;
F_34 ( V_5 -> V_13 , V_1 -> V_11 -> V_12 ) ;
V_5 -> V_37 = 0 ;
V_5 -> V_14 = 0 ;
F_35 ( & V_5 -> V_71 , 0 ) ;
return V_5 ;
}
static void F_36 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
struct V_63 * V_64 = V_5 -> V_64 ;
struct V_67 * V_60 = V_64 -> V_40 ;
F_3 ( & V_60 -> V_10 ) ;
F_37 ( V_1 -> V_11 , V_5 -> V_40 ) ;
F_38 ( & V_5 -> V_68 ) ;
F_7 ( & V_60 -> V_10 ) ;
}
static void F_39 ( struct V_1 * V_1 )
{
struct V_63 * V_64 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_1 -> V_44 ; V_19 ++ ) {
V_64 = & V_1 -> V_52 [ V_19 ] ;
if ( V_64 -> V_65 )
F_36 ( V_1 , V_64 -> V_65 ) ;
if ( V_64 -> V_72 )
F_36 ( V_1 , V_64 -> V_72 ) ;
}
}
static struct V_63 * F_40 ( struct V_1 * V_1 )
{
int V_73 = F_41 ( & V_1 -> V_74 ) ;
return & V_1 -> V_52 [ V_73 % V_1 -> V_44 ] ;
}
static void F_42 ( struct V_1 * V_1 )
{
struct V_63 * V_64 ;
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_1 -> V_44 ; V_19 ++ ) {
V_64 = & V_1 -> V_52 [ V_19 ] ;
F_43 ( V_1 -> V_75 , & V_64 -> V_76 ) ;
}
}
static void F_44 ( unsigned long V_77 )
{
struct V_1 * V_1 = (struct V_1 * ) V_77 ;
F_42 ( V_1 ) ;
F_45 ( & V_1 -> V_78 , V_79 + F_46 ( 10 ) ) ;
}
static void F_47 ( struct V_31 * V_31 )
{
struct V_80 * V_81 = V_31 -> V_82 ;
if ( V_31 -> V_83 )
F_20 ( L_3 , V_31 -> V_83 ) ;
F_48 ( V_81 ) ;
}
static int F_49 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
struct V_84 * V_85 = V_1 -> V_11 -> V_85 ;
struct V_86 * V_87 ;
struct V_22 * V_25 ;
struct V_31 * V_31 ;
struct V_88 * V_88 ;
int V_89 ;
int V_90 = V_1 -> V_11 -> V_12 ;
T_2 V_91 ;
F_50 ( V_92 ) ;
if ( F_51 ( V_5 -> V_13 , V_90 ) )
return 0 ;
V_31 = F_52 ( V_93 , 1 ) ;
if ( ! V_31 ) {
F_20 ( L_4 ) ;
return - V_30 ;
}
V_88 = F_10 ( V_1 -> V_94 , V_93 ) ;
if ( ! V_88 ) {
F_53 ( V_31 ) ;
return - V_30 ;
}
while ( ( V_89 = F_54 ( V_5 -> V_13 ,
V_90 ) ) < V_90 ) {
V_91 = V_5 -> V_40 -> V_42 * V_90 + V_89 ;
V_95:
F_3 ( & V_1 -> V_7 ) ;
V_87 = & V_1 -> V_15 [ V_91 - V_1 -> V_16 ] ;
if ( V_87 -> V_8 == V_9 ) {
F_7 ( & V_1 -> V_7 ) ;
continue;
}
V_25 = F_9 ( V_1 , V_87 -> V_8 , 1 ) ;
if ( F_55 ( V_25 ) ) {
F_7 ( & V_1 -> V_7 ) ;
F_18 () ;
goto V_95;
}
F_7 ( & V_1 -> V_7 ) ;
V_31 -> V_32 . V_33 = F_56 ( V_87 -> V_8 ) ;
V_31 -> V_96 = V_97 ;
V_31 -> V_82 = & V_92 ;
V_31 -> V_98 = F_47 ;
F_57 ( V_85 , V_31 , V_88 , V_36 , 0 ) ;
if ( F_58 ( V_1 , V_31 , V_25 , V_99 ) ) {
F_20 ( L_5 ) ;
F_15 ( V_1 , V_25 ) ;
goto V_100;
}
F_59 ( & V_92 ) ;
if ( V_31 -> V_83 ) {
F_15 ( V_1 , V_25 ) ;
goto V_100;
}
F_60 ( V_31 ) ;
F_61 ( & V_92 ) ;
V_31 -> V_32 . V_33 = F_56 ( V_87 -> V_8 ) ;
V_31 -> V_96 = V_101 ;
V_31 -> V_82 = & V_92 ;
V_31 -> V_98 = F_47 ;
F_57 ( V_85 , V_31 , V_88 , V_36 , 0 ) ;
if ( F_58 ( V_1 , V_31 , V_25 , V_99 ) ) {
F_20 ( L_6 ) ;
F_15 ( V_1 , V_25 ) ;
goto V_100;
}
F_59 ( & V_92 ) ;
F_15 ( V_1 , V_25 ) ;
if ( V_31 -> V_83 )
goto V_100;
F_60 ( V_31 ) ;
}
V_100:
F_14 ( V_88 , V_1 -> V_94 ) ;
F_53 ( V_31 ) ;
if ( ! F_51 ( V_5 -> V_13 , V_90 ) ) {
F_20 ( L_7 ) ;
return - V_102 ;
}
return 0 ;
}
static void F_62 ( struct V_103 * V_104 )
{
struct F_62 * V_105 = F_63 ( V_104 , struct F_62 ,
V_76 ) ;
struct V_1 * V_1 = V_105 -> V_1 ;
struct V_4 * V_5 = V_105 -> V_5 ;
struct V_63 * V_64 = V_5 -> V_64 ;
struct V_46 * V_11 = V_1 -> V_11 ;
F_14 ( V_105 , V_1 -> V_106 ) ;
F_64 ( L_8 , V_5 -> V_40 -> V_42 ) ;
if ( F_49 ( V_1 , V_5 ) )
goto V_107;
if ( F_65 ( V_11 , V_5 -> V_40 ) )
goto V_107;
F_36 ( V_1 , V_5 ) ;
return;
V_107:
F_3 ( & V_64 -> V_10 ) ;
F_33 ( & V_5 -> V_108 , & V_64 -> V_109 ) ;
F_7 ( & V_64 -> V_10 ) ;
}
static struct V_4 * F_66 ( struct V_4 * V_110 ,
struct V_4 * V_111 )
{
if ( V_110 -> V_14 == V_111 -> V_14 )
return V_110 ;
return ( V_110 -> V_14 < V_111 -> V_14 ) ? V_111 : V_110 ;
}
static struct V_4 * F_67 ( struct V_63 * V_64 )
{
struct V_112 * V_109 = & V_64 -> V_109 ;
struct V_4 * V_113 , * V_114 ;
F_29 ( F_68 ( V_109 ) ) ;
V_114 = F_69 ( V_109 , struct V_4 , V_108 ) ;
F_70 (rblock, prio_list, prio)
V_114 = F_66 ( V_114 , V_113 ) ;
return V_114 ;
}
static void F_71 ( struct V_103 * V_104 )
{
struct V_63 * V_64 = F_63 ( V_104 , struct V_63 , V_76 ) ;
struct V_1 * V_1 = V_64 -> V_1 ;
struct V_67 * V_60 = V_64 -> V_40 ;
struct F_62 * V_105 ;
unsigned int V_115 ;
V_115 = V_1 -> V_11 -> V_43 / V_116 ;
if ( V_115 < V_1 -> V_44 )
V_115 = V_1 -> V_44 ;
F_3 ( & V_64 -> V_10 ) ;
while ( V_115 > V_60 -> V_117 &&
! F_68 ( & V_64 -> V_109 ) ) {
struct V_4 * V_113 = F_67 ( V_64 ) ;
struct V_38 * V_118 = V_113 -> V_40 ;
if ( ! V_113 -> V_14 )
break;
V_105 = F_10 ( V_1 -> V_106 , V_29 ) ;
if ( ! V_105 )
break;
F_72 ( & V_113 -> V_108 ) ;
F_29 ( ! F_22 ( V_1 , V_113 ) ) ;
F_64 ( L_9 , V_118 -> V_42 ) ;
V_105 -> V_1 = V_1 ;
V_105 -> V_5 = V_113 ;
F_73 ( & V_105 -> V_76 , F_62 ) ;
F_43 ( V_1 -> V_119 , & V_105 -> V_76 ) ;
V_115 -- ;
}
F_7 ( & V_64 -> V_10 ) ;
}
static void F_74 ( struct V_103 * V_104 )
{
struct F_62 * V_105 = F_63 ( V_104 , struct F_62 ,
V_76 ) ;
struct V_1 * V_1 = V_105 -> V_1 ;
struct V_4 * V_5 = V_105 -> V_5 ;
struct V_63 * V_64 = V_5 -> V_64 ;
struct V_67 * V_60 = V_5 -> V_40 -> V_60 ;
struct V_38 * V_39 = V_5 -> V_40 ;
F_3 ( & V_64 -> V_10 ) ;
F_33 ( & V_5 -> V_108 , & V_64 -> V_109 ) ;
F_7 ( & V_64 -> V_10 ) ;
F_3 ( & V_60 -> V_10 ) ;
V_60 -> V_120 -- ;
V_60 -> V_121 ++ ;
V_39 -> V_122 &= ~ V_123 ;
V_39 -> V_122 |= V_124 ;
F_75 ( & V_5 -> V_68 , & V_64 -> V_125 ) ;
F_7 ( & V_60 -> V_10 ) ;
F_14 ( V_105 , V_1 -> V_106 ) ;
F_64 ( L_10 ,
V_5 -> V_40 -> V_42 ) ;
}
static struct V_63 * F_76 ( struct V_1 * V_1 , int V_126 )
{
unsigned int V_19 ;
struct V_63 * V_64 , * V_127 ;
if ( ! V_126 )
return F_40 ( V_1 ) ;
V_127 = & V_1 -> V_52 [ 0 ] ;
F_77 (rrpc, rlun, i) {
if ( V_64 -> V_40 -> V_117 >
V_127 -> V_40 -> V_117 )
V_127 = V_64 ;
}
return V_127 ;
}
static struct V_2 * F_78 ( struct V_1 * V_1 , T_1 V_23 ,
struct V_4 * V_5 , T_2 V_62 )
{
struct V_2 * V_20 ;
struct V_86 * V_87 ;
F_29 ( V_23 >= V_1 -> V_128 ) ;
V_20 = & V_1 -> V_21 [ V_23 ] ;
F_3 ( & V_1 -> V_7 ) ;
if ( V_20 -> V_5 )
F_1 ( V_1 , V_20 ) ;
V_20 -> V_8 = V_62 ;
V_20 -> V_5 = V_5 ;
V_87 = & V_1 -> V_15 [ V_20 -> V_8 - V_1 -> V_16 ] ;
V_87 -> V_8 = V_23 ;
F_7 ( & V_1 -> V_7 ) ;
return V_20 ;
}
static T_2 F_79 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
T_2 V_8 = V_9 ;
F_3 ( & V_5 -> V_10 ) ;
if ( F_22 ( V_1 , V_5 ) )
goto V_129;
V_8 = F_24 ( V_1 , V_5 ) + V_5 -> V_37 ;
V_5 -> V_37 ++ ;
V_129:
F_7 ( & V_5 -> V_10 ) ;
return V_8 ;
}
static struct V_2 * F_80 ( struct V_1 * V_1 , T_1 V_23 ,
int V_126 )
{
struct V_63 * V_64 ;
struct V_4 * V_5 ;
struct V_67 * V_60 ;
T_2 V_62 ;
V_64 = F_76 ( V_1 , V_126 ) ;
V_60 = V_64 -> V_40 ;
if ( ! V_126 && V_60 -> V_117 < V_1 -> V_44 * 4 )
return NULL ;
F_3 ( & V_64 -> V_10 ) ;
V_5 = V_64 -> V_65 ;
V_130:
V_62 = F_79 ( V_1 , V_5 ) ;
if ( V_62 == V_9 ) {
V_5 = F_30 ( V_1 , V_64 , 0 ) ;
if ( V_5 ) {
F_28 ( V_64 , V_5 ) ;
goto V_130;
}
if ( V_126 ) {
V_62 = F_79 ( V_1 , V_64 -> V_72 ) ;
if ( V_62 == V_9 ) {
V_5 = F_30 ( V_1 , V_64 , 1 ) ;
if ( ! V_5 ) {
F_20 ( L_11 ) ;
goto V_131;
}
V_64 -> V_72 = V_5 ;
V_62 = F_79 ( V_1 , V_64 -> V_72 ) ;
}
V_5 = V_64 -> V_72 ;
}
}
F_7 ( & V_64 -> V_10 ) ;
return F_78 ( V_1 , V_23 , V_5 , V_62 ) ;
V_131:
F_7 ( & V_64 -> V_10 ) ;
return NULL ;
}
static void F_81 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
struct F_62 * V_105 ;
V_105 = F_10 ( V_1 -> V_106 , V_29 ) ;
if ( ! V_105 ) {
F_20 ( L_12 ) ;
return;
}
V_105 -> V_1 = V_1 ;
V_105 -> V_5 = V_5 ;
F_73 ( & V_105 -> V_76 , F_74 ) ;
F_43 ( V_1 -> V_119 , & V_105 -> V_76 ) ;
}
static void F_82 ( struct V_1 * V_1 , struct V_132 * V_133 ,
T_1 V_23 , T_3 V_134 )
{
struct V_2 * V_135 ;
struct V_4 * V_5 ;
struct V_67 * V_60 ;
int V_136 , V_19 ;
for ( V_19 = 0 ; V_19 < V_134 ; V_19 ++ ) {
V_135 = & V_1 -> V_21 [ V_23 + V_19 ] ;
V_5 = V_135 -> V_5 ;
V_60 = V_5 -> V_40 -> V_60 ;
V_136 = F_41 ( & V_5 -> V_71 ) ;
if ( F_83 ( V_136 == V_1 -> V_11 -> V_12 ) )
F_81 ( V_1 , V_5 ) ;
}
}
static void F_84 ( struct V_22 * V_25 )
{
struct V_1 * V_1 = F_63 ( V_25 -> V_137 , struct V_1 , V_138 ) ;
struct V_132 * V_133 = F_85 ( V_25 ) ;
T_3 V_134 = V_25 -> V_139 ;
T_1 V_23 = F_86 ( V_25 -> V_31 ) - V_134 ;
if ( F_87 ( V_25 -> V_31 ) == V_101 )
F_82 ( V_1 , V_133 , V_23 , V_134 ) ;
F_53 ( V_25 -> V_31 ) ;
if ( V_133 -> V_66 & V_99 )
return;
F_88 ( V_1 , V_25 ) ;
if ( V_134 > 1 )
F_89 ( V_1 -> V_11 , V_25 -> V_140 , V_25 -> V_141 ) ;
F_14 ( V_25 , V_1 -> V_28 ) ;
}
static int F_90 ( struct V_1 * V_1 , struct V_31 * V_31 ,
struct V_22 * V_25 , unsigned long V_66 , int V_134 )
{
struct V_26 * V_47 = F_12 ( V_25 ) ;
struct V_2 * V_20 ;
T_1 V_23 = F_86 ( V_31 ) ;
int V_126 = V_66 & V_99 ;
int V_19 ;
if ( ! V_126 && F_91 ( V_1 , V_31 , V_25 ) ) {
F_89 ( V_1 -> V_11 , V_25 -> V_140 , V_25 -> V_141 ) ;
return V_142 ;
}
for ( V_19 = 0 ; V_19 < V_134 ; V_19 ++ ) {
F_29 ( ! ( V_23 + V_19 >= 0 && V_23 + V_19 < V_1 -> V_128 ) ) ;
V_20 = & V_1 -> V_21 [ V_23 + V_19 ] ;
if ( V_20 -> V_5 ) {
V_25 -> V_140 [ V_19 ] = F_27 ( V_1 -> V_11 ,
V_20 -> V_8 ) ;
} else {
F_29 ( V_126 ) ;
F_16 ( V_1 , V_47 ) ;
F_89 ( V_1 -> V_11 , V_25 -> V_140 ,
V_25 -> V_141 ) ;
return V_143 ;
}
}
V_25 -> V_144 = V_145 ;
return V_146 ;
}
static int F_92 ( struct V_1 * V_1 , struct V_31 * V_31 , struct V_22 * V_25 ,
unsigned long V_66 )
{
struct V_132 * V_133 = F_85 ( V_25 ) ;
int V_126 = V_66 & V_99 ;
T_1 V_23 = F_86 ( V_31 ) ;
struct V_2 * V_20 ;
if ( ! V_126 && F_91 ( V_1 , V_31 , V_25 ) )
return V_142 ;
F_29 ( ! ( V_23 >= 0 && V_23 < V_1 -> V_128 ) ) ;
V_20 = & V_1 -> V_21 [ V_23 ] ;
if ( V_20 -> V_5 ) {
V_25 -> V_45 = F_27 ( V_1 -> V_11 , V_20 -> V_8 ) ;
} else {
F_29 ( V_126 ) ;
F_88 ( V_1 , V_25 ) ;
return V_143 ;
}
V_25 -> V_144 = V_145 ;
V_133 -> V_8 = V_20 ;
return V_146 ;
}
static int F_93 ( struct V_1 * V_1 , struct V_31 * V_31 ,
struct V_22 * V_25 , unsigned long V_66 , int V_134 )
{
struct V_26 * V_47 = F_12 ( V_25 ) ;
struct V_2 * V_135 ;
T_1 V_23 = F_86 ( V_31 ) ;
int V_126 = V_66 & V_99 ;
int V_19 ;
if ( ! V_126 && F_91 ( V_1 , V_31 , V_25 ) ) {
F_89 ( V_1 -> V_11 , V_25 -> V_140 , V_25 -> V_141 ) ;
return V_142 ;
}
for ( V_19 = 0 ; V_19 < V_134 ; V_19 ++ ) {
V_135 = F_80 ( V_1 , V_23 + V_19 , V_126 ) ;
if ( ! V_135 ) {
F_29 ( V_126 ) ;
F_16 ( V_1 , V_47 ) ;
F_89 ( V_1 -> V_11 , V_25 -> V_140 ,
V_25 -> V_141 ) ;
F_42 ( V_1 ) ;
return V_142 ;
}
V_25 -> V_140 [ V_19 ] = F_27 ( V_1 -> V_11 ,
V_135 -> V_8 ) ;
}
V_25 -> V_144 = V_147 ;
return V_146 ;
}
static int F_94 ( struct V_1 * V_1 , struct V_31 * V_31 ,
struct V_22 * V_25 , unsigned long V_66 )
{
struct V_132 * V_133 = F_85 ( V_25 ) ;
struct V_2 * V_135 ;
int V_126 = V_66 & V_99 ;
T_1 V_23 = F_86 ( V_31 ) ;
if ( ! V_126 && F_91 ( V_1 , V_31 , V_25 ) )
return V_142 ;
V_135 = F_80 ( V_1 , V_23 , V_126 ) ;
if ( ! V_135 ) {
F_29 ( V_126 ) ;
F_88 ( V_1 , V_25 ) ;
F_42 ( V_1 ) ;
return V_142 ;
}
V_25 -> V_45 = F_27 ( V_1 -> V_11 , V_135 -> V_8 ) ;
V_25 -> V_144 = V_147 ;
V_133 -> V_8 = V_135 ;
return V_146 ;
}
static int F_95 ( struct V_1 * V_1 , struct V_31 * V_31 ,
struct V_22 * V_25 , unsigned long V_66 , T_3 V_134 )
{
if ( V_134 > 1 ) {
V_25 -> V_140 = F_96 ( V_1 -> V_11 , V_148 ,
& V_25 -> V_141 ) ;
if ( ! V_25 -> V_140 ) {
F_20 ( L_13 ) ;
return V_149 ;
}
if ( F_97 ( V_31 ) == V_101 )
return F_93 ( V_1 , V_31 , V_25 , V_66 ,
V_134 ) ;
return F_90 ( V_1 , V_31 , V_25 , V_66 , V_134 ) ;
}
if ( F_97 ( V_31 ) == V_101 )
return F_94 ( V_1 , V_31 , V_25 , V_66 ) ;
return F_92 ( V_1 , V_31 , V_25 , V_66 ) ;
}
static int F_58 ( struct V_1 * V_1 , struct V_31 * V_31 ,
struct V_22 * V_25 , unsigned long V_66 )
{
int V_131 ;
struct V_132 * V_150 = F_85 ( V_25 ) ;
T_3 V_151 = F_98 ( V_31 ) ;
int V_152 = F_99 ( V_31 ) << 9 ;
if ( V_152 < V_1 -> V_11 -> V_153 )
return V_149 ;
else if ( V_152 > V_1 -> V_11 -> V_154 )
return V_149 ;
V_131 = F_95 ( V_1 , V_31 , V_25 , V_66 , V_151 ) ;
if ( V_131 )
return V_131 ;
F_100 ( V_31 ) ;
V_25 -> V_31 = V_31 ;
V_25 -> V_137 = & V_1 -> V_138 ;
V_25 -> V_139 = V_151 ;
V_150 -> V_66 = V_66 ;
V_131 = F_101 ( V_1 -> V_11 , V_25 ) ;
if ( V_131 ) {
F_20 ( L_14 , V_131 ) ;
F_53 ( V_31 ) ;
if ( ! ( V_66 & V_99 ) ) {
F_88 ( V_1 , V_25 ) ;
if ( V_25 -> V_139 > 1 )
F_89 ( V_1 -> V_11 ,
V_25 -> V_140 , V_25 -> V_141 ) ;
}
return V_149 ;
}
return V_146 ;
}
static T_4 F_102 ( struct V_84 * V_85 , struct V_31 * V_31 )
{
struct V_1 * V_1 = V_85 -> V_155 ;
struct V_22 * V_25 ;
int V_131 ;
if ( V_31 -> V_96 & V_156 ) {
F_17 ( V_1 , V_31 ) ;
return V_157 ;
}
V_25 = F_10 ( V_1 -> V_28 , V_148 ) ;
if ( ! V_25 ) {
F_103 ( L_15 ) ;
F_21 ( V_31 ) ;
return V_157 ;
}
memset ( V_25 , 0 , sizeof( struct V_22 ) ) ;
V_131 = F_58 ( V_1 , V_31 , V_25 , V_158 ) ;
switch ( V_131 ) {
case V_146 :
return V_157 ;
case V_149 :
F_21 ( V_31 ) ;
break;
case V_143 :
F_104 ( V_31 ) ;
break;
case V_142 :
F_3 ( & V_1 -> V_159 ) ;
F_105 ( & V_1 -> V_160 , V_31 ) ;
F_7 ( & V_1 -> V_159 ) ;
F_43 ( V_1 -> V_119 , & V_1 -> V_161 ) ;
break;
}
F_14 ( V_25 , V_1 -> V_28 ) ;
return V_157 ;
}
static void F_106 ( struct V_103 * V_104 )
{
struct V_1 * V_1 = F_63 ( V_104 , struct V_1 , V_161 ) ;
struct V_162 V_163 ;
struct V_31 * V_31 ;
F_107 ( & V_163 ) ;
F_3 ( & V_1 -> V_159 ) ;
F_108 ( & V_163 , & V_1 -> V_160 ) ;
F_107 ( & V_1 -> V_160 ) ;
F_7 ( & V_1 -> V_159 ) ;
while ( ( V_31 = F_109 ( & V_163 ) ) )
F_102 ( V_1 -> V_164 -> V_165 , V_31 ) ;
}
static void F_110 ( struct V_1 * V_1 )
{
if ( V_1 -> V_75 )
F_111 ( V_1 -> V_75 ) ;
if ( V_1 -> V_119 )
F_111 ( V_1 -> V_119 ) ;
}
static int F_112 ( struct V_1 * V_1 )
{
V_1 -> V_75 = F_113 ( L_16 , V_166 | V_167 ,
V_1 -> V_44 ) ;
if ( ! V_1 -> V_75 )
return - V_30 ;
V_1 -> V_119 = F_113 ( L_17 , V_166 , 1 ) ;
if ( ! V_1 -> V_119 )
return - V_30 ;
F_114 ( & V_1 -> V_78 , F_44 , ( unsigned long ) V_1 ) ;
return 0 ;
}
static void F_115 ( struct V_1 * V_1 )
{
F_116 ( V_1 -> V_15 ) ;
F_116 ( V_1 -> V_21 ) ;
}
static int F_117 ( T_2 V_17 , T_5 V_168 , T_6 * V_169 , void * V_170 )
{
struct V_1 * V_1 = (struct V_1 * ) V_170 ;
struct V_46 * V_11 = V_1 -> V_11 ;
struct V_2 * V_8 = V_1 -> V_21 + V_17 ;
struct V_86 * V_171 = V_1 -> V_15 ;
T_2 V_172 = V_17 + V_168 ;
T_2 V_19 ;
if ( F_83 ( V_172 > V_11 -> V_173 ) ) {
F_20 ( L_18 ) ;
return - V_174 ;
}
for ( V_19 = 0 ; V_19 < V_168 ; V_19 ++ ) {
T_2 V_175 = F_118 ( V_169 [ V_19 ] ) ;
unsigned int V_176 ;
if ( F_83 ( V_175 >= V_11 -> V_173 && V_175 != V_177 ) ) {
F_20 ( L_19 ) ;
return - V_174 ;
}
if ( ! V_175 )
continue;
F_4 ( V_175 , V_1 -> V_128 , & V_176 ) ;
V_8 [ V_19 ] . V_8 = V_175 ;
V_171 [ V_176 ] . V_8 = V_17 + V_19 ;
}
return 0 ;
}
static int F_119 ( struct V_1 * V_1 )
{
struct V_46 * V_11 = V_1 -> V_11 ;
T_1 V_19 ;
int V_178 ;
V_1 -> V_21 = F_120 ( sizeof( struct V_2 ) * V_1 -> V_128 ) ;
if ( ! V_1 -> V_21 )
return - V_30 ;
V_1 -> V_15 = F_121 ( sizeof( struct V_86 )
* V_1 -> V_128 ) ;
if ( ! V_1 -> V_15 )
return - V_30 ;
for ( V_19 = 0 ; V_19 < V_1 -> V_128 ; V_19 ++ ) {
struct V_2 * V_135 = & V_1 -> V_21 [ V_19 ] ;
struct V_86 * V_47 = & V_1 -> V_15 [ V_19 ] ;
V_135 -> V_8 = V_9 ;
V_47 -> V_8 = V_9 ;
}
if ( ! V_11 -> V_179 -> V_180 )
return 0 ;
V_178 = V_11 -> V_179 -> V_180 ( V_11 , V_1 -> V_181 , V_1 -> V_128 ,
F_117 , V_1 ) ;
if ( V_178 ) {
F_20 ( L_20 ) ;
return - V_174 ;
}
return 0 ;
}
static int F_122 ( struct V_1 * V_1 )
{
F_123 ( & V_182 ) ;
if ( ! V_183 ) {
V_183 = F_124 ( L_21 ,
sizeof( struct F_62 ) , 0 , 0 , NULL ) ;
if ( ! V_183 ) {
F_125 ( & V_182 ) ;
return - V_30 ;
}
V_184 = F_124 ( L_22 ,
sizeof( struct V_22 ) + sizeof( struct V_132 ) ,
0 , 0 , NULL ) ;
if ( ! V_184 ) {
F_126 ( V_183 ) ;
F_125 ( & V_182 ) ;
return - V_30 ;
}
}
F_125 ( & V_182 ) ;
V_1 -> V_94 = F_127 ( V_185 , 0 ) ;
if ( ! V_1 -> V_94 )
return - V_30 ;
V_1 -> V_106 = F_128 ( V_1 -> V_11 -> V_44 ,
V_183 ) ;
if ( ! V_1 -> V_106 )
return - V_30 ;
V_1 -> V_28 = F_128 ( 64 , V_184 ) ;
if ( ! V_1 -> V_28 )
return - V_30 ;
F_129 ( & V_1 -> V_186 . V_10 ) ;
F_130 ( & V_1 -> V_186 . V_187 ) ;
return 0 ;
}
static void F_131 ( struct V_1 * V_1 )
{
F_132 ( V_1 -> V_94 ) ;
F_132 ( V_1 -> V_106 ) ;
F_132 ( V_1 -> V_28 ) ;
}
static void F_133 ( struct V_1 * V_1 )
{
struct V_46 * V_11 = V_1 -> V_11 ;
struct V_67 * V_60 ;
struct V_63 * V_64 ;
int V_19 ;
if ( ! V_1 -> V_52 )
return;
for ( V_19 = 0 ; V_19 < V_1 -> V_44 ; V_19 ++ ) {
V_64 = & V_1 -> V_52 [ V_19 ] ;
V_60 = V_64 -> V_40 ;
if ( ! V_60 )
break;
V_11 -> V_188 -> V_189 ( V_11 , V_60 -> V_42 ) ;
F_116 ( V_64 -> V_190 ) ;
}
F_134 ( V_1 -> V_52 ) ;
}
static int F_135 ( struct V_1 * V_1 , int V_191 , int V_192 )
{
struct V_46 * V_11 = V_1 -> V_11 ;
struct V_63 * V_64 ;
int V_19 , V_193 , V_178 = - V_174 ;
if ( V_11 -> V_12 > V_194 * V_195 ) {
F_20 ( L_23 ) ;
return - V_174 ;
}
F_129 ( & V_1 -> V_7 ) ;
V_1 -> V_52 = F_136 ( V_1 -> V_44 , sizeof( struct V_63 ) ,
V_148 ) ;
if ( ! V_1 -> V_52 )
return - V_30 ;
for ( V_19 = 0 ; V_19 < V_1 -> V_44 ; V_19 ++ ) {
int V_196 = V_191 + V_19 ;
struct V_67 * V_60 ;
if ( V_11 -> V_188 -> V_197 ( V_11 , V_196 ) ) {
F_20 ( L_24 , V_196 ) ;
goto V_131;
}
V_60 = V_11 -> V_188 -> V_198 ( V_11 , V_196 ) ;
if ( ! V_60 )
goto V_131;
V_64 = & V_1 -> V_52 [ V_19 ] ;
V_64 -> V_40 = V_60 ;
V_64 -> V_190 = F_120 ( sizeof( struct V_4 ) *
V_1 -> V_11 -> V_43 ) ;
if ( ! V_64 -> V_190 ) {
V_178 = - V_30 ;
goto V_131;
}
for ( V_193 = 0 ; V_193 < V_1 -> V_11 -> V_43 ; V_193 ++ ) {
struct V_4 * V_5 = & V_64 -> V_190 [ V_193 ] ;
struct V_38 * V_39 = & V_60 -> V_190 [ V_193 ] ;
V_5 -> V_40 = V_39 ;
V_5 -> V_64 = V_64 ;
F_130 ( & V_5 -> V_108 ) ;
F_129 ( & V_5 -> V_10 ) ;
}
V_64 -> V_1 = V_1 ;
F_130 ( & V_64 -> V_109 ) ;
F_130 ( & V_64 -> V_69 ) ;
F_130 ( & V_64 -> V_125 ) ;
F_73 ( & V_64 -> V_76 , F_71 ) ;
F_129 ( & V_64 -> V_10 ) ;
}
return 0 ;
V_131:
return V_178 ;
}
static int F_137 ( struct V_1 * V_1 , T_1 * V_199 )
{
struct V_46 * V_11 = V_1 -> V_11 ;
struct V_200 * V_188 = V_11 -> V_188 ;
T_1 V_201 = V_1 -> V_128 * V_11 -> V_153 ;
int V_178 ;
V_201 >>= 9 ;
V_178 = V_188 -> V_202 ( V_11 , V_199 , V_201 ) ;
if ( ! V_178 )
* V_199 >>= ( F_138 ( V_11 -> V_153 ) - 9 ) ;
return V_178 ;
}
static void F_139 ( struct V_1 * V_1 )
{
struct V_46 * V_11 = V_1 -> V_11 ;
struct V_200 * V_188 = V_11 -> V_188 ;
T_1 V_199 = V_1 -> V_181 << ( F_138 ( V_11 -> V_153 ) - 9 ) ;
V_188 -> V_203 ( V_11 , V_199 ) ;
}
static void F_140 ( struct V_1 * V_1 )
{
F_110 ( V_1 ) ;
F_115 ( V_1 ) ;
F_131 ( V_1 ) ;
F_133 ( V_1 ) ;
F_139 ( V_1 ) ;
F_134 ( V_1 ) ;
}
static void F_141 ( void * V_170 )
{
struct V_1 * V_1 = V_170 ;
F_142 ( & V_1 -> V_78 ) ;
F_143 ( V_1 -> V_75 ) ;
F_143 ( V_1 -> V_119 ) ;
F_140 ( V_1 ) ;
}
static T_1 F_144 ( void * V_170 )
{
struct V_1 * V_1 = V_170 ;
struct V_46 * V_11 = V_1 -> V_11 ;
T_1 V_204 , V_205 ;
V_204 = V_1 -> V_44 * V_11 -> V_12 * 4 ;
V_205 = V_1 -> V_128 - V_204 ;
if ( V_204 > V_1 -> V_128 ) {
F_20 ( L_25 ) ;
return 0 ;
}
F_26 ( V_205 , 10 ) ;
return V_205 * 9 * V_34 ;
}
static void F_145 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
struct V_46 * V_11 = V_1 -> V_11 ;
int V_206 ;
struct V_2 * V_23 ;
T_2 V_207 , V_62 , V_208 ;
V_207 = F_23 ( V_1 , V_5 ) ;
for ( V_206 = 0 ; V_206 < V_11 -> V_12 ; V_206 ++ ) {
V_62 = V_207 + V_206 ;
V_208 = V_1 -> V_15 [ V_62 ] . V_8 ;
if ( V_208 == V_9 )
continue;
V_23 = & V_1 -> V_21 [ V_208 ] ;
if ( V_62 == V_23 -> V_8 ) {
V_23 -> V_5 = V_5 ;
} else {
F_146 ( V_206 , V_5 -> V_13 ) ;
V_5 -> V_14 ++ ;
}
}
}
static int F_147 ( struct V_1 * V_1 )
{
struct V_63 * V_64 ;
struct V_4 * V_5 ;
int V_209 , V_210 ;
for ( V_209 = 0 ; V_209 < V_1 -> V_44 ; V_209 ++ ) {
V_64 = & V_1 -> V_52 [ V_209 ] ;
for ( V_210 = 0 ; V_210 < V_1 -> V_11 -> V_43 ;
V_210 ++ ) {
V_5 = & V_64 -> V_190 [ V_210 ] ;
F_145 ( V_1 , V_5 ) ;
}
}
return 0 ;
}
static int F_148 ( struct V_1 * V_1 )
{
struct V_63 * V_64 ;
struct V_4 * V_5 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_1 -> V_44 ; V_19 ++ ) {
V_64 = & V_1 -> V_52 [ V_19 ] ;
V_5 = F_30 ( V_1 , V_64 , 0 ) ;
if ( ! V_5 )
goto V_131;
F_28 ( V_64 , V_5 ) ;
V_5 = F_30 ( V_1 , V_64 , 1 ) ;
if ( ! V_5 )
goto V_131;
V_64 -> V_72 = V_5 ;
}
return 0 ;
V_131:
F_39 ( V_1 ) ;
return - V_174 ;
}
static void * F_149 ( struct V_46 * V_11 , struct V_211 * V_212 ,
int V_191 , int V_192 )
{
struct V_84 * V_213 = V_11 -> V_85 ;
struct V_84 * V_214 = V_212 -> V_165 ;
struct V_1 * V_1 ;
T_1 V_181 ;
int V_178 ;
if ( ! ( V_11 -> V_215 . V_216 & V_217 ) ) {
F_20 ( L_26 ,
V_11 -> V_215 . V_216 ) ;
return F_11 ( - V_174 ) ;
}
V_1 = F_150 ( sizeof( struct V_1 ) , V_148 ) ;
if ( ! V_1 )
return F_11 ( - V_30 ) ;
V_1 -> V_138 . V_218 = & V_219 ;
V_1 -> V_11 = V_11 ;
V_1 -> V_164 = V_212 ;
F_107 ( & V_1 -> V_160 ) ;
F_129 ( & V_1 -> V_159 ) ;
F_73 ( & V_1 -> V_161 , F_106 ) ;
V_1 -> V_44 = V_192 - V_191 + 1 ;
V_1 -> V_220 = ( unsigned long ) V_11 -> V_43 * V_1 -> V_44 ;
V_1 -> V_128 = ( unsigned long long ) V_11 -> V_221 * V_1 -> V_44 ;
F_35 ( & V_1 -> V_74 , - 1 ) ;
V_178 = F_137 ( V_1 , & V_181 ) ;
if ( V_178 < 0 ) {
F_20 ( L_27 ) ;
return F_11 ( V_178 ) ;
}
V_1 -> V_181 = V_181 ;
V_178 = F_135 ( V_1 , V_191 , V_192 ) ;
if ( V_178 ) {
F_20 ( L_28 ) ;
goto V_131;
}
V_1 -> V_16 = V_11 -> V_221 * V_191 ;
V_1 -> V_222 = V_191 ;
V_178 = F_122 ( V_1 ) ;
if ( V_178 ) {
F_20 ( L_29 ) ;
goto V_131;
}
V_178 = F_119 ( V_1 ) ;
if ( V_178 ) {
F_20 ( L_30 ) ;
goto V_131;
}
V_178 = F_147 ( V_1 ) ;
if ( V_178 ) {
F_20 ( L_31 ) ;
goto V_131;
}
V_178 = F_148 ( V_1 ) ;
if ( V_178 ) {
F_20 ( L_32 ) ;
goto V_131;
}
V_178 = F_112 ( V_1 ) ;
if ( V_178 ) {
F_20 ( L_33 ) ;
goto V_131;
}
F_151 ( V_214 , F_152 ( V_213 ) ) ;
F_153 ( V_214 , F_154 ( V_213 ) ) ;
F_155 ( L_34 ,
V_1 -> V_44 , ( unsigned long long ) V_1 -> V_128 ) ;
F_45 ( & V_1 -> V_78 , V_79 + F_46 ( 10 ) ) ;
return V_1 ;
V_131:
F_140 ( V_1 ) ;
return F_11 ( V_178 ) ;
}
static int T_7 F_156 ( void )
{
return F_157 ( & V_219 ) ;
}
static void F_158 ( void )
{
F_159 ( & V_219 ) ;
}
