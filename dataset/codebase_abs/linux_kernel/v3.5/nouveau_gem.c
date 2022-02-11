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
if ( ! V_14 -> V_18 )
return 0 ;
V_17 = F_11 ( & V_4 -> V_7 , false , false , false , 0 ) ;
if ( V_17 )
return V_17 ;
V_16 = F_12 ( V_4 , V_14 -> V_18 ) ;
if ( ! V_16 ) {
V_16 = F_13 ( sizeof( * V_16 ) , V_19 ) ;
if ( ! V_16 ) {
V_17 = - V_20 ;
goto V_21;
}
V_17 = F_14 ( V_4 , V_14 -> V_18 , V_16 ) ;
if ( V_17 ) {
F_8 ( V_16 ) ;
goto V_21;
}
} else {
V_16 -> V_22 ++ ;
}
V_21:
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
if ( ! V_14 -> V_18 )
return;
V_17 = F_11 ( & V_4 -> V_7 , false , false , false , 0 ) ;
if ( V_17 )
return;
V_16 = F_12 ( V_4 , V_14 -> V_18 ) ;
if ( V_16 ) {
if ( -- V_16 -> V_22 == 0 ) {
F_17 ( V_4 , V_16 ) ;
F_8 ( V_16 ) ;
}
}
F_15 ( & V_4 -> V_7 ) ;
}
int
F_18 ( struct V_23 * V_24 , int V_25 , int V_26 , T_1 V_27 ,
T_1 V_28 , T_1 V_29 ,
struct V_3 * * V_30 )
{
struct V_31 * V_32 = V_24 -> V_33 ;
struct V_3 * V_4 ;
T_2 V_34 = 0 ;
int V_17 ;
if ( V_27 & V_35 )
V_34 |= V_36 ;
if ( V_27 & V_37 )
V_34 |= V_38 ;
if ( ! V_34 || V_27 & V_39 )
V_34 |= V_40 ;
V_17 = F_19 ( V_24 , V_25 , V_26 , V_34 , V_28 ,
V_29 , NULL , V_30 ) ;
if ( V_17 )
return V_17 ;
V_4 = * V_30 ;
V_4 -> V_41 = V_35 |
V_37 ;
if ( V_32 -> V_42 >= V_43 )
V_4 -> V_41 &= V_27 ;
V_4 -> V_2 = F_20 ( V_24 , V_4 -> V_7 . V_44 . V_25 ) ;
if ( ! V_4 -> V_2 ) {
F_21 ( NULL , V_30 ) ;
return - V_20 ;
}
V_4 -> V_7 . V_45 = V_4 -> V_2 -> V_46 ;
V_4 -> V_2 -> V_5 = V_4 ;
return 0 ;
}
static int
F_22 ( struct V_11 * V_12 , struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_13 * V_14 = V_13 ( V_12 ) ;
struct V_3 * V_4 = F_10 ( V_2 ) ;
struct V_15 * V_16 ;
if ( V_4 -> V_7 . V_44 . V_49 == V_50 )
V_48 -> V_27 = V_37 ;
else
V_48 -> V_27 = V_35 ;
V_48 -> V_51 = V_4 -> V_7 . V_51 ;
if ( V_14 -> V_18 ) {
V_16 = F_12 ( V_4 , V_14 -> V_18 ) ;
if ( ! V_16 )
return - V_52 ;
V_48 -> V_51 = V_16 -> V_51 ;
}
V_48 -> V_25 = V_4 -> V_7 . V_44 . V_53 << V_54 ;
V_48 -> V_55 = V_4 -> V_7 . V_56 ;
V_48 -> V_28 = V_4 -> V_28 ;
V_48 -> V_29 = V_4 -> V_29 ;
return 0 ;
}
int
F_23 ( struct V_23 * V_24 , void * V_57 ,
struct V_11 * V_12 )
{
struct V_31 * V_32 = V_24 -> V_33 ;
struct V_58 * V_59 = V_57 ;
struct V_3 * V_4 = NULL ;
int V_17 = 0 ;
if ( F_3 ( V_32 -> V_60 . V_61 . V_62 == NULL ) )
V_32 -> V_60 . V_61 . V_62 = V_32 -> V_24 -> V_62 ;
if ( ! V_32 -> V_63 . V_64 . V_65 ( V_24 , V_59 -> V_66 . V_29 ) ) {
F_24 ( V_24 , L_1 , V_59 -> V_66 . V_29 ) ;
return - V_52 ;
}
V_17 = F_18 ( V_24 , V_59 -> V_66 . V_25 , V_59 -> V_26 ,
V_59 -> V_66 . V_27 , V_59 -> V_66 . V_28 ,
V_59 -> V_66 . V_29 , & V_4 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_25 ( V_12 , V_4 -> V_2 , & V_59 -> V_66 . V_67 ) ;
if ( V_17 == 0 ) {
V_17 = F_22 ( V_12 , V_4 -> V_2 , & V_59 -> V_66 ) ;
if ( V_17 )
F_26 ( V_12 , V_59 -> V_66 . V_67 ) ;
}
F_27 ( V_4 -> V_2 ) ;
return V_17 ;
}
static int
F_28 ( struct V_1 * V_2 , T_1 V_68 ,
T_1 V_69 , T_1 V_41 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_7 ;
T_1 V_70 = V_41 & V_4 -> V_41 &
( V_69 ? V_69 : V_68 ) ;
T_1 V_71 = 0 , V_72 = 0 ;
if ( ! V_70 )
return - V_52 ;
if ( V_41 & V_35 )
V_72 |= V_36 ;
if ( V_41 & V_37 )
V_72 |= V_38 ;
if ( ( V_70 & V_35 ) &&
V_7 -> V_44 . V_49 == V_73 )
V_71 |= V_36 ;
else if ( ( V_70 & V_37 ) &&
V_7 -> V_44 . V_49 == V_50 )
V_71 |= V_38 ;
else if ( V_70 & V_35 )
V_71 |= V_36 ;
else
V_71 |= V_38 ;
F_29 ( V_4 , V_71 , V_72 ) ;
return 0 ;
}
static void
F_30 ( struct V_74 * V_75 , struct V_76 * V_77 )
{
struct V_74 * V_78 , * V_79 ;
struct V_3 * V_4 ;
F_31 (entry, tmp, list) {
V_4 = F_32 ( V_78 , struct V_3 , V_78 ) ;
F_33 ( V_4 , V_77 ) ;
if ( F_3 ( V_4 -> V_80 ) ) {
F_34 ( & V_4 -> V_81 ) ;
V_4 -> V_80 = false ;
}
F_35 ( & V_4 -> V_78 ) ;
V_4 -> V_82 = NULL ;
F_15 ( & V_4 -> V_7 ) ;
F_27 ( V_4 -> V_2 ) ;
}
}
static void
F_36 ( struct V_83 * V_84 , struct V_76 * V_77 )
{
F_30 ( & V_84 -> V_85 , V_77 ) ;
F_30 ( & V_84 -> V_86 , V_77 ) ;
F_30 ( & V_84 -> V_87 , V_77 ) ;
}
static int
F_37 ( struct V_88 * V_89 , struct V_11 * V_12 ,
struct V_90 * V_91 ,
int V_92 , struct V_83 * V_84 )
{
struct V_23 * V_24 = V_89 -> V_24 ;
struct V_31 * V_32 = V_24 -> V_33 ;
T_1 V_93 ;
int V_94 = 0 ;
int V_17 , V_95 ;
V_93 = F_38 ( 1 , & V_32 -> V_60 . V_96 ) ;
V_97:
if ( ++ V_94 > 100000 ) {
F_24 ( V_24 , L_2 , V_98 ) ;
return - V_52 ;
}
for ( V_95 = 0 ; V_95 < V_92 ; V_95 ++ ) {
struct V_90 * V_99 = & V_91 [ V_95 ] ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_39 ( V_24 , V_12 , V_99 -> V_67 ) ;
if ( ! V_2 ) {
F_24 ( V_24 , L_3 , V_99 -> V_67 ) ;
F_36 ( V_84 , NULL ) ;
return - V_100 ;
}
V_4 = V_2 -> V_5 ;
if ( V_4 -> V_82 && V_4 -> V_82 == V_12 ) {
F_24 ( V_24 , L_4
L_5 , V_99 -> V_67 ) ;
F_36 ( V_84 , NULL ) ;
return - V_52 ;
}
V_17 = F_11 ( & V_4 -> V_7 , true , false , true , V_93 ) ;
if ( V_17 ) {
F_36 ( V_84 , NULL ) ;
if ( F_3 ( V_17 == - V_101 ) )
V_17 = F_40 ( & V_4 -> V_7 , true ) ;
F_27 ( V_2 ) ;
if ( F_3 ( V_17 ) ) {
if ( V_17 != - V_102 )
F_24 ( V_24 , L_6 ) ;
return V_17 ;
}
goto V_97;
}
V_99 -> V_103 = ( V_104 ) ( unsigned long ) V_4 ;
V_4 -> V_82 = V_12 ;
V_4 -> V_105 = V_95 ;
if ( ( V_99 -> V_41 & V_35 ) &&
( V_99 -> V_41 & V_37 ) )
F_41 ( & V_4 -> V_78 , & V_84 -> V_87 ) ;
else
if ( V_99 -> V_41 & V_35 )
F_41 ( & V_4 -> V_78 , & V_84 -> V_85 ) ;
else
if ( V_99 -> V_41 & V_37 )
F_41 ( & V_4 -> V_78 , & V_84 -> V_86 ) ;
else {
F_24 ( V_24 , L_7 ,
V_99 -> V_41 ) ;
F_41 ( & V_4 -> V_78 , & V_84 -> V_87 ) ;
F_36 ( V_84 , NULL ) ;
return - V_52 ;
}
}
return 0 ;
}
static int
F_42 ( struct V_88 * V_89 , struct V_3 * V_4 )
{
struct V_76 * V_77 = NULL ;
int V_17 = 0 ;
F_43 ( & V_4 -> V_7 . V_61 -> V_106 ) ;
if ( V_4 -> V_7 . V_107 )
V_77 = F_44 ( V_4 -> V_7 . V_107 ) ;
F_45 ( & V_4 -> V_7 . V_61 -> V_106 ) ;
if ( V_77 ) {
V_17 = F_46 ( V_77 , V_89 ) ;
F_47 ( & V_77 ) ;
}
return V_17 ;
}
static int
F_48 ( struct V_88 * V_89 , struct V_74 * V_75 ,
struct V_90 * V_91 , V_104 V_108 )
{
struct V_31 * V_32 = V_89 -> V_24 -> V_33 ;
struct V_90 T_3 * V_109 =
( void V_110 T_3 * ) ( V_111 ) V_108 ;
struct V_23 * V_24 = V_89 -> V_24 ;
struct V_3 * V_4 ;
int V_17 , V_112 = 0 ;
F_49 (nvbo, list, entry) {
struct V_90 * V_99 = & V_91 [ V_4 -> V_105 ] ;
V_17 = F_42 ( V_89 , V_4 ) ;
if ( F_3 ( V_17 ) ) {
F_24 ( V_24 , L_8 ) ;
return V_17 ;
}
V_17 = F_28 ( V_4 -> V_2 , V_99 -> V_68 ,
V_99 -> V_69 ,
V_99 -> V_41 ) ;
if ( F_3 ( V_17 ) ) {
F_24 ( V_24 , L_9 ) ;
return V_17 ;
}
V_17 = F_50 ( V_4 , true , false , false ) ;
if ( F_3 ( V_17 ) ) {
if ( V_17 != - V_102 )
F_24 ( V_24 , L_10 ) ;
return V_17 ;
}
V_17 = F_42 ( V_89 , V_4 ) ;
if ( F_3 ( V_17 ) ) {
F_24 ( V_24 , L_11 ) ;
return V_17 ;
}
if ( V_32 -> V_42 < V_43 ) {
if ( V_4 -> V_7 . V_51 == V_99 -> V_113 . V_51 &&
( ( V_4 -> V_7 . V_44 . V_49 == V_73 &&
V_99 -> V_113 . V_27 & V_35 ) ||
( V_4 -> V_7 . V_44 . V_49 == V_50 &&
V_99 -> V_113 . V_27 & V_37 ) ) )
continue;
if ( V_4 -> V_7 . V_44 . V_49 == V_50 )
V_99 -> V_113 . V_27 = V_37 ;
else
V_99 -> V_113 . V_27 = V_35 ;
V_99 -> V_113 . V_51 = V_4 -> V_7 . V_51 ;
V_99 -> V_113 . V_114 = 0 ;
V_112 ++ ;
if ( F_51 ( & V_109 [ V_4 -> V_105 ] . V_113 ,
& V_99 -> V_113 , sizeof( V_99 -> V_113 ) ) )
return - V_115 ;
}
}
return V_112 ;
}
static int
F_52 ( struct V_88 * V_89 ,
struct V_11 * V_12 ,
struct V_90 * V_91 ,
V_104 V_116 , int V_92 ,
struct V_83 * V_84 , int * V_117 )
{
struct V_23 * V_24 = V_89 -> V_24 ;
int V_17 , V_112 = 0 ;
F_53 ( & V_84 -> V_85 ) ;
F_53 ( & V_84 -> V_86 ) ;
F_53 ( & V_84 -> V_87 ) ;
if ( V_92 == 0 )
return 0 ;
V_17 = F_37 ( V_89 , V_12 , V_91 , V_92 , V_84 ) ;
if ( F_3 ( V_17 ) ) {
if ( V_17 != - V_102 )
F_24 ( V_24 , L_12 ) ;
return V_17 ;
}
V_17 = F_48 ( V_89 , & V_84 -> V_85 , V_91 , V_116 ) ;
if ( F_3 ( V_17 < 0 ) ) {
if ( V_17 != - V_102 )
F_24 ( V_24 , L_13 ) ;
F_36 ( V_84 , NULL ) ;
return V_17 ;
}
V_112 += V_17 ;
V_17 = F_48 ( V_89 , & V_84 -> V_86 , V_91 , V_116 ) ;
if ( F_3 ( V_17 < 0 ) ) {
if ( V_17 != - V_102 )
F_24 ( V_24 , L_14 ) ;
F_36 ( V_84 , NULL ) ;
return V_17 ;
}
V_112 += V_17 ;
V_17 = F_48 ( V_89 , & V_84 -> V_87 , V_91 , V_116 ) ;
if ( F_3 ( V_17 < 0 ) ) {
if ( V_17 != - V_102 )
F_24 ( V_24 , L_15 ) ;
F_36 ( V_84 , NULL ) ;
return V_17 ;
}
V_112 += V_17 ;
* V_117 = V_112 ;
return 0 ;
}
static inline void *
F_54 ( V_104 V_118 , unsigned V_119 , unsigned V_25 )
{
void * V_44 ;
void T_3 * V_120 = ( void V_110 T_3 * ) ( V_111 ) V_118 ;
V_44 = F_55 ( V_119 * V_25 , V_19 ) ;
if ( ! V_44 )
return F_56 ( - V_20 ) ;
if ( F_57 ( V_44 , V_120 , V_119 * V_25 ) ) {
F_8 ( V_44 ) ;
return F_56 ( - V_115 ) ;
}
return V_44 ;
}
static int
F_58 ( struct V_23 * V_24 ,
struct V_121 * V_59 ,
struct V_90 * V_7 )
{
struct V_122 * V_123 = NULL ;
int V_17 = 0 ;
unsigned V_95 ;
V_123 = F_54 ( V_59 -> V_112 , V_59 -> V_124 , sizeof( * V_123 ) ) ;
if ( F_59 ( V_123 ) )
return F_60 ( V_123 ) ;
for ( V_95 = 0 ; V_95 < V_59 -> V_124 ; V_95 ++ ) {
struct V_122 * V_125 = & V_123 [ V_95 ] ;
struct V_90 * V_99 ;
struct V_3 * V_4 ;
T_1 V_57 ;
if ( F_3 ( V_125 -> V_126 > V_59 -> V_92 ) ) {
F_24 ( V_24 , L_16 ) ;
V_17 = - V_52 ;
break;
}
V_99 = & V_7 [ V_125 -> V_126 ] ;
if ( V_99 -> V_113 . V_114 )
continue;
if ( F_3 ( V_125 -> V_127 > V_59 -> V_92 ) ) {
F_24 ( V_24 , L_17 ) ;
V_17 = - V_52 ;
break;
}
V_4 = ( void * ) ( unsigned long ) V_7 [ V_125 -> V_127 ] . V_103 ;
if ( F_3 ( V_125 -> V_128 + 4 >
V_4 -> V_7 . V_44 . V_53 << V_54 ) ) {
F_24 ( V_24 , L_18 ) ;
V_17 = - V_52 ;
break;
}
if ( ! V_4 -> V_81 . V_129 ) {
V_17 = F_61 ( & V_4 -> V_7 , 0 , V_4 -> V_7 . V_44 . V_53 ,
& V_4 -> V_81 ) ;
if ( V_17 ) {
F_24 ( V_24 , L_19 ) ;
break;
}
V_4 -> V_80 = true ;
}
if ( V_125 -> V_34 & V_130 )
V_57 = V_99 -> V_113 . V_51 + V_125 -> V_57 ;
else
if ( V_125 -> V_34 & V_131 )
V_57 = ( V_99 -> V_113 . V_51 + V_125 -> V_57 ) >> 32 ;
else
V_57 = V_125 -> V_57 ;
if ( V_125 -> V_34 & V_132 ) {
if ( V_99 -> V_113 . V_27 == V_37 )
V_57 |= V_125 -> V_133 ;
else
V_57 |= V_125 -> V_134 ;
}
F_43 ( & V_4 -> V_7 . V_61 -> V_106 ) ;
V_17 = F_62 ( & V_4 -> V_7 , false , false , false ) ;
F_45 ( & V_4 -> V_7 . V_61 -> V_106 ) ;
if ( V_17 ) {
F_24 ( V_24 , L_20 , V_17 ) ;
break;
}
F_63 ( V_4 , V_125 -> V_128 >> 2 , V_57 ) ;
}
F_8 ( V_123 ) ;
return V_17 ;
}
int
F_64 ( struct V_23 * V_24 , void * V_57 ,
struct V_11 * V_12 )
{
struct V_31 * V_32 = V_24 -> V_33 ;
struct V_121 * V_59 = V_57 ;
struct V_135 * V_136 ;
struct V_90 * V_7 ;
struct V_88 * V_89 ;
struct V_83 V_84 ;
struct V_76 * V_77 = NULL ;
int V_95 , V_137 , V_17 = 0 , V_138 = 0 ;
V_89 = F_65 ( V_12 , V_59 -> V_139 ) ;
if ( F_59 ( V_89 ) )
return F_60 ( V_89 ) ;
V_59 -> V_140 = V_32 -> V_141 ;
V_59 -> V_142 = V_32 -> V_143 . V_144 ;
if ( F_3 ( V_59 -> V_145 == 0 ) )
goto V_146;
if ( F_3 ( V_59 -> V_145 > V_147 ) ) {
F_24 ( V_24 , L_21 ,
V_59 -> V_145 , V_147 ) ;
F_66 ( & V_89 ) ;
return - V_52 ;
}
if ( F_3 ( V_59 -> V_92 > V_148 ) ) {
F_24 ( V_24 , L_22 ,
V_59 -> V_92 , V_148 ) ;
F_66 ( & V_89 ) ;
return - V_52 ;
}
if ( F_3 ( V_59 -> V_124 > V_149 ) ) {
F_24 ( V_24 , L_23 ,
V_59 -> V_124 , V_149 ) ;
F_66 ( & V_89 ) ;
return - V_52 ;
}
V_136 = F_54 ( V_59 -> V_136 , V_59 -> V_145 , sizeof( * V_136 ) ) ;
if ( F_59 ( V_136 ) ) {
F_66 ( & V_89 ) ;
return F_60 ( V_136 ) ;
}
V_7 = F_54 ( V_59 -> V_150 , V_59 -> V_92 , sizeof( * V_7 ) ) ;
if ( F_59 ( V_7 ) ) {
F_8 ( V_136 ) ;
F_66 ( & V_89 ) ;
return F_60 ( V_7 ) ;
}
for ( V_95 = 0 ; V_95 < V_59 -> V_145 ; V_95 ++ ) {
if ( V_136 [ V_95 ] . V_126 >= V_59 -> V_92 ) {
F_24 ( V_24 , L_24 , V_95 ) ;
V_17 = - V_52 ;
goto V_151;
}
}
V_17 = F_52 ( V_89 , V_12 , V_7 , V_59 -> V_150 ,
V_59 -> V_92 , & V_84 , & V_138 ) ;
if ( V_17 ) {
if ( V_17 != - V_102 )
F_24 ( V_24 , L_25 , V_17 ) ;
goto V_151;
}
if ( V_138 ) {
V_17 = F_58 ( V_24 , V_59 , V_7 ) ;
if ( V_17 ) {
F_24 ( V_24 , L_26 , V_17 ) ;
goto V_21;
}
}
if ( V_89 -> V_152 . V_153 ) {
V_17 = F_67 ( V_89 , V_59 -> V_145 + 1 , 16 ) ;
if ( V_17 ) {
F_68 ( V_24 , L_27 , V_17 ) ;
goto V_21;
}
for ( V_95 = 0 ; V_95 < V_59 -> V_145 ; V_95 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_136 [ V_95 ] . V_126 ] . V_103 ;
F_69 ( V_89 , V_4 , V_136 [ V_95 ] . V_51 ,
V_136 [ V_95 ] . V_154 ) ;
}
} else
if ( V_32 -> V_155 >= 0x25 ) {
V_17 = F_70 ( V_89 , V_59 -> V_145 * 2 ) ;
if ( V_17 ) {
F_24 ( V_24 , L_28 , V_17 ) ;
goto V_21;
}
for ( V_95 = 0 ; V_95 < V_59 -> V_145 ; V_95 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_136 [ V_95 ] . V_126 ] . V_103 ;
struct V_156 * V_44 = V_4 -> V_7 . V_44 . V_157 ;
F_71 ( V_89 , ( ( V_44 -> V_158 << V_54 ) +
V_136 [ V_95 ] . V_51 ) | 2 ) ;
F_71 ( V_89 , 0 ) ;
}
} else {
V_17 = F_70 ( V_89 , V_59 -> V_145 * ( 2 + V_159 ) ) ;
if ( V_17 ) {
F_24 ( V_24 , L_29 , V_17 ) ;
goto V_21;
}
for ( V_95 = 0 ; V_95 < V_59 -> V_145 ; V_95 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_136 [ V_95 ] . V_126 ] . V_103 ;
struct V_156 * V_44 = V_4 -> V_7 . V_44 . V_157 ;
T_1 V_160 ;
V_160 = V_89 -> V_161 + ( ( V_89 -> V_152 . V_162 + 2 ) << 2 ) ;
V_160 |= 0x20000000 ;
if ( F_3 ( V_160 != V_59 -> V_163 ) ) {
if ( ! V_4 -> V_81 . V_129 ) {
V_17 = F_61 ( & V_4 -> V_7 , 0 ,
V_4 -> V_7 . V_44 .
V_53 ,
& V_4 -> V_81 ) ;
if ( V_17 ) {
F_72 ( V_89 ) ;
goto V_21;
}
V_4 -> V_80 = true ;
}
F_63 ( V_4 , ( V_136 [ V_95 ] . V_51 +
V_136 [ V_95 ] . V_154 - 8 ) / 4 , V_160 ) ;
}
F_71 ( V_89 , ( ( V_44 -> V_158 << V_54 ) +
V_136 [ V_95 ] . V_51 ) | 0x20000000 ) ;
F_71 ( V_89 , 0 ) ;
for ( V_137 = 0 ; V_137 < V_159 ; V_137 ++ )
F_71 ( V_89 , 0 ) ;
}
}
V_17 = F_73 ( V_89 , & V_77 ) ;
if ( V_17 ) {
F_24 ( V_24 , L_30 , V_17 ) ;
F_72 ( V_89 ) ;
goto V_21;
}
V_21:
F_36 ( & V_84 , V_77 ) ;
F_47 ( & V_77 ) ;
V_151:
F_8 ( V_7 ) ;
F_8 ( V_136 ) ;
V_146:
if ( V_89 -> V_152 . V_153 ) {
V_59 -> V_163 = 0x00000000 ;
V_59 -> V_164 = 0x00000000 ;
} else
if ( V_32 -> V_155 >= 0x25 ) {
V_59 -> V_163 = 0x00020000 ;
V_59 -> V_164 = 0x00000000 ;
} else {
V_59 -> V_163 = 0x20000000 |
( V_89 -> V_161 + ( ( V_89 -> V_152 . V_162 + 2 ) << 2 ) ) ;
V_59 -> V_164 = 0x00000000 ;
}
F_66 ( & V_89 ) ;
return V_17 ;
}
static inline T_1
F_74 ( struct V_3 * V_4 , T_1 V_27 )
{
T_1 V_34 = 0 ;
if ( V_27 & V_35 )
V_34 |= V_36 ;
if ( V_27 & V_37 )
V_34 |= V_38 ;
return V_34 ;
}
int
F_75 ( struct V_23 * V_24 , void * V_57 ,
struct V_11 * V_12 )
{
struct V_165 * V_59 = V_57 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
bool V_166 = ! ! ( V_59 -> V_34 & V_167 ) ;
int V_17 = - V_52 ;
V_2 = F_39 ( V_24 , V_12 , V_59 -> V_67 ) ;
if ( ! V_2 )
return - V_100 ;
V_4 = F_10 ( V_2 ) ;
F_43 ( & V_4 -> V_7 . V_61 -> V_106 ) ;
V_17 = F_62 ( & V_4 -> V_7 , true , true , V_166 ) ;
F_45 ( & V_4 -> V_7 . V_61 -> V_106 ) ;
F_27 ( V_2 ) ;
return V_17 ;
}
int
F_76 ( struct V_23 * V_24 , void * V_57 ,
struct V_11 * V_12 )
{
return 0 ;
}
int
F_77 ( struct V_23 * V_24 , void * V_57 ,
struct V_11 * V_12 )
{
struct V_47 * V_59 = V_57 ;
struct V_1 * V_2 ;
int V_17 ;
V_2 = F_39 ( V_24 , V_12 , V_59 -> V_67 ) ;
if ( ! V_2 )
return - V_100 ;
V_17 = F_22 ( V_12 , V_2 , V_59 ) ;
F_27 ( V_2 ) ;
return V_17 ;
}
