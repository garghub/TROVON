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
struct V_6 * V_6 = F_33 ( V_28 ) ;
struct V_7 * V_8 = F_7 ( V_6 ) ;
struct V_29 * V_30 =
& F_34 ( V_6 ) -> V_31 -> V_30 ;
int V_32 = 0 ;
T_2 V_33 = V_34 ;
F_6 ( L_9 ,
V_6 , V_28 , V_2 , V_2 -> V_12 ) ;
V_32 = F_35 ( V_30 , F_36 ( V_6 ) , & V_8 -> V_35 ,
( T_2 ) F_37 ( V_2 ) , & V_33 ,
V_8 -> V_36 , V_8 -> V_37 ,
& V_2 , 1 , 0 ) ;
if ( V_32 == - V_38 )
V_32 = 0 ;
if ( V_32 < 0 ) {
F_38 ( V_2 ) ;
goto V_39;
} else if ( V_32 < V_34 ) {
F_39 ( V_2 , V_32 , V_34 ) ;
}
F_40 ( V_2 ) ;
V_39:
return V_32 < 0 ? V_32 : 0 ;
}
static int F_41 ( struct V_27 * V_28 , struct V_2 * V_2 )
{
int V_40 = F_32 ( V_28 , V_2 ) ;
F_42 ( V_2 ) ;
return V_40 ;
}
static void F_43 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
struct V_6 * V_6 = V_42 -> V_45 ;
struct V_46 * V_47 ;
int V_48 = V_42 -> V_49 ;
int V_50 = F_44 ( V_44 -> V_51 . V_52 ) ;
int V_53 ;
int V_54 ;
F_6 ( L_10 , V_6 , V_42 , V_48 , V_50 ) ;
V_47 = F_45 ( V_42 , 0 ) ;
F_22 ( V_47 -> type != V_55 ) ;
V_53 = F_46 ( ( T_2 ) V_47 -> V_56 ,
( T_2 ) V_47 -> V_57 ) ;
for ( V_54 = 0 ; V_54 < V_53 ; V_54 ++ ) {
struct V_2 * V_2 = V_47 -> V_58 [ V_54 ] ;
if ( V_50 < ( int ) V_34 ) {
int V_59 = V_50 < 0 ? 0 : V_50 ;
F_39 ( V_2 , V_59 , V_34 ) ;
}
F_6 ( L_11 , V_6 , V_2 ,
V_2 -> V_12 ) ;
F_47 ( V_2 ) ;
F_40 ( V_2 ) ;
F_42 ( V_2 ) ;
F_48 ( V_2 ) ;
V_50 -= V_34 ;
}
F_49 ( V_47 -> V_58 ) ;
}
static void F_50 ( struct V_2 * * V_58 , int V_53 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < V_53 ; V_54 ++ )
F_42 ( V_58 [ V_54 ] ) ;
}
static int F_51 ( struct V_6 * V_6 , struct V_60 * V_61 , int V_62 )
{
struct V_29 * V_30 =
& F_34 ( V_6 ) -> V_31 -> V_30 ;
struct V_7 * V_8 = F_7 ( V_6 ) ;
struct V_2 * V_2 = F_52 ( V_61 -> V_63 , struct V_2 , V_64 ) ;
struct F_36 V_65 ;
struct V_41 * V_42 ;
T_2 V_66 ;
T_2 V_33 ;
int V_54 ;
struct V_2 * * V_58 ;
T_3 V_67 ;
int V_68 = 0 ;
int V_69 ;
V_66 = ( T_2 ) F_37 ( V_2 ) ;
V_67 = V_2 -> V_12 ;
F_53 (page, page_list, lru) {
if ( V_2 -> V_12 != V_67 )
break;
V_68 ++ ;
V_67 ++ ;
if ( V_62 && V_68 == V_62 )
break;
}
V_33 = V_68 << V_70 ;
F_6 ( L_12 , V_6 , V_68 ,
V_66 , V_33 ) ;
V_65 = F_36 ( V_6 ) ;
V_42 = F_54 ( V_30 , & V_8 -> V_35 , V_65 , V_66 , & V_33 ,
1 , V_71 ,
V_72 , NULL ,
V_8 -> V_36 , V_8 -> V_37 ,
false ) ;
if ( F_55 ( V_42 ) )
return F_56 ( V_42 ) ;
V_68 = F_46 ( 0 , V_33 ) ;
V_58 = F_57 ( sizeof( * V_58 ) * V_68 , V_73 ) ;
V_69 = - V_74 ;
if ( ! V_58 )
goto V_39;
for ( V_54 = 0 ; V_54 < V_68 ; ++ V_54 ) {
V_2 = F_52 ( V_61 -> V_63 , struct V_2 , V_64 ) ;
F_22 ( F_25 ( V_2 ) ) ;
F_58 ( & V_2 -> V_64 ) ;
F_6 ( L_13 , V_6 , V_2 ,
V_2 -> V_12 ) ;
if ( F_59 ( V_2 , & V_6 -> V_75 , V_2 -> V_12 ,
V_73 ) ) {
F_48 ( V_2 ) ;
F_6 ( L_14 ,
V_6 , V_2 ) ;
V_68 = V_54 ;
goto V_76;
}
V_58 [ V_54 ] = V_2 ;
}
F_60 ( V_42 , 0 , V_58 , V_33 , 0 , false , false ) ;
V_42 -> V_77 = F_43 ;
V_42 -> V_45 = V_6 ;
F_61 ( V_42 , V_66 , NULL , V_65 . V_78 , NULL ) ;
F_6 ( L_15 , V_6 , V_42 , V_66 , V_33 ) ;
V_69 = F_62 ( V_30 , V_42 , false ) ;
if ( V_69 < 0 )
goto V_76;
F_63 ( V_42 ) ;
return V_68 ;
V_76:
F_50 ( V_58 , V_68 ) ;
F_64 ( V_58 , V_68 ) ;
V_39:
F_63 ( V_42 ) ;
return V_69 ;
}
static int F_65 ( struct V_27 * V_27 , struct V_4 * V_5 ,
struct V_60 * V_61 , unsigned V_68 )
{
struct V_6 * V_6 = F_33 ( V_27 ) ;
struct V_79 * V_80 = F_34 ( V_6 ) ;
int V_48 = 0 ;
int V_62 = 0 ;
if ( V_80 -> V_81 -> V_82 >= V_34 )
V_62 = ( V_80 -> V_81 -> V_82 + V_34 - 1 )
>> V_83 ;
F_6 ( L_16 , V_6 ,
V_27 , V_68 ,
V_62 ) ;
while ( ! F_66 ( V_61 ) ) {
V_48 = F_51 ( V_6 , V_61 , V_62 ) ;
if ( V_48 < 0 )
goto V_39;
F_22 ( V_48 == 0 ) ;
}
V_39:
F_6 ( L_17 , V_6 , V_27 , V_48 ) ;
return V_48 ;
}
static struct V_1 * F_67 ( struct V_6 * V_6 ,
T_2 * V_84 )
{
struct V_7 * V_8 = F_7 ( V_6 ) ;
struct V_1 * V_10 = NULL ;
struct V_85 * V_86 = NULL ;
F_9 ( & V_8 -> V_15 ) ;
F_68 (capsnap, &ci->i_cap_snaps, ci_item) {
F_6 ( L_18 , V_86 ,
V_86 -> V_87 , V_86 -> V_88 ) ;
if ( V_86 -> V_88 ) {
V_10 = F_8 ( V_86 -> V_87 ) ;
if ( V_84 )
* V_84 = V_86 -> V_89 ;
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
static int F_69 ( struct V_2 * V_2 , struct V_90 * V_91 )
{
struct V_6 * V_6 ;
struct V_7 * V_8 ;
struct V_79 * V_80 ;
struct V_29 * V_30 ;
T_4 V_92 = F_37 ( V_2 ) ;
int V_33 = V_34 ;
T_4 V_93 ;
int V_32 = 0 ;
struct V_1 * V_10 , * V_94 ;
T_2 V_84 = 0 ;
long V_95 ;
F_6 ( L_20 , V_2 , V_2 -> V_12 ) ;
if ( ! V_2 -> V_5 || ! V_2 -> V_5 -> V_11 ) {
F_6 ( L_21 , V_2 ) ;
return - V_96 ;
}
V_6 = V_2 -> V_5 -> V_11 ;
V_8 = F_7 ( V_6 ) ;
V_80 = F_34 ( V_6 ) ;
V_30 = & V_80 -> V_31 -> V_30 ;
V_10 = F_1 ( V_2 ) ;
if ( V_10 == NULL ) {
F_6 ( L_22 , V_6 , V_2 ) ;
goto V_39;
}
V_94 = F_67 ( V_6 , & V_84 ) ;
if ( V_10 -> V_19 > V_94 -> V_19 ) {
F_6 ( L_23 ,
V_6 , V_2 , V_10 ) ;
F_31 ( ( V_97 -> V_98 & V_99 ) == 0 ) ;
F_28 ( V_94 ) ;
goto V_39;
}
F_28 ( V_94 ) ;
if ( V_84 )
V_93 = V_84 ;
else
V_93 = F_70 ( V_6 ) ;
if ( V_93 < V_92 + V_33 )
V_33 = V_93 - V_92 ;
F_6 ( L_24 ,
V_6 , V_2 , V_2 -> V_12 , V_92 , V_33 , V_10 ) ;
V_95 = F_71 ( & V_80 -> V_100 ) ;
if ( V_95 >
F_72 ( V_80 -> V_81 -> V_101 ) )
F_73 ( & V_80 -> V_102 , V_103 ) ;
F_74 ( V_2 ) ;
V_32 = F_75 ( V_30 , F_36 ( V_6 ) ,
& V_8 -> V_35 , V_10 ,
V_92 , V_33 ,
V_8 -> V_36 , V_8 -> V_37 ,
& V_6 -> V_104 , & V_2 , 1 ) ;
if ( V_32 < 0 ) {
F_6 ( L_25 , V_32 , V_2 ) ;
F_38 ( V_2 ) ;
F_76 ( & V_6 -> V_75 , V_32 ) ;
if ( V_91 )
V_91 -> V_105 ++ ;
} else {
F_6 ( L_26 , V_2 ) ;
V_32 = 0 ;
}
V_2 -> V_3 = 0 ;
F_29 ( V_2 ) ;
F_77 ( V_2 ) ;
F_20 ( V_8 , 1 , V_10 ) ;
F_28 ( V_10 ) ;
V_39:
return V_32 ;
}
static int F_78 ( struct V_2 * V_2 , struct V_90 * V_91 )
{
int V_32 ;
struct V_6 * V_6 = V_2 -> V_5 -> V_11 ;
F_22 ( ! V_6 ) ;
F_10 ( V_6 ) ;
V_32 = F_69 ( V_2 , V_91 ) ;
F_42 ( V_2 ) ;
F_79 ( V_6 ) ;
return V_32 ;
}
static void F_80 ( struct V_2 * * V_58 , int V_106 )
{
struct V_107 V_108 ;
int V_54 ;
F_81 ( & V_108 , 0 ) ;
for ( V_54 = 0 ; V_54 < V_106 ; V_54 ++ ) {
if ( F_82 ( & V_108 , V_58 [ V_54 ] ) == 0 )
F_83 ( & V_108 ) ;
}
F_83 ( & V_108 ) ;
}
static void F_84 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_6 * V_6 = V_42 -> V_45 ;
struct V_7 * V_8 = F_7 ( V_6 ) ;
struct V_46 * V_47 ;
unsigned V_109 ;
struct V_2 * V_2 ;
int V_53 ;
int V_54 ;
struct V_1 * V_10 = V_42 -> V_110 ;
struct V_4 * V_5 = V_6 -> V_111 ;
int V_48 = V_42 -> V_49 ;
T_2 V_50 = V_42 -> V_112 [ 0 ] . V_113 . V_57 ;
struct V_79 * V_80 = F_34 ( V_6 ) ;
long V_95 ;
unsigned V_114 = F_85 ( V_8 ) ;
V_47 = F_45 ( V_42 , 0 ) ;
F_22 ( V_47 -> type != V_55 ) ;
V_53 = F_46 ( ( T_2 ) V_47 -> V_56 ,
( T_2 ) V_47 -> V_57 ) ;
if ( V_48 >= 0 ) {
V_109 = V_53 ;
} else {
V_109 = 0 ;
F_76 ( V_5 , V_48 ) ;
}
F_6 ( L_27 ,
V_6 , V_48 , V_50 , V_109 ) ;
for ( V_54 = 0 ; V_54 < V_53 ; V_54 ++ ) {
V_2 = V_47 -> V_58 [ V_54 ] ;
F_22 ( ! V_2 ) ;
F_31 ( ! F_14 ( V_2 ) ) ;
V_95 =
F_86 ( & V_80 -> V_100 ) ;
if ( V_95 <
F_87 ( V_80 -> V_81 -> V_101 ) )
F_88 ( & V_80 -> V_102 ,
V_103 ) ;
F_28 ( F_1 ( V_2 ) ) ;
V_2 -> V_3 = 0 ;
F_29 ( V_2 ) ;
F_6 ( L_28 , V_54 , V_2 ) ;
F_77 ( V_2 ) ;
if ( ( V_114 & ( V_115 | V_116 ) ) == 0 )
F_89 ( V_6 -> V_111 , V_2 ) ;
F_42 ( V_2 ) ;
}
F_6 ( L_29 , V_6 , V_109 ) ;
F_20 ( V_8 , V_53 , V_10 ) ;
F_80 ( V_47 -> V_58 , V_53 ) ;
if ( V_47 -> V_117 )
F_90 ( V_47 -> V_58 ,
F_91 ( V_6 -> V_118 ) -> V_119 ) ;
else
F_49 ( V_47 -> V_58 ) ;
F_63 ( V_42 ) ;
}
static struct V_41 *
F_92 ( struct V_6 * V_6 , T_2 V_25 , T_2 * V_33 ,
struct V_1 * V_10 , int V_120 )
{
struct V_79 * V_80 ;
struct V_7 * V_8 ;
struct F_36 V_65 ;
V_80 = F_34 ( V_6 ) ;
V_8 = F_7 ( V_6 ) ;
V_65 = F_36 ( V_6 ) ;
return F_54 ( & V_80 -> V_31 -> V_30 , & V_8 -> V_35 ,
V_65 , V_25 , V_33 , V_120 , V_121 ,
V_122 | V_123 ,
V_10 , V_8 -> V_36 , V_8 -> V_37 , true ) ;
}
static int F_93 ( struct V_4 * V_5 ,
struct V_90 * V_91 )
{
struct V_6 * V_6 = V_5 -> V_11 ;
struct V_7 * V_8 = F_7 ( V_6 ) ;
struct V_79 * V_80 ;
T_3 V_12 , V_124 , V_125 ;
int V_126 = 0 ;
int V_127 = 1 ;
T_3 V_128 = 0 , V_129 = 0 ;
struct V_1 * V_10 = NULL , * V_130 = NULL , * V_131 ;
struct V_107 V_108 ;
int V_132 = 0 ;
int V_48 = 0 ;
unsigned V_133 = 1 << V_6 -> V_134 ;
struct V_41 * V_42 = NULL ;
int V_135 ;
T_2 V_84 ;
V_135 = V_91 -> V_136 == V_137 ;
if ( F_94 ( V_8 , V_138 ) )
V_135 = 1 ;
F_6 ( L_30 ,
V_6 , V_135 ,
V_91 -> V_136 == V_139 ? L_31 :
( V_91 -> V_136 == V_137 ? L_32 : L_33 ) ) ;
V_80 = F_34 ( V_6 ) ;
if ( V_80 -> V_140 == V_141 ) {
F_95 ( L_34 , V_6 ) ;
return - V_142 ;
}
if ( V_80 -> V_81 -> V_133 && V_80 -> V_81 -> V_133 < V_133 )
V_133 = V_80 -> V_81 -> V_133 ;
if ( V_133 < V_34 )
V_133 = V_34 ;
V_129 = V_133 >> V_70 ;
F_81 ( & V_108 , 0 ) ;
if ( V_91 -> V_143 ) {
V_124 = V_5 -> V_144 ;
V_125 = - 1 ;
F_6 ( L_35 , V_124 ) ;
} else {
V_124 = V_91 -> V_145 >> V_70 ;
V_125 = V_91 -> V_146 >> V_70 ;
if ( V_91 -> V_145 == 0 && V_91 -> V_146 == V_147 )
V_126 = 1 ;
V_127 = 0 ;
F_6 ( L_36 , V_124 , V_125 ) ;
}
V_12 = V_124 ;
V_148:
F_28 ( V_10 ) ;
V_84 = 0 ;
V_10 = F_67 ( V_6 , & V_84 ) ;
if ( ! V_10 ) {
F_6 ( L_37 ) ;
goto V_39;
}
if ( V_84 == 0 )
V_84 = F_70 ( V_6 ) ;
F_6 ( L_38 ,
V_10 , V_10 -> V_19 , V_10 -> V_20 ) ;
if ( V_130 && V_10 != V_130 ) {
F_6 ( L_39 ,
V_12 ) ;
V_12 = V_124 ;
}
V_130 = V_10 ;
while ( ! V_132 && V_12 <= V_125 ) {
int V_120 = V_135 ? 2 : 1 ;
struct F_36 V_65 ;
unsigned V_54 ;
int V_149 ;
T_3 V_150 ;
int V_151 , V_152 ;
struct V_2 * * V_58 = NULL ;
T_5 * V_153 = NULL ;
struct V_2 * V_2 ;
int V_154 ;
T_2 V_25 , V_33 ;
long V_95 ;
V_150 = 0 ;
V_152 = 0 ;
V_128 = V_129 ;
V_155:
V_149 = - 1 ;
V_154 = F_96 ( V_125 - V_12 ,
F_96 ( ( T_3 ) V_156 ,
V_128 - ( T_3 ) V_152 ) - 1 )
+ 1 ;
V_151 = F_97 ( & V_108 , V_5 , & V_12 ,
V_23 ,
V_154 ) ;
F_6 ( L_40 , V_151 ) ;
if ( ! V_151 && ! V_152 )
break;
for ( V_54 = 0 ; V_54 < V_151 && V_152 < V_128 ; V_54 ++ ) {
V_2 = V_108 . V_58 [ V_54 ] ;
F_6 ( L_41 , V_2 , V_2 -> V_12 ) ;
if ( V_152 == 0 )
F_98 ( V_2 ) ;
else if ( ! F_99 ( V_2 ) )
break;
if ( F_4 ( ! F_23 ( V_2 ) ) ||
F_4 ( V_2 -> V_5 != V_5 ) ) {
F_6 ( L_42 , V_2 ) ;
F_42 ( V_2 ) ;
break;
}
if ( ! V_91 -> V_143 && V_2 -> V_12 > V_125 ) {
F_6 ( L_43 , V_2 ) ;
V_132 = 1 ;
F_42 ( V_2 ) ;
break;
}
if ( V_150 && ( V_2 -> V_12 != V_150 ) ) {
F_6 ( L_44 , V_2 ) ;
F_42 ( V_2 ) ;
break;
}
if ( V_91 -> V_136 != V_139 ) {
F_6 ( L_45 , V_2 ) ;
F_100 ( V_2 ) ;
}
if ( F_37 ( V_2 ) >= V_84 ) {
F_6 ( L_46 , V_2 , V_84 ) ;
V_132 = 1 ;
F_42 ( V_2 ) ;
break;
}
if ( F_101 ( V_2 ) ) {
F_6 ( L_47 , V_2 ) ;
F_42 ( V_2 ) ;
break;
}
V_131 = F_1 ( V_2 ) ;
if ( V_131 -> V_19 > V_10 -> V_19 ) {
F_6 ( L_48 ,
V_131 , V_131 -> V_19 , V_10 , V_10 -> V_19 ) ;
F_42 ( V_2 ) ;
if ( ! V_152 )
continue;
break;
}
if ( ! F_102 ( V_2 ) ) {
F_6 ( L_49 , V_2 ) ;
F_42 ( V_2 ) ;
break;
}
if ( V_152 == 0 ) {
T_6 V_89 ;
F_22 ( V_58 ) ;
V_25 = ( T_2 ) F_37 ( V_2 ) ;
V_33 = V_133 ;
V_42 = F_92 ( V_6 ,
V_25 , & V_33 , V_10 ,
V_120 ) ;
if ( F_55 ( V_42 ) ) {
V_48 = F_56 ( V_42 ) ;
F_42 ( V_2 ) ;
break;
}
V_42 -> V_77 = F_84 ;
V_42 -> V_45 = V_6 ;
V_128 = F_46 ( 0 , ( T_2 ) V_33 ) ;
V_89 = V_128 * sizeof ( * V_58 ) ;
V_58 = F_57 ( V_89 , V_73 ) ;
if ( ! V_58 ) {
V_153 = V_80 -> V_119 ;
V_58 = F_103 ( V_153 , V_73 ) ;
F_22 ( ! V_58 ) ;
}
}
if ( V_149 < 0 )
V_149 = V_54 ;
F_6 ( L_50 ,
V_6 , V_2 , V_2 -> V_12 ) ;
V_95 =
F_71 ( & V_80 -> V_100 ) ;
if ( V_95 > F_72 (
V_80 -> V_81 -> V_101 ) ) {
F_73 ( & V_80 -> V_102 ,
V_103 ) ;
}
F_74 ( V_2 ) ;
V_58 [ V_152 ] = V_2 ;
V_152 ++ ;
V_150 = V_2 -> V_12 + 1 ;
}
if ( ! V_152 )
goto V_157;
if ( V_54 ) {
int V_158 ;
F_22 ( ! V_152 || V_149 < 0 ) ;
if ( V_151 && V_54 == V_151 &&
V_152 < V_128 ) {
F_6 ( L_51 ) ;
F_104 ( & V_108 ) ;
goto V_155;
}
for ( V_158 = V_54 ; V_158 < V_151 ; V_158 ++ ) {
F_6 ( L_52 ,
V_108 . V_58 [ V_158 ] ) ;
V_108 . V_58 [ V_158 - V_54 + V_149 ] = V_108 . V_58 [ V_158 ] ;
}
V_108 . V_159 -= V_54 - V_149 ;
}
V_25 = F_37 ( V_58 [ 0 ] ) ;
V_33 = F_96 ( V_84 - V_25 ,
( T_2 ) V_152 << V_70 ) ;
F_6 ( L_53 ,
V_152 , V_25 , V_33 ) ;
F_60 ( V_42 , 0 , V_58 , V_33 , 0 ,
! ! V_153 , false ) ;
V_58 = NULL ;
V_153 = NULL ;
F_105 ( V_42 , 0 , V_33 ) ;
V_65 = F_36 ( V_6 ) ;
F_61 ( V_42 , V_25 , V_10 , V_65 . V_78 ,
& V_6 -> V_104 ) ;
V_48 = F_62 ( & V_80 -> V_31 -> V_30 , V_42 , true ) ;
F_22 ( V_48 ) ;
V_42 = NULL ;
V_12 = V_150 ;
V_91 -> V_160 -= V_152 ;
if ( V_91 -> V_160 <= 0 )
V_132 = 1 ;
V_157:
F_6 ( L_54 , ( int ) V_108 . V_159 ,
V_108 . V_159 ? V_108 . V_58 [ 0 ] : NULL ) ;
F_83 ( & V_108 ) ;
if ( V_152 && ! V_132 )
goto V_148;
}
if ( V_127 && ! V_132 ) {
F_6 ( L_55 ) ;
V_127 = 0 ;
V_12 = 0 ;
goto V_148;
}
if ( V_91 -> V_143 || ( V_126 && V_91 -> V_160 > 0 ) )
V_5 -> V_144 = V_12 ;
V_39:
if ( V_42 )
F_63 ( V_42 ) ;
F_28 ( V_10 ) ;
F_6 ( L_56 , V_48 ) ;
return V_48 ;
}
static int F_106 ( struct V_6 * V_6 ,
struct V_1 * V_10 )
{
struct V_1 * V_94 = F_67 ( V_6 , NULL ) ;
int V_69 = ! V_94 || V_10 -> V_19 <= V_94 -> V_19 ;
F_28 ( V_94 ) ;
return V_69 ;
}
static int F_107 ( struct V_27 * V_27 ,
T_4 V_161 , unsigned V_33 ,
struct V_2 * V_2 )
{
struct V_6 * V_6 = F_33 ( V_27 ) ;
struct V_7 * V_8 = F_7 ( V_6 ) ;
struct V_162 * V_163 = F_34 ( V_6 ) -> V_163 ;
T_4 V_92 = V_161 & V_164 ;
int V_165 = V_161 & ~ V_164 ;
int V_166 = V_165 + V_33 ;
T_4 V_93 ;
int V_40 ;
struct V_1 * V_10 , * V_94 ;
V_167:
F_100 ( V_2 ) ;
F_22 ( ! V_8 -> V_13 ) ;
F_108 ( & V_163 -> V_168 ) ;
F_22 ( ! V_8 -> V_13 -> V_14 ) ;
V_10 = F_1 ( V_2 ) ;
if ( V_10 && V_10 != V_8 -> V_16 ) {
V_94 = F_67 ( V_6 , NULL ) ;
F_109 ( & V_163 -> V_168 ) ;
if ( V_10 -> V_19 > V_94 -> V_19 ) {
F_28 ( V_94 ) ;
F_6 ( L_57 ,
V_2 , V_10 ) ;
V_10 = F_8 ( V_10 ) ;
F_42 ( V_2 ) ;
F_110 ( V_6 ) ;
V_40 = F_111 ( V_8 -> V_169 ,
F_106 ( V_6 , V_10 ) ) ;
F_28 ( V_10 ) ;
if ( V_40 == - V_170 )
return V_40 ;
return - V_171 ;
}
F_28 ( V_94 ) ;
F_6 ( L_58 ,
V_2 , V_10 ) ;
if ( ! F_102 ( V_2 ) )
goto V_167;
V_40 = F_69 ( V_2 , NULL ) ;
if ( V_40 < 0 )
goto V_172;
goto V_167;
}
if ( F_14 ( V_2 ) ) {
F_6 ( L_59 , V_2 ) ;
return 0 ;
}
if ( V_165 == 0 && V_33 == V_34 )
return 0 ;
V_93 = V_6 -> V_93 ;
if ( V_93 + V_33 > V_6 -> V_118 -> V_173 ) {
V_40 = - V_174 ;
goto V_175;
}
if ( V_92 >= V_93 ||
( V_165 == 0 && ( V_161 + V_33 ) >= V_93 &&
V_166 - V_165 != V_34 ) ) {
F_6 ( L_60 ,
V_2 , V_165 , V_166 , ( int ) V_34 ) ;
F_112 ( V_2 ,
0 , V_165 ,
V_166 , V_34 ) ;
return 0 ;
}
F_109 ( & V_163 -> V_168 ) ;
V_40 = F_32 ( V_27 , V_2 ) ;
if ( V_40 < 0 )
goto V_172;
goto V_167;
V_175:
F_109 ( & V_163 -> V_168 ) ;
V_172:
F_42 ( V_2 ) ;
return V_40 ;
}
static int F_113 ( struct V_27 * V_27 , struct V_4 * V_5 ,
T_4 V_161 , unsigned V_33 , unsigned V_98 ,
struct V_2 * * V_176 , void * * V_177 )
{
struct V_6 * V_6 = F_33 ( V_27 ) ;
struct V_2 * V_2 ;
T_3 V_12 = V_161 >> V_70 ;
int V_40 ;
do {
V_2 = F_114 ( V_5 , V_12 , 0 ) ;
if ( ! V_2 )
return - V_74 ;
* V_176 = V_2 ;
F_6 ( L_61 , V_27 ,
V_6 , V_2 , ( int ) V_161 , ( int ) V_33 ) ;
V_40 = F_107 ( V_27 , V_161 , V_33 , V_2 ) ;
} while ( V_40 == - V_171 );
return V_40 ;
}
static int F_115 ( struct V_27 * V_27 , struct V_4 * V_5 ,
T_4 V_161 , unsigned V_33 , unsigned V_178 ,
struct V_2 * V_2 , void * V_177 )
{
struct V_6 * V_6 = F_33 ( V_27 ) ;
struct V_79 * V_80 = F_34 ( V_6 ) ;
struct V_162 * V_163 = V_80 -> V_163 ;
unsigned V_179 = V_161 & ( V_34 - 1 ) ;
int V_180 = 0 ;
F_6 ( L_62 , V_27 ,
V_6 , V_2 , ( int ) V_161 , ( int ) V_178 , ( int ) V_33 ) ;
if ( V_178 < V_33 )
F_39 ( V_2 , V_179 + V_178 , V_33 ) ;
if ( V_161 + V_178 > V_6 -> V_93 )
V_180 = F_116 ( V_6 , V_161 + V_178 ) ;
if ( ! F_14 ( V_2 ) )
F_40 ( V_2 ) ;
F_117 ( V_2 ) ;
F_42 ( V_2 ) ;
F_109 ( & V_163 -> V_168 ) ;
F_48 ( V_2 ) ;
if ( V_180 )
F_118 ( F_7 ( V_6 ) , V_181 , NULL ) ;
return V_178 ;
}
static T_7 F_119 ( int V_182 , struct V_183 * V_184 ,
const struct V_185 * V_186 ,
T_4 V_161 , unsigned long V_187 )
{
F_31 ( 1 ) ;
return - V_174 ;
}
static int F_120 ( struct V_188 * V_189 , struct V_190 * V_191 )
{
struct V_6 * V_6 = F_33 ( V_189 -> V_192 ) ;
struct V_2 * V_2 = V_191 -> V_2 ;
struct V_162 * V_163 = F_34 ( V_6 ) -> V_163 ;
T_4 V_66 = F_37 ( V_2 ) ;
T_4 V_89 , V_33 ;
int V_69 ;
F_121 ( V_189 -> V_192 ) ;
V_89 = F_70 ( V_6 ) ;
if ( V_66 + V_34 <= V_89 )
V_33 = V_34 ;
else
V_33 = V_89 & ~ V_164 ;
F_6 ( L_63 , V_6 ,
V_66 , V_33 , V_2 , V_2 -> V_12 ) ;
F_98 ( V_2 ) ;
V_69 = V_193 ;
if ( ( V_66 > V_89 ) ||
( V_2 -> V_5 != V_6 -> V_111 ) )
goto V_39;
V_69 = F_107 ( V_189 -> V_192 , V_66 , V_33 , V_2 ) ;
if ( V_69 == 0 ) {
F_117 ( V_2 ) ;
F_109 ( & V_163 -> V_168 ) ;
V_69 = V_194 ;
} else {
if ( V_69 == - V_74 )
V_69 = V_195 ;
else
V_69 = V_196 ;
}
V_39:
F_6 ( L_64 , V_6 , V_66 , V_33 , V_69 ) ;
if ( V_69 != V_194 )
F_42 ( V_2 ) ;
return V_69 ;
}
int F_122 ( struct V_27 * V_27 , struct V_188 * V_189 )
{
struct V_4 * V_5 = V_27 -> V_197 ;
if ( ! V_5 -> V_198 -> V_199 )
return - V_200 ;
F_123 ( V_27 ) ;
V_189 -> V_201 = & V_202 ;
return 0 ;
}
