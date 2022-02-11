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
V_12 = F_12 ( & V_4 -> V_7 , false , false , false , NULL ) ;
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
if ( V_12 < 0 && V_12 != - V_13 )
goto V_26;
V_12 = F_15 ( V_4 , V_20 -> V_23 , V_22 ) ;
if ( V_12 )
F_16 ( V_22 ) ;
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
F_16 ( V_22 ) ;
}
static void
F_21 ( struct V_3 * V_4 , struct V_21 * V_22 )
{
const bool V_29 = V_4 -> V_7 . V_30 . V_31 != V_32 ;
struct V_33 * V_34 = V_4 -> V_7 . V_34 ;
struct V_35 * V_36 ;
struct V_37 * V_37 = NULL ;
V_36 = F_22 ( V_34 ) ;
F_23 ( & V_22 -> V_38 ) ;
if ( V_36 && V_36 -> V_39 > 1 )
F_24 ( & V_4 -> V_7 , true , false , false ) ;
else if ( V_36 && V_36 -> V_39 == 1 )
V_37 = F_25 ( V_36 -> V_40 [ 0 ] ,
F_26 ( V_34 ) ) ;
else
V_37 = F_27 ( V_4 -> V_7 . V_34 ) ;
if ( V_37 && V_29 ) {
F_28 ( V_37 , F_18 , V_22 ) ;
} else {
if ( V_29 )
F_19 ( V_22 ) ;
F_20 ( V_22 ) ;
F_16 ( V_22 ) ;
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
V_12 = F_12 ( & V_4 -> V_7 , false , false , false , NULL ) ;
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
F_30 ( struct V_41 * V_11 , int V_42 , int V_43 , T_1 V_44 ,
T_1 V_45 , T_1 V_46 ,
struct V_3 * * V_47 )
{
struct V_5 * V_6 = V_5 ( V_11 ) ;
struct V_3 * V_4 ;
T_2 V_48 = 0 ;
int V_12 ;
if ( V_44 & V_49 )
V_48 |= V_50 ;
if ( V_44 & V_51 )
V_48 |= V_52 ;
if ( ! V_48 || V_44 & V_53 )
V_48 |= V_54 ;
V_12 = F_31 ( V_11 , V_42 , V_43 , V_48 , V_45 ,
V_46 , NULL , NULL , V_47 ) ;
if ( V_12 )
return V_12 ;
V_4 = * V_47 ;
V_4 -> V_55 = V_49 |
V_51 ;
if ( V_6 -> V_10 . V_56 . V_57 >= V_58 )
V_4 -> V_55 &= V_44 ;
V_12 = F_32 ( V_11 , & V_4 -> V_2 , V_4 -> V_7 . V_30 . V_42 ) ;
if ( V_12 ) {
F_33 ( NULL , V_47 ) ;
return - V_25 ;
}
V_4 -> V_7 . V_59 = V_4 -> V_2 . V_16 ;
return 0 ;
}
static int
F_34 ( struct V_17 * V_18 , struct V_1 * V_2 ,
struct V_60 * V_61 )
{
struct V_19 * V_20 = V_19 ( V_18 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_21 * V_22 ;
if ( V_4 -> V_7 . V_30 . V_31 == V_62 )
V_61 -> V_44 = V_51 ;
else
V_61 -> V_44 = V_49 ;
V_61 -> V_63 = V_4 -> V_7 . V_63 ;
if ( V_20 -> V_23 ) {
V_22 = F_13 ( V_4 , V_20 -> V_23 ) ;
if ( ! V_22 )
return - V_64 ;
V_61 -> V_63 = V_22 -> V_63 ;
}
V_61 -> V_42 = V_4 -> V_7 . V_30 . V_65 << V_66 ;
V_61 -> V_67 = F_35 ( & V_4 -> V_7 . V_68 ) ;
V_61 -> V_45 = V_4 -> V_45 ;
V_61 -> V_46 = V_4 -> V_46 ;
return 0 ;
}
int
F_36 ( struct V_41 * V_11 , void * V_28 ,
struct V_17 * V_18 )
{
struct V_5 * V_6 = V_5 ( V_11 ) ;
struct V_19 * V_20 = V_19 ( V_18 ) ;
struct V_69 * V_70 = F_37 ( & V_6 -> V_10 ) ;
struct V_71 * V_72 = V_28 ;
struct V_3 * V_4 = NULL ;
int V_12 = 0 ;
if ( ! V_70 -> V_73 ( V_70 , V_72 -> V_56 . V_46 ) ) {
F_38 ( error , V_20 , L_1 , V_72 -> V_56 . V_46 ) ;
return - V_64 ;
}
V_12 = F_30 ( V_11 , V_72 -> V_56 . V_42 , V_72 -> V_43 ,
V_72 -> V_56 . V_44 , V_72 -> V_56 . V_45 ,
V_72 -> V_56 . V_46 , & V_4 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_39 ( V_18 , & V_4 -> V_2 , & V_72 -> V_56 . V_74 ) ;
if ( V_12 == 0 ) {
V_12 = F_34 ( V_18 , & V_4 -> V_2 , & V_72 -> V_56 ) ;
if ( V_12 )
F_40 ( V_18 , V_72 -> V_56 . V_74 ) ;
}
F_41 ( & V_4 -> V_2 ) ;
return V_12 ;
}
static int
F_42 ( struct V_1 * V_2 , T_1 V_75 ,
T_1 V_76 , T_1 V_55 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_7 = & V_4 -> V_7 ;
T_1 V_77 = V_55 & V_4 -> V_55 &
( V_76 ? V_76 : V_75 ) ;
T_1 V_78 = 0 , V_79 = 0 ;
if ( ! V_77 )
return - V_64 ;
if ( V_55 & V_49 )
V_79 |= V_50 ;
if ( V_55 & V_51 )
V_79 |= V_52 ;
if ( ( V_77 & V_49 ) &&
V_7 -> V_30 . V_31 == V_80 )
V_78 |= V_50 ;
else if ( ( V_77 & V_51 ) &&
V_7 -> V_30 . V_31 == V_62 )
V_78 |= V_52 ;
else if ( V_77 & V_49 )
V_78 |= V_50 ;
else
V_78 |= V_52 ;
F_43 ( V_4 , V_78 , V_79 ) ;
return 0 ;
}
static void
F_44 ( struct V_81 * V_82 , struct V_83 * V_37 ,
struct V_84 * V_85 )
{
struct V_3 * V_4 ;
struct V_84 * V_86 ;
while ( ! F_45 ( & V_82 -> V_87 ) ) {
V_4 = F_46 ( V_82 -> V_87 . V_88 , struct V_3 , V_89 ) ;
V_86 = & V_85 [ V_4 -> V_90 ] ;
if ( F_47 ( V_37 ) )
F_48 ( V_4 , V_37 , ! ! V_86 -> V_76 ) ;
if ( F_49 ( V_4 -> V_91 ) ) {
F_50 ( & V_4 -> V_92 ) ;
V_4 -> V_91 = false ;
}
F_23 ( & V_4 -> V_89 ) ;
V_4 -> V_93 = NULL ;
F_51 ( & V_4 -> V_7 , & V_82 -> V_94 ) ;
F_41 ( & V_4 -> V_2 ) ;
}
}
static void
F_52 ( struct V_81 * V_82 , struct V_83 * V_37 ,
struct V_84 * V_85 )
{
F_44 ( V_82 , V_37 , V_85 ) ;
F_53 ( & V_82 -> V_94 ) ;
}
static int
F_54 ( struct V_95 * V_96 , struct V_17 * V_18 ,
struct V_84 * V_85 ,
int V_97 , struct V_81 * V_82 )
{
struct V_19 * V_20 = V_19 ( V_18 ) ;
struct V_41 * V_11 = V_96 -> V_6 -> V_11 ;
int V_98 = 0 ;
int V_12 , V_99 ;
struct V_3 * V_100 = NULL ;
F_55 ( V_101 ) ;
F_55 ( V_102 ) ;
F_55 ( V_103 ) ;
F_56 ( & V_82 -> V_94 , & V_104 ) ;
V_105:
if ( ++ V_98 > 100000 ) {
F_38 ( error , V_20 , L_2 , V_106 ) ;
return - V_64 ;
}
for ( V_99 = 0 ; V_99 < V_97 ; V_99 ++ ) {
struct V_84 * V_86 = & V_85 [ V_99 ] ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_57 ( V_11 , V_18 , V_86 -> V_74 ) ;
if ( ! V_2 ) {
F_38 ( error , V_20 , L_3 , V_86 -> V_74 ) ;
V_12 = - V_107 ;
break;
}
V_4 = F_2 ( V_2 ) ;
if ( V_4 == V_100 ) {
V_100 = NULL ;
F_41 ( V_2 ) ;
continue;
}
if ( V_4 -> V_93 && V_4 -> V_93 == V_18 ) {
F_38 ( error , V_20 , L_4
L_5 , V_86 -> V_74 ) ;
F_41 ( V_2 ) ;
V_12 = - V_64 ;
break;
}
V_12 = F_12 ( & V_4 -> V_7 , true , false , true , & V_82 -> V_94 ) ;
if ( V_12 ) {
F_58 ( & V_102 , & V_82 -> V_87 ) ;
F_58 ( & V_101 , & V_82 -> V_87 ) ;
F_58 ( & V_103 , & V_82 -> V_87 ) ;
F_44 ( V_82 , NULL , NULL ) ;
if ( F_49 ( V_12 == - V_108 ) ) {
V_12 = F_59 ( & V_4 -> V_7 , true ,
& V_82 -> V_94 ) ;
if ( ! V_12 )
V_100 = V_4 ;
}
if ( F_49 ( V_12 ) ) {
if ( V_12 != - V_109 )
F_38 ( error , V_20 , L_6 ) ;
break;
}
}
V_86 -> V_110 = ( V_111 ) ( unsigned long ) V_4 ;
V_4 -> V_93 = V_18 ;
V_4 -> V_90 = V_99 ;
if ( ( V_86 -> V_55 & V_49 ) &&
( V_86 -> V_55 & V_51 ) )
F_60 ( & V_4 -> V_89 , & V_103 ) ;
else
if ( V_86 -> V_55 & V_49 )
F_60 ( & V_4 -> V_89 , & V_102 ) ;
else
if ( V_86 -> V_55 & V_51 )
F_60 ( & V_4 -> V_89 , & V_101 ) ;
else {
F_38 ( error , V_20 , L_7 ,
V_86 -> V_55 ) ;
F_60 ( & V_4 -> V_89 , & V_103 ) ;
V_12 = - V_64 ;
break;
}
if ( V_4 == V_100 )
goto V_105;
}
F_61 ( & V_82 -> V_94 ) ;
F_62 ( & V_102 , & V_82 -> V_87 ) ;
F_62 ( & V_101 , & V_82 -> V_87 ) ;
F_62 ( & V_103 , & V_82 -> V_87 ) ;
if ( V_12 )
F_52 ( V_82 , NULL , NULL ) ;
return V_12 ;
}
static int
F_63 ( struct V_95 * V_96 , struct V_19 * V_20 ,
struct V_112 * V_87 , struct V_84 * V_85 ,
V_111 V_113 )
{
struct V_5 * V_6 = V_96 -> V_6 ;
struct V_84 T_3 * V_114 =
( void V_115 T_3 * ) ( V_116 ) V_113 ;
struct V_3 * V_4 ;
int V_12 , V_117 = 0 ;
F_64 (nvbo, list, entry) {
struct V_84 * V_86 = & V_85 [ V_4 -> V_90 ] ;
V_12 = F_42 ( & V_4 -> V_2 , V_86 -> V_75 ,
V_86 -> V_76 ,
V_86 -> V_55 ) ;
if ( F_49 ( V_12 ) ) {
F_38 ( error , V_20 , L_8 ) ;
return V_12 ;
}
V_12 = F_65 ( V_4 , true , false ) ;
if ( F_49 ( V_12 ) ) {
if ( V_12 != - V_109 )
F_38 ( error , V_20 , L_9 ) ;
return V_12 ;
}
V_12 = F_66 ( V_4 , V_96 , ! ! V_86 -> V_76 , true ) ;
if ( F_49 ( V_12 ) ) {
if ( V_12 != - V_109 )
F_38 ( error , V_20 , L_10 ) ;
return V_12 ;
}
if ( V_6 -> V_10 . V_56 . V_57 < V_58 ) {
if ( V_4 -> V_7 . V_63 == V_86 -> V_118 . V_63 &&
( ( V_4 -> V_7 . V_30 . V_31 == V_80 &&
V_86 -> V_118 . V_44 & V_49 ) ||
( V_4 -> V_7 . V_30 . V_31 == V_62 &&
V_86 -> V_118 . V_44 & V_51 ) ) )
continue;
if ( V_4 -> V_7 . V_30 . V_31 == V_62 )
V_86 -> V_118 . V_44 = V_51 ;
else
V_86 -> V_118 . V_44 = V_49 ;
V_86 -> V_118 . V_63 = V_4 -> V_7 . V_63 ;
V_86 -> V_118 . V_119 = 0 ;
V_117 ++ ;
if ( F_67 ( & V_114 [ V_4 -> V_90 ] . V_118 ,
& V_86 -> V_118 , sizeof( V_86 -> V_118 ) ) )
return - V_120 ;
}
}
return V_117 ;
}
static int
F_68 ( struct V_95 * V_96 ,
struct V_17 * V_18 ,
struct V_84 * V_85 ,
V_111 V_121 , int V_97 ,
struct V_81 * V_82 , int * V_122 )
{
struct V_19 * V_20 = V_19 ( V_18 ) ;
int V_12 ;
F_69 ( & V_82 -> V_87 ) ;
if ( V_97 == 0 )
return 0 ;
V_12 = F_54 ( V_96 , V_18 , V_85 , V_97 , V_82 ) ;
if ( F_49 ( V_12 ) ) {
if ( V_12 != - V_109 )
F_38 ( error , V_20 , L_11 ) ;
return V_12 ;
}
V_12 = F_63 ( V_96 , V_20 , & V_82 -> V_87 , V_85 , V_121 ) ;
if ( F_49 ( V_12 < 0 ) ) {
if ( V_12 != - V_109 )
F_38 ( error , V_20 , L_12 ) ;
F_52 ( V_82 , NULL , NULL ) ;
return V_12 ;
}
* V_122 = V_12 ;
return 0 ;
}
static inline void
F_70 ( void * V_123 )
{
if ( ! F_71 ( V_123 ) )
F_16 ( V_123 ) ;
else
F_72 ( V_123 ) ;
}
static inline void *
F_73 ( V_111 V_124 , unsigned V_125 , unsigned V_42 )
{
void * V_30 ;
void T_3 * V_126 = ( void V_115 T_3 * ) ( V_116 ) V_124 ;
V_42 *= V_125 ;
V_30 = F_74 ( V_42 , V_24 | V_127 ) ;
if ( ! V_30 )
V_30 = F_75 ( V_42 ) ;
if ( ! V_30 )
return F_76 ( - V_25 ) ;
if ( F_77 ( V_30 , V_126 , V_42 ) ) {
F_70 ( V_30 ) ;
return F_76 ( - V_120 ) ;
}
return V_30 ;
}
static int
F_78 ( struct V_19 * V_20 ,
struct V_128 * V_72 ,
struct V_84 * V_7 )
{
struct V_129 * V_130 = NULL ;
int V_12 = 0 ;
unsigned V_99 ;
V_130 = F_73 ( V_72 -> V_117 , V_72 -> V_131 , sizeof( * V_130 ) ) ;
if ( F_79 ( V_130 ) )
return F_80 ( V_130 ) ;
for ( V_99 = 0 ; V_99 < V_72 -> V_131 ; V_99 ++ ) {
struct V_129 * V_132 = & V_130 [ V_99 ] ;
struct V_84 * V_86 ;
struct V_3 * V_4 ;
T_1 V_28 ;
if ( F_49 ( V_132 -> V_133 > V_72 -> V_97 ) ) {
F_38 ( error , V_20 , L_13 ) ;
V_12 = - V_64 ;
break;
}
V_86 = & V_7 [ V_132 -> V_133 ] ;
if ( V_86 -> V_118 . V_119 )
continue;
if ( F_49 ( V_132 -> V_134 > V_72 -> V_97 ) ) {
F_38 ( error , V_20 , L_14 ) ;
V_12 = - V_64 ;
break;
}
V_4 = ( void * ) ( unsigned long ) V_7 [ V_132 -> V_134 ] . V_110 ;
if ( F_49 ( V_132 -> V_135 + 4 >
V_4 -> V_7 . V_30 . V_65 << V_66 ) ) {
F_38 ( error , V_20 , L_15 ) ;
V_12 = - V_64 ;
break;
}
if ( ! V_4 -> V_92 . V_136 ) {
V_12 = F_81 ( & V_4 -> V_7 , 0 , V_4 -> V_7 . V_30 . V_65 ,
& V_4 -> V_92 ) ;
if ( V_12 ) {
F_38 ( error , V_20 , L_16 ) ;
break;
}
V_4 -> V_91 = true ;
}
if ( V_132 -> V_48 & V_137 )
V_28 = V_86 -> V_118 . V_63 + V_132 -> V_28 ;
else
if ( V_132 -> V_48 & V_138 )
V_28 = ( V_86 -> V_118 . V_63 + V_132 -> V_28 ) >> 32 ;
else
V_28 = V_132 -> V_28 ;
if ( V_132 -> V_48 & V_139 ) {
if ( V_86 -> V_118 . V_44 == V_51 )
V_28 |= V_132 -> V_140 ;
else
V_28 |= V_132 -> V_141 ;
}
V_12 = F_24 ( & V_4 -> V_7 , true , false , false ) ;
if ( V_12 ) {
F_38 ( error , V_20 , L_17 , V_12 ) ;
break;
}
F_82 ( V_4 , V_132 -> V_135 >> 2 , V_28 ) ;
}
F_70 ( V_130 ) ;
return V_12 ;
}
int
F_83 ( struct V_41 * V_11 , void * V_28 ,
struct V_17 * V_18 )
{
struct V_142 * V_143 = F_84 ( V_18 , V_11 ) ;
struct V_19 * V_20 = V_19 ( V_18 ) ;
struct V_144 * V_145 ;
struct V_5 * V_6 = V_5 ( V_11 ) ;
struct V_128 * V_72 = V_28 ;
struct V_146 * V_147 ;
struct V_84 * V_7 ;
struct V_95 * V_96 = NULL ;
struct V_81 V_82 ;
struct V_83 * V_37 = NULL ;
int V_99 , V_148 , V_12 = 0 , V_149 = 0 ;
if ( F_49 ( ! V_143 ) )
return - V_25 ;
F_64 (temp, &abi16->channels, head) {
if ( V_145 -> V_96 -> V_150 -> V_74 == ( V_151 | V_72 -> V_152 ) ) {
V_96 = V_145 -> V_96 ;
break;
}
}
if ( ! V_96 )
return F_85 ( V_143 , - V_107 ) ;
V_72 -> V_153 = V_6 -> V_2 . V_153 ;
V_72 -> V_154 = V_6 -> V_2 . V_154 ;
if ( F_49 ( V_72 -> V_155 == 0 ) )
goto V_156;
if ( F_49 ( V_72 -> V_155 > V_157 ) ) {
F_38 ( error , V_20 , L_18 ,
V_72 -> V_155 , V_157 ) ;
return F_85 ( V_143 , - V_64 ) ;
}
if ( F_49 ( V_72 -> V_97 > V_158 ) ) {
F_38 ( error , V_20 , L_19 ,
V_72 -> V_97 , V_158 ) ;
return F_85 ( V_143 , - V_64 ) ;
}
if ( F_49 ( V_72 -> V_131 > V_159 ) ) {
F_38 ( error , V_20 , L_20 ,
V_72 -> V_131 , V_159 ) ;
return F_85 ( V_143 , - V_64 ) ;
}
V_147 = F_73 ( V_72 -> V_147 , V_72 -> V_155 , sizeof( * V_147 ) ) ;
if ( F_79 ( V_147 ) )
return F_85 ( V_143 , F_80 ( V_147 ) ) ;
V_7 = F_73 ( V_72 -> V_160 , V_72 -> V_97 , sizeof( * V_7 ) ) ;
if ( F_79 ( V_7 ) ) {
F_70 ( V_147 ) ;
return F_85 ( V_143 , F_80 ( V_7 ) ) ;
}
for ( V_99 = 0 ; V_99 < V_72 -> V_155 ; V_99 ++ ) {
if ( V_147 [ V_99 ] . V_133 >= V_72 -> V_97 ) {
F_38 ( error , V_20 , L_21 , V_99 ) ;
V_12 = - V_64 ;
goto V_161;
}
}
V_12 = F_68 ( V_96 , V_18 , V_7 , V_72 -> V_160 ,
V_72 -> V_97 , & V_82 , & V_149 ) ;
if ( V_12 ) {
if ( V_12 != - V_109 )
F_38 ( error , V_20 , L_22 , V_12 ) ;
goto V_161;
}
if ( V_149 ) {
V_12 = F_78 ( V_20 , V_72 , V_7 ) ;
if ( V_12 ) {
F_38 ( error , V_20 , L_23 , V_12 ) ;
goto V_26;
}
}
if ( V_96 -> V_162 . V_163 ) {
V_12 = F_86 ( V_96 , V_72 -> V_155 + 1 , 16 ) ;
if ( V_12 ) {
F_38 ( error , V_20 , L_24 , V_12 ) ;
goto V_26;
}
for ( V_99 = 0 ; V_99 < V_72 -> V_155 ; V_99 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_147 [ V_99 ] . V_133 ] . V_110 ;
F_87 ( V_96 , V_4 , V_147 [ V_99 ] . V_63 ,
V_147 [ V_99 ] . V_164 ) ;
}
} else
if ( V_6 -> V_10 . V_56 . V_165 >= 0x25 ) {
V_12 = F_88 ( V_96 , V_72 -> V_155 * 2 ) ;
if ( V_12 ) {
F_38 ( error , V_20 , L_25 , V_12 ) ;
goto V_26;
}
for ( V_99 = 0 ; V_99 < V_72 -> V_155 ; V_99 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_147 [ V_99 ] . V_133 ] . V_110 ;
F_89 ( V_96 , ( V_4 -> V_7 . V_63 + V_147 [ V_99 ] . V_63 ) | 2 ) ;
F_89 ( V_96 , 0 ) ;
}
} else {
V_12 = F_88 ( V_96 , V_72 -> V_155 * ( 2 + V_166 ) ) ;
if ( V_12 ) {
F_38 ( error , V_20 , L_26 , V_12 ) ;
goto V_26;
}
for ( V_99 = 0 ; V_99 < V_72 -> V_155 ; V_99 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_147 [ V_99 ] . V_133 ] . V_110 ;
T_1 V_167 ;
V_167 = V_96 -> V_147 . V_22 . V_63 + ( ( V_96 -> V_162 . V_168 + 2 ) << 2 ) ;
V_167 |= 0x20000000 ;
if ( F_49 ( V_167 != V_72 -> V_169 ) ) {
if ( ! V_4 -> V_92 . V_136 ) {
V_12 = F_81 ( & V_4 -> V_7 , 0 ,
V_4 -> V_7 . V_30 .
V_65 ,
& V_4 -> V_92 ) ;
if ( V_12 ) {
F_90 ( V_96 ) ;
goto V_26;
}
V_4 -> V_91 = true ;
}
F_82 ( V_4 , ( V_147 [ V_99 ] . V_63 +
V_147 [ V_99 ] . V_164 - 8 ) / 4 , V_167 ) ;
}
F_89 ( V_96 , 0x20000000 |
( V_4 -> V_7 . V_63 + V_147 [ V_99 ] . V_63 ) ) ;
F_89 ( V_96 , 0 ) ;
for ( V_148 = 0 ; V_148 < V_166 ; V_148 ++ )
F_89 ( V_96 , 0 ) ;
}
}
V_12 = F_91 ( V_96 , false , & V_37 ) ;
if ( V_12 ) {
F_38 ( error , V_20 , L_27 , V_12 ) ;
F_90 ( V_96 ) ;
goto V_26;
}
V_26:
F_52 ( & V_82 , V_37 , V_7 ) ;
F_92 ( & V_37 ) ;
V_161:
F_70 ( V_7 ) ;
F_70 ( V_147 ) ;
V_156:
if ( V_96 -> V_162 . V_163 ) {
V_72 -> V_169 = 0x00000000 ;
V_72 -> V_170 = 0x00000000 ;
} else
if ( V_6 -> V_10 . V_56 . V_165 >= 0x25 ) {
V_72 -> V_169 = 0x00020000 ;
V_72 -> V_170 = 0x00000000 ;
} else {
V_72 -> V_169 = 0x20000000 |
( V_96 -> V_147 . V_22 . V_63 + ( ( V_96 -> V_162 . V_168 + 2 ) << 2 ) ) ;
V_72 -> V_170 = 0x00000000 ;
}
return F_85 ( V_143 , V_12 ) ;
}
static inline T_1
F_93 ( struct V_3 * V_4 , T_1 V_44 )
{
T_1 V_48 = 0 ;
if ( V_44 & V_49 )
V_48 |= V_50 ;
if ( V_44 & V_51 )
V_48 |= V_52 ;
return V_48 ;
}
int
F_94 ( struct V_41 * V_11 , void * V_28 ,
struct V_17 * V_18 )
{
struct V_171 * V_72 = V_28 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
bool V_172 = ! ! ( V_72 -> V_48 & V_173 ) ;
bool V_174 = ! ! ( V_72 -> V_48 & V_175 ) ;
int V_12 ;
V_2 = F_57 ( V_11 , V_18 , V_72 -> V_74 ) ;
if ( ! V_2 )
return - V_107 ;
V_4 = F_2 ( V_2 ) ;
if ( V_172 )
V_12 = F_95 ( V_4 -> V_7 . V_34 , V_174 ) ? 0 : - V_176 ;
else {
long V_177 ;
V_177 = F_96 ( V_4 -> V_7 . V_34 , V_174 , true , 30 * V_178 ) ;
if ( ! V_177 )
V_12 = - V_176 ;
else if ( V_177 > 0 )
V_12 = 0 ;
else
V_12 = V_177 ;
}
F_97 ( V_4 ) ;
F_41 ( V_2 ) ;
return V_12 ;
}
int
F_98 ( struct V_41 * V_11 , void * V_28 ,
struct V_17 * V_18 )
{
struct V_179 * V_72 = V_28 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_57 ( V_11 , V_18 , V_72 -> V_74 ) ;
if ( ! V_2 )
return - V_107 ;
V_4 = F_2 ( V_2 ) ;
F_99 ( V_4 ) ;
F_41 ( V_2 ) ;
return 0 ;
}
int
F_100 ( struct V_41 * V_11 , void * V_28 ,
struct V_17 * V_18 )
{
struct V_60 * V_72 = V_28 ;
struct V_1 * V_2 ;
int V_12 ;
V_2 = F_57 ( V_11 , V_18 , V_72 -> V_74 ) ;
if ( ! V_2 )
return - V_107 ;
V_12 = F_34 ( V_18 , V_2 , V_72 ) ;
F_41 ( V_2 ) ;
return V_12 ;
}
