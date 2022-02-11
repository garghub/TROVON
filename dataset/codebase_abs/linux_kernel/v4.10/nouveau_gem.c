void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_7 . V_8 ) ;
struct V_9 * V_7 = & V_4 -> V_7 ;
struct V_10 * V_11 = V_6 -> V_11 -> V_11 ;
int V_12 ;
V_12 = F_4 ( V_11 ) ;
if ( F_5 ( V_12 < 0 && V_12 != - V_13 ) )
return;
if ( V_2 -> V_14 )
F_6 ( V_2 , V_4 -> V_7 . V_15 ) ;
F_7 ( V_2 ) ;
V_2 -> V_16 = NULL ;
F_8 ( & V_7 ) ;
F_9 ( V_11 ) ;
F_10 ( V_11 ) ;
}
int
F_11 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_19 * V_20 = V_19 ( V_18 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_7 . V_8 ) ;
struct V_21 * V_22 ;
struct V_10 * V_11 = V_6 -> V_11 -> V_11 ;
int V_12 ;
if ( ! V_20 -> V_23 )
return 0 ;
V_12 = F_12 ( & V_4 -> V_7 , false , false , NULL ) ;
if ( V_12 )
return V_12 ;
V_22 = F_13 ( V_4 , V_20 -> V_23 ) ;
if ( ! V_22 ) {
V_22 = F_14 ( sizeof( * V_22 ) , V_24 ) ;
if ( ! V_22 ) {
V_12 = - V_25 ;
goto V_26;
}
V_12 = F_4 ( V_11 ) ;
if ( V_12 < 0 && V_12 != - V_13 ) {
F_15 ( V_22 ) ;
goto V_26;
}
V_12 = F_16 ( V_4 , V_20 -> V_23 , V_22 ) ;
if ( V_12 )
F_15 ( V_22 ) ;
F_9 ( V_11 ) ;
F_10 ( V_11 ) ;
} else {
V_22 -> V_27 ++ ;
}
V_26:
F_17 ( & V_4 -> V_7 ) ;
return V_12 ;
}
static void
F_18 ( void * V_28 )
{
struct V_21 * V_22 = V_28 ;
F_19 ( V_22 ) ;
F_20 ( V_22 ) ;
F_15 ( V_22 ) ;
}
static void
F_21 ( struct V_3 * V_4 , struct V_21 * V_22 )
{
const bool V_29 = V_4 -> V_7 . V_30 . V_31 != V_32 ;
struct V_33 * V_34 = V_4 -> V_7 . V_34 ;
struct V_35 * V_36 ;
struct V_37 * V_38 = NULL ;
V_36 = F_22 ( V_34 ) ;
F_23 ( & V_22 -> V_39 ) ;
if ( V_36 && V_36 -> V_40 > 1 )
F_24 ( & V_4 -> V_7 , false , false ) ;
else if ( V_36 && V_36 -> V_40 == 1 )
V_38 = F_25 ( V_36 -> V_41 [ 0 ] ,
F_26 ( V_34 ) ) ;
else
V_38 = F_27 ( V_4 -> V_7 . V_34 ) ;
if ( V_38 && V_29 ) {
F_28 ( V_38 , F_18 , V_22 ) ;
} else {
if ( V_29 )
F_19 ( V_22 ) ;
F_20 ( V_22 ) ;
F_15 ( V_22 ) ;
}
}
void
F_29 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_19 * V_20 = V_19 ( V_18 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_7 . V_8 ) ;
struct V_10 * V_11 = V_6 -> V_11 -> V_11 ;
struct V_21 * V_22 ;
int V_12 ;
if ( ! V_20 -> V_23 )
return;
V_12 = F_12 ( & V_4 -> V_7 , false , false , NULL ) ;
if ( V_12 )
return;
V_22 = F_13 ( V_4 , V_20 -> V_23 ) ;
if ( V_22 ) {
if ( -- V_22 -> V_27 == 0 ) {
V_12 = F_4 ( V_11 ) ;
if ( ! F_5 ( V_12 < 0 && V_12 != - V_13 ) ) {
F_21 ( V_4 , V_22 ) ;
F_9 ( V_11 ) ;
F_10 ( V_11 ) ;
}
}
}
F_17 ( & V_4 -> V_7 ) ;
}
int
F_30 ( struct V_42 * V_11 , int V_43 , int V_44 , T_1 V_45 ,
T_1 V_46 , T_1 V_47 ,
struct V_3 * * V_48 )
{
struct V_5 * V_6 = V_5 ( V_11 ) ;
struct V_3 * V_4 ;
T_2 V_49 = 0 ;
int V_12 ;
if ( V_45 & V_50 )
V_49 |= V_51 ;
if ( V_45 & V_52 )
V_49 |= V_53 ;
if ( ! V_49 || V_45 & V_54 )
V_49 |= V_55 ;
if ( V_45 & V_56 )
V_49 |= V_57 ;
V_12 = F_31 ( V_11 , V_43 , V_44 , V_49 , V_46 ,
V_47 , NULL , NULL , V_48 ) ;
if ( V_12 )
return V_12 ;
V_4 = * V_48 ;
V_4 -> V_58 = V_50 |
V_52 ;
if ( V_6 -> V_10 . V_59 . V_60 >= V_61 )
V_4 -> V_58 &= V_45 ;
V_12 = F_32 ( V_11 , & V_4 -> V_2 , V_4 -> V_7 . V_30 . V_43 ) ;
if ( V_12 ) {
F_33 ( NULL , V_48 ) ;
return - V_25 ;
}
V_4 -> V_7 . V_62 = V_4 -> V_2 . V_16 ;
return 0 ;
}
static int
F_34 ( struct V_17 * V_18 , struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_19 * V_20 = V_19 ( V_18 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_21 * V_22 ;
if ( F_35 ( V_4 -> V_58 ) )
V_64 -> V_45 = V_4 -> V_58 ;
else if ( V_4 -> V_7 . V_30 . V_31 == V_65 )
V_64 -> V_45 = V_52 ;
else
V_64 -> V_45 = V_50 ;
V_64 -> V_66 = V_4 -> V_7 . V_66 ;
if ( V_20 -> V_23 ) {
V_22 = F_13 ( V_4 , V_20 -> V_23 ) ;
if ( ! V_22 )
return - V_67 ;
V_64 -> V_66 = V_22 -> V_66 ;
}
V_64 -> V_43 = V_4 -> V_7 . V_30 . V_68 << V_69 ;
V_64 -> V_70 = F_36 ( & V_4 -> V_7 . V_71 ) ;
V_64 -> V_46 = V_4 -> V_46 ;
V_64 -> V_47 = V_4 -> V_47 ;
return 0 ;
}
int
F_37 ( struct V_42 * V_11 , void * V_28 ,
struct V_17 * V_18 )
{
struct V_5 * V_6 = V_5 ( V_11 ) ;
struct V_19 * V_20 = V_19 ( V_18 ) ;
struct V_72 * V_73 = F_38 ( & V_6 -> V_10 ) ;
struct V_74 * V_75 = V_28 ;
struct V_3 * V_4 = NULL ;
int V_12 = 0 ;
if ( ! F_39 ( V_73 , V_75 -> V_59 . V_47 ) ) {
F_40 ( V_76 , V_20 , L_1 , V_75 -> V_59 . V_47 ) ;
return - V_67 ;
}
V_12 = F_30 ( V_11 , V_75 -> V_59 . V_43 , V_75 -> V_44 ,
V_75 -> V_59 . V_45 , V_75 -> V_59 . V_46 ,
V_75 -> V_59 . V_47 , & V_4 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_41 ( V_18 , & V_4 -> V_2 , & V_75 -> V_59 . V_77 ) ;
if ( V_12 == 0 ) {
V_12 = F_34 ( V_18 , & V_4 -> V_2 , & V_75 -> V_59 ) ;
if ( V_12 )
F_42 ( V_18 , V_75 -> V_59 . V_77 ) ;
}
F_43 ( & V_4 -> V_2 ) ;
return V_12 ;
}
static int
F_44 ( struct V_1 * V_2 , T_1 V_78 ,
T_1 V_79 , T_1 V_58 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_7 = & V_4 -> V_7 ;
T_1 V_80 = V_58 & V_4 -> V_58 &
( V_79 ? V_79 : V_78 ) ;
T_1 V_81 = 0 , V_82 = 0 ;
if ( ! V_80 )
return - V_67 ;
if ( V_58 & V_50 )
V_82 |= V_51 ;
if ( V_58 & V_52 )
V_82 |= V_53 ;
if ( ( V_80 & V_50 ) &&
V_7 -> V_30 . V_31 == V_83 )
V_81 |= V_51 ;
else if ( ( V_80 & V_52 ) &&
V_7 -> V_30 . V_31 == V_65 )
V_81 |= V_53 ;
else if ( V_80 & V_50 )
V_81 |= V_51 ;
else
V_81 |= V_53 ;
F_45 ( V_4 , V_81 , V_82 ) ;
return 0 ;
}
static void
F_46 ( struct V_84 * V_85 , struct V_86 * V_38 ,
struct V_87 * V_88 )
{
struct V_3 * V_4 ;
struct V_87 * V_89 ;
while ( ! F_47 ( & V_85 -> V_90 ) ) {
V_4 = F_48 ( V_85 -> V_90 . V_91 , struct V_3 , V_92 ) ;
V_89 = & V_88 [ V_4 -> V_93 ] ;
if ( F_49 ( V_38 ) )
F_50 ( V_4 , V_38 , ! ! V_89 -> V_79 ) ;
if ( F_51 ( V_4 -> V_94 ) ) {
F_52 ( & V_4 -> V_95 ) ;
V_4 -> V_94 = false ;
}
F_23 ( & V_4 -> V_92 ) ;
V_4 -> V_96 = NULL ;
F_53 ( & V_4 -> V_7 , & V_85 -> V_97 ) ;
F_43 ( & V_4 -> V_2 ) ;
}
}
static void
F_54 ( struct V_84 * V_85 , struct V_86 * V_38 ,
struct V_87 * V_88 )
{
F_46 ( V_85 , V_38 , V_88 ) ;
F_55 ( & V_85 -> V_97 ) ;
}
static int
F_56 ( struct V_98 * V_99 , struct V_17 * V_18 ,
struct V_87 * V_88 ,
int V_100 , struct V_84 * V_85 )
{
struct V_19 * V_20 = V_19 ( V_18 ) ;
int V_101 = 0 ;
int V_12 = - V_67 , V_102 ;
struct V_3 * V_103 = NULL ;
F_57 ( V_104 ) ;
F_57 ( V_105 ) ;
F_57 ( V_106 ) ;
F_58 ( & V_85 -> V_97 , & V_107 ) ;
V_108:
if ( ++ V_101 > 100000 ) {
F_40 ( V_76 , V_20 , L_2 , V_109 ) ;
return - V_67 ;
}
for ( V_102 = 0 ; V_102 < V_100 ; V_102 ++ ) {
struct V_87 * V_89 = & V_88 [ V_102 ] ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_59 ( V_18 , V_89 -> V_77 ) ;
if ( ! V_2 ) {
F_40 ( V_76 , V_20 , L_3 , V_89 -> V_77 ) ;
V_12 = - V_110 ;
break;
}
V_4 = F_2 ( V_2 ) ;
if ( V_4 == V_103 ) {
V_103 = NULL ;
F_43 ( V_2 ) ;
continue;
}
if ( V_4 -> V_96 && V_4 -> V_96 == V_18 ) {
F_40 ( V_76 , V_20 , L_4
L_5 , V_89 -> V_77 ) ;
F_43 ( V_2 ) ;
V_12 = - V_67 ;
break;
}
V_12 = F_12 ( & V_4 -> V_7 , true , false , & V_85 -> V_97 ) ;
if ( V_12 ) {
F_60 ( & V_105 , & V_85 -> V_90 ) ;
F_60 ( & V_104 , & V_85 -> V_90 ) ;
F_60 ( & V_106 , & V_85 -> V_90 ) ;
F_46 ( V_85 , NULL , NULL ) ;
if ( F_51 ( V_12 == - V_111 ) ) {
V_12 = F_61 ( & V_4 -> V_7 , true ,
& V_85 -> V_97 ) ;
if ( ! V_12 )
V_103 = V_4 ;
}
if ( F_51 ( V_12 ) ) {
if ( V_12 != - V_112 )
F_40 ( V_76 , V_20 , L_6 ) ;
break;
}
}
V_89 -> V_113 = ( V_114 ) ( unsigned long ) V_4 ;
V_4 -> V_96 = V_18 ;
V_4 -> V_93 = V_102 ;
if ( ( V_89 -> V_58 & V_50 ) &&
( V_89 -> V_58 & V_52 ) )
F_62 ( & V_4 -> V_92 , & V_106 ) ;
else
if ( V_89 -> V_58 & V_50 )
F_62 ( & V_4 -> V_92 , & V_105 ) ;
else
if ( V_89 -> V_58 & V_52 )
F_62 ( & V_4 -> V_92 , & V_104 ) ;
else {
F_40 ( V_76 , V_20 , L_7 ,
V_89 -> V_58 ) ;
F_62 ( & V_4 -> V_92 , & V_106 ) ;
V_12 = - V_67 ;
break;
}
if ( V_4 == V_103 )
goto V_108;
}
F_63 ( & V_85 -> V_97 ) ;
F_64 ( & V_105 , & V_85 -> V_90 ) ;
F_64 ( & V_104 , & V_85 -> V_90 ) ;
F_64 ( & V_106 , & V_85 -> V_90 ) ;
if ( V_12 )
F_54 ( V_85 , NULL , NULL ) ;
return V_12 ;
}
static int
F_65 ( struct V_98 * V_99 , struct V_19 * V_20 ,
struct V_115 * V_90 , struct V_87 * V_88 ,
V_114 V_116 )
{
struct V_5 * V_6 = V_99 -> V_6 ;
struct V_87 T_3 * V_117 =
( void V_118 T_3 * ) ( V_119 ) V_116 ;
struct V_3 * V_4 ;
int V_12 , V_120 = 0 ;
F_66 (nvbo, list, entry) {
struct V_87 * V_89 = & V_88 [ V_4 -> V_93 ] ;
V_12 = F_44 ( & V_4 -> V_2 , V_89 -> V_78 ,
V_89 -> V_79 ,
V_89 -> V_58 ) ;
if ( F_51 ( V_12 ) ) {
F_40 ( V_76 , V_20 , L_8 ) ;
return V_12 ;
}
V_12 = F_67 ( V_4 , true , false ) ;
if ( F_51 ( V_12 ) ) {
if ( V_12 != - V_112 )
F_40 ( V_76 , V_20 , L_9 ) ;
return V_12 ;
}
V_12 = F_68 ( V_4 , V_99 , ! ! V_89 -> V_79 , true ) ;
if ( F_51 ( V_12 ) ) {
if ( V_12 != - V_112 )
F_40 ( V_76 , V_20 , L_10 ) ;
return V_12 ;
}
if ( V_6 -> V_10 . V_59 . V_60 < V_61 ) {
if ( V_4 -> V_7 . V_66 == V_89 -> V_121 . V_66 &&
( ( V_4 -> V_7 . V_30 . V_31 == V_83 &&
V_89 -> V_121 . V_45 & V_50 ) ||
( V_4 -> V_7 . V_30 . V_31 == V_65 &&
V_89 -> V_121 . V_45 & V_52 ) ) )
continue;
if ( V_4 -> V_7 . V_30 . V_31 == V_65 )
V_89 -> V_121 . V_45 = V_52 ;
else
V_89 -> V_121 . V_45 = V_50 ;
V_89 -> V_121 . V_66 = V_4 -> V_7 . V_66 ;
V_89 -> V_121 . V_122 = 0 ;
V_120 ++ ;
if ( F_69 ( & V_117 [ V_4 -> V_93 ] . V_121 ,
& V_89 -> V_121 , sizeof( V_89 -> V_121 ) ) )
return - V_123 ;
}
}
return V_120 ;
}
static int
F_70 ( struct V_98 * V_99 ,
struct V_17 * V_18 ,
struct V_87 * V_88 ,
V_114 V_124 , int V_100 ,
struct V_84 * V_85 , int * V_125 )
{
struct V_19 * V_20 = V_19 ( V_18 ) ;
int V_12 ;
F_71 ( & V_85 -> V_90 ) ;
if ( V_100 == 0 )
return 0 ;
V_12 = F_56 ( V_99 , V_18 , V_88 , V_100 , V_85 ) ;
if ( F_51 ( V_12 ) ) {
if ( V_12 != - V_112 )
F_40 ( V_76 , V_20 , L_11 ) ;
return V_12 ;
}
V_12 = F_65 ( V_99 , V_20 , & V_85 -> V_90 , V_88 , V_124 ) ;
if ( F_51 ( V_12 < 0 ) ) {
if ( V_12 != - V_112 )
F_40 ( V_76 , V_20 , L_12 ) ;
F_54 ( V_85 , NULL , NULL ) ;
return V_12 ;
}
* V_125 = V_12 ;
return 0 ;
}
static inline void
F_72 ( void * V_126 )
{
F_73 ( V_126 ) ;
}
static inline void *
F_74 ( V_114 V_127 , unsigned V_128 , unsigned V_43 )
{
void * V_30 ;
void T_3 * V_129 = ( void V_118 T_3 * ) ( V_119 ) V_127 ;
V_43 *= V_128 ;
V_30 = F_75 ( V_43 , V_24 | V_130 ) ;
if ( ! V_30 )
V_30 = F_76 ( V_43 ) ;
if ( ! V_30 )
return F_77 ( - V_25 ) ;
if ( F_78 ( V_30 , V_129 , V_43 ) ) {
F_72 ( V_30 ) ;
return F_77 ( - V_123 ) ;
}
return V_30 ;
}
static int
F_79 ( struct V_19 * V_20 ,
struct V_131 * V_75 ,
struct V_87 * V_7 )
{
struct V_132 * V_133 = NULL ;
int V_12 = 0 ;
unsigned V_102 ;
V_133 = F_74 ( V_75 -> V_120 , V_75 -> V_134 , sizeof( * V_133 ) ) ;
if ( F_80 ( V_133 ) )
return F_81 ( V_133 ) ;
for ( V_102 = 0 ; V_102 < V_75 -> V_134 ; V_102 ++ ) {
struct V_132 * V_135 = & V_133 [ V_102 ] ;
struct V_87 * V_89 ;
struct V_3 * V_4 ;
T_1 V_28 ;
if ( F_51 ( V_135 -> V_136 > V_75 -> V_100 ) ) {
F_40 ( V_76 , V_20 , L_13 ) ;
V_12 = - V_67 ;
break;
}
V_89 = & V_7 [ V_135 -> V_136 ] ;
if ( V_89 -> V_121 . V_122 )
continue;
if ( F_51 ( V_135 -> V_137 > V_75 -> V_100 ) ) {
F_40 ( V_76 , V_20 , L_14 ) ;
V_12 = - V_67 ;
break;
}
V_4 = ( void * ) ( unsigned long ) V_7 [ V_135 -> V_137 ] . V_113 ;
if ( F_51 ( V_135 -> V_138 + 4 >
V_4 -> V_7 . V_30 . V_68 << V_69 ) ) {
F_40 ( V_76 , V_20 , L_15 ) ;
V_12 = - V_67 ;
break;
}
if ( ! V_4 -> V_95 . V_139 ) {
V_12 = F_82 ( & V_4 -> V_7 , 0 , V_4 -> V_7 . V_30 . V_68 ,
& V_4 -> V_95 ) ;
if ( V_12 ) {
F_40 ( V_76 , V_20 , L_16 ) ;
break;
}
V_4 -> V_94 = true ;
}
if ( V_135 -> V_49 & V_140 )
V_28 = V_89 -> V_121 . V_66 + V_135 -> V_28 ;
else
if ( V_135 -> V_49 & V_141 )
V_28 = ( V_89 -> V_121 . V_66 + V_135 -> V_28 ) >> 32 ;
else
V_28 = V_135 -> V_28 ;
if ( V_135 -> V_49 & V_142 ) {
if ( V_89 -> V_121 . V_45 == V_52 )
V_28 |= V_135 -> V_143 ;
else
V_28 |= V_135 -> V_144 ;
}
V_12 = F_24 ( & V_4 -> V_7 , false , false ) ;
if ( V_12 ) {
F_40 ( V_76 , V_20 , L_17 , V_12 ) ;
break;
}
F_83 ( V_4 , V_135 -> V_138 >> 2 , V_28 ) ;
}
F_72 ( V_133 ) ;
return V_12 ;
}
int
F_84 ( struct V_42 * V_11 , void * V_28 ,
struct V_17 * V_18 )
{
struct V_145 * V_146 = F_85 ( V_18 ) ;
struct V_19 * V_20 = V_19 ( V_18 ) ;
struct V_147 * V_148 ;
struct V_5 * V_6 = V_5 ( V_11 ) ;
struct V_131 * V_75 = V_28 ;
struct V_149 * V_150 ;
struct V_87 * V_7 ;
struct V_98 * V_99 = NULL ;
struct V_84 V_85 ;
struct V_86 * V_38 = NULL ;
int V_102 , V_151 , V_12 = 0 , V_152 = 0 ;
if ( F_51 ( ! V_146 ) )
return - V_25 ;
F_66 (temp, &abi16->channels, head) {
if ( V_148 -> V_99 -> V_153 == V_75 -> V_154 ) {
V_99 = V_148 -> V_99 ;
break;
}
}
if ( ! V_99 )
return F_86 ( V_146 , - V_110 ) ;
V_75 -> V_155 = V_6 -> V_2 . V_155 ;
V_75 -> V_156 = V_6 -> V_2 . V_156 ;
if ( F_51 ( V_75 -> V_157 == 0 ) )
goto V_158;
if ( F_51 ( V_75 -> V_157 > V_159 ) ) {
F_40 ( V_76 , V_20 , L_18 ,
V_75 -> V_157 , V_159 ) ;
return F_86 ( V_146 , - V_67 ) ;
}
if ( F_51 ( V_75 -> V_100 > V_160 ) ) {
F_40 ( V_76 , V_20 , L_19 ,
V_75 -> V_100 , V_160 ) ;
return F_86 ( V_146 , - V_67 ) ;
}
if ( F_51 ( V_75 -> V_134 > V_161 ) ) {
F_40 ( V_76 , V_20 , L_20 ,
V_75 -> V_134 , V_161 ) ;
return F_86 ( V_146 , - V_67 ) ;
}
V_150 = F_74 ( V_75 -> V_150 , V_75 -> V_157 , sizeof( * V_150 ) ) ;
if ( F_80 ( V_150 ) )
return F_86 ( V_146 , F_81 ( V_150 ) ) ;
V_7 = F_74 ( V_75 -> V_162 , V_75 -> V_100 , sizeof( * V_7 ) ) ;
if ( F_80 ( V_7 ) ) {
F_72 ( V_150 ) ;
return F_86 ( V_146 , F_81 ( V_7 ) ) ;
}
for ( V_102 = 0 ; V_102 < V_75 -> V_157 ; V_102 ++ ) {
if ( V_150 [ V_102 ] . V_136 >= V_75 -> V_100 ) {
F_40 ( V_76 , V_20 , L_21 , V_102 ) ;
V_12 = - V_67 ;
goto V_163;
}
}
V_12 = F_70 ( V_99 , V_18 , V_7 , V_75 -> V_162 ,
V_75 -> V_100 , & V_85 , & V_152 ) ;
if ( V_12 ) {
if ( V_12 != - V_112 )
F_40 ( V_76 , V_20 , L_22 , V_12 ) ;
goto V_163;
}
if ( V_152 ) {
V_12 = F_79 ( V_20 , V_75 , V_7 ) ;
if ( V_12 ) {
F_40 ( V_76 , V_20 , L_23 , V_12 ) ;
goto V_26;
}
}
if ( V_99 -> V_164 . V_165 ) {
V_12 = F_87 ( V_99 , V_75 -> V_157 + 1 , 16 ) ;
if ( V_12 ) {
F_40 ( V_76 , V_20 , L_24 , V_12 ) ;
goto V_26;
}
for ( V_102 = 0 ; V_102 < V_75 -> V_157 ; V_102 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_150 [ V_102 ] . V_136 ] . V_113 ;
F_88 ( V_99 , V_4 , V_150 [ V_102 ] . V_66 ,
V_150 [ V_102 ] . V_166 ) ;
}
} else
if ( V_6 -> V_10 . V_59 . V_167 >= 0x25 ) {
V_12 = F_89 ( V_99 , V_75 -> V_157 * 2 ) ;
if ( V_12 ) {
F_40 ( V_76 , V_20 , L_25 , V_12 ) ;
goto V_26;
}
for ( V_102 = 0 ; V_102 < V_75 -> V_157 ; V_102 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_150 [ V_102 ] . V_136 ] . V_113 ;
F_90 ( V_99 , ( V_4 -> V_7 . V_66 + V_150 [ V_102 ] . V_66 ) | 2 ) ;
F_90 ( V_99 , 0 ) ;
}
} else {
V_12 = F_89 ( V_99 , V_75 -> V_157 * ( 2 + V_168 ) ) ;
if ( V_12 ) {
F_40 ( V_76 , V_20 , L_26 , V_12 ) ;
goto V_26;
}
for ( V_102 = 0 ; V_102 < V_75 -> V_157 ; V_102 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_150 [ V_102 ] . V_136 ] . V_113 ;
T_1 V_169 ;
V_169 = V_99 -> V_150 . V_22 . V_66 + ( ( V_99 -> V_164 . V_170 + 2 ) << 2 ) ;
V_169 |= 0x20000000 ;
if ( F_51 ( V_169 != V_75 -> V_171 ) ) {
if ( ! V_4 -> V_95 . V_139 ) {
V_12 = F_82 ( & V_4 -> V_7 , 0 ,
V_4 -> V_7 . V_30 .
V_68 ,
& V_4 -> V_95 ) ;
if ( V_12 ) {
F_91 ( V_99 ) ;
goto V_26;
}
V_4 -> V_94 = true ;
}
F_83 ( V_4 , ( V_150 [ V_102 ] . V_66 +
V_150 [ V_102 ] . V_166 - 8 ) / 4 , V_169 ) ;
}
F_90 ( V_99 , 0x20000000 |
( V_4 -> V_7 . V_66 + V_150 [ V_102 ] . V_66 ) ) ;
F_90 ( V_99 , 0 ) ;
for ( V_151 = 0 ; V_151 < V_168 ; V_151 ++ )
F_90 ( V_99 , 0 ) ;
}
}
V_12 = F_92 ( V_99 , false , & V_38 ) ;
if ( V_12 ) {
F_40 ( V_76 , V_20 , L_27 , V_12 ) ;
F_91 ( V_99 ) ;
goto V_26;
}
V_26:
F_54 ( & V_85 , V_38 , V_7 ) ;
F_93 ( & V_38 ) ;
V_163:
F_72 ( V_7 ) ;
F_72 ( V_150 ) ;
V_158:
if ( V_99 -> V_164 . V_165 ) {
V_75 -> V_171 = 0x00000000 ;
V_75 -> V_172 = 0x00000000 ;
} else
if ( V_6 -> V_10 . V_59 . V_167 >= 0x25 ) {
V_75 -> V_171 = 0x00020000 ;
V_75 -> V_172 = 0x00000000 ;
} else {
V_75 -> V_171 = 0x20000000 |
( V_99 -> V_150 . V_22 . V_66 + ( ( V_99 -> V_164 . V_170 + 2 ) << 2 ) ) ;
V_75 -> V_172 = 0x00000000 ;
}
return F_86 ( V_146 , V_12 ) ;
}
int
F_94 ( struct V_42 * V_11 , void * V_28 ,
struct V_17 * V_18 )
{
struct V_173 * V_75 = V_28 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
bool V_174 = ! ! ( V_75 -> V_49 & V_175 ) ;
bool V_176 = ! ! ( V_75 -> V_49 & V_177 ) ;
long V_178 ;
int V_12 ;
V_2 = F_59 ( V_18 , V_75 -> V_77 ) ;
if ( ! V_2 )
return - V_110 ;
V_4 = F_2 ( V_2 ) ;
V_178 = F_95 ( V_4 -> V_7 . V_34 , V_176 , true ,
V_174 ? 0 : 30 * V_179 ) ;
if ( ! V_178 )
V_12 = - V_180 ;
else if ( V_178 > 0 )
V_12 = 0 ;
else
V_12 = V_178 ;
F_96 ( V_4 ) ;
F_43 ( V_2 ) ;
return V_12 ;
}
int
F_97 ( struct V_42 * V_11 , void * V_28 ,
struct V_17 * V_18 )
{
struct V_181 * V_75 = V_28 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_59 ( V_18 , V_75 -> V_77 ) ;
if ( ! V_2 )
return - V_110 ;
V_4 = F_2 ( V_2 ) ;
F_98 ( V_4 ) ;
F_43 ( V_2 ) ;
return 0 ;
}
int
F_99 ( struct V_42 * V_11 , void * V_28 ,
struct V_17 * V_18 )
{
struct V_63 * V_75 = V_28 ;
struct V_1 * V_2 ;
int V_12 ;
V_2 = F_59 ( V_18 , V_75 -> V_77 ) ;
if ( ! V_2 )
return - V_110 ;
V_12 = F_34 ( V_18 , V_2 , V_75 ) ;
F_43 ( V_2 ) ;
return V_12 ;
}
