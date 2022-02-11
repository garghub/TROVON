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
if ( V_11 -> V_26 != 0 )
V_7 -> V_25 ++ ;
V_7 -> ctime = V_12 -> V_27 ;
V_7 -> V_28 = V_12 -> V_29 ;
V_7 -> V_17 [ 0 ] = ( V_30 | V_31 ) &
args -> V_17 [ 0 ] ;
V_7 -> V_17 [ 1 ] = ( V_32 | V_33 ) &
args -> V_17 [ 1 ] ;
V_7 -> V_13 = 0 ;
V_23:
F_12 () ;
F_6 ( V_4 -> V_15 , & args -> V_21 , V_12 , - F_7 ( V_7 -> V_13 ) ) ;
F_13 ( V_12 ) ;
V_16:
F_14 ( L_2 , V_34 , F_7 ( V_7 -> V_13 ) ) ;
return V_7 -> V_13 ;
}
T_1 F_15 ( void * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_35 * args = V_1 ;
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
F_16 ( V_4 -> V_15 , & args -> V_21 , NULL ,
& args -> V_36 , - F_7 ( V_7 ) ) ;
goto V_16;
}
switch ( F_17 ( V_12 , & args -> V_36 ) ) {
case 0 :
V_7 = 0 ;
break;
case - V_37 :
V_7 = F_2 ( V_38 ) ;
break;
default:
V_7 = F_2 ( V_39 ) ;
}
F_16 ( V_4 -> V_15 , & args -> V_21 , V_12 ,
& args -> V_36 , - F_7 ( V_7 ) ) ;
F_13 ( V_12 ) ;
V_16:
F_14 ( L_2 , V_34 , F_7 ( V_7 ) ) ;
return V_7 ;
}
static struct V_12 * F_18 ( struct V_40 * V_15 ,
const T_2 * V_36 )
{
struct V_41 * V_42 ;
struct V_12 * V_12 ;
struct V_43 * V_44 ;
V_45:
F_19 (server, &clp->cl_superblocks, client_link) {
F_20 (lo, &server->layouts, plh_layouts) {
if ( V_36 != NULL &&
! F_21 ( V_36 , & V_44 -> V_46 ) )
continue;
V_12 = F_22 ( V_44 -> V_47 ) ;
if ( ! V_12 )
continue;
if ( ! F_23 ( V_12 -> V_48 ) ) {
F_12 () ;
F_24 ( & V_15 -> V_49 ) ;
F_13 ( V_12 ) ;
F_25 ( & V_15 -> V_49 ) ;
F_9 () ;
goto V_45;
}
return V_12 ;
}
}
return NULL ;
}
static struct V_12 * F_26 ( struct V_40 * V_15 ,
const struct V_50 * V_21 )
{
struct V_41 * V_42 ;
struct V_10 * V_11 ;
struct V_12 * V_12 ;
struct V_43 * V_44 ;
V_45:
F_19 (server, &clp->cl_superblocks, client_link) {
F_20 (lo, &server->layouts, plh_layouts) {
V_11 = F_8 ( V_44 -> V_47 ) ;
if ( F_27 ( V_21 , & V_11 -> V_21 ) )
continue;
if ( V_11 -> V_51 != V_44 )
continue;
V_12 = F_22 ( V_44 -> V_47 ) ;
if ( ! V_12 )
continue;
if ( ! F_23 ( V_12 -> V_48 ) ) {
F_12 () ;
F_24 ( & V_15 -> V_49 ) ;
F_13 ( V_12 ) ;
F_25 ( & V_15 -> V_49 ) ;
F_9 () ;
goto V_45;
}
return V_12 ;
}
}
return NULL ;
}
static struct V_12 * F_28 ( struct V_40 * V_15 ,
const struct V_50 * V_21 ,
const T_2 * V_36 )
{
struct V_12 * V_12 ;
F_25 ( & V_15 -> V_49 ) ;
F_9 () ;
V_12 = F_18 ( V_15 , V_36 ) ;
if ( ! V_12 )
V_12 = F_26 ( V_15 , V_21 ) ;
F_12 () ;
F_24 ( & V_15 -> V_49 ) ;
return V_12 ;
}
static T_3 F_29 ( struct V_43 * V_44 ,
const T_2 * V_52 )
{
T_3 V_53 , V_54 ;
if ( ! F_30 ( V_44 ) )
return V_55 ;
if ( ! F_21 ( & V_44 -> V_46 , V_52 ) )
return V_38 ;
V_54 = F_31 ( V_52 -> V_56 ) ;
if ( F_32 ( V_57 , & V_44 -> V_58 ) &&
V_44 -> V_59 != 0 ) {
if ( V_54 < V_44 -> V_59 )
return V_60 ;
if ( V_54 > V_44 -> V_59 )
return V_55 ;
goto V_16;
}
V_53 = F_31 ( V_44 -> V_46 . V_56 ) ;
if ( V_54 > V_53 + 1 )
return V_55 ;
if ( V_54 <= V_53 )
return V_60 ;
V_16:
return V_61 ;
}
static T_3 F_33 ( struct V_40 * V_15 ,
struct V_62 * args )
{
struct V_12 * V_63 ;
struct V_43 * V_44 ;
T_3 V_64 = V_65 ;
F_34 ( V_66 ) ;
V_63 = F_28 ( V_15 , & args -> V_67 , & args -> V_68 ) ;
if ( ! V_63 )
goto V_16;
F_35 ( V_63 , false ) ;
F_25 ( & V_63 -> V_69 ) ;
V_44 = F_8 ( V_63 ) -> V_51 ;
if ( ! V_44 ) {
F_24 ( & V_63 -> V_69 ) ;
goto V_16;
}
F_36 ( V_44 ) ;
V_64 = F_29 ( V_44 , & args -> V_68 ) ;
if ( V_64 != V_61 )
goto V_70;
F_37 ( V_44 , & args -> V_68 , true ) ;
if ( F_32 ( V_71 , & V_44 -> V_58 ) ) {
V_64 = V_55 ;
goto V_70;
}
if ( F_38 ( V_44 , & V_66 ,
& args -> V_72 ,
F_31 ( args -> V_68 . V_56 ) ) ) {
V_64 = V_73 ;
goto V_70;
}
V_64 = V_65 ;
if ( F_39 ( V_63 ) -> V_74 -> V_75 ) {
F_39 ( V_63 ) -> V_74 -> V_75 ( V_44 ,
& args -> V_72 ) ;
}
V_70:
F_24 ( & V_63 -> V_69 ) ;
F_40 ( & V_66 ) ;
F_41 ( V_63 , 0 ) ;
F_42 ( V_44 ) ;
V_16:
F_43 ( V_15 , & args -> V_67 , V_63 ,
& args -> V_68 , - V_64 ) ;
F_44 ( V_63 ) ;
return V_64 ;
}
static T_3 F_45 ( struct V_40 * V_15 ,
struct V_62 * args )
{
int V_76 ;
if ( args -> V_77 == V_78 )
V_76 = F_46 ( V_15 , & args -> V_79 , true ) ;
else
V_76 = F_47 ( V_15 , true ) ;
if ( V_76 != 0 )
return V_55 ;
return V_65 ;
}
static T_3 F_48 ( struct V_40 * V_15 ,
struct V_62 * args )
{
if ( args -> V_77 == V_80 )
return F_33 ( V_15 , args ) ;
return F_45 ( V_15 , args ) ;
}
T_1 F_49 ( void * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_62 * args = V_1 ;
T_3 V_7 = V_14 ;
if ( V_4 -> V_15 )
V_7 = F_48 ( V_4 -> V_15 , args ) ;
return F_50 ( V_7 ) ;
}
static void F_51 ( struct V_40 * V_15 )
{
struct V_62 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_77 = V_81 ;
F_48 ( V_15 , & args ) ;
}
T_1 F_52 ( void * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_82 * args = V_1 ;
int V_83 ;
T_1 V_7 = 0 ;
struct V_40 * V_15 = V_4 -> V_15 ;
struct V_41 * V_42 = NULL ;
if ( ! V_15 ) {
V_7 = F_50 ( V_14 ) ;
goto V_16;
}
for ( V_83 = 0 ; V_83 < args -> V_84 ; V_83 ++ ) {
struct V_85 * V_86 = & args -> V_87 [ V_83 ] ;
if ( ! V_42 ||
V_42 -> V_74 -> V_88 != V_86 -> V_89 ) {
F_9 () ;
F_19 (server, &clp->cl_superblocks, client_link)
if ( V_42 -> V_74 &&
V_42 -> V_74 -> V_88 == V_86 -> V_89 ) {
F_12 () ;
goto V_90;
}
F_12 () ;
continue;
}
V_90:
F_53 ( V_42 -> V_74 , V_15 , & V_86 -> V_91 ) ;
}
V_16:
F_54 ( args -> V_87 ) ;
return V_7 ;
}
static T_1
F_55 ( const struct V_92 * V_93 , const struct V_94 * V_95 ,
const struct V_96 * args )
{
if ( args -> V_97 > V_93 -> V_98 )
return F_2 ( V_99 ) ;
if ( args -> V_100 == V_95 -> V_101 ) {
if ( F_56 ( V_93 , V_95 -> V_102 ) )
return F_2 ( V_55 ) ;
if ( args -> V_103 == 0 )
return F_2 ( V_104 ) ;
return F_2 ( V_105 ) ;
}
if ( F_57 ( V_95 -> V_101 == 0xFFFFFFFFU ) ) {
if ( args -> V_100 == 1 )
return F_2 ( V_73 ) ;
} else if ( F_58 ( args -> V_100 == V_95 -> V_101 + 1 ) )
return F_2 ( V_73 ) ;
return F_2 ( V_106 ) ;
}
static bool F_59 ( struct V_40 * V_15 ,
T_4 V_107 ,
struct V_108 * V_109 )
{
bool V_13 = 0 ;
int V_83 , V_110 ;
struct V_111 * V_112 ;
struct V_92 * V_93 ;
struct V_108 * V_113 ;
struct V_114 * V_115 ;
V_112 = V_15 -> V_116 ;
V_93 = & V_112 -> V_117 ;
for ( V_83 = 0 ; V_83 < V_107 ; V_83 ++ ) {
V_113 = & V_109 [ V_83 ] ;
if ( memcmp ( V_112 -> V_118 . V_119 ,
V_113 -> V_120 . V_119 ,
V_121 ) != 0 )
continue;
for ( V_110 = 0 ; V_110 < V_113 -> V_122 ; V_110 ++ ) {
V_115 = & V_113 -> V_123 [ V_110 ] ;
V_13 = F_60 ( V_93 , V_115 -> V_124 ,
V_115 -> V_125 , V_126 >> 1 ) < 0 ;
if ( V_13 )
goto V_16;
}
}
V_16:
return V_13 ;
}
T_1 F_61 ( void * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_96 * args = V_1 ;
struct V_127 * V_7 = V_2 ;
struct V_92 * V_93 ;
struct V_94 * V_95 ;
struct V_40 * V_15 ;
int V_83 ;
T_1 V_13 = F_2 ( V_128 ) ;
V_15 = F_62 ( V_4 -> V_129 , args -> V_130 ,
& args -> V_131 , V_4 -> V_132 ) ;
if ( V_15 == NULL )
goto V_16;
if ( ! ( V_15 -> V_116 -> V_133 & V_134 ) )
goto V_16;
V_93 = & V_15 -> V_116 -> V_135 ;
memcpy ( & V_7 -> V_136 , & args -> V_131 ,
sizeof( V_7 -> V_136 ) ) ;
V_7 -> V_137 = args -> V_100 ;
V_7 -> V_138 = args -> V_97 ;
F_25 ( & V_93 -> V_139 ) ;
if ( F_32 ( V_140 , & V_93 -> V_141 ) ) {
V_13 = F_2 ( V_55 ) ;
if ( F_32 ( V_142 , & V_15 -> V_143 ) )
V_13 = F_2 ( V_128 ) ;
goto V_144;
}
V_13 = F_2 ( V_99 ) ;
V_95 = F_63 ( V_93 , args -> V_97 ) ;
if ( F_64 ( V_95 ) )
goto V_144;
V_7 -> V_145 = V_93 -> V_98 ;
V_7 -> V_146 = V_93 -> V_147 ;
V_13 = F_55 ( V_93 , V_95 , args ) ;
if ( V_13 )
goto V_144;
if ( ! F_65 ( V_93 , V_95 ) ) {
V_13 = F_2 ( V_55 ) ;
goto V_144;
}
V_4 -> V_95 = V_95 ;
if ( args -> V_103 != 0 ) {
V_13 = F_2 ( V_148 ) ;
goto V_144;
}
if ( F_59 ( V_15 , args -> V_149 , args -> V_150 ) ) {
V_13 = F_2 ( V_55 ) ;
goto V_144;
}
V_95 -> V_101 = args -> V_100 ;
V_144:
F_24 ( & V_93 -> V_139 ) ;
V_16:
V_4 -> V_15 = V_15 ;
for ( V_83 = 0 ; V_83 < args -> V_149 ; V_83 ++ )
F_54 ( args -> V_150 [ V_83 ] . V_123 ) ;
F_54 ( args -> V_150 ) ;
if ( V_13 == F_2 ( V_104 ) ) {
V_4 -> V_151 = V_13 ;
V_13 = 0 ;
} else
V_7 -> V_152 = V_13 ;
F_66 ( args , V_7 , V_13 ) ;
return V_13 ;
}
static bool
F_67 ( unsigned long V_153 )
{
return ( V_153 & ~ V_154 ) == 0 ;
}
T_1 F_68 ( void * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_155 * args = V_1 ;
T_1 V_13 ;
T_5 V_133 = 0 ;
V_13 = F_50 ( V_14 ) ;
if ( ! V_4 -> V_15 )
goto V_16;
F_3 ( L_4 ,
F_4 ( V_4 -> V_15 -> V_19 , V_20 ) ) ;
V_13 = F_50 ( V_156 ) ;
if ( ! F_67 ( args -> V_157 ) )
goto V_16;
V_13 = F_50 ( V_73 ) ;
if ( F_32 ( V_158 , ( const unsigned long * )
& args -> V_157 ) )
V_133 = V_159 ;
if ( F_32 ( V_160 , ( const unsigned long * )
& args -> V_157 ) )
V_133 |= V_22 ;
if ( F_32 ( V_161 , ( const unsigned long * )
& args -> V_157 ) )
F_51 ( V_4 -> V_15 ) ;
if ( V_133 )
F_69 ( V_4 -> V_15 , V_133 ) ;
V_16:
F_14 ( L_2 , V_34 , F_7 ( V_13 ) ) ;
return V_13 ;
}
T_1 F_70 ( void * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_162 * args = V_1 ;
struct V_92 * V_163 ;
T_1 V_13 ;
V_13 = F_2 ( V_14 ) ;
if ( ! V_4 -> V_15 )
goto V_16;
F_3 ( L_5 ,
F_4 ( V_4 -> V_15 -> V_19 , V_20 ) ,
args -> V_164 ) ;
V_163 = & V_4 -> V_15 -> V_116 -> V_117 ;
V_13 = F_2 ( V_73 ) ;
F_71 ( V_163 , args -> V_164 ) ;
F_72 ( V_4 -> V_15 ) ;
V_16:
F_14 ( L_2 , V_34 , F_7 ( V_13 ) ) ;
return V_13 ;
}
T_1 F_73 ( void * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_165 * args = V_1 ;
if ( ! V_4 -> V_15 )
return F_2 ( V_14 ) ;
F_3 ( L_6 ,
F_4 ( V_4 -> V_15 -> V_19 , V_20 ) ) ;
if ( args -> V_166 )
F_74 ( & V_4 -> V_15 -> V_167 , V_168 , 0 , args ) ;
return F_2 ( V_73 ) ;
}
