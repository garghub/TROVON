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
V_5 -> V_56 = F_33 ( L_6 , 0644 ,
V_5 -> V_49 . V_54 ,
V_5 , & V_57 ) ;
if ( ! V_5 -> V_56 )
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
F_35 ( & V_58 ) ;
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
F_37 ( & V_58 ) ;
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
struct V_59 * V_60 ;
if ( ! V_7 )
return - V_41 ;
F_35 ( & V_58 ) ;
F_36 (component, &component_list, list) {
F_36 (dai, &component->dai_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_28 - V_14 , L_8 ,
V_60 -> V_53 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_28 ) {
V_14 = V_28 ;
break;
}
}
}
F_37 ( & V_58 ) ;
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
struct V_61 * V_62 ;
if ( ! V_7 )
return - V_41 ;
F_35 ( & V_58 ) ;
F_36 (platform, &platform_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_28 - V_14 , L_8 ,
V_62 -> V_49 . V_53 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_28 ) {
V_14 = V_28 ;
break;
}
}
F_37 ( & V_58 ) ;
V_14 = F_38 ( V_37 , V_16 , V_38 , V_7 , V_14 ) ;
F_16 ( V_7 ) ;
return V_14 ;
}
static void F_41 ( struct V_63 * V_50 )
{
if ( ! V_64 )
return;
V_50 -> V_51 = F_25 ( V_50 -> V_53 ,
V_64 ) ;
if ( ! V_50 -> V_51 ) {
F_26 ( V_50 -> V_23 ,
L_9 ) ;
return;
}
V_50 -> V_65 = F_42 ( L_10 , 0644 ,
V_50 -> V_51 ,
& V_50 -> V_66 ) ;
if ( ! V_50 -> V_65 )
F_26 ( V_50 -> V_23 ,
L_11 ) ;
}
static void F_43 ( struct V_63 * V_50 )
{
F_30 ( V_50 -> V_51 ) ;
}
static void F_44 ( void )
{
V_64 = F_25 ( L_12 , NULL ) ;
if ( F_45 ( V_64 ) || ! V_64 ) {
F_46 ( L_13 ) ;
V_64 = NULL ;
return;
}
if ( ! F_33 ( L_14 , 0444 , V_64 , NULL ,
& V_67 ) )
F_46 ( L_15 ) ;
if ( ! F_33 ( L_16 , 0444 , V_64 , NULL ,
& V_68 ) )
F_46 ( L_17 ) ;
if ( ! F_33 ( L_18 , 0444 , V_64 , NULL ,
& V_69 ) )
F_46 ( L_19 ) ;
}
static void F_47 ( void )
{
F_30 ( V_64 ) ;
}
static inline void F_23 (
struct V_48 * V_49 )
{
}
static inline void F_29 (
struct V_48 * V_49 )
{
}
static inline void F_41 ( struct V_63 * V_50 )
{
}
static inline void F_43 ( struct V_63 * V_50 )
{
}
static inline void F_44 ( void )
{
}
static inline void F_47 ( void )
{
}
struct V_70 * F_48 ( struct V_63 * V_50 ,
const char * V_71 , int V_72 )
{
struct V_26 * V_27 ;
F_36 (rtd, &card->rtd_list, list) {
if ( V_27 -> V_71 -> V_73 &&
! strcmp ( V_27 -> V_71 -> V_53 , V_71 ) )
return V_27 -> V_74 -> V_75 [ V_72 ] . V_76 ;
}
F_49 ( V_50 -> V_23 , L_20 , V_71 ) ;
return NULL ;
}
static struct V_26 * F_50 (
struct V_63 * V_50 , struct V_77 * V_71 )
{
struct V_26 * V_27 ;
V_27 = F_51 ( sizeof( struct V_26 ) , V_40 ) ;
if ( ! V_27 )
return NULL ;
V_27 -> V_50 = V_50 ;
V_27 -> V_71 = V_71 ;
V_27 -> V_78 = F_51 ( sizeof( struct V_59 * ) *
V_71 -> V_79 ,
V_40 ) ;
if ( ! V_27 -> V_78 ) {
F_16 ( V_27 ) ;
return NULL ;
}
return V_27 ;
}
static void F_52 ( struct V_26 * V_27 )
{
if ( V_27 && V_27 -> V_78 )
F_16 ( V_27 -> V_78 ) ;
F_16 ( V_27 ) ;
}
static void F_53 ( struct V_63 * V_50 ,
struct V_26 * V_27 )
{
F_54 ( & V_27 -> V_80 , & V_50 -> V_81 ) ;
V_27 -> V_82 = V_50 -> V_83 ;
V_50 -> V_83 ++ ;
}
static void F_55 ( struct V_63 * V_50 )
{
struct V_26 * V_27 , * V_84 ;
F_56 (rtd, _rtd, &card->rtd_list, list) {
F_57 ( & V_27 -> V_80 ) ;
F_52 ( V_27 ) ;
}
V_50 -> V_83 = 0 ;
}
struct V_26 * F_58 ( struct V_63 * V_50 ,
const char * V_71 )
{
struct V_26 * V_27 ;
F_36 (rtd, &card->rtd_list, list) {
if ( ! strcmp ( V_27 -> V_71 -> V_53 , V_71 ) )
return V_27 ;
}
F_49 ( V_50 -> V_23 , L_21 , V_71 ) ;
return NULL ;
}
static void F_59 ( struct V_85 * V_86 )
{
}
int F_60 ( struct V_22 * V_23 )
{
struct V_63 * V_50 = F_7 ( V_23 ) ;
struct V_48 * V_49 ;
struct V_26 * V_27 ;
int V_3 ;
if ( ! V_50 -> V_87 )
return 0 ;
F_61 ( V_50 -> V_88 ) ;
F_62 ( V_50 -> V_88 , V_89 ) ;
F_63 ( V_50 -> V_88 ) ;
F_64 ( V_50 -> V_88 , V_90 ) ;
F_36 (rtd, &card->rtd_list, list) {
if ( V_27 -> V_71 -> V_91 )
continue;
for ( V_3 = 0 ; V_3 < V_27 -> V_79 ; V_3 ++ ) {
struct V_59 * V_60 = V_27 -> V_78 [ V_3 ] ;
struct V_92 * V_93 = V_60 -> V_10 ;
if ( V_93 -> V_94 -> V_95 && V_60 -> V_96 )
V_93 -> V_94 -> V_95 ( V_60 , 1 ) ;
}
}
F_36 (rtd, &card->rtd_list, list) {
if ( V_27 -> V_71 -> V_91 )
continue;
F_65 ( V_27 -> V_74 ) ;
}
if ( V_50 -> V_97 )
V_50 -> V_97 ( V_50 ) ;
F_36 (rtd, &card->rtd_list, list) {
struct V_59 * V_98 = V_27 -> V_98 ;
if ( V_27 -> V_71 -> V_91 )
continue;
if ( V_98 -> V_10 -> V_99 && ! V_98 -> V_10 -> V_100 )
V_98 -> V_10 -> V_99 ( V_98 ) ;
}
F_36 (rtd, &card->rtd_list, list)
F_66 ( & V_27 -> V_101 ) ;
F_36 (rtd, &card->rtd_list, list) {
if ( V_27 -> V_71 -> V_91 )
continue;
F_67 ( V_27 ,
V_102 ,
V_103 ) ;
F_67 ( V_27 ,
V_104 ,
V_103 ) ;
}
F_68 ( V_50 ) ;
F_69 ( & V_50 -> V_105 ) ;
F_36 (component, &card->component_dev_list, card_list) {
struct V_106 * V_105 = F_28 ( V_49 ) ;
if ( ! V_49 -> V_107 ) {
switch ( F_70 ( V_105 ) ) {
case V_108 :
if ( V_105 -> V_109 ) {
F_49 ( V_49 -> V_23 ,
L_22 ) ;
break;
}
case V_110 :
if ( V_49 -> V_99 )
V_49 -> V_99 ( V_49 ) ;
V_49 -> V_107 = 1 ;
if ( V_49 -> V_111 )
F_71 ( V_49 -> V_111 ) ;
F_72 ( V_49 -> V_23 ) ;
break;
default:
F_49 ( V_49 -> V_23 ,
L_23 ) ;
break;
}
}
}
F_36 (rtd, &card->rtd_list, list) {
struct V_59 * V_98 = V_27 -> V_98 ;
if ( V_27 -> V_71 -> V_91 )
continue;
if ( V_98 -> V_10 -> V_99 && V_98 -> V_10 -> V_100 )
V_98 -> V_10 -> V_99 ( V_98 ) ;
F_72 ( V_98 -> V_23 ) ;
}
if ( V_50 -> V_112 )
V_50 -> V_112 ( V_50 ) ;
return 0 ;
}
static void F_73 ( struct V_85 * V_86 )
{
struct V_63 * V_50 =
F_74 ( V_86 , struct V_63 , V_113 ) ;
struct V_26 * V_27 ;
struct V_48 * V_49 ;
int V_3 ;
F_49 ( V_50 -> V_23 , L_24 ) ;
F_64 ( V_50 -> V_88 , V_114 ) ;
if ( V_50 -> V_115 )
V_50 -> V_115 ( V_50 ) ;
F_36 (rtd, &card->rtd_list, list) {
struct V_59 * V_98 = V_27 -> V_98 ;
if ( V_27 -> V_71 -> V_91 )
continue;
if ( V_98 -> V_10 -> V_116 && V_98 -> V_10 -> V_100 )
V_98 -> V_10 -> V_116 ( V_98 ) ;
}
F_36 (component, &card->component_dev_list, card_list) {
if ( V_49 -> V_107 ) {
if ( V_49 -> V_116 )
V_49 -> V_116 ( V_49 ) ;
V_49 -> V_107 = 0 ;
}
}
F_36 (rtd, &card->rtd_list, list) {
if ( V_27 -> V_71 -> V_91 )
continue;
F_67 ( V_27 ,
V_102 ,
V_117 ) ;
F_67 ( V_27 ,
V_104 ,
V_117 ) ;
}
F_36 (rtd, &card->rtd_list, list) {
if ( V_27 -> V_71 -> V_91 )
continue;
for ( V_3 = 0 ; V_3 < V_27 -> V_79 ; V_3 ++ ) {
struct V_59 * V_60 = V_27 -> V_78 [ V_3 ] ;
struct V_92 * V_93 = V_60 -> V_10 ;
if ( V_93 -> V_94 -> V_95 && V_60 -> V_96 )
V_93 -> V_94 -> V_95 ( V_60 , 0 ) ;
}
}
F_36 (rtd, &card->rtd_list, list) {
struct V_59 * V_98 = V_27 -> V_98 ;
if ( V_27 -> V_71 -> V_91 )
continue;
if ( V_98 -> V_10 -> V_116 && ! V_98 -> V_10 -> V_100 )
V_98 -> V_10 -> V_116 ( V_98 ) ;
}
if ( V_50 -> V_118 )
V_50 -> V_118 ( V_50 ) ;
F_49 ( V_50 -> V_23 , L_25 ) ;
F_68 ( V_50 ) ;
F_69 ( & V_50 -> V_105 ) ;
F_64 ( V_50 -> V_88 , V_89 ) ;
}
int F_75 ( struct V_22 * V_23 )
{
struct V_63 * V_50 = F_7 ( V_23 ) ;
bool V_100 = false ;
struct V_26 * V_27 ;
if ( ! V_50 -> V_87 )
return 0 ;
F_36 (rtd, &card->rtd_list, list) {
struct V_59 * * V_78 = V_27 -> V_78 ;
struct V_59 * V_98 = V_27 -> V_98 ;
int V_119 ;
if ( V_98 -> V_120 )
F_76 ( V_98 -> V_23 ) ;
for ( V_119 = 0 ; V_119 < V_27 -> V_79 ; V_119 ++ ) {
struct V_59 * V_121 = V_78 [ V_119 ] ;
if ( V_121 -> V_120 )
F_76 ( V_121 -> V_23 ) ;
}
}
F_36 (rtd, &card->rtd_list, list) {
struct V_59 * V_98 = V_27 -> V_98 ;
V_100 |= V_98 -> V_10 -> V_100 ;
}
if ( V_100 ) {
F_49 ( V_23 , L_26 ) ;
F_73 ( & V_50 -> V_113 ) ;
} else {
F_49 ( V_23 , L_27 ) ;
if ( ! F_77 ( & V_50 -> V_113 ) )
F_78 ( V_23 , L_28 ) ;
}
return 0 ;
}
static struct V_48 * F_79 (
const struct V_122 * V_123 , const char * V_53 )
{
struct V_48 * V_49 ;
F_80 ( & V_58 ) ;
F_36 (component, &component_list, list) {
if ( V_123 ) {
if ( V_49 -> V_23 -> V_123 == V_123 )
return V_49 ;
} else if ( strcmp ( V_49 -> V_53 , V_53 ) == 0 ) {
return V_49 ;
}
}
return NULL ;
}
struct V_59 * F_81 (
const struct V_124 * V_125 )
{
struct V_48 * V_49 ;
struct V_59 * V_60 ;
struct V_122 * V_126 ;
F_80 ( & V_58 ) ;
F_36 (component, &component_list, list) {
V_126 = V_49 -> V_23 -> V_123 ;
if ( ! V_126 && V_49 -> V_23 -> V_127 )
V_126 = V_49 -> V_23 -> V_127 -> V_123 ;
if ( V_125 -> V_123 && V_126 != V_125 -> V_123 )
continue;
if ( V_125 -> V_53 && strcmp ( V_49 -> V_53 , V_125 -> V_53 ) )
continue;
F_36 (dai, &component->dai_list, list) {
if ( V_125 -> V_128 && strcmp ( V_60 -> V_53 , V_125 -> V_128 ) )
continue;
return V_60 ;
}
}
return NULL ;
}
struct V_77 * F_82 ( struct V_63 * V_50 ,
int V_129 , const char * V_53 ,
const char * V_130 )
{
struct V_77 * V_131 , * V_132 ;
F_80 ( & V_58 ) ;
F_56 (link, _link, &card->dai_link_list, list) {
if ( V_131 -> V_129 != V_129 )
continue;
if ( V_53 && ( ! V_131 -> V_53 || strcmp ( V_53 , V_131 -> V_53 ) ) )
continue;
if ( V_130 && ( ! V_131 -> V_130
|| strcmp ( V_130 , V_131 -> V_130 ) ) )
continue;
return V_131 ;
}
return NULL ;
}
static bool F_83 ( struct V_63 * V_50 ,
struct V_77 * V_71 )
{
struct V_26 * V_27 ;
F_36 (rtd, &card->rtd_list, list) {
if ( V_27 -> V_71 == V_71 )
return true ;
}
return false ;
}
static int F_84 ( struct V_63 * V_50 ,
struct V_77 * V_71 )
{
struct V_26 * V_27 ;
struct V_124 * V_133 = V_71 -> V_133 ;
struct V_124 V_134 ;
struct V_59 * * V_78 ;
struct V_61 * V_62 ;
struct V_122 * V_135 ;
const char * V_136 ;
int V_3 ;
F_49 ( V_50 -> V_23 , L_29 , V_71 -> V_53 ) ;
if ( F_83 ( V_50 , V_71 ) ) {
F_49 ( V_50 -> V_23 , L_30 ,
V_71 -> V_53 ) ;
return 0 ;
}
V_27 = F_50 ( V_50 , V_71 ) ;
if ( ! V_27 )
return - V_41 ;
V_134 . V_53 = V_71 -> V_137 ;
V_134 . V_123 = V_71 -> V_138 ;
V_134 . V_128 = V_71 -> V_139 ;
V_27 -> V_98 = F_81 ( & V_134 ) ;
if ( ! V_27 -> V_98 ) {
F_78 ( V_50 -> V_23 , L_31 ,
V_71 -> V_139 ) ;
goto V_140;
}
V_27 -> V_79 = V_71 -> V_79 ;
V_78 = V_27 -> V_78 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_79 ; V_3 ++ ) {
V_78 [ V_3 ] = F_81 ( & V_133 [ V_3 ] ) ;
if ( ! V_78 [ V_3 ] ) {
F_78 ( V_50 -> V_23 , L_32 ,
V_133 [ V_3 ] . V_128 ) ;
goto V_140;
}
}
V_27 -> V_121 = V_78 [ 0 ] ;
V_27 -> V_5 = V_27 -> V_121 -> V_5 ;
V_136 = V_71 -> V_136 ;
if ( ! V_136 && ! V_71 -> V_135 )
V_136 = L_33 ;
F_36 (platform, &platform_list, list) {
V_135 = V_62 -> V_23 -> V_123 ;
if ( ! V_135 && V_62 -> V_23 -> V_127 -> V_123 )
V_135 = V_62 -> V_23 -> V_127 -> V_123 ;
if ( V_71 -> V_135 ) {
if ( V_135 != V_71 -> V_135 )
continue;
} else {
if ( strcmp ( V_62 -> V_49 . V_53 , V_136 ) )
continue;
}
V_27 -> V_62 = V_62 ;
}
if ( ! V_27 -> V_62 ) {
F_78 ( V_50 -> V_23 , L_34 ,
V_71 -> V_136 ) ;
goto V_140;
}
F_53 ( V_50 , V_27 ) ;
return 0 ;
V_140:
F_52 ( V_27 ) ;
return - V_141 ;
}
static void F_85 ( struct V_48 * V_49 )
{
if ( ! V_49 -> V_50 )
return;
F_57 ( & V_49 -> V_142 ) ;
if ( V_49 -> remove )
V_49 -> remove ( V_49 ) ;
F_86 ( F_28 ( V_49 ) ) ;
F_29 ( V_49 ) ;
V_49 -> V_50 = NULL ;
F_87 ( V_49 -> V_23 -> V_10 -> V_143 ) ;
}
static void F_88 ( struct V_59 * V_60 , int V_144 )
{
int V_145 ;
if ( V_60 && V_60 -> V_146 &&
V_60 -> V_10 -> V_147 == V_144 ) {
if ( V_60 -> V_10 -> remove ) {
V_145 = V_60 -> V_10 -> remove ( V_60 ) ;
if ( V_145 < 0 )
F_78 ( V_60 -> V_23 ,
L_35 ,
V_60 -> V_53 , V_145 ) ;
}
V_60 -> V_146 = 0 ;
}
}
static void F_89 ( struct V_63 * V_50 ,
struct V_26 * V_27 , int V_144 )
{
int V_3 ;
if ( V_27 -> V_148 ) {
F_90 ( V_27 -> V_23 ) ;
V_27 -> V_148 = 0 ;
}
for ( V_3 = 0 ; V_3 < V_27 -> V_79 ; V_3 ++ )
F_88 ( V_27 -> V_78 [ V_3 ] , V_144 ) ;
F_88 ( V_27 -> V_98 , V_144 ) ;
}
static void F_91 ( struct V_63 * V_50 ,
struct V_26 * V_27 , int V_144 )
{
struct V_59 * V_98 = V_27 -> V_98 ;
struct V_61 * V_62 = V_27 -> V_62 ;
struct V_48 * V_49 ;
int V_3 ;
if ( V_62 && V_62 -> V_49 . V_10 -> V_147 == V_144 )
F_85 ( & V_62 -> V_49 ) ;
for ( V_3 = 0 ; V_3 < V_27 -> V_79 ; V_3 ++ ) {
V_49 = V_27 -> V_78 [ V_3 ] -> V_49 ;
if ( V_49 -> V_10 -> V_147 == V_144 )
F_85 ( V_49 ) ;
}
if ( V_98 ) {
if ( V_98 -> V_49 -> V_10 -> V_147 == V_144 )
F_85 ( V_98 -> V_49 ) ;
}
}
static void F_92 ( struct V_63 * V_50 )
{
int V_144 ;
struct V_26 * V_27 ;
struct V_77 * V_131 , * V_132 ;
for ( V_144 = V_149 ; V_144 <= V_150 ;
V_144 ++ ) {
F_36 (rtd, &card->rtd_list, list)
F_89 ( V_50 , V_27 , V_144 ) ;
}
for ( V_144 = V_149 ; V_144 <= V_150 ;
V_144 ++ ) {
F_36 (rtd, &card->rtd_list, list)
F_91 ( V_50 , V_27 , V_144 ) ;
}
F_56 (link, _link, &card->dai_link_list, list) {
if ( V_131 -> V_151 . type == V_152 )
F_26 ( V_50 -> V_23 , L_36 ,
V_131 -> V_53 ) ;
F_57 ( & V_131 -> V_80 ) ;
V_50 -> V_153 -- ;
}
}
static int F_93 ( struct V_63 * V_50 ,
struct V_77 * V_71 )
{
if ( V_71 -> V_154 || V_71 -> V_155 ||
V_71 -> V_156 ) {
V_71 -> V_79 = 1 ;
V_71 -> V_133 = F_94 ( V_50 -> V_23 ,
sizeof( struct V_124 ) ,
V_40 ) ;
if ( ! V_71 -> V_133 )
return - V_41 ;
V_71 -> V_133 [ 0 ] . V_53 = V_71 -> V_154 ;
V_71 -> V_133 [ 0 ] . V_123 = V_71 -> V_155 ;
V_71 -> V_133 [ 0 ] . V_128 = V_71 -> V_156 ;
}
if ( ! V_71 -> V_133 ) {
F_78 ( V_50 -> V_23 , L_37 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_95 ( struct V_63 * V_50 ,
struct V_77 * V_131 )
{
int V_3 , V_14 ;
V_14 = F_93 ( V_50 , V_131 ) ;
if ( V_14 ) {
F_78 ( V_50 -> V_23 , L_38 ) ;
return V_14 ;
}
for ( V_3 = 0 ; V_3 < V_131 -> V_79 ; V_3 ++ ) {
if ( ! ! V_131 -> V_133 [ V_3 ] . V_53 ==
! ! V_131 -> V_133 [ V_3 ] . V_123 ) {
F_78 ( V_50 -> V_23 , L_39 ,
V_131 -> V_53 ) ;
return - V_15 ;
}
if ( ! V_131 -> V_133 [ V_3 ] . V_128 ) {
F_78 ( V_50 -> V_23 , L_40 ,
V_131 -> V_53 ) ;
return - V_15 ;
}
}
if ( V_131 -> V_136 && V_131 -> V_135 ) {
F_78 ( V_50 -> V_23 ,
L_41 ,
V_131 -> V_53 ) ;
return - V_15 ;
}
if ( V_131 -> V_137 && V_131 -> V_138 ) {
F_78 ( V_50 -> V_23 ,
L_42 ,
V_131 -> V_53 ) ;
return - V_15 ;
}
if ( ! V_131 -> V_139 &&
! ( V_131 -> V_137 || V_131 -> V_138 ) ) {
F_78 ( V_50 -> V_23 ,
L_43 ,
V_131 -> V_53 ) ;
return - V_15 ;
}
return 0 ;
}
int F_96 ( struct V_63 * V_50 ,
struct V_77 * V_71 )
{
if ( V_71 -> V_151 . type
&& V_71 -> V_151 . type != V_152 ) {
F_78 ( V_50 -> V_23 , L_44 ,
V_71 -> V_151 . type ) ;
return - V_15 ;
}
F_80 ( & V_58 ) ;
if ( V_71 -> V_151 . type && V_50 -> V_157 )
V_50 -> V_157 ( V_50 , V_71 ) ;
F_54 ( & V_71 -> V_80 , & V_50 -> V_158 ) ;
V_50 -> V_153 ++ ;
return 0 ;
}
void F_97 ( struct V_63 * V_50 ,
struct V_77 * V_71 )
{
struct V_77 * V_131 , * V_132 ;
if ( V_71 -> V_151 . type
&& V_71 -> V_151 . type != V_152 ) {
F_78 ( V_50 -> V_23 , L_44 ,
V_71 -> V_151 . type ) ;
return;
}
F_80 ( & V_58 ) ;
if ( V_71 -> V_151 . type && V_50 -> V_159 )
V_50 -> V_159 ( V_50 , V_71 ) ;
F_56 (link, _link, &card->dai_link_list, list) {
if ( V_131 == V_71 ) {
F_57 ( & V_131 -> V_80 ) ;
V_50 -> V_153 -- ;
return;
}
}
}
static void F_98 ( struct V_63 * V_50 ,
struct V_48 * V_49 )
{
int V_3 ;
if ( V_50 -> V_160 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_50 -> V_161 ; V_3 ++ ) {
struct V_162 * V_163 = & V_50 -> V_160 [ V_3 ] ;
if ( V_163 -> V_123 && V_49 -> V_23 -> V_123 != V_163 -> V_123 )
continue;
if ( V_163 -> V_164 && strcmp ( V_49 -> V_53 , V_163 -> V_164 ) )
continue;
V_49 -> V_165 = V_163 -> V_165 ;
break;
}
}
static int F_99 ( struct V_63 * V_50 ,
struct V_48 * V_49 )
{
struct V_106 * V_105 = F_28 ( V_49 ) ;
struct V_59 * V_60 ;
int V_14 ;
if ( ! strcmp ( V_49 -> V_53 , L_33 ) )
return 0 ;
if ( V_49 -> V_50 ) {
if ( V_49 -> V_50 != V_50 ) {
F_78 ( V_49 -> V_23 ,
L_45 ,
V_50 -> V_53 , V_49 -> V_50 -> V_53 ) ;
return - V_166 ;
}
return 0 ;
}
if ( ! F_100 ( V_49 -> V_23 -> V_10 -> V_143 ) )
return - V_166 ;
V_49 -> V_50 = V_50 ;
V_105 -> V_50 = V_50 ;
F_98 ( V_50 , V_49 ) ;
F_23 ( V_49 ) ;
if ( V_49 -> V_167 ) {
V_14 = F_101 ( V_105 , V_49 -> V_167 ,
V_49 -> V_168 ) ;
if ( V_14 != 0 ) {
F_78 ( V_49 -> V_23 ,
L_46 , V_14 ) ;
goto V_169;
}
}
F_36 (dai, &component->dai_list, list) {
V_14 = F_102 ( V_105 , V_60 ) ;
if ( V_14 != 0 ) {
F_78 ( V_49 -> V_23 ,
L_47 , V_14 ) ;
goto V_169;
}
}
if ( V_49 -> V_170 ) {
V_14 = V_49 -> V_170 ( V_49 ) ;
if ( V_14 < 0 ) {
F_78 ( V_49 -> V_23 ,
L_48 , V_14 ) ;
goto V_169;
}
F_103 ( V_105 -> V_109 &&
V_105 -> V_171 != V_110 ,
L_49 ,
V_49 -> V_53 ) ;
}
if ( V_49 -> V_172 ) {
V_14 = V_49 -> V_172 ( V_49 ) ;
if ( V_14 < 0 ) {
F_78 ( V_49 -> V_23 ,
L_50 , V_14 ) ;
goto V_169;
}
}
if ( V_49 -> V_173 )
F_104 ( V_49 , V_49 -> V_173 ,
V_49 -> V_174 ) ;
if ( V_49 -> V_175 )
F_105 ( V_105 , V_49 -> V_175 ,
V_49 -> V_176 ) ;
F_106 ( & V_105 -> V_80 , & V_50 -> V_177 ) ;
F_106 ( & V_49 -> V_142 , & V_50 -> V_178 ) ;
return 0 ;
V_169:
F_29 ( V_49 ) ;
V_49 -> V_50 = NULL ;
F_87 ( V_49 -> V_23 -> V_10 -> V_143 ) ;
return V_14 ;
}
static void F_107 ( struct V_22 * V_23 )
{
F_16 ( V_23 ) ;
}
static int F_108 ( struct V_26 * V_27 ,
const char * V_53 )
{
int V_14 = 0 ;
V_27 -> V_23 = F_51 ( sizeof( struct V_22 ) , V_40 ) ;
if ( ! V_27 -> V_23 )
return - V_41 ;
F_109 ( V_27 -> V_23 ) ;
V_27 -> V_23 -> V_127 = V_27 -> V_50 -> V_23 ;
V_27 -> V_23 -> V_179 = F_107 ;
V_27 -> V_23 -> V_180 = V_181 ;
F_110 ( V_27 -> V_23 , L_51 , V_53 ) ;
F_111 ( V_27 -> V_23 , V_27 ) ;
F_112 ( & V_27 -> V_182 ) ;
F_113 ( & V_27 -> V_183 [ V_102 ] . V_184 ) ;
F_113 ( & V_27 -> V_183 [ V_104 ] . V_184 ) ;
F_113 ( & V_27 -> V_183 [ V_102 ] . V_185 ) ;
F_113 ( & V_27 -> V_183 [ V_104 ] . V_185 ) ;
V_14 = F_114 ( V_27 -> V_23 ) ;
if ( V_14 < 0 ) {
F_115 ( V_27 -> V_23 ) ;
F_78 ( V_27 -> V_50 -> V_23 ,
L_52 , V_14 ) ;
return V_14 ;
}
V_27 -> V_148 = 1 ;
return 0 ;
}
static int F_116 ( struct V_63 * V_50 ,
struct V_26 * V_27 ,
int V_144 )
{
struct V_61 * V_62 = V_27 -> V_62 ;
struct V_48 * V_49 ;
int V_3 , V_14 ;
V_49 = V_27 -> V_98 -> V_49 ;
if ( V_49 -> V_10 -> V_186 == V_144 ) {
V_14 = F_99 ( V_50 , V_49 ) ;
if ( V_14 < 0 )
return V_14 ;
}
for ( V_3 = 0 ; V_3 < V_27 -> V_79 ; V_3 ++ ) {
V_49 = V_27 -> V_78 [ V_3 ] -> V_49 ;
if ( V_49 -> V_10 -> V_186 == V_144 ) {
V_14 = F_99 ( V_50 , V_49 ) ;
if ( V_14 < 0 )
return V_14 ;
}
}
if ( V_62 -> V_49 . V_10 -> V_186 == V_144 ) {
V_14 = F_99 ( V_50 , & V_62 -> V_49 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
static int F_117 ( struct V_59 * V_60 , int V_144 )
{
int V_14 ;
if ( ! V_60 -> V_146 && V_60 -> V_10 -> V_186 == V_144 ) {
if ( V_60 -> V_10 -> V_170 ) {
V_14 = V_60 -> V_10 -> V_170 ( V_60 ) ;
if ( V_14 < 0 ) {
F_78 ( V_60 -> V_23 ,
L_53 ,
V_60 -> V_53 , V_14 ) ;
return V_14 ;
}
}
V_60 -> V_146 = 1 ;
}
return 0 ;
}
static int F_118 ( struct V_59 * * V_187 , int V_188 ,
struct V_26 * V_27 )
{
int V_3 , V_14 = 0 ;
for ( V_3 = 0 ; V_3 < V_188 ; ++ V_3 ) {
struct V_92 * V_93 = V_187 [ V_3 ] -> V_10 ;
if ( ! V_27 -> V_71 -> V_73 && V_93 -> V_189 )
V_14 = V_93 -> V_189 ( V_27 , V_187 [ V_3 ] ) ;
if ( V_14 < 0 ) {
F_78 ( V_187 [ V_3 ] -> V_23 ,
L_54 ,
V_187 [ V_3 ] -> V_53 ) ;
return V_14 ;
}
}
return 0 ;
}
static int F_119 ( struct V_63 * V_50 ,
struct V_77 * V_71 ,
struct V_26 * V_27 )
{
struct V_59 * V_98 = V_27 -> V_98 ;
struct V_59 * V_121 = V_27 -> V_121 ;
struct V_190 * V_191 , * V_192 ;
int V_14 ;
if ( V_27 -> V_79 > 1 )
F_26 ( V_50 -> V_23 , L_55 ) ;
V_191 = V_121 -> V_193 ;
V_192 = V_98 -> V_194 ;
if ( V_191 && V_192 ) {
V_14 = F_120 ( V_50 , V_71 -> V_195 ,
V_71 -> V_196 ,
V_192 , V_191 ) ;
if ( V_14 != 0 ) {
F_78 ( V_50 -> V_23 , L_56 ,
V_191 -> V_53 , V_192 -> V_53 , V_14 ) ;
return V_14 ;
}
}
V_191 = V_98 -> V_193 ;
V_192 = V_121 -> V_194 ;
if ( V_191 && V_192 ) {
V_14 = F_120 ( V_50 , V_71 -> V_195 ,
V_71 -> V_196 ,
V_192 , V_191 ) ;
if ( V_14 != 0 ) {
F_78 ( V_50 -> V_23 , L_56 ,
V_191 -> V_53 , V_192 -> V_53 , V_14 ) ;
return V_14 ;
}
}
return 0 ;
}
static int F_121 ( struct V_63 * V_50 ,
struct V_26 * V_27 , int V_144 )
{
struct V_77 * V_71 = V_27 -> V_71 ;
struct V_59 * V_98 = V_27 -> V_98 ;
int V_3 , V_14 ;
F_49 ( V_50 -> V_23 , L_57 ,
V_50 -> V_53 , V_27 -> V_82 , V_144 ) ;
V_27 -> V_29 = V_29 ;
V_14 = F_117 ( V_98 , V_144 ) ;
if ( V_14 )
return V_14 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_79 ; V_3 ++ ) {
V_14 = F_117 ( V_27 -> V_78 [ V_3 ] , V_144 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_144 != V_150 )
return 0 ;
if ( V_71 -> V_172 ) {
V_14 = V_71 -> V_172 ( V_27 ) ;
if ( V_14 < 0 ) {
F_78 ( V_50 -> V_23 , L_58 ,
V_71 -> V_53 , V_14 ) ;
return V_14 ;
}
}
if ( V_71 -> V_197 )
F_122 ( V_27 , V_71 -> V_197 ) ;
V_14 = F_108 ( V_27 , V_71 -> V_53 ) ;
if ( V_14 )
return V_14 ;
#ifdef F_123
if ( V_71 -> V_198 )
F_124 ( V_27 ) ;
#endif
if ( V_98 -> V_10 -> V_199 ) {
V_14 = V_98 -> V_10 -> V_199 ( V_27 , V_27 -> V_82 ) ;
if ( V_14 < 0 ) {
F_78 ( V_50 -> V_23 , L_59 ,
V_71 -> V_130 ) ;
return V_14 ;
}
} else {
if ( ! V_71 -> V_195 ) {
V_14 = F_125 ( V_27 , V_27 -> V_82 ) ;
if ( V_14 < 0 ) {
F_78 ( V_50 -> V_23 , L_60 ,
V_71 -> V_130 , V_14 ) ;
return V_14 ;
}
V_14 = F_118 ( & V_98 , 1 , V_27 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_118 ( V_27 -> V_78 ,
V_27 -> V_79 , V_27 ) ;
if ( V_14 < 0 )
return V_14 ;
} else {
F_126 ( & V_27 -> V_101 ,
F_59 ) ;
V_14 = F_119 ( V_50 , V_71 , V_27 ) ;
if ( V_14 )
return V_14 ;
}
}
return 0 ;
}
static int F_127 ( struct V_63 * V_50 , int V_82 )
{
struct V_200 * V_201 = & V_50 -> V_201 [ V_82 ] ;
struct V_48 * V_49 ;
const char * V_53 ;
struct V_122 * V_155 ;
if ( V_201 -> V_155 || V_201 -> V_154 ) {
V_53 = V_201 -> V_154 ;
V_155 = V_201 -> V_155 ;
V_49 = F_79 ( V_155 , V_53 ) ;
if ( ! V_49 ) {
if ( V_155 )
V_53 = F_128 ( V_155 ) ;
goto V_202;
}
} else if ( V_201 -> V_53 ) {
V_53 = V_201 -> V_53 ;
V_49 = F_79 ( NULL , V_53 ) ;
if ( ! V_49 )
goto V_202;
} else {
F_78 ( V_50 -> V_23 , L_61 ) ;
return - V_15 ;
}
V_49 -> V_172 = V_201 -> V_172 ;
F_106 ( & V_49 -> V_203 , & V_50 -> V_204 ) ;
return 0 ;
V_202:
F_78 ( V_50 -> V_23 , L_62 , V_53 ) ;
return - V_141 ;
}
static int F_129 ( struct V_63 * V_50 )
{
struct V_48 * V_205 ;
int V_144 ;
int V_14 ;
for ( V_144 = V_149 ; V_144 <= V_150 ;
V_144 ++ ) {
F_36 (comp, &card->aux_comp_list, card_aux_list) {
if ( V_205 -> V_10 -> V_186 == V_144 ) {
V_14 = F_99 ( V_50 , V_205 ) ;
if ( V_14 < 0 ) {
F_78 ( V_50 -> V_23 ,
L_63 ,
V_205 -> V_53 , V_14 ) ;
return V_14 ;
}
}
}
}
return 0 ;
}
static void F_130 ( struct V_63 * V_50 )
{
struct V_48 * V_205 , * V_206 ;
int V_144 ;
for ( V_144 = V_149 ; V_144 <= V_150 ;
V_144 ++ ) {
F_56 (comp, _comp,
&card->aux_comp_list, card_aux_list) {
if ( V_205 -> V_10 -> V_147 == V_144 ) {
F_85 ( V_205 ) ;
F_57 ( & V_205 -> V_203 ) ;
}
}
}
}
static int F_131 ( struct V_4 * V_5 )
{
int V_14 ;
if ( V_5 -> V_207 )
return 0 ;
V_14 = F_132 ( V_5 ) ;
if ( V_14 < 0 ) {
F_78 ( V_5 -> V_23 ,
L_64 ,
V_14 ) ;
return V_14 ;
}
V_5 -> V_207 = 1 ;
return 0 ;
}
int F_122 ( struct V_26 * V_27 ,
unsigned int V_197 )
{
struct V_59 * * V_78 = V_27 -> V_78 ;
struct V_59 * V_98 = V_27 -> V_98 ;
unsigned int V_3 ;
int V_14 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_79 ; V_3 ++ ) {
struct V_59 * V_121 = V_78 [ V_3 ] ;
V_14 = F_133 ( V_121 , V_197 ) ;
if ( V_14 != 0 && V_14 != - V_208 ) {
F_26 ( V_121 -> V_23 ,
L_65 , V_14 ) ;
return V_14 ;
}
}
if ( V_98 -> V_5 ) {
unsigned int V_209 ;
V_209 = V_197 & ~ V_210 ;
switch ( V_197 & V_210 ) {
case V_211 :
V_209 |= V_212 ;
break;
case V_213 :
V_209 |= V_214 ;
break;
case V_214 :
V_209 |= V_213 ;
break;
case V_212 :
V_209 |= V_211 ;
break;
}
V_197 = V_209 ;
}
V_14 = F_133 ( V_98 , V_197 ) ;
if ( V_14 != 0 && V_14 != - V_208 ) {
F_26 ( V_98 -> V_23 ,
L_65 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static void F_134 ( char * V_53 )
{
int V_3 , V_119 = 0 ;
for ( V_3 = 0 ; V_53 [ V_3 ] ; V_3 ++ ) {
if ( isalnum ( V_53 [ V_3 ] ) || ( V_53 [ V_3 ] == '.' )
|| ( V_53 [ V_3 ] == '_' ) )
V_53 [ V_119 ++ ] = V_53 [ V_3 ] ;
else if ( V_53 [ V_3 ] == '-' )
V_53 [ V_119 ++ ] = '_' ;
}
V_53 [ V_119 ] = '\0' ;
}
static int F_135 ( const char * V_215 )
{
int V_3 = 0 ;
while ( V_216 [ V_3 ] ) {
if ( strstr ( V_215 , V_216 [ V_3 ] ) )
return 0 ;
V_3 ++ ;
}
return 1 ;
}
int F_136 ( struct V_63 * V_50 , const char * V_217 )
{
const char * V_218 , * V_219 , * V_220 , * V_221 ;
T_1 V_222 = sizeof( V_50 -> V_88 -> V_223 ) ;
T_1 V_8 ;
if ( V_50 -> V_224 )
return 0 ;
V_218 = F_137 ( V_225 ) ;
if ( ! V_218 || ! F_135 ( V_218 ) ) {
F_26 ( V_50 -> V_23 , L_66 ) ;
return 0 ;
}
snprintf ( V_50 -> V_226 , sizeof( V_50 -> V_88 -> V_223 ) ,
L_51 , V_218 ) ;
F_134 ( V_50 -> V_226 ) ;
V_219 = F_137 ( V_227 ) ;
if ( V_219 && F_135 ( V_219 ) ) {
V_8 = strlen ( V_50 -> V_226 ) ;
snprintf ( V_50 -> V_226 + V_8 ,
V_222 - V_8 ,
L_67 , V_219 ) ;
V_8 ++ ;
if ( V_8 < V_222 )
F_134 ( V_50 -> V_226 + V_8 ) ;
V_220 = F_137 ( V_228 ) ;
if ( V_220 && F_135 ( V_220 ) ) {
V_8 = strlen ( V_50 -> V_226 ) ;
snprintf ( V_50 -> V_226 + V_8 ,
V_222 - V_8 ,
L_67 , V_220 ) ;
V_8 ++ ;
if ( V_8 < V_222 )
F_134 ( V_50 -> V_226 + V_8 ) ;
}
}
V_221 = F_137 ( V_229 ) ;
if ( V_221 && F_135 ( V_221 ) ) {
V_8 = strlen ( V_50 -> V_226 ) ;
snprintf ( V_50 -> V_226 + V_8 ,
V_222 - V_8 ,
L_67 , V_221 ) ;
V_8 ++ ;
if ( V_8 < V_222 )
F_134 ( V_50 -> V_226 + V_8 ) ;
} else if ( ! V_219 ) {
F_26 ( V_50 -> V_23 , L_68 ) ;
return 0 ;
}
if ( V_217 ) {
V_8 = strlen ( V_50 -> V_226 ) ;
snprintf ( V_50 -> V_226 + V_8 ,
V_222 - V_8 ,
L_67 , V_217 ) ;
V_8 ++ ;
if ( V_8 < V_222 )
F_134 ( V_50 -> V_226 + V_8 ) ;
}
V_50 -> V_224 = V_50 -> V_226 ;
return 0 ;
}
static int F_138 ( struct V_63 * V_50 )
{
struct V_4 * V_5 ;
struct V_26 * V_27 ;
struct V_77 * V_71 ;
int V_14 , V_3 , V_144 ;
F_35 ( & V_58 ) ;
F_139 ( & V_50 -> V_230 , V_231 ) ;
for ( V_3 = 0 ; V_3 < V_50 -> V_232 ; V_3 ++ ) {
V_14 = F_84 ( V_50 , & V_50 -> V_71 [ V_3 ] ) ;
if ( V_14 != 0 )
goto V_233;
}
for ( V_3 = 0 ; V_3 < V_50 -> V_234 ; V_3 ++ ) {
V_14 = F_127 ( V_50 , V_3 ) ;
if ( V_14 != 0 )
goto V_233;
}
for ( V_3 = 0 ; V_3 < V_50 -> V_232 ; V_3 ++ )
F_96 ( V_50 , V_50 -> V_71 + V_3 ) ;
F_36 (codec, &codec_list, list) {
if ( V_5 -> V_207 )
continue;
V_14 = F_131 ( V_5 ) ;
if ( V_14 < 0 )
goto V_233;
}
V_14 = F_140 ( V_50 -> V_23 , V_235 , V_236 ,
V_50 -> V_143 , 0 , & V_50 -> V_88 ) ;
if ( V_14 < 0 ) {
F_78 ( V_50 -> V_23 ,
L_69 ,
V_50 -> V_53 , V_14 ) ;
goto V_233;
}
F_41 ( V_50 ) ;
V_50 -> V_105 . V_171 = V_110 ;
V_50 -> V_105 . V_23 = V_50 -> V_23 ;
V_50 -> V_105 . V_50 = V_50 ;
F_106 ( & V_50 -> V_105 . V_80 , & V_50 -> V_177 ) ;
#ifdef F_123
F_27 ( & V_50 -> V_105 , V_50 -> V_51 ) ;
#endif
#ifdef F_141
F_142 ( & V_50 -> V_113 , F_73 ) ;
#endif
if ( V_50 -> V_167 )
F_101 ( & V_50 -> V_105 , V_50 -> V_167 ,
V_50 -> V_168 ) ;
if ( V_50 -> V_237 )
F_101 ( & V_50 -> V_105 , V_50 -> V_237 ,
V_50 -> V_238 ) ;
if ( V_50 -> V_170 ) {
V_14 = V_50 -> V_170 ( V_50 ) ;
if ( V_14 < 0 )
goto V_239;
}
for ( V_144 = V_149 ; V_144 <= V_150 ;
V_144 ++ ) {
F_36 (rtd, &card->rtd_list, list) {
V_14 = F_116 ( V_50 , V_27 , V_144 ) ;
if ( V_14 < 0 ) {
F_78 ( V_50 -> V_23 ,
L_70 ,
V_14 ) ;
goto V_240;
}
}
}
V_14 = F_129 ( V_50 ) ;
if ( V_14 < 0 )
goto V_240;
F_36 (dai_link, &card->dai_link_list, list) {
if ( F_83 ( V_50 , V_71 ) )
continue;
V_14 = F_95 ( V_50 , V_71 ) ;
if ( V_14 )
goto V_240;
V_14 = F_84 ( V_50 , V_71 ) ;
if ( V_14 )
goto V_240;
}
for ( V_144 = V_149 ; V_144 <= V_150 ;
V_144 ++ ) {
F_36 (rtd, &card->rtd_list, list) {
V_14 = F_121 ( V_50 , V_27 , V_144 ) ;
if ( V_14 < 0 ) {
F_78 ( V_50 -> V_23 ,
L_70 ,
V_14 ) ;
goto V_240;
}
}
}
F_143 ( V_50 ) ;
F_144 ( V_50 ) ;
if ( V_50 -> V_173 )
F_145 ( V_50 , V_50 -> V_173 , V_50 -> V_174 ) ;
if ( V_50 -> V_175 )
F_105 ( & V_50 -> V_105 , V_50 -> V_175 ,
V_50 -> V_176 ) ;
if ( V_50 -> V_241 )
F_105 ( & V_50 -> V_105 , V_50 -> V_241 ,
V_50 -> V_242 ) ;
F_136 ( V_50 , NULL ) ;
snprintf ( V_50 -> V_88 -> V_243 , sizeof( V_50 -> V_88 -> V_243 ) ,
L_51 , V_50 -> V_53 ) ;
snprintf ( V_50 -> V_88 -> V_223 , sizeof( V_50 -> V_88 -> V_223 ) ,
L_51 , V_50 -> V_224 ? V_50 -> V_224 : V_50 -> V_53 ) ;
snprintf ( V_50 -> V_88 -> V_10 , sizeof( V_50 -> V_88 -> V_10 ) ,
L_51 , V_50 -> V_244 ? V_50 -> V_244 : V_50 -> V_53 ) ;
for ( V_3 = 0 ; V_3 < F_146 ( V_50 -> V_88 -> V_10 ) ; V_3 ++ ) {
switch ( V_50 -> V_88 -> V_10 [ V_3 ] ) {
case '_' :
case '-' :
case '\0' :
break;
default:
if ( ! isalnum ( V_50 -> V_88 -> V_10 [ V_3 ] ) )
V_50 -> V_88 -> V_10 [ V_3 ] = '_' ;
break;
}
}
if ( V_50 -> V_245 ) {
V_14 = V_50 -> V_245 ( V_50 ) ;
if ( V_14 < 0 ) {
F_78 ( V_50 -> V_23 , L_71 ,
V_50 -> V_53 , V_14 ) ;
goto V_246;
}
}
F_147 ( V_50 ) ;
V_14 = F_148 ( V_50 -> V_88 ) ;
if ( V_14 < 0 ) {
F_78 ( V_50 -> V_23 , L_72 ,
V_14 ) ;
goto V_246;
}
V_50 -> V_87 = 1 ;
F_69 ( & V_50 -> V_105 ) ;
F_37 ( & V_50 -> V_230 ) ;
F_37 ( & V_58 ) ;
return 0 ;
V_246:
F_130 ( V_50 ) ;
V_240:
F_92 ( V_50 ) ;
V_239:
if ( V_50 -> remove )
V_50 -> remove ( V_50 ) ;
F_86 ( & V_50 -> V_105 ) ;
F_43 ( V_50 ) ;
F_149 ( V_50 -> V_88 ) ;
V_233:
F_55 ( V_50 ) ;
F_37 ( & V_50 -> V_230 ) ;
F_37 ( & V_58 ) ;
return V_14 ;
}
static int F_150 ( struct V_247 * V_248 )
{
struct V_63 * V_50 = F_151 ( V_248 ) ;
if ( ! V_50 )
return - V_15 ;
F_26 ( & V_248 -> V_23 ,
L_73 ,
V_50 -> V_53 ) ;
V_50 -> V_23 = & V_248 -> V_23 ;
return F_152 ( V_50 ) ;
}
static int F_153 ( struct V_63 * V_50 )
{
struct V_26 * V_27 ;
F_36 (rtd, &card->rtd_list, list)
F_66 ( & V_27 -> V_101 ) ;
F_149 ( V_50 -> V_88 ) ;
F_92 ( V_50 ) ;
F_55 ( V_50 ) ;
F_130 ( V_50 ) ;
F_86 ( & V_50 -> V_105 ) ;
F_43 ( V_50 ) ;
if ( V_50 -> remove )
V_50 -> remove ( V_50 ) ;
return 0 ;
}
static int F_154 ( struct V_247 * V_248 )
{
struct V_63 * V_50 = F_151 ( V_248 ) ;
F_155 ( V_50 ) ;
return 0 ;
}
int F_156 ( struct V_22 * V_23 )
{
struct V_63 * V_50 = F_7 ( V_23 ) ;
struct V_26 * V_27 ;
if ( ! V_50 -> V_87 )
return 0 ;
F_36 (rtd, &card->rtd_list, list)
F_66 ( & V_27 -> V_101 ) ;
F_157 ( V_50 ) ;
F_36 (rtd, &card->rtd_list, list) {
struct V_59 * V_98 = V_27 -> V_98 ;
int V_3 ;
F_72 ( V_98 -> V_23 ) ;
for ( V_3 = 0 ; V_3 < V_27 -> V_79 ; V_3 ++ ) {
struct V_59 * V_121 = V_27 -> V_78 [ V_3 ] ;
F_72 ( V_121 -> V_23 ) ;
}
}
return 0 ;
}
struct V_249 * F_158 ( const struct V_250 * V_251 ,
void * V_252 , const char * V_224 ,
const char * V_253 )
{
struct V_250 V_254 ;
struct V_249 * V_255 ;
char * V_53 = NULL ;
memcpy ( & V_254 , V_251 , sizeof( V_254 ) ) ;
V_254 . V_256 = 0 ;
if ( ! V_224 )
V_224 = V_254 . V_53 ;
if ( V_253 ) {
V_53 = F_24 ( V_40 , L_74 , V_253 , V_224 ) ;
if ( ! V_53 )
return NULL ;
V_254 . V_53 = V_53 ;
} else {
V_254 . V_53 = V_224 ;
}
V_255 = F_159 ( & V_254 , V_252 ) ;
F_16 ( V_53 ) ;
return V_255 ;
}
static int F_160 ( struct V_88 * V_50 , struct V_22 * V_23 ,
const struct V_250 * V_173 , int V_174 ,
const char * V_253 , void * V_252 )
{
int V_145 , V_3 ;
for ( V_3 = 0 ; V_3 < V_174 ; V_3 ++ ) {
const struct V_250 * V_257 = & V_173 [ V_3 ] ;
V_145 = F_161 ( V_50 , F_158 ( V_257 , V_252 ,
V_257 -> V_53 , V_253 ) ) ;
if ( V_145 < 0 ) {
F_78 ( V_23 , L_75 ,
V_257 -> V_53 , V_145 ) ;
return V_145 ;
}
}
return 0 ;
}
struct V_249 * F_162 ( struct V_63 * V_258 ,
const char * V_53 )
{
struct V_88 * V_50 = V_258 -> V_88 ;
struct V_249 * V_259 ;
if ( F_163 ( ! V_53 ) )
return NULL ;
F_36 (kctl, &card->controls, list)
if ( ! strncmp ( V_259 -> V_129 . V_53 , V_53 , sizeof( V_259 -> V_129 . V_53 ) ) )
return V_259 ;
return NULL ;
}
int F_104 ( struct V_48 * V_49 ,
const struct V_250 * V_173 , unsigned int V_174 )
{
struct V_88 * V_50 = V_49 -> V_50 -> V_88 ;
return F_160 ( V_50 , V_49 -> V_23 , V_173 ,
V_174 , V_49 -> V_165 , V_49 ) ;
}
int F_164 ( struct V_4 * V_5 ,
const struct V_250 * V_173 , unsigned int V_174 )
{
return F_104 ( & V_5 -> V_49 , V_173 ,
V_174 ) ;
}
int F_165 ( struct V_61 * V_62 ,
const struct V_250 * V_173 , unsigned int V_174 )
{
return F_104 ( & V_62 -> V_49 , V_173 ,
V_174 ) ;
}
int F_145 ( struct V_63 * V_258 ,
const struct V_250 * V_173 , int V_174 )
{
struct V_88 * V_50 = V_258 -> V_88 ;
return F_160 ( V_50 , V_258 -> V_23 , V_173 , V_174 ,
NULL , V_258 ) ;
}
int F_166 ( struct V_59 * V_60 ,
const struct V_250 * V_173 , int V_174 )
{
struct V_88 * V_50 = V_60 -> V_49 -> V_50 -> V_88 ;
return F_160 ( V_50 , V_60 -> V_23 , V_173 , V_174 ,
NULL , V_60 ) ;
}
int F_167 ( struct V_59 * V_60 , int V_260 ,
unsigned int V_261 , int V_262 )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_94 -> V_263 )
return V_60 -> V_10 -> V_94 -> V_263 ( V_60 , V_260 , V_261 , V_262 ) ;
else if ( V_60 -> V_5 && V_60 -> V_5 -> V_10 -> V_263 )
return V_60 -> V_5 -> V_10 -> V_263 ( V_60 -> V_5 , V_260 , 0 ,
V_261 , V_262 ) ;
else
return - V_208 ;
}
int F_168 ( struct V_4 * V_5 , int V_260 ,
int V_192 , unsigned int V_261 , int V_262 )
{
if ( V_5 -> V_10 -> V_263 )
return V_5 -> V_10 -> V_263 ( V_5 , V_260 , V_192 ,
V_261 , V_262 ) ;
else
return - V_208 ;
}
int F_169 ( struct V_59 * V_60 ,
int V_264 , int div )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_94 -> V_265 )
return V_60 -> V_10 -> V_94 -> V_265 ( V_60 , V_264 , div ) ;
else
return - V_15 ;
}
int F_170 ( struct V_59 * V_60 , int V_266 , int V_192 ,
unsigned int V_267 , unsigned int V_268 )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_94 -> V_269 )
return V_60 -> V_10 -> V_94 -> V_269 ( V_60 , V_266 , V_192 ,
V_267 , V_268 ) ;
else if ( V_60 -> V_5 && V_60 -> V_5 -> V_10 -> V_269 )
return V_60 -> V_5 -> V_10 -> V_269 ( V_60 -> V_5 , V_266 , V_192 ,
V_267 , V_268 ) ;
else
return - V_15 ;
}
int F_171 ( struct V_4 * V_5 , int V_266 , int V_192 ,
unsigned int V_267 , unsigned int V_268 )
{
if ( V_5 -> V_10 -> V_269 )
return V_5 -> V_10 -> V_269 ( V_5 , V_266 , V_192 ,
V_267 , V_268 ) ;
else
return - V_15 ;
}
int F_172 ( struct V_59 * V_60 , unsigned int V_270 )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_94 -> V_271 )
return V_60 -> V_10 -> V_94 -> V_271 ( V_60 , V_270 ) ;
else
return - V_15 ;
}
int F_133 ( struct V_59 * V_60 , unsigned int V_272 )
{
if ( V_60 -> V_10 == NULL )
return - V_15 ;
if ( V_60 -> V_10 -> V_94 -> V_273 == NULL )
return - V_208 ;
return V_60 -> V_10 -> V_94 -> V_273 ( V_60 , V_272 ) ;
}
static int F_173 ( unsigned int V_274 ,
unsigned int * V_275 ,
unsigned int * V_276 )
{
if ( * V_275 || * V_276 )
return 0 ;
if ( ! V_274 )
return - V_15 ;
* V_275 = ( 1 << V_274 ) - 1 ;
* V_276 = ( 1 << V_274 ) - 1 ;
return 0 ;
}
int F_174 ( struct V_59 * V_60 ,
unsigned int V_275 , unsigned int V_276 , int V_274 , int V_277 )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_94 -> V_278 )
V_60 -> V_10 -> V_94 -> V_278 ( V_274 ,
& V_275 , & V_276 ) ;
else
F_173 ( V_274 , & V_275 , & V_276 ) ;
V_60 -> V_275 = V_275 ;
V_60 -> V_276 = V_276 ;
if ( V_60 -> V_10 && V_60 -> V_10 -> V_94 -> V_279 )
return V_60 -> V_10 -> V_94 -> V_279 ( V_60 , V_275 , V_276 ,
V_274 , V_277 ) ;
else
return - V_208 ;
}
int F_175 ( struct V_59 * V_60 ,
unsigned int V_280 , unsigned int * V_281 ,
unsigned int V_282 , unsigned int * V_283 )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_94 -> V_284 )
return V_60 -> V_10 -> V_94 -> V_284 ( V_60 , V_280 , V_281 ,
V_282 , V_283 ) ;
else
return - V_15 ;
}
int F_176 ( struct V_59 * V_60 , int V_285 )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_94 -> V_286 )
return V_60 -> V_10 -> V_94 -> V_286 ( V_60 , V_285 ) ;
else
return - V_15 ;
}
int F_177 ( struct V_59 * V_60 , int V_287 ,
int V_288 )
{
if ( ! V_60 -> V_10 )
return - V_208 ;
if ( V_60 -> V_10 -> V_94 -> V_289 )
return V_60 -> V_10 -> V_94 -> V_289 ( V_60 , V_287 , V_288 ) ;
else if ( V_288 == V_102 &&
V_60 -> V_10 -> V_94 -> V_95 )
return V_60 -> V_10 -> V_94 -> V_95 ( V_60 , V_287 ) ;
else
return - V_208 ;
}
int F_152 ( struct V_63 * V_50 )
{
int V_3 , V_14 ;
struct V_26 * V_27 ;
if ( ! V_50 -> V_53 || ! V_50 -> V_23 )
return - V_15 ;
for ( V_3 = 0 ; V_3 < V_50 -> V_232 ; V_3 ++ ) {
struct V_77 * V_131 = & V_50 -> V_71 [ V_3 ] ;
V_14 = F_95 ( V_50 , V_131 ) ;
if ( V_14 ) {
F_78 ( V_50 -> V_23 , L_76 ,
V_131 -> V_53 ) ;
return V_14 ;
}
}
F_111 ( V_50 -> V_23 , V_50 ) ;
F_178 ( V_50 ) ;
F_113 ( & V_50 -> V_158 ) ;
V_50 -> V_153 = 0 ;
F_113 ( & V_50 -> V_81 ) ;
V_50 -> V_83 = 0 ;
F_113 ( & V_50 -> V_290 ) ;
F_113 ( & V_50 -> V_291 ) ;
V_50 -> V_87 = 0 ;
F_112 ( & V_50 -> V_230 ) ;
F_112 ( & V_50 -> V_292 ) ;
V_14 = F_138 ( V_50 ) ;
if ( V_14 != 0 )
return V_14 ;
F_36 (rtd, &card->rtd_list, list) {
struct V_59 * V_98 = V_27 -> V_98 ;
int V_119 ;
for ( V_119 = 0 ; V_119 < V_27 -> V_79 ; V_119 ++ ) {
struct V_59 * V_121 = V_27 -> V_78 [ V_119 ] ;
if ( ! V_121 -> V_120 )
F_72 ( V_121 -> V_23 ) ;
}
if ( ! V_98 -> V_120 )
F_72 ( V_98 -> V_23 ) ;
}
return V_14 ;
}
int F_155 ( struct V_63 * V_50 )
{
if ( V_50 -> V_87 ) {
V_50 -> V_87 = false ;
F_157 ( V_50 ) ;
F_153 ( V_50 ) ;
F_49 ( V_50 -> V_23 , L_77 , V_50 -> V_53 ) ;
}
return 0 ;
}
static char * F_179 ( struct V_22 * V_23 , int * V_129 )
{
char * V_293 , V_53 [ V_294 ] ;
int V_295 , V_296 ;
if ( V_164 ( V_23 ) == NULL )
return NULL ;
F_180 ( V_53 , V_164 ( V_23 ) , V_294 ) ;
V_293 = strstr ( V_53 , V_23 -> V_10 -> V_53 ) ;
if ( V_293 ) {
if ( sscanf ( & V_293 [ strlen ( V_23 -> V_10 -> V_53 ) ] , L_78 , V_129 ) == 1 ) {
if ( * V_129 == - 1 )
V_293 [ strlen ( V_23 -> V_10 -> V_53 ) ] = '\0' ;
}
} else {
if ( sscanf ( V_53 , L_79 , & V_295 , & V_296 ) == 2 ) {
char V_297 [ V_294 ] ;
* V_129 = ( ( V_295 & 0xffff ) << 16 ) + V_296 ;
snprintf ( V_297 , V_294 , L_80 , V_23 -> V_10 -> V_53 , V_53 ) ;
F_180 ( V_53 , V_297 , V_294 ) ;
} else
* V_129 = 0 ;
}
return F_181 ( V_53 , V_40 ) ;
}
static inline char * F_182 ( struct V_22 * V_23 ,
struct V_92 * V_298 )
{
if ( V_298 -> V_53 == NULL ) {
F_78 ( V_23 ,
L_81 ,
V_164 ( V_23 ) ) ;
return NULL ;
}
return F_181 ( V_298 -> V_53 , V_40 ) ;
}
static void F_183 ( struct V_48 * V_49 )
{
struct V_59 * V_60 , * V_299 ;
F_56 (dai, _dai, &component->dai_list, list) {
F_49 ( V_49 -> V_23 , L_82 ,
V_60 -> V_53 ) ;
F_57 ( & V_60 -> V_80 ) ;
F_16 ( V_60 -> V_53 ) ;
F_16 ( V_60 ) ;
}
}
static struct V_59 * F_184 ( struct V_48 * V_49 ,
struct V_92 * V_298 ,
bool V_300 )
{
struct V_22 * V_23 = V_49 -> V_23 ;
struct V_59 * V_60 ;
F_49 ( V_23 , L_83 , V_164 ( V_23 ) ) ;
V_60 = F_51 ( sizeof( struct V_59 ) , V_40 ) ;
if ( V_60 == NULL )
return NULL ;
if ( V_300 &&
( V_298 -> V_129 == 0 || V_298 -> V_53 == NULL ) ) {
V_60 -> V_53 = F_179 ( V_23 , & V_60 -> V_129 ) ;
} else {
V_60 -> V_53 = F_182 ( V_23 , V_298 ) ;
if ( V_298 -> V_129 )
V_60 -> V_129 = V_298 -> V_129 ;
else
V_60 -> V_129 = V_49 -> V_301 ;
}
if ( V_60 -> V_53 == NULL ) {
F_16 ( V_60 ) ;
return NULL ;
}
V_60 -> V_49 = V_49 ;
V_60 -> V_23 = V_23 ;
V_60 -> V_10 = V_298 ;
if ( ! V_60 -> V_10 -> V_94 )
V_60 -> V_10 -> V_94 = & V_302 ;
F_106 ( & V_60 -> V_80 , & V_49 -> V_303 ) ;
V_49 -> V_301 ++ ;
F_49 ( V_23 , L_84 , V_60 -> V_53 ) ;
return V_60 ;
}
static int F_185 ( struct V_48 * V_49 ,
struct V_92 * V_298 , T_1 V_16 ,
bool V_300 )
{
struct V_22 * V_23 = V_49 -> V_23 ;
struct V_59 * V_60 ;
unsigned int V_3 ;
int V_14 ;
F_49 ( V_23 , L_85 , V_164 ( V_23 ) , V_16 ) ;
V_49 -> V_298 = V_298 ;
for ( V_3 = 0 ; V_3 < V_16 ; V_3 ++ ) {
V_60 = F_184 ( V_49 , V_298 + V_3 ,
V_16 == 1 && V_300 ) ;
if ( V_60 == NULL ) {
V_14 = - V_41 ;
goto V_145;
}
}
return 0 ;
V_145:
F_183 ( V_49 ) ;
return V_14 ;
}
int F_186 ( struct V_48 * V_49 ,
struct V_92 * V_298 )
{
struct V_106 * V_105 =
F_28 ( V_49 ) ;
struct V_59 * V_60 ;
int V_14 ;
if ( V_298 -> V_151 . type != V_304 ) {
F_78 ( V_49 -> V_23 , L_86 ,
V_298 -> V_151 . type ) ;
return - V_15 ;
}
F_80 ( & V_58 ) ;
V_60 = F_184 ( V_49 , V_298 , false ) ;
if ( ! V_60 )
return - V_41 ;
V_14 = F_102 ( V_105 , V_60 ) ;
if ( V_14 != 0 ) {
F_78 ( V_49 -> V_23 ,
L_47 , V_14 ) ;
}
return V_14 ;
}
static void F_187 ( struct V_106 * V_105 ,
enum V_305 type , int V_306 )
{
struct V_48 * V_49 = V_105 -> V_49 ;
V_49 -> V_10 -> V_307 ( V_49 , type , V_306 ) ;
}
static int F_188 ( struct V_106 * V_105 ,
int V_308 )
{
struct V_48 * V_49 = V_105 -> V_49 ;
return V_49 -> V_10 -> V_309 ( V_49 , V_308 ) ;
}
static int F_189 ( struct V_48 * V_49 ,
const struct V_310 * V_10 , struct V_22 * V_23 )
{
struct V_106 * V_105 ;
V_49 -> V_53 = F_179 ( V_23 , & V_49 -> V_129 ) ;
if ( ! V_49 -> V_53 ) {
F_78 ( V_23 , L_87 ) ;
return - V_41 ;
}
V_49 -> V_23 = V_23 ;
V_49 -> V_10 = V_10 ;
V_49 -> V_170 = V_49 -> V_10 -> V_170 ;
V_49 -> remove = V_49 -> V_10 -> remove ;
V_49 -> V_99 = V_49 -> V_10 -> V_99 ;
V_49 -> V_116 = V_49 -> V_10 -> V_116 ;
V_105 = & V_49 -> V_105 ;
V_105 -> V_23 = V_23 ;
V_105 -> V_49 = V_49 ;
V_105 -> V_171 = V_110 ;
V_105 -> V_109 = true ;
if ( V_10 -> V_307 )
V_105 -> V_307 = F_187 ;
if ( V_10 -> V_309 )
V_105 -> V_309 = F_188 ;
V_49 -> V_173 = V_10 -> V_173 ;
V_49 -> V_174 = V_10 -> V_174 ;
V_49 -> V_167 = V_10 -> V_167 ;
V_49 -> V_168 = V_10 -> V_168 ;
V_49 -> V_175 = V_10 -> V_175 ;
V_49 -> V_176 = V_10 -> V_176 ;
F_113 ( & V_49 -> V_303 ) ;
F_112 ( & V_49 -> V_311 ) ;
return 0 ;
}
static void F_190 ( struct V_48 * V_49 )
{
int V_312 = F_191 ( V_49 -> V_111 ) ;
if ( V_312 > 0 )
V_49 -> V_312 = V_312 ;
}
void F_192 ( struct V_48 * V_49 ,
struct V_111 * V_111 )
{
V_49 -> V_111 = V_111 ;
F_190 ( V_49 ) ;
}
void F_193 ( struct V_48 * V_49 )
{
F_194 ( V_49 -> V_111 ) ;
V_49 -> V_111 = NULL ;
}
static void F_195 ( struct V_48 * V_49 )
{
if ( ! V_49 -> V_313 && ! V_49 -> V_314 ) {
if ( ! V_49 -> V_111 )
V_49 -> V_111 = F_196 ( V_49 -> V_23 , NULL ) ;
if ( V_49 -> V_111 )
F_190 ( V_49 ) ;
}
F_106 ( & V_49 -> V_80 , & V_315 ) ;
F_113 ( & V_49 -> V_291 ) ;
}
static void F_197 ( struct V_48 * V_49 )
{
F_35 ( & V_58 ) ;
F_195 ( V_49 ) ;
F_37 ( & V_58 ) ;
}
static void F_198 ( struct V_48 * V_49 )
{
F_183 ( V_49 ) ;
F_16 ( V_49 -> V_53 ) ;
}
static void F_199 ( struct V_48 * V_49 )
{
struct V_63 * V_50 = V_49 -> V_50 ;
if ( V_50 )
F_155 ( V_50 ) ;
F_57 ( & V_49 -> V_80 ) ;
}
int F_200 ( struct V_22 * V_23 ,
const struct V_310 * V_316 ,
struct V_92 * V_298 ,
int V_301 )
{
struct V_48 * V_317 ;
int V_14 ;
V_317 = F_51 ( sizeof( * V_317 ) , V_40 ) ;
if ( ! V_317 ) {
F_78 ( V_23 , L_88 ) ;
return - V_41 ;
}
V_14 = F_189 ( V_317 , V_316 , V_23 ) ;
if ( V_14 )
goto V_318;
V_317 -> V_319 = true ;
V_317 -> V_320 = true ;
V_14 = F_185 ( V_317 , V_298 , V_301 , true ) ;
if ( V_14 < 0 ) {
F_78 ( V_23 , L_89 , V_14 ) ;
goto V_321;
}
F_197 ( V_317 ) ;
return 0 ;
V_321:
F_198 ( V_317 ) ;
V_318:
F_16 ( V_317 ) ;
return V_14 ;
}
void F_201 ( struct V_22 * V_23 )
{
struct V_48 * V_317 ;
F_35 ( & V_58 ) ;
F_36 (cmpnt, &component_list, list) {
if ( V_23 == V_317 -> V_23 && V_317 -> V_320 )
goto V_293;
}
F_37 ( & V_58 ) ;
return;
V_293:
F_202 ( V_317 , V_322 ) ;
F_199 ( V_317 ) ;
F_37 ( & V_58 ) ;
F_198 ( V_317 ) ;
F_16 ( V_317 ) ;
}
static int F_203 ( struct V_48 * V_49 )
{
struct V_61 * V_62 = F_204 ( V_49 ) ;
return V_62 -> V_10 -> V_170 ( V_62 ) ;
}
static void F_205 ( struct V_48 * V_49 )
{
struct V_61 * V_62 = F_204 ( V_49 ) ;
V_62 -> V_10 -> remove ( V_62 ) ;
}
int F_206 ( struct V_22 * V_23 , struct V_61 * V_62 ,
const struct V_323 * V_324 )
{
int V_14 ;
V_14 = F_189 ( & V_62 -> V_49 ,
& V_324 -> V_325 , V_23 ) ;
if ( V_14 )
return V_14 ;
V_62 -> V_23 = V_23 ;
V_62 -> V_10 = V_324 ;
if ( V_324 -> V_170 )
V_62 -> V_49 . V_170 = F_203 ;
if ( V_324 -> remove )
V_62 -> V_49 . remove = F_205 ;
#ifdef F_123
V_62 -> V_49 . V_52 = L_90 ;
#endif
F_35 ( & V_58 ) ;
F_195 ( & V_62 -> V_49 ) ;
F_106 ( & V_62 -> V_80 , & V_326 ) ;
F_37 ( & V_58 ) ;
F_49 ( V_23 , L_91 ,
V_62 -> V_49 . V_53 ) ;
return 0 ;
}
int F_207 ( struct V_22 * V_23 ,
const struct V_323 * V_324 )
{
struct V_61 * V_62 ;
int V_14 ;
F_49 ( V_23 , L_92 , V_164 ( V_23 ) ) ;
V_62 = F_51 ( sizeof( struct V_61 ) , V_40 ) ;
if ( V_62 == NULL )
return - V_41 ;
V_14 = F_206 ( V_23 , V_62 , V_324 ) ;
if ( V_14 )
F_16 ( V_62 ) ;
return V_14 ;
}
void F_208 ( struct V_61 * V_62 )
{
F_35 ( & V_58 ) ;
F_57 ( & V_62 -> V_80 ) ;
F_199 ( & V_62 -> V_49 ) ;
F_37 ( & V_58 ) ;
F_49 ( V_62 -> V_23 , L_93 ,
V_62 -> V_49 . V_53 ) ;
F_198 ( & V_62 -> V_49 ) ;
}
struct V_61 * F_209 ( struct V_22 * V_23 )
{
struct V_61 * V_62 ;
F_35 ( & V_58 ) ;
F_36 (platform, &platform_list, list) {
if ( V_23 == V_62 -> V_23 ) {
F_37 ( & V_58 ) ;
return V_62 ;
}
}
F_37 ( & V_58 ) ;
return NULL ;
}
void F_210 ( struct V_22 * V_23 )
{
struct V_61 * V_62 ;
V_62 = F_209 ( V_23 ) ;
if ( ! V_62 )
return;
F_208 ( V_62 ) ;
F_16 ( V_62 ) ;
}
static void F_211 ( struct V_327 * V_72 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_146 ( V_328 ) ; V_3 ++ )
if ( V_72 -> V_329 & V_328 [ V_3 ] )
V_72 -> V_329 |= V_328 [ V_3 ] ;
}
static int F_212 ( struct V_48 * V_49 )
{
struct V_4 * V_5 = F_32 ( V_49 ) ;
return V_5 -> V_10 -> V_170 ( V_5 ) ;
}
static void F_213 ( struct V_48 * V_49 )
{
struct V_4 * V_5 = F_32 ( V_49 ) ;
V_5 -> V_10 -> remove ( V_5 ) ;
}
static int F_214 ( struct V_48 * V_49 )
{
struct V_4 * V_5 = F_32 ( V_49 ) ;
return V_5 -> V_10 -> V_99 ( V_5 ) ;
}
static int F_215 ( struct V_48 * V_49 )
{
struct V_4 * V_5 = F_32 ( V_49 ) ;
return V_5 -> V_10 -> V_116 ( V_5 ) ;
}
static int F_216 ( struct V_48 * V_49 ,
unsigned int V_6 , unsigned int V_1 )
{
struct V_4 * V_5 = F_32 ( V_49 ) ;
return V_5 -> V_10 -> V_313 ( V_5 , V_6 , V_1 ) ;
}
static int F_217 ( struct V_48 * V_49 ,
unsigned int V_6 , unsigned int * V_1 )
{
struct V_4 * V_5 = F_32 ( V_49 ) ;
* V_1 = V_5 -> V_10 -> V_314 ( V_5 , V_6 ) ;
return 0 ;
}
static int F_218 ( struct V_106 * V_105 ,
enum V_330 V_331 )
{
struct V_4 * V_5 = F_219 ( V_105 ) ;
return V_5 -> V_10 -> V_332 ( V_5 , V_331 ) ;
}
int F_220 ( struct V_22 * V_23 ,
const struct V_333 * V_334 ,
struct V_92 * V_298 ,
int V_301 )
{
struct V_106 * V_105 ;
struct V_4 * V_5 ;
struct V_59 * V_60 ;
int V_14 , V_3 ;
F_49 ( V_23 , L_94 , V_164 ( V_23 ) ) ;
V_5 = F_51 ( sizeof( struct V_4 ) , V_40 ) ;
if ( V_5 == NULL )
return - V_41 ;
V_5 -> V_49 . V_5 = V_5 ;
V_14 = F_189 ( & V_5 -> V_49 ,
& V_334 -> V_325 , V_23 ) ;
if ( V_14 )
goto V_318;
if ( V_334 -> V_170 )
V_5 -> V_49 . V_170 = F_212 ;
if ( V_334 -> remove )
V_5 -> V_49 . remove = F_213 ;
if ( V_334 -> V_99 )
V_5 -> V_49 . V_99 = F_214 ;
if ( V_334 -> V_116 )
V_5 -> V_49 . V_116 = F_215 ;
if ( V_334 -> V_313 )
V_5 -> V_49 . V_313 = F_216 ;
if ( V_334 -> V_314 )
V_5 -> V_49 . V_314 = F_217 ;
V_5 -> V_49 . V_319 = V_334 -> V_319 ;
V_105 = F_221 ( V_5 ) ;
V_105 -> V_109 = V_334 -> V_109 ;
V_105 -> V_335 = V_334 -> V_335 ;
if ( V_334 -> V_307 )
V_105 -> V_307 = V_334 -> V_307 ;
if ( V_334 -> V_332 )
V_105 -> V_332 = F_218 ;
V_5 -> V_23 = V_23 ;
V_5 -> V_10 = V_334 ;
V_5 -> V_49 . V_312 = V_334 -> V_13 ;
#ifdef F_123
V_5 -> V_49 . V_55 = F_31 ;
V_5 -> V_49 . V_52 = L_95 ;
#endif
if ( V_334 -> V_336 )
V_5 -> V_49 . V_111 = V_334 -> V_336 ( V_23 ) ;
for ( V_3 = 0 ; V_3 < V_301 ; V_3 ++ ) {
F_211 ( & V_298 [ V_3 ] . V_337 ) ;
F_211 ( & V_298 [ V_3 ] . V_338 ) ;
}
V_14 = F_185 ( & V_5 -> V_49 , V_298 , V_301 , false ) ;
if ( V_14 < 0 ) {
F_78 ( V_23 , L_89 , V_14 ) ;
goto V_321;
}
F_36 (dai, &codec->component.dai_list, list)
V_60 -> V_5 = V_5 ;
F_35 ( & V_58 ) ;
F_195 ( & V_5 -> V_49 ) ;
F_106 ( & V_5 -> V_80 , & V_339 ) ;
F_37 ( & V_58 ) ;
F_49 ( V_5 -> V_23 , L_96 ,
V_5 -> V_49 . V_53 ) ;
return 0 ;
V_321:
F_198 ( & V_5 -> V_49 ) ;
V_318:
F_16 ( V_5 ) ;
return V_14 ;
}
void F_222 ( struct V_22 * V_23 )
{
struct V_4 * V_5 ;
F_35 ( & V_58 ) ;
F_36 (codec, &codec_list, list) {
if ( V_23 == V_5 -> V_23 )
goto V_293;
}
F_37 ( & V_58 ) ;
return;
V_293:
F_57 ( & V_5 -> V_80 ) ;
F_199 ( & V_5 -> V_49 ) ;
F_37 ( & V_58 ) ;
F_49 ( V_5 -> V_23 , L_97 ,
V_5 -> V_49 . V_53 ) ;
F_198 ( & V_5 -> V_49 ) ;
F_223 ( V_5 ) ;
F_16 ( V_5 ) ;
}
int F_224 ( struct V_63 * V_50 ,
const char * V_340 )
{
struct V_122 * V_341 ;
int V_14 ;
if ( ! V_50 -> V_23 ) {
F_225 ( L_98 , V_342 ) ;
return - V_15 ;
}
V_341 = V_50 -> V_23 -> V_123 ;
V_14 = F_226 ( V_341 , V_340 , 0 , & V_50 -> V_53 ) ;
if ( V_14 < 0 && V_14 != - V_15 ) {
F_78 ( V_50 -> V_23 ,
L_99 ,
V_340 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
int F_227 ( struct V_63 * V_50 ,
const char * V_340 )
{
struct V_122 * V_341 = V_50 -> V_23 -> V_123 ;
struct V_190 * V_343 ;
const char * V_254 , * V_344 ;
int V_3 , V_119 , V_345 , V_14 ;
V_345 = F_228 ( V_341 , V_340 ) ;
if ( V_345 < 0 ) {
F_78 ( V_50 -> V_23 ,
L_100 , V_340 ) ;
return - V_15 ;
}
if ( V_345 & 1 ) {
F_78 ( V_50 -> V_23 ,
L_101 , V_340 ) ;
return - V_15 ;
}
V_345 /= 2 ;
if ( ! V_345 ) {
F_78 ( V_50 -> V_23 , L_102 ,
V_340 ) ;
return - V_15 ;
}
V_343 = F_229 ( V_50 -> V_23 , V_345 , sizeof( * V_343 ) ,
V_40 ) ;
if ( ! V_343 ) {
F_78 ( V_50 -> V_23 ,
L_103 ) ;
return - V_41 ;
}
for ( V_3 = 0 ; V_3 < V_345 ; V_3 ++ ) {
V_14 = F_226 ( V_341 , V_340 ,
2 * V_3 , & V_254 ) ;
if ( V_14 ) {
F_78 ( V_50 -> V_23 ,
L_104 ,
V_340 , 2 * V_3 , V_14 ) ;
return - V_15 ;
}
for ( V_119 = 0 ; V_119 < F_146 ( V_346 ) ; V_119 ++ ) {
if ( ! strncmp ( V_254 , V_346 [ V_119 ] . V_53 ,
strlen ( V_346 [ V_119 ] . V_53 ) ) ) {
V_343 [ V_3 ] = V_346 [ V_119 ] ;
break;
}
}
if ( V_119 >= F_146 ( V_346 ) ) {
F_78 ( V_50 -> V_23 ,
L_105 ,
V_254 ) ;
return - V_15 ;
}
V_14 = F_226 ( V_341 , V_340 ,
( 2 * V_3 ) + 1 ,
& V_344 ) ;
if ( V_14 ) {
F_78 ( V_50 -> V_23 ,
L_104 ,
V_340 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_15 ;
}
V_343 [ V_3 ] . V_53 = V_344 ;
}
V_50 -> V_237 = V_343 ;
V_50 -> V_238 = V_345 ;
return 0 ;
}
static int F_230 ( struct V_122 * V_341 ,
const char * V_347 ,
unsigned int * V_348 )
{
T_6 V_1 ;
const T_7 * V_349 = F_231 ( V_341 , V_347 , & V_1 ) ;
int V_3 ;
if ( ! V_349 )
return 0 ;
V_1 /= sizeof( T_6 ) ;
for ( V_3 = 0 ; V_3 < V_1 ; V_3 ++ )
if ( F_232 ( & V_349 [ V_3 ] ) )
* V_348 |= ( 1 << V_3 ) ;
return V_1 ;
}
int F_233 ( struct V_122 * V_341 ,
unsigned int * V_275 ,
unsigned int * V_276 ,
unsigned int * V_274 ,
unsigned int * V_277 )
{
T_6 V_1 ;
int V_14 ;
if ( V_275 )
F_230 ( V_341 , L_106 , V_275 ) ;
if ( V_276 )
F_230 ( V_341 , L_107 , V_276 ) ;
if ( F_234 ( V_341 , L_108 ) ) {
V_14 = F_235 ( V_341 , L_108 , & V_1 ) ;
if ( V_14 )
return V_14 ;
if ( V_274 )
* V_274 = V_1 ;
}
if ( F_234 ( V_341 , L_109 ) ) {
V_14 = F_235 ( V_341 , L_109 , & V_1 ) ;
if ( V_14 )
return V_14 ;
if ( V_277 )
* V_277 = V_1 ;
}
return 0 ;
}
void F_236 ( struct V_63 * V_50 ,
struct V_162 * V_160 ,
struct V_122 * V_123 ,
const char * V_340 )
{
struct V_122 * V_341 = V_50 -> V_23 -> V_123 ;
const char * V_350 ;
int V_14 ;
V_14 = F_237 ( V_341 , V_340 , & V_350 ) ;
if ( V_14 < 0 ) {
return;
}
V_160 -> V_123 = V_123 ;
V_160 -> V_165 = V_350 ;
}
int F_238 ( struct V_63 * V_50 ,
const char * V_340 )
{
struct V_122 * V_341 = V_50 -> V_23 -> V_123 ;
int V_351 ;
struct V_352 * V_353 ;
int V_3 , V_14 ;
V_351 = F_228 ( V_341 , V_340 ) ;
if ( V_351 < 0 || V_351 & 1 ) {
F_78 ( V_50 -> V_23 ,
L_110 ,
V_340 ) ;
return - V_15 ;
}
V_351 /= 2 ;
if ( ! V_351 ) {
F_78 ( V_50 -> V_23 , L_102 ,
V_340 ) ;
return - V_15 ;
}
V_353 = F_94 ( V_50 -> V_23 , V_351 * sizeof( * V_353 ) ,
V_40 ) ;
if ( ! V_353 ) {
F_78 ( V_50 -> V_23 ,
L_111 ) ;
return - V_15 ;
}
for ( V_3 = 0 ; V_3 < V_351 ; V_3 ++ ) {
V_14 = F_226 ( V_341 , V_340 ,
2 * V_3 , & V_353 [ V_3 ] . V_191 ) ;
if ( V_14 ) {
F_78 ( V_50 -> V_23 ,
L_112 ,
V_340 , 2 * V_3 , V_14 ) ;
return - V_15 ;
}
V_14 = F_226 ( V_341 , V_340 ,
( 2 * V_3 ) + 1 , & V_353 [ V_3 ] . V_192 ) ;
if ( V_14 ) {
F_78 ( V_50 -> V_23 ,
L_112 ,
V_340 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_15 ;
}
}
V_50 -> V_242 = V_351 ;
V_50 -> V_241 = V_353 ;
return 0 ;
}
unsigned int F_239 ( struct V_122 * V_341 ,
const char * V_253 ,
struct V_122 * * V_354 ,
struct V_122 * * V_355 )
{
int V_14 , V_3 ;
char V_356 [ 128 ] ;
unsigned int V_357 = 0 ;
int V_358 , V_359 ;
const char * V_350 ;
struct {
char * V_53 ;
unsigned int V_1 ;
} V_360 [] = {
{ L_113 , V_361 } ,
{ L_114 , V_362 } ,
{ L_115 , V_363 } ,
{ L_116 , V_364 } ,
{ L_117 , V_365 } ,
{ L_118 , V_366 } ,
{ L_119 , V_367 } ,
{ L_120 , V_368 } ,
{ L_121 , V_369 } ,
} ;
if ( ! V_253 )
V_253 = L_122 ;
V_14 = F_237 ( V_341 , L_123 , & V_350 ) ;
if ( V_14 < 0 ) {
snprintf ( V_356 , sizeof( V_356 ) , L_124 , V_253 ) ;
V_14 = F_237 ( V_341 , V_356 , & V_350 ) ;
}
if ( V_14 == 0 ) {
for ( V_3 = 0 ; V_3 < F_146 ( V_360 ) ; V_3 ++ ) {
if ( strcmp ( V_350 , V_360 [ V_3 ] . V_53 ) == 0 ) {
V_357 |= V_360 [ V_3 ] . V_1 ;
break;
}
}
}
snprintf ( V_356 , sizeof( V_356 ) , L_125 , V_253 ) ;
if ( F_234 ( V_341 , V_356 ) )
V_357 |= V_370 ;
else
V_357 |= V_371 ;
snprintf ( V_356 , sizeof( V_356 ) , L_126 , V_253 ) ;
V_358 = ! ! F_231 ( V_341 , V_356 , NULL ) ;
snprintf ( V_356 , sizeof( V_356 ) , L_127 , V_253 ) ;
V_359 = ! ! F_231 ( V_341 , V_356 , NULL ) ;
switch ( ( V_358 << 4 ) + V_359 ) {
case 0x11 :
V_357 |= V_372 ;
break;
case 0x10 :
V_357 |= V_373 ;
break;
case 0x01 :
V_357 |= V_374 ;
break;
default:
break;
}
snprintf ( V_356 , sizeof( V_356 ) , L_128 , V_253 ) ;
V_358 = ! ! F_231 ( V_341 , V_356 , NULL ) ;
if ( V_358 && V_354 )
* V_354 = F_240 ( V_341 , V_356 , 0 ) ;
snprintf ( V_356 , sizeof( V_356 ) , L_129 , V_253 ) ;
V_359 = ! ! F_231 ( V_341 , V_356 , NULL ) ;
if ( V_359 && V_355 )
* V_355 = F_240 ( V_341 , V_356 , 0 ) ;
switch ( ( V_358 << 4 ) + V_359 ) {
case 0x11 :
V_357 |= V_211 ;
break;
case 0x10 :
V_357 |= V_213 ;
break;
case 0x01 :
V_357 |= V_214 ;
break;
default:
V_357 |= V_212 ;
break;
}
return V_357 ;
}
int F_241 ( struct V_122 * V_375 )
{
struct V_48 * V_17 ;
struct V_122 * V_376 ;
int V_14 ;
V_376 = F_242 ( V_375 ) ;
V_14 = - V_208 ;
F_35 ( & V_58 ) ;
F_36 (pos, &component_list, list) {
struct V_122 * V_126 = V_17 -> V_23 -> V_123 ;
if ( ! V_126 && V_17 -> V_23 -> V_127 )
V_126 = V_17 -> V_23 -> V_127 -> V_123 ;
if ( V_126 != V_376 )
continue;
if ( V_17 -> V_10 -> V_377 )
V_14 = V_17 -> V_10 -> V_377 ( V_17 , V_375 ) ;
break;
}
F_37 ( & V_58 ) ;
F_243 ( V_376 ) ;
return V_14 ;
}
int F_244 ( struct V_378 * args ,
const char * * V_128 )
{
struct V_48 * V_17 ;
struct V_122 * V_126 ;
int V_14 = - V_141 ;
F_35 ( & V_58 ) ;
F_36 (pos, &component_list, list) {
V_126 = V_17 -> V_23 -> V_123 ;
if ( ! V_126 && V_17 -> V_23 -> V_127 )
V_126 = V_17 -> V_23 -> V_127 -> V_123 ;
if ( V_126 != args -> V_341 )
continue;
if ( V_17 -> V_10 -> V_379 ) {
V_14 = V_17 -> V_10 -> V_379 ( V_17 ,
args ,
V_128 ) ;
} else {
int V_129 = - 1 ;
switch ( args -> V_380 ) {
case 0 :
V_129 = 0 ;
break;
case 1 :
V_129 = args -> args [ 0 ] ;
break;
default:
break;
}
if ( V_129 < 0 || V_129 >= V_17 -> V_301 ) {
V_14 = - V_15 ;
continue;
}
V_14 = 0 ;
* V_128 = V_17 -> V_298 [ V_129 ] . V_53 ;
if ( ! * V_128 )
* V_128 = V_17 -> V_53 ;
}
break;
}
F_37 ( & V_58 ) ;
return V_14 ;
}
int F_245 ( struct V_122 * V_123 ,
const char * * V_128 )
{
struct V_378 args ;
int V_14 ;
V_14 = F_246 ( V_123 , L_130 ,
L_131 , 0 , & args ) ;
if ( V_14 )
return V_14 ;
V_14 = F_244 ( & args , V_128 ) ;
F_243 ( args . V_341 ) ;
return V_14 ;
}
int F_247 ( struct V_22 * V_23 ,
struct V_122 * V_123 ,
struct V_77 * V_71 )
{
struct V_378 args ;
struct V_124 * V_49 ;
char * V_53 ;
int V_256 , V_79 , V_14 ;
V_53 = L_130 ;
V_79 = F_248 ( V_123 , V_53 ,
L_131 ) ;
if ( V_79 <= 0 ) {
if ( V_79 == - V_381 )
F_78 ( V_23 , L_132 ) ;
else
F_78 ( V_23 , L_133 ) ;
return V_79 ;
}
V_49 = F_94 ( V_23 ,
sizeof *V_49 * V_79 ,
V_40 ) ;
if ( ! V_49 )
return - V_41 ;
V_71 -> V_133 = V_49 ;
V_71 -> V_79 = V_79 ;
for ( V_256 = 0 , V_49 = V_71 -> V_133 ;
V_256 < V_71 -> V_79 ;
V_256 ++ , V_49 ++ ) {
V_14 = F_246 ( V_123 , V_53 ,
L_131 ,
V_256 , & args ) ;
if ( V_14 )
goto V_145;
V_49 -> V_123 = args . V_341 ;
V_14 = F_244 ( & args , & V_49 -> V_128 ) ;
if ( V_14 < 0 )
goto V_145;
}
return 0 ;
V_145:
for ( V_256 = 0 , V_49 = V_71 -> V_133 ;
V_256 < V_71 -> V_79 ;
V_256 ++ , V_49 ++ ) {
if ( ! V_49 -> V_123 )
break;
F_243 ( V_49 -> V_123 ) ;
V_49 -> V_123 = NULL ;
}
V_71 -> V_133 = NULL ;
V_71 -> V_79 = 0 ;
return V_14 ;
}
static int T_8 F_249 ( void )
{
F_44 () ;
F_250 () ;
return F_251 ( & V_382 ) ;
}
static void T_9 F_252 ( void )
{
F_253 () ;
F_47 () ;
F_254 ( & V_382 ) ;
}
