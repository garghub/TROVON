static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( & V_4 -> V_5 . V_6 ,
F_4 ( V_7 + F_5 ( 100 ) ) ) ;
}
static void
F_6 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_9 -> V_11 . V_12 ; V_10 ++ )
F_7 ( V_9 -> V_13 [ V_10 ] ) ;
F_8 ( V_9 ) ;
}
int
F_9 ( struct V_1 * V_2 , void * V_14 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = V_14 ;
struct V_19 * V_20 ;
struct V_8 * V_21 ;
struct V_17 * V_9 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_22 ;
T_1 V_10 ;
int V_23 = 0 ;
F_10 ( & V_4 -> V_24 , V_22 ) ;
V_21 = V_4 -> V_25 ;
if ( ! V_21 ) {
F_11 ( & V_4 -> V_24 , V_22 ) ;
return - V_26 ;
}
V_9 = & V_21 -> V_11 ;
if ( V_18 -> V_12 < V_9 -> V_12 ) {
V_18 -> V_12 = V_9 -> V_12 ;
F_11 ( & V_4 -> V_24 , V_22 ) ;
return 0 ;
}
V_4 -> V_25 = NULL ;
F_11 ( & V_4 -> V_24 , V_22 ) ;
V_9 -> V_13 = V_18 -> V_13 ;
memcpy ( V_18 , V_9 , sizeof( * V_9 ) ) ;
V_20 = F_12 ( V_9 -> V_12 , sizeof( * V_20 ) , V_27 ) ;
if ( ! V_20 ) {
V_23 = - V_28 ;
goto V_29;
}
for ( V_10 = 0 ; V_10 < V_9 -> V_12 ; V_10 ++ ) {
struct V_30 * V_30 = F_13 ( V_21 -> V_13 [ V_10 ] ) ;
T_1 V_31 ;
V_23 = F_14 ( V_16 , V_21 -> V_13 [ V_10 ] ,
& V_31 ) ;
if ( V_23 ) {
V_9 -> V_12 = V_10 ;
goto V_32;
}
V_20 [ V_10 ] . V_31 = V_31 ;
V_20 [ V_10 ] . V_33 = V_30 -> V_34 . V_33 ;
V_20 [ V_10 ] . V_35 = V_30 -> V_34 . V_34 . V_35 ;
}
if ( F_15 ( ( void V_36 * ) ( V_37 ) V_18 -> V_13 ,
V_20 ,
V_9 -> V_12 * sizeof( * V_20 ) ) )
V_23 = - V_38 ;
V_32:
if ( V_23 ) {
for ( V_10 = 0 ; V_10 < V_9 -> V_12 ; V_10 ++ )
F_16 ( V_16 , V_20 [ V_10 ] . V_31 ) ;
}
V_29:
F_6 ( V_2 , V_21 ) ;
F_8 ( V_20 ) ;
return V_23 ;
}
static void
F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_17 * V_9 ;
struct V_8 * V_21 ;
struct V_39 * V_40 [ 2 ] ;
struct V_30 * V_13 ;
unsigned long V_22 ;
unsigned int V_10 , V_41 , V_42 , V_43 ;
V_21 = F_12 ( 1 , sizeof( * V_21 ) , V_27 ) ;
if ( ! V_21 )
return;
V_9 = & V_21 -> V_11 ;
F_10 ( & V_4 -> V_24 , V_22 ) ;
V_40 [ 0 ] = F_18 ( V_4 ) ;
V_40 [ 1 ] = F_19 ( V_4 ) ;
if ( ! V_40 [ 0 ] && ! V_40 [ 1 ] ) {
F_11 ( & V_4 -> V_24 , V_22 ) ;
return;
}
V_9 -> V_12 = 0 ;
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ ) {
if ( ! V_40 [ V_10 ] )
continue;
V_42 = 0 ;
F_20 (bo, &exec[i]->unref_list, unref_head)
V_42 ++ ;
V_9 -> V_12 += V_40 [ V_10 ] -> V_12 + V_42 ;
}
V_21 -> V_13 = F_12 ( V_9 -> V_12 ,
sizeof( * V_21 -> V_13 ) , V_44 ) ;
if ( ! V_21 -> V_13 ) {
F_11 ( & V_4 -> V_24 , V_22 ) ;
return;
}
V_43 = 0 ;
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ ) {
if ( ! V_40 [ V_10 ] )
continue;
for ( V_41 = 0 ; V_41 < V_40 [ V_10 ] -> V_12 ; V_41 ++ ) {
F_21 ( & V_40 [ V_10 ] -> V_13 [ V_41 ] -> V_34 ) ;
V_21 -> V_13 [ V_41 + V_43 ] = & V_40 [ V_10 ] -> V_13 [ V_41 ] -> V_34 ;
}
F_20 (bo, &exec[i]->unref_list, unref_head) {
F_21 ( & V_13 -> V_34 . V_34 ) ;
V_21 -> V_13 [ V_41 + V_43 ] = & V_13 -> V_34 . V_34 ;
V_41 ++ ;
}
V_43 = V_41 + 1 ;
}
if ( V_40 [ 0 ] )
V_9 -> V_45 = V_40 [ 0 ] -> V_46 ;
if ( V_40 [ 1 ] )
V_9 -> V_47 = V_40 [ 1 ] -> V_48 ;
F_11 ( & V_4 -> V_24 , V_22 ) ;
V_9 -> V_46 = F_22 ( F_23 ( 0 ) ) ;
V_9 -> V_49 = F_22 ( F_24 ( 0 ) ) ;
V_9 -> V_48 = F_22 ( F_23 ( 1 ) ) ;
V_9 -> V_50 = F_22 ( F_24 ( 1 ) ) ;
V_9 -> V_51 = F_22 ( F_25 ( 0 ) ) ;
V_9 -> V_52 = F_22 ( F_25 ( 1 ) ) ;
V_9 -> V_53 = F_22 ( V_54 ) ;
V_9 -> V_55 = F_22 ( V_56 ) ;
V_9 -> V_57 = F_22 ( V_58 ) ;
V_9 -> V_59 = F_22 ( V_60 ) ;
V_9 -> V_61 = F_22 ( V_62 ) ;
V_9 -> V_63 = F_22 ( V_64 ) ;
V_9 -> V_65 = F_22 ( V_66 ) ;
V_9 -> V_67 = F_22 ( V_68 ) ;
V_9 -> V_69 = F_22 ( V_70 ) ;
V_9 -> V_71 = F_22 ( V_72 ) ;
V_9 -> V_73 = F_22 ( V_74 ) ;
V_9 -> V_75 = F_22 ( V_76 ) ;
V_9 -> V_77 = F_22 ( V_78 ) ;
F_10 ( & V_4 -> V_24 , V_22 ) ;
if ( V_4 -> V_25 ) {
F_11 ( & V_4 -> V_24 , V_22 ) ;
F_6 ( V_2 , V_21 ) ;
} else {
V_4 -> V_25 = V_21 ;
F_11 ( & V_4 -> V_24 , V_22 ) ;
}
}
static void
F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_27 ( L_1 ) ;
F_28 ( & V_4 -> V_79 ) ;
if ( V_4 -> V_80 ) {
F_29 ( & V_4 -> V_81 -> V_82 -> V_2 ) ;
F_30 ( & V_4 -> V_81 -> V_82 -> V_2 ) ;
}
F_31 ( & V_4 -> V_79 ) ;
F_32 ( V_2 ) ;
F_1 ( V_2 ) ;
}
static void
F_33 ( struct V_83 * V_84 )
{
struct V_3 * V_4 =
F_34 ( V_84 , struct V_3 , V_5 . V_85 ) ;
F_17 ( V_4 -> V_2 ) ;
F_26 ( V_4 -> V_2 ) ;
}
static void
F_35 ( unsigned long V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_46 , V_48 ;
unsigned long V_22 ;
struct V_39 * V_86 , * V_87 ;
F_10 ( & V_4 -> V_24 , V_22 ) ;
V_86 = F_18 ( V_4 ) ;
V_87 = F_19 ( V_4 ) ;
if ( ! V_86 && ! V_87 ) {
F_11 ( & V_4 -> V_24 , V_22 ) ;
return;
}
V_46 = F_22 ( F_23 ( 0 ) ) ;
V_48 = F_22 ( F_23 ( 1 ) ) ;
if ( ( V_86 && V_46 != V_86 -> V_88 ) ||
( V_87 && V_48 != V_87 -> V_89 ) ) {
if ( V_86 )
V_86 -> V_88 = V_46 ;
if ( V_87 )
V_87 -> V_89 = V_48 ;
F_11 ( & V_4 -> V_24 , V_22 ) ;
F_1 ( V_2 ) ;
return;
}
F_11 ( & V_4 -> V_24 , V_22 ) ;
F_36 ( & V_4 -> V_5 . V_85 ) ;
}
static void
F_37 ( struct V_1 * V_2 , T_2 V_90 , T_2 V_91 , T_2 V_92 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_38 ( F_23 ( V_90 ) , V_91 ) ;
F_38 ( F_24 ( V_90 ) , V_92 ) ;
}
int
F_39 ( struct V_1 * V_2 , T_3 V_93 , T_3 V_94 ,
bool V_95 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_23 = 0 ;
unsigned long V_96 ;
F_40 ( V_97 ) ;
if ( V_4 -> V_98 >= V_93 )
return 0 ;
if ( V_94 == 0 )
return - V_99 ;
V_96 = V_7 + F_41 ( V_94 ) ;
F_42 ( V_2 , V_93 , V_94 ) ;
for (; ; ) {
F_43 ( & V_4 -> V_100 , & V_97 ,
V_95 ? V_101 :
V_102 ) ;
if ( V_95 && F_44 ( V_103 ) ) {
V_23 = - V_104 ;
break;
}
if ( V_4 -> V_98 >= V_93 )
break;
if ( V_94 != ~ 0ull ) {
if ( F_45 ( V_7 , V_96 ) ) {
V_23 = - V_99 ;
break;
}
F_46 ( V_96 - V_7 ) ;
} else {
F_47 () ;
}
}
F_48 ( & V_4 -> V_100 , & V_97 ) ;
F_49 ( V_2 , V_93 ) ;
return V_23 ;
}
static void
F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_38 ( V_105 ,
V_106 ) ;
F_38 ( V_107 ,
F_51 ( 0xf , V_108 ) |
F_51 ( 0xf , V_109 ) |
F_51 ( 0xf , V_110 ) |
F_51 ( 0xf , V_111 ) ) ;
}
void
F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_39 * V_40 ;
V_112:
V_40 = F_18 ( V_4 ) ;
if ( ! V_40 )
return;
F_50 ( V_2 ) ;
if ( V_40 -> V_46 != V_40 -> V_49 ) {
F_37 ( V_2 , 0 , V_40 -> V_46 , V_40 -> V_49 ) ;
} else {
F_53 ( V_2 , V_40 ) ;
goto V_112;
}
}
void
F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_39 * V_40 = F_19 ( V_4 ) ;
if ( ! V_40 )
return;
F_37 ( V_2 , 1 , V_40 -> V_48 , V_40 -> V_50 ) ;
}
void
F_53 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_113 = F_55 ( & V_4 -> V_114 ) ;
F_56 ( & V_40 -> V_115 , & V_4 -> V_114 ) ;
if ( V_113 )
F_54 ( V_2 ) ;
}
static void
F_57 ( struct V_39 * V_40 , T_3 V_93 )
{
struct V_30 * V_13 ;
unsigned V_10 ;
for ( V_10 = 0 ; V_10 < V_40 -> V_12 ; V_10 ++ ) {
V_13 = F_13 ( & V_40 -> V_13 [ V_10 ] -> V_34 ) ;
V_13 -> V_93 = V_93 ;
F_58 ( V_13 -> V_116 , V_40 -> V_117 ) ;
}
F_20 (bo, &exec->unref_list, unref_head) {
V_13 -> V_93 = V_93 ;
}
for ( V_10 = 0 ; V_10 < V_40 -> V_118 ; V_10 ++ ) {
V_13 = F_13 ( & V_40 -> V_119 [ V_10 ] -> V_34 ) ;
V_13 -> V_120 = V_93 ;
F_59 ( V_13 -> V_116 , V_40 -> V_117 ) ;
}
}
static void
F_60 ( struct V_1 * V_2 ,
struct V_39 * V_40 ,
struct V_121 * V_122 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_40 -> V_12 ; V_10 ++ ) {
struct V_30 * V_13 = F_13 ( & V_40 -> V_13 [ V_10 ] -> V_34 ) ;
F_61 ( & V_13 -> V_116 -> V_123 ) ;
}
F_62 ( V_122 ) ;
}
static int
F_63 ( struct V_1 * V_2 ,
struct V_39 * V_40 ,
struct V_121 * V_122 )
{
int V_124 = - 1 ;
int V_10 , V_23 ;
struct V_30 * V_13 ;
F_64 ( V_122 , & V_125 ) ;
V_126:
if ( V_124 != - 1 ) {
V_13 = F_13 ( & V_40 -> V_13 [ V_124 ] -> V_34 ) ;
V_23 = F_65 ( & V_13 -> V_116 -> V_123 ,
V_122 ) ;
if ( V_23 ) {
F_66 ( V_122 ) ;
return V_23 ;
}
}
for ( V_10 = 0 ; V_10 < V_40 -> V_12 ; V_10 ++ ) {
if ( V_10 == V_124 )
continue;
V_13 = F_13 ( & V_40 -> V_13 [ V_10 ] -> V_34 ) ;
V_23 = F_67 ( & V_13 -> V_116 -> V_123 , V_122 ) ;
if ( V_23 ) {
int V_41 ;
for ( V_41 = 0 ; V_41 < V_10 ; V_41 ++ ) {
V_13 = F_13 ( & V_40 -> V_13 [ V_41 ] -> V_34 ) ;
F_61 ( & V_13 -> V_116 -> V_123 ) ;
}
if ( V_124 != - 1 && V_124 >= V_10 ) {
V_13 = F_13 ( & V_40 -> V_13 [ V_124 ] -> V_34 ) ;
F_61 ( & V_13 -> V_116 -> V_123 ) ;
}
if ( V_23 == - V_127 ) {
V_124 = V_10 ;
goto V_126;
}
F_66 ( V_122 ) ;
return V_23 ;
}
}
F_66 ( V_122 ) ;
for ( V_10 = 0 ; V_10 < V_40 -> V_12 ; V_10 ++ ) {
V_13 = F_13 ( & V_40 -> V_13 [ V_10 ] -> V_34 ) ;
V_23 = F_68 ( V_13 -> V_116 ) ;
if ( V_23 ) {
F_60 ( V_2 , V_40 , V_122 ) ;
return V_23 ;
}
}
return 0 ;
}
static int
F_69 ( struct V_1 * V_2 , struct V_39 * V_40 ,
struct V_121 * V_122 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_93 ;
unsigned long V_22 ;
struct V_128 * V_117 ;
V_117 = F_70 ( sizeof( * V_117 ) , V_27 ) ;
if ( ! V_117 )
return - V_28 ;
V_117 -> V_2 = V_2 ;
F_10 ( & V_4 -> V_24 , V_22 ) ;
V_93 = ++ V_4 -> V_129 ;
V_40 -> V_93 = V_93 ;
F_71 ( & V_117 -> V_34 , & V_130 , & V_4 -> V_24 ,
V_4 -> V_131 , V_40 -> V_93 ) ;
V_117 -> V_93 = V_40 -> V_93 ;
V_40 -> V_117 = & V_117 -> V_34 ;
F_57 ( V_40 , V_93 ) ;
F_60 ( V_2 , V_40 , V_122 ) ;
F_72 ( & V_40 -> V_115 , & V_4 -> V_132 ) ;
if ( F_18 ( V_4 ) == V_40 ) {
F_52 ( V_2 ) ;
F_1 ( V_2 ) ;
}
F_11 ( & V_4 -> V_24 , V_22 ) ;
return 0 ;
}
static int
F_73 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_39 * V_40 )
{
struct V_133 * args = V_40 -> args ;
T_2 * V_134 ;
int V_23 = 0 ;
int V_10 ;
V_40 -> V_12 = args -> V_135 ;
if ( ! V_40 -> V_12 ) {
F_74 ( L_2 ) ;
return - V_136 ;
}
V_40 -> V_13 = F_75 ( V_40 -> V_12 ,
sizeof( struct V_137 * ) ,
V_27 | V_138 ) ;
if ( ! V_40 -> V_13 ) {
F_74 ( L_3 ) ;
return - V_28 ;
}
V_134 = F_75 ( V_40 -> V_12 , sizeof( T_2 ) , V_27 ) ;
if ( ! V_134 ) {
V_23 = - V_28 ;
F_74 ( L_4 ) ;
goto V_139;
}
if ( F_76 ( V_134 ,
( void V_36 * ) ( V_37 ) args -> V_140 ,
V_40 -> V_12 * sizeof( T_2 ) ) ) {
V_23 = - V_38 ;
F_74 ( L_5 ) ;
goto V_139;
}
F_77 ( & V_16 -> V_141 ) ;
for ( V_10 = 0 ; V_10 < V_40 -> V_12 ; V_10 ++ ) {
struct V_142 * V_13 = F_78 ( & V_16 -> V_143 ,
V_134 [ V_10 ] ) ;
if ( ! V_13 ) {
F_74 ( L_6 ,
V_10 , V_134 [ V_10 ] ) ;
V_23 = - V_136 ;
F_79 ( & V_16 -> V_141 ) ;
goto V_139;
}
F_21 ( V_13 ) ;
V_40 -> V_13 [ V_10 ] = (struct V_137 * ) V_13 ;
}
F_79 ( & V_16 -> V_141 ) ;
V_139:
F_80 ( V_134 ) ;
return V_23 ;
}
static int
F_81 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
struct V_133 * args = V_40 -> args ;
void * V_144 = NULL ;
void * V_145 ;
int V_23 = 0 ;
T_2 V_146 = 0 ;
T_2 V_147 = F_82 ( V_146 + args -> V_148 ,
16 ) ;
T_2 V_149 = V_147 + args -> V_150 ;
T_2 V_151 = V_149 + args -> V_152 ;
T_2 V_153 = V_151 + ( sizeof( struct V_154 ) *
args -> V_155 ) ;
struct V_30 * V_13 ;
if ( V_147 < args -> V_148 ||
V_149 < V_147 ||
V_151 < V_149 ||
args -> V_155 >= ( V_156 /
sizeof( struct V_154 ) ) ||
V_153 < V_151 ) {
F_74 ( L_7 ) ;
V_23 = - V_136 ;
goto V_139;
}
V_144 = F_75 ( V_153 , 1 , V_27 ) ;
if ( ! V_144 ) {
F_74 ( L_8
L_9 ) ;
V_23 = - V_28 ;
goto V_139;
}
V_145 = V_144 + V_146 ;
V_40 -> V_157 = V_144 + V_147 ;
V_40 -> V_158 = V_144 + V_149 ;
V_40 -> V_159 = V_144 + V_151 ;
V_40 -> V_160 = args -> V_155 ;
if ( F_76 ( V_145 ,
( void V_36 * ) ( V_37 ) args -> V_161 ,
args -> V_148 ) ) {
V_23 = - V_38 ;
goto V_139;
}
if ( F_76 ( V_40 -> V_157 ,
( void V_36 * ) ( V_37 ) args -> V_162 ,
args -> V_150 ) ) {
V_23 = - V_38 ;
goto V_139;
}
if ( F_76 ( V_40 -> V_158 ,
( void V_36 * ) ( V_37 ) args -> V_163 ,
args -> V_152 ) ) {
V_23 = - V_38 ;
goto V_139;
}
V_13 = F_83 ( V_2 , V_151 , true ) ;
if ( F_84 ( V_13 ) ) {
F_74 ( L_10 ) ;
V_23 = F_85 ( V_13 ) ;
goto V_139;
}
V_40 -> V_164 = & V_13 -> V_34 ;
F_72 ( & F_13 ( & V_40 -> V_164 -> V_34 ) -> V_165 ,
& V_40 -> V_166 ) ;
V_40 -> V_46 = V_40 -> V_164 -> V_33 + V_146 ;
V_40 -> V_167 = V_145 ;
V_40 -> V_168 = V_40 -> V_164 -> V_169 + V_147 ;
V_40 -> V_170 = V_40 -> V_164 -> V_33 + V_147 ;
V_40 -> V_150 = args -> V_150 ;
V_40 -> V_171 = V_40 -> V_164 -> V_169 + V_149 ;
V_40 -> V_172 = V_40 -> V_164 -> V_33 + V_149 ;
V_40 -> V_152 = args -> V_152 ;
V_23 = F_86 ( V_2 ,
V_40 -> V_164 -> V_169 + V_146 ,
V_145 ,
V_40 ) ;
if ( V_23 )
goto V_139;
V_23 = F_87 ( V_2 , V_40 ) ;
if ( V_23 )
goto V_139;
V_23 = F_39 ( V_2 , V_40 -> V_173 , ~ 0ull , true ) ;
V_139:
F_80 ( V_144 ) ;
return V_23 ;
}
static void
F_88 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_22 ;
unsigned V_10 ;
if ( V_40 -> V_117 )
F_89 ( V_40 -> V_117 ) ;
if ( V_40 -> V_13 ) {
for ( V_10 = 0 ; V_10 < V_40 -> V_12 ; V_10 ++ )
F_7 ( & V_40 -> V_13 [ V_10 ] -> V_34 ) ;
F_80 ( V_40 -> V_13 ) ;
}
while ( ! F_55 ( & V_40 -> V_166 ) ) {
struct V_30 * V_13 = F_90 ( & V_40 -> V_166 ,
struct V_30 , V_165 ) ;
F_91 ( & V_13 -> V_165 ) ;
F_7 ( & V_13 -> V_34 . V_34 ) ;
}
F_10 ( & V_4 -> V_24 , V_22 ) ;
V_4 -> V_174 &= ~ V_40 -> V_175 ;
F_11 ( & V_4 -> V_24 , V_22 ) ;
F_28 ( & V_4 -> V_79 ) ;
if ( -- V_4 -> V_80 == 0 ) {
F_92 ( & V_4 -> V_81 -> V_82 -> V_2 ) ;
F_93 ( & V_4 -> V_81 -> V_82 -> V_2 ) ;
}
F_31 ( & V_4 -> V_79 ) ;
F_8 ( V_40 ) ;
}
void
F_94 ( struct V_3 * V_4 )
{
unsigned long V_22 ;
struct V_176 * V_177 , * V_178 ;
F_10 ( & V_4 -> V_24 , V_22 ) ;
while ( ! F_55 ( & V_4 -> V_179 ) ) {
struct V_39 * V_40 =
F_90 ( & V_4 -> V_179 ,
struct V_39 , V_115 ) ;
F_91 ( & V_40 -> V_115 ) ;
F_11 ( & V_4 -> V_24 , V_22 ) ;
F_88 ( V_4 -> V_2 , V_40 ) ;
F_10 ( & V_4 -> V_24 , V_22 ) ;
}
F_95 (cb, cb_temp, &vc4->seqno_cb_list, work.entry) {
if ( V_177 -> V_93 <= V_4 -> V_98 ) {
F_96 ( & V_177 -> V_84 . V_180 ) ;
F_36 ( & V_177 -> V_84 ) ;
}
}
F_11 ( & V_4 -> V_24 , V_22 ) ;
}
static void F_97 ( struct V_83 * V_84 )
{
struct V_176 * V_177 = F_34 ( V_84 , struct V_176 , V_84 ) ;
V_177 -> V_181 ( V_177 ) ;
}
int F_98 ( struct V_1 * V_2 ,
struct V_176 * V_177 , T_3 V_93 ,
void (* V_181)( struct V_176 * V_177 ) )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_23 = 0 ;
unsigned long V_22 ;
V_177 -> V_181 = V_181 ;
F_99 ( & V_177 -> V_84 , F_97 ) ;
F_10 ( & V_4 -> V_24 , V_22 ) ;
if ( V_93 > V_4 -> V_98 ) {
V_177 -> V_93 = V_93 ;
F_72 ( & V_177 -> V_84 . V_180 , & V_4 -> V_182 ) ;
} else {
F_36 ( & V_177 -> V_84 ) ;
}
F_11 ( & V_4 -> V_24 , V_22 ) ;
return V_23 ;
}
static void
F_100 ( struct V_83 * V_84 )
{
struct V_3 * V_4 =
F_34 ( V_84 , struct V_3 , V_183 ) ;
F_94 ( V_4 ) ;
}
static int
F_101 ( struct V_1 * V_2 ,
T_3 V_93 ,
T_3 * V_94 )
{
unsigned long V_91 = V_7 ;
int V_23 = F_39 ( V_2 , V_93 , * V_94 , true ) ;
if ( ( V_23 == - V_184 || V_23 == - V_104 ) && * V_94 != ~ 0ull ) {
T_3 V_185 = F_102 ( V_7 - V_91 ) ;
if ( * V_94 >= V_185 )
* V_94 -= V_185 ;
}
return V_23 ;
}
int
F_103 ( struct V_1 * V_2 , void * V_14 ,
struct V_15 * V_16 )
{
struct V_186 * args = V_14 ;
return F_101 ( V_2 , args -> V_93 ,
& args -> V_94 ) ;
}
int
F_104 ( struct V_1 * V_2 , void * V_14 ,
struct V_15 * V_16 )
{
int V_23 ;
struct V_187 * args = V_14 ;
struct V_142 * V_188 ;
struct V_30 * V_13 ;
if ( args -> V_189 != 0 )
return - V_136 ;
V_188 = F_105 ( V_16 , args -> V_31 ) ;
if ( ! V_188 ) {
F_74 ( L_11 , args -> V_31 ) ;
return - V_136 ;
}
V_13 = F_13 ( V_188 ) ;
V_23 = F_101 ( V_2 , V_13 -> V_93 ,
& args -> V_94 ) ;
F_7 ( V_188 ) ;
return V_23 ;
}
int
F_106 ( struct V_1 * V_2 , void * V_14 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_133 * args = V_14 ;
struct V_39 * V_40 ;
struct V_121 V_122 ;
int V_23 = 0 ;
if ( ( args -> V_190 & ~ V_191 ) != 0 ) {
F_74 ( L_12 , args -> V_190 ) ;
return - V_136 ;
}
V_40 = F_12 ( 1 , sizeof( * V_40 ) , V_27 ) ;
if ( ! V_40 ) {
F_74 ( L_13 ) ;
return - V_28 ;
}
F_28 ( & V_4 -> V_79 ) ;
if ( V_4 -> V_80 ++ == 0 ) {
V_23 = F_30 ( & V_4 -> V_81 -> V_82 -> V_2 ) ;
if ( V_23 < 0 ) {
F_31 ( & V_4 -> V_79 ) ;
V_4 -> V_80 -- ;
F_8 ( V_40 ) ;
return V_23 ;
}
}
F_31 ( & V_4 -> V_79 ) ;
V_40 -> args = args ;
F_107 ( & V_40 -> V_166 ) ;
V_23 = F_73 ( V_2 , V_16 , V_40 ) ;
if ( V_23 )
goto V_139;
if ( V_40 -> args -> V_148 != 0 ) {
V_23 = F_81 ( V_2 , V_40 ) ;
if ( V_23 )
goto V_139;
} else {
V_40 -> V_46 = 0 ;
V_40 -> V_49 = 0 ;
}
V_23 = F_108 ( V_2 , V_40 ) ;
if ( V_23 )
goto V_139;
V_23 = F_63 ( V_2 , V_40 , & V_122 ) ;
if ( V_23 )
goto V_139;
V_40 -> args = NULL ;
V_23 = F_69 ( V_2 , V_40 , & V_122 ) ;
if ( V_23 )
goto V_139;
args -> V_93 = V_4 -> V_129 ;
return 0 ;
V_139:
F_88 ( V_4 -> V_2 , V_40 ) ;
return V_23 ;
}
void
F_109 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_131 = F_110 ( 1 ) ;
F_107 ( & V_4 -> V_132 ) ;
F_107 ( & V_4 -> V_114 ) ;
F_107 ( & V_4 -> V_179 ) ;
F_107 ( & V_4 -> V_182 ) ;
F_111 ( & V_4 -> V_24 ) ;
F_99 ( & V_4 -> V_5 . V_85 , F_33 ) ;
F_112 ( & V_4 -> V_5 . V_6 ,
F_35 ,
( unsigned long ) V_2 ) ;
F_99 ( & V_4 -> V_183 , F_100 ) ;
F_113 ( & V_4 -> V_79 ) ;
}
void
F_114 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_115 ( V_4 -> V_129 != V_4 -> V_98 ) ;
if ( V_4 -> V_192 ) {
F_116 ( & V_4 -> V_192 -> V_34 . V_34 ) ;
V_4 -> V_192 = NULL ;
}
if ( V_4 -> V_25 )
F_6 ( V_2 , V_4 -> V_25 ) ;
F_117 ( V_2 ) ;
}
