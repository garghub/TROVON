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
if ( V_51 -> V_52 ) {
char * V_53 ;
V_53 = F_25 ( V_42 , L_4 ,
V_51 -> V_52 , V_51 -> V_53 ) ;
if ( V_53 ) {
V_51 -> V_54 = F_26 ( V_53 ,
V_51 -> V_55 -> V_56 ) ;
F_17 ( V_53 ) ;
}
} else {
V_51 -> V_54 = F_26 ( V_51 -> V_53 ,
V_51 -> V_55 -> V_56 ) ;
}
if ( ! V_51 -> V_54 ) {
F_27 ( V_51 -> V_25 ,
L_5 ) ;
return;
}
F_28 ( F_29 ( V_51 ) ,
V_51 -> V_54 ) ;
if ( V_51 -> V_57 )
V_51 -> V_57 ( V_51 ) ;
}
static void F_30 ( struct V_50 * V_51 )
{
F_31 ( V_51 -> V_54 ) ;
}
static void F_32 ( struct V_50 * V_51 )
{
struct V_4 * V_5 = F_33 ( V_51 ) ;
V_5 -> V_58 = F_34 ( L_6 , 0644 ,
V_5 -> V_51 . V_54 ,
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
V_5 -> V_51 . V_53 ) ;
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
V_62 -> V_53 ) ;
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
V_64 -> V_51 . V_53 ) ;
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
static void F_42 ( struct V_65 * V_55 )
{
V_55 -> V_56 = F_26 ( V_55 -> V_53 ,
V_66 ) ;
if ( ! V_55 -> V_56 ) {
F_27 ( V_55 -> V_25 ,
L_9 ) ;
return;
}
V_55 -> V_67 = F_43 ( L_10 , 0644 ,
V_55 -> V_56 ,
& V_55 -> V_68 ) ;
if ( ! V_55 -> V_67 )
F_27 ( V_55 -> V_25 ,
L_11 ) ;
}
static void F_44 ( struct V_65 * V_55 )
{
F_31 ( V_55 -> V_56 ) ;
}
static inline void F_24 (
struct V_50 * V_51 )
{
}
static inline void F_30 (
struct V_50 * V_51 )
{
}
static inline void F_42 ( struct V_65 * V_55 )
{
}
static inline void F_44 ( struct V_65 * V_55 )
{
}
struct V_69 * F_45 ( struct V_65 * V_55 ,
const char * V_70 , int V_71 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_55 -> V_72 ; V_3 ++ ) {
if ( V_55 -> V_29 [ V_3 ] . V_70 -> V_73 &&
! strcmp ( V_55 -> V_29 [ V_3 ] . V_70 -> V_53 , V_70 ) )
return V_55 -> V_29 [ V_3 ] . V_74 -> V_75 [ V_71 ] . V_76 ;
}
F_46 ( V_55 -> V_25 , L_12 , V_70 ) ;
return NULL ;
}
struct V_28 * F_47 ( struct V_65 * V_55 ,
const char * V_70 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_55 -> V_72 ; V_3 ++ ) {
if ( ! strcmp ( V_55 -> V_29 [ V_3 ] . V_70 -> V_53 , V_70 ) )
return & V_55 -> V_29 [ V_3 ] ;
}
F_46 ( V_55 -> V_25 , L_13 , V_70 ) ;
return NULL ;
}
static void F_48 ( struct V_77 * V_78 )
{
}
int F_49 ( struct V_24 * V_25 )
{
struct V_65 * V_55 = F_8 ( V_25 ) ;
struct V_4 * V_5 ;
int V_3 , V_79 ;
if ( ! V_55 -> V_80 )
return 0 ;
F_50 ( V_55 -> V_81 ) ;
F_51 ( V_55 -> V_81 , V_82 ) ;
F_52 ( V_55 -> V_81 ) ;
F_53 ( V_55 -> V_81 , V_83 ) ;
for ( V_3 = 0 ; V_3 < V_55 -> V_84 ; V_3 ++ ) {
if ( V_55 -> V_29 [ V_3 ] . V_70 -> V_85 )
continue;
for ( V_79 = 0 ; V_79 < V_55 -> V_29 [ V_3 ] . V_86 ; V_79 ++ ) {
struct V_61 * V_62 = V_55 -> V_29 [ V_3 ] . V_87 [ V_79 ] ;
struct V_88 * V_89 = V_62 -> V_10 ;
if ( V_89 -> V_90 -> V_91 && V_62 -> V_92 )
V_89 -> V_90 -> V_91 ( V_62 , 1 ) ;
}
}
for ( V_3 = 0 ; V_3 < V_55 -> V_84 ; V_3 ++ ) {
if ( V_55 -> V_29 [ V_3 ] . V_70 -> V_85 )
continue;
F_54 ( V_55 -> V_29 [ V_3 ] . V_74 ) ;
}
if ( V_55 -> V_93 )
V_55 -> V_93 ( V_55 ) ;
for ( V_3 = 0 ; V_3 < V_55 -> V_84 ; V_3 ++ ) {
struct V_61 * V_94 = V_55 -> V_29 [ V_3 ] . V_94 ;
if ( V_55 -> V_29 [ V_3 ] . V_70 -> V_85 )
continue;
if ( V_94 -> V_10 -> V_95 && ! V_94 -> V_10 -> V_96 )
V_94 -> V_10 -> V_95 ( V_94 ) ;
}
for ( V_3 = 0 ; V_3 < V_55 -> V_84 ; V_3 ++ ) {
struct V_61 * * V_87 = V_55 -> V_29 [ V_3 ] . V_87 ;
F_55 ( & V_55 -> V_29 [ V_3 ] . V_97 ) ;
for ( V_79 = 0 ; V_79 < V_55 -> V_29 [ V_3 ] . V_86 ; V_79 ++ ) {
V_87 [ V_79 ] -> V_5 -> V_98 . V_99 =
V_87 [ V_79 ] -> V_5 -> V_98 . V_100 ;
}
}
for ( V_3 = 0 ; V_3 < V_55 -> V_84 ; V_3 ++ ) {
if ( V_55 -> V_29 [ V_3 ] . V_70 -> V_85 )
continue;
F_56 ( & V_55 -> V_29 [ V_3 ] ,
V_101 ,
V_102 ) ;
F_56 ( & V_55 -> V_29 [ V_3 ] ,
V_103 ,
V_102 ) ;
}
F_57 ( V_55 ) ;
F_58 ( & V_55 -> V_98 ) ;
F_37 (codec, &card->codec_dev_list, card_list) {
if ( ! V_5 -> V_104 ) {
switch ( V_5 -> V_98 . V_100 ) {
case V_105 :
if ( V_5 -> V_98 . V_106 ) {
F_46 ( V_5 -> V_25 ,
L_14 ) ;
break;
}
case V_107 :
if ( V_5 -> V_10 -> V_95 )
V_5 -> V_10 -> V_95 ( V_5 ) ;
V_5 -> V_104 = 1 ;
if ( V_5 -> V_51 . V_108 )
F_59 ( V_5 -> V_51 . V_108 ) ;
F_60 ( V_5 -> V_25 ) ;
break;
default:
F_46 ( V_5 -> V_25 ,
L_15 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_55 -> V_84 ; V_3 ++ ) {
struct V_61 * V_94 = V_55 -> V_29 [ V_3 ] . V_94 ;
if ( V_55 -> V_29 [ V_3 ] . V_70 -> V_85 )
continue;
if ( V_94 -> V_10 -> V_95 && V_94 -> V_10 -> V_96 )
V_94 -> V_10 -> V_95 ( V_94 ) ;
F_60 ( V_94 -> V_25 ) ;
}
if ( V_55 -> V_109 )
V_55 -> V_109 ( V_55 ) ;
return 0 ;
}
static void F_61 ( struct V_77 * V_78 )
{
struct V_65 * V_55 =
F_62 ( V_78 , struct V_65 , V_110 ) ;
struct V_4 * V_5 ;
int V_3 , V_79 ;
F_46 ( V_55 -> V_25 , L_16 ) ;
F_53 ( V_55 -> V_81 , V_111 ) ;
if ( V_55 -> V_112 )
V_55 -> V_112 ( V_55 ) ;
for ( V_3 = 0 ; V_3 < V_55 -> V_84 ; V_3 ++ ) {
struct V_61 * V_94 = V_55 -> V_29 [ V_3 ] . V_94 ;
if ( V_55 -> V_29 [ V_3 ] . V_70 -> V_85 )
continue;
if ( V_94 -> V_10 -> V_113 && V_94 -> V_10 -> V_96 )
V_94 -> V_10 -> V_113 ( V_94 ) ;
}
F_37 (codec, &card->codec_dev_list, card_list) {
if ( V_5 -> V_104 ) {
switch ( V_5 -> V_98 . V_100 ) {
case V_105 :
case V_107 :
if ( V_5 -> V_10 -> V_113 )
V_5 -> V_10 -> V_113 ( V_5 ) ;
V_5 -> V_104 = 0 ;
break;
default:
F_46 ( V_5 -> V_25 ,
L_17 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_55 -> V_84 ; V_3 ++ ) {
if ( V_55 -> V_29 [ V_3 ] . V_70 -> V_85 )
continue;
F_56 ( & V_55 -> V_29 [ V_3 ] ,
V_101 ,
V_114 ) ;
F_56 ( & V_55 -> V_29 [ V_3 ] ,
V_103 ,
V_114 ) ;
}
for ( V_3 = 0 ; V_3 < V_55 -> V_84 ; V_3 ++ ) {
if ( V_55 -> V_29 [ V_3 ] . V_70 -> V_85 )
continue;
for ( V_79 = 0 ; V_79 < V_55 -> V_29 [ V_3 ] . V_86 ; V_79 ++ ) {
struct V_61 * V_62 = V_55 -> V_29 [ V_3 ] . V_87 [ V_79 ] ;
struct V_88 * V_89 = V_62 -> V_10 ;
if ( V_89 -> V_90 -> V_91 && V_62 -> V_92 )
V_89 -> V_90 -> V_91 ( V_62 , 0 ) ;
}
}
for ( V_3 = 0 ; V_3 < V_55 -> V_84 ; V_3 ++ ) {
struct V_61 * V_94 = V_55 -> V_29 [ V_3 ] . V_94 ;
if ( V_55 -> V_29 [ V_3 ] . V_70 -> V_85 )
continue;
if ( V_94 -> V_10 -> V_113 && ! V_94 -> V_10 -> V_96 )
V_94 -> V_10 -> V_113 ( V_94 ) ;
}
if ( V_55 -> V_115 )
V_55 -> V_115 ( V_55 ) ;
F_46 ( V_55 -> V_25 , L_18 ) ;
F_53 ( V_55 -> V_81 , V_82 ) ;
F_57 ( V_55 ) ;
F_58 ( & V_55 -> V_98 ) ;
}
int F_63 ( struct V_24 * V_25 )
{
struct V_65 * V_55 = F_8 ( V_25 ) ;
bool V_96 = false ;
int V_3 ;
if ( ! V_55 -> V_80 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_55 -> V_84 ; V_3 ++ ) {
struct V_28 * V_29 = & V_55 -> V_29 [ V_3 ] ;
struct V_61 * * V_87 = V_29 -> V_87 ;
struct V_61 * V_94 = V_29 -> V_94 ;
int V_79 ;
if ( V_94 -> V_116 )
F_64 ( V_94 -> V_25 ) ;
for ( V_79 = 0 ; V_79 < V_29 -> V_86 ; V_79 ++ ) {
struct V_61 * V_117 = V_87 [ V_79 ] ;
if ( V_117 -> V_116 )
F_64 ( V_117 -> V_25 ) ;
}
}
for ( V_3 = 0 ; V_3 < V_55 -> V_84 ; V_3 ++ ) {
struct V_61 * V_94 = V_55 -> V_29 [ V_3 ] . V_94 ;
V_96 |= V_94 -> V_10 -> V_96 ;
}
if ( V_96 ) {
F_46 ( V_25 , L_19 ) ;
F_61 ( & V_55 -> V_110 ) ;
} else {
F_46 ( V_25 , L_20 ) ;
if ( ! F_65 ( & V_55 -> V_110 ) )
F_66 ( V_25 , L_21 ) ;
}
return 0 ;
}
static struct V_50 * F_67 (
const struct V_118 * V_119 , const char * V_53 )
{
struct V_50 * V_51 ;
F_68 ( & V_60 ) ;
F_37 (component, &component_list, list) {
if ( V_119 ) {
if ( V_51 -> V_25 -> V_119 == V_119 )
return V_51 ;
} else if ( strcmp ( V_51 -> V_53 , V_53 ) == 0 ) {
return V_51 ;
}
}
return NULL ;
}
static struct V_61 * F_69 (
const struct V_120 * V_121 )
{
struct V_50 * V_51 ;
struct V_61 * V_62 ;
F_68 ( & V_60 ) ;
F_37 (component, &component_list, list) {
if ( V_121 -> V_119 && V_51 -> V_25 -> V_119 != V_121 -> V_119 )
continue;
if ( V_121 -> V_53 && strcmp ( V_51 -> V_53 , V_121 -> V_53 ) )
continue;
F_37 (dai, &component->dai_list, list) {
if ( V_121 -> V_122 && strcmp ( V_62 -> V_53 , V_121 -> V_122 ) )
continue;
return V_62 ;
}
}
return NULL ;
}
static int F_70 ( struct V_65 * V_55 , int V_123 )
{
struct V_124 * V_70 = & V_55 -> V_70 [ V_123 ] ;
struct V_28 * V_29 = & V_55 -> V_29 [ V_123 ] ;
struct V_120 * V_125 = V_70 -> V_125 ;
struct V_120 V_126 ;
struct V_61 * * V_87 = V_29 -> V_87 ;
struct V_63 * V_64 ;
const char * V_127 ;
int V_3 ;
F_46 ( V_55 -> V_25 , L_22 , V_70 -> V_53 , V_123 ) ;
V_126 . V_53 = V_70 -> V_128 ;
V_126 . V_119 = V_70 -> V_129 ;
V_126 . V_122 = V_70 -> V_130 ;
V_29 -> V_94 = F_69 ( & V_126 ) ;
if ( ! V_29 -> V_94 ) {
F_66 ( V_55 -> V_25 , L_23 ,
V_70 -> V_130 ) ;
return - V_131 ;
}
V_29 -> V_86 = V_70 -> V_86 ;
for ( V_3 = 0 ; V_3 < V_29 -> V_86 ; V_3 ++ ) {
V_87 [ V_3 ] = F_69 ( & V_125 [ V_3 ] ) ;
if ( ! V_87 [ V_3 ] ) {
F_66 ( V_55 -> V_25 , L_24 ,
V_125 [ V_3 ] . V_122 ) ;
return - V_131 ;
}
}
V_29 -> V_117 = V_87 [ 0 ] ;
V_29 -> V_5 = V_29 -> V_117 -> V_5 ;
V_127 = V_70 -> V_127 ;
if ( ! V_127 && ! V_70 -> V_132 )
V_127 = L_25 ;
F_37 (platform, &platform_list, list) {
if ( V_70 -> V_132 ) {
if ( V_64 -> V_25 -> V_119 !=
V_70 -> V_132 )
continue;
} else {
if ( strcmp ( V_64 -> V_51 . V_53 , V_127 ) )
continue;
}
V_29 -> V_64 = V_64 ;
}
if ( ! V_29 -> V_64 ) {
F_66 ( V_55 -> V_25 , L_26 ,
V_70 -> V_127 ) ;
return - V_131 ;
}
V_55 -> V_84 ++ ;
return 0 ;
}
static void F_71 ( struct V_50 * V_51 )
{
if ( ! V_51 -> V_133 )
return;
if ( V_51 -> V_5 )
F_72 ( & V_51 -> V_5 -> V_134 ) ;
if ( V_51 -> remove )
V_51 -> remove ( V_51 ) ;
F_73 ( F_29 ( V_51 ) ) ;
F_30 ( V_51 ) ;
V_51 -> V_133 = 0 ;
F_74 ( V_51 -> V_25 -> V_10 -> V_135 ) ;
}
static void F_75 ( struct V_61 * V_62 , int V_136 )
{
int V_137 ;
if ( V_62 && V_62 -> V_133 &&
V_62 -> V_10 -> V_138 == V_136 ) {
if ( V_62 -> V_10 -> remove ) {
V_137 = V_62 -> V_10 -> remove ( V_62 ) ;
if ( V_137 < 0 )
F_66 ( V_62 -> V_25 ,
L_27 ,
V_62 -> V_53 , V_137 ) ;
}
V_62 -> V_133 = 0 ;
}
}
static void F_76 ( struct V_65 * V_55 , int V_123 , int V_136 )
{
struct V_28 * V_29 = & V_55 -> V_29 [ V_123 ] ;
int V_3 ;
if ( V_29 -> V_139 ) {
F_77 ( V_29 -> V_25 ) ;
V_29 -> V_139 = 0 ;
}
for ( V_3 = 0 ; V_3 < V_29 -> V_86 ; V_3 ++ )
F_75 ( V_29 -> V_87 [ V_3 ] , V_136 ) ;
F_75 ( V_29 -> V_94 , V_136 ) ;
}
static void F_78 ( struct V_65 * V_55 , int V_123 ,
int V_136 )
{
struct V_28 * V_29 = & V_55 -> V_29 [ V_123 ] ;
struct V_61 * V_94 = V_29 -> V_94 ;
struct V_63 * V_64 = V_29 -> V_64 ;
struct V_50 * V_51 ;
int V_3 ;
if ( V_64 && V_64 -> V_51 . V_10 -> V_138 == V_136 )
F_71 ( & V_64 -> V_51 ) ;
for ( V_3 = 0 ; V_3 < V_29 -> V_86 ; V_3 ++ ) {
V_51 = V_29 -> V_87 [ V_3 ] -> V_51 ;
if ( V_51 -> V_10 -> V_138 == V_136 )
F_71 ( V_51 ) ;
}
if ( V_94 ) {
if ( V_94 -> V_51 -> V_10 -> V_138 == V_136 )
F_71 ( V_94 -> V_51 ) ;
}
}
static void F_79 ( struct V_65 * V_55 )
{
int V_62 , V_136 ;
for ( V_136 = V_140 ; V_136 <= V_141 ;
V_136 ++ ) {
for ( V_62 = 0 ; V_62 < V_55 -> V_84 ; V_62 ++ )
F_76 ( V_55 , V_62 , V_136 ) ;
}
for ( V_136 = V_140 ; V_136 <= V_141 ;
V_136 ++ ) {
for ( V_62 = 0 ; V_62 < V_55 -> V_84 ; V_62 ++ )
F_78 ( V_55 , V_62 , V_136 ) ;
}
V_55 -> V_84 = 0 ;
}
static void F_80 ( struct V_65 * V_55 ,
struct V_50 * V_51 )
{
int V_3 ;
if ( V_55 -> V_142 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_55 -> V_143 ; V_3 ++ ) {
struct V_144 * V_145 = & V_55 -> V_142 [ V_3 ] ;
if ( V_145 -> V_119 && V_51 -> V_25 -> V_119 != V_145 -> V_119 )
continue;
if ( V_145 -> V_146 && strcmp ( V_51 -> V_53 , V_145 -> V_146 ) )
continue;
V_51 -> V_147 = V_145 -> V_147 ;
break;
}
}
static int F_81 ( struct V_65 * V_55 ,
struct V_50 * V_51 )
{
struct V_148 * V_98 = F_29 ( V_51 ) ;
struct V_61 * V_62 ;
int V_14 ;
if ( V_51 -> V_133 )
return 0 ;
V_51 -> V_55 = V_55 ;
V_98 -> V_55 = V_55 ;
F_80 ( V_55 , V_51 ) ;
if ( ! F_82 ( V_51 -> V_25 -> V_10 -> V_135 ) )
return - V_149 ;
F_24 ( V_51 ) ;
if ( V_51 -> V_150 ) {
V_14 = F_83 ( V_98 , V_51 -> V_150 ,
V_51 -> V_151 ) ;
if ( V_14 != 0 ) {
F_66 ( V_51 -> V_25 ,
L_28 , V_14 ) ;
goto V_152;
}
}
F_37 (dai, &component->dai_list, list) {
V_14 = F_84 ( V_98 , V_62 ) ;
if ( V_14 != 0 ) {
F_66 ( V_51 -> V_25 ,
L_29 , V_14 ) ;
goto V_152;
}
}
if ( V_51 -> V_153 ) {
V_14 = V_51 -> V_153 ( V_51 ) ;
if ( V_14 < 0 ) {
F_66 ( V_51 -> V_25 ,
L_30 , V_14 ) ;
goto V_152;
}
F_85 ( V_98 -> V_106 &&
V_98 -> V_100 != V_107 ,
L_31 ,
V_51 -> V_53 ) ;
}
if ( V_51 -> V_154 )
F_86 ( V_51 , V_51 -> V_154 ,
V_51 -> V_155 ) ;
if ( V_51 -> V_156 )
F_87 ( V_98 , V_51 -> V_156 ,
V_51 -> V_157 ) ;
V_51 -> V_133 = 1 ;
F_88 ( & V_98 -> V_158 , & V_55 -> V_159 ) ;
if ( V_51 -> V_5 )
F_88 ( & V_51 -> V_5 -> V_134 , & V_55 -> V_160 ) ;
return 0 ;
V_152:
F_30 ( V_51 ) ;
F_74 ( V_51 -> V_25 -> V_10 -> V_135 ) ;
return V_14 ;
}
static void F_89 ( struct V_24 * V_25 )
{
F_17 ( V_25 ) ;
}
static int F_90 ( struct V_28 * V_29 ,
const char * V_53 )
{
int V_14 = 0 ;
V_29 -> V_25 = F_91 ( sizeof( struct V_24 ) , V_42 ) ;
if ( ! V_29 -> V_25 )
return - V_43 ;
F_92 ( V_29 -> V_25 ) ;
V_29 -> V_25 -> V_161 = V_29 -> V_55 -> V_25 ;
V_29 -> V_25 -> V_162 = F_89 ;
V_29 -> V_25 -> V_163 = V_164 ;
F_93 ( V_29 -> V_25 , L_32 , V_53 ) ;
F_94 ( V_29 -> V_25 , V_29 ) ;
F_95 ( & V_29 -> V_165 ) ;
F_96 ( & V_29 -> V_166 [ V_101 ] . V_167 ) ;
F_96 ( & V_29 -> V_166 [ V_103 ] . V_167 ) ;
F_96 ( & V_29 -> V_166 [ V_101 ] . V_168 ) ;
F_96 ( & V_29 -> V_166 [ V_103 ] . V_168 ) ;
V_14 = F_97 ( V_29 -> V_25 ) ;
if ( V_14 < 0 ) {
F_98 ( V_29 -> V_25 ) ;
F_66 ( V_29 -> V_55 -> V_25 ,
L_33 , V_14 ) ;
return V_14 ;
}
V_29 -> V_139 = 1 ;
return 0 ;
}
static int F_99 ( struct V_65 * V_55 , int V_123 ,
int V_136 )
{
struct V_28 * V_29 = & V_55 -> V_29 [ V_123 ] ;
struct V_63 * V_64 = V_29 -> V_64 ;
struct V_50 * V_51 ;
int V_3 , V_14 ;
V_51 = V_29 -> V_94 -> V_51 ;
if ( V_51 -> V_10 -> V_169 == V_136 ) {
V_14 = F_81 ( V_55 , V_51 ) ;
if ( V_14 < 0 )
return V_14 ;
}
for ( V_3 = 0 ; V_3 < V_29 -> V_86 ; V_3 ++ ) {
V_51 = V_29 -> V_87 [ V_3 ] -> V_51 ;
if ( V_51 -> V_10 -> V_169 == V_136 ) {
V_14 = F_81 ( V_55 , V_51 ) ;
if ( V_14 < 0 )
return V_14 ;
}
}
if ( V_64 -> V_51 . V_10 -> V_169 == V_136 ) {
V_14 = F_81 ( V_55 , & V_64 -> V_51 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
static int F_100 ( struct V_61 * V_62 , int V_136 )
{
int V_14 ;
if ( ! V_62 -> V_133 && V_62 -> V_10 -> V_169 == V_136 ) {
if ( V_62 -> V_10 -> V_153 ) {
V_14 = V_62 -> V_10 -> V_153 ( V_62 ) ;
if ( V_14 < 0 ) {
F_66 ( V_62 -> V_25 ,
L_34 ,
V_62 -> V_53 , V_14 ) ;
return V_14 ;
}
}
V_62 -> V_133 = 1 ;
}
return 0 ;
}
static int F_101 ( struct V_65 * V_55 ,
struct V_124 * V_70 ,
struct V_28 * V_29 )
{
struct V_61 * V_94 = V_29 -> V_94 ;
struct V_61 * V_117 = V_29 -> V_117 ;
struct V_170 * V_171 , * V_172 ;
int V_14 ;
if ( V_29 -> V_86 > 1 )
F_27 ( V_55 -> V_25 , L_35 ) ;
V_171 = V_117 -> V_173 ;
V_172 = V_94 -> V_174 ;
if ( V_171 && V_172 ) {
V_14 = F_102 ( V_55 , V_70 -> V_175 ,
V_172 , V_171 ) ;
if ( V_14 != 0 ) {
F_66 ( V_55 -> V_25 , L_36 ,
V_171 -> V_53 , V_172 -> V_53 , V_14 ) ;
return V_14 ;
}
}
V_171 = V_94 -> V_173 ;
V_172 = V_117 -> V_174 ;
if ( V_171 && V_172 ) {
V_14 = F_102 ( V_55 , V_70 -> V_175 ,
V_172 , V_171 ) ;
if ( V_14 != 0 ) {
F_66 ( V_55 -> V_25 , L_36 ,
V_171 -> V_53 , V_172 -> V_53 , V_14 ) ;
return V_14 ;
}
}
return 0 ;
}
static int F_103 ( struct V_65 * V_55 , int V_123 , int V_136 )
{
struct V_124 * V_70 = & V_55 -> V_70 [ V_123 ] ;
struct V_28 * V_29 = & V_55 -> V_29 [ V_123 ] ;
struct V_61 * V_94 = V_29 -> V_94 ;
int V_3 , V_14 ;
F_46 ( V_55 -> V_25 , L_37 ,
V_55 -> V_53 , V_123 , V_136 ) ;
V_29 -> V_31 = V_31 ;
V_14 = F_100 ( V_94 , V_136 ) ;
if ( V_14 )
return V_14 ;
for ( V_3 = 0 ; V_3 < V_29 -> V_86 ; V_3 ++ ) {
V_14 = F_100 ( V_29 -> V_87 [ V_3 ] , V_136 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_136 != V_141 )
return 0 ;
if ( V_70 -> V_176 ) {
V_14 = V_70 -> V_176 ( V_29 ) ;
if ( V_14 < 0 ) {
F_66 ( V_55 -> V_25 , L_38 ,
V_70 -> V_53 , V_14 ) ;
return V_14 ;
}
}
V_14 = F_90 ( V_29 , V_70 -> V_53 ) ;
if ( V_14 )
return V_14 ;
#ifdef F_104
if ( V_70 -> V_177 ) {
V_14 = F_105 ( V_29 ) ;
if ( V_14 < 0 ) {
F_66 ( V_29 -> V_25 ,
L_39 ,
V_14 ) ;
return V_14 ;
}
}
#endif
if ( V_94 -> V_10 -> V_178 ) {
V_14 = F_106 ( V_29 , V_123 ) ;
if ( V_14 < 0 ) {
F_66 ( V_55 -> V_25 , L_40 ,
V_70 -> V_179 ) ;
return V_14 ;
}
} else {
if ( ! V_70 -> V_175 ) {
V_14 = F_107 ( V_29 , V_123 ) ;
if ( V_14 < 0 ) {
F_66 ( V_55 -> V_25 , L_41 ,
V_70 -> V_179 , V_14 ) ;
return V_14 ;
}
} else {
F_108 ( & V_29 -> V_97 ,
F_48 ) ;
V_14 = F_101 ( V_55 , V_70 , V_29 ) ;
if ( V_14 )
return V_14 ;
}
}
return 0 ;
}
static int F_109 ( struct V_65 * V_55 , int V_123 )
{
struct V_28 * V_29 = & V_55 -> V_180 [ V_123 ] ;
struct V_181 * V_182 = & V_55 -> V_182 [ V_123 ] ;
const char * V_53 = V_182 -> V_183 ;
V_29 -> V_51 = F_67 ( V_182 -> V_184 , V_53 ) ;
if ( ! V_29 -> V_51 ) {
if ( V_182 -> V_184 )
V_53 = F_110 ( V_182 -> V_184 ) ;
F_66 ( V_55 -> V_25 , L_42 , V_53 ) ;
return - V_131 ;
}
V_29 -> V_5 = V_29 -> V_51 -> V_5 ;
return 0 ;
}
static int F_111 ( struct V_65 * V_55 , int V_123 )
{
struct V_28 * V_29 = & V_55 -> V_180 [ V_123 ] ;
struct V_181 * V_182 = & V_55 -> V_182 [ V_123 ] ;
int V_14 ;
V_14 = F_81 ( V_55 , V_29 -> V_51 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_182 -> V_176 ) {
V_14 = V_182 -> V_176 ( V_29 -> V_51 ) ;
if ( V_14 < 0 ) {
F_66 ( V_55 -> V_25 , L_38 ,
V_182 -> V_53 , V_14 ) ;
return V_14 ;
}
}
return F_90 ( V_29 , V_182 -> V_53 ) ;
}
static void F_112 ( struct V_65 * V_55 , int V_123 )
{
struct V_28 * V_29 = & V_55 -> V_180 [ V_123 ] ;
struct V_50 * V_51 = V_29 -> V_51 ;
if ( V_29 -> V_139 ) {
F_113 ( V_29 -> V_25 , & V_185 ) ;
F_77 ( V_29 -> V_25 ) ;
V_29 -> V_139 = 0 ;
}
if ( V_51 && V_51 -> V_133 )
F_71 ( V_51 ) ;
}
static int F_114 ( struct V_4 * V_5 )
{
int V_14 ;
if ( V_5 -> V_186 )
return 0 ;
V_14 = F_115 ( V_5 ) ;
if ( V_14 < 0 ) {
F_66 ( V_5 -> V_25 ,
L_43 ,
V_14 ) ;
return V_14 ;
}
V_5 -> V_186 = 1 ;
return 0 ;
}
int F_116 ( struct V_28 * V_29 ,
unsigned int V_187 )
{
struct V_61 * * V_87 = V_29 -> V_87 ;
struct V_61 * V_94 = V_29 -> V_94 ;
unsigned int V_3 ;
int V_14 ;
for ( V_3 = 0 ; V_3 < V_29 -> V_86 ; V_3 ++ ) {
struct V_61 * V_117 = V_87 [ V_3 ] ;
V_14 = F_117 ( V_117 , V_187 ) ;
if ( V_14 != 0 && V_14 != - V_188 ) {
F_27 ( V_117 -> V_25 ,
L_44 , V_14 ) ;
return V_14 ;
}
}
if ( V_94 -> V_5 ) {
unsigned int V_189 ;
V_189 = V_187 & ~ V_190 ;
switch ( V_187 & V_190 ) {
case V_191 :
V_189 |= V_192 ;
break;
case V_193 :
V_189 |= V_194 ;
break;
case V_194 :
V_189 |= V_193 ;
break;
case V_192 :
V_189 |= V_191 ;
break;
}
V_187 = V_189 ;
}
V_14 = F_117 ( V_94 , V_187 ) ;
if ( V_14 != 0 && V_14 != - V_188 ) {
F_27 ( V_94 -> V_25 ,
L_44 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_118 ( struct V_65 * V_55 )
{
struct V_4 * V_5 ;
int V_14 , V_3 , V_136 ;
F_36 ( & V_60 ) ;
F_119 ( & V_55 -> V_195 , V_196 ) ;
for ( V_3 = 0 ; V_3 < V_55 -> V_72 ; V_3 ++ ) {
V_14 = F_70 ( V_55 , V_3 ) ;
if ( V_14 != 0 )
goto V_197;
}
for ( V_3 = 0 ; V_3 < V_55 -> V_198 ; V_3 ++ ) {
V_14 = F_109 ( V_55 , V_3 ) ;
if ( V_14 != 0 )
goto V_197;
}
F_37 (codec, &codec_list, list) {
if ( V_5 -> V_186 )
continue;
V_14 = F_114 ( V_5 ) ;
if ( V_14 < 0 )
goto V_197;
}
V_14 = F_120 ( V_55 -> V_25 , V_199 , V_200 ,
V_55 -> V_135 , 0 , & V_55 -> V_81 ) ;
if ( V_14 < 0 ) {
F_66 ( V_55 -> V_25 ,
L_45 ,
V_55 -> V_53 , V_14 ) ;
goto V_197;
}
V_55 -> V_98 . V_100 = V_107 ;
V_55 -> V_98 . V_25 = V_55 -> V_25 ;
V_55 -> V_98 . V_55 = V_55 ;
F_88 ( & V_55 -> V_98 . V_158 , & V_55 -> V_159 ) ;
#ifdef F_104
F_28 ( & V_55 -> V_98 , V_55 -> V_56 ) ;
#endif
#ifdef F_121
F_122 ( & V_55 -> V_110 , F_61 ) ;
#endif
if ( V_55 -> V_150 )
F_83 ( & V_55 -> V_98 , V_55 -> V_150 ,
V_55 -> V_151 ) ;
if ( V_55 -> V_153 ) {
V_14 = V_55 -> V_153 ( V_55 ) ;
if ( V_14 < 0 )
goto V_201;
}
for ( V_136 = V_140 ; V_136 <= V_141 ;
V_136 ++ ) {
for ( V_3 = 0 ; V_3 < V_55 -> V_72 ; V_3 ++ ) {
V_14 = F_99 ( V_55 , V_3 , V_136 ) ;
if ( V_14 < 0 ) {
F_66 ( V_55 -> V_25 ,
L_46 ,
V_14 ) ;
goto V_202;
}
}
}
for ( V_136 = V_140 ; V_136 <= V_141 ;
V_136 ++ ) {
for ( V_3 = 0 ; V_3 < V_55 -> V_72 ; V_3 ++ ) {
V_14 = F_103 ( V_55 , V_3 , V_136 ) ;
if ( V_14 < 0 ) {
F_66 ( V_55 -> V_25 ,
L_46 ,
V_14 ) ;
goto V_202;
}
}
}
for ( V_3 = 0 ; V_3 < V_55 -> V_198 ; V_3 ++ ) {
V_14 = F_111 ( V_55 , V_3 ) ;
if ( V_14 < 0 ) {
F_66 ( V_55 -> V_25 ,
L_47 ,
V_14 ) ;
goto V_203;
}
}
F_123 ( V_55 ) ;
F_124 ( V_55 ) ;
if ( V_55 -> V_154 )
F_125 ( V_55 , V_55 -> V_154 , V_55 -> V_155 ) ;
if ( V_55 -> V_156 )
F_87 ( & V_55 -> V_98 , V_55 -> V_156 ,
V_55 -> V_157 ) ;
for ( V_3 = 0 ; V_3 < V_55 -> V_72 ; V_3 ++ ) {
if ( V_55 -> V_70 [ V_3 ] . V_187 )
F_116 ( & V_55 -> V_29 [ V_3 ] ,
V_55 -> V_70 [ V_3 ] . V_187 ) ;
}
snprintf ( V_55 -> V_81 -> V_204 , sizeof( V_55 -> V_81 -> V_204 ) ,
L_32 , V_55 -> V_53 ) ;
snprintf ( V_55 -> V_81 -> V_205 , sizeof( V_55 -> V_81 -> V_205 ) ,
L_32 , V_55 -> V_206 ? V_55 -> V_206 : V_55 -> V_53 ) ;
snprintf ( V_55 -> V_81 -> V_10 , sizeof( V_55 -> V_81 -> V_10 ) ,
L_32 , V_55 -> V_207 ? V_55 -> V_207 : V_55 -> V_53 ) ;
for ( V_3 = 0 ; V_3 < F_126 ( V_55 -> V_81 -> V_10 ) ; V_3 ++ ) {
switch ( V_55 -> V_81 -> V_10 [ V_3 ] ) {
case '_' :
case '-' :
case '\0' :
break;
default:
if ( ! isalnum ( V_55 -> V_81 -> V_10 [ V_3 ] ) )
V_55 -> V_81 -> V_10 [ V_3 ] = '_' ;
break;
}
}
if ( V_55 -> V_208 ) {
V_14 = V_55 -> V_208 ( V_55 ) ;
if ( V_14 < 0 ) {
F_66 ( V_55 -> V_25 , L_48 ,
V_55 -> V_53 , V_14 ) ;
goto V_203;
}
}
F_127 ( V_55 ) ;
V_14 = F_128 ( V_55 -> V_81 ) ;
if ( V_14 < 0 ) {
F_66 ( V_55 -> V_25 , L_49 ,
V_14 ) ;
goto V_203;
}
V_55 -> V_80 = 1 ;
F_58 ( & V_55 -> V_98 ) ;
F_38 ( & V_55 -> V_195 ) ;
F_38 ( & V_60 ) ;
return 0 ;
V_203:
for ( V_3 = 0 ; V_3 < V_55 -> V_198 ; V_3 ++ )
F_112 ( V_55 , V_3 ) ;
V_202:
F_79 ( V_55 ) ;
V_201:
if ( V_55 -> remove )
V_55 -> remove ( V_55 ) ;
F_129 ( V_55 -> V_81 ) ;
V_197:
F_38 ( & V_55 -> V_195 ) ;
F_38 ( & V_60 ) ;
return V_14 ;
}
static int F_130 ( struct V_209 * V_210 )
{
struct V_65 * V_55 = F_131 ( V_210 ) ;
if ( ! V_55 )
return - V_17 ;
F_27 ( & V_210 -> V_25 ,
L_50 ,
V_55 -> V_53 ) ;
V_55 -> V_25 = & V_210 -> V_25 ;
return F_132 ( V_55 ) ;
}
static int F_133 ( struct V_65 * V_55 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_55 -> V_84 ; V_3 ++ ) {
struct V_28 * V_29 = & V_55 -> V_29 [ V_3 ] ;
F_55 ( & V_29 -> V_97 ) ;
}
for ( V_3 = 0 ; V_3 < V_55 -> V_198 ; V_3 ++ )
F_112 ( V_55 , V_3 ) ;
F_79 ( V_55 ) ;
F_44 ( V_55 ) ;
if ( V_55 -> remove )
V_55 -> remove ( V_55 ) ;
F_73 ( & V_55 -> V_98 ) ;
F_129 ( V_55 -> V_81 ) ;
return 0 ;
}
static int F_134 ( struct V_209 * V_210 )
{
struct V_65 * V_55 = F_131 ( V_210 ) ;
F_135 ( V_55 ) ;
return 0 ;
}
int F_136 ( struct V_24 * V_25 )
{
struct V_65 * V_55 = F_8 ( V_25 ) ;
int V_3 ;
if ( ! V_55 -> V_80 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_55 -> V_84 ; V_3 ++ ) {
struct V_28 * V_29 = & V_55 -> V_29 [ V_3 ] ;
F_55 ( & V_29 -> V_97 ) ;
}
F_137 ( V_55 ) ;
for ( V_3 = 0 ; V_3 < V_55 -> V_84 ; V_3 ++ ) {
struct V_28 * V_29 = & V_55 -> V_29 [ V_3 ] ;
struct V_61 * V_94 = V_29 -> V_94 ;
int V_79 ;
F_60 ( V_94 -> V_25 ) ;
for ( V_79 = 0 ; V_79 < V_29 -> V_86 ; V_79 ++ ) {
struct V_61 * V_117 = V_29 -> V_87 [ V_79 ] ;
F_60 ( V_117 -> V_25 ) ;
}
}
return 0 ;
}
struct V_211 * F_138 ( const struct V_212 * V_213 ,
void * V_214 , const char * V_206 ,
const char * V_215 )
{
struct V_212 V_216 ;
struct V_211 * V_217 ;
char * V_53 = NULL ;
memcpy ( & V_216 , V_213 , sizeof( V_216 ) ) ;
V_216 . V_218 = 0 ;
if ( ! V_206 )
V_206 = V_216 . V_53 ;
if ( V_215 ) {
V_53 = F_25 ( V_42 , L_51 , V_215 , V_206 ) ;
if ( ! V_53 )
return NULL ;
V_216 . V_53 = V_53 ;
} else {
V_216 . V_53 = V_206 ;
}
V_217 = F_139 ( & V_216 , V_214 ) ;
F_17 ( V_53 ) ;
return V_217 ;
}
static int F_140 ( struct V_81 * V_55 , struct V_24 * V_25 ,
const struct V_212 * V_154 , int V_155 ,
const char * V_215 , void * V_214 )
{
int V_137 , V_3 ;
for ( V_3 = 0 ; V_3 < V_155 ; V_3 ++ ) {
const struct V_212 * V_219 = & V_154 [ V_3 ] ;
V_137 = F_141 ( V_55 , F_138 ( V_219 , V_214 ,
V_219 -> V_53 , V_215 ) ) ;
if ( V_137 < 0 ) {
F_66 ( V_25 , L_52 ,
V_219 -> V_53 , V_137 ) ;
return V_137 ;
}
}
return 0 ;
}
struct V_211 * F_142 ( struct V_65 * V_220 ,
const char * V_53 )
{
struct V_81 * V_55 = V_220 -> V_81 ;
struct V_211 * V_221 ;
if ( F_143 ( ! V_53 ) )
return NULL ;
F_37 (kctl, &card->controls, list)
if ( ! strncmp ( V_221 -> V_222 . V_53 , V_53 , sizeof( V_221 -> V_222 . V_53 ) ) )
return V_221 ;
return NULL ;
}
int F_86 ( struct V_50 * V_51 ,
const struct V_212 * V_154 , unsigned int V_155 )
{
struct V_81 * V_55 = V_51 -> V_55 -> V_81 ;
return F_140 ( V_55 , V_51 -> V_25 , V_154 ,
V_155 , V_51 -> V_147 , V_51 ) ;
}
int F_144 ( struct V_4 * V_5 ,
const struct V_212 * V_154 , unsigned int V_155 )
{
return F_86 ( & V_5 -> V_51 , V_154 ,
V_155 ) ;
}
int F_145 ( struct V_63 * V_64 ,
const struct V_212 * V_154 , unsigned int V_155 )
{
return F_86 ( & V_64 -> V_51 , V_154 ,
V_155 ) ;
}
int F_125 ( struct V_65 * V_220 ,
const struct V_212 * V_154 , int V_155 )
{
struct V_81 * V_55 = V_220 -> V_81 ;
return F_140 ( V_55 , V_220 -> V_25 , V_154 , V_155 ,
NULL , V_220 ) ;
}
int F_146 ( struct V_61 * V_62 ,
const struct V_212 * V_154 , int V_155 )
{
struct V_81 * V_55 = V_62 -> V_51 -> V_55 -> V_81 ;
return F_140 ( V_55 , V_62 -> V_25 , V_154 , V_155 ,
NULL , V_62 ) ;
}
int F_147 ( struct V_61 * V_62 , int V_223 ,
unsigned int V_224 , int V_225 )
{
if ( V_62 -> V_10 && V_62 -> V_10 -> V_90 -> V_226 )
return V_62 -> V_10 -> V_90 -> V_226 ( V_62 , V_223 , V_224 , V_225 ) ;
else if ( V_62 -> V_5 && V_62 -> V_5 -> V_10 -> V_226 )
return V_62 -> V_5 -> V_10 -> V_226 ( V_62 -> V_5 , V_223 , 0 ,
V_224 , V_225 ) ;
else
return - V_188 ;
}
int F_148 ( struct V_4 * V_5 , int V_223 ,
int V_227 , unsigned int V_224 , int V_225 )
{
if ( V_5 -> V_10 -> V_226 )
return V_5 -> V_10 -> V_226 ( V_5 , V_223 , V_227 ,
V_224 , V_225 ) ;
else
return - V_188 ;
}
int F_149 ( struct V_61 * V_62 ,
int V_228 , int div )
{
if ( V_62 -> V_10 && V_62 -> V_10 -> V_90 -> V_229 )
return V_62 -> V_10 -> V_90 -> V_229 ( V_62 , V_228 , div ) ;
else
return - V_17 ;
}
int F_150 ( struct V_61 * V_62 , int V_230 , int V_227 ,
unsigned int V_231 , unsigned int V_232 )
{
if ( V_62 -> V_10 && V_62 -> V_10 -> V_90 -> V_233 )
return V_62 -> V_10 -> V_90 -> V_233 ( V_62 , V_230 , V_227 ,
V_231 , V_232 ) ;
else if ( V_62 -> V_5 && V_62 -> V_5 -> V_10 -> V_233 )
return V_62 -> V_5 -> V_10 -> V_233 ( V_62 -> V_5 , V_230 , V_227 ,
V_231 , V_232 ) ;
else
return - V_17 ;
}
int F_151 ( struct V_4 * V_5 , int V_230 , int V_227 ,
unsigned int V_231 , unsigned int V_232 )
{
if ( V_5 -> V_10 -> V_233 )
return V_5 -> V_10 -> V_233 ( V_5 , V_230 , V_227 ,
V_231 , V_232 ) ;
else
return - V_17 ;
}
int F_152 ( struct V_61 * V_62 , unsigned int V_234 )
{
if ( V_62 -> V_10 && V_62 -> V_10 -> V_90 -> V_235 )
return V_62 -> V_10 -> V_90 -> V_235 ( V_62 , V_234 ) ;
else
return - V_17 ;
}
int F_117 ( struct V_61 * V_62 , unsigned int V_236 )
{
if ( V_62 -> V_10 == NULL )
return - V_17 ;
if ( V_62 -> V_10 -> V_90 -> V_237 == NULL )
return - V_188 ;
return V_62 -> V_10 -> V_90 -> V_237 ( V_62 , V_236 ) ;
}
static int F_153 ( unsigned int V_238 ,
unsigned int * V_239 ,
unsigned int * V_240 )
{
if ( * V_239 || * V_240 )
return 0 ;
if ( ! V_238 )
return - V_17 ;
* V_239 = ( 1 << V_238 ) - 1 ;
* V_240 = ( 1 << V_238 ) - 1 ;
return 0 ;
}
int F_154 ( struct V_61 * V_62 ,
unsigned int V_239 , unsigned int V_240 , int V_238 , int V_241 )
{
if ( V_62 -> V_10 && V_62 -> V_10 -> V_90 -> V_242 )
V_62 -> V_10 -> V_90 -> V_242 ( V_238 ,
& V_239 , & V_240 ) ;
else
F_153 ( V_238 , & V_239 , & V_240 ) ;
V_62 -> V_239 = V_239 ;
V_62 -> V_240 = V_240 ;
if ( V_62 -> V_10 && V_62 -> V_10 -> V_90 -> V_243 )
return V_62 -> V_10 -> V_90 -> V_243 ( V_62 , V_239 , V_240 ,
V_238 , V_241 ) ;
else
return - V_188 ;
}
int F_155 ( struct V_61 * V_62 ,
unsigned int V_244 , unsigned int * V_245 ,
unsigned int V_246 , unsigned int * V_247 )
{
if ( V_62 -> V_10 && V_62 -> V_10 -> V_90 -> V_248 )
return V_62 -> V_10 -> V_90 -> V_248 ( V_62 , V_244 , V_245 ,
V_246 , V_247 ) ;
else
return - V_17 ;
}
int F_156 ( struct V_61 * V_62 , int V_249 )
{
if ( V_62 -> V_10 && V_62 -> V_10 -> V_90 -> V_250 )
return V_62 -> V_10 -> V_90 -> V_250 ( V_62 , V_249 ) ;
else
return - V_17 ;
}
int F_157 ( struct V_61 * V_62 , int V_251 ,
int V_252 )
{
if ( ! V_62 -> V_10 )
return - V_188 ;
if ( V_62 -> V_10 -> V_90 -> V_253 )
return V_62 -> V_10 -> V_90 -> V_253 ( V_62 , V_251 , V_252 ) ;
else if ( V_252 == V_101 &&
V_62 -> V_10 -> V_90 -> V_91 )
return V_62 -> V_10 -> V_90 -> V_91 ( V_62 , V_251 ) ;
else
return - V_188 ;
}
static int F_158 ( struct V_65 * V_55 ,
struct V_124 * V_70 )
{
if ( V_70 -> V_183 || V_70 -> V_184 ||
V_70 -> V_254 ) {
V_70 -> V_86 = 1 ;
V_70 -> V_125 = F_159 ( V_55 -> V_25 ,
sizeof( struct V_120 ) ,
V_42 ) ;
if ( ! V_70 -> V_125 )
return - V_43 ;
V_70 -> V_125 [ 0 ] . V_53 = V_70 -> V_183 ;
V_70 -> V_125 [ 0 ] . V_119 = V_70 -> V_184 ;
V_70 -> V_125 [ 0 ] . V_122 = V_70 -> V_254 ;
}
if ( ! V_70 -> V_125 ) {
F_66 ( V_55 -> V_25 , L_53 ) ;
return - V_17 ;
}
return 0 ;
}
int F_132 ( struct V_65 * V_55 )
{
int V_3 , V_79 , V_14 ;
if ( ! V_55 -> V_53 || ! V_55 -> V_25 )
return - V_17 ;
for ( V_3 = 0 ; V_3 < V_55 -> V_72 ; V_3 ++ ) {
struct V_124 * V_255 = & V_55 -> V_70 [ V_3 ] ;
V_14 = F_158 ( V_55 , V_255 ) ;
if ( V_14 ) {
F_66 ( V_55 -> V_25 , L_54 ) ;
return V_14 ;
}
for ( V_79 = 0 ; V_79 < V_255 -> V_86 ; V_79 ++ ) {
if ( ! ! V_255 -> V_125 [ V_79 ] . V_53 ==
! ! V_255 -> V_125 [ V_79 ] . V_119 ) {
F_66 ( V_55 -> V_25 , L_55 ,
V_255 -> V_53 ) ;
return - V_17 ;
}
if ( ! V_255 -> V_125 [ V_79 ] . V_122 ) {
F_66 ( V_55 -> V_25 , L_56 ,
V_255 -> V_53 ) ;
return - V_17 ;
}
}
if ( V_255 -> V_127 && V_255 -> V_132 ) {
F_66 ( V_55 -> V_25 ,
L_57 ,
V_255 -> V_53 ) ;
return - V_17 ;
}
if ( V_255 -> V_128 && V_255 -> V_129 ) {
F_66 ( V_55 -> V_25 ,
L_58 ,
V_255 -> V_53 ) ;
return - V_17 ;
}
if ( ! V_255 -> V_130 &&
! ( V_255 -> V_128 || V_255 -> V_129 ) ) {
F_66 ( V_55 -> V_25 ,
L_59 ,
V_255 -> V_53 ) ;
return - V_17 ;
}
}
F_94 ( V_55 -> V_25 , V_55 ) ;
F_160 ( V_55 ) ;
F_42 ( V_55 ) ;
V_55 -> V_29 = F_159 ( V_55 -> V_25 ,
sizeof( struct V_28 ) *
( V_55 -> V_72 + V_55 -> V_198 ) ,
V_42 ) ;
if ( V_55 -> V_29 == NULL )
return - V_43 ;
V_55 -> V_84 = 0 ;
V_55 -> V_180 = & V_55 -> V_29 [ V_55 -> V_72 ] ;
for ( V_3 = 0 ; V_3 < V_55 -> V_72 ; V_3 ++ ) {
V_55 -> V_29 [ V_3 ] . V_55 = V_55 ;
V_55 -> V_29 [ V_3 ] . V_70 = & V_55 -> V_70 [ V_3 ] ;
V_55 -> V_29 [ V_3 ] . V_87 = F_159 ( V_55 -> V_25 ,
sizeof( struct V_61 * ) *
( V_55 -> V_29 [ V_3 ] . V_70 -> V_86 ) ,
V_42 ) ;
if ( V_55 -> V_29 [ V_3 ] . V_87 == NULL )
return - V_43 ;
}
for ( V_3 = 0 ; V_3 < V_55 -> V_198 ; V_3 ++ )
V_55 -> V_180 [ V_3 ] . V_55 = V_55 ;
F_96 ( & V_55 -> V_256 ) ;
V_55 -> V_80 = 0 ;
F_95 ( & V_55 -> V_195 ) ;
F_95 ( & V_55 -> V_257 ) ;
V_14 = F_118 ( V_55 ) ;
if ( V_14 != 0 )
F_44 ( V_55 ) ;
for ( V_3 = 0 ; V_3 < V_55 -> V_84 ; V_3 ++ ) {
struct V_28 * V_29 = & V_55 -> V_29 [ V_3 ] ;
struct V_61 * V_94 = V_29 -> V_94 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_29 -> V_86 ; V_79 ++ ) {
struct V_61 * V_117 = V_29 -> V_87 [ V_79 ] ;
if ( ! V_117 -> V_116 )
F_60 ( V_117 -> V_25 ) ;
}
if ( ! V_94 -> V_116 )
F_60 ( V_94 -> V_25 ) ;
}
return V_14 ;
}
int F_135 ( struct V_65 * V_55 )
{
if ( V_55 -> V_80 ) {
V_55 -> V_80 = false ;
F_137 ( V_55 ) ;
F_133 ( V_55 ) ;
F_46 ( V_55 -> V_25 , L_60 , V_55 -> V_53 ) ;
}
return 0 ;
}
static char * F_161 ( struct V_24 * V_25 , int * V_222 )
{
char * V_258 , V_53 [ V_259 ] ;
int V_260 , V_261 ;
if ( V_146 ( V_25 ) == NULL )
return NULL ;
F_162 ( V_53 , V_146 ( V_25 ) , V_259 ) ;
V_258 = strstr ( V_53 , V_25 -> V_10 -> V_53 ) ;
if ( V_258 ) {
if ( sscanf ( & V_258 [ strlen ( V_25 -> V_10 -> V_53 ) ] , L_61 , V_222 ) == 1 ) {
if ( * V_222 == - 1 )
V_258 [ strlen ( V_25 -> V_10 -> V_53 ) ] = '\0' ;
}
} else {
if ( sscanf ( V_53 , L_62 , & V_260 , & V_261 ) == 2 ) {
char V_262 [ V_259 ] ;
* V_222 = ( ( V_260 & 0xffff ) << 16 ) + V_261 ;
snprintf ( V_262 , V_259 , L_63 , V_25 -> V_10 -> V_53 , V_53 ) ;
F_162 ( V_53 , V_262 , V_259 ) ;
} else
* V_222 = 0 ;
}
return F_163 ( V_53 , V_42 ) ;
}
static inline char * F_164 ( struct V_24 * V_25 ,
struct V_88 * V_263 )
{
if ( V_263 -> V_53 == NULL ) {
F_66 ( V_25 ,
L_64 ,
V_146 ( V_25 ) ) ;
return NULL ;
}
return F_163 ( V_263 -> V_53 , V_42 ) ;
}
static void F_165 ( struct V_50 * V_51 )
{
struct V_61 * V_62 , * V_264 ;
F_166 (dai, _dai, &component->dai_list, list) {
F_46 ( V_51 -> V_25 , L_65 ,
V_62 -> V_53 ) ;
F_72 ( & V_62 -> V_158 ) ;
F_17 ( V_62 -> V_53 ) ;
F_17 ( V_62 ) ;
}
}
static int F_167 ( struct V_50 * V_51 ,
struct V_88 * V_263 , T_1 V_18 ,
bool V_265 )
{
struct V_24 * V_25 = V_51 -> V_25 ;
struct V_61 * V_62 ;
unsigned int V_3 ;
int V_14 ;
F_46 ( V_25 , L_66 , V_146 ( V_25 ) , V_18 ) ;
V_51 -> V_263 = V_263 ;
V_51 -> V_266 = V_18 ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ ) {
V_62 = F_91 ( sizeof( struct V_61 ) , V_42 ) ;
if ( V_62 == NULL ) {
V_14 = - V_43 ;
goto V_137;
}
if ( V_18 == 1 && V_265 ) {
V_62 -> V_53 = F_161 ( V_25 , & V_62 -> V_222 ) ;
} else {
V_62 -> V_53 = F_164 ( V_25 , & V_263 [ V_3 ] ) ;
if ( V_263 [ V_3 ] . V_222 )
V_62 -> V_222 = V_263 [ V_3 ] . V_222 ;
else
V_62 -> V_222 = V_3 ;
}
if ( V_62 -> V_53 == NULL ) {
F_17 ( V_62 ) ;
V_14 = - V_43 ;
goto V_137;
}
V_62 -> V_51 = V_51 ;
V_62 -> V_25 = V_25 ;
V_62 -> V_10 = & V_263 [ V_3 ] ;
if ( ! V_62 -> V_10 -> V_90 )
V_62 -> V_10 -> V_90 = & V_267 ;
F_88 ( & V_62 -> V_158 , & V_51 -> V_268 ) ;
F_46 ( V_25 , L_67 , V_62 -> V_53 ) ;
}
return 0 ;
V_137:
F_165 ( V_51 ) ;
return V_14 ;
}
static void F_168 ( struct V_148 * V_98 ,
enum V_269 type , int V_270 )
{
struct V_50 * V_51 = V_98 -> V_51 ;
V_51 -> V_10 -> V_271 ( V_51 , type , V_270 ) ;
}
static int F_169 ( struct V_148 * V_98 ,
int V_272 )
{
struct V_50 * V_51 = V_98 -> V_51 ;
return V_51 -> V_10 -> V_273 ( V_51 , V_272 ) ;
}
static int F_170 ( struct V_50 * V_51 ,
const struct V_274 * V_10 , struct V_24 * V_25 )
{
struct V_148 * V_98 ;
V_51 -> V_53 = F_161 ( V_25 , & V_51 -> V_222 ) ;
if ( ! V_51 -> V_53 ) {
F_66 ( V_25 , L_68 ) ;
return - V_43 ;
}
V_51 -> V_25 = V_25 ;
V_51 -> V_10 = V_10 ;
V_51 -> V_153 = V_51 -> V_10 -> V_153 ;
V_51 -> remove = V_51 -> V_10 -> remove ;
if ( ! V_51 -> V_275 )
V_51 -> V_275 = & V_51 -> V_98 ;
V_98 = V_51 -> V_275 ;
V_98 -> V_25 = V_25 ;
V_98 -> V_51 = V_51 ;
V_98 -> V_100 = V_107 ;
V_98 -> V_106 = true ;
if ( V_10 -> V_271 )
V_98 -> V_271 = F_168 ;
if ( V_10 -> V_273 )
V_98 -> V_273 = F_169 ;
V_51 -> V_154 = V_10 -> V_154 ;
V_51 -> V_155 = V_10 -> V_155 ;
V_51 -> V_150 = V_10 -> V_150 ;
V_51 -> V_151 = V_10 -> V_151 ;
V_51 -> V_156 = V_10 -> V_156 ;
V_51 -> V_157 = V_10 -> V_157 ;
F_96 ( & V_51 -> V_268 ) ;
F_95 ( & V_51 -> V_276 ) ;
return 0 ;
}
static void F_171 ( struct V_50 * V_51 )
{
int V_277 = F_172 ( V_51 -> V_108 ) ;
if ( V_277 > 0 )
V_51 -> V_277 = V_277 ;
}
void F_173 ( struct V_50 * V_51 ,
struct V_108 * V_108 )
{
V_51 -> V_108 = V_108 ;
F_171 ( V_51 ) ;
}
void F_174 ( struct V_50 * V_51 )
{
F_175 ( V_51 -> V_108 ) ;
V_51 -> V_108 = NULL ;
}
static void F_176 ( struct V_50 * V_51 )
{
if ( ! V_51 -> V_278 && ! V_51 -> V_279 ) {
if ( ! V_51 -> V_108 )
V_51 -> V_108 = F_177 ( V_51 -> V_25 , NULL ) ;
if ( V_51 -> V_108 )
F_171 ( V_51 ) ;
}
F_88 ( & V_51 -> V_158 , & V_280 ) ;
}
static void F_178 ( struct V_50 * V_51 )
{
F_36 ( & V_60 ) ;
F_176 ( V_51 ) ;
F_38 ( & V_60 ) ;
}
static void F_179 ( struct V_50 * V_51 )
{
F_165 ( V_51 ) ;
F_17 ( V_51 -> V_53 ) ;
}
static void F_180 ( struct V_50 * V_51 )
{
F_72 ( & V_51 -> V_158 ) ;
}
int F_181 ( struct V_24 * V_25 ,
const struct V_274 * V_281 ,
struct V_88 * V_263 ,
int V_266 )
{
struct V_50 * V_282 ;
int V_14 ;
V_282 = F_91 ( sizeof( * V_282 ) , V_42 ) ;
if ( ! V_282 ) {
F_66 ( V_25 , L_69 ) ;
return - V_43 ;
}
V_14 = F_170 ( V_282 , V_281 , V_25 ) ;
if ( V_14 )
goto V_283;
V_282 -> V_284 = true ;
V_282 -> V_285 = true ;
V_14 = F_167 ( V_282 , V_263 , V_266 , true ) ;
if ( V_14 < 0 ) {
F_66 ( V_25 , L_70 , V_14 ) ;
goto V_286;
}
F_178 ( V_282 ) ;
return 0 ;
V_286:
F_179 ( V_282 ) ;
V_283:
F_17 ( V_282 ) ;
return V_14 ;
}
void F_182 ( struct V_24 * V_25 )
{
struct V_50 * V_282 ;
F_36 ( & V_60 ) ;
F_37 (cmpnt, &component_list, list) {
if ( V_25 == V_282 -> V_25 && V_282 -> V_285 )
goto V_258;
}
F_38 ( & V_60 ) ;
return;
V_258:
F_180 ( V_282 ) ;
F_38 ( & V_60 ) ;
F_179 ( V_282 ) ;
F_17 ( V_282 ) ;
}
static int F_183 ( struct V_50 * V_51 )
{
struct V_63 * V_64 = F_184 ( V_51 ) ;
return V_64 -> V_10 -> V_153 ( V_64 ) ;
}
static void F_185 ( struct V_50 * V_51 )
{
struct V_63 * V_64 = F_184 ( V_51 ) ;
V_64 -> V_10 -> remove ( V_64 ) ;
}
int F_186 ( struct V_24 * V_25 , struct V_63 * V_64 ,
const struct V_287 * V_288 )
{
int V_14 ;
V_14 = F_170 ( & V_64 -> V_51 ,
& V_288 -> V_289 , V_25 ) ;
if ( V_14 )
return V_14 ;
V_64 -> V_25 = V_25 ;
V_64 -> V_10 = V_288 ;
if ( V_288 -> V_153 )
V_64 -> V_51 . V_153 = F_183 ;
if ( V_288 -> remove )
V_64 -> V_51 . remove = F_185 ;
#ifdef F_104
V_64 -> V_51 . V_52 = L_71 ;
#endif
F_36 ( & V_60 ) ;
F_176 ( & V_64 -> V_51 ) ;
F_88 ( & V_64 -> V_158 , & V_290 ) ;
F_38 ( & V_60 ) ;
F_46 ( V_25 , L_72 ,
V_64 -> V_51 . V_53 ) ;
return 0 ;
}
int F_187 ( struct V_24 * V_25 ,
const struct V_287 * V_288 )
{
struct V_63 * V_64 ;
int V_14 ;
F_46 ( V_25 , L_73 , V_146 ( V_25 ) ) ;
V_64 = F_91 ( sizeof( struct V_63 ) , V_42 ) ;
if ( V_64 == NULL )
return - V_43 ;
V_14 = F_186 ( V_25 , V_64 , V_288 ) ;
if ( V_14 )
F_17 ( V_64 ) ;
return V_14 ;
}
void F_188 ( struct V_63 * V_64 )
{
F_36 ( & V_60 ) ;
F_72 ( & V_64 -> V_158 ) ;
F_180 ( & V_64 -> V_51 ) ;
F_38 ( & V_60 ) ;
F_46 ( V_64 -> V_25 , L_74 ,
V_64 -> V_51 . V_53 ) ;
F_179 ( & V_64 -> V_51 ) ;
}
struct V_63 * F_189 ( struct V_24 * V_25 )
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
void F_190 ( struct V_24 * V_25 )
{
struct V_63 * V_64 ;
V_64 = F_189 ( V_25 ) ;
if ( ! V_64 )
return;
F_188 ( V_64 ) ;
F_17 ( V_64 ) ;
}
static void F_191 ( struct V_291 * V_71 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_126 ( V_292 ) ; V_3 ++ )
if ( V_71 -> V_293 & V_292 [ V_3 ] )
V_71 -> V_293 |= V_292 [ V_3 ] ;
}
static int F_192 ( struct V_50 * V_51 )
{
struct V_4 * V_5 = F_33 ( V_51 ) ;
return V_5 -> V_10 -> V_153 ( V_5 ) ;
}
static void F_193 ( struct V_50 * V_51 )
{
struct V_4 * V_5 = F_33 ( V_51 ) ;
V_5 -> V_10 -> remove ( V_5 ) ;
}
static int F_194 ( struct V_50 * V_51 ,
unsigned int V_6 , unsigned int V_1 )
{
struct V_4 * V_5 = F_33 ( V_51 ) ;
return V_5 -> V_10 -> V_278 ( V_5 , V_6 , V_1 ) ;
}
static int F_195 ( struct V_50 * V_51 ,
unsigned int V_6 , unsigned int * V_1 )
{
struct V_4 * V_5 = F_33 ( V_51 ) ;
* V_1 = V_5 -> V_10 -> V_279 ( V_5 , V_6 ) ;
return 0 ;
}
static int F_196 ( struct V_148 * V_98 ,
enum V_294 V_295 )
{
struct V_4 * V_5 = F_197 ( V_98 ) ;
return V_5 -> V_10 -> V_296 ( V_5 , V_295 ) ;
}
int F_198 ( struct V_24 * V_25 ,
const struct V_297 * V_298 ,
struct V_88 * V_263 ,
int V_266 )
{
struct V_4 * V_5 ;
struct V_61 * V_62 ;
int V_14 , V_3 ;
F_46 ( V_25 , L_75 , V_146 ( V_25 ) ) ;
V_5 = F_91 ( sizeof( struct V_4 ) , V_42 ) ;
if ( V_5 == NULL )
return - V_43 ;
V_5 -> V_51 . V_275 = & V_5 -> V_98 ;
V_5 -> V_51 . V_5 = V_5 ;
V_14 = F_170 ( & V_5 -> V_51 ,
& V_298 -> V_289 , V_25 ) ;
if ( V_14 )
goto V_283;
if ( V_298 -> V_154 ) {
V_5 -> V_51 . V_154 = V_298 -> V_154 ;
V_5 -> V_51 . V_155 = V_298 -> V_155 ;
}
if ( V_298 -> V_150 ) {
V_5 -> V_51 . V_150 = V_298 -> V_150 ;
V_5 -> V_51 . V_151 = V_298 -> V_151 ;
}
if ( V_298 -> V_156 ) {
V_5 -> V_51 . V_156 = V_298 -> V_156 ;
V_5 -> V_51 . V_157 = V_298 -> V_157 ;
}
if ( V_298 -> V_153 )
V_5 -> V_51 . V_153 = F_192 ;
if ( V_298 -> remove )
V_5 -> V_51 . remove = F_193 ;
if ( V_298 -> V_278 )
V_5 -> V_51 . V_278 = F_194 ;
if ( V_298 -> V_279 )
V_5 -> V_51 . V_279 = F_195 ;
V_5 -> V_51 . V_284 = V_298 -> V_284 ;
V_5 -> V_98 . V_106 = V_298 -> V_106 ;
V_5 -> V_98 . V_299 = V_298 -> V_299 ;
if ( V_298 -> V_271 )
V_5 -> V_98 . V_271 = V_298 -> V_271 ;
if ( V_298 -> V_296 )
V_5 -> V_98 . V_296 = F_196 ;
V_5 -> V_25 = V_25 ;
V_5 -> V_10 = V_298 ;
V_5 -> V_51 . V_277 = V_298 -> V_13 ;
#ifdef F_104
V_5 -> V_51 . V_57 = F_32 ;
V_5 -> V_51 . V_52 = L_76 ;
#endif
if ( V_298 -> V_300 )
V_5 -> V_51 . V_108 = V_298 -> V_300 ( V_25 ) ;
for ( V_3 = 0 ; V_3 < V_266 ; V_3 ++ ) {
F_191 ( & V_263 [ V_3 ] . V_301 ) ;
F_191 ( & V_263 [ V_3 ] . V_302 ) ;
}
V_14 = F_167 ( & V_5 -> V_51 , V_263 , V_266 , false ) ;
if ( V_14 < 0 ) {
F_66 ( V_25 , L_70 , V_14 ) ;
goto V_286;
}
F_37 (dai, &codec->component.dai_list, list)
V_62 -> V_5 = V_5 ;
F_36 ( & V_60 ) ;
F_176 ( & V_5 -> V_51 ) ;
F_88 ( & V_5 -> V_158 , & V_303 ) ;
F_38 ( & V_60 ) ;
F_46 ( V_5 -> V_25 , L_77 ,
V_5 -> V_51 . V_53 ) ;
return 0 ;
V_286:
F_179 ( & V_5 -> V_51 ) ;
V_283:
F_17 ( V_5 ) ;
return V_14 ;
}
void F_199 ( struct V_24 * V_25 )
{
struct V_4 * V_5 ;
F_36 ( & V_60 ) ;
F_37 (codec, &codec_list, list) {
if ( V_25 == V_5 -> V_25 )
goto V_258;
}
F_38 ( & V_60 ) ;
return;
V_258:
F_72 ( & V_5 -> V_158 ) ;
F_180 ( & V_5 -> V_51 ) ;
F_38 ( & V_60 ) ;
F_46 ( V_5 -> V_25 , L_78 ,
V_5 -> V_51 . V_53 ) ;
F_179 ( & V_5 -> V_51 ) ;
F_200 ( V_5 ) ;
F_17 ( V_5 ) ;
}
int F_201 ( struct V_65 * V_55 ,
const char * V_304 )
{
struct V_118 * V_305 ;
int V_14 ;
if ( ! V_55 -> V_25 ) {
F_202 ( L_79 , V_306 ) ;
return - V_17 ;
}
V_305 = V_55 -> V_25 -> V_119 ;
V_14 = F_203 ( V_305 , V_304 , 0 , & V_55 -> V_53 ) ;
if ( V_14 < 0 && V_14 != - V_17 ) {
F_66 ( V_55 -> V_25 ,
L_80 ,
V_304 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
int F_204 ( struct V_65 * V_55 ,
const char * V_304 )
{
struct V_118 * V_305 = V_55 -> V_25 -> V_119 ;
struct V_170 * V_307 ;
const char * V_216 , * V_308 ;
int V_3 , V_79 , V_309 , V_14 ;
V_309 = F_205 ( V_305 , V_304 ) ;
if ( V_309 < 0 ) {
F_66 ( V_55 -> V_25 ,
L_81 , V_304 ) ;
return - V_17 ;
}
if ( V_309 & 1 ) {
F_66 ( V_55 -> V_25 ,
L_82 , V_304 ) ;
return - V_17 ;
}
V_309 /= 2 ;
if ( ! V_309 ) {
F_66 ( V_55 -> V_25 , L_83 ,
V_304 ) ;
return - V_17 ;
}
V_307 = F_206 ( V_55 -> V_25 , V_309 , sizeof( * V_307 ) ,
V_42 ) ;
if ( ! V_307 ) {
F_66 ( V_55 -> V_25 ,
L_84 ) ;
return - V_43 ;
}
for ( V_3 = 0 ; V_3 < V_309 ; V_3 ++ ) {
V_14 = F_203 ( V_305 , V_304 ,
2 * V_3 , & V_216 ) ;
if ( V_14 ) {
F_66 ( V_55 -> V_25 ,
L_85 ,
V_304 , 2 * V_3 , V_14 ) ;
return - V_17 ;
}
for ( V_79 = 0 ; V_79 < F_126 ( V_310 ) ; V_79 ++ ) {
if ( ! strncmp ( V_216 , V_310 [ V_79 ] . V_53 ,
strlen ( V_310 [ V_79 ] . V_53 ) ) ) {
V_307 [ V_3 ] = V_310 [ V_79 ] ;
break;
}
}
if ( V_79 >= F_126 ( V_310 ) ) {
F_66 ( V_55 -> V_25 ,
L_86 ,
V_216 ) ;
return - V_17 ;
}
V_14 = F_203 ( V_305 , V_304 ,
( 2 * V_3 ) + 1 ,
& V_308 ) ;
if ( V_14 ) {
F_66 ( V_55 -> V_25 ,
L_85 ,
V_304 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_17 ;
}
V_307 [ V_3 ] . V_53 = V_308 ;
}
V_55 -> V_150 = V_307 ;
V_55 -> V_151 = V_309 ;
return 0 ;
}
int F_207 ( struct V_118 * V_305 ,
unsigned int * V_238 ,
unsigned int * V_241 )
{
T_6 V_1 ;
int V_14 ;
if ( F_208 ( V_305 , L_87 ) ) {
V_14 = F_209 ( V_305 , L_87 , & V_1 ) ;
if ( V_14 )
return V_14 ;
if ( V_238 )
* V_238 = V_1 ;
}
if ( F_208 ( V_305 , L_88 ) ) {
V_14 = F_209 ( V_305 , L_88 , & V_1 ) ;
if ( V_14 )
return V_14 ;
if ( V_241 )
* V_241 = V_1 ;
}
return 0 ;
}
int F_210 ( struct V_65 * V_55 ,
const char * V_304 )
{
struct V_118 * V_305 = V_55 -> V_25 -> V_119 ;
int V_311 ;
struct V_312 * V_313 ;
int V_3 , V_14 ;
V_311 = F_205 ( V_305 , V_304 ) ;
if ( V_311 < 0 || V_311 & 1 ) {
F_66 ( V_55 -> V_25 ,
L_89 ,
V_304 ) ;
return - V_17 ;
}
V_311 /= 2 ;
if ( ! V_311 ) {
F_66 ( V_55 -> V_25 , L_83 ,
V_304 ) ;
return - V_17 ;
}
V_313 = F_159 ( V_55 -> V_25 , V_311 * sizeof( * V_313 ) ,
V_42 ) ;
if ( ! V_313 ) {
F_66 ( V_55 -> V_25 ,
L_90 ) ;
return - V_17 ;
}
for ( V_3 = 0 ; V_3 < V_311 ; V_3 ++ ) {
V_14 = F_203 ( V_305 , V_304 ,
2 * V_3 , & V_313 [ V_3 ] . V_314 ) ;
if ( V_14 ) {
F_66 ( V_55 -> V_25 ,
L_91 ,
V_304 , 2 * V_3 , V_14 ) ;
return - V_17 ;
}
V_14 = F_203 ( V_305 , V_304 ,
( 2 * V_3 ) + 1 , & V_313 [ V_3 ] . V_227 ) ;
if ( V_14 ) {
F_66 ( V_55 -> V_25 ,
L_91 ,
V_304 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_17 ;
}
}
V_55 -> V_157 = V_311 ;
V_55 -> V_156 = V_313 ;
return 0 ;
}
unsigned int F_211 ( struct V_118 * V_305 ,
const char * V_215 ,
struct V_118 * * V_315 ,
struct V_118 * * V_316 )
{
int V_14 , V_3 ;
char V_317 [ 128 ] ;
unsigned int V_318 = 0 ;
int V_319 , V_320 ;
const char * V_321 ;
struct {
char * V_53 ;
unsigned int V_1 ;
} V_322 [] = {
{ L_92 , V_323 } ,
{ L_93 , V_324 } ,
{ L_94 , V_325 } ,
{ L_95 , V_326 } ,
{ L_96 , V_327 } ,
{ L_97 , V_328 } ,
{ L_98 , V_329 } ,
{ L_99 , V_330 } ,
{ L_100 , V_331 } ,
} ;
if ( ! V_215 )
V_215 = L_101 ;
snprintf ( V_317 , sizeof( V_317 ) , L_102 , V_215 ) ;
V_14 = F_212 ( V_305 , V_317 , & V_321 ) ;
if ( V_14 == 0 ) {
for ( V_3 = 0 ; V_3 < F_126 ( V_322 ) ; V_3 ++ ) {
if ( strcmp ( V_321 , V_322 [ V_3 ] . V_53 ) == 0 ) {
V_318 |= V_322 [ V_3 ] . V_1 ;
break;
}
}
}
snprintf ( V_317 , sizeof( V_317 ) , L_103 , V_215 ) ;
if ( F_213 ( V_305 , V_317 , NULL ) )
V_318 |= V_332 ;
else
V_318 |= V_333 ;
snprintf ( V_317 , sizeof( V_317 ) , L_104 , V_215 ) ;
V_319 = ! ! F_213 ( V_305 , V_317 , NULL ) ;
snprintf ( V_317 , sizeof( V_317 ) , L_105 , V_215 ) ;
V_320 = ! ! F_213 ( V_305 , V_317 , NULL ) ;
switch ( ( V_319 << 4 ) + V_320 ) {
case 0x11 :
V_318 |= V_334 ;
break;
case 0x10 :
V_318 |= V_335 ;
break;
case 0x01 :
V_318 |= V_336 ;
break;
default:
break;
}
snprintf ( V_317 , sizeof( V_317 ) , L_106 , V_215 ) ;
V_319 = ! ! F_213 ( V_305 , V_317 , NULL ) ;
if ( V_319 && V_315 )
* V_315 = F_214 ( V_305 , V_317 , 0 ) ;
snprintf ( V_317 , sizeof( V_317 ) , L_107 , V_215 ) ;
V_320 = ! ! F_213 ( V_305 , V_317 , NULL ) ;
if ( V_320 && V_316 )
* V_316 = F_214 ( V_305 , V_317 , 0 ) ;
switch ( ( V_319 << 4 ) + V_320 ) {
case 0x11 :
V_318 |= V_191 ;
break;
case 0x10 :
V_318 |= V_193 ;
break;
case 0x01 :
V_318 |= V_194 ;
break;
default:
V_318 |= V_192 ;
break;
}
return V_318 ;
}
static int F_215 ( struct V_337 * args ,
const char * * V_122 )
{
struct V_50 * V_19 ;
int V_14 = - V_131 ;
F_36 ( & V_60 ) ;
F_37 (pos, &component_list, list) {
if ( V_19 -> V_25 -> V_119 != args -> V_305 )
continue;
if ( V_19 -> V_10 -> V_338 ) {
V_14 = V_19 -> V_10 -> V_338 ( V_19 ,
args ,
V_122 ) ;
} else {
int V_222 = - 1 ;
switch ( args -> V_339 ) {
case 0 :
V_222 = 0 ;
break;
case 1 :
V_222 = args -> args [ 0 ] ;
break;
default:
break;
}
if ( V_222 < 0 || V_222 >= V_19 -> V_266 ) {
V_14 = - V_17 ;
continue;
}
V_14 = 0 ;
* V_122 = V_19 -> V_263 [ V_222 ] . V_53 ;
if ( ! * V_122 )
* V_122 = V_19 -> V_53 ;
}
break;
}
F_38 ( & V_60 ) ;
return V_14 ;
}
int F_216 ( struct V_118 * V_119 ,
const char * * V_122 )
{
struct V_337 args ;
int V_14 ;
V_14 = F_217 ( V_119 , L_108 ,
L_109 , 0 , & args ) ;
if ( V_14 )
return V_14 ;
V_14 = F_215 ( & args , V_122 ) ;
F_218 ( args . V_305 ) ;
return V_14 ;
}
int F_219 ( struct V_24 * V_25 ,
struct V_118 * V_119 ,
struct V_124 * V_70 )
{
struct V_337 args ;
struct V_120 * V_51 ;
char * V_53 ;
int V_218 , V_86 , V_14 ;
V_53 = L_108 ;
V_86 = F_220 ( V_119 , V_53 ,
L_109 ) ;
if ( V_86 <= 0 ) {
if ( V_86 == - V_340 )
F_66 ( V_25 , L_110 ) ;
else
F_66 ( V_25 , L_111 ) ;
return V_86 ;
}
V_51 = F_159 ( V_25 ,
sizeof *V_51 * V_86 ,
V_42 ) ;
if ( ! V_51 )
return - V_43 ;
V_70 -> V_125 = V_51 ;
V_70 -> V_86 = V_86 ;
for ( V_218 = 0 , V_51 = V_70 -> V_125 ;
V_218 < V_70 -> V_86 ;
V_218 ++ , V_51 ++ ) {
V_14 = F_217 ( V_119 , V_53 ,
L_109 ,
V_218 , & args ) ;
if ( V_14 )
goto V_137;
V_51 -> V_119 = args . V_305 ;
V_14 = F_215 ( & args , & V_51 -> V_122 ) ;
if ( V_14 < 0 )
goto V_137;
}
return 0 ;
V_137:
for ( V_218 = 0 , V_51 = V_70 -> V_125 ;
V_218 < V_70 -> V_86 ;
V_218 ++ , V_51 ++ ) {
if ( ! V_51 -> V_119 )
break;
F_218 ( V_51 -> V_119 ) ;
V_51 -> V_119 = NULL ;
}
V_70 -> V_125 = NULL ;
V_70 -> V_86 = 0 ;
return V_14 ;
}
static int T_7 F_221 ( void )
{
#ifdef F_104
V_66 = F_26 ( L_112 , NULL ) ;
if ( F_222 ( V_66 ) || ! V_66 ) {
F_223 ( L_113 ) ;
V_66 = NULL ;
}
if ( ! F_34 ( L_114 , 0444 , V_66 , NULL ,
& V_341 ) )
F_223 ( L_115 ) ;
if ( ! F_34 ( L_116 , 0444 , V_66 , NULL ,
& V_342 ) )
F_223 ( L_117 ) ;
if ( ! F_34 ( L_118 , 0444 , V_66 , NULL ,
& V_343 ) )
F_223 ( L_119 ) ;
#endif
F_224 () ;
return F_225 ( & V_344 ) ;
}
static void T_8 F_226 ( void )
{
F_227 () ;
#ifdef F_104
F_31 ( V_66 ) ;
#endif
F_228 ( & V_344 ) ;
}
