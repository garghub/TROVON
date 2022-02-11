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
if ( V_14 -> V_25 &&
( V_14 -> V_25 -> V_53 ||
! V_14 -> V_39 -> V_54 ) )
return V_46 ;
if ( ! strncmp ( V_31 , L_14 , strlen ( L_14 ) ) )
V_51 = - 1 ;
else {
V_46 = F_21 ( V_31 , 10 , & V_51 ) ;
if ( V_46 )
return V_46 ;
if ( V_51 * V_50 > V_55 )
return - V_24 ;
}
F_22 ( V_14 -> V_56 , V_52 ) ;
if ( F_23 ( V_14 ) )
V_46 = - V_57 ;
else {
if ( V_51 == - 1 )
V_14 -> V_49 = - 1 ;
else
V_14 -> V_49 = V_51 * V_50 ;
V_46 = V_32 ;
}
F_24 ( V_14 -> V_56 , V_52 ) ;
return V_46 ;
}
static void F_25 ( struct V_27 * V_58 )
{
struct V_59 * V_60 ;
V_60 = F_26 ( V_58 ) ;
F_27 ( & V_60 -> V_61 ) ;
}
static void F_28 ( struct V_62 * V_63 )
{
struct V_59 * V_60 ;
struct V_27 * V_64 ;
struct V_65 * V_66 , * V_67 ;
unsigned long V_52 ;
V_60 = F_29 ( V_63 , struct V_59 , V_68 . V_63 ) ;
V_64 = V_60 -> V_61 . V_64 ;
F_22 ( V_60 -> V_69 -> V_56 , V_52 ) ;
F_30 ( & V_60 -> V_70 ) ;
F_30 ( & V_60 -> V_71 ) ;
F_30 ( & V_60 -> V_72 ) ;
F_24 ( V_60 -> V_69 -> V_56 , V_52 ) ;
F_31 ( & V_60 -> V_73 ) ;
F_32 (this, tmp, &sdev->event_list) {
struct V_74 * V_75 ;
V_75 = F_33 ( V_66 , struct V_74 , V_76 ) ;
F_30 ( & V_75 -> V_76 ) ;
F_34 ( V_75 ) ;
}
F_35 ( V_60 -> V_77 ) ;
V_60 -> V_77 = NULL ;
F_34 ( V_60 -> V_78 ) ;
F_34 ( V_60 -> V_79 ) ;
F_34 ( V_60 -> V_80 ) ;
F_34 ( V_60 ) ;
if ( V_64 )
F_27 ( V_64 ) ;
}
static void F_36 ( struct V_27 * V_28 )
{
struct V_59 * V_81 = F_37 ( V_28 ) ;
F_38 ( F_28 ,
& V_81 -> V_68 ) ;
}
static int F_39 ( struct V_27 * V_28 , struct V_82 * V_83 )
{
struct V_59 * V_81 ;
if ( V_28 -> type != & V_84 )
return 0 ;
V_81 = F_37 ( V_28 ) ;
if ( V_81 -> V_85 )
return 0 ;
return ( V_81 -> V_86 == V_87 ) ? 1 : 0 ;
}
static int F_40 ( struct V_27 * V_28 , struct V_88 * V_89 )
{
struct V_59 * V_60 ;
if ( V_28 -> type != & V_84 )
return 0 ;
V_60 = F_37 ( V_28 ) ;
F_41 ( V_89 , L_17 V_90 , V_60 -> type ) ;
return 0 ;
}
int F_42 ( void )
{
int error ;
error = F_43 ( & V_91 ) ;
if ( ! error ) {
error = F_44 ( & V_92 ) ;
if ( error )
F_45 ( & V_91 ) ;
}
return error ;
}
void F_46 ( void )
{
F_47 ( & V_92 ) ;
F_45 ( & V_91 ) ;
}
static T_1
F_48 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_59 * V_60 ;
V_60 = F_37 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_18 , V_60 -> V_77 -> V_93 / V_50 ) ;
}
static T_1
F_49 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_59 * V_60 ;
int V_94 ;
V_60 = F_37 ( V_28 ) ;
sscanf ( V_31 , L_18 , & V_94 ) ;
F_50 ( V_60 -> V_77 , V_94 * V_50 ) ;
return V_32 ;
}
static T_1
F_51 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_59 * V_60 ;
V_60 = F_37 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_16 , V_60 -> V_95 / V_50 ) ;
}
static T_1
F_52 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_59 * V_60 ;
unsigned int V_95 ;
int V_96 ;
if ( ! F_53 ( V_97 ) )
return - V_98 ;
V_60 = F_37 ( V_28 ) ;
V_96 = F_54 ( V_31 , 10 , & V_95 ) ;
if ( V_96 )
return V_96 ;
V_60 -> V_95 = V_95 * V_50 ;
return V_32 ;
}
static T_1
F_55 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
F_56 ( V_28 ) ;
return V_32 ;
}
static T_1
F_57 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
if ( F_58 ( V_28 , V_30 ) )
F_59 ( F_37 ( V_28 ) ) ;
return V_32 ;
}
static T_1
F_60 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
int V_3 ;
struct V_59 * V_60 = F_37 ( V_28 ) ;
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
if ( F_61 ( V_60 , V_2 ) )
return - V_24 ;
return V_32 ;
}
static T_1
F_62 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_59 * V_60 = F_37 ( V_28 ) ;
const char * V_4 = F_1 ( V_60 -> V_99 ) ;
if ( ! V_4 )
return - V_24 ;
return snprintf ( V_31 , 20 , L_3 , V_4 ) ;
}
static T_1
F_63 ( struct V_27 * V_28 , struct V_29 * V_30 ,
char * V_31 )
{
struct V_59 * V_60 = F_37 ( V_28 ) ;
const char * V_4 = L_19 ;
if ( V_60 -> V_100 )
V_4 = L_20 ;
else if ( V_60 -> V_101 )
V_4 = L_21 ;
return snprintf ( V_31 , 20 , L_3 , V_4 ) ;
}
static T_1
F_64 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_59 * V_60 = F_37 ( V_28 ) ;
struct V_44 * V_45 = V_60 -> V_69 -> V_39 ;
int V_102 = 0 , V_103 ;
int V_104 = F_65 ( V_60 ) ;
if ( ! V_60 -> V_105 || ! V_45 -> V_106 )
return - V_24 ;
if ( strncmp ( V_31 , L_20 , 7 ) == 0 )
V_102 = V_107 ;
else if ( strncmp ( V_31 , L_21 , 6 ) == 0 )
V_102 = V_108 ;
else if ( strncmp ( V_31 , L_19 , 4 ) != 0 )
return - V_24 ;
if ( V_102 == V_104 )
return V_32 ;
V_103 = V_45 -> V_106 ( V_60 , V_102 ) ;
if ( V_103 < 0 )
return V_103 ;
return V_32 ;
}
static T_1
F_66 ( struct V_27 * V_28 , struct V_29 * V_30 ,
char * V_31 )
{
return snprintf ( V_31 , 20 , L_18 , ( int ) sizeof( V_109 ) * 8 ) ;
}
static T_1
F_67 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_59 * V_60 ;
V_60 = F_37 ( V_28 ) ;
return snprintf ( V_31 , 20 , V_90 L_10 , V_60 -> type ) ;
}
static T_1
F_68 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
int V_110 , V_103 ;
struct V_59 * V_60 = F_37 ( V_28 ) ;
struct V_44 * V_45 = V_60 -> V_69 -> V_39 ;
if ( ! V_45 -> V_111 )
return - V_24 ;
V_110 = F_5 ( V_31 , NULL , 0 ) ;
if ( V_110 < 1 )
return - V_24 ;
V_103 = V_45 -> V_111 ( V_60 , V_110 ,
V_112 ) ;
if ( V_103 < 0 )
return V_103 ;
V_60 -> V_113 = V_60 -> V_114 ;
return V_32 ;
}
static T_1
F_69 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
char * V_31 )
{
struct V_59 * V_60 ;
V_60 = F_37 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_16 ,
F_70 ( V_60 -> V_115 ) ) ;
}
static T_1
F_71 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_59 * V_60 = F_37 ( V_28 ) ;
unsigned long V_116 ;
if ( F_72 ( V_31 , 10 , & V_116 ) )
return - V_24 ;
V_60 -> V_115 = F_73 ( V_116 ) ;
return V_116 ;
}
static T_3 F_74 ( struct V_117 * V_118 ,
struct V_119 * V_30 , int V_3 )
{
struct V_27 * V_28 = F_29 ( V_118 , struct V_27 , V_118 ) ;
struct V_59 * V_60 = F_37 ( V_28 ) ;
if ( V_30 == & V_120 . V_30 &&
! V_60 -> V_69 -> V_39 -> V_111 )
return V_121 ;
if ( V_30 == & V_122 . V_30 &&
! V_60 -> V_69 -> V_39 -> V_111 )
return 0 ;
if ( V_30 == & V_123 . V_30 &&
! V_60 -> V_69 -> V_39 -> V_106 )
return V_121 ;
return V_30 -> V_35 ;
}
static int F_75 ( struct V_124 * V_125 )
{
int error ;
if ( V_125 -> V_2 != V_126 )
return 0 ;
error = F_76 ( & V_125 -> V_28 ) ;
if ( error ) {
F_77 ( & V_125 -> V_28 , L_22 , error ) ;
return error ;
}
F_78 ( & V_125 -> V_28 ) ;
V_125 -> V_2 = V_127 ;
F_79 ( & V_125 -> V_28 ) ;
F_80 ( & V_125 -> V_28 ) ;
F_81 ( & V_125 -> V_28 ) ;
return 0 ;
}
int F_82 ( struct V_59 * V_60 )
{
int error , V_3 ;
struct V_77 * V_128 = V_60 -> V_77 ;
struct V_124 * V_125 = V_60 -> V_129 ;
error = F_61 ( V_60 , V_130 ) ;
if ( error )
return error ;
error = F_75 ( V_125 ) ;
if ( error )
return error ;
F_83 ( & V_125 -> V_28 ) ;
F_81 ( & V_60 -> V_61 ) ;
F_84 ( V_125 ) ;
F_79 ( & V_60 -> V_61 ) ;
F_85 ( & V_60 -> V_61 ) ;
F_80 ( & V_60 -> V_61 ) ;
F_86 ( V_125 ) ;
F_87 ( V_60 ) ;
error = F_76 ( & V_60 -> V_61 ) ;
if ( error ) {
F_88 ( V_131 , V_60 ,
L_23 , error ) ;
return error ;
}
F_81 ( & V_60 -> V_132 ) ;
error = F_76 ( & V_60 -> V_132 ) ;
if ( error ) {
F_88 ( V_131 , V_60 ,
L_24 , error ) ;
F_89 ( & V_60 -> V_61 ) ;
return error ;
}
F_78 ( & V_60 -> V_61 ) ;
V_60 -> V_133 = 1 ;
error = F_90 ( V_128 , & V_60 -> V_61 , NULL , NULL ) ;
if ( error )
F_88 ( V_131 , V_60 ,
L_25 , error ) ;
if ( V_60 -> V_69 -> V_39 -> V_134 ) {
for ( V_3 = 0 ; V_60 -> V_69 -> V_39 -> V_134 [ V_3 ] ; V_3 ++ ) {
error = F_91 ( & V_60 -> V_61 ,
V_60 -> V_69 -> V_39 -> V_134 [ V_3 ] ) ;
if ( error )
return error ;
}
}
return error ;
}
void F_92 ( struct V_59 * V_60 )
{
struct V_27 * V_28 = & V_60 -> V_61 ;
if ( V_60 -> V_133 ) {
if ( F_61 ( V_60 , V_135 ) != 0 )
return;
F_93 ( V_60 -> V_77 ) ;
F_94 ( & V_60 -> V_132 ) ;
F_95 ( V_28 ) ;
F_89 ( V_28 ) ;
} else
F_27 ( & V_60 -> V_132 ) ;
F_61 ( V_60 , V_136 ) ;
F_96 ( V_60 -> V_77 ) ;
F_31 ( & V_60 -> V_137 ) ;
if ( V_60 -> V_69 -> V_39 -> V_138 )
V_60 -> V_69 -> V_39 -> V_138 ( V_60 ) ;
F_97 ( V_28 ) ;
F_98 ( V_124 ( V_60 ) ) ;
F_27 ( V_28 ) ;
}
void F_59 ( struct V_59 * V_60 )
{
struct V_13 * V_14 = V_60 -> V_69 ;
F_99 ( & V_14 -> V_139 ) ;
F_92 ( V_60 ) ;
F_100 ( & V_14 -> V_139 ) ;
}
static void F_101 ( struct V_124 * V_125 )
{
struct V_13 * V_14 = F_102 ( V_125 -> V_28 . V_64 ) ;
unsigned long V_52 ;
struct V_59 * V_60 ;
F_22 ( V_14 -> V_56 , V_52 ) ;
V_140:
F_103 (sdev, &shost->__devices, siblings) {
if ( V_60 -> V_20 != V_125 -> V_20 ||
V_60 -> V_21 != V_125 -> V_21 ||
F_104 ( V_60 ) )
continue;
F_24 ( V_14 -> V_56 , V_52 ) ;
F_59 ( V_60 ) ;
F_105 ( V_60 ) ;
F_22 ( V_14 -> V_56 , V_52 ) ;
goto V_140;
}
F_24 ( V_14 -> V_56 , V_52 ) ;
}
void F_106 ( struct V_27 * V_28 )
{
struct V_13 * V_14 = F_102 ( V_28 -> V_64 ) ;
struct V_124 * V_125 , * V_11 = NULL ;
unsigned long V_52 ;
F_22 ( V_14 -> V_56 , V_52 ) ;
F_103 (starget, &shost->__targets, siblings) {
if ( V_125 -> V_2 == V_141 )
continue;
if ( V_125 -> V_28 . V_64 == V_28 || & V_125 -> V_28 == V_28 ) {
F_107 ( & V_125 -> V_142 ) ;
F_24 ( V_14 -> V_56 , V_52 ) ;
if ( V_11 )
F_98 ( V_11 ) ;
V_11 = V_125 ;
F_101 ( V_125 ) ;
F_22 ( V_14 -> V_56 , V_52 ) ;
}
}
F_24 ( V_14 -> V_56 , V_52 ) ;
if ( V_11 )
F_98 ( V_11 ) ;
}
int F_108 ( struct V_82 * V_143 )
{
V_143 -> V_144 = & V_91 ;
return F_109 ( V_143 ) ;
}
int F_110 ( struct V_145 * V_146 )
{
V_146 -> V_147 = & V_92 ;
return F_111 ( V_146 ) ;
}
int F_112 ( struct V_13 * V_14 )
{
int error , V_3 ;
if ( V_14 -> V_39 -> V_148 ) {
for ( V_3 = 0 ; V_14 -> V_39 -> V_148 [ V_3 ] ; V_3 ++ ) {
error = F_91 ( & V_14 -> V_149 ,
V_14 -> V_39 -> V_148 [ V_3 ] ) ;
if ( error )
return error ;
}
}
F_113 ( & V_14 -> V_150 ) ;
F_83 ( & V_14 -> V_150 ) ;
return 0 ;
}
void F_114 ( struct V_59 * V_60 )
{
unsigned long V_52 ;
struct V_13 * V_14 = V_60 -> V_69 ;
struct V_124 * V_125 = V_60 -> V_129 ;
F_115 ( & V_60 -> V_61 ) ;
V_60 -> V_61 . V_144 = & V_91 ;
V_60 -> V_61 . type = & V_84 ;
F_116 ( & V_60 -> V_61 , L_26 ,
V_60 -> V_69 -> V_151 , V_60 -> V_20 , V_60 -> V_21 , V_60 -> V_22 ) ;
F_115 ( & V_60 -> V_132 ) ;
V_60 -> V_132 . V_64 = F_117 ( & V_60 -> V_61 ) ;
V_60 -> V_132 . V_147 = & V_92 ;
F_116 ( & V_60 -> V_132 , L_26 ,
V_60 -> V_69 -> V_151 , V_60 -> V_20 , V_60 -> V_21 , V_60 -> V_22 ) ;
V_60 -> V_152 = V_125 -> V_152 ;
F_118 ( & V_60 -> V_61 ) ;
F_22 ( V_14 -> V_56 , V_52 ) ;
F_119 ( & V_60 -> V_71 , & V_125 -> V_153 ) ;
F_119 ( & V_60 -> V_70 , & V_14 -> V_154 ) ;
F_24 ( V_14 -> V_56 , V_52 ) ;
F_107 ( & V_125 -> V_142 ) ;
}
int F_120 ( const struct V_27 * V_28 )
{
return V_28 -> type == & V_84 ;
}
