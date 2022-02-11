int F_1 ( void )
{
int V_1 = 0 ;
V_2 = F_2 ( 0 , V_3 , & V_4 ) ;
V_1 = V_2 ;
if ( V_1 < 0 )
goto V_5;
V_6 = F_3 ( V_7 , V_3 ) ;
V_1 = F_4 ( V_6 ) ;
if ( F_5 ( V_6 ) )
goto V_8;
V_9 = F_6 ( V_6 , NULL ,
F_7 ( V_2 , 0 ) ,
NULL , V_3 ) ;
V_1 = F_4 ( V_9 ) ;
if ( F_5 ( V_9 ) )
goto V_10;
return 0 ;
V_10:
F_8 ( V_6 ) ;
V_8:
F_9 ( V_2 , V_3 ) ;
V_5:
return V_1 ;
}
void F_10 ( void )
{
F_11 ( V_6 , F_7 ( V_2 , 0 ) ) ;
F_8 ( V_6 ) ;
F_9 ( V_2 , V_3 ) ;
}
struct V_11 * F_12 ( void )
{
return V_9 ;
}
static int F_13 ( struct V_12 * V_12 , struct V_13 * V_14 )
{
struct V_15 * V_16 ;
bool V_17 ;
if ( F_14 ( V_12 ) != 0 )
return - V_18 ;
V_17 = F_15 () ;
if ( V_17 == true ) {
F_16 ( V_9 ,
L_1
L_2 ,
V_19 -> V_20 ) ;
return - V_21 ;
}
V_16 = F_17 ( V_19 ) ;
if ( F_5 ( V_16 ) )
return F_4 ( V_16 ) ;
F_18 ( V_9 , L_3 ,
V_16 -> V_22 , V_16 -> V_17 ) ;
return 0 ;
}
static int F_19 ( struct V_13 * V_14 , struct V_15 * V_23 ,
void * V_24 )
{
struct V_25 * args = V_24 ;
int V_1 = 0 ;
args -> V_26 = V_27 ;
args -> V_28 = V_29 ;
return V_1 ;
}
static int F_20 ( struct V_30 * V_31 ,
struct V_32 * args )
{
if ( args -> V_33 > V_34 ) {
F_21 ( L_4 ) ;
return - V_35 ;
}
if ( args -> V_36 > V_37 ) {
F_21 ( L_5 ) ;
return - V_35 ;
}
if ( ( args -> V_38 ) &&
( ! F_22 ( V_39 ,
( const void V_40 * ) args -> V_38 ,
sizeof( V_41 ) ) ) ) {
F_21 ( L_6 ) ;
return - V_42 ;
}
if ( ! F_23 ( args -> V_43 ) && ( args -> V_43 != 0 ) ) {
F_21 ( L_7 ) ;
return - V_35 ;
}
if ( ! F_22 ( V_39 ,
( const void V_40 * ) args -> V_44 ,
sizeof( V_45 ) ) ) {
F_21 ( L_8 ) ;
return - V_42 ;
}
if ( ! F_22 ( V_39 ,
( const void V_40 * ) args -> V_46 ,
sizeof( V_45 ) ) ) {
F_21 ( L_9 ) ;
return - V_42 ;
}
if ( args -> V_47 &&
! F_22 ( V_39 ,
( const void V_40 * ) args -> V_47 ,
sizeof( V_45 ) ) ) {
F_24 ( L_10 ) ;
return - V_42 ;
}
if ( args -> V_48 &&
! F_22 ( V_39 ,
( const void V_40 * ) args -> V_48 ,
sizeof( V_45 ) ) ) {
F_24 ( L_11 ) ;
return - V_42 ;
}
V_31 -> V_49 = false ;
V_31 -> V_50 = args -> V_33 ;
V_31 -> V_51 = args -> V_36 ;
V_31 -> V_52 = args -> V_38 ;
V_31 -> V_53 = args -> V_43 ;
V_31 -> V_54 = ( V_45 * ) args -> V_44 ;
V_31 -> V_55 = ( V_45 * ) args -> V_46 ;
V_31 -> V_56 = args -> V_47 ;
V_31 -> V_57 = args -> V_58 ;
V_31 -> V_59 =
args -> V_48 ;
V_31 -> V_60 = args -> V_61 ;
if ( args -> V_62 == V_63 ||
args -> V_62 == V_64 )
V_31 -> type = V_65 ;
else if ( args -> V_62 == V_66 )
V_31 -> type = V_67 ;
else
return - V_68 ;
if ( args -> V_62 == V_64 )
V_31 -> V_69 = V_70 ;
else
V_31 -> V_69 = V_71 ;
F_24 ( L_12 ,
V_31 -> V_50 , args -> V_33 ) ;
F_24 ( L_13 ,
V_31 -> V_51 , args -> V_36 ) ;
F_24 ( L_14 ,
V_31 -> V_52 , args -> V_38 ) ;
F_24 ( L_15 ,
V_31 -> V_53 , args -> V_43 ) ;
F_24 ( L_16 ,
( V_41 ) V_31 -> V_54 ,
( V_41 ) V_31 -> V_55 ) ;
F_24 ( L_17 , V_31 -> V_69 ) ;
F_24 ( L_18 , V_31 -> V_56 ) ;
F_24 ( L_19 ,
V_31 -> V_59 ) ;
return 0 ;
}
static int F_25 ( struct V_13 * V_14 , struct V_15 * V_23 ,
void * V_24 )
{
struct V_32 * args = V_24 ;
struct V_72 * V_73 ;
int V_1 = 0 ;
unsigned int V_74 ;
struct V_75 * V_76 ;
struct V_30 V_31 ;
memset ( & V_31 , 0 , sizeof( struct V_30 ) ) ;
F_24 ( L_20 ) ;
V_1 = F_20 ( & V_31 , args ) ;
if ( V_1 )
return V_1 ;
F_24 ( L_21 , args -> V_77 ) ;
V_73 = F_26 ( args -> V_77 ) ;
if ( V_73 == NULL ) {
F_24 ( L_22 , args -> V_77 ) ;
return - V_35 ;
}
F_27 ( & V_23 -> V_78 ) ;
V_76 = F_28 ( V_73 , V_23 ) ;
if ( F_5 ( V_76 ) ) {
V_1 = - V_79 ;
goto V_80;
}
F_24 ( L_23 ,
V_23 -> V_22 ,
V_73 -> V_81 ) ;
V_1 = F_29 ( & V_23 -> V_82 , V_73 , V_14 , & V_31 ,
0 , V_31 . type , & V_74 ) ;
if ( V_1 != 0 )
goto V_83;
args -> V_74 = V_74 ;
args -> V_84 = args -> V_77 << V_85 ;
F_30 ( & V_23 -> V_78 ) ;
F_24 ( L_24 , args -> V_74 ) ;
F_24 ( L_25 ,
args -> V_38 ) ;
F_24 ( L_26 ,
args -> V_44 ) ;
F_24 ( L_27 ,
args -> V_46 ) ;
return 0 ;
V_83:
V_80:
F_30 ( & V_23 -> V_78 ) ;
return V_1 ;
}
static int F_31 ( struct V_13 * V_86 , struct V_15 * V_23 ,
void * V_24 )
{
int V_87 ;
struct V_88 * args = V_24 ;
F_24 ( L_28 ,
args -> V_74 ,
V_23 -> V_22 ) ;
F_27 ( & V_23 -> V_78 ) ;
V_87 = F_32 ( & V_23 -> V_82 , args -> V_74 ) ;
F_30 ( & V_23 -> V_78 ) ;
return V_87 ;
}
static int F_33 ( struct V_13 * V_86 , struct V_15 * V_23 ,
void * V_24 )
{
int V_87 ;
struct V_89 * args = V_24 ;
struct V_30 V_90 ;
if ( args -> V_33 > V_34 ) {
F_21 ( L_4 ) ;
return - V_35 ;
}
if ( args -> V_36 > V_37 ) {
F_21 ( L_5 ) ;
return - V_35 ;
}
if ( ( args -> V_38 ) &&
( ! F_22 ( V_39 ,
( const void V_40 * ) args -> V_38 ,
sizeof( V_41 ) ) ) ) {
F_21 ( L_6 ) ;
return - V_42 ;
}
if ( ! F_23 ( args -> V_43 ) && ( args -> V_43 != 0 ) ) {
F_21 ( L_7 ) ;
return - V_35 ;
}
V_90 . V_52 = args -> V_38 ;
V_90 . V_53 = args -> V_43 ;
V_90 . V_50 = args -> V_33 ;
V_90 . V_51 = args -> V_36 ;
F_24 ( L_29 ,
args -> V_74 , V_23 -> V_22 ) ;
F_27 ( & V_23 -> V_78 ) ;
V_87 = F_34 ( & V_23 -> V_82 , args -> V_74 , & V_90 ) ;
F_30 ( & V_23 -> V_78 ) ;
return V_87 ;
}
static int F_35 ( struct V_13 * V_14 ,
struct V_15 * V_23 , void * V_24 )
{
struct V_91 * args = V_24 ;
struct V_72 * V_73 ;
int V_1 = 0 ;
struct V_75 * V_76 ;
enum V_92 V_93 , V_94 ;
if ( args -> V_93 != V_95
&& args -> V_93 != V_96 ) {
return - V_35 ;
}
if ( args -> V_94 != V_95
&& args -> V_94 != V_96 ) {
return - V_35 ;
}
V_73 = F_26 ( args -> V_77 ) ;
if ( V_73 == NULL )
return - V_35 ;
F_27 ( & V_23 -> V_78 ) ;
V_76 = F_28 ( V_73 , V_23 ) ;
if ( F_5 ( V_76 ) ) {
V_1 = - V_79 ;
goto V_97;
}
V_93 = ( args -> V_93 == V_95 )
? V_98 : V_99 ;
V_94 =
( args -> V_94 == V_95 )
? V_98 : V_99 ;
if ( ! V_73 -> V_100 -> V_101 . V_102 ( V_73 -> V_100 ,
& V_76 -> V_103 ,
V_93 ,
V_94 ,
( void V_40 * ) args -> V_104 ,
args -> V_105 ) )
V_1 = - V_35 ;
V_97:
F_30 ( & V_23 -> V_78 ) ;
return V_1 ;
}
static int F_36 ( struct V_13 * V_14 ,
struct V_15 * V_23 , void * V_24 )
{
struct V_106 * args = V_24 ;
struct V_72 * V_73 ;
struct V_107 time ;
V_73 = F_26 ( args -> V_77 ) ;
if ( V_73 == NULL )
return - V_35 ;
args -> V_108 =
V_73 -> V_109 -> V_110 ( V_73 -> V_111 ) ;
F_37 ( & time ) ;
args -> V_112 = ( V_41 ) F_38 ( & time ) ;
F_39 ( & time ) ;
args -> V_113 = ( V_41 ) F_38 ( & time ) ;
args -> V_114 = 1000000000 ;
return 0 ;
}
static int F_40 ( struct V_13 * V_86 ,
struct V_15 * V_23 , void * V_24 )
{
struct V_115 * args = V_24 ;
struct V_116 * V_117 ;
struct V_75 * V_76 ;
F_18 ( V_9 , L_30 , V_23 -> V_22 ) ;
args -> V_118 = 0 ;
F_27 ( & V_23 -> V_78 ) ;
if ( F_41 ( V_23 ) ) {
V_76 = F_42 ( V_23 ) ;
do {
V_117 =
& args -> V_119 [ args -> V_118 ] ;
V_117 -> V_77 = V_76 -> V_73 -> V_81 ;
V_117 -> V_120 = V_76 -> V_120 ;
V_117 -> V_121 = V_76 -> V_121 ;
V_117 -> V_122 = V_76 -> V_122 ;
V_117 -> V_123 = V_76 -> V_123 ;
V_117 -> V_124 = V_76 -> V_124 ;
V_117 -> V_125 = V_76 -> V_125 ;
F_18 ( V_9 ,
L_31 , args -> V_118 ) ;
F_18 ( V_9 ,
L_32 , V_76 -> V_73 -> V_81 ) ;
F_18 ( V_9 ,
L_33 , V_76 -> V_120 ) ;
F_18 ( V_9 ,
L_34 , V_76 -> V_121 ) ;
F_18 ( V_9 ,
L_35 , V_76 -> V_122 ) ;
F_18 ( V_9 ,
L_36 , V_76 -> V_123 ) ;
F_18 ( V_9 ,
L_37 , V_76 -> V_124 ) ;
F_18 ( V_9 ,
L_38 , V_76 -> V_125 ) ;
args -> V_118 ++ ;
} while ( ( V_76 = F_43 ( V_23 , V_76 ) ) != NULL &&
( args -> V_118 < V_126 ) );
}
F_30 ( & V_23 -> V_78 ) ;
return 0 ;
}
static long F_44 ( struct V_13 * V_14 , unsigned int V_127 , unsigned long V_128 )
{
struct V_15 * V_16 ;
T_1 * V_129 ;
const struct V_130 * V_131 = NULL ;
unsigned int V_132 = F_45 ( V_127 ) ;
char V_133 [ 128 ] ;
char * V_134 = NULL ;
unsigned int V_135 , V_136 ;
int V_137 = - V_35 ;
if ( V_132 >= V_138 )
goto V_139;
if ( ( V_132 >= V_140 ) && ( V_132 < V_141 ) ) {
T_2 V_142 ;
V_131 = & V_143 [ V_132 ] ;
V_142 = F_46 ( V_131 -> V_127 ) ;
V_135 = V_136 = F_46 ( V_127 ) ;
if ( V_142 > V_136 )
V_136 = V_142 ;
V_127 = V_131 -> V_127 ;
} else
goto V_139;
F_18 ( V_9 , L_39 , V_127 , V_132 , V_128 ) ;
V_16 = F_47 ( V_19 ) ;
if ( F_5 ( V_16 ) ) {
F_18 ( V_9 , L_40 ) ;
goto V_139;
}
V_129 = V_131 -> V_129 ;
if ( F_48 ( ! V_129 ) ) {
F_18 ( V_9 , L_41 ) ;
V_137 = - V_35 ;
goto V_139;
}
if ( V_127 & ( V_144 | V_145 ) ) {
if ( V_136 <= sizeof( V_133 ) ) {
V_134 = V_133 ;
} else {
V_134 = F_49 ( V_136 , V_146 ) ;
if ( ! V_134 ) {
V_137 = - V_147 ;
goto V_139;
}
}
if ( V_136 > V_135 )
memset ( V_134 + V_135 , 0 , V_136 - V_135 ) ;
}
if ( V_127 & V_144 ) {
if ( F_50 ( V_134 , ( void V_40 * ) V_128 , V_135 ) != 0 ) {
V_137 = - V_42 ;
goto V_139;
}
} else if ( V_127 & V_145 ) {
memset ( V_134 , 0 , V_135 ) ;
}
V_137 = V_129 ( V_14 , V_16 , V_134 ) ;
if ( V_127 & V_145 )
if ( F_51 ( ( void V_40 * ) V_128 , V_134 , V_135 ) != 0 )
V_137 = - V_42 ;
V_139:
if ( ! V_131 )
F_18 ( V_9 , L_42 ,
F_52 ( V_19 ) , V_127 , V_132 ) ;
if ( V_134 != V_133 )
F_53 ( V_134 ) ;
if ( V_137 )
F_18 ( V_9 , L_43 , V_137 ) ;
return V_137 ;
}
static int F_54 ( struct V_13 * V_86 , struct V_148 * V_149 )
{
struct V_15 * V_16 ;
V_16 = F_47 ( V_19 ) ;
if ( F_5 ( V_16 ) )
return F_4 ( V_16 ) ;
return F_55 ( V_16 , V_149 ) ;
}
