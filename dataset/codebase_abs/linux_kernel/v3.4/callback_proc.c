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
F_21 ( V_45 ) ;
return V_45 ;
}
}
return NULL ;
}
static struct V_39 * F_22 ( struct V_40 * V_13 , struct V_41 * V_19 )
{
struct V_39 * V_45 ;
F_23 ( & V_13 -> V_47 ) ;
F_7 () ;
V_45 = F_16 ( V_13 , V_19 ) ;
F_10 () ;
F_24 ( & V_13 -> V_47 ) ;
return V_45 ;
}
static T_2 F_25 ( struct V_40 * V_13 ,
struct V_48 * args )
{
struct V_10 * V_44 ;
struct V_39 * V_45 ;
T_2 V_49 = V_50 ;
F_26 ( V_51 ) ;
V_45 = F_22 ( V_13 , & args -> V_52 ) ;
if ( ! V_45 )
return V_50 ;
V_44 = V_45 -> V_46 ;
F_23 ( & V_44 -> V_53 ) ;
if ( F_27 ( V_54 , & V_45 -> V_55 ) ||
F_28 ( V_45 , & V_51 ,
& args -> V_56 ) )
V_49 = V_57 ;
else
V_49 = V_50 ;
F_29 ( V_45 , & args -> V_58 , true ) ;
F_24 ( & V_44 -> V_53 ) ;
F_30 ( & V_51 ) ;
F_31 ( V_45 ) ;
F_11 ( V_44 ) ;
return V_49 ;
}
static T_2 F_32 ( struct V_40 * V_13 ,
struct V_48 * args )
{
struct V_42 * V_43 ;
struct V_39 * V_45 ;
struct V_10 * V_44 ;
T_2 V_49 = V_50 ;
struct V_39 * V_59 ;
F_26 ( V_60 ) ;
F_26 ( V_51 ) ;
struct V_61 V_62 = {
. V_63 = V_64 ,
. V_65 = 0 ,
. V_66 = V_67 ,
} ;
F_23 ( & V_13 -> V_47 ) ;
F_7 () ;
F_17 (server, &clp->cl_superblocks, client_link) {
if ( ( args -> V_68 == V_69 ) &&
memcmp ( & V_43 -> V_70 , & args -> V_71 ,
sizeof( struct V_72 ) ) )
continue;
F_18 (lo, &server->layouts, plh_layouts) {
if ( ! F_20 ( V_45 -> V_46 ) )
continue;
F_21 ( V_45 ) ;
F_33 ( ! F_34 ( & V_45 -> V_73 ) ) ;
F_35 ( & V_45 -> V_73 , & V_60 ) ;
}
}
F_10 () ;
F_24 ( & V_13 -> V_47 ) ;
F_36 (lo, tmp,
&recall_list, plh_bulk_recall) {
V_44 = V_45 -> V_46 ;
F_23 ( & V_44 -> V_53 ) ;
F_37 ( V_54 , & V_45 -> V_55 ) ;
if ( F_28 ( V_45 , & V_51 , & V_62 ) )
V_49 = V_57 ;
F_38 ( & V_45 -> V_73 ) ;
F_24 ( & V_44 -> V_53 ) ;
F_30 ( & V_51 ) ;
F_31 ( V_45 ) ;
F_11 ( V_44 ) ;
}
return V_49 ;
}
static T_2 F_39 ( struct V_40 * V_13 ,
struct V_48 * args )
{
T_2 V_3 ;
F_12 ( L_4 , V_32 , args -> V_68 ) ;
if ( args -> V_68 == V_74 )
V_3 = F_25 ( V_13 , args ) ;
else
V_3 = F_32 ( V_13 , args ) ;
F_12 ( L_5 , V_32 , V_3 ) ;
return V_3 ;
}
T_1 F_40 ( struct V_48 * args ,
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
struct V_48 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_68 = V_75 ;
F_39 ( V_13 , & args ) ;
}
T_1 F_43 ( struct V_76 * args ,
void * V_34 , struct V_4 * V_5 )
{
int V_77 ;
T_1 V_3 = 0 ;
struct V_40 * V_13 = V_5 -> V_13 ;
struct V_42 * V_43 = NULL ;
F_12 ( L_6 , V_32 ) ;
if ( ! V_13 ) {
V_3 = F_41 ( V_12 ) ;
goto V_14;
}
for ( V_77 = 0 ; V_77 < args -> V_78 ; V_77 ++ ) {
struct V_79 * V_80 = & args -> V_81 [ V_77 ] ;
if ( ! V_43 ||
V_43 -> V_82 -> V_83 != V_80 -> V_84 ) {
F_7 () ;
F_17 (server, &clp->cl_superblocks, client_link)
if ( V_43 -> V_82 &&
V_43 -> V_82 -> V_83 == V_80 -> V_84 ) {
F_10 () ;
goto V_85;
}
F_10 () ;
F_12 ( L_7 ,
V_32 , V_80 -> V_84 ) ;
continue;
}
V_85:
if ( V_80 -> V_86 == V_87 )
F_12 ( L_8
L_9 , V_32 ) ;
F_44 ( V_43 -> V_82 , V_13 , & V_80 -> V_88 ) ;
}
V_14:
F_45 ( args -> V_81 ) ;
F_12 ( L_10 ,
V_32 , F_46 ( V_3 ) ) ;
return V_3 ;
}
static T_1
F_47 ( struct V_89 * V_90 , struct V_91 * args )
{
struct V_92 * V_93 ;
F_12 ( L_11 ,
V_32 , args -> V_94 , args -> V_95 ) ;
if ( args -> V_94 >= V_96 )
return F_2 ( V_97 ) ;
V_93 = V_90 -> V_98 + args -> V_94 ;
F_12 ( L_12 , V_32 , V_93 -> V_99 ) ;
if ( F_48 ( args -> V_95 == V_93 -> V_99 + 1 ) ) {
V_93 -> V_99 ++ ;
goto V_100;
}
if ( args -> V_95 == V_93 -> V_99 ) {
F_12 ( L_13 ,
V_32 , args -> V_95 ) ;
if ( args -> V_101 == 0 )
return F_2 ( V_102 ) ;
else if ( args -> V_101 == 1 )
return F_2 ( V_103 ) ;
}
if ( args -> V_95 == 1 && ( V_93 -> V_99 + 1 ) == 0 ) {
V_93 -> V_99 = 1 ;
goto V_100;
}
return F_2 ( V_104 ) ;
V_100:
V_90 -> V_105 = args -> V_94 ;
return F_2 ( V_106 ) ;
}
static bool F_49 ( struct V_40 * V_13 ,
T_3 V_107 ,
struct V_108 * V_109 )
{
bool V_11 = 0 ;
int V_77 , V_110 ;
struct V_111 * V_112 ;
struct V_89 * V_90 ;
struct V_108 * V_113 ;
struct V_114 * V_115 ;
V_112 = V_13 -> V_116 ;
V_90 = & V_112 -> V_117 ;
for ( V_77 = 0 ; V_77 < V_107 ; V_77 ++ ) {
V_113 = & V_109 [ V_77 ] ;
if ( memcmp ( V_112 -> V_118 . V_119 ,
V_113 -> V_120 . V_119 ,
V_121 ) != 0 )
continue;
for ( V_110 = 0 ; V_110 < V_113 -> V_122 ; V_110 ++ ) {
V_115 = & V_113 -> V_123 [ V_110 ] ;
F_12 ( L_14
L_15 , V_32 ,
( ( T_2 * ) & V_113 -> V_120 . V_119 ) [ 0 ] ,
( ( T_2 * ) & V_113 -> V_120 . V_119 ) [ 1 ] ,
( ( T_2 * ) & V_113 -> V_120 . V_119 ) [ 2 ] ,
( ( T_2 * ) & V_113 -> V_120 . V_119 ) [ 3 ] ,
V_115 -> V_124 , V_115 -> V_125 ) ;
F_23 ( & V_90 -> V_126 ) ;
V_11 = ( F_27 ( V_115 -> V_125 , V_90 -> V_127 ) &&
V_90 -> V_98 [ V_115 -> V_125 ] . V_99 ==
V_115 -> V_124 ) ;
F_24 ( & V_90 -> V_126 ) ;
if ( V_11 )
goto V_14;
}
}
V_14:
return V_11 ;
}
T_1 F_50 ( struct V_91 * args ,
struct V_128 * V_3 ,
struct V_4 * V_5 )
{
struct V_89 * V_90 ;
struct V_40 * V_13 ;
int V_77 ;
T_1 V_11 = F_2 ( V_129 ) ;
V_13 = F_51 ( V_5 -> V_130 , args -> V_131 , & args -> V_132 ) ;
if ( V_13 == NULL )
goto V_14;
V_90 = & V_13 -> V_116 -> V_133 ;
F_23 ( & V_90 -> V_126 ) ;
if ( F_27 ( V_134 , & V_13 -> V_116 -> V_135 ) ) {
F_24 ( & V_90 -> V_126 ) ;
V_11 = F_2 ( V_57 ) ;
if ( F_27 ( V_136 , & V_13 -> V_137 ) )
V_11 = F_2 ( V_129 ) ;
goto V_14;
}
V_11 = F_47 ( & V_13 -> V_116 -> V_133 , args ) ;
F_24 ( & V_90 -> V_126 ) ;
if ( V_11 )
goto V_14;
V_5 -> V_138 = args -> V_94 ;
if ( F_49 ( V_13 , args -> V_139 , args -> V_140 ) ) {
V_11 = F_2 ( V_57 ) ;
goto V_14;
}
memcpy ( & V_3 -> V_141 , & args -> V_132 ,
sizeof( V_3 -> V_141 ) ) ;
V_3 -> V_142 = args -> V_95 ;
V_3 -> V_143 = args -> V_94 ;
V_3 -> V_144 = V_96 - 1 ;
V_3 -> V_145 = V_96 - 1 ;
V_14:
V_5 -> V_13 = V_13 ;
for ( V_77 = 0 ; V_77 < args -> V_139 ; V_77 ++ )
F_45 ( args -> V_140 [ V_77 ] . V_123 ) ;
F_45 ( args -> V_140 ) ;
if ( V_11 == F_2 ( V_102 ) ) {
V_5 -> V_146 = V_11 ;
V_11 = 0 ;
} else
V_3 -> V_147 = V_11 ;
F_12 ( L_16 , V_32 ,
F_13 ( V_11 ) , F_13 ( V_3 -> V_147 ) ) ;
return V_11 ;
}
static bool
F_52 ( unsigned long V_148 )
{
return ( V_148 & ~ V_149 ) == 0 ;
}
T_1 F_53 ( struct V_150 * args , void * V_34 ,
struct V_4 * V_5 )
{
T_1 V_11 ;
T_4 V_151 = 0 ;
V_11 = F_41 ( V_12 ) ;
if ( ! V_5 -> V_13 )
goto V_14;
F_3 ( L_17 ,
F_4 ( V_5 -> V_13 -> V_17 , V_18 ) ) ;
V_11 = F_41 ( V_152 ) ;
if ( ! F_52 ( args -> V_153 ) )
goto V_14;
V_11 = F_41 ( V_106 ) ;
if ( F_27 ( V_154 , ( const unsigned long * )
& args -> V_153 ) )
V_151 = V_155 ;
if ( F_27 ( V_156 , ( const unsigned long * )
& args -> V_153 ) )
V_151 |= V_20 ;
if ( F_27 ( V_157 , ( const unsigned long * )
& args -> V_153 ) )
F_42 ( V_5 -> V_13 ) ;
if ( V_151 )
F_54 ( V_5 -> V_13 , V_151 ) ;
V_14:
F_12 ( L_2 , V_32 , F_13 ( V_11 ) ) ;
return V_11 ;
}
T_1 F_55 ( struct V_158 * args , void * V_34 ,
struct V_4 * V_5 )
{
struct V_89 * V_159 ;
T_1 V_11 ;
V_11 = F_2 ( V_12 ) ;
if ( ! V_5 -> V_13 )
goto V_14;
F_3 ( L_18 ,
F_4 ( V_5 -> V_13 -> V_17 , V_18 ) ,
args -> V_160 ) ;
V_159 = & V_5 -> V_13 -> V_116 -> V_117 ;
V_11 = F_2 ( V_161 ) ;
if ( args -> V_160 > V_159 -> V_162 ||
args -> V_160 < 1 )
goto V_14;
V_11 = F_2 ( V_106 ) ;
if ( args -> V_160 == V_159 -> V_162 )
goto V_14;
V_159 -> V_163 = args -> V_160 ;
F_56 ( V_5 -> V_13 ) ;
V_14:
F_12 ( L_2 , V_32 , F_13 ( V_11 ) ) ;
return V_11 ;
}
