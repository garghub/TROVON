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
goto V_32;
} else if ( V_30 < V_23 ) {
F_35 ( V_2 , V_30 , V_23 ) ;
}
F_36 ( V_2 ) ;
if ( V_30 == 0 )
F_37 ( V_6 , V_2 ) ;
V_32:
return V_30 < 0 ? V_30 : 0 ;
}
static int F_38 ( struct V_25 * V_26 , struct V_2 * V_2 )
{
int V_37 = F_27 ( V_26 , V_2 ) ;
F_39 ( V_2 ) ;
return V_37 ;
}
static void F_40 ( struct V_38 * V_39 , struct V_40 * V_41 )
{
struct V_6 * V_6 = V_39 -> V_42 ;
struct V_43 * V_44 ;
int V_45 = V_39 -> V_46 ;
int V_47 = F_41 ( V_41 -> V_48 . V_49 ) ;
int V_50 ;
int V_51 ;
F_7 ( L_9 , V_6 , V_39 , V_45 , V_47 ) ;
V_44 = F_42 ( V_39 , 0 ) ;
F_8 ( V_44 -> type != V_52 ) ;
V_50 = F_43 ( ( T_2 ) V_44 -> V_53 ,
( T_2 ) V_44 -> V_22 ) ;
for ( V_51 = 0 ; V_51 < V_50 ; V_51 ++ ) {
struct V_2 * V_2 = V_44 -> V_54 [ V_51 ] ;
if ( V_47 < ( int ) V_23 ) {
int V_55 = V_47 < 0 ? 0 : V_47 ;
F_35 ( V_2 , V_55 , V_23 ) ;
}
F_7 ( L_10 , V_6 , V_2 ,
V_2 -> V_12 ) ;
F_44 ( V_2 ) ;
F_36 ( V_2 ) ;
F_37 ( V_6 , V_2 ) ;
F_39 ( V_2 ) ;
F_45 ( V_2 ) ;
V_47 -= V_23 ;
}
F_46 ( V_44 -> V_54 ) ;
}
static void F_47 ( struct V_2 * * V_54 , int V_50 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_50 ; V_51 ++ )
F_39 ( V_54 [ V_51 ] ) ;
}
static int F_48 ( struct V_6 * V_6 , struct V_56 * V_57 , int V_58 )
{
struct V_27 * V_28 =
& F_29 ( V_6 ) -> V_29 -> V_28 ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_2 * V_2 = F_49 ( V_57 -> V_59 , struct V_2 , V_60 ) ;
struct F_32 V_61 ;
struct V_38 * V_39 ;
T_2 V_62 ;
T_2 V_31 ;
int V_51 ;
struct V_2 * * V_54 ;
T_3 V_63 ;
int V_64 = 0 ;
int V_10 ;
V_62 = ( T_2 ) F_33 ( V_2 ) ;
V_63 = V_2 -> V_12 ;
F_50 (page, page_list, lru) {
if ( V_2 -> V_12 != V_63 )
break;
V_64 ++ ;
V_63 ++ ;
if ( V_58 && V_64 == V_58 )
break;
}
V_31 = V_64 << V_65 ;
F_7 ( L_11 , V_6 , V_64 ,
V_62 , V_31 ) ;
V_61 = F_32 ( V_6 ) ;
V_39 = F_51 ( V_28 , & V_8 -> V_33 , V_61 , V_62 , & V_31 ,
1 , V_66 ,
V_67 , NULL ,
V_8 -> V_34 , V_8 -> V_35 ,
false ) ;
if ( F_52 ( V_39 ) )
return F_53 ( V_39 ) ;
V_64 = F_43 ( 0 , V_31 ) ;
V_54 = F_54 ( sizeof( * V_54 ) * V_64 , V_68 ) ;
V_10 = - V_69 ;
if ( ! V_54 )
goto V_32;
for ( V_51 = 0 ; V_51 < V_64 ; ++ V_51 ) {
V_2 = F_49 ( V_57 -> V_59 , struct V_2 , V_60 ) ;
F_8 ( F_17 ( V_2 ) ) ;
F_55 ( & V_2 -> V_60 ) ;
F_7 ( L_12 , V_6 , V_2 ,
V_2 -> V_12 ) ;
if ( F_56 ( V_2 , & V_6 -> V_70 , V_2 -> V_12 ,
V_68 ) ) {
F_57 ( V_6 , V_2 ) ;
F_45 ( V_2 ) ;
F_7 ( L_13 ,
V_6 , V_2 ) ;
V_64 = V_51 ;
goto V_71;
}
V_54 [ V_51 ] = V_2 ;
}
F_58 ( V_39 , 0 , V_54 , V_31 , 0 , false , false ) ;
V_39 -> V_72 = F_40 ;
V_39 -> V_42 = V_6 ;
F_59 ( V_39 , V_62 , NULL , V_61 . V_73 , NULL ) ;
F_7 ( L_14 , V_6 , V_39 , V_62 , V_31 ) ;
V_10 = F_60 ( V_28 , V_39 , false ) ;
if ( V_10 < 0 )
goto V_71;
F_61 ( V_39 ) ;
return V_64 ;
V_71:
F_47 ( V_54 , V_64 ) ;
F_62 ( V_54 , V_64 ) ;
V_32:
F_61 ( V_39 ) ;
return V_10 ;
}
static int F_63 ( struct V_25 * V_25 , struct V_4 * V_5 ,
struct V_56 * V_57 , unsigned V_64 )
{
struct V_6 * V_6 = F_28 ( V_25 ) ;
struct V_74 * V_75 = F_29 ( V_6 ) ;
int V_45 = 0 ;
int V_58 = 0 ;
V_45 = F_64 ( V_5 -> V_11 , V_5 , V_57 ,
& V_64 ) ;
if ( V_45 == 0 )
goto V_32;
if ( V_75 -> V_76 -> V_77 >= V_23 )
V_58 = ( V_75 -> V_76 -> V_77 + V_23 - 1 )
>> V_78 ;
F_7 ( L_15 , V_6 ,
V_25 , V_64 ,
V_58 ) ;
while ( ! F_65 ( V_57 ) ) {
V_45 = F_48 ( V_6 , V_57 , V_58 ) ;
if ( V_45 < 0 )
goto V_32;
F_8 ( V_45 == 0 ) ;
}
V_32:
F_66 ( V_6 , V_57 ) ;
F_7 ( L_16 , V_6 , V_25 , V_45 ) ;
return V_45 ;
}
static struct V_1 * F_67 ( struct V_6 * V_6 ,
T_2 * V_79 )
{
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_1 * V_9 = NULL ;
struct V_80 * V_81 = NULL ;
F_11 ( & V_8 -> V_15 ) ;
F_68 (capsnap, &ci->i_cap_snaps, ci_item) {
F_7 ( L_17 , V_81 ,
V_81 -> V_82 , V_81 -> V_83 ) ;
if ( V_81 -> V_83 ) {
V_9 = F_10 ( V_81 -> V_82 ) ;
if ( V_79 )
* V_79 = V_81 -> V_84 ;
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
static int F_69 ( struct V_2 * V_2 , struct V_85 * V_86 )
{
struct V_6 * V_6 ;
struct V_7 * V_8 ;
struct V_74 * V_75 ;
struct V_27 * V_28 ;
struct V_1 * V_9 , * V_87 ;
T_4 V_88 = F_33 ( V_2 ) ;
long V_89 ;
T_2 V_90 , V_79 = 0 ;
T_5 V_91 ;
int V_30 = 0 , V_31 = V_23 ;
F_7 ( L_19 , V_2 , V_2 -> V_12 ) ;
if ( ! V_2 -> V_5 || ! V_2 -> V_5 -> V_11 ) {
F_7 ( L_20 , V_2 ) ;
return - V_92 ;
}
V_6 = V_2 -> V_5 -> V_11 ;
V_8 = F_9 ( V_6 ) ;
V_75 = F_29 ( V_6 ) ;
V_28 = & V_75 -> V_29 -> V_28 ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 == NULL ) {
F_7 ( L_21 , V_6 , V_2 ) ;
goto V_32;
}
V_87 = F_67 ( V_6 , & V_79 ) ;
if ( V_9 -> V_19 > V_87 -> V_19 ) {
F_7 ( L_22 ,
V_6 , V_2 , V_9 ) ;
F_16 ( ( V_93 -> V_94 & V_95 ) == 0 ) ;
F_23 ( V_87 ) ;
goto V_32;
}
F_23 ( V_87 ) ;
F_11 ( & V_8 -> V_15 ) ;
V_91 = V_8 -> V_34 ;
V_90 = V_8 -> V_35 ;
if ( ! V_79 )
V_79 = F_70 ( V_6 ) ;
F_13 ( & V_8 -> V_15 ) ;
if ( V_88 >= V_79 ) {
F_7 ( L_23 , V_2 , V_79 ) ;
goto V_32;
}
if ( V_79 < V_88 + V_31 )
V_31 = V_79 - V_88 ;
F_7 ( L_24 ,
V_6 , V_2 , V_2 -> V_12 , V_88 , V_31 , V_9 ) ;
V_89 = F_71 ( & V_75 -> V_96 ) ;
if ( V_89 >
F_72 ( V_75 -> V_76 -> V_97 ) )
F_73 ( & V_75 -> V_98 , V_99 ) ;
F_37 ( V_6 , V_2 ) ;
F_74 ( V_2 ) ;
V_30 = F_75 ( V_28 , F_32 ( V_6 ) ,
& V_8 -> V_33 , V_9 ,
V_88 , V_31 ,
V_91 , V_90 ,
& V_6 -> V_100 , & V_2 , 1 ) ;
if ( V_30 < 0 ) {
F_7 ( L_25 , V_30 , V_2 ) ;
F_34 ( V_2 ) ;
F_76 ( & V_6 -> V_70 , V_30 ) ;
if ( V_86 )
V_86 -> V_101 ++ ;
} else {
F_7 ( L_26 , V_2 ) ;
V_30 = 0 ;
}
V_2 -> V_3 = 0 ;
F_24 ( V_2 ) ;
F_77 ( V_2 ) ;
F_22 ( V_8 , 1 , V_9 ) ;
F_23 ( V_9 ) ;
V_32:
return V_30 ;
}
static int F_78 ( struct V_2 * V_2 , struct V_85 * V_86 )
{
int V_30 ;
struct V_6 * V_6 = V_2 -> V_5 -> V_11 ;
F_8 ( ! V_6 ) ;
F_12 ( V_6 ) ;
V_30 = F_69 ( V_2 , V_86 ) ;
F_39 ( V_2 ) ;
F_79 ( V_6 ) ;
return V_30 ;
}
static void F_80 ( struct V_2 * * V_54 , int V_102 )
{
struct V_103 V_104 ;
int V_51 ;
F_81 ( & V_104 , 0 ) ;
for ( V_51 = 0 ; V_51 < V_102 ; V_51 ++ ) {
if ( F_82 ( & V_104 , V_54 [ V_51 ] ) == 0 )
F_83 ( & V_104 ) ;
}
F_83 ( & V_104 ) ;
}
static void F_84 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_6 * V_6 = V_39 -> V_42 ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_43 * V_44 ;
unsigned V_105 ;
struct V_2 * V_2 ;
int V_50 ;
int V_51 ;
struct V_1 * V_9 = V_39 -> V_106 ;
struct V_4 * V_5 = V_6 -> V_107 ;
int V_45 = V_39 -> V_46 ;
T_2 V_47 = V_39 -> V_108 [ 0 ] . V_109 . V_22 ;
struct V_74 * V_75 = F_29 ( V_6 ) ;
long V_89 ;
unsigned V_110 = F_85 ( V_8 ) ;
V_44 = F_42 ( V_39 , 0 ) ;
F_8 ( V_44 -> type != V_52 ) ;
V_50 = F_43 ( ( T_2 ) V_44 -> V_53 ,
( T_2 ) V_44 -> V_22 ) ;
if ( V_45 >= 0 ) {
V_105 = V_50 ;
} else {
V_105 = 0 ;
F_76 ( V_5 , V_45 ) ;
}
F_7 ( L_27 ,
V_6 , V_45 , V_47 , V_105 ) ;
for ( V_51 = 0 ; V_51 < V_50 ; V_51 ++ ) {
V_2 = V_44 -> V_54 [ V_51 ] ;
F_8 ( ! V_2 ) ;
F_16 ( ! F_86 ( V_2 ) ) ;
V_89 =
F_87 ( & V_75 -> V_96 ) ;
if ( V_89 <
F_88 ( V_75 -> V_76 -> V_97 ) )
F_89 ( & V_75 -> V_98 ,
V_99 ) ;
F_23 ( F_1 ( V_2 ) ) ;
V_2 -> V_3 = 0 ;
F_24 ( V_2 ) ;
F_7 ( L_28 , V_51 , V_2 ) ;
F_77 ( V_2 ) ;
if ( ( V_110 & ( V_111 | V_112 ) ) == 0 )
F_90 ( V_6 -> V_107 , V_2 ) ;
F_39 ( V_2 ) ;
}
F_7 ( L_29 , V_6 , V_105 ) ;
F_22 ( V_8 , V_50 , V_9 ) ;
F_80 ( V_44 -> V_54 , V_50 ) ;
if ( V_44 -> V_113 )
F_91 ( V_44 -> V_54 ,
F_92 ( V_6 -> V_114 ) -> V_115 ) ;
else
F_46 ( V_44 -> V_54 ) ;
F_61 ( V_39 ) ;
}
static int F_93 ( struct V_4 * V_5 ,
struct V_85 * V_86 )
{
struct V_6 * V_6 = V_5 -> V_11 ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_74 * V_75 = F_29 ( V_6 ) ;
struct F_32 V_61 = F_32 ( V_6 ) ;
T_3 V_12 , V_116 , V_117 ;
int V_118 = 0 ;
int V_119 = 1 ;
T_3 V_120 = 0 , V_121 = 0 ;
struct V_1 * V_9 = NULL , * V_122 = NULL , * V_123 ;
struct V_103 V_104 ;
int V_124 = 0 ;
int V_45 = 0 ;
unsigned V_125 = 1 << V_6 -> V_126 ;
struct V_38 * V_39 = NULL ;
int V_127 ;
T_2 V_90 , V_79 ;
T_5 V_91 ;
if ( ( V_86 -> V_128 == V_129 ) ||
F_94 ( V_8 , V_130 ) )
V_127 = 1 ;
F_7 ( L_30 ,
V_6 , V_127 ,
V_86 -> V_128 == V_131 ? L_31 :
( V_86 -> V_128 == V_129 ? L_32 : L_33 ) ) ;
if ( V_75 -> V_132 == V_133 ) {
F_95 ( L_34 , V_6 ) ;
return - V_134 ;
}
if ( V_75 -> V_76 -> V_125 && V_75 -> V_76 -> V_125 < V_125 )
V_125 = V_75 -> V_76 -> V_125 ;
if ( V_125 < V_23 )
V_125 = V_23 ;
V_121 = V_125 >> V_65 ;
F_81 ( & V_104 , 0 ) ;
if ( V_86 -> V_135 ) {
V_116 = V_5 -> V_136 ;
V_117 = - 1 ;
F_7 ( L_35 , V_116 ) ;
} else {
V_116 = V_86 -> V_137 >> V_65 ;
V_117 = V_86 -> V_138 >> V_65 ;
if ( V_86 -> V_137 == 0 && V_86 -> V_138 == V_139 )
V_118 = 1 ;
V_119 = 0 ;
F_7 ( L_36 , V_116 , V_117 ) ;
}
V_12 = V_116 ;
V_140:
F_23 ( V_9 ) ;
V_79 = 0 ;
V_9 = F_67 ( V_6 , & V_79 ) ;
if ( ! V_9 ) {
F_7 ( L_37 ) ;
goto V_32;
}
if ( V_79 == 0 )
V_79 = F_70 ( V_6 ) ;
F_7 ( L_38 ,
V_9 , V_9 -> V_19 , V_9 -> V_20 ) ;
F_11 ( & V_8 -> V_15 ) ;
V_91 = V_8 -> V_34 ;
V_90 = V_8 -> V_35 ;
if ( ! V_79 )
V_79 = F_70 ( V_6 ) ;
F_13 ( & V_8 -> V_15 ) ;
if ( V_122 && V_9 != V_122 ) {
F_7 ( L_39 ,
V_12 ) ;
V_12 = V_116 ;
}
V_122 = V_9 ;
while ( ! V_124 && V_12 <= V_117 ) {
int V_141 = V_127 ? 2 : 1 ;
unsigned V_51 ;
int V_142 ;
T_3 V_143 ;
int V_144 , V_145 ;
struct V_2 * * V_54 = NULL ;
T_6 * V_146 = NULL ;
struct V_2 * V_2 ;
int V_147 ;
T_2 V_21 , V_31 ;
long V_89 ;
V_143 = 0 ;
V_145 = 0 ;
V_120 = V_121 ;
V_148:
V_142 = - 1 ;
V_147 = F_96 ( V_117 - V_12 ,
F_96 ( ( T_3 ) V_149 ,
V_120 - ( T_3 ) V_145 ) - 1 )
+ 1 ;
V_144 = F_97 ( & V_104 , V_5 , & V_12 ,
V_150 ,
V_147 ) ;
F_7 ( L_40 , V_144 ) ;
if ( ! V_144 && ! V_145 )
break;
for ( V_51 = 0 ; V_51 < V_144 && V_145 < V_120 ; V_51 ++ ) {
V_2 = V_104 . V_54 [ V_51 ] ;
F_7 ( L_41 , V_2 , V_2 -> V_12 ) ;
if ( V_145 == 0 )
F_98 ( V_2 ) ;
else if ( ! F_99 ( V_2 ) )
break;
if ( F_4 ( ! F_6 ( V_2 ) ) ||
F_4 ( V_2 -> V_5 != V_5 ) ) {
F_7 ( L_42 , V_2 ) ;
F_39 ( V_2 ) ;
break;
}
if ( ! V_86 -> V_135 && V_2 -> V_12 > V_117 ) {
F_7 ( L_43 , V_2 ) ;
V_124 = 1 ;
F_39 ( V_2 ) ;
break;
}
if ( V_143 && ( V_2 -> V_12 != V_143 ) ) {
F_7 ( L_44 , V_2 ) ;
F_39 ( V_2 ) ;
break;
}
if ( V_86 -> V_128 != V_131 ) {
F_7 ( L_45 , V_2 ) ;
F_100 ( V_2 ) ;
}
if ( F_33 ( V_2 ) >= V_79 ) {
F_7 ( L_23 , V_2 , V_79 ) ;
V_124 = 1 ;
F_39 ( V_2 ) ;
break;
}
if ( F_101 ( V_2 ) ) {
F_7 ( L_46 , V_2 ) ;
F_39 ( V_2 ) ;
break;
}
V_123 = F_1 ( V_2 ) ;
if ( V_123 -> V_19 > V_9 -> V_19 ) {
F_7 ( L_47 ,
V_123 , V_123 -> V_19 , V_9 , V_9 -> V_19 ) ;
F_39 ( V_2 ) ;
if ( ! V_145 )
continue;
break;
}
if ( ! F_102 ( V_2 ) ) {
F_7 ( L_48 , V_2 ) ;
F_39 ( V_2 ) ;
break;
}
if ( V_145 == 0 ) {
F_8 ( V_54 ) ;
V_21 = ( T_2 ) F_33 ( V_2 ) ;
V_31 = V_125 ;
V_39 = F_51 ( & V_75 -> V_29 -> V_28 ,
& V_8 -> V_33 , V_61 ,
V_21 , & V_31 , V_141 ,
V_151 ,
V_152 |
V_153 ,
V_9 , V_91 ,
V_90 , true ) ;
if ( F_52 ( V_39 ) ) {
V_45 = F_53 ( V_39 ) ;
F_39 ( V_2 ) ;
break;
}
V_39 -> V_72 = F_84 ;
V_39 -> V_42 = V_6 ;
V_120 = F_43 ( 0 , ( T_2 ) V_31 ) ;
V_54 = F_54 ( V_120 * sizeof ( * V_54 ) ,
V_68 ) ;
if ( ! V_54 ) {
V_146 = V_75 -> V_115 ;
V_54 = F_103 ( V_146 , V_68 ) ;
F_8 ( ! V_54 ) ;
}
}
if ( V_142 < 0 )
V_142 = V_51 ;
F_7 ( L_49 ,
V_6 , V_2 , V_2 -> V_12 ) ;
V_89 =
F_71 ( & V_75 -> V_96 ) ;
if ( V_89 > F_72 (
V_75 -> V_76 -> V_97 ) ) {
F_73 ( & V_75 -> V_98 ,
V_99 ) ;
}
F_74 ( V_2 ) ;
V_54 [ V_145 ] = V_2 ;
V_145 ++ ;
V_143 = V_2 -> V_12 + 1 ;
}
if ( ! V_145 )
goto V_154;
if ( V_51 ) {
int V_155 ;
F_8 ( ! V_145 || V_142 < 0 ) ;
if ( V_144 && V_51 == V_144 &&
V_145 < V_120 ) {
F_7 ( L_50 ) ;
F_104 ( & V_104 ) ;
goto V_148;
}
for ( V_155 = V_51 ; V_155 < V_144 ; V_155 ++ ) {
F_7 ( L_51 ,
V_104 . V_54 [ V_155 ] ) ;
V_104 . V_54 [ V_155 - V_51 + V_142 ] = V_104 . V_54 [ V_155 ] ;
}
V_104 . V_156 -= V_51 - V_142 ;
}
V_21 = F_33 ( V_54 [ 0 ] ) ;
V_31 = F_96 ( V_79 - V_21 ,
( T_2 ) V_145 << V_65 ) ;
F_7 ( L_52 ,
V_145 , V_21 , V_31 ) ;
F_58 ( V_39 , 0 , V_54 , V_31 , 0 ,
! ! V_146 , false ) ;
V_54 = NULL ;
V_146 = NULL ;
F_105 ( V_39 , 0 , V_31 ) ;
V_61 = F_32 ( V_6 ) ;
F_59 ( V_39 , V_21 , V_9 , V_61 . V_73 ,
& V_6 -> V_100 ) ;
V_45 = F_60 ( & V_75 -> V_29 -> V_28 , V_39 , true ) ;
F_8 ( V_45 ) ;
V_39 = NULL ;
V_12 = V_143 ;
V_86 -> V_157 -= V_145 ;
if ( V_86 -> V_157 <= 0 )
V_124 = 1 ;
V_154:
F_7 ( L_53 , ( int ) V_104 . V_156 ,
V_104 . V_156 ? V_104 . V_54 [ 0 ] : NULL ) ;
F_83 ( & V_104 ) ;
if ( V_145 && ! V_124 )
goto V_140;
}
if ( V_119 && ! V_124 ) {
F_7 ( L_54 ) ;
V_119 = 0 ;
V_12 = 0 ;
goto V_140;
}
if ( V_86 -> V_135 || ( V_118 && V_86 -> V_157 > 0 ) )
V_5 -> V_136 = V_12 ;
V_32:
if ( V_39 )
F_61 ( V_39 ) ;
F_23 ( V_9 ) ;
F_7 ( L_55 , V_45 ) ;
return V_45 ;
}
static int F_106 ( struct V_6 * V_6 ,
struct V_1 * V_9 )
{
struct V_1 * V_87 = F_67 ( V_6 , NULL ) ;
int V_10 = ! V_87 || V_9 -> V_19 <= V_87 -> V_19 ;
F_23 ( V_87 ) ;
return V_10 ;
}
static int F_107 ( struct V_25 * V_25 ,
T_4 V_158 , unsigned V_31 ,
struct V_2 * V_2 )
{
struct V_6 * V_6 = F_28 ( V_25 ) ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_159 * V_160 = F_29 ( V_6 ) -> V_160 ;
T_4 V_88 = V_158 & V_161 ;
int V_162 = V_158 & ~ V_161 ;
int V_163 = V_162 + V_31 ;
T_4 V_164 ;
int V_37 ;
struct V_1 * V_9 , * V_87 ;
V_165:
F_100 ( V_2 ) ;
F_8 ( ! V_8 -> V_13 ) ;
F_108 ( & V_160 -> V_166 ) ;
F_8 ( ! V_8 -> V_13 -> V_14 ) ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 && V_9 != V_8 -> V_16 ) {
V_87 = F_67 ( V_6 , NULL ) ;
F_109 ( & V_160 -> V_166 ) ;
if ( V_9 -> V_19 > V_87 -> V_19 ) {
F_23 ( V_87 ) ;
F_7 ( L_56 ,
V_2 , V_9 ) ;
V_9 = F_10 ( V_9 ) ;
F_39 ( V_2 ) ;
F_110 ( V_6 ) ;
V_37 = F_111 ( V_8 -> V_167 ,
F_106 ( V_6 , V_9 ) ) ;
F_23 ( V_9 ) ;
if ( V_37 == - V_168 )
return V_37 ;
return - V_169 ;
}
F_23 ( V_87 ) ;
F_7 ( L_57 ,
V_2 , V_9 ) ;
if ( ! F_102 ( V_2 ) )
goto V_165;
V_37 = F_69 ( V_2 , NULL ) ;
if ( V_37 < 0 )
goto V_170;
goto V_165;
}
if ( F_86 ( V_2 ) ) {
F_7 ( L_58 , V_2 ) ;
return 0 ;
}
if ( V_162 == 0 && V_31 == V_23 )
return 0 ;
V_164 = V_6 -> V_164 ;
if ( V_164 + V_31 > V_6 -> V_114 -> V_171 ) {
V_37 = - V_172 ;
goto V_173;
}
if ( V_88 >= V_164 ||
( V_162 == 0 && ( V_158 + V_31 ) >= V_164 &&
V_163 - V_162 != V_23 ) ) {
F_7 ( L_59 ,
V_2 , V_162 , V_163 , ( int ) V_23 ) ;
F_112 ( V_2 ,
0 , V_162 ,
V_163 , V_23 ) ;
return 0 ;
}
F_109 ( & V_160 -> V_166 ) ;
V_37 = F_27 ( V_25 , V_2 ) ;
if ( V_37 < 0 )
goto V_170;
goto V_165;
V_173:
F_109 ( & V_160 -> V_166 ) ;
V_170:
F_39 ( V_2 ) ;
return V_37 ;
}
static int F_113 ( struct V_25 * V_25 , struct V_4 * V_5 ,
T_4 V_158 , unsigned V_31 , unsigned V_94 ,
struct V_2 * * V_174 , void * * V_175 )
{
struct V_6 * V_6 = F_28 ( V_25 ) ;
struct V_2 * V_2 ;
T_3 V_12 = V_158 >> V_65 ;
int V_37 ;
do {
V_2 = F_114 ( V_5 , V_12 , 0 ) ;
if ( ! V_2 )
return - V_69 ;
* V_174 = V_2 ;
F_7 ( L_60 , V_25 ,
V_6 , V_2 , ( int ) V_158 , ( int ) V_31 ) ;
V_37 = F_107 ( V_25 , V_158 , V_31 , V_2 ) ;
} while ( V_37 == - V_169 );
return V_37 ;
}
static int F_115 ( struct V_25 * V_25 , struct V_4 * V_5 ,
T_4 V_158 , unsigned V_31 , unsigned V_176 ,
struct V_2 * V_2 , void * V_175 )
{
struct V_6 * V_6 = F_28 ( V_25 ) ;
struct V_74 * V_75 = F_29 ( V_6 ) ;
struct V_159 * V_160 = V_75 -> V_160 ;
unsigned V_177 = V_158 & ( V_23 - 1 ) ;
int V_178 = 0 ;
F_7 ( L_61 , V_25 ,
V_6 , V_2 , ( int ) V_158 , ( int ) V_176 , ( int ) V_31 ) ;
if ( V_176 < V_31 )
F_35 ( V_2 , V_177 + V_176 , V_31 ) ;
if ( V_158 + V_176 > V_6 -> V_164 )
V_178 = F_116 ( V_6 , V_158 + V_176 ) ;
if ( ! F_86 ( V_2 ) )
F_36 ( V_2 ) ;
F_117 ( V_2 ) ;
F_39 ( V_2 ) ;
F_109 ( & V_160 -> V_166 ) ;
F_45 ( V_2 ) ;
if ( V_178 )
F_118 ( F_9 ( V_6 ) , V_179 , NULL ) ;
return V_176 ;
}
static T_7 F_119 ( int V_180 , struct V_181 * V_182 ,
const struct V_183 * V_184 ,
T_4 V_158 , unsigned long V_185 )
{
F_16 ( 1 ) ;
return - V_172 ;
}
static int F_120 ( struct V_186 * V_187 , struct V_188 * V_189 )
{
struct V_6 * V_6 = F_28 ( V_187 -> V_190 ) ;
struct V_2 * V_2 = V_189 -> V_2 ;
struct V_159 * V_160 = F_29 ( V_6 ) -> V_160 ;
T_4 V_62 = F_33 ( V_2 ) ;
T_4 V_84 , V_31 ;
int V_10 ;
F_121 ( V_187 -> V_190 ) ;
V_84 = F_70 ( V_6 ) ;
if ( V_62 + V_23 <= V_84 )
V_31 = V_23 ;
else
V_31 = V_84 & ~ V_161 ;
F_7 ( L_62 , V_6 ,
V_62 , V_31 , V_2 , V_2 -> V_12 ) ;
F_98 ( V_2 ) ;
V_10 = V_191 ;
if ( ( V_62 > V_84 ) ||
( V_2 -> V_5 != V_6 -> V_107 ) )
goto V_32;
V_10 = F_107 ( V_187 -> V_190 , V_62 , V_31 , V_2 ) ;
if ( V_10 == 0 ) {
F_117 ( V_2 ) ;
F_109 ( & V_160 -> V_166 ) ;
V_10 = V_192 ;
} else {
if ( V_10 == - V_69 )
V_10 = V_193 ;
else
V_10 = V_194 ;
}
V_32:
F_7 ( L_63 , V_6 , V_62 , V_31 , V_10 ) ;
if ( V_10 != V_192 )
F_39 ( V_2 ) ;
return V_10 ;
}
int F_122 ( struct V_25 * V_25 , struct V_186 * V_187 )
{
struct V_4 * V_5 = V_25 -> V_195 ;
if ( ! V_5 -> V_196 -> V_197 )
return - V_198 ;
F_123 ( V_25 ) ;
V_187 -> V_199 = & V_200 ;
return 0 ;
}
