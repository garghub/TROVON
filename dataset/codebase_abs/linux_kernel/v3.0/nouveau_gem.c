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
F_5 ( & V_7 ) ;
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
}
int
F_8 ( struct V_9 * V_10 , struct V_11 * V_12 ,
int V_13 , int V_14 , T_1 V_15 , T_1 V_16 ,
T_1 V_17 , struct V_3 * * V_18 )
{
struct V_19 * V_20 = V_10 -> V_21 ;
struct V_3 * V_4 ;
T_2 V_22 = 0 ;
int V_23 ;
if ( V_15 & V_24 )
V_22 |= V_25 ;
if ( V_15 & V_26 )
V_22 |= V_27 ;
if ( ! V_22 || V_15 & V_28 )
V_22 |= V_29 ;
V_23 = F_9 ( V_10 , V_12 , V_13 , V_14 , V_22 , V_16 ,
V_17 , V_18 ) ;
if ( V_23 )
return V_23 ;
V_4 = * V_18 ;
V_4 -> V_30 = V_24 |
V_26 ;
if ( V_20 -> V_31 >= V_32 )
V_4 -> V_30 &= V_15 ;
V_4 -> V_2 = F_10 ( V_10 , V_4 -> V_7 . V_33 . V_13 ) ;
if ( ! V_4 -> V_2 ) {
F_11 ( NULL , V_18 ) ;
return - V_34 ;
}
V_4 -> V_7 . V_35 = V_4 -> V_2 -> V_36 ;
V_4 -> V_2 -> V_5 = V_4 ;
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
struct V_3 * V_4 = F_13 ( V_2 ) ;
if ( V_4 -> V_7 . V_33 . V_39 == V_40 )
V_38 -> V_15 = V_26 ;
else
V_38 -> V_15 = V_24 ;
V_38 -> V_13 = V_4 -> V_7 . V_33 . V_41 << V_42 ;
V_38 -> V_43 = V_4 -> V_7 . V_43 ;
V_38 -> V_44 = V_4 -> V_7 . V_45 ;
V_38 -> V_16 = V_4 -> V_16 ;
V_38 -> V_17 = V_4 -> V_17 ;
return 0 ;
}
int
F_14 ( struct V_9 * V_10 , void * V_46 ,
struct V_47 * V_48 )
{
struct V_19 * V_20 = V_10 -> V_21 ;
struct V_49 * V_50 = V_46 ;
struct V_3 * V_4 = NULL ;
struct V_11 * V_12 = NULL ;
int V_23 = 0 ;
if ( F_3 ( V_20 -> V_51 . V_52 . V_53 == NULL ) )
V_20 -> V_51 . V_52 . V_53 = V_20 -> V_10 -> V_53 ;
if ( ! V_20 -> V_54 . V_55 . V_56 ( V_10 , V_50 -> V_57 . V_17 ) ) {
F_15 ( V_10 , L_1 , V_50 -> V_57 . V_17 ) ;
return - V_58 ;
}
if ( V_50 -> V_59 ) {
V_12 = F_16 ( V_10 , V_48 , V_50 -> V_59 ) ;
if ( F_17 ( V_12 ) )
return F_18 ( V_12 ) ;
}
V_23 = F_8 ( V_10 , V_12 , V_50 -> V_57 . V_13 , V_50 -> V_14 ,
V_50 -> V_57 . V_15 , V_50 -> V_57 . V_16 ,
V_50 -> V_57 . V_17 , & V_4 ) ;
if ( V_12 )
F_19 ( & V_12 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_12 ( V_4 -> V_2 , & V_50 -> V_57 ) ;
if ( V_23 )
goto V_60;
V_23 = F_20 ( V_48 , V_4 -> V_2 , & V_50 -> V_57 . V_61 ) ;
F_21 ( V_4 -> V_2 ) ;
V_60:
return V_23 ;
}
static int
F_22 ( struct V_1 * V_2 , T_1 V_62 ,
T_1 V_63 , T_1 V_30 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_7 ;
T_1 V_64 = V_30 & V_4 -> V_30 &
( V_63 ? V_63 : V_62 ) ;
T_1 V_65 = 0 , V_66 = 0 ;
if ( ! V_64 )
return - V_58 ;
if ( V_30 & V_24 )
V_66 |= V_25 ;
if ( V_30 & V_26 )
V_66 |= V_27 ;
if ( ( V_64 & V_24 ) &&
V_7 -> V_33 . V_39 == V_67 )
V_65 |= V_25 ;
else if ( ( V_64 & V_26 ) &&
V_7 -> V_33 . V_39 == V_40 )
V_65 |= V_27 ;
else if ( V_64 & V_24 )
V_65 |= V_25 ;
else
V_65 |= V_27 ;
F_23 ( V_4 , V_65 , V_66 ) ;
return 0 ;
}
static void
F_24 ( struct V_68 * V_69 , struct V_70 * V_71 )
{
struct V_68 * V_72 , * V_73 ;
struct V_3 * V_4 ;
F_25 (entry, tmp, list) {
V_4 = F_26 ( V_72 , struct V_3 , V_72 ) ;
F_27 ( V_4 , V_71 ) ;
if ( F_3 ( V_4 -> V_74 ) ) {
F_28 ( & V_4 -> V_75 ) ;
V_4 -> V_74 = false ;
}
F_29 ( & V_4 -> V_72 ) ;
V_4 -> V_76 = NULL ;
F_30 ( & V_4 -> V_7 ) ;
F_21 ( V_4 -> V_2 ) ;
}
}
static void
F_31 ( struct V_77 * V_78 , struct V_70 * V_71 )
{
F_24 ( & V_78 -> V_79 , V_71 ) ;
F_24 ( & V_78 -> V_80 , V_71 ) ;
F_24 ( & V_78 -> V_81 , V_71 ) ;
}
static int
F_32 ( struct V_11 * V_12 , struct V_47 * V_48 ,
struct V_82 * V_83 ,
int V_84 , struct V_77 * V_78 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_19 * V_20 = V_10 -> V_21 ;
T_1 V_85 ;
int V_86 = 0 ;
int V_23 , V_87 ;
V_85 = F_33 ( 1 , & V_20 -> V_51 . V_88 ) ;
V_89:
if ( ++ V_86 > 100000 ) {
F_15 ( V_10 , L_2 , V_90 ) ;
return - V_58 ;
}
for ( V_87 = 0 ; V_87 < V_84 ; V_87 ++ ) {
struct V_82 * V_91 = & V_83 [ V_87 ] ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_34 ( V_10 , V_48 , V_91 -> V_61 ) ;
if ( ! V_2 ) {
F_15 ( V_10 , L_3 , V_91 -> V_61 ) ;
F_31 ( V_78 , NULL ) ;
return - V_92 ;
}
V_4 = V_2 -> V_5 ;
if ( V_4 -> V_76 && V_4 -> V_76 == V_48 ) {
F_15 ( V_10 , L_4
L_5 , V_91 -> V_61 ) ;
F_31 ( V_78 , NULL ) ;
return - V_58 ;
}
V_23 = F_35 ( & V_4 -> V_7 , true , false , true , V_85 ) ;
if ( V_23 ) {
F_31 ( V_78 , NULL ) ;
if ( F_3 ( V_23 == - V_93 ) )
V_23 = F_36 ( & V_4 -> V_7 , true ) ;
F_21 ( V_2 ) ;
if ( F_3 ( V_23 ) ) {
if ( V_23 != - V_94 )
F_15 ( V_10 , L_6 ) ;
return V_23 ;
}
goto V_89;
}
V_91 -> V_95 = ( V_96 ) ( unsigned long ) V_4 ;
V_4 -> V_76 = V_48 ;
V_4 -> V_97 = V_87 ;
if ( ( V_91 -> V_30 & V_24 ) &&
( V_91 -> V_30 & V_26 ) )
F_37 ( & V_4 -> V_72 , & V_78 -> V_81 ) ;
else
if ( V_91 -> V_30 & V_24 )
F_37 ( & V_4 -> V_72 , & V_78 -> V_79 ) ;
else
if ( V_91 -> V_30 & V_26 )
F_37 ( & V_4 -> V_72 , & V_78 -> V_80 ) ;
else {
F_15 ( V_10 , L_7 ,
V_91 -> V_30 ) ;
F_37 ( & V_4 -> V_72 , & V_78 -> V_81 ) ;
F_31 ( V_78 , NULL ) ;
return - V_58 ;
}
}
return 0 ;
}
static int
F_38 ( struct V_11 * V_12 , struct V_68 * V_69 ,
struct V_82 * V_83 , V_96 V_98 )
{
struct V_82 T_3 * V_99 =
( void V_100 T_3 * ) ( V_101 ) V_98 ;
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_3 * V_4 ;
int V_23 , V_102 = 0 ;
F_39 (nvbo, list, entry) {
struct V_82 * V_91 = & V_83 [ V_4 -> V_97 ] ;
V_23 = F_40 ( V_4 -> V_7 . V_103 , V_12 ) ;
if ( F_3 ( V_23 ) ) {
F_15 ( V_10 , L_8 ) ;
return V_23 ;
}
V_23 = F_22 ( V_4 -> V_2 , V_91 -> V_62 ,
V_91 -> V_63 ,
V_91 -> V_30 ) ;
if ( F_3 ( V_23 ) ) {
F_15 ( V_10 , L_9 ) ;
return V_23 ;
}
V_4 -> V_104 = ( V_91 -> V_62 & ( 1 << 31 ) ) ? NULL : V_12 ;
V_23 = F_41 ( V_4 , true , false , false ) ;
V_4 -> V_104 = NULL ;
if ( F_3 ( V_23 ) ) {
if ( V_23 != - V_94 )
F_15 ( V_10 , L_10 ) ;
return V_23 ;
}
V_23 = F_40 ( V_4 -> V_7 . V_103 , V_12 ) ;
if ( F_3 ( V_23 ) ) {
F_15 ( V_10 , L_11 ) ;
return V_23 ;
}
if ( V_4 -> V_7 . V_43 == V_91 -> V_105 . V_43 &&
( ( V_4 -> V_7 . V_33 . V_39 == V_67 &&
V_91 -> V_105 . V_15 & V_24 ) ||
( V_4 -> V_7 . V_33 . V_39 == V_40 &&
V_91 -> V_105 . V_15 & V_26 ) ) )
continue;
if ( V_4 -> V_7 . V_33 . V_39 == V_40 )
V_91 -> V_105 . V_15 = V_26 ;
else
V_91 -> V_105 . V_15 = V_24 ;
V_91 -> V_105 . V_43 = V_4 -> V_7 . V_43 ;
V_91 -> V_105 . V_106 = 0 ;
V_102 ++ ;
if ( F_42 ( & V_99 [ V_4 -> V_97 ] . V_105 ,
& V_91 -> V_105 , sizeof( V_91 -> V_105 ) ) )
return - V_107 ;
}
return V_102 ;
}
static int
F_43 ( struct V_11 * V_12 ,
struct V_47 * V_48 ,
struct V_82 * V_83 ,
V_96 V_108 , int V_84 ,
struct V_77 * V_78 , int * V_109 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
int V_23 , V_102 = 0 ;
F_44 ( & V_78 -> V_79 ) ;
F_44 ( & V_78 -> V_80 ) ;
F_44 ( & V_78 -> V_81 ) ;
if ( V_84 == 0 )
return 0 ;
V_23 = F_32 ( V_12 , V_48 , V_83 , V_84 , V_78 ) ;
if ( F_3 ( V_23 ) ) {
if ( V_23 != - V_94 )
F_15 ( V_10 , L_12 ) ;
return V_23 ;
}
V_23 = F_38 ( V_12 , & V_78 -> V_79 , V_83 , V_108 ) ;
if ( F_3 ( V_23 < 0 ) ) {
if ( V_23 != - V_94 )
F_15 ( V_10 , L_13 ) ;
F_31 ( V_78 , NULL ) ;
return V_23 ;
}
V_102 += V_23 ;
V_23 = F_38 ( V_12 , & V_78 -> V_80 , V_83 , V_108 ) ;
if ( F_3 ( V_23 < 0 ) ) {
if ( V_23 != - V_94 )
F_15 ( V_10 , L_14 ) ;
F_31 ( V_78 , NULL ) ;
return V_23 ;
}
V_102 += V_23 ;
V_23 = F_38 ( V_12 , & V_78 -> V_81 , V_83 , V_108 ) ;
if ( F_3 ( V_23 < 0 ) ) {
if ( V_23 != - V_94 )
F_15 ( V_10 , L_15 ) ;
F_31 ( V_78 , NULL ) ;
return V_23 ;
}
V_102 += V_23 ;
* V_109 = V_102 ;
return 0 ;
}
static inline void *
F_45 ( V_96 V_110 , unsigned V_111 , unsigned V_13 )
{
void * V_33 ;
void T_3 * V_112 = ( void V_100 T_3 * ) ( V_101 ) V_110 ;
V_33 = F_46 ( V_111 * V_13 , V_113 ) ;
if ( ! V_33 )
return F_47 ( - V_34 ) ;
if ( F_48 ( V_33 , V_112 , V_111 * V_13 ) ) {
F_7 ( V_33 ) ;
return F_47 ( - V_107 ) ;
}
return V_33 ;
}
static int
F_49 ( struct V_9 * V_10 ,
struct V_114 * V_50 ,
struct V_82 * V_7 )
{
struct V_115 * V_116 = NULL ;
int V_23 = 0 ;
unsigned V_87 ;
V_116 = F_45 ( V_50 -> V_102 , V_50 -> V_117 , sizeof( * V_116 ) ) ;
if ( F_17 ( V_116 ) )
return F_18 ( V_116 ) ;
for ( V_87 = 0 ; V_87 < V_50 -> V_117 ; V_87 ++ ) {
struct V_115 * V_118 = & V_116 [ V_87 ] ;
struct V_82 * V_91 ;
struct V_3 * V_4 ;
T_1 V_46 ;
if ( F_3 ( V_118 -> V_119 > V_50 -> V_84 ) ) {
F_15 ( V_10 , L_16 ) ;
V_23 = - V_58 ;
break;
}
V_91 = & V_7 [ V_118 -> V_119 ] ;
if ( V_91 -> V_105 . V_106 )
continue;
if ( F_3 ( V_118 -> V_120 > V_50 -> V_84 ) ) {
F_15 ( V_10 , L_17 ) ;
V_23 = - V_58 ;
break;
}
V_4 = ( void * ) ( unsigned long ) V_7 [ V_118 -> V_120 ] . V_95 ;
if ( F_3 ( V_118 -> V_121 + 4 >
V_4 -> V_7 . V_33 . V_41 << V_42 ) ) {
F_15 ( V_10 , L_18 ) ;
V_23 = - V_58 ;
break;
}
if ( ! V_4 -> V_75 . V_122 ) {
V_23 = F_50 ( & V_4 -> V_7 , 0 , V_4 -> V_7 . V_33 . V_41 ,
& V_4 -> V_75 ) ;
if ( V_23 ) {
F_15 ( V_10 , L_19 ) ;
break;
}
V_4 -> V_74 = true ;
}
if ( V_118 -> V_22 & V_123 )
V_46 = V_91 -> V_105 . V_43 + V_118 -> V_46 ;
else
if ( V_118 -> V_22 & V_124 )
V_46 = ( V_91 -> V_105 . V_43 + V_118 -> V_46 ) >> 32 ;
else
V_46 = V_118 -> V_46 ;
if ( V_118 -> V_22 & V_125 ) {
if ( V_91 -> V_105 . V_15 == V_26 )
V_46 |= V_118 -> V_126 ;
else
V_46 |= V_118 -> V_127 ;
}
F_51 ( & V_4 -> V_7 . V_52 -> V_128 ) ;
V_23 = F_52 ( & V_4 -> V_7 , false , false , false ) ;
F_53 ( & V_4 -> V_7 . V_52 -> V_128 ) ;
if ( V_23 ) {
F_15 ( V_10 , L_20 , V_23 ) ;
break;
}
F_54 ( V_4 , V_118 -> V_121 >> 2 , V_46 ) ;
}
F_7 ( V_116 ) ;
return V_23 ;
}
int
F_55 ( struct V_9 * V_10 , void * V_46 ,
struct V_47 * V_48 )
{
struct V_19 * V_20 = V_10 -> V_21 ;
struct V_114 * V_50 = V_46 ;
struct V_129 * V_130 ;
struct V_82 * V_7 ;
struct V_11 * V_12 ;
struct V_77 V_78 ;
struct V_70 * V_71 = NULL ;
int V_87 , V_131 , V_23 = 0 , V_132 = 0 ;
V_12 = F_16 ( V_10 , V_48 , V_50 -> V_104 ) ;
if ( F_17 ( V_12 ) )
return F_18 ( V_12 ) ;
V_50 -> V_133 = V_20 -> V_134 ;
V_50 -> V_135 = V_20 -> V_136 . V_137 ;
if ( F_3 ( V_50 -> V_138 == 0 ) )
goto V_139;
if ( F_3 ( V_50 -> V_138 > V_140 ) ) {
F_15 ( V_10 , L_21 ,
V_50 -> V_138 , V_140 ) ;
F_19 ( & V_12 ) ;
return - V_58 ;
}
if ( F_3 ( V_50 -> V_84 > V_141 ) ) {
F_15 ( V_10 , L_22 ,
V_50 -> V_84 , V_141 ) ;
F_19 ( & V_12 ) ;
return - V_58 ;
}
if ( F_3 ( V_50 -> V_117 > V_142 ) ) {
F_15 ( V_10 , L_23 ,
V_50 -> V_117 , V_142 ) ;
F_19 ( & V_12 ) ;
return - V_58 ;
}
V_130 = F_45 ( V_50 -> V_130 , V_50 -> V_138 , sizeof( * V_130 ) ) ;
if ( F_17 ( V_130 ) ) {
F_19 ( & V_12 ) ;
return F_18 ( V_130 ) ;
}
V_7 = F_45 ( V_50 -> V_143 , V_50 -> V_84 , sizeof( * V_7 ) ) ;
if ( F_17 ( V_7 ) ) {
F_7 ( V_130 ) ;
F_19 ( & V_12 ) ;
return F_18 ( V_7 ) ;
}
for ( V_87 = 0 ; V_87 < V_50 -> V_138 ; V_87 ++ ) {
if ( V_130 [ V_87 ] . V_119 >= V_50 -> V_84 ) {
F_15 ( V_10 , L_24 , V_87 ) ;
V_23 = - V_58 ;
goto V_144;
}
V_7 [ V_130 [ V_87 ] . V_119 ] . V_62 |= ( 1 << 31 ) ;
}
V_23 = F_43 ( V_12 , V_48 , V_7 , V_50 -> V_143 ,
V_50 -> V_84 , & V_78 , & V_132 ) ;
if ( V_23 ) {
if ( V_23 != - V_94 )
F_15 ( V_10 , L_25 , V_23 ) ;
goto V_144;
}
if ( V_132 ) {
V_23 = F_49 ( V_10 , V_50 , V_7 ) ;
if ( V_23 ) {
F_15 ( V_10 , L_26 , V_23 ) ;
goto V_60;
}
}
if ( V_12 -> V_145 . V_146 ) {
V_23 = F_56 ( V_12 , V_50 -> V_138 + 1 , 6 ) ;
if ( V_23 ) {
F_57 ( V_10 , L_27 , V_23 ) ;
goto V_60;
}
for ( V_87 = 0 ; V_87 < V_50 -> V_138 ; V_87 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_130 [ V_87 ] . V_119 ] . V_95 ;
F_58 ( V_12 , V_4 , V_130 [ V_87 ] . V_43 ,
V_130 [ V_87 ] . V_147 ) ;
}
} else
if ( V_20 -> V_148 >= 0x25 ) {
V_23 = F_59 ( V_12 , V_50 -> V_138 * 2 ) ;
if ( V_23 ) {
F_15 ( V_10 , L_28 , V_23 ) ;
goto V_60;
}
for ( V_87 = 0 ; V_87 < V_50 -> V_138 ; V_87 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_130 [ V_87 ] . V_119 ] . V_95 ;
struct V_149 * V_33 = V_4 -> V_7 . V_33 . V_150 ;
F_60 ( V_12 , ( ( V_33 -> V_151 << V_42 ) +
V_130 [ V_87 ] . V_43 ) | 2 ) ;
F_60 ( V_12 , 0 ) ;
}
} else {
V_23 = F_59 ( V_12 , V_50 -> V_138 * ( 2 + V_152 ) ) ;
if ( V_23 ) {
F_15 ( V_10 , L_29 , V_23 ) ;
goto V_60;
}
for ( V_87 = 0 ; V_87 < V_50 -> V_138 ; V_87 ++ ) {
struct V_3 * V_4 = ( void * ) ( unsigned long )
V_7 [ V_130 [ V_87 ] . V_119 ] . V_95 ;
struct V_149 * V_33 = V_4 -> V_7 . V_33 . V_150 ;
T_1 V_153 ;
V_153 = V_12 -> V_154 + ( ( V_12 -> V_145 . V_155 + 2 ) << 2 ) ;
V_153 |= 0x20000000 ;
if ( F_3 ( V_153 != V_50 -> V_156 ) ) {
if ( ! V_4 -> V_75 . V_122 ) {
V_23 = F_50 ( & V_4 -> V_7 , 0 ,
V_4 -> V_7 . V_33 .
V_41 ,
& V_4 -> V_75 ) ;
if ( V_23 ) {
F_61 ( V_12 ) ;
goto V_60;
}
V_4 -> V_74 = true ;
}
F_54 ( V_4 , ( V_130 [ V_87 ] . V_43 +
V_130 [ V_87 ] . V_147 - 8 ) / 4 , V_153 ) ;
}
F_60 ( V_12 , ( ( V_33 -> V_151 << V_42 ) +
V_130 [ V_87 ] . V_43 ) | 0x20000000 ) ;
F_60 ( V_12 , 0 ) ;
for ( V_131 = 0 ; V_131 < V_152 ; V_131 ++ )
F_60 ( V_12 , 0 ) ;
}
}
V_23 = F_62 ( V_12 , & V_71 , true ) ;
if ( V_23 ) {
F_15 ( V_10 , L_30 , V_23 ) ;
F_61 ( V_12 ) ;
goto V_60;
}
V_60:
F_31 ( & V_78 , V_71 ) ;
F_63 ( & V_71 ) ;
V_144:
F_7 ( V_7 ) ;
F_7 ( V_130 ) ;
V_139:
if ( V_12 -> V_145 . V_146 ) {
V_50 -> V_156 = 0x00000000 ;
V_50 -> V_157 = 0x00000000 ;
} else
if ( V_20 -> V_148 >= 0x25 ) {
V_50 -> V_156 = 0x00020000 ;
V_50 -> V_157 = 0x00000000 ;
} else {
V_50 -> V_156 = 0x20000000 |
( V_12 -> V_154 + ( ( V_12 -> V_145 . V_155 + 2 ) << 2 ) ) ;
V_50 -> V_157 = 0x00000000 ;
}
F_19 ( & V_12 ) ;
return V_23 ;
}
static inline T_1
F_64 ( struct V_3 * V_4 , T_1 V_15 )
{
T_1 V_22 = 0 ;
if ( V_15 & V_24 )
V_22 |= V_25 ;
if ( V_15 & V_26 )
V_22 |= V_27 ;
return V_22 ;
}
int
F_65 ( struct V_9 * V_10 , void * V_46 ,
struct V_47 * V_48 )
{
struct V_158 * V_50 = V_46 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
bool V_159 = ! ! ( V_50 -> V_22 & V_160 ) ;
int V_23 = - V_58 ;
V_2 = F_34 ( V_10 , V_48 , V_50 -> V_61 ) ;
if ( ! V_2 )
return - V_92 ;
V_4 = F_13 ( V_2 ) ;
F_51 ( & V_4 -> V_7 . V_52 -> V_128 ) ;
V_23 = F_52 ( & V_4 -> V_7 , true , true , V_159 ) ;
F_53 ( & V_4 -> V_7 . V_52 -> V_128 ) ;
F_21 ( V_2 ) ;
return V_23 ;
}
int
F_66 ( struct V_9 * V_10 , void * V_46 ,
struct V_47 * V_48 )
{
return 0 ;
}
int
F_67 ( struct V_9 * V_10 , void * V_46 ,
struct V_47 * V_48 )
{
struct V_37 * V_50 = V_46 ;
struct V_1 * V_2 ;
int V_23 ;
V_2 = F_34 ( V_10 , V_48 , V_50 -> V_61 ) ;
if ( ! V_2 )
return - V_92 ;
V_23 = F_12 ( V_2 , V_50 ) ;
F_21 ( V_2 ) ;
return V_23 ;
}
