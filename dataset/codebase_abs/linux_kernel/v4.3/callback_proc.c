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
if ( V_10 == NULL )
goto V_14;
switch ( F_16 ( V_10 , & args -> V_35 ) ) {
case 0 :
V_3 = 0 ;
break;
case - V_36 :
V_3 = F_2 ( V_37 ) ;
break;
default:
V_3 = F_2 ( V_38 ) ;
}
F_17 ( V_10 , - F_7 ( V_3 ) ) ;
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
static T_3 F_28 ( struct V_40 * V_13 ,
struct V_51 * args )
{
struct V_10 * V_44 ;
struct V_39 * V_45 ;
T_3 V_52 = V_53 ;
F_29 ( V_54 ) ;
V_45 = F_27 ( V_13 , & args -> V_55 , & args -> V_56 ) ;
if ( ! V_45 )
goto V_14;
V_44 = V_45 -> V_47 ;
F_24 ( & V_44 -> V_48 ) ;
F_30 ( V_45 , & args -> V_56 , true ) ;
F_25 ( & V_44 -> V_48 ) ;
F_31 ( V_44 , false ) ;
F_24 ( & V_44 -> V_48 ) ;
if ( F_32 ( V_57 , & V_45 -> V_58 ) ||
F_33 ( V_45 , & V_54 ,
& args -> V_59 ) ) {
V_52 = V_60 ;
goto V_61;
}
if ( F_34 ( V_44 ) -> V_62 -> V_63 ) {
F_34 ( V_44 ) -> V_62 -> V_63 ( V_45 ,
& args -> V_59 ) ;
}
V_61:
F_25 ( & V_44 -> V_48 ) ;
F_35 ( & V_54 ) ;
F_36 ( V_45 ) ;
F_37 ( V_13 , & args -> V_55 , V_44 , - V_52 ) ;
F_13 ( V_44 ) ;
V_14:
return V_52 ;
}
static T_3 F_38 ( struct V_40 * V_13 ,
struct V_51 * args )
{
int V_64 ;
if ( args -> V_65 == V_66 )
V_64 = F_39 ( V_13 , & args -> V_67 , true ) ;
else
V_64 = F_40 ( V_13 , true ) ;
if ( V_64 != 0 )
return V_60 ;
return V_53 ;
}
static T_3 F_41 ( struct V_40 * V_13 ,
struct V_51 * args )
{
T_3 V_3 ;
F_14 ( L_4 , V_32 , args -> V_65 ) ;
if ( args -> V_65 == V_68 )
V_3 = F_28 ( V_13 , args ) ;
else
V_3 = F_38 ( V_13 , args ) ;
F_14 ( L_5 , V_32 , V_3 ) ;
return V_3 ;
}
T_1 F_42 ( struct V_51 * args ,
void * V_34 , struct V_4 * V_5 )
{
T_3 V_3 ;
F_14 ( L_6 , V_32 ) ;
if ( V_5 -> V_13 )
V_3 = F_41 ( V_5 -> V_13 , args ) ;
else
V_3 = V_12 ;
F_14 ( L_2 , V_32 , V_3 ) ;
return F_43 ( V_3 ) ;
}
static void F_44 ( struct V_40 * V_13 )
{
struct V_51 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_65 = V_69 ;
F_41 ( V_13 , & args ) ;
}
T_1 F_45 ( struct V_70 * args ,
void * V_34 , struct V_4 * V_5 )
{
int V_71 ;
T_1 V_3 = 0 ;
struct V_40 * V_13 = V_5 -> V_13 ;
struct V_42 * V_43 = NULL ;
F_14 ( L_6 , V_32 ) ;
if ( ! V_13 ) {
V_3 = F_43 ( V_12 ) ;
goto V_14;
}
for ( V_71 = 0 ; V_71 < args -> V_72 ; V_71 ++ ) {
struct V_73 * V_74 = & args -> V_75 [ V_71 ] ;
if ( ! V_43 ||
V_43 -> V_62 -> V_76 != V_74 -> V_77 ) {
F_9 () ;
F_19 (server, &clp->cl_superblocks, client_link)
if ( V_43 -> V_62 &&
V_43 -> V_62 -> V_76 == V_74 -> V_77 ) {
F_12 () ;
goto V_78;
}
F_12 () ;
F_14 ( L_7 ,
V_32 , V_74 -> V_77 ) ;
continue;
}
V_78:
F_46 ( V_43 -> V_62 , V_13 , & V_74 -> V_79 ) ;
}
V_14:
F_47 ( args -> V_75 ) ;
F_14 ( L_8 ,
V_32 , F_48 ( V_3 ) ) ;
return V_3 ;
}
static T_1
F_49 ( struct V_80 * V_81 , struct V_82 * args )
{
struct V_83 * V_84 ;
F_14 ( L_9 ,
V_32 , args -> V_85 , args -> V_86 ) ;
if ( args -> V_85 >= V_87 )
return F_2 ( V_88 ) ;
V_84 = V_81 -> V_89 + args -> V_85 ;
F_14 ( L_10 , V_32 , V_84 -> V_90 ) ;
if ( F_50 ( args -> V_86 == V_84 -> V_90 + 1 ) )
goto V_91;
if ( args -> V_86 == V_84 -> V_90 ) {
F_14 ( L_11 ,
V_32 , args -> V_86 ) ;
if ( args -> V_92 == 0 )
return F_2 ( V_93 ) ;
else if ( args -> V_92 == 1 )
return F_2 ( V_94 ) ;
}
if ( args -> V_86 == 1 && ( V_84 -> V_90 + 1 ) == 0 ) {
V_84 -> V_90 = 1 ;
goto V_91;
}
return F_2 ( V_95 ) ;
V_91:
V_81 -> V_96 = args -> V_85 ;
return F_2 ( V_97 ) ;
}
static bool F_51 ( struct V_40 * V_13 ,
T_4 V_98 ,
struct V_99 * V_100 )
{
bool V_11 = 0 ;
int V_71 , V_101 ;
struct V_102 * V_103 ;
struct V_80 * V_81 ;
struct V_99 * V_104 ;
struct V_105 * V_106 ;
V_103 = V_13 -> V_107 ;
V_81 = & V_103 -> V_108 ;
for ( V_71 = 0 ; V_71 < V_98 ; V_71 ++ ) {
V_104 = & V_100 [ V_71 ] ;
if ( memcmp ( V_103 -> V_109 . V_110 ,
V_104 -> V_111 . V_110 ,
V_112 ) != 0 )
continue;
for ( V_101 = 0 ; V_101 < V_104 -> V_113 ; V_101 ++ ) {
V_106 = & V_104 -> V_114 [ V_101 ] ;
F_14 ( L_12
L_13 , V_32 ,
( ( T_3 * ) & V_104 -> V_111 . V_110 ) [ 0 ] ,
( ( T_3 * ) & V_104 -> V_111 . V_110 ) [ 1 ] ,
( ( T_3 * ) & V_104 -> V_111 . V_110 ) [ 2 ] ,
( ( T_3 * ) & V_104 -> V_111 . V_110 ) [ 3 ] ,
V_106 -> V_115 , V_106 -> V_116 ) ;
F_24 ( & V_81 -> V_117 ) ;
V_11 = ( F_32 ( V_106 -> V_116 , V_81 -> V_118 ) &&
V_81 -> V_89 [ V_106 -> V_116 ] . V_90 ==
V_106 -> V_115 ) ;
F_25 ( & V_81 -> V_117 ) ;
if ( V_11 )
goto V_14;
}
}
V_14:
return V_11 ;
}
T_1 F_52 ( struct V_82 * args ,
struct V_119 * V_3 ,
struct V_4 * V_5 )
{
struct V_80 * V_81 ;
struct V_83 * V_84 ;
struct V_40 * V_13 ;
int V_71 ;
T_1 V_11 = F_2 ( V_120 ) ;
V_13 = F_53 ( V_5 -> V_121 , args -> V_122 ,
& args -> V_123 , V_5 -> V_124 ) ;
if ( V_13 == NULL )
goto V_14;
if ( ! ( V_13 -> V_107 -> V_125 & V_126 ) )
goto V_14;
V_81 = & V_13 -> V_107 -> V_127 ;
V_84 = V_81 -> V_89 + args -> V_85 ;
F_24 ( & V_81 -> V_117 ) ;
if ( F_32 ( V_128 , & V_81 -> V_129 ) ) {
V_11 = F_2 ( V_60 ) ;
if ( F_32 ( V_130 , & V_13 -> V_131 ) )
V_11 = F_2 ( V_120 ) ;
goto V_132;
}
memcpy ( & V_3 -> V_133 , & args -> V_123 ,
sizeof( V_3 -> V_133 ) ) ;
V_3 -> V_134 = args -> V_86 ;
V_3 -> V_135 = args -> V_85 ;
V_3 -> V_136 = V_87 - 1 ;
V_3 -> V_137 = V_87 - 1 ;
V_11 = F_49 ( V_81 , args ) ;
if ( V_11 )
goto V_132;
V_5 -> V_138 = args -> V_85 ;
if ( F_51 ( V_13 , args -> V_139 , args -> V_140 ) ) {
V_11 = F_2 ( V_60 ) ;
goto V_132;
}
V_84 -> V_90 ++ ;
V_132:
F_25 ( & V_81 -> V_117 ) ;
V_14:
V_5 -> V_13 = V_13 ;
for ( V_71 = 0 ; V_71 < args -> V_139 ; V_71 ++ )
F_47 ( args -> V_140 [ V_71 ] . V_114 ) ;
F_47 ( args -> V_140 ) ;
if ( V_11 == F_2 ( V_93 ) ) {
V_5 -> V_141 = V_11 ;
V_11 = 0 ;
} else
V_3 -> V_142 = V_11 ;
F_54 ( args , V_3 , V_11 ) ;
F_14 ( L_14 , V_32 ,
F_7 ( V_11 ) , F_7 ( V_3 -> V_142 ) ) ;
return V_11 ;
}
static bool
F_55 ( unsigned long V_143 )
{
return ( V_143 & ~ V_144 ) == 0 ;
}
T_1 F_56 ( struct V_145 * args , void * V_34 ,
struct V_4 * V_5 )
{
T_1 V_11 ;
T_5 V_125 = 0 ;
V_11 = F_43 ( V_12 ) ;
if ( ! V_5 -> V_13 )
goto V_14;
F_3 ( L_15 ,
F_4 ( V_5 -> V_13 -> V_17 , V_18 ) ) ;
V_11 = F_43 ( V_146 ) ;
if ( ! F_55 ( args -> V_147 ) )
goto V_14;
V_11 = F_43 ( V_97 ) ;
if ( F_32 ( V_148 , ( const unsigned long * )
& args -> V_147 ) )
V_125 = V_149 ;
if ( F_32 ( V_150 , ( const unsigned long * )
& args -> V_147 ) )
V_125 |= V_20 ;
if ( F_32 ( V_151 , ( const unsigned long * )
& args -> V_147 ) )
F_44 ( V_5 -> V_13 ) ;
if ( V_125 )
F_57 ( V_5 -> V_13 , V_125 ) ;
V_14:
F_14 ( L_2 , V_32 , F_7 ( V_11 ) ) ;
return V_11 ;
}
T_1 F_58 ( struct V_152 * args , void * V_34 ,
struct V_4 * V_5 )
{
struct V_80 * V_153 ;
T_1 V_11 ;
V_11 = F_2 ( V_12 ) ;
if ( ! V_5 -> V_13 )
goto V_14;
F_3 ( L_16 ,
F_4 ( V_5 -> V_13 -> V_17 , V_18 ) ,
args -> V_154 ) ;
V_153 = & V_5 -> V_13 -> V_107 -> V_108 ;
V_11 = F_2 ( V_97 ) ;
F_59 ( V_153 , args -> V_154 ) ;
F_60 ( V_5 -> V_13 ) ;
V_14:
F_14 ( L_2 , V_32 , F_7 ( V_11 ) ) ;
return V_11 ;
}
