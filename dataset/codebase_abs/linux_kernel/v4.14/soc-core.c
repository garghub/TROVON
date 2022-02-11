static int F_1 ( unsigned long V_1 )
{
int V_2 = 0 ;
int V_3 ;
for ( V_3 = ( sizeof V_1 * 8 ) - 1 ; V_3 >= 0 ; -- V_3 , ++ V_2 )
if ( V_1 & ( 1UL << V_3 ) )
break;
V_2 = ( sizeof V_1 * 8 ) - V_2 ;
if ( ! V_2 || ( V_2 % 8 ) )
V_2 = ( V_2 + 8 ) / 8 ;
else
V_2 /= 8 ;
return V_2 ;
}
static int F_2 ( struct V_4 * V_5 ,
unsigned int V_6 , char * V_7 , T_1 V_8 )
{
int V_9 = F_1 ( V_5 -> V_10 -> V_11 ) * 2 ;
int V_12 = V_5 -> V_10 -> V_13 * 2 ;
int V_14 ;
if ( V_9 + V_12 + 2 + 1 != V_8 )
return - V_15 ;
sprintf ( V_7 , L_1 , V_9 , V_6 ) ;
V_7 += V_9 + 2 ;
V_14 = F_3 ( V_5 , V_6 ) ;
if ( V_14 < 0 )
memset ( V_7 , 'X' , V_12 ) ;
else
sprintf ( V_7 , L_2 , V_12 , V_14 ) ;
V_7 [ V_12 ] = '\n' ;
return 0 ;
}
static T_2 F_4 ( struct V_4 * V_5 , char * V_7 ,
T_1 V_16 , T_3 V_17 )
{
int V_3 , V_18 = 1 ;
int V_9 , V_12 ;
int V_8 ;
T_1 V_19 = 0 ;
T_3 V_20 = 0 ;
V_9 = F_1 ( V_5 -> V_10 -> V_11 ) * 2 ;
V_12 = V_5 -> V_10 -> V_13 * 2 ;
V_8 = V_9 + V_12 + 2 + 1 ;
if ( ! V_5 -> V_10 -> V_11 )
return 0 ;
if ( V_5 -> V_10 -> V_21 )
V_18 = V_5 -> V_10 -> V_21 ;
for ( V_3 = 0 ; V_3 < V_5 -> V_10 -> V_11 ; V_3 += V_18 ) {
if ( V_20 >= V_17 ) {
if ( V_19 + V_8 >= V_16 - 1 )
break;
F_2 ( V_5 , V_3 , V_7 + V_19 , V_8 ) ;
V_19 += V_8 ;
}
V_20 += V_8 ;
}
V_19 = F_5 ( V_19 , V_16 - 1 ) ;
return V_19 ;
}
static T_2 F_6 ( struct V_22 * V_23 ,
struct V_24 * V_25 , char * V_7 )
{
struct V_26 * V_27 = F_7 ( V_23 ) ;
return F_4 ( V_27 -> V_5 , V_7 , V_28 , 0 ) ;
}
static T_2 F_8 ( struct V_22 * V_23 ,
struct V_24 * V_25 , char * V_7 )
{
struct V_26 * V_27 = F_7 ( V_23 ) ;
return sprintf ( V_7 , L_3 , V_27 -> V_29 ) ;
}
static T_2 F_9 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_7 , T_1 V_16 )
{
struct V_26 * V_27 = F_7 ( V_23 ) ;
int V_14 ;
V_14 = F_10 ( V_7 , 10 , & V_27 -> V_29 ) ;
if ( V_14 )
return V_14 ;
return V_16 ;
}
static T_4 F_11 ( struct V_30 * V_31 ,
struct V_32 * V_25 , int V_33 )
{
struct V_22 * V_23 = F_12 ( V_31 ) ;
struct V_26 * V_27 = F_7 ( V_23 ) ;
if ( V_25 == & V_34 . V_25 )
return V_25 -> V_35 ;
return V_27 -> V_5 ? V_25 -> V_35 : 0 ;
}
static T_2 F_13 ( struct V_36 * V_36 , char T_5 * V_37 ,
T_1 V_16 , T_3 * V_38 )
{
T_2 V_14 ;
struct V_4 * V_5 = V_36 -> V_39 ;
char * V_7 ;
if ( * V_38 < 0 || ! V_16 )
return - V_15 ;
V_7 = F_14 ( V_16 , V_40 ) ;
if ( ! V_7 )
return - V_41 ;
V_14 = F_4 ( V_5 , V_7 , V_16 , * V_38 ) ;
if ( V_14 >= 0 ) {
if ( F_15 ( V_37 , V_7 , V_14 ) ) {
F_16 ( V_7 ) ;
return - V_42 ;
}
* V_38 += V_14 ;
}
F_16 ( V_7 ) ;
return V_14 ;
}
static T_2 F_17 ( struct V_36 * V_36 ,
const char T_5 * V_37 , T_1 V_16 , T_3 * V_38 )
{
char V_7 [ 32 ] ;
T_1 V_43 ;
char * V_44 = V_7 ;
unsigned long V_6 , V_45 ;
struct V_4 * V_5 = V_36 -> V_39 ;
int V_14 ;
V_43 = F_5 ( V_16 , ( sizeof( V_7 ) - 1 ) ) ;
if ( F_18 ( V_7 , V_37 , V_43 ) )
return - V_42 ;
V_7 [ V_43 ] = 0 ;
while ( * V_44 == ' ' )
V_44 ++ ;
V_6 = F_19 ( V_44 , & V_44 , 16 ) ;
while ( * V_44 == ' ' )
V_44 ++ ;
V_14 = F_20 ( V_44 , 16 , & V_45 ) ;
if ( V_14 )
return V_14 ;
F_21 ( V_46 , V_47 ) ;
F_22 ( V_5 , V_6 , V_45 ) ;
return V_43 ;
}
static void F_23 ( struct V_48 * V_49 )
{
if ( ! V_49 -> V_50 -> V_51 )
return;
if ( V_49 -> V_52 ) {
char * V_53 ;
V_53 = F_24 ( V_40 , L_4 ,
V_49 -> V_52 , V_49 -> V_53 ) ;
if ( V_53 ) {
V_49 -> V_54 = F_25 ( V_53 ,
V_49 -> V_50 -> V_51 ) ;
F_16 ( V_53 ) ;
}
} else {
V_49 -> V_54 = F_25 ( V_49 -> V_53 ,
V_49 -> V_50 -> V_51 ) ;
}
if ( ! V_49 -> V_54 ) {
F_26 ( V_49 -> V_23 ,
L_5 ) ;
return;
}
F_27 ( F_28 ( V_49 ) ,
V_49 -> V_54 ) ;
if ( V_49 -> V_55 )
V_49 -> V_55 ( V_49 ) ;
}
static void F_29 ( struct V_48 * V_49 )
{
F_30 ( V_49 -> V_54 ) ;
}
static void F_31 ( struct V_48 * V_49 )
{
struct V_4 * V_5 = F_32 ( V_49 ) ;
struct V_56 * V_57 ;
V_57 = F_33 ( L_6 , 0644 ,
V_5 -> V_49 . V_54 ,
V_5 , & V_58 ) ;
if ( ! V_57 )
F_26 ( V_5 -> V_23 ,
L_7 ) ;
}
static T_2 F_34 ( struct V_36 * V_36 , char T_5 * V_37 ,
T_1 V_16 , T_3 * V_38 )
{
char * V_7 = F_14 ( V_28 , V_40 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_4 * V_5 ;
if ( ! V_7 )
return - V_41 ;
F_35 ( & V_59 ) ;
F_36 (codec, &codec_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_28 - V_14 , L_8 ,
V_5 -> V_49 . V_53 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_28 ) {
V_14 = V_28 ;
break;
}
}
F_37 ( & V_59 ) ;
if ( V_14 >= 0 )
V_14 = F_38 ( V_37 , V_16 , V_38 , V_7 , V_14 ) ;
F_16 ( V_7 ) ;
return V_14 ;
}
static T_2 F_39 ( struct V_36 * V_36 , char T_5 * V_37 ,
T_1 V_16 , T_3 * V_38 )
{
char * V_7 = F_14 ( V_28 , V_40 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_48 * V_49 ;
struct V_60 * V_61 ;
if ( ! V_7 )
return - V_41 ;
F_35 ( & V_59 ) ;
F_36 (component, &component_list, list) {
F_36 (dai, &component->dai_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_28 - V_14 , L_8 ,
V_61 -> V_53 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_28 ) {
V_14 = V_28 ;
break;
}
}
}
F_37 ( & V_59 ) ;
V_14 = F_38 ( V_37 , V_16 , V_38 , V_7 , V_14 ) ;
F_16 ( V_7 ) ;
return V_14 ;
}
static T_2 F_40 ( struct V_36 * V_36 ,
char T_5 * V_37 ,
T_1 V_16 , T_3 * V_38 )
{
char * V_7 = F_14 ( V_28 , V_40 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_62 * V_63 ;
if ( ! V_7 )
return - V_41 ;
F_35 ( & V_59 ) ;
F_36 (platform, &platform_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_28 - V_14 , L_8 ,
V_63 -> V_49 . V_53 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_28 ) {
V_14 = V_28 ;
break;
}
}
F_37 ( & V_59 ) ;
V_14 = F_38 ( V_37 , V_16 , V_38 , V_7 , V_14 ) ;
F_16 ( V_7 ) ;
return V_14 ;
}
static void F_41 ( struct V_64 * V_50 )
{
if ( ! V_65 )
return;
V_50 -> V_51 = F_25 ( V_50 -> V_53 ,
V_65 ) ;
if ( ! V_50 -> V_51 ) {
F_26 ( V_50 -> V_23 ,
L_9 ) ;
return;
}
V_50 -> V_66 = F_42 ( L_10 , 0644 ,
V_50 -> V_51 ,
& V_50 -> V_67 ) ;
if ( ! V_50 -> V_66 )
F_26 ( V_50 -> V_23 ,
L_11 ) ;
}
static void F_43 ( struct V_64 * V_50 )
{
F_30 ( V_50 -> V_51 ) ;
}
static void F_44 ( void )
{
V_65 = F_25 ( L_12 , NULL ) ;
if ( F_45 ( V_65 ) ) {
F_46 ( L_13 ) ;
V_65 = NULL ;
return;
}
if ( ! F_33 ( L_14 , 0444 , V_65 , NULL ,
& V_68 ) )
F_46 ( L_15 ) ;
if ( ! F_33 ( L_16 , 0444 , V_65 , NULL ,
& V_69 ) )
F_46 ( L_17 ) ;
if ( ! F_33 ( L_18 , 0444 , V_65 , NULL ,
& V_70 ) )
F_46 ( L_19 ) ;
}
static void F_47 ( void )
{
F_30 ( V_65 ) ;
}
static inline void F_23 (
struct V_48 * V_49 )
{
}
static inline void F_29 (
struct V_48 * V_49 )
{
}
static inline void F_41 ( struct V_64 * V_50 )
{
}
static inline void F_43 ( struct V_64 * V_50 )
{
}
static inline void F_44 ( void )
{
}
static inline void F_47 ( void )
{
}
static int F_48 ( struct V_26 * V_27 ,
struct V_48 * V_49 )
{
struct V_71 * V_72 ;
struct V_71 * V_73 ;
F_49 (rtd, rtdcom) {
if ( V_72 -> V_49 == V_49 )
return 0 ;
}
V_73 = F_14 ( sizeof( * V_73 ) , V_40 ) ;
if ( ! V_73 )
return - V_41 ;
V_73 -> V_49 = V_49 ;
F_50 ( & V_73 -> V_74 ) ;
F_51 ( & V_73 -> V_74 , & V_27 -> V_75 ) ;
return 0 ;
}
static void F_52 ( struct V_26 * V_27 )
{
struct V_71 * V_76 , * V_77 ;
F_53 (rtd, rtdcom1, rtdcom2)
F_16 ( V_76 ) ;
F_50 ( & V_27 -> V_75 ) ;
}
struct V_48 * F_54 ( struct V_26 * V_27 ,
const char * V_78 )
{
struct V_71 * V_72 ;
F_49 (rtd, rtdcom) {
if ( ( V_72 -> V_49 -> V_10 -> V_53 == V_78 ) ||
strcmp ( V_72 -> V_49 -> V_10 -> V_53 , V_78 ) == 0 )
return V_72 -> V_49 ;
}
return NULL ;
}
struct V_79 * F_55 ( struct V_64 * V_50 ,
const char * V_80 , int V_81 )
{
struct V_26 * V_27 ;
F_36 (rtd, &card->rtd_list, list) {
if ( V_27 -> V_80 -> V_82 &&
! strcmp ( V_27 -> V_80 -> V_53 , V_80 ) )
return V_27 -> V_83 -> V_84 [ V_81 ] . V_85 ;
}
F_56 ( V_50 -> V_23 , L_20 , V_80 ) ;
return NULL ;
}
static struct V_26 * F_57 (
struct V_64 * V_50 , struct V_86 * V_80 )
{
struct V_26 * V_27 ;
V_27 = F_58 ( sizeof( struct V_26 ) , V_40 ) ;
if ( ! V_27 )
return NULL ;
F_50 ( & V_27 -> V_75 ) ;
V_27 -> V_50 = V_50 ;
V_27 -> V_80 = V_80 ;
V_27 -> V_87 = F_58 ( sizeof( struct V_60 * ) *
V_80 -> V_88 ,
V_40 ) ;
if ( ! V_27 -> V_87 ) {
F_16 ( V_27 ) ;
return NULL ;
}
return V_27 ;
}
static void F_59 ( struct V_26 * V_27 )
{
if ( V_27 && V_27 -> V_87 )
F_16 ( V_27 -> V_87 ) ;
F_52 ( V_27 ) ;
F_16 ( V_27 ) ;
}
static void F_60 ( struct V_64 * V_50 ,
struct V_26 * V_27 )
{
F_51 ( & V_27 -> V_74 , & V_50 -> V_89 ) ;
V_27 -> V_90 = V_50 -> V_91 ;
V_50 -> V_91 ++ ;
}
static void F_61 ( struct V_64 * V_50 )
{
struct V_26 * V_27 , * V_92 ;
F_62 (rtd, _rtd, &card->rtd_list, list) {
F_63 ( & V_27 -> V_74 ) ;
F_59 ( V_27 ) ;
}
V_50 -> V_91 = 0 ;
}
struct V_26 * F_64 ( struct V_64 * V_50 ,
const char * V_80 )
{
struct V_26 * V_27 ;
F_36 (rtd, &card->rtd_list, list) {
if ( ! strcmp ( V_27 -> V_80 -> V_53 , V_80 ) )
return V_27 ;
}
F_56 ( V_50 -> V_23 , L_21 , V_80 ) ;
return NULL ;
}
static void F_65 ( struct V_93 * V_94 )
{
}
int F_66 ( struct V_22 * V_23 )
{
struct V_64 * V_50 = F_7 ( V_23 ) ;
struct V_48 * V_49 ;
struct V_26 * V_27 ;
int V_3 ;
if ( ! V_50 -> V_95 )
return 0 ;
F_67 ( V_50 -> V_96 , V_97 ) ;
F_68 ( V_50 -> V_96 , V_98 ) ;
F_36 (rtd, &card->rtd_list, list) {
if ( V_27 -> V_80 -> V_99 )
continue;
for ( V_3 = 0 ; V_3 < V_27 -> V_88 ; V_3 ++ ) {
struct V_60 * V_61 = V_27 -> V_87 [ V_3 ] ;
struct V_100 * V_101 = V_61 -> V_10 ;
if ( V_101 -> V_102 -> V_103 && V_61 -> V_104 )
V_101 -> V_102 -> V_103 ( V_61 , 1 ) ;
}
}
F_36 (rtd, &card->rtd_list, list) {
if ( V_27 -> V_80 -> V_99 )
continue;
F_69 ( V_27 -> V_83 ) ;
}
if ( V_50 -> V_105 )
V_50 -> V_105 ( V_50 ) ;
F_36 (rtd, &card->rtd_list, list) {
struct V_60 * V_106 = V_27 -> V_106 ;
if ( V_27 -> V_80 -> V_99 )
continue;
if ( V_106 -> V_10 -> V_107 && ! V_106 -> V_10 -> V_108 )
V_106 -> V_10 -> V_107 ( V_106 ) ;
}
F_36 (rtd, &card->rtd_list, list)
F_70 ( & V_27 -> V_109 ) ;
F_36 (rtd, &card->rtd_list, list) {
if ( V_27 -> V_80 -> V_99 )
continue;
F_71 ( V_27 ,
V_110 ,
V_111 ) ;
F_71 ( V_27 ,
V_112 ,
V_111 ) ;
}
F_72 ( V_50 ) ;
F_73 ( & V_50 -> V_113 ) ;
F_36 (component, &card->component_dev_list, card_list) {
struct V_114 * V_113 = F_28 ( V_49 ) ;
if ( ! V_49 -> V_115 ) {
switch ( F_74 ( V_113 ) ) {
case V_116 :
if ( V_113 -> V_117 ) {
F_56 ( V_49 -> V_23 ,
L_22 ) ;
break;
}
case V_118 :
if ( V_49 -> V_107 )
V_49 -> V_107 ( V_49 ) ;
V_49 -> V_115 = 1 ;
if ( V_49 -> V_119 )
F_75 ( V_49 -> V_119 ) ;
F_76 ( V_49 -> V_23 ) ;
break;
default:
F_56 ( V_49 -> V_23 ,
L_23 ) ;
break;
}
}
}
F_36 (rtd, &card->rtd_list, list) {
struct V_60 * V_106 = V_27 -> V_106 ;
if ( V_27 -> V_80 -> V_99 )
continue;
if ( V_106 -> V_10 -> V_107 && V_106 -> V_10 -> V_108 )
V_106 -> V_10 -> V_107 ( V_106 ) ;
F_76 ( V_106 -> V_23 ) ;
}
if ( V_50 -> V_120 )
V_50 -> V_120 ( V_50 ) ;
return 0 ;
}
static void F_77 ( struct V_93 * V_94 )
{
struct V_64 * V_50 =
F_78 ( V_94 , struct V_64 , V_121 ) ;
struct V_26 * V_27 ;
struct V_48 * V_49 ;
int V_3 ;
F_56 ( V_50 -> V_23 , L_24 ) ;
F_68 ( V_50 -> V_96 , V_122 ) ;
if ( V_50 -> V_123 )
V_50 -> V_123 ( V_50 ) ;
F_36 (rtd, &card->rtd_list, list) {
struct V_60 * V_106 = V_27 -> V_106 ;
if ( V_27 -> V_80 -> V_99 )
continue;
if ( V_106 -> V_10 -> V_124 && V_106 -> V_10 -> V_108 )
V_106 -> V_10 -> V_124 ( V_106 ) ;
}
F_36 (component, &card->component_dev_list, card_list) {
if ( V_49 -> V_115 ) {
if ( V_49 -> V_124 )
V_49 -> V_124 ( V_49 ) ;
V_49 -> V_115 = 0 ;
}
}
F_36 (rtd, &card->rtd_list, list) {
if ( V_27 -> V_80 -> V_99 )
continue;
F_71 ( V_27 ,
V_110 ,
V_125 ) ;
F_71 ( V_27 ,
V_112 ,
V_125 ) ;
}
F_36 (rtd, &card->rtd_list, list) {
if ( V_27 -> V_80 -> V_99 )
continue;
for ( V_3 = 0 ; V_3 < V_27 -> V_88 ; V_3 ++ ) {
struct V_60 * V_61 = V_27 -> V_87 [ V_3 ] ;
struct V_100 * V_101 = V_61 -> V_10 ;
if ( V_101 -> V_102 -> V_103 && V_61 -> V_104 )
V_101 -> V_102 -> V_103 ( V_61 , 0 ) ;
}
}
F_36 (rtd, &card->rtd_list, list) {
struct V_60 * V_106 = V_27 -> V_106 ;
if ( V_27 -> V_80 -> V_99 )
continue;
if ( V_106 -> V_10 -> V_124 && ! V_106 -> V_10 -> V_108 )
V_106 -> V_10 -> V_124 ( V_106 ) ;
}
if ( V_50 -> V_126 )
V_50 -> V_126 ( V_50 ) ;
F_56 ( V_50 -> V_23 , L_25 ) ;
F_72 ( V_50 ) ;
F_73 ( & V_50 -> V_113 ) ;
F_68 ( V_50 -> V_96 , V_97 ) ;
}
int F_79 ( struct V_22 * V_23 )
{
struct V_64 * V_50 = F_7 ( V_23 ) ;
bool V_108 = false ;
struct V_26 * V_27 ;
if ( ! V_50 -> V_95 )
return 0 ;
F_36 (rtd, &card->rtd_list, list) {
struct V_60 * * V_87 = V_27 -> V_87 ;
struct V_60 * V_106 = V_27 -> V_106 ;
int V_127 ;
if ( V_106 -> V_128 )
F_80 ( V_106 -> V_23 ) ;
for ( V_127 = 0 ; V_127 < V_27 -> V_88 ; V_127 ++ ) {
struct V_60 * V_129 = V_87 [ V_127 ] ;
if ( V_129 -> V_128 )
F_80 ( V_129 -> V_23 ) ;
}
}
F_36 (rtd, &card->rtd_list, list) {
struct V_60 * V_106 = V_27 -> V_106 ;
V_108 |= V_106 -> V_10 -> V_108 ;
}
if ( V_108 ) {
F_56 ( V_23 , L_26 ) ;
F_77 ( & V_50 -> V_121 ) ;
} else {
F_56 ( V_23 , L_27 ) ;
if ( ! F_81 ( & V_50 -> V_121 ) )
F_82 ( V_23 , L_28 ) ;
}
return 0 ;
}
static struct V_48 * F_83 (
const struct V_130 * V_131 , const char * V_53 )
{
struct V_48 * V_49 ;
F_84 ( & V_59 ) ;
F_36 (component, &component_list, list) {
if ( V_131 ) {
if ( V_49 -> V_23 -> V_131 == V_131 )
return V_49 ;
} else if ( strcmp ( V_49 -> V_53 , V_53 ) == 0 ) {
return V_49 ;
}
}
return NULL ;
}
struct V_60 * F_85 (
const struct V_132 * V_133 )
{
struct V_48 * V_49 ;
struct V_60 * V_61 ;
struct V_130 * V_134 ;
F_84 ( & V_59 ) ;
F_36 (component, &component_list, list) {
V_134 = V_49 -> V_23 -> V_131 ;
if ( ! V_134 && V_49 -> V_23 -> V_135 )
V_134 = V_49 -> V_23 -> V_135 -> V_131 ;
if ( V_133 -> V_131 && V_134 != V_133 -> V_131 )
continue;
if ( V_133 -> V_53 && strcmp ( V_49 -> V_53 , V_133 -> V_53 ) )
continue;
F_36 (dai, &component->dai_list, list) {
if ( V_133 -> V_136 && strcmp ( V_61 -> V_53 , V_133 -> V_136 )
&& ( ! V_61 -> V_10 -> V_53
|| strcmp ( V_61 -> V_10 -> V_53 , V_133 -> V_136 ) ) )
continue;
return V_61 ;
}
}
return NULL ;
}
struct V_86 * F_86 ( struct V_64 * V_50 ,
int V_137 , const char * V_53 ,
const char * V_138 )
{
struct V_86 * V_139 , * V_140 ;
F_84 ( & V_59 ) ;
F_62 (link, _link, &card->dai_link_list, list) {
if ( V_139 -> V_137 != V_137 )
continue;
if ( V_53 && ( ! V_139 -> V_53 || strcmp ( V_53 , V_139 -> V_53 ) ) )
continue;
if ( V_138 && ( ! V_139 -> V_138
|| strcmp ( V_138 , V_139 -> V_138 ) ) )
continue;
return V_139 ;
}
return NULL ;
}
static bool F_87 ( struct V_64 * V_50 ,
struct V_86 * V_80 )
{
struct V_26 * V_27 ;
F_36 (rtd, &card->rtd_list, list) {
if ( V_27 -> V_80 == V_80 )
return true ;
}
return false ;
}
static int F_88 ( struct V_64 * V_50 ,
struct V_86 * V_80 )
{
struct V_26 * V_27 ;
struct V_132 * V_141 = V_80 -> V_141 ;
struct V_132 V_142 ;
struct V_48 * V_49 ;
struct V_60 * * V_87 ;
struct V_62 * V_63 ;
struct V_130 * V_143 ;
const char * V_144 ;
int V_3 ;
F_56 ( V_50 -> V_23 , L_29 , V_80 -> V_53 ) ;
if ( F_87 ( V_50 , V_80 ) ) {
F_56 ( V_50 -> V_23 , L_30 ,
V_80 -> V_53 ) ;
return 0 ;
}
V_27 = F_57 ( V_50 , V_80 ) ;
if ( ! V_27 )
return - V_41 ;
V_142 . V_53 = V_80 -> V_145 ;
V_142 . V_131 = V_80 -> V_146 ;
V_142 . V_136 = V_80 -> V_147 ;
V_27 -> V_106 = F_85 ( & V_142 ) ;
if ( ! V_27 -> V_106 ) {
F_82 ( V_50 -> V_23 , L_31 ,
V_80 -> V_147 ) ;
goto V_148;
}
F_48 ( V_27 , V_27 -> V_106 -> V_49 ) ;
V_27 -> V_88 = V_80 -> V_88 ;
V_87 = V_27 -> V_87 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_88 ; V_3 ++ ) {
V_87 [ V_3 ] = F_85 ( & V_141 [ V_3 ] ) ;
if ( ! V_87 [ V_3 ] ) {
F_82 ( V_50 -> V_23 , L_32 ,
V_141 [ V_3 ] . V_136 ) ;
goto V_148;
}
F_48 ( V_27 , V_87 [ V_3 ] -> V_49 ) ;
}
V_27 -> V_129 = V_87 [ 0 ] ;
V_27 -> V_5 = V_27 -> V_129 -> V_5 ;
V_144 = V_80 -> V_144 ;
if ( ! V_144 && ! V_80 -> V_143 )
V_144 = L_33 ;
F_36 (component, &component_list, list) {
V_143 = V_49 -> V_23 -> V_131 ;
if ( ! V_143 && V_49 -> V_23 -> V_135 -> V_131 )
V_143 = V_49 -> V_23 -> V_135 -> V_131 ;
if ( V_80 -> V_143 ) {
if ( V_143 != V_80 -> V_143 )
continue;
} else {
if ( strcmp ( V_49 -> V_53 , V_144 ) )
continue;
}
F_48 ( V_27 , V_49 ) ;
}
F_36 (platform, &platform_list, list) {
V_143 = V_63 -> V_23 -> V_131 ;
if ( ! V_143 && V_63 -> V_23 -> V_135 -> V_131 )
V_143 = V_63 -> V_23 -> V_135 -> V_131 ;
if ( V_80 -> V_143 ) {
if ( V_143 != V_80 -> V_143 )
continue;
} else {
if ( strcmp ( V_63 -> V_49 . V_53 , V_144 ) )
continue;
}
V_27 -> V_63 = V_63 ;
}
if ( ! V_27 -> V_63 ) {
F_82 ( V_50 -> V_23 , L_34 ,
V_80 -> V_144 ) ;
goto V_148;
}
F_60 ( V_50 , V_27 ) ;
return 0 ;
V_148:
F_59 ( V_27 ) ;
return - V_149 ;
}
static void F_89 ( struct V_48 * V_49 )
{
if ( ! V_49 -> V_50 )
return;
F_63 ( & V_49 -> V_150 ) ;
if ( V_49 -> remove )
V_49 -> remove ( V_49 ) ;
F_90 ( F_28 ( V_49 ) ) ;
F_29 ( V_49 ) ;
V_49 -> V_50 = NULL ;
F_91 ( V_49 -> V_23 -> V_10 -> V_151 ) ;
}
static void F_92 ( struct V_60 * V_61 , int V_152 )
{
int V_153 ;
if ( V_61 && V_61 -> V_154 &&
V_61 -> V_10 -> V_155 == V_152 ) {
if ( V_61 -> V_10 -> remove ) {
V_153 = V_61 -> V_10 -> remove ( V_61 ) ;
if ( V_153 < 0 )
F_82 ( V_61 -> V_23 ,
L_35 ,
V_61 -> V_53 , V_153 ) ;
}
V_61 -> V_154 = 0 ;
}
}
static void F_93 ( struct V_64 * V_50 ,
struct V_26 * V_27 , int V_152 )
{
int V_3 ;
if ( V_27 -> V_156 ) {
F_94 ( V_27 -> V_23 ) ;
V_27 -> V_156 = 0 ;
}
for ( V_3 = 0 ; V_3 < V_27 -> V_88 ; V_3 ++ )
F_92 ( V_27 -> V_87 [ V_3 ] , V_152 ) ;
F_92 ( V_27 -> V_106 , V_152 ) ;
}
static void F_95 ( struct V_64 * V_50 ,
struct V_26 * V_27 , int V_152 )
{
struct V_48 * V_49 ;
struct V_71 * V_72 ;
F_49 (rtd, rtdcom) {
V_49 = V_72 -> V_49 ;
if ( V_49 -> V_10 -> V_155 == V_152 )
F_89 ( V_49 ) ;
}
}
static void F_96 ( struct V_64 * V_50 )
{
int V_152 ;
struct V_26 * V_27 ;
struct V_86 * V_139 , * V_140 ;
for ( V_152 = V_157 ; V_152 <= V_158 ;
V_152 ++ ) {
F_36 (rtd, &card->rtd_list, list)
F_93 ( V_50 , V_27 , V_152 ) ;
}
for ( V_152 = V_157 ; V_152 <= V_158 ;
V_152 ++ ) {
F_36 (rtd, &card->rtd_list, list)
F_95 ( V_50 , V_27 , V_152 ) ;
}
F_62 (link, _link, &card->dai_link_list, list) {
if ( V_139 -> V_159 . type == V_160 )
F_26 ( V_50 -> V_23 , L_36 ,
V_139 -> V_53 ) ;
F_63 ( & V_139 -> V_74 ) ;
V_50 -> V_161 -- ;
}
}
static int F_97 ( struct V_64 * V_50 ,
struct V_86 * V_80 )
{
if ( V_80 -> V_162 || V_80 -> V_163 ||
V_80 -> V_164 ) {
V_80 -> V_88 = 1 ;
V_80 -> V_141 = F_98 ( V_50 -> V_23 ,
sizeof( struct V_132 ) ,
V_40 ) ;
if ( ! V_80 -> V_141 )
return - V_41 ;
V_80 -> V_141 [ 0 ] . V_53 = V_80 -> V_162 ;
V_80 -> V_141 [ 0 ] . V_131 = V_80 -> V_163 ;
V_80 -> V_141 [ 0 ] . V_136 = V_80 -> V_164 ;
}
if ( ! V_80 -> V_141 ) {
F_82 ( V_50 -> V_23 , L_37 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_99 ( struct V_64 * V_50 ,
struct V_86 * V_139 )
{
int V_3 , V_14 ;
V_14 = F_97 ( V_50 , V_139 ) ;
if ( V_14 ) {
F_82 ( V_50 -> V_23 , L_38 ) ;
return V_14 ;
}
for ( V_3 = 0 ; V_3 < V_139 -> V_88 ; V_3 ++ ) {
if ( ! ! V_139 -> V_141 [ V_3 ] . V_53 ==
! ! V_139 -> V_141 [ V_3 ] . V_131 ) {
F_82 ( V_50 -> V_23 , L_39 ,
V_139 -> V_53 ) ;
return - V_15 ;
}
if ( ! V_139 -> V_141 [ V_3 ] . V_136 ) {
F_82 ( V_50 -> V_23 , L_40 ,
V_139 -> V_53 ) ;
return - V_15 ;
}
}
if ( V_139 -> V_144 && V_139 -> V_143 ) {
F_82 ( V_50 -> V_23 ,
L_41 ,
V_139 -> V_53 ) ;
return - V_15 ;
}
if ( V_139 -> V_145 && V_139 -> V_146 ) {
F_82 ( V_50 -> V_23 ,
L_42 ,
V_139 -> V_53 ) ;
return - V_15 ;
}
if ( ! V_139 -> V_147 &&
! ( V_139 -> V_145 || V_139 -> V_146 ) ) {
F_82 ( V_50 -> V_23 ,
L_43 ,
V_139 -> V_53 ) ;
return - V_15 ;
}
return 0 ;
}
int F_100 ( struct V_64 * V_50 ,
struct V_86 * V_80 )
{
if ( V_80 -> V_159 . type
&& V_80 -> V_159 . type != V_160 ) {
F_82 ( V_50 -> V_23 , L_44 ,
V_80 -> V_159 . type ) ;
return - V_15 ;
}
F_84 ( & V_59 ) ;
if ( V_80 -> V_159 . type && V_50 -> V_165 )
V_50 -> V_165 ( V_50 , V_80 ) ;
F_51 ( & V_80 -> V_74 , & V_50 -> V_166 ) ;
V_50 -> V_161 ++ ;
return 0 ;
}
void F_101 ( struct V_64 * V_50 ,
struct V_86 * V_80 )
{
struct V_86 * V_139 , * V_140 ;
if ( V_80 -> V_159 . type
&& V_80 -> V_159 . type != V_160 ) {
F_82 ( V_50 -> V_23 , L_44 ,
V_80 -> V_159 . type ) ;
return;
}
F_84 ( & V_59 ) ;
if ( V_80 -> V_159 . type && V_50 -> V_167 )
V_50 -> V_167 ( V_50 , V_80 ) ;
F_62 (link, _link, &card->dai_link_list, list) {
if ( V_139 == V_80 ) {
F_63 ( & V_139 -> V_74 ) ;
V_50 -> V_161 -- ;
return;
}
}
}
static void F_102 ( struct V_64 * V_50 ,
struct V_48 * V_49 )
{
int V_3 ;
if ( V_50 -> V_168 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_50 -> V_169 ; V_3 ++ ) {
struct V_170 * V_171 = & V_50 -> V_168 [ V_3 ] ;
if ( V_171 -> V_131 && V_49 -> V_23 -> V_131 != V_171 -> V_131 )
continue;
if ( V_171 -> V_172 && strcmp ( V_49 -> V_53 , V_171 -> V_172 ) )
continue;
V_49 -> V_173 = V_171 -> V_173 ;
break;
}
}
static int F_103 ( struct V_64 * V_50 ,
struct V_48 * V_49 )
{
struct V_114 * V_113 = F_28 ( V_49 ) ;
struct V_60 * V_61 ;
int V_14 ;
if ( ! strcmp ( V_49 -> V_53 , L_33 ) )
return 0 ;
if ( V_49 -> V_50 ) {
if ( V_49 -> V_50 != V_50 ) {
F_82 ( V_49 -> V_23 ,
L_45 ,
V_50 -> V_53 , V_49 -> V_50 -> V_53 ) ;
return - V_174 ;
}
return 0 ;
}
if ( ! F_104 ( V_49 -> V_23 -> V_10 -> V_151 ) )
return - V_174 ;
V_49 -> V_50 = V_50 ;
V_113 -> V_50 = V_50 ;
F_102 ( V_50 , V_49 ) ;
F_23 ( V_49 ) ;
if ( V_49 -> V_10 -> V_175 ) {
V_14 = F_105 ( V_113 ,
V_49 -> V_10 -> V_175 ,
V_49 -> V_10 -> V_176 ) ;
if ( V_14 != 0 ) {
F_82 ( V_49 -> V_23 ,
L_46 , V_14 ) ;
goto V_177;
}
}
F_36 (dai, &component->dai_list, list) {
V_14 = F_106 ( V_113 , V_61 ) ;
if ( V_14 != 0 ) {
F_82 ( V_49 -> V_23 ,
L_47 , V_14 ) ;
goto V_177;
}
}
if ( V_49 -> V_178 ) {
V_14 = V_49 -> V_178 ( V_49 ) ;
if ( V_14 < 0 ) {
F_82 ( V_49 -> V_23 ,
L_48 , V_14 ) ;
goto V_177;
}
F_107 ( V_113 -> V_117 &&
V_113 -> V_179 != V_118 ,
L_49 ,
V_49 -> V_53 ) ;
}
if ( V_49 -> V_180 ) {
V_14 = V_49 -> V_180 ( V_49 ) ;
if ( V_14 < 0 ) {
F_82 ( V_49 -> V_23 ,
L_50 , V_14 ) ;
goto V_177;
}
}
if ( V_49 -> V_10 -> V_181 )
F_108 ( V_49 ,
V_49 -> V_10 -> V_181 ,
V_49 -> V_10 -> V_182 ) ;
if ( V_49 -> V_10 -> V_183 )
F_109 ( V_113 ,
V_49 -> V_10 -> V_183 ,
V_49 -> V_10 -> V_184 ) ;
F_110 ( & V_113 -> V_74 , & V_50 -> V_185 ) ;
F_110 ( & V_49 -> V_150 , & V_50 -> V_186 ) ;
return 0 ;
V_177:
F_29 ( V_49 ) ;
V_49 -> V_50 = NULL ;
F_91 ( V_49 -> V_23 -> V_10 -> V_151 ) ;
return V_14 ;
}
static void F_111 ( struct V_22 * V_23 )
{
F_16 ( V_23 ) ;
}
static int F_112 ( struct V_26 * V_27 ,
const char * V_53 )
{
int V_14 = 0 ;
V_27 -> V_23 = F_58 ( sizeof( struct V_22 ) , V_40 ) ;
if ( ! V_27 -> V_23 )
return - V_41 ;
F_113 ( V_27 -> V_23 ) ;
V_27 -> V_23 -> V_135 = V_27 -> V_50 -> V_23 ;
V_27 -> V_23 -> V_187 = F_111 ;
V_27 -> V_23 -> V_188 = V_189 ;
F_114 ( V_27 -> V_23 , L_51 , V_53 ) ;
F_115 ( V_27 -> V_23 , V_27 ) ;
F_116 ( & V_27 -> V_190 ) ;
F_50 ( & V_27 -> V_191 [ V_110 ] . V_192 ) ;
F_50 ( & V_27 -> V_191 [ V_112 ] . V_192 ) ;
F_50 ( & V_27 -> V_191 [ V_110 ] . V_193 ) ;
F_50 ( & V_27 -> V_191 [ V_112 ] . V_193 ) ;
V_14 = F_117 ( V_27 -> V_23 ) ;
if ( V_14 < 0 ) {
F_118 ( V_27 -> V_23 ) ;
F_82 ( V_27 -> V_50 -> V_23 ,
L_52 , V_14 ) ;
return V_14 ;
}
V_27 -> V_156 = 1 ;
return 0 ;
}
static int F_119 ( struct V_64 * V_50 ,
struct V_26 * V_27 ,
int V_152 )
{
struct V_48 * V_49 ;
struct V_71 * V_72 ;
int V_14 ;
F_49 (rtd, rtdcom) {
V_49 = V_72 -> V_49 ;
if ( V_49 -> V_10 -> V_194 == V_152 ) {
V_14 = F_103 ( V_50 , V_49 ) ;
if ( V_14 < 0 )
return V_14 ;
}
}
return 0 ;
}
static int F_120 ( struct V_60 * V_61 , int V_152 )
{
int V_14 ;
if ( ! V_61 -> V_154 && V_61 -> V_10 -> V_194 == V_152 ) {
if ( V_61 -> V_10 -> V_178 ) {
V_14 = V_61 -> V_10 -> V_178 ( V_61 ) ;
if ( V_14 < 0 ) {
F_82 ( V_61 -> V_23 ,
L_53 ,
V_61 -> V_53 , V_14 ) ;
return V_14 ;
}
}
V_61 -> V_154 = 1 ;
}
return 0 ;
}
static int F_121 ( struct V_60 * * V_195 , int V_196 ,
struct V_26 * V_27 )
{
int V_3 , V_14 = 0 ;
for ( V_3 = 0 ; V_3 < V_196 ; ++ V_3 ) {
struct V_100 * V_101 = V_195 [ V_3 ] -> V_10 ;
if ( ! V_27 -> V_80 -> V_82 && V_101 -> V_197 )
V_14 = V_101 -> V_197 ( V_27 , V_195 [ V_3 ] ) ;
if ( V_14 < 0 ) {
F_82 ( V_195 [ V_3 ] -> V_23 ,
L_54 ,
V_195 [ V_3 ] -> V_53 ) ;
return V_14 ;
}
}
return 0 ;
}
static int F_122 ( struct V_64 * V_50 ,
struct V_86 * V_80 ,
struct V_26 * V_27 )
{
struct V_60 * V_106 = V_27 -> V_106 ;
struct V_60 * V_129 = V_27 -> V_129 ;
struct V_198 * V_199 , * V_200 ;
int V_14 ;
if ( V_27 -> V_88 > 1 )
F_26 ( V_50 -> V_23 , L_55 ) ;
V_199 = V_129 -> V_201 ;
V_200 = V_106 -> V_202 ;
if ( V_199 && V_200 ) {
V_14 = F_123 ( V_50 , V_80 -> V_203 ,
V_80 -> V_204 ,
V_200 , V_199 ) ;
if ( V_14 != 0 ) {
F_82 ( V_50 -> V_23 , L_56 ,
V_199 -> V_53 , V_200 -> V_53 , V_14 ) ;
return V_14 ;
}
}
V_199 = V_106 -> V_201 ;
V_200 = V_129 -> V_202 ;
if ( V_199 && V_200 ) {
V_14 = F_123 ( V_50 , V_80 -> V_203 ,
V_80 -> V_204 ,
V_200 , V_199 ) ;
if ( V_14 != 0 ) {
F_82 ( V_50 -> V_23 , L_56 ,
V_199 -> V_53 , V_200 -> V_53 , V_14 ) ;
return V_14 ;
}
}
return 0 ;
}
static int F_124 ( struct V_64 * V_50 ,
struct V_26 * V_27 , int V_152 )
{
struct V_86 * V_80 = V_27 -> V_80 ;
struct V_60 * V_106 = V_27 -> V_106 ;
int V_3 , V_14 ;
F_56 ( V_50 -> V_23 , L_57 ,
V_50 -> V_53 , V_27 -> V_90 , V_152 ) ;
V_27 -> V_29 = V_29 ;
V_14 = F_120 ( V_106 , V_152 ) ;
if ( V_14 )
return V_14 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_88 ; V_3 ++ ) {
V_14 = F_120 ( V_27 -> V_87 [ V_3 ] , V_152 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_152 != V_158 )
return 0 ;
if ( V_80 -> V_180 ) {
V_14 = V_80 -> V_180 ( V_27 ) ;
if ( V_14 < 0 ) {
F_82 ( V_50 -> V_23 , L_58 ,
V_80 -> V_53 , V_14 ) ;
return V_14 ;
}
}
if ( V_80 -> V_205 )
F_125 ( V_27 , V_80 -> V_205 ) ;
V_14 = F_112 ( V_27 , V_80 -> V_53 ) ;
if ( V_14 )
return V_14 ;
#ifdef F_126
if ( V_80 -> V_206 )
F_127 ( V_27 ) ;
#endif
if ( V_106 -> V_10 -> V_207 ) {
V_14 = V_106 -> V_10 -> V_207 ( V_27 , V_27 -> V_90 ) ;
if ( V_14 < 0 ) {
F_82 ( V_50 -> V_23 , L_59 ,
V_80 -> V_138 ) ;
return V_14 ;
}
} else {
if ( ! V_80 -> V_203 ) {
V_14 = F_128 ( V_27 , V_27 -> V_90 ) ;
if ( V_14 < 0 ) {
F_82 ( V_50 -> V_23 , L_60 ,
V_80 -> V_138 , V_14 ) ;
return V_14 ;
}
V_14 = F_121 ( & V_106 , 1 , V_27 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_121 ( V_27 -> V_87 ,
V_27 -> V_88 , V_27 ) ;
if ( V_14 < 0 )
return V_14 ;
} else {
F_129 ( & V_27 -> V_109 ,
F_65 ) ;
V_14 = F_122 ( V_50 , V_80 , V_27 ) ;
if ( V_14 )
return V_14 ;
}
}
return 0 ;
}
static int F_130 ( struct V_64 * V_50 , int V_90 )
{
struct V_208 * V_209 = & V_50 -> V_209 [ V_90 ] ;
struct V_48 * V_49 ;
const char * V_53 ;
struct V_130 * V_163 ;
if ( V_209 -> V_163 || V_209 -> V_162 ) {
V_53 = V_209 -> V_162 ;
V_163 = V_209 -> V_163 ;
V_49 = F_83 ( V_163 , V_53 ) ;
if ( ! V_49 ) {
if ( V_163 )
V_53 = F_131 ( V_163 ) ;
goto V_210;
}
} else if ( V_209 -> V_53 ) {
V_53 = V_209 -> V_53 ;
V_49 = F_83 ( NULL , V_53 ) ;
if ( ! V_49 )
goto V_210;
} else {
F_82 ( V_50 -> V_23 , L_61 ) ;
return - V_15 ;
}
V_49 -> V_180 = V_209 -> V_180 ;
F_110 ( & V_49 -> V_211 , & V_50 -> V_212 ) ;
return 0 ;
V_210:
F_82 ( V_50 -> V_23 , L_62 , V_53 ) ;
return - V_149 ;
}
static int F_132 ( struct V_64 * V_50 )
{
struct V_48 * V_213 ;
int V_152 ;
int V_14 ;
for ( V_152 = V_157 ; V_152 <= V_158 ;
V_152 ++ ) {
F_36 (comp, &card->aux_comp_list, card_aux_list) {
if ( V_213 -> V_10 -> V_194 == V_152 ) {
V_14 = F_103 ( V_50 , V_213 ) ;
if ( V_14 < 0 ) {
F_82 ( V_50 -> V_23 ,
L_63 ,
V_213 -> V_53 , V_14 ) ;
return V_14 ;
}
}
}
}
return 0 ;
}
static void F_133 ( struct V_64 * V_50 )
{
struct V_48 * V_213 , * V_214 ;
int V_152 ;
for ( V_152 = V_157 ; V_152 <= V_158 ;
V_152 ++ ) {
F_62 (comp, _comp,
&card->aux_comp_list, card_aux_list) {
if ( V_213 -> V_10 -> V_155 == V_152 ) {
F_89 ( V_213 ) ;
F_63 ( & V_213 -> V_211 ) ;
}
}
}
}
static int F_134 ( struct V_4 * V_5 )
{
int V_14 ;
if ( V_5 -> V_215 )
return 0 ;
V_14 = F_135 ( V_5 ) ;
if ( V_14 < 0 ) {
F_82 ( V_5 -> V_23 ,
L_64 ,
V_14 ) ;
return V_14 ;
}
V_5 -> V_215 = 1 ;
return 0 ;
}
int F_125 ( struct V_26 * V_27 ,
unsigned int V_205 )
{
struct V_60 * * V_87 = V_27 -> V_87 ;
struct V_60 * V_106 = V_27 -> V_106 ;
unsigned int V_3 ;
int V_14 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_88 ; V_3 ++ ) {
struct V_60 * V_129 = V_87 [ V_3 ] ;
V_14 = F_136 ( V_129 , V_205 ) ;
if ( V_14 != 0 && V_14 != - V_216 ) {
F_26 ( V_129 -> V_23 ,
L_65 , V_14 ) ;
return V_14 ;
}
}
if ( V_106 -> V_5 ) {
unsigned int V_217 ;
V_217 = V_205 & ~ V_218 ;
switch ( V_205 & V_218 ) {
case V_219 :
V_217 |= V_220 ;
break;
case V_221 :
V_217 |= V_222 ;
break;
case V_222 :
V_217 |= V_221 ;
break;
case V_220 :
V_217 |= V_219 ;
break;
}
V_205 = V_217 ;
}
V_14 = F_136 ( V_106 , V_205 ) ;
if ( V_14 != 0 && V_14 != - V_216 ) {
F_26 ( V_106 -> V_23 ,
L_65 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static void F_137 ( char * V_53 )
{
int V_3 , V_127 = 0 ;
for ( V_3 = 0 ; V_53 [ V_3 ] ; V_3 ++ ) {
if ( isalnum ( V_53 [ V_3 ] ) || ( V_53 [ V_3 ] == '.' )
|| ( V_53 [ V_3 ] == '_' ) )
V_53 [ V_127 ++ ] = V_53 [ V_3 ] ;
else if ( V_53 [ V_3 ] == '-' )
V_53 [ V_127 ++ ] = '_' ;
}
V_53 [ V_127 ] = '\0' ;
}
static int F_138 ( const char * V_223 )
{
int V_3 = 0 ;
while ( V_224 [ V_3 ] ) {
if ( strstr ( V_223 , V_224 [ V_3 ] ) )
return 0 ;
V_3 ++ ;
}
return 1 ;
}
int F_139 ( struct V_64 * V_50 , const char * V_225 )
{
const char * V_226 , * V_227 , * V_228 , * V_229 ;
T_1 V_230 = sizeof( V_50 -> V_96 -> V_231 ) ;
T_1 V_8 ;
if ( V_50 -> V_232 )
return 0 ;
V_226 = F_140 ( V_233 ) ;
if ( ! V_226 || ! F_138 ( V_226 ) ) {
F_26 ( V_50 -> V_23 , L_66 ) ;
return 0 ;
}
snprintf ( V_50 -> V_234 , sizeof( V_50 -> V_96 -> V_231 ) ,
L_51 , V_226 ) ;
F_137 ( V_50 -> V_234 ) ;
V_227 = F_140 ( V_235 ) ;
if ( V_227 && F_138 ( V_227 ) ) {
V_8 = strlen ( V_50 -> V_234 ) ;
snprintf ( V_50 -> V_234 + V_8 ,
V_230 - V_8 ,
L_67 , V_227 ) ;
V_8 ++ ;
if ( V_8 < V_230 )
F_137 ( V_50 -> V_234 + V_8 ) ;
V_228 = F_140 ( V_236 ) ;
if ( V_228 && F_138 ( V_228 ) ) {
V_8 = strlen ( V_50 -> V_234 ) ;
snprintf ( V_50 -> V_234 + V_8 ,
V_230 - V_8 ,
L_67 , V_228 ) ;
V_8 ++ ;
if ( V_8 < V_230 )
F_137 ( V_50 -> V_234 + V_8 ) ;
}
}
V_229 = F_140 ( V_237 ) ;
if ( V_229 && F_138 ( V_229 ) ) {
V_8 = strlen ( V_50 -> V_234 ) ;
snprintf ( V_50 -> V_234 + V_8 ,
V_230 - V_8 ,
L_67 , V_229 ) ;
V_8 ++ ;
if ( V_8 < V_230 )
F_137 ( V_50 -> V_234 + V_8 ) ;
} else if ( ! V_227 ) {
F_26 ( V_50 -> V_23 , L_68 ) ;
return 0 ;
}
if ( V_225 ) {
V_8 = strlen ( V_50 -> V_234 ) ;
snprintf ( V_50 -> V_234 + V_8 ,
V_230 - V_8 ,
L_67 , V_225 ) ;
V_8 ++ ;
if ( V_8 < V_230 )
F_137 ( V_50 -> V_234 + V_8 ) ;
}
V_50 -> V_232 = V_50 -> V_234 ;
return 0 ;
}
static int F_141 ( struct V_64 * V_50 )
{
struct V_4 * V_5 ;
struct V_26 * V_27 ;
struct V_86 * V_80 ;
int V_14 , V_3 , V_152 ;
F_35 ( & V_59 ) ;
F_142 ( & V_50 -> V_238 , V_239 ) ;
for ( V_3 = 0 ; V_3 < V_50 -> V_240 ; V_3 ++ ) {
V_14 = F_88 ( V_50 , & V_50 -> V_80 [ V_3 ] ) ;
if ( V_14 != 0 )
goto V_241;
}
for ( V_3 = 0 ; V_3 < V_50 -> V_242 ; V_3 ++ ) {
V_14 = F_130 ( V_50 , V_3 ) ;
if ( V_14 != 0 )
goto V_241;
}
for ( V_3 = 0 ; V_3 < V_50 -> V_240 ; V_3 ++ )
F_100 ( V_50 , V_50 -> V_80 + V_3 ) ;
F_36 (codec, &codec_list, list) {
if ( V_5 -> V_215 )
continue;
V_14 = F_134 ( V_5 ) ;
if ( V_14 < 0 )
goto V_241;
}
V_14 = F_143 ( V_50 -> V_23 , V_243 , V_244 ,
V_50 -> V_151 , 0 , & V_50 -> V_96 ) ;
if ( V_14 < 0 ) {
F_82 ( V_50 -> V_23 ,
L_69 ,
V_50 -> V_53 , V_14 ) ;
goto V_241;
}
F_41 ( V_50 ) ;
V_50 -> V_113 . V_179 = V_118 ;
V_50 -> V_113 . V_23 = V_50 -> V_23 ;
V_50 -> V_113 . V_50 = V_50 ;
F_110 ( & V_50 -> V_113 . V_74 , & V_50 -> V_185 ) ;
#ifdef F_126
F_27 ( & V_50 -> V_113 , V_50 -> V_51 ) ;
#endif
#ifdef F_144
F_145 ( & V_50 -> V_121 , F_77 ) ;
#endif
if ( V_50 -> V_175 )
F_105 ( & V_50 -> V_113 , V_50 -> V_175 ,
V_50 -> V_176 ) ;
if ( V_50 -> V_245 )
F_105 ( & V_50 -> V_113 , V_50 -> V_245 ,
V_50 -> V_246 ) ;
if ( V_50 -> V_178 ) {
V_14 = V_50 -> V_178 ( V_50 ) ;
if ( V_14 < 0 )
goto V_247;
}
for ( V_152 = V_157 ; V_152 <= V_158 ;
V_152 ++ ) {
F_36 (rtd, &card->rtd_list, list) {
V_14 = F_119 ( V_50 , V_27 , V_152 ) ;
if ( V_14 < 0 ) {
F_82 ( V_50 -> V_23 ,
L_70 ,
V_14 ) ;
goto V_248;
}
}
}
V_14 = F_132 ( V_50 ) ;
if ( V_14 < 0 )
goto V_248;
F_36 (dai_link, &card->dai_link_list, list) {
if ( F_87 ( V_50 , V_80 ) )
continue;
V_14 = F_99 ( V_50 , V_80 ) ;
if ( V_14 )
goto V_248;
V_14 = F_88 ( V_50 , V_80 ) ;
if ( V_14 )
goto V_248;
}
for ( V_152 = V_157 ; V_152 <= V_158 ;
V_152 ++ ) {
F_36 (rtd, &card->rtd_list, list) {
V_14 = F_124 ( V_50 , V_27 , V_152 ) ;
if ( V_14 < 0 ) {
F_82 ( V_50 -> V_23 ,
L_70 ,
V_14 ) ;
goto V_248;
}
}
}
F_146 ( V_50 ) ;
F_147 ( V_50 ) ;
if ( V_50 -> V_181 )
F_148 ( V_50 , V_50 -> V_181 , V_50 -> V_182 ) ;
if ( V_50 -> V_183 )
F_109 ( & V_50 -> V_113 , V_50 -> V_183 ,
V_50 -> V_184 ) ;
if ( V_50 -> V_249 )
F_109 ( & V_50 -> V_113 , V_50 -> V_249 ,
V_50 -> V_250 ) ;
F_139 ( V_50 , NULL ) ;
snprintf ( V_50 -> V_96 -> V_251 , sizeof( V_50 -> V_96 -> V_251 ) ,
L_51 , V_50 -> V_53 ) ;
snprintf ( V_50 -> V_96 -> V_231 , sizeof( V_50 -> V_96 -> V_231 ) ,
L_51 , V_50 -> V_232 ? V_50 -> V_232 : V_50 -> V_53 ) ;
snprintf ( V_50 -> V_96 -> V_10 , sizeof( V_50 -> V_96 -> V_10 ) ,
L_51 , V_50 -> V_78 ? V_50 -> V_78 : V_50 -> V_53 ) ;
for ( V_3 = 0 ; V_3 < F_149 ( V_50 -> V_96 -> V_10 ) ; V_3 ++ ) {
switch ( V_50 -> V_96 -> V_10 [ V_3 ] ) {
case '_' :
case '-' :
case '\0' :
break;
default:
if ( ! isalnum ( V_50 -> V_96 -> V_10 [ V_3 ] ) )
V_50 -> V_96 -> V_10 [ V_3 ] = '_' ;
break;
}
}
if ( V_50 -> V_252 ) {
V_14 = V_50 -> V_252 ( V_50 ) ;
if ( V_14 < 0 ) {
F_82 ( V_50 -> V_23 , L_71 ,
V_50 -> V_53 , V_14 ) ;
goto V_253;
}
}
F_150 ( V_50 ) ;
V_14 = F_151 ( V_50 -> V_96 ) ;
if ( V_14 < 0 ) {
F_82 ( V_50 -> V_23 , L_72 ,
V_14 ) ;
goto V_253;
}
V_50 -> V_95 = 1 ;
F_73 ( & V_50 -> V_113 ) ;
F_37 ( & V_50 -> V_238 ) ;
F_37 ( & V_59 ) ;
return 0 ;
V_253:
F_133 ( V_50 ) ;
V_248:
F_96 ( V_50 ) ;
V_247:
if ( V_50 -> remove )
V_50 -> remove ( V_50 ) ;
F_90 ( & V_50 -> V_113 ) ;
F_43 ( V_50 ) ;
F_152 ( V_50 -> V_96 ) ;
V_241:
F_61 ( V_50 ) ;
F_37 ( & V_50 -> V_238 ) ;
F_37 ( & V_59 ) ;
return V_14 ;
}
static int F_153 ( struct V_254 * V_255 )
{
struct V_64 * V_50 = F_154 ( V_255 ) ;
if ( ! V_50 )
return - V_15 ;
F_26 ( & V_255 -> V_23 ,
L_73 ,
V_50 -> V_53 ) ;
V_50 -> V_23 = & V_255 -> V_23 ;
return F_155 ( V_50 ) ;
}
static int F_156 ( struct V_64 * V_50 )
{
struct V_26 * V_27 ;
F_36 (rtd, &card->rtd_list, list)
F_70 ( & V_27 -> V_109 ) ;
F_152 ( V_50 -> V_96 ) ;
F_96 ( V_50 ) ;
F_61 ( V_50 ) ;
F_133 ( V_50 ) ;
F_90 ( & V_50 -> V_113 ) ;
F_43 ( V_50 ) ;
if ( V_50 -> remove )
V_50 -> remove ( V_50 ) ;
return 0 ;
}
static int F_157 ( struct V_254 * V_255 )
{
struct V_64 * V_50 = F_154 ( V_255 ) ;
F_158 ( V_50 ) ;
return 0 ;
}
int F_159 ( struct V_22 * V_23 )
{
struct V_64 * V_50 = F_7 ( V_23 ) ;
struct V_26 * V_27 ;
if ( ! V_50 -> V_95 )
return 0 ;
F_36 (rtd, &card->rtd_list, list)
F_70 ( & V_27 -> V_109 ) ;
F_160 ( V_50 ) ;
F_36 (rtd, &card->rtd_list, list) {
struct V_60 * V_106 = V_27 -> V_106 ;
int V_3 ;
F_76 ( V_106 -> V_23 ) ;
for ( V_3 = 0 ; V_3 < V_27 -> V_88 ; V_3 ++ ) {
struct V_60 * V_129 = V_27 -> V_87 [ V_3 ] ;
F_76 ( V_129 -> V_23 ) ;
}
}
return 0 ;
}
struct V_256 * F_161 ( const struct V_257 * V_258 ,
void * V_259 , const char * V_232 ,
const char * V_260 )
{
struct V_257 V_261 ;
struct V_256 * V_262 ;
char * V_53 = NULL ;
memcpy ( & V_261 , V_258 , sizeof( V_261 ) ) ;
V_261 . V_263 = 0 ;
if ( ! V_232 )
V_232 = V_261 . V_53 ;
if ( V_260 ) {
V_53 = F_24 ( V_40 , L_74 , V_260 , V_232 ) ;
if ( ! V_53 )
return NULL ;
V_261 . V_53 = V_53 ;
} else {
V_261 . V_53 = V_232 ;
}
V_262 = F_162 ( & V_261 , V_259 ) ;
F_16 ( V_53 ) ;
return V_262 ;
}
static int F_163 ( struct V_96 * V_50 , struct V_22 * V_23 ,
const struct V_257 * V_181 , int V_182 ,
const char * V_260 , void * V_259 )
{
int V_153 , V_3 ;
for ( V_3 = 0 ; V_3 < V_182 ; V_3 ++ ) {
const struct V_257 * V_264 = & V_181 [ V_3 ] ;
V_153 = F_164 ( V_50 , F_161 ( V_264 , V_259 ,
V_264 -> V_53 , V_260 ) ) ;
if ( V_153 < 0 ) {
F_82 ( V_23 , L_75 ,
V_264 -> V_53 , V_153 ) ;
return V_153 ;
}
}
return 0 ;
}
struct V_256 * F_165 ( struct V_64 * V_265 ,
const char * V_53 )
{
struct V_96 * V_50 = V_265 -> V_96 ;
struct V_256 * V_266 ;
if ( F_166 ( ! V_53 ) )
return NULL ;
F_36 (kctl, &card->controls, list)
if ( ! strncmp ( V_266 -> V_137 . V_53 , V_53 , sizeof( V_266 -> V_137 . V_53 ) ) )
return V_266 ;
return NULL ;
}
int F_108 ( struct V_48 * V_49 ,
const struct V_257 * V_181 , unsigned int V_182 )
{
struct V_96 * V_50 = V_49 -> V_50 -> V_96 ;
return F_163 ( V_50 , V_49 -> V_23 , V_181 ,
V_182 , V_49 -> V_173 , V_49 ) ;
}
int F_167 ( struct V_4 * V_5 ,
const struct V_257 * V_181 , unsigned int V_182 )
{
return F_108 ( & V_5 -> V_49 , V_181 ,
V_182 ) ;
}
int F_168 ( struct V_62 * V_63 ,
const struct V_257 * V_181 , unsigned int V_182 )
{
return F_108 ( & V_63 -> V_49 , V_181 ,
V_182 ) ;
}
int F_148 ( struct V_64 * V_265 ,
const struct V_257 * V_181 , int V_182 )
{
struct V_96 * V_50 = V_265 -> V_96 ;
return F_163 ( V_50 , V_265 -> V_23 , V_181 , V_182 ,
NULL , V_265 ) ;
}
int F_169 ( struct V_60 * V_61 ,
const struct V_257 * V_181 , int V_182 )
{
struct V_96 * V_50 = V_61 -> V_49 -> V_50 -> V_96 ;
return F_163 ( V_50 , V_61 -> V_23 , V_181 , V_182 ,
NULL , V_61 ) ;
}
int F_170 ( struct V_60 * V_61 , int V_267 ,
unsigned int V_268 , int V_269 )
{
if ( V_61 -> V_10 && V_61 -> V_10 -> V_102 -> V_270 )
return V_61 -> V_10 -> V_102 -> V_270 ( V_61 , V_267 , V_268 , V_269 ) ;
return F_171 ( V_61 -> V_49 , V_267 , 0 ,
V_268 , V_269 ) ;
}
int F_172 ( struct V_4 * V_5 , int V_267 ,
int V_200 , unsigned int V_268 , int V_269 )
{
if ( V_5 -> V_10 -> V_270 )
return V_5 -> V_10 -> V_270 ( V_5 , V_267 , V_200 ,
V_268 , V_269 ) ;
else
return - V_216 ;
}
int F_171 ( struct V_48 * V_49 , int V_267 ,
int V_200 , unsigned int V_268 , int V_269 )
{
if ( V_49 -> V_270 )
return V_49 -> V_270 ( V_49 , V_267 , V_200 ,
V_268 , V_269 ) ;
if ( V_49 -> V_10 -> V_270 )
return V_49 -> V_10 -> V_270 ( V_49 , V_267 , V_200 ,
V_268 , V_269 ) ;
return - V_216 ;
}
int F_173 ( struct V_60 * V_61 ,
int V_271 , int div )
{
if ( V_61 -> V_10 && V_61 -> V_10 -> V_102 -> V_272 )
return V_61 -> V_10 -> V_102 -> V_272 ( V_61 , V_271 , div ) ;
else
return - V_15 ;
}
int F_174 ( struct V_60 * V_61 , int V_273 , int V_200 ,
unsigned int V_274 , unsigned int V_275 )
{
if ( V_61 -> V_10 && V_61 -> V_10 -> V_102 -> V_276 )
return V_61 -> V_10 -> V_102 -> V_276 ( V_61 , V_273 , V_200 ,
V_274 , V_275 ) ;
return F_175 ( V_61 -> V_49 , V_273 , V_200 ,
V_274 , V_275 ) ;
}
int F_176 ( struct V_4 * V_5 , int V_273 , int V_200 ,
unsigned int V_274 , unsigned int V_275 )
{
if ( V_5 -> V_10 -> V_276 )
return V_5 -> V_10 -> V_276 ( V_5 , V_273 , V_200 ,
V_274 , V_275 ) ;
else
return - V_15 ;
}
int F_175 ( struct V_48 * V_49 , int V_273 ,
int V_200 , unsigned int V_274 ,
unsigned int V_275 )
{
if ( V_49 -> V_276 )
return V_49 -> V_276 ( V_49 , V_273 , V_200 ,
V_274 , V_275 ) ;
if ( V_49 -> V_10 -> V_276 )
return V_49 -> V_10 -> V_276 ( V_49 , V_273 , V_200 ,
V_274 , V_275 ) ;
return - V_15 ;
}
int F_177 ( struct V_60 * V_61 , unsigned int V_277 )
{
if ( V_61 -> V_10 && V_61 -> V_10 -> V_102 -> V_278 )
return V_61 -> V_10 -> V_102 -> V_278 ( V_61 , V_277 ) ;
else
return - V_15 ;
}
int F_136 ( struct V_60 * V_61 , unsigned int V_279 )
{
if ( V_61 -> V_10 == NULL )
return - V_15 ;
if ( V_61 -> V_10 -> V_102 -> V_280 == NULL )
return - V_216 ;
return V_61 -> V_10 -> V_102 -> V_280 ( V_61 , V_279 ) ;
}
static int F_178 ( unsigned int V_281 ,
unsigned int * V_282 ,
unsigned int * V_283 )
{
if ( * V_282 || * V_283 )
return 0 ;
if ( ! V_281 )
return - V_15 ;
* V_282 = ( 1 << V_281 ) - 1 ;
* V_283 = ( 1 << V_281 ) - 1 ;
return 0 ;
}
int F_179 ( struct V_60 * V_61 ,
unsigned int V_282 , unsigned int V_283 , int V_281 , int V_284 )
{
if ( V_61 -> V_10 && V_61 -> V_10 -> V_102 -> V_285 )
V_61 -> V_10 -> V_102 -> V_285 ( V_281 ,
& V_282 , & V_283 ) ;
else
F_178 ( V_281 , & V_282 , & V_283 ) ;
V_61 -> V_282 = V_282 ;
V_61 -> V_283 = V_283 ;
if ( V_61 -> V_10 && V_61 -> V_10 -> V_102 -> V_286 )
return V_61 -> V_10 -> V_102 -> V_286 ( V_61 , V_282 , V_283 ,
V_281 , V_284 ) ;
else
return - V_216 ;
}
int F_180 ( struct V_60 * V_61 ,
unsigned int V_287 , unsigned int * V_288 ,
unsigned int V_289 , unsigned int * V_290 )
{
if ( V_61 -> V_10 && V_61 -> V_10 -> V_102 -> V_291 )
return V_61 -> V_10 -> V_102 -> V_291 ( V_61 , V_287 , V_288 ,
V_289 , V_290 ) ;
else
return - V_15 ;
}
int F_181 ( struct V_60 * V_61 , int V_292 )
{
if ( V_61 -> V_10 && V_61 -> V_10 -> V_102 -> V_293 )
return V_61 -> V_10 -> V_102 -> V_293 ( V_61 , V_292 ) ;
else
return - V_15 ;
}
int F_182 ( struct V_60 * V_61 , int V_294 ,
int V_295 )
{
if ( ! V_61 -> V_10 )
return - V_216 ;
if ( V_61 -> V_10 -> V_102 -> V_296 )
return V_61 -> V_10 -> V_102 -> V_296 ( V_61 , V_294 , V_295 ) ;
else if ( V_295 == V_110 &&
V_61 -> V_10 -> V_102 -> V_103 )
return V_61 -> V_10 -> V_102 -> V_103 ( V_61 , V_294 ) ;
else
return - V_216 ;
}
int F_155 ( struct V_64 * V_50 )
{
int V_3 , V_14 ;
struct V_26 * V_27 ;
if ( ! V_50 -> V_53 || ! V_50 -> V_23 )
return - V_15 ;
for ( V_3 = 0 ; V_3 < V_50 -> V_240 ; V_3 ++ ) {
struct V_86 * V_139 = & V_50 -> V_80 [ V_3 ] ;
V_14 = F_99 ( V_50 , V_139 ) ;
if ( V_14 ) {
F_82 ( V_50 -> V_23 , L_76 ,
V_139 -> V_53 ) ;
return V_14 ;
}
}
F_115 ( V_50 -> V_23 , V_50 ) ;
F_183 ( V_50 ) ;
F_50 ( & V_50 -> V_166 ) ;
V_50 -> V_161 = 0 ;
F_50 ( & V_50 -> V_89 ) ;
V_50 -> V_91 = 0 ;
F_50 ( & V_50 -> V_297 ) ;
F_50 ( & V_50 -> V_298 ) ;
V_50 -> V_95 = 0 ;
F_116 ( & V_50 -> V_238 ) ;
F_116 ( & V_50 -> V_299 ) ;
V_14 = F_141 ( V_50 ) ;
if ( V_14 != 0 )
return V_14 ;
F_36 (rtd, &card->rtd_list, list) {
struct V_60 * V_106 = V_27 -> V_106 ;
int V_127 ;
for ( V_127 = 0 ; V_127 < V_27 -> V_88 ; V_127 ++ ) {
struct V_60 * V_129 = V_27 -> V_87 [ V_127 ] ;
if ( ! V_129 -> V_128 )
F_76 ( V_129 -> V_23 ) ;
}
if ( ! V_106 -> V_128 )
F_76 ( V_106 -> V_23 ) ;
}
return V_14 ;
}
int F_158 ( struct V_64 * V_50 )
{
if ( V_50 -> V_95 ) {
V_50 -> V_95 = false ;
F_160 ( V_50 ) ;
F_156 ( V_50 ) ;
F_56 ( V_50 -> V_23 , L_77 , V_50 -> V_53 ) ;
}
return 0 ;
}
static char * F_184 ( struct V_22 * V_23 , int * V_137 )
{
char * V_300 , V_53 [ V_301 ] ;
int V_302 , V_303 ;
if ( V_172 ( V_23 ) == NULL )
return NULL ;
F_185 ( V_53 , V_172 ( V_23 ) , V_301 ) ;
V_300 = strstr ( V_53 , V_23 -> V_10 -> V_53 ) ;
if ( V_300 ) {
if ( sscanf ( & V_300 [ strlen ( V_23 -> V_10 -> V_53 ) ] , L_78 , V_137 ) == 1 ) {
if ( * V_137 == - 1 )
V_300 [ strlen ( V_23 -> V_10 -> V_53 ) ] = '\0' ;
}
} else {
if ( sscanf ( V_53 , L_79 , & V_302 , & V_303 ) == 2 ) {
char V_304 [ V_301 ] ;
* V_137 = ( ( V_302 & 0xffff ) << 16 ) + V_303 ;
snprintf ( V_304 , V_301 , L_80 , V_23 -> V_10 -> V_53 , V_53 ) ;
F_185 ( V_53 , V_304 , V_301 ) ;
} else
* V_137 = 0 ;
}
return F_186 ( V_53 , V_40 ) ;
}
static inline char * F_187 ( struct V_22 * V_23 ,
struct V_100 * V_305 )
{
if ( V_305 -> V_53 == NULL ) {
F_82 ( V_23 ,
L_81 ,
V_172 ( V_23 ) ) ;
return NULL ;
}
return F_186 ( V_305 -> V_53 , V_40 ) ;
}
static void F_188 ( struct V_48 * V_49 )
{
struct V_60 * V_61 , * V_306 ;
F_62 (dai, _dai, &component->dai_list, list) {
F_56 ( V_49 -> V_23 , L_82 ,
V_61 -> V_53 ) ;
F_63 ( & V_61 -> V_74 ) ;
F_16 ( V_61 -> V_53 ) ;
F_16 ( V_61 ) ;
}
}
static struct V_60 * F_189 ( struct V_48 * V_49 ,
struct V_100 * V_305 ,
bool V_307 )
{
struct V_22 * V_23 = V_49 -> V_23 ;
struct V_60 * V_61 ;
F_56 ( V_23 , L_83 , V_172 ( V_23 ) ) ;
V_61 = F_58 ( sizeof( struct V_60 ) , V_40 ) ;
if ( V_61 == NULL )
return NULL ;
if ( V_307 &&
( V_305 -> V_137 == 0 || V_305 -> V_53 == NULL ) ) {
V_61 -> V_53 = F_184 ( V_23 , & V_61 -> V_137 ) ;
} else {
V_61 -> V_53 = F_187 ( V_23 , V_305 ) ;
if ( V_305 -> V_137 )
V_61 -> V_137 = V_305 -> V_137 ;
else
V_61 -> V_137 = V_49 -> V_308 ;
}
if ( V_61 -> V_53 == NULL ) {
F_16 ( V_61 ) ;
return NULL ;
}
V_61 -> V_49 = V_49 ;
V_61 -> V_23 = V_23 ;
V_61 -> V_10 = V_305 ;
if ( ! V_61 -> V_10 -> V_102 )
V_61 -> V_10 -> V_102 = & V_309 ;
F_110 ( & V_61 -> V_74 , & V_49 -> V_310 ) ;
V_49 -> V_308 ++ ;
F_56 ( V_23 , L_84 , V_61 -> V_53 ) ;
return V_61 ;
}
static int F_190 ( struct V_48 * V_49 ,
struct V_100 * V_305 , T_1 V_16 ,
bool V_307 )
{
struct V_22 * V_23 = V_49 -> V_23 ;
struct V_60 * V_61 ;
unsigned int V_3 ;
int V_14 ;
F_56 ( V_23 , L_85 , V_172 ( V_23 ) , V_16 ) ;
V_49 -> V_305 = V_305 ;
for ( V_3 = 0 ; V_3 < V_16 ; V_3 ++ ) {
V_61 = F_189 ( V_49 , V_305 + V_3 ,
V_16 == 1 && V_307 ) ;
if ( V_61 == NULL ) {
V_14 = - V_41 ;
goto V_153;
}
}
return 0 ;
V_153:
F_188 ( V_49 ) ;
return V_14 ;
}
int F_191 ( struct V_48 * V_49 ,
struct V_100 * V_305 )
{
struct V_114 * V_113 =
F_28 ( V_49 ) ;
struct V_60 * V_61 ;
int V_14 ;
if ( V_305 -> V_159 . type != V_311 ) {
F_82 ( V_49 -> V_23 , L_86 ,
V_305 -> V_159 . type ) ;
return - V_15 ;
}
F_84 ( & V_59 ) ;
V_61 = F_189 ( V_49 , V_305 , false ) ;
if ( ! V_61 )
return - V_41 ;
V_14 = F_106 ( V_113 , V_61 ) ;
if ( V_14 != 0 ) {
F_82 ( V_49 -> V_23 ,
L_47 , V_14 ) ;
}
return V_14 ;
}
static void F_192 ( struct V_114 * V_113 ,
enum V_312 type , int V_313 )
{
struct V_48 * V_49 = V_113 -> V_49 ;
V_49 -> V_10 -> V_314 ( V_49 , type , V_313 ) ;
}
static int F_193 ( struct V_114 * V_113 ,
int V_315 )
{
struct V_48 * V_49 = V_113 -> V_49 ;
return V_49 -> V_10 -> V_316 ( V_49 , V_315 ) ;
}
static int F_194 ( struct V_48 * V_49 ,
const struct V_317 * V_10 , struct V_22 * V_23 )
{
struct V_114 * V_113 ;
V_49 -> V_53 = F_184 ( V_23 , & V_49 -> V_137 ) ;
if ( ! V_49 -> V_53 ) {
F_82 ( V_23 , L_87 ) ;
return - V_41 ;
}
V_49 -> V_23 = V_23 ;
V_49 -> V_10 = V_10 ;
V_49 -> V_178 = V_49 -> V_10 -> V_178 ;
V_49 -> remove = V_49 -> V_10 -> remove ;
V_49 -> V_107 = V_49 -> V_10 -> V_107 ;
V_49 -> V_124 = V_49 -> V_10 -> V_124 ;
V_49 -> V_270 = V_49 -> V_10 -> V_270 ;
V_49 -> V_276 = V_49 -> V_10 -> V_276 ;
V_49 -> V_318 = V_49 -> V_10 -> V_318 ;
V_113 = F_28 ( V_49 ) ;
V_113 -> V_23 = V_23 ;
V_113 -> V_49 = V_49 ;
V_113 -> V_179 = V_118 ;
V_113 -> V_117 = true ;
if ( V_10 -> V_314 )
V_113 -> V_314 = F_192 ;
if ( V_10 -> V_316 )
V_113 -> V_316 = F_193 ;
F_50 ( & V_49 -> V_310 ) ;
F_116 ( & V_49 -> V_319 ) ;
return 0 ;
}
static void F_195 ( struct V_48 * V_49 )
{
int V_320 = F_196 ( V_49 -> V_119 ) ;
if ( V_320 > 0 )
V_49 -> V_320 = V_320 ;
}
void F_197 ( struct V_48 * V_49 ,
struct V_119 * V_119 )
{
V_49 -> V_119 = V_119 ;
F_195 ( V_49 ) ;
}
void F_198 ( struct V_48 * V_49 )
{
F_199 ( V_49 -> V_119 ) ;
V_49 -> V_119 = NULL ;
}
static void F_200 ( struct V_48 * V_49 )
{
if ( ! V_49 -> V_321 && ! V_49 -> V_322 ) {
if ( ! V_49 -> V_119 )
V_49 -> V_119 = F_201 ( V_49 -> V_23 , NULL ) ;
if ( V_49 -> V_119 )
F_195 ( V_49 ) ;
}
F_110 ( & V_49 -> V_74 , & V_75 ) ;
F_50 ( & V_49 -> V_298 ) ;
}
static void F_202 ( struct V_48 * V_49 )
{
F_35 ( & V_59 ) ;
F_200 ( V_49 ) ;
F_37 ( & V_59 ) ;
}
static void F_203 ( struct V_48 * V_49 )
{
F_188 ( V_49 ) ;
F_16 ( V_49 -> V_53 ) ;
}
static void F_204 ( struct V_48 * V_49 )
{
struct V_64 * V_50 = V_49 -> V_50 ;
if ( V_50 )
F_158 ( V_50 ) ;
F_63 ( & V_49 -> V_74 ) ;
}
int F_205 ( struct V_22 * V_23 ,
const struct V_317 * V_323 ,
struct V_100 * V_305 ,
int V_308 )
{
struct V_48 * V_49 ;
int V_14 ;
V_49 = F_58 ( sizeof( * V_49 ) , V_40 ) ;
if ( ! V_49 ) {
F_82 ( V_23 , L_88 ) ;
return - V_41 ;
}
V_14 = F_194 ( V_49 , V_323 , V_23 ) ;
if ( V_14 )
goto V_324;
V_49 -> V_325 = true ;
V_49 -> V_326 = true ;
V_14 = F_190 ( V_49 , V_305 , V_308 , true ) ;
if ( V_14 < 0 ) {
F_82 ( V_23 , L_89 , V_14 ) ;
goto V_327;
}
F_202 ( V_49 ) ;
return 0 ;
V_327:
F_203 ( V_49 ) ;
V_324:
F_16 ( V_49 ) ;
return V_14 ;
}
static int F_206 ( struct V_22 * V_23 )
{
struct V_48 * V_49 ;
int V_300 = 0 ;
F_35 ( & V_59 ) ;
F_36 (component, &component_list, list) {
if ( V_23 != V_49 -> V_23 ||
! V_49 -> V_326 )
continue;
F_207 ( V_49 , V_328 ) ;
F_204 ( V_49 ) ;
V_300 = 1 ;
break;
}
F_37 ( & V_59 ) ;
if ( V_300 ) {
F_203 ( V_49 ) ;
F_16 ( V_49 ) ;
}
return V_300 ;
}
void F_208 ( struct V_22 * V_23 )
{
while ( F_206 ( V_23 ) ) ;
}
static int F_209 ( struct V_48 * V_49 )
{
struct V_62 * V_63 = F_210 ( V_49 ) ;
return V_63 -> V_10 -> V_178 ( V_63 ) ;
}
static void F_211 ( struct V_48 * V_49 )
{
struct V_62 * V_63 = F_210 ( V_49 ) ;
V_63 -> V_10 -> remove ( V_63 ) ;
}
int F_212 ( struct V_22 * V_23 , struct V_62 * V_63 ,
const struct V_329 * V_330 )
{
int V_14 ;
V_14 = F_194 ( & V_63 -> V_49 ,
& V_330 -> V_323 , V_23 ) ;
if ( V_14 )
return V_14 ;
V_63 -> V_23 = V_23 ;
V_63 -> V_10 = V_330 ;
if ( V_330 -> V_178 )
V_63 -> V_49 . V_178 = F_209 ;
if ( V_330 -> remove )
V_63 -> V_49 . remove = F_211 ;
#ifdef F_126
V_63 -> V_49 . V_52 = L_90 ;
#endif
F_35 ( & V_59 ) ;
F_200 ( & V_63 -> V_49 ) ;
F_110 ( & V_63 -> V_74 , & V_331 ) ;
F_37 ( & V_59 ) ;
F_56 ( V_23 , L_91 ,
V_63 -> V_49 . V_53 ) ;
return 0 ;
}
int F_213 ( struct V_22 * V_23 ,
const struct V_329 * V_330 )
{
struct V_62 * V_63 ;
int V_14 ;
F_56 ( V_23 , L_92 , V_172 ( V_23 ) ) ;
V_63 = F_58 ( sizeof( struct V_62 ) , V_40 ) ;
if ( V_63 == NULL )
return - V_41 ;
V_14 = F_212 ( V_23 , V_63 , V_330 ) ;
if ( V_14 )
F_16 ( V_63 ) ;
return V_14 ;
}
void F_214 ( struct V_62 * V_63 )
{
F_35 ( & V_59 ) ;
F_63 ( & V_63 -> V_74 ) ;
F_204 ( & V_63 -> V_49 ) ;
F_37 ( & V_59 ) ;
F_56 ( V_63 -> V_23 , L_93 ,
V_63 -> V_49 . V_53 ) ;
F_203 ( & V_63 -> V_49 ) ;
}
struct V_62 * F_215 ( struct V_22 * V_23 )
{
struct V_62 * V_63 ;
F_35 ( & V_59 ) ;
F_36 (platform, &platform_list, list) {
if ( V_23 == V_63 -> V_23 ) {
F_37 ( & V_59 ) ;
return V_63 ;
}
}
F_37 ( & V_59 ) ;
return NULL ;
}
void F_216 ( struct V_22 * V_23 )
{
struct V_62 * V_63 ;
V_63 = F_215 ( V_23 ) ;
if ( ! V_63 )
return;
F_214 ( V_63 ) ;
F_16 ( V_63 ) ;
}
static void F_217 ( struct V_332 * V_81 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_149 ( V_333 ) ; V_3 ++ )
if ( V_81 -> V_334 & V_333 [ V_3 ] )
V_81 -> V_334 |= V_333 [ V_3 ] ;
}
static int F_218 ( struct V_48 * V_49 )
{
struct V_4 * V_5 = F_32 ( V_49 ) ;
return V_5 -> V_10 -> V_178 ( V_5 ) ;
}
static void F_219 ( struct V_48 * V_49 )
{
struct V_4 * V_5 = F_32 ( V_49 ) ;
V_5 -> V_10 -> remove ( V_5 ) ;
}
static int F_220 ( struct V_48 * V_49 )
{
struct V_4 * V_5 = F_32 ( V_49 ) ;
return V_5 -> V_10 -> V_107 ( V_5 ) ;
}
static int F_221 ( struct V_48 * V_49 )
{
struct V_4 * V_5 = F_32 ( V_49 ) ;
return V_5 -> V_10 -> V_124 ( V_5 ) ;
}
static int F_222 ( struct V_48 * V_49 ,
unsigned int V_6 , unsigned int V_1 )
{
struct V_4 * V_5 = F_32 ( V_49 ) ;
return V_5 -> V_10 -> V_321 ( V_5 , V_6 , V_1 ) ;
}
static int F_223 ( struct V_48 * V_49 ,
unsigned int V_6 , unsigned int * V_1 )
{
struct V_4 * V_5 = F_32 ( V_49 ) ;
* V_1 = V_5 -> V_10 -> V_322 ( V_5 , V_6 ) ;
return 0 ;
}
static int F_224 ( struct V_48 * V_49 ,
int V_267 , int V_200 , unsigned int V_268 , int V_269 )
{
struct V_4 * V_5 = F_32 ( V_49 ) ;
return F_172 ( V_5 , V_267 , V_200 , V_268 , V_269 ) ;
}
static int F_225 ( struct V_48 * V_49 ,
int V_273 , int V_200 , unsigned int V_274 ,
unsigned int V_275 )
{
struct V_4 * V_5 = F_32 ( V_49 ) ;
return F_176 ( V_5 , V_273 , V_200 , V_274 , V_275 ) ;
}
static int F_226 ( struct V_48 * V_49 ,
struct V_335 * V_336 , void * V_259 )
{
struct V_4 * V_5 = F_32 ( V_49 ) ;
return F_227 ( V_5 , V_336 , V_259 ) ;
}
static int F_228 ( struct V_114 * V_113 ,
enum V_337 V_338 )
{
struct V_4 * V_5 = F_229 ( V_113 ) ;
return V_5 -> V_10 -> V_339 ( V_5 , V_338 ) ;
}
int F_230 ( struct V_22 * V_23 ,
const struct V_340 * V_341 ,
struct V_100 * V_305 ,
int V_308 )
{
struct V_114 * V_113 ;
struct V_4 * V_5 ;
struct V_60 * V_61 ;
int V_14 , V_3 ;
F_56 ( V_23 , L_94 , V_172 ( V_23 ) ) ;
V_5 = F_58 ( sizeof( struct V_4 ) , V_40 ) ;
if ( V_5 == NULL )
return - V_41 ;
V_5 -> V_49 . V_5 = V_5 ;
V_14 = F_194 ( & V_5 -> V_49 ,
& V_341 -> V_323 , V_23 ) ;
if ( V_14 )
goto V_324;
if ( V_341 -> V_178 )
V_5 -> V_49 . V_178 = F_218 ;
if ( V_341 -> remove )
V_5 -> V_49 . remove = F_219 ;
if ( V_341 -> V_107 )
V_5 -> V_49 . V_107 = F_220 ;
if ( V_341 -> V_124 )
V_5 -> V_49 . V_124 = F_221 ;
if ( V_341 -> V_321 )
V_5 -> V_49 . V_321 = F_222 ;
if ( V_341 -> V_322 )
V_5 -> V_49 . V_322 = F_223 ;
if ( V_341 -> V_270 )
V_5 -> V_49 . V_270 = F_224 ;
if ( V_341 -> V_276 )
V_5 -> V_49 . V_276 = F_225 ;
if ( V_341 -> V_318 )
V_5 -> V_49 . V_318 = F_226 ;
V_5 -> V_49 . V_325 = V_341 -> V_325 ;
V_113 = F_231 ( V_5 ) ;
V_113 -> V_117 = V_341 -> V_117 ;
V_113 -> V_342 = V_341 -> V_342 ;
if ( V_341 -> V_314 )
V_113 -> V_314 = V_341 -> V_314 ;
if ( V_341 -> V_339 )
V_113 -> V_339 = F_228 ;
V_5 -> V_23 = V_23 ;
V_5 -> V_10 = V_341 ;
V_5 -> V_49 . V_320 = V_341 -> V_13 ;
#ifdef F_126
V_5 -> V_49 . V_55 = F_31 ;
V_5 -> V_49 . V_52 = L_95 ;
#endif
if ( V_341 -> V_343 )
V_5 -> V_49 . V_119 = V_341 -> V_343 ( V_23 ) ;
for ( V_3 = 0 ; V_3 < V_308 ; V_3 ++ ) {
F_217 ( & V_305 [ V_3 ] . V_344 ) ;
F_217 ( & V_305 [ V_3 ] . V_345 ) ;
}
V_14 = F_190 ( & V_5 -> V_49 , V_305 , V_308 , false ) ;
if ( V_14 < 0 ) {
F_82 ( V_23 , L_89 , V_14 ) ;
goto V_327;
}
F_36 (dai, &codec->component.dai_list, list)
V_61 -> V_5 = V_5 ;
F_35 ( & V_59 ) ;
F_200 ( & V_5 -> V_49 ) ;
F_110 ( & V_5 -> V_74 , & V_346 ) ;
F_37 ( & V_59 ) ;
F_56 ( V_5 -> V_23 , L_96 ,
V_5 -> V_49 . V_53 ) ;
return 0 ;
V_327:
F_203 ( & V_5 -> V_49 ) ;
V_324:
F_16 ( V_5 ) ;
return V_14 ;
}
void F_232 ( struct V_22 * V_23 )
{
struct V_4 * V_5 ;
F_35 ( & V_59 ) ;
F_36 (codec, &codec_list, list) {
if ( V_23 == V_5 -> V_23 )
goto V_300;
}
F_37 ( & V_59 ) ;
return;
V_300:
F_63 ( & V_5 -> V_74 ) ;
F_204 ( & V_5 -> V_49 ) ;
F_37 ( & V_59 ) ;
F_56 ( V_5 -> V_23 , L_97 ,
V_5 -> V_49 . V_53 ) ;
F_203 ( & V_5 -> V_49 ) ;
F_233 ( V_5 ) ;
F_16 ( V_5 ) ;
}
int F_234 ( struct V_64 * V_50 ,
const char * V_347 )
{
struct V_130 * V_348 ;
int V_14 ;
if ( ! V_50 -> V_23 ) {
F_235 ( L_98 , V_349 ) ;
return - V_15 ;
}
V_348 = V_50 -> V_23 -> V_131 ;
V_14 = F_236 ( V_348 , V_347 , 0 , & V_50 -> V_53 ) ;
if ( V_14 < 0 && V_14 != - V_15 ) {
F_82 ( V_50 -> V_23 ,
L_99 ,
V_347 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
int F_237 ( struct V_64 * V_50 ,
const char * V_347 )
{
struct V_130 * V_348 = V_50 -> V_23 -> V_131 ;
struct V_198 * V_350 ;
const char * V_261 , * V_351 ;
int V_3 , V_127 , V_352 , V_14 ;
V_352 = F_238 ( V_348 , V_347 ) ;
if ( V_352 < 0 ) {
F_82 ( V_50 -> V_23 ,
L_100 , V_347 ) ;
return - V_15 ;
}
if ( V_352 & 1 ) {
F_82 ( V_50 -> V_23 ,
L_101 , V_347 ) ;
return - V_15 ;
}
V_352 /= 2 ;
if ( ! V_352 ) {
F_82 ( V_50 -> V_23 , L_102 ,
V_347 ) ;
return - V_15 ;
}
V_350 = F_239 ( V_50 -> V_23 , V_352 , sizeof( * V_350 ) ,
V_40 ) ;
if ( ! V_350 ) {
F_82 ( V_50 -> V_23 ,
L_103 ) ;
return - V_41 ;
}
for ( V_3 = 0 ; V_3 < V_352 ; V_3 ++ ) {
V_14 = F_236 ( V_348 , V_347 ,
2 * V_3 , & V_261 ) ;
if ( V_14 ) {
F_82 ( V_50 -> V_23 ,
L_104 ,
V_347 , 2 * V_3 , V_14 ) ;
return - V_15 ;
}
for ( V_127 = 0 ; V_127 < F_149 ( V_353 ) ; V_127 ++ ) {
if ( ! strncmp ( V_261 , V_353 [ V_127 ] . V_53 ,
strlen ( V_353 [ V_127 ] . V_53 ) ) ) {
V_350 [ V_3 ] = V_353 [ V_127 ] ;
break;
}
}
if ( V_127 >= F_149 ( V_353 ) ) {
F_82 ( V_50 -> V_23 ,
L_105 ,
V_261 ) ;
return - V_15 ;
}
V_14 = F_236 ( V_348 , V_347 ,
( 2 * V_3 ) + 1 ,
& V_351 ) ;
if ( V_14 ) {
F_82 ( V_50 -> V_23 ,
L_104 ,
V_347 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_15 ;
}
V_350 [ V_3 ] . V_53 = V_351 ;
}
V_50 -> V_245 = V_350 ;
V_50 -> V_246 = V_352 ;
return 0 ;
}
static int F_240 ( struct V_130 * V_348 ,
const char * V_354 ,
unsigned int * V_355 )
{
T_6 V_1 ;
const T_7 * V_356 = F_241 ( V_348 , V_354 , & V_1 ) ;
int V_3 ;
if ( ! V_356 )
return 0 ;
V_1 /= sizeof( T_6 ) ;
for ( V_3 = 0 ; V_3 < V_1 ; V_3 ++ )
if ( F_242 ( & V_356 [ V_3 ] ) )
* V_355 |= ( 1 << V_3 ) ;
return V_1 ;
}
int F_243 ( struct V_130 * V_348 ,
unsigned int * V_282 ,
unsigned int * V_283 ,
unsigned int * V_281 ,
unsigned int * V_284 )
{
T_6 V_1 ;
int V_14 ;
if ( V_282 )
F_240 ( V_348 , L_106 , V_282 ) ;
if ( V_283 )
F_240 ( V_348 , L_107 , V_283 ) ;
if ( F_244 ( V_348 , L_108 ) ) {
V_14 = F_245 ( V_348 , L_108 , & V_1 ) ;
if ( V_14 )
return V_14 ;
if ( V_281 )
* V_281 = V_1 ;
}
if ( F_244 ( V_348 , L_109 ) ) {
V_14 = F_245 ( V_348 , L_109 , & V_1 ) ;
if ( V_14 )
return V_14 ;
if ( V_284 )
* V_284 = V_1 ;
}
return 0 ;
}
void F_246 ( struct V_64 * V_50 ,
struct V_170 * V_168 ,
struct V_130 * V_131 ,
const char * V_347 )
{
struct V_130 * V_348 = V_50 -> V_23 -> V_131 ;
const char * V_357 ;
int V_14 ;
V_14 = F_247 ( V_348 , V_347 , & V_357 ) ;
if ( V_14 < 0 ) {
return;
}
V_168 -> V_131 = V_131 ;
V_168 -> V_173 = V_357 ;
}
int F_248 ( struct V_64 * V_50 ,
const char * V_347 )
{
struct V_130 * V_348 = V_50 -> V_23 -> V_131 ;
int V_358 ;
struct V_359 * V_360 ;
int V_3 , V_14 ;
V_358 = F_238 ( V_348 , V_347 ) ;
if ( V_358 < 0 || V_358 & 1 ) {
F_82 ( V_50 -> V_23 ,
L_110 ,
V_347 ) ;
return - V_15 ;
}
V_358 /= 2 ;
if ( ! V_358 ) {
F_82 ( V_50 -> V_23 , L_102 ,
V_347 ) ;
return - V_15 ;
}
V_360 = F_98 ( V_50 -> V_23 , V_358 * sizeof( * V_360 ) ,
V_40 ) ;
if ( ! V_360 ) {
F_82 ( V_50 -> V_23 ,
L_111 ) ;
return - V_15 ;
}
for ( V_3 = 0 ; V_3 < V_358 ; V_3 ++ ) {
V_14 = F_236 ( V_348 , V_347 ,
2 * V_3 , & V_360 [ V_3 ] . V_199 ) ;
if ( V_14 ) {
F_82 ( V_50 -> V_23 ,
L_112 ,
V_347 , 2 * V_3 , V_14 ) ;
return - V_15 ;
}
V_14 = F_236 ( V_348 , V_347 ,
( 2 * V_3 ) + 1 , & V_360 [ V_3 ] . V_200 ) ;
if ( V_14 ) {
F_82 ( V_50 -> V_23 ,
L_112 ,
V_347 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_15 ;
}
}
V_50 -> V_250 = V_358 ;
V_50 -> V_249 = V_360 ;
return 0 ;
}
unsigned int F_249 ( struct V_130 * V_348 ,
const char * V_260 ,
struct V_130 * * V_361 ,
struct V_130 * * V_362 )
{
int V_14 , V_3 ;
char V_363 [ 128 ] ;
unsigned int V_364 = 0 ;
int V_365 , V_366 ;
const char * V_357 ;
struct {
char * V_53 ;
unsigned int V_1 ;
} V_367 [] = {
{ L_113 , V_368 } ,
{ L_114 , V_369 } ,
{ L_115 , V_370 } ,
{ L_116 , V_371 } ,
{ L_117 , V_372 } ,
{ L_118 , V_373 } ,
{ L_119 , V_374 } ,
{ L_120 , V_375 } ,
{ L_121 , V_376 } ,
} ;
if ( ! V_260 )
V_260 = L_122 ;
V_14 = F_247 ( V_348 , L_123 , & V_357 ) ;
if ( V_14 < 0 ) {
snprintf ( V_363 , sizeof( V_363 ) , L_124 , V_260 ) ;
V_14 = F_247 ( V_348 , V_363 , & V_357 ) ;
}
if ( V_14 == 0 ) {
for ( V_3 = 0 ; V_3 < F_149 ( V_367 ) ; V_3 ++ ) {
if ( strcmp ( V_357 , V_367 [ V_3 ] . V_53 ) == 0 ) {
V_364 |= V_367 [ V_3 ] . V_1 ;
break;
}
}
}
snprintf ( V_363 , sizeof( V_363 ) , L_125 , V_260 ) ;
if ( F_244 ( V_348 , V_363 ) )
V_364 |= V_377 ;
else
V_364 |= V_378 ;
snprintf ( V_363 , sizeof( V_363 ) , L_126 , V_260 ) ;
V_365 = ! ! F_241 ( V_348 , V_363 , NULL ) ;
snprintf ( V_363 , sizeof( V_363 ) , L_127 , V_260 ) ;
V_366 = ! ! F_241 ( V_348 , V_363 , NULL ) ;
switch ( ( V_365 << 4 ) + V_366 ) {
case 0x11 :
V_364 |= V_379 ;
break;
case 0x10 :
V_364 |= V_380 ;
break;
case 0x01 :
V_364 |= V_381 ;
break;
default:
break;
}
snprintf ( V_363 , sizeof( V_363 ) , L_128 , V_260 ) ;
V_365 = ! ! F_241 ( V_348 , V_363 , NULL ) ;
if ( V_365 && V_361 )
* V_361 = F_250 ( V_348 , V_363 , 0 ) ;
snprintf ( V_363 , sizeof( V_363 ) , L_129 , V_260 ) ;
V_366 = ! ! F_241 ( V_348 , V_363 , NULL ) ;
if ( V_366 && V_362 )
* V_362 = F_250 ( V_348 , V_363 , 0 ) ;
switch ( ( V_365 << 4 ) + V_366 ) {
case 0x11 :
V_364 |= V_219 ;
break;
case 0x10 :
V_364 |= V_221 ;
break;
case 0x01 :
V_364 |= V_222 ;
break;
default:
V_364 |= V_220 ;
break;
}
return V_364 ;
}
int F_251 ( struct V_130 * V_382 )
{
struct V_48 * V_17 ;
struct V_130 * V_383 ;
int V_14 ;
V_383 = F_252 ( V_382 ) ;
V_14 = - V_216 ;
F_35 ( & V_59 ) ;
F_36 (pos, &component_list, list) {
struct V_130 * V_134 = V_17 -> V_23 -> V_131 ;
if ( ! V_134 && V_17 -> V_23 -> V_135 )
V_134 = V_17 -> V_23 -> V_135 -> V_131 ;
if ( V_134 != V_383 )
continue;
if ( V_17 -> V_10 -> V_384 )
V_14 = V_17 -> V_10 -> V_384 ( V_17 , V_382 ) ;
break;
}
F_37 ( & V_59 ) ;
F_253 ( V_383 ) ;
return V_14 ;
}
int F_254 ( struct V_385 * args ,
const char * * V_136 )
{
struct V_48 * V_17 ;
struct V_130 * V_134 ;
int V_14 = - V_149 ;
F_35 ( & V_59 ) ;
F_36 (pos, &component_list, list) {
V_134 = V_17 -> V_23 -> V_131 ;
if ( ! V_134 && V_17 -> V_23 -> V_135 )
V_134 = V_17 -> V_23 -> V_135 -> V_131 ;
if ( V_134 != args -> V_348 )
continue;
if ( V_17 -> V_10 -> V_386 ) {
V_14 = V_17 -> V_10 -> V_386 ( V_17 ,
args ,
V_136 ) ;
} else {
int V_137 = - 1 ;
switch ( args -> V_387 ) {
case 0 :
V_137 = 0 ;
break;
case 1 :
V_137 = args -> args [ 0 ] ;
break;
default:
break;
}
if ( V_137 < 0 || V_137 >= V_17 -> V_308 ) {
V_14 = - V_15 ;
continue;
}
V_14 = 0 ;
* V_136 = V_17 -> V_305 [ V_137 ] . V_53 ;
if ( ! * V_136 )
* V_136 = V_17 -> V_53 ;
}
break;
}
F_37 ( & V_59 ) ;
return V_14 ;
}
int F_255 ( struct V_130 * V_131 ,
const char * * V_136 )
{
struct V_385 args ;
int V_14 ;
V_14 = F_256 ( V_131 , L_130 ,
L_131 , 0 , & args ) ;
if ( V_14 )
return V_14 ;
V_14 = F_254 ( & args , V_136 ) ;
F_253 ( args . V_348 ) ;
return V_14 ;
}
int F_257 ( struct V_22 * V_23 ,
struct V_130 * V_131 ,
struct V_86 * V_80 )
{
struct V_385 args ;
struct V_132 * V_49 ;
char * V_53 ;
int V_263 , V_88 , V_14 ;
V_53 = L_130 ;
V_88 = F_258 ( V_131 , V_53 ,
L_131 ) ;
if ( V_88 <= 0 ) {
if ( V_88 == - V_388 )
F_82 ( V_23 , L_132 ) ;
else
F_82 ( V_23 , L_133 ) ;
return V_88 ;
}
V_49 = F_98 ( V_23 ,
sizeof *V_49 * V_88 ,
V_40 ) ;
if ( ! V_49 )
return - V_41 ;
V_80 -> V_141 = V_49 ;
V_80 -> V_88 = V_88 ;
for ( V_263 = 0 , V_49 = V_80 -> V_141 ;
V_263 < V_80 -> V_88 ;
V_263 ++ , V_49 ++ ) {
V_14 = F_256 ( V_131 , V_53 ,
L_131 ,
V_263 , & args ) ;
if ( V_14 )
goto V_153;
V_49 -> V_131 = args . V_348 ;
V_14 = F_254 ( & args , & V_49 -> V_136 ) ;
if ( V_14 < 0 )
goto V_153;
}
return 0 ;
V_153:
for ( V_263 = 0 , V_49 = V_80 -> V_141 ;
V_263 < V_80 -> V_88 ;
V_263 ++ , V_49 ++ ) {
if ( ! V_49 -> V_131 )
break;
F_253 ( V_49 -> V_131 ) ;
V_49 -> V_131 = NULL ;
}
V_80 -> V_141 = NULL ;
V_80 -> V_88 = 0 ;
return V_14 ;
}
static int T_8 F_259 ( void )
{
F_44 () ;
F_260 () ;
return F_261 ( & V_389 ) ;
}
static void T_9 F_262 ( void )
{
F_263 () ;
F_47 () ;
F_264 ( & V_389 ) ;
}
