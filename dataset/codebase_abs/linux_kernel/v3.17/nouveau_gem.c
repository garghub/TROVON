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
struct V_27 * V_28 = NULL ;
F_17 ( & V_15 -> V_29 ) ;
if ( V_23 ) {
F_18 ( & V_4 -> V_6 . V_30 -> V_31 ) ;
V_28 = F_19 ( V_4 -> V_6 . V_32 ) ;
F_20 ( & V_4 -> V_6 . V_30 -> V_31 ) ;
}
if ( V_28 ) {
F_21 ( V_28 , F_13 , V_15 ) ;
} else {
if ( V_23 )
F_14 ( V_15 ) ;
F_15 ( V_15 ) ;
F_11 ( V_15 ) ;
}
F_22 ( & V_28 ) ;
}
void
F_23 ( struct V_1 * V_2 , struct V_10 * V_11 )
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
F_24 ( struct V_33 * V_34 , int V_35 , int V_36 , T_1 V_37 ,
T_1 V_38 , T_1 V_39 ,
struct V_3 * * V_40 )
{
struct V_41 * V_42 = V_41 ( V_34 ) ;
struct V_3 * V_4 ;
T_2 V_43 = 0 ;
int V_16 ;
if ( V_37 & V_44 )
V_43 |= V_45 ;
if ( V_37 & V_46 )
V_43 |= V_47 ;
if ( ! V_43 || V_37 & V_48 )
V_43 |= V_49 ;
V_16 = F_25 ( V_34 , V_35 , V_36 , V_43 , V_38 ,
V_39 , NULL , V_40 ) ;
if ( V_16 )
return V_16 ;
V_4 = * V_40 ;
V_4 -> V_50 = V_44 |
V_46 ;
if ( V_42 -> V_51 . V_52 . V_53 >= V_54 )
V_4 -> V_50 &= V_37 ;
V_16 = F_26 ( V_34 , & V_4 -> V_2 , V_4 -> V_6 . V_24 . V_35 ) ;
if ( V_16 ) {
F_27 ( NULL , V_40 ) ;
return - V_19 ;
}
V_4 -> V_6 . V_55 = V_4 -> V_2 . V_9 ;
return 0 ;
}
static int
F_28 ( struct V_10 * V_11 , struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_12 * V_13 = V_12 ( V_11 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_14 * V_15 ;
if ( V_4 -> V_6 . V_24 . V_25 == V_58 )
V_57 -> V_37 = V_46 ;
else
V_57 -> V_37 = V_44 ;
V_57 -> V_59 = V_4 -> V_6 . V_59 ;
if ( V_13 -> V_17 ) {
V_15 = F_8 ( V_4 , V_13 -> V_17 ) ;
if ( ! V_15 )
return - V_60 ;
V_57 -> V_59 = V_15 -> V_59 ;
}
V_57 -> V_35 = V_4 -> V_6 . V_24 . V_61 << V_62 ;
V_57 -> V_63 = F_29 ( & V_4 -> V_6 . V_64 ) ;
V_57 -> V_38 = V_4 -> V_38 ;
V_57 -> V_39 = V_4 -> V_39 ;
return 0 ;
}
int
F_30 ( struct V_33 * V_34 , void * V_22 ,
struct V_10 * V_11 )
{
struct V_41 * V_42 = V_41 ( V_34 ) ;
struct V_12 * V_13 = V_12 ( V_11 ) ;
struct V_65 * V_66 = F_31 ( & V_42 -> V_51 ) ;
struct V_67 * V_68 = V_22 ;
struct V_3 * V_4 = NULL ;
int V_16 = 0 ;
if ( ! V_66 -> V_69 ( V_66 , V_68 -> V_52 . V_39 ) ) {
F_32 ( error , V_13 , L_1 , V_68 -> V_52 . V_39 ) ;
return - V_60 ;
}
V_16 = F_24 ( V_34 , V_68 -> V_52 . V_35 , V_68 -> V_36 ,
V_68 -> V_52 . V_37 , V_68 -> V_52 . V_38 ,
V_68 -> V_52 . V_39 , & V_4 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_33 ( V_11 , & V_4 -> V_2 , & V_68 -> V_52 . V_70 ) ;
if ( V_16 == 0 ) {
V_16 = F_28 ( V_11 , & V_4 -> V_2 , & V_68 -> V_52 ) ;
if ( V_16 )
F_34 ( V_11 , V_68 -> V_52 . V_70 ) ;
}
F_35 ( & V_4 -> V_2 ) ;
return V_16 ;
}
static int
F_36 ( struct V_1 * V_2 , T_1 V_71 ,
T_1 V_72 , T_1 V_50 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_1 V_73 = V_50 & V_4 -> V_50 &
( V_72 ? V_72 : V_71 ) ;
T_1 V_74 = 0 , V_75 = 0 ;
if ( ! V_73 )
return - V_60 ;
if ( V_50 & V_44 )
V_75 |= V_45 ;
if ( V_50 & V_46 )
V_75 |= V_47 ;
if ( ( V_73 & V_44 ) &&
V_6 -> V_24 . V_25 == V_76 )
V_74 |= V_45 ;
else if ( ( V_73 & V_46 ) &&
V_6 -> V_24 . V_25 == V_58 )
V_74 |= V_47 ;
else if ( V_73 & V_44 )
V_74 |= V_45 ;
else
V_74 |= V_47 ;
F_37 ( V_4 , V_74 , V_75 ) ;
return 0 ;
}
static void
F_38 ( struct V_77 * V_78 , struct V_27 * V_28 ,
struct V_79 * V_80 )
{
struct V_77 * V_81 , * V_82 ;
struct V_3 * V_4 ;
F_39 (entry, tmp, list) {
V_4 = F_40 ( V_81 , struct V_3 , V_81 ) ;
if ( F_41 ( V_28 ) )
F_42 ( V_4 , V_28 ) ;
if ( F_43 ( V_4 -> V_83 ) ) {
F_44 ( & V_4 -> V_84 ) ;
V_4 -> V_83 = false ;
}
F_17 ( & V_4 -> V_81 ) ;
V_4 -> V_85 = NULL ;
F_45 ( & V_4 -> V_6 , V_80 ) ;
F_35 ( & V_4 -> V_2 ) ;
}
}
static void
F_46 ( struct V_86 * V_87 , struct V_27 * V_28 )
{
F_38 ( & V_87 -> V_88 , V_28 , & V_87 -> V_80 ) ;
F_38 ( & V_87 -> V_89 , V_28 , & V_87 -> V_80 ) ;
F_38 ( & V_87 -> V_90 , V_28 , & V_87 -> V_80 ) ;
}
static void
F_47 ( struct V_86 * V_87 , struct V_27 * V_28 )
{
F_46 ( V_87 , V_28 ) ;
F_48 ( & V_87 -> V_80 ) ;
}
static int
F_49 ( struct V_91 * V_92 , struct V_10 * V_11 ,
struct V_93 * V_94 ,
int V_95 , struct V_86 * V_87 )
{
struct V_12 * V_13 = V_12 ( V_11 ) ;
struct V_33 * V_34 = V_92 -> V_42 -> V_34 ;
int V_96 = 0 ;
int V_16 , V_97 ;
struct V_3 * V_98 = NULL ;
F_50 ( & V_87 -> V_80 , & V_99 ) ;
V_100:
if ( ++ V_96 > 100000 ) {
F_32 ( error , V_13 , L_2 , V_101 ) ;
return - V_60 ;
}
for ( V_97 = 0 ; V_97 < V_95 ; V_97 ++ ) {
struct V_93 * V_102 = & V_94 [ V_97 ] ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_51 ( V_34 , V_11 , V_102 -> V_70 ) ;
if ( ! V_2 ) {
F_32 ( error , V_13 , L_3 , V_102 -> V_70 ) ;
F_52 ( & V_87 -> V_80 ) ;
F_47 ( V_87 , NULL ) ;
return - V_103 ;
}
V_4 = F_2 ( V_2 ) ;
if ( V_4 == V_98 ) {
V_98 = NULL ;
F_35 ( V_2 ) ;
continue;
}
if ( V_4 -> V_85 && V_4 -> V_85 == V_11 ) {
F_32 ( error , V_13 , L_4
L_5 , V_102 -> V_70 ) ;
F_35 ( V_2 ) ;
F_52 ( & V_87 -> V_80 ) ;
F_47 ( V_87 , NULL ) ;
return - V_60 ;
}
V_16 = F_7 ( & V_4 -> V_6 , true , false , true , & V_87 -> V_80 ) ;
if ( V_16 ) {
F_46 ( V_87 , NULL ) ;
if ( F_43 ( V_16 == - V_104 ) ) {
V_16 = F_53 ( & V_4 -> V_6 , true ,
& V_87 -> V_80 ) ;
if ( ! V_16 )
V_98 = V_4 ;
}
if ( F_43 ( V_16 ) ) {
F_52 ( & V_87 -> V_80 ) ;
F_48 ( & V_87 -> V_80 ) ;
F_35 ( V_2 ) ;
if ( V_16 != - V_105 )
F_32 ( error , V_13 , L_6 ) ;
return V_16 ;
}
}
V_102 -> V_106 = ( V_107 ) ( unsigned long ) V_4 ;
V_4 -> V_85 = V_11 ;
V_4 -> V_108 = V_97 ;
if ( ( V_102 -> V_50 & V_44 ) &&
( V_102 -> V_50 & V_46 ) )
F_54 ( & V_4 -> V_81 , & V_87 -> V_90 ) ;
else
if ( V_102 -> V_50 & V_44 )
F_54 ( & V_4 -> V_81 , & V_87 -> V_88 ) ;
else
if ( V_102 -> V_50 & V_46 )
F_54 ( & V_4 -> V_81 , & V_87 -> V_89 ) ;
else {
F_32 ( error , V_13 , L_7 ,
V_102 -> V_50 ) ;
F_54 ( & V_4 -> V_81 , & V_87 -> V_90 ) ;
F_52 ( & V_87 -> V_80 ) ;
F_47 ( V_87 , NULL ) ;
return - V_60 ;
}
if ( V_4 == V_98 )
goto V_100;
}
F_52 ( & V_87 -> V_80 ) ;
return 0 ;
}
static int
F_55 ( struct V_91 * V_92 , struct V_3 * V_4 )
{
struct V_27 * V_28 = NULL ;
int V_16 = 0 ;
F_18 ( & V_4 -> V_6 . V_30 -> V_31 ) ;
V_28 = F_19 ( V_4 -> V_6 . V_32 ) ;
F_20 ( & V_4 -> V_6 . V_30 -> V_31 ) ;
if ( V_28 ) {
V_16 = F_56 ( V_28 , V_92 ) ;
F_22 ( & V_28 ) ;
}
return V_16 ;
}
static int
F_57 ( struct V_91 * V_92 , struct V_12 * V_13 ,
struct V_77 * V_78 , struct V_93 * V_94 ,
V_107 V_109 )
{
struct V_41 * V_42 = V_92 -> V_42 ;
struct V_93 T_3 * V_110 =
( void V_111 T_3 * ) ( V_112 ) V_109 ;
struct V_3 * V_4 ;
int V_16 , V_113 = 0 ;
F_58 (nvbo, list, entry) {
struct V_93 * V_102 = & V_94 [ V_4 -> V_108 ] ;
V_16 = F_36 ( & V_4 -> V_2 , V_102 -> V_71 ,
V_102 -> V_72 ,
V_102 -> V_50 ) ;
if ( F_43 ( V_16 ) ) {
F_32 ( error , V_13 , L_8 ) ;
return V_16 ;
}
V_16 = F_59 ( V_4 , true , false ) ;
if ( F_43 ( V_16 ) ) {
if ( V_16 != - V_105 )
F_32 ( error , V_13 , L_9 ) ;
return V_16 ;
}
V_16 = F_55 ( V_92 , V_4 ) ;
if ( F_43 ( V_16 ) ) {
F_32 ( error , V_13 , L_10 ) ;
return V_16 ;
}
if ( V_42 -> V_51 . V_52 . V_53 < V_54 ) {
if ( V_4 -> V_6 . V_59 == V_102 -> V_114 . V_59 &&
( ( V_4 -> V_6 . V_24 . V_25 == V_76 &&
V_102 -> V_114 . V_37 & V_44 ) ||
( V_4 -> V_6 . V_24 . V_25 == V_58 &&
V_102 -> V_114 . V_37 & V_46 ) ) )
continue;
if ( V_4 -> V_6 . V_24 . V_25 == V_58 )
V_102 -> V_114 . V_37 = V_46 ;
else
V_102 -> V_114 . V_37 = V_44 ;
V_102 -> V_114 . V_59 = V_4 -> V_6 . V_59 ;
V_102 -> V_114 . V_115 = 0 ;
V_113 ++ ;
if ( F_60 ( & V_110 [ V_4 -> V_108 ] . V_114 ,
& V_102 -> V_114 , sizeof( V_102 -> V_114 ) ) )
return - V_116 ;
}
}
return V_113 ;
}
static int
F_61 ( struct V_91 * V_92 ,
struct V_10 * V_11 ,
struct V_93 * V_94 ,
V_107 V_117 , int V_95 ,
struct V_86 * V_87 , int * V_118 )
{
struct V_12 * V_13 = V_12 ( V_11 ) ;
int V_16 , V_113 = 0 ;
F_62 ( & V_87 -> V_88 ) ;
F_62 ( & V_87 -> V_89 ) ;
F_62 ( & V_87 -> V_90 ) ;
if ( V_95 == 0 )
return 0 ;
V_16 = F_49 ( V_92 , V_11 , V_94 , V_95 , V_87 ) ;
if ( F_43 ( V_16 ) ) {
if ( V_16 != - V_105 )
F_32 ( error , V_13 , L_11 ) ;
return V_16 ;
}
V_16 = F_57 ( V_92 , V_13 , & V_87 -> V_88 , V_94 , V_117 ) ;
if ( F_43 ( V_16 < 0 ) ) {
if ( V_16 != - V_105 )
F_32 ( error , V_13 , L_12 ) ;
F_47 ( V_87 , NULL ) ;
return V_16 ;
}
V_113 += V_16 ;
V_16 = F_57 ( V_92 , V_13 , & V_87 -> V_89 , V_94 , V_117 ) ;
if ( F_43 ( V_16 < 0 ) ) {
if ( V_16 != - V_105 )
F_32 ( error , V_13 , L_13 ) ;
F_47 ( V_87 , NULL ) ;
return V_16 ;
}
V_113 += V_16 ;
V_16 = F_57 ( V_92 , V_13 , & V_87 -> V_90 , V_94 , V_117 ) ;
if ( F_43 ( V_16 < 0 ) ) {
if ( V_16 != - V_105 )
F_32 ( error , V_13 , L_14 ) ;
F_47 ( V_87 , NULL ) ;
return V_16 ;
}
V_113 += V_16 ;
* V_118 = V_113 ;
return 0 ;
}
static inline void
F_63 ( void * V_119 )
{
if ( ! F_64 ( V_119 ) )
F_11 ( V_119 ) ;
else
F_65 ( V_119 ) ;
}
static inline void *
F_66 ( V_107 V_120 , unsigned V_121 , unsigned V_35 )
{
void * V_24 ;
void T_3 * V_122 = ( void V_111 T_3 * ) ( V_112 ) V_120 ;
V_35 *= V_121 ;
V_24 = F_67 ( V_35 , V_18 | V_123 ) ;
if ( ! V_24 )
V_24 = F_68 ( V_35 ) ;
if ( ! V_24 )
return F_69 ( - V_19 ) ;
if ( F_70 ( V_24 , V_122 , V_35 ) ) {
F_63 ( V_24 ) ;
return F_69 ( - V_116 ) ;
}
return V_24 ;
}
static int
F_71 ( struct V_12 * V_13 ,
struct V_124 * V_68 ,
struct V_93 * V_6 )
{
struct V_125 * V_126 = NULL ;
int V_16 = 0 ;
unsigned V_97 ;
V_126 = F_66 ( V_68 -> V_113 , V_68 -> V_127 , sizeof( * V_126 ) ) ;
if ( F_72 ( V_126 ) )
return F_73 ( V_126 ) ;
for ( V_97 = 0 ; V_97 < V_68 -> V_127 ; V_97 ++ ) {
struct V_125 * V_128 = & V_126 [ V_97 ] ;
struct V_93 * V_102 ;
struct V_3 * V_4 ;
T_1 V_22 ;
if ( F_43 ( V_128 -> V_129 > V_68 -> V_95 ) ) {
F_32 ( error , V_13 , L_15 ) ;
V_16 = - V_60 ;
break;
}
V_102 = & V_6 [ V_128 -> V_129 ] ;
if ( V_102 -> V_114 . V_115 )
continue;
if ( F_43 ( V_128 -> V_130 > V_68 -> V_95 ) ) {
F_32 ( error , V_13 , L_16 ) ;
V_16 = - V_60 ;
break;
}
V_4 = ( void * ) ( unsigned long ) V_6 [ V_128 -> V_130 ] . V_106 ;
if ( F_43 ( V_128 -> V_131 + 4 >
V_4 -> V_6 . V_24 . V_61 << V_62 ) ) {
F_32 ( error , V_13 , L_17 ) ;
V_16 = - V_60 ;
break;
}
if ( ! V_4 -> V_84 . V_132 ) {
V_16 = F_74 ( & V_4 -> V_6 , 0 , V_4 -> V_6 . V_24 . V_61 ,
& V_4 -> V_84 ) ;
if ( V_16 ) {
F_32 ( error , V_13 , L_18 ) ;
break;
}
V_4 -> V_83 = true ;
}
if ( V_128 -> V_43 & V_133 )
V_22 = V_102 -> V_114 . V_59 + V_128 -> V_22 ;
else
if ( V_128 -> V_43 & V_134 )
V_22 = ( V_102 -> V_114 . V_59 + V_128 -> V_22 ) >> 32 ;
else
V_22 = V_128 -> V_22 ;
if ( V_128 -> V_43 & V_135 ) {
if ( V_102 -> V_114 . V_37 == V_46 )
V_22 |= V_128 -> V_136 ;
else
V_22 |= V_128 -> V_137 ;
}
F_18 ( & V_4 -> V_6 . V_30 -> V_31 ) ;
V_16 = F_75 ( & V_4 -> V_6 , false , false , false ) ;
F_20 ( & V_4 -> V_6 . V_30 -> V_31 ) ;
if ( V_16 ) {
F_32 ( error , V_13 , L_19 , V_16 ) ;
break;
}
F_76 ( V_4 , V_128 -> V_131 >> 2 , V_22 ) ;
}
F_63 ( V_126 ) ;
return V_16 ;
}
int
F_77 ( struct V_33 * V_34 , void * V_22 ,
struct V_10 * V_11 )
{
struct V_138 * V_139 = F_78 ( V_11 , V_34 ) ;
struct V_12 * V_13 = V_12 ( V_11 ) ;
struct V_140 * V_141 ;
struct V_41 * V_42 = V_41 ( V_34 ) ;
struct V_124 * V_68 = V_22 ;
struct V_142 * V_143 ;
struct V_93 * V_6 ;
struct V_91 * V_92 = NULL ;
struct V_86 V_87 ;
struct V_27 * V_28 = NULL ;
int V_97 , V_144 , V_16 = 0 , V_145 = 0 ;
if ( F_43 ( ! V_139 ) )
return - V_19 ;
F_58 (temp, &abi16->channels, head) {
if ( V_141 -> V_92 -> V_146 -> V_70 == ( V_147 | V_68 -> V_148 ) ) {
V_92 = V_141 -> V_92 ;
break;
}
}
if ( ! V_92 )
return F_79 ( V_139 , - V_103 ) ;
V_68 -> V_149 = V_42 -> V_2 . V_149 ;
V_68 -> V_150 = V_42 -> V_2 . V_150 ;
if ( F_43 ( V_68 -> V_151 == 0 ) )
goto V_152;
if ( F_43 ( V_68 -> V_151 > V_153 ) ) {
F_32 ( error , V_13 , L_20 ,
V_68 -> V_151 , V_153 ) ;
return F_79 ( V_139 , - V_60 ) ;
}
if ( F_43 ( V_68 -> V_95 > V_154 ) ) {
F_32 ( error , V_13 , L_21 ,
V_68 -> V_95 , V_154 ) ;
return F_79 ( V_139 , - V_60 ) ;
}
if ( F_43 ( V_68 -> V_127 > V_155 ) ) {
F_32 ( error , V_13 , L_22 ,
V_68 -> V_127 , V_155 ) ;
return F_79 ( V_139 , - V_60 ) ;
}
V_143 = F_66 ( V_68 -> V_143 , V_68 -> V_151 , sizeof( * V_143 ) ) ;
if ( F_72 ( V_143 ) )
return F_79 ( V_139 , F_73 ( V_143 ) ) ;
V_6 = F_66 ( V_68 -> V_156 , V_68 -> V_95 , sizeof( * V_6 ) ) ;
if ( F_72 ( V_6 ) ) {
F_63 ( V_143 ) ;
return F_79 ( V_139 , F_73 ( V_6 ) ) ;
}
for ( V_97 = 0 ; V_97 < V_68 -> V_151 ; V_97 ++ ) {
if ( V_143 [ V_97 ] . V_129 >= V_68 -> V_95 ) {
F_32 ( error , V_13 , L_23 , V_97 ) ;
V_16 = - V_60 ;
goto V_157;
}
}
V_16 = F_61 ( V_92 , V_11 , V_6 , V_68 -> V_156 ,
V_68 -> V_95 , & V_87 , & V_145 ) ;
if ( V_16 ) {
if ( V_16 != - V_105 )
F_32 ( error , V_13 , L_24 , V_16 ) ;
goto V_157;
}
if ( V_145 ) {
V_16 = F_71 ( V_13 , V_68 , V_6 ) ;
if ( V_16 ) {
F_32 ( error , V_13 , L_25 , V_16 ) ;
goto V_20;
}
}
if ( V_92 -> V_158 . V_159 ) {
V_16 = F_80 ( V_92 , V_68 -> V_151 + 1 , 16 ) ;
if ( V_16 ) {
F_32 ( error , V_13 , L_26 , V_16 ) ;
goto V_20;
}
for ( V_97 = 0 ; V_97 < V_68 -> V_151 ; V_97 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_6 [ V_143 [ V_97 ] . V_129 ] . V_106 ;
F_81 ( V_92 , V_4 , V_143 [ V_97 ] . V_59 ,
V_143 [ V_97 ] . V_160 ) ;
}
} else
if ( V_42 -> V_51 . V_52 . V_161 >= 0x25 ) {
V_16 = F_82 ( V_92 , V_68 -> V_151 * 2 ) ;
if ( V_16 ) {
F_32 ( error , V_13 , L_27 , V_16 ) ;
goto V_20;
}
for ( V_97 = 0 ; V_97 < V_68 -> V_151 ; V_97 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_6 [ V_143 [ V_97 ] . V_129 ] . V_106 ;
F_83 ( V_92 , ( V_4 -> V_6 . V_59 + V_143 [ V_97 ] . V_59 ) | 2 ) ;
F_83 ( V_92 , 0 ) ;
}
} else {
V_16 = F_82 ( V_92 , V_68 -> V_151 * ( 2 + V_162 ) ) ;
if ( V_16 ) {
F_32 ( error , V_13 , L_28 , V_16 ) ;
goto V_20;
}
for ( V_97 = 0 ; V_97 < V_68 -> V_151 ; V_97 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_6 [ V_143 [ V_97 ] . V_129 ] . V_106 ;
T_1 V_163 ;
V_163 = V_92 -> V_143 . V_15 . V_59 + ( ( V_92 -> V_158 . V_164 + 2 ) << 2 ) ;
V_163 |= 0x20000000 ;
if ( F_43 ( V_163 != V_68 -> V_165 ) ) {
if ( ! V_4 -> V_84 . V_132 ) {
V_16 = F_74 ( & V_4 -> V_6 , 0 ,
V_4 -> V_6 . V_24 .
V_61 ,
& V_4 -> V_84 ) ;
if ( V_16 ) {
F_84 ( V_92 ) ;
goto V_20;
}
V_4 -> V_83 = true ;
}
F_76 ( V_4 , ( V_143 [ V_97 ] . V_59 +
V_143 [ V_97 ] . V_160 - 8 ) / 4 , V_163 ) ;
}
F_83 ( V_92 , 0x20000000 |
( V_4 -> V_6 . V_59 + V_143 [ V_97 ] . V_59 ) ) ;
F_83 ( V_92 , 0 ) ;
for ( V_144 = 0 ; V_144 < V_162 ; V_144 ++ )
F_83 ( V_92 , 0 ) ;
}
}
V_16 = F_85 ( V_92 , false , & V_28 ) ;
if ( V_16 ) {
F_32 ( error , V_13 , L_29 , V_16 ) ;
F_84 ( V_92 ) ;
goto V_20;
}
V_20:
F_47 ( & V_87 , V_28 ) ;
F_22 ( & V_28 ) ;
V_157:
F_63 ( V_6 ) ;
F_63 ( V_143 ) ;
V_152:
if ( V_92 -> V_158 . V_159 ) {
V_68 -> V_165 = 0x00000000 ;
V_68 -> V_166 = 0x00000000 ;
} else
if ( V_42 -> V_51 . V_52 . V_161 >= 0x25 ) {
V_68 -> V_165 = 0x00020000 ;
V_68 -> V_166 = 0x00000000 ;
} else {
V_68 -> V_165 = 0x20000000 |
( V_92 -> V_143 . V_15 . V_59 + ( ( V_92 -> V_158 . V_164 + 2 ) << 2 ) ) ;
V_68 -> V_166 = 0x00000000 ;
}
return F_79 ( V_139 , V_16 ) ;
}
static inline T_1
F_86 ( struct V_3 * V_4 , T_1 V_37 )
{
T_1 V_43 = 0 ;
if ( V_37 & V_44 )
V_43 |= V_45 ;
if ( V_37 & V_46 )
V_43 |= V_47 ;
return V_43 ;
}
int
F_87 ( struct V_33 * V_34 , void * V_22 ,
struct V_10 * V_11 )
{
struct V_167 * V_68 = V_22 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
bool V_168 = ! ! ( V_68 -> V_43 & V_169 ) ;
int V_16 = - V_60 ;
V_2 = F_51 ( V_34 , V_11 , V_68 -> V_70 ) ;
if ( ! V_2 )
return - V_103 ;
V_4 = F_2 ( V_2 ) ;
F_18 ( & V_4 -> V_6 . V_30 -> V_31 ) ;
V_16 = F_75 ( & V_4 -> V_6 , true , true , V_168 ) ;
F_20 ( & V_4 -> V_6 . V_30 -> V_31 ) ;
F_35 ( V_2 ) ;
return V_16 ;
}
int
F_88 ( struct V_33 * V_34 , void * V_22 ,
struct V_10 * V_11 )
{
return 0 ;
}
int
F_89 ( struct V_33 * V_34 , void * V_22 ,
struct V_10 * V_11 )
{
struct V_56 * V_68 = V_22 ;
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_51 ( V_34 , V_11 , V_68 -> V_70 ) ;
if ( ! V_2 )
return - V_103 ;
V_16 = F_28 ( V_11 , V_2 , V_68 ) ;
F_35 ( V_2 ) ;
return V_16 ;
}
