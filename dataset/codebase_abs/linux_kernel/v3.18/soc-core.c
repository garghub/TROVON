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
F_32 ( L_6 , 0444 , V_5 -> V_45 . V_48 ,
& V_5 -> V_52 ) ;
V_5 -> V_53 = F_33 ( L_7 , 0644 ,
V_5 -> V_45 . V_48 ,
V_5 , & V_54 ) ;
if ( ! V_5 -> V_53 )
F_25 ( V_5 -> V_25 ,
L_8 ) ;
}
static T_2 F_34 ( struct V_32 * V_32 , char T_4 * V_33 ,
T_1 V_18 , T_3 * V_34 )
{
char * V_7 = F_13 ( V_30 , V_36 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_4 * V_5 ;
if ( ! V_7 )
return - V_37 ;
F_35 (codec, &codec_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_30 - V_14 , L_9 ,
V_5 -> V_45 . V_47 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_30 ) {
V_14 = V_30 ;
break;
}
}
if ( V_14 >= 0 )
V_14 = F_36 ( V_33 , V_18 , V_34 , V_7 , V_14 ) ;
F_15 ( V_7 ) ;
return V_14 ;
}
static T_2 F_37 ( struct V_32 * V_32 , char T_4 * V_33 ,
T_1 V_18 , T_3 * V_34 )
{
char * V_7 = F_13 ( V_30 , V_36 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_44 * V_45 ;
struct V_55 * V_56 ;
if ( ! V_7 )
return - V_37 ;
F_35 (component, &component_list, list) {
F_35 (dai, &component->dai_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_30 - V_14 , L_9 ,
V_56 -> V_47 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_30 ) {
V_14 = V_30 ;
break;
}
}
}
V_14 = F_36 ( V_33 , V_18 , V_34 , V_7 , V_14 ) ;
F_15 ( V_7 ) ;
return V_14 ;
}
static T_2 F_38 ( struct V_32 * V_32 ,
char T_4 * V_33 ,
T_1 V_18 , T_3 * V_34 )
{
char * V_7 = F_13 ( V_30 , V_36 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_57 * V_58 ;
if ( ! V_7 )
return - V_37 ;
F_35 (platform, &platform_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_30 - V_14 , L_9 ,
V_58 -> V_45 . V_47 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_30 ) {
V_14 = V_30 ;
break;
}
}
V_14 = F_36 ( V_33 , V_18 , V_34 , V_7 , V_14 ) ;
F_15 ( V_7 ) ;
return V_14 ;
}
static void F_39 ( struct V_59 * V_49 )
{
V_49 -> V_50 = F_24 ( V_49 -> V_47 ,
V_60 ) ;
if ( ! V_49 -> V_50 ) {
F_25 ( V_49 -> V_25 ,
L_10 ) ;
return;
}
V_49 -> V_61 = F_40 ( L_11 , 0644 ,
V_49 -> V_50 ,
& V_49 -> V_62 ) ;
if ( ! V_49 -> V_61 )
F_25 ( V_49 -> V_25 ,
L_12 ) ;
}
static void F_41 ( struct V_59 * V_49 )
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
static inline void F_39 ( struct V_59 * V_49 )
{
}
static inline void F_41 ( struct V_59 * V_49 )
{
}
struct V_63 * F_42 ( struct V_59 * V_49 ,
const char * V_64 , int V_65 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_49 -> V_66 ; V_3 ++ ) {
if ( V_49 -> V_29 [ V_3 ] . V_64 -> V_67 &&
! strcmp ( V_49 -> V_29 [ V_3 ] . V_64 -> V_47 , V_64 ) )
return V_49 -> V_29 [ V_3 ] . V_68 -> V_69 [ V_65 ] . V_70 ;
}
F_43 ( V_49 -> V_25 , L_13 , V_64 ) ;
return NULL ;
}
struct V_28 * F_44 ( struct V_59 * V_49 ,
const char * V_64 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_49 -> V_66 ; V_3 ++ ) {
if ( ! strcmp ( V_49 -> V_29 [ V_3 ] . V_64 -> V_47 , V_64 ) )
return & V_49 -> V_29 [ V_3 ] ;
}
F_43 ( V_49 -> V_25 , L_14 , V_64 ) ;
return NULL ;
}
static int F_45 ( struct V_4 * V_5 )
{
if ( V_5 -> V_71 -> V_25 . V_72 )
F_46 ( & V_5 -> V_71 -> V_25 ) ;
return 0 ;
}
static void F_47 ( struct V_24 * V_25 ) {}
static int F_48 ( struct V_4 * V_5 )
{
int V_73 ;
V_5 -> V_71 -> V_25 . V_72 = & V_74 ;
V_5 -> V_71 -> V_25 . V_75 = V_5 -> V_45 . V_49 -> V_25 ;
V_5 -> V_71 -> V_25 . V_76 = F_47 ;
F_49 ( & V_5 -> V_71 -> V_25 , L_15 ,
V_5 -> V_45 . V_49 -> V_77 -> V_78 , 0 ,
V_5 -> V_45 . V_47 ) ;
V_73 = F_50 ( & V_5 -> V_71 -> V_25 ) ;
if ( V_73 < 0 ) {
F_51 ( V_5 -> V_25 , L_16 ) ;
V_5 -> V_71 -> V_25 . V_72 = NULL ;
return V_73 ;
}
return 0 ;
}
static void F_52 ( struct V_79 * V_80 )
{
}
int F_53 ( struct V_24 * V_25 )
{
struct V_59 * V_49 = F_8 ( V_25 ) ;
struct V_4 * V_5 ;
int V_3 , V_81 ;
if ( ! V_49 -> V_82 )
return 0 ;
F_54 ( V_49 -> V_77 ) ;
F_55 ( V_49 -> V_77 , V_83 ) ;
F_56 ( V_49 -> V_77 ) ;
F_57 ( V_49 -> V_77 , V_84 ) ;
for ( V_3 = 0 ; V_3 < V_49 -> V_85 ; V_3 ++ ) {
if ( V_49 -> V_29 [ V_3 ] . V_64 -> V_86 )
continue;
for ( V_81 = 0 ; V_81 < V_49 -> V_29 [ V_3 ] . V_87 ; V_81 ++ ) {
struct V_55 * V_56 = V_49 -> V_29 [ V_3 ] . V_88 [ V_81 ] ;
struct V_89 * V_90 = V_56 -> V_10 ;
if ( V_90 -> V_91 -> V_92 && V_56 -> V_93 )
V_90 -> V_91 -> V_92 ( V_56 , 1 ) ;
}
}
for ( V_3 = 0 ; V_3 < V_49 -> V_85 ; V_3 ++ ) {
if ( V_49 -> V_29 [ V_3 ] . V_64 -> V_86 )
continue;
F_58 ( V_49 -> V_29 [ V_3 ] . V_68 ) ;
}
if ( V_49 -> V_94 )
V_49 -> V_94 ( V_49 ) ;
for ( V_3 = 0 ; V_3 < V_49 -> V_85 ; V_3 ++ ) {
struct V_55 * V_95 = V_49 -> V_29 [ V_3 ] . V_95 ;
struct V_57 * V_58 = V_49 -> V_29 [ V_3 ] . V_58 ;
if ( V_49 -> V_29 [ V_3 ] . V_64 -> V_86 )
continue;
if ( V_95 -> V_10 -> V_96 && ! V_95 -> V_10 -> V_97 )
V_95 -> V_10 -> V_96 ( V_95 ) ;
if ( V_58 -> V_10 -> V_96 && ! V_58 -> V_98 ) {
V_58 -> V_10 -> V_96 ( V_95 ) ;
V_58 -> V_98 = 1 ;
}
}
for ( V_3 = 0 ; V_3 < V_49 -> V_85 ; V_3 ++ ) {
struct V_55 * * V_88 = V_49 -> V_29 [ V_3 ] . V_88 ;
F_59 ( & V_49 -> V_29 [ V_3 ] . V_99 ) ;
for ( V_81 = 0 ; V_81 < V_49 -> V_29 [ V_3 ] . V_87 ; V_81 ++ ) {
V_88 [ V_81 ] -> V_5 -> V_100 . V_101 =
V_88 [ V_81 ] -> V_5 -> V_100 . V_102 ;
}
}
for ( V_3 = 0 ; V_3 < V_49 -> V_85 ; V_3 ++ ) {
if ( V_49 -> V_29 [ V_3 ] . V_64 -> V_86 )
continue;
F_60 ( & V_49 -> V_29 [ V_3 ] ,
V_103 ,
V_104 ) ;
F_60 ( & V_49 -> V_29 [ V_3 ] ,
V_105 ,
V_104 ) ;
}
F_61 ( & V_49 -> V_100 ) ;
F_62 ( & V_49 -> V_100 ) ;
F_35 (codec, &card->codec_dev_list, card_list) {
if ( ! V_5 -> V_98 ) {
switch ( V_5 -> V_100 . V_102 ) {
case V_106 :
if ( V_5 -> V_100 . V_107 ) {
F_43 ( V_5 -> V_25 ,
L_17 ) ;
break;
}
case V_108 :
if ( V_5 -> V_10 -> V_96 )
V_5 -> V_10 -> V_96 ( V_5 ) ;
V_5 -> V_98 = 1 ;
V_5 -> V_52 = 1 ;
if ( V_5 -> V_45 . V_109 )
F_63 ( V_5 -> V_45 . V_109 ) ;
F_64 ( V_5 -> V_25 ) ;
break;
default:
F_43 ( V_5 -> V_25 ,
L_18 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_49 -> V_85 ; V_3 ++ ) {
struct V_55 * V_95 = V_49 -> V_29 [ V_3 ] . V_95 ;
if ( V_49 -> V_29 [ V_3 ] . V_64 -> V_86 )
continue;
if ( V_95 -> V_10 -> V_96 && V_95 -> V_10 -> V_97 )
V_95 -> V_10 -> V_96 ( V_95 ) ;
F_64 ( V_95 -> V_25 ) ;
}
if ( V_49 -> V_110 )
V_49 -> V_110 ( V_49 ) ;
return 0 ;
}
static void F_65 ( struct V_79 * V_80 )
{
struct V_59 * V_49 =
F_66 ( V_80 , struct V_59 , V_111 ) ;
struct V_4 * V_5 ;
int V_3 , V_81 ;
F_43 ( V_49 -> V_25 , L_19 ) ;
F_57 ( V_49 -> V_77 , V_112 ) ;
if ( V_49 -> V_113 )
V_49 -> V_113 ( V_49 ) ;
for ( V_3 = 0 ; V_3 < V_49 -> V_85 ; V_3 ++ ) {
struct V_55 * V_95 = V_49 -> V_29 [ V_3 ] . V_95 ;
if ( V_49 -> V_29 [ V_3 ] . V_64 -> V_86 )
continue;
if ( V_95 -> V_10 -> V_114 && V_95 -> V_10 -> V_97 )
V_95 -> V_10 -> V_114 ( V_95 ) ;
}
F_35 (codec, &card->codec_dev_list, card_list) {
if ( V_5 -> V_98 ) {
switch ( V_5 -> V_100 . V_102 ) {
case V_106 :
case V_108 :
if ( V_5 -> V_10 -> V_114 )
V_5 -> V_10 -> V_114 ( V_5 ) ;
V_5 -> V_98 = 0 ;
break;
default:
F_43 ( V_5 -> V_25 ,
L_20 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_49 -> V_85 ; V_3 ++ ) {
if ( V_49 -> V_29 [ V_3 ] . V_64 -> V_86 )
continue;
F_60 ( & V_49 -> V_29 [ V_3 ] ,
V_103 ,
V_115 ) ;
F_60 ( & V_49 -> V_29 [ V_3 ] ,
V_105 ,
V_115 ) ;
}
for ( V_3 = 0 ; V_3 < V_49 -> V_85 ; V_3 ++ ) {
if ( V_49 -> V_29 [ V_3 ] . V_64 -> V_86 )
continue;
for ( V_81 = 0 ; V_81 < V_49 -> V_29 [ V_3 ] . V_87 ; V_81 ++ ) {
struct V_55 * V_56 = V_49 -> V_29 [ V_3 ] . V_88 [ V_81 ] ;
struct V_89 * V_90 = V_56 -> V_10 ;
if ( V_90 -> V_91 -> V_92 && V_56 -> V_93 )
V_90 -> V_91 -> V_92 ( V_56 , 0 ) ;
}
}
for ( V_3 = 0 ; V_3 < V_49 -> V_85 ; V_3 ++ ) {
struct V_55 * V_95 = V_49 -> V_29 [ V_3 ] . V_95 ;
struct V_57 * V_58 = V_49 -> V_29 [ V_3 ] . V_58 ;
if ( V_49 -> V_29 [ V_3 ] . V_64 -> V_86 )
continue;
if ( V_95 -> V_10 -> V_114 && ! V_95 -> V_10 -> V_97 )
V_95 -> V_10 -> V_114 ( V_95 ) ;
if ( V_58 -> V_10 -> V_114 && V_58 -> V_98 ) {
V_58 -> V_10 -> V_114 ( V_95 ) ;
V_58 -> V_98 = 0 ;
}
}
if ( V_49 -> V_116 )
V_49 -> V_116 ( V_49 ) ;
F_43 ( V_49 -> V_25 , L_21 ) ;
F_57 ( V_49 -> V_77 , V_83 ) ;
F_61 ( & V_49 -> V_100 ) ;
F_62 ( & V_49 -> V_100 ) ;
}
int F_67 ( struct V_24 * V_25 )
{
struct V_59 * V_49 = F_8 ( V_25 ) ;
int V_3 , V_97 = 0 ;
if ( ! V_49 -> V_82 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_49 -> V_85 ; V_3 ++ ) {
struct V_28 * V_29 = & V_49 -> V_29 [ V_3 ] ;
struct V_55 * * V_88 = V_29 -> V_88 ;
struct V_55 * V_95 = V_29 -> V_95 ;
int V_81 ;
if ( V_95 -> V_117 )
F_68 ( V_95 -> V_25 ) ;
for ( V_81 = 0 ; V_81 < V_29 -> V_87 ; V_81 ++ ) {
struct V_55 * V_118 = V_88 [ V_81 ] ;
if ( V_118 -> V_117 )
F_68 ( V_118 -> V_25 ) ;
}
}
for ( V_3 = 0 ; V_3 < V_49 -> V_85 ; V_3 ++ ) {
struct V_55 * V_95 = V_49 -> V_29 [ V_3 ] . V_95 ;
V_97 |= V_95 -> V_10 -> V_97 ;
}
if ( V_97 ) {
F_43 ( V_25 , L_22 ) ;
F_65 ( & V_49 -> V_111 ) ;
} else {
F_43 ( V_25 , L_23 ) ;
if ( ! F_69 ( & V_49 -> V_111 ) )
F_51 ( V_25 , L_24 ) ;
}
return 0 ;
}
static struct V_44 * F_70 (
const struct V_119 * V_120 , const char * V_47 )
{
struct V_44 * V_45 ;
F_35 (component, &component_list, list) {
if ( V_120 ) {
if ( V_45 -> V_25 -> V_120 == V_120 )
return V_45 ;
} else if ( strcmp ( V_45 -> V_47 , V_47 ) == 0 ) {
return V_45 ;
}
}
return NULL ;
}
static struct V_55 * F_71 (
const struct V_121 * V_122 )
{
struct V_44 * V_45 ;
struct V_55 * V_56 ;
F_35 (component, &component_list, list) {
if ( V_122 -> V_120 && V_45 -> V_25 -> V_120 != V_122 -> V_120 )
continue;
if ( V_122 -> V_47 && strcmp ( V_45 -> V_47 , V_122 -> V_47 ) )
continue;
F_35 (dai, &component->dai_list, list) {
if ( V_122 -> V_123 && strcmp ( V_56 -> V_47 , V_122 -> V_123 ) )
continue;
return V_56 ;
}
}
return NULL ;
}
static int F_72 ( struct V_59 * V_49 , int V_124 )
{
struct V_125 * V_64 = & V_49 -> V_64 [ V_124 ] ;
struct V_28 * V_29 = & V_49 -> V_29 [ V_124 ] ;
struct V_121 * V_126 = V_64 -> V_126 ;
struct V_121 V_127 ;
struct V_55 * * V_88 = V_29 -> V_88 ;
struct V_57 * V_58 ;
const char * V_128 ;
int V_3 ;
F_43 ( V_49 -> V_25 , L_25 , V_64 -> V_47 , V_124 ) ;
V_127 . V_47 = V_64 -> V_129 ;
V_127 . V_120 = V_64 -> V_130 ;
V_127 . V_123 = V_64 -> V_131 ;
V_29 -> V_95 = F_71 ( & V_127 ) ;
if ( ! V_29 -> V_95 ) {
F_51 ( V_49 -> V_25 , L_26 ,
V_64 -> V_131 ) ;
return - V_132 ;
}
V_29 -> V_87 = V_64 -> V_87 ;
for ( V_3 = 0 ; V_3 < V_29 -> V_87 ; V_3 ++ ) {
V_88 [ V_3 ] = F_71 ( & V_126 [ V_3 ] ) ;
if ( ! V_88 [ V_3 ] ) {
F_51 ( V_49 -> V_25 , L_27 ,
V_126 [ V_3 ] . V_123 ) ;
return - V_132 ;
}
}
V_29 -> V_118 = V_88 [ 0 ] ;
V_29 -> V_5 = V_29 -> V_118 -> V_5 ;
V_128 = V_64 -> V_128 ;
if ( ! V_128 && ! V_64 -> V_133 )
V_128 = L_28 ;
F_35 (platform, &platform_list, list) {
if ( V_64 -> V_133 ) {
if ( V_58 -> V_25 -> V_120 !=
V_64 -> V_133 )
continue;
} else {
if ( strcmp ( V_58 -> V_45 . V_47 , V_128 ) )
continue;
}
V_29 -> V_58 = V_58 ;
}
if ( ! V_29 -> V_58 ) {
F_51 ( V_49 -> V_25 , L_29 ,
V_64 -> V_128 ) ;
return - V_132 ;
}
V_49 -> V_85 ++ ;
return 0 ;
}
static void F_73 ( struct V_44 * V_45 )
{
if ( ! V_45 -> V_134 )
return;
if ( V_45 -> V_5 )
F_74 ( & V_45 -> V_5 -> V_135 ) ;
if ( V_45 -> remove )
V_45 -> remove ( V_45 ) ;
F_75 ( F_27 ( V_45 ) ) ;
F_28 ( V_45 ) ;
V_45 -> V_134 = 0 ;
F_76 ( V_45 -> V_25 -> V_10 -> V_136 ) ;
}
static void F_77 ( struct V_55 * V_56 , int V_137 )
{
int V_73 ;
if ( V_56 && V_56 -> V_134 &&
V_56 -> V_10 -> V_138 == V_137 ) {
if ( V_56 -> V_10 -> remove ) {
V_73 = V_56 -> V_10 -> remove ( V_56 ) ;
if ( V_73 < 0 )
F_51 ( V_56 -> V_25 ,
L_30 ,
V_56 -> V_47 , V_73 ) ;
}
V_56 -> V_134 = 0 ;
}
}
static void F_78 ( struct V_59 * V_49 , int V_124 , int V_137 )
{
struct V_28 * V_29 = & V_49 -> V_29 [ V_124 ] ;
int V_3 ;
if ( V_29 -> V_139 ) {
F_79 ( V_29 -> V_25 , & V_140 ) ;
F_79 ( V_29 -> V_25 , & V_141 ) ;
F_46 ( V_29 -> V_25 ) ;
V_29 -> V_139 = 0 ;
}
for ( V_3 = 0 ; V_3 < V_29 -> V_87 ; V_3 ++ )
F_77 ( V_29 -> V_88 [ V_3 ] , V_137 ) ;
F_77 ( V_29 -> V_95 , V_137 ) ;
}
static void F_80 ( struct V_59 * V_49 , int V_124 ,
int V_137 )
{
struct V_28 * V_29 = & V_49 -> V_29 [ V_124 ] ;
struct V_55 * V_95 = V_29 -> V_95 ;
struct V_57 * V_58 = V_29 -> V_58 ;
struct V_44 * V_45 ;
int V_3 ;
if ( V_58 && V_58 -> V_45 . V_10 -> V_138 == V_137 )
F_73 ( & V_58 -> V_45 ) ;
for ( V_3 = 0 ; V_3 < V_29 -> V_87 ; V_3 ++ ) {
V_45 = V_29 -> V_88 [ V_3 ] -> V_45 ;
if ( V_45 -> V_10 -> V_138 == V_137 )
F_73 ( V_45 ) ;
}
if ( V_95 ) {
if ( V_95 -> V_45 -> V_10 -> V_138 == V_137 )
F_73 ( V_95 -> V_45 ) ;
}
}
static void F_81 ( struct V_59 * V_49 )
{
int V_56 , V_137 ;
for ( V_137 = V_142 ; V_137 <= V_143 ;
V_137 ++ ) {
for ( V_56 = 0 ; V_56 < V_49 -> V_85 ; V_56 ++ )
F_78 ( V_49 , V_56 , V_137 ) ;
}
for ( V_137 = V_142 ; V_137 <= V_143 ;
V_137 ++ ) {
for ( V_56 = 0 ; V_56 < V_49 -> V_85 ; V_56 ++ )
F_80 ( V_49 , V_56 , V_137 ) ;
}
V_49 -> V_85 = 0 ;
}
static void F_82 ( struct V_59 * V_49 ,
struct V_44 * V_45 )
{
int V_3 ;
if ( V_49 -> V_144 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_49 -> V_145 ; V_3 ++ ) {
struct V_146 * V_147 = & V_49 -> V_144 [ V_3 ] ;
if ( V_147 -> V_120 && V_45 -> V_25 -> V_120 != V_147 -> V_120 )
continue;
if ( V_147 -> V_148 && strcmp ( V_45 -> V_47 , V_147 -> V_148 ) )
continue;
V_45 -> V_149 = V_147 -> V_149 ;
break;
}
}
static int F_83 ( struct V_59 * V_49 ,
struct V_44 * V_45 )
{
struct V_150 * V_100 = F_27 ( V_45 ) ;
struct V_55 * V_56 ;
int V_14 ;
if ( V_45 -> V_134 )
return 0 ;
V_45 -> V_49 = V_49 ;
V_100 -> V_49 = V_49 ;
F_82 ( V_49 , V_45 ) ;
if ( ! F_84 ( V_45 -> V_25 -> V_10 -> V_136 ) )
return - V_151 ;
F_22 ( V_45 ) ;
if ( V_45 -> V_152 ) {
V_14 = F_85 ( V_100 , V_45 -> V_152 ,
V_45 -> V_153 ) ;
if ( V_14 != 0 ) {
F_51 ( V_45 -> V_25 ,
L_31 , V_14 ) ;
goto V_154;
}
}
F_35 (dai, &component->dai_list, list) {
V_14 = F_86 ( V_100 , V_56 ) ;
if ( V_14 != 0 ) {
F_51 ( V_45 -> V_25 ,
L_32 , V_14 ) ;
goto V_154;
}
}
if ( V_45 -> V_155 ) {
V_14 = V_45 -> V_155 ( V_45 ) ;
if ( V_14 < 0 ) {
F_51 ( V_45 -> V_25 ,
L_33 , V_14 ) ;
goto V_154;
}
F_87 ( V_100 -> V_107 &&
V_100 -> V_102 != V_108 ,
L_34 ,
V_45 -> V_47 ) ;
}
if ( V_45 -> V_156 )
F_88 ( V_45 , V_45 -> V_156 ,
V_45 -> V_157 ) ;
if ( V_45 -> V_158 )
F_89 ( V_100 , V_45 -> V_158 ,
V_45 -> V_159 ) ;
V_45 -> V_134 = 1 ;
F_90 ( & V_100 -> V_160 , & V_49 -> V_161 ) ;
if ( V_45 -> V_5 )
F_90 ( & V_45 -> V_5 -> V_135 , & V_49 -> V_162 ) ;
return 0 ;
V_154:
F_28 ( V_45 ) ;
F_76 ( V_45 -> V_25 -> V_10 -> V_136 ) ;
return V_14 ;
}
static void F_91 ( struct V_24 * V_25 )
{
F_15 ( V_25 ) ;
}
static int F_92 ( struct V_28 * V_29 ,
const char * V_47 )
{
int V_14 = 0 ;
V_29 -> V_25 = F_93 ( sizeof( struct V_24 ) , V_36 ) ;
if ( ! V_29 -> V_25 )
return - V_37 ;
F_94 ( V_29 -> V_25 ) ;
V_29 -> V_25 -> V_75 = V_29 -> V_49 -> V_25 ;
V_29 -> V_25 -> V_76 = F_91 ;
F_49 ( V_29 -> V_25 , L_35 , V_47 ) ;
F_95 ( V_29 -> V_25 , V_29 ) ;
F_96 ( & V_29 -> V_163 ) ;
F_97 ( & V_29 -> V_164 [ V_103 ] . V_165 ) ;
F_97 ( & V_29 -> V_164 [ V_105 ] . V_165 ) ;
F_97 ( & V_29 -> V_164 [ V_103 ] . V_166 ) ;
F_97 ( & V_29 -> V_164 [ V_105 ] . V_166 ) ;
V_14 = F_98 ( V_29 -> V_25 ) ;
if ( V_14 < 0 ) {
F_99 ( V_29 -> V_25 ) ;
F_51 ( V_29 -> V_49 -> V_25 ,
L_36 , V_14 ) ;
return V_14 ;
}
V_29 -> V_139 = 1 ;
if ( V_29 -> V_5 ) {
V_14 = F_100 ( V_29 -> V_25 ) ;
if ( V_14 < 0 )
F_51 ( V_29 -> V_25 ,
L_37 ,
V_14 ) ;
V_14 = F_101 ( V_29 -> V_25 , & V_141 ) ;
if ( V_14 < 0 )
F_51 ( V_29 -> V_25 ,
L_38 ,
V_14 ) ;
}
return 0 ;
}
static int F_102 ( struct V_59 * V_49 , int V_124 ,
int V_137 )
{
struct V_28 * V_29 = & V_49 -> V_29 [ V_124 ] ;
struct V_57 * V_58 = V_29 -> V_58 ;
struct V_44 * V_45 ;
int V_3 , V_14 ;
V_45 = V_29 -> V_95 -> V_45 ;
if ( V_45 -> V_10 -> V_167 == V_137 ) {
V_14 = F_83 ( V_49 , V_45 ) ;
if ( V_14 < 0 )
return V_14 ;
}
for ( V_3 = 0 ; V_3 < V_29 -> V_87 ; V_3 ++ ) {
V_45 = V_29 -> V_88 [ V_3 ] -> V_45 ;
if ( V_45 -> V_10 -> V_167 == V_137 ) {
V_14 = F_83 ( V_49 , V_45 ) ;
if ( V_14 < 0 )
return V_14 ;
}
}
if ( V_58 -> V_45 . V_10 -> V_167 == V_137 ) {
V_14 = F_83 ( V_49 , & V_58 -> V_45 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
static int F_103 ( struct V_59 * V_49 ,
struct V_55 * V_118 ,
int V_137 )
{
int V_14 ;
if ( ! V_118 -> V_134 && V_118 -> V_10 -> V_167 == V_137 ) {
if ( V_118 -> V_10 -> V_155 ) {
V_14 = V_118 -> V_10 -> V_155 ( V_118 ) ;
if ( V_14 < 0 ) {
F_51 ( V_118 -> V_25 ,
L_39 ,
V_118 -> V_47 , V_14 ) ;
return V_14 ;
}
}
V_118 -> V_134 = 1 ;
}
return 0 ;
}
static int F_104 ( struct V_59 * V_49 ,
struct V_125 * V_64 ,
struct V_28 * V_29 )
{
struct V_55 * V_95 = V_29 -> V_95 ;
struct V_55 * V_118 = V_29 -> V_118 ;
struct V_168 * V_169 , * V_170 ;
int V_14 ;
if ( V_29 -> V_87 > 1 )
F_25 ( V_49 -> V_25 , L_40 ) ;
V_169 = V_118 -> V_171 ;
V_170 = V_95 -> V_172 ;
if ( V_169 && V_170 ) {
V_14 = F_105 ( V_49 , V_64 -> V_173 ,
V_170 , V_169 ) ;
if ( V_14 != 0 ) {
F_51 ( V_49 -> V_25 , L_41 ,
V_169 -> V_47 , V_170 -> V_47 , V_14 ) ;
return V_14 ;
}
}
V_169 = V_95 -> V_171 ;
V_170 = V_118 -> V_172 ;
if ( V_169 && V_170 ) {
V_14 = F_105 ( V_49 , V_64 -> V_173 ,
V_170 , V_169 ) ;
if ( V_14 != 0 ) {
F_51 ( V_49 -> V_25 , L_41 ,
V_169 -> V_47 , V_170 -> V_47 , V_14 ) ;
return V_14 ;
}
}
return 0 ;
}
static int F_106 ( struct V_59 * V_49 , int V_124 , int V_137 )
{
struct V_125 * V_64 = & V_49 -> V_64 [ V_124 ] ;
struct V_28 * V_29 = & V_49 -> V_29 [ V_124 ] ;
struct V_57 * V_58 = V_29 -> V_58 ;
struct V_55 * V_95 = V_29 -> V_95 ;
int V_3 , V_14 ;
F_43 ( V_49 -> V_25 , L_42 ,
V_49 -> V_47 , V_124 , V_137 ) ;
V_95 -> V_58 = V_58 ;
V_95 -> V_49 = V_49 ;
for ( V_3 = 0 ; V_3 < V_29 -> V_87 ; V_3 ++ )
V_29 -> V_88 [ V_3 ] -> V_49 = V_49 ;
V_29 -> V_31 = V_31 ;
if ( ! V_95 -> V_134 &&
V_95 -> V_10 -> V_167 == V_137 ) {
if ( V_95 -> V_10 -> V_155 ) {
V_14 = V_95 -> V_10 -> V_155 ( V_95 ) ;
if ( V_14 < 0 ) {
F_51 ( V_95 -> V_25 ,
L_43 ,
V_95 -> V_47 , V_14 ) ;
return V_14 ;
}
}
V_95 -> V_134 = 1 ;
}
for ( V_3 = 0 ; V_3 < V_29 -> V_87 ; V_3 ++ ) {
V_14 = F_103 ( V_49 , V_29 -> V_88 [ V_3 ] , V_137 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_137 != V_143 )
return 0 ;
if ( V_64 -> V_174 ) {
V_14 = V_64 -> V_174 ( V_29 ) ;
if ( V_14 < 0 ) {
F_51 ( V_49 -> V_25 , L_44 ,
V_64 -> V_47 , V_14 ) ;
return V_14 ;
}
}
V_14 = F_92 ( V_29 , V_64 -> V_47 ) ;
if ( V_14 )
return V_14 ;
#ifdef F_107
if ( V_64 -> V_175 ) {
V_14 = F_108 ( V_29 ) ;
if ( V_14 < 0 ) {
F_51 ( V_29 -> V_25 ,
L_45 ,
V_14 ) ;
return V_14 ;
}
}
#endif
V_14 = F_101 ( V_29 -> V_25 , & V_140 ) ;
if ( V_14 < 0 )
F_25 ( V_29 -> V_25 , L_46 ,
V_14 ) ;
if ( V_95 -> V_10 -> V_176 ) {
V_14 = F_109 ( V_29 , V_124 ) ;
if ( V_14 < 0 ) {
F_51 ( V_49 -> V_25 , L_47 ,
V_64 -> V_177 ) ;
return V_14 ;
}
} else {
if ( ! V_64 -> V_173 ) {
V_14 = F_110 ( V_29 , V_124 ) ;
if ( V_14 < 0 ) {
F_51 ( V_49 -> V_25 , L_48 ,
V_64 -> V_177 , V_14 ) ;
return V_14 ;
}
} else {
F_111 ( & V_29 -> V_99 ,
F_52 ) ;
V_14 = F_104 ( V_49 , V_64 , V_29 ) ;
if ( V_14 )
return V_14 ;
}
}
for ( V_3 = 0 ; V_3 < V_29 -> V_87 ; V_3 ++ ) {
if ( V_29 -> V_88 [ V_3 ] -> V_10 -> V_97 )
F_112 ( V_29 -> V_88 [ V_3 ] -> V_5 -> V_71 ,
V_29 -> V_95 -> V_178 ) ;
}
return 0 ;
}
static int F_113 ( struct V_4 * V_5 ,
struct V_55 * V_118 )
{
int V_14 ;
if ( V_118 -> V_10 -> V_97 && ! V_5 -> V_179 ) {
if ( ! V_5 -> V_180 )
return 0 ;
V_14 = F_48 ( V_5 ) ;
if ( V_14 < 0 ) {
F_51 ( V_5 -> V_25 ,
L_49 , V_14 ) ;
return V_14 ;
}
V_5 -> V_179 = 1 ;
}
return 0 ;
}
static void F_114 ( struct V_4 * V_5 )
{
if ( V_5 -> V_179 ) {
F_45 ( V_5 ) ;
V_5 -> V_179 = 0 ;
}
}
static int F_115 ( struct V_28 * V_29 )
{
int V_3 , V_14 ;
for ( V_3 = 0 ; V_3 < V_29 -> V_87 ; V_3 ++ ) {
struct V_55 * V_118 = V_29 -> V_88 [ V_3 ] ;
V_14 = F_113 ( V_118 -> V_5 , V_118 ) ;
if ( V_14 ) {
while ( -- V_3 >= 0 )
F_114 ( V_118 -> V_5 ) ;
return V_14 ;
}
}
return 0 ;
}
static void F_116 ( struct V_28 * V_29 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_29 -> V_87 ; V_3 ++ )
F_114 ( V_29 -> V_88 [ V_3 ] -> V_5 ) ;
}
static int F_117 ( struct V_59 * V_49 , int V_124 )
{
struct V_28 * V_29 = & V_49 -> V_181 [ V_124 ] ;
struct V_182 * V_183 = & V_49 -> V_183 [ V_124 ] ;
const char * V_47 = V_183 -> V_184 ;
V_29 -> V_45 = F_70 ( V_183 -> V_185 , V_47 ) ;
if ( ! V_29 -> V_45 ) {
if ( V_183 -> V_185 )
V_47 = F_118 ( V_183 -> V_185 ) ;
F_51 ( V_49 -> V_25 , L_50 , V_47 ) ;
return - V_132 ;
}
V_29 -> V_5 = V_29 -> V_45 -> V_5 ;
return 0 ;
}
static int F_119 ( struct V_59 * V_49 , int V_124 )
{
struct V_28 * V_29 = & V_49 -> V_181 [ V_124 ] ;
struct V_182 * V_183 = & V_49 -> V_183 [ V_124 ] ;
int V_14 ;
V_14 = F_83 ( V_49 , V_29 -> V_45 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_183 -> V_174 ) {
V_14 = V_183 -> V_174 ( V_29 -> V_45 ) ;
if ( V_14 < 0 ) {
F_51 ( V_49 -> V_25 , L_44 ,
V_183 -> V_47 , V_14 ) ;
return V_14 ;
}
}
return F_92 ( V_29 , V_183 -> V_47 ) ;
}
static void F_120 ( struct V_59 * V_49 , int V_124 )
{
struct V_28 * V_29 = & V_49 -> V_181 [ V_124 ] ;
struct V_44 * V_45 = V_29 -> V_45 ;
if ( V_29 -> V_139 ) {
F_79 ( V_29 -> V_25 , & V_141 ) ;
F_46 ( V_29 -> V_25 ) ;
V_29 -> V_139 = 0 ;
}
if ( V_45 && V_45 -> V_134 )
F_73 ( V_45 ) ;
}
static int F_121 ( struct V_4 * V_5 )
{
int V_14 ;
if ( V_5 -> V_186 )
return 0 ;
V_14 = F_122 ( V_5 ) ;
if ( V_14 < 0 ) {
F_51 ( V_5 -> V_25 ,
L_51 ,
V_14 ) ;
return V_14 ;
}
V_5 -> V_186 = 1 ;
return 0 ;
}
static int F_123 ( struct V_59 * V_49 )
{
struct V_4 * V_5 ;
struct V_125 * V_64 ;
int V_14 , V_3 , V_137 , V_187 ;
F_124 ( & V_49 -> V_188 , V_189 ) ;
for ( V_3 = 0 ; V_3 < V_49 -> V_66 ; V_3 ++ ) {
V_14 = F_72 ( V_49 , V_3 ) ;
if ( V_14 != 0 )
goto V_190;
}
for ( V_3 = 0 ; V_3 < V_49 -> V_191 ; V_3 ++ ) {
V_14 = F_117 ( V_49 , V_3 ) ;
if ( V_14 != 0 )
goto V_190;
}
F_35 (codec, &codec_list, list) {
if ( V_5 -> V_186 )
continue;
V_14 = F_121 ( V_5 ) ;
if ( V_14 < 0 )
goto V_190;
}
V_14 = F_125 ( V_49 -> V_25 , V_192 , V_193 ,
V_49 -> V_136 , 0 , & V_49 -> V_77 ) ;
if ( V_14 < 0 ) {
F_51 ( V_49 -> V_25 ,
L_52 ,
V_49 -> V_47 , V_14 ) ;
goto V_190;
}
V_49 -> V_100 . V_102 = V_108 ;
V_49 -> V_100 . V_25 = V_49 -> V_25 ;
V_49 -> V_100 . V_49 = V_49 ;
F_90 ( & V_49 -> V_100 . V_160 , & V_49 -> V_161 ) ;
#ifdef F_107
F_26 ( & V_49 -> V_100 , V_49 -> V_50 ) ;
#endif
#ifdef F_126
F_127 ( & V_49 -> V_111 , F_65 ) ;
#endif
if ( V_49 -> V_152 )
F_85 ( & V_49 -> V_100 , V_49 -> V_152 ,
V_49 -> V_153 ) ;
if ( V_49 -> V_155 ) {
V_14 = V_49 -> V_155 ( V_49 ) ;
if ( V_14 < 0 )
goto V_194;
}
for ( V_137 = V_142 ; V_137 <= V_143 ;
V_137 ++ ) {
for ( V_3 = 0 ; V_3 < V_49 -> V_66 ; V_3 ++ ) {
V_14 = F_102 ( V_49 , V_3 , V_137 ) ;
if ( V_14 < 0 ) {
F_51 ( V_49 -> V_25 ,
L_53 ,
V_14 ) ;
goto V_195;
}
}
}
for ( V_137 = V_142 ; V_137 <= V_143 ;
V_137 ++ ) {
for ( V_3 = 0 ; V_3 < V_49 -> V_66 ; V_3 ++ ) {
V_14 = F_106 ( V_49 , V_3 , V_137 ) ;
if ( V_14 < 0 ) {
F_51 ( V_49 -> V_25 ,
L_53 ,
V_14 ) ;
goto V_195;
}
}
}
for ( V_3 = 0 ; V_3 < V_49 -> V_191 ; V_3 ++ ) {
V_14 = F_119 ( V_49 , V_3 ) ;
if ( V_14 < 0 ) {
F_51 ( V_49 -> V_25 ,
L_54 ,
V_14 ) ;
goto V_196;
}
}
F_128 ( V_49 ) ;
F_129 ( V_49 ) ;
if ( V_49 -> V_156 )
F_130 ( V_49 , V_49 -> V_156 , V_49 -> V_157 ) ;
if ( V_49 -> V_158 )
F_89 ( & V_49 -> V_100 , V_49 -> V_158 ,
V_49 -> V_159 ) ;
for ( V_3 = 0 ; V_3 < V_49 -> V_66 ; V_3 ++ ) {
struct V_28 * V_29 = & V_49 -> V_29 [ V_3 ] ;
V_64 = & V_49 -> V_64 [ V_3 ] ;
V_187 = V_64 -> V_187 ;
if ( V_187 ) {
struct V_55 * * V_88 = V_29 -> V_88 ;
int V_81 ;
for ( V_81 = 0 ; V_81 < V_29 -> V_87 ; V_81 ++ ) {
struct V_55 * V_118 = V_88 [ V_81 ] ;
V_14 = F_131 ( V_118 , V_187 ) ;
if ( V_14 != 0 && V_14 != - V_197 )
F_25 ( V_118 -> V_25 ,
L_55 ,
V_14 ) ;
}
}
if ( V_187 &&
( V_64 -> V_128 || V_64 -> V_133 ) ) {
V_14 = F_131 ( V_49 -> V_29 [ V_3 ] . V_95 ,
V_187 ) ;
if ( V_14 != 0 && V_14 != - V_197 )
F_25 ( V_49 -> V_29 [ V_3 ] . V_95 -> V_25 ,
L_55 ,
V_14 ) ;
} else if ( V_187 ) {
V_187 &= ~ V_198 ;
switch ( V_64 -> V_187 &
V_198 ) {
case V_199 :
V_187 |= V_200 ;
break;
case V_201 :
V_187 |= V_202 ;
break;
case V_202 :
V_187 |= V_201 ;
break;
case V_200 :
V_187 |= V_199 ;
break;
}
V_14 = F_131 ( V_49 -> V_29 [ V_3 ] . V_95 ,
V_187 ) ;
if ( V_14 != 0 && V_14 != - V_197 )
F_25 ( V_49 -> V_29 [ V_3 ] . V_95 -> V_25 ,
L_55 ,
V_14 ) ;
}
}
snprintf ( V_49 -> V_77 -> V_203 , sizeof( V_49 -> V_77 -> V_203 ) ,
L_35 , V_49 -> V_47 ) ;
snprintf ( V_49 -> V_77 -> V_204 , sizeof( V_49 -> V_77 -> V_204 ) ,
L_35 , V_49 -> V_205 ? V_49 -> V_205 : V_49 -> V_47 ) ;
snprintf ( V_49 -> V_77 -> V_10 , sizeof( V_49 -> V_77 -> V_10 ) ,
L_35 , V_49 -> V_206 ? V_49 -> V_206 : V_49 -> V_47 ) ;
for ( V_3 = 0 ; V_3 < F_132 ( V_49 -> V_77 -> V_10 ) ; V_3 ++ ) {
switch ( V_49 -> V_77 -> V_10 [ V_3 ] ) {
case '_' :
case '-' :
case '\0' :
break;
default:
if ( ! isalnum ( V_49 -> V_77 -> V_10 [ V_3 ] ) )
V_49 -> V_77 -> V_10 [ V_3 ] = '_' ;
break;
}
}
if ( V_49 -> V_207 ) {
V_14 = V_49 -> V_207 ( V_49 ) ;
if ( V_14 < 0 ) {
F_51 ( V_49 -> V_25 , L_56 ,
V_49 -> V_47 , V_14 ) ;
goto V_196;
}
}
if ( V_49 -> V_208 )
F_133 ( V_49 ) ;
F_134 ( V_49 ) ;
V_14 = F_135 ( V_49 -> V_77 ) ;
if ( V_14 < 0 ) {
F_51 ( V_49 -> V_25 , L_57 ,
V_14 ) ;
goto V_196;
}
#ifdef F_136
for ( V_3 = 0 ; V_3 < V_49 -> V_85 ; V_3 ++ ) {
V_14 = F_115 ( & V_49 -> V_29 [ V_3 ] ) ;
if ( V_14 < 0 ) {
F_51 ( V_49 -> V_25 ,
L_58 , V_14 ) ;
while ( -- V_3 >= 0 )
F_116 ( & V_49 -> V_29 [ V_3 ] ) ;
goto V_196;
}
}
#endif
V_49 -> V_82 = 1 ;
F_62 ( & V_49 -> V_100 ) ;
F_137 ( & V_49 -> V_188 ) ;
return 0 ;
V_196:
for ( V_3 = 0 ; V_3 < V_49 -> V_191 ; V_3 ++ )
F_120 ( V_49 , V_3 ) ;
V_195:
F_81 ( V_49 ) ;
V_194:
if ( V_49 -> remove )
V_49 -> remove ( V_49 ) ;
F_138 ( V_49 -> V_77 ) ;
V_190:
F_137 ( & V_49 -> V_188 ) ;
return V_14 ;
}
static int F_139 ( struct V_209 * V_210 )
{
struct V_59 * V_49 = F_140 ( V_210 ) ;
if ( ! V_49 )
return - V_17 ;
F_25 ( & V_210 -> V_25 ,
L_59 ,
V_49 -> V_47 ) ;
V_49 -> V_25 = & V_210 -> V_25 ;
return F_141 ( V_49 ) ;
}
static int F_142 ( struct V_59 * V_49 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_49 -> V_85 ; V_3 ++ ) {
struct V_28 * V_29 = & V_49 -> V_29 [ V_3 ] ;
F_59 ( & V_29 -> V_99 ) ;
}
for ( V_3 = 0 ; V_3 < V_49 -> V_191 ; V_3 ++ )
F_120 ( V_49 , V_3 ) ;
F_81 ( V_49 ) ;
F_41 ( V_49 ) ;
if ( V_49 -> remove )
V_49 -> remove ( V_49 ) ;
F_75 ( & V_49 -> V_100 ) ;
F_138 ( V_49 -> V_77 ) ;
return 0 ;
}
static int F_143 ( struct V_209 * V_210 )
{
struct V_59 * V_49 = F_140 ( V_210 ) ;
F_144 ( V_49 ) ;
return 0 ;
}
int F_145 ( struct V_24 * V_25 )
{
struct V_59 * V_49 = F_8 ( V_25 ) ;
int V_3 ;
if ( ! V_49 -> V_82 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_49 -> V_85 ; V_3 ++ ) {
struct V_28 * V_29 = & V_49 -> V_29 [ V_3 ] ;
F_59 ( & V_29 -> V_99 ) ;
}
F_146 ( V_49 ) ;
for ( V_3 = 0 ; V_3 < V_49 -> V_85 ; V_3 ++ ) {
struct V_28 * V_29 = & V_49 -> V_29 [ V_3 ] ;
struct V_55 * V_95 = V_29 -> V_95 ;
int V_81 ;
F_64 ( V_95 -> V_25 ) ;
for ( V_81 = 0 ; V_81 < V_29 -> V_87 ; V_81 ++ ) {
struct V_55 * V_118 = V_29 -> V_88 [ V_81 ] ;
F_64 ( V_118 -> V_25 ) ;
}
}
return 0 ;
}
int F_147 ( struct V_4 * V_5 ,
struct V_211 * V_91 , int V_124 )
{
V_5 -> V_71 = F_93 ( sizeof( struct V_212 ) , V_36 ) ;
if ( V_5 -> V_71 == NULL )
return - V_37 ;
V_5 -> V_71 -> V_72 = F_93 ( sizeof( struct V_213 ) , V_36 ) ;
if ( V_5 -> V_71 -> V_72 == NULL ) {
F_15 ( V_5 -> V_71 ) ;
V_5 -> V_71 = NULL ;
return - V_37 ;
}
V_5 -> V_71 -> V_72 -> V_91 = V_91 ;
V_5 -> V_71 -> V_124 = V_124 ;
V_5 -> V_180 = 1 ;
return 0 ;
}
static void F_148 ( struct V_212 * V_71 )
{
struct V_214 * V_215 = V_216 . V_215 ;
F_149 ( V_215 , V_216 . V_217 ) ;
F_150 ( V_216 . V_218 , 1 ) ;
F_151 ( 10 ) ;
F_150 ( V_216 . V_218 , 0 ) ;
F_149 ( V_215 , V_216 . V_219 ) ;
F_152 ( 2 ) ;
}
static void F_153 ( struct V_212 * V_71 )
{
struct V_214 * V_215 = V_216 . V_215 ;
F_149 ( V_215 , V_216 . V_220 ) ;
F_150 ( V_216 . V_218 , 0 ) ;
F_150 ( V_216 . V_221 , 0 ) ;
F_150 ( V_216 . V_222 , 0 ) ;
F_151 ( 10 ) ;
F_150 ( V_216 . V_222 , 1 ) ;
F_149 ( V_215 , V_216 . V_219 ) ;
F_152 ( 2 ) ;
}
static int F_154 ( struct V_24 * V_25 ,
struct V_223 * V_224 )
{
struct V_214 * V_22 ;
struct V_225 * V_226 ;
int V_227 ;
int V_14 ;
V_22 = F_155 ( V_25 ) ;
if ( F_156 ( V_22 ) ) {
F_51 ( V_25 , L_60 ) ;
return F_157 ( V_22 ) ;
}
V_224 -> V_215 = V_22 ;
V_226 = F_158 ( V_22 , L_61 ) ;
if ( F_156 ( V_226 ) ) {
F_51 ( V_25 , L_62 ) ;
return F_157 ( V_226 ) ;
}
V_224 -> V_220 = V_226 ;
V_226 = F_158 ( V_22 , L_63 ) ;
if ( F_156 ( V_226 ) ) {
F_51 ( V_25 , L_64 ) ;
return F_157 ( V_226 ) ;
}
V_224 -> V_217 = V_226 ;
V_226 = F_158 ( V_22 , L_65 ) ;
if ( F_156 ( V_226 ) ) {
F_51 ( V_25 , L_66 ) ;
return F_157 ( V_226 ) ;
}
V_224 -> V_219 = V_226 ;
V_227 = F_159 ( V_25 -> V_120 , L_67 , 0 ) ;
if ( V_227 < 0 ) {
F_51 ( V_25 , L_68 ) ;
return V_227 ;
}
V_14 = F_160 ( V_25 , V_227 , L_69 ) ;
if ( V_14 ) {
F_51 ( V_25 , L_70 ) ;
return V_14 ;
}
V_224 -> V_218 = V_227 ;
V_227 = F_159 ( V_25 -> V_120 , L_67 , 1 ) ;
if ( V_227 < 0 ) {
F_51 ( V_25 , L_71 , V_227 ) ;
return V_227 ;
}
V_14 = F_160 ( V_25 , V_227 , L_72 ) ;
if ( V_14 ) {
F_51 ( V_25 , L_73 ) ;
return V_14 ;
}
V_224 -> V_221 = V_227 ;
V_227 = F_159 ( V_25 -> V_120 , L_67 , 2 ) ;
if ( V_227 < 0 ) {
F_51 ( V_25 , L_74 ) ;
return V_227 ;
}
V_14 = F_160 ( V_25 , V_227 , L_75 ) ;
if ( V_14 ) {
F_51 ( V_25 , L_76 ) ;
return V_14 ;
}
V_224 -> V_222 = V_227 ;
return 0 ;
}
int F_161 ( struct V_211 * V_91 )
{
if ( V_91 == V_228 )
return 0 ;
if ( V_228 && V_91 )
return - V_229 ;
V_228 = V_91 ;
return 0 ;
}
int F_162 ( struct V_211 * V_91 ,
struct V_209 * V_210 )
{
struct V_24 * V_25 = & V_210 -> V_25 ;
struct V_223 V_224 ;
int V_14 ;
V_14 = F_154 ( V_25 , & V_224 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_161 ( V_91 ) ;
if ( V_14 )
return V_14 ;
V_91 -> V_230 = F_148 ;
V_91 -> V_231 = F_153 ;
V_216 = V_224 ;
return 0 ;
}
void F_163 ( struct V_4 * V_5 )
{
#ifdef F_136
F_114 ( V_5 ) ;
#endif
F_15 ( V_5 -> V_71 -> V_72 ) ;
F_15 ( V_5 -> V_71 ) ;
V_5 -> V_71 = NULL ;
V_5 -> V_180 = 0 ;
}
struct V_232 * F_164 ( const struct V_233 * V_234 ,
void * V_235 , const char * V_205 ,
const char * V_236 )
{
struct V_233 V_237 ;
struct V_232 * V_238 ;
char * V_47 = NULL ;
memcpy ( & V_237 , V_234 , sizeof( V_237 ) ) ;
V_237 . V_239 = 0 ;
if ( ! V_205 )
V_205 = V_237 . V_47 ;
if ( V_236 ) {
V_47 = F_23 ( V_36 , L_77 , V_236 , V_205 ) ;
if ( ! V_47 )
return NULL ;
V_237 . V_47 = V_47 ;
} else {
V_237 . V_47 = V_205 ;
}
V_238 = F_165 ( & V_237 , V_235 ) ;
F_15 ( V_47 ) ;
return V_238 ;
}
static int F_166 ( struct V_77 * V_49 , struct V_24 * V_25 ,
const struct V_233 * V_156 , int V_157 ,
const char * V_236 , void * V_235 )
{
int V_73 , V_3 ;
for ( V_3 = 0 ; V_3 < V_157 ; V_3 ++ ) {
const struct V_233 * V_240 = & V_156 [ V_3 ] ;
V_73 = F_167 ( V_49 , F_164 ( V_240 , V_235 ,
V_240 -> V_47 , V_236 ) ) ;
if ( V_73 < 0 ) {
F_51 ( V_25 , L_78 ,
V_240 -> V_47 , V_73 ) ;
return V_73 ;
}
}
return 0 ;
}
struct V_232 * F_168 ( struct V_59 * V_241 ,
const char * V_47 )
{
struct V_77 * V_49 = V_241 -> V_77 ;
struct V_232 * V_242 ;
if ( F_169 ( ! V_47 ) )
return NULL ;
F_35 (kctl, &card->controls, list)
if ( ! strncmp ( V_242 -> V_243 . V_47 , V_47 , sizeof( V_242 -> V_243 . V_47 ) ) )
return V_242 ;
return NULL ;
}
int F_88 ( struct V_44 * V_45 ,
const struct V_233 * V_156 , unsigned int V_157 )
{
struct V_77 * V_49 = V_45 -> V_49 -> V_77 ;
return F_166 ( V_49 , V_45 -> V_25 , V_156 ,
V_157 , V_45 -> V_149 , V_45 ) ;
}
int F_170 ( struct V_4 * V_5 ,
const struct V_233 * V_156 , unsigned int V_157 )
{
return F_88 ( & V_5 -> V_45 , V_156 ,
V_157 ) ;
}
int F_171 ( struct V_57 * V_58 ,
const struct V_233 * V_156 , unsigned int V_157 )
{
return F_88 ( & V_58 -> V_45 , V_156 ,
V_157 ) ;
}
int F_130 ( struct V_59 * V_241 ,
const struct V_233 * V_156 , int V_157 )
{
struct V_77 * V_49 = V_241 -> V_77 ;
return F_166 ( V_49 , V_241 -> V_25 , V_156 , V_157 ,
NULL , V_241 ) ;
}
int F_172 ( struct V_55 * V_56 ,
const struct V_233 * V_156 , int V_157 )
{
struct V_77 * V_49 = V_56 -> V_49 -> V_77 ;
return F_166 ( V_49 , V_56 -> V_25 , V_156 , V_157 ,
NULL , V_56 ) ;
}
int F_173 ( struct V_232 * V_238 ,
struct V_244 * V_245 )
{
struct V_246 * V_247 = (struct V_246 * ) V_238 -> V_248 ;
V_245 -> type = V_249 ;
V_245 -> V_18 = V_247 -> V_250 == V_247 -> V_251 ? 1 : 2 ;
V_245 -> V_41 . V_252 . V_253 = V_247 -> V_253 ;
if ( V_245 -> V_41 . V_252 . V_254 >= V_247 -> V_253 )
V_245 -> V_41 . V_252 . V_254 = V_247 -> V_253 - 1 ;
F_174 ( V_245 -> V_41 . V_252 . V_47 ,
V_247 -> V_255 [ V_245 -> V_41 . V_252 . V_254 ] ,
sizeof( V_245 -> V_41 . V_252 . V_47 ) ) ;
return 0 ;
}
int F_175 ( struct V_232 * V_238 ,
struct V_256 * V_257 )
{
struct V_44 * V_45 = F_176 ( V_238 ) ;
struct V_246 * V_247 = (struct V_246 * ) V_238 -> V_248 ;
unsigned int V_1 , V_254 ;
unsigned int V_258 ;
int V_14 ;
V_14 = F_177 ( V_45 , V_247 -> V_6 , & V_258 ) ;
if ( V_14 )
return V_14 ;
V_1 = ( V_258 >> V_247 -> V_250 ) & V_247 -> V_259 ;
V_254 = F_178 ( V_247 , V_1 ) ;
V_257 -> V_41 . V_252 . V_254 [ 0 ] = V_254 ;
if ( V_247 -> V_250 != V_247 -> V_251 ) {
V_1 = ( V_258 >> V_247 -> V_250 ) & V_247 -> V_259 ;
V_254 = F_178 ( V_247 , V_1 ) ;
V_257 -> V_41 . V_252 . V_254 [ 1 ] = V_254 ;
}
return 0 ;
}
int F_179 ( struct V_232 * V_238 ,
struct V_256 * V_257 )
{
struct V_44 * V_45 = F_176 ( V_238 ) ;
struct V_246 * V_247 = (struct V_246 * ) V_238 -> V_248 ;
unsigned int * V_254 = V_257 -> V_41 . V_252 . V_254 ;
unsigned int V_1 ;
unsigned int V_259 ;
if ( V_254 [ 0 ] >= V_247 -> V_253 )
return - V_17 ;
V_1 = F_180 ( V_247 , V_254 [ 0 ] ) << V_247 -> V_250 ;
V_259 = V_247 -> V_259 << V_247 -> V_250 ;
if ( V_247 -> V_250 != V_247 -> V_251 ) {
if ( V_254 [ 1 ] >= V_247 -> V_253 )
return - V_17 ;
V_1 |= F_180 ( V_247 , V_254 [ 1 ] ) << V_247 -> V_251 ;
V_259 |= V_247 -> V_259 << V_247 -> V_251 ;
}
return F_181 ( V_45 , V_247 -> V_6 , V_259 , V_1 ) ;
}
static int F_182 ( struct V_44 * V_45 ,
unsigned int V_6 , unsigned int V_259 , unsigned int V_260 ,
unsigned int V_261 , int * V_262 )
{
int V_14 ;
unsigned int V_1 ;
V_14 = F_177 ( V_45 , V_6 , & V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
V_1 = ( V_1 >> V_260 ) & V_259 ;
if ( ! V_261 ) {
* V_262 = V_1 ;
return 0 ;
}
if ( ! ( V_1 & F_183 ( V_261 ) ) ) {
* V_262 = V_1 ;
return 0 ;
}
V_14 = V_1 ;
V_14 |= ~ ( ( int ) ( F_183 ( V_261 ) - 1 ) ) ;
* V_262 = V_14 ;
return 0 ;
}
int F_184 ( struct V_232 * V_238 ,
struct V_244 * V_245 )
{
struct V_263 * V_264 =
(struct V_263 * ) V_238 -> V_248 ;
int V_265 ;
if ( ! V_264 -> V_265 )
V_264 -> V_265 = V_264 -> V_266 ;
V_265 = V_264 -> V_265 ;
if ( V_265 == 1 && ! strstr ( V_238 -> V_243 . V_47 , L_79 ) )
V_245 -> type = V_267 ;
else
V_245 -> type = V_268 ;
V_245 -> V_18 = F_185 ( V_264 ) ? 2 : 1 ;
V_245 -> V_41 . integer . F_6 = 0 ;
V_245 -> V_41 . integer . V_266 = V_265 - V_264 -> F_6 ;
return 0 ;
}
int F_186 ( struct V_232 * V_238 ,
struct V_256 * V_257 )
{
struct V_44 * V_45 = F_176 ( V_238 ) ;
struct V_263 * V_264 =
(struct V_263 * ) V_238 -> V_248 ;
unsigned int V_6 = V_264 -> V_6 ;
unsigned int V_269 = V_264 -> V_270 ;
unsigned int V_260 = V_264 -> V_260 ;
unsigned int V_271 = V_264 -> V_271 ;
int V_266 = V_264 -> V_266 ;
int F_6 = V_264 -> F_6 ;
int V_261 = V_264 -> V_261 ;
unsigned int V_259 = ( 1 << F_187 ( V_266 ) ) - 1 ;
unsigned int V_272 = V_264 -> V_272 ;
int V_1 ;
int V_14 ;
if ( V_261 )
V_259 = F_183 ( V_261 + 1 ) - 1 ;
V_14 = F_182 ( V_45 , V_6 , V_259 , V_260 , V_261 , & V_1 ) ;
if ( V_14 )
return V_14 ;
V_257 -> V_41 . integer . V_41 [ 0 ] = V_1 - F_6 ;
if ( V_272 )
V_257 -> V_41 . integer . V_41 [ 0 ] =
V_266 - V_257 -> V_41 . integer . V_41 [ 0 ] ;
if ( F_185 ( V_264 ) ) {
if ( V_6 == V_269 )
V_14 = F_182 ( V_45 , V_6 , V_259 , V_271 ,
V_261 , & V_1 ) ;
else
V_14 = F_182 ( V_45 , V_269 , V_259 , V_260 ,
V_261 , & V_1 ) ;
if ( V_14 )
return V_14 ;
V_257 -> V_41 . integer . V_41 [ 1 ] = V_1 - F_6 ;
if ( V_272 )
V_257 -> V_41 . integer . V_41 [ 1 ] =
V_266 - V_257 -> V_41 . integer . V_41 [ 1 ] ;
}
return 0 ;
}
int F_188 ( struct V_232 * V_238 ,
struct V_256 * V_257 )
{
struct V_44 * V_45 = F_176 ( V_238 ) ;
struct V_263 * V_264 =
(struct V_263 * ) V_238 -> V_248 ;
unsigned int V_6 = V_264 -> V_6 ;
unsigned int V_269 = V_264 -> V_270 ;
unsigned int V_260 = V_264 -> V_260 ;
unsigned int V_271 = V_264 -> V_271 ;
int V_266 = V_264 -> V_266 ;
int F_6 = V_264 -> F_6 ;
unsigned int V_261 = V_264 -> V_261 ;
unsigned int V_259 = ( 1 << F_187 ( V_266 ) ) - 1 ;
unsigned int V_272 = V_264 -> V_272 ;
int V_73 ;
bool V_273 = false ;
unsigned int V_274 = 0 ;
unsigned int V_1 , V_275 ;
if ( V_261 )
V_259 = F_183 ( V_261 + 1 ) - 1 ;
V_1 = ( ( V_257 -> V_41 . integer . V_41 [ 0 ] + F_6 ) & V_259 ) ;
if ( V_272 )
V_1 = V_266 - V_1 ;
V_275 = V_259 << V_260 ;
V_1 = V_1 << V_260 ;
if ( F_185 ( V_264 ) ) {
V_274 = ( ( V_257 -> V_41 . integer . V_41 [ 1 ] + F_6 ) & V_259 ) ;
if ( V_272 )
V_274 = V_266 - V_274 ;
if ( V_6 == V_269 ) {
V_275 |= V_259 << V_271 ;
V_1 |= V_274 << V_271 ;
} else {
V_274 = V_274 << V_260 ;
V_273 = true ;
}
}
V_73 = F_181 ( V_45 , V_6 , V_275 , V_1 ) ;
if ( V_73 < 0 )
return V_73 ;
if ( V_273 )
V_73 = F_181 ( V_45 , V_269 , V_275 ,
V_274 ) ;
return V_73 ;
}
int F_189 ( struct V_232 * V_238 ,
struct V_256 * V_257 )
{
struct V_44 * V_45 = F_176 ( V_238 ) ;
struct V_263 * V_264 =
(struct V_263 * ) V_238 -> V_248 ;
unsigned int V_6 = V_264 -> V_6 ;
unsigned int V_269 = V_264 -> V_270 ;
unsigned int V_260 = V_264 -> V_260 ;
unsigned int V_271 = V_264 -> V_271 ;
int V_266 = V_264 -> V_266 ;
int F_6 = V_264 -> F_6 ;
int V_259 = ( 1 << ( F_187 ( F_6 + V_266 ) - 1 ) ) - 1 ;
unsigned int V_1 ;
int V_14 ;
V_14 = F_177 ( V_45 , V_6 , & V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
V_257 -> V_41 . integer . V_41 [ 0 ] = ( ( V_1 >> V_260 ) - F_6 ) & V_259 ;
if ( F_185 ( V_264 ) ) {
V_14 = F_177 ( V_45 , V_269 , & V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
V_1 = ( ( V_1 >> V_271 ) - F_6 ) & V_259 ;
V_257 -> V_41 . integer . V_41 [ 1 ] = V_1 ;
}
return 0 ;
}
int F_190 ( struct V_232 * V_238 ,
struct V_256 * V_257 )
{
struct V_44 * V_45 = F_176 ( V_238 ) ;
struct V_263 * V_264 =
(struct V_263 * ) V_238 -> V_248 ;
unsigned int V_6 = V_264 -> V_6 ;
unsigned int V_269 = V_264 -> V_270 ;
unsigned int V_260 = V_264 -> V_260 ;
unsigned int V_271 = V_264 -> V_271 ;
int V_266 = V_264 -> V_266 ;
int F_6 = V_264 -> F_6 ;
int V_259 = ( 1 << ( F_187 ( F_6 + V_266 ) - 1 ) ) - 1 ;
int V_73 = 0 ;
unsigned int V_1 , V_275 , V_274 = 0 ;
V_275 = V_259 << V_260 ;
V_1 = ( V_257 -> V_41 . integer . V_41 [ 0 ] + F_6 ) & V_259 ;
V_1 = V_1 << V_260 ;
V_73 = F_181 ( V_45 , V_6 , V_275 , V_1 ) ;
if ( V_73 < 0 )
return V_73 ;
if ( F_185 ( V_264 ) ) {
V_275 = V_259 << V_271 ;
V_274 = ( V_257 -> V_41 . integer . V_41 [ 1 ] + F_6 ) & V_259 ;
V_274 = V_274 << V_271 ;
V_73 = F_181 ( V_45 , V_269 , V_275 ,
V_274 ) ;
}
return V_73 ;
}
int F_191 ( struct V_232 * V_238 ,
struct V_244 * V_245 )
{
struct V_263 * V_264 =
(struct V_263 * ) V_238 -> V_248 ;
int V_265 ;
int F_6 = V_264 -> F_6 ;
if ( ! V_264 -> V_265 )
V_264 -> V_265 = V_264 -> V_266 ;
V_265 = V_264 -> V_265 ;
V_245 -> type = V_268 ;
V_245 -> V_18 = 2 ;
V_245 -> V_41 . integer . F_6 = 0 ;
V_245 -> V_41 . integer . V_266 = V_265 - F_6 ;
return 0 ;
}
int F_192 ( struct V_232 * V_238 ,
struct V_256 * V_257 )
{
struct V_263 * V_264 =
(struct V_263 * ) V_238 -> V_248 ;
struct V_44 * V_45 = F_176 ( V_238 ) ;
unsigned int V_6 = V_264 -> V_6 ;
unsigned int V_1 ;
int F_6 = V_264 -> F_6 ;
int V_14 ;
V_14 = F_177 ( V_45 , V_6 , & V_1 ) ;
if ( V_14 )
return V_14 ;
V_257 -> V_41 . integer . V_41 [ 0 ] =
( ( signed char ) ( V_1 & 0xff ) ) - F_6 ;
V_257 -> V_41 . integer . V_41 [ 1 ] =
( ( signed char ) ( ( V_1 >> 8 ) & 0xff ) ) - F_6 ;
return 0 ;
}
int F_193 ( struct V_232 * V_238 ,
struct V_256 * V_257 )
{
struct V_263 * V_264 =
(struct V_263 * ) V_238 -> V_248 ;
struct V_44 * V_45 = F_176 ( V_238 ) ;
unsigned int V_6 = V_264 -> V_6 ;
int F_6 = V_264 -> F_6 ;
unsigned int V_1 ;
V_1 = ( V_257 -> V_41 . integer . V_41 [ 0 ] + F_6 ) & 0xff ;
V_1 |= ( ( V_257 -> V_41 . integer . V_41 [ 1 ] + F_6 ) & 0xff ) << 8 ;
return F_181 ( V_45 , V_6 , 0xffff , V_1 ) ;
}
int F_194 ( struct V_232 * V_238 ,
struct V_244 * V_245 )
{
struct V_263 * V_264 =
(struct V_263 * ) V_238 -> V_248 ;
int V_265 ;
int F_6 = V_264 -> F_6 ;
if ( ! V_264 -> V_265 )
V_264 -> V_265 = V_264 -> V_266 ;
V_265 = V_264 -> V_265 ;
V_245 -> type = V_268 ;
V_245 -> V_18 = F_185 ( V_264 ) ? 2 : 1 ;
V_245 -> V_41 . integer . F_6 = 0 ;
V_245 -> V_41 . integer . V_266 = V_265 - F_6 ;
return 0 ;
}
int F_195 ( struct V_232 * V_238 ,
struct V_256 * V_257 )
{
struct V_263 * V_264 =
(struct V_263 * ) V_238 -> V_248 ;
struct V_44 * V_45 = F_176 ( V_238 ) ;
unsigned int V_6 = V_264 -> V_6 ;
unsigned int V_270 = V_264 -> V_270 ;
unsigned int V_260 = V_264 -> V_260 ;
int F_6 = V_264 -> F_6 ;
int V_266 = V_264 -> V_266 ;
unsigned int V_259 = ( 1 << F_187 ( V_266 ) ) - 1 ;
unsigned int V_272 = V_264 -> V_272 ;
unsigned int V_1 , V_275 ;
int V_14 ;
if ( V_272 )
V_1 = ( V_266 - V_257 -> V_41 . integer . V_41 [ 0 ] ) & V_259 ;
else
V_1 = ( ( V_257 -> V_41 . integer . V_41 [ 0 ] + F_6 ) & V_259 ) ;
V_275 = V_259 << V_260 ;
V_1 = V_1 << V_260 ;
V_14 = F_181 ( V_45 , V_6 , V_275 , V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( F_185 ( V_264 ) ) {
if ( V_272 )
V_1 = ( V_266 - V_257 -> V_41 . integer . V_41 [ 1 ] ) & V_259 ;
else
V_1 = ( ( V_257 -> V_41 . integer . V_41 [ 1 ] + F_6 ) & V_259 ) ;
V_275 = V_259 << V_260 ;
V_1 = V_1 << V_260 ;
V_14 = F_181 ( V_45 , V_270 , V_275 ,
V_1 ) ;
}
return V_14 ;
}
int F_196 ( struct V_232 * V_238 ,
struct V_256 * V_257 )
{
struct V_44 * V_45 = F_176 ( V_238 ) ;
struct V_263 * V_264 =
(struct V_263 * ) V_238 -> V_248 ;
unsigned int V_6 = V_264 -> V_6 ;
unsigned int V_270 = V_264 -> V_270 ;
unsigned int V_260 = V_264 -> V_260 ;
int F_6 = V_264 -> F_6 ;
int V_266 = V_264 -> V_266 ;
unsigned int V_259 = ( 1 << F_187 ( V_266 ) ) - 1 ;
unsigned int V_272 = V_264 -> V_272 ;
unsigned int V_1 ;
int V_14 ;
V_14 = F_177 ( V_45 , V_6 , & V_1 ) ;
if ( V_14 )
return V_14 ;
V_257 -> V_41 . integer . V_41 [ 0 ] = ( V_1 >> V_260 ) & V_259 ;
if ( V_272 )
V_257 -> V_41 . integer . V_41 [ 0 ] =
V_266 - V_257 -> V_41 . integer . V_41 [ 0 ] ;
else
V_257 -> V_41 . integer . V_41 [ 0 ] =
V_257 -> V_41 . integer . V_41 [ 0 ] - F_6 ;
if ( F_185 ( V_264 ) ) {
V_14 = F_177 ( V_45 , V_270 , & V_1 ) ;
if ( V_14 )
return V_14 ;
V_257 -> V_41 . integer . V_41 [ 1 ] = ( V_1 >> V_260 ) & V_259 ;
if ( V_272 )
V_257 -> V_41 . integer . V_41 [ 1 ] =
V_266 - V_257 -> V_41 . integer . V_41 [ 1 ] ;
else
V_257 -> V_41 . integer . V_41 [ 1 ] =
V_257 -> V_41 . integer . V_41 [ 1 ] - F_6 ;
}
return 0 ;
}
int F_197 ( struct V_4 * V_5 ,
const char * V_47 , int V_266 )
{
struct V_77 * V_49 = V_5 -> V_45 . V_49 -> V_77 ;
struct V_232 * V_242 ;
struct V_263 * V_264 ;
int V_276 = 0 ;
int V_14 = - V_17 ;
if ( F_169 ( ! V_47 || V_266 <= 0 ) )
return - V_17 ;
F_35 (kctl, &card->controls, list) {
if ( ! strncmp ( V_242 -> V_243 . V_47 , V_47 , sizeof( V_242 -> V_243 . V_47 ) ) ) {
V_276 = 1 ;
break;
}
}
if ( V_276 ) {
V_264 = (struct V_263 * ) V_242 -> V_248 ;
if ( V_266 <= V_264 -> V_266 ) {
V_264 -> V_265 = V_266 ;
V_14 = 0 ;
}
}
return V_14 ;
}
int F_198 ( struct V_232 * V_238 ,
struct V_244 * V_245 )
{
struct V_44 * V_45 = F_176 ( V_238 ) ;
struct V_277 * V_173 = ( void * ) V_238 -> V_248 ;
V_245 -> type = V_278 ;
V_245 -> V_18 = V_173 -> V_279 * V_45 -> V_280 ;
return 0 ;
}
int F_199 ( struct V_232 * V_238 ,
struct V_256 * V_257 )
{
struct V_44 * V_45 = F_176 ( V_238 ) ;
struct V_277 * V_173 = ( void * ) V_238 -> V_248 ;
int V_14 ;
if ( V_45 -> V_109 )
V_14 = F_200 ( V_45 -> V_109 , V_173 -> V_281 ,
V_257 -> V_41 . V_282 . V_235 ,
V_173 -> V_279 * V_45 -> V_280 ) ;
else
V_14 = - V_17 ;
if ( V_14 == 0 && V_173 -> V_259 ) {
switch ( V_45 -> V_280 ) {
case 1 :
V_257 -> V_41 . V_282 . V_235 [ 0 ] &= ~ V_173 -> V_259 ;
break;
case 2 :
( ( V_283 * ) ( & V_257 -> V_41 . V_282 . V_235 ) ) [ 0 ]
&= F_201 ( ~ V_173 -> V_259 ) ;
break;
case 4 :
( ( V_284 * ) ( & V_257 -> V_41 . V_282 . V_235 ) ) [ 0 ]
&= F_202 ( ~ V_173 -> V_259 ) ;
break;
default:
return - V_17 ;
}
}
return V_14 ;
}
int F_203 ( struct V_232 * V_238 ,
struct V_256 * V_257 )
{
struct V_44 * V_45 = F_176 ( V_238 ) ;
struct V_277 * V_173 = ( void * ) V_238 -> V_248 ;
int V_14 , V_8 ;
unsigned int V_1 , V_259 ;
void * V_235 ;
if ( ! V_45 -> V_109 || ! V_173 -> V_279 )
return - V_17 ;
V_8 = V_173 -> V_279 * V_45 -> V_280 ;
V_235 = F_204 ( V_257 -> V_41 . V_282 . V_235 , V_8 , V_36 | V_285 ) ;
if ( ! V_235 )
return - V_37 ;
if ( V_173 -> V_259 ) {
V_14 = F_205 ( V_45 -> V_109 , V_173 -> V_281 , & V_1 ) ;
if ( V_14 != 0 )
goto V_286;
V_1 &= V_173 -> V_259 ;
switch ( V_45 -> V_280 ) {
case 1 :
( ( V_287 * ) V_235 ) [ 0 ] &= ~ V_173 -> V_259 ;
( ( V_287 * ) V_235 ) [ 0 ] |= V_1 ;
break;
case 2 :
V_259 = ~ V_173 -> V_259 ;
V_14 = F_206 ( V_45 -> V_109 ,
& V_259 , & V_259 ) ;
if ( V_14 != 0 )
goto V_286;
( ( V_283 * ) V_235 ) [ 0 ] &= V_259 ;
V_14 = F_206 ( V_45 -> V_109 ,
& V_1 , & V_1 ) ;
if ( V_14 != 0 )
goto V_286;
( ( V_283 * ) V_235 ) [ 0 ] |= V_1 ;
break;
case 4 :
V_259 = ~ V_173 -> V_259 ;
V_14 = F_206 ( V_45 -> V_109 ,
& V_259 , & V_259 ) ;
if ( V_14 != 0 )
goto V_286;
( ( V_284 * ) V_235 ) [ 0 ] &= V_259 ;
V_14 = F_206 ( V_45 -> V_109 ,
& V_1 , & V_1 ) ;
if ( V_14 != 0 )
goto V_286;
( ( V_284 * ) V_235 ) [ 0 ] |= V_1 ;
break;
default:
V_14 = - V_17 ;
goto V_286;
}
}
V_14 = F_207 ( V_45 -> V_109 , V_173 -> V_281 ,
V_235 , V_8 ) ;
V_286:
F_15 ( V_235 ) ;
return V_14 ;
}
int F_208 ( struct V_232 * V_238 ,
struct V_244 * V_257 )
{
struct V_288 * V_173 = ( void * ) V_238 -> V_248 ;
V_257 -> type = V_278 ;
V_257 -> V_18 = V_173 -> V_266 ;
return 0 ;
}
int F_209 ( struct V_232 * V_238 , int V_289 ,
unsigned int V_290 , unsigned int T_4 * V_291 )
{
struct V_288 * V_173 = ( void * ) V_238 -> V_248 ;
unsigned int V_18 = V_290 < V_173 -> V_266 ? V_290 : V_173 -> V_266 ;
int V_14 = - V_292 ;
switch ( V_289 ) {
case V_293 :
if ( V_173 -> V_294 )
V_14 = V_173 -> V_294 ( V_291 , V_18 ) ;
break;
case V_295 :
if ( V_173 -> V_296 )
V_14 = V_173 -> V_296 ( V_291 , V_18 ) ;
break;
}
return V_14 ;
}
int F_210 ( struct V_232 * V_238 ,
struct V_244 * V_245 )
{
struct V_297 * V_264 =
(struct V_297 * ) V_238 -> V_248 ;
V_245 -> type = V_268 ;
V_245 -> V_18 = 1 ;
V_245 -> V_41 . integer . F_6 = V_264 -> F_6 ;
V_245 -> V_41 . integer . V_266 = V_264 -> V_266 ;
return 0 ;
}
int F_211 ( struct V_232 * V_238 ,
struct V_256 * V_257 )
{
struct V_44 * V_45 = F_176 ( V_238 ) ;
struct V_297 * V_264 =
(struct V_297 * ) V_238 -> V_248 ;
unsigned int V_298 = V_264 -> V_298 ;
unsigned int V_299 = V_264 -> V_299 ;
unsigned int V_300 = V_45 -> V_280 * V_301 ;
unsigned int V_302 = ( 1 << V_300 ) - 1 ;
unsigned int V_272 = V_264 -> V_272 ;
unsigned long V_259 = ( 1UL << V_264 -> V_303 ) - 1 ;
long F_6 = V_264 -> F_6 ;
long V_266 = V_264 -> V_266 ;
long V_1 = 0 ;
unsigned int V_304 ;
unsigned int V_3 ;
int V_14 ;
for ( V_3 = 0 ; V_3 < V_299 ; V_3 ++ ) {
V_14 = F_177 ( V_45 , V_298 + V_3 , & V_304 ) ;
if ( V_14 )
return V_14 ;
V_1 |= ( V_304 & V_302 ) << ( V_300 * ( V_299 - V_3 - 1 ) ) ;
}
V_1 &= V_259 ;
if ( F_6 < 0 && V_1 > V_266 )
V_1 |= ~ V_259 ;
if ( V_272 )
V_1 = V_266 - V_1 ;
V_257 -> V_41 . integer . V_41 [ 0 ] = V_1 ;
return 0 ;
}
int F_212 ( struct V_232 * V_238 ,
struct V_256 * V_257 )
{
struct V_44 * V_45 = F_176 ( V_238 ) ;
struct V_297 * V_264 =
(struct V_297 * ) V_238 -> V_248 ;
unsigned int V_298 = V_264 -> V_298 ;
unsigned int V_299 = V_264 -> V_299 ;
unsigned int V_300 = V_45 -> V_280 * V_301 ;
unsigned int V_302 = ( 1 << V_300 ) - 1 ;
unsigned int V_272 = V_264 -> V_272 ;
unsigned long V_259 = ( 1UL << V_264 -> V_303 ) - 1 ;
long V_266 = V_264 -> V_266 ;
long V_1 = V_257 -> V_41 . integer . V_41 [ 0 ] ;
unsigned int V_3 , V_304 , V_305 ;
int V_73 ;
if ( V_272 )
V_1 = V_266 - V_1 ;
V_1 &= V_259 ;
for ( V_3 = 0 ; V_3 < V_299 ; V_3 ++ ) {
V_304 = ( V_1 >> ( V_300 * ( V_299 - V_3 - 1 ) ) ) & V_302 ;
V_305 = ( V_259 >> ( V_300 * ( V_299 - V_3 - 1 ) ) ) & V_302 ;
V_73 = F_181 ( V_45 , V_298 + V_3 ,
V_305 , V_304 ) ;
if ( V_73 < 0 )
return V_73 ;
}
return 0 ;
}
int F_213 ( struct V_232 * V_238 ,
struct V_256 * V_257 )
{
struct V_44 * V_45 = F_176 ( V_238 ) ;
struct V_263 * V_264 =
(struct V_263 * ) V_238 -> V_248 ;
unsigned int V_6 = V_264 -> V_6 ;
unsigned int V_260 = V_264 -> V_260 ;
unsigned int V_259 = 1 << V_260 ;
unsigned int V_272 = V_264 -> V_272 != 0 ;
unsigned int V_1 ;
int V_14 ;
V_14 = F_177 ( V_45 , V_6 , & V_1 ) ;
if ( V_14 )
return V_14 ;
V_1 &= V_259 ;
if ( V_260 != 0 && V_1 != 0 )
V_1 = V_1 >> V_260 ;
V_257 -> V_41 . V_252 . V_254 [ 0 ] = V_1 ^ V_272 ;
return 0 ;
}
int F_214 ( struct V_232 * V_238 ,
struct V_256 * V_257 )
{
struct V_44 * V_45 = F_176 ( V_238 ) ;
struct V_263 * V_264 =
(struct V_263 * ) V_238 -> V_248 ;
unsigned int V_6 = V_264 -> V_6 ;
unsigned int V_260 = V_264 -> V_260 ;
unsigned int V_259 = 1 << V_260 ;
unsigned int V_272 = V_264 -> V_272 != 0 ;
unsigned int V_306 = V_257 -> V_41 . V_252 . V_254 [ 0 ] != 0 ;
unsigned int V_307 = ( V_306 ^ V_272 ) ? V_259 : 0 ;
unsigned int V_274 = ( V_306 ^ V_272 ) ? 0 : V_259 ;
int V_73 ;
V_73 = F_181 ( V_45 , V_6 , V_259 , V_307 ) ;
if ( V_73 < 0 )
return V_73 ;
return F_181 ( V_45 , V_6 , V_259 , V_274 ) ;
}
int F_215 ( struct V_55 * V_56 , int V_308 ,
unsigned int V_309 , int V_310 )
{
if ( V_56 -> V_10 && V_56 -> V_10 -> V_91 -> V_311 )
return V_56 -> V_10 -> V_91 -> V_311 ( V_56 , V_308 , V_309 , V_310 ) ;
else if ( V_56 -> V_5 && V_56 -> V_5 -> V_10 -> V_311 )
return V_56 -> V_5 -> V_10 -> V_311 ( V_56 -> V_5 , V_308 , 0 ,
V_309 , V_310 ) ;
else
return - V_197 ;
}
int F_216 ( struct V_4 * V_5 , int V_308 ,
int V_312 , unsigned int V_309 , int V_310 )
{
if ( V_5 -> V_10 -> V_311 )
return V_5 -> V_10 -> V_311 ( V_5 , V_308 , V_312 ,
V_309 , V_310 ) ;
else
return - V_197 ;
}
int F_217 ( struct V_55 * V_56 ,
int V_313 , int div )
{
if ( V_56 -> V_10 && V_56 -> V_10 -> V_91 -> V_314 )
return V_56 -> V_10 -> V_91 -> V_314 ( V_56 , V_313 , div ) ;
else
return - V_17 ;
}
int F_218 ( struct V_55 * V_56 , int V_315 , int V_312 ,
unsigned int V_316 , unsigned int V_317 )
{
if ( V_56 -> V_10 && V_56 -> V_10 -> V_91 -> V_318 )
return V_56 -> V_10 -> V_91 -> V_318 ( V_56 , V_315 , V_312 ,
V_316 , V_317 ) ;
else if ( V_56 -> V_5 && V_56 -> V_5 -> V_10 -> V_318 )
return V_56 -> V_5 -> V_10 -> V_318 ( V_56 -> V_5 , V_315 , V_312 ,
V_316 , V_317 ) ;
else
return - V_17 ;
}
int F_219 ( struct V_4 * V_5 , int V_315 , int V_312 ,
unsigned int V_316 , unsigned int V_317 )
{
if ( V_5 -> V_10 -> V_318 )
return V_5 -> V_10 -> V_318 ( V_5 , V_315 , V_312 ,
V_316 , V_317 ) ;
else
return - V_17 ;
}
int F_220 ( struct V_55 * V_56 , unsigned int V_319 )
{
if ( V_56 -> V_10 && V_56 -> V_10 -> V_91 -> V_320 )
return V_56 -> V_10 -> V_91 -> V_320 ( V_56 , V_319 ) ;
else
return - V_17 ;
}
int F_131 ( struct V_55 * V_56 , unsigned int V_321 )
{
if ( V_56 -> V_10 == NULL )
return - V_17 ;
if ( V_56 -> V_10 -> V_91 -> V_322 == NULL )
return - V_197 ;
return V_56 -> V_10 -> V_91 -> V_322 ( V_56 , V_321 ) ;
}
static int F_221 ( unsigned int V_323 ,
unsigned int * V_324 ,
unsigned int * V_325 )
{
if ( * V_324 || * V_325 )
return 0 ;
if ( ! V_323 )
return - V_17 ;
* V_324 = ( 1 << V_323 ) - 1 ;
* V_325 = ( 1 << V_323 ) - 1 ;
return 0 ;
}
int F_222 ( struct V_55 * V_56 ,
unsigned int V_324 , unsigned int V_325 , int V_323 , int V_326 )
{
if ( V_56 -> V_10 && V_56 -> V_10 -> V_91 -> V_327 )
V_56 -> V_10 -> V_91 -> V_327 ( V_323 ,
& V_324 , & V_325 ) ;
else
F_221 ( V_323 , & V_324 , & V_325 ) ;
V_56 -> V_324 = V_324 ;
V_56 -> V_325 = V_325 ;
if ( V_56 -> V_10 && V_56 -> V_10 -> V_91 -> V_328 )
return V_56 -> V_10 -> V_91 -> V_328 ( V_56 , V_324 , V_325 ,
V_323 , V_326 ) ;
else
return - V_197 ;
}
int F_223 ( struct V_55 * V_56 ,
unsigned int V_329 , unsigned int * V_330 ,
unsigned int V_331 , unsigned int * V_332 )
{
if ( V_56 -> V_10 && V_56 -> V_10 -> V_91 -> V_333 )
return V_56 -> V_10 -> V_91 -> V_333 ( V_56 , V_329 , V_330 ,
V_331 , V_332 ) ;
else
return - V_17 ;
}
int F_224 ( struct V_55 * V_56 , int V_334 )
{
if ( V_56 -> V_10 && V_56 -> V_10 -> V_91 -> V_335 )
return V_56 -> V_10 -> V_91 -> V_335 ( V_56 , V_334 ) ;
else
return - V_17 ;
}
int F_225 ( struct V_55 * V_56 , int V_336 ,
int V_337 )
{
if ( ! V_56 -> V_10 )
return - V_197 ;
if ( V_56 -> V_10 -> V_91 -> V_338 )
return V_56 -> V_10 -> V_91 -> V_338 ( V_56 , V_336 , V_337 ) ;
else if ( V_337 == V_103 &&
V_56 -> V_10 -> V_91 -> V_92 )
return V_56 -> V_10 -> V_91 -> V_92 ( V_56 , V_336 ) ;
else
return - V_197 ;
}
static int F_226 ( struct V_59 * V_49 ,
struct V_125 * V_64 )
{
if ( V_64 -> V_184 || V_64 -> V_185 ||
V_64 -> V_339 ) {
V_64 -> V_87 = 1 ;
V_64 -> V_126 = F_227 ( V_49 -> V_25 ,
sizeof( struct V_121 ) ,
V_36 ) ;
if ( ! V_64 -> V_126 )
return - V_37 ;
V_64 -> V_126 [ 0 ] . V_47 = V_64 -> V_184 ;
V_64 -> V_126 [ 0 ] . V_120 = V_64 -> V_185 ;
V_64 -> V_126 [ 0 ] . V_123 = V_64 -> V_339 ;
}
if ( ! V_64 -> V_126 ) {
F_51 ( V_49 -> V_25 , L_80 ) ;
return - V_17 ;
}
return 0 ;
}
int F_141 ( struct V_59 * V_49 )
{
int V_3 , V_81 , V_14 ;
if ( ! V_49 -> V_47 || ! V_49 -> V_25 )
return - V_17 ;
for ( V_3 = 0 ; V_3 < V_49 -> V_66 ; V_3 ++ ) {
struct V_125 * V_340 = & V_49 -> V_64 [ V_3 ] ;
V_14 = F_226 ( V_49 , V_340 ) ;
if ( V_14 ) {
F_51 ( V_49 -> V_25 , L_81 ) ;
return V_14 ;
}
for ( V_81 = 0 ; V_81 < V_340 -> V_87 ; V_81 ++ ) {
if ( ! ! V_340 -> V_126 [ V_81 ] . V_47 ==
! ! V_340 -> V_126 [ V_81 ] . V_120 ) {
F_51 ( V_49 -> V_25 , L_82 ,
V_340 -> V_47 ) ;
return - V_17 ;
}
if ( ! V_340 -> V_126 [ V_81 ] . V_123 ) {
F_51 ( V_49 -> V_25 , L_83 ,
V_340 -> V_47 ) ;
return - V_17 ;
}
}
if ( V_340 -> V_128 && V_340 -> V_133 ) {
F_51 ( V_49 -> V_25 ,
L_84 ,
V_340 -> V_47 ) ;
return - V_17 ;
}
if ( V_340 -> V_129 && V_340 -> V_130 ) {
F_51 ( V_49 -> V_25 ,
L_85 ,
V_340 -> V_47 ) ;
return - V_17 ;
}
if ( ! V_340 -> V_131 &&
! ( V_340 -> V_129 || V_340 -> V_130 ) ) {
F_51 ( V_49 -> V_25 ,
L_86 ,
V_340 -> V_47 ) ;
return - V_17 ;
}
}
F_95 ( V_49 -> V_25 , V_49 ) ;
F_228 ( V_49 ) ;
F_39 ( V_49 ) ;
V_49 -> V_29 = F_227 ( V_49 -> V_25 ,
sizeof( struct V_28 ) *
( V_49 -> V_66 + V_49 -> V_191 ) ,
V_36 ) ;
if ( V_49 -> V_29 == NULL )
return - V_37 ;
V_49 -> V_85 = 0 ;
V_49 -> V_181 = & V_49 -> V_29 [ V_49 -> V_66 ] ;
for ( V_3 = 0 ; V_3 < V_49 -> V_66 ; V_3 ++ ) {
V_49 -> V_29 [ V_3 ] . V_49 = V_49 ;
V_49 -> V_29 [ V_3 ] . V_64 = & V_49 -> V_64 [ V_3 ] ;
V_49 -> V_29 [ V_3 ] . V_88 = F_227 ( V_49 -> V_25 ,
sizeof( struct V_55 * ) *
( V_49 -> V_29 [ V_3 ] . V_64 -> V_87 ) ,
V_36 ) ;
if ( V_49 -> V_29 [ V_3 ] . V_88 == NULL )
return - V_37 ;
}
for ( V_3 = 0 ; V_3 < V_49 -> V_191 ; V_3 ++ )
V_49 -> V_181 [ V_3 ] . V_49 = V_49 ;
F_97 ( & V_49 -> V_341 ) ;
V_49 -> V_82 = 0 ;
F_96 ( & V_49 -> V_188 ) ;
F_96 ( & V_49 -> V_342 ) ;
V_14 = F_123 ( V_49 ) ;
if ( V_14 != 0 )
F_41 ( V_49 ) ;
for ( V_3 = 0 ; V_3 < V_49 -> V_85 ; V_3 ++ ) {
struct V_28 * V_29 = & V_49 -> V_29 [ V_3 ] ;
struct V_55 * V_95 = V_29 -> V_95 ;
int V_81 ;
for ( V_81 = 0 ; V_81 < V_29 -> V_87 ; V_81 ++ ) {
struct V_55 * V_118 = V_29 -> V_88 [ V_81 ] ;
if ( ! V_118 -> V_117 )
F_64 ( V_118 -> V_25 ) ;
}
if ( ! V_95 -> V_117 )
F_64 ( V_95 -> V_25 ) ;
}
return V_14 ;
}
int F_144 ( struct V_59 * V_49 )
{
if ( V_49 -> V_82 ) {
V_49 -> V_82 = false ;
F_146 ( V_49 ) ;
F_142 ( V_49 ) ;
}
F_43 ( V_49 -> V_25 , L_87 , V_49 -> V_47 ) ;
return 0 ;
}
static char * F_229 ( struct V_24 * V_25 , int * V_243 )
{
char * V_276 , V_47 [ V_343 ] ;
int V_344 , V_345 ;
if ( V_148 ( V_25 ) == NULL )
return NULL ;
F_174 ( V_47 , V_148 ( V_25 ) , V_343 ) ;
V_276 = strstr ( V_47 , V_25 -> V_10 -> V_47 ) ;
if ( V_276 ) {
if ( sscanf ( & V_276 [ strlen ( V_25 -> V_10 -> V_47 ) ] , L_88 , V_243 ) == 1 ) {
if ( * V_243 == - 1 )
V_276 [ strlen ( V_25 -> V_10 -> V_47 ) ] = '\0' ;
}
} else {
if ( sscanf ( V_47 , L_89 , & V_344 , & V_345 ) == 2 ) {
char V_346 [ V_343 ] ;
* V_243 = ( ( V_344 & 0xffff ) << 16 ) + V_345 ;
snprintf ( V_346 , V_343 , L_90 , V_25 -> V_10 -> V_47 , V_47 ) ;
F_174 ( V_47 , V_346 , V_343 ) ;
} else
* V_243 = 0 ;
}
return F_230 ( V_47 , V_36 ) ;
}
static inline char * F_231 ( struct V_24 * V_25 ,
struct V_89 * V_347 )
{
if ( V_347 -> V_47 == NULL ) {
F_51 ( V_25 ,
L_91 ,
V_148 ( V_25 ) ) ;
return NULL ;
}
return F_230 ( V_347 -> V_47 , V_36 ) ;
}
static void F_232 ( struct V_44 * V_45 )
{
struct V_55 * V_56 , * V_348 ;
F_233 (dai, _dai, &component->dai_list, list) {
F_43 ( V_45 -> V_25 , L_92 ,
V_56 -> V_47 ) ;
F_74 ( & V_56 -> V_160 ) ;
F_15 ( V_56 -> V_47 ) ;
F_15 ( V_56 ) ;
}
}
static int F_234 ( struct V_44 * V_45 ,
struct V_89 * V_347 , T_1 V_18 ,
bool V_349 )
{
struct V_24 * V_25 = V_45 -> V_25 ;
struct V_55 * V_56 ;
unsigned int V_3 ;
int V_14 ;
F_43 ( V_25 , L_93 , V_148 ( V_25 ) , V_18 ) ;
V_45 -> V_347 = V_347 ;
V_45 -> V_350 = V_18 ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ ) {
V_56 = F_93 ( sizeof( struct V_55 ) , V_36 ) ;
if ( V_56 == NULL ) {
V_14 = - V_37 ;
goto V_73;
}
if ( V_18 == 1 && V_349 ) {
V_56 -> V_47 = F_229 ( V_25 , & V_56 -> V_243 ) ;
} else {
V_56 -> V_47 = F_231 ( V_25 , & V_347 [ V_3 ] ) ;
if ( V_347 [ V_3 ] . V_243 )
V_56 -> V_243 = V_347 [ V_3 ] . V_243 ;
else
V_56 -> V_243 = V_3 ;
}
if ( V_56 -> V_47 == NULL ) {
F_15 ( V_56 ) ;
V_14 = - V_37 ;
goto V_73;
}
V_56 -> V_45 = V_45 ;
V_56 -> V_25 = V_25 ;
V_56 -> V_10 = & V_347 [ V_3 ] ;
if ( ! V_56 -> V_10 -> V_91 )
V_56 -> V_10 -> V_91 = & V_351 ;
F_90 ( & V_56 -> V_160 , & V_45 -> V_352 ) ;
F_43 ( V_25 , L_94 , V_56 -> V_47 ) ;
}
return 0 ;
V_73:
F_232 ( V_45 ) ;
return V_14 ;
}
static void F_235 ( struct V_150 * V_100 ,
enum V_353 type , int V_354 )
{
struct V_44 * V_45 = V_100 -> V_45 ;
V_45 -> V_10 -> V_355 ( V_45 , type , V_354 ) ;
}
static int F_236 ( struct V_150 * V_100 ,
int V_356 )
{
struct V_44 * V_45 = V_100 -> V_45 ;
return V_45 -> V_10 -> V_357 ( V_45 , V_356 ) ;
}
static int F_237 ( struct V_44 * V_45 ,
const struct V_358 * V_10 , struct V_24 * V_25 )
{
struct V_150 * V_100 ;
V_45 -> V_47 = F_229 ( V_25 , & V_45 -> V_243 ) ;
if ( ! V_45 -> V_47 ) {
F_51 ( V_25 , L_95 ) ;
return - V_37 ;
}
V_45 -> V_25 = V_25 ;
V_45 -> V_10 = V_10 ;
V_45 -> V_155 = V_45 -> V_10 -> V_155 ;
V_45 -> remove = V_45 -> V_10 -> remove ;
if ( ! V_45 -> V_359 )
V_45 -> V_359 = & V_45 -> V_100 ;
V_100 = V_45 -> V_359 ;
V_100 -> V_25 = V_25 ;
V_100 -> V_45 = V_45 ;
V_100 -> V_102 = V_108 ;
V_100 -> V_107 = true ;
if ( V_10 -> V_355 )
V_100 -> V_355 = F_235 ;
if ( V_10 -> V_357 )
V_100 -> V_357 = F_236 ;
V_45 -> V_156 = V_10 -> V_156 ;
V_45 -> V_157 = V_10 -> V_157 ;
V_45 -> V_152 = V_10 -> V_152 ;
V_45 -> V_153 = V_10 -> V_153 ;
V_45 -> V_158 = V_10 -> V_158 ;
V_45 -> V_159 = V_10 -> V_159 ;
F_97 ( & V_45 -> V_352 ) ;
F_96 ( & V_45 -> V_360 ) ;
return 0 ;
}
static void F_238 ( struct V_44 * V_45 )
{
if ( ! V_45 -> V_109 )
V_45 -> V_109 = F_239 ( V_45 -> V_25 , NULL ) ;
if ( V_45 -> V_109 ) {
int V_280 = F_240 ( V_45 -> V_109 ) ;
if ( V_280 > 0 )
V_45 -> V_280 = V_280 ;
}
}
static void F_241 ( struct V_44 * V_45 )
{
if ( ! V_45 -> V_361 && ! V_45 -> V_362 )
F_238 ( V_45 ) ;
F_90 ( & V_45 -> V_160 , & V_363 ) ;
}
static void F_242 ( struct V_44 * V_45 )
{
F_243 ( & V_364 ) ;
F_241 ( V_45 ) ;
F_137 ( & V_364 ) ;
}
static void F_244 ( struct V_44 * V_45 )
{
F_232 ( V_45 ) ;
F_15 ( V_45 -> V_47 ) ;
}
static void F_245 ( struct V_44 * V_45 )
{
F_74 ( & V_45 -> V_160 ) ;
}
static void F_246 ( struct V_44 * V_45 )
{
F_243 ( & V_364 ) ;
F_245 ( V_45 ) ;
F_137 ( & V_364 ) ;
}
int F_247 ( struct V_24 * V_25 ,
const struct V_358 * V_365 ,
struct V_89 * V_347 ,
int V_350 )
{
struct V_44 * V_366 ;
int V_14 ;
V_366 = F_93 ( sizeof( * V_366 ) , V_36 ) ;
if ( ! V_366 ) {
F_51 ( V_25 , L_96 ) ;
return - V_37 ;
}
V_14 = F_237 ( V_366 , V_365 , V_25 ) ;
if ( V_14 )
goto V_367;
V_366 -> V_368 = true ;
V_366 -> V_369 = true ;
V_14 = F_234 ( V_366 , V_347 , V_350 , true ) ;
if ( V_14 < 0 ) {
F_51 ( V_25 , L_97 , V_14 ) ;
goto V_370;
}
F_242 ( V_366 ) ;
return 0 ;
V_370:
F_244 ( V_366 ) ;
V_367:
F_15 ( V_366 ) ;
return V_14 ;
}
void F_248 ( struct V_24 * V_25 )
{
struct V_44 * V_366 ;
F_35 (cmpnt, &component_list, list) {
if ( V_25 == V_366 -> V_25 && V_366 -> V_369 )
goto V_276;
}
return;
V_276:
F_246 ( V_366 ) ;
F_244 ( V_366 ) ;
F_15 ( V_366 ) ;
}
static int F_249 ( struct V_44 * V_45 )
{
struct V_57 * V_58 = F_250 ( V_45 ) ;
return V_58 -> V_10 -> V_155 ( V_58 ) ;
}
static void F_251 ( struct V_44 * V_45 )
{
struct V_57 * V_58 = F_250 ( V_45 ) ;
V_58 -> V_10 -> remove ( V_58 ) ;
}
int F_252 ( struct V_24 * V_25 , struct V_57 * V_58 ,
const struct V_371 * V_372 )
{
int V_14 ;
V_14 = F_237 ( & V_58 -> V_45 ,
& V_372 -> V_373 , V_25 ) ;
if ( V_14 )
return V_14 ;
V_58 -> V_25 = V_25 ;
V_58 -> V_10 = V_372 ;
if ( V_372 -> V_155 )
V_58 -> V_45 . V_155 = F_249 ;
if ( V_372 -> remove )
V_58 -> V_45 . remove = F_251 ;
#ifdef F_107
V_58 -> V_45 . V_46 = L_98 ;
#endif
F_243 ( & V_364 ) ;
F_241 ( & V_58 -> V_45 ) ;
F_90 ( & V_58 -> V_160 , & V_374 ) ;
F_137 ( & V_364 ) ;
F_43 ( V_25 , L_99 ,
V_58 -> V_45 . V_47 ) ;
return 0 ;
}
int F_253 ( struct V_24 * V_25 ,
const struct V_371 * V_372 )
{
struct V_57 * V_58 ;
int V_14 ;
F_43 ( V_25 , L_100 , V_148 ( V_25 ) ) ;
V_58 = F_93 ( sizeof( struct V_57 ) , V_36 ) ;
if ( V_58 == NULL )
return - V_37 ;
V_14 = F_252 ( V_25 , V_58 , V_372 ) ;
if ( V_14 )
F_15 ( V_58 ) ;
return V_14 ;
}
void F_254 ( struct V_57 * V_58 )
{
F_243 ( & V_364 ) ;
F_74 ( & V_58 -> V_160 ) ;
F_245 ( & V_58 -> V_45 ) ;
F_137 ( & V_364 ) ;
F_43 ( V_58 -> V_25 , L_101 ,
V_58 -> V_45 . V_47 ) ;
F_244 ( & V_58 -> V_45 ) ;
}
struct V_57 * F_255 ( struct V_24 * V_25 )
{
struct V_57 * V_58 ;
F_35 (platform, &platform_list, list) {
if ( V_25 == V_58 -> V_25 )
return V_58 ;
}
return NULL ;
}
void F_256 ( struct V_24 * V_25 )
{
struct V_57 * V_58 ;
V_58 = F_255 ( V_25 ) ;
if ( ! V_58 )
return;
F_254 ( V_58 ) ;
F_15 ( V_58 ) ;
}
static void F_257 ( struct V_375 * V_65 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_132 ( V_376 ) ; V_3 ++ )
if ( V_65 -> V_377 & V_376 [ V_3 ] )
V_65 -> V_377 |= V_376 [ V_3 ] ;
}
static int F_258 ( struct V_44 * V_45 )
{
struct V_4 * V_5 = F_31 ( V_45 ) ;
return V_5 -> V_10 -> V_155 ( V_5 ) ;
}
static void F_259 ( struct V_44 * V_45 )
{
struct V_4 * V_5 = F_31 ( V_45 ) ;
V_5 -> V_10 -> remove ( V_5 ) ;
}
static int F_260 ( struct V_44 * V_45 ,
unsigned int V_6 , unsigned int V_1 )
{
struct V_4 * V_5 = F_31 ( V_45 ) ;
return V_5 -> V_10 -> V_361 ( V_5 , V_6 , V_1 ) ;
}
static int F_261 ( struct V_44 * V_45 ,
unsigned int V_6 , unsigned int * V_1 )
{
struct V_4 * V_5 = F_31 ( V_45 ) ;
* V_1 = V_5 -> V_10 -> V_362 ( V_5 , V_6 ) ;
return 0 ;
}
static int F_262 ( struct V_150 * V_100 ,
enum V_378 V_379 )
{
struct V_4 * V_5 = F_263 ( V_100 ) ;
return V_5 -> V_10 -> V_380 ( V_5 , V_379 ) ;
}
int F_264 ( struct V_24 * V_25 ,
const struct V_381 * V_382 ,
struct V_89 * V_347 ,
int V_350 )
{
struct V_4 * V_5 ;
struct V_55 * V_56 ;
int V_14 , V_3 ;
F_43 ( V_25 , L_102 , V_148 ( V_25 ) ) ;
V_5 = F_93 ( sizeof( struct V_4 ) , V_36 ) ;
if ( V_5 == NULL )
return - V_37 ;
V_5 -> V_45 . V_359 = & V_5 -> V_100 ;
V_5 -> V_45 . V_5 = V_5 ;
V_14 = F_237 ( & V_5 -> V_45 ,
& V_382 -> V_373 , V_25 ) ;
if ( V_14 )
goto V_367;
if ( V_382 -> V_156 ) {
V_5 -> V_45 . V_156 = V_382 -> V_156 ;
V_5 -> V_45 . V_157 = V_382 -> V_157 ;
}
if ( V_382 -> V_152 ) {
V_5 -> V_45 . V_152 = V_382 -> V_152 ;
V_5 -> V_45 . V_153 = V_382 -> V_153 ;
}
if ( V_382 -> V_158 ) {
V_5 -> V_45 . V_158 = V_382 -> V_158 ;
V_5 -> V_45 . V_159 = V_382 -> V_159 ;
}
if ( V_382 -> V_155 )
V_5 -> V_45 . V_155 = F_258 ;
if ( V_382 -> remove )
V_5 -> V_45 . remove = F_259 ;
if ( V_382 -> V_361 )
V_5 -> V_45 . V_361 = F_260 ;
if ( V_382 -> V_362 )
V_5 -> V_45 . V_362 = F_261 ;
V_5 -> V_45 . V_368 = V_382 -> V_368 ;
V_5 -> V_100 . V_107 = V_382 -> V_107 ;
V_5 -> V_100 . V_383 = V_382 -> V_383 ;
if ( V_382 -> V_355 )
V_5 -> V_100 . V_355 = V_382 -> V_355 ;
if ( V_382 -> V_380 )
V_5 -> V_100 . V_380 = F_262 ;
V_5 -> V_25 = V_25 ;
V_5 -> V_10 = V_382 ;
V_5 -> V_45 . V_280 = V_382 -> V_13 ;
F_96 ( & V_5 -> V_188 ) ;
#ifdef F_107
V_5 -> V_45 . V_51 = F_30 ;
V_5 -> V_45 . V_46 = L_103 ;
#endif
if ( V_382 -> V_384 )
V_5 -> V_45 . V_109 = V_382 -> V_384 ( V_25 ) ;
for ( V_3 = 0 ; V_3 < V_350 ; V_3 ++ ) {
F_257 ( & V_347 [ V_3 ] . V_385 ) ;
F_257 ( & V_347 [ V_3 ] . V_386 ) ;
}
V_14 = F_234 ( & V_5 -> V_45 , V_347 , V_350 , false ) ;
if ( V_14 < 0 ) {
F_51 ( V_25 , L_97 , V_14 ) ;
goto V_370;
}
F_35 (dai, &codec->component.dai_list, list)
V_56 -> V_5 = V_5 ;
F_243 ( & V_364 ) ;
F_241 ( & V_5 -> V_45 ) ;
F_90 ( & V_5 -> V_160 , & V_387 ) ;
F_137 ( & V_364 ) ;
F_43 ( V_5 -> V_25 , L_104 ,
V_5 -> V_45 . V_47 ) ;
return 0 ;
V_370:
F_244 ( & V_5 -> V_45 ) ;
V_367:
F_15 ( V_5 ) ;
return V_14 ;
}
void F_265 ( struct V_24 * V_25 )
{
struct V_4 * V_5 ;
F_35 (codec, &codec_list, list) {
if ( V_25 == V_5 -> V_25 )
goto V_276;
}
return;
V_276:
F_243 ( & V_364 ) ;
F_74 ( & V_5 -> V_160 ) ;
F_245 ( & V_5 -> V_45 ) ;
F_137 ( & V_364 ) ;
F_43 ( V_5 -> V_25 , L_105 ,
V_5 -> V_45 . V_47 ) ;
F_244 ( & V_5 -> V_45 ) ;
F_266 ( V_5 ) ;
F_15 ( V_5 ) ;
}
int F_267 ( struct V_59 * V_49 ,
const char * V_388 )
{
struct V_119 * V_389 ;
int V_14 ;
if ( ! V_49 -> V_25 ) {
F_268 ( L_106 , V_390 ) ;
return - V_17 ;
}
V_389 = V_49 -> V_25 -> V_120 ;
V_14 = F_269 ( V_389 , V_388 , 0 , & V_49 -> V_47 ) ;
if ( V_14 < 0 && V_14 != - V_17 ) {
F_51 ( V_49 -> V_25 ,
L_107 ,
V_388 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
int F_270 ( struct V_59 * V_49 ,
const char * V_388 )
{
struct V_119 * V_389 = V_49 -> V_25 -> V_120 ;
struct V_168 * V_391 ;
const char * V_237 , * V_392 ;
int V_3 , V_81 , V_393 , V_14 ;
V_393 = F_271 ( V_389 , V_388 ) ;
if ( V_393 < 0 ) {
F_51 ( V_49 -> V_25 ,
L_108 , V_388 ) ;
return - V_17 ;
}
if ( V_393 & 1 ) {
F_51 ( V_49 -> V_25 ,
L_109 , V_388 ) ;
return - V_17 ;
}
V_393 /= 2 ;
if ( ! V_393 ) {
F_51 ( V_49 -> V_25 , L_110 ,
V_388 ) ;
return - V_17 ;
}
V_391 = F_272 ( V_49 -> V_25 , V_393 , sizeof( * V_391 ) ,
V_36 ) ;
if ( ! V_391 ) {
F_51 ( V_49 -> V_25 ,
L_111 ) ;
return - V_37 ;
}
for ( V_3 = 0 ; V_3 < V_393 ; V_3 ++ ) {
V_14 = F_269 ( V_389 , V_388 ,
2 * V_3 , & V_237 ) ;
if ( V_14 ) {
F_51 ( V_49 -> V_25 ,
L_112 ,
V_388 , 2 * V_3 , V_14 ) ;
return - V_17 ;
}
for ( V_81 = 0 ; V_81 < F_132 ( V_394 ) ; V_81 ++ ) {
if ( ! strncmp ( V_237 , V_394 [ V_81 ] . V_47 ,
strlen ( V_394 [ V_81 ] . V_47 ) ) ) {
V_391 [ V_3 ] = V_394 [ V_81 ] ;
break;
}
}
if ( V_81 >= F_132 ( V_394 ) ) {
F_51 ( V_49 -> V_25 ,
L_113 ,
V_237 ) ;
return - V_17 ;
}
V_14 = F_269 ( V_389 , V_388 ,
( 2 * V_3 ) + 1 ,
& V_392 ) ;
if ( V_14 ) {
F_51 ( V_49 -> V_25 ,
L_112 ,
V_388 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_17 ;
}
V_391 [ V_3 ] . V_47 = V_392 ;
}
V_49 -> V_152 = V_391 ;
V_49 -> V_153 = V_393 ;
return 0 ;
}
int F_273 ( struct V_119 * V_389 ,
unsigned int * V_323 ,
unsigned int * V_326 )
{
V_284 V_1 ;
int V_14 ;
if ( F_274 ( V_389 , L_114 ) ) {
V_14 = F_275 ( V_389 , L_114 , & V_1 ) ;
if ( V_14 )
return V_14 ;
if ( V_323 )
* V_323 = V_1 ;
}
if ( F_274 ( V_389 , L_115 ) ) {
V_14 = F_275 ( V_389 , L_115 , & V_1 ) ;
if ( V_14 )
return V_14 ;
if ( V_326 )
* V_326 = V_1 ;
}
return 0 ;
}
int F_276 ( struct V_59 * V_49 ,
const char * V_388 )
{
struct V_119 * V_389 = V_49 -> V_25 -> V_120 ;
int V_395 ;
struct V_396 * V_397 ;
int V_3 , V_14 ;
V_395 = F_271 ( V_389 , V_388 ) ;
if ( V_395 < 0 || V_395 & 1 ) {
F_51 ( V_49 -> V_25 ,
L_116 ,
V_388 ) ;
return - V_17 ;
}
V_395 /= 2 ;
if ( ! V_395 ) {
F_51 ( V_49 -> V_25 , L_110 ,
V_388 ) ;
return - V_17 ;
}
V_397 = F_227 ( V_49 -> V_25 , V_395 * sizeof( * V_397 ) ,
V_36 ) ;
if ( ! V_397 ) {
F_51 ( V_49 -> V_25 ,
L_117 ) ;
return - V_17 ;
}
for ( V_3 = 0 ; V_3 < V_395 ; V_3 ++ ) {
V_14 = F_269 ( V_389 , V_388 ,
2 * V_3 , & V_397 [ V_3 ] . V_398 ) ;
if ( V_14 ) {
F_51 ( V_49 -> V_25 ,
L_118 ,
V_388 , 2 * V_3 , V_14 ) ;
return - V_17 ;
}
V_14 = F_269 ( V_389 , V_388 ,
( 2 * V_3 ) + 1 , & V_397 [ V_3 ] . V_312 ) ;
if ( V_14 ) {
F_51 ( V_49 -> V_25 ,
L_118 ,
V_388 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_17 ;
}
}
V_49 -> V_159 = V_395 ;
V_49 -> V_158 = V_397 ;
return 0 ;
}
unsigned int F_277 ( struct V_119 * V_389 ,
const char * V_236 ,
struct V_119 * * V_399 ,
struct V_119 * * V_400 )
{
int V_14 , V_3 ;
char V_401 [ 128 ] ;
unsigned int V_402 = 0 ;
int V_403 , V_404 ;
const char * V_405 ;
struct {
char * V_47 ;
unsigned int V_1 ;
} V_406 [] = {
{ L_119 , V_407 } ,
{ L_120 , V_408 } ,
{ L_121 , V_409 } ,
{ L_122 , V_410 } ,
{ L_123 , V_411 } ,
{ L_124 , V_412 } ,
{ L_125 , V_413 } ,
{ L_126 , V_414 } ,
{ L_127 , V_415 } ,
} ;
if ( ! V_236 )
V_236 = L_128 ;
snprintf ( V_401 , sizeof( V_401 ) , L_129 , V_236 ) ;
V_14 = F_278 ( V_389 , V_401 , & V_405 ) ;
if ( V_14 == 0 ) {
for ( V_3 = 0 ; V_3 < F_132 ( V_406 ) ; V_3 ++ ) {
if ( strcmp ( V_405 , V_406 [ V_3 ] . V_47 ) == 0 ) {
V_402 |= V_406 [ V_3 ] . V_1 ;
break;
}
}
}
snprintf ( V_401 , sizeof( V_401 ) , L_130 , V_236 ) ;
if ( F_279 ( V_389 , V_401 , NULL ) )
V_402 |= V_416 ;
else
V_402 |= V_417 ;
snprintf ( V_401 , sizeof( V_401 ) , L_131 , V_236 ) ;
V_403 = ! ! F_279 ( V_389 , V_401 , NULL ) ;
snprintf ( V_401 , sizeof( V_401 ) , L_132 , V_236 ) ;
V_404 = ! ! F_279 ( V_389 , V_401 , NULL ) ;
switch ( ( V_403 << 4 ) + V_404 ) {
case 0x11 :
V_402 |= V_418 ;
break;
case 0x10 :
V_402 |= V_419 ;
break;
case 0x01 :
V_402 |= V_420 ;
break;
default:
break;
}
snprintf ( V_401 , sizeof( V_401 ) , L_133 , V_236 ) ;
V_403 = ! ! F_279 ( V_389 , V_401 , NULL ) ;
if ( V_403 && V_399 )
* V_399 = F_280 ( V_389 , V_401 , 0 ) ;
snprintf ( V_401 , sizeof( V_401 ) , L_134 , V_236 ) ;
V_404 = ! ! F_279 ( V_389 , V_401 , NULL ) ;
if ( V_404 && V_400 )
* V_400 = F_280 ( V_389 , V_401 , 0 ) ;
switch ( ( V_403 << 4 ) + V_404 ) {
case 0x11 :
V_402 |= V_199 ;
break;
case 0x10 :
V_402 |= V_201 ;
break;
case 0x01 :
V_402 |= V_202 ;
break;
default:
V_402 |= V_200 ;
break;
}
return V_402 ;
}
int F_281 ( struct V_119 * V_120 ,
const char * * V_123 )
{
struct V_44 * V_19 ;
struct V_421 args ;
int V_14 ;
V_14 = F_282 ( V_120 , L_135 ,
L_136 , 0 , & args ) ;
if ( V_14 )
return V_14 ;
V_14 = - V_132 ;
F_243 ( & V_364 ) ;
F_35 (pos, &component_list, list) {
if ( V_19 -> V_25 -> V_120 != args . V_389 )
continue;
if ( V_19 -> V_10 -> V_422 ) {
V_14 = V_19 -> V_10 -> V_422 ( V_19 , & args , V_123 ) ;
} else {
int V_243 = - 1 ;
switch ( args . V_423 ) {
case 0 :
V_243 = 0 ;
break;
case 1 :
V_243 = args . args [ 0 ] ;
break;
default:
break;
}
if ( V_243 < 0 || V_243 >= V_19 -> V_350 ) {
V_14 = - V_17 ;
continue;
}
V_14 = 0 ;
* V_123 = V_19 -> V_347 [ V_243 ] . V_47 ;
if ( ! * V_123 )
* V_123 = V_19 -> V_47 ;
}
break;
}
F_137 ( & V_364 ) ;
F_283 ( args . V_389 ) ;
return V_14 ;
}
static int T_5 F_284 ( void )
{
#ifdef F_107
V_60 = F_24 ( L_137 , NULL ) ;
if ( F_156 ( V_60 ) || ! V_60 ) {
F_285 ( L_138 ) ;
V_60 = NULL ;
}
if ( ! F_33 ( L_139 , 0444 , V_60 , NULL ,
& V_424 ) )
F_285 ( L_140 ) ;
if ( ! F_33 ( L_141 , 0444 , V_60 , NULL ,
& V_425 ) )
F_285 ( L_142 ) ;
if ( ! F_33 ( L_143 , 0444 , V_60 , NULL ,
& V_426 ) )
F_285 ( L_144 ) ;
#endif
F_286 () ;
return F_287 ( & V_427 ) ;
}
static void T_6 F_288 ( void )
{
F_289 () ;
#ifdef F_107
F_29 ( V_60 ) ;
#endif
F_290 ( & V_427 ) ;
}
