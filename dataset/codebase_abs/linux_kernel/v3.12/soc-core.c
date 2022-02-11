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
if ( ! F_6 ( V_5 , V_3 ) )
continue;
if ( V_5 -> V_10 -> V_24 ) {
V_18 += V_5 -> V_10 -> V_24 ( V_5 , V_7 + V_18 ,
V_25 - V_18 , V_3 ) ;
} else {
if ( V_22 >= V_19 ) {
if ( V_21 + V_8 >= V_18 - 1 )
break;
F_2 ( V_5 , V_3 , V_7 + V_21 , V_8 ) ;
V_21 += V_8 ;
}
V_22 += V_8 ;
}
}
V_21 = F_7 ( V_21 , V_18 - 1 ) ;
return V_21 ;
}
static T_2 F_8 ( struct V_26 * V_27 ,
struct V_28 * V_29 , char * V_7 )
{
struct V_30 * V_31 = F_9 ( V_27 ) ;
return F_5 ( V_31 -> V_5 , V_7 , V_25 , 0 ) ;
}
static T_2 F_10 ( struct V_26 * V_27 ,
struct V_28 * V_29 , char * V_7 )
{
struct V_30 * V_31 = F_9 ( V_27 ) ;
return sprintf ( V_7 , L_3 , V_31 -> V_32 ) ;
}
static T_2 F_11 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
const char * V_7 , T_1 V_18 )
{
struct V_30 * V_31 = F_9 ( V_27 ) ;
int V_14 ;
V_14 = F_12 ( V_7 , 10 , & V_31 -> V_32 ) ;
if ( V_14 )
return V_14 ;
return V_18 ;
}
static T_2 F_13 ( struct V_33 * V_33 , char T_4 * V_34 ,
T_1 V_18 , T_3 * V_35 )
{
T_2 V_14 ;
struct V_4 * V_5 = V_33 -> V_36 ;
char * V_7 ;
if ( * V_35 < 0 || ! V_18 )
return - V_17 ;
V_7 = F_14 ( V_18 , V_37 ) ;
if ( ! V_7 )
return - V_38 ;
V_14 = F_5 ( V_5 , V_7 , V_18 , * V_35 ) ;
if ( V_14 >= 0 ) {
if ( F_15 ( V_34 , V_7 , V_14 ) ) {
F_16 ( V_7 ) ;
return - V_39 ;
}
* V_35 += V_14 ;
}
F_16 ( V_7 ) ;
return V_14 ;
}
static T_2 F_17 ( struct V_33 * V_33 ,
const char T_4 * V_34 , T_1 V_18 , T_3 * V_35 )
{
char V_7 [ 32 ] ;
T_1 V_40 ;
char * V_41 = V_7 ;
unsigned long V_6 , V_42 ;
struct V_4 * V_5 = V_33 -> V_36 ;
int V_14 ;
V_40 = F_7 ( V_18 , ( sizeof( V_7 ) - 1 ) ) ;
if ( F_18 ( V_7 , V_34 , V_40 ) )
return - V_39 ;
V_7 [ V_40 ] = 0 ;
while ( * V_41 == ' ' )
V_41 ++ ;
V_6 = F_19 ( V_41 , & V_41 , 16 ) ;
while ( * V_41 == ' ' )
V_41 ++ ;
V_14 = F_20 ( V_41 , 16 , & V_42 ) ;
if ( V_14 )
return V_14 ;
F_21 ( V_43 , V_44 ) ;
F_22 ( V_5 , V_6 , V_42 ) ;
return V_40 ;
}
static void F_23 ( struct V_4 * V_5 )
{
struct V_45 * V_46 = V_5 -> V_47 -> V_46 ;
V_5 -> V_48 = F_24 ( V_5 -> V_49 ,
V_46 ) ;
if ( ! V_5 -> V_48 ) {
F_25 ( V_5 -> V_27 ,
L_4 ) ;
return;
}
F_26 ( L_5 , 0444 , V_5 -> V_48 ,
& V_5 -> V_50 ) ;
F_26 ( L_6 , 0444 , V_5 -> V_48 ,
& V_5 -> V_51 ) ;
V_5 -> V_52 = F_27 ( L_7 , 0644 ,
V_5 -> V_48 ,
V_5 , & V_53 ) ;
if ( ! V_5 -> V_52 )
F_25 ( V_5 -> V_27 ,
L_8 ) ;
F_28 ( & V_5 -> V_54 , V_5 -> V_48 ) ;
}
static void F_29 ( struct V_4 * V_5 )
{
F_30 ( V_5 -> V_48 ) ;
}
static void F_31 ( struct V_55 * V_56 )
{
struct V_45 * V_46 = V_56 -> V_47 -> V_46 ;
V_56 -> V_57 = F_24 ( V_56 -> V_49 ,
V_46 ) ;
if ( ! V_56 -> V_57 ) {
F_25 ( V_56 -> V_27 ,
L_9 ) ;
return;
}
F_28 ( & V_56 -> V_54 ,
V_56 -> V_57 ) ;
}
static void F_32 ( struct V_55 * V_56 )
{
F_30 ( V_56 -> V_57 ) ;
}
static T_2 F_33 ( struct V_33 * V_33 , char T_4 * V_34 ,
T_1 V_18 , T_3 * V_35 )
{
char * V_7 = F_14 ( V_25 , V_37 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_4 * V_5 ;
if ( ! V_7 )
return - V_38 ;
F_34 (codec, &codec_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_25 - V_14 , L_10 ,
V_5 -> V_49 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_25 ) {
V_14 = V_25 ;
break;
}
}
if ( V_14 >= 0 )
V_14 = F_35 ( V_34 , V_18 , V_35 , V_7 , V_14 ) ;
F_16 ( V_7 ) ;
return V_14 ;
}
static T_2 F_36 ( struct V_33 * V_33 , char T_4 * V_34 ,
T_1 V_18 , T_3 * V_35 )
{
char * V_7 = F_14 ( V_25 , V_37 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_58 * V_59 ;
if ( ! V_7 )
return - V_38 ;
F_34 (dai, &dai_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_25 - V_14 , L_10 , V_59 -> V_49 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_25 ) {
V_14 = V_25 ;
break;
}
}
V_14 = F_35 ( V_34 , V_18 , V_35 , V_7 , V_14 ) ;
F_16 ( V_7 ) ;
return V_14 ;
}
static T_2 F_37 ( struct V_33 * V_33 ,
char T_4 * V_34 ,
T_1 V_18 , T_3 * V_35 )
{
char * V_7 = F_14 ( V_25 , V_37 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_55 * V_56 ;
if ( ! V_7 )
return - V_38 ;
F_34 (platform, &platform_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_25 - V_14 , L_10 ,
V_56 -> V_49 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_25 ) {
V_14 = V_25 ;
break;
}
}
V_14 = F_35 ( V_34 , V_18 , V_35 , V_7 , V_14 ) ;
F_16 ( V_7 ) ;
return V_14 ;
}
static void F_38 ( struct V_60 * V_47 )
{
V_47 -> V_46 = F_24 ( V_47 -> V_49 ,
V_61 ) ;
if ( ! V_47 -> V_46 ) {
F_25 ( V_47 -> V_27 ,
L_11 ) ;
return;
}
V_47 -> V_62 = F_39 ( L_12 , 0644 ,
V_47 -> V_46 ,
& V_47 -> V_63 ) ;
if ( ! V_47 -> V_62 )
F_25 ( V_47 -> V_27 ,
L_13 ) ;
}
static void F_40 ( struct V_60 * V_47 )
{
F_30 ( V_47 -> V_46 ) ;
}
static inline void F_23 ( struct V_4 * V_5 )
{
}
static inline void F_29 ( struct V_4 * V_5 )
{
}
static inline void F_31 ( struct V_55 * V_56 )
{
}
static inline void F_32 ( struct V_55 * V_56 )
{
}
static inline void F_38 ( struct V_60 * V_47 )
{
}
static inline void F_40 ( struct V_60 * V_47 )
{
}
struct V_64 * F_41 ( struct V_60 * V_47 ,
const char * V_65 , int V_66 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_47 -> V_67 ; V_3 ++ ) {
if ( V_47 -> V_31 [ V_3 ] . V_65 -> V_68 &&
! strcmp ( V_47 -> V_31 [ V_3 ] . V_65 -> V_49 , V_65 ) )
return V_47 -> V_31 [ V_3 ] . V_69 -> V_70 [ V_66 ] . V_71 ;
}
F_42 ( V_47 -> V_27 , L_14 , V_65 ) ;
return NULL ;
}
struct V_30 * F_43 ( struct V_60 * V_47 ,
const char * V_65 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_47 -> V_67 ; V_3 ++ ) {
if ( ! strcmp ( V_47 -> V_31 [ V_3 ] . V_65 -> V_49 , V_65 ) )
return & V_47 -> V_31 [ V_3 ] ;
}
F_42 ( V_47 -> V_27 , L_15 , V_65 ) ;
return NULL ;
}
static int F_44 ( struct V_4 * V_5 )
{
if ( V_5 -> V_72 -> V_27 . V_73 )
F_45 ( & V_5 -> V_72 -> V_27 ) ;
return 0 ;
}
static void F_46 ( struct V_26 * V_27 ) {}
static int F_47 ( struct V_4 * V_5 )
{
int V_74 ;
V_5 -> V_72 -> V_27 . V_73 = & V_75 ;
V_5 -> V_72 -> V_27 . V_76 = V_5 -> V_47 -> V_27 ;
V_5 -> V_72 -> V_27 . V_77 = F_46 ;
F_48 ( & V_5 -> V_72 -> V_27 , L_16 ,
V_5 -> V_47 -> V_78 -> V_79 , 0 , V_5 -> V_49 ) ;
V_74 = F_49 ( & V_5 -> V_72 -> V_27 ) ;
if ( V_74 < 0 ) {
F_50 ( V_5 -> V_27 , L_17 ) ;
V_5 -> V_72 -> V_27 . V_73 = NULL ;
return V_74 ;
}
return 0 ;
}
static void F_51 ( struct V_80 * V_81 )
{
}
int F_52 ( struct V_26 * V_27 )
{
struct V_60 * V_47 = F_9 ( V_27 ) ;
struct V_4 * V_5 ;
int V_3 ;
if ( F_53 ( & V_47 -> V_82 ) )
return 0 ;
F_54 ( V_47 -> V_78 ) ;
F_55 ( V_47 -> V_78 , V_83 ) ;
F_56 ( V_47 -> V_78 ) ;
F_57 ( V_47 -> V_78 , V_84 ) ;
for ( V_3 = 0 ; V_3 < V_47 -> V_85 ; V_3 ++ ) {
struct V_58 * V_59 = V_47 -> V_31 [ V_3 ] . V_86 ;
struct V_87 * V_88 = V_59 -> V_10 ;
if ( V_47 -> V_31 [ V_3 ] . V_65 -> V_89 )
continue;
if ( V_88 -> V_90 -> V_91 && V_59 -> V_92 )
V_88 -> V_90 -> V_91 ( V_59 , 1 ) ;
}
for ( V_3 = 0 ; V_3 < V_47 -> V_85 ; V_3 ++ ) {
if ( V_47 -> V_31 [ V_3 ] . V_65 -> V_89 )
continue;
F_58 ( V_47 -> V_31 [ V_3 ] . V_69 ) ;
}
if ( V_47 -> V_93 )
V_47 -> V_93 ( V_47 ) ;
for ( V_3 = 0 ; V_3 < V_47 -> V_85 ; V_3 ++ ) {
struct V_58 * V_94 = V_47 -> V_31 [ V_3 ] . V_94 ;
struct V_55 * V_56 = V_47 -> V_31 [ V_3 ] . V_56 ;
if ( V_47 -> V_31 [ V_3 ] . V_65 -> V_89 )
continue;
if ( V_94 -> V_10 -> V_95 && ! V_94 -> V_10 -> V_96 )
V_94 -> V_10 -> V_95 ( V_94 ) ;
if ( V_56 -> V_10 -> V_95 && ! V_56 -> V_97 ) {
V_56 -> V_10 -> V_95 ( V_94 ) ;
V_56 -> V_97 = 1 ;
}
}
for ( V_3 = 0 ; V_3 < V_47 -> V_85 ; V_3 ++ ) {
F_59 ( & V_47 -> V_31 [ V_3 ] . V_98 ) ;
V_47 -> V_31 [ V_3 ] . V_5 -> V_54 . V_99 = V_47 -> V_31 [ V_3 ] . V_5 -> V_54 . V_100 ;
}
for ( V_3 = 0 ; V_3 < V_47 -> V_85 ; V_3 ++ ) {
if ( V_47 -> V_31 [ V_3 ] . V_65 -> V_89 )
continue;
F_60 ( & V_47 -> V_31 [ V_3 ] ,
V_101 ,
V_102 ) ;
F_60 ( & V_47 -> V_31 [ V_3 ] ,
V_103 ,
V_102 ) ;
}
F_61 ( & V_47 -> V_54 ) ;
F_62 ( & V_47 -> V_54 ) ;
F_34 (codec, &card->codec_dev_list, card_list) {
if ( ! V_5 -> V_97 && V_5 -> V_10 -> V_95 ) {
switch ( V_5 -> V_54 . V_100 ) {
case V_104 :
if ( V_5 -> V_54 . V_105 ) {
F_42 ( V_5 -> V_27 ,
L_18 ) ;
break;
}
case V_106 :
V_5 -> V_10 -> V_95 ( V_5 ) ;
V_5 -> V_97 = 1 ;
V_5 -> V_50 = 1 ;
if ( V_5 -> V_107 )
F_63 ( V_5 -> V_108 ) ;
break;
default:
F_42 ( V_5 -> V_27 ,
L_19 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_47 -> V_85 ; V_3 ++ ) {
struct V_58 * V_94 = V_47 -> V_31 [ V_3 ] . V_94 ;
if ( V_47 -> V_31 [ V_3 ] . V_65 -> V_89 )
continue;
if ( V_94 -> V_10 -> V_95 && V_94 -> V_10 -> V_96 )
V_94 -> V_10 -> V_95 ( V_94 ) ;
}
if ( V_47 -> V_109 )
V_47 -> V_109 ( V_47 ) ;
return 0 ;
}
static void F_64 ( struct V_80 * V_81 )
{
struct V_60 * V_47 =
F_65 ( V_81 , struct V_60 , V_110 ) ;
struct V_4 * V_5 ;
int V_3 ;
F_42 ( V_47 -> V_27 , L_20 ) ;
F_57 ( V_47 -> V_78 , V_111 ) ;
if ( V_47 -> V_112 )
V_47 -> V_112 ( V_47 ) ;
for ( V_3 = 0 ; V_3 < V_47 -> V_85 ; V_3 ++ ) {
struct V_58 * V_94 = V_47 -> V_31 [ V_3 ] . V_94 ;
if ( V_47 -> V_31 [ V_3 ] . V_65 -> V_89 )
continue;
if ( V_94 -> V_10 -> V_113 && V_94 -> V_10 -> V_96 )
V_94 -> V_10 -> V_113 ( V_94 ) ;
}
F_34 (codec, &card->codec_dev_list, card_list) {
if ( V_5 -> V_10 -> V_113 && V_5 -> V_97 ) {
switch ( V_5 -> V_54 . V_100 ) {
case V_104 :
case V_106 :
V_5 -> V_10 -> V_113 ( V_5 ) ;
V_5 -> V_97 = 0 ;
break;
default:
F_42 ( V_5 -> V_27 ,
L_21 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_47 -> V_85 ; V_3 ++ ) {
if ( V_47 -> V_31 [ V_3 ] . V_65 -> V_89 )
continue;
F_60 ( & V_47 -> V_31 [ V_3 ] ,
V_101 ,
V_114 ) ;
F_60 ( & V_47 -> V_31 [ V_3 ] ,
V_103 ,
V_114 ) ;
}
for ( V_3 = 0 ; V_3 < V_47 -> V_85 ; V_3 ++ ) {
struct V_58 * V_59 = V_47 -> V_31 [ V_3 ] . V_86 ;
struct V_87 * V_88 = V_59 -> V_10 ;
if ( V_47 -> V_31 [ V_3 ] . V_65 -> V_89 )
continue;
if ( V_88 -> V_90 -> V_91 && V_59 -> V_92 )
V_88 -> V_90 -> V_91 ( V_59 , 0 ) ;
}
for ( V_3 = 0 ; V_3 < V_47 -> V_85 ; V_3 ++ ) {
struct V_58 * V_94 = V_47 -> V_31 [ V_3 ] . V_94 ;
struct V_55 * V_56 = V_47 -> V_31 [ V_3 ] . V_56 ;
if ( V_47 -> V_31 [ V_3 ] . V_65 -> V_89 )
continue;
if ( V_94 -> V_10 -> V_113 && ! V_94 -> V_10 -> V_96 )
V_94 -> V_10 -> V_113 ( V_94 ) ;
if ( V_56 -> V_10 -> V_113 && V_56 -> V_97 ) {
V_56 -> V_10 -> V_113 ( V_94 ) ;
V_56 -> V_97 = 0 ;
}
}
if ( V_47 -> V_115 )
V_47 -> V_115 ( V_47 ) ;
F_42 ( V_47 -> V_27 , L_22 ) ;
F_57 ( V_47 -> V_78 , V_83 ) ;
F_61 ( & V_47 -> V_54 ) ;
F_62 ( & V_47 -> V_54 ) ;
}
int F_66 ( struct V_26 * V_27 )
{
struct V_60 * V_47 = F_9 ( V_27 ) ;
int V_3 , V_96 = 0 ;
if ( F_53 ( & V_47 -> V_82 ) )
return 0 ;
for ( V_3 = 0 ; V_3 < V_47 -> V_85 ; V_3 ++ ) {
struct V_58 * V_94 = V_47 -> V_31 [ V_3 ] . V_94 ;
V_96 |= V_94 -> V_10 -> V_96 ;
}
if ( V_96 ) {
F_42 ( V_27 , L_23 ) ;
F_64 ( & V_47 -> V_110 ) ;
} else {
F_42 ( V_27 , L_24 ) ;
if ( ! F_67 ( & V_47 -> V_110 ) )
F_50 ( V_27 , L_25 ) ;
}
return 0 ;
}
static int F_68 ( struct V_60 * V_47 , int V_116 )
{
struct V_117 * V_65 = & V_47 -> V_65 [ V_116 ] ;
struct V_30 * V_31 = & V_47 -> V_31 [ V_116 ] ;
struct V_4 * V_5 ;
struct V_55 * V_56 ;
struct V_58 * V_86 , * V_94 ;
const char * V_118 ;
F_42 ( V_47 -> V_27 , L_26 , V_65 -> V_49 , V_116 ) ;
F_34 (cpu_dai, &dai_list, list) {
if ( V_65 -> V_119 &&
( V_94 -> V_27 -> V_120 != V_65 -> V_119 ) )
continue;
if ( V_65 -> V_121 &&
strcmp ( F_69 ( V_94 -> V_27 ) , V_65 -> V_121 ) )
continue;
if ( V_65 -> V_122 &&
strcmp ( V_94 -> V_49 , V_65 -> V_122 ) )
continue;
V_31 -> V_94 = V_94 ;
}
if ( ! V_31 -> V_94 ) {
F_50 ( V_47 -> V_27 , L_27 ,
V_65 -> V_122 ) ;
return - V_123 ;
}
F_34 (codec, &codec_list, list) {
if ( V_65 -> V_124 ) {
if ( V_5 -> V_27 -> V_120 != V_65 -> V_124 )
continue;
} else {
if ( strcmp ( V_5 -> V_49 , V_65 -> V_125 ) )
continue;
}
V_31 -> V_5 = V_5 ;
F_34 (codec_dai, &dai_list, list) {
if ( V_5 -> V_27 == V_86 -> V_27 &&
! strcmp ( V_86 -> V_49 ,
V_65 -> V_126 ) ) {
V_31 -> V_86 = V_86 ;
}
}
if ( ! V_31 -> V_86 ) {
F_50 ( V_47 -> V_27 , L_28 ,
V_65 -> V_126 ) ;
return - V_123 ;
}
}
if ( ! V_31 -> V_5 ) {
F_50 ( V_47 -> V_27 , L_29 ,
V_65 -> V_125 ) ;
return - V_123 ;
}
V_118 = V_65 -> V_118 ;
if ( ! V_118 && ! V_65 -> V_127 )
V_118 = L_30 ;
F_34 (platform, &platform_list, list) {
if ( V_65 -> V_127 ) {
if ( V_56 -> V_27 -> V_120 !=
V_65 -> V_127 )
continue;
} else {
if ( strcmp ( V_56 -> V_49 , V_118 ) )
continue;
}
V_31 -> V_56 = V_56 ;
}
if ( ! V_31 -> V_56 ) {
F_50 ( V_47 -> V_27 , L_31 ,
V_65 -> V_118 ) ;
return - V_123 ;
}
V_47 -> V_85 ++ ;
return 0 ;
}
static int F_70 ( struct V_55 * V_56 )
{
int V_14 ;
if ( V_56 -> V_10 -> remove ) {
V_14 = V_56 -> V_10 -> remove ( V_56 ) ;
if ( V_14 < 0 )
F_50 ( V_56 -> V_27 , L_32 ,
V_14 ) ;
}
F_71 ( & V_56 -> V_54 ) ;
F_32 ( V_56 ) ;
V_56 -> V_128 = 0 ;
F_72 ( & V_56 -> V_129 ) ;
F_73 ( V_56 -> V_27 -> V_10 -> V_130 ) ;
return 0 ;
}
static void F_74 ( struct V_4 * V_5 )
{
int V_74 ;
if ( V_5 -> V_10 -> remove ) {
V_74 = V_5 -> V_10 -> remove ( V_5 ) ;
if ( V_74 < 0 )
F_50 ( V_5 -> V_27 , L_32 , V_74 ) ;
}
F_71 ( & V_5 -> V_54 ) ;
F_29 ( V_5 ) ;
V_5 -> V_128 = 0 ;
F_72 ( & V_5 -> V_129 ) ;
F_73 ( V_5 -> V_27 -> V_10 -> V_130 ) ;
}
static void F_75 ( struct V_60 * V_47 , int V_116 , int V_131 )
{
struct V_30 * V_31 = & V_47 -> V_31 [ V_116 ] ;
struct V_58 * V_86 = V_31 -> V_86 , * V_94 = V_31 -> V_94 ;
int V_74 ;
if ( V_31 -> V_132 ) {
F_76 ( V_31 -> V_27 , & V_133 ) ;
F_76 ( V_31 -> V_27 , & V_134 ) ;
F_45 ( V_31 -> V_27 ) ;
V_31 -> V_132 = 0 ;
}
if ( V_86 && V_86 -> V_128 &&
V_86 -> V_10 -> V_135 == V_131 ) {
if ( V_86 -> V_10 -> remove ) {
V_74 = V_86 -> V_10 -> remove ( V_86 ) ;
if ( V_74 < 0 )
F_50 ( V_86 -> V_27 ,
L_33 ,
V_86 -> V_49 , V_74 ) ;
}
V_86 -> V_128 = 0 ;
F_72 ( & V_86 -> V_129 ) ;
}
if ( V_94 && V_94 -> V_128 &&
V_94 -> V_10 -> V_135 == V_131 ) {
if ( V_94 -> V_10 -> remove ) {
V_74 = V_94 -> V_10 -> remove ( V_94 ) ;
if ( V_74 < 0 )
F_50 ( V_94 -> V_27 ,
L_33 ,
V_94 -> V_49 , V_74 ) ;
}
V_94 -> V_128 = 0 ;
F_72 ( & V_94 -> V_129 ) ;
if ( ! V_94 -> V_5 ) {
F_71 ( & V_94 -> V_54 ) ;
F_73 ( V_94 -> V_27 -> V_10 -> V_130 ) ;
}
}
}
static void F_77 ( struct V_60 * V_47 , int V_116 ,
int V_131 )
{
struct V_30 * V_31 = & V_47 -> V_31 [ V_116 ] ;
struct V_58 * V_94 = V_31 -> V_94 ;
struct V_58 * V_86 = V_31 -> V_86 ;
struct V_55 * V_56 = V_31 -> V_56 ;
struct V_4 * V_5 ;
if ( V_56 && V_56 -> V_128 &&
V_56 -> V_10 -> V_135 == V_131 ) {
F_70 ( V_56 ) ;
}
if ( V_86 ) {
V_5 = V_86 -> V_5 ;
if ( V_5 && V_5 -> V_128 &&
V_5 -> V_10 -> V_135 == V_131 )
F_74 ( V_5 ) ;
}
if ( V_94 ) {
V_5 = V_94 -> V_5 ;
if ( V_5 && V_5 -> V_128 &&
V_5 -> V_10 -> V_135 == V_131 )
F_74 ( V_5 ) ;
}
}
static void F_78 ( struct V_60 * V_47 )
{
int V_59 , V_131 ;
for ( V_131 = V_136 ; V_131 <= V_137 ;
V_131 ++ ) {
for ( V_59 = 0 ; V_59 < V_47 -> V_85 ; V_59 ++ )
F_75 ( V_47 , V_59 , V_131 ) ;
}
for ( V_131 = V_136 ; V_131 <= V_137 ;
V_131 ++ ) {
for ( V_59 = 0 ; V_59 < V_47 -> V_85 ; V_59 ++ )
F_77 ( V_47 , V_59 , V_131 ) ;
}
V_47 -> V_85 = 0 ;
}
static void F_79 ( struct V_60 * V_47 ,
struct V_4 * V_5 )
{
int V_3 ;
if ( V_47 -> V_138 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_47 -> V_139 ; V_3 ++ ) {
struct V_140 * V_141 = & V_47 -> V_138 [ V_3 ] ;
if ( V_141 -> F_69 && ! strcmp ( V_5 -> V_49 , V_141 -> F_69 ) ) {
V_5 -> V_142 = V_141 -> V_142 ;
break;
}
}
}
static int F_80 ( struct V_60 * V_47 ,
struct V_4 * V_5 )
{
int V_14 = 0 ;
const struct V_143 * V_10 = V_5 -> V_10 ;
struct V_58 * V_59 ;
V_5 -> V_47 = V_47 ;
V_5 -> V_54 . V_47 = V_47 ;
F_79 ( V_47 , V_5 ) ;
if ( ! F_81 ( V_5 -> V_27 -> V_10 -> V_130 ) )
return - V_144 ;
F_23 ( V_5 ) ;
if ( V_10 -> V_145 )
F_82 ( & V_5 -> V_54 , V_10 -> V_145 ,
V_10 -> V_146 ) ;
F_34 (dai, &dai_list, list) {
if ( V_59 -> V_27 != V_5 -> V_27 )
continue;
F_83 ( & V_5 -> V_54 , V_59 ) ;
}
V_5 -> V_54 . V_105 = V_10 -> V_105 ;
if ( V_10 -> V_147 ) {
V_14 = V_10 -> V_147 ( V_5 ) ;
if ( V_14 < 0 ) {
F_50 ( V_5 -> V_27 ,
L_34 , V_14 ) ;
goto V_148;
}
F_84 ( V_5 -> V_54 . V_105 &&
V_5 -> V_54 . V_100 != V_106 ,
L_35 ,
V_5 -> V_49 ) ;
}
if ( ! V_5 -> V_149 && F_85 ( V_5 -> V_27 , NULL ) )
F_86 ( V_5 , 0 , 0 , V_150 ) ;
if ( V_10 -> V_151 )
F_87 ( V_5 , V_10 -> V_151 ,
V_10 -> V_152 ) ;
if ( V_10 -> V_153 )
F_88 ( & V_5 -> V_54 , V_10 -> V_153 ,
V_10 -> V_154 ) ;
V_5 -> V_128 = 1 ;
F_89 ( & V_5 -> V_129 , & V_47 -> V_82 ) ;
F_89 ( & V_5 -> V_54 . V_155 , & V_47 -> V_156 ) ;
return 0 ;
V_148:
F_29 ( V_5 ) ;
F_73 ( V_5 -> V_27 -> V_10 -> V_130 ) ;
return V_14 ;
}
static int F_90 ( struct V_60 * V_47 ,
struct V_55 * V_56 )
{
int V_14 = 0 ;
const struct V_157 * V_10 = V_56 -> V_10 ;
struct V_58 * V_59 ;
V_56 -> V_47 = V_47 ;
V_56 -> V_54 . V_47 = V_47 ;
if ( ! F_81 ( V_56 -> V_27 -> V_10 -> V_130 ) )
return - V_144 ;
F_31 ( V_56 ) ;
if ( V_10 -> V_145 )
F_82 ( & V_56 -> V_54 ,
V_10 -> V_145 , V_10 -> V_146 ) ;
F_34 (dai, &dai_list, list) {
if ( V_59 -> V_27 != V_56 -> V_27 )
continue;
F_83 ( & V_56 -> V_54 , V_59 ) ;
}
V_56 -> V_54 . V_105 = 1 ;
if ( V_10 -> V_147 ) {
V_14 = V_10 -> V_147 ( V_56 ) ;
if ( V_14 < 0 ) {
F_50 ( V_56 -> V_27 ,
L_36 , V_14 ) ;
goto V_148;
}
}
if ( V_10 -> V_151 )
F_91 ( V_56 , V_10 -> V_151 ,
V_10 -> V_152 ) ;
if ( V_10 -> V_153 )
F_88 ( & V_56 -> V_54 , V_10 -> V_153 ,
V_10 -> V_154 ) ;
V_56 -> V_128 = 1 ;
F_89 ( & V_56 -> V_129 , & V_47 -> V_158 ) ;
F_89 ( & V_56 -> V_54 . V_155 , & V_47 -> V_156 ) ;
return 0 ;
V_148:
F_32 ( V_56 ) ;
F_73 ( V_56 -> V_27 -> V_10 -> V_130 ) ;
return V_14 ;
}
static void F_92 ( struct V_26 * V_27 )
{
F_16 ( V_27 ) ;
}
static int F_93 ( struct V_60 * V_47 ,
struct V_4 * V_5 ,
int V_116 , int V_159 )
{
struct V_117 * V_65 = NULL ;
struct V_160 * V_161 = NULL ;
struct V_30 * V_31 ;
const char * V_162 , * V_49 ;
int V_14 = 0 ;
if ( ! V_159 ) {
V_65 = & V_47 -> V_65 [ V_116 ] ;
V_31 = & V_47 -> V_31 [ V_116 ] ;
V_49 = V_65 -> V_49 ;
} else {
V_161 = & V_47 -> V_161 [ V_116 ] ;
V_31 = & V_47 -> V_163 [ V_116 ] ;
V_49 = V_161 -> V_49 ;
}
V_31 -> V_47 = V_47 ;
V_162 = V_5 -> V_142 ;
V_5 -> V_142 = NULL ;
if ( ! V_159 && V_65 -> V_164 )
V_14 = V_65 -> V_164 ( V_31 ) ;
else if ( V_159 && V_161 -> V_164 )
V_14 = V_161 -> V_164 ( & V_5 -> V_54 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 , L_37 , V_49 , V_14 ) ;
return V_14 ;
}
V_5 -> V_142 = V_162 ;
V_31 -> V_5 = V_5 ;
V_31 -> V_27 = F_94 ( sizeof( struct V_26 ) , V_37 ) ;
if ( ! V_31 -> V_27 )
return - V_38 ;
F_95 ( V_31 -> V_27 ) ;
V_31 -> V_27 -> V_76 = V_47 -> V_27 ;
V_31 -> V_27 -> V_77 = F_92 ;
V_31 -> V_27 -> V_165 = V_49 ;
F_96 ( V_31 -> V_27 , V_31 ) ;
F_97 ( & V_31 -> V_166 ) ;
F_98 ( & V_31 -> V_167 [ V_101 ] . V_168 ) ;
F_98 ( & V_31 -> V_167 [ V_103 ] . V_168 ) ;
F_98 ( & V_31 -> V_167 [ V_101 ] . V_169 ) ;
F_98 ( & V_31 -> V_167 [ V_103 ] . V_169 ) ;
V_14 = F_99 ( V_31 -> V_27 ) ;
if ( V_14 < 0 ) {
F_100 ( V_31 -> V_27 ) ;
F_50 ( V_47 -> V_27 ,
L_38 , V_14 ) ;
return V_14 ;
}
V_31 -> V_132 = 1 ;
V_14 = F_101 ( V_31 -> V_27 ) ;
if ( V_14 < 0 )
F_50 ( V_5 -> V_27 ,
L_39 , V_14 ) ;
V_14 = F_102 ( V_31 -> V_27 , & V_134 ) ;
if ( V_14 < 0 )
F_50 ( V_5 -> V_27 ,
L_40 , V_14 ) ;
#ifdef F_103
if ( ! V_159 && ! V_65 -> V_170 )
goto V_171;
V_14 = F_104 ( V_31 ) ;
if ( V_14 < 0 )
F_50 ( V_31 -> V_27 , L_41 , V_14 ) ;
V_171:
#endif
return 0 ;
}
static int F_105 ( struct V_60 * V_47 , int V_116 ,
int V_131 )
{
struct V_30 * V_31 = & V_47 -> V_31 [ V_116 ] ;
struct V_58 * V_94 = V_31 -> V_94 ;
struct V_58 * V_86 = V_31 -> V_86 ;
struct V_55 * V_56 = V_31 -> V_56 ;
int V_14 ;
if ( V_94 -> V_5 &&
! V_94 -> V_5 -> V_128 &&
V_94 -> V_5 -> V_10 -> V_172 == V_131 ) {
V_14 = F_80 ( V_47 , V_94 -> V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_86 -> V_5 -> V_128 &&
V_86 -> V_5 -> V_10 -> V_172 == V_131 ) {
V_14 = F_80 ( V_47 , V_86 -> V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_56 -> V_128 &&
V_56 -> V_10 -> V_172 == V_131 ) {
V_14 = F_90 ( V_47 , V_56 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
static int F_106 ( struct V_60 * V_47 , int V_116 , int V_131 )
{
struct V_117 * V_65 = & V_47 -> V_65 [ V_116 ] ;
struct V_30 * V_31 = & V_47 -> V_31 [ V_116 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
struct V_55 * V_56 = V_31 -> V_56 ;
struct V_58 * V_86 = V_31 -> V_86 ;
struct V_58 * V_94 = V_31 -> V_94 ;
struct V_173 * V_174 , * V_175 ;
int V_14 ;
F_42 ( V_47 -> V_27 , L_42 ,
V_47 -> V_49 , V_116 , V_131 ) ;
V_94 -> V_56 = V_56 ;
V_86 -> V_47 = V_47 ;
V_94 -> V_47 = V_47 ;
V_31 -> V_32 = V_32 ;
if ( ! V_94 -> V_128 &&
V_94 -> V_10 -> V_172 == V_131 ) {
if ( ! V_94 -> V_5 ) {
V_94 -> V_54 . V_47 = V_47 ;
if ( ! F_81 ( V_94 -> V_27 -> V_10 -> V_130 ) )
return - V_144 ;
F_89 ( & V_94 -> V_54 . V_155 , & V_47 -> V_156 ) ;
}
if ( V_94 -> V_10 -> V_147 ) {
V_14 = V_94 -> V_10 -> V_147 ( V_94 ) ;
if ( V_14 < 0 ) {
F_50 ( V_94 -> V_27 ,
L_43 ,
V_94 -> V_49 , V_14 ) ;
F_73 ( V_94 -> V_27 -> V_10 -> V_130 ) ;
return V_14 ;
}
}
V_94 -> V_128 = 1 ;
F_89 ( & V_94 -> V_129 , & V_47 -> V_176 ) ;
}
if ( ! V_86 -> V_128 && V_86 -> V_10 -> V_172 == V_131 ) {
if ( V_86 -> V_10 -> V_147 ) {
V_14 = V_86 -> V_10 -> V_147 ( V_86 ) ;
if ( V_14 < 0 ) {
F_50 ( V_86 -> V_27 ,
L_44 ,
V_86 -> V_49 , V_14 ) ;
return V_14 ;
}
}
V_86 -> V_128 = 1 ;
F_89 ( & V_86 -> V_129 , & V_47 -> V_176 ) ;
}
if ( V_131 != V_137 )
return 0 ;
V_14 = F_93 ( V_47 , V_5 , V_116 , 0 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_102 ( V_31 -> V_27 , & V_133 ) ;
if ( V_14 < 0 )
F_25 ( V_31 -> V_27 , L_45 ,
V_14 ) ;
if ( V_94 -> V_10 -> V_177 ) {
V_14 = F_107 ( V_31 , V_116 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 , L_46 ,
V_65 -> V_178 ) ;
return V_14 ;
}
} else {
if ( ! V_65 -> V_179 ) {
V_14 = F_108 ( V_31 , V_116 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 , L_47 ,
V_65 -> V_178 , V_14 ) ;
return V_14 ;
}
} else {
F_109 ( & V_31 -> V_98 ,
F_51 ) ;
V_174 = V_86 -> V_180 ;
V_175 = V_94 -> V_181 ;
if ( V_174 && V_175 ) {
V_14 = F_110 ( V_47 , V_65 -> V_179 ,
V_175 , V_174 ) ;
if ( V_14 != 0 ) {
F_50 ( V_47 -> V_27 , L_48 ,
V_174 -> V_49 , V_175 -> V_49 , V_14 ) ;
return V_14 ;
}
}
V_174 = V_94 -> V_180 ;
V_175 = V_86 -> V_181 ;
if ( V_174 && V_175 ) {
V_14 = F_110 ( V_47 , V_65 -> V_179 ,
V_175 , V_174 ) ;
if ( V_14 != 0 ) {
F_50 ( V_47 -> V_27 , L_48 ,
V_174 -> V_49 , V_175 -> V_49 , V_14 ) ;
return V_14 ;
}
}
}
}
if ( V_31 -> V_86 -> V_10 -> V_96 )
F_111 ( V_5 -> V_72 , V_31 -> V_94 -> V_182 ) ;
return 0 ;
}
static int F_112 ( struct V_30 * V_31 )
{
int V_14 ;
if ( V_31 -> V_86 -> V_10 -> V_96 && ! V_31 -> V_5 -> V_183 ) {
if ( ! V_31 -> V_5 -> V_184 )
return 0 ;
V_14 = F_47 ( V_31 -> V_5 ) ;
if ( V_14 < 0 ) {
F_50 ( V_31 -> V_5 -> V_27 ,
L_49 , V_14 ) ;
return V_14 ;
}
V_31 -> V_5 -> V_183 = 1 ;
}
return 0 ;
}
static void F_113 ( struct V_4 * V_5 )
{
if ( V_5 -> V_183 ) {
F_44 ( V_5 ) ;
V_5 -> V_183 = 0 ;
}
}
static int F_114 ( struct V_60 * V_47 , int V_116 )
{
struct V_160 * V_161 = & V_47 -> V_161 [ V_116 ] ;
struct V_4 * V_5 ;
F_34 (codec, &codec_list, list) {
if ( ! strcmp ( V_5 -> V_49 , V_161 -> V_125 ) )
return 0 ;
}
F_50 ( V_47 -> V_27 , L_50 , V_161 -> V_125 ) ;
return - V_123 ;
}
static int F_115 ( struct V_60 * V_47 , int V_116 )
{
struct V_160 * V_161 = & V_47 -> V_161 [ V_116 ] ;
struct V_4 * V_5 ;
int V_14 = - V_144 ;
F_34 (codec, &codec_list, list) {
if ( ! strcmp ( V_5 -> V_49 , V_161 -> V_125 ) ) {
if ( V_5 -> V_128 ) {
F_50 ( V_5 -> V_27 ,
L_51 ) ;
V_14 = - V_185 ;
goto V_171;
}
goto V_186;
}
}
F_50 ( V_47 -> V_27 , L_52 , V_161 -> V_125 ) ;
return - V_123 ;
V_186:
V_14 = F_80 ( V_47 , V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_93 ( V_47 , V_5 , V_116 , 1 ) ;
V_171:
return V_14 ;
}
static void F_116 ( struct V_60 * V_47 , int V_116 )
{
struct V_30 * V_31 = & V_47 -> V_163 [ V_116 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
if ( V_31 -> V_132 ) {
F_76 ( V_31 -> V_27 , & V_134 ) ;
F_45 ( V_31 -> V_27 ) ;
V_31 -> V_132 = 0 ;
}
if ( V_5 && V_5 -> V_128 )
F_74 ( V_5 ) ;
}
static int F_117 ( struct V_4 * V_5 ,
enum V_187 V_188 )
{
int V_14 ;
if ( V_5 -> V_189 )
return 0 ;
if ( V_188 && V_5 -> V_188 != V_188 )
V_5 -> V_188 = V_188 ;
V_14 = F_118 ( V_5 ) ;
if ( V_14 < 0 ) {
F_50 ( V_5 -> V_27 ,
L_53 ,
V_14 ) ;
return V_14 ;
}
V_5 -> V_189 = 1 ;
return 0 ;
}
static int F_119 ( struct V_60 * V_47 )
{
struct V_4 * V_5 ;
struct V_140 * V_138 ;
enum V_187 V_188 ;
struct V_117 * V_65 ;
int V_14 , V_3 , V_131 , V_190 ;
F_120 ( & V_47 -> V_191 , V_192 ) ;
for ( V_3 = 0 ; V_3 < V_47 -> V_67 ; V_3 ++ ) {
V_14 = F_68 ( V_47 , V_3 ) ;
if ( V_14 != 0 )
goto V_193;
}
for ( V_3 = 0 ; V_3 < V_47 -> V_194 ; V_3 ++ ) {
V_14 = F_114 ( V_47 , V_3 ) ;
if ( V_14 != 0 )
goto V_193;
}
F_34 (codec, &codec_list, list) {
if ( V_5 -> V_189 )
continue;
V_188 = 0 ;
for ( V_3 = 0 ; V_3 < V_47 -> V_139 ; ++ V_3 ) {
V_138 = & V_47 -> V_138 [ V_3 ] ;
if ( ! strcmp ( V_5 -> V_49 , V_138 -> F_69 ) ) {
V_188 = V_138 -> V_188 ;
if ( V_188 && V_188
!= V_5 -> V_188 )
break;
}
}
V_14 = F_117 ( V_5 , V_188 ) ;
if ( V_14 < 0 )
goto V_193;
}
V_14 = F_121 ( V_195 , V_196 ,
V_47 -> V_130 , 0 , & V_47 -> V_78 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 ,
L_54 ,
V_47 -> V_49 , V_14 ) ;
goto V_193;
}
V_47 -> V_78 -> V_27 = V_47 -> V_27 ;
V_47 -> V_54 . V_100 = V_106 ;
V_47 -> V_54 . V_27 = V_47 -> V_27 ;
V_47 -> V_54 . V_47 = V_47 ;
F_89 ( & V_47 -> V_54 . V_155 , & V_47 -> V_156 ) ;
#ifdef F_103
F_28 ( & V_47 -> V_54 , V_47 -> V_46 ) ;
#endif
#ifdef F_122
F_123 ( & V_47 -> V_110 , F_64 ) ;
#endif
if ( V_47 -> V_145 )
F_82 ( & V_47 -> V_54 , V_47 -> V_145 ,
V_47 -> V_146 ) ;
if ( V_47 -> V_147 ) {
V_14 = V_47 -> V_147 ( V_47 ) ;
if ( V_14 < 0 )
goto V_197;
}
for ( V_131 = V_136 ; V_131 <= V_137 ;
V_131 ++ ) {
for ( V_3 = 0 ; V_3 < V_47 -> V_67 ; V_3 ++ ) {
V_14 = F_105 ( V_47 , V_3 , V_131 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 ,
L_55 ,
V_14 ) ;
goto V_198;
}
}
}
for ( V_131 = V_136 ; V_131 <= V_137 ;
V_131 ++ ) {
for ( V_3 = 0 ; V_3 < V_47 -> V_67 ; V_3 ++ ) {
V_14 = F_106 ( V_47 , V_3 , V_131 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 ,
L_55 ,
V_14 ) ;
goto V_198;
}
}
}
for ( V_3 = 0 ; V_3 < V_47 -> V_194 ; V_3 ++ ) {
V_14 = F_115 ( V_47 , V_3 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 ,
L_56 ,
V_14 ) ;
goto V_199;
}
}
F_124 ( V_47 ) ;
if ( V_47 -> V_151 )
F_125 ( V_47 , V_47 -> V_151 , V_47 -> V_152 ) ;
if ( V_47 -> V_153 )
F_88 ( & V_47 -> V_54 , V_47 -> V_153 ,
V_47 -> V_154 ) ;
for ( V_3 = 0 ; V_3 < V_47 -> V_67 ; V_3 ++ ) {
V_65 = & V_47 -> V_65 [ V_3 ] ;
V_190 = V_65 -> V_190 ;
if ( V_190 ) {
V_14 = F_126 ( V_47 -> V_31 [ V_3 ] . V_86 ,
V_190 ) ;
if ( V_14 != 0 && V_14 != - V_200 )
F_25 ( V_47 -> V_31 [ V_3 ] . V_86 -> V_27 ,
L_57 ,
V_14 ) ;
}
if ( V_190 &&
( V_65 -> V_118 || V_65 -> V_127 ) ) {
V_14 = F_126 ( V_47 -> V_31 [ V_3 ] . V_94 ,
V_190 ) ;
if ( V_14 != 0 && V_14 != - V_200 )
F_25 ( V_47 -> V_31 [ V_3 ] . V_94 -> V_27 ,
L_57 ,
V_14 ) ;
} else if ( V_190 ) {
V_190 &= ~ V_201 ;
switch ( V_65 -> V_190 &
V_201 ) {
case V_202 :
V_190 |= V_203 ;
break;
case V_204 :
V_190 |= V_205 ;
break;
case V_205 :
V_190 |= V_204 ;
break;
case V_203 :
V_190 |= V_202 ;
break;
}
V_14 = F_126 ( V_47 -> V_31 [ V_3 ] . V_94 ,
V_190 ) ;
if ( V_14 != 0 && V_14 != - V_200 )
F_25 ( V_47 -> V_31 [ V_3 ] . V_94 -> V_27 ,
L_57 ,
V_14 ) ;
}
}
snprintf ( V_47 -> V_78 -> V_206 , sizeof( V_47 -> V_78 -> V_206 ) ,
L_58 , V_47 -> V_49 ) ;
snprintf ( V_47 -> V_78 -> V_207 , sizeof( V_47 -> V_78 -> V_207 ) ,
L_58 , V_47 -> V_208 ? V_47 -> V_208 : V_47 -> V_49 ) ;
snprintf ( V_47 -> V_78 -> V_10 , sizeof( V_47 -> V_78 -> V_10 ) ,
L_58 , V_47 -> V_209 ? V_47 -> V_209 : V_47 -> V_49 ) ;
for ( V_3 = 0 ; V_3 < F_127 ( V_47 -> V_78 -> V_10 ) ; V_3 ++ ) {
switch ( V_47 -> V_78 -> V_10 [ V_3 ] ) {
case '_' :
case '-' :
case '\0' :
break;
default:
if ( ! isalnum ( V_47 -> V_78 -> V_10 [ V_3 ] ) )
V_47 -> V_78 -> V_10 [ V_3 ] = '_' ;
break;
}
}
if ( V_47 -> V_210 ) {
V_14 = V_47 -> V_210 ( V_47 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 , L_59 ,
V_47 -> V_49 , V_14 ) ;
goto V_199;
}
}
if ( V_47 -> V_211 )
F_34 (codec, &card->codec_dev_list, card_list)
F_128 ( V_5 ) ;
F_129 ( V_47 ) ;
V_14 = F_130 ( V_47 -> V_78 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 , L_60 ,
V_14 ) ;
goto V_199;
}
#ifdef F_131
for ( V_3 = 0 ; V_3 < V_47 -> V_85 ; V_3 ++ ) {
V_14 = F_112 ( & V_47 -> V_31 [ V_3 ] ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 ,
L_61 , V_14 ) ;
while ( -- V_3 >= 0 )
F_113 ( V_47 -> V_31 [ V_3 ] . V_5 ) ;
goto V_199;
}
}
#endif
V_47 -> V_212 = 1 ;
F_62 ( & V_47 -> V_54 ) ;
F_132 ( & V_47 -> V_191 ) ;
return 0 ;
V_199:
for ( V_3 = 0 ; V_3 < V_47 -> V_194 ; V_3 ++ )
F_116 ( V_47 , V_3 ) ;
V_198:
F_78 ( V_47 ) ;
V_197:
if ( V_47 -> remove )
V_47 -> remove ( V_47 ) ;
F_133 ( V_47 -> V_78 ) ;
V_193:
F_132 ( & V_47 -> V_191 ) ;
return V_14 ;
}
static int F_134 ( struct V_213 * V_214 )
{
struct V_60 * V_47 = F_135 ( V_214 ) ;
if ( ! V_47 )
return - V_17 ;
F_25 ( & V_214 -> V_27 ,
L_62 ,
V_47 -> V_49 ) ;
V_47 -> V_27 = & V_214 -> V_27 ;
return F_136 ( V_47 ) ;
}
static int F_137 ( struct V_60 * V_47 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_47 -> V_85 ; V_3 ++ ) {
struct V_30 * V_31 = & V_47 -> V_31 [ V_3 ] ;
F_59 ( & V_31 -> V_98 ) ;
}
for ( V_3 = 0 ; V_3 < V_47 -> V_194 ; V_3 ++ )
F_116 ( V_47 , V_3 ) ;
F_78 ( V_47 ) ;
F_40 ( V_47 ) ;
if ( V_47 -> remove )
V_47 -> remove ( V_47 ) ;
F_71 ( & V_47 -> V_54 ) ;
F_133 ( V_47 -> V_78 ) ;
return 0 ;
}
static int F_138 ( struct V_213 * V_214 )
{
struct V_60 * V_47 = F_135 ( V_214 ) ;
F_139 ( V_47 ) ;
return 0 ;
}
int F_140 ( struct V_26 * V_27 )
{
struct V_60 * V_47 = F_9 ( V_27 ) ;
int V_3 ;
if ( ! V_47 -> V_212 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_47 -> V_85 ; V_3 ++ ) {
struct V_30 * V_31 = & V_47 -> V_31 [ V_3 ] ;
F_59 ( & V_31 -> V_98 ) ;
}
F_141 ( V_47 ) ;
return 0 ;
}
int F_142 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_215 )
return V_5 -> V_215 ( V_5 , V_6 ) ;
else
return 0 ;
}
int F_6 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_216 )
return V_5 -> V_216 ( V_5 , V_6 ) ;
else
return 1 ;
}
int F_143 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_217 )
return V_5 -> V_217 ( V_5 , V_6 ) ;
else
return 1 ;
}
int F_144 ( struct V_55 * V_56 ,
unsigned int V_6 )
{
unsigned int V_14 ;
if ( ! V_56 -> V_10 -> V_218 ) {
F_50 ( V_56 -> V_27 , L_63 ) ;
return - 1 ;
}
V_14 = V_56 -> V_10 -> V_218 ( V_56 , V_6 ) ;
F_42 ( V_56 -> V_27 , L_64 , V_6 , V_14 ) ;
F_145 ( V_56 , V_6 , V_14 ) ;
return V_14 ;
}
int F_146 ( struct V_55 * V_56 ,
unsigned int V_6 , unsigned int V_1 )
{
if ( ! V_56 -> V_10 -> V_149 ) {
F_50 ( V_56 -> V_27 , L_65 ) ;
return - 1 ;
}
F_42 ( V_56 -> V_27 , L_66 , V_6 , V_1 ) ;
F_147 ( V_56 , V_6 , V_1 ) ;
return V_56 -> V_10 -> V_149 ( V_56 , V_6 , V_1 ) ;
}
int F_148 ( struct V_4 * V_5 ,
struct V_219 * V_90 , int V_116 )
{
F_149 ( & V_5 -> V_191 ) ;
V_5 -> V_72 = F_94 ( sizeof( struct V_220 ) , V_37 ) ;
if ( V_5 -> V_72 == NULL ) {
F_132 ( & V_5 -> V_191 ) ;
return - V_38 ;
}
V_5 -> V_72 -> V_73 = F_94 ( sizeof( struct V_221 ) , V_37 ) ;
if ( V_5 -> V_72 -> V_73 == NULL ) {
F_16 ( V_5 -> V_72 ) ;
V_5 -> V_72 = NULL ;
F_132 ( & V_5 -> V_191 ) ;
return - V_38 ;
}
V_5 -> V_72 -> V_73 -> V_90 = V_90 ;
V_5 -> V_72 -> V_116 = V_116 ;
V_5 -> V_184 = 1 ;
F_132 ( & V_5 -> V_191 ) ;
return 0 ;
}
static void F_150 ( struct V_220 * V_72 )
{
struct V_222 * V_223 = V_224 . V_223 ;
F_151 ( V_223 , V_224 . V_225 ) ;
F_152 ( V_224 . V_226 , 1 ) ;
F_153 ( 10 ) ;
F_152 ( V_224 . V_226 , 0 ) ;
F_151 ( V_223 , V_224 . V_227 ) ;
F_154 ( 2 ) ;
}
static void F_155 ( struct V_220 * V_72 )
{
struct V_222 * V_223 = V_224 . V_223 ;
F_151 ( V_223 , V_224 . V_228 ) ;
F_152 ( V_224 . V_226 , 0 ) ;
F_152 ( V_224 . V_229 , 0 ) ;
F_152 ( V_224 . V_230 , 0 ) ;
F_153 ( 10 ) ;
F_152 ( V_224 . V_230 , 1 ) ;
F_151 ( V_223 , V_224 . V_227 ) ;
F_154 ( 2 ) ;
}
static int F_156 ( struct V_26 * V_27 ,
struct V_231 * V_232 )
{
struct V_222 * V_22 ;
struct V_233 * V_234 ;
int V_235 ;
int V_14 ;
V_22 = F_157 ( V_27 ) ;
if ( F_158 ( V_22 ) ) {
F_50 ( V_27 , L_67 ) ;
return F_159 ( V_22 ) ;
}
V_232 -> V_223 = V_22 ;
V_234 = F_160 ( V_22 , L_68 ) ;
if ( F_158 ( V_234 ) ) {
F_50 ( V_27 , L_69 ) ;
return F_159 ( V_234 ) ;
}
V_232 -> V_228 = V_234 ;
V_234 = F_160 ( V_22 , L_70 ) ;
if ( F_158 ( V_234 ) ) {
F_50 ( V_27 , L_71 ) ;
return F_159 ( V_234 ) ;
}
V_232 -> V_225 = V_234 ;
V_234 = F_160 ( V_22 , L_72 ) ;
if ( F_158 ( V_234 ) ) {
F_50 ( V_27 , L_73 ) ;
return F_159 ( V_234 ) ;
}
V_232 -> V_227 = V_234 ;
V_235 = F_161 ( V_27 -> V_120 , L_74 , 0 ) ;
if ( V_235 < 0 ) {
F_50 ( V_27 , L_75 ) ;
return V_235 ;
}
V_14 = F_162 ( V_27 , V_235 , L_76 ) ;
if ( V_14 ) {
F_50 ( V_27 , L_77 ) ;
return V_14 ;
}
V_232 -> V_226 = V_235 ;
V_235 = F_161 ( V_27 -> V_120 , L_74 , 1 ) ;
if ( V_235 < 0 ) {
F_50 ( V_27 , L_78 , V_235 ) ;
return V_235 ;
}
V_14 = F_162 ( V_27 , V_235 , L_79 ) ;
if ( V_14 ) {
F_50 ( V_27 , L_80 ) ;
return V_14 ;
}
V_232 -> V_229 = V_235 ;
V_235 = F_161 ( V_27 -> V_120 , L_74 , 2 ) ;
if ( V_235 < 0 ) {
F_50 ( V_27 , L_81 ) ;
return V_235 ;
}
V_14 = F_162 ( V_27 , V_235 , L_82 ) ;
if ( V_14 ) {
F_50 ( V_27 , L_83 ) ;
return V_14 ;
}
V_232 -> V_230 = V_235 ;
return 0 ;
}
int F_163 ( struct V_219 * V_90 )
{
if ( V_90 == V_236 )
return 0 ;
if ( V_236 && V_90 )
return - V_185 ;
V_236 = V_90 ;
return 0 ;
}
int F_164 ( struct V_219 * V_90 ,
struct V_213 * V_214 )
{
struct V_26 * V_27 = & V_214 -> V_27 ;
struct V_231 V_232 ;
int V_14 ;
V_14 = F_156 ( V_27 , & V_232 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_163 ( V_90 ) ;
if ( V_14 )
return V_14 ;
V_90 -> V_237 = F_150 ;
V_90 -> V_238 = F_155 ;
V_224 = V_232 ;
return 0 ;
}
void F_165 ( struct V_4 * V_5 )
{
F_149 ( & V_5 -> V_191 ) ;
#ifdef F_131
F_113 ( V_5 ) ;
#endif
F_16 ( V_5 -> V_72 -> V_73 ) ;
F_16 ( V_5 -> V_72 ) ;
V_5 -> V_72 = NULL ;
V_5 -> V_184 = 0 ;
F_132 ( & V_5 -> V_191 ) ;
}
unsigned int F_4 ( struct V_4 * V_5 , unsigned int V_6 )
{
unsigned int V_14 ;
V_14 = V_5 -> V_218 ( V_5 , V_6 ) ;
F_42 ( V_5 -> V_27 , L_64 , V_6 , V_14 ) ;
F_166 ( V_5 , V_6 , V_14 ) ;
return V_14 ;
}
unsigned int F_22 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned int V_1 )
{
F_42 ( V_5 -> V_27 , L_66 , V_6 , V_1 ) ;
F_167 ( V_5 , V_6 , V_1 ) ;
return V_5 -> V_149 ( V_5 , V_6 , V_1 ) ;
}
unsigned int F_168 ( struct V_4 * V_5 ,
unsigned int V_6 , const void * V_239 , T_1 V_8 )
{
return V_5 -> V_240 ( V_5 , V_6 , V_239 , V_8 ) ;
}
int F_169 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_241 , unsigned int V_42 )
{
bool V_242 ;
unsigned int V_243 , V_244 ;
int V_14 ;
if ( V_5 -> V_107 ) {
V_14 = F_170 ( V_5 -> V_108 , V_6 ,
V_241 , V_42 , & V_242 ) ;
} else {
V_14 = F_4 ( V_5 , V_6 ) ;
if ( V_14 < 0 )
return V_14 ;
V_243 = V_14 ;
V_244 = ( V_243 & ~ V_241 ) | ( V_42 & V_241 ) ;
V_242 = V_243 != V_244 ;
if ( V_242 )
V_14 = F_22 ( V_5 , V_6 , V_244 ) ;
}
if ( V_14 < 0 )
return V_14 ;
return V_242 ;
}
int F_171 ( struct V_4 * V_5 ,
unsigned short V_6 , unsigned int V_241 ,
unsigned int V_42 )
{
int V_242 ;
F_149 ( & V_5 -> V_191 ) ;
V_242 = F_169 ( V_5 , V_6 , V_241 , V_42 ) ;
F_132 ( & V_5 -> V_191 ) ;
return V_242 ;
}
int F_172 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_241 , unsigned int V_42 )
{
int V_242 ;
unsigned int V_243 , V_244 ;
V_243 = F_4 ( V_5 , V_6 ) ;
V_244 = ( V_243 & ~ V_241 ) | V_42 ;
V_242 = V_243 != V_244 ;
return V_242 ;
}
struct V_245 * F_173 ( const struct V_246 * V_247 ,
void * V_239 , const char * V_208 ,
const char * V_248 )
{
struct V_246 V_249 ;
struct V_245 * V_250 ;
char * V_49 = NULL ;
memcpy ( & V_249 , V_247 , sizeof( V_249 ) ) ;
V_249 . V_251 = 0 ;
if ( ! V_208 )
V_208 = V_249 . V_49 ;
if ( V_248 ) {
V_49 = F_174 ( V_37 , L_84 , V_248 , V_208 ) ;
if ( ! V_49 )
return NULL ;
V_249 . V_49 = V_49 ;
} else {
V_249 . V_49 = V_208 ;
}
V_250 = F_175 ( & V_249 , V_239 ) ;
F_16 ( V_49 ) ;
return V_250 ;
}
static int F_176 ( struct V_78 * V_47 , struct V_26 * V_27 ,
const struct V_246 * V_151 , int V_152 ,
const char * V_248 , void * V_239 )
{
int V_74 , V_3 ;
for ( V_3 = 0 ; V_3 < V_152 ; V_3 ++ ) {
const struct V_246 * V_252 = & V_151 [ V_3 ] ;
V_74 = F_177 ( V_47 , F_173 ( V_252 , V_239 ,
V_252 -> V_49 , V_248 ) ) ;
if ( V_74 < 0 ) {
F_50 ( V_27 , L_85 ,
V_252 -> V_49 , V_74 ) ;
return V_74 ;
}
}
return 0 ;
}
struct V_245 * F_178 ( struct V_60 * V_253 ,
const char * V_49 )
{
struct V_78 * V_47 = V_253 -> V_78 ;
struct V_245 * V_254 ;
if ( F_179 ( ! V_49 ) )
return NULL ;
F_34 (kctl, &card->controls, list)
if ( ! strncmp ( V_254 -> V_255 . V_49 , V_49 , sizeof( V_254 -> V_255 . V_49 ) ) )
return V_254 ;
return NULL ;
}
int F_87 ( struct V_4 * V_5 ,
const struct V_246 * V_151 , int V_152 )
{
struct V_78 * V_47 = V_5 -> V_47 -> V_78 ;
return F_176 ( V_47 , V_5 -> V_27 , V_151 , V_152 ,
V_5 -> V_142 , V_5 ) ;
}
int F_91 ( struct V_55 * V_56 ,
const struct V_246 * V_151 , int V_152 )
{
struct V_78 * V_47 = V_56 -> V_47 -> V_78 ;
return F_176 ( V_47 , V_56 -> V_27 , V_151 , V_152 ,
NULL , V_56 ) ;
}
int F_125 ( struct V_60 * V_253 ,
const struct V_246 * V_151 , int V_152 )
{
struct V_78 * V_47 = V_253 -> V_78 ;
return F_176 ( V_47 , V_253 -> V_27 , V_151 , V_152 ,
NULL , V_253 ) ;
}
int F_180 ( struct V_58 * V_59 ,
const struct V_246 * V_151 , int V_152 )
{
struct V_78 * V_47 = V_59 -> V_47 -> V_78 ;
return F_176 ( V_47 , V_59 -> V_27 , V_151 , V_152 ,
NULL , V_59 ) ;
}
int F_181 ( struct V_245 * V_250 ,
struct V_256 * V_257 )
{
struct V_258 * V_259 = (struct V_258 * ) V_250 -> V_260 ;
V_257 -> type = V_261 ;
V_257 -> V_18 = V_259 -> V_262 == V_259 -> V_263 ? 1 : 2 ;
V_257 -> V_42 . V_264 . V_265 = V_259 -> V_266 ;
if ( V_257 -> V_42 . V_264 . V_267 > V_259 -> V_266 - 1 )
V_257 -> V_42 . V_264 . V_267 = V_259 -> V_266 - 1 ;
strcpy ( V_257 -> V_42 . V_264 . V_49 ,
V_259 -> V_268 [ V_257 -> V_42 . V_264 . V_267 ] ) ;
return 0 ;
}
int F_182 ( struct V_245 * V_250 ,
struct V_269 * V_270 )
{
struct V_4 * V_5 = F_183 ( V_250 ) ;
struct V_258 * V_259 = (struct V_258 * ) V_250 -> V_260 ;
unsigned int V_1 ;
V_1 = F_4 ( V_5 , V_259 -> V_6 ) ;
V_270 -> V_42 . V_264 . V_267 [ 0 ]
= ( V_1 >> V_259 -> V_262 ) & V_259 -> V_241 ;
if ( V_259 -> V_262 != V_259 -> V_263 )
V_270 -> V_42 . V_264 . V_267 [ 1 ] =
( V_1 >> V_259 -> V_263 ) & V_259 -> V_241 ;
return 0 ;
}
int F_184 ( struct V_245 * V_250 ,
struct V_269 * V_270 )
{
struct V_4 * V_5 = F_183 ( V_250 ) ;
struct V_258 * V_259 = (struct V_258 * ) V_250 -> V_260 ;
unsigned int V_1 ;
unsigned int V_241 ;
if ( V_270 -> V_42 . V_264 . V_267 [ 0 ] > V_259 -> V_266 - 1 )
return - V_17 ;
V_1 = V_270 -> V_42 . V_264 . V_267 [ 0 ] << V_259 -> V_262 ;
V_241 = V_259 -> V_241 << V_259 -> V_262 ;
if ( V_259 -> V_262 != V_259 -> V_263 ) {
if ( V_270 -> V_42 . V_264 . V_267 [ 1 ] > V_259 -> V_266 - 1 )
return - V_17 ;
V_1 |= V_270 -> V_42 . V_264 . V_267 [ 1 ] << V_259 -> V_263 ;
V_241 |= V_259 -> V_241 << V_259 -> V_263 ;
}
return F_171 ( V_5 , V_259 -> V_6 , V_241 , V_1 ) ;
}
int F_185 ( struct V_245 * V_250 ,
struct V_269 * V_270 )
{
struct V_4 * V_5 = F_183 ( V_250 ) ;
struct V_258 * V_259 = (struct V_258 * ) V_250 -> V_260 ;
unsigned int V_271 , V_1 , V_272 ;
V_271 = F_4 ( V_5 , V_259 -> V_6 ) ;
V_1 = ( V_271 >> V_259 -> V_262 ) & V_259 -> V_241 ;
for ( V_272 = 0 ; V_272 < V_259 -> V_266 ; V_272 ++ ) {
if ( V_1 == V_259 -> V_273 [ V_272 ] )
break;
}
V_270 -> V_42 . V_264 . V_267 [ 0 ] = V_272 ;
if ( V_259 -> V_262 != V_259 -> V_263 ) {
V_1 = ( V_271 >> V_259 -> V_263 ) & V_259 -> V_241 ;
for ( V_272 = 0 ; V_272 < V_259 -> V_266 ; V_272 ++ ) {
if ( V_1 == V_259 -> V_273 [ V_272 ] )
break;
}
V_270 -> V_42 . V_264 . V_267 [ 1 ] = V_272 ;
}
return 0 ;
}
int F_186 ( struct V_245 * V_250 ,
struct V_269 * V_270 )
{
struct V_4 * V_5 = F_183 ( V_250 ) ;
struct V_258 * V_259 = (struct V_258 * ) V_250 -> V_260 ;
unsigned int V_1 ;
unsigned int V_241 ;
if ( V_270 -> V_42 . V_264 . V_267 [ 0 ] > V_259 -> V_266 - 1 )
return - V_17 ;
V_1 = V_259 -> V_273 [ V_270 -> V_42 . V_264 . V_267 [ 0 ] ] << V_259 -> V_262 ;
V_241 = V_259 -> V_241 << V_259 -> V_262 ;
if ( V_259 -> V_262 != V_259 -> V_263 ) {
if ( V_270 -> V_42 . V_264 . V_267 [ 1 ] > V_259 -> V_266 - 1 )
return - V_17 ;
V_1 |= V_259 -> V_273 [ V_270 -> V_42 . V_264 . V_267 [ 1 ] ] << V_259 -> V_263 ;
V_241 |= V_259 -> V_241 << V_259 -> V_263 ;
}
return F_171 ( V_5 , V_259 -> V_6 , V_241 , V_1 ) ;
}
int F_187 ( struct V_245 * V_250 ,
struct V_256 * V_257 )
{
struct V_274 * V_275 =
(struct V_274 * ) V_250 -> V_260 ;
int V_276 ;
if ( ! V_275 -> V_276 )
V_275 -> V_276 = V_275 -> V_266 ;
V_276 = V_275 -> V_276 ;
if ( V_276 == 1 && ! strstr ( V_250 -> V_255 . V_49 , L_86 ) )
V_257 -> type = V_277 ;
else
V_257 -> type = V_278 ;
V_257 -> V_18 = F_188 ( V_275 ) ? 2 : 1 ;
V_257 -> V_42 . integer . F_7 = 0 ;
V_257 -> V_42 . integer . V_266 = V_276 ;
return 0 ;
}
int F_189 ( struct V_245 * V_250 ,
struct V_269 * V_270 )
{
struct V_274 * V_275 =
(struct V_274 * ) V_250 -> V_260 ;
struct V_4 * V_5 = F_183 ( V_250 ) ;
unsigned int V_6 = V_275 -> V_6 ;
unsigned int V_279 = V_275 -> V_280 ;
unsigned int V_281 = V_275 -> V_281 ;
unsigned int V_282 = V_275 -> V_282 ;
int V_266 = V_275 -> V_266 ;
unsigned int V_241 = ( 1 << F_190 ( V_266 ) ) - 1 ;
unsigned int V_283 = V_275 -> V_283 ;
V_270 -> V_42 . integer . V_42 [ 0 ] =
( F_4 ( V_5 , V_6 ) >> V_281 ) & V_241 ;
if ( V_283 )
V_270 -> V_42 . integer . V_42 [ 0 ] =
V_266 - V_270 -> V_42 . integer . V_42 [ 0 ] ;
if ( F_188 ( V_275 ) ) {
if ( V_6 == V_279 )
V_270 -> V_42 . integer . V_42 [ 1 ] =
( F_4 ( V_5 , V_6 ) >> V_282 ) & V_241 ;
else
V_270 -> V_42 . integer . V_42 [ 1 ] =
( F_4 ( V_5 , V_279 ) >> V_281 ) & V_241 ;
if ( V_283 )
V_270 -> V_42 . integer . V_42 [ 1 ] =
V_266 - V_270 -> V_42 . integer . V_42 [ 1 ] ;
}
return 0 ;
}
int F_191 ( struct V_245 * V_250 ,
struct V_269 * V_270 )
{
struct V_274 * V_275 =
(struct V_274 * ) V_250 -> V_260 ;
struct V_4 * V_5 = F_183 ( V_250 ) ;
unsigned int V_6 = V_275 -> V_6 ;
unsigned int V_279 = V_275 -> V_280 ;
unsigned int V_281 = V_275 -> V_281 ;
unsigned int V_282 = V_275 -> V_282 ;
int V_266 = V_275 -> V_266 ;
unsigned int V_241 = ( 1 << F_190 ( V_266 ) ) - 1 ;
unsigned int V_283 = V_275 -> V_283 ;
int V_74 ;
bool V_284 = 0 ;
unsigned int V_285 = 0 ;
unsigned int V_1 , V_286 ;
V_1 = ( V_270 -> V_42 . integer . V_42 [ 0 ] & V_241 ) ;
if ( V_283 )
V_1 = V_266 - V_1 ;
V_286 = V_241 << V_281 ;
V_1 = V_1 << V_281 ;
if ( F_188 ( V_275 ) ) {
V_285 = ( V_270 -> V_42 . integer . V_42 [ 1 ] & V_241 ) ;
if ( V_283 )
V_285 = V_266 - V_285 ;
if ( V_6 == V_279 ) {
V_286 |= V_241 << V_282 ;
V_1 |= V_285 << V_282 ;
} else {
V_285 = V_285 << V_281 ;
V_284 = 1 ;
}
}
V_74 = F_171 ( V_5 , V_6 , V_286 , V_1 ) ;
if ( V_74 < 0 )
return V_74 ;
if ( V_284 )
V_74 = F_171 ( V_5 , V_279 , V_286 , V_285 ) ;
return V_74 ;
}
int F_192 ( struct V_245 * V_250 ,
struct V_269 * V_270 )
{
struct V_4 * V_5 = F_183 ( V_250 ) ;
struct V_274 * V_275 =
(struct V_274 * ) V_250 -> V_260 ;
unsigned int V_6 = V_275 -> V_6 ;
unsigned int V_279 = V_275 -> V_280 ;
unsigned int V_281 = V_275 -> V_281 ;
unsigned int V_282 = V_275 -> V_282 ;
int V_266 = V_275 -> V_266 ;
int F_7 = V_275 -> F_7 ;
int V_241 = ( 1 << ( F_190 ( F_7 + V_266 ) - 1 ) ) - 1 ;
V_270 -> V_42 . integer . V_42 [ 0 ] =
( ( F_4 ( V_5 , V_6 ) >> V_281 ) - F_7 ) & V_241 ;
if ( F_188 ( V_275 ) )
V_270 -> V_42 . integer . V_42 [ 1 ] =
( ( F_4 ( V_5 , V_279 ) >> V_282 ) - F_7 ) & V_241 ;
return 0 ;
}
int F_193 ( struct V_245 * V_250 ,
struct V_269 * V_270 )
{
struct V_4 * V_5 = F_183 ( V_250 ) ;
struct V_274 * V_275 =
(struct V_274 * ) V_250 -> V_260 ;
unsigned int V_6 = V_275 -> V_6 ;
unsigned int V_279 = V_275 -> V_280 ;
unsigned int V_281 = V_275 -> V_281 ;
unsigned int V_282 = V_275 -> V_282 ;
int V_266 = V_275 -> V_266 ;
int F_7 = V_275 -> F_7 ;
int V_241 = ( 1 << ( F_190 ( F_7 + V_266 ) - 1 ) ) - 1 ;
int V_74 = 0 ;
unsigned short V_1 , V_286 , V_285 = 0 ;
V_286 = V_241 << V_281 ;
V_1 = ( V_270 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & V_241 ;
V_1 = V_1 << V_281 ;
V_74 = F_171 ( V_5 , V_6 , V_286 , V_1 ) ;
if ( V_74 < 0 )
return V_74 ;
if ( F_188 ( V_275 ) ) {
V_286 = V_241 << V_282 ;
V_285 = ( V_270 -> V_42 . integer . V_42 [ 1 ] + F_7 ) & V_241 ;
V_285 = V_285 << V_282 ;
if ( F_171 ( V_5 , V_279 , V_286 , V_285 ) )
return V_74 ;
}
return 0 ;
}
int F_194 ( struct V_245 * V_250 ,
struct V_256 * V_257 )
{
struct V_274 * V_275 =
(struct V_274 * ) V_250 -> V_260 ;
int V_276 ;
int F_7 = V_275 -> F_7 ;
if ( ! V_275 -> V_276 )
V_275 -> V_276 = V_275 -> V_266 ;
V_276 = V_275 -> V_276 ;
V_257 -> type = V_278 ;
V_257 -> V_18 = 2 ;
V_257 -> V_42 . integer . F_7 = 0 ;
V_257 -> V_42 . integer . V_266 = V_276 - F_7 ;
return 0 ;
}
int F_195 ( struct V_245 * V_250 ,
struct V_269 * V_270 )
{
struct V_274 * V_275 =
(struct V_274 * ) V_250 -> V_260 ;
struct V_4 * V_5 = F_183 ( V_250 ) ;
unsigned int V_6 = V_275 -> V_6 ;
int F_7 = V_275 -> F_7 ;
int V_1 = F_4 ( V_5 , V_6 ) ;
V_270 -> V_42 . integer . V_42 [ 0 ] =
( ( signed char ) ( V_1 & 0xff ) ) - F_7 ;
V_270 -> V_42 . integer . V_42 [ 1 ] =
( ( signed char ) ( ( V_1 >> 8 ) & 0xff ) ) - F_7 ;
return 0 ;
}
int F_196 ( struct V_245 * V_250 ,
struct V_269 * V_270 )
{
struct V_274 * V_275 =
(struct V_274 * ) V_250 -> V_260 ;
struct V_4 * V_5 = F_183 ( V_250 ) ;
unsigned int V_6 = V_275 -> V_6 ;
int F_7 = V_275 -> F_7 ;
unsigned int V_1 ;
V_1 = ( V_270 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & 0xff ;
V_1 |= ( ( V_270 -> V_42 . integer . V_42 [ 1 ] + F_7 ) & 0xff ) << 8 ;
return F_171 ( V_5 , V_6 , 0xffff , V_1 ) ;
}
int F_197 ( struct V_245 * V_250 ,
struct V_256 * V_257 )
{
struct V_274 * V_275 =
(struct V_274 * ) V_250 -> V_260 ;
int V_276 ;
int F_7 = V_275 -> F_7 ;
if ( ! V_275 -> V_276 )
V_275 -> V_276 = V_275 -> V_266 ;
V_276 = V_275 -> V_276 ;
V_257 -> type = V_278 ;
V_257 -> V_18 = F_188 ( V_275 ) ? 2 : 1 ;
V_257 -> V_42 . integer . F_7 = 0 ;
V_257 -> V_42 . integer . V_266 = V_276 - F_7 ;
return 0 ;
}
int F_198 ( struct V_245 * V_250 ,
struct V_269 * V_270 )
{
struct V_274 * V_275 =
(struct V_274 * ) V_250 -> V_260 ;
struct V_4 * V_5 = F_183 ( V_250 ) ;
unsigned int V_6 = V_275 -> V_6 ;
unsigned int V_280 = V_275 -> V_280 ;
unsigned int V_281 = V_275 -> V_281 ;
int F_7 = V_275 -> F_7 ;
int V_266 = V_275 -> V_266 ;
unsigned int V_241 = ( 1 << F_190 ( V_266 ) ) - 1 ;
unsigned int V_283 = V_275 -> V_283 ;
unsigned int V_1 , V_286 ;
int V_14 ;
V_1 = ( ( V_270 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & V_241 ) ;
if ( V_283 )
V_1 = V_266 - V_1 ;
V_286 = V_241 << V_281 ;
V_1 = V_1 << V_281 ;
V_14 = F_171 ( V_5 , V_6 , V_286 , V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( F_188 ( V_275 ) ) {
V_1 = ( ( V_270 -> V_42 . integer . V_42 [ 1 ] + F_7 ) & V_241 ) ;
if ( V_283 )
V_1 = V_266 - V_1 ;
V_286 = V_241 << V_281 ;
V_1 = V_1 << V_281 ;
V_14 = F_171 ( V_5 , V_280 , V_286 , V_1 ) ;
}
return V_14 ;
}
int F_199 ( struct V_245 * V_250 ,
struct V_269 * V_270 )
{
struct V_274 * V_275 =
(struct V_274 * ) V_250 -> V_260 ;
struct V_4 * V_5 = F_183 ( V_250 ) ;
unsigned int V_6 = V_275 -> V_6 ;
unsigned int V_280 = V_275 -> V_280 ;
unsigned int V_281 = V_275 -> V_281 ;
int F_7 = V_275 -> F_7 ;
int V_266 = V_275 -> V_266 ;
unsigned int V_241 = ( 1 << F_190 ( V_266 ) ) - 1 ;
unsigned int V_283 = V_275 -> V_283 ;
V_270 -> V_42 . integer . V_42 [ 0 ] =
( F_4 ( V_5 , V_6 ) >> V_281 ) & V_241 ;
if ( V_283 )
V_270 -> V_42 . integer . V_42 [ 0 ] =
V_266 - V_270 -> V_42 . integer . V_42 [ 0 ] ;
V_270 -> V_42 . integer . V_42 [ 0 ] =
V_270 -> V_42 . integer . V_42 [ 0 ] - F_7 ;
if ( F_188 ( V_275 ) ) {
V_270 -> V_42 . integer . V_42 [ 1 ] =
( F_4 ( V_5 , V_280 ) >> V_281 ) & V_241 ;
if ( V_283 )
V_270 -> V_42 . integer . V_42 [ 1 ] =
V_266 - V_270 -> V_42 . integer . V_42 [ 1 ] ;
V_270 -> V_42 . integer . V_42 [ 1 ] =
V_270 -> V_42 . integer . V_42 [ 1 ] - F_7 ;
}
return 0 ;
}
int F_200 ( struct V_4 * V_5 ,
const char * V_49 , int V_266 )
{
struct V_78 * V_47 = V_5 -> V_47 -> V_78 ;
struct V_245 * V_254 ;
struct V_274 * V_275 ;
int V_186 = 0 ;
int V_14 = - V_17 ;
if ( F_179 ( ! V_49 || V_266 <= 0 ) )
return - V_17 ;
F_34 (kctl, &card->controls, list) {
if ( ! strncmp ( V_254 -> V_255 . V_49 , V_49 , sizeof( V_254 -> V_255 . V_49 ) ) ) {
V_186 = 1 ;
break;
}
}
if ( V_186 ) {
V_275 = (struct V_274 * ) V_254 -> V_260 ;
if ( V_266 <= V_275 -> V_266 ) {
V_275 -> V_276 = V_266 ;
V_14 = 0 ;
}
}
return V_14 ;
}
int F_201 ( struct V_245 * V_250 ,
struct V_256 * V_257 )
{
struct V_4 * V_5 = F_183 ( V_250 ) ;
struct V_287 * V_179 = ( void * ) V_250 -> V_260 ;
V_257 -> type = V_288 ;
V_257 -> V_18 = V_179 -> V_289 * V_5 -> V_290 ;
return 0 ;
}
int F_202 ( struct V_245 * V_250 ,
struct V_269 * V_270 )
{
struct V_287 * V_179 = ( void * ) V_250 -> V_260 ;
struct V_4 * V_5 = F_183 ( V_250 ) ;
int V_14 ;
if ( V_5 -> V_107 )
V_14 = F_203 ( V_5 -> V_108 , V_179 -> V_291 ,
V_270 -> V_42 . V_292 . V_239 ,
V_179 -> V_289 * V_5 -> V_290 ) ;
else
V_14 = - V_17 ;
if ( V_14 == 0 && V_179 -> V_241 ) {
switch ( V_5 -> V_290 ) {
case 1 :
V_270 -> V_42 . V_292 . V_239 [ 0 ] &= ~ V_179 -> V_241 ;
break;
case 2 :
( ( V_293 * ) ( & V_270 -> V_42 . V_292 . V_239 ) ) [ 0 ]
&= ~ V_179 -> V_241 ;
break;
case 4 :
( ( V_294 * ) ( & V_270 -> V_42 . V_292 . V_239 ) ) [ 0 ]
&= ~ V_179 -> V_241 ;
break;
default:
return - V_17 ;
}
}
return V_14 ;
}
int F_204 ( struct V_245 * V_250 ,
struct V_269 * V_270 )
{
struct V_287 * V_179 = ( void * ) V_250 -> V_260 ;
struct V_4 * V_5 = F_183 ( V_250 ) ;
int V_14 , V_8 ;
unsigned int V_1 ;
void * V_239 ;
if ( ! V_5 -> V_107 )
return - V_17 ;
V_8 = V_179 -> V_289 * V_5 -> V_290 ;
V_239 = F_205 ( V_270 -> V_42 . V_292 . V_239 , V_8 , V_37 | V_295 ) ;
if ( ! V_239 )
return - V_38 ;
if ( V_179 -> V_241 ) {
V_14 = F_206 ( V_5 -> V_108 , V_179 -> V_291 , & V_1 ) ;
if ( V_14 != 0 )
goto V_171;
V_1 &= V_179 -> V_241 ;
switch ( V_5 -> V_290 ) {
case 1 :
( ( V_296 * ) V_239 ) [ 0 ] &= ~ V_179 -> V_241 ;
( ( V_296 * ) V_239 ) [ 0 ] |= V_1 ;
break;
case 2 :
( ( V_293 * ) V_239 ) [ 0 ] &= F_207 ( ~ V_179 -> V_241 ) ;
( ( V_293 * ) V_239 ) [ 0 ] |= F_207 ( V_1 ) ;
break;
case 4 :
( ( V_294 * ) V_239 ) [ 0 ] &= F_208 ( ~ V_179 -> V_241 ) ;
( ( V_294 * ) V_239 ) [ 0 ] |= F_208 ( V_1 ) ;
break;
default:
V_14 = - V_17 ;
goto V_171;
}
}
V_14 = F_209 ( V_5 -> V_108 , V_179 -> V_291 ,
V_239 , V_8 ) ;
V_171:
F_16 ( V_239 ) ;
return V_14 ;
}
int F_210 ( struct V_245 * V_250 ,
struct V_256 * V_257 )
{
struct V_297 * V_275 =
(struct V_297 * ) V_250 -> V_260 ;
V_257 -> type = V_278 ;
V_257 -> V_18 = 1 ;
V_257 -> V_42 . integer . F_7 = V_275 -> F_7 ;
V_257 -> V_42 . integer . V_266 = V_275 -> V_266 ;
return 0 ;
}
int F_211 ( struct V_245 * V_250 ,
struct V_269 * V_270 )
{
struct V_297 * V_275 =
(struct V_297 * ) V_250 -> V_260 ;
struct V_4 * V_5 = F_183 ( V_250 ) ;
unsigned int V_298 = V_275 -> V_298 ;
unsigned int V_299 = V_275 -> V_299 ;
unsigned int V_300 = V_5 -> V_10 -> V_13 * V_301 ;
unsigned int V_302 = ( 1 << V_300 ) - 1 ;
unsigned int V_283 = V_275 -> V_283 ;
unsigned long V_241 = ( 1UL << V_275 -> V_303 ) - 1 ;
long F_7 = V_275 -> F_7 ;
long V_266 = V_275 -> V_266 ;
long V_1 = 0 ;
unsigned long V_304 ;
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_299 ; V_3 ++ ) {
V_304 = F_4 ( V_5 , V_298 + V_3 ) & V_302 ;
V_1 |= V_304 << ( V_300 * ( V_299 - V_3 - 1 ) ) ;
}
V_1 &= V_241 ;
if ( F_7 < 0 && V_1 > V_266 )
V_1 |= ~ V_241 ;
if ( V_283 )
V_1 = V_266 - V_1 ;
V_270 -> V_42 . integer . V_42 [ 0 ] = V_1 ;
return 0 ;
}
int F_212 ( struct V_245 * V_250 ,
struct V_269 * V_270 )
{
struct V_297 * V_275 =
(struct V_297 * ) V_250 -> V_260 ;
struct V_4 * V_5 = F_183 ( V_250 ) ;
unsigned int V_298 = V_275 -> V_298 ;
unsigned int V_299 = V_275 -> V_299 ;
unsigned int V_300 = V_5 -> V_10 -> V_13 * V_301 ;
unsigned int V_302 = ( 1 << V_300 ) - 1 ;
unsigned int V_283 = V_275 -> V_283 ;
unsigned long V_241 = ( 1UL << V_275 -> V_303 ) - 1 ;
long V_266 = V_275 -> V_266 ;
long V_1 = V_270 -> V_42 . integer . V_42 [ 0 ] ;
unsigned int V_3 , V_304 , V_305 ;
int V_74 ;
if ( V_283 )
V_1 = V_266 - V_1 ;
V_1 &= V_241 ;
for ( V_3 = 0 ; V_3 < V_299 ; V_3 ++ ) {
V_304 = ( V_1 >> ( V_300 * ( V_299 - V_3 - 1 ) ) ) & V_302 ;
V_305 = ( V_241 >> ( V_300 * ( V_299 - V_3 - 1 ) ) ) & V_302 ;
V_74 = F_171 ( V_5 , V_298 + V_3 ,
V_305 , V_304 ) ;
if ( V_74 < 0 )
return V_74 ;
}
return 0 ;
}
int F_213 ( struct V_245 * V_250 ,
struct V_269 * V_270 )
{
struct V_274 * V_275 =
(struct V_274 * ) V_250 -> V_260 ;
struct V_4 * V_5 = F_183 ( V_250 ) ;
unsigned int V_6 = V_275 -> V_6 ;
unsigned int V_281 = V_275 -> V_281 ;
unsigned int V_241 = 1 << V_281 ;
unsigned int V_283 = V_275 -> V_283 != 0 ;
unsigned int V_1 = F_4 ( V_5 , V_6 ) & V_241 ;
if ( V_281 != 0 && V_1 != 0 )
V_1 = V_1 >> V_281 ;
V_270 -> V_42 . V_264 . V_267 [ 0 ] = V_1 ^ V_283 ;
return 0 ;
}
int F_214 ( struct V_245 * V_250 ,
struct V_269 * V_270 )
{
struct V_274 * V_275 =
(struct V_274 * ) V_250 -> V_260 ;
struct V_4 * V_5 = F_183 ( V_250 ) ;
unsigned int V_6 = V_275 -> V_6 ;
unsigned int V_281 = V_275 -> V_281 ;
unsigned int V_241 = 1 << V_281 ;
unsigned int V_283 = V_275 -> V_283 != 0 ;
unsigned int V_306 = V_270 -> V_42 . V_264 . V_267 [ 0 ] != 0 ;
unsigned int V_307 = ( V_306 ^ V_283 ) ? V_241 : 0 ;
unsigned int V_285 = ( V_306 ^ V_283 ) ? 0 : V_241 ;
int V_74 ;
V_74 = F_171 ( V_5 , V_6 , V_241 , V_307 ) ;
if ( V_74 < 0 )
return V_74 ;
V_74 = F_171 ( V_5 , V_6 , V_241 , V_285 ) ;
return V_74 ;
}
int F_215 ( struct V_58 * V_59 , int V_308 ,
unsigned int V_309 , int V_310 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_90 -> V_311 )
return V_59 -> V_10 -> V_90 -> V_311 ( V_59 , V_308 , V_309 , V_310 ) ;
else if ( V_59 -> V_5 && V_59 -> V_5 -> V_10 -> V_311 )
return V_59 -> V_5 -> V_10 -> V_311 ( V_59 -> V_5 , V_308 , 0 ,
V_309 , V_310 ) ;
else
return - V_17 ;
}
int F_216 ( struct V_4 * V_5 , int V_308 ,
int V_312 , unsigned int V_309 , int V_310 )
{
if ( V_5 -> V_10 -> V_311 )
return V_5 -> V_10 -> V_311 ( V_5 , V_308 , V_312 ,
V_309 , V_310 ) ;
else
return - V_17 ;
}
int F_217 ( struct V_58 * V_59 ,
int V_313 , int div )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_90 -> V_314 )
return V_59 -> V_10 -> V_90 -> V_314 ( V_59 , V_313 , div ) ;
else
return - V_17 ;
}
int F_218 ( struct V_58 * V_59 , int V_315 , int V_312 ,
unsigned int V_316 , unsigned int V_317 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_90 -> V_318 )
return V_59 -> V_10 -> V_90 -> V_318 ( V_59 , V_315 , V_312 ,
V_316 , V_317 ) ;
else if ( V_59 -> V_5 && V_59 -> V_5 -> V_10 -> V_318 )
return V_59 -> V_5 -> V_10 -> V_318 ( V_59 -> V_5 , V_315 , V_312 ,
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
int F_126 ( struct V_58 * V_59 , unsigned int V_319 )
{
if ( V_59 -> V_10 == NULL )
return - V_17 ;
if ( V_59 -> V_10 -> V_90 -> V_320 == NULL )
return - V_200 ;
return V_59 -> V_10 -> V_90 -> V_320 ( V_59 , V_319 ) ;
}
int F_220 ( struct V_58 * V_59 ,
unsigned int V_321 , unsigned int V_322 , int V_323 , int V_324 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_90 -> V_325 )
return V_59 -> V_10 -> V_90 -> V_325 ( V_59 , V_321 , V_322 ,
V_323 , V_324 ) ;
else
return - V_17 ;
}
int F_221 ( struct V_58 * V_59 ,
unsigned int V_326 , unsigned int * V_327 ,
unsigned int V_328 , unsigned int * V_329 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_90 -> V_330 )
return V_59 -> V_10 -> V_90 -> V_330 ( V_59 , V_326 , V_327 ,
V_328 , V_329 ) ;
else
return - V_17 ;
}
int F_222 ( struct V_58 * V_59 , int V_331 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_90 -> V_332 )
return V_59 -> V_10 -> V_90 -> V_332 ( V_59 , V_331 ) ;
else
return - V_17 ;
}
int F_223 ( struct V_58 * V_59 , int V_333 ,
int V_334 )
{
if ( ! V_59 -> V_10 )
return - V_200 ;
if ( V_59 -> V_10 -> V_90 -> V_335 )
return V_59 -> V_10 -> V_90 -> V_335 ( V_59 , V_333 , V_334 ) ;
else if ( V_334 == V_101 &&
V_59 -> V_10 -> V_90 -> V_91 )
return V_59 -> V_10 -> V_90 -> V_91 ( V_59 , V_333 ) ;
else
return - V_200 ;
}
int F_136 ( struct V_60 * V_47 )
{
int V_3 , V_14 ;
if ( ! V_47 -> V_49 || ! V_47 -> V_27 )
return - V_17 ;
for ( V_3 = 0 ; V_3 < V_47 -> V_67 ; V_3 ++ ) {
struct V_117 * V_336 = & V_47 -> V_65 [ V_3 ] ;
if ( ! ! V_336 -> V_125 == ! ! V_336 -> V_124 ) {
F_50 ( V_47 -> V_27 ,
L_87 ,
V_336 -> V_49 ) ;
return - V_17 ;
}
if ( ! V_336 -> V_126 ) {
F_50 ( V_47 -> V_27 ,
L_88 ,
V_336 -> V_49 ) ;
return - V_17 ;
}
if ( V_336 -> V_118 && V_336 -> V_127 ) {
F_50 ( V_47 -> V_27 ,
L_89 ,
V_336 -> V_49 ) ;
return - V_17 ;
}
if ( V_336 -> V_121 && V_336 -> V_119 ) {
F_50 ( V_47 -> V_27 ,
L_90 ,
V_336 -> V_49 ) ;
return - V_17 ;
}
if ( ! V_336 -> V_122 &&
! ( V_336 -> V_121 || V_336 -> V_119 ) ) {
F_50 ( V_47 -> V_27 ,
L_91 ,
V_336 -> V_49 ) ;
return - V_17 ;
}
}
F_96 ( V_47 -> V_27 , V_47 ) ;
F_224 ( V_47 ) ;
F_38 ( V_47 ) ;
V_47 -> V_31 = F_225 ( V_47 -> V_27 ,
sizeof( struct V_30 ) *
( V_47 -> V_67 + V_47 -> V_194 ) ,
V_37 ) ;
if ( V_47 -> V_31 == NULL )
return - V_38 ;
V_47 -> V_85 = 0 ;
V_47 -> V_163 = & V_47 -> V_31 [ V_47 -> V_67 ] ;
for ( V_3 = 0 ; V_3 < V_47 -> V_67 ; V_3 ++ )
V_47 -> V_31 [ V_3 ] . V_65 = & V_47 -> V_65 [ V_3 ] ;
F_98 ( & V_47 -> V_155 ) ;
F_98 ( & V_47 -> V_337 ) ;
V_47 -> V_212 = 0 ;
F_97 ( & V_47 -> V_191 ) ;
F_97 ( & V_47 -> V_338 ) ;
V_14 = F_119 ( V_47 ) ;
if ( V_14 != 0 )
F_40 ( V_47 ) ;
return V_14 ;
}
int F_139 ( struct V_60 * V_47 )
{
if ( V_47 -> V_212 )
F_137 ( V_47 ) ;
F_42 ( V_47 -> V_27 , L_92 , V_47 -> V_49 ) ;
return 0 ;
}
static char * F_226 ( struct V_26 * V_27 , int * V_255 )
{
char * V_186 , V_49 [ V_339 ] ;
int V_340 , V_341 ;
if ( F_69 ( V_27 ) == NULL )
return NULL ;
F_227 ( V_49 , F_69 ( V_27 ) , V_339 ) ;
V_186 = strstr ( V_49 , V_27 -> V_10 -> V_49 ) ;
if ( V_186 ) {
if ( sscanf ( & V_186 [ strlen ( V_27 -> V_10 -> V_49 ) ] , L_93 , V_255 ) == 1 ) {
if ( * V_255 == - 1 )
V_186 [ strlen ( V_27 -> V_10 -> V_49 ) ] = '\0' ;
}
} else {
if ( sscanf ( V_49 , L_94 , & V_340 , & V_341 ) == 2 ) {
char V_342 [ V_339 ] ;
* V_255 = ( ( V_340 & 0xffff ) << 16 ) + V_341 ;
snprintf ( V_342 , V_339 , L_95 , V_27 -> V_10 -> V_49 , V_49 ) ;
F_227 ( V_49 , V_342 , V_339 ) ;
} else
* V_255 = 0 ;
}
return F_228 ( V_49 , V_37 ) ;
}
static inline char * F_229 ( struct V_26 * V_27 ,
struct V_87 * V_343 )
{
if ( V_343 -> V_49 == NULL ) {
F_50 ( V_27 ,
L_96 ,
F_69 ( V_27 ) ) ;
return NULL ;
}
return F_228 ( V_343 -> V_49 , V_37 ) ;
}
static int F_230 ( struct V_26 * V_27 ,
struct V_87 * V_343 )
{
struct V_4 * V_5 ;
struct V_58 * V_59 ;
F_42 ( V_27 , L_97 , F_69 ( V_27 ) ) ;
V_59 = F_94 ( sizeof( struct V_58 ) , V_37 ) ;
if ( V_59 == NULL )
return - V_38 ;
V_59 -> V_49 = F_226 ( V_27 , & V_59 -> V_255 ) ;
if ( V_59 -> V_49 == NULL ) {
F_16 ( V_59 ) ;
return - V_38 ;
}
V_59 -> V_27 = V_27 ;
V_59 -> V_10 = V_343 ;
V_59 -> V_54 . V_27 = V_27 ;
if ( ! V_59 -> V_10 -> V_90 )
V_59 -> V_10 -> V_90 = & V_344 ;
F_149 ( & V_345 ) ;
F_34 (codec, &codec_list, list) {
if ( V_5 -> V_27 == V_27 ) {
F_42 ( V_27 , L_98 ,
V_59 -> V_49 , V_5 -> V_49 ) ;
V_59 -> V_5 = V_5 ;
break;
}
}
if ( ! V_59 -> V_5 )
V_59 -> V_54 . V_105 = 1 ;
F_89 ( & V_59 -> V_155 , & V_346 ) ;
F_132 ( & V_345 ) ;
F_42 ( V_27 , L_99 , V_59 -> V_49 ) ;
return 0 ;
}
static void F_231 ( struct V_26 * V_27 )
{
struct V_58 * V_59 ;
F_34 (dai, &dai_list, list) {
if ( V_27 == V_59 -> V_27 )
goto V_186;
}
return;
V_186:
F_149 ( & V_345 ) ;
F_72 ( & V_59 -> V_155 ) ;
F_132 ( & V_345 ) ;
F_42 ( V_27 , L_100 , V_59 -> V_49 ) ;
F_16 ( V_59 -> V_49 ) ;
F_16 ( V_59 ) ;
}
static int F_232 ( struct V_26 * V_27 ,
struct V_87 * V_343 , T_1 V_18 )
{
struct V_4 * V_5 ;
struct V_58 * V_59 ;
int V_3 , V_14 = 0 ;
F_42 ( V_27 , L_101 , F_69 ( V_27 ) , V_18 ) ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ ) {
V_59 = F_94 ( sizeof( struct V_58 ) , V_37 ) ;
if ( V_59 == NULL ) {
V_14 = - V_38 ;
goto V_74;
}
V_59 -> V_49 = F_229 ( V_27 , & V_343 [ V_3 ] ) ;
if ( V_59 -> V_49 == NULL ) {
F_16 ( V_59 ) ;
V_14 = - V_17 ;
goto V_74;
}
V_59 -> V_27 = V_27 ;
V_59 -> V_10 = & V_343 [ V_3 ] ;
if ( V_59 -> V_10 -> V_255 )
V_59 -> V_255 = V_59 -> V_10 -> V_255 ;
else
V_59 -> V_255 = V_3 ;
V_59 -> V_54 . V_27 = V_27 ;
if ( ! V_59 -> V_10 -> V_90 )
V_59 -> V_10 -> V_90 = & V_344 ;
F_149 ( & V_345 ) ;
F_34 (codec, &codec_list, list) {
if ( V_5 -> V_27 == V_27 ) {
F_42 ( V_27 ,
L_98 ,
V_59 -> V_49 , V_5 -> V_49 ) ;
V_59 -> V_5 = V_5 ;
break;
}
}
if ( ! V_59 -> V_5 )
V_59 -> V_54 . V_105 = 1 ;
F_89 ( & V_59 -> V_155 , & V_346 ) ;
F_132 ( & V_345 ) ;
F_42 ( V_59 -> V_27 , L_99 , V_59 -> V_49 ) ;
}
return 0 ;
V_74:
for ( V_3 -- ; V_3 >= 0 ; V_3 -- )
F_231 ( V_27 ) ;
return V_14 ;
}
static void F_233 ( struct V_26 * V_27 , T_1 V_18 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ )
F_231 ( V_27 ) ;
}
int F_234 ( struct V_26 * V_27 , struct V_55 * V_56 ,
const struct V_157 * V_347 )
{
V_56 -> V_49 = F_226 ( V_27 , & V_56 -> V_255 ) ;
if ( V_56 -> V_49 == NULL )
return - V_38 ;
V_56 -> V_27 = V_27 ;
V_56 -> V_10 = V_347 ;
V_56 -> V_54 . V_27 = V_27 ;
V_56 -> V_54 . V_56 = V_56 ;
V_56 -> V_54 . V_348 = V_347 -> V_348 ;
F_97 ( & V_56 -> V_191 ) ;
F_149 ( & V_345 ) ;
F_89 ( & V_56 -> V_155 , & V_349 ) ;
F_132 ( & V_345 ) ;
F_42 ( V_27 , L_102 , V_56 -> V_49 ) ;
return 0 ;
}
int F_235 ( struct V_26 * V_27 ,
const struct V_157 * V_347 )
{
struct V_55 * V_56 ;
int V_14 ;
F_42 ( V_27 , L_103 , F_69 ( V_27 ) ) ;
V_56 = F_94 ( sizeof( struct V_55 ) , V_37 ) ;
if ( V_56 == NULL )
return - V_38 ;
V_14 = F_234 ( V_27 , V_56 , V_347 ) ;
if ( V_14 )
F_16 ( V_56 ) ;
return V_14 ;
}
void F_236 ( struct V_55 * V_56 )
{
F_149 ( & V_345 ) ;
F_72 ( & V_56 -> V_155 ) ;
F_132 ( & V_345 ) ;
F_42 ( V_56 -> V_27 , L_104 ,
V_56 -> V_49 ) ;
F_16 ( V_56 -> V_49 ) ;
}
struct V_55 * F_237 ( struct V_26 * V_27 )
{
struct V_55 * V_56 ;
F_34 (platform, &platform_list, list) {
if ( V_27 == V_56 -> V_27 )
return V_56 ;
}
return NULL ;
}
void F_238 ( struct V_26 * V_27 )
{
struct V_55 * V_56 ;
V_56 = F_237 ( V_27 ) ;
if ( ! V_56 )
return;
F_236 ( V_56 ) ;
F_16 ( V_56 ) ;
}
static void F_239 ( struct V_350 * V_66 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_127 ( V_351 ) ; V_3 ++ )
if ( V_66 -> V_352 & V_351 [ V_3 ] )
V_66 -> V_352 |= V_351 [ V_3 ] ;
}
int F_240 ( struct V_26 * V_27 ,
const struct V_143 * V_353 ,
struct V_87 * V_343 ,
int V_354 )
{
T_1 V_355 ;
struct V_4 * V_5 ;
int V_14 , V_3 ;
F_42 ( V_27 , L_105 , F_69 ( V_27 ) ) ;
V_5 = F_94 ( sizeof( struct V_4 ) , V_37 ) ;
if ( V_5 == NULL )
return - V_38 ;
V_5 -> V_49 = F_226 ( V_27 , & V_5 -> V_255 ) ;
if ( V_5 -> V_49 == NULL ) {
V_14 = - V_38 ;
goto V_356;
}
if ( V_353 -> V_188 )
V_5 -> V_188 = V_353 -> V_188 ;
else
V_5 -> V_188 = V_357 ;
V_5 -> V_149 = V_353 -> V_149 ;
V_5 -> V_218 = V_353 -> V_218 ;
V_5 -> V_215 = V_353 -> V_215 ;
V_5 -> V_216 = V_353 -> V_216 ;
V_5 -> V_217 = V_353 -> V_217 ;
V_5 -> V_358 = V_353 -> V_358 ;
V_5 -> V_54 . V_100 = V_106 ;
V_5 -> V_54 . V_27 = V_27 ;
V_5 -> V_54 . V_5 = V_5 ;
V_5 -> V_54 . V_359 = V_353 -> V_359 ;
V_5 -> V_54 . V_348 = V_353 -> V_348 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_10 = V_353 ;
V_5 -> V_354 = V_354 ;
F_97 ( & V_5 -> V_191 ) ;
if ( V_353 -> V_11 && V_353 -> V_13 ) {
V_355 = V_353 -> V_11 * V_353 -> V_13 ;
V_5 -> V_355 = V_355 ;
if ( V_353 -> V_360 ) {
V_5 -> V_361 = F_205 ( V_353 -> V_360 ,
V_355 , V_37 ) ;
if ( ! V_5 -> V_361 ) {
V_14 = - V_38 ;
goto V_362;
}
}
}
if ( V_353 -> V_363 && V_353 -> V_364 ) {
if ( ! V_5 -> V_215 )
V_5 -> V_215 = V_365 ;
if ( ! V_5 -> V_216 )
V_5 -> V_216 = V_366 ;
if ( ! V_5 -> V_217 )
V_5 -> V_217 = V_367 ;
}
for ( V_3 = 0 ; V_3 < V_354 ; V_3 ++ ) {
F_239 ( & V_343 [ V_3 ] . V_368 ) ;
F_239 ( & V_343 [ V_3 ] . V_369 ) ;
}
F_149 ( & V_345 ) ;
F_89 ( & V_5 -> V_155 , & V_370 ) ;
F_132 ( & V_345 ) ;
V_14 = F_232 ( V_27 , V_343 , V_354 ) ;
if ( V_14 < 0 ) {
F_50 ( V_5 -> V_27 , L_106 , V_14 ) ;
goto V_362;
}
F_42 ( V_5 -> V_27 , L_107 , V_5 -> V_49 ) ;
return 0 ;
V_362:
F_149 ( & V_345 ) ;
F_72 ( & V_5 -> V_155 ) ;
F_132 ( & V_345 ) ;
F_16 ( V_5 -> V_49 ) ;
V_356:
F_16 ( V_5 ) ;
return V_14 ;
}
void F_241 ( struct V_26 * V_27 )
{
struct V_4 * V_5 ;
F_34 (codec, &codec_list, list) {
if ( V_27 == V_5 -> V_27 )
goto V_186;
}
return;
V_186:
F_233 ( V_27 , V_5 -> V_354 ) ;
F_149 ( & V_345 ) ;
F_72 ( & V_5 -> V_155 ) ;
F_132 ( & V_345 ) ;
F_42 ( V_5 -> V_27 , L_108 , V_5 -> V_49 ) ;
F_242 ( V_5 ) ;
F_16 ( V_5 -> V_361 ) ;
F_16 ( V_5 -> V_49 ) ;
F_16 ( V_5 ) ;
}
int F_243 ( struct V_26 * V_27 ,
const struct V_371 * V_372 ,
struct V_87 * V_343 ,
int V_354 )
{
struct V_373 * V_374 ;
int V_14 ;
F_42 ( V_27 , L_109 , F_69 ( V_27 ) ) ;
V_374 = F_225 ( V_27 , sizeof( * V_374 ) , V_37 ) ;
if ( ! V_374 ) {
F_50 ( V_27 , L_110 ) ;
return - V_38 ;
}
V_374 -> V_49 = F_226 ( V_27 , & V_374 -> V_255 ) ;
if ( ! V_374 -> V_49 ) {
F_50 ( V_27 , L_111 ) ;
return - V_38 ;
}
V_374 -> V_27 = V_27 ;
V_374 -> V_10 = V_372 ;
V_374 -> V_354 = V_354 ;
if ( 1 == V_354 )
V_14 = F_230 ( V_27 , V_343 ) ;
else
V_14 = F_232 ( V_27 , V_343 , V_354 ) ;
if ( V_14 < 0 ) {
F_50 ( V_27 , L_106 , V_14 ) ;
goto V_375;
}
F_149 ( & V_345 ) ;
F_89 ( & V_374 -> V_155 , & V_376 ) ;
F_132 ( & V_345 ) ;
F_42 ( V_374 -> V_27 , L_112 , V_374 -> V_49 ) ;
return V_14 ;
V_375:
F_16 ( V_374 -> V_49 ) ;
return V_14 ;
}
void F_244 ( struct V_26 * V_27 )
{
struct V_373 * V_374 ;
F_34 (cmpnt, &component_list, list) {
if ( V_27 == V_374 -> V_27 )
goto V_186;
}
return;
V_186:
F_233 ( V_27 , V_374 -> V_354 ) ;
F_149 ( & V_345 ) ;
F_72 ( & V_374 -> V_155 ) ;
F_132 ( & V_345 ) ;
F_42 ( V_27 , L_113 , V_374 -> V_49 ) ;
F_16 ( V_374 -> V_49 ) ;
}
int F_245 ( struct V_60 * V_47 ,
const char * V_377 )
{
struct V_378 * V_379 = V_47 -> V_27 -> V_120 ;
int V_14 ;
V_14 = F_246 ( V_379 , V_377 , 0 , & V_47 -> V_49 ) ;
if ( V_14 < 0 && V_14 != - V_17 ) {
F_50 ( V_47 -> V_27 ,
L_114 ,
V_377 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
int F_247 ( struct V_60 * V_47 ,
const char * V_377 )
{
struct V_378 * V_379 = V_47 -> V_27 -> V_120 ;
int V_380 ;
struct V_381 * V_382 ;
int V_3 , V_14 ;
V_380 = F_248 ( V_379 , V_377 ) ;
if ( V_380 < 0 || V_380 & 1 ) {
F_50 ( V_47 -> V_27 ,
L_115 ,
V_377 ) ;
return - V_17 ;
}
V_380 /= 2 ;
if ( ! V_380 ) {
F_50 ( V_47 -> V_27 , L_116 ,
V_377 ) ;
return - V_17 ;
}
V_382 = F_225 ( V_47 -> V_27 , V_380 * sizeof( * V_382 ) ,
V_37 ) ;
if ( ! V_382 ) {
F_50 ( V_47 -> V_27 ,
L_117 ) ;
return - V_17 ;
}
for ( V_3 = 0 ; V_3 < V_380 ; V_3 ++ ) {
V_14 = F_246 ( V_379 , V_377 ,
2 * V_3 , & V_382 [ V_3 ] . V_383 ) ;
if ( V_14 ) {
F_50 ( V_47 -> V_27 ,
L_118 ,
V_377 , 2 * V_3 , V_14 ) ;
return - V_17 ;
}
V_14 = F_246 ( V_379 , V_377 ,
( 2 * V_3 ) + 1 , & V_382 [ V_3 ] . V_312 ) ;
if ( V_14 ) {
F_50 ( V_47 -> V_27 ,
L_118 ,
V_377 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_17 ;
}
}
V_47 -> V_154 = V_380 ;
V_47 -> V_153 = V_382 ;
return 0 ;
}
unsigned int F_249 ( struct V_378 * V_379 ,
const char * V_248 )
{
int V_14 , V_3 ;
char V_384 [ 128 ] ;
unsigned int V_385 = 0 ;
int V_386 , V_387 ;
const char * V_388 ;
struct {
char * V_49 ;
unsigned int V_1 ;
} V_389 [] = {
{ L_119 , V_390 } ,
{ L_120 , V_391 } ,
{ L_121 , V_392 } ,
{ L_122 , V_393 } ,
{ L_123 , V_394 } ,
{ L_124 , V_395 } ,
{ L_125 , V_396 } ,
{ L_126 , V_397 } ,
{ L_127 , V_398 } ,
} ;
if ( ! V_248 )
V_248 = L_128 ;
snprintf ( V_384 , sizeof( V_384 ) , L_129 , V_248 ) ;
V_14 = F_250 ( V_379 , V_384 , & V_388 ) ;
if ( V_14 == 0 ) {
for ( V_3 = 0 ; V_3 < F_127 ( V_389 ) ; V_3 ++ ) {
if ( strcmp ( V_388 , V_389 [ V_3 ] . V_49 ) == 0 ) {
V_385 |= V_389 [ V_3 ] . V_1 ;
break;
}
}
}
snprintf ( V_384 , sizeof( V_384 ) , L_130 , V_248 ) ;
if ( F_251 ( V_379 , V_384 , NULL ) )
V_385 |= V_399 ;
else
V_385 |= V_400 ;
snprintf ( V_384 , sizeof( V_384 ) , L_131 , V_248 ) ;
V_386 = ! ! F_251 ( V_379 , V_384 , NULL ) ;
snprintf ( V_384 , sizeof( V_384 ) , L_132 , V_248 ) ;
V_387 = ! ! F_251 ( V_379 , V_384 , NULL ) ;
switch ( ( V_386 << 4 ) + V_387 ) {
case 0x11 :
V_385 |= V_401 ;
break;
case 0x10 :
V_385 |= V_402 ;
break;
case 0x01 :
V_385 |= V_403 ;
break;
default:
break;
}
snprintf ( V_384 , sizeof( V_384 ) , L_133 , V_248 ) ;
V_386 = ! ! F_251 ( V_379 , V_384 , NULL ) ;
snprintf ( V_384 , sizeof( V_384 ) , L_134 , V_248 ) ;
V_387 = ! ! F_251 ( V_379 , V_384 , NULL ) ;
switch ( ( V_386 << 4 ) + V_387 ) {
case 0x11 :
V_385 |= V_202 ;
break;
case 0x10 :
V_385 |= V_204 ;
break;
case 0x01 :
V_385 |= V_205 ;
break;
default:
V_385 |= V_203 ;
break;
}
return V_385 ;
}
static int T_5 F_252 ( void )
{
#ifdef F_103
V_61 = F_24 ( L_135 , NULL ) ;
if ( F_158 ( V_61 ) || ! V_61 ) {
F_253 ( L_136 ) ;
V_61 = NULL ;
}
if ( ! F_27 ( L_137 , 0444 , V_61 , NULL ,
& V_404 ) )
F_253 ( L_138 ) ;
if ( ! F_27 ( L_139 , 0444 , V_61 , NULL ,
& V_405 ) )
F_253 ( L_140 ) ;
if ( ! F_27 ( L_141 , 0444 , V_61 , NULL ,
& V_406 ) )
F_253 ( L_142 ) ;
#endif
F_254 () ;
return F_255 ( & V_407 ) ;
}
static void T_6 F_256 ( void )
{
F_257 () ;
#ifdef F_103
F_30 ( V_61 ) ;
#endif
F_258 ( & V_407 ) ;
}
