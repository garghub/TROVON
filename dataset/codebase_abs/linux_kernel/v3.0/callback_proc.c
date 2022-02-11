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
struct V_10 * V_44 ;
bool V_45 = false ;
T_3 V_46 = V_47 ;
F_17 ( V_48 ) ;
F_18 ( & V_13 -> V_49 ) ;
F_19 (lo, &clp->cl_layouts, plh_layouts) {
if ( F_20 ( & args -> V_50 ,
& F_6 ( V_43 -> V_51 ) -> V_19 ) )
continue;
V_44 = F_21 ( V_43 -> V_51 ) ;
if ( ! V_44 )
continue;
V_45 = true ;
F_22 ( V_43 ) ;
break;
}
F_23 ( & V_13 -> V_49 ) ;
if ( ! V_45 )
return V_47 ;
F_18 ( & V_44 -> V_52 ) ;
if ( F_24 ( V_53 , & V_43 -> V_54 ) ||
F_25 ( V_43 , & V_48 ,
& args -> V_55 ) )
V_46 = V_56 ;
else
V_46 = V_47 ;
F_26 ( V_43 , & args -> V_57 , true ) ;
F_23 ( & V_44 -> V_52 ) ;
F_27 ( & V_48 ) ;
F_28 ( V_43 ) ;
F_11 ( V_44 ) ;
return V_46 ;
}
static T_3 F_29 ( struct V_40 * V_13 ,
struct V_41 * args )
{
struct V_42 * V_43 ;
struct V_10 * V_44 ;
T_3 V_46 = V_47 ;
struct V_42 * V_58 ;
F_17 ( V_59 ) ;
F_17 ( V_48 ) ;
struct V_60 V_61 = {
. V_62 = V_63 ,
. V_64 = 0 ,
. V_65 = V_66 ,
} ;
F_18 ( & V_13 -> V_49 ) ;
F_19 (lo, &clp->cl_layouts, plh_layouts) {
if ( ( args -> V_67 == V_68 ) &&
memcmp ( & F_30 ( V_43 -> V_51 ) -> V_69 ,
& args -> V_70 , sizeof( struct V_71 ) ) )
continue;
if ( ! F_21 ( V_43 -> V_51 ) )
continue;
F_22 ( V_43 ) ;
F_31 ( ! F_32 ( & V_43 -> V_72 ) ) ;
F_33 ( & V_43 -> V_72 , & V_59 ) ;
}
F_23 ( & V_13 -> V_49 ) ;
F_34 (lo, tmp,
&recall_list, plh_bulk_recall) {
V_44 = V_43 -> V_51 ;
F_18 ( & V_44 -> V_52 ) ;
F_35 ( V_53 , & V_43 -> V_54 ) ;
if ( F_25 ( V_43 , & V_48 , & V_61 ) )
V_46 = V_56 ;
F_36 ( & V_43 -> V_72 ) ;
F_23 ( & V_44 -> V_52 ) ;
F_27 ( & V_48 ) ;
F_28 ( V_43 ) ;
F_11 ( V_44 ) ;
}
return V_46 ;
}
static T_3 F_37 ( struct V_40 * V_13 ,
struct V_41 * args )
{
T_3 V_3 = V_56 ;
F_3 ( L_4 , V_32 , args -> V_67 ) ;
if ( F_38 ( V_73 , & V_13 -> V_74 ) )
goto V_14;
if ( args -> V_67 == V_75 )
V_3 = F_16 ( V_13 , args ) ;
else
V_3 = F_29 ( V_13 , args ) ;
F_39 ( V_73 , & V_13 -> V_74 ) ;
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
args . V_67 = V_76 ;
F_37 ( V_13 , & args ) ;
}
T_1 F_43 ( struct V_77 * args ,
void * V_34 , struct V_4 * V_5 )
{
int V_78 ;
T_1 V_3 = 0 ;
struct V_40 * V_13 = V_5 -> V_13 ;
struct V_79 * V_80 = NULL ;
F_3 ( L_6 , V_32 ) ;
if ( ! V_13 ) {
V_3 = F_41 ( V_12 ) ;
goto V_14;
}
for ( V_78 = 0 ; V_78 < args -> V_81 ; V_78 ++ ) {
struct V_82 * V_83 = & args -> V_84 [ V_78 ] ;
if ( ! V_80 ||
V_80 -> V_85 -> V_86 != V_83 -> V_87 ) {
F_7 () ;
F_44 (server, &clp->cl_superblocks, client_link)
if ( V_80 -> V_85 &&
V_80 -> V_85 -> V_86 == V_83 -> V_87 ) {
F_10 () ;
goto V_45;
}
F_10 () ;
F_3 ( L_7 ,
V_32 , V_83 -> V_87 ) ;
continue;
}
V_45:
if ( V_83 -> V_88 == V_89 )
F_3 ( L_8
L_9 , V_32 ) ;
F_45 ( V_80 -> V_85 , V_13 , & V_83 -> V_90 ) ;
}
V_14:
F_46 ( args -> V_84 ) ;
F_3 ( L_10 ,
V_32 , F_47 ( V_3 ) ) ;
return V_3 ;
}
int F_48 ( struct V_6 * V_7 , const T_2 * V_35 )
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
F_49 ( struct V_94 * V_95 , struct V_96 * args )
{
struct V_97 * V_98 ;
F_3 ( L_11 ,
V_32 , args -> V_99 , args -> V_100 ) ;
if ( args -> V_99 > V_101 )
return F_2 ( V_102 ) ;
V_98 = V_95 -> V_103 + args -> V_99 ;
F_3 ( L_12 , V_32 , V_98 -> V_104 ) ;
if ( F_50 ( args -> V_100 == V_98 -> V_104 + 1 ) ) {
V_98 -> V_104 ++ ;
return F_2 ( V_105 ) ;
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
return F_2 ( V_105 ) ;
}
return F_2 ( V_109 ) ;
}
static bool F_51 ( struct V_40 * V_13 ,
T_4 V_110 ,
struct V_111 * V_112 )
{
bool V_11 = 0 ;
int V_78 , V_113 ;
struct V_114 * V_115 ;
struct V_94 * V_95 ;
struct V_111 * V_116 ;
struct V_117 * V_118 ;
V_115 = V_13 -> V_119 ;
V_95 = & V_115 -> V_120 ;
for ( V_78 = 0 ; V_78 < V_110 ; V_78 ++ ) {
V_116 = & V_112 [ V_78 ] ;
if ( memcmp ( V_115 -> V_121 . V_39 ,
V_116 -> V_122 . V_39 ,
V_123 ) != 0 )
continue;
for ( V_113 = 0 ; V_113 < V_116 -> V_124 ; V_113 ++ ) {
V_118 = & V_116 -> V_125 [ V_113 ] ;
F_3 ( L_14
L_15 , V_32 ,
( ( T_3 * ) & V_116 -> V_122 . V_39 ) [ 0 ] ,
( ( T_3 * ) & V_116 -> V_122 . V_39 ) [ 1 ] ,
( ( T_3 * ) & V_116 -> V_122 . V_39 ) [ 2 ] ,
( ( T_3 * ) & V_116 -> V_122 . V_39 ) [ 3 ] ,
V_118 -> V_126 , V_118 -> V_127 ) ;
F_18 ( & V_95 -> V_128 ) ;
V_11 = ( F_24 ( V_118 -> V_127 , V_95 -> V_129 ) &&
V_95 -> V_103 [ V_118 -> V_127 ] . V_104 ==
V_118 -> V_126 ) ;
F_23 ( & V_95 -> V_128 ) ;
if ( V_11 )
goto V_14;
}
}
V_14:
return V_11 ;
}
T_1 F_52 ( struct V_96 * args ,
struct V_130 * V_3 ,
struct V_4 * V_5 )
{
struct V_40 * V_13 ;
int V_78 ;
T_1 V_11 = F_2 ( V_131 ) ;
V_5 -> V_13 = NULL ;
V_13 = F_53 ( args -> V_132 , & args -> V_133 ) ;
if ( V_13 == NULL )
goto V_14;
if ( F_24 ( V_134 , & V_13 -> V_119 -> V_135 ) ) {
V_11 = V_56 ;
goto V_14;
}
V_11 = F_49 ( & V_13 -> V_119 -> V_136 , args ) ;
if ( V_11 )
goto V_14;
if ( F_51 ( V_13 , args -> V_137 , args -> V_138 ) ) {
V_11 = F_2 ( V_56 ) ;
goto V_14;
}
memcpy ( & V_3 -> V_139 , & args -> V_133 ,
sizeof( V_3 -> V_139 ) ) ;
V_3 -> V_140 = args -> V_100 ;
V_3 -> V_141 = args -> V_99 ;
V_3 -> V_142 = V_101 - 1 ;
V_3 -> V_143 = V_101 - 1 ;
F_54 ( V_13 ) ;
V_14:
V_5 -> V_13 = V_13 ;
for ( V_78 = 0 ; V_78 < args -> V_137 ; V_78 ++ )
F_46 ( args -> V_138 [ V_78 ] . V_125 ) ;
F_46 ( args -> V_138 ) ;
if ( V_11 == F_2 ( V_107 ) ) {
V_5 -> V_144 = V_11 ;
V_11 = 0 ;
} else
V_3 -> V_145 = V_11 ;
F_3 ( L_16 , V_32 ,
F_12 ( V_11 ) , F_12 ( V_3 -> V_145 ) ) ;
return V_11 ;
}
static bool
F_55 ( unsigned long V_146 )
{
return ( V_146 & ~ V_147 ) == 0 ;
}
T_1 F_56 ( struct V_148 * args , void * V_34 ,
struct V_4 * V_5 )
{
T_1 V_11 ;
T_5 V_149 = 0 ;
V_11 = F_41 ( V_12 ) ;
if ( ! V_5 -> V_13 )
goto V_14;
F_3 ( L_17 ,
F_4 ( V_5 -> V_13 -> V_17 , V_18 ) ) ;
V_11 = F_41 ( V_150 ) ;
if ( ! F_55 ( args -> V_151 ) )
goto V_14;
V_11 = F_41 ( V_105 ) ;
if ( F_24 ( V_152 , ( const unsigned long * )
& args -> V_151 ) )
V_149 = V_153 ;
if ( F_24 ( V_154 , ( const unsigned long * )
& args -> V_151 ) )
V_149 |= V_20 ;
if ( F_24 ( V_155 , ( const unsigned long * )
& args -> V_151 ) )
F_42 ( V_5 -> V_13 ) ;
if ( V_149 )
F_57 ( V_5 -> V_13 , V_149 ) ;
V_14:
F_3 ( L_2 , V_32 , F_12 ( V_11 ) ) ;
return V_11 ;
}
T_1 F_58 ( struct V_156 * args , void * V_34 ,
struct V_4 * V_5 )
{
struct V_94 * V_157 ;
T_1 V_11 ;
V_11 = F_2 ( V_12 ) ;
if ( ! V_5 -> V_13 )
goto V_14;
F_3 ( L_18 ,
F_4 ( V_5 -> V_13 -> V_17 , V_18 ) ,
args -> V_158 ) ;
V_157 = & V_5 -> V_13 -> V_119 -> V_120 ;
V_11 = F_2 ( V_159 ) ;
if ( args -> V_158 > V_157 -> V_160 ||
args -> V_158 < 1 )
goto V_14;
V_11 = F_2 ( V_105 ) ;
if ( args -> V_158 == V_157 -> V_160 )
goto V_14;
V_157 -> V_161 = args -> V_158 ;
F_59 ( V_5 -> V_13 ) ;
V_14:
F_3 ( L_2 , V_32 , F_12 ( V_11 ) ) ;
return V_11 ;
}
