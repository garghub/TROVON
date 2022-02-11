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
if ( F_15 ( F_16 ( V_18 -> V_13 ) ,
V_20 ,
V_9 -> V_12 * sizeof( * V_20 ) ) )
V_23 = - V_36 ;
V_32:
if ( V_23 ) {
for ( V_10 = 0 ; V_10 < V_9 -> V_12 ; V_10 ++ )
F_17 ( V_16 , V_20 [ V_10 ] . V_31 ) ;
}
V_29:
F_6 ( V_2 , V_21 ) ;
F_8 ( V_20 ) ;
return V_23 ;
}
static void
F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_17 * V_9 ;
struct V_8 * V_21 ;
struct V_37 * V_38 [ 2 ] ;
struct V_30 * V_13 ;
unsigned long V_22 ;
unsigned int V_10 , V_39 , V_40 , V_41 ;
V_21 = F_12 ( 1 , sizeof( * V_21 ) , V_27 ) ;
if ( ! V_21 )
return;
V_9 = & V_21 -> V_11 ;
F_10 ( & V_4 -> V_24 , V_22 ) ;
V_38 [ 0 ] = F_19 ( V_4 ) ;
V_38 [ 1 ] = F_20 ( V_4 ) ;
if ( ! V_38 [ 0 ] && ! V_38 [ 1 ] ) {
F_11 ( & V_4 -> V_24 , V_22 ) ;
return;
}
V_9 -> V_12 = 0 ;
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ ) {
if ( ! V_38 [ V_10 ] )
continue;
V_40 = 0 ;
F_21 (bo, &exec[i]->unref_list, unref_head)
V_40 ++ ;
V_9 -> V_12 += V_38 [ V_10 ] -> V_12 + V_40 ;
}
V_21 -> V_13 = F_12 ( V_9 -> V_12 ,
sizeof( * V_21 -> V_13 ) , V_42 ) ;
if ( ! V_21 -> V_13 ) {
F_11 ( & V_4 -> V_24 , V_22 ) ;
return;
}
V_41 = 0 ;
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ ) {
if ( ! V_38 [ V_10 ] )
continue;
for ( V_39 = 0 ; V_39 < V_38 [ V_10 ] -> V_12 ; V_39 ++ ) {
F_22 ( & V_38 [ V_10 ] -> V_13 [ V_39 ] -> V_34 ) ;
V_21 -> V_13 [ V_39 + V_41 ] = & V_38 [ V_10 ] -> V_13 [ V_39 ] -> V_34 ;
}
F_21 (bo, &exec[i]->unref_list, unref_head) {
F_22 ( & V_13 -> V_34 . V_34 ) ;
V_21 -> V_13 [ V_39 + V_41 ] = & V_13 -> V_34 . V_34 ;
V_39 ++ ;
}
V_41 = V_39 + 1 ;
}
if ( V_38 [ 0 ] )
V_9 -> V_43 = V_38 [ 0 ] -> V_44 ;
if ( V_38 [ 1 ] )
V_9 -> V_45 = V_38 [ 1 ] -> V_46 ;
F_11 ( & V_4 -> V_24 , V_22 ) ;
V_9 -> V_44 = F_23 ( F_24 ( 0 ) ) ;
V_9 -> V_47 = F_23 ( F_25 ( 0 ) ) ;
V_9 -> V_46 = F_23 ( F_24 ( 1 ) ) ;
V_9 -> V_48 = F_23 ( F_25 ( 1 ) ) ;
V_9 -> V_49 = F_23 ( F_26 ( 0 ) ) ;
V_9 -> V_50 = F_23 ( F_26 ( 1 ) ) ;
V_9 -> V_51 = F_23 ( V_52 ) ;
V_9 -> V_53 = F_23 ( V_54 ) ;
V_9 -> V_55 = F_23 ( V_56 ) ;
V_9 -> V_57 = F_23 ( V_58 ) ;
V_9 -> V_59 = F_23 ( V_60 ) ;
V_9 -> V_61 = F_23 ( V_62 ) ;
V_9 -> V_63 = F_23 ( V_64 ) ;
V_9 -> V_65 = F_23 ( V_66 ) ;
V_9 -> V_67 = F_23 ( V_68 ) ;
V_9 -> V_69 = F_23 ( V_70 ) ;
V_9 -> V_71 = F_23 ( V_72 ) ;
V_9 -> V_73 = F_23 ( V_74 ) ;
V_9 -> V_75 = F_23 ( V_76 ) ;
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
F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_28 ( L_1 ) ;
F_29 ( & V_4 -> V_77 ) ;
if ( V_4 -> V_78 ) {
F_30 ( & V_4 -> V_79 -> V_80 -> V_2 ) ;
F_31 ( & V_4 -> V_79 -> V_80 -> V_2 ) ;
}
F_32 ( & V_4 -> V_77 ) ;
F_33 ( V_2 ) ;
F_1 ( V_2 ) ;
}
static void
F_34 ( struct V_81 * V_82 )
{
struct V_3 * V_4 =
F_35 ( V_82 , struct V_3 , V_5 . V_83 ) ;
F_18 ( V_4 -> V_2 ) ;
F_27 ( V_4 -> V_2 ) ;
}
static void
F_36 ( unsigned long V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_44 , V_46 ;
unsigned long V_22 ;
struct V_37 * V_84 , * V_85 ;
F_10 ( & V_4 -> V_24 , V_22 ) ;
V_84 = F_19 ( V_4 ) ;
V_85 = F_20 ( V_4 ) ;
if ( ! V_84 && ! V_85 ) {
F_11 ( & V_4 -> V_24 , V_22 ) ;
return;
}
V_44 = F_23 ( F_24 ( 0 ) ) ;
V_46 = F_23 ( F_24 ( 1 ) ) ;
if ( ( V_84 && V_44 != V_84 -> V_86 ) ||
( V_85 && V_46 != V_85 -> V_87 ) ) {
if ( V_84 )
V_84 -> V_86 = V_44 ;
if ( V_85 )
V_85 -> V_87 = V_46 ;
F_11 ( & V_4 -> V_24 , V_22 ) ;
F_1 ( V_2 ) ;
return;
}
F_11 ( & V_4 -> V_24 , V_22 ) ;
F_37 ( & V_4 -> V_5 . V_83 ) ;
}
static void
F_38 ( struct V_1 * V_2 , T_2 V_88 , T_2 V_89 , T_2 V_90 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_39 ( F_24 ( V_88 ) , V_89 ) ;
F_39 ( F_25 ( V_88 ) , V_90 ) ;
}
int
F_40 ( struct V_1 * V_2 , T_3 V_91 , T_3 V_92 ,
bool V_93 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_23 = 0 ;
unsigned long V_94 ;
F_41 ( V_95 ) ;
if ( V_4 -> V_96 >= V_91 )
return 0 ;
if ( V_92 == 0 )
return - V_97 ;
V_94 = V_7 + F_42 ( V_92 ) ;
F_43 ( V_2 , V_91 , V_92 ) ;
for (; ; ) {
F_44 ( & V_4 -> V_98 , & V_95 ,
V_93 ? V_99 :
V_100 ) ;
if ( V_93 && F_45 ( V_101 ) ) {
V_23 = - V_102 ;
break;
}
if ( V_4 -> V_96 >= V_91 )
break;
if ( V_92 != ~ 0ull ) {
if ( F_46 ( V_7 , V_94 ) ) {
V_23 = - V_97 ;
break;
}
F_47 ( V_94 - V_7 ) ;
} else {
F_48 () ;
}
}
F_49 ( & V_4 -> V_98 , & V_95 ) ;
F_50 ( V_2 , V_91 ) ;
return V_23 ;
}
static void
F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_39 ( V_103 ,
V_104 ) ;
F_39 ( V_105 ,
F_52 ( 0xf , V_106 ) |
F_52 ( 0xf , V_107 ) |
F_52 ( 0xf , V_108 ) |
F_52 ( 0xf , V_109 ) ) ;
}
void
F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_37 * V_38 ;
V_110:
V_38 = F_19 ( V_4 ) ;
if ( ! V_38 )
return;
F_51 ( V_2 ) ;
if ( V_38 -> V_44 != V_38 -> V_47 ) {
F_38 ( V_2 , 0 , V_38 -> V_44 , V_38 -> V_47 ) ;
} else {
F_54 ( V_2 , V_38 ) ;
goto V_110;
}
}
void
F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_37 * V_38 = F_20 ( V_4 ) ;
if ( ! V_38 )
return;
F_38 ( V_2 , 1 , V_38 -> V_46 , V_38 -> V_48 ) ;
}
void
F_54 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_111 = F_56 ( & V_4 -> V_112 ) ;
F_57 ( & V_38 -> V_113 , & V_4 -> V_112 ) ;
if ( V_111 )
F_55 ( V_2 ) ;
}
static void
F_58 ( struct V_37 * V_38 , T_3 V_91 )
{
struct V_30 * V_13 ;
unsigned V_10 ;
for ( V_10 = 0 ; V_10 < V_38 -> V_12 ; V_10 ++ ) {
V_13 = F_13 ( & V_38 -> V_13 [ V_10 ] -> V_34 ) ;
V_13 -> V_91 = V_91 ;
F_59 ( V_13 -> V_114 , V_38 -> V_115 ) ;
}
F_21 (bo, &exec->unref_list, unref_head) {
V_13 -> V_91 = V_91 ;
}
for ( V_10 = 0 ; V_10 < V_38 -> V_116 ; V_10 ++ ) {
V_13 = F_13 ( & V_38 -> V_117 [ V_10 ] -> V_34 ) ;
V_13 -> V_118 = V_91 ;
F_60 ( V_13 -> V_114 , V_38 -> V_115 ) ;
}
}
static void
F_61 ( struct V_1 * V_2 ,
struct V_37 * V_38 ,
struct V_119 * V_120 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_38 -> V_12 ; V_10 ++ ) {
struct V_30 * V_13 = F_13 ( & V_38 -> V_13 [ V_10 ] -> V_34 ) ;
F_62 ( & V_13 -> V_114 -> V_121 ) ;
}
F_63 ( V_120 ) ;
}
static int
F_64 ( struct V_1 * V_2 ,
struct V_37 * V_38 ,
struct V_119 * V_120 )
{
int V_122 = - 1 ;
int V_10 , V_23 ;
struct V_30 * V_13 ;
F_65 ( V_120 , & V_123 ) ;
V_124:
if ( V_122 != - 1 ) {
V_13 = F_13 ( & V_38 -> V_13 [ V_122 ] -> V_34 ) ;
V_23 = F_66 ( & V_13 -> V_114 -> V_121 ,
V_120 ) ;
if ( V_23 ) {
F_67 ( V_120 ) ;
return V_23 ;
}
}
for ( V_10 = 0 ; V_10 < V_38 -> V_12 ; V_10 ++ ) {
if ( V_10 == V_122 )
continue;
V_13 = F_13 ( & V_38 -> V_13 [ V_10 ] -> V_34 ) ;
V_23 = F_68 ( & V_13 -> V_114 -> V_121 , V_120 ) ;
if ( V_23 ) {
int V_39 ;
for ( V_39 = 0 ; V_39 < V_10 ; V_39 ++ ) {
V_13 = F_13 ( & V_38 -> V_13 [ V_39 ] -> V_34 ) ;
F_62 ( & V_13 -> V_114 -> V_121 ) ;
}
if ( V_122 != - 1 && V_122 >= V_10 ) {
V_13 = F_13 ( & V_38 -> V_13 [ V_122 ] -> V_34 ) ;
F_62 ( & V_13 -> V_114 -> V_121 ) ;
}
if ( V_23 == - V_125 ) {
V_122 = V_10 ;
goto V_124;
}
F_67 ( V_120 ) ;
return V_23 ;
}
}
F_67 ( V_120 ) ;
for ( V_10 = 0 ; V_10 < V_38 -> V_12 ; V_10 ++ ) {
V_13 = F_13 ( & V_38 -> V_13 [ V_10 ] -> V_34 ) ;
V_23 = F_69 ( V_13 -> V_114 ) ;
if ( V_23 ) {
F_61 ( V_2 , V_38 , V_120 ) ;
return V_23 ;
}
}
return 0 ;
}
static int
F_70 ( struct V_1 * V_2 , struct V_37 * V_38 ,
struct V_119 * V_120 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_91 ;
unsigned long V_22 ;
struct V_126 * V_115 ;
V_115 = F_71 ( sizeof( * V_115 ) , V_27 ) ;
if ( ! V_115 )
return - V_28 ;
V_115 -> V_2 = V_2 ;
F_10 ( & V_4 -> V_24 , V_22 ) ;
V_91 = ++ V_4 -> V_127 ;
V_38 -> V_91 = V_91 ;
F_72 ( & V_115 -> V_34 , & V_128 , & V_4 -> V_24 ,
V_4 -> V_129 , V_38 -> V_91 ) ;
V_115 -> V_91 = V_38 -> V_91 ;
V_38 -> V_115 = & V_115 -> V_34 ;
F_58 ( V_38 , V_91 ) ;
F_61 ( V_2 , V_38 , V_120 ) ;
F_73 ( & V_38 -> V_113 , & V_4 -> V_130 ) ;
if ( F_19 ( V_4 ) == V_38 ) {
F_53 ( V_2 ) ;
F_1 ( V_2 ) ;
}
F_11 ( & V_4 -> V_24 , V_22 ) ;
return 0 ;
}
static int
F_74 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_37 * V_38 )
{
struct V_131 * args = V_38 -> args ;
T_2 * V_132 ;
int V_23 = 0 ;
int V_10 ;
V_38 -> V_12 = args -> V_133 ;
if ( ! V_38 -> V_12 ) {
F_75 ( L_2 ) ;
return - V_134 ;
}
V_38 -> V_13 = F_76 ( V_38 -> V_12 ,
sizeof( struct V_135 * ) ,
V_27 | V_136 ) ;
if ( ! V_38 -> V_13 ) {
F_77 ( L_3 ) ;
return - V_28 ;
}
V_132 = F_76 ( V_38 -> V_12 , sizeof( T_2 ) , V_27 ) ;
if ( ! V_132 ) {
V_23 = - V_28 ;
F_77 ( L_4 ) ;
goto V_137;
}
if ( F_78 ( V_132 , F_16 ( args -> V_138 ) ,
V_38 -> V_12 * sizeof( T_2 ) ) ) {
V_23 = - V_36 ;
F_77 ( L_5 ) ;
goto V_137;
}
F_79 ( & V_16 -> V_139 ) ;
for ( V_10 = 0 ; V_10 < V_38 -> V_12 ; V_10 ++ ) {
struct V_140 * V_13 = F_80 ( & V_16 -> V_141 ,
V_132 [ V_10 ] ) ;
if ( ! V_13 ) {
F_75 ( L_6 ,
V_10 , V_132 [ V_10 ] ) ;
V_23 = - V_134 ;
F_81 ( & V_16 -> V_139 ) ;
goto V_137;
}
F_22 ( V_13 ) ;
V_38 -> V_13 [ V_10 ] = (struct V_135 * ) V_13 ;
}
F_81 ( & V_16 -> V_139 ) ;
V_137:
F_82 ( V_132 ) ;
return V_23 ;
}
static int
F_83 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
struct V_131 * args = V_38 -> args ;
void * V_142 = NULL ;
void * V_143 ;
int V_23 = 0 ;
T_2 V_144 = 0 ;
T_2 V_145 = F_84 ( V_144 + args -> V_146 ,
16 ) ;
T_2 V_147 = V_145 + args -> V_148 ;
T_2 V_149 = V_147 + args -> V_150 ;
T_2 V_151 = V_149 + ( sizeof( struct V_152 ) *
args -> V_153 ) ;
struct V_30 * V_13 ;
if ( V_145 < args -> V_146 ||
V_147 < V_145 ||
V_149 < V_147 ||
args -> V_153 >= ( V_154 /
sizeof( struct V_152 ) ) ||
V_151 < V_149 ) {
F_75 ( L_7 ) ;
V_23 = - V_134 ;
goto V_137;
}
V_142 = F_76 ( V_151 , 1 , V_27 ) ;
if ( ! V_142 ) {
F_77 ( L_8
L_9 ) ;
V_23 = - V_28 ;
goto V_137;
}
V_143 = V_142 + V_144 ;
V_38 -> V_155 = V_142 + V_145 ;
V_38 -> V_156 = V_142 + V_147 ;
V_38 -> V_157 = V_142 + V_149 ;
V_38 -> V_158 = args -> V_153 ;
if ( F_78 ( V_143 ,
F_16 ( args -> V_159 ) ,
args -> V_146 ) ) {
V_23 = - V_36 ;
goto V_137;
}
if ( F_78 ( V_38 -> V_155 ,
F_16 ( args -> V_160 ) ,
args -> V_148 ) ) {
V_23 = - V_36 ;
goto V_137;
}
if ( F_78 ( V_38 -> V_156 ,
F_16 ( args -> V_161 ) ,
args -> V_150 ) ) {
V_23 = - V_36 ;
goto V_137;
}
V_13 = F_85 ( V_2 , V_149 , true , V_162 ) ;
if ( F_86 ( V_13 ) ) {
F_77 ( L_10 ) ;
V_23 = F_87 ( V_13 ) ;
goto V_137;
}
V_38 -> V_163 = & V_13 -> V_34 ;
F_73 ( & F_13 ( & V_38 -> V_163 -> V_34 ) -> V_164 ,
& V_38 -> V_165 ) ;
V_38 -> V_44 = V_38 -> V_163 -> V_33 + V_144 ;
V_38 -> V_166 = V_143 ;
V_38 -> V_167 = V_38 -> V_163 -> V_168 + V_145 ;
V_38 -> V_169 = V_38 -> V_163 -> V_33 + V_145 ;
V_38 -> V_148 = args -> V_148 ;
V_38 -> V_170 = V_38 -> V_163 -> V_168 + V_147 ;
V_38 -> V_171 = V_38 -> V_163 -> V_33 + V_147 ;
V_38 -> V_150 = args -> V_150 ;
V_23 = F_88 ( V_2 ,
V_38 -> V_163 -> V_168 + V_144 ,
V_143 ,
V_38 ) ;
if ( V_23 )
goto V_137;
V_23 = F_89 ( V_2 , V_38 ) ;
if ( V_23 )
goto V_137;
V_23 = F_40 ( V_2 , V_38 -> V_172 , ~ 0ull , true ) ;
V_137:
F_82 ( V_142 ) ;
return V_23 ;
}
static void
F_90 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_22 ;
unsigned V_10 ;
if ( V_38 -> V_115 )
F_91 ( V_38 -> V_115 ) ;
if ( V_38 -> V_13 ) {
for ( V_10 = 0 ; V_10 < V_38 -> V_12 ; V_10 ++ )
F_7 ( & V_38 -> V_13 [ V_10 ] -> V_34 ) ;
F_82 ( V_38 -> V_13 ) ;
}
while ( ! F_56 ( & V_38 -> V_165 ) ) {
struct V_30 * V_13 = F_92 ( & V_38 -> V_165 ,
struct V_30 , V_164 ) ;
F_93 ( & V_13 -> V_164 ) ;
F_7 ( & V_13 -> V_34 . V_34 ) ;
}
F_10 ( & V_4 -> V_24 , V_22 ) ;
V_4 -> V_173 &= ~ V_38 -> V_174 ;
F_11 ( & V_4 -> V_24 , V_22 ) ;
F_29 ( & V_4 -> V_77 ) ;
if ( -- V_4 -> V_78 == 0 ) {
F_94 ( & V_4 -> V_79 -> V_80 -> V_2 ) ;
F_95 ( & V_4 -> V_79 -> V_80 -> V_2 ) ;
}
F_32 ( & V_4 -> V_77 ) ;
F_8 ( V_38 ) ;
}
void
F_96 ( struct V_3 * V_4 )
{
unsigned long V_22 ;
struct V_175 * V_176 , * V_177 ;
F_10 ( & V_4 -> V_24 , V_22 ) ;
while ( ! F_56 ( & V_4 -> V_178 ) ) {
struct V_37 * V_38 =
F_92 ( & V_4 -> V_178 ,
struct V_37 , V_113 ) ;
F_93 ( & V_38 -> V_113 ) ;
F_11 ( & V_4 -> V_24 , V_22 ) ;
F_90 ( V_4 -> V_2 , V_38 ) ;
F_10 ( & V_4 -> V_24 , V_22 ) ;
}
F_97 (cb, cb_temp, &vc4->seqno_cb_list, work.entry) {
if ( V_176 -> V_91 <= V_4 -> V_96 ) {
F_98 ( & V_176 -> V_82 . V_179 ) ;
F_37 ( & V_176 -> V_82 ) ;
}
}
F_11 ( & V_4 -> V_24 , V_22 ) ;
}
static void F_99 ( struct V_81 * V_82 )
{
struct V_175 * V_176 = F_35 ( V_82 , struct V_175 , V_82 ) ;
V_176 -> V_180 ( V_176 ) ;
}
int F_100 ( struct V_1 * V_2 ,
struct V_175 * V_176 , T_3 V_91 ,
void (* V_180)( struct V_175 * V_176 ) )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_23 = 0 ;
unsigned long V_22 ;
V_176 -> V_180 = V_180 ;
F_101 ( & V_176 -> V_82 , F_99 ) ;
F_10 ( & V_4 -> V_24 , V_22 ) ;
if ( V_91 > V_4 -> V_96 ) {
V_176 -> V_91 = V_91 ;
F_73 ( & V_176 -> V_82 . V_179 , & V_4 -> V_181 ) ;
} else {
F_37 ( & V_176 -> V_82 ) ;
}
F_11 ( & V_4 -> V_24 , V_22 ) ;
return V_23 ;
}
static void
F_102 ( struct V_81 * V_82 )
{
struct V_3 * V_4 =
F_35 ( V_82 , struct V_3 , V_182 ) ;
F_96 ( V_4 ) ;
}
static int
F_103 ( struct V_1 * V_2 ,
T_3 V_91 ,
T_3 * V_92 )
{
unsigned long V_89 = V_7 ;
int V_23 = F_40 ( V_2 , V_91 , * V_92 , true ) ;
if ( ( V_23 == - V_183 || V_23 == - V_102 ) && * V_92 != ~ 0ull ) {
T_3 V_184 = F_104 ( V_7 - V_89 ) ;
if ( * V_92 >= V_184 )
* V_92 -= V_184 ;
}
return V_23 ;
}
int
F_105 ( struct V_1 * V_2 , void * V_14 ,
struct V_15 * V_16 )
{
struct V_185 * args = V_14 ;
return F_103 ( V_2 , args -> V_91 ,
& args -> V_92 ) ;
}
int
F_106 ( struct V_1 * V_2 , void * V_14 ,
struct V_15 * V_16 )
{
int V_23 ;
struct V_186 * args = V_14 ;
struct V_140 * V_187 ;
struct V_30 * V_13 ;
if ( args -> V_188 != 0 )
return - V_134 ;
V_187 = F_107 ( V_16 , args -> V_31 ) ;
if ( ! V_187 ) {
F_75 ( L_11 , args -> V_31 ) ;
return - V_134 ;
}
V_13 = F_13 ( V_187 ) ;
V_23 = F_103 ( V_2 , V_13 -> V_91 ,
& args -> V_92 ) ;
F_7 ( V_187 ) ;
return V_23 ;
}
int
F_108 ( struct V_1 * V_2 , void * V_14 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_131 * args = V_14 ;
struct V_37 * V_38 ;
struct V_119 V_120 ;
int V_23 = 0 ;
if ( ( args -> V_189 & ~ ( V_190 |
V_191 |
V_192 |
V_193 ) ) != 0 ) {
F_75 ( L_12 , args -> V_189 ) ;
return - V_134 ;
}
V_38 = F_12 ( 1 , sizeof( * V_38 ) , V_27 ) ;
if ( ! V_38 ) {
F_77 ( L_13 ) ;
return - V_28 ;
}
F_29 ( & V_4 -> V_77 ) ;
if ( V_4 -> V_78 ++ == 0 ) {
V_23 = F_31 ( & V_4 -> V_79 -> V_80 -> V_2 ) ;
if ( V_23 < 0 ) {
F_32 ( & V_4 -> V_77 ) ;
V_4 -> V_78 -- ;
F_8 ( V_38 ) ;
return V_23 ;
}
}
F_32 ( & V_4 -> V_77 ) ;
V_38 -> args = args ;
F_109 ( & V_38 -> V_165 ) ;
V_23 = F_74 ( V_2 , V_16 , V_38 ) ;
if ( V_23 )
goto V_137;
if ( V_38 -> args -> V_146 != 0 ) {
V_23 = F_83 ( V_2 , V_38 ) ;
if ( V_23 )
goto V_137;
} else {
V_38 -> V_44 = 0 ;
V_38 -> V_47 = 0 ;
}
V_23 = F_110 ( V_2 , V_38 ) ;
if ( V_23 )
goto V_137;
V_23 = F_64 ( V_2 , V_38 , & V_120 ) ;
if ( V_23 )
goto V_137;
V_38 -> args = NULL ;
V_23 = F_70 ( V_2 , V_38 , & V_120 ) ;
if ( V_23 )
goto V_137;
args -> V_91 = V_4 -> V_127 ;
return 0 ;
V_137:
F_90 ( V_4 -> V_2 , V_38 ) ;
return V_23 ;
}
void
F_111 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_129 = F_112 ( 1 ) ;
F_109 ( & V_4 -> V_130 ) ;
F_109 ( & V_4 -> V_112 ) ;
F_109 ( & V_4 -> V_178 ) ;
F_109 ( & V_4 -> V_181 ) ;
F_113 ( & V_4 -> V_24 ) ;
F_101 ( & V_4 -> V_5 . V_83 , F_34 ) ;
F_114 ( & V_4 -> V_5 . V_6 ,
F_36 ,
( unsigned long ) V_2 ) ;
F_101 ( & V_4 -> V_182 , F_102 ) ;
F_115 ( & V_4 -> V_77 ) ;
}
void
F_116 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_117 ( V_4 -> V_127 != V_4 -> V_96 ) ;
if ( V_4 -> V_194 ) {
F_7 ( & V_4 -> V_194 -> V_34 . V_34 ) ;
V_4 -> V_194 = NULL ;
}
if ( V_4 -> V_25 )
F_6 ( V_2 , V_4 -> V_25 ) ;
}
