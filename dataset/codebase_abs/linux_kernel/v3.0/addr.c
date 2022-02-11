static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
struct V_4 * V_4 ;
struct V_5 * V_6 ;
int V_7 = 0 ;
struct V_8 * V_9 ;
if ( F_2 ( ! V_3 ) )
return ! F_3 ( V_1 ) ;
if ( F_3 ( V_1 ) ) {
F_4 ( L_1 ,
V_3 -> V_10 , V_1 , V_1 -> V_11 ) ;
return 0 ;
}
V_4 = V_3 -> V_10 ;
V_6 = F_5 ( V_4 ) ;
V_9 = F_6 ( V_6 -> V_12 -> V_13 ) ;
F_7 ( & V_4 -> V_14 ) ;
if ( V_6 -> V_15 == NULL )
V_6 -> V_15 = F_6 ( V_9 ) ;
++ V_6 -> V_16 ;
if ( V_6 -> V_17 == 0 )
F_8 ( V_4 ) ;
++ V_6 -> V_17 ;
F_4 ( L_2
L_3 ,
V_3 -> V_10 , V_1 , V_1 -> V_11 ,
V_6 -> V_17 - 1 , V_6 -> V_16 - 1 ,
V_6 -> V_17 , V_6 -> V_16 ,
V_9 , V_9 -> V_18 , V_9 -> V_19 ) ;
F_9 ( & V_4 -> V_14 ) ;
F_10 ( & V_3 -> V_20 ) ;
if ( V_1 -> V_3 ) {
F_11 ( ! F_12 ( V_1 ) ) ;
F_13 ( V_1 , V_1 -> V_3 ) ;
F_14 ( & V_3 -> V_21 ,
F_15 ( V_1 ) , V_22 ) ;
V_1 -> V_23 = ( unsigned long ) V_9 ;
F_16 ( V_1 ) ;
} else {
F_4 ( L_4 , V_1 ) ;
V_7 = 1 ;
}
F_17 ( & V_3 -> V_20 ) ;
if ( V_7 )
F_18 ( V_6 , 1 , V_9 ) ;
F_19 ( V_3 -> V_10 , V_24 ) ;
F_20 ( ! F_21 ( V_1 ) ) ;
return 1 ;
}
static void F_22 ( struct V_1 * V_1 , unsigned long V_25 )
{
struct V_4 * V_4 ;
struct V_5 * V_6 ;
struct V_8 * V_9 = ( void * ) V_1 -> V_23 ;
F_20 ( ! F_23 ( V_1 ) ) ;
F_20 ( ! V_1 -> V_23 ) ;
F_20 ( ! F_24 ( V_1 ) ) ;
F_20 ( ! V_1 -> V_3 ) ;
V_4 = V_1 -> V_3 -> V_10 ;
if ( ! F_21 ( V_1 ) )
F_25 ( L_5 , V_4 , V_1 ) ;
if ( V_25 == 0 )
F_26 ( V_1 ) ;
V_6 = F_5 ( V_4 ) ;
if ( V_25 == 0 ) {
F_4 ( L_6 ,
V_4 , V_1 , V_1 -> V_11 , V_25 ) ;
F_18 ( V_6 , 1 , V_9 ) ;
F_27 ( V_9 ) ;
V_1 -> V_23 = 0 ;
F_28 ( V_1 ) ;
} else {
F_4 ( L_7 ,
V_4 , V_1 , V_1 -> V_11 ) ;
}
}
static int F_29 ( struct V_1 * V_1 , T_1 V_26 )
{
struct V_4 * V_4 = V_1 -> V_3 ? V_1 -> V_3 -> V_10 : NULL ;
F_4 ( L_8 , V_4 , V_1 , V_1 -> V_11 ) ;
F_30 ( F_21 ( V_1 ) ) ;
F_30 ( V_1 -> V_23 ) ;
F_30 ( F_24 ( V_1 ) ) ;
return 0 ;
}
static int F_31 ( struct V_27 * V_28 , struct V_1 * V_1 )
{
struct V_4 * V_4 = V_28 -> V_29 -> V_30 ;
struct V_5 * V_6 = F_5 ( V_4 ) ;
struct V_31 * V_32 =
& F_32 ( V_4 ) -> V_33 -> V_32 ;
int V_34 = 0 ;
T_2 V_35 = V_36 ;
F_4 ( L_9 ,
V_4 , V_28 , V_1 , V_1 -> V_11 ) ;
V_34 = F_33 ( V_32 , F_34 ( V_4 ) , & V_6 -> V_37 ,
V_1 -> V_11 << V_38 , & V_35 ,
V_6 -> V_39 , V_6 -> V_40 ,
& V_1 , 1 , 0 ) ;
if ( V_34 == - V_41 )
V_34 = 0 ;
if ( V_34 < 0 ) {
F_35 ( V_1 ) ;
goto V_42;
} else if ( V_34 < V_36 ) {
F_36 ( V_1 , V_34 , V_36 ) ;
}
F_37 ( V_1 ) ;
V_42:
return V_34 < 0 ? V_34 : 0 ;
}
static int F_38 ( struct V_27 * V_28 , struct V_1 * V_1 )
{
int V_43 = F_31 ( V_28 , V_1 ) ;
F_39 ( V_1 ) ;
return V_43 ;
}
static struct V_1 * * F_40 ( struct V_44 * V_45 ,
unsigned * V_46 )
{
struct V_1 * * V_47 ;
struct V_1 * V_1 ;
int V_48 , V_49 = 0 ;
V_47 = F_41 ( sizeof( * V_47 ) * * V_46 , V_50 ) ;
if ( ! V_47 )
return F_42 ( - V_51 ) ;
F_20 ( F_43 ( V_45 ) ) ;
V_48 = F_44 ( V_45 -> V_52 , struct V_1 , V_53 ) -> V_11 ;
F_45 (page, page_list, lru) {
if ( V_1 -> V_11 == V_48 ) {
F_4 ( L_10 , V_49 , V_1 ) ;
V_47 [ V_49 ] = V_1 ;
V_49 ++ ;
V_48 ++ ;
} else {
break;
}
}
* V_46 = V_49 ;
return V_47 ;
}
static int F_46 ( struct V_27 * V_27 , struct V_2 * V_3 ,
struct V_44 * V_45 , unsigned V_46 )
{
struct V_4 * V_4 = V_27 -> V_29 -> V_30 ;
struct V_5 * V_6 = F_5 ( V_4 ) ;
struct V_31 * V_32 =
& F_32 ( V_4 ) -> V_33 -> V_32 ;
int V_54 = 0 ;
struct V_1 * * V_47 ;
T_3 V_25 ;
T_2 V_35 ;
F_4 ( L_11 ,
V_4 , V_27 , V_46 ) ;
V_47 = F_40 ( V_45 , & V_46 ) ;
if ( F_47 ( V_47 ) )
return F_48 ( V_47 ) ;
V_25 = V_47 [ 0 ] -> V_11 << V_38 ;
V_35 = V_46 << V_38 ;
V_54 = F_33 ( V_32 , F_34 ( V_4 ) , & V_6 -> V_37 ,
V_25 , & V_35 ,
V_6 -> V_39 , V_6 -> V_40 ,
V_47 , V_46 , 0 ) ;
if ( V_54 == - V_41 )
V_54 = 0 ;
if ( V_54 < 0 )
goto V_42;
for (; ! F_43 ( V_45 ) && V_35 > 0 ;
V_54 -= V_36 , V_35 -= V_36 ) {
struct V_1 * V_1 =
F_44 ( V_45 -> V_52 , struct V_1 , V_53 ) ;
F_49 ( & V_1 -> V_53 ) ;
if ( V_54 < ( int ) V_36 ) {
int V_55 = V_54 < 0 ? 0 : V_54 ;
F_36 ( V_1 , V_55 , V_36 ) ;
}
if ( F_50 ( V_1 , V_3 , V_1 -> V_11 ,
V_50 ) ) {
F_51 ( V_1 ) ;
F_4 ( L_12 ,
V_4 , V_1 ) ;
continue;
}
F_4 ( L_13 , V_4 , V_1 ,
V_1 -> V_11 ) ;
F_52 ( V_1 ) ;
F_37 ( V_1 ) ;
F_39 ( V_1 ) ;
F_51 ( V_1 ) ;
}
V_54 = 0 ;
V_42:
F_53 ( V_47 ) ;
return V_54 ;
}
static struct V_8 * F_54 ( struct V_4 * V_4 ,
T_2 * V_56 )
{
struct V_5 * V_6 = F_5 ( V_4 ) ;
struct V_8 * V_9 = NULL ;
struct V_57 * V_58 = NULL ;
F_7 ( & V_4 -> V_14 ) ;
F_55 (capsnap, &ci->i_cap_snaps, ci_item) {
F_4 ( L_14 , V_58 ,
V_58 -> V_59 , V_58 -> V_60 ) ;
if ( V_58 -> V_60 ) {
V_9 = F_6 ( V_58 -> V_59 ) ;
if ( V_56 )
* V_56 = V_58 -> V_61 ;
break;
}
}
if ( ! V_9 && V_6 -> V_16 ) {
V_9 = F_6 ( V_6 -> V_15 ) ;
F_4 ( L_15 ,
V_9 , V_6 -> V_16 ) ;
}
F_9 ( & V_4 -> V_14 ) ;
return V_9 ;
}
static int F_56 ( struct V_1 * V_1 , struct V_62 * V_63 )
{
struct V_4 * V_4 ;
struct V_5 * V_6 ;
struct V_64 * V_65 ;
struct V_31 * V_32 ;
T_3 V_66 = V_1 -> V_11 << V_38 ;
int V_35 = V_36 ;
T_3 V_67 ;
int V_34 = 0 ;
struct V_8 * V_9 , * V_68 ;
T_2 V_56 = 0 ;
long V_69 ;
F_4 ( L_16 , V_1 , V_1 -> V_11 ) ;
if ( ! V_1 -> V_3 || ! V_1 -> V_3 -> V_10 ) {
F_4 ( L_17 , V_1 ) ;
return - V_70 ;
}
V_4 = V_1 -> V_3 -> V_10 ;
V_6 = F_5 ( V_4 ) ;
V_65 = F_32 ( V_4 ) ;
V_32 = & V_65 -> V_33 -> V_32 ;
V_9 = ( void * ) V_1 -> V_23 ;
if ( V_9 == NULL ) {
F_4 ( L_18 , V_4 , V_1 ) ;
goto V_42;
}
V_68 = F_54 ( V_4 , & V_56 ) ;
if ( V_9 -> V_18 > V_68 -> V_18 ) {
F_4 ( L_19 ,
V_4 , V_1 , ( void * ) V_1 -> V_23 ) ;
F_30 ( ( V_71 -> V_72 & V_73 ) == 0 ) ;
F_27 ( V_68 ) ;
goto V_42;
}
F_27 ( V_68 ) ;
if ( V_56 )
V_67 = V_56 ;
else
V_67 = F_57 ( V_4 ) ;
if ( V_67 < V_66 + V_35 )
V_35 = V_67 - V_66 ;
F_4 ( L_20 ,
V_4 , V_1 , V_1 -> V_11 , V_66 , V_35 , V_9 ) ;
V_69 = F_58 ( & V_65 -> V_74 ) ;
if ( V_69 >
F_59 ( V_65 -> V_75 -> V_76 ) )
F_60 ( & V_65 -> V_77 , V_78 ) ;
F_61 ( V_1 ) ;
V_34 = F_62 ( V_32 , F_34 ( V_4 ) ,
& V_6 -> V_37 , V_9 ,
V_66 , V_35 ,
V_6 -> V_39 , V_6 -> V_40 ,
& V_4 -> V_79 ,
& V_1 , 1 , 0 , 0 , true ) ;
if ( V_34 < 0 ) {
F_4 ( L_21 , V_34 , V_1 ) ;
F_35 ( V_1 ) ;
F_63 ( & V_4 -> V_80 , V_34 ) ;
if ( V_63 )
V_63 -> V_81 ++ ;
} else {
F_4 ( L_22 , V_1 ) ;
V_34 = 0 ;
}
V_1 -> V_23 = 0 ;
F_28 ( V_1 ) ;
F_64 ( V_1 ) ;
F_18 ( V_6 , 1 , V_9 ) ;
F_27 ( V_9 ) ;
V_42:
return V_34 ;
}
static int F_65 ( struct V_1 * V_1 , struct V_62 * V_63 )
{
int V_34 ;
struct V_4 * V_4 = V_1 -> V_3 -> V_10 ;
F_20 ( ! V_4 ) ;
F_8 ( V_4 ) ;
V_34 = F_56 ( V_1 , V_63 ) ;
F_39 ( V_1 ) ;
F_66 ( V_4 ) ;
return V_34 ;
}
static void F_67 ( struct V_1 * * V_47 , int V_82 )
{
struct V_83 V_84 ;
int V_85 ;
F_68 ( & V_84 , 0 ) ;
for ( V_85 = 0 ; V_85 < V_82 ; V_85 ++ ) {
if ( F_69 ( & V_84 , V_47 [ V_85 ] ) == 0 )
F_70 ( & V_84 ) ;
}
F_70 ( & V_84 ) ;
}
static void F_71 ( struct V_86 * V_87 ,
struct V_88 * V_89 )
{
struct V_4 * V_4 = V_87 -> V_90 ;
struct V_91 * V_92 ;
struct V_93 * V_94 ;
struct V_5 * V_6 = F_5 ( V_4 ) ;
unsigned V_95 ;
struct V_1 * V_1 ;
int V_85 ;
struct V_8 * V_9 = V_87 -> V_96 ;
struct V_2 * V_3 = V_4 -> V_97 ;
T_4 V_54 = - V_98 ;
T_2 V_99 = 0 ;
struct V_64 * V_65 = F_32 ( V_4 ) ;
long V_69 ;
unsigned V_100 = F_72 ( V_6 ) ;
V_92 = V_89 -> V_101 . V_102 ;
F_30 ( F_73 ( V_92 -> V_103 ) == 0 ) ;
V_94 = ( void * ) ( V_92 + 1 ) ;
V_54 = F_73 ( V_92 -> V_104 ) ;
V_99 = F_74 ( V_94 -> V_105 . V_106 ) ;
if ( V_54 >= 0 ) {
V_95 = V_87 -> V_107 ;
} else {
V_95 = 0 ;
F_63 ( V_3 , V_54 ) ;
}
F_4 ( L_23 ,
V_4 , V_54 , V_99 , V_95 ) ;
for ( V_85 = 0 ; V_85 < V_87 -> V_107 ; V_85 ++ ) {
V_1 = V_87 -> V_108 [ V_85 ] ;
F_20 ( ! V_1 ) ;
F_30 ( ! F_12 ( V_1 ) ) ;
V_69 =
F_75 ( & V_65 -> V_74 ) ;
if ( V_69 <
F_76 ( V_65 -> V_75 -> V_76 ) )
F_77 ( & V_65 -> V_77 ,
V_78 ) ;
F_27 ( ( void * ) V_1 -> V_23 ) ;
V_1 -> V_23 = 0 ;
F_28 ( V_1 ) ;
F_4 ( L_24 , V_85 , V_1 ) ;
F_64 ( V_1 ) ;
if ( ( V_100 & ( V_109 | V_110 ) ) == 0 )
F_78 ( V_4 -> V_97 , V_1 ) ;
F_39 ( V_1 ) ;
}
F_4 ( L_25 , V_4 , V_95 ) ;
F_18 ( V_6 , V_87 -> V_107 , V_9 ) ;
F_67 ( V_87 -> V_108 , V_87 -> V_107 ) ;
if ( V_87 -> V_111 )
F_79 ( V_87 -> V_108 ,
F_80 ( V_4 -> V_112 ) -> V_113 ) ;
else
F_53 ( V_87 -> V_108 ) ;
F_81 ( V_87 ) ;
}
static void F_82 ( struct V_64 * V_65 ,
struct V_86 * V_87 )
{
V_87 -> V_108 = F_41 ( sizeof( struct V_1 * ) * V_87 -> V_107 ,
V_50 ) ;
if ( ! V_87 -> V_108 ) {
V_87 -> V_108 = F_83 ( V_65 -> V_113 , V_50 ) ;
V_87 -> V_111 = 1 ;
F_30 ( ! V_87 -> V_108 ) ;
}
}
static int F_84 ( struct V_2 * V_3 ,
struct V_62 * V_63 )
{
struct V_4 * V_4 = V_3 -> V_10 ;
struct V_5 * V_6 = F_5 ( V_4 ) ;
struct V_64 * V_65 ;
T_5 V_11 , V_114 , V_115 ;
int V_116 = 0 ;
int V_117 = 1 ;
T_5 V_118 = 0 , V_119 = 0 ;
struct V_8 * V_9 = NULL , * V_120 = NULL , * V_121 ;
struct V_83 V_84 ;
int V_122 = 0 ;
int V_54 = 0 ;
unsigned V_123 = 1 << V_4 -> V_124 ;
struct V_86 * V_87 = NULL ;
int V_125 ;
T_2 V_56 = 0 ;
V_125 = V_63 -> V_126 == V_127 ;
if ( F_85 ( V_6 , V_128 ) )
V_125 = 1 ;
F_4 ( L_26 ,
V_4 , V_125 ,
V_63 -> V_126 == V_129 ? L_27 :
( V_63 -> V_126 == V_127 ? L_28 : L_29 ) ) ;
V_65 = F_32 ( V_4 ) ;
if ( V_65 -> V_130 == V_131 ) {
F_86 ( L_30 , V_4 ) ;
return - V_98 ;
}
if ( V_65 -> V_75 -> V_123 && V_65 -> V_75 -> V_123 < V_123 )
V_123 = V_65 -> V_75 -> V_123 ;
if ( V_123 < V_36 )
V_123 = V_36 ;
V_119 = V_123 >> V_38 ;
F_68 ( & V_84 , 0 ) ;
if ( V_63 -> V_132 ) {
V_114 = V_3 -> V_133 ;
V_115 = - 1 ;
F_4 ( L_31 , V_114 ) ;
} else {
V_114 = V_63 -> V_134 >> V_38 ;
V_115 = V_63 -> V_135 >> V_38 ;
if ( V_63 -> V_134 == 0 && V_63 -> V_135 == V_136 )
V_116 = 1 ;
V_117 = 0 ;
F_4 ( L_32 , V_114 , V_115 ) ;
}
V_11 = V_114 ;
V_137:
F_27 ( V_9 ) ;
V_9 = F_54 ( V_4 , & V_56 ) ;
if ( ! V_9 ) {
F_4 ( L_33 ) ;
goto V_42;
}
F_4 ( L_34 ,
V_9 , V_9 -> V_18 , V_9 -> V_19 ) ;
if ( V_120 && V_9 != V_120 ) {
F_4 ( L_35 ,
V_11 ) ;
V_11 = V_114 ;
}
V_120 = V_9 ;
while ( ! V_122 && V_11 <= V_115 ) {
unsigned V_85 ;
int V_138 ;
T_5 V_139 ;
int V_140 , V_141 ;
struct V_1 * V_1 ;
int V_142 ;
T_2 V_25 , V_35 ;
struct V_143 * V_144 ;
struct V_93 * V_94 ;
long V_69 ;
V_139 = 0 ;
V_141 = 0 ;
V_118 = V_119 ;
V_145:
V_138 = - 1 ;
V_142 = F_87 ( V_115 - V_11 ,
F_87 ( ( T_5 ) V_146 ,
V_118 - ( T_5 ) V_141 ) - 1 )
+ 1 ;
V_140 = F_88 ( & V_84 , V_3 , & V_11 ,
V_22 ,
V_142 ) ;
F_4 ( L_36 , V_140 ) ;
if ( ! V_140 && ! V_141 )
break;
for ( V_85 = 0 ; V_85 < V_140 && V_141 < V_118 ; V_85 ++ ) {
V_1 = V_84 . V_47 [ V_85 ] ;
F_4 ( L_37 , V_1 , V_1 -> V_11 ) ;
if ( V_141 == 0 )
F_89 ( V_1 ) ;
else if ( ! F_90 ( V_1 ) )
break;
if ( F_2 ( ! F_21 ( V_1 ) ) ||
F_2 ( V_1 -> V_3 != V_3 ) ) {
F_4 ( L_38 , V_1 ) ;
F_39 ( V_1 ) ;
break;
}
if ( ! V_63 -> V_132 && V_1 -> V_11 > V_115 ) {
F_4 ( L_39 , V_1 ) ;
V_122 = 1 ;
F_39 ( V_1 ) ;
break;
}
if ( V_139 && ( V_1 -> V_11 != V_139 ) ) {
F_4 ( L_40 , V_1 ) ;
F_39 ( V_1 ) ;
break;
}
if ( V_63 -> V_126 != V_129 ) {
F_4 ( L_41 , V_1 ) ;
F_91 ( V_1 ) ;
}
if ( ( V_56 && F_92 ( V_1 ) > V_56 ) ||
( ! V_56 &&
F_92 ( V_1 ) > F_57 ( V_4 ) ) ) {
F_4 ( L_42 , V_1 , V_56 ?
V_56 : F_57 ( V_4 ) ) ;
V_122 = 1 ;
F_39 ( V_1 ) ;
break;
}
if ( F_93 ( V_1 ) ) {
F_4 ( L_43 , V_1 ) ;
F_39 ( V_1 ) ;
break;
}
V_121 = ( void * ) V_1 -> V_23 ;
if ( V_121 -> V_18 > V_9 -> V_18 ) {
F_4 ( L_44 ,
V_121 , V_121 -> V_18 , V_9 , V_9 -> V_18 ) ;
F_39 ( V_1 ) ;
if ( ! V_141 )
continue;
break;
}
if ( ! F_94 ( V_1 ) ) {
F_4 ( L_45 , V_1 ) ;
F_39 ( V_1 ) ;
break;
}
if ( V_141 == 0 ) {
V_25 = ( unsigned long long ) V_1 -> V_11
<< V_38 ;
V_35 = V_123 ;
V_87 = F_95 ( & V_65 -> V_33 -> V_32 ,
& V_6 -> V_37 ,
F_34 ( V_4 ) ,
V_25 , & V_35 ,
V_147 ,
V_148 |
V_149 ,
V_9 , V_125 ,
V_6 -> V_39 ,
V_6 -> V_40 ,
& V_4 -> V_79 , true , 1 , 0 ) ;
if ( ! V_87 ) {
V_54 = - V_51 ;
F_39 ( V_1 ) ;
break;
}
V_118 = V_87 -> V_107 ;
F_82 ( V_65 , V_87 ) ;
V_87 -> V_150 = F_71 ;
V_87 -> V_90 = V_4 ;
}
if ( V_138 < 0 )
V_138 = V_85 ;
F_4 ( L_46 ,
V_4 , V_1 , V_1 -> V_11 ) ;
V_69 =
F_58 ( & V_65 -> V_74 ) ;
if ( V_69 > F_59 (
V_65 -> V_75 -> V_76 ) ) {
F_60 ( & V_65 -> V_77 ,
V_78 ) ;
}
F_61 ( V_1 ) ;
V_87 -> V_108 [ V_141 ] = V_1 ;
V_141 ++ ;
V_139 = V_1 -> V_11 + 1 ;
}
if ( ! V_141 )
goto V_151;
if ( V_85 ) {
int V_152 ;
F_20 ( ! V_141 || V_138 < 0 ) ;
if ( V_140 && V_85 == V_140 &&
V_141 < V_118 ) {
F_4 ( L_47 ) ;
F_96 ( & V_84 ) ;
goto V_145;
}
for ( V_152 = V_85 ; V_152 < V_140 ; V_152 ++ ) {
F_4 ( L_48 ,
V_84 . V_47 [ V_152 ] ) ;
V_84 . V_47 [ V_152 - V_85 + V_138 ] = V_84 . V_47 [ V_152 ] ;
}
V_84 . V_153 -= V_85 - V_138 ;
}
V_25 = V_87 -> V_108 [ 0 ] -> V_11 << V_38 ;
V_35 = F_87 ( ( V_56 ? V_56 : F_57 ( V_4 ) ) - V_25 ,
( T_2 ) V_141 << V_38 ) ;
F_4 ( L_49 ,
V_141 , V_25 , V_35 ) ;
V_87 -> V_107 = V_141 ;
V_144 = V_87 -> V_154 -> V_101 . V_102 ;
V_94 = ( void * ) ( V_144 + 1 ) ;
V_94 -> V_105 . V_106 = F_97 ( V_35 ) ;
V_94 -> V_155 = F_98 ( V_35 ) ;
V_87 -> V_154 -> V_156 . V_157 = F_98 ( V_35 ) ;
V_54 = F_99 ( & V_65 -> V_33 -> V_32 , V_87 , true ) ;
F_20 ( V_54 ) ;
V_87 = NULL ;
V_11 = V_139 ;
V_63 -> V_158 -= V_141 ;
if ( V_63 -> V_158 <= 0 )
V_122 = 1 ;
V_151:
F_4 ( L_50 , ( int ) V_84 . V_153 ,
V_84 . V_153 ? V_84 . V_47 [ 0 ] : NULL ) ;
F_70 ( & V_84 ) ;
if ( V_141 && ! V_122 )
goto V_137;
}
if ( V_117 && ! V_122 ) {
F_4 ( L_51 ) ;
V_117 = 0 ;
V_11 = 0 ;
goto V_137;
}
if ( V_63 -> V_132 || ( V_116 && V_63 -> V_158 > 0 ) )
V_3 -> V_133 = V_11 ;
V_42:
if ( V_87 )
F_81 ( V_87 ) ;
F_27 ( V_9 ) ;
F_4 ( L_52 , V_54 ) ;
return V_54 ;
}
static int F_100 ( struct V_4 * V_4 ,
struct V_8 * V_9 )
{
struct V_8 * V_68 = F_54 ( V_4 , NULL ) ;
int V_159 = ! V_68 || V_9 -> V_18 <= V_68 -> V_18 ;
F_27 ( V_68 ) ;
return V_159 ;
}
static int F_101 ( struct V_27 * V_27 ,
T_3 V_160 , unsigned V_35 ,
struct V_1 * V_1 )
{
struct V_4 * V_4 = V_27 -> V_29 -> V_30 ;
struct V_5 * V_6 = F_5 ( V_4 ) ;
struct V_161 * V_162 = F_32 ( V_4 ) -> V_162 ;
T_3 V_66 = V_160 & V_163 ;
int V_164 = V_160 & ~ V_163 ;
int V_165 = V_164 + V_35 ;
T_3 V_67 ;
int V_43 ;
struct V_8 * V_9 , * V_68 ;
V_166:
F_91 ( V_1 ) ;
F_20 ( ! V_6 -> V_12 ) ;
F_102 ( & V_162 -> V_167 ) ;
F_20 ( ! V_6 -> V_12 -> V_13 ) ;
V_9 = ( void * ) V_1 -> V_23 ;
if ( V_9 && V_9 != V_6 -> V_15 ) {
V_68 = F_54 ( V_4 , NULL ) ;
F_103 ( & V_162 -> V_167 ) ;
if ( V_9 -> V_18 > V_68 -> V_18 ) {
F_27 ( V_68 ) ;
F_4 ( L_53 ,
V_1 , V_9 ) ;
V_9 = F_6 ( V_9 ) ;
F_39 ( V_1 ) ;
F_104 ( V_4 ) ;
V_43 = F_105 ( V_6 -> V_168 ,
F_100 ( V_4 , V_9 ) ) ;
F_27 ( V_9 ) ;
if ( V_43 == - V_169 )
return V_43 ;
return - V_170 ;
}
F_27 ( V_68 ) ;
F_4 ( L_54 ,
V_1 , V_9 ) ;
if ( ! F_94 ( V_1 ) )
goto V_166;
V_43 = F_56 ( V_1 , NULL ) ;
if ( V_43 < 0 )
goto V_171;
goto V_166;
}
if ( F_12 ( V_1 ) ) {
F_4 ( L_55 , V_1 ) ;
return 0 ;
}
if ( V_164 == 0 && V_35 == V_36 )
return 0 ;
V_67 = V_4 -> V_67 ;
if ( V_67 + V_35 > V_4 -> V_112 -> V_172 ) {
V_43 = - V_173 ;
goto V_174;
}
if ( V_66 >= V_67 ||
( V_164 == 0 && ( V_160 + V_35 ) >= V_67 &&
V_165 - V_164 != V_36 ) ) {
F_4 ( L_56 ,
V_1 , V_164 , V_165 , ( int ) V_36 ) ;
F_106 ( V_1 ,
0 , V_164 ,
V_165 , V_36 ) ;
return 0 ;
}
F_103 ( & V_162 -> V_167 ) ;
V_43 = F_31 ( V_27 , V_1 ) ;
if ( V_43 < 0 )
goto V_171;
goto V_166;
V_174:
F_103 ( & V_162 -> V_167 ) ;
V_171:
F_39 ( V_1 ) ;
return V_43 ;
}
static int F_107 ( struct V_27 * V_27 , struct V_2 * V_3 ,
T_3 V_160 , unsigned V_35 , unsigned V_72 ,
struct V_1 * * V_175 , void * * V_176 )
{
struct V_4 * V_4 = V_27 -> V_29 -> V_30 ;
struct V_1 * V_1 ;
T_5 V_11 = V_160 >> V_38 ;
int V_43 ;
do {
V_1 = F_108 ( V_3 , V_11 , 0 ) ;
if ( ! V_1 )
return - V_51 ;
* V_175 = V_1 ;
F_4 ( L_57 , V_27 ,
V_4 , V_1 , ( int ) V_160 , ( int ) V_35 ) ;
V_43 = F_101 ( V_27 , V_160 , V_35 , V_1 ) ;
} while ( V_43 == - V_170 );
return V_43 ;
}
static int F_109 ( struct V_27 * V_27 , struct V_2 * V_3 ,
T_3 V_160 , unsigned V_35 , unsigned V_177 ,
struct V_1 * V_1 , void * V_176 )
{
struct V_4 * V_4 = V_27 -> V_29 -> V_30 ;
struct V_64 * V_65 = F_32 ( V_4 ) ;
struct V_161 * V_162 = V_65 -> V_162 ;
unsigned V_178 = V_160 & ( V_36 - 1 ) ;
int V_179 = 0 ;
F_4 ( L_58 , V_27 ,
V_4 , V_1 , ( int ) V_160 , ( int ) V_177 , ( int ) V_35 ) ;
if ( V_177 < V_35 )
F_36 ( V_1 , V_178 + V_177 , V_35 ) ;
if ( V_160 + V_177 > V_4 -> V_67 )
V_179 = F_110 ( V_4 , V_160 + V_177 ) ;
if ( ! F_12 ( V_1 ) )
F_37 ( V_1 ) ;
F_111 ( V_1 ) ;
F_39 ( V_1 ) ;
F_103 ( & V_162 -> V_167 ) ;
F_51 ( V_1 ) ;
if ( V_179 )
F_112 ( F_5 ( V_4 ) , V_180 , NULL ) ;
return V_177 ;
}
static T_6 F_113 ( int V_181 , struct V_182 * V_183 ,
const struct V_184 * V_185 ,
T_3 V_160 , unsigned long V_186 )
{
F_30 ( 1 ) ;
return - V_173 ;
}
static int F_114 ( struct V_187 * V_188 , struct V_189 * V_190 )
{
struct V_4 * V_4 = V_188 -> V_191 -> V_29 -> V_30 ;
struct V_1 * V_1 = V_190 -> V_1 ;
struct V_161 * V_162 = F_32 ( V_4 ) -> V_162 ;
T_3 V_192 = V_1 -> V_11 << V_38 ;
T_3 V_61 , V_35 ;
int V_159 ;
V_61 = F_57 ( V_4 ) ;
if ( V_192 + V_36 <= V_61 )
V_35 = V_36 ;
else
V_35 = V_61 & ~ V_163 ;
F_4 ( L_59 , V_4 ,
V_192 , V_35 , V_1 , V_1 -> V_11 ) ;
F_89 ( V_1 ) ;
V_159 = V_193 ;
if ( ( V_192 > V_61 ) ||
( V_1 -> V_3 != V_4 -> V_97 ) )
goto V_42;
V_159 = F_101 ( V_188 -> V_191 , V_192 , V_35 , V_1 ) ;
if ( V_159 == 0 ) {
F_111 ( V_1 ) ;
F_103 ( & V_162 -> V_167 ) ;
V_159 = V_194 ;
} else {
if ( V_159 == - V_51 )
V_159 = V_195 ;
else
V_159 = V_196 ;
}
V_42:
F_4 ( L_60 , V_4 , V_192 , V_35 , V_159 ) ;
if ( V_159 != V_194 )
F_39 ( V_1 ) ;
return V_159 ;
}
int F_115 ( struct V_27 * V_27 , struct V_187 * V_188 )
{
struct V_2 * V_3 = V_27 -> V_197 ;
if ( ! V_3 -> V_198 -> V_199 )
return - V_200 ;
F_116 ( V_27 ) ;
V_188 -> V_201 = & V_202 ;
V_188 -> V_203 |= V_204 ;
return 0 ;
}
