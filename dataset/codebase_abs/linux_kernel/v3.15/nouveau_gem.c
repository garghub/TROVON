void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
if ( V_2 -> V_7 )
F_3 ( V_2 , V_4 -> V_6 . V_8 ) ;
F_4 ( V_2 ) ;
V_2 -> V_9 = NULL ;
F_5 ( & V_6 ) ;
}
int
F_6 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_12 * V_13 = V_12 ( V_11 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_14 * V_15 ;
int V_16 ;
if ( ! V_13 -> V_17 . V_18 )
return 0 ;
V_16 = F_7 ( & V_4 -> V_6 , false , false , false , 0 ) ;
if ( V_16 )
return V_16 ;
V_15 = F_8 ( V_4 , V_13 -> V_17 . V_18 ) ;
if ( ! V_15 ) {
V_15 = F_9 ( sizeof( * V_15 ) , V_19 ) ;
if ( ! V_15 ) {
V_16 = - V_20 ;
goto V_21;
}
V_16 = F_10 ( V_4 , V_13 -> V_17 . V_18 , V_15 ) ;
if ( V_16 ) {
F_11 ( V_15 ) ;
goto V_21;
}
} else {
V_15 -> V_22 ++ ;
}
V_21:
F_12 ( & V_4 -> V_6 ) ;
return V_16 ;
}
static void
F_13 ( void * V_23 )
{
struct V_14 * V_15 = V_23 ;
F_14 ( V_15 ) ;
F_15 ( V_15 ) ;
F_11 ( V_15 ) ;
}
static void
F_16 ( struct V_3 * V_4 , struct V_14 * V_15 )
{
const bool V_24 = V_4 -> V_6 . V_25 . V_26 != V_27 ;
struct V_28 * V_29 = NULL ;
F_17 ( & V_15 -> V_30 ) ;
if ( V_24 ) {
F_18 ( & V_4 -> V_6 . V_31 -> V_32 ) ;
V_29 = F_19 ( V_4 -> V_6 . V_33 ) ;
F_20 ( & V_4 -> V_6 . V_31 -> V_32 ) ;
}
if ( V_29 ) {
F_21 ( V_29 , F_13 , V_15 ) ;
} else {
if ( V_24 )
F_14 ( V_15 ) ;
F_15 ( V_15 ) ;
F_11 ( V_15 ) ;
}
F_22 ( & V_29 ) ;
}
void
F_23 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_12 * V_13 = V_12 ( V_11 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_14 * V_15 ;
int V_16 ;
if ( ! V_13 -> V_17 . V_18 )
return;
V_16 = F_7 ( & V_4 -> V_6 , false , false , false , 0 ) ;
if ( V_16 )
return;
V_15 = F_8 ( V_4 , V_13 -> V_17 . V_18 ) ;
if ( V_15 ) {
if ( -- V_15 -> V_22 == 0 )
F_16 ( V_4 , V_15 ) ;
}
F_12 ( & V_4 -> V_6 ) ;
}
int
F_24 ( struct V_34 * V_35 , int V_36 , int V_37 , T_1 V_38 ,
T_1 V_39 , T_1 V_40 ,
struct V_3 * * V_41 )
{
struct V_42 * V_43 = V_42 ( V_35 ) ;
struct V_3 * V_4 ;
T_2 V_44 = 0 ;
int V_16 ;
if ( V_38 & V_45 )
V_44 |= V_46 ;
if ( V_38 & V_47 )
V_44 |= V_48 ;
if ( ! V_44 || V_38 & V_49 )
V_44 |= V_50 ;
V_16 = F_25 ( V_35 , V_36 , V_37 , V_44 , V_39 ,
V_40 , NULL , V_41 ) ;
if ( V_16 )
return V_16 ;
V_4 = * V_41 ;
V_4 -> V_51 = V_45 |
V_47 ;
if ( F_26 ( V_43 -> V_52 ) -> V_53 >= V_54 )
V_4 -> V_51 &= V_38 ;
V_16 = F_27 ( V_35 , & V_4 -> V_2 , V_4 -> V_6 . V_25 . V_36 ) ;
if ( V_16 ) {
F_28 ( NULL , V_41 ) ;
return - V_20 ;
}
V_4 -> V_6 . V_55 = V_4 -> V_2 . V_9 ;
return 0 ;
}
static int
F_29 ( struct V_10 * V_11 , struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_12 * V_13 = V_12 ( V_11 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_14 * V_15 ;
if ( V_4 -> V_6 . V_25 . V_26 == V_58 )
V_57 -> V_38 = V_47 ;
else
V_57 -> V_38 = V_45 ;
V_57 -> V_59 = V_4 -> V_6 . V_59 ;
if ( V_13 -> V_17 . V_18 ) {
V_15 = F_8 ( V_4 , V_13 -> V_17 . V_18 ) ;
if ( ! V_15 )
return - V_60 ;
V_57 -> V_59 = V_15 -> V_59 ;
}
V_57 -> V_36 = V_4 -> V_6 . V_25 . V_61 << V_62 ;
V_57 -> V_63 = F_30 ( & V_4 -> V_6 . V_64 ) ;
V_57 -> V_39 = V_4 -> V_39 ;
V_57 -> V_40 = V_4 -> V_40 ;
return 0 ;
}
int
F_31 ( struct V_34 * V_35 , void * V_23 ,
struct V_10 * V_11 )
{
struct V_42 * V_43 = V_42 ( V_35 ) ;
struct V_12 * V_13 = V_12 ( V_11 ) ;
struct V_65 * V_66 = V_65 ( V_43 -> V_52 ) ;
struct V_67 * V_68 = V_23 ;
struct V_3 * V_4 = NULL ;
int V_16 = 0 ;
if ( ! V_66 -> V_69 ( V_66 , V_68 -> V_70 . V_40 ) ) {
F_32 ( V_13 , L_1 , V_68 -> V_70 . V_40 ) ;
return - V_60 ;
}
V_16 = F_24 ( V_35 , V_68 -> V_70 . V_36 , V_68 -> V_37 ,
V_68 -> V_70 . V_38 , V_68 -> V_70 . V_39 ,
V_68 -> V_70 . V_40 , & V_4 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_33 ( V_11 , & V_4 -> V_2 , & V_68 -> V_70 . V_71 ) ;
if ( V_16 == 0 ) {
V_16 = F_29 ( V_11 , & V_4 -> V_2 , & V_68 -> V_70 ) ;
if ( V_16 )
F_34 ( V_11 , V_68 -> V_70 . V_71 ) ;
}
F_35 ( & V_4 -> V_2 ) ;
return V_16 ;
}
static int
F_36 ( struct V_1 * V_2 , T_1 V_72 ,
T_1 V_73 , T_1 V_51 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_1 V_74 = V_51 & V_4 -> V_51 &
( V_73 ? V_73 : V_72 ) ;
T_1 V_75 = 0 , V_76 = 0 ;
if ( ! V_74 )
return - V_60 ;
if ( V_51 & V_45 )
V_76 |= V_46 ;
if ( V_51 & V_47 )
V_76 |= V_48 ;
if ( ( V_74 & V_45 ) &&
V_6 -> V_25 . V_26 == V_77 )
V_75 |= V_46 ;
else if ( ( V_74 & V_47 ) &&
V_6 -> V_25 . V_26 == V_58 )
V_75 |= V_48 ;
else if ( V_74 & V_45 )
V_75 |= V_46 ;
else
V_75 |= V_48 ;
F_37 ( V_4 , V_75 , V_76 ) ;
return 0 ;
}
static void
F_38 ( struct V_78 * V_79 , struct V_28 * V_29 ,
struct V_80 * V_81 )
{
struct V_78 * V_82 , * V_83 ;
struct V_3 * V_4 ;
F_39 (entry, tmp, list) {
V_4 = F_40 ( V_82 , struct V_3 , V_82 ) ;
if ( F_41 ( V_29 ) )
F_42 ( V_4 , V_29 ) ;
if ( F_43 ( V_4 -> V_84 ) ) {
F_44 ( & V_4 -> V_85 ) ;
V_4 -> V_84 = false ;
}
F_17 ( & V_4 -> V_82 ) ;
V_4 -> V_86 = NULL ;
F_45 ( & V_4 -> V_6 , V_81 ) ;
F_35 ( & V_4 -> V_2 ) ;
}
}
static void
F_46 ( struct V_87 * V_88 , struct V_28 * V_29 )
{
F_38 ( & V_88 -> V_89 , V_29 , & V_88 -> V_81 ) ;
F_38 ( & V_88 -> V_90 , V_29 , & V_88 -> V_81 ) ;
F_38 ( & V_88 -> V_91 , V_29 , & V_88 -> V_81 ) ;
}
static void
F_47 ( struct V_87 * V_88 , struct V_28 * V_29 )
{
F_46 ( V_88 , V_29 ) ;
F_48 ( & V_88 -> V_81 ) ;
}
static int
F_49 ( struct V_92 * V_93 , struct V_10 * V_11 ,
struct V_94 * V_95 ,
int V_96 , struct V_87 * V_88 )
{
struct V_12 * V_13 = V_12 ( V_11 ) ;
struct V_34 * V_35 = V_93 -> V_43 -> V_35 ;
int V_97 = 0 ;
int V_16 , V_98 ;
struct V_3 * V_99 = NULL ;
F_50 ( & V_88 -> V_81 , & V_100 ) ;
V_101:
if ( ++ V_97 > 100000 ) {
F_32 ( V_13 , L_2 , V_102 ) ;
return - V_60 ;
}
for ( V_98 = 0 ; V_98 < V_96 ; V_98 ++ ) {
struct V_94 * V_103 = & V_95 [ V_98 ] ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_51 ( V_35 , V_11 , V_103 -> V_71 ) ;
if ( ! V_2 ) {
F_32 ( V_13 , L_3 , V_103 -> V_71 ) ;
F_52 ( & V_88 -> V_81 ) ;
F_47 ( V_88 , NULL ) ;
return - V_104 ;
}
V_4 = F_2 ( V_2 ) ;
if ( V_4 == V_99 ) {
V_99 = NULL ;
F_35 ( V_2 ) ;
continue;
}
if ( V_4 -> V_86 && V_4 -> V_86 == V_11 ) {
F_32 ( V_13 , L_4
L_5 , V_103 -> V_71 ) ;
F_35 ( V_2 ) ;
F_52 ( & V_88 -> V_81 ) ;
F_47 ( V_88 , NULL ) ;
return - V_60 ;
}
V_16 = F_7 ( & V_4 -> V_6 , true , false , true , & V_88 -> V_81 ) ;
if ( V_16 ) {
F_46 ( V_88 , NULL ) ;
if ( F_43 ( V_16 == - V_105 ) ) {
V_16 = F_53 ( & V_4 -> V_6 , true ,
& V_88 -> V_81 ) ;
if ( ! V_16 )
V_99 = V_4 ;
}
if ( F_43 ( V_16 ) ) {
F_52 ( & V_88 -> V_81 ) ;
F_48 ( & V_88 -> V_81 ) ;
F_35 ( V_2 ) ;
if ( V_16 != - V_106 )
F_32 ( V_13 , L_6 ) ;
return V_16 ;
}
}
V_103 -> V_107 = ( V_108 ) ( unsigned long ) V_4 ;
V_4 -> V_86 = V_11 ;
V_4 -> V_109 = V_98 ;
if ( ( V_103 -> V_51 & V_45 ) &&
( V_103 -> V_51 & V_47 ) )
F_54 ( & V_4 -> V_82 , & V_88 -> V_91 ) ;
else
if ( V_103 -> V_51 & V_45 )
F_54 ( & V_4 -> V_82 , & V_88 -> V_89 ) ;
else
if ( V_103 -> V_51 & V_47 )
F_54 ( & V_4 -> V_82 , & V_88 -> V_90 ) ;
else {
F_32 ( V_13 , L_7 ,
V_103 -> V_51 ) ;
F_54 ( & V_4 -> V_82 , & V_88 -> V_91 ) ;
F_52 ( & V_88 -> V_81 ) ;
F_47 ( V_88 , NULL ) ;
return - V_60 ;
}
if ( V_4 == V_99 )
goto V_101;
}
F_52 ( & V_88 -> V_81 ) ;
return 0 ;
}
static int
F_55 ( struct V_92 * V_93 , struct V_3 * V_4 )
{
struct V_28 * V_29 = NULL ;
int V_16 = 0 ;
F_18 ( & V_4 -> V_6 . V_31 -> V_32 ) ;
V_29 = F_19 ( V_4 -> V_6 . V_33 ) ;
F_20 ( & V_4 -> V_6 . V_31 -> V_32 ) ;
if ( V_29 ) {
V_16 = F_56 ( V_29 , V_93 ) ;
F_22 ( & V_29 ) ;
}
return V_16 ;
}
static int
F_57 ( struct V_92 * V_93 , struct V_12 * V_13 ,
struct V_78 * V_79 , struct V_94 * V_95 ,
V_108 V_110 )
{
struct V_42 * V_43 = V_93 -> V_43 ;
struct V_94 T_3 * V_111 =
( void V_112 T_3 * ) ( V_113 ) V_110 ;
struct V_3 * V_4 ;
int V_16 , V_114 = 0 ;
F_58 (nvbo, list, entry) {
struct V_94 * V_103 = & V_95 [ V_4 -> V_109 ] ;
V_16 = F_36 ( & V_4 -> V_2 , V_103 -> V_72 ,
V_103 -> V_73 ,
V_103 -> V_51 ) ;
if ( F_43 ( V_16 ) ) {
F_32 ( V_13 , L_8 ) ;
return V_16 ;
}
V_16 = F_59 ( V_4 , true , false ) ;
if ( F_43 ( V_16 ) ) {
if ( V_16 != - V_106 )
F_32 ( V_13 , L_9 ) ;
return V_16 ;
}
V_16 = F_55 ( V_93 , V_4 ) ;
if ( F_43 ( V_16 ) ) {
F_32 ( V_13 , L_10 ) ;
return V_16 ;
}
if ( F_26 ( V_43 -> V_52 ) -> V_53 < V_54 ) {
if ( V_4 -> V_6 . V_59 == V_103 -> V_115 . V_59 &&
( ( V_4 -> V_6 . V_25 . V_26 == V_77 &&
V_103 -> V_115 . V_38 & V_45 ) ||
( V_4 -> V_6 . V_25 . V_26 == V_58 &&
V_103 -> V_115 . V_38 & V_47 ) ) )
continue;
if ( V_4 -> V_6 . V_25 . V_26 == V_58 )
V_103 -> V_115 . V_38 = V_47 ;
else
V_103 -> V_115 . V_38 = V_45 ;
V_103 -> V_115 . V_59 = V_4 -> V_6 . V_59 ;
V_103 -> V_115 . V_116 = 0 ;
V_114 ++ ;
if ( F_60 ( & V_111 [ V_4 -> V_109 ] . V_115 ,
& V_103 -> V_115 , sizeof( V_103 -> V_115 ) ) )
return - V_117 ;
}
}
return V_114 ;
}
static int
F_61 ( struct V_92 * V_93 ,
struct V_10 * V_11 ,
struct V_94 * V_95 ,
V_108 V_118 , int V_96 ,
struct V_87 * V_88 , int * V_119 )
{
struct V_12 * V_13 = V_12 ( V_11 ) ;
int V_16 , V_114 = 0 ;
F_62 ( & V_88 -> V_89 ) ;
F_62 ( & V_88 -> V_90 ) ;
F_62 ( & V_88 -> V_91 ) ;
if ( V_96 == 0 )
return 0 ;
V_16 = F_49 ( V_93 , V_11 , V_95 , V_96 , V_88 ) ;
if ( F_43 ( V_16 ) ) {
if ( V_16 != - V_106 )
F_32 ( V_13 , L_11 ) ;
return V_16 ;
}
V_16 = F_57 ( V_93 , V_13 , & V_88 -> V_89 , V_95 , V_118 ) ;
if ( F_43 ( V_16 < 0 ) ) {
if ( V_16 != - V_106 )
F_32 ( V_13 , L_12 ) ;
F_47 ( V_88 , NULL ) ;
return V_16 ;
}
V_114 += V_16 ;
V_16 = F_57 ( V_93 , V_13 , & V_88 -> V_90 , V_95 , V_118 ) ;
if ( F_43 ( V_16 < 0 ) ) {
if ( V_16 != - V_106 )
F_32 ( V_13 , L_13 ) ;
F_47 ( V_88 , NULL ) ;
return V_16 ;
}
V_114 += V_16 ;
V_16 = F_57 ( V_93 , V_13 , & V_88 -> V_91 , V_95 , V_118 ) ;
if ( F_43 ( V_16 < 0 ) ) {
if ( V_16 != - V_106 )
F_32 ( V_13 , L_14 ) ;
F_47 ( V_88 , NULL ) ;
return V_16 ;
}
V_114 += V_16 ;
* V_119 = V_114 ;
return 0 ;
}
static inline void
F_63 ( void * V_120 )
{
if ( ! F_64 ( V_120 ) )
F_11 ( V_120 ) ;
else
F_65 ( V_120 ) ;
}
static inline void *
F_66 ( V_108 V_121 , unsigned V_122 , unsigned V_36 )
{
void * V_25 ;
void T_3 * V_123 = ( void V_112 T_3 * ) ( V_113 ) V_121 ;
V_36 *= V_122 ;
V_25 = F_67 ( V_36 , V_19 | V_124 ) ;
if ( ! V_25 )
V_25 = F_68 ( V_36 ) ;
if ( ! V_25 )
return F_69 ( - V_20 ) ;
if ( F_70 ( V_25 , V_123 , V_36 ) ) {
F_63 ( V_25 ) ;
return F_69 ( - V_117 ) ;
}
return V_25 ;
}
static int
F_71 ( struct V_12 * V_13 ,
struct V_125 * V_68 ,
struct V_94 * V_6 )
{
struct V_126 * V_127 = NULL ;
int V_16 = 0 ;
unsigned V_98 ;
V_127 = F_66 ( V_68 -> V_114 , V_68 -> V_128 , sizeof( * V_127 ) ) ;
if ( F_72 ( V_127 ) )
return F_73 ( V_127 ) ;
for ( V_98 = 0 ; V_98 < V_68 -> V_128 ; V_98 ++ ) {
struct V_126 * V_129 = & V_127 [ V_98 ] ;
struct V_94 * V_103 ;
struct V_3 * V_4 ;
T_1 V_23 ;
if ( F_43 ( V_129 -> V_130 > V_68 -> V_96 ) ) {
F_32 ( V_13 , L_15 ) ;
V_16 = - V_60 ;
break;
}
V_103 = & V_6 [ V_129 -> V_130 ] ;
if ( V_103 -> V_115 . V_116 )
continue;
if ( F_43 ( V_129 -> V_131 > V_68 -> V_96 ) ) {
F_32 ( V_13 , L_16 ) ;
V_16 = - V_60 ;
break;
}
V_4 = ( void * ) ( unsigned long ) V_6 [ V_129 -> V_131 ] . V_107 ;
if ( F_43 ( V_129 -> V_132 + 4 >
V_4 -> V_6 . V_25 . V_61 << V_62 ) ) {
F_32 ( V_13 , L_17 ) ;
V_16 = - V_60 ;
break;
}
if ( ! V_4 -> V_85 . V_133 ) {
V_16 = F_74 ( & V_4 -> V_6 , 0 , V_4 -> V_6 . V_25 . V_61 ,
& V_4 -> V_85 ) ;
if ( V_16 ) {
F_32 ( V_13 , L_18 ) ;
break;
}
V_4 -> V_84 = true ;
}
if ( V_129 -> V_44 & V_134 )
V_23 = V_103 -> V_115 . V_59 + V_129 -> V_23 ;
else
if ( V_129 -> V_44 & V_135 )
V_23 = ( V_103 -> V_115 . V_59 + V_129 -> V_23 ) >> 32 ;
else
V_23 = V_129 -> V_23 ;
if ( V_129 -> V_44 & V_136 ) {
if ( V_103 -> V_115 . V_38 == V_47 )
V_23 |= V_129 -> V_137 ;
else
V_23 |= V_129 -> V_138 ;
}
F_18 ( & V_4 -> V_6 . V_31 -> V_32 ) ;
V_16 = F_75 ( & V_4 -> V_6 , false , false , false ) ;
F_20 ( & V_4 -> V_6 . V_31 -> V_32 ) ;
if ( V_16 ) {
F_32 ( V_13 , L_19 , V_16 ) ;
break;
}
F_76 ( V_4 , V_129 -> V_132 >> 2 , V_23 ) ;
}
F_63 ( V_127 ) ;
return V_16 ;
}
int
F_77 ( struct V_34 * V_35 , void * V_23 ,
struct V_10 * V_11 )
{
struct V_139 * V_140 = F_78 ( V_11 , V_35 ) ;
struct V_12 * V_13 = V_12 ( V_11 ) ;
struct V_141 * V_142 ;
struct V_42 * V_43 = V_42 ( V_35 ) ;
struct V_125 * V_68 = V_23 ;
struct V_143 * V_144 ;
struct V_94 * V_6 ;
struct V_92 * V_93 = NULL ;
struct V_87 V_88 ;
struct V_28 * V_29 = NULL ;
int V_98 , V_145 , V_16 = 0 , V_146 = 0 ;
if ( F_43 ( ! V_140 ) )
return - V_20 ;
F_58 (temp, &abi16->channels, head) {
if ( V_142 -> V_93 -> V_71 == ( V_147 | V_68 -> V_148 ) ) {
V_93 = V_142 -> V_93 ;
break;
}
}
if ( ! V_93 )
return F_79 ( V_140 , - V_104 ) ;
V_68 -> V_149 = V_43 -> V_2 . V_149 ;
V_68 -> V_150 = V_43 -> V_2 . V_150 ;
if ( F_43 ( V_68 -> V_151 == 0 ) )
goto V_152;
if ( F_43 ( V_68 -> V_151 > V_153 ) ) {
F_32 ( V_13 , L_20 ,
V_68 -> V_151 , V_153 ) ;
return F_79 ( V_140 , - V_60 ) ;
}
if ( F_43 ( V_68 -> V_96 > V_154 ) ) {
F_32 ( V_13 , L_21 ,
V_68 -> V_96 , V_154 ) ;
return F_79 ( V_140 , - V_60 ) ;
}
if ( F_43 ( V_68 -> V_128 > V_155 ) ) {
F_32 ( V_13 , L_22 ,
V_68 -> V_128 , V_155 ) ;
return F_79 ( V_140 , - V_60 ) ;
}
V_144 = F_66 ( V_68 -> V_144 , V_68 -> V_151 , sizeof( * V_144 ) ) ;
if ( F_72 ( V_144 ) )
return F_79 ( V_140 , F_73 ( V_144 ) ) ;
V_6 = F_66 ( V_68 -> V_156 , V_68 -> V_96 , sizeof( * V_6 ) ) ;
if ( F_72 ( V_6 ) ) {
F_63 ( V_144 ) ;
return F_79 ( V_140 , F_73 ( V_6 ) ) ;
}
for ( V_98 = 0 ; V_98 < V_68 -> V_151 ; V_98 ++ ) {
if ( V_144 [ V_98 ] . V_130 >= V_68 -> V_96 ) {
F_32 ( V_13 , L_23 , V_98 ) ;
V_16 = - V_60 ;
goto V_157;
}
}
V_16 = F_61 ( V_93 , V_11 , V_6 , V_68 -> V_156 ,
V_68 -> V_96 , & V_88 , & V_146 ) ;
if ( V_16 ) {
if ( V_16 != - V_106 )
F_32 ( V_13 , L_24 , V_16 ) ;
goto V_157;
}
if ( V_146 ) {
V_16 = F_71 ( V_13 , V_68 , V_6 ) ;
if ( V_16 ) {
F_32 ( V_13 , L_25 , V_16 ) ;
goto V_21;
}
}
if ( V_93 -> V_158 . V_159 ) {
V_16 = F_80 ( V_93 , V_68 -> V_151 + 1 , 16 ) ;
if ( V_16 ) {
F_32 ( V_13 , L_26 , V_16 ) ;
goto V_21;
}
for ( V_98 = 0 ; V_98 < V_68 -> V_151 ; V_98 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_6 [ V_144 [ V_98 ] . V_130 ] . V_107 ;
F_81 ( V_93 , V_4 , V_144 [ V_98 ] . V_59 ,
V_144 [ V_98 ] . V_160 ) ;
}
} else
if ( F_26 ( V_43 -> V_52 ) -> V_161 >= 0x25 ) {
V_16 = F_82 ( V_93 , V_68 -> V_151 * 2 ) ;
if ( V_16 ) {
F_32 ( V_13 , L_27 , V_16 ) ;
goto V_21;
}
for ( V_98 = 0 ; V_98 < V_68 -> V_151 ; V_98 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_6 [ V_144 [ V_98 ] . V_130 ] . V_107 ;
F_83 ( V_93 , ( V_4 -> V_6 . V_59 + V_144 [ V_98 ] . V_59 ) | 2 ) ;
F_83 ( V_93 , 0 ) ;
}
} else {
V_16 = F_82 ( V_93 , V_68 -> V_151 * ( 2 + V_162 ) ) ;
if ( V_16 ) {
F_32 ( V_13 , L_28 , V_16 ) ;
goto V_21;
}
for ( V_98 = 0 ; V_98 < V_68 -> V_151 ; V_98 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_6 [ V_144 [ V_98 ] . V_130 ] . V_107 ;
T_1 V_163 ;
V_163 = V_93 -> V_144 . V_15 . V_59 + ( ( V_93 -> V_158 . V_164 + 2 ) << 2 ) ;
V_163 |= 0x20000000 ;
if ( F_43 ( V_163 != V_68 -> V_165 ) ) {
if ( ! V_4 -> V_85 . V_133 ) {
V_16 = F_74 ( & V_4 -> V_6 , 0 ,
V_4 -> V_6 . V_25 .
V_61 ,
& V_4 -> V_85 ) ;
if ( V_16 ) {
F_84 ( V_93 ) ;
goto V_21;
}
V_4 -> V_84 = true ;
}
F_76 ( V_4 , ( V_144 [ V_98 ] . V_59 +
V_144 [ V_98 ] . V_160 - 8 ) / 4 , V_163 ) ;
}
F_83 ( V_93 , 0x20000000 |
( V_4 -> V_6 . V_59 + V_144 [ V_98 ] . V_59 ) ) ;
F_83 ( V_93 , 0 ) ;
for ( V_145 = 0 ; V_145 < V_162 ; V_145 ++ )
F_83 ( V_93 , 0 ) ;
}
}
V_16 = F_85 ( V_93 , false , & V_29 ) ;
if ( V_16 ) {
F_32 ( V_13 , L_29 , V_16 ) ;
F_84 ( V_93 ) ;
goto V_21;
}
V_21:
F_47 ( & V_88 , V_29 ) ;
F_22 ( & V_29 ) ;
V_157:
F_63 ( V_6 ) ;
F_63 ( V_144 ) ;
V_152:
if ( V_93 -> V_158 . V_159 ) {
V_68 -> V_165 = 0x00000000 ;
V_68 -> V_166 = 0x00000000 ;
} else
if ( F_26 ( V_43 -> V_52 ) -> V_161 >= 0x25 ) {
V_68 -> V_165 = 0x00020000 ;
V_68 -> V_166 = 0x00000000 ;
} else {
V_68 -> V_165 = 0x20000000 |
( V_93 -> V_144 . V_15 . V_59 + ( ( V_93 -> V_158 . V_164 + 2 ) << 2 ) ) ;
V_68 -> V_166 = 0x00000000 ;
}
return F_79 ( V_140 , V_16 ) ;
}
static inline T_1
F_86 ( struct V_3 * V_4 , T_1 V_38 )
{
T_1 V_44 = 0 ;
if ( V_38 & V_45 )
V_44 |= V_46 ;
if ( V_38 & V_47 )
V_44 |= V_48 ;
return V_44 ;
}
int
F_87 ( struct V_34 * V_35 , void * V_23 ,
struct V_10 * V_11 )
{
struct V_167 * V_68 = V_23 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
bool V_168 = ! ! ( V_68 -> V_44 & V_169 ) ;
int V_16 = - V_60 ;
V_2 = F_51 ( V_35 , V_11 , V_68 -> V_71 ) ;
if ( ! V_2 )
return - V_104 ;
V_4 = F_2 ( V_2 ) ;
F_18 ( & V_4 -> V_6 . V_31 -> V_32 ) ;
V_16 = F_75 ( & V_4 -> V_6 , true , true , V_168 ) ;
F_20 ( & V_4 -> V_6 . V_31 -> V_32 ) ;
F_35 ( V_2 ) ;
return V_16 ;
}
int
F_88 ( struct V_34 * V_35 , void * V_23 ,
struct V_10 * V_11 )
{
return 0 ;
}
int
F_89 ( struct V_34 * V_35 , void * V_23 ,
struct V_10 * V_11 )
{
struct V_56 * V_68 = V_23 ;
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_51 ( V_35 , V_11 , V_68 -> V_71 ) ;
if ( ! V_2 )
return - V_104 ;
V_16 = F_29 ( V_11 , V_2 , V_68 ) ;
F_35 ( V_2 ) ;
return V_16 ;
}
