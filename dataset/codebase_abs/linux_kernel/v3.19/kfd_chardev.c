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
V_31 -> V_47 = false ;
V_31 -> V_48 = args -> V_33 ;
V_31 -> V_49 = args -> V_36 ;
V_31 -> V_50 = args -> V_38 ;
V_31 -> V_51 = args -> V_43 ;
V_31 -> V_52 = ( V_45 * ) args -> V_44 ;
V_31 -> V_53 = ( V_45 * ) args -> V_46 ;
if ( args -> V_54 == V_55 ||
args -> V_54 == V_56 )
V_31 -> type = V_57 ;
else
return - V_58 ;
if ( args -> V_54 == V_56 )
V_31 -> V_59 = V_60 ;
else
V_31 -> V_59 = V_61 ;
F_24 ( L_10 ,
V_31 -> V_48 , args -> V_33 ) ;
F_24 ( L_11 ,
V_31 -> V_49 , args -> V_36 ) ;
F_24 ( L_12 ,
V_31 -> V_50 , args -> V_38 ) ;
F_24 ( L_13 ,
V_31 -> V_51 , args -> V_43 ) ;
F_24 ( L_14 ,
( V_41 ) V_31 -> V_52 ,
( V_41 ) V_31 -> V_53 ) ;
F_24 ( L_15 , V_31 -> V_59 ) ;
return 0 ;
}
static int F_25 ( struct V_13 * V_14 , struct V_15 * V_23 ,
void * V_24 )
{
struct V_32 * args = V_24 ;
struct V_62 * V_63 ;
int V_1 = 0 ;
unsigned int V_64 ;
struct V_65 * V_66 ;
struct V_30 V_31 ;
memset ( & V_31 , 0 , sizeof( struct V_30 ) ) ;
F_24 ( L_16 ) ;
V_1 = F_20 ( & V_31 , args ) ;
if ( V_1 )
return V_1 ;
V_63 = F_26 ( args -> V_67 ) ;
if ( V_63 == NULL )
return - V_35 ;
F_27 ( & V_23 -> V_68 ) ;
V_66 = F_28 ( V_63 , V_23 ) ;
if ( F_5 ( V_66 ) ) {
V_1 = - V_69 ;
goto V_70;
}
F_24 ( L_17 ,
V_23 -> V_22 ,
V_63 -> V_71 ) ;
V_1 = F_29 ( & V_23 -> V_72 , V_63 , V_14 , & V_31 , 0 ,
V_57 , & V_64 ) ;
if ( V_1 != 0 )
goto V_73;
args -> V_64 = V_64 ;
args -> V_74 = args -> V_67 << V_75 ;
F_30 ( & V_23 -> V_68 ) ;
F_24 ( L_18 , args -> V_64 ) ;
F_24 ( L_19 ,
args -> V_38 ) ;
F_24 ( L_20 ,
args -> V_44 ) ;
F_24 ( L_21 ,
args -> V_46 ) ;
return 0 ;
V_73:
V_70:
F_30 ( & V_23 -> V_68 ) ;
return V_1 ;
}
static int F_31 ( struct V_13 * V_76 , struct V_15 * V_23 ,
void * V_24 )
{
int V_77 ;
struct V_78 * args = V_24 ;
F_24 ( L_22 ,
args -> V_64 ,
V_23 -> V_22 ) ;
F_27 ( & V_23 -> V_68 ) ;
V_77 = F_32 ( & V_23 -> V_72 , args -> V_64 ) ;
F_30 ( & V_23 -> V_68 ) ;
return V_77 ;
}
static int F_33 ( struct V_13 * V_76 , struct V_15 * V_23 ,
void * V_24 )
{
int V_77 ;
struct V_79 * args = V_24 ;
struct V_30 V_80 ;
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
V_80 . V_50 = args -> V_38 ;
V_80 . V_51 = args -> V_43 ;
V_80 . V_48 = args -> V_33 ;
V_80 . V_49 = args -> V_36 ;
F_24 ( L_23 ,
args -> V_64 , V_23 -> V_22 ) ;
F_27 ( & V_23 -> V_68 ) ;
V_77 = F_34 ( & V_23 -> V_72 , args -> V_64 , & V_80 ) ;
F_30 ( & V_23 -> V_68 ) ;
return V_77 ;
}
static int F_35 ( struct V_13 * V_14 ,
struct V_15 * V_23 , void * V_24 )
{
struct V_81 * args = V_24 ;
struct V_62 * V_63 ;
int V_1 = 0 ;
struct V_65 * V_66 ;
enum V_82 V_83 , V_84 ;
if ( args -> V_83 != V_85
&& args -> V_83 != V_86 ) {
return - V_35 ;
}
if ( args -> V_84 != V_85
&& args -> V_84 != V_86 ) {
return - V_35 ;
}
V_63 = F_26 ( args -> V_67 ) ;
if ( V_63 == NULL )
return - V_35 ;
F_27 ( & V_23 -> V_68 ) ;
V_66 = F_28 ( V_63 , V_23 ) ;
if ( F_5 ( V_66 ) ) {
V_1 = - V_69 ;
goto V_87;
}
V_83 = ( args -> V_83 == V_85 )
? V_88 : V_89 ;
V_84 =
( args -> V_84 == V_85 )
? V_88 : V_89 ;
if ( ! V_63 -> V_90 -> V_91 ( V_63 -> V_90 ,
& V_66 -> V_92 ,
V_83 ,
V_84 ,
( void V_40 * ) args -> V_93 ,
args -> V_94 ) )
V_1 = - V_35 ;
V_87:
F_30 ( & V_23 -> V_68 ) ;
return V_1 ;
}
static int F_36 ( struct V_13 * V_14 ,
struct V_15 * V_23 , void * V_24 )
{
struct V_95 * args = V_24 ;
struct V_62 * V_63 ;
struct V_96 time ;
V_63 = F_26 ( args -> V_67 ) ;
if ( V_63 == NULL )
return - V_35 ;
args -> V_97 = V_98 -> V_99 ( V_63 -> V_100 ) ;
F_37 ( & time ) ;
args -> V_101 = ( V_41 ) F_38 ( & time ) ;
F_39 ( & time ) ;
args -> V_102 = ( V_41 ) F_38 ( & time ) ;
args -> V_103 = 1000000000 ;
return 0 ;
}
static int F_40 ( struct V_13 * V_76 ,
struct V_15 * V_23 , void * V_24 )
{
struct V_104 * args = V_24 ;
struct V_105 * V_106 ;
struct V_65 * V_66 ;
F_18 ( V_9 , L_24 , V_23 -> V_22 ) ;
args -> V_107 = 0 ;
F_27 ( & V_23 -> V_68 ) ;
if ( F_41 ( V_23 ) ) {
V_66 = F_42 ( V_23 ) ;
do {
V_106 =
& args -> V_108 [ args -> V_107 ] ;
V_106 -> V_67 = V_66 -> V_63 -> V_71 ;
V_106 -> V_109 = V_66 -> V_109 ;
V_106 -> V_110 = V_66 -> V_110 ;
V_106 -> V_111 = V_66 -> V_111 ;
V_106 -> V_112 = V_66 -> V_112 ;
V_106 -> V_113 = V_66 -> V_113 ;
V_106 -> V_114 = V_66 -> V_114 ;
F_18 ( V_9 ,
L_25 , args -> V_107 ) ;
F_18 ( V_9 ,
L_26 , V_66 -> V_63 -> V_71 ) ;
F_18 ( V_9 ,
L_27 , V_66 -> V_109 ) ;
F_18 ( V_9 ,
L_28 , V_66 -> V_110 ) ;
F_18 ( V_9 ,
L_29 , V_66 -> V_111 ) ;
F_18 ( V_9 ,
L_30 , V_66 -> V_112 ) ;
F_18 ( V_9 ,
L_31 , V_66 -> V_113 ) ;
F_18 ( V_9 ,
L_32 , V_66 -> V_114 ) ;
args -> V_107 ++ ;
} while ( ( V_66 = F_43 ( V_23 , V_66 ) ) != NULL &&
( args -> V_107 < V_115 ) );
}
F_30 ( & V_23 -> V_68 ) ;
return 0 ;
}
static long F_44 ( struct V_13 * V_14 , unsigned int V_116 , unsigned long V_117 )
{
struct V_15 * V_16 ;
T_1 * V_118 ;
const struct V_119 * V_120 = NULL ;
unsigned int V_121 = F_45 ( V_116 ) ;
char V_122 [ 128 ] ;
char * V_123 = NULL ;
unsigned int V_124 , V_125 ;
int V_126 = - V_35 ;
if ( V_121 >= V_127 )
goto V_128;
if ( ( V_121 >= V_129 ) && ( V_121 < V_130 ) ) {
T_2 V_131 ;
V_120 = & V_132 [ V_121 ] ;
V_131 = F_46 ( V_120 -> V_116 ) ;
V_124 = V_125 = F_46 ( V_116 ) ;
if ( V_131 > V_125 )
V_125 = V_131 ;
V_116 = V_120 -> V_116 ;
} else
goto V_128;
F_18 ( V_9 , L_33 , V_116 , V_121 , V_117 ) ;
V_16 = F_47 ( V_19 ) ;
if ( F_5 ( V_16 ) ) {
F_18 ( V_9 , L_34 ) ;
goto V_128;
}
V_118 = V_120 -> V_118 ;
if ( F_48 ( ! V_118 ) ) {
F_18 ( V_9 , L_35 ) ;
V_126 = - V_35 ;
goto V_128;
}
if ( V_116 & ( V_133 | V_134 ) ) {
if ( V_125 <= sizeof( V_122 ) ) {
V_123 = V_122 ;
} else {
V_123 = F_49 ( V_125 , V_135 ) ;
if ( ! V_123 ) {
V_126 = - V_136 ;
goto V_128;
}
}
if ( V_125 > V_124 )
memset ( V_123 + V_124 , 0 , V_125 - V_124 ) ;
}
if ( V_116 & V_133 ) {
if ( F_50 ( V_123 , ( void V_40 * ) V_117 , V_124 ) != 0 ) {
V_126 = - V_42 ;
goto V_128;
}
} else if ( V_116 & V_134 ) {
memset ( V_123 , 0 , V_124 ) ;
}
V_126 = V_118 ( V_14 , V_16 , V_123 ) ;
if ( V_116 & V_134 )
if ( F_51 ( ( void V_40 * ) V_117 , V_123 , V_124 ) != 0 )
V_126 = - V_42 ;
V_128:
if ( ! V_120 )
F_18 ( V_9 , L_36 ,
F_52 ( V_19 ) , V_116 , V_121 ) ;
if ( V_123 != V_122 )
F_53 ( V_123 ) ;
if ( V_126 )
F_18 ( V_9 , L_37 , V_126 ) ;
return V_126 ;
}
static int F_54 ( struct V_13 * V_76 , struct V_137 * V_138 )
{
struct V_15 * V_16 ;
V_16 = F_47 ( V_19 ) ;
if ( F_5 ( V_16 ) )
return F_4 ( V_16 ) ;
return F_55 ( V_16 , V_138 ) ;
}
