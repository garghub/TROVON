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
if ( V_10 == NULL ) {
F_6 ( V_5 -> V_13 , & args -> V_19 , NULL ,
- F_7 ( V_3 -> V_11 ) ) ;
goto V_14;
}
V_9 = F_8 ( V_10 ) ;
F_9 () ;
V_7 = F_10 ( V_9 -> V_7 ) ;
if ( V_7 == NULL || ( V_7 -> type & V_20 ) == 0 )
goto V_21;
V_3 -> V_22 = F_11 ( V_10 ) ;
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
F_12 () ;
F_6 ( V_5 -> V_13 , & args -> V_19 , V_10 , - F_7 ( V_3 -> V_11 ) ) ;
F_13 ( V_10 ) ;
V_14:
F_14 ( L_2 , V_32 , F_7 ( V_3 -> V_11 ) ) ;
return V_3 -> V_11 ;
}
T_1 F_15 ( struct V_33 * args , void * V_34 ,
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
if ( V_10 == NULL ) {
F_16 ( V_5 -> V_13 , & args -> V_19 , NULL ,
& args -> V_35 , - F_7 ( V_3 ) ) ;
goto V_14;
}
switch ( F_17 ( V_10 , & args -> V_35 ) ) {
case 0 :
V_3 = 0 ;
break;
case - V_36 :
V_3 = F_2 ( V_37 ) ;
break;
default:
V_3 = F_2 ( V_38 ) ;
}
F_16 ( V_5 -> V_13 , & args -> V_19 , V_10 ,
& args -> V_35 , - F_7 ( V_3 ) ) ;
F_13 ( V_10 ) ;
V_14:
F_14 ( L_2 , V_32 , F_7 ( V_3 ) ) ;
return V_3 ;
}
static struct V_10 * F_18 ( struct V_39 * V_13 ,
const T_2 * V_35 )
{
struct V_40 * V_41 ;
struct V_10 * V_10 ;
struct V_42 * V_43 ;
V_44:
F_19 (server, &clp->cl_superblocks, client_link) {
F_20 (lo, &server->layouts, plh_layouts) {
if ( V_35 != NULL &&
! F_21 ( V_35 , & V_43 -> V_45 ) )
continue;
V_10 = F_22 ( V_43 -> V_46 ) ;
if ( ! V_10 )
continue;
if ( ! F_23 ( V_10 -> V_47 ) ) {
F_12 () ;
F_24 ( & V_13 -> V_48 ) ;
F_13 ( V_10 ) ;
F_25 ( & V_13 -> V_48 ) ;
F_9 () ;
goto V_44;
}
return V_10 ;
}
}
return NULL ;
}
static struct V_10 * F_26 ( struct V_39 * V_13 ,
const struct V_49 * V_19 )
{
struct V_40 * V_41 ;
struct V_8 * V_9 ;
struct V_10 * V_10 ;
struct V_42 * V_43 ;
V_44:
F_19 (server, &clp->cl_superblocks, client_link) {
F_20 (lo, &server->layouts, plh_layouts) {
V_9 = F_8 ( V_43 -> V_46 ) ;
if ( F_27 ( V_19 , & V_9 -> V_19 ) )
continue;
if ( V_9 -> V_50 != V_43 )
continue;
V_10 = F_22 ( V_43 -> V_46 ) ;
if ( ! V_10 )
continue;
if ( ! F_23 ( V_10 -> V_47 ) ) {
F_12 () ;
F_24 ( & V_13 -> V_48 ) ;
F_13 ( V_10 ) ;
F_25 ( & V_13 -> V_48 ) ;
F_9 () ;
goto V_44;
}
return V_10 ;
}
}
return NULL ;
}
static struct V_10 * F_28 ( struct V_39 * V_13 ,
const struct V_49 * V_19 ,
const T_2 * V_35 )
{
struct V_10 * V_10 ;
F_25 ( & V_13 -> V_48 ) ;
F_9 () ;
V_10 = F_18 ( V_13 , V_35 ) ;
if ( ! V_10 )
V_10 = F_26 ( V_13 , V_19 ) ;
F_12 () ;
F_24 ( & V_13 -> V_48 ) ;
return V_10 ;
}
static T_3 F_29 ( struct V_42 * V_43 ,
const T_2 * V_51 )
{
T_3 V_52 , V_53 ;
if ( ! F_30 ( V_43 ) )
return V_54 ;
if ( ! F_21 ( & V_43 -> V_45 , V_51 ) )
return V_37 ;
V_53 = F_31 ( V_51 -> V_55 ) ;
if ( F_32 ( V_56 , & V_43 -> V_57 ) &&
V_43 -> V_58 != 0 ) {
if ( V_53 < V_43 -> V_58 )
return V_59 ;
if ( V_53 > V_43 -> V_58 )
return V_54 ;
goto V_14;
}
V_52 = F_31 ( V_43 -> V_45 . V_55 ) ;
if ( V_53 > V_52 + 1 )
return V_54 ;
if ( V_53 <= V_52 )
return V_59 ;
V_14:
return V_60 ;
}
static T_3 F_33 ( struct V_39 * V_13 ,
struct V_61 * args )
{
struct V_10 * V_62 ;
struct V_42 * V_43 ;
T_3 V_63 = V_64 ;
F_34 ( V_65 ) ;
V_62 = F_28 ( V_13 , & args -> V_66 , & args -> V_67 ) ;
if ( ! V_62 )
goto V_14;
F_35 ( V_62 , false ) ;
F_25 ( & V_62 -> V_68 ) ;
V_43 = F_8 ( V_62 ) -> V_50 ;
if ( ! V_43 ) {
F_24 ( & V_62 -> V_68 ) ;
goto V_14;
}
F_36 ( V_43 ) ;
V_63 = F_29 ( V_43 , & args -> V_67 ) ;
if ( V_63 != V_60 )
goto V_69;
F_37 ( V_43 , & args -> V_67 , true ) ;
if ( F_32 ( V_70 , & V_43 -> V_57 ) ) {
V_63 = V_54 ;
goto V_69;
}
if ( F_38 ( V_43 , & V_65 ,
& args -> V_71 ,
F_31 ( args -> V_67 . V_55 ) ) ) {
V_63 = V_72 ;
goto V_69;
}
V_63 = V_64 ;
if ( F_39 ( V_62 ) -> V_73 -> V_74 ) {
F_39 ( V_62 ) -> V_73 -> V_74 ( V_43 ,
& args -> V_71 ) ;
}
V_69:
F_24 ( & V_62 -> V_68 ) ;
F_40 ( & V_65 ) ;
F_41 ( V_62 , 0 ) ;
F_42 ( V_43 ) ;
V_14:
F_43 ( V_13 , & args -> V_66 , V_62 ,
& args -> V_67 , - V_63 ) ;
F_44 ( V_62 ) ;
return V_63 ;
}
static T_3 F_45 ( struct V_39 * V_13 ,
struct V_61 * args )
{
int V_75 ;
if ( args -> V_76 == V_77 )
V_75 = F_46 ( V_13 , & args -> V_78 , true ) ;
else
V_75 = F_47 ( V_13 , true ) ;
if ( V_75 != 0 )
return V_54 ;
return V_64 ;
}
static T_3 F_48 ( struct V_39 * V_13 ,
struct V_61 * args )
{
if ( args -> V_76 == V_79 )
return F_33 ( V_13 , args ) ;
return F_45 ( V_13 , args ) ;
}
T_1 F_49 ( struct V_61 * args ,
void * V_34 , struct V_4 * V_5 )
{
T_3 V_3 = V_12 ;
if ( V_5 -> V_13 )
V_3 = F_48 ( V_5 -> V_13 , args ) ;
return F_50 ( V_3 ) ;
}
static void F_51 ( struct V_39 * V_13 )
{
struct V_61 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_76 = V_80 ;
F_48 ( V_13 , & args ) ;
}
T_1 F_52 ( struct V_81 * args ,
void * V_34 , struct V_4 * V_5 )
{
int V_82 ;
T_1 V_3 = 0 ;
struct V_39 * V_13 = V_5 -> V_13 ;
struct V_40 * V_41 = NULL ;
if ( ! V_13 ) {
V_3 = F_50 ( V_12 ) ;
goto V_14;
}
for ( V_82 = 0 ; V_82 < args -> V_83 ; V_82 ++ ) {
struct V_84 * V_85 = & args -> V_86 [ V_82 ] ;
if ( ! V_41 ||
V_41 -> V_73 -> V_87 != V_85 -> V_88 ) {
F_9 () ;
F_19 (server, &clp->cl_superblocks, client_link)
if ( V_41 -> V_73 &&
V_41 -> V_73 -> V_87 == V_85 -> V_88 ) {
F_12 () ;
goto V_89;
}
F_12 () ;
continue;
}
V_89:
F_53 ( V_41 -> V_73 , V_13 , & V_85 -> V_90 ) ;
}
V_14:
F_54 ( args -> V_86 ) ;
return V_3 ;
}
static T_1
F_55 ( const struct V_91 * V_92 , const struct V_93 * V_94 ,
const struct V_95 * args )
{
if ( args -> V_96 > V_92 -> V_97 )
return F_2 ( V_98 ) ;
if ( args -> V_99 == V_94 -> V_100 ) {
if ( F_56 ( V_92 , V_94 -> V_101 ) )
return F_2 ( V_54 ) ;
if ( args -> V_102 == 0 )
return F_2 ( V_103 ) ;
return F_2 ( V_104 ) ;
}
if ( F_57 ( V_94 -> V_100 == 0xFFFFFFFFU ) ) {
if ( args -> V_99 == 1 )
return F_2 ( V_72 ) ;
} else if ( F_58 ( args -> V_99 == V_94 -> V_100 + 1 ) )
return F_2 ( V_72 ) ;
return F_2 ( V_105 ) ;
}
static bool F_59 ( struct V_39 * V_13 ,
T_4 V_106 ,
struct V_107 * V_108 )
{
bool V_11 = 0 ;
int V_82 , V_109 ;
struct V_110 * V_111 ;
struct V_91 * V_92 ;
struct V_107 * V_112 ;
struct V_113 * V_114 ;
V_111 = V_13 -> V_115 ;
V_92 = & V_111 -> V_116 ;
for ( V_82 = 0 ; V_82 < V_106 ; V_82 ++ ) {
V_112 = & V_108 [ V_82 ] ;
if ( memcmp ( V_111 -> V_117 . V_118 ,
V_112 -> V_119 . V_118 ,
V_120 ) != 0 )
continue;
for ( V_109 = 0 ; V_109 < V_112 -> V_121 ; V_109 ++ ) {
V_114 = & V_112 -> V_122 [ V_109 ] ;
V_11 = F_60 ( V_92 , V_114 -> V_123 ,
V_114 -> V_124 , V_125 >> 1 ) < 0 ;
if ( V_11 )
goto V_14;
}
}
V_14:
return V_11 ;
}
T_1 F_61 ( struct V_95 * args ,
struct V_126 * V_3 ,
struct V_4 * V_5 )
{
struct V_91 * V_92 ;
struct V_93 * V_94 ;
struct V_39 * V_13 ;
int V_82 ;
T_1 V_11 = F_2 ( V_127 ) ;
V_13 = F_62 ( V_5 -> V_128 , args -> V_129 ,
& args -> V_130 , V_5 -> V_131 ) ;
if ( V_13 == NULL )
goto V_14;
if ( ! ( V_13 -> V_115 -> V_132 & V_133 ) )
goto V_14;
V_92 = & V_13 -> V_115 -> V_134 ;
memcpy ( & V_3 -> V_135 , & args -> V_130 ,
sizeof( V_3 -> V_135 ) ) ;
V_3 -> V_136 = args -> V_99 ;
V_3 -> V_137 = args -> V_96 ;
F_25 ( & V_92 -> V_138 ) ;
if ( F_32 ( V_139 , & V_92 -> V_140 ) ) {
V_11 = F_2 ( V_54 ) ;
if ( F_32 ( V_141 , & V_13 -> V_142 ) )
V_11 = F_2 ( V_127 ) ;
goto V_143;
}
V_11 = F_2 ( V_98 ) ;
V_94 = F_63 ( V_92 , args -> V_96 ) ;
if ( F_64 ( V_94 ) )
goto V_143;
V_3 -> V_144 = V_92 -> V_97 ;
V_3 -> V_145 = V_92 -> V_146 ;
V_11 = F_55 ( V_92 , V_94 , args ) ;
if ( V_11 )
goto V_143;
if ( ! F_65 ( V_92 , V_94 ) ) {
V_11 = F_2 ( V_54 ) ;
goto V_143;
}
V_5 -> V_94 = V_94 ;
if ( args -> V_102 != 0 ) {
V_11 = F_2 ( V_147 ) ;
goto V_143;
}
if ( F_59 ( V_13 , args -> V_148 , args -> V_149 ) ) {
V_11 = F_2 ( V_54 ) ;
goto V_143;
}
V_94 -> V_100 = args -> V_99 ;
V_143:
F_24 ( & V_92 -> V_138 ) ;
V_14:
V_5 -> V_13 = V_13 ;
for ( V_82 = 0 ; V_82 < args -> V_148 ; V_82 ++ )
F_54 ( args -> V_149 [ V_82 ] . V_122 ) ;
F_54 ( args -> V_149 ) ;
if ( V_11 == F_2 ( V_103 ) ) {
V_5 -> V_150 = V_11 ;
V_11 = 0 ;
} else
V_3 -> V_151 = V_11 ;
F_66 ( args , V_3 , V_11 ) ;
return V_11 ;
}
static bool
F_67 ( unsigned long V_152 )
{
return ( V_152 & ~ V_153 ) == 0 ;
}
T_1 F_68 ( struct V_154 * args , void * V_34 ,
struct V_4 * V_5 )
{
T_1 V_11 ;
T_5 V_132 = 0 ;
V_11 = F_50 ( V_12 ) ;
if ( ! V_5 -> V_13 )
goto V_14;
F_3 ( L_4 ,
F_4 ( V_5 -> V_13 -> V_17 , V_18 ) ) ;
V_11 = F_50 ( V_155 ) ;
if ( ! F_67 ( args -> V_156 ) )
goto V_14;
V_11 = F_50 ( V_72 ) ;
if ( F_32 ( V_157 , ( const unsigned long * )
& args -> V_156 ) )
V_132 = V_158 ;
if ( F_32 ( V_159 , ( const unsigned long * )
& args -> V_156 ) )
V_132 |= V_20 ;
if ( F_32 ( V_160 , ( const unsigned long * )
& args -> V_156 ) )
F_51 ( V_5 -> V_13 ) ;
if ( V_132 )
F_69 ( V_5 -> V_13 , V_132 ) ;
V_14:
F_14 ( L_2 , V_32 , F_7 ( V_11 ) ) ;
return V_11 ;
}
T_1 F_70 ( struct V_161 * args , void * V_34 ,
struct V_4 * V_5 )
{
struct V_91 * V_162 ;
T_1 V_11 ;
V_11 = F_2 ( V_12 ) ;
if ( ! V_5 -> V_13 )
goto V_14;
F_3 ( L_5 ,
F_4 ( V_5 -> V_13 -> V_17 , V_18 ) ,
args -> V_163 ) ;
V_162 = & V_5 -> V_13 -> V_115 -> V_116 ;
V_11 = F_2 ( V_72 ) ;
F_71 ( V_162 , args -> V_163 ) ;
F_72 ( V_5 -> V_13 ) ;
V_14:
F_14 ( L_2 , V_32 , F_7 ( V_11 ) ) ;
return V_11 ;
}
T_1 F_73 ( struct V_164 * args , void * V_34 ,
struct V_4 * V_5 )
{
if ( ! V_5 -> V_13 )
return F_2 ( V_12 ) ;
F_3 ( L_6 ,
F_4 ( V_5 -> V_13 -> V_17 , V_18 ) ) ;
if ( args -> V_165 )
F_74 ( & V_5 -> V_13 -> V_166 , V_167 , 0 , args ) ;
return F_2 ( V_72 ) ;
}
