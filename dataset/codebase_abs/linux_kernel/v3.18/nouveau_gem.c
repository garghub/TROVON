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
if ( ! V_13 -> V_17 )
return 0 ;
V_16 = F_7 ( & V_4 -> V_6 , false , false , false , NULL ) ;
if ( V_16 )
return V_16 ;
V_15 = F_8 ( V_4 , V_13 -> V_17 ) ;
if ( ! V_15 ) {
V_15 = F_9 ( sizeof( * V_15 ) , V_18 ) ;
if ( ! V_15 ) {
V_16 = - V_19 ;
goto V_20;
}
V_16 = F_10 ( V_4 , V_13 -> V_17 , V_15 ) ;
if ( V_16 ) {
F_11 ( V_15 ) ;
goto V_20;
}
} else {
V_15 -> V_21 ++ ;
}
V_20:
F_12 ( & V_4 -> V_6 ) ;
return V_16 ;
}
static void
F_13 ( void * V_22 )
{
struct V_14 * V_15 = V_22 ;
F_14 ( V_15 ) ;
F_15 ( V_15 ) ;
F_11 ( V_15 ) ;
}
static void
F_16 ( struct V_3 * V_4 , struct V_14 * V_15 )
{
const bool V_23 = V_4 -> V_6 . V_24 . V_25 != V_26 ;
struct V_27 * V_28 = V_4 -> V_6 . V_28 ;
struct V_29 * V_30 ;
struct V_31 * V_31 = NULL ;
V_30 = F_17 ( V_28 ) ;
F_18 ( & V_15 -> V_32 ) ;
if ( V_30 && V_30 -> V_33 > 1 )
F_19 ( & V_4 -> V_6 , true , false , false ) ;
else if ( V_30 && V_30 -> V_33 == 1 )
V_31 = F_20 ( V_30 -> V_34 [ 0 ] ,
F_21 ( V_28 ) ) ;
else
V_31 = F_22 ( V_4 -> V_6 . V_28 ) ;
if ( V_31 && V_23 ) {
F_23 ( V_31 , F_13 , V_15 ) ;
} else {
if ( V_23 )
F_14 ( V_15 ) ;
F_15 ( V_15 ) ;
F_11 ( V_15 ) ;
}
}
void
F_24 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_12 * V_13 = V_12 ( V_11 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_14 * V_15 ;
int V_16 ;
if ( ! V_13 -> V_17 )
return;
V_16 = F_7 ( & V_4 -> V_6 , false , false , false , NULL ) ;
if ( V_16 )
return;
V_15 = F_8 ( V_4 , V_13 -> V_17 ) ;
if ( V_15 ) {
if ( -- V_15 -> V_21 == 0 )
F_16 ( V_4 , V_15 ) ;
}
F_12 ( & V_4 -> V_6 ) ;
}
int
F_25 ( struct V_35 * V_36 , int V_37 , int V_38 , T_1 V_39 ,
T_1 V_40 , T_1 V_41 ,
struct V_3 * * V_42 )
{
struct V_43 * V_44 = V_43 ( V_36 ) ;
struct V_3 * V_4 ;
T_2 V_45 = 0 ;
int V_16 ;
if ( V_39 & V_46 )
V_45 |= V_47 ;
if ( V_39 & V_48 )
V_45 |= V_49 ;
if ( ! V_45 || V_39 & V_50 )
V_45 |= V_51 ;
V_16 = F_26 ( V_36 , V_37 , V_38 , V_45 , V_40 ,
V_41 , NULL , NULL , V_42 ) ;
if ( V_16 )
return V_16 ;
V_4 = * V_42 ;
V_4 -> V_52 = V_46 |
V_48 ;
if ( V_44 -> V_53 . V_54 . V_55 >= V_56 )
V_4 -> V_52 &= V_39 ;
V_16 = F_27 ( V_36 , & V_4 -> V_2 , V_4 -> V_6 . V_24 . V_37 ) ;
if ( V_16 ) {
F_28 ( NULL , V_42 ) ;
return - V_19 ;
}
V_4 -> V_6 . V_57 = V_4 -> V_2 . V_9 ;
return 0 ;
}
static int
F_29 ( struct V_10 * V_11 , struct V_1 * V_2 ,
struct V_58 * V_59 )
{
struct V_12 * V_13 = V_12 ( V_11 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_14 * V_15 ;
if ( V_4 -> V_6 . V_24 . V_25 == V_60 )
V_59 -> V_39 = V_48 ;
else
V_59 -> V_39 = V_46 ;
V_59 -> V_61 = V_4 -> V_6 . V_61 ;
if ( V_13 -> V_17 ) {
V_15 = F_8 ( V_4 , V_13 -> V_17 ) ;
if ( ! V_15 )
return - V_62 ;
V_59 -> V_61 = V_15 -> V_61 ;
}
V_59 -> V_37 = V_4 -> V_6 . V_24 . V_63 << V_64 ;
V_59 -> V_65 = F_30 ( & V_4 -> V_6 . V_66 ) ;
V_59 -> V_40 = V_4 -> V_40 ;
V_59 -> V_41 = V_4 -> V_41 ;
return 0 ;
}
int
F_31 ( struct V_35 * V_36 , void * V_22 ,
struct V_10 * V_11 )
{
struct V_43 * V_44 = V_43 ( V_36 ) ;
struct V_12 * V_13 = V_12 ( V_11 ) ;
struct V_67 * V_68 = F_32 ( & V_44 -> V_53 ) ;
struct V_69 * V_70 = V_22 ;
struct V_3 * V_4 = NULL ;
int V_16 = 0 ;
if ( ! V_68 -> V_71 ( V_68 , V_70 -> V_54 . V_41 ) ) {
F_33 ( error , V_13 , L_1 , V_70 -> V_54 . V_41 ) ;
return - V_62 ;
}
V_16 = F_25 ( V_36 , V_70 -> V_54 . V_37 , V_70 -> V_38 ,
V_70 -> V_54 . V_39 , V_70 -> V_54 . V_40 ,
V_70 -> V_54 . V_41 , & V_4 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_34 ( V_11 , & V_4 -> V_2 , & V_70 -> V_54 . V_72 ) ;
if ( V_16 == 0 ) {
V_16 = F_29 ( V_11 , & V_4 -> V_2 , & V_70 -> V_54 ) ;
if ( V_16 )
F_35 ( V_11 , V_70 -> V_54 . V_72 ) ;
}
F_36 ( & V_4 -> V_2 ) ;
return V_16 ;
}
static int
F_37 ( struct V_1 * V_2 , T_1 V_73 ,
T_1 V_74 , T_1 V_52 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_1 V_75 = V_52 & V_4 -> V_52 &
( V_74 ? V_74 : V_73 ) ;
T_1 V_76 = 0 , V_77 = 0 ;
if ( ! V_75 )
return - V_62 ;
if ( V_52 & V_46 )
V_77 |= V_47 ;
if ( V_52 & V_48 )
V_77 |= V_49 ;
if ( ( V_75 & V_46 ) &&
V_6 -> V_24 . V_25 == V_78 )
V_76 |= V_47 ;
else if ( ( V_75 & V_48 ) &&
V_6 -> V_24 . V_25 == V_60 )
V_76 |= V_49 ;
else if ( V_75 & V_46 )
V_76 |= V_47 ;
else
V_76 |= V_49 ;
F_38 ( V_4 , V_76 , V_77 ) ;
return 0 ;
}
static void
F_39 ( struct V_79 * V_80 , struct V_81 * V_31 ,
struct V_82 * V_83 )
{
struct V_3 * V_4 ;
struct V_82 * V_84 ;
while ( ! F_40 ( & V_80 -> V_85 ) ) {
V_4 = F_41 ( V_80 -> V_85 . V_86 , struct V_3 , V_87 ) ;
V_84 = & V_83 [ V_4 -> V_88 ] ;
if ( F_42 ( V_31 ) )
F_43 ( V_4 , V_31 , ! ! V_84 -> V_74 ) ;
if ( F_44 ( V_4 -> V_89 ) ) {
F_45 ( & V_4 -> V_90 ) ;
V_4 -> V_89 = false ;
}
F_18 ( & V_4 -> V_87 ) ;
V_4 -> V_91 = NULL ;
F_46 ( & V_4 -> V_6 , & V_80 -> V_92 ) ;
F_36 ( & V_4 -> V_2 ) ;
}
}
static void
F_47 ( struct V_79 * V_80 , struct V_81 * V_31 ,
struct V_82 * V_83 )
{
F_39 ( V_80 , V_31 , V_83 ) ;
F_48 ( & V_80 -> V_92 ) ;
}
static int
F_49 ( struct V_93 * V_94 , struct V_10 * V_11 ,
struct V_82 * V_83 ,
int V_95 , struct V_79 * V_80 )
{
struct V_12 * V_13 = V_12 ( V_11 ) ;
struct V_35 * V_36 = V_94 -> V_44 -> V_36 ;
int V_96 = 0 ;
int V_16 , V_97 ;
struct V_3 * V_98 = NULL ;
F_50 ( V_99 ) ;
F_50 ( V_100 ) ;
F_50 ( V_101 ) ;
F_51 ( & V_80 -> V_92 , & V_102 ) ;
V_103:
if ( ++ V_96 > 100000 ) {
F_33 ( error , V_13 , L_2 , V_104 ) ;
return - V_62 ;
}
for ( V_97 = 0 ; V_97 < V_95 ; V_97 ++ ) {
struct V_82 * V_84 = & V_83 [ V_97 ] ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_52 ( V_36 , V_11 , V_84 -> V_72 ) ;
if ( ! V_2 ) {
F_33 ( error , V_13 , L_3 , V_84 -> V_72 ) ;
V_16 = - V_105 ;
break;
}
V_4 = F_2 ( V_2 ) ;
if ( V_4 == V_98 ) {
V_98 = NULL ;
F_36 ( V_2 ) ;
continue;
}
if ( V_4 -> V_91 && V_4 -> V_91 == V_11 ) {
F_33 ( error , V_13 , L_4
L_5 , V_84 -> V_72 ) ;
F_36 ( V_2 ) ;
V_16 = - V_62 ;
break;
}
V_16 = F_7 ( & V_4 -> V_6 , true , false , true , & V_80 -> V_92 ) ;
if ( V_16 ) {
F_53 ( & V_100 , & V_80 -> V_85 ) ;
F_53 ( & V_99 , & V_80 -> V_85 ) ;
F_53 ( & V_101 , & V_80 -> V_85 ) ;
F_39 ( V_80 , NULL , NULL ) ;
if ( F_44 ( V_16 == - V_106 ) ) {
V_16 = F_54 ( & V_4 -> V_6 , true ,
& V_80 -> V_92 ) ;
if ( ! V_16 )
V_98 = V_4 ;
}
if ( F_44 ( V_16 ) ) {
if ( V_16 != - V_107 )
F_33 ( error , V_13 , L_6 ) ;
break;
}
}
V_84 -> V_108 = ( V_109 ) ( unsigned long ) V_4 ;
V_4 -> V_91 = V_11 ;
V_4 -> V_88 = V_97 ;
if ( ( V_84 -> V_52 & V_46 ) &&
( V_84 -> V_52 & V_48 ) )
F_55 ( & V_4 -> V_87 , & V_101 ) ;
else
if ( V_84 -> V_52 & V_46 )
F_55 ( & V_4 -> V_87 , & V_100 ) ;
else
if ( V_84 -> V_52 & V_48 )
F_55 ( & V_4 -> V_87 , & V_99 ) ;
else {
F_33 ( error , V_13 , L_7 ,
V_84 -> V_52 ) ;
F_55 ( & V_4 -> V_87 , & V_101 ) ;
V_16 = - V_62 ;
break;
}
if ( V_4 == V_98 )
goto V_103;
}
F_56 ( & V_80 -> V_92 ) ;
F_57 ( & V_100 , & V_80 -> V_85 ) ;
F_57 ( & V_99 , & V_80 -> V_85 ) ;
F_57 ( & V_101 , & V_80 -> V_85 ) ;
if ( V_16 )
F_47 ( V_80 , NULL , NULL ) ;
return V_16 ;
}
static int
F_58 ( struct V_93 * V_94 , struct V_12 * V_13 ,
struct V_110 * V_85 , struct V_82 * V_83 ,
V_109 V_111 )
{
struct V_43 * V_44 = V_94 -> V_44 ;
struct V_82 T_3 * V_112 =
( void V_113 T_3 * ) ( V_114 ) V_111 ;
struct V_3 * V_4 ;
int V_16 , V_115 = 0 ;
F_59 (nvbo, list, entry) {
struct V_82 * V_84 = & V_83 [ V_4 -> V_88 ] ;
V_16 = F_37 ( & V_4 -> V_2 , V_84 -> V_73 ,
V_84 -> V_74 ,
V_84 -> V_52 ) ;
if ( F_44 ( V_16 ) ) {
F_33 ( error , V_13 , L_8 ) ;
return V_16 ;
}
V_16 = F_60 ( V_4 , true , false ) ;
if ( F_44 ( V_16 ) ) {
if ( V_16 != - V_107 )
F_33 ( error , V_13 , L_9 ) ;
return V_16 ;
}
V_16 = F_61 ( V_4 , V_94 , ! ! V_84 -> V_74 , true ) ;
if ( F_44 ( V_16 ) ) {
if ( V_16 != - V_107 )
F_33 ( error , V_13 , L_10 ) ;
return V_16 ;
}
if ( V_44 -> V_53 . V_54 . V_55 < V_56 ) {
if ( V_4 -> V_6 . V_61 == V_84 -> V_116 . V_61 &&
( ( V_4 -> V_6 . V_24 . V_25 == V_78 &&
V_84 -> V_116 . V_39 & V_46 ) ||
( V_4 -> V_6 . V_24 . V_25 == V_60 &&
V_84 -> V_116 . V_39 & V_48 ) ) )
continue;
if ( V_4 -> V_6 . V_24 . V_25 == V_60 )
V_84 -> V_116 . V_39 = V_48 ;
else
V_84 -> V_116 . V_39 = V_46 ;
V_84 -> V_116 . V_61 = V_4 -> V_6 . V_61 ;
V_84 -> V_116 . V_117 = 0 ;
V_115 ++ ;
if ( F_62 ( & V_112 [ V_4 -> V_88 ] . V_116 ,
& V_84 -> V_116 , sizeof( V_84 -> V_116 ) ) )
return - V_118 ;
}
}
return V_115 ;
}
static int
F_63 ( struct V_93 * V_94 ,
struct V_10 * V_11 ,
struct V_82 * V_83 ,
V_109 V_119 , int V_95 ,
struct V_79 * V_80 , int * V_120 )
{
struct V_12 * V_13 = V_12 ( V_11 ) ;
int V_16 ;
F_64 ( & V_80 -> V_85 ) ;
if ( V_95 == 0 )
return 0 ;
V_16 = F_49 ( V_94 , V_11 , V_83 , V_95 , V_80 ) ;
if ( F_44 ( V_16 ) ) {
if ( V_16 != - V_107 )
F_33 ( error , V_13 , L_11 ) ;
return V_16 ;
}
V_16 = F_58 ( V_94 , V_13 , & V_80 -> V_85 , V_83 , V_119 ) ;
if ( F_44 ( V_16 < 0 ) ) {
if ( V_16 != - V_107 )
F_33 ( error , V_13 , L_12 ) ;
F_47 ( V_80 , NULL , NULL ) ;
return V_16 ;
}
* V_120 = V_16 ;
return 0 ;
}
static inline void
F_65 ( void * V_121 )
{
if ( ! F_66 ( V_121 ) )
F_11 ( V_121 ) ;
else
F_67 ( V_121 ) ;
}
static inline void *
F_68 ( V_109 V_122 , unsigned V_123 , unsigned V_37 )
{
void * V_24 ;
void T_3 * V_124 = ( void V_113 T_3 * ) ( V_114 ) V_122 ;
V_37 *= V_123 ;
V_24 = F_69 ( V_37 , V_18 | V_125 ) ;
if ( ! V_24 )
V_24 = F_70 ( V_37 ) ;
if ( ! V_24 )
return F_71 ( - V_19 ) ;
if ( F_72 ( V_24 , V_124 , V_37 ) ) {
F_65 ( V_24 ) ;
return F_71 ( - V_118 ) ;
}
return V_24 ;
}
static int
F_73 ( struct V_12 * V_13 ,
struct V_126 * V_70 ,
struct V_82 * V_6 )
{
struct V_127 * V_128 = NULL ;
int V_16 = 0 ;
unsigned V_97 ;
V_128 = F_68 ( V_70 -> V_115 , V_70 -> V_129 , sizeof( * V_128 ) ) ;
if ( F_74 ( V_128 ) )
return F_75 ( V_128 ) ;
for ( V_97 = 0 ; V_97 < V_70 -> V_129 ; V_97 ++ ) {
struct V_127 * V_130 = & V_128 [ V_97 ] ;
struct V_82 * V_84 ;
struct V_3 * V_4 ;
T_1 V_22 ;
if ( F_44 ( V_130 -> V_131 > V_70 -> V_95 ) ) {
F_33 ( error , V_13 , L_13 ) ;
V_16 = - V_62 ;
break;
}
V_84 = & V_6 [ V_130 -> V_131 ] ;
if ( V_84 -> V_116 . V_117 )
continue;
if ( F_44 ( V_130 -> V_132 > V_70 -> V_95 ) ) {
F_33 ( error , V_13 , L_14 ) ;
V_16 = - V_62 ;
break;
}
V_4 = ( void * ) ( unsigned long ) V_6 [ V_130 -> V_132 ] . V_108 ;
if ( F_44 ( V_130 -> V_133 + 4 >
V_4 -> V_6 . V_24 . V_63 << V_64 ) ) {
F_33 ( error , V_13 , L_15 ) ;
V_16 = - V_62 ;
break;
}
if ( ! V_4 -> V_90 . V_134 ) {
V_16 = F_76 ( & V_4 -> V_6 , 0 , V_4 -> V_6 . V_24 . V_63 ,
& V_4 -> V_90 ) ;
if ( V_16 ) {
F_33 ( error , V_13 , L_16 ) ;
break;
}
V_4 -> V_89 = true ;
}
if ( V_130 -> V_45 & V_135 )
V_22 = V_84 -> V_116 . V_61 + V_130 -> V_22 ;
else
if ( V_130 -> V_45 & V_136 )
V_22 = ( V_84 -> V_116 . V_61 + V_130 -> V_22 ) >> 32 ;
else
V_22 = V_130 -> V_22 ;
if ( V_130 -> V_45 & V_137 ) {
if ( V_84 -> V_116 . V_39 == V_48 )
V_22 |= V_130 -> V_138 ;
else
V_22 |= V_130 -> V_139 ;
}
V_16 = F_19 ( & V_4 -> V_6 , true , false , false ) ;
if ( V_16 ) {
F_33 ( error , V_13 , L_17 , V_16 ) ;
break;
}
F_77 ( V_4 , V_130 -> V_133 >> 2 , V_22 ) ;
}
F_65 ( V_128 ) ;
return V_16 ;
}
int
F_78 ( struct V_35 * V_36 , void * V_22 ,
struct V_10 * V_11 )
{
struct V_140 * V_141 = F_79 ( V_11 , V_36 ) ;
struct V_12 * V_13 = V_12 ( V_11 ) ;
struct V_142 * V_143 ;
struct V_43 * V_44 = V_43 ( V_36 ) ;
struct V_126 * V_70 = V_22 ;
struct V_144 * V_145 ;
struct V_82 * V_6 ;
struct V_93 * V_94 = NULL ;
struct V_79 V_80 ;
struct V_81 * V_31 = NULL ;
int V_97 , V_146 , V_16 = 0 , V_147 = 0 ;
if ( F_44 ( ! V_141 ) )
return - V_19 ;
F_59 (temp, &abi16->channels, head) {
if ( V_143 -> V_94 -> V_148 -> V_72 == ( V_149 | V_70 -> V_150 ) ) {
V_94 = V_143 -> V_94 ;
break;
}
}
if ( ! V_94 )
return F_80 ( V_141 , - V_105 ) ;
V_70 -> V_151 = V_44 -> V_2 . V_151 ;
V_70 -> V_152 = V_44 -> V_2 . V_152 ;
if ( F_44 ( V_70 -> V_153 == 0 ) )
goto V_154;
if ( F_44 ( V_70 -> V_153 > V_155 ) ) {
F_33 ( error , V_13 , L_18 ,
V_70 -> V_153 , V_155 ) ;
return F_80 ( V_141 , - V_62 ) ;
}
if ( F_44 ( V_70 -> V_95 > V_156 ) ) {
F_33 ( error , V_13 , L_19 ,
V_70 -> V_95 , V_156 ) ;
return F_80 ( V_141 , - V_62 ) ;
}
if ( F_44 ( V_70 -> V_129 > V_157 ) ) {
F_33 ( error , V_13 , L_20 ,
V_70 -> V_129 , V_157 ) ;
return F_80 ( V_141 , - V_62 ) ;
}
V_145 = F_68 ( V_70 -> V_145 , V_70 -> V_153 , sizeof( * V_145 ) ) ;
if ( F_74 ( V_145 ) )
return F_80 ( V_141 , F_75 ( V_145 ) ) ;
V_6 = F_68 ( V_70 -> V_158 , V_70 -> V_95 , sizeof( * V_6 ) ) ;
if ( F_74 ( V_6 ) ) {
F_65 ( V_145 ) ;
return F_80 ( V_141 , F_75 ( V_6 ) ) ;
}
for ( V_97 = 0 ; V_97 < V_70 -> V_153 ; V_97 ++ ) {
if ( V_145 [ V_97 ] . V_131 >= V_70 -> V_95 ) {
F_33 ( error , V_13 , L_21 , V_97 ) ;
V_16 = - V_62 ;
goto V_159;
}
}
V_16 = F_63 ( V_94 , V_11 , V_6 , V_70 -> V_158 ,
V_70 -> V_95 , & V_80 , & V_147 ) ;
if ( V_16 ) {
if ( V_16 != - V_107 )
F_33 ( error , V_13 , L_22 , V_16 ) ;
goto V_159;
}
if ( V_147 ) {
V_16 = F_73 ( V_13 , V_70 , V_6 ) ;
if ( V_16 ) {
F_33 ( error , V_13 , L_23 , V_16 ) ;
goto V_20;
}
}
if ( V_94 -> V_160 . V_161 ) {
V_16 = F_81 ( V_94 , V_70 -> V_153 + 1 , 16 ) ;
if ( V_16 ) {
F_33 ( error , V_13 , L_24 , V_16 ) ;
goto V_20;
}
for ( V_97 = 0 ; V_97 < V_70 -> V_153 ; V_97 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_6 [ V_145 [ V_97 ] . V_131 ] . V_108 ;
F_82 ( V_94 , V_4 , V_145 [ V_97 ] . V_61 ,
V_145 [ V_97 ] . V_162 ) ;
}
} else
if ( V_44 -> V_53 . V_54 . V_163 >= 0x25 ) {
V_16 = F_83 ( V_94 , V_70 -> V_153 * 2 ) ;
if ( V_16 ) {
F_33 ( error , V_13 , L_25 , V_16 ) ;
goto V_20;
}
for ( V_97 = 0 ; V_97 < V_70 -> V_153 ; V_97 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_6 [ V_145 [ V_97 ] . V_131 ] . V_108 ;
F_84 ( V_94 , ( V_4 -> V_6 . V_61 + V_145 [ V_97 ] . V_61 ) | 2 ) ;
F_84 ( V_94 , 0 ) ;
}
} else {
V_16 = F_83 ( V_94 , V_70 -> V_153 * ( 2 + V_164 ) ) ;
if ( V_16 ) {
F_33 ( error , V_13 , L_26 , V_16 ) ;
goto V_20;
}
for ( V_97 = 0 ; V_97 < V_70 -> V_153 ; V_97 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_6 [ V_145 [ V_97 ] . V_131 ] . V_108 ;
T_1 V_165 ;
V_165 = V_94 -> V_145 . V_15 . V_61 + ( ( V_94 -> V_160 . V_166 + 2 ) << 2 ) ;
V_165 |= 0x20000000 ;
if ( F_44 ( V_165 != V_70 -> V_167 ) ) {
if ( ! V_4 -> V_90 . V_134 ) {
V_16 = F_76 ( & V_4 -> V_6 , 0 ,
V_4 -> V_6 . V_24 .
V_63 ,
& V_4 -> V_90 ) ;
if ( V_16 ) {
F_85 ( V_94 ) ;
goto V_20;
}
V_4 -> V_89 = true ;
}
F_77 ( V_4 , ( V_145 [ V_97 ] . V_61 +
V_145 [ V_97 ] . V_162 - 8 ) / 4 , V_165 ) ;
}
F_84 ( V_94 , 0x20000000 |
( V_4 -> V_6 . V_61 + V_145 [ V_97 ] . V_61 ) ) ;
F_84 ( V_94 , 0 ) ;
for ( V_146 = 0 ; V_146 < V_164 ; V_146 ++ )
F_84 ( V_94 , 0 ) ;
}
}
V_16 = F_86 ( V_94 , false , & V_31 ) ;
if ( V_16 ) {
F_33 ( error , V_13 , L_27 , V_16 ) ;
F_85 ( V_94 ) ;
goto V_20;
}
V_20:
F_47 ( & V_80 , V_31 , V_6 ) ;
F_87 ( & V_31 ) ;
V_159:
F_65 ( V_6 ) ;
F_65 ( V_145 ) ;
V_154:
if ( V_94 -> V_160 . V_161 ) {
V_70 -> V_167 = 0x00000000 ;
V_70 -> V_168 = 0x00000000 ;
} else
if ( V_44 -> V_53 . V_54 . V_163 >= 0x25 ) {
V_70 -> V_167 = 0x00020000 ;
V_70 -> V_168 = 0x00000000 ;
} else {
V_70 -> V_167 = 0x20000000 |
( V_94 -> V_145 . V_15 . V_61 + ( ( V_94 -> V_160 . V_166 + 2 ) << 2 ) ) ;
V_70 -> V_168 = 0x00000000 ;
}
return F_80 ( V_141 , V_16 ) ;
}
static inline T_1
F_88 ( struct V_3 * V_4 , T_1 V_39 )
{
T_1 V_45 = 0 ;
if ( V_39 & V_46 )
V_45 |= V_47 ;
if ( V_39 & V_48 )
V_45 |= V_49 ;
return V_45 ;
}
int
F_89 ( struct V_35 * V_36 , void * V_22 ,
struct V_10 * V_11 )
{
struct V_169 * V_70 = V_22 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
bool V_170 = ! ! ( V_70 -> V_45 & V_171 ) ;
bool V_172 = ! ! ( V_70 -> V_45 & V_173 ) ;
int V_16 ;
V_2 = F_52 ( V_36 , V_11 , V_70 -> V_72 ) ;
if ( ! V_2 )
return - V_105 ;
V_4 = F_2 ( V_2 ) ;
if ( V_170 )
V_16 = F_90 ( V_4 -> V_6 . V_28 , V_172 ) ? 0 : - V_174 ;
else {
long V_175 ;
V_175 = F_91 ( V_4 -> V_6 . V_28 , V_172 , true , 30 * V_176 ) ;
if ( ! V_175 )
V_16 = - V_174 ;
else if ( V_175 > 0 )
V_16 = 0 ;
else
V_16 = V_175 ;
}
F_36 ( V_2 ) ;
return V_16 ;
}
int
F_92 ( struct V_35 * V_36 , void * V_22 ,
struct V_10 * V_11 )
{
return 0 ;
}
int
F_93 ( struct V_35 * V_36 , void * V_22 ,
struct V_10 * V_11 )
{
struct V_58 * V_70 = V_22 ;
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_52 ( V_36 , V_11 , V_70 -> V_72 ) ;
if ( ! V_2 )
return - V_105 ;
V_16 = F_29 ( V_11 , V_2 , V_70 ) ;
F_36 ( V_2 ) ;
return V_16 ;
}
