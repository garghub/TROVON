const char * F_1 ( enum V_1 V_2 )
{
int V_3 ;
char * V_4 = NULL ;
for ( V_3 = 0 ; V_3 < F_2 ( V_5 ) ; V_3 ++ ) {
if ( V_5 [ V_3 ] . V_6 == V_2 ) {
V_4 = V_5 [ V_3 ] . V_4 ;
break;
}
}
return V_4 ;
}
const char * F_3 ( enum V_7 V_2 )
{
int V_3 ;
char * V_4 = NULL ;
for ( V_3 = 0 ; V_3 < F_2 ( V_8 ) ; V_3 ++ ) {
if ( V_8 [ V_3 ] . V_6 == V_2 ) {
V_4 = V_8 [ V_3 ] . V_4 ;
break;
}
}
return V_4 ;
}
static int F_4 ( unsigned int * V_9 , char * V_10 )
{
char * V_11 ;
if ( strncmp ( V_10 , L_1 , 20 ) == 0 ) {
* V_9 = V_12 ;
} else {
* V_9 = F_5 ( V_10 , & V_11 , 0 ) ;
if ( * V_11 != '\0' )
return 1 ;
}
return 0 ;
}
static int F_6 ( struct V_13 * V_14 , const char * V_15 )
{
char V_16 [ 15 ] , V_17 [ 15 ] , V_18 [ 15 ] , V_19 ;
unsigned int V_20 , V_21 , V_22 ;
int V_23 ;
V_23 = sscanf ( V_15 , L_2 , V_16 , V_17 , V_18 , & V_19 ) ;
if ( V_23 != 3 )
return - V_24 ;
if ( F_4 ( & V_20 , V_16 ) )
return - V_24 ;
if ( F_4 ( & V_21 , V_17 ) )
return - V_24 ;
if ( F_4 ( & V_22 , V_18 ) )
return - V_24 ;
if ( V_14 -> V_25 -> V_26 )
V_23 = V_14 -> V_25 -> V_26 ( V_14 , V_20 , V_21 , V_22 ) ;
else
V_23 = F_7 ( V_14 , V_20 , V_21 , V_22 , 1 ) ;
return V_23 ;
}
static T_1
F_8 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_13 * V_14 = F_9 ( V_28 ) ;
int V_23 ;
V_23 = F_6 ( V_14 , V_31 ) ;
if ( V_23 == 0 )
V_23 = V_32 ;
return V_23 ;
}
static T_1
F_10 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
int V_3 ;
struct V_13 * V_14 = F_9 ( V_28 ) ;
enum V_7 V_2 = 0 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_8 ) ; V_3 ++ ) {
const int V_33 = strlen ( V_8 [ V_3 ] . V_4 ) ;
if ( strncmp ( V_8 [ V_3 ] . V_4 , V_31 , V_33 ) == 0 &&
V_31 [ V_33 ] == '\n' ) {
V_2 = V_8 [ V_3 ] . V_6 ;
break;
}
}
if ( ! V_2 )
return - V_24 ;
if ( F_11 ( V_14 , V_2 ) )
return - V_24 ;
return V_32 ;
}
static T_1
F_12 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_13 * V_14 = F_9 ( V_28 ) ;
const char * V_4 = F_3 ( V_14 -> V_34 ) ;
if ( ! V_4 )
return - V_24 ;
return snprintf ( V_31 , 20 , L_3 , V_4 ) ;
}
static T_1
F_13 ( unsigned int V_35 , char * V_31 )
{
T_1 V_33 = 0 ;
if ( V_35 & V_36 )
V_33 = sprintf ( V_31 , L_4 , L_5 ) ;
if ( V_35 & V_37 )
V_33 += sprintf ( V_31 + V_33 , L_6 , V_33 ? L_7 : L_8 , L_9 ) ;
V_33 += sprintf ( V_31 + V_33 , L_10 ) ;
return V_33 ;
}
static T_1
F_14 ( struct V_27 * V_28 , struct V_29 * V_30 ,
char * V_31 )
{
struct V_13 * V_14 = F_9 ( V_28 ) ;
unsigned int V_38 = V_14 -> V_39 -> V_38 ;
if ( V_38 == V_40 )
V_38 = V_36 ;
return F_13 ( V_38 , V_31 ) ;
}
static T_1
F_15 ( struct V_27 * V_28 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_13 * V_14 = F_9 ( V_28 ) ;
if ( V_14 -> V_41 == V_40 )
return snprintf ( V_31 , 20 , L_11 ) ;
else
return F_13 ( V_14 -> V_41 , V_31 ) ;
}
static int F_16 ( const char * V_15 )
{
if ( F_17 ( V_15 , L_12 ) )
return V_42 ;
else if ( F_17 ( V_15 , L_13 ) )
return V_43 ;
else
return 0 ;
}
static T_1
F_18 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_13 * V_14 = F_9 ( V_28 ) ;
struct V_44 * V_45 = V_14 -> V_39 ;
int V_46 = - V_24 ;
int type ;
type = F_16 ( V_31 ) ;
if ( ! type )
goto V_47;
if ( V_45 -> V_48 )
V_46 = V_45 -> V_48 ( V_14 , type ) ;
V_47:
if ( V_46 == 0 )
V_46 = V_32 ;
return V_46 ;
}
static void F_19 ( struct V_27 * V_49 )
{
struct V_50 * V_51 ;
V_51 = F_20 ( V_49 ) ;
F_21 ( & V_51 -> V_52 ) ;
}
static void F_22 ( struct V_53 * V_54 )
{
struct V_50 * V_51 ;
struct V_27 * V_55 ;
struct V_56 * V_57 ;
struct V_58 * V_59 , * V_60 ;
unsigned long V_61 ;
V_51 = F_23 ( V_54 , struct V_50 , V_62 . V_54 ) ;
V_55 = V_51 -> V_52 . V_55 ;
V_57 = F_24 ( V_55 ) ;
F_25 ( V_51 -> V_63 -> V_64 , V_61 ) ;
V_57 -> V_65 ++ ;
F_26 ( & V_51 -> V_66 ) ;
F_26 ( & V_51 -> V_67 ) ;
F_26 ( & V_51 -> V_68 ) ;
F_27 ( V_51 -> V_63 -> V_64 , V_61 ) ;
F_28 ( & V_51 -> V_69 ) ;
F_29 (this, tmp, &sdev->event_list) {
struct V_70 * V_71 ;
V_71 = F_30 ( V_59 , struct V_70 , V_72 ) ;
F_26 ( & V_71 -> V_72 ) ;
F_31 ( V_71 ) ;
}
F_32 ( V_51 -> V_73 ) ;
V_51 -> V_73 = NULL ;
F_33 ( V_56 ( V_51 ) ) ;
F_31 ( V_51 -> V_74 ) ;
F_31 ( V_51 ) ;
if ( V_55 )
F_21 ( V_55 ) ;
}
static void F_34 ( struct V_27 * V_28 )
{
struct V_50 * V_75 = F_35 ( V_28 ) ;
F_36 ( F_22 ,
& V_75 -> V_62 ) ;
}
static int F_37 ( struct V_27 * V_28 , struct V_76 * V_77 )
{
struct V_50 * V_75 ;
if ( V_28 -> type != & V_78 )
return 0 ;
V_75 = F_35 ( V_28 ) ;
if ( V_75 -> V_79 )
return 0 ;
return ( V_75 -> V_80 == V_81 ) ? 1 : 0 ;
}
static int F_38 ( struct V_27 * V_28 , struct V_82 * V_83 )
{
struct V_50 * V_51 ;
if ( V_28 -> type != & V_78 )
return 0 ;
V_51 = F_35 ( V_28 ) ;
F_39 ( V_83 , L_14 V_84 , V_51 -> type ) ;
return 0 ;
}
int F_40 ( void )
{
int error ;
error = F_41 ( & V_85 ) ;
if ( ! error ) {
error = F_42 ( & V_86 ) ;
if ( error )
F_43 ( & V_85 ) ;
}
return error ;
}
void F_44 ( void )
{
F_45 ( & V_86 ) ;
F_43 ( & V_85 ) ;
}
static T_1
F_46 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_50 * V_51 ;
V_51 = F_35 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_15 , V_51 -> V_73 -> V_87 / V_88 ) ;
}
static T_1
F_47 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_50 * V_51 ;
int V_89 ;
V_51 = F_35 ( V_28 ) ;
sscanf ( V_31 , L_15 , & V_89 ) ;
F_48 ( V_51 -> V_73 , V_89 * V_88 ) ;
return V_32 ;
}
static T_1
F_49 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_50 * V_51 ;
V_51 = F_35 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_16 , V_51 -> V_90 / V_88 ) ;
}
static T_1
F_50 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_50 * V_51 ;
unsigned int V_90 ;
int V_91 ;
if ( ! F_51 ( V_92 ) )
return - V_93 ;
V_51 = F_35 ( V_28 ) ;
V_91 = F_52 ( V_31 , 10 , & V_90 ) ;
if ( V_91 )
return V_91 ;
V_51 -> V_90 = V_90 * V_88 ;
return V_32 ;
}
static T_1
F_53 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
F_54 ( V_28 ) ;
return V_32 ;
}
static void F_55 ( struct V_27 * V_28 )
{
F_56 ( F_35 ( V_28 ) ) ;
}
static T_1
F_57 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
int V_94 ;
V_94 = F_58 ( V_28 , F_55 ) ;
if ( V_94 )
V_32 = V_94 ;
return V_32 ;
}
static T_1
F_59 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
int V_3 ;
struct V_50 * V_51 = F_35 ( V_28 ) ;
enum V_1 V_2 = 0 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_5 ) ; V_3 ++ ) {
const int V_33 = strlen ( V_5 [ V_3 ] . V_4 ) ;
if ( strncmp ( V_5 [ V_3 ] . V_4 , V_31 , V_33 ) == 0 &&
V_31 [ V_33 ] == '\n' ) {
V_2 = V_5 [ V_3 ] . V_6 ;
break;
}
}
if ( ! V_2 )
return - V_24 ;
if ( F_60 ( V_51 , V_2 ) )
return - V_24 ;
return V_32 ;
}
static T_1
F_61 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_50 * V_51 = F_35 ( V_28 ) ;
const char * V_4 = F_1 ( V_51 -> V_95 ) ;
if ( ! V_4 )
return - V_24 ;
return snprintf ( V_31 , 20 , L_3 , V_4 ) ;
}
static T_1
F_62 ( struct V_27 * V_28 , struct V_29 * V_30 ,
char * V_31 )
{
struct V_50 * V_51 = F_35 ( V_28 ) ;
const char * V_4 = L_17 ;
if ( V_51 -> V_96 )
V_4 = L_18 ;
else if ( V_51 -> V_97 )
V_4 = L_19 ;
return snprintf ( V_31 , 20 , L_3 , V_4 ) ;
}
static T_1
F_63 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
return snprintf ( V_31 , 20 , L_15 , ( int ) sizeof( V_98 ) * 8 ) ;
}
static T_1
F_64 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_50 * V_51 ;
V_51 = F_35 ( V_28 ) ;
return snprintf ( V_31 , 20 , V_84 L_10 , V_51 -> type ) ;
}
static T_1
F_65 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
int V_99 , V_100 ;
struct V_50 * V_51 = F_35 ( V_28 ) ;
struct V_44 * V_45 = V_51 -> V_63 -> V_39 ;
if ( ! V_45 -> V_101 )
return - V_24 ;
V_99 = F_5 ( V_31 , NULL , 0 ) ;
if ( V_99 < 1 )
return - V_24 ;
V_100 = V_45 -> V_101 ( V_51 , V_99 ,
V_102 ) ;
if ( V_100 < 0 )
return V_100 ;
V_51 -> V_103 = V_51 -> V_104 ;
return V_32 ;
}
static T_1
F_66 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
char * V_31 )
{
struct V_50 * V_51 ;
V_51 = F_35 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_16 ,
F_67 ( V_51 -> V_105 ) ) ;
}
static T_1
F_68 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_50 * V_51 = F_35 ( V_28 ) ;
unsigned long V_106 ;
if ( F_69 ( V_31 , 10 , & V_106 ) )
return - V_24 ;
V_51 -> V_105 = F_70 ( V_106 ) ;
return V_106 ;
}
static T_1
F_71 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_50 * V_51 = F_35 ( V_28 ) ;
struct V_44 * V_45 = V_51 -> V_63 -> V_39 ;
int V_107 = 0 , V_100 ;
int V_108 = F_72 ( V_51 ) ;
if ( ! V_51 -> V_109 || ! V_45 -> V_110 )
return - V_24 ;
if ( strncmp ( V_31 , L_18 , 7 ) == 0 )
V_107 = V_111 ;
else if ( strncmp ( V_31 , L_19 , 6 ) == 0 )
V_107 = V_112 ;
else if ( strncmp ( V_31 , L_17 , 4 ) != 0 )
return - V_24 ;
if ( V_107 == V_108 )
return V_32 ;
V_100 = V_45 -> V_110 ( V_51 , V_107 ) ;
if ( V_100 < 0 )
return V_100 ;
return V_32 ;
}
static int F_73 ( struct V_56 * V_57 )
{
int error ;
if ( V_57 -> V_2 != V_113 )
return 0 ;
error = F_74 ( & V_57 -> V_28 ) ;
if ( error ) {
F_75 ( & V_57 -> V_28 , L_20 , error ) ;
return error ;
}
F_76 ( & V_57 -> V_28 ) ;
V_57 -> V_2 = V_114 ;
F_77 ( & V_57 -> V_28 ) ;
F_78 ( & V_57 -> V_28 ) ;
F_79 ( & V_57 -> V_28 ) ;
return 0 ;
}
int F_80 ( struct V_50 * V_51 )
{
int error , V_3 ;
struct V_73 * V_115 = V_51 -> V_73 ;
struct V_56 * V_57 = V_51 -> V_116 ;
error = F_60 ( V_51 , V_117 ) ;
if ( error )
return error ;
error = F_73 ( V_57 ) ;
if ( error )
return error ;
F_81 ( & V_57 -> V_28 ) ;
F_79 ( & V_51 -> V_52 ) ;
F_82 ( V_57 ) ;
F_77 ( & V_51 -> V_52 ) ;
F_83 ( & V_51 -> V_52 ) ;
F_78 ( & V_51 -> V_52 ) ;
F_84 ( V_57 ) ;
F_85 ( V_51 ) ;
error = F_74 ( & V_51 -> V_52 ) ;
if ( error ) {
F_86 ( V_118 , V_51 ,
L_21 , error ) ;
return error ;
}
F_79 ( & V_51 -> V_119 ) ;
error = F_74 ( & V_51 -> V_119 ) ;
if ( error ) {
F_86 ( V_118 , V_51 ,
L_22 , error ) ;
F_87 ( & V_51 -> V_52 ) ;
return error ;
}
F_76 ( & V_51 -> V_52 ) ;
V_51 -> V_120 = 1 ;
if ( V_51 -> V_63 -> V_39 -> V_101 ) {
error = F_88 ( & V_51 -> V_52 ,
& V_121 ) ;
error = F_88 ( & V_51 -> V_52 ,
& V_122 ) ;
}
else
error = F_88 ( & V_51 -> V_52 , & V_123 ) ;
if ( error )
return error ;
if ( V_51 -> V_63 -> V_39 -> V_110 )
error = F_88 ( & V_51 -> V_52 , & V_124 ) ;
else
error = F_88 ( & V_51 -> V_52 , & V_125 ) ;
if ( error )
return error ;
error = F_89 ( V_115 , & V_51 -> V_52 , NULL , NULL ) ;
if ( error )
F_86 ( V_118 , V_51 ,
L_23 , error ) ;
if ( V_51 -> V_63 -> V_39 -> V_126 ) {
for ( V_3 = 0 ; V_51 -> V_63 -> V_39 -> V_126 [ V_3 ] ; V_3 ++ ) {
error = F_88 ( & V_51 -> V_52 ,
V_51 -> V_63 -> V_39 -> V_126 [ V_3 ] ) ;
if ( error )
return error ;
}
}
return error ;
}
void F_90 ( struct V_50 * V_51 )
{
struct V_27 * V_28 = & V_51 -> V_52 ;
if ( V_51 -> V_120 ) {
if ( F_60 ( V_51 , V_127 ) != 0 )
return;
F_91 ( V_51 -> V_73 ) ;
F_92 ( & V_51 -> V_119 ) ;
F_93 ( V_28 ) ;
F_87 ( V_28 ) ;
} else
F_21 ( & V_51 -> V_119 ) ;
F_60 ( V_51 , V_128 ) ;
F_94 ( V_51 -> V_73 ) ;
F_28 ( & V_51 -> V_129 ) ;
if ( V_51 -> V_63 -> V_39 -> V_130 )
V_51 -> V_63 -> V_39 -> V_130 ( V_51 ) ;
F_95 ( V_28 ) ;
F_21 ( V_28 ) ;
}
void F_56 ( struct V_50 * V_51 )
{
struct V_13 * V_14 = V_51 -> V_63 ;
F_96 ( & V_14 -> V_131 ) ;
F_90 ( V_51 ) ;
F_97 ( & V_14 -> V_131 ) ;
}
static void F_98 ( struct V_56 * V_57 )
{
struct V_13 * V_14 = F_99 ( V_57 -> V_28 . V_55 ) ;
unsigned long V_61 ;
struct V_50 * V_51 ;
F_25 ( V_14 -> V_64 , V_61 ) ;
V_132:
F_100 (sdev, &shost->__devices, siblings) {
if ( V_51 -> V_20 != V_57 -> V_20 ||
V_51 -> V_21 != V_57 -> V_21 ||
F_101 ( V_51 ) )
continue;
F_27 ( V_14 -> V_64 , V_61 ) ;
F_56 ( V_51 ) ;
F_102 ( V_51 ) ;
F_25 ( V_14 -> V_64 , V_61 ) ;
goto V_132;
}
F_27 ( V_14 -> V_64 , V_61 ) ;
}
void F_103 ( struct V_27 * V_28 )
{
struct V_13 * V_14 = F_99 ( V_28 -> V_55 ) ;
struct V_56 * V_57 , * V_11 = NULL ;
unsigned long V_61 ;
F_25 ( V_14 -> V_64 , V_61 ) ;
F_100 (starget, &shost->__targets, siblings) {
if ( V_57 -> V_2 == V_133 )
continue;
if ( V_57 -> V_28 . V_55 == V_28 || & V_57 -> V_28 == V_28 ) {
V_57 -> V_65 ++ ;
F_27 ( V_14 -> V_64 , V_61 ) ;
if ( V_11 )
F_33 ( V_11 ) ;
V_11 = V_57 ;
F_98 ( V_57 ) ;
F_25 ( V_14 -> V_64 , V_61 ) ;
}
}
F_27 ( V_14 -> V_64 , V_61 ) ;
if ( V_11 )
F_33 ( V_11 ) ;
}
int F_104 ( struct V_76 * V_134 )
{
V_134 -> V_135 = & V_85 ;
return F_105 ( V_134 ) ;
}
int F_106 ( struct V_136 * V_137 )
{
V_137 -> V_138 = & V_86 ;
return F_107 ( V_137 ) ;
}
int F_108 ( struct V_13 * V_14 )
{
int error , V_3 ;
if ( V_14 -> V_39 -> V_139 ) {
for ( V_3 = 0 ; V_14 -> V_39 -> V_139 [ V_3 ] ; V_3 ++ ) {
error = F_88 ( & V_14 -> V_140 ,
V_14 -> V_39 -> V_139 [ V_3 ] ) ;
if ( error )
return error ;
}
}
F_109 ( & V_14 -> V_141 ) ;
F_81 ( & V_14 -> V_141 ) ;
return 0 ;
}
void F_110 ( struct V_50 * V_51 )
{
unsigned long V_61 ;
struct V_13 * V_14 = V_51 -> V_63 ;
struct V_56 * V_57 = V_51 -> V_116 ;
F_111 ( & V_51 -> V_52 ) ;
V_51 -> V_52 . V_135 = & V_85 ;
V_51 -> V_52 . type = & V_78 ;
F_112 ( & V_51 -> V_52 , L_24 ,
V_51 -> V_63 -> V_142 , V_51 -> V_20 , V_51 -> V_21 , V_51 -> V_22 ) ;
F_111 ( & V_51 -> V_119 ) ;
V_51 -> V_119 . V_55 = F_113 ( & V_51 -> V_52 ) ;
V_51 -> V_119 . V_138 = & V_86 ;
F_112 ( & V_51 -> V_119 , L_24 ,
V_51 -> V_63 -> V_142 , V_51 -> V_20 , V_51 -> V_21 , V_51 -> V_22 ) ;
V_51 -> V_143 = V_57 -> V_143 ;
F_114 ( & V_51 -> V_52 ) ;
F_25 ( V_14 -> V_64 , V_61 ) ;
F_115 ( & V_51 -> V_67 , & V_57 -> V_144 ) ;
F_115 ( & V_51 -> V_66 , & V_14 -> V_145 ) ;
F_27 ( V_14 -> V_64 , V_61 ) ;
}
int F_116 ( const struct V_27 * V_28 )
{
return V_28 -> type == & V_78 ;
}
