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
F_10 ( & V_8 -> V_13 ) ;
F_8 ( V_8 -> V_14 == 0 ) ;
if ( F_11 ( V_8 ) ) {
struct V_15 * V_16 =
F_12 ( & V_8 -> V_17 ,
struct V_15 ,
V_18 ) ;
V_9 = F_13 ( V_16 -> V_19 ) ;
V_16 -> V_20 ++ ;
} else {
F_8 ( ! V_8 -> V_21 ) ;
V_9 = F_13 ( V_8 -> V_21 ) ;
++ V_8 -> V_22 ;
}
if ( V_8 -> V_23 == 0 )
F_14 ( V_6 ) ;
++ V_8 -> V_23 ;
F_7 ( L_2
L_3 ,
V_5 -> V_11 , V_2 , V_2 -> V_12 ,
V_8 -> V_23 - 1 , V_8 -> V_22 - 1 ,
V_8 -> V_23 , V_8 -> V_22 ,
V_9 , V_9 -> V_24 , V_9 -> V_25 ) ;
F_15 ( & V_8 -> V_13 ) ;
F_8 ( F_2 ( V_2 ) ) ;
V_2 -> V_3 = ( unsigned long ) V_9 ;
F_16 ( V_2 ) ;
V_10 = F_17 ( V_2 ) ;
F_18 ( ! F_19 ( V_2 ) ) ;
F_18 ( ! V_2 -> V_5 ) ;
return V_10 ;
}
static void F_20 ( struct V_2 * V_2 , unsigned int V_26 ,
unsigned int V_27 )
{
struct V_6 * V_6 ;
struct V_7 * V_8 ;
struct V_1 * V_9 = F_1 ( V_2 ) ;
V_6 = V_2 -> V_5 -> V_11 ;
V_8 = F_9 ( V_6 ) ;
if ( V_26 != 0 || V_27 != V_28 ) {
F_7 ( L_4 ,
V_6 , V_2 , V_2 -> V_12 , V_26 , V_27 ) ;
return;
}
F_21 ( V_6 , V_2 ) ;
if ( ! F_2 ( V_2 ) )
return;
if ( ! F_6 ( V_2 ) )
F_22 ( L_5 , V_6 , V_2 ) ;
F_23 ( V_2 ) ;
F_7 ( L_6 ,
V_6 , V_2 , V_2 -> V_12 ) ;
F_24 ( V_8 , 1 , V_9 ) ;
F_25 ( V_9 ) ;
V_2 -> V_3 = 0 ;
F_26 ( V_2 ) ;
}
static int F_27 ( struct V_2 * V_2 , T_1 V_29 )
{
F_7 ( L_7 , V_2 -> V_5 -> V_11 ,
V_2 , V_2 -> V_12 , F_6 ( V_2 ) ? L_8 : L_9 ) ;
if ( ! F_28 ( V_2 , V_29 ) )
return 0 ;
return ! F_2 ( V_2 ) ;
}
static int F_29 ( struct V_30 * V_31 , struct V_2 * V_2 )
{
struct V_6 * V_6 = F_30 ( V_31 ) ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_32 * V_33 =
& F_31 ( V_6 ) -> V_34 -> V_33 ;
int V_35 = 0 ;
T_2 V_36 = F_32 ( V_2 ) ;
T_2 V_37 = V_28 ;
if ( V_36 >= F_33 ( V_6 ) ) {
F_34 ( V_2 , 0 , V_28 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
if ( V_8 -> V_38 != V_39 ) {
if ( V_36 == 0 )
return - V_40 ;
F_34 ( V_2 , 0 , V_28 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
V_35 = F_36 ( V_6 , V_2 ) ;
if ( V_35 == 0 )
goto V_41;
F_7 ( L_10 ,
V_6 , V_31 , V_2 , V_2 -> V_12 ) ;
V_35 = F_37 ( V_33 , F_38 ( V_6 ) , & V_8 -> V_42 ,
V_36 , & V_37 ,
V_8 -> V_43 , V_8 -> V_44 ,
& V_2 , 1 , 0 ) ;
if ( V_35 == - V_45 )
V_35 = 0 ;
if ( V_35 < 0 ) {
F_39 ( V_2 ) ;
F_40 ( V_6 , V_2 ) ;
goto V_41;
}
if ( V_35 < V_28 )
F_34 ( V_2 , V_35 , V_28 ) ;
else
F_41 ( V_2 ) ;
F_35 ( V_2 ) ;
F_42 ( V_6 , V_2 ) ;
V_41:
return V_35 < 0 ? V_35 : 0 ;
}
static int F_43 ( struct V_30 * V_31 , struct V_2 * V_2 )
{
int V_46 = F_29 ( V_31 , V_2 ) ;
F_44 ( V_2 ) ;
return V_46 ;
}
static void F_45 ( struct V_47 * V_48 )
{
struct V_6 * V_6 = V_48 -> V_49 ;
struct V_50 * V_51 ;
int V_52 = V_48 -> V_53 <= 0 ? V_48 -> V_53 : 0 ;
int V_54 = V_48 -> V_53 >= 0 ? V_48 -> V_53 : 0 ;
int V_55 ;
int V_56 ;
F_7 ( L_11 , V_6 , V_48 , V_52 , V_54 ) ;
V_51 = F_46 ( V_48 , 0 ) ;
F_8 ( V_51 -> type != V_57 ) ;
V_55 = F_47 ( ( T_2 ) V_51 -> V_58 ,
( T_2 ) V_51 -> V_27 ) ;
for ( V_56 = 0 ; V_56 < V_55 ; V_56 ++ ) {
struct V_2 * V_2 = V_51 -> V_59 [ V_56 ] ;
if ( V_52 < 0 && V_52 != - V_45 ) {
F_40 ( V_6 , V_2 ) ;
goto V_60;
}
if ( V_54 < ( int ) V_28 ) {
int V_61 = V_54 < 0 ? 0 : V_54 ;
F_34 ( V_2 , V_61 , V_28 ) ;
}
F_7 ( L_12 , V_6 , V_2 ,
V_2 -> V_12 ) ;
F_41 ( V_2 ) ;
F_35 ( V_2 ) ;
F_42 ( V_6 , V_2 ) ;
V_60:
F_44 ( V_2 ) ;
F_48 ( V_2 ) ;
V_54 -= V_28 ;
}
F_49 ( V_51 -> V_59 ) ;
}
static int F_50 ( struct V_6 * V_6 , struct V_62 * V_63 , int V_64 )
{
struct V_32 * V_33 =
& F_31 ( V_6 ) -> V_34 -> V_33 ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_2 * V_2 = F_51 ( V_63 -> V_65 , struct V_2 , V_66 ) ;
struct F_38 V_67 ;
struct V_47 * V_48 ;
T_2 V_36 ;
T_2 V_37 ;
int V_56 ;
struct V_2 * * V_59 ;
T_3 V_68 ;
int V_69 = 0 ;
int V_70 = 0 ;
int V_10 = 0 ;
if ( ! V_71 -> V_72 ) {
int V_73 = V_74 ;
V_10 = F_52 ( V_8 , V_75 , V_73 , & V_70 ) ;
if ( V_10 < 0 ) {
F_7 ( L_13 , V_6 ) ;
} else if ( ! ( V_70 & V_73 ) ) {
F_7 ( L_14 , V_6 ) ;
V_10 = 0 ;
}
if ( V_10 <= 0 ) {
if ( V_70 )
F_53 ( V_8 , V_70 ) ;
while ( ! F_54 ( V_63 ) ) {
V_2 = F_51 ( V_63 -> V_65 ,
struct V_2 , V_66 ) ;
F_55 ( & V_2 -> V_66 ) ;
F_48 ( V_2 ) ;
}
return V_10 ;
}
}
V_36 = ( T_2 ) F_32 ( V_2 ) ;
V_68 = V_2 -> V_12 ;
F_56 (page, page_list, lru) {
if ( V_2 -> V_12 != V_68 )
break;
V_69 ++ ;
V_68 ++ ;
if ( V_64 && V_69 == V_64 )
break;
}
V_37 = V_69 << V_76 ;
F_7 ( L_15 , V_6 , V_69 ,
V_36 , V_37 ) ;
V_67 = F_38 ( V_6 ) ;
V_48 = F_57 ( V_33 , & V_8 -> V_42 , V_67 , V_36 , & V_37 ,
0 , 1 , V_77 ,
V_78 , NULL ,
V_8 -> V_43 , V_8 -> V_44 ,
false ) ;
if ( F_58 ( V_48 ) ) {
V_10 = F_59 ( V_48 ) ;
goto V_41;
}
V_69 = F_47 ( 0 , V_37 ) ;
V_59 = F_60 ( sizeof( * V_59 ) * V_69 , V_79 ) ;
if ( ! V_59 ) {
V_10 = - V_80 ;
goto V_81;
}
for ( V_56 = 0 ; V_56 < V_69 ; ++ V_56 ) {
V_2 = F_51 ( V_63 -> V_65 , struct V_2 , V_66 ) ;
F_8 ( F_19 ( V_2 ) ) ;
F_55 ( & V_2 -> V_66 ) ;
F_7 ( L_16 , V_6 , V_2 ,
V_2 -> V_12 ) ;
if ( F_61 ( V_2 , & V_6 -> V_82 , V_2 -> V_12 ,
V_79 ) ) {
F_62 ( V_6 , V_2 ) ;
F_48 ( V_2 ) ;
F_7 ( L_17 ,
V_6 , V_2 ) ;
V_69 = V_56 ;
if ( V_69 > 0 ) {
V_37 = V_69 << V_76 ;
F_63 ( V_48 , 0 , V_37 ) ;
break;
}
goto V_83;
}
V_59 [ V_56 ] = V_2 ;
}
F_64 ( V_48 , 0 , V_59 , V_37 , 0 , false , false ) ;
V_48 -> V_84 = F_45 ;
V_48 -> V_49 = V_6 ;
F_7 ( L_18 , V_6 , V_48 , V_36 , V_37 ) ;
V_10 = F_65 ( V_33 , V_48 , false ) ;
if ( V_10 < 0 )
goto V_83;
F_66 ( V_48 ) ;
if ( V_70 )
F_53 ( V_8 , V_70 ) ;
return V_69 ;
V_83:
for ( V_56 = 0 ; V_56 < V_69 ; ++ V_56 ) {
F_40 ( V_6 , V_59 [ V_56 ] ) ;
F_44 ( V_59 [ V_56 ] ) ;
}
F_67 ( V_59 , V_69 , false ) ;
V_81:
F_66 ( V_48 ) ;
V_41:
if ( V_70 )
F_53 ( V_8 , V_70 ) ;
return V_10 ;
}
static int F_68 ( struct V_30 * V_30 , struct V_4 * V_5 ,
struct V_62 * V_63 , unsigned V_69 )
{
struct V_6 * V_6 = F_30 ( V_30 ) ;
struct V_85 * V_86 = F_31 ( V_6 ) ;
int V_52 = 0 ;
int V_64 = 0 ;
if ( F_9 ( V_6 ) -> V_38 != V_39 )
return - V_40 ;
V_52 = F_69 ( V_5 -> V_11 , V_5 , V_63 ,
& V_69 ) ;
if ( V_52 == 0 )
goto V_41;
if ( V_86 -> V_87 -> V_88 >= V_28 )
V_64 = ( V_86 -> V_87 -> V_88 + V_28 - 1 )
>> V_76 ;
F_7 ( L_19 , V_6 ,
V_30 , V_69 ,
V_64 ) ;
while ( ! F_54 ( V_63 ) ) {
V_52 = F_50 ( V_6 , V_63 , V_64 ) ;
if ( V_52 < 0 )
goto V_41;
}
V_41:
F_70 ( V_6 , V_63 ) ;
F_7 ( L_20 , V_6 , V_30 , V_52 ) ;
return V_52 ;
}
static struct V_1 * F_71 ( struct V_6 * V_6 ,
T_4 * V_89 ,
T_2 * V_90 ,
T_5 * V_91 )
{
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_1 * V_9 = NULL ;
struct V_15 * V_16 = NULL ;
F_10 ( & V_8 -> V_13 ) ;
F_72 (capsnap, &ci->i_cap_snaps, ci_item) {
F_7 ( L_21 , V_16 ,
V_16 -> V_19 , V_16 -> V_20 ) ;
if ( V_16 -> V_20 ) {
V_9 = F_13 ( V_16 -> V_19 ) ;
if ( V_89 )
* V_89 = V_16 -> V_92 ;
if ( V_90 )
* V_90 = V_16 -> V_90 ;
if ( V_91 )
* V_91 = V_16 -> V_91 ;
break;
}
}
if ( ! V_9 && V_8 -> V_22 ) {
V_9 = F_13 ( V_8 -> V_21 ) ;
F_7 ( L_22 ,
V_9 , V_8 -> V_22 ) ;
if ( V_90 )
* V_90 = V_8 -> V_44 ;
if ( V_91 )
* V_91 = V_8 -> V_43 ;
}
F_15 ( & V_8 -> V_13 ) ;
return V_9 ;
}
static int F_73 ( struct V_2 * V_2 , struct V_93 * V_94 )
{
struct V_6 * V_6 ;
struct V_7 * V_8 ;
struct V_85 * V_86 ;
struct V_32 * V_33 ;
struct V_1 * V_9 , * V_95 ;
T_4 V_96 = F_32 ( V_2 ) ;
T_4 V_89 = - 1 ;
long V_97 ;
T_2 V_90 ;
T_5 V_91 ;
int V_35 = 0 , V_37 = V_28 ;
F_7 ( L_23 , V_2 , V_2 -> V_12 ) ;
if ( ! V_2 -> V_5 || ! V_2 -> V_5 -> V_11 ) {
F_7 ( L_24 , V_2 ) ;
return - V_98 ;
}
V_6 = V_2 -> V_5 -> V_11 ;
V_8 = F_9 ( V_6 ) ;
V_86 = F_31 ( V_6 ) ;
V_33 = & V_86 -> V_34 -> V_33 ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 == NULL ) {
F_7 ( L_25 , V_6 , V_2 ) ;
goto V_41;
}
V_95 = F_71 ( V_6 , & V_89 ,
& V_90 , & V_91 ) ;
if ( V_9 -> V_24 > V_95 -> V_24 ) {
F_7 ( L_26 ,
V_6 , V_2 , V_9 ) ;
F_18 ( ( V_71 -> V_99 & V_100 ) == 0 ) ;
F_25 ( V_95 ) ;
goto V_41;
}
F_25 ( V_95 ) ;
if ( V_89 == - 1 )
V_89 = F_33 ( V_6 ) ;
if ( V_96 >= V_89 ) {
F_7 ( L_27 , V_2 , V_89 ) ;
goto V_41;
}
if ( V_89 < V_96 + V_37 )
V_37 = V_89 - V_96 ;
F_7 ( L_28 ,
V_6 , V_2 , V_2 -> V_12 , V_96 , V_37 , V_9 ) ;
V_97 = F_74 ( & V_86 -> V_101 ) ;
if ( V_97 >
F_75 ( V_86 -> V_87 -> V_102 ) )
F_76 ( F_77 ( V_6 ) , V_103 ) ;
F_78 ( V_2 ) ;
V_35 = F_79 ( V_33 , F_38 ( V_6 ) ,
& V_8 -> V_42 , V_9 ,
V_96 , V_37 ,
V_91 , V_90 ,
& V_6 -> V_104 , & V_2 , 1 ) ;
if ( V_35 < 0 ) {
struct V_93 V_105 ;
if ( ! V_94 )
V_94 = & V_105 ;
if ( V_35 == - V_106 ) {
F_7 ( L_29 , V_2 ) ;
F_80 ( V_94 , V_2 ) ;
F_81 ( V_2 ) ;
goto V_41;
}
F_7 ( L_30 ,
V_35 , V_2 ) ;
F_39 ( V_2 ) ;
F_82 ( & V_6 -> V_82 , V_35 ) ;
V_94 -> V_107 ++ ;
} else {
F_7 ( L_31 , V_2 ) ;
V_35 = 0 ;
}
V_2 -> V_3 = 0 ;
F_26 ( V_2 ) ;
F_81 ( V_2 ) ;
F_24 ( V_8 , 1 , V_9 ) ;
F_25 ( V_9 ) ;
V_41:
return V_35 ;
}
static int F_83 ( struct V_2 * V_2 , struct V_93 * V_94 )
{
int V_35 ;
struct V_6 * V_6 = V_2 -> V_5 -> V_11 ;
F_8 ( ! V_6 ) ;
F_14 ( V_6 ) ;
V_35 = F_73 ( V_2 , V_94 ) ;
if ( V_35 == - V_106 ) {
V_35 = 0 ;
}
F_44 ( V_2 ) ;
F_84 ( V_6 ) ;
return V_35 ;
}
static void F_85 ( struct V_2 * * V_59 , int V_108 )
{
struct V_109 V_110 ;
int V_56 ;
F_86 ( & V_110 , 0 ) ;
for ( V_56 = 0 ; V_56 < V_108 ; V_56 ++ ) {
if ( F_87 ( & V_110 , V_59 [ V_56 ] ) == 0 )
F_88 ( & V_110 ) ;
}
F_88 ( & V_110 ) ;
}
static void F_89 ( struct V_47 * V_48 )
{
struct V_6 * V_6 = V_48 -> V_49 ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_50 * V_51 ;
struct V_2 * V_2 ;
int V_55 , V_111 = 0 ;
int V_56 , V_112 ;
int V_52 = V_48 -> V_53 ;
struct V_1 * V_9 = V_48 -> V_113 ;
struct V_4 * V_5 = V_6 -> V_114 ;
struct V_85 * V_86 = F_31 ( V_6 ) ;
bool V_115 ;
F_7 ( L_32 , V_6 , V_52 ) ;
if ( V_52 < 0 ) {
F_82 ( V_5 , V_52 ) ;
F_90 ( V_8 ) ;
} else {
F_91 ( V_8 ) ;
}
V_115 = ! ( F_92 ( V_8 ) &
( V_74 | V_116 ) ) ;
for ( V_56 = 0 ; V_56 < V_48 -> V_117 ; V_56 ++ ) {
if ( V_48 -> V_118 [ V_56 ] . V_119 != V_120 )
break;
V_51 = F_46 ( V_48 , V_56 ) ;
F_8 ( V_51 -> type != V_57 ) ;
V_55 = F_47 ( ( T_2 ) V_51 -> V_58 ,
( T_2 ) V_51 -> V_27 ) ;
V_111 += V_55 ;
for ( V_112 = 0 ; V_112 < V_55 ; V_112 ++ ) {
V_2 = V_51 -> V_59 [ V_112 ] ;
F_8 ( ! V_2 ) ;
F_18 ( ! F_93 ( V_2 ) ) ;
if ( F_94 ( & V_86 -> V_101 ) <
F_95 (
V_86 -> V_87 -> V_102 ) )
F_96 ( F_77 ( V_6 ) ,
V_103 ) ;
F_25 ( F_1 ( V_2 ) ) ;
V_2 -> V_3 = 0 ;
F_26 ( V_2 ) ;
F_7 ( L_33 , V_2 ) ;
F_81 ( V_2 ) ;
if ( V_115 )
F_97 ( V_6 -> V_114 ,
V_2 ) ;
F_44 ( V_2 ) ;
}
F_7 ( L_34 ,
V_6 , V_51 -> V_27 , V_52 >= 0 ? V_55 : 0 ) ;
F_85 ( V_51 -> V_59 , V_55 ) ;
}
F_24 ( V_8 , V_111 , V_9 ) ;
V_51 = F_46 ( V_48 , 0 ) ;
if ( V_51 -> V_121 )
F_98 ( V_51 -> V_59 ,
F_99 ( V_6 -> V_122 ) -> V_123 ) ;
else
F_49 ( V_51 -> V_59 ) ;
F_66 ( V_48 ) ;
}
static int F_100 ( struct V_4 * V_5 ,
struct V_93 * V_94 )
{
struct V_6 * V_6 = V_5 -> V_11 ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_85 * V_86 = F_31 ( V_6 ) ;
struct F_38 V_67 = F_38 ( V_6 ) ;
T_3 V_12 , V_124 , V_125 ;
int V_126 = 0 ;
int V_127 = 1 ;
T_3 V_128 = 0 , V_129 = 0 ;
struct V_1 * V_9 = NULL , * V_130 = NULL , * V_131 ;
struct V_109 V_110 ;
int V_132 = 0 ;
int V_52 = 0 ;
unsigned int V_133 = F_101 ( V_6 ) ;
struct V_47 * V_48 = NULL ;
int V_134 = 0 ;
T_4 V_89 , V_135 ;
T_2 V_90 ;
T_5 V_91 ;
if ( ( V_94 -> V_136 == V_137 ) ||
F_102 ( V_8 , V_138 ) )
V_134 = 1 ;
F_7 ( L_35 ,
V_6 , V_134 ,
V_94 -> V_136 == V_139 ? L_36 :
( V_94 -> V_136 == V_137 ? L_37 : L_38 ) ) ;
if ( F_103 ( V_86 -> V_140 ) == V_141 ) {
if ( V_8 -> V_23 > 0 ) {
F_104 (
L_39 ,
V_6 , F_105 ( V_6 ) ) ;
}
F_82 ( V_5 , - V_142 ) ;
return - V_142 ;
}
if ( V_86 -> V_87 -> V_133 && V_86 -> V_87 -> V_133 < V_133 )
V_133 = V_86 -> V_87 -> V_133 ;
if ( V_133 < V_28 )
V_133 = V_28 ;
V_129 = V_133 >> V_76 ;
F_86 ( & V_110 , 0 ) ;
if ( V_94 -> V_143 ) {
V_124 = V_5 -> V_144 ;
V_125 = - 1 ;
F_7 ( L_40 , V_124 ) ;
} else {
V_124 = V_94 -> V_145 >> V_76 ;
V_125 = V_94 -> V_146 >> V_76 ;
if ( V_94 -> V_145 == 0 && V_94 -> V_146 == V_147 )
V_126 = 1 ;
V_127 = 0 ;
F_7 ( L_41 , V_124 , V_125 ) ;
}
V_12 = V_124 ;
V_148:
F_25 ( V_9 ) ;
V_89 = - 1 ;
V_9 = F_71 ( V_6 , & V_89 ,
& V_90 , & V_91 ) ;
if ( ! V_9 ) {
F_7 ( L_42 ) ;
goto V_41;
}
F_7 ( L_43 ,
V_9 , V_9 -> V_24 , V_9 -> V_25 ) ;
V_135 = F_33 ( V_6 ) ;
if ( V_130 && V_9 != V_130 ) {
F_7 ( L_44 ,
V_12 ) ;
V_12 = V_124 ;
}
V_130 = V_9 ;
while ( ! V_132 && V_12 <= V_125 ) {
unsigned V_56 ;
int V_149 ;
T_3 V_150 = 0 ;
int V_151 = 0 , V_152 ;
int V_153 , V_154 = 0 ;
struct V_2 * * V_59 = NULL , * * V_155 ;
T_6 * V_156 = NULL ;
struct V_2 * V_2 ;
int V_73 ;
T_2 V_26 = 0 , V_37 = 0 ;
V_128 = V_129 ;
V_157:
V_149 = - 1 ;
V_73 = F_106 ( V_125 - V_12 ,
F_106 ( ( T_3 ) V_158 ,
V_128 - ( T_3 ) V_154 ) - 1 )
+ 1 ;
V_153 = F_107 ( & V_110 , V_5 , & V_12 ,
V_159 ,
V_73 ) ;
F_7 ( L_45 , V_153 ) ;
if ( ! V_153 && ! V_154 )
break;
for ( V_56 = 0 ; V_56 < V_153 && V_154 < V_128 ; V_56 ++ ) {
V_2 = V_110 . V_59 [ V_56 ] ;
F_7 ( L_46 , V_2 , V_2 -> V_12 ) ;
if ( V_154 == 0 )
F_108 ( V_2 ) ;
else if ( ! F_109 ( V_2 ) )
break;
if ( F_4 ( ! F_6 ( V_2 ) ) ||
F_4 ( V_2 -> V_5 != V_5 ) ) {
F_7 ( L_47 , V_2 ) ;
F_44 ( V_2 ) ;
break;
}
if ( ! V_94 -> V_143 && V_2 -> V_12 > V_125 ) {
F_7 ( L_48 , V_2 ) ;
V_132 = 1 ;
F_44 ( V_2 ) ;
break;
}
if ( V_150 && ( V_2 -> V_12 > V_150 ) ) {
F_7 ( L_49 , V_2 ) ;
F_44 ( V_2 ) ;
break;
}
if ( V_94 -> V_136 != V_139 ) {
F_7 ( L_50 , V_2 ) ;
F_110 ( V_2 ) ;
}
if ( F_32 ( V_2 ) >=
( V_89 == - 1 ? V_135 : V_89 ) ) {
F_7 ( L_27 , V_2 ,
( V_89 == - 1 ? V_135 : V_89 ) ) ;
V_132 = 1 ;
F_44 ( V_2 ) ;
break;
}
if ( F_111 ( V_2 ) ) {
F_7 ( L_51 , V_2 ) ;
F_44 ( V_2 ) ;
break;
}
V_131 = F_1 ( V_2 ) ;
if ( V_131 -> V_24 > V_9 -> V_24 ) {
F_7 ( L_52 ,
V_131 , V_131 -> V_24 , V_9 , V_9 -> V_24 ) ;
F_44 ( V_2 ) ;
if ( ! V_154 )
continue;
break;
}
if ( ! F_112 ( V_2 ) ) {
F_7 ( L_53 , V_2 ) ;
F_44 ( V_2 ) ;
break;
}
if ( V_154 == 0 ) {
T_2 V_160 ;
T_2 V_161 ;
V_26 = ( T_2 ) F_32 ( V_2 ) ;
V_37 = V_133 ;
V_52 = F_113 ( & V_8 -> V_42 ,
V_26 , V_37 ,
& V_160 , & V_161 ,
& V_37 ) ;
if ( V_52 < 0 ) {
F_44 ( V_2 ) ;
break;
}
V_151 = 1 + V_134 ;
V_150 = V_2 -> V_12 +
( ( V_37 - 1 ) >> V_76 ) ;
F_8 ( V_59 ) ;
V_128 = F_47 ( 0 , ( T_2 ) V_37 ) ;
V_59 = F_60 ( V_128 * sizeof ( * V_59 ) ,
V_162 ) ;
if ( ! V_59 ) {
V_156 = V_86 -> V_123 ;
V_59 = F_114 ( V_156 , V_162 ) ;
F_8 ( ! V_59 ) ;
}
V_37 = 0 ;
} else if ( V_2 -> V_12 !=
( V_26 + V_37 ) >> V_76 ) {
if ( V_151 >= ( V_156 ? V_163 :
V_164 ) ) {
F_80 ( V_94 , V_2 ) ;
F_44 ( V_2 ) ;
break;
}
V_151 ++ ;
V_26 = ( T_2 ) F_32 ( V_2 ) ;
V_37 = 0 ;
}
if ( V_149 < 0 )
V_149 = V_56 ;
F_7 ( L_54 ,
V_6 , V_2 , V_2 -> V_12 ) ;
if ( F_74 ( & V_86 -> V_101 ) >
F_75 (
V_86 -> V_87 -> V_102 ) ) {
F_76 ( F_77 ( V_6 ) ,
V_103 ) ;
}
V_59 [ V_154 ] = V_2 ;
V_154 ++ ;
V_37 += V_28 ;
}
if ( ! V_154 )
goto V_165;
if ( V_56 ) {
int V_112 ;
F_8 ( ! V_154 || V_149 < 0 ) ;
if ( V_153 && V_56 == V_153 &&
V_154 < V_128 ) {
F_7 ( L_55 ) ;
F_115 ( & V_110 ) ;
goto V_157;
}
for ( V_112 = V_56 ; V_112 < V_153 ; V_112 ++ ) {
F_7 ( L_56 , V_110 . V_59 [ V_112 ] ) ;
V_110 . V_59 [ V_112 - V_56 + V_149 ] = V_110 . V_59 [ V_112 ] ;
}
V_110 . V_166 -= V_56 - V_149 ;
}
V_167:
V_26 = F_32 ( V_59 [ 0 ] ) ;
V_37 = V_133 ;
V_48 = F_57 ( & V_86 -> V_34 -> V_33 ,
& V_8 -> V_42 , V_67 ,
V_26 , & V_37 , 0 , V_151 ,
V_120 ,
V_168 ,
V_9 , V_91 ,
V_90 , false ) ;
if ( F_58 ( V_48 ) ) {
V_48 = F_57 ( & V_86 -> V_34 -> V_33 ,
& V_8 -> V_42 , V_67 ,
V_26 , & V_37 , 0 ,
F_106 ( V_151 ,
V_163 ) ,
V_120 ,
V_168 ,
V_9 , V_91 ,
V_90 , true ) ;
F_8 ( F_58 ( V_48 ) ) ;
}
F_8 ( V_37 < F_32 ( V_59 [ V_154 - 1 ] ) +
V_28 - V_26 ) ;
V_48 -> V_84 = F_89 ;
V_48 -> V_49 = V_6 ;
V_37 = 0 ;
V_155 = V_59 ;
V_152 = 0 ;
for ( V_56 = 0 ; V_56 < V_154 ; V_56 ++ ) {
T_2 V_169 = F_32 ( V_59 [ V_56 ] ) ;
if ( V_26 + V_37 != V_169 ) {
if ( V_152 + V_134 + 1 == V_48 -> V_117 )
break;
F_116 ( V_48 , V_152 ,
V_169 - V_26 ) ;
F_7 ( L_57 ,
V_26 , V_37 ) ;
F_64 ( V_48 , V_152 ,
V_155 , V_37 , 0 ,
! ! V_156 , false ) ;
F_63 ( V_48 , V_152 , V_37 ) ;
V_37 = 0 ;
V_26 = V_169 ;
V_155 = V_59 + V_56 ;
V_152 ++ ;
}
F_78 ( V_59 [ V_56 ] ) ;
V_37 += V_28 ;
}
if ( V_89 != - 1 ) {
V_37 = F_106 ( V_37 , V_89 - V_26 ) ;
} else if ( V_56 == V_154 ) {
T_2 V_170 = V_37 + 1 - V_28 ;
V_37 = F_106 ( V_37 , ( T_2 ) F_33 ( V_6 ) - V_26 ) ;
V_37 = V_64 ( V_37 , V_170 ) ;
}
F_7 ( L_57 , V_26 , V_37 ) ;
F_64 ( V_48 , V_152 , V_155 , V_37 ,
0 , ! ! V_156 , false ) ;
F_63 ( V_48 , V_152 , V_37 ) ;
if ( V_134 ) {
V_152 ++ ;
F_117 ( V_48 , V_152 , V_171 , 0 ) ;
}
F_8 ( V_152 + 1 != V_48 -> V_117 ) ;
V_156 = NULL ;
if ( V_56 < V_154 ) {
F_8 ( V_151 <= V_48 -> V_117 ) ;
V_151 -= V_48 -> V_117 ;
V_151 += V_134 ;
V_154 -= V_56 ;
V_155 = V_59 ;
V_59 = F_60 ( V_154 * sizeof ( * V_59 ) ,
V_162 ) ;
if ( ! V_59 ) {
V_156 = V_86 -> V_123 ;
V_59 = F_114 ( V_156 , V_162 ) ;
F_8 ( ! V_59 ) ;
}
memcpy ( V_59 , V_155 + V_56 ,
V_154 * sizeof( * V_59 ) ) ;
memset ( V_155 + V_56 , 0 ,
V_154 * sizeof( * V_59 ) ) ;
} else {
F_8 ( V_151 != V_48 -> V_117 ) ;
V_12 = V_59 [ V_56 - 1 ] -> V_12 + 1 ;
V_59 = NULL ;
}
V_48 -> V_172 = V_6 -> V_104 ;
V_52 = F_65 ( & V_86 -> V_34 -> V_33 , V_48 , true ) ;
F_8 ( V_52 ) ;
V_48 = NULL ;
V_94 -> V_173 -= V_56 ;
if ( V_59 )
goto V_167;
if ( V_94 -> V_173 <= 0 )
V_132 = 1 ;
V_165:
F_7 ( L_58 , ( int ) V_110 . V_166 ,
V_110 . V_166 ? V_110 . V_59 [ 0 ] : NULL ) ;
F_88 ( & V_110 ) ;
if ( V_154 && ! V_132 )
goto V_148;
}
if ( V_127 && ! V_132 ) {
F_7 ( L_59 ) ;
V_127 = 0 ;
V_12 = 0 ;
goto V_148;
}
if ( V_94 -> V_143 || ( V_126 && V_94 -> V_173 > 0 ) )
V_5 -> V_144 = V_12 ;
V_41:
F_66 ( V_48 ) ;
F_25 ( V_9 ) ;
F_7 ( L_60 , V_52 ) ;
return V_52 ;
}
static int F_118 ( struct V_6 * V_6 ,
struct V_1 * V_9 )
{
struct V_1 * V_95 = F_71 ( V_6 , NULL ,
NULL , NULL ) ;
int V_10 = ! V_95 || V_9 -> V_24 <= V_95 -> V_24 ;
F_25 ( V_95 ) ;
return V_10 ;
}
static int F_119 ( struct V_30 * V_30 ,
T_4 V_174 , unsigned V_37 ,
struct V_2 * V_2 )
{
struct V_6 * V_6 = F_30 ( V_30 ) ;
struct V_85 * V_86 = F_31 ( V_6 ) ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
T_4 V_96 = V_174 & V_175 ;
int V_176 = V_174 & ~ V_175 ;
int V_177 = V_176 + V_37 ;
T_4 V_135 ;
int V_46 ;
struct V_1 * V_9 , * V_95 ;
if ( F_103 ( V_86 -> V_140 ) == V_141 ) {
F_7 ( L_61 , V_2 ) ;
F_44 ( V_2 ) ;
return - V_142 ;
}
V_178:
F_110 ( V_2 ) ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 && V_9 != V_8 -> V_21 ) {
V_95 = F_71 ( V_6 , NULL , NULL , NULL ) ;
if ( V_9 -> V_24 > V_95 -> V_24 ) {
F_25 ( V_95 ) ;
F_7 ( L_62 ,
V_2 , V_9 ) ;
V_9 = F_13 ( V_9 ) ;
F_44 ( V_2 ) ;
F_120 ( V_6 ) ;
V_46 = F_121 ( V_8 -> V_179 ,
F_118 ( V_6 , V_9 ) ) ;
F_25 ( V_9 ) ;
if ( V_46 == - V_106 )
return V_46 ;
return - V_180 ;
}
F_25 ( V_95 ) ;
F_7 ( L_63 ,
V_2 , V_9 ) ;
if ( ! F_112 ( V_2 ) )
goto V_178;
V_46 = F_73 ( V_2 , NULL ) ;
if ( V_46 < 0 )
goto V_181;
goto V_178;
}
if ( F_93 ( V_2 ) ) {
F_7 ( L_64 , V_2 ) ;
return 0 ;
}
if ( V_176 == 0 && V_37 == V_28 )
return 0 ;
V_135 = F_33 ( V_6 ) ;
if ( V_96 >= V_135 ||
( V_176 == 0 && ( V_174 + V_37 ) >= V_135 &&
V_177 - V_176 != V_28 ) ) {
F_7 ( L_65 ,
V_2 , V_176 , V_177 , ( int ) V_28 ) ;
F_122 ( V_2 ,
0 , V_176 ,
V_177 , V_28 ) ;
return 0 ;
}
V_46 = F_29 ( V_30 , V_2 ) ;
if ( V_46 < 0 )
goto V_181;
goto V_178;
V_181:
F_44 ( V_2 ) ;
return V_46 ;
}
static int F_123 ( struct V_30 * V_30 , struct V_4 * V_5 ,
T_4 V_174 , unsigned V_37 , unsigned V_99 ,
struct V_2 * * V_182 , void * * V_183 )
{
struct V_6 * V_6 = F_30 ( V_30 ) ;
struct V_2 * V_2 ;
T_3 V_12 = V_174 >> V_76 ;
int V_46 ;
do {
V_2 = F_124 ( V_5 , V_12 , 0 ) ;
if ( ! V_2 )
return - V_80 ;
F_7 ( L_66 , V_30 ,
V_6 , V_2 , ( int ) V_174 , ( int ) V_37 ) ;
V_46 = F_119 ( V_30 , V_174 , V_37 , V_2 ) ;
if ( V_46 < 0 )
F_48 ( V_2 ) ;
else
* V_182 = V_2 ;
} while ( V_46 == - V_180 );
return V_46 ;
}
static int F_125 ( struct V_30 * V_30 , struct V_4 * V_5 ,
T_4 V_174 , unsigned V_37 , unsigned V_184 ,
struct V_2 * V_2 , void * V_183 )
{
struct V_6 * V_6 = F_30 ( V_30 ) ;
int V_185 = 0 ;
F_7 ( L_67 , V_30 ,
V_6 , V_2 , ( int ) V_174 , ( int ) V_184 , ( int ) V_37 ) ;
if ( ! F_93 ( V_2 ) ) {
if ( V_184 < V_37 ) {
V_184 = 0 ;
goto V_41;
}
F_35 ( V_2 ) ;
}
if ( V_174 + V_184 > F_33 ( V_6 ) )
V_185 = F_126 ( V_6 , V_174 + V_184 ) ;
F_127 ( V_2 ) ;
V_41:
F_44 ( V_2 ) ;
F_48 ( V_2 ) ;
if ( V_185 )
F_128 ( F_9 ( V_6 ) , V_186 , NULL ) ;
return V_184 ;
}
static T_7 F_129 ( struct V_187 * V_188 , struct V_189 * V_190 )
{
F_18 ( 1 ) ;
return - V_40 ;
}
static void F_130 ( T_8 * V_191 )
{
T_8 V_192 ;
F_131 ( & V_192 , F_132 ( V_193 ) ) ;
F_133 ( V_194 , & V_192 , V_191 ) ;
}
static void F_134 ( T_8 * V_191 )
{
F_133 ( V_195 , V_191 , NULL ) ;
}
static int F_135 ( struct V_196 * V_197 )
{
struct V_198 * V_199 = V_197 -> V_199 ;
struct V_6 * V_6 = F_30 ( V_199 -> V_200 ) ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_201 * V_202 = V_199 -> V_200 -> V_203 ;
struct V_2 * V_204 = NULL ;
T_4 V_36 = V_197 -> V_205 << V_76 ;
int V_73 , V_70 , V_10 ;
T_8 V_191 ;
F_130 ( & V_191 ) ;
F_7 ( L_68 ,
V_6 , F_136 ( V_6 ) , V_36 , ( V_206 ) V_28 ) ;
if ( V_202 -> V_207 & V_208 )
V_73 = V_74 | V_116 ;
else
V_73 = V_74 ;
V_70 = 0 ;
V_10 = F_137 ( V_8 , V_75 , V_73 , - 1 , & V_70 , & V_204 ) ;
if ( V_10 < 0 )
goto V_209;
F_7 ( L_69 ,
V_6 , V_36 , ( V_206 ) V_28 , F_138 ( V_70 ) ) ;
if ( ( V_70 & ( V_74 | V_116 ) ) ||
V_8 -> V_38 == V_39 ) {
V_71 -> V_72 = V_199 -> V_200 ;
V_10 = F_139 ( V_197 ) ;
V_71 -> V_72 = NULL ;
} else
V_10 = - V_180 ;
F_7 ( L_70 ,
V_6 , V_36 , ( V_206 ) V_28 , F_138 ( V_70 ) , V_10 ) ;
if ( V_204 )
F_48 ( V_204 ) ;
F_53 ( V_8 , V_70 ) ;
if ( V_10 != - V_180 )
goto V_209;
if ( V_36 >= V_28 ) {
V_10 = V_210 ;
} else {
int V_211 ;
struct V_4 * V_5 = V_6 -> V_114 ;
struct V_2 * V_2 = F_140 ( V_5 , 0 ,
F_141 ( V_5 ,
~ V_212 ) ) ;
if ( ! V_2 ) {
V_10 = V_213 ;
goto V_214;
}
V_211 = F_142 ( V_6 , V_2 ,
V_215 , true ) ;
if ( V_211 < 0 || V_36 >= F_33 ( V_6 ) ) {
F_44 ( V_2 ) ;
F_48 ( V_2 ) ;
if ( V_211 < 0 )
V_10 = V_211 ;
else
V_10 = V_210 ;
goto V_214;
}
if ( V_211 < V_28 )
F_34 ( V_2 , V_211 , V_28 ) ;
else
F_41 ( V_2 ) ;
F_35 ( V_2 ) ;
V_197 -> V_2 = V_2 ;
V_10 = V_216 | V_217 ;
V_214:
F_7 ( L_71 ,
V_6 , V_36 , ( V_206 ) V_28 , V_10 ) ;
}
V_209:
F_134 ( & V_191 ) ;
if ( V_10 < 0 )
V_10 = ( V_10 == - V_80 ) ? V_213 : V_210 ;
return V_10 ;
}
static int F_143 ( struct V_196 * V_197 )
{
struct V_198 * V_199 = V_197 -> V_199 ;
struct V_6 * V_6 = F_30 ( V_199 -> V_200 ) ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_201 * V_202 = V_199 -> V_200 -> V_203 ;
struct V_218 * V_219 ;
struct V_2 * V_2 = V_197 -> V_2 ;
T_4 V_36 = F_32 ( V_2 ) ;
T_4 V_92 = F_33 ( V_6 ) ;
V_206 V_37 ;
int V_73 , V_70 , V_10 ;
T_8 V_191 ;
V_219 = F_144 () ;
if ( ! V_219 )
return V_213 ;
F_130 ( & V_191 ) ;
if ( V_8 -> V_38 != V_39 ) {
struct V_2 * V_220 = NULL ;
if ( V_36 == 0 ) {
F_108 ( V_2 ) ;
V_220 = V_2 ;
}
V_10 = F_145 ( V_199 -> V_200 , V_220 ) ;
if ( V_220 )
F_44 ( V_220 ) ;
if ( V_10 < 0 )
goto V_221;
}
if ( V_36 + V_28 <= V_92 )
V_37 = V_28 ;
else
V_37 = V_92 & ~ V_175 ;
F_7 ( L_72 ,
V_6 , F_136 ( V_6 ) , V_36 , V_37 , V_92 ) ;
if ( V_202 -> V_207 & V_208 )
V_73 = V_138 | V_116 ;
else
V_73 = V_138 ;
V_70 = 0 ;
V_10 = F_137 ( V_8 , V_222 , V_73 , V_36 + V_37 ,
& V_70 , NULL ) ;
if ( V_10 < 0 )
goto V_221;
F_7 ( L_73 ,
V_6 , V_36 , V_37 , F_138 ( V_70 ) ) ;
F_146 ( V_199 -> V_200 ) ;
do {
F_108 ( V_2 ) ;
if ( ( V_36 > V_92 ) || ( V_2 -> V_5 != V_6 -> V_114 ) ) {
F_44 ( V_2 ) ;
V_10 = V_223 ;
break;
}
V_10 = F_119 ( V_199 -> V_200 , V_36 , V_37 , V_2 ) ;
if ( V_10 >= 0 ) {
F_127 ( V_2 ) ;
V_10 = V_217 ;
}
} while ( V_10 == - V_180 );
if ( V_10 == V_217 ||
V_8 -> V_38 != V_39 ) {
int V_224 ;
F_10 ( & V_8 -> V_13 ) ;
V_8 -> V_38 = V_39 ;
V_224 = F_147 ( V_8 , V_222 ,
& V_219 ) ;
F_15 ( & V_8 -> V_13 ) ;
if ( V_224 )
F_148 ( V_6 , V_224 ) ;
}
F_7 ( L_74 ,
V_6 , V_36 , V_37 , F_138 ( V_70 ) , V_10 ) ;
F_53 ( V_8 , V_70 ) ;
V_221:
F_134 ( & V_191 ) ;
F_149 ( V_219 ) ;
if ( V_10 < 0 )
V_10 = ( V_10 == - V_80 ) ? V_213 : V_210 ;
return V_10 ;
}
void F_150 ( struct V_6 * V_6 , struct V_2 * V_220 ,
char * V_225 , V_206 V_37 )
{
struct V_4 * V_5 = V_6 -> V_114 ;
struct V_2 * V_2 ;
if ( V_220 ) {
V_2 = V_220 ;
} else {
if ( F_33 ( V_6 ) == 0 )
return;
V_2 = F_140 ( V_5 , 0 ,
F_141 ( V_5 ,
~ V_212 ) ) ;
if ( ! V_2 )
return;
if ( F_93 ( V_2 ) ) {
F_44 ( V_2 ) ;
F_48 ( V_2 ) ;
return;
}
}
F_7 ( L_75 ,
V_6 , F_136 ( V_6 ) , V_37 , V_220 ) ;
if ( V_37 > 0 ) {
void * V_226 = F_151 ( V_2 ) ;
memcpy ( V_226 , V_225 , V_37 ) ;
F_152 ( V_226 ) ;
}
if ( V_2 != V_220 ) {
if ( V_37 < V_28 )
F_34 ( V_2 , V_37 , V_28 ) ;
else
F_41 ( V_2 ) ;
F_35 ( V_2 ) ;
F_44 ( V_2 ) ;
F_48 ( V_2 ) ;
}
}
int F_145 ( struct V_30 * V_31 , struct V_2 * V_220 )
{
struct V_6 * V_6 = F_30 ( V_31 ) ;
struct V_7 * V_8 = F_9 ( V_6 ) ;
struct V_85 * V_86 = F_31 ( V_6 ) ;
struct V_47 * V_48 ;
struct V_2 * V_2 = NULL ;
T_2 V_37 , V_227 ;
int V_35 = 0 ;
bool V_228 = false ;
F_10 ( & V_8 -> V_13 ) ;
V_227 = V_8 -> V_38 ;
F_15 ( & V_8 -> V_13 ) ;
F_7 ( L_76 ,
V_6 , F_136 ( V_6 ) , V_227 ) ;
if ( V_227 == 1 ||
V_227 == V_39 )
goto V_41;
if ( V_220 ) {
V_2 = V_220 ;
F_18 ( ! F_93 ( V_2 ) ) ;
} else if ( F_92 ( V_8 ) &
( V_74 | V_116 ) ) {
V_2 = F_153 ( V_6 -> V_114 , 0 ) ;
if ( V_2 ) {
if ( F_93 ( V_2 ) ) {
V_228 = true ;
F_108 ( V_2 ) ;
} else {
F_48 ( V_2 ) ;
V_2 = NULL ;
}
}
}
if ( V_2 ) {
V_37 = F_33 ( V_6 ) ;
if ( V_37 > V_28 )
V_37 = V_28 ;
} else {
V_2 = F_154 ( V_162 ) ;
if ( ! V_2 ) {
V_35 = - V_80 ;
goto V_41;
}
V_35 = F_142 ( V_6 , V_2 ,
V_215 , true ) ;
if ( V_35 < 0 ) {
if ( V_35 == - V_229 )
V_35 = 0 ;
goto V_41;
}
V_37 = V_35 ;
}
V_48 = F_57 ( & V_86 -> V_34 -> V_33 , & V_8 -> V_42 ,
F_38 ( V_6 ) , 0 , & V_37 , 0 , 1 ,
V_230 , V_168 ,
NULL , 0 , 0 , false ) ;
if ( F_58 ( V_48 ) ) {
V_35 = F_59 ( V_48 ) ;
goto V_41;
}
V_48 -> V_172 = V_6 -> V_104 ;
V_35 = F_65 ( & V_86 -> V_34 -> V_33 , V_48 , false ) ;
if ( ! V_35 )
V_35 = F_155 ( & V_86 -> V_34 -> V_33 , V_48 ) ;
F_66 ( V_48 ) ;
if ( V_35 < 0 )
goto V_41;
V_48 = F_57 ( & V_86 -> V_34 -> V_33 , & V_8 -> V_42 ,
F_38 ( V_6 ) , 0 , & V_37 , 1 , 3 ,
V_120 , V_168 ,
NULL , V_8 -> V_43 ,
V_8 -> V_44 , false ) ;
if ( F_58 ( V_48 ) ) {
V_35 = F_59 ( V_48 ) ;
goto V_41;
}
F_64 ( V_48 , 1 , & V_2 , V_37 , 0 , false , false ) ;
{
T_9 V_231 = F_156 ( V_227 ) ;
V_35 = F_157 ( V_48 , 0 , V_232 ,
L_77 , & V_231 ,
sizeof( V_231 ) ,
V_233 ,
V_234 ) ;
if ( V_35 )
goto V_81;
}
{
char V_231 [ 32 ] ;
int V_235 = snprintf ( V_231 , sizeof( V_231 ) ,
L_78 , V_227 ) ;
V_35 = F_157 ( V_48 , 2 , V_236 ,
L_77 ,
V_231 , V_235 , 0 , 0 ) ;
if ( V_35 )
goto V_81;
}
V_48 -> V_172 = V_6 -> V_104 ;
V_35 = F_65 ( & V_86 -> V_34 -> V_33 , V_48 , false ) ;
if ( ! V_35 )
V_35 = F_155 ( & V_86 -> V_34 -> V_33 , V_48 ) ;
V_81:
F_66 ( V_48 ) ;
if ( V_35 == - V_237 )
V_35 = 0 ;
V_41:
if ( V_2 && V_2 != V_220 ) {
if ( V_228 ) {
F_44 ( V_2 ) ;
F_48 ( V_2 ) ;
} else
F_158 ( V_2 , 0 ) ;
}
F_7 ( L_79 ,
V_6 , F_136 ( V_6 ) , V_227 , V_35 ) ;
return V_35 ;
}
int F_159 ( struct V_30 * V_30 , struct V_198 * V_199 )
{
struct V_4 * V_5 = V_30 -> V_238 ;
if ( ! V_5 -> V_239 -> V_240 )
return - V_241 ;
F_160 ( V_30 ) ;
V_199 -> V_242 = & V_243 ;
return 0 ;
}
static int F_161 ( struct V_7 * V_8 ,
T_10 V_156 , struct V_244 * V_245 )
{
struct V_85 * V_86 = F_31 ( & V_8 -> V_246 ) ;
struct V_247 * V_248 = V_86 -> V_248 ;
struct V_47 * V_249 = NULL , * V_250 = NULL ;
struct V_251 * * V_252 , * V_253 ;
struct V_254 * V_255 ;
struct V_2 * * V_59 ;
V_206 V_256 ;
int V_35 = 0 , V_257 = 0 , V_258 = 0 ;
F_162 ( & V_248 -> V_259 ) ;
V_252 = & V_248 -> V_260 . V_251 ;
while ( * V_252 ) {
V_255 = F_163 ( * V_252 , struct V_254 , V_261 ) ;
if ( V_156 < V_255 -> V_156 )
V_252 = & ( * V_252 ) -> V_262 ;
else if ( V_156 > V_255 -> V_156 )
V_252 = & ( * V_252 ) -> V_263 ;
else {
int V_10 = F_164 ( V_245 ,
V_255 -> V_245 ,
V_255 -> V_256 ) ;
if ( V_10 < 0 )
V_252 = & ( * V_252 ) -> V_262 ;
else if ( V_10 > 0 )
V_252 = & ( * V_252 ) -> V_263 ;
else {
V_258 = V_255 -> V_255 ;
break;
}
}
}
F_165 ( & V_248 -> V_259 ) ;
if ( * V_252 )
goto V_41;
if ( V_245 )
F_7 ( L_80 ,
V_156 , ( int ) V_245 -> V_37 , V_245 -> V_264 ) ;
else
F_7 ( L_81 , V_156 ) ;
F_166 ( & V_248 -> V_259 ) ;
V_252 = & V_248 -> V_260 . V_251 ;
V_253 = NULL ;
while ( * V_252 ) {
V_253 = * V_252 ;
V_255 = F_163 ( V_253 , struct V_254 , V_261 ) ;
if ( V_156 < V_255 -> V_156 )
V_252 = & ( * V_252 ) -> V_262 ;
else if ( V_156 > V_255 -> V_156 )
V_252 = & ( * V_252 ) -> V_263 ;
else {
int V_10 = F_164 ( V_245 ,
V_255 -> V_245 ,
V_255 -> V_256 ) ;
if ( V_10 < 0 )
V_252 = & ( * V_252 ) -> V_262 ;
else if ( V_10 > 0 )
V_252 = & ( * V_252 ) -> V_263 ;
else {
V_258 = V_255 -> V_255 ;
break;
}
}
}
if ( * V_252 ) {
F_167 ( & V_248 -> V_259 ) ;
goto V_41;
}
V_249 = F_168 ( & V_86 -> V_34 -> V_33 , NULL ,
1 , false , V_162 ) ;
if ( ! V_249 ) {
V_35 = - V_80 ;
goto V_265;
}
V_249 -> V_266 = V_78 ;
F_117 ( V_249 , 0 , V_267 , 0 ) ;
V_249 -> V_268 . V_156 = V_156 ;
if ( V_245 )
V_249 -> V_268 . V_245 = F_169 ( V_245 ) ;
F_170 ( & V_249 -> V_269 , L_82 , V_8 -> V_270 . V_271 ) ;
V_35 = F_171 ( V_249 , V_162 ) ;
if ( V_35 )
goto V_265;
V_250 = F_168 ( & V_86 -> V_34 -> V_33 , NULL ,
1 , false , V_162 ) ;
if ( ! V_250 ) {
V_35 = - V_80 ;
goto V_265;
}
V_250 -> V_266 = V_168 ;
F_117 ( V_250 , 0 , V_230 , V_272 ) ;
F_172 ( & V_250 -> V_268 , & V_249 -> V_268 ) ;
F_173 ( & V_250 -> V_269 , & V_249 -> V_269 ) ;
V_35 = F_171 ( V_250 , V_162 ) ;
if ( V_35 )
goto V_265;
V_59 = F_174 ( 1 , V_79 ) ;
if ( F_58 ( V_59 ) ) {
V_35 = F_59 ( V_59 ) ;
goto V_265;
}
F_175 ( V_249 , 0 , V_59 , V_28 ,
0 , false , true ) ;
V_35 = F_65 ( & V_86 -> V_34 -> V_33 , V_249 , false ) ;
V_250 -> V_172 = V_8 -> V_246 . V_104 ;
V_250 -> V_273 = true ;
V_257 = F_65 ( & V_86 -> V_34 -> V_33 , V_250 , false ) ;
if ( ! V_35 )
V_35 = F_155 ( & V_86 -> V_34 -> V_33 , V_249 ) ;
if ( ! V_257 )
V_257 = F_155 ( & V_86 -> V_34 -> V_33 , V_250 ) ;
if ( V_35 >= 0 || V_35 == - V_45 )
V_258 |= V_274 ;
else if ( V_35 != - V_275 )
goto V_265;
if ( V_257 == 0 || V_257 == - V_276 )
V_258 |= V_277 ;
else if ( V_257 != - V_275 ) {
V_35 = V_257 ;
goto V_265;
}
V_256 = V_245 ? V_245 -> V_37 : 0 ;
V_255 = F_60 ( sizeof( * V_255 ) + V_256 + 1 , V_162 ) ;
if ( ! V_255 ) {
V_35 = - V_80 ;
goto V_265;
}
V_255 -> V_156 = V_156 ;
V_255 -> V_255 = V_258 ;
V_255 -> V_256 = V_256 ;
if ( V_256 > 0 )
memcpy ( V_255 -> V_245 , V_245 -> V_264 , V_256 ) ;
V_255 -> V_245 [ V_256 ] = 0 ;
F_176 ( & V_255 -> V_261 , V_253 , V_252 ) ;
F_177 ( & V_255 -> V_261 , & V_248 -> V_260 ) ;
V_35 = 0 ;
V_265:
F_167 ( & V_248 -> V_259 ) ;
F_66 ( V_249 ) ;
F_66 ( V_250 ) ;
V_41:
if ( ! V_35 )
V_35 = V_258 ;
if ( V_245 )
F_7 ( L_83 ,
V_156 , ( int ) V_245 -> V_37 , V_245 -> V_264 , V_35 ) ;
else
F_7 ( L_84 , V_156 , V_35 ) ;
return V_35 ;
}
int F_178 ( struct V_7 * V_8 , int V_278 )
{
T_10 V_156 ;
struct V_244 * V_245 ;
int V_10 , V_99 ;
if ( V_8 -> V_270 . V_279 != V_280 ) {
return 0 ;
}
if ( F_179 ( F_31 ( & V_8 -> V_246 ) ,
V_281 ) )
return 0 ;
F_10 ( & V_8 -> V_13 ) ;
V_99 = V_8 -> V_282 ;
V_156 = V_8 -> V_42 . V_283 ;
F_15 ( & V_8 -> V_13 ) ;
V_284:
if ( V_99 & V_285 ) {
if ( ( V_278 & V_75 ) && ! ( V_99 & V_286 ) ) {
F_7 ( L_85 ,
V_156 ) ;
return - V_275 ;
}
if ( ( V_278 & V_222 ) && ! ( V_99 & V_287 ) ) {
F_7 ( L_86 ,
V_156 ) ;
return - V_275 ;
}
return 0 ;
}
V_245 = F_180 ( V_8 -> V_42 . V_245 ) ;
V_10 = F_161 ( V_8 , V_156 , V_245 ) ;
F_181 ( V_245 ) ;
if ( V_10 < 0 )
return V_10 ;
V_99 = V_285 ;
if ( V_10 & V_274 )
V_99 |= V_286 ;
if ( V_10 & V_277 )
V_99 |= V_287 ;
F_10 ( & V_8 -> V_13 ) ;
if ( V_156 == V_8 -> V_42 . V_283 &&
V_245 == F_182 ( V_8 -> V_42 . V_245 ) ) {
V_8 -> V_282 |= V_99 ;
} else {
V_156 = V_8 -> V_42 . V_283 ;
V_99 = V_8 -> V_282 ;
}
F_15 ( & V_8 -> V_13 ) ;
goto V_284;
}
void F_183 ( struct V_247 * V_248 )
{
struct V_254 * V_255 ;
struct V_251 * V_288 ;
while ( ! F_184 ( & V_248 -> V_260 ) ) {
V_288 = F_185 ( & V_248 -> V_260 ) ;
V_255 = F_163 ( V_288 , struct V_254 , V_261 ) ;
F_186 ( V_288 , & V_248 -> V_260 ) ;
F_49 ( V_255 ) ;
}
}
