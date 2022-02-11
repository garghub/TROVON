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
struct V_1 * V_9 ;
int V_10 ;
if ( F_4 ( ! V_5 ) )
return ! F_5 ( V_2 ) ;
if ( F_6 ( V_2 ) ) {
F_7 ( L_1 ,
V_5 -> V_11 , V_2 , V_2 -> V_12 ) ;
F_8 ( ! F_2 ( V_2 ) ) ;
return 0 ;
}
V_6 = V_5 -> V_11 ;
V_8 = F_9 ( V_6 ) ;
V_9 = F_10 ( V_8 -> V_13 -> V_14 ) ;
F_11 ( & V_8 -> V_15 ) ;
if ( V_8 -> V_16 == NULL )
V_8 -> V_16 = F_10 ( V_9 ) ;
++ V_8 -> V_17 ;
if ( V_8 -> V_18 == 0 )
F_12 ( V_6 ) ;
++ V_8 -> V_18 ;
F_7 ( L_2
L_3 ,
V_5 -> V_11 , V_2 , V_2 -> V_12 ,
V_8 -> V_18 - 1 , V_8 -> V_17 - 1 ,
V_8 -> V_18 , V_8 -> V_17 ,
V_9 , V_9 -> V_19 , V_9 -> V_20 ) ;
F_13 ( & V_8 -> V_15 ) ;
F_8 ( F_2 ( V_2 ) ) ;
V_2 -> V_3 = ( unsigned long ) V_9 ;
F_14 ( V_2 ) ;
V_10 = F_15 ( V_2 ) ;
F_16 ( ! F_17 ( V_2 ) ) ;
F_16 ( ! V_2 -> V_5 ) ;
return V_10 ;
}
static void F_18 ( struct V_2 * V_2 , unsigned int V_21 ,
unsigned int V_22 )
{
struct V_6 * V_6 ;
struct V_7 * V_8 ;
struct V_1 * V_9 = F_1 ( V_2 ) ;
V_6 = V_2 -> V_5 -> V_11 ;
V_8 = F_9 ( V_6 ) ;
if ( V_21 != 0 || V_22 != V_23 ) {
F_7 ( L_4 ,
V_6 , V_2 , V_2 -> V_12 , V_21 , V_22 ) ;
return;
}
F_19 ( V_6 , V_2 ) ;
if ( ! F_2 ( V_2 ) )
return;
if ( ! F_6 ( V_2 ) )
F_20 ( L_5 , V_6 , V_2 ) ;
F_21 ( V_2 ) ;
F_7 ( L_6 ,
V_6 , V_2 , V_2 -> V_12 ) ;
F_22 ( V_8 , 1 , V_9 ) ;
F_23 ( V_9 ) ;
V_2 -> V_3 = 0 ;
F_24 ( V_2 ) ;
}
static int F_25 ( struct V_2 * V_2 , T_1 V_24 )
{
struct V_6 * V_6 = V_2 -> V_5 ? V_2 -> V_5 -> V_11 : NULL ;
F_7 ( L_7 , V_6 , V_2 , V_2 -> V_12 ) ;
F_16 ( F_6 ( V_2 ) ) ;
if ( ! F_26 ( V_2 , V_24 ) )
return 0 ;
return ! F_2 ( V_2 ) ;
}
static int F_27 ( struct V_25 * V_26 , struct V_2 * V_2 )
{
struct V_6 * V_6 = F_28 ( V_26 ) ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_27 * V_28 =
& F_29 ( V_6 ) -> V_29 -> V_28 ;
int V_30 = 0 ;
T_2 V_31 = V_23 ;
V_30 = F_30 ( V_6 , V_2 ) ;
if ( V_30 == 0 )
goto V_32;
F_7 ( L_8 ,
V_6 , V_26 , V_2 , V_2 -> V_12 ) ;
V_30 = F_31 ( V_28 , F_32 ( V_6 ) , & V_8 -> V_33 ,
( T_2 ) F_33 ( V_2 ) , & V_31 ,
V_8 -> V_34 , V_8 -> V_35 ,
& V_2 , 1 , 0 ) ;
if ( V_30 == - V_36 )
V_30 = 0 ;
if ( V_30 < 0 ) {
F_34 ( V_2 ) ;
F_35 ( V_6 , V_2 ) ;
goto V_32;
}
if ( V_30 < V_23 )
F_36 ( V_2 , V_30 , V_23 ) ;
else
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
F_39 ( V_6 , V_2 ) ;
V_32:
return V_30 < 0 ? V_30 : 0 ;
}
static int F_40 ( struct V_25 * V_26 , struct V_2 * V_2 )
{
int V_37 = F_27 ( V_26 , V_2 ) ;
F_41 ( V_2 ) ;
return V_37 ;
}
static void F_42 ( struct V_38 * V_39 , struct V_40 * V_41 )
{
struct V_6 * V_6 = V_39 -> V_42 ;
struct V_43 * V_44 ;
int V_45 = V_39 -> V_46 ;
int V_47 = F_43 ( V_41 -> V_48 . V_49 ) ;
int V_50 ;
int V_51 ;
F_7 ( L_9 , V_6 , V_39 , V_45 , V_47 ) ;
V_44 = F_44 ( V_39 , 0 ) ;
F_8 ( V_44 -> type != V_52 ) ;
V_50 = F_45 ( ( T_2 ) V_44 -> V_53 ,
( T_2 ) V_44 -> V_22 ) ;
for ( V_51 = 0 ; V_51 < V_50 ; V_51 ++ ) {
struct V_2 * V_2 = V_44 -> V_54 [ V_51 ] ;
if ( V_45 < 0 )
goto V_55;
if ( V_47 < ( int ) V_23 ) {
int V_56 = V_47 < 0 ? 0 : V_47 ;
F_36 ( V_2 , V_56 , V_23 ) ;
}
F_7 ( L_10 , V_6 , V_2 ,
V_2 -> V_12 ) ;
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
F_39 ( V_6 , V_2 ) ;
V_55:
F_41 ( V_2 ) ;
F_46 ( V_2 ) ;
V_47 -= V_23 ;
}
F_47 ( V_44 -> V_54 ) ;
}
static void F_48 ( struct V_2 * * V_54 , int V_50 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_50 ; V_51 ++ )
F_41 ( V_54 [ V_51 ] ) ;
}
static int F_49 ( struct V_6 * V_6 , struct V_57 * V_58 , int V_59 )
{
struct V_27 * V_28 =
& F_29 ( V_6 ) -> V_29 -> V_28 ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_2 * V_2 = F_50 ( V_58 -> V_60 , struct V_2 , V_61 ) ;
struct F_32 V_62 ;
struct V_38 * V_39 ;
T_2 V_63 ;
T_2 V_31 ;
int V_51 ;
struct V_2 * * V_54 ;
T_3 V_64 ;
int V_65 = 0 ;
int V_10 ;
V_63 = ( T_2 ) F_33 ( V_2 ) ;
V_64 = V_2 -> V_12 ;
F_51 (page, page_list, lru) {
if ( V_2 -> V_12 != V_64 )
break;
V_65 ++ ;
V_64 ++ ;
if ( V_59 && V_65 == V_59 )
break;
}
V_31 = V_65 << V_66 ;
F_7 ( L_11 , V_6 , V_65 ,
V_63 , V_31 ) ;
V_62 = F_32 ( V_6 ) ;
V_39 = F_52 ( V_28 , & V_8 -> V_33 , V_62 , V_63 , & V_31 ,
1 , V_67 ,
V_68 , NULL ,
V_8 -> V_34 , V_8 -> V_35 ,
false ) ;
if ( F_53 ( V_39 ) )
return F_54 ( V_39 ) ;
V_65 = F_45 ( 0 , V_31 ) ;
V_54 = F_55 ( sizeof( * V_54 ) * V_65 , V_69 ) ;
V_10 = - V_70 ;
if ( ! V_54 )
goto V_32;
for ( V_51 = 0 ; V_51 < V_65 ; ++ V_51 ) {
V_2 = F_50 ( V_58 -> V_60 , struct V_2 , V_61 ) ;
F_8 ( F_17 ( V_2 ) ) ;
F_56 ( & V_2 -> V_61 ) ;
F_7 ( L_12 , V_6 , V_2 ,
V_2 -> V_12 ) ;
if ( F_57 ( V_2 , & V_6 -> V_71 , V_2 -> V_12 ,
V_69 ) ) {
F_58 ( V_6 , V_2 ) ;
F_46 ( V_2 ) ;
F_7 ( L_13 ,
V_6 , V_2 ) ;
V_65 = V_51 ;
goto V_72;
}
V_54 [ V_51 ] = V_2 ;
}
F_59 ( V_39 , 0 , V_54 , V_31 , 0 , false , false ) ;
V_39 -> V_73 = F_42 ;
V_39 -> V_42 = V_6 ;
F_60 ( V_39 , V_63 , NULL , V_62 . V_74 , NULL ) ;
F_7 ( L_14 , V_6 , V_39 , V_63 , V_31 ) ;
V_10 = F_61 ( V_28 , V_39 , false ) ;
if ( V_10 < 0 )
goto V_72;
F_62 ( V_39 ) ;
return V_65 ;
V_72:
F_48 ( V_54 , V_65 ) ;
F_63 ( V_54 , V_65 ) ;
V_32:
F_62 ( V_39 ) ;
return V_10 ;
}
static int F_64 ( struct V_25 * V_25 , struct V_4 * V_5 ,
struct V_57 * V_58 , unsigned V_65 )
{
struct V_6 * V_6 = F_28 ( V_25 ) ;
struct V_75 * V_76 = F_29 ( V_6 ) ;
int V_45 = 0 ;
int V_59 = 0 ;
V_45 = F_65 ( V_5 -> V_11 , V_5 , V_58 ,
& V_65 ) ;
if ( V_45 == 0 )
goto V_32;
if ( V_76 -> V_77 -> V_78 >= V_23 )
V_59 = ( V_76 -> V_77 -> V_78 + V_23 - 1 )
>> V_79 ;
F_7 ( L_15 , V_6 ,
V_25 , V_65 ,
V_59 ) ;
while ( ! F_66 ( V_58 ) ) {
V_45 = F_49 ( V_6 , V_58 , V_59 ) ;
if ( V_45 < 0 )
goto V_32;
F_8 ( V_45 == 0 ) ;
}
V_32:
F_67 ( V_6 , V_58 ) ;
F_7 ( L_16 , V_6 , V_25 , V_45 ) ;
return V_45 ;
}
static struct V_1 * F_68 ( struct V_6 * V_6 ,
T_2 * V_80 )
{
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_1 * V_9 = NULL ;
struct V_81 * V_82 = NULL ;
F_11 ( & V_8 -> V_15 ) ;
F_69 (capsnap, &ci->i_cap_snaps, ci_item) {
F_7 ( L_17 , V_82 ,
V_82 -> V_83 , V_82 -> V_84 ) ;
if ( V_82 -> V_84 ) {
V_9 = F_10 ( V_82 -> V_83 ) ;
if ( V_80 )
* V_80 = V_82 -> V_85 ;
break;
}
}
if ( ! V_9 && V_8 -> V_17 ) {
V_9 = F_10 ( V_8 -> V_16 ) ;
F_7 ( L_18 ,
V_9 , V_8 -> V_17 ) ;
}
F_13 ( & V_8 -> V_15 ) ;
return V_9 ;
}
static int F_70 ( struct V_2 * V_2 , struct V_86 * V_87 )
{
struct V_6 * V_6 ;
struct V_7 * V_8 ;
struct V_75 * V_76 ;
struct V_27 * V_28 ;
struct V_1 * V_9 , * V_88 ;
T_4 V_89 = F_33 ( V_2 ) ;
long V_90 ;
T_2 V_91 , V_80 = 0 ;
T_5 V_92 ;
int V_30 = 0 , V_31 = V_23 ;
F_7 ( L_19 , V_2 , V_2 -> V_12 ) ;
if ( ! V_2 -> V_5 || ! V_2 -> V_5 -> V_11 ) {
F_7 ( L_20 , V_2 ) ;
return - V_93 ;
}
V_6 = V_2 -> V_5 -> V_11 ;
V_8 = F_9 ( V_6 ) ;
V_76 = F_29 ( V_6 ) ;
V_28 = & V_76 -> V_29 -> V_28 ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 == NULL ) {
F_7 ( L_21 , V_6 , V_2 ) ;
goto V_32;
}
V_88 = F_68 ( V_6 , & V_80 ) ;
if ( V_9 -> V_19 > V_88 -> V_19 ) {
F_7 ( L_22 ,
V_6 , V_2 , V_9 ) ;
F_16 ( ( V_94 -> V_95 & V_96 ) == 0 ) ;
F_23 ( V_88 ) ;
goto V_32;
}
F_23 ( V_88 ) ;
F_11 ( & V_8 -> V_15 ) ;
V_92 = V_8 -> V_34 ;
V_91 = V_8 -> V_35 ;
if ( ! V_80 )
V_80 = F_71 ( V_6 ) ;
F_13 ( & V_8 -> V_15 ) ;
if ( V_89 >= V_80 ) {
F_7 ( L_23 , V_2 , V_80 ) ;
goto V_32;
}
if ( V_80 < V_89 + V_31 )
V_31 = V_80 - V_89 ;
F_7 ( L_24 ,
V_6 , V_2 , V_2 -> V_12 , V_89 , V_31 , V_9 ) ;
V_90 = F_72 ( & V_76 -> V_97 ) ;
if ( V_90 >
F_73 ( V_76 -> V_77 -> V_98 ) )
F_74 ( & V_76 -> V_99 , V_100 ) ;
F_39 ( V_6 , V_2 ) ;
F_75 ( V_2 ) ;
V_30 = F_76 ( V_28 , F_32 ( V_6 ) ,
& V_8 -> V_33 , V_9 ,
V_89 , V_31 ,
V_92 , V_91 ,
& V_6 -> V_101 , & V_2 , 1 ) ;
if ( V_30 < 0 ) {
F_7 ( L_25 , V_30 , V_2 ) ;
F_34 ( V_2 ) ;
F_77 ( & V_6 -> V_71 , V_30 ) ;
if ( V_87 )
V_87 -> V_102 ++ ;
} else {
F_7 ( L_26 , V_2 ) ;
V_30 = 0 ;
}
V_2 -> V_3 = 0 ;
F_24 ( V_2 ) ;
F_78 ( V_2 ) ;
F_22 ( V_8 , 1 , V_9 ) ;
F_23 ( V_9 ) ;
V_32:
return V_30 ;
}
static int F_79 ( struct V_2 * V_2 , struct V_86 * V_87 )
{
int V_30 ;
struct V_6 * V_6 = V_2 -> V_5 -> V_11 ;
F_8 ( ! V_6 ) ;
F_12 ( V_6 ) ;
V_30 = F_70 ( V_2 , V_87 ) ;
F_41 ( V_2 ) ;
F_80 ( V_6 ) ;
return V_30 ;
}
static void F_81 ( struct V_2 * * V_54 , int V_103 )
{
struct V_104 V_105 ;
int V_51 ;
F_82 ( & V_105 , 0 ) ;
for ( V_51 = 0 ; V_51 < V_103 ; V_51 ++ ) {
if ( F_83 ( & V_105 , V_54 [ V_51 ] ) == 0 )
F_84 ( & V_105 ) ;
}
F_84 ( & V_105 ) ;
}
static void F_85 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_6 * V_6 = V_39 -> V_42 ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_43 * V_44 ;
unsigned V_106 ;
struct V_2 * V_2 ;
int V_50 ;
int V_51 ;
struct V_1 * V_9 = V_39 -> V_107 ;
struct V_4 * V_5 = V_6 -> V_108 ;
int V_45 = V_39 -> V_46 ;
T_2 V_47 = V_39 -> V_109 [ 0 ] . V_110 . V_22 ;
struct V_75 * V_76 = F_29 ( V_6 ) ;
long V_90 ;
unsigned V_111 = F_86 ( V_8 ) ;
V_44 = F_44 ( V_39 , 0 ) ;
F_8 ( V_44 -> type != V_52 ) ;
V_50 = F_45 ( ( T_2 ) V_44 -> V_53 ,
( T_2 ) V_44 -> V_22 ) ;
if ( V_45 >= 0 ) {
V_106 = V_50 ;
} else {
V_106 = 0 ;
F_77 ( V_5 , V_45 ) ;
}
F_7 ( L_27 ,
V_6 , V_45 , V_47 , V_106 ) ;
for ( V_51 = 0 ; V_51 < V_50 ; V_51 ++ ) {
V_2 = V_44 -> V_54 [ V_51 ] ;
F_8 ( ! V_2 ) ;
F_16 ( ! F_87 ( V_2 ) ) ;
V_90 =
F_88 ( & V_76 -> V_97 ) ;
if ( V_90 <
F_89 ( V_76 -> V_77 -> V_98 ) )
F_90 ( & V_76 -> V_99 ,
V_100 ) ;
F_23 ( F_1 ( V_2 ) ) ;
V_2 -> V_3 = 0 ;
F_24 ( V_2 ) ;
F_7 ( L_28 , V_51 , V_2 ) ;
F_78 ( V_2 ) ;
if ( ( V_111 & ( V_112 | V_113 ) ) == 0 )
F_91 ( V_6 -> V_108 , V_2 ) ;
F_41 ( V_2 ) ;
}
F_7 ( L_29 , V_6 , V_106 ) ;
F_22 ( V_8 , V_50 , V_9 ) ;
F_81 ( V_44 -> V_54 , V_50 ) ;
if ( V_44 -> V_114 )
F_92 ( V_44 -> V_54 ,
F_93 ( V_6 -> V_115 ) -> V_116 ) ;
else
F_47 ( V_44 -> V_54 ) ;
F_62 ( V_39 ) ;
}
static int F_94 ( struct V_4 * V_5 ,
struct V_86 * V_87 )
{
struct V_6 * V_6 = V_5 -> V_11 ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_75 * V_76 = F_29 ( V_6 ) ;
struct F_32 V_62 = F_32 ( V_6 ) ;
T_3 V_12 , V_117 , V_118 ;
int V_119 = 0 ;
int V_120 = 1 ;
T_3 V_121 = 0 , V_122 = 0 ;
struct V_1 * V_9 = NULL , * V_123 = NULL , * V_124 ;
struct V_104 V_105 ;
int V_125 = 0 ;
int V_45 = 0 ;
unsigned V_126 = 1 << V_6 -> V_127 ;
struct V_38 * V_39 = NULL ;
int V_128 ;
T_2 V_91 , V_80 ;
T_5 V_92 ;
if ( ( V_87 -> V_129 == V_130 ) ||
F_95 ( V_8 , V_131 ) )
V_128 = 1 ;
F_7 ( L_30 ,
V_6 , V_128 ,
V_87 -> V_129 == V_132 ? L_31 :
( V_87 -> V_129 == V_130 ? L_32 : L_33 ) ) ;
if ( V_76 -> V_133 == V_134 ) {
F_96 ( L_34 , V_6 ) ;
return - V_135 ;
}
if ( V_76 -> V_77 -> V_126 && V_76 -> V_77 -> V_126 < V_126 )
V_126 = V_76 -> V_77 -> V_126 ;
if ( V_126 < V_23 )
V_126 = V_23 ;
V_122 = V_126 >> V_66 ;
F_82 ( & V_105 , 0 ) ;
if ( V_87 -> V_136 ) {
V_117 = V_5 -> V_137 ;
V_118 = - 1 ;
F_7 ( L_35 , V_117 ) ;
} else {
V_117 = V_87 -> V_138 >> V_66 ;
V_118 = V_87 -> V_139 >> V_66 ;
if ( V_87 -> V_138 == 0 && V_87 -> V_139 == V_140 )
V_119 = 1 ;
V_120 = 0 ;
F_7 ( L_36 , V_117 , V_118 ) ;
}
V_12 = V_117 ;
V_141:
F_23 ( V_9 ) ;
V_80 = 0 ;
V_9 = F_68 ( V_6 , & V_80 ) ;
if ( ! V_9 ) {
F_7 ( L_37 ) ;
goto V_32;
}
if ( V_80 == 0 )
V_80 = F_71 ( V_6 ) ;
F_7 ( L_38 ,
V_9 , V_9 -> V_19 , V_9 -> V_20 ) ;
F_11 ( & V_8 -> V_15 ) ;
V_92 = V_8 -> V_34 ;
V_91 = V_8 -> V_35 ;
if ( ! V_80 )
V_80 = F_71 ( V_6 ) ;
F_13 ( & V_8 -> V_15 ) ;
if ( V_123 && V_9 != V_123 ) {
F_7 ( L_39 ,
V_12 ) ;
V_12 = V_117 ;
}
V_123 = V_9 ;
while ( ! V_125 && V_12 <= V_118 ) {
int V_142 = V_128 ? 2 : 1 ;
unsigned V_51 ;
int V_143 ;
T_3 V_144 ;
int V_145 , V_146 ;
struct V_2 * * V_54 = NULL ;
T_6 * V_147 = NULL ;
struct V_2 * V_2 ;
int V_148 ;
T_2 V_21 , V_31 ;
long V_90 ;
V_144 = 0 ;
V_146 = 0 ;
V_121 = V_122 ;
V_149:
V_143 = - 1 ;
V_148 = F_97 ( V_118 - V_12 ,
F_97 ( ( T_3 ) V_150 ,
V_121 - ( T_3 ) V_146 ) - 1 )
+ 1 ;
V_145 = F_98 ( & V_105 , V_5 , & V_12 ,
V_151 ,
V_148 ) ;
F_7 ( L_40 , V_145 ) ;
if ( ! V_145 && ! V_146 )
break;
for ( V_51 = 0 ; V_51 < V_145 && V_146 < V_121 ; V_51 ++ ) {
V_2 = V_105 . V_54 [ V_51 ] ;
F_7 ( L_41 , V_2 , V_2 -> V_12 ) ;
if ( V_146 == 0 )
F_99 ( V_2 ) ;
else if ( ! F_100 ( V_2 ) )
break;
if ( F_4 ( ! F_6 ( V_2 ) ) ||
F_4 ( V_2 -> V_5 != V_5 ) ) {
F_7 ( L_42 , V_2 ) ;
F_41 ( V_2 ) ;
break;
}
if ( ! V_87 -> V_136 && V_2 -> V_12 > V_118 ) {
F_7 ( L_43 , V_2 ) ;
V_125 = 1 ;
F_41 ( V_2 ) ;
break;
}
if ( V_144 && ( V_2 -> V_12 != V_144 ) ) {
F_7 ( L_44 , V_2 ) ;
F_41 ( V_2 ) ;
break;
}
if ( V_87 -> V_129 != V_132 ) {
F_7 ( L_45 , V_2 ) ;
F_101 ( V_2 ) ;
}
if ( F_33 ( V_2 ) >= V_80 ) {
F_7 ( L_23 , V_2 , V_80 ) ;
V_125 = 1 ;
F_41 ( V_2 ) ;
break;
}
if ( F_102 ( V_2 ) ) {
F_7 ( L_46 , V_2 ) ;
F_41 ( V_2 ) ;
break;
}
V_124 = F_1 ( V_2 ) ;
if ( V_124 -> V_19 > V_9 -> V_19 ) {
F_7 ( L_47 ,
V_124 , V_124 -> V_19 , V_9 , V_9 -> V_19 ) ;
F_41 ( V_2 ) ;
if ( ! V_146 )
continue;
break;
}
if ( ! F_103 ( V_2 ) ) {
F_7 ( L_48 , V_2 ) ;
F_41 ( V_2 ) ;
break;
}
if ( V_146 == 0 ) {
F_8 ( V_54 ) ;
V_21 = ( T_2 ) F_33 ( V_2 ) ;
V_31 = V_126 ;
V_39 = F_52 ( & V_76 -> V_29 -> V_28 ,
& V_8 -> V_33 , V_62 ,
V_21 , & V_31 , V_142 ,
V_152 ,
V_153 |
V_154 ,
V_9 , V_92 ,
V_91 , true ) ;
if ( F_53 ( V_39 ) ) {
V_45 = F_54 ( V_39 ) ;
F_41 ( V_2 ) ;
break;
}
V_39 -> V_73 = F_85 ;
V_39 -> V_42 = V_6 ;
V_121 = F_45 ( 0 , ( T_2 ) V_31 ) ;
V_54 = F_55 ( V_121 * sizeof ( * V_54 ) ,
V_69 ) ;
if ( ! V_54 ) {
V_147 = V_76 -> V_116 ;
V_54 = F_104 ( V_147 , V_69 ) ;
F_8 ( ! V_54 ) ;
}
}
if ( V_143 < 0 )
V_143 = V_51 ;
F_7 ( L_49 ,
V_6 , V_2 , V_2 -> V_12 ) ;
V_90 =
F_72 ( & V_76 -> V_97 ) ;
if ( V_90 > F_73 (
V_76 -> V_77 -> V_98 ) ) {
F_74 ( & V_76 -> V_99 ,
V_100 ) ;
}
F_75 ( V_2 ) ;
V_54 [ V_146 ] = V_2 ;
V_146 ++ ;
V_144 = V_2 -> V_12 + 1 ;
}
if ( ! V_146 )
goto V_155;
if ( V_51 ) {
int V_156 ;
F_8 ( ! V_146 || V_143 < 0 ) ;
if ( V_145 && V_51 == V_145 &&
V_146 < V_121 ) {
F_7 ( L_50 ) ;
F_105 ( & V_105 ) ;
goto V_149;
}
for ( V_156 = V_51 ; V_156 < V_145 ; V_156 ++ ) {
F_7 ( L_51 ,
V_105 . V_54 [ V_156 ] ) ;
V_105 . V_54 [ V_156 - V_51 + V_143 ] = V_105 . V_54 [ V_156 ] ;
}
V_105 . V_157 -= V_51 - V_143 ;
}
V_21 = F_33 ( V_54 [ 0 ] ) ;
V_31 = F_97 ( V_80 - V_21 ,
( T_2 ) V_146 << V_66 ) ;
F_7 ( L_52 ,
V_146 , V_21 , V_31 ) ;
F_59 ( V_39 , 0 , V_54 , V_31 , 0 ,
! ! V_147 , false ) ;
V_54 = NULL ;
V_147 = NULL ;
F_106 ( V_39 , 0 , V_31 ) ;
V_62 = F_32 ( V_6 ) ;
F_60 ( V_39 , V_21 , V_9 , V_62 . V_74 ,
& V_6 -> V_101 ) ;
V_45 = F_61 ( & V_76 -> V_29 -> V_28 , V_39 , true ) ;
F_8 ( V_45 ) ;
V_39 = NULL ;
V_12 = V_144 ;
V_87 -> V_158 -= V_146 ;
if ( V_87 -> V_158 <= 0 )
V_125 = 1 ;
V_155:
F_7 ( L_53 , ( int ) V_105 . V_157 ,
V_105 . V_157 ? V_105 . V_54 [ 0 ] : NULL ) ;
F_84 ( & V_105 ) ;
if ( V_146 && ! V_125 )
goto V_141;
}
if ( V_120 && ! V_125 ) {
F_7 ( L_54 ) ;
V_120 = 0 ;
V_12 = 0 ;
goto V_141;
}
if ( V_87 -> V_136 || ( V_119 && V_87 -> V_158 > 0 ) )
V_5 -> V_137 = V_12 ;
V_32:
if ( V_39 )
F_62 ( V_39 ) ;
F_23 ( V_9 ) ;
F_7 ( L_55 , V_45 ) ;
return V_45 ;
}
static int F_107 ( struct V_6 * V_6 ,
struct V_1 * V_9 )
{
struct V_1 * V_88 = F_68 ( V_6 , NULL ) ;
int V_10 = ! V_88 || V_9 -> V_19 <= V_88 -> V_19 ;
F_23 ( V_88 ) ;
return V_10 ;
}
static int F_108 ( struct V_25 * V_25 ,
T_4 V_159 , unsigned V_31 ,
struct V_2 * V_2 )
{
struct V_6 * V_6 = F_28 ( V_25 ) ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_160 * V_161 = F_29 ( V_6 ) -> V_161 ;
T_4 V_89 = V_159 & V_162 ;
int V_163 = V_159 & ~ V_162 ;
int V_164 = V_163 + V_31 ;
T_4 V_165 ;
int V_37 ;
struct V_1 * V_9 , * V_88 ;
V_166:
F_101 ( V_2 ) ;
F_8 ( ! V_8 -> V_13 ) ;
F_109 ( & V_161 -> V_167 ) ;
F_8 ( ! V_8 -> V_13 -> V_14 ) ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 && V_9 != V_8 -> V_16 ) {
V_88 = F_68 ( V_6 , NULL ) ;
F_110 ( & V_161 -> V_167 ) ;
if ( V_9 -> V_19 > V_88 -> V_19 ) {
F_23 ( V_88 ) ;
F_7 ( L_56 ,
V_2 , V_9 ) ;
V_9 = F_10 ( V_9 ) ;
F_41 ( V_2 ) ;
F_111 ( V_6 ) ;
V_37 = F_112 ( V_8 -> V_168 ,
F_107 ( V_6 , V_9 ) ) ;
F_23 ( V_9 ) ;
if ( V_37 == - V_169 )
return V_37 ;
return - V_170 ;
}
F_23 ( V_88 ) ;
F_7 ( L_57 ,
V_2 , V_9 ) ;
if ( ! F_103 ( V_2 ) )
goto V_166;
V_37 = F_70 ( V_2 , NULL ) ;
if ( V_37 < 0 )
goto V_171;
goto V_166;
}
if ( F_87 ( V_2 ) ) {
F_7 ( L_58 , V_2 ) ;
return 0 ;
}
if ( V_163 == 0 && V_31 == V_23 )
return 0 ;
V_165 = V_6 -> V_165 ;
if ( V_89 >= V_165 ||
( V_163 == 0 && ( V_159 + V_31 ) >= V_165 &&
V_164 - V_163 != V_23 ) ) {
F_7 ( L_59 ,
V_2 , V_163 , V_164 , ( int ) V_23 ) ;
F_113 ( V_2 ,
0 , V_163 ,
V_164 , V_23 ) ;
return 0 ;
}
F_110 ( & V_161 -> V_167 ) ;
V_37 = F_27 ( V_25 , V_2 ) ;
if ( V_37 < 0 )
goto V_171;
goto V_166;
V_171:
F_41 ( V_2 ) ;
return V_37 ;
}
static int F_114 ( struct V_25 * V_25 , struct V_4 * V_5 ,
T_4 V_159 , unsigned V_31 , unsigned V_95 ,
struct V_2 * * V_172 , void * * V_173 )
{
struct V_6 * V_6 = F_28 ( V_25 ) ;
struct V_2 * V_2 ;
T_3 V_12 = V_159 >> V_66 ;
int V_37 ;
do {
V_2 = F_115 ( V_5 , V_12 , 0 ) ;
if ( ! V_2 )
return - V_70 ;
* V_172 = V_2 ;
F_7 ( L_60 , V_25 ,
V_6 , V_2 , ( int ) V_159 , ( int ) V_31 ) ;
V_37 = F_108 ( V_25 , V_159 , V_31 , V_2 ) ;
} while ( V_37 == - V_170 );
return V_37 ;
}
static int F_116 ( struct V_25 * V_25 , struct V_4 * V_5 ,
T_4 V_159 , unsigned V_31 , unsigned V_174 ,
struct V_2 * V_2 , void * V_173 )
{
struct V_6 * V_6 = F_28 ( V_25 ) ;
struct V_75 * V_76 = F_29 ( V_6 ) ;
struct V_160 * V_161 = V_76 -> V_161 ;
unsigned V_175 = V_159 & ( V_23 - 1 ) ;
int V_176 = 0 ;
F_7 ( L_61 , V_25 ,
V_6 , V_2 , ( int ) V_159 , ( int ) V_174 , ( int ) V_31 ) ;
if ( V_174 < V_31 )
F_36 ( V_2 , V_175 + V_174 , V_31 ) ;
if ( V_159 + V_174 > V_6 -> V_165 )
V_176 = F_117 ( V_6 , V_159 + V_174 ) ;
if ( ! F_87 ( V_2 ) )
F_38 ( V_2 ) ;
F_118 ( V_2 ) ;
F_41 ( V_2 ) ;
F_110 ( & V_161 -> V_167 ) ;
F_46 ( V_2 ) ;
if ( V_176 )
F_119 ( F_9 ( V_6 ) , V_177 , NULL ) ;
return V_174 ;
}
static T_7 F_120 ( int V_178 , struct V_179 * V_180 ,
struct V_181 * V_182 ,
T_4 V_159 )
{
F_16 ( 1 ) ;
return - V_183 ;
}
static int F_121 ( struct V_184 * V_185 , struct V_186 * V_187 )
{
struct V_6 * V_6 = F_28 ( V_185 -> V_188 ) ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_189 * V_190 = V_185 -> V_188 -> V_191 ;
T_4 V_63 = V_187 -> V_192 << V_66 ;
int V_148 , V_193 , V_10 ;
F_7 ( L_62 ,
V_6 , F_122 ( V_6 ) , V_63 , ( V_194 ) V_23 ) ;
if ( V_190 -> V_195 & V_196 )
V_148 = V_112 | V_113 ;
else
V_148 = V_112 ;
while ( 1 ) {
V_193 = 0 ;
V_10 = F_123 ( V_8 , V_197 , V_148 , & V_193 , - 1 ) ;
if ( V_10 == 0 )
break;
if ( V_10 != - V_169 ) {
F_16 ( 1 ) ;
return V_198 ;
}
}
F_7 ( L_63 ,
V_6 , V_63 , ( V_194 ) V_23 , F_124 ( V_193 ) ) ;
V_10 = F_125 ( V_185 , V_187 ) ;
F_7 ( L_64 ,
V_6 , V_63 , ( V_194 ) V_23 , F_124 ( V_193 ) , V_10 ) ;
F_126 ( V_8 , V_193 ) ;
return V_10 ;
}
static int F_127 ( struct V_184 * V_185 , struct V_186 * V_187 )
{
struct V_6 * V_6 = F_28 ( V_185 -> V_188 ) ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_189 * V_190 = V_185 -> V_188 -> V_191 ;
struct V_160 * V_161 = F_29 ( V_6 ) -> V_161 ;
struct V_2 * V_2 = V_187 -> V_2 ;
T_4 V_63 = F_33 ( V_2 ) ;
T_4 V_85 = F_71 ( V_6 ) ;
V_194 V_31 ;
int V_148 , V_193 , V_10 ;
if ( V_63 + V_23 <= V_85 )
V_31 = V_23 ;
else
V_31 = V_85 & ~ V_162 ;
F_7 ( L_65 ,
V_6 , F_122 ( V_6 ) , V_63 , V_31 , V_85 ) ;
if ( V_190 -> V_195 & V_196 )
V_148 = V_131 | V_113 ;
else
V_148 = V_131 ;
while ( 1 ) {
V_193 = 0 ;
V_10 = F_123 ( V_8 , V_199 , V_148 , & V_193 , V_63 + V_31 ) ;
if ( V_10 == 0 )
break;
if ( V_10 != - V_169 ) {
F_16 ( 1 ) ;
return V_198 ;
}
}
F_7 ( L_66 ,
V_6 , V_63 , V_31 , F_124 ( V_193 ) ) ;
F_128 ( V_185 -> V_188 ) ;
F_99 ( V_2 ) ;
V_10 = V_200 ;
if ( ( V_63 > V_85 ) ||
( V_2 -> V_5 != V_6 -> V_108 ) )
goto V_32;
V_10 = F_108 ( V_185 -> V_188 , V_63 , V_31 , V_2 ) ;
if ( V_10 == 0 ) {
F_118 ( V_2 ) ;
F_110 ( & V_161 -> V_167 ) ;
V_10 = V_201 ;
} else {
if ( V_10 == - V_70 )
V_10 = V_202 ;
else
V_10 = V_198 ;
}
V_32:
if ( V_10 != V_201 ) {
F_41 ( V_2 ) ;
} else {
int V_203 ;
F_11 ( & V_8 -> V_15 ) ;
V_203 = F_129 ( V_8 , V_199 ) ;
F_13 ( & V_8 -> V_15 ) ;
if ( V_203 )
F_130 ( V_6 , V_203 ) ;
}
F_7 ( L_67 ,
V_6 , V_63 , V_31 , F_124 ( V_193 ) , V_10 ) ;
F_126 ( V_8 , V_193 ) ;
return V_10 ;
}
int F_131 ( struct V_25 * V_25 , struct V_184 * V_185 )
{
struct V_4 * V_5 = V_25 -> V_204 ;
if ( ! V_5 -> V_205 -> V_206 )
return - V_207 ;
F_132 ( V_25 ) ;
V_185 -> V_208 = & V_209 ;
return 0 ;
}
