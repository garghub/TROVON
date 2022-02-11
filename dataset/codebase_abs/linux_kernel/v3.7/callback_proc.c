T_1 F_1 ( struct V_1 * args ,
struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_10 ;
V_3 -> V_11 = F_2 ( V_12 ) ;
if ( ! V_5 -> V_13 )
goto V_14;
V_3 -> V_15 [ 0 ] = V_3 -> V_15 [ 1 ] = 0 ;
V_3 -> V_11 = F_2 ( V_16 ) ;
F_3 ( L_1 ,
F_4 ( V_5 -> V_13 -> V_17 , V_18 ) ) ;
V_10 = F_5 ( V_5 -> V_13 , & args -> V_19 ) ;
if ( V_10 == NULL )
goto V_14;
V_9 = F_6 ( V_10 ) ;
F_7 () ;
V_7 = F_8 ( V_9 -> V_7 ) ;
if ( V_7 == NULL || ( V_7 -> type & V_20 ) == 0 )
goto V_21;
V_3 -> V_22 = F_9 ( V_10 ) ;
V_3 -> V_23 = V_7 -> V_23 ;
if ( V_9 -> V_24 != 0 )
V_3 -> V_23 ++ ;
V_3 -> ctime = V_10 -> V_25 ;
V_3 -> V_26 = V_10 -> V_27 ;
V_3 -> V_15 [ 0 ] = ( V_28 | V_29 ) &
args -> V_15 [ 0 ] ;
V_3 -> V_15 [ 1 ] = ( V_30 | V_31 ) &
args -> V_15 [ 1 ] ;
V_3 -> V_11 = 0 ;
V_21:
F_10 () ;
F_11 ( V_10 ) ;
V_14:
F_12 ( L_2 , V_32 , F_13 ( V_3 -> V_11 ) ) ;
return V_3 -> V_11 ;
}
T_1 F_14 ( struct V_33 * args , void * V_34 ,
struct V_4 * V_5 )
{
struct V_10 * V_10 ;
T_1 V_3 ;
V_3 = F_2 ( V_12 ) ;
if ( ! V_5 -> V_13 )
goto V_14;
F_3 ( L_3 ,
F_4 ( V_5 -> V_13 -> V_17 , V_18 ) ) ;
V_3 = F_2 ( V_16 ) ;
V_10 = F_5 ( V_5 -> V_13 , & args -> V_19 ) ;
if ( V_10 == NULL )
goto V_14;
switch ( F_15 ( V_10 , & args -> V_35 ) ) {
case 0 :
V_3 = 0 ;
break;
case - V_36 :
V_3 = F_2 ( V_37 ) ;
break;
default:
V_3 = F_2 ( V_38 ) ;
}
F_11 ( V_10 ) ;
V_14:
F_12 ( L_2 , V_32 , F_13 ( V_3 ) ) ;
return V_3 ;
}
static struct V_39 * F_16 ( struct V_40 * V_13 , struct V_41 * V_19 )
{
struct V_42 * V_43 ;
struct V_10 * V_44 ;
struct V_39 * V_45 ;
F_17 (server, &clp->cl_superblocks, client_link) {
F_18 (lo, &server->layouts, plh_layouts) {
if ( F_19 ( V_19 , & F_6 ( V_45 -> V_46 ) -> V_19 ) )
continue;
V_44 = F_20 ( V_45 -> V_46 ) ;
if ( ! V_44 )
continue;
F_21 ( & V_44 -> V_47 ) ;
if ( F_6 ( V_44 ) -> V_48 != V_45 ) {
F_22 ( & V_44 -> V_47 ) ;
F_11 ( V_44 ) ;
continue;
}
F_23 ( V_45 ) ;
F_22 ( & V_44 -> V_47 ) ;
return V_45 ;
}
}
return NULL ;
}
static struct V_39 * F_24 ( struct V_40 * V_13 , struct V_41 * V_19 )
{
struct V_39 * V_45 ;
F_21 ( & V_13 -> V_49 ) ;
F_7 () ;
V_45 = F_16 ( V_13 , V_19 ) ;
F_10 () ;
F_22 ( & V_13 -> V_49 ) ;
return V_45 ;
}
static T_2 F_25 ( struct V_40 * V_13 ,
struct V_50 * args )
{
struct V_10 * V_44 ;
struct V_39 * V_45 ;
T_2 V_51 = V_52 ;
F_26 ( V_53 ) ;
V_45 = F_24 ( V_13 , & args -> V_54 ) ;
if ( ! V_45 )
return V_52 ;
V_44 = V_45 -> V_46 ;
F_21 ( & V_44 -> V_47 ) ;
if ( F_27 ( V_55 , & V_45 -> V_56 ) ||
F_28 ( V_45 , & V_53 ,
& args -> V_57 ) )
V_51 = V_58 ;
else
V_51 = V_52 ;
F_29 ( V_45 , & args -> V_59 , true ) ;
F_22 ( & V_44 -> V_47 ) ;
F_30 ( & V_53 ) ;
F_31 ( V_45 ) ;
F_11 ( V_44 ) ;
return V_51 ;
}
static T_2 F_32 ( struct V_40 * V_13 ,
struct V_50 * args )
{
struct V_42 * V_43 ;
struct V_39 * V_45 ;
struct V_10 * V_44 ;
T_2 V_51 = V_52 ;
struct V_39 * V_60 ;
F_26 ( V_61 ) ;
F_26 ( V_53 ) ;
struct V_62 V_63 = {
. V_64 = V_65 ,
. V_66 = 0 ,
. V_67 = V_68 ,
} ;
F_21 ( & V_13 -> V_49 ) ;
F_7 () ;
F_17 (server, &clp->cl_superblocks, client_link) {
if ( ( args -> V_69 == V_70 ) &&
memcmp ( & V_43 -> V_71 , & args -> V_72 ,
sizeof( struct V_73 ) ) )
continue;
F_18 (lo, &server->layouts, plh_layouts) {
V_44 = F_20 ( V_45 -> V_46 ) ;
if ( V_44 )
continue;
F_21 ( & V_44 -> V_47 ) ;
if ( F_6 ( V_44 ) -> V_48 != V_45 ) {
F_22 ( & V_44 -> V_47 ) ;
F_11 ( V_44 ) ;
continue;
}
F_23 ( V_45 ) ;
F_22 ( & V_44 -> V_47 ) ;
F_33 ( ! F_34 ( & V_45 -> V_74 ) ) ;
F_35 ( & V_45 -> V_74 , & V_61 ) ;
}
}
F_10 () ;
F_22 ( & V_13 -> V_49 ) ;
F_36 (lo, tmp,
&recall_list, plh_bulk_recall) {
V_44 = V_45 -> V_46 ;
F_21 ( & V_44 -> V_47 ) ;
F_37 ( V_55 , & V_45 -> V_56 ) ;
if ( F_28 ( V_45 , & V_53 , & V_63 ) )
V_51 = V_58 ;
F_38 ( & V_45 -> V_74 ) ;
F_22 ( & V_44 -> V_47 ) ;
F_30 ( & V_53 ) ;
F_31 ( V_45 ) ;
F_11 ( V_44 ) ;
}
return V_51 ;
}
static T_2 F_39 ( struct V_40 * V_13 ,
struct V_50 * args )
{
T_2 V_3 ;
F_12 ( L_4 , V_32 , args -> V_69 ) ;
if ( args -> V_69 == V_75 )
V_3 = F_25 ( V_13 , args ) ;
else
V_3 = F_32 ( V_13 , args ) ;
F_12 ( L_5 , V_32 , V_3 ) ;
return V_3 ;
}
T_1 F_40 ( struct V_50 * args ,
void * V_34 , struct V_4 * V_5 )
{
T_2 V_3 ;
F_12 ( L_6 , V_32 ) ;
if ( V_5 -> V_13 )
V_3 = F_39 ( V_5 -> V_13 , args ) ;
else
V_3 = V_12 ;
F_12 ( L_2 , V_32 , V_3 ) ;
return F_41 ( V_3 ) ;
}
static void F_42 ( struct V_40 * V_13 )
{
struct V_50 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_69 = V_76 ;
F_39 ( V_13 , & args ) ;
}
T_1 F_43 ( struct V_77 * args ,
void * V_34 , struct V_4 * V_5 )
{
int V_78 ;
T_1 V_3 = 0 ;
struct V_40 * V_13 = V_5 -> V_13 ;
struct V_42 * V_43 = NULL ;
F_12 ( L_6 , V_32 ) ;
if ( ! V_13 ) {
V_3 = F_41 ( V_12 ) ;
goto V_14;
}
for ( V_78 = 0 ; V_78 < args -> V_79 ; V_78 ++ ) {
struct V_80 * V_81 = & args -> V_82 [ V_78 ] ;
if ( ! V_43 ||
V_43 -> V_83 -> V_84 != V_81 -> V_85 ) {
F_7 () ;
F_17 (server, &clp->cl_superblocks, client_link)
if ( V_43 -> V_83 &&
V_43 -> V_83 -> V_84 == V_81 -> V_85 ) {
F_10 () ;
goto V_86;
}
F_10 () ;
F_12 ( L_7 ,
V_32 , V_81 -> V_85 ) ;
continue;
}
V_86:
if ( V_81 -> V_87 == V_88 )
F_12 ( L_8
L_9 , V_32 ) ;
F_44 ( V_43 -> V_83 , V_13 , & V_81 -> V_89 ) ;
}
V_14:
F_45 ( args -> V_82 ) ;
F_12 ( L_10 ,
V_32 , F_46 ( V_3 ) ) ;
return V_3 ;
}
static T_1
F_47 ( struct V_90 * V_91 , struct V_92 * args )
{
struct V_93 * V_94 ;
F_12 ( L_11 ,
V_32 , args -> V_95 , args -> V_96 ) ;
if ( args -> V_95 >= V_97 )
return F_2 ( V_98 ) ;
V_94 = V_91 -> V_99 + args -> V_95 ;
F_12 ( L_12 , V_32 , V_94 -> V_100 ) ;
if ( F_48 ( args -> V_96 == V_94 -> V_100 + 1 ) ) {
V_94 -> V_100 ++ ;
goto V_101;
}
if ( args -> V_96 == V_94 -> V_100 ) {
F_12 ( L_13 ,
V_32 , args -> V_96 ) ;
if ( args -> V_102 == 0 )
return F_2 ( V_103 ) ;
else if ( args -> V_102 == 1 )
return F_2 ( V_104 ) ;
}
if ( args -> V_96 == 1 && ( V_94 -> V_100 + 1 ) == 0 ) {
V_94 -> V_100 = 1 ;
goto V_101;
}
return F_2 ( V_105 ) ;
V_101:
V_91 -> V_106 = args -> V_95 ;
return F_2 ( V_107 ) ;
}
static bool F_49 ( struct V_40 * V_13 ,
T_3 V_108 ,
struct V_109 * V_110 )
{
bool V_11 = 0 ;
int V_78 , V_111 ;
struct V_112 * V_113 ;
struct V_90 * V_91 ;
struct V_109 * V_114 ;
struct V_115 * V_116 ;
V_113 = V_13 -> V_117 ;
V_91 = & V_113 -> V_118 ;
for ( V_78 = 0 ; V_78 < V_108 ; V_78 ++ ) {
V_114 = & V_110 [ V_78 ] ;
if ( memcmp ( V_113 -> V_119 . V_120 ,
V_114 -> V_121 . V_120 ,
V_122 ) != 0 )
continue;
for ( V_111 = 0 ; V_111 < V_114 -> V_123 ; V_111 ++ ) {
V_116 = & V_114 -> V_124 [ V_111 ] ;
F_12 ( L_14
L_15 , V_32 ,
( ( T_2 * ) & V_114 -> V_121 . V_120 ) [ 0 ] ,
( ( T_2 * ) & V_114 -> V_121 . V_120 ) [ 1 ] ,
( ( T_2 * ) & V_114 -> V_121 . V_120 ) [ 2 ] ,
( ( T_2 * ) & V_114 -> V_121 . V_120 ) [ 3 ] ,
V_116 -> V_125 , V_116 -> V_126 ) ;
F_21 ( & V_91 -> V_127 ) ;
V_11 = ( F_27 ( V_116 -> V_126 , V_91 -> V_128 ) &&
V_91 -> V_99 [ V_116 -> V_126 ] . V_100 ==
V_116 -> V_125 ) ;
F_22 ( & V_91 -> V_127 ) ;
if ( V_11 )
goto V_14;
}
}
V_14:
return V_11 ;
}
T_1 F_50 ( struct V_92 * args ,
struct V_129 * V_3 ,
struct V_4 * V_5 )
{
struct V_90 * V_91 ;
struct V_40 * V_13 ;
int V_78 ;
T_1 V_11 = F_2 ( V_130 ) ;
V_13 = F_51 ( V_5 -> V_131 , args -> V_132 , & args -> V_133 ) ;
if ( V_13 == NULL )
goto V_14;
V_91 = & V_13 -> V_117 -> V_134 ;
F_21 ( & V_91 -> V_127 ) ;
if ( F_27 ( V_135 , & V_13 -> V_117 -> V_136 ) ) {
F_22 ( & V_91 -> V_127 ) ;
V_11 = F_2 ( V_58 ) ;
if ( F_27 ( V_137 , & V_13 -> V_138 ) )
V_11 = F_2 ( V_130 ) ;
goto V_14;
}
V_11 = F_47 ( & V_13 -> V_117 -> V_134 , args ) ;
F_22 ( & V_91 -> V_127 ) ;
if ( V_11 )
goto V_14;
V_5 -> V_139 = args -> V_95 ;
if ( F_49 ( V_13 , args -> V_140 , args -> V_141 ) ) {
V_11 = F_2 ( V_58 ) ;
goto V_14;
}
memcpy ( & V_3 -> V_142 , & args -> V_133 ,
sizeof( V_3 -> V_142 ) ) ;
V_3 -> V_143 = args -> V_96 ;
V_3 -> V_144 = args -> V_95 ;
V_3 -> V_145 = V_97 - 1 ;
V_3 -> V_146 = V_97 - 1 ;
V_14:
V_5 -> V_13 = V_13 ;
for ( V_78 = 0 ; V_78 < args -> V_140 ; V_78 ++ )
F_45 ( args -> V_141 [ V_78 ] . V_124 ) ;
F_45 ( args -> V_141 ) ;
if ( V_11 == F_2 ( V_103 ) ) {
V_5 -> V_147 = V_11 ;
V_11 = 0 ;
} else
V_3 -> V_148 = V_11 ;
F_12 ( L_16 , V_32 ,
F_13 ( V_11 ) , F_13 ( V_3 -> V_148 ) ) ;
return V_11 ;
}
static bool
F_52 ( unsigned long V_149 )
{
return ( V_149 & ~ V_150 ) == 0 ;
}
T_1 F_53 ( struct V_151 * args , void * V_34 ,
struct V_4 * V_5 )
{
T_1 V_11 ;
T_4 V_152 = 0 ;
V_11 = F_41 ( V_12 ) ;
if ( ! V_5 -> V_13 )
goto V_14;
F_3 ( L_17 ,
F_4 ( V_5 -> V_13 -> V_17 , V_18 ) ) ;
V_11 = F_41 ( V_153 ) ;
if ( ! F_52 ( args -> V_154 ) )
goto V_14;
V_11 = F_41 ( V_107 ) ;
if ( F_27 ( V_155 , ( const unsigned long * )
& args -> V_154 ) )
V_152 = V_156 ;
if ( F_27 ( V_157 , ( const unsigned long * )
& args -> V_154 ) )
V_152 |= V_20 ;
if ( F_27 ( V_158 , ( const unsigned long * )
& args -> V_154 ) )
F_42 ( V_5 -> V_13 ) ;
if ( V_152 )
F_54 ( V_5 -> V_13 , V_152 ) ;
V_14:
F_12 ( L_2 , V_32 , F_13 ( V_11 ) ) ;
return V_11 ;
}
T_1 F_55 ( struct V_159 * args , void * V_34 ,
struct V_4 * V_5 )
{
struct V_90 * V_160 ;
T_1 V_11 ;
V_11 = F_2 ( V_12 ) ;
if ( ! V_5 -> V_13 )
goto V_14;
F_3 ( L_18 ,
F_4 ( V_5 -> V_13 -> V_17 , V_18 ) ,
args -> V_161 ) ;
V_160 = & V_5 -> V_13 -> V_117 -> V_118 ;
V_11 = F_2 ( V_162 ) ;
if ( args -> V_161 > V_160 -> V_163 ||
args -> V_161 < 1 )
goto V_14;
V_11 = F_2 ( V_107 ) ;
if ( args -> V_161 == V_160 -> V_163 )
goto V_14;
V_160 -> V_164 = args -> V_161 ;
F_56 ( V_5 -> V_13 ) ;
V_14:
F_12 ( L_2 , V_32 , F_13 ( V_11 ) ) ;
return V_11 ;
}
