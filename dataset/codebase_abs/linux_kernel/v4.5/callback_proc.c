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
struct V_41 * V_19 , T_2 * V_35 )
{
struct V_42 * V_43 ;
struct V_10 * V_44 ;
struct V_39 * V_45 ;
F_19 (server, &clp->cl_superblocks, client_link) {
F_20 (lo, &server->layouts, plh_layouts) {
if ( ! F_21 ( & V_45 -> V_46 , V_35 ) )
continue;
if ( F_22 ( V_19 , & F_8 ( V_45 -> V_47 ) -> V_19 ) )
continue;
V_44 = F_23 ( V_45 -> V_47 ) ;
if ( ! V_44 )
break;
F_24 ( & V_44 -> V_48 ) ;
if ( F_8 ( V_44 ) -> V_49 != V_45 ) {
F_25 ( & V_44 -> V_48 ) ;
F_13 ( V_44 ) ;
break;
}
F_26 ( V_45 ) ;
F_25 ( & V_44 -> V_48 ) ;
return V_45 ;
}
}
return NULL ;
}
static struct V_39 * F_27 ( struct V_40 * V_13 ,
struct V_41 * V_19 , T_2 * V_35 )
{
struct V_39 * V_45 ;
F_24 ( & V_13 -> V_50 ) ;
F_9 () ;
V_45 = F_18 ( V_13 , V_19 , V_35 ) ;
F_12 () ;
F_25 ( & V_13 -> V_50 ) ;
return V_45 ;
}
static bool F_28 ( struct V_39 * V_45 ,
const T_2 * V_51 )
{
T_3 V_52 , V_53 ;
V_52 = F_29 ( V_45 -> V_46 . V_54 ) ;
V_53 = F_29 ( V_51 -> V_54 ) ;
if ( V_53 > V_52 + 1 )
return false ;
return true ;
}
static T_3 F_30 ( struct V_40 * V_13 ,
struct V_55 * args )
{
struct V_10 * V_44 ;
struct V_39 * V_45 ;
T_3 V_56 = V_57 ;
F_31 ( V_58 ) ;
V_45 = F_27 ( V_13 , & args -> V_59 , & args -> V_60 ) ;
if ( ! V_45 ) {
F_32 ( V_13 , & args -> V_59 , NULL ,
& args -> V_60 , - V_56 ) ;
goto V_14;
}
V_44 = V_45 -> V_47 ;
F_24 ( & V_44 -> V_48 ) ;
if ( ! F_28 ( V_45 , & args -> V_60 ) ) {
V_56 = V_61 ;
goto V_62;
}
F_33 ( V_45 , & args -> V_60 , true ) ;
F_25 ( & V_44 -> V_48 ) ;
F_34 ( V_44 , false ) ;
F_24 ( & V_44 -> V_48 ) ;
if ( F_35 ( V_63 , & V_45 -> V_64 ) ) {
V_56 = V_61 ;
goto V_62;
}
if ( F_36 ( V_45 , & V_58 ,
& args -> V_65 ) ) {
V_56 = V_66 ;
goto V_62;
}
if ( F_37 ( V_44 ) -> V_67 -> V_68 ) {
F_37 ( V_44 ) -> V_67 -> V_68 ( V_45 ,
& args -> V_65 ) ;
}
F_38 ( V_45 ) ;
V_62:
F_25 ( & V_44 -> V_48 ) ;
F_39 ( & V_58 ) ;
F_40 ( V_44 , 0 ) ;
F_41 ( V_45 ) ;
F_32 ( V_13 , & args -> V_59 , V_44 ,
& args -> V_60 , - V_56 ) ;
F_13 ( V_44 ) ;
V_14:
return V_56 ;
}
static T_3 F_42 ( struct V_40 * V_13 ,
struct V_55 * args )
{
int V_69 ;
if ( args -> V_70 == V_71 )
V_69 = F_43 ( V_13 , & args -> V_72 , true ) ;
else
V_69 = F_44 ( V_13 , true ) ;
if ( V_69 != 0 )
return V_61 ;
return V_57 ;
}
static T_3 F_45 ( struct V_40 * V_13 ,
struct V_55 * args )
{
T_3 V_3 ;
F_14 ( L_4 , V_32 , args -> V_70 ) ;
if ( args -> V_70 == V_73 )
V_3 = F_30 ( V_13 , args ) ;
else
V_3 = F_42 ( V_13 , args ) ;
F_14 ( L_5 , V_32 , V_3 ) ;
return V_3 ;
}
T_1 F_46 ( struct V_55 * args ,
void * V_34 , struct V_4 * V_5 )
{
T_3 V_3 ;
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
struct V_55 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_70 = V_74 ;
F_45 ( V_13 , & args ) ;
}
T_1 F_49 ( struct V_75 * args ,
void * V_34 , struct V_4 * V_5 )
{
int V_76 ;
T_1 V_3 = 0 ;
struct V_40 * V_13 = V_5 -> V_13 ;
struct V_42 * V_43 = NULL ;
F_14 ( L_6 , V_32 ) ;
if ( ! V_13 ) {
V_3 = F_47 ( V_12 ) ;
goto V_14;
}
for ( V_76 = 0 ; V_76 < args -> V_77 ; V_76 ++ ) {
struct V_78 * V_79 = & args -> V_80 [ V_76 ] ;
if ( ! V_43 ||
V_43 -> V_67 -> V_81 != V_79 -> V_82 ) {
F_9 () ;
F_19 (server, &clp->cl_superblocks, client_link)
if ( V_43 -> V_67 &&
V_43 -> V_67 -> V_81 == V_79 -> V_82 ) {
F_12 () ;
goto V_83;
}
F_12 () ;
F_14 ( L_7 ,
V_32 , V_79 -> V_82 ) ;
continue;
}
V_83:
F_50 ( V_43 -> V_67 , V_13 , & V_79 -> V_84 ) ;
}
V_14:
F_51 ( args -> V_80 ) ;
F_14 ( L_8 ,
V_32 , F_29 ( V_3 ) ) ;
return V_3 ;
}
static T_1
F_52 ( struct V_85 * V_86 , struct V_87 * args )
{
struct V_88 * V_89 ;
F_14 ( L_9 ,
V_32 , args -> V_90 , args -> V_91 ) ;
if ( args -> V_90 >= V_92 )
return F_2 ( V_93 ) ;
V_89 = V_86 -> V_94 + args -> V_90 ;
F_14 ( L_10 , V_32 , V_89 -> V_95 ) ;
if ( F_53 ( args -> V_91 == V_89 -> V_95 + 1 ) )
goto V_96;
if ( args -> V_91 == V_89 -> V_95 ) {
F_14 ( L_11 ,
V_32 , args -> V_91 ) ;
if ( args -> V_97 == 0 )
return F_2 ( V_98 ) ;
else if ( args -> V_97 == 1 )
return F_2 ( V_99 ) ;
}
if ( args -> V_91 == 1 && ( V_89 -> V_95 + 1 ) == 0 ) {
V_89 -> V_95 = 1 ;
goto V_96;
}
return F_2 ( V_100 ) ;
V_96:
V_86 -> V_101 = args -> V_90 ;
return F_2 ( V_66 ) ;
}
static bool F_54 ( struct V_40 * V_13 ,
T_4 V_102 ,
struct V_103 * V_104 )
{
bool V_11 = 0 ;
int V_76 , V_105 ;
struct V_106 * V_107 ;
struct V_85 * V_86 ;
struct V_103 * V_108 ;
struct V_109 * V_110 ;
V_107 = V_13 -> V_111 ;
V_86 = & V_107 -> V_112 ;
for ( V_76 = 0 ; V_76 < V_102 ; V_76 ++ ) {
V_108 = & V_104 [ V_76 ] ;
if ( memcmp ( V_107 -> V_113 . V_114 ,
V_108 -> V_115 . V_114 ,
V_116 ) != 0 )
continue;
for ( V_105 = 0 ; V_105 < V_108 -> V_117 ; V_105 ++ ) {
V_110 = & V_108 -> V_118 [ V_105 ] ;
F_14 ( L_12
L_13 , V_32 ,
( ( T_3 * ) & V_108 -> V_115 . V_114 ) [ 0 ] ,
( ( T_3 * ) & V_108 -> V_115 . V_114 ) [ 1 ] ,
( ( T_3 * ) & V_108 -> V_115 . V_114 ) [ 2 ] ,
( ( T_3 * ) & V_108 -> V_115 . V_114 ) [ 3 ] ,
V_110 -> V_119 , V_110 -> V_120 ) ;
F_24 ( & V_86 -> V_121 ) ;
V_11 = ( F_35 ( V_110 -> V_120 , V_86 -> V_122 ) &&
V_86 -> V_94 [ V_110 -> V_120 ] . V_95 ==
V_110 -> V_119 ) ;
F_25 ( & V_86 -> V_121 ) ;
if ( V_11 )
goto V_14;
}
}
V_14:
return V_11 ;
}
T_1 F_55 ( struct V_87 * args ,
struct V_123 * V_3 ,
struct V_4 * V_5 )
{
struct V_85 * V_86 ;
struct V_88 * V_89 ;
struct V_40 * V_13 ;
int V_76 ;
T_1 V_11 = F_2 ( V_124 ) ;
V_13 = F_56 ( V_5 -> V_125 , args -> V_126 ,
& args -> V_127 , V_5 -> V_128 ) ;
if ( V_13 == NULL )
goto V_14;
if ( ! ( V_13 -> V_111 -> V_129 & V_130 ) )
goto V_14;
V_86 = & V_13 -> V_111 -> V_131 ;
V_89 = V_86 -> V_94 + args -> V_90 ;
F_24 ( & V_86 -> V_121 ) ;
if ( F_35 ( V_132 , & V_86 -> V_133 ) ) {
V_11 = F_2 ( V_61 ) ;
if ( F_35 ( V_134 , & V_13 -> V_135 ) )
V_11 = F_2 ( V_124 ) ;
goto V_136;
}
memcpy ( & V_3 -> V_137 , & args -> V_127 ,
sizeof( V_3 -> V_137 ) ) ;
V_3 -> V_138 = args -> V_91 ;
V_3 -> V_139 = args -> V_90 ;
V_3 -> V_140 = V_92 - 1 ;
V_3 -> V_141 = V_92 - 1 ;
V_11 = F_52 ( V_86 , args ) ;
if ( V_11 )
goto V_136;
V_5 -> V_142 = args -> V_90 ;
if ( F_54 ( V_13 , args -> V_143 , args -> V_144 ) ) {
V_11 = F_2 ( V_61 ) ;
goto V_136;
}
V_89 -> V_95 ++ ;
V_136:
F_25 ( & V_86 -> V_121 ) ;
V_14:
V_5 -> V_13 = V_13 ;
for ( V_76 = 0 ; V_76 < args -> V_143 ; V_76 ++ )
F_51 ( args -> V_144 [ V_76 ] . V_118 ) ;
F_51 ( args -> V_144 ) ;
if ( V_11 == F_2 ( V_98 ) ) {
V_5 -> V_145 = V_11 ;
V_11 = 0 ;
} else
V_3 -> V_146 = V_11 ;
F_57 ( args , V_3 , V_11 ) ;
F_14 ( L_14 , V_32 ,
F_7 ( V_11 ) , F_7 ( V_3 -> V_146 ) ) ;
return V_11 ;
}
static bool
F_58 ( unsigned long V_147 )
{
return ( V_147 & ~ V_148 ) == 0 ;
}
T_1 F_59 ( struct V_149 * args , void * V_34 ,
struct V_4 * V_5 )
{
T_1 V_11 ;
T_5 V_129 = 0 ;
V_11 = F_47 ( V_12 ) ;
if ( ! V_5 -> V_13 )
goto V_14;
F_3 ( L_15 ,
F_4 ( V_5 -> V_13 -> V_17 , V_18 ) ) ;
V_11 = F_47 ( V_150 ) ;
if ( ! F_58 ( args -> V_151 ) )
goto V_14;
V_11 = F_47 ( V_66 ) ;
if ( F_35 ( V_152 , ( const unsigned long * )
& args -> V_151 ) )
V_129 = V_153 ;
if ( F_35 ( V_154 , ( const unsigned long * )
& args -> V_151 ) )
V_129 |= V_20 ;
if ( F_35 ( V_155 , ( const unsigned long * )
& args -> V_151 ) )
F_48 ( V_5 -> V_13 ) ;
if ( V_129 )
F_60 ( V_5 -> V_13 , V_129 ) ;
V_14:
F_14 ( L_2 , V_32 , F_7 ( V_11 ) ) ;
return V_11 ;
}
T_1 F_61 ( struct V_156 * args , void * V_34 ,
struct V_4 * V_5 )
{
struct V_85 * V_157 ;
T_1 V_11 ;
V_11 = F_2 ( V_12 ) ;
if ( ! V_5 -> V_13 )
goto V_14;
F_3 ( L_16 ,
F_4 ( V_5 -> V_13 -> V_17 , V_18 ) ,
args -> V_158 ) ;
V_157 = & V_5 -> V_13 -> V_111 -> V_112 ;
V_11 = F_2 ( V_66 ) ;
F_62 ( V_157 , args -> V_158 ) ;
F_63 ( V_5 -> V_13 ) ;
V_14:
F_14 ( L_2 , V_32 , F_7 ( V_11 ) ) ;
return V_11 ;
}
