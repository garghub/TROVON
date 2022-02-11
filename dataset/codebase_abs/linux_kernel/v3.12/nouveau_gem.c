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
if ( V_2 -> V_8 )
F_3 ( V_2 , V_4 -> V_7 . V_9 ) ;
F_4 ( & V_7 ) ;
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
}
int
F_7 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_12 * V_13 = V_12 ( V_11 ) ;
struct V_3 * V_4 = F_8 ( V_2 ) ;
struct V_14 * V_15 ;
int V_16 ;
if ( ! V_13 -> V_17 . V_18 )
return 0 ;
V_16 = F_9 ( & V_4 -> V_7 , false , false , false , 0 ) ;
if ( V_16 )
return V_16 ;
V_15 = F_10 ( V_4 , V_13 -> V_17 . V_18 ) ;
if ( ! V_15 ) {
V_15 = F_11 ( sizeof( * V_15 ) , V_19 ) ;
if ( ! V_15 ) {
V_16 = - V_20 ;
goto V_21;
}
V_16 = F_12 ( V_4 , V_13 -> V_17 . V_18 , V_15 ) ;
if ( V_16 ) {
F_6 ( V_15 ) ;
goto V_21;
}
} else {
V_15 -> V_22 ++ ;
}
V_21:
F_13 ( & V_4 -> V_7 ) ;
return V_16 ;
}
static void
F_14 ( void * V_23 )
{
struct V_14 * V_15 = V_23 ;
F_15 ( V_15 ) ;
F_16 ( V_15 ) ;
F_6 ( V_15 ) ;
}
static void
F_17 ( struct V_3 * V_4 , struct V_14 * V_15 )
{
const bool V_24 = V_4 -> V_7 . V_25 . V_26 != V_27 ;
struct V_28 * V_29 = NULL ;
F_18 ( & V_15 -> V_30 ) ;
if ( V_24 ) {
F_19 ( & V_4 -> V_7 . V_31 -> V_32 ) ;
if ( V_4 -> V_7 . V_33 )
V_29 = F_20 ( V_4 -> V_7 . V_33 ) ;
F_21 ( & V_4 -> V_7 . V_31 -> V_32 ) ;
}
if ( V_29 ) {
F_22 ( V_29 , F_14 , V_15 ) ;
} else {
if ( V_24 )
F_15 ( V_15 ) ;
F_16 ( V_15 ) ;
F_6 ( V_15 ) ;
}
F_23 ( & V_29 ) ;
}
void
F_24 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_12 * V_13 = V_12 ( V_11 ) ;
struct V_3 * V_4 = F_8 ( V_2 ) ;
struct V_14 * V_15 ;
int V_16 ;
if ( ! V_13 -> V_17 . V_18 )
return;
V_16 = F_9 ( & V_4 -> V_7 , false , false , false , 0 ) ;
if ( V_16 )
return;
V_15 = F_10 ( V_4 , V_13 -> V_17 . V_18 ) ;
if ( V_15 ) {
if ( -- V_15 -> V_22 == 0 )
F_17 ( V_4 , V_15 ) ;
}
F_13 ( & V_4 -> V_7 ) ;
}
int
F_25 ( struct V_34 * V_35 , int V_36 , int V_37 , T_1 V_38 ,
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
V_16 = F_26 ( V_35 , V_36 , V_37 , V_44 , V_39 ,
V_40 , NULL , V_41 ) ;
if ( V_16 )
return V_16 ;
V_4 = * V_41 ;
V_4 -> V_51 = V_45 |
V_47 ;
if ( F_27 ( V_43 -> V_52 ) -> V_53 >= V_54 )
V_4 -> V_51 &= V_38 ;
V_4 -> V_2 = F_28 ( V_35 , V_4 -> V_7 . V_25 . V_36 ) ;
if ( ! V_4 -> V_2 ) {
F_29 ( NULL , V_41 ) ;
return - V_20 ;
}
V_4 -> V_7 . V_55 = V_4 -> V_2 -> V_56 ;
V_4 -> V_2 -> V_5 = V_4 ;
return 0 ;
}
static int
F_30 ( struct V_10 * V_11 , struct V_1 * V_2 ,
struct V_57 * V_58 )
{
struct V_12 * V_13 = V_12 ( V_11 ) ;
struct V_3 * V_4 = F_8 ( V_2 ) ;
struct V_14 * V_15 ;
if ( V_4 -> V_7 . V_25 . V_26 == V_59 )
V_58 -> V_38 = V_47 ;
else
V_58 -> V_38 = V_45 ;
V_58 -> V_60 = V_4 -> V_7 . V_60 ;
if ( V_13 -> V_17 . V_18 ) {
V_15 = F_10 ( V_4 , V_13 -> V_17 . V_18 ) ;
if ( ! V_15 )
return - V_61 ;
V_58 -> V_60 = V_15 -> V_60 ;
}
V_58 -> V_36 = V_4 -> V_7 . V_25 . V_62 << V_63 ;
V_58 -> V_64 = F_31 ( & V_4 -> V_7 . V_65 ) ;
V_58 -> V_39 = V_4 -> V_39 ;
V_58 -> V_40 = V_4 -> V_40 ;
return 0 ;
}
int
F_32 ( struct V_34 * V_35 , void * V_23 ,
struct V_10 * V_11 )
{
struct V_42 * V_43 = V_42 ( V_35 ) ;
struct V_12 * V_13 = V_12 ( V_11 ) ;
struct V_66 * V_67 = V_66 ( V_43 -> V_52 ) ;
struct V_68 * V_69 = V_23 ;
struct V_3 * V_4 = NULL ;
int V_16 = 0 ;
V_43 -> V_70 . V_31 . V_71 = V_43 -> V_35 -> V_71 ;
if ( ! V_67 -> V_72 ( V_67 , V_69 -> V_73 . V_40 ) ) {
F_33 ( V_13 , L_1 , V_69 -> V_73 . V_40 ) ;
return - V_61 ;
}
V_16 = F_25 ( V_35 , V_69 -> V_73 . V_36 , V_69 -> V_37 ,
V_69 -> V_73 . V_38 , V_69 -> V_73 . V_39 ,
V_69 -> V_73 . V_40 , & V_4 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_34 ( V_11 , V_4 -> V_2 , & V_69 -> V_73 . V_74 ) ;
if ( V_16 == 0 ) {
V_16 = F_30 ( V_11 , V_4 -> V_2 , & V_69 -> V_73 ) ;
if ( V_16 )
F_35 ( V_11 , V_69 -> V_73 . V_74 ) ;
}
F_36 ( V_4 -> V_2 ) ;
return V_16 ;
}
static int
F_37 ( struct V_1 * V_2 , T_1 V_75 ,
T_1 V_76 , T_1 V_51 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_7 ;
T_1 V_77 = V_51 & V_4 -> V_51 &
( V_76 ? V_76 : V_75 ) ;
T_1 V_78 = 0 , V_79 = 0 ;
if ( ! V_77 )
return - V_61 ;
if ( V_51 & V_45 )
V_79 |= V_46 ;
if ( V_51 & V_47 )
V_79 |= V_48 ;
if ( ( V_77 & V_45 ) &&
V_7 -> V_25 . V_26 == V_80 )
V_78 |= V_46 ;
else if ( ( V_77 & V_47 ) &&
V_7 -> V_25 . V_26 == V_59 )
V_78 |= V_48 ;
else if ( V_77 & V_45 )
V_78 |= V_46 ;
else
V_78 |= V_48 ;
F_38 ( V_4 , V_78 , V_79 ) ;
return 0 ;
}
static void
F_39 ( struct V_81 * V_82 , struct V_28 * V_29 ,
struct V_83 * V_84 )
{
struct V_81 * V_85 , * V_86 ;
struct V_3 * V_4 ;
F_40 (entry, tmp, list) {
V_4 = F_41 ( V_85 , struct V_3 , V_85 ) ;
F_42 ( V_4 , V_29 ) ;
if ( F_43 ( V_4 -> V_87 ) ) {
F_44 ( & V_4 -> V_88 ) ;
V_4 -> V_87 = false ;
}
F_18 ( & V_4 -> V_85 ) ;
V_4 -> V_89 = NULL ;
F_45 ( & V_4 -> V_7 , V_84 ) ;
F_36 ( V_4 -> V_2 ) ;
}
}
static void
F_46 ( struct V_90 * V_91 , struct V_28 * V_29 )
{
F_39 ( & V_91 -> V_92 , V_29 , & V_91 -> V_84 ) ;
F_39 ( & V_91 -> V_93 , V_29 , & V_91 -> V_84 ) ;
F_39 ( & V_91 -> V_94 , V_29 , & V_91 -> V_84 ) ;
}
static void
F_47 ( struct V_90 * V_91 , struct V_28 * V_29 )
{
F_46 ( V_91 , V_29 ) ;
F_48 ( & V_91 -> V_84 ) ;
}
static int
F_49 ( struct V_95 * V_96 , struct V_10 * V_11 ,
struct V_97 * V_98 ,
int V_99 , struct V_90 * V_91 )
{
struct V_12 * V_13 = V_12 ( V_11 ) ;
struct V_34 * V_35 = V_96 -> V_43 -> V_35 ;
int V_100 = 0 ;
int V_16 , V_101 ;
struct V_3 * V_102 = NULL ;
F_50 ( & V_91 -> V_84 , & V_103 ) ;
V_104:
if ( ++ V_100 > 100000 ) {
F_33 ( V_13 , L_2 , V_105 ) ;
return - V_61 ;
}
for ( V_101 = 0 ; V_101 < V_99 ; V_101 ++ ) {
struct V_97 * V_106 = & V_98 [ V_101 ] ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_51 ( V_35 , V_11 , V_106 -> V_74 ) ;
if ( ! V_2 ) {
F_33 ( V_13 , L_3 , V_106 -> V_74 ) ;
F_52 ( & V_91 -> V_84 ) ;
F_47 ( V_91 , NULL ) ;
return - V_107 ;
}
V_4 = V_2 -> V_5 ;
if ( V_4 == V_102 ) {
V_102 = NULL ;
F_36 ( V_2 ) ;
continue;
}
if ( V_4 -> V_89 && V_4 -> V_89 == V_11 ) {
F_33 ( V_13 , L_4
L_5 , V_106 -> V_74 ) ;
F_36 ( V_2 ) ;
F_52 ( & V_91 -> V_84 ) ;
F_47 ( V_91 , NULL ) ;
return - V_61 ;
}
V_16 = F_9 ( & V_4 -> V_7 , true , false , true , & V_91 -> V_84 ) ;
if ( V_16 ) {
F_46 ( V_91 , NULL ) ;
if ( F_43 ( V_16 == - V_108 ) ) {
V_16 = F_53 ( & V_4 -> V_7 , true ,
& V_91 -> V_84 ) ;
if ( ! V_16 )
V_102 = V_4 ;
}
if ( F_43 ( V_16 ) ) {
F_52 ( & V_91 -> V_84 ) ;
F_48 ( & V_91 -> V_84 ) ;
F_36 ( V_2 ) ;
if ( V_16 != - V_109 )
F_33 ( V_13 , L_6 ) ;
return V_16 ;
}
}
V_106 -> V_110 = ( V_111 ) ( unsigned long ) V_4 ;
V_4 -> V_89 = V_11 ;
V_4 -> V_112 = V_101 ;
if ( ( V_106 -> V_51 & V_45 ) &&
( V_106 -> V_51 & V_47 ) )
F_54 ( & V_4 -> V_85 , & V_91 -> V_94 ) ;
else
if ( V_106 -> V_51 & V_45 )
F_54 ( & V_4 -> V_85 , & V_91 -> V_92 ) ;
else
if ( V_106 -> V_51 & V_47 )
F_54 ( & V_4 -> V_85 , & V_91 -> V_93 ) ;
else {
F_33 ( V_13 , L_7 ,
V_106 -> V_51 ) ;
F_54 ( & V_4 -> V_85 , & V_91 -> V_94 ) ;
F_52 ( & V_91 -> V_84 ) ;
F_47 ( V_91 , NULL ) ;
return - V_61 ;
}
if ( V_4 == V_102 )
goto V_104;
}
F_52 ( & V_91 -> V_84 ) ;
return 0 ;
}
static int
F_55 ( struct V_95 * V_96 , struct V_3 * V_4 )
{
struct V_28 * V_29 = NULL ;
int V_16 = 0 ;
F_19 ( & V_4 -> V_7 . V_31 -> V_32 ) ;
if ( V_4 -> V_7 . V_33 )
V_29 = F_20 ( V_4 -> V_7 . V_33 ) ;
F_21 ( & V_4 -> V_7 . V_31 -> V_32 ) ;
if ( V_29 ) {
V_16 = F_56 ( V_29 , V_96 ) ;
F_23 ( & V_29 ) ;
}
return V_16 ;
}
static int
F_57 ( struct V_95 * V_96 , struct V_12 * V_13 ,
struct V_81 * V_82 , struct V_97 * V_98 ,
V_111 V_113 )
{
struct V_42 * V_43 = V_96 -> V_43 ;
struct V_97 T_3 * V_114 =
( void V_115 T_3 * ) ( V_116 ) V_113 ;
struct V_3 * V_4 ;
int V_16 , V_117 = 0 ;
F_58 (nvbo, list, entry) {
struct V_97 * V_106 = & V_98 [ V_4 -> V_112 ] ;
V_16 = F_55 ( V_96 , V_4 ) ;
if ( F_43 ( V_16 ) ) {
F_33 ( V_13 , L_8 ) ;
return V_16 ;
}
V_16 = F_37 ( V_4 -> V_2 , V_106 -> V_75 ,
V_106 -> V_76 ,
V_106 -> V_51 ) ;
if ( F_43 ( V_16 ) ) {
F_33 ( V_13 , L_9 ) ;
return V_16 ;
}
V_16 = F_59 ( V_4 , true , false ) ;
if ( F_43 ( V_16 ) ) {
if ( V_16 != - V_109 )
F_33 ( V_13 , L_10 ) ;
return V_16 ;
}
V_16 = F_55 ( V_96 , V_4 ) ;
if ( F_43 ( V_16 ) ) {
F_33 ( V_13 , L_11 ) ;
return V_16 ;
}
if ( F_27 ( V_43 -> V_52 ) -> V_53 < V_54 ) {
if ( V_4 -> V_7 . V_60 == V_106 -> V_118 . V_60 &&
( ( V_4 -> V_7 . V_25 . V_26 == V_80 &&
V_106 -> V_118 . V_38 & V_45 ) ||
( V_4 -> V_7 . V_25 . V_26 == V_59 &&
V_106 -> V_118 . V_38 & V_47 ) ) )
continue;
if ( V_4 -> V_7 . V_25 . V_26 == V_59 )
V_106 -> V_118 . V_38 = V_47 ;
else
V_106 -> V_118 . V_38 = V_45 ;
V_106 -> V_118 . V_60 = V_4 -> V_7 . V_60 ;
V_106 -> V_118 . V_119 = 0 ;
V_117 ++ ;
if ( F_60 ( & V_114 [ V_4 -> V_112 ] . V_118 ,
& V_106 -> V_118 , sizeof( V_106 -> V_118 ) ) )
return - V_120 ;
}
}
return V_117 ;
}
static int
F_61 ( struct V_95 * V_96 ,
struct V_10 * V_11 ,
struct V_97 * V_98 ,
V_111 V_121 , int V_99 ,
struct V_90 * V_91 , int * V_122 )
{
struct V_12 * V_13 = V_12 ( V_11 ) ;
int V_16 , V_117 = 0 ;
F_62 ( & V_91 -> V_92 ) ;
F_62 ( & V_91 -> V_93 ) ;
F_62 ( & V_91 -> V_94 ) ;
if ( V_99 == 0 )
return 0 ;
V_16 = F_49 ( V_96 , V_11 , V_98 , V_99 , V_91 ) ;
if ( F_43 ( V_16 ) ) {
if ( V_16 != - V_109 )
F_33 ( V_13 , L_12 ) ;
return V_16 ;
}
V_16 = F_57 ( V_96 , V_13 , & V_91 -> V_92 , V_98 , V_121 ) ;
if ( F_43 ( V_16 < 0 ) ) {
if ( V_16 != - V_109 )
F_33 ( V_13 , L_13 ) ;
F_47 ( V_91 , NULL ) ;
return V_16 ;
}
V_117 += V_16 ;
V_16 = F_57 ( V_96 , V_13 , & V_91 -> V_93 , V_98 , V_121 ) ;
if ( F_43 ( V_16 < 0 ) ) {
if ( V_16 != - V_109 )
F_33 ( V_13 , L_14 ) ;
F_47 ( V_91 , NULL ) ;
return V_16 ;
}
V_117 += V_16 ;
V_16 = F_57 ( V_96 , V_13 , & V_91 -> V_94 , V_98 , V_121 ) ;
if ( F_43 ( V_16 < 0 ) ) {
if ( V_16 != - V_109 )
F_33 ( V_13 , L_15 ) ;
F_47 ( V_91 , NULL ) ;
return V_16 ;
}
V_117 += V_16 ;
* V_122 = V_117 ;
return 0 ;
}
static inline void
F_63 ( void * V_123 )
{
if ( ! F_64 ( V_123 ) )
F_6 ( V_123 ) ;
else
F_65 ( V_123 ) ;
}
static inline void *
F_66 ( V_111 V_124 , unsigned V_125 , unsigned V_36 )
{
void * V_25 ;
void T_3 * V_126 = ( void V_115 T_3 * ) ( V_116 ) V_124 ;
V_36 *= V_125 ;
V_25 = F_67 ( V_36 , V_19 | V_127 ) ;
if ( ! V_25 )
V_25 = F_68 ( V_36 ) ;
if ( ! V_25 )
return F_69 ( - V_20 ) ;
if ( F_70 ( V_25 , V_126 , V_36 ) ) {
F_63 ( V_25 ) ;
return F_69 ( - V_120 ) ;
}
return V_25 ;
}
static int
F_71 ( struct V_12 * V_13 ,
struct V_128 * V_69 ,
struct V_97 * V_7 )
{
struct V_129 * V_130 = NULL ;
int V_16 = 0 ;
unsigned V_101 ;
V_130 = F_66 ( V_69 -> V_117 , V_69 -> V_131 , sizeof( * V_130 ) ) ;
if ( F_72 ( V_130 ) )
return F_73 ( V_130 ) ;
for ( V_101 = 0 ; V_101 < V_69 -> V_131 ; V_101 ++ ) {
struct V_129 * V_132 = & V_130 [ V_101 ] ;
struct V_97 * V_106 ;
struct V_3 * V_4 ;
T_1 V_23 ;
if ( F_43 ( V_132 -> V_133 > V_69 -> V_99 ) ) {
F_33 ( V_13 , L_16 ) ;
V_16 = - V_61 ;
break;
}
V_106 = & V_7 [ V_132 -> V_133 ] ;
if ( V_106 -> V_118 . V_119 )
continue;
if ( F_43 ( V_132 -> V_134 > V_69 -> V_99 ) ) {
F_33 ( V_13 , L_17 ) ;
V_16 = - V_61 ;
break;
}
V_4 = ( void * ) ( unsigned long ) V_7 [ V_132 -> V_134 ] . V_110 ;
if ( F_43 ( V_132 -> V_135 + 4 >
V_4 -> V_7 . V_25 . V_62 << V_63 ) ) {
F_33 ( V_13 , L_18 ) ;
V_16 = - V_61 ;
break;
}
if ( ! V_4 -> V_88 . V_136 ) {
V_16 = F_74 ( & V_4 -> V_7 , 0 , V_4 -> V_7 . V_25 . V_62 ,
& V_4 -> V_88 ) ;
if ( V_16 ) {
F_33 ( V_13 , L_19 ) ;
break;
}
V_4 -> V_87 = true ;
}
if ( V_132 -> V_44 & V_137 )
V_23 = V_106 -> V_118 . V_60 + V_132 -> V_23 ;
else
if ( V_132 -> V_44 & V_138 )
V_23 = ( V_106 -> V_118 . V_60 + V_132 -> V_23 ) >> 32 ;
else
V_23 = V_132 -> V_23 ;
if ( V_132 -> V_44 & V_139 ) {
if ( V_106 -> V_118 . V_38 == V_47 )
V_23 |= V_132 -> V_140 ;
else
V_23 |= V_132 -> V_141 ;
}
F_19 ( & V_4 -> V_7 . V_31 -> V_32 ) ;
V_16 = F_75 ( & V_4 -> V_7 , false , false , false ) ;
F_21 ( & V_4 -> V_7 . V_31 -> V_32 ) ;
if ( V_16 ) {
F_33 ( V_13 , L_20 , V_16 ) ;
break;
}
F_76 ( V_4 , V_132 -> V_135 >> 2 , V_23 ) ;
}
F_63 ( V_130 ) ;
return V_16 ;
}
int
F_77 ( struct V_34 * V_35 , void * V_23 ,
struct V_10 * V_11 )
{
struct V_142 * V_143 = F_78 ( V_11 , V_35 ) ;
struct V_12 * V_13 = V_12 ( V_11 ) ;
struct V_144 * V_145 ;
struct V_42 * V_43 = V_42 ( V_35 ) ;
struct V_128 * V_69 = V_23 ;
struct V_146 * V_147 ;
struct V_97 * V_7 ;
struct V_95 * V_96 = NULL ;
struct V_90 V_91 ;
struct V_28 * V_29 = NULL ;
int V_101 , V_148 , V_16 = 0 , V_149 = 0 ;
if ( F_43 ( ! V_143 ) )
return - V_20 ;
F_58 (temp, &abi16->channels, head) {
if ( V_145 -> V_96 -> V_74 == ( V_150 | V_69 -> V_151 ) ) {
V_96 = V_145 -> V_96 ;
break;
}
}
if ( ! V_96 )
return F_79 ( V_143 , - V_107 ) ;
V_69 -> V_152 = V_43 -> V_2 . V_152 ;
V_69 -> V_153 = V_43 -> V_2 . V_153 ;
if ( F_43 ( V_69 -> V_154 == 0 ) )
goto V_155;
if ( F_43 ( V_69 -> V_154 > V_156 ) ) {
F_33 ( V_13 , L_21 ,
V_69 -> V_154 , V_156 ) ;
return F_79 ( V_143 , - V_61 ) ;
}
if ( F_43 ( V_69 -> V_99 > V_157 ) ) {
F_33 ( V_13 , L_22 ,
V_69 -> V_99 , V_157 ) ;
return F_79 ( V_143 , - V_61 ) ;
}
if ( F_43 ( V_69 -> V_131 > V_158 ) ) {
F_33 ( V_13 , L_23 ,
V_69 -> V_131 , V_158 ) ;
return F_79 ( V_143 , - V_61 ) ;
}
V_147 = F_66 ( V_69 -> V_147 , V_69 -> V_154 , sizeof( * V_147 ) ) ;
if ( F_72 ( V_147 ) )
return F_79 ( V_143 , F_73 ( V_147 ) ) ;
V_7 = F_66 ( V_69 -> V_159 , V_69 -> V_99 , sizeof( * V_7 ) ) ;
if ( F_72 ( V_7 ) ) {
F_63 ( V_147 ) ;
return F_79 ( V_143 , F_73 ( V_7 ) ) ;
}
for ( V_101 = 0 ; V_101 < V_69 -> V_154 ; V_101 ++ ) {
if ( V_147 [ V_101 ] . V_133 >= V_69 -> V_99 ) {
F_33 ( V_13 , L_24 , V_101 ) ;
V_16 = - V_61 ;
goto V_160;
}
}
V_16 = F_61 ( V_96 , V_11 , V_7 , V_69 -> V_159 ,
V_69 -> V_99 , & V_91 , & V_149 ) ;
if ( V_16 ) {
if ( V_16 != - V_109 )
F_33 ( V_13 , L_25 , V_16 ) ;
goto V_160;
}
if ( V_149 ) {
V_16 = F_71 ( V_13 , V_69 , V_7 ) ;
if ( V_16 ) {
F_33 ( V_13 , L_26 , V_16 ) ;
goto V_21;
}
}
if ( V_96 -> V_161 . V_162 ) {
V_16 = F_80 ( V_96 , V_69 -> V_154 + 1 , 16 ) ;
if ( V_16 ) {
F_33 ( V_13 , L_27 , V_16 ) ;
goto V_21;
}
for ( V_101 = 0 ; V_101 < V_69 -> V_154 ; V_101 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_147 [ V_101 ] . V_133 ] . V_110 ;
F_81 ( V_96 , V_4 , V_147 [ V_101 ] . V_60 ,
V_147 [ V_101 ] . V_163 ) ;
}
} else
if ( F_27 ( V_43 -> V_52 ) -> V_164 >= 0x25 ) {
V_16 = F_82 ( V_96 , V_69 -> V_154 * 2 ) ;
if ( V_16 ) {
F_33 ( V_13 , L_28 , V_16 ) ;
goto V_21;
}
for ( V_101 = 0 ; V_101 < V_69 -> V_154 ; V_101 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_147 [ V_101 ] . V_133 ] . V_110 ;
F_83 ( V_96 , ( V_4 -> V_7 . V_60 + V_147 [ V_101 ] . V_60 ) | 2 ) ;
F_83 ( V_96 , 0 ) ;
}
} else {
V_16 = F_82 ( V_96 , V_69 -> V_154 * ( 2 + V_165 ) ) ;
if ( V_16 ) {
F_33 ( V_13 , L_29 , V_16 ) ;
goto V_21;
}
for ( V_101 = 0 ; V_101 < V_69 -> V_154 ; V_101 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_147 [ V_101 ] . V_133 ] . V_110 ;
T_1 V_166 ;
V_166 = V_96 -> V_147 . V_15 . V_60 + ( ( V_96 -> V_161 . V_167 + 2 ) << 2 ) ;
V_166 |= 0x20000000 ;
if ( F_43 ( V_166 != V_69 -> V_168 ) ) {
if ( ! V_4 -> V_88 . V_136 ) {
V_16 = F_74 ( & V_4 -> V_7 , 0 ,
V_4 -> V_7 . V_25 .
V_62 ,
& V_4 -> V_88 ) ;
if ( V_16 ) {
F_84 ( V_96 ) ;
goto V_21;
}
V_4 -> V_87 = true ;
}
F_76 ( V_4 , ( V_147 [ V_101 ] . V_60 +
V_147 [ V_101 ] . V_163 - 8 ) / 4 , V_166 ) ;
}
F_83 ( V_96 , 0x20000000 |
( V_4 -> V_7 . V_60 + V_147 [ V_101 ] . V_60 ) ) ;
F_83 ( V_96 , 0 ) ;
for ( V_148 = 0 ; V_148 < V_165 ; V_148 ++ )
F_83 ( V_96 , 0 ) ;
}
}
V_16 = F_85 ( V_96 , false , & V_29 ) ;
if ( V_16 ) {
F_33 ( V_13 , L_30 , V_16 ) ;
F_84 ( V_96 ) ;
goto V_21;
}
V_21:
F_47 ( & V_91 , V_29 ) ;
F_23 ( & V_29 ) ;
V_160:
F_63 ( V_7 ) ;
F_63 ( V_147 ) ;
V_155:
if ( V_96 -> V_161 . V_162 ) {
V_69 -> V_168 = 0x00000000 ;
V_69 -> V_169 = 0x00000000 ;
} else
if ( F_27 ( V_43 -> V_52 ) -> V_164 >= 0x25 ) {
V_69 -> V_168 = 0x00020000 ;
V_69 -> V_169 = 0x00000000 ;
} else {
V_69 -> V_168 = 0x20000000 |
( V_96 -> V_147 . V_15 . V_60 + ( ( V_96 -> V_161 . V_167 + 2 ) << 2 ) ) ;
V_69 -> V_169 = 0x00000000 ;
}
return F_79 ( V_143 , V_16 ) ;
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
struct V_170 * V_69 = V_23 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
bool V_171 = ! ! ( V_69 -> V_44 & V_172 ) ;
int V_16 = - V_61 ;
V_2 = F_51 ( V_35 , V_11 , V_69 -> V_74 ) ;
if ( ! V_2 )
return - V_107 ;
V_4 = F_8 ( V_2 ) ;
F_19 ( & V_4 -> V_7 . V_31 -> V_32 ) ;
V_16 = F_75 ( & V_4 -> V_7 , true , true , V_171 ) ;
F_21 ( & V_4 -> V_7 . V_31 -> V_32 ) ;
F_36 ( V_2 ) ;
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
struct V_57 * V_69 = V_23 ;
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_51 ( V_35 , V_11 , V_69 -> V_74 ) ;
if ( ! V_2 )
return - V_107 ;
V_16 = F_30 ( V_11 , V_2 , V_69 ) ;
F_36 ( V_2 ) ;
return V_16 ;
}
