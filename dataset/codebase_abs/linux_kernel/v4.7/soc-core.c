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
struct V_4 * V_5 ;
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
F_36 (codec, &card->codec_dev_list, card_list) {
struct V_106 * V_105 = F_70 ( V_5 ) ;
if ( ! V_5 -> V_107 ) {
switch ( F_71 ( V_105 ) ) {
case V_108 :
if ( V_105 -> V_109 ) {
F_49 ( V_5 -> V_23 ,
L_22 ) ;
break;
}
case V_110 :
if ( V_5 -> V_10 -> V_99 )
V_5 -> V_10 -> V_99 ( V_5 ) ;
V_5 -> V_107 = 1 ;
if ( V_5 -> V_49 . V_111 )
F_72 ( V_5 -> V_49 . V_111 ) ;
F_73 ( V_5 -> V_23 ) ;
break;
default:
F_49 ( V_5 -> V_23 ,
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
F_73 ( V_98 -> V_23 ) ;
}
if ( V_50 -> V_112 )
V_50 -> V_112 ( V_50 ) ;
return 0 ;
}
static void F_74 ( struct V_85 * V_86 )
{
struct V_63 * V_50 =
F_75 ( V_86 , struct V_63 , V_113 ) ;
struct V_26 * V_27 ;
struct V_4 * V_5 ;
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
F_36 (codec, &card->codec_dev_list, card_list) {
if ( V_5 -> V_107 ) {
if ( V_5 -> V_10 -> V_116 )
V_5 -> V_10 -> V_116 ( V_5 ) ;
V_5 -> V_107 = 0 ;
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
int F_76 ( struct V_22 * V_23 )
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
F_77 ( V_98 -> V_23 ) ;
for ( V_119 = 0 ; V_119 < V_27 -> V_79 ; V_119 ++ ) {
struct V_59 * V_121 = V_78 [ V_119 ] ;
if ( V_121 -> V_120 )
F_77 ( V_121 -> V_23 ) ;
}
}
F_36 (rtd, &card->rtd_list, list) {
struct V_59 * V_98 = V_27 -> V_98 ;
V_100 |= V_98 -> V_10 -> V_100 ;
}
if ( V_100 ) {
F_49 ( V_23 , L_26 ) ;
F_74 ( & V_50 -> V_113 ) ;
} else {
F_49 ( V_23 , L_27 ) ;
if ( ! F_78 ( & V_50 -> V_113 ) )
F_79 ( V_23 , L_28 ) ;
}
return 0 ;
}
static struct V_48 * F_80 (
const struct V_122 * V_123 , const char * V_53 )
{
struct V_48 * V_49 ;
F_81 ( & V_58 ) ;
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
struct V_59 * F_82 (
const struct V_124 * V_125 )
{
struct V_48 * V_49 ;
struct V_59 * V_60 ;
struct V_122 * V_126 ;
F_81 ( & V_58 ) ;
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
struct V_124 * V_129 = V_71 -> V_129 ;
struct V_124 V_130 ;
struct V_59 * * V_78 ;
struct V_61 * V_62 ;
const char * V_131 ;
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
V_130 . V_53 = V_71 -> V_132 ;
V_130 . V_123 = V_71 -> V_133 ;
V_130 . V_128 = V_71 -> V_134 ;
V_27 -> V_98 = F_82 ( & V_130 ) ;
if ( ! V_27 -> V_98 ) {
F_79 ( V_50 -> V_23 , L_31 ,
V_71 -> V_134 ) ;
goto V_135;
}
V_27 -> V_79 = V_71 -> V_79 ;
V_78 = V_27 -> V_78 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_79 ; V_3 ++ ) {
V_78 [ V_3 ] = F_82 ( & V_129 [ V_3 ] ) ;
if ( ! V_78 [ V_3 ] ) {
F_79 ( V_50 -> V_23 , L_32 ,
V_129 [ V_3 ] . V_128 ) ;
goto V_135;
}
}
V_27 -> V_121 = V_78 [ 0 ] ;
V_27 -> V_5 = V_27 -> V_121 -> V_5 ;
V_131 = V_71 -> V_131 ;
if ( ! V_131 && ! V_71 -> V_136 )
V_131 = L_33 ;
F_36 (platform, &platform_list, list) {
if ( V_71 -> V_136 ) {
if ( V_62 -> V_23 -> V_123 !=
V_71 -> V_136 )
continue;
} else {
if ( strcmp ( V_62 -> V_49 . V_53 , V_131 ) )
continue;
}
V_27 -> V_62 = V_62 ;
}
if ( ! V_27 -> V_62 ) {
F_79 ( V_50 -> V_23 , L_34 ,
V_71 -> V_131 ) ;
return - V_137 ;
}
F_53 ( V_50 , V_27 ) ;
return 0 ;
V_135:
F_52 ( V_27 ) ;
return - V_137 ;
}
static void F_85 ( struct V_48 * V_49 )
{
if ( ! V_49 -> V_50 )
return;
if ( V_49 -> V_5 )
F_57 ( & V_49 -> V_5 -> V_138 ) ;
if ( V_49 -> remove )
V_49 -> remove ( V_49 ) ;
F_86 ( F_28 ( V_49 ) ) ;
F_29 ( V_49 ) ;
V_49 -> V_50 = NULL ;
F_87 ( V_49 -> V_23 -> V_10 -> V_139 ) ;
}
static void F_88 ( struct V_59 * V_60 , int V_140 )
{
int V_141 ;
if ( V_60 && V_60 -> V_142 &&
V_60 -> V_10 -> V_143 == V_140 ) {
if ( V_60 -> V_10 -> remove ) {
V_141 = V_60 -> V_10 -> remove ( V_60 ) ;
if ( V_141 < 0 )
F_79 ( V_60 -> V_23 ,
L_35 ,
V_60 -> V_53 , V_141 ) ;
}
V_60 -> V_142 = 0 ;
}
}
static void F_89 ( struct V_63 * V_50 ,
struct V_26 * V_27 , int V_140 )
{
int V_3 ;
if ( V_27 -> V_144 ) {
F_90 ( V_27 -> V_23 ) ;
V_27 -> V_144 = 0 ;
}
for ( V_3 = 0 ; V_3 < V_27 -> V_79 ; V_3 ++ )
F_88 ( V_27 -> V_78 [ V_3 ] , V_140 ) ;
F_88 ( V_27 -> V_98 , V_140 ) ;
}
static void F_91 ( struct V_63 * V_50 ,
struct V_26 * V_27 , int V_140 )
{
struct V_59 * V_98 = V_27 -> V_98 ;
struct V_61 * V_62 = V_27 -> V_62 ;
struct V_48 * V_49 ;
int V_3 ;
if ( V_62 && V_62 -> V_49 . V_10 -> V_143 == V_140 )
F_85 ( & V_62 -> V_49 ) ;
for ( V_3 = 0 ; V_3 < V_27 -> V_79 ; V_3 ++ ) {
V_49 = V_27 -> V_78 [ V_3 ] -> V_49 ;
if ( V_49 -> V_10 -> V_143 == V_140 )
F_85 ( V_49 ) ;
}
if ( V_98 ) {
if ( V_98 -> V_49 -> V_10 -> V_143 == V_140 )
F_85 ( V_98 -> V_49 ) ;
}
}
static void F_92 ( struct V_63 * V_50 )
{
int V_140 ;
struct V_26 * V_27 ;
struct V_77 * V_145 , * V_146 ;
for ( V_140 = V_147 ; V_140 <= V_148 ;
V_140 ++ ) {
F_36 (rtd, &card->rtd_list, list)
F_89 ( V_50 , V_27 , V_140 ) ;
}
for ( V_140 = V_147 ; V_140 <= V_148 ;
V_140 ++ ) {
F_36 (rtd, &card->rtd_list, list)
F_91 ( V_50 , V_27 , V_140 ) ;
}
F_56 (link, _link, &card->dai_link_list, list) {
if ( V_145 -> V_149 . type == V_150 )
F_26 ( V_50 -> V_23 , L_36 ,
V_145 -> V_53 ) ;
F_57 ( & V_145 -> V_80 ) ;
V_50 -> V_151 -- ;
}
}
static int F_93 ( struct V_63 * V_50 ,
struct V_77 * V_71 )
{
if ( V_71 -> V_152 || V_71 -> V_153 ||
V_71 -> V_154 ) {
V_71 -> V_79 = 1 ;
V_71 -> V_129 = F_94 ( V_50 -> V_23 ,
sizeof( struct V_124 ) ,
V_40 ) ;
if ( ! V_71 -> V_129 )
return - V_41 ;
V_71 -> V_129 [ 0 ] . V_53 = V_71 -> V_152 ;
V_71 -> V_129 [ 0 ] . V_123 = V_71 -> V_153 ;
V_71 -> V_129 [ 0 ] . V_128 = V_71 -> V_154 ;
}
if ( ! V_71 -> V_129 ) {
F_79 ( V_50 -> V_23 , L_37 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_95 ( struct V_63 * V_50 ,
struct V_77 * V_145 )
{
int V_3 , V_14 ;
V_14 = F_93 ( V_50 , V_145 ) ;
if ( V_14 ) {
F_79 ( V_50 -> V_23 , L_38 ) ;
return V_14 ;
}
for ( V_3 = 0 ; V_3 < V_145 -> V_79 ; V_3 ++ ) {
if ( ! ! V_145 -> V_129 [ V_3 ] . V_53 ==
! ! V_145 -> V_129 [ V_3 ] . V_123 ) {
F_79 ( V_50 -> V_23 , L_39 ,
V_145 -> V_53 ) ;
return - V_15 ;
}
if ( ! V_145 -> V_129 [ V_3 ] . V_128 ) {
F_79 ( V_50 -> V_23 , L_40 ,
V_145 -> V_53 ) ;
return - V_15 ;
}
}
if ( V_145 -> V_131 && V_145 -> V_136 ) {
F_79 ( V_50 -> V_23 ,
L_41 ,
V_145 -> V_53 ) ;
return - V_15 ;
}
if ( V_145 -> V_132 && V_145 -> V_133 ) {
F_79 ( V_50 -> V_23 ,
L_42 ,
V_145 -> V_53 ) ;
return - V_15 ;
}
if ( ! V_145 -> V_134 &&
! ( V_145 -> V_132 || V_145 -> V_133 ) ) {
F_79 ( V_50 -> V_23 ,
L_43 ,
V_145 -> V_53 ) ;
return - V_15 ;
}
return 0 ;
}
int F_96 ( struct V_63 * V_50 ,
struct V_77 * V_71 )
{
if ( V_71 -> V_149 . type
&& V_71 -> V_149 . type != V_150 ) {
F_79 ( V_50 -> V_23 , L_44 ,
V_71 -> V_149 . type ) ;
return - V_15 ;
}
F_81 ( & V_58 ) ;
if ( V_71 -> V_149 . type && V_50 -> V_155 )
V_50 -> V_155 ( V_50 , V_71 ) ;
F_54 ( & V_71 -> V_80 , & V_50 -> V_156 ) ;
V_50 -> V_151 ++ ;
return 0 ;
}
void F_97 ( struct V_63 * V_50 ,
struct V_77 * V_71 )
{
struct V_77 * V_145 , * V_146 ;
if ( V_71 -> V_149 . type
&& V_71 -> V_149 . type != V_150 ) {
F_79 ( V_50 -> V_23 , L_44 ,
V_71 -> V_149 . type ) ;
return;
}
F_81 ( & V_58 ) ;
if ( V_71 -> V_149 . type && V_50 -> V_157 )
V_50 -> V_157 ( V_50 , V_71 ) ;
F_56 (link, _link, &card->dai_link_list, list) {
if ( V_145 == V_71 ) {
F_57 ( & V_145 -> V_80 ) ;
V_50 -> V_151 -- ;
return;
}
}
}
static void F_98 ( struct V_63 * V_50 ,
struct V_48 * V_49 )
{
int V_3 ;
if ( V_50 -> V_158 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_50 -> V_159 ; V_3 ++ ) {
struct V_160 * V_161 = & V_50 -> V_158 [ V_3 ] ;
if ( V_161 -> V_123 && V_49 -> V_23 -> V_123 != V_161 -> V_123 )
continue;
if ( V_161 -> V_162 && strcmp ( V_49 -> V_53 , V_161 -> V_162 ) )
continue;
V_49 -> V_163 = V_161 -> V_163 ;
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
F_79 ( V_49 -> V_23 ,
L_45 ,
V_50 -> V_53 , V_49 -> V_50 -> V_53 ) ;
return - V_164 ;
}
return 0 ;
}
if ( ! F_100 ( V_49 -> V_23 -> V_10 -> V_139 ) )
return - V_164 ;
V_49 -> V_50 = V_50 ;
V_105 -> V_50 = V_50 ;
F_98 ( V_50 , V_49 ) ;
F_23 ( V_49 ) ;
if ( V_49 -> V_165 ) {
V_14 = F_101 ( V_105 , V_49 -> V_165 ,
V_49 -> V_166 ) ;
if ( V_14 != 0 ) {
F_79 ( V_49 -> V_23 ,
L_46 , V_14 ) ;
goto V_167;
}
}
F_36 (dai, &component->dai_list, list) {
V_14 = F_102 ( V_105 , V_60 ) ;
if ( V_14 != 0 ) {
F_79 ( V_49 -> V_23 ,
L_47 , V_14 ) ;
goto V_167;
}
}
if ( V_49 -> V_168 ) {
V_14 = V_49 -> V_168 ( V_49 ) ;
if ( V_14 < 0 ) {
F_79 ( V_49 -> V_23 ,
L_48 , V_14 ) ;
goto V_167;
}
F_103 ( V_105 -> V_109 &&
V_105 -> V_169 != V_110 ,
L_49 ,
V_49 -> V_53 ) ;
}
if ( V_49 -> V_170 ) {
V_14 = V_49 -> V_170 ( V_49 ) ;
if ( V_14 < 0 ) {
F_79 ( V_49 -> V_23 ,
L_50 , V_14 ) ;
goto V_167;
}
}
if ( V_49 -> V_171 )
F_104 ( V_49 , V_49 -> V_171 ,
V_49 -> V_172 ) ;
if ( V_49 -> V_173 )
F_105 ( V_105 , V_49 -> V_173 ,
V_49 -> V_174 ) ;
F_106 ( & V_105 -> V_80 , & V_50 -> V_175 ) ;
if ( V_49 -> V_5 )
F_106 ( & V_49 -> V_5 -> V_138 , & V_50 -> V_176 ) ;
return 0 ;
V_167:
F_29 ( V_49 ) ;
V_49 -> V_50 = NULL ;
F_87 ( V_49 -> V_23 -> V_10 -> V_139 ) ;
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
V_27 -> V_23 -> V_177 = F_107 ;
V_27 -> V_23 -> V_178 = V_179 ;
F_110 ( V_27 -> V_23 , L_51 , V_53 ) ;
F_111 ( V_27 -> V_23 , V_27 ) ;
F_112 ( & V_27 -> V_180 ) ;
F_113 ( & V_27 -> V_181 [ V_102 ] . V_182 ) ;
F_113 ( & V_27 -> V_181 [ V_104 ] . V_182 ) ;
F_113 ( & V_27 -> V_181 [ V_102 ] . V_183 ) ;
F_113 ( & V_27 -> V_181 [ V_104 ] . V_183 ) ;
V_14 = F_114 ( V_27 -> V_23 ) ;
if ( V_14 < 0 ) {
F_115 ( V_27 -> V_23 ) ;
F_79 ( V_27 -> V_50 -> V_23 ,
L_52 , V_14 ) ;
return V_14 ;
}
V_27 -> V_144 = 1 ;
return 0 ;
}
static int F_116 ( struct V_63 * V_50 ,
struct V_26 * V_27 ,
int V_140 )
{
struct V_61 * V_62 = V_27 -> V_62 ;
struct V_48 * V_49 ;
int V_3 , V_14 ;
V_49 = V_27 -> V_98 -> V_49 ;
if ( V_49 -> V_10 -> V_184 == V_140 ) {
V_14 = F_99 ( V_50 , V_49 ) ;
if ( V_14 < 0 )
return V_14 ;
}
for ( V_3 = 0 ; V_3 < V_27 -> V_79 ; V_3 ++ ) {
V_49 = V_27 -> V_78 [ V_3 ] -> V_49 ;
if ( V_49 -> V_10 -> V_184 == V_140 ) {
V_14 = F_99 ( V_50 , V_49 ) ;
if ( V_14 < 0 )
return V_14 ;
}
}
if ( V_62 -> V_49 . V_10 -> V_184 == V_140 ) {
V_14 = F_99 ( V_50 , & V_62 -> V_49 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
static int F_117 ( struct V_59 * V_60 , int V_140 )
{
int V_14 ;
if ( ! V_60 -> V_142 && V_60 -> V_10 -> V_184 == V_140 ) {
if ( V_60 -> V_10 -> V_168 ) {
V_14 = V_60 -> V_10 -> V_168 ( V_60 ) ;
if ( V_14 < 0 ) {
F_79 ( V_60 -> V_23 ,
L_53 ,
V_60 -> V_53 , V_14 ) ;
return V_14 ;
}
}
V_60 -> V_142 = 1 ;
}
return 0 ;
}
static int F_118 ( struct V_63 * V_50 ,
struct V_77 * V_71 ,
struct V_26 * V_27 )
{
struct V_59 * V_98 = V_27 -> V_98 ;
struct V_59 * V_121 = V_27 -> V_121 ;
struct V_185 * V_186 , * V_187 ;
int V_14 ;
if ( V_27 -> V_79 > 1 )
F_26 ( V_50 -> V_23 , L_54 ) ;
V_186 = V_121 -> V_188 ;
V_187 = V_98 -> V_189 ;
if ( V_186 && V_187 ) {
V_14 = F_119 ( V_50 , V_71 -> V_190 ,
V_71 -> V_191 ,
V_187 , V_186 ) ;
if ( V_14 != 0 ) {
F_79 ( V_50 -> V_23 , L_55 ,
V_186 -> V_53 , V_187 -> V_53 , V_14 ) ;
return V_14 ;
}
}
V_186 = V_98 -> V_188 ;
V_187 = V_121 -> V_189 ;
if ( V_186 && V_187 ) {
V_14 = F_119 ( V_50 , V_71 -> V_190 ,
V_71 -> V_191 ,
V_187 , V_186 ) ;
if ( V_14 != 0 ) {
F_79 ( V_50 -> V_23 , L_55 ,
V_186 -> V_53 , V_187 -> V_53 , V_14 ) ;
return V_14 ;
}
}
return 0 ;
}
static int F_120 ( struct V_63 * V_50 ,
struct V_26 * V_27 , int V_140 )
{
struct V_77 * V_71 = V_27 -> V_71 ;
struct V_59 * V_98 = V_27 -> V_98 ;
int V_3 , V_14 ;
F_49 ( V_50 -> V_23 , L_56 ,
V_50 -> V_53 , V_27 -> V_82 , V_140 ) ;
V_27 -> V_29 = V_29 ;
V_14 = F_117 ( V_98 , V_140 ) ;
if ( V_14 )
return V_14 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_79 ; V_3 ++ ) {
V_14 = F_117 ( V_27 -> V_78 [ V_3 ] , V_140 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_140 != V_148 )
return 0 ;
if ( V_71 -> V_170 ) {
V_14 = V_71 -> V_170 ( V_27 ) ;
if ( V_14 < 0 ) {
F_79 ( V_50 -> V_23 , L_57 ,
V_71 -> V_53 , V_14 ) ;
return V_14 ;
}
}
if ( V_71 -> V_192 )
F_121 ( V_27 , V_71 -> V_192 ) ;
V_14 = F_108 ( V_27 , V_71 -> V_53 ) ;
if ( V_14 )
return V_14 ;
#ifdef F_122
if ( V_71 -> V_193 )
F_123 ( V_27 ) ;
#endif
if ( V_98 -> V_10 -> V_194 ) {
V_14 = V_98 -> V_10 -> V_194 ( V_27 , V_27 -> V_82 ) ;
if ( V_14 < 0 ) {
F_79 ( V_50 -> V_23 , L_58 ,
V_71 -> V_195 ) ;
return V_14 ;
}
} else {
if ( ! V_71 -> V_190 ) {
V_14 = F_124 ( V_27 , V_27 -> V_82 ) ;
if ( V_14 < 0 ) {
F_79 ( V_50 -> V_23 , L_59 ,
V_71 -> V_195 , V_14 ) ;
return V_14 ;
}
} else {
F_125 ( & V_27 -> V_101 ,
F_59 ) ;
V_14 = F_118 ( V_50 , V_71 , V_27 ) ;
if ( V_14 )
return V_14 ;
}
}
return 0 ;
}
static int F_126 ( struct V_63 * V_50 , int V_82 )
{
struct V_196 * V_197 = & V_50 -> V_197 [ V_82 ] ;
struct V_48 * V_49 ;
const char * V_53 ;
struct V_122 * V_153 ;
if ( V_197 -> V_153 || V_197 -> V_152 ) {
V_53 = V_197 -> V_152 ;
V_153 = V_197 -> V_153 ;
V_49 = F_80 ( V_153 , V_53 ) ;
if ( ! V_49 ) {
if ( V_153 )
V_53 = F_127 ( V_153 ) ;
goto V_198;
}
} else if ( V_197 -> V_53 ) {
V_53 = V_197 -> V_53 ;
V_49 = F_80 ( NULL , V_53 ) ;
if ( ! V_49 )
goto V_198;
} else {
F_79 ( V_50 -> V_23 , L_60 ) ;
return - V_15 ;
}
V_49 -> V_170 = V_197 -> V_170 ;
F_106 ( & V_49 -> V_199 , & V_50 -> V_200 ) ;
return 0 ;
V_198:
F_79 ( V_50 -> V_23 , L_61 , V_53 ) ;
return - V_137 ;
}
static int F_128 ( struct V_63 * V_50 )
{
struct V_48 * V_201 ;
int V_140 ;
int V_14 ;
for ( V_140 = V_147 ; V_140 <= V_148 ;
V_140 ++ ) {
F_36 (comp, &card->aux_comp_list, list_aux) {
if ( V_201 -> V_10 -> V_184 == V_140 ) {
V_14 = F_99 ( V_50 , V_201 ) ;
if ( V_14 < 0 ) {
F_79 ( V_50 -> V_23 ,
L_62 ,
V_201 -> V_53 , V_14 ) ;
return V_14 ;
}
}
}
}
return 0 ;
}
static void F_129 ( struct V_63 * V_50 )
{
struct V_48 * V_201 , * V_202 ;
int V_140 ;
for ( V_140 = V_147 ; V_140 <= V_148 ;
V_140 ++ ) {
F_56 (comp, _comp,
&card->aux_comp_list, list_aux) {
if ( V_201 -> V_10 -> V_143 == V_140 ) {
F_85 ( V_201 ) ;
F_57 ( & V_201 -> V_199 ) ;
}
}
}
}
static int F_130 ( struct V_4 * V_5 )
{
int V_14 ;
if ( V_5 -> V_203 )
return 0 ;
V_14 = F_131 ( V_5 ) ;
if ( V_14 < 0 ) {
F_79 ( V_5 -> V_23 ,
L_63 ,
V_14 ) ;
return V_14 ;
}
V_5 -> V_203 = 1 ;
return 0 ;
}
int F_121 ( struct V_26 * V_27 ,
unsigned int V_192 )
{
struct V_59 * * V_78 = V_27 -> V_78 ;
struct V_59 * V_98 = V_27 -> V_98 ;
unsigned int V_3 ;
int V_14 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_79 ; V_3 ++ ) {
struct V_59 * V_121 = V_78 [ V_3 ] ;
V_14 = F_132 ( V_121 , V_192 ) ;
if ( V_14 != 0 && V_14 != - V_204 ) {
F_26 ( V_121 -> V_23 ,
L_64 , V_14 ) ;
return V_14 ;
}
}
if ( V_98 -> V_5 ) {
unsigned int V_205 ;
V_205 = V_192 & ~ V_206 ;
switch ( V_192 & V_206 ) {
case V_207 :
V_205 |= V_208 ;
break;
case V_209 :
V_205 |= V_210 ;
break;
case V_210 :
V_205 |= V_209 ;
break;
case V_208 :
V_205 |= V_207 ;
break;
}
V_192 = V_205 ;
}
V_14 = F_132 ( V_98 , V_192 ) ;
if ( V_14 != 0 && V_14 != - V_204 ) {
F_26 ( V_98 -> V_23 ,
L_64 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_133 ( struct V_63 * V_50 )
{
struct V_4 * V_5 ;
struct V_26 * V_27 ;
struct V_77 * V_71 ;
int V_14 , V_3 , V_140 ;
F_35 ( & V_58 ) ;
F_134 ( & V_50 -> V_211 , V_212 ) ;
for ( V_3 = 0 ; V_3 < V_50 -> V_213 ; V_3 ++ ) {
V_14 = F_84 ( V_50 , & V_50 -> V_71 [ V_3 ] ) ;
if ( V_14 != 0 )
goto V_214;
}
for ( V_3 = 0 ; V_3 < V_50 -> V_215 ; V_3 ++ ) {
V_14 = F_126 ( V_50 , V_3 ) ;
if ( V_14 != 0 )
goto V_214;
}
for ( V_3 = 0 ; V_3 < V_50 -> V_213 ; V_3 ++ )
F_96 ( V_50 , V_50 -> V_71 + V_3 ) ;
F_36 (codec, &codec_list, list) {
if ( V_5 -> V_203 )
continue;
V_14 = F_130 ( V_5 ) ;
if ( V_14 < 0 )
goto V_214;
}
V_14 = F_135 ( V_50 -> V_23 , V_216 , V_217 ,
V_50 -> V_139 , 0 , & V_50 -> V_88 ) ;
if ( V_14 < 0 ) {
F_79 ( V_50 -> V_23 ,
L_65 ,
V_50 -> V_53 , V_14 ) ;
goto V_214;
}
F_41 ( V_50 ) ;
V_50 -> V_105 . V_169 = V_110 ;
V_50 -> V_105 . V_23 = V_50 -> V_23 ;
V_50 -> V_105 . V_50 = V_50 ;
F_106 ( & V_50 -> V_105 . V_80 , & V_50 -> V_175 ) ;
#ifdef F_122
F_27 ( & V_50 -> V_105 , V_50 -> V_51 ) ;
#endif
#ifdef F_136
F_137 ( & V_50 -> V_113 , F_74 ) ;
#endif
if ( V_50 -> V_165 )
F_101 ( & V_50 -> V_105 , V_50 -> V_165 ,
V_50 -> V_166 ) ;
if ( V_50 -> V_218 )
F_101 ( & V_50 -> V_105 , V_50 -> V_218 ,
V_50 -> V_219 ) ;
if ( V_50 -> V_168 ) {
V_14 = V_50 -> V_168 ( V_50 ) ;
if ( V_14 < 0 )
goto V_220;
}
for ( V_140 = V_147 ; V_140 <= V_148 ;
V_140 ++ ) {
F_36 (rtd, &card->rtd_list, list) {
V_14 = F_116 ( V_50 , V_27 , V_140 ) ;
if ( V_14 < 0 ) {
F_79 ( V_50 -> V_23 ,
L_66 ,
V_14 ) ;
goto V_221;
}
}
}
V_14 = F_128 ( V_50 ) ;
if ( V_14 < 0 )
goto V_221;
F_36 (dai_link, &card->dai_link_list, list) {
if ( F_83 ( V_50 , V_71 ) )
continue;
V_14 = F_95 ( V_50 , V_71 ) ;
if ( V_14 )
goto V_221;
V_14 = F_84 ( V_50 , V_71 ) ;
if ( V_14 )
goto V_221;
}
for ( V_140 = V_147 ; V_140 <= V_148 ;
V_140 ++ ) {
F_36 (rtd, &card->rtd_list, list) {
V_14 = F_120 ( V_50 , V_27 , V_140 ) ;
if ( V_14 < 0 ) {
F_79 ( V_50 -> V_23 ,
L_66 ,
V_14 ) ;
goto V_221;
}
}
}
F_138 ( V_50 ) ;
F_139 ( V_50 ) ;
if ( V_50 -> V_171 )
F_140 ( V_50 , V_50 -> V_171 , V_50 -> V_172 ) ;
if ( V_50 -> V_173 )
F_105 ( & V_50 -> V_105 , V_50 -> V_173 ,
V_50 -> V_174 ) ;
if ( V_50 -> V_222 )
F_105 ( & V_50 -> V_105 , V_50 -> V_222 ,
V_50 -> V_223 ) ;
snprintf ( V_50 -> V_88 -> V_224 , sizeof( V_50 -> V_88 -> V_224 ) ,
L_51 , V_50 -> V_53 ) ;
snprintf ( V_50 -> V_88 -> V_225 , sizeof( V_50 -> V_88 -> V_225 ) ,
L_51 , V_50 -> V_226 ? V_50 -> V_226 : V_50 -> V_53 ) ;
snprintf ( V_50 -> V_88 -> V_10 , sizeof( V_50 -> V_88 -> V_10 ) ,
L_51 , V_50 -> V_227 ? V_50 -> V_227 : V_50 -> V_53 ) ;
for ( V_3 = 0 ; V_3 < F_141 ( V_50 -> V_88 -> V_10 ) ; V_3 ++ ) {
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
if ( V_50 -> V_228 ) {
V_14 = V_50 -> V_228 ( V_50 ) ;
if ( V_14 < 0 ) {
F_79 ( V_50 -> V_23 , L_67 ,
V_50 -> V_53 , V_14 ) ;
goto V_229;
}
}
F_142 ( V_50 ) ;
V_14 = F_143 ( V_50 -> V_88 ) ;
if ( V_14 < 0 ) {
F_79 ( V_50 -> V_23 , L_68 ,
V_14 ) ;
goto V_229;
}
V_50 -> V_87 = 1 ;
F_69 ( & V_50 -> V_105 ) ;
F_37 ( & V_50 -> V_211 ) ;
F_37 ( & V_58 ) ;
return 0 ;
V_229:
F_129 ( V_50 ) ;
V_221:
F_92 ( V_50 ) ;
V_220:
if ( V_50 -> remove )
V_50 -> remove ( V_50 ) ;
F_86 ( & V_50 -> V_105 ) ;
F_43 ( V_50 ) ;
F_144 ( V_50 -> V_88 ) ;
V_214:
F_55 ( V_50 ) ;
F_37 ( & V_50 -> V_211 ) ;
F_37 ( & V_58 ) ;
return V_14 ;
}
static int F_145 ( struct V_230 * V_231 )
{
struct V_63 * V_50 = F_146 ( V_231 ) ;
if ( ! V_50 )
return - V_15 ;
F_26 ( & V_231 -> V_23 ,
L_69 ,
V_50 -> V_53 ) ;
V_50 -> V_23 = & V_231 -> V_23 ;
return F_147 ( V_50 ) ;
}
static int F_148 ( struct V_63 * V_50 )
{
struct V_26 * V_27 ;
F_36 (rtd, &card->rtd_list, list)
F_66 ( & V_27 -> V_101 ) ;
F_92 ( V_50 ) ;
F_55 ( V_50 ) ;
F_129 ( V_50 ) ;
F_43 ( V_50 ) ;
if ( V_50 -> remove )
V_50 -> remove ( V_50 ) ;
F_86 ( & V_50 -> V_105 ) ;
F_144 ( V_50 -> V_88 ) ;
return 0 ;
}
static int F_149 ( struct V_230 * V_231 )
{
struct V_63 * V_50 = F_146 ( V_231 ) ;
F_150 ( V_50 ) ;
return 0 ;
}
int F_151 ( struct V_22 * V_23 )
{
struct V_63 * V_50 = F_7 ( V_23 ) ;
struct V_26 * V_27 ;
if ( ! V_50 -> V_87 )
return 0 ;
F_36 (rtd, &card->rtd_list, list)
F_66 ( & V_27 -> V_101 ) ;
F_152 ( V_50 ) ;
F_36 (rtd, &card->rtd_list, list) {
struct V_59 * V_98 = V_27 -> V_98 ;
int V_3 ;
F_73 ( V_98 -> V_23 ) ;
for ( V_3 = 0 ; V_3 < V_27 -> V_79 ; V_3 ++ ) {
struct V_59 * V_121 = V_27 -> V_78 [ V_3 ] ;
F_73 ( V_121 -> V_23 ) ;
}
}
return 0 ;
}
struct V_232 * F_153 ( const struct V_233 * V_234 ,
void * V_235 , const char * V_226 ,
const char * V_236 )
{
struct V_233 V_237 ;
struct V_232 * V_238 ;
char * V_53 = NULL ;
memcpy ( & V_237 , V_234 , sizeof( V_237 ) ) ;
V_237 . V_239 = 0 ;
if ( ! V_226 )
V_226 = V_237 . V_53 ;
if ( V_236 ) {
V_53 = F_24 ( V_40 , L_70 , V_236 , V_226 ) ;
if ( ! V_53 )
return NULL ;
V_237 . V_53 = V_53 ;
} else {
V_237 . V_53 = V_226 ;
}
V_238 = F_154 ( & V_237 , V_235 ) ;
F_16 ( V_53 ) ;
return V_238 ;
}
static int F_155 ( struct V_88 * V_50 , struct V_22 * V_23 ,
const struct V_233 * V_171 , int V_172 ,
const char * V_236 , void * V_235 )
{
int V_141 , V_3 ;
for ( V_3 = 0 ; V_3 < V_172 ; V_3 ++ ) {
const struct V_233 * V_240 = & V_171 [ V_3 ] ;
V_141 = F_156 ( V_50 , F_153 ( V_240 , V_235 ,
V_240 -> V_53 , V_236 ) ) ;
if ( V_141 < 0 ) {
F_79 ( V_23 , L_71 ,
V_240 -> V_53 , V_141 ) ;
return V_141 ;
}
}
return 0 ;
}
struct V_232 * F_157 ( struct V_63 * V_241 ,
const char * V_53 )
{
struct V_88 * V_50 = V_241 -> V_88 ;
struct V_232 * V_242 ;
if ( F_158 ( ! V_53 ) )
return NULL ;
F_36 (kctl, &card->controls, list)
if ( ! strncmp ( V_242 -> V_243 . V_53 , V_53 , sizeof( V_242 -> V_243 . V_53 ) ) )
return V_242 ;
return NULL ;
}
int F_104 ( struct V_48 * V_49 ,
const struct V_233 * V_171 , unsigned int V_172 )
{
struct V_88 * V_50 = V_49 -> V_50 -> V_88 ;
return F_155 ( V_50 , V_49 -> V_23 , V_171 ,
V_172 , V_49 -> V_163 , V_49 ) ;
}
int F_159 ( struct V_4 * V_5 ,
const struct V_233 * V_171 , unsigned int V_172 )
{
return F_104 ( & V_5 -> V_49 , V_171 ,
V_172 ) ;
}
int F_160 ( struct V_61 * V_62 ,
const struct V_233 * V_171 , unsigned int V_172 )
{
return F_104 ( & V_62 -> V_49 , V_171 ,
V_172 ) ;
}
int F_140 ( struct V_63 * V_241 ,
const struct V_233 * V_171 , int V_172 )
{
struct V_88 * V_50 = V_241 -> V_88 ;
return F_155 ( V_50 , V_241 -> V_23 , V_171 , V_172 ,
NULL , V_241 ) ;
}
int F_161 ( struct V_59 * V_60 ,
const struct V_233 * V_171 , int V_172 )
{
struct V_88 * V_50 = V_60 -> V_49 -> V_50 -> V_88 ;
return F_155 ( V_50 , V_60 -> V_23 , V_171 , V_172 ,
NULL , V_60 ) ;
}
int F_162 ( struct V_59 * V_60 , int V_244 ,
unsigned int V_245 , int V_246 )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_94 -> V_247 )
return V_60 -> V_10 -> V_94 -> V_247 ( V_60 , V_244 , V_245 , V_246 ) ;
else if ( V_60 -> V_5 && V_60 -> V_5 -> V_10 -> V_247 )
return V_60 -> V_5 -> V_10 -> V_247 ( V_60 -> V_5 , V_244 , 0 ,
V_245 , V_246 ) ;
else
return - V_204 ;
}
int F_163 ( struct V_4 * V_5 , int V_244 ,
int V_187 , unsigned int V_245 , int V_246 )
{
if ( V_5 -> V_10 -> V_247 )
return V_5 -> V_10 -> V_247 ( V_5 , V_244 , V_187 ,
V_245 , V_246 ) ;
else
return - V_204 ;
}
int F_164 ( struct V_59 * V_60 ,
int V_248 , int div )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_94 -> V_249 )
return V_60 -> V_10 -> V_94 -> V_249 ( V_60 , V_248 , div ) ;
else
return - V_15 ;
}
int F_165 ( struct V_59 * V_60 , int V_250 , int V_187 ,
unsigned int V_251 , unsigned int V_252 )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_94 -> V_253 )
return V_60 -> V_10 -> V_94 -> V_253 ( V_60 , V_250 , V_187 ,
V_251 , V_252 ) ;
else if ( V_60 -> V_5 && V_60 -> V_5 -> V_10 -> V_253 )
return V_60 -> V_5 -> V_10 -> V_253 ( V_60 -> V_5 , V_250 , V_187 ,
V_251 , V_252 ) ;
else
return - V_15 ;
}
int F_166 ( struct V_4 * V_5 , int V_250 , int V_187 ,
unsigned int V_251 , unsigned int V_252 )
{
if ( V_5 -> V_10 -> V_253 )
return V_5 -> V_10 -> V_253 ( V_5 , V_250 , V_187 ,
V_251 , V_252 ) ;
else
return - V_15 ;
}
int F_167 ( struct V_59 * V_60 , unsigned int V_254 )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_94 -> V_255 )
return V_60 -> V_10 -> V_94 -> V_255 ( V_60 , V_254 ) ;
else
return - V_15 ;
}
int F_132 ( struct V_59 * V_60 , unsigned int V_256 )
{
if ( V_60 -> V_10 == NULL )
return - V_15 ;
if ( V_60 -> V_10 -> V_94 -> V_257 == NULL )
return - V_204 ;
return V_60 -> V_10 -> V_94 -> V_257 ( V_60 , V_256 ) ;
}
static int F_168 ( unsigned int V_258 ,
unsigned int * V_259 ,
unsigned int * V_260 )
{
if ( * V_259 || * V_260 )
return 0 ;
if ( ! V_258 )
return - V_15 ;
* V_259 = ( 1 << V_258 ) - 1 ;
* V_260 = ( 1 << V_258 ) - 1 ;
return 0 ;
}
int F_169 ( struct V_59 * V_60 ,
unsigned int V_259 , unsigned int V_260 , int V_258 , int V_261 )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_94 -> V_262 )
V_60 -> V_10 -> V_94 -> V_262 ( V_258 ,
& V_259 , & V_260 ) ;
else
F_168 ( V_258 , & V_259 , & V_260 ) ;
V_60 -> V_259 = V_259 ;
V_60 -> V_260 = V_260 ;
if ( V_60 -> V_10 && V_60 -> V_10 -> V_94 -> V_263 )
return V_60 -> V_10 -> V_94 -> V_263 ( V_60 , V_259 , V_260 ,
V_258 , V_261 ) ;
else
return - V_204 ;
}
int F_170 ( struct V_59 * V_60 ,
unsigned int V_264 , unsigned int * V_265 ,
unsigned int V_266 , unsigned int * V_267 )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_94 -> V_268 )
return V_60 -> V_10 -> V_94 -> V_268 ( V_60 , V_264 , V_265 ,
V_266 , V_267 ) ;
else
return - V_15 ;
}
int F_171 ( struct V_59 * V_60 , int V_269 )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_94 -> V_270 )
return V_60 -> V_10 -> V_94 -> V_270 ( V_60 , V_269 ) ;
else
return - V_15 ;
}
int F_172 ( struct V_59 * V_60 , int V_271 ,
int V_272 )
{
if ( ! V_60 -> V_10 )
return - V_204 ;
if ( V_60 -> V_10 -> V_94 -> V_273 )
return V_60 -> V_10 -> V_94 -> V_273 ( V_60 , V_271 , V_272 ) ;
else if ( V_272 == V_102 &&
V_60 -> V_10 -> V_94 -> V_95 )
return V_60 -> V_10 -> V_94 -> V_95 ( V_60 , V_271 ) ;
else
return - V_204 ;
}
int F_147 ( struct V_63 * V_50 )
{
int V_3 , V_14 ;
struct V_26 * V_27 ;
if ( ! V_50 -> V_53 || ! V_50 -> V_23 )
return - V_15 ;
for ( V_3 = 0 ; V_3 < V_50 -> V_213 ; V_3 ++ ) {
struct V_77 * V_145 = & V_50 -> V_71 [ V_3 ] ;
V_14 = F_95 ( V_50 , V_145 ) ;
if ( V_14 ) {
F_79 ( V_50 -> V_23 , L_72 ,
V_145 -> V_53 ) ;
return V_14 ;
}
}
F_111 ( V_50 -> V_23 , V_50 ) ;
F_173 ( V_50 ) ;
F_113 ( & V_50 -> V_156 ) ;
V_50 -> V_151 = 0 ;
F_113 ( & V_50 -> V_81 ) ;
V_50 -> V_83 = 0 ;
F_113 ( & V_50 -> V_274 ) ;
F_113 ( & V_50 -> V_275 ) ;
V_50 -> V_87 = 0 ;
F_112 ( & V_50 -> V_211 ) ;
F_112 ( & V_50 -> V_276 ) ;
V_14 = F_133 ( V_50 ) ;
if ( V_14 != 0 )
return V_14 ;
F_36 (rtd, &card->rtd_list, list) {
struct V_59 * V_98 = V_27 -> V_98 ;
int V_119 ;
for ( V_119 = 0 ; V_119 < V_27 -> V_79 ; V_119 ++ ) {
struct V_59 * V_121 = V_27 -> V_78 [ V_119 ] ;
if ( ! V_121 -> V_120 )
F_73 ( V_121 -> V_23 ) ;
}
if ( ! V_98 -> V_120 )
F_73 ( V_98 -> V_23 ) ;
}
return V_14 ;
}
int F_150 ( struct V_63 * V_50 )
{
if ( V_50 -> V_87 ) {
V_50 -> V_87 = false ;
F_152 ( V_50 ) ;
F_148 ( V_50 ) ;
F_49 ( V_50 -> V_23 , L_73 , V_50 -> V_53 ) ;
}
return 0 ;
}
static char * F_174 ( struct V_22 * V_23 , int * V_243 )
{
char * V_277 , V_53 [ V_278 ] ;
int V_279 , V_280 ;
if ( V_162 ( V_23 ) == NULL )
return NULL ;
F_175 ( V_53 , V_162 ( V_23 ) , V_278 ) ;
V_277 = strstr ( V_53 , V_23 -> V_10 -> V_53 ) ;
if ( V_277 ) {
if ( sscanf ( & V_277 [ strlen ( V_23 -> V_10 -> V_53 ) ] , L_74 , V_243 ) == 1 ) {
if ( * V_243 == - 1 )
V_277 [ strlen ( V_23 -> V_10 -> V_53 ) ] = '\0' ;
}
} else {
if ( sscanf ( V_53 , L_75 , & V_279 , & V_280 ) == 2 ) {
char V_281 [ V_278 ] ;
* V_243 = ( ( V_279 & 0xffff ) << 16 ) + V_280 ;
snprintf ( V_281 , V_278 , L_76 , V_23 -> V_10 -> V_53 , V_53 ) ;
F_175 ( V_53 , V_281 , V_278 ) ;
} else
* V_243 = 0 ;
}
return F_176 ( V_53 , V_40 ) ;
}
static inline char * F_177 ( struct V_22 * V_23 ,
struct V_92 * V_282 )
{
if ( V_282 -> V_53 == NULL ) {
F_79 ( V_23 ,
L_77 ,
V_162 ( V_23 ) ) ;
return NULL ;
}
return F_176 ( V_282 -> V_53 , V_40 ) ;
}
static void F_178 ( struct V_48 * V_49 )
{
struct V_59 * V_60 , * V_283 ;
F_56 (dai, _dai, &component->dai_list, list) {
F_49 ( V_49 -> V_23 , L_78 ,
V_60 -> V_53 ) ;
F_57 ( & V_60 -> V_80 ) ;
F_16 ( V_60 -> V_53 ) ;
F_16 ( V_60 ) ;
}
}
static struct V_59 * F_179 ( struct V_48 * V_49 ,
struct V_92 * V_282 ,
bool V_284 )
{
struct V_22 * V_23 = V_49 -> V_23 ;
struct V_59 * V_60 ;
F_49 ( V_23 , L_79 , V_162 ( V_23 ) ) ;
V_60 = F_51 ( sizeof( struct V_59 ) , V_40 ) ;
if ( V_60 == NULL )
return NULL ;
if ( V_284 &&
( V_282 -> V_243 == 0 || V_282 -> V_53 == NULL ) ) {
V_60 -> V_53 = F_174 ( V_23 , & V_60 -> V_243 ) ;
} else {
V_60 -> V_53 = F_177 ( V_23 , V_282 ) ;
if ( V_282 -> V_243 )
V_60 -> V_243 = V_282 -> V_243 ;
else
V_60 -> V_243 = V_49 -> V_285 ;
}
if ( V_60 -> V_53 == NULL ) {
F_16 ( V_60 ) ;
return NULL ;
}
V_60 -> V_49 = V_49 ;
V_60 -> V_23 = V_23 ;
V_60 -> V_10 = V_282 ;
if ( ! V_60 -> V_10 -> V_94 )
V_60 -> V_10 -> V_94 = & V_286 ;
F_106 ( & V_60 -> V_80 , & V_49 -> V_287 ) ;
V_49 -> V_285 ++ ;
F_49 ( V_23 , L_80 , V_60 -> V_53 ) ;
return V_60 ;
}
static int F_180 ( struct V_48 * V_49 ,
struct V_92 * V_282 , T_1 V_16 ,
bool V_284 )
{
struct V_22 * V_23 = V_49 -> V_23 ;
struct V_59 * V_60 ;
unsigned int V_3 ;
int V_14 ;
F_49 ( V_23 , L_81 , V_162 ( V_23 ) , V_16 ) ;
V_49 -> V_282 = V_282 ;
for ( V_3 = 0 ; V_3 < V_16 ; V_3 ++ ) {
V_60 = F_179 ( V_49 , V_282 + V_3 ,
V_16 == 1 && V_284 ) ;
if ( V_60 == NULL ) {
V_14 = - V_41 ;
goto V_141;
}
}
return 0 ;
V_141:
F_178 ( V_49 ) ;
return V_14 ;
}
int F_181 ( struct V_48 * V_49 ,
struct V_92 * V_282 )
{
struct V_106 * V_105 =
F_28 ( V_49 ) ;
struct V_59 * V_60 ;
int V_14 ;
if ( V_282 -> V_149 . type != V_288 ) {
F_79 ( V_49 -> V_23 , L_82 ,
V_282 -> V_149 . type ) ;
return - V_15 ;
}
F_81 ( & V_58 ) ;
V_60 = F_179 ( V_49 , V_282 , false ) ;
if ( ! V_60 )
return - V_41 ;
V_14 = F_102 ( V_105 , V_60 ) ;
if ( V_14 != 0 ) {
F_79 ( V_49 -> V_23 ,
L_47 , V_14 ) ;
}
return V_14 ;
}
static void F_182 ( struct V_106 * V_105 ,
enum V_289 type , int V_290 )
{
struct V_48 * V_49 = V_105 -> V_49 ;
V_49 -> V_10 -> V_291 ( V_49 , type , V_290 ) ;
}
static int F_183 ( struct V_106 * V_105 ,
int V_292 )
{
struct V_48 * V_49 = V_105 -> V_49 ;
return V_49 -> V_10 -> V_293 ( V_49 , V_292 ) ;
}
static int F_184 ( struct V_48 * V_49 ,
const struct V_294 * V_10 , struct V_22 * V_23 )
{
struct V_106 * V_105 ;
V_49 -> V_53 = F_174 ( V_23 , & V_49 -> V_243 ) ;
if ( ! V_49 -> V_53 ) {
F_79 ( V_23 , L_83 ) ;
return - V_41 ;
}
V_49 -> V_23 = V_23 ;
V_49 -> V_10 = V_10 ;
V_49 -> V_168 = V_49 -> V_10 -> V_168 ;
V_49 -> remove = V_49 -> V_10 -> remove ;
V_105 = & V_49 -> V_105 ;
V_105 -> V_23 = V_23 ;
V_105 -> V_49 = V_49 ;
V_105 -> V_169 = V_110 ;
V_105 -> V_109 = true ;
if ( V_10 -> V_291 )
V_105 -> V_291 = F_182 ;
if ( V_10 -> V_293 )
V_105 -> V_293 = F_183 ;
V_49 -> V_171 = V_10 -> V_171 ;
V_49 -> V_172 = V_10 -> V_172 ;
V_49 -> V_165 = V_10 -> V_165 ;
V_49 -> V_166 = V_10 -> V_166 ;
V_49 -> V_173 = V_10 -> V_173 ;
V_49 -> V_174 = V_10 -> V_174 ;
F_113 ( & V_49 -> V_287 ) ;
F_112 ( & V_49 -> V_295 ) ;
return 0 ;
}
static void F_185 ( struct V_48 * V_49 )
{
int V_296 = F_186 ( V_49 -> V_111 ) ;
if ( V_296 > 0 )
V_49 -> V_296 = V_296 ;
}
void F_187 ( struct V_48 * V_49 ,
struct V_111 * V_111 )
{
V_49 -> V_111 = V_111 ;
F_185 ( V_49 ) ;
}
void F_188 ( struct V_48 * V_49 )
{
F_189 ( V_49 -> V_111 ) ;
V_49 -> V_111 = NULL ;
}
static void F_190 ( struct V_48 * V_49 )
{
if ( ! V_49 -> V_297 && ! V_49 -> V_298 ) {
if ( ! V_49 -> V_111 )
V_49 -> V_111 = F_191 ( V_49 -> V_23 , NULL ) ;
if ( V_49 -> V_111 )
F_185 ( V_49 ) ;
}
F_106 ( & V_49 -> V_80 , & V_299 ) ;
F_113 ( & V_49 -> V_275 ) ;
}
static void F_192 ( struct V_48 * V_49 )
{
F_35 ( & V_58 ) ;
F_190 ( V_49 ) ;
F_37 ( & V_58 ) ;
}
static void F_193 ( struct V_48 * V_49 )
{
F_178 ( V_49 ) ;
F_16 ( V_49 -> V_53 ) ;
}
static void F_194 ( struct V_48 * V_49 )
{
F_57 ( & V_49 -> V_80 ) ;
}
int F_195 ( struct V_22 * V_23 ,
const struct V_294 * V_300 ,
struct V_92 * V_282 ,
int V_285 )
{
struct V_48 * V_301 ;
int V_14 ;
V_301 = F_51 ( sizeof( * V_301 ) , V_40 ) ;
if ( ! V_301 ) {
F_79 ( V_23 , L_84 ) ;
return - V_41 ;
}
V_14 = F_184 ( V_301 , V_300 , V_23 ) ;
if ( V_14 )
goto V_302;
V_301 -> V_303 = true ;
V_301 -> V_304 = true ;
V_14 = F_180 ( V_301 , V_282 , V_285 , true ) ;
if ( V_14 < 0 ) {
F_79 ( V_23 , L_85 , V_14 ) ;
goto V_305;
}
F_192 ( V_301 ) ;
return 0 ;
V_305:
F_193 ( V_301 ) ;
V_302:
F_16 ( V_301 ) ;
return V_14 ;
}
void F_196 ( struct V_22 * V_23 )
{
struct V_48 * V_301 ;
F_35 ( & V_58 ) ;
F_36 (cmpnt, &component_list, list) {
if ( V_23 == V_301 -> V_23 && V_301 -> V_304 )
goto V_277;
}
F_37 ( & V_58 ) ;
return;
V_277:
F_197 ( V_301 , V_306 ) ;
F_194 ( V_301 ) ;
F_37 ( & V_58 ) ;
F_193 ( V_301 ) ;
F_16 ( V_301 ) ;
}
static int F_198 ( struct V_48 * V_49 )
{
struct V_61 * V_62 = F_199 ( V_49 ) ;
return V_62 -> V_10 -> V_168 ( V_62 ) ;
}
static void F_200 ( struct V_48 * V_49 )
{
struct V_61 * V_62 = F_199 ( V_49 ) ;
V_62 -> V_10 -> remove ( V_62 ) ;
}
int F_201 ( struct V_22 * V_23 , struct V_61 * V_62 ,
const struct V_307 * V_308 )
{
int V_14 ;
V_14 = F_184 ( & V_62 -> V_49 ,
& V_308 -> V_309 , V_23 ) ;
if ( V_14 )
return V_14 ;
V_62 -> V_23 = V_23 ;
V_62 -> V_10 = V_308 ;
if ( V_308 -> V_168 )
V_62 -> V_49 . V_168 = F_198 ;
if ( V_308 -> remove )
V_62 -> V_49 . remove = F_200 ;
#ifdef F_122
V_62 -> V_49 . V_52 = L_86 ;
#endif
F_35 ( & V_58 ) ;
F_190 ( & V_62 -> V_49 ) ;
F_106 ( & V_62 -> V_80 , & V_310 ) ;
F_37 ( & V_58 ) ;
F_49 ( V_23 , L_87 ,
V_62 -> V_49 . V_53 ) ;
return 0 ;
}
int F_202 ( struct V_22 * V_23 ,
const struct V_307 * V_308 )
{
struct V_61 * V_62 ;
int V_14 ;
F_49 ( V_23 , L_88 , V_162 ( V_23 ) ) ;
V_62 = F_51 ( sizeof( struct V_61 ) , V_40 ) ;
if ( V_62 == NULL )
return - V_41 ;
V_14 = F_201 ( V_23 , V_62 , V_308 ) ;
if ( V_14 )
F_16 ( V_62 ) ;
return V_14 ;
}
void F_203 ( struct V_61 * V_62 )
{
F_35 ( & V_58 ) ;
F_57 ( & V_62 -> V_80 ) ;
F_194 ( & V_62 -> V_49 ) ;
F_37 ( & V_58 ) ;
F_49 ( V_62 -> V_23 , L_89 ,
V_62 -> V_49 . V_53 ) ;
F_193 ( & V_62 -> V_49 ) ;
}
struct V_61 * F_204 ( struct V_22 * V_23 )
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
void F_205 ( struct V_22 * V_23 )
{
struct V_61 * V_62 ;
V_62 = F_204 ( V_23 ) ;
if ( ! V_62 )
return;
F_203 ( V_62 ) ;
F_16 ( V_62 ) ;
}
static void F_206 ( struct V_311 * V_72 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_141 ( V_312 ) ; V_3 ++ )
if ( V_72 -> V_313 & V_312 [ V_3 ] )
V_72 -> V_313 |= V_312 [ V_3 ] ;
}
static int F_207 ( struct V_48 * V_49 )
{
struct V_4 * V_5 = F_32 ( V_49 ) ;
return V_5 -> V_10 -> V_168 ( V_5 ) ;
}
static void F_208 ( struct V_48 * V_49 )
{
struct V_4 * V_5 = F_32 ( V_49 ) ;
V_5 -> V_10 -> remove ( V_5 ) ;
}
static int F_209 ( struct V_48 * V_49 ,
unsigned int V_6 , unsigned int V_1 )
{
struct V_4 * V_5 = F_32 ( V_49 ) ;
return V_5 -> V_10 -> V_297 ( V_5 , V_6 , V_1 ) ;
}
static int F_210 ( struct V_48 * V_49 ,
unsigned int V_6 , unsigned int * V_1 )
{
struct V_4 * V_5 = F_32 ( V_49 ) ;
* V_1 = V_5 -> V_10 -> V_298 ( V_5 , V_6 ) ;
return 0 ;
}
static int F_211 ( struct V_106 * V_105 ,
enum V_314 V_315 )
{
struct V_4 * V_5 = F_212 ( V_105 ) ;
return V_5 -> V_10 -> V_316 ( V_5 , V_315 ) ;
}
int F_213 ( struct V_22 * V_23 ,
const struct V_317 * V_318 ,
struct V_92 * V_282 ,
int V_285 )
{
struct V_106 * V_105 ;
struct V_4 * V_5 ;
struct V_59 * V_60 ;
int V_14 , V_3 ;
F_49 ( V_23 , L_90 , V_162 ( V_23 ) ) ;
V_5 = F_51 ( sizeof( struct V_4 ) , V_40 ) ;
if ( V_5 == NULL )
return - V_41 ;
V_5 -> V_49 . V_5 = V_5 ;
V_14 = F_184 ( & V_5 -> V_49 ,
& V_318 -> V_309 , V_23 ) ;
if ( V_14 )
goto V_302;
if ( V_318 -> V_171 ) {
V_5 -> V_49 . V_171 = V_318 -> V_171 ;
V_5 -> V_49 . V_172 = V_318 -> V_172 ;
}
if ( V_318 -> V_165 ) {
V_5 -> V_49 . V_165 = V_318 -> V_165 ;
V_5 -> V_49 . V_166 = V_318 -> V_166 ;
}
if ( V_318 -> V_173 ) {
V_5 -> V_49 . V_173 = V_318 -> V_173 ;
V_5 -> V_49 . V_174 = V_318 -> V_174 ;
}
if ( V_318 -> V_168 )
V_5 -> V_49 . V_168 = F_207 ;
if ( V_318 -> remove )
V_5 -> V_49 . remove = F_208 ;
if ( V_318 -> V_297 )
V_5 -> V_49 . V_297 = F_209 ;
if ( V_318 -> V_298 )
V_5 -> V_49 . V_298 = F_210 ;
V_5 -> V_49 . V_303 = V_318 -> V_303 ;
V_105 = F_70 ( V_5 ) ;
V_105 -> V_109 = V_318 -> V_109 ;
V_105 -> V_319 = V_318 -> V_319 ;
if ( V_318 -> V_291 )
V_105 -> V_291 = V_318 -> V_291 ;
if ( V_318 -> V_316 )
V_105 -> V_316 = F_211 ;
V_5 -> V_23 = V_23 ;
V_5 -> V_10 = V_318 ;
V_5 -> V_49 . V_296 = V_318 -> V_13 ;
#ifdef F_122
V_5 -> V_49 . V_55 = F_31 ;
V_5 -> V_49 . V_52 = L_91 ;
#endif
if ( V_318 -> V_320 )
V_5 -> V_49 . V_111 = V_318 -> V_320 ( V_23 ) ;
for ( V_3 = 0 ; V_3 < V_285 ; V_3 ++ ) {
F_206 ( & V_282 [ V_3 ] . V_321 ) ;
F_206 ( & V_282 [ V_3 ] . V_322 ) ;
}
V_14 = F_180 ( & V_5 -> V_49 , V_282 , V_285 , false ) ;
if ( V_14 < 0 ) {
F_79 ( V_23 , L_85 , V_14 ) ;
goto V_305;
}
F_36 (dai, &codec->component.dai_list, list)
V_60 -> V_5 = V_5 ;
F_35 ( & V_58 ) ;
F_190 ( & V_5 -> V_49 ) ;
F_106 ( & V_5 -> V_80 , & V_323 ) ;
F_37 ( & V_58 ) ;
F_49 ( V_5 -> V_23 , L_92 ,
V_5 -> V_49 . V_53 ) ;
return 0 ;
V_305:
F_193 ( & V_5 -> V_49 ) ;
V_302:
F_16 ( V_5 ) ;
return V_14 ;
}
void F_214 ( struct V_22 * V_23 )
{
struct V_4 * V_5 ;
F_35 ( & V_58 ) ;
F_36 (codec, &codec_list, list) {
if ( V_23 == V_5 -> V_23 )
goto V_277;
}
F_37 ( & V_58 ) ;
return;
V_277:
F_57 ( & V_5 -> V_80 ) ;
F_194 ( & V_5 -> V_49 ) ;
F_37 ( & V_58 ) ;
F_49 ( V_5 -> V_23 , L_93 ,
V_5 -> V_49 . V_53 ) ;
F_193 ( & V_5 -> V_49 ) ;
F_215 ( V_5 ) ;
F_16 ( V_5 ) ;
}
int F_216 ( struct V_63 * V_50 ,
const char * V_324 )
{
struct V_122 * V_325 ;
int V_14 ;
if ( ! V_50 -> V_23 ) {
F_217 ( L_94 , V_326 ) ;
return - V_15 ;
}
V_325 = V_50 -> V_23 -> V_123 ;
V_14 = F_218 ( V_325 , V_324 , 0 , & V_50 -> V_53 ) ;
if ( V_14 < 0 && V_14 != - V_15 ) {
F_79 ( V_50 -> V_23 ,
L_95 ,
V_324 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
int F_219 ( struct V_63 * V_50 ,
const char * V_324 )
{
struct V_122 * V_325 = V_50 -> V_23 -> V_123 ;
struct V_185 * V_327 ;
const char * V_237 , * V_328 ;
int V_3 , V_119 , V_329 , V_14 ;
V_329 = F_220 ( V_325 , V_324 ) ;
if ( V_329 < 0 ) {
F_79 ( V_50 -> V_23 ,
L_96 , V_324 ) ;
return - V_15 ;
}
if ( V_329 & 1 ) {
F_79 ( V_50 -> V_23 ,
L_97 , V_324 ) ;
return - V_15 ;
}
V_329 /= 2 ;
if ( ! V_329 ) {
F_79 ( V_50 -> V_23 , L_98 ,
V_324 ) ;
return - V_15 ;
}
V_327 = F_221 ( V_50 -> V_23 , V_329 , sizeof( * V_327 ) ,
V_40 ) ;
if ( ! V_327 ) {
F_79 ( V_50 -> V_23 ,
L_99 ) ;
return - V_41 ;
}
for ( V_3 = 0 ; V_3 < V_329 ; V_3 ++ ) {
V_14 = F_218 ( V_325 , V_324 ,
2 * V_3 , & V_237 ) ;
if ( V_14 ) {
F_79 ( V_50 -> V_23 ,
L_100 ,
V_324 , 2 * V_3 , V_14 ) ;
return - V_15 ;
}
for ( V_119 = 0 ; V_119 < F_141 ( V_330 ) ; V_119 ++ ) {
if ( ! strncmp ( V_237 , V_330 [ V_119 ] . V_53 ,
strlen ( V_330 [ V_119 ] . V_53 ) ) ) {
V_327 [ V_3 ] = V_330 [ V_119 ] ;
break;
}
}
if ( V_119 >= F_141 ( V_330 ) ) {
F_79 ( V_50 -> V_23 ,
L_101 ,
V_237 ) ;
return - V_15 ;
}
V_14 = F_218 ( V_325 , V_324 ,
( 2 * V_3 ) + 1 ,
& V_328 ) ;
if ( V_14 ) {
F_79 ( V_50 -> V_23 ,
L_100 ,
V_324 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_15 ;
}
V_327 [ V_3 ] . V_53 = V_328 ;
}
V_50 -> V_218 = V_327 ;
V_50 -> V_219 = V_329 ;
return 0 ;
}
static int F_222 ( struct V_122 * V_325 ,
const char * V_331 ,
unsigned int * V_332 )
{
T_6 V_1 ;
const T_7 * V_333 = F_223 ( V_325 , V_331 , & V_1 ) ;
int V_3 ;
if ( ! V_333 )
return 0 ;
V_1 /= sizeof( T_6 ) ;
for ( V_3 = 0 ; V_3 < V_1 ; V_3 ++ )
if ( F_224 ( & V_333 [ V_3 ] ) )
* V_332 |= ( 1 << V_3 ) ;
return V_1 ;
}
int F_225 ( struct V_122 * V_325 ,
unsigned int * V_259 ,
unsigned int * V_260 ,
unsigned int * V_258 ,
unsigned int * V_261 )
{
T_6 V_1 ;
int V_14 ;
if ( V_259 )
F_222 ( V_325 , L_102 , V_259 ) ;
if ( V_260 )
F_222 ( V_325 , L_103 , V_260 ) ;
if ( F_226 ( V_325 , L_104 ) ) {
V_14 = F_227 ( V_325 , L_104 , & V_1 ) ;
if ( V_14 )
return V_14 ;
if ( V_258 )
* V_258 = V_1 ;
}
if ( F_226 ( V_325 , L_105 ) ) {
V_14 = F_227 ( V_325 , L_105 , & V_1 ) ;
if ( V_14 )
return V_14 ;
if ( V_261 )
* V_261 = V_1 ;
}
return 0 ;
}
void F_228 ( struct V_63 * V_50 ,
struct V_160 * V_158 ,
struct V_122 * V_123 ,
const char * V_324 )
{
struct V_122 * V_325 = V_50 -> V_23 -> V_123 ;
const char * V_334 ;
int V_14 ;
V_14 = F_229 ( V_325 , V_324 , & V_334 ) ;
if ( V_14 < 0 ) {
return;
}
V_158 -> V_123 = V_123 ;
V_158 -> V_163 = V_334 ;
}
int F_230 ( struct V_63 * V_50 ,
const char * V_324 )
{
struct V_122 * V_325 = V_50 -> V_23 -> V_123 ;
int V_335 ;
struct V_336 * V_337 ;
int V_3 , V_14 ;
V_335 = F_220 ( V_325 , V_324 ) ;
if ( V_335 < 0 || V_335 & 1 ) {
F_79 ( V_50 -> V_23 ,
L_106 ,
V_324 ) ;
return - V_15 ;
}
V_335 /= 2 ;
if ( ! V_335 ) {
F_79 ( V_50 -> V_23 , L_98 ,
V_324 ) ;
return - V_15 ;
}
V_337 = F_94 ( V_50 -> V_23 , V_335 * sizeof( * V_337 ) ,
V_40 ) ;
if ( ! V_337 ) {
F_79 ( V_50 -> V_23 ,
L_107 ) ;
return - V_15 ;
}
for ( V_3 = 0 ; V_3 < V_335 ; V_3 ++ ) {
V_14 = F_218 ( V_325 , V_324 ,
2 * V_3 , & V_337 [ V_3 ] . V_186 ) ;
if ( V_14 ) {
F_79 ( V_50 -> V_23 ,
L_108 ,
V_324 , 2 * V_3 , V_14 ) ;
return - V_15 ;
}
V_14 = F_218 ( V_325 , V_324 ,
( 2 * V_3 ) + 1 , & V_337 [ V_3 ] . V_187 ) ;
if ( V_14 ) {
F_79 ( V_50 -> V_23 ,
L_108 ,
V_324 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_15 ;
}
}
V_50 -> V_223 = V_335 ;
V_50 -> V_222 = V_337 ;
return 0 ;
}
unsigned int F_231 ( struct V_122 * V_325 ,
const char * V_236 ,
struct V_122 * * V_338 ,
struct V_122 * * V_339 )
{
int V_14 , V_3 ;
char V_340 [ 128 ] ;
unsigned int V_341 = 0 ;
int V_342 , V_343 ;
const char * V_334 ;
struct {
char * V_53 ;
unsigned int V_1 ;
} V_344 [] = {
{ L_109 , V_345 } ,
{ L_110 , V_346 } ,
{ L_111 , V_347 } ,
{ L_112 , V_348 } ,
{ L_113 , V_349 } ,
{ L_114 , V_350 } ,
{ L_115 , V_351 } ,
{ L_116 , V_352 } ,
{ L_117 , V_353 } ,
} ;
if ( ! V_236 )
V_236 = L_118 ;
snprintf ( V_340 , sizeof( V_340 ) , L_119 , V_236 ) ;
V_14 = F_229 ( V_325 , V_340 , & V_334 ) ;
if ( V_14 == 0 ) {
for ( V_3 = 0 ; V_3 < F_141 ( V_344 ) ; V_3 ++ ) {
if ( strcmp ( V_334 , V_344 [ V_3 ] . V_53 ) == 0 ) {
V_341 |= V_344 [ V_3 ] . V_1 ;
break;
}
}
}
snprintf ( V_340 , sizeof( V_340 ) , L_120 , V_236 ) ;
if ( F_223 ( V_325 , V_340 , NULL ) )
V_341 |= V_354 ;
else
V_341 |= V_355 ;
snprintf ( V_340 , sizeof( V_340 ) , L_121 , V_236 ) ;
V_342 = ! ! F_223 ( V_325 , V_340 , NULL ) ;
snprintf ( V_340 , sizeof( V_340 ) , L_122 , V_236 ) ;
V_343 = ! ! F_223 ( V_325 , V_340 , NULL ) ;
switch ( ( V_342 << 4 ) + V_343 ) {
case 0x11 :
V_341 |= V_356 ;
break;
case 0x10 :
V_341 |= V_357 ;
break;
case 0x01 :
V_341 |= V_358 ;
break;
default:
break;
}
snprintf ( V_340 , sizeof( V_340 ) , L_123 , V_236 ) ;
V_342 = ! ! F_223 ( V_325 , V_340 , NULL ) ;
if ( V_342 && V_338 )
* V_338 = F_232 ( V_325 , V_340 , 0 ) ;
snprintf ( V_340 , sizeof( V_340 ) , L_124 , V_236 ) ;
V_343 = ! ! F_223 ( V_325 , V_340 , NULL ) ;
if ( V_343 && V_339 )
* V_339 = F_232 ( V_325 , V_340 , 0 ) ;
switch ( ( V_342 << 4 ) + V_343 ) {
case 0x11 :
V_341 |= V_207 ;
break;
case 0x10 :
V_341 |= V_209 ;
break;
case 0x01 :
V_341 |= V_210 ;
break;
default:
V_341 |= V_208 ;
break;
}
return V_341 ;
}
static int F_233 ( struct V_359 * args ,
const char * * V_128 )
{
struct V_48 * V_17 ;
struct V_122 * V_126 ;
int V_14 = - V_137 ;
F_35 ( & V_58 ) ;
F_36 (pos, &component_list, list) {
V_126 = V_17 -> V_23 -> V_123 ;
if ( ! V_126 && V_17 -> V_23 -> V_127 )
V_126 = V_17 -> V_23 -> V_127 -> V_123 ;
if ( V_126 != args -> V_325 )
continue;
if ( V_17 -> V_10 -> V_360 ) {
V_14 = V_17 -> V_10 -> V_360 ( V_17 ,
args ,
V_128 ) ;
} else {
int V_243 = - 1 ;
switch ( args -> V_361 ) {
case 0 :
V_243 = 0 ;
break;
case 1 :
V_243 = args -> args [ 0 ] ;
break;
default:
break;
}
if ( V_243 < 0 || V_243 >= V_17 -> V_285 ) {
V_14 = - V_15 ;
continue;
}
V_14 = 0 ;
* V_128 = V_17 -> V_282 [ V_243 ] . V_53 ;
if ( ! * V_128 )
* V_128 = V_17 -> V_53 ;
}
break;
}
F_37 ( & V_58 ) ;
return V_14 ;
}
int F_234 ( struct V_122 * V_123 ,
const char * * V_128 )
{
struct V_359 args ;
int V_14 ;
V_14 = F_235 ( V_123 , L_125 ,
L_126 , 0 , & args ) ;
if ( V_14 )
return V_14 ;
V_14 = F_233 ( & args , V_128 ) ;
F_236 ( args . V_325 ) ;
return V_14 ;
}
int F_237 ( struct V_22 * V_23 ,
struct V_122 * V_123 ,
struct V_77 * V_71 )
{
struct V_359 args ;
struct V_124 * V_49 ;
char * V_53 ;
int V_239 , V_79 , V_14 ;
V_53 = L_125 ;
V_79 = F_238 ( V_123 , V_53 ,
L_126 ) ;
if ( V_79 <= 0 ) {
if ( V_79 == - V_362 )
F_79 ( V_23 , L_127 ) ;
else
F_79 ( V_23 , L_128 ) ;
return V_79 ;
}
V_49 = F_94 ( V_23 ,
sizeof *V_49 * V_79 ,
V_40 ) ;
if ( ! V_49 )
return - V_41 ;
V_71 -> V_129 = V_49 ;
V_71 -> V_79 = V_79 ;
for ( V_239 = 0 , V_49 = V_71 -> V_129 ;
V_239 < V_71 -> V_79 ;
V_239 ++ , V_49 ++ ) {
V_14 = F_235 ( V_123 , V_53 ,
L_126 ,
V_239 , & args ) ;
if ( V_14 )
goto V_141;
V_49 -> V_123 = args . V_325 ;
V_14 = F_233 ( & args , & V_49 -> V_128 ) ;
if ( V_14 < 0 )
goto V_141;
}
return 0 ;
V_141:
for ( V_239 = 0 , V_49 = V_71 -> V_129 ;
V_239 < V_71 -> V_79 ;
V_239 ++ , V_49 ++ ) {
if ( ! V_49 -> V_123 )
break;
F_236 ( V_49 -> V_123 ) ;
V_49 -> V_123 = NULL ;
}
V_71 -> V_129 = NULL ;
V_71 -> V_79 = 0 ;
return V_14 ;
}
static int T_8 F_239 ( void )
{
F_44 () ;
F_240 () ;
return F_241 ( & V_363 ) ;
}
static void T_9 F_242 ( void )
{
F_243 () ;
F_47 () ;
#ifdef F_122
#endif
F_244 ( & V_363 ) ;
}
