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
struct V_40 * V_41 ;
struct V_31 * V_14 ;
unsigned long V_23 ;
unsigned int V_10 , V_42 ;
V_22 = F_14 ( 1 , sizeof( * V_22 ) , V_28 ) ;
if ( ! V_22 )
return;
V_9 = & V_22 -> V_12 ;
F_12 ( & V_4 -> V_25 , V_23 ) ;
V_41 = F_19 ( V_4 ) ;
if ( ! V_41 ) {
F_13 ( & V_4 -> V_25 , V_23 ) ;
return;
}
V_42 = 0 ;
F_20 (bo, &exec->unref_list, unref_head)
V_42 ++ ;
V_9 -> V_13 = V_41 -> V_13 + V_42 ;
V_22 -> V_14 = F_14 ( V_9 -> V_13 , sizeof( * V_22 -> V_14 ) ,
V_43 ) ;
if ( ! V_22 -> V_14 ) {
F_13 ( & V_4 -> V_25 , V_23 ) ;
return;
}
for ( V_10 = 0 ; V_10 < V_41 -> V_13 ; V_10 ++ ) {
F_21 ( & V_41 -> V_14 [ V_10 ] -> V_35 ) ;
V_22 -> V_14 [ V_10 ] = & V_41 -> V_14 [ V_10 ] -> V_35 ;
}
F_20 (bo, &exec->unref_list, unref_head) {
F_21 ( & V_14 -> V_35 . V_35 ) ;
V_22 -> V_14 [ V_10 ] = & V_14 -> V_35 . V_35 ;
V_10 ++ ;
}
V_9 -> V_44 = V_41 -> V_45 ;
V_9 -> V_46 = V_41 -> V_47 ;
F_13 ( & V_4 -> V_25 , V_23 ) ;
V_9 -> V_45 = F_22 ( F_23 ( 0 ) ) ;
V_9 -> V_48 = F_22 ( F_24 ( 0 ) ) ;
V_9 -> V_47 = F_22 ( F_23 ( 1 ) ) ;
V_9 -> V_49 = F_22 ( F_24 ( 1 ) ) ;
V_9 -> V_50 = F_22 ( F_25 ( 0 ) ) ;
V_9 -> V_51 = F_22 ( F_25 ( 1 ) ) ;
V_9 -> V_52 = F_22 ( V_53 ) ;
V_9 -> V_54 = F_22 ( V_55 ) ;
V_9 -> V_56 = F_22 ( V_57 ) ;
V_9 -> V_58 = F_22 ( V_59 ) ;
V_9 -> V_60 = F_22 ( V_61 ) ;
V_9 -> V_62 = F_22 ( V_63 ) ;
V_9 -> V_64 = F_22 ( V_65 ) ;
V_9 -> V_66 = F_22 ( V_67 ) ;
V_9 -> V_68 = F_22 ( V_69 ) ;
V_9 -> V_70 = F_22 ( V_71 ) ;
V_9 -> V_72 = F_22 ( V_73 ) ;
V_9 -> V_74 = F_22 ( V_75 ) ;
V_9 -> V_76 = F_22 ( V_77 ) ;
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
F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_27 ( L_1 ) ;
F_7 ( & V_4 -> V_78 ) ;
if ( V_4 -> V_79 ) {
F_28 ( & V_4 -> V_80 -> V_81 -> V_2 ) ;
F_29 ( & V_4 -> V_80 -> V_81 -> V_2 ) ;
}
F_9 ( & V_4 -> V_78 ) ;
F_30 ( V_2 ) ;
F_1 ( V_2 ) ;
}
static void
F_31 ( struct V_82 * V_83 )
{
struct V_3 * V_4 =
F_32 ( V_83 , struct V_3 , V_5 . V_84 ) ;
F_18 ( V_4 -> V_2 ) ;
F_26 ( V_4 -> V_2 ) ;
}
static void
F_33 ( unsigned long V_15 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_45 , V_47 ;
unsigned long V_23 ;
struct V_40 * V_41 ;
F_12 ( & V_4 -> V_25 , V_23 ) ;
V_41 = F_19 ( V_4 ) ;
if ( ! V_41 ) {
F_13 ( & V_4 -> V_25 , V_23 ) ;
return;
}
V_45 = F_22 ( F_23 ( 0 ) ) ;
V_47 = F_22 ( F_23 ( 1 ) ) ;
if ( V_45 != V_41 -> V_85 || V_47 != V_41 -> V_86 ) {
V_41 -> V_85 = V_45 ;
V_41 -> V_86 = V_47 ;
F_13 ( & V_4 -> V_25 , V_23 ) ;
F_1 ( V_2 ) ;
return;
}
F_13 ( & V_4 -> V_25 , V_23 ) ;
F_34 ( & V_4 -> V_5 . V_84 ) ;
}
static void
F_35 ( struct V_1 * V_2 , T_2 V_87 , T_2 V_88 , T_2 V_89 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_36 ( F_23 ( V_87 ) , V_88 ) ;
F_36 ( F_24 ( V_87 ) , V_89 ) ;
}
int
F_37 ( struct V_1 * V_2 , T_3 V_90 , T_3 V_91 ,
bool V_92 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_24 = 0 ;
unsigned long V_93 ;
F_38 ( V_94 ) ;
if ( V_4 -> V_95 >= V_90 )
return 0 ;
if ( V_91 == 0 )
return - V_96 ;
V_93 = V_7 + F_39 ( V_91 ) ;
F_40 ( V_2 , V_90 , V_91 ) ;
for (; ; ) {
F_41 ( & V_4 -> V_97 , & V_94 ,
V_92 ? V_98 :
V_99 ) ;
if ( V_92 && F_42 ( V_100 ) ) {
V_24 = - V_101 ;
break;
}
if ( V_4 -> V_95 >= V_90 )
break;
if ( V_91 != ~ 0ull ) {
if ( F_43 ( V_7 , V_93 ) ) {
V_24 = - V_96 ;
break;
}
F_44 ( V_93 - V_7 ) ;
} else {
F_45 () ;
}
}
F_46 ( & V_4 -> V_97 , & V_94 ) ;
F_47 ( V_2 , V_90 ) ;
return V_24 ;
}
static void
F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_36 ( V_102 ,
V_103 ) ;
F_36 ( V_104 ,
F_49 ( 0xf , V_105 ) |
F_49 ( 0xf , V_106 ) |
F_49 ( 0xf , V_107 ) |
F_49 ( 0xf , V_108 ) ) ;
}
void
F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_40 * V_41 = F_19 ( V_4 ) ;
if ( ! V_41 )
return;
F_48 ( V_2 ) ;
F_36 ( V_61 , 0 ) ;
F_36 ( V_63 , 0 ) ;
if ( V_41 -> V_45 != V_41 -> V_48 )
F_35 ( V_2 , 0 , V_41 -> V_45 , V_41 -> V_48 ) ;
F_35 ( V_2 , 1 , V_41 -> V_47 , V_41 -> V_49 ) ;
}
static void
F_51 ( struct V_40 * V_41 , T_3 V_90 )
{
struct V_31 * V_14 ;
unsigned V_10 ;
for ( V_10 = 0 ; V_10 < V_41 -> V_13 ; V_10 ++ ) {
V_14 = F_15 ( & V_41 -> V_14 [ V_10 ] -> V_35 ) ;
V_14 -> V_90 = V_90 ;
}
F_20 (bo, &exec->unref_list, unref_head) {
V_14 -> V_90 = V_90 ;
}
}
static void
F_52 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_90 ;
unsigned long V_23 ;
F_12 ( & V_4 -> V_25 , V_23 ) ;
V_90 = ++ V_4 -> V_109 ;
V_41 -> V_90 = V_90 ;
F_51 ( V_41 , V_90 ) ;
F_53 ( & V_41 -> V_110 , & V_4 -> V_111 ) ;
if ( F_19 ( V_4 ) == V_41 ) {
F_50 ( V_2 ) ;
F_1 ( V_2 ) ;
}
F_13 ( & V_4 -> V_25 , V_23 ) ;
}
static int
F_54 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_40 * V_41 )
{
struct V_112 * args = V_41 -> args ;
T_2 * V_113 ;
int V_24 = 0 ;
int V_10 ;
V_41 -> V_13 = args -> V_114 ;
if ( ! V_41 -> V_13 ) {
F_55 ( L_2 ) ;
return - V_115 ;
}
V_41 -> V_14 = F_14 ( V_41 -> V_13 , sizeof( struct V_116 * ) ,
V_28 ) ;
if ( ! V_41 -> V_14 ) {
F_55 ( L_3 ) ;
return - V_29 ;
}
V_113 = F_56 ( V_41 -> V_13 , sizeof( T_2 ) ) ;
if ( ! V_113 ) {
F_55 ( L_4 ) ;
goto V_117;
}
V_24 = F_57 ( V_113 ,
( void V_37 * ) ( V_38 ) args -> V_118 ,
V_41 -> V_13 * sizeof( T_2 ) ) ;
if ( V_24 ) {
F_55 ( L_5 ) ;
goto V_117;
}
F_58 ( & V_17 -> V_119 ) ;
for ( V_10 = 0 ; V_10 < V_41 -> V_13 ; V_10 ++ ) {
struct V_120 * V_14 = F_59 ( & V_17 -> V_121 ,
V_113 [ V_10 ] ) ;
if ( ! V_14 ) {
F_55 ( L_6 ,
V_10 , V_113 [ V_10 ] ) ;
V_24 = - V_115 ;
F_60 ( & V_17 -> V_119 ) ;
goto V_117;
}
F_21 ( V_14 ) ;
V_41 -> V_14 [ V_10 ] = (struct V_116 * ) V_14 ;
}
F_60 ( & V_17 -> V_119 ) ;
V_117:
F_10 ( V_113 ) ;
return 0 ;
}
static int
F_61 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
struct V_112 * args = V_41 -> args ;
void * V_122 = NULL ;
void * V_123 ;
int V_24 = 0 ;
T_2 V_124 = 0 ;
T_2 V_125 = F_62 ( V_124 + args -> V_126 ,
16 ) ;
T_2 V_127 = V_125 + args -> V_128 ;
T_2 V_129 = V_127 + args -> V_130 ;
T_2 V_131 = V_129 + ( sizeof( struct V_132 ) *
args -> V_133 ) ;
struct V_31 * V_14 ;
if ( V_127 < V_125 ||
V_129 < V_127 ||
args -> V_133 >= ( V_134 /
sizeof( struct V_132 ) ) ||
V_131 < V_129 ) {
F_55 ( L_7 ) ;
goto V_117;
}
V_122 = F_63 ( V_131 , V_28 ) ;
if ( ! V_122 ) {
F_55 ( L_8
L_9 ) ;
V_24 = - V_29 ;
goto V_117;
}
V_123 = V_122 + V_124 ;
V_41 -> V_135 = V_122 + V_125 ;
V_41 -> V_136 = V_122 + V_127 ;
V_41 -> V_137 = V_122 + V_129 ;
V_41 -> V_138 = args -> V_133 ;
if ( F_57 ( V_123 ,
( void V_37 * ) ( V_38 ) args -> V_139 ,
args -> V_126 ) ) {
V_24 = - V_39 ;
goto V_117;
}
if ( F_57 ( V_41 -> V_135 ,
( void V_37 * ) ( V_38 ) args -> V_140 ,
args -> V_128 ) ) {
V_24 = - V_39 ;
goto V_117;
}
if ( F_57 ( V_41 -> V_136 ,
( void V_37 * ) ( V_38 ) args -> V_141 ,
args -> V_130 ) ) {
V_24 = - V_39 ;
goto V_117;
}
V_14 = F_64 ( V_2 , V_129 , true ) ;
if ( F_65 ( V_14 ) ) {
F_55 ( L_10 ) ;
V_24 = F_66 ( V_14 ) ;
goto V_117;
}
V_41 -> V_142 = & V_14 -> V_35 ;
F_53 ( & F_15 ( & V_41 -> V_142 -> V_35 ) -> V_143 ,
& V_41 -> V_144 ) ;
V_41 -> V_45 = V_41 -> V_142 -> V_34 + V_124 ;
V_41 -> V_145 = V_123 ;
V_41 -> V_146 = V_41 -> V_142 -> V_147 + V_125 ;
V_41 -> V_148 = V_41 -> V_142 -> V_34 + V_125 ;
V_41 -> V_128 = args -> V_128 ;
V_41 -> V_149 = V_41 -> V_142 -> V_147 + V_127 ;
V_41 -> V_150 = V_41 -> V_142 -> V_34 + V_127 ;
V_41 -> V_130 = args -> V_130 ;
V_24 = F_67 ( V_2 ,
V_41 -> V_142 -> V_147 + V_124 ,
V_123 ,
V_41 ) ;
if ( V_24 )
goto V_117;
V_24 = F_68 ( V_2 , V_41 ) ;
V_117:
F_10 ( V_122 ) ;
return V_24 ;
}
static void
F_69 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned V_10 ;
F_7 ( & V_2 -> V_11 ) ;
if ( V_41 -> V_14 ) {
for ( V_10 = 0 ; V_10 < V_41 -> V_13 ; V_10 ++ )
F_8 ( & V_41 -> V_14 [ V_10 ] -> V_35 ) ;
F_10 ( V_41 -> V_14 ) ;
}
while ( ! F_70 ( & V_41 -> V_144 ) ) {
struct V_31 * V_14 = F_71 ( & V_41 -> V_144 ,
struct V_31 , V_143 ) ;
F_72 ( & V_14 -> V_143 ) ;
F_8 ( & V_14 -> V_35 . V_35 ) ;
}
F_9 ( & V_2 -> V_11 ) ;
F_7 ( & V_4 -> V_78 ) ;
if ( -- V_4 -> V_79 == 0 )
F_73 ( & V_4 -> V_80 -> V_81 -> V_2 ) ;
F_9 ( & V_4 -> V_78 ) ;
F_10 ( V_41 ) ;
}
void
F_74 ( struct V_3 * V_4 )
{
unsigned long V_23 ;
struct V_151 * V_152 , * V_153 ;
F_12 ( & V_4 -> V_25 , V_23 ) ;
while ( ! F_70 ( & V_4 -> V_154 ) ) {
struct V_40 * V_41 =
F_71 ( & V_4 -> V_154 ,
struct V_40 , V_110 ) ;
F_72 ( & V_41 -> V_110 ) ;
F_13 ( & V_4 -> V_25 , V_23 ) ;
F_69 ( V_4 -> V_2 , V_41 ) ;
F_12 ( & V_4 -> V_25 , V_23 ) ;
}
F_75 (cb, cb_temp, &vc4->seqno_cb_list, work.entry) {
if ( V_152 -> V_90 <= V_4 -> V_95 ) {
F_76 ( & V_152 -> V_83 . V_155 ) ;
F_34 ( & V_152 -> V_83 ) ;
}
}
F_13 ( & V_4 -> V_25 , V_23 ) ;
}
static void F_77 ( struct V_82 * V_83 )
{
struct V_151 * V_152 = F_32 ( V_83 , struct V_151 , V_83 ) ;
V_152 -> V_156 ( V_152 ) ;
}
int F_78 ( struct V_1 * V_2 ,
struct V_151 * V_152 , T_3 V_90 ,
void (* V_156)( struct V_151 * V_152 ) )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_24 = 0 ;
unsigned long V_23 ;
V_152 -> V_156 = V_156 ;
F_79 ( & V_152 -> V_83 , F_77 ) ;
F_12 ( & V_4 -> V_25 , V_23 ) ;
if ( V_90 > V_4 -> V_95 ) {
V_152 -> V_90 = V_90 ;
F_53 ( & V_152 -> V_83 . V_155 , & V_4 -> V_157 ) ;
} else {
F_34 ( & V_152 -> V_83 ) ;
}
F_13 ( & V_4 -> V_25 , V_23 ) ;
return V_24 ;
}
static void
F_80 ( struct V_82 * V_83 )
{
struct V_3 * V_4 =
F_32 ( V_83 , struct V_3 , V_158 ) ;
F_74 ( V_4 ) ;
}
static int
F_81 ( struct V_1 * V_2 ,
T_3 V_90 ,
T_3 * V_91 )
{
unsigned long V_88 = V_7 ;
int V_24 = F_37 ( V_2 , V_90 , * V_91 , true ) ;
if ( ( V_24 == - V_159 || V_24 == - V_101 ) && * V_91 != ~ 0ull ) {
T_3 V_160 = F_82 ( V_7 - V_88 ) ;
if ( * V_91 >= V_160 )
* V_91 -= V_160 ;
}
return V_24 ;
}
int
F_83 ( struct V_1 * V_2 , void * V_15 ,
struct V_16 * V_17 )
{
struct V_161 * args = V_15 ;
return F_81 ( V_2 , args -> V_90 ,
& args -> V_91 ) ;
}
int
F_84 ( struct V_1 * V_2 , void * V_15 ,
struct V_16 * V_17 )
{
int V_24 ;
struct V_162 * args = V_15 ;
struct V_120 * V_163 ;
struct V_31 * V_14 ;
if ( args -> V_164 != 0 )
return - V_115 ;
V_163 = F_85 ( V_2 , V_17 , args -> V_32 ) ;
if ( ! V_163 ) {
F_55 ( L_11 , args -> V_32 ) ;
return - V_115 ;
}
V_14 = F_15 ( V_163 ) ;
V_24 = F_81 ( V_2 , V_14 -> V_90 ,
& args -> V_91 ) ;
F_86 ( V_163 ) ;
return V_24 ;
}
int
F_87 ( struct V_1 * V_2 , void * V_15 ,
struct V_16 * V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_112 * args = V_15 ;
struct V_40 * V_41 ;
int V_24 = 0 ;
if ( ( args -> V_165 & ~ V_166 ) != 0 ) {
F_55 ( L_12 , args -> V_165 ) ;
return - V_115 ;
}
V_41 = F_14 ( 1 , sizeof( * V_41 ) , V_28 ) ;
if ( ! V_41 ) {
F_55 ( L_13 ) ;
return - V_29 ;
}
F_7 ( & V_4 -> V_78 ) ;
if ( V_4 -> V_79 ++ == 0 )
V_24 = F_29 ( & V_4 -> V_80 -> V_81 -> V_2 ) ;
F_9 ( & V_4 -> V_78 ) ;
if ( V_24 < 0 ) {
F_10 ( V_41 ) ;
return V_24 ;
}
V_41 -> args = args ;
F_88 ( & V_41 -> V_144 ) ;
V_24 = F_54 ( V_2 , V_17 , V_41 ) ;
if ( V_24 )
goto V_117;
if ( V_41 -> args -> V_126 != 0 ) {
V_24 = F_61 ( V_2 , V_41 ) ;
if ( V_24 )
goto V_117;
} else {
V_41 -> V_45 = 0 ;
V_41 -> V_48 = 0 ;
}
V_24 = F_89 ( V_2 , V_41 ) ;
if ( V_24 )
goto V_117;
V_41 -> args = NULL ;
F_52 ( V_2 , V_41 ) ;
args -> V_90 = V_4 -> V_109 ;
return 0 ;
V_117:
F_69 ( V_4 -> V_2 , V_41 ) ;
return V_24 ;
}
void
F_90 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_88 ( & V_4 -> V_111 ) ;
F_88 ( & V_4 -> V_154 ) ;
F_88 ( & V_4 -> V_157 ) ;
F_91 ( & V_4 -> V_25 ) ;
F_79 ( & V_4 -> V_5 . V_84 , F_31 ) ;
F_92 ( & V_4 -> V_5 . V_6 ,
F_33 ,
( unsigned long ) V_2 ) ;
F_79 ( & V_4 -> V_158 , F_80 ) ;
F_93 ( & V_4 -> V_78 ) ;
}
void
F_94 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_95 ( V_4 -> V_109 != V_4 -> V_95 ) ;
if ( V_4 -> V_167 ) {
F_86 ( & V_4 -> V_167 -> V_35 . V_35 ) ;
V_4 -> V_167 = NULL ;
}
F_96 ( V_2 ) ;
if ( V_4 -> V_26 )
F_6 ( V_2 , V_4 -> V_26 ) ;
}
