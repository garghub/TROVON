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
static int F_12 ( void )
{
int V_28 = 0 ;
int V_29 = F_1 ( V_34 , 0 , & V_28 ,
sizeof( V_28 ) , sizeof( V_28 ) ) ;
if ( V_29 )
return V_29 ;
return ( V_28 & 0x10 ) ? 1 : 0 ;
}
static int F_13 ( void * V_15 , bool V_35 )
{
enum V_36 V_37 = (enum V_36 ) V_15 ;
int V_1 = F_14 ( V_37 + 8 ) | ( ( ! V_35 ) << V_37 ) ;
int V_29 ;
V_29 = F_1 ( V_38 , 1 ,
& V_1 , sizeof( V_1 ) , 0 ) ;
if ( V_29 )
return - V_21 ;
return 0 ;
}
static bool F_15 ( enum V_36 V_37 )
{
int V_39 = 0 ;
int V_40 ;
F_1 ( V_38 , 0 ,
& V_39 , sizeof( V_39 ) ,
sizeof( V_39 ) ) ;
V_40 = 0x200 << ( V_37 * 8 ) ;
if ( V_39 & V_40 )
return false ;
else
return true ;
}
static bool F_16 ( enum V_36 V_37 )
{
int V_39 = 0 ;
int V_40 ;
F_1 ( V_38 , 0 ,
& V_39 , sizeof( V_39 ) ,
sizeof( V_39 ) ) ;
V_40 = 0x800 << ( V_37 * 8 ) ;
if ( V_39 & V_40 )
return false ;
else
return true ;
}
static int F_17 ( void * V_15 , bool V_35 )
{
int V_41 = ( int ) ( long ) V_15 ;
char V_3 [ 4 ] = { 0x01 , 0x00 , V_41 , ! V_35 } ;
if ( F_1 ( V_42 , 1 ,
V_3 , sizeof( V_3 ) , 0 ) )
return - V_21 ;
return 0 ;
}
static int F_18 ( void )
{
int V_43 , V_44 ;
struct V_45 V_28 ;
V_43 = F_1 ( V_42 , 0 , & V_28 ,
0 , sizeof( V_28 ) ) ;
if ( V_43 )
return V_43 ;
for ( V_44 = 0 ; V_44 < V_46 ; V_44 ++ ) {
int V_47 = V_48 [ V_44 ] . V_47 ;
struct V_49 * V_50 ;
V_50 = & V_28 . V_51 [ V_47 ] ;
if ( V_47 >= V_28 . V_52 ||
V_50 -> V_41 != V_48 [ V_44 ] . V_53 ) {
F_5 ( L_2 ) ;
continue;
}
F_19 ( V_48 [ V_44 ] . V_54 ,
F_20 ( V_50 -> V_55 ) ,
F_21 ( V_50 -> V_55 ) ) ;
}
return 0 ;
}
static int F_22 ( void )
{
int V_28 = 0 ;
int V_29 = F_1 ( V_56 , 0 , & V_28 ,
sizeof( V_28 ) , sizeof( V_28 ) ) ;
if ( V_29 )
return - V_21 ;
return V_28 ;
}
static T_2 F_23 ( struct V_51 * V_57 , struct V_58 * V_59 ,
char * V_60 )
{
int V_61 = F_7 () ;
if ( V_61 < 0 )
return - V_21 ;
return sprintf ( V_60 , L_3 , V_61 ) ;
}
static T_2 F_24 ( struct V_51 * V_57 , struct V_58 * V_59 ,
char * V_60 )
{
int V_61 = F_8 () ;
if ( V_61 < 0 )
return - V_21 ;
return sprintf ( V_60 , L_3 , V_61 ) ;
}
static T_2 F_25 ( struct V_51 * V_57 , struct V_58 * V_59 ,
char * V_60 )
{
int V_61 = F_9 () ;
if ( V_61 < 0 )
return - V_21 ;
return sprintf ( V_60 , L_3 , V_61 ) ;
}
static T_2 F_26 ( struct V_51 * V_57 , struct V_58 * V_59 ,
char * V_60 )
{
int V_61 = F_10 () ;
if ( V_61 < 0 )
return - V_21 ;
return sprintf ( V_60 , L_3 , V_61 ) ;
}
static T_2 F_27 ( struct V_51 * V_57 , struct V_58 * V_59 ,
char * V_60 )
{
int V_61 = F_11 () ;
if ( V_61 < 0 )
return - V_21 ;
return sprintf ( V_60 , L_3 , V_61 ) ;
}
static T_2 F_28 ( struct V_51 * V_57 , struct V_58 * V_59 ,
char * V_60 )
{
int V_61 = F_22 () ;
if ( V_61 < 0 )
return - V_21 ;
return sprintf ( V_60 , L_4 , V_61 ) ;
}
static T_2 F_29 ( struct V_51 * V_57 , struct V_58 * V_59 ,
const char * V_60 , T_3 V_52 )
{
T_1 V_62 = F_30 ( V_60 , NULL , 10 ) ;
int V_29 = F_1 ( V_32 , 1 , & V_62 ,
sizeof( V_62 ) , sizeof( V_62 ) ) ;
if ( V_29 )
return - V_21 ;
return V_52 ;
}
static T_2 F_31 ( struct V_51 * V_57 , struct V_58 * V_59 ,
const char * V_60 , T_3 V_52 )
{
int V_29 ;
T_1 V_62 ;
long unsigned int V_63 ;
V_29 = F_32 ( V_60 , 10 , & V_63 ) ;
if ( V_29 || V_63 != 1 )
return - V_21 ;
V_62 = ( T_1 ) V_63 ;
V_29 = F_1 ( V_56 , 1 , & V_62 ,
sizeof( V_62 ) , sizeof( V_62 ) ) ;
if ( V_29 )
return - V_21 ;
return V_52 ;
}
static void F_33 ( T_1 V_61 , void * V_64 )
{
struct V_16 V_65 = { V_19 , NULL } ;
union V_8 * V_9 ;
T_1 V_66 , V_67 ;
int V_68 = 0 , V_29 ;
T_1 * V_69 ;
T_4 V_70 ;
V_70 = F_34 ( V_61 , & V_65 ) ;
if ( V_70 != V_71 ) {
F_35 ( L_5 , V_70 ) ;
return;
}
V_9 = (union V_8 * ) V_65 . V_23 ;
if ( ! V_9 )
return;
if ( V_9 -> type != V_24 ) {
F_35 ( L_6 , V_9 -> type ) ;
F_4 ( V_9 ) ;
return;
}
V_69 = ( T_1 * ) V_9 -> V_3 . V_23 ;
if ( V_9 -> V_3 . V_27 == 8 ) {
V_66 = * V_69 ;
V_67 = * ( V_69 + 1 ) ;
} else if ( V_9 -> V_3 . V_27 == 16 ) {
V_66 = * V_69 ;
V_67 = * ( V_69 + 2 ) ;
} else {
F_35 ( L_7 , V_9 -> V_3 . V_27 ) ;
F_4 ( V_9 ) ;
return;
}
F_4 ( V_9 ) ;
switch ( V_66 ) {
case V_72 :
F_36 ( V_73 , V_74 ,
F_10 () ) ;
F_36 ( V_73 , V_75 ,
F_11 () ) ;
F_37 ( V_73 ) ;
break;
case V_76 :
break;
case V_77 :
break;
case V_78 :
V_29 = F_1 ( V_79 , 0 ,
& V_68 ,
sizeof( V_68 ) ,
sizeof( V_68 ) ) ;
if ( V_29 )
break;
if ( ! F_38 ( V_73 ,
V_68 , 1 , true ) )
F_35 ( L_8 , V_68 ) ;
break;
case V_80 :
if ( V_46 ) {
F_18 () ;
break;
}
if ( V_81 )
F_19 ( V_81 ,
F_15 ( V_82 ) ,
F_16 ( V_82 ) ) ;
if ( V_83 )
F_19 ( V_83 ,
F_15 ( V_84 ) ,
F_16 ( V_84 ) ) ;
if ( V_85 )
F_19 ( V_85 ,
F_15 ( V_86 ) ,
F_16 ( V_86 ) ) ;
if ( V_87 )
F_19 ( V_87 ,
F_15 ( V_88 ) ,
F_16 ( V_88 ) ) ;
break;
case V_89 :
F_35 ( L_9 ) ;
break;
case V_90 :
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
default:
F_35 ( L_10 , V_66 , V_67 ) ;
break;
}
}
static int T_5 F_39 ( void )
{
T_4 V_70 ;
int V_43 ;
V_73 = F_40 () ;
if ( ! V_73 )
return - V_99 ;
V_73 -> V_100 = L_11 ;
V_73 -> V_101 = L_12 ;
V_73 -> V_53 . V_102 = V_103 ;
F_41 ( V_104 , V_73 -> V_105 ) ;
F_41 ( V_74 , V_73 -> V_106 ) ;
F_41 ( V_75 , V_73 -> V_106 ) ;
V_43 = F_42 ( V_73 , V_107 , NULL ) ;
if ( V_43 )
goto V_108;
F_36 ( V_73 , V_74 , F_10 () ) ;
F_36 ( V_73 , V_75 ,
F_11 () ) ;
F_37 ( V_73 ) ;
V_70 = F_43 ( V_109 , F_33 , NULL ) ;
if ( F_44 ( V_70 ) ) {
V_43 = - V_110 ;
goto V_111;
}
V_43 = F_45 ( V_73 ) ;
if ( V_43 )
goto V_112;
return 0 ;
V_112:
F_46 ( V_109 ) ;
V_111:
F_47 ( V_73 ) ;
V_108:
F_48 ( V_73 ) ;
return V_43 ;
}
static void F_49 ( void )
{
F_46 ( V_109 ) ;
F_47 ( V_73 ) ;
F_50 ( V_73 ) ;
}
static void F_51 ( struct V_113 * V_51 )
{
F_52 ( & V_51 -> V_57 , & V_114 ) ;
F_52 ( & V_51 -> V_57 , & V_115 ) ;
F_52 ( & V_51 -> V_57 , & V_116 ) ;
F_52 ( & V_51 -> V_57 , & V_117 ) ;
F_52 ( & V_51 -> V_57 , & V_118 ) ;
F_52 ( & V_51 -> V_57 , & V_119 ) ;
}
static int F_53 ( struct V_113 * V_51 )
{
int V_43 ;
int V_39 = 0 ;
V_43 = F_1 ( V_38 , 0 , & V_39 ,
sizeof( V_39 ) , sizeof( V_39 ) ) ;
if ( V_43 )
return V_43 ;
if ( V_39 & 0x1 ) {
V_81 = F_54 ( L_13 , & V_51 -> V_57 ,
V_120 ,
& V_121 ,
( void * ) V_82 ) ;
if ( ! V_81 )
return - V_99 ;
F_55 ( V_81 ,
F_15 ( V_82 ) ) ;
F_56 ( V_81 ,
F_16 ( V_82 ) ) ;
V_43 = F_57 ( V_81 ) ;
if ( V_43 )
goto V_122;
}
if ( V_39 & 0x2 ) {
V_83 = F_54 ( L_14 , & V_51 -> V_57 ,
V_123 ,
& V_121 ,
( void * ) V_84 ) ;
if ( ! V_83 ) {
V_43 = - V_99 ;
goto V_122;
}
F_55 ( V_83 ,
F_15 ( V_84 ) ) ;
F_56 ( V_83 ,
F_16 ( V_84 ) ) ;
V_43 = F_57 ( V_83 ) ;
if ( V_43 )
goto V_124;
}
if ( V_39 & 0x4 ) {
V_85 = F_54 ( L_15 , & V_51 -> V_57 ,
V_125 ,
& V_121 ,
( void * ) V_86 ) ;
if ( ! V_85 ) {
V_43 = - V_99 ;
goto V_124;
}
F_55 ( V_85 ,
F_15 ( V_86 ) ) ;
F_56 ( V_85 ,
F_16 ( V_86 ) ) ;
V_43 = F_57 ( V_85 ) ;
if ( V_43 )
goto V_126;
}
if ( V_39 & 0x8 ) {
V_87 = F_54 ( L_16 , & V_51 -> V_57 ,
V_127 ,
& V_121 ,
( void * ) V_88 ) ;
if ( ! V_87 ) {
V_43 = - V_99 ;
goto V_126;
}
F_55 ( V_87 ,
F_15 ( V_88 ) ) ;
F_56 ( V_87 ,
F_16 ( V_88 ) ) ;
V_43 = F_57 ( V_87 ) ;
if ( V_43 )
goto V_128;
}
return 0 ;
V_128:
F_58 ( V_87 ) ;
V_87 = NULL ;
if ( V_83 )
F_59 ( V_83 ) ;
V_126:
F_58 ( V_85 ) ;
V_85 = NULL ;
if ( V_87 )
F_59 ( V_87 ) ;
V_124:
F_58 ( V_83 ) ;
V_83 = NULL ;
if ( V_81 )
F_59 ( V_81 ) ;
V_122:
F_58 ( V_81 ) ;
V_81 = NULL ;
return V_43 ;
}
static int F_60 ( struct V_113 * V_51 )
{
int V_43 , V_44 ;
struct V_45 V_28 ;
V_43 = F_1 ( V_42 , 0 , & V_28 ,
0 , sizeof( V_28 ) ) ;
if ( V_43 )
return V_43 ;
if ( V_28 . V_52 > V_129 ) {
F_5 ( L_17 ) ;
return - V_21 ;
}
for ( V_44 = 0 ; V_44 < V_28 . V_52 ; V_44 ++ ) {
struct V_54 * V_54 ;
enum V_130 type ;
char * V_100 ;
switch ( V_28 . V_51 [ V_44 ] . V_131 ) {
case V_82 :
type = V_120 ;
V_100 = L_13 ;
break;
case V_84 :
type = V_123 ;
V_100 = L_14 ;
break;
case V_86 :
type = V_125 ;
V_100 = L_15 ;
break;
case V_88 :
type = V_127 ;
V_100 = L_16 ;
break;
default:
F_5 ( L_18 ,
V_28 . V_51 [ V_44 ] . V_131 ) ;
continue;
}
if ( ! V_28 . V_51 [ V_44 ] . V_132 ) {
F_5 ( L_19 ,
V_44 , V_28 . V_52 ) ;
continue;
}
V_54 = F_54 ( V_100 , & V_51 -> V_57 , type ,
& V_133 , ( void * ) ( long ) V_44 ) ;
if ( ! V_54 ) {
V_43 = - V_99 ;
goto V_134;
}
V_48 [ V_46 ] . V_53 = V_28 . V_51 [ V_44 ] . V_41 ;
V_48 [ V_46 ] . V_47 = V_44 ;
V_48 [ V_46 ] . V_54 = V_54 ;
F_55 ( V_54 ,
F_20 ( V_28 . V_51 [ V_44 ] . V_55 ) ) ;
F_56 ( V_54 ,
F_21 ( V_28 . V_51 [ V_44 ] . V_55 ) ) ;
if ( ! ( V_28 . V_51 [ V_44 ] . V_55 & V_135 ) )
F_35 ( L_20 , V_100 ) ;
V_43 = F_57 ( V_54 ) ;
if ( V_43 ) {
F_58 ( V_54 ) ;
goto V_134;
}
V_46 ++ ;
}
return 0 ;
V_134:
for (; V_46 > 0 ; V_46 -- ) {
F_59 ( V_48 [ V_46 - 1 ] . V_54 ) ;
F_58 ( V_48 [ V_46 - 1 ] . V_54 ) ;
}
return V_43 ;
}
static int T_5 F_61 ( struct V_113 * V_51 )
{
int V_43 ;
V_81 = NULL ;
V_83 = NULL ;
V_85 = NULL ;
V_87 = NULL ;
V_46 = 0 ;
if ( F_12 () || F_53 ( V_51 ) )
F_60 ( V_51 ) ;
V_43 = F_62 ( & V_51 -> V_57 , & V_114 ) ;
if ( V_43 )
goto V_136;
V_43 = F_62 ( & V_51 -> V_57 , & V_115 ) ;
if ( V_43 )
goto V_136;
V_43 = F_62 ( & V_51 -> V_57 , & V_116 ) ;
if ( V_43 )
goto V_136;
V_43 = F_62 ( & V_51 -> V_57 , & V_117 ) ;
if ( V_43 )
goto V_136;
V_43 = F_62 ( & V_51 -> V_57 , & V_118 ) ;
if ( V_43 )
goto V_136;
V_43 = F_62 ( & V_51 -> V_57 , & V_119 ) ;
if ( V_43 )
goto V_136;
return 0 ;
V_136:
F_51 ( V_51 ) ;
return V_43 ;
}
static int T_6 F_63 ( struct V_113 * V_51 )
{
int V_44 ;
F_51 ( V_51 ) ;
for ( V_44 = 0 ; V_44 < V_46 ; V_44 ++ ) {
F_59 ( V_48 [ V_44 ] . V_54 ) ;
F_58 ( V_48 [ V_44 ] . V_54 ) ;
}
if ( V_81 ) {
F_59 ( V_81 ) ;
F_58 ( V_81 ) ;
}
if ( V_83 ) {
F_59 ( V_83 ) ;
F_58 ( V_83 ) ;
}
if ( V_85 ) {
F_59 ( V_85 ) ;
F_58 ( V_85 ) ;
}
if ( V_87 ) {
F_59 ( V_87 ) ;
F_58 ( V_87 ) ;
}
return 0 ;
}
static int F_64 ( struct V_51 * V_51 )
{
if ( V_73 ) {
F_36 ( V_73 , V_74 ,
F_10 () ) ;
F_36 ( V_73 , V_75 ,
F_11 () ) ;
F_37 ( V_73 ) ;
}
if ( V_46 )
F_18 () ;
if ( V_81 )
F_19 ( V_81 ,
F_15 ( V_82 ) ,
F_16 ( V_82 ) ) ;
if ( V_83 )
F_19 ( V_83 ,
F_15 ( V_84 ) ,
F_16 ( V_84 ) ) ;
if ( V_85 )
F_19 ( V_85 ,
F_15 ( V_86 ) ,
F_16 ( V_86 ) ) ;
if ( V_87 )
F_19 ( V_87 ,
F_15 ( V_88 ) ,
F_16 ( V_88 ) ) ;
return 0 ;
}
static int T_5 F_65 ( void )
{
int V_43 ;
int V_137 = F_66 ( V_109 ) ;
int V_138 = F_66 ( V_22 ) ;
if ( ! V_138 && ! V_137 )
return - V_139 ;
if ( V_137 ) {
V_43 = F_39 () ;
if ( V_43 )
return V_43 ;
}
if ( V_138 ) {
V_140 =
F_67 ( L_21 , - 1 , NULL , 0 ) ;
if ( F_68 ( V_140 ) ) {
V_43 = F_69 ( V_140 ) ;
goto V_141;
}
V_43 = F_70 ( & V_142 , F_61 ) ;
if ( V_43 )
goto V_143;
}
return 0 ;
V_143:
F_71 ( V_140 ) ;
V_141:
if ( V_137 )
F_49 () ;
return V_43 ;
}
static void T_6 F_72 ( void )
{
if ( F_66 ( V_109 ) )
F_49 () ;
if ( V_140 ) {
F_71 ( V_140 ) ;
F_73 ( & V_142 ) ;
}
}
