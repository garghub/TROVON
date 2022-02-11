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
struct V_38 * V_39 ;
struct V_4 * V_5 ;
V_39 = F_30 ( V_1 -> V_11 , V_62 -> V_40 , V_64 ) ;
if ( ! V_39 )
return NULL ;
V_5 = & V_62 -> V_65 [ V_39 -> V_41 ] ;
V_39 -> V_66 = V_5 ;
F_31 ( V_5 -> V_13 , V_1 -> V_11 -> V_12 ) ;
V_5 -> V_37 = 0 ;
V_5 -> V_14 = 0 ;
F_32 ( & V_5 -> V_67 , 0 ) ;
return V_5 ;
}
static void F_33 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
F_34 ( V_1 -> V_11 , V_5 -> V_40 ) ;
}
static void F_35 ( struct V_1 * V_1 )
{
struct V_61 * V_62 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_1 -> V_68 ; V_19 ++ ) {
V_62 = & V_1 -> V_49 [ V_19 ] ;
if ( V_62 -> V_63 )
F_33 ( V_1 , V_62 -> V_63 ) ;
if ( V_62 -> V_69 )
F_33 ( V_1 , V_62 -> V_69 ) ;
}
}
static struct V_61 * F_36 ( struct V_1 * V_1 )
{
int V_70 = F_37 ( & V_1 -> V_71 ) ;
return & V_1 -> V_49 [ V_70 % V_1 -> V_68 ] ;
}
static void F_38 ( struct V_1 * V_1 )
{
struct V_61 * V_62 ;
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_1 -> V_68 ; V_19 ++ ) {
V_62 = & V_1 -> V_49 [ V_19 ] ;
F_39 ( V_1 -> V_72 , & V_62 -> V_73 ) ;
}
}
static void F_40 ( unsigned long V_74 )
{
struct V_1 * V_1 = (struct V_1 * ) V_74 ;
F_38 ( V_1 ) ;
F_41 ( & V_1 -> V_75 , V_76 + F_42 ( 10 ) ) ;
}
static void F_43 ( struct V_31 * V_31 )
{
struct V_77 * V_78 = V_31 -> V_79 ;
if ( V_31 -> V_80 )
F_20 ( L_2 , V_31 -> V_80 ) ;
F_44 ( V_78 ) ;
}
static int F_45 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
struct V_81 * V_82 = V_1 -> V_11 -> V_82 ;
struct V_83 * V_84 ;
struct V_22 * V_25 ;
struct V_31 * V_31 ;
struct V_85 * V_85 ;
int V_86 ;
int V_87 = V_1 -> V_11 -> V_12 ;
T_2 V_88 ;
F_46 ( V_89 ) ;
if ( F_47 ( V_5 -> V_13 , V_87 ) )
return 0 ;
V_31 = F_48 ( V_90 , 1 ) ;
if ( ! V_31 ) {
F_20 ( L_3 ) ;
return - V_30 ;
}
V_85 = F_10 ( V_1 -> V_91 , V_90 ) ;
while ( ( V_86 = F_49 ( V_5 -> V_13 ,
V_87 ) ) < V_87 ) {
V_88 = ( V_5 -> V_40 -> V_41 * V_87 ) + V_86 ;
V_92:
F_3 ( & V_1 -> V_7 ) ;
V_84 = & V_1 -> V_15 [ V_88 - V_1 -> V_16 ] ;
if ( V_84 -> V_8 == V_9 ) {
F_7 ( & V_1 -> V_7 ) ;
continue;
}
V_25 = F_9 ( V_1 , V_84 -> V_8 , 1 ) ;
if ( F_50 ( V_25 ) ) {
F_7 ( & V_1 -> V_7 ) ;
F_18 () ;
goto V_92;
}
F_7 ( & V_1 -> V_7 ) ;
V_31 -> V_32 . V_33 = F_51 ( V_84 -> V_8 ) ;
V_31 -> V_93 = V_94 ;
V_31 -> V_79 = & V_89 ;
V_31 -> V_95 = F_43 ;
F_52 ( V_82 , V_31 , V_85 , V_36 , 0 ) ;
if ( F_53 ( V_1 , V_31 , V_25 , V_96 ) ) {
F_20 ( L_4 ) ;
F_15 ( V_1 , V_25 ) ;
goto V_97;
}
F_54 ( & V_89 ) ;
F_55 ( V_31 ) ;
F_56 ( & V_89 ) ;
V_31 -> V_32 . V_33 = F_51 ( V_84 -> V_8 ) ;
V_31 -> V_93 = V_98 ;
V_31 -> V_79 = & V_89 ;
V_31 -> V_95 = F_43 ;
F_52 ( V_82 , V_31 , V_85 , V_36 , 0 ) ;
if ( F_53 ( V_1 , V_31 , V_25 , V_96 ) ) {
F_20 ( L_5 ) ;
F_15 ( V_1 , V_25 ) ;
goto V_97;
}
F_54 ( & V_89 ) ;
F_15 ( V_1 , V_25 ) ;
F_55 ( V_31 ) ;
}
V_97:
F_14 ( V_85 , V_1 -> V_91 ) ;
F_57 ( V_31 ) ;
if ( ! F_47 ( V_5 -> V_13 , V_87 ) ) {
F_20 ( L_6 ) ;
return - V_99 ;
}
return 0 ;
}
static void F_58 ( struct V_100 * V_101 )
{
struct F_58 * V_102 = F_59 ( V_101 , struct F_58 ,
V_73 ) ;
struct V_1 * V_1 = V_102 -> V_1 ;
struct V_4 * V_5 = V_102 -> V_5 ;
struct V_43 * V_11 = V_1 -> V_11 ;
F_60 ( L_7 , V_5 -> V_40 -> V_41 ) ;
if ( F_45 ( V_1 , V_5 ) )
goto V_103;
F_61 ( V_11 , V_5 -> V_40 ) ;
F_33 ( V_1 , V_5 ) ;
V_103:
F_14 ( V_102 , V_1 -> V_104 ) ;
}
static struct V_4 * F_62 ( struct V_4 * V_105 ,
struct V_4 * V_106 )
{
if ( V_105 -> V_14 == V_106 -> V_14 )
return V_105 ;
return ( V_105 -> V_14 < V_106 -> V_14 ) ? V_106 : V_105 ;
}
static struct V_4 * F_63 ( struct V_61 * V_62 )
{
struct V_107 * V_108 = & V_62 -> V_108 ;
struct V_4 * V_109 , * V_110 ;
F_28 ( F_64 ( V_108 ) ) ;
V_110 = F_65 ( V_108 , struct V_4 , V_111 ) ;
F_66 (rblock, prio_list, prio)
V_110 = F_62 ( V_110 , V_109 ) ;
return V_110 ;
}
static void F_67 ( struct V_100 * V_101 )
{
struct V_61 * V_62 = F_59 ( V_101 , struct V_61 , V_73 ) ;
struct V_1 * V_1 = V_62 -> V_1 ;
struct V_112 * V_58 = V_62 -> V_40 ;
struct F_58 * V_102 ;
unsigned int V_113 ;
V_113 = V_1 -> V_11 -> V_56 / V_114 ;
if ( V_113 < V_1 -> V_68 )
V_113 = V_1 -> V_68 ;
F_3 ( & V_58 -> V_10 ) ;
while ( V_113 > V_58 -> V_115 &&
! F_64 ( & V_62 -> V_108 ) ) {
struct V_4 * V_109 = F_63 ( V_62 ) ;
struct V_38 * V_116 = V_109 -> V_40 ;
if ( ! V_109 -> V_14 )
break;
F_68 ( & V_109 -> V_111 ) ;
F_28 ( ! F_22 ( V_1 , V_109 ) ) ;
F_60 ( L_8 , V_116 -> V_41 ) ;
V_102 = F_10 ( V_1 -> V_104 , V_29 ) ;
if ( ! V_102 )
break;
V_102 -> V_1 = V_1 ;
V_102 -> V_5 = V_109 ;
F_69 ( & V_102 -> V_73 , F_58 ) ;
F_39 ( V_1 -> V_117 , & V_102 -> V_73 ) ;
V_113 -- ;
}
F_7 ( & V_58 -> V_10 ) ;
}
static void F_70 ( struct V_100 * V_101 )
{
struct F_58 * V_102 = F_59 ( V_101 , struct F_58 ,
V_73 ) ;
struct V_1 * V_1 = V_102 -> V_1 ;
struct V_4 * V_5 = V_102 -> V_5 ;
struct V_112 * V_58 = V_5 -> V_40 -> V_58 ;
struct V_61 * V_62 = & V_1 -> V_49 [ V_58 -> V_41 - V_1 -> V_118 ] ;
F_3 ( & V_62 -> V_10 ) ;
F_71 ( & V_5 -> V_111 , & V_62 -> V_108 ) ;
F_7 ( & V_62 -> V_10 ) ;
F_14 ( V_102 , V_1 -> V_104 ) ;
F_60 ( L_9 ,
V_5 -> V_40 -> V_41 ) ;
}
static struct V_61 * F_72 ( struct V_1 * V_1 , int V_119 )
{
unsigned int V_19 ;
struct V_61 * V_62 , * V_120 ;
if ( ! V_119 )
return F_36 ( V_1 ) ;
V_120 = & V_1 -> V_49 [ 0 ] ;
F_73 (rrpc, rlun, i) {
if ( V_62 -> V_40 -> V_115 >
V_120 -> V_40 -> V_115 )
V_120 = V_62 ;
}
return V_120 ;
}
static struct V_2 * F_74 ( struct V_1 * V_1 , T_1 V_23 ,
struct V_4 * V_5 , T_2 V_60 )
{
struct V_2 * V_20 ;
struct V_83 * V_84 ;
F_28 ( V_23 >= V_1 -> V_121 ) ;
V_20 = & V_1 -> V_21 [ V_23 ] ;
F_3 ( & V_1 -> V_7 ) ;
if ( V_20 -> V_5 )
F_1 ( V_1 , V_20 ) ;
V_20 -> V_8 = V_60 ;
V_20 -> V_5 = V_5 ;
V_84 = & V_1 -> V_15 [ V_20 -> V_8 - V_1 -> V_16 ] ;
V_84 -> V_8 = V_23 ;
F_7 ( & V_1 -> V_7 ) ;
return V_20 ;
}
static T_2 F_75 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
T_2 V_8 = V_9 ;
F_3 ( & V_5 -> V_10 ) ;
if ( F_22 ( V_1 , V_5 ) )
goto V_122;
V_8 = F_23 ( V_1 , V_5 ) + V_5 -> V_37 ;
V_5 -> V_37 ++ ;
V_122:
F_7 ( & V_5 -> V_10 ) ;
return V_8 ;
}
static struct V_2 * F_76 ( struct V_1 * V_1 , T_1 V_23 ,
int V_119 )
{
struct V_61 * V_62 ;
struct V_4 * V_5 ;
struct V_112 * V_58 ;
T_2 V_60 ;
V_62 = F_72 ( V_1 , V_119 ) ;
V_58 = V_62 -> V_40 ;
if ( ! V_119 && V_58 -> V_115 < V_1 -> V_68 * 4 )
return NULL ;
F_3 ( & V_62 -> V_10 ) ;
V_5 = V_62 -> V_63 ;
V_123:
V_60 = F_75 ( V_1 , V_5 ) ;
if ( V_60 == V_9 ) {
V_5 = F_29 ( V_1 , V_62 , 0 ) ;
if ( V_5 ) {
F_27 ( V_62 , V_5 ) ;
goto V_123;
}
if ( V_119 ) {
V_60 = F_75 ( V_1 , V_62 -> V_69 ) ;
if ( V_60 == V_9 ) {
V_5 = F_29 ( V_1 , V_62 , 1 ) ;
if ( ! V_5 ) {
F_20 ( L_10 ) ;
goto V_124;
}
V_62 -> V_69 = V_5 ;
V_60 = F_75 ( V_1 , V_62 -> V_69 ) ;
}
V_5 = V_62 -> V_69 ;
}
}
F_7 ( & V_62 -> V_10 ) ;
return F_74 ( V_1 , V_23 , V_5 , V_60 ) ;
V_124:
F_7 ( & V_62 -> V_10 ) ;
return NULL ;
}
static void F_77 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
struct F_58 * V_102 ;
V_102 = F_10 ( V_1 -> V_104 , V_29 ) ;
if ( ! V_102 ) {
F_20 ( L_11 ) ;
return;
}
V_102 -> V_1 = V_1 ;
V_102 -> V_5 = V_5 ;
F_69 ( & V_102 -> V_73 , F_70 ) ;
F_39 ( V_1 -> V_117 , & V_102 -> V_73 ) ;
}
static void F_78 ( struct V_1 * V_1 , struct V_125 * V_126 ,
T_1 V_23 , T_3 V_127 )
{
struct V_2 * V_128 ;
struct V_4 * V_5 ;
struct V_112 * V_58 ;
int V_129 , V_19 ;
for ( V_19 = 0 ; V_19 < V_127 ; V_19 ++ ) {
V_128 = & V_1 -> V_21 [ V_23 + V_19 ] ;
V_5 = V_128 -> V_5 ;
V_58 = V_5 -> V_40 -> V_58 ;
V_129 = F_37 ( & V_5 -> V_67 ) ;
if ( F_79 ( V_129 == V_1 -> V_11 -> V_12 ) )
F_77 ( V_1 , V_5 ) ;
}
}
static int F_80 ( struct V_22 * V_25 , int error )
{
struct V_1 * V_1 = F_59 ( V_25 -> V_130 , struct V_1 , V_131 ) ;
struct V_125 * V_126 = F_81 ( V_25 ) ;
T_3 V_127 = V_25 -> V_121 ;
T_1 V_23 = F_82 ( V_25 -> V_31 ) - V_127 ;
if ( F_83 ( V_25 -> V_31 ) == V_98 )
F_78 ( V_1 , V_126 , V_23 , V_127 ) ;
if ( V_126 -> V_64 & V_96 )
return 0 ;
F_84 ( V_1 , V_25 ) ;
F_57 ( V_25 -> V_31 ) ;
if ( V_127 > 1 )
F_85 ( V_1 -> V_11 , V_25 -> V_132 , V_25 -> V_133 ) ;
if ( V_25 -> V_134 )
F_85 ( V_1 -> V_11 , V_25 -> V_134 , V_25 -> V_135 ) ;
F_14 ( V_25 , V_1 -> V_28 ) ;
return 0 ;
}
static int F_86 ( struct V_1 * V_1 , struct V_31 * V_31 ,
struct V_22 * V_25 , unsigned long V_64 , int V_127 )
{
struct V_26 * V_44 = F_12 ( V_25 ) ;
struct V_2 * V_20 ;
T_1 V_23 = F_82 ( V_31 ) ;
int V_119 = V_64 & V_96 ;
int V_19 ;
if ( ! V_119 && F_87 ( V_1 , V_31 , V_25 ) ) {
F_85 ( V_1 -> V_11 , V_25 -> V_132 , V_25 -> V_133 ) ;
return V_136 ;
}
for ( V_19 = 0 ; V_19 < V_127 ; V_19 ++ ) {
F_28 ( ! ( V_23 + V_19 >= 0 && V_23 + V_19 < V_1 -> V_121 ) ) ;
V_20 = & V_1 -> V_21 [ V_23 + V_19 ] ;
if ( V_20 -> V_5 ) {
V_25 -> V_132 [ V_19 ] = F_26 ( V_1 -> V_11 ,
V_20 -> V_8 ) ;
} else {
F_28 ( V_119 ) ;
F_16 ( V_1 , V_44 ) ;
F_85 ( V_1 -> V_11 , V_25 -> V_132 ,
V_25 -> V_133 ) ;
return V_137 ;
}
}
V_25 -> V_138 = V_139 ;
return V_140 ;
}
static int F_88 ( struct V_1 * V_1 , struct V_31 * V_31 , struct V_22 * V_25 ,
unsigned long V_64 )
{
struct V_125 * V_126 = F_81 ( V_25 ) ;
int V_119 = V_64 & V_96 ;
T_1 V_23 = F_82 ( V_31 ) ;
struct V_2 * V_20 ;
if ( ! V_119 && F_87 ( V_1 , V_31 , V_25 ) )
return V_136 ;
F_28 ( ! ( V_23 >= 0 && V_23 < V_1 -> V_121 ) ) ;
V_20 = & V_1 -> V_21 [ V_23 ] ;
if ( V_20 -> V_5 ) {
V_25 -> V_42 = F_26 ( V_1 -> V_11 , V_20 -> V_8 ) ;
} else {
F_28 ( V_119 ) ;
F_84 ( V_1 , V_25 ) ;
return V_137 ;
}
V_25 -> V_138 = V_139 ;
V_126 -> V_8 = V_20 ;
return V_140 ;
}
static int F_89 ( struct V_1 * V_1 , struct V_31 * V_31 ,
struct V_22 * V_25 , unsigned long V_64 , int V_127 )
{
struct V_26 * V_44 = F_12 ( V_25 ) ;
struct V_2 * V_128 ;
T_1 V_23 = F_82 ( V_31 ) ;
int V_119 = V_64 & V_96 ;
int V_19 ;
if ( ! V_119 && F_87 ( V_1 , V_31 , V_25 ) ) {
F_85 ( V_1 -> V_11 , V_25 -> V_132 , V_25 -> V_133 ) ;
return V_136 ;
}
for ( V_19 = 0 ; V_19 < V_127 ; V_19 ++ ) {
V_128 = F_76 ( V_1 , V_23 + V_19 , V_119 ) ;
if ( ! V_128 ) {
F_28 ( V_119 ) ;
F_16 ( V_1 , V_44 ) ;
F_85 ( V_1 -> V_11 , V_25 -> V_132 ,
V_25 -> V_133 ) ;
F_38 ( V_1 ) ;
return V_136 ;
}
V_25 -> V_132 [ V_19 ] = F_26 ( V_1 -> V_11 ,
V_128 -> V_8 ) ;
}
V_25 -> V_138 = V_141 ;
return V_140 ;
}
static int F_90 ( struct V_1 * V_1 , struct V_31 * V_31 ,
struct V_22 * V_25 , unsigned long V_64 )
{
struct V_125 * V_126 = F_81 ( V_25 ) ;
struct V_2 * V_128 ;
int V_119 = V_64 & V_96 ;
T_1 V_23 = F_82 ( V_31 ) ;
if ( ! V_119 && F_87 ( V_1 , V_31 , V_25 ) )
return V_136 ;
V_128 = F_76 ( V_1 , V_23 , V_119 ) ;
if ( ! V_128 ) {
F_28 ( V_119 ) ;
F_84 ( V_1 , V_25 ) ;
F_38 ( V_1 ) ;
return V_136 ;
}
V_25 -> V_42 = F_26 ( V_1 -> V_11 , V_128 -> V_8 ) ;
V_25 -> V_138 = V_141 ;
V_126 -> V_8 = V_128 ;
return V_140 ;
}
static int F_91 ( struct V_1 * V_1 , struct V_31 * V_31 ,
struct V_22 * V_25 , unsigned long V_64 , T_3 V_127 )
{
if ( V_127 > 1 ) {
V_25 -> V_132 = F_92 ( V_1 -> V_11 , V_142 ,
& V_25 -> V_133 ) ;
if ( ! V_25 -> V_132 ) {
F_20 ( L_12 ) ;
return V_143 ;
}
if ( F_93 ( V_31 ) == V_98 )
return F_89 ( V_1 , V_31 , V_25 , V_64 ,
V_127 ) ;
return F_86 ( V_1 , V_31 , V_25 , V_64 , V_127 ) ;
}
if ( F_93 ( V_31 ) == V_98 )
return F_90 ( V_1 , V_31 , V_25 , V_64 ) ;
return F_88 ( V_1 , V_31 , V_25 , V_64 ) ;
}
static int F_53 ( struct V_1 * V_1 , struct V_31 * V_31 ,
struct V_22 * V_25 , unsigned long V_64 )
{
int V_124 ;
struct V_125 * V_144 = F_81 ( V_25 ) ;
T_3 V_121 = F_94 ( V_31 ) ;
int V_145 = F_95 ( V_31 ) << 9 ;
if ( V_145 < V_1 -> V_11 -> V_146 )
return V_143 ;
else if ( V_145 > V_1 -> V_11 -> V_147 )
return V_143 ;
V_124 = F_91 ( V_1 , V_31 , V_25 , V_64 , V_121 ) ;
if ( V_124 )
return V_124 ;
F_96 ( V_31 ) ;
V_25 -> V_31 = V_31 ;
V_25 -> V_130 = & V_1 -> V_131 ;
V_25 -> V_121 = V_121 ;
V_144 -> V_64 = V_64 ;
V_124 = F_97 ( V_1 -> V_11 , V_25 ) ;
if ( V_124 ) {
F_20 ( L_13 , V_124 ) ;
return V_143 ;
}
return V_140 ;
}
static T_4 F_98 ( struct V_81 * V_82 , struct V_31 * V_31 )
{
struct V_1 * V_1 = V_82 -> V_148 ;
struct V_22 * V_25 ;
int V_124 ;
if ( V_31 -> V_93 & V_149 ) {
F_17 ( V_1 , V_31 ) ;
return V_150 ;
}
V_25 = F_10 ( V_1 -> V_28 , V_142 ) ;
if ( ! V_25 ) {
F_99 ( L_14 ) ;
F_21 ( V_31 ) ;
return V_150 ;
}
memset ( V_25 , 0 , sizeof( struct V_22 ) ) ;
V_124 = F_53 ( V_1 , V_31 , V_25 , V_151 ) ;
switch ( V_124 ) {
case V_140 :
return V_150 ;
case V_143 :
F_21 ( V_31 ) ;
break;
case V_137 :
F_100 ( V_31 ) ;
break;
case V_136 :
F_3 ( & V_1 -> V_152 ) ;
F_101 ( & V_1 -> V_153 , V_31 ) ;
F_7 ( & V_1 -> V_152 ) ;
F_39 ( V_1 -> V_117 , & V_1 -> V_154 ) ;
break;
}
F_14 ( V_25 , V_1 -> V_28 ) ;
return V_150 ;
}
static void F_102 ( struct V_100 * V_101 )
{
struct V_1 * V_1 = F_59 ( V_101 , struct V_1 , V_154 ) ;
struct V_155 V_156 ;
struct V_31 * V_31 ;
F_103 ( & V_156 ) ;
F_3 ( & V_1 -> V_152 ) ;
F_104 ( & V_156 , & V_1 -> V_153 ) ;
F_103 ( & V_1 -> V_153 ) ;
F_7 ( & V_1 -> V_152 ) ;
while ( ( V_31 = F_105 ( & V_156 ) ) )
F_98 ( V_1 -> V_157 -> V_158 , V_31 ) ;
}
static void F_106 ( struct V_1 * V_1 )
{
struct V_61 * V_62 ;
int V_19 ;
if ( V_1 -> V_72 )
F_107 ( V_1 -> V_72 ) ;
if ( V_1 -> V_117 )
F_107 ( V_1 -> V_117 ) ;
if ( ! V_1 -> V_49 )
return;
for ( V_19 = 0 ; V_19 < V_1 -> V_68 ; V_19 ++ ) {
V_62 = & V_1 -> V_49 [ V_19 ] ;
if ( ! V_62 -> V_65 )
break;
F_108 ( V_62 -> V_65 ) ;
}
}
static int F_109 ( struct V_1 * V_1 )
{
V_1 -> V_72 = F_110 ( L_15 , V_159 | V_160 ,
V_1 -> V_68 ) ;
if ( ! V_1 -> V_72 )
return - V_30 ;
V_1 -> V_117 = F_110 ( L_16 , V_159 , 1 ) ;
if ( ! V_1 -> V_117 )
return - V_30 ;
F_111 ( & V_1 -> V_75 , F_40 , ( unsigned long ) V_1 ) ;
return 0 ;
}
static void F_112 ( struct V_1 * V_1 )
{
F_108 ( V_1 -> V_15 ) ;
F_108 ( V_1 -> V_21 ) ;
}
static int F_113 ( T_2 V_17 , T_5 V_161 , T_6 * V_162 , void * V_163 )
{
struct V_1 * V_1 = (struct V_1 * ) V_163 ;
struct V_43 * V_11 = V_1 -> V_11 ;
struct V_2 * V_8 = V_1 -> V_21 + V_17 ;
struct V_83 * V_164 = V_1 -> V_15 ;
T_1 V_165 = V_11 -> V_166 * ( V_11 -> V_146 >> 9 ) ;
T_2 V_167 = V_17 + V_161 ;
T_2 V_19 ;
if ( F_79 ( V_167 > V_11 -> V_166 ) ) {
F_20 ( L_17 ) ;
return - V_168 ;
}
for ( V_19 = 0 ; V_19 < V_161 ; V_19 ++ ) {
T_2 V_169 = F_114 ( V_162 [ V_19 ] ) ;
if ( F_79 ( V_169 >= V_165 && V_169 != V_170 ) ) {
F_20 ( L_18 ) ;
return - V_168 ;
}
if ( ! V_169 )
continue;
V_8 [ V_19 ] . V_8 = V_169 ;
V_164 [ V_169 ] . V_8 = V_17 + V_19 ;
}
return 0 ;
}
static int F_115 ( struct V_1 * V_1 )
{
struct V_43 * V_11 = V_1 -> V_11 ;
T_1 V_19 ;
int V_171 ;
V_1 -> V_21 = F_116 ( sizeof( struct V_2 ) * V_1 -> V_121 ) ;
if ( ! V_1 -> V_21 )
return - V_30 ;
V_1 -> V_15 = F_117 ( sizeof( struct V_83 )
* V_1 -> V_121 ) ;
if ( ! V_1 -> V_15 )
return - V_30 ;
for ( V_19 = 0 ; V_19 < V_1 -> V_121 ; V_19 ++ ) {
struct V_2 * V_128 = & V_1 -> V_21 [ V_19 ] ;
struct V_83 * V_44 = & V_1 -> V_15 [ V_19 ] ;
V_128 -> V_8 = V_9 ;
V_44 -> V_8 = V_9 ;
}
if ( ! V_11 -> V_172 -> V_173 )
return 0 ;
V_171 = V_11 -> V_172 -> V_173 ( V_11 , 0 , V_11 -> V_166 ,
F_113 , V_1 ) ;
if ( V_171 ) {
F_20 ( L_19 ) ;
return - V_168 ;
}
return 0 ;
}
static int F_118 ( struct V_1 * V_1 )
{
F_119 ( & V_174 ) ;
if ( ! V_175 ) {
V_175 = F_120 ( L_20 ,
sizeof( struct F_58 ) , 0 , 0 , NULL ) ;
if ( ! V_175 ) {
F_121 ( & V_174 ) ;
return - V_30 ;
}
V_176 = F_120 ( L_21 ,
sizeof( struct V_22 ) + sizeof( struct V_125 ) ,
0 , 0 , NULL ) ;
if ( ! V_176 ) {
F_122 ( V_175 ) ;
F_121 ( & V_174 ) ;
return - V_30 ;
}
}
F_121 ( & V_174 ) ;
V_1 -> V_91 = F_123 ( V_177 , 0 ) ;
if ( ! V_1 -> V_91 )
return - V_30 ;
V_1 -> V_104 = F_124 ( V_1 -> V_11 -> V_68 ,
V_175 ) ;
if ( ! V_1 -> V_104 )
return - V_30 ;
V_1 -> V_28 = F_124 ( 64 , V_176 ) ;
if ( ! V_1 -> V_28 )
return - V_30 ;
F_125 ( & V_1 -> V_178 . V_10 ) ;
F_126 ( & V_1 -> V_178 . V_179 ) ;
return 0 ;
}
static void F_127 ( struct V_1 * V_1 )
{
F_128 ( V_1 -> V_91 ) ;
F_128 ( V_1 -> V_104 ) ;
F_128 ( V_1 -> V_28 ) ;
}
static void F_129 ( struct V_1 * V_1 )
{
F_130 ( V_1 -> V_49 ) ;
}
static int F_131 ( struct V_1 * V_1 , int V_180 , int V_181 )
{
struct V_43 * V_11 = V_1 -> V_11 ;
struct V_61 * V_62 ;
int V_19 , V_182 ;
F_125 ( & V_1 -> V_7 ) ;
V_1 -> V_49 = F_132 ( V_1 -> V_68 , sizeof( struct V_61 ) ,
V_142 ) ;
if ( ! V_1 -> V_49 )
return - V_30 ;
for ( V_19 = 0 ; V_19 < V_1 -> V_68 ; V_19 ++ ) {
struct V_112 * V_58 = V_11 -> V_183 -> V_184 ( V_11 , V_180 + V_19 ) ;
if ( V_11 -> V_12 >
V_185 * V_186 ) {
F_20 ( L_22 ) ;
goto V_124;
}
V_62 = & V_1 -> V_49 [ V_19 ] ;
V_62 -> V_1 = V_1 ;
V_62 -> V_40 = V_58 ;
F_126 ( & V_62 -> V_108 ) ;
F_69 ( & V_62 -> V_73 , F_67 ) ;
F_125 ( & V_62 -> V_10 ) ;
V_1 -> V_187 += V_11 -> V_56 ;
V_1 -> V_121 += V_11 -> V_188 ;
V_62 -> V_65 = F_116 ( sizeof( struct V_4 ) *
V_1 -> V_11 -> V_56 ) ;
if ( ! V_62 -> V_65 )
goto V_124;
for ( V_182 = 0 ; V_182 < V_1 -> V_11 -> V_56 ; V_182 ++ ) {
struct V_4 * V_5 = & V_62 -> V_65 [ V_182 ] ;
struct V_38 * V_39 = & V_58 -> V_65 [ V_182 ] ;
V_5 -> V_40 = V_39 ;
F_126 ( & V_5 -> V_111 ) ;
F_125 ( & V_5 -> V_10 ) ;
}
}
return 0 ;
V_124:
return - V_30 ;
}
static void F_133 ( struct V_1 * V_1 )
{
F_106 ( V_1 ) ;
F_112 ( V_1 ) ;
F_127 ( V_1 ) ;
F_129 ( V_1 ) ;
F_130 ( V_1 ) ;
}
static void F_134 ( void * V_163 )
{
struct V_1 * V_1 = V_163 ;
F_135 ( & V_1 -> V_75 ) ;
F_136 ( V_1 -> V_72 ) ;
F_136 ( V_1 -> V_117 ) ;
F_133 ( V_1 ) ;
}
static T_1 F_137 ( void * V_163 )
{
struct V_1 * V_1 = V_163 ;
struct V_43 * V_11 = V_1 -> V_11 ;
T_1 V_189 , V_190 ;
V_189 = V_1 -> V_68 * V_11 -> V_191 * 4 ;
V_190 = V_1 -> V_121 - V_189 ;
if ( V_189 > V_1 -> V_121 ) {
F_20 ( L_23 ) ;
return 0 ;
}
F_25 ( V_190 , 10 ) ;
return V_190 * 9 * V_34 ;
}
static void F_138 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
struct V_43 * V_11 = V_1 -> V_11 ;
int V_192 ;
struct V_2 * V_23 ;
T_2 V_60 , V_193 ;
for ( V_192 = 0 ; V_192 < V_11 -> V_12 ; V_192 ++ ) {
V_60 = F_23 ( V_1 , V_5 ) + V_192 ;
V_193 = V_1 -> V_15 [ V_60 ] . V_8 ;
if ( V_193 == V_9 )
continue;
V_23 = & V_1 -> V_21 [ V_193 ] ;
if ( V_60 == V_23 -> V_8 ) {
V_23 -> V_5 = V_5 ;
} else {
F_139 ( V_192 , V_5 -> V_13 ) ;
V_5 -> V_14 ++ ;
}
}
}
static int F_140 ( struct V_1 * V_1 )
{
struct V_61 * V_62 ;
struct V_4 * V_5 ;
int V_194 , V_195 ;
for ( V_194 = 0 ; V_194 < V_1 -> V_68 ; V_194 ++ ) {
V_62 = & V_1 -> V_49 [ V_194 ] ;
for ( V_195 = 0 ; V_195 < V_1 -> V_11 -> V_56 ;
V_195 ++ ) {
V_5 = & V_62 -> V_65 [ V_195 ] ;
F_138 ( V_1 , V_5 ) ;
}
}
return 0 ;
}
static int F_141 ( struct V_1 * V_1 )
{
struct V_61 * V_62 ;
struct V_4 * V_5 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_1 -> V_68 ; V_19 ++ ) {
V_62 = & V_1 -> V_49 [ V_19 ] ;
V_5 = F_29 ( V_1 , V_62 , 0 ) ;
if ( ! V_5 )
goto V_124;
F_27 ( V_62 , V_5 ) ;
V_5 = F_29 ( V_1 , V_62 , 1 ) ;
if ( ! V_5 )
goto V_124;
V_62 -> V_69 = V_5 ;
}
return 0 ;
V_124:
F_35 ( V_1 ) ;
return - V_168 ;
}
static void * F_142 ( struct V_43 * V_11 , struct V_196 * V_197 ,
int V_180 , int V_181 )
{
struct V_81 * V_198 = V_11 -> V_82 ;
struct V_81 * V_199 = V_197 -> V_158 ;
struct V_1 * V_1 ;
int V_171 ;
if ( ! ( V_11 -> V_200 . V_201 & V_202 ) ) {
F_20 ( L_24 ,
V_11 -> V_200 . V_201 ) ;
return F_11 ( - V_168 ) ;
}
V_1 = F_143 ( sizeof( struct V_1 ) , V_142 ) ;
if ( ! V_1 )
return F_11 ( - V_30 ) ;
V_1 -> V_131 . V_203 = & V_204 ;
V_1 -> V_11 = V_11 ;
V_1 -> V_157 = V_197 ;
F_103 ( & V_1 -> V_153 ) ;
F_125 ( & V_1 -> V_152 ) ;
F_69 ( & V_1 -> V_154 , F_102 ) ;
V_1 -> V_68 = V_181 - V_180 + 1 ;
F_32 ( & V_1 -> V_71 , - 1 ) ;
V_171 = F_131 ( V_1 , V_180 , V_181 ) ;
if ( V_171 ) {
F_20 ( L_25 ) ;
goto V_124;
}
V_1 -> V_16 = V_11 -> V_188 * V_180 ;
V_1 -> V_118 = V_180 ;
V_171 = F_118 ( V_1 ) ;
if ( V_171 ) {
F_20 ( L_26 ) ;
goto V_124;
}
V_171 = F_115 ( V_1 ) ;
if ( V_171 ) {
F_20 ( L_27 ) ;
goto V_124;
}
V_171 = F_140 ( V_1 ) ;
if ( V_171 ) {
F_20 ( L_28 ) ;
goto V_124;
}
V_171 = F_141 ( V_1 ) ;
if ( V_171 ) {
F_20 ( L_29 ) ;
goto V_124;
}
V_171 = F_109 ( V_1 ) ;
if ( V_171 ) {
F_20 ( L_30 ) ;
goto V_124;
}
F_144 ( V_199 , F_145 ( V_198 ) ) ;
F_146 ( V_199 , F_147 ( V_198 ) ) ;
F_148 ( L_31 ,
V_1 -> V_68 , ( unsigned long long ) V_1 -> V_121 ) ;
F_41 ( & V_1 -> V_75 , V_76 + F_42 ( 10 ) ) ;
return V_1 ;
V_124:
F_133 ( V_1 ) ;
return F_11 ( V_171 ) ;
}
static int T_7 F_149 ( void )
{
return F_150 ( & V_204 ) ;
}
static void F_151 ( void )
{
F_152 ( & V_204 ) ;
}
