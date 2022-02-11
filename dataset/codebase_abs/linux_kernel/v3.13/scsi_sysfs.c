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
return sprintf ( V_31 , L_14 , V_14 -> V_49 / V_50 ) ;
}
static T_1
F_20 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_13 * V_14 = F_9 ( V_28 ) ;
int V_46 = - V_24 ;
int V_51 ;
unsigned long V_52 ;
if ( V_14 -> V_25 && V_14 -> V_25 -> V_53 )
return V_46 ;
if ( sscanf ( V_31 , L_14 , & V_51 ) == 1 ) {
F_21 ( V_14 -> V_54 , V_52 ) ;
if ( F_22 ( V_14 ) )
V_46 = - V_55 ;
else {
V_14 -> V_49 = V_51 * V_50 ;
V_46 = V_32 ;
}
F_23 ( V_14 -> V_54 , V_52 ) ;
}
return V_46 ;
}
static void F_24 ( struct V_27 * V_56 )
{
struct V_57 * V_58 ;
V_58 = F_25 ( V_56 ) ;
F_26 ( & V_58 -> V_59 ) ;
}
static void F_27 ( struct V_60 * V_61 )
{
struct V_57 * V_58 ;
struct V_27 * V_62 ;
struct V_63 * V_64 ;
struct V_65 * V_66 , * V_67 ;
unsigned long V_52 ;
V_58 = F_28 ( V_61 , struct V_57 , V_68 . V_61 ) ;
V_62 = V_58 -> V_59 . V_62 ;
V_64 = F_29 ( V_62 ) ;
F_21 ( V_58 -> V_69 -> V_54 , V_52 ) ;
V_64 -> V_70 ++ ;
F_30 ( & V_58 -> V_71 ) ;
F_30 ( & V_58 -> V_72 ) ;
F_30 ( & V_58 -> V_73 ) ;
F_23 ( V_58 -> V_69 -> V_54 , V_52 ) ;
F_31 ( & V_58 -> V_74 ) ;
F_32 (this, tmp, &sdev->event_list) {
struct V_75 * V_76 ;
V_76 = F_33 ( V_66 , struct V_75 , V_77 ) ;
F_30 ( & V_76 -> V_77 ) ;
F_34 ( V_76 ) ;
}
F_35 ( V_58 -> V_78 ) ;
V_58 -> V_78 = NULL ;
F_36 ( V_63 ( V_58 ) ) ;
F_34 ( V_58 -> V_79 ) ;
F_34 ( V_58 ) ;
if ( V_62 )
F_26 ( V_62 ) ;
}
static void F_37 ( struct V_27 * V_28 )
{
struct V_57 * V_80 = F_38 ( V_28 ) ;
F_39 ( F_27 ,
& V_80 -> V_68 ) ;
}
static int F_40 ( struct V_27 * V_28 , struct V_81 * V_82 )
{
struct V_57 * V_80 ;
if ( V_28 -> type != & V_83 )
return 0 ;
V_80 = F_38 ( V_28 ) ;
if ( V_80 -> V_84 )
return 0 ;
return ( V_80 -> V_85 == V_86 ) ? 1 : 0 ;
}
static int F_41 ( struct V_27 * V_28 , struct V_87 * V_88 )
{
struct V_57 * V_58 ;
if ( V_28 -> type != & V_83 )
return 0 ;
V_58 = F_38 ( V_28 ) ;
F_42 ( V_88 , L_15 V_89 , V_58 -> type ) ;
return 0 ;
}
int F_43 ( void )
{
int error ;
error = F_44 ( & V_90 ) ;
if ( ! error ) {
error = F_45 ( & V_91 ) ;
if ( error )
F_46 ( & V_90 ) ;
}
return error ;
}
void F_47 ( void )
{
F_48 ( & V_91 ) ;
F_46 ( & V_90 ) ;
}
static T_1
F_49 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_57 * V_58 ;
V_58 = F_38 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_14 , V_58 -> V_78 -> V_92 / V_50 ) ;
}
static T_1
F_50 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_57 * V_58 ;
int V_93 ;
V_58 = F_38 ( V_28 ) ;
sscanf ( V_31 , L_14 , & V_93 ) ;
F_51 ( V_58 -> V_78 , V_93 * V_50 ) ;
return V_32 ;
}
static T_1
F_52 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_57 * V_58 ;
V_58 = F_38 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_16 , V_58 -> V_94 / V_50 ) ;
}
static T_1
F_53 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_57 * V_58 ;
unsigned int V_94 ;
int V_95 ;
if ( ! F_54 ( V_96 ) )
return - V_97 ;
V_58 = F_38 ( V_28 ) ;
V_95 = F_55 ( V_31 , 10 , & V_94 ) ;
if ( V_95 )
return V_95 ;
V_58 -> V_94 = V_94 * V_50 ;
return V_32 ;
}
static T_1
F_56 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
F_57 ( V_28 ) ;
return V_32 ;
}
static void F_58 ( struct V_27 * V_28 )
{
F_59 ( F_38 ( V_28 ) ) ;
}
static T_1
F_60 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
int V_98 ;
V_98 = F_61 ( V_28 , F_58 ) ;
if ( V_98 )
V_32 = V_98 ;
return V_32 ;
}
static T_1
F_62 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
int V_3 ;
struct V_57 * V_58 = F_38 ( V_28 ) ;
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
if ( F_63 ( V_58 , V_2 ) )
return - V_24 ;
return V_32 ;
}
static T_1
F_64 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_57 * V_58 = F_38 ( V_28 ) ;
const char * V_4 = F_1 ( V_58 -> V_99 ) ;
if ( ! V_4 )
return - V_24 ;
return snprintf ( V_31 , 20 , L_3 , V_4 ) ;
}
static T_1
F_65 ( struct V_27 * V_28 , struct V_29 * V_30 ,
char * V_31 )
{
struct V_57 * V_58 = F_38 ( V_28 ) ;
const char * V_4 = L_17 ;
if ( V_58 -> V_100 )
V_4 = L_18 ;
else if ( V_58 -> V_101 )
V_4 = L_19 ;
return snprintf ( V_31 , 20 , L_3 , V_4 ) ;
}
static T_1
F_66 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
return snprintf ( V_31 , 20 , L_14 , ( int ) sizeof( V_102 ) * 8 ) ;
}
static T_1
F_67 ( struct V_27 * V_28 , struct V_29 * V_30 , char * V_31 )
{
struct V_57 * V_58 ;
V_58 = F_38 ( V_28 ) ;
return snprintf ( V_31 , 20 , V_89 L_10 , V_58 -> type ) ;
}
static T_1
F_68 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
int V_103 , V_104 ;
struct V_57 * V_58 = F_38 ( V_28 ) ;
struct V_44 * V_45 = V_58 -> V_69 -> V_39 ;
if ( ! V_45 -> V_105 )
return - V_24 ;
V_103 = F_5 ( V_31 , NULL , 0 ) ;
if ( V_103 < 1 )
return - V_24 ;
V_104 = V_45 -> V_105 ( V_58 , V_103 ,
V_106 ) ;
if ( V_104 < 0 )
return V_104 ;
V_58 -> V_107 = V_58 -> V_108 ;
return V_32 ;
}
static T_1
F_69 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
char * V_31 )
{
struct V_57 * V_58 ;
V_58 = F_38 ( V_28 ) ;
return snprintf ( V_31 , 20 , L_16 ,
F_70 ( V_58 -> V_109 ) ) ;
}
static T_1
F_71 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_57 * V_58 = F_38 ( V_28 ) ;
unsigned long V_110 ;
if ( F_72 ( V_31 , 10 , & V_110 ) )
return - V_24 ;
V_58 -> V_109 = F_73 ( V_110 ) ;
return V_110 ;
}
static T_1
F_74 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const char * V_31 , T_2 V_32 )
{
struct V_57 * V_58 = F_38 ( V_28 ) ;
struct V_44 * V_45 = V_58 -> V_69 -> V_39 ;
int V_111 = 0 , V_104 ;
int V_112 = F_75 ( V_58 ) ;
if ( ! V_58 -> V_113 || ! V_45 -> V_114 )
return - V_24 ;
if ( strncmp ( V_31 , L_18 , 7 ) == 0 )
V_111 = V_115 ;
else if ( strncmp ( V_31 , L_19 , 6 ) == 0 )
V_111 = V_116 ;
else if ( strncmp ( V_31 , L_17 , 4 ) != 0 )
return - V_24 ;
if ( V_111 == V_112 )
return V_32 ;
V_104 = V_45 -> V_114 ( V_58 , V_111 ) ;
if ( V_104 < 0 )
return V_104 ;
return V_32 ;
}
static int F_76 ( struct V_63 * V_64 )
{
int error ;
if ( V_64 -> V_2 != V_117 )
return 0 ;
error = F_77 ( & V_64 -> V_28 ) ;
if ( error ) {
F_78 ( & V_64 -> V_28 , L_20 , error ) ;
return error ;
}
F_79 ( & V_64 -> V_28 ) ;
V_64 -> V_2 = V_118 ;
F_80 ( & V_64 -> V_28 ) ;
F_81 ( & V_64 -> V_28 ) ;
F_82 ( & V_64 -> V_28 ) ;
return 0 ;
}
int F_83 ( struct V_57 * V_58 )
{
int error , V_3 ;
struct V_78 * V_119 = V_58 -> V_78 ;
struct V_63 * V_64 = V_58 -> V_120 ;
error = F_63 ( V_58 , V_121 ) ;
if ( error )
return error ;
error = F_76 ( V_64 ) ;
if ( error )
return error ;
F_84 ( & V_64 -> V_28 ) ;
F_82 ( & V_58 -> V_59 ) ;
F_85 ( V_64 ) ;
F_80 ( & V_58 -> V_59 ) ;
F_86 ( & V_58 -> V_59 ) ;
F_81 ( & V_58 -> V_59 ) ;
F_87 ( V_64 ) ;
F_88 ( V_58 ) ;
error = F_77 ( & V_58 -> V_59 ) ;
if ( error ) {
F_89 ( V_122 , V_58 ,
L_21 , error ) ;
return error ;
}
F_82 ( & V_58 -> V_123 ) ;
error = F_77 ( & V_58 -> V_123 ) ;
if ( error ) {
F_89 ( V_122 , V_58 ,
L_22 , error ) ;
F_90 ( & V_58 -> V_59 ) ;
return error ;
}
F_79 ( & V_58 -> V_59 ) ;
V_58 -> V_124 = 1 ;
if ( V_58 -> V_69 -> V_39 -> V_105 ) {
error = F_91 ( & V_58 -> V_59 ,
& V_125 ) ;
error = F_91 ( & V_58 -> V_59 ,
& V_126 ) ;
}
else
error = F_91 ( & V_58 -> V_59 , & V_127 ) ;
if ( error )
return error ;
if ( V_58 -> V_69 -> V_39 -> V_114 )
error = F_91 ( & V_58 -> V_59 , & V_128 ) ;
else
error = F_91 ( & V_58 -> V_59 , & V_129 ) ;
if ( error )
return error ;
error = F_92 ( V_119 , & V_58 -> V_59 , NULL , NULL ) ;
if ( error )
F_89 ( V_122 , V_58 ,
L_23 , error ) ;
if ( V_58 -> V_69 -> V_39 -> V_130 ) {
for ( V_3 = 0 ; V_58 -> V_69 -> V_39 -> V_130 [ V_3 ] ; V_3 ++ ) {
error = F_91 ( & V_58 -> V_59 ,
V_58 -> V_69 -> V_39 -> V_130 [ V_3 ] ) ;
if ( error )
return error ;
}
}
return error ;
}
void F_93 ( struct V_57 * V_58 )
{
struct V_27 * V_28 = & V_58 -> V_59 ;
if ( V_58 -> V_124 ) {
if ( F_63 ( V_58 , V_131 ) != 0 )
return;
F_94 ( V_58 -> V_78 ) ;
F_95 ( & V_58 -> V_123 ) ;
F_96 ( V_28 ) ;
F_90 ( V_28 ) ;
} else
F_26 ( & V_58 -> V_123 ) ;
F_63 ( V_58 , V_132 ) ;
F_97 ( V_58 -> V_78 ) ;
F_31 ( & V_58 -> V_133 ) ;
if ( V_58 -> V_69 -> V_39 -> V_134 )
V_58 -> V_69 -> V_39 -> V_134 ( V_58 ) ;
F_98 ( V_28 ) ;
F_26 ( V_28 ) ;
}
void F_59 ( struct V_57 * V_58 )
{
struct V_13 * V_14 = V_58 -> V_69 ;
F_99 ( & V_14 -> V_135 ) ;
F_93 ( V_58 ) ;
F_100 ( & V_14 -> V_135 ) ;
}
static void F_101 ( struct V_63 * V_64 )
{
struct V_13 * V_14 = F_102 ( V_64 -> V_28 . V_62 ) ;
unsigned long V_52 ;
struct V_57 * V_58 ;
F_21 ( V_14 -> V_54 , V_52 ) ;
V_136:
F_103 (sdev, &shost->__devices, siblings) {
if ( V_58 -> V_20 != V_64 -> V_20 ||
V_58 -> V_21 != V_64 -> V_21 ||
F_104 ( V_58 ) )
continue;
F_23 ( V_14 -> V_54 , V_52 ) ;
F_59 ( V_58 ) ;
F_105 ( V_58 ) ;
F_21 ( V_14 -> V_54 , V_52 ) ;
goto V_136;
}
F_23 ( V_14 -> V_54 , V_52 ) ;
}
void F_106 ( struct V_27 * V_28 )
{
struct V_13 * V_14 = F_102 ( V_28 -> V_62 ) ;
struct V_63 * V_64 , * V_11 = NULL ;
unsigned long V_52 ;
F_21 ( V_14 -> V_54 , V_52 ) ;
F_103 (starget, &shost->__targets, siblings) {
if ( V_64 -> V_2 == V_137 )
continue;
if ( V_64 -> V_28 . V_62 == V_28 || & V_64 -> V_28 == V_28 ) {
V_64 -> V_70 ++ ;
F_23 ( V_14 -> V_54 , V_52 ) ;
if ( V_11 )
F_36 ( V_11 ) ;
V_11 = V_64 ;
F_101 ( V_64 ) ;
F_21 ( V_14 -> V_54 , V_52 ) ;
}
}
F_23 ( V_14 -> V_54 , V_52 ) ;
if ( V_11 )
F_36 ( V_11 ) ;
}
int F_107 ( struct V_81 * V_138 )
{
V_138 -> V_139 = & V_90 ;
return F_108 ( V_138 ) ;
}
int F_109 ( struct V_140 * V_141 )
{
V_141 -> V_142 = & V_91 ;
return F_110 ( V_141 ) ;
}
int F_111 ( struct V_13 * V_14 )
{
int error , V_3 ;
if ( V_14 -> V_39 -> V_143 ) {
for ( V_3 = 0 ; V_14 -> V_39 -> V_143 [ V_3 ] ; V_3 ++ ) {
error = F_91 ( & V_14 -> V_144 ,
V_14 -> V_39 -> V_143 [ V_3 ] ) ;
if ( error )
return error ;
}
}
F_112 ( & V_14 -> V_145 ) ;
F_84 ( & V_14 -> V_145 ) ;
return 0 ;
}
void F_113 ( struct V_57 * V_58 )
{
unsigned long V_52 ;
struct V_13 * V_14 = V_58 -> V_69 ;
struct V_63 * V_64 = V_58 -> V_120 ;
F_114 ( & V_58 -> V_59 ) ;
V_58 -> V_59 . V_139 = & V_90 ;
V_58 -> V_59 . type = & V_83 ;
F_115 ( & V_58 -> V_59 , L_24 ,
V_58 -> V_69 -> V_146 , V_58 -> V_20 , V_58 -> V_21 , V_58 -> V_22 ) ;
F_114 ( & V_58 -> V_123 ) ;
V_58 -> V_123 . V_62 = F_116 ( & V_58 -> V_59 ) ;
V_58 -> V_123 . V_142 = & V_91 ;
F_115 ( & V_58 -> V_123 , L_24 ,
V_58 -> V_69 -> V_146 , V_58 -> V_20 , V_58 -> V_21 , V_58 -> V_22 ) ;
V_58 -> V_147 = V_64 -> V_147 ;
F_117 ( & V_58 -> V_59 ) ;
F_21 ( V_14 -> V_54 , V_52 ) ;
F_118 ( & V_58 -> V_72 , & V_64 -> V_148 ) ;
F_118 ( & V_58 -> V_71 , & V_14 -> V_149 ) ;
F_23 ( V_14 -> V_54 , V_52 ) ;
}
int F_119 ( const struct V_27 * V_28 )
{
return V_28 -> type == & V_83 ;
}
