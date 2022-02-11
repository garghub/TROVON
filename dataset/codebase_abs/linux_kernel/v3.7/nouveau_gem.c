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
if ( V_2 -> V_9 )
F_5 ( V_2 , V_4 -> V_7 . V_10 ) ;
F_6 ( & V_7 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
}
int
F_9 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_13 * V_14 = V_13 ( V_12 ) ;
struct V_3 * V_4 = F_10 ( V_2 ) ;
struct V_15 * V_16 ;
int V_17 ;
if ( ! V_14 -> V_18 . V_19 )
return 0 ;
V_17 = F_11 ( & V_4 -> V_7 , false , false , false , 0 ) ;
if ( V_17 )
return V_17 ;
V_16 = F_12 ( V_4 , V_14 -> V_18 . V_19 ) ;
if ( ! V_16 ) {
V_16 = F_13 ( sizeof( * V_16 ) , V_20 ) ;
if ( ! V_16 ) {
V_17 = - V_21 ;
goto V_22;
}
V_17 = F_14 ( V_4 , V_14 -> V_18 . V_19 , V_16 ) ;
if ( V_17 ) {
F_8 ( V_16 ) ;
goto V_22;
}
} else {
V_16 -> V_23 ++ ;
}
V_22:
F_15 ( & V_4 -> V_7 ) ;
return V_17 ;
}
void
F_16 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_13 * V_14 = V_13 ( V_12 ) ;
struct V_3 * V_4 = F_10 ( V_2 ) ;
struct V_15 * V_16 ;
int V_17 ;
if ( ! V_14 -> V_18 . V_19 )
return;
V_17 = F_11 ( & V_4 -> V_7 , false , false , false , 0 ) ;
if ( V_17 )
return;
V_16 = F_12 ( V_4 , V_14 -> V_18 . V_19 ) ;
if ( V_16 ) {
if ( -- V_16 -> V_23 == 0 ) {
F_17 ( V_4 , V_16 ) ;
F_8 ( V_16 ) ;
}
}
F_15 ( & V_4 -> V_7 ) ;
}
int
F_18 ( struct V_24 * V_25 , int V_26 , int V_27 , T_1 V_28 ,
T_1 V_29 , T_1 V_30 ,
struct V_3 * * V_31 )
{
struct V_32 * V_33 = V_32 ( V_25 ) ;
struct V_3 * V_4 ;
T_2 V_34 = 0 ;
int V_17 ;
if ( V_28 & V_35 )
V_34 |= V_36 ;
if ( V_28 & V_37 )
V_34 |= V_38 ;
if ( ! V_34 || V_28 & V_39 )
V_34 |= V_40 ;
V_17 = F_19 ( V_25 , V_26 , V_27 , V_34 , V_29 ,
V_30 , NULL , V_31 ) ;
if ( V_17 )
return V_17 ;
V_4 = * V_31 ;
V_4 -> V_41 = V_35 |
V_37 ;
if ( F_20 ( V_33 -> V_42 ) -> V_43 >= V_44 )
V_4 -> V_41 &= V_28 ;
V_4 -> V_2 = F_21 ( V_25 , V_4 -> V_7 . V_45 . V_26 ) ;
if ( ! V_4 -> V_2 ) {
F_22 ( NULL , V_31 ) ;
return - V_21 ;
}
V_4 -> V_7 . V_46 = V_4 -> V_2 -> V_47 ;
V_4 -> V_2 -> V_5 = V_4 ;
return 0 ;
}
static int
F_23 ( struct V_11 * V_12 , struct V_1 * V_2 ,
struct V_48 * V_49 )
{
struct V_13 * V_14 = V_13 ( V_12 ) ;
struct V_3 * V_4 = F_10 ( V_2 ) ;
struct V_15 * V_16 ;
if ( V_4 -> V_7 . V_45 . V_50 == V_51 )
V_49 -> V_28 = V_37 ;
else
V_49 -> V_28 = V_35 ;
V_49 -> V_52 = V_4 -> V_7 . V_52 ;
if ( V_14 -> V_18 . V_19 ) {
V_16 = F_12 ( V_4 , V_14 -> V_18 . V_19 ) ;
if ( ! V_16 )
return - V_53 ;
V_49 -> V_52 = V_16 -> V_52 ;
}
V_49 -> V_26 = V_4 -> V_7 . V_45 . V_54 << V_55 ;
V_49 -> V_56 = V_4 -> V_7 . V_57 ;
V_49 -> V_29 = V_4 -> V_29 ;
V_49 -> V_30 = V_4 -> V_30 ;
return 0 ;
}
int
F_24 ( struct V_24 * V_25 , void * V_58 ,
struct V_11 * V_12 )
{
struct V_32 * V_33 = V_32 ( V_25 ) ;
struct V_59 * V_60 = V_59 ( V_33 -> V_42 ) ;
struct V_61 * V_62 = V_58 ;
struct V_3 * V_4 = NULL ;
int V_17 = 0 ;
V_33 -> V_63 . V_64 . V_65 = V_33 -> V_25 -> V_65 ;
if ( ! V_60 -> V_66 ( V_60 , V_62 -> V_67 . V_30 ) ) {
F_25 ( V_33 , L_1 , V_62 -> V_67 . V_30 ) ;
return - V_53 ;
}
V_17 = F_18 ( V_25 , V_62 -> V_67 . V_26 , V_62 -> V_27 ,
V_62 -> V_67 . V_28 , V_62 -> V_67 . V_29 ,
V_62 -> V_67 . V_30 , & V_4 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_26 ( V_12 , V_4 -> V_2 , & V_62 -> V_67 . V_68 ) ;
if ( V_17 == 0 ) {
V_17 = F_23 ( V_12 , V_4 -> V_2 , & V_62 -> V_67 ) ;
if ( V_17 )
F_27 ( V_12 , V_62 -> V_67 . V_68 ) ;
}
F_28 ( V_4 -> V_2 ) ;
return V_17 ;
}
static int
F_29 ( struct V_1 * V_2 , T_1 V_69 ,
T_1 V_70 , T_1 V_41 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_7 ;
T_1 V_71 = V_41 & V_4 -> V_41 &
( V_70 ? V_70 : V_69 ) ;
T_1 V_72 = 0 , V_73 = 0 ;
if ( ! V_71 )
return - V_53 ;
if ( V_41 & V_35 )
V_73 |= V_36 ;
if ( V_41 & V_37 )
V_73 |= V_38 ;
if ( ( V_71 & V_35 ) &&
V_7 -> V_45 . V_50 == V_74 )
V_72 |= V_36 ;
else if ( ( V_71 & V_37 ) &&
V_7 -> V_45 . V_50 == V_51 )
V_72 |= V_38 ;
else if ( V_71 & V_35 )
V_72 |= V_36 ;
else
V_72 |= V_38 ;
F_30 ( V_4 , V_72 , V_73 ) ;
return 0 ;
}
static void
F_31 ( struct V_75 * V_76 , struct V_77 * V_78 )
{
struct V_75 * V_79 , * V_80 ;
struct V_3 * V_4 ;
F_32 (entry, tmp, list) {
V_4 = F_33 ( V_79 , struct V_3 , V_79 ) ;
F_34 ( V_4 , V_78 ) ;
if ( F_3 ( V_4 -> V_81 ) ) {
F_35 ( & V_4 -> V_82 ) ;
V_4 -> V_81 = false ;
}
F_36 ( & V_4 -> V_79 ) ;
V_4 -> V_83 = NULL ;
F_15 ( & V_4 -> V_7 ) ;
F_28 ( V_4 -> V_2 ) ;
}
}
static void
F_37 ( struct V_84 * V_85 , struct V_77 * V_78 )
{
F_31 ( & V_85 -> V_86 , V_78 ) ;
F_31 ( & V_85 -> V_87 , V_78 ) ;
F_31 ( & V_85 -> V_88 , V_78 ) ;
}
static int
F_38 ( struct V_89 * V_90 , struct V_11 * V_12 ,
struct V_91 * V_92 ,
int V_93 , struct V_84 * V_85 )
{
struct V_24 * V_25 = V_90 -> V_33 -> V_25 ;
struct V_32 * V_33 = V_32 ( V_25 ) ;
T_1 V_94 ;
int V_95 = 0 ;
int V_17 , V_96 ;
V_94 = F_39 ( 1 , & V_33 -> V_63 . V_97 ) ;
V_98:
if ( ++ V_95 > 100000 ) {
F_25 ( V_33 , L_2 , V_99 ) ;
return - V_53 ;
}
for ( V_96 = 0 ; V_96 < V_93 ; V_96 ++ ) {
struct V_91 * V_100 = & V_92 [ V_96 ] ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_40 ( V_25 , V_12 , V_100 -> V_68 ) ;
if ( ! V_2 ) {
F_25 ( V_33 , L_3 , V_100 -> V_68 ) ;
F_37 ( V_85 , NULL ) ;
return - V_101 ;
}
V_4 = V_2 -> V_5 ;
if ( V_4 -> V_83 && V_4 -> V_83 == V_12 ) {
F_25 ( V_33 , L_4
L_5 , V_100 -> V_68 ) ;
F_28 ( V_2 ) ;
F_37 ( V_85 , NULL ) ;
return - V_53 ;
}
V_17 = F_11 ( & V_4 -> V_7 , true , false , true , V_94 ) ;
if ( V_17 ) {
F_37 ( V_85 , NULL ) ;
if ( F_3 ( V_17 == - V_102 ) )
V_17 = F_41 ( & V_4 -> V_7 , true ) ;
F_28 ( V_2 ) ;
if ( F_3 ( V_17 ) ) {
if ( V_17 != - V_103 )
F_25 ( V_33 , L_6 ) ;
return V_17 ;
}
goto V_98;
}
V_100 -> V_104 = ( V_105 ) ( unsigned long ) V_4 ;
V_4 -> V_83 = V_12 ;
V_4 -> V_106 = V_96 ;
if ( ( V_100 -> V_41 & V_35 ) &&
( V_100 -> V_41 & V_37 ) )
F_42 ( & V_4 -> V_79 , & V_85 -> V_88 ) ;
else
if ( V_100 -> V_41 & V_35 )
F_42 ( & V_4 -> V_79 , & V_85 -> V_86 ) ;
else
if ( V_100 -> V_41 & V_37 )
F_42 ( & V_4 -> V_79 , & V_85 -> V_87 ) ;
else {
F_25 ( V_33 , L_7 ,
V_100 -> V_41 ) ;
F_42 ( & V_4 -> V_79 , & V_85 -> V_88 ) ;
F_37 ( V_85 , NULL ) ;
return - V_53 ;
}
}
return 0 ;
}
static int
F_43 ( struct V_89 * V_90 , struct V_3 * V_4 )
{
struct V_77 * V_78 = NULL ;
int V_17 = 0 ;
F_44 ( & V_4 -> V_7 . V_64 -> V_107 ) ;
if ( V_4 -> V_7 . V_108 )
V_78 = F_45 ( V_4 -> V_7 . V_108 ) ;
F_46 ( & V_4 -> V_7 . V_64 -> V_107 ) ;
if ( V_78 ) {
V_17 = F_47 ( V_78 , V_90 ) ;
F_48 ( & V_78 ) ;
}
return V_17 ;
}
static int
F_49 ( struct V_89 * V_90 , struct V_75 * V_76 ,
struct V_91 * V_92 , V_105 V_109 )
{
struct V_32 * V_33 = V_90 -> V_33 ;
struct V_91 T_3 * V_110 =
( void V_111 T_3 * ) ( V_112 ) V_109 ;
struct V_3 * V_4 ;
int V_17 , V_113 = 0 ;
F_50 (nvbo, list, entry) {
struct V_91 * V_100 = & V_92 [ V_4 -> V_106 ] ;
V_17 = F_43 ( V_90 , V_4 ) ;
if ( F_3 ( V_17 ) ) {
F_25 ( V_33 , L_8 ) ;
return V_17 ;
}
V_17 = F_29 ( V_4 -> V_2 , V_100 -> V_69 ,
V_100 -> V_70 ,
V_100 -> V_41 ) ;
if ( F_3 ( V_17 ) ) {
F_25 ( V_33 , L_9 ) ;
return V_17 ;
}
V_17 = F_51 ( V_4 , true , false , false ) ;
if ( F_3 ( V_17 ) ) {
if ( V_17 != - V_103 )
F_25 ( V_33 , L_10 ) ;
return V_17 ;
}
V_17 = F_43 ( V_90 , V_4 ) ;
if ( F_3 ( V_17 ) ) {
F_25 ( V_33 , L_11 ) ;
return V_17 ;
}
if ( F_20 ( V_33 -> V_42 ) -> V_43 < V_44 ) {
if ( V_4 -> V_7 . V_52 == V_100 -> V_114 . V_52 &&
( ( V_4 -> V_7 . V_45 . V_50 == V_74 &&
V_100 -> V_114 . V_28 & V_35 ) ||
( V_4 -> V_7 . V_45 . V_50 == V_51 &&
V_100 -> V_114 . V_28 & V_37 ) ) )
continue;
if ( V_4 -> V_7 . V_45 . V_50 == V_51 )
V_100 -> V_114 . V_28 = V_37 ;
else
V_100 -> V_114 . V_28 = V_35 ;
V_100 -> V_114 . V_52 = V_4 -> V_7 . V_52 ;
V_100 -> V_114 . V_115 = 0 ;
V_113 ++ ;
if ( F_52 ( & V_110 [ V_4 -> V_106 ] . V_114 ,
& V_100 -> V_114 , sizeof( V_100 -> V_114 ) ) )
return - V_116 ;
}
}
return V_113 ;
}
static int
F_53 ( struct V_89 * V_90 ,
struct V_11 * V_12 ,
struct V_91 * V_92 ,
V_105 V_117 , int V_93 ,
struct V_84 * V_85 , int * V_118 )
{
struct V_32 * V_33 = V_90 -> V_33 ;
int V_17 , V_113 = 0 ;
F_54 ( & V_85 -> V_86 ) ;
F_54 ( & V_85 -> V_87 ) ;
F_54 ( & V_85 -> V_88 ) ;
if ( V_93 == 0 )
return 0 ;
V_17 = F_38 ( V_90 , V_12 , V_92 , V_93 , V_85 ) ;
if ( F_3 ( V_17 ) ) {
if ( V_17 != - V_103 )
F_25 ( V_33 , L_12 ) ;
return V_17 ;
}
V_17 = F_49 ( V_90 , & V_85 -> V_86 , V_92 , V_117 ) ;
if ( F_3 ( V_17 < 0 ) ) {
if ( V_17 != - V_103 )
F_25 ( V_33 , L_13 ) ;
F_37 ( V_85 , NULL ) ;
return V_17 ;
}
V_113 += V_17 ;
V_17 = F_49 ( V_90 , & V_85 -> V_87 , V_92 , V_117 ) ;
if ( F_3 ( V_17 < 0 ) ) {
if ( V_17 != - V_103 )
F_25 ( V_33 , L_14 ) ;
F_37 ( V_85 , NULL ) ;
return V_17 ;
}
V_113 += V_17 ;
V_17 = F_49 ( V_90 , & V_85 -> V_88 , V_92 , V_117 ) ;
if ( F_3 ( V_17 < 0 ) ) {
if ( V_17 != - V_103 )
F_25 ( V_33 , L_15 ) ;
F_37 ( V_85 , NULL ) ;
return V_17 ;
}
V_113 += V_17 ;
* V_118 = V_113 ;
return 0 ;
}
static inline void *
F_55 ( V_105 V_119 , unsigned V_120 , unsigned V_26 )
{
void * V_45 ;
void T_3 * V_121 = ( void V_111 T_3 * ) ( V_112 ) V_119 ;
V_45 = F_56 ( V_120 * V_26 , V_20 ) ;
if ( ! V_45 )
return F_57 ( - V_21 ) ;
if ( F_58 ( V_45 , V_121 , V_120 * V_26 ) ) {
F_8 ( V_45 ) ;
return F_57 ( - V_116 ) ;
}
return V_45 ;
}
static int
F_59 ( struct V_24 * V_25 ,
struct V_122 * V_62 ,
struct V_91 * V_7 )
{
struct V_32 * V_33 = V_32 ( V_25 ) ;
struct V_123 * V_124 = NULL ;
int V_17 = 0 ;
unsigned V_96 ;
V_124 = F_55 ( V_62 -> V_113 , V_62 -> V_125 , sizeof( * V_124 ) ) ;
if ( F_60 ( V_124 ) )
return F_61 ( V_124 ) ;
for ( V_96 = 0 ; V_96 < V_62 -> V_125 ; V_96 ++ ) {
struct V_123 * V_126 = & V_124 [ V_96 ] ;
struct V_91 * V_100 ;
struct V_3 * V_4 ;
T_1 V_58 ;
if ( F_3 ( V_126 -> V_127 > V_62 -> V_93 ) ) {
F_25 ( V_33 , L_16 ) ;
V_17 = - V_53 ;
break;
}
V_100 = & V_7 [ V_126 -> V_127 ] ;
if ( V_100 -> V_114 . V_115 )
continue;
if ( F_3 ( V_126 -> V_128 > V_62 -> V_93 ) ) {
F_25 ( V_33 , L_17 ) ;
V_17 = - V_53 ;
break;
}
V_4 = ( void * ) ( unsigned long ) V_7 [ V_126 -> V_128 ] . V_104 ;
if ( F_3 ( V_126 -> V_129 + 4 >
V_4 -> V_7 . V_45 . V_54 << V_55 ) ) {
F_25 ( V_33 , L_18 ) ;
V_17 = - V_53 ;
break;
}
if ( ! V_4 -> V_82 . V_130 ) {
V_17 = F_62 ( & V_4 -> V_7 , 0 , V_4 -> V_7 . V_45 . V_54 ,
& V_4 -> V_82 ) ;
if ( V_17 ) {
F_25 ( V_33 , L_19 ) ;
break;
}
V_4 -> V_81 = true ;
}
if ( V_126 -> V_34 & V_131 )
V_58 = V_100 -> V_114 . V_52 + V_126 -> V_58 ;
else
if ( V_126 -> V_34 & V_132 )
V_58 = ( V_100 -> V_114 . V_52 + V_126 -> V_58 ) >> 32 ;
else
V_58 = V_126 -> V_58 ;
if ( V_126 -> V_34 & V_133 ) {
if ( V_100 -> V_114 . V_28 == V_37 )
V_58 |= V_126 -> V_134 ;
else
V_58 |= V_126 -> V_135 ;
}
F_44 ( & V_4 -> V_7 . V_64 -> V_107 ) ;
V_17 = F_63 ( & V_4 -> V_7 , false , false , false ) ;
F_46 ( & V_4 -> V_7 . V_64 -> V_107 ) ;
if ( V_17 ) {
F_25 ( V_33 , L_20 , V_17 ) ;
break;
}
F_64 ( V_4 , V_126 -> V_129 >> 2 , V_58 ) ;
}
F_8 ( V_124 ) ;
return V_17 ;
}
int
F_65 ( struct V_24 * V_25 , void * V_58 ,
struct V_11 * V_12 )
{
struct V_136 * V_137 = F_66 ( V_12 , V_25 ) ;
struct V_138 * V_139 ;
struct V_32 * V_33 = V_32 ( V_25 ) ;
struct V_122 * V_62 = V_58 ;
struct V_140 * V_141 ;
struct V_91 * V_7 ;
struct V_89 * V_90 = NULL ;
struct V_84 V_85 ;
struct V_77 * V_78 = NULL ;
int V_96 , V_142 , V_17 = 0 , V_143 = 0 ;
if ( F_3 ( ! V_137 ) )
return - V_21 ;
F_50 (temp, &abi16->channels, head) {
if ( V_139 -> V_90 -> V_68 == ( V_144 | V_62 -> V_145 ) ) {
V_90 = V_139 -> V_90 ;
break;
}
}
if ( ! V_90 )
return F_67 ( V_137 , - V_101 ) ;
V_62 -> V_146 = V_33 -> V_2 . V_146 ;
V_62 -> V_147 = V_33 -> V_2 . V_147 ;
if ( F_3 ( V_62 -> V_148 == 0 ) )
goto V_149;
if ( F_3 ( V_62 -> V_148 > V_150 ) ) {
F_25 ( V_33 , L_21 ,
V_62 -> V_148 , V_150 ) ;
return F_67 ( V_137 , - V_53 ) ;
}
if ( F_3 ( V_62 -> V_93 > V_151 ) ) {
F_25 ( V_33 , L_22 ,
V_62 -> V_93 , V_151 ) ;
return F_67 ( V_137 , - V_53 ) ;
}
if ( F_3 ( V_62 -> V_125 > V_152 ) ) {
F_25 ( V_33 , L_23 ,
V_62 -> V_125 , V_152 ) ;
return F_67 ( V_137 , - V_53 ) ;
}
V_141 = F_55 ( V_62 -> V_141 , V_62 -> V_148 , sizeof( * V_141 ) ) ;
if ( F_60 ( V_141 ) )
return F_67 ( V_137 , F_61 ( V_141 ) ) ;
V_7 = F_55 ( V_62 -> V_153 , V_62 -> V_93 , sizeof( * V_7 ) ) ;
if ( F_60 ( V_7 ) ) {
F_8 ( V_141 ) ;
return F_67 ( V_137 , F_61 ( V_7 ) ) ;
}
for ( V_96 = 0 ; V_96 < V_62 -> V_148 ; V_96 ++ ) {
if ( V_141 [ V_96 ] . V_127 >= V_62 -> V_93 ) {
F_25 ( V_33 , L_24 , V_96 ) ;
V_17 = - V_53 ;
goto V_154;
}
}
V_17 = F_53 ( V_90 , V_12 , V_7 , V_62 -> V_153 ,
V_62 -> V_93 , & V_85 , & V_143 ) ;
if ( V_17 ) {
if ( V_17 != - V_103 )
F_25 ( V_33 , L_25 , V_17 ) ;
goto V_154;
}
if ( V_143 ) {
V_17 = F_59 ( V_25 , V_62 , V_7 ) ;
if ( V_17 ) {
F_25 ( V_33 , L_26 , V_17 ) ;
goto V_22;
}
}
if ( V_90 -> V_155 . V_156 ) {
V_17 = F_68 ( V_90 , V_62 -> V_148 + 1 , 16 ) ;
if ( V_17 ) {
F_25 ( V_33 , L_27 , V_17 ) ;
goto V_22;
}
for ( V_96 = 0 ; V_96 < V_62 -> V_148 ; V_96 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_141 [ V_96 ] . V_127 ] . V_104 ;
F_69 ( V_90 , V_4 , V_141 [ V_96 ] . V_52 ,
V_141 [ V_96 ] . V_157 ) ;
}
} else
if ( F_20 ( V_33 -> V_42 ) -> V_158 >= 0x25 ) {
V_17 = F_70 ( V_90 , V_62 -> V_148 * 2 ) ;
if ( V_17 ) {
F_25 ( V_33 , L_28 , V_17 ) ;
goto V_22;
}
for ( V_96 = 0 ; V_96 < V_62 -> V_148 ; V_96 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_141 [ V_96 ] . V_127 ] . V_104 ;
F_71 ( V_90 , ( V_4 -> V_7 . V_52 + V_141 [ V_96 ] . V_52 ) | 2 ) ;
F_71 ( V_90 , 0 ) ;
}
} else {
V_17 = F_70 ( V_90 , V_62 -> V_148 * ( 2 + V_159 ) ) ;
if ( V_17 ) {
F_25 ( V_33 , L_29 , V_17 ) ;
goto V_22;
}
for ( V_96 = 0 ; V_96 < V_62 -> V_148 ; V_96 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_141 [ V_96 ] . V_127 ] . V_104 ;
T_1 V_160 ;
V_160 = V_90 -> V_141 . V_16 . V_52 + ( ( V_90 -> V_155 . V_161 + 2 ) << 2 ) ;
V_160 |= 0x20000000 ;
if ( F_3 ( V_160 != V_62 -> V_162 ) ) {
if ( ! V_4 -> V_82 . V_130 ) {
V_17 = F_62 ( & V_4 -> V_7 , 0 ,
V_4 -> V_7 . V_45 .
V_54 ,
& V_4 -> V_82 ) ;
if ( V_17 ) {
F_72 ( V_90 ) ;
goto V_22;
}
V_4 -> V_81 = true ;
}
F_64 ( V_4 , ( V_141 [ V_96 ] . V_52 +
V_141 [ V_96 ] . V_157 - 8 ) / 4 , V_160 ) ;
}
F_71 ( V_90 , 0x20000000 |
( V_4 -> V_7 . V_52 + V_141 [ V_96 ] . V_52 ) ) ;
F_71 ( V_90 , 0 ) ;
for ( V_142 = 0 ; V_142 < V_159 ; V_142 ++ )
F_71 ( V_90 , 0 ) ;
}
}
V_17 = F_73 ( V_90 , & V_78 ) ;
if ( V_17 ) {
F_25 ( V_33 , L_30 , V_17 ) ;
F_72 ( V_90 ) ;
goto V_22;
}
V_22:
F_37 ( & V_85 , V_78 ) ;
F_48 ( & V_78 ) ;
V_154:
F_8 ( V_7 ) ;
F_8 ( V_141 ) ;
V_149:
if ( V_90 -> V_155 . V_156 ) {
V_62 -> V_162 = 0x00000000 ;
V_62 -> V_163 = 0x00000000 ;
} else
if ( F_20 ( V_33 -> V_42 ) -> V_158 >= 0x25 ) {
V_62 -> V_162 = 0x00020000 ;
V_62 -> V_163 = 0x00000000 ;
} else {
V_62 -> V_162 = 0x20000000 |
( V_90 -> V_141 . V_16 . V_52 + ( ( V_90 -> V_155 . V_161 + 2 ) << 2 ) ) ;
V_62 -> V_163 = 0x00000000 ;
}
return F_67 ( V_137 , V_17 ) ;
}
static inline T_1
F_74 ( struct V_3 * V_4 , T_1 V_28 )
{
T_1 V_34 = 0 ;
if ( V_28 & V_35 )
V_34 |= V_36 ;
if ( V_28 & V_37 )
V_34 |= V_38 ;
return V_34 ;
}
int
F_75 ( struct V_24 * V_25 , void * V_58 ,
struct V_11 * V_12 )
{
struct V_164 * V_62 = V_58 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
bool V_165 = ! ! ( V_62 -> V_34 & V_166 ) ;
int V_17 = - V_53 ;
V_2 = F_40 ( V_25 , V_12 , V_62 -> V_68 ) ;
if ( ! V_2 )
return - V_101 ;
V_4 = F_10 ( V_2 ) ;
F_44 ( & V_4 -> V_7 . V_64 -> V_107 ) ;
V_17 = F_63 ( & V_4 -> V_7 , true , true , V_165 ) ;
F_46 ( & V_4 -> V_7 . V_64 -> V_107 ) ;
F_28 ( V_2 ) ;
return V_17 ;
}
int
F_76 ( struct V_24 * V_25 , void * V_58 ,
struct V_11 * V_12 )
{
return 0 ;
}
int
F_77 ( struct V_24 * V_25 , void * V_58 ,
struct V_11 * V_12 )
{
struct V_48 * V_62 = V_58 ;
struct V_1 * V_2 ;
int V_17 ;
V_2 = F_40 ( V_25 , V_12 , V_62 -> V_68 ) ;
if ( ! V_2 )
return - V_101 ;
V_17 = F_23 ( V_12 , V_2 , V_62 ) ;
F_28 ( V_2 ) ;
return V_17 ;
}
