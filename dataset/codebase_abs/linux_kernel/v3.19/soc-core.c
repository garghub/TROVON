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
static T_2 F_12 ( struct V_32 * V_32 , char T_4 * V_33 ,
T_1 V_18 , T_3 * V_34 )
{
T_2 V_14 ;
struct V_4 * V_5 = V_32 -> V_35 ;
char * V_7 ;
if ( * V_34 < 0 || ! V_18 )
return - V_17 ;
V_7 = F_13 ( V_18 , V_36 ) ;
if ( ! V_7 )
return - V_37 ;
V_14 = F_5 ( V_5 , V_7 , V_18 , * V_34 ) ;
if ( V_14 >= 0 ) {
if ( F_14 ( V_33 , V_7 , V_14 ) ) {
F_15 ( V_7 ) ;
return - V_38 ;
}
* V_34 += V_14 ;
}
F_15 ( V_7 ) ;
return V_14 ;
}
static T_2 F_16 ( struct V_32 * V_32 ,
const char T_4 * V_33 , T_1 V_18 , T_3 * V_34 )
{
char V_7 [ 32 ] ;
T_1 V_39 ;
char * V_40 = V_7 ;
unsigned long V_6 , V_41 ;
struct V_4 * V_5 = V_32 -> V_35 ;
int V_14 ;
V_39 = F_6 ( V_18 , ( sizeof( V_7 ) - 1 ) ) ;
if ( F_17 ( V_7 , V_33 , V_39 ) )
return - V_38 ;
V_7 [ V_39 ] = 0 ;
while ( * V_40 == ' ' )
V_40 ++ ;
V_6 = F_18 ( V_40 , & V_40 , 16 ) ;
while ( * V_40 == ' ' )
V_40 ++ ;
V_14 = F_19 ( V_40 , 16 , & V_41 ) ;
if ( V_14 )
return V_14 ;
F_20 ( V_42 , V_43 ) ;
F_21 ( V_5 , V_6 , V_41 ) ;
return V_39 ;
}
static void F_22 ( struct V_44 * V_45 )
{
if ( V_45 -> V_46 ) {
char * V_47 ;
V_47 = F_23 ( V_36 , L_4 ,
V_45 -> V_46 , V_45 -> V_47 ) ;
if ( V_47 ) {
V_45 -> V_48 = F_24 ( V_47 ,
V_45 -> V_49 -> V_50 ) ;
F_15 ( V_47 ) ;
}
} else {
V_45 -> V_48 = F_24 ( V_45 -> V_47 ,
V_45 -> V_49 -> V_50 ) ;
}
if ( ! V_45 -> V_48 ) {
F_25 ( V_45 -> V_25 ,
L_5 ) ;
return;
}
F_26 ( F_27 ( V_45 ) ,
V_45 -> V_48 ) ;
if ( V_45 -> V_51 )
V_45 -> V_51 ( V_45 ) ;
}
static void F_28 ( struct V_44 * V_45 )
{
F_29 ( V_45 -> V_48 ) ;
}
static void F_30 ( struct V_44 * V_45 )
{
struct V_4 * V_5 = F_31 ( V_45 ) ;
V_5 -> V_52 = F_32 ( L_6 , 0644 ,
V_5 -> V_45 . V_48 ,
V_5 , & V_53 ) ;
if ( ! V_5 -> V_52 )
F_25 ( V_5 -> V_25 ,
L_7 ) ;
}
static T_2 F_33 ( struct V_32 * V_32 , char T_4 * V_33 ,
T_1 V_18 , T_3 * V_34 )
{
char * V_7 = F_13 ( V_30 , V_36 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_4 * V_5 ;
if ( ! V_7 )
return - V_37 ;
F_34 (codec, &codec_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_30 - V_14 , L_8 ,
V_5 -> V_45 . V_47 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_30 ) {
V_14 = V_30 ;
break;
}
}
if ( V_14 >= 0 )
V_14 = F_35 ( V_33 , V_18 , V_34 , V_7 , V_14 ) ;
F_15 ( V_7 ) ;
return V_14 ;
}
static T_2 F_36 ( struct V_32 * V_32 , char T_4 * V_33 ,
T_1 V_18 , T_3 * V_34 )
{
char * V_7 = F_13 ( V_30 , V_36 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_44 * V_45 ;
struct V_54 * V_55 ;
if ( ! V_7 )
return - V_37 ;
F_34 (component, &component_list, list) {
F_34 (dai, &component->dai_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_30 - V_14 , L_8 ,
V_55 -> V_47 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_30 ) {
V_14 = V_30 ;
break;
}
}
}
V_14 = F_35 ( V_33 , V_18 , V_34 , V_7 , V_14 ) ;
F_15 ( V_7 ) ;
return V_14 ;
}
static T_2 F_37 ( struct V_32 * V_32 ,
char T_4 * V_33 ,
T_1 V_18 , T_3 * V_34 )
{
char * V_7 = F_13 ( V_30 , V_36 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_56 * V_57 ;
if ( ! V_7 )
return - V_37 ;
F_34 (platform, &platform_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_30 - V_14 , L_8 ,
V_57 -> V_45 . V_47 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_30 ) {
V_14 = V_30 ;
break;
}
}
V_14 = F_35 ( V_33 , V_18 , V_34 , V_7 , V_14 ) ;
F_15 ( V_7 ) ;
return V_14 ;
}
static void F_38 ( struct V_58 * V_49 )
{
V_49 -> V_50 = F_24 ( V_49 -> V_47 ,
V_59 ) ;
if ( ! V_49 -> V_50 ) {
F_25 ( V_49 -> V_25 ,
L_9 ) ;
return;
}
V_49 -> V_60 = F_39 ( L_10 , 0644 ,
V_49 -> V_50 ,
& V_49 -> V_61 ) ;
if ( ! V_49 -> V_60 )
F_25 ( V_49 -> V_25 ,
L_11 ) ;
}
static void F_40 ( struct V_58 * V_49 )
{
F_29 ( V_49 -> V_50 ) ;
}
static inline void F_22 (
struct V_44 * V_45 )
{
}
static inline void F_28 (
struct V_44 * V_45 )
{
}
static inline void F_38 ( struct V_58 * V_49 )
{
}
static inline void F_40 ( struct V_58 * V_49 )
{
}
struct V_62 * F_41 ( struct V_58 * V_49 ,
const char * V_63 , int V_64 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_49 -> V_65 ; V_3 ++ ) {
if ( V_49 -> V_29 [ V_3 ] . V_63 -> V_66 &&
! strcmp ( V_49 -> V_29 [ V_3 ] . V_63 -> V_47 , V_63 ) )
return V_49 -> V_29 [ V_3 ] . V_67 -> V_68 [ V_64 ] . V_69 ;
}
F_42 ( V_49 -> V_25 , L_12 , V_63 ) ;
return NULL ;
}
struct V_28 * F_43 ( struct V_58 * V_49 ,
const char * V_63 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_49 -> V_65 ; V_3 ++ ) {
if ( ! strcmp ( V_49 -> V_29 [ V_3 ] . V_63 -> V_47 , V_63 ) )
return & V_49 -> V_29 [ V_3 ] ;
}
F_42 ( V_49 -> V_25 , L_13 , V_63 ) ;
return NULL ;
}
static void F_44 ( struct V_70 * V_71 )
{
}
int F_45 ( struct V_24 * V_25 )
{
struct V_58 * V_49 = F_8 ( V_25 ) ;
struct V_4 * V_5 ;
int V_3 , V_72 ;
if ( ! V_49 -> V_73 )
return 0 ;
F_46 ( V_49 -> V_74 ) ;
F_47 ( V_49 -> V_74 , V_75 ) ;
F_48 ( V_49 -> V_74 ) ;
F_49 ( V_49 -> V_74 , V_76 ) ;
for ( V_3 = 0 ; V_3 < V_49 -> V_77 ; V_3 ++ ) {
if ( V_49 -> V_29 [ V_3 ] . V_63 -> V_78 )
continue;
for ( V_72 = 0 ; V_72 < V_49 -> V_29 [ V_3 ] . V_79 ; V_72 ++ ) {
struct V_54 * V_55 = V_49 -> V_29 [ V_3 ] . V_80 [ V_72 ] ;
struct V_81 * V_82 = V_55 -> V_10 ;
if ( V_82 -> V_83 -> V_84 && V_55 -> V_85 )
V_82 -> V_83 -> V_84 ( V_55 , 1 ) ;
}
}
for ( V_3 = 0 ; V_3 < V_49 -> V_77 ; V_3 ++ ) {
if ( V_49 -> V_29 [ V_3 ] . V_63 -> V_78 )
continue;
F_50 ( V_49 -> V_29 [ V_3 ] . V_67 ) ;
}
if ( V_49 -> V_86 )
V_49 -> V_86 ( V_49 ) ;
for ( V_3 = 0 ; V_3 < V_49 -> V_77 ; V_3 ++ ) {
struct V_54 * V_87 = V_49 -> V_29 [ V_3 ] . V_87 ;
if ( V_49 -> V_29 [ V_3 ] . V_63 -> V_78 )
continue;
if ( V_87 -> V_10 -> V_88 && ! V_87 -> V_10 -> V_89 )
V_87 -> V_10 -> V_88 ( V_87 ) ;
}
for ( V_3 = 0 ; V_3 < V_49 -> V_77 ; V_3 ++ ) {
struct V_54 * * V_80 = V_49 -> V_29 [ V_3 ] . V_80 ;
F_51 ( & V_49 -> V_29 [ V_3 ] . V_90 ) ;
for ( V_72 = 0 ; V_72 < V_49 -> V_29 [ V_3 ] . V_79 ; V_72 ++ ) {
V_80 [ V_72 ] -> V_5 -> V_91 . V_92 =
V_80 [ V_72 ] -> V_5 -> V_91 . V_93 ;
}
}
for ( V_3 = 0 ; V_3 < V_49 -> V_77 ; V_3 ++ ) {
if ( V_49 -> V_29 [ V_3 ] . V_63 -> V_78 )
continue;
F_52 ( & V_49 -> V_29 [ V_3 ] ,
V_94 ,
V_95 ) ;
F_52 ( & V_49 -> V_29 [ V_3 ] ,
V_96 ,
V_95 ) ;
}
F_53 ( V_49 ) ;
F_54 ( & V_49 -> V_91 ) ;
F_34 (codec, &card->codec_dev_list, card_list) {
if ( ! V_5 -> V_97 ) {
switch ( V_5 -> V_91 . V_93 ) {
case V_98 :
if ( V_5 -> V_91 . V_99 ) {
F_42 ( V_5 -> V_25 ,
L_14 ) ;
break;
}
case V_100 :
if ( V_5 -> V_10 -> V_88 )
V_5 -> V_10 -> V_88 ( V_5 ) ;
V_5 -> V_97 = 1 ;
if ( V_5 -> V_45 . V_101 )
F_55 ( V_5 -> V_45 . V_101 ) ;
F_56 ( V_5 -> V_25 ) ;
break;
default:
F_42 ( V_5 -> V_25 ,
L_15 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_49 -> V_77 ; V_3 ++ ) {
struct V_54 * V_87 = V_49 -> V_29 [ V_3 ] . V_87 ;
if ( V_49 -> V_29 [ V_3 ] . V_63 -> V_78 )
continue;
if ( V_87 -> V_10 -> V_88 && V_87 -> V_10 -> V_89 )
V_87 -> V_10 -> V_88 ( V_87 ) ;
F_56 ( V_87 -> V_25 ) ;
}
if ( V_49 -> V_102 )
V_49 -> V_102 ( V_49 ) ;
return 0 ;
}
static void F_57 ( struct V_70 * V_71 )
{
struct V_58 * V_49 =
F_58 ( V_71 , struct V_58 , V_103 ) ;
struct V_4 * V_5 ;
int V_3 , V_72 ;
F_42 ( V_49 -> V_25 , L_16 ) ;
F_49 ( V_49 -> V_74 , V_104 ) ;
if ( V_49 -> V_105 )
V_49 -> V_105 ( V_49 ) ;
for ( V_3 = 0 ; V_3 < V_49 -> V_77 ; V_3 ++ ) {
struct V_54 * V_87 = V_49 -> V_29 [ V_3 ] . V_87 ;
if ( V_49 -> V_29 [ V_3 ] . V_63 -> V_78 )
continue;
if ( V_87 -> V_10 -> V_106 && V_87 -> V_10 -> V_89 )
V_87 -> V_10 -> V_106 ( V_87 ) ;
}
F_34 (codec, &card->codec_dev_list, card_list) {
if ( V_5 -> V_97 ) {
switch ( V_5 -> V_91 . V_93 ) {
case V_98 :
case V_100 :
if ( V_5 -> V_10 -> V_106 )
V_5 -> V_10 -> V_106 ( V_5 ) ;
V_5 -> V_97 = 0 ;
break;
default:
F_42 ( V_5 -> V_25 ,
L_17 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_49 -> V_77 ; V_3 ++ ) {
if ( V_49 -> V_29 [ V_3 ] . V_63 -> V_78 )
continue;
F_52 ( & V_49 -> V_29 [ V_3 ] ,
V_94 ,
V_107 ) ;
F_52 ( & V_49 -> V_29 [ V_3 ] ,
V_96 ,
V_107 ) ;
}
for ( V_3 = 0 ; V_3 < V_49 -> V_77 ; V_3 ++ ) {
if ( V_49 -> V_29 [ V_3 ] . V_63 -> V_78 )
continue;
for ( V_72 = 0 ; V_72 < V_49 -> V_29 [ V_3 ] . V_79 ; V_72 ++ ) {
struct V_54 * V_55 = V_49 -> V_29 [ V_3 ] . V_80 [ V_72 ] ;
struct V_81 * V_82 = V_55 -> V_10 ;
if ( V_82 -> V_83 -> V_84 && V_55 -> V_85 )
V_82 -> V_83 -> V_84 ( V_55 , 0 ) ;
}
}
for ( V_3 = 0 ; V_3 < V_49 -> V_77 ; V_3 ++ ) {
struct V_54 * V_87 = V_49 -> V_29 [ V_3 ] . V_87 ;
if ( V_49 -> V_29 [ V_3 ] . V_63 -> V_78 )
continue;
if ( V_87 -> V_10 -> V_106 && ! V_87 -> V_10 -> V_89 )
V_87 -> V_10 -> V_106 ( V_87 ) ;
}
if ( V_49 -> V_108 )
V_49 -> V_108 ( V_49 ) ;
F_42 ( V_49 -> V_25 , L_18 ) ;
F_49 ( V_49 -> V_74 , V_75 ) ;
F_53 ( V_49 ) ;
F_54 ( & V_49 -> V_91 ) ;
}
int F_59 ( struct V_24 * V_25 )
{
struct V_58 * V_49 = F_8 ( V_25 ) ;
bool V_89 = false ;
int V_3 ;
if ( ! V_49 -> V_73 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_49 -> V_77 ; V_3 ++ ) {
struct V_28 * V_29 = & V_49 -> V_29 [ V_3 ] ;
struct V_54 * * V_80 = V_29 -> V_80 ;
struct V_54 * V_87 = V_29 -> V_87 ;
int V_72 ;
if ( V_87 -> V_109 )
F_60 ( V_87 -> V_25 ) ;
for ( V_72 = 0 ; V_72 < V_29 -> V_79 ; V_72 ++ ) {
struct V_54 * V_110 = V_80 [ V_72 ] ;
if ( V_110 -> V_109 )
F_60 ( V_110 -> V_25 ) ;
}
}
for ( V_3 = 0 ; V_3 < V_49 -> V_77 ; V_3 ++ ) {
struct V_54 * V_87 = V_49 -> V_29 [ V_3 ] . V_87 ;
V_89 |= V_87 -> V_10 -> V_89 ;
}
if ( V_89 ) {
F_42 ( V_25 , L_19 ) ;
F_57 ( & V_49 -> V_103 ) ;
} else {
F_42 ( V_25 , L_20 ) ;
if ( ! F_61 ( & V_49 -> V_103 ) )
F_62 ( V_25 , L_21 ) ;
}
return 0 ;
}
static struct V_44 * F_63 (
const struct V_111 * V_112 , const char * V_47 )
{
struct V_44 * V_45 ;
F_34 (component, &component_list, list) {
if ( V_112 ) {
if ( V_45 -> V_25 -> V_112 == V_112 )
return V_45 ;
} else if ( strcmp ( V_45 -> V_47 , V_47 ) == 0 ) {
return V_45 ;
}
}
return NULL ;
}
static struct V_54 * F_64 (
const struct V_113 * V_114 )
{
struct V_44 * V_45 ;
struct V_54 * V_55 ;
F_34 (component, &component_list, list) {
if ( V_114 -> V_112 && V_45 -> V_25 -> V_112 != V_114 -> V_112 )
continue;
if ( V_114 -> V_47 && strcmp ( V_45 -> V_47 , V_114 -> V_47 ) )
continue;
F_34 (dai, &component->dai_list, list) {
if ( V_114 -> V_115 && strcmp ( V_55 -> V_47 , V_114 -> V_115 ) )
continue;
return V_55 ;
}
}
return NULL ;
}
static int F_65 ( struct V_58 * V_49 , int V_116 )
{
struct V_117 * V_63 = & V_49 -> V_63 [ V_116 ] ;
struct V_28 * V_29 = & V_49 -> V_29 [ V_116 ] ;
struct V_113 * V_118 = V_63 -> V_118 ;
struct V_113 V_119 ;
struct V_54 * * V_80 = V_29 -> V_80 ;
struct V_56 * V_57 ;
const char * V_120 ;
int V_3 ;
F_42 ( V_49 -> V_25 , L_22 , V_63 -> V_47 , V_116 ) ;
V_119 . V_47 = V_63 -> V_121 ;
V_119 . V_112 = V_63 -> V_122 ;
V_119 . V_115 = V_63 -> V_123 ;
V_29 -> V_87 = F_64 ( & V_119 ) ;
if ( ! V_29 -> V_87 ) {
F_62 ( V_49 -> V_25 , L_23 ,
V_63 -> V_123 ) ;
return - V_124 ;
}
V_29 -> V_79 = V_63 -> V_79 ;
for ( V_3 = 0 ; V_3 < V_29 -> V_79 ; V_3 ++ ) {
V_80 [ V_3 ] = F_64 ( & V_118 [ V_3 ] ) ;
if ( ! V_80 [ V_3 ] ) {
F_62 ( V_49 -> V_25 , L_24 ,
V_118 [ V_3 ] . V_115 ) ;
return - V_124 ;
}
}
V_29 -> V_110 = V_80 [ 0 ] ;
V_29 -> V_5 = V_29 -> V_110 -> V_5 ;
V_120 = V_63 -> V_120 ;
if ( ! V_120 && ! V_63 -> V_125 )
V_120 = L_25 ;
F_34 (platform, &platform_list, list) {
if ( V_63 -> V_125 ) {
if ( V_57 -> V_25 -> V_112 !=
V_63 -> V_125 )
continue;
} else {
if ( strcmp ( V_57 -> V_45 . V_47 , V_120 ) )
continue;
}
V_29 -> V_57 = V_57 ;
}
if ( ! V_29 -> V_57 ) {
F_62 ( V_49 -> V_25 , L_26 ,
V_63 -> V_120 ) ;
return - V_124 ;
}
V_49 -> V_77 ++ ;
return 0 ;
}
static void F_66 ( struct V_44 * V_45 )
{
if ( ! V_45 -> V_126 )
return;
if ( V_45 -> V_5 )
F_67 ( & V_45 -> V_5 -> V_127 ) ;
if ( V_45 -> remove )
V_45 -> remove ( V_45 ) ;
F_68 ( F_27 ( V_45 ) ) ;
F_28 ( V_45 ) ;
V_45 -> V_126 = 0 ;
F_69 ( V_45 -> V_25 -> V_10 -> V_128 ) ;
}
static void F_70 ( struct V_54 * V_55 , int V_129 )
{
int V_130 ;
if ( V_55 && V_55 -> V_126 &&
V_55 -> V_10 -> V_131 == V_129 ) {
if ( V_55 -> V_10 -> remove ) {
V_130 = V_55 -> V_10 -> remove ( V_55 ) ;
if ( V_130 < 0 )
F_62 ( V_55 -> V_25 ,
L_27 ,
V_55 -> V_47 , V_130 ) ;
}
V_55 -> V_126 = 0 ;
}
}
static void F_71 ( struct V_58 * V_49 , int V_116 , int V_129 )
{
struct V_28 * V_29 = & V_49 -> V_29 [ V_116 ] ;
int V_3 ;
if ( V_29 -> V_132 ) {
F_72 ( V_29 -> V_25 , & V_133 ) ;
F_72 ( V_29 -> V_25 , & V_134 ) ;
F_73 ( V_29 -> V_25 ) ;
V_29 -> V_132 = 0 ;
}
for ( V_3 = 0 ; V_3 < V_29 -> V_79 ; V_3 ++ )
F_70 ( V_29 -> V_80 [ V_3 ] , V_129 ) ;
F_70 ( V_29 -> V_87 , V_129 ) ;
}
static void F_74 ( struct V_58 * V_49 , int V_116 ,
int V_129 )
{
struct V_28 * V_29 = & V_49 -> V_29 [ V_116 ] ;
struct V_54 * V_87 = V_29 -> V_87 ;
struct V_56 * V_57 = V_29 -> V_57 ;
struct V_44 * V_45 ;
int V_3 ;
if ( V_57 && V_57 -> V_45 . V_10 -> V_131 == V_129 )
F_66 ( & V_57 -> V_45 ) ;
for ( V_3 = 0 ; V_3 < V_29 -> V_79 ; V_3 ++ ) {
V_45 = V_29 -> V_80 [ V_3 ] -> V_45 ;
if ( V_45 -> V_10 -> V_131 == V_129 )
F_66 ( V_45 ) ;
}
if ( V_87 ) {
if ( V_87 -> V_45 -> V_10 -> V_131 == V_129 )
F_66 ( V_87 -> V_45 ) ;
}
}
static void F_75 ( struct V_58 * V_49 )
{
int V_55 , V_129 ;
for ( V_129 = V_135 ; V_129 <= V_136 ;
V_129 ++ ) {
for ( V_55 = 0 ; V_55 < V_49 -> V_77 ; V_55 ++ )
F_71 ( V_49 , V_55 , V_129 ) ;
}
for ( V_129 = V_135 ; V_129 <= V_136 ;
V_129 ++ ) {
for ( V_55 = 0 ; V_55 < V_49 -> V_77 ; V_55 ++ )
F_74 ( V_49 , V_55 , V_129 ) ;
}
V_49 -> V_77 = 0 ;
}
static void F_76 ( struct V_58 * V_49 ,
struct V_44 * V_45 )
{
int V_3 ;
if ( V_49 -> V_137 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_49 -> V_138 ; V_3 ++ ) {
struct V_139 * V_140 = & V_49 -> V_137 [ V_3 ] ;
if ( V_140 -> V_112 && V_45 -> V_25 -> V_112 != V_140 -> V_112 )
continue;
if ( V_140 -> V_141 && strcmp ( V_45 -> V_47 , V_140 -> V_141 ) )
continue;
V_45 -> V_142 = V_140 -> V_142 ;
break;
}
}
static int F_77 ( struct V_58 * V_49 ,
struct V_44 * V_45 )
{
struct V_143 * V_91 = F_27 ( V_45 ) ;
struct V_54 * V_55 ;
int V_14 ;
if ( V_45 -> V_126 )
return 0 ;
V_45 -> V_49 = V_49 ;
V_91 -> V_49 = V_49 ;
F_76 ( V_49 , V_45 ) ;
if ( ! F_78 ( V_45 -> V_25 -> V_10 -> V_128 ) )
return - V_144 ;
F_22 ( V_45 ) ;
if ( V_45 -> V_145 ) {
V_14 = F_79 ( V_91 , V_45 -> V_145 ,
V_45 -> V_146 ) ;
if ( V_14 != 0 ) {
F_62 ( V_45 -> V_25 ,
L_28 , V_14 ) ;
goto V_147;
}
}
F_34 (dai, &component->dai_list, list) {
V_14 = F_80 ( V_91 , V_55 ) ;
if ( V_14 != 0 ) {
F_62 ( V_45 -> V_25 ,
L_29 , V_14 ) ;
goto V_147;
}
}
if ( V_45 -> V_148 ) {
V_14 = V_45 -> V_148 ( V_45 ) ;
if ( V_14 < 0 ) {
F_62 ( V_45 -> V_25 ,
L_30 , V_14 ) ;
goto V_147;
}
F_81 ( V_91 -> V_99 &&
V_91 -> V_93 != V_100 ,
L_31 ,
V_45 -> V_47 ) ;
}
if ( V_45 -> V_149 )
F_82 ( V_45 , V_45 -> V_149 ,
V_45 -> V_150 ) ;
if ( V_45 -> V_151 )
F_83 ( V_91 , V_45 -> V_151 ,
V_45 -> V_152 ) ;
V_45 -> V_126 = 1 ;
F_84 ( & V_91 -> V_153 , & V_49 -> V_154 ) ;
if ( V_45 -> V_5 )
F_84 ( & V_45 -> V_5 -> V_127 , & V_49 -> V_155 ) ;
return 0 ;
V_147:
F_28 ( V_45 ) ;
F_69 ( V_45 -> V_25 -> V_10 -> V_128 ) ;
return V_14 ;
}
static void F_85 ( struct V_24 * V_25 )
{
F_15 ( V_25 ) ;
}
static int F_86 ( struct V_28 * V_29 ,
const char * V_47 )
{
int V_14 = 0 ;
V_29 -> V_25 = F_87 ( sizeof( struct V_24 ) , V_36 ) ;
if ( ! V_29 -> V_25 )
return - V_37 ;
F_88 ( V_29 -> V_25 ) ;
V_29 -> V_25 -> V_156 = V_29 -> V_49 -> V_25 ;
V_29 -> V_25 -> V_157 = F_85 ;
F_89 ( V_29 -> V_25 , L_32 , V_47 ) ;
F_90 ( V_29 -> V_25 , V_29 ) ;
F_91 ( & V_29 -> V_158 ) ;
F_92 ( & V_29 -> V_159 [ V_94 ] . V_160 ) ;
F_92 ( & V_29 -> V_159 [ V_96 ] . V_160 ) ;
F_92 ( & V_29 -> V_159 [ V_94 ] . V_161 ) ;
F_92 ( & V_29 -> V_159 [ V_96 ] . V_161 ) ;
V_14 = F_93 ( V_29 -> V_25 ) ;
if ( V_14 < 0 ) {
F_94 ( V_29 -> V_25 ) ;
F_62 ( V_29 -> V_49 -> V_25 ,
L_33 , V_14 ) ;
return V_14 ;
}
V_29 -> V_132 = 1 ;
if ( V_29 -> V_5 ) {
V_14 = F_95 ( V_29 -> V_25 ) ;
if ( V_14 < 0 )
F_62 ( V_29 -> V_25 ,
L_34 ,
V_14 ) ;
V_14 = F_96 ( V_29 -> V_25 , & V_134 ) ;
if ( V_14 < 0 )
F_62 ( V_29 -> V_25 ,
L_35 ,
V_14 ) ;
}
return 0 ;
}
static int F_97 ( struct V_58 * V_49 , int V_116 ,
int V_129 )
{
struct V_28 * V_29 = & V_49 -> V_29 [ V_116 ] ;
struct V_56 * V_57 = V_29 -> V_57 ;
struct V_44 * V_45 ;
int V_3 , V_14 ;
V_45 = V_29 -> V_87 -> V_45 ;
if ( V_45 -> V_10 -> V_162 == V_129 ) {
V_14 = F_77 ( V_49 , V_45 ) ;
if ( V_14 < 0 )
return V_14 ;
}
for ( V_3 = 0 ; V_3 < V_29 -> V_79 ; V_3 ++ ) {
V_45 = V_29 -> V_80 [ V_3 ] -> V_45 ;
if ( V_45 -> V_10 -> V_162 == V_129 ) {
V_14 = F_77 ( V_49 , V_45 ) ;
if ( V_14 < 0 )
return V_14 ;
}
}
if ( V_57 -> V_45 . V_10 -> V_162 == V_129 ) {
V_14 = F_77 ( V_49 , & V_57 -> V_45 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
static int F_98 ( struct V_54 * V_55 , int V_129 )
{
int V_14 ;
if ( ! V_55 -> V_126 && V_55 -> V_10 -> V_162 == V_129 ) {
if ( V_55 -> V_10 -> V_148 ) {
V_14 = V_55 -> V_10 -> V_148 ( V_55 ) ;
if ( V_14 < 0 ) {
F_62 ( V_55 -> V_25 ,
L_36 ,
V_55 -> V_47 , V_14 ) ;
return V_14 ;
}
}
V_55 -> V_126 = 1 ;
}
return 0 ;
}
static int F_99 ( struct V_58 * V_49 ,
struct V_117 * V_63 ,
struct V_28 * V_29 )
{
struct V_54 * V_87 = V_29 -> V_87 ;
struct V_54 * V_110 = V_29 -> V_110 ;
struct V_163 * V_164 , * V_165 ;
int V_14 ;
if ( V_29 -> V_79 > 1 )
F_25 ( V_49 -> V_25 , L_37 ) ;
V_164 = V_110 -> V_166 ;
V_165 = V_87 -> V_167 ;
if ( V_164 && V_165 ) {
V_14 = F_100 ( V_49 , V_63 -> V_168 ,
V_165 , V_164 ) ;
if ( V_14 != 0 ) {
F_62 ( V_49 -> V_25 , L_38 ,
V_164 -> V_47 , V_165 -> V_47 , V_14 ) ;
return V_14 ;
}
}
V_164 = V_87 -> V_166 ;
V_165 = V_110 -> V_167 ;
if ( V_164 && V_165 ) {
V_14 = F_100 ( V_49 , V_63 -> V_168 ,
V_165 , V_164 ) ;
if ( V_14 != 0 ) {
F_62 ( V_49 -> V_25 , L_38 ,
V_164 -> V_47 , V_165 -> V_47 , V_14 ) ;
return V_14 ;
}
}
return 0 ;
}
static int F_101 ( struct V_58 * V_49 , int V_116 , int V_129 )
{
struct V_117 * V_63 = & V_49 -> V_63 [ V_116 ] ;
struct V_28 * V_29 = & V_49 -> V_29 [ V_116 ] ;
struct V_54 * V_87 = V_29 -> V_87 ;
int V_3 , V_14 ;
F_42 ( V_49 -> V_25 , L_39 ,
V_49 -> V_47 , V_116 , V_129 ) ;
V_29 -> V_31 = V_31 ;
V_14 = F_98 ( V_87 , V_129 ) ;
if ( V_14 )
return V_14 ;
for ( V_3 = 0 ; V_3 < V_29 -> V_79 ; V_3 ++ ) {
V_14 = F_98 ( V_29 -> V_80 [ V_3 ] , V_129 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_129 != V_136 )
return 0 ;
if ( V_63 -> V_169 ) {
V_14 = V_63 -> V_169 ( V_29 ) ;
if ( V_14 < 0 ) {
F_62 ( V_49 -> V_25 , L_40 ,
V_63 -> V_47 , V_14 ) ;
return V_14 ;
}
}
V_14 = F_86 ( V_29 , V_63 -> V_47 ) ;
if ( V_14 )
return V_14 ;
#ifdef F_102
if ( V_63 -> V_170 ) {
V_14 = F_103 ( V_29 ) ;
if ( V_14 < 0 ) {
F_62 ( V_29 -> V_25 ,
L_41 ,
V_14 ) ;
return V_14 ;
}
}
#endif
V_14 = F_96 ( V_29 -> V_25 , & V_133 ) ;
if ( V_14 < 0 )
F_25 ( V_29 -> V_25 , L_42 ,
V_14 ) ;
if ( V_87 -> V_10 -> V_171 ) {
V_14 = F_104 ( V_29 , V_116 ) ;
if ( V_14 < 0 ) {
F_62 ( V_49 -> V_25 , L_43 ,
V_63 -> V_172 ) ;
return V_14 ;
}
} else {
if ( ! V_63 -> V_168 ) {
V_14 = F_105 ( V_29 , V_116 ) ;
if ( V_14 < 0 ) {
F_62 ( V_49 -> V_25 , L_44 ,
V_63 -> V_172 , V_14 ) ;
return V_14 ;
}
} else {
F_106 ( & V_29 -> V_90 ,
F_44 ) ;
V_14 = F_99 ( V_49 , V_63 , V_29 ) ;
if ( V_14 )
return V_14 ;
}
}
return 0 ;
}
static int F_107 ( struct V_58 * V_49 , int V_116 )
{
struct V_28 * V_29 = & V_49 -> V_173 [ V_116 ] ;
struct V_174 * V_175 = & V_49 -> V_175 [ V_116 ] ;
const char * V_47 = V_175 -> V_176 ;
V_29 -> V_45 = F_63 ( V_175 -> V_177 , V_47 ) ;
if ( ! V_29 -> V_45 ) {
if ( V_175 -> V_177 )
V_47 = F_108 ( V_175 -> V_177 ) ;
F_62 ( V_49 -> V_25 , L_45 , V_47 ) ;
return - V_124 ;
}
V_29 -> V_5 = V_29 -> V_45 -> V_5 ;
return 0 ;
}
static int F_109 ( struct V_58 * V_49 , int V_116 )
{
struct V_28 * V_29 = & V_49 -> V_173 [ V_116 ] ;
struct V_174 * V_175 = & V_49 -> V_175 [ V_116 ] ;
int V_14 ;
V_14 = F_77 ( V_49 , V_29 -> V_45 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_175 -> V_169 ) {
V_14 = V_175 -> V_169 ( V_29 -> V_45 ) ;
if ( V_14 < 0 ) {
F_62 ( V_49 -> V_25 , L_40 ,
V_175 -> V_47 , V_14 ) ;
return V_14 ;
}
}
return F_86 ( V_29 , V_175 -> V_47 ) ;
}
static void F_110 ( struct V_58 * V_49 , int V_116 )
{
struct V_28 * V_29 = & V_49 -> V_173 [ V_116 ] ;
struct V_44 * V_45 = V_29 -> V_45 ;
if ( V_29 -> V_132 ) {
F_72 ( V_29 -> V_25 , & V_134 ) ;
F_73 ( V_29 -> V_25 ) ;
V_29 -> V_132 = 0 ;
}
if ( V_45 && V_45 -> V_126 )
F_66 ( V_45 ) ;
}
static int F_111 ( struct V_4 * V_5 )
{
int V_14 ;
if ( V_5 -> V_178 )
return 0 ;
V_14 = F_112 ( V_5 ) ;
if ( V_14 < 0 ) {
F_62 ( V_5 -> V_25 ,
L_46 ,
V_14 ) ;
return V_14 ;
}
V_5 -> V_178 = 1 ;
return 0 ;
}
static int F_113 ( struct V_58 * V_49 )
{
struct V_4 * V_5 ;
struct V_117 * V_63 ;
int V_14 , V_3 , V_129 , V_179 ;
F_114 ( & V_49 -> V_180 , V_181 ) ;
for ( V_3 = 0 ; V_3 < V_49 -> V_65 ; V_3 ++ ) {
V_14 = F_65 ( V_49 , V_3 ) ;
if ( V_14 != 0 )
goto V_182;
}
for ( V_3 = 0 ; V_3 < V_49 -> V_183 ; V_3 ++ ) {
V_14 = F_107 ( V_49 , V_3 ) ;
if ( V_14 != 0 )
goto V_182;
}
F_34 (codec, &codec_list, list) {
if ( V_5 -> V_178 )
continue;
V_14 = F_111 ( V_5 ) ;
if ( V_14 < 0 )
goto V_182;
}
V_14 = F_115 ( V_49 -> V_25 , V_184 , V_185 ,
V_49 -> V_128 , 0 , & V_49 -> V_74 ) ;
if ( V_14 < 0 ) {
F_62 ( V_49 -> V_25 ,
L_47 ,
V_49 -> V_47 , V_14 ) ;
goto V_182;
}
V_49 -> V_91 . V_93 = V_100 ;
V_49 -> V_91 . V_25 = V_49 -> V_25 ;
V_49 -> V_91 . V_49 = V_49 ;
F_84 ( & V_49 -> V_91 . V_153 , & V_49 -> V_154 ) ;
#ifdef F_102
F_26 ( & V_49 -> V_91 , V_49 -> V_50 ) ;
#endif
#ifdef F_116
F_117 ( & V_49 -> V_103 , F_57 ) ;
#endif
if ( V_49 -> V_145 )
F_79 ( & V_49 -> V_91 , V_49 -> V_145 ,
V_49 -> V_146 ) ;
if ( V_49 -> V_148 ) {
V_14 = V_49 -> V_148 ( V_49 ) ;
if ( V_14 < 0 )
goto V_186;
}
for ( V_129 = V_135 ; V_129 <= V_136 ;
V_129 ++ ) {
for ( V_3 = 0 ; V_3 < V_49 -> V_65 ; V_3 ++ ) {
V_14 = F_97 ( V_49 , V_3 , V_129 ) ;
if ( V_14 < 0 ) {
F_62 ( V_49 -> V_25 ,
L_48 ,
V_14 ) ;
goto V_187;
}
}
}
for ( V_129 = V_135 ; V_129 <= V_136 ;
V_129 ++ ) {
for ( V_3 = 0 ; V_3 < V_49 -> V_65 ; V_3 ++ ) {
V_14 = F_101 ( V_49 , V_3 , V_129 ) ;
if ( V_14 < 0 ) {
F_62 ( V_49 -> V_25 ,
L_48 ,
V_14 ) ;
goto V_187;
}
}
}
for ( V_3 = 0 ; V_3 < V_49 -> V_183 ; V_3 ++ ) {
V_14 = F_109 ( V_49 , V_3 ) ;
if ( V_14 < 0 ) {
F_62 ( V_49 -> V_25 ,
L_49 ,
V_14 ) ;
goto V_188;
}
}
F_118 ( V_49 ) ;
F_119 ( V_49 ) ;
if ( V_49 -> V_149 )
F_120 ( V_49 , V_49 -> V_149 , V_49 -> V_150 ) ;
if ( V_49 -> V_151 )
F_83 ( & V_49 -> V_91 , V_49 -> V_151 ,
V_49 -> V_152 ) ;
for ( V_3 = 0 ; V_3 < V_49 -> V_65 ; V_3 ++ ) {
struct V_28 * V_29 = & V_49 -> V_29 [ V_3 ] ;
V_63 = & V_49 -> V_63 [ V_3 ] ;
V_179 = V_63 -> V_179 ;
if ( V_179 ) {
struct V_54 * * V_80 = V_29 -> V_80 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_29 -> V_79 ; V_72 ++ ) {
struct V_54 * V_110 = V_80 [ V_72 ] ;
V_14 = F_121 ( V_110 , V_179 ) ;
if ( V_14 != 0 && V_14 != - V_189 )
F_25 ( V_110 -> V_25 ,
L_50 ,
V_14 ) ;
}
}
if ( V_179 &&
( V_63 -> V_120 || V_63 -> V_125 ) ) {
V_14 = F_121 ( V_49 -> V_29 [ V_3 ] . V_87 ,
V_179 ) ;
if ( V_14 != 0 && V_14 != - V_189 )
F_25 ( V_49 -> V_29 [ V_3 ] . V_87 -> V_25 ,
L_50 ,
V_14 ) ;
} else if ( V_179 ) {
V_179 &= ~ V_190 ;
switch ( V_63 -> V_179 &
V_190 ) {
case V_191 :
V_179 |= V_192 ;
break;
case V_193 :
V_179 |= V_194 ;
break;
case V_194 :
V_179 |= V_193 ;
break;
case V_192 :
V_179 |= V_191 ;
break;
}
V_14 = F_121 ( V_49 -> V_29 [ V_3 ] . V_87 ,
V_179 ) ;
if ( V_14 != 0 && V_14 != - V_189 )
F_25 ( V_49 -> V_29 [ V_3 ] . V_87 -> V_25 ,
L_50 ,
V_14 ) ;
}
}
snprintf ( V_49 -> V_74 -> V_195 , sizeof( V_49 -> V_74 -> V_195 ) ,
L_32 , V_49 -> V_47 ) ;
snprintf ( V_49 -> V_74 -> V_196 , sizeof( V_49 -> V_74 -> V_196 ) ,
L_32 , V_49 -> V_197 ? V_49 -> V_197 : V_49 -> V_47 ) ;
snprintf ( V_49 -> V_74 -> V_10 , sizeof( V_49 -> V_74 -> V_10 ) ,
L_32 , V_49 -> V_198 ? V_49 -> V_198 : V_49 -> V_47 ) ;
for ( V_3 = 0 ; V_3 < F_122 ( V_49 -> V_74 -> V_10 ) ; V_3 ++ ) {
switch ( V_49 -> V_74 -> V_10 [ V_3 ] ) {
case '_' :
case '-' :
case '\0' :
break;
default:
if ( ! isalnum ( V_49 -> V_74 -> V_10 [ V_3 ] ) )
V_49 -> V_74 -> V_10 [ V_3 ] = '_' ;
break;
}
}
if ( V_49 -> V_199 ) {
V_14 = V_49 -> V_199 ( V_49 ) ;
if ( V_14 < 0 ) {
F_62 ( V_49 -> V_25 , L_51 ,
V_49 -> V_47 , V_14 ) ;
goto V_188;
}
}
if ( V_49 -> V_200 )
F_123 ( V_49 ) ;
F_124 ( V_49 ) ;
V_14 = F_125 ( V_49 -> V_74 ) ;
if ( V_14 < 0 ) {
F_62 ( V_49 -> V_25 , L_52 ,
V_14 ) ;
goto V_188;
}
V_49 -> V_73 = 1 ;
F_54 ( & V_49 -> V_91 ) ;
F_126 ( & V_49 -> V_180 ) ;
return 0 ;
V_188:
for ( V_3 = 0 ; V_3 < V_49 -> V_183 ; V_3 ++ )
F_110 ( V_49 , V_3 ) ;
V_187:
F_75 ( V_49 ) ;
V_186:
if ( V_49 -> remove )
V_49 -> remove ( V_49 ) ;
F_127 ( V_49 -> V_74 ) ;
V_182:
F_126 ( & V_49 -> V_180 ) ;
return V_14 ;
}
static int F_128 ( struct V_201 * V_202 )
{
struct V_58 * V_49 = F_129 ( V_202 ) ;
if ( ! V_49 )
return - V_17 ;
F_25 ( & V_202 -> V_25 ,
L_53 ,
V_49 -> V_47 ) ;
V_49 -> V_25 = & V_202 -> V_25 ;
return F_130 ( V_49 ) ;
}
static int F_131 ( struct V_58 * V_49 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_49 -> V_77 ; V_3 ++ ) {
struct V_28 * V_29 = & V_49 -> V_29 [ V_3 ] ;
F_51 ( & V_29 -> V_90 ) ;
}
for ( V_3 = 0 ; V_3 < V_49 -> V_183 ; V_3 ++ )
F_110 ( V_49 , V_3 ) ;
F_75 ( V_49 ) ;
F_40 ( V_49 ) ;
if ( V_49 -> remove )
V_49 -> remove ( V_49 ) ;
F_68 ( & V_49 -> V_91 ) ;
F_127 ( V_49 -> V_74 ) ;
return 0 ;
}
static int F_132 ( struct V_201 * V_202 )
{
struct V_58 * V_49 = F_129 ( V_202 ) ;
F_133 ( V_49 ) ;
return 0 ;
}
int F_134 ( struct V_24 * V_25 )
{
struct V_58 * V_49 = F_8 ( V_25 ) ;
int V_3 ;
if ( ! V_49 -> V_73 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_49 -> V_77 ; V_3 ++ ) {
struct V_28 * V_29 = & V_49 -> V_29 [ V_3 ] ;
F_51 ( & V_29 -> V_90 ) ;
}
F_135 ( V_49 ) ;
for ( V_3 = 0 ; V_3 < V_49 -> V_77 ; V_3 ++ ) {
struct V_28 * V_29 = & V_49 -> V_29 [ V_3 ] ;
struct V_54 * V_87 = V_29 -> V_87 ;
int V_72 ;
F_56 ( V_87 -> V_25 ) ;
for ( V_72 = 0 ; V_72 < V_29 -> V_79 ; V_72 ++ ) {
struct V_54 * V_110 = V_29 -> V_80 [ V_72 ] ;
F_56 ( V_110 -> V_25 ) ;
}
}
return 0 ;
}
struct V_203 * F_136 ( const struct V_204 * V_205 ,
void * V_206 , const char * V_197 ,
const char * V_207 )
{
struct V_204 V_208 ;
struct V_203 * V_209 ;
char * V_47 = NULL ;
memcpy ( & V_208 , V_205 , sizeof( V_208 ) ) ;
V_208 . V_210 = 0 ;
if ( ! V_197 )
V_197 = V_208 . V_47 ;
if ( V_207 ) {
V_47 = F_23 ( V_36 , L_54 , V_207 , V_197 ) ;
if ( ! V_47 )
return NULL ;
V_208 . V_47 = V_47 ;
} else {
V_208 . V_47 = V_197 ;
}
V_209 = F_137 ( & V_208 , V_206 ) ;
F_15 ( V_47 ) ;
return V_209 ;
}
static int F_138 ( struct V_74 * V_49 , struct V_24 * V_25 ,
const struct V_204 * V_149 , int V_150 ,
const char * V_207 , void * V_206 )
{
int V_130 , V_3 ;
for ( V_3 = 0 ; V_3 < V_150 ; V_3 ++ ) {
const struct V_204 * V_211 = & V_149 [ V_3 ] ;
V_130 = F_139 ( V_49 , F_136 ( V_211 , V_206 ,
V_211 -> V_47 , V_207 ) ) ;
if ( V_130 < 0 ) {
F_62 ( V_25 , L_55 ,
V_211 -> V_47 , V_130 ) ;
return V_130 ;
}
}
return 0 ;
}
struct V_203 * F_140 ( struct V_58 * V_212 ,
const char * V_47 )
{
struct V_74 * V_49 = V_212 -> V_74 ;
struct V_203 * V_213 ;
if ( F_141 ( ! V_47 ) )
return NULL ;
F_34 (kctl, &card->controls, list)
if ( ! strncmp ( V_213 -> V_214 . V_47 , V_47 , sizeof( V_213 -> V_214 . V_47 ) ) )
return V_213 ;
return NULL ;
}
int F_82 ( struct V_44 * V_45 ,
const struct V_204 * V_149 , unsigned int V_150 )
{
struct V_74 * V_49 = V_45 -> V_49 -> V_74 ;
return F_138 ( V_49 , V_45 -> V_25 , V_149 ,
V_150 , V_45 -> V_142 , V_45 ) ;
}
int F_142 ( struct V_4 * V_5 ,
const struct V_204 * V_149 , unsigned int V_150 )
{
return F_82 ( & V_5 -> V_45 , V_149 ,
V_150 ) ;
}
int F_143 ( struct V_56 * V_57 ,
const struct V_204 * V_149 , unsigned int V_150 )
{
return F_82 ( & V_57 -> V_45 , V_149 ,
V_150 ) ;
}
int F_120 ( struct V_58 * V_212 ,
const struct V_204 * V_149 , int V_150 )
{
struct V_74 * V_49 = V_212 -> V_74 ;
return F_138 ( V_49 , V_212 -> V_25 , V_149 , V_150 ,
NULL , V_212 ) ;
}
int F_144 ( struct V_54 * V_55 ,
const struct V_204 * V_149 , int V_150 )
{
struct V_74 * V_49 = V_55 -> V_45 -> V_49 -> V_74 ;
return F_138 ( V_49 , V_55 -> V_25 , V_149 , V_150 ,
NULL , V_55 ) ;
}
int F_145 ( struct V_54 * V_55 , int V_215 ,
unsigned int V_216 , int V_217 )
{
if ( V_55 -> V_10 && V_55 -> V_10 -> V_83 -> V_218 )
return V_55 -> V_10 -> V_83 -> V_218 ( V_55 , V_215 , V_216 , V_217 ) ;
else if ( V_55 -> V_5 && V_55 -> V_5 -> V_10 -> V_218 )
return V_55 -> V_5 -> V_10 -> V_218 ( V_55 -> V_5 , V_215 , 0 ,
V_216 , V_217 ) ;
else
return - V_189 ;
}
int F_146 ( struct V_4 * V_5 , int V_215 ,
int V_219 , unsigned int V_216 , int V_217 )
{
if ( V_5 -> V_10 -> V_218 )
return V_5 -> V_10 -> V_218 ( V_5 , V_215 , V_219 ,
V_216 , V_217 ) ;
else
return - V_189 ;
}
int F_147 ( struct V_54 * V_55 ,
int V_220 , int div )
{
if ( V_55 -> V_10 && V_55 -> V_10 -> V_83 -> V_221 )
return V_55 -> V_10 -> V_83 -> V_221 ( V_55 , V_220 , div ) ;
else
return - V_17 ;
}
int F_148 ( struct V_54 * V_55 , int V_222 , int V_219 ,
unsigned int V_223 , unsigned int V_224 )
{
if ( V_55 -> V_10 && V_55 -> V_10 -> V_83 -> V_225 )
return V_55 -> V_10 -> V_83 -> V_225 ( V_55 , V_222 , V_219 ,
V_223 , V_224 ) ;
else if ( V_55 -> V_5 && V_55 -> V_5 -> V_10 -> V_225 )
return V_55 -> V_5 -> V_10 -> V_225 ( V_55 -> V_5 , V_222 , V_219 ,
V_223 , V_224 ) ;
else
return - V_17 ;
}
int F_149 ( struct V_4 * V_5 , int V_222 , int V_219 ,
unsigned int V_223 , unsigned int V_224 )
{
if ( V_5 -> V_10 -> V_225 )
return V_5 -> V_10 -> V_225 ( V_5 , V_222 , V_219 ,
V_223 , V_224 ) ;
else
return - V_17 ;
}
int F_150 ( struct V_54 * V_55 , unsigned int V_226 )
{
if ( V_55 -> V_10 && V_55 -> V_10 -> V_83 -> V_227 )
return V_55 -> V_10 -> V_83 -> V_227 ( V_55 , V_226 ) ;
else
return - V_17 ;
}
int F_121 ( struct V_54 * V_55 , unsigned int V_228 )
{
if ( V_55 -> V_10 == NULL )
return - V_17 ;
if ( V_55 -> V_10 -> V_83 -> V_229 == NULL )
return - V_189 ;
return V_55 -> V_10 -> V_83 -> V_229 ( V_55 , V_228 ) ;
}
static int F_151 ( unsigned int V_230 ,
unsigned int * V_231 ,
unsigned int * V_232 )
{
if ( * V_231 || * V_232 )
return 0 ;
if ( ! V_230 )
return - V_17 ;
* V_231 = ( 1 << V_230 ) - 1 ;
* V_232 = ( 1 << V_230 ) - 1 ;
return 0 ;
}
int F_152 ( struct V_54 * V_55 ,
unsigned int V_231 , unsigned int V_232 , int V_230 , int V_233 )
{
if ( V_55 -> V_10 && V_55 -> V_10 -> V_83 -> V_234 )
V_55 -> V_10 -> V_83 -> V_234 ( V_230 ,
& V_231 , & V_232 ) ;
else
F_151 ( V_230 , & V_231 , & V_232 ) ;
V_55 -> V_231 = V_231 ;
V_55 -> V_232 = V_232 ;
if ( V_55 -> V_10 && V_55 -> V_10 -> V_83 -> V_235 )
return V_55 -> V_10 -> V_83 -> V_235 ( V_55 , V_231 , V_232 ,
V_230 , V_233 ) ;
else
return - V_189 ;
}
int F_153 ( struct V_54 * V_55 ,
unsigned int V_236 , unsigned int * V_237 ,
unsigned int V_238 , unsigned int * V_239 )
{
if ( V_55 -> V_10 && V_55 -> V_10 -> V_83 -> V_240 )
return V_55 -> V_10 -> V_83 -> V_240 ( V_55 , V_236 , V_237 ,
V_238 , V_239 ) ;
else
return - V_17 ;
}
int F_154 ( struct V_54 * V_55 , int V_241 )
{
if ( V_55 -> V_10 && V_55 -> V_10 -> V_83 -> V_242 )
return V_55 -> V_10 -> V_83 -> V_242 ( V_55 , V_241 ) ;
else
return - V_17 ;
}
int F_155 ( struct V_54 * V_55 , int V_243 ,
int V_244 )
{
if ( ! V_55 -> V_10 )
return - V_189 ;
if ( V_55 -> V_10 -> V_83 -> V_245 )
return V_55 -> V_10 -> V_83 -> V_245 ( V_55 , V_243 , V_244 ) ;
else if ( V_244 == V_94 &&
V_55 -> V_10 -> V_83 -> V_84 )
return V_55 -> V_10 -> V_83 -> V_84 ( V_55 , V_243 ) ;
else
return - V_189 ;
}
static int F_156 ( struct V_58 * V_49 ,
struct V_117 * V_63 )
{
if ( V_63 -> V_176 || V_63 -> V_177 ||
V_63 -> V_246 ) {
V_63 -> V_79 = 1 ;
V_63 -> V_118 = F_157 ( V_49 -> V_25 ,
sizeof( struct V_113 ) ,
V_36 ) ;
if ( ! V_63 -> V_118 )
return - V_37 ;
V_63 -> V_118 [ 0 ] . V_47 = V_63 -> V_176 ;
V_63 -> V_118 [ 0 ] . V_112 = V_63 -> V_177 ;
V_63 -> V_118 [ 0 ] . V_115 = V_63 -> V_246 ;
}
if ( ! V_63 -> V_118 ) {
F_62 ( V_49 -> V_25 , L_56 ) ;
return - V_17 ;
}
return 0 ;
}
int F_130 ( struct V_58 * V_49 )
{
int V_3 , V_72 , V_14 ;
if ( ! V_49 -> V_47 || ! V_49 -> V_25 )
return - V_17 ;
for ( V_3 = 0 ; V_3 < V_49 -> V_65 ; V_3 ++ ) {
struct V_117 * V_247 = & V_49 -> V_63 [ V_3 ] ;
V_14 = F_156 ( V_49 , V_247 ) ;
if ( V_14 ) {
F_62 ( V_49 -> V_25 , L_57 ) ;
return V_14 ;
}
for ( V_72 = 0 ; V_72 < V_247 -> V_79 ; V_72 ++ ) {
if ( ! ! V_247 -> V_118 [ V_72 ] . V_47 ==
! ! V_247 -> V_118 [ V_72 ] . V_112 ) {
F_62 ( V_49 -> V_25 , L_58 ,
V_247 -> V_47 ) ;
return - V_17 ;
}
if ( ! V_247 -> V_118 [ V_72 ] . V_115 ) {
F_62 ( V_49 -> V_25 , L_59 ,
V_247 -> V_47 ) ;
return - V_17 ;
}
}
if ( V_247 -> V_120 && V_247 -> V_125 ) {
F_62 ( V_49 -> V_25 ,
L_60 ,
V_247 -> V_47 ) ;
return - V_17 ;
}
if ( V_247 -> V_121 && V_247 -> V_122 ) {
F_62 ( V_49 -> V_25 ,
L_61 ,
V_247 -> V_47 ) ;
return - V_17 ;
}
if ( ! V_247 -> V_123 &&
! ( V_247 -> V_121 || V_247 -> V_122 ) ) {
F_62 ( V_49 -> V_25 ,
L_62 ,
V_247 -> V_47 ) ;
return - V_17 ;
}
}
F_90 ( V_49 -> V_25 , V_49 ) ;
F_158 ( V_49 ) ;
F_38 ( V_49 ) ;
V_49 -> V_29 = F_157 ( V_49 -> V_25 ,
sizeof( struct V_28 ) *
( V_49 -> V_65 + V_49 -> V_183 ) ,
V_36 ) ;
if ( V_49 -> V_29 == NULL )
return - V_37 ;
V_49 -> V_77 = 0 ;
V_49 -> V_173 = & V_49 -> V_29 [ V_49 -> V_65 ] ;
for ( V_3 = 0 ; V_3 < V_49 -> V_65 ; V_3 ++ ) {
V_49 -> V_29 [ V_3 ] . V_49 = V_49 ;
V_49 -> V_29 [ V_3 ] . V_63 = & V_49 -> V_63 [ V_3 ] ;
V_49 -> V_29 [ V_3 ] . V_80 = F_157 ( V_49 -> V_25 ,
sizeof( struct V_54 * ) *
( V_49 -> V_29 [ V_3 ] . V_63 -> V_79 ) ,
V_36 ) ;
if ( V_49 -> V_29 [ V_3 ] . V_80 == NULL )
return - V_37 ;
}
for ( V_3 = 0 ; V_3 < V_49 -> V_183 ; V_3 ++ )
V_49 -> V_173 [ V_3 ] . V_49 = V_49 ;
F_92 ( & V_49 -> V_248 ) ;
V_49 -> V_73 = 0 ;
F_91 ( & V_49 -> V_180 ) ;
F_91 ( & V_49 -> V_249 ) ;
V_14 = F_113 ( V_49 ) ;
if ( V_14 != 0 )
F_40 ( V_49 ) ;
for ( V_3 = 0 ; V_3 < V_49 -> V_77 ; V_3 ++ ) {
struct V_28 * V_29 = & V_49 -> V_29 [ V_3 ] ;
struct V_54 * V_87 = V_29 -> V_87 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_29 -> V_79 ; V_72 ++ ) {
struct V_54 * V_110 = V_29 -> V_80 [ V_72 ] ;
if ( ! V_110 -> V_109 )
F_56 ( V_110 -> V_25 ) ;
}
if ( ! V_87 -> V_109 )
F_56 ( V_87 -> V_25 ) ;
}
return V_14 ;
}
int F_133 ( struct V_58 * V_49 )
{
if ( V_49 -> V_73 ) {
V_49 -> V_73 = false ;
F_135 ( V_49 ) ;
F_131 ( V_49 ) ;
}
F_42 ( V_49 -> V_25 , L_63 , V_49 -> V_47 ) ;
return 0 ;
}
static char * F_159 ( struct V_24 * V_25 , int * V_214 )
{
char * V_250 , V_47 [ V_251 ] ;
int V_252 , V_253 ;
if ( V_141 ( V_25 ) == NULL )
return NULL ;
F_160 ( V_47 , V_141 ( V_25 ) , V_251 ) ;
V_250 = strstr ( V_47 , V_25 -> V_10 -> V_47 ) ;
if ( V_250 ) {
if ( sscanf ( & V_250 [ strlen ( V_25 -> V_10 -> V_47 ) ] , L_64 , V_214 ) == 1 ) {
if ( * V_214 == - 1 )
V_250 [ strlen ( V_25 -> V_10 -> V_47 ) ] = '\0' ;
}
} else {
if ( sscanf ( V_47 , L_65 , & V_252 , & V_253 ) == 2 ) {
char V_254 [ V_251 ] ;
* V_214 = ( ( V_252 & 0xffff ) << 16 ) + V_253 ;
snprintf ( V_254 , V_251 , L_66 , V_25 -> V_10 -> V_47 , V_47 ) ;
F_160 ( V_47 , V_254 , V_251 ) ;
} else
* V_214 = 0 ;
}
return F_161 ( V_47 , V_36 ) ;
}
static inline char * F_162 ( struct V_24 * V_25 ,
struct V_81 * V_255 )
{
if ( V_255 -> V_47 == NULL ) {
F_62 ( V_25 ,
L_67 ,
V_141 ( V_25 ) ) ;
return NULL ;
}
return F_161 ( V_255 -> V_47 , V_36 ) ;
}
static void F_163 ( struct V_44 * V_45 )
{
struct V_54 * V_55 , * V_256 ;
F_164 (dai, _dai, &component->dai_list, list) {
F_42 ( V_45 -> V_25 , L_68 ,
V_55 -> V_47 ) ;
F_67 ( & V_55 -> V_153 ) ;
F_15 ( V_55 -> V_47 ) ;
F_15 ( V_55 ) ;
}
}
static int F_165 ( struct V_44 * V_45 ,
struct V_81 * V_255 , T_1 V_18 ,
bool V_257 )
{
struct V_24 * V_25 = V_45 -> V_25 ;
struct V_54 * V_55 ;
unsigned int V_3 ;
int V_14 ;
F_42 ( V_25 , L_69 , V_141 ( V_25 ) , V_18 ) ;
V_45 -> V_255 = V_255 ;
V_45 -> V_258 = V_18 ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ ) {
V_55 = F_87 ( sizeof( struct V_54 ) , V_36 ) ;
if ( V_55 == NULL ) {
V_14 = - V_37 ;
goto V_130;
}
if ( V_18 == 1 && V_257 ) {
V_55 -> V_47 = F_159 ( V_25 , & V_55 -> V_214 ) ;
} else {
V_55 -> V_47 = F_162 ( V_25 , & V_255 [ V_3 ] ) ;
if ( V_255 [ V_3 ] . V_214 )
V_55 -> V_214 = V_255 [ V_3 ] . V_214 ;
else
V_55 -> V_214 = V_3 ;
}
if ( V_55 -> V_47 == NULL ) {
F_15 ( V_55 ) ;
V_14 = - V_37 ;
goto V_130;
}
V_55 -> V_45 = V_45 ;
V_55 -> V_25 = V_25 ;
V_55 -> V_10 = & V_255 [ V_3 ] ;
if ( ! V_55 -> V_10 -> V_83 )
V_55 -> V_10 -> V_83 = & V_259 ;
F_84 ( & V_55 -> V_153 , & V_45 -> V_260 ) ;
F_42 ( V_25 , L_70 , V_55 -> V_47 ) ;
}
return 0 ;
V_130:
F_163 ( V_45 ) ;
return V_14 ;
}
static void F_166 ( struct V_143 * V_91 ,
enum V_261 type , int V_262 )
{
struct V_44 * V_45 = V_91 -> V_45 ;
V_45 -> V_10 -> V_263 ( V_45 , type , V_262 ) ;
}
static int F_167 ( struct V_143 * V_91 ,
int V_264 )
{
struct V_44 * V_45 = V_91 -> V_45 ;
return V_45 -> V_10 -> V_265 ( V_45 , V_264 ) ;
}
static int F_168 ( struct V_44 * V_45 ,
const struct V_266 * V_10 , struct V_24 * V_25 )
{
struct V_143 * V_91 ;
V_45 -> V_47 = F_159 ( V_25 , & V_45 -> V_214 ) ;
if ( ! V_45 -> V_47 ) {
F_62 ( V_25 , L_71 ) ;
return - V_37 ;
}
V_45 -> V_25 = V_25 ;
V_45 -> V_10 = V_10 ;
V_45 -> V_148 = V_45 -> V_10 -> V_148 ;
V_45 -> remove = V_45 -> V_10 -> remove ;
if ( ! V_45 -> V_267 )
V_45 -> V_267 = & V_45 -> V_91 ;
V_91 = V_45 -> V_267 ;
V_91 -> V_25 = V_25 ;
V_91 -> V_45 = V_45 ;
V_91 -> V_93 = V_100 ;
V_91 -> V_99 = true ;
if ( V_10 -> V_263 )
V_91 -> V_263 = F_166 ;
if ( V_10 -> V_265 )
V_91 -> V_265 = F_167 ;
V_45 -> V_149 = V_10 -> V_149 ;
V_45 -> V_150 = V_10 -> V_150 ;
V_45 -> V_145 = V_10 -> V_145 ;
V_45 -> V_146 = V_10 -> V_146 ;
V_45 -> V_151 = V_10 -> V_151 ;
V_45 -> V_152 = V_10 -> V_152 ;
F_92 ( & V_45 -> V_260 ) ;
F_91 ( & V_45 -> V_268 ) ;
return 0 ;
}
static void F_169 ( struct V_44 * V_45 )
{
int V_269 = F_170 ( V_45 -> V_101 ) ;
if ( V_269 > 0 )
V_45 -> V_269 = V_269 ;
}
void F_171 ( struct V_44 * V_45 ,
struct V_101 * V_101 )
{
V_45 -> V_101 = V_101 ;
F_169 ( V_45 ) ;
}
void F_172 ( struct V_44 * V_45 )
{
F_173 ( V_45 -> V_101 ) ;
V_45 -> V_101 = NULL ;
}
static void F_174 ( struct V_44 * V_45 )
{
if ( ! V_45 -> V_270 && ! V_45 -> V_271 ) {
if ( ! V_45 -> V_101 )
V_45 -> V_101 = F_175 ( V_45 -> V_25 , NULL ) ;
if ( V_45 -> V_101 )
F_169 ( V_45 ) ;
}
F_84 ( & V_45 -> V_153 , & V_272 ) ;
}
static void F_176 ( struct V_44 * V_45 )
{
F_177 ( & V_273 ) ;
F_174 ( V_45 ) ;
F_126 ( & V_273 ) ;
}
static void F_178 ( struct V_44 * V_45 )
{
F_163 ( V_45 ) ;
F_15 ( V_45 -> V_47 ) ;
}
static void F_179 ( struct V_44 * V_45 )
{
F_67 ( & V_45 -> V_153 ) ;
}
static void F_180 ( struct V_44 * V_45 )
{
F_177 ( & V_273 ) ;
F_179 ( V_45 ) ;
F_126 ( & V_273 ) ;
}
int F_181 ( struct V_24 * V_25 ,
const struct V_266 * V_274 ,
struct V_81 * V_255 ,
int V_258 )
{
struct V_44 * V_275 ;
int V_14 ;
V_275 = F_87 ( sizeof( * V_275 ) , V_36 ) ;
if ( ! V_275 ) {
F_62 ( V_25 , L_72 ) ;
return - V_37 ;
}
V_14 = F_168 ( V_275 , V_274 , V_25 ) ;
if ( V_14 )
goto V_276;
V_275 -> V_277 = true ;
V_275 -> V_278 = true ;
V_14 = F_165 ( V_275 , V_255 , V_258 , true ) ;
if ( V_14 < 0 ) {
F_62 ( V_25 , L_73 , V_14 ) ;
goto V_279;
}
F_176 ( V_275 ) ;
return 0 ;
V_279:
F_178 ( V_275 ) ;
V_276:
F_15 ( V_275 ) ;
return V_14 ;
}
void F_182 ( struct V_24 * V_25 )
{
struct V_44 * V_275 ;
F_34 (cmpnt, &component_list, list) {
if ( V_25 == V_275 -> V_25 && V_275 -> V_278 )
goto V_250;
}
return;
V_250:
F_180 ( V_275 ) ;
F_178 ( V_275 ) ;
F_15 ( V_275 ) ;
}
static int F_183 ( struct V_44 * V_45 )
{
struct V_56 * V_57 = F_184 ( V_45 ) ;
return V_57 -> V_10 -> V_148 ( V_57 ) ;
}
static void F_185 ( struct V_44 * V_45 )
{
struct V_56 * V_57 = F_184 ( V_45 ) ;
V_57 -> V_10 -> remove ( V_57 ) ;
}
int F_186 ( struct V_24 * V_25 , struct V_56 * V_57 ,
const struct V_280 * V_281 )
{
int V_14 ;
V_14 = F_168 ( & V_57 -> V_45 ,
& V_281 -> V_282 , V_25 ) ;
if ( V_14 )
return V_14 ;
V_57 -> V_25 = V_25 ;
V_57 -> V_10 = V_281 ;
if ( V_281 -> V_148 )
V_57 -> V_45 . V_148 = F_183 ;
if ( V_281 -> remove )
V_57 -> V_45 . remove = F_185 ;
#ifdef F_102
V_57 -> V_45 . V_46 = L_74 ;
#endif
F_177 ( & V_273 ) ;
F_174 ( & V_57 -> V_45 ) ;
F_84 ( & V_57 -> V_153 , & V_283 ) ;
F_126 ( & V_273 ) ;
F_42 ( V_25 , L_75 ,
V_57 -> V_45 . V_47 ) ;
return 0 ;
}
int F_187 ( struct V_24 * V_25 ,
const struct V_280 * V_281 )
{
struct V_56 * V_57 ;
int V_14 ;
F_42 ( V_25 , L_76 , V_141 ( V_25 ) ) ;
V_57 = F_87 ( sizeof( struct V_56 ) , V_36 ) ;
if ( V_57 == NULL )
return - V_37 ;
V_14 = F_186 ( V_25 , V_57 , V_281 ) ;
if ( V_14 )
F_15 ( V_57 ) ;
return V_14 ;
}
void F_188 ( struct V_56 * V_57 )
{
F_177 ( & V_273 ) ;
F_67 ( & V_57 -> V_153 ) ;
F_179 ( & V_57 -> V_45 ) ;
F_126 ( & V_273 ) ;
F_42 ( V_57 -> V_25 , L_77 ,
V_57 -> V_45 . V_47 ) ;
F_178 ( & V_57 -> V_45 ) ;
}
struct V_56 * F_189 ( struct V_24 * V_25 )
{
struct V_56 * V_57 ;
F_34 (platform, &platform_list, list) {
if ( V_25 == V_57 -> V_25 )
return V_57 ;
}
return NULL ;
}
void F_190 ( struct V_24 * V_25 )
{
struct V_56 * V_57 ;
V_57 = F_189 ( V_25 ) ;
if ( ! V_57 )
return;
F_188 ( V_57 ) ;
F_15 ( V_57 ) ;
}
static void F_191 ( struct V_284 * V_64 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_122 ( V_285 ) ; V_3 ++ )
if ( V_64 -> V_286 & V_285 [ V_3 ] )
V_64 -> V_286 |= V_285 [ V_3 ] ;
}
static int F_192 ( struct V_44 * V_45 )
{
struct V_4 * V_5 = F_31 ( V_45 ) ;
return V_5 -> V_10 -> V_148 ( V_5 ) ;
}
static void F_193 ( struct V_44 * V_45 )
{
struct V_4 * V_5 = F_31 ( V_45 ) ;
V_5 -> V_10 -> remove ( V_5 ) ;
}
static int F_194 ( struct V_44 * V_45 ,
unsigned int V_6 , unsigned int V_1 )
{
struct V_4 * V_5 = F_31 ( V_45 ) ;
return V_5 -> V_10 -> V_270 ( V_5 , V_6 , V_1 ) ;
}
static int F_195 ( struct V_44 * V_45 ,
unsigned int V_6 , unsigned int * V_1 )
{
struct V_4 * V_5 = F_31 ( V_45 ) ;
* V_1 = V_5 -> V_10 -> V_271 ( V_5 , V_6 ) ;
return 0 ;
}
static int F_196 ( struct V_143 * V_91 ,
enum V_287 V_288 )
{
struct V_4 * V_5 = F_197 ( V_91 ) ;
return V_5 -> V_10 -> V_289 ( V_5 , V_288 ) ;
}
int F_198 ( struct V_24 * V_25 ,
const struct V_290 * V_291 ,
struct V_81 * V_255 ,
int V_258 )
{
struct V_4 * V_5 ;
struct V_54 * V_55 ;
int V_14 , V_3 ;
F_42 ( V_25 , L_78 , V_141 ( V_25 ) ) ;
V_5 = F_87 ( sizeof( struct V_4 ) , V_36 ) ;
if ( V_5 == NULL )
return - V_37 ;
V_5 -> V_45 . V_267 = & V_5 -> V_91 ;
V_5 -> V_45 . V_5 = V_5 ;
V_14 = F_168 ( & V_5 -> V_45 ,
& V_291 -> V_282 , V_25 ) ;
if ( V_14 )
goto V_276;
if ( V_291 -> V_149 ) {
V_5 -> V_45 . V_149 = V_291 -> V_149 ;
V_5 -> V_45 . V_150 = V_291 -> V_150 ;
}
if ( V_291 -> V_145 ) {
V_5 -> V_45 . V_145 = V_291 -> V_145 ;
V_5 -> V_45 . V_146 = V_291 -> V_146 ;
}
if ( V_291 -> V_151 ) {
V_5 -> V_45 . V_151 = V_291 -> V_151 ;
V_5 -> V_45 . V_152 = V_291 -> V_152 ;
}
if ( V_291 -> V_148 )
V_5 -> V_45 . V_148 = F_192 ;
if ( V_291 -> remove )
V_5 -> V_45 . remove = F_193 ;
if ( V_291 -> V_270 )
V_5 -> V_45 . V_270 = F_194 ;
if ( V_291 -> V_271 )
V_5 -> V_45 . V_271 = F_195 ;
V_5 -> V_45 . V_277 = V_291 -> V_277 ;
V_5 -> V_91 . V_99 = V_291 -> V_99 ;
V_5 -> V_91 . V_292 = V_291 -> V_292 ;
if ( V_291 -> V_263 )
V_5 -> V_91 . V_263 = V_291 -> V_263 ;
if ( V_291 -> V_289 )
V_5 -> V_91 . V_289 = F_196 ;
V_5 -> V_25 = V_25 ;
V_5 -> V_10 = V_291 ;
V_5 -> V_45 . V_269 = V_291 -> V_13 ;
#ifdef F_102
V_5 -> V_45 . V_51 = F_30 ;
V_5 -> V_45 . V_46 = L_79 ;
#endif
if ( V_291 -> V_293 )
V_5 -> V_45 . V_101 = V_291 -> V_293 ( V_25 ) ;
for ( V_3 = 0 ; V_3 < V_258 ; V_3 ++ ) {
F_191 ( & V_255 [ V_3 ] . V_294 ) ;
F_191 ( & V_255 [ V_3 ] . V_295 ) ;
}
V_14 = F_165 ( & V_5 -> V_45 , V_255 , V_258 , false ) ;
if ( V_14 < 0 ) {
F_62 ( V_25 , L_73 , V_14 ) ;
goto V_279;
}
F_34 (dai, &codec->component.dai_list, list)
V_55 -> V_5 = V_5 ;
F_177 ( & V_273 ) ;
F_174 ( & V_5 -> V_45 ) ;
F_84 ( & V_5 -> V_153 , & V_296 ) ;
F_126 ( & V_273 ) ;
F_42 ( V_5 -> V_25 , L_80 ,
V_5 -> V_45 . V_47 ) ;
return 0 ;
V_279:
F_178 ( & V_5 -> V_45 ) ;
V_276:
F_15 ( V_5 ) ;
return V_14 ;
}
void F_199 ( struct V_24 * V_25 )
{
struct V_4 * V_5 ;
F_34 (codec, &codec_list, list) {
if ( V_25 == V_5 -> V_25 )
goto V_250;
}
return;
V_250:
F_177 ( & V_273 ) ;
F_67 ( & V_5 -> V_153 ) ;
F_179 ( & V_5 -> V_45 ) ;
F_126 ( & V_273 ) ;
F_42 ( V_5 -> V_25 , L_81 ,
V_5 -> V_45 . V_47 ) ;
F_178 ( & V_5 -> V_45 ) ;
F_200 ( V_5 ) ;
F_15 ( V_5 ) ;
}
int F_201 ( struct V_58 * V_49 ,
const char * V_297 )
{
struct V_111 * V_298 ;
int V_14 ;
if ( ! V_49 -> V_25 ) {
F_202 ( L_82 , V_299 ) ;
return - V_17 ;
}
V_298 = V_49 -> V_25 -> V_112 ;
V_14 = F_203 ( V_298 , V_297 , 0 , & V_49 -> V_47 ) ;
if ( V_14 < 0 && V_14 != - V_17 ) {
F_62 ( V_49 -> V_25 ,
L_83 ,
V_297 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
int F_204 ( struct V_58 * V_49 ,
const char * V_297 )
{
struct V_111 * V_298 = V_49 -> V_25 -> V_112 ;
struct V_163 * V_300 ;
const char * V_208 , * V_301 ;
int V_3 , V_72 , V_302 , V_14 ;
V_302 = F_205 ( V_298 , V_297 ) ;
if ( V_302 < 0 ) {
F_62 ( V_49 -> V_25 ,
L_84 , V_297 ) ;
return - V_17 ;
}
if ( V_302 & 1 ) {
F_62 ( V_49 -> V_25 ,
L_85 , V_297 ) ;
return - V_17 ;
}
V_302 /= 2 ;
if ( ! V_302 ) {
F_62 ( V_49 -> V_25 , L_86 ,
V_297 ) ;
return - V_17 ;
}
V_300 = F_206 ( V_49 -> V_25 , V_302 , sizeof( * V_300 ) ,
V_36 ) ;
if ( ! V_300 ) {
F_62 ( V_49 -> V_25 ,
L_87 ) ;
return - V_37 ;
}
for ( V_3 = 0 ; V_3 < V_302 ; V_3 ++ ) {
V_14 = F_203 ( V_298 , V_297 ,
2 * V_3 , & V_208 ) ;
if ( V_14 ) {
F_62 ( V_49 -> V_25 ,
L_88 ,
V_297 , 2 * V_3 , V_14 ) ;
return - V_17 ;
}
for ( V_72 = 0 ; V_72 < F_122 ( V_303 ) ; V_72 ++ ) {
if ( ! strncmp ( V_208 , V_303 [ V_72 ] . V_47 ,
strlen ( V_303 [ V_72 ] . V_47 ) ) ) {
V_300 [ V_3 ] = V_303 [ V_72 ] ;
break;
}
}
if ( V_72 >= F_122 ( V_303 ) ) {
F_62 ( V_49 -> V_25 ,
L_89 ,
V_208 ) ;
return - V_17 ;
}
V_14 = F_203 ( V_298 , V_297 ,
( 2 * V_3 ) + 1 ,
& V_301 ) ;
if ( V_14 ) {
F_62 ( V_49 -> V_25 ,
L_88 ,
V_297 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_17 ;
}
V_300 [ V_3 ] . V_47 = V_301 ;
}
V_49 -> V_145 = V_300 ;
V_49 -> V_146 = V_302 ;
return 0 ;
}
int F_207 ( struct V_111 * V_298 ,
unsigned int * V_230 ,
unsigned int * V_233 )
{
T_5 V_1 ;
int V_14 ;
if ( F_208 ( V_298 , L_90 ) ) {
V_14 = F_209 ( V_298 , L_90 , & V_1 ) ;
if ( V_14 )
return V_14 ;
if ( V_230 )
* V_230 = V_1 ;
}
if ( F_208 ( V_298 , L_91 ) ) {
V_14 = F_209 ( V_298 , L_91 , & V_1 ) ;
if ( V_14 )
return V_14 ;
if ( V_233 )
* V_233 = V_1 ;
}
return 0 ;
}
int F_210 ( struct V_58 * V_49 ,
const char * V_297 )
{
struct V_111 * V_298 = V_49 -> V_25 -> V_112 ;
int V_304 ;
struct V_305 * V_306 ;
int V_3 , V_14 ;
V_304 = F_205 ( V_298 , V_297 ) ;
if ( V_304 < 0 || V_304 & 1 ) {
F_62 ( V_49 -> V_25 ,
L_92 ,
V_297 ) ;
return - V_17 ;
}
V_304 /= 2 ;
if ( ! V_304 ) {
F_62 ( V_49 -> V_25 , L_86 ,
V_297 ) ;
return - V_17 ;
}
V_306 = F_157 ( V_49 -> V_25 , V_304 * sizeof( * V_306 ) ,
V_36 ) ;
if ( ! V_306 ) {
F_62 ( V_49 -> V_25 ,
L_93 ) ;
return - V_17 ;
}
for ( V_3 = 0 ; V_3 < V_304 ; V_3 ++ ) {
V_14 = F_203 ( V_298 , V_297 ,
2 * V_3 , & V_306 [ V_3 ] . V_307 ) ;
if ( V_14 ) {
F_62 ( V_49 -> V_25 ,
L_94 ,
V_297 , 2 * V_3 , V_14 ) ;
return - V_17 ;
}
V_14 = F_203 ( V_298 , V_297 ,
( 2 * V_3 ) + 1 , & V_306 [ V_3 ] . V_219 ) ;
if ( V_14 ) {
F_62 ( V_49 -> V_25 ,
L_94 ,
V_297 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_17 ;
}
}
V_49 -> V_152 = V_304 ;
V_49 -> V_151 = V_306 ;
return 0 ;
}
unsigned int F_211 ( struct V_111 * V_298 ,
const char * V_207 ,
struct V_111 * * V_308 ,
struct V_111 * * V_309 )
{
int V_14 , V_3 ;
char V_310 [ 128 ] ;
unsigned int V_311 = 0 ;
int V_312 , V_313 ;
const char * V_314 ;
struct {
char * V_47 ;
unsigned int V_1 ;
} V_315 [] = {
{ L_95 , V_316 } ,
{ L_96 , V_317 } ,
{ L_97 , V_318 } ,
{ L_98 , V_319 } ,
{ L_99 , V_320 } ,
{ L_100 , V_321 } ,
{ L_101 , V_322 } ,
{ L_102 , V_323 } ,
{ L_103 , V_324 } ,
} ;
if ( ! V_207 )
V_207 = L_104 ;
snprintf ( V_310 , sizeof( V_310 ) , L_105 , V_207 ) ;
V_14 = F_212 ( V_298 , V_310 , & V_314 ) ;
if ( V_14 == 0 ) {
for ( V_3 = 0 ; V_3 < F_122 ( V_315 ) ; V_3 ++ ) {
if ( strcmp ( V_314 , V_315 [ V_3 ] . V_47 ) == 0 ) {
V_311 |= V_315 [ V_3 ] . V_1 ;
break;
}
}
}
snprintf ( V_310 , sizeof( V_310 ) , L_106 , V_207 ) ;
if ( F_213 ( V_298 , V_310 , NULL ) )
V_311 |= V_325 ;
else
V_311 |= V_326 ;
snprintf ( V_310 , sizeof( V_310 ) , L_107 , V_207 ) ;
V_312 = ! ! F_213 ( V_298 , V_310 , NULL ) ;
snprintf ( V_310 , sizeof( V_310 ) , L_108 , V_207 ) ;
V_313 = ! ! F_213 ( V_298 , V_310 , NULL ) ;
switch ( ( V_312 << 4 ) + V_313 ) {
case 0x11 :
V_311 |= V_327 ;
break;
case 0x10 :
V_311 |= V_328 ;
break;
case 0x01 :
V_311 |= V_329 ;
break;
default:
break;
}
snprintf ( V_310 , sizeof( V_310 ) , L_109 , V_207 ) ;
V_312 = ! ! F_213 ( V_298 , V_310 , NULL ) ;
if ( V_312 && V_308 )
* V_308 = F_214 ( V_298 , V_310 , 0 ) ;
snprintf ( V_310 , sizeof( V_310 ) , L_110 , V_207 ) ;
V_313 = ! ! F_213 ( V_298 , V_310 , NULL ) ;
if ( V_313 && V_309 )
* V_309 = F_214 ( V_298 , V_310 , 0 ) ;
switch ( ( V_312 << 4 ) + V_313 ) {
case 0x11 :
V_311 |= V_191 ;
break;
case 0x10 :
V_311 |= V_193 ;
break;
case 0x01 :
V_311 |= V_194 ;
break;
default:
V_311 |= V_192 ;
break;
}
return V_311 ;
}
static int F_215 ( struct V_330 * args ,
const char * * V_115 )
{
struct V_44 * V_19 ;
int V_14 = - V_124 ;
F_177 ( & V_273 ) ;
F_34 (pos, &component_list, list) {
if ( V_19 -> V_25 -> V_112 != args -> V_298 )
continue;
if ( V_19 -> V_10 -> V_331 ) {
V_14 = V_19 -> V_10 -> V_331 ( V_19 ,
args ,
V_115 ) ;
} else {
int V_214 = - 1 ;
switch ( args -> V_332 ) {
case 0 :
V_214 = 0 ;
break;
case 1 :
V_214 = args -> args [ 0 ] ;
break;
default:
break;
}
if ( V_214 < 0 || V_214 >= V_19 -> V_258 ) {
V_14 = - V_17 ;
continue;
}
V_14 = 0 ;
* V_115 = V_19 -> V_255 [ V_214 ] . V_47 ;
if ( ! * V_115 )
* V_115 = V_19 -> V_47 ;
}
break;
}
F_126 ( & V_273 ) ;
return V_14 ;
}
int F_216 ( struct V_111 * V_112 ,
const char * * V_115 )
{
struct V_330 args ;
int V_14 ;
V_14 = F_217 ( V_112 , L_111 ,
L_112 , 0 , & args ) ;
if ( V_14 )
return V_14 ;
V_14 = F_215 ( & args , V_115 ) ;
F_218 ( args . V_298 ) ;
return V_14 ;
}
int F_219 ( struct V_24 * V_25 ,
struct V_111 * V_112 ,
struct V_117 * V_63 )
{
struct V_330 args ;
struct V_113 * V_45 ;
char * V_47 ;
int V_210 , V_79 , V_14 ;
V_47 = L_111 ;
V_79 = F_220 ( V_112 , V_47 ,
L_112 ) ;
if ( V_79 <= 0 ) {
if ( V_79 == - V_333 )
F_62 ( V_25 , L_113 ) ;
else
F_62 ( V_25 , L_114 ) ;
return V_79 ;
}
V_45 = F_157 ( V_25 ,
sizeof *V_45 * V_79 ,
V_36 ) ;
if ( ! V_45 )
return - V_37 ;
V_63 -> V_118 = V_45 ;
V_63 -> V_79 = V_79 ;
for ( V_210 = 0 , V_45 = V_63 -> V_118 ;
V_210 < V_63 -> V_79 ;
V_210 ++ , V_45 ++ ) {
V_14 = F_217 ( V_112 , V_47 ,
L_112 ,
V_210 , & args ) ;
if ( V_14 )
goto V_130;
V_45 -> V_112 = args . V_298 ;
V_14 = F_215 ( & args , & V_45 -> V_115 ) ;
if ( V_14 < 0 )
goto V_130;
}
return 0 ;
V_130:
for ( V_210 = 0 , V_45 = V_63 -> V_118 ;
V_210 < V_63 -> V_79 ;
V_210 ++ , V_45 ++ ) {
if ( ! V_45 -> V_112 )
break;
F_218 ( V_45 -> V_112 ) ;
V_45 -> V_112 = NULL ;
}
V_63 -> V_118 = NULL ;
V_63 -> V_79 = 0 ;
return V_14 ;
}
static int T_6 F_221 ( void )
{
#ifdef F_102
V_59 = F_24 ( L_115 , NULL ) ;
if ( F_222 ( V_59 ) || ! V_59 ) {
F_223 ( L_116 ) ;
V_59 = NULL ;
}
if ( ! F_32 ( L_117 , 0444 , V_59 , NULL ,
& V_334 ) )
F_223 ( L_118 ) ;
if ( ! F_32 ( L_119 , 0444 , V_59 , NULL ,
& V_335 ) )
F_223 ( L_120 ) ;
if ( ! F_32 ( L_121 , 0444 , V_59 , NULL ,
& V_336 ) )
F_223 ( L_122 ) ;
#endif
F_224 () ;
return F_225 ( & V_337 ) ;
}
static void T_7 F_226 ( void )
{
F_227 () ;
#ifdef F_102
F_29 ( V_59 ) ;
#endif
F_228 ( & V_337 ) ;
}
