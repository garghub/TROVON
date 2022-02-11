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
static int F_12 ( void * V_15 , bool V_34 )
{
enum V_35 V_36 = (enum V_35 ) V_15 ;
int V_1 = F_13 ( V_36 + 8 ) | ( ( ! V_34 ) << V_36 ) ;
int V_29 ;
V_29 = F_1 ( V_37 , 1 ,
& V_1 , sizeof( V_1 ) , 0 ) ;
if ( V_29 )
return - V_21 ;
return 0 ;
}
static bool F_14 ( enum V_35 V_36 )
{
int V_38 = 0 ;
int V_39 ;
F_1 ( V_37 , 0 ,
& V_38 , sizeof( V_38 ) ,
sizeof( V_38 ) ) ;
V_39 = 0x200 << ( V_36 * 8 ) ;
if ( V_38 & V_39 )
return false ;
else
return true ;
}
static bool F_15 ( enum V_35 V_36 )
{
int V_38 = 0 ;
int V_39 ;
F_1 ( V_37 , 0 ,
& V_38 , sizeof( V_38 ) ,
sizeof( V_38 ) ) ;
V_39 = 0x800 << ( V_36 * 8 ) ;
if ( V_38 & V_39 )
return false ;
else
return true ;
}
static int F_16 ( void * V_15 , bool V_34 )
{
int V_40 = ( int ) ( long ) V_15 ;
char V_3 [ 4 ] = { 0x01 , 0x00 , V_40 , ! V_34 } ;
if ( F_1 ( V_41 , 1 ,
V_3 , sizeof( V_3 ) , 0 ) )
return - V_21 ;
return 0 ;
}
static int F_17 ( void )
{
int V_42 , V_43 ;
struct V_44 V_28 ;
V_42 = F_1 ( V_41 , 0 , & V_28 ,
0 , sizeof( V_28 ) ) ;
if ( V_42 )
return V_42 ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
int V_46 = V_47 [ V_43 ] . V_46 ;
struct V_48 * V_49 ;
V_49 = & V_28 . V_50 [ V_46 ] ;
if ( V_46 >= V_28 . V_51 ||
V_49 -> V_40 != V_47 [ V_43 ] . V_52 ) {
F_5 ( L_2 ) ;
continue;
}
F_18 ( V_47 [ V_43 ] . V_53 ,
F_19 ( V_49 -> V_54 ) ,
F_20 ( V_49 -> V_54 ) ) ;
}
return 0 ;
}
static T_2 F_21 ( struct V_50 * V_55 , struct V_56 * V_57 ,
char * V_58 )
{
int V_59 = F_7 () ;
if ( V_59 < 0 )
return - V_21 ;
return sprintf ( V_58 , L_3 , V_59 ) ;
}
static T_2 F_22 ( struct V_50 * V_55 , struct V_56 * V_57 ,
char * V_58 )
{
int V_59 = F_8 () ;
if ( V_59 < 0 )
return - V_21 ;
return sprintf ( V_58 , L_3 , V_59 ) ;
}
static T_2 F_23 ( struct V_50 * V_55 , struct V_56 * V_57 ,
char * V_58 )
{
int V_59 = F_9 () ;
if ( V_59 < 0 )
return - V_21 ;
return sprintf ( V_58 , L_3 , V_59 ) ;
}
static T_2 F_24 ( struct V_50 * V_55 , struct V_56 * V_57 ,
char * V_58 )
{
int V_59 = F_10 () ;
if ( V_59 < 0 )
return - V_21 ;
return sprintf ( V_58 , L_3 , V_59 ) ;
}
static T_2 F_25 ( struct V_50 * V_55 , struct V_56 * V_57 ,
char * V_58 )
{
int V_59 = F_11 () ;
if ( V_59 < 0 )
return - V_21 ;
return sprintf ( V_58 , L_3 , V_59 ) ;
}
static T_2 F_26 ( struct V_50 * V_55 , struct V_56 * V_57 ,
const char * V_58 , T_3 V_51 )
{
T_1 V_60 = F_27 ( V_58 , NULL , 10 ) ;
int V_29 = F_1 ( V_32 , 1 , & V_60 ,
sizeof( V_60 ) , sizeof( V_60 ) ) ;
if ( V_29 )
return - V_21 ;
return V_51 ;
}
static void F_28 ( T_1 V_59 , void * V_61 )
{
struct V_16 V_62 = { V_19 , NULL } ;
union V_8 * V_9 ;
T_1 V_63 , V_64 ;
int V_65 = 0 , V_29 ;
T_1 * V_66 ;
T_4 V_67 ;
V_67 = F_29 ( V_59 , & V_62 ) ;
if ( V_67 != V_68 ) {
F_30 ( L_4 , V_67 ) ;
return;
}
V_9 = (union V_8 * ) V_62 . V_23 ;
if ( ! V_9 )
return;
if ( V_9 -> type != V_24 ) {
F_30 ( L_5 , V_9 -> type ) ;
F_4 ( V_9 ) ;
return;
}
V_66 = ( T_1 * ) V_9 -> V_3 . V_23 ;
if ( V_9 -> V_3 . V_27 == 8 ) {
V_63 = * V_66 ;
V_64 = * ( V_66 + 1 ) ;
} else if ( V_9 -> V_3 . V_27 == 16 ) {
V_63 = * V_66 ;
V_64 = * ( V_66 + 2 ) ;
} else {
F_30 ( L_6 , V_9 -> V_3 . V_27 ) ;
F_4 ( V_9 ) ;
return;
}
F_4 ( V_9 ) ;
switch ( V_63 ) {
case V_69 :
F_31 ( V_70 , V_71 ,
F_10 () ) ;
F_31 ( V_70 , V_72 ,
F_11 () ) ;
F_32 ( V_70 ) ;
break;
case V_73 :
break;
case V_74 :
break;
case V_75 :
V_29 = F_1 ( V_76 , 0 ,
& V_65 ,
sizeof( V_65 ) ,
sizeof( V_65 ) ) ;
if ( V_29 )
break;
if ( ! F_33 ( V_70 ,
V_65 , 1 , true ) )
F_30 ( L_7 , V_65 ) ;
break;
case V_77 :
if ( V_45 ) {
F_17 () ;
break;
}
if ( V_78 )
F_18 ( V_78 ,
F_14 ( V_79 ) ,
F_15 ( V_79 ) ) ;
if ( V_80 )
F_18 ( V_80 ,
F_14 ( V_81 ) ,
F_15 ( V_81 ) ) ;
if ( V_82 )
F_18 ( V_82 ,
F_14 ( V_83 ) ,
F_15 ( V_83 ) ) ;
break;
case V_84 :
F_30 ( L_8 ) ;
break;
case V_85 :
break;
default:
F_30 ( L_9 , V_63 , V_64 ) ;
break;
}
}
static int T_5 F_34 ( void )
{
T_4 V_67 ;
int V_42 ;
V_70 = F_35 () ;
if ( ! V_70 )
return - V_86 ;
V_70 -> V_87 = L_10 ;
V_70 -> V_88 = L_11 ;
V_70 -> V_52 . V_89 = V_90 ;
F_36 ( V_91 , V_70 -> V_92 ) ;
F_36 ( V_71 , V_70 -> V_93 ) ;
F_36 ( V_72 , V_70 -> V_93 ) ;
V_42 = F_37 ( V_70 , V_94 , NULL ) ;
if ( V_42 )
goto V_95;
F_31 ( V_70 , V_71 , F_10 () ) ;
F_31 ( V_70 , V_72 ,
F_11 () ) ;
F_32 ( V_70 ) ;
V_67 = F_38 ( V_96 , F_28 , NULL ) ;
if ( F_39 ( V_67 ) ) {
V_42 = - V_97 ;
goto V_98;
}
V_42 = F_40 ( V_70 ) ;
if ( V_42 )
goto V_99;
return 0 ;
V_99:
F_41 ( V_96 ) ;
V_98:
F_42 ( V_70 ) ;
V_95:
F_43 ( V_70 ) ;
return V_42 ;
}
static void F_44 ( void )
{
F_41 ( V_96 ) ;
F_42 ( V_70 ) ;
F_45 ( V_70 ) ;
}
static void F_46 ( struct V_100 * V_50 )
{
F_47 ( & V_50 -> V_55 , & V_101 ) ;
F_47 ( & V_50 -> V_55 , & V_102 ) ;
F_47 ( & V_50 -> V_55 , & V_103 ) ;
F_47 ( & V_50 -> V_55 , & V_104 ) ;
F_47 ( & V_50 -> V_55 , & V_105 ) ;
}
static int T_6 F_48 ( struct V_100 * V_50 )
{
int V_42 ;
int V_38 = 0 ;
V_42 = F_1 ( V_37 , 0 , & V_38 ,
sizeof( V_38 ) , sizeof( V_38 ) ) ;
if ( V_42 )
return V_42 ;
if ( V_38 & 0x1 ) {
V_78 = F_49 ( L_12 , & V_50 -> V_55 ,
V_106 ,
& V_107 ,
( void * ) V_79 ) ;
F_50 ( V_78 ,
F_14 ( V_79 ) ) ;
F_51 ( V_78 ,
F_15 ( V_79 ) ) ;
V_42 = F_52 ( V_78 ) ;
if ( V_42 )
goto V_108;
}
if ( V_38 & 0x2 ) {
V_80 = F_49 ( L_13 , & V_50 -> V_55 ,
V_109 ,
& V_107 ,
( void * ) V_81 ) ;
F_50 ( V_80 ,
F_14 ( V_81 ) ) ;
F_51 ( V_80 ,
F_15 ( V_81 ) ) ;
V_42 = F_52 ( V_80 ) ;
if ( V_42 )
goto V_110;
}
if ( V_38 & 0x4 ) {
V_82 = F_49 ( L_14 , & V_50 -> V_55 ,
V_111 ,
& V_107 ,
( void * ) V_83 ) ;
F_50 ( V_82 ,
F_14 ( V_83 ) ) ;
F_51 ( V_82 ,
F_15 ( V_83 ) ) ;
V_42 = F_52 ( V_82 ) ;
if ( V_42 )
goto V_112;
}
return 0 ;
V_112:
F_53 ( V_82 ) ;
V_82 = NULL ;
if ( V_80 )
F_54 ( V_80 ) ;
V_110:
F_53 ( V_80 ) ;
V_80 = NULL ;
if ( V_78 )
F_54 ( V_78 ) ;
V_108:
F_53 ( V_78 ) ;
V_78 = NULL ;
return V_42 ;
}
static int T_6 F_55 ( struct V_100 * V_50 )
{
int V_42 , V_43 ;
struct V_44 V_28 ;
V_42 = F_1 ( V_41 , 0 , & V_28 ,
0 , sizeof( V_28 ) ) ;
if ( V_42 )
return V_42 ;
if ( V_28 . V_51 > V_113 ) {
F_5 ( L_15 ) ;
return - V_21 ;
}
for ( V_43 = 0 ; V_43 < V_28 . V_51 ; V_43 ++ ) {
struct V_53 * V_53 ;
enum V_114 type ;
char * V_87 ;
switch ( V_28 . V_50 [ V_43 ] . V_115 ) {
case V_79 :
type = V_106 ;
V_87 = L_12 ;
break;
case V_81 :
type = V_109 ;
V_87 = L_13 ;
break;
case V_83 :
type = V_111 ;
V_87 = L_14 ;
break;
default:
F_5 ( L_16 ,
V_28 . V_50 [ V_43 ] . V_115 ) ;
continue;
}
if ( ! V_28 . V_50 [ V_43 ] . V_116 ) {
F_5 ( L_17 ,
V_43 , V_28 . V_51 ) ;
continue;
}
V_53 = F_49 ( V_87 , & V_50 -> V_55 , type ,
& V_117 , ( void * ) ( long ) V_43 ) ;
if ( ! V_53 ) {
V_42 = - V_86 ;
goto V_118;
}
V_47 [ V_45 ] . V_52 = V_28 . V_50 [ V_43 ] . V_40 ;
V_47 [ V_45 ] . V_46 = V_43 ;
V_47 [ V_45 ] . V_53 = V_53 ;
F_50 ( V_53 ,
F_19 ( V_28 . V_50 [ V_43 ] . V_54 ) ) ;
F_51 ( V_53 ,
F_20 ( V_28 . V_50 [ V_43 ] . V_54 ) ) ;
if ( ! ( V_28 . V_50 [ V_43 ] . V_54 & V_119 ) )
F_30 ( L_18 , V_87 ) ;
V_42 = F_52 ( V_53 ) ;
if ( V_42 ) {
F_53 ( V_53 ) ;
goto V_118;
}
V_45 ++ ;
}
return 0 ;
V_118:
for (; V_45 > 0 ; V_45 -- ) {
F_54 ( V_47 [ V_45 - 1 ] . V_53 ) ;
F_53 ( V_47 [ V_45 - 1 ] . V_53 ) ;
}
return V_42 ;
}
static int T_6 F_56 ( struct V_100 * V_50 )
{
int V_42 ;
V_78 = NULL ;
V_80 = NULL ;
V_82 = NULL ;
V_45 = 0 ;
if ( F_48 ( V_50 ) )
F_55 ( V_50 ) ;
V_42 = F_57 ( & V_50 -> V_55 , & V_101 ) ;
if ( V_42 )
goto V_120;
V_42 = F_57 ( & V_50 -> V_55 , & V_102 ) ;
if ( V_42 )
goto V_120;
V_42 = F_57 ( & V_50 -> V_55 , & V_103 ) ;
if ( V_42 )
goto V_120;
V_42 = F_57 ( & V_50 -> V_55 , & V_104 ) ;
if ( V_42 )
goto V_120;
V_42 = F_57 ( & V_50 -> V_55 , & V_105 ) ;
if ( V_42 )
goto V_120;
return 0 ;
V_120:
F_46 ( V_50 ) ;
return V_42 ;
}
static int T_7 F_58 ( struct V_100 * V_50 )
{
int V_43 ;
F_46 ( V_50 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
F_54 ( V_47 [ V_43 ] . V_53 ) ;
F_53 ( V_47 [ V_43 ] . V_53 ) ;
}
if ( V_78 ) {
F_54 ( V_78 ) ;
F_53 ( V_78 ) ;
}
if ( V_80 ) {
F_54 ( V_80 ) ;
F_53 ( V_80 ) ;
}
if ( V_82 ) {
F_54 ( V_82 ) ;
F_53 ( V_82 ) ;
}
return 0 ;
}
static int F_59 ( struct V_50 * V_50 )
{
if ( V_70 ) {
F_31 ( V_70 , V_71 ,
F_10 () ) ;
F_31 ( V_70 , V_72 ,
F_11 () ) ;
F_32 ( V_70 ) ;
}
if ( V_45 )
F_17 () ;
if ( V_78 )
F_18 ( V_78 ,
F_14 ( V_79 ) ,
F_15 ( V_79 ) ) ;
if ( V_80 )
F_18 ( V_80 ,
F_14 ( V_81 ) ,
F_15 ( V_81 ) ) ;
if ( V_82 )
F_18 ( V_82 ,
F_14 ( V_83 ) ,
F_15 ( V_83 ) ) ;
return 0 ;
}
static int T_5 F_60 ( void )
{
int V_42 ;
int V_121 = F_61 ( V_96 ) ;
int V_122 = F_61 ( V_22 ) ;
if ( V_121 ) {
V_42 = F_34 () ;
if ( V_42 )
return V_42 ;
}
if ( V_122 ) {
V_42 = F_62 ( & V_123 ) ;
if ( V_42 )
goto V_124;
V_125 = F_63 ( L_19 , - 1 ) ;
if ( ! V_125 ) {
V_42 = - V_86 ;
goto V_126;
}
V_42 = F_64 ( V_125 ) ;
if ( V_42 )
goto V_127;
}
if ( ! V_122 && ! V_121 )
return - V_128 ;
return 0 ;
V_127:
F_65 ( V_125 ) ;
V_126:
F_66 ( & V_123 ) ;
V_124:
if ( V_121 )
F_44 () ;
return V_42 ;
}
static void T_7 F_67 ( void )
{
if ( F_61 ( V_96 ) )
F_44 () ;
if ( V_125 ) {
F_68 ( V_125 ) ;
F_66 ( & V_123 ) ;
}
}
