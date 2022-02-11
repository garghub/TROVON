static void F_1 ( struct V_1 * V_2 )
{
static bool V_3 ;
if ( V_3 )
return;
V_3 = true ;
F_2 ( V_4 , V_2 -> V_5 ) ;
F_2 ( V_6 , V_2 -> V_7 ) ;
F_2 ( V_8 , V_2 -> V_9 ) ;
F_2 ( V_10 , V_2 -> V_11 ) ;
F_2 ( V_12 , V_2 -> V_13 ) ;
F_2 ( V_14 , V_15 ) ;
}
static int F_3 ( struct V_16 * V_17 , unsigned long V_18 ,
void * args )
{
struct V_1 * V_2 ;
V_2 = F_4 () ;
F_1 ( V_2 ) ;
return V_19 ;
}
static int F_5 ( struct V_16 * V_17 , unsigned long V_18 ,
void * args )
{
struct V_20 * V_21 = (struct V_20 * ) args ;
struct V_1 * V_2 = V_21 -> V_2 ;
F_1 ( V_2 ) ;
return V_19 ;
}
static int F_6 ( void )
{
if ( V_22 == NULL )
return - V_23 ;
return 0 ;
}
static void F_7 ( struct V_24 * V_25 , char * V_26 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 += 2 )
sprintf ( & V_26 [ V_27 ] , L_1 , V_25 -> V_29 . V_30 [ V_27 / 2 ] ) ;
}
static T_1 F_8 ( struct V_31 * V_32 )
{
return ( T_1 ) V_32 -> V_33 . V_34 / 32 ;
}
static T_1 F_9 ( struct V_31 * V_32 )
{
return ( T_1 ) V_32 -> V_33 . V_34 % 32 ;
}
static T_2 F_10 ( struct V_31 * V_32 ,
struct V_35 * V_36 )
{
T_1 V_37 = F_8 ( V_32 ) ;
return V_36 -> V_38 [ V_37 ] . V_39 ;
}
static T_2 F_11 ( struct V_31 * V_32 ,
struct V_35 * V_36 )
{
T_1 V_37 = F_8 ( V_32 ) ;
T_1 V_40 = F_9 ( V_32 ) ;
return V_36 -> V_41 [ V_37 ] [ V_40 ] ;
}
static T_2 F_12 ( struct V_31 * V_32 ,
struct V_35 * V_36 )
{
T_1 V_37 = F_8 ( V_32 ) ;
T_1 V_40 = F_9 ( V_32 ) ;
return V_36 -> V_42 [ V_37 ] [ V_40 ] . V_43 . V_44 . V_45 ;
}
static T_3 F_13 ( struct V_46 * V_47 , struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
if ( ! V_25 -> V_32 )
return - V_23 ;
return sprintf ( V_50 , L_2 , V_25 -> V_32 -> V_33 . V_51 ) ;
}
static T_3 F_15 ( struct V_46 * V_47 , struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
if ( ! V_25 -> V_32 )
return - V_23 ;
return sprintf ( V_50 , L_2 , V_25 -> V_32 -> V_52 ) ;
}
static T_3 F_16 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
if ( ! V_25 -> V_32 )
return - V_23 ;
return sprintf ( V_50 , L_2 , V_25 -> V_32 -> V_33 . V_34 ) ;
}
static T_3 F_17 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
if ( ! V_25 -> V_32 )
return - V_23 ;
return sprintf ( V_50 , L_3 ,
V_25 -> V_32 -> V_33 . V_53 . V_54 . V_30 ) ;
}
static T_3 F_18 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
if ( ! V_25 -> V_32 )
return - V_23 ;
return sprintf ( V_50 , L_3 ,
V_25 -> V_32 -> V_33 . V_53 . V_55 . V_30 ) ;
}
static T_3 F_19 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
char V_26 [ V_28 + 1 ] ;
F_7 ( V_25 , V_26 ) ;
return sprintf ( V_50 , L_4 , V_26 ) ;
}
static T_3 F_20 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
if ( ! V_25 -> V_32 )
return - V_23 ;
return sprintf ( V_50 , L_2 ,
F_10 ( V_25 -> V_32 ,
V_56 . V_57 [ 1 ] ) ) ;
}
static T_3 F_21 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
if ( ! V_25 -> V_32 )
return - V_23 ;
return sprintf ( V_50 , L_2 ,
F_10 ( V_25 -> V_32 ,
V_56 . V_57 [ 1 ] ) ) ;
}
static T_3 F_22 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
if ( ! V_25 -> V_32 )
return - V_23 ;
return sprintf ( V_50 , L_2 ,
F_11 ( V_25 -> V_32 ,
V_56 . V_57 [ 0 ] ) ) ;
}
static T_3 F_23 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
if ( ! V_25 -> V_32 )
return - V_23 ;
return sprintf ( V_50 , L_2 ,
F_11 ( V_25 -> V_32 ,
V_56 . V_57 [ 1 ] ) ) ;
}
static T_3 F_24 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
if ( ! V_25 -> V_32 )
return - V_23 ;
return sprintf ( V_50 , L_2 ,
F_12 ( V_25 -> V_32 ,
V_56 . V_57 [ 0 ] ) ) ;
}
static T_3 F_25 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
if ( ! V_25 -> V_32 )
return - V_23 ;
return sprintf ( V_50 , L_2 ,
F_12 ( V_25 -> V_32 ,
V_56 . V_57 [ 1 ] ) ) ;
}
static T_3 F_26 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
struct V_58 V_59 ;
if ( ! V_25 -> V_32 )
return - V_23 ;
F_27 ( & V_25 -> V_32 -> V_59 , & V_59 ) ;
return sprintf ( V_50 , L_2 , V_59 . V_60 ) ;
}
static T_3 F_28 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
struct V_58 V_59 ;
if ( ! V_25 -> V_32 )
return - V_23 ;
F_27 ( & V_25 -> V_32 -> V_59 , & V_59 ) ;
return sprintf ( V_50 , L_2 , V_59 . V_61 ) ;
}
static T_3 F_29 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
struct V_58 V_59 ;
if ( ! V_25 -> V_32 )
return - V_23 ;
F_27 ( & V_25 -> V_32 -> V_59 , & V_59 ) ;
return sprintf ( V_50 , L_2 , V_59 . V_62 ) ;
}
static T_3 F_30 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
struct V_58 V_59 ;
if ( ! V_25 -> V_32 )
return - V_23 ;
F_27 ( & V_25 -> V_32 -> V_59 , & V_59 ) ;
return sprintf ( V_50 , L_2 , V_59 . V_63 ) ;
}
static T_3 F_31 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
struct V_58 V_59 ;
if ( ! V_25 -> V_32 )
return - V_23 ;
F_27 ( & V_25 -> V_32 -> V_59 , & V_59 ) ;
return sprintf ( V_50 , L_2 , V_59 . V_64 ) ;
}
static T_3 F_32 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
struct V_58 V_65 ;
if ( ! V_25 -> V_32 )
return - V_23 ;
F_27 ( & V_25 -> V_32 -> V_65 , & V_65 ) ;
return sprintf ( V_50 , L_2 , V_65 . V_60 ) ;
}
static T_3 F_33 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
struct V_58 V_65 ;
if ( ! V_25 -> V_32 )
return - V_23 ;
F_27 ( & V_25 -> V_32 -> V_65 , & V_65 ) ;
return sprintf ( V_50 , L_2 , V_65 . V_61 ) ;
}
static T_3 F_34 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
struct V_58 V_65 ;
if ( ! V_25 -> V_32 )
return - V_23 ;
F_27 ( & V_25 -> V_32 -> V_65 , & V_65 ) ;
return sprintf ( V_50 , L_2 , V_65 . V_62 ) ;
}
static T_3 F_35 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
struct V_58 V_65 ;
if ( ! V_25 -> V_32 )
return - V_23 ;
F_27 ( & V_25 -> V_32 -> V_65 , & V_65 ) ;
return sprintf ( V_50 , L_2 , V_65 . V_63 ) ;
}
static T_3 F_36 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
struct V_58 V_65 ;
if ( ! V_25 -> V_32 )
return - V_23 ;
F_27 ( & V_25 -> V_32 -> V_65 , & V_65 ) ;
return sprintf ( V_50 , L_2 , V_65 . V_64 ) ;
}
static T_3 F_37 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
struct V_31 * V_32 = V_25 -> V_32 , * V_66 ;
unsigned long V_67 ;
int V_68 = V_69 , V_70 , V_71 ;
struct V_72 * V_73 ;
if ( ! V_32 )
return - V_23 ;
V_71 = snprintf ( V_50 , V_68 , L_5 ,
V_32 -> V_33 . V_51 , V_32 -> V_74 ) ;
F_38 ( & V_32 -> V_75 , V_67 ) ;
F_39 (cur, &channel->sc_list) {
if ( V_71 >= V_68 - 1 )
break;
V_66 = F_40 ( V_73 , struct V_31 , V_76 ) ;
V_70 = F_41 ( V_50 + V_71 ,
V_68 - V_71 ,
L_5 ,
V_66 -> V_33 . V_51 ,
V_66 -> V_74 ) ;
V_71 += V_70 ;
}
F_42 ( & V_32 -> V_75 , V_67 ) ;
return V_71 ;
}
static T_3 F_43 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
return sprintf ( V_50 , L_6 , V_25 -> V_77 ) ;
}
static T_3 F_44 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
return sprintf ( V_50 , L_6 , V_25 -> V_78 ) ;
}
static int F_45 ( struct V_46 * V_46 , struct V_79 * V_80 )
{
struct V_24 * V_47 = F_14 ( V_46 ) ;
int V_81 ;
char V_26 [ V_28 + 1 ] ;
F_7 ( V_47 , V_26 ) ;
V_81 = F_46 ( V_80 , L_7 , V_26 ) ;
return V_81 ;
}
static inline bool F_47 ( const T_4 * V_82 )
{
if ( F_48 ( * V_82 , V_83 ) )
return false ;
return true ;
}
static const struct V_84 * F_49 ( struct V_85 * V_86 ,
const T_4 * V_82 )
{
const struct V_84 * V_45 = NULL ;
struct V_87 * V_88 ;
F_50 ( & V_86 -> V_89 . V_75 ) ;
F_51 (dynid, &drv->dynids.list, node) {
if ( ! F_48 ( V_88 -> V_45 . V_82 , * V_82 ) ) {
V_45 = & V_88 -> V_45 ;
break;
}
}
F_52 ( & V_86 -> V_89 . V_75 ) ;
if ( V_45 )
return V_45 ;
V_45 = V_86 -> V_90 ;
if ( V_45 == NULL )
return NULL ;
for (; ! F_47 ( & V_45 -> V_82 ) ; V_45 ++ )
if ( ! F_48 ( V_45 -> V_82 , * V_82 ) )
return V_45 ;
return NULL ;
}
static int F_53 ( struct V_85 * V_86 , T_4 * V_82 )
{
struct V_87 * V_88 ;
V_88 = F_54 ( sizeof( * V_88 ) , V_91 ) ;
if ( ! V_88 )
return - V_92 ;
V_88 -> V_45 . V_82 = * V_82 ;
F_50 ( & V_86 -> V_89 . V_75 ) ;
F_55 ( & V_88 -> V_93 , & V_86 -> V_89 . V_94 ) ;
F_52 ( & V_86 -> V_89 . V_75 ) ;
return F_56 ( & V_86 -> V_95 ) ;
}
static void F_57 ( struct V_85 * V_86 )
{
struct V_87 * V_88 , * V_96 ;
F_50 ( & V_86 -> V_89 . V_75 ) ;
F_58 (dynid, n, &drv->dynids.list, node) {
F_59 ( & V_88 -> V_93 ) ;
F_60 ( V_88 ) ;
}
F_52 ( & V_86 -> V_89 . V_75 ) ;
}
static int F_61 ( const char * V_97 , T_4 * V_98 )
{
unsigned int V_30 [ 16 ] ;
int V_27 ;
if ( strlen ( V_97 ) < 37 )
return - 1 ;
for ( V_27 = 0 ; V_27 < 36 ; V_27 ++ ) {
switch ( V_27 ) {
case 8 : case 13 : case 18 : case 23 :
if ( V_97 [ V_27 ] != '-' )
return - 1 ;
break;
default:
if ( ! isxdigit ( V_97 [ V_27 ] ) )
return - 1 ;
}
}
if ( sscanf ( V_97 ,
L_8 ,
& V_30 [ 3 ] , & V_30 [ 2 ] , & V_30 [ 1 ] , & V_30 [ 0 ] ,
& V_30 [ 5 ] , & V_30 [ 4 ] , & V_30 [ 7 ] , & V_30 [ 6 ] , & V_30 [ 8 ] , & V_30 [ 9 ] ,
& V_30 [ 10 ] , & V_30 [ 11 ] , & V_30 [ 12 ] , & V_30 [ 13 ] , & V_30 [ 14 ] , & V_30 [ 15 ] ) != 16 )
return - 1 ;
for ( V_27 = 0 ; V_27 < 16 ; V_27 ++ )
V_98 -> V_30 [ V_27 ] = V_30 [ V_27 ] ;
return 0 ;
}
static T_3 F_62 ( struct V_99 * V_95 , const char * V_50 ,
T_5 V_100 )
{
struct V_85 * V_86 = F_63 ( V_95 ) ;
T_4 V_82 = V_101 ;
T_3 V_102 ;
if ( F_61 ( V_50 , & V_82 ) != 0 )
return - V_103 ;
if ( F_49 ( V_86 , & V_82 ) )
return - V_104 ;
V_102 = F_53 ( V_86 , & V_82 ) ;
if ( V_102 )
return V_102 ;
return V_100 ;
}
static T_3 F_64 ( struct V_99 * V_95 , const char * V_50 ,
T_5 V_100 )
{
struct V_85 * V_86 = F_63 ( V_95 ) ;
struct V_87 * V_88 , * V_96 ;
T_4 V_82 = V_101 ;
T_5 V_102 = - V_23 ;
if ( F_61 ( V_50 , & V_82 ) )
return - V_103 ;
F_50 ( & V_86 -> V_89 . V_75 ) ;
F_58 (dynid, n, &drv->dynids.list, node) {
struct V_84 * V_45 = & V_88 -> V_45 ;
if ( ! F_48 ( V_45 -> V_82 , V_82 ) ) {
F_59 ( & V_88 -> V_93 ) ;
F_60 ( V_88 ) ;
V_102 = V_100 ;
break;
}
}
F_52 ( & V_86 -> V_89 . V_75 ) ;
return V_102 ;
}
static int F_65 ( struct V_46 * V_46 , struct V_99 * V_95 )
{
struct V_85 * V_86 = F_63 ( V_95 ) ;
struct V_24 * V_25 = F_14 ( V_46 ) ;
if ( F_66 ( V_25 -> V_32 ) )
return V_86 -> V_105 ;
if ( F_49 ( V_86 , & V_25 -> V_29 ) )
return 1 ;
return 0 ;
}
static int F_67 ( struct V_46 * V_106 )
{
int V_81 = 0 ;
struct V_85 * V_86 =
F_63 ( V_106 -> V_95 ) ;
struct V_24 * V_47 = F_14 ( V_106 ) ;
const struct V_84 * V_107 ;
V_107 = F_49 ( V_86 , & V_47 -> V_29 ) ;
if ( V_86 -> V_108 ) {
V_81 = V_86 -> V_108 ( V_47 , V_107 ) ;
if ( V_81 != 0 )
F_68 ( L_9 ,
F_69 ( V_106 ) , V_81 ) ;
} else {
F_68 ( L_10 ,
F_69 ( V_106 ) ) ;
V_81 = - V_23 ;
}
return V_81 ;
}
static int F_70 ( struct V_46 * V_106 )
{
struct V_85 * V_86 ;
struct V_24 * V_47 = F_14 ( V_106 ) ;
if ( V_106 -> V_95 ) {
V_86 = F_63 ( V_106 -> V_95 ) ;
if ( V_86 -> remove )
V_86 -> remove ( V_47 ) ;
}
return 0 ;
}
static void F_71 ( struct V_46 * V_106 )
{
struct V_85 * V_86 ;
struct V_24 * V_47 = F_14 ( V_106 ) ;
if ( ! V_106 -> V_95 )
return;
V_86 = F_63 ( V_106 -> V_95 ) ;
if ( V_86 -> V_109 )
V_86 -> V_109 ( V_47 ) ;
return;
}
static void F_72 ( struct V_46 * V_46 )
{
struct V_24 * V_25 = F_14 ( V_46 ) ;
struct V_31 * V_32 = V_25 -> V_32 ;
F_73 ( V_32 ,
V_32 -> V_33 . V_51 ) ;
F_60 ( V_25 ) ;
}
static void F_74 ( struct V_110 * V_111 )
{
struct V_112 * V_113 ;
if ( V_56 . V_114 == V_115 )
return;
V_113 = F_75 ( V_111 , struct V_112 ,
V_111 ) ;
F_76 ( & V_113 -> V_116 ) ;
F_60 ( V_113 ) ;
}
static void F_77 ( struct V_117 * V_116 , int V_118 )
{
struct V_119 * V_47 = V_120 . V_121 [ V_118 ] ;
if ( V_47 -> V_122 )
V_47 -> V_122 ( V_47 ) ;
F_78 ( V_116 , V_123 ) ;
}
void F_79 ( unsigned long V_124 )
{
int V_118 = F_80 () ;
void * V_125 = V_120 . V_126 [ V_118 ] ;
struct V_117 * V_116 = (struct V_117 * ) V_125 +
V_127 ;
struct V_128 * V_129 ;
struct V_130 * V_131 ;
struct V_112 * V_113 ;
T_2 V_132 = V_116 -> V_133 . V_132 ;
if ( V_132 == V_134 )
return;
V_129 = (struct V_128 * ) V_116 -> V_44 . V_135 ;
if ( V_129 -> V_136 >= V_137 ) {
F_81 ( 1 , L_11 , V_129 -> V_136 ) ;
goto V_138;
}
V_131 = & V_139 [ V_129 -> V_136 ] ;
if ( V_131 -> V_140 == V_141 ) {
V_113 = F_82 ( sizeof( * V_113 ) , V_142 ) ;
if ( V_113 == NULL )
return;
F_83 ( & V_113 -> V_111 , F_74 ) ;
memcpy ( & V_113 -> V_116 , V_116 , sizeof( * V_116 ) ) ;
F_84 ( V_56 . V_143 , & V_113 -> V_111 ) ;
} else
V_131 -> V_144 ( V_129 ) ;
V_138:
F_78 ( V_116 , V_132 ) ;
}
static void F_85 ( void )
{
int V_118 = F_80 () ;
void * V_125 ;
struct V_117 * V_116 ;
union V_145 * V_146 ;
bool V_147 = false ;
V_125 = V_120 . V_148 [ V_118 ] ;
if ( V_125 == NULL )
return;
V_146 = (union V_145 * ) V_125 +
V_127 ;
if ( ( V_149 == V_150 ) ||
( V_149 == V_151 ) ) {
if ( F_86 ( 0 ,
( unsigned long * ) & V_146 -> V_152 [ 0 ] ) ) {
V_147 = true ;
}
} else {
V_147 = true ;
}
if ( V_147 )
F_87 ( V_120 . V_153 [ V_118 ] ) ;
V_125 = V_120 . V_126 [ V_118 ] ;
V_116 = (struct V_117 * ) V_125 + V_127 ;
if ( V_116 -> V_133 . V_132 != V_134 ) {
if ( V_116 -> V_133 . V_132 == V_123 )
F_77 ( V_116 , V_118 ) ;
else
F_87 ( V_120 . V_154 [ V_118 ] ) ;
}
F_88 ( V_155 , 0 ) ;
}
static int F_89 ( void )
{
int V_81 ;
V_81 = F_90 () ;
if ( V_81 != 0 ) {
F_68 ( L_12 , V_81 ) ;
return V_81 ;
}
V_81 = F_91 ( & V_156 ) ;
if ( V_81 )
goto V_157;
F_92 ( F_85 ) ;
V_81 = F_93 () ;
if ( V_81 )
goto V_158;
F_94 ( V_159 , NULL , 1 ) ;
V_81 = F_95 () ;
if ( V_81 )
goto V_160;
if ( V_149 > V_151 )
F_96 () ;
if ( V_161 . V_162 & V_163 ) {
F_97 ( & V_164 ) ;
F_98 ( & V_165 ,
& V_166 ) ;
}
F_99 () ;
return 0 ;
V_160:
F_94 ( V_167 , NULL , 1 ) ;
V_158:
F_100 () ;
F_101 () ;
F_102 ( & V_156 ) ;
V_157:
F_103 ( false ) ;
return V_81 ;
}
int F_104 ( struct V_85 * V_85 , struct V_168 * V_169 , const char * V_170 )
{
int V_81 ;
F_105 ( L_13 , V_85 -> V_171 ) ;
V_81 = F_6 () ;
if ( V_81 < 0 )
return V_81 ;
V_85 -> V_95 . V_171 = V_85 -> V_171 ;
V_85 -> V_95 . V_169 = V_169 ;
V_85 -> V_95 . V_170 = V_170 ;
V_85 -> V_95 . V_172 = & V_156 ;
F_106 ( & V_85 -> V_89 . V_75 ) ;
F_107 ( & V_85 -> V_89 . V_94 ) ;
V_81 = F_108 ( & V_85 -> V_95 ) ;
return V_81 ;
}
void F_109 ( struct V_85 * V_85 )
{
F_105 ( L_14 , V_85 -> V_171 ) ;
if ( ! F_6 () ) {
F_110 ( & V_85 -> V_95 ) ;
F_57 ( V_85 ) ;
}
}
struct V_24 * F_111 ( const T_4 * type ,
const T_4 * V_173 ,
struct V_31 * V_32 )
{
struct V_24 * V_174 ;
V_174 = F_54 ( sizeof( struct V_24 ) , V_91 ) ;
if ( ! V_174 ) {
F_68 ( L_15 ) ;
return NULL ;
}
V_174 -> V_32 = V_32 ;
memcpy ( & V_174 -> V_29 , type , sizeof( T_4 ) ) ;
memcpy ( & V_174 -> V_175 , V_173 ,
sizeof( T_4 ) ) ;
V_174 -> V_77 = 0x1414 ;
return V_174 ;
}
int F_112 ( struct V_24 * V_174 )
{
int V_81 = 0 ;
F_113 ( & V_174 -> V_46 , L_16 ,
V_174 -> V_32 -> V_33 . V_53 . V_55 . V_30 ) ;
V_174 -> V_46 . V_172 = & V_156 ;
V_174 -> V_46 . V_176 = & V_22 -> V_47 ;
V_174 -> V_46 . V_177 = F_72 ;
V_81 = F_114 ( & V_174 -> V_46 ) ;
if ( V_81 )
F_68 ( L_17 ) ;
else
F_115 ( L_18 ,
F_69 ( & V_174 -> V_46 ) ) ;
return V_81 ;
}
void F_116 ( struct V_24 * V_178 )
{
F_115 ( L_19 ,
F_69 ( & V_178 -> V_46 ) ) ;
F_117 ( & V_178 -> V_46 ) ;
}
static T_6 F_118 ( struct V_179 * V_180 , void * V_113 )
{
T_7 V_181 = 0 ;
T_7 V_182 = 0 ;
struct V_183 * V_184 ;
struct V_183 * * V_185 = & V_186 ;
struct V_183 * * V_187 = NULL ;
switch ( V_180 -> type ) {
case V_188 :
V_181 = V_180 -> V_124 . V_189 . V_190 . V_191 ;
V_182 = V_180 -> V_124 . V_189 . V_190 . V_192 ;
break;
case V_193 :
V_181 = V_180 -> V_124 . V_194 . V_190 . V_191 ;
V_182 = V_180 -> V_124 . V_194 . V_190 . V_192 ;
break;
default:
return V_195 ;
}
if ( V_182 < 0x100000 )
return V_195 ;
V_184 = F_54 ( sizeof( * V_184 ) , V_142 ) ;
if ( ! V_184 )
return V_196 ;
if ( V_182 > V_197 && V_181 < V_197 )
V_182 = V_197 ;
V_184 -> V_171 = L_20 ;
V_184 -> V_67 = V_198 ;
V_184 -> V_181 = V_181 ;
V_184 -> V_182 = V_182 ;
do {
if ( ! * V_185 ) {
* V_185 = V_184 ;
break;
}
if ( ( ( * V_185 ) -> V_182 + 1 ) == V_184 -> V_181 ) {
( * V_185 ) -> V_182 = V_184 -> V_182 ;
F_60 ( V_184 ) ;
break;
}
if ( ( * V_185 ) -> V_181 == V_184 -> V_182 + 1 ) {
( * V_185 ) -> V_181 = V_184 -> V_181 ;
F_60 ( V_184 ) ;
break;
}
if ( ( * V_185 ) -> V_181 > V_184 -> V_182 ) {
V_184 -> V_199 = * V_185 ;
if ( V_187 )
( * V_187 ) -> V_199 = V_184 ;
* V_185 = V_184 ;
break;
}
V_187 = V_185 ;
V_185 = & ( * V_185 ) -> V_199 ;
} while ( 1 );
return V_195 ;
}
static int F_119 ( struct V_200 * V_46 )
{
struct V_183 * V_201 ;
struct V_183 * V_202 ;
if ( V_186 ) {
if ( V_203 ) {
F_120 ( V_186 , V_203 -> V_181 ,
F_121 ( V_203 ) ) ;
V_203 = NULL ;
}
for ( V_201 = V_186 ; V_201 ; V_201 = V_202 ) {
V_202 = V_201 -> V_199 ;
F_60 ( V_201 ) ;
}
}
return 0 ;
}
static void F_122 ( void )
{
int V_204 ;
if ( V_205 . V_206 ) {
if ( F_123 ( V_207 ) )
V_204 = F_124 ( V_208 , V_205 . V_209 , 0x800000 ) ;
else
V_204 = F_124 ( V_208 , V_205 . V_209 , 0x4000000 ) ;
for (; ! V_203 && ( V_204 >= 0x100000 ) ; V_204 >>= 1 ) {
V_203 = F_125 ( V_186 ,
V_205 . V_206 , V_204 ,
V_210 , 0 ) ;
}
}
}
int F_126 ( struct V_183 * * V_211 , struct V_24 * V_178 ,
T_7 V_212 , T_7 V_213 ,
T_7 V_204 , T_7 V_214 ,
bool V_215 )
{
struct V_183 * V_216 , * V_217 ;
T_7 V_218 , V_219 , V_181 ;
const char * V_220 = F_69 ( & V_178 -> V_46 ) ;
int V_102 ;
V_102 = - V_221 ;
F_127 ( & V_222 ) ;
if ( V_215 && V_203 && ! ( V_212 > V_203 -> V_182 ) &&
! ( V_213 < V_203 -> V_181 ) ) {
V_218 = V_203 -> V_181 ;
V_219 = V_203 -> V_182 ;
V_181 = ( V_218 + V_214 - 1 ) & ~ ( V_214 - 1 ) ;
for (; V_181 + V_204 - 1 <= V_219 ; V_181 += V_214 ) {
* V_211 = F_128 ( V_181 , V_204 , V_220 ) ;
if ( * V_211 ) {
V_102 = 0 ;
goto exit;
}
}
}
for ( V_216 = V_186 ; V_216 ; V_216 = V_216 -> V_199 ) {
if ( ( V_216 -> V_181 >= V_213 ) || ( V_216 -> V_182 <= V_212 ) )
continue;
V_218 = V_216 -> V_181 ;
V_219 = V_216 -> V_182 ;
V_181 = ( V_218 + V_214 - 1 ) & ~ ( V_214 - 1 ) ;
for (; V_181 + V_204 - 1 <= V_219 ; V_181 += V_214 ) {
V_217 = F_125 ( V_216 , V_181 , V_204 , NULL ,
V_223 ) ;
if ( ! V_217 )
continue;
* V_211 = F_128 ( V_181 , V_204 , V_220 ) ;
if ( * V_211 ) {
V_217 -> V_171 = ( char * ) * V_211 ;
V_102 = 0 ;
goto exit;
}
F_120 ( V_216 , V_181 , V_204 ) ;
}
}
exit:
F_129 ( & V_222 ) ;
return V_102 ;
}
void F_130 ( T_7 V_181 , T_7 V_204 )
{
struct V_183 * V_216 ;
F_127 ( & V_222 ) ;
for ( V_216 = V_186 ; V_216 ; V_216 = V_216 -> V_199 ) {
if ( ( V_216 -> V_181 >= V_181 + V_204 ) || ( V_216 -> V_182 <= V_181 ) )
continue;
F_120 ( V_216 , V_181 , V_204 ) ;
}
F_131 ( V_181 , V_204 ) ;
F_129 ( & V_222 ) ;
}
int F_132 ( int V_224 )
{
return V_120 . V_225 [ V_224 ] ;
}
static int F_133 ( struct V_200 * V_46 )
{
T_6 V_226 ;
int V_227 = - V_23 ;
struct V_200 * V_228 ;
V_22 = V_46 ;
V_226 = F_134 ( V_46 -> V_229 , V_230 ,
F_118 , NULL ) ;
if ( F_135 ( V_226 ) )
goto V_231;
for ( V_228 = V_46 -> V_176 ; V_228 ; V_228 = V_228 -> V_176 ) {
V_226 = F_134 ( V_228 -> V_229 , V_230 ,
F_118 , NULL ) ;
if ( F_135 ( V_226 ) )
continue;
if ( V_186 ) {
F_122 () ;
break;
}
}
V_227 = 0 ;
V_231:
F_136 ( & V_232 ) ;
if ( V_227 )
F_119 ( V_46 ) ;
return V_227 ;
}
static void F_137 ( void )
{
int V_118 ;
F_138 () ;
F_139 ( false ) ;
F_140 (cpu)
F_141 ( V_118 , V_167 , NULL , 1 ) ;
F_103 ( false ) ;
}
static void F_142 ( struct V_1 * V_2 )
{
F_139 ( true ) ;
V_167 ( NULL ) ;
F_103 ( true ) ;
}
static int T_8 F_143 ( void )
{
int V_81 , V_233 ;
if ( V_234 != & V_235 )
return - V_23 ;
F_144 ( & V_232 ) ;
V_81 = F_145 ( & V_236 ) ;
if ( V_81 )
return V_81 ;
V_233 = F_146 ( & V_232 , 5 * V_237 ) ;
if ( V_233 == 0 ) {
V_81 = - V_238 ;
goto V_239;
}
V_81 = F_89 () ;
if ( V_81 )
goto V_239;
F_147 ( F_137 ) ;
F_148 ( F_142 ) ;
return 0 ;
V_239:
F_149 ( & V_236 ) ;
V_22 = NULL ;
return V_81 ;
}
static void T_9 F_150 ( void )
{
int V_118 ;
F_151 () ;
F_152 () ;
V_56 . V_114 = V_115 ;
F_138 () ;
F_153 () ;
F_101 () ;
F_140 (cpu)
F_154 ( V_120 . V_154 [ V_118 ] ) ;
F_155 () ;
if ( V_161 . V_162 & V_163 ) {
F_156 ( & V_164 ) ;
F_157 ( & V_165 ,
& V_166 ) ;
}
F_102 ( & V_156 ) ;
F_103 ( false ) ;
F_140 (cpu) {
F_154 ( V_120 . V_153 [ V_118 ] ) ;
F_141 ( V_118 , V_167 , NULL , 1 ) ;
}
F_100 () ;
F_149 ( & V_236 ) ;
if ( V_149 > V_151 )
F_158 () ;
}
