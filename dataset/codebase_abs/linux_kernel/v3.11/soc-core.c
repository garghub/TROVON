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
V_40 = F_7 ( V_18 , ( sizeof( V_7 ) - 1 ) ) ;
if ( F_18 ( V_7 , V_34 , V_40 ) )
return - V_39 ;
V_7 [ V_40 ] = 0 ;
while ( * V_41 == ' ' )
V_41 ++ ;
V_6 = F_19 ( V_41 , & V_41 , 16 ) ;
while ( * V_41 == ' ' )
V_41 ++ ;
if ( F_20 ( V_41 , 16 , & V_42 ) )
return - V_17 ;
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
int F_51 ( struct V_26 * V_27 )
{
struct V_60 * V_47 = F_9 ( V_27 ) ;
struct V_4 * V_5 ;
int V_3 ;
if ( F_52 ( & V_47 -> V_80 ) )
return 0 ;
F_53 ( V_47 -> V_78 ) ;
F_54 ( V_47 -> V_78 , V_81 ) ;
F_55 ( V_47 -> V_78 ) ;
F_56 ( V_47 -> V_78 , V_82 ) ;
for ( V_3 = 0 ; V_3 < V_47 -> V_83 ; V_3 ++ ) {
struct V_58 * V_59 = V_47 -> V_31 [ V_3 ] . V_84 ;
struct V_85 * V_86 = V_59 -> V_10 ;
if ( V_47 -> V_31 [ V_3 ] . V_65 -> V_87 )
continue;
if ( V_86 -> V_88 -> V_89 && V_59 -> V_90 )
V_86 -> V_88 -> V_89 ( V_59 , 1 ) ;
}
for ( V_3 = 0 ; V_3 < V_47 -> V_83 ; V_3 ++ ) {
if ( V_47 -> V_31 [ V_3 ] . V_65 -> V_87 )
continue;
F_57 ( V_47 -> V_31 [ V_3 ] . V_69 ) ;
}
if ( V_47 -> V_91 )
V_47 -> V_91 ( V_47 ) ;
for ( V_3 = 0 ; V_3 < V_47 -> V_83 ; V_3 ++ ) {
struct V_58 * V_92 = V_47 -> V_31 [ V_3 ] . V_92 ;
struct V_55 * V_56 = V_47 -> V_31 [ V_3 ] . V_56 ;
if ( V_47 -> V_31 [ V_3 ] . V_65 -> V_87 )
continue;
if ( V_92 -> V_10 -> V_93 && ! V_92 -> V_10 -> V_94 )
V_92 -> V_10 -> V_93 ( V_92 ) ;
if ( V_56 -> V_10 -> V_93 && ! V_56 -> V_95 ) {
V_56 -> V_10 -> V_93 ( V_92 ) ;
V_56 -> V_95 = 1 ;
}
}
for ( V_3 = 0 ; V_3 < V_47 -> V_83 ; V_3 ++ ) {
F_58 ( & V_47 -> V_31 [ V_3 ] . V_96 ) ;
V_47 -> V_31 [ V_3 ] . V_5 -> V_54 . V_97 = V_47 -> V_31 [ V_3 ] . V_5 -> V_54 . V_98 ;
}
for ( V_3 = 0 ; V_3 < V_47 -> V_83 ; V_3 ++ ) {
if ( V_47 -> V_31 [ V_3 ] . V_65 -> V_87 )
continue;
F_59 ( & V_47 -> V_31 [ V_3 ] ,
V_99 ,
V_100 ) ;
F_59 ( & V_47 -> V_31 [ V_3 ] ,
V_101 ,
V_100 ) ;
}
F_60 ( & V_47 -> V_54 ) ;
F_61 ( & V_47 -> V_54 ) ;
F_34 (codec, &card->codec_dev_list, card_list) {
if ( ! V_5 -> V_95 && V_5 -> V_10 -> V_93 ) {
switch ( V_5 -> V_54 . V_98 ) {
case V_102 :
if ( V_5 -> V_54 . V_103 ) {
F_42 ( V_5 -> V_27 ,
L_18 ) ;
break;
}
case V_104 :
V_5 -> V_10 -> V_93 ( V_5 ) ;
V_5 -> V_95 = 1 ;
V_5 -> V_50 = 1 ;
if ( V_5 -> V_105 )
F_62 ( V_5 -> V_106 ) ;
break;
default:
F_42 ( V_5 -> V_27 ,
L_19 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_47 -> V_83 ; V_3 ++ ) {
struct V_58 * V_92 = V_47 -> V_31 [ V_3 ] . V_92 ;
if ( V_47 -> V_31 [ V_3 ] . V_65 -> V_87 )
continue;
if ( V_92 -> V_10 -> V_93 && V_92 -> V_10 -> V_94 )
V_92 -> V_10 -> V_93 ( V_92 ) ;
}
if ( V_47 -> V_107 )
V_47 -> V_107 ( V_47 ) ;
return 0 ;
}
static void F_63 ( struct V_108 * V_109 )
{
struct V_60 * V_47 =
F_64 ( V_109 , struct V_60 , V_110 ) ;
struct V_4 * V_5 ;
int V_3 ;
F_42 ( V_47 -> V_27 , L_20 ) ;
F_56 ( V_47 -> V_78 , V_111 ) ;
if ( V_47 -> V_112 )
V_47 -> V_112 ( V_47 ) ;
for ( V_3 = 0 ; V_3 < V_47 -> V_83 ; V_3 ++ ) {
struct V_58 * V_92 = V_47 -> V_31 [ V_3 ] . V_92 ;
if ( V_47 -> V_31 [ V_3 ] . V_65 -> V_87 )
continue;
if ( V_92 -> V_10 -> V_113 && V_92 -> V_10 -> V_94 )
V_92 -> V_10 -> V_113 ( V_92 ) ;
}
F_34 (codec, &card->codec_dev_list, card_list) {
if ( V_5 -> V_10 -> V_113 && V_5 -> V_95 ) {
switch ( V_5 -> V_54 . V_98 ) {
case V_102 :
case V_104 :
V_5 -> V_10 -> V_113 ( V_5 ) ;
V_5 -> V_95 = 0 ;
break;
default:
F_42 ( V_5 -> V_27 ,
L_21 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_47 -> V_83 ; V_3 ++ ) {
if ( V_47 -> V_31 [ V_3 ] . V_65 -> V_87 )
continue;
F_59 ( & V_47 -> V_31 [ V_3 ] ,
V_99 ,
V_114 ) ;
F_59 ( & V_47 -> V_31 [ V_3 ] ,
V_101 ,
V_114 ) ;
}
for ( V_3 = 0 ; V_3 < V_47 -> V_83 ; V_3 ++ ) {
struct V_58 * V_59 = V_47 -> V_31 [ V_3 ] . V_84 ;
struct V_85 * V_86 = V_59 -> V_10 ;
if ( V_47 -> V_31 [ V_3 ] . V_65 -> V_87 )
continue;
if ( V_86 -> V_88 -> V_89 && V_59 -> V_90 )
V_86 -> V_88 -> V_89 ( V_59 , 0 ) ;
}
for ( V_3 = 0 ; V_3 < V_47 -> V_83 ; V_3 ++ ) {
struct V_58 * V_92 = V_47 -> V_31 [ V_3 ] . V_92 ;
struct V_55 * V_56 = V_47 -> V_31 [ V_3 ] . V_56 ;
if ( V_47 -> V_31 [ V_3 ] . V_65 -> V_87 )
continue;
if ( V_92 -> V_10 -> V_113 && ! V_92 -> V_10 -> V_94 )
V_92 -> V_10 -> V_113 ( V_92 ) ;
if ( V_56 -> V_10 -> V_113 && V_56 -> V_95 ) {
V_56 -> V_10 -> V_113 ( V_92 ) ;
V_56 -> V_95 = 0 ;
}
}
if ( V_47 -> V_115 )
V_47 -> V_115 ( V_47 ) ;
F_42 ( V_47 -> V_27 , L_22 ) ;
F_56 ( V_47 -> V_78 , V_81 ) ;
F_60 ( & V_47 -> V_54 ) ;
F_61 ( & V_47 -> V_54 ) ;
}
int F_65 ( struct V_26 * V_27 )
{
struct V_60 * V_47 = F_9 ( V_27 ) ;
int V_3 , V_94 = 0 ;
if ( F_52 ( & V_47 -> V_80 ) )
return 0 ;
for ( V_3 = 0 ; V_3 < V_47 -> V_83 ; V_3 ++ ) {
struct V_58 * V_92 = V_47 -> V_31 [ V_3 ] . V_92 ;
V_94 |= V_92 -> V_10 -> V_94 ;
}
if ( V_94 ) {
F_42 ( V_27 , L_23 ) ;
F_63 ( & V_47 -> V_110 ) ;
} else {
F_42 ( V_27 , L_24 ) ;
if ( ! F_66 ( & V_47 -> V_110 ) )
F_50 ( V_27 , L_25 ) ;
}
return 0 ;
}
static int F_67 ( struct V_60 * V_47 , int V_116 )
{
struct V_117 * V_65 = & V_47 -> V_65 [ V_116 ] ;
struct V_30 * V_31 = & V_47 -> V_31 [ V_116 ] ;
struct V_4 * V_5 ;
struct V_55 * V_56 ;
struct V_58 * V_84 , * V_92 ;
const char * V_118 ;
F_42 ( V_47 -> V_27 , L_26 , V_65 -> V_49 , V_116 ) ;
F_34 (cpu_dai, &dai_list, list) {
if ( V_65 -> V_119 &&
( V_92 -> V_27 -> V_120 != V_65 -> V_119 ) )
continue;
if ( V_65 -> V_121 &&
strcmp ( F_68 ( V_92 -> V_27 ) , V_65 -> V_121 ) )
continue;
if ( V_65 -> V_122 &&
strcmp ( V_92 -> V_49 , V_65 -> V_122 ) )
continue;
V_31 -> V_92 = V_92 ;
}
if ( ! V_31 -> V_92 ) {
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
if ( V_5 -> V_27 == V_84 -> V_27 &&
! strcmp ( V_84 -> V_49 ,
V_65 -> V_126 ) ) {
V_31 -> V_84 = V_84 ;
}
}
if ( ! V_31 -> V_84 ) {
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
V_47 -> V_83 ++ ;
return 0 ;
}
static int F_69 ( struct V_55 * V_56 )
{
int V_14 ;
if ( V_56 -> V_10 -> remove ) {
V_14 = V_56 -> V_10 -> remove ( V_56 ) ;
if ( V_14 < 0 )
F_50 ( V_56 -> V_27 , L_32 ,
V_14 ) ;
}
F_70 ( & V_56 -> V_54 ) ;
F_32 ( V_56 ) ;
V_56 -> V_128 = 0 ;
F_71 ( & V_56 -> V_129 ) ;
F_72 ( V_56 -> V_27 -> V_10 -> V_130 ) ;
return 0 ;
}
static void F_73 ( struct V_4 * V_5 )
{
int V_74 ;
if ( V_5 -> V_10 -> remove ) {
V_74 = V_5 -> V_10 -> remove ( V_5 ) ;
if ( V_74 < 0 )
F_50 ( V_5 -> V_27 , L_32 , V_74 ) ;
}
F_70 ( & V_5 -> V_54 ) ;
F_29 ( V_5 ) ;
V_5 -> V_128 = 0 ;
F_71 ( & V_5 -> V_129 ) ;
F_72 ( V_5 -> V_27 -> V_10 -> V_130 ) ;
}
static void F_74 ( struct V_60 * V_47 , int V_116 , int V_131 )
{
struct V_30 * V_31 = & V_47 -> V_31 [ V_116 ] ;
struct V_58 * V_84 = V_31 -> V_84 , * V_92 = V_31 -> V_92 ;
int V_74 ;
if ( V_31 -> V_132 ) {
F_75 ( V_31 -> V_27 , & V_133 ) ;
F_75 ( V_31 -> V_27 , & V_134 ) ;
F_45 ( V_31 -> V_27 ) ;
V_31 -> V_132 = 0 ;
}
if ( V_84 && V_84 -> V_128 &&
V_84 -> V_10 -> V_135 == V_131 ) {
if ( V_84 -> V_10 -> remove ) {
V_74 = V_84 -> V_10 -> remove ( V_84 ) ;
if ( V_74 < 0 )
F_50 ( V_84 -> V_27 ,
L_33 ,
V_84 -> V_49 , V_74 ) ;
}
V_84 -> V_128 = 0 ;
F_71 ( & V_84 -> V_129 ) ;
}
if ( V_92 && V_92 -> V_128 &&
V_92 -> V_10 -> V_135 == V_131 ) {
if ( V_92 -> V_10 -> remove ) {
V_74 = V_92 -> V_10 -> remove ( V_92 ) ;
if ( V_74 < 0 )
F_50 ( V_92 -> V_27 ,
L_33 ,
V_92 -> V_49 , V_74 ) ;
}
V_92 -> V_128 = 0 ;
F_71 ( & V_92 -> V_129 ) ;
if ( ! V_92 -> V_5 ) {
F_70 ( & V_92 -> V_54 ) ;
F_72 ( V_92 -> V_27 -> V_10 -> V_130 ) ;
}
}
}
static void F_76 ( struct V_60 * V_47 , int V_116 ,
int V_131 )
{
struct V_30 * V_31 = & V_47 -> V_31 [ V_116 ] ;
struct V_58 * V_92 = V_31 -> V_92 ;
struct V_58 * V_84 = V_31 -> V_84 ;
struct V_55 * V_56 = V_31 -> V_56 ;
struct V_4 * V_5 ;
if ( V_56 && V_56 -> V_128 &&
V_56 -> V_10 -> V_135 == V_131 ) {
F_69 ( V_56 ) ;
}
if ( V_84 ) {
V_5 = V_84 -> V_5 ;
if ( V_5 && V_5 -> V_128 &&
V_5 -> V_10 -> V_135 == V_131 )
F_73 ( V_5 ) ;
}
if ( V_92 ) {
V_5 = V_92 -> V_5 ;
if ( V_5 && V_5 -> V_128 &&
V_5 -> V_10 -> V_135 == V_131 )
F_73 ( V_5 ) ;
}
}
static void F_77 ( struct V_60 * V_47 )
{
int V_59 , V_131 ;
for ( V_131 = V_136 ; V_131 <= V_137 ;
V_131 ++ ) {
for ( V_59 = 0 ; V_59 < V_47 -> V_83 ; V_59 ++ )
F_74 ( V_47 , V_59 , V_131 ) ;
}
for ( V_131 = V_136 ; V_131 <= V_137 ;
V_131 ++ ) {
for ( V_59 = 0 ; V_59 < V_47 -> V_83 ; V_59 ++ )
F_76 ( V_47 , V_59 , V_131 ) ;
}
V_47 -> V_83 = 0 ;
}
static void F_78 ( struct V_60 * V_47 ,
struct V_4 * V_5 )
{
int V_3 ;
if ( V_47 -> V_138 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_47 -> V_139 ; V_3 ++ ) {
struct V_140 * V_141 = & V_47 -> V_138 [ V_3 ] ;
if ( V_141 -> F_68 && ! strcmp ( V_5 -> V_49 , V_141 -> F_68 ) ) {
V_5 -> V_142 = V_141 -> V_142 ;
break;
}
}
}
static int F_79 ( struct V_60 * V_47 ,
struct V_4 * V_5 )
{
int V_14 = 0 ;
const struct V_143 * V_10 = V_5 -> V_10 ;
struct V_58 * V_59 ;
V_5 -> V_47 = V_47 ;
V_5 -> V_54 . V_47 = V_47 ;
F_78 ( V_47 , V_5 ) ;
if ( ! F_80 ( V_5 -> V_27 -> V_10 -> V_130 ) )
return - V_144 ;
F_23 ( V_5 ) ;
if ( V_10 -> V_145 )
F_81 ( & V_5 -> V_54 , V_10 -> V_145 ,
V_10 -> V_146 ) ;
F_34 (dai, &dai_list, list) {
if ( V_59 -> V_27 != V_5 -> V_27 )
continue;
F_82 ( & V_5 -> V_54 , V_59 ) ;
}
V_5 -> V_54 . V_103 = V_10 -> V_103 ;
if ( V_10 -> V_147 ) {
V_14 = V_10 -> V_147 ( V_5 ) ;
if ( V_14 < 0 ) {
F_50 ( V_5 -> V_27 ,
L_34 , V_14 ) ;
goto V_148;
}
F_83 ( V_5 -> V_54 . V_103 &&
V_5 -> V_54 . V_98 != V_104 ,
L_35 ,
V_5 -> V_49 ) ;
}
if ( ! V_5 -> V_149 && F_84 ( V_5 -> V_27 , NULL ) )
F_85 ( V_5 , 0 , 0 , V_150 ) ;
if ( V_10 -> V_151 )
F_86 ( V_5 , V_10 -> V_151 ,
V_10 -> V_152 ) ;
if ( V_10 -> V_153 )
F_87 ( & V_5 -> V_54 , V_10 -> V_153 ,
V_10 -> V_154 ) ;
V_5 -> V_128 = 1 ;
F_88 ( & V_5 -> V_129 , & V_47 -> V_80 ) ;
F_88 ( & V_5 -> V_54 . V_155 , & V_47 -> V_156 ) ;
return 0 ;
V_148:
F_29 ( V_5 ) ;
F_72 ( V_5 -> V_27 -> V_10 -> V_130 ) ;
return V_14 ;
}
static int F_89 ( struct V_60 * V_47 ,
struct V_55 * V_56 )
{
int V_14 = 0 ;
const struct V_157 * V_10 = V_56 -> V_10 ;
struct V_58 * V_59 ;
V_56 -> V_47 = V_47 ;
V_56 -> V_54 . V_47 = V_47 ;
if ( ! F_80 ( V_56 -> V_27 -> V_10 -> V_130 ) )
return - V_144 ;
F_31 ( V_56 ) ;
if ( V_10 -> V_145 )
F_81 ( & V_56 -> V_54 ,
V_10 -> V_145 , V_10 -> V_146 ) ;
F_34 (dai, &dai_list, list) {
if ( V_59 -> V_27 != V_56 -> V_27 )
continue;
F_82 ( & V_56 -> V_54 , V_59 ) ;
}
V_56 -> V_54 . V_103 = 1 ;
if ( V_10 -> V_147 ) {
V_14 = V_10 -> V_147 ( V_56 ) ;
if ( V_14 < 0 ) {
F_50 ( V_56 -> V_27 ,
L_36 , V_14 ) ;
goto V_148;
}
}
if ( V_10 -> V_151 )
F_90 ( V_56 , V_10 -> V_151 ,
V_10 -> V_152 ) ;
if ( V_10 -> V_153 )
F_87 ( & V_56 -> V_54 , V_10 -> V_153 ,
V_10 -> V_154 ) ;
V_56 -> V_128 = 1 ;
F_88 ( & V_56 -> V_129 , & V_47 -> V_158 ) ;
F_88 ( & V_56 -> V_54 . V_155 , & V_47 -> V_156 ) ;
return 0 ;
V_148:
F_32 ( V_56 ) ;
F_72 ( V_56 -> V_27 -> V_10 -> V_130 ) ;
return V_14 ;
}
static void F_91 ( struct V_26 * V_27 )
{
F_16 ( V_27 ) ;
}
static int F_92 ( struct V_60 * V_47 ,
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
F_93 ( & V_5 -> V_54 ) ;
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
V_31 -> V_27 -> V_77 = F_91 ;
V_31 -> V_27 -> V_165 = V_49 ;
F_96 ( V_31 -> V_27 , V_31 ) ;
F_97 ( & V_31 -> V_166 ) ;
F_98 ( & V_31 -> V_167 [ V_99 ] . V_168 ) ;
F_98 ( & V_31 -> V_167 [ V_101 ] . V_168 ) ;
F_98 ( & V_31 -> V_167 [ V_99 ] . V_169 ) ;
F_98 ( & V_31 -> V_167 [ V_101 ] . V_169 ) ;
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
struct V_58 * V_92 = V_31 -> V_92 ;
struct V_58 * V_84 = V_31 -> V_84 ;
struct V_55 * V_56 = V_31 -> V_56 ;
int V_14 ;
if ( V_92 -> V_5 &&
! V_92 -> V_5 -> V_128 &&
V_92 -> V_5 -> V_10 -> V_172 == V_131 ) {
V_14 = F_79 ( V_47 , V_92 -> V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_84 -> V_5 -> V_128 &&
V_84 -> V_5 -> V_10 -> V_172 == V_131 ) {
V_14 = F_79 ( V_47 , V_84 -> V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_56 -> V_128 &&
V_56 -> V_10 -> V_172 == V_131 ) {
V_14 = F_89 ( V_47 , V_56 ) ;
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
struct V_58 * V_84 = V_31 -> V_84 ;
struct V_58 * V_92 = V_31 -> V_92 ;
struct V_173 * V_174 , * V_175 ;
int V_14 ;
F_42 ( V_47 -> V_27 , L_42 ,
V_47 -> V_49 , V_116 , V_131 ) ;
V_92 -> V_56 = V_56 ;
V_84 -> V_47 = V_47 ;
V_92 -> V_47 = V_47 ;
V_31 -> V_32 = V_32 ;
if ( ! V_92 -> V_128 &&
V_92 -> V_10 -> V_172 == V_131 ) {
if ( ! V_92 -> V_5 ) {
V_92 -> V_54 . V_47 = V_47 ;
if ( ! F_80 ( V_92 -> V_27 -> V_10 -> V_130 ) )
return - V_144 ;
F_88 ( & V_92 -> V_54 . V_155 , & V_47 -> V_156 ) ;
F_82 ( & V_92 -> V_54 , V_92 ) ;
}
if ( V_92 -> V_10 -> V_147 ) {
V_14 = V_92 -> V_10 -> V_147 ( V_92 ) ;
if ( V_14 < 0 ) {
F_50 ( V_92 -> V_27 ,
L_43 ,
V_92 -> V_49 , V_14 ) ;
F_72 ( V_92 -> V_27 -> V_10 -> V_130 ) ;
return V_14 ;
}
}
V_92 -> V_128 = 1 ;
F_88 ( & V_92 -> V_129 , & V_47 -> V_176 ) ;
}
if ( ! V_84 -> V_128 && V_84 -> V_10 -> V_172 == V_131 ) {
if ( V_84 -> V_10 -> V_147 ) {
V_14 = V_84 -> V_10 -> V_147 ( V_84 ) ;
if ( V_14 < 0 ) {
F_50 ( V_84 -> V_27 ,
L_44 ,
V_84 -> V_49 , V_14 ) ;
return V_14 ;
}
}
V_84 -> V_128 = 1 ;
F_88 ( & V_84 -> V_129 , & V_47 -> V_176 ) ;
}
if ( V_131 != V_137 )
return 0 ;
V_14 = F_92 ( V_47 , V_5 , V_116 , 0 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_102 ( V_31 -> V_27 , & V_133 ) ;
if ( V_14 < 0 )
F_25 ( V_31 -> V_27 , L_45 ,
V_14 ) ;
if ( V_92 -> V_10 -> V_177 ) {
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
V_174 = V_84 -> V_180 ;
V_175 = V_92 -> V_181 ;
if ( V_174 && V_175 ) {
V_14 = F_109 ( V_47 , V_65 -> V_179 ,
V_175 , V_174 ) ;
if ( V_14 != 0 ) {
F_50 ( V_47 -> V_27 , L_48 ,
V_174 -> V_49 , V_175 -> V_49 , V_14 ) ;
return V_14 ;
}
}
V_174 = V_92 -> V_180 ;
V_175 = V_84 -> V_181 ;
if ( V_174 && V_175 ) {
V_14 = F_109 ( V_47 , V_65 -> V_179 ,
V_175 , V_174 ) ;
if ( V_14 != 0 ) {
F_50 ( V_47 -> V_27 , L_48 ,
V_174 -> V_49 , V_175 -> V_49 , V_14 ) ;
return V_14 ;
}
}
}
}
if ( V_31 -> V_84 -> V_10 -> V_94 )
F_110 ( V_5 -> V_72 , V_31 -> V_92 -> V_182 ) ;
return 0 ;
}
static int F_111 ( struct V_30 * V_31 )
{
int V_14 ;
if ( V_31 -> V_84 -> V_10 -> V_94 && ! V_31 -> V_5 -> V_183 ) {
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
static void F_112 ( struct V_4 * V_5 )
{
if ( V_5 -> V_183 ) {
F_44 ( V_5 ) ;
V_5 -> V_183 = 0 ;
}
}
static int F_113 ( struct V_60 * V_47 , int V_116 )
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
static int F_114 ( struct V_60 * V_47 , int V_116 )
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
V_14 = F_79 ( V_47 , V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_92 ( V_47 , V_5 , V_116 , 1 ) ;
V_171:
return V_14 ;
}
static void F_115 ( struct V_60 * V_47 , int V_116 )
{
struct V_30 * V_31 = & V_47 -> V_163 [ V_116 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
if ( V_31 -> V_132 ) {
F_75 ( V_31 -> V_27 , & V_134 ) ;
F_45 ( V_31 -> V_27 ) ;
V_31 -> V_132 = 0 ;
}
if ( V_5 && V_5 -> V_128 )
F_73 ( V_5 ) ;
}
static int F_116 ( struct V_4 * V_5 ,
enum V_187 V_188 )
{
int V_14 ;
if ( V_5 -> V_189 )
return 0 ;
if ( V_188 && V_5 -> V_188 != V_188 )
V_5 -> V_188 = V_188 ;
V_14 = F_117 ( V_5 ) ;
if ( V_14 < 0 ) {
F_50 ( V_5 -> V_27 ,
L_53 ,
V_14 ) ;
return V_14 ;
}
V_5 -> V_189 = 1 ;
return 0 ;
}
static int F_118 ( struct V_60 * V_47 )
{
struct V_4 * V_5 ;
struct V_140 * V_138 ;
enum V_187 V_188 ;
struct V_117 * V_65 ;
int V_14 , V_3 , V_131 , V_190 ;
F_119 ( & V_47 -> V_191 , V_192 ) ;
for ( V_3 = 0 ; V_3 < V_47 -> V_67 ; V_3 ++ ) {
V_14 = F_67 ( V_47 , V_3 ) ;
if ( V_14 != 0 )
goto V_193;
}
for ( V_3 = 0 ; V_3 < V_47 -> V_194 ; V_3 ++ ) {
V_14 = F_113 ( V_47 , V_3 ) ;
if ( V_14 != 0 )
goto V_193;
}
F_34 (codec, &codec_list, list) {
if ( V_5 -> V_189 )
continue;
V_188 = 0 ;
for ( V_3 = 0 ; V_3 < V_47 -> V_139 ; ++ V_3 ) {
V_138 = & V_47 -> V_138 [ V_3 ] ;
if ( ! strcmp ( V_5 -> V_49 , V_138 -> F_68 ) ) {
V_188 = V_138 -> V_188 ;
if ( V_188 && V_188
!= V_5 -> V_188 )
break;
}
}
V_14 = F_116 ( V_5 , V_188 ) ;
if ( V_14 < 0 )
goto V_193;
}
V_14 = F_120 ( V_195 , V_196 ,
V_47 -> V_130 , 0 , & V_47 -> V_78 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 ,
L_54 ,
V_47 -> V_49 , V_14 ) ;
goto V_193;
}
V_47 -> V_78 -> V_27 = V_47 -> V_27 ;
V_47 -> V_54 . V_98 = V_104 ;
V_47 -> V_54 . V_27 = V_47 -> V_27 ;
V_47 -> V_54 . V_47 = V_47 ;
F_88 ( & V_47 -> V_54 . V_155 , & V_47 -> V_156 ) ;
#ifdef F_103
F_28 ( & V_47 -> V_54 , V_47 -> V_46 ) ;
#endif
#ifdef F_121
F_122 ( & V_47 -> V_110 , F_63 ) ;
#endif
if ( V_47 -> V_145 )
F_81 ( & V_47 -> V_54 , V_47 -> V_145 ,
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
V_14 = F_114 ( V_47 , V_3 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 ,
L_56 ,
V_14 ) ;
goto V_199;
}
}
F_123 ( V_47 ) ;
if ( V_47 -> V_151 )
F_124 ( V_47 , V_47 -> V_151 , V_47 -> V_152 ) ;
if ( V_47 -> V_153 )
F_87 ( & V_47 -> V_54 , V_47 -> V_153 ,
V_47 -> V_154 ) ;
F_93 ( & V_47 -> V_54 ) ;
for ( V_3 = 0 ; V_3 < V_47 -> V_67 ; V_3 ++ ) {
V_65 = & V_47 -> V_65 [ V_3 ] ;
V_190 = V_65 -> V_190 ;
if ( V_190 ) {
V_14 = F_125 ( V_47 -> V_31 [ V_3 ] . V_84 ,
V_190 ) ;
if ( V_14 != 0 && V_14 != - V_200 )
F_25 ( V_47 -> V_31 [ V_3 ] . V_84 -> V_27 ,
L_57 ,
V_14 ) ;
}
if ( V_190 &&
( V_65 -> V_118 || V_65 -> V_127 ) ) {
V_14 = F_125 ( V_47 -> V_31 [ V_3 ] . V_92 ,
V_190 ) ;
if ( V_14 != 0 && V_14 != - V_200 )
F_25 ( V_47 -> V_31 [ V_3 ] . V_92 -> V_27 ,
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
V_14 = F_125 ( V_47 -> V_31 [ V_3 ] . V_92 ,
V_190 ) ;
if ( V_14 != 0 && V_14 != - V_200 )
F_25 ( V_47 -> V_31 [ V_3 ] . V_92 -> V_27 ,
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
for ( V_3 = 0 ; V_3 < F_126 ( V_47 -> V_78 -> V_10 ) ; V_3 ++ ) {
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
F_93 ( & V_47 -> V_54 ) ;
if ( V_47 -> V_211 )
F_34 (codec, &card->codec_dev_list, card_list)
F_127 ( V_5 ) ;
V_14 = F_128 ( V_47 -> V_78 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 , L_60 ,
V_14 ) ;
goto V_199;
}
#ifdef F_129
for ( V_3 = 0 ; V_3 < V_47 -> V_83 ; V_3 ++ ) {
V_14 = F_111 ( & V_47 -> V_31 [ V_3 ] ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 ,
L_61 , V_14 ) ;
while ( -- V_3 >= 0 )
F_112 ( V_47 -> V_31 [ V_3 ] . V_5 ) ;
goto V_199;
}
}
#endif
V_47 -> V_212 = 1 ;
F_61 ( & V_47 -> V_54 ) ;
F_130 ( & V_47 -> V_191 ) ;
return 0 ;
V_199:
for ( V_3 = 0 ; V_3 < V_47 -> V_194 ; V_3 ++ )
F_115 ( V_47 , V_3 ) ;
V_198:
F_77 ( V_47 ) ;
V_197:
if ( V_47 -> remove )
V_47 -> remove ( V_47 ) ;
F_131 ( V_47 -> V_78 ) ;
V_193:
F_130 ( & V_47 -> V_191 ) ;
return V_14 ;
}
static int F_132 ( struct V_213 * V_214 )
{
struct V_60 * V_47 = F_133 ( V_214 ) ;
if ( ! V_47 )
return - V_17 ;
F_25 ( & V_214 -> V_27 ,
L_62 ,
V_47 -> V_49 ) ;
V_47 -> V_27 = & V_214 -> V_27 ;
return F_134 ( V_47 ) ;
}
static int F_135 ( struct V_60 * V_47 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_47 -> V_83 ; V_3 ++ ) {
struct V_30 * V_31 = & V_47 -> V_31 [ V_3 ] ;
F_58 ( & V_31 -> V_96 ) ;
}
for ( V_3 = 0 ; V_3 < V_47 -> V_194 ; V_3 ++ )
F_115 ( V_47 , V_3 ) ;
F_77 ( V_47 ) ;
F_40 ( V_47 ) ;
if ( V_47 -> remove )
V_47 -> remove ( V_47 ) ;
F_70 ( & V_47 -> V_54 ) ;
F_131 ( V_47 -> V_78 ) ;
return 0 ;
}
static int F_136 ( struct V_213 * V_214 )
{
struct V_60 * V_47 = F_133 ( V_214 ) ;
F_137 ( V_47 ) ;
return 0 ;
}
int F_138 ( struct V_26 * V_27 )
{
struct V_60 * V_47 = F_9 ( V_27 ) ;
int V_3 ;
if ( ! V_47 -> V_212 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_47 -> V_83 ; V_3 ++ ) {
struct V_30 * V_31 = & V_47 -> V_31 [ V_3 ] ;
F_58 ( & V_31 -> V_96 ) ;
}
F_139 ( V_47 ) ;
return 0 ;
}
int F_140 ( struct V_4 * V_5 ,
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
int F_141 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_217 )
return V_5 -> V_217 ( V_5 , V_6 ) ;
else
return 1 ;
}
int F_142 ( struct V_55 * V_56 ,
unsigned int V_6 )
{
unsigned int V_14 ;
if ( ! V_56 -> V_10 -> V_218 ) {
F_50 ( V_56 -> V_27 , L_63 ) ;
return - 1 ;
}
V_14 = V_56 -> V_10 -> V_218 ( V_56 , V_6 ) ;
F_42 ( V_56 -> V_27 , L_64 , V_6 , V_14 ) ;
F_143 ( V_56 , V_6 , V_14 ) ;
return V_14 ;
}
int F_144 ( struct V_55 * V_56 ,
unsigned int V_6 , unsigned int V_1 )
{
if ( ! V_56 -> V_10 -> V_149 ) {
F_50 ( V_56 -> V_27 , L_65 ) ;
return - 1 ;
}
F_42 ( V_56 -> V_27 , L_66 , V_6 , V_1 ) ;
F_145 ( V_56 , V_6 , V_1 ) ;
return V_56 -> V_10 -> V_149 ( V_56 , V_6 , V_1 ) ;
}
int F_146 ( struct V_4 * V_5 ,
struct V_219 * V_88 , int V_116 )
{
F_147 ( & V_5 -> V_191 ) ;
V_5 -> V_72 = F_94 ( sizeof( struct V_220 ) , V_37 ) ;
if ( V_5 -> V_72 == NULL ) {
F_130 ( & V_5 -> V_191 ) ;
return - V_38 ;
}
V_5 -> V_72 -> V_73 = F_94 ( sizeof( struct V_221 ) , V_37 ) ;
if ( V_5 -> V_72 -> V_73 == NULL ) {
F_16 ( V_5 -> V_72 ) ;
V_5 -> V_72 = NULL ;
F_130 ( & V_5 -> V_191 ) ;
return - V_38 ;
}
V_5 -> V_72 -> V_73 -> V_88 = V_88 ;
V_5 -> V_72 -> V_116 = V_116 ;
V_5 -> V_184 = 1 ;
F_130 ( & V_5 -> V_191 ) ;
return 0 ;
}
int F_148 ( struct V_219 * V_88 )
{
if ( V_88 == V_222 )
return 0 ;
if ( V_222 && V_88 )
return - V_185 ;
V_222 = V_88 ;
return 0 ;
}
void F_149 ( struct V_4 * V_5 )
{
F_147 ( & V_5 -> V_191 ) ;
#ifdef F_129
F_112 ( V_5 ) ;
#endif
F_16 ( V_5 -> V_72 -> V_73 ) ;
F_16 ( V_5 -> V_72 ) ;
V_5 -> V_72 = NULL ;
V_5 -> V_184 = 0 ;
F_130 ( & V_5 -> V_191 ) ;
}
unsigned int F_4 ( struct V_4 * V_5 , unsigned int V_6 )
{
unsigned int V_14 ;
V_14 = V_5 -> V_218 ( V_5 , V_6 ) ;
F_42 ( V_5 -> V_27 , L_64 , V_6 , V_14 ) ;
F_150 ( V_5 , V_6 , V_14 ) ;
return V_14 ;
}
unsigned int F_22 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned int V_1 )
{
F_42 ( V_5 -> V_27 , L_66 , V_6 , V_1 ) ;
F_151 ( V_5 , V_6 , V_1 ) ;
return V_5 -> V_149 ( V_5 , V_6 , V_1 ) ;
}
unsigned int F_152 ( struct V_4 * V_5 ,
unsigned int V_6 , const void * V_223 , T_1 V_8 )
{
return V_5 -> V_224 ( V_5 , V_6 , V_223 , V_8 ) ;
}
int F_153 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_225 , unsigned int V_42 )
{
bool V_226 ;
unsigned int V_227 , V_228 ;
int V_14 ;
if ( V_5 -> V_105 ) {
V_14 = F_154 ( V_5 -> V_106 , V_6 ,
V_225 , V_42 , & V_226 ) ;
} else {
V_14 = F_4 ( V_5 , V_6 ) ;
if ( V_14 < 0 )
return V_14 ;
V_227 = V_14 ;
V_228 = ( V_227 & ~ V_225 ) | ( V_42 & V_225 ) ;
V_226 = V_227 != V_228 ;
if ( V_226 )
V_14 = F_22 ( V_5 , V_6 , V_228 ) ;
}
if ( V_14 < 0 )
return V_14 ;
return V_226 ;
}
int F_155 ( struct V_4 * V_5 ,
unsigned short V_6 , unsigned int V_225 ,
unsigned int V_42 )
{
int V_226 ;
F_147 ( & V_5 -> V_191 ) ;
V_226 = F_153 ( V_5 , V_6 , V_225 , V_42 ) ;
F_130 ( & V_5 -> V_191 ) ;
return V_226 ;
}
int F_156 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_225 , unsigned int V_42 )
{
int V_226 ;
unsigned int V_227 , V_228 ;
V_227 = F_4 ( V_5 , V_6 ) ;
V_228 = ( V_227 & ~ V_225 ) | V_42 ;
V_226 = V_227 != V_228 ;
return V_226 ;
}
struct V_229 * F_157 ( const struct V_230 * V_231 ,
void * V_223 , const char * V_208 ,
const char * V_232 )
{
struct V_230 V_233 ;
struct V_229 * V_234 ;
char * V_49 = NULL ;
memcpy ( & V_233 , V_231 , sizeof( V_233 ) ) ;
V_233 . V_235 = 0 ;
if ( ! V_208 )
V_208 = V_233 . V_49 ;
if ( V_232 ) {
V_49 = F_158 ( V_37 , L_67 , V_232 , V_208 ) ;
if ( ! V_49 )
return NULL ;
V_233 . V_49 = V_49 ;
} else {
V_233 . V_49 = V_208 ;
}
V_234 = F_159 ( & V_233 , V_223 ) ;
F_16 ( V_49 ) ;
return V_234 ;
}
static int F_160 ( struct V_78 * V_47 , struct V_26 * V_27 ,
const struct V_230 * V_151 , int V_152 ,
const char * V_232 , void * V_223 )
{
int V_74 , V_3 ;
for ( V_3 = 0 ; V_3 < V_152 ; V_3 ++ ) {
const struct V_230 * V_236 = & V_151 [ V_3 ] ;
V_74 = F_161 ( V_47 , F_157 ( V_236 , V_223 ,
V_236 -> V_49 , V_232 ) ) ;
if ( V_74 < 0 ) {
F_50 ( V_27 , L_68 ,
V_236 -> V_49 , V_74 ) ;
return V_74 ;
}
}
return 0 ;
}
int F_86 ( struct V_4 * V_5 ,
const struct V_230 * V_151 , int V_152 )
{
struct V_78 * V_47 = V_5 -> V_47 -> V_78 ;
return F_160 ( V_47 , V_5 -> V_27 , V_151 , V_152 ,
V_5 -> V_142 , V_5 ) ;
}
int F_90 ( struct V_55 * V_56 ,
const struct V_230 * V_151 , int V_152 )
{
struct V_78 * V_47 = V_56 -> V_47 -> V_78 ;
return F_160 ( V_47 , V_56 -> V_27 , V_151 , V_152 ,
NULL , V_56 ) ;
}
int F_124 ( struct V_60 * V_237 ,
const struct V_230 * V_151 , int V_152 )
{
struct V_78 * V_47 = V_237 -> V_78 ;
return F_160 ( V_47 , V_237 -> V_27 , V_151 , V_152 ,
NULL , V_237 ) ;
}
int F_162 ( struct V_58 * V_59 ,
const struct V_230 * V_151 , int V_152 )
{
struct V_78 * V_47 = V_59 -> V_47 -> V_78 ;
return F_160 ( V_47 , V_59 -> V_27 , V_151 , V_152 ,
NULL , V_59 ) ;
}
int F_163 ( struct V_229 * V_234 ,
struct V_238 * V_239 )
{
struct V_240 * V_241 = (struct V_240 * ) V_234 -> V_242 ;
V_239 -> type = V_243 ;
V_239 -> V_18 = V_241 -> V_244 == V_241 -> V_245 ? 1 : 2 ;
V_239 -> V_42 . V_246 . V_247 = V_241 -> V_248 ;
if ( V_239 -> V_42 . V_246 . V_249 > V_241 -> V_248 - 1 )
V_239 -> V_42 . V_246 . V_249 = V_241 -> V_248 - 1 ;
strcpy ( V_239 -> V_42 . V_246 . V_49 ,
V_241 -> V_250 [ V_239 -> V_42 . V_246 . V_249 ] ) ;
return 0 ;
}
int F_164 ( struct V_229 * V_234 ,
struct V_251 * V_252 )
{
struct V_4 * V_5 = F_165 ( V_234 ) ;
struct V_240 * V_241 = (struct V_240 * ) V_234 -> V_242 ;
unsigned int V_1 ;
V_1 = F_4 ( V_5 , V_241 -> V_6 ) ;
V_252 -> V_42 . V_246 . V_249 [ 0 ]
= ( V_1 >> V_241 -> V_244 ) & V_241 -> V_225 ;
if ( V_241 -> V_244 != V_241 -> V_245 )
V_252 -> V_42 . V_246 . V_249 [ 1 ] =
( V_1 >> V_241 -> V_245 ) & V_241 -> V_225 ;
return 0 ;
}
int F_166 ( struct V_229 * V_234 ,
struct V_251 * V_252 )
{
struct V_4 * V_5 = F_165 ( V_234 ) ;
struct V_240 * V_241 = (struct V_240 * ) V_234 -> V_242 ;
unsigned int V_1 ;
unsigned int V_225 ;
if ( V_252 -> V_42 . V_246 . V_249 [ 0 ] > V_241 -> V_248 - 1 )
return - V_17 ;
V_1 = V_252 -> V_42 . V_246 . V_249 [ 0 ] << V_241 -> V_244 ;
V_225 = V_241 -> V_225 << V_241 -> V_244 ;
if ( V_241 -> V_244 != V_241 -> V_245 ) {
if ( V_252 -> V_42 . V_246 . V_249 [ 1 ] > V_241 -> V_248 - 1 )
return - V_17 ;
V_1 |= V_252 -> V_42 . V_246 . V_249 [ 1 ] << V_241 -> V_245 ;
V_225 |= V_241 -> V_225 << V_241 -> V_245 ;
}
return F_155 ( V_5 , V_241 -> V_6 , V_225 , V_1 ) ;
}
int F_167 ( struct V_229 * V_234 ,
struct V_251 * V_252 )
{
struct V_4 * V_5 = F_165 ( V_234 ) ;
struct V_240 * V_241 = (struct V_240 * ) V_234 -> V_242 ;
unsigned int V_253 , V_1 , V_254 ;
V_253 = F_4 ( V_5 , V_241 -> V_6 ) ;
V_1 = ( V_253 >> V_241 -> V_244 ) & V_241 -> V_225 ;
for ( V_254 = 0 ; V_254 < V_241 -> V_248 ; V_254 ++ ) {
if ( V_1 == V_241 -> V_255 [ V_254 ] )
break;
}
V_252 -> V_42 . V_246 . V_249 [ 0 ] = V_254 ;
if ( V_241 -> V_244 != V_241 -> V_245 ) {
V_1 = ( V_253 >> V_241 -> V_245 ) & V_241 -> V_225 ;
for ( V_254 = 0 ; V_254 < V_241 -> V_248 ; V_254 ++ ) {
if ( V_1 == V_241 -> V_255 [ V_254 ] )
break;
}
V_252 -> V_42 . V_246 . V_249 [ 1 ] = V_254 ;
}
return 0 ;
}
int F_168 ( struct V_229 * V_234 ,
struct V_251 * V_252 )
{
struct V_4 * V_5 = F_165 ( V_234 ) ;
struct V_240 * V_241 = (struct V_240 * ) V_234 -> V_242 ;
unsigned int V_1 ;
unsigned int V_225 ;
if ( V_252 -> V_42 . V_246 . V_249 [ 0 ] > V_241 -> V_248 - 1 )
return - V_17 ;
V_1 = V_241 -> V_255 [ V_252 -> V_42 . V_246 . V_249 [ 0 ] ] << V_241 -> V_244 ;
V_225 = V_241 -> V_225 << V_241 -> V_244 ;
if ( V_241 -> V_244 != V_241 -> V_245 ) {
if ( V_252 -> V_42 . V_246 . V_249 [ 1 ] > V_241 -> V_248 - 1 )
return - V_17 ;
V_1 |= V_241 -> V_255 [ V_252 -> V_42 . V_246 . V_249 [ 1 ] ] << V_241 -> V_245 ;
V_225 |= V_241 -> V_225 << V_241 -> V_245 ;
}
return F_155 ( V_5 , V_241 -> V_6 , V_225 , V_1 ) ;
}
int F_169 ( struct V_229 * V_234 ,
struct V_238 * V_239 )
{
struct V_240 * V_241 = (struct V_240 * ) V_234 -> V_242 ;
V_239 -> type = V_243 ;
V_239 -> V_18 = 1 ;
V_239 -> V_42 . V_246 . V_247 = V_241 -> V_248 ;
if ( V_239 -> V_42 . V_246 . V_249 > V_241 -> V_248 - 1 )
V_239 -> V_42 . V_246 . V_249 = V_241 -> V_248 - 1 ;
strcpy ( V_239 -> V_42 . V_246 . V_49 ,
V_241 -> V_250 [ V_239 -> V_42 . V_246 . V_249 ] ) ;
return 0 ;
}
int F_170 ( struct V_229 * V_234 ,
struct V_238 * V_239 )
{
int V_248 = V_234 -> V_242 ;
if ( V_248 == 1 && ! strstr ( V_234 -> V_256 . V_49 , L_69 ) )
V_239 -> type = V_257 ;
else
V_239 -> type = V_258 ;
V_239 -> V_18 = 1 ;
V_239 -> V_42 . integer . F_7 = 0 ;
V_239 -> V_42 . integer . V_248 = V_248 ;
return 0 ;
}
int F_171 ( struct V_229 * V_234 ,
struct V_238 * V_239 )
{
struct V_259 * V_260 =
(struct V_259 * ) V_234 -> V_242 ;
int V_261 ;
if ( ! V_260 -> V_261 )
V_260 -> V_261 = V_260 -> V_248 ;
V_261 = V_260 -> V_261 ;
if ( V_261 == 1 && ! strstr ( V_234 -> V_256 . V_49 , L_69 ) )
V_239 -> type = V_257 ;
else
V_239 -> type = V_258 ;
V_239 -> V_18 = F_172 ( V_260 ) ? 2 : 1 ;
V_239 -> V_42 . integer . F_7 = 0 ;
V_239 -> V_42 . integer . V_248 = V_261 ;
return 0 ;
}
int F_173 ( struct V_229 * V_234 ,
struct V_251 * V_252 )
{
struct V_259 * V_260 =
(struct V_259 * ) V_234 -> V_242 ;
struct V_4 * V_5 = F_165 ( V_234 ) ;
unsigned int V_6 = V_260 -> V_6 ;
unsigned int V_262 = V_260 -> V_263 ;
unsigned int V_264 = V_260 -> V_264 ;
unsigned int V_265 = V_260 -> V_265 ;
int V_248 = V_260 -> V_248 ;
unsigned int V_225 = ( 1 << F_174 ( V_248 ) ) - 1 ;
unsigned int V_266 = V_260 -> V_266 ;
V_252 -> V_42 . integer . V_42 [ 0 ] =
( F_4 ( V_5 , V_6 ) >> V_264 ) & V_225 ;
if ( V_266 )
V_252 -> V_42 . integer . V_42 [ 0 ] =
V_248 - V_252 -> V_42 . integer . V_42 [ 0 ] ;
if ( F_172 ( V_260 ) ) {
if ( V_6 == V_262 )
V_252 -> V_42 . integer . V_42 [ 1 ] =
( F_4 ( V_5 , V_6 ) >> V_265 ) & V_225 ;
else
V_252 -> V_42 . integer . V_42 [ 1 ] =
( F_4 ( V_5 , V_262 ) >> V_264 ) & V_225 ;
if ( V_266 )
V_252 -> V_42 . integer . V_42 [ 1 ] =
V_248 - V_252 -> V_42 . integer . V_42 [ 1 ] ;
}
return 0 ;
}
int F_175 ( struct V_229 * V_234 ,
struct V_251 * V_252 )
{
struct V_259 * V_260 =
(struct V_259 * ) V_234 -> V_242 ;
struct V_4 * V_5 = F_165 ( V_234 ) ;
unsigned int V_6 = V_260 -> V_6 ;
unsigned int V_262 = V_260 -> V_263 ;
unsigned int V_264 = V_260 -> V_264 ;
unsigned int V_265 = V_260 -> V_265 ;
int V_248 = V_260 -> V_248 ;
unsigned int V_225 = ( 1 << F_174 ( V_248 ) ) - 1 ;
unsigned int V_266 = V_260 -> V_266 ;
int V_74 ;
bool V_267 = 0 ;
unsigned int V_268 = 0 ;
unsigned int V_1 , V_269 ;
V_1 = ( V_252 -> V_42 . integer . V_42 [ 0 ] & V_225 ) ;
if ( V_266 )
V_1 = V_248 - V_1 ;
V_269 = V_225 << V_264 ;
V_1 = V_1 << V_264 ;
if ( F_172 ( V_260 ) ) {
V_268 = ( V_252 -> V_42 . integer . V_42 [ 1 ] & V_225 ) ;
if ( V_266 )
V_268 = V_248 - V_268 ;
if ( V_6 == V_262 ) {
V_269 |= V_225 << V_265 ;
V_1 |= V_268 << V_265 ;
} else {
V_268 = V_268 << V_264 ;
V_267 = 1 ;
}
}
V_74 = F_155 ( V_5 , V_6 , V_269 , V_1 ) ;
if ( V_74 < 0 )
return V_74 ;
if ( V_267 )
V_74 = F_155 ( V_5 , V_262 , V_269 , V_268 ) ;
return V_74 ;
}
int F_176 ( struct V_229 * V_234 ,
struct V_251 * V_252 )
{
struct V_4 * V_5 = F_165 ( V_234 ) ;
struct V_259 * V_260 =
(struct V_259 * ) V_234 -> V_242 ;
unsigned int V_6 = V_260 -> V_6 ;
unsigned int V_262 = V_260 -> V_263 ;
unsigned int V_264 = V_260 -> V_264 ;
unsigned int V_265 = V_260 -> V_265 ;
int V_248 = V_260 -> V_248 ;
int F_7 = V_260 -> F_7 ;
int V_225 = ( 1 << ( F_174 ( F_7 + V_248 ) - 1 ) ) - 1 ;
V_252 -> V_42 . integer . V_42 [ 0 ] =
( ( F_4 ( V_5 , V_6 ) >> V_264 ) - F_7 ) & V_225 ;
if ( F_172 ( V_260 ) )
V_252 -> V_42 . integer . V_42 [ 1 ] =
( ( F_4 ( V_5 , V_262 ) >> V_265 ) - F_7 ) & V_225 ;
return 0 ;
}
int F_177 ( struct V_229 * V_234 ,
struct V_251 * V_252 )
{
struct V_4 * V_5 = F_165 ( V_234 ) ;
struct V_259 * V_260 =
(struct V_259 * ) V_234 -> V_242 ;
unsigned int V_6 = V_260 -> V_6 ;
unsigned int V_262 = V_260 -> V_263 ;
unsigned int V_264 = V_260 -> V_264 ;
unsigned int V_265 = V_260 -> V_265 ;
int V_248 = V_260 -> V_248 ;
int F_7 = V_260 -> F_7 ;
int V_225 = ( 1 << ( F_174 ( F_7 + V_248 ) - 1 ) ) - 1 ;
int V_74 = 0 ;
unsigned short V_1 , V_269 , V_268 = 0 ;
V_269 = V_225 << V_264 ;
V_1 = ( V_252 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & V_225 ;
V_1 = V_1 << V_264 ;
V_74 = F_155 ( V_5 , V_6 , V_269 , V_1 ) ;
if ( V_74 < 0 )
return V_74 ;
if ( F_172 ( V_260 ) ) {
V_269 = V_225 << V_265 ;
V_268 = ( V_252 -> V_42 . integer . V_42 [ 1 ] + F_7 ) & V_225 ;
V_268 = V_268 << V_265 ;
if ( F_155 ( V_5 , V_262 , V_269 , V_268 ) )
return V_74 ;
}
return 0 ;
}
int F_178 ( struct V_229 * V_234 ,
struct V_238 * V_239 )
{
struct V_259 * V_260 =
(struct V_259 * ) V_234 -> V_242 ;
int V_261 ;
int F_7 = V_260 -> F_7 ;
if ( ! V_260 -> V_261 )
V_260 -> V_261 = V_260 -> V_248 ;
V_261 = V_260 -> V_261 ;
V_239 -> type = V_258 ;
V_239 -> V_18 = 2 ;
V_239 -> V_42 . integer . F_7 = 0 ;
V_239 -> V_42 . integer . V_248 = V_261 - F_7 ;
return 0 ;
}
int F_179 ( struct V_229 * V_234 ,
struct V_251 * V_252 )
{
struct V_259 * V_260 =
(struct V_259 * ) V_234 -> V_242 ;
struct V_4 * V_5 = F_165 ( V_234 ) ;
unsigned int V_6 = V_260 -> V_6 ;
int F_7 = V_260 -> F_7 ;
int V_1 = F_4 ( V_5 , V_6 ) ;
V_252 -> V_42 . integer . V_42 [ 0 ] =
( ( signed char ) ( V_1 & 0xff ) ) - F_7 ;
V_252 -> V_42 . integer . V_42 [ 1 ] =
( ( signed char ) ( ( V_1 >> 8 ) & 0xff ) ) - F_7 ;
return 0 ;
}
int F_180 ( struct V_229 * V_234 ,
struct V_251 * V_252 )
{
struct V_259 * V_260 =
(struct V_259 * ) V_234 -> V_242 ;
struct V_4 * V_5 = F_165 ( V_234 ) ;
unsigned int V_6 = V_260 -> V_6 ;
int F_7 = V_260 -> F_7 ;
unsigned int V_1 ;
V_1 = ( V_252 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & 0xff ;
V_1 |= ( ( V_252 -> V_42 . integer . V_42 [ 1 ] + F_7 ) & 0xff ) << 8 ;
return F_155 ( V_5 , V_6 , 0xffff , V_1 ) ;
}
int F_181 ( struct V_229 * V_234 ,
struct V_238 * V_239 )
{
struct V_259 * V_260 =
(struct V_259 * ) V_234 -> V_242 ;
int V_261 ;
int F_7 = V_260 -> F_7 ;
if ( ! V_260 -> V_261 )
V_260 -> V_261 = V_260 -> V_248 ;
V_261 = V_260 -> V_261 ;
V_239 -> type = V_258 ;
V_239 -> V_18 = F_172 ( V_260 ) ? 2 : 1 ;
V_239 -> V_42 . integer . F_7 = 0 ;
V_239 -> V_42 . integer . V_248 = V_261 - F_7 ;
return 0 ;
}
int F_182 ( struct V_229 * V_234 ,
struct V_251 * V_252 )
{
struct V_259 * V_260 =
(struct V_259 * ) V_234 -> V_242 ;
struct V_4 * V_5 = F_165 ( V_234 ) ;
unsigned int V_6 = V_260 -> V_6 ;
unsigned int V_263 = V_260 -> V_263 ;
unsigned int V_264 = V_260 -> V_264 ;
int F_7 = V_260 -> F_7 ;
int V_248 = V_260 -> V_248 ;
unsigned int V_225 = ( 1 << F_174 ( V_248 ) ) - 1 ;
unsigned int V_266 = V_260 -> V_266 ;
unsigned int V_1 , V_269 ;
int V_14 ;
V_1 = ( ( V_252 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & V_225 ) ;
if ( V_266 )
V_1 = V_248 - V_1 ;
V_269 = V_225 << V_264 ;
V_1 = V_1 << V_264 ;
V_14 = F_155 ( V_5 , V_6 , V_269 , V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( F_172 ( V_260 ) ) {
V_1 = ( ( V_252 -> V_42 . integer . V_42 [ 1 ] + F_7 ) & V_225 ) ;
if ( V_266 )
V_1 = V_248 - V_1 ;
V_269 = V_225 << V_264 ;
V_1 = V_1 << V_264 ;
V_14 = F_155 ( V_5 , V_263 , V_269 , V_1 ) ;
}
return V_14 ;
}
int F_183 ( struct V_229 * V_234 ,
struct V_251 * V_252 )
{
struct V_259 * V_260 =
(struct V_259 * ) V_234 -> V_242 ;
struct V_4 * V_5 = F_165 ( V_234 ) ;
unsigned int V_6 = V_260 -> V_6 ;
unsigned int V_263 = V_260 -> V_263 ;
unsigned int V_264 = V_260 -> V_264 ;
int F_7 = V_260 -> F_7 ;
int V_248 = V_260 -> V_248 ;
unsigned int V_225 = ( 1 << F_174 ( V_248 ) ) - 1 ;
unsigned int V_266 = V_260 -> V_266 ;
V_252 -> V_42 . integer . V_42 [ 0 ] =
( F_4 ( V_5 , V_6 ) >> V_264 ) & V_225 ;
if ( V_266 )
V_252 -> V_42 . integer . V_42 [ 0 ] =
V_248 - V_252 -> V_42 . integer . V_42 [ 0 ] ;
V_252 -> V_42 . integer . V_42 [ 0 ] =
V_252 -> V_42 . integer . V_42 [ 0 ] - F_7 ;
if ( F_172 ( V_260 ) ) {
V_252 -> V_42 . integer . V_42 [ 1 ] =
( F_4 ( V_5 , V_263 ) >> V_264 ) & V_225 ;
if ( V_266 )
V_252 -> V_42 . integer . V_42 [ 1 ] =
V_248 - V_252 -> V_42 . integer . V_42 [ 1 ] ;
V_252 -> V_42 . integer . V_42 [ 1 ] =
V_252 -> V_42 . integer . V_42 [ 1 ] - F_7 ;
}
return 0 ;
}
int F_184 ( struct V_4 * V_5 ,
const char * V_49 , int V_248 )
{
struct V_78 * V_47 = V_5 -> V_47 -> V_78 ;
struct V_229 * V_270 ;
struct V_259 * V_260 ;
int V_186 = 0 ;
int V_14 = - V_17 ;
if ( F_185 ( ! V_49 || V_248 <= 0 ) )
return - V_17 ;
F_34 (kctl, &card->controls, list) {
if ( ! strncmp ( V_270 -> V_256 . V_49 , V_49 , sizeof( V_270 -> V_256 . V_49 ) ) ) {
V_186 = 1 ;
break;
}
}
if ( V_186 ) {
V_260 = (struct V_259 * ) V_270 -> V_242 ;
if ( V_248 <= V_260 -> V_248 ) {
V_260 -> V_261 = V_248 ;
V_14 = 0 ;
}
}
return V_14 ;
}
int F_186 ( struct V_229 * V_234 ,
struct V_238 * V_239 )
{
struct V_4 * V_5 = F_165 ( V_234 ) ;
struct V_271 * V_179 = ( void * ) V_234 -> V_242 ;
V_239 -> type = V_272 ;
V_239 -> V_18 = V_179 -> V_273 * V_5 -> V_274 ;
return 0 ;
}
int F_187 ( struct V_229 * V_234 ,
struct V_251 * V_252 )
{
struct V_271 * V_179 = ( void * ) V_234 -> V_242 ;
struct V_4 * V_5 = F_165 ( V_234 ) ;
int V_14 ;
if ( V_5 -> V_105 )
V_14 = F_188 ( V_5 -> V_106 , V_179 -> V_275 ,
V_252 -> V_42 . V_276 . V_223 ,
V_179 -> V_273 * V_5 -> V_274 ) ;
else
V_14 = - V_17 ;
if ( V_14 == 0 && V_179 -> V_225 ) {
switch ( V_5 -> V_274 ) {
case 1 :
V_252 -> V_42 . V_276 . V_223 [ 0 ] &= ~ V_179 -> V_225 ;
break;
case 2 :
( ( V_277 * ) ( & V_252 -> V_42 . V_276 . V_223 ) ) [ 0 ]
&= ~ V_179 -> V_225 ;
break;
case 4 :
( ( V_278 * ) ( & V_252 -> V_42 . V_276 . V_223 ) ) [ 0 ]
&= ~ V_179 -> V_225 ;
break;
default:
return - V_17 ;
}
}
return V_14 ;
}
int F_189 ( struct V_229 * V_234 ,
struct V_251 * V_252 )
{
struct V_271 * V_179 = ( void * ) V_234 -> V_242 ;
struct V_4 * V_5 = F_165 ( V_234 ) ;
int V_14 , V_8 ;
unsigned int V_1 ;
void * V_223 ;
if ( ! V_5 -> V_105 )
return - V_17 ;
V_8 = V_179 -> V_273 * V_5 -> V_274 ;
V_223 = F_190 ( V_252 -> V_42 . V_276 . V_223 , V_8 , V_37 | V_279 ) ;
if ( ! V_223 )
return - V_38 ;
if ( V_179 -> V_225 ) {
V_14 = F_191 ( V_5 -> V_106 , V_179 -> V_275 , & V_1 ) ;
if ( V_14 != 0 )
goto V_171;
V_1 &= V_179 -> V_225 ;
switch ( V_5 -> V_274 ) {
case 1 :
( ( V_280 * ) V_223 ) [ 0 ] &= ~ V_179 -> V_225 ;
( ( V_280 * ) V_223 ) [ 0 ] |= V_1 ;
break;
case 2 :
( ( V_277 * ) V_223 ) [ 0 ] &= F_192 ( ~ V_179 -> V_225 ) ;
( ( V_277 * ) V_223 ) [ 0 ] |= F_192 ( V_1 ) ;
break;
case 4 :
( ( V_278 * ) V_223 ) [ 0 ] &= F_193 ( ~ V_179 -> V_225 ) ;
( ( V_278 * ) V_223 ) [ 0 ] |= F_193 ( V_1 ) ;
break;
default:
V_14 = - V_17 ;
goto V_171;
}
}
V_14 = F_194 ( V_5 -> V_106 , V_179 -> V_275 ,
V_223 , V_8 ) ;
V_171:
F_16 ( V_223 ) ;
return V_14 ;
}
int F_195 ( struct V_229 * V_234 ,
struct V_238 * V_239 )
{
struct V_281 * V_260 =
(struct V_281 * ) V_234 -> V_242 ;
V_239 -> type = V_258 ;
V_239 -> V_18 = 1 ;
V_239 -> V_42 . integer . F_7 = V_260 -> F_7 ;
V_239 -> V_42 . integer . V_248 = V_260 -> V_248 ;
return 0 ;
}
int F_196 ( struct V_229 * V_234 ,
struct V_251 * V_252 )
{
struct V_281 * V_260 =
(struct V_281 * ) V_234 -> V_242 ;
struct V_4 * V_5 = F_165 ( V_234 ) ;
unsigned int V_282 = V_260 -> V_282 ;
unsigned int V_283 = V_260 -> V_283 ;
unsigned int V_284 = V_5 -> V_10 -> V_13 * V_285 ;
unsigned int V_286 = ( 1 << V_284 ) - 1 ;
unsigned int V_266 = V_260 -> V_266 ;
unsigned long V_225 = ( 1UL << V_260 -> V_287 ) - 1 ;
long F_7 = V_260 -> F_7 ;
long V_248 = V_260 -> V_248 ;
long V_1 = 0 ;
unsigned long V_288 ;
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_283 ; V_3 ++ ) {
V_288 = F_4 ( V_5 , V_282 + V_3 ) & V_286 ;
V_1 |= V_288 << ( V_284 * ( V_283 - V_3 - 1 ) ) ;
}
V_1 &= V_225 ;
if ( F_7 < 0 && V_1 > V_248 )
V_1 |= ~ V_225 ;
if ( V_266 )
V_1 = V_248 - V_1 ;
V_252 -> V_42 . integer . V_42 [ 0 ] = V_1 ;
return 0 ;
}
int F_197 ( struct V_229 * V_234 ,
struct V_251 * V_252 )
{
struct V_281 * V_260 =
(struct V_281 * ) V_234 -> V_242 ;
struct V_4 * V_5 = F_165 ( V_234 ) ;
unsigned int V_282 = V_260 -> V_282 ;
unsigned int V_283 = V_260 -> V_283 ;
unsigned int V_284 = V_5 -> V_10 -> V_13 * V_285 ;
unsigned int V_286 = ( 1 << V_284 ) - 1 ;
unsigned int V_266 = V_260 -> V_266 ;
unsigned long V_225 = ( 1UL << V_260 -> V_287 ) - 1 ;
long V_248 = V_260 -> V_248 ;
long V_1 = V_252 -> V_42 . integer . V_42 [ 0 ] ;
unsigned int V_3 , V_288 , V_289 ;
int V_74 ;
if ( V_266 )
V_1 = V_248 - V_1 ;
V_1 &= V_225 ;
for ( V_3 = 0 ; V_3 < V_283 ; V_3 ++ ) {
V_288 = ( V_1 >> ( V_284 * ( V_283 - V_3 - 1 ) ) ) & V_286 ;
V_289 = ( V_225 >> ( V_284 * ( V_283 - V_3 - 1 ) ) ) & V_286 ;
V_74 = F_155 ( V_5 , V_282 + V_3 ,
V_289 , V_288 ) ;
if ( V_74 < 0 )
return V_74 ;
}
return 0 ;
}
int F_198 ( struct V_229 * V_234 ,
struct V_251 * V_252 )
{
struct V_259 * V_260 =
(struct V_259 * ) V_234 -> V_242 ;
struct V_4 * V_5 = F_165 ( V_234 ) ;
unsigned int V_6 = V_260 -> V_6 ;
unsigned int V_264 = V_260 -> V_264 ;
unsigned int V_225 = 1 << V_264 ;
unsigned int V_266 = V_260 -> V_266 != 0 ;
unsigned int V_1 = F_4 ( V_5 , V_6 ) & V_225 ;
if ( V_264 != 0 && V_1 != 0 )
V_1 = V_1 >> V_264 ;
V_252 -> V_42 . V_246 . V_249 [ 0 ] = V_1 ^ V_266 ;
return 0 ;
}
int F_199 ( struct V_229 * V_234 ,
struct V_251 * V_252 )
{
struct V_259 * V_260 =
(struct V_259 * ) V_234 -> V_242 ;
struct V_4 * V_5 = F_165 ( V_234 ) ;
unsigned int V_6 = V_260 -> V_6 ;
unsigned int V_264 = V_260 -> V_264 ;
unsigned int V_225 = 1 << V_264 ;
unsigned int V_266 = V_260 -> V_266 != 0 ;
unsigned int V_290 = V_252 -> V_42 . V_246 . V_249 [ 0 ] != 0 ;
unsigned int V_291 = ( V_290 ^ V_266 ) ? V_225 : 0 ;
unsigned int V_268 = ( V_290 ^ V_266 ) ? 0 : V_225 ;
int V_74 ;
V_74 = F_155 ( V_5 , V_6 , V_225 , V_291 ) ;
if ( V_74 < 0 )
return V_74 ;
V_74 = F_155 ( V_5 , V_6 , V_225 , V_268 ) ;
return V_74 ;
}
int F_200 ( struct V_58 * V_59 , int V_292 ,
unsigned int V_293 , int V_294 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_88 -> V_295 )
return V_59 -> V_10 -> V_88 -> V_295 ( V_59 , V_292 , V_293 , V_294 ) ;
else if ( V_59 -> V_5 && V_59 -> V_5 -> V_10 -> V_295 )
return V_59 -> V_5 -> V_10 -> V_295 ( V_59 -> V_5 , V_292 , 0 ,
V_293 , V_294 ) ;
else
return - V_17 ;
}
int F_201 ( struct V_4 * V_5 , int V_292 ,
int V_296 , unsigned int V_293 , int V_294 )
{
if ( V_5 -> V_10 -> V_295 )
return V_5 -> V_10 -> V_295 ( V_5 , V_292 , V_296 ,
V_293 , V_294 ) ;
else
return - V_17 ;
}
int F_202 ( struct V_58 * V_59 ,
int V_297 , int div )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_88 -> V_298 )
return V_59 -> V_10 -> V_88 -> V_298 ( V_59 , V_297 , div ) ;
else
return - V_17 ;
}
int F_203 ( struct V_58 * V_59 , int V_299 , int V_296 ,
unsigned int V_300 , unsigned int V_301 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_88 -> V_302 )
return V_59 -> V_10 -> V_88 -> V_302 ( V_59 , V_299 , V_296 ,
V_300 , V_301 ) ;
else if ( V_59 -> V_5 && V_59 -> V_5 -> V_10 -> V_302 )
return V_59 -> V_5 -> V_10 -> V_302 ( V_59 -> V_5 , V_299 , V_296 ,
V_300 , V_301 ) ;
else
return - V_17 ;
}
int F_204 ( struct V_4 * V_5 , int V_299 , int V_296 ,
unsigned int V_300 , unsigned int V_301 )
{
if ( V_5 -> V_10 -> V_302 )
return V_5 -> V_10 -> V_302 ( V_5 , V_299 , V_296 ,
V_300 , V_301 ) ;
else
return - V_17 ;
}
int F_125 ( struct V_58 * V_59 , unsigned int V_303 )
{
if ( V_59 -> V_10 == NULL )
return - V_17 ;
if ( V_59 -> V_10 -> V_88 -> V_304 == NULL )
return - V_200 ;
return V_59 -> V_10 -> V_88 -> V_304 ( V_59 , V_303 ) ;
}
int F_205 ( struct V_58 * V_59 ,
unsigned int V_305 , unsigned int V_306 , int V_307 , int V_308 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_88 -> V_309 )
return V_59 -> V_10 -> V_88 -> V_309 ( V_59 , V_305 , V_306 ,
V_307 , V_308 ) ;
else
return - V_17 ;
}
int F_206 ( struct V_58 * V_59 ,
unsigned int V_310 , unsigned int * V_311 ,
unsigned int V_312 , unsigned int * V_313 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_88 -> V_314 )
return V_59 -> V_10 -> V_88 -> V_314 ( V_59 , V_310 , V_311 ,
V_312 , V_313 ) ;
else
return - V_17 ;
}
int F_207 ( struct V_58 * V_59 , int V_315 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_88 -> V_316 )
return V_59 -> V_10 -> V_88 -> V_316 ( V_59 , V_315 ) ;
else
return - V_17 ;
}
int F_208 ( struct V_58 * V_59 , int V_317 ,
int V_318 )
{
if ( ! V_59 -> V_10 )
return - V_200 ;
if ( V_59 -> V_10 -> V_88 -> V_319 )
return V_59 -> V_10 -> V_88 -> V_319 ( V_59 , V_317 , V_318 ) ;
else if ( V_318 == V_99 &&
V_59 -> V_10 -> V_88 -> V_89 )
return V_59 -> V_10 -> V_88 -> V_89 ( V_59 , V_317 ) ;
else
return - V_200 ;
}
int F_134 ( struct V_60 * V_47 )
{
int V_3 , V_14 ;
if ( ! V_47 -> V_49 || ! V_47 -> V_27 )
return - V_17 ;
for ( V_3 = 0 ; V_3 < V_47 -> V_67 ; V_3 ++ ) {
struct V_117 * V_320 = & V_47 -> V_65 [ V_3 ] ;
if ( ! ! V_320 -> V_125 == ! ! V_320 -> V_124 ) {
F_50 ( V_47 -> V_27 ,
L_70 ,
V_320 -> V_49 ) ;
return - V_17 ;
}
if ( ! V_320 -> V_126 ) {
F_50 ( V_47 -> V_27 ,
L_71 ,
V_320 -> V_49 ) ;
return - V_17 ;
}
if ( V_320 -> V_118 && V_320 -> V_127 ) {
F_50 ( V_47 -> V_27 ,
L_72 ,
V_320 -> V_49 ) ;
return - V_17 ;
}
if ( V_320 -> V_121 && V_320 -> V_119 ) {
F_50 ( V_47 -> V_27 ,
L_73 ,
V_320 -> V_49 ) ;
return - V_17 ;
}
if ( ! V_320 -> V_122 &&
! ( V_320 -> V_121 || V_320 -> V_119 ) ) {
F_50 ( V_47 -> V_27 ,
L_74 ,
V_320 -> V_49 ) ;
return - V_17 ;
}
}
F_96 ( V_47 -> V_27 , V_47 ) ;
F_209 ( V_47 ) ;
F_38 ( V_47 ) ;
V_47 -> V_31 = F_210 ( V_47 -> V_27 ,
sizeof( struct V_30 ) *
( V_47 -> V_67 + V_47 -> V_194 ) ,
V_37 ) ;
if ( V_47 -> V_31 == NULL )
return - V_38 ;
V_47 -> V_83 = 0 ;
V_47 -> V_163 = & V_47 -> V_31 [ V_47 -> V_67 ] ;
for ( V_3 = 0 ; V_3 < V_47 -> V_67 ; V_3 ++ )
V_47 -> V_31 [ V_3 ] . V_65 = & V_47 -> V_65 [ V_3 ] ;
F_98 ( & V_47 -> V_155 ) ;
F_98 ( & V_47 -> V_321 ) ;
V_47 -> V_212 = 0 ;
F_97 ( & V_47 -> V_191 ) ;
F_97 ( & V_47 -> V_322 ) ;
V_14 = F_118 ( V_47 ) ;
if ( V_14 != 0 )
F_40 ( V_47 ) ;
return V_14 ;
}
int F_137 ( struct V_60 * V_47 )
{
if ( V_47 -> V_212 )
F_135 ( V_47 ) ;
F_42 ( V_47 -> V_27 , L_75 , V_47 -> V_49 ) ;
return 0 ;
}
static char * F_211 ( struct V_26 * V_27 , int * V_256 )
{
char * V_186 , V_49 [ V_323 ] ;
int V_324 , V_325 ;
if ( F_68 ( V_27 ) == NULL )
return NULL ;
F_212 ( V_49 , F_68 ( V_27 ) , V_323 ) ;
V_186 = strstr ( V_49 , V_27 -> V_10 -> V_49 ) ;
if ( V_186 ) {
if ( sscanf ( & V_186 [ strlen ( V_27 -> V_10 -> V_49 ) ] , L_76 , V_256 ) == 1 ) {
if ( * V_256 == - 1 )
V_186 [ strlen ( V_27 -> V_10 -> V_49 ) ] = '\0' ;
}
} else {
if ( sscanf ( V_49 , L_77 , & V_324 , & V_325 ) == 2 ) {
char V_326 [ V_323 ] ;
* V_256 = ( ( V_324 & 0xffff ) << 16 ) + V_325 ;
snprintf ( V_326 , V_323 , L_78 , V_27 -> V_10 -> V_49 , V_49 ) ;
F_212 ( V_49 , V_326 , V_323 ) ;
} else
* V_256 = 0 ;
}
return F_213 ( V_49 , V_37 ) ;
}
static inline char * F_214 ( struct V_26 * V_27 ,
struct V_85 * V_327 )
{
if ( V_327 -> V_49 == NULL ) {
F_50 ( V_27 ,
L_79 ,
F_68 ( V_27 ) ) ;
return NULL ;
}
return F_213 ( V_327 -> V_49 , V_37 ) ;
}
static int F_215 ( struct V_26 * V_27 ,
struct V_85 * V_327 )
{
struct V_4 * V_5 ;
struct V_58 * V_59 ;
F_42 ( V_27 , L_80 , F_68 ( V_27 ) ) ;
V_59 = F_94 ( sizeof( struct V_58 ) , V_37 ) ;
if ( V_59 == NULL )
return - V_38 ;
V_59 -> V_49 = F_211 ( V_27 , & V_59 -> V_256 ) ;
if ( V_59 -> V_49 == NULL ) {
F_16 ( V_59 ) ;
return - V_38 ;
}
V_59 -> V_27 = V_27 ;
V_59 -> V_10 = V_327 ;
V_59 -> V_54 . V_27 = V_27 ;
if ( ! V_59 -> V_10 -> V_88 )
V_59 -> V_10 -> V_88 = & V_328 ;
F_147 ( & V_329 ) ;
F_34 (codec, &codec_list, list) {
if ( V_5 -> V_27 == V_27 ) {
F_42 ( V_27 , L_81 ,
V_59 -> V_49 , V_5 -> V_49 ) ;
V_59 -> V_5 = V_5 ;
break;
}
}
if ( ! V_59 -> V_5 )
V_59 -> V_54 . V_103 = 1 ;
F_88 ( & V_59 -> V_155 , & V_330 ) ;
F_130 ( & V_329 ) ;
F_42 ( V_27 , L_82 , V_59 -> V_49 ) ;
return 0 ;
}
static void F_216 ( struct V_26 * V_27 )
{
struct V_58 * V_59 ;
F_34 (dai, &dai_list, list) {
if ( V_27 == V_59 -> V_27 )
goto V_186;
}
return;
V_186:
F_147 ( & V_329 ) ;
F_71 ( & V_59 -> V_155 ) ;
F_130 ( & V_329 ) ;
F_42 ( V_27 , L_83 , V_59 -> V_49 ) ;
F_16 ( V_59 -> V_49 ) ;
F_16 ( V_59 ) ;
}
static int F_217 ( struct V_26 * V_27 ,
struct V_85 * V_327 , T_1 V_18 )
{
struct V_4 * V_5 ;
struct V_58 * V_59 ;
int V_3 , V_14 = 0 ;
F_42 ( V_27 , L_84 , F_68 ( V_27 ) , V_18 ) ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ ) {
V_59 = F_94 ( sizeof( struct V_58 ) , V_37 ) ;
if ( V_59 == NULL ) {
V_14 = - V_38 ;
goto V_74;
}
V_59 -> V_49 = F_214 ( V_27 , & V_327 [ V_3 ] ) ;
if ( V_59 -> V_49 == NULL ) {
F_16 ( V_59 ) ;
V_14 = - V_17 ;
goto V_74;
}
V_59 -> V_27 = V_27 ;
V_59 -> V_10 = & V_327 [ V_3 ] ;
if ( V_59 -> V_10 -> V_256 )
V_59 -> V_256 = V_59 -> V_10 -> V_256 ;
else
V_59 -> V_256 = V_3 ;
V_59 -> V_54 . V_27 = V_27 ;
if ( ! V_59 -> V_10 -> V_88 )
V_59 -> V_10 -> V_88 = & V_328 ;
F_147 ( & V_329 ) ;
F_34 (codec, &codec_list, list) {
if ( V_5 -> V_27 == V_27 ) {
F_42 ( V_27 ,
L_81 ,
V_59 -> V_49 , V_5 -> V_49 ) ;
V_59 -> V_5 = V_5 ;
break;
}
}
if ( ! V_59 -> V_5 )
V_59 -> V_54 . V_103 = 1 ;
F_88 ( & V_59 -> V_155 , & V_330 ) ;
F_130 ( & V_329 ) ;
F_42 ( V_59 -> V_27 , L_82 , V_59 -> V_49 ) ;
}
return 0 ;
V_74:
for ( V_3 -- ; V_3 >= 0 ; V_3 -- )
F_216 ( V_27 ) ;
return V_14 ;
}
static void F_218 ( struct V_26 * V_27 , T_1 V_18 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ )
F_216 ( V_27 ) ;
}
int F_219 ( struct V_26 * V_27 , struct V_55 * V_56 ,
const struct V_157 * V_331 )
{
V_56 -> V_49 = F_211 ( V_27 , & V_56 -> V_256 ) ;
if ( V_56 -> V_49 == NULL )
return - V_38 ;
V_56 -> V_27 = V_27 ;
V_56 -> V_10 = V_331 ;
V_56 -> V_54 . V_27 = V_27 ;
V_56 -> V_54 . V_56 = V_56 ;
V_56 -> V_54 . V_332 = V_331 -> V_332 ;
F_97 ( & V_56 -> V_191 ) ;
F_147 ( & V_329 ) ;
F_88 ( & V_56 -> V_155 , & V_333 ) ;
F_130 ( & V_329 ) ;
F_42 ( V_27 , L_85 , V_56 -> V_49 ) ;
return 0 ;
}
int F_220 ( struct V_26 * V_27 ,
const struct V_157 * V_331 )
{
struct V_55 * V_56 ;
int V_14 ;
F_42 ( V_27 , L_86 , F_68 ( V_27 ) ) ;
V_56 = F_94 ( sizeof( struct V_55 ) , V_37 ) ;
if ( V_56 == NULL )
return - V_38 ;
V_14 = F_219 ( V_27 , V_56 , V_331 ) ;
if ( V_14 )
F_16 ( V_56 ) ;
return V_14 ;
}
void F_221 ( struct V_55 * V_56 )
{
F_147 ( & V_329 ) ;
F_71 ( & V_56 -> V_155 ) ;
F_130 ( & V_329 ) ;
F_42 ( V_56 -> V_27 , L_87 ,
V_56 -> V_49 ) ;
F_16 ( V_56 -> V_49 ) ;
}
struct V_55 * F_222 ( struct V_26 * V_27 )
{
struct V_55 * V_56 ;
F_34 (platform, &platform_list, list) {
if ( V_27 == V_56 -> V_27 )
return V_56 ;
}
return NULL ;
}
void F_223 ( struct V_26 * V_27 )
{
struct V_55 * V_56 ;
V_56 = F_222 ( V_27 ) ;
if ( ! V_56 )
return;
F_221 ( V_56 ) ;
F_16 ( V_56 ) ;
}
static void F_224 ( struct V_334 * V_66 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_126 ( V_335 ) ; V_3 ++ )
if ( V_66 -> V_336 & V_335 [ V_3 ] )
V_66 -> V_336 |= V_335 [ V_3 ] ;
}
int F_225 ( struct V_26 * V_27 ,
const struct V_143 * V_337 ,
struct V_85 * V_327 ,
int V_338 )
{
T_1 V_339 ;
struct V_4 * V_5 ;
int V_14 , V_3 ;
F_42 ( V_27 , L_88 , F_68 ( V_27 ) ) ;
V_5 = F_94 ( sizeof( struct V_4 ) , V_37 ) ;
if ( V_5 == NULL )
return - V_38 ;
V_5 -> V_49 = F_211 ( V_27 , & V_5 -> V_256 ) ;
if ( V_5 -> V_49 == NULL ) {
V_14 = - V_38 ;
goto V_340;
}
if ( V_337 -> V_188 )
V_5 -> V_188 = V_337 -> V_188 ;
else
V_5 -> V_188 = V_341 ;
V_5 -> V_149 = V_337 -> V_149 ;
V_5 -> V_218 = V_337 -> V_218 ;
V_5 -> V_215 = V_337 -> V_215 ;
V_5 -> V_216 = V_337 -> V_216 ;
V_5 -> V_217 = V_337 -> V_217 ;
V_5 -> V_342 = V_337 -> V_342 ;
V_5 -> V_54 . V_98 = V_104 ;
V_5 -> V_54 . V_27 = V_27 ;
V_5 -> V_54 . V_5 = V_5 ;
V_5 -> V_54 . V_343 = V_337 -> V_343 ;
V_5 -> V_54 . V_332 = V_337 -> V_332 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_10 = V_337 ;
V_5 -> V_338 = V_338 ;
F_97 ( & V_5 -> V_191 ) ;
if ( V_337 -> V_11 && V_337 -> V_13 ) {
V_339 = V_337 -> V_11 * V_337 -> V_13 ;
V_5 -> V_339 = V_339 ;
if ( V_337 -> V_344 ) {
V_5 -> V_345 = F_190 ( V_337 -> V_344 ,
V_339 , V_37 ) ;
if ( ! V_5 -> V_345 ) {
V_14 = - V_38 ;
goto V_346;
}
}
}
if ( V_337 -> V_347 && V_337 -> V_348 ) {
if ( ! V_5 -> V_215 )
V_5 -> V_215 = V_349 ;
if ( ! V_5 -> V_216 )
V_5 -> V_216 = V_350 ;
if ( ! V_5 -> V_217 )
V_5 -> V_217 = V_351 ;
}
for ( V_3 = 0 ; V_3 < V_338 ; V_3 ++ ) {
F_224 ( & V_327 [ V_3 ] . V_352 ) ;
F_224 ( & V_327 [ V_3 ] . V_353 ) ;
}
F_147 ( & V_329 ) ;
F_88 ( & V_5 -> V_155 , & V_354 ) ;
F_130 ( & V_329 ) ;
V_14 = F_217 ( V_27 , V_327 , V_338 ) ;
if ( V_14 < 0 ) {
F_50 ( V_5 -> V_27 , L_89 , V_14 ) ;
goto V_346;
}
F_42 ( V_5 -> V_27 , L_90 , V_5 -> V_49 ) ;
return 0 ;
V_346:
F_147 ( & V_329 ) ;
F_71 ( & V_5 -> V_155 ) ;
F_130 ( & V_329 ) ;
F_16 ( V_5 -> V_49 ) ;
V_340:
F_16 ( V_5 ) ;
return V_14 ;
}
void F_226 ( struct V_26 * V_27 )
{
struct V_4 * V_5 ;
F_34 (codec, &codec_list, list) {
if ( V_27 == V_5 -> V_27 )
goto V_186;
}
return;
V_186:
F_218 ( V_27 , V_5 -> V_338 ) ;
F_147 ( & V_329 ) ;
F_71 ( & V_5 -> V_155 ) ;
F_130 ( & V_329 ) ;
F_42 ( V_5 -> V_27 , L_91 , V_5 -> V_49 ) ;
F_227 ( V_5 ) ;
F_16 ( V_5 -> V_345 ) ;
F_16 ( V_5 -> V_49 ) ;
F_16 ( V_5 ) ;
}
int F_228 ( struct V_26 * V_27 ,
const struct V_355 * V_356 ,
struct V_85 * V_327 ,
int V_338 )
{
struct V_357 * V_358 ;
int V_14 ;
F_42 ( V_27 , L_92 , F_68 ( V_27 ) ) ;
V_358 = F_210 ( V_27 , sizeof( * V_358 ) , V_37 ) ;
if ( ! V_358 ) {
F_50 ( V_27 , L_93 ) ;
return - V_38 ;
}
V_358 -> V_49 = F_211 ( V_27 , & V_358 -> V_256 ) ;
if ( ! V_358 -> V_49 ) {
F_50 ( V_27 , L_94 ) ;
return - V_38 ;
}
V_358 -> V_27 = V_27 ;
V_358 -> V_10 = V_356 ;
V_358 -> V_338 = V_338 ;
if ( 1 == V_338 )
V_14 = F_215 ( V_27 , V_327 ) ;
else
V_14 = F_217 ( V_27 , V_327 , V_338 ) ;
if ( V_14 < 0 ) {
F_50 ( V_27 , L_89 , V_14 ) ;
goto V_359;
}
F_147 ( & V_329 ) ;
F_88 ( & V_358 -> V_155 , & V_360 ) ;
F_130 ( & V_329 ) ;
F_42 ( V_358 -> V_27 , L_95 , V_358 -> V_49 ) ;
return V_14 ;
V_359:
F_16 ( V_358 -> V_49 ) ;
return V_14 ;
}
void F_229 ( struct V_26 * V_27 )
{
struct V_357 * V_358 ;
F_34 (cmpnt, &component_list, list) {
if ( V_27 == V_358 -> V_27 )
goto V_186;
}
return;
V_186:
F_218 ( V_27 , V_358 -> V_338 ) ;
F_147 ( & V_329 ) ;
F_71 ( & V_358 -> V_155 ) ;
F_130 ( & V_329 ) ;
F_42 ( V_27 , L_96 , V_358 -> V_49 ) ;
F_16 ( V_358 -> V_49 ) ;
}
int F_230 ( struct V_60 * V_47 ,
const char * V_361 )
{
struct V_362 * V_363 = V_47 -> V_27 -> V_120 ;
int V_14 ;
V_14 = F_231 ( V_363 , V_361 , 0 , & V_47 -> V_49 ) ;
if ( V_14 < 0 && V_14 != - V_17 ) {
F_50 ( V_47 -> V_27 ,
L_97 ,
V_361 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
int F_232 ( struct V_60 * V_47 ,
const char * V_361 )
{
struct V_362 * V_363 = V_47 -> V_27 -> V_120 ;
int V_364 ;
struct V_365 * V_366 ;
int V_3 , V_14 ;
V_364 = F_233 ( V_363 , V_361 ) ;
if ( V_364 < 0 || V_364 & 1 ) {
F_50 ( V_47 -> V_27 ,
L_98 ,
V_361 ) ;
return - V_17 ;
}
V_364 /= 2 ;
if ( ! V_364 ) {
F_50 ( V_47 -> V_27 , L_99 ,
V_361 ) ;
return - V_17 ;
}
V_366 = F_210 ( V_47 -> V_27 , V_364 * sizeof( * V_366 ) ,
V_37 ) ;
if ( ! V_366 ) {
F_50 ( V_47 -> V_27 ,
L_100 ) ;
return - V_17 ;
}
for ( V_3 = 0 ; V_3 < V_364 ; V_3 ++ ) {
V_14 = F_231 ( V_363 , V_361 ,
2 * V_3 , & V_366 [ V_3 ] . V_367 ) ;
if ( V_14 ) {
F_50 ( V_47 -> V_27 ,
L_101 ,
V_361 , 2 * V_3 , V_14 ) ;
return - V_17 ;
}
V_14 = F_231 ( V_363 , V_361 ,
( 2 * V_3 ) + 1 , & V_366 [ V_3 ] . V_296 ) ;
if ( V_14 ) {
F_50 ( V_47 -> V_27 ,
L_101 ,
V_361 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_17 ;
}
}
V_47 -> V_154 = V_364 ;
V_47 -> V_153 = V_366 ;
return 0 ;
}
unsigned int F_234 ( struct V_362 * V_363 ,
const char * V_232 )
{
int V_14 , V_3 ;
char V_368 [ 128 ] ;
unsigned int V_369 = 0 ;
int V_370 , V_371 ;
const char * V_372 ;
struct {
char * V_49 ;
unsigned int V_1 ;
} V_373 [] = {
{ L_102 , V_374 } ,
{ L_103 , V_375 } ,
{ L_104 , V_376 } ,
{ L_105 , V_377 } ,
{ L_106 , V_378 } ,
{ L_107 , V_379 } ,
{ L_108 , V_380 } ,
{ L_109 , V_381 } ,
{ L_110 , V_382 } ,
} ;
if ( ! V_232 )
V_232 = L_111 ;
snprintf ( V_368 , sizeof( V_368 ) , L_112 , V_232 ) ;
V_14 = F_235 ( V_363 , V_368 , & V_372 ) ;
if ( V_14 == 0 ) {
for ( V_3 = 0 ; V_3 < F_126 ( V_373 ) ; V_3 ++ ) {
if ( strcmp ( V_372 , V_373 [ V_3 ] . V_49 ) == 0 ) {
V_369 |= V_373 [ V_3 ] . V_1 ;
break;
}
}
}
snprintf ( V_368 , sizeof( V_368 ) , L_113 , V_232 ) ;
if ( F_236 ( V_363 , V_368 , NULL ) )
V_369 |= V_383 ;
else
V_369 |= V_384 ;
snprintf ( V_368 , sizeof( V_368 ) , L_114 , V_232 ) ;
V_370 = ! ! F_236 ( V_363 , V_368 , NULL ) ;
snprintf ( V_368 , sizeof( V_368 ) , L_115 , V_232 ) ;
V_371 = ! ! F_236 ( V_363 , V_368 , NULL ) ;
switch ( ( V_370 << 4 ) + V_371 ) {
case 0x11 :
V_369 |= V_385 ;
break;
case 0x10 :
V_369 |= V_386 ;
break;
case 0x01 :
V_369 |= V_387 ;
break;
default:
break;
}
snprintf ( V_368 , sizeof( V_368 ) , L_116 , V_232 ) ;
V_370 = ! ! F_236 ( V_363 , V_368 , NULL ) ;
snprintf ( V_368 , sizeof( V_368 ) , L_117 , V_232 ) ;
V_371 = ! ! F_236 ( V_363 , V_368 , NULL ) ;
switch ( ( V_370 << 4 ) + V_371 ) {
case 0x11 :
V_369 |= V_202 ;
break;
case 0x10 :
V_369 |= V_204 ;
break;
case 0x01 :
V_369 |= V_205 ;
break;
default:
V_369 |= V_203 ;
break;
}
return V_369 ;
}
static int T_5 F_237 ( void )
{
#ifdef F_103
V_61 = F_24 ( L_118 , NULL ) ;
if ( F_238 ( V_61 ) || ! V_61 ) {
F_239 ( L_119 ) ;
V_61 = NULL ;
}
if ( ! F_27 ( L_120 , 0444 , V_61 , NULL ,
& V_388 ) )
F_239 ( L_121 ) ;
if ( ! F_27 ( L_122 , 0444 , V_61 , NULL ,
& V_389 ) )
F_239 ( L_123 ) ;
if ( ! F_27 ( L_124 , 0444 , V_61 , NULL ,
& V_390 ) )
F_239 ( L_125 ) ;
#endif
F_240 () ;
return F_241 ( & V_391 ) ;
}
static void T_6 F_242 ( void )
{
F_243 () ;
#ifdef F_103
F_30 ( V_61 ) ;
#endif
F_244 ( & V_391 ) ;
}
