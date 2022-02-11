static inline int F_1 ( int V_1 )
{
if ( V_1 > 4096 )
return - V_2 ;
if ( V_1 > 1024 )
return 5 ;
if ( V_1 > 128 )
return 4 ;
if ( V_1 > 4 )
return 3 ;
if ( V_1 > 0 )
return 2 ;
return 1 ;
}
static int F_2 ( int V_3 , enum V_4 V_5 ,
void * V_6 , int V_7 , int V_1 )
{
int V_8 ;
struct V_9 * V_9 ;
int V_10 ;
union V_11 * V_12 ;
struct V_13 args = {
. V_14 = 0x55434553 ,
. V_5 = V_5 ,
. V_15 = V_3 ,
. V_16 = V_7 ,
. V_17 = 0 ,
} ;
struct V_18 V_19 = { sizeof( struct V_13 ) , & args } ;
struct V_18 V_20 = { V_21 , NULL } ;
int V_22 = 0 ;
V_8 = F_1 ( V_1 ) ;
if ( F_3 ( V_8 < 0 ) )
return V_8 ;
if ( F_3 ( V_7 > sizeof( args . V_17 ) ) )
return - V_2 ;
memcpy ( & args . V_17 , V_6 , V_7 ) ;
F_4 ( V_23 , 0 , V_8 , & V_19 , & V_20 ) ;
V_12 = V_20 . V_24 ;
if ( ! V_12 )
return - V_2 ;
if ( V_12 -> type != V_25 ) {
V_22 = - V_2 ;
goto V_26;
}
V_9 = (struct V_9 * ) V_12 -> V_6 . V_24 ;
V_22 = V_9 -> V_27 ;
if ( V_22 ) {
if ( V_22 != V_28 )
F_5 ( L_1 , V_3 , V_22 ) ;
goto V_26;
}
if ( ! V_1 )
goto V_26;
V_10 = F_6 ( V_1 , ( int ) ( V_12 -> V_6 . V_29 - sizeof( * V_9 ) ) ) ;
memcpy ( V_6 , V_12 -> V_6 . V_24 + sizeof( * V_9 ) , V_10 ) ;
memset ( V_6 + V_10 , 0 , V_1 - V_10 ) ;
V_26:
F_7 ( V_12 ) ;
return V_22 ;
}
static int F_8 ( int V_3 )
{
int V_30 = 0 , V_22 ;
V_22 = F_2 ( V_3 , V_31 , & V_30 ,
sizeof( V_30 ) , sizeof( V_30 ) ) ;
if ( V_22 )
return V_22 < 0 ? V_22 : - V_2 ;
return V_30 ;
}
static int F_9 ( int V_32 )
{
int V_33 = F_8 ( V_34 ) ;
if ( V_33 < 0 )
return V_33 ;
return V_33 & 0x1 ;
}
static int T_1 F_10 ( void )
{
int V_33 = 0 ;
int V_22 = F_2 ( V_35 , V_31 , & V_33 ,
sizeof( V_33 ) , sizeof( V_33 ) ) ;
if ( ! V_22 )
return 1 ;
return ( V_22 == V_28 ) ? 0 : - V_36 ;
}
static int T_1 F_11 ( void )
{
int V_33 = 0 ;
int V_22 = F_2 ( V_37 , V_31 , & V_33 ,
sizeof( V_33 ) , sizeof( V_33 ) ) ;
if ( ! V_22 )
return 1 ;
return ( V_22 == V_28 ) ? 0 : - V_36 ;
}
static int T_1 F_12 ( void )
{
int V_38 = 0x6e ;
int V_22 = F_2 ( V_39 , V_40 , & V_38 ,
sizeof( V_38 ) , 0 ) ;
return V_22 <= 0 ? V_22 : - V_2 ;
}
static int F_13 ( void * V_17 , bool V_41 )
{
enum V_42 V_43 = (enum V_42 ) V_17 ;
int V_3 = F_14 ( V_43 + 8 ) | ( ( ! V_41 ) << V_43 ) ;
int V_22 ;
V_22 = F_2 ( V_44 , V_40 ,
& V_3 , sizeof( V_3 ) , 0 ) ;
return V_22 <= 0 ? V_22 : - V_2 ;
}
static bool F_15 ( enum V_42 V_43 )
{
int V_32 = 0x200 << ( V_43 * 8 ) ;
int V_45 = F_8 ( V_44 ) ;
F_16 ( V_45 < 0 , L_2 ) ;
return ! ( V_45 & V_32 ) ;
}
static bool F_17 ( enum V_42 V_43 )
{
int V_32 = 0x800 << ( V_43 * 8 ) ;
int V_45 = F_8 ( V_44 ) ;
F_16 ( V_45 < 0 , L_2 ) ;
return ! ( V_45 & V_32 ) ;
}
static int F_18 ( void * V_17 , bool V_41 )
{
int V_46 = ( int ) ( long ) V_17 ;
char V_6 [ 4 ] = { 0x01 , 0x00 , V_46 , ! V_41 } ;
int V_22 ;
V_22 = F_2 ( V_47 , V_40 ,
V_6 , sizeof( V_6 ) , 0 ) ;
return V_22 <= 0 ? V_22 : - V_2 ;
}
static int F_19 ( void )
{
struct V_48 V_33 ;
int V_49 , V_50 ;
V_49 = F_2 ( V_47 , V_31 , & V_33 ,
0 , sizeof( V_33 ) ) ;
if ( V_49 )
return V_49 ;
for ( V_50 = 0 ; V_50 < V_51 ; V_50 ++ ) {
int V_52 = V_53 [ V_50 ] . V_52 ;
struct V_54 * V_55 ;
V_55 = & V_33 . V_56 [ V_52 ] ;
if ( V_52 >= V_33 . V_57 ||
V_55 -> V_46 != V_53 [ V_50 ] . V_58 ) {
F_5 ( L_3 ) ;
continue;
}
F_20 ( V_53 [ V_50 ] . V_59 ,
F_21 ( V_55 -> V_60 ) ,
F_22 ( V_55 -> V_60 ) ) ;
}
return 0 ;
}
static T_2 F_23 ( struct V_56 * V_61 , struct V_62 * V_63 ,
char * V_64 )
{
int V_38 = F_8 ( V_65 ) ;
if ( V_38 < 0 )
return V_38 ;
return sprintf ( V_64 , L_4 , V_38 ) ;
}
static T_2 F_24 ( struct V_56 * V_61 , struct V_62 * V_63 ,
char * V_64 )
{
int V_38 = F_8 ( V_66 ) ;
if ( V_38 < 0 )
return V_38 ;
return sprintf ( V_64 , L_4 , V_38 ) ;
}
static T_2 F_25 ( struct V_56 * V_61 , struct V_62 * V_63 ,
char * V_64 )
{
int V_38 = F_8 ( V_67 ) ;
if ( V_38 < 0 )
return V_38 ;
return sprintf ( V_64 , L_4 , V_38 ) ;
}
static T_2 F_26 ( struct V_56 * V_61 , struct V_62 * V_63 ,
char * V_64 )
{
int V_38 = F_9 ( V_68 ) ;
if ( V_38 < 0 )
return V_38 ;
return sprintf ( V_64 , L_4 , V_38 ) ;
}
static T_2 F_27 ( struct V_56 * V_61 , struct V_62 * V_63 ,
char * V_64 )
{
int V_38 = F_9 ( V_69 ) ;
if ( V_38 < 0 )
return V_38 ;
return sprintf ( V_64 , L_4 , V_38 ) ;
}
static T_2 F_28 ( struct V_56 * V_61 , struct V_62 * V_63 ,
char * V_64 )
{
int V_38 = F_8 ( V_70 ) ;
if ( V_38 < 0 )
return V_38 ;
return sprintf ( V_64 , L_5 , V_38 ) ;
}
static T_2 F_29 ( struct V_56 * V_61 , struct V_62 * V_63 ,
const char * V_64 , T_3 V_57 )
{
T_4 V_71 = F_30 ( V_64 , NULL , 10 ) ;
int V_22 = F_2 ( V_67 , V_40 , & V_71 ,
sizeof( V_71 ) , sizeof( V_71 ) ) ;
if ( V_22 )
return V_22 < 0 ? V_22 : - V_2 ;
return V_57 ;
}
static T_2 F_31 ( struct V_56 * V_61 , struct V_62 * V_63 ,
const char * V_64 , T_3 V_57 )
{
long unsigned int V_72 ;
int V_22 ;
T_4 V_71 ;
V_22 = F_32 ( V_64 , 10 , & V_72 ) ;
if ( ! V_22 && V_72 != 1 )
V_22 = - V_2 ;
if ( V_22 )
goto V_73;
V_71 = ( T_4 ) V_72 ;
V_22 = F_2 ( V_70 , V_40 , & V_71 ,
sizeof( V_71 ) , sizeof( V_71 ) ) ;
V_73:
if ( V_22 )
return V_22 < 0 ? V_22 : - V_2 ;
return V_57 ;
}
static void F_33 ( T_4 V_38 , void * V_74 )
{
struct V_18 V_75 = { V_21 , NULL } ;
T_4 V_76 , V_77 ;
union V_11 * V_12 ;
T_5 V_78 ;
T_4 * V_79 ;
int V_80 ;
V_78 = F_34 ( V_38 , & V_75 ) ;
if ( V_78 != V_81 ) {
F_35 ( L_6 , V_78 ) ;
return;
}
V_12 = (union V_11 * ) V_75 . V_24 ;
if ( ! V_12 )
return;
if ( V_12 -> type != V_25 ) {
F_35 ( L_7 , V_12 -> type ) ;
F_7 ( V_12 ) ;
return;
}
V_79 = ( T_4 * ) V_12 -> V_6 . V_24 ;
if ( V_12 -> V_6 . V_29 == 8 ) {
V_76 = * V_79 ;
V_77 = * ( V_79 + 1 ) ;
} else if ( V_12 -> V_6 . V_29 == 16 ) {
V_76 = * V_79 ;
V_77 = * ( V_79 + 2 ) ;
} else {
F_35 ( L_8 , V_12 -> V_6 . V_29 ) ;
F_7 ( V_12 ) ;
return;
}
F_7 ( V_12 ) ;
switch ( V_76 ) {
case V_82 :
if ( F_36 ( V_83 , V_84 -> V_85 ) )
F_37 ( V_84 , V_83 ,
F_9 ( V_68 ) ) ;
if ( F_36 ( V_86 , V_84 -> V_85 ) )
F_37 ( V_84 , V_86 ,
F_9 ( V_69 ) ) ;
F_38 ( V_84 ) ;
break;
case V_87 :
break;
case V_88 :
break;
case V_89 :
V_80 = F_8 ( V_90 ) ;
if ( V_80 < 0 )
break;
if ( ! F_39 ( V_84 ,
V_80 , 1 , true ) )
F_35 ( L_9 , V_80 ) ;
break;
case V_91 :
if ( V_51 ) {
F_19 () ;
break;
}
if ( V_92 )
F_20 ( V_92 ,
F_15 ( V_93 ) ,
F_17 ( V_93 ) ) ;
if ( V_94 )
F_20 ( V_94 ,
F_15 ( V_95 ) ,
F_17 ( V_95 ) ) ;
if ( V_96 )
F_20 ( V_96 ,
F_15 ( V_97 ) ,
F_17 ( V_97 ) ) ;
break;
case V_98 :
F_35 ( L_10 ) ;
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
case V_107 :
break;
default:
F_35 ( L_11 , V_76 , V_77 ) ;
break;
}
}
static int T_1 F_40 ( void )
{
T_5 V_78 ;
int V_49 , V_30 ;
V_84 = F_41 () ;
if ( ! V_84 )
return - V_108 ;
V_84 -> V_109 = L_12 ;
V_84 -> V_110 = L_13 ;
V_84 -> V_58 . V_111 = V_112 ;
F_42 ( V_113 , V_84 -> V_114 ) ;
V_30 = F_9 ( V_68 ) ;
if ( ! ( V_30 < 0 ) ) {
F_42 ( V_83 , V_84 -> V_85 ) ;
F_37 ( V_84 , V_83 , V_30 ) ;
}
V_30 = F_9 ( V_69 ) ;
if ( ! ( V_30 < 0 ) ) {
F_42 ( V_86 , V_84 -> V_85 ) ;
F_37 ( V_84 , V_86 , V_30 ) ;
}
V_49 = F_43 ( V_84 , V_115 , NULL ) ;
if ( V_49 )
goto V_116;
F_38 ( V_84 ) ;
if ( ! F_11 () && F_10 () )
F_12 () ;
V_78 = F_44 ( V_117 , F_33 , NULL ) ;
if ( F_45 ( V_78 ) ) {
V_49 = - V_118 ;
goto V_116;
}
V_49 = F_46 ( V_84 ) ;
if ( V_49 )
goto V_119;
return 0 ;
V_119:
F_47 ( V_117 ) ;
V_116:
F_48 ( V_84 ) ;
return V_49 ;
}
static void F_49 ( void )
{
F_47 ( V_117 ) ;
F_50 ( V_84 ) ;
}
static void F_51 ( struct V_120 * V_56 )
{
F_52 ( & V_56 -> V_61 , & V_121 ) ;
F_52 ( & V_56 -> V_61 , & V_122 ) ;
F_52 ( & V_56 -> V_61 , & V_123 ) ;
F_52 ( & V_56 -> V_61 , & V_124 ) ;
F_52 ( & V_56 -> V_61 , & V_125 ) ;
F_52 ( & V_56 -> V_61 , & V_126 ) ;
}
static int T_1 F_53 ( struct V_120 * V_56 )
{
int V_49 , V_45 ;
V_45 = F_8 ( V_44 ) ;
if ( V_45 < 0 )
return V_45 ;
V_49 = F_2 ( V_44 , V_40 , & V_45 ,
sizeof( V_45 ) , 0 ) ;
if ( V_49 )
return V_49 ;
if ( V_45 & 0x1 ) {
V_92 = F_54 ( L_14 , & V_56 -> V_61 ,
V_127 ,
& V_128 ,
( void * ) V_93 ) ;
if ( ! V_92 )
return - V_108 ;
F_55 ( V_92 ,
F_15 ( V_93 ) ) ;
F_56 ( V_92 ,
F_17 ( V_93 ) ) ;
V_49 = F_57 ( V_92 ) ;
if ( V_49 )
goto V_129;
}
if ( V_45 & 0x2 ) {
V_94 = F_54 ( L_15 , & V_56 -> V_61 ,
V_130 ,
& V_128 ,
( void * ) V_95 ) ;
if ( ! V_94 ) {
V_49 = - V_108 ;
goto V_131;
}
F_55 ( V_94 ,
F_15 ( V_95 ) ) ;
F_56 ( V_94 ,
F_17 ( V_95 ) ) ;
V_49 = F_57 ( V_94 ) ;
if ( V_49 )
goto V_131;
}
if ( V_45 & 0x4 ) {
V_96 = F_54 ( L_16 , & V_56 -> V_61 ,
V_132 ,
& V_128 ,
( void * ) V_97 ) ;
if ( ! V_96 ) {
V_49 = - V_108 ;
goto V_133;
}
F_55 ( V_96 ,
F_15 ( V_97 ) ) ;
F_56 ( V_96 ,
F_17 ( V_97 ) ) ;
V_49 = F_57 ( V_96 ) ;
if ( V_49 )
goto V_133;
}
return 0 ;
V_133:
F_58 ( V_96 ) ;
V_96 = NULL ;
if ( V_94 )
F_59 ( V_94 ) ;
V_131:
F_58 ( V_94 ) ;
V_94 = NULL ;
if ( V_92 )
F_59 ( V_92 ) ;
V_129:
F_58 ( V_92 ) ;
V_92 = NULL ;
return V_49 ;
}
static int T_1 F_60 ( struct V_120 * V_56 )
{
struct V_48 V_33 ;
int V_49 , V_50 ;
V_49 = F_2 ( V_47 , V_31 , & V_33 ,
0 , sizeof( V_33 ) ) ;
if ( V_49 )
return V_49 < 0 ? V_49 : - V_2 ;
if ( V_33 . V_57 > V_134 ) {
F_5 ( L_17 ) ;
return - V_2 ;
}
for ( V_50 = 0 ; V_50 < V_33 . V_57 ; V_50 ++ ) {
struct V_59 * V_59 ;
enum V_135 type ;
char * V_109 ;
switch ( V_33 . V_56 [ V_50 ] . V_136 ) {
case V_93 :
type = V_127 ;
V_109 = L_14 ;
break;
case V_95 :
type = V_130 ;
V_109 = L_15 ;
break;
case V_97 :
type = V_132 ;
V_109 = L_16 ;
break;
case V_137 :
type = V_138 ;
V_109 = L_18 ;
break;
default:
F_5 ( L_19 ,
V_33 . V_56 [ V_50 ] . V_136 ) ;
continue;
}
if ( ! V_33 . V_56 [ V_50 ] . V_139 ) {
F_5 ( L_20 ,
V_50 , V_33 . V_57 ) ;
continue;
}
V_59 = F_54 ( V_109 , & V_56 -> V_61 , type ,
& V_140 , ( void * ) ( long ) V_50 ) ;
if ( ! V_59 ) {
V_49 = - V_108 ;
goto V_141;
}
V_53 [ V_51 ] . V_58 = V_33 . V_56 [ V_50 ] . V_46 ;
V_53 [ V_51 ] . V_52 = V_50 ;
V_53 [ V_51 ] . V_59 = V_59 ;
F_55 ( V_59 ,
F_21 ( V_33 . V_56 [ V_50 ] . V_60 ) ) ;
F_56 ( V_59 ,
F_22 ( V_33 . V_56 [ V_50 ] . V_60 ) ) ;
if ( ! ( V_33 . V_56 [ V_50 ] . V_60 & V_142 ) )
F_35 ( L_21 , V_109 ) ;
V_49 = F_57 ( V_59 ) ;
if ( V_49 ) {
F_58 ( V_59 ) ;
goto V_141;
}
V_51 ++ ;
}
return 0 ;
V_141:
for (; V_51 > 0 ; V_51 -- ) {
F_59 ( V_53 [ V_51 - 1 ] . V_59 ) ;
F_58 ( V_53 [ V_51 - 1 ] . V_59 ) ;
}
return V_49 ;
}
static int T_1 F_61 ( struct V_120 * V_56 )
{
int V_49 ;
V_92 = NULL ;
V_94 = NULL ;
V_96 = NULL ;
V_51 = 0 ;
if ( F_53 ( V_56 ) )
F_60 ( V_56 ) ;
V_49 = F_62 ( & V_56 -> V_61 , & V_121 ) ;
if ( V_49 )
goto V_143;
V_49 = F_62 ( & V_56 -> V_61 , & V_122 ) ;
if ( V_49 )
goto V_143;
V_49 = F_62 ( & V_56 -> V_61 , & V_123 ) ;
if ( V_49 )
goto V_143;
V_49 = F_62 ( & V_56 -> V_61 , & V_124 ) ;
if ( V_49 )
goto V_143;
V_49 = F_62 ( & V_56 -> V_61 , & V_125 ) ;
if ( V_49 )
goto V_143;
V_49 = F_62 ( & V_56 -> V_61 , & V_126 ) ;
if ( V_49 )
goto V_143;
return 0 ;
V_143:
F_51 ( V_56 ) ;
return V_49 ;
}
static int T_6 F_63 ( struct V_120 * V_56 )
{
int V_50 ;
F_51 ( V_56 ) ;
for ( V_50 = 0 ; V_50 < V_51 ; V_50 ++ ) {
F_59 ( V_53 [ V_50 ] . V_59 ) ;
F_58 ( V_53 [ V_50 ] . V_59 ) ;
}
if ( V_92 ) {
F_59 ( V_92 ) ;
F_58 ( V_92 ) ;
}
if ( V_94 ) {
F_59 ( V_94 ) ;
F_58 ( V_94 ) ;
}
if ( V_96 ) {
F_59 ( V_96 ) ;
F_58 ( V_96 ) ;
}
return 0 ;
}
static int F_64 ( struct V_56 * V_56 )
{
if ( V_84 ) {
if ( F_36 ( V_83 , V_84 -> V_85 ) )
F_37 ( V_84 , V_83 ,
F_9 ( V_68 ) ) ;
if ( F_36 ( V_86 , V_84 -> V_85 ) )
F_37 ( V_84 , V_86 ,
F_9 ( V_69 ) ) ;
F_38 ( V_84 ) ;
}
if ( V_51 )
F_19 () ;
if ( V_92 )
F_20 ( V_92 ,
F_15 ( V_93 ) ,
F_17 ( V_93 ) ) ;
if ( V_94 )
F_20 ( V_94 ,
F_15 ( V_95 ) ,
F_17 ( V_95 ) ) ;
if ( V_96 )
F_20 ( V_96 ,
F_15 ( V_97 ) ,
F_17 ( V_97 ) ) ;
return 0 ;
}
static int T_1 F_65 ( void )
{
int V_144 = F_66 ( V_117 ) ;
int V_145 = F_66 ( V_23 ) ;
int V_49 ;
if ( ! V_145 && ! V_144 )
return - V_146 ;
if ( V_144 ) {
V_49 = F_40 () ;
if ( V_49 )
return V_49 ;
}
if ( V_145 ) {
V_147 =
F_67 ( L_22 , - 1 , NULL , 0 ) ;
if ( F_68 ( V_147 ) ) {
V_49 = F_69 ( V_147 ) ;
goto V_148;
}
V_49 = F_70 ( & V_149 , F_61 ) ;
if ( V_49 )
goto V_150;
}
return 0 ;
V_150:
F_71 ( V_147 ) ;
V_148:
if ( V_144 )
F_49 () ;
return V_49 ;
}
static void T_6 F_72 ( void )
{
if ( F_66 ( V_117 ) )
F_49 () ;
if ( V_147 ) {
F_71 ( V_147 ) ;
F_73 ( & V_149 ) ;
}
}
