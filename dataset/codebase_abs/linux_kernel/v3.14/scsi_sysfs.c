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
static T_1
F_19 ( struct V_27 * V_28 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_13 * V_14 = F_9 ( V_28 ) ;
if ( V_14 -> V_49 == - 1 )
return snprintf ( V_31 , strlen ( L_14 ) + 2 , L_15 ) ;
return sprintf ( V_31 , L_16 , V_14 -> V_49 / V_50 ) ;
}
static T_1
F_20 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_13 * V_14 = F_9 ( V_28 ) ;
int V_46 = - V_24 ;
unsigned long V_51 , V_52 ;
if ( V_14 -> V_25 && V_14 -> V_25 -> V_53 )
return V_46 ;
if ( ! strncmp ( V_31 , L_14 , strlen ( L_14 ) ) )
V_51 = - 1 ;
else {
V_46 = F_21 ( V_31 , 10 , & V_51 ) ;
if ( V_46 )
return V_46 ;
if ( V_51 * V_50 > V_54 )
return - V_24 ;
}
F_22 ( V_14 -> V_55 , V_52 ) ;
if ( F_23 ( V_14 ) )
V_46 = - V_56 ;
else {
if ( V_51 == - 1 )
V_14 -> V_49 = - 1 ;
else
V_14 -> V_49 = V_51 * V_50 ;
V_46 = V_32 ;
}
F_24 ( V_14 -> V_55 , V_52 ) ;
return V_46 ;
}
static void F_25 ( struct V_27 * V_57 )
{
struct V_58 * V_59 ;
V_59 = F_26 ( V_57 ) ;
F_27 ( & V_59 -> V_60 ) ;
}
static void F_28 ( struct V_61 * V_62 )
{
struct V_58 * V_59 ;
struct V_27 * V_63 ;
struct V_64 * V_65 ;
struct V_66 * V_67 , * V_68 ;
unsigned long V_52 ;
V_59 = F_29 ( V_62 , struct V_58 , V_69 . V_62 ) ;
V_63 = V_59 -> V_60 . V_63 ;
V_65 = F_30 ( V_63 ) ;
F_22 ( V_59 -> V_70 -> V_55 , V_52 ) ;
V_65 -> V_71 ++ ;
F_31 ( & V_59 -> V_72 ) ;
F_31 ( & V_59 -> V_73 ) ;
F_31 ( & V_59 -> V_74 ) ;
F_24 ( V_59 -> V_70 -> V_55 , V_52 ) ;
F_32 ( & V_59 -> V_75 ) ;
F_33 (this, tmp, &sdev->event_list) {
struct V_76 * V_77 ;
V_77 = F_34 ( V_67 , struct V_76 , V_78 ) ;
F_31 ( & V_77 -> V_78 ) ;
F_35 ( V_77 ) ;
}
F_36 ( V_59 -> V_79 ) ;
V_59 -> V_79 = NULL ;
F_37 ( V_64 ( V_59 ) ) ;
F_35 ( V_59 -> V_80 ) ;
F_35 ( V_59 ) ;
if ( V_63 )
F_27 ( V_63 ) ;
}
static void F_38 ( struct V_27 * V_28 )
{
struct V_58 * V_81 = F_39 ( V_28 ) ;
F_40 ( F_28 ,
& V_81 -> V_69 ) ;
}
static int F_41 ( struct V_27 * V_28 , struct V_82 * V_83 )
{
struct V_58 * V_81 ;
if ( V_28 -> type != & V_84 )
return 0 ;
V_81 = F_39 ( V_28 ) ;
if ( V_81 -> V_85 )
return 0 ;
return ( V_81 -> V_86 == V_87 ) ? 1 : 0 ;
}
static int F_42 ( struct V_27 * V_28 , struct V_88 * V_89 )
{
struct V_58 * V_59 ;
if ( V_28 -> type != & V_84 )
return 0 ;
V_59 = F_39 ( V_28 ) ;
F_43 ( V_89 , L_17 V_90 , V_59 -> type ) ;
return 0 ;
}
int F_44 ( void )
{
int error ;
error = F_45 ( & V_91 ) ;
if ( ! error ) {
error = F_46 ( & V_92 ) ;
if ( error )
F_47 ( & V_91 ) ;
}
return error ;
}
void F_48 ( void )
{
F_49 ( & V_92 ) ;
F_47 ( & V_91 ) ;
}
static T_1
F_50 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_58 * V_59 ;
V_59 = F_39 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_18 , V_59 -> V_79 -> V_93 / V_50 ) ;
}
static T_1
F_51 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_58 * V_59 ;
int V_94 ;
V_59 = F_39 ( V_28 ) ;
sscanf ( V_31 , L_18 , & V_94 ) ;
F_52 ( V_59 -> V_79 , V_94 * V_50 ) ;
return V_32 ;
}
static T_1
F_53 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_58 * V_59 ;
V_59 = F_39 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_16 , V_59 -> V_95 / V_50 ) ;
}
static T_1
F_54 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_58 * V_59 ;
unsigned int V_95 ;
int V_96 ;
if ( ! F_55 ( V_97 ) )
return - V_98 ;
V_59 = F_39 ( V_28 ) ;
V_96 = F_56 ( V_31 , 10 , & V_95 ) ;
if ( V_96 )
return V_96 ;
V_59 -> V_95 = V_95 * V_50 ;
return V_32 ;
}
static T_1
F_57 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
F_58 ( V_28 ) ;
return V_32 ;
}
static void F_59 ( struct V_27 * V_28 )
{
F_60 ( F_39 ( V_28 ) ) ;
}
static T_1
F_61 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
int V_99 ;
V_99 = F_62 ( V_28 , F_59 ) ;
if ( V_99 )
V_32 = V_99 ;
return V_32 ;
}
static T_1
F_63 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
int V_3 ;
struct V_58 * V_59 = F_39 ( V_28 ) ;
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
if ( F_64 ( V_59 , V_2 ) )
return - V_24 ;
return V_32 ;
}
static T_1
F_65 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_58 * V_59 = F_39 ( V_28 ) ;
const char * V_4 = F_1 ( V_59 -> V_100 ) ;
if ( ! V_4 )
return - V_24 ;
return snprintf ( V_31 , 20 , L_3 , V_4 ) ;
}
static T_1
F_66 ( struct V_27 * V_28 , struct V_29 * V_30 ,
char * V_31 )
{
struct V_58 * V_59 = F_39 ( V_28 ) ;
const char * V_4 = L_19 ;
if ( V_59 -> V_101 )
V_4 = L_20 ;
else if ( V_59 -> V_102 )
V_4 = L_21 ;
return snprintf ( V_31 , 20 , L_3 , V_4 ) ;
}
static T_1
F_67 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
return snprintf ( V_31 , 20 , L_18 , ( int ) sizeof( V_103 ) * 8 ) ;
}
static T_1
F_68 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_58 * V_59 ;
V_59 = F_39 ( V_28 ) ;
return snprintf ( V_31 , 20 , V_90 L_10 , V_59 -> type ) ;
}
static T_1
F_69 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
int V_104 , V_105 ;
struct V_58 * V_59 = F_39 ( V_28 ) ;
struct V_44 * V_45 = V_59 -> V_70 -> V_39 ;
if ( ! V_45 -> V_106 )
return - V_24 ;
V_104 = F_5 ( V_31 , NULL , 0 ) ;
if ( V_104 < 1 )
return - V_24 ;
V_105 = V_45 -> V_106 ( V_59 , V_104 ,
V_107 ) ;
if ( V_105 < 0 )
return V_105 ;
V_59 -> V_108 = V_59 -> V_109 ;
return V_32 ;
}
static T_1
F_70 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
char * V_31 )
{
struct V_58 * V_59 ;
V_59 = F_39 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_16 ,
F_71 ( V_59 -> V_110 ) ) ;
}
static T_1
F_72 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_58 * V_59 = F_39 ( V_28 ) ;
unsigned long V_111 ;
if ( F_73 ( V_31 , 10 , & V_111 ) )
return - V_24 ;
V_59 -> V_110 = F_74 ( V_111 ) ;
return V_111 ;
}
static T_1
F_75 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_58 * V_59 = F_39 ( V_28 ) ;
struct V_44 * V_45 = V_59 -> V_70 -> V_39 ;
int V_112 = 0 , V_105 ;
int V_113 = F_76 ( V_59 ) ;
if ( ! V_59 -> V_114 || ! V_45 -> V_115 )
return - V_24 ;
if ( strncmp ( V_31 , L_20 , 7 ) == 0 )
V_112 = V_116 ;
else if ( strncmp ( V_31 , L_21 , 6 ) == 0 )
V_112 = V_117 ;
else if ( strncmp ( V_31 , L_19 , 4 ) != 0 )
return - V_24 ;
if ( V_112 == V_113 )
return V_32 ;
V_105 = V_45 -> V_115 ( V_59 , V_112 ) ;
if ( V_105 < 0 )
return V_105 ;
return V_32 ;
}
static int F_77 ( struct V_64 * V_65 )
{
int error ;
if ( V_65 -> V_2 != V_118 )
return 0 ;
error = F_78 ( & V_65 -> V_28 ) ;
if ( error ) {
F_79 ( & V_65 -> V_28 , L_22 , error ) ;
return error ;
}
F_80 ( & V_65 -> V_28 ) ;
V_65 -> V_2 = V_119 ;
F_81 ( & V_65 -> V_28 ) ;
F_82 ( & V_65 -> V_28 ) ;
F_83 ( & V_65 -> V_28 ) ;
return 0 ;
}
int F_84 ( struct V_58 * V_59 )
{
int error , V_3 ;
struct V_79 * V_120 = V_59 -> V_79 ;
struct V_64 * V_65 = V_59 -> V_121 ;
error = F_64 ( V_59 , V_122 ) ;
if ( error )
return error ;
error = F_77 ( V_65 ) ;
if ( error )
return error ;
F_85 ( & V_65 -> V_28 ) ;
F_83 ( & V_59 -> V_60 ) ;
F_86 ( V_65 ) ;
F_81 ( & V_59 -> V_60 ) ;
F_87 ( & V_59 -> V_60 ) ;
F_82 ( & V_59 -> V_60 ) ;
F_88 ( V_65 ) ;
F_89 ( V_59 ) ;
error = F_78 ( & V_59 -> V_60 ) ;
if ( error ) {
F_90 ( V_123 , V_59 ,
L_23 , error ) ;
return error ;
}
F_83 ( & V_59 -> V_124 ) ;
error = F_78 ( & V_59 -> V_124 ) ;
if ( error ) {
F_90 ( V_123 , V_59 ,
L_24 , error ) ;
F_91 ( & V_59 -> V_60 ) ;
return error ;
}
F_80 ( & V_59 -> V_60 ) ;
V_59 -> V_125 = 1 ;
if ( V_59 -> V_70 -> V_39 -> V_106 ) {
error = F_92 ( & V_59 -> V_60 ,
& V_126 ) ;
error = F_92 ( & V_59 -> V_60 ,
& V_127 ) ;
}
else
error = F_92 ( & V_59 -> V_60 , & V_128 ) ;
if ( error )
return error ;
if ( V_59 -> V_70 -> V_39 -> V_115 )
error = F_92 ( & V_59 -> V_60 , & V_129 ) ;
else
error = F_92 ( & V_59 -> V_60 , & V_130 ) ;
if ( error )
return error ;
error = F_93 ( V_120 , & V_59 -> V_60 , NULL , NULL ) ;
if ( error )
F_90 ( V_123 , V_59 ,
L_25 , error ) ;
if ( V_59 -> V_70 -> V_39 -> V_131 ) {
for ( V_3 = 0 ; V_59 -> V_70 -> V_39 -> V_131 [ V_3 ] ; V_3 ++ ) {
error = F_92 ( & V_59 -> V_60 ,
V_59 -> V_70 -> V_39 -> V_131 [ V_3 ] ) ;
if ( error )
return error ;
}
}
return error ;
}
void F_94 ( struct V_58 * V_59 )
{
struct V_27 * V_28 = & V_59 -> V_60 ;
if ( V_59 -> V_125 ) {
if ( F_64 ( V_59 , V_132 ) != 0 )
return;
F_95 ( V_59 -> V_79 ) ;
F_96 ( & V_59 -> V_124 ) ;
F_97 ( V_28 ) ;
F_91 ( V_28 ) ;
} else
F_27 ( & V_59 -> V_124 ) ;
F_64 ( V_59 , V_133 ) ;
F_98 ( V_59 -> V_79 ) ;
F_32 ( & V_59 -> V_134 ) ;
if ( V_59 -> V_70 -> V_39 -> V_135 )
V_59 -> V_70 -> V_39 -> V_135 ( V_59 ) ;
F_99 ( V_28 ) ;
F_27 ( V_28 ) ;
}
void F_60 ( struct V_58 * V_59 )
{
struct V_13 * V_14 = V_59 -> V_70 ;
F_100 ( & V_14 -> V_136 ) ;
F_94 ( V_59 ) ;
F_101 ( & V_14 -> V_136 ) ;
}
static void F_102 ( struct V_64 * V_65 )
{
struct V_13 * V_14 = F_103 ( V_65 -> V_28 . V_63 ) ;
unsigned long V_52 ;
struct V_58 * V_59 ;
F_22 ( V_14 -> V_55 , V_52 ) ;
V_137:
F_104 (sdev, &shost->__devices, siblings) {
if ( V_59 -> V_20 != V_65 -> V_20 ||
V_59 -> V_21 != V_65 -> V_21 ||
F_105 ( V_59 ) )
continue;
F_24 ( V_14 -> V_55 , V_52 ) ;
F_60 ( V_59 ) ;
F_106 ( V_59 ) ;
F_22 ( V_14 -> V_55 , V_52 ) ;
goto V_137;
}
F_24 ( V_14 -> V_55 , V_52 ) ;
}
void F_107 ( struct V_27 * V_28 )
{
struct V_13 * V_14 = F_103 ( V_28 -> V_63 ) ;
struct V_64 * V_65 , * V_11 = NULL ;
unsigned long V_52 ;
F_22 ( V_14 -> V_55 , V_52 ) ;
F_104 (starget, &shost->__targets, siblings) {
if ( V_65 -> V_2 == V_138 )
continue;
if ( V_65 -> V_28 . V_63 == V_28 || & V_65 -> V_28 == V_28 ) {
V_65 -> V_71 ++ ;
F_24 ( V_14 -> V_55 , V_52 ) ;
if ( V_11 )
F_37 ( V_11 ) ;
V_11 = V_65 ;
F_102 ( V_65 ) ;
F_22 ( V_14 -> V_55 , V_52 ) ;
}
}
F_24 ( V_14 -> V_55 , V_52 ) ;
if ( V_11 )
F_37 ( V_11 ) ;
}
int F_108 ( struct V_82 * V_139 )
{
V_139 -> V_140 = & V_91 ;
return F_109 ( V_139 ) ;
}
int F_110 ( struct V_141 * V_142 )
{
V_142 -> V_143 = & V_92 ;
return F_111 ( V_142 ) ;
}
int F_112 ( struct V_13 * V_14 )
{
int error , V_3 ;
if ( V_14 -> V_39 -> V_144 ) {
for ( V_3 = 0 ; V_14 -> V_39 -> V_144 [ V_3 ] ; V_3 ++ ) {
error = F_92 ( & V_14 -> V_145 ,
V_14 -> V_39 -> V_144 [ V_3 ] ) ;
if ( error )
return error ;
}
}
F_113 ( & V_14 -> V_146 ) ;
F_85 ( & V_14 -> V_146 ) ;
return 0 ;
}
void F_114 ( struct V_58 * V_59 )
{
unsigned long V_52 ;
struct V_13 * V_14 = V_59 -> V_70 ;
struct V_64 * V_65 = V_59 -> V_121 ;
F_115 ( & V_59 -> V_60 ) ;
V_59 -> V_60 . V_140 = & V_91 ;
V_59 -> V_60 . type = & V_84 ;
F_116 ( & V_59 -> V_60 , L_26 ,
V_59 -> V_70 -> V_147 , V_59 -> V_20 , V_59 -> V_21 , V_59 -> V_22 ) ;
F_115 ( & V_59 -> V_124 ) ;
V_59 -> V_124 . V_63 = F_117 ( & V_59 -> V_60 ) ;
V_59 -> V_124 . V_143 = & V_92 ;
F_116 ( & V_59 -> V_124 , L_26 ,
V_59 -> V_70 -> V_147 , V_59 -> V_20 , V_59 -> V_21 , V_59 -> V_22 ) ;
V_59 -> V_148 = V_65 -> V_148 ;
F_118 ( & V_59 -> V_60 ) ;
F_22 ( V_14 -> V_55 , V_52 ) ;
F_119 ( & V_59 -> V_73 , & V_65 -> V_149 ) ;
F_119 ( & V_59 -> V_72 , & V_14 -> V_150 ) ;
F_24 ( V_14 -> V_55 , V_52 ) ;
}
int F_120 ( const struct V_27 * V_28 )
{
return V_28 -> type == & V_84 ;
}
