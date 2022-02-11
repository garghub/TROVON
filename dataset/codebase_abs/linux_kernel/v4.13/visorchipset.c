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
return sprintf ( V_5 , L_2 , error ) ;
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
return sprintf ( V_5 , L_2 , V_18 ) ;
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
return sprintf ( V_5 , L_3 , V_20 ) ;
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
static T_6
F_18 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = NULL ;
V_25 = (struct V_24 * ) ( V_23 -> V_26 ) ;
return V_25 -> V_27 ;
}
static void F_19 ( struct V_22 * V_23 )
{
V_8 -> V_28 -= V_23 -> V_29 ;
F_20 ( V_23 ) ;
}
static void *
F_21 ( struct V_22 * V_23 )
{
T_2 * V_30 ;
unsigned long V_31 ;
int V_32 = - 1 ;
void * V_33 = NULL ;
int V_34 ;
V_30 = V_23 -> V_35 ;
V_31 = V_23 -> V_36 ;
if ( V_31 == 0 )
return NULL ;
if ( ! V_30 )
return NULL ;
for ( V_34 = 0 , V_32 = - 1 ; V_34 < V_31 ; V_34 ++ )
if ( V_30 [ V_34 ] == '\0' ) {
V_32 = V_34 ;
break;
}
if ( V_32 < 0 )
V_32 = V_31 ;
V_33 = F_22 ( V_32 + 1 , V_37 ) ;
if ( ! V_33 )
return NULL ;
if ( V_32 > 0 )
memcpy ( V_33 , V_30 , V_32 ) ;
( ( T_2 * ) ( V_33 ) ) [ V_32 ] = '\0' ;
return V_33 ;
}
static void *
F_23 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = NULL ;
V_25 = (struct V_24 * ) ( V_23 -> V_26 ) ;
if ( V_25 -> V_38 + V_25 -> V_39 > V_23 -> V_29 )
return NULL ;
V_23 -> V_35 = V_23 -> V_26 + V_25 -> V_38 ;
V_23 -> V_36 = V_25 -> V_39 ;
return F_21 ( V_23 ) ;
}
static int F_24 ( struct V_1 * V_2 , void * V_26 )
{
struct V_40 * V_41 = F_25 ( V_2 ) ;
struct V_42 * V_27 = V_26 ;
T_4 V_43 = V_27 -> V_43 ;
T_4 V_44 = V_27 -> V_44 ;
if ( ( V_41 -> V_45 == V_43 ) &&
( V_41 -> V_46 == V_44 ) )
return 1 ;
return 0 ;
}
struct V_40 * F_26 ( T_4 V_43 , T_4 V_44 ,
struct V_40 * V_47 )
{
struct V_1 * V_2 ;
struct V_1 * V_48 = NULL ;
struct V_40 * V_41 = NULL ;
struct V_42 V_27 = {
. V_43 = V_43 ,
. V_44 = V_44
} ;
if ( V_47 )
V_48 = & V_47 -> V_1 ;
V_2 = F_27 ( & V_49 , V_48 , ( void * ) & V_27 ,
F_24 ) ;
if ( V_2 )
V_41 = F_25 ( V_2 ) ;
return V_41 ;
}
static void
F_28 ( struct V_50 * V_51 ,
struct V_52 * V_53 , int V_54 )
{
memset ( V_51 , 0 , sizeof( struct V_50 ) ) ;
memcpy ( & V_51 -> V_55 , V_53 , sizeof( struct V_52 ) ) ;
V_51 -> V_55 . V_56 = 0 ;
V_51 -> V_55 . V_57 = 0 ;
V_51 -> V_55 . V_58 = 0 ;
if ( V_54 < 0 ) {
V_51 -> V_55 . V_59 . V_60 = 1 ;
V_51 -> V_55 . V_61 = ( T_4 ) ( - V_54 ) ;
}
}
static int
F_29 ( struct V_52 * V_53 ,
int V_54 ,
enum V_62 V_63 )
{
struct V_50 V_64 ;
F_28 ( & V_64 , V_53 , V_54 ) ;
V_64 . V_65 . V_66 . V_63 = V_63 ;
return F_30 ( V_8 -> V_9 ,
V_67 , & V_64 ) ;
}
static int
F_31 ( struct V_50 * V_68 )
{
static int V_69 ;
enum V_62 V_63 = 0 ;
int V_70 = V_71 ;
int V_72 = 0 ;
if ( V_69 ) {
V_70 = - V_73 ;
V_72 = - V_74 ;
goto V_75;
}
V_69 = 1 ;
V_63 = V_68 -> V_65 . V_66 . V_63 &
V_76 ;
V_63 |= V_77 ;
V_75:
if ( V_68 -> V_55 . V_59 . V_78 )
V_72 = F_29 ( & V_68 -> V_55 , V_70 , V_63 ) ;
return V_72 ;
}
static int
F_32 ( struct V_52 * V_53 , int V_54 ,
struct V_79 * V_80 )
{
struct V_50 V_64 ;
F_28 ( & V_64 , V_53 , V_54 ) ;
if ( V_64 . V_55 . V_59 . V_81 == 1 )
return - V_12 ;
if ( V_80 ) {
V_64 . V_65 . V_82 . V_80 = * V_80 ;
V_64 . V_65 . V_82 . V_59 . V_83 = 1 ;
}
return F_30 ( V_8 -> V_9 ,
V_67 , & V_64 ) ;
}
static int
F_33 ( struct V_50 * V_51 , enum V_84 V_85 )
{
T_4 V_86 ;
T_5 V_87 ;
int V_7 ;
V_7 = F_2 ( V_8 -> V_9 ,
F_3 ( struct V_10 ,
V_88 ) ,
& V_87 , sizeof( T_5 ) ) ;
if ( V_7 ) {
F_34 ( & V_8 -> V_89 -> V_2 ,
L_4 ) ;
return V_7 ;
}
if ( V_87 != V_90 ) {
F_34 ( & V_8 -> V_89 -> V_2 ,
L_5 ) ;
return - V_74 ;
}
V_7 = F_2 ( V_8 -> V_9 ,
F_3 ( struct V_10 ,
V_91 ) ,
& V_86 , sizeof( T_4 ) ) ;
if ( V_7 ) {
F_34 ( & V_8 -> V_89 -> V_2 ,
L_6 ) ;
return V_7 ;
}
switch ( V_85 ) {
case V_92 :
V_86 += sizeof( struct V_50 ) ;
V_7 = F_6 ( V_8 -> V_9 ,
V_86 ,
V_51 ,
sizeof( struct V_50 ) ) ;
if ( V_7 ) {
F_34 ( & V_8 -> V_89 -> V_2 ,
L_7 ) ;
return V_7 ;
}
break;
case V_93 :
V_7 = F_6 ( V_8 -> V_9 ,
V_86 ,
V_51 ,
sizeof( struct V_50 ) ) ;
if ( V_7 ) {
F_34 ( & V_8 -> V_89 -> V_2 ,
L_8 ) ;
return V_7 ;
}
break;
default:
F_34 ( & V_8 -> V_89 -> V_2 ,
L_9 ) ;
break;
}
return 0 ;
}
static int
F_35 ( enum V_94 V_95 ,
struct V_52 * V_96 ,
int V_54 )
{
if ( ! V_96 )
return - V_74 ;
if ( V_96 -> V_27 != ( T_4 ) V_95 )
return - V_12 ;
return F_32 ( V_96 , V_54 , NULL ) ;
}
static int
F_36 ( enum V_94 V_95 ,
struct V_40 * V_97 , int V_54 ,
struct V_79 V_98 )
{
struct V_50 V_64 ;
T_4 V_43 = V_97 -> V_45 ;
T_4 V_44 = V_97 -> V_46 ;
if ( ! V_97 -> V_96 )
return - V_74 ;
if ( V_97 -> V_96 -> V_27 != V_95 )
return - V_12 ;
F_28 ( & V_64 , V_97 -> V_96 , V_54 ) ;
V_64 . V_65 . V_82 . V_43 = V_43 ;
V_64 . V_65 . V_82 . V_44 = V_44 ;
V_64 . V_65 . V_82 . V_80 = V_98 ;
return F_30 ( V_8 -> V_9 ,
V_67 , & V_64 ) ;
}
static int
F_37 ( struct V_50 * V_68 )
{
struct V_99 * V_65 = & V_68 -> V_65 ;
struct V_52 * V_100 = NULL ;
T_4 V_43 = V_65 -> V_101 . V_43 ;
struct V_40 * V_102 ;
struct V_103 * V_103 ;
int V_7 ;
V_102 = F_26 ( V_43 , V_104 , NULL ) ;
if ( V_102 && ( V_102 -> V_80 . V_105 == 1 ) ) {
F_34 ( & V_8 -> V_89 -> V_2 ,
L_10 ) ;
V_7 = - V_106 ;
goto V_107;
}
V_102 = F_38 ( sizeof( * V_102 ) , V_37 ) ;
if ( ! V_102 ) {
V_7 = - V_108 ;
goto V_107;
}
F_39 ( & V_102 -> V_109 ) ;
V_102 -> V_45 = V_43 ;
V_102 -> V_46 = V_104 ;
if ( F_40 ( V_65 -> V_101 . V_110 , V_111 ) == 0 ) {
V_7 = F_33 ( V_68 , V_93 ) ;
if ( V_7 )
goto V_112;
}
if ( V_68 -> V_55 . V_59 . V_78 == 1 ) {
V_100 = F_38 ( sizeof( * V_100 ) ,
V_37 ) ;
if ( ! V_100 ) {
V_7 = - V_108 ;
goto V_112;
}
memcpy ( V_100 , & V_68 -> V_55 ,
sizeof( struct V_52 ) ) ;
V_102 -> V_96 = V_100 ;
}
V_103 = F_41 ( V_65 -> V_101 . V_113 ,
V_65 -> V_101 . V_114 ,
V_37 ,
V_65 -> V_101 . V_115 ) ;
if ( ! V_103 ) {
V_7 = - V_108 ;
goto V_116;
}
V_102 -> V_103 = V_103 ;
V_7 = F_42 ( V_102 ) ;
if ( V_7 )
goto V_117;
return 0 ;
V_117:
F_43 ( V_103 ) ;
V_116:
F_20 ( V_102 -> V_96 ) ;
V_112:
F_20 ( V_102 ) ;
V_107:
if ( V_68 -> V_55 . V_59 . V_78 == 1 )
F_35 ( V_68 -> V_55 . V_27 , & V_68 -> V_55 , V_7 ) ;
return V_7 ;
}
static int
F_44 ( struct V_50 * V_68 )
{
struct V_99 * V_65 = & V_68 -> V_65 ;
struct V_52 * V_100 = NULL ;
T_4 V_43 = V_65 -> V_118 . V_43 ;
struct V_40 * V_102 ;
int V_7 ;
V_102 = F_26 ( V_43 , V_104 , NULL ) ;
if ( ! V_102 ) {
V_7 = - V_119 ;
goto V_107;
}
if ( V_102 -> V_80 . V_105 == 0 ) {
V_7 = - V_120 ;
goto V_107;
}
if ( V_102 -> V_96 ) {
V_7 = - V_106 ;
goto V_107;
}
if ( V_68 -> V_55 . V_59 . V_78 == 1 ) {
V_100 = F_38 ( sizeof( * V_100 ) , V_37 ) ;
if ( ! V_100 ) {
V_7 = - V_108 ;
goto V_107;
}
memcpy ( V_100 , & V_68 -> V_55 ,
sizeof( struct V_52 ) ) ;
V_102 -> V_96 = V_100 ;
}
F_45 ( V_102 ) ;
return 0 ;
V_107:
if ( V_68 -> V_55 . V_59 . V_78 == 1 )
F_35 ( V_68 -> V_55 . V_27 , & V_68 -> V_55 , V_7 ) ;
return V_7 ;
}
static int
F_46 ( struct V_50 * V_68 ,
struct V_22 * V_121 )
{
struct V_99 * V_65 = & V_68 -> V_65 ;
T_4 V_43 ;
struct V_40 * V_102 ;
int V_7 = 0 ;
V_43 = V_65 -> V_122 . V_43 ;
V_102 = F_26 ( V_43 , V_104 , NULL ) ;
if ( ! V_102 ) {
V_7 = - V_12 ;
goto V_107;
} else if ( V_102 -> V_80 . V_105 == 0 ) {
V_7 = - V_12 ;
goto V_107;
} else if ( V_102 -> V_96 ) {
V_7 = - V_74 ;
goto V_107;
}
V_7 = F_47
( V_102 -> V_103 ,
V_65 -> V_122 . V_123 ) ;
if ( V_7 )
goto V_107;
if ( V_121 ) {
V_102 -> V_124 = F_18 ( V_121 ) ;
V_102 -> V_125 = F_23 ( V_121 ) ;
}
if ( V_68 -> V_55 . V_59 . V_78 == 1 )
F_35 ( V_68 -> V_55 . V_27 , & V_68 -> V_55 , V_7 ) ;
return 0 ;
V_107:
F_34 ( & V_8 -> V_89 -> V_2 ,
L_11 , V_7 ) ;
if ( V_68 -> V_55 . V_59 . V_78 == 1 )
F_35 ( V_68 -> V_55 . V_27 , & V_68 -> V_55 , V_7 ) ;
return V_7 ;
}
static int
F_48 ( struct V_50 * V_68 )
{
struct V_99 * V_65 = & V_68 -> V_65 ;
struct V_52 * V_100 = NULL ;
T_4 V_43 = V_65 -> V_126 . V_43 ;
T_4 V_44 = V_65 -> V_126 . V_44 ;
struct V_40 * V_127 = NULL ;
struct V_40 * V_102 ;
struct V_103 * V_103 ;
int V_7 ;
V_102 = F_26 ( V_43 , V_104 , NULL ) ;
if ( ! V_102 ) {
F_34 ( & V_8 -> V_89 -> V_2 ,
L_12 , V_43 ) ;
V_7 = - V_119 ;
goto V_107;
}
if ( V_102 -> V_80 . V_105 == 0 ) {
F_34 ( & V_8 -> V_89 -> V_2 ,
L_13 , V_43 ) ;
V_7 = - V_12 ;
goto V_107;
}
V_127 = F_26 ( V_43 , V_44 , NULL ) ;
if ( V_127 && ( V_127 -> V_80 . V_105 == 1 ) ) {
F_34 ( & V_8 -> V_89 -> V_2 ,
L_14 , V_43 , V_44 ) ;
V_7 = - V_106 ;
goto V_107;
}
V_127 = F_38 ( sizeof( * V_127 ) , V_37 ) ;
if ( ! V_127 ) {
V_7 = - V_108 ;
goto V_107;
}
V_127 -> V_45 = V_43 ;
V_127 -> V_46 = V_44 ;
V_127 -> V_128 = V_65 -> V_126 . V_129 ;
V_127 -> V_1 . V_130 = & V_102 -> V_1 ;
V_103 =
F_49 ( V_65 -> V_126 . V_113 ,
V_65 -> V_126 . V_114 ,
V_37 ,
V_65 -> V_126 . V_131 ) ;
if ( ! V_103 ) {
F_34 ( & V_8 -> V_89 -> V_2 ,
L_15 ,
V_43 , V_44 ) ;
V_7 = - V_108 ;
goto V_132;
}
V_127 -> V_103 = V_103 ;
V_127 -> V_133 = V_65 -> V_126 . V_131 ;
if ( F_40 ( V_65 -> V_126 . V_131 ,
V_134 ) == 0 ) {
V_7 = F_33 ( V_68 , V_92 ) ;
if ( V_7 )
goto V_135;
}
if ( V_68 -> V_55 . V_59 . V_78 == 1 ) {
V_100 = F_38 ( sizeof( * V_100 ) , V_37 ) ;
if ( ! V_100 ) {
V_7 = - V_108 ;
goto V_135;
}
memcpy ( V_100 , & V_68 -> V_55 ,
sizeof( struct V_52 ) ) ;
V_127 -> V_96 = V_100 ;
}
V_7 = F_50 ( V_127 ) ;
if ( V_7 )
goto V_135;
return 0 ;
V_135:
F_43 ( V_103 ) ;
V_132:
F_20 ( V_127 ) ;
V_107:
if ( V_68 -> V_55 . V_59 . V_78 == 1 )
F_35 ( V_68 -> V_55 . V_27 , & V_68 -> V_55 , V_7 ) ;
return V_7 ;
}
static int
F_51 ( struct V_50 * V_68 )
{
struct V_99 * V_65 = & V_68 -> V_65 ;
struct V_52 * V_100 = NULL ;
T_4 V_43 = V_65 -> V_82 . V_43 ;
T_4 V_44 = V_65 -> V_82 . V_44 ;
struct V_79 V_80 = V_65 -> V_82 . V_80 ;
struct V_40 * V_127 ;
int V_7 = 0 ;
V_127 = F_26 ( V_43 , V_44 , NULL ) ;
if ( ! V_127 ) {
V_7 = - V_119 ;
goto V_107;
}
if ( V_127 -> V_80 . V_105 == 0 ) {
V_7 = - V_12 ;
goto V_107;
}
if ( V_127 -> V_96 ) {
V_7 = - V_74 ;
goto V_107;
}
if ( V_68 -> V_55 . V_59 . V_78 == 1 ) {
V_100 = F_38 ( sizeof( * V_100 ) , V_37 ) ;
if ( ! V_100 ) {
V_7 = - V_108 ;
goto V_107;
}
memcpy ( V_100 , & V_68 -> V_55 ,
sizeof( struct V_52 ) ) ;
V_127 -> V_96 = V_100 ;
}
if ( V_80 . V_136 == V_137 . V_136 &&
V_80 . V_138 == V_137 . V_138 )
V_7 = F_52 ( V_127 ) ;
else if ( V_80 . V_136 == V_139 . V_136 &&
V_80 . V_138 == V_139 . V_138 )
V_7 = F_53 ( V_127 ) ;
if ( V_7 )
goto V_107;
return 0 ;
V_107:
F_34 ( & V_8 -> V_89 -> V_2 , L_16 , V_7 ) ;
if ( V_68 -> V_55 . V_59 . V_78 == 1 )
F_35 ( V_68 -> V_55 . V_27 , & V_68 -> V_55 , V_7 ) ;
return V_7 ;
}
static int
F_54 ( struct V_50 * V_68 )
{
struct V_99 * V_65 = & V_68 -> V_65 ;
struct V_52 * V_100 = NULL ;
T_4 V_43 = V_65 -> V_140 . V_43 ;
T_4 V_44 = V_65 -> V_140 . V_44 ;
struct V_40 * V_127 ;
int V_7 ;
V_127 = F_26 ( V_43 , V_44 , NULL ) ;
if ( ! V_127 ) {
V_7 = - V_119 ;
goto V_107;
}
if ( V_127 -> V_80 . V_105 == 0 ) {
V_7 = - V_12 ;
goto V_107;
}
if ( V_127 -> V_96 ) {
V_7 = - V_74 ;
goto V_107;
}
if ( V_68 -> V_55 . V_59 . V_78 == 1 ) {
V_100 = F_38 ( sizeof( * V_100 ) , V_37 ) ;
if ( ! V_100 ) {
V_7 = - V_108 ;
goto V_107;
}
memcpy ( V_100 , & V_68 -> V_55 ,
sizeof( struct V_52 ) ) ;
V_127 -> V_96 = V_100 ;
}
F_55 ( V_127 ) ;
return 0 ;
V_107:
if ( V_68 -> V_55 . V_59 . V_78 == 1 )
F_35 ( V_68 -> V_55 . V_27 , & V_68 -> V_55 , V_7 ) ;
return V_7 ;
}
static int
F_56 ( void )
{
static T_7 V_27 = F_57 ( 0 ) ;
return F_58 ( & V_27 ) ;
}
static unsigned long
F_59 ( void )
{
return V_141 + F_60 ( V_142 ) ;
}
static struct V_143 *
F_61 ( struct V_50 * V_51 )
{
struct V_143 * V_144 ;
V_144 = F_22 ( sizeof( * V_144 ) , V_37 ) ;
if ( ! V_144 )
return NULL ;
V_144 -> V_27 = F_56 () ;
V_144 -> V_145 = F_59 () ;
V_144 -> V_51 = * V_51 ;
return V_144 ;
}
static void
F_62 ( struct V_143 * V_144 )
{
F_20 ( V_144 ) ;
}
static int
F_63 ( int V_27 , T_5 V_146 )
{
struct V_147 * V_148 ;
struct V_147 * V_149 ;
F_64 ( & V_150 ) ;
F_65 (pos, tmp, &parahotplug_request_list) {
struct V_143 * V_144 =
F_66 ( V_148 , struct V_143 , V_151 ) ;
if ( V_144 -> V_27 == V_27 ) {
F_67 ( V_148 ) ;
F_68 ( & V_150 ) ;
V_144 -> V_51 . V_65 . V_82 . V_80 . V_146 = V_146 ;
if ( V_144 -> V_51 . V_55 . V_59 . V_78 )
F_32 (
& V_144 -> V_51 . V_55 , V_71 ,
& V_144 -> V_51 . V_65 . V_82 . V_80 ) ;
F_62 ( V_144 ) ;
return 0 ;
}
}
F_68 ( & V_150 ) ;
return - V_12 ;
}
static T_1 F_69 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_3 V_11 )
{
unsigned int V_27 ;
int V_7 ;
if ( F_70 ( V_5 , 10 , & V_27 ) )
return - V_12 ;
V_7 = F_63 ( V_27 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
return V_11 ;
}
static T_1 F_71 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_3 V_11 )
{
unsigned int V_27 ;
if ( F_70 ( V_5 , 10 , & V_27 ) )
return - V_12 ;
F_63 ( V_27 , 1 ) ;
return V_11 ;
}
static int
F_72 ( struct V_143 * V_144 )
{
struct V_99 * V_65 = & V_144 -> V_51 . V_65 ;
char V_152 [ 40 ] , V_153 [ 40 ] , V_154 [ 40 ] , V_155 [ 40 ] , V_156 [ 40 ] ,
V_157 [ 40 ] ;
char * V_158 [] = {
V_152 , V_153 , V_154 , V_155 , V_156 , V_157 , NULL
} ;
sprintf ( V_152 , L_17 ) ;
sprintf ( V_153 , L_18 , V_144 -> V_27 ) ;
sprintf ( V_154 , L_19 ,
V_65 -> V_82 . V_80 . V_146 ) ;
sprintf ( V_155 , L_20 ,
V_65 -> V_82 . V_43 ) ;
sprintf ( V_156 , L_21 ,
V_65 -> V_82 . V_44 >> 3 ) ;
sprintf ( V_157 , L_22 ,
V_65 -> V_82 . V_44 & 0x7 ) ;
return F_73 ( & V_8 -> V_89 -> V_2 . V_159 ,
V_160 , V_158 ) ;
}
static int
F_74 ( struct V_50 * V_68 )
{
struct V_143 * V_144 ;
int V_7 ;
V_144 = F_61 ( V_68 ) ;
if ( ! V_144 )
return - V_108 ;
if ( V_68 -> V_65 . V_82 . V_80 . V_146 ) {
V_7 = F_72 ( V_144 ) ;
if ( V_7 )
goto V_107;
F_32 ( & V_68 -> V_55 , V_71 ,
& V_68 -> V_65 . V_82 . V_80 ) ;
F_62 ( V_144 ) ;
return 0 ;
}
F_64 ( & V_150 ) ;
F_75 ( & V_144 -> V_151 , & V_161 ) ;
F_68 ( & V_150 ) ;
V_7 = F_72 ( V_144 ) ;
if ( V_7 )
goto V_107;
return 0 ;
V_107:
F_32 ( & V_68 -> V_55 , V_7 ,
& V_68 -> V_65 . V_82 . V_80 ) ;
return V_7 ;
}
static int
F_76 ( struct V_52 * V_53 )
{
int V_72 ;
V_72 = F_77 ( & V_8 -> V_89 -> V_2 . V_159 ,
V_162 ) ;
if ( V_53 -> V_59 . V_78 )
F_32 ( V_53 , V_72 , NULL ) ;
return V_72 ;
}
static int
F_78 ( struct V_52 * V_53 )
{
char V_163 [ 20 ] ;
char * V_158 [] = { V_163 , NULL } ;
int V_72 ;
sprintf ( V_163 , L_23 , 1 ) ;
V_72 = F_73 ( & V_8 -> V_89 -> V_2 . V_159 ,
V_160 , V_158 ) ;
if ( V_53 -> V_59 . V_78 )
F_32 ( V_53 , V_72 , NULL ) ;
return V_72 ;
}
static int
F_79 ( struct V_52 * V_53 )
{
int V_72 ;
V_72 = F_77 ( & V_8 -> V_89 -> V_2 . V_159 ,
V_164 ) ;
if ( V_53 -> V_59 . V_78 )
F_32 ( V_53 , V_72 , NULL ) ;
return V_72 ;
}
static int F_80 ( unsigned long V_165 , unsigned long V_166 )
{
int V_167 = 0 ;
unsigned int V_168 , V_169 , V_170 , V_171 ;
unsigned long V_172 ;
unsigned long V_173 ;
V_172 = V_166 & 0xFFFFFFFF ;
V_173 = V_166 >> 32 ;
F_81 ( 0x00000001 , & V_168 , & V_169 , & V_170 , & V_171 ) ;
if ( ! ( V_170 & 0x80000000 ) )
return - V_174 ;
__asm__ __volatile__(".byte 0x00f, 0x001, 0x0c1" : "=a"(result) :
"a"(tuple), "b"(reg_ebx), "c"(reg_ecx));
if ( V_167 )
goto error;
return 0 ;
error:
switch ( V_167 ) {
case V_175 :
return - V_12 ;
case V_176 :
return - V_119 ;
default:
return - V_177 ;
}
}
static unsigned int
F_82 ( T_8 * V_178 , T_4 * V_179 )
{
V_8 -> V_180 . V_181 = F_83 (
& V_8 -> V_180 . V_182 ) ;
V_8 -> V_180 . V_7 = F_80 ( V_183 ,
V_8 -> V_180 . V_181 ) ;
if ( V_8 -> V_180 . V_7 )
return V_8 -> V_180 . V_7 ;
* V_178 = V_8 -> V_180 . V_182 . V_184 ;
* V_179 = V_8 -> V_180 . V_182 . V_114 ;
return 0 ;
}
static T_8 F_84 ( void )
{
T_8 V_185 = 0 ;
T_4 V_186 = 0 ;
if ( F_82 ( & V_185 , & V_186 ) )
return 0 ;
return V_185 ;
}
static void
F_85 ( struct V_187 * V_188 )
{
struct V_50 V_189 ;
struct V_50 V_190 ;
struct V_50 V_51 ;
T_4 V_86 ;
T_5 V_87 ;
V_51 . V_55 . V_27 = V_191 ;
V_51 . V_65 . V_66 . V_192 = 23 ;
V_51 . V_65 . V_66 . V_193 = 0 ;
F_31 ( & V_51 ) ;
if ( F_2 ( V_8 -> V_9 ,
F_3 ( struct V_10 ,
V_88 ) ,
& V_87 , sizeof( T_5 ) ) < 0 ) {
F_34 ( & V_8 -> V_89 -> V_2 ,
L_24 ) ;
return;
}
if ( V_87 != V_90 ) {
F_34 ( & V_8 -> V_89 -> V_2 ,
L_25 ) ;
return;
}
if ( F_2 ( V_8 -> V_9 ,
F_3 ( struct V_10 ,
V_91 ) ,
& V_86 , sizeof( T_4 ) ) < 0 ) {
F_34 ( & V_8 -> V_89 -> V_2 ,
L_24 ) ;
return;
}
if ( F_2 ( V_8 -> V_9 ,
V_86 ,
& V_189 ,
sizeof( struct V_50 ) ) < 0 ) {
F_34 ( & V_8 -> V_89 -> V_2 ,
L_24 ) ;
return;
}
if ( F_2 ( V_8 -> V_9 ,
V_86 +
sizeof( struct V_50 ) ,
& V_190 ,
sizeof( struct V_50 ) ) < 0 ) {
F_34 ( & V_8 -> V_89 -> V_2 ,
L_24 ) ;
return;
}
if ( ! V_189 . V_65 . V_101 . V_113 ) {
F_34 ( & V_8 -> V_89 -> V_2 ,
L_26 ) ;
return;
}
F_37 ( & V_189 ) ;
if ( ! V_190 . V_65 . V_126 . V_113 ) {
F_34 ( & V_8 -> V_89 -> V_2 ,
L_27 ) ;
return;
}
F_48 ( & V_190 ) ;
}
void
F_86 ( struct V_40 * V_102 , int V_54 )
{
if ( V_54 >= 0 )
V_102 -> V_80 . V_105 = 1 ;
F_35 ( V_194 , V_102 -> V_96 ,
V_54 ) ;
F_20 ( V_102 -> V_96 ) ;
V_102 -> V_96 = NULL ;
}
void
F_87 ( struct V_40 * V_102 , int V_54 )
{
F_35 ( V_195 , V_102 -> V_96 ,
V_54 ) ;
F_20 ( V_102 -> V_96 ) ;
V_102 -> V_96 = NULL ;
}
void
F_88 ( struct V_40 * V_127 , int V_54 )
{
if ( V_54 >= 0 )
V_127 -> V_80 . V_105 = 1 ;
F_35 ( V_196 , V_127 -> V_96 ,
V_54 ) ;
F_20 ( V_127 -> V_96 ) ;
V_127 -> V_96 = NULL ;
}
void
F_89 ( struct V_40 * V_127 , int V_54 )
{
F_35 ( V_197 , V_127 -> V_96 ,
V_54 ) ;
F_20 ( V_127 -> V_96 ) ;
V_127 -> V_96 = NULL ;
}
void
F_90 ( struct V_40 * V_127 , int V_54 )
{
F_36 ( V_198 ,
V_127 , V_54 ,
V_139 ) ;
F_20 ( V_127 -> V_96 ) ;
V_127 -> V_96 = NULL ;
}
void
F_91 ( struct V_40 * V_127 , int V_54 )
{
F_36 ( V_198 ,
V_127 , V_54 ,
V_137 ) ;
F_20 ( V_127 -> V_96 ) ;
V_127 -> V_96 = NULL ;
}
static struct V_22 *
F_92 ( T_8 V_185 , T_4 V_199 , bool V_200 , bool * V_201 )
{
int V_202 = sizeof( struct V_22 ) + V_199 ;
struct V_22 * V_23 ;
* V_201 = false ;
V_202 ++ ;
if ( ( V_8 -> V_28 + V_199 )
> V_203 ) {
* V_201 = true ;
return NULL ;
}
V_23 = F_38 ( V_202 , V_37 ) ;
if ( ! V_23 ) {
* V_201 = true ;
return NULL ;
}
V_23 -> V_202 = V_202 ;
V_23 -> V_29 = V_199 ;
V_23 -> V_35 = NULL ;
V_23 -> V_36 = 0 ;
V_23 -> V_204 = false ;
if ( V_200 ) {
void * V_97 ;
if ( V_185 > F_83 ( V_205 - 1 ) )
goto V_206;
V_97 = F_93 ( ( unsigned long ) ( V_185 ) ) ;
memcpy ( V_23 -> V_26 , V_97 , V_199 ) ;
} else {
void * V_207 = F_94 ( V_185 , V_199 , V_208 ) ;
if ( ! V_207 )
goto V_206;
memcpy ( V_23 -> V_26 , V_207 , V_199 ) ;
F_95 ( V_207 ) ;
}
V_23 -> V_204 = true ;
V_8 -> V_28 += V_23 -> V_29 ;
return V_23 ;
V_206:
F_19 ( V_23 ) ;
return NULL ;
}
static int
F_96 ( struct V_50 V_68 , T_8 V_113 )
{
struct V_99 * V_65 = & V_68 . V_65 ;
T_8 V_209 ;
T_4 V_210 ;
struct V_22 * V_121 = NULL ;
bool V_211 ;
struct V_50 V_212 ;
int V_7 = 0 ;
V_211 = ( V_68 . V_55 . V_59 . V_81 == 1 ) ;
V_209 = V_113 + V_68 . V_55 . V_57 ;
V_210 = V_68 . V_55 . V_56 ;
if ( V_209 && V_210 ) {
bool V_201 = false ;
V_121 =
F_92 ( V_209 , V_210 ,
V_211 , & V_201 ) ;
if ( ! V_121 && V_201 )
return - V_213 ;
}
if ( ! V_211 ) {
F_28 ( & V_212 , & V_68 . V_55 ,
V_71 ) ;
V_7 = F_30 ( V_8 -> V_9 ,
V_214 ,
& V_212 ) ;
if ( V_7 )
return V_7 ;
}
switch ( V_68 . V_55 . V_27 ) {
case V_191 :
V_7 = F_31 ( & V_68 ) ;
break;
case V_194 :
V_7 = F_37 ( & V_68 ) ;
break;
case V_195 :
V_7 = F_44 ( & V_68 ) ;
break;
case V_215 :
V_7 = F_46 ( & V_68 , V_121 ) ;
break;
case V_196 :
V_7 = F_48 ( & V_68 ) ;
break;
case V_198 :
if ( V_65 -> V_82 . V_59 . V_83 ) {
V_7 = F_74 ( & V_68 ) ;
} else {
V_7 = F_51 ( & V_68 ) ;
break;
}
break;
case V_197 :
V_7 = F_54 ( & V_68 ) ;
break;
case V_216 :
if ( V_68 . V_55 . V_59 . V_78 )
F_32 ( & V_68 . V_55 , V_71 ,
NULL ) ;
break;
case V_217 :
V_7 = F_76 ( & V_68 . V_55 ) ;
break;
case V_218 :
V_7 = F_78 ( & V_68 . V_55 ) ;
break;
case V_219 :
V_7 = F_79 ( & V_68 . V_55 ) ;
break;
default:
V_7 = - V_220 ;
if ( V_68 . V_55 . V_59 . V_78 )
F_32 ( & V_68 . V_55 ,
- V_221 , NULL ) ;
break;
}
if ( V_121 ) {
F_19 ( V_121 ) ;
V_121 = NULL ;
}
return V_7 ;
}
static int
F_97 ( struct V_50 * V_51 )
{
int V_7 ;
V_7 = F_98 ( V_8 -> V_9 ,
V_222 , V_51 ) ;
if ( V_7 )
return V_7 ;
if ( V_51 -> V_55 . V_59 . V_81 == 1 )
return - V_12 ;
return 0 ;
}
static void
F_99 ( void )
{
struct V_147 * V_148 ;
struct V_147 * V_149 ;
F_64 ( & V_150 ) ;
F_65 (pos, tmp, &parahotplug_request_list) {
struct V_143 * V_144 =
F_66 ( V_148 , struct V_143 , V_151 ) ;
if ( ! F_100 ( V_141 , V_144 -> V_145 ) )
continue;
F_67 ( V_148 ) ;
if ( V_144 -> V_51 . V_55 . V_59 . V_78 )
F_32 (
& V_144 -> V_51 . V_55 ,
V_223 ,
& V_144 -> V_51 . V_65 . V_82 . V_80 ) ;
F_62 ( V_144 ) ;
}
F_68 ( & V_150 ) ;
}
static void
F_101 ( struct V_187 * V_188 )
{
struct V_50 V_68 ;
int V_11 = 0 ;
int V_7 ;
do {
V_7 = F_98 ( V_8 -> V_9 ,
V_224 ,
& V_68 ) ;
} while ( ( ! V_7 ) && ( ++ V_11 < V_225 ) );
if ( V_7 != - V_213 )
goto V_226;
if ( V_8 -> V_227 ) {
V_68 = V_8 -> V_228 ;
V_8 -> V_227 = false ;
V_7 = 0 ;
} else {
V_7 = F_97 ( & V_68 ) ;
}
while ( ! V_7 ) {
V_8 -> V_229 = V_141 ;
V_7 = F_96 ( V_68 ,
F_102
( V_8 -> V_9 ) ) ;
if ( V_7 == - V_213 ) {
V_8 -> V_228 = V_68 ;
V_8 -> V_227 = true ;
break;
}
V_7 = F_97 ( & V_68 ) ;
}
F_99 () ;
V_226:
if ( F_103 ( V_141 , V_8 -> V_229 +
( V_230 * V_231 ) ) ) {
if ( V_8 -> V_232 !=
V_233 )
V_8 -> V_232 =
V_233 ;
} else {
if ( V_8 -> V_232 !=
V_234 )
V_8 -> V_232 =
V_234 ;
}
F_104 ( & V_8 -> V_235 ,
V_8 -> V_232 ) ;
}
static int
F_105 ( struct V_89 * V_89 )
{
int V_7 = - V_119 ;
T_8 V_185 ;
T_6 V_236 = V_237 ;
struct V_103 * V_9 ;
V_8 = F_38 ( sizeof( * V_8 ) , V_37 ) ;
if ( ! V_8 )
goto error;
V_185 = F_84 () ;
if ( ! V_185 )
goto error;
V_89 -> V_238 = V_8 ;
V_8 -> V_89 = V_89 ;
V_8 -> V_232 = V_234 ;
V_9 = F_49 ( V_185 ,
0 , V_37 , V_236 ) ;
if ( ! V_9 )
goto V_239;
V_8 -> V_9 = V_9 ;
V_7 = F_106 ( & V_8 -> V_89 -> V_2 . V_159 ,
V_240 ) ;
if ( V_7 < 0 )
goto V_241;
if ( ! F_107 (
F_108 ( V_9 ) ) )
goto V_242;
if ( F_109 () )
F_110 ( & V_8 -> V_235 ,
F_85 ) ;
else
F_110 ( & V_8 -> V_235 ,
F_101 ) ;
V_8 -> V_229 = V_141 ;
V_8 -> V_232 = V_234 ;
F_104 ( & V_8 -> V_235 ,
V_8 -> V_232 ) ;
V_7 = F_111 () ;
if ( V_7 < 0 )
goto V_243;
return 0 ;
V_243:
F_112 ( & V_8 -> V_235 ) ;
V_242:
F_113 ( & V_8 -> V_89 -> V_2 . V_159 ,
V_240 ) ;
V_241:
F_43 ( V_8 -> V_9 ) ;
V_239:
F_20 ( V_8 ) ;
error:
F_34 ( & V_89 -> V_2 , L_28 , V_7 ) ;
return V_7 ;
}
static int
F_114 ( struct V_89 * V_89 )
{
F_115 () ;
F_112 ( & V_8 -> V_235 ) ;
F_113 ( & V_8 -> V_89 -> V_2 . V_159 ,
V_240 ) ;
F_43 ( V_8 -> V_9 ) ;
F_20 ( V_8 ) ;
return 0 ;
}
static T_9 int F_116 ( void )
{
unsigned int V_244 , V_245 , V_246 , V_247 ;
if ( F_117 ( V_248 ) ) {
F_81 ( V_249 , & V_244 , & V_245 , & V_246 , & V_247 ) ;
return ( V_245 == V_250 ) &&
( V_246 == V_251 ) &&
( V_247 == V_252 ) ;
} else {
return 0 ;
}
}
static int F_118 ( void )
{
int V_167 ;
if ( ! F_116 () )
return - V_119 ;
V_167 = F_119 ( & V_253 ) ;
if ( V_167 )
return - V_119 ;
F_120 ( L_29 ) ;
return 0 ;
}
static void F_121 ( void )
{
F_122 ( & V_253 ) ;
}
