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
F_30 ( struct V_19 * V_20 , T_1 V_42 , int V_43 , T_2 V_44 ,
T_2 V_45 , T_2 V_46 ,
struct V_3 * * V_47 )
{
struct V_5 * V_6 = V_5 ( V_20 -> V_11 ) ;
struct V_3 * V_4 ;
T_3 V_48 = 0 ;
int V_12 ;
if ( V_44 & V_49 )
V_48 |= V_50 ;
if ( V_44 & V_51 )
V_48 |= V_52 ;
if ( ! V_48 || V_44 & V_53 )
V_48 |= V_54 ;
if ( V_44 & V_55 )
V_48 |= V_56 ;
V_12 = F_31 ( V_20 , V_42 , V_43 , V_48 , V_45 ,
V_46 , NULL , NULL , V_47 ) ;
if ( V_12 )
return V_12 ;
V_4 = * V_47 ;
V_4 -> V_57 = V_49 |
V_51 ;
if ( V_6 -> V_58 . V_10 . V_59 . V_60 >= V_61 )
V_4 -> V_57 &= V_44 ;
V_12 = F_32 ( V_6 -> V_11 , & V_4 -> V_2 , V_4 -> V_7 . V_30 . V_42 ) ;
if ( V_12 ) {
F_33 ( NULL , V_47 ) ;
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
if ( F_35 ( V_4 -> V_57 ) )
V_64 -> V_44 = V_4 -> V_57 ;
else if ( V_4 -> V_7 . V_30 . V_31 == V_65 )
V_64 -> V_44 = V_51 ;
else
V_64 -> V_44 = V_49 ;
V_64 -> V_66 = V_4 -> V_7 . V_66 ;
if ( V_20 -> V_23 ) {
V_22 = F_13 ( V_4 , V_20 -> V_23 ) ;
if ( ! V_22 )
return - V_67 ;
V_64 -> V_66 = V_22 -> V_66 ;
}
V_64 -> V_42 = V_4 -> V_7 . V_30 . V_68 << V_69 ;
V_64 -> V_70 = F_36 ( & V_4 -> V_7 . V_71 ) ;
V_64 -> V_45 = V_4 -> V_45 ;
V_64 -> V_46 = V_4 -> V_46 ;
return 0 ;
}
int
F_37 ( struct V_72 * V_11 , void * V_28 ,
struct V_17 * V_18 )
{
struct V_5 * V_6 = V_5 ( V_11 ) ;
struct V_19 * V_20 = V_19 ( V_18 ) ;
struct V_73 * V_74 = F_38 ( & V_6 -> V_58 . V_10 ) ;
struct V_75 * V_76 = V_28 ;
struct V_3 * V_4 = NULL ;
int V_12 = 0 ;
if ( ! F_39 ( V_74 , V_76 -> V_59 . V_46 ) ) {
F_40 ( V_77 , V_20 , L_1 , V_76 -> V_59 . V_46 ) ;
return - V_67 ;
}
V_12 = F_30 ( V_20 , V_76 -> V_59 . V_42 , V_76 -> V_43 ,
V_76 -> V_59 . V_44 , V_76 -> V_59 . V_45 ,
V_76 -> V_59 . V_46 , & V_4 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_41 ( V_18 , & V_4 -> V_2 , & V_76 -> V_59 . V_78 ) ;
if ( V_12 == 0 ) {
V_12 = F_34 ( V_18 , & V_4 -> V_2 , & V_76 -> V_59 ) ;
if ( V_12 )
F_42 ( V_18 , V_76 -> V_59 . V_78 ) ;
}
F_43 ( & V_4 -> V_2 ) ;
return V_12 ;
}
static int
F_44 ( struct V_1 * V_2 , T_2 V_79 ,
T_2 V_80 , T_2 V_57 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_7 = & V_4 -> V_7 ;
T_2 V_81 = V_57 & V_4 -> V_57 &
( V_80 ? V_80 : V_79 ) ;
T_2 V_82 = 0 , V_83 = 0 ;
if ( ! V_81 )
return - V_67 ;
if ( V_57 & V_49 )
V_83 |= V_50 ;
if ( V_57 & V_51 )
V_83 |= V_52 ;
if ( ( V_81 & V_49 ) &&
V_7 -> V_30 . V_31 == V_84 )
V_82 |= V_50 ;
else if ( ( V_81 & V_51 ) &&
V_7 -> V_30 . V_31 == V_65 )
V_82 |= V_52 ;
else if ( V_81 & V_49 )
V_82 |= V_50 ;
else
V_82 |= V_52 ;
F_45 ( V_4 , V_82 , V_83 ) ;
return 0 ;
}
static void
F_46 ( struct V_85 * V_86 , struct V_87 * V_38 ,
struct V_88 * V_89 )
{
struct V_3 * V_4 ;
struct V_88 * V_90 ;
while ( ! F_47 ( & V_86 -> V_91 ) ) {
V_4 = F_48 ( V_86 -> V_91 . V_92 , struct V_3 , V_93 ) ;
V_90 = & V_89 [ V_4 -> V_94 ] ;
if ( F_49 ( V_38 ) )
F_50 ( V_4 , V_38 , ! ! V_90 -> V_80 ) ;
if ( F_51 ( V_4 -> V_95 ) ) {
F_52 ( & V_4 -> V_96 ) ;
V_4 -> V_95 = false ;
}
F_23 ( & V_4 -> V_93 ) ;
V_4 -> V_97 = NULL ;
F_53 ( & V_4 -> V_7 , & V_86 -> V_98 ) ;
F_43 ( & V_4 -> V_2 ) ;
}
}
static void
F_54 ( struct V_85 * V_86 , struct V_87 * V_38 ,
struct V_88 * V_89 )
{
F_46 ( V_86 , V_38 , V_89 ) ;
F_55 ( & V_86 -> V_98 ) ;
}
static int
F_56 ( struct V_99 * V_100 , struct V_17 * V_18 ,
struct V_88 * V_89 ,
int V_101 , struct V_85 * V_86 )
{
struct V_19 * V_20 = V_19 ( V_18 ) ;
int V_102 = 0 ;
int V_12 = - V_67 , V_103 ;
struct V_3 * V_104 = NULL ;
F_57 ( V_105 ) ;
F_57 ( V_106 ) ;
F_57 ( V_107 ) ;
F_58 ( & V_86 -> V_98 , & V_108 ) ;
V_109:
if ( ++ V_102 > 100000 ) {
F_40 ( V_77 , V_20 , L_2 , V_110 ) ;
return - V_67 ;
}
for ( V_103 = 0 ; V_103 < V_101 ; V_103 ++ ) {
struct V_88 * V_90 = & V_89 [ V_103 ] ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_59 ( V_18 , V_90 -> V_78 ) ;
if ( ! V_2 ) {
F_40 ( V_77 , V_20 , L_3 , V_90 -> V_78 ) ;
V_12 = - V_111 ;
break;
}
V_4 = F_2 ( V_2 ) ;
if ( V_4 == V_104 ) {
V_104 = NULL ;
F_43 ( V_2 ) ;
continue;
}
if ( V_4 -> V_97 && V_4 -> V_97 == V_18 ) {
F_40 ( V_77 , V_20 , L_4
L_5 , V_90 -> V_78 ) ;
F_43 ( V_2 ) ;
V_12 = - V_67 ;
break;
}
V_12 = F_12 ( & V_4 -> V_7 , true , false , & V_86 -> V_98 ) ;
if ( V_12 ) {
F_60 ( & V_106 , & V_86 -> V_91 ) ;
F_60 ( & V_105 , & V_86 -> V_91 ) ;
F_60 ( & V_107 , & V_86 -> V_91 ) ;
F_46 ( V_86 , NULL , NULL ) ;
if ( F_51 ( V_12 == - V_112 ) ) {
V_12 = F_61 ( & V_4 -> V_7 , true ,
& V_86 -> V_98 ) ;
if ( ! V_12 )
V_104 = V_4 ;
}
if ( F_51 ( V_12 ) ) {
if ( V_12 != - V_113 )
F_40 ( V_77 , V_20 , L_6 ) ;
break;
}
}
V_90 -> V_114 = ( V_115 ) ( unsigned long ) V_4 ;
V_4 -> V_97 = V_18 ;
V_4 -> V_94 = V_103 ;
if ( ( V_90 -> V_57 & V_49 ) &&
( V_90 -> V_57 & V_51 ) )
F_62 ( & V_4 -> V_93 , & V_107 ) ;
else
if ( V_90 -> V_57 & V_49 )
F_62 ( & V_4 -> V_93 , & V_106 ) ;
else
if ( V_90 -> V_57 & V_51 )
F_62 ( & V_4 -> V_93 , & V_105 ) ;
else {
F_40 ( V_77 , V_20 , L_7 ,
V_90 -> V_57 ) ;
F_62 ( & V_4 -> V_93 , & V_107 ) ;
V_12 = - V_67 ;
break;
}
if ( V_4 == V_104 )
goto V_109;
}
F_63 ( & V_86 -> V_98 ) ;
F_64 ( & V_106 , & V_86 -> V_91 ) ;
F_64 ( & V_105 , & V_86 -> V_91 ) ;
F_64 ( & V_107 , & V_86 -> V_91 ) ;
if ( V_12 )
F_54 ( V_86 , NULL , NULL ) ;
return V_12 ;
}
static int
F_65 ( struct V_99 * V_100 , struct V_19 * V_20 ,
struct V_116 * V_91 , struct V_88 * V_89 ,
V_115 V_117 )
{
struct V_5 * V_6 = V_100 -> V_6 ;
struct V_88 T_4 * V_118 =
( void V_119 T_4 * ) ( V_120 ) V_117 ;
struct V_3 * V_4 ;
int V_12 , V_121 = 0 ;
F_66 (nvbo, list, entry) {
struct V_88 * V_90 = & V_89 [ V_4 -> V_94 ] ;
V_12 = F_44 ( & V_4 -> V_2 , V_90 -> V_79 ,
V_90 -> V_80 ,
V_90 -> V_57 ) ;
if ( F_51 ( V_12 ) ) {
F_40 ( V_77 , V_20 , L_8 ) ;
return V_12 ;
}
V_12 = F_67 ( V_4 , true , false ) ;
if ( F_51 ( V_12 ) ) {
if ( V_12 != - V_113 )
F_40 ( V_77 , V_20 , L_9 ) ;
return V_12 ;
}
V_12 = F_68 ( V_4 , V_100 , ! ! V_90 -> V_80 , true ) ;
if ( F_51 ( V_12 ) ) {
if ( V_12 != - V_113 )
F_40 ( V_77 , V_20 , L_10 ) ;
return V_12 ;
}
if ( V_6 -> V_58 . V_10 . V_59 . V_60 < V_61 ) {
if ( V_4 -> V_7 . V_66 == V_90 -> V_122 . V_66 &&
( ( V_4 -> V_7 . V_30 . V_31 == V_84 &&
V_90 -> V_122 . V_44 & V_49 ) ||
( V_4 -> V_7 . V_30 . V_31 == V_65 &&
V_90 -> V_122 . V_44 & V_51 ) ) )
continue;
if ( V_4 -> V_7 . V_30 . V_31 == V_65 )
V_90 -> V_122 . V_44 = V_51 ;
else
V_90 -> V_122 . V_44 = V_49 ;
V_90 -> V_122 . V_66 = V_4 -> V_7 . V_66 ;
V_90 -> V_122 . V_123 = 0 ;
V_121 ++ ;
if ( F_69 ( & V_118 [ V_4 -> V_94 ] . V_122 ,
& V_90 -> V_122 , sizeof( V_90 -> V_122 ) ) )
return - V_124 ;
}
}
return V_121 ;
}
static int
F_70 ( struct V_99 * V_100 ,
struct V_17 * V_18 ,
struct V_88 * V_89 ,
V_115 V_125 , int V_101 ,
struct V_85 * V_86 , int * V_126 )
{
struct V_19 * V_20 = V_19 ( V_18 ) ;
int V_12 ;
F_71 ( & V_86 -> V_91 ) ;
if ( V_101 == 0 )
return 0 ;
V_12 = F_56 ( V_100 , V_18 , V_89 , V_101 , V_86 ) ;
if ( F_51 ( V_12 ) ) {
if ( V_12 != - V_113 )
F_40 ( V_77 , V_20 , L_11 ) ;
return V_12 ;
}
V_12 = F_65 ( V_100 , V_20 , & V_86 -> V_91 , V_89 , V_125 ) ;
if ( F_51 ( V_12 < 0 ) ) {
if ( V_12 != - V_113 )
F_40 ( V_77 , V_20 , L_12 ) ;
F_54 ( V_86 , NULL , NULL ) ;
return V_12 ;
}
* V_126 = V_12 ;
return 0 ;
}
static inline void
F_72 ( void * V_127 )
{
F_73 ( V_127 ) ;
}
static inline void *
F_74 ( V_115 V_128 , unsigned V_129 , unsigned V_42 )
{
void * V_30 ;
void T_4 * V_130 = ( void V_119 T_4 * ) ( V_120 ) V_128 ;
V_42 *= V_129 ;
V_30 = F_75 ( V_42 , V_24 | V_131 ) ;
if ( ! V_30 )
V_30 = F_76 ( V_42 ) ;
if ( ! V_30 )
return F_77 ( - V_25 ) ;
if ( F_78 ( V_30 , V_130 , V_42 ) ) {
F_72 ( V_30 ) ;
return F_77 ( - V_124 ) ;
}
return V_30 ;
}
static int
F_79 ( struct V_19 * V_20 ,
struct V_132 * V_76 ,
struct V_88 * V_7 )
{
struct V_133 * V_134 = NULL ;
int V_12 = 0 ;
unsigned V_103 ;
V_134 = F_74 ( V_76 -> V_121 , V_76 -> V_135 , sizeof( * V_134 ) ) ;
if ( F_80 ( V_134 ) )
return F_81 ( V_134 ) ;
for ( V_103 = 0 ; V_103 < V_76 -> V_135 ; V_103 ++ ) {
struct V_133 * V_136 = & V_134 [ V_103 ] ;
struct V_88 * V_90 ;
struct V_3 * V_4 ;
T_2 V_28 ;
if ( F_51 ( V_136 -> V_137 > V_76 -> V_101 ) ) {
F_40 ( V_77 , V_20 , L_13 ) ;
V_12 = - V_67 ;
break;
}
V_90 = & V_7 [ V_136 -> V_137 ] ;
if ( V_90 -> V_122 . V_123 )
continue;
if ( F_51 ( V_136 -> V_138 > V_76 -> V_101 ) ) {
F_40 ( V_77 , V_20 , L_14 ) ;
V_12 = - V_67 ;
break;
}
V_4 = ( void * ) ( unsigned long ) V_7 [ V_136 -> V_138 ] . V_114 ;
if ( F_51 ( V_136 -> V_139 + 4 >
V_4 -> V_7 . V_30 . V_68 << V_69 ) ) {
F_40 ( V_77 , V_20 , L_15 ) ;
V_12 = - V_67 ;
break;
}
if ( ! V_4 -> V_96 . V_140 ) {
V_12 = F_82 ( & V_4 -> V_7 , 0 , V_4 -> V_7 . V_30 . V_68 ,
& V_4 -> V_96 ) ;
if ( V_12 ) {
F_40 ( V_77 , V_20 , L_16 ) ;
break;
}
V_4 -> V_95 = true ;
}
if ( V_136 -> V_48 & V_141 )
V_28 = V_90 -> V_122 . V_66 + V_136 -> V_28 ;
else
if ( V_136 -> V_48 & V_142 )
V_28 = ( V_90 -> V_122 . V_66 + V_136 -> V_28 ) >> 32 ;
else
V_28 = V_136 -> V_28 ;
if ( V_136 -> V_48 & V_143 ) {
if ( V_90 -> V_122 . V_44 == V_51 )
V_28 |= V_136 -> V_144 ;
else
V_28 |= V_136 -> V_145 ;
}
V_12 = F_24 ( & V_4 -> V_7 , false , false ) ;
if ( V_12 ) {
F_40 ( V_77 , V_20 , L_17 , V_12 ) ;
break;
}
F_83 ( V_4 , V_136 -> V_139 >> 2 , V_28 ) ;
}
F_72 ( V_134 ) ;
return V_12 ;
}
int
F_84 ( struct V_72 * V_11 , void * V_28 ,
struct V_17 * V_18 )
{
struct V_146 * V_147 = F_85 ( V_18 ) ;
struct V_19 * V_20 = V_19 ( V_18 ) ;
struct V_148 * V_149 ;
struct V_5 * V_6 = V_5 ( V_11 ) ;
struct V_132 * V_76 = V_28 ;
struct V_150 * V_151 ;
struct V_88 * V_7 ;
struct V_99 * V_100 = NULL ;
struct V_85 V_86 ;
struct V_87 * V_38 = NULL ;
int V_103 , V_152 , V_12 = 0 , V_153 = 0 ;
if ( F_51 ( ! V_147 ) )
return - V_25 ;
F_66 (temp, &abi16->channels, head) {
if ( V_149 -> V_100 -> V_154 == V_76 -> V_155 ) {
V_100 = V_149 -> V_100 ;
break;
}
}
if ( ! V_100 )
return F_86 ( V_147 , - V_111 ) ;
V_76 -> V_156 = V_6 -> V_2 . V_156 ;
V_76 -> V_157 = V_6 -> V_2 . V_157 ;
if ( F_51 ( V_76 -> V_158 == 0 ) )
goto V_159;
if ( F_51 ( V_76 -> V_158 > V_160 ) ) {
F_40 ( V_77 , V_20 , L_18 ,
V_76 -> V_158 , V_160 ) ;
return F_86 ( V_147 , - V_67 ) ;
}
if ( F_51 ( V_76 -> V_101 > V_161 ) ) {
F_40 ( V_77 , V_20 , L_19 ,
V_76 -> V_101 , V_161 ) ;
return F_86 ( V_147 , - V_67 ) ;
}
if ( F_51 ( V_76 -> V_135 > V_162 ) ) {
F_40 ( V_77 , V_20 , L_20 ,
V_76 -> V_135 , V_162 ) ;
return F_86 ( V_147 , - V_67 ) ;
}
V_151 = F_74 ( V_76 -> V_151 , V_76 -> V_158 , sizeof( * V_151 ) ) ;
if ( F_80 ( V_151 ) )
return F_86 ( V_147 , F_81 ( V_151 ) ) ;
V_7 = F_74 ( V_76 -> V_163 , V_76 -> V_101 , sizeof( * V_7 ) ) ;
if ( F_80 ( V_7 ) ) {
F_72 ( V_151 ) ;
return F_86 ( V_147 , F_81 ( V_7 ) ) ;
}
for ( V_103 = 0 ; V_103 < V_76 -> V_158 ; V_103 ++ ) {
if ( V_151 [ V_103 ] . V_137 >= V_76 -> V_101 ) {
F_40 ( V_77 , V_20 , L_21 , V_103 ) ;
V_12 = - V_67 ;
goto V_164;
}
}
V_12 = F_70 ( V_100 , V_18 , V_7 , V_76 -> V_163 ,
V_76 -> V_101 , & V_86 , & V_153 ) ;
if ( V_12 ) {
if ( V_12 != - V_113 )
F_40 ( V_77 , V_20 , L_22 , V_12 ) ;
goto V_164;
}
if ( V_153 ) {
V_12 = F_79 ( V_20 , V_76 , V_7 ) ;
if ( V_12 ) {
F_40 ( V_77 , V_20 , L_23 , V_12 ) ;
goto V_26;
}
}
if ( V_100 -> V_165 . V_166 ) {
V_12 = F_87 ( V_100 , V_76 -> V_158 + 1 , 16 ) ;
if ( V_12 ) {
F_40 ( V_77 , V_20 , L_24 , V_12 ) ;
goto V_26;
}
for ( V_103 = 0 ; V_103 < V_76 -> V_158 ; V_103 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_151 [ V_103 ] . V_137 ] . V_114 ;
F_88 ( V_100 , V_4 , V_151 [ V_103 ] . V_66 ,
V_151 [ V_103 ] . V_167 ) ;
}
} else
if ( V_6 -> V_58 . V_10 . V_59 . V_168 >= 0x25 ) {
V_12 = F_89 ( V_100 , V_76 -> V_158 * 2 ) ;
if ( V_12 ) {
F_40 ( V_77 , V_20 , L_25 , V_12 ) ;
goto V_26;
}
for ( V_103 = 0 ; V_103 < V_76 -> V_158 ; V_103 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_151 [ V_103 ] . V_137 ] . V_114 ;
F_90 ( V_100 , ( V_4 -> V_7 . V_66 + V_151 [ V_103 ] . V_66 ) | 2 ) ;
F_90 ( V_100 , 0 ) ;
}
} else {
V_12 = F_89 ( V_100 , V_76 -> V_158 * ( 2 + V_169 ) ) ;
if ( V_12 ) {
F_40 ( V_77 , V_20 , L_26 , V_12 ) ;
goto V_26;
}
for ( V_103 = 0 ; V_103 < V_76 -> V_158 ; V_103 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_151 [ V_103 ] . V_137 ] . V_114 ;
T_2 V_170 ;
V_170 = V_100 -> V_151 . V_22 . V_66 + ( ( V_100 -> V_165 . V_171 + 2 ) << 2 ) ;
V_170 |= 0x20000000 ;
if ( F_51 ( V_170 != V_76 -> V_172 ) ) {
if ( ! V_4 -> V_96 . V_140 ) {
V_12 = F_82 ( & V_4 -> V_7 , 0 ,
V_4 -> V_7 . V_30 .
V_68 ,
& V_4 -> V_96 ) ;
if ( V_12 ) {
F_91 ( V_100 ) ;
goto V_26;
}
V_4 -> V_95 = true ;
}
F_83 ( V_4 , ( V_151 [ V_103 ] . V_66 +
V_151 [ V_103 ] . V_167 - 8 ) / 4 , V_170 ) ;
}
F_90 ( V_100 , 0x20000000 |
( V_4 -> V_7 . V_66 + V_151 [ V_103 ] . V_66 ) ) ;
F_90 ( V_100 , 0 ) ;
for ( V_152 = 0 ; V_152 < V_169 ; V_152 ++ )
F_90 ( V_100 , 0 ) ;
}
}
V_12 = F_92 ( V_100 , false , & V_38 ) ;
if ( V_12 ) {
F_40 ( V_77 , V_20 , L_27 , V_12 ) ;
F_91 ( V_100 ) ;
goto V_26;
}
V_26:
F_54 ( & V_86 , V_38 , V_7 ) ;
F_93 ( & V_38 ) ;
V_164:
F_72 ( V_7 ) ;
F_72 ( V_151 ) ;
V_159:
if ( V_100 -> V_165 . V_166 ) {
V_76 -> V_172 = 0x00000000 ;
V_76 -> V_173 = 0x00000000 ;
} else
if ( V_6 -> V_58 . V_10 . V_59 . V_168 >= 0x25 ) {
V_76 -> V_172 = 0x00020000 ;
V_76 -> V_173 = 0x00000000 ;
} else {
V_76 -> V_172 = 0x20000000 |
( V_100 -> V_151 . V_22 . V_66 + ( ( V_100 -> V_165 . V_171 + 2 ) << 2 ) ) ;
V_76 -> V_173 = 0x00000000 ;
}
return F_86 ( V_147 , V_12 ) ;
}
int
F_94 ( struct V_72 * V_11 , void * V_28 ,
struct V_17 * V_18 )
{
struct V_174 * V_76 = V_28 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
bool V_175 = ! ! ( V_76 -> V_48 & V_176 ) ;
bool V_177 = ! ! ( V_76 -> V_48 & V_178 ) ;
long V_179 ;
int V_12 ;
V_2 = F_59 ( V_18 , V_76 -> V_78 ) ;
if ( ! V_2 )
return - V_111 ;
V_4 = F_2 ( V_2 ) ;
V_179 = F_95 ( V_4 -> V_7 . V_34 , V_177 , true ,
V_175 ? 0 : 30 * V_180 ) ;
if ( ! V_179 )
V_12 = - V_181 ;
else if ( V_179 > 0 )
V_12 = 0 ;
else
V_12 = V_179 ;
F_96 ( V_4 ) ;
F_43 ( V_2 ) ;
return V_12 ;
}
int
F_97 ( struct V_72 * V_11 , void * V_28 ,
struct V_17 * V_18 )
{
struct V_182 * V_76 = V_28 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_59 ( V_18 , V_76 -> V_78 ) ;
if ( ! V_2 )
return - V_111 ;
V_4 = F_2 ( V_2 ) ;
F_98 ( V_4 ) ;
F_43 ( V_2 ) ;
return 0 ;
}
int
F_99 ( struct V_72 * V_11 , void * V_28 ,
struct V_17 * V_18 )
{
struct V_63 * V_76 = V_28 ;
struct V_1 * V_2 ;
int V_12 ;
V_2 = F_59 ( V_18 , V_76 -> V_78 ) ;
if ( ! V_2 )
return - V_111 ;
V_12 = F_34 ( V_18 , V_2 , V_76 ) ;
F_43 ( V_2 ) ;
return V_12 ;
}
