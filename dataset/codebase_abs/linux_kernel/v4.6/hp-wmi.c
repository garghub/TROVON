static int F_1 ( int V_1 , int V_2 , void * V_3 ,
int V_4 , int V_5 )
{
struct V_6 * V_6 ;
int V_7 ;
union V_8 * V_9 ;
struct V_10 args = {
. V_11 = 0x55434553 ,
. V_12 = V_2 ? 0x2 : 0x1 ,
. V_13 = V_1 ,
. V_14 = V_4 ,
. V_15 = 0 ,
} ;
struct V_16 V_17 = { sizeof( struct V_10 ) , & args } ;
struct V_16 V_18 = { V_19 , NULL } ;
T_1 V_20 ;
if ( F_2 ( V_4 > sizeof( args . V_15 ) ) )
return - V_21 ;
memcpy ( & args . V_15 , V_3 , V_4 ) ;
F_3 ( V_22 , 0 , 0x3 , & V_17 , & V_18 ) ;
V_9 = V_18 . V_23 ;
if ( ! V_9 )
return - V_21 ;
else if ( V_9 -> type != V_24 ) {
F_4 ( V_9 ) ;
return - V_21 ;
}
V_6 = (struct V_6 * ) V_9 -> V_3 . V_23 ;
V_20 = V_6 -> V_25 ;
if ( V_20 ) {
if ( V_20 != V_26 )
F_5 ( L_1 , V_1 , V_20 ) ;
F_4 ( V_9 ) ;
return V_20 ;
}
if ( ! V_5 ) {
F_4 ( V_9 ) ;
return 0 ;
}
V_7 = F_6 ( V_5 , ( int ) ( V_9 -> V_3 . V_27 - sizeof( * V_6 ) ) ) ;
memcpy ( V_3 , V_9 -> V_3 . V_23 + sizeof( * V_6 ) , V_7 ) ;
memset ( V_3 + V_7 , 0 , V_5 - V_7 ) ;
F_4 ( V_9 ) ;
return 0 ;
}
static int F_7 ( void )
{
int V_28 = 0 ;
int V_29 = F_1 ( V_30 , 0 , & V_28 ,
sizeof( V_28 ) , sizeof( V_28 ) ) ;
if ( V_29 )
return - V_21 ;
return V_28 ;
}
static int F_8 ( void )
{
int V_28 = 0 ;
int V_29 = F_1 ( V_31 , 0 , & V_28 ,
sizeof( V_28 ) , sizeof( V_28 ) ) ;
if ( V_29 )
return - V_21 ;
return V_28 ;
}
static int F_9 ( void )
{
int V_28 = 0 ;
int V_29 = F_1 ( V_32 , 0 , & V_28 ,
sizeof( V_28 ) , sizeof( V_28 ) ) ;
if ( V_29 )
return - V_21 ;
return V_28 ;
}
static int F_10 ( void )
{
int V_28 = 0 ;
int V_29 = F_1 ( V_33 , 0 , & V_28 ,
sizeof( V_28 ) , sizeof( V_28 ) ) ;
if ( V_29 )
return - V_21 ;
return V_28 & 0x1 ;
}
static int F_11 ( void )
{
int V_28 = 0 ;
int V_29 = F_1 ( V_33 , 0 , & V_28 ,
sizeof( V_28 ) , sizeof( V_28 ) ) ;
if ( V_29 )
return V_29 ;
return ( V_28 & 0x4 ) ? 1 : 0 ;
}
static int T_2 F_12 ( void )
{
int V_28 = 0 ;
int V_29 = F_1 ( V_34 , 0 , & V_28 ,
sizeof( V_28 ) , sizeof( V_28 ) ) ;
if ( ! V_29 )
return 1 ;
return ( V_29 == V_26 ) ? 0 : - V_35 ;
}
static int T_2 F_13 ( void )
{
int V_28 = 0 ;
int V_29 = F_1 ( V_36 , 0 , & V_28 ,
sizeof( V_28 ) , sizeof( V_28 ) ) ;
if ( ! V_29 )
return 1 ;
return ( V_29 == V_26 ) ? 0 : - V_35 ;
}
static int T_2 F_14 ( void )
{
int V_37 = 0x6e ;
int V_29 = F_1 ( V_38 , 1 , & V_37 ,
sizeof( V_37 ) , 0 ) ;
if ( V_29 )
return - V_21 ;
return 0 ;
}
static int F_15 ( void * V_15 , bool V_39 )
{
enum V_40 V_41 = (enum V_40 ) V_15 ;
int V_1 = F_16 ( V_41 + 8 ) | ( ( ! V_39 ) << V_41 ) ;
int V_29 ;
V_29 = F_1 ( V_42 , 1 ,
& V_1 , sizeof( V_1 ) , 0 ) ;
if ( V_29 )
return - V_21 ;
return 0 ;
}
static bool F_17 ( enum V_40 V_41 )
{
int V_43 = 0 ;
int V_44 ;
F_1 ( V_42 , 0 ,
& V_43 , sizeof( V_43 ) ,
sizeof( V_43 ) ) ;
V_44 = 0x200 << ( V_41 * 8 ) ;
if ( V_43 & V_44 )
return false ;
else
return true ;
}
static bool F_18 ( enum V_40 V_41 )
{
int V_43 = 0 ;
int V_44 ;
F_1 ( V_42 , 0 ,
& V_43 , sizeof( V_43 ) ,
sizeof( V_43 ) ) ;
V_44 = 0x800 << ( V_41 * 8 ) ;
if ( V_43 & V_44 )
return false ;
else
return true ;
}
static int F_19 ( void * V_15 , bool V_39 )
{
int V_45 = ( int ) ( long ) V_15 ;
char V_3 [ 4 ] = { 0x01 , 0x00 , V_45 , ! V_39 } ;
if ( F_1 ( V_46 , 1 ,
V_3 , sizeof( V_3 ) , 0 ) )
return - V_21 ;
return 0 ;
}
static int F_20 ( void )
{
int V_47 , V_48 ;
struct V_49 V_28 ;
V_47 = F_1 ( V_46 , 0 , & V_28 ,
0 , sizeof( V_28 ) ) ;
if ( V_47 )
return V_47 ;
for ( V_48 = 0 ; V_48 < V_50 ; V_48 ++ ) {
int V_51 = V_52 [ V_48 ] . V_51 ;
struct V_53 * V_54 ;
V_54 = & V_28 . V_55 [ V_51 ] ;
if ( V_51 >= V_28 . V_56 ||
V_54 -> V_45 != V_52 [ V_48 ] . V_57 ) {
F_5 ( L_2 ) ;
continue;
}
F_21 ( V_52 [ V_48 ] . V_58 ,
F_22 ( V_54 -> V_59 ) ,
F_23 ( V_54 -> V_59 ) ) ;
}
return 0 ;
}
static int F_24 ( void )
{
int V_28 = 0 ;
int V_29 = F_1 ( V_60 , 0 , & V_28 ,
sizeof( V_28 ) , sizeof( V_28 ) ) ;
if ( V_29 )
return - V_21 ;
return V_28 ;
}
static T_3 F_25 ( struct V_55 * V_61 , struct V_62 * V_63 ,
char * V_64 )
{
int V_37 = F_7 () ;
if ( V_37 < 0 )
return - V_21 ;
return sprintf ( V_64 , L_3 , V_37 ) ;
}
static T_3 F_26 ( struct V_55 * V_61 , struct V_62 * V_63 ,
char * V_64 )
{
int V_37 = F_8 () ;
if ( V_37 < 0 )
return - V_21 ;
return sprintf ( V_64 , L_3 , V_37 ) ;
}
static T_3 F_27 ( struct V_55 * V_61 , struct V_62 * V_63 ,
char * V_64 )
{
int V_37 = F_9 () ;
if ( V_37 < 0 )
return - V_21 ;
return sprintf ( V_64 , L_3 , V_37 ) ;
}
static T_3 F_28 ( struct V_55 * V_61 , struct V_62 * V_63 ,
char * V_64 )
{
int V_37 = F_10 () ;
if ( V_37 < 0 )
return - V_21 ;
return sprintf ( V_64 , L_3 , V_37 ) ;
}
static T_3 F_29 ( struct V_55 * V_61 , struct V_62 * V_63 ,
char * V_64 )
{
int V_37 = F_11 () ;
if ( V_37 < 0 )
return - V_21 ;
return sprintf ( V_64 , L_3 , V_37 ) ;
}
static T_3 F_30 ( struct V_55 * V_61 , struct V_62 * V_63 ,
char * V_64 )
{
int V_37 = F_24 () ;
if ( V_37 < 0 )
return - V_21 ;
return sprintf ( V_64 , L_4 , V_37 ) ;
}
static T_3 F_31 ( struct V_55 * V_61 , struct V_62 * V_63 ,
const char * V_64 , T_4 V_56 )
{
T_1 V_65 = F_32 ( V_64 , NULL , 10 ) ;
int V_29 = F_1 ( V_32 , 1 , & V_65 ,
sizeof( V_65 ) , sizeof( V_65 ) ) ;
if ( V_29 )
return - V_21 ;
return V_56 ;
}
static T_3 F_33 ( struct V_55 * V_61 , struct V_62 * V_63 ,
const char * V_64 , T_4 V_56 )
{
int V_29 ;
T_1 V_65 ;
long unsigned int V_66 ;
V_29 = F_34 ( V_64 , 10 , & V_66 ) ;
if ( V_29 || V_66 != 1 )
return - V_21 ;
V_65 = ( T_1 ) V_66 ;
V_29 = F_1 ( V_60 , 1 , & V_65 ,
sizeof( V_65 ) , sizeof( V_65 ) ) ;
if ( V_29 )
return - V_21 ;
return V_56 ;
}
static void F_35 ( T_1 V_37 , void * V_67 )
{
struct V_16 V_68 = { V_19 , NULL } ;
union V_8 * V_9 ;
T_1 V_69 , V_70 ;
int V_71 = 0 , V_29 ;
T_1 * V_72 ;
T_5 V_73 ;
V_73 = F_36 ( V_37 , & V_68 ) ;
if ( V_73 != V_74 ) {
F_37 ( L_5 , V_73 ) ;
return;
}
V_9 = (union V_8 * ) V_68 . V_23 ;
if ( ! V_9 )
return;
if ( V_9 -> type != V_24 ) {
F_37 ( L_6 , V_9 -> type ) ;
F_4 ( V_9 ) ;
return;
}
V_72 = ( T_1 * ) V_9 -> V_3 . V_23 ;
if ( V_9 -> V_3 . V_27 == 8 ) {
V_69 = * V_72 ;
V_70 = * ( V_72 + 1 ) ;
} else if ( V_9 -> V_3 . V_27 == 16 ) {
V_69 = * V_72 ;
V_70 = * ( V_72 + 2 ) ;
} else {
F_37 ( L_7 , V_9 -> V_3 . V_27 ) ;
F_4 ( V_9 ) ;
return;
}
F_4 ( V_9 ) ;
switch ( V_69 ) {
case V_75 :
F_38 ( V_76 , V_77 ,
F_10 () ) ;
F_38 ( V_76 , V_78 ,
F_11 () ) ;
F_39 ( V_76 ) ;
break;
case V_79 :
break;
case V_80 :
break;
case V_81 :
V_29 = F_1 ( V_82 , 0 ,
& V_71 ,
sizeof( V_71 ) ,
sizeof( V_71 ) ) ;
if ( V_29 )
break;
if ( ! F_40 ( V_76 ,
V_71 , 1 , true ) )
F_37 ( L_8 , V_71 ) ;
break;
case V_83 :
if ( V_50 ) {
F_20 () ;
break;
}
if ( V_84 )
F_21 ( V_84 ,
F_17 ( V_85 ) ,
F_18 ( V_85 ) ) ;
if ( V_86 )
F_21 ( V_86 ,
F_17 ( V_87 ) ,
F_18 ( V_87 ) ) ;
if ( V_88 )
F_21 ( V_88 ,
F_17 ( V_89 ) ,
F_18 ( V_89 ) ) ;
break;
case V_90 :
F_37 ( L_9 ) ;
break;
case V_91 :
break;
case V_92 :
break;
case V_93 :
break;
case V_94 :
break;
case V_95 :
break;
case V_96 :
break;
case V_97 :
break;
case V_98 :
break;
case V_99 :
break;
default:
F_37 ( L_10 , V_69 , V_70 ) ;
break;
}
}
static int T_2 F_41 ( void )
{
T_5 V_73 ;
int V_47 ;
V_76 = F_42 () ;
if ( ! V_76 )
return - V_100 ;
V_76 -> V_101 = L_11 ;
V_76 -> V_102 = L_12 ;
V_76 -> V_57 . V_103 = V_104 ;
F_43 ( V_105 , V_76 -> V_106 ) ;
F_43 ( V_77 , V_76 -> V_107 ) ;
F_43 ( V_78 , V_76 -> V_107 ) ;
V_47 = F_44 ( V_76 , V_108 , NULL ) ;
if ( V_47 )
goto V_109;
F_38 ( V_76 , V_77 , F_10 () ) ;
F_38 ( V_76 , V_78 ,
F_11 () ) ;
F_39 ( V_76 ) ;
if ( ! F_13 () && F_12 () )
F_14 () ;
V_73 = F_45 ( V_110 , F_35 , NULL ) ;
if ( F_46 ( V_73 ) ) {
V_47 = - V_111 ;
goto V_112;
}
V_47 = F_47 ( V_76 ) ;
if ( V_47 )
goto V_113;
return 0 ;
V_113:
F_48 ( V_110 ) ;
V_112:
F_49 ( V_76 ) ;
V_109:
F_50 ( V_76 ) ;
return V_47 ;
}
static void F_51 ( void )
{
F_48 ( V_110 ) ;
F_49 ( V_76 ) ;
F_52 ( V_76 ) ;
}
static void F_53 ( struct V_114 * V_55 )
{
F_54 ( & V_55 -> V_61 , & V_115 ) ;
F_54 ( & V_55 -> V_61 , & V_116 ) ;
F_54 ( & V_55 -> V_61 , & V_117 ) ;
F_54 ( & V_55 -> V_61 , & V_118 ) ;
F_54 ( & V_55 -> V_61 , & V_119 ) ;
F_54 ( & V_55 -> V_61 , & V_120 ) ;
}
static int T_2 F_55 ( struct V_114 * V_55 )
{
int V_47 ;
int V_43 = 0 ;
V_47 = F_1 ( V_42 , 0 , & V_43 ,
sizeof( V_43 ) , sizeof( V_43 ) ) ;
if ( V_47 )
return V_47 ;
if ( V_43 & 0x1 ) {
V_84 = F_56 ( L_13 , & V_55 -> V_61 ,
V_121 ,
& V_122 ,
( void * ) V_85 ) ;
if ( ! V_84 )
return - V_100 ;
F_57 ( V_84 ,
F_17 ( V_85 ) ) ;
F_58 ( V_84 ,
F_18 ( V_85 ) ) ;
V_47 = F_59 ( V_84 ) ;
if ( V_47 )
goto V_123;
}
if ( V_43 & 0x2 ) {
V_86 = F_56 ( L_14 , & V_55 -> V_61 ,
V_124 ,
& V_122 ,
( void * ) V_87 ) ;
if ( ! V_86 ) {
V_47 = - V_100 ;
goto V_125;
}
F_57 ( V_86 ,
F_17 ( V_87 ) ) ;
F_58 ( V_86 ,
F_18 ( V_87 ) ) ;
V_47 = F_59 ( V_86 ) ;
if ( V_47 )
goto V_125;
}
if ( V_43 & 0x4 ) {
V_88 = F_56 ( L_15 , & V_55 -> V_61 ,
V_126 ,
& V_122 ,
( void * ) V_89 ) ;
if ( ! V_88 ) {
V_47 = - V_100 ;
goto V_127;
}
F_57 ( V_88 ,
F_17 ( V_89 ) ) ;
F_58 ( V_88 ,
F_18 ( V_89 ) ) ;
V_47 = F_59 ( V_88 ) ;
if ( V_47 )
goto V_127;
}
return 0 ;
V_127:
F_60 ( V_88 ) ;
V_88 = NULL ;
if ( V_86 )
F_61 ( V_86 ) ;
V_125:
F_60 ( V_86 ) ;
V_86 = NULL ;
if ( V_84 )
F_61 ( V_84 ) ;
V_123:
F_60 ( V_84 ) ;
V_84 = NULL ;
return V_47 ;
}
static int T_2 F_62 ( struct V_114 * V_55 )
{
int V_47 , V_48 ;
struct V_49 V_28 ;
V_47 = F_1 ( V_46 , 0 , & V_28 ,
0 , sizeof( V_28 ) ) ;
if ( V_47 )
return V_47 ;
if ( V_28 . V_56 > V_128 ) {
F_5 ( L_16 ) ;
return - V_21 ;
}
for ( V_48 = 0 ; V_48 < V_28 . V_56 ; V_48 ++ ) {
struct V_58 * V_58 ;
enum V_129 type ;
char * V_101 ;
switch ( V_28 . V_55 [ V_48 ] . V_130 ) {
case V_85 :
type = V_121 ;
V_101 = L_13 ;
break;
case V_87 :
type = V_124 ;
V_101 = L_14 ;
break;
case V_89 :
type = V_126 ;
V_101 = L_15 ;
break;
case V_131 :
type = V_132 ;
V_101 = L_17 ;
break;
default:
F_5 ( L_18 ,
V_28 . V_55 [ V_48 ] . V_130 ) ;
continue;
}
if ( ! V_28 . V_55 [ V_48 ] . V_133 ) {
F_5 ( L_19 ,
V_48 , V_28 . V_56 ) ;
continue;
}
V_58 = F_56 ( V_101 , & V_55 -> V_61 , type ,
& V_134 , ( void * ) ( long ) V_48 ) ;
if ( ! V_58 ) {
V_47 = - V_100 ;
goto V_135;
}
V_52 [ V_50 ] . V_57 = V_28 . V_55 [ V_48 ] . V_45 ;
V_52 [ V_50 ] . V_51 = V_48 ;
V_52 [ V_50 ] . V_58 = V_58 ;
F_57 ( V_58 ,
F_22 ( V_28 . V_55 [ V_48 ] . V_59 ) ) ;
F_58 ( V_58 ,
F_23 ( V_28 . V_55 [ V_48 ] . V_59 ) ) ;
if ( ! ( V_28 . V_55 [ V_48 ] . V_59 & V_136 ) )
F_37 ( L_20 , V_101 ) ;
V_47 = F_59 ( V_58 ) ;
if ( V_47 ) {
F_60 ( V_58 ) ;
goto V_135;
}
V_50 ++ ;
}
return 0 ;
V_135:
for (; V_50 > 0 ; V_50 -- ) {
F_61 ( V_52 [ V_50 - 1 ] . V_58 ) ;
F_60 ( V_52 [ V_50 - 1 ] . V_58 ) ;
}
return V_47 ;
}
static int T_2 F_63 ( struct V_114 * V_55 )
{
int V_47 ;
V_84 = NULL ;
V_86 = NULL ;
V_88 = NULL ;
V_50 = 0 ;
if ( F_13 () || F_55 ( V_55 ) )
F_62 ( V_55 ) ;
V_47 = F_64 ( & V_55 -> V_61 , & V_115 ) ;
if ( V_47 )
goto V_137;
V_47 = F_64 ( & V_55 -> V_61 , & V_116 ) ;
if ( V_47 )
goto V_137;
V_47 = F_64 ( & V_55 -> V_61 , & V_117 ) ;
if ( V_47 )
goto V_137;
V_47 = F_64 ( & V_55 -> V_61 , & V_118 ) ;
if ( V_47 )
goto V_137;
V_47 = F_64 ( & V_55 -> V_61 , & V_119 ) ;
if ( V_47 )
goto V_137;
V_47 = F_64 ( & V_55 -> V_61 , & V_120 ) ;
if ( V_47 )
goto V_137;
return 0 ;
V_137:
F_53 ( V_55 ) ;
return V_47 ;
}
static int T_6 F_65 ( struct V_114 * V_55 )
{
int V_48 ;
F_53 ( V_55 ) ;
for ( V_48 = 0 ; V_48 < V_50 ; V_48 ++ ) {
F_61 ( V_52 [ V_48 ] . V_58 ) ;
F_60 ( V_52 [ V_48 ] . V_58 ) ;
}
if ( V_84 ) {
F_61 ( V_84 ) ;
F_60 ( V_84 ) ;
}
if ( V_86 ) {
F_61 ( V_86 ) ;
F_60 ( V_86 ) ;
}
if ( V_88 ) {
F_61 ( V_88 ) ;
F_60 ( V_88 ) ;
}
return 0 ;
}
static int F_66 ( struct V_55 * V_55 )
{
if ( V_76 ) {
F_38 ( V_76 , V_77 ,
F_10 () ) ;
F_38 ( V_76 , V_78 ,
F_11 () ) ;
F_39 ( V_76 ) ;
}
if ( V_50 )
F_20 () ;
if ( V_84 )
F_21 ( V_84 ,
F_17 ( V_85 ) ,
F_18 ( V_85 ) ) ;
if ( V_86 )
F_21 ( V_86 ,
F_17 ( V_87 ) ,
F_18 ( V_87 ) ) ;
if ( V_88 )
F_21 ( V_88 ,
F_17 ( V_89 ) ,
F_18 ( V_89 ) ) ;
return 0 ;
}
static int T_2 F_67 ( void )
{
int V_47 ;
int V_138 = F_68 ( V_110 ) ;
int V_139 = F_68 ( V_22 ) ;
if ( ! V_139 && ! V_138 )
return - V_140 ;
if ( V_138 ) {
V_47 = F_41 () ;
if ( V_47 )
return V_47 ;
}
if ( V_139 ) {
V_141 =
F_69 ( L_21 , - 1 , NULL , 0 ) ;
if ( F_70 ( V_141 ) ) {
V_47 = F_71 ( V_141 ) ;
goto V_142;
}
V_47 = F_72 ( & V_143 , F_63 ) ;
if ( V_47 )
goto V_144;
}
return 0 ;
V_144:
F_73 ( V_141 ) ;
V_142:
if ( V_138 )
F_51 () ;
return V_47 ;
}
static void T_6 F_74 ( void )
{
if ( F_68 ( V_110 ) )
F_51 () ;
if ( V_141 ) {
F_73 ( V_141 ) ;
F_75 ( & V_143 ) ;
}
}
