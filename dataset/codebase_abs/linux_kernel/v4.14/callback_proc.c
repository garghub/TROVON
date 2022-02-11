T_1 F_1 ( void * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * args = V_1 ;
struct V_6 * V_7 = V_2 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_12 ;
V_7 -> V_13 = F_2 ( V_14 ) ;
if ( ! V_4 -> V_15 )
goto V_16;
V_7 -> V_17 [ 0 ] = V_7 -> V_17 [ 1 ] = 0 ;
V_7 -> V_13 = F_2 ( V_18 ) ;
F_3 ( L_1 ,
F_4 ( V_4 -> V_15 -> V_19 , V_20 ) ) ;
V_12 = F_5 ( V_4 -> V_15 , & args -> V_21 ) ;
if ( V_12 == NULL ) {
F_6 ( V_4 -> V_15 , & args -> V_21 , NULL ,
- F_7 ( V_7 -> V_13 ) ) ;
goto V_16;
}
V_11 = F_8 ( V_12 ) ;
F_9 () ;
V_9 = F_10 ( V_11 -> V_9 ) ;
if ( V_9 == NULL || ( V_9 -> type & V_22 ) == 0 )
goto V_23;
V_7 -> V_24 = F_11 ( V_12 ) ;
V_7 -> V_25 = V_9 -> V_25 ;
if ( F_12 ( V_12 ) )
V_7 -> V_25 ++ ;
V_7 -> ctime = V_12 -> V_26 ;
V_7 -> V_27 = V_12 -> V_28 ;
V_7 -> V_17 [ 0 ] = ( V_29 | V_30 ) &
args -> V_17 [ 0 ] ;
V_7 -> V_17 [ 1 ] = ( V_31 | V_32 ) &
args -> V_17 [ 1 ] ;
V_7 -> V_13 = 0 ;
V_23:
F_13 () ;
F_6 ( V_4 -> V_15 , & args -> V_21 , V_12 , - F_7 ( V_7 -> V_13 ) ) ;
F_14 ( V_12 ) ;
V_16:
F_15 ( L_2 , V_33 , F_7 ( V_7 -> V_13 ) ) ;
return V_7 -> V_13 ;
}
T_1 F_16 ( void * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_34 * args = V_1 ;
struct V_12 * V_12 ;
T_1 V_7 ;
V_7 = F_2 ( V_14 ) ;
if ( ! V_4 -> V_15 )
goto V_16;
F_3 ( L_3 ,
F_4 ( V_4 -> V_15 -> V_19 , V_20 ) ) ;
V_7 = F_2 ( V_18 ) ;
V_12 = F_5 ( V_4 -> V_15 , & args -> V_21 ) ;
if ( V_12 == NULL ) {
F_17 ( V_4 -> V_15 , & args -> V_21 , NULL ,
& args -> V_35 , - F_7 ( V_7 ) ) ;
goto V_16;
}
switch ( F_18 ( V_12 , & args -> V_35 ) ) {
case 0 :
V_7 = 0 ;
break;
case - V_36 :
V_7 = F_2 ( V_37 ) ;
break;
default:
V_7 = F_2 ( V_38 ) ;
}
F_17 ( V_4 -> V_15 , & args -> V_21 , V_12 ,
& args -> V_35 , - F_7 ( V_7 ) ) ;
F_14 ( V_12 ) ;
V_16:
F_15 ( L_2 , V_33 , F_7 ( V_7 ) ) ;
return V_7 ;
}
static struct V_12 * F_19 ( struct V_39 * V_15 ,
const T_2 * V_35 )
{
struct V_40 * V_41 ;
struct V_12 * V_12 ;
struct V_42 * V_43 ;
V_44:
F_20 (server, &clp->cl_superblocks, client_link) {
F_21 (lo, &server->layouts, plh_layouts) {
if ( V_35 != NULL &&
! F_22 ( V_35 , & V_43 -> V_45 ) )
continue;
V_12 = F_23 ( V_43 -> V_46 ) ;
if ( ! V_12 )
continue;
if ( ! F_24 ( V_12 -> V_47 ) ) {
F_13 () ;
F_25 ( & V_15 -> V_48 ) ;
F_14 ( V_12 ) ;
F_26 ( & V_15 -> V_48 ) ;
F_9 () ;
goto V_44;
}
return V_12 ;
}
}
return NULL ;
}
static struct V_12 * F_27 ( struct V_39 * V_15 ,
const struct V_49 * V_21 )
{
struct V_40 * V_41 ;
struct V_10 * V_11 ;
struct V_12 * V_12 ;
struct V_42 * V_43 ;
V_44:
F_20 (server, &clp->cl_superblocks, client_link) {
F_21 (lo, &server->layouts, plh_layouts) {
V_11 = F_8 ( V_43 -> V_46 ) ;
if ( F_28 ( V_21 , & V_11 -> V_21 ) )
continue;
if ( V_11 -> V_50 != V_43 )
continue;
V_12 = F_23 ( V_43 -> V_46 ) ;
if ( ! V_12 )
continue;
if ( ! F_24 ( V_12 -> V_47 ) ) {
F_13 () ;
F_25 ( & V_15 -> V_48 ) ;
F_14 ( V_12 ) ;
F_26 ( & V_15 -> V_48 ) ;
F_9 () ;
goto V_44;
}
return V_12 ;
}
}
return NULL ;
}
static struct V_12 * F_29 ( struct V_39 * V_15 ,
const struct V_49 * V_21 ,
const T_2 * V_35 )
{
struct V_12 * V_12 ;
F_26 ( & V_15 -> V_48 ) ;
F_9 () ;
V_12 = F_19 ( V_15 , V_35 ) ;
if ( ! V_12 )
V_12 = F_27 ( V_15 , V_21 ) ;
F_13 () ;
F_25 ( & V_15 -> V_48 ) ;
return V_12 ;
}
static T_3 F_30 ( struct V_42 * V_43 ,
const T_2 * V_51 )
{
T_3 V_52 , V_53 ;
if ( ! F_31 ( V_43 ) )
return V_54 ;
if ( ! F_22 ( & V_43 -> V_45 , V_51 ) )
return V_37 ;
V_53 = F_32 ( V_51 -> V_55 ) ;
if ( F_33 ( V_56 , & V_43 -> V_57 ) &&
V_43 -> V_58 != 0 ) {
if ( V_53 < V_43 -> V_58 )
return V_59 ;
if ( V_53 > V_43 -> V_58 )
return V_54 ;
goto V_16;
}
V_52 = F_32 ( V_43 -> V_45 . V_55 ) ;
if ( V_53 > V_52 + 1 )
return V_54 ;
if ( V_53 <= V_52 )
return V_59 ;
V_16:
return V_60 ;
}
static T_3 F_34 ( struct V_39 * V_15 ,
struct V_61 * args )
{
struct V_12 * V_62 ;
struct V_42 * V_43 ;
T_3 V_63 = V_64 ;
F_35 ( V_65 ) ;
V_62 = F_29 ( V_15 , & args -> V_66 , & args -> V_67 ) ;
if ( ! V_62 )
goto V_16;
F_36 ( V_62 , false ) ;
F_26 ( & V_62 -> V_68 ) ;
V_43 = F_8 ( V_62 ) -> V_50 ;
if ( ! V_43 ) {
F_25 ( & V_62 -> V_68 ) ;
goto V_16;
}
F_37 ( V_43 ) ;
V_63 = F_30 ( V_43 , & args -> V_67 ) ;
if ( V_63 != V_60 )
goto V_69;
F_38 ( V_43 , & args -> V_67 , true ) ;
if ( F_33 ( V_70 , & V_43 -> V_57 ) ) {
V_63 = V_54 ;
goto V_69;
}
if ( F_39 ( V_43 , & V_65 ,
& args -> V_71 ,
F_32 ( args -> V_67 . V_55 ) ) ) {
V_63 = V_72 ;
goto V_69;
}
V_63 = V_64 ;
if ( F_40 ( V_62 ) -> V_73 -> V_74 ) {
F_40 ( V_62 ) -> V_73 -> V_74 ( V_43 ,
& args -> V_71 ) ;
}
V_69:
F_25 ( & V_62 -> V_68 ) ;
F_41 ( & V_65 ) ;
F_42 ( V_62 , 0 ) ;
F_43 ( V_43 ) ;
V_16:
F_44 ( V_15 , & args -> V_66 , V_62 ,
& args -> V_67 , - V_63 ) ;
F_45 ( V_62 ) ;
return V_63 ;
}
static T_3 F_46 ( struct V_39 * V_15 ,
struct V_61 * args )
{
int V_75 ;
if ( args -> V_76 == V_77 )
V_75 = F_47 ( V_15 , & args -> V_78 , true ) ;
else
V_75 = F_48 ( V_15 , true ) ;
if ( V_75 != 0 )
return V_54 ;
return V_64 ;
}
static T_3 F_49 ( struct V_39 * V_15 ,
struct V_61 * args )
{
if ( args -> V_76 == V_79 )
return F_34 ( V_15 , args ) ;
return F_46 ( V_15 , args ) ;
}
T_1 F_50 ( void * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_61 * args = V_1 ;
T_3 V_7 = V_14 ;
if ( V_4 -> V_15 )
V_7 = F_49 ( V_4 -> V_15 , args ) ;
return F_51 ( V_7 ) ;
}
static void F_52 ( struct V_39 * V_15 )
{
struct V_61 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_76 = V_80 ;
F_49 ( V_15 , & args ) ;
}
T_1 F_53 ( void * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_81 * args = V_1 ;
int V_82 ;
T_1 V_7 = 0 ;
struct V_39 * V_15 = V_4 -> V_15 ;
struct V_40 * V_41 = NULL ;
if ( ! V_15 ) {
V_7 = F_51 ( V_14 ) ;
goto V_16;
}
for ( V_82 = 0 ; V_82 < args -> V_83 ; V_82 ++ ) {
struct V_84 * V_85 = & args -> V_86 [ V_82 ] ;
if ( ! V_41 ||
V_41 -> V_73 -> V_87 != V_85 -> V_88 ) {
F_9 () ;
F_20 (server, &clp->cl_superblocks, client_link)
if ( V_41 -> V_73 &&
V_41 -> V_73 -> V_87 == V_85 -> V_88 ) {
F_13 () ;
goto V_89;
}
F_13 () ;
continue;
}
V_89:
F_54 ( V_41 -> V_73 , V_15 , & V_85 -> V_90 ) ;
}
V_16:
F_55 ( args -> V_86 ) ;
return V_7 ;
}
static T_1
F_56 ( const struct V_91 * V_92 , const struct V_93 * V_94 ,
const struct V_95 * args )
{
if ( args -> V_96 > V_92 -> V_97 )
return F_2 ( V_98 ) ;
if ( args -> V_99 == V_94 -> V_100 ) {
if ( F_57 ( V_92 , V_94 -> V_101 ) )
return F_2 ( V_54 ) ;
if ( args -> V_102 == 0 )
return F_2 ( V_103 ) ;
return F_2 ( V_104 ) ;
}
if ( F_58 ( V_94 -> V_100 == 0xFFFFFFFFU ) ) {
if ( args -> V_99 == 1 )
return F_2 ( V_72 ) ;
} else if ( F_59 ( args -> V_99 == V_94 -> V_100 + 1 ) )
return F_2 ( V_72 ) ;
return F_2 ( V_105 ) ;
}
static bool F_60 ( struct V_39 * V_15 ,
T_4 V_106 ,
struct V_107 * V_108 )
{
bool V_13 = 0 ;
int V_82 , V_109 ;
struct V_110 * V_111 ;
struct V_91 * V_92 ;
struct V_107 * V_112 ;
struct V_113 * V_114 ;
V_111 = V_15 -> V_115 ;
V_92 = & V_111 -> V_116 ;
for ( V_82 = 0 ; V_82 < V_106 ; V_82 ++ ) {
V_112 = & V_108 [ V_82 ] ;
if ( memcmp ( V_111 -> V_117 . V_118 ,
V_112 -> V_119 . V_118 ,
V_120 ) != 0 )
continue;
for ( V_109 = 0 ; V_109 < V_112 -> V_121 ; V_109 ++ ) {
V_114 = & V_112 -> V_122 [ V_109 ] ;
V_13 = F_61 ( V_92 , V_114 -> V_123 ,
V_114 -> V_124 , V_125 >> 1 ) < 0 ;
if ( V_13 )
goto V_16;
}
}
V_16:
return V_13 ;
}
T_1 F_62 ( void * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_95 * args = V_1 ;
struct V_126 * V_7 = V_2 ;
struct V_91 * V_92 ;
struct V_93 * V_94 ;
struct V_39 * V_15 ;
int V_82 ;
T_1 V_13 = F_2 ( V_127 ) ;
V_15 = F_63 ( V_4 -> V_128 , args -> V_129 ,
& args -> V_130 , V_4 -> V_131 ) ;
if ( V_15 == NULL )
goto V_16;
if ( ! ( V_15 -> V_115 -> V_132 & V_133 ) )
goto V_16;
V_92 = & V_15 -> V_115 -> V_134 ;
memcpy ( & V_7 -> V_135 , & args -> V_130 ,
sizeof( V_7 -> V_135 ) ) ;
V_7 -> V_136 = args -> V_99 ;
V_7 -> V_137 = args -> V_96 ;
F_26 ( & V_92 -> V_138 ) ;
if ( F_33 ( V_139 , & V_92 -> V_140 ) ) {
V_13 = F_2 ( V_54 ) ;
if ( F_33 ( V_141 , & V_15 -> V_142 ) )
V_13 = F_2 ( V_127 ) ;
goto V_143;
}
V_13 = F_2 ( V_98 ) ;
V_94 = F_64 ( V_92 , args -> V_96 ) ;
if ( F_65 ( V_94 ) )
goto V_143;
V_7 -> V_144 = V_92 -> V_97 ;
V_7 -> V_145 = V_92 -> V_146 ;
V_13 = F_56 ( V_92 , V_94 , args ) ;
if ( V_13 )
goto V_143;
if ( ! F_66 ( V_92 , V_94 ) ) {
V_13 = F_2 ( V_54 ) ;
goto V_143;
}
V_4 -> V_94 = V_94 ;
if ( args -> V_102 != 0 ) {
V_13 = F_2 ( V_147 ) ;
goto V_143;
}
if ( F_60 ( V_15 , args -> V_148 , args -> V_149 ) ) {
V_13 = F_2 ( V_54 ) ;
goto V_143;
}
V_94 -> V_100 = args -> V_99 ;
V_143:
F_25 ( & V_92 -> V_138 ) ;
V_16:
V_4 -> V_15 = V_15 ;
for ( V_82 = 0 ; V_82 < args -> V_148 ; V_82 ++ )
F_55 ( args -> V_149 [ V_82 ] . V_122 ) ;
F_55 ( args -> V_149 ) ;
if ( V_13 == F_2 ( V_103 ) ) {
V_4 -> V_150 = V_13 ;
V_13 = 0 ;
} else
V_7 -> V_151 = V_13 ;
F_67 ( args , V_7 , V_13 ) ;
return V_13 ;
}
static bool
F_68 ( unsigned long V_152 )
{
return ( V_152 & ~ V_153 ) == 0 ;
}
T_1 F_69 ( void * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_154 * args = V_1 ;
T_1 V_13 ;
T_5 V_132 = 0 ;
V_13 = F_51 ( V_14 ) ;
if ( ! V_4 -> V_15 )
goto V_16;
F_3 ( L_4 ,
F_4 ( V_4 -> V_15 -> V_19 , V_20 ) ) ;
V_13 = F_51 ( V_155 ) ;
if ( ! F_68 ( args -> V_156 ) )
goto V_16;
V_13 = F_51 ( V_72 ) ;
if ( F_33 ( V_157 , ( const unsigned long * )
& args -> V_156 ) )
V_132 = V_158 ;
if ( F_33 ( V_159 , ( const unsigned long * )
& args -> V_156 ) )
V_132 |= V_22 ;
if ( F_33 ( V_160 , ( const unsigned long * )
& args -> V_156 ) )
F_52 ( V_4 -> V_15 ) ;
if ( V_132 )
F_70 ( V_4 -> V_15 , V_132 ) ;
V_16:
F_15 ( L_2 , V_33 , F_7 ( V_13 ) ) ;
return V_13 ;
}
T_1 F_71 ( void * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_161 * args = V_1 ;
struct V_91 * V_162 ;
T_1 V_13 ;
V_13 = F_2 ( V_14 ) ;
if ( ! V_4 -> V_15 )
goto V_16;
F_3 ( L_5 ,
F_4 ( V_4 -> V_15 -> V_19 , V_20 ) ,
args -> V_163 ) ;
V_162 = & V_4 -> V_15 -> V_115 -> V_116 ;
V_13 = F_2 ( V_72 ) ;
F_72 ( V_162 , args -> V_163 ) ;
F_73 ( V_4 -> V_15 ) ;
V_16:
F_15 ( L_2 , V_33 , F_7 ( V_13 ) ) ;
return V_13 ;
}
T_1 F_74 ( void * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_164 * args = V_1 ;
if ( ! V_4 -> V_15 )
return F_2 ( V_14 ) ;
F_3 ( L_6 ,
F_4 ( V_4 -> V_15 -> V_19 , V_20 ) ) ;
if ( args -> V_165 )
F_75 ( & V_4 -> V_15 -> V_166 , V_167 , 0 , args ) ;
return F_2 ( V_72 ) ;
}
