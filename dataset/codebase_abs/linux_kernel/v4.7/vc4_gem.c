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
F_7 ( & V_2 -> V_11 ) ;
for ( V_10 = 0 ; V_10 < V_9 -> V_12 . V_13 ; V_10 ++ )
F_8 ( V_9 -> V_14 [ V_10 ] ) ;
F_9 ( & V_2 -> V_11 ) ;
F_10 ( V_9 ) ;
}
int
F_11 ( struct V_1 * V_2 , void * V_15 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_15 ;
struct V_20 * V_21 ;
struct V_8 * V_22 ;
struct V_18 * V_9 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_23 ;
T_1 V_10 ;
int V_24 = 0 ;
F_12 ( & V_4 -> V_25 , V_23 ) ;
V_22 = V_4 -> V_26 ;
if ( ! V_22 ) {
F_13 ( & V_4 -> V_25 , V_23 ) ;
return - V_27 ;
}
V_9 = & V_22 -> V_12 ;
if ( V_19 -> V_13 < V_9 -> V_13 ) {
V_19 -> V_13 = V_9 -> V_13 ;
F_13 ( & V_4 -> V_25 , V_23 ) ;
return 0 ;
}
V_4 -> V_26 = NULL ;
F_13 ( & V_4 -> V_25 , V_23 ) ;
V_9 -> V_14 = V_19 -> V_14 ;
memcpy ( V_19 , V_9 , sizeof( * V_9 ) ) ;
V_21 = F_14 ( V_9 -> V_13 , sizeof( * V_21 ) , V_28 ) ;
if ( ! V_21 ) {
V_24 = - V_29 ;
goto V_30;
}
for ( V_10 = 0 ; V_10 < V_9 -> V_13 ; V_10 ++ ) {
struct V_31 * V_31 = F_15 ( V_22 -> V_14 [ V_10 ] ) ;
T_1 V_32 ;
V_24 = F_16 ( V_17 , V_22 -> V_14 [ V_10 ] ,
& V_32 ) ;
if ( V_24 ) {
V_9 -> V_13 = V_10 - 1 ;
goto V_33;
}
V_21 [ V_10 ] . V_32 = V_32 ;
V_21 [ V_10 ] . V_34 = V_31 -> V_35 . V_34 ;
V_21 [ V_10 ] . V_36 = V_31 -> V_35 . V_35 . V_36 ;
}
if ( F_17 ( ( void V_37 * ) ( V_38 ) V_19 -> V_14 ,
V_21 ,
V_9 -> V_13 * sizeof( * V_21 ) ) )
V_24 = - V_39 ;
F_10 ( V_21 ) ;
V_30:
F_6 ( V_2 , V_22 ) ;
V_33:
return V_24 ;
}
static void
F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_18 * V_9 ;
struct V_8 * V_22 ;
struct V_40 * V_41 [ 2 ] ;
struct V_31 * V_14 ;
unsigned long V_23 ;
unsigned int V_10 , V_42 , V_43 , V_44 ;
V_22 = F_14 ( 1 , sizeof( * V_22 ) , V_28 ) ;
if ( ! V_22 )
return;
V_9 = & V_22 -> V_12 ;
F_12 ( & V_4 -> V_25 , V_23 ) ;
V_41 [ 0 ] = F_19 ( V_4 ) ;
V_41 [ 1 ] = F_20 ( V_4 ) ;
if ( ! V_41 [ 0 ] && ! V_41 [ 1 ] ) {
F_13 ( & V_4 -> V_25 , V_23 ) ;
return;
}
V_9 -> V_13 = 0 ;
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ ) {
if ( ! V_41 [ V_10 ] )
continue;
V_43 = 0 ;
F_21 (bo, &exec[i]->unref_list, unref_head)
V_43 ++ ;
V_9 -> V_13 += V_41 [ V_10 ] -> V_13 + V_43 ;
}
V_22 -> V_14 = F_14 ( V_9 -> V_13 ,
sizeof( * V_22 -> V_14 ) , V_45 ) ;
if ( ! V_22 -> V_14 ) {
F_13 ( & V_4 -> V_25 , V_23 ) ;
return;
}
V_44 = 0 ;
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ ) {
if ( ! V_41 [ V_10 ] )
continue;
for ( V_42 = 0 ; V_42 < V_41 [ V_10 ] -> V_13 ; V_42 ++ ) {
F_22 ( & V_41 [ V_10 ] -> V_14 [ V_42 ] -> V_35 ) ;
V_22 -> V_14 [ V_42 + V_44 ] = & V_41 [ V_10 ] -> V_14 [ V_42 ] -> V_35 ;
}
F_21 (bo, &exec[i]->unref_list, unref_head) {
F_22 ( & V_14 -> V_35 . V_35 ) ;
V_22 -> V_14 [ V_42 + V_44 ] = & V_14 -> V_35 . V_35 ;
V_42 ++ ;
}
V_44 = V_42 + 1 ;
}
if ( V_41 [ 0 ] )
V_9 -> V_46 = V_41 [ 0 ] -> V_47 ;
if ( V_41 [ 1 ] )
V_9 -> V_48 = V_41 [ 1 ] -> V_49 ;
F_13 ( & V_4 -> V_25 , V_23 ) ;
V_9 -> V_47 = F_23 ( F_24 ( 0 ) ) ;
V_9 -> V_50 = F_23 ( F_25 ( 0 ) ) ;
V_9 -> V_49 = F_23 ( F_24 ( 1 ) ) ;
V_9 -> V_51 = F_23 ( F_25 ( 1 ) ) ;
V_9 -> V_52 = F_23 ( F_26 ( 0 ) ) ;
V_9 -> V_53 = F_23 ( F_26 ( 1 ) ) ;
V_9 -> V_54 = F_23 ( V_55 ) ;
V_9 -> V_56 = F_23 ( V_57 ) ;
V_9 -> V_58 = F_23 ( V_59 ) ;
V_9 -> V_60 = F_23 ( V_61 ) ;
V_9 -> V_62 = F_23 ( V_63 ) ;
V_9 -> V_64 = F_23 ( V_65 ) ;
V_9 -> V_66 = F_23 ( V_67 ) ;
V_9 -> V_68 = F_23 ( V_69 ) ;
V_9 -> V_70 = F_23 ( V_71 ) ;
V_9 -> V_72 = F_23 ( V_73 ) ;
V_9 -> V_74 = F_23 ( V_75 ) ;
V_9 -> V_76 = F_23 ( V_77 ) ;
V_9 -> V_78 = F_23 ( V_79 ) ;
F_12 ( & V_4 -> V_25 , V_23 ) ;
if ( V_4 -> V_26 ) {
F_13 ( & V_4 -> V_25 , V_23 ) ;
F_6 ( V_2 , V_22 ) ;
} else {
V_4 -> V_26 = V_22 ;
F_13 ( & V_4 -> V_25 , V_23 ) ;
}
}
static void
F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_28 ( L_1 ) ;
F_7 ( & V_4 -> V_80 ) ;
if ( V_4 -> V_81 ) {
F_29 ( & V_4 -> V_82 -> V_83 -> V_2 ) ;
F_30 ( & V_4 -> V_82 -> V_83 -> V_2 ) ;
}
F_9 ( & V_4 -> V_80 ) ;
F_31 ( V_2 ) ;
F_1 ( V_2 ) ;
}
static void
F_32 ( struct V_84 * V_85 )
{
struct V_3 * V_4 =
F_33 ( V_85 , struct V_3 , V_5 . V_86 ) ;
F_18 ( V_4 -> V_2 ) ;
F_27 ( V_4 -> V_2 ) ;
}
static void
F_34 ( unsigned long V_15 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_47 , V_49 ;
unsigned long V_23 ;
struct V_40 * V_87 , * V_88 ;
F_12 ( & V_4 -> V_25 , V_23 ) ;
V_87 = F_19 ( V_4 ) ;
V_88 = F_20 ( V_4 ) ;
if ( ! V_87 && ! V_88 ) {
F_13 ( & V_4 -> V_25 , V_23 ) ;
return;
}
V_47 = F_23 ( F_24 ( 0 ) ) ;
V_49 = F_23 ( F_24 ( 1 ) ) ;
if ( ( V_87 && V_47 != V_87 -> V_89 ) ||
( V_88 && V_49 != V_88 -> V_90 ) ) {
if ( V_87 )
V_87 -> V_89 = V_47 ;
if ( V_88 )
V_88 -> V_90 = V_49 ;
F_13 ( & V_4 -> V_25 , V_23 ) ;
F_1 ( V_2 ) ;
return;
}
F_13 ( & V_4 -> V_25 , V_23 ) ;
F_35 ( & V_4 -> V_5 . V_86 ) ;
}
static void
F_36 ( struct V_1 * V_2 , T_2 V_91 , T_2 V_92 , T_2 V_93 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_37 ( F_24 ( V_91 ) , V_92 ) ;
F_37 ( F_25 ( V_91 ) , V_93 ) ;
}
int
F_38 ( struct V_1 * V_2 , T_3 V_94 , T_3 V_95 ,
bool V_96 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_24 = 0 ;
unsigned long V_97 ;
F_39 ( V_98 ) ;
if ( V_4 -> V_99 >= V_94 )
return 0 ;
if ( V_95 == 0 )
return - V_100 ;
V_97 = V_7 + F_40 ( V_95 ) ;
F_41 ( V_2 , V_94 , V_95 ) ;
for (; ; ) {
F_42 ( & V_4 -> V_101 , & V_98 ,
V_96 ? V_102 :
V_103 ) ;
if ( V_96 && F_43 ( V_104 ) ) {
V_24 = - V_105 ;
break;
}
if ( V_4 -> V_99 >= V_94 )
break;
if ( V_95 != ~ 0ull ) {
if ( F_44 ( V_7 , V_97 ) ) {
V_24 = - V_100 ;
break;
}
F_45 ( V_97 - V_7 ) ;
} else {
F_46 () ;
}
}
F_47 ( & V_4 -> V_101 , & V_98 ) ;
F_48 ( V_2 , V_94 ) ;
return V_24 ;
}
static void
F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_37 ( V_106 ,
V_107 ) ;
F_37 ( V_108 ,
F_50 ( 0xf , V_109 ) |
F_50 ( 0xf , V_110 ) |
F_50 ( 0xf , V_111 ) |
F_50 ( 0xf , V_112 ) ) ;
}
void
F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_40 * V_41 ;
V_113:
V_41 = F_19 ( V_4 ) ;
if ( ! V_41 )
return;
F_49 ( V_2 ) ;
F_37 ( V_63 , 0 ) ;
F_37 ( V_65 , 0 ) ;
if ( V_41 -> V_47 != V_41 -> V_50 ) {
F_36 ( V_2 , 0 , V_41 -> V_47 , V_41 -> V_50 ) ;
} else {
F_52 ( V_2 , V_41 ) ;
goto V_113;
}
}
void
F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_40 * V_41 = F_20 ( V_4 ) ;
if ( ! V_41 )
return;
F_36 ( V_2 , 1 , V_41 -> V_49 , V_41 -> V_51 ) ;
}
void
F_52 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_114 = F_54 ( & V_4 -> V_115 ) ;
F_55 ( & V_41 -> V_116 , & V_4 -> V_115 ) ;
if ( V_114 )
F_53 ( V_2 ) ;
}
static void
F_56 ( struct V_40 * V_41 , T_3 V_94 )
{
struct V_31 * V_14 ;
unsigned V_10 ;
for ( V_10 = 0 ; V_10 < V_41 -> V_13 ; V_10 ++ ) {
V_14 = F_15 ( & V_41 -> V_14 [ V_10 ] -> V_35 ) ;
V_14 -> V_94 = V_94 ;
}
F_21 (bo, &exec->unref_list, unref_head) {
V_14 -> V_94 = V_94 ;
}
}
static void
F_57 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_94 ;
unsigned long V_23 ;
F_12 ( & V_4 -> V_25 , V_23 ) ;
V_94 = ++ V_4 -> V_117 ;
V_41 -> V_94 = V_94 ;
F_56 ( V_41 , V_94 ) ;
F_58 ( & V_41 -> V_116 , & V_4 -> V_118 ) ;
if ( F_19 ( V_4 ) == V_41 ) {
F_51 ( V_2 ) ;
F_1 ( V_2 ) ;
}
F_13 ( & V_4 -> V_25 , V_23 ) ;
}
static int
F_59 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_40 * V_41 )
{
struct V_119 * args = V_41 -> args ;
T_2 * V_120 ;
int V_24 = 0 ;
int V_10 ;
V_41 -> V_13 = args -> V_121 ;
if ( ! V_41 -> V_13 ) {
F_60 ( L_2 ) ;
return - V_122 ;
}
V_41 -> V_14 = F_14 ( V_41 -> V_13 , sizeof( struct V_123 * ) ,
V_28 ) ;
if ( ! V_41 -> V_14 ) {
F_60 ( L_3 ) ;
return - V_29 ;
}
V_120 = F_61 ( V_41 -> V_13 , sizeof( T_2 ) ) ;
if ( ! V_120 ) {
F_60 ( L_4 ) ;
goto V_124;
}
V_24 = F_62 ( V_120 ,
( void V_37 * ) ( V_38 ) args -> V_125 ,
V_41 -> V_13 * sizeof( T_2 ) ) ;
if ( V_24 ) {
F_60 ( L_5 ) ;
goto V_124;
}
F_63 ( & V_17 -> V_126 ) ;
for ( V_10 = 0 ; V_10 < V_41 -> V_13 ; V_10 ++ ) {
struct V_127 * V_14 = F_64 ( & V_17 -> V_128 ,
V_120 [ V_10 ] ) ;
if ( ! V_14 ) {
F_60 ( L_6 ,
V_10 , V_120 [ V_10 ] ) ;
V_24 = - V_122 ;
F_65 ( & V_17 -> V_126 ) ;
goto V_124;
}
F_22 ( V_14 ) ;
V_41 -> V_14 [ V_10 ] = (struct V_123 * ) V_14 ;
}
F_65 ( & V_17 -> V_126 ) ;
V_124:
F_10 ( V_120 ) ;
return 0 ;
}
static int
F_66 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
struct V_119 * args = V_41 -> args ;
void * V_129 = NULL ;
void * V_130 ;
int V_24 = 0 ;
T_2 V_131 = 0 ;
T_2 V_132 = F_67 ( V_131 + args -> V_133 ,
16 ) ;
T_2 V_134 = V_132 + args -> V_135 ;
T_2 V_136 = V_134 + args -> V_137 ;
T_2 V_138 = V_136 + ( sizeof( struct V_139 ) *
args -> V_140 ) ;
struct V_31 * V_14 ;
if ( V_134 < V_132 ||
V_136 < V_134 ||
args -> V_140 >= ( V_141 /
sizeof( struct V_139 ) ) ||
V_138 < V_136 ) {
F_60 ( L_7 ) ;
goto V_124;
}
V_129 = F_68 ( V_138 , V_28 ) ;
if ( ! V_129 ) {
F_60 ( L_8
L_9 ) ;
V_24 = - V_29 ;
goto V_124;
}
V_130 = V_129 + V_131 ;
V_41 -> V_142 = V_129 + V_132 ;
V_41 -> V_143 = V_129 + V_134 ;
V_41 -> V_144 = V_129 + V_136 ;
V_41 -> V_145 = args -> V_140 ;
if ( F_62 ( V_130 ,
( void V_37 * ) ( V_38 ) args -> V_146 ,
args -> V_133 ) ) {
V_24 = - V_39 ;
goto V_124;
}
if ( F_62 ( V_41 -> V_142 ,
( void V_37 * ) ( V_38 ) args -> V_147 ,
args -> V_135 ) ) {
V_24 = - V_39 ;
goto V_124;
}
if ( F_62 ( V_41 -> V_143 ,
( void V_37 * ) ( V_38 ) args -> V_148 ,
args -> V_137 ) ) {
V_24 = - V_39 ;
goto V_124;
}
V_14 = F_69 ( V_2 , V_136 , true ) ;
if ( F_70 ( V_14 ) ) {
F_60 ( L_10 ) ;
V_24 = F_71 ( V_14 ) ;
goto V_124;
}
V_41 -> V_149 = & V_14 -> V_35 ;
F_58 ( & F_15 ( & V_41 -> V_149 -> V_35 ) -> V_150 ,
& V_41 -> V_151 ) ;
V_41 -> V_47 = V_41 -> V_149 -> V_34 + V_131 ;
V_41 -> V_152 = V_130 ;
V_41 -> V_153 = V_41 -> V_149 -> V_154 + V_132 ;
V_41 -> V_155 = V_41 -> V_149 -> V_34 + V_132 ;
V_41 -> V_135 = args -> V_135 ;
V_41 -> V_156 = V_41 -> V_149 -> V_154 + V_134 ;
V_41 -> V_157 = V_41 -> V_149 -> V_34 + V_134 ;
V_41 -> V_137 = args -> V_137 ;
V_24 = F_72 ( V_2 ,
V_41 -> V_149 -> V_154 + V_131 ,
V_130 ,
V_41 ) ;
if ( V_24 )
goto V_124;
V_24 = F_73 ( V_2 , V_41 ) ;
V_124:
F_10 ( V_129 ) ;
return V_24 ;
}
static void
F_74 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned V_10 ;
F_7 ( & V_2 -> V_11 ) ;
if ( V_41 -> V_14 ) {
for ( V_10 = 0 ; V_10 < V_41 -> V_13 ; V_10 ++ )
F_8 ( & V_41 -> V_14 [ V_10 ] -> V_35 ) ;
F_10 ( V_41 -> V_14 ) ;
}
while ( ! F_54 ( & V_41 -> V_151 ) ) {
struct V_31 * V_14 = F_75 ( & V_41 -> V_151 ,
struct V_31 , V_150 ) ;
F_76 ( & V_14 -> V_150 ) ;
F_8 ( & V_14 -> V_35 . V_35 ) ;
}
F_9 ( & V_2 -> V_11 ) ;
F_7 ( & V_4 -> V_80 ) ;
if ( -- V_4 -> V_81 == 0 )
F_77 ( & V_4 -> V_82 -> V_83 -> V_2 ) ;
F_9 ( & V_4 -> V_80 ) ;
F_10 ( V_41 ) ;
}
void
F_78 ( struct V_3 * V_4 )
{
unsigned long V_23 ;
struct V_158 * V_159 , * V_160 ;
F_12 ( & V_4 -> V_25 , V_23 ) ;
while ( ! F_54 ( & V_4 -> V_161 ) ) {
struct V_40 * V_41 =
F_75 ( & V_4 -> V_161 ,
struct V_40 , V_116 ) ;
F_76 ( & V_41 -> V_116 ) ;
F_13 ( & V_4 -> V_25 , V_23 ) ;
F_74 ( V_4 -> V_2 , V_41 ) ;
F_12 ( & V_4 -> V_25 , V_23 ) ;
}
F_79 (cb, cb_temp, &vc4->seqno_cb_list, work.entry) {
if ( V_159 -> V_94 <= V_4 -> V_99 ) {
F_80 ( & V_159 -> V_85 . V_162 ) ;
F_35 ( & V_159 -> V_85 ) ;
}
}
F_13 ( & V_4 -> V_25 , V_23 ) ;
}
static void F_81 ( struct V_84 * V_85 )
{
struct V_158 * V_159 = F_33 ( V_85 , struct V_158 , V_85 ) ;
V_159 -> V_163 ( V_159 ) ;
}
int F_82 ( struct V_1 * V_2 ,
struct V_158 * V_159 , T_3 V_94 ,
void (* V_163)( struct V_158 * V_159 ) )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_24 = 0 ;
unsigned long V_23 ;
V_159 -> V_163 = V_163 ;
F_83 ( & V_159 -> V_85 , F_81 ) ;
F_12 ( & V_4 -> V_25 , V_23 ) ;
if ( V_94 > V_4 -> V_99 ) {
V_159 -> V_94 = V_94 ;
F_58 ( & V_159 -> V_85 . V_162 , & V_4 -> V_164 ) ;
} else {
F_35 ( & V_159 -> V_85 ) ;
}
F_13 ( & V_4 -> V_25 , V_23 ) ;
return V_24 ;
}
static void
F_84 ( struct V_84 * V_85 )
{
struct V_3 * V_4 =
F_33 ( V_85 , struct V_3 , V_165 ) ;
F_78 ( V_4 ) ;
}
static int
F_85 ( struct V_1 * V_2 ,
T_3 V_94 ,
T_3 * V_95 )
{
unsigned long V_92 = V_7 ;
int V_24 = F_38 ( V_2 , V_94 , * V_95 , true ) ;
if ( ( V_24 == - V_166 || V_24 == - V_105 ) && * V_95 != ~ 0ull ) {
T_3 V_167 = F_86 ( V_7 - V_92 ) ;
if ( * V_95 >= V_167 )
* V_95 -= V_167 ;
}
return V_24 ;
}
int
F_87 ( struct V_1 * V_2 , void * V_15 ,
struct V_16 * V_17 )
{
struct V_168 * args = V_15 ;
return F_85 ( V_2 , args -> V_94 ,
& args -> V_95 ) ;
}
int
F_88 ( struct V_1 * V_2 , void * V_15 ,
struct V_16 * V_17 )
{
int V_24 ;
struct V_169 * args = V_15 ;
struct V_127 * V_170 ;
struct V_31 * V_14 ;
if ( args -> V_171 != 0 )
return - V_122 ;
V_170 = F_89 ( V_17 , args -> V_32 ) ;
if ( ! V_170 ) {
F_60 ( L_11 , args -> V_32 ) ;
return - V_122 ;
}
V_14 = F_15 ( V_170 ) ;
V_24 = F_85 ( V_2 , V_14 -> V_94 ,
& args -> V_95 ) ;
F_90 ( V_170 ) ;
return V_24 ;
}
int
F_91 ( struct V_1 * V_2 , void * V_15 ,
struct V_16 * V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_119 * args = V_15 ;
struct V_40 * V_41 ;
int V_24 = 0 ;
if ( ( args -> V_172 & ~ V_173 ) != 0 ) {
F_60 ( L_12 , args -> V_172 ) ;
return - V_122 ;
}
V_41 = F_14 ( 1 , sizeof( * V_41 ) , V_28 ) ;
if ( ! V_41 ) {
F_60 ( L_13 ) ;
return - V_29 ;
}
F_7 ( & V_4 -> V_80 ) ;
if ( V_4 -> V_81 ++ == 0 )
V_24 = F_30 ( & V_4 -> V_82 -> V_83 -> V_2 ) ;
F_9 ( & V_4 -> V_80 ) ;
if ( V_24 < 0 ) {
F_10 ( V_41 ) ;
return V_24 ;
}
V_41 -> args = args ;
F_92 ( & V_41 -> V_151 ) ;
V_24 = F_59 ( V_2 , V_17 , V_41 ) ;
if ( V_24 )
goto V_124;
if ( V_41 -> args -> V_133 != 0 ) {
V_24 = F_66 ( V_2 , V_41 ) ;
if ( V_24 )
goto V_124;
} else {
V_41 -> V_47 = 0 ;
V_41 -> V_50 = 0 ;
}
V_24 = F_93 ( V_2 , V_41 ) ;
if ( V_24 )
goto V_124;
V_41 -> args = NULL ;
F_57 ( V_2 , V_41 ) ;
args -> V_94 = V_4 -> V_117 ;
return 0 ;
V_124:
F_74 ( V_4 -> V_2 , V_41 ) ;
return V_24 ;
}
void
F_94 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_92 ( & V_4 -> V_118 ) ;
F_92 ( & V_4 -> V_115 ) ;
F_92 ( & V_4 -> V_161 ) ;
F_92 ( & V_4 -> V_164 ) ;
F_95 ( & V_4 -> V_25 ) ;
F_83 ( & V_4 -> V_5 . V_86 , F_32 ) ;
F_96 ( & V_4 -> V_5 . V_6 ,
F_34 ,
( unsigned long ) V_2 ) ;
F_83 ( & V_4 -> V_165 , F_84 ) ;
F_97 ( & V_4 -> V_80 ) ;
}
void
F_98 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_99 ( V_4 -> V_117 != V_4 -> V_99 ) ;
if ( V_4 -> V_174 ) {
F_90 ( & V_4 -> V_174 -> V_35 . V_35 ) ;
V_4 -> V_174 = NULL ;
}
F_100 ( V_2 ) ;
if ( V_4 -> V_26 )
F_6 ( V_2 , V_4 -> V_26 ) ;
}
