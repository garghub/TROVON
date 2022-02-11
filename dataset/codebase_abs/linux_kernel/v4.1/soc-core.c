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
char V_15 [ V_8 + 1 ] ;
char V_16 [ V_12 + 1 ] ;
F_3 ( V_8 > 63 ) ;
if ( V_9 + V_12 + 2 + 1 != V_8 )
return - V_17 ;
V_14 = F_4 ( V_5 , V_6 ) ;
if ( V_14 < 0 ) {
memset ( V_16 , 'X' , V_12 ) ;
V_16 [ V_12 ] = '\0' ;
} else {
snprintf ( V_16 , V_12 + 1 , L_1 , V_12 , V_14 ) ;
}
snprintf ( V_15 , V_8 + 1 , L_2 , V_9 , V_6 , V_16 ) ;
memcpy ( V_7 , V_15 , V_8 ) ;
return 0 ;
}
static T_2 F_5 ( struct V_4 * V_5 , char * V_7 ,
T_1 V_18 , T_3 V_19 )
{
int V_3 , V_20 = 1 ;
int V_9 , V_12 ;
int V_8 ;
T_1 V_21 = 0 ;
T_3 V_22 = 0 ;
V_9 = F_1 ( V_5 -> V_10 -> V_11 ) * 2 ;
V_12 = V_5 -> V_10 -> V_13 * 2 ;
V_8 = V_9 + V_12 + 2 + 1 ;
if ( ! V_5 -> V_10 -> V_11 )
return 0 ;
if ( V_5 -> V_10 -> V_23 )
V_20 = V_5 -> V_10 -> V_23 ;
for ( V_3 = 0 ; V_3 < V_5 -> V_10 -> V_11 ; V_3 += V_20 ) {
if ( V_22 >= V_19 ) {
if ( V_21 + V_8 >= V_18 - 1 )
break;
F_2 ( V_5 , V_3 , V_7 + V_21 , V_8 ) ;
V_21 += V_8 ;
}
V_22 += V_8 ;
}
V_21 = F_6 ( V_21 , V_18 - 1 ) ;
return V_21 ;
}
static T_2 F_7 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_7 )
{
struct V_28 * V_29 = F_8 ( V_25 ) ;
return F_5 ( V_29 -> V_5 , V_7 , V_30 , 0 ) ;
}
static T_2 F_9 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_7 )
{
struct V_28 * V_29 = F_8 ( V_25 ) ;
return sprintf ( V_7 , L_3 , V_29 -> V_31 ) ;
}
static T_2 F_10 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
const char * V_7 , T_1 V_18 )
{
struct V_28 * V_29 = F_8 ( V_25 ) ;
int V_14 ;
V_14 = F_11 ( V_7 , 10 , & V_29 -> V_31 ) ;
if ( V_14 )
return V_14 ;
return V_18 ;
}
static T_4 F_12 ( struct V_32 * V_33 ,
struct V_34 * V_27 , int V_35 )
{
struct V_24 * V_25 = F_13 ( V_33 ) ;
struct V_28 * V_29 = F_8 ( V_25 ) ;
if ( V_27 == & V_36 . V_27 )
return V_27 -> V_37 ;
return V_29 -> V_5 ? V_27 -> V_37 : 0 ;
}
static T_2 F_14 ( struct V_38 * V_38 , char T_5 * V_39 ,
T_1 V_18 , T_3 * V_40 )
{
T_2 V_14 ;
struct V_4 * V_5 = V_38 -> V_41 ;
char * V_7 ;
if ( * V_40 < 0 || ! V_18 )
return - V_17 ;
V_7 = F_15 ( V_18 , V_42 ) ;
if ( ! V_7 )
return - V_43 ;
V_14 = F_5 ( V_5 , V_7 , V_18 , * V_40 ) ;
if ( V_14 >= 0 ) {
if ( F_16 ( V_39 , V_7 , V_14 ) ) {
F_17 ( V_7 ) ;
return - V_44 ;
}
* V_40 += V_14 ;
}
F_17 ( V_7 ) ;
return V_14 ;
}
static T_2 F_18 ( struct V_38 * V_38 ,
const char T_5 * V_39 , T_1 V_18 , T_3 * V_40 )
{
char V_7 [ 32 ] ;
T_1 V_45 ;
char * V_46 = V_7 ;
unsigned long V_6 , V_47 ;
struct V_4 * V_5 = V_38 -> V_41 ;
int V_14 ;
V_45 = F_6 ( V_18 , ( sizeof( V_7 ) - 1 ) ) ;
if ( F_19 ( V_7 , V_39 , V_45 ) )
return - V_44 ;
V_7 [ V_45 ] = 0 ;
while ( * V_46 == ' ' )
V_46 ++ ;
V_6 = F_20 ( V_46 , & V_46 , 16 ) ;
while ( * V_46 == ' ' )
V_46 ++ ;
V_14 = F_21 ( V_46 , 16 , & V_47 ) ;
if ( V_14 )
return V_14 ;
F_22 ( V_48 , V_49 ) ;
F_23 ( V_5 , V_6 , V_47 ) ;
return V_45 ;
}
static void F_24 ( struct V_50 * V_51 )
{
if ( ! V_51 -> V_52 -> V_53 )
return;
if ( V_51 -> V_54 ) {
char * V_55 ;
V_55 = F_25 ( V_42 , L_4 ,
V_51 -> V_54 , V_51 -> V_55 ) ;
if ( V_55 ) {
V_51 -> V_56 = F_26 ( V_55 ,
V_51 -> V_52 -> V_53 ) ;
F_17 ( V_55 ) ;
}
} else {
V_51 -> V_56 = F_26 ( V_51 -> V_55 ,
V_51 -> V_52 -> V_53 ) ;
}
if ( ! V_51 -> V_56 ) {
F_27 ( V_51 -> V_25 ,
L_5 ) ;
return;
}
F_28 ( F_29 ( V_51 ) ,
V_51 -> V_56 ) ;
if ( V_51 -> V_57 )
V_51 -> V_57 ( V_51 ) ;
}
static void F_30 ( struct V_50 * V_51 )
{
F_31 ( V_51 -> V_56 ) ;
}
static void F_32 ( struct V_50 * V_51 )
{
struct V_4 * V_5 = F_33 ( V_51 ) ;
V_5 -> V_58 = F_34 ( L_6 , 0644 ,
V_5 -> V_51 . V_56 ,
V_5 , & V_59 ) ;
if ( ! V_5 -> V_58 )
F_27 ( V_5 -> V_25 ,
L_7 ) ;
}
static T_2 F_35 ( struct V_38 * V_38 , char T_5 * V_39 ,
T_1 V_18 , T_3 * V_40 )
{
char * V_7 = F_15 ( V_30 , V_42 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_4 * V_5 ;
if ( ! V_7 )
return - V_43 ;
F_36 ( & V_60 ) ;
F_37 (codec, &codec_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_30 - V_14 , L_8 ,
V_5 -> V_51 . V_55 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_30 ) {
V_14 = V_30 ;
break;
}
}
F_38 ( & V_60 ) ;
if ( V_14 >= 0 )
V_14 = F_39 ( V_39 , V_18 , V_40 , V_7 , V_14 ) ;
F_17 ( V_7 ) ;
return V_14 ;
}
static T_2 F_40 ( struct V_38 * V_38 , char T_5 * V_39 ,
T_1 V_18 , T_3 * V_40 )
{
char * V_7 = F_15 ( V_30 , V_42 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_50 * V_51 ;
struct V_61 * V_62 ;
if ( ! V_7 )
return - V_43 ;
F_36 ( & V_60 ) ;
F_37 (component, &component_list, list) {
F_37 (dai, &component->dai_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_30 - V_14 , L_8 ,
V_62 -> V_55 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_30 ) {
V_14 = V_30 ;
break;
}
}
}
F_38 ( & V_60 ) ;
V_14 = F_39 ( V_39 , V_18 , V_40 , V_7 , V_14 ) ;
F_17 ( V_7 ) ;
return V_14 ;
}
static T_2 F_41 ( struct V_38 * V_38 ,
char T_5 * V_39 ,
T_1 V_18 , T_3 * V_40 )
{
char * V_7 = F_15 ( V_30 , V_42 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_63 * V_64 ;
if ( ! V_7 )
return - V_43 ;
F_36 ( & V_60 ) ;
F_37 (platform, &platform_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_30 - V_14 , L_8 ,
V_64 -> V_51 . V_55 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_30 ) {
V_14 = V_30 ;
break;
}
}
F_38 ( & V_60 ) ;
V_14 = F_39 ( V_39 , V_18 , V_40 , V_7 , V_14 ) ;
F_17 ( V_7 ) ;
return V_14 ;
}
static void F_42 ( struct V_65 * V_52 )
{
if ( ! V_66 )
return;
V_52 -> V_53 = F_26 ( V_52 -> V_55 ,
V_66 ) ;
if ( ! V_52 -> V_53 ) {
F_27 ( V_52 -> V_25 ,
L_9 ) ;
return;
}
V_52 -> V_67 = F_43 ( L_10 , 0644 ,
V_52 -> V_53 ,
& V_52 -> V_68 ) ;
if ( ! V_52 -> V_67 )
F_27 ( V_52 -> V_25 ,
L_11 ) ;
}
static void F_44 ( struct V_65 * V_52 )
{
F_31 ( V_52 -> V_53 ) ;
}
static void F_45 ( void )
{
V_66 = F_26 ( L_12 , NULL ) ;
if ( F_46 ( V_66 ) || ! V_66 ) {
F_47 ( L_13 ) ;
V_66 = NULL ;
return;
}
if ( ! F_34 ( L_14 , 0444 , V_66 , NULL ,
& V_69 ) )
F_47 ( L_15 ) ;
if ( ! F_34 ( L_16 , 0444 , V_66 , NULL ,
& V_70 ) )
F_47 ( L_17 ) ;
if ( ! F_34 ( L_18 , 0444 , V_66 , NULL ,
& V_71 ) )
F_47 ( L_19 ) ;
}
static void F_48 ( void )
{
F_31 ( V_66 ) ;
}
static inline void F_24 (
struct V_50 * V_51 )
{
}
static inline void F_30 (
struct V_50 * V_51 )
{
}
static inline void F_42 ( struct V_65 * V_52 )
{
}
static inline void F_44 ( struct V_65 * V_52 )
{
}
static inline void F_45 ( void )
{
}
static inline void F_48 ( void )
{
}
struct V_72 * F_49 ( struct V_65 * V_52 ,
const char * V_73 , int V_74 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_52 -> V_75 ; V_3 ++ ) {
if ( V_52 -> V_29 [ V_3 ] . V_73 -> V_76 &&
! strcmp ( V_52 -> V_29 [ V_3 ] . V_73 -> V_55 , V_73 ) )
return V_52 -> V_29 [ V_3 ] . V_77 -> V_78 [ V_74 ] . V_79 ;
}
F_50 ( V_52 -> V_25 , L_20 , V_73 ) ;
return NULL ;
}
struct V_28 * F_51 ( struct V_65 * V_52 ,
const char * V_73 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_52 -> V_75 ; V_3 ++ ) {
if ( ! strcmp ( V_52 -> V_29 [ V_3 ] . V_73 -> V_55 , V_73 ) )
return & V_52 -> V_29 [ V_3 ] ;
}
F_50 ( V_52 -> V_25 , L_21 , V_73 ) ;
return NULL ;
}
static void F_52 ( struct V_80 * V_81 )
{
}
int F_53 ( struct V_24 * V_25 )
{
struct V_65 * V_52 = F_8 ( V_25 ) ;
struct V_4 * V_5 ;
int V_3 , V_82 ;
if ( ! V_52 -> V_83 )
return 0 ;
F_54 ( V_52 -> V_84 ) ;
F_55 ( V_52 -> V_84 , V_85 ) ;
F_56 ( V_52 -> V_84 ) ;
F_57 ( V_52 -> V_84 , V_86 ) ;
for ( V_3 = 0 ; V_3 < V_52 -> V_87 ; V_3 ++ ) {
if ( V_52 -> V_29 [ V_3 ] . V_73 -> V_88 )
continue;
for ( V_82 = 0 ; V_82 < V_52 -> V_29 [ V_3 ] . V_89 ; V_82 ++ ) {
struct V_61 * V_62 = V_52 -> V_29 [ V_3 ] . V_90 [ V_82 ] ;
struct V_91 * V_92 = V_62 -> V_10 ;
if ( V_92 -> V_93 -> V_94 && V_62 -> V_95 )
V_92 -> V_93 -> V_94 ( V_62 , 1 ) ;
}
}
for ( V_3 = 0 ; V_3 < V_52 -> V_87 ; V_3 ++ ) {
if ( V_52 -> V_29 [ V_3 ] . V_73 -> V_88 )
continue;
F_58 ( V_52 -> V_29 [ V_3 ] . V_77 ) ;
}
if ( V_52 -> V_96 )
V_52 -> V_96 ( V_52 ) ;
for ( V_3 = 0 ; V_3 < V_52 -> V_87 ; V_3 ++ ) {
struct V_61 * V_97 = V_52 -> V_29 [ V_3 ] . V_97 ;
if ( V_52 -> V_29 [ V_3 ] . V_73 -> V_88 )
continue;
if ( V_97 -> V_10 -> V_98 && ! V_97 -> V_10 -> V_99 )
V_97 -> V_10 -> V_98 ( V_97 ) ;
}
for ( V_3 = 0 ; V_3 < V_52 -> V_87 ; V_3 ++ )
F_59 ( & V_52 -> V_29 [ V_3 ] . V_100 ) ;
for ( V_3 = 0 ; V_3 < V_52 -> V_87 ; V_3 ++ ) {
if ( V_52 -> V_29 [ V_3 ] . V_73 -> V_88 )
continue;
F_60 ( & V_52 -> V_29 [ V_3 ] ,
V_101 ,
V_102 ) ;
F_60 ( & V_52 -> V_29 [ V_3 ] ,
V_103 ,
V_102 ) ;
}
F_61 ( V_52 ) ;
F_62 ( & V_52 -> V_104 ) ;
F_37 (codec, &card->codec_dev_list, card_list) {
if ( ! V_5 -> V_105 ) {
switch ( V_5 -> V_104 . V_106 ) {
case V_107 :
if ( V_5 -> V_104 . V_108 ) {
F_50 ( V_5 -> V_25 ,
L_22 ) ;
break;
}
case V_109 :
if ( V_5 -> V_10 -> V_98 )
V_5 -> V_10 -> V_98 ( V_5 ) ;
V_5 -> V_105 = 1 ;
if ( V_5 -> V_51 . V_110 )
F_63 ( V_5 -> V_51 . V_110 ) ;
F_64 ( V_5 -> V_25 ) ;
break;
default:
F_50 ( V_5 -> V_25 ,
L_23 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_52 -> V_87 ; V_3 ++ ) {
struct V_61 * V_97 = V_52 -> V_29 [ V_3 ] . V_97 ;
if ( V_52 -> V_29 [ V_3 ] . V_73 -> V_88 )
continue;
if ( V_97 -> V_10 -> V_98 && V_97 -> V_10 -> V_99 )
V_97 -> V_10 -> V_98 ( V_97 ) ;
F_64 ( V_97 -> V_25 ) ;
}
if ( V_52 -> V_111 )
V_52 -> V_111 ( V_52 ) ;
return 0 ;
}
static void F_65 ( struct V_80 * V_81 )
{
struct V_65 * V_52 =
F_66 ( V_81 , struct V_65 , V_112 ) ;
struct V_4 * V_5 ;
int V_3 , V_82 ;
F_50 ( V_52 -> V_25 , L_24 ) ;
F_57 ( V_52 -> V_84 , V_113 ) ;
if ( V_52 -> V_114 )
V_52 -> V_114 ( V_52 ) ;
for ( V_3 = 0 ; V_3 < V_52 -> V_87 ; V_3 ++ ) {
struct V_61 * V_97 = V_52 -> V_29 [ V_3 ] . V_97 ;
if ( V_52 -> V_29 [ V_3 ] . V_73 -> V_88 )
continue;
if ( V_97 -> V_10 -> V_115 && V_97 -> V_10 -> V_99 )
V_97 -> V_10 -> V_115 ( V_97 ) ;
}
F_37 (codec, &card->codec_dev_list, card_list) {
if ( V_5 -> V_105 ) {
switch ( V_5 -> V_104 . V_106 ) {
case V_107 :
case V_109 :
if ( V_5 -> V_10 -> V_115 )
V_5 -> V_10 -> V_115 ( V_5 ) ;
V_5 -> V_105 = 0 ;
break;
default:
F_50 ( V_5 -> V_25 ,
L_25 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_52 -> V_87 ; V_3 ++ ) {
if ( V_52 -> V_29 [ V_3 ] . V_73 -> V_88 )
continue;
F_60 ( & V_52 -> V_29 [ V_3 ] ,
V_101 ,
V_116 ) ;
F_60 ( & V_52 -> V_29 [ V_3 ] ,
V_103 ,
V_116 ) ;
}
for ( V_3 = 0 ; V_3 < V_52 -> V_87 ; V_3 ++ ) {
if ( V_52 -> V_29 [ V_3 ] . V_73 -> V_88 )
continue;
for ( V_82 = 0 ; V_82 < V_52 -> V_29 [ V_3 ] . V_89 ; V_82 ++ ) {
struct V_61 * V_62 = V_52 -> V_29 [ V_3 ] . V_90 [ V_82 ] ;
struct V_91 * V_92 = V_62 -> V_10 ;
if ( V_92 -> V_93 -> V_94 && V_62 -> V_95 )
V_92 -> V_93 -> V_94 ( V_62 , 0 ) ;
}
}
for ( V_3 = 0 ; V_3 < V_52 -> V_87 ; V_3 ++ ) {
struct V_61 * V_97 = V_52 -> V_29 [ V_3 ] . V_97 ;
if ( V_52 -> V_29 [ V_3 ] . V_73 -> V_88 )
continue;
if ( V_97 -> V_10 -> V_115 && ! V_97 -> V_10 -> V_99 )
V_97 -> V_10 -> V_115 ( V_97 ) ;
}
if ( V_52 -> V_117 )
V_52 -> V_117 ( V_52 ) ;
F_50 ( V_52 -> V_25 , L_26 ) ;
F_57 ( V_52 -> V_84 , V_85 ) ;
F_61 ( V_52 ) ;
F_62 ( & V_52 -> V_104 ) ;
}
int F_67 ( struct V_24 * V_25 )
{
struct V_65 * V_52 = F_8 ( V_25 ) ;
bool V_99 = false ;
int V_3 ;
if ( ! V_52 -> V_83 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_52 -> V_87 ; V_3 ++ ) {
struct V_28 * V_29 = & V_52 -> V_29 [ V_3 ] ;
struct V_61 * * V_90 = V_29 -> V_90 ;
struct V_61 * V_97 = V_29 -> V_97 ;
int V_82 ;
if ( V_97 -> V_118 )
F_68 ( V_97 -> V_25 ) ;
for ( V_82 = 0 ; V_82 < V_29 -> V_89 ; V_82 ++ ) {
struct V_61 * V_119 = V_90 [ V_82 ] ;
if ( V_119 -> V_118 )
F_68 ( V_119 -> V_25 ) ;
}
}
for ( V_3 = 0 ; V_3 < V_52 -> V_87 ; V_3 ++ ) {
struct V_61 * V_97 = V_52 -> V_29 [ V_3 ] . V_97 ;
V_99 |= V_97 -> V_10 -> V_99 ;
}
if ( V_99 ) {
F_50 ( V_25 , L_27 ) ;
F_65 ( & V_52 -> V_112 ) ;
} else {
F_50 ( V_25 , L_28 ) ;
if ( ! F_69 ( & V_52 -> V_112 ) )
F_70 ( V_25 , L_29 ) ;
}
return 0 ;
}
static struct V_50 * F_71 (
const struct V_120 * V_121 , const char * V_55 )
{
struct V_50 * V_51 ;
F_72 ( & V_60 ) ;
F_37 (component, &component_list, list) {
if ( V_121 ) {
if ( V_51 -> V_25 -> V_121 == V_121 )
return V_51 ;
} else if ( strcmp ( V_51 -> V_55 , V_55 ) == 0 ) {
return V_51 ;
}
}
return NULL ;
}
static struct V_61 * F_73 (
const struct V_122 * V_123 )
{
struct V_50 * V_51 ;
struct V_61 * V_62 ;
F_72 ( & V_60 ) ;
F_37 (component, &component_list, list) {
if ( V_123 -> V_121 && V_51 -> V_25 -> V_121 != V_123 -> V_121 )
continue;
if ( V_123 -> V_55 && strcmp ( V_51 -> V_55 , V_123 -> V_55 ) )
continue;
F_37 (dai, &component->dai_list, list) {
if ( V_123 -> V_124 && strcmp ( V_62 -> V_55 , V_123 -> V_124 ) )
continue;
return V_62 ;
}
}
return NULL ;
}
static int F_74 ( struct V_65 * V_52 , int V_125 )
{
struct V_126 * V_73 = & V_52 -> V_73 [ V_125 ] ;
struct V_28 * V_29 = & V_52 -> V_29 [ V_125 ] ;
struct V_122 * V_127 = V_73 -> V_127 ;
struct V_122 V_128 ;
struct V_61 * * V_90 = V_29 -> V_90 ;
struct V_63 * V_64 ;
const char * V_129 ;
int V_3 ;
F_50 ( V_52 -> V_25 , L_30 , V_73 -> V_55 , V_125 ) ;
V_128 . V_55 = V_73 -> V_130 ;
V_128 . V_121 = V_73 -> V_131 ;
V_128 . V_124 = V_73 -> V_132 ;
V_29 -> V_97 = F_73 ( & V_128 ) ;
if ( ! V_29 -> V_97 ) {
F_70 ( V_52 -> V_25 , L_31 ,
V_73 -> V_132 ) ;
return - V_133 ;
}
V_29 -> V_89 = V_73 -> V_89 ;
for ( V_3 = 0 ; V_3 < V_29 -> V_89 ; V_3 ++ ) {
V_90 [ V_3 ] = F_73 ( & V_127 [ V_3 ] ) ;
if ( ! V_90 [ V_3 ] ) {
F_70 ( V_52 -> V_25 , L_32 ,
V_127 [ V_3 ] . V_124 ) ;
return - V_133 ;
}
}
V_29 -> V_119 = V_90 [ 0 ] ;
V_29 -> V_5 = V_29 -> V_119 -> V_5 ;
V_129 = V_73 -> V_129 ;
if ( ! V_129 && ! V_73 -> V_134 )
V_129 = L_33 ;
F_37 (platform, &platform_list, list) {
if ( V_73 -> V_134 ) {
if ( V_64 -> V_25 -> V_121 !=
V_73 -> V_134 )
continue;
} else {
if ( strcmp ( V_64 -> V_51 . V_55 , V_129 ) )
continue;
}
V_29 -> V_64 = V_64 ;
}
if ( ! V_29 -> V_64 ) {
F_70 ( V_52 -> V_25 , L_34 ,
V_73 -> V_129 ) ;
return - V_133 ;
}
V_52 -> V_87 ++ ;
return 0 ;
}
static void F_75 ( struct V_50 * V_51 )
{
if ( ! V_51 -> V_135 )
return;
if ( V_51 -> V_5 )
F_76 ( & V_51 -> V_5 -> V_136 ) ;
if ( V_51 -> remove )
V_51 -> remove ( V_51 ) ;
F_77 ( F_29 ( V_51 ) ) ;
F_30 ( V_51 ) ;
V_51 -> V_135 = 0 ;
F_78 ( V_51 -> V_25 -> V_10 -> V_137 ) ;
}
static void F_79 ( struct V_61 * V_62 , int V_138 )
{
int V_139 ;
if ( V_62 && V_62 -> V_135 &&
V_62 -> V_10 -> V_140 == V_138 ) {
if ( V_62 -> V_10 -> remove ) {
V_139 = V_62 -> V_10 -> remove ( V_62 ) ;
if ( V_139 < 0 )
F_70 ( V_62 -> V_25 ,
L_35 ,
V_62 -> V_55 , V_139 ) ;
}
V_62 -> V_135 = 0 ;
}
}
static void F_80 ( struct V_65 * V_52 , int V_125 , int V_138 )
{
struct V_28 * V_29 = & V_52 -> V_29 [ V_125 ] ;
int V_3 ;
if ( V_29 -> V_141 ) {
F_81 ( V_29 -> V_25 ) ;
V_29 -> V_141 = 0 ;
}
for ( V_3 = 0 ; V_3 < V_29 -> V_89 ; V_3 ++ )
F_79 ( V_29 -> V_90 [ V_3 ] , V_138 ) ;
F_79 ( V_29 -> V_97 , V_138 ) ;
}
static void F_82 ( struct V_65 * V_52 , int V_125 ,
int V_138 )
{
struct V_28 * V_29 = & V_52 -> V_29 [ V_125 ] ;
struct V_61 * V_97 = V_29 -> V_97 ;
struct V_63 * V_64 = V_29 -> V_64 ;
struct V_50 * V_51 ;
int V_3 ;
if ( V_64 && V_64 -> V_51 . V_10 -> V_140 == V_138 )
F_75 ( & V_64 -> V_51 ) ;
for ( V_3 = 0 ; V_3 < V_29 -> V_89 ; V_3 ++ ) {
V_51 = V_29 -> V_90 [ V_3 ] -> V_51 ;
if ( V_51 -> V_10 -> V_140 == V_138 )
F_75 ( V_51 ) ;
}
if ( V_97 ) {
if ( V_97 -> V_51 -> V_10 -> V_140 == V_138 )
F_75 ( V_97 -> V_51 ) ;
}
}
static void F_83 ( struct V_65 * V_52 )
{
int V_62 , V_138 ;
for ( V_138 = V_142 ; V_138 <= V_143 ;
V_138 ++ ) {
for ( V_62 = 0 ; V_62 < V_52 -> V_87 ; V_62 ++ )
F_80 ( V_52 , V_62 , V_138 ) ;
}
for ( V_138 = V_142 ; V_138 <= V_143 ;
V_138 ++ ) {
for ( V_62 = 0 ; V_62 < V_52 -> V_87 ; V_62 ++ )
F_82 ( V_52 , V_62 , V_138 ) ;
}
V_52 -> V_87 = 0 ;
}
static void F_84 ( struct V_65 * V_52 ,
struct V_50 * V_51 )
{
int V_3 ;
if ( V_52 -> V_144 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_52 -> V_145 ; V_3 ++ ) {
struct V_146 * V_147 = & V_52 -> V_144 [ V_3 ] ;
if ( V_147 -> V_121 && V_51 -> V_25 -> V_121 != V_147 -> V_121 )
continue;
if ( V_147 -> V_148 && strcmp ( V_51 -> V_55 , V_147 -> V_148 ) )
continue;
V_51 -> V_149 = V_147 -> V_149 ;
break;
}
}
static int F_85 ( struct V_65 * V_52 ,
struct V_50 * V_51 )
{
struct V_150 * V_104 = F_29 ( V_51 ) ;
struct V_61 * V_62 ;
int V_14 ;
if ( V_51 -> V_135 )
return 0 ;
V_51 -> V_52 = V_52 ;
V_104 -> V_52 = V_52 ;
F_84 ( V_52 , V_51 ) ;
if ( ! F_86 ( V_51 -> V_25 -> V_10 -> V_137 ) )
return - V_151 ;
F_24 ( V_51 ) ;
if ( V_51 -> V_152 ) {
V_14 = F_87 ( V_104 , V_51 -> V_152 ,
V_51 -> V_153 ) ;
if ( V_14 != 0 ) {
F_70 ( V_51 -> V_25 ,
L_36 , V_14 ) ;
goto V_154;
}
}
F_37 (dai, &component->dai_list, list) {
V_14 = F_88 ( V_104 , V_62 ) ;
if ( V_14 != 0 ) {
F_70 ( V_51 -> V_25 ,
L_37 , V_14 ) ;
goto V_154;
}
}
if ( V_51 -> V_155 ) {
V_14 = V_51 -> V_155 ( V_51 ) ;
if ( V_14 < 0 ) {
F_70 ( V_51 -> V_25 ,
L_38 , V_14 ) ;
goto V_154;
}
F_89 ( V_104 -> V_108 &&
V_104 -> V_106 != V_109 ,
L_39 ,
V_51 -> V_55 ) ;
}
if ( V_51 -> V_156 )
F_90 ( V_51 , V_51 -> V_156 ,
V_51 -> V_157 ) ;
if ( V_51 -> V_158 )
F_91 ( V_104 , V_51 -> V_158 ,
V_51 -> V_159 ) ;
V_51 -> V_135 = 1 ;
F_92 ( & V_104 -> V_160 , & V_52 -> V_161 ) ;
if ( V_51 -> V_5 )
F_92 ( & V_51 -> V_5 -> V_136 , & V_52 -> V_162 ) ;
return 0 ;
V_154:
F_30 ( V_51 ) ;
F_78 ( V_51 -> V_25 -> V_10 -> V_137 ) ;
return V_14 ;
}
static void F_93 ( struct V_24 * V_25 )
{
F_17 ( V_25 ) ;
}
static int F_94 ( struct V_28 * V_29 ,
const char * V_55 )
{
int V_14 = 0 ;
V_29 -> V_25 = F_95 ( sizeof( struct V_24 ) , V_42 ) ;
if ( ! V_29 -> V_25 )
return - V_43 ;
F_96 ( V_29 -> V_25 ) ;
V_29 -> V_25 -> V_163 = V_29 -> V_52 -> V_25 ;
V_29 -> V_25 -> V_164 = F_93 ;
V_29 -> V_25 -> V_165 = V_166 ;
F_97 ( V_29 -> V_25 , L_40 , V_55 ) ;
F_98 ( V_29 -> V_25 , V_29 ) ;
F_99 ( & V_29 -> V_167 ) ;
F_100 ( & V_29 -> V_168 [ V_101 ] . V_169 ) ;
F_100 ( & V_29 -> V_168 [ V_103 ] . V_169 ) ;
F_100 ( & V_29 -> V_168 [ V_101 ] . V_170 ) ;
F_100 ( & V_29 -> V_168 [ V_103 ] . V_170 ) ;
V_14 = F_101 ( V_29 -> V_25 ) ;
if ( V_14 < 0 ) {
F_102 ( V_29 -> V_25 ) ;
F_70 ( V_29 -> V_52 -> V_25 ,
L_41 , V_14 ) ;
return V_14 ;
}
V_29 -> V_141 = 1 ;
return 0 ;
}
static int F_103 ( struct V_65 * V_52 , int V_125 ,
int V_138 )
{
struct V_28 * V_29 = & V_52 -> V_29 [ V_125 ] ;
struct V_63 * V_64 = V_29 -> V_64 ;
struct V_50 * V_51 ;
int V_3 , V_14 ;
V_51 = V_29 -> V_97 -> V_51 ;
if ( V_51 -> V_10 -> V_171 == V_138 ) {
V_14 = F_85 ( V_52 , V_51 ) ;
if ( V_14 < 0 )
return V_14 ;
}
for ( V_3 = 0 ; V_3 < V_29 -> V_89 ; V_3 ++ ) {
V_51 = V_29 -> V_90 [ V_3 ] -> V_51 ;
if ( V_51 -> V_10 -> V_171 == V_138 ) {
V_14 = F_85 ( V_52 , V_51 ) ;
if ( V_14 < 0 )
return V_14 ;
}
}
if ( V_64 -> V_51 . V_10 -> V_171 == V_138 ) {
V_14 = F_85 ( V_52 , & V_64 -> V_51 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
static int F_104 ( struct V_61 * V_62 , int V_138 )
{
int V_14 ;
if ( ! V_62 -> V_135 && V_62 -> V_10 -> V_171 == V_138 ) {
if ( V_62 -> V_10 -> V_155 ) {
V_14 = V_62 -> V_10 -> V_155 ( V_62 ) ;
if ( V_14 < 0 ) {
F_70 ( V_62 -> V_25 ,
L_42 ,
V_62 -> V_55 , V_14 ) ;
return V_14 ;
}
}
V_62 -> V_135 = 1 ;
}
return 0 ;
}
static int F_105 ( struct V_65 * V_52 ,
struct V_126 * V_73 ,
struct V_28 * V_29 )
{
struct V_61 * V_97 = V_29 -> V_97 ;
struct V_61 * V_119 = V_29 -> V_119 ;
struct V_172 * V_173 , * V_174 ;
int V_14 ;
if ( V_29 -> V_89 > 1 )
F_27 ( V_52 -> V_25 , L_43 ) ;
V_173 = V_119 -> V_175 ;
V_174 = V_97 -> V_176 ;
if ( V_173 && V_174 ) {
V_14 = F_106 ( V_52 , V_73 -> V_177 ,
V_73 -> V_178 , V_174 ,
V_173 ) ;
if ( V_14 != 0 ) {
F_70 ( V_52 -> V_25 , L_44 ,
V_173 -> V_55 , V_174 -> V_55 , V_14 ) ;
return V_14 ;
}
}
V_173 = V_97 -> V_175 ;
V_174 = V_119 -> V_176 ;
if ( V_173 && V_174 ) {
V_14 = F_106 ( V_52 , V_73 -> V_177 ,
V_73 -> V_178 , V_174 ,
V_173 ) ;
if ( V_14 != 0 ) {
F_70 ( V_52 -> V_25 , L_44 ,
V_173 -> V_55 , V_174 -> V_55 , V_14 ) ;
return V_14 ;
}
}
return 0 ;
}
static int F_107 ( struct V_65 * V_52 , int V_125 , int V_138 )
{
struct V_126 * V_73 = & V_52 -> V_73 [ V_125 ] ;
struct V_28 * V_29 = & V_52 -> V_29 [ V_125 ] ;
struct V_61 * V_97 = V_29 -> V_97 ;
int V_3 , V_14 ;
F_50 ( V_52 -> V_25 , L_45 ,
V_52 -> V_55 , V_125 , V_138 ) ;
V_29 -> V_31 = V_31 ;
V_14 = F_104 ( V_97 , V_138 ) ;
if ( V_14 )
return V_14 ;
for ( V_3 = 0 ; V_3 < V_29 -> V_89 ; V_3 ++ ) {
V_14 = F_104 ( V_29 -> V_90 [ V_3 ] , V_138 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_138 != V_143 )
return 0 ;
if ( V_73 -> V_179 ) {
V_14 = V_73 -> V_179 ( V_29 ) ;
if ( V_14 < 0 ) {
F_70 ( V_52 -> V_25 , L_46 ,
V_73 -> V_55 , V_14 ) ;
return V_14 ;
}
}
if ( V_73 -> V_180 )
F_108 ( V_29 , V_73 -> V_180 ) ;
V_14 = F_94 ( V_29 , V_73 -> V_55 ) ;
if ( V_14 )
return V_14 ;
#ifdef F_109
if ( V_73 -> V_181 )
F_110 ( V_29 ) ;
#endif
if ( V_97 -> V_10 -> V_182 ) {
V_14 = F_111 ( V_29 , V_125 ) ;
if ( V_14 < 0 ) {
F_70 ( V_52 -> V_25 , L_47 ,
V_73 -> V_183 ) ;
return V_14 ;
}
} else {
if ( ! V_73 -> V_177 ) {
V_14 = F_112 ( V_29 , V_125 ) ;
if ( V_14 < 0 ) {
F_70 ( V_52 -> V_25 , L_48 ,
V_73 -> V_183 , V_14 ) ;
return V_14 ;
}
} else {
F_113 ( & V_29 -> V_100 ,
F_52 ) ;
V_14 = F_105 ( V_52 , V_73 , V_29 ) ;
if ( V_14 )
return V_14 ;
}
}
return 0 ;
}
static int F_114 ( struct V_65 * V_52 , int V_125 )
{
struct V_28 * V_29 = & V_52 -> V_184 [ V_125 ] ;
struct V_185 * V_186 = & V_52 -> V_186 [ V_125 ] ;
const char * V_55 = V_186 -> V_187 ;
V_29 -> V_51 = F_71 ( V_186 -> V_188 , V_55 ) ;
if ( ! V_29 -> V_51 ) {
if ( V_186 -> V_188 )
V_55 = F_115 ( V_186 -> V_188 ) ;
F_70 ( V_52 -> V_25 , L_49 , V_55 ) ;
return - V_133 ;
}
V_29 -> V_5 = V_29 -> V_51 -> V_5 ;
return 0 ;
}
static int F_116 ( struct V_65 * V_52 , int V_125 )
{
struct V_28 * V_29 = & V_52 -> V_184 [ V_125 ] ;
struct V_185 * V_186 = & V_52 -> V_186 [ V_125 ] ;
int V_14 ;
V_14 = F_85 ( V_52 , V_29 -> V_51 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_186 -> V_179 ) {
V_14 = V_186 -> V_179 ( V_29 -> V_51 ) ;
if ( V_14 < 0 ) {
F_70 ( V_52 -> V_25 , L_46 ,
V_186 -> V_55 , V_14 ) ;
return V_14 ;
}
}
return F_94 ( V_29 , V_186 -> V_55 ) ;
}
static void F_117 ( struct V_65 * V_52 , int V_125 )
{
struct V_28 * V_29 = & V_52 -> V_184 [ V_125 ] ;
struct V_50 * V_51 = V_29 -> V_51 ;
if ( V_29 -> V_141 ) {
F_81 ( V_29 -> V_25 ) ;
V_29 -> V_141 = 0 ;
}
if ( V_51 && V_51 -> V_135 )
F_75 ( V_51 ) ;
}
static int F_118 ( struct V_4 * V_5 )
{
int V_14 ;
if ( V_5 -> V_189 )
return 0 ;
V_14 = F_119 ( V_5 ) ;
if ( V_14 < 0 ) {
F_70 ( V_5 -> V_25 ,
L_50 ,
V_14 ) ;
return V_14 ;
}
V_5 -> V_189 = 1 ;
return 0 ;
}
int F_108 ( struct V_28 * V_29 ,
unsigned int V_180 )
{
struct V_61 * * V_90 = V_29 -> V_90 ;
struct V_61 * V_97 = V_29 -> V_97 ;
unsigned int V_3 ;
int V_14 ;
for ( V_3 = 0 ; V_3 < V_29 -> V_89 ; V_3 ++ ) {
struct V_61 * V_119 = V_90 [ V_3 ] ;
V_14 = F_120 ( V_119 , V_180 ) ;
if ( V_14 != 0 && V_14 != - V_190 ) {
F_27 ( V_119 -> V_25 ,
L_51 , V_14 ) ;
return V_14 ;
}
}
if ( V_97 -> V_5 ) {
unsigned int V_191 ;
V_191 = V_180 & ~ V_192 ;
switch ( V_180 & V_192 ) {
case V_193 :
V_191 |= V_194 ;
break;
case V_195 :
V_191 |= V_196 ;
break;
case V_196 :
V_191 |= V_195 ;
break;
case V_194 :
V_191 |= V_193 ;
break;
}
V_180 = V_191 ;
}
V_14 = F_120 ( V_97 , V_180 ) ;
if ( V_14 != 0 && V_14 != - V_190 ) {
F_27 ( V_97 -> V_25 ,
L_51 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_121 ( struct V_65 * V_52 )
{
struct V_4 * V_5 ;
int V_14 , V_3 , V_138 ;
F_36 ( & V_60 ) ;
F_122 ( & V_52 -> V_197 , V_198 ) ;
for ( V_3 = 0 ; V_3 < V_52 -> V_75 ; V_3 ++ ) {
V_14 = F_74 ( V_52 , V_3 ) ;
if ( V_14 != 0 )
goto V_199;
}
for ( V_3 = 0 ; V_3 < V_52 -> V_200 ; V_3 ++ ) {
V_14 = F_114 ( V_52 , V_3 ) ;
if ( V_14 != 0 )
goto V_199;
}
F_37 (codec, &codec_list, list) {
if ( V_5 -> V_189 )
continue;
V_14 = F_118 ( V_5 ) ;
if ( V_14 < 0 )
goto V_199;
}
V_14 = F_123 ( V_52 -> V_25 , V_201 , V_202 ,
V_52 -> V_137 , 0 , & V_52 -> V_84 ) ;
if ( V_14 < 0 ) {
F_70 ( V_52 -> V_25 ,
L_52 ,
V_52 -> V_55 , V_14 ) ;
goto V_199;
}
F_42 ( V_52 ) ;
V_52 -> V_104 . V_106 = V_109 ;
V_52 -> V_104 . V_25 = V_52 -> V_25 ;
V_52 -> V_104 . V_52 = V_52 ;
F_92 ( & V_52 -> V_104 . V_160 , & V_52 -> V_161 ) ;
#ifdef F_109
F_28 ( & V_52 -> V_104 , V_52 -> V_53 ) ;
#endif
#ifdef F_124
F_125 ( & V_52 -> V_112 , F_65 ) ;
#endif
if ( V_52 -> V_152 )
F_87 ( & V_52 -> V_104 , V_52 -> V_152 ,
V_52 -> V_153 ) ;
if ( V_52 -> V_203 )
F_87 ( & V_52 -> V_104 , V_52 -> V_203 ,
V_52 -> V_204 ) ;
if ( V_52 -> V_155 ) {
V_14 = V_52 -> V_155 ( V_52 ) ;
if ( V_14 < 0 )
goto V_205;
}
for ( V_138 = V_142 ; V_138 <= V_143 ;
V_138 ++ ) {
for ( V_3 = 0 ; V_3 < V_52 -> V_75 ; V_3 ++ ) {
V_14 = F_103 ( V_52 , V_3 , V_138 ) ;
if ( V_14 < 0 ) {
F_70 ( V_52 -> V_25 ,
L_53 ,
V_14 ) ;
goto V_206;
}
}
}
for ( V_138 = V_142 ; V_138 <= V_143 ;
V_138 ++ ) {
for ( V_3 = 0 ; V_3 < V_52 -> V_75 ; V_3 ++ ) {
V_14 = F_107 ( V_52 , V_3 , V_138 ) ;
if ( V_14 < 0 ) {
F_70 ( V_52 -> V_25 ,
L_53 ,
V_14 ) ;
goto V_206;
}
}
}
for ( V_3 = 0 ; V_3 < V_52 -> V_200 ; V_3 ++ ) {
V_14 = F_116 ( V_52 , V_3 ) ;
if ( V_14 < 0 ) {
F_70 ( V_52 -> V_25 ,
L_54 ,
V_14 ) ;
goto V_207;
}
}
F_126 ( V_52 ) ;
F_127 ( V_52 ) ;
if ( V_52 -> V_156 )
F_128 ( V_52 , V_52 -> V_156 , V_52 -> V_157 ) ;
if ( V_52 -> V_158 )
F_91 ( & V_52 -> V_104 , V_52 -> V_158 ,
V_52 -> V_159 ) ;
if ( V_52 -> V_208 )
F_91 ( & V_52 -> V_104 , V_52 -> V_208 ,
V_52 -> V_209 ) ;
snprintf ( V_52 -> V_84 -> V_210 , sizeof( V_52 -> V_84 -> V_210 ) ,
L_40 , V_52 -> V_55 ) ;
snprintf ( V_52 -> V_84 -> V_211 , sizeof( V_52 -> V_84 -> V_211 ) ,
L_40 , V_52 -> V_212 ? V_52 -> V_212 : V_52 -> V_55 ) ;
snprintf ( V_52 -> V_84 -> V_10 , sizeof( V_52 -> V_84 -> V_10 ) ,
L_40 , V_52 -> V_213 ? V_52 -> V_213 : V_52 -> V_55 ) ;
for ( V_3 = 0 ; V_3 < F_129 ( V_52 -> V_84 -> V_10 ) ; V_3 ++ ) {
switch ( V_52 -> V_84 -> V_10 [ V_3 ] ) {
case '_' :
case '-' :
case '\0' :
break;
default:
if ( ! isalnum ( V_52 -> V_84 -> V_10 [ V_3 ] ) )
V_52 -> V_84 -> V_10 [ V_3 ] = '_' ;
break;
}
}
if ( V_52 -> V_214 ) {
V_14 = V_52 -> V_214 ( V_52 ) ;
if ( V_14 < 0 ) {
F_70 ( V_52 -> V_25 , L_55 ,
V_52 -> V_55 , V_14 ) ;
goto V_207;
}
}
F_130 ( V_52 ) ;
V_14 = F_131 ( V_52 -> V_84 ) ;
if ( V_14 < 0 ) {
F_70 ( V_52 -> V_25 , L_56 ,
V_14 ) ;
goto V_207;
}
V_52 -> V_83 = 1 ;
F_62 ( & V_52 -> V_104 ) ;
F_38 ( & V_52 -> V_197 ) ;
F_38 ( & V_60 ) ;
return 0 ;
V_207:
for ( V_3 = 0 ; V_3 < V_52 -> V_200 ; V_3 ++ )
F_117 ( V_52 , V_3 ) ;
V_206:
F_83 ( V_52 ) ;
V_205:
if ( V_52 -> remove )
V_52 -> remove ( V_52 ) ;
F_44 ( V_52 ) ;
F_132 ( V_52 -> V_84 ) ;
V_199:
F_38 ( & V_52 -> V_197 ) ;
F_38 ( & V_60 ) ;
return V_14 ;
}
static int F_133 ( struct V_215 * V_216 )
{
struct V_65 * V_52 = F_134 ( V_216 ) ;
if ( ! V_52 )
return - V_17 ;
F_27 ( & V_216 -> V_25 ,
L_57 ,
V_52 -> V_55 ) ;
V_52 -> V_25 = & V_216 -> V_25 ;
return F_135 ( V_52 ) ;
}
static int F_136 ( struct V_65 * V_52 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_52 -> V_87 ; V_3 ++ ) {
struct V_28 * V_29 = & V_52 -> V_29 [ V_3 ] ;
F_59 ( & V_29 -> V_100 ) ;
}
for ( V_3 = 0 ; V_3 < V_52 -> V_200 ; V_3 ++ )
F_117 ( V_52 , V_3 ) ;
F_83 ( V_52 ) ;
F_44 ( V_52 ) ;
if ( V_52 -> remove )
V_52 -> remove ( V_52 ) ;
F_77 ( & V_52 -> V_104 ) ;
F_132 ( V_52 -> V_84 ) ;
return 0 ;
}
static int F_137 ( struct V_215 * V_216 )
{
struct V_65 * V_52 = F_134 ( V_216 ) ;
F_138 ( V_52 ) ;
return 0 ;
}
int F_139 ( struct V_24 * V_25 )
{
struct V_65 * V_52 = F_8 ( V_25 ) ;
int V_3 ;
if ( ! V_52 -> V_83 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_52 -> V_87 ; V_3 ++ ) {
struct V_28 * V_29 = & V_52 -> V_29 [ V_3 ] ;
F_59 ( & V_29 -> V_100 ) ;
}
F_140 ( V_52 ) ;
for ( V_3 = 0 ; V_3 < V_52 -> V_87 ; V_3 ++ ) {
struct V_28 * V_29 = & V_52 -> V_29 [ V_3 ] ;
struct V_61 * V_97 = V_29 -> V_97 ;
int V_82 ;
F_64 ( V_97 -> V_25 ) ;
for ( V_82 = 0 ; V_82 < V_29 -> V_89 ; V_82 ++ ) {
struct V_61 * V_119 = V_29 -> V_90 [ V_82 ] ;
F_64 ( V_119 -> V_25 ) ;
}
}
return 0 ;
}
struct V_217 * F_141 ( const struct V_218 * V_219 ,
void * V_220 , const char * V_212 ,
const char * V_221 )
{
struct V_218 V_222 ;
struct V_217 * V_223 ;
char * V_55 = NULL ;
memcpy ( & V_222 , V_219 , sizeof( V_222 ) ) ;
V_222 . V_224 = 0 ;
if ( ! V_212 )
V_212 = V_222 . V_55 ;
if ( V_221 ) {
V_55 = F_25 ( V_42 , L_58 , V_221 , V_212 ) ;
if ( ! V_55 )
return NULL ;
V_222 . V_55 = V_55 ;
} else {
V_222 . V_55 = V_212 ;
}
V_223 = F_142 ( & V_222 , V_220 ) ;
F_17 ( V_55 ) ;
return V_223 ;
}
static int F_143 ( struct V_84 * V_52 , struct V_24 * V_25 ,
const struct V_218 * V_156 , int V_157 ,
const char * V_221 , void * V_220 )
{
int V_139 , V_3 ;
for ( V_3 = 0 ; V_3 < V_157 ; V_3 ++ ) {
const struct V_218 * V_225 = & V_156 [ V_3 ] ;
V_139 = F_144 ( V_52 , F_141 ( V_225 , V_220 ,
V_225 -> V_55 , V_221 ) ) ;
if ( V_139 < 0 ) {
F_70 ( V_25 , L_59 ,
V_225 -> V_55 , V_139 ) ;
return V_139 ;
}
}
return 0 ;
}
struct V_217 * F_145 ( struct V_65 * V_226 ,
const char * V_55 )
{
struct V_84 * V_52 = V_226 -> V_84 ;
struct V_217 * V_227 ;
if ( F_146 ( ! V_55 ) )
return NULL ;
F_37 (kctl, &card->controls, list)
if ( ! strncmp ( V_227 -> V_228 . V_55 , V_55 , sizeof( V_227 -> V_228 . V_55 ) ) )
return V_227 ;
return NULL ;
}
int F_90 ( struct V_50 * V_51 ,
const struct V_218 * V_156 , unsigned int V_157 )
{
struct V_84 * V_52 = V_51 -> V_52 -> V_84 ;
return F_143 ( V_52 , V_51 -> V_25 , V_156 ,
V_157 , V_51 -> V_149 , V_51 ) ;
}
int F_147 ( struct V_4 * V_5 ,
const struct V_218 * V_156 , unsigned int V_157 )
{
return F_90 ( & V_5 -> V_51 , V_156 ,
V_157 ) ;
}
int F_148 ( struct V_63 * V_64 ,
const struct V_218 * V_156 , unsigned int V_157 )
{
return F_90 ( & V_64 -> V_51 , V_156 ,
V_157 ) ;
}
int F_128 ( struct V_65 * V_226 ,
const struct V_218 * V_156 , int V_157 )
{
struct V_84 * V_52 = V_226 -> V_84 ;
return F_143 ( V_52 , V_226 -> V_25 , V_156 , V_157 ,
NULL , V_226 ) ;
}
int F_149 ( struct V_61 * V_62 ,
const struct V_218 * V_156 , int V_157 )
{
struct V_84 * V_52 = V_62 -> V_51 -> V_52 -> V_84 ;
return F_143 ( V_52 , V_62 -> V_25 , V_156 , V_157 ,
NULL , V_62 ) ;
}
int F_150 ( struct V_61 * V_62 , int V_229 ,
unsigned int V_230 , int V_231 )
{
if ( V_62 -> V_10 && V_62 -> V_10 -> V_93 -> V_232 )
return V_62 -> V_10 -> V_93 -> V_232 ( V_62 , V_229 , V_230 , V_231 ) ;
else if ( V_62 -> V_5 && V_62 -> V_5 -> V_10 -> V_232 )
return V_62 -> V_5 -> V_10 -> V_232 ( V_62 -> V_5 , V_229 , 0 ,
V_230 , V_231 ) ;
else
return - V_190 ;
}
int F_151 ( struct V_4 * V_5 , int V_229 ,
int V_233 , unsigned int V_230 , int V_231 )
{
if ( V_5 -> V_10 -> V_232 )
return V_5 -> V_10 -> V_232 ( V_5 , V_229 , V_233 ,
V_230 , V_231 ) ;
else
return - V_190 ;
}
int F_152 ( struct V_61 * V_62 ,
int V_234 , int div )
{
if ( V_62 -> V_10 && V_62 -> V_10 -> V_93 -> V_235 )
return V_62 -> V_10 -> V_93 -> V_235 ( V_62 , V_234 , div ) ;
else
return - V_17 ;
}
int F_153 ( struct V_61 * V_62 , int V_236 , int V_233 ,
unsigned int V_237 , unsigned int V_238 )
{
if ( V_62 -> V_10 && V_62 -> V_10 -> V_93 -> V_239 )
return V_62 -> V_10 -> V_93 -> V_239 ( V_62 , V_236 , V_233 ,
V_237 , V_238 ) ;
else if ( V_62 -> V_5 && V_62 -> V_5 -> V_10 -> V_239 )
return V_62 -> V_5 -> V_10 -> V_239 ( V_62 -> V_5 , V_236 , V_233 ,
V_237 , V_238 ) ;
else
return - V_17 ;
}
int F_154 ( struct V_4 * V_5 , int V_236 , int V_233 ,
unsigned int V_237 , unsigned int V_238 )
{
if ( V_5 -> V_10 -> V_239 )
return V_5 -> V_10 -> V_239 ( V_5 , V_236 , V_233 ,
V_237 , V_238 ) ;
else
return - V_17 ;
}
int F_155 ( struct V_61 * V_62 , unsigned int V_240 )
{
if ( V_62 -> V_10 && V_62 -> V_10 -> V_93 -> V_241 )
return V_62 -> V_10 -> V_93 -> V_241 ( V_62 , V_240 ) ;
else
return - V_17 ;
}
int F_120 ( struct V_61 * V_62 , unsigned int V_242 )
{
if ( V_62 -> V_10 == NULL )
return - V_17 ;
if ( V_62 -> V_10 -> V_93 -> V_243 == NULL )
return - V_190 ;
return V_62 -> V_10 -> V_93 -> V_243 ( V_62 , V_242 ) ;
}
static int F_156 ( unsigned int V_244 ,
unsigned int * V_245 ,
unsigned int * V_246 )
{
if ( * V_245 || * V_246 )
return 0 ;
if ( ! V_244 )
return - V_17 ;
* V_245 = ( 1 << V_244 ) - 1 ;
* V_246 = ( 1 << V_244 ) - 1 ;
return 0 ;
}
int F_157 ( struct V_61 * V_62 ,
unsigned int V_245 , unsigned int V_246 , int V_244 , int V_247 )
{
if ( V_62 -> V_10 && V_62 -> V_10 -> V_93 -> V_248 )
V_62 -> V_10 -> V_93 -> V_248 ( V_244 ,
& V_245 , & V_246 ) ;
else
F_156 ( V_244 , & V_245 , & V_246 ) ;
V_62 -> V_245 = V_245 ;
V_62 -> V_246 = V_246 ;
if ( V_62 -> V_10 && V_62 -> V_10 -> V_93 -> V_249 )
return V_62 -> V_10 -> V_93 -> V_249 ( V_62 , V_245 , V_246 ,
V_244 , V_247 ) ;
else
return - V_190 ;
}
int F_158 ( struct V_61 * V_62 ,
unsigned int V_250 , unsigned int * V_251 ,
unsigned int V_252 , unsigned int * V_253 )
{
if ( V_62 -> V_10 && V_62 -> V_10 -> V_93 -> V_254 )
return V_62 -> V_10 -> V_93 -> V_254 ( V_62 , V_250 , V_251 ,
V_252 , V_253 ) ;
else
return - V_17 ;
}
int F_159 ( struct V_61 * V_62 , int V_255 )
{
if ( V_62 -> V_10 && V_62 -> V_10 -> V_93 -> V_256 )
return V_62 -> V_10 -> V_93 -> V_256 ( V_62 , V_255 ) ;
else
return - V_17 ;
}
int F_160 ( struct V_61 * V_62 , int V_257 ,
int V_258 )
{
if ( ! V_62 -> V_10 )
return - V_190 ;
if ( V_62 -> V_10 -> V_93 -> V_259 )
return V_62 -> V_10 -> V_93 -> V_259 ( V_62 , V_257 , V_258 ) ;
else if ( V_258 == V_101 &&
V_62 -> V_10 -> V_93 -> V_94 )
return V_62 -> V_10 -> V_93 -> V_94 ( V_62 , V_257 ) ;
else
return - V_190 ;
}
static int F_161 ( struct V_65 * V_52 ,
struct V_126 * V_73 )
{
if ( V_73 -> V_187 || V_73 -> V_188 ||
V_73 -> V_260 ) {
V_73 -> V_89 = 1 ;
V_73 -> V_127 = F_162 ( V_52 -> V_25 ,
sizeof( struct V_122 ) ,
V_42 ) ;
if ( ! V_73 -> V_127 )
return - V_43 ;
V_73 -> V_127 [ 0 ] . V_55 = V_73 -> V_187 ;
V_73 -> V_127 [ 0 ] . V_121 = V_73 -> V_188 ;
V_73 -> V_127 [ 0 ] . V_124 = V_73 -> V_260 ;
}
if ( ! V_73 -> V_127 ) {
F_70 ( V_52 -> V_25 , L_60 ) ;
return - V_17 ;
}
return 0 ;
}
int F_135 ( struct V_65 * V_52 )
{
int V_3 , V_82 , V_14 ;
if ( ! V_52 -> V_55 || ! V_52 -> V_25 )
return - V_17 ;
for ( V_3 = 0 ; V_3 < V_52 -> V_75 ; V_3 ++ ) {
struct V_126 * V_261 = & V_52 -> V_73 [ V_3 ] ;
V_14 = F_161 ( V_52 , V_261 ) ;
if ( V_14 ) {
F_70 ( V_52 -> V_25 , L_61 ) ;
return V_14 ;
}
for ( V_82 = 0 ; V_82 < V_261 -> V_89 ; V_82 ++ ) {
if ( ! ! V_261 -> V_127 [ V_82 ] . V_55 ==
! ! V_261 -> V_127 [ V_82 ] . V_121 ) {
F_70 ( V_52 -> V_25 , L_62 ,
V_261 -> V_55 ) ;
return - V_17 ;
}
if ( ! V_261 -> V_127 [ V_82 ] . V_124 ) {
F_70 ( V_52 -> V_25 , L_63 ,
V_261 -> V_55 ) ;
return - V_17 ;
}
}
if ( V_261 -> V_129 && V_261 -> V_134 ) {
F_70 ( V_52 -> V_25 ,
L_64 ,
V_261 -> V_55 ) ;
return - V_17 ;
}
if ( V_261 -> V_130 && V_261 -> V_131 ) {
F_70 ( V_52 -> V_25 ,
L_65 ,
V_261 -> V_55 ) ;
return - V_17 ;
}
if ( ! V_261 -> V_132 &&
! ( V_261 -> V_130 || V_261 -> V_131 ) ) {
F_70 ( V_52 -> V_25 ,
L_66 ,
V_261 -> V_55 ) ;
return - V_17 ;
}
}
F_98 ( V_52 -> V_25 , V_52 ) ;
F_163 ( V_52 ) ;
V_52 -> V_29 = F_162 ( V_52 -> V_25 ,
sizeof( struct V_28 ) *
( V_52 -> V_75 + V_52 -> V_200 ) ,
V_42 ) ;
if ( V_52 -> V_29 == NULL )
return - V_43 ;
V_52 -> V_87 = 0 ;
V_52 -> V_184 = & V_52 -> V_29 [ V_52 -> V_75 ] ;
for ( V_3 = 0 ; V_3 < V_52 -> V_75 ; V_3 ++ ) {
V_52 -> V_29 [ V_3 ] . V_52 = V_52 ;
V_52 -> V_29 [ V_3 ] . V_73 = & V_52 -> V_73 [ V_3 ] ;
V_52 -> V_29 [ V_3 ] . V_90 = F_162 ( V_52 -> V_25 ,
sizeof( struct V_61 * ) *
( V_52 -> V_29 [ V_3 ] . V_73 -> V_89 ) ,
V_42 ) ;
if ( V_52 -> V_29 [ V_3 ] . V_90 == NULL )
return - V_43 ;
}
for ( V_3 = 0 ; V_3 < V_52 -> V_200 ; V_3 ++ )
V_52 -> V_184 [ V_3 ] . V_52 = V_52 ;
F_100 ( & V_52 -> V_262 ) ;
V_52 -> V_83 = 0 ;
F_99 ( & V_52 -> V_197 ) ;
F_99 ( & V_52 -> V_263 ) ;
V_14 = F_121 ( V_52 ) ;
if ( V_14 != 0 )
return V_14 ;
for ( V_3 = 0 ; V_3 < V_52 -> V_87 ; V_3 ++ ) {
struct V_28 * V_29 = & V_52 -> V_29 [ V_3 ] ;
struct V_61 * V_97 = V_29 -> V_97 ;
int V_82 ;
for ( V_82 = 0 ; V_82 < V_29 -> V_89 ; V_82 ++ ) {
struct V_61 * V_119 = V_29 -> V_90 [ V_82 ] ;
if ( ! V_119 -> V_118 )
F_64 ( V_119 -> V_25 ) ;
}
if ( ! V_97 -> V_118 )
F_64 ( V_97 -> V_25 ) ;
}
return V_14 ;
}
int F_138 ( struct V_65 * V_52 )
{
if ( V_52 -> V_83 ) {
V_52 -> V_83 = false ;
F_140 ( V_52 ) ;
F_136 ( V_52 ) ;
F_50 ( V_52 -> V_25 , L_67 , V_52 -> V_55 ) ;
}
return 0 ;
}
static char * F_164 ( struct V_24 * V_25 , int * V_228 )
{
char * V_264 , V_55 [ V_265 ] ;
int V_266 , V_267 ;
if ( V_148 ( V_25 ) == NULL )
return NULL ;
F_165 ( V_55 , V_148 ( V_25 ) , V_265 ) ;
V_264 = strstr ( V_55 , V_25 -> V_10 -> V_55 ) ;
if ( V_264 ) {
if ( sscanf ( & V_264 [ strlen ( V_25 -> V_10 -> V_55 ) ] , L_68 , V_228 ) == 1 ) {
if ( * V_228 == - 1 )
V_264 [ strlen ( V_25 -> V_10 -> V_55 ) ] = '\0' ;
}
} else {
if ( sscanf ( V_55 , L_69 , & V_266 , & V_267 ) == 2 ) {
char V_268 [ V_265 ] ;
* V_228 = ( ( V_266 & 0xffff ) << 16 ) + V_267 ;
snprintf ( V_268 , V_265 , L_70 , V_25 -> V_10 -> V_55 , V_55 ) ;
F_165 ( V_55 , V_268 , V_265 ) ;
} else
* V_228 = 0 ;
}
return F_166 ( V_55 , V_42 ) ;
}
static inline char * F_167 ( struct V_24 * V_25 ,
struct V_91 * V_269 )
{
if ( V_269 -> V_55 == NULL ) {
F_70 ( V_25 ,
L_71 ,
V_148 ( V_25 ) ) ;
return NULL ;
}
return F_166 ( V_269 -> V_55 , V_42 ) ;
}
static void F_168 ( struct V_50 * V_51 )
{
struct V_61 * V_62 , * V_270 ;
F_169 (dai, _dai, &component->dai_list, list) {
F_50 ( V_51 -> V_25 , L_72 ,
V_62 -> V_55 ) ;
F_76 ( & V_62 -> V_160 ) ;
F_17 ( V_62 -> V_55 ) ;
F_17 ( V_62 ) ;
}
}
static int F_170 ( struct V_50 * V_51 ,
struct V_91 * V_269 , T_1 V_18 ,
bool V_271 )
{
struct V_24 * V_25 = V_51 -> V_25 ;
struct V_61 * V_62 ;
unsigned int V_3 ;
int V_14 ;
F_50 ( V_25 , L_73 , V_148 ( V_25 ) , V_18 ) ;
V_51 -> V_269 = V_269 ;
V_51 -> V_272 = V_18 ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ ) {
V_62 = F_95 ( sizeof( struct V_61 ) , V_42 ) ;
if ( V_62 == NULL ) {
V_14 = - V_43 ;
goto V_139;
}
if ( V_18 == 1 && V_271 ) {
V_62 -> V_55 = F_164 ( V_25 , & V_62 -> V_228 ) ;
} else {
V_62 -> V_55 = F_167 ( V_25 , & V_269 [ V_3 ] ) ;
if ( V_269 [ V_3 ] . V_228 )
V_62 -> V_228 = V_269 [ V_3 ] . V_228 ;
else
V_62 -> V_228 = V_3 ;
}
if ( V_62 -> V_55 == NULL ) {
F_17 ( V_62 ) ;
V_14 = - V_43 ;
goto V_139;
}
V_62 -> V_51 = V_51 ;
V_62 -> V_25 = V_25 ;
V_62 -> V_10 = & V_269 [ V_3 ] ;
if ( ! V_62 -> V_10 -> V_93 )
V_62 -> V_10 -> V_93 = & V_273 ;
F_92 ( & V_62 -> V_160 , & V_51 -> V_274 ) ;
F_50 ( V_25 , L_74 , V_62 -> V_55 ) ;
}
return 0 ;
V_139:
F_168 ( V_51 ) ;
return V_14 ;
}
static void F_171 ( struct V_150 * V_104 ,
enum V_275 type , int V_276 )
{
struct V_50 * V_51 = V_104 -> V_51 ;
V_51 -> V_10 -> V_277 ( V_51 , type , V_276 ) ;
}
static int F_172 ( struct V_150 * V_104 ,
int V_278 )
{
struct V_50 * V_51 = V_104 -> V_51 ;
return V_51 -> V_10 -> V_279 ( V_51 , V_278 ) ;
}
static int F_173 ( struct V_50 * V_51 ,
const struct V_280 * V_10 , struct V_24 * V_25 )
{
struct V_150 * V_104 ;
V_51 -> V_55 = F_164 ( V_25 , & V_51 -> V_228 ) ;
if ( ! V_51 -> V_55 ) {
F_70 ( V_25 , L_75 ) ;
return - V_43 ;
}
V_51 -> V_25 = V_25 ;
V_51 -> V_10 = V_10 ;
V_51 -> V_155 = V_51 -> V_10 -> V_155 ;
V_51 -> remove = V_51 -> V_10 -> remove ;
if ( ! V_51 -> V_281 )
V_51 -> V_281 = & V_51 -> V_104 ;
V_104 = V_51 -> V_281 ;
V_104 -> V_25 = V_25 ;
V_104 -> V_51 = V_51 ;
V_104 -> V_106 = V_109 ;
V_104 -> V_108 = true ;
if ( V_10 -> V_277 )
V_104 -> V_277 = F_171 ;
if ( V_10 -> V_279 )
V_104 -> V_279 = F_172 ;
V_51 -> V_156 = V_10 -> V_156 ;
V_51 -> V_157 = V_10 -> V_157 ;
V_51 -> V_152 = V_10 -> V_152 ;
V_51 -> V_153 = V_10 -> V_153 ;
V_51 -> V_158 = V_10 -> V_158 ;
V_51 -> V_159 = V_10 -> V_159 ;
F_100 ( & V_51 -> V_274 ) ;
F_99 ( & V_51 -> V_282 ) ;
return 0 ;
}
static void F_174 ( struct V_50 * V_51 )
{
int V_283 = F_175 ( V_51 -> V_110 ) ;
if ( V_283 > 0 )
V_51 -> V_283 = V_283 ;
}
void F_176 ( struct V_50 * V_51 ,
struct V_110 * V_110 )
{
V_51 -> V_110 = V_110 ;
F_174 ( V_51 ) ;
}
void F_177 ( struct V_50 * V_51 )
{
F_178 ( V_51 -> V_110 ) ;
V_51 -> V_110 = NULL ;
}
static void F_179 ( struct V_50 * V_51 )
{
if ( ! V_51 -> V_284 && ! V_51 -> V_285 ) {
if ( ! V_51 -> V_110 )
V_51 -> V_110 = F_180 ( V_51 -> V_25 , NULL ) ;
if ( V_51 -> V_110 )
F_174 ( V_51 ) ;
}
F_92 ( & V_51 -> V_160 , & V_286 ) ;
}
static void F_181 ( struct V_50 * V_51 )
{
F_36 ( & V_60 ) ;
F_179 ( V_51 ) ;
F_38 ( & V_60 ) ;
}
static void F_182 ( struct V_50 * V_51 )
{
F_168 ( V_51 ) ;
F_17 ( V_51 -> V_55 ) ;
}
static void F_183 ( struct V_50 * V_51 )
{
F_76 ( & V_51 -> V_160 ) ;
}
int F_184 ( struct V_24 * V_25 ,
const struct V_280 * V_287 ,
struct V_91 * V_269 ,
int V_272 )
{
struct V_50 * V_288 ;
int V_14 ;
V_288 = F_95 ( sizeof( * V_288 ) , V_42 ) ;
if ( ! V_288 ) {
F_70 ( V_25 , L_76 ) ;
return - V_43 ;
}
V_14 = F_173 ( V_288 , V_287 , V_25 ) ;
if ( V_14 )
goto V_289;
V_288 -> V_290 = true ;
V_288 -> V_291 = true ;
V_14 = F_170 ( V_288 , V_269 , V_272 , true ) ;
if ( V_14 < 0 ) {
F_70 ( V_25 , L_77 , V_14 ) ;
goto V_292;
}
F_181 ( V_288 ) ;
return 0 ;
V_292:
F_182 ( V_288 ) ;
V_289:
F_17 ( V_288 ) ;
return V_14 ;
}
void F_185 ( struct V_24 * V_25 )
{
struct V_50 * V_288 ;
F_36 ( & V_60 ) ;
F_37 (cmpnt, &component_list, list) {
if ( V_25 == V_288 -> V_25 && V_288 -> V_291 )
goto V_264;
}
F_38 ( & V_60 ) ;
return;
V_264:
F_183 ( V_288 ) ;
F_38 ( & V_60 ) ;
F_182 ( V_288 ) ;
F_17 ( V_288 ) ;
}
static int F_186 ( struct V_50 * V_51 )
{
struct V_63 * V_64 = F_187 ( V_51 ) ;
return V_64 -> V_10 -> V_155 ( V_64 ) ;
}
static void F_188 ( struct V_50 * V_51 )
{
struct V_63 * V_64 = F_187 ( V_51 ) ;
V_64 -> V_10 -> remove ( V_64 ) ;
}
int F_189 ( struct V_24 * V_25 , struct V_63 * V_64 ,
const struct V_293 * V_294 )
{
int V_14 ;
V_14 = F_173 ( & V_64 -> V_51 ,
& V_294 -> V_295 , V_25 ) ;
if ( V_14 )
return V_14 ;
V_64 -> V_25 = V_25 ;
V_64 -> V_10 = V_294 ;
if ( V_294 -> V_155 )
V_64 -> V_51 . V_155 = F_186 ;
if ( V_294 -> remove )
V_64 -> V_51 . remove = F_188 ;
#ifdef F_109
V_64 -> V_51 . V_54 = L_78 ;
#endif
F_36 ( & V_60 ) ;
F_179 ( & V_64 -> V_51 ) ;
F_92 ( & V_64 -> V_160 , & V_296 ) ;
F_38 ( & V_60 ) ;
F_50 ( V_25 , L_79 ,
V_64 -> V_51 . V_55 ) ;
return 0 ;
}
int F_190 ( struct V_24 * V_25 ,
const struct V_293 * V_294 )
{
struct V_63 * V_64 ;
int V_14 ;
F_50 ( V_25 , L_80 , V_148 ( V_25 ) ) ;
V_64 = F_95 ( sizeof( struct V_63 ) , V_42 ) ;
if ( V_64 == NULL )
return - V_43 ;
V_14 = F_189 ( V_25 , V_64 , V_294 ) ;
if ( V_14 )
F_17 ( V_64 ) ;
return V_14 ;
}
void F_191 ( struct V_63 * V_64 )
{
F_36 ( & V_60 ) ;
F_76 ( & V_64 -> V_160 ) ;
F_183 ( & V_64 -> V_51 ) ;
F_38 ( & V_60 ) ;
F_50 ( V_64 -> V_25 , L_81 ,
V_64 -> V_51 . V_55 ) ;
F_182 ( & V_64 -> V_51 ) ;
}
struct V_63 * F_192 ( struct V_24 * V_25 )
{
struct V_63 * V_64 ;
F_36 ( & V_60 ) ;
F_37 (platform, &platform_list, list) {
if ( V_25 == V_64 -> V_25 ) {
F_38 ( & V_60 ) ;
return V_64 ;
}
}
F_38 ( & V_60 ) ;
return NULL ;
}
void F_193 ( struct V_24 * V_25 )
{
struct V_63 * V_64 ;
V_64 = F_192 ( V_25 ) ;
if ( ! V_64 )
return;
F_191 ( V_64 ) ;
F_17 ( V_64 ) ;
}
static void F_194 ( struct V_297 * V_74 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_129 ( V_298 ) ; V_3 ++ )
if ( V_74 -> V_299 & V_298 [ V_3 ] )
V_74 -> V_299 |= V_298 [ V_3 ] ;
}
static int F_195 ( struct V_50 * V_51 )
{
struct V_4 * V_5 = F_33 ( V_51 ) ;
return V_5 -> V_10 -> V_155 ( V_5 ) ;
}
static void F_196 ( struct V_50 * V_51 )
{
struct V_4 * V_5 = F_33 ( V_51 ) ;
V_5 -> V_10 -> remove ( V_5 ) ;
}
static int F_197 ( struct V_50 * V_51 ,
unsigned int V_6 , unsigned int V_1 )
{
struct V_4 * V_5 = F_33 ( V_51 ) ;
return V_5 -> V_10 -> V_284 ( V_5 , V_6 , V_1 ) ;
}
static int F_198 ( struct V_50 * V_51 ,
unsigned int V_6 , unsigned int * V_1 )
{
struct V_4 * V_5 = F_33 ( V_51 ) ;
* V_1 = V_5 -> V_10 -> V_285 ( V_5 , V_6 ) ;
return 0 ;
}
static int F_199 ( struct V_150 * V_104 ,
enum V_300 V_301 )
{
struct V_4 * V_5 = F_200 ( V_104 ) ;
return V_5 -> V_10 -> V_302 ( V_5 , V_301 ) ;
}
int F_201 ( struct V_24 * V_25 ,
const struct V_303 * V_304 ,
struct V_91 * V_269 ,
int V_272 )
{
struct V_4 * V_5 ;
struct V_61 * V_62 ;
int V_14 , V_3 ;
F_50 ( V_25 , L_82 , V_148 ( V_25 ) ) ;
V_5 = F_95 ( sizeof( struct V_4 ) , V_42 ) ;
if ( V_5 == NULL )
return - V_43 ;
V_5 -> V_51 . V_281 = & V_5 -> V_104 ;
V_5 -> V_51 . V_5 = V_5 ;
V_14 = F_173 ( & V_5 -> V_51 ,
& V_304 -> V_295 , V_25 ) ;
if ( V_14 )
goto V_289;
if ( V_304 -> V_156 ) {
V_5 -> V_51 . V_156 = V_304 -> V_156 ;
V_5 -> V_51 . V_157 = V_304 -> V_157 ;
}
if ( V_304 -> V_152 ) {
V_5 -> V_51 . V_152 = V_304 -> V_152 ;
V_5 -> V_51 . V_153 = V_304 -> V_153 ;
}
if ( V_304 -> V_158 ) {
V_5 -> V_51 . V_158 = V_304 -> V_158 ;
V_5 -> V_51 . V_159 = V_304 -> V_159 ;
}
if ( V_304 -> V_155 )
V_5 -> V_51 . V_155 = F_195 ;
if ( V_304 -> remove )
V_5 -> V_51 . remove = F_196 ;
if ( V_304 -> V_284 )
V_5 -> V_51 . V_284 = F_197 ;
if ( V_304 -> V_285 )
V_5 -> V_51 . V_285 = F_198 ;
V_5 -> V_51 . V_290 = V_304 -> V_290 ;
V_5 -> V_104 . V_108 = V_304 -> V_108 ;
V_5 -> V_104 . V_305 = V_304 -> V_305 ;
if ( V_304 -> V_277 )
V_5 -> V_104 . V_277 = V_304 -> V_277 ;
if ( V_304 -> V_302 )
V_5 -> V_104 . V_302 = F_199 ;
V_5 -> V_25 = V_25 ;
V_5 -> V_10 = V_304 ;
V_5 -> V_51 . V_283 = V_304 -> V_13 ;
#ifdef F_109
V_5 -> V_51 . V_57 = F_32 ;
V_5 -> V_51 . V_54 = L_83 ;
#endif
if ( V_304 -> V_306 )
V_5 -> V_51 . V_110 = V_304 -> V_306 ( V_25 ) ;
for ( V_3 = 0 ; V_3 < V_272 ; V_3 ++ ) {
F_194 ( & V_269 [ V_3 ] . V_307 ) ;
F_194 ( & V_269 [ V_3 ] . V_308 ) ;
}
V_14 = F_170 ( & V_5 -> V_51 , V_269 , V_272 , false ) ;
if ( V_14 < 0 ) {
F_70 ( V_25 , L_77 , V_14 ) ;
goto V_292;
}
F_37 (dai, &codec->component.dai_list, list)
V_62 -> V_5 = V_5 ;
F_36 ( & V_60 ) ;
F_179 ( & V_5 -> V_51 ) ;
F_92 ( & V_5 -> V_160 , & V_309 ) ;
F_38 ( & V_60 ) ;
F_50 ( V_5 -> V_25 , L_84 ,
V_5 -> V_51 . V_55 ) ;
return 0 ;
V_292:
F_182 ( & V_5 -> V_51 ) ;
V_289:
F_17 ( V_5 ) ;
return V_14 ;
}
void F_202 ( struct V_24 * V_25 )
{
struct V_4 * V_5 ;
F_36 ( & V_60 ) ;
F_37 (codec, &codec_list, list) {
if ( V_25 == V_5 -> V_25 )
goto V_264;
}
F_38 ( & V_60 ) ;
return;
V_264:
F_76 ( & V_5 -> V_160 ) ;
F_183 ( & V_5 -> V_51 ) ;
F_38 ( & V_60 ) ;
F_50 ( V_5 -> V_25 , L_85 ,
V_5 -> V_51 . V_55 ) ;
F_182 ( & V_5 -> V_51 ) ;
F_203 ( V_5 ) ;
F_17 ( V_5 ) ;
}
int F_204 ( struct V_65 * V_52 ,
const char * V_310 )
{
struct V_120 * V_311 ;
int V_14 ;
if ( ! V_52 -> V_25 ) {
F_205 ( L_86 , V_312 ) ;
return - V_17 ;
}
V_311 = V_52 -> V_25 -> V_121 ;
V_14 = F_206 ( V_311 , V_310 , 0 , & V_52 -> V_55 ) ;
if ( V_14 < 0 && V_14 != - V_17 ) {
F_70 ( V_52 -> V_25 ,
L_87 ,
V_310 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
int F_207 ( struct V_65 * V_52 ,
const char * V_310 )
{
struct V_120 * V_311 = V_52 -> V_25 -> V_121 ;
struct V_172 * V_313 ;
const char * V_222 , * V_314 ;
int V_3 , V_82 , V_315 , V_14 ;
V_315 = F_208 ( V_311 , V_310 ) ;
if ( V_315 < 0 ) {
F_70 ( V_52 -> V_25 ,
L_88 , V_310 ) ;
return - V_17 ;
}
if ( V_315 & 1 ) {
F_70 ( V_52 -> V_25 ,
L_89 , V_310 ) ;
return - V_17 ;
}
V_315 /= 2 ;
if ( ! V_315 ) {
F_70 ( V_52 -> V_25 , L_90 ,
V_310 ) ;
return - V_17 ;
}
V_313 = F_209 ( V_52 -> V_25 , V_315 , sizeof( * V_313 ) ,
V_42 ) ;
if ( ! V_313 ) {
F_70 ( V_52 -> V_25 ,
L_91 ) ;
return - V_43 ;
}
for ( V_3 = 0 ; V_3 < V_315 ; V_3 ++ ) {
V_14 = F_206 ( V_311 , V_310 ,
2 * V_3 , & V_222 ) ;
if ( V_14 ) {
F_70 ( V_52 -> V_25 ,
L_92 ,
V_310 , 2 * V_3 , V_14 ) ;
return - V_17 ;
}
for ( V_82 = 0 ; V_82 < F_129 ( V_316 ) ; V_82 ++ ) {
if ( ! strncmp ( V_222 , V_316 [ V_82 ] . V_55 ,
strlen ( V_316 [ V_82 ] . V_55 ) ) ) {
V_313 [ V_3 ] = V_316 [ V_82 ] ;
break;
}
}
if ( V_82 >= F_129 ( V_316 ) ) {
F_70 ( V_52 -> V_25 ,
L_93 ,
V_222 ) ;
return - V_17 ;
}
V_14 = F_206 ( V_311 , V_310 ,
( 2 * V_3 ) + 1 ,
& V_314 ) ;
if ( V_14 ) {
F_70 ( V_52 -> V_25 ,
L_92 ,
V_310 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_17 ;
}
V_313 [ V_3 ] . V_55 = V_314 ;
}
V_52 -> V_203 = V_313 ;
V_52 -> V_204 = V_315 ;
return 0 ;
}
int F_210 ( struct V_120 * V_311 ,
unsigned int * V_244 ,
unsigned int * V_247 )
{
T_6 V_1 ;
int V_14 ;
if ( F_211 ( V_311 , L_94 ) ) {
V_14 = F_212 ( V_311 , L_94 , & V_1 ) ;
if ( V_14 )
return V_14 ;
if ( V_244 )
* V_244 = V_1 ;
}
if ( F_211 ( V_311 , L_95 ) ) {
V_14 = F_212 ( V_311 , L_95 , & V_1 ) ;
if ( V_14 )
return V_14 ;
if ( V_247 )
* V_247 = V_1 ;
}
return 0 ;
}
int F_213 ( struct V_65 * V_52 ,
const char * V_310 )
{
struct V_120 * V_311 = V_52 -> V_25 -> V_121 ;
int V_317 ;
struct V_318 * V_319 ;
int V_3 , V_14 ;
V_317 = F_208 ( V_311 , V_310 ) ;
if ( V_317 < 0 || V_317 & 1 ) {
F_70 ( V_52 -> V_25 ,
L_96 ,
V_310 ) ;
return - V_17 ;
}
V_317 /= 2 ;
if ( ! V_317 ) {
F_70 ( V_52 -> V_25 , L_90 ,
V_310 ) ;
return - V_17 ;
}
V_319 = F_162 ( V_52 -> V_25 , V_317 * sizeof( * V_319 ) ,
V_42 ) ;
if ( ! V_319 ) {
F_70 ( V_52 -> V_25 ,
L_97 ) ;
return - V_17 ;
}
for ( V_3 = 0 ; V_3 < V_317 ; V_3 ++ ) {
V_14 = F_206 ( V_311 , V_310 ,
2 * V_3 , & V_319 [ V_3 ] . V_320 ) ;
if ( V_14 ) {
F_70 ( V_52 -> V_25 ,
L_98 ,
V_310 , 2 * V_3 , V_14 ) ;
return - V_17 ;
}
V_14 = F_206 ( V_311 , V_310 ,
( 2 * V_3 ) + 1 , & V_319 [ V_3 ] . V_233 ) ;
if ( V_14 ) {
F_70 ( V_52 -> V_25 ,
L_98 ,
V_310 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_17 ;
}
}
V_52 -> V_209 = V_317 ;
V_52 -> V_208 = V_319 ;
return 0 ;
}
unsigned int F_214 ( struct V_120 * V_311 ,
const char * V_221 ,
struct V_120 * * V_321 ,
struct V_120 * * V_322 )
{
int V_14 , V_3 ;
char V_323 [ 128 ] ;
unsigned int V_324 = 0 ;
int V_325 , V_326 ;
const char * V_327 ;
struct {
char * V_55 ;
unsigned int V_1 ;
} V_328 [] = {
{ L_99 , V_329 } ,
{ L_100 , V_330 } ,
{ L_101 , V_331 } ,
{ L_102 , V_332 } ,
{ L_103 , V_333 } ,
{ L_104 , V_334 } ,
{ L_105 , V_335 } ,
{ L_106 , V_336 } ,
{ L_107 , V_337 } ,
} ;
if ( ! V_221 )
V_221 = L_108 ;
snprintf ( V_323 , sizeof( V_323 ) , L_109 , V_221 ) ;
V_14 = F_215 ( V_311 , V_323 , & V_327 ) ;
if ( V_14 == 0 ) {
for ( V_3 = 0 ; V_3 < F_129 ( V_328 ) ; V_3 ++ ) {
if ( strcmp ( V_327 , V_328 [ V_3 ] . V_55 ) == 0 ) {
V_324 |= V_328 [ V_3 ] . V_1 ;
break;
}
}
}
snprintf ( V_323 , sizeof( V_323 ) , L_110 , V_221 ) ;
if ( F_216 ( V_311 , V_323 , NULL ) )
V_324 |= V_338 ;
else
V_324 |= V_339 ;
snprintf ( V_323 , sizeof( V_323 ) , L_111 , V_221 ) ;
V_325 = ! ! F_216 ( V_311 , V_323 , NULL ) ;
snprintf ( V_323 , sizeof( V_323 ) , L_112 , V_221 ) ;
V_326 = ! ! F_216 ( V_311 , V_323 , NULL ) ;
switch ( ( V_325 << 4 ) + V_326 ) {
case 0x11 :
V_324 |= V_340 ;
break;
case 0x10 :
V_324 |= V_341 ;
break;
case 0x01 :
V_324 |= V_342 ;
break;
default:
break;
}
snprintf ( V_323 , sizeof( V_323 ) , L_113 , V_221 ) ;
V_325 = ! ! F_216 ( V_311 , V_323 , NULL ) ;
if ( V_325 && V_321 )
* V_321 = F_217 ( V_311 , V_323 , 0 ) ;
snprintf ( V_323 , sizeof( V_323 ) , L_114 , V_221 ) ;
V_326 = ! ! F_216 ( V_311 , V_323 , NULL ) ;
if ( V_326 && V_322 )
* V_322 = F_217 ( V_311 , V_323 , 0 ) ;
switch ( ( V_325 << 4 ) + V_326 ) {
case 0x11 :
V_324 |= V_193 ;
break;
case 0x10 :
V_324 |= V_195 ;
break;
case 0x01 :
V_324 |= V_196 ;
break;
default:
V_324 |= V_194 ;
break;
}
return V_324 ;
}
static int F_218 ( struct V_343 * args ,
const char * * V_124 )
{
struct V_50 * V_19 ;
int V_14 = - V_133 ;
F_36 ( & V_60 ) ;
F_37 (pos, &component_list, list) {
if ( V_19 -> V_25 -> V_121 != args -> V_311 )
continue;
if ( V_19 -> V_10 -> V_344 ) {
V_14 = V_19 -> V_10 -> V_344 ( V_19 ,
args ,
V_124 ) ;
} else {
int V_228 = - 1 ;
switch ( args -> V_345 ) {
case 0 :
V_228 = 0 ;
break;
case 1 :
V_228 = args -> args [ 0 ] ;
break;
default:
break;
}
if ( V_228 < 0 || V_228 >= V_19 -> V_272 ) {
V_14 = - V_17 ;
continue;
}
V_14 = 0 ;
* V_124 = V_19 -> V_269 [ V_228 ] . V_55 ;
if ( ! * V_124 )
* V_124 = V_19 -> V_55 ;
}
break;
}
F_38 ( & V_60 ) ;
return V_14 ;
}
int F_219 ( struct V_120 * V_121 ,
const char * * V_124 )
{
struct V_343 args ;
int V_14 ;
V_14 = F_220 ( V_121 , L_115 ,
L_116 , 0 , & args ) ;
if ( V_14 )
return V_14 ;
V_14 = F_218 ( & args , V_124 ) ;
F_221 ( args . V_311 ) ;
return V_14 ;
}
int F_222 ( struct V_24 * V_25 ,
struct V_120 * V_121 ,
struct V_126 * V_73 )
{
struct V_343 args ;
struct V_122 * V_51 ;
char * V_55 ;
int V_224 , V_89 , V_14 ;
V_55 = L_115 ;
V_89 = F_223 ( V_121 , V_55 ,
L_116 ) ;
if ( V_89 <= 0 ) {
if ( V_89 == - V_346 )
F_70 ( V_25 , L_117 ) ;
else
F_70 ( V_25 , L_118 ) ;
return V_89 ;
}
V_51 = F_162 ( V_25 ,
sizeof *V_51 * V_89 ,
V_42 ) ;
if ( ! V_51 )
return - V_43 ;
V_73 -> V_127 = V_51 ;
V_73 -> V_89 = V_89 ;
for ( V_224 = 0 , V_51 = V_73 -> V_127 ;
V_224 < V_73 -> V_89 ;
V_224 ++ , V_51 ++ ) {
V_14 = F_220 ( V_121 , V_55 ,
L_116 ,
V_224 , & args ) ;
if ( V_14 )
goto V_139;
V_51 -> V_121 = args . V_311 ;
V_14 = F_218 ( & args , & V_51 -> V_124 ) ;
if ( V_14 < 0 )
goto V_139;
}
return 0 ;
V_139:
for ( V_224 = 0 , V_51 = V_73 -> V_127 ;
V_224 < V_73 -> V_89 ;
V_224 ++ , V_51 ++ ) {
if ( ! V_51 -> V_121 )
break;
F_221 ( V_51 -> V_121 ) ;
V_51 -> V_121 = NULL ;
}
V_73 -> V_127 = NULL ;
V_73 -> V_89 = 0 ;
return V_14 ;
}
static int T_7 F_224 ( void )
{
F_45 () ;
F_225 () ;
return F_226 ( & V_347 ) ;
}
static void T_8 F_227 ( void )
{
F_228 () ;
F_48 () ;
#ifdef F_109
#endif
F_229 ( & V_347 ) ;
}
