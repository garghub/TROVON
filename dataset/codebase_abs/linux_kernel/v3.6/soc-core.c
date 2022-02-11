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
if ( V_46 -> V_105 )
V_46 -> V_105 ( V_46 ) ;
return 0 ;
}
static void F_60 ( struct V_106 * V_107 )
{
struct V_59 * V_46 =
F_61 ( V_107 , struct V_59 , V_108 ) ;
struct V_4 * V_5 ;
int V_3 ;
F_42 ( V_46 -> V_27 , L_20 ) ;
F_56 ( V_46 -> V_77 , V_109 ) ;
if ( V_46 -> V_110 )
V_46 -> V_110 ( V_46 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_83 ; V_3 ++ ) {
struct V_57 * V_92 = V_46 -> V_31 [ V_3 ] . V_92 ;
if ( V_46 -> V_31 [ V_3 ] . V_64 -> V_87 )
continue;
if ( V_92 -> V_10 -> V_111 && V_92 -> V_10 -> V_94 )
V_92 -> V_10 -> V_111 ( V_92 ) ;
}
F_34 (codec, &card->codec_dev_list, card_list) {
if ( V_5 -> V_10 -> V_111 && V_5 -> V_95 ) {
switch ( V_5 -> V_53 . V_98 ) {
case V_102 :
case V_104 :
V_5 -> V_10 -> V_111 ( V_5 ) ;
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
V_112 ) ;
F_59 ( & V_46 -> V_31 [ V_3 ] ,
V_101 ,
V_112 ) ;
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
if ( V_92 -> V_10 -> V_111 && ! V_92 -> V_10 -> V_94 )
V_92 -> V_10 -> V_111 ( V_92 ) ;
if ( V_55 -> V_10 -> V_111 && V_55 -> V_95 ) {
V_55 -> V_10 -> V_111 ( V_92 ) ;
V_55 -> V_95 = 0 ;
}
}
if ( V_46 -> V_113 )
V_46 -> V_113 ( V_46 ) ;
F_42 ( V_46 -> V_27 , L_22 ) ;
F_56 ( V_46 -> V_77 , V_81 ) ;
}
int F_62 ( struct V_26 * V_27 )
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
F_60 ( & V_46 -> V_108 ) ;
} else {
F_42 ( V_27 , L_24 ) ;
if ( ! F_63 ( & V_46 -> V_108 ) )
F_64 ( V_27 , L_25 ) ;
}
return 0 ;
}
static int F_65 ( struct V_59 * V_46 , int V_114 )
{
struct V_115 * V_64 = & V_46 -> V_64 [ V_114 ] ;
struct V_30 * V_31 = & V_46 -> V_31 [ V_114 ] ;
struct V_4 * V_5 ;
struct V_54 * V_55 ;
struct V_57 * V_84 , * V_92 ;
const char * V_116 ;
F_42 ( V_46 -> V_27 , L_26 , V_64 -> V_48 , V_114 ) ;
F_34 (cpu_dai, &dai_list, list) {
if ( V_64 -> V_117 &&
( V_92 -> V_27 -> V_118 != V_64 -> V_117 ) )
continue;
if ( V_64 -> V_119 &&
strcmp ( F_66 ( V_92 -> V_27 ) , V_64 -> V_119 ) )
continue;
if ( V_64 -> V_120 &&
strcmp ( V_92 -> V_48 , V_64 -> V_120 ) )
continue;
V_31 -> V_92 = V_92 ;
}
if ( ! V_31 -> V_92 ) {
F_64 ( V_46 -> V_27 , L_27 ,
V_64 -> V_120 ) ;
return - V_121 ;
}
F_34 (codec, &codec_list, list) {
if ( V_64 -> V_122 ) {
if ( V_5 -> V_27 -> V_118 != V_64 -> V_122 )
continue;
} else {
if ( strcmp ( V_5 -> V_48 , V_64 -> V_123 ) )
continue;
}
V_31 -> V_5 = V_5 ;
F_34 (codec_dai, &dai_list, list) {
if ( V_5 -> V_27 == V_84 -> V_27 &&
! strcmp ( V_84 -> V_48 ,
V_64 -> V_124 ) ) {
V_31 -> V_84 = V_84 ;
}
}
if ( ! V_31 -> V_84 ) {
F_64 ( V_46 -> V_27 , L_28 ,
V_64 -> V_124 ) ;
return - V_121 ;
}
}
if ( ! V_31 -> V_5 ) {
F_64 ( V_46 -> V_27 , L_29 ,
V_64 -> V_123 ) ;
return - V_121 ;
}
V_116 = V_64 -> V_116 ;
if ( ! V_116 && ! V_64 -> V_125 )
V_116 = L_30 ;
F_34 (platform, &platform_list, list) {
if ( V_64 -> V_125 ) {
if ( V_55 -> V_27 -> V_118 !=
V_64 -> V_125 )
continue;
} else {
if ( strcmp ( V_55 -> V_48 , V_116 ) )
continue;
}
V_31 -> V_55 = V_55 ;
}
if ( ! V_31 -> V_55 ) {
F_64 ( V_46 -> V_27 , L_31 ,
V_64 -> V_116 ) ;
return - V_121 ;
}
V_46 -> V_83 ++ ;
return 0 ;
}
static int F_67 ( struct V_54 * V_55 )
{
int V_14 ;
if ( V_55 -> V_10 -> remove ) {
V_14 = V_55 -> V_10 -> remove ( V_55 ) ;
if ( V_14 < 0 )
F_68 ( L_32 ,
V_55 -> V_48 , V_14 ) ;
}
F_69 ( & V_55 -> V_53 ) ;
F_32 ( V_55 ) ;
V_55 -> V_126 = 0 ;
F_70 ( & V_55 -> V_127 ) ;
F_71 ( V_55 -> V_27 -> V_10 -> V_128 ) ;
return 0 ;
}
static void F_72 ( struct V_4 * V_5 )
{
int V_73 ;
if ( V_5 -> V_10 -> remove ) {
V_73 = V_5 -> V_10 -> remove ( V_5 ) ;
if ( V_73 < 0 )
F_64 ( V_5 -> V_27 ,
L_32 ,
V_5 -> V_48 , V_73 ) ;
}
F_69 ( & V_5 -> V_53 ) ;
F_29 ( V_5 ) ;
V_5 -> V_126 = 0 ;
F_70 ( & V_5 -> V_127 ) ;
F_71 ( V_5 -> V_27 -> V_10 -> V_128 ) ;
}
static void F_73 ( struct V_59 * V_46 , int V_114 , int V_129 )
{
struct V_30 * V_31 = & V_46 -> V_31 [ V_114 ] ;
struct V_57 * V_84 = V_31 -> V_84 , * V_92 = V_31 -> V_92 ;
int V_73 ;
if ( V_31 -> V_130 ) {
F_74 ( V_31 -> V_27 , & V_131 ) ;
F_74 ( V_31 -> V_27 , & V_132 ) ;
F_45 ( V_31 -> V_27 ) ;
V_31 -> V_130 = 0 ;
}
if ( V_84 && V_84 -> V_126 &&
V_84 -> V_10 -> V_133 == V_129 ) {
if ( V_84 -> V_10 -> remove ) {
V_73 = V_84 -> V_10 -> remove ( V_84 ) ;
if ( V_73 < 0 )
F_68 ( L_32 ,
V_84 -> V_48 , V_73 ) ;
}
V_84 -> V_126 = 0 ;
F_70 ( & V_84 -> V_127 ) ;
}
if ( V_92 && V_92 -> V_126 &&
V_92 -> V_10 -> V_133 == V_129 ) {
if ( V_92 -> V_10 -> remove ) {
V_73 = V_92 -> V_10 -> remove ( V_92 ) ;
if ( V_73 < 0 )
F_68 ( L_32 ,
V_92 -> V_48 , V_73 ) ;
}
V_92 -> V_126 = 0 ;
F_70 ( & V_92 -> V_127 ) ;
if ( ! V_92 -> V_5 ) {
F_69 ( & V_92 -> V_53 ) ;
F_71 ( V_92 -> V_27 -> V_10 -> V_128 ) ;
}
}
}
static void F_75 ( struct V_59 * V_46 , int V_114 ,
int V_129 )
{
struct V_30 * V_31 = & V_46 -> V_31 [ V_114 ] ;
struct V_57 * V_92 = V_31 -> V_92 ;
struct V_57 * V_84 = V_31 -> V_84 ;
struct V_54 * V_55 = V_31 -> V_55 ;
struct V_4 * V_5 ;
if ( V_55 && V_55 -> V_126 &&
V_55 -> V_10 -> V_133 == V_129 ) {
F_67 ( V_55 ) ;
}
if ( V_84 ) {
V_5 = V_84 -> V_5 ;
if ( V_5 && V_5 -> V_126 &&
V_5 -> V_10 -> V_133 == V_129 )
F_72 ( V_5 ) ;
}
if ( V_92 ) {
V_5 = V_92 -> V_5 ;
if ( V_5 && V_5 -> V_126 &&
V_5 -> V_10 -> V_133 == V_129 )
F_72 ( V_5 ) ;
}
}
static void F_76 ( struct V_59 * V_46 )
{
int V_58 , V_129 ;
for ( V_129 = V_134 ; V_129 <= V_135 ;
V_129 ++ ) {
for ( V_58 = 0 ; V_58 < V_46 -> V_83 ; V_58 ++ )
F_73 ( V_46 , V_58 , V_129 ) ;
}
for ( V_129 = V_134 ; V_129 <= V_135 ;
V_129 ++ ) {
for ( V_58 = 0 ; V_58 < V_46 -> V_83 ; V_58 ++ )
F_75 ( V_46 , V_58 , V_129 ) ;
}
V_46 -> V_83 = 0 ;
}
static void F_77 ( struct V_59 * V_46 ,
struct V_4 * V_5 )
{
int V_3 ;
if ( V_46 -> V_136 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_46 -> V_137 ; V_3 ++ ) {
struct V_138 * V_139 = & V_46 -> V_136 [ V_3 ] ;
if ( V_139 -> F_66 && ! strcmp ( V_5 -> V_48 , V_139 -> F_66 ) ) {
V_5 -> V_140 = V_139 -> V_140 ;
break;
}
}
}
static int F_78 ( struct V_59 * V_46 ,
struct V_4 * V_5 )
{
int V_14 = 0 ;
const struct V_141 * V_10 = V_5 -> V_10 ;
struct V_57 * V_58 ;
V_5 -> V_46 = V_46 ;
V_5 -> V_53 . V_46 = V_46 ;
F_77 ( V_46 , V_5 ) ;
if ( ! F_79 ( V_5 -> V_27 -> V_10 -> V_128 ) )
return - V_142 ;
F_23 ( V_5 ) ;
if ( V_10 -> V_143 )
F_80 ( & V_5 -> V_53 , V_10 -> V_143 ,
V_10 -> V_144 ) ;
F_34 (dai, &dai_list, list) {
if ( V_58 -> V_27 != V_5 -> V_27 )
continue;
F_81 ( & V_5 -> V_53 , V_58 ) ;
}
V_5 -> V_53 . V_103 = V_10 -> V_103 ;
if ( V_10 -> V_145 ) {
V_14 = V_10 -> V_145 ( V_5 ) ;
if ( V_14 < 0 ) {
F_64 ( V_5 -> V_27 ,
L_33 ,
V_5 -> V_48 , V_14 ) ;
goto V_146;
}
}
if ( ! V_5 -> V_147 && F_82 ( V_5 -> V_27 , NULL ) )
F_83 ( V_5 , 0 , 0 , V_148 ) ;
if ( V_10 -> V_149 )
F_84 ( V_5 , V_10 -> V_149 ,
V_10 -> V_150 ) ;
if ( V_10 -> V_151 )
F_85 ( & V_5 -> V_53 , V_10 -> V_151 ,
V_10 -> V_152 ) ;
V_5 -> V_126 = 1 ;
F_86 ( & V_5 -> V_127 , & V_46 -> V_80 ) ;
F_86 ( & V_5 -> V_53 . V_153 , & V_46 -> V_154 ) ;
return 0 ;
V_146:
F_29 ( V_5 ) ;
F_71 ( V_5 -> V_27 -> V_10 -> V_128 ) ;
return V_14 ;
}
static int F_87 ( struct V_59 * V_46 ,
struct V_54 * V_55 )
{
int V_14 = 0 ;
const struct V_155 * V_10 = V_55 -> V_10 ;
struct V_57 * V_58 ;
V_55 -> V_46 = V_46 ;
V_55 -> V_53 . V_46 = V_46 ;
if ( ! F_79 ( V_55 -> V_27 -> V_10 -> V_128 ) )
return - V_142 ;
F_31 ( V_55 ) ;
if ( V_10 -> V_143 )
F_80 ( & V_55 -> V_53 ,
V_10 -> V_143 , V_10 -> V_144 ) ;
F_34 (dai, &dai_list, list) {
if ( V_58 -> V_27 != V_55 -> V_27 )
continue;
F_81 ( & V_55 -> V_53 , V_58 ) ;
}
V_55 -> V_53 . V_103 = 1 ;
if ( V_10 -> V_145 ) {
V_14 = V_10 -> V_145 ( V_55 ) ;
if ( V_14 < 0 ) {
F_64 ( V_55 -> V_27 ,
L_34 ,
V_55 -> V_48 , V_14 ) ;
goto V_146;
}
}
if ( V_10 -> V_149 )
F_88 ( V_55 , V_10 -> V_149 ,
V_10 -> V_150 ) ;
if ( V_10 -> V_151 )
F_85 ( & V_55 -> V_53 , V_10 -> V_151 ,
V_10 -> V_152 ) ;
V_55 -> V_126 = 1 ;
F_86 ( & V_55 -> V_127 , & V_46 -> V_156 ) ;
F_86 ( & V_55 -> V_53 . V_153 , & V_46 -> V_154 ) ;
return 0 ;
V_146:
F_32 ( V_55 ) ;
F_71 ( V_55 -> V_27 -> V_10 -> V_128 ) ;
return V_14 ;
}
static void F_89 ( struct V_26 * V_27 )
{
F_16 ( V_27 ) ;
}
static int F_90 ( struct V_59 * V_46 ,
struct V_4 * V_5 ,
int V_114 , int V_157 )
{
struct V_115 * V_64 = NULL ;
struct V_158 * V_159 = NULL ;
struct V_30 * V_31 ;
const char * V_160 , * V_48 ;
int V_14 = 0 ;
if ( ! V_157 ) {
V_64 = & V_46 -> V_64 [ V_114 ] ;
V_31 = & V_46 -> V_31 [ V_114 ] ;
V_48 = V_64 -> V_48 ;
} else {
V_159 = & V_46 -> V_159 [ V_114 ] ;
V_31 = & V_46 -> V_161 [ V_114 ] ;
V_48 = V_159 -> V_48 ;
}
V_31 -> V_46 = V_46 ;
F_91 ( & V_5 -> V_53 ) ;
V_160 = V_5 -> V_140 ;
V_5 -> V_140 = NULL ;
if ( ! V_157 && V_64 -> V_162 )
V_14 = V_64 -> V_162 ( V_31 ) ;
else if ( V_157 && V_159 -> V_162 )
V_14 = V_159 -> V_162 ( & V_5 -> V_53 ) ;
if ( V_14 < 0 ) {
F_64 ( V_46 -> V_27 , L_35 , V_48 , V_14 ) ;
return V_14 ;
}
V_5 -> V_140 = V_160 ;
V_31 -> V_5 = V_5 ;
V_31 -> V_27 = F_92 ( sizeof( struct V_26 ) , V_37 ) ;
if ( ! V_31 -> V_27 )
return - V_38 ;
F_93 ( V_31 -> V_27 ) ;
V_31 -> V_27 -> V_75 = V_46 -> V_27 ;
V_31 -> V_27 -> V_76 = F_89 ;
V_31 -> V_27 -> V_163 = V_48 ;
F_94 ( V_31 -> V_27 , V_31 ) ;
F_95 ( & V_31 -> V_164 ) ;
F_96 ( & V_31 -> V_165 [ V_99 ] . V_166 ) ;
F_96 ( & V_31 -> V_165 [ V_101 ] . V_166 ) ;
F_96 ( & V_31 -> V_165 [ V_99 ] . V_167 ) ;
F_96 ( & V_31 -> V_165 [ V_101 ] . V_167 ) ;
V_14 = F_97 ( V_31 -> V_27 ) ;
if ( V_14 < 0 ) {
F_64 ( V_46 -> V_27 ,
L_36 , V_14 ) ;
return V_14 ;
}
V_31 -> V_130 = 1 ;
V_14 = F_98 ( V_31 -> V_27 ) ;
if ( V_14 < 0 )
F_64 ( V_5 -> V_27 ,
L_37 ,
V_14 ) ;
V_14 = F_99 ( V_31 -> V_27 , & V_132 ) ;
if ( V_14 < 0 )
F_64 ( V_5 -> V_27 ,
L_38 , V_14 ) ;
#ifdef F_100
if ( ! V_157 && ! V_64 -> V_168 )
goto V_169;
V_14 = F_101 ( V_31 ) ;
if ( V_14 < 0 )
F_64 ( V_31 -> V_27 , L_39 , V_14 ) ;
V_169:
#endif
return 0 ;
}
static int F_102 ( struct V_59 * V_46 , int V_114 ,
int V_129 )
{
struct V_30 * V_31 = & V_46 -> V_31 [ V_114 ] ;
struct V_57 * V_92 = V_31 -> V_92 ;
struct V_57 * V_84 = V_31 -> V_84 ;
struct V_54 * V_55 = V_31 -> V_55 ;
int V_14 ;
if ( V_92 -> V_5 &&
! V_92 -> V_5 -> V_126 &&
V_92 -> V_5 -> V_10 -> V_170 == V_129 ) {
V_14 = F_78 ( V_46 , V_92 -> V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_84 -> V_5 -> V_126 &&
V_84 -> V_5 -> V_10 -> V_170 == V_129 ) {
V_14 = F_78 ( V_46 , V_84 -> V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_55 -> V_126 &&
V_55 -> V_10 -> V_170 == V_129 ) {
V_14 = F_87 ( V_46 , V_55 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
static int F_103 ( struct V_59 * V_46 , int V_114 , int V_129 )
{
struct V_115 * V_64 = & V_46 -> V_64 [ V_114 ] ;
struct V_30 * V_31 = & V_46 -> V_31 [ V_114 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
struct V_54 * V_55 = V_31 -> V_55 ;
struct V_57 * V_84 = V_31 -> V_84 ;
struct V_57 * V_92 = V_31 -> V_92 ;
struct V_171 * V_172 , * V_173 ;
int V_14 ;
F_42 ( V_46 -> V_27 , L_40 ,
V_46 -> V_48 , V_114 , V_129 ) ;
V_92 -> V_55 = V_55 ;
V_84 -> V_46 = V_46 ;
V_92 -> V_46 = V_46 ;
V_31 -> V_32 = V_32 ;
if ( ! V_92 -> V_126 &&
V_92 -> V_10 -> V_170 == V_129 ) {
if ( ! V_92 -> V_5 ) {
V_92 -> V_53 . V_46 = V_46 ;
if ( ! F_79 ( V_92 -> V_27 -> V_10 -> V_128 ) )
return - V_142 ;
F_86 ( & V_92 -> V_53 . V_153 , & V_46 -> V_154 ) ;
F_81 ( & V_92 -> V_53 , V_92 ) ;
}
if ( V_92 -> V_10 -> V_145 ) {
V_14 = V_92 -> V_10 -> V_145 ( V_92 ) ;
if ( V_14 < 0 ) {
F_68 ( L_41 ,
V_92 -> V_48 , V_14 ) ;
F_71 ( V_92 -> V_27 -> V_10 -> V_128 ) ;
return V_14 ;
}
}
V_92 -> V_126 = 1 ;
F_86 ( & V_92 -> V_127 , & V_46 -> V_174 ) ;
}
if ( ! V_84 -> V_126 && V_84 -> V_10 -> V_170 == V_129 ) {
if ( V_84 -> V_10 -> V_145 ) {
V_14 = V_84 -> V_10 -> V_145 ( V_84 ) ;
if ( V_14 < 0 ) {
F_68 ( L_42 ,
V_84 -> V_48 , V_14 ) ;
return V_14 ;
}
}
V_84 -> V_126 = 1 ;
F_86 ( & V_84 -> V_127 , & V_46 -> V_174 ) ;
}
if ( V_129 != V_135 )
return 0 ;
V_14 = F_90 ( V_46 , V_5 , V_114 , 0 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_99 ( V_31 -> V_27 , & V_131 ) ;
if ( V_14 < 0 )
F_104 ( L_43 , V_14 ) ;
if ( ! V_64 -> V_175 ) {
V_14 = F_105 ( V_31 , V_114 ) ;
if ( V_14 < 0 ) {
F_68 ( L_44 ,
V_64 -> V_176 , V_14 ) ;
return V_14 ;
}
} else {
V_172 = V_84 -> V_177 ;
V_173 = V_92 -> V_178 ;
if ( V_172 && V_173 ) {
V_14 = F_106 ( V_46 , V_64 -> V_175 ,
V_173 , V_172 ) ;
if ( V_14 != 0 ) {
F_64 ( V_46 -> V_27 , L_45 ,
V_172 -> V_48 , V_173 -> V_48 , V_14 ) ;
return V_14 ;
}
}
V_172 = V_92 -> V_177 ;
V_173 = V_84 -> V_178 ;
if ( V_172 && V_173 ) {
V_14 = F_106 ( V_46 , V_64 -> V_175 ,
V_173 , V_172 ) ;
if ( V_14 != 0 ) {
F_64 ( V_46 -> V_27 , L_45 ,
V_172 -> V_48 , V_173 -> V_48 , V_14 ) ;
return V_14 ;
}
}
}
if ( V_31 -> V_84 -> V_10 -> V_94 )
F_107 ( V_5 -> V_71 , V_31 -> V_92 -> V_179 ) ;
return 0 ;
}
static int F_108 ( struct V_30 * V_31 )
{
int V_14 ;
if ( V_31 -> V_84 -> V_10 -> V_94 && ! V_31 -> V_5 -> V_180 ) {
if ( ! V_31 -> V_5 -> V_181 )
return 0 ;
V_14 = F_47 ( V_31 -> V_5 ) ;
if ( V_14 < 0 ) {
F_68 ( L_46 , V_14 ) ;
return V_14 ;
}
V_31 -> V_5 -> V_180 = 1 ;
}
return 0 ;
}
static void F_109 ( struct V_4 * V_5 )
{
if ( V_5 -> V_180 ) {
F_44 ( V_5 ) ;
V_5 -> V_180 = 0 ;
}
}
static int F_110 ( struct V_59 * V_46 , int V_114 )
{
struct V_158 * V_159 = & V_46 -> V_159 [ V_114 ] ;
struct V_4 * V_5 ;
F_34 (codec, &codec_list, list) {
if ( ! strcmp ( V_5 -> V_48 , V_159 -> V_123 ) )
return 0 ;
}
F_64 ( V_46 -> V_27 , L_47 , V_159 -> V_123 ) ;
return - V_121 ;
}
static int F_111 ( struct V_59 * V_46 , int V_114 )
{
struct V_158 * V_159 = & V_46 -> V_159 [ V_114 ] ;
struct V_4 * V_5 ;
int V_14 = - V_142 ;
F_34 (codec, &codec_list, list) {
if ( ! strcmp ( V_5 -> V_48 , V_159 -> V_123 ) ) {
if ( V_5 -> V_126 ) {
F_64 ( V_5 -> V_27 ,
L_48 ) ;
V_14 = - V_182 ;
goto V_169;
}
goto V_183;
}
}
F_64 ( V_46 -> V_27 , L_49 , V_159 -> V_123 ) ;
return - V_121 ;
V_183:
V_14 = F_78 ( V_46 , V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_90 ( V_46 , V_5 , V_114 , 1 ) ;
V_169:
return V_14 ;
}
static void F_112 ( struct V_59 * V_46 , int V_114 )
{
struct V_30 * V_31 = & V_46 -> V_161 [ V_114 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
if ( V_31 -> V_130 ) {
F_74 ( V_31 -> V_27 , & V_132 ) ;
F_113 ( V_31 -> V_27 ) ;
V_31 -> V_130 = 0 ;
}
if ( V_5 && V_5 -> V_126 )
F_72 ( V_5 ) ;
}
static int F_114 ( struct V_4 * V_5 ,
enum V_184 V_185 )
{
int V_14 ;
if ( V_5 -> V_186 )
return 0 ;
if ( V_185 && V_5 -> V_185 != V_185 )
V_5 -> V_185 = V_185 ;
V_14 = F_115 ( V_5 ) ;
if ( V_14 < 0 ) {
F_64 ( V_5 -> V_27 , L_50 ,
V_14 ) ;
return V_14 ;
}
V_5 -> V_186 = 1 ;
return 0 ;
}
static int F_116 ( struct V_59 * V_46 )
{
struct V_4 * V_5 ;
struct V_138 * V_136 ;
enum V_184 V_185 ;
struct V_115 * V_64 ;
int V_14 , V_3 , V_129 , V_187 ;
F_117 ( & V_46 -> V_188 , V_189 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ ) {
V_14 = F_65 ( V_46 , V_3 ) ;
if ( V_14 != 0 )
goto V_190;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_191 ; V_3 ++ ) {
V_14 = F_110 ( V_46 , V_3 ) ;
if ( V_14 != 0 )
goto V_190;
}
F_34 (codec, &codec_list, list) {
if ( V_5 -> V_186 )
continue;
V_185 = 0 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_137 ; ++ V_3 ) {
V_136 = & V_46 -> V_136 [ V_3 ] ;
if ( ! strcmp ( V_5 -> V_48 , V_136 -> F_66 ) ) {
V_185 = V_136 -> V_185 ;
if ( V_185 && V_185
!= V_5 -> V_185 )
break;
}
}
V_14 = F_114 ( V_5 , V_185 ) ;
if ( V_14 < 0 )
goto V_190;
}
V_14 = F_118 ( V_192 , V_193 ,
V_46 -> V_128 , 0 , & V_46 -> V_77 ) ;
if ( V_14 < 0 ) {
F_68 ( L_51 ,
V_46 -> V_48 , V_14 ) ;
goto V_190;
}
V_46 -> V_77 -> V_27 = V_46 -> V_27 ;
V_46 -> V_53 . V_98 = V_104 ;
V_46 -> V_53 . V_27 = V_46 -> V_27 ;
V_46 -> V_53 . V_46 = V_46 ;
F_86 ( & V_46 -> V_53 . V_153 , & V_46 -> V_154 ) ;
#ifdef F_100
F_28 ( & V_46 -> V_53 , V_46 -> V_45 ) ;
#endif
#ifdef F_119
F_120 ( & V_46 -> V_108 , F_60 ) ;
#endif
if ( V_46 -> V_143 )
F_80 ( & V_46 -> V_53 , V_46 -> V_143 ,
V_46 -> V_144 ) ;
if ( V_46 -> V_145 ) {
V_14 = V_46 -> V_145 ( V_46 ) ;
if ( V_14 < 0 )
goto V_194;
}
for ( V_129 = V_134 ; V_129 <= V_135 ;
V_129 ++ ) {
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ ) {
V_14 = F_102 ( V_46 , V_3 , V_129 ) ;
if ( V_14 < 0 ) {
F_68 ( L_52 ,
V_46 -> V_48 , V_14 ) ;
goto V_195;
}
}
}
for ( V_129 = V_134 ; V_129 <= V_135 ;
V_129 ++ ) {
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ ) {
V_14 = F_103 ( V_46 , V_3 , V_129 ) ;
if ( V_14 < 0 ) {
F_68 ( L_52 ,
V_46 -> V_48 , V_14 ) ;
goto V_195;
}
}
}
for ( V_3 = 0 ; V_3 < V_46 -> V_191 ; V_3 ++ ) {
V_14 = F_111 ( V_46 , V_3 ) ;
if ( V_14 < 0 ) {
F_68 ( L_53 ,
V_46 -> V_48 , V_14 ) ;
goto V_196;
}
}
F_121 ( V_46 ) ;
if ( V_46 -> V_149 )
F_122 ( V_46 , V_46 -> V_149 , V_46 -> V_150 ) ;
if ( V_46 -> V_151 )
F_85 ( & V_46 -> V_53 , V_46 -> V_151 ,
V_46 -> V_152 ) ;
F_91 ( & V_46 -> V_53 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ ) {
V_64 = & V_46 -> V_64 [ V_3 ] ;
V_187 = V_64 -> V_187 ;
if ( V_187 ) {
V_14 = F_123 ( V_46 -> V_31 [ V_3 ] . V_84 ,
V_187 ) ;
if ( V_14 != 0 && V_14 != - V_197 )
F_25 ( V_46 -> V_31 [ V_3 ] . V_84 -> V_27 ,
L_54 ,
V_14 ) ;
}
if ( V_187 &&
( V_64 -> V_116 || V_64 -> V_125 ) ) {
V_14 = F_123 ( V_46 -> V_31 [ V_3 ] . V_92 ,
V_187 ) ;
if ( V_14 != 0 && V_14 != - V_197 )
F_25 ( V_46 -> V_31 [ V_3 ] . V_92 -> V_27 ,
L_54 ,
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
V_14 = F_123 ( V_46 -> V_31 [ V_3 ] . V_92 ,
V_187 ) ;
if ( V_14 != 0 && V_14 != - V_197 )
F_25 ( V_46 -> V_31 [ V_3 ] . V_92 -> V_27 ,
L_54 ,
V_14 ) ;
}
}
snprintf ( V_46 -> V_77 -> V_203 , sizeof( V_46 -> V_77 -> V_203 ) ,
L_55 , V_46 -> V_48 ) ;
snprintf ( V_46 -> V_77 -> V_204 , sizeof( V_46 -> V_77 -> V_204 ) ,
L_55 , V_46 -> V_205 ? V_46 -> V_205 : V_46 -> V_48 ) ;
snprintf ( V_46 -> V_77 -> V_10 , sizeof( V_46 -> V_77 -> V_10 ) ,
L_55 , V_46 -> V_206 ? V_46 -> V_206 : V_46 -> V_48 ) ;
for ( V_3 = 0 ; V_3 < F_124 ( V_46 -> V_77 -> V_10 ) ; V_3 ++ ) {
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
if ( V_46 -> V_207 ) {
V_14 = V_46 -> V_207 ( V_46 ) ;
if ( V_14 < 0 ) {
F_64 ( V_46 -> V_27 , L_56 ,
V_46 -> V_48 , V_14 ) ;
goto V_196;
}
}
F_91 ( & V_46 -> V_53 ) ;
if ( V_46 -> V_208 )
F_34 (codec, &card->codec_dev_list, card_list)
F_125 ( V_5 ) ;
V_14 = F_126 ( V_46 -> V_77 ) ;
if ( V_14 < 0 ) {
F_68 ( L_57 ,
V_46 -> V_48 , V_14 ) ;
goto V_196;
}
#ifdef F_127
for ( V_3 = 0 ; V_3 < V_46 -> V_83 ; V_3 ++ ) {
V_14 = F_108 ( & V_46 -> V_31 [ V_3 ] ) ;
if ( V_14 < 0 ) {
F_68 ( L_58 ,
V_46 -> V_48 , V_14 ) ;
while ( -- V_3 >= 0 )
F_109 ( V_46 -> V_31 [ V_3 ] . V_5 ) ;
goto V_196;
}
}
#endif
V_46 -> V_209 = 1 ;
F_128 ( & V_46 -> V_53 ) ;
F_129 ( & V_46 -> V_188 ) ;
return 0 ;
V_196:
for ( V_3 = 0 ; V_3 < V_46 -> V_191 ; V_3 ++ )
F_112 ( V_46 , V_3 ) ;
V_195:
F_76 ( V_46 ) ;
V_194:
if ( V_46 -> remove )
V_46 -> remove ( V_46 ) ;
F_130 ( V_46 -> V_77 ) ;
V_190:
F_129 ( & V_46 -> V_188 ) ;
return V_14 ;
}
static int F_131 ( struct V_210 * V_211 )
{
struct V_59 * V_46 = F_132 ( V_211 ) ;
int V_14 = 0 ;
if ( ! V_46 )
return - V_17 ;
F_25 ( & V_211 -> V_27 ,
L_59 ,
V_46 -> V_48 ) ;
V_46 -> V_27 = & V_211 -> V_27 ;
V_14 = F_133 ( V_46 ) ;
if ( V_14 != 0 ) {
F_64 ( & V_211 -> V_27 , L_60 ) ;
return V_14 ;
}
return 0 ;
}
static int F_134 ( struct V_59 * V_46 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_83 ; V_3 ++ ) {
struct V_30 * V_31 = & V_46 -> V_31 [ V_3 ] ;
F_58 ( & V_31 -> V_96 ) ;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_191 ; V_3 ++ )
F_112 ( V_46 , V_3 ) ;
F_76 ( V_46 ) ;
F_40 ( V_46 ) ;
if ( V_46 -> remove )
V_46 -> remove ( V_46 ) ;
F_69 ( & V_46 -> V_53 ) ;
F_130 ( V_46 -> V_77 ) ;
return 0 ;
}
static int F_135 ( struct V_210 * V_211 )
{
struct V_59 * V_46 = F_132 ( V_211 ) ;
F_136 ( V_46 ) ;
return 0 ;
}
int F_137 ( struct V_26 * V_27 )
{
struct V_59 * V_46 = F_9 ( V_27 ) ;
int V_3 ;
if ( ! V_46 -> V_209 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_83 ; V_3 ++ ) {
struct V_30 * V_31 = & V_46 -> V_31 [ V_3 ] ;
F_58 ( & V_31 -> V_96 ) ;
}
F_138 ( V_46 ) ;
return 0 ;
}
int F_139 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_212 )
return V_5 -> V_212 ( V_5 , V_6 ) ;
else
return 0 ;
}
int F_6 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_213 )
return V_5 -> V_213 ( V_5 , V_6 ) ;
else
return 1 ;
}
int F_140 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_214 )
return V_5 -> V_214 ( V_5 , V_6 ) ;
else
return 1 ;
}
int F_141 ( struct V_54 * V_55 ,
unsigned int V_6 )
{
unsigned int V_14 ;
if ( ! V_55 -> V_10 -> V_215 ) {
F_64 ( V_55 -> V_27 , L_61 ) ;
return - 1 ;
}
V_14 = V_55 -> V_10 -> V_215 ( V_55 , V_6 ) ;
F_42 ( V_55 -> V_27 , L_62 , V_6 , V_14 ) ;
F_142 ( V_55 , V_6 , V_14 ) ;
return V_14 ;
}
int F_143 ( struct V_54 * V_55 ,
unsigned int V_6 , unsigned int V_1 )
{
if ( ! V_55 -> V_10 -> V_147 ) {
F_64 ( V_55 -> V_27 , L_63 ) ;
return - 1 ;
}
F_42 ( V_55 -> V_27 , L_64 , V_6 , V_1 ) ;
F_144 ( V_55 , V_6 , V_1 ) ;
return V_55 -> V_10 -> V_147 ( V_55 , V_6 , V_1 ) ;
}
int F_145 ( struct V_4 * V_5 ,
struct V_216 * V_88 , int V_114 )
{
F_146 ( & V_5 -> V_188 ) ;
V_5 -> V_71 = F_92 ( sizeof( struct V_217 ) , V_37 ) ;
if ( V_5 -> V_71 == NULL ) {
F_129 ( & V_5 -> V_188 ) ;
return - V_38 ;
}
V_5 -> V_71 -> V_72 = F_92 ( sizeof( struct V_218 ) , V_37 ) ;
if ( V_5 -> V_71 -> V_72 == NULL ) {
F_16 ( V_5 -> V_71 ) ;
V_5 -> V_71 = NULL ;
F_129 ( & V_5 -> V_188 ) ;
return - V_38 ;
}
V_5 -> V_71 -> V_72 -> V_88 = V_88 ;
V_5 -> V_71 -> V_114 = V_114 ;
V_5 -> V_181 = 1 ;
F_129 ( & V_5 -> V_188 ) ;
return 0 ;
}
void F_147 ( struct V_4 * V_5 )
{
F_146 ( & V_5 -> V_188 ) ;
#ifdef F_127
F_109 ( V_5 ) ;
#endif
F_16 ( V_5 -> V_71 -> V_72 ) ;
F_16 ( V_5 -> V_71 ) ;
V_5 -> V_71 = NULL ;
V_5 -> V_181 = 0 ;
F_129 ( & V_5 -> V_188 ) ;
}
unsigned int F_4 ( struct V_4 * V_5 , unsigned int V_6 )
{
unsigned int V_14 ;
V_14 = V_5 -> V_215 ( V_5 , V_6 ) ;
F_42 ( V_5 -> V_27 , L_62 , V_6 , V_14 ) ;
F_148 ( V_5 , V_6 , V_14 ) ;
return V_14 ;
}
unsigned int F_22 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned int V_1 )
{
F_42 ( V_5 -> V_27 , L_64 , V_6 , V_1 ) ;
F_149 ( V_5 , V_6 , V_1 ) ;
return V_5 -> V_147 ( V_5 , V_6 , V_1 ) ;
}
unsigned int F_150 ( struct V_4 * V_5 ,
unsigned int V_6 , const void * V_219 , T_1 V_8 )
{
return V_5 -> V_220 ( V_5 , V_6 , V_219 , V_8 ) ;
}
int F_151 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_221 , unsigned int V_42 )
{
bool V_222 ;
unsigned int V_223 , V_224 ;
int V_14 ;
if ( V_5 -> V_225 ) {
V_14 = F_152 ( V_5 -> V_226 , V_6 ,
V_221 , V_42 , & V_222 ) ;
} else {
V_14 = F_4 ( V_5 , V_6 ) ;
if ( V_14 < 0 )
return V_14 ;
V_223 = V_14 ;
V_224 = ( V_223 & ~ V_221 ) | ( V_42 & V_221 ) ;
V_222 = V_223 != V_224 ;
if ( V_222 )
V_14 = F_22 ( V_5 , V_6 , V_224 ) ;
}
if ( V_14 < 0 )
return V_14 ;
return V_222 ;
}
int F_153 ( struct V_4 * V_5 ,
unsigned short V_6 , unsigned int V_221 ,
unsigned int V_42 )
{
int V_222 ;
F_146 ( & V_5 -> V_188 ) ;
V_222 = F_151 ( V_5 , V_6 , V_221 , V_42 ) ;
F_129 ( & V_5 -> V_188 ) ;
return V_222 ;
}
int F_154 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_221 , unsigned int V_42 )
{
int V_222 ;
unsigned int V_223 , V_224 ;
V_223 = F_4 ( V_5 , V_6 ) ;
V_224 = ( V_223 & ~ V_221 ) | V_42 ;
V_222 = V_223 != V_224 ;
return V_222 ;
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
void * V_219 , const char * V_205 ,
const char * V_242 )
{
struct V_240 V_243 ;
struct V_239 * V_244 ;
char * V_48 = NULL ;
int V_245 ;
memcpy ( & V_243 , V_241 , sizeof( V_243 ) ) ;
V_243 . V_246 = 0 ;
if ( ! V_205 )
V_205 = V_243 . V_48 ;
if ( V_242 ) {
V_245 = strlen ( V_205 ) + strlen ( V_242 ) + 2 ;
V_48 = F_14 ( V_245 , V_37 ) ;
if ( ! V_48 )
return NULL ;
snprintf ( V_48 , V_245 , L_65 , V_242 , V_205 ) ;
V_243 . V_48 = V_48 ;
} else {
V_243 . V_48 = V_205 ;
}
V_244 = F_157 ( & V_243 , V_219 ) ;
F_16 ( V_48 ) ;
return V_244 ;
}
static int F_158 ( struct V_77 * V_46 , struct V_26 * V_27 ,
const struct V_240 * V_149 , int V_150 ,
const char * V_242 , void * V_219 )
{
int V_73 , V_3 ;
for ( V_3 = 0 ; V_3 < V_150 ; V_3 ++ ) {
const struct V_240 * V_247 = & V_149 [ V_3 ] ;
V_73 = F_159 ( V_46 , F_156 ( V_247 , V_219 ,
V_247 -> V_48 , V_242 ) ) ;
if ( V_73 < 0 ) {
F_64 ( V_27 , L_66 , V_247 -> V_48 , V_73 ) ;
return V_73 ;
}
}
return 0 ;
}
int F_84 ( struct V_4 * V_5 ,
const struct V_240 * V_149 , int V_150 )
{
struct V_77 * V_46 = V_5 -> V_46 -> V_77 ;
return F_158 ( V_46 , V_5 -> V_27 , V_149 , V_150 ,
V_5 -> V_140 , V_5 ) ;
}
int F_88 ( struct V_54 * V_55 ,
const struct V_240 * V_149 , int V_150 )
{
struct V_77 * V_46 = V_55 -> V_46 -> V_77 ;
return F_158 ( V_46 , V_55 -> V_27 , V_149 , V_150 ,
NULL , V_55 ) ;
}
int F_122 ( struct V_59 * V_248 ,
const struct V_240 * V_149 , int V_150 )
{
struct V_77 * V_46 = V_248 -> V_77 ;
return F_158 ( V_46 , V_248 -> V_27 , V_149 , V_150 ,
NULL , V_248 ) ;
}
int F_160 ( struct V_57 * V_58 ,
const struct V_240 * V_149 , int V_150 )
{
struct V_77 * V_46 = V_58 -> V_46 -> V_77 ;
return F_158 ( V_46 , V_58 -> V_27 , V_149 , V_150 ,
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
unsigned int V_1 , V_264 ;
for ( V_264 = 1 ; V_264 < V_252 -> V_259 ; V_264 <<= 1 )
;
V_1 = F_4 ( V_5 , V_252 -> V_6 ) ;
V_263 -> V_42 . V_257 . V_260 [ 0 ]
= ( V_1 >> V_252 -> V_255 ) & ( V_264 - 1 ) ;
if ( V_252 -> V_255 != V_252 -> V_256 )
V_263 -> V_42 . V_257 . V_260 [ 1 ] =
( V_1 >> V_252 -> V_256 ) & ( V_264 - 1 ) ;
return 0 ;
}
int F_164 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_4 * V_5 = F_163 ( V_244 ) ;
struct V_251 * V_252 = (struct V_251 * ) V_244 -> V_253 ;
unsigned int V_1 ;
unsigned int V_221 , V_264 ;
for ( V_264 = 1 ; V_264 < V_252 -> V_259 ; V_264 <<= 1 )
;
if ( V_263 -> V_42 . V_257 . V_260 [ 0 ] > V_252 -> V_259 - 1 )
return - V_17 ;
V_1 = V_263 -> V_42 . V_257 . V_260 [ 0 ] << V_252 -> V_255 ;
V_221 = ( V_264 - 1 ) << V_252 -> V_255 ;
if ( V_252 -> V_255 != V_252 -> V_256 ) {
if ( V_263 -> V_42 . V_257 . V_260 [ 1 ] > V_252 -> V_259 - 1 )
return - V_17 ;
V_1 |= V_263 -> V_42 . V_257 . V_260 [ 1 ] << V_252 -> V_256 ;
V_221 |= ( V_264 - 1 ) << V_252 -> V_256 ;
}
return F_153 ( V_5 , V_252 -> V_6 , V_221 , V_1 ) ;
}
int F_165 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_4 * V_5 = F_163 ( V_244 ) ;
struct V_251 * V_252 = (struct V_251 * ) V_244 -> V_253 ;
unsigned int V_265 , V_1 , V_266 ;
V_265 = F_4 ( V_5 , V_252 -> V_6 ) ;
V_1 = ( V_265 >> V_252 -> V_255 ) & V_252 -> V_221 ;
for ( V_266 = 0 ; V_266 < V_252 -> V_259 ; V_266 ++ ) {
if ( V_1 == V_252 -> V_267 [ V_266 ] )
break;
}
V_263 -> V_42 . V_257 . V_260 [ 0 ] = V_266 ;
if ( V_252 -> V_255 != V_252 -> V_256 ) {
V_1 = ( V_265 >> V_252 -> V_256 ) & V_252 -> V_221 ;
for ( V_266 = 0 ; V_266 < V_252 -> V_259 ; V_266 ++ ) {
if ( V_1 == V_252 -> V_267 [ V_266 ] )
break;
}
V_263 -> V_42 . V_257 . V_260 [ 1 ] = V_266 ;
}
return 0 ;
}
int F_166 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_4 * V_5 = F_163 ( V_244 ) ;
struct V_251 * V_252 = (struct V_251 * ) V_244 -> V_253 ;
unsigned int V_1 ;
unsigned int V_221 ;
if ( V_263 -> V_42 . V_257 . V_260 [ 0 ] > V_252 -> V_259 - 1 )
return - V_17 ;
V_1 = V_252 -> V_267 [ V_263 -> V_42 . V_257 . V_260 [ 0 ] ] << V_252 -> V_255 ;
V_221 = V_252 -> V_221 << V_252 -> V_255 ;
if ( V_252 -> V_255 != V_252 -> V_256 ) {
if ( V_263 -> V_42 . V_257 . V_260 [ 1 ] > V_252 -> V_259 - 1 )
return - V_17 ;
V_1 |= V_252 -> V_267 [ V_263 -> V_42 . V_257 . V_260 [ 1 ] ] << V_252 -> V_256 ;
V_221 |= V_252 -> V_221 << V_252 -> V_256 ;
}
return F_153 ( V_5 , V_252 -> V_6 , V_221 , V_1 ) ;
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
if ( V_259 == 1 && ! strstr ( V_244 -> V_268 . V_48 , L_67 ) )
V_250 -> type = V_269 ;
else
V_250 -> type = V_270 ;
V_250 -> V_18 = 1 ;
V_250 -> V_42 . integer . F_7 = 0 ;
V_250 -> V_42 . integer . V_259 = V_259 ;
return 0 ;
}
int F_169 ( struct V_239 * V_244 ,
struct V_249 * V_250 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_244 -> V_253 ;
int V_273 ;
if ( ! V_272 -> V_273 )
V_272 -> V_273 = V_272 -> V_259 ;
V_273 = V_272 -> V_273 ;
if ( V_273 == 1 && ! strstr ( V_244 -> V_268 . V_48 , L_67 ) )
V_250 -> type = V_269 ;
else
V_250 -> type = V_270 ;
V_250 -> V_18 = F_170 ( V_272 ) ? 2 : 1 ;
V_250 -> V_42 . integer . F_7 = 0 ;
V_250 -> V_42 . integer . V_259 = V_273 ;
return 0 ;
}
int F_171 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_244 -> V_253 ;
struct V_4 * V_5 = F_163 ( V_244 ) ;
unsigned int V_6 = V_272 -> V_6 ;
unsigned int V_274 = V_272 -> V_275 ;
unsigned int V_276 = V_272 -> V_276 ;
unsigned int V_277 = V_272 -> V_277 ;
int V_259 = V_272 -> V_259 ;
unsigned int V_221 = ( 1 << F_172 ( V_259 ) ) - 1 ;
unsigned int V_278 = V_272 -> V_278 ;
V_263 -> V_42 . integer . V_42 [ 0 ] =
( F_4 ( V_5 , V_6 ) >> V_276 ) & V_221 ;
if ( V_278 )
V_263 -> V_42 . integer . V_42 [ 0 ] =
V_259 - V_263 -> V_42 . integer . V_42 [ 0 ] ;
if ( F_170 ( V_272 ) ) {
if ( V_6 == V_274 )
V_263 -> V_42 . integer . V_42 [ 1 ] =
( F_4 ( V_5 , V_6 ) >> V_277 ) & V_221 ;
else
V_263 -> V_42 . integer . V_42 [ 1 ] =
( F_4 ( V_5 , V_274 ) >> V_276 ) & V_221 ;
if ( V_278 )
V_263 -> V_42 . integer . V_42 [ 1 ] =
V_259 - V_263 -> V_42 . integer . V_42 [ 1 ] ;
}
return 0 ;
}
int F_173 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_244 -> V_253 ;
struct V_4 * V_5 = F_163 ( V_244 ) ;
unsigned int V_6 = V_272 -> V_6 ;
unsigned int V_274 = V_272 -> V_275 ;
unsigned int V_276 = V_272 -> V_276 ;
unsigned int V_277 = V_272 -> V_277 ;
int V_259 = V_272 -> V_259 ;
unsigned int V_221 = ( 1 << F_172 ( V_259 ) ) - 1 ;
unsigned int V_278 = V_272 -> V_278 ;
int V_73 ;
bool V_279 = 0 ;
unsigned int V_280 = 0 ;
unsigned int V_1 , V_281 ;
V_1 = ( V_263 -> V_42 . integer . V_42 [ 0 ] & V_221 ) ;
if ( V_278 )
V_1 = V_259 - V_1 ;
V_281 = V_221 << V_276 ;
V_1 = V_1 << V_276 ;
if ( F_170 ( V_272 ) ) {
V_280 = ( V_263 -> V_42 . integer . V_42 [ 1 ] & V_221 ) ;
if ( V_278 )
V_280 = V_259 - V_280 ;
if ( V_6 == V_274 ) {
V_281 |= V_221 << V_277 ;
V_1 |= V_280 << V_277 ;
} else {
V_280 = V_280 << V_276 ;
V_279 = 1 ;
}
}
V_73 = F_153 ( V_5 , V_6 , V_281 , V_1 ) ;
if ( V_73 < 0 )
return V_73 ;
if ( V_279 )
V_73 = F_153 ( V_5 , V_274 , V_281 , V_280 ) ;
return V_73 ;
}
int F_174 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_4 * V_5 = F_163 ( V_244 ) ;
struct V_271 * V_272 =
(struct V_271 * ) V_244 -> V_253 ;
unsigned int V_6 = V_272 -> V_6 ;
unsigned int V_274 = V_272 -> V_275 ;
unsigned int V_276 = V_272 -> V_276 ;
unsigned int V_277 = V_272 -> V_277 ;
int V_259 = V_272 -> V_259 ;
int F_7 = V_272 -> F_7 ;
int V_221 = ( 1 << ( F_172 ( F_7 + V_259 ) - 1 ) ) - 1 ;
V_263 -> V_42 . integer . V_42 [ 0 ] =
( ( F_4 ( V_5 , V_6 ) >> V_276 ) - F_7 ) & V_221 ;
if ( F_170 ( V_272 ) )
V_263 -> V_42 . integer . V_42 [ 1 ] =
( ( F_4 ( V_5 , V_274 ) >> V_277 ) - F_7 ) & V_221 ;
return 0 ;
}
int F_175 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_4 * V_5 = F_163 ( V_244 ) ;
struct V_271 * V_272 =
(struct V_271 * ) V_244 -> V_253 ;
unsigned int V_6 = V_272 -> V_6 ;
unsigned int V_274 = V_272 -> V_275 ;
unsigned int V_276 = V_272 -> V_276 ;
unsigned int V_277 = V_272 -> V_277 ;
int V_259 = V_272 -> V_259 ;
int F_7 = V_272 -> F_7 ;
int V_221 = ( 1 << ( F_172 ( F_7 + V_259 ) - 1 ) ) - 1 ;
int V_73 = 0 ;
unsigned short V_1 , V_281 , V_280 = 0 ;
V_281 = V_221 << V_276 ;
V_1 = ( V_263 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & V_221 ;
V_1 = V_1 << V_276 ;
if ( F_153 ( V_5 , V_6 , V_281 , V_1 ) )
return V_73 ;
if ( F_170 ( V_272 ) ) {
V_281 = V_221 << V_277 ;
V_280 = ( V_263 -> V_42 . integer . V_42 [ 1 ] + F_7 ) & V_221 ;
V_280 = V_280 << V_277 ;
if ( F_153 ( V_5 , V_274 , V_281 , V_280 ) )
return V_73 ;
}
return 0 ;
}
int F_176 ( struct V_239 * V_244 ,
struct V_249 * V_250 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_244 -> V_253 ;
int V_273 ;
int F_7 = V_272 -> F_7 ;
if ( ! V_272 -> V_273 )
V_272 -> V_273 = V_272 -> V_259 ;
V_273 = V_272 -> V_273 ;
V_250 -> type = V_270 ;
V_250 -> V_18 = 2 ;
V_250 -> V_42 . integer . F_7 = 0 ;
V_250 -> V_42 . integer . V_259 = V_273 - F_7 ;
return 0 ;
}
int F_177 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_244 -> V_253 ;
struct V_4 * V_5 = F_163 ( V_244 ) ;
unsigned int V_6 = V_272 -> V_6 ;
int F_7 = V_272 -> F_7 ;
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
struct V_271 * V_272 =
(struct V_271 * ) V_244 -> V_253 ;
struct V_4 * V_5 = F_163 ( V_244 ) ;
unsigned int V_6 = V_272 -> V_6 ;
int F_7 = V_272 -> F_7 ;
unsigned int V_1 ;
V_1 = ( V_263 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & 0xff ;
V_1 |= ( ( V_263 -> V_42 . integer . V_42 [ 1 ] + F_7 ) & 0xff ) << 8 ;
return F_153 ( V_5 , V_6 , 0xffff , V_1 ) ;
}
int F_179 ( struct V_239 * V_244 ,
struct V_249 * V_250 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_244 -> V_253 ;
int V_273 ;
int F_7 = V_272 -> F_7 ;
if ( ! V_272 -> V_273 )
V_272 -> V_273 = V_272 -> V_259 ;
V_273 = V_272 -> V_273 ;
V_250 -> type = V_270 ;
V_250 -> V_18 = 1 ;
V_250 -> V_42 . integer . F_7 = 0 ;
V_250 -> V_42 . integer . V_259 = V_273 - F_7 ;
return 0 ;
}
int F_180 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_244 -> V_253 ;
struct V_4 * V_5 = F_163 ( V_244 ) ;
unsigned int V_6 = V_272 -> V_6 ;
unsigned int V_276 = V_272 -> V_276 ;
int F_7 = V_272 -> F_7 ;
int V_259 = V_272 -> V_259 ;
unsigned int V_221 = ( 1 << F_172 ( V_259 ) ) - 1 ;
unsigned int V_278 = V_272 -> V_278 ;
unsigned int V_1 , V_281 ;
V_1 = ( ( V_263 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & V_221 ) ;
if ( V_278 )
V_1 = V_259 - V_1 ;
V_281 = V_221 << V_276 ;
V_1 = V_1 << V_276 ;
return F_153 ( V_5 , V_6 , V_281 , V_1 ) ;
}
int F_181 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_244 -> V_253 ;
struct V_4 * V_5 = F_163 ( V_244 ) ;
unsigned int V_6 = V_272 -> V_6 ;
unsigned int V_276 = V_272 -> V_276 ;
int F_7 = V_272 -> F_7 ;
int V_259 = V_272 -> V_259 ;
unsigned int V_221 = ( 1 << F_172 ( V_259 ) ) - 1 ;
unsigned int V_278 = V_272 -> V_278 ;
V_263 -> V_42 . integer . V_42 [ 0 ] =
( F_4 ( V_5 , V_6 ) >> V_276 ) & V_221 ;
if ( V_278 )
V_263 -> V_42 . integer . V_42 [ 0 ] =
V_259 - V_263 -> V_42 . integer . V_42 [ 0 ] ;
V_263 -> V_42 . integer . V_42 [ 0 ] =
V_263 -> V_42 . integer . V_42 [ 0 ] - F_7 ;
return 0 ;
}
int F_182 ( struct V_4 * V_5 ,
const char * V_48 , int V_259 )
{
struct V_77 * V_46 = V_5 -> V_46 -> V_77 ;
struct V_239 * V_282 ;
struct V_271 * V_272 ;
int V_183 = 0 ;
int V_14 = - V_17 ;
if ( F_183 ( ! V_48 || V_259 <= 0 ) )
return - V_17 ;
F_34 (kctl, &card->controls, list) {
if ( ! strncmp ( V_282 -> V_268 . V_48 , V_48 , sizeof( V_282 -> V_268 . V_48 ) ) ) {
V_183 = 1 ;
break;
}
}
if ( V_183 ) {
V_272 = (struct V_271 * ) V_282 -> V_253 ;
if ( V_259 <= V_272 -> V_259 ) {
V_272 -> V_273 = V_259 ;
V_14 = 0 ;
}
}
return V_14 ;
}
int F_184 ( struct V_239 * V_244 ,
struct V_249 * V_250 )
{
struct V_4 * V_5 = F_163 ( V_244 ) ;
struct V_283 * V_175 = ( void * ) V_244 -> V_253 ;
V_250 -> type = V_284 ;
V_250 -> V_18 = V_175 -> V_285 * V_5 -> V_286 ;
return 0 ;
}
int F_185 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_283 * V_175 = ( void * ) V_244 -> V_253 ;
struct V_4 * V_5 = F_163 ( V_244 ) ;
int V_14 ;
if ( V_5 -> V_225 )
V_14 = F_186 ( V_5 -> V_226 , V_175 -> V_287 ,
V_263 -> V_42 . V_288 . V_219 ,
V_175 -> V_285 * V_5 -> V_286 ) ;
else
V_14 = - V_17 ;
if ( V_14 == 0 && V_175 -> V_221 ) {
switch ( V_5 -> V_286 ) {
case 1 :
V_263 -> V_42 . V_288 . V_219 [ 0 ] &= ~ V_175 -> V_221 ;
break;
case 2 :
( ( V_289 * ) ( & V_263 -> V_42 . V_288 . V_219 ) ) [ 0 ]
&= ~ V_175 -> V_221 ;
break;
case 4 :
( ( V_290 * ) ( & V_263 -> V_42 . V_288 . V_219 ) ) [ 0 ]
&= ~ V_175 -> V_221 ;
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
struct V_283 * V_175 = ( void * ) V_244 -> V_253 ;
struct V_4 * V_5 = F_163 ( V_244 ) ;
int V_14 , V_8 ;
unsigned int V_1 ;
void * V_219 ;
if ( ! V_5 -> V_225 )
return - V_17 ;
V_219 = V_263 -> V_42 . V_288 . V_219 ;
V_8 = V_175 -> V_285 * V_5 -> V_286 ;
if ( V_175 -> V_221 ) {
V_14 = F_188 ( V_5 -> V_226 , V_175 -> V_287 , & V_1 ) ;
if ( V_14 != 0 )
return V_14 ;
V_1 &= V_175 -> V_221 ;
V_219 = F_189 ( V_219 , V_8 , V_37 ) ;
if ( ! V_219 )
return - V_38 ;
switch ( V_5 -> V_286 ) {
case 1 :
( ( V_291 * ) V_219 ) [ 0 ] &= ~ V_175 -> V_221 ;
( ( V_291 * ) V_219 ) [ 0 ] |= V_1 ;
break;
case 2 :
( ( V_289 * ) V_219 ) [ 0 ] &= F_190 ( ~ V_175 -> V_221 ) ;
( ( V_289 * ) V_219 ) [ 0 ] |= F_190 ( V_1 ) ;
break;
case 4 :
( ( V_290 * ) V_219 ) [ 0 ] &= F_191 ( ~ V_175 -> V_221 ) ;
( ( V_290 * ) V_219 ) [ 0 ] |= F_191 ( V_1 ) ;
break;
default:
return - V_17 ;
}
}
V_14 = F_192 ( V_5 -> V_226 , V_175 -> V_287 ,
V_219 , V_8 ) ;
if ( V_175 -> V_221 )
F_16 ( V_219 ) ;
return V_14 ;
}
int F_193 ( struct V_239 * V_244 ,
struct V_249 * V_250 )
{
struct V_292 * V_272 =
(struct V_292 * ) V_244 -> V_253 ;
V_250 -> type = V_270 ;
V_250 -> V_18 = 1 ;
V_250 -> V_42 . integer . F_7 = V_272 -> F_7 ;
V_250 -> V_42 . integer . V_259 = V_272 -> V_259 ;
return 0 ;
}
int F_194 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_292 * V_272 =
(struct V_292 * ) V_244 -> V_253 ;
struct V_4 * V_5 = F_163 ( V_244 ) ;
unsigned int V_293 = V_272 -> V_293 ;
unsigned int V_294 = V_272 -> V_294 ;
unsigned int V_295 = V_5 -> V_10 -> V_13 * V_296 ;
unsigned int V_297 = ( 1 << V_295 ) - 1 ;
unsigned int V_278 = V_272 -> V_278 ;
unsigned long V_221 = ( 1UL << V_272 -> V_298 ) - 1 ;
long F_7 = V_272 -> F_7 ;
long V_259 = V_272 -> V_259 ;
long V_1 = 0 ;
unsigned long V_299 ;
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_294 ; V_3 ++ ) {
V_299 = F_4 ( V_5 , V_293 + V_3 ) & V_297 ;
V_1 |= V_299 << ( V_295 * ( V_294 - V_3 - 1 ) ) ;
}
V_1 &= V_221 ;
if ( F_7 < 0 && V_1 > V_259 )
V_1 |= ~ V_221 ;
if ( V_278 )
V_1 = V_259 - V_1 ;
V_263 -> V_42 . integer . V_42 [ 0 ] = V_1 ;
return 0 ;
}
int F_195 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_292 * V_272 =
(struct V_292 * ) V_244 -> V_253 ;
struct V_4 * V_5 = F_163 ( V_244 ) ;
unsigned int V_293 = V_272 -> V_293 ;
unsigned int V_294 = V_272 -> V_294 ;
unsigned int V_295 = V_5 -> V_10 -> V_13 * V_296 ;
unsigned int V_297 = ( 1 << V_295 ) - 1 ;
unsigned int V_278 = V_272 -> V_278 ;
unsigned long V_221 = ( 1UL << V_272 -> V_298 ) - 1 ;
long V_259 = V_272 -> V_259 ;
long V_1 = V_263 -> V_42 . integer . V_42 [ 0 ] ;
unsigned int V_3 , V_299 , V_300 ;
int V_73 ;
if ( V_278 )
V_1 = V_259 - V_1 ;
V_1 &= V_221 ;
for ( V_3 = 0 ; V_3 < V_294 ; V_3 ++ ) {
V_299 = ( V_1 >> ( V_295 * ( V_294 - V_3 - 1 ) ) ) & V_297 ;
V_300 = ( V_221 >> ( V_295 * ( V_294 - V_3 - 1 ) ) ) & V_297 ;
V_73 = F_153 ( V_5 , V_293 + V_3 ,
V_300 , V_299 ) ;
if ( V_73 < 0 )
return V_73 ;
}
return 0 ;
}
int F_196 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_244 -> V_253 ;
struct V_4 * V_5 = F_163 ( V_244 ) ;
unsigned int V_6 = V_272 -> V_6 ;
unsigned int V_276 = V_272 -> V_276 ;
unsigned int V_221 = 1 << V_276 ;
unsigned int V_278 = V_272 -> V_278 != 0 ;
unsigned int V_1 = F_4 ( V_5 , V_6 ) & V_221 ;
if ( V_276 != 0 && V_1 != 0 )
V_1 = V_1 >> V_276 ;
V_263 -> V_42 . V_257 . V_260 [ 0 ] = V_1 ^ V_278 ;
return 0 ;
}
int F_197 ( struct V_239 * V_244 ,
struct V_262 * V_263 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_244 -> V_253 ;
struct V_4 * V_5 = F_163 ( V_244 ) ;
unsigned int V_6 = V_272 -> V_6 ;
unsigned int V_276 = V_272 -> V_276 ;
unsigned int V_221 = 1 << V_276 ;
unsigned int V_278 = V_272 -> V_278 != 0 ;
unsigned int V_301 = V_263 -> V_42 . V_257 . V_260 [ 0 ] != 0 ;
unsigned int V_302 = ( V_301 ^ V_278 ) ? V_221 : 0 ;
unsigned int V_280 = ( V_301 ^ V_278 ) ? 0 : V_221 ;
int V_73 ;
V_73 = F_153 ( V_5 , V_6 , V_221 , V_302 ) ;
if ( V_73 < 0 )
return V_73 ;
V_73 = F_153 ( V_5 , V_6 , V_221 , V_280 ) ;
return V_73 ;
}
int F_198 ( struct V_57 * V_58 , int V_303 ,
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
int F_199 ( struct V_4 * V_5 , int V_303 ,
int V_307 , unsigned int V_304 , int V_305 )
{
if ( V_5 -> V_10 -> V_306 )
return V_5 -> V_10 -> V_306 ( V_5 , V_303 , V_307 ,
V_304 , V_305 ) ;
else
return - V_17 ;
}
int F_200 ( struct V_57 * V_58 ,
int V_308 , int div )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_88 -> V_309 )
return V_58 -> V_10 -> V_88 -> V_309 ( V_58 , V_308 , div ) ;
else
return - V_17 ;
}
int F_201 ( struct V_57 * V_58 , int V_310 , int V_307 ,
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
int F_202 ( struct V_4 * V_5 , int V_310 , int V_307 ,
unsigned int V_311 , unsigned int V_312 )
{
if ( V_5 -> V_10 -> V_313 )
return V_5 -> V_10 -> V_313 ( V_5 , V_310 , V_307 ,
V_311 , V_312 ) ;
else
return - V_17 ;
}
int F_123 ( struct V_57 * V_58 , unsigned int V_314 )
{
if ( V_58 -> V_10 == NULL )
return - V_17 ;
if ( V_58 -> V_10 -> V_88 -> V_315 == NULL )
return - V_197 ;
return V_58 -> V_10 -> V_88 -> V_315 ( V_58 , V_314 ) ;
}
int F_203 ( struct V_57 * V_58 ,
unsigned int V_316 , unsigned int V_317 , int V_318 , int V_319 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_88 -> V_320 )
return V_58 -> V_10 -> V_88 -> V_320 ( V_58 , V_316 , V_317 ,
V_318 , V_319 ) ;
else
return - V_17 ;
}
int F_204 ( struct V_57 * V_58 ,
unsigned int V_321 , unsigned int * V_322 ,
unsigned int V_323 , unsigned int * V_324 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_88 -> V_325 )
return V_58 -> V_10 -> V_88 -> V_325 ( V_58 , V_321 , V_322 ,
V_323 , V_324 ) ;
else
return - V_17 ;
}
int F_205 ( struct V_57 * V_58 , int V_326 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_88 -> V_327 )
return V_58 -> V_10 -> V_88 -> V_327 ( V_58 , V_326 ) ;
else
return - V_17 ;
}
int F_206 ( struct V_57 * V_58 , int V_328 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_88 -> V_89 )
return V_58 -> V_10 -> V_88 -> V_89 ( V_58 , V_328 ) ;
else
return - V_197 ;
}
int F_133 ( struct V_59 * V_46 )
{
int V_3 , V_14 ;
if ( ! V_46 -> V_48 || ! V_46 -> V_27 )
return - V_17 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ ) {
struct V_115 * V_329 = & V_46 -> V_64 [ V_3 ] ;
if ( ! ! V_329 -> V_123 == ! ! V_329 -> V_122 ) {
F_64 ( V_46 -> V_27 ,
L_68 ,
V_329 -> V_48 ) ;
return - V_17 ;
}
if ( ! V_329 -> V_124 ) {
F_64 ( V_46 -> V_27 , L_69 ,
V_329 -> V_48 ) ;
return - V_17 ;
}
if ( V_329 -> V_116 && V_329 -> V_125 ) {
F_64 ( V_46 -> V_27 ,
L_70 , V_329 -> V_48 ) ;
return - V_17 ;
}
if ( V_329 -> V_119 && V_329 -> V_117 ) {
F_64 ( V_46 -> V_27 ,
L_71 ,
V_329 -> V_48 ) ;
return - V_17 ;
}
if ( ! V_329 -> V_120 &&
! ( V_329 -> V_119 || V_329 -> V_117 ) ) {
F_64 ( V_46 -> V_27 ,
L_72 ,
V_329 -> V_48 ) ;
return - V_17 ;
}
}
F_94 ( V_46 -> V_27 , V_46 ) ;
F_207 ( V_46 ) ;
F_38 ( V_46 ) ;
V_46 -> V_31 = F_208 ( V_46 -> V_27 ,
sizeof( struct V_30 ) *
( V_46 -> V_66 + V_46 -> V_191 ) ,
V_37 ) ;
if ( V_46 -> V_31 == NULL )
return - V_38 ;
V_46 -> V_83 = 0 ;
V_46 -> V_161 = & V_46 -> V_31 [ V_46 -> V_66 ] ;
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ )
V_46 -> V_31 [ V_3 ] . V_64 = & V_46 -> V_64 [ V_3 ] ;
F_96 ( & V_46 -> V_153 ) ;
F_96 ( & V_46 -> V_330 ) ;
V_46 -> V_209 = 0 ;
F_95 ( & V_46 -> V_188 ) ;
F_95 ( & V_46 -> V_331 ) ;
V_14 = F_116 ( V_46 ) ;
if ( V_14 != 0 )
F_40 ( V_46 ) ;
return V_14 ;
}
int F_136 ( struct V_59 * V_46 )
{
if ( V_46 -> V_209 )
F_134 ( V_46 ) ;
F_42 ( V_46 -> V_27 , L_73 , V_46 -> V_48 ) ;
return 0 ;
}
static char * F_209 ( struct V_26 * V_27 , int * V_268 )
{
char * V_183 , V_48 [ V_332 ] ;
int V_333 , V_334 ;
if ( F_66 ( V_27 ) == NULL )
return NULL ;
F_210 ( V_48 , F_66 ( V_27 ) , V_332 ) ;
V_183 = strstr ( V_48 , V_27 -> V_10 -> V_48 ) ;
if ( V_183 ) {
if ( sscanf ( & V_183 [ strlen ( V_27 -> V_10 -> V_48 ) ] , L_74 , V_268 ) == 1 ) {
if ( * V_268 == - 1 )
V_183 [ strlen ( V_27 -> V_10 -> V_48 ) ] = '\0' ;
}
} else {
if ( sscanf ( V_48 , L_75 , & V_333 , & V_334 ) == 2 ) {
char V_335 [ V_332 ] ;
* V_268 = ( ( V_333 & 0xffff ) << 16 ) + V_334 ;
snprintf ( V_335 , V_332 , L_76 , V_27 -> V_10 -> V_48 , V_48 ) ;
F_210 ( V_48 , V_335 , V_332 ) ;
} else
* V_268 = 0 ;
}
return F_211 ( V_48 , V_37 ) ;
}
static inline char * F_212 ( struct V_26 * V_27 ,
struct V_85 * V_336 )
{
if ( V_336 -> V_48 == NULL ) {
F_68 ( L_77 ,
F_66 ( V_27 ) ) ;
return NULL ;
}
return F_211 ( V_336 -> V_48 , V_37 ) ;
}
int F_213 ( struct V_26 * V_27 ,
struct V_85 * V_336 )
{
struct V_4 * V_5 ;
struct V_57 * V_58 ;
F_42 ( V_27 , L_78 , F_66 ( V_27 ) ) ;
V_58 = F_92 ( sizeof( struct V_57 ) , V_37 ) ;
if ( V_58 == NULL )
return - V_38 ;
V_58 -> V_48 = F_209 ( V_27 , & V_58 -> V_268 ) ;
if ( V_58 -> V_48 == NULL ) {
F_16 ( V_58 ) ;
return - V_38 ;
}
V_58 -> V_27 = V_27 ;
V_58 -> V_10 = V_336 ;
V_58 -> V_53 . V_27 = V_27 ;
if ( ! V_58 -> V_10 -> V_88 )
V_58 -> V_10 -> V_88 = & V_337 ;
F_146 ( & V_338 ) ;
F_34 (codec, &codec_list, list) {
if ( V_5 -> V_27 == V_27 ) {
F_42 ( V_27 , L_79 ,
V_58 -> V_48 , V_5 -> V_48 ) ;
V_58 -> V_5 = V_5 ;
break;
}
}
F_86 ( & V_58 -> V_153 , & V_339 ) ;
F_129 ( & V_338 ) ;
F_214 ( L_80 , V_58 -> V_48 ) ;
return 0 ;
}
void F_215 ( struct V_26 * V_27 )
{
struct V_57 * V_58 ;
F_34 (dai, &dai_list, list) {
if ( V_27 == V_58 -> V_27 )
goto V_183;
}
return;
V_183:
F_146 ( & V_338 ) ;
F_70 ( & V_58 -> V_153 ) ;
F_129 ( & V_338 ) ;
F_214 ( L_81 , V_58 -> V_48 ) ;
F_16 ( V_58 -> V_48 ) ;
F_16 ( V_58 ) ;
}
int F_216 ( struct V_26 * V_27 ,
struct V_85 * V_336 , T_1 V_18 )
{
struct V_4 * V_5 ;
struct V_57 * V_58 ;
int V_3 , V_14 = 0 ;
F_42 ( V_27 , L_82 , F_66 ( V_27 ) , V_18 ) ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ ) {
V_58 = F_92 ( sizeof( struct V_57 ) , V_37 ) ;
if ( V_58 == NULL ) {
V_14 = - V_38 ;
goto V_73;
}
V_58 -> V_48 = F_212 ( V_27 , & V_336 [ V_3 ] ) ;
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
F_146 ( & V_338 ) ;
F_34 (codec, &codec_list, list) {
if ( V_5 -> V_27 == V_27 ) {
F_42 ( V_27 , L_79 ,
V_58 -> V_48 , V_5 -> V_48 ) ;
V_58 -> V_5 = V_5 ;
break;
}
}
F_86 ( & V_58 -> V_153 , & V_339 ) ;
F_129 ( & V_338 ) ;
F_214 ( L_80 , V_58 -> V_48 ) ;
}
return 0 ;
V_73:
for ( V_3 -- ; V_3 >= 0 ; V_3 -- )
F_215 ( V_27 ) ;
return V_14 ;
}
void F_217 ( struct V_26 * V_27 , T_1 V_18 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ )
F_215 ( V_27 ) ;
}
int F_218 ( struct V_26 * V_27 ,
struct V_155 * V_340 )
{
struct V_54 * V_55 ;
F_42 ( V_27 , L_83 , F_66 ( V_27 ) ) ;
V_55 = F_92 ( sizeof( struct V_54 ) , V_37 ) ;
if ( V_55 == NULL )
return - V_38 ;
V_55 -> V_48 = F_209 ( V_27 , & V_55 -> V_268 ) ;
if ( V_55 -> V_48 == NULL ) {
F_16 ( V_55 ) ;
return - V_38 ;
}
V_55 -> V_27 = V_27 ;
V_55 -> V_10 = V_340 ;
V_55 -> V_53 . V_27 = V_27 ;
V_55 -> V_53 . V_55 = V_55 ;
V_55 -> V_53 . V_341 = V_340 -> V_341 ;
F_95 ( & V_55 -> V_188 ) ;
F_146 ( & V_338 ) ;
F_86 ( & V_55 -> V_153 , & V_342 ) ;
F_129 ( & V_338 ) ;
F_214 ( L_84 , V_55 -> V_48 ) ;
return 0 ;
}
void F_219 ( struct V_26 * V_27 )
{
struct V_54 * V_55 ;
F_34 (platform, &platform_list, list) {
if ( V_27 == V_55 -> V_27 )
goto V_183;
}
return;
V_183:
F_146 ( & V_338 ) ;
F_70 ( & V_55 -> V_153 ) ;
F_129 ( & V_338 ) ;
F_214 ( L_85 , V_55 -> V_48 ) ;
F_16 ( V_55 -> V_48 ) ;
F_16 ( V_55 ) ;
}
static void F_220 ( struct V_343 * V_65 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_124 ( V_344 ) ; V_3 ++ )
if ( V_65 -> V_232 & V_344 [ V_3 ] )
V_65 -> V_232 |= V_344 [ V_3 ] ;
}
int F_221 ( struct V_26 * V_27 ,
const struct V_141 * V_345 ,
struct V_85 * V_336 ,
int V_346 )
{
T_1 V_347 ;
struct V_4 * V_5 ;
int V_14 , V_3 ;
F_42 ( V_27 , L_86 , F_66 ( V_27 ) ) ;
V_5 = F_92 ( sizeof( struct V_4 ) , V_37 ) ;
if ( V_5 == NULL )
return - V_38 ;
V_5 -> V_48 = F_209 ( V_27 , & V_5 -> V_268 ) ;
if ( V_5 -> V_48 == NULL ) {
F_16 ( V_5 ) ;
return - V_38 ;
}
if ( V_345 -> V_185 )
V_5 -> V_185 = V_345 -> V_185 ;
else
V_5 -> V_185 = V_348 ;
V_5 -> V_147 = V_345 -> V_147 ;
V_5 -> V_215 = V_345 -> V_215 ;
V_5 -> V_212 = V_345 -> V_212 ;
V_5 -> V_213 = V_345 -> V_213 ;
V_5 -> V_214 = V_345 -> V_214 ;
V_5 -> V_349 = V_345 -> V_349 ;
V_5 -> V_53 . V_98 = V_104 ;
V_5 -> V_53 . V_27 = V_27 ;
V_5 -> V_53 . V_5 = V_5 ;
V_5 -> V_53 . V_350 = V_345 -> V_350 ;
V_5 -> V_53 . V_341 = V_345 -> V_341 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_10 = V_345 ;
V_5 -> V_346 = V_346 ;
F_95 ( & V_5 -> V_188 ) ;
if ( V_345 -> V_11 && V_345 -> V_13 ) {
V_347 = V_345 -> V_11 * V_345 -> V_13 ;
V_5 -> V_347 = V_347 ;
if ( V_345 -> V_351 ) {
V_5 -> V_352 = F_189 ( V_345 -> V_351 ,
V_347 , V_37 ) ;
if ( ! V_5 -> V_352 ) {
V_14 = - V_38 ;
goto V_353;
}
}
}
if ( V_345 -> V_354 && V_345 -> V_355 ) {
if ( ! V_5 -> V_212 )
V_5 -> V_212 = V_356 ;
if ( ! V_5 -> V_213 )
V_5 -> V_213 = V_357 ;
if ( ! V_5 -> V_214 )
V_5 -> V_214 = V_358 ;
}
for ( V_3 = 0 ; V_3 < V_346 ; V_3 ++ ) {
F_220 ( & V_336 [ V_3 ] . V_359 ) ;
F_220 ( & V_336 [ V_3 ] . V_360 ) ;
}
F_146 ( & V_338 ) ;
F_86 ( & V_5 -> V_153 , & V_361 ) ;
F_129 ( & V_338 ) ;
if ( V_346 ) {
V_14 = F_216 ( V_27 , V_336 , V_346 ) ;
if ( V_14 < 0 )
F_64 ( V_5 -> V_27 , L_87 ,
V_14 ) ;
}
F_214 ( L_88 , V_5 -> V_48 ) ;
return 0 ;
V_353:
F_16 ( V_5 -> V_352 ) ;
V_5 -> V_352 = NULL ;
F_16 ( V_5 -> V_48 ) ;
F_16 ( V_5 ) ;
return V_14 ;
}
void F_222 ( struct V_26 * V_27 )
{
struct V_4 * V_5 ;
int V_3 ;
F_34 (codec, &codec_list, list) {
if ( V_27 == V_5 -> V_27 )
goto V_183;
}
return;
V_183:
if ( V_5 -> V_346 )
for ( V_3 = 0 ; V_3 < V_5 -> V_346 ; V_3 ++ )
F_215 ( V_27 ) ;
F_146 ( & V_338 ) ;
F_70 ( & V_5 -> V_153 ) ;
F_129 ( & V_338 ) ;
F_214 ( L_89 , V_5 -> V_48 ) ;
F_223 ( V_5 ) ;
F_16 ( V_5 -> V_352 ) ;
F_16 ( V_5 -> V_48 ) ;
F_16 ( V_5 ) ;
}
int F_224 ( struct V_59 * V_46 ,
const char * V_362 )
{
struct V_363 * V_364 = V_46 -> V_27 -> V_118 ;
int V_14 ;
V_14 = F_225 ( V_364 , V_362 , 0 , & V_46 -> V_48 ) ;
if ( V_14 < 0 && V_14 != - V_17 ) {
F_64 ( V_46 -> V_27 ,
L_90 ,
V_362 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
int F_226 ( struct V_59 * V_46 ,
const char * V_362 )
{
struct V_363 * V_364 = V_46 -> V_27 -> V_118 ;
int V_365 ;
struct V_366 * V_367 ;
int V_3 , V_14 ;
V_365 = F_227 ( V_364 , V_362 ) ;
if ( V_365 < 0 || V_365 & 1 ) {
F_64 ( V_46 -> V_27 ,
L_91 ,
V_362 ) ;
return - V_17 ;
}
V_365 /= 2 ;
if ( ! V_365 ) {
F_64 ( V_46 -> V_27 ,
L_92 ,
V_362 ) ;
return - V_17 ;
}
V_367 = F_208 ( V_46 -> V_27 , V_365 * sizeof( * V_367 ) ,
V_37 ) ;
if ( ! V_367 ) {
F_64 ( V_46 -> V_27 ,
L_93 ) ;
return - V_17 ;
}
for ( V_3 = 0 ; V_3 < V_365 ; V_3 ++ ) {
V_14 = F_225 ( V_364 , V_362 ,
2 * V_3 , & V_367 [ V_3 ] . V_368 ) ;
if ( V_14 ) {
F_64 ( V_46 -> V_27 ,
L_94 ,
V_362 , 2 * V_3 , V_14 ) ;
F_16 ( V_367 ) ;
return - V_17 ;
}
V_14 = F_225 ( V_364 , V_362 ,
( 2 * V_3 ) + 1 , & V_367 [ V_3 ] . V_307 ) ;
if ( V_14 ) {
F_64 ( V_46 -> V_27 ,
L_94 ,
V_362 , ( 2 * V_3 ) + 1 , V_14 ) ;
F_16 ( V_367 ) ;
return - V_17 ;
}
}
V_46 -> V_152 = V_365 ;
V_46 -> V_151 = V_367 ;
return 0 ;
}
static int T_5 F_228 ( void )
{
#ifdef F_100
V_60 = F_24 ( L_95 , NULL ) ;
if ( F_229 ( V_60 ) || ! V_60 ) {
F_104 ( L_96 ) ;
V_60 = NULL ;
}
if ( ! F_27 ( L_97 , 0444 , V_60 , NULL ,
& V_369 ) )
F_104 ( L_98 ) ;
if ( ! F_27 ( L_99 , 0444 , V_60 , NULL ,
& V_370 ) )
F_104 ( L_100 ) ;
if ( ! F_27 ( L_101 , 0444 , V_60 , NULL ,
& V_371 ) )
F_104 ( L_102 ) ;
#endif
F_230 () ;
return F_231 ( & V_372 ) ;
}
static void T_6 F_232 ( void )
{
F_233 () ;
#ifdef F_100
F_30 ( V_60 ) ;
#endif
F_234 ( & V_372 ) ;
}
