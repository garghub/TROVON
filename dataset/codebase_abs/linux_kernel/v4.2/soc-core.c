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
int V_3 ;
for ( V_3 = 0 ; V_3 < V_50 -> V_73 ; V_3 ++ ) {
if ( V_50 -> V_27 [ V_3 ] . V_71 -> V_74 &&
! strcmp ( V_50 -> V_27 [ V_3 ] . V_71 -> V_53 , V_71 ) )
return V_50 -> V_27 [ V_3 ] . V_75 -> V_76 [ V_72 ] . V_77 ;
}
F_49 ( V_50 -> V_23 , L_20 , V_71 ) ;
return NULL ;
}
struct V_26 * F_50 ( struct V_63 * V_50 ,
const char * V_71 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_50 -> V_73 ; V_3 ++ ) {
if ( ! strcmp ( V_50 -> V_27 [ V_3 ] . V_71 -> V_53 , V_71 ) )
return & V_50 -> V_27 [ V_3 ] ;
}
F_49 ( V_50 -> V_23 , L_21 , V_71 ) ;
return NULL ;
}
static void F_51 ( struct V_78 * V_79 )
{
}
int F_52 ( struct V_22 * V_23 )
{
struct V_63 * V_50 = F_7 ( V_23 ) ;
struct V_4 * V_5 ;
int V_3 , V_80 ;
if ( ! V_50 -> V_81 )
return 0 ;
F_53 ( V_50 -> V_82 ) ;
F_54 ( V_50 -> V_82 , V_83 ) ;
F_55 ( V_50 -> V_82 ) ;
F_56 ( V_50 -> V_82 , V_84 ) ;
for ( V_3 = 0 ; V_3 < V_50 -> V_85 ; V_3 ++ ) {
if ( V_50 -> V_27 [ V_3 ] . V_71 -> V_86 )
continue;
for ( V_80 = 0 ; V_80 < V_50 -> V_27 [ V_3 ] . V_87 ; V_80 ++ ) {
struct V_59 * V_60 = V_50 -> V_27 [ V_3 ] . V_88 [ V_80 ] ;
struct V_89 * V_90 = V_60 -> V_10 ;
if ( V_90 -> V_91 -> V_92 && V_60 -> V_93 )
V_90 -> V_91 -> V_92 ( V_60 , 1 ) ;
}
}
for ( V_3 = 0 ; V_3 < V_50 -> V_85 ; V_3 ++ ) {
if ( V_50 -> V_27 [ V_3 ] . V_71 -> V_86 )
continue;
F_57 ( V_50 -> V_27 [ V_3 ] . V_75 ) ;
}
if ( V_50 -> V_94 )
V_50 -> V_94 ( V_50 ) ;
for ( V_3 = 0 ; V_3 < V_50 -> V_85 ; V_3 ++ ) {
struct V_59 * V_95 = V_50 -> V_27 [ V_3 ] . V_95 ;
if ( V_50 -> V_27 [ V_3 ] . V_71 -> V_86 )
continue;
if ( V_95 -> V_10 -> V_96 && ! V_95 -> V_10 -> V_97 )
V_95 -> V_10 -> V_96 ( V_95 ) ;
}
for ( V_3 = 0 ; V_3 < V_50 -> V_85 ; V_3 ++ )
F_58 ( & V_50 -> V_27 [ V_3 ] . V_98 ) ;
for ( V_3 = 0 ; V_3 < V_50 -> V_85 ; V_3 ++ ) {
if ( V_50 -> V_27 [ V_3 ] . V_71 -> V_86 )
continue;
F_59 ( & V_50 -> V_27 [ V_3 ] ,
V_99 ,
V_100 ) ;
F_59 ( & V_50 -> V_27 [ V_3 ] ,
V_101 ,
V_100 ) ;
}
F_60 ( V_50 ) ;
F_61 ( & V_50 -> V_102 ) ;
F_36 (codec, &card->codec_dev_list, card_list) {
if ( ! V_5 -> V_103 ) {
switch ( V_5 -> V_102 . V_104 ) {
case V_105 :
if ( V_5 -> V_102 . V_106 ) {
F_49 ( V_5 -> V_23 ,
L_22 ) ;
break;
}
case V_107 :
if ( V_5 -> V_10 -> V_96 )
V_5 -> V_10 -> V_96 ( V_5 ) ;
V_5 -> V_103 = 1 ;
if ( V_5 -> V_49 . V_108 )
F_62 ( V_5 -> V_49 . V_108 ) ;
F_63 ( V_5 -> V_23 ) ;
break;
default:
F_49 ( V_5 -> V_23 ,
L_23 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_50 -> V_85 ; V_3 ++ ) {
struct V_59 * V_95 = V_50 -> V_27 [ V_3 ] . V_95 ;
if ( V_50 -> V_27 [ V_3 ] . V_71 -> V_86 )
continue;
if ( V_95 -> V_10 -> V_96 && V_95 -> V_10 -> V_97 )
V_95 -> V_10 -> V_96 ( V_95 ) ;
F_63 ( V_95 -> V_23 ) ;
}
if ( V_50 -> V_109 )
V_50 -> V_109 ( V_50 ) ;
return 0 ;
}
static void F_64 ( struct V_78 * V_79 )
{
struct V_63 * V_50 =
F_65 ( V_79 , struct V_63 , V_110 ) ;
struct V_4 * V_5 ;
int V_3 , V_80 ;
F_49 ( V_50 -> V_23 , L_24 ) ;
F_56 ( V_50 -> V_82 , V_111 ) ;
if ( V_50 -> V_112 )
V_50 -> V_112 ( V_50 ) ;
for ( V_3 = 0 ; V_3 < V_50 -> V_85 ; V_3 ++ ) {
struct V_59 * V_95 = V_50 -> V_27 [ V_3 ] . V_95 ;
if ( V_50 -> V_27 [ V_3 ] . V_71 -> V_86 )
continue;
if ( V_95 -> V_10 -> V_113 && V_95 -> V_10 -> V_97 )
V_95 -> V_10 -> V_113 ( V_95 ) ;
}
F_36 (codec, &card->codec_dev_list, card_list) {
if ( V_5 -> V_103 ) {
if ( V_5 -> V_10 -> V_113 )
V_5 -> V_10 -> V_113 ( V_5 ) ;
V_5 -> V_103 = 0 ;
}
}
for ( V_3 = 0 ; V_3 < V_50 -> V_85 ; V_3 ++ ) {
if ( V_50 -> V_27 [ V_3 ] . V_71 -> V_86 )
continue;
F_59 ( & V_50 -> V_27 [ V_3 ] ,
V_99 ,
V_114 ) ;
F_59 ( & V_50 -> V_27 [ V_3 ] ,
V_101 ,
V_114 ) ;
}
for ( V_3 = 0 ; V_3 < V_50 -> V_85 ; V_3 ++ ) {
if ( V_50 -> V_27 [ V_3 ] . V_71 -> V_86 )
continue;
for ( V_80 = 0 ; V_80 < V_50 -> V_27 [ V_3 ] . V_87 ; V_80 ++ ) {
struct V_59 * V_60 = V_50 -> V_27 [ V_3 ] . V_88 [ V_80 ] ;
struct V_89 * V_90 = V_60 -> V_10 ;
if ( V_90 -> V_91 -> V_92 && V_60 -> V_93 )
V_90 -> V_91 -> V_92 ( V_60 , 0 ) ;
}
}
for ( V_3 = 0 ; V_3 < V_50 -> V_85 ; V_3 ++ ) {
struct V_59 * V_95 = V_50 -> V_27 [ V_3 ] . V_95 ;
if ( V_50 -> V_27 [ V_3 ] . V_71 -> V_86 )
continue;
if ( V_95 -> V_10 -> V_113 && ! V_95 -> V_10 -> V_97 )
V_95 -> V_10 -> V_113 ( V_95 ) ;
}
if ( V_50 -> V_115 )
V_50 -> V_115 ( V_50 ) ;
F_49 ( V_50 -> V_23 , L_25 ) ;
F_56 ( V_50 -> V_82 , V_83 ) ;
F_60 ( V_50 ) ;
F_61 ( & V_50 -> V_102 ) ;
}
int F_66 ( struct V_22 * V_23 )
{
struct V_63 * V_50 = F_7 ( V_23 ) ;
bool V_97 = false ;
int V_3 ;
if ( ! V_50 -> V_81 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_50 -> V_85 ; V_3 ++ ) {
struct V_26 * V_27 = & V_50 -> V_27 [ V_3 ] ;
struct V_59 * * V_88 = V_27 -> V_88 ;
struct V_59 * V_95 = V_27 -> V_95 ;
int V_80 ;
if ( V_95 -> V_116 )
F_67 ( V_95 -> V_23 ) ;
for ( V_80 = 0 ; V_80 < V_27 -> V_87 ; V_80 ++ ) {
struct V_59 * V_117 = V_88 [ V_80 ] ;
if ( V_117 -> V_116 )
F_67 ( V_117 -> V_23 ) ;
}
}
for ( V_3 = 0 ; V_3 < V_50 -> V_85 ; V_3 ++ ) {
struct V_59 * V_95 = V_50 -> V_27 [ V_3 ] . V_95 ;
V_97 |= V_95 -> V_10 -> V_97 ;
}
if ( V_97 ) {
F_49 ( V_23 , L_26 ) ;
F_64 ( & V_50 -> V_110 ) ;
} else {
F_49 ( V_23 , L_27 ) ;
if ( ! F_68 ( & V_50 -> V_110 ) )
F_69 ( V_23 , L_28 ) ;
}
return 0 ;
}
static struct V_48 * F_70 (
const struct V_118 * V_119 , const char * V_53 )
{
struct V_48 * V_49 ;
F_71 ( & V_58 ) ;
F_36 (component, &component_list, list) {
if ( V_119 ) {
if ( V_49 -> V_23 -> V_119 == V_119 )
return V_49 ;
} else if ( strcmp ( V_49 -> V_53 , V_53 ) == 0 ) {
return V_49 ;
}
}
return NULL ;
}
static struct V_59 * F_72 (
const struct V_120 * V_121 )
{
struct V_48 * V_49 ;
struct V_59 * V_60 ;
struct V_118 * V_122 ;
F_71 ( & V_58 ) ;
F_36 (component, &component_list, list) {
V_122 = V_49 -> V_23 -> V_119 ;
if ( ! V_122 && V_49 -> V_23 -> V_123 )
V_122 = V_49 -> V_23 -> V_123 -> V_119 ;
if ( V_121 -> V_119 && V_122 != V_121 -> V_119 )
continue;
if ( V_121 -> V_53 && strcmp ( V_49 -> V_53 , V_121 -> V_53 ) )
continue;
F_36 (dai, &component->dai_list, list) {
if ( V_121 -> V_124 && strcmp ( V_60 -> V_53 , V_121 -> V_124 ) )
continue;
return V_60 ;
}
}
return NULL ;
}
static int F_73 ( struct V_63 * V_50 , int V_125 )
{
struct V_126 * V_71 = & V_50 -> V_71 [ V_125 ] ;
struct V_26 * V_27 = & V_50 -> V_27 [ V_125 ] ;
struct V_120 * V_127 = V_71 -> V_127 ;
struct V_120 V_128 ;
struct V_59 * * V_88 = V_27 -> V_88 ;
struct V_61 * V_62 ;
const char * V_129 ;
int V_3 ;
F_49 ( V_50 -> V_23 , L_29 , V_71 -> V_53 , V_125 ) ;
V_128 . V_53 = V_71 -> V_130 ;
V_128 . V_119 = V_71 -> V_131 ;
V_128 . V_124 = V_71 -> V_132 ;
V_27 -> V_95 = F_72 ( & V_128 ) ;
if ( ! V_27 -> V_95 ) {
F_69 ( V_50 -> V_23 , L_30 ,
V_71 -> V_132 ) ;
return - V_133 ;
}
V_27 -> V_87 = V_71 -> V_87 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_87 ; V_3 ++ ) {
V_88 [ V_3 ] = F_72 ( & V_127 [ V_3 ] ) ;
if ( ! V_88 [ V_3 ] ) {
F_69 ( V_50 -> V_23 , L_31 ,
V_127 [ V_3 ] . V_124 ) ;
return - V_133 ;
}
}
V_27 -> V_117 = V_88 [ 0 ] ;
V_27 -> V_5 = V_27 -> V_117 -> V_5 ;
V_129 = V_71 -> V_129 ;
if ( ! V_129 && ! V_71 -> V_134 )
V_129 = L_32 ;
F_36 (platform, &platform_list, list) {
if ( V_71 -> V_134 ) {
if ( V_62 -> V_23 -> V_119 !=
V_71 -> V_134 )
continue;
} else {
if ( strcmp ( V_62 -> V_49 . V_53 , V_129 ) )
continue;
}
V_27 -> V_62 = V_62 ;
}
if ( ! V_27 -> V_62 ) {
F_69 ( V_50 -> V_23 , L_33 ,
V_71 -> V_129 ) ;
return - V_133 ;
}
V_50 -> V_85 ++ ;
return 0 ;
}
static void F_74 ( struct V_48 * V_49 )
{
if ( ! V_49 -> V_135 )
return;
if ( V_49 -> V_5 )
F_75 ( & V_49 -> V_5 -> V_136 ) ;
if ( V_49 -> remove )
V_49 -> remove ( V_49 ) ;
F_76 ( F_28 ( V_49 ) ) ;
F_29 ( V_49 ) ;
V_49 -> V_135 = 0 ;
F_77 ( V_49 -> V_23 -> V_10 -> V_137 ) ;
}
static void F_78 ( struct V_59 * V_60 , int V_138 )
{
int V_139 ;
if ( V_60 && V_60 -> V_135 &&
V_60 -> V_10 -> V_140 == V_138 ) {
if ( V_60 -> V_10 -> remove ) {
V_139 = V_60 -> V_10 -> remove ( V_60 ) ;
if ( V_139 < 0 )
F_69 ( V_60 -> V_23 ,
L_34 ,
V_60 -> V_53 , V_139 ) ;
}
V_60 -> V_135 = 0 ;
}
}
static void F_79 ( struct V_63 * V_50 , int V_125 , int V_138 )
{
struct V_26 * V_27 = & V_50 -> V_27 [ V_125 ] ;
int V_3 ;
if ( V_27 -> V_141 ) {
F_80 ( V_27 -> V_23 ) ;
V_27 -> V_141 = 0 ;
}
for ( V_3 = 0 ; V_3 < V_27 -> V_87 ; V_3 ++ )
F_78 ( V_27 -> V_88 [ V_3 ] , V_138 ) ;
F_78 ( V_27 -> V_95 , V_138 ) ;
}
static void F_81 ( struct V_63 * V_50 , int V_125 ,
int V_138 )
{
struct V_26 * V_27 = & V_50 -> V_27 [ V_125 ] ;
struct V_59 * V_95 = V_27 -> V_95 ;
struct V_61 * V_62 = V_27 -> V_62 ;
struct V_48 * V_49 ;
int V_3 ;
if ( V_62 && V_62 -> V_49 . V_10 -> V_140 == V_138 )
F_74 ( & V_62 -> V_49 ) ;
for ( V_3 = 0 ; V_3 < V_27 -> V_87 ; V_3 ++ ) {
V_49 = V_27 -> V_88 [ V_3 ] -> V_49 ;
if ( V_49 -> V_10 -> V_140 == V_138 )
F_74 ( V_49 ) ;
}
if ( V_95 ) {
if ( V_95 -> V_49 -> V_10 -> V_140 == V_138 )
F_74 ( V_95 -> V_49 ) ;
}
}
static void F_82 ( struct V_63 * V_50 )
{
int V_60 , V_138 ;
for ( V_138 = V_142 ; V_138 <= V_143 ;
V_138 ++ ) {
for ( V_60 = 0 ; V_60 < V_50 -> V_85 ; V_60 ++ )
F_79 ( V_50 , V_60 , V_138 ) ;
}
for ( V_138 = V_142 ; V_138 <= V_143 ;
V_138 ++ ) {
for ( V_60 = 0 ; V_60 < V_50 -> V_85 ; V_60 ++ )
F_81 ( V_50 , V_60 , V_138 ) ;
}
V_50 -> V_85 = 0 ;
}
static void F_83 ( struct V_63 * V_50 ,
struct V_48 * V_49 )
{
int V_3 ;
if ( V_50 -> V_144 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_50 -> V_145 ; V_3 ++ ) {
struct V_146 * V_147 = & V_50 -> V_144 [ V_3 ] ;
if ( V_147 -> V_119 && V_49 -> V_23 -> V_119 != V_147 -> V_119 )
continue;
if ( V_147 -> V_148 && strcmp ( V_49 -> V_53 , V_147 -> V_148 ) )
continue;
V_49 -> V_149 = V_147 -> V_149 ;
break;
}
}
static int F_84 ( struct V_63 * V_50 ,
struct V_48 * V_49 )
{
struct V_150 * V_102 = F_28 ( V_49 ) ;
struct V_59 * V_60 ;
int V_14 ;
if ( V_49 -> V_135 )
return 0 ;
V_49 -> V_50 = V_50 ;
V_102 -> V_50 = V_50 ;
F_83 ( V_50 , V_49 ) ;
if ( ! F_85 ( V_49 -> V_23 -> V_10 -> V_137 ) )
return - V_151 ;
F_23 ( V_49 ) ;
if ( V_49 -> V_152 ) {
V_14 = F_86 ( V_102 , V_49 -> V_152 ,
V_49 -> V_153 ) ;
if ( V_14 != 0 ) {
F_69 ( V_49 -> V_23 ,
L_35 , V_14 ) ;
goto V_154;
}
}
F_36 (dai, &component->dai_list, list) {
V_14 = F_87 ( V_102 , V_60 ) ;
if ( V_14 != 0 ) {
F_69 ( V_49 -> V_23 ,
L_36 , V_14 ) ;
goto V_154;
}
}
if ( V_49 -> V_155 ) {
V_14 = V_49 -> V_155 ( V_49 ) ;
if ( V_14 < 0 ) {
F_69 ( V_49 -> V_23 ,
L_37 , V_14 ) ;
goto V_154;
}
F_88 ( V_102 -> V_106 &&
V_102 -> V_104 != V_107 ,
L_38 ,
V_49 -> V_53 ) ;
}
if ( V_49 -> V_156 )
F_89 ( V_49 , V_49 -> V_156 ,
V_49 -> V_157 ) ;
if ( V_49 -> V_158 )
F_90 ( V_102 , V_49 -> V_158 ,
V_49 -> V_159 ) ;
V_49 -> V_135 = 1 ;
F_91 ( & V_102 -> V_160 , & V_50 -> V_161 ) ;
if ( V_49 -> V_5 )
F_91 ( & V_49 -> V_5 -> V_136 , & V_50 -> V_162 ) ;
return 0 ;
V_154:
F_29 ( V_49 ) ;
F_77 ( V_49 -> V_23 -> V_10 -> V_137 ) ;
return V_14 ;
}
static void F_92 ( struct V_22 * V_23 )
{
F_16 ( V_23 ) ;
}
static int F_93 ( struct V_26 * V_27 ,
const char * V_53 )
{
int V_14 = 0 ;
V_27 -> V_23 = F_94 ( sizeof( struct V_22 ) , V_40 ) ;
if ( ! V_27 -> V_23 )
return - V_41 ;
F_95 ( V_27 -> V_23 ) ;
V_27 -> V_23 -> V_123 = V_27 -> V_50 -> V_23 ;
V_27 -> V_23 -> V_163 = F_92 ;
V_27 -> V_23 -> V_164 = V_165 ;
F_96 ( V_27 -> V_23 , L_39 , V_53 ) ;
F_97 ( V_27 -> V_23 , V_27 ) ;
F_98 ( & V_27 -> V_166 ) ;
F_99 ( & V_27 -> V_167 [ V_99 ] . V_168 ) ;
F_99 ( & V_27 -> V_167 [ V_101 ] . V_168 ) ;
F_99 ( & V_27 -> V_167 [ V_99 ] . V_169 ) ;
F_99 ( & V_27 -> V_167 [ V_101 ] . V_169 ) ;
V_14 = F_100 ( V_27 -> V_23 ) ;
if ( V_14 < 0 ) {
F_101 ( V_27 -> V_23 ) ;
F_69 ( V_27 -> V_50 -> V_23 ,
L_40 , V_14 ) ;
return V_14 ;
}
V_27 -> V_141 = 1 ;
return 0 ;
}
static int F_102 ( struct V_63 * V_50 , int V_125 ,
int V_138 )
{
struct V_26 * V_27 = & V_50 -> V_27 [ V_125 ] ;
struct V_61 * V_62 = V_27 -> V_62 ;
struct V_48 * V_49 ;
int V_3 , V_14 ;
V_49 = V_27 -> V_95 -> V_49 ;
if ( V_49 -> V_10 -> V_170 == V_138 ) {
V_14 = F_84 ( V_50 , V_49 ) ;
if ( V_14 < 0 )
return V_14 ;
}
for ( V_3 = 0 ; V_3 < V_27 -> V_87 ; V_3 ++ ) {
V_49 = V_27 -> V_88 [ V_3 ] -> V_49 ;
if ( V_49 -> V_10 -> V_170 == V_138 ) {
V_14 = F_84 ( V_50 , V_49 ) ;
if ( V_14 < 0 )
return V_14 ;
}
}
if ( V_62 -> V_49 . V_10 -> V_170 == V_138 ) {
V_14 = F_84 ( V_50 , & V_62 -> V_49 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
static int F_103 ( struct V_59 * V_60 , int V_138 )
{
int V_14 ;
if ( ! V_60 -> V_135 && V_60 -> V_10 -> V_170 == V_138 ) {
if ( V_60 -> V_10 -> V_155 ) {
V_14 = V_60 -> V_10 -> V_155 ( V_60 ) ;
if ( V_14 < 0 ) {
F_69 ( V_60 -> V_23 ,
L_41 ,
V_60 -> V_53 , V_14 ) ;
return V_14 ;
}
}
V_60 -> V_135 = 1 ;
}
return 0 ;
}
static int F_104 ( struct V_63 * V_50 ,
struct V_126 * V_71 ,
struct V_26 * V_27 )
{
struct V_59 * V_95 = V_27 -> V_95 ;
struct V_59 * V_117 = V_27 -> V_117 ;
struct V_171 * V_172 , * V_173 ;
int V_14 ;
if ( V_27 -> V_87 > 1 )
F_26 ( V_50 -> V_23 , L_42 ) ;
V_172 = V_117 -> V_174 ;
V_173 = V_95 -> V_175 ;
if ( V_172 && V_173 ) {
V_14 = F_105 ( V_50 , V_71 -> V_176 ,
V_71 -> V_177 , V_173 ,
V_172 ) ;
if ( V_14 != 0 ) {
F_69 ( V_50 -> V_23 , L_43 ,
V_172 -> V_53 , V_173 -> V_53 , V_14 ) ;
return V_14 ;
}
}
V_172 = V_95 -> V_174 ;
V_173 = V_117 -> V_175 ;
if ( V_172 && V_173 ) {
V_14 = F_105 ( V_50 , V_71 -> V_176 ,
V_71 -> V_177 , V_173 ,
V_172 ) ;
if ( V_14 != 0 ) {
F_69 ( V_50 -> V_23 , L_43 ,
V_172 -> V_53 , V_173 -> V_53 , V_14 ) ;
return V_14 ;
}
}
return 0 ;
}
static int F_106 ( struct V_63 * V_50 , int V_125 , int V_138 )
{
struct V_126 * V_71 = & V_50 -> V_71 [ V_125 ] ;
struct V_26 * V_27 = & V_50 -> V_27 [ V_125 ] ;
struct V_59 * V_95 = V_27 -> V_95 ;
int V_3 , V_14 ;
F_49 ( V_50 -> V_23 , L_44 ,
V_50 -> V_53 , V_125 , V_138 ) ;
V_27 -> V_29 = V_29 ;
V_14 = F_103 ( V_95 , V_138 ) ;
if ( V_14 )
return V_14 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_87 ; V_3 ++ ) {
V_14 = F_103 ( V_27 -> V_88 [ V_3 ] , V_138 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_138 != V_143 )
return 0 ;
if ( V_71 -> V_178 ) {
V_14 = V_71 -> V_178 ( V_27 ) ;
if ( V_14 < 0 ) {
F_69 ( V_50 -> V_23 , L_45 ,
V_71 -> V_53 , V_14 ) ;
return V_14 ;
}
}
if ( V_71 -> V_179 )
F_107 ( V_27 , V_71 -> V_179 ) ;
V_14 = F_93 ( V_27 , V_71 -> V_53 ) ;
if ( V_14 )
return V_14 ;
#ifdef F_108
if ( V_71 -> V_180 )
F_109 ( V_27 ) ;
#endif
if ( V_95 -> V_10 -> V_181 ) {
V_14 = F_110 ( V_27 , V_125 ) ;
if ( V_14 < 0 ) {
F_69 ( V_50 -> V_23 , L_46 ,
V_71 -> V_182 ) ;
return V_14 ;
}
} else {
if ( ! V_71 -> V_176 ) {
V_14 = F_111 ( V_27 , V_125 ) ;
if ( V_14 < 0 ) {
F_69 ( V_50 -> V_23 , L_47 ,
V_71 -> V_182 , V_14 ) ;
return V_14 ;
}
} else {
F_112 ( & V_27 -> V_98 ,
F_51 ) ;
V_14 = F_104 ( V_50 , V_71 , V_27 ) ;
if ( V_14 )
return V_14 ;
}
}
return 0 ;
}
static int F_113 ( struct V_63 * V_50 , int V_125 )
{
struct V_26 * V_27 = & V_50 -> V_183 [ V_125 ] ;
struct V_184 * V_185 = & V_50 -> V_185 [ V_125 ] ;
const char * V_53 = V_185 -> V_186 ;
V_27 -> V_49 = F_70 ( V_185 -> V_187 , V_53 ) ;
if ( ! V_27 -> V_49 ) {
if ( V_185 -> V_187 )
V_53 = F_114 ( V_185 -> V_187 ) ;
F_69 ( V_50 -> V_23 , L_48 , V_53 ) ;
return - V_133 ;
}
V_27 -> V_5 = V_27 -> V_49 -> V_5 ;
return 0 ;
}
static int F_115 ( struct V_63 * V_50 , int V_125 )
{
struct V_26 * V_27 = & V_50 -> V_183 [ V_125 ] ;
struct V_184 * V_185 = & V_50 -> V_185 [ V_125 ] ;
int V_14 ;
V_14 = F_84 ( V_50 , V_27 -> V_49 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_185 -> V_178 ) {
V_14 = V_185 -> V_178 ( V_27 -> V_49 ) ;
if ( V_14 < 0 ) {
F_69 ( V_50 -> V_23 , L_45 ,
V_185 -> V_53 , V_14 ) ;
return V_14 ;
}
}
return F_93 ( V_27 , V_185 -> V_53 ) ;
}
static void F_116 ( struct V_63 * V_50 , int V_125 )
{
struct V_26 * V_27 = & V_50 -> V_183 [ V_125 ] ;
struct V_48 * V_49 = V_27 -> V_49 ;
if ( V_27 -> V_141 ) {
F_80 ( V_27 -> V_23 ) ;
V_27 -> V_141 = 0 ;
}
if ( V_49 && V_49 -> V_135 )
F_74 ( V_49 ) ;
}
static int F_117 ( struct V_4 * V_5 )
{
int V_14 ;
if ( V_5 -> V_188 )
return 0 ;
V_14 = F_118 ( V_5 ) ;
if ( V_14 < 0 ) {
F_69 ( V_5 -> V_23 ,
L_49 ,
V_14 ) ;
return V_14 ;
}
V_5 -> V_188 = 1 ;
return 0 ;
}
int F_107 ( struct V_26 * V_27 ,
unsigned int V_179 )
{
struct V_59 * * V_88 = V_27 -> V_88 ;
struct V_59 * V_95 = V_27 -> V_95 ;
unsigned int V_3 ;
int V_14 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_87 ; V_3 ++ ) {
struct V_59 * V_117 = V_88 [ V_3 ] ;
V_14 = F_119 ( V_117 , V_179 ) ;
if ( V_14 != 0 && V_14 != - V_189 ) {
F_26 ( V_117 -> V_23 ,
L_50 , V_14 ) ;
return V_14 ;
}
}
if ( V_95 -> V_5 ) {
unsigned int V_190 ;
V_190 = V_179 & ~ V_191 ;
switch ( V_179 & V_191 ) {
case V_192 :
V_190 |= V_193 ;
break;
case V_194 :
V_190 |= V_195 ;
break;
case V_195 :
V_190 |= V_194 ;
break;
case V_193 :
V_190 |= V_192 ;
break;
}
V_179 = V_190 ;
}
V_14 = F_119 ( V_95 , V_179 ) ;
if ( V_14 != 0 && V_14 != - V_189 ) {
F_26 ( V_95 -> V_23 ,
L_50 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_120 ( struct V_63 * V_50 )
{
struct V_4 * V_5 ;
int V_14 , V_3 , V_138 ;
F_35 ( & V_58 ) ;
F_121 ( & V_50 -> V_196 , V_197 ) ;
for ( V_3 = 0 ; V_3 < V_50 -> V_73 ; V_3 ++ ) {
V_14 = F_73 ( V_50 , V_3 ) ;
if ( V_14 != 0 )
goto V_198;
}
for ( V_3 = 0 ; V_3 < V_50 -> V_199 ; V_3 ++ ) {
V_14 = F_113 ( V_50 , V_3 ) ;
if ( V_14 != 0 )
goto V_198;
}
F_36 (codec, &codec_list, list) {
if ( V_5 -> V_188 )
continue;
V_14 = F_117 ( V_5 ) ;
if ( V_14 < 0 )
goto V_198;
}
V_14 = F_122 ( V_50 -> V_23 , V_200 , V_201 ,
V_50 -> V_137 , 0 , & V_50 -> V_82 ) ;
if ( V_14 < 0 ) {
F_69 ( V_50 -> V_23 ,
L_51 ,
V_50 -> V_53 , V_14 ) ;
goto V_198;
}
F_41 ( V_50 ) ;
V_50 -> V_102 . V_104 = V_107 ;
V_50 -> V_102 . V_23 = V_50 -> V_23 ;
V_50 -> V_102 . V_50 = V_50 ;
F_91 ( & V_50 -> V_102 . V_160 , & V_50 -> V_161 ) ;
#ifdef F_108
F_27 ( & V_50 -> V_102 , V_50 -> V_51 ) ;
#endif
#ifdef F_123
F_124 ( & V_50 -> V_110 , F_64 ) ;
#endif
if ( V_50 -> V_152 )
F_86 ( & V_50 -> V_102 , V_50 -> V_152 ,
V_50 -> V_153 ) ;
if ( V_50 -> V_202 )
F_86 ( & V_50 -> V_102 , V_50 -> V_202 ,
V_50 -> V_203 ) ;
if ( V_50 -> V_155 ) {
V_14 = V_50 -> V_155 ( V_50 ) ;
if ( V_14 < 0 )
goto V_204;
}
for ( V_138 = V_142 ; V_138 <= V_143 ;
V_138 ++ ) {
for ( V_3 = 0 ; V_3 < V_50 -> V_73 ; V_3 ++ ) {
V_14 = F_102 ( V_50 , V_3 , V_138 ) ;
if ( V_14 < 0 ) {
F_69 ( V_50 -> V_23 ,
L_52 ,
V_14 ) ;
goto V_205;
}
}
}
for ( V_138 = V_142 ; V_138 <= V_143 ;
V_138 ++ ) {
for ( V_3 = 0 ; V_3 < V_50 -> V_73 ; V_3 ++ ) {
V_14 = F_106 ( V_50 , V_3 , V_138 ) ;
if ( V_14 < 0 ) {
F_69 ( V_50 -> V_23 ,
L_52 ,
V_14 ) ;
goto V_205;
}
}
}
for ( V_3 = 0 ; V_3 < V_50 -> V_199 ; V_3 ++ ) {
V_14 = F_115 ( V_50 , V_3 ) ;
if ( V_14 < 0 ) {
F_69 ( V_50 -> V_23 ,
L_53 ,
V_14 ) ;
goto V_206;
}
}
F_125 ( V_50 ) ;
F_126 ( V_50 ) ;
if ( V_50 -> V_156 )
F_127 ( V_50 , V_50 -> V_156 , V_50 -> V_157 ) ;
if ( V_50 -> V_158 )
F_90 ( & V_50 -> V_102 , V_50 -> V_158 ,
V_50 -> V_159 ) ;
if ( V_50 -> V_207 )
F_90 ( & V_50 -> V_102 , V_50 -> V_207 ,
V_50 -> V_208 ) ;
snprintf ( V_50 -> V_82 -> V_209 , sizeof( V_50 -> V_82 -> V_209 ) ,
L_39 , V_50 -> V_53 ) ;
snprintf ( V_50 -> V_82 -> V_210 , sizeof( V_50 -> V_82 -> V_210 ) ,
L_39 , V_50 -> V_211 ? V_50 -> V_211 : V_50 -> V_53 ) ;
snprintf ( V_50 -> V_82 -> V_10 , sizeof( V_50 -> V_82 -> V_10 ) ,
L_39 , V_50 -> V_212 ? V_50 -> V_212 : V_50 -> V_53 ) ;
for ( V_3 = 0 ; V_3 < F_128 ( V_50 -> V_82 -> V_10 ) ; V_3 ++ ) {
switch ( V_50 -> V_82 -> V_10 [ V_3 ] ) {
case '_' :
case '-' :
case '\0' :
break;
default:
if ( ! isalnum ( V_50 -> V_82 -> V_10 [ V_3 ] ) )
V_50 -> V_82 -> V_10 [ V_3 ] = '_' ;
break;
}
}
if ( V_50 -> V_213 ) {
V_14 = V_50 -> V_213 ( V_50 ) ;
if ( V_14 < 0 ) {
F_69 ( V_50 -> V_23 , L_54 ,
V_50 -> V_53 , V_14 ) ;
goto V_206;
}
}
F_129 ( V_50 ) ;
V_14 = F_130 ( V_50 -> V_82 ) ;
if ( V_14 < 0 ) {
F_69 ( V_50 -> V_23 , L_55 ,
V_14 ) ;
goto V_206;
}
V_50 -> V_81 = 1 ;
F_61 ( & V_50 -> V_102 ) ;
F_37 ( & V_50 -> V_196 ) ;
F_37 ( & V_58 ) ;
return 0 ;
V_206:
for ( V_3 = 0 ; V_3 < V_50 -> V_199 ; V_3 ++ )
F_116 ( V_50 , V_3 ) ;
V_205:
F_82 ( V_50 ) ;
V_204:
if ( V_50 -> remove )
V_50 -> remove ( V_50 ) ;
F_76 ( & V_50 -> V_102 ) ;
F_43 ( V_50 ) ;
F_131 ( V_50 -> V_82 ) ;
V_198:
F_37 ( & V_50 -> V_196 ) ;
F_37 ( & V_58 ) ;
return V_14 ;
}
static int F_132 ( struct V_214 * V_215 )
{
struct V_63 * V_50 = F_133 ( V_215 ) ;
if ( ! V_50 )
return - V_15 ;
F_26 ( & V_215 -> V_23 ,
L_56 ,
V_50 -> V_53 ) ;
V_50 -> V_23 = & V_215 -> V_23 ;
return F_134 ( V_50 ) ;
}
static int F_135 ( struct V_63 * V_50 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_50 -> V_85 ; V_3 ++ ) {
struct V_26 * V_27 = & V_50 -> V_27 [ V_3 ] ;
F_58 ( & V_27 -> V_98 ) ;
}
for ( V_3 = 0 ; V_3 < V_50 -> V_199 ; V_3 ++ )
F_116 ( V_50 , V_3 ) ;
F_82 ( V_50 ) ;
F_43 ( V_50 ) ;
if ( V_50 -> remove )
V_50 -> remove ( V_50 ) ;
F_76 ( & V_50 -> V_102 ) ;
F_131 ( V_50 -> V_82 ) ;
return 0 ;
}
static int F_136 ( struct V_214 * V_215 )
{
struct V_63 * V_50 = F_133 ( V_215 ) ;
F_137 ( V_50 ) ;
return 0 ;
}
int F_138 ( struct V_22 * V_23 )
{
struct V_63 * V_50 = F_7 ( V_23 ) ;
int V_3 ;
if ( ! V_50 -> V_81 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_50 -> V_85 ; V_3 ++ ) {
struct V_26 * V_27 = & V_50 -> V_27 [ V_3 ] ;
F_58 ( & V_27 -> V_98 ) ;
}
F_139 ( V_50 ) ;
for ( V_3 = 0 ; V_3 < V_50 -> V_85 ; V_3 ++ ) {
struct V_26 * V_27 = & V_50 -> V_27 [ V_3 ] ;
struct V_59 * V_95 = V_27 -> V_95 ;
int V_80 ;
F_63 ( V_95 -> V_23 ) ;
for ( V_80 = 0 ; V_80 < V_27 -> V_87 ; V_80 ++ ) {
struct V_59 * V_117 = V_27 -> V_88 [ V_80 ] ;
F_63 ( V_117 -> V_23 ) ;
}
}
return 0 ;
}
struct V_216 * F_140 ( const struct V_217 * V_218 ,
void * V_219 , const char * V_211 ,
const char * V_220 )
{
struct V_217 V_221 ;
struct V_216 * V_222 ;
char * V_53 = NULL ;
memcpy ( & V_221 , V_218 , sizeof( V_221 ) ) ;
V_221 . V_223 = 0 ;
if ( ! V_211 )
V_211 = V_221 . V_53 ;
if ( V_220 ) {
V_53 = F_24 ( V_40 , L_57 , V_220 , V_211 ) ;
if ( ! V_53 )
return NULL ;
V_221 . V_53 = V_53 ;
} else {
V_221 . V_53 = V_211 ;
}
V_222 = F_141 ( & V_221 , V_219 ) ;
F_16 ( V_53 ) ;
return V_222 ;
}
static int F_142 ( struct V_82 * V_50 , struct V_22 * V_23 ,
const struct V_217 * V_156 , int V_157 ,
const char * V_220 , void * V_219 )
{
int V_139 , V_3 ;
for ( V_3 = 0 ; V_3 < V_157 ; V_3 ++ ) {
const struct V_217 * V_224 = & V_156 [ V_3 ] ;
V_139 = F_143 ( V_50 , F_140 ( V_224 , V_219 ,
V_224 -> V_53 , V_220 ) ) ;
if ( V_139 < 0 ) {
F_69 ( V_23 , L_58 ,
V_224 -> V_53 , V_139 ) ;
return V_139 ;
}
}
return 0 ;
}
struct V_216 * F_144 ( struct V_63 * V_225 ,
const char * V_53 )
{
struct V_82 * V_50 = V_225 -> V_82 ;
struct V_216 * V_226 ;
if ( F_145 ( ! V_53 ) )
return NULL ;
F_36 (kctl, &card->controls, list)
if ( ! strncmp ( V_226 -> V_227 . V_53 , V_53 , sizeof( V_226 -> V_227 . V_53 ) ) )
return V_226 ;
return NULL ;
}
int F_89 ( struct V_48 * V_49 ,
const struct V_217 * V_156 , unsigned int V_157 )
{
struct V_82 * V_50 = V_49 -> V_50 -> V_82 ;
return F_142 ( V_50 , V_49 -> V_23 , V_156 ,
V_157 , V_49 -> V_149 , V_49 ) ;
}
int F_146 ( struct V_4 * V_5 ,
const struct V_217 * V_156 , unsigned int V_157 )
{
return F_89 ( & V_5 -> V_49 , V_156 ,
V_157 ) ;
}
int F_147 ( struct V_61 * V_62 ,
const struct V_217 * V_156 , unsigned int V_157 )
{
return F_89 ( & V_62 -> V_49 , V_156 ,
V_157 ) ;
}
int F_127 ( struct V_63 * V_225 ,
const struct V_217 * V_156 , int V_157 )
{
struct V_82 * V_50 = V_225 -> V_82 ;
return F_142 ( V_50 , V_225 -> V_23 , V_156 , V_157 ,
NULL , V_225 ) ;
}
int F_148 ( struct V_59 * V_60 ,
const struct V_217 * V_156 , int V_157 )
{
struct V_82 * V_50 = V_60 -> V_49 -> V_50 -> V_82 ;
return F_142 ( V_50 , V_60 -> V_23 , V_156 , V_157 ,
NULL , V_60 ) ;
}
int F_149 ( struct V_59 * V_60 , int V_228 ,
unsigned int V_229 , int V_230 )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_91 -> V_231 )
return V_60 -> V_10 -> V_91 -> V_231 ( V_60 , V_228 , V_229 , V_230 ) ;
else if ( V_60 -> V_5 && V_60 -> V_5 -> V_10 -> V_231 )
return V_60 -> V_5 -> V_10 -> V_231 ( V_60 -> V_5 , V_228 , 0 ,
V_229 , V_230 ) ;
else
return - V_189 ;
}
int F_150 ( struct V_4 * V_5 , int V_228 ,
int V_232 , unsigned int V_229 , int V_230 )
{
if ( V_5 -> V_10 -> V_231 )
return V_5 -> V_10 -> V_231 ( V_5 , V_228 , V_232 ,
V_229 , V_230 ) ;
else
return - V_189 ;
}
int F_151 ( struct V_59 * V_60 ,
int V_233 , int div )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_91 -> V_234 )
return V_60 -> V_10 -> V_91 -> V_234 ( V_60 , V_233 , div ) ;
else
return - V_15 ;
}
int F_152 ( struct V_59 * V_60 , int V_235 , int V_232 ,
unsigned int V_236 , unsigned int V_237 )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_91 -> V_238 )
return V_60 -> V_10 -> V_91 -> V_238 ( V_60 , V_235 , V_232 ,
V_236 , V_237 ) ;
else if ( V_60 -> V_5 && V_60 -> V_5 -> V_10 -> V_238 )
return V_60 -> V_5 -> V_10 -> V_238 ( V_60 -> V_5 , V_235 , V_232 ,
V_236 , V_237 ) ;
else
return - V_15 ;
}
int F_153 ( struct V_4 * V_5 , int V_235 , int V_232 ,
unsigned int V_236 , unsigned int V_237 )
{
if ( V_5 -> V_10 -> V_238 )
return V_5 -> V_10 -> V_238 ( V_5 , V_235 , V_232 ,
V_236 , V_237 ) ;
else
return - V_15 ;
}
int F_154 ( struct V_59 * V_60 , unsigned int V_239 )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_91 -> V_240 )
return V_60 -> V_10 -> V_91 -> V_240 ( V_60 , V_239 ) ;
else
return - V_15 ;
}
int F_119 ( struct V_59 * V_60 , unsigned int V_241 )
{
if ( V_60 -> V_10 == NULL )
return - V_15 ;
if ( V_60 -> V_10 -> V_91 -> V_242 == NULL )
return - V_189 ;
return V_60 -> V_10 -> V_91 -> V_242 ( V_60 , V_241 ) ;
}
static int F_155 ( unsigned int V_243 ,
unsigned int * V_244 ,
unsigned int * V_245 )
{
if ( * V_244 || * V_245 )
return 0 ;
if ( ! V_243 )
return - V_15 ;
* V_244 = ( 1 << V_243 ) - 1 ;
* V_245 = ( 1 << V_243 ) - 1 ;
return 0 ;
}
int F_156 ( struct V_59 * V_60 ,
unsigned int V_244 , unsigned int V_245 , int V_243 , int V_246 )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_91 -> V_247 )
V_60 -> V_10 -> V_91 -> V_247 ( V_243 ,
& V_244 , & V_245 ) ;
else
F_155 ( V_243 , & V_244 , & V_245 ) ;
V_60 -> V_244 = V_244 ;
V_60 -> V_245 = V_245 ;
if ( V_60 -> V_10 && V_60 -> V_10 -> V_91 -> V_248 )
return V_60 -> V_10 -> V_91 -> V_248 ( V_60 , V_244 , V_245 ,
V_243 , V_246 ) ;
else
return - V_189 ;
}
int F_157 ( struct V_59 * V_60 ,
unsigned int V_249 , unsigned int * V_250 ,
unsigned int V_251 , unsigned int * V_252 )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_91 -> V_253 )
return V_60 -> V_10 -> V_91 -> V_253 ( V_60 , V_249 , V_250 ,
V_251 , V_252 ) ;
else
return - V_15 ;
}
int F_158 ( struct V_59 * V_60 , int V_254 )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_91 -> V_255 )
return V_60 -> V_10 -> V_91 -> V_255 ( V_60 , V_254 ) ;
else
return - V_15 ;
}
int F_159 ( struct V_59 * V_60 , int V_256 ,
int V_257 )
{
if ( ! V_60 -> V_10 )
return - V_189 ;
if ( V_60 -> V_10 -> V_91 -> V_258 )
return V_60 -> V_10 -> V_91 -> V_258 ( V_60 , V_256 , V_257 ) ;
else if ( V_257 == V_99 &&
V_60 -> V_10 -> V_91 -> V_92 )
return V_60 -> V_10 -> V_91 -> V_92 ( V_60 , V_256 ) ;
else
return - V_189 ;
}
static int F_160 ( struct V_63 * V_50 ,
struct V_126 * V_71 )
{
if ( V_71 -> V_186 || V_71 -> V_187 ||
V_71 -> V_259 ) {
V_71 -> V_87 = 1 ;
V_71 -> V_127 = F_161 ( V_50 -> V_23 ,
sizeof( struct V_120 ) ,
V_40 ) ;
if ( ! V_71 -> V_127 )
return - V_41 ;
V_71 -> V_127 [ 0 ] . V_53 = V_71 -> V_186 ;
V_71 -> V_127 [ 0 ] . V_119 = V_71 -> V_187 ;
V_71 -> V_127 [ 0 ] . V_124 = V_71 -> V_259 ;
}
if ( ! V_71 -> V_127 ) {
F_69 ( V_50 -> V_23 , L_59 ) ;
return - V_15 ;
}
return 0 ;
}
int F_134 ( struct V_63 * V_50 )
{
int V_3 , V_80 , V_14 ;
if ( ! V_50 -> V_53 || ! V_50 -> V_23 )
return - V_15 ;
for ( V_3 = 0 ; V_3 < V_50 -> V_73 ; V_3 ++ ) {
struct V_126 * V_260 = & V_50 -> V_71 [ V_3 ] ;
V_14 = F_160 ( V_50 , V_260 ) ;
if ( V_14 ) {
F_69 ( V_50 -> V_23 , L_60 ) ;
return V_14 ;
}
for ( V_80 = 0 ; V_80 < V_260 -> V_87 ; V_80 ++ ) {
if ( ! ! V_260 -> V_127 [ V_80 ] . V_53 ==
! ! V_260 -> V_127 [ V_80 ] . V_119 ) {
F_69 ( V_50 -> V_23 , L_61 ,
V_260 -> V_53 ) ;
return - V_15 ;
}
if ( ! V_260 -> V_127 [ V_80 ] . V_124 ) {
F_69 ( V_50 -> V_23 , L_62 ,
V_260 -> V_53 ) ;
return - V_15 ;
}
}
if ( V_260 -> V_129 && V_260 -> V_134 ) {
F_69 ( V_50 -> V_23 ,
L_63 ,
V_260 -> V_53 ) ;
return - V_15 ;
}
if ( V_260 -> V_130 && V_260 -> V_131 ) {
F_69 ( V_50 -> V_23 ,
L_64 ,
V_260 -> V_53 ) ;
return - V_15 ;
}
if ( ! V_260 -> V_132 &&
! ( V_260 -> V_130 || V_260 -> V_131 ) ) {
F_69 ( V_50 -> V_23 ,
L_65 ,
V_260 -> V_53 ) ;
return - V_15 ;
}
}
F_97 ( V_50 -> V_23 , V_50 ) ;
F_162 ( V_50 ) ;
V_50 -> V_27 = F_161 ( V_50 -> V_23 ,
sizeof( struct V_26 ) *
( V_50 -> V_73 + V_50 -> V_199 ) ,
V_40 ) ;
if ( V_50 -> V_27 == NULL )
return - V_41 ;
V_50 -> V_85 = 0 ;
V_50 -> V_183 = & V_50 -> V_27 [ V_50 -> V_73 ] ;
for ( V_3 = 0 ; V_3 < V_50 -> V_73 ; V_3 ++ ) {
V_50 -> V_27 [ V_3 ] . V_50 = V_50 ;
V_50 -> V_27 [ V_3 ] . V_71 = & V_50 -> V_71 [ V_3 ] ;
V_50 -> V_27 [ V_3 ] . V_88 = F_161 ( V_50 -> V_23 ,
sizeof( struct V_59 * ) *
( V_50 -> V_27 [ V_3 ] . V_71 -> V_87 ) ,
V_40 ) ;
if ( V_50 -> V_27 [ V_3 ] . V_88 == NULL )
return - V_41 ;
}
for ( V_3 = 0 ; V_3 < V_50 -> V_199 ; V_3 ++ )
V_50 -> V_183 [ V_3 ] . V_50 = V_50 ;
F_99 ( & V_50 -> V_261 ) ;
F_99 ( & V_50 -> V_262 ) ;
V_50 -> V_81 = 0 ;
F_98 ( & V_50 -> V_196 ) ;
F_98 ( & V_50 -> V_263 ) ;
V_14 = F_120 ( V_50 ) ;
if ( V_14 != 0 )
return V_14 ;
for ( V_3 = 0 ; V_3 < V_50 -> V_85 ; V_3 ++ ) {
struct V_26 * V_27 = & V_50 -> V_27 [ V_3 ] ;
struct V_59 * V_95 = V_27 -> V_95 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < V_27 -> V_87 ; V_80 ++ ) {
struct V_59 * V_117 = V_27 -> V_88 [ V_80 ] ;
if ( ! V_117 -> V_116 )
F_63 ( V_117 -> V_23 ) ;
}
if ( ! V_95 -> V_116 )
F_63 ( V_95 -> V_23 ) ;
}
return V_14 ;
}
int F_137 ( struct V_63 * V_50 )
{
if ( V_50 -> V_81 ) {
V_50 -> V_81 = false ;
F_139 ( V_50 ) ;
F_135 ( V_50 ) ;
F_49 ( V_50 -> V_23 , L_66 , V_50 -> V_53 ) ;
}
return 0 ;
}
static char * F_163 ( struct V_22 * V_23 , int * V_227 )
{
char * V_264 , V_53 [ V_265 ] ;
int V_266 , V_267 ;
if ( V_148 ( V_23 ) == NULL )
return NULL ;
F_164 ( V_53 , V_148 ( V_23 ) , V_265 ) ;
V_264 = strstr ( V_53 , V_23 -> V_10 -> V_53 ) ;
if ( V_264 ) {
if ( sscanf ( & V_264 [ strlen ( V_23 -> V_10 -> V_53 ) ] , L_67 , V_227 ) == 1 ) {
if ( * V_227 == - 1 )
V_264 [ strlen ( V_23 -> V_10 -> V_53 ) ] = '\0' ;
}
} else {
if ( sscanf ( V_53 , L_68 , & V_266 , & V_267 ) == 2 ) {
char V_268 [ V_265 ] ;
* V_227 = ( ( V_266 & 0xffff ) << 16 ) + V_267 ;
snprintf ( V_268 , V_265 , L_69 , V_23 -> V_10 -> V_53 , V_53 ) ;
F_164 ( V_53 , V_268 , V_265 ) ;
} else
* V_227 = 0 ;
}
return F_165 ( V_53 , V_40 ) ;
}
static inline char * F_166 ( struct V_22 * V_23 ,
struct V_89 * V_269 )
{
if ( V_269 -> V_53 == NULL ) {
F_69 ( V_23 ,
L_70 ,
V_148 ( V_23 ) ) ;
return NULL ;
}
return F_165 ( V_269 -> V_53 , V_40 ) ;
}
static void F_167 ( struct V_48 * V_49 )
{
struct V_59 * V_60 , * V_270 ;
F_168 (dai, _dai, &component->dai_list, list) {
F_49 ( V_49 -> V_23 , L_71 ,
V_60 -> V_53 ) ;
F_75 ( & V_60 -> V_160 ) ;
F_16 ( V_60 -> V_53 ) ;
F_16 ( V_60 ) ;
}
}
static int F_169 ( struct V_48 * V_49 ,
struct V_89 * V_269 , T_1 V_16 ,
bool V_271 )
{
struct V_22 * V_23 = V_49 -> V_23 ;
struct V_59 * V_60 ;
unsigned int V_3 ;
int V_14 ;
F_49 ( V_23 , L_72 , V_148 ( V_23 ) , V_16 ) ;
V_49 -> V_269 = V_269 ;
V_49 -> V_272 = V_16 ;
for ( V_3 = 0 ; V_3 < V_16 ; V_3 ++ ) {
V_60 = F_94 ( sizeof( struct V_59 ) , V_40 ) ;
if ( V_60 == NULL ) {
V_14 = - V_41 ;
goto V_139;
}
if ( V_16 == 1 && V_271 &&
( V_269 [ V_3 ] . V_227 == 0 || V_269 [ V_3 ] . V_53 == NULL ) ) {
V_60 -> V_53 = F_163 ( V_23 , & V_60 -> V_227 ) ;
} else {
V_60 -> V_53 = F_166 ( V_23 , & V_269 [ V_3 ] ) ;
if ( V_269 [ V_3 ] . V_227 )
V_60 -> V_227 = V_269 [ V_3 ] . V_227 ;
else
V_60 -> V_227 = V_3 ;
}
if ( V_60 -> V_53 == NULL ) {
F_16 ( V_60 ) ;
V_14 = - V_41 ;
goto V_139;
}
V_60 -> V_49 = V_49 ;
V_60 -> V_23 = V_23 ;
V_60 -> V_10 = & V_269 [ V_3 ] ;
if ( ! V_60 -> V_10 -> V_91 )
V_60 -> V_10 -> V_91 = & V_273 ;
F_91 ( & V_60 -> V_160 , & V_49 -> V_274 ) ;
F_49 ( V_23 , L_73 , V_60 -> V_53 ) ;
}
return 0 ;
V_139:
F_167 ( V_49 ) ;
return V_14 ;
}
static void F_170 ( struct V_150 * V_102 ,
enum V_275 type , int V_276 )
{
struct V_48 * V_49 = V_102 -> V_49 ;
V_49 -> V_10 -> V_277 ( V_49 , type , V_276 ) ;
}
static int F_171 ( struct V_150 * V_102 ,
int V_278 )
{
struct V_48 * V_49 = V_102 -> V_49 ;
return V_49 -> V_10 -> V_279 ( V_49 , V_278 ) ;
}
static int F_172 ( struct V_48 * V_49 ,
const struct V_280 * V_10 , struct V_22 * V_23 )
{
struct V_150 * V_102 ;
V_49 -> V_53 = F_163 ( V_23 , & V_49 -> V_227 ) ;
if ( ! V_49 -> V_53 ) {
F_69 ( V_23 , L_74 ) ;
return - V_41 ;
}
V_49 -> V_23 = V_23 ;
V_49 -> V_10 = V_10 ;
V_49 -> V_155 = V_49 -> V_10 -> V_155 ;
V_49 -> remove = V_49 -> V_10 -> remove ;
if ( ! V_49 -> V_281 )
V_49 -> V_281 = & V_49 -> V_102 ;
V_102 = V_49 -> V_281 ;
V_102 -> V_23 = V_23 ;
V_102 -> V_49 = V_49 ;
V_102 -> V_104 = V_107 ;
V_102 -> V_106 = true ;
if ( V_10 -> V_277 )
V_102 -> V_277 = F_170 ;
if ( V_10 -> V_279 )
V_102 -> V_279 = F_171 ;
V_49 -> V_156 = V_10 -> V_156 ;
V_49 -> V_157 = V_10 -> V_157 ;
V_49 -> V_152 = V_10 -> V_152 ;
V_49 -> V_153 = V_10 -> V_153 ;
V_49 -> V_158 = V_10 -> V_158 ;
V_49 -> V_159 = V_10 -> V_159 ;
F_99 ( & V_49 -> V_274 ) ;
F_98 ( & V_49 -> V_282 ) ;
return 0 ;
}
static void F_173 ( struct V_48 * V_49 )
{
int V_283 = F_174 ( V_49 -> V_108 ) ;
if ( V_283 > 0 )
V_49 -> V_283 = V_283 ;
}
void F_175 ( struct V_48 * V_49 ,
struct V_108 * V_108 )
{
V_49 -> V_108 = V_108 ;
F_173 ( V_49 ) ;
}
void F_176 ( struct V_48 * V_49 )
{
F_177 ( V_49 -> V_108 ) ;
V_49 -> V_108 = NULL ;
}
static void F_178 ( struct V_48 * V_49 )
{
if ( ! V_49 -> V_284 && ! V_49 -> V_285 ) {
if ( ! V_49 -> V_108 )
V_49 -> V_108 = F_179 ( V_49 -> V_23 , NULL ) ;
if ( V_49 -> V_108 )
F_173 ( V_49 ) ;
}
F_91 ( & V_49 -> V_160 , & V_286 ) ;
F_99 ( & V_49 -> V_262 ) ;
}
static void F_180 ( struct V_48 * V_49 )
{
F_35 ( & V_58 ) ;
F_178 ( V_49 ) ;
F_37 ( & V_58 ) ;
}
static void F_181 ( struct V_48 * V_49 )
{
F_167 ( V_49 ) ;
F_16 ( V_49 -> V_53 ) ;
}
static void F_182 ( struct V_48 * V_49 )
{
F_75 ( & V_49 -> V_160 ) ;
}
int F_183 ( struct V_22 * V_23 ,
const struct V_280 * V_287 ,
struct V_89 * V_269 ,
int V_272 )
{
struct V_48 * V_288 ;
int V_14 ;
V_288 = F_94 ( sizeof( * V_288 ) , V_40 ) ;
if ( ! V_288 ) {
F_69 ( V_23 , L_75 ) ;
return - V_41 ;
}
V_14 = F_172 ( V_288 , V_287 , V_23 ) ;
if ( V_14 )
goto V_289;
V_288 -> V_290 = true ;
V_288 -> V_291 = true ;
V_14 = F_169 ( V_288 , V_269 , V_272 , true ) ;
if ( V_14 < 0 ) {
F_69 ( V_23 , L_76 , V_14 ) ;
goto V_292;
}
F_180 ( V_288 ) ;
return 0 ;
V_292:
F_181 ( V_288 ) ;
V_289:
F_16 ( V_288 ) ;
return V_14 ;
}
void F_184 ( struct V_22 * V_23 )
{
struct V_48 * V_288 ;
F_35 ( & V_58 ) ;
F_36 (cmpnt, &component_list, list) {
if ( V_23 == V_288 -> V_23 && V_288 -> V_291 )
goto V_264;
}
F_37 ( & V_58 ) ;
return;
V_264:
F_185 ( V_288 , V_293 ) ;
F_182 ( V_288 ) ;
F_37 ( & V_58 ) ;
F_181 ( V_288 ) ;
F_16 ( V_288 ) ;
}
static int F_186 ( struct V_48 * V_49 )
{
struct V_61 * V_62 = F_187 ( V_49 ) ;
return V_62 -> V_10 -> V_155 ( V_62 ) ;
}
static void F_188 ( struct V_48 * V_49 )
{
struct V_61 * V_62 = F_187 ( V_49 ) ;
V_62 -> V_10 -> remove ( V_62 ) ;
}
int F_189 ( struct V_22 * V_23 , struct V_61 * V_62 ,
const struct V_294 * V_295 )
{
int V_14 ;
V_14 = F_172 ( & V_62 -> V_49 ,
& V_295 -> V_296 , V_23 ) ;
if ( V_14 )
return V_14 ;
V_62 -> V_23 = V_23 ;
V_62 -> V_10 = V_295 ;
if ( V_295 -> V_155 )
V_62 -> V_49 . V_155 = F_186 ;
if ( V_295 -> remove )
V_62 -> V_49 . remove = F_188 ;
#ifdef F_108
V_62 -> V_49 . V_52 = L_77 ;
#endif
F_35 ( & V_58 ) ;
F_178 ( & V_62 -> V_49 ) ;
F_91 ( & V_62 -> V_160 , & V_297 ) ;
F_37 ( & V_58 ) ;
F_49 ( V_23 , L_78 ,
V_62 -> V_49 . V_53 ) ;
return 0 ;
}
int F_190 ( struct V_22 * V_23 ,
const struct V_294 * V_295 )
{
struct V_61 * V_62 ;
int V_14 ;
F_49 ( V_23 , L_79 , V_148 ( V_23 ) ) ;
V_62 = F_94 ( sizeof( struct V_61 ) , V_40 ) ;
if ( V_62 == NULL )
return - V_41 ;
V_14 = F_189 ( V_23 , V_62 , V_295 ) ;
if ( V_14 )
F_16 ( V_62 ) ;
return V_14 ;
}
void F_191 ( struct V_61 * V_62 )
{
F_35 ( & V_58 ) ;
F_75 ( & V_62 -> V_160 ) ;
F_182 ( & V_62 -> V_49 ) ;
F_37 ( & V_58 ) ;
F_49 ( V_62 -> V_23 , L_80 ,
V_62 -> V_49 . V_53 ) ;
F_181 ( & V_62 -> V_49 ) ;
}
struct V_61 * F_192 ( struct V_22 * V_23 )
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
void F_193 ( struct V_22 * V_23 )
{
struct V_61 * V_62 ;
V_62 = F_192 ( V_23 ) ;
if ( ! V_62 )
return;
F_191 ( V_62 ) ;
F_16 ( V_62 ) ;
}
static void F_194 ( struct V_298 * V_72 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_128 ( V_299 ) ; V_3 ++ )
if ( V_72 -> V_300 & V_299 [ V_3 ] )
V_72 -> V_300 |= V_299 [ V_3 ] ;
}
static int F_195 ( struct V_48 * V_49 )
{
struct V_4 * V_5 = F_32 ( V_49 ) ;
return V_5 -> V_10 -> V_155 ( V_5 ) ;
}
static void F_196 ( struct V_48 * V_49 )
{
struct V_4 * V_5 = F_32 ( V_49 ) ;
V_5 -> V_10 -> remove ( V_5 ) ;
}
static int F_197 ( struct V_48 * V_49 ,
unsigned int V_6 , unsigned int V_1 )
{
struct V_4 * V_5 = F_32 ( V_49 ) ;
return V_5 -> V_10 -> V_284 ( V_5 , V_6 , V_1 ) ;
}
static int F_198 ( struct V_48 * V_49 ,
unsigned int V_6 , unsigned int * V_1 )
{
struct V_4 * V_5 = F_32 ( V_49 ) ;
* V_1 = V_5 -> V_10 -> V_285 ( V_5 , V_6 ) ;
return 0 ;
}
static int F_199 ( struct V_150 * V_102 ,
enum V_301 V_302 )
{
struct V_4 * V_5 = F_200 ( V_102 ) ;
return V_5 -> V_10 -> V_303 ( V_5 , V_302 ) ;
}
int F_201 ( struct V_22 * V_23 ,
const struct V_304 * V_305 ,
struct V_89 * V_269 ,
int V_272 )
{
struct V_4 * V_5 ;
struct V_59 * V_60 ;
int V_14 , V_3 ;
F_49 ( V_23 , L_81 , V_148 ( V_23 ) ) ;
V_5 = F_94 ( sizeof( struct V_4 ) , V_40 ) ;
if ( V_5 == NULL )
return - V_41 ;
V_5 -> V_49 . V_281 = & V_5 -> V_102 ;
V_5 -> V_49 . V_5 = V_5 ;
V_14 = F_172 ( & V_5 -> V_49 ,
& V_305 -> V_296 , V_23 ) ;
if ( V_14 )
goto V_289;
if ( V_305 -> V_156 ) {
V_5 -> V_49 . V_156 = V_305 -> V_156 ;
V_5 -> V_49 . V_157 = V_305 -> V_157 ;
}
if ( V_305 -> V_152 ) {
V_5 -> V_49 . V_152 = V_305 -> V_152 ;
V_5 -> V_49 . V_153 = V_305 -> V_153 ;
}
if ( V_305 -> V_158 ) {
V_5 -> V_49 . V_158 = V_305 -> V_158 ;
V_5 -> V_49 . V_159 = V_305 -> V_159 ;
}
if ( V_305 -> V_155 )
V_5 -> V_49 . V_155 = F_195 ;
if ( V_305 -> remove )
V_5 -> V_49 . remove = F_196 ;
if ( V_305 -> V_284 )
V_5 -> V_49 . V_284 = F_197 ;
if ( V_305 -> V_285 )
V_5 -> V_49 . V_285 = F_198 ;
V_5 -> V_49 . V_290 = V_305 -> V_290 ;
V_5 -> V_102 . V_106 = V_305 -> V_106 ;
V_5 -> V_102 . V_306 = V_305 -> V_306 ;
if ( V_305 -> V_277 )
V_5 -> V_102 . V_277 = V_305 -> V_277 ;
if ( V_305 -> V_303 )
V_5 -> V_102 . V_303 = F_199 ;
V_5 -> V_23 = V_23 ;
V_5 -> V_10 = V_305 ;
V_5 -> V_49 . V_283 = V_305 -> V_13 ;
#ifdef F_108
V_5 -> V_49 . V_55 = F_31 ;
V_5 -> V_49 . V_52 = L_82 ;
#endif
if ( V_305 -> V_307 )
V_5 -> V_49 . V_108 = V_305 -> V_307 ( V_23 ) ;
for ( V_3 = 0 ; V_3 < V_272 ; V_3 ++ ) {
F_194 ( & V_269 [ V_3 ] . V_308 ) ;
F_194 ( & V_269 [ V_3 ] . V_309 ) ;
}
V_14 = F_169 ( & V_5 -> V_49 , V_269 , V_272 , false ) ;
if ( V_14 < 0 ) {
F_69 ( V_23 , L_76 , V_14 ) ;
goto V_292;
}
F_36 (dai, &codec->component.dai_list, list)
V_60 -> V_5 = V_5 ;
F_35 ( & V_58 ) ;
F_178 ( & V_5 -> V_49 ) ;
F_91 ( & V_5 -> V_160 , & V_310 ) ;
F_37 ( & V_58 ) ;
F_49 ( V_5 -> V_23 , L_83 ,
V_5 -> V_49 . V_53 ) ;
return 0 ;
V_292:
F_181 ( & V_5 -> V_49 ) ;
V_289:
F_16 ( V_5 ) ;
return V_14 ;
}
void F_202 ( struct V_22 * V_23 )
{
struct V_4 * V_5 ;
F_35 ( & V_58 ) ;
F_36 (codec, &codec_list, list) {
if ( V_23 == V_5 -> V_23 )
goto V_264;
}
F_37 ( & V_58 ) ;
return;
V_264:
F_75 ( & V_5 -> V_160 ) ;
F_182 ( & V_5 -> V_49 ) ;
F_37 ( & V_58 ) ;
F_49 ( V_5 -> V_23 , L_84 ,
V_5 -> V_49 . V_53 ) ;
F_181 ( & V_5 -> V_49 ) ;
F_203 ( V_5 ) ;
F_16 ( V_5 ) ;
}
int F_204 ( struct V_63 * V_50 ,
const char * V_311 )
{
struct V_118 * V_312 ;
int V_14 ;
if ( ! V_50 -> V_23 ) {
F_205 ( L_85 , V_313 ) ;
return - V_15 ;
}
V_312 = V_50 -> V_23 -> V_119 ;
V_14 = F_206 ( V_312 , V_311 , 0 , & V_50 -> V_53 ) ;
if ( V_14 < 0 && V_14 != - V_15 ) {
F_69 ( V_50 -> V_23 ,
L_86 ,
V_311 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
int F_207 ( struct V_63 * V_50 ,
const char * V_311 )
{
struct V_118 * V_312 = V_50 -> V_23 -> V_119 ;
struct V_171 * V_314 ;
const char * V_221 , * V_315 ;
int V_3 , V_80 , V_316 , V_14 ;
V_316 = F_208 ( V_312 , V_311 ) ;
if ( V_316 < 0 ) {
F_69 ( V_50 -> V_23 ,
L_87 , V_311 ) ;
return - V_15 ;
}
if ( V_316 & 1 ) {
F_69 ( V_50 -> V_23 ,
L_88 , V_311 ) ;
return - V_15 ;
}
V_316 /= 2 ;
if ( ! V_316 ) {
F_69 ( V_50 -> V_23 , L_89 ,
V_311 ) ;
return - V_15 ;
}
V_314 = F_209 ( V_50 -> V_23 , V_316 , sizeof( * V_314 ) ,
V_40 ) ;
if ( ! V_314 ) {
F_69 ( V_50 -> V_23 ,
L_90 ) ;
return - V_41 ;
}
for ( V_3 = 0 ; V_3 < V_316 ; V_3 ++ ) {
V_14 = F_206 ( V_312 , V_311 ,
2 * V_3 , & V_221 ) ;
if ( V_14 ) {
F_69 ( V_50 -> V_23 ,
L_91 ,
V_311 , 2 * V_3 , V_14 ) ;
return - V_15 ;
}
for ( V_80 = 0 ; V_80 < F_128 ( V_317 ) ; V_80 ++ ) {
if ( ! strncmp ( V_221 , V_317 [ V_80 ] . V_53 ,
strlen ( V_317 [ V_80 ] . V_53 ) ) ) {
V_314 [ V_3 ] = V_317 [ V_80 ] ;
break;
}
}
if ( V_80 >= F_128 ( V_317 ) ) {
F_69 ( V_50 -> V_23 ,
L_92 ,
V_221 ) ;
return - V_15 ;
}
V_14 = F_206 ( V_312 , V_311 ,
( 2 * V_3 ) + 1 ,
& V_315 ) ;
if ( V_14 ) {
F_69 ( V_50 -> V_23 ,
L_91 ,
V_311 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_15 ;
}
V_314 [ V_3 ] . V_53 = V_315 ;
}
V_50 -> V_202 = V_314 ;
V_50 -> V_203 = V_316 ;
return 0 ;
}
int F_210 ( struct V_118 * V_312 ,
unsigned int * V_243 ,
unsigned int * V_246 )
{
T_6 V_1 ;
int V_14 ;
if ( F_211 ( V_312 , L_93 ) ) {
V_14 = F_212 ( V_312 , L_93 , & V_1 ) ;
if ( V_14 )
return V_14 ;
if ( V_243 )
* V_243 = V_1 ;
}
if ( F_211 ( V_312 , L_94 ) ) {
V_14 = F_212 ( V_312 , L_94 , & V_1 ) ;
if ( V_14 )
return V_14 ;
if ( V_246 )
* V_246 = V_1 ;
}
return 0 ;
}
int F_213 ( struct V_63 * V_50 ,
const char * V_311 )
{
struct V_118 * V_312 = V_50 -> V_23 -> V_119 ;
int V_318 ;
struct V_319 * V_320 ;
int V_3 , V_14 ;
V_318 = F_208 ( V_312 , V_311 ) ;
if ( V_318 < 0 || V_318 & 1 ) {
F_69 ( V_50 -> V_23 ,
L_95 ,
V_311 ) ;
return - V_15 ;
}
V_318 /= 2 ;
if ( ! V_318 ) {
F_69 ( V_50 -> V_23 , L_89 ,
V_311 ) ;
return - V_15 ;
}
V_320 = F_161 ( V_50 -> V_23 , V_318 * sizeof( * V_320 ) ,
V_40 ) ;
if ( ! V_320 ) {
F_69 ( V_50 -> V_23 ,
L_96 ) ;
return - V_15 ;
}
for ( V_3 = 0 ; V_3 < V_318 ; V_3 ++ ) {
V_14 = F_206 ( V_312 , V_311 ,
2 * V_3 , & V_320 [ V_3 ] . V_321 ) ;
if ( V_14 ) {
F_69 ( V_50 -> V_23 ,
L_97 ,
V_311 , 2 * V_3 , V_14 ) ;
return - V_15 ;
}
V_14 = F_206 ( V_312 , V_311 ,
( 2 * V_3 ) + 1 , & V_320 [ V_3 ] . V_232 ) ;
if ( V_14 ) {
F_69 ( V_50 -> V_23 ,
L_97 ,
V_311 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_15 ;
}
}
V_50 -> V_208 = V_318 ;
V_50 -> V_207 = V_320 ;
return 0 ;
}
unsigned int F_214 ( struct V_118 * V_312 ,
const char * V_220 ,
struct V_118 * * V_322 ,
struct V_118 * * V_323 )
{
int V_14 , V_3 ;
char V_324 [ 128 ] ;
unsigned int V_325 = 0 ;
int V_326 , V_327 ;
const char * V_328 ;
struct {
char * V_53 ;
unsigned int V_1 ;
} V_329 [] = {
{ L_98 , V_330 } ,
{ L_99 , V_331 } ,
{ L_100 , V_332 } ,
{ L_101 , V_333 } ,
{ L_102 , V_334 } ,
{ L_103 , V_335 } ,
{ L_104 , V_336 } ,
{ L_105 , V_337 } ,
{ L_106 , V_338 } ,
} ;
if ( ! V_220 )
V_220 = L_107 ;
snprintf ( V_324 , sizeof( V_324 ) , L_108 , V_220 ) ;
V_14 = F_215 ( V_312 , V_324 , & V_328 ) ;
if ( V_14 == 0 ) {
for ( V_3 = 0 ; V_3 < F_128 ( V_329 ) ; V_3 ++ ) {
if ( strcmp ( V_328 , V_329 [ V_3 ] . V_53 ) == 0 ) {
V_325 |= V_329 [ V_3 ] . V_1 ;
break;
}
}
}
snprintf ( V_324 , sizeof( V_324 ) , L_109 , V_220 ) ;
if ( F_216 ( V_312 , V_324 , NULL ) )
V_325 |= V_339 ;
else
V_325 |= V_340 ;
snprintf ( V_324 , sizeof( V_324 ) , L_110 , V_220 ) ;
V_326 = ! ! F_216 ( V_312 , V_324 , NULL ) ;
snprintf ( V_324 , sizeof( V_324 ) , L_111 , V_220 ) ;
V_327 = ! ! F_216 ( V_312 , V_324 , NULL ) ;
switch ( ( V_326 << 4 ) + V_327 ) {
case 0x11 :
V_325 |= V_341 ;
break;
case 0x10 :
V_325 |= V_342 ;
break;
case 0x01 :
V_325 |= V_343 ;
break;
default:
break;
}
snprintf ( V_324 , sizeof( V_324 ) , L_112 , V_220 ) ;
V_326 = ! ! F_216 ( V_312 , V_324 , NULL ) ;
if ( V_326 && V_322 )
* V_322 = F_217 ( V_312 , V_324 , 0 ) ;
snprintf ( V_324 , sizeof( V_324 ) , L_113 , V_220 ) ;
V_327 = ! ! F_216 ( V_312 , V_324 , NULL ) ;
if ( V_327 && V_323 )
* V_323 = F_217 ( V_312 , V_324 , 0 ) ;
switch ( ( V_326 << 4 ) + V_327 ) {
case 0x11 :
V_325 |= V_192 ;
break;
case 0x10 :
V_325 |= V_194 ;
break;
case 0x01 :
V_325 |= V_195 ;
break;
default:
V_325 |= V_193 ;
break;
}
return V_325 ;
}
static int F_218 ( struct V_344 * args ,
const char * * V_124 )
{
struct V_48 * V_17 ;
struct V_118 * V_122 ;
int V_14 = - V_133 ;
F_35 ( & V_58 ) ;
F_36 (pos, &component_list, list) {
V_122 = V_17 -> V_23 -> V_119 ;
if ( ! V_122 && V_17 -> V_23 -> V_123 )
V_122 = V_17 -> V_23 -> V_123 -> V_119 ;
if ( V_122 != args -> V_312 )
continue;
if ( V_17 -> V_10 -> V_345 ) {
V_14 = V_17 -> V_10 -> V_345 ( V_17 ,
args ,
V_124 ) ;
} else {
int V_227 = - 1 ;
switch ( args -> V_346 ) {
case 0 :
V_227 = 0 ;
break;
case 1 :
V_227 = args -> args [ 0 ] ;
break;
default:
break;
}
if ( V_227 < 0 || V_227 >= V_17 -> V_272 ) {
V_14 = - V_15 ;
continue;
}
V_14 = 0 ;
* V_124 = V_17 -> V_269 [ V_227 ] . V_53 ;
if ( ! * V_124 )
* V_124 = V_17 -> V_53 ;
}
break;
}
F_37 ( & V_58 ) ;
return V_14 ;
}
int F_219 ( struct V_118 * V_119 ,
const char * * V_124 )
{
struct V_344 args ;
int V_14 ;
V_14 = F_220 ( V_119 , L_114 ,
L_115 , 0 , & args ) ;
if ( V_14 )
return V_14 ;
V_14 = F_218 ( & args , V_124 ) ;
F_221 ( args . V_312 ) ;
return V_14 ;
}
int F_222 ( struct V_22 * V_23 ,
struct V_118 * V_119 ,
struct V_126 * V_71 )
{
struct V_344 args ;
struct V_120 * V_49 ;
char * V_53 ;
int V_223 , V_87 , V_14 ;
V_53 = L_114 ;
V_87 = F_223 ( V_119 , V_53 ,
L_115 ) ;
if ( V_87 <= 0 ) {
if ( V_87 == - V_347 )
F_69 ( V_23 , L_116 ) ;
else
F_69 ( V_23 , L_117 ) ;
return V_87 ;
}
V_49 = F_161 ( V_23 ,
sizeof *V_49 * V_87 ,
V_40 ) ;
if ( ! V_49 )
return - V_41 ;
V_71 -> V_127 = V_49 ;
V_71 -> V_87 = V_87 ;
for ( V_223 = 0 , V_49 = V_71 -> V_127 ;
V_223 < V_71 -> V_87 ;
V_223 ++ , V_49 ++ ) {
V_14 = F_220 ( V_119 , V_53 ,
L_115 ,
V_223 , & args ) ;
if ( V_14 )
goto V_139;
V_49 -> V_119 = args . V_312 ;
V_14 = F_218 ( & args , & V_49 -> V_124 ) ;
if ( V_14 < 0 )
goto V_139;
}
return 0 ;
V_139:
for ( V_223 = 0 , V_49 = V_71 -> V_127 ;
V_223 < V_71 -> V_87 ;
V_223 ++ , V_49 ++ ) {
if ( ! V_49 -> V_119 )
break;
F_221 ( V_49 -> V_119 ) ;
V_49 -> V_119 = NULL ;
}
V_71 -> V_127 = NULL ;
V_71 -> V_87 = 0 ;
return V_14 ;
}
static int T_7 F_224 ( void )
{
F_44 () ;
F_225 () ;
return F_226 ( & V_348 ) ;
}
static void T_8 F_227 ( void )
{
F_228 () ;
F_47 () ;
#ifdef F_108
#endif
F_229 ( & V_348 ) ;
}
