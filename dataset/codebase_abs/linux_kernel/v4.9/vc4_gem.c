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
V_9 -> V_12 = V_10 - 1 ;
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
F_8 ( V_20 ) ;
V_29:
F_6 ( V_2 , V_21 ) ;
V_32:
return V_23 ;
}
static void
F_16 ( struct V_1 * V_2 )
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
V_40 [ 0 ] = F_17 ( V_4 ) ;
V_40 [ 1 ] = F_18 ( V_4 ) ;
if ( ! V_40 [ 0 ] && ! V_40 [ 1 ] ) {
F_11 ( & V_4 -> V_24 , V_22 ) ;
return;
}
V_9 -> V_12 = 0 ;
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ ) {
if ( ! V_40 [ V_10 ] )
continue;
V_42 = 0 ;
F_19 (bo, &exec[i]->unref_list, unref_head)
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
F_20 ( & V_40 [ V_10 ] -> V_13 [ V_41 ] -> V_34 ) ;
V_21 -> V_13 [ V_41 + V_43 ] = & V_40 [ V_10 ] -> V_13 [ V_41 ] -> V_34 ;
}
F_19 (bo, &exec[i]->unref_list, unref_head) {
F_20 ( & V_13 -> V_34 . V_34 ) ;
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
V_9 -> V_46 = F_21 ( F_22 ( 0 ) ) ;
V_9 -> V_49 = F_21 ( F_23 ( 0 ) ) ;
V_9 -> V_48 = F_21 ( F_22 ( 1 ) ) ;
V_9 -> V_50 = F_21 ( F_23 ( 1 ) ) ;
V_9 -> V_51 = F_21 ( F_24 ( 0 ) ) ;
V_9 -> V_52 = F_21 ( F_24 ( 1 ) ) ;
V_9 -> V_53 = F_21 ( V_54 ) ;
V_9 -> V_55 = F_21 ( V_56 ) ;
V_9 -> V_57 = F_21 ( V_58 ) ;
V_9 -> V_59 = F_21 ( V_60 ) ;
V_9 -> V_61 = F_21 ( V_62 ) ;
V_9 -> V_63 = F_21 ( V_64 ) ;
V_9 -> V_65 = F_21 ( V_66 ) ;
V_9 -> V_67 = F_21 ( V_68 ) ;
V_9 -> V_69 = F_21 ( V_70 ) ;
V_9 -> V_71 = F_21 ( V_72 ) ;
V_9 -> V_73 = F_21 ( V_74 ) ;
V_9 -> V_75 = F_21 ( V_76 ) ;
V_9 -> V_77 = F_21 ( V_78 ) ;
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
F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_26 ( L_1 ) ;
F_27 ( & V_4 -> V_79 ) ;
if ( V_4 -> V_80 ) {
F_28 ( & V_4 -> V_81 -> V_82 -> V_2 ) ;
F_29 ( & V_4 -> V_81 -> V_82 -> V_2 ) ;
}
F_30 ( & V_4 -> V_79 ) ;
F_31 ( V_2 ) ;
F_1 ( V_2 ) ;
}
static void
F_32 ( struct V_83 * V_84 )
{
struct V_3 * V_4 =
F_33 ( V_84 , struct V_3 , V_5 . V_85 ) ;
F_16 ( V_4 -> V_2 ) ;
F_25 ( V_4 -> V_2 ) ;
}
static void
F_34 ( unsigned long V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_46 , V_48 ;
unsigned long V_22 ;
struct V_39 * V_86 , * V_87 ;
F_10 ( & V_4 -> V_24 , V_22 ) ;
V_86 = F_17 ( V_4 ) ;
V_87 = F_18 ( V_4 ) ;
if ( ! V_86 && ! V_87 ) {
F_11 ( & V_4 -> V_24 , V_22 ) ;
return;
}
V_46 = F_21 ( F_22 ( 0 ) ) ;
V_48 = F_21 ( F_22 ( 1 ) ) ;
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
F_35 ( & V_4 -> V_5 . V_85 ) ;
}
static void
F_36 ( struct V_1 * V_2 , T_2 V_90 , T_2 V_91 , T_2 V_92 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_37 ( F_22 ( V_90 ) , V_91 ) ;
F_37 ( F_23 ( V_90 ) , V_92 ) ;
}
int
F_38 ( struct V_1 * V_2 , T_3 V_93 , T_3 V_94 ,
bool V_95 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_23 = 0 ;
unsigned long V_96 ;
F_39 ( V_97 ) ;
if ( V_4 -> V_98 >= V_93 )
return 0 ;
if ( V_94 == 0 )
return - V_99 ;
V_96 = V_7 + F_40 ( V_94 ) ;
F_41 ( V_2 , V_93 , V_94 ) ;
for (; ; ) {
F_42 ( & V_4 -> V_100 , & V_97 ,
V_95 ? V_101 :
V_102 ) ;
if ( V_95 && F_43 ( V_103 ) ) {
V_23 = - V_104 ;
break;
}
if ( V_4 -> V_98 >= V_93 )
break;
if ( V_94 != ~ 0ull ) {
if ( F_44 ( V_7 , V_96 ) ) {
V_23 = - V_99 ;
break;
}
F_45 ( V_96 - V_7 ) ;
} else {
F_46 () ;
}
}
F_47 ( & V_4 -> V_100 , & V_97 ) ;
F_48 ( V_2 , V_93 ) ;
return V_23 ;
}
static void
F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_37 ( V_105 ,
V_106 ) ;
F_37 ( V_107 ,
F_50 ( 0xf , V_108 ) |
F_50 ( 0xf , V_109 ) |
F_50 ( 0xf , V_110 ) |
F_50 ( 0xf , V_111 ) ) ;
}
void
F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_39 * V_40 ;
V_112:
V_40 = F_17 ( V_4 ) ;
if ( ! V_40 )
return;
F_49 ( V_2 ) ;
if ( V_40 -> V_46 != V_40 -> V_49 ) {
F_36 ( V_2 , 0 , V_40 -> V_46 , V_40 -> V_49 ) ;
} else {
F_52 ( V_2 , V_40 ) ;
goto V_112;
}
}
void
F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_39 * V_40 = F_18 ( V_4 ) ;
if ( ! V_40 )
return;
F_36 ( V_2 , 1 , V_40 -> V_48 , V_40 -> V_50 ) ;
}
void
F_52 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_113 = F_54 ( & V_4 -> V_114 ) ;
F_55 ( & V_40 -> V_115 , & V_4 -> V_114 ) ;
if ( V_113 )
F_53 ( V_2 ) ;
}
static void
F_56 ( struct V_39 * V_40 , T_3 V_93 )
{
struct V_30 * V_13 ;
unsigned V_10 ;
for ( V_10 = 0 ; V_10 < V_40 -> V_12 ; V_10 ++ ) {
V_13 = F_13 ( & V_40 -> V_13 [ V_10 ] -> V_34 ) ;
V_13 -> V_93 = V_93 ;
}
F_19 (bo, &exec->unref_list, unref_head) {
V_13 -> V_93 = V_93 ;
}
for ( V_10 = 0 ; V_10 < V_40 -> V_116 ; V_10 ++ ) {
V_13 = F_13 ( & V_40 -> V_117 [ V_10 ] -> V_34 ) ;
V_13 -> V_118 = V_93 ;
}
}
static void
F_57 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_93 ;
unsigned long V_22 ;
F_10 ( & V_4 -> V_24 , V_22 ) ;
V_93 = ++ V_4 -> V_119 ;
V_40 -> V_93 = V_93 ;
F_56 ( V_40 , V_93 ) ;
F_58 ( & V_40 -> V_115 , & V_4 -> V_120 ) ;
if ( F_17 ( V_4 ) == V_40 ) {
F_51 ( V_2 ) ;
F_1 ( V_2 ) ;
}
F_11 ( & V_4 -> V_24 , V_22 ) ;
}
static int
F_59 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_39 * V_40 )
{
struct V_121 * args = V_40 -> args ;
T_2 * V_122 ;
int V_23 = 0 ;
int V_10 ;
V_40 -> V_12 = args -> V_123 ;
if ( ! V_40 -> V_12 ) {
F_60 ( L_2 ) ;
return - V_124 ;
}
V_40 -> V_13 = F_61 ( V_40 -> V_12 ,
sizeof( struct V_125 * ) ) ;
if ( ! V_40 -> V_13 ) {
F_60 ( L_3 ) ;
return - V_28 ;
}
V_122 = F_62 ( V_40 -> V_12 , sizeof( T_2 ) ) ;
if ( ! V_122 ) {
F_60 ( L_4 ) ;
goto V_126;
}
V_23 = F_63 ( V_122 ,
( void V_36 * ) ( V_37 ) args -> V_127 ,
V_40 -> V_12 * sizeof( T_2 ) ) ;
if ( V_23 ) {
F_60 ( L_5 ) ;
goto V_126;
}
F_64 ( & V_16 -> V_128 ) ;
for ( V_10 = 0 ; V_10 < V_40 -> V_12 ; V_10 ++ ) {
struct V_129 * V_13 = F_65 ( & V_16 -> V_130 ,
V_122 [ V_10 ] ) ;
if ( ! V_13 ) {
F_60 ( L_6 ,
V_10 , V_122 [ V_10 ] ) ;
V_23 = - V_124 ;
F_66 ( & V_16 -> V_128 ) ;
goto V_126;
}
F_20 ( V_13 ) ;
V_40 -> V_13 [ V_10 ] = (struct V_125 * ) V_13 ;
}
F_66 ( & V_16 -> V_128 ) ;
V_126:
F_67 ( V_122 ) ;
return V_23 ;
}
static int
F_68 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
struct V_121 * args = V_40 -> args ;
void * V_131 = NULL ;
void * V_132 ;
int V_23 = 0 ;
T_2 V_133 = 0 ;
T_2 V_134 = F_69 ( V_133 + args -> V_135 ,
16 ) ;
T_2 V_136 = V_134 + args -> V_137 ;
T_2 V_138 = V_136 + args -> V_139 ;
T_2 V_140 = V_138 + ( sizeof( struct V_141 ) *
args -> V_142 ) ;
struct V_30 * V_13 ;
if ( V_136 < V_134 ||
V_138 < V_136 ||
args -> V_142 >= ( V_143 /
sizeof( struct V_141 ) ) ||
V_140 < V_138 ) {
F_60 ( L_7 ) ;
goto V_126;
}
V_131 = F_62 ( V_140 , 1 ) ;
if ( ! V_131 ) {
F_60 ( L_8
L_9 ) ;
V_23 = - V_28 ;
goto V_126;
}
V_132 = V_131 + V_133 ;
V_40 -> V_144 = V_131 + V_134 ;
V_40 -> V_145 = V_131 + V_136 ;
V_40 -> V_146 = V_131 + V_138 ;
V_40 -> V_147 = args -> V_142 ;
if ( F_63 ( V_132 ,
( void V_36 * ) ( V_37 ) args -> V_148 ,
args -> V_135 ) ) {
V_23 = - V_38 ;
goto V_126;
}
if ( F_63 ( V_40 -> V_144 ,
( void V_36 * ) ( V_37 ) args -> V_149 ,
args -> V_137 ) ) {
V_23 = - V_38 ;
goto V_126;
}
if ( F_63 ( V_40 -> V_145 ,
( void V_36 * ) ( V_37 ) args -> V_150 ,
args -> V_139 ) ) {
V_23 = - V_38 ;
goto V_126;
}
V_13 = F_70 ( V_2 , V_138 , true ) ;
if ( F_71 ( V_13 ) ) {
F_60 ( L_10 ) ;
V_23 = F_72 ( V_13 ) ;
goto V_126;
}
V_40 -> V_151 = & V_13 -> V_34 ;
F_58 ( & F_13 ( & V_40 -> V_151 -> V_34 ) -> V_152 ,
& V_40 -> V_153 ) ;
V_40 -> V_46 = V_40 -> V_151 -> V_33 + V_133 ;
V_40 -> V_154 = V_132 ;
V_40 -> V_155 = V_40 -> V_151 -> V_156 + V_134 ;
V_40 -> V_157 = V_40 -> V_151 -> V_33 + V_134 ;
V_40 -> V_137 = args -> V_137 ;
V_40 -> V_158 = V_40 -> V_151 -> V_156 + V_136 ;
V_40 -> V_159 = V_40 -> V_151 -> V_33 + V_136 ;
V_40 -> V_139 = args -> V_139 ;
V_23 = F_73 ( V_2 ,
V_40 -> V_151 -> V_156 + V_133 ,
V_132 ,
V_40 ) ;
if ( V_23 )
goto V_126;
V_23 = F_74 ( V_2 , V_40 ) ;
if ( V_23 )
goto V_126;
V_23 = F_38 ( V_2 , V_40 -> V_160 , ~ 0ull , true ) ;
V_126:
F_67 ( V_131 ) ;
return V_23 ;
}
static void
F_75 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned V_10 ;
if ( V_40 -> V_13 ) {
for ( V_10 = 0 ; V_10 < V_40 -> V_12 ; V_10 ++ )
F_7 ( & V_40 -> V_13 [ V_10 ] -> V_34 ) ;
F_67 ( V_40 -> V_13 ) ;
}
while ( ! F_54 ( & V_40 -> V_153 ) ) {
struct V_30 * V_13 = F_76 ( & V_40 -> V_153 ,
struct V_30 , V_152 ) ;
F_77 ( & V_13 -> V_152 ) ;
F_7 ( & V_13 -> V_34 . V_34 ) ;
}
F_27 ( & V_4 -> V_79 ) ;
if ( -- V_4 -> V_80 == 0 )
F_78 ( & V_4 -> V_81 -> V_82 -> V_2 ) ;
F_30 ( & V_4 -> V_79 ) ;
F_8 ( V_40 ) ;
}
void
F_79 ( struct V_3 * V_4 )
{
unsigned long V_22 ;
struct V_161 * V_162 , * V_163 ;
F_10 ( & V_4 -> V_24 , V_22 ) ;
while ( ! F_54 ( & V_4 -> V_164 ) ) {
struct V_39 * V_40 =
F_76 ( & V_4 -> V_164 ,
struct V_39 , V_115 ) ;
F_77 ( & V_40 -> V_115 ) ;
F_11 ( & V_4 -> V_24 , V_22 ) ;
F_75 ( V_4 -> V_2 , V_40 ) ;
F_10 ( & V_4 -> V_24 , V_22 ) ;
}
F_80 (cb, cb_temp, &vc4->seqno_cb_list, work.entry) {
if ( V_162 -> V_93 <= V_4 -> V_98 ) {
F_81 ( & V_162 -> V_84 . V_165 ) ;
F_35 ( & V_162 -> V_84 ) ;
}
}
F_11 ( & V_4 -> V_24 , V_22 ) ;
}
static void F_82 ( struct V_83 * V_84 )
{
struct V_161 * V_162 = F_33 ( V_84 , struct V_161 , V_84 ) ;
V_162 -> V_166 ( V_162 ) ;
}
int F_83 ( struct V_1 * V_2 ,
struct V_161 * V_162 , T_3 V_93 ,
void (* V_166)( struct V_161 * V_162 ) )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_23 = 0 ;
unsigned long V_22 ;
V_162 -> V_166 = V_166 ;
F_84 ( & V_162 -> V_84 , F_82 ) ;
F_10 ( & V_4 -> V_24 , V_22 ) ;
if ( V_93 > V_4 -> V_98 ) {
V_162 -> V_93 = V_93 ;
F_58 ( & V_162 -> V_84 . V_165 , & V_4 -> V_167 ) ;
} else {
F_35 ( & V_162 -> V_84 ) ;
}
F_11 ( & V_4 -> V_24 , V_22 ) ;
return V_23 ;
}
static void
F_85 ( struct V_83 * V_84 )
{
struct V_3 * V_4 =
F_33 ( V_84 , struct V_3 , V_168 ) ;
F_79 ( V_4 ) ;
}
static int
F_86 ( struct V_1 * V_2 ,
T_3 V_93 ,
T_3 * V_94 )
{
unsigned long V_91 = V_7 ;
int V_23 = F_38 ( V_2 , V_93 , * V_94 , true ) ;
if ( ( V_23 == - V_169 || V_23 == - V_104 ) && * V_94 != ~ 0ull ) {
T_3 V_170 = F_87 ( V_7 - V_91 ) ;
if ( * V_94 >= V_170 )
* V_94 -= V_170 ;
}
return V_23 ;
}
int
F_88 ( struct V_1 * V_2 , void * V_14 ,
struct V_15 * V_16 )
{
struct V_171 * args = V_14 ;
return F_86 ( V_2 , args -> V_93 ,
& args -> V_94 ) ;
}
int
F_89 ( struct V_1 * V_2 , void * V_14 ,
struct V_15 * V_16 )
{
int V_23 ;
struct V_172 * args = V_14 ;
struct V_129 * V_173 ;
struct V_30 * V_13 ;
if ( args -> V_174 != 0 )
return - V_124 ;
V_173 = F_90 ( V_16 , args -> V_31 ) ;
if ( ! V_173 ) {
F_60 ( L_11 , args -> V_31 ) ;
return - V_124 ;
}
V_13 = F_13 ( V_173 ) ;
V_23 = F_86 ( V_2 , V_13 -> V_93 ,
& args -> V_94 ) ;
F_7 ( V_173 ) ;
return V_23 ;
}
int
F_91 ( struct V_1 * V_2 , void * V_14 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_121 * args = V_14 ;
struct V_39 * V_40 ;
int V_23 = 0 ;
if ( ( args -> V_175 & ~ V_176 ) != 0 ) {
F_60 ( L_12 , args -> V_175 ) ;
return - V_124 ;
}
V_40 = F_12 ( 1 , sizeof( * V_40 ) , V_27 ) ;
if ( ! V_40 ) {
F_60 ( L_13 ) ;
return - V_28 ;
}
F_27 ( & V_4 -> V_79 ) ;
if ( V_4 -> V_80 ++ == 0 )
V_23 = F_29 ( & V_4 -> V_81 -> V_82 -> V_2 ) ;
F_30 ( & V_4 -> V_79 ) ;
if ( V_23 < 0 ) {
F_8 ( V_40 ) ;
return V_23 ;
}
V_40 -> args = args ;
F_92 ( & V_40 -> V_153 ) ;
V_23 = F_59 ( V_2 , V_16 , V_40 ) ;
if ( V_23 )
goto V_126;
if ( V_40 -> args -> V_135 != 0 ) {
V_23 = F_68 ( V_2 , V_40 ) ;
if ( V_23 )
goto V_126;
} else {
V_40 -> V_46 = 0 ;
V_40 -> V_49 = 0 ;
}
V_23 = F_93 ( V_2 , V_40 ) ;
if ( V_23 )
goto V_126;
V_40 -> args = NULL ;
F_57 ( V_2 , V_40 ) ;
args -> V_93 = V_4 -> V_119 ;
return 0 ;
V_126:
F_75 ( V_4 -> V_2 , V_40 ) ;
return V_23 ;
}
void
F_94 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_92 ( & V_4 -> V_120 ) ;
F_92 ( & V_4 -> V_114 ) ;
F_92 ( & V_4 -> V_164 ) ;
F_92 ( & V_4 -> V_167 ) ;
F_95 ( & V_4 -> V_24 ) ;
F_84 ( & V_4 -> V_5 . V_85 , F_32 ) ;
F_96 ( & V_4 -> V_5 . V_6 ,
F_34 ,
( unsigned long ) V_2 ) ;
F_84 ( & V_4 -> V_168 , F_85 ) ;
F_97 ( & V_4 -> V_79 ) ;
}
void
F_98 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_99 ( V_4 -> V_119 != V_4 -> V_98 ) ;
if ( V_4 -> V_177 ) {
F_7 ( & V_4 -> V_177 -> V_34 . V_34 ) ;
V_4 -> V_177 = NULL ;
}
if ( V_4 -> V_25 )
F_6 ( V_2 , V_4 -> V_25 ) ;
F_100 ( V_2 ) ;
}
