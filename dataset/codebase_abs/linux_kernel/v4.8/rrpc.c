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
unsigned int V_18 )
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
while ( 1 ) {
V_25 = F_9 ( V_1 , V_17 , V_18 ) ;
if ( V_25 )
break;
F_18 () ;
}
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
static void F_28 ( struct V_63 * V_64 , struct V_4 * V_65 ,
struct V_4 * * V_66 )
{
struct V_1 * V_1 = V_64 -> V_1 ;
if ( * V_66 ) {
F_3 ( & ( * V_66 ) -> V_10 ) ;
F_5 ( ! F_22 ( V_1 , * V_66 ) ) ;
F_7 ( & ( * V_66 ) -> V_10 ) ;
}
* V_66 = V_65 ;
}
static struct V_4 * F_29 ( struct V_1 * V_1 , struct V_63 * V_64 ,
unsigned long V_67 )
{
struct V_38 * V_39 ;
struct V_4 * V_5 ;
V_39 = F_30 ( V_1 -> V_11 , V_64 -> V_40 , V_67 ) ;
if ( ! V_39 ) {
F_20 ( L_2 ) ;
return NULL ;
}
V_5 = F_31 ( V_64 , V_39 -> V_42 ) ;
V_39 -> V_68 = V_5 ;
F_32 ( V_5 -> V_13 , V_1 -> V_11 -> V_12 ) ;
V_5 -> V_37 = 0 ;
V_5 -> V_14 = 0 ;
F_33 ( & V_5 -> V_69 , 0 ) ;
return V_5 ;
}
static void F_34 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
F_35 ( V_1 -> V_11 , V_5 -> V_40 ) ;
}
static void F_36 ( struct V_1 * V_1 )
{
struct V_63 * V_64 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_1 -> V_44 ; V_19 ++ ) {
V_64 = & V_1 -> V_52 [ V_19 ] ;
if ( V_64 -> V_70 )
F_34 ( V_1 , V_64 -> V_70 ) ;
if ( V_64 -> V_71 )
F_34 ( V_1 , V_64 -> V_71 ) ;
}
}
static struct V_63 * F_37 ( struct V_1 * V_1 )
{
int V_72 = F_38 ( & V_1 -> V_73 ) ;
return & V_1 -> V_52 [ V_72 % V_1 -> V_44 ] ;
}
static void F_39 ( struct V_1 * V_1 )
{
struct V_63 * V_64 ;
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_1 -> V_44 ; V_19 ++ ) {
V_64 = & V_1 -> V_52 [ V_19 ] ;
F_40 ( V_1 -> V_74 , & V_64 -> V_75 ) ;
}
}
static void F_41 ( unsigned long V_76 )
{
struct V_1 * V_1 = (struct V_1 * ) V_76 ;
F_39 ( V_1 ) ;
F_42 ( & V_1 -> V_77 , V_78 + F_43 ( 10 ) ) ;
}
static void F_44 ( struct V_31 * V_31 )
{
struct V_79 * V_80 = V_31 -> V_81 ;
if ( V_31 -> V_82 )
F_20 ( L_3 , V_31 -> V_82 ) ;
F_45 ( V_80 ) ;
}
static int F_46 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
struct V_83 * V_84 = V_1 -> V_11 -> V_84 ;
struct V_85 * V_86 ;
struct V_22 * V_25 ;
struct V_31 * V_31 ;
struct V_87 * V_87 ;
int V_88 ;
int V_89 = V_1 -> V_11 -> V_12 ;
T_2 V_90 ;
F_47 ( V_91 ) ;
if ( F_48 ( V_5 -> V_13 , V_89 ) )
return 0 ;
V_31 = F_49 ( V_92 , 1 ) ;
if ( ! V_31 ) {
F_20 ( L_4 ) ;
return - V_30 ;
}
V_87 = F_10 ( V_1 -> V_93 , V_92 ) ;
if ( ! V_87 ) {
F_50 ( V_31 ) ;
return - V_30 ;
}
while ( ( V_88 = F_51 ( V_5 -> V_13 ,
V_89 ) ) < V_89 ) {
V_90 = V_5 -> V_40 -> V_42 * V_89 + V_88 ;
V_94:
F_3 ( & V_1 -> V_7 ) ;
V_86 = & V_1 -> V_15 [ V_90 - V_1 -> V_16 ] ;
if ( V_86 -> V_8 == V_9 ) {
F_7 ( & V_1 -> V_7 ) ;
continue;
}
V_25 = F_9 ( V_1 , V_86 -> V_8 , 1 ) ;
if ( F_52 ( V_25 ) ) {
F_7 ( & V_1 -> V_7 ) ;
F_18 () ;
goto V_94;
}
F_7 ( & V_1 -> V_7 ) ;
V_31 -> V_32 . V_33 = F_53 ( V_86 -> V_8 ) ;
F_54 ( V_31 , V_95 , 0 ) ;
V_31 -> V_81 = & V_91 ;
V_31 -> V_96 = F_44 ;
F_55 ( V_84 , V_31 , V_87 , V_36 , 0 ) ;
if ( F_56 ( V_1 , V_31 , V_25 , V_97 ) ) {
F_20 ( L_5 ) ;
F_15 ( V_1 , V_25 ) ;
goto V_98;
}
F_57 ( & V_91 ) ;
if ( V_31 -> V_82 ) {
F_15 ( V_1 , V_25 ) ;
goto V_98;
}
F_58 ( V_31 ) ;
F_59 ( & V_91 ) ;
V_31 -> V_32 . V_33 = F_53 ( V_86 -> V_8 ) ;
F_54 ( V_31 , V_99 , 0 ) ;
V_31 -> V_81 = & V_91 ;
V_31 -> V_96 = F_44 ;
F_55 ( V_84 , V_31 , V_87 , V_36 , 0 ) ;
if ( F_56 ( V_1 , V_31 , V_25 , V_97 ) ) {
F_20 ( L_6 ) ;
F_15 ( V_1 , V_25 ) ;
goto V_98;
}
F_57 ( & V_91 ) ;
F_15 ( V_1 , V_25 ) ;
if ( V_31 -> V_82 )
goto V_98;
F_58 ( V_31 ) ;
}
V_98:
F_14 ( V_87 , V_1 -> V_93 ) ;
F_50 ( V_31 ) ;
if ( ! F_48 ( V_5 -> V_13 , V_89 ) ) {
F_20 ( L_7 ) ;
return - V_100 ;
}
return 0 ;
}
static void F_60 ( struct V_101 * V_102 )
{
struct F_60 * V_103 = F_61 ( V_102 , struct F_60 ,
V_75 ) ;
struct V_1 * V_1 = V_103 -> V_1 ;
struct V_4 * V_5 = V_103 -> V_5 ;
struct V_63 * V_64 = V_5 -> V_64 ;
struct V_46 * V_11 = V_1 -> V_11 ;
F_14 ( V_103 , V_1 -> V_104 ) ;
F_62 ( L_8 , V_5 -> V_40 -> V_42 ) ;
if ( F_46 ( V_1 , V_5 ) )
goto V_105;
if ( F_63 ( V_11 , V_5 -> V_40 ) )
goto V_105;
F_34 ( V_1 , V_5 ) ;
return;
V_105:
F_3 ( & V_64 -> V_10 ) ;
F_64 ( & V_5 -> V_106 , & V_64 -> V_107 ) ;
F_7 ( & V_64 -> V_10 ) ;
}
static struct V_4 * F_65 ( struct V_4 * V_108 ,
struct V_4 * V_109 )
{
if ( V_108 -> V_14 == V_109 -> V_14 )
return V_108 ;
return ( V_108 -> V_14 < V_109 -> V_14 ) ? V_109 : V_108 ;
}
static struct V_4 * F_66 ( struct V_63 * V_64 )
{
struct V_110 * V_107 = & V_64 -> V_107 ;
struct V_4 * V_111 , * V_112 ;
F_67 ( F_68 ( V_107 ) ) ;
V_112 = F_69 ( V_107 , struct V_4 , V_106 ) ;
F_70 (rblock, prio_list, prio)
V_112 = F_65 ( V_112 , V_111 ) ;
return V_112 ;
}
static void F_71 ( struct V_101 * V_102 )
{
struct V_63 * V_64 = F_61 ( V_102 , struct V_63 , V_75 ) ;
struct V_1 * V_1 = V_64 -> V_1 ;
struct V_113 * V_60 = V_64 -> V_40 ;
struct F_60 * V_103 ;
unsigned int V_114 ;
V_114 = V_1 -> V_11 -> V_43 / V_115 ;
if ( V_114 < V_1 -> V_44 )
V_114 = V_1 -> V_44 ;
F_3 ( & V_64 -> V_10 ) ;
while ( V_114 > V_60 -> V_116 &&
! F_68 ( & V_64 -> V_107 ) ) {
struct V_4 * V_111 = F_66 ( V_64 ) ;
struct V_38 * V_117 = V_111 -> V_40 ;
if ( ! V_111 -> V_14 )
break;
V_103 = F_10 ( V_1 -> V_104 , V_29 ) ;
if ( ! V_103 )
break;
F_72 ( & V_111 -> V_106 ) ;
F_67 ( ! F_22 ( V_1 , V_111 ) ) ;
F_62 ( L_9 , V_117 -> V_42 ) ;
V_103 -> V_1 = V_1 ;
V_103 -> V_5 = V_111 ;
F_73 ( & V_103 -> V_75 , F_60 ) ;
F_40 ( V_1 -> V_118 , & V_103 -> V_75 ) ;
V_114 -- ;
}
F_7 ( & V_64 -> V_10 ) ;
}
static void F_74 ( struct V_101 * V_102 )
{
struct F_60 * V_103 = F_61 ( V_102 , struct F_60 ,
V_75 ) ;
struct V_1 * V_1 = V_103 -> V_1 ;
struct V_4 * V_5 = V_103 -> V_5 ;
struct V_63 * V_64 = V_5 -> V_64 ;
F_3 ( & V_64 -> V_10 ) ;
F_64 ( & V_5 -> V_106 , & V_64 -> V_107 ) ;
F_7 ( & V_64 -> V_10 ) ;
F_14 ( V_103 , V_1 -> V_104 ) ;
F_62 ( L_10 ,
V_5 -> V_40 -> V_42 ) ;
}
static struct V_63 * F_75 ( struct V_1 * V_1 , int V_119 )
{
unsigned int V_19 ;
struct V_63 * V_64 , * V_120 ;
if ( ! V_119 )
return F_37 ( V_1 ) ;
V_120 = & V_1 -> V_52 [ 0 ] ;
F_76 (rrpc, rlun, i) {
if ( V_64 -> V_40 -> V_116 >
V_120 -> V_40 -> V_116 )
V_120 = V_64 ;
}
return V_120 ;
}
static struct V_2 * F_77 ( struct V_1 * V_1 , T_1 V_23 ,
struct V_4 * V_5 , T_2 V_62 )
{
struct V_2 * V_20 ;
struct V_85 * V_86 ;
F_67 ( V_23 >= V_1 -> V_121 ) ;
V_20 = & V_1 -> V_21 [ V_23 ] ;
F_3 ( & V_1 -> V_7 ) ;
if ( V_20 -> V_5 )
F_1 ( V_1 , V_20 ) ;
V_20 -> V_8 = V_62 ;
V_20 -> V_5 = V_5 ;
V_86 = & V_1 -> V_15 [ V_20 -> V_8 - V_1 -> V_16 ] ;
V_86 -> V_8 = V_23 ;
F_7 ( & V_1 -> V_7 ) ;
return V_20 ;
}
static T_2 F_78 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
T_2 V_8 = V_9 ;
F_3 ( & V_5 -> V_10 ) ;
if ( F_22 ( V_1 , V_5 ) )
goto V_122;
V_8 = F_24 ( V_1 , V_5 ) + V_5 -> V_37 ;
V_5 -> V_37 ++ ;
V_122:
F_7 ( & V_5 -> V_10 ) ;
return V_8 ;
}
static struct V_2 * F_79 ( struct V_1 * V_1 , T_1 V_23 ,
int V_119 )
{
struct V_63 * V_64 ;
struct V_4 * V_5 , * * V_66 ;
struct V_113 * V_60 ;
T_2 V_62 ;
int V_123 = 0 ;
V_64 = F_75 ( V_1 , V_119 ) ;
V_60 = V_64 -> V_40 ;
if ( ! V_119 && V_60 -> V_116 < V_1 -> V_44 * 4 )
return NULL ;
F_3 ( & V_64 -> V_10 ) ;
V_66 = & V_64 -> V_70 ;
V_5 = V_64 -> V_70 ;
V_124:
V_62 = F_78 ( V_1 , V_5 ) ;
if ( V_62 != V_9 )
goto V_125;
if ( ! F_68 ( & V_64 -> V_126 ) ) {
V_127:
V_5 = F_69 ( & V_64 -> V_126 , struct V_4 ,
V_106 ) ;
F_28 ( V_64 , V_5 , V_66 ) ;
F_80 ( & V_5 -> V_106 ) ;
goto V_124;
}
F_7 ( & V_64 -> V_10 ) ;
V_5 = F_29 ( V_1 , V_64 , V_123 ) ;
if ( V_5 ) {
F_3 ( & V_64 -> V_10 ) ;
F_64 ( & V_5 -> V_106 , & V_64 -> V_126 ) ;
goto V_127;
}
if ( F_81 ( V_119 ) && ! V_123 ) {
V_66 = & V_64 -> V_71 ;
V_5 = V_64 -> V_71 ;
V_123 = 1 ;
F_3 ( & V_64 -> V_10 ) ;
goto V_124;
}
F_20 ( L_11 ) ;
return NULL ;
V_125:
F_7 ( & V_64 -> V_10 ) ;
return F_77 ( V_1 , V_23 , V_5 , V_62 ) ;
}
static void F_82 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
struct F_60 * V_103 ;
V_103 = F_10 ( V_1 -> V_104 , V_29 ) ;
if ( ! V_103 ) {
F_20 ( L_12 ) ;
return;
}
V_103 -> V_1 = V_1 ;
V_103 -> V_5 = V_5 ;
F_73 ( & V_103 -> V_75 , F_74 ) ;
F_40 ( V_1 -> V_118 , & V_103 -> V_75 ) ;
}
static void F_83 ( struct V_1 * V_1 , struct V_128 * V_129 ,
T_1 V_23 , T_3 V_130 )
{
struct V_2 * V_131 ;
struct V_4 * V_5 ;
struct V_113 * V_60 ;
int V_132 , V_19 ;
for ( V_19 = 0 ; V_19 < V_130 ; V_19 ++ ) {
V_131 = & V_1 -> V_21 [ V_23 + V_19 ] ;
V_5 = V_131 -> V_5 ;
V_60 = V_5 -> V_40 -> V_60 ;
V_132 = F_38 ( & V_5 -> V_69 ) ;
if ( F_81 ( V_132 == V_1 -> V_11 -> V_12 ) )
F_82 ( V_1 , V_5 ) ;
}
}
static void F_84 ( struct V_22 * V_25 )
{
struct V_1 * V_1 = F_61 ( V_25 -> V_133 , struct V_1 , V_134 ) ;
struct V_128 * V_129 = F_85 ( V_25 ) ;
T_3 V_130 = V_25 -> V_135 ;
T_1 V_23 = F_86 ( V_25 -> V_31 ) - V_130 ;
if ( F_87 ( V_25 -> V_31 ) == V_136 )
F_83 ( V_1 , V_129 , V_23 , V_130 ) ;
F_50 ( V_25 -> V_31 ) ;
if ( V_129 -> V_67 & V_97 )
return;
F_88 ( V_1 , V_25 ) ;
if ( V_130 > 1 )
F_89 ( V_1 -> V_11 , V_25 -> V_137 , V_25 -> V_138 ) ;
F_14 ( V_25 , V_1 -> V_28 ) ;
}
static int F_90 ( struct V_1 * V_1 , struct V_31 * V_31 ,
struct V_22 * V_25 , unsigned long V_67 , int V_130 )
{
struct V_26 * V_47 = F_12 ( V_25 ) ;
struct V_2 * V_20 ;
T_1 V_23 = F_86 ( V_31 ) ;
int V_119 = V_67 & V_97 ;
int V_19 ;
if ( ! V_119 && F_91 ( V_1 , V_31 , V_25 ) ) {
F_89 ( V_1 -> V_11 , V_25 -> V_137 , V_25 -> V_138 ) ;
return V_139 ;
}
for ( V_19 = 0 ; V_19 < V_130 ; V_19 ++ ) {
F_67 ( ! ( V_23 + V_19 >= 0 && V_23 + V_19 < V_1 -> V_121 ) ) ;
V_20 = & V_1 -> V_21 [ V_23 + V_19 ] ;
if ( V_20 -> V_5 ) {
V_25 -> V_137 [ V_19 ] = F_27 ( V_1 -> V_11 ,
V_20 -> V_8 ) ;
} else {
F_67 ( V_119 ) ;
F_16 ( V_1 , V_47 ) ;
F_89 ( V_1 -> V_11 , V_25 -> V_137 ,
V_25 -> V_138 ) ;
return V_140 ;
}
}
V_25 -> V_141 = V_142 ;
return V_143 ;
}
static int F_92 ( struct V_1 * V_1 , struct V_31 * V_31 , struct V_22 * V_25 ,
unsigned long V_67 )
{
struct V_128 * V_129 = F_85 ( V_25 ) ;
int V_119 = V_67 & V_97 ;
T_1 V_23 = F_86 ( V_31 ) ;
struct V_2 * V_20 ;
if ( ! V_119 && F_91 ( V_1 , V_31 , V_25 ) )
return V_139 ;
F_67 ( ! ( V_23 >= 0 && V_23 < V_1 -> V_121 ) ) ;
V_20 = & V_1 -> V_21 [ V_23 ] ;
if ( V_20 -> V_5 ) {
V_25 -> V_45 = F_27 ( V_1 -> V_11 , V_20 -> V_8 ) ;
} else {
F_67 ( V_119 ) ;
F_88 ( V_1 , V_25 ) ;
return V_140 ;
}
V_25 -> V_141 = V_142 ;
V_129 -> V_8 = V_20 ;
return V_143 ;
}
static int F_93 ( struct V_1 * V_1 , struct V_31 * V_31 ,
struct V_22 * V_25 , unsigned long V_67 , int V_130 )
{
struct V_26 * V_47 = F_12 ( V_25 ) ;
struct V_2 * V_131 ;
T_1 V_23 = F_86 ( V_31 ) ;
int V_119 = V_67 & V_97 ;
int V_19 ;
if ( ! V_119 && F_91 ( V_1 , V_31 , V_25 ) ) {
F_89 ( V_1 -> V_11 , V_25 -> V_137 , V_25 -> V_138 ) ;
return V_139 ;
}
for ( V_19 = 0 ; V_19 < V_130 ; V_19 ++ ) {
V_131 = F_79 ( V_1 , V_23 + V_19 , V_119 ) ;
if ( ! V_131 ) {
F_67 ( V_119 ) ;
F_16 ( V_1 , V_47 ) ;
F_89 ( V_1 -> V_11 , V_25 -> V_137 ,
V_25 -> V_138 ) ;
F_39 ( V_1 ) ;
return V_139 ;
}
V_25 -> V_137 [ V_19 ] = F_27 ( V_1 -> V_11 ,
V_131 -> V_8 ) ;
}
V_25 -> V_141 = V_144 ;
return V_143 ;
}
static int F_94 ( struct V_1 * V_1 , struct V_31 * V_31 ,
struct V_22 * V_25 , unsigned long V_67 )
{
struct V_128 * V_129 = F_85 ( V_25 ) ;
struct V_2 * V_131 ;
int V_119 = V_67 & V_97 ;
T_1 V_23 = F_86 ( V_31 ) ;
if ( ! V_119 && F_91 ( V_1 , V_31 , V_25 ) )
return V_139 ;
V_131 = F_79 ( V_1 , V_23 , V_119 ) ;
if ( ! V_131 ) {
F_67 ( V_119 ) ;
F_88 ( V_1 , V_25 ) ;
F_39 ( V_1 ) ;
return V_139 ;
}
V_25 -> V_45 = F_27 ( V_1 -> V_11 , V_131 -> V_8 ) ;
V_25 -> V_141 = V_144 ;
V_129 -> V_8 = V_131 ;
return V_143 ;
}
static int F_95 ( struct V_1 * V_1 , struct V_31 * V_31 ,
struct V_22 * V_25 , unsigned long V_67 , T_3 V_130 )
{
if ( V_130 > 1 ) {
V_25 -> V_137 = F_96 ( V_1 -> V_11 , V_145 ,
& V_25 -> V_138 ) ;
if ( ! V_25 -> V_137 ) {
F_20 ( L_13 ) ;
return V_146 ;
}
if ( F_97 ( V_31 ) == V_99 )
return F_93 ( V_1 , V_31 , V_25 , V_67 ,
V_130 ) ;
return F_90 ( V_1 , V_31 , V_25 , V_67 , V_130 ) ;
}
if ( F_97 ( V_31 ) == V_99 )
return F_94 ( V_1 , V_31 , V_25 , V_67 ) ;
return F_92 ( V_1 , V_31 , V_25 , V_67 ) ;
}
static int F_56 ( struct V_1 * V_1 , struct V_31 * V_31 ,
struct V_22 * V_25 , unsigned long V_67 )
{
int V_147 ;
struct V_128 * V_148 = F_85 ( V_25 ) ;
T_3 V_149 = F_98 ( V_31 ) ;
int V_150 = F_99 ( V_31 ) << 9 ;
if ( V_150 < V_1 -> V_11 -> V_151 )
return V_146 ;
else if ( V_150 > V_1 -> V_11 -> V_152 )
return V_146 ;
V_147 = F_95 ( V_1 , V_31 , V_25 , V_67 , V_149 ) ;
if ( V_147 )
return V_147 ;
F_100 ( V_31 ) ;
V_25 -> V_31 = V_31 ;
V_25 -> V_133 = & V_1 -> V_134 ;
V_25 -> V_135 = V_149 ;
V_148 -> V_67 = V_67 ;
V_147 = F_101 ( V_1 -> V_11 , V_25 ) ;
if ( V_147 ) {
F_20 ( L_14 , V_147 ) ;
F_50 ( V_31 ) ;
if ( ! ( V_67 & V_97 ) ) {
F_88 ( V_1 , V_25 ) ;
if ( V_25 -> V_135 > 1 )
F_89 ( V_1 -> V_11 ,
V_25 -> V_137 , V_25 -> V_138 ) ;
}
return V_146 ;
}
return V_143 ;
}
static T_4 F_102 ( struct V_83 * V_84 , struct V_31 * V_31 )
{
struct V_1 * V_1 = V_84 -> V_153 ;
struct V_22 * V_25 ;
int V_147 ;
if ( F_97 ( V_31 ) == V_154 ) {
F_17 ( V_1 , V_31 ) ;
return V_155 ;
}
V_25 = F_10 ( V_1 -> V_28 , V_145 ) ;
if ( ! V_25 ) {
F_103 ( L_15 ) ;
F_21 ( V_31 ) ;
return V_155 ;
}
memset ( V_25 , 0 , sizeof( struct V_22 ) ) ;
V_147 = F_56 ( V_1 , V_31 , V_25 , V_156 ) ;
switch ( V_147 ) {
case V_143 :
return V_155 ;
case V_146 :
F_21 ( V_31 ) ;
break;
case V_140 :
F_104 ( V_31 ) ;
break;
case V_139 :
F_3 ( & V_1 -> V_157 ) ;
F_105 ( & V_1 -> V_158 , V_31 ) ;
F_7 ( & V_1 -> V_157 ) ;
F_40 ( V_1 -> V_118 , & V_1 -> V_159 ) ;
break;
}
F_14 ( V_25 , V_1 -> V_28 ) ;
return V_155 ;
}
static void F_106 ( struct V_101 * V_102 )
{
struct V_1 * V_1 = F_61 ( V_102 , struct V_1 , V_159 ) ;
struct V_160 V_161 ;
struct V_31 * V_31 ;
F_107 ( & V_161 ) ;
F_3 ( & V_1 -> V_157 ) ;
F_108 ( & V_161 , & V_1 -> V_158 ) ;
F_107 ( & V_1 -> V_158 ) ;
F_7 ( & V_1 -> V_157 ) ;
while ( ( V_31 = F_109 ( & V_161 ) ) )
F_102 ( V_1 -> V_162 -> V_163 , V_31 ) ;
}
static void F_110 ( struct V_1 * V_1 )
{
if ( V_1 -> V_74 )
F_111 ( V_1 -> V_74 ) ;
if ( V_1 -> V_118 )
F_111 ( V_1 -> V_118 ) ;
}
static int F_112 ( struct V_1 * V_1 )
{
V_1 -> V_74 = F_113 ( L_16 , V_164 | V_165 ,
V_1 -> V_44 ) ;
if ( ! V_1 -> V_74 )
return - V_30 ;
V_1 -> V_118 = F_113 ( L_17 , V_164 , 1 ) ;
if ( ! V_1 -> V_118 )
return - V_30 ;
F_114 ( & V_1 -> V_77 , F_41 , ( unsigned long ) V_1 ) ;
return 0 ;
}
static void F_115 ( struct V_1 * V_1 )
{
F_116 ( V_1 -> V_15 ) ;
F_116 ( V_1 -> V_21 ) ;
}
static int F_117 ( T_2 V_17 , T_5 V_166 , T_6 * V_167 , void * V_168 )
{
struct V_1 * V_1 = (struct V_1 * ) V_168 ;
struct V_46 * V_11 = V_1 -> V_11 ;
struct V_2 * V_8 = V_1 -> V_21 + V_17 ;
struct V_85 * V_169 = V_1 -> V_15 ;
T_2 V_170 = V_17 + V_166 ;
T_2 V_19 ;
if ( F_81 ( V_170 > V_11 -> V_171 ) ) {
F_20 ( L_18 ) ;
return - V_172 ;
}
for ( V_19 = 0 ; V_19 < V_166 ; V_19 ++ ) {
T_2 V_173 = F_118 ( V_167 [ V_19 ] ) ;
unsigned int V_174 ;
if ( F_81 ( V_173 >= V_11 -> V_171 && V_173 != V_175 ) ) {
F_20 ( L_19 ) ;
return - V_172 ;
}
if ( ! V_173 )
continue;
F_4 ( V_173 , V_1 -> V_121 , & V_174 ) ;
V_8 [ V_19 ] . V_8 = V_173 ;
V_169 [ V_174 ] . V_8 = V_17 + V_19 ;
}
return 0 ;
}
static int F_119 ( struct V_1 * V_1 )
{
struct V_46 * V_11 = V_1 -> V_11 ;
T_1 V_19 ;
int V_176 ;
V_1 -> V_21 = F_120 ( sizeof( struct V_2 ) * V_1 -> V_121 ) ;
if ( ! V_1 -> V_21 )
return - V_30 ;
V_1 -> V_15 = F_121 ( sizeof( struct V_85 )
* V_1 -> V_121 ) ;
if ( ! V_1 -> V_15 )
return - V_30 ;
for ( V_19 = 0 ; V_19 < V_1 -> V_121 ; V_19 ++ ) {
struct V_2 * V_131 = & V_1 -> V_21 [ V_19 ] ;
struct V_85 * V_47 = & V_1 -> V_15 [ V_19 ] ;
V_131 -> V_8 = V_9 ;
V_47 -> V_8 = V_9 ;
}
if ( ! V_11 -> V_177 -> V_178 )
return 0 ;
V_176 = V_11 -> V_177 -> V_178 ( V_11 , V_1 -> V_179 , V_1 -> V_121 ,
F_117 , V_1 ) ;
if ( V_176 ) {
F_20 ( L_20 ) ;
return - V_172 ;
}
return 0 ;
}
static int F_122 ( struct V_1 * V_1 )
{
F_123 ( & V_180 ) ;
if ( ! V_181 ) {
V_181 = F_124 ( L_21 ,
sizeof( struct F_60 ) , 0 , 0 , NULL ) ;
if ( ! V_181 ) {
F_125 ( & V_180 ) ;
return - V_30 ;
}
V_182 = F_124 ( L_22 ,
sizeof( struct V_22 ) + sizeof( struct V_128 ) ,
0 , 0 , NULL ) ;
if ( ! V_182 ) {
F_126 ( V_181 ) ;
F_125 ( & V_180 ) ;
return - V_30 ;
}
}
F_125 ( & V_180 ) ;
V_1 -> V_93 = F_127 ( V_183 , 0 ) ;
if ( ! V_1 -> V_93 )
return - V_30 ;
V_1 -> V_104 = F_128 ( V_1 -> V_11 -> V_44 ,
V_181 ) ;
if ( ! V_1 -> V_104 )
return - V_30 ;
V_1 -> V_28 = F_128 ( 64 , V_182 ) ;
if ( ! V_1 -> V_28 )
return - V_30 ;
F_129 ( & V_1 -> V_184 . V_10 ) ;
F_130 ( & V_1 -> V_184 . V_185 ) ;
return 0 ;
}
static void F_131 ( struct V_1 * V_1 )
{
F_132 ( V_1 -> V_93 ) ;
F_132 ( V_1 -> V_104 ) ;
F_132 ( V_1 -> V_28 ) ;
}
static void F_133 ( struct V_1 * V_1 )
{
struct V_46 * V_11 = V_1 -> V_11 ;
struct V_113 * V_60 ;
struct V_63 * V_64 ;
int V_19 ;
if ( ! V_1 -> V_52 )
return;
for ( V_19 = 0 ; V_19 < V_1 -> V_44 ; V_19 ++ ) {
V_64 = & V_1 -> V_52 [ V_19 ] ;
V_60 = V_64 -> V_40 ;
if ( ! V_60 )
break;
V_11 -> V_186 -> V_187 ( V_11 , V_60 -> V_42 ) ;
F_116 ( V_64 -> V_188 ) ;
}
F_134 ( V_1 -> V_52 ) ;
}
static int F_135 ( struct V_1 * V_1 , int V_189 , int V_190 )
{
struct V_46 * V_11 = V_1 -> V_11 ;
struct V_63 * V_64 ;
int V_19 , V_191 , V_176 = - V_172 ;
if ( V_11 -> V_12 > V_192 * V_193 ) {
F_20 ( L_23 ) ;
return - V_172 ;
}
F_129 ( & V_1 -> V_7 ) ;
V_1 -> V_52 = F_136 ( V_1 -> V_44 , sizeof( struct V_63 ) ,
V_145 ) ;
if ( ! V_1 -> V_52 )
return - V_30 ;
for ( V_19 = 0 ; V_19 < V_1 -> V_44 ; V_19 ++ ) {
int V_194 = V_189 + V_19 ;
struct V_113 * V_60 ;
if ( V_11 -> V_186 -> V_195 ( V_11 , V_194 ) ) {
F_20 ( L_24 , V_194 ) ;
goto V_147;
}
V_60 = V_11 -> V_186 -> V_196 ( V_11 , V_194 ) ;
if ( ! V_60 )
goto V_147;
V_64 = & V_1 -> V_52 [ V_19 ] ;
V_64 -> V_40 = V_60 ;
V_64 -> V_188 = F_120 ( sizeof( struct V_4 ) *
V_1 -> V_11 -> V_43 ) ;
if ( ! V_64 -> V_188 ) {
V_176 = - V_30 ;
goto V_147;
}
for ( V_191 = 0 ; V_191 < V_1 -> V_11 -> V_43 ; V_191 ++ ) {
struct V_4 * V_5 = & V_64 -> V_188 [ V_191 ] ;
struct V_38 * V_39 = & V_60 -> V_188 [ V_191 ] ;
V_5 -> V_40 = V_39 ;
V_5 -> V_64 = V_64 ;
F_130 ( & V_5 -> V_106 ) ;
F_129 ( & V_5 -> V_10 ) ;
}
V_64 -> V_1 = V_1 ;
F_130 ( & V_64 -> V_107 ) ;
F_130 ( & V_64 -> V_126 ) ;
F_73 ( & V_64 -> V_75 , F_71 ) ;
F_129 ( & V_64 -> V_10 ) ;
}
return 0 ;
V_147:
return V_176 ;
}
static int F_137 ( struct V_1 * V_1 , T_1 * V_197 )
{
struct V_46 * V_11 = V_1 -> V_11 ;
struct V_198 * V_186 = V_11 -> V_186 ;
T_1 V_199 = V_1 -> V_121 * V_11 -> V_151 ;
int V_176 ;
V_199 >>= 9 ;
V_176 = V_186 -> V_200 ( V_11 , V_197 , V_199 ) ;
if ( ! V_176 )
* V_197 >>= ( F_138 ( V_11 -> V_151 ) - 9 ) ;
return V_176 ;
}
static void F_139 ( struct V_1 * V_1 )
{
struct V_46 * V_11 = V_1 -> V_11 ;
struct V_198 * V_186 = V_11 -> V_186 ;
T_1 V_197 = V_1 -> V_179 << ( F_138 ( V_11 -> V_151 ) - 9 ) ;
V_186 -> V_201 ( V_11 , V_197 ) ;
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
static void F_141 ( void * V_168 )
{
struct V_1 * V_1 = V_168 ;
F_142 ( & V_1 -> V_77 ) ;
F_143 ( V_1 -> V_74 ) ;
F_143 ( V_1 -> V_118 ) ;
F_140 ( V_1 ) ;
}
static T_1 F_144 ( void * V_168 )
{
struct V_1 * V_1 = V_168 ;
struct V_46 * V_11 = V_1 -> V_11 ;
T_1 V_202 , V_203 ;
V_202 = V_1 -> V_44 * V_11 -> V_12 * 4 ;
V_203 = V_1 -> V_121 - V_202 ;
if ( V_202 > V_1 -> V_121 ) {
F_20 ( L_25 ) ;
return 0 ;
}
F_26 ( V_203 , 10 ) ;
return V_203 * 9 * V_34 ;
}
static void F_145 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
struct V_46 * V_11 = V_1 -> V_11 ;
int V_204 ;
struct V_2 * V_23 ;
T_2 V_205 , V_62 , V_206 ;
V_205 = F_23 ( V_1 , V_5 ) ;
for ( V_204 = 0 ; V_204 < V_11 -> V_12 ; V_204 ++ ) {
V_62 = V_205 + V_204 ;
V_206 = V_1 -> V_15 [ V_62 ] . V_8 ;
if ( V_206 == V_9 )
continue;
V_23 = & V_1 -> V_21 [ V_206 ] ;
if ( V_62 == V_23 -> V_8 ) {
V_23 -> V_5 = V_5 ;
} else {
F_146 ( V_204 , V_5 -> V_13 ) ;
V_5 -> V_14 ++ ;
}
}
}
static int F_147 ( struct V_1 * V_1 )
{
struct V_63 * V_64 ;
struct V_4 * V_5 ;
int V_207 , V_208 ;
for ( V_207 = 0 ; V_207 < V_1 -> V_44 ; V_207 ++ ) {
V_64 = & V_1 -> V_52 [ V_207 ] ;
for ( V_208 = 0 ; V_208 < V_1 -> V_11 -> V_43 ;
V_208 ++ ) {
V_5 = & V_64 -> V_188 [ V_208 ] ;
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
V_5 = F_29 ( V_1 , V_64 , 0 ) ;
if ( ! V_5 )
goto V_147;
F_28 ( V_64 , V_5 , & V_64 -> V_70 ) ;
V_5 = F_29 ( V_1 , V_64 , 1 ) ;
if ( ! V_5 )
goto V_147;
F_28 ( V_64 , V_5 , & V_64 -> V_71 ) ;
}
return 0 ;
V_147:
F_36 ( V_1 ) ;
return - V_172 ;
}
static void * F_149 ( struct V_46 * V_11 , struct V_209 * V_210 ,
int V_189 , int V_190 )
{
struct V_83 * V_211 = V_11 -> V_84 ;
struct V_83 * V_212 = V_210 -> V_163 ;
struct V_1 * V_1 ;
T_1 V_179 ;
int V_176 ;
if ( ! ( V_11 -> V_213 . V_214 & V_215 ) ) {
F_20 ( L_26 ,
V_11 -> V_213 . V_214 ) ;
return F_11 ( - V_172 ) ;
}
V_1 = F_150 ( sizeof( struct V_1 ) , V_145 ) ;
if ( ! V_1 )
return F_11 ( - V_30 ) ;
V_1 -> V_134 . V_216 = & V_217 ;
V_1 -> V_11 = V_11 ;
V_1 -> V_162 = V_210 ;
F_107 ( & V_1 -> V_158 ) ;
F_129 ( & V_1 -> V_157 ) ;
F_73 ( & V_1 -> V_159 , F_106 ) ;
V_1 -> V_44 = V_190 - V_189 + 1 ;
V_1 -> V_218 = ( unsigned long ) V_11 -> V_43 * V_1 -> V_44 ;
V_1 -> V_121 = ( unsigned long long ) V_11 -> V_219 * V_1 -> V_44 ;
F_33 ( & V_1 -> V_73 , - 1 ) ;
V_176 = F_137 ( V_1 , & V_179 ) ;
if ( V_176 < 0 ) {
F_20 ( L_27 ) ;
return F_11 ( V_176 ) ;
}
V_1 -> V_179 = V_179 ;
V_176 = F_135 ( V_1 , V_189 , V_190 ) ;
if ( V_176 ) {
F_20 ( L_28 ) ;
goto V_147;
}
V_1 -> V_16 = V_11 -> V_219 * V_189 ;
V_1 -> V_220 = V_189 ;
V_176 = F_122 ( V_1 ) ;
if ( V_176 ) {
F_20 ( L_29 ) ;
goto V_147;
}
V_176 = F_119 ( V_1 ) ;
if ( V_176 ) {
F_20 ( L_30 ) ;
goto V_147;
}
V_176 = F_147 ( V_1 ) ;
if ( V_176 ) {
F_20 ( L_31 ) ;
goto V_147;
}
V_176 = F_148 ( V_1 ) ;
if ( V_176 ) {
F_20 ( L_32 ) ;
goto V_147;
}
V_176 = F_112 ( V_1 ) ;
if ( V_176 ) {
F_20 ( L_33 ) ;
goto V_147;
}
F_151 ( V_212 , F_152 ( V_211 ) ) ;
F_153 ( V_212 , F_154 ( V_211 ) ) ;
F_155 ( L_34 ,
V_1 -> V_44 , ( unsigned long long ) V_1 -> V_121 ) ;
F_42 ( & V_1 -> V_77 , V_78 + F_43 ( 10 ) ) ;
return V_1 ;
V_147:
F_140 ( V_1 ) ;
return F_11 ( V_176 ) ;
}
static int T_7 F_156 ( void )
{
return F_157 ( & V_217 ) ;
}
static void F_158 ( void )
{
F_159 ( & V_217 ) ;
}
