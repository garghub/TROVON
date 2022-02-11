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
F_25 ( V_5 -> V_27 , L_4
L_5 ) ;
return;
}
F_26 ( L_6 , 0444 , V_5 -> V_47 ,
& V_5 -> V_49 ) ;
F_26 ( L_7 , 0444 , V_5 -> V_47 ,
& V_5 -> V_50 ) ;
V_5 -> V_51 = F_27 ( L_8 , 0644 ,
V_5 -> V_47 ,
V_5 , & V_52 ) ;
if ( ! V_5 -> V_51 )
F_25 ( V_5 -> V_27 , L_9
L_10 ) ;
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
L_11 ) ;
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
V_8 = snprintf ( V_7 + V_14 , V_25 - V_14 , L_12 ,
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
V_8 = snprintf ( V_7 + V_14 , V_25 - V_14 , L_12 , V_58 -> V_48 ) ;
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
V_8 = snprintf ( V_7 + V_14 , V_25 - V_14 , L_12 ,
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
L_13 ) ;
return;
}
V_46 -> V_61 = F_39 ( L_14 , 0644 ,
V_46 -> V_45 ,
& V_46 -> V_62 ) ;
if ( ! V_46 -> V_61 )
F_25 ( V_46 -> V_27 ,
L_15 ) ;
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
F_42 ( V_46 -> V_27 , L_16 , V_64 ) ;
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
F_42 ( V_46 -> V_27 , L_17 , V_64 ) ;
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
F_48 ( & V_5 -> V_71 -> V_27 , L_18 ,
V_5 -> V_46 -> V_77 -> V_78 , 0 , V_5 -> V_48 ) ;
V_73 = F_49 ( & V_5 -> V_71 -> V_27 ) ;
if ( V_73 < 0 ) {
F_50 ( V_5 -> V_27 , L_19 ) ;
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
if ( F_52 ( & V_46 -> V_79 ) )
return 0 ;
F_53 ( V_46 -> V_77 ) ;
F_54 ( V_46 -> V_77 , V_80 ) ;
F_55 ( V_46 -> V_77 ) ;
F_56 ( V_46 -> V_77 , V_81 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_82 ; V_3 ++ ) {
struct V_57 * V_58 = V_46 -> V_31 [ V_3 ] . V_83 ;
struct V_84 * V_85 = V_58 -> V_10 ;
if ( V_46 -> V_31 [ V_3 ] . V_64 -> V_86 )
continue;
if ( V_85 -> V_87 -> V_88 && V_58 -> V_89 )
V_85 -> V_87 -> V_88 ( V_58 , 1 ) ;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_82 ; V_3 ++ ) {
if ( V_46 -> V_31 [ V_3 ] . V_64 -> V_86 )
continue;
F_57 ( V_46 -> V_31 [ V_3 ] . V_68 ) ;
}
if ( V_46 -> V_90 )
V_46 -> V_90 ( V_46 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_82 ; V_3 ++ ) {
struct V_57 * V_91 = V_46 -> V_31 [ V_3 ] . V_91 ;
struct V_54 * V_55 = V_46 -> V_31 [ V_3 ] . V_55 ;
if ( V_46 -> V_31 [ V_3 ] . V_64 -> V_86 )
continue;
if ( V_91 -> V_10 -> V_92 && ! V_91 -> V_10 -> V_93 )
V_91 -> V_10 -> V_92 ( V_91 ) ;
if ( V_55 -> V_10 -> V_92 && ! V_55 -> V_94 ) {
V_55 -> V_10 -> V_92 ( V_91 ) ;
V_55 -> V_94 = 1 ;
}
}
for ( V_3 = 0 ; V_3 < V_46 -> V_82 ; V_3 ++ ) {
F_58 ( & V_46 -> V_31 [ V_3 ] . V_95 ) ;
V_46 -> V_31 [ V_3 ] . V_5 -> V_53 . V_96 = V_46 -> V_31 [ V_3 ] . V_5 -> V_53 . V_97 ;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_82 ; V_3 ++ ) {
if ( V_46 -> V_31 [ V_3 ] . V_64 -> V_86 )
continue;
F_59 ( & V_46 -> V_31 [ V_3 ] ,
V_98 ,
V_99 ) ;
F_59 ( & V_46 -> V_31 [ V_3 ] ,
V_100 ,
V_99 ) ;
}
F_60 ( & V_46 -> V_53 ) ;
F_61 ( & V_46 -> V_53 ) ;
F_34 (codec, &card->codec_dev_list, card_list) {
if ( ! V_5 -> V_94 && V_5 -> V_10 -> V_92 ) {
switch ( V_5 -> V_53 . V_97 ) {
case V_101 :
if ( V_5 -> V_53 . V_102 ) {
F_42 ( V_5 -> V_27 ,
L_20
L_21 ) ;
break;
}
case V_103 :
V_5 -> V_10 -> V_92 ( V_5 ) ;
V_5 -> V_94 = 1 ;
V_5 -> V_49 = 1 ;
if ( V_5 -> V_104 )
F_62 ( V_5 -> V_105 ) ;
break;
default:
F_42 ( V_5 -> V_27 , L_22
L_21 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_46 -> V_82 ; V_3 ++ ) {
struct V_57 * V_91 = V_46 -> V_31 [ V_3 ] . V_91 ;
if ( V_46 -> V_31 [ V_3 ] . V_64 -> V_86 )
continue;
if ( V_91 -> V_10 -> V_92 && V_91 -> V_10 -> V_93 )
V_91 -> V_10 -> V_92 ( V_91 ) ;
}
if ( V_46 -> V_106 )
V_46 -> V_106 ( V_46 ) ;
return 0 ;
}
static void F_63 ( struct V_107 * V_108 )
{
struct V_59 * V_46 =
F_64 ( V_108 , struct V_59 , V_109 ) ;
struct V_4 * V_5 ;
int V_3 ;
F_42 ( V_46 -> V_27 , L_23 ) ;
F_56 ( V_46 -> V_77 , V_110 ) ;
if ( V_46 -> V_111 )
V_46 -> V_111 ( V_46 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_82 ; V_3 ++ ) {
struct V_57 * V_91 = V_46 -> V_31 [ V_3 ] . V_91 ;
if ( V_46 -> V_31 [ V_3 ] . V_64 -> V_86 )
continue;
if ( V_91 -> V_10 -> V_112 && V_91 -> V_10 -> V_93 )
V_91 -> V_10 -> V_112 ( V_91 ) ;
}
F_34 (codec, &card->codec_dev_list, card_list) {
if ( V_5 -> V_10 -> V_112 && V_5 -> V_94 ) {
switch ( V_5 -> V_53 . V_97 ) {
case V_101 :
case V_103 :
V_5 -> V_10 -> V_112 ( V_5 ) ;
V_5 -> V_94 = 0 ;
break;
default:
F_42 ( V_5 -> V_27 , L_24
L_25 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_46 -> V_82 ; V_3 ++ ) {
if ( V_46 -> V_31 [ V_3 ] . V_64 -> V_86 )
continue;
F_59 ( & V_46 -> V_31 [ V_3 ] ,
V_98 ,
V_113 ) ;
F_59 ( & V_46 -> V_31 [ V_3 ] ,
V_100 ,
V_113 ) ;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_82 ; V_3 ++ ) {
struct V_57 * V_58 = V_46 -> V_31 [ V_3 ] . V_83 ;
struct V_84 * V_85 = V_58 -> V_10 ;
if ( V_46 -> V_31 [ V_3 ] . V_64 -> V_86 )
continue;
if ( V_85 -> V_87 -> V_88 && V_58 -> V_89 )
V_85 -> V_87 -> V_88 ( V_58 , 0 ) ;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_82 ; V_3 ++ ) {
struct V_57 * V_91 = V_46 -> V_31 [ V_3 ] . V_91 ;
struct V_54 * V_55 = V_46 -> V_31 [ V_3 ] . V_55 ;
if ( V_46 -> V_31 [ V_3 ] . V_64 -> V_86 )
continue;
if ( V_91 -> V_10 -> V_112 && ! V_91 -> V_10 -> V_93 )
V_91 -> V_10 -> V_112 ( V_91 ) ;
if ( V_55 -> V_10 -> V_112 && V_55 -> V_94 ) {
V_55 -> V_10 -> V_112 ( V_91 ) ;
V_55 -> V_94 = 0 ;
}
}
if ( V_46 -> V_114 )
V_46 -> V_114 ( V_46 ) ;
F_42 ( V_46 -> V_27 , L_26 ) ;
F_56 ( V_46 -> V_77 , V_80 ) ;
F_60 ( & V_46 -> V_53 ) ;
F_61 ( & V_46 -> V_53 ) ;
}
int F_65 ( struct V_26 * V_27 )
{
struct V_59 * V_46 = F_9 ( V_27 ) ;
int V_3 , V_93 = 0 ;
if ( F_52 ( & V_46 -> V_79 ) )
return 0 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_82 ; V_3 ++ ) {
struct V_57 * V_91 = V_46 -> V_31 [ V_3 ] . V_91 ;
V_93 |= V_91 -> V_10 -> V_93 ;
}
if ( V_93 ) {
F_42 ( V_27 , L_27 ) ;
F_63 ( & V_46 -> V_109 ) ;
} else {
F_42 ( V_27 , L_28 ) ;
if ( ! F_66 ( & V_46 -> V_109 ) )
F_50 ( V_27 , L_29 ) ;
}
return 0 ;
}
static int F_67 ( struct V_59 * V_46 , int V_115 )
{
struct V_116 * V_64 = & V_46 -> V_64 [ V_115 ] ;
struct V_30 * V_31 = & V_46 -> V_31 [ V_115 ] ;
struct V_4 * V_5 ;
struct V_54 * V_55 ;
struct V_57 * V_83 , * V_91 ;
const char * V_117 ;
F_42 ( V_46 -> V_27 , L_30 , V_64 -> V_48 , V_115 ) ;
F_34 (cpu_dai, &dai_list, list) {
if ( V_64 -> V_118 &&
( V_91 -> V_27 -> V_119 != V_64 -> V_118 ) )
continue;
if ( V_64 -> V_120 &&
strcmp ( F_68 ( V_91 -> V_27 ) , V_64 -> V_120 ) )
continue;
if ( V_64 -> V_121 &&
strcmp ( V_91 -> V_48 , V_64 -> V_121 ) )
continue;
V_31 -> V_91 = V_91 ;
}
if ( ! V_31 -> V_91 ) {
F_50 ( V_46 -> V_27 , L_31 ,
V_64 -> V_121 ) ;
return - V_122 ;
}
F_34 (codec, &codec_list, list) {
if ( V_64 -> V_123 ) {
if ( V_5 -> V_27 -> V_119 != V_64 -> V_123 )
continue;
} else {
if ( strcmp ( V_5 -> V_48 , V_64 -> V_124 ) )
continue;
}
V_31 -> V_5 = V_5 ;
F_34 (codec_dai, &dai_list, list) {
if ( V_5 -> V_27 == V_83 -> V_27 &&
! strcmp ( V_83 -> V_48 ,
V_64 -> V_125 ) ) {
V_31 -> V_83 = V_83 ;
}
}
if ( ! V_31 -> V_83 ) {
F_50 ( V_46 -> V_27 , L_32 ,
V_64 -> V_125 ) ;
return - V_122 ;
}
}
if ( ! V_31 -> V_5 ) {
F_50 ( V_46 -> V_27 , L_33 ,
V_64 -> V_124 ) ;
return - V_122 ;
}
V_117 = V_64 -> V_117 ;
if ( ! V_117 && ! V_64 -> V_126 )
V_117 = L_34 ;
F_34 (platform, &platform_list, list) {
if ( V_64 -> V_126 ) {
if ( V_55 -> V_27 -> V_119 !=
V_64 -> V_126 )
continue;
} else {
if ( strcmp ( V_55 -> V_48 , V_117 ) )
continue;
}
V_31 -> V_55 = V_55 ;
}
if ( ! V_31 -> V_55 ) {
F_50 ( V_46 -> V_27 , L_35 ,
V_64 -> V_117 ) ;
return - V_122 ;
}
V_46 -> V_82 ++ ;
return 0 ;
}
static int F_69 ( struct V_54 * V_55 )
{
int V_14 ;
if ( V_55 -> V_10 -> remove ) {
V_14 = V_55 -> V_10 -> remove ( V_55 ) ;
if ( V_14 < 0 )
F_50 ( V_55 -> V_27 , L_36 ,
V_14 ) ;
}
F_70 ( & V_55 -> V_53 ) ;
F_32 ( V_55 ) ;
V_55 -> V_127 = 0 ;
F_71 ( & V_55 -> V_128 ) ;
F_72 ( V_55 -> V_27 -> V_10 -> V_129 ) ;
return 0 ;
}
static void F_73 ( struct V_4 * V_5 )
{
int V_73 ;
if ( V_5 -> V_10 -> remove ) {
V_73 = V_5 -> V_10 -> remove ( V_5 ) ;
if ( V_73 < 0 )
F_50 ( V_5 -> V_27 , L_36 , V_73 ) ;
}
F_70 ( & V_5 -> V_53 ) ;
F_29 ( V_5 ) ;
V_5 -> V_127 = 0 ;
F_71 ( & V_5 -> V_128 ) ;
F_72 ( V_5 -> V_27 -> V_10 -> V_129 ) ;
}
static void F_74 ( struct V_59 * V_46 , int V_115 , int V_130 )
{
struct V_30 * V_31 = & V_46 -> V_31 [ V_115 ] ;
struct V_57 * V_83 = V_31 -> V_83 , * V_91 = V_31 -> V_91 ;
int V_73 ;
if ( V_31 -> V_131 ) {
F_75 ( V_31 -> V_27 , & V_132 ) ;
F_75 ( V_31 -> V_27 , & V_133 ) ;
F_45 ( V_31 -> V_27 ) ;
V_31 -> V_131 = 0 ;
}
if ( V_83 && V_83 -> V_127 &&
V_83 -> V_10 -> V_134 == V_130 ) {
if ( V_83 -> V_10 -> remove ) {
V_73 = V_83 -> V_10 -> remove ( V_83 ) ;
if ( V_73 < 0 )
F_50 ( V_83 -> V_27 ,
L_37 ,
V_83 -> V_48 , V_73 ) ;
}
V_83 -> V_127 = 0 ;
F_71 ( & V_83 -> V_128 ) ;
}
if ( V_91 && V_91 -> V_127 &&
V_91 -> V_10 -> V_134 == V_130 ) {
if ( V_91 -> V_10 -> remove ) {
V_73 = V_91 -> V_10 -> remove ( V_91 ) ;
if ( V_73 < 0 )
F_50 ( V_91 -> V_27 ,
L_37 ,
V_91 -> V_48 , V_73 ) ;
}
V_91 -> V_127 = 0 ;
F_71 ( & V_91 -> V_128 ) ;
if ( ! V_91 -> V_5 ) {
F_70 ( & V_91 -> V_53 ) ;
F_72 ( V_91 -> V_27 -> V_10 -> V_129 ) ;
}
}
}
static void F_76 ( struct V_59 * V_46 , int V_115 ,
int V_130 )
{
struct V_30 * V_31 = & V_46 -> V_31 [ V_115 ] ;
struct V_57 * V_91 = V_31 -> V_91 ;
struct V_57 * V_83 = V_31 -> V_83 ;
struct V_54 * V_55 = V_31 -> V_55 ;
struct V_4 * V_5 ;
if ( V_55 && V_55 -> V_127 &&
V_55 -> V_10 -> V_134 == V_130 ) {
F_69 ( V_55 ) ;
}
if ( V_83 ) {
V_5 = V_83 -> V_5 ;
if ( V_5 && V_5 -> V_127 &&
V_5 -> V_10 -> V_134 == V_130 )
F_73 ( V_5 ) ;
}
if ( V_91 ) {
V_5 = V_91 -> V_5 ;
if ( V_5 && V_5 -> V_127 &&
V_5 -> V_10 -> V_134 == V_130 )
F_73 ( V_5 ) ;
}
}
static void F_77 ( struct V_59 * V_46 )
{
int V_58 , V_130 ;
for ( V_130 = V_135 ; V_130 <= V_136 ;
V_130 ++ ) {
for ( V_58 = 0 ; V_58 < V_46 -> V_82 ; V_58 ++ )
F_74 ( V_46 , V_58 , V_130 ) ;
}
for ( V_130 = V_135 ; V_130 <= V_136 ;
V_130 ++ ) {
for ( V_58 = 0 ; V_58 < V_46 -> V_82 ; V_58 ++ )
F_76 ( V_46 , V_58 , V_130 ) ;
}
V_46 -> V_82 = 0 ;
}
static void F_78 ( struct V_59 * V_46 ,
struct V_4 * V_5 )
{
int V_3 ;
if ( V_46 -> V_137 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_46 -> V_138 ; V_3 ++ ) {
struct V_139 * V_140 = & V_46 -> V_137 [ V_3 ] ;
if ( V_140 -> F_68 && ! strcmp ( V_5 -> V_48 , V_140 -> F_68 ) ) {
V_5 -> V_141 = V_140 -> V_141 ;
break;
}
}
}
static int F_79 ( struct V_59 * V_46 ,
struct V_4 * V_5 )
{
int V_14 = 0 ;
const struct V_142 * V_10 = V_5 -> V_10 ;
struct V_57 * V_58 ;
V_5 -> V_46 = V_46 ;
V_5 -> V_53 . V_46 = V_46 ;
F_78 ( V_46 , V_5 ) ;
if ( ! F_80 ( V_5 -> V_27 -> V_10 -> V_129 ) )
return - V_143 ;
F_23 ( V_5 ) ;
if ( V_10 -> V_144 )
F_81 ( & V_5 -> V_53 , V_10 -> V_144 ,
V_10 -> V_145 ) ;
F_34 (dai, &dai_list, list) {
if ( V_58 -> V_27 != V_5 -> V_27 )
continue;
F_82 ( & V_5 -> V_53 , V_58 ) ;
}
V_5 -> V_53 . V_102 = V_10 -> V_102 ;
if ( V_10 -> V_146 ) {
V_14 = V_10 -> V_146 ( V_5 ) ;
if ( V_14 < 0 ) {
F_50 ( V_5 -> V_27 ,
L_38 , V_14 ) ;
goto V_147;
}
}
if ( ! V_5 -> V_148 && F_83 ( V_5 -> V_27 , NULL ) )
F_84 ( V_5 , 0 , 0 , V_149 ) ;
if ( V_10 -> V_150 )
F_85 ( V_5 , V_10 -> V_150 ,
V_10 -> V_151 ) ;
if ( V_10 -> V_152 )
F_86 ( & V_5 -> V_53 , V_10 -> V_152 ,
V_10 -> V_153 ) ;
V_5 -> V_127 = 1 ;
F_87 ( & V_5 -> V_128 , & V_46 -> V_79 ) ;
F_87 ( & V_5 -> V_53 . V_154 , & V_46 -> V_155 ) ;
return 0 ;
V_147:
F_29 ( V_5 ) ;
F_72 ( V_5 -> V_27 -> V_10 -> V_129 ) ;
return V_14 ;
}
static int F_88 ( struct V_59 * V_46 ,
struct V_54 * V_55 )
{
int V_14 = 0 ;
const struct V_156 * V_10 = V_55 -> V_10 ;
struct V_57 * V_58 ;
V_55 -> V_46 = V_46 ;
V_55 -> V_53 . V_46 = V_46 ;
if ( ! F_80 ( V_55 -> V_27 -> V_10 -> V_129 ) )
return - V_143 ;
F_31 ( V_55 ) ;
if ( V_10 -> V_144 )
F_81 ( & V_55 -> V_53 ,
V_10 -> V_144 , V_10 -> V_145 ) ;
F_34 (dai, &dai_list, list) {
if ( V_58 -> V_27 != V_55 -> V_27 )
continue;
F_82 ( & V_55 -> V_53 , V_58 ) ;
}
V_55 -> V_53 . V_102 = 1 ;
if ( V_10 -> V_146 ) {
V_14 = V_10 -> V_146 ( V_55 ) ;
if ( V_14 < 0 ) {
F_50 ( V_55 -> V_27 ,
L_39 , V_14 ) ;
goto V_147;
}
}
if ( V_10 -> V_150 )
F_89 ( V_55 , V_10 -> V_150 ,
V_10 -> V_151 ) ;
if ( V_10 -> V_152 )
F_86 ( & V_55 -> V_53 , V_10 -> V_152 ,
V_10 -> V_153 ) ;
V_55 -> V_127 = 1 ;
F_87 ( & V_55 -> V_128 , & V_46 -> V_157 ) ;
F_87 ( & V_55 -> V_53 . V_154 , & V_46 -> V_155 ) ;
return 0 ;
V_147:
F_32 ( V_55 ) ;
F_72 ( V_55 -> V_27 -> V_10 -> V_129 ) ;
return V_14 ;
}
static void F_90 ( struct V_26 * V_27 )
{
F_16 ( V_27 ) ;
}
static int F_91 ( struct V_59 * V_46 ,
struct V_4 * V_5 ,
int V_115 , int V_158 )
{
struct V_116 * V_64 = NULL ;
struct V_159 * V_160 = NULL ;
struct V_30 * V_31 ;
const char * V_161 , * V_48 ;
int V_14 = 0 ;
if ( ! V_158 ) {
V_64 = & V_46 -> V_64 [ V_115 ] ;
V_31 = & V_46 -> V_31 [ V_115 ] ;
V_48 = V_64 -> V_48 ;
} else {
V_160 = & V_46 -> V_160 [ V_115 ] ;
V_31 = & V_46 -> V_162 [ V_115 ] ;
V_48 = V_160 -> V_48 ;
}
V_31 -> V_46 = V_46 ;
F_92 ( & V_5 -> V_53 ) ;
V_161 = V_5 -> V_141 ;
V_5 -> V_141 = NULL ;
if ( ! V_158 && V_64 -> V_163 )
V_14 = V_64 -> V_163 ( V_31 ) ;
else if ( V_158 && V_160 -> V_163 )
V_14 = V_160 -> V_163 ( & V_5 -> V_53 ) ;
if ( V_14 < 0 ) {
F_50 ( V_46 -> V_27 , L_40 , V_48 , V_14 ) ;
return V_14 ;
}
V_5 -> V_141 = V_161 ;
V_31 -> V_5 = V_5 ;
V_31 -> V_27 = F_93 ( sizeof( struct V_26 ) , V_37 ) ;
if ( ! V_31 -> V_27 )
return - V_38 ;
F_94 ( V_31 -> V_27 ) ;
V_31 -> V_27 -> V_75 = V_46 -> V_27 ;
V_31 -> V_27 -> V_76 = F_90 ;
V_31 -> V_27 -> V_164 = V_48 ;
F_95 ( V_31 -> V_27 , V_31 ) ;
F_96 ( & V_31 -> V_165 ) ;
F_97 ( & V_31 -> V_166 [ V_98 ] . V_167 ) ;
F_97 ( & V_31 -> V_166 [ V_100 ] . V_167 ) ;
F_97 ( & V_31 -> V_166 [ V_98 ] . V_168 ) ;
F_97 ( & V_31 -> V_166 [ V_100 ] . V_168 ) ;
V_14 = F_98 ( V_31 -> V_27 ) ;
if ( V_14 < 0 ) {
F_99 ( V_31 -> V_27 ) ;
F_50 ( V_46 -> V_27 ,
L_41 , V_14 ) ;
return V_14 ;
}
V_31 -> V_131 = 1 ;
V_14 = F_100 ( V_31 -> V_27 ) ;
if ( V_14 < 0 )
F_50 ( V_5 -> V_27 ,
L_42 , V_14 ) ;
V_14 = F_101 ( V_31 -> V_27 , & V_133 ) ;
if ( V_14 < 0 )
F_50 ( V_5 -> V_27 ,
L_43 , V_14 ) ;
#ifdef F_102
if ( ! V_158 && ! V_64 -> V_169 )
goto V_170;
V_14 = F_103 ( V_31 ) ;
if ( V_14 < 0 )
F_50 ( V_31 -> V_27 , L_44 , V_14 ) ;
V_170:
#endif
return 0 ;
}
static int F_104 ( struct V_59 * V_46 , int V_115 ,
int V_130 )
{
struct V_30 * V_31 = & V_46 -> V_31 [ V_115 ] ;
struct V_57 * V_91 = V_31 -> V_91 ;
struct V_57 * V_83 = V_31 -> V_83 ;
struct V_54 * V_55 = V_31 -> V_55 ;
int V_14 ;
if ( V_91 -> V_5 &&
! V_91 -> V_5 -> V_127 &&
V_91 -> V_5 -> V_10 -> V_171 == V_130 ) {
V_14 = F_79 ( V_46 , V_91 -> V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_83 -> V_5 -> V_127 &&
V_83 -> V_5 -> V_10 -> V_171 == V_130 ) {
V_14 = F_79 ( V_46 , V_83 -> V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_55 -> V_127 &&
V_55 -> V_10 -> V_171 == V_130 ) {
V_14 = F_88 ( V_46 , V_55 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
static int F_105 ( struct V_59 * V_46 , int V_115 , int V_130 )
{
struct V_116 * V_64 = & V_46 -> V_64 [ V_115 ] ;
struct V_30 * V_31 = & V_46 -> V_31 [ V_115 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
struct V_54 * V_55 = V_31 -> V_55 ;
struct V_57 * V_83 = V_31 -> V_83 ;
struct V_57 * V_91 = V_31 -> V_91 ;
struct V_172 * V_173 , * V_174 ;
int V_14 ;
F_42 ( V_46 -> V_27 , L_45 ,
V_46 -> V_48 , V_115 , V_130 ) ;
V_91 -> V_55 = V_55 ;
V_83 -> V_46 = V_46 ;
V_91 -> V_46 = V_46 ;
V_31 -> V_32 = V_32 ;
if ( ! V_91 -> V_127 &&
V_91 -> V_10 -> V_171 == V_130 ) {
if ( ! V_91 -> V_5 ) {
V_91 -> V_53 . V_46 = V_46 ;
if ( ! F_80 ( V_91 -> V_27 -> V_10 -> V_129 ) )
return - V_143 ;
F_87 ( & V_91 -> V_53 . V_154 , & V_46 -> V_155 ) ;
F_82 ( & V_91 -> V_53 , V_91 ) ;
}
if ( V_91 -> V_10 -> V_146 ) {
V_14 = V_91 -> V_10 -> V_146 ( V_91 ) ;
if ( V_14 < 0 ) {
F_50 ( V_91 -> V_27 ,
L_46 ,
V_91 -> V_48 , V_14 ) ;
F_72 ( V_91 -> V_27 -> V_10 -> V_129 ) ;
return V_14 ;
}
}
V_91 -> V_127 = 1 ;
F_87 ( & V_91 -> V_128 , & V_46 -> V_175 ) ;
}
if ( ! V_83 -> V_127 && V_83 -> V_10 -> V_171 == V_130 ) {
if ( V_83 -> V_10 -> V_146 ) {
V_14 = V_83 -> V_10 -> V_146 ( V_83 ) ;
if ( V_14 < 0 ) {
F_50 ( V_83 -> V_27 ,
L_47 ,
V_83 -> V_48 , V_14 ) ;
return V_14 ;
}
}
V_83 -> V_127 = 1 ;
F_87 ( & V_83 -> V_128 , & V_46 -> V_175 ) ;
}
if ( V_130 != V_136 )
return 0 ;
V_14 = F_91 ( V_46 , V_5 , V_115 , 0 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_101 ( V_31 -> V_27 , & V_132 ) ;
if ( V_14 < 0 )
F_25 ( V_31 -> V_27 , L_48 ,
V_14 ) ;
if ( V_91 -> V_10 -> V_176 ) {
V_14 = F_106 ( V_31 , V_115 ) ;
if ( V_14 < 0 ) {
F_50 ( V_46 -> V_27 , L_49 ,
V_64 -> V_177 ) ;
return V_14 ;
}
} else {
if ( ! V_64 -> V_178 ) {
V_14 = F_107 ( V_31 , V_115 ) ;
if ( V_14 < 0 ) {
F_50 ( V_46 -> V_27 , L_50 ,
V_64 -> V_177 , V_14 ) ;
return V_14 ;
}
} else {
V_173 = V_83 -> V_179 ;
V_174 = V_91 -> V_180 ;
if ( V_173 && V_174 ) {
V_14 = F_108 ( V_46 , V_64 -> V_178 ,
V_174 , V_173 ) ;
if ( V_14 != 0 ) {
F_50 ( V_46 -> V_27 , L_51 ,
V_173 -> V_48 , V_174 -> V_48 , V_14 ) ;
return V_14 ;
}
}
V_173 = V_91 -> V_179 ;
V_174 = V_83 -> V_180 ;
if ( V_173 && V_174 ) {
V_14 = F_108 ( V_46 , V_64 -> V_178 ,
V_174 , V_173 ) ;
if ( V_14 != 0 ) {
F_50 ( V_46 -> V_27 , L_51 ,
V_173 -> V_48 , V_174 -> V_48 , V_14 ) ;
return V_14 ;
}
}
}
}
if ( V_31 -> V_83 -> V_10 -> V_93 )
F_109 ( V_5 -> V_71 , V_31 -> V_91 -> V_181 ) ;
return 0 ;
}
static int F_110 ( struct V_30 * V_31 )
{
int V_14 ;
if ( V_31 -> V_83 -> V_10 -> V_93 && ! V_31 -> V_5 -> V_182 ) {
if ( ! V_31 -> V_5 -> V_183 )
return 0 ;
V_14 = F_47 ( V_31 -> V_5 ) ;
if ( V_14 < 0 ) {
F_50 ( V_31 -> V_5 -> V_27 ,
L_52 , V_14 ) ;
return V_14 ;
}
V_31 -> V_5 -> V_182 = 1 ;
}
return 0 ;
}
static void F_111 ( struct V_4 * V_5 )
{
if ( V_5 -> V_182 ) {
F_44 ( V_5 ) ;
V_5 -> V_182 = 0 ;
}
}
static int F_112 ( struct V_59 * V_46 , int V_115 )
{
struct V_159 * V_160 = & V_46 -> V_160 [ V_115 ] ;
struct V_4 * V_5 ;
F_34 (codec, &codec_list, list) {
if ( ! strcmp ( V_5 -> V_48 , V_160 -> V_124 ) )
return 0 ;
}
F_50 ( V_46 -> V_27 , L_53 , V_160 -> V_124 ) ;
return - V_122 ;
}
static int F_113 ( struct V_59 * V_46 , int V_115 )
{
struct V_159 * V_160 = & V_46 -> V_160 [ V_115 ] ;
struct V_4 * V_5 ;
int V_14 = - V_143 ;
F_34 (codec, &codec_list, list) {
if ( ! strcmp ( V_5 -> V_48 , V_160 -> V_124 ) ) {
if ( V_5 -> V_127 ) {
F_50 ( V_5 -> V_27 ,
L_54 ) ;
V_14 = - V_184 ;
goto V_170;
}
goto V_185;
}
}
F_50 ( V_46 -> V_27 , L_55 , V_160 -> V_124 ) ;
return - V_122 ;
V_185:
V_14 = F_79 ( V_46 , V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_91 ( V_46 , V_5 , V_115 , 1 ) ;
V_170:
return V_14 ;
}
static void F_114 ( struct V_59 * V_46 , int V_115 )
{
struct V_30 * V_31 = & V_46 -> V_162 [ V_115 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
if ( V_31 -> V_131 ) {
F_75 ( V_31 -> V_27 , & V_133 ) ;
F_45 ( V_31 -> V_27 ) ;
V_31 -> V_131 = 0 ;
}
if ( V_5 && V_5 -> V_127 )
F_73 ( V_5 ) ;
}
static int F_115 ( struct V_4 * V_5 ,
enum V_186 V_187 )
{
int V_14 ;
if ( V_5 -> V_188 )
return 0 ;
if ( V_187 && V_5 -> V_187 != V_187 )
V_5 -> V_187 = V_187 ;
V_14 = F_116 ( V_5 ) ;
if ( V_14 < 0 ) {
F_50 ( V_5 -> V_27 , L_56
L_57 , V_14 ) ;
return V_14 ;
}
V_5 -> V_188 = 1 ;
return 0 ;
}
static int F_117 ( struct V_59 * V_46 )
{
struct V_4 * V_5 ;
struct V_139 * V_137 ;
enum V_186 V_187 ;
struct V_116 * V_64 ;
int V_14 , V_3 , V_130 , V_189 ;
F_118 ( & V_46 -> V_190 , V_191 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ ) {
V_14 = F_67 ( V_46 , V_3 ) ;
if ( V_14 != 0 )
goto V_192;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_193 ; V_3 ++ ) {
V_14 = F_112 ( V_46 , V_3 ) ;
if ( V_14 != 0 )
goto V_192;
}
F_34 (codec, &codec_list, list) {
if ( V_5 -> V_188 )
continue;
V_187 = 0 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_138 ; ++ V_3 ) {
V_137 = & V_46 -> V_137 [ V_3 ] ;
if ( ! strcmp ( V_5 -> V_48 , V_137 -> F_68 ) ) {
V_187 = V_137 -> V_187 ;
if ( V_187 && V_187
!= V_5 -> V_187 )
break;
}
}
V_14 = F_115 ( V_5 , V_187 ) ;
if ( V_14 < 0 )
goto V_192;
}
V_14 = F_119 ( V_194 , V_195 ,
V_46 -> V_129 , 0 , & V_46 -> V_77 ) ;
if ( V_14 < 0 ) {
F_50 ( V_46 -> V_27 , L_58
L_59 , V_46 -> V_48 , V_14 ) ;
goto V_192;
}
V_46 -> V_77 -> V_27 = V_46 -> V_27 ;
V_46 -> V_53 . V_97 = V_103 ;
V_46 -> V_53 . V_27 = V_46 -> V_27 ;
V_46 -> V_53 . V_46 = V_46 ;
F_87 ( & V_46 -> V_53 . V_154 , & V_46 -> V_155 ) ;
#ifdef F_102
F_28 ( & V_46 -> V_53 , V_46 -> V_45 ) ;
#endif
#ifdef F_120
F_121 ( & V_46 -> V_109 , F_63 ) ;
#endif
if ( V_46 -> V_144 )
F_81 ( & V_46 -> V_53 , V_46 -> V_144 ,
V_46 -> V_145 ) ;
if ( V_46 -> V_146 ) {
V_14 = V_46 -> V_146 ( V_46 ) ;
if ( V_14 < 0 )
goto V_196;
}
for ( V_130 = V_135 ; V_130 <= V_136 ;
V_130 ++ ) {
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ ) {
V_14 = F_104 ( V_46 , V_3 , V_130 ) ;
if ( V_14 < 0 ) {
F_50 ( V_46 -> V_27 ,
L_60 ,
V_14 ) ;
goto V_197;
}
}
}
for ( V_130 = V_135 ; V_130 <= V_136 ;
V_130 ++ ) {
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ ) {
V_14 = F_105 ( V_46 , V_3 , V_130 ) ;
if ( V_14 < 0 ) {
F_50 ( V_46 -> V_27 ,
L_60 ,
V_14 ) ;
goto V_197;
}
}
}
for ( V_3 = 0 ; V_3 < V_46 -> V_193 ; V_3 ++ ) {
V_14 = F_113 ( V_46 , V_3 ) ;
if ( V_14 < 0 ) {
F_50 ( V_46 -> V_27 ,
L_61 ,
V_14 ) ;
goto V_198;
}
}
F_122 ( V_46 ) ;
if ( V_46 -> V_150 )
F_123 ( V_46 , V_46 -> V_150 , V_46 -> V_151 ) ;
if ( V_46 -> V_152 )
F_86 ( & V_46 -> V_53 , V_46 -> V_152 ,
V_46 -> V_153 ) ;
F_92 ( & V_46 -> V_53 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ ) {
V_64 = & V_46 -> V_64 [ V_3 ] ;
V_189 = V_64 -> V_189 ;
if ( V_189 ) {
V_14 = F_124 ( V_46 -> V_31 [ V_3 ] . V_83 ,
V_189 ) ;
if ( V_14 != 0 && V_14 != - V_199 )
F_25 ( V_46 -> V_31 [ V_3 ] . V_83 -> V_27 ,
L_62 ,
V_14 ) ;
}
if ( V_189 &&
( V_64 -> V_117 || V_64 -> V_126 ) ) {
V_14 = F_124 ( V_46 -> V_31 [ V_3 ] . V_91 ,
V_189 ) ;
if ( V_14 != 0 && V_14 != - V_199 )
F_25 ( V_46 -> V_31 [ V_3 ] . V_91 -> V_27 ,
L_62 ,
V_14 ) ;
} else if ( V_189 ) {
V_189 &= ~ V_200 ;
switch ( V_64 -> V_189 &
V_200 ) {
case V_201 :
V_189 |= V_202 ;
break;
case V_203 :
V_189 |= V_204 ;
break;
case V_204 :
V_189 |= V_203 ;
break;
case V_202 :
V_189 |= V_201 ;
break;
}
V_14 = F_124 ( V_46 -> V_31 [ V_3 ] . V_91 ,
V_189 ) ;
if ( V_14 != 0 && V_14 != - V_199 )
F_25 ( V_46 -> V_31 [ V_3 ] . V_91 -> V_27 ,
L_62 ,
V_14 ) ;
}
}
snprintf ( V_46 -> V_77 -> V_205 , sizeof( V_46 -> V_77 -> V_205 ) ,
L_63 , V_46 -> V_48 ) ;
snprintf ( V_46 -> V_77 -> V_206 , sizeof( V_46 -> V_77 -> V_206 ) ,
L_63 , V_46 -> V_207 ? V_46 -> V_207 : V_46 -> V_48 ) ;
snprintf ( V_46 -> V_77 -> V_10 , sizeof( V_46 -> V_77 -> V_10 ) ,
L_63 , V_46 -> V_208 ? V_46 -> V_208 : V_46 -> V_48 ) ;
for ( V_3 = 0 ; V_3 < F_125 ( V_46 -> V_77 -> V_10 ) ; V_3 ++ ) {
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
if ( V_46 -> V_209 ) {
V_14 = V_46 -> V_209 ( V_46 ) ;
if ( V_14 < 0 ) {
F_50 ( V_46 -> V_27 , L_64 ,
V_46 -> V_48 , V_14 ) ;
goto V_198;
}
}
F_92 ( & V_46 -> V_53 ) ;
if ( V_46 -> V_210 )
F_34 (codec, &card->codec_dev_list, card_list)
F_126 ( V_5 ) ;
V_14 = F_127 ( V_46 -> V_77 ) ;
if ( V_14 < 0 ) {
F_50 ( V_46 -> V_27 , L_65 ,
V_14 ) ;
goto V_198;
}
#ifdef F_128
for ( V_3 = 0 ; V_3 < V_46 -> V_82 ; V_3 ++ ) {
V_14 = F_110 ( & V_46 -> V_31 [ V_3 ] ) ;
if ( V_14 < 0 ) {
F_50 ( V_46 -> V_27 , L_66
L_67 , V_14 ) ;
while ( -- V_3 >= 0 )
F_111 ( V_46 -> V_31 [ V_3 ] . V_5 ) ;
goto V_198;
}
}
#endif
V_46 -> V_211 = 1 ;
F_61 ( & V_46 -> V_53 ) ;
F_129 ( & V_46 -> V_190 ) ;
return 0 ;
V_198:
for ( V_3 = 0 ; V_3 < V_46 -> V_193 ; V_3 ++ )
F_114 ( V_46 , V_3 ) ;
V_197:
F_77 ( V_46 ) ;
V_196:
if ( V_46 -> remove )
V_46 -> remove ( V_46 ) ;
F_130 ( V_46 -> V_77 ) ;
V_192:
F_129 ( & V_46 -> V_190 ) ;
return V_14 ;
}
static int F_131 ( struct V_212 * V_213 )
{
struct V_59 * V_46 = F_132 ( V_213 ) ;
if ( ! V_46 )
return - V_17 ;
F_25 ( & V_213 -> V_27 ,
L_68 ,
V_46 -> V_48 ) ;
V_46 -> V_27 = & V_213 -> V_27 ;
return F_133 ( V_46 ) ;
}
static int F_134 ( struct V_59 * V_46 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_82 ; V_3 ++ ) {
struct V_30 * V_31 = & V_46 -> V_31 [ V_3 ] ;
F_58 ( & V_31 -> V_95 ) ;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_193 ; V_3 ++ )
F_114 ( V_46 , V_3 ) ;
F_77 ( V_46 ) ;
F_40 ( V_46 ) ;
if ( V_46 -> remove )
V_46 -> remove ( V_46 ) ;
F_70 ( & V_46 -> V_53 ) ;
F_130 ( V_46 -> V_77 ) ;
return 0 ;
}
static int F_135 ( struct V_212 * V_213 )
{
struct V_59 * V_46 = F_132 ( V_213 ) ;
F_136 ( V_46 ) ;
return 0 ;
}
int F_137 ( struct V_26 * V_27 )
{
struct V_59 * V_46 = F_9 ( V_27 ) ;
int V_3 ;
if ( ! V_46 -> V_211 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_82 ; V_3 ++ ) {
struct V_30 * V_31 = & V_46 -> V_31 [ V_3 ] ;
F_58 ( & V_31 -> V_95 ) ;
}
F_138 ( V_46 ) ;
return 0 ;
}
int F_139 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_214 )
return V_5 -> V_214 ( V_5 , V_6 ) ;
else
return 0 ;
}
int F_6 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_215 )
return V_5 -> V_215 ( V_5 , V_6 ) ;
else
return 1 ;
}
int F_140 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_216 )
return V_5 -> V_216 ( V_5 , V_6 ) ;
else
return 1 ;
}
int F_141 ( struct V_54 * V_55 ,
unsigned int V_6 )
{
unsigned int V_14 ;
if ( ! V_55 -> V_10 -> V_217 ) {
F_50 ( V_55 -> V_27 , L_69 ) ;
return - 1 ;
}
V_14 = V_55 -> V_10 -> V_217 ( V_55 , V_6 ) ;
F_42 ( V_55 -> V_27 , L_70 , V_6 , V_14 ) ;
F_142 ( V_55 , V_6 , V_14 ) ;
return V_14 ;
}
int F_143 ( struct V_54 * V_55 ,
unsigned int V_6 , unsigned int V_1 )
{
if ( ! V_55 -> V_10 -> V_148 ) {
F_50 ( V_55 -> V_27 , L_71 ) ;
return - 1 ;
}
F_42 ( V_55 -> V_27 , L_72 , V_6 , V_1 ) ;
F_144 ( V_55 , V_6 , V_1 ) ;
return V_55 -> V_10 -> V_148 ( V_55 , V_6 , V_1 ) ;
}
int F_145 ( struct V_4 * V_5 ,
struct V_218 * V_87 , int V_115 )
{
F_146 ( & V_5 -> V_190 ) ;
V_5 -> V_71 = F_93 ( sizeof( struct V_219 ) , V_37 ) ;
if ( V_5 -> V_71 == NULL ) {
F_129 ( & V_5 -> V_190 ) ;
return - V_38 ;
}
V_5 -> V_71 -> V_72 = F_93 ( sizeof( struct V_220 ) , V_37 ) ;
if ( V_5 -> V_71 -> V_72 == NULL ) {
F_16 ( V_5 -> V_71 ) ;
V_5 -> V_71 = NULL ;
F_129 ( & V_5 -> V_190 ) ;
return - V_38 ;
}
V_5 -> V_71 -> V_72 -> V_87 = V_87 ;
V_5 -> V_71 -> V_115 = V_115 ;
V_5 -> V_183 = 1 ;
F_129 ( & V_5 -> V_190 ) ;
return 0 ;
}
void F_147 ( struct V_4 * V_5 )
{
F_146 ( & V_5 -> V_190 ) ;
#ifdef F_128
F_111 ( V_5 ) ;
#endif
F_16 ( V_5 -> V_71 -> V_72 ) ;
F_16 ( V_5 -> V_71 ) ;
V_5 -> V_71 = NULL ;
V_5 -> V_183 = 0 ;
F_129 ( & V_5 -> V_190 ) ;
}
unsigned int F_4 ( struct V_4 * V_5 , unsigned int V_6 )
{
unsigned int V_14 ;
V_14 = V_5 -> V_217 ( V_5 , V_6 ) ;
F_42 ( V_5 -> V_27 , L_70 , V_6 , V_14 ) ;
F_148 ( V_5 , V_6 , V_14 ) ;
return V_14 ;
}
unsigned int F_22 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned int V_1 )
{
F_42 ( V_5 -> V_27 , L_72 , V_6 , V_1 ) ;
F_149 ( V_5 , V_6 , V_1 ) ;
return V_5 -> V_148 ( V_5 , V_6 , V_1 ) ;
}
unsigned int F_150 ( struct V_4 * V_5 ,
unsigned int V_6 , const void * V_221 , T_1 V_8 )
{
return V_5 -> V_222 ( V_5 , V_6 , V_221 , V_8 ) ;
}
int F_151 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_223 , unsigned int V_42 )
{
bool V_224 ;
unsigned int V_225 , V_226 ;
int V_14 ;
if ( V_5 -> V_104 ) {
V_14 = F_152 ( V_5 -> V_105 , V_6 ,
V_223 , V_42 , & V_224 ) ;
} else {
V_14 = F_4 ( V_5 , V_6 ) ;
if ( V_14 < 0 )
return V_14 ;
V_225 = V_14 ;
V_226 = ( V_225 & ~ V_223 ) | ( V_42 & V_223 ) ;
V_224 = V_225 != V_226 ;
if ( V_224 )
V_14 = F_22 ( V_5 , V_6 , V_226 ) ;
}
if ( V_14 < 0 )
return V_14 ;
return V_224 ;
}
int F_153 ( struct V_4 * V_5 ,
unsigned short V_6 , unsigned int V_223 ,
unsigned int V_42 )
{
int V_224 ;
F_146 ( & V_5 -> V_190 ) ;
V_224 = F_151 ( V_5 , V_6 , V_223 , V_42 ) ;
F_129 ( & V_5 -> V_190 ) ;
return V_224 ;
}
int F_154 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_223 , unsigned int V_42 )
{
int V_224 ;
unsigned int V_225 , V_226 ;
V_225 = F_4 ( V_5 , V_6 ) ;
V_226 = ( V_225 & ~ V_223 ) | V_42 ;
V_224 = V_225 != V_226 ;
return V_224 ;
}
int F_155 ( struct V_63 * V_70 ,
const struct V_227 * V_228 )
{
struct V_229 * V_230 = V_70 -> V_230 ;
V_230 -> V_228 . V_231 = V_228 -> V_231 ;
V_230 -> V_228 . V_232 = V_228 -> V_232 ;
V_230 -> V_228 . V_233 = V_228 -> V_233 ;
V_230 -> V_228 . V_234 = V_228 -> V_234 ;
V_230 -> V_228 . V_235 = V_228 -> V_235 ;
V_230 -> V_228 . V_236 = V_228 -> V_236 ;
V_230 -> V_228 . V_237 = V_228 -> V_237 ;
V_230 -> V_228 . V_238 = V_228 -> V_238 ;
return 0 ;
}
struct V_239 * F_156 ( const struct V_240 * V_241 ,
void * V_221 , const char * V_207 ,
const char * V_242 )
{
struct V_240 V_243 ;
struct V_239 * V_244 ;
char * V_48 = NULL ;
int V_245 ;
memcpy ( & V_243 , V_241 , sizeof( V_243 ) ) ;
V_243 . V_246 = 0 ;
if ( ! V_207 )
V_207 = V_243 . V_48 ;
if ( V_242 ) {
V_245 = strlen ( V_207 ) + strlen ( V_242 ) + 2 ;
V_48 = F_14 ( V_245 , V_37 ) ;
if ( ! V_48 )
return NULL ;
snprintf ( V_48 , V_245 , L_73 , V_242 , V_207 ) ;
V_243 . V_48 = V_48 ;
} else {
V_243 . V_48 = V_207 ;
}
V_244 = F_157 ( & V_243 , V_221 ) ;
F_16 ( V_48 ) ;
return V_244 ;
}
static int F_158 ( struct V_77 * V_46 , struct V_26 * V_27 ,
const struct V_240 * V_150 , int V_151 ,
const char * V_242 , void * V_221 )
{
int V_73 , V_3 ;
for ( V_3 = 0 ; V_3 < V_151 ; V_3 ++ ) {
const struct V_240 * V_247 = & V_150 [ V_3 ] ;
V_73 = F_159 ( V_46 , F_156 ( V_247 , V_221 ,
V_247 -> V_48 , V_242 ) ) ;
if ( V_73 < 0 ) {
F_50 ( V_27 , L_74 ,
V_247 -> V_48 , V_73 ) ;
return V_73 ;
}
}
return 0 ;
}
int F_85 ( struct V_4 * V_5 ,
const struct V_240 * V_150 , int V_151 )
{
struct V_77 * V_46 = V_5 -> V_46 -> V_77 ;
return F_158 ( V_46 , V_5 -> V_27 , V_150 , V_151 ,
V_5 -> V_141 , V_5 ) ;
}
int F_89 ( struct V_54 * V_55 ,
const struct V_240 * V_150 , int V_151 )
{
struct V_77 * V_46 = V_55 -> V_46 -> V_77 ;
return F_158 ( V_46 , V_55 -> V_27 , V_150 , V_151 ,
NULL , V_55 ) ;
}
int F_123 ( struct V_59 * V_248 ,
const struct V_240 * V_150 , int V_151 )
{
struct V_77 * V_46 = V_248 -> V_77 ;
return F_158 ( V_46 , V_248 -> V_27 , V_150 , V_151 ,
NULL , V_248 ) ;
}
int F_160 ( struct V_57 * V_58 ,
const struct V_240 * V_150 , int V_151 )
{
struct V_77 * V_46 = V_58 -> V_46 -> V_77 ;
return F_158 ( V_46 , V_58 -> V_27 , V_150 , V_151 ,
NULL , V_58 ) ;
}
int F_161 ( struct V_239 * V_244 ,
struct V_249 * V_250 )
{
struct V_251 * V_252 = (struct V_251 * ) V_244 -> V_253 ;
V_250 -> type = V_254 ;
V_250 -> V_18 = V_252 -> V_255 == V_252 -> V_256 ? 1 : 2 ;
V_250 -> V_42 . V_257 . V_258 = V_252 -> V_259 ;
if ( V_250 -> V_42 . V_257 . V_260 > V_252 -> V_259 - 1 )
V_250 -> V_42 . V_257 . V_260 = V_252 -> V_259 - 1 ;
strcpy ( V_250 -> V_42 . V_257 . V_48 ,
V_252 -> V_261 [ V_250 -> V_42 . V_257 . V_260 ] ) ;
return 0 ;
}
int F_162 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_4 * V_5 = F_163 ( V_244 ) ;
struct V_251 * V_252 = (struct V_251 * ) V_244 -> V_253 ;
unsigned int V_1 ;
V_1 = F_4 ( V_5 , V_252 -> V_6 ) ;
V_263 -> V_42 . V_257 . V_260 [ 0 ]
= ( V_1 >> V_252 -> V_255 ) & V_252 -> V_223 ;
if ( V_252 -> V_255 != V_252 -> V_256 )
V_263 -> V_42 . V_257 . V_260 [ 1 ] =
( V_1 >> V_252 -> V_256 ) & V_252 -> V_223 ;
return 0 ;
}
int F_164 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_4 * V_5 = F_163 ( V_244 ) ;
struct V_251 * V_252 = (struct V_251 * ) V_244 -> V_253 ;
unsigned int V_1 ;
unsigned int V_223 ;
if ( V_263 -> V_42 . V_257 . V_260 [ 0 ] > V_252 -> V_259 - 1 )
return - V_17 ;
V_1 = V_263 -> V_42 . V_257 . V_260 [ 0 ] << V_252 -> V_255 ;
V_223 = V_252 -> V_223 << V_252 -> V_255 ;
if ( V_252 -> V_255 != V_252 -> V_256 ) {
if ( V_263 -> V_42 . V_257 . V_260 [ 1 ] > V_252 -> V_259 - 1 )
return - V_17 ;
V_1 |= V_263 -> V_42 . V_257 . V_260 [ 1 ] << V_252 -> V_256 ;
V_223 |= V_252 -> V_223 << V_252 -> V_256 ;
}
return F_153 ( V_5 , V_252 -> V_6 , V_223 , V_1 ) ;
}
int F_165 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_4 * V_5 = F_163 ( V_244 ) ;
struct V_251 * V_252 = (struct V_251 * ) V_244 -> V_253 ;
unsigned int V_264 , V_1 , V_265 ;
V_264 = F_4 ( V_5 , V_252 -> V_6 ) ;
V_1 = ( V_264 >> V_252 -> V_255 ) & V_252 -> V_223 ;
for ( V_265 = 0 ; V_265 < V_252 -> V_259 ; V_265 ++ ) {
if ( V_1 == V_252 -> V_266 [ V_265 ] )
break;
}
V_263 -> V_42 . V_257 . V_260 [ 0 ] = V_265 ;
if ( V_252 -> V_255 != V_252 -> V_256 ) {
V_1 = ( V_264 >> V_252 -> V_256 ) & V_252 -> V_223 ;
for ( V_265 = 0 ; V_265 < V_252 -> V_259 ; V_265 ++ ) {
if ( V_1 == V_252 -> V_266 [ V_265 ] )
break;
}
V_263 -> V_42 . V_257 . V_260 [ 1 ] = V_265 ;
}
return 0 ;
}
int F_166 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_4 * V_5 = F_163 ( V_244 ) ;
struct V_251 * V_252 = (struct V_251 * ) V_244 -> V_253 ;
unsigned int V_1 ;
unsigned int V_223 ;
if ( V_263 -> V_42 . V_257 . V_260 [ 0 ] > V_252 -> V_259 - 1 )
return - V_17 ;
V_1 = V_252 -> V_266 [ V_263 -> V_42 . V_257 . V_260 [ 0 ] ] << V_252 -> V_255 ;
V_223 = V_252 -> V_223 << V_252 -> V_255 ;
if ( V_252 -> V_255 != V_252 -> V_256 ) {
if ( V_263 -> V_42 . V_257 . V_260 [ 1 ] > V_252 -> V_259 - 1 )
return - V_17 ;
V_1 |= V_252 -> V_266 [ V_263 -> V_42 . V_257 . V_260 [ 1 ] ] << V_252 -> V_256 ;
V_223 |= V_252 -> V_223 << V_252 -> V_256 ;
}
return F_153 ( V_5 , V_252 -> V_6 , V_223 , V_1 ) ;
}
int F_167 ( struct V_239 * V_244 ,
struct V_249 * V_250 )
{
struct V_251 * V_252 = (struct V_251 * ) V_244 -> V_253 ;
V_250 -> type = V_254 ;
V_250 -> V_18 = 1 ;
V_250 -> V_42 . V_257 . V_258 = V_252 -> V_259 ;
if ( V_250 -> V_42 . V_257 . V_260 > V_252 -> V_259 - 1 )
V_250 -> V_42 . V_257 . V_260 = V_252 -> V_259 - 1 ;
strcpy ( V_250 -> V_42 . V_257 . V_48 ,
V_252 -> V_261 [ V_250 -> V_42 . V_257 . V_260 ] ) ;
return 0 ;
}
int F_168 ( struct V_239 * V_244 ,
struct V_249 * V_250 )
{
int V_259 = V_244 -> V_253 ;
if ( V_259 == 1 && ! strstr ( V_244 -> V_267 . V_48 , L_75 ) )
V_250 -> type = V_268 ;
else
V_250 -> type = V_269 ;
V_250 -> V_18 = 1 ;
V_250 -> V_42 . integer . F_7 = 0 ;
V_250 -> V_42 . integer . V_259 = V_259 ;
return 0 ;
}
int F_169 ( struct V_239 * V_244 ,
struct V_249 * V_250 )
{
struct V_270 * V_271 =
(struct V_270 * ) V_244 -> V_253 ;
int V_272 ;
if ( ! V_271 -> V_272 )
V_271 -> V_272 = V_271 -> V_259 ;
V_272 = V_271 -> V_272 ;
if ( V_272 == 1 && ! strstr ( V_244 -> V_267 . V_48 , L_75 ) )
V_250 -> type = V_268 ;
else
V_250 -> type = V_269 ;
V_250 -> V_18 = F_170 ( V_271 ) ? 2 : 1 ;
V_250 -> V_42 . integer . F_7 = 0 ;
V_250 -> V_42 . integer . V_259 = V_272 ;
return 0 ;
}
int F_171 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_270 * V_271 =
(struct V_270 * ) V_244 -> V_253 ;
struct V_4 * V_5 = F_163 ( V_244 ) ;
unsigned int V_6 = V_271 -> V_6 ;
unsigned int V_273 = V_271 -> V_274 ;
unsigned int V_275 = V_271 -> V_275 ;
unsigned int V_276 = V_271 -> V_276 ;
int V_259 = V_271 -> V_259 ;
unsigned int V_223 = ( 1 << F_172 ( V_259 ) ) - 1 ;
unsigned int V_277 = V_271 -> V_277 ;
V_263 -> V_42 . integer . V_42 [ 0 ] =
( F_4 ( V_5 , V_6 ) >> V_275 ) & V_223 ;
if ( V_277 )
V_263 -> V_42 . integer . V_42 [ 0 ] =
V_259 - V_263 -> V_42 . integer . V_42 [ 0 ] ;
if ( F_170 ( V_271 ) ) {
if ( V_6 == V_273 )
V_263 -> V_42 . integer . V_42 [ 1 ] =
( F_4 ( V_5 , V_6 ) >> V_276 ) & V_223 ;
else
V_263 -> V_42 . integer . V_42 [ 1 ] =
( F_4 ( V_5 , V_273 ) >> V_275 ) & V_223 ;
if ( V_277 )
V_263 -> V_42 . integer . V_42 [ 1 ] =
V_259 - V_263 -> V_42 . integer . V_42 [ 1 ] ;
}
return 0 ;
}
int F_173 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_270 * V_271 =
(struct V_270 * ) V_244 -> V_253 ;
struct V_4 * V_5 = F_163 ( V_244 ) ;
unsigned int V_6 = V_271 -> V_6 ;
unsigned int V_273 = V_271 -> V_274 ;
unsigned int V_275 = V_271 -> V_275 ;
unsigned int V_276 = V_271 -> V_276 ;
int V_259 = V_271 -> V_259 ;
unsigned int V_223 = ( 1 << F_172 ( V_259 ) ) - 1 ;
unsigned int V_277 = V_271 -> V_277 ;
int V_73 ;
bool V_278 = 0 ;
unsigned int V_279 = 0 ;
unsigned int V_1 , V_280 ;
V_1 = ( V_263 -> V_42 . integer . V_42 [ 0 ] & V_223 ) ;
if ( V_277 )
V_1 = V_259 - V_1 ;
V_280 = V_223 << V_275 ;
V_1 = V_1 << V_275 ;
if ( F_170 ( V_271 ) ) {
V_279 = ( V_263 -> V_42 . integer . V_42 [ 1 ] & V_223 ) ;
if ( V_277 )
V_279 = V_259 - V_279 ;
if ( V_6 == V_273 ) {
V_280 |= V_223 << V_276 ;
V_1 |= V_279 << V_276 ;
} else {
V_279 = V_279 << V_275 ;
V_278 = 1 ;
}
}
V_73 = F_153 ( V_5 , V_6 , V_280 , V_1 ) ;
if ( V_73 < 0 )
return V_73 ;
if ( V_278 )
V_73 = F_153 ( V_5 , V_273 , V_280 , V_279 ) ;
return V_73 ;
}
int F_174 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_4 * V_5 = F_163 ( V_244 ) ;
struct V_270 * V_271 =
(struct V_270 * ) V_244 -> V_253 ;
unsigned int V_6 = V_271 -> V_6 ;
unsigned int V_273 = V_271 -> V_274 ;
unsigned int V_275 = V_271 -> V_275 ;
unsigned int V_276 = V_271 -> V_276 ;
int V_259 = V_271 -> V_259 ;
int F_7 = V_271 -> F_7 ;
int V_223 = ( 1 << ( F_172 ( F_7 + V_259 ) - 1 ) ) - 1 ;
V_263 -> V_42 . integer . V_42 [ 0 ] =
( ( F_4 ( V_5 , V_6 ) >> V_275 ) - F_7 ) & V_223 ;
if ( F_170 ( V_271 ) )
V_263 -> V_42 . integer . V_42 [ 1 ] =
( ( F_4 ( V_5 , V_273 ) >> V_276 ) - F_7 ) & V_223 ;
return 0 ;
}
int F_175 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_4 * V_5 = F_163 ( V_244 ) ;
struct V_270 * V_271 =
(struct V_270 * ) V_244 -> V_253 ;
unsigned int V_6 = V_271 -> V_6 ;
unsigned int V_273 = V_271 -> V_274 ;
unsigned int V_275 = V_271 -> V_275 ;
unsigned int V_276 = V_271 -> V_276 ;
int V_259 = V_271 -> V_259 ;
int F_7 = V_271 -> F_7 ;
int V_223 = ( 1 << ( F_172 ( F_7 + V_259 ) - 1 ) ) - 1 ;
int V_73 = 0 ;
unsigned short V_1 , V_280 , V_279 = 0 ;
V_280 = V_223 << V_275 ;
V_1 = ( V_263 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & V_223 ;
V_1 = V_1 << V_275 ;
V_73 = F_153 ( V_5 , V_6 , V_280 , V_1 ) ;
if ( V_73 < 0 )
return V_73 ;
if ( F_170 ( V_271 ) ) {
V_280 = V_223 << V_276 ;
V_279 = ( V_263 -> V_42 . integer . V_42 [ 1 ] + F_7 ) & V_223 ;
V_279 = V_279 << V_276 ;
if ( F_153 ( V_5 , V_273 , V_280 , V_279 ) )
return V_73 ;
}
return 0 ;
}
int F_176 ( struct V_239 * V_244 ,
struct V_249 * V_250 )
{
struct V_270 * V_271 =
(struct V_270 * ) V_244 -> V_253 ;
int V_272 ;
int F_7 = V_271 -> F_7 ;
if ( ! V_271 -> V_272 )
V_271 -> V_272 = V_271 -> V_259 ;
V_272 = V_271 -> V_272 ;
V_250 -> type = V_269 ;
V_250 -> V_18 = 2 ;
V_250 -> V_42 . integer . F_7 = 0 ;
V_250 -> V_42 . integer . V_259 = V_272 - F_7 ;
return 0 ;
}
int F_177 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_270 * V_271 =
(struct V_270 * ) V_244 -> V_253 ;
struct V_4 * V_5 = F_163 ( V_244 ) ;
unsigned int V_6 = V_271 -> V_6 ;
int F_7 = V_271 -> F_7 ;
int V_1 = F_4 ( V_5 , V_6 ) ;
V_263 -> V_42 . integer . V_42 [ 0 ] =
( ( signed char ) ( V_1 & 0xff ) ) - F_7 ;
V_263 -> V_42 . integer . V_42 [ 1 ] =
( ( signed char ) ( ( V_1 >> 8 ) & 0xff ) ) - F_7 ;
return 0 ;
}
int F_178 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_270 * V_271 =
(struct V_270 * ) V_244 -> V_253 ;
struct V_4 * V_5 = F_163 ( V_244 ) ;
unsigned int V_6 = V_271 -> V_6 ;
int F_7 = V_271 -> F_7 ;
unsigned int V_1 ;
V_1 = ( V_263 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & 0xff ;
V_1 |= ( ( V_263 -> V_42 . integer . V_42 [ 1 ] + F_7 ) & 0xff ) << 8 ;
return F_153 ( V_5 , V_6 , 0xffff , V_1 ) ;
}
int F_179 ( struct V_239 * V_244 ,
struct V_249 * V_250 )
{
struct V_270 * V_271 =
(struct V_270 * ) V_244 -> V_253 ;
int V_272 ;
int F_7 = V_271 -> F_7 ;
if ( ! V_271 -> V_272 )
V_271 -> V_272 = V_271 -> V_259 ;
V_272 = V_271 -> V_272 ;
V_250 -> type = V_269 ;
V_250 -> V_18 = F_170 ( V_271 ) ? 2 : 1 ;
V_250 -> V_42 . integer . F_7 = 0 ;
V_250 -> V_42 . integer . V_259 = V_272 - F_7 ;
return 0 ;
}
int F_180 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_270 * V_271 =
(struct V_270 * ) V_244 -> V_253 ;
struct V_4 * V_5 = F_163 ( V_244 ) ;
unsigned int V_6 = V_271 -> V_6 ;
unsigned int V_274 = V_271 -> V_274 ;
unsigned int V_275 = V_271 -> V_275 ;
int F_7 = V_271 -> F_7 ;
int V_259 = V_271 -> V_259 ;
unsigned int V_223 = ( 1 << F_172 ( V_259 ) ) - 1 ;
unsigned int V_277 = V_271 -> V_277 ;
unsigned int V_1 , V_280 ;
int V_14 ;
V_1 = ( ( V_263 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & V_223 ) ;
if ( V_277 )
V_1 = V_259 - V_1 ;
V_280 = V_223 << V_275 ;
V_1 = V_1 << V_275 ;
V_14 = F_153 ( V_5 , V_6 , V_280 , V_1 ) ;
if ( V_14 != 0 )
return V_14 ;
if ( F_170 ( V_271 ) ) {
V_1 = ( ( V_263 -> V_42 . integer . V_42 [ 1 ] + F_7 ) & V_223 ) ;
if ( V_277 )
V_1 = V_259 - V_1 ;
V_280 = V_223 << V_275 ;
V_1 = V_1 << V_275 ;
V_14 = F_153 ( V_5 , V_274 , V_280 , V_1 ) ;
}
return V_14 ;
}
int F_181 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_270 * V_271 =
(struct V_270 * ) V_244 -> V_253 ;
struct V_4 * V_5 = F_163 ( V_244 ) ;
unsigned int V_6 = V_271 -> V_6 ;
unsigned int V_274 = V_271 -> V_274 ;
unsigned int V_275 = V_271 -> V_275 ;
int F_7 = V_271 -> F_7 ;
int V_259 = V_271 -> V_259 ;
unsigned int V_223 = ( 1 << F_172 ( V_259 ) ) - 1 ;
unsigned int V_277 = V_271 -> V_277 ;
V_263 -> V_42 . integer . V_42 [ 0 ] =
( F_4 ( V_5 , V_6 ) >> V_275 ) & V_223 ;
if ( V_277 )
V_263 -> V_42 . integer . V_42 [ 0 ] =
V_259 - V_263 -> V_42 . integer . V_42 [ 0 ] ;
V_263 -> V_42 . integer . V_42 [ 0 ] =
V_263 -> V_42 . integer . V_42 [ 0 ] - F_7 ;
if ( F_170 ( V_271 ) ) {
V_263 -> V_42 . integer . V_42 [ 1 ] =
( F_4 ( V_5 , V_274 ) >> V_275 ) & V_223 ;
if ( V_277 )
V_263 -> V_42 . integer . V_42 [ 1 ] =
V_259 - V_263 -> V_42 . integer . V_42 [ 1 ] ;
V_263 -> V_42 . integer . V_42 [ 1 ] =
V_263 -> V_42 . integer . V_42 [ 1 ] - F_7 ;
}
return 0 ;
}
int F_182 ( struct V_4 * V_5 ,
const char * V_48 , int V_259 )
{
struct V_77 * V_46 = V_5 -> V_46 -> V_77 ;
struct V_239 * V_281 ;
struct V_270 * V_271 ;
int V_185 = 0 ;
int V_14 = - V_17 ;
if ( F_183 ( ! V_48 || V_259 <= 0 ) )
return - V_17 ;
F_34 (kctl, &card->controls, list) {
if ( ! strncmp ( V_281 -> V_267 . V_48 , V_48 , sizeof( V_281 -> V_267 . V_48 ) ) ) {
V_185 = 1 ;
break;
}
}
if ( V_185 ) {
V_271 = (struct V_270 * ) V_281 -> V_253 ;
if ( V_259 <= V_271 -> V_259 ) {
V_271 -> V_272 = V_259 ;
V_14 = 0 ;
}
}
return V_14 ;
}
int F_184 ( struct V_239 * V_244 ,
struct V_249 * V_250 )
{
struct V_4 * V_5 = F_163 ( V_244 ) ;
struct V_282 * V_178 = ( void * ) V_244 -> V_253 ;
V_250 -> type = V_283 ;
V_250 -> V_18 = V_178 -> V_284 * V_5 -> V_285 ;
return 0 ;
}
int F_185 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_282 * V_178 = ( void * ) V_244 -> V_253 ;
struct V_4 * V_5 = F_163 ( V_244 ) ;
int V_14 ;
if ( V_5 -> V_104 )
V_14 = F_186 ( V_5 -> V_105 , V_178 -> V_286 ,
V_263 -> V_42 . V_287 . V_221 ,
V_178 -> V_284 * V_5 -> V_285 ) ;
else
V_14 = - V_17 ;
if ( V_14 == 0 && V_178 -> V_223 ) {
switch ( V_5 -> V_285 ) {
case 1 :
V_263 -> V_42 . V_287 . V_221 [ 0 ] &= ~ V_178 -> V_223 ;
break;
case 2 :
( ( V_288 * ) ( & V_263 -> V_42 . V_287 . V_221 ) ) [ 0 ]
&= ~ V_178 -> V_223 ;
break;
case 4 :
( ( V_289 * ) ( & V_263 -> V_42 . V_287 . V_221 ) ) [ 0 ]
&= ~ V_178 -> V_223 ;
break;
default:
return - V_17 ;
}
}
return V_14 ;
}
int F_187 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_282 * V_178 = ( void * ) V_244 -> V_253 ;
struct V_4 * V_5 = F_163 ( V_244 ) ;
int V_14 , V_8 ;
unsigned int V_1 ;
void * V_221 ;
if ( ! V_5 -> V_104 )
return - V_17 ;
V_221 = V_263 -> V_42 . V_287 . V_221 ;
V_8 = V_178 -> V_284 * V_5 -> V_285 ;
if ( V_178 -> V_223 ) {
V_14 = F_188 ( V_5 -> V_105 , V_178 -> V_286 , & V_1 ) ;
if ( V_14 != 0 )
return V_14 ;
V_1 &= V_178 -> V_223 ;
V_221 = F_189 ( V_221 , V_8 , V_37 ) ;
if ( ! V_221 )
return - V_38 ;
switch ( V_5 -> V_285 ) {
case 1 :
( ( V_290 * ) V_221 ) [ 0 ] &= ~ V_178 -> V_223 ;
( ( V_290 * ) V_221 ) [ 0 ] |= V_1 ;
break;
case 2 :
( ( V_288 * ) V_221 ) [ 0 ] &= F_190 ( ~ V_178 -> V_223 ) ;
( ( V_288 * ) V_221 ) [ 0 ] |= F_190 ( V_1 ) ;
break;
case 4 :
( ( V_289 * ) V_221 ) [ 0 ] &= F_191 ( ~ V_178 -> V_223 ) ;
( ( V_289 * ) V_221 ) [ 0 ] |= F_191 ( V_1 ) ;
break;
default:
return - V_17 ;
}
}
V_14 = F_192 ( V_5 -> V_105 , V_178 -> V_286 ,
V_221 , V_8 ) ;
if ( V_178 -> V_223 )
F_16 ( V_221 ) ;
return V_14 ;
}
int F_193 ( struct V_239 * V_244 ,
struct V_249 * V_250 )
{
struct V_291 * V_271 =
(struct V_291 * ) V_244 -> V_253 ;
V_250 -> type = V_269 ;
V_250 -> V_18 = 1 ;
V_250 -> V_42 . integer . F_7 = V_271 -> F_7 ;
V_250 -> V_42 . integer . V_259 = V_271 -> V_259 ;
return 0 ;
}
int F_194 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_291 * V_271 =
(struct V_291 * ) V_244 -> V_253 ;
struct V_4 * V_5 = F_163 ( V_244 ) ;
unsigned int V_292 = V_271 -> V_292 ;
unsigned int V_293 = V_271 -> V_293 ;
unsigned int V_294 = V_5 -> V_10 -> V_13 * V_295 ;
unsigned int V_296 = ( 1 << V_294 ) - 1 ;
unsigned int V_277 = V_271 -> V_277 ;
unsigned long V_223 = ( 1UL << V_271 -> V_297 ) - 1 ;
long F_7 = V_271 -> F_7 ;
long V_259 = V_271 -> V_259 ;
long V_1 = 0 ;
unsigned long V_298 ;
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_293 ; V_3 ++ ) {
V_298 = F_4 ( V_5 , V_292 + V_3 ) & V_296 ;
V_1 |= V_298 << ( V_294 * ( V_293 - V_3 - 1 ) ) ;
}
V_1 &= V_223 ;
if ( F_7 < 0 && V_1 > V_259 )
V_1 |= ~ V_223 ;
if ( V_277 )
V_1 = V_259 - V_1 ;
V_263 -> V_42 . integer . V_42 [ 0 ] = V_1 ;
return 0 ;
}
int F_195 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_291 * V_271 =
(struct V_291 * ) V_244 -> V_253 ;
struct V_4 * V_5 = F_163 ( V_244 ) ;
unsigned int V_292 = V_271 -> V_292 ;
unsigned int V_293 = V_271 -> V_293 ;
unsigned int V_294 = V_5 -> V_10 -> V_13 * V_295 ;
unsigned int V_296 = ( 1 << V_294 ) - 1 ;
unsigned int V_277 = V_271 -> V_277 ;
unsigned long V_223 = ( 1UL << V_271 -> V_297 ) - 1 ;
long V_259 = V_271 -> V_259 ;
long V_1 = V_263 -> V_42 . integer . V_42 [ 0 ] ;
unsigned int V_3 , V_298 , V_299 ;
int V_73 ;
if ( V_277 )
V_1 = V_259 - V_1 ;
V_1 &= V_223 ;
for ( V_3 = 0 ; V_3 < V_293 ; V_3 ++ ) {
V_298 = ( V_1 >> ( V_294 * ( V_293 - V_3 - 1 ) ) ) & V_296 ;
V_299 = ( V_223 >> ( V_294 * ( V_293 - V_3 - 1 ) ) ) & V_296 ;
V_73 = F_153 ( V_5 , V_292 + V_3 ,
V_299 , V_298 ) ;
if ( V_73 < 0 )
return V_73 ;
}
return 0 ;
}
int F_196 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_270 * V_271 =
(struct V_270 * ) V_244 -> V_253 ;
struct V_4 * V_5 = F_163 ( V_244 ) ;
unsigned int V_6 = V_271 -> V_6 ;
unsigned int V_275 = V_271 -> V_275 ;
unsigned int V_223 = 1 << V_275 ;
unsigned int V_277 = V_271 -> V_277 != 0 ;
unsigned int V_1 = F_4 ( V_5 , V_6 ) & V_223 ;
if ( V_275 != 0 && V_1 != 0 )
V_1 = V_1 >> V_275 ;
V_263 -> V_42 . V_257 . V_260 [ 0 ] = V_1 ^ V_277 ;
return 0 ;
}
int F_197 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_270 * V_271 =
(struct V_270 * ) V_244 -> V_253 ;
struct V_4 * V_5 = F_163 ( V_244 ) ;
unsigned int V_6 = V_271 -> V_6 ;
unsigned int V_275 = V_271 -> V_275 ;
unsigned int V_223 = 1 << V_275 ;
unsigned int V_277 = V_271 -> V_277 != 0 ;
unsigned int V_300 = V_263 -> V_42 . V_257 . V_260 [ 0 ] != 0 ;
unsigned int V_301 = ( V_300 ^ V_277 ) ? V_223 : 0 ;
unsigned int V_279 = ( V_300 ^ V_277 ) ? 0 : V_223 ;
int V_73 ;
V_73 = F_153 ( V_5 , V_6 , V_223 , V_301 ) ;
if ( V_73 < 0 )
return V_73 ;
V_73 = F_153 ( V_5 , V_6 , V_223 , V_279 ) ;
return V_73 ;
}
int F_198 ( struct V_57 * V_58 , int V_302 ,
unsigned int V_303 , int V_304 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_87 -> V_305 )
return V_58 -> V_10 -> V_87 -> V_305 ( V_58 , V_302 , V_303 , V_304 ) ;
else if ( V_58 -> V_5 && V_58 -> V_5 -> V_10 -> V_305 )
return V_58 -> V_5 -> V_10 -> V_305 ( V_58 -> V_5 , V_302 , 0 ,
V_303 , V_304 ) ;
else
return - V_17 ;
}
int F_199 ( struct V_4 * V_5 , int V_302 ,
int V_306 , unsigned int V_303 , int V_304 )
{
if ( V_5 -> V_10 -> V_305 )
return V_5 -> V_10 -> V_305 ( V_5 , V_302 , V_306 ,
V_303 , V_304 ) ;
else
return - V_17 ;
}
int F_200 ( struct V_57 * V_58 ,
int V_307 , int div )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_87 -> V_308 )
return V_58 -> V_10 -> V_87 -> V_308 ( V_58 , V_307 , div ) ;
else
return - V_17 ;
}
int F_201 ( struct V_57 * V_58 , int V_309 , int V_306 ,
unsigned int V_310 , unsigned int V_311 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_87 -> V_312 )
return V_58 -> V_10 -> V_87 -> V_312 ( V_58 , V_309 , V_306 ,
V_310 , V_311 ) ;
else if ( V_58 -> V_5 && V_58 -> V_5 -> V_10 -> V_312 )
return V_58 -> V_5 -> V_10 -> V_312 ( V_58 -> V_5 , V_309 , V_306 ,
V_310 , V_311 ) ;
else
return - V_17 ;
}
int F_202 ( struct V_4 * V_5 , int V_309 , int V_306 ,
unsigned int V_310 , unsigned int V_311 )
{
if ( V_5 -> V_10 -> V_312 )
return V_5 -> V_10 -> V_312 ( V_5 , V_309 , V_306 ,
V_310 , V_311 ) ;
else
return - V_17 ;
}
int F_124 ( struct V_57 * V_58 , unsigned int V_313 )
{
if ( V_58 -> V_10 == NULL )
return - V_17 ;
if ( V_58 -> V_10 -> V_87 -> V_314 == NULL )
return - V_199 ;
return V_58 -> V_10 -> V_87 -> V_314 ( V_58 , V_313 ) ;
}
int F_203 ( struct V_57 * V_58 ,
unsigned int V_315 , unsigned int V_316 , int V_317 , int V_318 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_87 -> V_319 )
return V_58 -> V_10 -> V_87 -> V_319 ( V_58 , V_315 , V_316 ,
V_317 , V_318 ) ;
else
return - V_17 ;
}
int F_204 ( struct V_57 * V_58 ,
unsigned int V_320 , unsigned int * V_321 ,
unsigned int V_322 , unsigned int * V_323 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_87 -> V_324 )
return V_58 -> V_10 -> V_87 -> V_324 ( V_58 , V_320 , V_321 ,
V_322 , V_323 ) ;
else
return - V_17 ;
}
int F_205 ( struct V_57 * V_58 , int V_325 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_87 -> V_326 )
return V_58 -> V_10 -> V_87 -> V_326 ( V_58 , V_325 ) ;
else
return - V_17 ;
}
int F_206 ( struct V_57 * V_58 , int V_327 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_87 -> V_88 )
return V_58 -> V_10 -> V_87 -> V_88 ( V_58 , V_327 ) ;
else
return - V_199 ;
}
int F_133 ( struct V_59 * V_46 )
{
int V_3 , V_14 ;
if ( ! V_46 -> V_48 || ! V_46 -> V_27 )
return - V_17 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ ) {
struct V_116 * V_328 = & V_46 -> V_64 [ V_3 ] ;
if ( ! ! V_328 -> V_124 == ! ! V_328 -> V_123 ) {
F_50 ( V_46 -> V_27 , L_76
L_77 , V_328 -> V_48 ) ;
return - V_17 ;
}
if ( ! V_328 -> V_125 ) {
F_50 ( V_46 -> V_27 , L_78
L_79 , V_328 -> V_48 ) ;
return - V_17 ;
}
if ( V_328 -> V_117 && V_328 -> V_126 ) {
F_50 ( V_46 -> V_27 , L_80
L_81 , V_328 -> V_48 ) ;
return - V_17 ;
}
if ( V_328 -> V_120 && V_328 -> V_118 ) {
F_50 ( V_46 -> V_27 , L_82
L_83 , V_328 -> V_48 ) ;
return - V_17 ;
}
if ( ! V_328 -> V_121 &&
! ( V_328 -> V_120 || V_328 -> V_118 ) ) {
F_50 ( V_46 -> V_27 , L_84
L_85 , V_328 -> V_48 ) ;
return - V_17 ;
}
}
F_95 ( V_46 -> V_27 , V_46 ) ;
F_207 ( V_46 ) ;
F_38 ( V_46 ) ;
V_46 -> V_31 = F_208 ( V_46 -> V_27 ,
sizeof( struct V_30 ) *
( V_46 -> V_66 + V_46 -> V_193 ) ,
V_37 ) ;
if ( V_46 -> V_31 == NULL )
return - V_38 ;
V_46 -> V_82 = 0 ;
V_46 -> V_162 = & V_46 -> V_31 [ V_46 -> V_66 ] ;
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ )
V_46 -> V_31 [ V_3 ] . V_64 = & V_46 -> V_64 [ V_3 ] ;
F_97 ( & V_46 -> V_154 ) ;
F_97 ( & V_46 -> V_329 ) ;
V_46 -> V_211 = 0 ;
F_96 ( & V_46 -> V_190 ) ;
F_96 ( & V_46 -> V_330 ) ;
V_14 = F_117 ( V_46 ) ;
if ( V_14 != 0 )
F_40 ( V_46 ) ;
return V_14 ;
}
int F_136 ( struct V_59 * V_46 )
{
if ( V_46 -> V_211 )
F_134 ( V_46 ) ;
F_42 ( V_46 -> V_27 , L_86 , V_46 -> V_48 ) ;
return 0 ;
}
static char * F_209 ( struct V_26 * V_27 , int * V_267 )
{
char * V_185 , V_48 [ V_331 ] ;
int V_332 , V_333 ;
if ( F_68 ( V_27 ) == NULL )
return NULL ;
F_210 ( V_48 , F_68 ( V_27 ) , V_331 ) ;
V_185 = strstr ( V_48 , V_27 -> V_10 -> V_48 ) ;
if ( V_185 ) {
if ( sscanf ( & V_185 [ strlen ( V_27 -> V_10 -> V_48 ) ] , L_87 , V_267 ) == 1 ) {
if ( * V_267 == - 1 )
V_185 [ strlen ( V_27 -> V_10 -> V_48 ) ] = '\0' ;
}
} else {
if ( sscanf ( V_48 , L_88 , & V_332 , & V_333 ) == 2 ) {
char V_334 [ V_331 ] ;
* V_267 = ( ( V_332 & 0xffff ) << 16 ) + V_333 ;
snprintf ( V_334 , V_331 , L_89 , V_27 -> V_10 -> V_48 , V_48 ) ;
F_210 ( V_48 , V_334 , V_331 ) ;
} else
* V_267 = 0 ;
}
return F_211 ( V_48 , V_37 ) ;
}
static inline char * F_212 ( struct V_26 * V_27 ,
struct V_84 * V_335 )
{
if ( V_335 -> V_48 == NULL ) {
F_50 ( V_27 , L_90
L_91 , F_68 ( V_27 ) ) ;
return NULL ;
}
return F_211 ( V_335 -> V_48 , V_37 ) ;
}
int F_213 ( struct V_26 * V_27 ,
struct V_84 * V_335 )
{
struct V_4 * V_5 ;
struct V_57 * V_58 ;
F_42 ( V_27 , L_92 , F_68 ( V_27 ) ) ;
V_58 = F_93 ( sizeof( struct V_57 ) , V_37 ) ;
if ( V_58 == NULL )
return - V_38 ;
V_58 -> V_48 = F_209 ( V_27 , & V_58 -> V_267 ) ;
if ( V_58 -> V_48 == NULL ) {
F_16 ( V_58 ) ;
return - V_38 ;
}
V_58 -> V_27 = V_27 ;
V_58 -> V_10 = V_335 ;
V_58 -> V_53 . V_27 = V_27 ;
if ( ! V_58 -> V_10 -> V_87 )
V_58 -> V_10 -> V_87 = & V_336 ;
F_146 ( & V_337 ) ;
F_34 (codec, &codec_list, list) {
if ( V_5 -> V_27 == V_27 ) {
F_42 ( V_27 , L_93 ,
V_58 -> V_48 , V_5 -> V_48 ) ;
V_58 -> V_5 = V_5 ;
break;
}
}
if ( ! V_58 -> V_5 )
V_58 -> V_53 . V_102 = 1 ;
F_87 ( & V_58 -> V_154 , & V_338 ) ;
F_129 ( & V_337 ) ;
F_42 ( V_27 , L_94 , V_58 -> V_48 ) ;
return 0 ;
}
void F_214 ( struct V_26 * V_27 )
{
struct V_57 * V_58 ;
F_34 (dai, &dai_list, list) {
if ( V_27 == V_58 -> V_27 )
goto V_185;
}
return;
V_185:
F_146 ( & V_337 ) ;
F_71 ( & V_58 -> V_154 ) ;
F_129 ( & V_337 ) ;
F_42 ( V_27 , L_95 , V_58 -> V_48 ) ;
F_16 ( V_58 -> V_48 ) ;
F_16 ( V_58 ) ;
}
int F_215 ( struct V_26 * V_27 ,
struct V_84 * V_335 , T_1 V_18 )
{
struct V_4 * V_5 ;
struct V_57 * V_58 ;
int V_3 , V_14 = 0 ;
F_42 ( V_27 , L_96 , F_68 ( V_27 ) , V_18 ) ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ ) {
V_58 = F_93 ( sizeof( struct V_57 ) , V_37 ) ;
if ( V_58 == NULL ) {
V_14 = - V_38 ;
goto V_73;
}
V_58 -> V_48 = F_212 ( V_27 , & V_335 [ V_3 ] ) ;
if ( V_58 -> V_48 == NULL ) {
F_16 ( V_58 ) ;
V_14 = - V_17 ;
goto V_73;
}
V_58 -> V_27 = V_27 ;
V_58 -> V_10 = & V_335 [ V_3 ] ;
if ( V_58 -> V_10 -> V_267 )
V_58 -> V_267 = V_58 -> V_10 -> V_267 ;
else
V_58 -> V_267 = V_3 ;
V_58 -> V_53 . V_27 = V_27 ;
if ( ! V_58 -> V_10 -> V_87 )
V_58 -> V_10 -> V_87 = & V_336 ;
F_146 ( & V_337 ) ;
F_34 (codec, &codec_list, list) {
if ( V_5 -> V_27 == V_27 ) {
F_42 ( V_27 , L_97
L_98 , V_58 -> V_48 , V_5 -> V_48 ) ;
V_58 -> V_5 = V_5 ;
break;
}
}
if ( ! V_58 -> V_5 )
V_58 -> V_53 . V_102 = 1 ;
F_87 ( & V_58 -> V_154 , & V_338 ) ;
F_129 ( & V_337 ) ;
F_42 ( V_58 -> V_27 , L_94 , V_58 -> V_48 ) ;
}
return 0 ;
V_73:
for ( V_3 -- ; V_3 >= 0 ; V_3 -- )
F_214 ( V_27 ) ;
return V_14 ;
}
void F_216 ( struct V_26 * V_27 , T_1 V_18 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ )
F_214 ( V_27 ) ;
}
int F_217 ( struct V_26 * V_27 ,
struct V_156 * V_339 )
{
struct V_54 * V_55 ;
F_42 ( V_27 , L_99 , F_68 ( V_27 ) ) ;
V_55 = F_93 ( sizeof( struct V_54 ) , V_37 ) ;
if ( V_55 == NULL )
return - V_38 ;
V_55 -> V_48 = F_209 ( V_27 , & V_55 -> V_267 ) ;
if ( V_55 -> V_48 == NULL ) {
F_16 ( V_55 ) ;
return - V_38 ;
}
V_55 -> V_27 = V_27 ;
V_55 -> V_10 = V_339 ;
V_55 -> V_53 . V_27 = V_27 ;
V_55 -> V_53 . V_55 = V_55 ;
V_55 -> V_53 . V_340 = V_339 -> V_340 ;
F_96 ( & V_55 -> V_190 ) ;
F_146 ( & V_337 ) ;
F_87 ( & V_55 -> V_154 , & V_341 ) ;
F_129 ( & V_337 ) ;
F_42 ( V_27 , L_100 , V_55 -> V_48 ) ;
return 0 ;
}
void F_218 ( struct V_26 * V_27 )
{
struct V_54 * V_55 ;
F_34 (platform, &platform_list, list) {
if ( V_27 == V_55 -> V_27 )
goto V_185;
}
return;
V_185:
F_146 ( & V_337 ) ;
F_71 ( & V_55 -> V_154 ) ;
F_129 ( & V_337 ) ;
F_42 ( V_27 , L_101 , V_55 -> V_48 ) ;
F_16 ( V_55 -> V_48 ) ;
F_16 ( V_55 ) ;
}
static void F_219 ( struct V_342 * V_65 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_125 ( V_343 ) ; V_3 ++ )
if ( V_65 -> V_232 & V_343 [ V_3 ] )
V_65 -> V_232 |= V_343 [ V_3 ] ;
}
int F_220 ( struct V_26 * V_27 ,
const struct V_142 * V_344 ,
struct V_84 * V_335 ,
int V_345 )
{
T_1 V_346 ;
struct V_4 * V_5 ;
int V_14 , V_3 ;
F_42 ( V_27 , L_102 , F_68 ( V_27 ) ) ;
V_5 = F_93 ( sizeof( struct V_4 ) , V_37 ) ;
if ( V_5 == NULL )
return - V_38 ;
V_5 -> V_48 = F_209 ( V_27 , & V_5 -> V_267 ) ;
if ( V_5 -> V_48 == NULL ) {
F_16 ( V_5 ) ;
return - V_38 ;
}
if ( V_344 -> V_187 )
V_5 -> V_187 = V_344 -> V_187 ;
else
V_5 -> V_187 = V_347 ;
V_5 -> V_148 = V_344 -> V_148 ;
V_5 -> V_217 = V_344 -> V_217 ;
V_5 -> V_214 = V_344 -> V_214 ;
V_5 -> V_215 = V_344 -> V_215 ;
V_5 -> V_216 = V_344 -> V_216 ;
V_5 -> V_348 = V_344 -> V_348 ;
V_5 -> V_53 . V_97 = V_103 ;
V_5 -> V_53 . V_27 = V_27 ;
V_5 -> V_53 . V_5 = V_5 ;
V_5 -> V_53 . V_349 = V_344 -> V_349 ;
V_5 -> V_53 . V_340 = V_344 -> V_340 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_10 = V_344 ;
V_5 -> V_345 = V_345 ;
F_96 ( & V_5 -> V_190 ) ;
if ( V_344 -> V_11 && V_344 -> V_13 ) {
V_346 = V_344 -> V_11 * V_344 -> V_13 ;
V_5 -> V_346 = V_346 ;
if ( V_344 -> V_350 ) {
V_5 -> V_351 = F_189 ( V_344 -> V_350 ,
V_346 , V_37 ) ;
if ( ! V_5 -> V_351 ) {
V_14 = - V_38 ;
goto V_352;
}
}
}
if ( V_344 -> V_353 && V_344 -> V_354 ) {
if ( ! V_5 -> V_214 )
V_5 -> V_214 = V_355 ;
if ( ! V_5 -> V_215 )
V_5 -> V_215 = V_356 ;
if ( ! V_5 -> V_216 )
V_5 -> V_216 = V_357 ;
}
for ( V_3 = 0 ; V_3 < V_345 ; V_3 ++ ) {
F_219 ( & V_335 [ V_3 ] . V_358 ) ;
F_219 ( & V_335 [ V_3 ] . V_359 ) ;
}
F_146 ( & V_337 ) ;
F_87 ( & V_5 -> V_154 , & V_360 ) ;
F_129 ( & V_337 ) ;
if ( V_345 ) {
V_14 = F_215 ( V_27 , V_335 , V_345 ) ;
if ( V_14 < 0 )
F_50 ( V_5 -> V_27 , L_103
L_104 , V_14 ) ;
}
F_42 ( V_5 -> V_27 , L_105 , V_5 -> V_48 ) ;
return 0 ;
V_352:
F_16 ( V_5 -> V_48 ) ;
F_16 ( V_5 ) ;
return V_14 ;
}
void F_221 ( struct V_26 * V_27 )
{
struct V_4 * V_5 ;
int V_3 ;
F_34 (codec, &codec_list, list) {
if ( V_27 == V_5 -> V_27 )
goto V_185;
}
return;
V_185:
if ( V_5 -> V_345 )
for ( V_3 = 0 ; V_3 < V_5 -> V_345 ; V_3 ++ )
F_214 ( V_27 ) ;
F_146 ( & V_337 ) ;
F_71 ( & V_5 -> V_154 ) ;
F_129 ( & V_337 ) ;
F_42 ( V_5 -> V_27 , L_106 , V_5 -> V_48 ) ;
F_222 ( V_5 ) ;
F_16 ( V_5 -> V_351 ) ;
F_16 ( V_5 -> V_48 ) ;
F_16 ( V_5 ) ;
}
int F_223 ( struct V_59 * V_46 ,
const char * V_361 )
{
struct V_362 * V_363 = V_46 -> V_27 -> V_119 ;
int V_14 ;
V_14 = F_224 ( V_363 , V_361 , 0 , & V_46 -> V_48 ) ;
if ( V_14 < 0 && V_14 != - V_17 ) {
F_50 ( V_46 -> V_27 ,
L_107 ,
V_361 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
int F_225 ( struct V_59 * V_46 ,
const char * V_361 )
{
struct V_362 * V_363 = V_46 -> V_27 -> V_119 ;
int V_364 ;
struct V_365 * V_366 ;
int V_3 , V_14 ;
V_364 = F_226 ( V_363 , V_361 ) ;
if ( V_364 < 0 || V_364 & 1 ) {
F_50 ( V_46 -> V_27 , L_108
L_109 , V_361 ) ;
return - V_17 ;
}
V_364 /= 2 ;
if ( ! V_364 ) {
F_50 ( V_46 -> V_27 , L_110 ,
V_361 ) ;
return - V_17 ;
}
V_366 = F_208 ( V_46 -> V_27 , V_364 * sizeof( * V_366 ) ,
V_37 ) ;
if ( ! V_366 ) {
F_50 ( V_46 -> V_27 ,
L_111 ) ;
return - V_17 ;
}
for ( V_3 = 0 ; V_3 < V_364 ; V_3 ++ ) {
V_14 = F_224 ( V_363 , V_361 ,
2 * V_3 , & V_366 [ V_3 ] . V_367 ) ;
if ( V_14 ) {
F_50 ( V_46 -> V_27 ,
L_112 ,
V_361 , 2 * V_3 , V_14 ) ;
F_16 ( V_366 ) ;
return - V_17 ;
}
V_14 = F_224 ( V_363 , V_361 ,
( 2 * V_3 ) + 1 , & V_366 [ V_3 ] . V_306 ) ;
if ( V_14 ) {
F_50 ( V_46 -> V_27 ,
L_112 ,
V_361 , ( 2 * V_3 ) + 1 , V_14 ) ;
F_16 ( V_366 ) ;
return - V_17 ;
}
}
V_46 -> V_153 = V_364 ;
V_46 -> V_152 = V_366 ;
return 0 ;
}
static int T_5 F_227 ( void )
{
#ifdef F_102
V_60 = F_24 ( L_113 , NULL ) ;
if ( F_228 ( V_60 ) || ! V_60 ) {
F_229 ( L_114 ) ;
V_60 = NULL ;
}
if ( ! F_27 ( L_115 , 0444 , V_60 , NULL ,
& V_368 ) )
F_229 ( L_116 ) ;
if ( ! F_27 ( L_117 , 0444 , V_60 , NULL ,
& V_369 ) )
F_229 ( L_118 ) ;
if ( ! F_27 ( L_119 , 0444 , V_60 , NULL ,
& V_370 ) )
F_229 ( L_120 ) ;
#endif
F_230 () ;
return F_231 ( & V_371 ) ;
}
static void T_6 F_232 ( void )
{
F_233 () ;
#ifdef F_102
F_30 ( V_60 ) ;
#endif
F_234 ( & V_371 ) ;
}
