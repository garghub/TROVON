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
static int F_21 ( void )
{
int V_28 = 0 ;
int V_29 = F_1 ( V_55 , 0 , & V_28 ,
sizeof( V_28 ) , sizeof( V_28 ) ) ;
if ( V_29 )
return - V_21 ;
return V_28 ;
}
static T_2 F_22 ( struct V_50 * V_56 , struct V_57 * V_58 ,
char * V_59 )
{
int V_60 = F_7 () ;
if ( V_60 < 0 )
return - V_21 ;
return sprintf ( V_59 , L_3 , V_60 ) ;
}
static T_2 F_23 ( struct V_50 * V_56 , struct V_57 * V_58 ,
char * V_59 )
{
int V_60 = F_8 () ;
if ( V_60 < 0 )
return - V_21 ;
return sprintf ( V_59 , L_3 , V_60 ) ;
}
static T_2 F_24 ( struct V_50 * V_56 , struct V_57 * V_58 ,
char * V_59 )
{
int V_60 = F_9 () ;
if ( V_60 < 0 )
return - V_21 ;
return sprintf ( V_59 , L_3 , V_60 ) ;
}
static T_2 F_25 ( struct V_50 * V_56 , struct V_57 * V_58 ,
char * V_59 )
{
int V_60 = F_10 () ;
if ( V_60 < 0 )
return - V_21 ;
return sprintf ( V_59 , L_3 , V_60 ) ;
}
static T_2 F_26 ( struct V_50 * V_56 , struct V_57 * V_58 ,
char * V_59 )
{
int V_60 = F_11 () ;
if ( V_60 < 0 )
return - V_21 ;
return sprintf ( V_59 , L_3 , V_60 ) ;
}
static T_2 F_27 ( struct V_50 * V_56 , struct V_57 * V_58 ,
char * V_59 )
{
int V_60 = F_21 () ;
if ( V_60 < 0 )
return - V_21 ;
return sprintf ( V_59 , L_4 , V_60 ) ;
}
static T_2 F_28 ( struct V_50 * V_56 , struct V_57 * V_58 ,
const char * V_59 , T_3 V_51 )
{
T_1 V_61 = F_29 ( V_59 , NULL , 10 ) ;
int V_29 = F_1 ( V_32 , 1 , & V_61 ,
sizeof( V_61 ) , sizeof( V_61 ) ) ;
if ( V_29 )
return - V_21 ;
return V_51 ;
}
static T_2 F_30 ( struct V_50 * V_56 , struct V_57 * V_58 ,
const char * V_59 , T_3 V_51 )
{
int V_29 ;
T_1 V_61 ;
long unsigned int V_62 ;
V_29 = F_31 ( V_59 , 10 , & V_62 ) ;
if ( V_29 || V_62 != 1 )
return - V_21 ;
V_61 = ( T_1 ) V_62 ;
V_29 = F_1 ( V_55 , 1 , & V_61 ,
sizeof( V_61 ) , sizeof( V_61 ) ) ;
if ( V_29 )
return - V_21 ;
return V_51 ;
}
static void F_32 ( T_1 V_60 , void * V_63 )
{
struct V_16 V_64 = { V_19 , NULL } ;
union V_8 * V_9 ;
T_1 V_65 , V_66 ;
int V_67 = 0 , V_29 ;
T_1 * V_68 ;
T_4 V_69 ;
V_69 = F_33 ( V_60 , & V_64 ) ;
if ( V_69 != V_70 ) {
F_34 ( L_5 , V_69 ) ;
return;
}
V_9 = (union V_8 * ) V_64 . V_23 ;
if ( ! V_9 )
return;
if ( V_9 -> type != V_24 ) {
F_34 ( L_6 , V_9 -> type ) ;
F_4 ( V_9 ) ;
return;
}
V_68 = ( T_1 * ) V_9 -> V_3 . V_23 ;
if ( V_9 -> V_3 . V_27 == 8 ) {
V_65 = * V_68 ;
V_66 = * ( V_68 + 1 ) ;
} else if ( V_9 -> V_3 . V_27 == 16 ) {
V_65 = * V_68 ;
V_66 = * ( V_68 + 2 ) ;
} else {
F_34 ( L_7 , V_9 -> V_3 . V_27 ) ;
F_4 ( V_9 ) ;
return;
}
F_4 ( V_9 ) ;
switch ( V_65 ) {
case V_71 :
F_35 ( V_72 , V_73 ,
F_10 () ) ;
F_35 ( V_72 , V_74 ,
F_11 () ) ;
F_36 ( V_72 ) ;
break;
case V_75 :
break;
case V_76 :
break;
case V_77 :
V_29 = F_1 ( V_78 , 0 ,
& V_67 ,
sizeof( V_67 ) ,
sizeof( V_67 ) ) ;
if ( V_29 )
break;
if ( ! F_37 ( V_72 ,
V_67 , 1 , true ) )
F_34 ( L_8 , V_67 ) ;
break;
case V_79 :
if ( V_45 ) {
F_17 () ;
break;
}
if ( V_80 )
F_18 ( V_80 ,
F_14 ( V_81 ) ,
F_15 ( V_81 ) ) ;
if ( V_82 )
F_18 ( V_82 ,
F_14 ( V_83 ) ,
F_15 ( V_83 ) ) ;
if ( V_84 )
F_18 ( V_84 ,
F_14 ( V_85 ) ,
F_15 ( V_85 ) ) ;
if ( V_86 )
F_18 ( V_86 ,
F_14 ( V_87 ) ,
F_15 ( V_87 ) ) ;
break;
case V_88 :
F_34 ( L_9 ) ;
break;
case V_89 :
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
default:
F_34 ( L_10 , V_65 , V_66 ) ;
break;
}
}
static int T_5 F_38 ( void )
{
T_4 V_69 ;
int V_42 ;
V_72 = F_39 () ;
if ( ! V_72 )
return - V_98 ;
V_72 -> V_99 = L_11 ;
V_72 -> V_100 = L_12 ;
V_72 -> V_52 . V_101 = V_102 ;
F_40 ( V_103 , V_72 -> V_104 ) ;
F_40 ( V_73 , V_72 -> V_105 ) ;
F_40 ( V_74 , V_72 -> V_105 ) ;
V_42 = F_41 ( V_72 , V_106 , NULL ) ;
if ( V_42 )
goto V_107;
F_35 ( V_72 , V_73 , F_10 () ) ;
F_35 ( V_72 , V_74 ,
F_11 () ) ;
F_36 ( V_72 ) ;
V_69 = F_42 ( V_108 , F_32 , NULL ) ;
if ( F_43 ( V_69 ) ) {
V_42 = - V_109 ;
goto V_110;
}
V_42 = F_44 ( V_72 ) ;
if ( V_42 )
goto V_111;
return 0 ;
V_111:
F_45 ( V_108 ) ;
V_110:
F_46 ( V_72 ) ;
V_107:
F_47 ( V_72 ) ;
return V_42 ;
}
static void F_48 ( void )
{
F_45 ( V_108 ) ;
F_46 ( V_72 ) ;
F_49 ( V_72 ) ;
}
static void F_50 ( struct V_112 * V_50 )
{
F_51 ( & V_50 -> V_56 , & V_113 ) ;
F_51 ( & V_50 -> V_56 , & V_114 ) ;
F_51 ( & V_50 -> V_56 , & V_115 ) ;
F_51 ( & V_50 -> V_56 , & V_116 ) ;
F_51 ( & V_50 -> V_56 , & V_117 ) ;
F_51 ( & V_50 -> V_56 , & V_118 ) ;
}
static int F_52 ( struct V_112 * V_50 )
{
int V_42 ;
int V_38 = 0 ;
V_42 = F_1 ( V_37 , 0 , & V_38 ,
sizeof( V_38 ) , sizeof( V_38 ) ) ;
if ( V_42 )
return V_42 ;
if ( V_38 & 0x1 ) {
V_80 = F_53 ( L_13 , & V_50 -> V_56 ,
V_119 ,
& V_120 ,
( void * ) V_81 ) ;
if ( ! V_80 )
return - V_98 ;
F_54 ( V_80 ,
F_14 ( V_81 ) ) ;
F_55 ( V_80 ,
F_15 ( V_81 ) ) ;
V_42 = F_56 ( V_80 ) ;
if ( V_42 )
goto V_121;
}
if ( V_38 & 0x2 ) {
V_82 = F_53 ( L_14 , & V_50 -> V_56 ,
V_122 ,
& V_120 ,
( void * ) V_83 ) ;
if ( ! V_82 ) {
V_42 = - V_98 ;
goto V_121;
}
F_54 ( V_82 ,
F_14 ( V_83 ) ) ;
F_55 ( V_82 ,
F_15 ( V_83 ) ) ;
V_42 = F_56 ( V_82 ) ;
if ( V_42 )
goto V_123;
}
if ( V_38 & 0x4 ) {
V_84 = F_53 ( L_15 , & V_50 -> V_56 ,
V_124 ,
& V_120 ,
( void * ) V_85 ) ;
if ( ! V_84 ) {
V_42 = - V_98 ;
goto V_123;
}
F_54 ( V_84 ,
F_14 ( V_85 ) ) ;
F_55 ( V_84 ,
F_15 ( V_85 ) ) ;
V_42 = F_56 ( V_84 ) ;
if ( V_42 )
goto V_125;
}
if ( V_38 & 0x8 ) {
V_86 = F_53 ( L_16 , & V_50 -> V_56 ,
V_126 ,
& V_120 ,
( void * ) V_87 ) ;
if ( ! V_86 ) {
V_42 = - V_98 ;
goto V_125;
}
F_54 ( V_86 ,
F_14 ( V_87 ) ) ;
F_55 ( V_86 ,
F_15 ( V_87 ) ) ;
V_42 = F_56 ( V_86 ) ;
if ( V_42 )
goto V_127;
}
return 0 ;
V_127:
F_57 ( V_86 ) ;
V_86 = NULL ;
if ( V_82 )
F_58 ( V_82 ) ;
V_125:
F_57 ( V_84 ) ;
V_84 = NULL ;
if ( V_86 )
F_58 ( V_86 ) ;
V_123:
F_57 ( V_82 ) ;
V_82 = NULL ;
if ( V_80 )
F_58 ( V_80 ) ;
V_121:
F_57 ( V_80 ) ;
V_80 = NULL ;
return V_42 ;
}
static int F_59 ( struct V_112 * V_50 )
{
int V_42 , V_43 ;
struct V_44 V_28 ;
V_42 = F_1 ( V_41 , 0 , & V_28 ,
0 , sizeof( V_28 ) ) ;
if ( V_42 )
return V_42 ;
if ( V_28 . V_51 > V_128 ) {
F_5 ( L_17 ) ;
return - V_21 ;
}
for ( V_43 = 0 ; V_43 < V_28 . V_51 ; V_43 ++ ) {
struct V_53 * V_53 ;
enum V_129 type ;
char * V_99 ;
switch ( V_28 . V_50 [ V_43 ] . V_130 ) {
case V_81 :
type = V_119 ;
V_99 = L_13 ;
break;
case V_83 :
type = V_122 ;
V_99 = L_14 ;
break;
case V_85 :
type = V_124 ;
V_99 = L_15 ;
break;
case V_87 :
type = V_126 ;
V_99 = L_16 ;
break;
default:
F_5 ( L_18 ,
V_28 . V_50 [ V_43 ] . V_130 ) ;
continue;
}
if ( ! V_28 . V_50 [ V_43 ] . V_131 ) {
F_5 ( L_19 ,
V_43 , V_28 . V_51 ) ;
continue;
}
V_53 = F_53 ( V_99 , & V_50 -> V_56 , type ,
& V_132 , ( void * ) ( long ) V_43 ) ;
if ( ! V_53 ) {
V_42 = - V_98 ;
goto V_133;
}
V_47 [ V_45 ] . V_52 = V_28 . V_50 [ V_43 ] . V_40 ;
V_47 [ V_45 ] . V_46 = V_43 ;
V_47 [ V_45 ] . V_53 = V_53 ;
F_54 ( V_53 ,
F_19 ( V_28 . V_50 [ V_43 ] . V_54 ) ) ;
F_55 ( V_53 ,
F_20 ( V_28 . V_50 [ V_43 ] . V_54 ) ) ;
if ( ! ( V_28 . V_50 [ V_43 ] . V_54 & V_134 ) )
F_34 ( L_20 , V_99 ) ;
V_42 = F_56 ( V_53 ) ;
if ( V_42 ) {
F_57 ( V_53 ) ;
goto V_133;
}
V_45 ++ ;
}
return 0 ;
V_133:
for (; V_45 > 0 ; V_45 -- ) {
F_58 ( V_47 [ V_45 - 1 ] . V_53 ) ;
F_57 ( V_47 [ V_45 - 1 ] . V_53 ) ;
}
return V_42 ;
}
static int T_5 F_60 ( struct V_112 * V_50 )
{
int V_42 ;
V_80 = NULL ;
V_82 = NULL ;
V_84 = NULL ;
V_86 = NULL ;
V_45 = 0 ;
if ( F_52 ( V_50 ) )
F_59 ( V_50 ) ;
V_42 = F_61 ( & V_50 -> V_56 , & V_113 ) ;
if ( V_42 )
goto V_135;
V_42 = F_61 ( & V_50 -> V_56 , & V_114 ) ;
if ( V_42 )
goto V_135;
V_42 = F_61 ( & V_50 -> V_56 , & V_115 ) ;
if ( V_42 )
goto V_135;
V_42 = F_61 ( & V_50 -> V_56 , & V_116 ) ;
if ( V_42 )
goto V_135;
V_42 = F_61 ( & V_50 -> V_56 , & V_117 ) ;
if ( V_42 )
goto V_135;
V_42 = F_61 ( & V_50 -> V_56 , & V_118 ) ;
if ( V_42 )
goto V_135;
return 0 ;
V_135:
F_50 ( V_50 ) ;
return V_42 ;
}
static int T_6 F_62 ( struct V_112 * V_50 )
{
int V_43 ;
F_50 ( V_50 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
F_58 ( V_47 [ V_43 ] . V_53 ) ;
F_57 ( V_47 [ V_43 ] . V_53 ) ;
}
if ( V_80 ) {
F_58 ( V_80 ) ;
F_57 ( V_80 ) ;
}
if ( V_82 ) {
F_58 ( V_82 ) ;
F_57 ( V_82 ) ;
}
if ( V_84 ) {
F_58 ( V_84 ) ;
F_57 ( V_84 ) ;
}
if ( V_86 ) {
F_58 ( V_86 ) ;
F_57 ( V_86 ) ;
}
return 0 ;
}
static int F_63 ( struct V_50 * V_50 )
{
if ( V_72 ) {
F_35 ( V_72 , V_73 ,
F_10 () ) ;
F_35 ( V_72 , V_74 ,
F_11 () ) ;
F_36 ( V_72 ) ;
}
if ( V_45 )
F_17 () ;
if ( V_80 )
F_18 ( V_80 ,
F_14 ( V_81 ) ,
F_15 ( V_81 ) ) ;
if ( V_82 )
F_18 ( V_82 ,
F_14 ( V_83 ) ,
F_15 ( V_83 ) ) ;
if ( V_84 )
F_18 ( V_84 ,
F_14 ( V_85 ) ,
F_15 ( V_85 ) ) ;
if ( V_86 )
F_18 ( V_86 ,
F_14 ( V_87 ) ,
F_15 ( V_87 ) ) ;
return 0 ;
}
static int T_5 F_64 ( void )
{
int V_42 ;
int V_136 = F_65 ( V_108 ) ;
int V_137 = F_65 ( V_22 ) ;
if ( ! V_137 && ! V_136 )
return - V_138 ;
if ( V_136 ) {
V_42 = F_38 () ;
if ( V_42 )
return V_42 ;
}
if ( V_137 ) {
V_139 =
F_66 ( L_21 , - 1 , NULL , 0 ) ;
if ( F_67 ( V_139 ) ) {
V_42 = F_68 ( V_139 ) ;
goto V_140;
}
V_42 = F_69 ( & V_141 , F_60 ) ;
if ( V_42 )
goto V_142;
}
return 0 ;
V_142:
F_70 ( V_139 ) ;
V_140:
if ( V_136 )
F_48 () ;
return V_42 ;
}
static void T_6 F_71 ( void )
{
if ( F_65 ( V_108 ) )
F_48 () ;
if ( V_139 ) {
F_70 ( V_139 ) ;
F_72 ( & V_141 ) ;
}
}
