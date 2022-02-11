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
V_141 = F_71 (
( unsigned long ) V_111 -> V_140 & V_142 ,
V_73 ,
V_72 ,
V_34 == V_118 ? V_145 : 0 ) ;
if ( V_141 != V_73 ) {
if ( V_141 < 0 ) {
F_24 ( L_21 ,
V_141 ) ;
V_73 = 0 ;
} else
F_24 ( L_22 ,
V_141 , V_73 ) ;
V_13 = - V_15 ;
goto V_146;
}
V_13 = F_72 ( & V_66 -> V_69 , V_72 , V_73 ,
V_11 , V_111 -> V_12 , V_32 ) ;
if ( V_13 ) {
F_24 ( L_23 , V_13 ) ;
goto V_146;
}
V_66 -> V_72 = V_72 ;
V_66 -> V_73 = V_73 ;
} else {
T_6 V_147 ;
struct V_29 * V_30 ;
V_147 = ( T_6 ) V_111 -> V_47 ;
F_20 ( & V_7 -> V_42 ) ;
F_21 (map, &md->mappings, node) {
if ( V_147 >= V_30 -> V_37 &&
V_147 < ( V_30 -> V_37 + V_30 -> V_27 ) ) {
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
V_13 = F_73 ( & V_66 -> V_69 , 1 , V_32 ) ;
if ( F_2 ( V_13 ) ) {
F_24 ( L_24 ) ;
goto V_144;
}
F_74 ( V_66 -> V_69 . V_70 ,
V_30 -> V_148 + ( V_147 - V_30 -> V_37 ) +
V_111 -> V_11 , V_111 -> V_12 ) ;
}
V_66 -> V_34 = V_34 ;
V_66 -> V_25 = V_25 ;
V_66 -> V_2 = V_2 ;
V_85 = V_2 -> V_63 ;
V_71 = F_75 ( V_85 -> V_67 -> V_68 ,
V_66 -> V_69 . V_70 , V_66 -> V_69 . V_71 , V_34 ) ;
if ( V_71 == - V_15 ) {
F_24 ( L_25 ) ;
return - V_15 ;
}
V_13 = F_56 ( V_66 , V_111 , V_113 , V_71 ) ;
if ( V_13 >= 0 ) {
if ( V_113 == V_149 )
goto V_150;
return V_13 ;
}
if ( V_13 == - V_133 || V_13 == - V_135 ) {
F_65 ( & V_2 -> V_131 ) ;
F_17 ( & V_66 -> V_39 , & V_2 -> V_151 ) ;
F_66 ( & V_2 -> V_131 ) ;
return V_13 ;
}
F_13 ( V_110 , L_26 , V_13 ) ;
V_150:
F_38 ( V_85 -> V_67 -> V_68 , V_66 -> V_69 . V_70 , V_66 -> V_69 . V_71 , V_34 ) ;
F_39 ( & V_66 -> V_69 ) ;
V_146:
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
static int F_76 ( struct V_24 * V_25 , void T_1 * V_3 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
struct V_152 V_153 ;
struct V_86 * V_87 ;
enum V_138 V_34 ;
int V_14 , V_13 = 0 ;
if ( F_2 ( F_3 ( & V_153 , V_3 , sizeof( V_153 ) ) ) )
return - V_15 ;
if ( V_153 . V_154 != 1 )
return - V_17 ;
if ( ( V_153 . V_137 &
V_2 -> V_7 -> V_55 . V_137 ) == 0 )
return - V_109 ;
V_87 = F_4 ( V_153 . V_154 * sizeof( * V_87 ) ) ;
if ( ! V_87 )
return - V_18 ;
if ( F_2 ( F_3 ( V_87 ,
( void T_1 * ) ( V_22 ) V_153 . V_155 ,
V_153 . V_154 * sizeof( * V_87 ) ) ) ) {
V_13 = - V_15 ;
goto V_156;
}
V_34 = ( V_153 . V_34 == V_157 ) ?
V_118 : V_158 ;
for ( V_14 = 0 ; V_14 < V_153 . V_154 && V_13 == 0 ; V_14 ++ )
V_13 = F_68 ( V_25 , V_153 . V_137 ,
V_153 . V_113 , V_34 , & V_87 [ V_14 ] ) ;
if ( F_2 ( F_7 ( ( void T_1 * ) ( V_22 ) V_153 . V_155 ,
V_87 ,
V_153 . V_154 * sizeof( * V_87 ) ) ) )
V_13 = - V_15 ;
V_156:
F_8 ( V_87 ) ;
return V_13 ;
}
static int F_77 ( struct V_24 * V_25 , void T_1 * V_3 )
{
struct V_1 * V_2 ;
struct V_23 * V_7 ;
struct V_159 V_160 ;
struct V_65 * V_66 ;
T_7 V_76 ;
unsigned long V_115 ;
long V_117 ;
int V_161 = 0 ;
int V_13 ;
V_2 = (struct V_1 * ) V_25 -> V_44 ;
V_7 = V_2 -> V_7 ;
if ( F_2 ( F_3 ( & V_160 , V_3 , sizeof( V_160 ) ) ) )
return - V_15 ;
V_76 = V_160 . V_162 ;
if ( V_160 . V_163 )
V_115 = F_57 ( V_160 . V_163 ) ;
else
V_115 = F_57 ( V_116 ) ;
F_65 ( & V_2 -> V_131 ) ;
F_21 (req, &priv->async_list, node) {
if ( V_66 -> V_76 == V_76 ) {
F_78 ( & V_66 -> V_39 ) ;
V_161 = 1 ;
break;
}
}
F_66 ( & V_2 -> V_131 ) ;
if ( ! V_161 )
return - V_164 ;
V_117 = F_67 ( & V_66 -> V_77 , V_115 ) ;
if ( V_117 == 0 ) {
F_24 ( L_27 ,
V_120 -> V_121 , F_58 ( V_120 ) ,
( V_66 -> V_34 == V_118 ) ? L_12 : L_13 ) ;
V_13 = - V_133 ;
goto V_165;
} else if ( V_117 == - V_134 ) {
F_24 ( L_28 ,
V_120 -> V_121 , F_58 ( V_120 ) ,
( V_66 -> V_34 == V_118 ) ? L_12 : L_13 ) ;
V_13 = - V_135 ;
goto V_165;
}
if ( V_66 -> V_75 != V_136 ) {
F_24 ( L_29 ,
V_120 -> V_121 , F_58 ( V_120 ) ,
( V_66 -> V_34 == V_118 ) ? L_12 : L_13 ,
V_66 -> V_75 ) ;
V_13 = - V_124 ;
} else
V_13 = 0 ;
if ( V_66 -> V_75 != V_129 && V_66 -> V_75 != V_166 )
F_37 ( V_66 ) ;
return V_13 ;
V_165:
F_65 ( & V_2 -> V_131 ) ;
F_17 ( & V_66 -> V_39 , & V_2 -> V_132 ) ;
F_66 ( & V_2 -> V_131 ) ;
return V_13 ;
}
static int F_79 ( struct V_23 * V_7 , struct V_24 * V_25 ,
T_5 V_27 , struct V_29 * * V_167 )
{
struct V_29 * V_30 ;
V_30 = F_14 ( sizeof( * V_30 ) , V_32 ) ;
if ( V_30 == NULL )
return - V_18 ;
V_30 -> V_148 = F_80 ( V_7 -> V_6 -> V_68 . V_168 , V_27 ,
& V_30 -> V_37 , V_32 ) ;
if ( V_30 -> V_148 == NULL ) {
F_18 ( V_30 ) ;
return - V_18 ;
}
V_30 -> V_34 = V_169 ;
V_30 -> V_27 = V_27 ;
V_30 -> V_25 = V_25 ;
V_30 -> V_7 = V_7 ;
F_16 ( & V_30 -> V_38 ) ;
F_20 ( & V_7 -> V_42 ) ;
F_17 ( & V_30 -> V_39 , & V_7 -> V_40 ) ;
F_22 ( & V_7 -> V_42 ) ;
* V_167 = V_30 ;
return 0 ;
}
static int F_81 ( struct V_24 * V_25 , void T_1 * V_3 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
struct V_23 * V_7 = V_2 -> V_7 ;
struct V_170 V_30 ;
struct V_29 * V_167 = NULL ;
int V_13 ;
if ( F_2 ( F_3 ( & V_30 , V_3 , sizeof( V_30 ) ) ) )
return - V_15 ;
V_13 = F_79 ( V_7 , V_25 , V_30 . V_12 , & V_167 ) ;
if ( V_13 )
return V_13 ;
V_30 . V_171 = V_167 -> V_37 ;
if ( F_2 ( F_7 ( V_3 , & V_30 , sizeof( V_30 ) ) ) ) {
F_20 ( & V_7 -> V_42 ) ;
F_27 ( & V_167 -> V_38 , V_52 ) ;
F_22 ( & V_7 -> V_42 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_82 ( struct V_24 * V_25 , void T_1 * V_3 )
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
if ( V_30 -> V_34 == V_169 && V_30 -> V_37 == V_47 &&
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
static int F_76 ( struct V_24 * V_25 , void * V_3 )
{
return - V_109 ;
}
static int F_77 ( struct V_24 * V_25 , void T_1 * V_3 )
{
return - V_109 ;
}
static int F_81 ( struct V_24 * V_25 , void T_1 * V_3 )
{
return - V_109 ;
}
static int F_82 ( struct V_24 * V_25 , void T_1 * V_3 )
{
return - V_109 ;
}
static int
F_83 ( struct V_23 * V_7 , struct V_24 * V_25 ,
T_5 V_26 , T_5 V_27 ,
struct V_29 * * V_167 )
{
struct V_5 * V_6 = V_7 -> V_6 ;
struct V_29 * V_30 ;
int V_13 ;
if ( V_27 > 0xffffffff )
return - V_17 ;
V_30 = F_14 ( sizeof( * V_30 ) , V_32 ) ;
if ( V_30 == NULL )
return - V_18 ;
V_30 -> V_148 = F_80 ( V_6 -> V_68 . V_168 , V_27 ,
& V_30 -> V_37 , V_32 ) ;
if ( V_30 -> V_148 == NULL ) {
V_13 = - V_18 ;
goto V_172;
}
if ( V_26 == V_173 )
V_26 = V_30 -> V_37 ;
V_13 = F_84 ( V_6 , V_30 -> V_37 , V_26 , ( T_2 ) V_27 , 0 ) ;
if ( V_13 < 0 )
goto V_174;
V_30 -> V_34 = V_175 ;
V_30 -> V_36 = V_26 ;
V_30 -> V_27 = V_27 ;
V_30 -> V_25 = V_25 ;
V_30 -> V_7 = V_7 ;
F_16 ( & V_30 -> V_38 ) ;
F_20 ( & V_7 -> V_42 ) ;
F_17 ( & V_30 -> V_39 , & V_7 -> V_40 ) ;
F_22 ( & V_7 -> V_42 ) ;
* V_167 = V_30 ;
return 0 ;
V_174:
F_85 ( V_6 -> V_68 . V_168 , V_27 ,
V_30 -> V_148 , V_30 -> V_37 ) ;
V_172:
F_18 ( V_30 ) ;
return V_13 ;
}
static int
F_86 ( struct V_23 * V_7 , struct V_24 * V_25 ,
T_5 V_26 , T_5 V_27 ,
struct V_29 * * V_167 )
{
struct V_29 * V_30 ;
int V_41 = - V_18 ;
if ( V_26 == V_173 )
goto V_176;
F_20 ( & V_7 -> V_42 ) ;
F_21 (map, &md->mappings, node) {
if ( V_30 -> V_34 != V_175 )
continue;
if ( V_26 == V_30 -> V_36 && V_27 == V_30 -> V_27 ) {
* V_167 = V_30 ;
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
V_176:
return F_83 ( V_7 , V_25 , V_26 , V_27 , V_167 ) ;
}
static int F_87 ( struct V_24 * V_25 , void T_1 * V_3 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
struct V_23 * V_7 = V_2 -> V_7 ;
struct V_46 V_30 ;
struct V_29 * V_167 = NULL ;
int V_13 ;
if ( ! V_7 -> V_6 -> V_49 -> V_177 )
return - V_51 ;
if ( F_2 ( F_3 ( & V_30 , V_3 , sizeof( V_30 ) ) ) )
return - V_15 ;
F_13 ( V_178 , L_32 , F_59 ( & V_2 -> V_7 -> V_68 ) , V_25 ) ;
V_13 = F_86 ( V_7 , V_25 , V_30 . V_36 ,
V_30 . V_12 , & V_167 ) ;
if ( V_13 )
return V_13 ;
V_30 . V_47 = V_167 -> V_37 ;
V_30 . V_36 = V_167 -> V_36 ;
if ( F_2 ( F_7 ( V_3 , & V_30 , sizeof( V_30 ) ) ) ) {
if ( V_13 == 0 && V_167 -> V_25 == V_25 ) {
F_20 ( & V_7 -> V_42 ) ;
F_27 ( & V_167 -> V_38 , V_52 ) ;
F_22 ( & V_7 -> V_42 ) ;
}
return - V_15 ;
}
return 0 ;
}
static int F_88 ( struct V_24 * V_25 , void T_1 * V_3 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
struct V_23 * V_7 = V_2 -> V_7 ;
T_5 V_47 ;
struct V_29 * V_30 , * V_48 ;
F_13 ( V_178 , L_32 , F_59 ( & V_2 -> V_7 -> V_68 ) , V_25 ) ;
if ( ! V_7 -> V_6 -> V_49 -> V_179 )
return - V_51 ;
if ( F_3 ( & V_47 , V_3 , sizeof( V_47 ) ) )
return - V_15 ;
F_20 ( & V_7 -> V_42 ) ;
F_26 (map, _map, &md->mappings, node) {
if ( V_30 -> V_34 == V_175 && V_30 -> V_37 == V_47 ) {
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
static int F_89 ( struct V_1 * V_2 , void T_1 * V_3 )
{
struct V_23 * V_7 = V_2 -> V_7 ;
T_2 V_180 = V_7 -> V_6 -> V_181 ;
F_13 ( V_56 , L_33 , V_180 ) ;
if ( F_7 ( V_3 , & V_180 , sizeof( V_180 ) ) )
return - V_15 ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_182 * V_183 )
{
int V_184 ;
if ( ! ( V_2 -> V_185 & V_183 -> V_186 ) )
return - V_187 ;
F_65 ( & V_2 -> V_188 ) ;
V_184 = F_91 ( & V_2 -> V_189 ) < sizeof( * V_183 )
|| F_92 ( & V_2 -> V_189 , ( unsigned char * ) V_183 ,
sizeof( * V_183 ) ) != sizeof( * V_183 ) ;
F_66 ( & V_2 -> V_188 ) ;
F_93 ( & V_2 -> V_190 ) ;
if ( V_184 ) {
F_94 ( & V_2 -> V_7 -> V_68 , V_191 L_34 ) ;
return - V_43 ;
}
return 0 ;
}
static void F_95 ( struct V_5 * V_6 , void * V_192 ,
T_4 V_193 , T_4 V_194 , T_4 V_195 )
{
struct V_23 * V_45 = V_192 ;
struct V_1 * V_2 ;
struct V_196 * V_197 ;
struct V_182 V_183 ;
int V_198 ;
V_183 . V_186 = V_199 ;
V_183 . V_200 . V_201 . V_19 = V_193 ;
V_183 . V_200 . V_201 . V_202 = V_195 ;
V_198 = 0 ;
F_65 ( & V_45 -> V_203 ) ;
F_21 (db_filter, &data->doorbells, data_node) {
if ( ( ( V_197 -> V_204 . V_19 == V_205 ||
V_197 -> V_204 . V_19 == V_193 ) ) &&
V_195 >= V_197 -> V_204 . V_206 &&
V_195 <= V_197 -> V_204 . V_207 ) {
V_2 = V_197 -> V_2 ;
F_90 ( V_2 , & V_183 ) ;
V_198 = 1 ;
}
}
F_66 ( & V_45 -> V_203 ) ;
if ( ! V_198 )
F_94 ( & V_45 -> V_68 ,
L_35 ,
V_208 , V_193 , V_195 ) ;
}
static int F_96 ( struct V_1 * V_2 ,
void T_1 * V_3 )
{
struct V_23 * V_7 = V_2 -> V_7 ;
struct V_196 * V_197 ;
struct V_209 V_204 ;
unsigned long V_91 ;
int V_13 ;
if ( F_3 ( & V_204 , V_3 , sizeof( V_204 ) ) )
return - V_15 ;
if ( V_204 . V_206 > V_204 . V_207 )
return - V_17 ;
V_13 = F_97 ( V_7 -> V_6 , V_7 , V_204 . V_206 , V_204 . V_207 ,
F_95 ) ;
if ( V_13 ) {
F_24 ( L_36 ,
F_59 ( & V_7 -> V_68 ) , V_13 ) ;
return V_13 ;
}
V_197 = F_14 ( sizeof( * V_197 ) , V_32 ) ;
if ( V_197 == NULL ) {
F_98 ( V_7 -> V_6 , V_204 . V_206 , V_204 . V_207 ) ;
return - V_18 ;
}
V_197 -> V_204 = V_204 ;
V_197 -> V_2 = V_2 ;
F_99 ( & V_7 -> V_203 , V_91 ) ;
F_17 ( & V_197 -> V_210 , & V_2 -> V_211 ) ;
F_17 ( & V_197 -> V_212 , & V_7 -> V_213 ) ;
F_100 ( & V_7 -> V_203 , V_91 ) ;
return 0 ;
}
static void F_101 ( struct V_196 * V_197 )
{
F_78 ( & V_197 -> V_212 ) ;
F_78 ( & V_197 -> V_210 ) ;
F_18 ( V_197 ) ;
}
static int F_102 ( struct V_1 * V_2 ,
void T_1 * V_3 )
{
struct V_196 * V_197 ;
struct V_209 V_204 ;
unsigned long V_91 ;
int V_13 = - V_17 ;
if ( F_3 ( & V_204 , V_3 , sizeof( V_204 ) ) )
return - V_15 ;
if ( V_204 . V_206 > V_204 . V_207 )
return - V_17 ;
F_99 ( & V_2 -> V_7 -> V_203 , V_91 ) ;
F_21 (db_filter, &priv->db_filters, priv_node) {
if ( V_197 -> V_204 . V_19 == V_204 . V_19 &&
V_197 -> V_204 . V_206 == V_204 . V_206 &&
V_197 -> V_204 . V_207 == V_204 . V_207 ) {
F_101 ( V_197 ) ;
V_13 = 0 ;
break;
}
}
F_100 ( & V_2 -> V_7 -> V_203 , V_91 ) ;
if ( ! V_13 )
F_98 ( V_2 -> V_7 -> V_6 , V_204 . V_206 , V_204 . V_207 ) ;
return V_13 ;
}
static int F_103 ( union V_214 * V_215 ,
struct V_216 * V_204 )
{
if ( ( V_215 -> V_217 . V_57 & V_204 -> V_218 ) < V_204 -> V_206 ||
( V_215 -> V_217 . V_57 & V_204 -> V_218 ) > V_204 -> V_207 )
return 0 ;
return 1 ;
}
static int F_104 ( struct V_5 * V_6 , void * V_219 ,
union V_214 * V_215 , int V_220 )
{
struct V_23 * V_7 = V_219 ;
struct V_1 * V_2 ;
struct V_221 * V_222 ;
struct V_182 V_183 ;
int V_198 ;
V_183 . V_186 = V_223 ;
memcpy ( V_183 . V_200 . V_224 . V_202 , V_215 -> V_225 , V_226 ) ;
V_198 = 0 ;
F_65 ( & V_7 -> V_227 ) ;
F_21 (pw_filter, &md->portwrites, md_node) {
if ( F_103 ( V_215 , & V_222 -> V_204 ) ) {
V_2 = V_222 -> V_2 ;
F_90 ( V_2 , & V_183 ) ;
V_198 = 1 ;
}
}
F_66 ( & V_7 -> V_227 ) ;
if ( ! V_198 ) {
F_105 (KERN_WARNING DRV_NAME
L_37 ,
mport->id, msg->em.comptag) ;
}
return 0 ;
}
static int F_106 ( struct V_1 * V_2 ,
void T_1 * V_3 )
{
struct V_23 * V_7 = V_2 -> V_7 ;
struct V_221 * V_222 ;
struct V_216 V_204 ;
unsigned long V_91 ;
int V_228 = 0 ;
if ( F_3 ( & V_204 , V_3 , sizeof( V_204 ) ) )
return - V_15 ;
V_222 = F_14 ( sizeof( * V_222 ) , V_32 ) ;
if ( V_222 == NULL )
return - V_18 ;
V_222 -> V_204 = V_204 ;
V_222 -> V_2 = V_2 ;
F_99 ( & V_7 -> V_227 , V_91 ) ;
if ( F_107 ( & V_7 -> V_229 ) )
V_228 = 1 ;
F_17 ( & V_222 -> V_210 , & V_2 -> V_230 ) ;
F_17 ( & V_222 -> V_231 , & V_7 -> V_229 ) ;
F_100 ( & V_7 -> V_227 , V_91 ) ;
if ( V_228 ) {
int V_13 ;
V_13 = F_108 ( V_7 -> V_6 , V_7 ,
F_104 ) ;
if ( V_13 ) {
F_109 ( & V_7 -> V_68 ,
L_38 ,
V_208 , V_13 ) ;
return V_13 ;
}
F_110 ( V_7 -> V_6 , 1 ) ;
}
return 0 ;
}
static void F_111 ( struct V_221 * V_222 )
{
F_78 ( & V_222 -> V_231 ) ;
F_78 ( & V_222 -> V_210 ) ;
F_18 ( V_222 ) ;
}
static int F_112 ( struct V_216 * V_232 ,
struct V_216 * V_233 )
{
if ( ( V_232 -> V_218 == V_233 -> V_218 ) && ( V_232 -> V_206 == V_233 -> V_206 ) && ( V_232 -> V_207 == V_233 -> V_207 ) )
return 1 ;
return 0 ;
}
static int F_113 ( struct V_1 * V_2 ,
void T_1 * V_3 )
{
struct V_23 * V_7 = V_2 -> V_7 ;
struct V_221 * V_222 ;
struct V_216 V_204 ;
unsigned long V_91 ;
int V_13 = - V_17 ;
int V_234 = 0 ;
if ( F_3 ( & V_204 , V_3 , sizeof( V_204 ) ) )
return - V_15 ;
F_99 ( & V_7 -> V_227 , V_91 ) ;
F_21 (pw_filter, &priv->pw_filters, priv_node) {
if ( F_112 ( & V_222 -> V_204 , & V_204 ) ) {
F_111 ( V_222 ) ;
V_13 = 0 ;
break;
}
}
if ( F_107 ( & V_7 -> V_229 ) )
V_234 = 1 ;
F_100 ( & V_7 -> V_227 , V_91 ) ;
if ( V_234 ) {
F_114 ( V_7 -> V_6 , V_2 -> V_7 ,
F_104 ) ;
F_110 ( V_7 -> V_6 , 0 ) ;
}
return V_13 ;
}
static void F_115 ( struct V_67 * V_68 )
{
struct V_235 * V_236 ;
V_236 = F_116 ( V_68 ) ;
F_117 ( V_237 L_39 , V_208 , F_118 ( V_236 ) ) ;
F_18 ( V_236 ) ;
}
static void F_119 ( struct V_67 * V_68 )
{
struct V_238 * V_239 ;
V_239 = F_120 ( V_68 ) ;
F_13 ( V_240 , L_40 , V_239 -> V_241 ) ;
F_18 ( V_239 ) ;
}
static int F_121 ( struct V_1 * V_2 ,
void T_1 * V_3 )
{
struct V_23 * V_7 = V_2 -> V_7 ;
struct V_242 V_243 ;
struct V_235 * V_236 ;
struct V_244 * V_245 = NULL ;
struct V_5 * V_6 ;
T_3 V_27 ;
T_2 V_246 ;
T_2 V_247 = 0 ;
T_4 V_248 ;
T_8 V_20 ;
int V_41 ;
if ( F_3 ( & V_243 , V_3 , sizeof( V_243 ) ) )
return - V_15 ;
F_13 ( V_240 , L_41 , V_243 . V_249 ,
V_243 . V_57 , V_243 . V_248 , V_243 . V_20 ) ;
if ( F_122 ( & V_250 , NULL , V_243 . V_249 ) ) {
F_13 ( V_240 , L_42 , V_243 . V_249 ) ;
return - V_251 ;
}
V_27 = sizeof( * V_236 ) ;
V_6 = V_7 -> V_6 ;
V_248 = V_243 . V_248 ;
V_20 = V_243 . V_20 ;
if ( F_6 ( V_6 , V_248 , V_20 ,
V_252 , & V_246 ) )
return - V_124 ;
if ( V_246 & V_253 ) {
F_6 ( V_6 , V_248 , V_20 ,
V_254 , & V_247 ) ;
V_27 += ( F_123 ( V_247 ) *
sizeof( V_245 -> V_255 [ 0 ] ) ) + sizeof( * V_245 ) ;
}
V_236 = F_14 ( V_27 , V_32 ) ;
if ( V_236 == NULL )
return - V_18 ;
if ( V_6 -> V_239 == NULL ) {
struct V_238 * V_239 ;
V_239 = F_124 ( V_6 ) ;
if ( ! V_239 ) {
V_41 = - V_18 ;
F_13 ( V_240 , L_43 ) ;
goto V_256;
}
V_239 -> V_241 = V_6 -> V_241 ;
V_239 -> V_257 = V_6 ;
F_125 ( & V_239 -> V_68 , L_44 , V_239 -> V_241 ) ;
V_239 -> V_68 . V_168 = & V_6 -> V_68 ;
V_239 -> V_68 . V_258 = F_119 ;
V_41 = F_126 ( V_239 ) ;
if ( V_41 ) {
F_13 ( V_240 , L_45 , V_41 ) ;
F_18 ( V_239 ) ;
goto V_256;
}
}
V_236 -> V_239 = V_6 -> V_239 ;
V_236 -> V_259 = V_246 ;
V_236 -> V_247 = V_247 ;
F_6 ( V_6 , V_248 , V_20 ,
V_260 , & V_246 ) ;
V_236 -> V_261 = V_246 >> 16 ;
V_236 -> V_262 = V_246 & 0xffff ;
F_6 ( V_6 , V_248 , V_20 , V_263 ,
& V_236 -> V_264 ) ;
F_6 ( V_6 , V_248 , V_20 , V_265 ,
& V_246 ) ;
V_236 -> V_266 = V_246 >> 16 ;
V_236 -> V_267 = V_246 & 0xffff ;
F_6 ( V_6 , V_248 , V_20 , V_268 ,
& V_246 ) ;
V_236 -> V_269 = V_246 >> 16 ;
if ( V_236 -> V_259 & V_270 ) {
V_236 -> V_271 = V_246 & 0xffff ;
V_236 -> V_272 = F_127 ( V_6 , 0 , V_248 ,
V_20 , & V_236 -> V_273 ) ;
V_236 -> V_274 = F_128 ( V_6 , 0 , V_248 ,
V_20 , V_275 ) ;
}
F_6 ( V_6 , V_248 , V_20 , V_276 ,
& V_236 -> V_277 ) ;
F_6 ( V_6 , V_248 , V_20 , V_278 ,
& V_236 -> V_279 ) ;
V_236 -> V_280 = V_243 . V_57 ;
V_236 -> V_248 = V_248 ;
V_236 -> V_20 = V_20 ;
if ( V_236 -> V_259 & V_253 ) {
V_245 = V_236 -> V_245 ;
V_245 -> V_281 = NULL ;
}
if ( strlen ( V_243 . V_249 ) )
F_125 ( & V_236 -> V_68 , L_46 , V_243 . V_249 ) ;
else if ( V_236 -> V_259 & V_253 )
F_125 ( & V_236 -> V_68 , L_47 , V_6 -> V_241 ,
V_236 -> V_280 & V_282 ) ;
else
F_125 ( & V_236 -> V_68 , L_48 , V_6 -> V_241 ,
V_236 -> V_280 & V_282 ) ;
F_129 ( & V_236 -> V_283 ) ;
V_236 -> V_68 . V_168 = & V_6 -> V_239 -> V_68 ;
F_130 ( V_236 ) ;
V_236 -> V_68 . V_258 = F_115 ;
if ( V_236 -> V_279 & V_284 )
F_131 ( & V_236 -> V_285 [ V_286 ] ,
0 , 0xffff ) ;
V_41 = F_132 ( V_236 ) ;
if ( V_41 )
goto V_256;
F_133 ( V_236 ) ;
return 0 ;
V_256:
F_18 ( V_236 ) ;
return V_41 ;
}
static int F_134 ( struct V_1 * V_2 , void T_1 * V_3 )
{
struct V_242 V_243 ;
struct V_235 * V_236 = NULL ;
struct V_67 * V_68 ;
struct V_5 * V_6 ;
struct V_238 * V_239 ;
if ( F_3 ( & V_243 , V_3 , sizeof( V_243 ) ) )
return - V_15 ;
V_6 = V_2 -> V_7 -> V_6 ;
if ( strlen ( V_243 . V_249 ) ) {
V_68 = F_122 ( & V_250 , NULL ,
V_243 . V_249 ) ;
if ( V_68 )
V_236 = F_116 ( V_68 ) ;
} else {
do {
V_236 = F_135 ( V_243 . V_57 , V_236 ) ;
if ( V_236 && V_236 -> V_68 . V_168 == & V_6 -> V_239 -> V_68 &&
V_236 -> V_248 == V_243 . V_248 &&
V_236 -> V_20 == V_243 . V_20 )
break;
} while ( V_236 );
}
if ( ! V_236 ) {
F_13 ( V_240 ,
L_49 ,
V_243 . V_249 , V_243 . V_57 , V_243 . V_248 ,
V_243 . V_20 ) ;
return - V_109 ;
}
V_239 = V_236 -> V_239 ;
F_136 ( V_236 ) ;
F_137 ( V_236 , V_287 ) ;
if ( F_107 ( & V_239 -> V_288 ) ) {
F_138 ( V_239 ) ;
V_6 -> V_239 = NULL ;
}
return 0 ;
}
static int F_139 ( struct V_289 * V_289 , struct V_24 * V_25 )
{
int V_13 ;
int V_290 = F_140 ( V_289 ) ;
struct V_23 * V_291 ;
struct V_1 * V_2 ;
if ( V_290 >= V_292 ) {
F_24 ( L_50 ) ;
return - V_17 ;
}
V_291 = F_33 ( V_289 -> V_293 , struct V_23 , V_294 ) ;
F_13 ( V_295 , L_32 , F_59 ( & V_291 -> V_68 ) , V_25 ) ;
if ( F_141 ( & V_291 -> V_296 ) == 0 )
return - V_109 ;
F_142 ( & V_291 -> V_68 ) ;
V_2 = F_14 ( sizeof( * V_2 ) , V_32 ) ;
if ( ! V_2 ) {
F_143 ( & V_291 -> V_68 ) ;
return - V_18 ;
}
V_2 -> V_7 = V_291 ;
F_20 ( & V_291 -> V_297 ) ;
F_17 ( & V_2 -> V_298 , & V_291 -> V_299 ) ;
F_22 ( & V_291 -> V_297 ) ;
F_129 ( & V_2 -> V_211 ) ;
F_129 ( & V_2 -> V_230 ) ;
F_144 ( & V_2 -> V_188 ) ;
F_145 ( & V_2 -> V_190 ) ;
V_13 = F_146 ( & V_2 -> V_189 ,
sizeof( struct V_182 ) * V_300 ,
V_32 ) ;
if ( V_13 < 0 ) {
F_109 ( & V_291 -> V_68 , V_191 L_51 ) ;
V_13 = - V_18 ;
goto V_301;
}
#ifdef F_147
F_129 ( & V_2 -> V_132 ) ;
F_129 ( & V_2 -> V_151 ) ;
F_144 ( & V_2 -> V_131 ) ;
F_148 ( & V_2 -> V_108 ) ;
#endif
V_25 -> V_44 = V_2 ;
goto V_21;
V_301:
F_18 ( V_2 ) ;
V_21:
return V_13 ;
}
static int F_149 ( int V_302 , struct V_24 * V_25 , int V_303 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
return F_150 ( V_302 , V_25 , V_303 , & V_2 -> V_304 ) ;
}
static void F_151 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
struct V_23 * V_7 ;
struct V_65 * V_66 , * V_305 ;
unsigned long V_115 = F_57 ( V_116 ) ;
long V_117 ;
F_152 ( V_298 ) ;
F_13 ( EXIT , L_52 ,
V_25 , V_120 -> V_121 , F_58 ( V_120 ) ) ;
if ( ! V_2 -> V_63 ) {
F_13 ( EXIT , L_53 , V_25 ) ;
return;
}
V_7 = V_2 -> V_7 ;
F_153 ( V_83 ) ;
F_65 ( & V_2 -> V_131 ) ;
if ( ! F_107 ( & V_2 -> V_132 ) ) {
F_13 ( EXIT , L_54 ,
V_25 , V_120 -> V_121 , F_58 ( V_120 ) ) ;
F_154 ( & V_2 -> V_132 , & V_298 ) ;
}
F_66 ( & V_2 -> V_131 ) ;
if ( ! F_107 ( & V_298 ) ) {
F_13 ( EXIT , L_55 ) ;
F_26 (req, req_next, &list, node) {
F_13 ( EXIT , L_56 ,
V_66 -> V_25 , V_66 -> V_76 ,
F_155 ( & V_66 -> V_77 ) ? L_57 : L_58 ) ;
F_78 ( & V_66 -> V_39 ) ;
F_37 ( V_66 ) ;
}
}
if ( ! F_107 ( & V_2 -> V_151 ) ) {
F_13 ( EXIT , L_59 ,
V_25 , V_120 -> V_121 , F_58 ( V_120 ) ) ;
F_26 (req,
req_next, &priv->pend_list, node) {
F_13 ( EXIT , L_56 ,
V_66 -> V_25 , V_66 -> V_76 ,
F_155 ( & V_66 -> V_77 ) ? L_57 : L_58 ) ;
F_78 ( & V_66 -> V_39 ) ;
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
if ( ! F_107 ( & V_2 -> V_151 ) ) {
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
static int F_156 ( struct V_289 * V_289 , struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
struct V_23 * V_291 ;
struct V_221 * V_222 , * V_306 ;
struct V_196 * V_197 , * V_307 ;
struct V_29 * V_30 , * V_48 ;
unsigned long V_91 ;
F_13 ( EXIT , L_32 , F_59 ( & V_2 -> V_7 -> V_68 ) , V_25 ) ;
V_291 = V_2 -> V_7 ;
F_151 ( V_25 ) ;
V_2 -> V_185 = 0 ;
F_99 ( & V_291 -> V_227 , V_91 ) ;
if ( ! F_107 ( & V_2 -> V_230 ) ) {
F_26 (pw_filter, pw_filter_next,
&priv->pw_filters, priv_node)
F_111 ( V_222 ) ;
}
F_100 ( & V_291 -> V_227 , V_91 ) ;
F_99 ( & V_291 -> V_203 , V_91 ) ;
F_26 (db_filter, db_filter_next,
&priv->db_filters, priv_node) {
F_101 ( V_197 ) ;
}
F_100 ( & V_291 -> V_203 , V_91 ) ;
F_157 ( & V_2 -> V_189 ) ;
F_20 ( & V_291 -> V_42 ) ;
F_26 (map, _map, &chdev->mappings, node) {
if ( V_30 -> V_25 == V_25 ) {
F_13 ( EXIT , L_64 ,
V_30 -> V_148 , V_25 ) ;
F_27 ( & V_30 -> V_38 , V_52 ) ;
}
}
F_22 ( & V_291 -> V_42 ) ;
F_149 ( - 1 , V_25 , 0 ) ;
V_25 -> V_44 = NULL ;
F_20 ( & V_291 -> V_297 ) ;
F_78 ( & V_2 -> V_298 ) ;
F_22 ( & V_291 -> V_297 ) ;
F_143 ( & V_291 -> V_68 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
static long F_158 ( struct V_24 * V_25 ,
unsigned int V_308 , unsigned long V_3 )
{
int V_41 = - V_17 ;
struct V_1 * V_45 = V_25 -> V_44 ;
struct V_23 * V_7 = V_45 -> V_7 ;
if ( F_141 ( & V_7 -> V_296 ) == 0 )
return - V_109 ;
switch ( V_308 ) {
case V_309 :
return F_1 ( V_45 , ( void T_1 * ) V_3 , 1 ) ;
case V_310 :
return F_9 ( V_45 , ( void T_1 * ) V_3 , 1 ) ;
case V_311 :
return F_1 ( V_45 , ( void T_1 * ) V_3 , 0 ) ;
case V_312 :
return F_9 ( V_45 , ( void T_1 * ) V_3 , 0 ) ;
case V_313 :
return F_28 ( V_45 , ( void T_1 * ) V_3 ) ;
case V_314 :
return F_30 ( V_45 , ( void T_1 * ) V_3 ) ;
case V_315 :
return F_89 ( V_45 , ( void T_1 * ) V_3 ) ;
case V_316 :
V_7 -> V_55 . V_53 = V_7 -> V_6 -> V_54 ;
if ( F_7 ( ( void T_1 * ) V_3 , & ( V_7 -> V_55 ) ,
sizeof( V_7 -> V_55 ) ) )
return - V_15 ;
return 0 ;
case V_317 :
return F_96 ( V_45 , ( void T_1 * ) V_3 ) ;
case V_318 :
return F_102 ( V_45 , ( void T_1 * ) V_3 ) ;
case V_319 :
return F_106 ( V_45 , ( void T_1 * ) V_3 ) ;
case V_320 :
return F_113 ( V_45 , ( void T_1 * ) V_3 ) ;
case V_321 :
V_45 -> V_185 = ( T_2 ) V_3 ;
return 0 ;
case V_322 :
if ( F_7 ( ( void T_1 * ) V_3 , & V_45 -> V_185 ,
sizeof( T_2 ) ) )
return - V_15 ;
return 0 ;
case V_323 :
return F_23 ( V_25 , ( void T_1 * ) V_3 ) ;
case V_324 :
return F_87 ( V_25 , ( void T_1 * ) V_3 ) ;
case V_325 :
return F_25 ( V_25 , ( void T_1 * ) V_3 ) ;
case V_326 :
return F_88 ( V_25 , ( void T_1 * ) V_3 ) ;
case V_327 :
return F_81 ( V_25 , ( void T_1 * ) V_3 ) ;
case V_328 :
return F_82 ( V_25 , ( void T_1 * ) V_3 ) ;
case V_329 :
return F_77 ( V_25 , ( void T_1 * ) V_3 ) ;
case V_330 :
return F_76 ( V_25 , ( void T_1 * ) V_3 ) ;
case V_331 :
return F_121 ( V_45 , ( void T_1 * ) V_3 ) ;
case V_332 :
return F_134 ( V_45 , ( void T_1 * ) V_3 ) ;
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
F_13 ( V_333 , L_65 ,
V_30 -> V_34 , V_30 -> V_148 ,
& V_30 -> V_37 , V_6 -> V_249 ) ;
F_78 ( & V_30 -> V_39 ) ;
switch ( V_30 -> V_34 ) {
case V_175 :
F_159 ( V_6 , V_30 -> V_37 ) ;
case V_169 :
F_85 ( V_6 -> V_68 . V_168 , V_30 -> V_27 ,
V_30 -> V_148 , V_30 -> V_37 ) ;
break;
case V_35 :
F_160 ( V_6 , V_30 -> V_19 , V_30 -> V_36 ) ;
break;
}
F_18 ( V_30 ) ;
}
static void F_161 ( struct V_334 * V_335 )
{
struct V_29 * V_30 = V_335 -> V_336 ;
F_13 ( V_333 , L_66 , & V_30 -> V_37 ) ;
F_53 ( & V_30 -> V_38 ) ;
}
static void F_162 ( struct V_334 * V_335 )
{
struct V_29 * V_30 = V_335 -> V_336 ;
F_13 ( V_333 , L_66 , & V_30 -> V_37 ) ;
F_20 ( & V_30 -> V_7 -> V_42 ) ;
F_27 ( & V_30 -> V_38 , V_52 ) ;
F_22 ( & V_30 -> V_7 -> V_42 ) ;
}
static int F_163 ( struct V_24 * V_25 , struct V_334 * V_335 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
struct V_23 * V_7 ;
T_3 V_27 = V_335 -> V_337 - V_335 -> V_338 ;
T_6 V_147 ;
unsigned long V_11 ;
int V_161 = 0 , V_13 ;
struct V_29 * V_30 ;
F_13 ( V_333 , L_67 ,
( unsigned int ) V_27 , V_335 -> V_339 ) ;
V_7 = V_2 -> V_7 ;
V_147 = ( ( T_6 ) V_335 -> V_339 << V_143 ) ;
F_20 ( & V_7 -> V_42 ) ;
F_21 (map, &md->mappings, node) {
if ( V_147 >= V_30 -> V_37 &&
V_147 < ( V_30 -> V_37 + V_30 -> V_27 ) ) {
V_161 = 1 ;
break;
}
}
F_22 ( & V_7 -> V_42 ) ;
if ( ! V_161 )
return - V_18 ;
V_11 = V_147 - V_30 -> V_37 ;
if ( V_27 + V_11 > V_30 -> V_27 )
return - V_17 ;
V_335 -> V_339 = V_11 >> V_143 ;
F_13 ( V_333 , L_68 , V_335 -> V_339 ) ;
if ( V_30 -> V_34 == V_175 || V_30 -> V_34 == V_169 )
V_13 = F_164 ( V_7 -> V_6 -> V_68 . V_168 , V_335 ,
V_30 -> V_148 , V_30 -> V_37 , V_30 -> V_27 ) ;
else if ( V_30 -> V_34 == V_35 ) {
V_335 -> V_340 = F_165 ( V_335 -> V_340 ) ;
V_13 = F_166 ( V_335 , V_30 -> V_37 , V_30 -> V_27 ) ;
} else {
F_24 ( L_69 ) ;
V_13 = - V_124 ;
}
if ( ! V_13 ) {
V_335 -> V_336 = V_30 ;
V_335 -> V_341 = & V_341 ;
F_161 ( V_335 ) ;
} else {
F_24 ( L_70 , V_13 ) ;
}
return V_13 ;
}
static unsigned int F_167 ( struct V_24 * V_25 , T_9 * V_342 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
F_168 ( V_25 , & V_2 -> V_190 , V_342 ) ;
if ( F_169 ( & V_2 -> V_189 ) )
return V_343 | V_344 ;
return 0 ;
}
static T_10 F_170 ( struct V_24 * V_25 , char T_1 * V_345 , T_3 V_154 ,
T_11 * V_346 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
int V_347 ;
T_10 V_13 ;
if ( ! V_154 )
return 0 ;
if ( F_171 ( & V_2 -> V_189 ) &&
( V_25 -> V_348 & V_349 ) )
return - V_164 ;
if ( V_154 % sizeof( struct V_182 ) )
return - V_17 ;
V_13 = F_172 ( V_2 -> V_190 ,
F_169 ( & V_2 -> V_189 ) != 0 ) ;
if ( V_13 )
return V_13 ;
while ( V_13 < V_154 ) {
if ( F_173 ( & V_2 -> V_189 , V_345 ,
sizeof( struct V_182 ) , & V_347 ) )
return - V_15 ;
V_13 += V_347 ;
V_345 += V_347 ;
}
return V_13 ;
}
static T_10 F_174 ( struct V_24 * V_25 , const char T_1 * V_345 ,
T_3 V_154 , T_11 * V_346 )
{
struct V_1 * V_2 = V_25 -> V_44 ;
struct V_5 * V_6 = V_2 -> V_7 -> V_6 ;
struct V_182 V_183 ;
int V_350 , V_13 ;
if ( ! V_154 )
return 0 ;
if ( V_154 % sizeof( V_183 ) )
return - V_17 ;
V_350 = 0 ;
while ( ( V_154 - V_350 ) >= ( int ) sizeof( V_183 ) ) {
if ( F_3 ( & V_183 , V_345 , sizeof( V_183 ) ) )
return - V_15 ;
if ( V_183 . V_186 != V_199 )
return - V_17 ;
V_13 = F_175 ( V_6 ,
V_183 . V_200 . V_201 . V_19 ,
V_183 . V_200 . V_201 . V_202 ) ;
if ( V_13 < 0 )
return V_13 ;
V_350 += sizeof( V_183 ) ;
V_345 += sizeof( V_183 ) ;
}
return V_350 ;
}
static void F_176 ( struct V_67 * V_68 )
{
struct V_23 * V_7 ;
F_13 ( EXIT , L_46 , F_59 ( V_68 ) ) ;
V_7 = F_33 ( V_68 , struct V_23 , V_68 ) ;
F_18 ( V_7 ) ;
}
static struct V_23 * F_177 ( struct V_5 * V_6 )
{
int V_13 = 0 ;
struct V_23 * V_7 ;
struct V_351 V_352 ;
V_7 = F_14 ( sizeof( * V_7 ) , V_32 ) ;
if ( ! V_7 ) {
F_24 ( L_71 ) ;
return NULL ;
}
V_7 -> V_6 = V_6 ;
F_148 ( & V_7 -> V_42 ) ;
F_148 ( & V_7 -> V_297 ) ;
F_129 ( & V_7 -> V_299 ) ;
F_178 ( & V_7 -> V_68 ) ;
V_7 -> V_68 . V_353 = F_179 ( F_180 ( V_354 ) , V_6 -> V_241 ) ;
V_7 -> V_68 . V_355 = V_356 ;
V_7 -> V_68 . V_168 = & V_6 -> V_68 ;
V_7 -> V_68 . V_258 = F_176 ;
F_125 ( & V_7 -> V_68 , V_357 L_72 , V_6 -> V_241 ) ;
F_181 ( & V_7 -> V_296 , 1 ) ;
F_182 ( & V_7 -> V_294 , & V_358 ) ;
V_7 -> V_294 . V_359 = V_360 ;
V_13 = F_183 ( & V_7 -> V_294 , & V_7 -> V_68 ) ;
if ( V_13 ) {
F_24 ( L_73 ,
V_6 -> V_241 , V_13 ) ;
goto V_361;
}
F_129 ( & V_7 -> V_213 ) ;
F_144 ( & V_7 -> V_203 ) ;
F_129 ( & V_7 -> V_229 ) ;
F_144 ( & V_7 -> V_227 ) ;
F_129 ( & V_7 -> V_40 ) ;
V_7 -> V_55 . V_241 = V_6 -> V_241 ;
V_7 -> V_55 . V_362 = V_6 -> V_362 ;
V_7 -> V_55 . V_53 = V_6 -> V_54 ;
V_7 -> V_55 . V_181 = V_6 -> V_181 ;
#ifdef F_184
V_7 -> V_55 . V_137 |= V_363 ;
#else
V_7 -> V_55 . V_137 |= V_364 ;
#endif
V_13 = F_185 ( V_6 , & V_352 ) ;
if ( ! V_13 ) {
V_7 -> V_55 . V_91 = V_352 . V_91 ;
V_7 -> V_55 . V_365 = V_352 . V_365 ;
V_7 -> V_55 . V_366 = V_352 . V_366 ;
V_7 -> V_55 . V_367 = V_352 . V_367 ;
V_7 -> V_55 . V_368 = V_352 . V_368 ;
V_7 -> V_55 . V_369 = V_352 . V_369 ;
V_7 -> V_55 . V_370 = 0 ;
V_7 -> V_55 . V_371 = 0 ;
V_7 -> V_55 . V_372 = 0 ;
} else
F_117 ( V_237 L_74 ,
V_6 -> V_249 , F_180 ( V_354 ) , V_6 -> V_241 ) ;
F_20 ( & V_373 ) ;
F_17 ( & V_7 -> V_39 , & V_374 ) ;
F_22 ( & V_373 ) ;
F_117 ( V_237 L_75 ,
V_6 -> V_249 , F_180 ( V_354 ) , V_6 -> V_241 ) ;
return V_7 ;
V_361:
F_143 ( & V_7 -> V_68 ) ;
return NULL ;
}
static void F_186 ( struct V_23 * V_7 )
{
#ifdef F_147
struct V_1 * V_375 ;
F_13 ( V_110 , L_46 , F_59 ( & V_7 -> V_68 ) ) ;
F_20 ( & V_7 -> V_297 ) ;
F_21 (client, &md->file_list, list) {
if ( V_375 -> V_63 ) {
F_187 ( V_375 -> V_63 ) ;
F_34 ( V_375 -> V_63 ) ;
}
}
F_22 ( & V_7 -> V_297 ) ;
if ( V_7 -> V_61 ) {
F_187 ( V_7 -> V_61 ) ;
F_34 ( V_7 -> V_61 ) ;
V_7 -> V_61 = NULL ;
}
#endif
}
static int F_188 ( struct V_23 * V_7 )
{
unsigned int V_376 = 0 ;
struct V_1 * V_375 ;
F_20 ( & V_7 -> V_297 ) ;
F_21 (client, &md->file_list, list) {
if ( V_375 -> V_304 )
F_189 ( & V_375 -> V_304 , V_377 , V_378 ) ;
V_376 ++ ;
}
F_22 ( & V_7 -> V_297 ) ;
return V_376 ;
}
static void F_190 ( struct V_23 * V_7 )
{
struct V_29 * V_30 , * V_48 ;
F_13 ( EXIT , L_76 , V_7 -> V_6 -> V_249 ) ;
F_181 ( & V_7 -> V_296 , 0 ) ;
F_186 ( V_7 ) ;
F_114 ( V_7 -> V_6 , V_7 , F_104 ) ;
F_191 ( & V_7 -> V_294 , & V_7 -> V_68 ) ;
F_188 ( V_7 ) ;
F_153 ( V_83 ) ;
F_20 ( & V_7 -> V_42 ) ;
F_26 (map, _map, &md->mappings, node) {
F_27 ( & V_30 -> V_38 , V_52 ) ;
}
F_22 ( & V_7 -> V_42 ) ;
if ( ! F_107 ( & V_7 -> V_40 ) )
F_192 ( L_77 ,
V_7 -> V_6 -> V_249 ) ;
F_98 ( V_7 -> V_6 , 0 , 0x0fff ) ;
F_143 ( & V_7 -> V_68 ) ;
}
static int F_193 ( struct V_67 * V_68 ,
struct V_379 * V_380 )
{
struct V_5 * V_6 = NULL ;
struct V_23 * V_291 = NULL ;
V_6 = F_194 ( V_68 ) ;
if ( ! V_6 )
return - V_109 ;
V_291 = F_177 ( V_6 ) ;
if ( ! V_291 )
return - V_109 ;
return 0 ;
}
static void F_195 ( struct V_67 * V_68 ,
struct V_379 * V_380 )
{
struct V_5 * V_6 = NULL ;
struct V_23 * V_291 ;
int V_161 = 0 ;
V_6 = F_194 ( V_68 ) ;
F_13 ( EXIT , L_78 , V_6 -> V_249 ) ;
F_20 ( & V_373 ) ;
F_21 (chdev, &mport_devs, node) {
if ( V_291 -> V_6 -> V_241 == V_6 -> V_241 ) {
F_181 ( & V_291 -> V_296 , 0 ) ;
F_78 ( & V_291 -> V_39 ) ;
V_161 = 1 ;
break;
}
}
F_22 ( & V_373 ) ;
if ( V_161 )
F_190 ( V_291 ) ;
}
static int T_12 F_196 ( void )
{
int V_13 ;
V_356 = F_197 ( V_360 , V_191 ) ;
if ( F_60 ( V_356 ) ) {
F_24 ( L_79 V_191 L_80 ) ;
return F_61 ( V_356 ) ;
}
V_13 = F_198 ( & V_354 , 0 , V_292 , V_191 ) ;
if ( V_13 < 0 )
goto V_381;
F_13 ( V_295 , L_81 , F_180 ( V_354 ) ) ;
V_13 = F_199 ( & V_382 ) ;
if ( V_13 ) {
F_24 ( L_82 , V_13 ) ;
goto V_383;
}
V_83 = F_200 ( L_83 ) ;
if ( ! V_83 ) {
F_24 ( L_84 ) ;
V_13 = - V_18 ;
goto V_384;
}
return 0 ;
V_384:
F_201 ( & V_382 ) ;
V_383:
F_202 ( V_354 , V_292 ) ;
V_381:
F_203 ( V_356 ) ;
return V_13 ;
}
static void T_13 F_204 ( void )
{
F_201 ( & V_382 ) ;
F_203 ( V_356 ) ;
F_202 ( V_354 , V_292 ) ;
F_205 ( V_83 ) ;
}
