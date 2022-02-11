static int F_1 ( int V_1 , enum V_2 V_3 ,
void * V_4 , int V_5 , int V_6 )
{
struct V_7 * V_7 ;
int V_8 ;
union V_9 * V_10 ;
struct V_11 args = {
. V_12 = 0x55434553 ,
. V_3 = V_3 ,
. V_13 = V_1 ,
. V_14 = V_5 ,
. V_15 = 0 ,
} ;
struct V_16 V_17 = { sizeof( struct V_11 ) , & args } ;
struct V_16 V_18 = { V_19 , NULL } ;
int V_20 = 0 ;
if ( F_2 ( V_5 > sizeof( args . V_15 ) ) )
return - V_21 ;
memcpy ( & args . V_15 , V_4 , V_5 ) ;
F_3 ( V_22 , 0 , 0x3 , & V_17 , & V_18 ) ;
V_10 = V_18 . V_23 ;
if ( ! V_10 )
return - V_21 ;
if ( V_10 -> type != V_24 ) {
V_20 = - V_21 ;
goto V_25;
}
V_7 = (struct V_7 * ) V_10 -> V_4 . V_23 ;
V_20 = V_7 -> V_26 ;
if ( V_20 ) {
if ( V_20 != V_27 )
F_4 ( L_1 , V_1 , V_20 ) ;
goto V_25;
}
if ( ! V_6 )
goto V_25;
V_8 = F_5 ( V_6 , ( int ) ( V_10 -> V_4 . V_28 - sizeof( * V_7 ) ) ) ;
memcpy ( V_4 , V_10 -> V_4 . V_23 + sizeof( * V_7 ) , V_8 ) ;
memset ( V_4 + V_8 , 0 , V_6 - V_8 ) ;
V_25:
F_6 ( V_10 ) ;
return V_20 ;
}
static int F_7 ( int V_1 )
{
int V_29 = 0 , V_20 ;
V_20 = F_1 ( V_1 , V_30 , & V_29 ,
sizeof( V_29 ) , sizeof( V_29 ) ) ;
if ( V_20 )
return V_20 < 0 ? V_20 : - V_21 ;
return V_29 ;
}
static int F_8 ( int V_31 )
{
int V_32 = F_7 ( V_33 ) ;
if ( V_32 < 0 )
return V_32 ;
return V_32 & 0x1 ;
}
static int T_1 F_9 ( void )
{
int V_32 = 0 ;
int V_20 = F_1 ( V_34 , V_30 , & V_32 ,
sizeof( V_32 ) , sizeof( V_32 ) ) ;
if ( ! V_20 )
return 1 ;
return ( V_20 == V_27 ) ? 0 : - V_35 ;
}
static int T_1 F_10 ( void )
{
int V_32 = 0 ;
int V_20 = F_1 ( V_36 , V_30 , & V_32 ,
sizeof( V_32 ) , sizeof( V_32 ) ) ;
if ( ! V_20 )
return 1 ;
return ( V_20 == V_27 ) ? 0 : - V_35 ;
}
static int T_1 F_11 ( void )
{
int V_37 = 0x6e ;
int V_20 = F_1 ( V_38 , V_39 , & V_37 ,
sizeof( V_37 ) , 0 ) ;
return V_20 <= 0 ? V_20 : - V_21 ;
}
static int F_12 ( void * V_15 , bool V_40 )
{
enum V_41 V_42 = (enum V_41 ) V_15 ;
int V_1 = F_13 ( V_42 + 8 ) | ( ( ! V_40 ) << V_42 ) ;
int V_20 ;
V_20 = F_1 ( V_43 , V_39 ,
& V_1 , sizeof( V_1 ) , 0 ) ;
return V_20 <= 0 ? V_20 : - V_21 ;
}
static bool F_14 ( enum V_41 V_42 )
{
int V_31 = 0x200 << ( V_42 * 8 ) ;
int V_44 = F_7 ( V_43 ) ;
F_15 ( V_44 < 0 , L_2 ) ;
return ! ( V_44 & V_31 ) ;
}
static bool F_16 ( enum V_41 V_42 )
{
int V_31 = 0x800 << ( V_42 * 8 ) ;
int V_44 = F_7 ( V_43 ) ;
F_15 ( V_44 < 0 , L_2 ) ;
return ! ( V_44 & V_31 ) ;
}
static int F_17 ( void * V_15 , bool V_40 )
{
int V_45 = ( int ) ( long ) V_15 ;
char V_4 [ 4 ] = { 0x01 , 0x00 , V_45 , ! V_40 } ;
int V_20 ;
V_20 = F_1 ( V_46 , V_39 ,
V_4 , sizeof( V_4 ) , 0 ) ;
return V_20 <= 0 ? V_20 : - V_21 ;
}
static int F_18 ( void )
{
struct V_47 V_32 ;
int V_48 , V_49 ;
V_48 = F_1 ( V_46 , V_30 , & V_32 ,
0 , sizeof( V_32 ) ) ;
if ( V_48 )
return V_48 ;
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ ) {
int V_51 = V_52 [ V_49 ] . V_51 ;
struct V_53 * V_54 ;
V_54 = & V_32 . V_55 [ V_51 ] ;
if ( V_51 >= V_32 . V_56 ||
V_54 -> V_45 != V_52 [ V_49 ] . V_57 ) {
F_4 ( L_3 ) ;
continue;
}
F_19 ( V_52 [ V_49 ] . V_58 ,
F_20 ( V_54 -> V_59 ) ,
F_21 ( V_54 -> V_59 ) ) ;
}
return 0 ;
}
static T_2 F_22 ( struct V_55 * V_60 , struct V_61 * V_62 ,
char * V_63 )
{
int V_37 = F_7 ( V_64 ) ;
if ( V_37 < 0 )
return V_37 ;
return sprintf ( V_63 , L_4 , V_37 ) ;
}
static T_2 F_23 ( struct V_55 * V_60 , struct V_61 * V_62 ,
char * V_63 )
{
int V_37 = F_7 ( V_65 ) ;
if ( V_37 < 0 )
return V_37 ;
return sprintf ( V_63 , L_4 , V_37 ) ;
}
static T_2 F_24 ( struct V_55 * V_60 , struct V_61 * V_62 ,
char * V_63 )
{
int V_37 = F_7 ( V_66 ) ;
if ( V_37 < 0 )
return V_37 ;
return sprintf ( V_63 , L_4 , V_37 ) ;
}
static T_2 F_25 ( struct V_55 * V_60 , struct V_61 * V_62 ,
char * V_63 )
{
int V_37 = F_8 ( V_67 ) ;
if ( V_37 < 0 )
return V_37 ;
return sprintf ( V_63 , L_4 , V_37 ) ;
}
static T_2 F_26 ( struct V_55 * V_60 , struct V_61 * V_62 ,
char * V_63 )
{
int V_37 = F_8 ( V_68 ) ;
if ( V_37 < 0 )
return V_37 ;
return sprintf ( V_63 , L_4 , V_37 ) ;
}
static T_2 F_27 ( struct V_55 * V_60 , struct V_61 * V_62 ,
char * V_63 )
{
int V_37 = F_7 ( V_69 ) ;
if ( V_37 < 0 )
return V_37 ;
return sprintf ( V_63 , L_5 , V_37 ) ;
}
static T_2 F_28 ( struct V_55 * V_60 , struct V_61 * V_62 ,
const char * V_63 , T_3 V_56 )
{
T_4 V_70 = F_29 ( V_63 , NULL , 10 ) ;
int V_20 = F_1 ( V_66 , V_39 , & V_70 ,
sizeof( V_70 ) , sizeof( V_70 ) ) ;
if ( V_20 )
return V_20 < 0 ? V_20 : - V_21 ;
return V_56 ;
}
static T_2 F_30 ( struct V_55 * V_60 , struct V_61 * V_62 ,
const char * V_63 , T_3 V_56 )
{
long unsigned int V_71 ;
int V_20 ;
T_4 V_70 ;
V_20 = F_31 ( V_63 , 10 , & V_71 ) ;
if ( ! V_20 && V_71 != 1 )
V_20 = - V_21 ;
if ( V_20 )
goto V_72;
V_70 = ( T_4 ) V_71 ;
V_20 = F_1 ( V_69 , V_39 , & V_70 ,
sizeof( V_70 ) , sizeof( V_70 ) ) ;
V_72:
if ( V_20 )
return V_20 < 0 ? V_20 : - V_21 ;
return V_56 ;
}
static void F_32 ( T_4 V_37 , void * V_73 )
{
struct V_16 V_74 = { V_19 , NULL } ;
T_4 V_75 , V_76 ;
union V_9 * V_10 ;
T_5 V_77 ;
T_4 * V_78 ;
int V_79 ;
V_77 = F_33 ( V_37 , & V_74 ) ;
if ( V_77 != V_80 ) {
F_34 ( L_6 , V_77 ) ;
return;
}
V_10 = (union V_9 * ) V_74 . V_23 ;
if ( ! V_10 )
return;
if ( V_10 -> type != V_24 ) {
F_34 ( L_7 , V_10 -> type ) ;
F_6 ( V_10 ) ;
return;
}
V_78 = ( T_4 * ) V_10 -> V_4 . V_23 ;
if ( V_10 -> V_4 . V_28 == 8 ) {
V_75 = * V_78 ;
V_76 = * ( V_78 + 1 ) ;
} else if ( V_10 -> V_4 . V_28 == 16 ) {
V_75 = * V_78 ;
V_76 = * ( V_78 + 2 ) ;
} else {
F_34 ( L_8 , V_10 -> V_4 . V_28 ) ;
F_6 ( V_10 ) ;
return;
}
F_6 ( V_10 ) ;
switch ( V_75 ) {
case V_81 :
if ( F_35 ( V_82 , V_83 -> V_84 ) )
F_36 ( V_83 , V_82 ,
F_8 ( V_67 ) ) ;
if ( F_35 ( V_85 , V_83 -> V_84 ) )
F_36 ( V_83 , V_85 ,
F_8 ( V_68 ) ) ;
F_37 ( V_83 ) ;
break;
case V_86 :
break;
case V_87 :
break;
case V_88 :
V_79 = F_7 ( V_89 ) ;
if ( V_79 < 0 )
break;
if ( ! F_38 ( V_83 ,
V_79 , 1 , true ) )
F_34 ( L_9 , V_79 ) ;
break;
case V_90 :
if ( V_50 ) {
F_18 () ;
break;
}
if ( V_91 )
F_19 ( V_91 ,
F_14 ( V_92 ) ,
F_16 ( V_92 ) ) ;
if ( V_93 )
F_19 ( V_93 ,
F_14 ( V_94 ) ,
F_16 ( V_94 ) ) ;
if ( V_95 )
F_19 ( V_95 ,
F_14 ( V_96 ) ,
F_16 ( V_96 ) ) ;
break;
case V_97 :
F_34 ( L_10 ) ;
break;
case V_98 :
break;
case V_99 :
break;
case V_100 :
break;
case V_101 :
break;
case V_102 :
break;
case V_103 :
break;
case V_104 :
break;
case V_105 :
break;
case V_106 :
break;
default:
F_34 ( L_11 , V_75 , V_76 ) ;
break;
}
}
static int T_1 F_39 ( void )
{
T_5 V_77 ;
int V_48 , V_29 ;
V_83 = F_40 () ;
if ( ! V_83 )
return - V_107 ;
V_83 -> V_108 = L_12 ;
V_83 -> V_109 = L_13 ;
V_83 -> V_57 . V_110 = V_111 ;
F_41 ( V_112 , V_83 -> V_113 ) ;
V_29 = F_8 ( V_67 ) ;
if ( ! ( V_29 < 0 ) ) {
F_41 ( V_82 , V_83 -> V_84 ) ;
F_36 ( V_83 , V_82 , V_29 ) ;
}
V_29 = F_8 ( V_68 ) ;
if ( ! ( V_29 < 0 ) ) {
F_41 ( V_85 , V_83 -> V_84 ) ;
F_36 ( V_83 , V_85 , V_29 ) ;
}
V_48 = F_42 ( V_83 , V_114 , NULL ) ;
if ( V_48 )
goto V_115;
F_37 ( V_83 ) ;
if ( ! F_10 () && F_9 () )
F_11 () ;
V_77 = F_43 ( V_116 , F_32 , NULL ) ;
if ( F_44 ( V_77 ) ) {
V_48 = - V_117 ;
goto V_115;
}
V_48 = F_45 ( V_83 ) ;
if ( V_48 )
goto V_118;
return 0 ;
V_118:
F_46 ( V_116 ) ;
V_115:
F_47 ( V_83 ) ;
return V_48 ;
}
static void F_48 ( void )
{
F_46 ( V_116 ) ;
F_49 ( V_83 ) ;
}
static void F_50 ( struct V_119 * V_55 )
{
F_51 ( & V_55 -> V_60 , & V_120 ) ;
F_51 ( & V_55 -> V_60 , & V_121 ) ;
F_51 ( & V_55 -> V_60 , & V_122 ) ;
F_51 ( & V_55 -> V_60 , & V_123 ) ;
F_51 ( & V_55 -> V_60 , & V_124 ) ;
F_51 ( & V_55 -> V_60 , & V_125 ) ;
}
static int T_1 F_52 ( struct V_119 * V_55 )
{
int V_48 , V_44 ;
V_44 = F_7 ( V_43 ) ;
if ( V_44 < 0 )
return V_44 ;
V_48 = F_1 ( V_43 , V_39 , & V_44 ,
sizeof( V_44 ) , 0 ) ;
if ( V_48 )
return V_48 ;
if ( V_44 & 0x1 ) {
V_91 = F_53 ( L_14 , & V_55 -> V_60 ,
V_126 ,
& V_127 ,
( void * ) V_92 ) ;
if ( ! V_91 )
return - V_107 ;
F_54 ( V_91 ,
F_14 ( V_92 ) ) ;
F_55 ( V_91 ,
F_16 ( V_92 ) ) ;
V_48 = F_56 ( V_91 ) ;
if ( V_48 )
goto V_128;
}
if ( V_44 & 0x2 ) {
V_93 = F_53 ( L_15 , & V_55 -> V_60 ,
V_129 ,
& V_127 ,
( void * ) V_94 ) ;
if ( ! V_93 ) {
V_48 = - V_107 ;
goto V_130;
}
F_54 ( V_93 ,
F_14 ( V_94 ) ) ;
F_55 ( V_93 ,
F_16 ( V_94 ) ) ;
V_48 = F_56 ( V_93 ) ;
if ( V_48 )
goto V_130;
}
if ( V_44 & 0x4 ) {
V_95 = F_53 ( L_16 , & V_55 -> V_60 ,
V_131 ,
& V_127 ,
( void * ) V_96 ) ;
if ( ! V_95 ) {
V_48 = - V_107 ;
goto V_132;
}
F_54 ( V_95 ,
F_14 ( V_96 ) ) ;
F_55 ( V_95 ,
F_16 ( V_96 ) ) ;
V_48 = F_56 ( V_95 ) ;
if ( V_48 )
goto V_132;
}
return 0 ;
V_132:
F_57 ( V_95 ) ;
V_95 = NULL ;
if ( V_93 )
F_58 ( V_93 ) ;
V_130:
F_57 ( V_93 ) ;
V_93 = NULL ;
if ( V_91 )
F_58 ( V_91 ) ;
V_128:
F_57 ( V_91 ) ;
V_91 = NULL ;
return V_48 ;
}
static int T_1 F_59 ( struct V_119 * V_55 )
{
struct V_47 V_32 ;
int V_48 , V_49 ;
V_48 = F_1 ( V_46 , V_30 , & V_32 ,
0 , sizeof( V_32 ) ) ;
if ( V_48 )
return V_48 < 0 ? V_48 : - V_21 ;
if ( V_32 . V_56 > V_133 ) {
F_4 ( L_17 ) ;
return - V_21 ;
}
for ( V_49 = 0 ; V_49 < V_32 . V_56 ; V_49 ++ ) {
struct V_58 * V_58 ;
enum V_134 type ;
char * V_108 ;
switch ( V_32 . V_55 [ V_49 ] . V_135 ) {
case V_92 :
type = V_126 ;
V_108 = L_14 ;
break;
case V_94 :
type = V_129 ;
V_108 = L_15 ;
break;
case V_96 :
type = V_131 ;
V_108 = L_16 ;
break;
case V_136 :
type = V_137 ;
V_108 = L_18 ;
break;
default:
F_4 ( L_19 ,
V_32 . V_55 [ V_49 ] . V_135 ) ;
continue;
}
if ( ! V_32 . V_55 [ V_49 ] . V_138 ) {
F_4 ( L_20 ,
V_49 , V_32 . V_56 ) ;
continue;
}
V_58 = F_53 ( V_108 , & V_55 -> V_60 , type ,
& V_139 , ( void * ) ( long ) V_49 ) ;
if ( ! V_58 ) {
V_48 = - V_107 ;
goto V_140;
}
V_52 [ V_50 ] . V_57 = V_32 . V_55 [ V_49 ] . V_45 ;
V_52 [ V_50 ] . V_51 = V_49 ;
V_52 [ V_50 ] . V_58 = V_58 ;
F_54 ( V_58 ,
F_20 ( V_32 . V_55 [ V_49 ] . V_59 ) ) ;
F_55 ( V_58 ,
F_21 ( V_32 . V_55 [ V_49 ] . V_59 ) ) ;
if ( ! ( V_32 . V_55 [ V_49 ] . V_59 & V_141 ) )
F_34 ( L_21 , V_108 ) ;
V_48 = F_56 ( V_58 ) ;
if ( V_48 ) {
F_57 ( V_58 ) ;
goto V_140;
}
V_50 ++ ;
}
return 0 ;
V_140:
for (; V_50 > 0 ; V_50 -- ) {
F_58 ( V_52 [ V_50 - 1 ] . V_58 ) ;
F_57 ( V_52 [ V_50 - 1 ] . V_58 ) ;
}
return V_48 ;
}
static int T_1 F_60 ( struct V_119 * V_55 )
{
int V_48 ;
V_91 = NULL ;
V_93 = NULL ;
V_95 = NULL ;
V_50 = 0 ;
if ( F_52 ( V_55 ) )
F_59 ( V_55 ) ;
V_48 = F_61 ( & V_55 -> V_60 , & V_120 ) ;
if ( V_48 )
goto V_142;
V_48 = F_61 ( & V_55 -> V_60 , & V_121 ) ;
if ( V_48 )
goto V_142;
V_48 = F_61 ( & V_55 -> V_60 , & V_122 ) ;
if ( V_48 )
goto V_142;
V_48 = F_61 ( & V_55 -> V_60 , & V_123 ) ;
if ( V_48 )
goto V_142;
V_48 = F_61 ( & V_55 -> V_60 , & V_124 ) ;
if ( V_48 )
goto V_142;
V_48 = F_61 ( & V_55 -> V_60 , & V_125 ) ;
if ( V_48 )
goto V_142;
return 0 ;
V_142:
F_50 ( V_55 ) ;
return V_48 ;
}
static int T_6 F_62 ( struct V_119 * V_55 )
{
int V_49 ;
F_50 ( V_55 ) ;
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ ) {
F_58 ( V_52 [ V_49 ] . V_58 ) ;
F_57 ( V_52 [ V_49 ] . V_58 ) ;
}
if ( V_91 ) {
F_58 ( V_91 ) ;
F_57 ( V_91 ) ;
}
if ( V_93 ) {
F_58 ( V_93 ) ;
F_57 ( V_93 ) ;
}
if ( V_95 ) {
F_58 ( V_95 ) ;
F_57 ( V_95 ) ;
}
return 0 ;
}
static int F_63 ( struct V_55 * V_55 )
{
if ( V_83 ) {
if ( F_35 ( V_82 , V_83 -> V_84 ) )
F_36 ( V_83 , V_82 ,
F_8 ( V_67 ) ) ;
if ( F_35 ( V_85 , V_83 -> V_84 ) )
F_36 ( V_83 , V_85 ,
F_8 ( V_68 ) ) ;
F_37 ( V_83 ) ;
}
if ( V_50 )
F_18 () ;
if ( V_91 )
F_19 ( V_91 ,
F_14 ( V_92 ) ,
F_16 ( V_92 ) ) ;
if ( V_93 )
F_19 ( V_93 ,
F_14 ( V_94 ) ,
F_16 ( V_94 ) ) ;
if ( V_95 )
F_19 ( V_95 ,
F_14 ( V_96 ) ,
F_16 ( V_96 ) ) ;
return 0 ;
}
static int T_1 F_64 ( void )
{
int V_143 = F_65 ( V_116 ) ;
int V_144 = F_65 ( V_22 ) ;
int V_48 ;
if ( ! V_144 && ! V_143 )
return - V_145 ;
if ( V_143 ) {
V_48 = F_39 () ;
if ( V_48 )
return V_48 ;
}
if ( V_144 ) {
V_146 =
F_66 ( L_22 , - 1 , NULL , 0 ) ;
if ( F_67 ( V_146 ) ) {
V_48 = F_68 ( V_146 ) ;
goto V_147;
}
V_48 = F_69 ( & V_148 , F_60 ) ;
if ( V_48 )
goto V_149;
}
return 0 ;
V_149:
F_70 ( V_146 ) ;
V_147:
if ( V_143 )
F_48 () ;
return V_48 ;
}
static void T_6 F_71 ( void )
{
if ( F_65 ( V_116 ) )
F_48 () ;
if ( V_146 ) {
F_70 ( V_146 ) ;
F_72 ( & V_148 ) ;
}
}
