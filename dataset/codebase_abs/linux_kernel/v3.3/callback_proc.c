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
F_3 ( L_2 , V_32 , F_12 ( V_3 -> V_11 ) ) ;
return V_3 -> V_11 ;
}
T_1 F_13 ( struct V_33 * args , void * V_34 ,
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
switch ( F_14 ( V_10 , & args -> V_35 ) ) {
case 0 :
V_3 = 0 ;
break;
case - V_36 :
if ( V_3 != 0 )
V_3 = F_2 ( V_37 ) ;
break;
default:
V_3 = F_2 ( V_38 ) ;
}
F_11 ( V_10 ) ;
V_14:
F_3 ( L_2 , V_32 , F_12 ( V_3 ) ) ;
return V_3 ;
}
int F_15 ( struct V_6 * V_7 , const T_2 * V_35 )
{
if ( V_7 == NULL || memcmp ( V_7 -> V_35 . V_39 , V_35 -> V_39 ,
sizeof( V_7 -> V_35 . V_39 ) ) != 0 )
return 0 ;
return 1 ;
}
static T_3 F_16 ( struct V_40 * V_13 ,
struct V_41 * args )
{
struct V_42 * V_43 ;
struct V_44 * V_45 ;
struct V_10 * V_46 ;
bool V_47 = false ;
T_3 V_48 = V_49 ;
F_17 ( V_50 ) ;
F_18 ( & V_13 -> V_51 ) ;
F_7 () ;
F_19 (server, &clp->cl_superblocks, client_link) {
F_20 (lo, &server->layouts, plh_layouts) {
if ( F_21 ( & args -> V_52 ,
& F_6 ( V_45 -> V_53 ) -> V_19 ) )
continue;
V_46 = F_22 ( V_45 -> V_53 ) ;
if ( ! V_46 )
continue;
V_47 = true ;
F_23 ( V_45 ) ;
break;
}
if ( V_47 )
break;
}
F_10 () ;
F_24 ( & V_13 -> V_51 ) ;
if ( ! V_47 )
return V_49 ;
F_18 ( & V_46 -> V_54 ) ;
if ( F_25 ( V_55 , & V_45 -> V_56 ) ||
F_26 ( V_45 , & V_50 ,
& args -> V_57 ) )
V_48 = V_58 ;
else
V_48 = V_49 ;
F_27 ( V_45 , & args -> V_59 , true ) ;
F_24 ( & V_46 -> V_54 ) ;
F_28 ( & V_50 ) ;
F_29 ( V_45 ) ;
F_11 ( V_46 ) ;
return V_48 ;
}
static T_3 F_30 ( struct V_40 * V_13 ,
struct V_41 * args )
{
struct V_42 * V_43 ;
struct V_44 * V_45 ;
struct V_10 * V_46 ;
T_3 V_48 = V_49 ;
struct V_44 * V_60 ;
F_17 ( V_61 ) ;
F_17 ( V_50 ) ;
struct V_62 V_63 = {
. V_64 = V_65 ,
. V_66 = 0 ,
. V_67 = V_68 ,
} ;
F_18 ( & V_13 -> V_51 ) ;
F_7 () ;
F_19 (server, &clp->cl_superblocks, client_link) {
if ( ( args -> V_69 == V_70 ) &&
memcmp ( & V_43 -> V_71 , & args -> V_72 ,
sizeof( struct V_73 ) ) )
continue;
F_20 (lo, &server->layouts, plh_layouts) {
if ( ! F_22 ( V_45 -> V_53 ) )
continue;
F_23 ( V_45 ) ;
F_31 ( ! F_32 ( & V_45 -> V_74 ) ) ;
F_33 ( & V_45 -> V_74 , & V_61 ) ;
}
}
F_10 () ;
F_24 ( & V_13 -> V_51 ) ;
F_34 (lo, tmp,
&recall_list, plh_bulk_recall) {
V_46 = V_45 -> V_53 ;
F_18 ( & V_46 -> V_54 ) ;
F_35 ( V_55 , & V_45 -> V_56 ) ;
if ( F_26 ( V_45 , & V_50 , & V_63 ) )
V_48 = V_58 ;
F_36 ( & V_45 -> V_74 ) ;
F_24 ( & V_46 -> V_54 ) ;
F_28 ( & V_50 ) ;
F_29 ( V_45 ) ;
F_11 ( V_46 ) ;
}
return V_48 ;
}
static T_3 F_37 ( struct V_40 * V_13 ,
struct V_41 * args )
{
T_3 V_3 = V_58 ;
F_3 ( L_4 , V_32 , args -> V_69 ) ;
if ( F_38 ( V_75 , & V_13 -> V_76 ) )
goto V_14;
if ( args -> V_69 == V_77 )
V_3 = F_16 ( V_13 , args ) ;
else
V_3 = F_30 ( V_13 , args ) ;
F_39 ( V_75 , & V_13 -> V_76 ) ;
V_14:
F_3 ( L_5 , V_32 , V_3 ) ;
return V_3 ;
}
T_1 F_40 ( struct V_41 * args ,
void * V_34 , struct V_4 * V_5 )
{
T_3 V_3 ;
F_3 ( L_6 , V_32 ) ;
if ( V_5 -> V_13 )
V_3 = F_37 ( V_5 -> V_13 , args ) ;
else
V_3 = V_12 ;
F_3 ( L_2 , V_32 , V_3 ) ;
return F_41 ( V_3 ) ;
}
static void F_42 ( struct V_40 * V_13 )
{
struct V_41 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_69 = V_78 ;
F_37 ( V_13 , & args ) ;
}
T_1 F_43 ( struct V_79 * args ,
void * V_34 , struct V_4 * V_5 )
{
int V_80 ;
T_1 V_3 = 0 ;
struct V_40 * V_13 = V_5 -> V_13 ;
struct V_42 * V_43 = NULL ;
F_3 ( L_6 , V_32 ) ;
if ( ! V_13 ) {
V_3 = F_41 ( V_12 ) ;
goto V_14;
}
for ( V_80 = 0 ; V_80 < args -> V_81 ; V_80 ++ ) {
struct V_82 * V_83 = & args -> V_84 [ V_80 ] ;
if ( ! V_43 ||
V_43 -> V_85 -> V_86 != V_83 -> V_87 ) {
F_7 () ;
F_19 (server, &clp->cl_superblocks, client_link)
if ( V_43 -> V_85 &&
V_43 -> V_85 -> V_86 == V_83 -> V_87 ) {
F_10 () ;
goto V_47;
}
F_10 () ;
F_3 ( L_7 ,
V_32 , V_83 -> V_87 ) ;
continue;
}
V_47:
if ( V_83 -> V_88 == V_89 )
F_3 ( L_8
L_9 , V_32 ) ;
F_44 ( V_43 -> V_85 , V_13 , & V_83 -> V_90 ) ;
}
V_14:
F_45 ( args -> V_84 ) ;
F_3 ( L_10 ,
V_32 , F_46 ( V_3 ) ) ;
return V_3 ;
}
int F_47 ( struct V_6 * V_7 , const T_2 * V_35 )
{
if ( V_7 == NULL )
return 0 ;
if ( V_35 -> V_35 . V_91 != 0 )
return 0 ;
if ( memcmp ( & V_7 -> V_35 . V_35 . V_92 ,
& V_35 -> V_35 . V_92 ,
V_93 ) )
return 0 ;
return 1 ;
}
static T_1
F_48 ( struct V_94 * V_95 , struct V_96 * args )
{
struct V_97 * V_98 ;
F_3 ( L_11 ,
V_32 , args -> V_99 , args -> V_100 ) ;
if ( args -> V_99 >= V_101 )
return F_2 ( V_102 ) ;
V_98 = V_95 -> V_103 + args -> V_99 ;
F_3 ( L_12 , V_32 , V_98 -> V_104 ) ;
if ( F_49 ( args -> V_100 == V_98 -> V_104 + 1 ) ) {
V_98 -> V_104 ++ ;
goto V_105;
}
if ( args -> V_100 == V_98 -> V_104 ) {
F_3 ( L_13 ,
V_32 , args -> V_100 ) ;
if ( args -> V_106 == 0 )
return F_2 ( V_107 ) ;
else if ( args -> V_106 == 1 )
return F_2 ( V_108 ) ;
}
if ( args -> V_100 == 1 && ( V_98 -> V_104 + 1 ) == 0 ) {
V_98 -> V_104 = 1 ;
goto V_105;
}
return F_2 ( V_109 ) ;
V_105:
V_95 -> V_110 = args -> V_99 ;
return F_2 ( V_111 ) ;
}
static bool F_50 ( struct V_40 * V_13 ,
T_4 V_112 ,
struct V_113 * V_114 )
{
bool V_11 = 0 ;
int V_80 , V_115 ;
struct V_116 * V_117 ;
struct V_94 * V_95 ;
struct V_113 * V_118 ;
struct V_119 * V_120 ;
V_117 = V_13 -> V_121 ;
V_95 = & V_117 -> V_122 ;
for ( V_80 = 0 ; V_80 < V_112 ; V_80 ++ ) {
V_118 = & V_114 [ V_80 ] ;
if ( memcmp ( V_117 -> V_123 . V_39 ,
V_118 -> V_124 . V_39 ,
V_125 ) != 0 )
continue;
for ( V_115 = 0 ; V_115 < V_118 -> V_126 ; V_115 ++ ) {
V_120 = & V_118 -> V_127 [ V_115 ] ;
F_3 ( L_14
L_15 , V_32 ,
( ( T_3 * ) & V_118 -> V_124 . V_39 ) [ 0 ] ,
( ( T_3 * ) & V_118 -> V_124 . V_39 ) [ 1 ] ,
( ( T_3 * ) & V_118 -> V_124 . V_39 ) [ 2 ] ,
( ( T_3 * ) & V_118 -> V_124 . V_39 ) [ 3 ] ,
V_120 -> V_128 , V_120 -> V_129 ) ;
F_18 ( & V_95 -> V_130 ) ;
V_11 = ( F_25 ( V_120 -> V_129 , V_95 -> V_131 ) &&
V_95 -> V_103 [ V_120 -> V_129 ] . V_104 ==
V_120 -> V_128 ) ;
F_24 ( & V_95 -> V_130 ) ;
if ( V_11 )
goto V_14;
}
}
V_14:
return V_11 ;
}
T_1 F_51 ( struct V_96 * args ,
struct V_132 * V_3 ,
struct V_4 * V_5 )
{
struct V_94 * V_95 ;
struct V_40 * V_13 ;
int V_80 ;
T_1 V_11 = F_2 ( V_133 ) ;
V_13 = F_52 ( args -> V_134 , & args -> V_135 ) ;
if ( V_13 == NULL )
goto V_14;
V_95 = & V_13 -> V_121 -> V_136 ;
F_18 ( & V_95 -> V_130 ) ;
if ( F_25 ( V_137 , & V_13 -> V_121 -> V_138 ) ) {
F_24 ( & V_95 -> V_130 ) ;
V_11 = F_2 ( V_58 ) ;
if ( F_25 ( V_139 , & V_13 -> V_76 ) )
V_11 = F_2 ( V_133 ) ;
goto V_14;
}
V_11 = F_48 ( & V_13 -> V_121 -> V_136 , args ) ;
F_24 ( & V_95 -> V_130 ) ;
if ( V_11 )
goto V_14;
V_5 -> V_140 = args -> V_99 ;
if ( F_50 ( V_13 , args -> V_141 , args -> V_142 ) ) {
V_11 = F_2 ( V_58 ) ;
goto V_14;
}
memcpy ( & V_3 -> V_143 , & args -> V_135 ,
sizeof( V_3 -> V_143 ) ) ;
V_3 -> V_144 = args -> V_100 ;
V_3 -> V_145 = args -> V_99 ;
V_3 -> V_146 = V_101 - 1 ;
V_3 -> V_147 = V_101 - 1 ;
V_14:
V_5 -> V_13 = V_13 ;
for ( V_80 = 0 ; V_80 < args -> V_141 ; V_80 ++ )
F_45 ( args -> V_142 [ V_80 ] . V_127 ) ;
F_45 ( args -> V_142 ) ;
if ( V_11 == F_2 ( V_107 ) ) {
V_5 -> V_148 = V_11 ;
V_11 = 0 ;
} else
V_3 -> V_149 = V_11 ;
F_3 ( L_16 , V_32 ,
F_12 ( V_11 ) , F_12 ( V_3 -> V_149 ) ) ;
return V_11 ;
}
static bool
F_53 ( unsigned long V_150 )
{
return ( V_150 & ~ V_151 ) == 0 ;
}
T_1 F_54 ( struct V_152 * args , void * V_34 ,
struct V_4 * V_5 )
{
T_1 V_11 ;
T_5 V_153 = 0 ;
V_11 = F_41 ( V_12 ) ;
if ( ! V_5 -> V_13 )
goto V_14;
F_3 ( L_17 ,
F_4 ( V_5 -> V_13 -> V_17 , V_18 ) ) ;
V_11 = F_41 ( V_154 ) ;
if ( ! F_53 ( args -> V_155 ) )
goto V_14;
V_11 = F_41 ( V_111 ) ;
if ( F_25 ( V_156 , ( const unsigned long * )
& args -> V_155 ) )
V_153 = V_157 ;
if ( F_25 ( V_158 , ( const unsigned long * )
& args -> V_155 ) )
V_153 |= V_20 ;
if ( F_25 ( V_159 , ( const unsigned long * )
& args -> V_155 ) )
F_42 ( V_5 -> V_13 ) ;
if ( V_153 )
F_55 ( V_5 -> V_13 , V_153 ) ;
V_14:
F_3 ( L_2 , V_32 , F_12 ( V_11 ) ) ;
return V_11 ;
}
T_1 F_56 ( struct V_160 * args , void * V_34 ,
struct V_4 * V_5 )
{
struct V_94 * V_161 ;
T_1 V_11 ;
V_11 = F_2 ( V_12 ) ;
if ( ! V_5 -> V_13 )
goto V_14;
F_3 ( L_18 ,
F_4 ( V_5 -> V_13 -> V_17 , V_18 ) ,
args -> V_162 ) ;
V_161 = & V_5 -> V_13 -> V_121 -> V_122 ;
V_11 = F_2 ( V_163 ) ;
if ( args -> V_162 > V_161 -> V_164 ||
args -> V_162 < 1 )
goto V_14;
V_11 = F_2 ( V_111 ) ;
if ( args -> V_162 == V_161 -> V_164 )
goto V_14;
V_161 -> V_165 = args -> V_162 ;
F_57 ( V_5 -> V_13 ) ;
V_14:
F_3 ( L_2 , V_32 , F_12 ( V_11 ) ) ;
return V_11 ;
}
