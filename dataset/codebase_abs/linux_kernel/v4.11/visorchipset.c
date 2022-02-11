static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
unsigned int V_3 = F_2 ( V_1 ) ;
if ( V_3 )
return - V_4 ;
return 0 ;
}
static int
F_3 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return 0 ;
}
static T_1 F_4 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
T_2 V_10 = 0 ;
F_5 ( V_11 ,
F_6 ( struct V_12 ,
V_10 ) , & V_10 , sizeof( T_2 ) ) ;
return sprintf ( V_9 , L_1 , V_10 ) ;
}
static T_1 F_7 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_3 V_13 )
{
T_2 V_10 ;
int V_14 ;
if ( F_8 ( V_9 , 10 , & V_10 ) )
return - V_15 ;
V_14 = F_9
( V_11 ,
F_6 ( struct V_12 ,
V_10 ) ,
& V_10 , sizeof( T_2 ) ) ;
if ( V_14 )
return V_14 ;
return V_13 ;
}
static T_1 F_10 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
struct V_16 V_16 ;
F_5 ( V_11 ,
F_6 ( struct V_12 ,
V_17 ) , & V_16 ,
sizeof( struct V_16 ) ) ;
return sprintf ( V_9 , L_1 , V_16 . V_18 ) ;
}
static T_1 F_11 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_3 V_13 )
{
int V_19 , V_14 ;
struct V_16 V_16 ;
if ( F_12 ( V_9 , 10 , & V_19 ) )
return - V_15 ;
V_16 . V_18 = V_19 ;
V_14 = F_9
( V_11 ,
F_6 ( struct V_12 ,
V_17 ) , & ( V_16 ) ,
sizeof( struct V_16 ) ) ;
if ( V_14 )
return V_14 ;
return V_13 ;
}
static T_1 F_13 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
T_4 error = 0 ;
F_5 ( V_11 ,
F_6 ( struct V_12 ,
V_20 ) ,
& error , sizeof( T_4 ) ) ;
return sprintf ( V_9 , L_2 , error ) ;
}
static T_1 F_14 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_13 )
{
T_4 error ;
int V_14 ;
if ( F_15 ( V_9 , 10 , & error ) )
return - V_15 ;
V_14 = F_9
( V_11 ,
F_6 ( struct V_12 ,
V_20 ) ,
& error , sizeof( T_4 ) ) ;
if ( V_14 )
return V_14 ;
return V_13 ;
}
static T_1 F_16 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
T_4 V_21 = 0 ;
F_5
( V_11 ,
F_6 ( struct V_12 ,
V_22 ) ,
& V_21 , sizeof( T_4 ) ) ;
return sprintf ( V_9 , L_2 , V_21 ) ;
}
static T_1 F_17 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_3 V_13 )
{
T_4 V_21 ;
int V_14 ;
if ( F_15 ( V_9 , 10 , & V_21 ) )
return - V_15 ;
V_14 = F_9
( V_11 ,
F_6 ( struct V_12 ,
V_22 ) ,
& V_21 , sizeof( T_4 ) ) ;
if ( V_14 )
return V_14 ;
return V_13 ;
}
static T_1 F_18 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
T_5 V_23 = 0 ;
F_5 ( V_11 ,
F_6 ( struct V_12 ,
V_24 ) ,
& V_23 , sizeof( T_5 ) ) ;
return sprintf ( V_9 , L_3 , V_23 ) ;
}
static T_1 F_19 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_3 V_13 )
{
T_5 V_23 ;
int V_14 ;
if ( F_20 ( V_9 , 10 , & V_23 ) )
return - V_15 ;
V_14 = F_9
( V_11 ,
F_6 ( struct V_12 ,
V_24 ) ,
& V_23 , sizeof( T_5 ) ) ;
if ( V_14 )
return V_14 ;
return V_13 ;
}
static T_6
F_21 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = NULL ;
V_28 = (struct V_27 * ) ( V_26 -> V_29 ) ;
return V_28 -> V_30 ;
}
static void F_22 ( struct V_25 * V_26 )
{
V_31 -= V_26 -> V_32 ;
F_23 ( V_26 ) ;
}
static void *
F_24 ( struct V_25 * V_26 )
{
T_2 * V_33 ;
unsigned long V_34 ;
int V_35 = - 1 ;
void * V_36 = NULL ;
int V_37 ;
V_33 = V_26 -> V_38 ;
V_34 = V_26 -> V_39 ;
if ( V_34 == 0 )
return NULL ;
if ( ! V_33 )
return NULL ;
for ( V_37 = 0 , V_35 = - 1 ; V_37 < V_34 ; V_37 ++ )
if ( V_33 [ V_37 ] == '\0' ) {
V_35 = V_37 ;
break;
}
if ( V_35 < 0 )
V_35 = V_34 ;
V_36 = F_25 ( V_35 + 1 , V_40 | V_41 ) ;
if ( ! V_36 )
return NULL ;
if ( V_35 > 0 )
memcpy ( V_36 , V_33 , V_35 ) ;
( ( T_2 * ) ( V_36 ) ) [ V_35 ] = '\0' ;
return V_36 ;
}
static void *
F_26 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = NULL ;
V_28 = (struct V_27 * ) ( V_26 -> V_29 ) ;
if ( V_28 -> V_42 + V_28 -> V_43 > V_26 -> V_32 )
return NULL ;
V_26 -> V_38 = V_26 -> V_29 + V_28 -> V_42 ;
V_26 -> V_39 = V_28 -> V_43 ;
return F_24 ( V_26 ) ;
}
static int F_27 ( struct V_5 * V_6 , void * V_29 )
{
struct V_44 * V_45 = F_28 ( V_6 ) ;
struct V_46 * V_30 = V_29 ;
T_4 V_47 = V_30 -> V_47 ;
T_4 V_48 = V_30 -> V_48 ;
if ( ( V_45 -> V_49 == V_47 ) &&
( V_45 -> V_50 == V_48 ) )
return 1 ;
return 0 ;
}
struct V_44 * F_29 ( T_4 V_47 , T_4 V_48 ,
struct V_44 * V_51 )
{
struct V_5 * V_6 ;
struct V_5 * V_52 = NULL ;
struct V_44 * V_45 = NULL ;
struct V_46 V_30 = {
. V_47 = V_47 ,
. V_48 = V_48
} ;
if ( V_51 )
V_52 = & V_51 -> V_5 ;
V_6 = F_30 ( & V_53 , V_52 , ( void * ) & V_30 ,
F_27 ) ;
if ( V_6 )
V_45 = F_28 ( V_6 ) ;
return V_45 ;
}
static void
F_31 ( struct V_54 * V_55 ,
struct V_56 * V_57 , int V_58 )
{
memset ( V_55 , 0 , sizeof( struct V_54 ) ) ;
memcpy ( & V_55 -> V_59 , V_57 , sizeof( struct V_56 ) ) ;
V_55 -> V_59 . V_60 = 0 ;
V_55 -> V_59 . V_61 = 0 ;
V_55 -> V_59 . V_62 = 0 ;
if ( V_58 < 0 ) {
V_55 -> V_59 . V_63 . V_64 = 1 ;
V_55 -> V_59 . V_65 = ( T_4 ) ( - V_58 ) ;
}
}
static int
F_32 ( struct V_56 * V_57 ,
int V_58 ,
enum V_66 V_67 )
{
struct V_54 V_68 ;
F_31 ( & V_68 , V_57 , V_58 ) ;
V_68 . V_69 . V_70 . V_67 = V_67 ;
return F_33 ( V_11 ,
V_71 , & V_68 ) ;
}
static int
F_34 ( struct V_54 * V_72 )
{
static int V_73 ;
enum V_66 V_67 = 0 ;
int V_74 = V_75 ;
int V_76 = 0 ;
F_35 ( V_77 , 0 , 0 , V_78 ) ;
if ( V_73 ) {
V_74 = - V_79 ;
V_76 = - V_80 ;
goto V_81;
}
V_73 = 1 ;
F_35 ( V_82 , 0 , 0 , V_78 ) ;
V_67 = V_72 -> V_69 . V_70 . V_67 &
V_83 ;
V_67 |= V_84 ;
V_81:
if ( V_72 -> V_59 . V_63 . V_85 )
V_76 = F_32 ( & V_72 -> V_59 , V_74 , V_67 ) ;
return V_76 ;
}
static int
F_36 ( struct V_56 * V_57 , int V_58 )
{
struct V_54 V_68 ;
F_31 ( & V_68 , V_57 , V_58 ) ;
if ( V_68 . V_59 . V_63 . V_86 == 1 )
return - V_15 ;
return F_33 ( V_11 ,
V_71 , & V_68 ) ;
}
static int F_37 (
struct V_56 * V_57 , int V_58 ,
struct V_87 V_88 )
{
struct V_54 V_68 ;
F_31 ( & V_68 , V_57 , V_58 ) ;
V_68 . V_69 . V_89 . V_88 = V_88 ;
V_68 . V_69 . V_89 . V_63 . V_90 = 1 ;
return F_33 ( V_11 ,
V_71 , & V_68 ) ;
}
static int
F_38 ( struct V_54 * V_55 , enum V_91 V_92 )
{
T_4 V_93 ;
T_5 V_94 ;
int V_95 ;
V_95 = F_5 ( V_11 ,
F_6 ( struct V_12 ,
V_96 ) ,
& V_94 , sizeof( T_5 ) ) ;
if ( V_95 ) {
F_35 ( V_97 , 0 , 0 ,
V_98 ) ;
return V_95 ;
}
if ( V_94 != V_99 ) {
F_35 ( V_100 , 0 ,
V_94 ,
V_98 ) ;
return - V_80 ;
}
V_95 = F_5 ( V_11 ,
F_6 ( struct V_12 ,
V_101 ) ,
& V_93 , sizeof( T_4 ) ) ;
if ( V_95 ) {
F_35 ( V_97 , 0 , 0 ,
V_98 ) ;
return V_95 ;
}
switch ( V_92 ) {
case V_102 :
V_93 += sizeof( struct V_54 ) ;
V_95 = F_9 ( V_11 ,
V_93 ,
V_55 ,
sizeof( struct V_54 ) ) ;
if ( V_95 ) {
F_35 ( V_103 , 0 , 0 ,
V_98 ) ;
return V_95 ;
}
break;
case V_104 :
V_95 = F_9 ( V_11 ,
V_93 ,
V_55 ,
sizeof( struct V_54 ) ) ;
if ( V_95 ) {
F_35 ( V_105 , 0 , 0 ,
V_98 ) ;
return V_95 ;
}
break;
default:
F_39 ( L_4 ) ;
break;
}
return 0 ;
}
static int
F_40 ( enum V_106 V_107 ,
struct V_56 * V_108 ,
int V_58 )
{
if ( ! V_108 )
return - V_80 ;
if ( V_108 -> V_30 != ( T_4 ) V_107 )
return - V_15 ;
return F_36 ( V_108 , V_58 ) ;
}
static int
F_41 ( enum V_106 V_107 ,
struct V_44 * V_109 , int V_58 ,
struct V_87 V_110 )
{
struct V_54 V_68 ;
T_4 V_47 = V_109 -> V_49 ;
T_4 V_48 = V_109 -> V_50 ;
if ( ! V_109 -> V_108 )
return - V_80 ;
if ( V_109 -> V_108 -> V_30 != V_107 )
return - V_15 ;
F_31 ( & V_68 , V_109 -> V_108 , V_58 ) ;
V_68 . V_69 . V_89 . V_47 = V_47 ;
V_68 . V_69 . V_89 . V_48 = V_48 ;
V_68 . V_69 . V_89 . V_88 = V_110 ;
return F_33 ( V_11 ,
V_71 , & V_68 ) ;
}
static int
F_42 ( enum V_106 V_107 ,
struct V_56 * V_108 ,
int V_58 )
{
if ( ! V_108 )
return - V_80 ;
if ( V_108 -> V_30 != ( T_4 ) V_107 )
return - V_15 ;
return F_36 ( V_108 , V_58 ) ;
}
static int
F_43 ( struct V_54 * V_72 )
{
struct V_111 * V_69 = & V_72 -> V_69 ;
struct V_56 * V_112 = NULL ;
T_4 V_47 = V_69 -> V_113 . V_47 ;
struct V_44 * V_114 ;
struct V_115 * V_115 ;
int V_95 ;
V_114 = F_29 ( V_47 , V_116 , NULL ) ;
if ( V_114 && ( V_114 -> V_88 . V_117 == 1 ) ) {
F_35 ( V_118 , 0 , V_47 ,
V_98 ) ;
V_95 = - V_119 ;
goto V_120;
}
V_114 = F_44 ( sizeof( * V_114 ) , V_40 ) ;
if ( ! V_114 ) {
F_35 ( V_118 , 0 , V_47 ,
V_98 ) ;
V_95 = - V_121 ;
goto V_120;
}
F_45 ( & V_114 -> V_122 ) ;
V_114 -> V_49 = V_47 ;
V_114 -> V_50 = V_116 ;
F_35 ( V_123 , 0 , V_47 , V_78 ) ;
if ( F_46 ( V_69 -> V_113 . V_124 , V_125 ) == 0 ) {
V_95 = F_38 ( V_72 , V_104 ) ;
if ( V_95 )
goto V_126;
}
if ( V_72 -> V_59 . V_63 . V_85 == 1 ) {
V_112 = F_44 ( sizeof( * V_112 ) ,
V_40 ) ;
if ( ! V_112 ) {
F_35 ( V_127 , V_69 ,
V_114 -> V_49 ,
V_98 ) ;
V_95 = - V_121 ;
goto V_126;
}
memcpy ( V_112 , & V_72 -> V_59 ,
sizeof( struct V_56 ) ) ;
V_114 -> V_108 = V_112 ;
}
V_115 = F_47 ( V_69 -> V_113 . V_128 ,
V_69 -> V_113 . V_129 ,
V_40 ,
V_69 -> V_113 . V_130 ) ;
if ( ! V_115 ) {
F_35 ( V_118 , 0 , V_47 ,
V_98 ) ;
V_95 = - V_121 ;
goto V_131;
}
V_114 -> V_115 = V_115 ;
F_48 ( V_114 ) ;
F_35 ( V_132 , 0 , V_47 , V_78 ) ;
return 0 ;
V_131:
F_23 ( V_114 -> V_108 ) ;
V_126:
F_23 ( V_114 ) ;
V_120:
if ( V_72 -> V_59 . V_63 . V_85 == 1 )
F_40 ( V_72 -> V_59 . V_30 , & V_72 -> V_59 , V_95 ) ;
return V_95 ;
}
static int
F_49 ( struct V_54 * V_72 )
{
struct V_111 * V_69 = & V_72 -> V_69 ;
struct V_56 * V_112 = NULL ;
T_4 V_47 = V_69 -> V_133 . V_47 ;
struct V_44 * V_114 ;
int V_95 ;
V_114 = F_29 ( V_47 , V_116 , NULL ) ;
if ( ! V_114 ) {
V_95 = - V_4 ;
goto V_120;
}
if ( V_114 -> V_88 . V_117 == 0 ) {
V_95 = - V_134 ;
goto V_120;
}
if ( V_114 -> V_108 ) {
V_95 = - V_119 ;
goto V_120;
}
if ( V_72 -> V_59 . V_63 . V_85 == 1 ) {
V_112 = F_44 ( sizeof( * V_112 ) , V_40 ) ;
if ( ! V_112 ) {
F_35 ( V_127 , V_69 ,
V_114 -> V_49 ,
V_98 ) ;
V_95 = - V_121 ;
goto V_120;
}
memcpy ( V_112 , & V_72 -> V_59 ,
sizeof( struct V_56 ) ) ;
V_114 -> V_108 = V_112 ;
}
F_50 ( V_114 ) ;
return 0 ;
V_120:
if ( V_72 -> V_59 . V_63 . V_85 == 1 )
F_40 ( V_72 -> V_59 . V_30 , & V_72 -> V_59 , V_95 ) ;
return V_95 ;
}
static int
F_51 ( struct V_54 * V_72 ,
struct V_25 * V_135 )
{
struct V_111 * V_69 = & V_72 -> V_69 ;
T_4 V_47 ;
struct V_44 * V_114 ;
int V_95 = 0 ;
V_47 = V_69 -> V_136 . V_47 ;
F_35 ( V_137 , 0 , V_47 ,
V_78 ) ;
V_114 = F_29 ( V_47 , V_116 , NULL ) ;
if ( ! V_114 ) {
F_35 ( V_138 , 0 , V_47 ,
V_98 ) ;
V_95 = - V_15 ;
goto V_120;
} else if ( V_114 -> V_88 . V_117 == 0 ) {
F_35 ( V_138 , 0 , V_47 ,
V_98 ) ;
V_95 = - V_15 ;
goto V_120;
} else if ( V_114 -> V_108 ) {
F_35 ( V_138 , 0 , V_47 ,
V_98 ) ;
V_95 = - V_80 ;
goto V_120;
}
V_95 = F_52
( V_114 -> V_115 ,
V_69 -> V_136 . V_139 ) ;
if ( V_95 )
goto V_120;
if ( V_135 ) {
V_114 -> V_140 = F_21 ( V_135 ) ;
V_114 -> V_141 = F_26 ( V_135 ) ;
}
F_35 ( V_142 , 0 , V_47 ,
V_78 ) ;
if ( V_72 -> V_59 . V_63 . V_85 == 1 )
F_40 ( V_72 -> V_59 . V_30 , & V_72 -> V_59 , V_95 ) ;
return 0 ;
V_120:
if ( V_72 -> V_59 . V_63 . V_85 == 1 )
F_40 ( V_72 -> V_59 . V_30 , & V_72 -> V_59 , V_95 ) ;
return V_95 ;
}
static int
F_53 ( struct V_54 * V_72 )
{
struct V_111 * V_69 = & V_72 -> V_69 ;
struct V_56 * V_112 = NULL ;
T_4 V_47 = V_69 -> V_143 . V_47 ;
T_4 V_48 = V_69 -> V_143 . V_48 ;
struct V_44 * V_144 = NULL ;
struct V_44 * V_114 ;
struct V_115 * V_115 ;
int V_95 ;
V_114 = F_29 ( V_47 , V_116 , NULL ) ;
if ( ! V_114 ) {
F_35 ( V_145 , V_48 , V_47 ,
V_98 ) ;
V_95 = - V_4 ;
goto V_120;
}
if ( V_114 -> V_88 . V_117 == 0 ) {
F_35 ( V_145 , V_48 , V_47 ,
V_98 ) ;
V_95 = - V_15 ;
goto V_120;
}
V_144 = F_29 ( V_47 , V_48 , NULL ) ;
if ( V_144 && ( V_144 -> V_88 . V_117 == 1 ) ) {
F_35 ( V_145 , V_48 , V_47 ,
V_98 ) ;
V_95 = - V_119 ;
goto V_120;
}
V_144 = F_44 ( sizeof( * V_144 ) , V_40 ) ;
if ( ! V_144 ) {
F_35 ( V_145 , V_48 , V_47 ,
V_98 ) ;
V_95 = - V_121 ;
goto V_120;
}
V_144 -> V_49 = V_47 ;
V_144 -> V_50 = V_48 ;
V_144 -> V_146 = V_69 -> V_143 . V_147 ;
V_144 -> V_5 . V_148 = & V_114 -> V_5 ;
F_35 ( V_149 , V_48 , V_47 ,
V_78 ) ;
V_115 =
F_54 ( V_69 -> V_143 . V_128 ,
V_69 -> V_143 . V_129 ,
V_40 ,
V_69 -> V_143 . V_150 ) ;
if ( ! V_115 ) {
F_35 ( V_145 , V_48 , V_47 ,
V_98 ) ;
V_95 = - V_121 ;
goto V_151;
}
V_144 -> V_115 = V_115 ;
V_144 -> V_152 = V_69 -> V_143 . V_150 ;
if ( F_46 ( V_69 -> V_143 . V_150 ,
V_153 ) == 0 ) {
V_95 = F_38 ( V_72 , V_102 ) ;
if ( V_95 )
goto V_151;
}
if ( V_72 -> V_59 . V_63 . V_85 == 1 ) {
V_112 = F_44 ( sizeof( * V_112 ) , V_40 ) ;
if ( ! V_112 ) {
V_95 = - V_121 ;
goto V_151;
}
memcpy ( V_112 , & V_72 -> V_59 ,
sizeof( struct V_56 ) ) ;
V_144 -> V_108 = V_112 ;
}
F_55 ( V_144 ) ;
F_35 ( V_154 , V_48 , V_47 ,
V_78 ) ;
return 0 ;
V_151:
F_23 ( V_144 ) ;
V_120:
if ( V_72 -> V_59 . V_63 . V_85 == 1 )
F_42 ( V_72 -> V_59 . V_30 , & V_72 -> V_59 , V_95 ) ;
return V_95 ;
}
static int
F_56 ( struct V_54 * V_72 )
{
struct V_111 * V_69 = & V_72 -> V_69 ;
struct V_56 * V_112 = NULL ;
T_4 V_47 = V_69 -> V_89 . V_47 ;
T_4 V_48 = V_69 -> V_89 . V_48 ;
struct V_87 V_88 = V_69 -> V_89 . V_88 ;
struct V_44 * V_144 ;
int V_95 ;
V_144 = F_29 ( V_47 , V_48 , NULL ) ;
if ( ! V_144 ) {
F_35 ( V_155 , V_48 , V_47 ,
V_98 ) ;
V_95 = - V_4 ;
goto V_120;
}
if ( V_144 -> V_88 . V_117 == 0 ) {
F_35 ( V_155 , V_48 , V_47 ,
V_98 ) ;
V_95 = - V_15 ;
goto V_120;
}
if ( V_144 -> V_108 ) {
V_95 = - V_80 ;
goto V_120;
}
if ( V_72 -> V_59 . V_63 . V_85 == 1 ) {
V_112 = F_44 ( sizeof( * V_112 ) , V_40 ) ;
if ( ! V_112 ) {
V_95 = - V_121 ;
goto V_120;
}
memcpy ( V_112 , & V_72 -> V_59 ,
sizeof( struct V_56 ) ) ;
V_144 -> V_108 = V_112 ;
}
if ( V_88 . V_156 == V_157 . V_156 &&
V_88 . V_158 == V_157 . V_158 )
F_57 ( V_144 ) ;
else if ( V_88 . V_156 == V_159 . V_156 &&
V_88 . V_158 == V_159 . V_158 )
F_58 ( V_144 ) ;
return 0 ;
V_120:
if ( V_72 -> V_59 . V_63 . V_85 == 1 )
F_42 ( V_72 -> V_59 . V_30 , & V_72 -> V_59 , V_95 ) ;
return V_95 ;
}
static int
F_59 ( struct V_54 * V_72 )
{
struct V_111 * V_69 = & V_72 -> V_69 ;
struct V_56 * V_112 = NULL ;
T_4 V_47 = V_69 -> V_160 . V_47 ;
T_4 V_48 = V_69 -> V_160 . V_48 ;
struct V_44 * V_144 ;
int V_95 ;
V_144 = F_29 ( V_47 , V_48 , NULL ) ;
if ( ! V_144 ) {
V_95 = - V_4 ;
goto V_120;
}
if ( V_144 -> V_88 . V_117 == 0 ) {
V_95 = - V_15 ;
goto V_120;
}
if ( V_144 -> V_108 ) {
V_95 = - V_80 ;
goto V_120;
}
if ( V_72 -> V_59 . V_63 . V_85 == 1 ) {
V_112 = F_44 ( sizeof( * V_112 ) , V_40 ) ;
if ( ! V_112 ) {
V_95 = - V_121 ;
goto V_120;
}
memcpy ( V_112 , & V_72 -> V_59 ,
sizeof( struct V_56 ) ) ;
V_144 -> V_108 = V_112 ;
}
F_60 ( V_144 ) ;
return 0 ;
V_120:
if ( V_72 -> V_59 . V_63 . V_85 == 1 )
F_42 ( V_72 -> V_59 . V_30 , & V_72 -> V_59 , V_95 ) ;
return V_95 ;
}
static int
F_61 ( void )
{
static T_7 V_30 = F_62 ( 0 ) ;
return F_63 ( & V_30 ) ;
}
static unsigned long
F_64 ( void )
{
return V_161 + F_65 ( V_162 ) ;
}
static struct V_163 *
F_66 ( struct V_54 * V_55 )
{
struct V_163 * V_164 ;
V_164 = F_25 ( sizeof( * V_164 ) , V_40 | V_41 ) ;
if ( ! V_164 )
return NULL ;
V_164 -> V_30 = F_61 () ;
V_164 -> V_165 = F_64 () ;
V_164 -> V_55 = * V_55 ;
return V_164 ;
}
static void
F_67 ( struct V_163 * V_164 )
{
F_23 ( V_164 ) ;
}
static int
F_68 ( int V_30 , T_5 V_166 )
{
struct V_167 * V_168 ;
struct V_167 * V_169 ;
F_69 ( & V_170 ) ;
F_70 (pos, tmp, &parahotplug_request_list) {
struct V_163 * V_164 =
F_71 ( V_168 , struct V_163 , V_171 ) ;
if ( V_164 -> V_30 == V_30 ) {
F_72 ( V_168 ) ;
F_73 ( & V_170 ) ;
V_164 -> V_55 . V_69 . V_89 . V_88 . V_166 = V_166 ;
if ( V_164 -> V_55 . V_59 . V_63 . V_85 )
F_37 (
& V_164 -> V_55 . V_59 , V_75 ,
V_164 -> V_55 . V_69 . V_89 . V_88 ) ;
F_67 ( V_164 ) ;
return 0 ;
}
}
F_73 ( & V_170 ) ;
return - V_15 ;
}
static T_1 F_74 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_3 V_13 )
{
unsigned int V_30 ;
int V_95 ;
if ( F_75 ( V_9 , 10 , & V_30 ) )
return - V_15 ;
V_95 = F_68 ( V_30 , 0 ) ;
if ( V_95 < 0 )
return V_95 ;
return V_13 ;
}
static T_1 F_76 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_3 V_13 )
{
unsigned int V_30 ;
if ( F_75 ( V_9 , 10 , & V_30 ) )
return - V_15 ;
F_68 ( V_30 , 1 ) ;
return V_13 ;
}
static void F_77 ( struct V_5 * V_6 )
{
}
static void
F_78 ( struct V_163 * V_164 )
{
struct V_111 * V_69 = & V_164 -> V_55 . V_69 ;
char V_172 [ 40 ] , V_173 [ 40 ] , V_174 [ 40 ] , V_175 [ 40 ] , V_176 [ 40 ] ,
V_177 [ 40 ] ;
char * V_178 [] = {
V_172 , V_173 , V_174 , V_175 , V_176 , V_177 , NULL
} ;
sprintf ( V_172 , L_5 ) ;
sprintf ( V_173 , L_6 , V_164 -> V_30 ) ;
sprintf ( V_174 , L_7 ,
V_69 -> V_89 . V_88 . V_166 ) ;
sprintf ( V_175 , L_8 ,
V_69 -> V_89 . V_47 ) ;
sprintf ( V_176 , L_9 ,
V_69 -> V_89 . V_48 >> 3 ) ;
sprintf ( V_177 , L_10 ,
V_69 -> V_89 . V_48 & 0x7 ) ;
F_79 ( & V_179 . V_6 . V_180 , V_181 ,
V_178 ) ;
}
static void
F_80 ( struct V_54 * V_72 )
{
struct V_163 * V_164 ;
V_164 = F_66 ( V_72 ) ;
if ( ! V_164 )
return;
if ( V_72 -> V_69 . V_89 . V_88 . V_166 ) {
F_78 ( V_164 ) ;
F_37
( & V_72 -> V_59 ,
V_75 ,
V_72 -> V_69 . V_89 . V_88 ) ;
F_67 ( V_164 ) ;
} else {
F_69 ( & V_170 ) ;
F_81 ( & V_164 -> V_171 , & V_182 ) ;
F_73 ( & V_170 ) ;
F_78 ( V_164 ) ;
}
}
static int
F_82 ( struct V_56 * V_57 )
{
F_83 ( & V_179 . V_6 . V_180 , V_183 ) ;
if ( V_57 -> V_63 . V_85 )
return F_36 ( V_57 , V_75 ) ;
return 0 ;
}
static int
F_84 ( struct V_56 * V_57 )
{
char V_184 [ 20 ] ;
char * V_178 [] = { V_184 , NULL } ;
sprintf ( V_184 , L_11 , 1 ) ;
F_79 ( & V_179 . V_6 . V_180 , V_181 ,
V_178 ) ;
if ( V_57 -> V_63 . V_85 )
return F_36 ( V_57 , V_75 ) ;
return 0 ;
}
static int
F_85 ( struct V_56 * V_57 )
{
F_83 ( & V_179 . V_6 . V_180 , V_185 ) ;
if ( V_57 -> V_63 . V_85 )
return F_36 ( V_57 , V_75 ) ;
return 0 ;
}
static inline unsigned int
F_86 ( T_8 * V_186 , T_4 * V_187 )
{
struct V_188 V_189 ;
int V_190 = V_191 ;
T_8 V_192 ;
V_192 = F_87 ( & V_189 ) ;
F_88 ( V_193 , V_192 , V_190 ) ;
if ( F_89 ( V_190 ) ) {
* V_186 = V_189 . V_194 ;
* V_187 = V_189 . V_129 ;
}
return V_190 ;
}
static T_8 F_90 ( void )
{
T_8 V_195 = 0 ;
T_4 V_196 = 0 ;
if ( ! F_89 ( F_86 ( & V_195 , & V_196 ) ) )
return 0 ;
return V_195 ;
}
static void
F_91 ( struct V_197 * V_198 )
{
struct V_54 V_199 ;
struct V_54 V_200 ;
struct V_54 V_55 ;
T_4 V_93 ;
T_5 V_94 ;
F_35 ( V_201 , 0 , 0 , V_78 ) ;
V_55 . V_59 . V_30 = V_202 ;
V_55 . V_69 . V_70 . V_203 = 23 ;
V_55 . V_69 . V_70 . V_204 = 0 ;
F_34 ( & V_55 ) ;
if ( F_5 ( V_11 ,
F_6 ( struct V_12 ,
V_96 ) ,
& V_94 , sizeof( T_5 ) ) < 0 ) {
F_35 ( V_97 , 0 , 0 ,
V_98 ) ;
return;
}
if ( V_94 != V_99 ) {
F_35 ( V_100 , 0 ,
V_94 ,
V_98 ) ;
return;
}
if ( F_5 ( V_11 ,
F_6 ( struct V_12 ,
V_101 ) ,
& V_93 , sizeof( T_4 ) ) < 0 ) {
F_35 ( V_97 , 0 , 0 ,
V_98 ) ;
return;
}
if ( F_5 ( V_11 ,
V_93 ,
& V_199 ,
sizeof( struct V_54 ) ) < 0 ) {
F_35 ( V_205 , 0 , 0 ,
V_98 ) ;
return;
}
if ( F_5 ( V_11 ,
V_93 +
sizeof( struct V_54 ) ,
& V_200 ,
sizeof( struct V_54 ) ) < 0 ) {
F_35 ( V_206 , 0 , 0 ,
V_98 ) ;
return;
}
if ( V_199 . V_69 . V_113 . V_128 ) {
F_43 ( & V_199 ) ;
} else {
F_35 ( V_207 , 0 , 0 ,
V_98 ) ;
return;
}
if ( V_200 . V_69 . V_143 . V_128 ) {
F_53 ( & V_200 ) ;
} else {
F_35 ( V_208 , 0 , 0 ,
V_98 ) ;
return;
}
F_35 ( V_209 , 0 , 0 , V_78 ) ;
}
void
F_92 ( struct V_44 * V_114 , int V_58 )
{
if ( V_58 >= 0 )
V_114 -> V_88 . V_117 = 1 ;
F_40 ( V_210 , V_114 -> V_108 ,
V_58 ) ;
F_23 ( V_114 -> V_108 ) ;
V_114 -> V_108 = NULL ;
}
void
F_93 ( struct V_44 * V_114 , int V_58 )
{
F_40 ( V_211 , V_114 -> V_108 ,
V_58 ) ;
F_23 ( V_114 -> V_108 ) ;
V_114 -> V_108 = NULL ;
}
void
F_94 ( struct V_44 * V_144 , int V_58 )
{
if ( V_58 >= 0 )
V_144 -> V_88 . V_117 = 1 ;
F_42 ( V_212 , V_144 -> V_108 ,
V_58 ) ;
F_23 ( V_144 -> V_108 ) ;
V_144 -> V_108 = NULL ;
}
void
F_95 ( struct V_44 * V_144 , int V_58 )
{
F_42 ( V_213 , V_144 -> V_108 ,
V_58 ) ;
F_23 ( V_144 -> V_108 ) ;
V_144 -> V_108 = NULL ;
}
void
F_96 ( struct V_44 * V_144 ,
int V_58 )
{
F_41 ( V_214 ,
V_144 , V_58 ,
V_159 ) ;
F_23 ( V_144 -> V_108 ) ;
V_144 -> V_108 = NULL ;
}
void
F_97 ( struct V_44 * V_144 , int V_58 )
{
F_41 ( V_214 ,
V_144 , V_58 ,
V_157 ) ;
F_23 ( V_144 -> V_108 ) ;
V_144 -> V_108 = NULL ;
}
static int
F_98 ( struct V_2 * V_2 , struct V_215 * V_216 )
{
unsigned long V_192 = 0 ;
unsigned long V_217 = V_216 -> V_218 << V_219 ;
T_8 V_195 = 0 ;
if ( V_217 & ( V_220 - 1 ) )
return - V_221 ;
switch ( V_217 ) {
case V_222 :
V_216 -> V_223 |= V_224 ;
if ( ! * V_225 )
return - V_221 ;
F_5
( * V_225 ,
F_6 ( struct V_12 ,
V_226 ) ,
& V_195 , sizeof( V_195 ) ) ;
if ( ! V_195 )
return - V_221 ;
V_192 = ( unsigned long ) V_195 ;
if ( F_99 ( V_216 , V_216 -> V_227 ,
V_192 >> V_219 ,
V_216 -> V_228 - V_216 -> V_227 ,
( V_216 -> V_229 ) ) ) {
return - V_230 ;
}
break;
default:
return - V_221 ;
}
return 0 ;
}
static inline T_9 F_100 ( void )
{
T_8 V_190 = V_191 ;
T_8 V_192 = 0 ;
F_88 ( V_231 , V_192 ,
V_190 ) ;
return V_190 ;
}
static inline int F_101 ( T_8 V_232 )
{
int V_190 = V_191 ;
F_88 ( V_233 , V_232 , V_190 ) ;
return V_190 ;
}
static long F_102 ( struct V_2 * V_2 , unsigned int V_69 ,
unsigned long V_234 )
{
T_8 V_232 ;
T_9 V_235 ;
switch ( V_69 ) {
case V_231 :
V_235 = F_100 () ;
if ( F_103 ( ( void V_236 * ) V_234 , & V_235 ,
sizeof( V_235 ) ) ) {
return - V_237 ;
}
return 0 ;
case V_233 :
if ( F_104 ( & V_232 , ( void V_236 * ) V_234 ,
sizeof( V_232 ) ) ) {
return - V_237 ;
}
return F_101 ( V_232 ) ;
default:
return - V_237 ;
}
}
static int
F_105 ( T_10 V_238 , struct V_115 * * V_11 )
{
int V_74 = 0 ;
V_225 = V_11 ;
F_106 ( & V_239 , & V_240 ) ;
V_239 . V_241 = V_242 ;
if ( F_107 ( V_238 ) == 0 ) {
V_74 = F_108 ( & V_238 , 0 , 1 , L_12 ) ;
if ( V_74 < 0 )
return V_74 ;
} else {
V_74 = F_109 ( V_238 , 1 , L_12 ) ;
if ( V_74 < 0 )
return V_74 ;
}
V_74 = F_110 ( & V_239 , F_111 ( F_107 ( V_238 ) , 0 ) , 1 ) ;
if ( V_74 < 0 ) {
F_112 ( V_238 , 1 ) ;
return V_74 ;
}
return 0 ;
}
static void
F_113 ( T_10 V_238 )
{
if ( V_239 . V_243 )
F_114 ( & V_239 ) ;
V_239 . V_243 = NULL ;
F_112 ( V_238 , 1 ) ;
}
static struct V_25 *
F_115 ( T_8 V_195 , T_4 V_244 , bool V_245 , bool * V_246 )
{
int V_247 = sizeof( struct V_25 ) + V_244 ;
struct V_25 * V_26 ;
* V_246 = false ;
V_247 ++ ;
if ( ( V_31 + V_244 )
> V_248 ) {
* V_246 = true ;
return NULL ;
}
V_26 = F_44 ( V_247 , V_40 | V_41 ) ;
if ( ! V_26 ) {
* V_246 = true ;
return NULL ;
}
V_26 -> V_247 = V_247 ;
V_26 -> V_32 = V_244 ;
V_26 -> V_38 = NULL ;
V_26 -> V_39 = 0 ;
V_26 -> V_249 = false ;
if ( V_245 ) {
void * V_109 ;
if ( V_195 > F_87 ( V_250 - 1 ) )
goto V_251;
V_109 = F_116 ( ( unsigned long ) ( V_195 ) ) ;
memcpy ( V_26 -> V_29 , V_109 , V_244 ) ;
} else {
void * V_252 = F_117 ( V_195 , V_244 , V_253 ) ;
if ( ! V_252 )
goto V_251;
memcpy ( V_26 -> V_29 , V_252 , V_244 ) ;
F_118 ( V_252 ) ;
}
V_26 -> V_249 = true ;
V_31 += V_26 -> V_32 ;
return V_26 ;
V_251:
F_22 ( V_26 ) ;
return NULL ;
}
static bool
F_119 ( struct V_54 V_72 , T_8 V_128 )
{
struct V_111 * V_69 = & V_72 . V_69 ;
T_8 V_254 ;
T_4 V_255 ;
struct V_25 * V_135 = NULL ;
bool V_256 ;
struct V_54 V_257 ;
V_256 = ( V_72 . V_59 . V_63 . V_86 == 1 ) ;
if ( V_128 == 0 )
return true ;
V_254 = V_128 + V_72 . V_59 . V_61 ;
V_255 = V_72 . V_59 . V_60 ;
if ( V_254 && V_255 ) {
bool V_246 = false ;
V_135 =
F_115 ( V_254 , V_255 ,
V_256 , & V_246 ) ;
if ( ! V_135 && V_246 )
return false ;
}
if ( ! V_256 ) {
F_31 ( & V_257 , & V_72 . V_59 ,
V_75 ) ;
if ( V_11 )
F_33 ( V_11 ,
V_258 ,
& V_257 ) ;
}
switch ( V_72 . V_59 . V_30 ) {
case V_202 :
F_34 ( & V_72 ) ;
break;
case V_210 :
F_43 ( & V_72 ) ;
break;
case V_211 :
F_49 ( & V_72 ) ;
break;
case V_259 :
F_51 ( & V_72 , V_135 ) ;
break;
case V_212 :
F_53 ( & V_72 ) ;
break;
case V_214 :
if ( V_69 -> V_89 . V_63 . V_90 ) {
F_80 ( & V_72 ) ;
} else {
F_56 ( & V_72 ) ;
break;
}
break;
case V_213 :
F_59 ( & V_72 ) ;
break;
case V_260 :
if ( V_72 . V_59 . V_63 . V_85 )
F_36 ( & V_72 . V_59 , V_75 ) ;
break;
case V_261 :
F_82 ( & V_72 . V_59 ) ;
break;
case V_262 :
F_84 ( & V_72 . V_59 ) ;
break;
case V_263 :
F_85 ( & V_72 . V_59 ) ;
break;
default:
if ( V_72 . V_59 . V_63 . V_85 )
F_36
( & V_72 . V_59 , - V_264 ) ;
break;
}
if ( V_135 ) {
F_22 ( V_135 ) ;
V_135 = NULL ;
}
return true ;
}
static bool
F_120 ( struct V_54 * V_55 )
{
if ( ! F_121 ( V_11 ,
V_265 , V_55 ) ) {
if ( V_55 -> V_59 . V_63 . V_86 == 1 )
return false ;
return true ;
}
return false ;
}
static void
F_122 ( void )
{
struct V_167 * V_168 ;
struct V_167 * V_169 ;
F_69 ( & V_170 ) ;
F_70 (pos, tmp, &parahotplug_request_list) {
struct V_163 * V_164 =
F_71 ( V_168 , struct V_163 , V_171 ) ;
if ( ! F_123 ( V_161 , V_164 -> V_165 ) )
continue;
F_72 ( V_168 ) ;
if ( V_164 -> V_55 . V_59 . V_63 . V_85 )
F_37 (
& V_164 -> V_55 . V_59 ,
V_266 ,
V_164 -> V_55 . V_69 . V_89 . V_88 ) ;
F_67 ( V_164 ) ;
}
F_73 ( & V_170 ) ;
}
static void
F_124 ( struct V_197 * V_198 )
{
struct V_54 V_72 ;
bool V_267 = false ;
bool V_268 = false ;
while ( ! F_121 ( V_11 ,
V_269 ,
& V_72 ) )
;
if ( ! V_267 ) {
if ( V_270 ) {
V_72 = V_271 ;
V_270 = false ;
V_267 = true ;
} else {
V_267 = F_120 ( & V_72 ) ;
}
}
V_268 = false ;
while ( V_267 && ( ! V_268 ) ) {
V_272 = V_161 ;
if ( F_119 ( V_72 ,
F_125
( V_11 ) ) )
V_267 = F_120 ( & V_72 ) ;
else {
V_268 = true ;
V_271 = V_72 ;
V_270 = true ;
}
}
F_122 () ;
if ( F_126 ( V_161 ,
V_272 + ( V_273 * V_274 ) ) ) {
if ( V_275 != V_276 )
V_275 = V_276 ;
} else {
if ( V_275 != V_277 )
V_275 = V_277 ;
}
F_127 ( & V_278 , V_275 ) ;
}
static int
F_128 ( struct V_279 * V_279 )
{
int V_95 = - V_4 ;
T_8 V_195 ;
T_6 V_280 = V_281 ;
V_195 = F_90 () ;
if ( ! V_195 )
goto error;
V_11 = F_54 ( V_195 , 0 ,
V_40 , V_280 ) ;
if ( ! V_11 )
goto error;
if ( ! F_129 (
F_130 ( V_11 ) ) )
goto V_282;
V_238 = F_111 ( V_283 , 0 ) ;
V_95 = F_105 ( V_238 , & V_11 ) ;
if ( V_95 < 0 )
goto V_282;
if ( F_131 () )
F_132 ( & V_278 ,
F_91 ) ;
else
F_132 ( & V_278 ,
F_124 ) ;
V_272 = V_161 ;
V_275 = V_277 ;
F_127 ( & V_278 , V_275 ) ;
V_179 . V_6 . V_284 = V_238 ;
if ( F_133 ( & V_179 ) < 0 ) {
F_35 ( V_285 , 0 , 0 ,
V_98 ) ;
V_95 = - V_4 ;
goto V_286;
}
F_35 ( V_287 , 0 , 0 , V_78 ) ;
V_95 = F_134 () ;
if ( V_95 < 0 )
goto V_288;
return 0 ;
V_288:
F_135 ( & V_179 ) ;
V_286:
F_136 ( & V_278 ) ;
F_113 ( V_238 ) ;
V_282:
F_137 ( V_11 ) ;
error:
F_35 ( V_289 , 0 , V_95 , V_98 ) ;
return V_95 ;
}
static int
F_138 ( struct V_279 * V_279 )
{
F_35 ( V_290 , 0 , 0 , V_78 ) ;
F_139 () ;
F_136 ( & V_278 ) ;
F_137 ( V_11 ) ;
F_113 ( V_179 . V_6 . V_284 ) ;
F_135 ( & V_179 ) ;
F_35 ( V_290 , 0 , 0 , V_78 ) ;
return 0 ;
}
static T_11 T_12 F_140 ( void )
{
unsigned int V_291 , V_292 , V_293 , V_294 ;
if ( F_141 ( V_295 ) ) {
F_142 ( V_296 , & V_291 , & V_292 , & V_293 , & V_294 ) ;
return ( V_292 == V_297 ) &&
( V_293 == V_298 ) &&
( V_294 == V_299 ) ;
} else {
return 0 ;
}
}
static int F_143 ( void )
{
int V_190 ;
if ( ! F_140 () )
return - V_4 ;
V_190 = F_144 ( & V_300 ) ;
if ( V_190 )
return - V_4 ;
F_39 ( L_13 ) ;
return 0 ;
}
static void F_145 ( void )
{
F_146 ( & V_300 ) ;
}
