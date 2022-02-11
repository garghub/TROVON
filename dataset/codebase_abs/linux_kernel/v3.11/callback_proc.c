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
int V_60 ;
if ( args -> V_61 == V_62 )
V_60 = F_33 ( V_13 , & args -> V_63 , true ) ;
else
V_60 = F_34 ( V_13 , true ) ;
if ( V_60 != 0 )
return V_58 ;
return V_52 ;
}
static T_2 F_35 ( struct V_40 * V_13 ,
struct V_50 * args )
{
T_2 V_3 ;
F_12 ( L_4 , V_32 , args -> V_61 ) ;
if ( args -> V_61 == V_64 )
V_3 = F_25 ( V_13 , args ) ;
else
V_3 = F_32 ( V_13 , args ) ;
F_12 ( L_5 , V_32 , V_3 ) ;
return V_3 ;
}
T_1 F_36 ( struct V_50 * args ,
void * V_34 , struct V_4 * V_5 )
{
T_2 V_3 ;
F_12 ( L_6 , V_32 ) ;
if ( V_5 -> V_13 )
V_3 = F_35 ( V_5 -> V_13 , args ) ;
else
V_3 = V_12 ;
F_12 ( L_2 , V_32 , V_3 ) ;
return F_37 ( V_3 ) ;
}
static void F_38 ( struct V_40 * V_13 )
{
struct V_50 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_61 = V_65 ;
F_35 ( V_13 , & args ) ;
}
T_1 F_39 ( struct V_66 * args ,
void * V_34 , struct V_4 * V_5 )
{
int V_67 ;
T_1 V_3 = 0 ;
struct V_40 * V_13 = V_5 -> V_13 ;
struct V_42 * V_43 = NULL ;
F_12 ( L_6 , V_32 ) ;
if ( ! V_13 ) {
V_3 = F_37 ( V_12 ) ;
goto V_14;
}
for ( V_67 = 0 ; V_67 < args -> V_68 ; V_67 ++ ) {
struct V_69 * V_70 = & args -> V_71 [ V_67 ] ;
if ( ! V_43 ||
V_43 -> V_72 -> V_73 != V_70 -> V_74 ) {
F_7 () ;
F_17 (server, &clp->cl_superblocks, client_link)
if ( V_43 -> V_72 &&
V_43 -> V_72 -> V_73 == V_70 -> V_74 ) {
F_10 () ;
goto V_75;
}
F_10 () ;
F_12 ( L_7 ,
V_32 , V_70 -> V_74 ) ;
continue;
}
V_75:
if ( V_70 -> V_76 == V_77 )
F_12 ( L_8
L_9 , V_32 ) ;
F_40 ( V_43 -> V_72 , V_13 , & V_70 -> V_78 ) ;
}
V_14:
F_41 ( args -> V_71 ) ;
F_12 ( L_10 ,
V_32 , F_42 ( V_3 ) ) ;
return V_3 ;
}
static T_1
F_43 ( struct V_79 * V_80 , struct V_81 * args )
{
struct V_82 * V_83 ;
F_12 ( L_11 ,
V_32 , args -> V_84 , args -> V_85 ) ;
if ( args -> V_84 >= V_86 )
return F_2 ( V_87 ) ;
V_83 = V_80 -> V_88 + args -> V_84 ;
F_12 ( L_12 , V_32 , V_83 -> V_89 ) ;
if ( F_44 ( args -> V_85 == V_83 -> V_89 + 1 ) ) {
V_83 -> V_89 ++ ;
goto V_90;
}
if ( args -> V_85 == V_83 -> V_89 ) {
F_12 ( L_13 ,
V_32 , args -> V_85 ) ;
if ( args -> V_91 == 0 )
return F_2 ( V_92 ) ;
else if ( args -> V_91 == 1 )
return F_2 ( V_93 ) ;
}
if ( args -> V_85 == 1 && ( V_83 -> V_89 + 1 ) == 0 ) {
V_83 -> V_89 = 1 ;
goto V_90;
}
return F_2 ( V_94 ) ;
V_90:
V_80 -> V_95 = args -> V_84 ;
return F_2 ( V_96 ) ;
}
static bool F_45 ( struct V_40 * V_13 ,
T_3 V_97 ,
struct V_98 * V_99 )
{
bool V_11 = 0 ;
int V_67 , V_100 ;
struct V_101 * V_102 ;
struct V_79 * V_80 ;
struct V_98 * V_103 ;
struct V_104 * V_105 ;
V_102 = V_13 -> V_106 ;
V_80 = & V_102 -> V_107 ;
for ( V_67 = 0 ; V_67 < V_97 ; V_67 ++ ) {
V_103 = & V_99 [ V_67 ] ;
if ( memcmp ( V_102 -> V_108 . V_109 ,
V_103 -> V_110 . V_109 ,
V_111 ) != 0 )
continue;
for ( V_100 = 0 ; V_100 < V_103 -> V_112 ; V_100 ++ ) {
V_105 = & V_103 -> V_113 [ V_100 ] ;
F_12 ( L_14
L_15 , V_32 ,
( ( T_2 * ) & V_103 -> V_110 . V_109 ) [ 0 ] ,
( ( T_2 * ) & V_103 -> V_110 . V_109 ) [ 1 ] ,
( ( T_2 * ) & V_103 -> V_110 . V_109 ) [ 2 ] ,
( ( T_2 * ) & V_103 -> V_110 . V_109 ) [ 3 ] ,
V_105 -> V_114 , V_105 -> V_115 ) ;
F_21 ( & V_80 -> V_116 ) ;
V_11 = ( F_27 ( V_105 -> V_115 , V_80 -> V_117 ) &&
V_80 -> V_88 [ V_105 -> V_115 ] . V_89 ==
V_105 -> V_114 ) ;
F_22 ( & V_80 -> V_116 ) ;
if ( V_11 )
goto V_14;
}
}
V_14:
return V_11 ;
}
T_1 F_46 ( struct V_81 * args ,
struct V_118 * V_3 ,
struct V_4 * V_5 )
{
struct V_79 * V_80 ;
struct V_40 * V_13 ;
int V_67 ;
T_1 V_11 = F_2 ( V_119 ) ;
V_13 = F_47 ( V_5 -> V_120 , args -> V_121 ,
& args -> V_122 , V_5 -> V_123 ) ;
if ( V_13 == NULL )
goto V_14;
V_80 = & V_13 -> V_106 -> V_124 ;
F_21 ( & V_80 -> V_116 ) ;
if ( F_27 ( V_125 , & V_80 -> V_126 ) ) {
F_22 ( & V_80 -> V_116 ) ;
V_11 = F_2 ( V_58 ) ;
if ( F_27 ( V_127 , & V_13 -> V_128 ) )
V_11 = F_2 ( V_119 ) ;
goto V_14;
}
V_11 = F_43 ( & V_13 -> V_106 -> V_124 , args ) ;
F_22 ( & V_80 -> V_116 ) ;
if ( V_11 )
goto V_14;
V_5 -> V_129 = args -> V_84 ;
if ( F_45 ( V_13 , args -> V_130 , args -> V_131 ) ) {
V_11 = F_2 ( V_58 ) ;
goto V_14;
}
memcpy ( & V_3 -> V_132 , & args -> V_122 ,
sizeof( V_3 -> V_132 ) ) ;
V_3 -> V_133 = args -> V_85 ;
V_3 -> V_134 = args -> V_84 ;
V_3 -> V_135 = V_86 - 1 ;
V_3 -> V_136 = V_86 - 1 ;
V_14:
V_5 -> V_13 = V_13 ;
for ( V_67 = 0 ; V_67 < args -> V_130 ; V_67 ++ )
F_41 ( args -> V_131 [ V_67 ] . V_113 ) ;
F_41 ( args -> V_131 ) ;
if ( V_11 == F_2 ( V_92 ) ) {
V_5 -> V_137 = V_11 ;
V_11 = 0 ;
} else
V_3 -> V_138 = V_11 ;
F_12 ( L_16 , V_32 ,
F_13 ( V_11 ) , F_13 ( V_3 -> V_138 ) ) ;
return V_11 ;
}
static bool
F_48 ( unsigned long V_139 )
{
return ( V_139 & ~ V_140 ) == 0 ;
}
T_1 F_49 ( struct V_141 * args , void * V_34 ,
struct V_4 * V_5 )
{
T_1 V_11 ;
T_4 V_142 = 0 ;
V_11 = F_37 ( V_12 ) ;
if ( ! V_5 -> V_13 )
goto V_14;
F_3 ( L_17 ,
F_4 ( V_5 -> V_13 -> V_17 , V_18 ) ) ;
V_11 = F_37 ( V_143 ) ;
if ( ! F_48 ( args -> V_144 ) )
goto V_14;
V_11 = F_37 ( V_96 ) ;
if ( F_27 ( V_145 , ( const unsigned long * )
& args -> V_144 ) )
V_142 = V_146 ;
if ( F_27 ( V_147 , ( const unsigned long * )
& args -> V_144 ) )
V_142 |= V_20 ;
if ( F_27 ( V_148 , ( const unsigned long * )
& args -> V_144 ) )
F_38 ( V_5 -> V_13 ) ;
if ( V_142 )
F_50 ( V_5 -> V_13 , V_142 ) ;
V_14:
F_12 ( L_2 , V_32 , F_13 ( V_11 ) ) ;
return V_11 ;
}
T_1 F_51 ( struct V_149 * args , void * V_34 ,
struct V_4 * V_5 )
{
struct V_79 * V_150 ;
T_1 V_11 ;
V_11 = F_2 ( V_12 ) ;
if ( ! V_5 -> V_13 )
goto V_14;
F_3 ( L_18 ,
F_4 ( V_5 -> V_13 -> V_17 , V_18 ) ,
args -> V_151 ) ;
V_150 = & V_5 -> V_13 -> V_106 -> V_107 ;
V_11 = F_2 ( V_96 ) ;
F_52 ( V_150 , args -> V_151 ) ;
F_53 ( V_5 -> V_13 ) ;
V_14:
F_12 ( L_2 , V_32 , F_13 ( V_11 ) ) ;
return V_11 ;
}
