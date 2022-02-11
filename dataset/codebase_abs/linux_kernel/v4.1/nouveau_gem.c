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
if ( V_44 & V_55 )
V_48 |= V_56 ;
V_12 = F_31 ( V_11 , V_42 , V_43 , V_48 , V_45 ,
V_46 , NULL , NULL , V_47 ) ;
if ( V_12 )
return V_12 ;
V_4 = * V_47 ;
V_4 -> V_57 = V_49 |
V_51 ;
if ( V_6 -> V_10 . V_58 . V_59 >= V_60 )
V_4 -> V_57 &= V_44 ;
V_12 = F_32 ( V_11 , & V_4 -> V_2 , V_4 -> V_7 . V_30 . V_42 ) ;
if ( V_12 ) {
F_33 ( NULL , V_47 ) ;
return - V_25 ;
}
V_4 -> V_7 . V_61 = V_4 -> V_2 . V_16 ;
return 0 ;
}
static int
F_34 ( struct V_17 * V_18 , struct V_1 * V_2 ,
struct V_62 * V_63 )
{
struct V_19 * V_20 = V_19 ( V_18 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_21 * V_22 ;
if ( V_4 -> V_7 . V_30 . V_31 == V_64 )
V_63 -> V_44 = V_51 ;
else
V_63 -> V_44 = V_49 ;
V_63 -> V_65 = V_4 -> V_7 . V_65 ;
if ( V_20 -> V_23 ) {
V_22 = F_13 ( V_4 , V_20 -> V_23 ) ;
if ( ! V_22 )
return - V_66 ;
V_63 -> V_65 = V_22 -> V_65 ;
}
V_63 -> V_42 = V_4 -> V_7 . V_30 . V_67 << V_68 ;
V_63 -> V_69 = F_35 ( & V_4 -> V_7 . V_70 ) ;
V_63 -> V_45 = V_4 -> V_45 ;
V_63 -> V_46 = V_4 -> V_46 ;
return 0 ;
}
int
F_36 ( struct V_41 * V_11 , void * V_28 ,
struct V_17 * V_18 )
{
struct V_5 * V_6 = V_5 ( V_11 ) ;
struct V_19 * V_20 = V_19 ( V_18 ) ;
struct V_71 * V_72 = F_37 ( & V_6 -> V_10 ) ;
struct V_73 * V_74 = V_28 ;
struct V_3 * V_4 = NULL ;
int V_12 = 0 ;
if ( ! V_72 -> V_75 ( V_72 , V_74 -> V_58 . V_46 ) ) {
F_38 ( error , V_20 , L_1 , V_74 -> V_58 . V_46 ) ;
return - V_66 ;
}
V_12 = F_30 ( V_11 , V_74 -> V_58 . V_42 , V_74 -> V_43 ,
V_74 -> V_58 . V_44 , V_74 -> V_58 . V_45 ,
V_74 -> V_58 . V_46 , & V_4 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_39 ( V_18 , & V_4 -> V_2 , & V_74 -> V_58 . V_76 ) ;
if ( V_12 == 0 ) {
V_12 = F_34 ( V_18 , & V_4 -> V_2 , & V_74 -> V_58 ) ;
if ( V_12 )
F_40 ( V_18 , V_74 -> V_58 . V_76 ) ;
}
F_41 ( & V_4 -> V_2 ) ;
return V_12 ;
}
static int
F_42 ( struct V_1 * V_2 , T_1 V_77 ,
T_1 V_78 , T_1 V_57 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_7 = & V_4 -> V_7 ;
T_1 V_79 = V_57 & V_4 -> V_57 &
( V_78 ? V_78 : V_77 ) ;
T_1 V_80 = 0 , V_81 = 0 ;
if ( ! V_79 )
return - V_66 ;
if ( V_57 & V_49 )
V_81 |= V_50 ;
if ( V_57 & V_51 )
V_81 |= V_52 ;
if ( ( V_79 & V_49 ) &&
V_7 -> V_30 . V_31 == V_82 )
V_80 |= V_50 ;
else if ( ( V_79 & V_51 ) &&
V_7 -> V_30 . V_31 == V_64 )
V_80 |= V_52 ;
else if ( V_79 & V_49 )
V_80 |= V_50 ;
else
V_80 |= V_52 ;
F_43 ( V_4 , V_80 , V_81 ) ;
return 0 ;
}
static void
F_44 ( struct V_83 * V_84 , struct V_85 * V_37 ,
struct V_86 * V_87 )
{
struct V_3 * V_4 ;
struct V_86 * V_88 ;
while ( ! F_45 ( & V_84 -> V_89 ) ) {
V_4 = F_46 ( V_84 -> V_89 . V_90 , struct V_3 , V_91 ) ;
V_88 = & V_87 [ V_4 -> V_92 ] ;
if ( F_47 ( V_37 ) )
F_48 ( V_4 , V_37 , ! ! V_88 -> V_78 ) ;
if ( F_49 ( V_4 -> V_93 ) ) {
F_50 ( & V_4 -> V_94 ) ;
V_4 -> V_93 = false ;
}
F_23 ( & V_4 -> V_91 ) ;
V_4 -> V_95 = NULL ;
F_51 ( & V_4 -> V_7 , & V_84 -> V_96 ) ;
F_41 ( & V_4 -> V_2 ) ;
}
}
static void
F_52 ( struct V_83 * V_84 , struct V_85 * V_37 ,
struct V_86 * V_87 )
{
F_44 ( V_84 , V_37 , V_87 ) ;
F_53 ( & V_84 -> V_96 ) ;
}
static int
F_54 ( struct V_97 * V_98 , struct V_17 * V_18 ,
struct V_86 * V_87 ,
int V_99 , struct V_83 * V_84 )
{
struct V_19 * V_20 = V_19 ( V_18 ) ;
struct V_41 * V_11 = V_98 -> V_6 -> V_11 ;
int V_100 = 0 ;
int V_12 , V_101 ;
struct V_3 * V_102 = NULL ;
F_55 ( V_103 ) ;
F_55 ( V_104 ) ;
F_55 ( V_105 ) ;
F_56 ( & V_84 -> V_96 , & V_106 ) ;
V_107:
if ( ++ V_100 > 100000 ) {
F_38 ( error , V_20 , L_2 , V_108 ) ;
return - V_66 ;
}
for ( V_101 = 0 ; V_101 < V_99 ; V_101 ++ ) {
struct V_86 * V_88 = & V_87 [ V_101 ] ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_57 ( V_11 , V_18 , V_88 -> V_76 ) ;
if ( ! V_2 ) {
F_38 ( error , V_20 , L_3 , V_88 -> V_76 ) ;
V_12 = - V_109 ;
break;
}
V_4 = F_2 ( V_2 ) ;
if ( V_4 == V_102 ) {
V_102 = NULL ;
F_41 ( V_2 ) ;
continue;
}
if ( V_4 -> V_95 && V_4 -> V_95 == V_18 ) {
F_38 ( error , V_20 , L_4
L_5 , V_88 -> V_76 ) ;
F_41 ( V_2 ) ;
V_12 = - V_66 ;
break;
}
V_12 = F_12 ( & V_4 -> V_7 , true , false , true , & V_84 -> V_96 ) ;
if ( V_12 ) {
F_58 ( & V_104 , & V_84 -> V_89 ) ;
F_58 ( & V_103 , & V_84 -> V_89 ) ;
F_58 ( & V_105 , & V_84 -> V_89 ) ;
F_44 ( V_84 , NULL , NULL ) ;
if ( F_49 ( V_12 == - V_110 ) ) {
V_12 = F_59 ( & V_4 -> V_7 , true ,
& V_84 -> V_96 ) ;
if ( ! V_12 )
V_102 = V_4 ;
}
if ( F_49 ( V_12 ) ) {
if ( V_12 != - V_111 )
F_38 ( error , V_20 , L_6 ) ;
break;
}
}
V_88 -> V_112 = ( V_113 ) ( unsigned long ) V_4 ;
V_4 -> V_95 = V_18 ;
V_4 -> V_92 = V_101 ;
if ( ( V_88 -> V_57 & V_49 ) &&
( V_88 -> V_57 & V_51 ) )
F_60 ( & V_4 -> V_91 , & V_105 ) ;
else
if ( V_88 -> V_57 & V_49 )
F_60 ( & V_4 -> V_91 , & V_104 ) ;
else
if ( V_88 -> V_57 & V_51 )
F_60 ( & V_4 -> V_91 , & V_103 ) ;
else {
F_38 ( error , V_20 , L_7 ,
V_88 -> V_57 ) ;
F_60 ( & V_4 -> V_91 , & V_105 ) ;
V_12 = - V_66 ;
break;
}
if ( V_4 == V_102 )
goto V_107;
}
F_61 ( & V_84 -> V_96 ) ;
F_62 ( & V_104 , & V_84 -> V_89 ) ;
F_62 ( & V_103 , & V_84 -> V_89 ) ;
F_62 ( & V_105 , & V_84 -> V_89 ) ;
if ( V_12 )
F_52 ( V_84 , NULL , NULL ) ;
return V_12 ;
}
static int
F_63 ( struct V_97 * V_98 , struct V_19 * V_20 ,
struct V_114 * V_89 , struct V_86 * V_87 ,
V_113 V_115 )
{
struct V_5 * V_6 = V_98 -> V_6 ;
struct V_86 T_3 * V_116 =
( void V_117 T_3 * ) ( V_118 ) V_115 ;
struct V_3 * V_4 ;
int V_12 , V_119 = 0 ;
F_64 (nvbo, list, entry) {
struct V_86 * V_88 = & V_87 [ V_4 -> V_92 ] ;
V_12 = F_42 ( & V_4 -> V_2 , V_88 -> V_77 ,
V_88 -> V_78 ,
V_88 -> V_57 ) ;
if ( F_49 ( V_12 ) ) {
F_38 ( error , V_20 , L_8 ) ;
return V_12 ;
}
V_12 = F_65 ( V_4 , true , false ) ;
if ( F_49 ( V_12 ) ) {
if ( V_12 != - V_111 )
F_38 ( error , V_20 , L_9 ) ;
return V_12 ;
}
V_12 = F_66 ( V_4 , V_98 , ! ! V_88 -> V_78 , true ) ;
if ( F_49 ( V_12 ) ) {
if ( V_12 != - V_111 )
F_38 ( error , V_20 , L_10 ) ;
return V_12 ;
}
if ( V_6 -> V_10 . V_58 . V_59 < V_60 ) {
if ( V_4 -> V_7 . V_65 == V_88 -> V_120 . V_65 &&
( ( V_4 -> V_7 . V_30 . V_31 == V_82 &&
V_88 -> V_120 . V_44 & V_49 ) ||
( V_4 -> V_7 . V_30 . V_31 == V_64 &&
V_88 -> V_120 . V_44 & V_51 ) ) )
continue;
if ( V_4 -> V_7 . V_30 . V_31 == V_64 )
V_88 -> V_120 . V_44 = V_51 ;
else
V_88 -> V_120 . V_44 = V_49 ;
V_88 -> V_120 . V_65 = V_4 -> V_7 . V_65 ;
V_88 -> V_120 . V_121 = 0 ;
V_119 ++ ;
if ( F_67 ( & V_116 [ V_4 -> V_92 ] . V_120 ,
& V_88 -> V_120 , sizeof( V_88 -> V_120 ) ) )
return - V_122 ;
}
}
return V_119 ;
}
static int
F_68 ( struct V_97 * V_98 ,
struct V_17 * V_18 ,
struct V_86 * V_87 ,
V_113 V_123 , int V_99 ,
struct V_83 * V_84 , int * V_124 )
{
struct V_19 * V_20 = V_19 ( V_18 ) ;
int V_12 ;
F_69 ( & V_84 -> V_89 ) ;
if ( V_99 == 0 )
return 0 ;
V_12 = F_54 ( V_98 , V_18 , V_87 , V_99 , V_84 ) ;
if ( F_49 ( V_12 ) ) {
if ( V_12 != - V_111 )
F_38 ( error , V_20 , L_11 ) ;
return V_12 ;
}
V_12 = F_63 ( V_98 , V_20 , & V_84 -> V_89 , V_87 , V_123 ) ;
if ( F_49 ( V_12 < 0 ) ) {
if ( V_12 != - V_111 )
F_38 ( error , V_20 , L_12 ) ;
F_52 ( V_84 , NULL , NULL ) ;
return V_12 ;
}
* V_124 = V_12 ;
return 0 ;
}
static inline void
F_70 ( void * V_125 )
{
if ( ! F_71 ( V_125 ) )
F_16 ( V_125 ) ;
else
F_72 ( V_125 ) ;
}
static inline void *
F_73 ( V_113 V_126 , unsigned V_127 , unsigned V_42 )
{
void * V_30 ;
void T_3 * V_128 = ( void V_117 T_3 * ) ( V_118 ) V_126 ;
V_42 *= V_127 ;
V_30 = F_74 ( V_42 , V_24 | V_129 ) ;
if ( ! V_30 )
V_30 = F_75 ( V_42 ) ;
if ( ! V_30 )
return F_76 ( - V_25 ) ;
if ( F_77 ( V_30 , V_128 , V_42 ) ) {
F_70 ( V_30 ) ;
return F_76 ( - V_122 ) ;
}
return V_30 ;
}
static int
F_78 ( struct V_19 * V_20 ,
struct V_130 * V_74 ,
struct V_86 * V_7 )
{
struct V_131 * V_132 = NULL ;
int V_12 = 0 ;
unsigned V_101 ;
V_132 = F_73 ( V_74 -> V_119 , V_74 -> V_133 , sizeof( * V_132 ) ) ;
if ( F_79 ( V_132 ) )
return F_80 ( V_132 ) ;
for ( V_101 = 0 ; V_101 < V_74 -> V_133 ; V_101 ++ ) {
struct V_131 * V_134 = & V_132 [ V_101 ] ;
struct V_86 * V_88 ;
struct V_3 * V_4 ;
T_1 V_28 ;
if ( F_49 ( V_134 -> V_135 > V_74 -> V_99 ) ) {
F_38 ( error , V_20 , L_13 ) ;
V_12 = - V_66 ;
break;
}
V_88 = & V_7 [ V_134 -> V_135 ] ;
if ( V_88 -> V_120 . V_121 )
continue;
if ( F_49 ( V_134 -> V_136 > V_74 -> V_99 ) ) {
F_38 ( error , V_20 , L_14 ) ;
V_12 = - V_66 ;
break;
}
V_4 = ( void * ) ( unsigned long ) V_7 [ V_134 -> V_136 ] . V_112 ;
if ( F_49 ( V_134 -> V_137 + 4 >
V_4 -> V_7 . V_30 . V_67 << V_68 ) ) {
F_38 ( error , V_20 , L_15 ) ;
V_12 = - V_66 ;
break;
}
if ( ! V_4 -> V_94 . V_138 ) {
V_12 = F_81 ( & V_4 -> V_7 , 0 , V_4 -> V_7 . V_30 . V_67 ,
& V_4 -> V_94 ) ;
if ( V_12 ) {
F_38 ( error , V_20 , L_16 ) ;
break;
}
V_4 -> V_93 = true ;
}
if ( V_134 -> V_48 & V_139 )
V_28 = V_88 -> V_120 . V_65 + V_134 -> V_28 ;
else
if ( V_134 -> V_48 & V_140 )
V_28 = ( V_88 -> V_120 . V_65 + V_134 -> V_28 ) >> 32 ;
else
V_28 = V_134 -> V_28 ;
if ( V_134 -> V_48 & V_141 ) {
if ( V_88 -> V_120 . V_44 == V_51 )
V_28 |= V_134 -> V_142 ;
else
V_28 |= V_134 -> V_143 ;
}
V_12 = F_24 ( & V_4 -> V_7 , true , false , false ) ;
if ( V_12 ) {
F_38 ( error , V_20 , L_17 , V_12 ) ;
break;
}
F_82 ( V_4 , V_134 -> V_137 >> 2 , V_28 ) ;
}
F_70 ( V_132 ) ;
return V_12 ;
}
int
F_83 ( struct V_41 * V_11 , void * V_28 ,
struct V_17 * V_18 )
{
struct V_144 * V_145 = F_84 ( V_18 , V_11 ) ;
struct V_19 * V_20 = V_19 ( V_18 ) ;
struct V_146 * V_147 ;
struct V_5 * V_6 = V_5 ( V_11 ) ;
struct V_130 * V_74 = V_28 ;
struct V_148 * V_149 ;
struct V_86 * V_7 ;
struct V_97 * V_98 = NULL ;
struct V_83 V_84 ;
struct V_85 * V_37 = NULL ;
int V_101 , V_150 , V_12 = 0 , V_151 = 0 ;
if ( F_49 ( ! V_145 ) )
return - V_25 ;
F_64 (temp, &abi16->channels, head) {
if ( V_147 -> V_98 -> V_152 -> V_76 == ( V_153 | V_74 -> V_154 ) ) {
V_98 = V_147 -> V_98 ;
break;
}
}
if ( ! V_98 )
return F_85 ( V_145 , - V_109 ) ;
V_74 -> V_155 = V_6 -> V_2 . V_155 ;
V_74 -> V_156 = V_6 -> V_2 . V_156 ;
if ( F_49 ( V_74 -> V_157 == 0 ) )
goto V_158;
if ( F_49 ( V_74 -> V_157 > V_159 ) ) {
F_38 ( error , V_20 , L_18 ,
V_74 -> V_157 , V_159 ) ;
return F_85 ( V_145 , - V_66 ) ;
}
if ( F_49 ( V_74 -> V_99 > V_160 ) ) {
F_38 ( error , V_20 , L_19 ,
V_74 -> V_99 , V_160 ) ;
return F_85 ( V_145 , - V_66 ) ;
}
if ( F_49 ( V_74 -> V_133 > V_161 ) ) {
F_38 ( error , V_20 , L_20 ,
V_74 -> V_133 , V_161 ) ;
return F_85 ( V_145 , - V_66 ) ;
}
V_149 = F_73 ( V_74 -> V_149 , V_74 -> V_157 , sizeof( * V_149 ) ) ;
if ( F_79 ( V_149 ) )
return F_85 ( V_145 , F_80 ( V_149 ) ) ;
V_7 = F_73 ( V_74 -> V_162 , V_74 -> V_99 , sizeof( * V_7 ) ) ;
if ( F_79 ( V_7 ) ) {
F_70 ( V_149 ) ;
return F_85 ( V_145 , F_80 ( V_7 ) ) ;
}
for ( V_101 = 0 ; V_101 < V_74 -> V_157 ; V_101 ++ ) {
if ( V_149 [ V_101 ] . V_135 >= V_74 -> V_99 ) {
F_38 ( error , V_20 , L_21 , V_101 ) ;
V_12 = - V_66 ;
goto V_163;
}
}
V_12 = F_68 ( V_98 , V_18 , V_7 , V_74 -> V_162 ,
V_74 -> V_99 , & V_84 , & V_151 ) ;
if ( V_12 ) {
if ( V_12 != - V_111 )
F_38 ( error , V_20 , L_22 , V_12 ) ;
goto V_163;
}
if ( V_151 ) {
V_12 = F_78 ( V_20 , V_74 , V_7 ) ;
if ( V_12 ) {
F_38 ( error , V_20 , L_23 , V_12 ) ;
goto V_26;
}
}
if ( V_98 -> V_164 . V_165 ) {
V_12 = F_86 ( V_98 , V_74 -> V_157 + 1 , 16 ) ;
if ( V_12 ) {
F_38 ( error , V_20 , L_24 , V_12 ) ;
goto V_26;
}
for ( V_101 = 0 ; V_101 < V_74 -> V_157 ; V_101 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_149 [ V_101 ] . V_135 ] . V_112 ;
F_87 ( V_98 , V_4 , V_149 [ V_101 ] . V_65 ,
V_149 [ V_101 ] . V_166 ) ;
}
} else
if ( V_6 -> V_10 . V_58 . V_167 >= 0x25 ) {
V_12 = F_88 ( V_98 , V_74 -> V_157 * 2 ) ;
if ( V_12 ) {
F_38 ( error , V_20 , L_25 , V_12 ) ;
goto V_26;
}
for ( V_101 = 0 ; V_101 < V_74 -> V_157 ; V_101 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_149 [ V_101 ] . V_135 ] . V_112 ;
F_89 ( V_98 , ( V_4 -> V_7 . V_65 + V_149 [ V_101 ] . V_65 ) | 2 ) ;
F_89 ( V_98 , 0 ) ;
}
} else {
V_12 = F_88 ( V_98 , V_74 -> V_157 * ( 2 + V_168 ) ) ;
if ( V_12 ) {
F_38 ( error , V_20 , L_26 , V_12 ) ;
goto V_26;
}
for ( V_101 = 0 ; V_101 < V_74 -> V_157 ; V_101 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_149 [ V_101 ] . V_135 ] . V_112 ;
T_1 V_169 ;
V_169 = V_98 -> V_149 . V_22 . V_65 + ( ( V_98 -> V_164 . V_170 + 2 ) << 2 ) ;
V_169 |= 0x20000000 ;
if ( F_49 ( V_169 != V_74 -> V_171 ) ) {
if ( ! V_4 -> V_94 . V_138 ) {
V_12 = F_81 ( & V_4 -> V_7 , 0 ,
V_4 -> V_7 . V_30 .
V_67 ,
& V_4 -> V_94 ) ;
if ( V_12 ) {
F_90 ( V_98 ) ;
goto V_26;
}
V_4 -> V_93 = true ;
}
F_82 ( V_4 , ( V_149 [ V_101 ] . V_65 +
V_149 [ V_101 ] . V_166 - 8 ) / 4 , V_169 ) ;
}
F_89 ( V_98 , 0x20000000 |
( V_4 -> V_7 . V_65 + V_149 [ V_101 ] . V_65 ) ) ;
F_89 ( V_98 , 0 ) ;
for ( V_150 = 0 ; V_150 < V_168 ; V_150 ++ )
F_89 ( V_98 , 0 ) ;
}
}
V_12 = F_91 ( V_98 , false , & V_37 ) ;
if ( V_12 ) {
F_38 ( error , V_20 , L_27 , V_12 ) ;
F_90 ( V_98 ) ;
goto V_26;
}
V_26:
F_52 ( & V_84 , V_37 , V_7 ) ;
F_92 ( & V_37 ) ;
V_163:
F_70 ( V_7 ) ;
F_70 ( V_149 ) ;
V_158:
if ( V_98 -> V_164 . V_165 ) {
V_74 -> V_171 = 0x00000000 ;
V_74 -> V_172 = 0x00000000 ;
} else
if ( V_6 -> V_10 . V_58 . V_167 >= 0x25 ) {
V_74 -> V_171 = 0x00020000 ;
V_74 -> V_172 = 0x00000000 ;
} else {
V_74 -> V_171 = 0x20000000 |
( V_98 -> V_149 . V_22 . V_65 + ( ( V_98 -> V_164 . V_170 + 2 ) << 2 ) ) ;
V_74 -> V_172 = 0x00000000 ;
}
return F_85 ( V_145 , V_12 ) ;
}
int
F_93 ( struct V_41 * V_11 , void * V_28 ,
struct V_17 * V_18 )
{
struct V_173 * V_74 = V_28 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
bool V_174 = ! ! ( V_74 -> V_48 & V_175 ) ;
bool V_176 = ! ! ( V_74 -> V_48 & V_177 ) ;
int V_12 ;
V_2 = F_57 ( V_11 , V_18 , V_74 -> V_76 ) ;
if ( ! V_2 )
return - V_109 ;
V_4 = F_2 ( V_2 ) ;
if ( V_174 )
V_12 = F_94 ( V_4 -> V_7 . V_34 , V_176 ) ? 0 : - V_178 ;
else {
long V_179 ;
V_179 = F_95 ( V_4 -> V_7 . V_34 , V_176 , true , 30 * V_180 ) ;
if ( ! V_179 )
V_12 = - V_178 ;
else if ( V_179 > 0 )
V_12 = 0 ;
else
V_12 = V_179 ;
}
F_96 ( V_4 ) ;
F_41 ( V_2 ) ;
return V_12 ;
}
int
F_97 ( struct V_41 * V_11 , void * V_28 ,
struct V_17 * V_18 )
{
struct V_181 * V_74 = V_28 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_57 ( V_11 , V_18 , V_74 -> V_76 ) ;
if ( ! V_2 )
return - V_109 ;
V_4 = F_2 ( V_2 ) ;
F_98 ( V_4 ) ;
F_41 ( V_2 ) ;
return 0 ;
}
int
F_99 ( struct V_41 * V_11 , void * V_28 ,
struct V_17 * V_18 )
{
struct V_62 * V_74 = V_28 ;
struct V_1 * V_2 ;
int V_12 ;
V_2 = F_57 ( V_11 , V_18 , V_74 -> V_76 ) ;
if ( ! V_2 )
return - V_109 ;
V_12 = F_34 ( V_18 , V_2 , V_74 ) ;
F_41 ( V_2 ) ;
return V_12 ;
}
