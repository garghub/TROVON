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
static void F_22 ( struct V_4 * V_5 )
{
struct V_44 * V_45 = V_5 -> V_46 -> V_45 ;
V_5 -> V_47 = F_23 ( V_5 -> V_48 ,
V_45 ) ;
if ( ! V_5 -> V_47 ) {
F_24 ( V_5 -> V_25 ,
L_4 ) ;
return;
}
F_25 ( L_5 , 0444 , V_5 -> V_47 ,
& V_5 -> V_49 ) ;
F_25 ( L_6 , 0444 , V_5 -> V_47 ,
& V_5 -> V_50 ) ;
V_5 -> V_51 = F_26 ( L_7 , 0644 ,
V_5 -> V_47 ,
V_5 , & V_52 ) ;
if ( ! V_5 -> V_51 )
F_24 ( V_5 -> V_25 ,
L_8 ) ;
F_27 ( & V_5 -> V_53 , V_5 -> V_47 ) ;
}
static void F_28 ( struct V_4 * V_5 )
{
F_29 ( V_5 -> V_47 ) ;
}
static void F_30 ( struct V_54 * V_55 )
{
struct V_44 * V_45 = V_55 -> V_46 -> V_45 ;
V_55 -> V_56 = F_23 ( V_55 -> V_48 ,
V_45 ) ;
if ( ! V_55 -> V_56 ) {
F_24 ( V_55 -> V_25 ,
L_9 ) ;
return;
}
F_27 ( & V_55 -> V_53 ,
V_55 -> V_56 ) ;
}
static void F_31 ( struct V_54 * V_55 )
{
F_29 ( V_55 -> V_56 ) ;
}
static T_2 F_32 ( struct V_32 * V_32 , char T_4 * V_33 ,
T_1 V_18 , T_3 * V_34 )
{
char * V_7 = F_13 ( V_30 , V_36 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_4 * V_5 ;
if ( ! V_7 )
return - V_37 ;
F_33 (codec, &codec_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_30 - V_14 , L_10 ,
V_5 -> V_48 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_30 ) {
V_14 = V_30 ;
break;
}
}
if ( V_14 >= 0 )
V_14 = F_34 ( V_33 , V_18 , V_34 , V_7 , V_14 ) ;
F_15 ( V_7 ) ;
return V_14 ;
}
static T_2 F_35 ( struct V_32 * V_32 , char T_4 * V_33 ,
T_1 V_18 , T_3 * V_34 )
{
char * V_7 = F_13 ( V_30 , V_36 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_57 * V_58 ;
struct V_59 * V_60 ;
if ( ! V_7 )
return - V_37 ;
F_33 (component, &component_list, list) {
F_33 (dai, &component->dai_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_30 - V_14 , L_10 ,
V_60 -> V_48 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_30 ) {
V_14 = V_30 ;
break;
}
}
}
V_14 = F_34 ( V_33 , V_18 , V_34 , V_7 , V_14 ) ;
F_15 ( V_7 ) ;
return V_14 ;
}
static T_2 F_36 ( struct V_32 * V_32 ,
char T_4 * V_33 ,
T_1 V_18 , T_3 * V_34 )
{
char * V_7 = F_13 ( V_30 , V_36 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_54 * V_55 ;
if ( ! V_7 )
return - V_37 ;
F_33 (platform, &platform_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_30 - V_14 , L_10 ,
V_55 -> V_48 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_30 ) {
V_14 = V_30 ;
break;
}
}
V_14 = F_34 ( V_33 , V_18 , V_34 , V_7 , V_14 ) ;
F_15 ( V_7 ) ;
return V_14 ;
}
static void F_37 ( struct V_61 * V_46 )
{
V_46 -> V_45 = F_23 ( V_46 -> V_48 ,
V_62 ) ;
if ( ! V_46 -> V_45 ) {
F_24 ( V_46 -> V_25 ,
L_11 ) ;
return;
}
V_46 -> V_63 = F_38 ( L_12 , 0644 ,
V_46 -> V_45 ,
& V_46 -> V_64 ) ;
if ( ! V_46 -> V_63 )
F_24 ( V_46 -> V_25 ,
L_13 ) ;
}
static void F_39 ( struct V_61 * V_46 )
{
F_29 ( V_46 -> V_45 ) ;
}
static inline void F_22 ( struct V_4 * V_5 )
{
}
static inline void F_28 ( struct V_4 * V_5 )
{
}
static inline void F_30 ( struct V_54 * V_55 )
{
}
static inline void F_31 ( struct V_54 * V_55 )
{
}
static inline void F_37 ( struct V_61 * V_46 )
{
}
static inline void F_39 ( struct V_61 * V_46 )
{
}
struct V_65 * F_40 ( struct V_61 * V_46 ,
const char * V_66 , int V_67 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_68 ; V_3 ++ ) {
if ( V_46 -> V_29 [ V_3 ] . V_66 -> V_69 &&
! strcmp ( V_46 -> V_29 [ V_3 ] . V_66 -> V_48 , V_66 ) )
return V_46 -> V_29 [ V_3 ] . V_70 -> V_71 [ V_67 ] . V_72 ;
}
F_41 ( V_46 -> V_25 , L_14 , V_66 ) ;
return NULL ;
}
struct V_28 * F_42 ( struct V_61 * V_46 ,
const char * V_66 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_68 ; V_3 ++ ) {
if ( ! strcmp ( V_46 -> V_29 [ V_3 ] . V_66 -> V_48 , V_66 ) )
return & V_46 -> V_29 [ V_3 ] ;
}
F_41 ( V_46 -> V_25 , L_15 , V_66 ) ;
return NULL ;
}
static int F_43 ( struct V_4 * V_5 )
{
if ( V_5 -> V_73 -> V_25 . V_74 )
F_44 ( & V_5 -> V_73 -> V_25 ) ;
return 0 ;
}
static void F_45 ( struct V_24 * V_25 ) {}
static int F_46 ( struct V_4 * V_5 )
{
int V_75 ;
V_5 -> V_73 -> V_25 . V_74 = & V_76 ;
V_5 -> V_73 -> V_25 . V_77 = V_5 -> V_46 -> V_25 ;
V_5 -> V_73 -> V_25 . V_78 = F_45 ;
F_47 ( & V_5 -> V_73 -> V_25 , L_16 ,
V_5 -> V_46 -> V_79 -> V_80 , 0 , V_5 -> V_48 ) ;
V_75 = F_48 ( & V_5 -> V_73 -> V_25 ) ;
if ( V_75 < 0 ) {
F_49 ( V_5 -> V_25 , L_17 ) ;
V_5 -> V_73 -> V_25 . V_74 = NULL ;
return V_75 ;
}
return 0 ;
}
static void F_50 ( struct V_81 * V_82 )
{
}
int F_51 ( struct V_24 * V_25 )
{
struct V_61 * V_46 = F_8 ( V_25 ) ;
struct V_4 * V_5 ;
int V_3 ;
if ( F_52 ( & V_46 -> V_83 ) )
return 0 ;
F_53 ( V_46 -> V_79 ) ;
F_54 ( V_46 -> V_79 , V_84 ) ;
F_55 ( V_46 -> V_79 ) ;
F_56 ( V_46 -> V_79 , V_85 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_86 ; V_3 ++ ) {
struct V_59 * V_60 = V_46 -> V_29 [ V_3 ] . V_87 ;
struct V_88 * V_89 = V_60 -> V_10 ;
if ( V_46 -> V_29 [ V_3 ] . V_66 -> V_90 )
continue;
if ( V_89 -> V_91 -> V_92 && V_60 -> V_93 )
V_89 -> V_91 -> V_92 ( V_60 , 1 ) ;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_86 ; V_3 ++ ) {
if ( V_46 -> V_29 [ V_3 ] . V_66 -> V_90 )
continue;
F_57 ( V_46 -> V_29 [ V_3 ] . V_70 ) ;
}
if ( V_46 -> V_94 )
V_46 -> V_94 ( V_46 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_86 ; V_3 ++ ) {
struct V_59 * V_95 = V_46 -> V_29 [ V_3 ] . V_95 ;
struct V_54 * V_55 = V_46 -> V_29 [ V_3 ] . V_55 ;
if ( V_46 -> V_29 [ V_3 ] . V_66 -> V_90 )
continue;
if ( V_95 -> V_10 -> V_96 && ! V_95 -> V_10 -> V_97 )
V_95 -> V_10 -> V_96 ( V_95 ) ;
if ( V_55 -> V_10 -> V_96 && ! V_55 -> V_98 ) {
V_55 -> V_10 -> V_96 ( V_95 ) ;
V_55 -> V_98 = 1 ;
}
}
for ( V_3 = 0 ; V_3 < V_46 -> V_86 ; V_3 ++ ) {
F_58 ( & V_46 -> V_29 [ V_3 ] . V_99 ) ;
V_46 -> V_29 [ V_3 ] . V_5 -> V_53 . V_100 = V_46 -> V_29 [ V_3 ] . V_5 -> V_53 . V_101 ;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_86 ; V_3 ++ ) {
if ( V_46 -> V_29 [ V_3 ] . V_66 -> V_90 )
continue;
F_59 ( & V_46 -> V_29 [ V_3 ] ,
V_102 ,
V_103 ) ;
F_59 ( & V_46 -> V_29 [ V_3 ] ,
V_104 ,
V_103 ) ;
}
F_60 ( & V_46 -> V_53 ) ;
F_61 ( & V_46 -> V_53 ) ;
F_33 (codec, &card->codec_dev_list, card_list) {
if ( ! V_5 -> V_98 && V_5 -> V_10 -> V_96 ) {
switch ( V_5 -> V_53 . V_101 ) {
case V_105 :
if ( V_5 -> V_53 . V_106 ) {
F_41 ( V_5 -> V_25 ,
L_18 ) ;
break;
}
case V_107 :
V_5 -> V_10 -> V_96 ( V_5 ) ;
V_5 -> V_98 = 1 ;
V_5 -> V_49 = 1 ;
if ( V_5 -> V_58 . V_108 )
F_62 ( V_5 -> V_58 . V_108 ) ;
F_63 ( V_5 -> V_25 ) ;
break;
default:
F_41 ( V_5 -> V_25 ,
L_19 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_46 -> V_86 ; V_3 ++ ) {
struct V_59 * V_95 = V_46 -> V_29 [ V_3 ] . V_95 ;
if ( V_46 -> V_29 [ V_3 ] . V_66 -> V_90 )
continue;
if ( V_95 -> V_10 -> V_96 && V_95 -> V_10 -> V_97 )
V_95 -> V_10 -> V_96 ( V_95 ) ;
F_63 ( V_95 -> V_25 ) ;
}
if ( V_46 -> V_109 )
V_46 -> V_109 ( V_46 ) ;
return 0 ;
}
static void F_64 ( struct V_81 * V_82 )
{
struct V_61 * V_46 =
F_65 ( V_82 , struct V_61 , V_110 ) ;
struct V_4 * V_5 ;
int V_3 ;
F_41 ( V_46 -> V_25 , L_20 ) ;
F_56 ( V_46 -> V_79 , V_111 ) ;
if ( V_46 -> V_112 )
V_46 -> V_112 ( V_46 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_86 ; V_3 ++ ) {
struct V_59 * V_95 = V_46 -> V_29 [ V_3 ] . V_95 ;
if ( V_46 -> V_29 [ V_3 ] . V_66 -> V_90 )
continue;
if ( V_95 -> V_10 -> V_113 && V_95 -> V_10 -> V_97 )
V_95 -> V_10 -> V_113 ( V_95 ) ;
}
F_33 (codec, &card->codec_dev_list, card_list) {
if ( V_5 -> V_10 -> V_113 && V_5 -> V_98 ) {
switch ( V_5 -> V_53 . V_101 ) {
case V_105 :
case V_107 :
V_5 -> V_10 -> V_113 ( V_5 ) ;
V_5 -> V_98 = 0 ;
break;
default:
F_41 ( V_5 -> V_25 ,
L_21 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_46 -> V_86 ; V_3 ++ ) {
if ( V_46 -> V_29 [ V_3 ] . V_66 -> V_90 )
continue;
F_59 ( & V_46 -> V_29 [ V_3 ] ,
V_102 ,
V_114 ) ;
F_59 ( & V_46 -> V_29 [ V_3 ] ,
V_104 ,
V_114 ) ;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_86 ; V_3 ++ ) {
struct V_59 * V_60 = V_46 -> V_29 [ V_3 ] . V_87 ;
struct V_88 * V_89 = V_60 -> V_10 ;
if ( V_46 -> V_29 [ V_3 ] . V_66 -> V_90 )
continue;
if ( V_89 -> V_91 -> V_92 && V_60 -> V_93 )
V_89 -> V_91 -> V_92 ( V_60 , 0 ) ;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_86 ; V_3 ++ ) {
struct V_59 * V_95 = V_46 -> V_29 [ V_3 ] . V_95 ;
struct V_54 * V_55 = V_46 -> V_29 [ V_3 ] . V_55 ;
if ( V_46 -> V_29 [ V_3 ] . V_66 -> V_90 )
continue;
if ( V_95 -> V_10 -> V_113 && ! V_95 -> V_10 -> V_97 )
V_95 -> V_10 -> V_113 ( V_95 ) ;
if ( V_55 -> V_10 -> V_113 && V_55 -> V_98 ) {
V_55 -> V_10 -> V_113 ( V_95 ) ;
V_55 -> V_98 = 0 ;
}
}
if ( V_46 -> V_115 )
V_46 -> V_115 ( V_46 ) ;
F_41 ( V_46 -> V_25 , L_22 ) ;
F_56 ( V_46 -> V_79 , V_84 ) ;
F_60 ( & V_46 -> V_53 ) ;
F_61 ( & V_46 -> V_53 ) ;
}
int F_66 ( struct V_24 * V_25 )
{
struct V_61 * V_46 = F_8 ( V_25 ) ;
int V_3 , V_97 = 0 ;
if ( F_52 ( & V_46 -> V_83 ) )
return 0 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_86 ; V_3 ++ ) {
struct V_59 * V_95 = V_46 -> V_29 [ V_3 ] . V_95 ;
struct V_59 * V_87 = V_46 -> V_29 [ V_3 ] . V_87 ;
if ( V_95 -> V_116 )
F_67 ( V_95 -> V_25 ) ;
if ( V_87 -> V_116 )
F_67 ( V_87 -> V_25 ) ;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_86 ; V_3 ++ ) {
struct V_59 * V_95 = V_46 -> V_29 [ V_3 ] . V_95 ;
V_97 |= V_95 -> V_10 -> V_97 ;
}
if ( V_97 ) {
F_41 ( V_25 , L_23 ) ;
F_64 ( & V_46 -> V_110 ) ;
} else {
F_41 ( V_25 , L_24 ) ;
if ( ! F_68 ( & V_46 -> V_110 ) )
F_49 ( V_25 , L_25 ) ;
}
return 0 ;
}
static struct V_4 * F_69 ( const struct V_117 * V_118 ,
const char * V_119 )
{
struct V_4 * V_5 ;
F_33 (codec, &codec_list, list) {
if ( V_118 ) {
if ( V_5 -> V_25 -> V_120 != V_118 )
continue;
} else {
if ( strcmp ( V_5 -> V_48 , V_119 ) )
continue;
}
return V_5 ;
}
return NULL ;
}
static struct V_59 * F_70 ( struct V_4 * V_5 ,
const char * V_121 )
{
struct V_59 * V_87 ;
F_33 (codec_dai, &codec->component.dai_list, list) {
if ( ! strcmp ( V_87 -> V_48 , V_121 ) ) {
return V_87 ;
}
}
return NULL ;
}
static int F_71 ( struct V_61 * V_46 , int V_122 )
{
struct V_123 * V_66 = & V_46 -> V_66 [ V_122 ] ;
struct V_28 * V_29 = & V_46 -> V_29 [ V_122 ] ;
struct V_57 * V_58 ;
struct V_54 * V_55 ;
struct V_59 * V_95 ;
const char * V_124 ;
F_41 ( V_46 -> V_25 , L_26 , V_66 -> V_48 , V_122 ) ;
F_33 (component, &component_list, list) {
if ( V_66 -> V_125 &&
V_58 -> V_25 -> V_120 != V_66 -> V_125 )
continue;
if ( V_66 -> V_126 &&
strcmp ( F_72 ( V_58 -> V_25 ) , V_66 -> V_126 ) )
continue;
F_33 (cpu_dai, &component->dai_list, list) {
if ( V_66 -> V_127 &&
strcmp ( V_95 -> V_48 , V_66 -> V_127 ) )
continue;
V_29 -> V_95 = V_95 ;
}
}
if ( ! V_29 -> V_95 ) {
F_49 ( V_46 -> V_25 , L_27 ,
V_66 -> V_127 ) ;
return - V_128 ;
}
V_29 -> V_5 = F_69 ( V_66 -> V_118 ,
V_66 -> V_119 ) ;
if ( ! V_29 -> V_5 ) {
F_49 ( V_46 -> V_25 , L_28 ,
V_66 -> V_119 ) ;
return - V_128 ;
}
V_29 -> V_87 = F_70 ( V_29 -> V_5 ,
V_66 -> V_121 ) ;
if ( ! V_29 -> V_87 ) {
F_49 ( V_46 -> V_25 , L_29 ,
V_66 -> V_121 ) ;
return - V_128 ;
}
V_124 = V_66 -> V_124 ;
if ( ! V_124 && ! V_66 -> V_129 )
V_124 = L_30 ;
F_33 (platform, &platform_list, list) {
if ( V_66 -> V_129 ) {
if ( V_55 -> V_25 -> V_120 !=
V_66 -> V_129 )
continue;
} else {
if ( strcmp ( V_55 -> V_48 , V_124 ) )
continue;
}
V_29 -> V_55 = V_55 ;
}
if ( ! V_29 -> V_55 ) {
F_49 ( V_46 -> V_25 , L_31 ,
V_66 -> V_124 ) ;
return - V_128 ;
}
V_46 -> V_86 ++ ;
return 0 ;
}
static int F_73 ( struct V_54 * V_55 )
{
int V_14 ;
if ( V_55 -> V_10 -> remove ) {
V_14 = V_55 -> V_10 -> remove ( V_55 ) ;
if ( V_14 < 0 )
F_49 ( V_55 -> V_25 , L_32 ,
V_14 ) ;
}
F_74 ( & V_55 -> V_53 ) ;
F_31 ( V_55 ) ;
V_55 -> V_130 = 0 ;
F_75 ( & V_55 -> V_131 ) ;
F_76 ( V_55 -> V_25 -> V_10 -> V_132 ) ;
return 0 ;
}
static void F_77 ( struct V_4 * V_5 )
{
int V_75 ;
if ( V_5 -> V_10 -> remove ) {
V_75 = V_5 -> V_10 -> remove ( V_5 ) ;
if ( V_75 < 0 )
F_49 ( V_5 -> V_25 , L_32 , V_75 ) ;
}
F_74 ( & V_5 -> V_53 ) ;
F_28 ( V_5 ) ;
V_5 -> V_130 = 0 ;
F_75 ( & V_5 -> V_131 ) ;
F_76 ( V_5 -> V_25 -> V_10 -> V_132 ) ;
}
static void F_78 ( struct V_59 * V_87 , int V_133 )
{
int V_75 ;
if ( V_87 && V_87 -> V_130 &&
V_87 -> V_10 -> V_134 == V_133 ) {
if ( V_87 -> V_10 -> remove ) {
V_75 = V_87 -> V_10 -> remove ( V_87 ) ;
if ( V_75 < 0 )
F_49 ( V_87 -> V_25 ,
L_33 ,
V_87 -> V_48 , V_75 ) ;
}
V_87 -> V_130 = 0 ;
}
}
static void F_79 ( struct V_61 * V_46 , int V_122 , int V_133 )
{
struct V_28 * V_29 = & V_46 -> V_29 [ V_122 ] ;
struct V_59 * V_87 = V_29 -> V_87 , * V_95 = V_29 -> V_95 ;
int V_75 ;
if ( V_29 -> V_135 ) {
F_80 ( V_29 -> V_25 , & V_136 ) ;
F_80 ( V_29 -> V_25 , & V_137 ) ;
F_44 ( V_29 -> V_25 ) ;
V_29 -> V_135 = 0 ;
}
F_78 ( V_87 , V_133 ) ;
if ( V_95 && V_95 -> V_130 &&
V_95 -> V_10 -> V_134 == V_133 ) {
if ( V_95 -> V_10 -> remove ) {
V_75 = V_95 -> V_10 -> remove ( V_95 ) ;
if ( V_75 < 0 )
F_49 ( V_95 -> V_25 ,
L_33 ,
V_95 -> V_48 , V_75 ) ;
}
V_95 -> V_130 = 0 ;
if ( ! V_95 -> V_5 ) {
F_74 ( & V_95 -> V_53 ) ;
F_76 ( V_95 -> V_25 -> V_10 -> V_132 ) ;
}
}
}
static void F_81 ( struct V_61 * V_46 , int V_122 ,
int V_133 )
{
struct V_28 * V_29 = & V_46 -> V_29 [ V_122 ] ;
struct V_59 * V_95 = V_29 -> V_95 ;
struct V_59 * V_87 = V_29 -> V_87 ;
struct V_54 * V_55 = V_29 -> V_55 ;
struct V_4 * V_5 ;
if ( V_55 && V_55 -> V_130 &&
V_55 -> V_10 -> V_134 == V_133 ) {
F_73 ( V_55 ) ;
}
if ( V_87 ) {
V_5 = V_87 -> V_5 ;
if ( V_5 && V_5 -> V_130 &&
V_5 -> V_10 -> V_134 == V_133 )
F_77 ( V_5 ) ;
}
if ( V_95 ) {
V_5 = V_95 -> V_5 ;
if ( V_5 && V_5 -> V_130 &&
V_5 -> V_10 -> V_134 == V_133 )
F_77 ( V_5 ) ;
}
}
static void F_82 ( struct V_61 * V_46 )
{
int V_60 , V_133 ;
for ( V_133 = V_138 ; V_133 <= V_139 ;
V_133 ++ ) {
for ( V_60 = 0 ; V_60 < V_46 -> V_86 ; V_60 ++ )
F_79 ( V_46 , V_60 , V_133 ) ;
}
for ( V_133 = V_138 ; V_133 <= V_139 ;
V_133 ++ ) {
for ( V_60 = 0 ; V_60 < V_46 -> V_86 ; V_60 ++ )
F_81 ( V_46 , V_60 , V_133 ) ;
}
V_46 -> V_86 = 0 ;
}
static void F_83 ( struct V_61 * V_46 ,
struct V_4 * V_5 )
{
int V_3 ;
if ( V_46 -> V_140 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_46 -> V_141 ; V_3 ++ ) {
struct V_142 * V_143 = & V_46 -> V_140 [ V_3 ] ;
if ( V_143 -> V_120 && V_5 -> V_25 -> V_120 != V_143 -> V_120 )
continue;
if ( V_143 -> F_72 && strcmp ( V_5 -> V_48 , V_143 -> F_72 ) )
continue;
V_5 -> V_144 = V_143 -> V_144 ;
break;
}
}
static int F_84 ( struct V_61 * V_46 ,
struct V_4 * V_5 )
{
int V_14 = 0 ;
const struct V_145 * V_10 = V_5 -> V_10 ;
struct V_59 * V_60 ;
V_5 -> V_46 = V_46 ;
V_5 -> V_53 . V_46 = V_46 ;
F_83 ( V_46 , V_5 ) ;
if ( ! F_85 ( V_5 -> V_25 -> V_10 -> V_132 ) )
return - V_146 ;
F_22 ( V_5 ) ;
if ( V_10 -> V_147 ) {
V_14 = F_86 ( & V_5 -> V_53 ,
V_10 -> V_147 ,
V_10 -> V_148 ) ;
if ( V_14 != 0 ) {
F_49 ( V_5 -> V_25 ,
L_34 , V_14 ) ;
goto V_149;
}
}
F_33 (dai, &codec->component.dai_list, list) {
V_14 = F_87 ( & V_5 -> V_53 , V_60 ) ;
if ( V_14 != 0 ) {
F_49 ( V_5 -> V_25 ,
L_35 , V_14 ) ;
goto V_149;
}
}
V_5 -> V_53 . V_106 = V_10 -> V_106 ;
if ( V_10 -> V_150 ) {
V_14 = V_10 -> V_150 ( V_5 ) ;
if ( V_14 < 0 ) {
F_49 ( V_5 -> V_25 ,
L_36 , V_14 ) ;
goto V_149;
}
F_88 ( V_5 -> V_53 . V_106 &&
V_5 -> V_53 . V_101 != V_107 ,
L_37 ,
V_5 -> V_48 ) ;
}
if ( V_10 -> V_151 )
F_89 ( V_5 , V_10 -> V_151 ,
V_10 -> V_152 ) ;
if ( V_10 -> V_153 )
F_90 ( & V_5 -> V_53 , V_10 -> V_153 ,
V_10 -> V_154 ) ;
V_5 -> V_130 = 1 ;
F_91 ( & V_5 -> V_131 , & V_46 -> V_83 ) ;
F_91 ( & V_5 -> V_53 . V_155 , & V_46 -> V_156 ) ;
return 0 ;
V_149:
F_28 ( V_5 ) ;
F_76 ( V_5 -> V_25 -> V_10 -> V_132 ) ;
return V_14 ;
}
static int F_92 ( struct V_61 * V_46 ,
struct V_54 * V_55 )
{
int V_14 = 0 ;
const struct V_157 * V_10 = V_55 -> V_10 ;
struct V_57 * V_58 ;
struct V_59 * V_60 ;
V_55 -> V_46 = V_46 ;
V_55 -> V_53 . V_46 = V_46 ;
if ( ! F_85 ( V_55 -> V_25 -> V_10 -> V_132 ) )
return - V_146 ;
F_30 ( V_55 ) ;
if ( V_10 -> V_147 )
F_86 ( & V_55 -> V_53 ,
V_10 -> V_147 , V_10 -> V_148 ) ;
F_33 (component, &component_list, list) {
if ( V_58 -> V_25 != V_55 -> V_25 )
continue;
F_33 (dai, &component->dai_list, list)
F_87 ( & V_55 -> V_53 , V_60 ) ;
}
V_55 -> V_53 . V_106 = 1 ;
if ( V_10 -> V_150 ) {
V_14 = V_10 -> V_150 ( V_55 ) ;
if ( V_14 < 0 ) {
F_49 ( V_55 -> V_25 ,
L_38 , V_14 ) ;
goto V_149;
}
}
if ( V_10 -> V_151 )
F_93 ( V_55 , V_10 -> V_151 ,
V_10 -> V_152 ) ;
if ( V_10 -> V_153 )
F_90 ( & V_55 -> V_53 , V_10 -> V_153 ,
V_10 -> V_154 ) ;
V_55 -> V_130 = 1 ;
F_91 ( & V_55 -> V_131 , & V_46 -> V_158 ) ;
F_91 ( & V_55 -> V_53 . V_155 , & V_46 -> V_156 ) ;
return 0 ;
V_149:
F_31 ( V_55 ) ;
F_76 ( V_55 -> V_25 -> V_10 -> V_132 ) ;
return V_14 ;
}
static void F_94 ( struct V_24 * V_25 )
{
F_15 ( V_25 ) ;
}
static int F_95 ( struct V_61 * V_46 ,
struct V_4 * V_5 ,
int V_122 )
{
struct V_159 * V_160 = & V_46 -> V_160 [ V_122 ] ;
struct V_28 * V_29 = & V_46 -> V_161 [ V_122 ] ;
int V_14 ;
V_29 -> V_46 = V_46 ;
if ( V_160 -> V_162 ) {
V_14 = V_160 -> V_162 ( & V_5 -> V_53 ) ;
if ( V_14 < 0 )
return V_14 ;
}
V_29 -> V_5 = V_5 ;
return 0 ;
}
static int F_96 ( struct V_61 * V_46 ,
struct V_4 * V_5 ,
int V_122 )
{
struct V_123 * V_66 = & V_46 -> V_66 [ V_122 ] ;
struct V_28 * V_29 = & V_46 -> V_29 [ V_122 ] ;
int V_14 ;
V_29 -> V_46 = V_46 ;
if ( V_66 -> V_162 ) {
V_14 = V_66 -> V_162 ( V_29 ) ;
if ( V_14 < 0 )
return V_14 ;
}
V_29 -> V_5 = V_5 ;
return 0 ;
}
static int F_97 ( struct V_61 * V_46 ,
struct V_4 * V_5 ,
int V_122 , int V_163 )
{
struct V_123 * V_66 = NULL ;
struct V_159 * V_160 = NULL ;
struct V_28 * V_29 ;
const char * V_48 ;
int V_14 = 0 ;
if ( ! V_163 ) {
V_66 = & V_46 -> V_66 [ V_122 ] ;
V_29 = & V_46 -> V_29 [ V_122 ] ;
V_48 = V_66 -> V_48 ;
V_14 = F_96 ( V_46 , V_5 , V_122 ) ;
} else {
V_160 = & V_46 -> V_160 [ V_122 ] ;
V_29 = & V_46 -> V_161 [ V_122 ] ;
V_48 = V_160 -> V_48 ;
V_14 = F_95 ( V_46 , V_5 , V_122 ) ;
}
if ( V_14 < 0 ) {
F_49 ( V_46 -> V_25 , L_39 , V_48 , V_14 ) ;
return V_14 ;
}
V_29 -> V_25 = F_98 ( sizeof( struct V_24 ) , V_36 ) ;
if ( ! V_29 -> V_25 )
return - V_37 ;
F_99 ( V_29 -> V_25 ) ;
V_29 -> V_25 -> V_77 = V_46 -> V_25 ;
V_29 -> V_25 -> V_78 = F_94 ;
V_29 -> V_25 -> V_164 = V_48 ;
F_100 ( V_29 -> V_25 , V_29 ) ;
F_101 ( & V_29 -> V_165 ) ;
F_102 ( & V_29 -> V_166 [ V_102 ] . V_167 ) ;
F_102 ( & V_29 -> V_166 [ V_104 ] . V_167 ) ;
F_102 ( & V_29 -> V_166 [ V_102 ] . V_168 ) ;
F_102 ( & V_29 -> V_166 [ V_104 ] . V_168 ) ;
V_14 = F_103 ( V_29 -> V_25 ) ;
if ( V_14 < 0 ) {
F_104 ( V_29 -> V_25 ) ;
F_49 ( V_46 -> V_25 ,
L_40 , V_14 ) ;
return V_14 ;
}
V_29 -> V_135 = 1 ;
V_14 = F_105 ( V_29 -> V_25 ) ;
if ( V_14 < 0 )
F_49 ( V_5 -> V_25 ,
L_41 , V_14 ) ;
V_14 = F_106 ( V_29 -> V_25 , & V_137 ) ;
if ( V_14 < 0 )
F_49 ( V_5 -> V_25 ,
L_42 , V_14 ) ;
#ifdef F_107
if ( ! V_163 && ! V_66 -> V_169 )
goto V_170;
V_14 = F_108 ( V_29 ) ;
if ( V_14 < 0 )
F_49 ( V_29 -> V_25 , L_43 , V_14 ) ;
V_170:
#endif
return 0 ;
}
static int F_109 ( struct V_61 * V_46 , int V_122 ,
int V_133 )
{
struct V_28 * V_29 = & V_46 -> V_29 [ V_122 ] ;
struct V_59 * V_95 = V_29 -> V_95 ;
struct V_59 * V_87 = V_29 -> V_87 ;
struct V_54 * V_55 = V_29 -> V_55 ;
int V_14 ;
if ( V_95 -> V_5 &&
! V_95 -> V_5 -> V_130 &&
V_95 -> V_5 -> V_10 -> V_171 == V_133 ) {
V_14 = F_84 ( V_46 , V_95 -> V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_87 -> V_5 -> V_130 &&
V_87 -> V_5 -> V_10 -> V_171 == V_133 ) {
V_14 = F_84 ( V_46 , V_87 -> V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_55 -> V_130 &&
V_55 -> V_10 -> V_171 == V_133 ) {
V_14 = F_92 ( V_46 , V_55 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
static int F_110 ( struct V_61 * V_46 ,
struct V_59 * V_87 ,
int V_133 )
{
int V_14 ;
if ( ! V_87 -> V_130 && V_87 -> V_10 -> V_171 == V_133 ) {
if ( V_87 -> V_10 -> V_150 ) {
V_14 = V_87 -> V_10 -> V_150 ( V_87 ) ;
if ( V_14 < 0 ) {
F_49 ( V_87 -> V_25 ,
L_44 ,
V_87 -> V_48 , V_14 ) ;
return V_14 ;
}
}
V_87 -> V_130 = 1 ;
}
return 0 ;
}
static int F_111 ( struct V_61 * V_46 ,
struct V_123 * V_66 ,
struct V_59 * V_95 ,
struct V_59 * V_87 )
{
struct V_172 * V_173 , * V_174 ;
int V_14 ;
V_173 = V_87 -> V_175 ;
V_174 = V_95 -> V_176 ;
if ( V_173 && V_174 ) {
V_14 = F_112 ( V_46 , V_66 -> V_177 ,
V_174 , V_173 ) ;
if ( V_14 != 0 ) {
F_49 ( V_46 -> V_25 , L_45 ,
V_173 -> V_48 , V_174 -> V_48 , V_14 ) ;
return V_14 ;
}
}
V_173 = V_95 -> V_175 ;
V_174 = V_87 -> V_176 ;
if ( V_173 && V_174 ) {
V_14 = F_112 ( V_46 , V_66 -> V_177 ,
V_174 , V_173 ) ;
if ( V_14 != 0 ) {
F_49 ( V_46 -> V_25 , L_45 ,
V_173 -> V_48 , V_174 -> V_48 , V_14 ) ;
return V_14 ;
}
}
return 0 ;
}
static int F_113 ( struct V_61 * V_46 , int V_122 , int V_133 )
{
struct V_123 * V_66 = & V_46 -> V_66 [ V_122 ] ;
struct V_28 * V_29 = & V_46 -> V_29 [ V_122 ] ;
struct V_4 * V_5 = V_29 -> V_5 ;
struct V_54 * V_55 = V_29 -> V_55 ;
struct V_59 * V_87 = V_29 -> V_87 ;
struct V_59 * V_95 = V_29 -> V_95 ;
int V_14 ;
F_41 ( V_46 -> V_25 , L_46 ,
V_46 -> V_48 , V_122 , V_133 ) ;
V_95 -> V_55 = V_55 ;
V_87 -> V_46 = V_46 ;
V_95 -> V_46 = V_46 ;
V_29 -> V_31 = V_31 ;
if ( ! V_95 -> V_130 &&
V_95 -> V_10 -> V_171 == V_133 ) {
if ( ! V_95 -> V_5 ) {
V_95 -> V_53 . V_46 = V_46 ;
if ( ! F_85 ( V_95 -> V_25 -> V_10 -> V_132 ) )
return - V_146 ;
F_91 ( & V_95 -> V_53 . V_155 , & V_46 -> V_156 ) ;
}
if ( V_95 -> V_10 -> V_150 ) {
V_14 = V_95 -> V_10 -> V_150 ( V_95 ) ;
if ( V_14 < 0 ) {
F_49 ( V_95 -> V_25 ,
L_47 ,
V_95 -> V_48 , V_14 ) ;
F_76 ( V_95 -> V_25 -> V_10 -> V_132 ) ;
return V_14 ;
}
}
V_95 -> V_130 = 1 ;
}
V_14 = F_110 ( V_46 , V_87 , V_133 ) ;
if ( V_14 )
return V_14 ;
if ( V_133 != V_139 )
return 0 ;
V_14 = F_97 ( V_46 , V_5 , V_122 , 0 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_106 ( V_29 -> V_25 , & V_136 ) ;
if ( V_14 < 0 )
F_24 ( V_29 -> V_25 , L_48 ,
V_14 ) ;
if ( V_95 -> V_10 -> V_178 ) {
V_14 = F_114 ( V_29 , V_122 ) ;
if ( V_14 < 0 ) {
F_49 ( V_46 -> V_25 , L_49 ,
V_66 -> V_179 ) ;
return V_14 ;
}
} else {
if ( ! V_66 -> V_177 ) {
V_14 = F_115 ( V_29 , V_122 ) ;
if ( V_14 < 0 ) {
F_49 ( V_46 -> V_25 , L_50 ,
V_66 -> V_179 , V_14 ) ;
return V_14 ;
}
} else {
F_116 ( & V_29 -> V_99 ,
F_50 ) ;
V_14 = F_111 ( V_46 , V_66 ,
V_95 , V_87 ) ;
if ( V_14 )
return V_14 ;
}
}
if ( V_29 -> V_87 -> V_10 -> V_97 )
F_117 ( V_5 -> V_73 , V_29 -> V_95 -> V_180 ) ;
return 0 ;
}
static int F_118 ( struct V_4 * V_5 ,
struct V_59 * V_87 )
{
int V_14 ;
if ( V_87 -> V_10 -> V_97 && ! V_5 -> V_181 ) {
if ( ! V_5 -> V_182 )
return 0 ;
V_14 = F_46 ( V_5 ) ;
if ( V_14 < 0 ) {
F_49 ( V_5 -> V_25 ,
L_51 , V_14 ) ;
return V_14 ;
}
V_5 -> V_181 = 1 ;
}
return 0 ;
}
static int F_119 ( struct V_28 * V_29 )
{
return F_118 ( V_29 -> V_5 , V_29 -> V_87 ) ;
}
static void F_120 ( struct V_4 * V_5 )
{
if ( V_5 -> V_181 ) {
F_43 ( V_5 ) ;
V_5 -> V_181 = 0 ;
}
}
static void F_121 ( struct V_28 * V_29 )
{
F_120 ( V_29 -> V_5 ) ;
}
static struct V_4 * F_122 ( struct V_61 * V_46 ,
int V_122 )
{
struct V_159 * V_160 = & V_46 -> V_160 [ V_122 ] ;
struct V_4 * V_5 ;
F_33 (codec, &codec_list, list) {
if ( V_160 -> V_118 &&
( V_5 -> V_25 -> V_120 != V_160 -> V_118 ) )
continue;
if ( V_160 -> V_119 && strcmp ( V_5 -> V_48 , V_160 -> V_119 ) )
continue;
return V_5 ;
}
return NULL ;
}
static int F_123 ( struct V_61 * V_46 , int V_122 )
{
struct V_159 * V_160 = & V_46 -> V_160 [ V_122 ] ;
const char * V_183 = V_160 -> V_119 ;
struct V_4 * V_5 = F_122 ( V_46 , V_122 ) ;
if ( V_5 )
return 0 ;
if ( V_160 -> V_118 )
V_183 = F_124 ( V_160 -> V_118 ) ;
F_49 ( V_46 -> V_25 , L_52 , V_183 ) ;
return - V_128 ;
}
static int F_125 ( struct V_61 * V_46 , int V_122 )
{
struct V_159 * V_160 = & V_46 -> V_160 [ V_122 ] ;
const char * V_183 = V_160 -> V_119 ;
int V_14 = - V_146 ;
struct V_4 * V_5 = F_122 ( V_46 , V_122 ) ;
if ( ! V_5 ) {
if ( V_160 -> V_118 )
V_183 = F_124 ( V_160 -> V_118 ) ;
F_49 ( V_46 -> V_25 , L_53 , V_183 ) ;
return - V_128 ;
}
if ( V_5 -> V_130 ) {
F_49 ( V_5 -> V_25 , L_54 ) ;
return - V_184 ;
}
V_14 = F_84 ( V_46 , V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_97 ( V_46 , V_5 , V_122 , 1 ) ;
return V_14 ;
}
static void F_126 ( struct V_61 * V_46 , int V_122 )
{
struct V_28 * V_29 = & V_46 -> V_161 [ V_122 ] ;
struct V_4 * V_5 = V_29 -> V_5 ;
if ( V_29 -> V_135 ) {
F_80 ( V_29 -> V_25 , & V_137 ) ;
F_44 ( V_29 -> V_25 ) ;
V_29 -> V_135 = 0 ;
}
if ( V_5 && V_5 -> V_130 )
F_77 ( V_5 ) ;
}
static int F_127 ( struct V_4 * V_5 )
{
int V_14 ;
if ( V_5 -> V_185 )
return 0 ;
V_14 = F_128 ( V_5 ) ;
if ( V_14 < 0 ) {
F_49 ( V_5 -> V_25 ,
L_55 ,
V_14 ) ;
return V_14 ;
}
V_5 -> V_185 = 1 ;
return 0 ;
}
static int F_129 ( struct V_61 * V_46 )
{
struct V_4 * V_5 ;
struct V_123 * V_66 ;
int V_14 , V_3 , V_133 , V_186 ;
F_130 ( & V_46 -> V_187 , V_188 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_68 ; V_3 ++ ) {
V_14 = F_71 ( V_46 , V_3 ) ;
if ( V_14 != 0 )
goto V_189;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_190 ; V_3 ++ ) {
V_14 = F_123 ( V_46 , V_3 ) ;
if ( V_14 != 0 )
goto V_189;
}
F_33 (codec, &codec_list, list) {
if ( V_5 -> V_185 )
continue;
V_14 = F_127 ( V_5 ) ;
if ( V_14 < 0 )
goto V_189;
}
V_14 = F_131 ( V_46 -> V_25 , V_191 , V_192 ,
V_46 -> V_132 , 0 , & V_46 -> V_79 ) ;
if ( V_14 < 0 ) {
F_49 ( V_46 -> V_25 ,
L_56 ,
V_46 -> V_48 , V_14 ) ;
goto V_189;
}
V_46 -> V_53 . V_101 = V_107 ;
V_46 -> V_53 . V_25 = V_46 -> V_25 ;
V_46 -> V_53 . V_46 = V_46 ;
F_91 ( & V_46 -> V_53 . V_155 , & V_46 -> V_156 ) ;
#ifdef F_107
F_27 ( & V_46 -> V_53 , V_46 -> V_45 ) ;
#endif
#ifdef F_132
F_133 ( & V_46 -> V_110 , F_64 ) ;
#endif
if ( V_46 -> V_147 )
F_86 ( & V_46 -> V_53 , V_46 -> V_147 ,
V_46 -> V_148 ) ;
if ( V_46 -> V_150 ) {
V_14 = V_46 -> V_150 ( V_46 ) ;
if ( V_14 < 0 )
goto V_193;
}
for ( V_133 = V_138 ; V_133 <= V_139 ;
V_133 ++ ) {
for ( V_3 = 0 ; V_3 < V_46 -> V_68 ; V_3 ++ ) {
V_14 = F_109 ( V_46 , V_3 , V_133 ) ;
if ( V_14 < 0 ) {
F_49 ( V_46 -> V_25 ,
L_57 ,
V_14 ) ;
goto V_194;
}
}
}
for ( V_133 = V_138 ; V_133 <= V_139 ;
V_133 ++ ) {
for ( V_3 = 0 ; V_3 < V_46 -> V_68 ; V_3 ++ ) {
V_14 = F_113 ( V_46 , V_3 , V_133 ) ;
if ( V_14 < 0 ) {
F_49 ( V_46 -> V_25 ,
L_57 ,
V_14 ) ;
goto V_194;
}
}
}
for ( V_3 = 0 ; V_3 < V_46 -> V_190 ; V_3 ++ ) {
V_14 = F_125 ( V_46 , V_3 ) ;
if ( V_14 < 0 ) {
F_49 ( V_46 -> V_25 ,
L_58 ,
V_14 ) ;
goto V_195;
}
}
F_134 ( V_46 ) ;
F_135 ( V_46 ) ;
if ( V_46 -> V_151 )
F_136 ( V_46 , V_46 -> V_151 , V_46 -> V_152 ) ;
if ( V_46 -> V_153 )
F_90 ( & V_46 -> V_53 , V_46 -> V_153 ,
V_46 -> V_154 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_68 ; V_3 ++ ) {
V_66 = & V_46 -> V_66 [ V_3 ] ;
V_186 = V_66 -> V_186 ;
if ( V_186 ) {
V_14 = F_137 ( V_46 -> V_29 [ V_3 ] . V_87 ,
V_186 ) ;
if ( V_14 != 0 && V_14 != - V_196 )
F_24 ( V_46 -> V_29 [ V_3 ] . V_87 -> V_25 ,
L_59 ,
V_14 ) ;
}
if ( V_186 &&
( V_66 -> V_124 || V_66 -> V_129 ) ) {
V_14 = F_137 ( V_46 -> V_29 [ V_3 ] . V_95 ,
V_186 ) ;
if ( V_14 != 0 && V_14 != - V_196 )
F_24 ( V_46 -> V_29 [ V_3 ] . V_95 -> V_25 ,
L_59 ,
V_14 ) ;
} else if ( V_186 ) {
V_186 &= ~ V_197 ;
switch ( V_66 -> V_186 &
V_197 ) {
case V_198 :
V_186 |= V_199 ;
break;
case V_200 :
V_186 |= V_201 ;
break;
case V_201 :
V_186 |= V_200 ;
break;
case V_199 :
V_186 |= V_198 ;
break;
}
V_14 = F_137 ( V_46 -> V_29 [ V_3 ] . V_95 ,
V_186 ) ;
if ( V_14 != 0 && V_14 != - V_196 )
F_24 ( V_46 -> V_29 [ V_3 ] . V_95 -> V_25 ,
L_59 ,
V_14 ) ;
}
}
snprintf ( V_46 -> V_79 -> V_202 , sizeof( V_46 -> V_79 -> V_202 ) ,
L_60 , V_46 -> V_48 ) ;
snprintf ( V_46 -> V_79 -> V_203 , sizeof( V_46 -> V_79 -> V_203 ) ,
L_60 , V_46 -> V_204 ? V_46 -> V_204 : V_46 -> V_48 ) ;
snprintf ( V_46 -> V_79 -> V_10 , sizeof( V_46 -> V_79 -> V_10 ) ,
L_60 , V_46 -> V_205 ? V_46 -> V_205 : V_46 -> V_48 ) ;
for ( V_3 = 0 ; V_3 < F_138 ( V_46 -> V_79 -> V_10 ) ; V_3 ++ ) {
switch ( V_46 -> V_79 -> V_10 [ V_3 ] ) {
case '_' :
case '-' :
case '\0' :
break;
default:
if ( ! isalnum ( V_46 -> V_79 -> V_10 [ V_3 ] ) )
V_46 -> V_79 -> V_10 [ V_3 ] = '_' ;
break;
}
}
if ( V_46 -> V_206 ) {
V_14 = V_46 -> V_206 ( V_46 ) ;
if ( V_14 < 0 ) {
F_49 ( V_46 -> V_25 , L_61 ,
V_46 -> V_48 , V_14 ) ;
goto V_195;
}
}
if ( V_46 -> V_207 )
F_33 (codec, &card->codec_dev_list, card_list)
F_139 ( V_5 ) ;
F_140 ( V_46 ) ;
V_14 = F_141 ( V_46 -> V_79 ) ;
if ( V_14 < 0 ) {
F_49 ( V_46 -> V_25 , L_62 ,
V_14 ) ;
goto V_195;
}
#ifdef F_142
for ( V_3 = 0 ; V_3 < V_46 -> V_86 ; V_3 ++ ) {
V_14 = F_119 ( & V_46 -> V_29 [ V_3 ] ) ;
if ( V_14 < 0 ) {
F_49 ( V_46 -> V_25 ,
L_63 , V_14 ) ;
while ( -- V_3 >= 0 )
F_121 ( & V_46 -> V_29 [ V_3 ] ) ;
goto V_195;
}
}
#endif
V_46 -> V_208 = 1 ;
F_61 ( & V_46 -> V_53 ) ;
F_143 ( & V_46 -> V_187 ) ;
return 0 ;
V_195:
for ( V_3 = 0 ; V_3 < V_46 -> V_190 ; V_3 ++ )
F_126 ( V_46 , V_3 ) ;
V_194:
F_82 ( V_46 ) ;
V_193:
if ( V_46 -> remove )
V_46 -> remove ( V_46 ) ;
F_144 ( V_46 -> V_79 ) ;
V_189:
F_143 ( & V_46 -> V_187 ) ;
return V_14 ;
}
static int F_145 ( struct V_209 * V_210 )
{
struct V_61 * V_46 = F_146 ( V_210 ) ;
if ( ! V_46 )
return - V_17 ;
F_24 ( & V_210 -> V_25 ,
L_64 ,
V_46 -> V_48 ) ;
V_46 -> V_25 = & V_210 -> V_25 ;
return F_147 ( V_46 ) ;
}
static int F_148 ( struct V_61 * V_46 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_86 ; V_3 ++ ) {
struct V_28 * V_29 = & V_46 -> V_29 [ V_3 ] ;
F_58 ( & V_29 -> V_99 ) ;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_190 ; V_3 ++ )
F_126 ( V_46 , V_3 ) ;
F_82 ( V_46 ) ;
F_39 ( V_46 ) ;
if ( V_46 -> remove )
V_46 -> remove ( V_46 ) ;
F_74 ( & V_46 -> V_53 ) ;
F_144 ( V_46 -> V_79 ) ;
return 0 ;
}
static int F_149 ( struct V_209 * V_210 )
{
struct V_61 * V_46 = F_146 ( V_210 ) ;
F_150 ( V_46 ) ;
return 0 ;
}
int F_151 ( struct V_24 * V_25 )
{
struct V_61 * V_46 = F_8 ( V_25 ) ;
int V_3 ;
if ( ! V_46 -> V_208 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_86 ; V_3 ++ ) {
struct V_28 * V_29 = & V_46 -> V_29 [ V_3 ] ;
F_58 ( & V_29 -> V_99 ) ;
}
F_152 ( V_46 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_86 ; V_3 ++ ) {
struct V_59 * V_95 = V_46 -> V_29 [ V_3 ] . V_95 ;
struct V_59 * V_87 = V_46 -> V_29 [ V_3 ] . V_87 ;
F_63 ( V_87 -> V_25 ) ;
F_63 ( V_95 -> V_25 ) ;
}
return 0 ;
}
int F_153 ( struct V_4 * V_5 ,
struct V_211 * V_91 , int V_122 )
{
F_154 ( & V_5 -> V_187 ) ;
V_5 -> V_73 = F_98 ( sizeof( struct V_212 ) , V_36 ) ;
if ( V_5 -> V_73 == NULL ) {
F_143 ( & V_5 -> V_187 ) ;
return - V_37 ;
}
V_5 -> V_73 -> V_74 = F_98 ( sizeof( struct V_213 ) , V_36 ) ;
if ( V_5 -> V_73 -> V_74 == NULL ) {
F_15 ( V_5 -> V_73 ) ;
V_5 -> V_73 = NULL ;
F_143 ( & V_5 -> V_187 ) ;
return - V_37 ;
}
V_5 -> V_73 -> V_74 -> V_91 = V_91 ;
V_5 -> V_73 -> V_122 = V_122 ;
V_5 -> V_182 = 1 ;
F_143 ( & V_5 -> V_187 ) ;
return 0 ;
}
static void F_155 ( struct V_212 * V_73 )
{
struct V_214 * V_215 = V_216 . V_215 ;
F_156 ( V_215 , V_216 . V_217 ) ;
F_157 ( V_216 . V_218 , 1 ) ;
F_158 ( 10 ) ;
F_157 ( V_216 . V_218 , 0 ) ;
F_156 ( V_215 , V_216 . V_219 ) ;
F_159 ( 2 ) ;
}
static void F_160 ( struct V_212 * V_73 )
{
struct V_214 * V_215 = V_216 . V_215 ;
F_156 ( V_215 , V_216 . V_220 ) ;
F_157 ( V_216 . V_218 , 0 ) ;
F_157 ( V_216 . V_221 , 0 ) ;
F_157 ( V_216 . V_222 , 0 ) ;
F_158 ( 10 ) ;
F_157 ( V_216 . V_222 , 1 ) ;
F_156 ( V_215 , V_216 . V_219 ) ;
F_159 ( 2 ) ;
}
static int F_161 ( struct V_24 * V_25 ,
struct V_223 * V_224 )
{
struct V_214 * V_22 ;
struct V_225 * V_226 ;
int V_227 ;
int V_14 ;
V_22 = F_162 ( V_25 ) ;
if ( F_163 ( V_22 ) ) {
F_49 ( V_25 , L_65 ) ;
return F_164 ( V_22 ) ;
}
V_224 -> V_215 = V_22 ;
V_226 = F_165 ( V_22 , L_66 ) ;
if ( F_163 ( V_226 ) ) {
F_49 ( V_25 , L_67 ) ;
return F_164 ( V_226 ) ;
}
V_224 -> V_220 = V_226 ;
V_226 = F_165 ( V_22 , L_68 ) ;
if ( F_163 ( V_226 ) ) {
F_49 ( V_25 , L_69 ) ;
return F_164 ( V_226 ) ;
}
V_224 -> V_217 = V_226 ;
V_226 = F_165 ( V_22 , L_70 ) ;
if ( F_163 ( V_226 ) ) {
F_49 ( V_25 , L_71 ) ;
return F_164 ( V_226 ) ;
}
V_224 -> V_219 = V_226 ;
V_227 = F_166 ( V_25 -> V_120 , L_72 , 0 ) ;
if ( V_227 < 0 ) {
F_49 ( V_25 , L_73 ) ;
return V_227 ;
}
V_14 = F_167 ( V_25 , V_227 , L_74 ) ;
if ( V_14 ) {
F_49 ( V_25 , L_75 ) ;
return V_14 ;
}
V_224 -> V_218 = V_227 ;
V_227 = F_166 ( V_25 -> V_120 , L_72 , 1 ) ;
if ( V_227 < 0 ) {
F_49 ( V_25 , L_76 , V_227 ) ;
return V_227 ;
}
V_14 = F_167 ( V_25 , V_227 , L_77 ) ;
if ( V_14 ) {
F_49 ( V_25 , L_78 ) ;
return V_14 ;
}
V_224 -> V_221 = V_227 ;
V_227 = F_166 ( V_25 -> V_120 , L_72 , 2 ) ;
if ( V_227 < 0 ) {
F_49 ( V_25 , L_79 ) ;
return V_227 ;
}
V_14 = F_167 ( V_25 , V_227 , L_80 ) ;
if ( V_14 ) {
F_49 ( V_25 , L_81 ) ;
return V_14 ;
}
V_224 -> V_222 = V_227 ;
return 0 ;
}
int F_168 ( struct V_211 * V_91 )
{
if ( V_91 == V_228 )
return 0 ;
if ( V_228 && V_91 )
return - V_184 ;
V_228 = V_91 ;
return 0 ;
}
int F_169 ( struct V_211 * V_91 ,
struct V_209 * V_210 )
{
struct V_24 * V_25 = & V_210 -> V_25 ;
struct V_223 V_224 ;
int V_14 ;
V_14 = F_161 ( V_25 , & V_224 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_168 ( V_91 ) ;
if ( V_14 )
return V_14 ;
V_91 -> V_229 = F_155 ;
V_91 -> V_230 = F_160 ;
V_216 = V_224 ;
return 0 ;
}
void F_170 ( struct V_4 * V_5 )
{
F_154 ( & V_5 -> V_187 ) ;
#ifdef F_142
F_120 ( V_5 ) ;
#endif
F_15 ( V_5 -> V_73 -> V_74 ) ;
F_15 ( V_5 -> V_73 ) ;
V_5 -> V_73 = NULL ;
V_5 -> V_182 = 0 ;
F_143 ( & V_5 -> V_187 ) ;
}
struct V_231 * F_171 ( const struct V_232 * V_233 ,
void * V_234 , const char * V_204 ,
const char * V_235 )
{
struct V_232 V_236 ;
struct V_231 * V_237 ;
char * V_48 = NULL ;
memcpy ( & V_236 , V_233 , sizeof( V_236 ) ) ;
V_236 . V_238 = 0 ;
if ( ! V_204 )
V_204 = V_236 . V_48 ;
if ( V_235 ) {
V_48 = F_172 ( V_36 , L_82 , V_235 , V_204 ) ;
if ( ! V_48 )
return NULL ;
V_236 . V_48 = V_48 ;
} else {
V_236 . V_48 = V_204 ;
}
V_237 = F_173 ( & V_236 , V_234 ) ;
F_15 ( V_48 ) ;
return V_237 ;
}
static int F_174 ( struct V_79 * V_46 , struct V_24 * V_25 ,
const struct V_232 * V_151 , int V_152 ,
const char * V_235 , void * V_234 )
{
int V_75 , V_3 ;
for ( V_3 = 0 ; V_3 < V_152 ; V_3 ++ ) {
const struct V_232 * V_239 = & V_151 [ V_3 ] ;
V_75 = F_175 ( V_46 , F_171 ( V_239 , V_234 ,
V_239 -> V_48 , V_235 ) ) ;
if ( V_75 < 0 ) {
F_49 ( V_25 , L_83 ,
V_239 -> V_48 , V_75 ) ;
return V_75 ;
}
}
return 0 ;
}
struct V_231 * F_176 ( struct V_61 * V_240 ,
const char * V_48 )
{
struct V_79 * V_46 = V_240 -> V_79 ;
struct V_231 * V_241 ;
if ( F_177 ( ! V_48 ) )
return NULL ;
F_33 (kctl, &card->controls, list)
if ( ! strncmp ( V_241 -> V_242 . V_48 , V_48 , sizeof( V_241 -> V_242 . V_48 ) ) )
return V_241 ;
return NULL ;
}
int F_89 ( struct V_4 * V_5 ,
const struct V_232 * V_151 , int V_152 )
{
struct V_79 * V_46 = V_5 -> V_46 -> V_79 ;
return F_174 ( V_46 , V_5 -> V_25 , V_151 , V_152 ,
V_5 -> V_144 , & V_5 -> V_58 ) ;
}
int F_93 ( struct V_54 * V_55 ,
const struct V_232 * V_151 , int V_152 )
{
struct V_79 * V_46 = V_55 -> V_46 -> V_79 ;
return F_174 ( V_46 , V_55 -> V_25 , V_151 , V_152 ,
NULL , & V_55 -> V_58 ) ;
}
int F_136 ( struct V_61 * V_240 ,
const struct V_232 * V_151 , int V_152 )
{
struct V_79 * V_46 = V_240 -> V_79 ;
return F_174 ( V_46 , V_240 -> V_25 , V_151 , V_152 ,
NULL , V_240 ) ;
}
int F_178 ( struct V_59 * V_60 ,
const struct V_232 * V_151 , int V_152 )
{
struct V_79 * V_46 = V_60 -> V_46 -> V_79 ;
return F_174 ( V_46 , V_60 -> V_25 , V_151 , V_152 ,
NULL , V_60 ) ;
}
int F_179 ( struct V_231 * V_237 ,
struct V_243 * V_244 )
{
struct V_245 * V_246 = (struct V_245 * ) V_237 -> V_247 ;
V_244 -> type = V_248 ;
V_244 -> V_18 = V_246 -> V_249 == V_246 -> V_250 ? 1 : 2 ;
V_244 -> V_41 . V_251 . V_252 = V_246 -> V_252 ;
if ( V_244 -> V_41 . V_251 . V_253 >= V_246 -> V_252 )
V_244 -> V_41 . V_251 . V_253 = V_246 -> V_252 - 1 ;
F_180 ( V_244 -> V_41 . V_251 . V_48 ,
V_246 -> V_254 [ V_244 -> V_41 . V_251 . V_253 ] ,
sizeof( V_244 -> V_41 . V_251 . V_48 ) ) ;
return 0 ;
}
int F_181 ( struct V_231 * V_237 ,
struct V_255 * V_256 )
{
struct V_57 * V_58 = F_182 ( V_237 ) ;
struct V_245 * V_246 = (struct V_245 * ) V_237 -> V_247 ;
unsigned int V_1 , V_253 ;
unsigned int V_257 ;
int V_14 ;
V_14 = F_183 ( V_58 , V_246 -> V_6 , & V_257 ) ;
if ( V_14 )
return V_14 ;
V_1 = ( V_257 >> V_246 -> V_249 ) & V_246 -> V_258 ;
V_253 = F_184 ( V_246 , V_1 ) ;
V_256 -> V_41 . V_251 . V_253 [ 0 ] = V_253 ;
if ( V_246 -> V_249 != V_246 -> V_250 ) {
V_1 = ( V_257 >> V_246 -> V_249 ) & V_246 -> V_258 ;
V_253 = F_184 ( V_246 , V_1 ) ;
V_256 -> V_41 . V_251 . V_253 [ 1 ] = V_253 ;
}
return 0 ;
}
int F_185 ( struct V_231 * V_237 ,
struct V_255 * V_256 )
{
struct V_57 * V_58 = F_182 ( V_237 ) ;
struct V_245 * V_246 = (struct V_245 * ) V_237 -> V_247 ;
unsigned int * V_253 = V_256 -> V_41 . V_251 . V_253 ;
unsigned int V_1 ;
unsigned int V_258 ;
if ( V_253 [ 0 ] >= V_246 -> V_252 )
return - V_17 ;
V_1 = F_186 ( V_246 , V_253 [ 0 ] ) << V_246 -> V_249 ;
V_258 = V_246 -> V_258 << V_246 -> V_249 ;
if ( V_246 -> V_249 != V_246 -> V_250 ) {
if ( V_253 [ 1 ] >= V_246 -> V_252 )
return - V_17 ;
V_1 |= F_186 ( V_246 , V_253 [ 1 ] ) << V_246 -> V_250 ;
V_258 |= V_246 -> V_258 << V_246 -> V_250 ;
}
return F_187 ( V_58 , V_246 -> V_6 , V_258 , V_1 ) ;
}
static int F_188 ( struct V_57 * V_58 ,
unsigned int V_6 , unsigned int V_258 , unsigned int V_259 ,
unsigned int V_260 , int * V_261 )
{
int V_14 ;
unsigned int V_1 ;
V_14 = F_183 ( V_58 , V_6 , & V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
V_1 = ( V_1 >> V_259 ) & V_258 ;
if ( ! V_260 ) {
* V_261 = V_1 ;
return 0 ;
}
if ( ! ( V_1 & F_189 ( V_260 ) ) ) {
* V_261 = V_1 ;
return 0 ;
}
V_14 = V_1 ;
V_14 |= ~ ( ( int ) ( F_189 ( V_260 ) - 1 ) ) ;
* V_261 = V_14 ;
return 0 ;
}
int F_190 ( struct V_231 * V_237 ,
struct V_243 * V_244 )
{
struct V_262 * V_263 =
(struct V_262 * ) V_237 -> V_247 ;
int V_264 ;
if ( ! V_263 -> V_264 )
V_263 -> V_264 = V_263 -> V_265 ;
V_264 = V_263 -> V_264 ;
if ( V_264 == 1 && ! strstr ( V_237 -> V_242 . V_48 , L_84 ) )
V_244 -> type = V_266 ;
else
V_244 -> type = V_267 ;
V_244 -> V_18 = F_191 ( V_263 ) ? 2 : 1 ;
V_244 -> V_41 . integer . F_6 = 0 ;
V_244 -> V_41 . integer . V_265 = V_264 - V_263 -> F_6 ;
return 0 ;
}
int F_192 ( struct V_231 * V_237 ,
struct V_255 * V_256 )
{
struct V_57 * V_58 = F_182 ( V_237 ) ;
struct V_262 * V_263 =
(struct V_262 * ) V_237 -> V_247 ;
unsigned int V_6 = V_263 -> V_6 ;
unsigned int V_268 = V_263 -> V_269 ;
unsigned int V_259 = V_263 -> V_259 ;
unsigned int V_270 = V_263 -> V_270 ;
int V_265 = V_263 -> V_265 ;
int F_6 = V_263 -> F_6 ;
int V_260 = V_263 -> V_260 ;
unsigned int V_258 = ( 1 << F_193 ( V_265 ) ) - 1 ;
unsigned int V_271 = V_263 -> V_271 ;
int V_1 ;
int V_14 ;
if ( V_260 )
V_258 = F_189 ( V_260 + 1 ) - 1 ;
V_14 = F_188 ( V_58 , V_6 , V_258 , V_259 , V_260 , & V_1 ) ;
if ( V_14 )
return V_14 ;
V_256 -> V_41 . integer . V_41 [ 0 ] = V_1 - F_6 ;
if ( V_271 )
V_256 -> V_41 . integer . V_41 [ 0 ] =
V_265 - V_256 -> V_41 . integer . V_41 [ 0 ] ;
if ( F_191 ( V_263 ) ) {
if ( V_6 == V_268 )
V_14 = F_188 ( V_58 , V_6 , V_258 , V_270 ,
V_260 , & V_1 ) ;
else
V_14 = F_188 ( V_58 , V_268 , V_258 , V_259 ,
V_260 , & V_1 ) ;
if ( V_14 )
return V_14 ;
V_256 -> V_41 . integer . V_41 [ 1 ] = V_1 - F_6 ;
if ( V_271 )
V_256 -> V_41 . integer . V_41 [ 1 ] =
V_265 - V_256 -> V_41 . integer . V_41 [ 1 ] ;
}
return 0 ;
}
int F_194 ( struct V_231 * V_237 ,
struct V_255 * V_256 )
{
struct V_57 * V_58 = F_182 ( V_237 ) ;
struct V_262 * V_263 =
(struct V_262 * ) V_237 -> V_247 ;
unsigned int V_6 = V_263 -> V_6 ;
unsigned int V_268 = V_263 -> V_269 ;
unsigned int V_259 = V_263 -> V_259 ;
unsigned int V_270 = V_263 -> V_270 ;
int V_265 = V_263 -> V_265 ;
int F_6 = V_263 -> F_6 ;
unsigned int V_260 = V_263 -> V_260 ;
unsigned int V_258 = ( 1 << F_193 ( V_265 ) ) - 1 ;
unsigned int V_271 = V_263 -> V_271 ;
int V_75 ;
bool V_272 = false ;
unsigned int V_273 = 0 ;
unsigned int V_1 , V_274 ;
if ( V_260 )
V_258 = F_189 ( V_260 + 1 ) - 1 ;
V_1 = ( ( V_256 -> V_41 . integer . V_41 [ 0 ] + F_6 ) & V_258 ) ;
if ( V_271 )
V_1 = V_265 - V_1 ;
V_274 = V_258 << V_259 ;
V_1 = V_1 << V_259 ;
if ( F_191 ( V_263 ) ) {
V_273 = ( ( V_256 -> V_41 . integer . V_41 [ 1 ] + F_6 ) & V_258 ) ;
if ( V_271 )
V_273 = V_265 - V_273 ;
if ( V_6 == V_268 ) {
V_274 |= V_258 << V_270 ;
V_1 |= V_273 << V_270 ;
} else {
V_273 = V_273 << V_259 ;
V_272 = true ;
}
}
V_75 = F_187 ( V_58 , V_6 , V_274 , V_1 ) ;
if ( V_75 < 0 )
return V_75 ;
if ( V_272 )
V_75 = F_187 ( V_58 , V_268 , V_274 ,
V_273 ) ;
return V_75 ;
}
int F_195 ( struct V_231 * V_237 ,
struct V_255 * V_256 )
{
struct V_57 * V_58 = F_182 ( V_237 ) ;
struct V_262 * V_263 =
(struct V_262 * ) V_237 -> V_247 ;
unsigned int V_6 = V_263 -> V_6 ;
unsigned int V_268 = V_263 -> V_269 ;
unsigned int V_259 = V_263 -> V_259 ;
unsigned int V_270 = V_263 -> V_270 ;
int V_265 = V_263 -> V_265 ;
int F_6 = V_263 -> F_6 ;
int V_258 = ( 1 << ( F_193 ( F_6 + V_265 ) - 1 ) ) - 1 ;
unsigned int V_1 ;
int V_14 ;
V_14 = F_183 ( V_58 , V_6 , & V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
V_256 -> V_41 . integer . V_41 [ 0 ] = ( ( V_1 >> V_259 ) - F_6 ) & V_258 ;
if ( F_191 ( V_263 ) ) {
V_14 = F_183 ( V_58 , V_268 , & V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
V_1 = ( ( V_1 >> V_270 ) - F_6 ) & V_258 ;
V_256 -> V_41 . integer . V_41 [ 1 ] = V_1 ;
}
return 0 ;
}
int F_196 ( struct V_231 * V_237 ,
struct V_255 * V_256 )
{
struct V_57 * V_58 = F_182 ( V_237 ) ;
struct V_262 * V_263 =
(struct V_262 * ) V_237 -> V_247 ;
unsigned int V_6 = V_263 -> V_6 ;
unsigned int V_268 = V_263 -> V_269 ;
unsigned int V_259 = V_263 -> V_259 ;
unsigned int V_270 = V_263 -> V_270 ;
int V_265 = V_263 -> V_265 ;
int F_6 = V_263 -> F_6 ;
int V_258 = ( 1 << ( F_193 ( F_6 + V_265 ) - 1 ) ) - 1 ;
int V_75 = 0 ;
unsigned int V_1 , V_274 , V_273 = 0 ;
V_274 = V_258 << V_259 ;
V_1 = ( V_256 -> V_41 . integer . V_41 [ 0 ] + F_6 ) & V_258 ;
V_1 = V_1 << V_259 ;
V_75 = F_187 ( V_58 , V_6 , V_274 , V_1 ) ;
if ( V_75 < 0 )
return V_75 ;
if ( F_191 ( V_263 ) ) {
V_274 = V_258 << V_270 ;
V_273 = ( V_256 -> V_41 . integer . V_41 [ 1 ] + F_6 ) & V_258 ;
V_273 = V_273 << V_270 ;
V_75 = F_187 ( V_58 , V_268 , V_274 ,
V_273 ) ;
}
return V_75 ;
}
int F_197 ( struct V_231 * V_237 ,
struct V_243 * V_244 )
{
struct V_262 * V_263 =
(struct V_262 * ) V_237 -> V_247 ;
int V_264 ;
int F_6 = V_263 -> F_6 ;
if ( ! V_263 -> V_264 )
V_263 -> V_264 = V_263 -> V_265 ;
V_264 = V_263 -> V_264 ;
V_244 -> type = V_267 ;
V_244 -> V_18 = 2 ;
V_244 -> V_41 . integer . F_6 = 0 ;
V_244 -> V_41 . integer . V_265 = V_264 - F_6 ;
return 0 ;
}
int F_198 ( struct V_231 * V_237 ,
struct V_255 * V_256 )
{
struct V_262 * V_263 =
(struct V_262 * ) V_237 -> V_247 ;
struct V_57 * V_58 = F_182 ( V_237 ) ;
unsigned int V_6 = V_263 -> V_6 ;
unsigned int V_1 ;
int F_6 = V_263 -> F_6 ;
int V_14 ;
V_14 = F_183 ( V_58 , V_6 , & V_1 ) ;
if ( V_14 )
return V_14 ;
V_256 -> V_41 . integer . V_41 [ 0 ] =
( ( signed char ) ( V_1 & 0xff ) ) - F_6 ;
V_256 -> V_41 . integer . V_41 [ 1 ] =
( ( signed char ) ( ( V_1 >> 8 ) & 0xff ) ) - F_6 ;
return 0 ;
}
int F_199 ( struct V_231 * V_237 ,
struct V_255 * V_256 )
{
struct V_262 * V_263 =
(struct V_262 * ) V_237 -> V_247 ;
struct V_57 * V_58 = F_182 ( V_237 ) ;
unsigned int V_6 = V_263 -> V_6 ;
int F_6 = V_263 -> F_6 ;
unsigned int V_1 ;
V_1 = ( V_256 -> V_41 . integer . V_41 [ 0 ] + F_6 ) & 0xff ;
V_1 |= ( ( V_256 -> V_41 . integer . V_41 [ 1 ] + F_6 ) & 0xff ) << 8 ;
return F_187 ( V_58 , V_6 , 0xffff , V_1 ) ;
}
int F_200 ( struct V_231 * V_237 ,
struct V_243 * V_244 )
{
struct V_262 * V_263 =
(struct V_262 * ) V_237 -> V_247 ;
int V_264 ;
int F_6 = V_263 -> F_6 ;
if ( ! V_263 -> V_264 )
V_263 -> V_264 = V_263 -> V_265 ;
V_264 = V_263 -> V_264 ;
V_244 -> type = V_267 ;
V_244 -> V_18 = F_191 ( V_263 ) ? 2 : 1 ;
V_244 -> V_41 . integer . F_6 = 0 ;
V_244 -> V_41 . integer . V_265 = V_264 - F_6 ;
return 0 ;
}
int F_201 ( struct V_231 * V_237 ,
struct V_255 * V_256 )
{
struct V_262 * V_263 =
(struct V_262 * ) V_237 -> V_247 ;
struct V_57 * V_58 = F_182 ( V_237 ) ;
unsigned int V_6 = V_263 -> V_6 ;
unsigned int V_269 = V_263 -> V_269 ;
unsigned int V_259 = V_263 -> V_259 ;
int F_6 = V_263 -> F_6 ;
int V_265 = V_263 -> V_265 ;
unsigned int V_258 = ( 1 << F_193 ( V_265 ) ) - 1 ;
unsigned int V_271 = V_263 -> V_271 ;
unsigned int V_1 , V_274 ;
int V_14 ;
V_1 = ( ( V_256 -> V_41 . integer . V_41 [ 0 ] + F_6 ) & V_258 ) ;
if ( V_271 )
V_1 = V_265 - V_1 ;
V_274 = V_258 << V_259 ;
V_1 = V_1 << V_259 ;
V_14 = F_187 ( V_58 , V_6 , V_274 , V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( F_191 ( V_263 ) ) {
V_1 = ( ( V_256 -> V_41 . integer . V_41 [ 1 ] + F_6 ) & V_258 ) ;
if ( V_271 )
V_1 = V_265 - V_1 ;
V_274 = V_258 << V_259 ;
V_1 = V_1 << V_259 ;
V_14 = F_187 ( V_58 , V_269 , V_274 ,
V_1 ) ;
}
return V_14 ;
}
int F_202 ( struct V_231 * V_237 ,
struct V_255 * V_256 )
{
struct V_57 * V_58 = F_182 ( V_237 ) ;
struct V_262 * V_263 =
(struct V_262 * ) V_237 -> V_247 ;
unsigned int V_6 = V_263 -> V_6 ;
unsigned int V_269 = V_263 -> V_269 ;
unsigned int V_259 = V_263 -> V_259 ;
int F_6 = V_263 -> F_6 ;
int V_265 = V_263 -> V_265 ;
unsigned int V_258 = ( 1 << F_193 ( V_265 ) ) - 1 ;
unsigned int V_271 = V_263 -> V_271 ;
unsigned int V_1 ;
int V_14 ;
V_14 = F_183 ( V_58 , V_6 , & V_1 ) ;
if ( V_14 )
return V_14 ;
V_256 -> V_41 . integer . V_41 [ 0 ] = ( V_1 >> V_259 ) & V_258 ;
if ( V_271 )
V_256 -> V_41 . integer . V_41 [ 0 ] =
V_265 - V_256 -> V_41 . integer . V_41 [ 0 ] ;
V_256 -> V_41 . integer . V_41 [ 0 ] =
V_256 -> V_41 . integer . V_41 [ 0 ] - F_6 ;
if ( F_191 ( V_263 ) ) {
V_14 = F_183 ( V_58 , V_269 , & V_1 ) ;
if ( V_14 )
return V_14 ;
V_256 -> V_41 . integer . V_41 [ 1 ] = ( V_1 >> V_259 ) & V_258 ;
if ( V_271 )
V_256 -> V_41 . integer . V_41 [ 1 ] =
V_265 - V_256 -> V_41 . integer . V_41 [ 1 ] ;
V_256 -> V_41 . integer . V_41 [ 1 ] =
V_256 -> V_41 . integer . V_41 [ 1 ] - F_6 ;
}
return 0 ;
}
int F_203 ( struct V_4 * V_5 ,
const char * V_48 , int V_265 )
{
struct V_79 * V_46 = V_5 -> V_46 -> V_79 ;
struct V_231 * V_241 ;
struct V_262 * V_263 ;
int V_275 = 0 ;
int V_14 = - V_17 ;
if ( F_177 ( ! V_48 || V_265 <= 0 ) )
return - V_17 ;
F_33 (kctl, &card->controls, list) {
if ( ! strncmp ( V_241 -> V_242 . V_48 , V_48 , sizeof( V_241 -> V_242 . V_48 ) ) ) {
V_275 = 1 ;
break;
}
}
if ( V_275 ) {
V_263 = (struct V_262 * ) V_241 -> V_247 ;
if ( V_265 <= V_263 -> V_265 ) {
V_263 -> V_264 = V_265 ;
V_14 = 0 ;
}
}
return V_14 ;
}
int F_204 ( struct V_231 * V_237 ,
struct V_243 * V_244 )
{
struct V_57 * V_58 = F_182 ( V_237 ) ;
struct V_276 * V_177 = ( void * ) V_237 -> V_247 ;
V_244 -> type = V_277 ;
V_244 -> V_18 = V_177 -> V_278 * V_58 -> V_279 ;
return 0 ;
}
int F_205 ( struct V_231 * V_237 ,
struct V_255 * V_256 )
{
struct V_57 * V_58 = F_182 ( V_237 ) ;
struct V_276 * V_177 = ( void * ) V_237 -> V_247 ;
int V_14 ;
if ( V_58 -> V_108 )
V_14 = F_206 ( V_58 -> V_108 , V_177 -> V_280 ,
V_256 -> V_41 . V_281 . V_234 ,
V_177 -> V_278 * V_58 -> V_279 ) ;
else
V_14 = - V_17 ;
if ( V_14 == 0 && V_177 -> V_258 ) {
switch ( V_58 -> V_279 ) {
case 1 :
V_256 -> V_41 . V_281 . V_234 [ 0 ] &= ~ V_177 -> V_258 ;
break;
case 2 :
( ( V_282 * ) ( & V_256 -> V_41 . V_281 . V_234 ) ) [ 0 ]
&= F_207 ( ~ V_177 -> V_258 ) ;
break;
case 4 :
( ( V_283 * ) ( & V_256 -> V_41 . V_281 . V_234 ) ) [ 0 ]
&= F_208 ( ~ V_177 -> V_258 ) ;
break;
default:
return - V_17 ;
}
}
return V_14 ;
}
int F_209 ( struct V_231 * V_237 ,
struct V_255 * V_256 )
{
struct V_57 * V_58 = F_182 ( V_237 ) ;
struct V_276 * V_177 = ( void * ) V_237 -> V_247 ;
int V_14 , V_8 ;
unsigned int V_1 , V_258 ;
void * V_234 ;
if ( ! V_58 -> V_108 )
return - V_17 ;
V_8 = V_177 -> V_278 * V_58 -> V_279 ;
V_234 = F_210 ( V_256 -> V_41 . V_281 . V_234 , V_8 , V_36 | V_284 ) ;
if ( ! V_234 )
return - V_37 ;
if ( V_177 -> V_258 ) {
V_14 = F_211 ( V_58 -> V_108 , V_177 -> V_280 , & V_1 ) ;
if ( V_14 != 0 )
goto V_170;
V_1 &= V_177 -> V_258 ;
switch ( V_58 -> V_279 ) {
case 1 :
( ( V_285 * ) V_234 ) [ 0 ] &= ~ V_177 -> V_258 ;
( ( V_285 * ) V_234 ) [ 0 ] |= V_1 ;
break;
case 2 :
V_258 = ~ V_177 -> V_258 ;
V_14 = F_212 ( V_58 -> V_108 ,
& V_258 , & V_258 ) ;
if ( V_14 != 0 )
goto V_170;
( ( V_282 * ) V_234 ) [ 0 ] &= V_258 ;
V_14 = F_212 ( V_58 -> V_108 ,
& V_1 , & V_1 ) ;
if ( V_14 != 0 )
goto V_170;
( ( V_282 * ) V_234 ) [ 0 ] |= V_1 ;
break;
case 4 :
V_258 = ~ V_177 -> V_258 ;
V_14 = F_212 ( V_58 -> V_108 ,
& V_258 , & V_258 ) ;
if ( V_14 != 0 )
goto V_170;
( ( V_283 * ) V_234 ) [ 0 ] &= V_258 ;
V_14 = F_212 ( V_58 -> V_108 ,
& V_1 , & V_1 ) ;
if ( V_14 != 0 )
goto V_170;
( ( V_283 * ) V_234 ) [ 0 ] |= V_1 ;
break;
default:
V_14 = - V_17 ;
goto V_170;
}
}
V_14 = F_213 ( V_58 -> V_108 , V_177 -> V_280 ,
V_234 , V_8 ) ;
V_170:
F_15 ( V_234 ) ;
return V_14 ;
}
int F_214 ( struct V_231 * V_237 ,
struct V_243 * V_256 )
{
struct V_286 * V_177 = ( void * ) V_237 -> V_247 ;
V_256 -> type = V_277 ;
V_256 -> V_18 = V_177 -> V_265 ;
return 0 ;
}
int F_215 ( struct V_231 * V_237 ,
struct V_243 * V_244 )
{
struct V_287 * V_263 =
(struct V_287 * ) V_237 -> V_247 ;
V_244 -> type = V_267 ;
V_244 -> V_18 = 1 ;
V_244 -> V_41 . integer . F_6 = V_263 -> F_6 ;
V_244 -> V_41 . integer . V_265 = V_263 -> V_265 ;
return 0 ;
}
int F_216 ( struct V_231 * V_237 ,
struct V_255 * V_256 )
{
struct V_57 * V_58 = F_182 ( V_237 ) ;
struct V_287 * V_263 =
(struct V_287 * ) V_237 -> V_247 ;
unsigned int V_288 = V_263 -> V_288 ;
unsigned int V_289 = V_263 -> V_289 ;
unsigned int V_290 = V_58 -> V_279 * V_291 ;
unsigned int V_292 = ( 1 << V_290 ) - 1 ;
unsigned int V_271 = V_263 -> V_271 ;
unsigned long V_258 = ( 1UL << V_263 -> V_293 ) - 1 ;
long F_6 = V_263 -> F_6 ;
long V_265 = V_263 -> V_265 ;
long V_1 = 0 ;
unsigned int V_294 ;
unsigned int V_3 ;
int V_14 ;
for ( V_3 = 0 ; V_3 < V_289 ; V_3 ++ ) {
V_14 = F_183 ( V_58 , V_288 + V_3 , & V_294 ) ;
if ( V_14 )
return V_14 ;
V_1 |= ( V_294 & V_292 ) << ( V_290 * ( V_289 - V_3 - 1 ) ) ;
}
V_1 &= V_258 ;
if ( F_6 < 0 && V_1 > V_265 )
V_1 |= ~ V_258 ;
if ( V_271 )
V_1 = V_265 - V_1 ;
V_256 -> V_41 . integer . V_41 [ 0 ] = V_1 ;
return 0 ;
}
int F_217 ( struct V_231 * V_237 ,
struct V_255 * V_256 )
{
struct V_57 * V_58 = F_182 ( V_237 ) ;
struct V_287 * V_263 =
(struct V_287 * ) V_237 -> V_247 ;
unsigned int V_288 = V_263 -> V_288 ;
unsigned int V_289 = V_263 -> V_289 ;
unsigned int V_290 = V_58 -> V_279 * V_291 ;
unsigned int V_292 = ( 1 << V_290 ) - 1 ;
unsigned int V_271 = V_263 -> V_271 ;
unsigned long V_258 = ( 1UL << V_263 -> V_293 ) - 1 ;
long V_265 = V_263 -> V_265 ;
long V_1 = V_256 -> V_41 . integer . V_41 [ 0 ] ;
unsigned int V_3 , V_294 , V_295 ;
int V_75 ;
if ( V_271 )
V_1 = V_265 - V_1 ;
V_1 &= V_258 ;
for ( V_3 = 0 ; V_3 < V_289 ; V_3 ++ ) {
V_294 = ( V_1 >> ( V_290 * ( V_289 - V_3 - 1 ) ) ) & V_292 ;
V_295 = ( V_258 >> ( V_290 * ( V_289 - V_3 - 1 ) ) ) & V_292 ;
V_75 = F_187 ( V_58 , V_288 + V_3 ,
V_295 , V_294 ) ;
if ( V_75 < 0 )
return V_75 ;
}
return 0 ;
}
int F_218 ( struct V_231 * V_237 ,
struct V_255 * V_256 )
{
struct V_57 * V_58 = F_182 ( V_237 ) ;
struct V_262 * V_263 =
(struct V_262 * ) V_237 -> V_247 ;
unsigned int V_6 = V_263 -> V_6 ;
unsigned int V_259 = V_263 -> V_259 ;
unsigned int V_258 = 1 << V_259 ;
unsigned int V_271 = V_263 -> V_271 != 0 ;
unsigned int V_1 ;
int V_14 ;
V_14 = F_183 ( V_58 , V_6 , & V_1 ) ;
if ( V_14 )
return V_14 ;
V_1 &= V_258 ;
if ( V_259 != 0 && V_1 != 0 )
V_1 = V_1 >> V_259 ;
V_256 -> V_41 . V_251 . V_253 [ 0 ] = V_1 ^ V_271 ;
return 0 ;
}
int F_219 ( struct V_231 * V_237 ,
struct V_255 * V_256 )
{
struct V_57 * V_58 = F_182 ( V_237 ) ;
struct V_262 * V_263 =
(struct V_262 * ) V_237 -> V_247 ;
unsigned int V_6 = V_263 -> V_6 ;
unsigned int V_259 = V_263 -> V_259 ;
unsigned int V_258 = 1 << V_259 ;
unsigned int V_271 = V_263 -> V_271 != 0 ;
unsigned int V_296 = V_256 -> V_41 . V_251 . V_253 [ 0 ] != 0 ;
unsigned int V_297 = ( V_296 ^ V_271 ) ? V_258 : 0 ;
unsigned int V_273 = ( V_296 ^ V_271 ) ? 0 : V_258 ;
int V_75 ;
V_75 = F_187 ( V_58 , V_6 , V_258 , V_297 ) ;
if ( V_75 < 0 )
return V_75 ;
return F_187 ( V_58 , V_6 , V_258 , V_273 ) ;
}
int F_220 ( struct V_59 * V_60 , int V_298 ,
unsigned int V_299 , int V_300 )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_91 -> V_301 )
return V_60 -> V_10 -> V_91 -> V_301 ( V_60 , V_298 , V_299 , V_300 ) ;
else if ( V_60 -> V_5 && V_60 -> V_5 -> V_10 -> V_301 )
return V_60 -> V_5 -> V_10 -> V_301 ( V_60 -> V_5 , V_298 , 0 ,
V_299 , V_300 ) ;
else
return - V_196 ;
}
int F_221 ( struct V_4 * V_5 , int V_298 ,
int V_302 , unsigned int V_299 , int V_300 )
{
if ( V_5 -> V_10 -> V_301 )
return V_5 -> V_10 -> V_301 ( V_5 , V_298 , V_302 ,
V_299 , V_300 ) ;
else
return - V_196 ;
}
int F_222 ( struct V_59 * V_60 ,
int V_303 , int div )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_91 -> V_304 )
return V_60 -> V_10 -> V_91 -> V_304 ( V_60 , V_303 , div ) ;
else
return - V_17 ;
}
int F_223 ( struct V_59 * V_60 , int V_305 , int V_302 ,
unsigned int V_306 , unsigned int V_307 )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_91 -> V_308 )
return V_60 -> V_10 -> V_91 -> V_308 ( V_60 , V_305 , V_302 ,
V_306 , V_307 ) ;
else if ( V_60 -> V_5 && V_60 -> V_5 -> V_10 -> V_308 )
return V_60 -> V_5 -> V_10 -> V_308 ( V_60 -> V_5 , V_305 , V_302 ,
V_306 , V_307 ) ;
else
return - V_17 ;
}
int F_224 ( struct V_4 * V_5 , int V_305 , int V_302 ,
unsigned int V_306 , unsigned int V_307 )
{
if ( V_5 -> V_10 -> V_308 )
return V_5 -> V_10 -> V_308 ( V_5 , V_305 , V_302 ,
V_306 , V_307 ) ;
else
return - V_17 ;
}
int F_225 ( struct V_59 * V_60 , unsigned int V_309 )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_91 -> V_310 )
return V_60 -> V_10 -> V_91 -> V_310 ( V_60 , V_309 ) ;
else
return - V_17 ;
}
int F_137 ( struct V_59 * V_60 , unsigned int V_311 )
{
if ( V_60 -> V_10 == NULL )
return - V_17 ;
if ( V_60 -> V_10 -> V_91 -> V_312 == NULL )
return - V_196 ;
return V_60 -> V_10 -> V_91 -> V_312 ( V_60 , V_311 ) ;
}
static int F_226 ( unsigned int V_313 ,
unsigned int * V_314 ,
unsigned int * V_315 )
{
if ( * V_314 || * V_315 )
return 0 ;
if ( ! V_313 )
return - V_17 ;
* V_314 = ( 1 << V_313 ) - 1 ;
* V_315 = ( 1 << V_313 ) - 1 ;
return 0 ;
}
int F_227 ( struct V_59 * V_60 ,
unsigned int V_314 , unsigned int V_315 , int V_313 , int V_316 )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_91 -> V_317 )
V_60 -> V_10 -> V_91 -> V_317 ( V_313 ,
& V_314 , & V_315 ) ;
else
F_226 ( V_313 , & V_314 , & V_315 ) ;
if ( V_60 -> V_10 && V_60 -> V_10 -> V_91 -> V_318 )
return V_60 -> V_10 -> V_91 -> V_318 ( V_60 , V_314 , V_315 ,
V_313 , V_316 ) ;
else
return - V_196 ;
}
int F_228 ( struct V_59 * V_60 ,
unsigned int V_319 , unsigned int * V_320 ,
unsigned int V_321 , unsigned int * V_322 )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_91 -> V_323 )
return V_60 -> V_10 -> V_91 -> V_323 ( V_60 , V_319 , V_320 ,
V_321 , V_322 ) ;
else
return - V_17 ;
}
int F_229 ( struct V_59 * V_60 , int V_324 )
{
if ( V_60 -> V_10 && V_60 -> V_10 -> V_91 -> V_325 )
return V_60 -> V_10 -> V_91 -> V_325 ( V_60 , V_324 ) ;
else
return - V_17 ;
}
int F_230 ( struct V_59 * V_60 , int V_326 ,
int V_327 )
{
if ( ! V_60 -> V_10 )
return - V_196 ;
if ( V_60 -> V_10 -> V_91 -> V_328 )
return V_60 -> V_10 -> V_91 -> V_328 ( V_60 , V_326 , V_327 ) ;
else if ( V_327 == V_102 &&
V_60 -> V_10 -> V_91 -> V_92 )
return V_60 -> V_10 -> V_91 -> V_92 ( V_60 , V_326 ) ;
else
return - V_196 ;
}
int F_147 ( struct V_61 * V_46 )
{
int V_3 , V_14 ;
if ( ! V_46 -> V_48 || ! V_46 -> V_25 )
return - V_17 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_68 ; V_3 ++ ) {
struct V_123 * V_329 = & V_46 -> V_66 [ V_3 ] ;
if ( ! ! V_329 -> V_119 == ! ! V_329 -> V_118 ) {
F_49 ( V_46 -> V_25 ,
L_85 ,
V_329 -> V_48 ) ;
return - V_17 ;
}
if ( ! V_329 -> V_121 ) {
F_49 ( V_46 -> V_25 ,
L_86 ,
V_329 -> V_48 ) ;
return - V_17 ;
}
if ( V_329 -> V_124 && V_329 -> V_129 ) {
F_49 ( V_46 -> V_25 ,
L_87 ,
V_329 -> V_48 ) ;
return - V_17 ;
}
if ( V_329 -> V_126 && V_329 -> V_125 ) {
F_49 ( V_46 -> V_25 ,
L_88 ,
V_329 -> V_48 ) ;
return - V_17 ;
}
if ( ! V_329 -> V_127 &&
! ( V_329 -> V_126 || V_329 -> V_125 ) ) {
F_49 ( V_46 -> V_25 ,
L_89 ,
V_329 -> V_48 ) ;
return - V_17 ;
}
}
F_100 ( V_46 -> V_25 , V_46 ) ;
F_231 ( V_46 ) ;
F_37 ( V_46 ) ;
V_46 -> V_29 = F_232 ( V_46 -> V_25 ,
sizeof( struct V_28 ) *
( V_46 -> V_68 + V_46 -> V_190 ) ,
V_36 ) ;
if ( V_46 -> V_29 == NULL )
return - V_37 ;
V_46 -> V_86 = 0 ;
V_46 -> V_161 = & V_46 -> V_29 [ V_46 -> V_68 ] ;
for ( V_3 = 0 ; V_3 < V_46 -> V_68 ; V_3 ++ )
V_46 -> V_29 [ V_3 ] . V_66 = & V_46 -> V_66 [ V_3 ] ;
F_102 ( & V_46 -> V_330 ) ;
V_46 -> V_208 = 0 ;
F_101 ( & V_46 -> V_187 ) ;
F_101 ( & V_46 -> V_331 ) ;
V_14 = F_129 ( V_46 ) ;
if ( V_14 != 0 )
F_39 ( V_46 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_86 ; V_3 ++ ) {
struct V_59 * V_95 = V_46 -> V_29 [ V_3 ] . V_95 ;
struct V_59 * V_87 = V_46 -> V_29 [ V_3 ] . V_87 ;
if ( ! V_87 -> V_116 )
F_63 ( V_87 -> V_25 ) ;
if ( ! V_95 -> V_116 )
F_63 ( V_95 -> V_25 ) ;
}
return V_14 ;
}
int F_150 ( struct V_61 * V_46 )
{
if ( V_46 -> V_208 )
F_148 ( V_46 ) ;
F_41 ( V_46 -> V_25 , L_90 , V_46 -> V_48 ) ;
return 0 ;
}
static char * F_233 ( struct V_24 * V_25 , int * V_242 )
{
char * V_275 , V_48 [ V_332 ] ;
int V_333 , V_334 ;
if ( F_72 ( V_25 ) == NULL )
return NULL ;
F_180 ( V_48 , F_72 ( V_25 ) , V_332 ) ;
V_275 = strstr ( V_48 , V_25 -> V_10 -> V_48 ) ;
if ( V_275 ) {
if ( sscanf ( & V_275 [ strlen ( V_25 -> V_10 -> V_48 ) ] , L_91 , V_242 ) == 1 ) {
if ( * V_242 == - 1 )
V_275 [ strlen ( V_25 -> V_10 -> V_48 ) ] = '\0' ;
}
} else {
if ( sscanf ( V_48 , L_92 , & V_333 , & V_334 ) == 2 ) {
char V_335 [ V_332 ] ;
* V_242 = ( ( V_333 & 0xffff ) << 16 ) + V_334 ;
snprintf ( V_335 , V_332 , L_93 , V_25 -> V_10 -> V_48 , V_48 ) ;
F_180 ( V_48 , V_335 , V_332 ) ;
} else
* V_242 = 0 ;
}
return F_234 ( V_48 , V_36 ) ;
}
static inline char * F_235 ( struct V_24 * V_25 ,
struct V_88 * V_336 )
{
if ( V_336 -> V_48 == NULL ) {
F_49 ( V_25 ,
L_94 ,
F_72 ( V_25 ) ) ;
return NULL ;
}
return F_234 ( V_336 -> V_48 , V_36 ) ;
}
static void F_236 ( struct V_57 * V_58 )
{
struct V_59 * V_60 , * V_337 ;
F_237 (dai, _dai, &component->dai_list, list) {
F_41 ( V_58 -> V_25 , L_95 ,
V_60 -> V_48 ) ;
F_75 ( & V_60 -> V_155 ) ;
F_15 ( V_60 -> V_48 ) ;
F_15 ( V_60 ) ;
}
}
static int F_238 ( struct V_57 * V_58 ,
struct V_4 * V_5 , struct V_88 * V_336 ,
T_1 V_18 , bool V_338 )
{
struct V_24 * V_25 = V_58 -> V_25 ;
struct V_59 * V_60 ;
unsigned int V_3 ;
int V_14 ;
F_41 ( V_25 , L_96 , F_72 ( V_25 ) , V_18 ) ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ ) {
V_60 = F_98 ( sizeof( struct V_59 ) , V_36 ) ;
if ( V_60 == NULL ) {
V_14 = - V_37 ;
goto V_75;
}
if ( V_18 == 1 && V_338 ) {
V_60 -> V_48 = F_233 ( V_25 , & V_60 -> V_242 ) ;
} else {
V_60 -> V_48 = F_235 ( V_25 , & V_336 [ V_3 ] ) ;
if ( V_336 [ V_3 ] . V_242 )
V_60 -> V_242 = V_336 [ V_3 ] . V_242 ;
else
V_60 -> V_242 = V_3 ;
}
if ( V_60 -> V_48 == NULL ) {
F_15 ( V_60 ) ;
V_14 = - V_37 ;
goto V_75;
}
V_60 -> V_58 = V_58 ;
V_60 -> V_5 = V_5 ;
V_60 -> V_25 = V_25 ;
V_60 -> V_10 = & V_336 [ V_3 ] ;
V_60 -> V_53 . V_25 = V_25 ;
if ( ! V_60 -> V_10 -> V_91 )
V_60 -> V_10 -> V_91 = & V_339 ;
if ( ! V_60 -> V_5 )
V_60 -> V_53 . V_106 = 1 ;
F_91 ( & V_60 -> V_155 , & V_58 -> V_340 ) ;
F_41 ( V_25 , L_97 , V_60 -> V_48 ) ;
}
return 0 ;
V_75:
F_236 ( V_58 ) ;
return V_14 ;
}
static int
F_239 ( struct V_24 * V_25 ,
struct V_57 * V_341 ,
const struct V_342 * V_343 ,
struct V_4 * V_5 ,
struct V_88 * V_336 ,
int V_344 , bool V_345 )
{
int V_14 ;
F_41 ( V_25 , L_98 , F_72 ( V_25 ) ) ;
if ( ! V_341 ) {
F_49 ( V_25 , L_99 ) ;
return - V_37 ;
}
F_101 ( & V_341 -> V_346 ) ;
V_341 -> V_48 = F_233 ( V_25 , & V_341 -> V_242 ) ;
if ( ! V_341 -> V_48 ) {
F_49 ( V_25 , L_100 ) ;
return - V_37 ;
}
V_341 -> V_25 = V_25 ;
V_341 -> V_10 = V_343 ;
V_341 -> V_336 = V_336 ;
V_341 -> V_344 = V_344 ;
F_102 ( & V_341 -> V_340 ) ;
V_14 = F_238 ( V_341 , V_5 , V_336 , V_344 ,
V_345 ) ;
if ( V_14 < 0 ) {
F_49 ( V_25 , L_101 , V_14 ) ;
goto V_347;
}
F_154 ( & V_348 ) ;
F_91 ( & V_341 -> V_155 , & V_349 ) ;
F_143 ( & V_348 ) ;
F_41 ( V_341 -> V_25 , L_102 , V_341 -> V_48 ) ;
return V_14 ;
V_347:
F_15 ( V_341 -> V_48 ) ;
return V_14 ;
}
int F_240 ( struct V_24 * V_25 ,
const struct V_342 * V_343 ,
struct V_88 * V_336 ,
int V_344 )
{
struct V_57 * V_341 ;
V_341 = F_232 ( V_25 , sizeof( * V_341 ) , V_36 ) ;
if ( ! V_341 ) {
F_49 ( V_25 , L_103 ) ;
return - V_37 ;
}
V_341 -> V_350 = true ;
V_341 -> V_351 = true ;
return F_239 ( V_25 , V_341 , V_343 , NULL ,
V_336 , V_344 , true ) ;
}
static void F_241 ( struct V_57 * V_341 )
{
F_236 ( V_341 ) ;
F_154 ( & V_348 ) ;
F_75 ( & V_341 -> V_155 ) ;
F_143 ( & V_348 ) ;
F_41 ( V_341 -> V_25 , L_104 , V_341 -> V_48 ) ;
F_15 ( V_341 -> V_48 ) ;
}
void F_242 ( struct V_24 * V_25 )
{
struct V_57 * V_341 ;
F_33 (cmpnt, &component_list, list) {
if ( V_25 == V_341 -> V_25 && V_341 -> V_351 )
goto V_275;
}
return;
V_275:
F_241 ( V_341 ) ;
}
static int F_243 ( struct V_57 * V_58 ,
unsigned int V_6 , unsigned int V_1 )
{
struct V_54 * V_55 = F_244 ( V_58 ) ;
return V_55 -> V_10 -> V_352 ( V_55 , V_6 , V_1 ) ;
}
static int F_245 ( struct V_57 * V_58 ,
unsigned int V_6 , unsigned int * V_1 )
{
struct V_54 * V_55 = F_244 ( V_58 ) ;
* V_1 = V_55 -> V_10 -> V_353 ( V_55 , V_6 ) ;
return 0 ;
}
int F_246 ( struct V_24 * V_25 , struct V_54 * V_55 ,
const struct V_157 * V_354 )
{
int V_14 ;
V_55 -> V_48 = F_233 ( V_25 , & V_55 -> V_242 ) ;
if ( V_55 -> V_48 == NULL )
return - V_37 ;
V_55 -> V_25 = V_25 ;
V_55 -> V_10 = V_354 ;
V_55 -> V_53 . V_25 = V_25 ;
V_55 -> V_53 . V_55 = V_55 ;
V_55 -> V_53 . V_58 = & V_55 -> V_58 ;
V_55 -> V_53 . V_355 = V_354 -> V_355 ;
if ( V_354 -> V_352 )
V_55 -> V_58 . V_352 = F_243 ;
if ( V_354 -> V_353 )
V_55 -> V_58 . V_353 = F_245 ;
V_14 = F_239 ( V_25 , & V_55 -> V_58 ,
& V_354 -> V_356 ,
NULL , NULL , 0 , false ) ;
if ( V_14 < 0 ) {
F_49 ( V_55 -> V_58 . V_25 ,
L_105 , V_14 ) ;
return V_14 ;
}
F_154 ( & V_348 ) ;
F_91 ( & V_55 -> V_155 , & V_357 ) ;
F_143 ( & V_348 ) ;
F_41 ( V_25 , L_106 , V_55 -> V_48 ) ;
return 0 ;
}
int F_247 ( struct V_24 * V_25 ,
const struct V_157 * V_354 )
{
struct V_54 * V_55 ;
int V_14 ;
F_41 ( V_25 , L_107 , F_72 ( V_25 ) ) ;
V_55 = F_98 ( sizeof( struct V_54 ) , V_36 ) ;
if ( V_55 == NULL )
return - V_37 ;
V_14 = F_246 ( V_25 , V_55 , V_354 ) ;
if ( V_14 )
F_15 ( V_55 ) ;
return V_14 ;
}
void F_248 ( struct V_54 * V_55 )
{
F_241 ( & V_55 -> V_58 ) ;
F_154 ( & V_348 ) ;
F_75 ( & V_55 -> V_155 ) ;
F_143 ( & V_348 ) ;
F_41 ( V_55 -> V_25 , L_108 ,
V_55 -> V_48 ) ;
F_15 ( V_55 -> V_48 ) ;
}
struct V_54 * F_249 ( struct V_24 * V_25 )
{
struct V_54 * V_55 ;
F_33 (platform, &platform_list, list) {
if ( V_25 == V_55 -> V_25 )
return V_55 ;
}
return NULL ;
}
void F_250 ( struct V_24 * V_25 )
{
struct V_54 * V_55 ;
V_55 = F_249 ( V_25 ) ;
if ( ! V_55 )
return;
F_248 ( V_55 ) ;
F_15 ( V_55 ) ;
}
static void F_251 ( struct V_358 * V_67 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_138 ( V_359 ) ; V_3 ++ )
if ( V_67 -> V_360 & V_359 [ V_3 ] )
V_67 -> V_360 |= V_359 [ V_3 ] ;
}
static int F_252 ( struct V_57 * V_58 ,
unsigned int V_6 , unsigned int V_1 )
{
struct V_4 * V_5 = F_253 ( V_58 ) ;
return V_5 -> V_10 -> V_352 ( V_5 , V_6 , V_1 ) ;
}
static int F_254 ( struct V_57 * V_58 ,
unsigned int V_6 , unsigned int * V_1 )
{
struct V_4 * V_5 = F_253 ( V_58 ) ;
* V_1 = V_5 -> V_10 -> V_353 ( V_5 , V_6 ) ;
return 0 ;
}
int F_255 ( struct V_24 * V_25 ,
const struct V_145 * V_361 ,
struct V_88 * V_336 ,
int V_344 )
{
struct V_4 * V_5 ;
struct V_108 * V_108 ;
int V_14 , V_3 ;
F_41 ( V_25 , L_109 , F_72 ( V_25 ) ) ;
V_5 = F_98 ( sizeof( struct V_4 ) , V_36 ) ;
if ( V_5 == NULL )
return - V_37 ;
V_5 -> V_48 = F_233 ( V_25 , & V_5 -> V_242 ) ;
if ( V_5 -> V_48 == NULL ) {
V_14 = - V_37 ;
goto V_362;
}
if ( V_361 -> V_352 )
V_5 -> V_58 . V_352 = F_252 ;
if ( V_361 -> V_353 )
V_5 -> V_58 . V_353 = F_254 ;
V_5 -> V_58 . V_350 = V_361 -> V_350 ;
V_5 -> V_53 . V_101 = V_107 ;
V_5 -> V_53 . V_25 = V_25 ;
V_5 -> V_53 . V_5 = V_5 ;
V_5 -> V_53 . V_58 = & V_5 -> V_58 ;
V_5 -> V_53 . V_363 = V_361 -> V_363 ;
V_5 -> V_53 . V_355 = V_361 -> V_355 ;
V_5 -> V_25 = V_25 ;
V_5 -> V_10 = V_361 ;
V_5 -> V_58 . V_279 = V_361 -> V_13 ;
F_101 ( & V_5 -> V_187 ) ;
if ( ! V_5 -> V_58 . V_352 ) {
if ( V_361 -> V_364 )
V_108 = V_361 -> V_364 ( V_25 ) ;
else
V_108 = F_256 ( V_25 , NULL ) ;
if ( V_108 ) {
V_14 = F_257 ( & V_5 -> V_58 ,
V_108 ) ;
if ( V_14 ) {
F_49 ( V_5 -> V_25 ,
L_110 ,
V_14 ) ;
return V_14 ;
}
}
}
for ( V_3 = 0 ; V_3 < V_344 ; V_3 ++ ) {
F_251 ( & V_336 [ V_3 ] . V_365 ) ;
F_251 ( & V_336 [ V_3 ] . V_366 ) ;
}
F_154 ( & V_348 ) ;
F_91 ( & V_5 -> V_155 , & V_367 ) ;
F_143 ( & V_348 ) ;
V_14 = F_239 ( V_25 , & V_5 -> V_58 ,
& V_361 -> V_356 ,
V_5 , V_336 , V_344 , false ) ;
if ( V_14 < 0 ) {
F_49 ( V_5 -> V_25 , L_111 , V_14 ) ;
goto V_368;
}
F_41 ( V_5 -> V_25 , L_112 , V_5 -> V_48 ) ;
return 0 ;
V_368:
F_154 ( & V_348 ) ;
F_75 ( & V_5 -> V_155 ) ;
F_143 ( & V_348 ) ;
F_15 ( V_5 -> V_48 ) ;
V_362:
F_15 ( V_5 ) ;
return V_14 ;
}
void F_258 ( struct V_24 * V_25 )
{
struct V_4 * V_5 ;
F_33 (codec, &codec_list, list) {
if ( V_25 == V_5 -> V_25 )
goto V_275;
}
return;
V_275:
F_241 ( & V_5 -> V_58 ) ;
F_154 ( & V_348 ) ;
F_75 ( & V_5 -> V_155 ) ;
F_143 ( & V_348 ) ;
F_41 ( V_5 -> V_25 , L_113 , V_5 -> V_48 ) ;
F_259 ( V_5 ) ;
F_15 ( V_5 -> V_48 ) ;
F_15 ( V_5 ) ;
}
int F_260 ( struct V_61 * V_46 ,
const char * V_369 )
{
struct V_117 * V_370 = V_46 -> V_25 -> V_120 ;
int V_14 ;
V_14 = F_261 ( V_370 , V_369 , 0 , & V_46 -> V_48 ) ;
if ( V_14 < 0 && V_14 != - V_17 ) {
F_49 ( V_46 -> V_25 ,
L_114 ,
V_369 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
int F_262 ( struct V_61 * V_46 ,
const char * V_369 )
{
struct V_117 * V_370 = V_46 -> V_25 -> V_120 ;
struct V_172 * V_371 ;
const char * V_236 , * V_372 ;
int V_3 , V_373 , V_374 , V_14 ;
V_374 = F_263 ( V_370 , V_369 ) ;
if ( V_374 < 0 ) {
F_49 ( V_46 -> V_25 ,
L_115 , V_369 ) ;
return - V_17 ;
}
if ( V_374 & 1 ) {
F_49 ( V_46 -> V_25 ,
L_116 , V_369 ) ;
return - V_17 ;
}
V_374 /= 2 ;
if ( ! V_374 ) {
F_49 ( V_46 -> V_25 , L_117 ,
V_369 ) ;
return - V_17 ;
}
V_371 = F_264 ( V_46 -> V_25 , V_374 , sizeof( * V_371 ) ,
V_36 ) ;
if ( ! V_371 ) {
F_49 ( V_46 -> V_25 ,
L_118 ) ;
return - V_37 ;
}
for ( V_3 = 0 ; V_3 < V_374 ; V_3 ++ ) {
V_14 = F_261 ( V_370 , V_369 ,
2 * V_3 , & V_236 ) ;
if ( V_14 ) {
F_49 ( V_46 -> V_25 ,
L_119 ,
V_369 , 2 * V_3 , V_14 ) ;
return - V_17 ;
}
for ( V_373 = 0 ; V_373 < F_138 ( V_375 ) ; V_373 ++ ) {
if ( ! strncmp ( V_236 , V_375 [ V_373 ] . V_48 ,
strlen ( V_375 [ V_373 ] . V_48 ) ) ) {
V_371 [ V_3 ] = V_375 [ V_373 ] ;
break;
}
}
if ( V_373 >= F_138 ( V_375 ) ) {
F_49 ( V_46 -> V_25 ,
L_120 ,
V_236 ) ;
return - V_17 ;
}
V_14 = F_261 ( V_370 , V_369 ,
( 2 * V_3 ) + 1 ,
& V_372 ) ;
if ( V_14 ) {
F_49 ( V_46 -> V_25 ,
L_119 ,
V_369 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_17 ;
}
V_371 [ V_3 ] . V_48 = V_372 ;
}
V_46 -> V_147 = V_371 ;
V_46 -> V_148 = V_374 ;
return 0 ;
}
int F_265 ( struct V_117 * V_370 ,
unsigned int * V_313 ,
unsigned int * V_316 )
{
V_283 V_1 ;
int V_14 ;
if ( F_266 ( V_370 , L_121 ) ) {
V_14 = F_267 ( V_370 , L_121 , & V_1 ) ;
if ( V_14 )
return V_14 ;
if ( V_313 )
* V_313 = V_1 ;
}
if ( F_266 ( V_370 , L_122 ) ) {
V_14 = F_267 ( V_370 , L_122 , & V_1 ) ;
if ( V_14 )
return V_14 ;
if ( V_316 )
* V_316 = V_1 ;
}
return 0 ;
}
int F_268 ( struct V_61 * V_46 ,
const char * V_369 )
{
struct V_117 * V_370 = V_46 -> V_25 -> V_120 ;
int V_376 ;
struct V_377 * V_378 ;
int V_3 , V_14 ;
V_376 = F_263 ( V_370 , V_369 ) ;
if ( V_376 < 0 || V_376 & 1 ) {
F_49 ( V_46 -> V_25 ,
L_123 ,
V_369 ) ;
return - V_17 ;
}
V_376 /= 2 ;
if ( ! V_376 ) {
F_49 ( V_46 -> V_25 , L_117 ,
V_369 ) ;
return - V_17 ;
}
V_378 = F_232 ( V_46 -> V_25 , V_376 * sizeof( * V_378 ) ,
V_36 ) ;
if ( ! V_378 ) {
F_49 ( V_46 -> V_25 ,
L_124 ) ;
return - V_17 ;
}
for ( V_3 = 0 ; V_3 < V_376 ; V_3 ++ ) {
V_14 = F_261 ( V_370 , V_369 ,
2 * V_3 , & V_378 [ V_3 ] . V_379 ) ;
if ( V_14 ) {
F_49 ( V_46 -> V_25 ,
L_125 ,
V_369 , 2 * V_3 , V_14 ) ;
return - V_17 ;
}
V_14 = F_261 ( V_370 , V_369 ,
( 2 * V_3 ) + 1 , & V_378 [ V_3 ] . V_302 ) ;
if ( V_14 ) {
F_49 ( V_46 -> V_25 ,
L_125 ,
V_369 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_17 ;
}
}
V_46 -> V_154 = V_376 ;
V_46 -> V_153 = V_378 ;
return 0 ;
}
unsigned int F_269 ( struct V_117 * V_370 ,
const char * V_235 ,
struct V_117 * * V_380 ,
struct V_117 * * V_381 )
{
int V_14 , V_3 ;
char V_382 [ 128 ] ;
unsigned int V_383 = 0 ;
int V_384 , V_385 ;
const char * V_386 ;
struct {
char * V_48 ;
unsigned int V_1 ;
} V_387 [] = {
{ L_126 , V_388 } ,
{ L_127 , V_389 } ,
{ L_128 , V_390 } ,
{ L_129 , V_391 } ,
{ L_130 , V_392 } ,
{ L_131 , V_393 } ,
{ L_132 , V_394 } ,
{ L_133 , V_395 } ,
{ L_134 , V_396 } ,
} ;
if ( ! V_235 )
V_235 = L_135 ;
snprintf ( V_382 , sizeof( V_382 ) , L_136 , V_235 ) ;
V_14 = F_270 ( V_370 , V_382 , & V_386 ) ;
if ( V_14 == 0 ) {
for ( V_3 = 0 ; V_3 < F_138 ( V_387 ) ; V_3 ++ ) {
if ( strcmp ( V_386 , V_387 [ V_3 ] . V_48 ) == 0 ) {
V_383 |= V_387 [ V_3 ] . V_1 ;
break;
}
}
}
snprintf ( V_382 , sizeof( V_382 ) , L_137 , V_235 ) ;
if ( F_271 ( V_370 , V_382 , NULL ) )
V_383 |= V_397 ;
else
V_383 |= V_398 ;
snprintf ( V_382 , sizeof( V_382 ) , L_138 , V_235 ) ;
V_384 = ! ! F_271 ( V_370 , V_382 , NULL ) ;
snprintf ( V_382 , sizeof( V_382 ) , L_139 , V_235 ) ;
V_385 = ! ! F_271 ( V_370 , V_382 , NULL ) ;
switch ( ( V_384 << 4 ) + V_385 ) {
case 0x11 :
V_383 |= V_399 ;
break;
case 0x10 :
V_383 |= V_400 ;
break;
case 0x01 :
V_383 |= V_401 ;
break;
default:
break;
}
snprintf ( V_382 , sizeof( V_382 ) , L_140 , V_235 ) ;
V_384 = ! ! F_271 ( V_370 , V_382 , NULL ) ;
if ( V_384 && V_380 )
* V_380 = F_272 ( V_370 , V_382 , 0 ) ;
snprintf ( V_382 , sizeof( V_382 ) , L_141 , V_235 ) ;
V_385 = ! ! F_271 ( V_370 , V_382 , NULL ) ;
if ( V_385 && V_381 )
* V_381 = F_272 ( V_370 , V_382 , 0 ) ;
switch ( ( V_384 << 4 ) + V_385 ) {
case 0x11 :
V_383 |= V_198 ;
break;
case 0x10 :
V_383 |= V_200 ;
break;
case 0x01 :
V_383 |= V_201 ;
break;
default:
V_383 |= V_199 ;
break;
}
return V_383 ;
}
int F_273 ( struct V_117 * V_120 ,
const char * * V_402 )
{
struct V_57 * V_19 ;
struct V_403 args ;
int V_14 ;
V_14 = F_274 ( V_120 , L_142 ,
L_143 , 0 , & args ) ;
if ( V_14 )
return V_14 ;
V_14 = - V_128 ;
F_154 ( & V_348 ) ;
F_33 (pos, &component_list, list) {
if ( V_19 -> V_25 -> V_120 != args . V_370 )
continue;
if ( V_19 -> V_10 -> V_404 ) {
V_14 = V_19 -> V_10 -> V_404 ( V_19 , & args , V_402 ) ;
} else {
int V_242 = - 1 ;
switch ( args . V_405 ) {
case 0 :
V_242 = 0 ;
break;
case 1 :
V_242 = args . args [ 0 ] ;
break;
default:
break;
}
if ( V_242 < 0 || V_242 >= V_19 -> V_344 ) {
V_14 = - V_17 ;
continue;
}
V_14 = 0 ;
* V_402 = V_19 -> V_336 [ V_242 ] . V_48 ;
if ( ! * V_402 )
* V_402 = V_19 -> V_48 ;
}
break;
}
F_143 ( & V_348 ) ;
F_275 ( args . V_370 ) ;
return V_14 ;
}
static int T_5 F_276 ( void )
{
#ifdef F_107
V_62 = F_23 ( L_144 , NULL ) ;
if ( F_163 ( V_62 ) || ! V_62 ) {
F_277 ( L_145 ) ;
V_62 = NULL ;
}
if ( ! F_26 ( L_146 , 0444 , V_62 , NULL ,
& V_406 ) )
F_277 ( L_147 ) ;
if ( ! F_26 ( L_148 , 0444 , V_62 , NULL ,
& V_407 ) )
F_277 ( L_149 ) ;
if ( ! F_26 ( L_150 , 0444 , V_62 , NULL ,
& V_408 ) )
F_277 ( L_151 ) ;
#endif
F_278 () ;
return F_279 ( & V_409 ) ;
}
static void T_6 F_280 ( void )
{
F_281 () ;
#ifdef F_107
F_29 ( V_62 ) ;
#endif
F_282 ( & V_409 ) ;
}
