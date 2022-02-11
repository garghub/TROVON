static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 ,
V_4 ) ;
}
static struct V_1 *
F_3 ( struct V_5 * V_6 , unsigned int V_7 )
{
struct V_1 * V_8 ;
F_4 ( & V_6 -> V_9 ) ;
V_8 = F_1 ( & V_6 -> V_10 ) ;
if ( V_8 ) {
F_5 ( & V_8 -> V_4 ) ;
F_6 ( & V_6 -> V_9 ) ;
} else {
F_6 ( & V_6 -> V_9 ) ;
V_8 = F_7 ( sizeof( * V_8 ) +
V_11 * sizeof( struct V_12 ) ,
V_13 ) ;
if ( ! V_8 )
goto V_14;
F_8 ( & V_8 -> V_4 ) ;
}
V_8 -> V_15 . V_16 = V_8 -> V_17 ;
if ( F_9 ( & V_8 -> V_15 , V_7 ,
V_8 -> V_15 . V_16 ) ) {
F_10 ( V_8 ) ;
V_8 = NULL ;
}
V_14:
return V_8 ;
}
static void F_11 ( struct V_5 * V_6 ,
struct V_1 * V_8 )
{
F_12 ( & V_8 -> V_15 , true ) ;
F_4 ( & V_6 -> V_9 ) ;
F_13 ( & V_8 -> V_4 , & V_6 -> V_10 ) ;
F_6 ( & V_6 -> V_9 ) ;
}
void F_14 ( struct V_5 * V_6 )
{
struct V_1 * V_8 ;
while ( ( V_8 = F_1 ( & V_6 -> V_10 ) ) != NULL ) {
F_5 ( & V_8 -> V_4 ) ;
F_10 ( V_8 ) ;
}
}
static void F_15 ( struct V_5 * V_6 ,
struct V_18 * V_19 )
{
V_19 -> V_20 = V_6 ;
F_16 ( & V_6 -> V_21 ) ;
F_8 ( & V_19 -> V_22 ) ;
V_19 -> V_23 = 0 ;
}
static void F_17 ( struct V_18 * V_19 ,
enum V_24 V_25 )
{
struct V_5 * V_6 = V_19 -> V_20 ;
struct V_1 * V_8 ;
while ( ( V_8 = F_1 ( & V_19 -> V_22 ) ) != NULL ) {
F_5 ( & V_8 -> V_4 ) ;
F_18 ( & V_8 -> V_26 , V_6 -> V_27 ,
V_6 -> V_28 , V_8 -> V_15 . V_16 ,
V_8 -> V_29 , V_25 ) ;
F_11 ( V_6 , V_8 ) ;
}
F_19 ( & V_6 -> V_21 ) ;
}
static struct V_30 *
F_20 ( struct V_5 * V_6 , T_1 * V_31 )
{
struct V_30 * V_32 ;
V_32 = F_7 ( sizeof( * V_32 ) , V_13 ) ;
if ( ! V_32 )
return V_32 ;
V_32 -> V_33 = 0 ;
V_32 -> V_34 = 0 ;
V_32 -> V_35 = F_21 ( ++ V_31 ) ;
V_32 -> V_36 = ++ V_31 ;
F_15 ( V_6 , & V_32 -> V_37 ) ;
V_32 -> V_37 . V_38 . V_39 = V_40 ;
return V_32 ;
}
static void F_22 ( struct V_30 * V_32 )
{
F_17 ( & V_32 -> V_37 , V_41 ) ;
F_10 ( V_32 ) ;
}
static void V_40 ( struct V_42 * V_43 , struct V_44 * V_45 )
{
struct V_46 * V_47 = V_45 -> V_48 ;
struct V_18 * V_19 =
F_23 ( V_47 , struct V_18 , V_38 ) ;
struct V_5 * V_6 = V_19 -> V_20 ;
struct V_30 * V_32 =
F_23 ( V_19 , struct V_30 , V_37 ) ;
F_24 ( V_19 -> V_23 , & V_6 -> V_49 ) ;
F_25 ( & V_6 -> V_50 ) ;
if ( F_26 ( V_45 -> V_51 != V_52 ) ) {
F_27 ( V_53 , & V_6 -> V_21 . V_54 ) ;
if ( V_45 -> V_51 != V_55 )
F_28 ( L_1 ,
F_29 ( V_45 -> V_51 ) ,
V_45 -> V_51 , V_45 -> V_56 ) ;
}
F_22 ( V_32 ) ;
}
static struct V_57 *
F_30 ( struct V_5 * V_6 )
{
struct V_57 * V_32 ;
V_32 = F_7 ( sizeof( * V_32 ) , V_13 ) ;
if ( ! V_32 )
return V_32 ;
F_15 ( V_6 , & V_32 -> V_58 ) ;
V_32 -> V_58 . V_38 . V_39 = V_59 ;
return V_32 ;
}
static void F_31 ( struct V_57 * V_32 )
{
F_17 ( & V_32 -> V_58 , V_60 ) ;
F_10 ( V_32 ) ;
}
static void V_59 ( struct V_42 * V_43 , struct V_44 * V_45 )
{
struct V_46 * V_47 = V_45 -> V_48 ;
struct V_18 * V_19 =
F_23 ( V_47 , struct V_18 , V_38 ) ;
struct V_5 * V_6 = V_19 -> V_20 ;
struct V_57 * V_32 =
F_23 ( V_19 , struct V_57 , V_58 ) ;
F_24 ( V_19 -> V_23 , & V_6 -> V_49 ) ;
F_25 ( & V_6 -> V_50 ) ;
if ( F_26 ( V_45 -> V_51 != V_52 ) ) {
F_27 ( V_53 , & V_6 -> V_21 . V_54 ) ;
if ( V_45 -> V_51 != V_55 )
F_28 ( L_2 ,
F_29 ( V_45 -> V_51 ) ,
V_45 -> V_51 , V_45 -> V_56 ) ;
F_32 ( V_32 -> V_61 , 1 ) ;
} else {
F_4 ( & V_6 -> V_62 ) ;
F_33 ( & V_32 -> V_61 -> V_3 ,
& V_6 -> V_63 ) ;
F_6 ( & V_6 -> V_62 ) ;
F_27 ( V_64 , & V_6 -> V_21 . V_54 ) ;
F_34 ( & V_6 -> V_21 ) ;
}
F_31 ( V_32 ) ;
}
static int F_35 ( struct V_18 * V_19 )
{
struct V_5 * V_6 = V_19 -> V_20 ;
struct V_65 * V_66 = & V_6 -> V_21 ;
struct V_67 * V_68 , * V_69 ;
struct V_2 * V_70 ;
struct V_46 * V_47 ;
int V_71 ;
if ( V_19 -> V_23 > V_6 -> V_72 )
return - V_73 ;
V_68 = NULL ;
V_47 = & V_19 -> V_38 ;
F_36 (tmp, &cc->cc_rwctxts) {
struct V_1 * V_8 ;
V_8 = F_37 ( V_70 , struct V_1 , V_4 ) ;
V_68 = F_38 ( & V_8 -> V_26 , V_6 -> V_27 ,
V_6 -> V_28 , V_47 , V_68 ) ;
V_47 = NULL ;
}
do {
if ( F_39 ( V_19 -> V_23 ,
& V_6 -> V_49 ) > 0 ) {
V_71 = F_40 ( V_6 -> V_27 , V_68 , & V_69 ) ;
if ( V_71 )
break;
return 0 ;
}
F_41 ( & V_74 ) ;
F_24 ( V_19 -> V_23 , & V_6 -> V_49 ) ;
F_42 ( V_6 -> V_50 ,
F_43 ( & V_6 -> V_49 ) > V_19 -> V_23 ) ;
} while ( 1 );
F_28 ( L_3 , V_71 ) ;
F_27 ( V_53 , & V_66 -> V_54 ) ;
if ( V_69 != V_68 )
return 0 ;
F_24 ( V_19 -> V_23 , & V_6 -> V_49 ) ;
F_25 ( & V_6 -> V_50 ) ;
return - V_75 ;
}
static void F_44 ( struct V_30 * V_32 ,
unsigned int V_76 ,
struct V_1 * V_8 )
{
struct V_12 * V_77 = V_8 -> V_15 . V_16 ;
F_45 ( & V_77 [ 0 ] , V_32 -> V_78 , V_76 ) ;
V_32 -> V_78 += V_76 ;
V_8 -> V_29 = 1 ;
}
static void F_46 ( struct V_30 * V_32 ,
unsigned int V_79 ,
struct V_1 * V_8 )
{
unsigned int V_80 , V_81 , V_82 , V_83 ;
struct V_84 * V_85 = V_32 -> V_86 ;
struct V_12 * V_77 ;
struct V_87 * * V_87 ;
V_82 = V_32 -> V_88 + V_85 -> V_89 ;
V_83 = V_82 >> V_90 ;
V_82 = F_47 ( V_82 ) ;
V_87 = V_85 -> V_91 + V_83 ;
V_32 -> V_88 += V_79 ;
V_77 = V_8 -> V_15 . V_16 ;
V_80 = 0 ;
do {
V_81 = F_48 (unsigned int, remaining,
PAGE_SIZE - page_off) ;
F_49 ( V_77 , * V_87 , V_81 , V_82 ) ;
V_79 -= V_81 ;
V_77 = F_50 ( V_77 ) ;
V_82 = 0 ;
V_80 ++ ;
V_87 ++ ;
} while ( V_79 );
V_8 -> V_29 = V_80 ;
}
static int
F_51 ( struct V_30 * V_32 ,
void (* F_52)( struct V_30 * V_32 ,
unsigned int V_76 ,
struct V_1 * V_8 ) ,
unsigned int V_79 )
{
struct V_18 * V_19 = & V_32 -> V_37 ;
struct V_5 * V_6 = V_19 -> V_20 ;
struct V_1 * V_8 ;
T_1 * V_92 ;
int V_71 ;
V_92 = V_32 -> V_36 + V_32 -> V_34 * V_93 ;
do {
unsigned int V_94 ;
T_2 V_95 , V_96 ;
T_3 V_97 ;
if ( V_32 -> V_34 >= V_32 -> V_35 )
goto V_98;
V_96 = F_21 ( V_92 ) ;
V_95 = F_21 ( V_92 + 1 ) ;
F_53 ( V_92 + 2 , & V_97 ) ;
V_97 += V_32 -> V_33 ;
V_94 = F_54 ( V_79 , V_95 - V_32 -> V_33 ) ;
V_8 = F_3 ( V_6 ,
( V_94 >> V_90 ) + 2 ) ;
if ( ! V_8 )
goto V_99;
F_52 ( V_32 , V_94 , V_8 ) ;
V_71 = F_55 ( & V_8 -> V_26 , V_6 -> V_27 ,
V_6 -> V_28 , V_8 -> V_15 . V_16 ,
V_8 -> V_29 , 0 , V_97 ,
V_96 , V_41 ) ;
if ( V_71 < 0 )
goto V_100;
F_13 ( & V_8 -> V_4 , & V_19 -> V_22 ) ;
V_19 -> V_23 += V_71 ;
if ( V_94 == V_95 - V_32 -> V_33 ) {
V_92 += 4 ;
V_32 -> V_34 ++ ;
V_32 -> V_33 = 0 ;
} else {
V_32 -> V_33 += V_94 ;
}
V_79 -= V_94 ;
} while ( V_79 );
return 0 ;
V_98:
F_56 ( L_4 ,
V_32 -> V_35 ) ;
return - V_101 ;
V_99:
F_56 ( L_5 ) ;
return - V_102 ;
V_100:
F_11 ( V_6 , V_8 ) ;
F_28 ( L_6 , V_71 ) ;
return - V_103 ;
}
static int F_57 ( struct V_30 * V_32 ,
struct V_104 * V_105 )
{
V_32 -> V_78 = V_105 -> V_106 ;
return F_51 ( V_32 , F_44 ,
V_105 -> V_107 ) ;
}
static int F_58 ( struct V_30 * V_32 ,
struct V_84 * V_85 )
{
V_32 -> V_86 = V_85 ;
V_32 -> V_88 = 0 ;
return F_51 ( V_32 , F_46 ,
V_85 -> V_108 ) ;
}
int F_59 ( struct V_5 * V_6 , T_1 * V_109 ,
struct V_84 * V_85 )
{
struct V_30 * V_32 ;
int V_71 ;
if ( ! V_85 -> V_108 )
return 0 ;
V_32 = F_20 ( V_6 , V_109 ) ;
if ( ! V_32 )
return - V_102 ;
V_71 = F_58 ( V_32 , V_85 ) ;
if ( V_71 < 0 )
goto V_110;
V_71 = F_35 ( & V_32 -> V_37 ) ;
if ( V_71 < 0 )
goto V_110;
return V_85 -> V_108 ;
V_110:
F_22 ( V_32 ) ;
return V_71 ;
}
int F_60 ( struct V_5 * V_6 , T_1 * V_111 ,
bool V_112 , struct V_84 * V_85 )
{
struct V_30 * V_32 ;
int V_113 , V_71 ;
V_32 = F_20 ( V_6 , V_111 ) ;
if ( ! V_32 )
return - V_102 ;
V_71 = F_57 ( V_32 , & V_85 -> V_114 [ 0 ] ) ;
if ( V_71 < 0 )
goto V_110;
V_113 = V_85 -> V_114 [ 0 ] . V_107 ;
if ( ! V_112 && V_85 -> V_108 ) {
V_71 = F_58 ( V_32 , V_85 ) ;
if ( V_71 < 0 )
goto V_110;
V_113 += V_85 -> V_108 ;
}
if ( V_85 -> V_115 [ 0 ] . V_107 ) {
V_71 = F_57 ( V_32 , & V_85 -> V_115 [ 0 ] ) ;
if ( V_71 < 0 )
goto V_110;
V_113 += V_85 -> V_115 [ 0 ] . V_107 ;
}
V_71 = F_35 ( & V_32 -> V_37 ) ;
if ( V_71 < 0 )
goto V_110;
return V_113 ;
V_110:
F_22 ( V_32 ) ;
return V_71 ;
}
static int F_61 ( struct V_57 * V_32 ,
struct V_116 * V_117 ,
T_2 V_118 , T_2 V_76 , T_3 V_119 )
{
struct V_120 * V_114 = V_32 -> V_61 ;
struct V_18 * V_19 = & V_32 -> V_58 ;
struct V_1 * V_8 ;
unsigned int V_80 , V_121 ;
struct V_12 * V_77 ;
int V_71 ;
V_80 = F_62 ( V_32 -> V_122 + V_76 ) >> V_90 ;
V_8 = F_3 ( V_19 -> V_20 , V_80 ) ;
if ( ! V_8 )
goto V_99;
V_8 -> V_29 = V_80 ;
F_56 ( L_7 ,
V_76 , V_119 , V_118 , V_80 ) ;
V_77 = V_8 -> V_15 . V_16 ;
for ( V_80 = 0 ; V_80 < V_8 -> V_29 ; V_80 ++ ) {
V_121 = F_48 (unsigned int, len,
PAGE_SIZE - info->ri_pageoff) ;
V_114 -> V_123 . V_91 [ V_32 -> V_124 ] =
V_117 -> V_125 [ V_32 -> V_124 ] ;
if ( ! V_32 -> V_122 )
V_114 -> V_126 ++ ;
F_49 ( V_77 , V_117 -> V_125 [ V_32 -> V_124 ] ,
V_121 , V_32 -> V_122 ) ;
V_77 = F_50 ( V_77 ) ;
V_32 -> V_122 += V_121 ;
if ( V_32 -> V_122 == V_127 ) {
V_32 -> V_124 ++ ;
V_32 -> V_122 = 0 ;
}
V_76 -= V_121 ;
if ( V_76 &&
& V_117 -> V_125 [ V_32 -> V_124 + 1 ] > V_117 -> V_128 )
goto V_129;
}
V_71 = F_55 ( & V_8 -> V_26 , V_19 -> V_20 -> V_27 ,
V_19 -> V_20 -> V_28 ,
V_8 -> V_15 . V_16 , V_8 -> V_29 ,
0 , V_119 , V_118 , V_60 ) ;
if ( V_71 < 0 )
goto V_100;
F_13 ( & V_8 -> V_4 , & V_19 -> V_22 ) ;
V_19 -> V_23 += V_71 ;
return 0 ;
V_99:
F_56 ( L_5 ) ;
return - V_102 ;
V_129:
F_56 ( L_8 ) ;
return - V_73 ;
V_100:
F_11 ( V_19 -> V_20 , V_8 ) ;
F_28 ( L_6 , V_71 ) ;
return - V_103 ;
}
static int F_63 ( struct V_116 * V_117 ,
struct V_57 * V_32 ,
T_1 * V_130 )
{
int V_71 ;
V_32 -> V_131 = 0 ;
while ( * V_130 ++ != V_132 ) {
T_2 V_133 , V_134 ;
T_3 V_135 ;
if ( F_21 ( V_130 ++ ) != V_32 -> V_136 )
break;
V_133 = F_21 ( V_130 ++ ) ;
V_134 = F_21 ( V_130 ++ ) ;
V_130 = F_53 ( V_130 , & V_135 ) ;
V_71 = F_61 ( V_32 , V_117 ,
V_133 , V_134 ,
V_135 ) ;
if ( V_71 < 0 )
break;
V_32 -> V_131 += V_134 ;
}
return V_71 ;
}
static int F_64 ( struct V_116 * V_117 ,
struct V_57 * V_32 )
{
struct V_120 * V_114 = V_32 -> V_61 ;
unsigned int V_137 , V_79 ;
T_4 * V_138 , * V_139 ;
if ( V_114 -> V_123 . V_114 [ 0 ] . V_107 > V_127 ) {
F_65 ( L_9 ) ;
return - V_73 ;
}
V_138 = V_114 -> V_123 . V_114 [ 0 ] . V_106 ;
V_138 += V_32 -> V_136 ;
V_137 = V_114 -> V_123 . V_114 [ 0 ] . V_107 - V_32 -> V_136 ;
V_79 = V_137 ;
if ( V_32 -> V_122 > 0 ) {
unsigned int V_76 ;
V_76 = F_48 (unsigned int, remaining,
PAGE_SIZE - info->ri_pageoff) ;
V_139 = F_66 ( V_117 -> V_125 [ V_32 -> V_124 ] ) ;
V_139 += V_32 -> V_122 ;
memcpy ( V_139 , V_138 , V_76 ) ;
V_138 += V_76 ;
V_139 += V_76 ;
V_32 -> V_122 += V_76 ;
V_79 -= V_76 ;
if ( V_32 -> V_122 == V_127 ) {
V_32 -> V_124 ++ ;
V_32 -> V_122 = 0 ;
}
}
if ( V_79 ) {
V_114 -> V_123 . V_91 [ V_32 -> V_124 ] =
V_117 -> V_125 [ V_32 -> V_124 ] ;
V_114 -> V_126 ++ ;
V_139 = F_66 ( V_117 -> V_125 [ V_32 -> V_124 ] ) ;
memcpy ( V_139 , V_138 , V_79 ) ;
V_32 -> V_122 += V_79 ;
}
V_114 -> V_123 . V_108 += V_137 ;
V_114 -> V_123 . V_76 += V_137 ;
V_114 -> V_123 . V_140 += V_137 ;
return 0 ;
}
static int F_67 ( struct V_116 * V_117 ,
struct V_57 * V_32 ,
T_1 * V_130 )
{
struct V_120 * V_114 = V_32 -> V_61 ;
int V_71 ;
F_56 ( L_10 ,
V_32 -> V_136 ) ;
V_32 -> V_124 = V_114 -> V_141 ;
V_32 -> V_122 = 0 ;
V_71 = F_63 ( V_117 , V_32 , V_130 ) ;
if ( V_71 < 0 )
goto V_14;
if ( V_32 -> V_131 & 3 ) {
T_2 V_142 = 4 - ( V_32 -> V_131 & 3 ) ;
V_32 -> V_131 += V_142 ;
V_32 -> V_122 += V_142 ;
if ( V_32 -> V_122 == V_127 ) {
V_32 -> V_124 ++ ;
V_32 -> V_122 = 0 ;
}
}
V_114 -> V_123 . V_108 = V_32 -> V_131 ;
V_114 -> V_123 . V_76 += V_32 -> V_131 ;
V_114 -> V_123 . V_140 += V_32 -> V_131 ;
if ( V_32 -> V_136 < V_114 -> V_123 . V_114 [ 0 ] . V_107 ) {
V_71 = F_64 ( V_117 , V_32 ) ;
if ( V_71 < 0 )
goto V_14;
}
V_114 -> V_123 . V_114 [ 0 ] . V_107 = V_32 -> V_136 ;
V_14:
return V_71 ;
}
static int F_68 ( struct V_116 * V_117 ,
struct V_57 * V_32 ,
T_1 * V_130 )
{
struct V_120 * V_114 = V_32 -> V_61 ;
int V_71 ;
F_56 ( L_11 ) ;
V_32 -> V_124 = V_114 -> V_141 - 1 ;
V_32 -> V_122 = F_47 ( V_114 -> V_143 ) ;
V_71 = F_63 ( V_117 , V_32 , V_130 ) ;
if ( V_71 < 0 )
goto V_14;
V_114 -> V_123 . V_76 += V_32 -> V_131 ;
V_114 -> V_123 . V_140 += V_32 -> V_131 ;
if ( V_114 -> V_123 . V_140 <= V_114 -> V_144 [ 0 ] . V_145 ) {
V_114 -> V_123 . V_114 [ 0 ] . V_107 = V_32 -> V_131 ;
} else {
V_114 -> V_123 . V_114 [ 0 ] . V_107 =
V_114 -> V_144 [ 0 ] . V_145 - V_114 -> V_143 ;
V_114 -> V_123 . V_108 =
V_32 -> V_131 - V_114 -> V_123 . V_114 [ 0 ] . V_107 ;
}
V_14:
return V_71 ;
}
int F_69 ( struct V_5 * V_6 , struct V_116 * V_117 ,
struct V_120 * V_114 , T_1 * V_130 )
{
struct V_57 * V_32 ;
struct V_87 * * V_87 ;
int V_71 ;
V_114 -> V_141 = V_114 -> V_126 ;
V_114 -> V_123 . V_114 [ 0 ] = V_117 -> V_146 . V_114 [ 0 ] ;
V_114 -> V_123 . V_115 [ 0 ] = V_117 -> V_146 . V_115 [ 0 ] ;
V_114 -> V_123 . V_91 = V_114 -> V_91 ;
V_114 -> V_123 . V_89 = 0 ;
V_114 -> V_123 . V_108 = 0 ;
V_114 -> V_123 . V_76 = V_117 -> V_146 . V_76 ;
V_114 -> V_123 . V_140 = V_117 -> V_146 . V_140 ;
V_32 = F_30 ( V_6 ) ;
if ( ! V_32 )
return - V_102 ;
V_32 -> V_61 = V_114 ;
V_32 -> V_136 = F_21 ( V_130 + 1 ) ;
if ( V_32 -> V_136 )
V_71 = F_67 ( V_117 , V_32 , V_130 ) ;
else
V_71 = F_68 ( V_117 , V_32 , V_130 ) ;
if ( V_32 -> V_122 > 0 )
V_32 -> V_124 ++ ;
V_117 -> V_147 = & V_117 -> V_125 [ V_32 -> V_124 ] ;
V_117 -> V_148 = V_117 -> V_147 + 1 ;
if ( V_71 < 0 )
goto V_14;
V_71 = F_35 ( & V_32 -> V_58 ) ;
V_14:
for ( V_87 = V_117 -> V_125 ; V_87 < V_117 -> V_147 ; V_87 ++ )
* V_87 = NULL ;
if ( V_71 < 0 )
F_31 ( V_32 ) ;
return V_71 ;
}
