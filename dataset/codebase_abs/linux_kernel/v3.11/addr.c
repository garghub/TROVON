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
static void F_24 ( struct V_2 * V_2 , unsigned int V_25 ,
unsigned int V_26 )
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
if ( V_25 == 0 && V_26 == V_27 )
F_27 ( V_2 ) ;
V_8 = F_7 ( V_6 ) ;
if ( V_25 == 0 && V_26 == V_27 ) {
F_6 ( L_6 ,
V_6 , V_2 , V_2 -> V_12 ) ;
F_20 ( V_8 , 1 , V_10 ) ;
F_28 ( V_10 ) ;
V_2 -> V_3 = 0 ;
F_29 ( V_2 ) ;
} else {
F_6 ( L_7 ,
V_6 , V_2 , V_2 -> V_12 , V_25 , V_26 ) ;
}
}
static int F_30 ( struct V_2 * V_2 , T_1 V_28 )
{
struct V_6 * V_6 = V_2 -> V_5 ? V_2 -> V_5 -> V_11 : NULL ;
F_6 ( L_8 , V_6 , V_2 , V_2 -> V_12 ) ;
F_31 ( F_23 ( V_2 ) ) ;
F_31 ( F_2 ( V_2 ) ) ;
return 0 ;
}
static int F_32 ( struct V_29 * V_30 , struct V_2 * V_2 )
{
struct V_6 * V_6 = F_33 ( V_30 ) ;
struct V_7 * V_8 = F_7 ( V_6 ) ;
struct V_31 * V_32 =
& F_34 ( V_6 ) -> V_33 -> V_32 ;
int V_34 = 0 ;
T_2 V_35 = V_27 ;
F_6 ( L_9 ,
V_6 , V_30 , V_2 , V_2 -> V_12 ) ;
V_34 = F_35 ( V_32 , F_36 ( V_6 ) , & V_8 -> V_36 ,
( T_2 ) F_37 ( V_2 ) , & V_35 ,
V_8 -> V_37 , V_8 -> V_38 ,
& V_2 , 1 , 0 ) ;
if ( V_34 == - V_39 )
V_34 = 0 ;
if ( V_34 < 0 ) {
F_38 ( V_2 ) ;
goto V_40;
} else if ( V_34 < V_27 ) {
F_39 ( V_2 , V_34 , V_27 ) ;
}
F_40 ( V_2 ) ;
V_40:
return V_34 < 0 ? V_34 : 0 ;
}
static int F_41 ( struct V_29 * V_30 , struct V_2 * V_2 )
{
int V_41 = F_32 ( V_30 , V_2 ) ;
F_42 ( V_2 ) ;
return V_41 ;
}
static void F_43 ( struct V_42 * V_43 , struct V_44 * V_45 )
{
struct V_6 * V_6 = V_43 -> V_46 ;
struct V_47 * V_48 ;
int V_49 = V_43 -> V_50 ;
int V_51 = F_44 ( V_45 -> V_52 . V_53 ) ;
int V_54 ;
int V_55 ;
F_6 ( L_10 , V_6 , V_43 , V_49 , V_51 ) ;
V_48 = F_45 ( V_43 , 0 ) ;
F_22 ( V_48 -> type != V_56 ) ;
V_54 = F_46 ( ( T_2 ) V_48 -> V_57 ,
( T_2 ) V_48 -> V_26 ) ;
for ( V_55 = 0 ; V_55 < V_54 ; V_55 ++ ) {
struct V_2 * V_2 = V_48 -> V_58 [ V_55 ] ;
if ( V_51 < ( int ) V_27 ) {
int V_59 = V_51 < 0 ? 0 : V_51 ;
F_39 ( V_2 , V_59 , V_27 ) ;
}
F_6 ( L_11 , V_6 , V_2 ,
V_2 -> V_12 ) ;
F_47 ( V_2 ) ;
F_40 ( V_2 ) ;
F_42 ( V_2 ) ;
F_48 ( V_2 ) ;
V_51 -= V_27 ;
}
F_49 ( V_48 -> V_58 ) ;
}
static void F_50 ( struct V_2 * * V_58 , int V_54 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_54 ; V_55 ++ )
F_42 ( V_58 [ V_55 ] ) ;
}
static int F_51 ( struct V_6 * V_6 , struct V_60 * V_61 , int V_62 )
{
struct V_31 * V_32 =
& F_34 ( V_6 ) -> V_33 -> V_32 ;
struct V_7 * V_8 = F_7 ( V_6 ) ;
struct V_2 * V_2 = F_52 ( V_61 -> V_63 , struct V_2 , V_64 ) ;
struct F_36 V_65 ;
struct V_42 * V_43 ;
T_2 V_66 ;
T_2 V_35 ;
int V_55 ;
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
V_35 = V_68 << V_70 ;
F_6 ( L_12 , V_6 , V_68 ,
V_66 , V_35 ) ;
V_65 = F_36 ( V_6 ) ;
V_43 = F_54 ( V_32 , & V_8 -> V_36 , V_65 , V_66 , & V_35 ,
1 , V_71 ,
V_72 , NULL ,
V_8 -> V_37 , V_8 -> V_38 ,
false ) ;
if ( F_55 ( V_43 ) )
return F_56 ( V_43 ) ;
V_68 = F_46 ( 0 , V_35 ) ;
V_58 = F_57 ( sizeof( * V_58 ) * V_68 , V_73 ) ;
V_69 = - V_74 ;
if ( ! V_58 )
goto V_40;
for ( V_55 = 0 ; V_55 < V_68 ; ++ V_55 ) {
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
V_68 = V_55 ;
goto V_76;
}
V_58 [ V_55 ] = V_2 ;
}
F_60 ( V_43 , 0 , V_58 , V_35 , 0 , false , false ) ;
V_43 -> V_77 = F_43 ;
V_43 -> V_46 = V_6 ;
F_61 ( V_43 , V_66 , NULL , V_65 . V_78 , NULL ) ;
F_6 ( L_15 , V_6 , V_43 , V_66 , V_35 ) ;
V_69 = F_62 ( V_32 , V_43 , false ) ;
if ( V_69 < 0 )
goto V_76;
F_63 ( V_43 ) ;
return V_68 ;
V_76:
F_50 ( V_58 , V_68 ) ;
F_64 ( V_58 , V_68 ) ;
V_40:
F_63 ( V_43 ) ;
return V_69 ;
}
static int F_65 ( struct V_29 * V_29 , struct V_4 * V_5 ,
struct V_60 * V_61 , unsigned V_68 )
{
struct V_6 * V_6 = F_33 ( V_29 ) ;
struct V_79 * V_80 = F_34 ( V_6 ) ;
int V_49 = 0 ;
int V_62 = 0 ;
if ( V_80 -> V_81 -> V_82 >= V_27 )
V_62 = ( V_80 -> V_81 -> V_82 + V_27 - 1 )
>> V_83 ;
F_6 ( L_16 , V_6 ,
V_29 , V_68 ,
V_62 ) ;
while ( ! F_66 ( V_61 ) ) {
V_49 = F_51 ( V_6 , V_61 , V_62 ) ;
if ( V_49 < 0 )
goto V_40;
F_22 ( V_49 == 0 ) ;
}
V_40:
F_6 ( L_17 , V_6 , V_29 , V_49 ) ;
return V_49 ;
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
struct V_31 * V_32 ;
struct V_1 * V_10 , * V_92 ;
T_4 V_93 = F_37 ( V_2 ) ;
long V_94 ;
T_2 V_95 , V_84 = 0 ;
T_5 V_96 ;
int V_34 = 0 , V_35 = V_27 ;
F_6 ( L_20 , V_2 , V_2 -> V_12 ) ;
if ( ! V_2 -> V_5 || ! V_2 -> V_5 -> V_11 ) {
F_6 ( L_21 , V_2 ) ;
return - V_97 ;
}
V_6 = V_2 -> V_5 -> V_11 ;
V_8 = F_7 ( V_6 ) ;
V_80 = F_34 ( V_6 ) ;
V_32 = & V_80 -> V_33 -> V_32 ;
V_10 = F_1 ( V_2 ) ;
if ( V_10 == NULL ) {
F_6 ( L_22 , V_6 , V_2 ) ;
goto V_40;
}
V_92 = F_67 ( V_6 , & V_84 ) ;
if ( V_10 -> V_19 > V_92 -> V_19 ) {
F_6 ( L_23 ,
V_6 , V_2 , V_10 ) ;
F_31 ( ( V_98 -> V_99 & V_100 ) == 0 ) ;
F_28 ( V_92 ) ;
goto V_40;
}
F_28 ( V_92 ) ;
F_9 ( & V_8 -> V_15 ) ;
V_96 = V_8 -> V_37 ;
V_95 = V_8 -> V_38 ;
if ( ! V_84 )
V_84 = F_70 ( V_6 ) ;
F_11 ( & V_8 -> V_15 ) ;
if ( V_93 >= V_84 ) {
F_6 ( L_24 , V_2 , V_84 ) ;
goto V_40;
}
if ( V_84 < V_93 + V_35 )
V_35 = V_84 - V_93 ;
F_6 ( L_25 ,
V_6 , V_2 , V_2 -> V_12 , V_93 , V_35 , V_10 ) ;
V_94 = F_71 ( & V_80 -> V_101 ) ;
if ( V_94 >
F_72 ( V_80 -> V_81 -> V_102 ) )
F_73 ( & V_80 -> V_103 , V_104 ) ;
F_74 ( V_2 ) ;
V_34 = F_75 ( V_32 , F_36 ( V_6 ) ,
& V_8 -> V_36 , V_10 ,
V_93 , V_35 ,
V_96 , V_95 ,
& V_6 -> V_105 , & V_2 , 1 ) ;
if ( V_34 < 0 ) {
F_6 ( L_26 , V_34 , V_2 ) ;
F_38 ( V_2 ) ;
F_76 ( & V_6 -> V_75 , V_34 ) ;
if ( V_91 )
V_91 -> V_106 ++ ;
} else {
F_6 ( L_27 , V_2 ) ;
V_34 = 0 ;
}
V_2 -> V_3 = 0 ;
F_29 ( V_2 ) ;
F_77 ( V_2 ) ;
F_20 ( V_8 , 1 , V_10 ) ;
F_28 ( V_10 ) ;
V_40:
return V_34 ;
}
static int F_78 ( struct V_2 * V_2 , struct V_90 * V_91 )
{
int V_34 ;
struct V_6 * V_6 = V_2 -> V_5 -> V_11 ;
F_22 ( ! V_6 ) ;
F_10 ( V_6 ) ;
V_34 = F_69 ( V_2 , V_91 ) ;
F_42 ( V_2 ) ;
F_79 ( V_6 ) ;
return V_34 ;
}
static void F_80 ( struct V_2 * * V_58 , int V_107 )
{
struct V_108 V_109 ;
int V_55 ;
F_81 ( & V_109 , 0 ) ;
for ( V_55 = 0 ; V_55 < V_107 ; V_55 ++ ) {
if ( F_82 ( & V_109 , V_58 [ V_55 ] ) == 0 )
F_83 ( & V_109 ) ;
}
F_83 ( & V_109 ) ;
}
static void F_84 ( struct V_42 * V_43 ,
struct V_44 * V_45 )
{
struct V_6 * V_6 = V_43 -> V_46 ;
struct V_7 * V_8 = F_7 ( V_6 ) ;
struct V_47 * V_48 ;
unsigned V_110 ;
struct V_2 * V_2 ;
int V_54 ;
int V_55 ;
struct V_1 * V_10 = V_43 -> V_111 ;
struct V_4 * V_5 = V_6 -> V_112 ;
int V_49 = V_43 -> V_50 ;
T_2 V_51 = V_43 -> V_113 [ 0 ] . V_114 . V_26 ;
struct V_79 * V_80 = F_34 ( V_6 ) ;
long V_94 ;
unsigned V_115 = F_85 ( V_8 ) ;
V_48 = F_45 ( V_43 , 0 ) ;
F_22 ( V_48 -> type != V_56 ) ;
V_54 = F_46 ( ( T_2 ) V_48 -> V_57 ,
( T_2 ) V_48 -> V_26 ) ;
if ( V_49 >= 0 ) {
V_110 = V_54 ;
} else {
V_110 = 0 ;
F_76 ( V_5 , V_49 ) ;
}
F_6 ( L_28 ,
V_6 , V_49 , V_51 , V_110 ) ;
for ( V_55 = 0 ; V_55 < V_54 ; V_55 ++ ) {
V_2 = V_48 -> V_58 [ V_55 ] ;
F_22 ( ! V_2 ) ;
F_31 ( ! F_14 ( V_2 ) ) ;
V_94 =
F_86 ( & V_80 -> V_101 ) ;
if ( V_94 <
F_87 ( V_80 -> V_81 -> V_102 ) )
F_88 ( & V_80 -> V_103 ,
V_104 ) ;
F_28 ( F_1 ( V_2 ) ) ;
V_2 -> V_3 = 0 ;
F_29 ( V_2 ) ;
F_6 ( L_29 , V_55 , V_2 ) ;
F_77 ( V_2 ) ;
if ( ( V_115 & ( V_116 | V_117 ) ) == 0 )
F_89 ( V_6 -> V_112 , V_2 ) ;
F_42 ( V_2 ) ;
}
F_6 ( L_30 , V_6 , V_110 ) ;
F_20 ( V_8 , V_54 , V_10 ) ;
F_80 ( V_48 -> V_58 , V_54 ) ;
if ( V_48 -> V_118 )
F_90 ( V_48 -> V_58 ,
F_91 ( V_6 -> V_119 ) -> V_120 ) ;
else
F_49 ( V_48 -> V_58 ) ;
F_63 ( V_43 ) ;
}
static int F_92 ( struct V_4 * V_5 ,
struct V_90 * V_91 )
{
struct V_6 * V_6 = V_5 -> V_11 ;
struct V_7 * V_8 = F_7 ( V_6 ) ;
struct V_79 * V_80 = F_34 ( V_6 ) ;
struct F_36 V_65 = F_36 ( V_6 ) ;
T_3 V_12 , V_121 , V_122 ;
int V_123 = 0 ;
int V_124 = 1 ;
T_3 V_125 = 0 , V_126 = 0 ;
struct V_1 * V_10 = NULL , * V_127 = NULL , * V_128 ;
struct V_108 V_109 ;
int V_129 = 0 ;
int V_49 = 0 ;
unsigned V_130 = 1 << V_6 -> V_131 ;
struct V_42 * V_43 = NULL ;
int V_132 ;
T_2 V_95 , V_84 ;
T_5 V_96 ;
if ( ( V_91 -> V_133 == V_134 ) ||
F_93 ( V_8 , V_135 ) )
V_132 = 1 ;
F_6 ( L_31 ,
V_6 , V_132 ,
V_91 -> V_133 == V_136 ? L_32 :
( V_91 -> V_133 == V_134 ? L_33 : L_34 ) ) ;
if ( V_80 -> V_137 == V_138 ) {
F_94 ( L_35 , V_6 ) ;
return - V_139 ;
}
if ( V_80 -> V_81 -> V_130 && V_80 -> V_81 -> V_130 < V_130 )
V_130 = V_80 -> V_81 -> V_130 ;
if ( V_130 < V_27 )
V_130 = V_27 ;
V_126 = V_130 >> V_70 ;
F_81 ( & V_109 , 0 ) ;
if ( V_91 -> V_140 ) {
V_121 = V_5 -> V_141 ;
V_122 = - 1 ;
F_6 ( L_36 , V_121 ) ;
} else {
V_121 = V_91 -> V_142 >> V_70 ;
V_122 = V_91 -> V_143 >> V_70 ;
if ( V_91 -> V_142 == 0 && V_91 -> V_143 == V_144 )
V_123 = 1 ;
V_124 = 0 ;
F_6 ( L_37 , V_121 , V_122 ) ;
}
V_12 = V_121 ;
V_145:
F_28 ( V_10 ) ;
V_84 = 0 ;
V_10 = F_67 ( V_6 , & V_84 ) ;
if ( ! V_10 ) {
F_6 ( L_38 ) ;
goto V_40;
}
if ( V_84 == 0 )
V_84 = F_70 ( V_6 ) ;
F_6 ( L_39 ,
V_10 , V_10 -> V_19 , V_10 -> V_20 ) ;
F_9 ( & V_8 -> V_15 ) ;
V_96 = V_8 -> V_37 ;
V_95 = V_8 -> V_38 ;
if ( ! V_84 )
V_84 = F_70 ( V_6 ) ;
F_11 ( & V_8 -> V_15 ) ;
if ( V_127 && V_10 != V_127 ) {
F_6 ( L_40 ,
V_12 ) ;
V_12 = V_121 ;
}
V_127 = V_10 ;
while ( ! V_129 && V_12 <= V_122 ) {
int V_146 = V_132 ? 2 : 1 ;
unsigned V_55 ;
int V_147 ;
T_3 V_148 ;
int V_149 , V_150 ;
struct V_2 * * V_58 = NULL ;
T_6 * V_151 = NULL ;
struct V_2 * V_2 ;
int V_152 ;
T_2 V_25 , V_35 ;
long V_94 ;
V_148 = 0 ;
V_150 = 0 ;
V_125 = V_126 ;
V_153:
V_147 = - 1 ;
V_152 = F_95 ( V_122 - V_12 ,
F_95 ( ( T_3 ) V_154 ,
V_125 - ( T_3 ) V_150 ) - 1 )
+ 1 ;
V_149 = F_96 ( & V_109 , V_5 , & V_12 ,
V_23 ,
V_152 ) ;
F_6 ( L_41 , V_149 ) ;
if ( ! V_149 && ! V_150 )
break;
for ( V_55 = 0 ; V_55 < V_149 && V_150 < V_125 ; V_55 ++ ) {
V_2 = V_109 . V_58 [ V_55 ] ;
F_6 ( L_42 , V_2 , V_2 -> V_12 ) ;
if ( V_150 == 0 )
F_97 ( V_2 ) ;
else if ( ! F_98 ( V_2 ) )
break;
if ( F_4 ( ! F_23 ( V_2 ) ) ||
F_4 ( V_2 -> V_5 != V_5 ) ) {
F_6 ( L_43 , V_2 ) ;
F_42 ( V_2 ) ;
break;
}
if ( ! V_91 -> V_140 && V_2 -> V_12 > V_122 ) {
F_6 ( L_44 , V_2 ) ;
V_129 = 1 ;
F_42 ( V_2 ) ;
break;
}
if ( V_148 && ( V_2 -> V_12 != V_148 ) ) {
F_6 ( L_45 , V_2 ) ;
F_42 ( V_2 ) ;
break;
}
if ( V_91 -> V_133 != V_136 ) {
F_6 ( L_46 , V_2 ) ;
F_99 ( V_2 ) ;
}
if ( F_37 ( V_2 ) >= V_84 ) {
F_6 ( L_24 , V_2 , V_84 ) ;
V_129 = 1 ;
F_42 ( V_2 ) ;
break;
}
if ( F_100 ( V_2 ) ) {
F_6 ( L_47 , V_2 ) ;
F_42 ( V_2 ) ;
break;
}
V_128 = F_1 ( V_2 ) ;
if ( V_128 -> V_19 > V_10 -> V_19 ) {
F_6 ( L_48 ,
V_128 , V_128 -> V_19 , V_10 , V_10 -> V_19 ) ;
F_42 ( V_2 ) ;
if ( ! V_150 )
continue;
break;
}
if ( ! F_101 ( V_2 ) ) {
F_6 ( L_49 , V_2 ) ;
F_42 ( V_2 ) ;
break;
}
if ( V_150 == 0 ) {
F_22 ( V_58 ) ;
V_25 = ( T_2 ) F_37 ( V_2 ) ;
V_35 = V_130 ;
V_43 = F_54 ( & V_80 -> V_33 -> V_32 ,
& V_8 -> V_36 , V_65 ,
V_25 , & V_35 , V_146 ,
V_155 ,
V_156 |
V_157 ,
V_10 , V_96 ,
V_95 , true ) ;
if ( F_55 ( V_43 ) ) {
V_49 = F_56 ( V_43 ) ;
F_42 ( V_2 ) ;
break;
}
V_43 -> V_77 = F_84 ;
V_43 -> V_46 = V_6 ;
V_125 = F_46 ( 0 , ( T_2 ) V_35 ) ;
V_58 = F_57 ( V_125 * sizeof ( * V_58 ) ,
V_73 ) ;
if ( ! V_58 ) {
V_151 = V_80 -> V_120 ;
V_58 = F_102 ( V_151 , V_73 ) ;
F_22 ( ! V_58 ) ;
}
}
if ( V_147 < 0 )
V_147 = V_55 ;
F_6 ( L_50 ,
V_6 , V_2 , V_2 -> V_12 ) ;
V_94 =
F_71 ( & V_80 -> V_101 ) ;
if ( V_94 > F_72 (
V_80 -> V_81 -> V_102 ) ) {
F_73 ( & V_80 -> V_103 ,
V_104 ) ;
}
F_74 ( V_2 ) ;
V_58 [ V_150 ] = V_2 ;
V_150 ++ ;
V_148 = V_2 -> V_12 + 1 ;
}
if ( ! V_150 )
goto V_158;
if ( V_55 ) {
int V_159 ;
F_22 ( ! V_150 || V_147 < 0 ) ;
if ( V_149 && V_55 == V_149 &&
V_150 < V_125 ) {
F_6 ( L_51 ) ;
F_103 ( & V_109 ) ;
goto V_153;
}
for ( V_159 = V_55 ; V_159 < V_149 ; V_159 ++ ) {
F_6 ( L_52 ,
V_109 . V_58 [ V_159 ] ) ;
V_109 . V_58 [ V_159 - V_55 + V_147 ] = V_109 . V_58 [ V_159 ] ;
}
V_109 . V_160 -= V_55 - V_147 ;
}
V_25 = F_37 ( V_58 [ 0 ] ) ;
V_35 = F_95 ( V_84 - V_25 ,
( T_2 ) V_150 << V_70 ) ;
F_6 ( L_53 ,
V_150 , V_25 , V_35 ) ;
F_60 ( V_43 , 0 , V_58 , V_35 , 0 ,
! ! V_151 , false ) ;
V_58 = NULL ;
V_151 = NULL ;
F_104 ( V_43 , 0 , V_35 ) ;
V_65 = F_36 ( V_6 ) ;
F_61 ( V_43 , V_25 , V_10 , V_65 . V_78 ,
& V_6 -> V_105 ) ;
V_49 = F_62 ( & V_80 -> V_33 -> V_32 , V_43 , true ) ;
F_22 ( V_49 ) ;
V_43 = NULL ;
V_12 = V_148 ;
V_91 -> V_161 -= V_150 ;
if ( V_91 -> V_161 <= 0 )
V_129 = 1 ;
V_158:
F_6 ( L_54 , ( int ) V_109 . V_160 ,
V_109 . V_160 ? V_109 . V_58 [ 0 ] : NULL ) ;
F_83 ( & V_109 ) ;
if ( V_150 && ! V_129 )
goto V_145;
}
if ( V_124 && ! V_129 ) {
F_6 ( L_55 ) ;
V_124 = 0 ;
V_12 = 0 ;
goto V_145;
}
if ( V_91 -> V_140 || ( V_123 && V_91 -> V_161 > 0 ) )
V_5 -> V_141 = V_12 ;
V_40:
if ( V_43 )
F_63 ( V_43 ) ;
F_28 ( V_10 ) ;
F_6 ( L_56 , V_49 ) ;
return V_49 ;
}
static int F_105 ( struct V_6 * V_6 ,
struct V_1 * V_10 )
{
struct V_1 * V_92 = F_67 ( V_6 , NULL ) ;
int V_69 = ! V_92 || V_10 -> V_19 <= V_92 -> V_19 ;
F_28 ( V_92 ) ;
return V_69 ;
}
static int F_106 ( struct V_29 * V_29 ,
T_4 V_162 , unsigned V_35 ,
struct V_2 * V_2 )
{
struct V_6 * V_6 = F_33 ( V_29 ) ;
struct V_7 * V_8 = F_7 ( V_6 ) ;
struct V_163 * V_164 = F_34 ( V_6 ) -> V_164 ;
T_4 V_93 = V_162 & V_165 ;
int V_166 = V_162 & ~ V_165 ;
int V_167 = V_166 + V_35 ;
T_4 V_168 ;
int V_41 ;
struct V_1 * V_10 , * V_92 ;
V_169:
F_99 ( V_2 ) ;
F_22 ( ! V_8 -> V_13 ) ;
F_107 ( & V_164 -> V_170 ) ;
F_22 ( ! V_8 -> V_13 -> V_14 ) ;
V_10 = F_1 ( V_2 ) ;
if ( V_10 && V_10 != V_8 -> V_16 ) {
V_92 = F_67 ( V_6 , NULL ) ;
F_108 ( & V_164 -> V_170 ) ;
if ( V_10 -> V_19 > V_92 -> V_19 ) {
F_28 ( V_92 ) ;
F_6 ( L_57 ,
V_2 , V_10 ) ;
V_10 = F_8 ( V_10 ) ;
F_42 ( V_2 ) ;
F_109 ( V_6 ) ;
V_41 = F_110 ( V_8 -> V_171 ,
F_105 ( V_6 , V_10 ) ) ;
F_28 ( V_10 ) ;
if ( V_41 == - V_172 )
return V_41 ;
return - V_173 ;
}
F_28 ( V_92 ) ;
F_6 ( L_58 ,
V_2 , V_10 ) ;
if ( ! F_101 ( V_2 ) )
goto V_169;
V_41 = F_69 ( V_2 , NULL ) ;
if ( V_41 < 0 )
goto V_174;
goto V_169;
}
if ( F_14 ( V_2 ) ) {
F_6 ( L_59 , V_2 ) ;
return 0 ;
}
if ( V_166 == 0 && V_35 == V_27 )
return 0 ;
V_168 = V_6 -> V_168 ;
if ( V_168 + V_35 > V_6 -> V_119 -> V_175 ) {
V_41 = - V_176 ;
goto V_177;
}
if ( V_93 >= V_168 ||
( V_166 == 0 && ( V_162 + V_35 ) >= V_168 &&
V_167 - V_166 != V_27 ) ) {
F_6 ( L_60 ,
V_2 , V_166 , V_167 , ( int ) V_27 ) ;
F_111 ( V_2 ,
0 , V_166 ,
V_167 , V_27 ) ;
return 0 ;
}
F_108 ( & V_164 -> V_170 ) ;
V_41 = F_32 ( V_29 , V_2 ) ;
if ( V_41 < 0 )
goto V_174;
goto V_169;
V_177:
F_108 ( & V_164 -> V_170 ) ;
V_174:
F_42 ( V_2 ) ;
return V_41 ;
}
static int F_112 ( struct V_29 * V_29 , struct V_4 * V_5 ,
T_4 V_162 , unsigned V_35 , unsigned V_99 ,
struct V_2 * * V_178 , void * * V_179 )
{
struct V_6 * V_6 = F_33 ( V_29 ) ;
struct V_2 * V_2 ;
T_3 V_12 = V_162 >> V_70 ;
int V_41 ;
do {
V_2 = F_113 ( V_5 , V_12 , 0 ) ;
if ( ! V_2 )
return - V_74 ;
* V_178 = V_2 ;
F_6 ( L_61 , V_29 ,
V_6 , V_2 , ( int ) V_162 , ( int ) V_35 ) ;
V_41 = F_106 ( V_29 , V_162 , V_35 , V_2 ) ;
} while ( V_41 == - V_173 );
return V_41 ;
}
static int F_114 ( struct V_29 * V_29 , struct V_4 * V_5 ,
T_4 V_162 , unsigned V_35 , unsigned V_180 ,
struct V_2 * V_2 , void * V_179 )
{
struct V_6 * V_6 = F_33 ( V_29 ) ;
struct V_79 * V_80 = F_34 ( V_6 ) ;
struct V_163 * V_164 = V_80 -> V_164 ;
unsigned V_181 = V_162 & ( V_27 - 1 ) ;
int V_182 = 0 ;
F_6 ( L_62 , V_29 ,
V_6 , V_2 , ( int ) V_162 , ( int ) V_180 , ( int ) V_35 ) ;
if ( V_180 < V_35 )
F_39 ( V_2 , V_181 + V_180 , V_35 ) ;
if ( V_162 + V_180 > V_6 -> V_168 )
V_182 = F_115 ( V_6 , V_162 + V_180 ) ;
if ( ! F_14 ( V_2 ) )
F_40 ( V_2 ) ;
F_116 ( V_2 ) ;
F_42 ( V_2 ) ;
F_108 ( & V_164 -> V_170 ) ;
F_48 ( V_2 ) ;
if ( V_182 )
F_117 ( F_7 ( V_6 ) , V_183 , NULL ) ;
return V_180 ;
}
static T_7 F_118 ( int V_184 , struct V_185 * V_186 ,
const struct V_187 * V_188 ,
T_4 V_162 , unsigned long V_189 )
{
F_31 ( 1 ) ;
return - V_176 ;
}
static int F_119 ( struct V_190 * V_191 , struct V_192 * V_193 )
{
struct V_6 * V_6 = F_33 ( V_191 -> V_194 ) ;
struct V_2 * V_2 = V_193 -> V_2 ;
struct V_163 * V_164 = F_34 ( V_6 ) -> V_164 ;
T_4 V_66 = F_37 ( V_2 ) ;
T_4 V_89 , V_35 ;
int V_69 ;
F_120 ( V_191 -> V_194 ) ;
V_89 = F_70 ( V_6 ) ;
if ( V_66 + V_27 <= V_89 )
V_35 = V_27 ;
else
V_35 = V_89 & ~ V_165 ;
F_6 ( L_63 , V_6 ,
V_66 , V_35 , V_2 , V_2 -> V_12 ) ;
F_97 ( V_2 ) ;
V_69 = V_195 ;
if ( ( V_66 > V_89 ) ||
( V_2 -> V_5 != V_6 -> V_112 ) )
goto V_40;
V_69 = F_106 ( V_191 -> V_194 , V_66 , V_35 , V_2 ) ;
if ( V_69 == 0 ) {
F_116 ( V_2 ) ;
F_108 ( & V_164 -> V_170 ) ;
V_69 = V_196 ;
} else {
if ( V_69 == - V_74 )
V_69 = V_197 ;
else
V_69 = V_198 ;
}
V_40:
F_6 ( L_64 , V_6 , V_66 , V_35 , V_69 ) ;
if ( V_69 != V_196 )
F_42 ( V_2 ) ;
return V_69 ;
}
int F_121 ( struct V_29 * V_29 , struct V_190 * V_191 )
{
struct V_4 * V_5 = V_29 -> V_199 ;
if ( ! V_5 -> V_200 -> V_201 )
return - V_202 ;
F_122 ( V_29 ) ;
V_191 -> V_203 = & V_204 ;
return 0 ;
}
