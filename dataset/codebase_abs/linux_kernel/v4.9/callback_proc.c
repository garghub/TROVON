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
static struct V_39 * F_18 ( struct V_40 * V_13 ,
struct V_41 * V_19 )
{
struct V_42 * V_43 ;
struct V_8 * V_9 ;
struct V_10 * V_44 ;
struct V_39 * V_45 ;
V_46:
F_19 (server, &clp->cl_superblocks, client_link) {
F_20 (lo, &server->layouts, plh_layouts) {
V_9 = F_8 ( V_45 -> V_47 ) ;
if ( F_21 ( V_19 , & V_9 -> V_19 ) )
continue;
if ( V_9 -> V_48 != V_45 )
continue;
V_44 = F_22 ( V_45 -> V_47 ) ;
if ( ! V_44 )
break;
F_23 ( & V_44 -> V_49 ) ;
if ( V_9 -> V_48 != V_45 ) {
F_24 ( & V_44 -> V_49 ) ;
F_13 ( V_44 ) ;
goto V_46;
}
F_25 ( V_45 ) ;
F_24 ( & V_44 -> V_49 ) ;
return V_45 ;
}
}
return NULL ;
}
static struct V_39 * F_26 ( struct V_40 * V_13 ,
struct V_41 * V_19 )
{
struct V_39 * V_45 ;
F_23 ( & V_13 -> V_50 ) ;
F_9 () ;
V_45 = F_18 ( V_13 , V_19 ) ;
F_12 () ;
F_24 ( & V_13 -> V_50 ) ;
return V_45 ;
}
static T_2 F_27 ( struct V_39 * V_45 ,
const T_3 * V_51 )
{
T_2 V_52 , V_53 ;
if ( ! F_28 ( V_45 ) )
return V_54 ;
if ( ! F_29 ( & V_45 -> V_55 , V_51 ) )
return V_37 ;
V_53 = F_30 ( V_51 -> V_56 ) ;
if ( F_31 ( V_57 , & V_45 -> V_58 ) &&
V_45 -> V_59 != 0 ) {
if ( V_53 < V_45 -> V_59 )
return V_60 ;
if ( V_53 > V_45 -> V_59 )
return V_54 ;
goto V_14;
}
V_52 = F_30 ( V_45 -> V_55 . V_56 ) ;
if ( V_53 > V_52 + 1 )
return V_54 ;
if ( V_53 <= V_52 )
return V_60 ;
V_14:
return V_61 ;
}
static T_2 F_32 ( struct V_40 * V_13 ,
struct V_62 * args )
{
struct V_10 * V_44 ;
struct V_39 * V_45 ;
T_2 V_63 = V_64 ;
F_33 ( V_65 ) ;
V_45 = F_26 ( V_13 , & args -> V_66 ) ;
if ( ! V_45 ) {
F_34 ( V_13 , & args -> V_66 , NULL ,
& args -> V_67 , - V_63 ) ;
goto V_14;
}
V_44 = V_45 -> V_47 ;
F_35 ( V_44 , false ) ;
F_23 ( & V_44 -> V_49 ) ;
V_63 = F_27 ( V_45 , & args -> V_67 ) ;
if ( V_63 != V_61 )
goto V_68;
F_36 ( V_45 , & args -> V_67 , true ) ;
if ( F_31 ( V_69 , & V_45 -> V_58 ) ) {
V_63 = V_54 ;
goto V_68;
}
if ( F_37 ( V_45 , & V_65 ,
& args -> V_70 ,
F_30 ( args -> V_67 . V_56 ) ) ) {
V_63 = V_71 ;
goto V_68;
}
V_63 = V_64 ;
if ( F_38 ( V_44 ) -> V_72 -> V_73 ) {
F_38 ( V_44 ) -> V_72 -> V_73 ( V_45 ,
& args -> V_70 ) ;
}
V_68:
F_24 ( & V_44 -> V_49 ) ;
F_39 ( & V_65 ) ;
F_40 ( V_44 , 0 ) ;
F_41 ( V_45 ) ;
F_34 ( V_13 , & args -> V_66 , V_44 ,
& args -> V_67 , - V_63 ) ;
F_13 ( V_44 ) ;
V_14:
return V_63 ;
}
static T_2 F_42 ( struct V_40 * V_13 ,
struct V_62 * args )
{
int V_74 ;
if ( args -> V_75 == V_76 )
V_74 = F_43 ( V_13 , & args -> V_77 , true ) ;
else
V_74 = F_44 ( V_13 , true ) ;
if ( V_74 != 0 )
return V_54 ;
return V_64 ;
}
static T_2 F_45 ( struct V_40 * V_13 ,
struct V_62 * args )
{
T_2 V_3 ;
F_14 ( L_4 , V_32 , args -> V_75 ) ;
if ( args -> V_75 == V_78 )
V_3 = F_32 ( V_13 , args ) ;
else
V_3 = F_42 ( V_13 , args ) ;
F_14 ( L_5 , V_32 , V_3 ) ;
return V_3 ;
}
T_1 F_46 ( struct V_62 * args ,
void * V_34 , struct V_4 * V_5 )
{
T_2 V_3 ;
F_14 ( L_6 , V_32 ) ;
if ( V_5 -> V_13 )
V_3 = F_45 ( V_5 -> V_13 , args ) ;
else
V_3 = V_12 ;
F_14 ( L_2 , V_32 , V_3 ) ;
return F_47 ( V_3 ) ;
}
static void F_48 ( struct V_40 * V_13 )
{
struct V_62 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_75 = V_79 ;
F_45 ( V_13 , & args ) ;
}
T_1 F_49 ( struct V_80 * args ,
void * V_34 , struct V_4 * V_5 )
{
int V_81 ;
T_1 V_3 = 0 ;
struct V_40 * V_13 = V_5 -> V_13 ;
struct V_42 * V_43 = NULL ;
F_14 ( L_6 , V_32 ) ;
if ( ! V_13 ) {
V_3 = F_47 ( V_12 ) ;
goto V_14;
}
for ( V_81 = 0 ; V_81 < args -> V_82 ; V_81 ++ ) {
struct V_83 * V_84 = & args -> V_85 [ V_81 ] ;
if ( ! V_43 ||
V_43 -> V_72 -> V_86 != V_84 -> V_87 ) {
F_9 () ;
F_19 (server, &clp->cl_superblocks, client_link)
if ( V_43 -> V_72 &&
V_43 -> V_72 -> V_86 == V_84 -> V_87 ) {
F_12 () ;
goto V_88;
}
F_12 () ;
F_14 ( L_7 ,
V_32 , V_84 -> V_87 ) ;
continue;
}
V_88:
F_50 ( V_43 -> V_72 , V_13 , & V_84 -> V_89 ) ;
}
V_14:
F_51 ( args -> V_85 ) ;
F_14 ( L_8 ,
V_32 , F_30 ( V_3 ) ) ;
return V_3 ;
}
static T_1
F_52 ( const struct V_90 * V_91 , const struct V_92 * V_93 ,
const struct V_94 * args )
{
F_14 ( L_9 ,
V_32 , args -> V_95 , args -> V_96 , V_93 -> V_97 ) ;
if ( args -> V_95 > V_91 -> V_98 )
return F_2 ( V_99 ) ;
if ( args -> V_96 == V_93 -> V_97 ) {
F_14 ( L_10 ,
V_32 , args -> V_96 ) ;
if ( F_53 ( V_91 , V_93 -> V_100 ) )
return F_2 ( V_54 ) ;
if ( args -> V_101 == 0 )
return F_2 ( V_102 ) ;
return F_2 ( V_103 ) ;
}
if ( F_54 ( V_93 -> V_97 == 0xFFFFFFFFU ) ) {
if ( args -> V_96 == 1 )
return F_2 ( V_71 ) ;
} else if ( F_55 ( args -> V_96 == V_93 -> V_97 + 1 ) )
return F_2 ( V_71 ) ;
return F_2 ( V_104 ) ;
}
static bool F_56 ( struct V_40 * V_13 ,
T_4 V_105 ,
struct V_106 * V_107 )
{
bool V_11 = 0 ;
int V_81 , V_108 ;
struct V_109 * V_110 ;
struct V_90 * V_91 ;
struct V_106 * V_111 ;
struct V_112 * V_113 ;
V_110 = V_13 -> V_114 ;
V_91 = & V_110 -> V_115 ;
for ( V_81 = 0 ; V_81 < V_105 ; V_81 ++ ) {
V_111 = & V_107 [ V_81 ] ;
if ( memcmp ( V_110 -> V_116 . V_117 ,
V_111 -> V_118 . V_117 ,
V_119 ) != 0 )
continue;
for ( V_108 = 0 ; V_108 < V_111 -> V_120 ; V_108 ++ ) {
V_113 = & V_111 -> V_121 [ V_108 ] ;
F_14 ( L_11
L_12 , V_32 ,
( ( T_2 * ) & V_111 -> V_118 . V_117 ) [ 0 ] ,
( ( T_2 * ) & V_111 -> V_118 . V_117 ) [ 1 ] ,
( ( T_2 * ) & V_111 -> V_118 . V_117 ) [ 2 ] ,
( ( T_2 * ) & V_111 -> V_118 . V_117 ) [ 3 ] ,
V_113 -> V_122 , V_113 -> V_123 ) ;
V_11 = F_57 ( V_91 , V_113 -> V_123 ,
V_113 -> V_122 , V_124 >> 1 ) < 0 ;
if ( V_11 )
goto V_14;
}
}
V_14:
return V_11 ;
}
T_1 F_58 ( struct V_94 * args ,
struct V_125 * V_3 ,
struct V_4 * V_5 )
{
struct V_90 * V_91 ;
struct V_92 * V_93 ;
struct V_40 * V_13 ;
int V_81 ;
T_1 V_11 = F_2 ( V_126 ) ;
V_13 = F_59 ( V_5 -> V_127 , args -> V_128 ,
& args -> V_129 , V_5 -> V_130 ) ;
if ( V_13 == NULL )
goto V_14;
if ( ! ( V_13 -> V_114 -> V_131 & V_132 ) )
goto V_14;
V_91 = & V_13 -> V_114 -> V_133 ;
memcpy ( & V_3 -> V_134 , & args -> V_129 ,
sizeof( V_3 -> V_134 ) ) ;
V_3 -> V_135 = args -> V_96 ;
V_3 -> V_136 = args -> V_95 ;
F_23 ( & V_91 -> V_137 ) ;
if ( F_31 ( V_138 , & V_91 -> V_139 ) ) {
V_11 = F_2 ( V_54 ) ;
if ( F_31 ( V_140 , & V_13 -> V_141 ) )
V_11 = F_2 ( V_126 ) ;
goto V_142;
}
V_11 = F_2 ( V_99 ) ;
V_93 = F_60 ( V_91 , args -> V_95 ) ;
if ( F_61 ( V_93 ) )
goto V_142;
V_3 -> V_143 = V_91 -> V_98 ;
V_3 -> V_144 = V_91 -> V_145 ;
V_11 = F_52 ( V_91 , V_93 , args ) ;
if ( V_11 )
goto V_142;
if ( ! F_62 ( V_91 , V_93 ) ) {
V_11 = F_2 ( V_54 ) ;
goto V_142;
}
V_5 -> V_93 = V_93 ;
if ( args -> V_101 != 0 ) {
V_11 = F_2 ( V_146 ) ;
goto V_142;
}
if ( F_56 ( V_13 , args -> V_147 , args -> V_148 ) ) {
V_11 = F_2 ( V_54 ) ;
goto V_142;
}
V_93 -> V_97 = args -> V_96 ;
V_142:
F_24 ( & V_91 -> V_137 ) ;
V_14:
V_5 -> V_13 = V_13 ;
for ( V_81 = 0 ; V_81 < args -> V_147 ; V_81 ++ )
F_51 ( args -> V_148 [ V_81 ] . V_121 ) ;
F_51 ( args -> V_148 ) ;
if ( V_11 == F_2 ( V_102 ) ) {
V_5 -> V_149 = V_11 ;
V_11 = 0 ;
} else
V_3 -> V_150 = V_11 ;
F_63 ( args , V_3 , V_11 ) ;
F_14 ( L_13 , V_32 ,
F_7 ( V_11 ) , F_7 ( V_3 -> V_150 ) ) ;
return V_11 ;
}
static bool
F_64 ( unsigned long V_151 )
{
return ( V_151 & ~ V_152 ) == 0 ;
}
T_1 F_65 ( struct V_153 * args , void * V_34 ,
struct V_4 * V_5 )
{
T_1 V_11 ;
T_5 V_131 = 0 ;
V_11 = F_47 ( V_12 ) ;
if ( ! V_5 -> V_13 )
goto V_14;
F_3 ( L_14 ,
F_4 ( V_5 -> V_13 -> V_17 , V_18 ) ) ;
V_11 = F_47 ( V_154 ) ;
if ( ! F_64 ( args -> V_155 ) )
goto V_14;
V_11 = F_47 ( V_71 ) ;
if ( F_31 ( V_156 , ( const unsigned long * )
& args -> V_155 ) )
V_131 = V_157 ;
if ( F_31 ( V_158 , ( const unsigned long * )
& args -> V_155 ) )
V_131 |= V_20 ;
if ( F_31 ( V_159 , ( const unsigned long * )
& args -> V_155 ) )
F_48 ( V_5 -> V_13 ) ;
if ( V_131 )
F_66 ( V_5 -> V_13 , V_131 ) ;
V_14:
F_14 ( L_2 , V_32 , F_7 ( V_11 ) ) ;
return V_11 ;
}
T_1 F_67 ( struct V_160 * args , void * V_34 ,
struct V_4 * V_5 )
{
struct V_90 * V_161 ;
T_1 V_11 ;
V_11 = F_2 ( V_12 ) ;
if ( ! V_5 -> V_13 )
goto V_14;
F_3 ( L_15 ,
F_4 ( V_5 -> V_13 -> V_17 , V_18 ) ,
args -> V_162 ) ;
V_161 = & V_5 -> V_13 -> V_114 -> V_115 ;
V_11 = F_2 ( V_71 ) ;
F_68 ( V_161 , args -> V_162 ) ;
F_69 ( V_5 -> V_13 ) ;
V_14:
F_14 ( L_2 , V_32 , F_7 ( V_11 ) ) ;
return V_11 ;
}
T_1 F_70 ( struct V_163 * args , void * V_34 ,
struct V_4 * V_5 )
{
if ( ! V_5 -> V_13 )
return F_2 ( V_12 ) ;
F_3 ( L_16 ,
F_4 ( V_5 -> V_13 -> V_17 , V_18 ) ) ;
if ( args -> V_164 )
F_71 ( & V_5 -> V_13 -> V_165 , V_166 , 0 , args ) ;
return F_2 ( V_71 ) ;
}
