static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
if ( F_2 ( V_2 ) )
return ( void * ) V_2 -> V_3 ;
return NULL ;
}
static int F_3 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_6 ;
struct V_7 * V_8 ;
int V_9 = 0 ;
struct V_1 * V_10 ;
if ( F_4 ( ! V_5 ) )
return ! F_5 ( V_2 ) ;
if ( F_5 ( V_2 ) ) {
F_6 ( L_1 ,
V_5 -> V_11 , V_2 , V_2 -> V_12 ) ;
return 0 ;
}
V_6 = V_5 -> V_11 ;
V_8 = F_7 ( V_6 ) ;
V_10 = F_8 ( V_8 -> V_13 -> V_14 ) ;
F_9 ( & V_8 -> V_15 ) ;
if ( V_8 -> V_16 == NULL )
V_8 -> V_16 = F_8 ( V_10 ) ;
++ V_8 -> V_17 ;
if ( V_8 -> V_18 == 0 )
F_10 ( V_6 ) ;
++ V_8 -> V_18 ;
F_6 ( L_2
L_3 ,
V_5 -> V_11 , V_2 , V_2 -> V_12 ,
V_8 -> V_18 - 1 , V_8 -> V_17 - 1 ,
V_8 -> V_18 , V_8 -> V_17 ,
V_10 , V_10 -> V_19 , V_10 -> V_20 ) ;
F_11 ( & V_8 -> V_15 ) ;
F_12 ( & V_5 -> V_21 ) ;
if ( V_2 -> V_5 ) {
F_13 ( ! F_14 ( V_2 ) ) ;
F_15 ( V_2 , V_2 -> V_5 ) ;
F_16 ( & V_5 -> V_22 ,
F_17 ( V_2 ) , V_23 ) ;
V_2 -> V_3 = ( unsigned long ) V_10 ;
F_18 ( V_2 ) ;
} else {
F_6 ( L_4 , V_2 ) ;
V_9 = 1 ;
}
F_19 ( & V_5 -> V_21 ) ;
if ( V_9 )
F_20 ( V_8 , 1 , V_10 ) ;
F_21 ( V_5 -> V_11 , V_24 ) ;
F_22 ( ! F_23 ( V_2 ) ) ;
return 1 ;
}
static void F_24 ( struct V_2 * V_2 , unsigned long V_25 )
{
struct V_6 * V_6 ;
struct V_7 * V_8 ;
struct V_1 * V_10 = F_1 ( V_2 ) ;
F_22 ( ! F_25 ( V_2 ) ) ;
F_22 ( ! F_2 ( V_2 ) ) ;
F_22 ( ! V_2 -> V_5 ) ;
V_6 = V_2 -> V_5 -> V_11 ;
if ( ! F_23 ( V_2 ) )
F_26 ( L_5 , V_6 , V_2 ) ;
if ( V_25 == 0 )
F_27 ( V_2 ) ;
V_8 = F_7 ( V_6 ) ;
if ( V_25 == 0 ) {
F_6 ( L_6 ,
V_6 , V_2 , V_2 -> V_12 , V_25 ) ;
F_20 ( V_8 , 1 , V_10 ) ;
F_28 ( V_10 ) ;
V_2 -> V_3 = 0 ;
F_29 ( V_2 ) ;
} else {
F_6 ( L_7 ,
V_6 , V_2 , V_2 -> V_12 ) ;
}
}
static int F_30 ( struct V_2 * V_2 , T_1 V_26 )
{
struct V_6 * V_6 = V_2 -> V_5 ? V_2 -> V_5 -> V_11 : NULL ;
F_6 ( L_8 , V_6 , V_2 , V_2 -> V_12 ) ;
F_31 ( F_23 ( V_2 ) ) ;
F_31 ( F_2 ( V_2 ) ) ;
return 0 ;
}
static int F_32 ( struct V_27 * V_28 , struct V_2 * V_2 )
{
struct V_6 * V_6 = V_28 -> V_29 -> V_30 ;
struct V_7 * V_8 = F_7 ( V_6 ) ;
struct V_31 * V_32 =
& F_33 ( V_6 ) -> V_33 -> V_32 ;
int V_34 = 0 ;
T_2 V_35 = V_36 ;
F_6 ( L_9 ,
V_6 , V_28 , V_2 , V_2 -> V_12 ) ;
V_34 = F_34 ( V_32 , F_35 ( V_6 ) , & V_8 -> V_37 ,
V_2 -> V_12 << V_38 , & V_35 ,
V_8 -> V_39 , V_8 -> V_40 ,
& V_2 , 1 , 0 ) ;
if ( V_34 == - V_41 )
V_34 = 0 ;
if ( V_34 < 0 ) {
F_36 ( V_2 ) ;
goto V_42;
} else if ( V_34 < V_36 ) {
F_37 ( V_2 , V_34 , V_36 ) ;
}
F_38 ( V_2 ) ;
V_42:
return V_34 < 0 ? V_34 : 0 ;
}
static int F_39 ( struct V_27 * V_28 , struct V_2 * V_2 )
{
int V_43 = F_32 ( V_28 , V_2 ) ;
F_40 ( V_2 ) ;
return V_43 ;
}
static void F_41 ( struct V_44 * V_45 , struct V_46 * V_47 )
{
struct V_6 * V_6 = V_45 -> V_48 ;
struct V_49 * V_50 ;
int V_51 , V_52 ;
int V_53 ;
V_50 = V_47 -> V_54 . V_55 ;
F_31 ( F_42 ( V_50 -> V_56 ) == 0 ) ;
V_51 = F_42 ( V_50 -> V_57 ) ;
V_52 = F_42 ( V_47 -> V_58 . V_59 ) ;
F_6 ( L_10 , V_6 , V_45 , V_51 , V_52 ) ;
for ( V_53 = 0 ; V_53 < V_45 -> V_60 ; V_53 ++ , V_52 -= V_36 ) {
struct V_2 * V_2 = V_45 -> V_61 [ V_53 ] ;
if ( V_52 < ( int ) V_36 ) {
int V_62 = V_52 < 0 ? 0 : V_52 ;
F_37 ( V_2 , V_62 , V_36 ) ;
}
F_6 ( L_11 , V_6 , V_2 ,
V_2 -> V_12 ) ;
F_43 ( V_2 ) ;
F_38 ( V_2 ) ;
F_40 ( V_2 ) ;
F_44 ( V_2 ) ;
}
F_45 ( V_45 -> V_61 ) ;
}
static int F_46 ( struct V_6 * V_6 , struct V_63 * V_64 , int V_65 )
{
struct V_31 * V_32 =
& F_33 ( V_6 ) -> V_33 -> V_32 ;
struct V_7 * V_8 = F_7 ( V_6 ) ;
struct V_2 * V_2 = F_47 ( V_64 -> V_66 , struct V_2 , V_67 ) ;
struct V_44 * V_45 ;
T_2 V_68 ;
T_2 V_35 ;
int V_53 ;
struct V_2 * * V_69 ;
T_3 V_70 ;
int V_71 = 0 ;
int V_72 ;
V_68 = V_2 -> V_12 << V_38 ;
V_70 = V_2 -> V_12 ;
F_48 (page, page_list, lru) {
if ( V_2 -> V_12 != V_70 )
break;
V_71 ++ ;
V_70 ++ ;
if ( V_65 && V_71 == V_65 )
break;
}
V_35 = V_71 << V_38 ;
F_6 ( L_12 , V_6 , V_71 ,
V_68 , V_35 ) ;
V_45 = F_49 ( V_32 , & V_8 -> V_37 , F_35 ( V_6 ) ,
V_68 , & V_35 ,
V_73 , V_74 ,
NULL , 0 ,
V_8 -> V_39 , V_8 -> V_40 ,
NULL , false , 1 , 0 ) ;
if ( ! V_45 )
return - V_75 ;
V_71 = V_35 >> V_38 ;
V_69 = F_50 ( sizeof( * V_69 ) * V_71 , V_76 ) ;
V_72 = - V_75 ;
if ( ! V_69 )
goto V_42;
for ( V_53 = 0 ; V_53 < V_71 ; ++ V_53 ) {
V_2 = F_47 ( V_64 -> V_66 , struct V_2 , V_67 ) ;
F_22 ( F_25 ( V_2 ) ) ;
F_51 ( & V_2 -> V_67 ) ;
F_6 ( L_13 , V_6 , V_2 ,
V_2 -> V_12 ) ;
if ( F_52 ( V_2 , & V_6 -> V_77 , V_2 -> V_12 ,
V_76 ) ) {
F_44 ( V_2 ) ;
F_6 ( L_14 ,
V_6 , V_2 ) ;
V_71 = V_53 ;
goto V_78;
}
V_69 [ V_53 ] = V_2 ;
}
V_45 -> V_61 = V_69 ;
V_45 -> V_60 = V_71 ;
V_45 -> V_79 = F_41 ;
V_45 -> V_48 = V_6 ;
F_6 ( L_15 , V_6 , V_45 , V_68 , V_35 ) ;
V_72 = F_53 ( V_32 , V_45 , false ) ;
if ( V_72 < 0 )
goto V_78;
F_54 ( V_45 ) ;
return V_71 ;
V_78:
F_55 ( V_69 , V_71 ) ;
V_42:
F_54 ( V_45 ) ;
return V_72 ;
}
static int F_56 ( struct V_27 * V_27 , struct V_4 * V_5 ,
struct V_63 * V_64 , unsigned V_71 )
{
struct V_6 * V_6 = V_27 -> V_29 -> V_30 ;
struct V_80 * V_81 = F_33 ( V_6 ) ;
int V_51 = 0 ;
int V_65 = 0 ;
if ( V_81 -> V_82 -> V_83 >= V_36 )
V_65 = ( V_81 -> V_82 -> V_83 + V_36 - 1 )
>> V_84 ;
F_6 ( L_16 , V_6 , V_27 , V_71 ,
V_65 ) ;
while ( ! F_57 ( V_64 ) ) {
V_51 = F_46 ( V_6 , V_64 , V_65 ) ;
if ( V_51 < 0 )
goto V_42;
F_22 ( V_51 == 0 ) ;
}
V_42:
F_6 ( L_17 , V_6 , V_27 , V_51 ) ;
return V_51 ;
}
static struct V_1 * F_58 ( struct V_6 * V_6 ,
T_2 * V_85 )
{
struct V_7 * V_8 = F_7 ( V_6 ) ;
struct V_1 * V_10 = NULL ;
struct V_86 * V_87 = NULL ;
F_9 ( & V_8 -> V_15 ) ;
F_59 (capsnap, &ci->i_cap_snaps, ci_item) {
F_6 ( L_18 , V_87 ,
V_87 -> V_88 , V_87 -> V_89 ) ;
if ( V_87 -> V_89 ) {
V_10 = F_8 ( V_87 -> V_88 ) ;
if ( V_85 )
* V_85 = V_87 -> V_90 ;
break;
}
}
if ( ! V_10 && V_8 -> V_17 ) {
V_10 = F_8 ( V_8 -> V_16 ) ;
F_6 ( L_19 ,
V_10 , V_8 -> V_17 ) ;
}
F_11 ( & V_8 -> V_15 ) ;
return V_10 ;
}
static int F_60 ( struct V_2 * V_2 , struct V_91 * V_92 )
{
struct V_6 * V_6 ;
struct V_7 * V_8 ;
struct V_80 * V_81 ;
struct V_31 * V_32 ;
T_4 V_93 = V_2 -> V_12 << V_38 ;
int V_35 = V_36 ;
T_4 V_94 ;
int V_34 = 0 ;
struct V_1 * V_10 , * V_95 ;
T_2 V_85 = 0 ;
long V_96 ;
F_6 ( L_20 , V_2 , V_2 -> V_12 ) ;
if ( ! V_2 -> V_5 || ! V_2 -> V_5 -> V_11 ) {
F_6 ( L_21 , V_2 ) ;
return - V_97 ;
}
V_6 = V_2 -> V_5 -> V_11 ;
V_8 = F_7 ( V_6 ) ;
V_81 = F_33 ( V_6 ) ;
V_32 = & V_81 -> V_33 -> V_32 ;
V_10 = F_1 ( V_2 ) ;
if ( V_10 == NULL ) {
F_6 ( L_22 , V_6 , V_2 ) ;
goto V_42;
}
V_95 = F_58 ( V_6 , & V_85 ) ;
if ( V_10 -> V_19 > V_95 -> V_19 ) {
F_6 ( L_23 ,
V_6 , V_2 , V_10 ) ;
F_31 ( ( V_98 -> V_99 & V_100 ) == 0 ) ;
F_28 ( V_95 ) ;
goto V_42;
}
F_28 ( V_95 ) ;
if ( V_85 )
V_94 = V_85 ;
else
V_94 = F_61 ( V_6 ) ;
if ( V_94 < V_93 + V_35 )
V_35 = V_94 - V_93 ;
F_6 ( L_24 ,
V_6 , V_2 , V_2 -> V_12 , V_93 , V_35 , V_10 ) ;
V_96 = F_62 ( & V_81 -> V_101 ) ;
if ( V_96 >
F_63 ( V_81 -> V_82 -> V_102 ) )
F_64 ( & V_81 -> V_103 , V_104 ) ;
F_65 ( V_2 ) ;
V_34 = F_66 ( V_32 , F_35 ( V_6 ) ,
& V_8 -> V_37 , V_10 ,
V_93 , V_35 ,
V_8 -> V_39 , V_8 -> V_40 ,
& V_6 -> V_105 ,
& V_2 , 1 , 0 , 0 , true ) ;
if ( V_34 < 0 ) {
F_6 ( L_25 , V_34 , V_2 ) ;
F_36 ( V_2 ) ;
F_67 ( & V_6 -> V_77 , V_34 ) ;
if ( V_92 )
V_92 -> V_106 ++ ;
} else {
F_6 ( L_26 , V_2 ) ;
V_34 = 0 ;
}
V_2 -> V_3 = 0 ;
F_29 ( V_2 ) ;
F_68 ( V_2 ) ;
F_20 ( V_8 , 1 , V_10 ) ;
F_28 ( V_10 ) ;
V_42:
return V_34 ;
}
static int F_69 ( struct V_2 * V_2 , struct V_91 * V_92 )
{
int V_34 ;
struct V_6 * V_6 = V_2 -> V_5 -> V_11 ;
F_22 ( ! V_6 ) ;
F_10 ( V_6 ) ;
V_34 = F_60 ( V_2 , V_92 ) ;
F_40 ( V_2 ) ;
F_70 ( V_6 ) ;
return V_34 ;
}
static void F_71 ( struct V_2 * * V_69 , int V_107 )
{
struct V_108 V_109 ;
int V_53 ;
F_72 ( & V_109 , 0 ) ;
for ( V_53 = 0 ; V_53 < V_107 ; V_53 ++ ) {
if ( F_73 ( & V_109 , V_69 [ V_53 ] ) == 0 )
F_74 ( & V_109 ) ;
}
F_74 ( & V_109 ) ;
}
static void F_75 ( struct V_44 * V_45 ,
struct V_46 * V_47 )
{
struct V_6 * V_6 = V_45 -> V_48 ;
struct V_49 * V_50 ;
struct V_110 * V_111 ;
struct V_7 * V_8 = F_7 ( V_6 ) ;
unsigned V_112 ;
struct V_2 * V_2 ;
int V_53 ;
struct V_1 * V_10 = V_45 -> V_113 ;
struct V_4 * V_5 = V_6 -> V_114 ;
T_5 V_51 = - V_115 ;
T_2 V_52 = 0 ;
struct V_80 * V_81 = F_33 ( V_6 ) ;
long V_96 ;
unsigned V_116 = F_76 ( V_8 ) ;
V_50 = V_47 -> V_54 . V_55 ;
F_31 ( F_42 ( V_50 -> V_56 ) == 0 ) ;
V_111 = ( void * ) ( V_50 + 1 ) ;
V_51 = F_42 ( V_50 -> V_57 ) ;
V_52 = F_77 ( V_111 -> V_117 . V_118 ) ;
if ( V_51 >= 0 ) {
V_112 = V_45 -> V_60 ;
} else {
V_112 = 0 ;
F_67 ( V_5 , V_51 ) ;
}
F_6 ( L_27 ,
V_6 , V_51 , V_52 , V_112 ) ;
for ( V_53 = 0 ; V_53 < V_45 -> V_60 ; V_53 ++ ) {
V_2 = V_45 -> V_61 [ V_53 ] ;
F_22 ( ! V_2 ) ;
F_31 ( ! F_14 ( V_2 ) ) ;
V_96 =
F_78 ( & V_81 -> V_101 ) ;
if ( V_96 <
F_79 ( V_81 -> V_82 -> V_102 ) )
F_80 ( & V_81 -> V_103 ,
V_104 ) ;
F_28 ( F_1 ( V_2 ) ) ;
V_2 -> V_3 = 0 ;
F_29 ( V_2 ) ;
F_6 ( L_28 , V_53 , V_2 ) ;
F_68 ( V_2 ) ;
if ( ( V_116 & ( V_119 | V_120 ) ) == 0 )
F_81 ( V_6 -> V_114 , V_2 ) ;
F_40 ( V_2 ) ;
}
F_6 ( L_29 , V_6 , V_112 ) ;
F_20 ( V_8 , V_45 -> V_60 , V_10 ) ;
F_71 ( V_45 -> V_61 , V_45 -> V_60 ) ;
if ( V_45 -> V_121 )
F_82 ( V_45 -> V_61 ,
F_83 ( V_6 -> V_122 ) -> V_123 ) ;
else
F_45 ( V_45 -> V_61 ) ;
F_54 ( V_45 ) ;
}
static void F_84 ( struct V_80 * V_81 ,
struct V_44 * V_45 )
{
V_45 -> V_61 = F_50 ( sizeof( struct V_2 * ) * V_45 -> V_60 ,
V_76 ) ;
if ( ! V_45 -> V_61 ) {
V_45 -> V_61 = F_85 ( V_81 -> V_123 , V_76 ) ;
V_45 -> V_121 = 1 ;
F_31 ( ! V_45 -> V_61 ) ;
}
}
static int F_86 ( struct V_4 * V_5 ,
struct V_91 * V_92 )
{
struct V_6 * V_6 = V_5 -> V_11 ;
struct V_7 * V_8 = F_7 ( V_6 ) ;
struct V_80 * V_81 ;
T_3 V_12 , V_124 , V_125 ;
int V_126 = 0 ;
int V_127 = 1 ;
T_3 V_128 = 0 , V_129 = 0 ;
struct V_1 * V_10 = NULL , * V_130 = NULL , * V_131 ;
struct V_108 V_109 ;
int V_132 = 0 ;
int V_51 = 0 ;
unsigned V_133 = 1 << V_6 -> V_134 ;
struct V_44 * V_45 = NULL ;
int V_135 ;
T_2 V_85 = 0 ;
V_135 = V_92 -> V_136 == V_137 ;
if ( F_87 ( V_8 , V_138 ) )
V_135 = 1 ;
F_6 ( L_30 ,
V_6 , V_135 ,
V_92 -> V_136 == V_139 ? L_31 :
( V_92 -> V_136 == V_137 ? L_32 : L_33 ) ) ;
V_81 = F_33 ( V_6 ) ;
if ( V_81 -> V_140 == V_141 ) {
F_88 ( L_34 , V_6 ) ;
return - V_115 ;
}
if ( V_81 -> V_82 -> V_133 && V_81 -> V_82 -> V_133 < V_133 )
V_133 = V_81 -> V_82 -> V_133 ;
if ( V_133 < V_36 )
V_133 = V_36 ;
V_129 = V_133 >> V_38 ;
F_72 ( & V_109 , 0 ) ;
if ( V_92 -> V_142 ) {
V_124 = V_5 -> V_143 ;
V_125 = - 1 ;
F_6 ( L_35 , V_124 ) ;
} else {
V_124 = V_92 -> V_144 >> V_38 ;
V_125 = V_92 -> V_145 >> V_38 ;
if ( V_92 -> V_144 == 0 && V_92 -> V_145 == V_146 )
V_126 = 1 ;
V_127 = 0 ;
F_6 ( L_36 , V_124 , V_125 ) ;
}
V_12 = V_124 ;
V_147:
F_28 ( V_10 ) ;
V_10 = F_58 ( V_6 , & V_85 ) ;
if ( ! V_10 ) {
F_6 ( L_37 ) ;
goto V_42;
}
F_6 ( L_38 ,
V_10 , V_10 -> V_19 , V_10 -> V_20 ) ;
if ( V_130 && V_10 != V_130 ) {
F_6 ( L_39 ,
V_12 ) ;
V_12 = V_124 ;
}
V_130 = V_10 ;
while ( ! V_132 && V_12 <= V_125 ) {
unsigned V_53 ;
int V_148 ;
T_3 V_149 ;
int V_150 , V_151 ;
struct V_2 * V_2 ;
int V_152 ;
T_2 V_25 , V_35 ;
struct V_153 * V_154 ;
struct V_110 * V_111 ;
long V_96 ;
V_149 = 0 ;
V_151 = 0 ;
V_128 = V_129 ;
V_155:
V_148 = - 1 ;
V_152 = F_89 ( V_125 - V_12 ,
F_89 ( ( T_3 ) V_156 ,
V_128 - ( T_3 ) V_151 ) - 1 )
+ 1 ;
V_150 = F_90 ( & V_109 , V_5 , & V_12 ,
V_23 ,
V_152 ) ;
F_6 ( L_40 , V_150 ) ;
if ( ! V_150 && ! V_151 )
break;
for ( V_53 = 0 ; V_53 < V_150 && V_151 < V_128 ; V_53 ++ ) {
V_2 = V_109 . V_69 [ V_53 ] ;
F_6 ( L_41 , V_2 , V_2 -> V_12 ) ;
if ( V_151 == 0 )
F_91 ( V_2 ) ;
else if ( ! F_92 ( V_2 ) )
break;
if ( F_4 ( ! F_23 ( V_2 ) ) ||
F_4 ( V_2 -> V_5 != V_5 ) ) {
F_6 ( L_42 , V_2 ) ;
F_40 ( V_2 ) ;
break;
}
if ( ! V_92 -> V_142 && V_2 -> V_12 > V_125 ) {
F_6 ( L_43 , V_2 ) ;
V_132 = 1 ;
F_40 ( V_2 ) ;
break;
}
if ( V_149 && ( V_2 -> V_12 != V_149 ) ) {
F_6 ( L_44 , V_2 ) ;
F_40 ( V_2 ) ;
break;
}
if ( V_92 -> V_136 != V_139 ) {
F_6 ( L_45 , V_2 ) ;
F_93 ( V_2 ) ;
}
if ( ( V_85 && F_94 ( V_2 ) > V_85 ) ||
( ! V_85 &&
F_94 ( V_2 ) > F_61 ( V_6 ) ) ) {
F_6 ( L_46 , V_2 , V_85 ?
V_85 : F_61 ( V_6 ) ) ;
V_132 = 1 ;
F_40 ( V_2 ) ;
break;
}
if ( F_95 ( V_2 ) ) {
F_6 ( L_47 , V_2 ) ;
F_40 ( V_2 ) ;
break;
}
V_131 = F_1 ( V_2 ) ;
if ( V_131 -> V_19 > V_10 -> V_19 ) {
F_6 ( L_48 ,
V_131 , V_131 -> V_19 , V_10 , V_10 -> V_19 ) ;
F_40 ( V_2 ) ;
if ( ! V_151 )
continue;
break;
}
if ( ! F_96 ( V_2 ) ) {
F_6 ( L_49 , V_2 ) ;
F_40 ( V_2 ) ;
break;
}
if ( V_151 == 0 ) {
V_25 = ( unsigned long long ) V_2 -> V_12
<< V_38 ;
V_35 = V_133 ;
V_45 = F_49 ( & V_81 -> V_33 -> V_32 ,
& V_8 -> V_37 ,
F_35 ( V_6 ) ,
V_25 , & V_35 ,
V_157 ,
V_158 |
V_159 ,
V_10 , V_135 ,
V_8 -> V_39 ,
V_8 -> V_40 ,
& V_6 -> V_105 , true , 1 , 0 ) ;
if ( ! V_45 ) {
V_51 = - V_75 ;
F_40 ( V_2 ) ;
break;
}
V_128 = V_45 -> V_60 ;
F_84 ( V_81 , V_45 ) ;
V_45 -> V_79 = F_75 ;
V_45 -> V_48 = V_6 ;
}
if ( V_148 < 0 )
V_148 = V_53 ;
F_6 ( L_50 ,
V_6 , V_2 , V_2 -> V_12 ) ;
V_96 =
F_62 ( & V_81 -> V_101 ) ;
if ( V_96 > F_63 (
V_81 -> V_82 -> V_102 ) ) {
F_64 ( & V_81 -> V_103 ,
V_104 ) ;
}
F_65 ( V_2 ) ;
V_45 -> V_61 [ V_151 ] = V_2 ;
V_151 ++ ;
V_149 = V_2 -> V_12 + 1 ;
}
if ( ! V_151 )
goto V_160;
if ( V_53 ) {
int V_161 ;
F_22 ( ! V_151 || V_148 < 0 ) ;
if ( V_150 && V_53 == V_150 &&
V_151 < V_128 ) {
F_6 ( L_51 ) ;
F_97 ( & V_109 ) ;
goto V_155;
}
for ( V_161 = V_53 ; V_161 < V_150 ; V_161 ++ ) {
F_6 ( L_52 ,
V_109 . V_69 [ V_161 ] ) ;
V_109 . V_69 [ V_161 - V_53 + V_148 ] = V_109 . V_69 [ V_161 ] ;
}
V_109 . V_162 -= V_53 - V_148 ;
}
V_25 = V_45 -> V_61 [ 0 ] -> V_12 << V_38 ;
V_35 = F_89 ( ( V_85 ? V_85 : F_61 ( V_6 ) ) - V_25 ,
( T_2 ) V_151 << V_38 ) ;
F_6 ( L_53 ,
V_151 , V_25 , V_35 ) ;
V_45 -> V_60 = V_151 ;
V_154 = V_45 -> V_163 -> V_54 . V_55 ;
V_111 = ( void * ) ( V_154 + 1 ) ;
V_111 -> V_117 . V_118 = F_98 ( V_35 ) ;
V_111 -> V_164 = F_99 ( V_35 ) ;
V_45 -> V_163 -> V_58 . V_59 = F_99 ( V_35 ) ;
V_51 = F_53 ( & V_81 -> V_33 -> V_32 , V_45 , true ) ;
F_22 ( V_51 ) ;
V_45 = NULL ;
V_12 = V_149 ;
V_92 -> V_165 -= V_151 ;
if ( V_92 -> V_165 <= 0 )
V_132 = 1 ;
V_160:
F_6 ( L_54 , ( int ) V_109 . V_162 ,
V_109 . V_162 ? V_109 . V_69 [ 0 ] : NULL ) ;
F_74 ( & V_109 ) ;
if ( V_151 && ! V_132 )
goto V_147;
}
if ( V_127 && ! V_132 ) {
F_6 ( L_55 ) ;
V_127 = 0 ;
V_12 = 0 ;
goto V_147;
}
if ( V_92 -> V_142 || ( V_126 && V_92 -> V_165 > 0 ) )
V_5 -> V_143 = V_12 ;
V_42:
if ( V_45 )
F_54 ( V_45 ) ;
F_28 ( V_10 ) ;
F_6 ( L_56 , V_51 ) ;
return V_51 ;
}
static int F_100 ( struct V_6 * V_6 ,
struct V_1 * V_10 )
{
struct V_1 * V_95 = F_58 ( V_6 , NULL ) ;
int V_72 = ! V_95 || V_10 -> V_19 <= V_95 -> V_19 ;
F_28 ( V_95 ) ;
return V_72 ;
}
static int F_101 ( struct V_27 * V_27 ,
T_4 V_166 , unsigned V_35 ,
struct V_2 * V_2 )
{
struct V_6 * V_6 = V_27 -> V_29 -> V_30 ;
struct V_7 * V_8 = F_7 ( V_6 ) ;
struct V_167 * V_168 = F_33 ( V_6 ) -> V_168 ;
T_4 V_93 = V_166 & V_169 ;
int V_170 = V_166 & ~ V_169 ;
int V_171 = V_170 + V_35 ;
T_4 V_94 ;
int V_43 ;
struct V_1 * V_10 , * V_95 ;
V_172:
F_93 ( V_2 ) ;
F_22 ( ! V_8 -> V_13 ) ;
F_102 ( & V_168 -> V_173 ) ;
F_22 ( ! V_8 -> V_13 -> V_14 ) ;
V_10 = F_1 ( V_2 ) ;
if ( V_10 && V_10 != V_8 -> V_16 ) {
V_95 = F_58 ( V_6 , NULL ) ;
F_103 ( & V_168 -> V_173 ) ;
if ( V_10 -> V_19 > V_95 -> V_19 ) {
F_28 ( V_95 ) ;
F_6 ( L_57 ,
V_2 , V_10 ) ;
V_10 = F_8 ( V_10 ) ;
F_40 ( V_2 ) ;
F_104 ( V_6 ) ;
V_43 = F_105 ( V_8 -> V_174 ,
F_100 ( V_6 , V_10 ) ) ;
F_28 ( V_10 ) ;
if ( V_43 == - V_175 )
return V_43 ;
return - V_176 ;
}
F_28 ( V_95 ) ;
F_6 ( L_58 ,
V_2 , V_10 ) ;
if ( ! F_96 ( V_2 ) )
goto V_172;
V_43 = F_60 ( V_2 , NULL ) ;
if ( V_43 < 0 )
goto V_177;
goto V_172;
}
if ( F_14 ( V_2 ) ) {
F_6 ( L_59 , V_2 ) ;
return 0 ;
}
if ( V_170 == 0 && V_35 == V_36 )
return 0 ;
V_94 = V_6 -> V_94 ;
if ( V_94 + V_35 > V_6 -> V_122 -> V_178 ) {
V_43 = - V_179 ;
goto V_180;
}
if ( V_93 >= V_94 ||
( V_170 == 0 && ( V_166 + V_35 ) >= V_94 &&
V_171 - V_170 != V_36 ) ) {
F_6 ( L_60 ,
V_2 , V_170 , V_171 , ( int ) V_36 ) ;
F_106 ( V_2 ,
0 , V_170 ,
V_171 , V_36 ) ;
return 0 ;
}
F_103 ( & V_168 -> V_173 ) ;
V_43 = F_32 ( V_27 , V_2 ) ;
if ( V_43 < 0 )
goto V_177;
goto V_172;
V_180:
F_103 ( & V_168 -> V_173 ) ;
V_177:
F_40 ( V_2 ) ;
return V_43 ;
}
static int F_107 ( struct V_27 * V_27 , struct V_4 * V_5 ,
T_4 V_166 , unsigned V_35 , unsigned V_99 ,
struct V_2 * * V_181 , void * * V_182 )
{
struct V_6 * V_6 = V_27 -> V_29 -> V_30 ;
struct V_2 * V_2 ;
T_3 V_12 = V_166 >> V_38 ;
int V_43 ;
do {
V_2 = F_108 ( V_5 , V_12 , 0 ) ;
if ( ! V_2 )
return - V_75 ;
* V_181 = V_2 ;
F_6 ( L_61 , V_27 ,
V_6 , V_2 , ( int ) V_166 , ( int ) V_35 ) ;
V_43 = F_101 ( V_27 , V_166 , V_35 , V_2 ) ;
} while ( V_43 == - V_176 );
return V_43 ;
}
static int F_109 ( struct V_27 * V_27 , struct V_4 * V_5 ,
T_4 V_166 , unsigned V_35 , unsigned V_183 ,
struct V_2 * V_2 , void * V_182 )
{
struct V_6 * V_6 = V_27 -> V_29 -> V_30 ;
struct V_80 * V_81 = F_33 ( V_6 ) ;
struct V_167 * V_168 = V_81 -> V_168 ;
unsigned V_184 = V_166 & ( V_36 - 1 ) ;
int V_185 = 0 ;
F_6 ( L_62 , V_27 ,
V_6 , V_2 , ( int ) V_166 , ( int ) V_183 , ( int ) V_35 ) ;
if ( V_183 < V_35 )
F_37 ( V_2 , V_184 + V_183 , V_35 ) ;
if ( V_166 + V_183 > V_6 -> V_94 )
V_185 = F_110 ( V_6 , V_166 + V_183 ) ;
if ( ! F_14 ( V_2 ) )
F_38 ( V_2 ) ;
F_111 ( V_2 ) ;
F_40 ( V_2 ) ;
F_103 ( & V_168 -> V_173 ) ;
F_44 ( V_2 ) ;
if ( V_185 )
F_112 ( F_7 ( V_6 ) , V_186 , NULL ) ;
return V_183 ;
}
static T_6 F_113 ( int V_187 , struct V_188 * V_189 ,
const struct V_190 * V_191 ,
T_4 V_166 , unsigned long V_192 )
{
F_31 ( 1 ) ;
return - V_179 ;
}
static int F_114 ( struct V_193 * V_194 , struct V_195 * V_196 )
{
struct V_6 * V_6 = V_194 -> V_197 -> V_29 -> V_30 ;
struct V_2 * V_2 = V_196 -> V_2 ;
struct V_167 * V_168 = F_33 ( V_6 ) -> V_168 ;
T_4 V_68 = V_2 -> V_12 << V_38 ;
T_4 V_90 , V_35 ;
int V_72 ;
V_90 = F_61 ( V_6 ) ;
if ( V_68 + V_36 <= V_90 )
V_35 = V_36 ;
else
V_35 = V_90 & ~ V_169 ;
F_6 ( L_63 , V_6 ,
V_68 , V_35 , V_2 , V_2 -> V_12 ) ;
F_91 ( V_2 ) ;
V_72 = V_198 ;
if ( ( V_68 > V_90 ) ||
( V_2 -> V_5 != V_6 -> V_114 ) )
goto V_42;
V_72 = F_101 ( V_194 -> V_197 , V_68 , V_35 , V_2 ) ;
if ( V_72 == 0 ) {
F_111 ( V_2 ) ;
F_103 ( & V_168 -> V_173 ) ;
V_72 = V_199 ;
} else {
if ( V_72 == - V_75 )
V_72 = V_200 ;
else
V_72 = V_201 ;
}
V_42:
F_6 ( L_64 , V_6 , V_68 , V_35 , V_72 ) ;
if ( V_72 != V_199 )
F_40 ( V_2 ) ;
return V_72 ;
}
int F_115 ( struct V_27 * V_27 , struct V_193 * V_194 )
{
struct V_4 * V_5 = V_27 -> V_202 ;
if ( ! V_5 -> V_203 -> V_204 )
return - V_205 ;
F_116 ( V_27 ) ;
V_194 -> V_206 = & V_207 ;
V_194 -> V_208 |= V_209 ;
return 0 ;
}
