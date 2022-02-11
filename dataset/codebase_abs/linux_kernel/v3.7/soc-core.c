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
F_21 ( V_43 ) ;
F_22 ( V_5 , V_6 , V_42 ) ;
return V_40 ;
}
static void F_23 ( struct V_4 * V_5 )
{
struct V_44 * V_45 = V_5 -> V_46 -> V_45 ;
V_5 -> V_47 = F_24 ( V_5 -> V_48 ,
V_45 ) ;
if ( ! V_5 -> V_47 ) {
F_25 ( V_5 -> V_27 , L_4 ) ;
return;
}
F_26 ( L_5 , 0444 , V_5 -> V_47 ,
& V_5 -> V_49 ) ;
F_26 ( L_6 , 0444 , V_5 -> V_47 ,
& V_5 -> V_50 ) ;
V_5 -> V_51 = F_27 ( L_7 , 0644 ,
V_5 -> V_47 ,
V_5 , & V_52 ) ;
if ( ! V_5 -> V_51 )
F_25 ( V_5 -> V_27 , L_8 ) ;
F_28 ( & V_5 -> V_53 , V_5 -> V_47 ) ;
}
static void F_29 ( struct V_4 * V_5 )
{
F_30 ( V_5 -> V_47 ) ;
}
static void F_31 ( struct V_54 * V_55 )
{
struct V_44 * V_45 = V_55 -> V_46 -> V_45 ;
V_55 -> V_56 = F_24 ( V_55 -> V_48 ,
V_45 ) ;
if ( ! V_55 -> V_56 ) {
F_25 ( V_55 -> V_27 ,
L_9 ) ;
return;
}
F_28 ( & V_55 -> V_53 ,
V_55 -> V_56 ) ;
}
static void F_32 ( struct V_54 * V_55 )
{
F_30 ( V_55 -> V_56 ) ;
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
V_5 -> V_48 ) ;
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
struct V_57 * V_58 ;
if ( ! V_7 )
return - V_38 ;
F_34 (dai, &dai_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_25 - V_14 , L_10 , V_58 -> V_48 ) ;
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
struct V_54 * V_55 ;
if ( ! V_7 )
return - V_38 ;
F_34 (platform, &platform_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_25 - V_14 , L_10 ,
V_55 -> V_48 ) ;
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
static void F_38 ( struct V_59 * V_46 )
{
V_46 -> V_45 = F_24 ( V_46 -> V_48 ,
V_60 ) ;
if ( ! V_46 -> V_45 ) {
F_25 ( V_46 -> V_27 ,
L_11 ) ;
return;
}
V_46 -> V_61 = F_39 ( L_12 , 0644 ,
V_46 -> V_45 ,
& V_46 -> V_62 ) ;
if ( ! V_46 -> V_61 )
F_25 ( V_46 -> V_27 ,
L_13 ) ;
}
static void F_40 ( struct V_59 * V_46 )
{
F_30 ( V_46 -> V_45 ) ;
}
static inline void F_23 ( struct V_4 * V_5 )
{
}
static inline void F_29 ( struct V_4 * V_5 )
{
}
static inline void F_31 ( struct V_54 * V_55 )
{
}
static inline void F_32 ( struct V_54 * V_55 )
{
}
static inline void F_38 ( struct V_59 * V_46 )
{
}
static inline void F_40 ( struct V_59 * V_46 )
{
}
struct V_63 * F_41 ( struct V_59 * V_46 ,
const char * V_64 , int V_65 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ ) {
if ( V_46 -> V_31 [ V_3 ] . V_64 -> V_67 &&
! strcmp ( V_46 -> V_31 [ V_3 ] . V_64 -> V_48 , V_64 ) )
return V_46 -> V_31 [ V_3 ] . V_68 -> V_69 [ V_65 ] . V_70 ;
}
F_42 ( V_46 -> V_27 , L_14 , V_64 ) ;
return NULL ;
}
struct V_30 * F_43 ( struct V_59 * V_46 ,
const char * V_64 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ ) {
if ( ! strcmp ( V_46 -> V_31 [ V_3 ] . V_64 -> V_48 , V_64 ) )
return & V_46 -> V_31 [ V_3 ] ;
}
F_42 ( V_46 -> V_27 , L_15 , V_64 ) ;
return NULL ;
}
static int F_44 ( struct V_4 * V_5 )
{
if ( V_5 -> V_71 -> V_27 . V_72 )
F_45 ( & V_5 -> V_71 -> V_27 ) ;
return 0 ;
}
static void F_46 ( struct V_26 * V_27 ) {}
static int F_47 ( struct V_4 * V_5 )
{
int V_73 ;
V_5 -> V_71 -> V_27 . V_72 = & V_74 ;
V_5 -> V_71 -> V_27 . V_75 = V_5 -> V_46 -> V_27 ;
V_5 -> V_71 -> V_27 . V_76 = F_46 ;
F_48 ( & V_5 -> V_71 -> V_27 , L_16 ,
V_5 -> V_46 -> V_77 -> V_78 , 0 , V_5 -> V_48 ) ;
V_73 = F_49 ( & V_5 -> V_71 -> V_27 ) ;
if ( V_73 < 0 ) {
F_50 ( V_79 L_17 ) ;
V_5 -> V_71 -> V_27 . V_72 = NULL ;
return V_73 ;
}
return 0 ;
}
int F_51 ( struct V_26 * V_27 )
{
struct V_59 * V_46 = F_9 ( V_27 ) ;
struct V_4 * V_5 ;
int V_3 ;
if ( F_52 ( & V_46 -> V_80 ) )
return 0 ;
F_53 ( V_46 -> V_77 ) ;
F_54 ( V_46 -> V_77 , V_81 ) ;
F_55 ( V_46 -> V_77 ) ;
F_56 ( V_46 -> V_77 , V_82 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_83 ; V_3 ++ ) {
struct V_57 * V_58 = V_46 -> V_31 [ V_3 ] . V_84 ;
struct V_85 * V_86 = V_58 -> V_10 ;
if ( V_46 -> V_31 [ V_3 ] . V_64 -> V_87 )
continue;
if ( V_86 -> V_88 -> V_89 && V_58 -> V_90 )
V_86 -> V_88 -> V_89 ( V_58 , 1 ) ;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_83 ; V_3 ++ ) {
if ( V_46 -> V_31 [ V_3 ] . V_64 -> V_87 )
continue;
F_57 ( V_46 -> V_31 [ V_3 ] . V_68 ) ;
}
if ( V_46 -> V_91 )
V_46 -> V_91 ( V_46 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_83 ; V_3 ++ ) {
struct V_57 * V_92 = V_46 -> V_31 [ V_3 ] . V_92 ;
struct V_54 * V_55 = V_46 -> V_31 [ V_3 ] . V_55 ;
if ( V_46 -> V_31 [ V_3 ] . V_64 -> V_87 )
continue;
if ( V_92 -> V_10 -> V_93 && ! V_92 -> V_10 -> V_94 )
V_92 -> V_10 -> V_93 ( V_92 ) ;
if ( V_55 -> V_10 -> V_93 && ! V_55 -> V_95 ) {
V_55 -> V_10 -> V_93 ( V_92 ) ;
V_55 -> V_95 = 1 ;
}
}
for ( V_3 = 0 ; V_3 < V_46 -> V_83 ; V_3 ++ ) {
F_58 ( & V_46 -> V_31 [ V_3 ] . V_96 ) ;
V_46 -> V_31 [ V_3 ] . V_5 -> V_53 . V_97 = V_46 -> V_31 [ V_3 ] . V_5 -> V_53 . V_98 ;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_83 ; V_3 ++ ) {
if ( V_46 -> V_31 [ V_3 ] . V_64 -> V_87 )
continue;
F_59 ( & V_46 -> V_31 [ V_3 ] ,
V_99 ,
V_100 ) ;
F_59 ( & V_46 -> V_31 [ V_3 ] ,
V_101 ,
V_100 ) ;
}
F_60 ( & V_46 -> V_53 ) ;
F_61 ( & V_46 -> V_53 ) ;
F_34 (codec, &card->codec_dev_list, card_list) {
if ( ! V_5 -> V_95 && V_5 -> V_10 -> V_93 ) {
switch ( V_5 -> V_53 . V_98 ) {
case V_102 :
if ( V_5 -> V_53 . V_103 ) {
F_42 ( V_5 -> V_27 ,
L_18 ) ;
break;
}
case V_104 :
V_5 -> V_10 -> V_93 ( V_5 ) ;
V_5 -> V_95 = 1 ;
V_5 -> V_49 = 1 ;
if ( V_5 -> V_105 )
F_62 ( V_5 -> V_106 ) ;
break;
default:
F_42 ( V_5 -> V_27 , L_19 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_46 -> V_83 ; V_3 ++ ) {
struct V_57 * V_92 = V_46 -> V_31 [ V_3 ] . V_92 ;
if ( V_46 -> V_31 [ V_3 ] . V_64 -> V_87 )
continue;
if ( V_92 -> V_10 -> V_93 && V_92 -> V_10 -> V_94 )
V_92 -> V_10 -> V_93 ( V_92 ) ;
}
if ( V_46 -> V_107 )
V_46 -> V_107 ( V_46 ) ;
return 0 ;
}
static void F_63 ( struct V_108 * V_109 )
{
struct V_59 * V_46 =
F_64 ( V_109 , struct V_59 , V_110 ) ;
struct V_4 * V_5 ;
int V_3 ;
F_42 ( V_46 -> V_27 , L_20 ) ;
F_56 ( V_46 -> V_77 , V_111 ) ;
if ( V_46 -> V_112 )
V_46 -> V_112 ( V_46 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_83 ; V_3 ++ ) {
struct V_57 * V_92 = V_46 -> V_31 [ V_3 ] . V_92 ;
if ( V_46 -> V_31 [ V_3 ] . V_64 -> V_87 )
continue;
if ( V_92 -> V_10 -> V_113 && V_92 -> V_10 -> V_94 )
V_92 -> V_10 -> V_113 ( V_92 ) ;
}
F_34 (codec, &card->codec_dev_list, card_list) {
if ( V_5 -> V_10 -> V_113 && V_5 -> V_95 ) {
switch ( V_5 -> V_53 . V_98 ) {
case V_102 :
case V_104 :
V_5 -> V_10 -> V_113 ( V_5 ) ;
V_5 -> V_95 = 0 ;
break;
default:
F_42 ( V_5 -> V_27 , L_21 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_46 -> V_83 ; V_3 ++ ) {
if ( V_46 -> V_31 [ V_3 ] . V_64 -> V_87 )
continue;
F_59 ( & V_46 -> V_31 [ V_3 ] ,
V_99 ,
V_114 ) ;
F_59 ( & V_46 -> V_31 [ V_3 ] ,
V_101 ,
V_114 ) ;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_83 ; V_3 ++ ) {
struct V_57 * V_58 = V_46 -> V_31 [ V_3 ] . V_84 ;
struct V_85 * V_86 = V_58 -> V_10 ;
if ( V_46 -> V_31 [ V_3 ] . V_64 -> V_87 )
continue;
if ( V_86 -> V_88 -> V_89 && V_58 -> V_90 )
V_86 -> V_88 -> V_89 ( V_58 , 0 ) ;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_83 ; V_3 ++ ) {
struct V_57 * V_92 = V_46 -> V_31 [ V_3 ] . V_92 ;
struct V_54 * V_55 = V_46 -> V_31 [ V_3 ] . V_55 ;
if ( V_46 -> V_31 [ V_3 ] . V_64 -> V_87 )
continue;
if ( V_92 -> V_10 -> V_113 && ! V_92 -> V_10 -> V_94 )
V_92 -> V_10 -> V_113 ( V_92 ) ;
if ( V_55 -> V_10 -> V_113 && V_55 -> V_95 ) {
V_55 -> V_10 -> V_113 ( V_92 ) ;
V_55 -> V_95 = 0 ;
}
}
if ( V_46 -> V_115 )
V_46 -> V_115 ( V_46 ) ;
F_42 ( V_46 -> V_27 , L_22 ) ;
F_56 ( V_46 -> V_77 , V_81 ) ;
F_60 ( & V_46 -> V_53 ) ;
F_61 ( & V_46 -> V_53 ) ;
}
int F_65 ( struct V_26 * V_27 )
{
struct V_59 * V_46 = F_9 ( V_27 ) ;
int V_3 , V_94 = 0 ;
if ( F_52 ( & V_46 -> V_80 ) )
return 0 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_83 ; V_3 ++ ) {
struct V_57 * V_92 = V_46 -> V_31 [ V_3 ] . V_92 ;
V_94 |= V_92 -> V_10 -> V_94 ;
}
if ( V_94 ) {
F_42 ( V_27 , L_23 ) ;
F_63 ( & V_46 -> V_110 ) ;
} else {
F_42 ( V_27 , L_24 ) ;
if ( ! F_66 ( & V_46 -> V_110 ) )
F_67 ( V_27 , L_25 ) ;
}
return 0 ;
}
static int F_68 ( struct V_59 * V_46 , int V_116 )
{
struct V_117 * V_64 = & V_46 -> V_64 [ V_116 ] ;
struct V_30 * V_31 = & V_46 -> V_31 [ V_116 ] ;
struct V_4 * V_5 ;
struct V_54 * V_55 ;
struct V_57 * V_84 , * V_92 ;
const char * V_118 ;
F_42 ( V_46 -> V_27 , L_26 , V_64 -> V_48 , V_116 ) ;
F_34 (cpu_dai, &dai_list, list) {
if ( V_64 -> V_119 &&
( V_92 -> V_27 -> V_120 != V_64 -> V_119 ) )
continue;
if ( V_64 -> V_121 &&
strcmp ( F_69 ( V_92 -> V_27 ) , V_64 -> V_121 ) )
continue;
if ( V_64 -> V_122 &&
strcmp ( V_92 -> V_48 , V_64 -> V_122 ) )
continue;
V_31 -> V_92 = V_92 ;
}
if ( ! V_31 -> V_92 ) {
F_67 ( V_46 -> V_27 , L_27 ,
V_64 -> V_122 ) ;
return - V_123 ;
}
F_34 (codec, &codec_list, list) {
if ( V_64 -> V_124 ) {
if ( V_5 -> V_27 -> V_120 != V_64 -> V_124 )
continue;
} else {
if ( strcmp ( V_5 -> V_48 , V_64 -> V_125 ) )
continue;
}
V_31 -> V_5 = V_5 ;
F_34 (codec_dai, &dai_list, list) {
if ( V_5 -> V_27 == V_84 -> V_27 &&
! strcmp ( V_84 -> V_48 ,
V_64 -> V_126 ) ) {
V_31 -> V_84 = V_84 ;
}
}
if ( ! V_31 -> V_84 ) {
F_67 ( V_46 -> V_27 , L_28 ,
V_64 -> V_126 ) ;
return - V_123 ;
}
}
if ( ! V_31 -> V_5 ) {
F_67 ( V_46 -> V_27 , L_29 ,
V_64 -> V_125 ) ;
return - V_123 ;
}
V_118 = V_64 -> V_118 ;
if ( ! V_118 && ! V_64 -> V_127 )
V_118 = L_30 ;
F_34 (platform, &platform_list, list) {
if ( V_64 -> V_127 ) {
if ( V_55 -> V_27 -> V_120 !=
V_64 -> V_127 )
continue;
} else {
if ( strcmp ( V_55 -> V_48 , V_118 ) )
continue;
}
V_31 -> V_55 = V_55 ;
}
if ( ! V_31 -> V_55 ) {
F_67 ( V_46 -> V_27 , L_31 ,
V_64 -> V_118 ) ;
return - V_123 ;
}
V_46 -> V_83 ++ ;
return 0 ;
}
static int F_70 ( struct V_54 * V_55 )
{
int V_14 ;
if ( V_55 -> V_10 -> remove ) {
V_14 = V_55 -> V_10 -> remove ( V_55 ) ;
if ( V_14 < 0 )
F_71 ( L_32 ,
V_55 -> V_48 , V_14 ) ;
}
F_72 ( & V_55 -> V_53 ) ;
F_32 ( V_55 ) ;
V_55 -> V_128 = 0 ;
F_73 ( & V_55 -> V_129 ) ;
F_74 ( V_55 -> V_27 -> V_10 -> V_130 ) ;
return 0 ;
}
static void F_75 ( struct V_4 * V_5 )
{
int V_73 ;
if ( V_5 -> V_10 -> remove ) {
V_73 = V_5 -> V_10 -> remove ( V_5 ) ;
if ( V_73 < 0 )
F_67 ( V_5 -> V_27 ,
L_32 ,
V_5 -> V_48 , V_73 ) ;
}
F_72 ( & V_5 -> V_53 ) ;
F_29 ( V_5 ) ;
V_5 -> V_128 = 0 ;
F_73 ( & V_5 -> V_129 ) ;
F_74 ( V_5 -> V_27 -> V_10 -> V_130 ) ;
}
static void F_76 ( struct V_59 * V_46 , int V_116 , int V_131 )
{
struct V_30 * V_31 = & V_46 -> V_31 [ V_116 ] ;
struct V_57 * V_84 = V_31 -> V_84 , * V_92 = V_31 -> V_92 ;
int V_73 ;
if ( V_31 -> V_132 ) {
F_77 ( V_31 -> V_27 , & V_133 ) ;
F_77 ( V_31 -> V_27 , & V_134 ) ;
F_45 ( V_31 -> V_27 ) ;
V_31 -> V_132 = 0 ;
}
if ( V_84 && V_84 -> V_128 &&
V_84 -> V_10 -> V_135 == V_131 ) {
if ( V_84 -> V_10 -> remove ) {
V_73 = V_84 -> V_10 -> remove ( V_84 ) ;
if ( V_73 < 0 )
F_71 ( L_32 ,
V_84 -> V_48 , V_73 ) ;
}
V_84 -> V_128 = 0 ;
F_73 ( & V_84 -> V_129 ) ;
}
if ( V_92 && V_92 -> V_128 &&
V_92 -> V_10 -> V_135 == V_131 ) {
if ( V_92 -> V_10 -> remove ) {
V_73 = V_92 -> V_10 -> remove ( V_92 ) ;
if ( V_73 < 0 )
F_71 ( L_32 ,
V_92 -> V_48 , V_73 ) ;
}
V_92 -> V_128 = 0 ;
F_73 ( & V_92 -> V_129 ) ;
if ( ! V_92 -> V_5 ) {
F_72 ( & V_92 -> V_53 ) ;
F_74 ( V_92 -> V_27 -> V_10 -> V_130 ) ;
}
}
}
static void F_78 ( struct V_59 * V_46 , int V_116 ,
int V_131 )
{
struct V_30 * V_31 = & V_46 -> V_31 [ V_116 ] ;
struct V_57 * V_92 = V_31 -> V_92 ;
struct V_57 * V_84 = V_31 -> V_84 ;
struct V_54 * V_55 = V_31 -> V_55 ;
struct V_4 * V_5 ;
if ( V_55 && V_55 -> V_128 &&
V_55 -> V_10 -> V_135 == V_131 ) {
F_70 ( V_55 ) ;
}
if ( V_84 ) {
V_5 = V_84 -> V_5 ;
if ( V_5 && V_5 -> V_128 &&
V_5 -> V_10 -> V_135 == V_131 )
F_75 ( V_5 ) ;
}
if ( V_92 ) {
V_5 = V_92 -> V_5 ;
if ( V_5 && V_5 -> V_128 &&
V_5 -> V_10 -> V_135 == V_131 )
F_75 ( V_5 ) ;
}
}
static void F_79 ( struct V_59 * V_46 )
{
int V_58 , V_131 ;
for ( V_131 = V_136 ; V_131 <= V_137 ;
V_131 ++ ) {
for ( V_58 = 0 ; V_58 < V_46 -> V_83 ; V_58 ++ )
F_76 ( V_46 , V_58 , V_131 ) ;
}
for ( V_131 = V_136 ; V_131 <= V_137 ;
V_131 ++ ) {
for ( V_58 = 0 ; V_58 < V_46 -> V_83 ; V_58 ++ )
F_78 ( V_46 , V_58 , V_131 ) ;
}
V_46 -> V_83 = 0 ;
}
static void F_80 ( struct V_59 * V_46 ,
struct V_4 * V_5 )
{
int V_3 ;
if ( V_46 -> V_138 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_46 -> V_139 ; V_3 ++ ) {
struct V_140 * V_141 = & V_46 -> V_138 [ V_3 ] ;
if ( V_141 -> F_69 && ! strcmp ( V_5 -> V_48 , V_141 -> F_69 ) ) {
V_5 -> V_142 = V_141 -> V_142 ;
break;
}
}
}
static int F_81 ( struct V_59 * V_46 ,
struct V_4 * V_5 )
{
int V_14 = 0 ;
const struct V_143 * V_10 = V_5 -> V_10 ;
struct V_57 * V_58 ;
V_5 -> V_46 = V_46 ;
V_5 -> V_53 . V_46 = V_46 ;
F_80 ( V_46 , V_5 ) ;
if ( ! F_82 ( V_5 -> V_27 -> V_10 -> V_130 ) )
return - V_144 ;
F_23 ( V_5 ) ;
if ( V_10 -> V_145 )
F_83 ( & V_5 -> V_53 , V_10 -> V_145 ,
V_10 -> V_146 ) ;
F_34 (dai, &dai_list, list) {
if ( V_58 -> V_27 != V_5 -> V_27 )
continue;
F_84 ( & V_5 -> V_53 , V_58 ) ;
}
V_5 -> V_53 . V_103 = V_10 -> V_103 ;
if ( V_10 -> V_147 ) {
V_14 = V_10 -> V_147 ( V_5 ) ;
if ( V_14 < 0 ) {
F_67 ( V_5 -> V_27 ,
L_33 ,
V_5 -> V_48 , V_14 ) ;
goto V_148;
}
}
if ( ! V_5 -> V_149 && F_85 ( V_5 -> V_27 , NULL ) )
F_86 ( V_5 , 0 , 0 , V_150 ) ;
if ( V_10 -> V_151 )
F_87 ( V_5 , V_10 -> V_151 ,
V_10 -> V_152 ) ;
if ( V_10 -> V_153 )
F_88 ( & V_5 -> V_53 , V_10 -> V_153 ,
V_10 -> V_154 ) ;
V_5 -> V_128 = 1 ;
F_89 ( & V_5 -> V_129 , & V_46 -> V_80 ) ;
F_89 ( & V_5 -> V_53 . V_155 , & V_46 -> V_156 ) ;
return 0 ;
V_148:
F_29 ( V_5 ) ;
F_74 ( V_5 -> V_27 -> V_10 -> V_130 ) ;
return V_14 ;
}
static int F_90 ( struct V_59 * V_46 ,
struct V_54 * V_55 )
{
int V_14 = 0 ;
const struct V_157 * V_10 = V_55 -> V_10 ;
struct V_57 * V_58 ;
V_55 -> V_46 = V_46 ;
V_55 -> V_53 . V_46 = V_46 ;
if ( ! F_82 ( V_55 -> V_27 -> V_10 -> V_130 ) )
return - V_144 ;
F_31 ( V_55 ) ;
if ( V_10 -> V_145 )
F_83 ( & V_55 -> V_53 ,
V_10 -> V_145 , V_10 -> V_146 ) ;
F_34 (dai, &dai_list, list) {
if ( V_58 -> V_27 != V_55 -> V_27 )
continue;
F_84 ( & V_55 -> V_53 , V_58 ) ;
}
V_55 -> V_53 . V_103 = 1 ;
if ( V_10 -> V_147 ) {
V_14 = V_10 -> V_147 ( V_55 ) ;
if ( V_14 < 0 ) {
F_67 ( V_55 -> V_27 ,
L_34 ,
V_55 -> V_48 , V_14 ) ;
goto V_148;
}
}
if ( V_10 -> V_151 )
F_91 ( V_55 , V_10 -> V_151 ,
V_10 -> V_152 ) ;
if ( V_10 -> V_153 )
F_88 ( & V_55 -> V_53 , V_10 -> V_153 ,
V_10 -> V_154 ) ;
V_55 -> V_128 = 1 ;
F_89 ( & V_55 -> V_129 , & V_46 -> V_158 ) ;
F_89 ( & V_55 -> V_53 . V_155 , & V_46 -> V_156 ) ;
return 0 ;
V_148:
F_32 ( V_55 ) ;
F_74 ( V_55 -> V_27 -> V_10 -> V_130 ) ;
return V_14 ;
}
static void F_92 ( struct V_26 * V_27 )
{
F_16 ( V_27 ) ;
}
static int F_93 ( struct V_59 * V_46 ,
struct V_4 * V_5 ,
int V_116 , int V_159 )
{
struct V_117 * V_64 = NULL ;
struct V_160 * V_161 = NULL ;
struct V_30 * V_31 ;
const char * V_162 , * V_48 ;
int V_14 = 0 ;
if ( ! V_159 ) {
V_64 = & V_46 -> V_64 [ V_116 ] ;
V_31 = & V_46 -> V_31 [ V_116 ] ;
V_48 = V_64 -> V_48 ;
} else {
V_161 = & V_46 -> V_161 [ V_116 ] ;
V_31 = & V_46 -> V_163 [ V_116 ] ;
V_48 = V_161 -> V_48 ;
}
V_31 -> V_46 = V_46 ;
F_94 ( & V_5 -> V_53 ) ;
V_162 = V_5 -> V_142 ;
V_5 -> V_142 = NULL ;
if ( ! V_159 && V_64 -> V_164 )
V_14 = V_64 -> V_164 ( V_31 ) ;
else if ( V_159 && V_161 -> V_164 )
V_14 = V_161 -> V_164 ( & V_5 -> V_53 ) ;
if ( V_14 < 0 ) {
F_67 ( V_46 -> V_27 , L_35 , V_48 , V_14 ) ;
return V_14 ;
}
V_5 -> V_142 = V_162 ;
V_31 -> V_5 = V_5 ;
V_31 -> V_27 = F_95 ( sizeof( struct V_26 ) , V_37 ) ;
if ( ! V_31 -> V_27 )
return - V_38 ;
F_96 ( V_31 -> V_27 ) ;
V_31 -> V_27 -> V_75 = V_46 -> V_27 ;
V_31 -> V_27 -> V_76 = F_92 ;
V_31 -> V_27 -> V_165 = V_48 ;
F_97 ( V_31 -> V_27 , V_31 ) ;
F_98 ( & V_31 -> V_166 ) ;
F_99 ( & V_31 -> V_167 [ V_99 ] . V_168 ) ;
F_99 ( & V_31 -> V_167 [ V_101 ] . V_168 ) ;
F_99 ( & V_31 -> V_167 [ V_99 ] . V_169 ) ;
F_99 ( & V_31 -> V_167 [ V_101 ] . V_169 ) ;
V_14 = F_100 ( V_31 -> V_27 ) ;
if ( V_14 < 0 ) {
F_67 ( V_46 -> V_27 ,
L_36 , V_14 ) ;
return V_14 ;
}
V_31 -> V_132 = 1 ;
V_14 = F_101 ( V_31 -> V_27 ) ;
if ( V_14 < 0 )
F_67 ( V_5 -> V_27 ,
L_37 ,
V_14 ) ;
V_14 = F_102 ( V_31 -> V_27 , & V_134 ) ;
if ( V_14 < 0 )
F_67 ( V_5 -> V_27 ,
L_38 , V_14 ) ;
#ifdef F_103
if ( ! V_159 && ! V_64 -> V_170 )
goto V_171;
V_14 = F_104 ( V_31 ) ;
if ( V_14 < 0 )
F_67 ( V_31 -> V_27 , L_39 , V_14 ) ;
V_171:
#endif
return 0 ;
}
static int F_105 ( struct V_59 * V_46 , int V_116 ,
int V_131 )
{
struct V_30 * V_31 = & V_46 -> V_31 [ V_116 ] ;
struct V_57 * V_92 = V_31 -> V_92 ;
struct V_57 * V_84 = V_31 -> V_84 ;
struct V_54 * V_55 = V_31 -> V_55 ;
int V_14 ;
if ( V_92 -> V_5 &&
! V_92 -> V_5 -> V_128 &&
V_92 -> V_5 -> V_10 -> V_172 == V_131 ) {
V_14 = F_81 ( V_46 , V_92 -> V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_84 -> V_5 -> V_128 &&
V_84 -> V_5 -> V_10 -> V_172 == V_131 ) {
V_14 = F_81 ( V_46 , V_84 -> V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_55 -> V_128 &&
V_55 -> V_10 -> V_172 == V_131 ) {
V_14 = F_90 ( V_46 , V_55 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
static int F_106 ( struct V_59 * V_46 , int V_116 , int V_131 )
{
struct V_117 * V_64 = & V_46 -> V_64 [ V_116 ] ;
struct V_30 * V_31 = & V_46 -> V_31 [ V_116 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
struct V_54 * V_55 = V_31 -> V_55 ;
struct V_57 * V_84 = V_31 -> V_84 ;
struct V_57 * V_92 = V_31 -> V_92 ;
struct V_173 * V_174 , * V_175 ;
int V_14 ;
F_42 ( V_46 -> V_27 , L_40 ,
V_46 -> V_48 , V_116 , V_131 ) ;
V_92 -> V_55 = V_55 ;
V_84 -> V_46 = V_46 ;
V_92 -> V_46 = V_46 ;
V_31 -> V_32 = V_32 ;
if ( ! V_92 -> V_128 &&
V_92 -> V_10 -> V_172 == V_131 ) {
if ( ! V_92 -> V_5 ) {
V_92 -> V_53 . V_46 = V_46 ;
if ( ! F_82 ( V_92 -> V_27 -> V_10 -> V_130 ) )
return - V_144 ;
F_89 ( & V_92 -> V_53 . V_155 , & V_46 -> V_156 ) ;
F_84 ( & V_92 -> V_53 , V_92 ) ;
}
if ( V_92 -> V_10 -> V_147 ) {
V_14 = V_92 -> V_10 -> V_147 ( V_92 ) ;
if ( V_14 < 0 ) {
F_71 ( L_41 ,
V_92 -> V_48 , V_14 ) ;
F_74 ( V_92 -> V_27 -> V_10 -> V_130 ) ;
return V_14 ;
}
}
V_92 -> V_128 = 1 ;
F_89 ( & V_92 -> V_129 , & V_46 -> V_176 ) ;
}
if ( ! V_84 -> V_128 && V_84 -> V_10 -> V_172 == V_131 ) {
if ( V_84 -> V_10 -> V_147 ) {
V_14 = V_84 -> V_10 -> V_147 ( V_84 ) ;
if ( V_14 < 0 ) {
F_71 ( L_42 ,
V_84 -> V_48 , V_14 ) ;
return V_14 ;
}
}
V_84 -> V_128 = 1 ;
F_89 ( & V_84 -> V_129 , & V_46 -> V_176 ) ;
}
if ( V_131 != V_137 )
return 0 ;
V_14 = F_93 ( V_46 , V_5 , V_116 , 0 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_102 ( V_31 -> V_27 , & V_133 ) ;
if ( V_14 < 0 )
F_107 ( L_43 , V_14 ) ;
if ( V_92 -> V_10 -> V_177 ) {
V_14 = F_108 ( V_31 , V_116 ) ;
if ( V_14 < 0 ) {
F_71 ( L_44 ,
V_64 -> V_178 ) ;
return V_14 ;
}
} else {
if ( ! V_64 -> V_179 ) {
V_14 = F_109 ( V_31 , V_116 ) ;
if ( V_14 < 0 ) {
F_71 ( L_45 ,
V_64 -> V_178 , V_14 ) ;
return V_14 ;
}
} else {
V_174 = V_84 -> V_180 ;
V_175 = V_92 -> V_181 ;
if ( V_174 && V_175 ) {
V_14 = F_110 ( V_46 , V_64 -> V_179 ,
V_175 , V_174 ) ;
if ( V_14 != 0 ) {
F_67 ( V_46 -> V_27 , L_46 ,
V_174 -> V_48 , V_175 -> V_48 , V_14 ) ;
return V_14 ;
}
}
V_174 = V_92 -> V_180 ;
V_175 = V_84 -> V_181 ;
if ( V_174 && V_175 ) {
V_14 = F_110 ( V_46 , V_64 -> V_179 ,
V_175 , V_174 ) ;
if ( V_14 != 0 ) {
F_67 ( V_46 -> V_27 , L_46 ,
V_174 -> V_48 , V_175 -> V_48 , V_14 ) ;
return V_14 ;
}
}
}
}
if ( V_31 -> V_84 -> V_10 -> V_94 )
F_111 ( V_5 -> V_71 , V_31 -> V_92 -> V_182 ) ;
return 0 ;
}
static int F_112 ( struct V_30 * V_31 )
{
int V_14 ;
if ( V_31 -> V_84 -> V_10 -> V_94 && ! V_31 -> V_5 -> V_183 ) {
if ( ! V_31 -> V_5 -> V_184 )
return 0 ;
V_14 = F_47 ( V_31 -> V_5 ) ;
if ( V_14 < 0 ) {
F_71 ( L_47 , V_14 ) ;
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
static int F_114 ( struct V_59 * V_46 , int V_116 )
{
struct V_160 * V_161 = & V_46 -> V_161 [ V_116 ] ;
struct V_4 * V_5 ;
F_34 (codec, &codec_list, list) {
if ( ! strcmp ( V_5 -> V_48 , V_161 -> V_125 ) )
return 0 ;
}
F_67 ( V_46 -> V_27 , L_48 , V_161 -> V_125 ) ;
return - V_123 ;
}
static int F_115 ( struct V_59 * V_46 , int V_116 )
{
struct V_160 * V_161 = & V_46 -> V_161 [ V_116 ] ;
struct V_4 * V_5 ;
int V_14 = - V_144 ;
F_34 (codec, &codec_list, list) {
if ( ! strcmp ( V_5 -> V_48 , V_161 -> V_125 ) ) {
if ( V_5 -> V_128 ) {
F_67 ( V_5 -> V_27 ,
L_49 ) ;
V_14 = - V_185 ;
goto V_171;
}
goto V_186;
}
}
F_67 ( V_46 -> V_27 , L_50 , V_161 -> V_125 ) ;
return - V_123 ;
V_186:
V_14 = F_81 ( V_46 , V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_93 ( V_46 , V_5 , V_116 , 1 ) ;
V_171:
return V_14 ;
}
static void F_116 ( struct V_59 * V_46 , int V_116 )
{
struct V_30 * V_31 = & V_46 -> V_163 [ V_116 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
if ( V_31 -> V_132 ) {
F_77 ( V_31 -> V_27 , & V_134 ) ;
F_117 ( V_31 -> V_27 ) ;
V_31 -> V_132 = 0 ;
}
if ( V_5 && V_5 -> V_128 )
F_75 ( V_5 ) ;
}
static int F_118 ( struct V_4 * V_5 ,
enum V_187 V_188 )
{
int V_14 ;
if ( V_5 -> V_189 )
return 0 ;
if ( V_188 && V_5 -> V_188 != V_188 )
V_5 -> V_188 = V_188 ;
V_14 = F_119 ( V_5 ) ;
if ( V_14 < 0 ) {
F_67 ( V_5 -> V_27 , L_51 ,
V_14 ) ;
return V_14 ;
}
V_5 -> V_189 = 1 ;
return 0 ;
}
static int F_120 ( struct V_59 * V_46 )
{
struct V_4 * V_5 ;
struct V_140 * V_138 ;
enum V_187 V_188 ;
struct V_117 * V_64 ;
int V_14 , V_3 , V_131 , V_190 ;
F_121 ( & V_46 -> V_191 , V_192 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ ) {
V_14 = F_68 ( V_46 , V_3 ) ;
if ( V_14 != 0 )
goto V_193;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_194 ; V_3 ++ ) {
V_14 = F_114 ( V_46 , V_3 ) ;
if ( V_14 != 0 )
goto V_193;
}
F_34 (codec, &codec_list, list) {
if ( V_5 -> V_189 )
continue;
V_188 = 0 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_139 ; ++ V_3 ) {
V_138 = & V_46 -> V_138 [ V_3 ] ;
if ( ! strcmp ( V_5 -> V_48 , V_138 -> F_69 ) ) {
V_188 = V_138 -> V_188 ;
if ( V_188 && V_188
!= V_5 -> V_188 )
break;
}
}
V_14 = F_118 ( V_5 , V_188 ) ;
if ( V_14 < 0 )
goto V_193;
}
V_14 = F_122 ( V_195 , V_196 ,
V_46 -> V_130 , 0 , & V_46 -> V_77 ) ;
if ( V_14 < 0 ) {
F_71 ( L_52 ,
V_46 -> V_48 , V_14 ) ;
goto V_193;
}
V_46 -> V_77 -> V_27 = V_46 -> V_27 ;
V_46 -> V_53 . V_98 = V_104 ;
V_46 -> V_53 . V_27 = V_46 -> V_27 ;
V_46 -> V_53 . V_46 = V_46 ;
F_89 ( & V_46 -> V_53 . V_155 , & V_46 -> V_156 ) ;
#ifdef F_103
F_28 ( & V_46 -> V_53 , V_46 -> V_45 ) ;
#endif
#ifdef F_123
F_124 ( & V_46 -> V_110 , F_63 ) ;
#endif
if ( V_46 -> V_145 )
F_83 ( & V_46 -> V_53 , V_46 -> V_145 ,
V_46 -> V_146 ) ;
if ( V_46 -> V_147 ) {
V_14 = V_46 -> V_147 ( V_46 ) ;
if ( V_14 < 0 )
goto V_197;
}
for ( V_131 = V_136 ; V_131 <= V_137 ;
V_131 ++ ) {
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ ) {
V_14 = F_105 ( V_46 , V_3 , V_131 ) ;
if ( V_14 < 0 ) {
F_71 ( L_53 ,
V_46 -> V_48 , V_14 ) ;
goto V_198;
}
}
}
for ( V_131 = V_136 ; V_131 <= V_137 ;
V_131 ++ ) {
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ ) {
V_14 = F_106 ( V_46 , V_3 , V_131 ) ;
if ( V_14 < 0 ) {
F_71 ( L_53 ,
V_46 -> V_48 , V_14 ) ;
goto V_198;
}
}
}
for ( V_3 = 0 ; V_3 < V_46 -> V_194 ; V_3 ++ ) {
V_14 = F_115 ( V_46 , V_3 ) ;
if ( V_14 < 0 ) {
F_71 ( L_54 ,
V_46 -> V_48 , V_14 ) ;
goto V_199;
}
}
F_125 ( V_46 ) ;
if ( V_46 -> V_151 )
F_126 ( V_46 , V_46 -> V_151 , V_46 -> V_152 ) ;
if ( V_46 -> V_153 )
F_88 ( & V_46 -> V_53 , V_46 -> V_153 ,
V_46 -> V_154 ) ;
F_94 ( & V_46 -> V_53 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ ) {
V_64 = & V_46 -> V_64 [ V_3 ] ;
V_190 = V_64 -> V_190 ;
if ( V_190 ) {
V_14 = F_127 ( V_46 -> V_31 [ V_3 ] . V_84 ,
V_190 ) ;
if ( V_14 != 0 && V_14 != - V_200 )
F_25 ( V_46 -> V_31 [ V_3 ] . V_84 -> V_27 ,
L_55 ,
V_14 ) ;
}
if ( V_190 &&
( V_64 -> V_118 || V_64 -> V_127 ) ) {
V_14 = F_127 ( V_46 -> V_31 [ V_3 ] . V_92 ,
V_190 ) ;
if ( V_14 != 0 && V_14 != - V_200 )
F_25 ( V_46 -> V_31 [ V_3 ] . V_92 -> V_27 ,
L_55 ,
V_14 ) ;
} else if ( V_190 ) {
V_190 &= ~ V_201 ;
switch ( V_64 -> V_190 &
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
V_14 = F_127 ( V_46 -> V_31 [ V_3 ] . V_92 ,
V_190 ) ;
if ( V_14 != 0 && V_14 != - V_200 )
F_25 ( V_46 -> V_31 [ V_3 ] . V_92 -> V_27 ,
L_55 ,
V_14 ) ;
}
}
snprintf ( V_46 -> V_77 -> V_206 , sizeof( V_46 -> V_77 -> V_206 ) ,
L_56 , V_46 -> V_48 ) ;
snprintf ( V_46 -> V_77 -> V_207 , sizeof( V_46 -> V_77 -> V_207 ) ,
L_56 , V_46 -> V_208 ? V_46 -> V_208 : V_46 -> V_48 ) ;
snprintf ( V_46 -> V_77 -> V_10 , sizeof( V_46 -> V_77 -> V_10 ) ,
L_56 , V_46 -> V_209 ? V_46 -> V_209 : V_46 -> V_48 ) ;
for ( V_3 = 0 ; V_3 < F_128 ( V_46 -> V_77 -> V_10 ) ; V_3 ++ ) {
switch ( V_46 -> V_77 -> V_10 [ V_3 ] ) {
case '_' :
case '-' :
case '\0' :
break;
default:
if ( ! isalnum ( V_46 -> V_77 -> V_10 [ V_3 ] ) )
V_46 -> V_77 -> V_10 [ V_3 ] = '_' ;
break;
}
}
if ( V_46 -> V_210 ) {
V_14 = V_46 -> V_210 ( V_46 ) ;
if ( V_14 < 0 ) {
F_67 ( V_46 -> V_27 , L_57 ,
V_46 -> V_48 , V_14 ) ;
goto V_199;
}
}
F_94 ( & V_46 -> V_53 ) ;
if ( V_46 -> V_211 )
F_34 (codec, &card->codec_dev_list, card_list)
F_129 ( V_5 ) ;
V_14 = F_130 ( V_46 -> V_77 ) ;
if ( V_14 < 0 ) {
F_71 ( L_58 ,
V_46 -> V_48 , V_14 ) ;
goto V_199;
}
#ifdef F_131
for ( V_3 = 0 ; V_3 < V_46 -> V_83 ; V_3 ++ ) {
V_14 = F_112 ( & V_46 -> V_31 [ V_3 ] ) ;
if ( V_14 < 0 ) {
F_71 ( L_59 ,
V_46 -> V_48 , V_14 ) ;
while ( -- V_3 >= 0 )
F_113 ( V_46 -> V_31 [ V_3 ] . V_5 ) ;
goto V_199;
}
}
#endif
V_46 -> V_212 = 1 ;
F_61 ( & V_46 -> V_53 ) ;
F_132 ( & V_46 -> V_191 ) ;
return 0 ;
V_199:
for ( V_3 = 0 ; V_3 < V_46 -> V_194 ; V_3 ++ )
F_116 ( V_46 , V_3 ) ;
V_198:
F_79 ( V_46 ) ;
V_197:
if ( V_46 -> remove )
V_46 -> remove ( V_46 ) ;
F_133 ( V_46 -> V_77 ) ;
V_193:
F_132 ( & V_46 -> V_191 ) ;
return V_14 ;
}
static int F_134 ( struct V_213 * V_214 )
{
struct V_59 * V_46 = F_135 ( V_214 ) ;
if ( ! V_46 )
return - V_17 ;
F_25 ( & V_214 -> V_27 ,
L_60 ,
V_46 -> V_48 ) ;
V_46 -> V_27 = & V_214 -> V_27 ;
return F_136 ( V_46 ) ;
}
static int F_137 ( struct V_59 * V_46 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_83 ; V_3 ++ ) {
struct V_30 * V_31 = & V_46 -> V_31 [ V_3 ] ;
F_58 ( & V_31 -> V_96 ) ;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_194 ; V_3 ++ )
F_116 ( V_46 , V_3 ) ;
F_79 ( V_46 ) ;
F_40 ( V_46 ) ;
if ( V_46 -> remove )
V_46 -> remove ( V_46 ) ;
F_72 ( & V_46 -> V_53 ) ;
F_133 ( V_46 -> V_77 ) ;
return 0 ;
}
static int F_138 ( struct V_213 * V_214 )
{
struct V_59 * V_46 = F_135 ( V_214 ) ;
F_139 ( V_46 ) ;
return 0 ;
}
int F_140 ( struct V_26 * V_27 )
{
struct V_59 * V_46 = F_9 ( V_27 ) ;
int V_3 ;
if ( ! V_46 -> V_212 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_83 ; V_3 ++ ) {
struct V_30 * V_31 = & V_46 -> V_31 [ V_3 ] ;
F_58 ( & V_31 -> V_96 ) ;
}
F_141 ( V_46 ) ;
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
int F_144 ( struct V_54 * V_55 ,
unsigned int V_6 )
{
unsigned int V_14 ;
if ( ! V_55 -> V_10 -> V_218 ) {
F_67 ( V_55 -> V_27 , L_61 ) ;
return - 1 ;
}
V_14 = V_55 -> V_10 -> V_218 ( V_55 , V_6 ) ;
F_42 ( V_55 -> V_27 , L_62 , V_6 , V_14 ) ;
F_145 ( V_55 , V_6 , V_14 ) ;
return V_14 ;
}
int F_146 ( struct V_54 * V_55 ,
unsigned int V_6 , unsigned int V_1 )
{
if ( ! V_55 -> V_10 -> V_149 ) {
F_67 ( V_55 -> V_27 , L_63 ) ;
return - 1 ;
}
F_42 ( V_55 -> V_27 , L_64 , V_6 , V_1 ) ;
F_147 ( V_55 , V_6 , V_1 ) ;
return V_55 -> V_10 -> V_149 ( V_55 , V_6 , V_1 ) ;
}
int F_148 ( struct V_4 * V_5 ,
struct V_219 * V_88 , int V_116 )
{
F_149 ( & V_5 -> V_191 ) ;
V_5 -> V_71 = F_95 ( sizeof( struct V_220 ) , V_37 ) ;
if ( V_5 -> V_71 == NULL ) {
F_132 ( & V_5 -> V_191 ) ;
return - V_38 ;
}
V_5 -> V_71 -> V_72 = F_95 ( sizeof( struct V_221 ) , V_37 ) ;
if ( V_5 -> V_71 -> V_72 == NULL ) {
F_16 ( V_5 -> V_71 ) ;
V_5 -> V_71 = NULL ;
F_132 ( & V_5 -> V_191 ) ;
return - V_38 ;
}
V_5 -> V_71 -> V_72 -> V_88 = V_88 ;
V_5 -> V_71 -> V_116 = V_116 ;
V_5 -> V_184 = 1 ;
F_132 ( & V_5 -> V_191 ) ;
return 0 ;
}
void F_150 ( struct V_4 * V_5 )
{
F_149 ( & V_5 -> V_191 ) ;
#ifdef F_131
F_113 ( V_5 ) ;
#endif
F_16 ( V_5 -> V_71 -> V_72 ) ;
F_16 ( V_5 -> V_71 ) ;
V_5 -> V_71 = NULL ;
V_5 -> V_184 = 0 ;
F_132 ( & V_5 -> V_191 ) ;
}
unsigned int F_4 ( struct V_4 * V_5 , unsigned int V_6 )
{
unsigned int V_14 ;
V_14 = V_5 -> V_218 ( V_5 , V_6 ) ;
F_42 ( V_5 -> V_27 , L_62 , V_6 , V_14 ) ;
F_151 ( V_5 , V_6 , V_14 ) ;
return V_14 ;
}
unsigned int F_22 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned int V_1 )
{
F_42 ( V_5 -> V_27 , L_64 , V_6 , V_1 ) ;
F_152 ( V_5 , V_6 , V_1 ) ;
return V_5 -> V_149 ( V_5 , V_6 , V_1 ) ;
}
unsigned int F_153 ( struct V_4 * V_5 ,
unsigned int V_6 , const void * V_222 , T_1 V_8 )
{
return V_5 -> V_223 ( V_5 , V_6 , V_222 , V_8 ) ;
}
int F_154 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_224 , unsigned int V_42 )
{
bool V_225 ;
unsigned int V_226 , V_227 ;
int V_14 ;
if ( V_5 -> V_105 ) {
V_14 = F_155 ( V_5 -> V_106 , V_6 ,
V_224 , V_42 , & V_225 ) ;
} else {
V_14 = F_4 ( V_5 , V_6 ) ;
if ( V_14 < 0 )
return V_14 ;
V_226 = V_14 ;
V_227 = ( V_226 & ~ V_224 ) | ( V_42 & V_224 ) ;
V_225 = V_226 != V_227 ;
if ( V_225 )
V_14 = F_22 ( V_5 , V_6 , V_227 ) ;
}
if ( V_14 < 0 )
return V_14 ;
return V_225 ;
}
int F_156 ( struct V_4 * V_5 ,
unsigned short V_6 , unsigned int V_224 ,
unsigned int V_42 )
{
int V_225 ;
F_149 ( & V_5 -> V_191 ) ;
V_225 = F_154 ( V_5 , V_6 , V_224 , V_42 ) ;
F_132 ( & V_5 -> V_191 ) ;
return V_225 ;
}
int F_157 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_224 , unsigned int V_42 )
{
int V_225 ;
unsigned int V_226 , V_227 ;
V_226 = F_4 ( V_5 , V_6 ) ;
V_227 = ( V_226 & ~ V_224 ) | V_42 ;
V_225 = V_226 != V_227 ;
return V_225 ;
}
int F_158 ( struct V_63 * V_70 ,
const struct V_228 * V_229 )
{
struct V_230 * V_231 = V_70 -> V_231 ;
V_231 -> V_229 . V_232 = V_229 -> V_232 ;
V_231 -> V_229 . V_233 = V_229 -> V_233 ;
V_231 -> V_229 . V_234 = V_229 -> V_234 ;
V_231 -> V_229 . V_235 = V_229 -> V_235 ;
V_231 -> V_229 . V_236 = V_229 -> V_236 ;
V_231 -> V_229 . V_237 = V_229 -> V_237 ;
V_231 -> V_229 . V_238 = V_229 -> V_238 ;
V_231 -> V_229 . V_239 = V_229 -> V_239 ;
return 0 ;
}
struct V_240 * F_159 ( const struct V_241 * V_242 ,
void * V_222 , const char * V_208 ,
const char * V_243 )
{
struct V_241 V_244 ;
struct V_240 * V_245 ;
char * V_48 = NULL ;
int V_246 ;
memcpy ( & V_244 , V_242 , sizeof( V_244 ) ) ;
V_244 . V_247 = 0 ;
if ( ! V_208 )
V_208 = V_244 . V_48 ;
if ( V_243 ) {
V_246 = strlen ( V_208 ) + strlen ( V_243 ) + 2 ;
V_48 = F_14 ( V_246 , V_37 ) ;
if ( ! V_48 )
return NULL ;
snprintf ( V_48 , V_246 , L_65 , V_243 , V_208 ) ;
V_244 . V_48 = V_48 ;
} else {
V_244 . V_48 = V_208 ;
}
V_245 = F_160 ( & V_244 , V_222 ) ;
F_16 ( V_48 ) ;
return V_245 ;
}
static int F_161 ( struct V_77 * V_46 , struct V_26 * V_27 ,
const struct V_241 * V_151 , int V_152 ,
const char * V_243 , void * V_222 )
{
int V_73 , V_3 ;
for ( V_3 = 0 ; V_3 < V_152 ; V_3 ++ ) {
const struct V_241 * V_248 = & V_151 [ V_3 ] ;
V_73 = F_162 ( V_46 , F_159 ( V_248 , V_222 ,
V_248 -> V_48 , V_243 ) ) ;
if ( V_73 < 0 ) {
F_67 ( V_27 , L_66 , V_248 -> V_48 , V_73 ) ;
return V_73 ;
}
}
return 0 ;
}
int F_87 ( struct V_4 * V_5 ,
const struct V_241 * V_151 , int V_152 )
{
struct V_77 * V_46 = V_5 -> V_46 -> V_77 ;
return F_161 ( V_46 , V_5 -> V_27 , V_151 , V_152 ,
V_5 -> V_142 , V_5 ) ;
}
int F_91 ( struct V_54 * V_55 ,
const struct V_241 * V_151 , int V_152 )
{
struct V_77 * V_46 = V_55 -> V_46 -> V_77 ;
return F_161 ( V_46 , V_55 -> V_27 , V_151 , V_152 ,
NULL , V_55 ) ;
}
int F_126 ( struct V_59 * V_249 ,
const struct V_241 * V_151 , int V_152 )
{
struct V_77 * V_46 = V_249 -> V_77 ;
return F_161 ( V_46 , V_249 -> V_27 , V_151 , V_152 ,
NULL , V_249 ) ;
}
int F_163 ( struct V_57 * V_58 ,
const struct V_241 * V_151 , int V_152 )
{
struct V_77 * V_46 = V_58 -> V_46 -> V_77 ;
return F_161 ( V_46 , V_58 -> V_27 , V_151 , V_152 ,
NULL , V_58 ) ;
}
int F_164 ( struct V_240 * V_245 ,
struct V_250 * V_251 )
{
struct V_252 * V_253 = (struct V_252 * ) V_245 -> V_254 ;
V_251 -> type = V_255 ;
V_251 -> V_18 = V_253 -> V_256 == V_253 -> V_257 ? 1 : 2 ;
V_251 -> V_42 . V_258 . V_259 = V_253 -> V_260 ;
if ( V_251 -> V_42 . V_258 . V_261 > V_253 -> V_260 - 1 )
V_251 -> V_42 . V_258 . V_261 = V_253 -> V_260 - 1 ;
strcpy ( V_251 -> V_42 . V_258 . V_48 ,
V_253 -> V_262 [ V_251 -> V_42 . V_258 . V_261 ] ) ;
return 0 ;
}
int F_165 ( struct V_240 * V_245 ,
struct V_263 * V_264 )
{
struct V_4 * V_5 = F_166 ( V_245 ) ;
struct V_252 * V_253 = (struct V_252 * ) V_245 -> V_254 ;
unsigned int V_1 ;
V_1 = F_4 ( V_5 , V_253 -> V_6 ) ;
V_264 -> V_42 . V_258 . V_261 [ 0 ]
= ( V_1 >> V_253 -> V_256 ) & V_253 -> V_224 ;
if ( V_253 -> V_256 != V_253 -> V_257 )
V_264 -> V_42 . V_258 . V_261 [ 1 ] =
( V_1 >> V_253 -> V_257 ) & V_253 -> V_224 ;
return 0 ;
}
int F_167 ( struct V_240 * V_245 ,
struct V_263 * V_264 )
{
struct V_4 * V_5 = F_166 ( V_245 ) ;
struct V_252 * V_253 = (struct V_252 * ) V_245 -> V_254 ;
unsigned int V_1 ;
unsigned int V_224 ;
if ( V_264 -> V_42 . V_258 . V_261 [ 0 ] > V_253 -> V_260 - 1 )
return - V_17 ;
V_1 = V_264 -> V_42 . V_258 . V_261 [ 0 ] << V_253 -> V_256 ;
V_224 = V_253 -> V_224 << V_253 -> V_256 ;
if ( V_253 -> V_256 != V_253 -> V_257 ) {
if ( V_264 -> V_42 . V_258 . V_261 [ 1 ] > V_253 -> V_260 - 1 )
return - V_17 ;
V_1 |= V_264 -> V_42 . V_258 . V_261 [ 1 ] << V_253 -> V_257 ;
V_224 |= V_253 -> V_224 << V_253 -> V_257 ;
}
return F_156 ( V_5 , V_253 -> V_6 , V_224 , V_1 ) ;
}
int F_168 ( struct V_240 * V_245 ,
struct V_263 * V_264 )
{
struct V_4 * V_5 = F_166 ( V_245 ) ;
struct V_252 * V_253 = (struct V_252 * ) V_245 -> V_254 ;
unsigned int V_265 , V_1 , V_266 ;
V_265 = F_4 ( V_5 , V_253 -> V_6 ) ;
V_1 = ( V_265 >> V_253 -> V_256 ) & V_253 -> V_224 ;
for ( V_266 = 0 ; V_266 < V_253 -> V_260 ; V_266 ++ ) {
if ( V_1 == V_253 -> V_267 [ V_266 ] )
break;
}
V_264 -> V_42 . V_258 . V_261 [ 0 ] = V_266 ;
if ( V_253 -> V_256 != V_253 -> V_257 ) {
V_1 = ( V_265 >> V_253 -> V_257 ) & V_253 -> V_224 ;
for ( V_266 = 0 ; V_266 < V_253 -> V_260 ; V_266 ++ ) {
if ( V_1 == V_253 -> V_267 [ V_266 ] )
break;
}
V_264 -> V_42 . V_258 . V_261 [ 1 ] = V_266 ;
}
return 0 ;
}
int F_169 ( struct V_240 * V_245 ,
struct V_263 * V_264 )
{
struct V_4 * V_5 = F_166 ( V_245 ) ;
struct V_252 * V_253 = (struct V_252 * ) V_245 -> V_254 ;
unsigned int V_1 ;
unsigned int V_224 ;
if ( V_264 -> V_42 . V_258 . V_261 [ 0 ] > V_253 -> V_260 - 1 )
return - V_17 ;
V_1 = V_253 -> V_267 [ V_264 -> V_42 . V_258 . V_261 [ 0 ] ] << V_253 -> V_256 ;
V_224 = V_253 -> V_224 << V_253 -> V_256 ;
if ( V_253 -> V_256 != V_253 -> V_257 ) {
if ( V_264 -> V_42 . V_258 . V_261 [ 1 ] > V_253 -> V_260 - 1 )
return - V_17 ;
V_1 |= V_253 -> V_267 [ V_264 -> V_42 . V_258 . V_261 [ 1 ] ] << V_253 -> V_257 ;
V_224 |= V_253 -> V_224 << V_253 -> V_257 ;
}
return F_156 ( V_5 , V_253 -> V_6 , V_224 , V_1 ) ;
}
int F_170 ( struct V_240 * V_245 ,
struct V_250 * V_251 )
{
struct V_252 * V_253 = (struct V_252 * ) V_245 -> V_254 ;
V_251 -> type = V_255 ;
V_251 -> V_18 = 1 ;
V_251 -> V_42 . V_258 . V_259 = V_253 -> V_260 ;
if ( V_251 -> V_42 . V_258 . V_261 > V_253 -> V_260 - 1 )
V_251 -> V_42 . V_258 . V_261 = V_253 -> V_260 - 1 ;
strcpy ( V_251 -> V_42 . V_258 . V_48 ,
V_253 -> V_262 [ V_251 -> V_42 . V_258 . V_261 ] ) ;
return 0 ;
}
int F_171 ( struct V_240 * V_245 ,
struct V_250 * V_251 )
{
int V_260 = V_245 -> V_254 ;
if ( V_260 == 1 && ! strstr ( V_245 -> V_268 . V_48 , L_67 ) )
V_251 -> type = V_269 ;
else
V_251 -> type = V_270 ;
V_251 -> V_18 = 1 ;
V_251 -> V_42 . integer . F_7 = 0 ;
V_251 -> V_42 . integer . V_260 = V_260 ;
return 0 ;
}
int F_172 ( struct V_240 * V_245 ,
struct V_250 * V_251 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_245 -> V_254 ;
int V_273 ;
if ( ! V_272 -> V_273 )
V_272 -> V_273 = V_272 -> V_260 ;
V_273 = V_272 -> V_273 ;
if ( V_273 == 1 && ! strstr ( V_245 -> V_268 . V_48 , L_67 ) )
V_251 -> type = V_269 ;
else
V_251 -> type = V_270 ;
V_251 -> V_18 = F_173 ( V_272 ) ? 2 : 1 ;
V_251 -> V_42 . integer . F_7 = 0 ;
V_251 -> V_42 . integer . V_260 = V_273 ;
return 0 ;
}
int F_174 ( struct V_240 * V_245 ,
struct V_263 * V_264 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_245 -> V_254 ;
struct V_4 * V_5 = F_166 ( V_245 ) ;
unsigned int V_6 = V_272 -> V_6 ;
unsigned int V_274 = V_272 -> V_275 ;
unsigned int V_276 = V_272 -> V_276 ;
unsigned int V_277 = V_272 -> V_277 ;
int V_260 = V_272 -> V_260 ;
unsigned int V_224 = ( 1 << F_175 ( V_260 ) ) - 1 ;
unsigned int V_278 = V_272 -> V_278 ;
V_264 -> V_42 . integer . V_42 [ 0 ] =
( F_4 ( V_5 , V_6 ) >> V_276 ) & V_224 ;
if ( V_278 )
V_264 -> V_42 . integer . V_42 [ 0 ] =
V_260 - V_264 -> V_42 . integer . V_42 [ 0 ] ;
if ( F_173 ( V_272 ) ) {
if ( V_6 == V_274 )
V_264 -> V_42 . integer . V_42 [ 1 ] =
( F_4 ( V_5 , V_6 ) >> V_277 ) & V_224 ;
else
V_264 -> V_42 . integer . V_42 [ 1 ] =
( F_4 ( V_5 , V_274 ) >> V_276 ) & V_224 ;
if ( V_278 )
V_264 -> V_42 . integer . V_42 [ 1 ] =
V_260 - V_264 -> V_42 . integer . V_42 [ 1 ] ;
}
return 0 ;
}
int F_176 ( struct V_240 * V_245 ,
struct V_263 * V_264 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_245 -> V_254 ;
struct V_4 * V_5 = F_166 ( V_245 ) ;
unsigned int V_6 = V_272 -> V_6 ;
unsigned int V_274 = V_272 -> V_275 ;
unsigned int V_276 = V_272 -> V_276 ;
unsigned int V_277 = V_272 -> V_277 ;
int V_260 = V_272 -> V_260 ;
unsigned int V_224 = ( 1 << F_175 ( V_260 ) ) - 1 ;
unsigned int V_278 = V_272 -> V_278 ;
int V_73 ;
bool V_279 = 0 ;
unsigned int V_280 = 0 ;
unsigned int V_1 , V_281 ;
V_1 = ( V_264 -> V_42 . integer . V_42 [ 0 ] & V_224 ) ;
if ( V_278 )
V_1 = V_260 - V_1 ;
V_281 = V_224 << V_276 ;
V_1 = V_1 << V_276 ;
if ( F_173 ( V_272 ) ) {
V_280 = ( V_264 -> V_42 . integer . V_42 [ 1 ] & V_224 ) ;
if ( V_278 )
V_280 = V_260 - V_280 ;
if ( V_6 == V_274 ) {
V_281 |= V_224 << V_277 ;
V_1 |= V_280 << V_277 ;
} else {
V_280 = V_280 << V_276 ;
V_279 = 1 ;
}
}
V_73 = F_156 ( V_5 , V_6 , V_281 , V_1 ) ;
if ( V_73 < 0 )
return V_73 ;
if ( V_279 )
V_73 = F_156 ( V_5 , V_274 , V_281 , V_280 ) ;
return V_73 ;
}
int F_177 ( struct V_240 * V_245 ,
struct V_263 * V_264 )
{
struct V_4 * V_5 = F_166 ( V_245 ) ;
struct V_271 * V_272 =
(struct V_271 * ) V_245 -> V_254 ;
unsigned int V_6 = V_272 -> V_6 ;
unsigned int V_274 = V_272 -> V_275 ;
unsigned int V_276 = V_272 -> V_276 ;
unsigned int V_277 = V_272 -> V_277 ;
int V_260 = V_272 -> V_260 ;
int F_7 = V_272 -> F_7 ;
int V_224 = ( 1 << ( F_175 ( F_7 + V_260 ) - 1 ) ) - 1 ;
V_264 -> V_42 . integer . V_42 [ 0 ] =
( ( F_4 ( V_5 , V_6 ) >> V_276 ) - F_7 ) & V_224 ;
if ( F_173 ( V_272 ) )
V_264 -> V_42 . integer . V_42 [ 1 ] =
( ( F_4 ( V_5 , V_274 ) >> V_277 ) - F_7 ) & V_224 ;
return 0 ;
}
int F_178 ( struct V_240 * V_245 ,
struct V_263 * V_264 )
{
struct V_4 * V_5 = F_166 ( V_245 ) ;
struct V_271 * V_272 =
(struct V_271 * ) V_245 -> V_254 ;
unsigned int V_6 = V_272 -> V_6 ;
unsigned int V_274 = V_272 -> V_275 ;
unsigned int V_276 = V_272 -> V_276 ;
unsigned int V_277 = V_272 -> V_277 ;
int V_260 = V_272 -> V_260 ;
int F_7 = V_272 -> F_7 ;
int V_224 = ( 1 << ( F_175 ( F_7 + V_260 ) - 1 ) ) - 1 ;
int V_73 = 0 ;
unsigned short V_1 , V_281 , V_280 = 0 ;
V_281 = V_224 << V_276 ;
V_1 = ( V_264 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & V_224 ;
V_1 = V_1 << V_276 ;
V_73 = F_156 ( V_5 , V_6 , V_281 , V_1 ) ;
if ( V_73 < 0 )
return V_73 ;
if ( F_173 ( V_272 ) ) {
V_281 = V_224 << V_277 ;
V_280 = ( V_264 -> V_42 . integer . V_42 [ 1 ] + F_7 ) & V_224 ;
V_280 = V_280 << V_277 ;
if ( F_156 ( V_5 , V_274 , V_281 , V_280 ) )
return V_73 ;
}
return 0 ;
}
int F_179 ( struct V_240 * V_245 ,
struct V_250 * V_251 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_245 -> V_254 ;
int V_273 ;
int F_7 = V_272 -> F_7 ;
if ( ! V_272 -> V_273 )
V_272 -> V_273 = V_272 -> V_260 ;
V_273 = V_272 -> V_273 ;
V_251 -> type = V_270 ;
V_251 -> V_18 = 2 ;
V_251 -> V_42 . integer . F_7 = 0 ;
V_251 -> V_42 . integer . V_260 = V_273 - F_7 ;
return 0 ;
}
int F_180 ( struct V_240 * V_245 ,
struct V_263 * V_264 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_245 -> V_254 ;
struct V_4 * V_5 = F_166 ( V_245 ) ;
unsigned int V_6 = V_272 -> V_6 ;
int F_7 = V_272 -> F_7 ;
int V_1 = F_4 ( V_5 , V_6 ) ;
V_264 -> V_42 . integer . V_42 [ 0 ] =
( ( signed char ) ( V_1 & 0xff ) ) - F_7 ;
V_264 -> V_42 . integer . V_42 [ 1 ] =
( ( signed char ) ( ( V_1 >> 8 ) & 0xff ) ) - F_7 ;
return 0 ;
}
int F_181 ( struct V_240 * V_245 ,
struct V_263 * V_264 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_245 -> V_254 ;
struct V_4 * V_5 = F_166 ( V_245 ) ;
unsigned int V_6 = V_272 -> V_6 ;
int F_7 = V_272 -> F_7 ;
unsigned int V_1 ;
V_1 = ( V_264 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & 0xff ;
V_1 |= ( ( V_264 -> V_42 . integer . V_42 [ 1 ] + F_7 ) & 0xff ) << 8 ;
return F_156 ( V_5 , V_6 , 0xffff , V_1 ) ;
}
int F_182 ( struct V_240 * V_245 ,
struct V_250 * V_251 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_245 -> V_254 ;
int V_273 ;
int F_7 = V_272 -> F_7 ;
if ( ! V_272 -> V_273 )
V_272 -> V_273 = V_272 -> V_260 ;
V_273 = V_272 -> V_273 ;
V_251 -> type = V_270 ;
V_251 -> V_18 = 1 ;
V_251 -> V_42 . integer . F_7 = 0 ;
V_251 -> V_42 . integer . V_260 = V_273 - F_7 ;
return 0 ;
}
int F_183 ( struct V_240 * V_245 ,
struct V_263 * V_264 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_245 -> V_254 ;
struct V_4 * V_5 = F_166 ( V_245 ) ;
unsigned int V_6 = V_272 -> V_6 ;
unsigned int V_276 = V_272 -> V_276 ;
int F_7 = V_272 -> F_7 ;
int V_260 = V_272 -> V_260 ;
unsigned int V_224 = ( 1 << F_175 ( V_260 ) ) - 1 ;
unsigned int V_278 = V_272 -> V_278 ;
unsigned int V_1 , V_281 ;
V_1 = ( ( V_264 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & V_224 ) ;
if ( V_278 )
V_1 = V_260 - V_1 ;
V_281 = V_224 << V_276 ;
V_1 = V_1 << V_276 ;
return F_156 ( V_5 , V_6 , V_281 , V_1 ) ;
}
int F_184 ( struct V_240 * V_245 ,
struct V_263 * V_264 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_245 -> V_254 ;
struct V_4 * V_5 = F_166 ( V_245 ) ;
unsigned int V_6 = V_272 -> V_6 ;
unsigned int V_276 = V_272 -> V_276 ;
int F_7 = V_272 -> F_7 ;
int V_260 = V_272 -> V_260 ;
unsigned int V_224 = ( 1 << F_175 ( V_260 ) ) - 1 ;
unsigned int V_278 = V_272 -> V_278 ;
V_264 -> V_42 . integer . V_42 [ 0 ] =
( F_4 ( V_5 , V_6 ) >> V_276 ) & V_224 ;
if ( V_278 )
V_264 -> V_42 . integer . V_42 [ 0 ] =
V_260 - V_264 -> V_42 . integer . V_42 [ 0 ] ;
V_264 -> V_42 . integer . V_42 [ 0 ] =
V_264 -> V_42 . integer . V_42 [ 0 ] - F_7 ;
return 0 ;
}
int F_185 ( struct V_4 * V_5 ,
const char * V_48 , int V_260 )
{
struct V_77 * V_46 = V_5 -> V_46 -> V_77 ;
struct V_240 * V_282 ;
struct V_271 * V_272 ;
int V_186 = 0 ;
int V_14 = - V_17 ;
if ( F_186 ( ! V_48 || V_260 <= 0 ) )
return - V_17 ;
F_34 (kctl, &card->controls, list) {
if ( ! strncmp ( V_282 -> V_268 . V_48 , V_48 , sizeof( V_282 -> V_268 . V_48 ) ) ) {
V_186 = 1 ;
break;
}
}
if ( V_186 ) {
V_272 = (struct V_271 * ) V_282 -> V_254 ;
if ( V_260 <= V_272 -> V_260 ) {
V_272 -> V_273 = V_260 ;
V_14 = 0 ;
}
}
return V_14 ;
}
int F_187 ( struct V_240 * V_245 ,
struct V_250 * V_251 )
{
struct V_4 * V_5 = F_166 ( V_245 ) ;
struct V_283 * V_179 = ( void * ) V_245 -> V_254 ;
V_251 -> type = V_284 ;
V_251 -> V_18 = V_179 -> V_285 * V_5 -> V_286 ;
return 0 ;
}
int F_188 ( struct V_240 * V_245 ,
struct V_263 * V_264 )
{
struct V_283 * V_179 = ( void * ) V_245 -> V_254 ;
struct V_4 * V_5 = F_166 ( V_245 ) ;
int V_14 ;
if ( V_5 -> V_105 )
V_14 = F_189 ( V_5 -> V_106 , V_179 -> V_287 ,
V_264 -> V_42 . V_288 . V_222 ,
V_179 -> V_285 * V_5 -> V_286 ) ;
else
V_14 = - V_17 ;
if ( V_14 == 0 && V_179 -> V_224 ) {
switch ( V_5 -> V_286 ) {
case 1 :
V_264 -> V_42 . V_288 . V_222 [ 0 ] &= ~ V_179 -> V_224 ;
break;
case 2 :
( ( V_289 * ) ( & V_264 -> V_42 . V_288 . V_222 ) ) [ 0 ]
&= ~ V_179 -> V_224 ;
break;
case 4 :
( ( V_290 * ) ( & V_264 -> V_42 . V_288 . V_222 ) ) [ 0 ]
&= ~ V_179 -> V_224 ;
break;
default:
return - V_17 ;
}
}
return V_14 ;
}
int F_190 ( struct V_240 * V_245 ,
struct V_263 * V_264 )
{
struct V_283 * V_179 = ( void * ) V_245 -> V_254 ;
struct V_4 * V_5 = F_166 ( V_245 ) ;
int V_14 , V_8 ;
unsigned int V_1 ;
void * V_222 ;
if ( ! V_5 -> V_105 )
return - V_17 ;
V_222 = V_264 -> V_42 . V_288 . V_222 ;
V_8 = V_179 -> V_285 * V_5 -> V_286 ;
if ( V_179 -> V_224 ) {
V_14 = F_191 ( V_5 -> V_106 , V_179 -> V_287 , & V_1 ) ;
if ( V_14 != 0 )
return V_14 ;
V_1 &= V_179 -> V_224 ;
V_222 = F_192 ( V_222 , V_8 , V_37 ) ;
if ( ! V_222 )
return - V_38 ;
switch ( V_5 -> V_286 ) {
case 1 :
( ( V_291 * ) V_222 ) [ 0 ] &= ~ V_179 -> V_224 ;
( ( V_291 * ) V_222 ) [ 0 ] |= V_1 ;
break;
case 2 :
( ( V_289 * ) V_222 ) [ 0 ] &= F_193 ( ~ V_179 -> V_224 ) ;
( ( V_289 * ) V_222 ) [ 0 ] |= F_193 ( V_1 ) ;
break;
case 4 :
( ( V_290 * ) V_222 ) [ 0 ] &= F_194 ( ~ V_179 -> V_224 ) ;
( ( V_290 * ) V_222 ) [ 0 ] |= F_194 ( V_1 ) ;
break;
default:
return - V_17 ;
}
}
V_14 = F_195 ( V_5 -> V_106 , V_179 -> V_287 ,
V_222 , V_8 ) ;
if ( V_179 -> V_224 )
F_16 ( V_222 ) ;
return V_14 ;
}
int F_196 ( struct V_240 * V_245 ,
struct V_250 * V_251 )
{
struct V_292 * V_272 =
(struct V_292 * ) V_245 -> V_254 ;
V_251 -> type = V_270 ;
V_251 -> V_18 = 1 ;
V_251 -> V_42 . integer . F_7 = V_272 -> F_7 ;
V_251 -> V_42 . integer . V_260 = V_272 -> V_260 ;
return 0 ;
}
int F_197 ( struct V_240 * V_245 ,
struct V_263 * V_264 )
{
struct V_292 * V_272 =
(struct V_292 * ) V_245 -> V_254 ;
struct V_4 * V_5 = F_166 ( V_245 ) ;
unsigned int V_293 = V_272 -> V_293 ;
unsigned int V_294 = V_272 -> V_294 ;
unsigned int V_295 = V_5 -> V_10 -> V_13 * V_296 ;
unsigned int V_297 = ( 1 << V_295 ) - 1 ;
unsigned int V_278 = V_272 -> V_278 ;
unsigned long V_224 = ( 1UL << V_272 -> V_298 ) - 1 ;
long F_7 = V_272 -> F_7 ;
long V_260 = V_272 -> V_260 ;
long V_1 = 0 ;
unsigned long V_299 ;
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_294 ; V_3 ++ ) {
V_299 = F_4 ( V_5 , V_293 + V_3 ) & V_297 ;
V_1 |= V_299 << ( V_295 * ( V_294 - V_3 - 1 ) ) ;
}
V_1 &= V_224 ;
if ( F_7 < 0 && V_1 > V_260 )
V_1 |= ~ V_224 ;
if ( V_278 )
V_1 = V_260 - V_1 ;
V_264 -> V_42 . integer . V_42 [ 0 ] = V_1 ;
return 0 ;
}
int F_198 ( struct V_240 * V_245 ,
struct V_263 * V_264 )
{
struct V_292 * V_272 =
(struct V_292 * ) V_245 -> V_254 ;
struct V_4 * V_5 = F_166 ( V_245 ) ;
unsigned int V_293 = V_272 -> V_293 ;
unsigned int V_294 = V_272 -> V_294 ;
unsigned int V_295 = V_5 -> V_10 -> V_13 * V_296 ;
unsigned int V_297 = ( 1 << V_295 ) - 1 ;
unsigned int V_278 = V_272 -> V_278 ;
unsigned long V_224 = ( 1UL << V_272 -> V_298 ) - 1 ;
long V_260 = V_272 -> V_260 ;
long V_1 = V_264 -> V_42 . integer . V_42 [ 0 ] ;
unsigned int V_3 , V_299 , V_300 ;
int V_73 ;
if ( V_278 )
V_1 = V_260 - V_1 ;
V_1 &= V_224 ;
for ( V_3 = 0 ; V_3 < V_294 ; V_3 ++ ) {
V_299 = ( V_1 >> ( V_295 * ( V_294 - V_3 - 1 ) ) ) & V_297 ;
V_300 = ( V_224 >> ( V_295 * ( V_294 - V_3 - 1 ) ) ) & V_297 ;
V_73 = F_156 ( V_5 , V_293 + V_3 ,
V_300 , V_299 ) ;
if ( V_73 < 0 )
return V_73 ;
}
return 0 ;
}
int F_199 ( struct V_240 * V_245 ,
struct V_263 * V_264 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_245 -> V_254 ;
struct V_4 * V_5 = F_166 ( V_245 ) ;
unsigned int V_6 = V_272 -> V_6 ;
unsigned int V_276 = V_272 -> V_276 ;
unsigned int V_224 = 1 << V_276 ;
unsigned int V_278 = V_272 -> V_278 != 0 ;
unsigned int V_1 = F_4 ( V_5 , V_6 ) & V_224 ;
if ( V_276 != 0 && V_1 != 0 )
V_1 = V_1 >> V_276 ;
V_264 -> V_42 . V_258 . V_261 [ 0 ] = V_1 ^ V_278 ;
return 0 ;
}
int F_200 ( struct V_240 * V_245 ,
struct V_263 * V_264 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_245 -> V_254 ;
struct V_4 * V_5 = F_166 ( V_245 ) ;
unsigned int V_6 = V_272 -> V_6 ;
unsigned int V_276 = V_272 -> V_276 ;
unsigned int V_224 = 1 << V_276 ;
unsigned int V_278 = V_272 -> V_278 != 0 ;
unsigned int V_301 = V_264 -> V_42 . V_258 . V_261 [ 0 ] != 0 ;
unsigned int V_302 = ( V_301 ^ V_278 ) ? V_224 : 0 ;
unsigned int V_280 = ( V_301 ^ V_278 ) ? 0 : V_224 ;
int V_73 ;
V_73 = F_156 ( V_5 , V_6 , V_224 , V_302 ) ;
if ( V_73 < 0 )
return V_73 ;
V_73 = F_156 ( V_5 , V_6 , V_224 , V_280 ) ;
return V_73 ;
}
int F_201 ( struct V_57 * V_58 , int V_303 ,
unsigned int V_304 , int V_305 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_88 -> V_306 )
return V_58 -> V_10 -> V_88 -> V_306 ( V_58 , V_303 , V_304 , V_305 ) ;
else if ( V_58 -> V_5 && V_58 -> V_5 -> V_10 -> V_306 )
return V_58 -> V_5 -> V_10 -> V_306 ( V_58 -> V_5 , V_303 , 0 ,
V_304 , V_305 ) ;
else
return - V_17 ;
}
int F_202 ( struct V_4 * V_5 , int V_303 ,
int V_307 , unsigned int V_304 , int V_305 )
{
if ( V_5 -> V_10 -> V_306 )
return V_5 -> V_10 -> V_306 ( V_5 , V_303 , V_307 ,
V_304 , V_305 ) ;
else
return - V_17 ;
}
int F_203 ( struct V_57 * V_58 ,
int V_308 , int div )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_88 -> V_309 )
return V_58 -> V_10 -> V_88 -> V_309 ( V_58 , V_308 , div ) ;
else
return - V_17 ;
}
int F_204 ( struct V_57 * V_58 , int V_310 , int V_307 ,
unsigned int V_311 , unsigned int V_312 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_88 -> V_313 )
return V_58 -> V_10 -> V_88 -> V_313 ( V_58 , V_310 , V_307 ,
V_311 , V_312 ) ;
else if ( V_58 -> V_5 && V_58 -> V_5 -> V_10 -> V_313 )
return V_58 -> V_5 -> V_10 -> V_313 ( V_58 -> V_5 , V_310 , V_307 ,
V_311 , V_312 ) ;
else
return - V_17 ;
}
int F_205 ( struct V_4 * V_5 , int V_310 , int V_307 ,
unsigned int V_311 , unsigned int V_312 )
{
if ( V_5 -> V_10 -> V_313 )
return V_5 -> V_10 -> V_313 ( V_5 , V_310 , V_307 ,
V_311 , V_312 ) ;
else
return - V_17 ;
}
int F_127 ( struct V_57 * V_58 , unsigned int V_314 )
{
if ( V_58 -> V_10 == NULL )
return - V_17 ;
if ( V_58 -> V_10 -> V_88 -> V_315 == NULL )
return - V_200 ;
return V_58 -> V_10 -> V_88 -> V_315 ( V_58 , V_314 ) ;
}
int F_206 ( struct V_57 * V_58 ,
unsigned int V_316 , unsigned int V_317 , int V_318 , int V_319 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_88 -> V_320 )
return V_58 -> V_10 -> V_88 -> V_320 ( V_58 , V_316 , V_317 ,
V_318 , V_319 ) ;
else
return - V_17 ;
}
int F_207 ( struct V_57 * V_58 ,
unsigned int V_321 , unsigned int * V_322 ,
unsigned int V_323 , unsigned int * V_324 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_88 -> V_325 )
return V_58 -> V_10 -> V_88 -> V_325 ( V_58 , V_321 , V_322 ,
V_323 , V_324 ) ;
else
return - V_17 ;
}
int F_208 ( struct V_57 * V_58 , int V_326 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_88 -> V_327 )
return V_58 -> V_10 -> V_88 -> V_327 ( V_58 , V_326 ) ;
else
return - V_17 ;
}
int F_209 ( struct V_57 * V_58 , int V_328 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_88 -> V_89 )
return V_58 -> V_10 -> V_88 -> V_89 ( V_58 , V_328 ) ;
else
return - V_200 ;
}
int F_136 ( struct V_59 * V_46 )
{
int V_3 , V_14 ;
if ( ! V_46 -> V_48 || ! V_46 -> V_27 )
return - V_17 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ ) {
struct V_117 * V_329 = & V_46 -> V_64 [ V_3 ] ;
if ( ! ! V_329 -> V_125 == ! ! V_329 -> V_124 ) {
F_67 ( V_46 -> V_27 ,
L_68 ,
V_329 -> V_48 ) ;
return - V_17 ;
}
if ( ! V_329 -> V_126 ) {
F_67 ( V_46 -> V_27 , L_69 ,
V_329 -> V_48 ) ;
return - V_17 ;
}
if ( V_329 -> V_118 && V_329 -> V_127 ) {
F_67 ( V_46 -> V_27 ,
L_70 , V_329 -> V_48 ) ;
return - V_17 ;
}
if ( V_329 -> V_121 && V_329 -> V_119 ) {
F_67 ( V_46 -> V_27 ,
L_71 ,
V_329 -> V_48 ) ;
return - V_17 ;
}
if ( ! V_329 -> V_122 &&
! ( V_329 -> V_121 || V_329 -> V_119 ) ) {
F_67 ( V_46 -> V_27 ,
L_72 ,
V_329 -> V_48 ) ;
return - V_17 ;
}
}
F_97 ( V_46 -> V_27 , V_46 ) ;
F_210 ( V_46 ) ;
F_38 ( V_46 ) ;
V_46 -> V_31 = F_211 ( V_46 -> V_27 ,
sizeof( struct V_30 ) *
( V_46 -> V_66 + V_46 -> V_194 ) ,
V_37 ) ;
if ( V_46 -> V_31 == NULL )
return - V_38 ;
V_46 -> V_83 = 0 ;
V_46 -> V_163 = & V_46 -> V_31 [ V_46 -> V_66 ] ;
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ )
V_46 -> V_31 [ V_3 ] . V_64 = & V_46 -> V_64 [ V_3 ] ;
F_99 ( & V_46 -> V_155 ) ;
F_99 ( & V_46 -> V_330 ) ;
V_46 -> V_212 = 0 ;
F_98 ( & V_46 -> V_191 ) ;
F_98 ( & V_46 -> V_331 ) ;
V_14 = F_120 ( V_46 ) ;
if ( V_14 != 0 )
F_40 ( V_46 ) ;
return V_14 ;
}
int F_139 ( struct V_59 * V_46 )
{
if ( V_46 -> V_212 )
F_137 ( V_46 ) ;
F_42 ( V_46 -> V_27 , L_73 , V_46 -> V_48 ) ;
return 0 ;
}
static char * F_212 ( struct V_26 * V_27 , int * V_268 )
{
char * V_186 , V_48 [ V_332 ] ;
int V_333 , V_334 ;
if ( F_69 ( V_27 ) == NULL )
return NULL ;
F_213 ( V_48 , F_69 ( V_27 ) , V_332 ) ;
V_186 = strstr ( V_48 , V_27 -> V_10 -> V_48 ) ;
if ( V_186 ) {
if ( sscanf ( & V_186 [ strlen ( V_27 -> V_10 -> V_48 ) ] , L_74 , V_268 ) == 1 ) {
if ( * V_268 == - 1 )
V_186 [ strlen ( V_27 -> V_10 -> V_48 ) ] = '\0' ;
}
} else {
if ( sscanf ( V_48 , L_75 , & V_333 , & V_334 ) == 2 ) {
char V_335 [ V_332 ] ;
* V_268 = ( ( V_333 & 0xffff ) << 16 ) + V_334 ;
snprintf ( V_335 , V_332 , L_76 , V_27 -> V_10 -> V_48 , V_48 ) ;
F_213 ( V_48 , V_335 , V_332 ) ;
} else
* V_268 = 0 ;
}
return F_214 ( V_48 , V_37 ) ;
}
static inline char * F_215 ( struct V_26 * V_27 ,
struct V_85 * V_336 )
{
if ( V_336 -> V_48 == NULL ) {
F_71 ( L_77 ,
F_69 ( V_27 ) ) ;
return NULL ;
}
return F_214 ( V_336 -> V_48 , V_37 ) ;
}
int F_216 ( struct V_26 * V_27 ,
struct V_85 * V_336 )
{
struct V_4 * V_5 ;
struct V_57 * V_58 ;
F_42 ( V_27 , L_78 , F_69 ( V_27 ) ) ;
V_58 = F_95 ( sizeof( struct V_57 ) , V_37 ) ;
if ( V_58 == NULL )
return - V_38 ;
V_58 -> V_48 = F_212 ( V_27 , & V_58 -> V_268 ) ;
if ( V_58 -> V_48 == NULL ) {
F_16 ( V_58 ) ;
return - V_38 ;
}
V_58 -> V_27 = V_27 ;
V_58 -> V_10 = V_336 ;
V_58 -> V_53 . V_27 = V_27 ;
if ( ! V_58 -> V_10 -> V_88 )
V_58 -> V_10 -> V_88 = & V_337 ;
F_149 ( & V_338 ) ;
F_34 (codec, &codec_list, list) {
if ( V_5 -> V_27 == V_27 ) {
F_42 ( V_27 , L_79 ,
V_58 -> V_48 , V_5 -> V_48 ) ;
V_58 -> V_5 = V_5 ;
break;
}
}
if ( ! V_58 -> V_5 )
V_58 -> V_53 . V_103 = 1 ;
F_89 ( & V_58 -> V_155 , & V_339 ) ;
F_132 ( & V_338 ) ;
F_217 ( L_80 , V_58 -> V_48 ) ;
return 0 ;
}
void F_218 ( struct V_26 * V_27 )
{
struct V_57 * V_58 ;
F_34 (dai, &dai_list, list) {
if ( V_27 == V_58 -> V_27 )
goto V_186;
}
return;
V_186:
F_149 ( & V_338 ) ;
F_73 ( & V_58 -> V_155 ) ;
F_132 ( & V_338 ) ;
F_217 ( L_81 , V_58 -> V_48 ) ;
F_16 ( V_58 -> V_48 ) ;
F_16 ( V_58 ) ;
}
int F_219 ( struct V_26 * V_27 ,
struct V_85 * V_336 , T_1 V_18 )
{
struct V_4 * V_5 ;
struct V_57 * V_58 ;
int V_3 , V_14 = 0 ;
F_42 ( V_27 , L_82 , F_69 ( V_27 ) , V_18 ) ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ ) {
V_58 = F_95 ( sizeof( struct V_57 ) , V_37 ) ;
if ( V_58 == NULL ) {
V_14 = - V_38 ;
goto V_73;
}
V_58 -> V_48 = F_215 ( V_27 , & V_336 [ V_3 ] ) ;
if ( V_58 -> V_48 == NULL ) {
F_16 ( V_58 ) ;
V_14 = - V_17 ;
goto V_73;
}
V_58 -> V_27 = V_27 ;
V_58 -> V_10 = & V_336 [ V_3 ] ;
if ( V_58 -> V_10 -> V_268 )
V_58 -> V_268 = V_58 -> V_10 -> V_268 ;
else
V_58 -> V_268 = V_3 ;
V_58 -> V_53 . V_27 = V_27 ;
if ( ! V_58 -> V_10 -> V_88 )
V_58 -> V_10 -> V_88 = & V_337 ;
F_149 ( & V_338 ) ;
F_34 (codec, &codec_list, list) {
if ( V_5 -> V_27 == V_27 ) {
F_42 ( V_27 , L_79 ,
V_58 -> V_48 , V_5 -> V_48 ) ;
V_58 -> V_5 = V_5 ;
break;
}
}
if ( ! V_58 -> V_5 )
V_58 -> V_53 . V_103 = 1 ;
F_89 ( & V_58 -> V_155 , & V_339 ) ;
F_132 ( & V_338 ) ;
F_217 ( L_80 , V_58 -> V_48 ) ;
}
return 0 ;
V_73:
for ( V_3 -- ; V_3 >= 0 ; V_3 -- )
F_218 ( V_27 ) ;
return V_14 ;
}
void F_220 ( struct V_26 * V_27 , T_1 V_18 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ )
F_218 ( V_27 ) ;
}
int F_221 ( struct V_26 * V_27 ,
struct V_157 * V_340 )
{
struct V_54 * V_55 ;
F_42 ( V_27 , L_83 , F_69 ( V_27 ) ) ;
V_55 = F_95 ( sizeof( struct V_54 ) , V_37 ) ;
if ( V_55 == NULL )
return - V_38 ;
V_55 -> V_48 = F_212 ( V_27 , & V_55 -> V_268 ) ;
if ( V_55 -> V_48 == NULL ) {
F_16 ( V_55 ) ;
return - V_38 ;
}
V_55 -> V_27 = V_27 ;
V_55 -> V_10 = V_340 ;
V_55 -> V_53 . V_27 = V_27 ;
V_55 -> V_53 . V_55 = V_55 ;
V_55 -> V_53 . V_341 = V_340 -> V_341 ;
F_98 ( & V_55 -> V_191 ) ;
F_149 ( & V_338 ) ;
F_89 ( & V_55 -> V_155 , & V_342 ) ;
F_132 ( & V_338 ) ;
F_217 ( L_84 , V_55 -> V_48 ) ;
return 0 ;
}
void F_222 ( struct V_26 * V_27 )
{
struct V_54 * V_55 ;
F_34 (platform, &platform_list, list) {
if ( V_27 == V_55 -> V_27 )
goto V_186;
}
return;
V_186:
F_149 ( & V_338 ) ;
F_73 ( & V_55 -> V_155 ) ;
F_132 ( & V_338 ) ;
F_217 ( L_85 , V_55 -> V_48 ) ;
F_16 ( V_55 -> V_48 ) ;
F_16 ( V_55 ) ;
}
static void F_223 ( struct V_343 * V_65 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_128 ( V_344 ) ; V_3 ++ )
if ( V_65 -> V_233 & V_344 [ V_3 ] )
V_65 -> V_233 |= V_344 [ V_3 ] ;
}
int F_224 ( struct V_26 * V_27 ,
const struct V_143 * V_345 ,
struct V_85 * V_336 ,
int V_346 )
{
T_1 V_347 ;
struct V_4 * V_5 ;
int V_14 , V_3 ;
F_42 ( V_27 , L_86 , F_69 ( V_27 ) ) ;
V_5 = F_95 ( sizeof( struct V_4 ) , V_37 ) ;
if ( V_5 == NULL )
return - V_38 ;
V_5 -> V_48 = F_212 ( V_27 , & V_5 -> V_268 ) ;
if ( V_5 -> V_48 == NULL ) {
F_16 ( V_5 ) ;
return - V_38 ;
}
if ( V_345 -> V_188 )
V_5 -> V_188 = V_345 -> V_188 ;
else
V_5 -> V_188 = V_348 ;
V_5 -> V_149 = V_345 -> V_149 ;
V_5 -> V_218 = V_345 -> V_218 ;
V_5 -> V_215 = V_345 -> V_215 ;
V_5 -> V_216 = V_345 -> V_216 ;
V_5 -> V_217 = V_345 -> V_217 ;
V_5 -> V_349 = V_345 -> V_349 ;
V_5 -> V_53 . V_98 = V_104 ;
V_5 -> V_53 . V_27 = V_27 ;
V_5 -> V_53 . V_5 = V_5 ;
V_5 -> V_53 . V_350 = V_345 -> V_350 ;
V_5 -> V_53 . V_341 = V_345 -> V_341 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_10 = V_345 ;
V_5 -> V_346 = V_346 ;
F_98 ( & V_5 -> V_191 ) ;
if ( V_345 -> V_11 && V_345 -> V_13 ) {
V_347 = V_345 -> V_11 * V_345 -> V_13 ;
V_5 -> V_347 = V_347 ;
if ( V_345 -> V_351 ) {
V_5 -> V_352 = F_192 ( V_345 -> V_351 ,
V_347 , V_37 ) ;
if ( ! V_5 -> V_352 ) {
V_14 = - V_38 ;
goto V_353;
}
}
}
if ( V_345 -> V_354 && V_345 -> V_355 ) {
if ( ! V_5 -> V_215 )
V_5 -> V_215 = V_356 ;
if ( ! V_5 -> V_216 )
V_5 -> V_216 = V_357 ;
if ( ! V_5 -> V_217 )
V_5 -> V_217 = V_358 ;
}
for ( V_3 = 0 ; V_3 < V_346 ; V_3 ++ ) {
F_223 ( & V_336 [ V_3 ] . V_359 ) ;
F_223 ( & V_336 [ V_3 ] . V_360 ) ;
}
F_149 ( & V_338 ) ;
F_89 ( & V_5 -> V_155 , & V_361 ) ;
F_132 ( & V_338 ) ;
if ( V_346 ) {
V_14 = F_219 ( V_27 , V_336 , V_346 ) ;
if ( V_14 < 0 )
F_67 ( V_5 -> V_27 , L_87 ,
V_14 ) ;
}
F_217 ( L_88 , V_5 -> V_48 ) ;
return 0 ;
V_353:
F_16 ( V_5 -> V_48 ) ;
F_16 ( V_5 ) ;
return V_14 ;
}
void F_225 ( struct V_26 * V_27 )
{
struct V_4 * V_5 ;
int V_3 ;
F_34 (codec, &codec_list, list) {
if ( V_27 == V_5 -> V_27 )
goto V_186;
}
return;
V_186:
if ( V_5 -> V_346 )
for ( V_3 = 0 ; V_3 < V_5 -> V_346 ; V_3 ++ )
F_218 ( V_27 ) ;
F_149 ( & V_338 ) ;
F_73 ( & V_5 -> V_155 ) ;
F_132 ( & V_338 ) ;
F_217 ( L_89 , V_5 -> V_48 ) ;
F_226 ( V_5 ) ;
F_16 ( V_5 -> V_352 ) ;
F_16 ( V_5 -> V_48 ) ;
F_16 ( V_5 ) ;
}
int F_227 ( struct V_59 * V_46 ,
const char * V_362 )
{
struct V_363 * V_364 = V_46 -> V_27 -> V_120 ;
int V_14 ;
V_14 = F_228 ( V_364 , V_362 , 0 , & V_46 -> V_48 ) ;
if ( V_14 < 0 && V_14 != - V_17 ) {
F_67 ( V_46 -> V_27 ,
L_90 ,
V_362 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
int F_229 ( struct V_59 * V_46 ,
const char * V_362 )
{
struct V_363 * V_364 = V_46 -> V_27 -> V_120 ;
int V_365 ;
struct V_366 * V_367 ;
int V_3 , V_14 ;
V_365 = F_230 ( V_364 , V_362 ) ;
if ( V_365 < 0 || V_365 & 1 ) {
F_67 ( V_46 -> V_27 ,
L_91 ,
V_362 ) ;
return - V_17 ;
}
V_365 /= 2 ;
if ( ! V_365 ) {
F_67 ( V_46 -> V_27 ,
L_92 ,
V_362 ) ;
return - V_17 ;
}
V_367 = F_211 ( V_46 -> V_27 , V_365 * sizeof( * V_367 ) ,
V_37 ) ;
if ( ! V_367 ) {
F_67 ( V_46 -> V_27 ,
L_93 ) ;
return - V_17 ;
}
for ( V_3 = 0 ; V_3 < V_365 ; V_3 ++ ) {
V_14 = F_228 ( V_364 , V_362 ,
2 * V_3 , & V_367 [ V_3 ] . V_368 ) ;
if ( V_14 ) {
F_67 ( V_46 -> V_27 ,
L_94 ,
V_362 , 2 * V_3 , V_14 ) ;
F_16 ( V_367 ) ;
return - V_17 ;
}
V_14 = F_228 ( V_364 , V_362 ,
( 2 * V_3 ) + 1 , & V_367 [ V_3 ] . V_307 ) ;
if ( V_14 ) {
F_67 ( V_46 -> V_27 ,
L_94 ,
V_362 , ( 2 * V_3 ) + 1 , V_14 ) ;
F_16 ( V_367 ) ;
return - V_17 ;
}
}
V_46 -> V_154 = V_365 ;
V_46 -> V_153 = V_367 ;
return 0 ;
}
static int T_5 F_231 ( void )
{
#ifdef F_103
V_60 = F_24 ( L_95 , NULL ) ;
if ( F_232 ( V_60 ) || ! V_60 ) {
F_107 ( L_96 ) ;
V_60 = NULL ;
}
if ( ! F_27 ( L_97 , 0444 , V_60 , NULL ,
& V_369 ) )
F_107 ( L_98 ) ;
if ( ! F_27 ( L_99 , 0444 , V_60 , NULL ,
& V_370 ) )
F_107 ( L_100 ) ;
if ( ! F_27 ( L_101 , 0444 , V_60 , NULL ,
& V_371 ) )
F_107 ( L_102 ) ;
#endif
F_233 () ;
return F_234 ( & V_372 ) ;
}
static void T_6 F_235 ( void )
{
F_236 () ;
#ifdef F_103
F_30 ( V_60 ) ;
#endif
F_237 ( & V_372 ) ;
}
