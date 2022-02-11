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
if ( V_64 -> V_117 ) {
if ( V_92 -> V_27 -> V_118 != V_64 -> V_117 )
continue;
} else {
if ( strcmp ( V_92 -> V_48 , V_64 -> V_119 ) )
continue;
}
V_31 -> V_92 = V_92 ;
}
if ( ! V_31 -> V_92 ) {
F_42 ( V_46 -> V_27 , L_27 ,
V_64 -> V_119 ) ;
return - V_120 ;
}
F_34 (codec, &codec_list, list) {
if ( V_64 -> V_121 ) {
if ( V_5 -> V_27 -> V_118 != V_64 -> V_121 )
continue;
} else {
if ( strcmp ( V_5 -> V_48 , V_64 -> V_122 ) )
continue;
}
V_31 -> V_5 = V_5 ;
F_34 (codec_dai, &dai_list, list) {
if ( V_5 -> V_27 == V_84 -> V_27 &&
! strcmp ( V_84 -> V_48 ,
V_64 -> V_123 ) ) {
V_31 -> V_84 = V_84 ;
}
}
if ( ! V_31 -> V_84 ) {
F_42 ( V_46 -> V_27 , L_28 ,
V_64 -> V_123 ) ;
return - V_120 ;
}
}
if ( ! V_31 -> V_5 ) {
F_42 ( V_46 -> V_27 , L_29 ,
V_64 -> V_122 ) ;
return - V_120 ;
}
V_116 = V_64 -> V_116 ;
if ( ! V_116 && ! V_64 -> V_124 )
V_116 = L_30 ;
F_34 (platform, &platform_list, list) {
if ( V_64 -> V_124 ) {
if ( V_55 -> V_27 -> V_118 !=
V_64 -> V_124 )
continue;
} else {
if ( strcmp ( V_55 -> V_48 , V_116 ) )
continue;
}
V_31 -> V_55 = V_55 ;
}
if ( ! V_31 -> V_55 ) {
F_42 ( V_46 -> V_27 , L_31 ,
V_64 -> V_116 ) ;
return - V_120 ;
}
V_46 -> V_83 ++ ;
return 0 ;
}
static void F_66 ( struct V_4 * V_5 )
{
int V_73 ;
if ( V_5 -> V_10 -> remove ) {
V_73 = V_5 -> V_10 -> remove ( V_5 ) ;
if ( V_73 < 0 )
F_64 ( V_5 -> V_27 ,
L_32 ,
V_5 -> V_48 , V_73 ) ;
}
F_67 ( & V_5 -> V_53 ) ;
F_29 ( V_5 ) ;
V_5 -> V_125 = 0 ;
F_68 ( & V_5 -> V_126 ) ;
F_69 ( V_5 -> V_27 -> V_10 -> V_127 ) ;
}
static void F_70 ( struct V_59 * V_46 , int V_114 , int V_128 )
{
struct V_30 * V_31 = & V_46 -> V_31 [ V_114 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
struct V_54 * V_55 = V_31 -> V_55 ;
struct V_57 * V_84 = V_31 -> V_84 , * V_92 = V_31 -> V_92 ;
int V_73 ;
if ( V_31 -> V_129 ) {
F_71 ( V_31 -> V_27 , & V_130 ) ;
F_71 ( V_31 -> V_27 , & V_131 ) ;
F_45 ( V_31 -> V_27 ) ;
V_31 -> V_129 = 0 ;
}
if ( V_84 && V_84 -> V_125 &&
V_84 -> V_10 -> V_132 == V_128 ) {
if ( V_84 -> V_10 -> remove ) {
V_73 = V_84 -> V_10 -> remove ( V_84 ) ;
if ( V_73 < 0 )
F_72 ( L_32 ,
V_84 -> V_48 , V_73 ) ;
}
V_84 -> V_125 = 0 ;
F_68 ( & V_84 -> V_126 ) ;
}
if ( V_55 && V_55 -> V_125 &&
V_55 -> V_10 -> V_132 == V_128 ) {
if ( V_55 -> V_10 -> remove ) {
V_73 = V_55 -> V_10 -> remove ( V_55 ) ;
if ( V_73 < 0 )
F_72 ( L_32 ,
V_55 -> V_48 , V_73 ) ;
}
F_67 ( & V_55 -> V_53 ) ;
F_32 ( V_55 ) ;
V_55 -> V_125 = 0 ;
F_68 ( & V_55 -> V_126 ) ;
F_69 ( V_55 -> V_27 -> V_10 -> V_127 ) ;
}
if ( V_5 && V_5 -> V_125 &&
V_5 -> V_10 -> V_132 == V_128 )
F_66 ( V_5 ) ;
if ( V_92 && V_92 -> V_125 &&
V_92 -> V_10 -> V_132 == V_128 ) {
if ( V_92 -> V_10 -> remove ) {
V_73 = V_92 -> V_10 -> remove ( V_92 ) ;
if ( V_73 < 0 )
F_72 ( L_32 ,
V_92 -> V_48 , V_73 ) ;
}
V_92 -> V_125 = 0 ;
F_68 ( & V_92 -> V_126 ) ;
F_69 ( V_92 -> V_27 -> V_10 -> V_127 ) ;
}
}
static void F_73 ( struct V_59 * V_46 )
{
int V_58 , V_128 ;
for ( V_128 = V_133 ; V_128 <= V_134 ;
V_128 ++ ) {
for ( V_58 = 0 ; V_58 < V_46 -> V_83 ; V_58 ++ )
F_70 ( V_46 , V_58 , V_128 ) ;
}
V_46 -> V_83 = 0 ;
}
static void F_74 ( struct V_59 * V_46 ,
struct V_4 * V_5 )
{
int V_3 ;
if ( V_46 -> V_135 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_46 -> V_136 ; V_3 ++ ) {
struct V_137 * V_138 = & V_46 -> V_135 [ V_3 ] ;
if ( V_138 -> V_139 && ! strcmp ( V_5 -> V_48 , V_138 -> V_139 ) ) {
V_5 -> V_140 = V_138 -> V_140 ;
break;
}
}
}
static int F_75 ( struct V_59 * V_46 ,
struct V_4 * V_5 )
{
int V_14 = 0 ;
const struct V_141 * V_10 = V_5 -> V_10 ;
struct V_57 * V_58 ;
V_5 -> V_46 = V_46 ;
V_5 -> V_53 . V_46 = V_46 ;
F_74 ( V_46 , V_5 ) ;
if ( ! F_76 ( V_5 -> V_27 -> V_10 -> V_127 ) )
return - V_142 ;
F_23 ( V_5 ) ;
if ( V_10 -> V_143 )
F_77 ( & V_5 -> V_53 , V_10 -> V_143 ,
V_10 -> V_144 ) ;
F_34 (dai, &dai_list, list) {
if ( V_58 -> V_27 != V_5 -> V_27 )
continue;
F_78 ( & V_5 -> V_53 , V_58 ) ;
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
if ( V_10 -> V_147 )
F_79 ( V_5 , V_10 -> V_147 ,
V_10 -> V_148 ) ;
if ( V_10 -> V_149 )
F_80 ( & V_5 -> V_53 , V_10 -> V_149 ,
V_10 -> V_150 ) ;
V_5 -> V_125 = 1 ;
F_81 ( & V_5 -> V_126 , & V_46 -> V_80 ) ;
F_81 ( & V_5 -> V_53 . V_151 , & V_46 -> V_152 ) ;
return 0 ;
V_146:
F_29 ( V_5 ) ;
F_69 ( V_5 -> V_27 -> V_10 -> V_127 ) ;
return V_14 ;
}
static int F_82 ( struct V_59 * V_46 ,
struct V_54 * V_55 )
{
int V_14 = 0 ;
const struct V_153 * V_10 = V_55 -> V_10 ;
struct V_57 * V_58 ;
V_55 -> V_46 = V_46 ;
V_55 -> V_53 . V_46 = V_46 ;
if ( ! F_76 ( V_55 -> V_27 -> V_10 -> V_127 ) )
return - V_142 ;
F_31 ( V_55 ) ;
if ( V_10 -> V_143 )
F_77 ( & V_55 -> V_53 ,
V_10 -> V_143 , V_10 -> V_144 ) ;
F_34 (dai, &dai_list, list) {
if ( V_58 -> V_27 != V_55 -> V_27 )
continue;
F_78 ( & V_55 -> V_53 , V_58 ) ;
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
if ( V_10 -> V_147 )
F_83 ( V_55 , V_10 -> V_147 ,
V_10 -> V_148 ) ;
if ( V_10 -> V_149 )
F_80 ( & V_55 -> V_53 , V_10 -> V_149 ,
V_10 -> V_150 ) ;
V_55 -> V_125 = 1 ;
F_81 ( & V_55 -> V_126 , & V_46 -> V_154 ) ;
F_81 ( & V_55 -> V_53 . V_151 , & V_46 -> V_152 ) ;
return 0 ;
V_146:
F_32 ( V_55 ) ;
F_69 ( V_55 -> V_27 -> V_10 -> V_127 ) ;
return V_14 ;
}
static void F_84 ( struct V_26 * V_27 )
{
F_16 ( V_27 ) ;
}
static int F_85 ( struct V_59 * V_46 ,
struct V_4 * V_5 ,
int V_114 , int V_155 )
{
struct V_115 * V_64 = NULL ;
struct V_156 * V_157 = NULL ;
struct V_30 * V_31 ;
const char * V_158 , * V_48 ;
int V_14 = 0 ;
if ( ! V_155 ) {
V_64 = & V_46 -> V_64 [ V_114 ] ;
V_31 = & V_46 -> V_31 [ V_114 ] ;
V_48 = V_64 -> V_48 ;
} else {
V_157 = & V_46 -> V_157 [ V_114 ] ;
V_31 = & V_46 -> V_159 [ V_114 ] ;
V_48 = V_157 -> V_48 ;
}
V_31 -> V_46 = V_46 ;
F_86 ( & V_5 -> V_53 ) ;
V_158 = V_5 -> V_140 ;
V_5 -> V_140 = NULL ;
if ( ! V_155 && V_64 -> V_160 )
V_14 = V_64 -> V_160 ( V_31 ) ;
else if ( V_155 && V_157 -> V_160 )
V_14 = V_157 -> V_160 ( & V_5 -> V_53 ) ;
if ( V_14 < 0 ) {
F_64 ( V_46 -> V_27 , L_35 , V_48 , V_14 ) ;
return V_14 ;
}
V_5 -> V_140 = V_158 ;
V_31 -> V_5 = V_5 ;
V_31 -> V_27 = F_87 ( sizeof( struct V_26 ) , V_37 ) ;
if ( ! V_31 -> V_27 )
return - V_38 ;
F_88 ( V_31 -> V_27 ) ;
V_31 -> V_27 -> V_75 = V_46 -> V_27 ;
V_31 -> V_27 -> V_76 = F_84 ;
V_31 -> V_27 -> V_161 = V_48 ;
F_89 ( V_31 -> V_27 , V_31 ) ;
F_90 ( & V_31 -> V_162 ) ;
F_91 ( & V_31 -> V_163 [ V_99 ] . V_164 ) ;
F_91 ( & V_31 -> V_163 [ V_101 ] . V_164 ) ;
F_91 ( & V_31 -> V_163 [ V_99 ] . V_165 ) ;
F_91 ( & V_31 -> V_163 [ V_101 ] . V_165 ) ;
V_14 = F_92 ( V_31 -> V_27 ) ;
if ( V_14 < 0 ) {
F_64 ( V_46 -> V_27 ,
L_36 , V_14 ) ;
return V_14 ;
}
V_31 -> V_129 = 1 ;
V_14 = F_93 ( V_31 -> V_27 ) ;
if ( V_14 < 0 )
F_64 ( V_5 -> V_27 ,
L_37 ,
V_14 ) ;
V_14 = F_94 ( V_31 -> V_27 , & V_131 ) ;
if ( V_14 < 0 )
F_64 ( V_5 -> V_27 ,
L_38 , V_14 ) ;
#ifdef F_95
if ( ! V_155 && ! V_64 -> V_166 )
goto V_167;
V_14 = F_96 ( V_31 ) ;
if ( V_14 < 0 )
F_64 ( V_31 -> V_27 , L_39 , V_14 ) ;
V_167:
#endif
return 0 ;
}
static int F_97 ( struct V_59 * V_46 , int V_114 , int V_128 )
{
struct V_115 * V_64 = & V_46 -> V_64 [ V_114 ] ;
struct V_30 * V_31 = & V_46 -> V_31 [ V_114 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
struct V_54 * V_55 = V_31 -> V_55 ;
struct V_57 * V_84 = V_31 -> V_84 ;
struct V_57 * V_92 = V_31 -> V_92 ;
struct V_168 * V_169 , * V_170 ;
int V_14 ;
F_42 ( V_46 -> V_27 , L_40 ,
V_46 -> V_48 , V_114 , V_128 ) ;
V_92 -> V_55 = V_55 ;
V_84 -> V_46 = V_46 ;
V_92 -> V_46 = V_46 ;
V_31 -> V_32 = V_32 ;
if ( ! V_92 -> V_125 &&
V_92 -> V_10 -> V_171 == V_128 ) {
V_92 -> V_53 . V_46 = V_46 ;
if ( ! F_76 ( V_92 -> V_27 -> V_10 -> V_127 ) )
return - V_142 ;
F_78 ( & V_92 -> V_53 , V_92 ) ;
if ( V_92 -> V_10 -> V_145 ) {
V_14 = V_92 -> V_10 -> V_145 ( V_92 ) ;
if ( V_14 < 0 ) {
F_72 ( L_41 ,
V_92 -> V_48 , V_14 ) ;
F_69 ( V_92 -> V_27 -> V_10 -> V_127 ) ;
return V_14 ;
}
}
V_92 -> V_125 = 1 ;
F_81 ( & V_92 -> V_126 , & V_46 -> V_172 ) ;
}
if ( ! V_5 -> V_125 &&
V_5 -> V_10 -> V_171 == V_128 ) {
V_14 = F_75 ( V_46 , V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_55 -> V_125 &&
V_55 -> V_10 -> V_171 == V_128 ) {
V_14 = F_82 ( V_46 , V_55 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_84 -> V_125 && V_84 -> V_10 -> V_171 == V_128 ) {
if ( V_84 -> V_10 -> V_145 ) {
V_14 = V_84 -> V_10 -> V_145 ( V_84 ) ;
if ( V_14 < 0 ) {
F_72 ( L_42 ,
V_84 -> V_48 , V_14 ) ;
return V_14 ;
}
}
V_84 -> V_125 = 1 ;
F_81 ( & V_84 -> V_126 , & V_46 -> V_172 ) ;
}
if ( V_128 != V_134 )
return 0 ;
V_14 = F_85 ( V_46 , V_5 , V_114 , 0 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_94 ( V_31 -> V_27 , & V_130 ) ;
if ( V_14 < 0 )
F_98 ( L_43 , V_14 ) ;
if ( ! V_64 -> V_173 ) {
V_14 = F_99 ( V_31 , V_114 ) ;
if ( V_14 < 0 ) {
F_72 ( L_44 ,
V_64 -> V_174 , V_14 ) ;
return V_14 ;
}
} else {
V_169 = V_84 -> V_175 ;
V_170 = V_92 -> V_176 ;
if ( V_169 && V_170 ) {
V_14 = F_100 ( V_46 , V_64 -> V_173 ,
V_170 , V_169 ) ;
if ( V_14 != 0 ) {
F_64 ( V_46 -> V_27 , L_45 ,
V_169 -> V_48 , V_170 -> V_48 , V_14 ) ;
return V_14 ;
}
}
V_169 = V_92 -> V_175 ;
V_170 = V_84 -> V_176 ;
if ( V_169 && V_170 ) {
V_14 = F_100 ( V_46 , V_64 -> V_173 ,
V_170 , V_169 ) ;
if ( V_14 != 0 ) {
F_64 ( V_46 -> V_27 , L_45 ,
V_169 -> V_48 , V_170 -> V_48 , V_14 ) ;
return V_14 ;
}
}
}
if ( V_31 -> V_84 -> V_10 -> V_94 )
F_101 ( V_5 -> V_71 , V_31 -> V_92 -> V_177 ) ;
return 0 ;
}
static int F_102 ( struct V_30 * V_31 )
{
int V_14 ;
if ( V_31 -> V_84 -> V_10 -> V_94 && ! V_31 -> V_5 -> V_178 ) {
if ( ! V_31 -> V_5 -> V_179 )
return 0 ;
V_14 = F_47 ( V_31 -> V_5 ) ;
if ( V_14 < 0 ) {
F_72 ( L_46 , V_14 ) ;
return V_14 ;
}
V_31 -> V_5 -> V_178 = 1 ;
}
return 0 ;
}
static void F_103 ( struct V_4 * V_5 )
{
if ( V_5 -> V_178 ) {
F_44 ( V_5 ) ;
V_5 -> V_178 = 0 ;
}
}
static int F_104 ( struct V_59 * V_46 , int V_114 )
{
struct V_156 * V_157 = & V_46 -> V_157 [ V_114 ] ;
struct V_4 * V_5 ;
F_34 (codec, &codec_list, list) {
if ( ! strcmp ( V_5 -> V_48 , V_157 -> V_122 ) )
return 0 ;
}
return - V_120 ;
}
static int F_105 ( struct V_59 * V_46 , int V_114 )
{
struct V_156 * V_157 = & V_46 -> V_157 [ V_114 ] ;
struct V_4 * V_5 ;
int V_14 = - V_142 ;
F_34 (codec, &codec_list, list) {
if ( ! strcmp ( V_5 -> V_48 , V_157 -> V_122 ) ) {
if ( V_5 -> V_125 ) {
F_64 ( V_5 -> V_27 ,
L_47 ) ;
V_14 = - V_180 ;
goto V_167;
}
goto V_181;
}
}
F_64 ( V_46 -> V_27 , L_48 , V_157 -> V_122 ) ;
return - V_120 ;
V_181:
V_14 = F_75 ( V_46 , V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_85 ( V_46 , V_5 , V_114 , 1 ) ;
V_167:
return V_14 ;
}
static void F_106 ( struct V_59 * V_46 , int V_114 )
{
struct V_30 * V_31 = & V_46 -> V_159 [ V_114 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
if ( V_31 -> V_129 ) {
F_71 ( V_31 -> V_27 , & V_131 ) ;
F_107 ( V_31 -> V_27 ) ;
V_31 -> V_129 = 0 ;
}
if ( V_5 && V_5 -> V_125 )
F_66 ( V_5 ) ;
}
static int F_108 ( struct V_4 * V_5 ,
enum V_182 V_183 )
{
int V_14 ;
if ( V_5 -> V_184 )
return 0 ;
if ( V_183 && V_5 -> V_183 != V_183 )
V_5 -> V_183 = V_183 ;
V_14 = F_109 ( V_5 ) ;
if ( V_14 < 0 ) {
F_64 ( V_5 -> V_27 , L_49 ,
V_14 ) ;
return V_14 ;
}
V_5 -> V_184 = 1 ;
return 0 ;
}
static int F_110 ( struct V_59 * V_46 )
{
struct V_4 * V_5 ;
struct V_137 * V_135 ;
enum V_182 V_183 ;
struct V_115 * V_64 ;
int V_14 , V_3 , V_128 , V_185 ;
F_111 ( & V_46 -> V_186 , V_187 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ ) {
V_14 = F_65 ( V_46 , V_3 ) ;
if ( V_14 != 0 )
goto V_188;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_189 ; V_3 ++ ) {
V_14 = F_104 ( V_46 , V_3 ) ;
if ( V_14 != 0 )
goto V_188;
}
F_34 (codec, &codec_list, list) {
if ( V_5 -> V_184 )
continue;
V_183 = 0 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_136 ; ++ V_3 ) {
V_135 = & V_46 -> V_135 [ V_3 ] ;
if ( ! strcmp ( V_5 -> V_48 , V_135 -> V_139 ) ) {
V_183 = V_135 -> V_183 ;
if ( V_183 && V_183
!= V_5 -> V_183 )
break;
}
}
V_14 = F_108 ( V_5 , V_183 ) ;
if ( V_14 < 0 )
goto V_188;
}
V_14 = F_112 ( V_190 , V_191 ,
V_46 -> V_127 , 0 , & V_46 -> V_77 ) ;
if ( V_14 < 0 ) {
F_72 ( L_50 ,
V_46 -> V_48 , V_14 ) ;
goto V_188;
}
V_46 -> V_77 -> V_27 = V_46 -> V_27 ;
V_46 -> V_53 . V_98 = V_104 ;
V_46 -> V_53 . V_27 = V_46 -> V_27 ;
V_46 -> V_53 . V_46 = V_46 ;
F_81 ( & V_46 -> V_53 . V_151 , & V_46 -> V_152 ) ;
#ifdef F_95
F_28 ( & V_46 -> V_53 , V_46 -> V_45 ) ;
#endif
#ifdef F_113
F_114 ( & V_46 -> V_108 , F_60 ) ;
#endif
if ( V_46 -> V_143 )
F_77 ( & V_46 -> V_53 , V_46 -> V_143 ,
V_46 -> V_144 ) ;
if ( V_46 -> V_145 ) {
V_14 = V_46 -> V_145 ( V_46 ) ;
if ( V_14 < 0 )
goto V_192;
}
for ( V_128 = V_133 ; V_128 <= V_134 ;
V_128 ++ ) {
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ ) {
V_14 = F_97 ( V_46 , V_3 , V_128 ) ;
if ( V_14 < 0 ) {
F_72 ( L_51 ,
V_46 -> V_48 , V_14 ) ;
goto V_193;
}
}
}
for ( V_3 = 0 ; V_3 < V_46 -> V_189 ; V_3 ++ ) {
V_14 = F_105 ( V_46 , V_3 ) ;
if ( V_14 < 0 ) {
F_72 ( L_52 ,
V_46 -> V_48 , V_14 ) ;
goto V_194;
}
}
F_115 ( V_46 ) ;
if ( V_46 -> V_147 )
F_116 ( V_46 , V_46 -> V_147 , V_46 -> V_148 ) ;
if ( V_46 -> V_149 )
F_80 ( & V_46 -> V_53 , V_46 -> V_149 ,
V_46 -> V_150 ) ;
F_86 ( & V_46 -> V_53 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ ) {
V_64 = & V_46 -> V_64 [ V_3 ] ;
V_185 = V_64 -> V_185 ;
if ( V_185 ) {
V_14 = F_117 ( V_46 -> V_31 [ V_3 ] . V_84 ,
V_185 ) ;
if ( V_14 != 0 && V_14 != - V_195 )
F_25 ( V_46 -> V_31 [ V_3 ] . V_84 -> V_27 ,
L_53 ,
V_14 ) ;
}
if ( V_185 &&
( V_64 -> V_116 || V_64 -> V_124 ) ) {
V_14 = F_117 ( V_46 -> V_31 [ V_3 ] . V_92 ,
V_185 ) ;
if ( V_14 != 0 && V_14 != - V_195 )
F_25 ( V_46 -> V_31 [ V_3 ] . V_92 -> V_27 ,
L_53 ,
V_14 ) ;
} else if ( V_185 ) {
V_185 &= ~ V_196 ;
switch ( V_64 -> V_185 &
V_196 ) {
case V_197 :
V_185 |= V_198 ;
break;
case V_199 :
V_185 |= V_200 ;
break;
case V_200 :
V_185 |= V_199 ;
break;
case V_198 :
V_185 |= V_197 ;
break;
}
V_14 = F_117 ( V_46 -> V_31 [ V_3 ] . V_92 ,
V_185 ) ;
if ( V_14 != 0 && V_14 != - V_195 )
F_25 ( V_46 -> V_31 [ V_3 ] . V_92 -> V_27 ,
L_53 ,
V_14 ) ;
}
}
snprintf ( V_46 -> V_77 -> V_201 , sizeof( V_46 -> V_77 -> V_201 ) ,
L_54 , V_46 -> V_48 ) ;
snprintf ( V_46 -> V_77 -> V_202 , sizeof( V_46 -> V_77 -> V_202 ) ,
L_54 , V_46 -> V_203 ? V_46 -> V_203 : V_46 -> V_48 ) ;
snprintf ( V_46 -> V_77 -> V_10 , sizeof( V_46 -> V_77 -> V_10 ) ,
L_54 , V_46 -> V_204 ? V_46 -> V_204 : V_46 -> V_48 ) ;
for ( V_3 = 0 ; V_3 < F_118 ( V_46 -> V_77 -> V_10 ) ; V_3 ++ ) {
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
if ( V_46 -> V_205 ) {
V_14 = V_46 -> V_205 ( V_46 ) ;
if ( V_14 < 0 ) {
F_64 ( V_46 -> V_27 , L_55 ,
V_46 -> V_48 , V_14 ) ;
goto V_194;
}
}
F_86 ( & V_46 -> V_53 ) ;
if ( V_46 -> V_206 )
F_34 (codec, &card->codec_dev_list, card_list)
F_119 ( V_5 ) ;
V_14 = F_120 ( V_46 -> V_77 ) ;
if ( V_14 < 0 ) {
F_72 ( L_56 ,
V_46 -> V_48 , V_14 ) ;
goto V_194;
}
#ifdef F_121
for ( V_3 = 0 ; V_3 < V_46 -> V_83 ; V_3 ++ ) {
V_14 = F_102 ( & V_46 -> V_31 [ V_3 ] ) ;
if ( V_14 < 0 ) {
F_72 ( L_57 ,
V_46 -> V_48 , V_14 ) ;
while ( -- V_3 >= 0 )
F_103 ( V_46 -> V_31 [ V_3 ] . V_5 ) ;
goto V_194;
}
}
#endif
V_46 -> V_207 = 1 ;
F_122 ( & V_46 -> V_53 ) ;
F_123 ( & V_46 -> V_186 ) ;
return 0 ;
V_194:
for ( V_3 = 0 ; V_3 < V_46 -> V_189 ; V_3 ++ )
F_106 ( V_46 , V_3 ) ;
V_193:
F_73 ( V_46 ) ;
V_192:
if ( V_46 -> remove )
V_46 -> remove ( V_46 ) ;
F_124 ( V_46 -> V_77 ) ;
V_188:
F_123 ( & V_46 -> V_186 ) ;
return V_14 ;
}
static int F_125 ( struct V_208 * V_209 )
{
struct V_59 * V_46 = F_126 ( V_209 ) ;
int V_14 = 0 ;
if ( ! V_46 )
return - V_17 ;
F_25 ( & V_209 -> V_27 ,
L_58 ,
V_46 -> V_48 ) ;
V_46 -> V_27 = & V_209 -> V_27 ;
V_14 = F_127 ( V_46 ) ;
if ( V_14 != 0 ) {
F_64 ( & V_209 -> V_27 , L_59 ) ;
return V_14 ;
}
return 0 ;
}
static int F_128 ( struct V_59 * V_46 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_83 ; V_3 ++ ) {
struct V_30 * V_31 = & V_46 -> V_31 [ V_3 ] ;
F_58 ( & V_31 -> V_96 ) ;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_189 ; V_3 ++ )
F_106 ( V_46 , V_3 ) ;
F_73 ( V_46 ) ;
F_40 ( V_46 ) ;
if ( V_46 -> remove )
V_46 -> remove ( V_46 ) ;
F_67 ( & V_46 -> V_53 ) ;
F_124 ( V_46 -> V_77 ) ;
return 0 ;
}
static int F_129 ( struct V_208 * V_209 )
{
struct V_59 * V_46 = F_126 ( V_209 ) ;
F_130 ( V_46 ) ;
return 0 ;
}
int F_131 ( struct V_26 * V_27 )
{
struct V_59 * V_46 = F_9 ( V_27 ) ;
int V_3 ;
if ( ! V_46 -> V_207 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_83 ; V_3 ++ ) {
struct V_30 * V_31 = & V_46 -> V_31 [ V_3 ] ;
F_58 ( & V_31 -> V_96 ) ;
}
F_132 ( V_46 ) ;
return 0 ;
}
int F_133 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_210 )
return V_5 -> V_210 ( V_5 , V_6 ) ;
else
return 0 ;
}
int F_6 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_211 )
return V_5 -> V_211 ( V_5 , V_6 ) ;
else
return 1 ;
}
int F_134 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_212 )
return V_5 -> V_212 ( V_5 , V_6 ) ;
else
return 1 ;
}
int F_135 ( struct V_54 * V_55 ,
unsigned int V_6 )
{
unsigned int V_14 ;
if ( ! V_55 -> V_10 -> V_213 ) {
F_64 ( V_55 -> V_27 , L_60 ) ;
return - 1 ;
}
V_14 = V_55 -> V_10 -> V_213 ( V_55 , V_6 ) ;
F_42 ( V_55 -> V_27 , L_61 , V_6 , V_14 ) ;
F_136 ( V_55 , V_6 , V_14 ) ;
return V_14 ;
}
int F_137 ( struct V_54 * V_55 ,
unsigned int V_6 , unsigned int V_1 )
{
if ( ! V_55 -> V_10 -> V_214 ) {
F_64 ( V_55 -> V_27 , L_62 ) ;
return - 1 ;
}
F_42 ( V_55 -> V_27 , L_63 , V_6 , V_1 ) ;
F_138 ( V_55 , V_6 , V_1 ) ;
return V_55 -> V_10 -> V_214 ( V_55 , V_6 , V_1 ) ;
}
int F_139 ( struct V_4 * V_5 ,
struct V_215 * V_88 , int V_114 )
{
F_140 ( & V_5 -> V_186 ) ;
V_5 -> V_71 = F_87 ( sizeof( struct V_216 ) , V_37 ) ;
if ( V_5 -> V_71 == NULL ) {
F_123 ( & V_5 -> V_186 ) ;
return - V_38 ;
}
V_5 -> V_71 -> V_72 = F_87 ( sizeof( struct V_217 ) , V_37 ) ;
if ( V_5 -> V_71 -> V_72 == NULL ) {
F_16 ( V_5 -> V_71 ) ;
V_5 -> V_71 = NULL ;
F_123 ( & V_5 -> V_186 ) ;
return - V_38 ;
}
V_5 -> V_71 -> V_72 -> V_88 = V_88 ;
V_5 -> V_71 -> V_114 = V_114 ;
V_5 -> V_179 = 1 ;
F_123 ( & V_5 -> V_186 ) ;
return 0 ;
}
void F_141 ( struct V_4 * V_5 )
{
F_140 ( & V_5 -> V_186 ) ;
#ifdef F_121
F_103 ( V_5 ) ;
#endif
F_16 ( V_5 -> V_71 -> V_72 ) ;
F_16 ( V_5 -> V_71 ) ;
V_5 -> V_71 = NULL ;
V_5 -> V_179 = 0 ;
F_123 ( & V_5 -> V_186 ) ;
}
unsigned int F_4 ( struct V_4 * V_5 , unsigned int V_6 )
{
unsigned int V_14 ;
V_14 = V_5 -> V_213 ( V_5 , V_6 ) ;
F_42 ( V_5 -> V_27 , L_61 , V_6 , V_14 ) ;
F_142 ( V_5 , V_6 , V_14 ) ;
return V_14 ;
}
unsigned int F_22 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned int V_1 )
{
F_42 ( V_5 -> V_27 , L_63 , V_6 , V_1 ) ;
F_143 ( V_5 , V_6 , V_1 ) ;
return V_5 -> V_214 ( V_5 , V_6 , V_1 ) ;
}
unsigned int F_144 ( struct V_4 * V_5 ,
unsigned int V_6 , const void * V_218 , T_1 V_8 )
{
return V_5 -> V_219 ( V_5 , V_6 , V_218 , V_8 ) ;
}
int F_145 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_220 , unsigned int V_42 )
{
bool V_221 ;
unsigned int V_222 , V_223 ;
int V_14 ;
if ( V_5 -> V_224 ) {
V_14 = F_146 ( V_5 -> V_225 , V_6 ,
V_220 , V_42 , & V_221 ) ;
} else {
V_14 = F_4 ( V_5 , V_6 ) ;
if ( V_14 < 0 )
return V_14 ;
V_222 = V_14 ;
V_223 = ( V_222 & ~ V_220 ) | ( V_42 & V_220 ) ;
V_221 = V_222 != V_223 ;
if ( V_221 )
V_14 = F_22 ( V_5 , V_6 , V_223 ) ;
}
if ( V_14 < 0 )
return V_14 ;
return V_221 ;
}
int F_147 ( struct V_4 * V_5 ,
unsigned short V_6 , unsigned int V_220 ,
unsigned int V_42 )
{
int V_221 ;
F_140 ( & V_5 -> V_186 ) ;
V_221 = F_145 ( V_5 , V_6 , V_220 , V_42 ) ;
F_123 ( & V_5 -> V_186 ) ;
return V_221 ;
}
int F_148 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_220 , unsigned int V_42 )
{
int V_221 ;
unsigned int V_222 , V_223 ;
V_222 = F_4 ( V_5 , V_6 ) ;
V_223 = ( V_222 & ~ V_220 ) | V_42 ;
V_221 = V_222 != V_223 ;
return V_221 ;
}
int F_149 ( struct V_63 * V_70 ,
const struct V_226 * V_227 )
{
struct V_228 * V_229 = V_70 -> V_229 ;
V_229 -> V_227 . V_230 = V_227 -> V_230 ;
V_229 -> V_227 . V_231 = V_227 -> V_231 ;
V_229 -> V_227 . V_232 = V_227 -> V_232 ;
V_229 -> V_227 . V_233 = V_227 -> V_233 ;
V_229 -> V_227 . V_234 = V_227 -> V_234 ;
V_229 -> V_227 . V_235 = V_227 -> V_235 ;
V_229 -> V_227 . V_236 = V_227 -> V_236 ;
V_229 -> V_227 . V_237 = V_227 -> V_237 ;
return 0 ;
}
struct V_238 * F_150 ( const struct V_239 * V_240 ,
void * V_218 , const char * V_203 ,
const char * V_241 )
{
struct V_239 V_242 ;
struct V_238 * V_243 ;
char * V_48 = NULL ;
int V_244 ;
memcpy ( & V_242 , V_240 , sizeof( V_242 ) ) ;
V_242 . V_245 = 0 ;
if ( ! V_203 )
V_203 = V_242 . V_48 ;
if ( V_241 ) {
V_244 = strlen ( V_203 ) + strlen ( V_241 ) + 2 ;
V_48 = F_14 ( V_244 , V_37 ) ;
if ( ! V_48 )
return NULL ;
snprintf ( V_48 , V_244 , L_64 , V_241 , V_203 ) ;
V_242 . V_48 = V_48 ;
} else {
V_242 . V_48 = V_203 ;
}
V_243 = F_151 ( & V_242 , V_218 ) ;
F_16 ( V_48 ) ;
return V_243 ;
}
static int F_152 ( struct V_77 * V_46 , struct V_26 * V_27 ,
const struct V_239 * V_147 , int V_148 ,
const char * V_241 , void * V_218 )
{
int V_73 , V_3 ;
for ( V_3 = 0 ; V_3 < V_148 ; V_3 ++ ) {
const struct V_239 * V_246 = & V_147 [ V_3 ] ;
V_73 = F_153 ( V_46 , F_150 ( V_246 , V_218 ,
V_246 -> V_48 , V_241 ) ) ;
if ( V_73 < 0 ) {
F_64 ( V_27 , L_65 , V_246 -> V_48 , V_73 ) ;
return V_73 ;
}
}
return 0 ;
}
int F_79 ( struct V_4 * V_5 ,
const struct V_239 * V_147 , int V_148 )
{
struct V_77 * V_46 = V_5 -> V_46 -> V_77 ;
return F_152 ( V_46 , V_5 -> V_27 , V_147 , V_148 ,
V_5 -> V_140 , V_5 ) ;
}
int F_83 ( struct V_54 * V_55 ,
const struct V_239 * V_147 , int V_148 )
{
struct V_77 * V_46 = V_55 -> V_46 -> V_77 ;
return F_152 ( V_46 , V_55 -> V_27 , V_147 , V_148 ,
NULL , V_55 ) ;
}
int F_116 ( struct V_59 * V_247 ,
const struct V_239 * V_147 , int V_148 )
{
struct V_77 * V_46 = V_247 -> V_77 ;
return F_152 ( V_46 , V_247 -> V_27 , V_147 , V_148 ,
NULL , V_247 ) ;
}
int F_154 ( struct V_57 * V_58 ,
const struct V_239 * V_147 , int V_148 )
{
struct V_77 * V_46 = V_58 -> V_46 -> V_77 ;
return F_152 ( V_46 , V_58 -> V_27 , V_147 , V_148 ,
NULL , V_58 ) ;
}
int F_155 ( struct V_238 * V_243 ,
struct V_248 * V_249 )
{
struct V_250 * V_251 = (struct V_250 * ) V_243 -> V_252 ;
V_249 -> type = V_253 ;
V_249 -> V_18 = V_251 -> V_254 == V_251 -> V_255 ? 1 : 2 ;
V_249 -> V_42 . V_256 . V_257 = V_251 -> V_258 ;
if ( V_249 -> V_42 . V_256 . V_259 > V_251 -> V_258 - 1 )
V_249 -> V_42 . V_256 . V_259 = V_251 -> V_258 - 1 ;
strcpy ( V_249 -> V_42 . V_256 . V_48 ,
V_251 -> V_260 [ V_249 -> V_42 . V_256 . V_259 ] ) ;
return 0 ;
}
int F_156 ( struct V_238 * V_243 ,
struct V_261 * V_262 )
{
struct V_4 * V_5 = F_157 ( V_243 ) ;
struct V_250 * V_251 = (struct V_250 * ) V_243 -> V_252 ;
unsigned int V_1 , V_263 ;
for ( V_263 = 1 ; V_263 < V_251 -> V_258 ; V_263 <<= 1 )
;
V_1 = F_4 ( V_5 , V_251 -> V_6 ) ;
V_262 -> V_42 . V_256 . V_259 [ 0 ]
= ( V_1 >> V_251 -> V_254 ) & ( V_263 - 1 ) ;
if ( V_251 -> V_254 != V_251 -> V_255 )
V_262 -> V_42 . V_256 . V_259 [ 1 ] =
( V_1 >> V_251 -> V_255 ) & ( V_263 - 1 ) ;
return 0 ;
}
int F_158 ( struct V_238 * V_243 ,
struct V_261 * V_262 )
{
struct V_4 * V_5 = F_157 ( V_243 ) ;
struct V_250 * V_251 = (struct V_250 * ) V_243 -> V_252 ;
unsigned int V_1 ;
unsigned int V_220 , V_263 ;
for ( V_263 = 1 ; V_263 < V_251 -> V_258 ; V_263 <<= 1 )
;
if ( V_262 -> V_42 . V_256 . V_259 [ 0 ] > V_251 -> V_258 - 1 )
return - V_17 ;
V_1 = V_262 -> V_42 . V_256 . V_259 [ 0 ] << V_251 -> V_254 ;
V_220 = ( V_263 - 1 ) << V_251 -> V_254 ;
if ( V_251 -> V_254 != V_251 -> V_255 ) {
if ( V_262 -> V_42 . V_256 . V_259 [ 1 ] > V_251 -> V_258 - 1 )
return - V_17 ;
V_1 |= V_262 -> V_42 . V_256 . V_259 [ 1 ] << V_251 -> V_255 ;
V_220 |= ( V_263 - 1 ) << V_251 -> V_255 ;
}
return F_147 ( V_5 , V_251 -> V_6 , V_220 , V_1 ) ;
}
int F_159 ( struct V_238 * V_243 ,
struct V_261 * V_262 )
{
struct V_4 * V_5 = F_157 ( V_243 ) ;
struct V_250 * V_251 = (struct V_250 * ) V_243 -> V_252 ;
unsigned int V_264 , V_1 , V_265 ;
V_264 = F_4 ( V_5 , V_251 -> V_6 ) ;
V_1 = ( V_264 >> V_251 -> V_254 ) & V_251 -> V_220 ;
for ( V_265 = 0 ; V_265 < V_251 -> V_258 ; V_265 ++ ) {
if ( V_1 == V_251 -> V_266 [ V_265 ] )
break;
}
V_262 -> V_42 . V_256 . V_259 [ 0 ] = V_265 ;
if ( V_251 -> V_254 != V_251 -> V_255 ) {
V_1 = ( V_264 >> V_251 -> V_255 ) & V_251 -> V_220 ;
for ( V_265 = 0 ; V_265 < V_251 -> V_258 ; V_265 ++ ) {
if ( V_1 == V_251 -> V_266 [ V_265 ] )
break;
}
V_262 -> V_42 . V_256 . V_259 [ 1 ] = V_265 ;
}
return 0 ;
}
int F_160 ( struct V_238 * V_243 ,
struct V_261 * V_262 )
{
struct V_4 * V_5 = F_157 ( V_243 ) ;
struct V_250 * V_251 = (struct V_250 * ) V_243 -> V_252 ;
unsigned int V_1 ;
unsigned int V_220 ;
if ( V_262 -> V_42 . V_256 . V_259 [ 0 ] > V_251 -> V_258 - 1 )
return - V_17 ;
V_1 = V_251 -> V_266 [ V_262 -> V_42 . V_256 . V_259 [ 0 ] ] << V_251 -> V_254 ;
V_220 = V_251 -> V_220 << V_251 -> V_254 ;
if ( V_251 -> V_254 != V_251 -> V_255 ) {
if ( V_262 -> V_42 . V_256 . V_259 [ 1 ] > V_251 -> V_258 - 1 )
return - V_17 ;
V_1 |= V_251 -> V_266 [ V_262 -> V_42 . V_256 . V_259 [ 1 ] ] << V_251 -> V_255 ;
V_220 |= V_251 -> V_220 << V_251 -> V_255 ;
}
return F_147 ( V_5 , V_251 -> V_6 , V_220 , V_1 ) ;
}
int F_161 ( struct V_238 * V_243 ,
struct V_248 * V_249 )
{
struct V_250 * V_251 = (struct V_250 * ) V_243 -> V_252 ;
V_249 -> type = V_253 ;
V_249 -> V_18 = 1 ;
V_249 -> V_42 . V_256 . V_257 = V_251 -> V_258 ;
if ( V_249 -> V_42 . V_256 . V_259 > V_251 -> V_258 - 1 )
V_249 -> V_42 . V_256 . V_259 = V_251 -> V_258 - 1 ;
strcpy ( V_249 -> V_42 . V_256 . V_48 ,
V_251 -> V_260 [ V_249 -> V_42 . V_256 . V_259 ] ) ;
return 0 ;
}
int F_162 ( struct V_238 * V_243 ,
struct V_248 * V_249 )
{
int V_258 = V_243 -> V_252 ;
if ( V_258 == 1 && ! strstr ( V_243 -> V_267 . V_48 , L_66 ) )
V_249 -> type = V_268 ;
else
V_249 -> type = V_269 ;
V_249 -> V_18 = 1 ;
V_249 -> V_42 . integer . F_7 = 0 ;
V_249 -> V_42 . integer . V_258 = V_258 ;
return 0 ;
}
int F_163 ( struct V_238 * V_243 ,
struct V_248 * V_249 )
{
struct V_270 * V_271 =
(struct V_270 * ) V_243 -> V_252 ;
int V_272 ;
if ( ! V_271 -> V_272 )
V_271 -> V_272 = V_271 -> V_258 ;
V_272 = V_271 -> V_272 ;
if ( V_272 == 1 && ! strstr ( V_243 -> V_267 . V_48 , L_66 ) )
V_249 -> type = V_268 ;
else
V_249 -> type = V_269 ;
V_249 -> V_18 = F_164 ( V_271 ) ? 2 : 1 ;
V_249 -> V_42 . integer . F_7 = 0 ;
V_249 -> V_42 . integer . V_258 = V_272 ;
return 0 ;
}
int F_165 ( struct V_238 * V_243 ,
struct V_261 * V_262 )
{
struct V_270 * V_271 =
(struct V_270 * ) V_243 -> V_252 ;
struct V_4 * V_5 = F_157 ( V_243 ) ;
unsigned int V_6 = V_271 -> V_6 ;
unsigned int V_273 = V_271 -> V_274 ;
unsigned int V_275 = V_271 -> V_275 ;
unsigned int V_276 = V_271 -> V_276 ;
int V_258 = V_271 -> V_258 ;
unsigned int V_220 = ( 1 << F_166 ( V_258 ) ) - 1 ;
unsigned int V_277 = V_271 -> V_277 ;
V_262 -> V_42 . integer . V_42 [ 0 ] =
( F_4 ( V_5 , V_6 ) >> V_275 ) & V_220 ;
if ( V_277 )
V_262 -> V_42 . integer . V_42 [ 0 ] =
V_258 - V_262 -> V_42 . integer . V_42 [ 0 ] ;
if ( F_164 ( V_271 ) ) {
if ( V_6 == V_273 )
V_262 -> V_42 . integer . V_42 [ 1 ] =
( F_4 ( V_5 , V_6 ) >> V_276 ) & V_220 ;
else
V_262 -> V_42 . integer . V_42 [ 1 ] =
( F_4 ( V_5 , V_273 ) >> V_275 ) & V_220 ;
if ( V_277 )
V_262 -> V_42 . integer . V_42 [ 1 ] =
V_258 - V_262 -> V_42 . integer . V_42 [ 1 ] ;
}
return 0 ;
}
int F_167 ( struct V_238 * V_243 ,
struct V_261 * V_262 )
{
struct V_270 * V_271 =
(struct V_270 * ) V_243 -> V_252 ;
struct V_4 * V_5 = F_157 ( V_243 ) ;
unsigned int V_6 = V_271 -> V_6 ;
unsigned int V_273 = V_271 -> V_274 ;
unsigned int V_275 = V_271 -> V_275 ;
unsigned int V_276 = V_271 -> V_276 ;
int V_258 = V_271 -> V_258 ;
unsigned int V_220 = ( 1 << F_166 ( V_258 ) ) - 1 ;
unsigned int V_277 = V_271 -> V_277 ;
int V_73 ;
bool V_278 = 0 ;
unsigned int V_279 = 0 ;
unsigned int V_1 , V_280 ;
V_1 = ( V_262 -> V_42 . integer . V_42 [ 0 ] & V_220 ) ;
if ( V_277 )
V_1 = V_258 - V_1 ;
V_280 = V_220 << V_275 ;
V_1 = V_1 << V_275 ;
if ( F_164 ( V_271 ) ) {
V_279 = ( V_262 -> V_42 . integer . V_42 [ 1 ] & V_220 ) ;
if ( V_277 )
V_279 = V_258 - V_279 ;
if ( V_6 == V_273 ) {
V_280 |= V_220 << V_276 ;
V_1 |= V_279 << V_276 ;
} else {
V_279 = V_279 << V_275 ;
V_278 = 1 ;
}
}
V_73 = F_147 ( V_5 , V_6 , V_280 , V_1 ) ;
if ( V_73 < 0 )
return V_73 ;
if ( V_278 )
V_73 = F_147 ( V_5 , V_273 , V_280 , V_279 ) ;
return V_73 ;
}
int F_168 ( struct V_238 * V_243 ,
struct V_261 * V_262 )
{
struct V_4 * V_5 = F_157 ( V_243 ) ;
struct V_270 * V_271 =
(struct V_270 * ) V_243 -> V_252 ;
unsigned int V_6 = V_271 -> V_6 ;
unsigned int V_273 = V_271 -> V_274 ;
unsigned int V_275 = V_271 -> V_275 ;
unsigned int V_276 = V_271 -> V_276 ;
int V_258 = V_271 -> V_258 ;
int F_7 = V_271 -> F_7 ;
int V_220 = ( 1 << ( F_166 ( F_7 + V_258 ) - 1 ) ) - 1 ;
V_262 -> V_42 . integer . V_42 [ 0 ] =
( ( F_4 ( V_5 , V_6 ) >> V_275 ) - F_7 ) & V_220 ;
if ( F_164 ( V_271 ) )
V_262 -> V_42 . integer . V_42 [ 1 ] =
( ( F_4 ( V_5 , V_273 ) >> V_276 ) - F_7 ) & V_220 ;
return 0 ;
}
int F_169 ( struct V_238 * V_243 ,
struct V_261 * V_262 )
{
struct V_4 * V_5 = F_157 ( V_243 ) ;
struct V_270 * V_271 =
(struct V_270 * ) V_243 -> V_252 ;
unsigned int V_6 = V_271 -> V_6 ;
unsigned int V_273 = V_271 -> V_274 ;
unsigned int V_275 = V_271 -> V_275 ;
unsigned int V_276 = V_271 -> V_276 ;
int V_258 = V_271 -> V_258 ;
int F_7 = V_271 -> F_7 ;
int V_220 = ( 1 << ( F_166 ( F_7 + V_258 ) - 1 ) ) - 1 ;
int V_73 = 0 ;
unsigned short V_1 , V_280 , V_279 = 0 ;
V_280 = V_220 << V_275 ;
V_1 = ( V_262 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & V_220 ;
V_1 = V_1 << V_275 ;
if ( F_147 ( V_5 , V_6 , V_280 , V_1 ) )
return V_73 ;
if ( F_164 ( V_271 ) ) {
V_280 = V_220 << V_276 ;
V_279 = ( V_262 -> V_42 . integer . V_42 [ 1 ] + F_7 ) & V_220 ;
V_279 = V_279 << V_276 ;
if ( F_147 ( V_5 , V_273 , V_280 , V_279 ) )
return V_73 ;
}
return 0 ;
}
int F_170 ( struct V_238 * V_243 ,
struct V_248 * V_249 )
{
struct V_270 * V_271 =
(struct V_270 * ) V_243 -> V_252 ;
int V_272 ;
int F_7 = V_271 -> F_7 ;
if ( ! V_271 -> V_272 )
V_271 -> V_272 = V_271 -> V_258 ;
V_272 = V_271 -> V_272 ;
V_249 -> type = V_269 ;
V_249 -> V_18 = 2 ;
V_249 -> V_42 . integer . F_7 = 0 ;
V_249 -> V_42 . integer . V_258 = V_272 - F_7 ;
return 0 ;
}
int F_171 ( struct V_238 * V_243 ,
struct V_261 * V_262 )
{
struct V_270 * V_271 =
(struct V_270 * ) V_243 -> V_252 ;
struct V_4 * V_5 = F_157 ( V_243 ) ;
unsigned int V_6 = V_271 -> V_6 ;
int F_7 = V_271 -> F_7 ;
int V_1 = F_4 ( V_5 , V_6 ) ;
V_262 -> V_42 . integer . V_42 [ 0 ] =
( ( signed char ) ( V_1 & 0xff ) ) - F_7 ;
V_262 -> V_42 . integer . V_42 [ 1 ] =
( ( signed char ) ( ( V_1 >> 8 ) & 0xff ) ) - F_7 ;
return 0 ;
}
int F_172 ( struct V_238 * V_243 ,
struct V_261 * V_262 )
{
struct V_270 * V_271 =
(struct V_270 * ) V_243 -> V_252 ;
struct V_4 * V_5 = F_157 ( V_243 ) ;
unsigned int V_6 = V_271 -> V_6 ;
int F_7 = V_271 -> F_7 ;
unsigned int V_1 ;
V_1 = ( V_262 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & 0xff ;
V_1 |= ( ( V_262 -> V_42 . integer . V_42 [ 1 ] + F_7 ) & 0xff ) << 8 ;
return F_147 ( V_5 , V_6 , 0xffff , V_1 ) ;
}
int F_173 ( struct V_4 * V_5 ,
const char * V_48 , int V_258 )
{
struct V_77 * V_46 = V_5 -> V_46 -> V_77 ;
struct V_238 * V_281 ;
struct V_270 * V_271 ;
int V_181 = 0 ;
int V_14 = - V_17 ;
if ( F_174 ( ! V_48 || V_258 <= 0 ) )
return - V_17 ;
F_34 (kctl, &card->controls, list) {
if ( ! strncmp ( V_281 -> V_267 . V_48 , V_48 , sizeof( V_281 -> V_267 . V_48 ) ) ) {
V_181 = 1 ;
break;
}
}
if ( V_181 ) {
V_271 = (struct V_270 * ) V_281 -> V_252 ;
if ( V_258 <= V_271 -> V_258 ) {
V_271 -> V_272 = V_258 ;
V_14 = 0 ;
}
}
return V_14 ;
}
int F_175 ( struct V_238 * V_243 ,
struct V_248 * V_249 )
{
struct V_4 * V_5 = F_157 ( V_243 ) ;
struct V_282 * V_173 = ( void * ) V_243 -> V_252 ;
V_249 -> type = V_283 ;
V_249 -> V_18 = V_173 -> V_284 * V_5 -> V_285 ;
return 0 ;
}
int F_176 ( struct V_238 * V_243 ,
struct V_261 * V_262 )
{
struct V_282 * V_173 = ( void * ) V_243 -> V_252 ;
struct V_4 * V_5 = F_157 ( V_243 ) ;
int V_14 ;
if ( V_5 -> V_224 )
V_14 = F_177 ( V_5 -> V_225 , V_173 -> V_286 ,
V_262 -> V_42 . V_287 . V_218 ,
V_173 -> V_284 * V_5 -> V_285 ) ;
else
V_14 = - V_17 ;
if ( V_14 == 0 && V_173 -> V_220 ) {
switch ( V_5 -> V_285 ) {
case 1 :
V_262 -> V_42 . V_287 . V_218 [ 0 ] &= ~ V_173 -> V_220 ;
break;
case 2 :
( ( V_288 * ) ( & V_262 -> V_42 . V_287 . V_218 ) ) [ 0 ]
&= ~ V_173 -> V_220 ;
break;
case 4 :
( ( V_289 * ) ( & V_262 -> V_42 . V_287 . V_218 ) ) [ 0 ]
&= ~ V_173 -> V_220 ;
break;
default:
return - V_17 ;
}
}
return V_14 ;
}
int F_178 ( struct V_238 * V_243 ,
struct V_261 * V_262 )
{
struct V_282 * V_173 = ( void * ) V_243 -> V_252 ;
struct V_4 * V_5 = F_157 ( V_243 ) ;
int V_14 , V_8 ;
unsigned int V_1 ;
void * V_218 ;
if ( ! V_5 -> V_224 )
return - V_17 ;
V_218 = V_262 -> V_42 . V_287 . V_218 ;
V_8 = V_173 -> V_284 * V_5 -> V_285 ;
if ( V_173 -> V_220 ) {
V_14 = F_179 ( V_5 -> V_225 , V_173 -> V_286 , & V_1 ) ;
if ( V_14 != 0 )
return V_14 ;
V_1 &= V_173 -> V_220 ;
V_218 = F_180 ( V_218 , V_8 , V_37 ) ;
if ( ! V_218 )
return - V_38 ;
switch ( V_5 -> V_285 ) {
case 1 :
( ( V_290 * ) V_218 ) [ 0 ] &= ~ V_173 -> V_220 ;
( ( V_290 * ) V_218 ) [ 0 ] |= V_1 ;
break;
case 2 :
( ( V_288 * ) V_218 ) [ 0 ] &= F_181 ( ~ V_173 -> V_220 ) ;
( ( V_288 * ) V_218 ) [ 0 ] |= F_181 ( V_1 ) ;
break;
case 4 :
( ( V_289 * ) V_218 ) [ 0 ] &= F_182 ( ~ V_173 -> V_220 ) ;
( ( V_289 * ) V_218 ) [ 0 ] |= F_182 ( V_1 ) ;
break;
default:
return - V_17 ;
}
}
V_14 = F_183 ( V_5 -> V_225 , V_173 -> V_286 ,
V_218 , V_8 ) ;
if ( V_173 -> V_220 )
F_16 ( V_218 ) ;
return V_14 ;
}
int F_184 ( struct V_238 * V_243 ,
struct V_248 * V_249 )
{
struct V_291 * V_271 =
(struct V_291 * ) V_243 -> V_252 ;
V_249 -> type = V_269 ;
V_249 -> V_18 = 1 ;
V_249 -> V_42 . integer . F_7 = V_271 -> F_7 ;
V_249 -> V_42 . integer . V_258 = V_271 -> V_258 ;
return 0 ;
}
int F_185 ( struct V_238 * V_243 ,
struct V_261 * V_262 )
{
struct V_291 * V_271 =
(struct V_291 * ) V_243 -> V_252 ;
struct V_4 * V_5 = F_157 ( V_243 ) ;
unsigned int V_292 = V_271 -> V_292 ;
unsigned int V_293 = V_271 -> V_293 ;
unsigned int V_294 = V_5 -> V_10 -> V_13 * V_295 ;
unsigned int V_296 = ( 1 << V_294 ) - 1 ;
unsigned int V_277 = V_271 -> V_277 ;
unsigned long V_220 = ( 1UL << V_271 -> V_297 ) - 1 ;
long F_7 = V_271 -> F_7 ;
long V_258 = V_271 -> V_258 ;
long V_1 = 0 ;
unsigned long V_298 ;
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_293 ; V_3 ++ ) {
V_298 = F_4 ( V_5 , V_292 + V_3 ) & V_296 ;
V_1 |= V_298 << ( V_294 * ( V_293 - V_3 - 1 ) ) ;
}
V_1 &= V_220 ;
if ( F_7 < 0 && V_1 > V_258 )
V_1 |= ~ V_220 ;
if ( V_277 )
V_1 = V_258 - V_1 ;
V_262 -> V_42 . integer . V_42 [ 0 ] = V_1 ;
return 0 ;
}
int F_186 ( struct V_238 * V_243 ,
struct V_261 * V_262 )
{
struct V_291 * V_271 =
(struct V_291 * ) V_243 -> V_252 ;
struct V_4 * V_5 = F_157 ( V_243 ) ;
unsigned int V_292 = V_271 -> V_292 ;
unsigned int V_293 = V_271 -> V_293 ;
unsigned int V_294 = V_5 -> V_10 -> V_13 * V_295 ;
unsigned int V_296 = ( 1 << V_294 ) - 1 ;
unsigned int V_277 = V_271 -> V_277 ;
unsigned long V_220 = ( 1UL << V_271 -> V_297 ) - 1 ;
long V_258 = V_271 -> V_258 ;
long V_1 = V_262 -> V_42 . integer . V_42 [ 0 ] ;
unsigned int V_3 , V_298 , V_299 ;
int V_73 ;
if ( V_277 )
V_1 = V_258 - V_1 ;
V_1 &= V_220 ;
for ( V_3 = 0 ; V_3 < V_293 ; V_3 ++ ) {
V_298 = ( V_1 >> ( V_294 * ( V_293 - V_3 - 1 ) ) ) & V_296 ;
V_299 = ( V_220 >> ( V_294 * ( V_293 - V_3 - 1 ) ) ) & V_296 ;
V_73 = F_147 ( V_5 , V_292 + V_3 ,
V_299 , V_298 ) ;
if ( V_73 < 0 )
return V_73 ;
}
return 0 ;
}
int F_187 ( struct V_238 * V_243 ,
struct V_261 * V_262 )
{
struct V_270 * V_271 =
(struct V_270 * ) V_243 -> V_252 ;
struct V_4 * V_5 = F_157 ( V_243 ) ;
unsigned int V_6 = V_271 -> V_6 ;
unsigned int V_275 = V_271 -> V_275 ;
unsigned int V_220 = 1 << V_275 ;
unsigned int V_277 = V_271 -> V_277 != 0 ;
unsigned int V_1 = F_4 ( V_5 , V_6 ) & V_220 ;
if ( V_275 != 0 && V_1 != 0 )
V_1 = V_1 >> V_275 ;
V_262 -> V_42 . V_256 . V_259 [ 0 ] = V_1 ^ V_277 ;
return 0 ;
}
int F_188 ( struct V_238 * V_243 ,
struct V_261 * V_262 )
{
struct V_270 * V_271 =
(struct V_270 * ) V_243 -> V_252 ;
struct V_4 * V_5 = F_157 ( V_243 ) ;
unsigned int V_6 = V_271 -> V_6 ;
unsigned int V_275 = V_271 -> V_275 ;
unsigned int V_220 = 1 << V_275 ;
unsigned int V_277 = V_271 -> V_277 != 0 ;
unsigned int V_300 = V_262 -> V_42 . V_256 . V_259 [ 0 ] != 0 ;
unsigned int V_301 = ( V_300 ^ V_277 ) ? V_220 : 0 ;
unsigned int V_279 = ( V_300 ^ V_277 ) ? 0 : V_220 ;
int V_73 ;
V_73 = F_147 ( V_5 , V_6 , V_220 , V_301 ) ;
if ( V_73 < 0 )
return V_73 ;
V_73 = F_147 ( V_5 , V_6 , V_220 , V_279 ) ;
return V_73 ;
}
int F_189 ( struct V_57 * V_58 , int V_302 ,
unsigned int V_303 , int V_304 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_88 -> V_305 )
return V_58 -> V_10 -> V_88 -> V_305 ( V_58 , V_302 , V_303 , V_304 ) ;
else if ( V_58 -> V_5 && V_58 -> V_5 -> V_10 -> V_305 )
return V_58 -> V_5 -> V_10 -> V_305 ( V_58 -> V_5 , V_302 , 0 ,
V_303 , V_304 ) ;
else
return - V_17 ;
}
int F_190 ( struct V_4 * V_5 , int V_302 ,
int V_306 , unsigned int V_303 , int V_304 )
{
if ( V_5 -> V_10 -> V_305 )
return V_5 -> V_10 -> V_305 ( V_5 , V_302 , V_306 ,
V_303 , V_304 ) ;
else
return - V_17 ;
}
int F_191 ( struct V_57 * V_58 ,
int V_307 , int div )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_88 -> V_308 )
return V_58 -> V_10 -> V_88 -> V_308 ( V_58 , V_307 , div ) ;
else
return - V_17 ;
}
int F_192 ( struct V_57 * V_58 , int V_309 , int V_306 ,
unsigned int V_310 , unsigned int V_311 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_88 -> V_312 )
return V_58 -> V_10 -> V_88 -> V_312 ( V_58 , V_309 , V_306 ,
V_310 , V_311 ) ;
else if ( V_58 -> V_5 && V_58 -> V_5 -> V_10 -> V_312 )
return V_58 -> V_5 -> V_10 -> V_312 ( V_58 -> V_5 , V_309 , V_306 ,
V_310 , V_311 ) ;
else
return - V_17 ;
}
int F_193 ( struct V_4 * V_5 , int V_309 , int V_306 ,
unsigned int V_310 , unsigned int V_311 )
{
if ( V_5 -> V_10 -> V_312 )
return V_5 -> V_10 -> V_312 ( V_5 , V_309 , V_306 ,
V_310 , V_311 ) ;
else
return - V_17 ;
}
int F_117 ( struct V_57 * V_58 , unsigned int V_313 )
{
if ( V_58 -> V_10 == NULL )
return - V_17 ;
if ( V_58 -> V_10 -> V_88 -> V_314 == NULL )
return - V_195 ;
return V_58 -> V_10 -> V_88 -> V_314 ( V_58 , V_313 ) ;
}
int F_194 ( struct V_57 * V_58 ,
unsigned int V_315 , unsigned int V_316 , int V_317 , int V_318 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_88 -> V_319 )
return V_58 -> V_10 -> V_88 -> V_319 ( V_58 , V_315 , V_316 ,
V_317 , V_318 ) ;
else
return - V_17 ;
}
int F_195 ( struct V_57 * V_58 ,
unsigned int V_320 , unsigned int * V_321 ,
unsigned int V_322 , unsigned int * V_323 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_88 -> V_324 )
return V_58 -> V_10 -> V_88 -> V_324 ( V_58 , V_320 , V_321 ,
V_322 , V_323 ) ;
else
return - V_17 ;
}
int F_196 ( struct V_57 * V_58 , int V_325 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_88 -> V_326 )
return V_58 -> V_10 -> V_88 -> V_326 ( V_58 , V_325 ) ;
else
return - V_17 ;
}
int F_197 ( struct V_57 * V_58 , int V_327 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_88 -> V_89 )
return V_58 -> V_10 -> V_88 -> V_89 ( V_58 , V_327 ) ;
else
return - V_195 ;
}
int F_127 ( struct V_59 * V_46 )
{
int V_3 , V_14 ;
if ( ! V_46 -> V_48 || ! V_46 -> V_27 )
return - V_17 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ ) {
struct V_115 * V_328 = & V_46 -> V_64 [ V_3 ] ;
if ( ! ! V_328 -> V_122 == ! ! V_328 -> V_121 ) {
F_64 ( V_46 -> V_27 ,
L_67 ,
V_328 -> V_48 ) ;
return - V_17 ;
}
if ( V_328 -> V_116 && V_328 -> V_124 ) {
F_64 ( V_46 -> V_27 ,
L_68 , V_328 -> V_48 ) ;
return - V_17 ;
}
if ( ! ! V_328 -> V_119 == ! ! V_328 -> V_117 ) {
F_64 ( V_46 -> V_27 ,
L_69 ,
V_328 -> V_48 ) ;
return - V_17 ;
}
}
F_89 ( V_46 -> V_27 , V_46 ) ;
F_198 ( V_46 ) ;
F_38 ( V_46 ) ;
V_46 -> V_31 = F_199 ( V_46 -> V_27 ,
sizeof( struct V_30 ) *
( V_46 -> V_66 + V_46 -> V_189 ) ,
V_37 ) ;
if ( V_46 -> V_31 == NULL )
return - V_38 ;
V_46 -> V_83 = 0 ;
V_46 -> V_159 = & V_46 -> V_31 [ V_46 -> V_66 ] ;
for ( V_3 = 0 ; V_3 < V_46 -> V_66 ; V_3 ++ )
V_46 -> V_31 [ V_3 ] . V_64 = & V_46 -> V_64 [ V_3 ] ;
F_91 ( & V_46 -> V_151 ) ;
F_91 ( & V_46 -> V_329 ) ;
V_46 -> V_207 = 0 ;
F_90 ( & V_46 -> V_186 ) ;
F_90 ( & V_46 -> V_330 ) ;
V_14 = F_110 ( V_46 ) ;
if ( V_14 != 0 )
F_40 ( V_46 ) ;
return V_14 ;
}
int F_130 ( struct V_59 * V_46 )
{
if ( V_46 -> V_207 )
F_128 ( V_46 ) ;
F_42 ( V_46 -> V_27 , L_70 , V_46 -> V_48 ) ;
return 0 ;
}
static char * F_200 ( struct V_26 * V_27 , int * V_267 )
{
char * V_181 , V_48 [ V_331 ] ;
int V_332 , V_333 ;
if ( V_139 ( V_27 ) == NULL )
return NULL ;
F_201 ( V_48 , V_139 ( V_27 ) , V_331 ) ;
V_181 = strstr ( V_48 , V_27 -> V_10 -> V_48 ) ;
if ( V_181 ) {
if ( sscanf ( & V_181 [ strlen ( V_27 -> V_10 -> V_48 ) ] , L_71 , V_267 ) == 1 ) {
if ( * V_267 == - 1 )
V_181 [ strlen ( V_27 -> V_10 -> V_48 ) ] = '\0' ;
}
} else {
if ( sscanf ( V_48 , L_72 , & V_332 , & V_333 ) == 2 ) {
char V_334 [ V_331 ] ;
* V_267 = ( ( V_332 & 0xffff ) << 16 ) + V_333 ;
snprintf ( V_334 , V_331 , L_73 , V_27 -> V_10 -> V_48 , V_48 ) ;
F_201 ( V_48 , V_334 , V_331 ) ;
} else
* V_267 = 0 ;
}
return F_202 ( V_48 , V_37 ) ;
}
static inline char * F_203 ( struct V_26 * V_27 ,
struct V_85 * V_335 )
{
if ( V_335 -> V_48 == NULL ) {
F_72 ( L_74 ,
V_139 ( V_27 ) ) ;
return NULL ;
}
return F_202 ( V_335 -> V_48 , V_37 ) ;
}
int F_204 ( struct V_26 * V_27 ,
struct V_85 * V_335 )
{
struct V_4 * V_5 ;
struct V_57 * V_58 ;
F_42 ( V_27 , L_75 , V_139 ( V_27 ) ) ;
V_58 = F_87 ( sizeof( struct V_57 ) , V_37 ) ;
if ( V_58 == NULL )
return - V_38 ;
V_58 -> V_48 = F_200 ( V_27 , & V_58 -> V_267 ) ;
if ( V_58 -> V_48 == NULL ) {
F_16 ( V_58 ) ;
return - V_38 ;
}
V_58 -> V_27 = V_27 ;
V_58 -> V_10 = V_335 ;
V_58 -> V_53 . V_27 = V_27 ;
if ( ! V_58 -> V_10 -> V_88 )
V_58 -> V_10 -> V_88 = & V_336 ;
F_140 ( & V_337 ) ;
F_34 (codec, &codec_list, list) {
if ( V_5 -> V_27 == V_27 ) {
F_42 ( V_27 , L_76 ,
V_58 -> V_48 , V_5 -> V_48 ) ;
V_58 -> V_5 = V_5 ;
break;
}
}
F_81 ( & V_58 -> V_151 , & V_338 ) ;
F_123 ( & V_337 ) ;
F_205 ( L_77 , V_58 -> V_48 ) ;
return 0 ;
}
void F_206 ( struct V_26 * V_27 )
{
struct V_57 * V_58 ;
F_34 (dai, &dai_list, list) {
if ( V_27 == V_58 -> V_27 )
goto V_181;
}
return;
V_181:
F_140 ( & V_337 ) ;
F_68 ( & V_58 -> V_151 ) ;
F_123 ( & V_337 ) ;
F_205 ( L_78 , V_58 -> V_48 ) ;
F_16 ( V_58 -> V_48 ) ;
F_16 ( V_58 ) ;
}
int F_207 ( struct V_26 * V_27 ,
struct V_85 * V_335 , T_1 V_18 )
{
struct V_4 * V_5 ;
struct V_57 * V_58 ;
int V_3 , V_14 = 0 ;
F_42 ( V_27 , L_79 , V_139 ( V_27 ) , V_18 ) ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ ) {
V_58 = F_87 ( sizeof( struct V_57 ) , V_37 ) ;
if ( V_58 == NULL ) {
V_14 = - V_38 ;
goto V_73;
}
V_58 -> V_48 = F_203 ( V_27 , & V_335 [ V_3 ] ) ;
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
if ( ! V_58 -> V_10 -> V_88 )
V_58 -> V_10 -> V_88 = & V_336 ;
F_140 ( & V_337 ) ;
F_34 (codec, &codec_list, list) {
if ( V_5 -> V_27 == V_27 ) {
F_42 ( V_27 , L_76 ,
V_58 -> V_48 , V_5 -> V_48 ) ;
V_58 -> V_5 = V_5 ;
break;
}
}
F_81 ( & V_58 -> V_151 , & V_338 ) ;
F_123 ( & V_337 ) ;
F_205 ( L_77 , V_58 -> V_48 ) ;
}
return 0 ;
V_73:
for ( V_3 -- ; V_3 >= 0 ; V_3 -- )
F_206 ( V_27 ) ;
return V_14 ;
}
void F_208 ( struct V_26 * V_27 , T_1 V_18 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ )
F_206 ( V_27 ) ;
}
int F_209 ( struct V_26 * V_27 ,
struct V_153 * V_339 )
{
struct V_54 * V_55 ;
F_42 ( V_27 , L_80 , V_139 ( V_27 ) ) ;
V_55 = F_87 ( sizeof( struct V_54 ) , V_37 ) ;
if ( V_55 == NULL )
return - V_38 ;
V_55 -> V_48 = F_200 ( V_27 , & V_55 -> V_267 ) ;
if ( V_55 -> V_48 == NULL ) {
F_16 ( V_55 ) ;
return - V_38 ;
}
V_55 -> V_27 = V_27 ;
V_55 -> V_10 = V_339 ;
V_55 -> V_53 . V_27 = V_27 ;
V_55 -> V_53 . V_55 = V_55 ;
V_55 -> V_53 . V_340 = V_339 -> V_340 ;
F_90 ( & V_55 -> V_186 ) ;
F_140 ( & V_337 ) ;
F_81 ( & V_55 -> V_151 , & V_341 ) ;
F_123 ( & V_337 ) ;
F_205 ( L_81 , V_55 -> V_48 ) ;
return 0 ;
}
void F_210 ( struct V_26 * V_27 )
{
struct V_54 * V_55 ;
F_34 (platform, &platform_list, list) {
if ( V_27 == V_55 -> V_27 )
goto V_181;
}
return;
V_181:
F_140 ( & V_337 ) ;
F_68 ( & V_55 -> V_151 ) ;
F_123 ( & V_337 ) ;
F_205 ( L_82 , V_55 -> V_48 ) ;
F_16 ( V_55 -> V_48 ) ;
F_16 ( V_55 ) ;
}
static void F_211 ( struct V_342 * V_65 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_118 ( V_343 ) ; V_3 ++ )
if ( V_65 -> V_231 & V_343 [ V_3 ] )
V_65 -> V_231 |= V_343 [ V_3 ] ;
}
int F_212 ( struct V_26 * V_27 ,
const struct V_141 * V_344 ,
struct V_85 * V_335 ,
int V_345 )
{
T_1 V_346 ;
struct V_4 * V_5 ;
int V_14 , V_3 ;
F_42 ( V_27 , L_83 , V_139 ( V_27 ) ) ;
V_5 = F_87 ( sizeof( struct V_4 ) , V_37 ) ;
if ( V_5 == NULL )
return - V_38 ;
V_5 -> V_48 = F_200 ( V_27 , & V_5 -> V_267 ) ;
if ( V_5 -> V_48 == NULL ) {
F_16 ( V_5 ) ;
return - V_38 ;
}
if ( V_344 -> V_183 )
V_5 -> V_183 = V_344 -> V_183 ;
else
V_5 -> V_183 = V_347 ;
V_5 -> V_214 = V_344 -> V_214 ;
V_5 -> V_213 = V_344 -> V_213 ;
V_5 -> V_210 = V_344 -> V_210 ;
V_5 -> V_211 = V_344 -> V_211 ;
V_5 -> V_212 = V_344 -> V_212 ;
V_5 -> V_348 = V_344 -> V_348 ;
V_5 -> V_53 . V_98 = V_104 ;
V_5 -> V_53 . V_27 = V_27 ;
V_5 -> V_53 . V_5 = V_5 ;
V_5 -> V_53 . V_349 = V_344 -> V_349 ;
V_5 -> V_53 . V_340 = V_344 -> V_340 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_10 = V_344 ;
V_5 -> V_345 = V_345 ;
F_90 ( & V_5 -> V_186 ) ;
if ( V_344 -> V_11 && V_344 -> V_13 ) {
V_346 = V_344 -> V_11 * V_344 -> V_13 ;
V_5 -> V_346 = V_346 ;
if ( V_344 -> V_350 ) {
V_5 -> V_351 = F_180 ( V_344 -> V_350 ,
V_346 , V_37 ) ;
if ( ! V_5 -> V_351 ) {
V_14 = - V_38 ;
goto V_352;
}
}
}
if ( V_344 -> V_353 && V_344 -> V_354 ) {
if ( ! V_5 -> V_210 )
V_5 -> V_210 = V_355 ;
if ( ! V_5 -> V_211 )
V_5 -> V_211 = V_356 ;
if ( ! V_5 -> V_212 )
V_5 -> V_212 = V_357 ;
}
for ( V_3 = 0 ; V_3 < V_345 ; V_3 ++ ) {
F_211 ( & V_335 [ V_3 ] . V_358 ) ;
F_211 ( & V_335 [ V_3 ] . V_359 ) ;
}
F_140 ( & V_337 ) ;
F_81 ( & V_5 -> V_151 , & V_360 ) ;
F_123 ( & V_337 ) ;
if ( V_345 ) {
V_14 = F_207 ( V_27 , V_335 , V_345 ) ;
if ( V_14 < 0 )
F_64 ( V_5 -> V_27 , L_84 ,
V_14 ) ;
}
F_205 ( L_85 , V_5 -> V_48 ) ;
return 0 ;
V_352:
F_16 ( V_5 -> V_351 ) ;
V_5 -> V_351 = NULL ;
F_16 ( V_5 -> V_48 ) ;
F_16 ( V_5 ) ;
return V_14 ;
}
void F_213 ( struct V_26 * V_27 )
{
struct V_4 * V_5 ;
int V_3 ;
F_34 (codec, &codec_list, list) {
if ( V_27 == V_5 -> V_27 )
goto V_181;
}
return;
V_181:
if ( V_5 -> V_345 )
for ( V_3 = 0 ; V_3 < V_5 -> V_345 ; V_3 ++ )
F_206 ( V_27 ) ;
F_140 ( & V_337 ) ;
F_68 ( & V_5 -> V_151 ) ;
F_123 ( & V_337 ) ;
F_205 ( L_86 , V_5 -> V_48 ) ;
F_214 ( V_5 ) ;
F_16 ( V_5 -> V_351 ) ;
F_16 ( V_5 -> V_48 ) ;
F_16 ( V_5 ) ;
}
int F_215 ( struct V_59 * V_46 ,
const char * V_361 )
{
struct V_362 * V_363 = V_46 -> V_27 -> V_118 ;
int V_14 ;
V_14 = F_216 ( V_363 , V_361 , 0 , & V_46 -> V_48 ) ;
if ( V_14 < 0 && V_14 != - V_17 ) {
F_64 ( V_46 -> V_27 ,
L_87 ,
V_361 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
int F_217 ( struct V_59 * V_46 ,
const char * V_361 )
{
struct V_362 * V_363 = V_46 -> V_27 -> V_118 ;
int V_364 ;
struct V_365 * V_366 ;
int V_3 , V_14 ;
V_364 = F_218 ( V_363 , V_361 ) ;
if ( V_364 < 0 || V_364 & 1 ) {
F_64 ( V_46 -> V_27 ,
L_88 ,
V_361 ) ;
return - V_17 ;
}
V_364 /= 2 ;
if ( ! V_364 ) {
F_64 ( V_46 -> V_27 ,
L_89 ,
V_361 ) ;
return - V_17 ;
}
V_366 = F_199 ( V_46 -> V_27 , V_364 * sizeof( * V_366 ) ,
V_37 ) ;
if ( ! V_366 ) {
F_64 ( V_46 -> V_27 ,
L_90 ) ;
return - V_17 ;
}
for ( V_3 = 0 ; V_3 < V_364 ; V_3 ++ ) {
V_14 = F_216 ( V_363 , V_361 ,
2 * V_3 , & V_366 [ V_3 ] . V_367 ) ;
if ( V_14 ) {
F_64 ( V_46 -> V_27 ,
L_91 ,
V_361 , 2 * V_3 , V_14 ) ;
return - V_17 ;
}
V_14 = F_216 ( V_363 , V_361 ,
( 2 * V_3 ) + 1 , & V_366 [ V_3 ] . V_306 ) ;
if ( V_14 ) {
F_64 ( V_46 -> V_27 ,
L_91 ,
V_361 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_17 ;
}
}
V_46 -> V_150 = V_364 ;
V_46 -> V_149 = V_366 ;
return 0 ;
}
static int T_5 F_219 ( void )
{
#ifdef F_95
V_60 = F_24 ( L_92 , NULL ) ;
if ( F_220 ( V_60 ) || ! V_60 ) {
F_98 ( L_93 ) ;
V_60 = NULL ;
}
if ( ! F_27 ( L_94 , 0444 , V_60 , NULL ,
& V_368 ) )
F_98 ( L_95 ) ;
if ( ! F_27 ( L_96 , 0444 , V_60 , NULL ,
& V_369 ) )
F_98 ( L_97 ) ;
if ( ! F_27 ( L_98 , 0444 , V_60 , NULL ,
& V_370 ) )
F_98 ( L_99 ) ;
#endif
F_221 () ;
return F_222 ( & V_371 ) ;
}
static void T_6 F_223 ( void )
{
F_224 () ;
#ifdef F_95
F_30 ( V_60 ) ;
#endif
F_225 ( & V_371 ) ;
}
