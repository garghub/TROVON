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
if ( V_29 )
return V_29 ;
return ( V_28 & 0x10 ) ? 1 : 0 ;
}
static int F_13 ( void )
{
int V_29 ;
int V_1 = 0x6e ;
V_29 = F_1 ( V_35 , 1 , & V_1 , sizeof( V_1 ) ,
0 ) ;
if ( V_29 )
return - V_21 ;
return 0 ;
}
static int F_14 ( void * V_15 , bool V_36 )
{
enum V_37 V_38 = (enum V_37 ) V_15 ;
int V_1 = F_15 ( V_38 + 8 ) | ( ( ! V_36 ) << V_38 ) ;
int V_29 ;
V_29 = F_1 ( V_39 , 1 ,
& V_1 , sizeof( V_1 ) , 0 ) ;
if ( V_29 )
return - V_21 ;
return 0 ;
}
static bool F_16 ( enum V_37 V_38 )
{
int V_40 = 0 ;
int V_41 ;
F_1 ( V_39 , 0 ,
& V_40 , sizeof( V_40 ) ,
sizeof( V_40 ) ) ;
V_41 = 0x200 << ( V_38 * 8 ) ;
if ( V_40 & V_41 )
return false ;
else
return true ;
}
static bool F_17 ( enum V_37 V_38 )
{
int V_40 = 0 ;
int V_41 ;
F_1 ( V_39 , 0 ,
& V_40 , sizeof( V_40 ) ,
sizeof( V_40 ) ) ;
V_41 = 0x800 << ( V_38 * 8 ) ;
if ( V_40 & V_41 )
return false ;
else
return true ;
}
static int F_18 ( void * V_15 , bool V_36 )
{
int V_42 = ( int ) ( long ) V_15 ;
char V_3 [ 4 ] = { 0x01 , 0x00 , V_42 , ! V_36 } ;
if ( F_1 ( V_43 , 1 ,
V_3 , sizeof( V_3 ) , 0 ) )
return - V_21 ;
return 0 ;
}
static int F_19 ( void )
{
int V_44 , V_45 ;
struct V_46 V_28 ;
V_44 = F_1 ( V_43 , 0 , & V_28 ,
0 , sizeof( V_28 ) ) ;
if ( V_44 )
return V_44 ;
for ( V_45 = 0 ; V_45 < V_47 ; V_45 ++ ) {
int V_48 = V_49 [ V_45 ] . V_48 ;
struct V_50 * V_51 ;
V_51 = & V_28 . V_52 [ V_48 ] ;
if ( V_48 >= V_28 . V_53 ||
V_51 -> V_42 != V_49 [ V_45 ] . V_54 ) {
F_5 ( L_2 ) ;
continue;
}
F_20 ( V_49 [ V_45 ] . V_55 ,
F_21 ( V_51 -> V_56 ) ,
F_22 ( V_51 -> V_56 ) ) ;
}
return 0 ;
}
static int F_23 ( void )
{
int V_28 = 0 ;
int V_29 = F_1 ( V_57 , 0 , & V_28 ,
sizeof( V_28 ) , sizeof( V_28 ) ) ;
if ( V_29 )
return - V_21 ;
return V_28 ;
}
static T_3 F_24 ( struct V_52 * V_58 , struct V_59 * V_60 ,
char * V_61 )
{
int V_62 = F_7 () ;
if ( V_62 < 0 )
return - V_21 ;
return sprintf ( V_61 , L_3 , V_62 ) ;
}
static T_3 F_25 ( struct V_52 * V_58 , struct V_59 * V_60 ,
char * V_61 )
{
int V_62 = F_8 () ;
if ( V_62 < 0 )
return - V_21 ;
return sprintf ( V_61 , L_3 , V_62 ) ;
}
static T_3 F_26 ( struct V_52 * V_58 , struct V_59 * V_60 ,
char * V_61 )
{
int V_62 = F_9 () ;
if ( V_62 < 0 )
return - V_21 ;
return sprintf ( V_61 , L_3 , V_62 ) ;
}
static T_3 F_27 ( struct V_52 * V_58 , struct V_59 * V_60 ,
char * V_61 )
{
int V_62 = F_10 () ;
if ( V_62 < 0 )
return - V_21 ;
return sprintf ( V_61 , L_3 , V_62 ) ;
}
static T_3 F_28 ( struct V_52 * V_58 , struct V_59 * V_60 ,
char * V_61 )
{
int V_62 = F_11 () ;
if ( V_62 < 0 )
return - V_21 ;
return sprintf ( V_61 , L_3 , V_62 ) ;
}
static T_3 F_29 ( struct V_52 * V_58 , struct V_59 * V_60 ,
char * V_61 )
{
int V_62 = F_23 () ;
if ( V_62 < 0 )
return - V_21 ;
return sprintf ( V_61 , L_4 , V_62 ) ;
}
static T_3 F_30 ( struct V_52 * V_58 , struct V_59 * V_60 ,
const char * V_61 , T_4 V_53 )
{
T_1 V_63 = F_31 ( V_61 , NULL , 10 ) ;
int V_29 = F_1 ( V_32 , 1 , & V_63 ,
sizeof( V_63 ) , sizeof( V_63 ) ) ;
if ( V_29 )
return - V_21 ;
return V_53 ;
}
static T_3 F_32 ( struct V_52 * V_58 , struct V_59 * V_60 ,
const char * V_61 , T_4 V_53 )
{
int V_29 ;
T_1 V_63 ;
long unsigned int V_64 ;
V_29 = F_33 ( V_61 , 10 , & V_64 ) ;
if ( V_29 || V_64 != 1 )
return - V_21 ;
V_63 = ( T_1 ) V_64 ;
V_29 = F_1 ( V_57 , 1 , & V_63 ,
sizeof( V_63 ) , sizeof( V_63 ) ) ;
if ( V_29 )
return - V_21 ;
return V_53 ;
}
static void F_34 ( T_1 V_62 , void * V_65 )
{
struct V_16 V_66 = { V_19 , NULL } ;
union V_8 * V_9 ;
T_1 V_67 , V_68 ;
int V_69 = 0 , V_29 ;
T_1 * V_70 ;
T_5 V_71 ;
V_71 = F_35 ( V_62 , & V_66 ) ;
if ( V_71 != V_72 ) {
F_36 ( L_5 , V_71 ) ;
return;
}
V_9 = (union V_8 * ) V_66 . V_23 ;
if ( ! V_9 )
return;
if ( V_9 -> type != V_24 ) {
F_36 ( L_6 , V_9 -> type ) ;
F_4 ( V_9 ) ;
return;
}
V_70 = ( T_1 * ) V_9 -> V_3 . V_23 ;
if ( V_9 -> V_3 . V_27 == 8 ) {
V_67 = * V_70 ;
V_68 = * ( V_70 + 1 ) ;
} else if ( V_9 -> V_3 . V_27 == 16 ) {
V_67 = * V_70 ;
V_68 = * ( V_70 + 2 ) ;
} else {
F_36 ( L_7 , V_9 -> V_3 . V_27 ) ;
F_4 ( V_9 ) ;
return;
}
F_4 ( V_9 ) ;
switch ( V_67 ) {
case V_73 :
F_37 ( V_74 , V_75 ,
F_10 () ) ;
F_37 ( V_74 , V_76 ,
F_11 () ) ;
F_38 ( V_74 ) ;
break;
case V_77 :
break;
case V_78 :
break;
case V_79 :
V_29 = F_1 ( V_80 , 0 ,
& V_69 ,
sizeof( V_69 ) ,
sizeof( V_69 ) ) ;
if ( V_29 )
break;
if ( ! F_39 ( V_74 ,
V_69 , 1 , true ) )
F_36 ( L_8 , V_69 ) ;
break;
case V_81 :
if ( V_47 ) {
F_19 () ;
break;
}
if ( V_82 )
F_20 ( V_82 ,
F_16 ( V_83 ) ,
F_17 ( V_83 ) ) ;
if ( V_84 )
F_20 ( V_84 ,
F_16 ( V_85 ) ,
F_17 ( V_85 ) ) ;
if ( V_86 )
F_20 ( V_86 ,
F_16 ( V_87 ) ,
F_17 ( V_87 ) ) ;
if ( V_88 )
F_20 ( V_88 ,
F_16 ( V_89 ) ,
F_17 ( V_89 ) ) ;
break;
case V_90 :
F_36 ( L_9 ) ;
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
F_36 ( L_10 , V_67 , V_68 ) ;
break;
}
}
static int T_2 F_40 ( void )
{
T_5 V_71 ;
int V_44 ;
V_74 = F_41 () ;
if ( ! V_74 )
return - V_100 ;
V_74 -> V_101 = L_11 ;
V_74 -> V_102 = L_12 ;
V_74 -> V_54 . V_103 = V_104 ;
F_42 ( V_105 , V_74 -> V_106 ) ;
F_42 ( V_75 , V_74 -> V_107 ) ;
F_42 ( V_76 , V_74 -> V_107 ) ;
V_44 = F_43 ( V_74 , V_108 , NULL ) ;
if ( V_44 )
goto V_109;
F_37 ( V_74 , V_75 , F_10 () ) ;
F_37 ( V_74 , V_76 ,
F_11 () ) ;
F_38 ( V_74 ) ;
if ( F_12 () == 4 )
F_13 () ;
V_71 = F_44 ( V_110 , F_34 , NULL ) ;
if ( F_45 ( V_71 ) ) {
V_44 = - V_111 ;
goto V_112;
}
V_44 = F_46 ( V_74 ) ;
if ( V_44 )
goto V_113;
return 0 ;
V_113:
F_47 ( V_110 ) ;
V_112:
F_48 ( V_74 ) ;
V_109:
F_49 ( V_74 ) ;
return V_44 ;
}
static void F_50 ( void )
{
F_47 ( V_110 ) ;
F_48 ( V_74 ) ;
F_51 ( V_74 ) ;
}
static void F_52 ( struct V_114 * V_52 )
{
F_53 ( & V_52 -> V_58 , & V_115 ) ;
F_53 ( & V_52 -> V_58 , & V_116 ) ;
F_53 ( & V_52 -> V_58 , & V_117 ) ;
F_53 ( & V_52 -> V_58 , & V_118 ) ;
F_53 ( & V_52 -> V_58 , & V_119 ) ;
F_53 ( & V_52 -> V_58 , & V_120 ) ;
}
static int T_2 F_54 ( struct V_114 * V_52 )
{
int V_44 ;
int V_40 = 0 ;
V_44 = F_1 ( V_39 , 0 , & V_40 ,
sizeof( V_40 ) , sizeof( V_40 ) ) ;
if ( V_44 )
return V_44 ;
if ( V_40 & 0x1 ) {
V_82 = F_55 ( L_13 , & V_52 -> V_58 ,
V_121 ,
& V_122 ,
( void * ) V_83 ) ;
if ( ! V_82 )
return - V_100 ;
F_56 ( V_82 ,
F_16 ( V_83 ) ) ;
F_57 ( V_82 ,
F_17 ( V_83 ) ) ;
V_44 = F_58 ( V_82 ) ;
if ( V_44 )
goto V_123;
}
if ( V_40 & 0x2 ) {
V_84 = F_55 ( L_14 , & V_52 -> V_58 ,
V_124 ,
& V_122 ,
( void * ) V_85 ) ;
if ( ! V_84 ) {
V_44 = - V_100 ;
goto V_123;
}
F_56 ( V_84 ,
F_16 ( V_85 ) ) ;
F_57 ( V_84 ,
F_17 ( V_85 ) ) ;
V_44 = F_58 ( V_84 ) ;
if ( V_44 )
goto V_125;
}
if ( V_40 & 0x4 ) {
V_86 = F_55 ( L_15 , & V_52 -> V_58 ,
V_126 ,
& V_122 ,
( void * ) V_87 ) ;
if ( ! V_86 ) {
V_44 = - V_100 ;
goto V_125;
}
F_56 ( V_86 ,
F_16 ( V_87 ) ) ;
F_57 ( V_86 ,
F_17 ( V_87 ) ) ;
V_44 = F_58 ( V_86 ) ;
if ( V_44 )
goto V_127;
}
if ( V_40 & 0x8 ) {
V_88 = F_55 ( L_16 , & V_52 -> V_58 ,
V_128 ,
& V_122 ,
( void * ) V_89 ) ;
if ( ! V_88 ) {
V_44 = - V_100 ;
goto V_127;
}
F_56 ( V_88 ,
F_16 ( V_89 ) ) ;
F_57 ( V_88 ,
F_17 ( V_89 ) ) ;
V_44 = F_58 ( V_88 ) ;
if ( V_44 )
goto V_129;
}
return 0 ;
V_129:
F_59 ( V_88 ) ;
V_88 = NULL ;
if ( V_84 )
F_60 ( V_84 ) ;
V_127:
F_59 ( V_86 ) ;
V_86 = NULL ;
if ( V_88 )
F_60 ( V_88 ) ;
V_125:
F_59 ( V_84 ) ;
V_84 = NULL ;
if ( V_82 )
F_60 ( V_82 ) ;
V_123:
F_59 ( V_82 ) ;
V_82 = NULL ;
return V_44 ;
}
static int T_2 F_61 ( struct V_114 * V_52 )
{
int V_44 , V_45 ;
struct V_46 V_28 ;
V_44 = F_1 ( V_43 , 0 , & V_28 ,
0 , sizeof( V_28 ) ) ;
if ( V_44 )
return V_44 ;
if ( V_28 . V_53 > V_130 ) {
F_5 ( L_17 ) ;
return - V_21 ;
}
for ( V_45 = 0 ; V_45 < V_28 . V_53 ; V_45 ++ ) {
struct V_55 * V_55 ;
enum V_131 type ;
char * V_101 ;
switch ( V_28 . V_52 [ V_45 ] . V_132 ) {
case V_83 :
type = V_121 ;
V_101 = L_13 ;
break;
case V_85 :
type = V_124 ;
V_101 = L_14 ;
break;
case V_87 :
type = V_126 ;
V_101 = L_15 ;
break;
case V_89 :
type = V_128 ;
V_101 = L_16 ;
break;
default:
F_5 ( L_18 ,
V_28 . V_52 [ V_45 ] . V_132 ) ;
continue;
}
if ( ! V_28 . V_52 [ V_45 ] . V_133 ) {
F_5 ( L_19 ,
V_45 , V_28 . V_53 ) ;
continue;
}
V_55 = F_55 ( V_101 , & V_52 -> V_58 , type ,
& V_134 , ( void * ) ( long ) V_45 ) ;
if ( ! V_55 ) {
V_44 = - V_100 ;
goto V_135;
}
V_49 [ V_47 ] . V_54 = V_28 . V_52 [ V_45 ] . V_42 ;
V_49 [ V_47 ] . V_48 = V_45 ;
V_49 [ V_47 ] . V_55 = V_55 ;
F_56 ( V_55 ,
F_21 ( V_28 . V_52 [ V_45 ] . V_56 ) ) ;
F_57 ( V_55 ,
F_22 ( V_28 . V_52 [ V_45 ] . V_56 ) ) ;
if ( ! ( V_28 . V_52 [ V_45 ] . V_56 & V_136 ) )
F_36 ( L_20 , V_101 ) ;
V_44 = F_58 ( V_55 ) ;
if ( V_44 ) {
F_59 ( V_55 ) ;
goto V_135;
}
V_47 ++ ;
}
return 0 ;
V_135:
for (; V_47 > 0 ; V_47 -- ) {
F_60 ( V_49 [ V_47 - 1 ] . V_55 ) ;
F_59 ( V_49 [ V_47 - 1 ] . V_55 ) ;
}
return V_44 ;
}
static int T_2 F_62 ( struct V_114 * V_52 )
{
int V_44 ;
V_82 = NULL ;
V_84 = NULL ;
V_86 = NULL ;
V_88 = NULL ;
V_47 = 0 ;
if ( F_12 () || F_54 ( V_52 ) )
F_61 ( V_52 ) ;
V_44 = F_63 ( & V_52 -> V_58 , & V_115 ) ;
if ( V_44 )
goto V_137;
V_44 = F_63 ( & V_52 -> V_58 , & V_116 ) ;
if ( V_44 )
goto V_137;
V_44 = F_63 ( & V_52 -> V_58 , & V_117 ) ;
if ( V_44 )
goto V_137;
V_44 = F_63 ( & V_52 -> V_58 , & V_118 ) ;
if ( V_44 )
goto V_137;
V_44 = F_63 ( & V_52 -> V_58 , & V_119 ) ;
if ( V_44 )
goto V_137;
V_44 = F_63 ( & V_52 -> V_58 , & V_120 ) ;
if ( V_44 )
goto V_137;
return 0 ;
V_137:
F_52 ( V_52 ) ;
return V_44 ;
}
static int T_6 F_64 ( struct V_114 * V_52 )
{
int V_45 ;
F_52 ( V_52 ) ;
for ( V_45 = 0 ; V_45 < V_47 ; V_45 ++ ) {
F_60 ( V_49 [ V_45 ] . V_55 ) ;
F_59 ( V_49 [ V_45 ] . V_55 ) ;
}
if ( V_82 ) {
F_60 ( V_82 ) ;
F_59 ( V_82 ) ;
}
if ( V_84 ) {
F_60 ( V_84 ) ;
F_59 ( V_84 ) ;
}
if ( V_86 ) {
F_60 ( V_86 ) ;
F_59 ( V_86 ) ;
}
if ( V_88 ) {
F_60 ( V_88 ) ;
F_59 ( V_88 ) ;
}
return 0 ;
}
static int F_65 ( struct V_52 * V_52 )
{
if ( V_74 ) {
F_37 ( V_74 , V_75 ,
F_10 () ) ;
F_37 ( V_74 , V_76 ,
F_11 () ) ;
F_38 ( V_74 ) ;
}
if ( V_47 )
F_19 () ;
if ( V_82 )
F_20 ( V_82 ,
F_16 ( V_83 ) ,
F_17 ( V_83 ) ) ;
if ( V_84 )
F_20 ( V_84 ,
F_16 ( V_85 ) ,
F_17 ( V_85 ) ) ;
if ( V_86 )
F_20 ( V_86 ,
F_16 ( V_87 ) ,
F_17 ( V_87 ) ) ;
if ( V_88 )
F_20 ( V_88 ,
F_16 ( V_89 ) ,
F_17 ( V_89 ) ) ;
return 0 ;
}
static int T_2 F_66 ( void )
{
int V_44 ;
int V_138 = F_67 ( V_110 ) ;
int V_139 = F_67 ( V_22 ) ;
if ( ! V_139 && ! V_138 )
return - V_140 ;
if ( V_138 ) {
V_44 = F_40 () ;
if ( V_44 )
return V_44 ;
}
if ( V_139 ) {
V_141 =
F_68 ( L_21 , - 1 , NULL , 0 ) ;
if ( F_69 ( V_141 ) ) {
V_44 = F_70 ( V_141 ) ;
goto V_142;
}
V_44 = F_71 ( & V_143 , F_62 ) ;
if ( V_44 )
goto V_144;
}
return 0 ;
V_144:
F_72 ( V_141 ) ;
V_142:
if ( V_138 )
F_50 () ;
return V_44 ;
}
static void T_6 F_73 ( void )
{
if ( F_67 ( V_110 ) )
F_50 () ;
if ( V_141 ) {
F_72 ( V_141 ) ;
F_74 ( & V_143 ) ;
}
}
