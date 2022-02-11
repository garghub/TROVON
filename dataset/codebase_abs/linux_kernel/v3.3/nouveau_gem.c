int
F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
void
F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_7 ;
if ( ! V_4 )
return;
V_4 -> V_2 = NULL ;
if ( F_3 ( V_4 -> V_8 ) ) {
V_4 -> V_8 = 1 ;
F_4 ( V_4 ) ;
}
F_5 ( & V_7 ) ;
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
}
int
F_8 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_11 * V_12 = V_11 ( V_10 ) ;
struct V_3 * V_4 = F_9 ( V_2 ) ;
struct V_13 * V_14 ;
int V_15 ;
if ( ! V_12 -> V_16 )
return 0 ;
V_15 = F_10 ( & V_4 -> V_7 , false , false , false , 0 ) ;
if ( V_15 )
return V_15 ;
V_14 = F_11 ( V_4 , V_12 -> V_16 ) ;
if ( ! V_14 ) {
V_14 = F_12 ( sizeof( * V_14 ) , V_17 ) ;
if ( ! V_14 ) {
V_15 = - V_18 ;
goto V_19;
}
V_15 = F_13 ( V_4 , V_12 -> V_16 , V_14 ) ;
if ( V_15 ) {
F_7 ( V_14 ) ;
goto V_19;
}
} else {
V_14 -> V_20 ++ ;
}
V_19:
F_14 ( & V_4 -> V_7 ) ;
return V_15 ;
}
void
F_15 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_11 * V_12 = V_11 ( V_10 ) ;
struct V_3 * V_4 = F_9 ( V_2 ) ;
struct V_13 * V_14 ;
int V_15 ;
if ( ! V_12 -> V_16 )
return;
V_15 = F_10 ( & V_4 -> V_7 , false , false , false , 0 ) ;
if ( V_15 )
return;
V_14 = F_11 ( V_4 , V_12 -> V_16 ) ;
if ( V_14 ) {
if ( -- V_14 -> V_20 == 0 ) {
F_16 ( V_4 , V_14 ) ;
F_7 ( V_14 ) ;
}
}
F_14 ( & V_4 -> V_7 ) ;
}
int
F_17 ( struct V_21 * V_22 , int V_23 , int V_24 , T_1 V_25 ,
T_1 V_26 , T_1 V_27 ,
struct V_3 * * V_28 )
{
struct V_29 * V_30 = V_22 -> V_31 ;
struct V_3 * V_4 ;
T_2 V_32 = 0 ;
int V_15 ;
if ( V_25 & V_33 )
V_32 |= V_34 ;
if ( V_25 & V_35 )
V_32 |= V_36 ;
if ( ! V_32 || V_25 & V_37 )
V_32 |= V_38 ;
V_15 = F_18 ( V_22 , V_23 , V_24 , V_32 , V_26 ,
V_27 , V_28 ) ;
if ( V_15 )
return V_15 ;
V_4 = * V_28 ;
V_4 -> V_39 = V_33 |
V_35 ;
if ( V_30 -> V_40 >= V_41 )
V_4 -> V_39 &= V_25 ;
V_4 -> V_2 = F_19 ( V_22 , V_4 -> V_7 . V_42 . V_23 ) ;
if ( ! V_4 -> V_2 ) {
F_20 ( NULL , V_28 ) ;
return - V_18 ;
}
V_4 -> V_7 . V_43 = V_4 -> V_2 -> V_44 ;
V_4 -> V_2 -> V_5 = V_4 ;
return 0 ;
}
static int
F_21 ( struct V_9 * V_10 , struct V_1 * V_2 ,
struct V_45 * V_46 )
{
struct V_11 * V_12 = V_11 ( V_10 ) ;
struct V_3 * V_4 = F_9 ( V_2 ) ;
struct V_13 * V_14 ;
if ( V_4 -> V_7 . V_42 . V_47 == V_48 )
V_46 -> V_25 = V_35 ;
else
V_46 -> V_25 = V_33 ;
V_46 -> V_49 = V_4 -> V_7 . V_49 ;
if ( V_12 -> V_16 ) {
V_14 = F_11 ( V_4 , V_12 -> V_16 ) ;
if ( ! V_14 )
return - V_50 ;
V_46 -> V_49 = V_14 -> V_49 ;
}
V_46 -> V_23 = V_4 -> V_7 . V_42 . V_51 << V_52 ;
V_46 -> V_53 = V_4 -> V_7 . V_54 ;
V_46 -> V_26 = V_4 -> V_26 ;
V_46 -> V_27 = V_4 -> V_27 ;
return 0 ;
}
int
F_22 ( struct V_21 * V_22 , void * V_55 ,
struct V_9 * V_10 )
{
struct V_29 * V_30 = V_22 -> V_31 ;
struct V_56 * V_57 = V_55 ;
struct V_3 * V_4 = NULL ;
int V_15 = 0 ;
if ( F_3 ( V_30 -> V_58 . V_59 . V_60 == NULL ) )
V_30 -> V_58 . V_59 . V_60 = V_30 -> V_22 -> V_60 ;
if ( ! V_30 -> V_61 . V_62 . V_63 ( V_22 , V_57 -> V_64 . V_27 ) ) {
F_23 ( V_22 , L_1 , V_57 -> V_64 . V_27 ) ;
return - V_50 ;
}
V_15 = F_17 ( V_22 , V_57 -> V_64 . V_23 , V_57 -> V_24 ,
V_57 -> V_64 . V_25 , V_57 -> V_64 . V_26 ,
V_57 -> V_64 . V_27 , & V_4 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_24 ( V_10 , V_4 -> V_2 , & V_57 -> V_64 . V_65 ) ;
if ( V_15 == 0 ) {
V_15 = F_21 ( V_10 , V_4 -> V_2 , & V_57 -> V_64 ) ;
if ( V_15 )
F_25 ( V_10 , V_57 -> V_64 . V_65 ) ;
}
F_26 ( V_4 -> V_2 ) ;
return V_15 ;
}
static int
F_27 ( struct V_1 * V_2 , T_1 V_66 ,
T_1 V_67 , T_1 V_39 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_7 ;
T_1 V_68 = V_39 & V_4 -> V_39 &
( V_67 ? V_67 : V_66 ) ;
T_1 V_69 = 0 , V_70 = 0 ;
if ( ! V_68 )
return - V_50 ;
if ( V_39 & V_33 )
V_70 |= V_34 ;
if ( V_39 & V_35 )
V_70 |= V_36 ;
if ( ( V_68 & V_33 ) &&
V_7 -> V_42 . V_47 == V_71 )
V_69 |= V_34 ;
else if ( ( V_68 & V_35 ) &&
V_7 -> V_42 . V_47 == V_48 )
V_69 |= V_36 ;
else if ( V_68 & V_33 )
V_69 |= V_34 ;
else
V_69 |= V_36 ;
F_28 ( V_4 , V_69 , V_70 ) ;
return 0 ;
}
static void
F_29 ( struct V_72 * V_73 , struct V_74 * V_75 )
{
struct V_72 * V_76 , * V_77 ;
struct V_3 * V_4 ;
F_30 (entry, tmp, list) {
V_4 = F_31 ( V_76 , struct V_3 , V_76 ) ;
F_32 ( V_4 , V_75 ) ;
if ( F_3 ( V_4 -> V_78 ) ) {
F_33 ( & V_4 -> V_79 ) ;
V_4 -> V_78 = false ;
}
F_34 ( & V_4 -> V_76 ) ;
V_4 -> V_80 = NULL ;
F_14 ( & V_4 -> V_7 ) ;
F_26 ( V_4 -> V_2 ) ;
}
}
static void
F_35 ( struct V_81 * V_82 , struct V_74 * V_75 )
{
F_29 ( & V_82 -> V_83 , V_75 ) ;
F_29 ( & V_82 -> V_84 , V_75 ) ;
F_29 ( & V_82 -> V_85 , V_75 ) ;
}
static int
F_36 ( struct V_86 * V_87 , struct V_9 * V_10 ,
struct V_88 * V_89 ,
int V_90 , struct V_81 * V_82 )
{
struct V_21 * V_22 = V_87 -> V_22 ;
struct V_29 * V_30 = V_22 -> V_31 ;
T_1 V_91 ;
int V_92 = 0 ;
int V_15 , V_93 ;
V_91 = F_37 ( 1 , & V_30 -> V_58 . V_94 ) ;
V_95:
if ( ++ V_92 > 100000 ) {
F_23 ( V_22 , L_2 , V_96 ) ;
return - V_50 ;
}
for ( V_93 = 0 ; V_93 < V_90 ; V_93 ++ ) {
struct V_88 * V_97 = & V_89 [ V_93 ] ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_38 ( V_22 , V_10 , V_97 -> V_65 ) ;
if ( ! V_2 ) {
F_23 ( V_22 , L_3 , V_97 -> V_65 ) ;
F_35 ( V_82 , NULL ) ;
return - V_98 ;
}
V_4 = V_2 -> V_5 ;
if ( V_4 -> V_80 && V_4 -> V_80 == V_10 ) {
F_23 ( V_22 , L_4
L_5 , V_97 -> V_65 ) ;
F_35 ( V_82 , NULL ) ;
return - V_50 ;
}
V_15 = F_10 ( & V_4 -> V_7 , true , false , true , V_91 ) ;
if ( V_15 ) {
F_35 ( V_82 , NULL ) ;
if ( F_3 ( V_15 == - V_99 ) )
V_15 = F_39 ( & V_4 -> V_7 , true ) ;
F_26 ( V_2 ) ;
if ( F_3 ( V_15 ) ) {
if ( V_15 != - V_100 )
F_23 ( V_22 , L_6 ) ;
return V_15 ;
}
goto V_95;
}
V_97 -> V_101 = ( V_102 ) ( unsigned long ) V_4 ;
V_4 -> V_80 = V_10 ;
V_4 -> V_103 = V_93 ;
if ( ( V_97 -> V_39 & V_33 ) &&
( V_97 -> V_39 & V_35 ) )
F_40 ( & V_4 -> V_76 , & V_82 -> V_85 ) ;
else
if ( V_97 -> V_39 & V_33 )
F_40 ( & V_4 -> V_76 , & V_82 -> V_83 ) ;
else
if ( V_97 -> V_39 & V_35 )
F_40 ( & V_4 -> V_76 , & V_82 -> V_84 ) ;
else {
F_23 ( V_22 , L_7 ,
V_97 -> V_39 ) ;
F_40 ( & V_4 -> V_76 , & V_82 -> V_85 ) ;
F_35 ( V_82 , NULL ) ;
return - V_50 ;
}
}
return 0 ;
}
static int
F_41 ( struct V_86 * V_87 , struct V_3 * V_4 )
{
struct V_74 * V_75 = NULL ;
int V_15 = 0 ;
F_42 ( & V_4 -> V_7 . V_59 -> V_104 ) ;
if ( V_4 -> V_7 . V_105 )
V_75 = F_43 ( V_4 -> V_7 . V_105 ) ;
F_44 ( & V_4 -> V_7 . V_59 -> V_104 ) ;
if ( V_75 ) {
V_15 = F_45 ( V_75 , V_87 ) ;
F_46 ( & V_75 ) ;
}
return V_15 ;
}
static int
F_47 ( struct V_86 * V_87 , struct V_72 * V_73 ,
struct V_88 * V_89 , V_102 V_106 )
{
struct V_29 * V_30 = V_87 -> V_22 -> V_31 ;
struct V_88 T_3 * V_107 =
( void V_108 T_3 * ) ( V_109 ) V_106 ;
struct V_21 * V_22 = V_87 -> V_22 ;
struct V_3 * V_4 ;
int V_15 , V_110 = 0 ;
F_48 (nvbo, list, entry) {
struct V_88 * V_97 = & V_89 [ V_4 -> V_103 ] ;
V_15 = F_41 ( V_87 , V_4 ) ;
if ( F_3 ( V_15 ) ) {
F_23 ( V_22 , L_8 ) ;
return V_15 ;
}
V_15 = F_27 ( V_4 -> V_2 , V_97 -> V_66 ,
V_97 -> V_67 ,
V_97 -> V_39 ) ;
if ( F_3 ( V_15 ) ) {
F_23 ( V_22 , L_9 ) ;
return V_15 ;
}
V_4 -> V_111 = ( V_97 -> V_66 & ( 1 << 31 ) ) ? NULL : V_87 ;
V_15 = F_49 ( V_4 , true , false , false ) ;
V_4 -> V_111 = NULL ;
if ( F_3 ( V_15 ) ) {
if ( V_15 != - V_100 )
F_23 ( V_22 , L_10 ) ;
return V_15 ;
}
V_15 = F_41 ( V_87 , V_4 ) ;
if ( F_3 ( V_15 ) ) {
F_23 ( V_22 , L_11 ) ;
return V_15 ;
}
if ( V_30 -> V_40 < V_41 ) {
if ( V_4 -> V_7 . V_49 == V_97 -> V_112 . V_49 &&
( ( V_4 -> V_7 . V_42 . V_47 == V_71 &&
V_97 -> V_112 . V_25 & V_33 ) ||
( V_4 -> V_7 . V_42 . V_47 == V_48 &&
V_97 -> V_112 . V_25 & V_35 ) ) )
continue;
if ( V_4 -> V_7 . V_42 . V_47 == V_48 )
V_97 -> V_112 . V_25 = V_35 ;
else
V_97 -> V_112 . V_25 = V_33 ;
V_97 -> V_112 . V_49 = V_4 -> V_7 . V_49 ;
V_97 -> V_112 . V_113 = 0 ;
V_110 ++ ;
if ( F_50 ( & V_107 [ V_4 -> V_103 ] . V_112 ,
& V_97 -> V_112 , sizeof( V_97 -> V_112 ) ) )
return - V_114 ;
}
}
return V_110 ;
}
static int
F_51 ( struct V_86 * V_87 ,
struct V_9 * V_10 ,
struct V_88 * V_89 ,
V_102 V_115 , int V_90 ,
struct V_81 * V_82 , int * V_116 )
{
struct V_21 * V_22 = V_87 -> V_22 ;
int V_15 , V_110 = 0 ;
F_52 ( & V_82 -> V_83 ) ;
F_52 ( & V_82 -> V_84 ) ;
F_52 ( & V_82 -> V_85 ) ;
if ( V_90 == 0 )
return 0 ;
V_15 = F_36 ( V_87 , V_10 , V_89 , V_90 , V_82 ) ;
if ( F_3 ( V_15 ) ) {
if ( V_15 != - V_100 )
F_23 ( V_22 , L_12 ) ;
return V_15 ;
}
V_15 = F_47 ( V_87 , & V_82 -> V_83 , V_89 , V_115 ) ;
if ( F_3 ( V_15 < 0 ) ) {
if ( V_15 != - V_100 )
F_23 ( V_22 , L_13 ) ;
F_35 ( V_82 , NULL ) ;
return V_15 ;
}
V_110 += V_15 ;
V_15 = F_47 ( V_87 , & V_82 -> V_84 , V_89 , V_115 ) ;
if ( F_3 ( V_15 < 0 ) ) {
if ( V_15 != - V_100 )
F_23 ( V_22 , L_14 ) ;
F_35 ( V_82 , NULL ) ;
return V_15 ;
}
V_110 += V_15 ;
V_15 = F_47 ( V_87 , & V_82 -> V_85 , V_89 , V_115 ) ;
if ( F_3 ( V_15 < 0 ) ) {
if ( V_15 != - V_100 )
F_23 ( V_22 , L_15 ) ;
F_35 ( V_82 , NULL ) ;
return V_15 ;
}
V_110 += V_15 ;
* V_116 = V_110 ;
return 0 ;
}
static inline void *
F_53 ( V_102 V_117 , unsigned V_118 , unsigned V_23 )
{
void * V_42 ;
void T_3 * V_119 = ( void V_108 T_3 * ) ( V_109 ) V_117 ;
V_42 = F_54 ( V_118 * V_23 , V_17 ) ;
if ( ! V_42 )
return F_55 ( - V_18 ) ;
if ( F_56 ( V_42 , V_119 , V_118 * V_23 ) ) {
F_7 ( V_42 ) ;
return F_55 ( - V_114 ) ;
}
return V_42 ;
}
static int
F_57 ( struct V_21 * V_22 ,
struct V_120 * V_57 ,
struct V_88 * V_7 )
{
struct V_121 * V_122 = NULL ;
int V_15 = 0 ;
unsigned V_93 ;
V_122 = F_53 ( V_57 -> V_110 , V_57 -> V_123 , sizeof( * V_122 ) ) ;
if ( F_58 ( V_122 ) )
return F_59 ( V_122 ) ;
for ( V_93 = 0 ; V_93 < V_57 -> V_123 ; V_93 ++ ) {
struct V_121 * V_124 = & V_122 [ V_93 ] ;
struct V_88 * V_97 ;
struct V_3 * V_4 ;
T_1 V_55 ;
if ( F_3 ( V_124 -> V_125 > V_57 -> V_90 ) ) {
F_23 ( V_22 , L_16 ) ;
V_15 = - V_50 ;
break;
}
V_97 = & V_7 [ V_124 -> V_125 ] ;
if ( V_97 -> V_112 . V_113 )
continue;
if ( F_3 ( V_124 -> V_126 > V_57 -> V_90 ) ) {
F_23 ( V_22 , L_17 ) ;
V_15 = - V_50 ;
break;
}
V_4 = ( void * ) ( unsigned long ) V_7 [ V_124 -> V_126 ] . V_101 ;
if ( F_3 ( V_124 -> V_127 + 4 >
V_4 -> V_7 . V_42 . V_51 << V_52 ) ) {
F_23 ( V_22 , L_18 ) ;
V_15 = - V_50 ;
break;
}
if ( ! V_4 -> V_79 . V_128 ) {
V_15 = F_60 ( & V_4 -> V_7 , 0 , V_4 -> V_7 . V_42 . V_51 ,
& V_4 -> V_79 ) ;
if ( V_15 ) {
F_23 ( V_22 , L_19 ) ;
break;
}
V_4 -> V_78 = true ;
}
if ( V_124 -> V_32 & V_129 )
V_55 = V_97 -> V_112 . V_49 + V_124 -> V_55 ;
else
if ( V_124 -> V_32 & V_130 )
V_55 = ( V_97 -> V_112 . V_49 + V_124 -> V_55 ) >> 32 ;
else
V_55 = V_124 -> V_55 ;
if ( V_124 -> V_32 & V_131 ) {
if ( V_97 -> V_112 . V_25 == V_35 )
V_55 |= V_124 -> V_132 ;
else
V_55 |= V_124 -> V_133 ;
}
F_42 ( & V_4 -> V_7 . V_59 -> V_104 ) ;
V_15 = F_61 ( & V_4 -> V_7 , false , false , false ) ;
F_44 ( & V_4 -> V_7 . V_59 -> V_104 ) ;
if ( V_15 ) {
F_23 ( V_22 , L_20 , V_15 ) ;
break;
}
F_62 ( V_4 , V_124 -> V_127 >> 2 , V_55 ) ;
}
F_7 ( V_122 ) ;
return V_15 ;
}
int
F_63 ( struct V_21 * V_22 , void * V_55 ,
struct V_9 * V_10 )
{
struct V_29 * V_30 = V_22 -> V_31 ;
struct V_120 * V_57 = V_55 ;
struct V_134 * V_135 ;
struct V_88 * V_7 ;
struct V_86 * V_87 ;
struct V_81 V_82 ;
struct V_74 * V_75 = NULL ;
int V_93 , V_136 , V_15 = 0 , V_137 = 0 ;
V_87 = F_64 ( V_10 , V_57 -> V_111 ) ;
if ( F_58 ( V_87 ) )
return F_59 ( V_87 ) ;
V_57 -> V_138 = V_30 -> V_139 ;
V_57 -> V_140 = V_30 -> V_141 . V_142 ;
if ( F_3 ( V_57 -> V_143 == 0 ) )
goto V_144;
if ( F_3 ( V_57 -> V_143 > V_145 ) ) {
F_23 ( V_22 , L_21 ,
V_57 -> V_143 , V_145 ) ;
F_65 ( & V_87 ) ;
return - V_50 ;
}
if ( F_3 ( V_57 -> V_90 > V_146 ) ) {
F_23 ( V_22 , L_22 ,
V_57 -> V_90 , V_146 ) ;
F_65 ( & V_87 ) ;
return - V_50 ;
}
if ( F_3 ( V_57 -> V_123 > V_147 ) ) {
F_23 ( V_22 , L_23 ,
V_57 -> V_123 , V_147 ) ;
F_65 ( & V_87 ) ;
return - V_50 ;
}
V_135 = F_53 ( V_57 -> V_135 , V_57 -> V_143 , sizeof( * V_135 ) ) ;
if ( F_58 ( V_135 ) ) {
F_65 ( & V_87 ) ;
return F_59 ( V_135 ) ;
}
V_7 = F_53 ( V_57 -> V_148 , V_57 -> V_90 , sizeof( * V_7 ) ) ;
if ( F_58 ( V_7 ) ) {
F_7 ( V_135 ) ;
F_65 ( & V_87 ) ;
return F_59 ( V_7 ) ;
}
for ( V_93 = 0 ; V_93 < V_57 -> V_143 ; V_93 ++ ) {
if ( V_135 [ V_93 ] . V_125 >= V_57 -> V_90 ) {
F_23 ( V_22 , L_24 , V_93 ) ;
V_15 = - V_50 ;
goto V_149;
}
V_7 [ V_135 [ V_93 ] . V_125 ] . V_66 |= ( 1 << 31 ) ;
}
V_15 = F_51 ( V_87 , V_10 , V_7 , V_57 -> V_148 ,
V_57 -> V_90 , & V_82 , & V_137 ) ;
if ( V_15 ) {
if ( V_15 != - V_100 )
F_23 ( V_22 , L_25 , V_15 ) ;
goto V_149;
}
if ( V_137 ) {
V_15 = F_57 ( V_22 , V_57 , V_7 ) ;
if ( V_15 ) {
F_23 ( V_22 , L_26 , V_15 ) ;
goto V_19;
}
}
if ( V_87 -> V_150 . V_151 ) {
V_15 = F_66 ( V_87 , V_57 -> V_143 + 1 , 6 ) ;
if ( V_15 ) {
F_67 ( V_22 , L_27 , V_15 ) ;
goto V_19;
}
for ( V_93 = 0 ; V_93 < V_57 -> V_143 ; V_93 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_135 [ V_93 ] . V_125 ] . V_101 ;
F_68 ( V_87 , V_4 , V_135 [ V_93 ] . V_49 ,
V_135 [ V_93 ] . V_152 ) ;
}
} else
if ( V_30 -> V_153 >= 0x25 ) {
V_15 = F_69 ( V_87 , V_57 -> V_143 * 2 ) ;
if ( V_15 ) {
F_23 ( V_22 , L_28 , V_15 ) ;
goto V_19;
}
for ( V_93 = 0 ; V_93 < V_57 -> V_143 ; V_93 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_135 [ V_93 ] . V_125 ] . V_101 ;
struct V_154 * V_42 = V_4 -> V_7 . V_42 . V_155 ;
F_70 ( V_87 , ( ( V_42 -> V_156 << V_52 ) +
V_135 [ V_93 ] . V_49 ) | 2 ) ;
F_70 ( V_87 , 0 ) ;
}
} else {
V_15 = F_69 ( V_87 , V_57 -> V_143 * ( 2 + V_157 ) ) ;
if ( V_15 ) {
F_23 ( V_22 , L_29 , V_15 ) ;
goto V_19;
}
for ( V_93 = 0 ; V_93 < V_57 -> V_143 ; V_93 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_135 [ V_93 ] . V_125 ] . V_101 ;
struct V_154 * V_42 = V_4 -> V_7 . V_42 . V_155 ;
T_1 V_158 ;
V_158 = V_87 -> V_159 + ( ( V_87 -> V_150 . V_160 + 2 ) << 2 ) ;
V_158 |= 0x20000000 ;
if ( F_3 ( V_158 != V_57 -> V_161 ) ) {
if ( ! V_4 -> V_79 . V_128 ) {
V_15 = F_60 ( & V_4 -> V_7 , 0 ,
V_4 -> V_7 . V_42 .
V_51 ,
& V_4 -> V_79 ) ;
if ( V_15 ) {
F_71 ( V_87 ) ;
goto V_19;
}
V_4 -> V_78 = true ;
}
F_62 ( V_4 , ( V_135 [ V_93 ] . V_49 +
V_135 [ V_93 ] . V_152 - 8 ) / 4 , V_158 ) ;
}
F_70 ( V_87 , ( ( V_42 -> V_156 << V_52 ) +
V_135 [ V_93 ] . V_49 ) | 0x20000000 ) ;
F_70 ( V_87 , 0 ) ;
for ( V_136 = 0 ; V_136 < V_157 ; V_136 ++ )
F_70 ( V_87 , 0 ) ;
}
}
V_15 = F_72 ( V_87 , & V_75 , true ) ;
if ( V_15 ) {
F_23 ( V_22 , L_30 , V_15 ) ;
F_71 ( V_87 ) ;
goto V_19;
}
V_19:
F_35 ( & V_82 , V_75 ) ;
F_46 ( & V_75 ) ;
V_149:
F_7 ( V_7 ) ;
F_7 ( V_135 ) ;
V_144:
if ( V_87 -> V_150 . V_151 ) {
V_57 -> V_161 = 0x00000000 ;
V_57 -> V_162 = 0x00000000 ;
} else
if ( V_30 -> V_153 >= 0x25 ) {
V_57 -> V_161 = 0x00020000 ;
V_57 -> V_162 = 0x00000000 ;
} else {
V_57 -> V_161 = 0x20000000 |
( V_87 -> V_159 + ( ( V_87 -> V_150 . V_160 + 2 ) << 2 ) ) ;
V_57 -> V_162 = 0x00000000 ;
}
F_65 ( & V_87 ) ;
return V_15 ;
}
static inline T_1
F_73 ( struct V_3 * V_4 , T_1 V_25 )
{
T_1 V_32 = 0 ;
if ( V_25 & V_33 )
V_32 |= V_34 ;
if ( V_25 & V_35 )
V_32 |= V_36 ;
return V_32 ;
}
int
F_74 ( struct V_21 * V_22 , void * V_55 ,
struct V_9 * V_10 )
{
struct V_163 * V_57 = V_55 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
bool V_164 = ! ! ( V_57 -> V_32 & V_165 ) ;
int V_15 = - V_50 ;
V_2 = F_38 ( V_22 , V_10 , V_57 -> V_65 ) ;
if ( ! V_2 )
return - V_98 ;
V_4 = F_9 ( V_2 ) ;
F_42 ( & V_4 -> V_7 . V_59 -> V_104 ) ;
V_15 = F_61 ( & V_4 -> V_7 , true , true , V_164 ) ;
F_44 ( & V_4 -> V_7 . V_59 -> V_104 ) ;
F_26 ( V_2 ) ;
return V_15 ;
}
int
F_75 ( struct V_21 * V_22 , void * V_55 ,
struct V_9 * V_10 )
{
return 0 ;
}
int
F_76 ( struct V_21 * V_22 , void * V_55 ,
struct V_9 * V_10 )
{
struct V_45 * V_57 = V_55 ;
struct V_1 * V_2 ;
int V_15 ;
V_2 = F_38 ( V_22 , V_10 , V_57 -> V_65 ) ;
if ( ! V_2 )
return - V_98 ;
V_15 = F_21 ( V_10 , V_2 , V_57 ) ;
F_26 ( V_2 ) ;
return V_15 ;
}
