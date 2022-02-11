static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
T_2 V_6 = 0 ;
int V_7 ;
V_7 = F_2 ( V_8 -> V_9 ,
F_3 ( struct V_10 ,
V_6 ) ,
& V_6 , sizeof( T_2 ) ) ;
if ( V_7 )
return V_7 ;
return sprintf ( V_5 , L_1 , V_6 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_3 V_11 )
{
T_2 V_6 ;
int V_7 ;
if ( F_5 ( V_5 , 10 , & V_6 ) )
return - V_12 ;
V_7 = F_6 ( V_8 -> V_9 ,
F_3 ( struct V_10 ,
V_6 ) ,
& V_6 , sizeof( T_2 ) ) ;
if ( V_7 )
return V_7 ;
return V_11 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_13 V_13 ;
int V_7 ;
V_7 = F_2 ( V_8 -> V_9 ,
F_3 ( struct V_10 ,
V_14 ) ,
& V_13 ,
sizeof( struct V_13 ) ) ;
if ( V_7 )
return V_7 ;
return sprintf ( V_5 , L_1 , V_13 . V_15 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_3 V_11 )
{
int V_16 , V_7 ;
struct V_13 V_13 ;
if ( F_9 ( V_5 , 10 , & V_16 ) )
return - V_12 ;
V_13 . V_15 = V_16 ;
V_7 = F_6 ( V_8 -> V_9 ,
F_3 ( struct V_10 ,
V_14 ) ,
& ( V_13 ) ,
sizeof( struct V_13 ) ) ;
if ( V_7 )
return V_7 ;
return V_11 ;
}
static T_1 F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
T_4 error = 0 ;
int V_7 ;
V_7 = F_2 ( V_8 -> V_9 ,
F_3 ( struct V_10 ,
V_17 ) ,
& error , sizeof( T_4 ) ) ;
if ( V_7 )
return V_7 ;
return sprintf ( V_5 , L_1 , error ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_3 V_11 )
{
T_4 error ;
int V_7 ;
if ( F_12 ( V_5 , 10 , & error ) )
return - V_12 ;
V_7 = F_6 ( V_8 -> V_9 ,
F_3 ( struct V_10 ,
V_17 ) ,
& error , sizeof( T_4 ) ) ;
if ( V_7 )
return V_7 ;
return V_11 ;
}
static T_1 F_13 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
T_4 V_18 = 0 ;
int V_7 ;
V_7 = F_2 ( V_8 -> V_9 ,
F_3 ( struct V_10 ,
V_19 ) ,
& V_18 , sizeof( T_4 ) ) ;
if ( V_7 )
return V_7 ;
return sprintf ( V_5 , L_1 , V_18 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_3 V_11 )
{
T_4 V_18 ;
int V_7 ;
if ( F_12 ( V_5 , 10 , & V_18 ) )
return - V_12 ;
V_7 = F_6 ( V_8 -> V_9 ,
F_3 ( struct V_10 ,
V_19 ) ,
& V_18 , sizeof( T_4 ) ) ;
if ( V_7 )
return V_7 ;
return V_11 ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
T_5 V_20 = 0 ;
int V_7 ;
V_7 = F_2 ( V_8 -> V_9 ,
F_3 ( struct V_10 ,
V_21 ) ,
& V_20 , sizeof( T_5 ) ) ;
if ( V_7 )
return V_7 ;
return sprintf ( V_5 , L_2 , V_20 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_3 V_11 )
{
T_5 V_20 ;
int V_7 ;
if ( F_17 ( V_5 , 10 , & V_20 ) )
return - V_12 ;
V_7 = F_6 ( V_8 -> V_9 ,
F_3 ( struct V_10 ,
V_21 ) ,
& V_20 , sizeof( T_5 ) ) ;
if ( V_7 )
return V_7 ;
return V_11 ;
}
static int F_18 ( struct V_1 * V_2 , void * V_22 )
{
struct V_23 * V_24 = F_19 ( V_2 ) ;
struct V_25 * V_26 = V_22 ;
if ( ( V_24 -> V_27 == V_26 -> V_28 ) &&
( V_24 -> V_29 == V_26 -> V_30 ) )
return 1 ;
return 0 ;
}
struct V_23 * F_20 ( T_4 V_28 , T_4 V_30 ,
struct V_23 * V_31 )
{
struct V_1 * V_2 ;
struct V_1 * V_32 = NULL ;
struct V_23 * V_24 = NULL ;
struct V_25 V_26 = {
. V_28 = V_28 ,
. V_30 = V_30
} ;
if ( V_31 )
V_32 = & V_31 -> V_1 ;
V_2 = F_21 ( & V_33 , V_32 , ( void * ) & V_26 ,
F_18 ) ;
if ( V_2 )
V_24 = F_19 ( V_2 ) ;
return V_24 ;
}
static void F_22 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
int V_38 )
{
memset ( V_35 , 0 , sizeof( struct V_34 ) ) ;
memcpy ( & V_35 -> V_39 , V_37 , sizeof( struct V_36 ) ) ;
V_35 -> V_39 . V_40 = 0 ;
V_35 -> V_39 . V_41 = 0 ;
V_35 -> V_39 . V_42 = 0 ;
if ( V_38 < 0 ) {
V_35 -> V_39 . V_43 . V_44 = 1 ;
V_35 -> V_39 . V_45 = ( T_4 ) ( - V_38 ) ;
}
}
static int F_23 (
struct V_36 * V_37 ,
int V_38 ,
enum V_46 V_47 )
{
struct V_34 V_48 ;
F_22 ( & V_48 , V_37 , V_38 ) ;
V_48 . V_49 . V_50 . V_47 = V_47 ;
return F_24 ( V_8 -> V_9 ,
V_51 , & V_48 ) ;
}
static int F_25 ( struct V_34 * V_52 )
{
static int V_53 ;
enum V_46 V_47 = 0 ;
int V_54 = V_55 ;
int V_56 = 0 ;
if ( V_53 ) {
V_54 = - V_57 ;
V_56 = - V_58 ;
goto V_59;
}
V_53 = 1 ;
V_47 = V_52 -> V_49 . V_50 . V_47 &
V_60 ;
V_47 |= V_61 ;
V_59:
if ( V_52 -> V_39 . V_43 . V_62 )
V_56 = F_23 ( & V_52 -> V_39 , V_54 , V_47 ) ;
return V_56 ;
}
static int F_26 ( struct V_36 * V_37 ,
int V_38 ,
struct V_63 * V_64 )
{
struct V_34 V_48 ;
F_22 ( & V_48 , V_37 , V_38 ) ;
if ( V_48 . V_39 . V_43 . V_65 == 1 )
return - V_12 ;
if ( V_64 ) {
V_48 . V_49 . V_66 . V_64 = * V_64 ;
V_48 . V_49 . V_66 . V_43 . V_67 = 1 ;
}
return F_24 ( V_8 -> V_9 ,
V_51 , & V_48 ) ;
}
static int F_27 ( struct V_34 * V_35 ,
enum V_68 V_69 )
{
T_4 V_70 ;
T_5 V_71 ;
int V_7 ;
V_7 = F_2 ( V_8 -> V_9 ,
F_3 ( struct V_10 ,
V_72 ) ,
& V_71 , sizeof( T_5 ) ) ;
if ( V_7 ) {
F_28 ( & V_8 -> V_73 -> V_2 ,
L_3 ) ;
return V_7 ;
}
if ( V_71 != V_74 ) {
F_28 ( & V_8 -> V_73 -> V_2 ,
L_4 ) ;
return - V_58 ;
}
V_7 = F_2 ( V_8 -> V_9 ,
F_3 ( struct V_10 ,
V_75 ) ,
& V_70 , sizeof( T_4 ) ) ;
if ( V_7 ) {
F_28 ( & V_8 -> V_73 -> V_2 ,
L_5 ) ;
return V_7 ;
}
switch ( V_69 ) {
case V_76 :
V_70 += sizeof( struct V_34 ) ;
V_7 = F_6 ( V_8 -> V_9 ,
V_70 ,
V_35 ,
sizeof( struct V_34 ) ) ;
if ( V_7 ) {
F_28 ( & V_8 -> V_73 -> V_2 ,
L_6 ) ;
return V_7 ;
}
break;
case V_77 :
V_7 = F_6 ( V_8 -> V_9 ,
V_70 ,
V_35 ,
sizeof( struct V_34 ) ) ;
if ( V_7 ) {
F_28 ( & V_8 -> V_73 -> V_2 ,
L_7 ) ;
return V_7 ;
}
break;
default:
F_28 ( & V_8 -> V_73 -> V_2 ,
L_8 ) ;
break;
}
return 0 ;
}
static int F_29 ( enum V_78 V_79 ,
struct V_36 * V_80 ,
int V_38 )
{
if ( ! V_80 )
return - V_58 ;
if ( V_80 -> V_26 != ( T_4 ) V_79 )
return - V_12 ;
return F_26 ( V_80 , V_38 , NULL ) ;
}
static int F_30 (
enum V_78 V_79 ,
struct V_23 * V_81 , int V_38 ,
struct V_63 V_82 )
{
struct V_34 V_48 ;
if ( ! V_81 -> V_80 )
return - V_58 ;
if ( V_81 -> V_80 -> V_26 != V_79 )
return - V_12 ;
F_22 ( & V_48 , V_81 -> V_80 , V_38 ) ;
V_48 . V_49 . V_66 . V_28 = V_81 -> V_27 ;
V_48 . V_49 . V_66 . V_30 = V_81 -> V_29 ;
V_48 . V_49 . V_66 . V_64 = V_82 ;
return F_24 ( V_8 -> V_9 ,
V_51 , & V_48 ) ;
}
static int F_31 ( struct V_34 * V_52 )
{
struct V_83 * V_49 = & V_52 -> V_49 ;
struct V_36 * V_84 = NULL ;
T_4 V_28 = V_49 -> V_85 . V_28 ;
struct V_23 * V_86 ;
struct V_87 * V_87 ;
int V_7 ;
V_86 = F_20 ( V_28 , V_88 , NULL ) ;
if ( V_86 && ( V_86 -> V_64 . V_89 == 1 ) ) {
F_28 ( & V_8 -> V_73 -> V_2 ,
L_9 , V_90 ) ;
V_7 = - V_91 ;
goto V_92;
}
V_86 = F_32 ( sizeof( * V_86 ) , V_93 ) ;
if ( ! V_86 ) {
V_7 = - V_94 ;
goto V_92;
}
F_33 ( & V_86 -> V_95 ) ;
V_86 -> V_27 = V_28 ;
V_86 -> V_29 = V_88 ;
if ( F_34 ( & V_49 -> V_85 . V_96 , & V_97 ) ) {
V_7 = F_27 ( V_52 , V_77 ) ;
if ( V_7 )
goto V_98;
}
if ( V_52 -> V_39 . V_43 . V_62 == 1 ) {
V_84 = F_32 ( sizeof( * V_84 ) ,
V_93 ) ;
if ( ! V_84 ) {
V_7 = - V_94 ;
goto V_98;
}
memcpy ( V_84 , & V_52 -> V_39 ,
sizeof( struct V_36 ) ) ;
V_86 -> V_80 = V_84 ;
}
V_87 = F_35 ( V_49 -> V_85 . V_99 ,
V_93 ,
& V_49 -> V_85 . V_100 ) ;
if ( ! V_87 ) {
V_7 = - V_94 ;
goto V_101;
}
V_86 -> V_87 = V_87 ;
V_7 = F_36 ( V_86 ) ;
if ( V_7 )
goto V_102;
return 0 ;
V_102:
F_37 ( V_87 ) ;
V_101:
F_38 ( V_86 -> V_80 ) ;
V_98:
F_38 ( V_86 ) ;
V_92:
if ( V_52 -> V_39 . V_43 . V_62 == 1 )
F_29 ( V_52 -> V_39 . V_26 , & V_52 -> V_39 , V_7 ) ;
return V_7 ;
}
static int F_39 ( struct V_34 * V_52 )
{
struct V_83 * V_49 = & V_52 -> V_49 ;
struct V_36 * V_84 = NULL ;
T_4 V_28 = V_49 -> V_103 . V_28 ;
struct V_23 * V_86 ;
int V_7 ;
V_86 = F_20 ( V_28 , V_88 , NULL ) ;
if ( ! V_86 ) {
V_7 = - V_104 ;
goto V_92;
}
if ( V_86 -> V_64 . V_89 == 0 ) {
V_7 = - V_105 ;
goto V_92;
}
if ( V_86 -> V_80 ) {
V_7 = - V_91 ;
goto V_92;
}
if ( V_52 -> V_39 . V_43 . V_62 == 1 ) {
V_84 = F_32 ( sizeof( * V_84 ) , V_93 ) ;
if ( ! V_84 ) {
V_7 = - V_94 ;
goto V_92;
}
memcpy ( V_84 , & V_52 -> V_39 ,
sizeof( struct V_36 ) ) ;
V_86 -> V_80 = V_84 ;
}
F_40 ( V_86 ) ;
return 0 ;
V_92:
if ( V_52 -> V_39 . V_43 . V_62 == 1 )
F_29 ( V_52 -> V_39 . V_26 , & V_52 -> V_39 , V_7 ) ;
return V_7 ;
}
static const T_6 * F_41 ( struct V_106 * V_107 )
{
return & V_107 -> V_22 . V_26 ;
}
static void * F_42 ( struct V_106 * V_107 )
{
T_2 * V_108 ;
unsigned long V_109 ;
int V_110 ;
void * V_111 ;
int V_112 ;
V_108 = V_107 -> V_113 ;
if ( ! V_108 )
return NULL ;
V_109 = V_107 -> V_114 ;
if ( V_109 == 0 )
return NULL ;
for ( V_112 = 0 , V_110 = - 1 ; V_112 < V_109 ; V_112 ++ )
if ( V_108 [ V_112 ] == '\0' ) {
V_110 = V_112 ;
break;
}
if ( V_110 < 0 )
V_110 = V_109 ;
V_111 = F_43 ( V_110 + 1 , V_93 ) ;
if ( ! V_111 )
return NULL ;
if ( V_110 > 0 )
memcpy ( V_111 , V_108 , V_110 ) ;
( ( T_2 * ) ( V_111 ) ) [ V_110 ] = '\0' ;
return V_111 ;
}
static void * F_44 ( struct V_106 * V_107 )
{
struct V_115 * V_116 = NULL ;
V_116 = & V_107 -> V_22 ;
if ( V_116 -> V_117 + V_116 -> V_118 > V_107 -> V_119 )
return NULL ;
V_107 -> V_113 = ( char * ) & V_116 + V_116 -> V_117 ;
V_107 -> V_114 = V_116 -> V_118 ;
return F_42 ( V_107 ) ;
}
static int F_45 ( struct V_34 * V_52 ,
struct V_106 * V_120 )
{
struct V_83 * V_49 = & V_52 -> V_49 ;
T_4 V_28 ;
struct V_23 * V_86 ;
int V_7 = 0 ;
V_28 = V_49 -> V_121 . V_28 ;
V_86 = F_20 ( V_28 , V_88 , NULL ) ;
if ( ! V_86 ) {
V_7 = - V_12 ;
goto V_92;
}
if ( V_86 -> V_64 . V_89 == 0 ) {
V_7 = - V_12 ;
goto V_92;
}
if ( V_86 -> V_80 ) {
V_7 = - V_58 ;
goto V_92;
}
V_7 = F_46
( V_86 -> V_87 ,
V_49 -> V_121 . V_122 ) ;
if ( V_7 )
goto V_92;
if ( V_120 ) {
const T_6 * V_123 = F_41 ( V_120 ) ;
F_47 ( & V_86 -> V_123 , V_123 ) ;
V_86 -> V_124 = F_44 ( V_120 ) ;
}
if ( V_52 -> V_39 . V_43 . V_62 == 1 )
F_29 ( V_52 -> V_39 . V_26 , & V_52 -> V_39 , V_7 ) ;
return 0 ;
V_92:
F_28 ( & V_8 -> V_73 -> V_2 ,
L_10 , V_90 , V_7 ) ;
if ( V_52 -> V_39 . V_43 . V_62 == 1 )
F_29 ( V_52 -> V_39 . V_26 , & V_52 -> V_39 , V_7 ) ;
return V_7 ;
}
static int F_48 ( struct V_34 * V_52 )
{
struct V_83 * V_49 = & V_52 -> V_49 ;
struct V_36 * V_84 = NULL ;
T_4 V_28 = V_49 -> V_125 . V_28 ;
T_4 V_30 = V_49 -> V_125 . V_30 ;
struct V_23 * V_126 = NULL ;
struct V_23 * V_86 ;
struct V_87 * V_87 ;
int V_7 ;
V_86 = F_20 ( V_28 , V_88 , NULL ) ;
if ( ! V_86 ) {
F_28 ( & V_8 -> V_73 -> V_2 ,
L_11 , V_28 ) ;
V_7 = - V_104 ;
goto V_92;
}
if ( V_86 -> V_64 . V_89 == 0 ) {
F_28 ( & V_8 -> V_73 -> V_2 ,
L_12 , V_28 ) ;
V_7 = - V_12 ;
goto V_92;
}
V_126 = F_20 ( V_28 , V_30 , NULL ) ;
if ( V_126 && ( V_126 -> V_64 . V_89 == 1 ) ) {
F_28 ( & V_8 -> V_73 -> V_2 ,
L_13 , V_28 , V_30 ) ;
V_7 = - V_91 ;
goto V_92;
}
V_126 = F_32 ( sizeof( * V_126 ) , V_93 ) ;
if ( ! V_126 ) {
V_7 = - V_94 ;
goto V_92;
}
V_126 -> V_27 = V_28 ;
V_126 -> V_29 = V_30 ;
F_47 ( & V_126 -> V_127 , & V_49 -> V_125 . V_128 ) ;
V_126 -> V_1 . V_129 = & V_86 -> V_1 ;
V_87 =
F_49 ( V_49 -> V_125 . V_99 ,
V_93 ,
& V_49 -> V_125 . V_130 ) ;
if ( ! V_87 ) {
F_28 ( & V_8 -> V_73 -> V_2 ,
L_14 ,
V_28 , V_30 ) ;
V_7 = - V_94 ;
goto V_131;
}
V_126 -> V_87 = V_87 ;
F_47 ( & V_126 -> V_132 , & V_49 -> V_125 . V_130 ) ;
if ( F_34 ( & V_49 -> V_125 . V_130 , & V_133 ) ) {
V_7 = F_27 ( V_52 , V_76 ) ;
if ( V_7 )
goto V_134;
}
if ( V_52 -> V_39 . V_43 . V_62 == 1 ) {
V_84 = F_32 ( sizeof( * V_84 ) , V_93 ) ;
if ( ! V_84 ) {
V_7 = - V_94 ;
goto V_134;
}
memcpy ( V_84 , & V_52 -> V_39 ,
sizeof( struct V_36 ) ) ;
V_126 -> V_80 = V_84 ;
}
V_7 = F_50 ( V_126 ) ;
if ( V_7 )
goto V_134;
return 0 ;
V_134:
F_37 ( V_87 ) ;
V_131:
F_38 ( V_126 ) ;
V_92:
if ( V_52 -> V_39 . V_43 . V_62 == 1 )
F_29 ( V_52 -> V_39 . V_26 , & V_52 -> V_39 , V_7 ) ;
return V_7 ;
}
static int F_51 ( struct V_34 * V_52 )
{
struct V_83 * V_49 = & V_52 -> V_49 ;
struct V_36 * V_84 = NULL ;
T_4 V_28 = V_49 -> V_66 . V_28 ;
T_4 V_30 = V_49 -> V_66 . V_30 ;
struct V_63 V_64 = V_49 -> V_66 . V_64 ;
struct V_23 * V_126 ;
int V_7 = 0 ;
V_126 = F_20 ( V_28 , V_30 , NULL ) ;
if ( ! V_126 ) {
V_7 = - V_104 ;
goto V_92;
}
if ( V_126 -> V_64 . V_89 == 0 ) {
V_7 = - V_12 ;
goto V_92;
}
if ( V_126 -> V_80 ) {
V_7 = - V_58 ;
goto V_92;
}
if ( V_52 -> V_39 . V_43 . V_62 == 1 ) {
V_84 = F_32 ( sizeof( * V_84 ) , V_93 ) ;
if ( ! V_84 ) {
V_7 = - V_94 ;
goto V_92;
}
memcpy ( V_84 , & V_52 -> V_39 ,
sizeof( struct V_36 ) ) ;
V_126 -> V_80 = V_84 ;
}
if ( V_64 . V_135 == V_136 . V_135 &&
V_64 . V_137 == V_136 . V_137 )
V_7 = F_52 ( V_126 ) ;
else if ( V_64 . V_135 == V_138 . V_135 &&
V_64 . V_137 == V_138 . V_137 )
V_7 = F_53 ( V_126 ) ;
if ( V_7 )
goto V_92;
return 0 ;
V_92:
F_28 ( & V_8 -> V_73 -> V_2 , L_15 , V_7 ) ;
if ( V_52 -> V_39 . V_43 . V_62 == 1 )
F_29 ( V_52 -> V_39 . V_26 , & V_52 -> V_39 , V_7 ) ;
return V_7 ;
}
static int F_54 ( struct V_34 * V_52 )
{
struct V_83 * V_49 = & V_52 -> V_49 ;
struct V_36 * V_84 = NULL ;
T_4 V_28 = V_49 -> V_139 . V_28 ;
T_4 V_30 = V_49 -> V_139 . V_30 ;
struct V_23 * V_126 ;
int V_7 ;
V_126 = F_20 ( V_28 , V_30 , NULL ) ;
if ( ! V_126 ) {
V_7 = - V_104 ;
goto V_92;
}
if ( V_126 -> V_64 . V_89 == 0 ) {
V_7 = - V_12 ;
goto V_92;
}
if ( V_126 -> V_80 ) {
V_7 = - V_58 ;
goto V_92;
}
if ( V_52 -> V_39 . V_43 . V_62 == 1 ) {
V_84 = F_32 ( sizeof( * V_84 ) , V_93 ) ;
if ( ! V_84 ) {
V_7 = - V_94 ;
goto V_92;
}
memcpy ( V_84 , & V_52 -> V_39 ,
sizeof( struct V_36 ) ) ;
V_126 -> V_80 = V_84 ;
}
F_38 ( V_126 -> V_124 ) ;
F_55 ( V_126 ) ;
return 0 ;
V_92:
if ( V_52 -> V_39 . V_43 . V_62 == 1 )
F_29 ( V_52 -> V_39 . V_26 , & V_52 -> V_39 , V_7 ) ;
return V_7 ;
}
static int F_56 ( void )
{
static T_7 V_26 = F_57 ( 0 ) ;
return F_58 ( & V_26 ) ;
}
static unsigned long F_59 ( void )
{
return V_140 + F_60 ( V_141 ) ;
}
static struct V_142 * F_61 (
struct V_34 * V_35 )
{
struct V_142 * V_143 ;
V_143 = F_43 ( sizeof( * V_143 ) , V_93 ) ;
if ( ! V_143 )
return NULL ;
V_143 -> V_26 = F_56 () ;
V_143 -> V_144 = F_59 () ;
V_143 -> V_35 = * V_35 ;
return V_143 ;
}
static void F_62 ( struct V_142 * V_143 )
{
F_38 ( V_143 ) ;
}
static int F_63 ( int V_26 , T_5 V_145 )
{
struct V_146 * V_147 ;
struct V_146 * V_148 ;
F_64 ( & V_149 ) ;
F_65 (pos, tmp, &parahotplug_request_list) {
struct V_142 * V_143 =
F_66 ( V_147 , struct V_142 , V_150 ) ;
if ( V_143 -> V_26 == V_26 ) {
F_67 ( V_147 ) ;
F_68 ( & V_149 ) ;
V_143 -> V_35 . V_49 . V_66 . V_64 . V_145 = V_145 ;
if ( V_143 -> V_35 . V_39 . V_43 . V_62 )
F_26 (
& V_143 -> V_35 . V_39 , V_55 ,
& V_143 -> V_35 . V_49 . V_66 . V_64 ) ;
F_62 ( V_143 ) ;
return 0 ;
}
}
F_68 ( & V_149 ) ;
return - V_12 ;
}
static T_1 F_69 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_3 V_11 )
{
unsigned int V_26 ;
int V_7 ;
if ( F_70 ( V_5 , 10 , & V_26 ) )
return - V_12 ;
V_7 = F_63 ( V_26 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
return V_11 ;
}
static T_1 F_71 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_3 V_11 )
{
unsigned int V_26 ;
if ( F_70 ( V_5 , 10 , & V_26 ) )
return - V_12 ;
F_63 ( V_26 , 1 ) ;
return V_11 ;
}
static int F_72 ( struct V_142 * V_143 )
{
struct V_83 * V_49 = & V_143 -> V_35 . V_49 ;
char V_151 [ 40 ] , V_152 [ 40 ] , V_153 [ 40 ] , V_154 [ 40 ] , V_155 [ 40 ] ,
V_156 [ 40 ] ;
char * V_157 [] = {
V_151 , V_152 , V_153 , V_154 , V_155 , V_156 , NULL
} ;
sprintf ( V_151 , L_16 ) ;
sprintf ( V_152 , L_17 , V_143 -> V_26 ) ;
sprintf ( V_153 , L_18 ,
V_49 -> V_66 . V_64 . V_145 ) ;
sprintf ( V_154 , L_19 ,
V_49 -> V_66 . V_28 ) ;
sprintf ( V_155 , L_20 ,
V_49 -> V_66 . V_30 >> 3 ) ;
sprintf ( V_156 , L_21 ,
V_49 -> V_66 . V_30 & 0x7 ) ;
return F_73 ( & V_8 -> V_73 -> V_2 . V_158 ,
V_159 , V_157 ) ;
}
static int F_74 ( struct V_34 * V_52 )
{
struct V_142 * V_143 ;
int V_7 ;
V_143 = F_61 ( V_52 ) ;
if ( ! V_143 )
return - V_94 ;
if ( V_52 -> V_49 . V_66 . V_64 . V_145 ) {
V_7 = F_72 ( V_143 ) ;
if ( V_7 )
goto V_92;
F_26 ( & V_52 -> V_39 , V_55 ,
& V_52 -> V_49 . V_66 . V_64 ) ;
F_62 ( V_143 ) ;
return 0 ;
}
F_64 ( & V_149 ) ;
F_75 ( & V_143 -> V_150 , & V_160 ) ;
F_68 ( & V_149 ) ;
V_7 = F_72 ( V_143 ) ;
if ( V_7 )
goto V_92;
return 0 ;
V_92:
F_26 ( & V_52 -> V_39 , V_7 ,
& V_52 -> V_49 . V_66 . V_64 ) ;
return V_7 ;
}
static int F_76 ( struct V_36 * V_37 )
{
int V_56 ;
V_56 = F_77 ( & V_8 -> V_73 -> V_2 . V_158 ,
V_161 ) ;
if ( V_37 -> V_43 . V_62 )
F_26 ( V_37 , V_56 , NULL ) ;
return V_56 ;
}
static int F_78 ( struct V_36 * V_37 )
{
char V_162 [ 20 ] ;
char * V_157 [] = { V_162 , NULL } ;
int V_56 ;
sprintf ( V_162 , L_22 , 1 ) ;
V_56 = F_73 ( & V_8 -> V_73 -> V_2 . V_158 ,
V_159 , V_157 ) ;
if ( V_37 -> V_43 . V_62 )
F_26 ( V_37 , V_56 , NULL ) ;
return V_56 ;
}
static int F_79 ( struct V_36 * V_37 )
{
int V_56 = F_77 ( & V_8 -> V_73 -> V_2 . V_158 ,
V_163 ) ;
if ( V_37 -> V_43 . V_62 )
F_26 ( V_37 , V_56 , NULL ) ;
return V_56 ;
}
static int F_80 ( unsigned long V_164 , unsigned long V_165 )
{
int V_166 = 0 ;
unsigned int V_167 , V_168 , V_169 , V_170 ;
unsigned long V_171 ;
unsigned long V_172 ;
V_171 = V_165 & 0xFFFFFFFF ;
V_172 = V_165 >> 32 ;
F_81 ( 0x00000001 , & V_167 , & V_168 , & V_169 , & V_170 ) ;
if ( ! ( V_169 & 0x80000000 ) )
return - V_173 ;
__asm__ __volatile__(".byte 0x00f, 0x001, 0x0c1" : "=a"(result) :
"a"(tuple), "b"(reg_ebx), "c"(reg_ecx));
if ( V_166 )
goto error;
return 0 ;
error:
switch ( V_166 ) {
case V_174 :
return - V_12 ;
case V_175 :
return - V_104 ;
default:
return - V_176 ;
}
}
static int F_82 ( struct V_177 * V_2 )
{
struct V_87 * V_178 ;
T_8 V_179 ;
int V_7 ;
V_7 = F_80 ( V_180 ,
F_83 ( & V_2 -> V_181 ) ) ;
if ( V_7 )
return V_7 ;
V_179 = V_2 -> V_181 . V_182 ;
V_178 = F_49 ( V_179 , V_93 ,
& V_183 ) ;
if ( ! V_178 )
return - V_94 ;
V_2 -> V_9 = V_178 ;
return 0 ;
}
static void F_84 ( struct V_184 * V_185 )
{
struct V_34 V_186 ;
struct V_34 V_187 ;
struct V_34 V_35 ;
T_4 V_70 ;
T_5 V_71 ;
V_35 . V_39 . V_26 = V_188 ;
V_35 . V_49 . V_50 . V_189 = 23 ;
V_35 . V_49 . V_50 . V_190 = 0 ;
F_25 ( & V_35 ) ;
if ( F_2 ( V_8 -> V_9 ,
F_3 ( struct V_10 ,
V_72 ) ,
& V_71 , sizeof( T_5 ) ) < 0 ) {
F_28 ( & V_8 -> V_73 -> V_2 ,
L_23 ) ;
return;
}
if ( V_71 != V_74 ) {
F_28 ( & V_8 -> V_73 -> V_2 ,
L_24 ) ;
return;
}
if ( F_2 ( V_8 -> V_9 ,
F_3 ( struct V_10 ,
V_75 ) ,
& V_70 , sizeof( T_4 ) ) < 0 ) {
F_28 ( & V_8 -> V_73 -> V_2 ,
L_23 ) ;
return;
}
if ( F_2 ( V_8 -> V_9 ,
V_70 ,
& V_186 ,
sizeof( struct V_34 ) ) < 0 ) {
F_28 ( & V_8 -> V_73 -> V_2 ,
L_23 ) ;
return;
}
if ( F_2 ( V_8 -> V_9 ,
V_70 +
sizeof( struct V_34 ) ,
& V_187 ,
sizeof( struct V_34 ) ) < 0 ) {
F_28 ( & V_8 -> V_73 -> V_2 ,
L_23 ) ;
return;
}
if ( ! V_186 . V_49 . V_85 . V_99 ) {
F_28 ( & V_8 -> V_73 -> V_2 ,
L_25 ) ;
return;
}
F_31 ( & V_186 ) ;
if ( ! V_187 . V_49 . V_125 . V_99 ) {
F_28 ( & V_8 -> V_73 -> V_2 ,
L_26 ) ;
return;
}
F_48 ( & V_187 ) ;
}
void F_85 ( struct V_23 * V_86 , int V_38 ,
int V_78 )
{
F_29 ( V_78 , V_86 -> V_80 , V_38 ) ;
F_38 ( V_86 -> V_80 ) ;
V_86 -> V_80 = NULL ;
}
void F_86 ( struct V_23 * V_126 ,
int V_38 ,
struct V_63 V_64 )
{
F_30 ( V_191 ,
V_126 , V_38 , V_64 ) ;
F_38 ( V_126 -> V_80 ) ;
V_126 -> V_80 = NULL ;
}
static void F_87 ( struct V_106 * V_107 )
{
V_8 -> V_192 -= V_107 -> V_119 ;
F_38 ( V_107 ) ;
}
static struct V_106 * F_88 ( T_8 V_179 , T_4 V_193 ,
bool * V_194 )
{
int V_195 ;
struct V_106 * V_107 ;
void * V_196 ;
* V_194 = false ;
V_195 = V_193 + 1 + ( sizeof( struct V_106 ) -
sizeof( struct V_115 ) ) ;
if ( ( V_8 -> V_192 + V_193 )
> V_197 ) {
* V_194 = true ;
return NULL ;
}
V_107 = F_32 ( V_195 , V_93 ) ;
if ( ! V_107 ) {
* V_194 = true ;
return NULL ;
}
V_107 -> V_195 = V_195 ;
V_107 -> V_119 = V_193 ;
V_196 = F_89 ( V_179 , V_193 , V_198 ) ;
if ( ! V_196 )
goto V_199;
memcpy ( & V_107 -> V_22 , V_196 , V_193 ) ;
F_90 ( V_196 ) ;
V_107 -> V_200 = true ;
V_8 -> V_192 += V_107 -> V_119 ;
return V_107 ;
V_199:
F_38 ( V_107 ) ;
return NULL ;
}
static int F_91 ( struct V_34 V_52 , T_8 V_99 )
{
struct V_83 * V_49 = & V_52 . V_49 ;
T_8 V_201 ;
T_4 V_202 ;
struct V_106 * V_120 = NULL ;
struct V_34 V_203 ;
int V_7 = 0 ;
V_201 = V_99 + V_52 . V_39 . V_41 ;
V_202 = V_52 . V_39 . V_40 ;
if ( V_202 ) {
bool V_194 = false ;
V_120 = F_88 ( V_201 , V_202 , & V_194 ) ;
if ( ! V_120 && V_194 )
return - V_204 ;
}
F_22 ( & V_203 , & V_52 . V_39 , V_55 ) ;
V_7 = F_24 ( V_8 -> V_9 ,
V_205 , & V_203 ) ;
if ( V_7 )
return V_7 ;
switch ( V_52 . V_39 . V_26 ) {
case V_188 :
V_7 = F_25 ( & V_52 ) ;
break;
case V_206 :
V_7 = F_31 ( & V_52 ) ;
break;
case V_207 :
V_7 = F_39 ( & V_52 ) ;
break;
case V_208 :
V_7 = F_45 ( & V_52 , V_120 ) ;
break;
case V_209 :
V_7 = F_48 ( & V_52 ) ;
break;
case V_191 :
if ( V_49 -> V_66 . V_43 . V_67 ) {
V_7 = F_74 ( & V_52 ) ;
} else {
V_7 = F_51 ( & V_52 ) ;
break;
}
break;
case V_210 :
V_7 = F_54 ( & V_52 ) ;
break;
case V_211 :
if ( V_52 . V_39 . V_43 . V_62 )
F_26 ( & V_52 . V_39 , V_55 ,
NULL ) ;
break;
case V_212 :
V_7 = F_76 ( & V_52 . V_39 ) ;
break;
case V_213 :
V_7 = F_78 ( & V_52 . V_39 ) ;
break;
case V_214 :
V_7 = F_79 ( & V_52 . V_39 ) ;
break;
default:
V_7 = - V_215 ;
if ( V_52 . V_39 . V_43 . V_62 )
F_26 ( & V_52 . V_39 ,
- V_216 , NULL ) ;
break;
}
if ( V_120 ) {
F_87 ( V_120 ) ;
V_120 = NULL ;
}
return V_7 ;
}
static int F_92 ( struct V_34 * V_35 )
{
int V_7 = F_93 ( V_8 -> V_9 ,
V_217 , V_35 ) ;
if ( V_7 )
return V_7 ;
if ( V_35 -> V_39 . V_43 . V_65 == 1 )
return - V_12 ;
return 0 ;
}
static void F_94 ( void )
{
struct V_146 * V_147 ;
struct V_146 * V_148 ;
F_64 ( & V_149 ) ;
F_65 (pos, tmp, &parahotplug_request_list) {
struct V_142 * V_143 =
F_66 ( V_147 , struct V_142 , V_150 ) ;
if ( ! F_95 ( V_140 , V_143 -> V_144 ) )
continue;
F_67 ( V_147 ) ;
if ( V_143 -> V_35 . V_39 . V_43 . V_62 )
F_26 (
& V_143 -> V_35 . V_39 ,
V_218 ,
& V_143 -> V_35 . V_49 . V_66 . V_64 ) ;
F_62 ( V_143 ) ;
}
F_68 ( & V_149 ) ;
}
static void F_96 ( struct V_184 * V_185 )
{
struct V_34 V_52 ;
int V_11 = 0 ;
int V_7 ;
do {
V_7 = F_93 ( V_8 -> V_9 ,
V_219 ,
& V_52 ) ;
} while ( ( ! V_7 ) && ( ++ V_11 < V_220 ) );
if ( V_7 != - V_204 )
goto V_221;
if ( V_8 -> V_222 ) {
V_52 = V_8 -> V_223 ;
V_8 -> V_222 = false ;
V_7 = 0 ;
} else {
V_7 = F_92 ( & V_52 ) ;
}
while ( ! V_7 ) {
V_8 -> V_224 = V_140 ;
V_7 = F_91 ( V_52 ,
F_97
( V_8 -> V_9 ) ) ;
if ( V_7 == - V_204 ) {
V_8 -> V_223 = V_52 ;
V_8 -> V_222 = true ;
break;
}
V_7 = F_92 ( & V_52 ) ;
}
F_94 () ;
V_221:
if ( F_98 ( V_140 , V_8 -> V_224 +
( V_225 * V_226 ) ) ) {
if ( V_8 -> V_227 !=
V_228 )
V_8 -> V_227 =
V_228 ;
} else {
if ( V_8 -> V_227 !=
V_229 )
V_8 -> V_227 =
V_229 ;
}
F_99 ( & V_8 -> V_230 ,
V_8 -> V_227 ) ;
}
static int F_100 ( struct V_73 * V_73 )
{
int V_7 = - V_104 ;
struct V_87 * V_9 ;
V_8 = F_32 ( sizeof( * V_8 ) , V_93 ) ;
if ( ! V_8 )
goto error;
V_7 = F_82 ( V_8 ) ;
if ( V_7 )
goto V_231;
V_73 -> V_232 = V_8 ;
V_8 -> V_73 = V_73 ;
V_8 -> V_227 = V_229 ;
V_7 = F_101 ( & V_8 -> V_73 -> V_2 . V_158 ,
V_233 ) ;
if ( V_7 < 0 )
goto V_234;
V_9 = V_8 -> V_9 ;
if ( ! F_102 ( F_103 ( V_9 ) ,
& V_8 -> V_73 -> V_2 ,
& V_183 ,
L_27 ,
sizeof( struct V_10 ) ,
V_235 ,
V_236 ) )
goto V_237;
if ( F_104 () )
F_105 ( & V_8 -> V_230 ,
F_84 ) ;
else
F_105 ( & V_8 -> V_230 ,
F_96 ) ;
V_8 -> V_224 = V_140 ;
V_8 -> V_227 = V_229 ;
F_99 ( & V_8 -> V_230 ,
V_8 -> V_227 ) ;
V_7 = F_106 () ;
if ( V_7 < 0 )
goto V_238;
return 0 ;
V_238:
F_107 ( & V_8 -> V_230 ) ;
V_237:
F_108 ( & V_8 -> V_73 -> V_2 . V_158 ,
V_233 ) ;
V_234:
F_37 ( V_8 -> V_9 ) ;
V_231:
F_38 ( V_8 ) ;
error:
F_28 ( & V_73 -> V_2 , L_28 , V_7 ) ;
return V_7 ;
}
static int F_109 ( struct V_73 * V_73 )
{
F_110 () ;
F_107 ( & V_8 -> V_230 ) ;
F_108 ( & V_8 -> V_73 -> V_2 . V_158 ,
V_233 ) ;
F_37 ( V_8 -> V_9 ) ;
F_38 ( V_8 ) ;
return 0 ;
}
static T_9 int F_111 ( void )
{
unsigned int V_239 , V_240 , V_241 , V_242 ;
if ( F_112 ( V_243 ) ) {
F_81 ( V_244 , & V_239 , & V_240 , & V_241 , & V_242 ) ;
return ( V_240 == V_245 ) &&
( V_241 == V_246 ) &&
( V_242 == V_247 ) ;
}
return 0 ;
}
static int T_9 F_113 ( void )
{
int V_166 ;
if ( ! F_111 () )
return - V_104 ;
V_166 = F_114 ( & V_248 ) ;
if ( V_166 )
return - V_104 ;
F_115 ( L_29 ) ;
return 0 ;
}
static void T_10 F_116 ( void )
{
F_117 ( & V_248 ) ;
}
