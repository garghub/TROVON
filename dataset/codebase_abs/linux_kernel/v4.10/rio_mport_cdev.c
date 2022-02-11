static int F_1 ( struct V_1 * V_2 , void T_1 * V_3 ,
int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_6 ;
struct V_8 V_9 ;
T_2 * V_10 ;
T_2 V_11 ;
T_3 V_12 ;
int V_13 , V_14 ;
if ( F_2 ( F_3 ( & V_9 , V_3 , sizeof( V_9 ) ) ) )
return - V_15 ;
if ( ( V_9 . V_11 % 4 ) ||
( V_9 . V_12 == 0 ) || ( V_9 . V_12 % 4 ) ||
( V_9 . V_12 + V_9 . V_11 ) > V_16 )
return - V_17 ;
V_10 = F_4 ( V_9 . V_12 ) ;
if ( V_10 == NULL )
return - V_18 ;
V_12 = V_9 . V_12 / sizeof( T_2 ) ;
V_11 = V_9 . V_11 ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ ) {
if ( V_4 )
V_13 = F_5 ( V_6 ,
V_11 , & V_10 [ V_14 ] ) ;
else
V_13 = F_6 ( V_6 , V_9 . V_19 ,
V_9 . V_20 , V_11 , & V_10 [ V_14 ] ) ;
if ( V_13 )
goto V_21;
V_11 += 4 ;
}
if ( F_2 ( F_7 ( ( void T_1 * ) ( V_22 ) V_9 . V_10 ,
V_10 , V_9 . V_12 ) ) )
V_13 = - V_15 ;
V_21:
F_8 ( V_10 ) ;
return V_13 ;
}
static int F_9 ( struct V_1 * V_2 , void T_1 * V_3 ,
int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_6 ;
struct V_8 V_9 ;
T_2 * V_10 ;
T_2 V_11 ;
T_3 V_12 ;
int V_13 = - V_17 , V_14 ;
if ( F_2 ( F_3 ( & V_9 , V_3 , sizeof( V_9 ) ) ) )
return - V_15 ;
if ( ( V_9 . V_11 % 4 ) ||
( V_9 . V_12 == 0 ) || ( V_9 . V_12 % 4 ) ||
( V_9 . V_12 + V_9 . V_11 ) > V_16 )
return - V_17 ;
V_10 = F_4 ( V_9 . V_12 ) ;
if ( V_10 == NULL )
return - V_18 ;
V_12 = V_9 . V_12 ;
if ( F_2 ( F_3 ( V_10 ,
( void T_1 * ) ( V_22 ) V_9 . V_10 , V_12 ) ) ) {
V_13 = - V_15 ;
goto V_21;
}
V_11 = V_9 . V_11 ;
V_12 /= sizeof( T_2 ) ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ ) {
if ( V_4 )
V_13 = F_10 ( V_6 ,
V_11 , V_10 [ V_14 ] ) ;
else
V_13 = F_11 ( V_6 , V_9 . V_19 ,
V_9 . V_20 ,
V_11 , V_10 [ V_14 ] ) ;
if ( V_13 )
goto V_21;
V_11 += 4 ;
}
V_21:
F_8 ( V_10 ) ;
return V_13 ;
}
static int
F_12 ( struct V_23 * V_7 , struct V_24 * V_25 ,
T_4 V_19 , T_5 V_26 , T_2 V_27 ,
T_6 * V_28 )
{
struct V_5 * V_6 = V_7 -> V_6 ;
struct V_29 * V_30 ;
int V_13 ;
F_13 ( V_31 , L_1 , V_19 , V_26 , V_27 ) ;
V_30 = F_14 ( sizeof( * V_30 ) , V_32 ) ;
if ( V_30 == NULL )
return - V_18 ;
V_13 = F_15 ( V_6 , V_19 , V_26 , V_27 , 0 , V_28 ) ;
if ( V_13 < 0 )
goto V_33;
V_30 -> V_34 = V_35 ;
V_30 -> V_19 = V_19 ;
V_30 -> V_36 = V_26 ;
V_30 -> V_27 = V_27 ;
V_30 -> V_37 = * V_28 ;
V_30 -> V_25 = V_25 ;
V_30 -> V_7 = V_7 ;
F_16 ( & V_30 -> V_38 ) ;
F_17 ( & V_30 -> V_39 , & V_7 -> V_40 ) ;
return 0 ;
V_33:
F_18 ( V_30 ) ;
return V_13 ;
}
static int
F_19 ( struct V_23 * V_7 , struct V_24 * V_25 ,
T_4 V_19 , T_5 V_26 , T_2 V_27 ,
T_6 * V_28 )
{
struct V_29 * V_30 ;
int V_41 = - V_18 ;
F_20 ( & V_7 -> V_42 ) ;
F_21 (map, &md->mappings, node) {
if ( V_30 -> V_34 != V_35 )
continue;
if ( V_19 == V_30 -> V_19 &&
V_26 == V_30 -> V_36 && V_27 == V_30 -> V_27 ) {
* V_28 = V_30 -> V_37 ;
V_41 = 0 ;
break;
} else if ( V_19 == V_30 -> V_19 &&
V_26 < ( V_30 -> V_36 + V_30 -> V_27 - 1 ) &&
( V_26 + V_27 ) > V_30 -> V_36 ) {
V_41 = - V_43 ;
break;
}
}
if ( V_41 == - V_18 )
V_41 = F_12 ( V_7 , V_25 , V_19 , V_26 ,
V_27 , V_28 ) ;
F_22 ( & V_7 -> V_42 ) ;
return V_41 ;
}
static int F_23 ( struct V_24 * V_25 , void T_1 * V_3 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
struct V_23 * V_45 = V_2 -> V_7 ;
struct V_46 V_30 ;
T_6 V_28 ;
int V_13 ;
if ( F_2 ( F_3 ( & V_30 , V_3 , sizeof( V_30 ) ) ) )
return - V_15 ;
F_13 ( V_31 , L_2 ,
V_30 . V_19 , V_30 . V_36 , V_30 . V_12 ) ;
V_13 = F_19 ( V_45 , V_25 , V_30 . V_19 ,
V_30 . V_36 , V_30 . V_12 , & V_28 ) ;
if ( V_13 < 0 ) {
F_24 ( L_3 , V_13 ) ;
return V_13 ;
}
V_30 . V_47 = V_28 ;
if ( F_2 ( F_7 ( V_3 , & V_30 , sizeof( V_30 ) ) ) )
return - V_15 ;
return 0 ;
}
static int F_25 ( struct V_24 * V_25 , void T_1 * V_3 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
struct V_23 * V_7 = V_2 -> V_7 ;
T_5 V_47 ;
struct V_29 * V_30 , * V_48 ;
if ( ! V_7 -> V_6 -> V_49 -> V_50 )
return - V_51 ;
if ( F_3 ( & V_47 , V_3 , sizeof( V_47 ) ) )
return - V_15 ;
F_13 ( V_31 , L_4 , V_47 ) ;
F_20 ( & V_7 -> V_42 ) ;
F_26 (map, _map, &md->mappings, node) {
if ( V_30 -> V_34 == V_35 && V_30 -> V_37 == V_47 ) {
if ( V_30 -> V_25 == V_25 ) {
F_13 ( V_31 , L_5 , V_47 ) ;
V_30 -> V_25 = NULL ;
F_27 ( & V_30 -> V_38 , V_52 ) ;
}
break;
}
}
F_22 ( & V_7 -> V_42 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , void T_1 * V_3 )
{
struct V_23 * V_7 = V_2 -> V_7 ;
T_4 V_53 ;
if ( F_3 ( & V_53 , V_3 , sizeof( V_53 ) ) )
return - V_15 ;
V_7 -> V_6 -> V_54 = V_53 ;
V_7 -> V_55 . V_53 = V_53 ;
F_29 ( V_7 -> V_6 , V_53 ) ;
F_13 ( V_56 , L_6 , V_53 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , void T_1 * V_3 )
{
struct V_23 * V_7 = V_2 -> V_7 ;
T_2 V_57 ;
if ( F_3 ( & V_57 , V_3 , sizeof( V_57 ) ) )
return - V_15 ;
F_31 ( V_7 -> V_6 , V_58 , V_57 ) ;
F_13 ( V_56 , L_7 , V_57 ) ;
return 0 ;
}
static void F_32 ( struct V_59 * V_60 )
{
struct V_23 * V_7 =
F_33 ( V_60 , struct V_23 , V_60 ) ;
F_13 ( EXIT , L_8 , V_7 -> V_61 -> V_62 ) ;
F_34 ( V_7 -> V_61 ) ;
V_7 -> V_61 = NULL ;
}
static void F_35 ( struct V_59 * V_60 )
{
struct V_1 * V_2 =
F_33 ( V_60 , struct V_1 , V_60 ) ;
F_13 ( EXIT , L_8 , V_2 -> V_63 -> V_62 ) ;
F_36 ( & V_2 -> V_64 ) ;
}
static void F_37 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
unsigned int V_14 ;
F_38 ( V_66 -> V_63 -> V_67 -> V_68 ,
V_66 -> V_69 . V_70 , V_66 -> V_69 . V_71 , V_66 -> V_34 ) ;
F_39 ( & V_66 -> V_69 ) ;
if ( V_66 -> V_72 ) {
for ( V_14 = 0 ; V_14 < V_66 -> V_73 ; V_14 ++ )
F_40 ( V_66 -> V_72 [ V_14 ] ) ;
F_18 ( V_66 -> V_72 ) ;
}
if ( V_66 -> V_30 ) {
F_20 ( & V_66 -> V_30 -> V_7 -> V_42 ) ;
F_27 ( & V_66 -> V_30 -> V_38 , V_52 ) ;
F_22 ( & V_66 -> V_30 -> V_7 -> V_42 ) ;
}
F_27 ( & V_2 -> V_60 , F_35 ) ;
F_18 ( V_66 ) ;
}
static void F_41 ( void * V_74 )
{
struct V_65 * V_66 = (struct V_65 * ) V_74 ;
struct V_1 * V_2 = V_66 -> V_2 ;
V_66 -> V_75 = F_42 ( V_2 -> V_63 , V_66 -> V_76 ,
NULL , NULL ) ;
F_36 ( & V_66 -> V_77 ) ;
}
static void F_43 ( struct V_78 * V_79 )
{
struct V_80 * V_81 = F_33 ( V_79 ,
struct V_80 , V_81 ) ;
struct V_65 * V_66 = V_81 -> V_66 ;
F_37 ( V_66 ) ;
F_18 ( V_81 ) ;
}
static void F_44 ( void * V_74 )
{
struct V_65 * V_66 = (struct V_65 * ) V_74 ;
struct V_80 * V_81 ;
V_81 = F_45 ( sizeof( * V_81 ) , V_82 ) ;
if ( ! V_81 )
return;
F_46 ( & V_81 -> V_81 , F_43 ) ;
V_81 -> V_66 = V_66 ;
F_47 ( V_83 , & V_81 -> V_81 ) ;
}
static struct V_84
* F_48 ( struct V_61 * V_85 , struct V_86 * V_87 ,
struct V_88 * V_69 , int V_71 , enum V_89 V_34 ,
enum V_90 V_91 )
{
struct V_92 V_93 ;
V_93 . V_94 = V_69 -> V_70 ;
V_93 . V_95 = V_71 ;
V_93 . V_96 = 0 ;
V_93 . V_36 = V_87 -> V_36 ;
if ( V_34 == V_97 ) {
switch ( V_87 -> V_98 ) {
case V_99 :
V_93 . V_100 = V_101 ;
break;
case V_102 :
V_93 . V_100 = V_103 ;
break;
case V_104 :
V_93 . V_100 = V_105 ;
break;
case V_106 :
V_93 . V_100 = V_107 ;
break;
default:
return F_49 ( - V_17 ) ;
}
}
return F_50 ( V_85 , V_87 -> V_19 , & V_93 , V_34 , V_91 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
F_20 ( & V_2 -> V_108 ) ;
if ( ! V_2 -> V_63 ) {
V_2 -> V_63 = F_52 ( V_2 -> V_7 -> V_6 ) ;
if ( ! V_2 -> V_63 ) {
if ( V_2 -> V_7 -> V_61 ) {
V_2 -> V_63 = V_2 -> V_7 -> V_61 ;
F_53 ( & V_2 -> V_7 -> V_60 ) ;
} else {
F_24 ( L_9 ) ;
F_22 ( & V_2 -> V_108 ) ;
return - V_109 ;
}
} else if ( ! V_2 -> V_7 -> V_61 ) {
V_2 -> V_7 -> V_61 = V_2 -> V_63 ;
F_16 ( & V_2 -> V_7 -> V_60 ) ;
F_13 ( V_110 , L_10 ,
V_2 -> V_63 -> V_62 ) ;
}
F_16 ( & V_2 -> V_60 ) ;
F_54 ( & V_2 -> V_64 ) ;
}
F_53 ( & V_2 -> V_60 ) ;
F_22 ( & V_2 -> V_108 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_60 , F_35 ) ;
}
static int F_56 ( struct V_65 * V_66 ,
struct V_86 * V_111 ,
enum V_112 V_113 , int V_71 )
{
struct V_1 * V_2 ;
struct V_88 * V_69 ;
struct V_61 * V_85 ;
struct V_84 * V_114 ;
T_7 V_76 ;
unsigned long V_115 = F_57 ( V_116 ) ;
enum V_89 V_34 ;
long V_117 ;
int V_13 = 0 ;
V_2 = V_66 -> V_2 ;
V_69 = & V_66 -> V_69 ;
V_85 = V_2 -> V_63 ;
V_34 = ( V_66 -> V_34 == V_118 ) ? V_119 : V_97 ;
F_13 ( V_110 , L_11 ,
V_120 -> V_121 , F_58 ( V_120 ) ,
F_59 ( & V_85 -> V_68 -> V_67 ) ,
( V_34 == V_119 ) ? L_12 : L_13 ) ;
V_114 = F_48 ( V_85 , V_111 , V_69 , V_71 , V_34 ,
V_122 | V_123 ) ;
if ( ! V_114 ) {
F_13 ( V_110 , L_14 ,
( V_34 == V_119 ) ? L_12 : L_13 ,
V_111 -> V_36 , V_111 -> V_12 ) ;
V_13 = - V_124 ;
goto V_125;
} else if ( F_60 ( V_114 ) ) {
V_13 = F_61 ( V_114 ) ;
F_13 ( V_110 , L_15 , V_13 ,
( V_34 == V_119 ) ? L_12 : L_13 ,
V_111 -> V_36 , V_111 -> V_12 ) ;
goto V_125;
}
if ( V_113 == V_126 )
V_114 -> V_127 = F_44 ;
else
V_114 -> V_127 = F_41 ;
V_114 -> V_128 = V_66 ;
V_66 -> V_63 = V_85 ;
V_66 -> V_113 = V_113 ;
V_66 -> V_75 = V_129 ;
F_54 ( & V_66 -> V_77 ) ;
V_76 = F_62 ( V_114 ) ;
V_66 -> V_76 = V_76 ;
F_13 ( V_110 , L_16 , F_58 ( V_120 ) ,
( V_34 == V_119 ) ? L_12 : L_13 , V_76 ) ;
if ( F_63 ( V_76 ) ) {
F_24 ( L_17 ,
V_76 , V_111 -> V_36 , V_111 -> V_12 ) ;
V_13 = - V_124 ;
goto V_125;
}
F_64 ( V_85 ) ;
if ( V_113 == V_130 ) {
F_65 ( & V_2 -> V_131 ) ;
F_17 ( & V_66 -> V_39 , & V_2 -> V_132 ) ;
F_66 ( & V_2 -> V_131 ) ;
return V_76 ;
} else if ( V_113 == V_126 )
return 0 ;
V_117 = F_67 ( & V_66 -> V_77 , V_115 ) ;
if ( V_117 == 0 ) {
F_24 ( L_18 ,
V_120 -> V_121 , F_58 ( V_120 ) ,
( V_34 == V_119 ) ? L_12 : L_13 , V_76 ) ;
return - V_133 ;
} else if ( V_117 == - V_134 ) {
F_24 ( L_19 ,
V_120 -> V_121 , F_58 ( V_120 ) ,
( V_34 == V_119 ) ? L_12 : L_13 , V_76 ) ;
return - V_135 ;
}
if ( V_66 -> V_75 != V_136 ) {
F_24 ( L_20 ,
V_120 -> V_121 , F_58 ( V_120 ) ,
( V_34 == V_119 ) ? L_12 : L_13 ,
V_76 , V_66 -> V_75 , V_13 ) ;
V_13 = - V_124 ;
}
V_125:
return V_13 ;
}
static int
F_68 ( struct V_24 * V_25 , T_2 V_137 ,
enum V_112 V_113 , enum V_138 V_34 ,
struct V_86 * V_111 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
unsigned long V_73 = 0 ;
struct V_139 * * V_72 = NULL ;
struct V_65 * V_66 ;
struct V_23 * V_7 = V_2 -> V_7 ;
struct V_61 * V_85 ;
int V_14 , V_13 ;
int V_71 ;
if ( V_111 -> V_12 == 0 )
return - V_17 ;
V_66 = F_14 ( sizeof( * V_66 ) , V_32 ) ;
if ( ! V_66 )
return - V_18 ;
V_13 = F_51 ( V_2 ) ;
if ( V_13 ) {
F_18 ( V_66 ) ;
return V_13 ;
}
if ( V_111 -> V_140 ) {
unsigned long V_11 ;
long V_141 ;
V_11 = ( unsigned long ) ( V_22 ) V_111 -> V_140 & ~ V_142 ;
V_73 = F_69 ( V_111 -> V_12 + V_11 ) >> V_143 ;
V_72 = F_70 ( V_73 ,
sizeof( * V_72 ) , V_32 ) ;
if ( V_72 == NULL ) {
V_13 = - V_18 ;
goto V_144;
}
F_71 ( & V_120 -> V_145 -> V_146 ) ;
V_141 = F_72 (
( unsigned long ) V_111 -> V_140 & V_142 ,
V_73 ,
V_34 == V_118 ? V_147 : 0 ,
V_72 , NULL ) ;
F_73 ( & V_120 -> V_145 -> V_146 ) ;
if ( V_141 != V_73 ) {
if ( V_141 < 0 ) {
F_24 ( L_21 , V_141 ) ;
V_73 = 0 ;
} else
F_24 ( L_22 ,
V_141 , V_73 ) ;
V_13 = - V_15 ;
goto V_148;
}
V_13 = F_74 ( & V_66 -> V_69 , V_72 , V_73 ,
V_11 , V_111 -> V_12 , V_32 ) ;
if ( V_13 ) {
F_24 ( L_23 , V_13 ) ;
goto V_148;
}
V_66 -> V_72 = V_72 ;
V_66 -> V_73 = V_73 ;
} else {
T_6 V_149 ;
struct V_29 * V_30 ;
V_149 = ( T_6 ) V_111 -> V_47 ;
F_20 ( & V_7 -> V_42 ) ;
F_21 (map, &md->mappings, node) {
if ( V_149 >= V_30 -> V_37 &&
V_149 < ( V_30 -> V_37 + V_30 -> V_27 ) ) {
F_53 ( & V_30 -> V_38 ) ;
V_66 -> V_30 = V_30 ;
break;
}
}
F_22 ( & V_7 -> V_42 ) ;
if ( V_66 -> V_30 == NULL ) {
V_13 = - V_18 ;
goto V_144;
}
if ( V_111 -> V_12 + V_111 -> V_11 > V_30 -> V_27 ) {
V_13 = - V_17 ;
goto V_144;
}
V_13 = F_75 ( & V_66 -> V_69 , 1 , V_32 ) ;
if ( F_2 ( V_13 ) ) {
F_24 ( L_24 ) ;
goto V_144;
}
F_76 ( V_66 -> V_69 . V_70 ,
V_30 -> V_150 + ( V_149 - V_30 -> V_37 ) +
V_111 -> V_11 , V_111 -> V_12 ) ;
}
V_66 -> V_34 = V_34 ;
V_66 -> V_25 = V_25 ;
V_66 -> V_2 = V_2 ;
V_85 = V_2 -> V_63 ;
V_71 = F_77 ( V_85 -> V_67 -> V_68 ,
V_66 -> V_69 . V_70 , V_66 -> V_69 . V_71 , V_34 ) ;
if ( V_71 == - V_15 ) {
F_24 ( L_25 ) ;
return - V_15 ;
}
V_13 = F_56 ( V_66 , V_111 , V_113 , V_71 ) ;
if ( V_13 >= 0 ) {
if ( V_113 == V_151 )
goto V_152;
return V_13 ;
}
if ( V_13 == - V_133 || V_13 == - V_135 ) {
F_65 ( & V_2 -> V_131 ) ;
F_17 ( & V_66 -> V_39 , & V_2 -> V_153 ) ;
F_66 ( & V_2 -> V_131 ) ;
return V_13 ;
}
F_13 ( V_110 , L_26 , V_13 ) ;
V_152:
F_38 ( V_85 -> V_67 -> V_68 , V_66 -> V_69 . V_70 , V_66 -> V_69 . V_71 , V_34 ) ;
F_39 ( & V_66 -> V_69 ) ;
V_148:
if ( V_72 ) {
for ( V_14 = 0 ; V_14 < V_73 ; V_14 ++ )
F_40 ( V_72 [ V_14 ] ) ;
F_18 ( V_72 ) ;
}
V_144:
if ( V_66 -> V_30 ) {
F_20 ( & V_7 -> V_42 ) ;
F_27 ( & V_66 -> V_30 -> V_38 , V_52 ) ;
F_22 ( & V_7 -> V_42 ) ;
}
F_55 ( V_2 ) ;
F_18 ( V_66 ) ;
return V_13 ;
}
static int F_78 ( struct V_24 * V_25 , void T_1 * V_3 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
struct V_154 V_155 ;
struct V_86 * V_87 ;
enum V_138 V_34 ;
int V_14 , V_13 = 0 ;
if ( F_2 ( F_3 ( & V_155 , V_3 , sizeof( V_155 ) ) ) )
return - V_15 ;
if ( V_155 . V_156 != 1 )
return - V_17 ;
if ( ( V_155 . V_137 &
V_2 -> V_7 -> V_55 . V_137 ) == 0 )
return - V_109 ;
V_87 = F_4 ( V_155 . V_156 * sizeof( * V_87 ) ) ;
if ( ! V_87 )
return - V_18 ;
if ( F_2 ( F_3 ( V_87 ,
( void T_1 * ) ( V_22 ) V_155 . V_157 ,
V_155 . V_156 * sizeof( * V_87 ) ) ) ) {
V_13 = - V_15 ;
goto V_158;
}
V_34 = ( V_155 . V_34 == V_159 ) ?
V_118 : V_160 ;
for ( V_14 = 0 ; V_14 < V_155 . V_156 && V_13 == 0 ; V_14 ++ )
V_13 = F_68 ( V_25 , V_155 . V_137 ,
V_155 . V_113 , V_34 , & V_87 [ V_14 ] ) ;
if ( F_2 ( F_7 ( ( void T_1 * ) ( V_22 ) V_155 . V_157 ,
V_87 ,
V_155 . V_156 * sizeof( * V_87 ) ) ) )
V_13 = - V_15 ;
V_158:
F_8 ( V_87 ) ;
return V_13 ;
}
static int F_79 ( struct V_24 * V_25 , void T_1 * V_3 )
{
struct V_1 * V_2 ;
struct V_23 * V_7 ;
struct V_161 V_162 ;
struct V_65 * V_66 ;
T_7 V_76 ;
unsigned long V_115 ;
long V_117 ;
int V_163 = 0 ;
int V_13 ;
V_2 = (struct V_1 * ) V_25 -> V_44 ;
V_7 = V_2 -> V_7 ;
if ( F_2 ( F_3 ( & V_162 , V_3 , sizeof( V_162 ) ) ) )
return - V_15 ;
V_76 = V_162 . V_164 ;
if ( V_162 . V_165 )
V_115 = F_57 ( V_162 . V_165 ) ;
else
V_115 = F_57 ( V_116 ) ;
F_65 ( & V_2 -> V_131 ) ;
F_21 (req, &priv->async_list, node) {
if ( V_66 -> V_76 == V_76 ) {
F_80 ( & V_66 -> V_39 ) ;
V_163 = 1 ;
break;
}
}
F_66 ( & V_2 -> V_131 ) ;
if ( ! V_163 )
return - V_166 ;
V_117 = F_67 ( & V_66 -> V_77 , V_115 ) ;
if ( V_117 == 0 ) {
F_24 ( L_27 ,
V_120 -> V_121 , F_58 ( V_120 ) ,
( V_66 -> V_34 == V_118 ) ? L_12 : L_13 ) ;
V_13 = - V_133 ;
goto V_167;
} else if ( V_117 == - V_134 ) {
F_24 ( L_28 ,
V_120 -> V_121 , F_58 ( V_120 ) ,
( V_66 -> V_34 == V_118 ) ? L_12 : L_13 ) ;
V_13 = - V_135 ;
goto V_167;
}
if ( V_66 -> V_75 != V_136 ) {
F_24 ( L_29 ,
V_120 -> V_121 , F_58 ( V_120 ) ,
( V_66 -> V_34 == V_118 ) ? L_12 : L_13 ,
V_66 -> V_75 ) ;
V_13 = - V_124 ;
} else
V_13 = 0 ;
if ( V_66 -> V_75 != V_129 && V_66 -> V_75 != V_168 )
F_37 ( V_66 ) ;
return V_13 ;
V_167:
F_65 ( & V_2 -> V_131 ) ;
F_17 ( & V_66 -> V_39 , & V_2 -> V_132 ) ;
F_66 ( & V_2 -> V_131 ) ;
return V_13 ;
}
static int F_81 ( struct V_23 * V_7 , struct V_24 * V_25 ,
T_5 V_27 , struct V_29 * * V_169 )
{
struct V_29 * V_30 ;
V_30 = F_14 ( sizeof( * V_30 ) , V_32 ) ;
if ( V_30 == NULL )
return - V_18 ;
V_30 -> V_150 = F_82 ( V_7 -> V_6 -> V_68 . V_170 , V_27 ,
& V_30 -> V_37 , V_32 ) ;
if ( V_30 -> V_150 == NULL ) {
F_18 ( V_30 ) ;
return - V_18 ;
}
V_30 -> V_34 = V_171 ;
V_30 -> V_27 = V_27 ;
V_30 -> V_25 = V_25 ;
V_30 -> V_7 = V_7 ;
F_16 ( & V_30 -> V_38 ) ;
F_20 ( & V_7 -> V_42 ) ;
F_17 ( & V_30 -> V_39 , & V_7 -> V_40 ) ;
F_22 ( & V_7 -> V_42 ) ;
* V_169 = V_30 ;
return 0 ;
}
static int F_83 ( struct V_24 * V_25 , void T_1 * V_3 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
struct V_23 * V_7 = V_2 -> V_7 ;
struct V_172 V_30 ;
struct V_29 * V_169 = NULL ;
int V_13 ;
if ( F_2 ( F_3 ( & V_30 , V_3 , sizeof( V_30 ) ) ) )
return - V_15 ;
V_13 = F_81 ( V_7 , V_25 , V_30 . V_12 , & V_169 ) ;
if ( V_13 )
return V_13 ;
V_30 . V_173 = V_169 -> V_37 ;
if ( F_2 ( F_7 ( V_3 , & V_30 , sizeof( V_30 ) ) ) ) {
F_20 ( & V_7 -> V_42 ) ;
F_27 ( & V_169 -> V_38 , V_52 ) ;
F_22 ( & V_7 -> V_42 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_84 ( struct V_24 * V_25 , void T_1 * V_3 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
struct V_23 * V_7 = V_2 -> V_7 ;
T_5 V_47 ;
int V_13 = - V_15 ;
struct V_29 * V_30 , * V_48 ;
if ( F_3 ( & V_47 , V_3 , sizeof( V_47 ) ) )
return - V_15 ;
F_13 ( EXIT , L_30 , V_25 ) ;
F_20 ( & V_7 -> V_42 ) ;
F_26 (map, _map, &md->mappings, node) {
if ( V_30 -> V_34 == V_171 && V_30 -> V_37 == V_47 &&
V_30 -> V_25 == V_25 ) {
F_27 ( & V_30 -> V_38 , V_52 ) ;
V_13 = 0 ;
break;
}
}
F_22 ( & V_7 -> V_42 ) ;
if ( V_13 == - V_15 ) {
F_13 ( V_110 , L_31 ) ;
return V_13 ;
}
return 0 ;
}
static int F_78 ( struct V_24 * V_25 , void * V_3 )
{
return - V_109 ;
}
static int F_79 ( struct V_24 * V_25 , void T_1 * V_3 )
{
return - V_109 ;
}
static int F_83 ( struct V_24 * V_25 , void T_1 * V_3 )
{
return - V_109 ;
}
static int F_84 ( struct V_24 * V_25 , void T_1 * V_3 )
{
return - V_109 ;
}
static int
F_85 ( struct V_23 * V_7 , struct V_24 * V_25 ,
T_5 V_26 , T_5 V_27 ,
struct V_29 * * V_169 )
{
struct V_5 * V_6 = V_7 -> V_6 ;
struct V_29 * V_30 ;
int V_13 ;
if ( V_27 > 0xffffffff )
return - V_17 ;
V_30 = F_14 ( sizeof( * V_30 ) , V_32 ) ;
if ( V_30 == NULL )
return - V_18 ;
V_30 -> V_150 = F_82 ( V_6 -> V_68 . V_170 , V_27 ,
& V_30 -> V_37 , V_32 ) ;
if ( V_30 -> V_150 == NULL ) {
V_13 = - V_18 ;
goto V_174;
}
if ( V_26 == V_175 )
V_26 = V_30 -> V_37 ;
V_13 = F_86 ( V_6 , V_30 -> V_37 , V_26 , ( T_2 ) V_27 , 0 ) ;
if ( V_13 < 0 )
goto V_176;
V_30 -> V_34 = V_177 ;
V_30 -> V_36 = V_26 ;
V_30 -> V_27 = V_27 ;
V_30 -> V_25 = V_25 ;
V_30 -> V_7 = V_7 ;
F_16 ( & V_30 -> V_38 ) ;
F_20 ( & V_7 -> V_42 ) ;
F_17 ( & V_30 -> V_39 , & V_7 -> V_40 ) ;
F_22 ( & V_7 -> V_42 ) ;
* V_169 = V_30 ;
return 0 ;
V_176:
F_87 ( V_6 -> V_68 . V_170 , V_27 ,
V_30 -> V_150 , V_30 -> V_37 ) ;
V_174:
F_18 ( V_30 ) ;
return V_13 ;
}
static int
F_88 ( struct V_23 * V_7 , struct V_24 * V_25 ,
T_5 V_26 , T_5 V_27 ,
struct V_29 * * V_169 )
{
struct V_29 * V_30 ;
int V_41 = - V_18 ;
if ( V_26 == V_175 )
goto V_178;
F_20 ( & V_7 -> V_42 ) ;
F_21 (map, &md->mappings, node) {
if ( V_30 -> V_34 != V_177 )
continue;
if ( V_26 == V_30 -> V_36 && V_27 == V_30 -> V_27 ) {
* V_169 = V_30 ;
V_41 = 0 ;
break;
} else if ( V_26 < ( V_30 -> V_36 + V_30 -> V_27 - 1 ) &&
( V_26 + V_27 ) > V_30 -> V_36 ) {
V_41 = - V_43 ;
break;
}
}
F_22 ( & V_7 -> V_42 ) ;
if ( V_41 != - V_18 )
return V_41 ;
V_178:
return F_85 ( V_7 , V_25 , V_26 , V_27 , V_169 ) ;
}
static int F_89 ( struct V_24 * V_25 , void T_1 * V_3 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
struct V_23 * V_7 = V_2 -> V_7 ;
struct V_46 V_30 ;
struct V_29 * V_169 = NULL ;
int V_13 ;
if ( ! V_7 -> V_6 -> V_49 -> V_179 )
return - V_51 ;
if ( F_2 ( F_3 ( & V_30 , V_3 , sizeof( V_30 ) ) ) )
return - V_15 ;
F_13 ( V_180 , L_32 , F_59 ( & V_2 -> V_7 -> V_68 ) , V_25 ) ;
V_13 = F_88 ( V_7 , V_25 , V_30 . V_36 ,
V_30 . V_12 , & V_169 ) ;
if ( V_13 )
return V_13 ;
V_30 . V_47 = V_169 -> V_37 ;
V_30 . V_36 = V_169 -> V_36 ;
if ( F_2 ( F_7 ( V_3 , & V_30 , sizeof( V_30 ) ) ) ) {
if ( V_13 == 0 && V_169 -> V_25 == V_25 ) {
F_20 ( & V_7 -> V_42 ) ;
F_27 ( & V_169 -> V_38 , V_52 ) ;
F_22 ( & V_7 -> V_42 ) ;
}
return - V_15 ;
}
return 0 ;
}
static int F_90 ( struct V_24 * V_25 , void T_1 * V_3 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
struct V_23 * V_7 = V_2 -> V_7 ;
T_5 V_47 ;
struct V_29 * V_30 , * V_48 ;
F_13 ( V_180 , L_32 , F_59 ( & V_2 -> V_7 -> V_68 ) , V_25 ) ;
if ( ! V_7 -> V_6 -> V_49 -> V_181 )
return - V_51 ;
if ( F_3 ( & V_47 , V_3 , sizeof( V_47 ) ) )
return - V_15 ;
F_20 ( & V_7 -> V_42 ) ;
F_26 (map, _map, &md->mappings, node) {
if ( V_30 -> V_34 == V_177 && V_30 -> V_37 == V_47 ) {
if ( V_30 -> V_25 == V_25 ) {
V_30 -> V_25 = NULL ;
F_27 ( & V_30 -> V_38 , V_52 ) ;
}
break;
}
}
F_22 ( & V_7 -> V_42 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , void T_1 * V_3 )
{
struct V_23 * V_7 = V_2 -> V_7 ;
T_2 V_182 = V_7 -> V_6 -> V_183 ;
F_13 ( V_56 , L_33 , V_182 ) ;
if ( F_7 ( V_3 , & V_182 , sizeof( V_182 ) ) )
return - V_15 ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_184 * V_185 )
{
int V_186 ;
if ( ! ( V_2 -> V_187 & V_185 -> V_188 ) )
return - V_189 ;
F_65 ( & V_2 -> V_190 ) ;
V_186 = F_93 ( & V_2 -> V_191 ) < sizeof( * V_185 )
|| F_94 ( & V_2 -> V_191 , ( unsigned char * ) V_185 ,
sizeof( * V_185 ) ) != sizeof( * V_185 ) ;
F_66 ( & V_2 -> V_190 ) ;
F_95 ( & V_2 -> V_192 ) ;
if ( V_186 ) {
F_96 ( & V_2 -> V_7 -> V_68 , V_193 L_34 ) ;
return - V_43 ;
}
return 0 ;
}
static void F_97 ( struct V_5 * V_6 , void * V_194 ,
T_4 V_195 , T_4 V_196 , T_4 V_197 )
{
struct V_23 * V_45 = V_194 ;
struct V_1 * V_2 ;
struct V_198 * V_199 ;
struct V_184 V_185 ;
int V_200 ;
V_185 . V_188 = V_201 ;
V_185 . V_202 . V_203 . V_19 = V_195 ;
V_185 . V_202 . V_203 . V_204 = V_197 ;
V_200 = 0 ;
F_65 ( & V_45 -> V_205 ) ;
F_21 (db_filter, &data->doorbells, data_node) {
if ( ( ( V_199 -> V_206 . V_19 == V_207 ||
V_199 -> V_206 . V_19 == V_195 ) ) &&
V_197 >= V_199 -> V_206 . V_208 &&
V_197 <= V_199 -> V_206 . V_209 ) {
V_2 = V_199 -> V_2 ;
F_92 ( V_2 , & V_185 ) ;
V_200 = 1 ;
}
}
F_66 ( & V_45 -> V_205 ) ;
if ( ! V_200 )
F_96 ( & V_45 -> V_68 ,
L_35 ,
V_210 , V_195 , V_197 ) ;
}
static int F_98 ( struct V_1 * V_2 ,
void T_1 * V_3 )
{
struct V_23 * V_7 = V_2 -> V_7 ;
struct V_198 * V_199 ;
struct V_211 V_206 ;
unsigned long V_91 ;
int V_13 ;
if ( F_3 ( & V_206 , V_3 , sizeof( V_206 ) ) )
return - V_15 ;
if ( V_206 . V_208 > V_206 . V_209 )
return - V_17 ;
V_13 = F_99 ( V_7 -> V_6 , V_7 , V_206 . V_208 , V_206 . V_209 ,
F_97 ) ;
if ( V_13 ) {
F_24 ( L_36 ,
F_59 ( & V_7 -> V_68 ) , V_13 ) ;
return V_13 ;
}
V_199 = F_14 ( sizeof( * V_199 ) , V_32 ) ;
if ( V_199 == NULL ) {
F_100 ( V_7 -> V_6 , V_206 . V_208 , V_206 . V_209 ) ;
return - V_18 ;
}
V_199 -> V_206 = V_206 ;
V_199 -> V_2 = V_2 ;
F_101 ( & V_7 -> V_205 , V_91 ) ;
F_17 ( & V_199 -> V_212 , & V_2 -> V_213 ) ;
F_17 ( & V_199 -> V_214 , & V_7 -> V_215 ) ;
F_102 ( & V_7 -> V_205 , V_91 ) ;
return 0 ;
}
static void F_103 ( struct V_198 * V_199 )
{
F_80 ( & V_199 -> V_214 ) ;
F_80 ( & V_199 -> V_212 ) ;
F_18 ( V_199 ) ;
}
static int F_104 ( struct V_1 * V_2 ,
void T_1 * V_3 )
{
struct V_198 * V_199 ;
struct V_211 V_206 ;
unsigned long V_91 ;
int V_13 = - V_17 ;
if ( F_3 ( & V_206 , V_3 , sizeof( V_206 ) ) )
return - V_15 ;
if ( V_206 . V_208 > V_206 . V_209 )
return - V_17 ;
F_101 ( & V_2 -> V_7 -> V_205 , V_91 ) ;
F_21 (db_filter, &priv->db_filters, priv_node) {
if ( V_199 -> V_206 . V_19 == V_206 . V_19 &&
V_199 -> V_206 . V_208 == V_206 . V_208 &&
V_199 -> V_206 . V_209 == V_206 . V_209 ) {
F_103 ( V_199 ) ;
V_13 = 0 ;
break;
}
}
F_102 ( & V_2 -> V_7 -> V_205 , V_91 ) ;
if ( ! V_13 )
F_100 ( V_2 -> V_7 -> V_6 , V_206 . V_208 , V_206 . V_209 ) ;
return V_13 ;
}
static int F_105 ( union V_216 * V_217 ,
struct V_218 * V_206 )
{
if ( ( V_217 -> V_219 . V_57 & V_206 -> V_220 ) < V_206 -> V_208 ||
( V_217 -> V_219 . V_57 & V_206 -> V_220 ) > V_206 -> V_209 )
return 0 ;
return 1 ;
}
static int F_106 ( struct V_5 * V_6 , void * V_221 ,
union V_216 * V_217 , int V_222 )
{
struct V_23 * V_7 = V_221 ;
struct V_1 * V_2 ;
struct V_223 * V_224 ;
struct V_184 V_185 ;
int V_200 ;
V_185 . V_188 = V_225 ;
memcpy ( V_185 . V_202 . V_226 . V_204 , V_217 -> V_227 , V_228 ) ;
V_200 = 0 ;
F_65 ( & V_7 -> V_229 ) ;
F_21 (pw_filter, &md->portwrites, md_node) {
if ( F_105 ( V_217 , & V_224 -> V_206 ) ) {
V_2 = V_224 -> V_2 ;
F_92 ( V_2 , & V_185 ) ;
V_200 = 1 ;
}
}
F_66 ( & V_7 -> V_229 ) ;
if ( ! V_200 ) {
F_107 (KERN_WARNING DRV_NAME
L_37 ,
mport->id, msg->em.comptag) ;
}
return 0 ;
}
static int F_108 ( struct V_1 * V_2 ,
void T_1 * V_3 )
{
struct V_23 * V_7 = V_2 -> V_7 ;
struct V_223 * V_224 ;
struct V_218 V_206 ;
unsigned long V_91 ;
int V_230 = 0 ;
if ( F_3 ( & V_206 , V_3 , sizeof( V_206 ) ) )
return - V_15 ;
V_224 = F_14 ( sizeof( * V_224 ) , V_32 ) ;
if ( V_224 == NULL )
return - V_18 ;
V_224 -> V_206 = V_206 ;
V_224 -> V_2 = V_2 ;
F_101 ( & V_7 -> V_229 , V_91 ) ;
if ( F_109 ( & V_7 -> V_231 ) )
V_230 = 1 ;
F_17 ( & V_224 -> V_212 , & V_2 -> V_232 ) ;
F_17 ( & V_224 -> V_233 , & V_7 -> V_231 ) ;
F_102 ( & V_7 -> V_229 , V_91 ) ;
if ( V_230 ) {
int V_13 ;
V_13 = F_110 ( V_7 -> V_6 , V_7 ,
F_106 ) ;
if ( V_13 ) {
F_111 ( & V_7 -> V_68 ,
L_38 ,
V_210 , V_13 ) ;
return V_13 ;
}
F_112 ( V_7 -> V_6 , 1 ) ;
}
return 0 ;
}
static void F_113 ( struct V_223 * V_224 )
{
F_80 ( & V_224 -> V_233 ) ;
F_80 ( & V_224 -> V_212 ) ;
F_18 ( V_224 ) ;
}
static int F_114 ( struct V_218 * V_234 ,
struct V_218 * V_235 )
{
if ( ( V_234 -> V_220 == V_235 -> V_220 ) && ( V_234 -> V_208 == V_235 -> V_208 ) && ( V_234 -> V_209 == V_235 -> V_209 ) )
return 1 ;
return 0 ;
}
static int F_115 ( struct V_1 * V_2 ,
void T_1 * V_3 )
{
struct V_23 * V_7 = V_2 -> V_7 ;
struct V_223 * V_224 ;
struct V_218 V_206 ;
unsigned long V_91 ;
int V_13 = - V_17 ;
int V_236 = 0 ;
if ( F_3 ( & V_206 , V_3 , sizeof( V_206 ) ) )
return - V_15 ;
F_101 ( & V_7 -> V_229 , V_91 ) ;
F_21 (pw_filter, &priv->pw_filters, priv_node) {
if ( F_114 ( & V_224 -> V_206 , & V_206 ) ) {
F_113 ( V_224 ) ;
V_13 = 0 ;
break;
}
}
if ( F_109 ( & V_7 -> V_231 ) )
V_236 = 1 ;
F_102 ( & V_7 -> V_229 , V_91 ) ;
if ( V_236 ) {
F_116 ( V_7 -> V_6 , V_2 -> V_7 ,
F_106 ) ;
F_112 ( V_7 -> V_6 , 0 ) ;
}
return V_13 ;
}
static void F_117 ( struct V_67 * V_68 )
{
struct V_237 * V_238 ;
V_238 = F_118 ( V_68 ) ;
F_119 ( V_239 L_39 , V_210 , F_120 ( V_238 ) ) ;
F_18 ( V_238 ) ;
}
static void F_121 ( struct V_67 * V_68 )
{
struct V_240 * V_241 ;
V_241 = F_122 ( V_68 ) ;
F_13 ( V_242 , L_40 , V_241 -> V_243 ) ;
F_18 ( V_241 ) ;
}
static int F_123 ( struct V_1 * V_2 ,
void T_1 * V_3 )
{
struct V_23 * V_7 = V_2 -> V_7 ;
struct V_244 V_245 ;
struct V_237 * V_238 ;
struct V_246 * V_247 = NULL ;
struct V_5 * V_6 ;
T_3 V_27 ;
T_2 V_248 ;
T_2 V_249 = 0 ;
T_4 V_250 ;
T_8 V_20 ;
int V_41 ;
if ( F_3 ( & V_245 , V_3 , sizeof( V_245 ) ) )
return - V_15 ;
F_13 ( V_242 , L_41 , V_245 . V_251 ,
V_245 . V_57 , V_245 . V_250 , V_245 . V_20 ) ;
if ( F_124 ( & V_252 , NULL , V_245 . V_251 ) ) {
F_13 ( V_242 , L_42 , V_245 . V_251 ) ;
return - V_253 ;
}
V_27 = sizeof( * V_238 ) ;
V_6 = V_7 -> V_6 ;
V_250 = V_245 . V_250 ;
V_20 = V_245 . V_20 ;
if ( F_6 ( V_6 , V_250 , V_20 ,
V_254 , & V_248 ) )
return - V_124 ;
if ( V_248 & V_255 ) {
F_6 ( V_6 , V_250 , V_20 ,
V_256 , & V_249 ) ;
V_27 += ( F_125 ( V_249 ) *
sizeof( V_247 -> V_257 [ 0 ] ) ) + sizeof( * V_247 ) ;
}
V_238 = F_14 ( V_27 , V_32 ) ;
if ( V_238 == NULL )
return - V_18 ;
if ( V_6 -> V_241 == NULL ) {
struct V_240 * V_241 ;
V_241 = F_126 ( V_6 ) ;
if ( ! V_241 ) {
V_41 = - V_18 ;
F_13 ( V_242 , L_43 ) ;
goto V_258;
}
V_241 -> V_243 = V_6 -> V_243 ;
V_241 -> V_259 = V_6 ;
F_127 ( & V_241 -> V_68 , L_44 , V_241 -> V_243 ) ;
V_241 -> V_68 . V_170 = & V_6 -> V_68 ;
V_241 -> V_68 . V_260 = F_121 ;
V_41 = F_128 ( V_241 ) ;
if ( V_41 ) {
F_13 ( V_242 , L_45 , V_41 ) ;
F_18 ( V_241 ) ;
goto V_258;
}
}
V_238 -> V_241 = V_6 -> V_241 ;
V_238 -> V_261 = V_248 ;
V_238 -> V_249 = V_249 ;
F_6 ( V_6 , V_250 , V_20 ,
V_262 , & V_248 ) ;
V_238 -> V_263 = V_248 >> 16 ;
V_238 -> V_264 = V_248 & 0xffff ;
F_6 ( V_6 , V_250 , V_20 , V_265 ,
& V_238 -> V_266 ) ;
F_6 ( V_6 , V_250 , V_20 , V_267 ,
& V_248 ) ;
V_238 -> V_268 = V_248 >> 16 ;
V_238 -> V_269 = V_248 & 0xffff ;
F_6 ( V_6 , V_250 , V_20 , V_270 ,
& V_248 ) ;
V_238 -> V_271 = V_248 >> 16 ;
if ( V_238 -> V_261 & V_272 ) {
V_238 -> V_273 = V_248 & 0xffff ;
V_238 -> V_274 = F_129 ( V_6 , 0 , V_250 ,
V_20 , & V_238 -> V_275 ) ;
V_238 -> V_276 = F_130 ( V_6 , 0 , V_250 ,
V_20 , V_277 ) ;
}
F_6 ( V_6 , V_250 , V_20 , V_278 ,
& V_238 -> V_279 ) ;
F_6 ( V_6 , V_250 , V_20 , V_280 ,
& V_238 -> V_281 ) ;
V_238 -> V_282 = V_245 . V_57 ;
V_238 -> V_250 = V_250 ;
V_238 -> V_20 = V_20 ;
if ( V_238 -> V_261 & V_255 ) {
V_247 = V_238 -> V_247 ;
V_247 -> V_283 = NULL ;
}
if ( strlen ( V_245 . V_251 ) )
F_127 ( & V_238 -> V_68 , L_46 , V_245 . V_251 ) ;
else if ( V_238 -> V_261 & V_255 )
F_127 ( & V_238 -> V_68 , L_47 , V_6 -> V_243 ,
V_238 -> V_282 & V_284 ) ;
else
F_127 ( & V_238 -> V_68 , L_48 , V_6 -> V_243 ,
V_238 -> V_282 & V_284 ) ;
F_131 ( & V_238 -> V_285 ) ;
V_238 -> V_68 . V_170 = & V_6 -> V_241 -> V_68 ;
F_132 ( V_238 ) ;
V_238 -> V_68 . V_260 = F_117 ;
if ( V_238 -> V_281 & V_286 )
F_133 ( & V_238 -> V_287 [ V_288 ] ,
0 , 0xffff ) ;
V_41 = F_134 ( V_238 ) ;
if ( V_41 )
goto V_258;
F_135 ( V_238 ) ;
return 0 ;
V_258:
F_18 ( V_238 ) ;
return V_41 ;
}
static int F_136 ( struct V_1 * V_2 , void T_1 * V_3 )
{
struct V_244 V_245 ;
struct V_237 * V_238 = NULL ;
struct V_67 * V_68 ;
struct V_5 * V_6 ;
struct V_240 * V_241 ;
if ( F_3 ( & V_245 , V_3 , sizeof( V_245 ) ) )
return - V_15 ;
V_6 = V_2 -> V_7 -> V_6 ;
if ( strlen ( V_245 . V_251 ) ) {
V_68 = F_124 ( & V_252 , NULL ,
V_245 . V_251 ) ;
if ( V_68 )
V_238 = F_118 ( V_68 ) ;
} else {
do {
V_238 = F_137 ( V_245 . V_57 , V_238 ) ;
if ( V_238 && V_238 -> V_68 . V_170 == & V_6 -> V_241 -> V_68 &&
V_238 -> V_250 == V_245 . V_250 &&
V_238 -> V_20 == V_245 . V_20 )
break;
} while ( V_238 );
}
if ( ! V_238 ) {
F_13 ( V_242 ,
L_49 ,
V_245 . V_251 , V_245 . V_57 , V_245 . V_250 ,
V_245 . V_20 ) ;
return - V_109 ;
}
V_241 = V_238 -> V_241 ;
F_138 ( V_238 ) ;
F_139 ( V_238 , V_289 ) ;
if ( F_109 ( & V_241 -> V_290 ) ) {
F_140 ( V_241 ) ;
V_6 -> V_241 = NULL ;
}
return 0 ;
}
static int F_141 ( struct V_291 * V_291 , struct V_24 * V_25 )
{
int V_13 ;
int V_292 = F_142 ( V_291 ) ;
struct V_23 * V_293 ;
struct V_1 * V_2 ;
if ( V_292 >= V_294 ) {
F_24 ( L_50 ) ;
return - V_17 ;
}
V_293 = F_33 ( V_291 -> V_295 , struct V_23 , V_296 ) ;
F_13 ( V_297 , L_32 , F_59 ( & V_293 -> V_68 ) , V_25 ) ;
if ( F_143 ( & V_293 -> V_298 ) == 0 )
return - V_109 ;
F_144 ( & V_293 -> V_68 ) ;
V_2 = F_14 ( sizeof( * V_2 ) , V_32 ) ;
if ( ! V_2 ) {
F_145 ( & V_293 -> V_68 ) ;
return - V_18 ;
}
V_2 -> V_7 = V_293 ;
F_20 ( & V_293 -> V_299 ) ;
F_17 ( & V_2 -> V_300 , & V_293 -> V_301 ) ;
F_22 ( & V_293 -> V_299 ) ;
F_131 ( & V_2 -> V_213 ) ;
F_131 ( & V_2 -> V_232 ) ;
F_146 ( & V_2 -> V_190 ) ;
F_147 ( & V_2 -> V_192 ) ;
V_13 = F_148 ( & V_2 -> V_191 ,
sizeof( struct V_184 ) * V_302 ,
V_32 ) ;
if ( V_13 < 0 ) {
F_111 ( & V_293 -> V_68 , V_193 L_51 ) ;
V_13 = - V_18 ;
goto V_303;
}
#ifdef F_149
F_131 ( & V_2 -> V_132 ) ;
F_131 ( & V_2 -> V_153 ) ;
F_146 ( & V_2 -> V_131 ) ;
F_150 ( & V_2 -> V_108 ) ;
#endif
V_25 -> V_44 = V_2 ;
goto V_21;
V_303:
F_18 ( V_2 ) ;
V_21:
return V_13 ;
}
static int F_151 ( int V_304 , struct V_24 * V_25 , int V_305 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
return F_152 ( V_304 , V_25 , V_305 , & V_2 -> V_306 ) ;
}
static void F_153 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
struct V_23 * V_7 ;
struct V_65 * V_66 , * V_307 ;
unsigned long V_115 = F_57 ( V_116 ) ;
long V_117 ;
F_154 ( V_300 ) ;
F_13 ( EXIT , L_52 ,
V_25 , V_120 -> V_121 , F_58 ( V_120 ) ) ;
if ( ! V_2 -> V_63 ) {
F_13 ( EXIT , L_53 , V_25 ) ;
return;
}
V_7 = V_2 -> V_7 ;
F_155 ( V_83 ) ;
F_65 ( & V_2 -> V_131 ) ;
if ( ! F_109 ( & V_2 -> V_132 ) ) {
F_13 ( EXIT , L_54 ,
V_25 , V_120 -> V_121 , F_58 ( V_120 ) ) ;
F_156 ( & V_2 -> V_132 , & V_300 ) ;
}
F_66 ( & V_2 -> V_131 ) ;
if ( ! F_109 ( & V_300 ) ) {
F_13 ( EXIT , L_55 ) ;
F_26 (req, req_next, &list, node) {
F_13 ( EXIT , L_56 ,
V_66 -> V_25 , V_66 -> V_76 ,
F_157 ( & V_66 -> V_77 ) ? L_57 : L_58 ) ;
F_80 ( & V_66 -> V_39 ) ;
F_37 ( V_66 ) ;
}
}
if ( ! F_109 ( & V_2 -> V_153 ) ) {
F_13 ( EXIT , L_59 ,
V_25 , V_120 -> V_121 , F_58 ( V_120 ) ) ;
F_26 (req,
req_next, &priv->pend_list, node) {
F_13 ( EXIT , L_56 ,
V_66 -> V_25 , V_66 -> V_76 ,
F_157 ( & V_66 -> V_77 ) ? L_57 : L_58 ) ;
F_80 ( & V_66 -> V_39 ) ;
F_37 ( V_66 ) ;
}
}
F_55 ( V_2 ) ;
V_117 = F_67 ( & V_2 -> V_64 , V_115 ) ;
if ( V_117 <= 0 ) {
F_24 ( L_60 ,
V_120 -> V_121 , F_58 ( V_120 ) , V_117 ) ;
}
F_65 ( & V_2 -> V_131 ) ;
if ( ! F_109 ( & V_2 -> V_153 ) ) {
F_13 ( EXIT , L_61 ,
V_25 , V_120 -> V_121 , F_58 ( V_120 ) ) ;
}
F_66 ( & V_2 -> V_131 ) ;
if ( V_2 -> V_63 != V_2 -> V_7 -> V_61 ) {
F_13 ( EXIT , L_62 ,
V_25 , V_120 -> V_121 , F_58 ( V_120 ) ) ;
F_34 ( V_2 -> V_63 ) ;
} else {
F_13 ( EXIT , L_63 ) ;
F_27 ( & V_7 -> V_60 , F_32 ) ;
}
V_2 -> V_63 = NULL ;
}
static int F_158 ( struct V_291 * V_291 , struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
struct V_23 * V_293 ;
struct V_223 * V_224 , * V_308 ;
struct V_198 * V_199 , * V_309 ;
struct V_29 * V_30 , * V_48 ;
unsigned long V_91 ;
F_13 ( EXIT , L_32 , F_59 ( & V_2 -> V_7 -> V_68 ) , V_25 ) ;
V_293 = V_2 -> V_7 ;
F_153 ( V_25 ) ;
V_2 -> V_187 = 0 ;
F_101 ( & V_293 -> V_229 , V_91 ) ;
if ( ! F_109 ( & V_2 -> V_232 ) ) {
F_26 (pw_filter, pw_filter_next,
&priv->pw_filters, priv_node)
F_113 ( V_224 ) ;
}
F_102 ( & V_293 -> V_229 , V_91 ) ;
F_101 ( & V_293 -> V_205 , V_91 ) ;
F_26 (db_filter, db_filter_next,
&priv->db_filters, priv_node) {
F_103 ( V_199 ) ;
}
F_102 ( & V_293 -> V_205 , V_91 ) ;
F_159 ( & V_2 -> V_191 ) ;
F_20 ( & V_293 -> V_42 ) ;
F_26 (map, _map, &chdev->mappings, node) {
if ( V_30 -> V_25 == V_25 ) {
F_13 ( EXIT , L_64 ,
V_30 -> V_150 , V_25 ) ;
F_27 ( & V_30 -> V_38 , V_52 ) ;
}
}
F_22 ( & V_293 -> V_42 ) ;
F_151 ( - 1 , V_25 , 0 ) ;
V_25 -> V_44 = NULL ;
F_20 ( & V_293 -> V_299 ) ;
F_80 ( & V_2 -> V_300 ) ;
F_22 ( & V_293 -> V_299 ) ;
F_145 ( & V_293 -> V_68 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
static long F_160 ( struct V_24 * V_25 ,
unsigned int V_310 , unsigned long V_3 )
{
int V_41 = - V_17 ;
struct V_1 * V_45 = V_25 -> V_44 ;
struct V_23 * V_7 = V_45 -> V_7 ;
if ( F_143 ( & V_7 -> V_298 ) == 0 )
return - V_109 ;
switch ( V_310 ) {
case V_311 :
return F_1 ( V_45 , ( void T_1 * ) V_3 , 1 ) ;
case V_312 :
return F_9 ( V_45 , ( void T_1 * ) V_3 , 1 ) ;
case V_313 :
return F_1 ( V_45 , ( void T_1 * ) V_3 , 0 ) ;
case V_314 :
return F_9 ( V_45 , ( void T_1 * ) V_3 , 0 ) ;
case V_315 :
return F_28 ( V_45 , ( void T_1 * ) V_3 ) ;
case V_316 :
return F_30 ( V_45 , ( void T_1 * ) V_3 ) ;
case V_317 :
return F_91 ( V_45 , ( void T_1 * ) V_3 ) ;
case V_318 :
V_7 -> V_55 . V_53 = V_7 -> V_6 -> V_54 ;
if ( F_7 ( ( void T_1 * ) V_3 , & ( V_7 -> V_55 ) ,
sizeof( V_7 -> V_55 ) ) )
return - V_15 ;
return 0 ;
case V_319 :
return F_98 ( V_45 , ( void T_1 * ) V_3 ) ;
case V_320 :
return F_104 ( V_45 , ( void T_1 * ) V_3 ) ;
case V_321 :
return F_108 ( V_45 , ( void T_1 * ) V_3 ) ;
case V_322 :
return F_115 ( V_45 , ( void T_1 * ) V_3 ) ;
case V_323 :
V_45 -> V_187 = ( T_2 ) V_3 ;
return 0 ;
case V_324 :
if ( F_7 ( ( void T_1 * ) V_3 , & V_45 -> V_187 ,
sizeof( T_2 ) ) )
return - V_15 ;
return 0 ;
case V_325 :
return F_23 ( V_25 , ( void T_1 * ) V_3 ) ;
case V_326 :
return F_89 ( V_25 , ( void T_1 * ) V_3 ) ;
case V_327 :
return F_25 ( V_25 , ( void T_1 * ) V_3 ) ;
case V_328 :
return F_90 ( V_25 , ( void T_1 * ) V_3 ) ;
case V_329 :
return F_83 ( V_25 , ( void T_1 * ) V_3 ) ;
case V_330 :
return F_84 ( V_25 , ( void T_1 * ) V_3 ) ;
case V_331 :
return F_79 ( V_25 , ( void T_1 * ) V_3 ) ;
case V_332 :
return F_78 ( V_25 , ( void T_1 * ) V_3 ) ;
case V_333 :
return F_123 ( V_45 , ( void T_1 * ) V_3 ) ;
case V_334 :
return F_136 ( V_45 , ( void T_1 * ) V_3 ) ;
default:
break;
}
return V_41 ;
}
static void V_52 ( struct V_59 * V_38 )
{
struct V_29 * V_30 =
F_33 ( V_38 , struct V_29 , V_38 ) ;
struct V_5 * V_6 = V_30 -> V_7 -> V_6 ;
F_13 ( V_335 , L_65 ,
V_30 -> V_34 , V_30 -> V_150 ,
& V_30 -> V_37 , V_6 -> V_251 ) ;
F_80 ( & V_30 -> V_39 ) ;
switch ( V_30 -> V_34 ) {
case V_177 :
F_161 ( V_6 , V_30 -> V_37 ) ;
case V_171 :
F_87 ( V_6 -> V_68 . V_170 , V_30 -> V_27 ,
V_30 -> V_150 , V_30 -> V_37 ) ;
break;
case V_35 :
F_162 ( V_6 , V_30 -> V_19 , V_30 -> V_36 ) ;
break;
}
F_18 ( V_30 ) ;
}
static void F_163 ( struct V_336 * V_337 )
{
struct V_29 * V_30 = V_337 -> V_338 ;
F_13 ( V_335 , L_66 , & V_30 -> V_37 ) ;
F_53 ( & V_30 -> V_38 ) ;
}
static void F_164 ( struct V_336 * V_337 )
{
struct V_29 * V_30 = V_337 -> V_338 ;
F_13 ( V_335 , L_66 , & V_30 -> V_37 ) ;
F_20 ( & V_30 -> V_7 -> V_42 ) ;
F_27 ( & V_30 -> V_38 , V_52 ) ;
F_22 ( & V_30 -> V_7 -> V_42 ) ;
}
static int F_165 ( struct V_24 * V_25 , struct V_336 * V_337 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
struct V_23 * V_7 ;
T_3 V_27 = V_337 -> V_339 - V_337 -> V_340 ;
T_6 V_149 ;
unsigned long V_11 ;
int V_163 = 0 , V_13 ;
struct V_29 * V_30 ;
F_13 ( V_335 , L_67 ,
( unsigned int ) V_27 , V_337 -> V_341 ) ;
V_7 = V_2 -> V_7 ;
V_149 = ( ( T_6 ) V_337 -> V_341 << V_143 ) ;
F_20 ( & V_7 -> V_42 ) ;
F_21 (map, &md->mappings, node) {
if ( V_149 >= V_30 -> V_37 &&
V_149 < ( V_30 -> V_37 + V_30 -> V_27 ) ) {
V_163 = 1 ;
break;
}
}
F_22 ( & V_7 -> V_42 ) ;
if ( ! V_163 )
return - V_18 ;
V_11 = V_149 - V_30 -> V_37 ;
if ( V_27 + V_11 > V_30 -> V_27 )
return - V_17 ;
V_337 -> V_341 = V_11 >> V_143 ;
F_13 ( V_335 , L_68 , V_337 -> V_341 ) ;
if ( V_30 -> V_34 == V_177 || V_30 -> V_34 == V_171 )
V_13 = F_166 ( V_7 -> V_6 -> V_68 . V_170 , V_337 ,
V_30 -> V_150 , V_30 -> V_37 , V_30 -> V_27 ) ;
else if ( V_30 -> V_34 == V_35 ) {
V_337 -> V_342 = F_167 ( V_337 -> V_342 ) ;
V_13 = F_168 ( V_337 , V_30 -> V_37 , V_30 -> V_27 ) ;
} else {
F_24 ( L_69 ) ;
V_13 = - V_124 ;
}
if ( ! V_13 ) {
V_337 -> V_338 = V_30 ;
V_337 -> V_343 = & V_343 ;
F_163 ( V_337 ) ;
} else {
F_24 ( L_70 , V_13 ) ;
}
return V_13 ;
}
static unsigned int F_169 ( struct V_24 * V_25 , T_9 * V_344 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
F_170 ( V_25 , & V_2 -> V_192 , V_344 ) ;
if ( F_171 ( & V_2 -> V_191 ) )
return V_345 | V_346 ;
return 0 ;
}
static T_10 F_172 ( struct V_24 * V_25 , char T_1 * V_347 , T_3 V_156 ,
T_11 * V_348 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
int V_349 ;
T_10 V_13 ;
if ( ! V_156 )
return 0 ;
if ( F_173 ( & V_2 -> V_191 ) &&
( V_25 -> V_350 & V_351 ) )
return - V_166 ;
if ( V_156 % sizeof( struct V_184 ) )
return - V_17 ;
V_13 = F_174 ( V_2 -> V_192 ,
F_171 ( & V_2 -> V_191 ) != 0 ) ;
if ( V_13 )
return V_13 ;
while ( V_13 < V_156 ) {
if ( F_175 ( & V_2 -> V_191 , V_347 ,
sizeof( struct V_184 ) , & V_349 ) )
return - V_15 ;
V_13 += V_349 ;
V_347 += V_349 ;
}
return V_13 ;
}
static T_10 F_176 ( struct V_24 * V_25 , const char T_1 * V_347 ,
T_3 V_156 , T_11 * V_348 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
struct V_5 * V_6 = V_2 -> V_7 -> V_6 ;
struct V_184 V_185 ;
int V_352 , V_13 ;
if ( ! V_156 )
return 0 ;
if ( V_156 % sizeof( V_185 ) )
return - V_17 ;
V_352 = 0 ;
while ( ( V_156 - V_352 ) >= ( int ) sizeof( V_185 ) ) {
if ( F_3 ( & V_185 , V_347 , sizeof( V_185 ) ) )
return - V_15 ;
if ( V_185 . V_188 != V_201 )
return - V_17 ;
V_13 = F_177 ( V_6 ,
V_185 . V_202 . V_203 . V_19 ,
V_185 . V_202 . V_203 . V_204 ) ;
if ( V_13 < 0 )
return V_13 ;
V_352 += sizeof( V_185 ) ;
V_347 += sizeof( V_185 ) ;
}
return V_352 ;
}
static void F_178 ( struct V_67 * V_68 )
{
struct V_23 * V_7 ;
F_13 ( EXIT , L_46 , F_59 ( V_68 ) ) ;
V_7 = F_33 ( V_68 , struct V_23 , V_68 ) ;
F_18 ( V_7 ) ;
}
static struct V_23 * F_179 ( struct V_5 * V_6 )
{
int V_13 = 0 ;
struct V_23 * V_7 ;
struct V_353 V_354 ;
V_7 = F_14 ( sizeof( * V_7 ) , V_32 ) ;
if ( ! V_7 ) {
F_24 ( L_71 ) ;
return NULL ;
}
V_7 -> V_6 = V_6 ;
F_150 ( & V_7 -> V_42 ) ;
F_150 ( & V_7 -> V_299 ) ;
F_131 ( & V_7 -> V_301 ) ;
F_180 ( & V_7 -> V_296 , & V_355 ) ;
V_7 -> V_296 . V_356 = V_357 ;
V_13 = F_181 ( & V_7 -> V_296 , F_182 ( F_183 ( V_358 ) , V_6 -> V_243 ) , 1 ) ;
if ( V_13 < 0 ) {
F_18 ( V_7 ) ;
F_24 ( L_72 , V_13 ) ;
return NULL ;
}
V_7 -> V_68 . V_359 = V_7 -> V_296 . V_68 ;
V_7 -> V_68 . V_360 = V_361 ;
V_7 -> V_68 . V_170 = & V_6 -> V_68 ;
V_7 -> V_68 . V_260 = F_178 ;
F_127 ( & V_7 -> V_68 , V_362 L_73 , V_6 -> V_243 ) ;
F_184 ( & V_7 -> V_298 , 1 ) ;
V_13 = F_185 ( & V_7 -> V_68 ) ;
if ( V_13 ) {
F_24 ( L_74 ,
V_6 -> V_243 , V_13 ) ;
goto V_363;
}
F_144 ( & V_7 -> V_68 ) ;
F_131 ( & V_7 -> V_215 ) ;
F_146 ( & V_7 -> V_205 ) ;
F_131 ( & V_7 -> V_231 ) ;
F_146 ( & V_7 -> V_229 ) ;
F_131 ( & V_7 -> V_40 ) ;
V_7 -> V_55 . V_243 = V_6 -> V_243 ;
V_7 -> V_55 . V_364 = V_6 -> V_364 ;
V_7 -> V_55 . V_53 = V_6 -> V_54 ;
V_7 -> V_55 . V_183 = V_6 -> V_183 ;
#ifdef F_186
V_7 -> V_55 . V_137 |= V_365 ;
#else
V_7 -> V_55 . V_137 |= V_366 ;
#endif
V_13 = F_187 ( V_6 , & V_354 ) ;
if ( ! V_13 ) {
V_7 -> V_55 . V_91 = V_354 . V_91 ;
V_7 -> V_55 . V_367 = V_354 . V_367 ;
V_7 -> V_55 . V_368 = V_354 . V_368 ;
V_7 -> V_55 . V_369 = V_354 . V_369 ;
V_7 -> V_55 . V_370 = V_354 . V_370 ;
V_7 -> V_55 . V_371 = V_354 . V_371 ;
V_7 -> V_55 . V_372 = 0 ;
V_7 -> V_55 . V_373 = 0 ;
V_7 -> V_55 . V_374 = 0 ;
} else
F_119 ( V_239 L_75 ,
V_6 -> V_251 , F_183 ( V_358 ) , V_6 -> V_243 ) ;
F_20 ( & V_375 ) ;
F_17 ( & V_7 -> V_39 , & V_376 ) ;
F_22 ( & V_375 ) ;
F_119 ( V_239 L_76 ,
V_6 -> V_251 , F_183 ( V_358 ) , V_6 -> V_243 ) ;
return V_7 ;
V_363:
F_188 ( & V_7 -> V_296 ) ;
F_18 ( V_7 ) ;
return NULL ;
}
static void F_189 ( struct V_23 * V_7 )
{
#ifdef F_149
struct V_1 * V_377 ;
F_13 ( V_110 , L_46 , F_59 ( & V_7 -> V_68 ) ) ;
F_20 ( & V_7 -> V_299 ) ;
F_21 (client, &md->file_list, list) {
if ( V_377 -> V_63 ) {
F_190 ( V_377 -> V_63 ) ;
F_34 ( V_377 -> V_63 ) ;
}
}
F_22 ( & V_7 -> V_299 ) ;
if ( V_7 -> V_61 ) {
F_190 ( V_7 -> V_61 ) ;
F_34 ( V_7 -> V_61 ) ;
V_7 -> V_61 = NULL ;
}
#endif
}
static int F_191 ( struct V_23 * V_7 )
{
unsigned int V_378 = 0 ;
struct V_1 * V_377 ;
F_20 ( & V_7 -> V_299 ) ;
F_21 (client, &md->file_list, list) {
if ( V_377 -> V_306 )
F_192 ( & V_377 -> V_306 , V_379 , V_380 ) ;
V_378 ++ ;
}
F_22 ( & V_7 -> V_299 ) ;
return V_378 ;
}
static void F_193 ( struct V_23 * V_7 )
{
struct V_29 * V_30 , * V_48 ;
F_13 ( EXIT , L_77 , V_7 -> V_6 -> V_251 ) ;
F_184 ( & V_7 -> V_298 , 0 ) ;
F_189 ( V_7 ) ;
F_116 ( V_7 -> V_6 , V_7 , F_106 ) ;
F_188 ( & ( V_7 -> V_296 ) ) ;
F_191 ( V_7 ) ;
F_155 ( V_83 ) ;
F_20 ( & V_7 -> V_42 ) ;
F_26 (map, _map, &md->mappings, node) {
F_27 ( & V_30 -> V_38 , V_52 ) ;
}
F_22 ( & V_7 -> V_42 ) ;
if ( ! F_109 ( & V_7 -> V_40 ) )
F_194 ( L_78 ,
V_7 -> V_6 -> V_251 ) ;
F_100 ( V_7 -> V_6 , 0 , 0x0fff ) ;
F_195 ( & V_7 -> V_68 ) ;
F_145 ( & V_7 -> V_68 ) ;
}
static int F_196 ( struct V_67 * V_68 ,
struct V_381 * V_382 )
{
struct V_5 * V_6 = NULL ;
struct V_23 * V_293 = NULL ;
V_6 = F_197 ( V_68 ) ;
if ( ! V_6 )
return - V_109 ;
V_293 = F_179 ( V_6 ) ;
if ( ! V_293 )
return - V_109 ;
return 0 ;
}
static void F_198 ( struct V_67 * V_68 ,
struct V_381 * V_382 )
{
struct V_5 * V_6 = NULL ;
struct V_23 * V_293 ;
int V_163 = 0 ;
V_6 = F_197 ( V_68 ) ;
F_13 ( EXIT , L_79 , V_6 -> V_251 ) ;
F_20 ( & V_375 ) ;
F_21 (chdev, &mport_devs, node) {
if ( V_293 -> V_6 -> V_243 == V_6 -> V_243 ) {
F_184 ( & V_293 -> V_298 , 0 ) ;
F_80 ( & V_293 -> V_39 ) ;
V_163 = 1 ;
break;
}
}
F_22 ( & V_375 ) ;
if ( V_163 )
F_193 ( V_293 ) ;
}
static int T_12 F_199 ( void )
{
int V_13 ;
V_361 = F_200 ( V_357 , V_193 ) ;
if ( F_60 ( V_361 ) ) {
F_24 ( L_80 V_193 L_81 ) ;
return F_61 ( V_361 ) ;
}
V_13 = F_201 ( & V_358 , 0 , V_294 , V_193 ) ;
if ( V_13 < 0 )
goto V_383;
F_13 ( V_297 , L_82 , F_183 ( V_358 ) ) ;
V_13 = F_202 ( & V_384 ) ;
if ( V_13 ) {
F_24 ( L_83 , V_13 ) ;
goto V_385;
}
V_83 = F_203 ( L_84 ) ;
if ( ! V_83 ) {
F_24 ( L_85 ) ;
V_13 = - V_18 ;
goto V_386;
}
return 0 ;
V_386:
F_204 ( & V_384 ) ;
V_385:
F_205 ( V_358 , V_294 ) ;
V_383:
F_206 ( V_361 ) ;
return V_13 ;
}
static void T_13 F_207 ( void )
{
F_204 ( & V_384 ) ;
F_206 ( V_361 ) ;
F_205 ( V_358 , V_294 ) ;
F_208 ( V_83 ) ;
}
