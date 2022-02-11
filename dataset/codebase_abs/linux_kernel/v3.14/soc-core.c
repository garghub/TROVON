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
F_64 ( V_5 -> V_27 ) ;
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
F_64 ( V_94 -> V_27 ) ;
}
if ( V_47 -> V_109 )
V_47 -> V_109 ( V_47 ) ;
return 0 ;
}
static void F_65 ( struct V_80 * V_81 )
{
struct V_60 * V_47 =
F_66 ( V_81 , struct V_60 , V_110 ) ;
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
int F_67 ( struct V_26 * V_27 )
{
struct V_60 * V_47 = F_9 ( V_27 ) ;
int V_3 , V_96 = 0 ;
if ( F_53 ( & V_47 -> V_82 ) )
return 0 ;
for ( V_3 = 0 ; V_3 < V_47 -> V_85 ; V_3 ++ ) {
struct V_58 * V_94 = V_47 -> V_31 [ V_3 ] . V_94 ;
struct V_58 * V_86 = V_47 -> V_31 [ V_3 ] . V_86 ;
if ( V_94 -> V_116 )
F_68 ( V_94 -> V_27 ) ;
if ( V_86 -> V_116 )
F_68 ( V_86 -> V_27 ) ;
}
for ( V_3 = 0 ; V_3 < V_47 -> V_85 ; V_3 ++ ) {
struct V_58 * V_94 = V_47 -> V_31 [ V_3 ] . V_94 ;
V_96 |= V_94 -> V_10 -> V_96 ;
}
if ( V_96 ) {
F_42 ( V_27 , L_23 ) ;
F_65 ( & V_47 -> V_110 ) ;
} else {
F_42 ( V_27 , L_24 ) ;
if ( ! F_69 ( & V_47 -> V_110 ) )
F_50 ( V_27 , L_25 ) ;
}
return 0 ;
}
static int F_70 ( struct V_60 * V_47 , int V_117 )
{
struct V_118 * V_65 = & V_47 -> V_65 [ V_117 ] ;
struct V_30 * V_31 = & V_47 -> V_31 [ V_117 ] ;
struct V_4 * V_5 ;
struct V_55 * V_56 ;
struct V_58 * V_86 , * V_94 ;
const char * V_119 ;
F_42 ( V_47 -> V_27 , L_26 , V_65 -> V_49 , V_117 ) ;
F_34 (cpu_dai, &dai_list, list) {
if ( V_65 -> V_120 &&
( V_94 -> V_27 -> V_121 != V_65 -> V_120 ) )
continue;
if ( V_65 -> V_122 &&
strcmp ( F_71 ( V_94 -> V_27 ) , V_65 -> V_122 ) )
continue;
if ( V_65 -> V_123 &&
strcmp ( V_94 -> V_49 , V_65 -> V_123 ) )
continue;
V_31 -> V_94 = V_94 ;
}
if ( ! V_31 -> V_94 ) {
F_50 ( V_47 -> V_27 , L_27 ,
V_65 -> V_123 ) ;
return - V_124 ;
}
F_34 (codec, &codec_list, list) {
if ( V_65 -> V_125 ) {
if ( V_5 -> V_27 -> V_121 != V_65 -> V_125 )
continue;
} else {
if ( strcmp ( V_5 -> V_49 , V_65 -> V_126 ) )
continue;
}
V_31 -> V_5 = V_5 ;
F_34 (codec_dai, &dai_list, list) {
if ( V_5 -> V_27 == V_86 -> V_27 &&
! strcmp ( V_86 -> V_49 ,
V_65 -> V_127 ) ) {
V_31 -> V_86 = V_86 ;
}
}
if ( ! V_31 -> V_86 ) {
F_50 ( V_47 -> V_27 , L_28 ,
V_65 -> V_127 ) ;
return - V_124 ;
}
}
if ( ! V_31 -> V_5 ) {
F_50 ( V_47 -> V_27 , L_29 ,
V_65 -> V_126 ) ;
return - V_124 ;
}
V_119 = V_65 -> V_119 ;
if ( ! V_119 && ! V_65 -> V_128 )
V_119 = L_30 ;
F_34 (platform, &platform_list, list) {
if ( V_65 -> V_128 ) {
if ( V_56 -> V_27 -> V_121 !=
V_65 -> V_128 )
continue;
} else {
if ( strcmp ( V_56 -> V_49 , V_119 ) )
continue;
}
V_31 -> V_56 = V_56 ;
}
if ( ! V_31 -> V_56 ) {
F_50 ( V_47 -> V_27 , L_31 ,
V_65 -> V_119 ) ;
return - V_124 ;
}
V_47 -> V_85 ++ ;
return 0 ;
}
static int F_72 ( struct V_55 * V_56 )
{
int V_14 ;
if ( V_56 -> V_10 -> remove ) {
V_14 = V_56 -> V_10 -> remove ( V_56 ) ;
if ( V_14 < 0 )
F_50 ( V_56 -> V_27 , L_32 ,
V_14 ) ;
}
F_73 ( & V_56 -> V_54 ) ;
F_32 ( V_56 ) ;
V_56 -> V_129 = 0 ;
F_74 ( & V_56 -> V_130 ) ;
F_75 ( V_56 -> V_27 -> V_10 -> V_131 ) ;
return 0 ;
}
static void F_76 ( struct V_4 * V_5 )
{
int V_74 ;
if ( V_5 -> V_10 -> remove ) {
V_74 = V_5 -> V_10 -> remove ( V_5 ) ;
if ( V_74 < 0 )
F_50 ( V_5 -> V_27 , L_32 , V_74 ) ;
}
F_73 ( & V_5 -> V_54 ) ;
F_29 ( V_5 ) ;
V_5 -> V_129 = 0 ;
F_74 ( & V_5 -> V_130 ) ;
F_75 ( V_5 -> V_27 -> V_10 -> V_131 ) ;
}
static void F_77 ( struct V_60 * V_47 , int V_117 , int V_132 )
{
struct V_30 * V_31 = & V_47 -> V_31 [ V_117 ] ;
struct V_58 * V_86 = V_31 -> V_86 , * V_94 = V_31 -> V_94 ;
int V_74 ;
if ( V_31 -> V_133 ) {
F_78 ( V_31 -> V_27 , & V_134 ) ;
F_78 ( V_31 -> V_27 , & V_135 ) ;
F_45 ( V_31 -> V_27 ) ;
V_31 -> V_133 = 0 ;
}
if ( V_86 && V_86 -> V_129 &&
V_86 -> V_10 -> V_136 == V_132 ) {
if ( V_86 -> V_10 -> remove ) {
V_74 = V_86 -> V_10 -> remove ( V_86 ) ;
if ( V_74 < 0 )
F_50 ( V_86 -> V_27 ,
L_33 ,
V_86 -> V_49 , V_74 ) ;
}
V_86 -> V_129 = 0 ;
F_74 ( & V_86 -> V_130 ) ;
}
if ( V_94 && V_94 -> V_129 &&
V_94 -> V_10 -> V_136 == V_132 ) {
if ( V_94 -> V_10 -> remove ) {
V_74 = V_94 -> V_10 -> remove ( V_94 ) ;
if ( V_74 < 0 )
F_50 ( V_94 -> V_27 ,
L_33 ,
V_94 -> V_49 , V_74 ) ;
}
V_94 -> V_129 = 0 ;
F_74 ( & V_94 -> V_130 ) ;
if ( ! V_94 -> V_5 ) {
F_73 ( & V_94 -> V_54 ) ;
F_75 ( V_94 -> V_27 -> V_10 -> V_131 ) ;
}
}
}
static void F_79 ( struct V_60 * V_47 , int V_117 ,
int V_132 )
{
struct V_30 * V_31 = & V_47 -> V_31 [ V_117 ] ;
struct V_58 * V_94 = V_31 -> V_94 ;
struct V_58 * V_86 = V_31 -> V_86 ;
struct V_55 * V_56 = V_31 -> V_56 ;
struct V_4 * V_5 ;
if ( V_56 && V_56 -> V_129 &&
V_56 -> V_10 -> V_136 == V_132 ) {
F_72 ( V_56 ) ;
}
if ( V_86 ) {
V_5 = V_86 -> V_5 ;
if ( V_5 && V_5 -> V_129 &&
V_5 -> V_10 -> V_136 == V_132 )
F_76 ( V_5 ) ;
}
if ( V_94 ) {
V_5 = V_94 -> V_5 ;
if ( V_5 && V_5 -> V_129 &&
V_5 -> V_10 -> V_136 == V_132 )
F_76 ( V_5 ) ;
}
}
static void F_80 ( struct V_60 * V_47 )
{
int V_59 , V_132 ;
for ( V_132 = V_137 ; V_132 <= V_138 ;
V_132 ++ ) {
for ( V_59 = 0 ; V_59 < V_47 -> V_85 ; V_59 ++ )
F_77 ( V_47 , V_59 , V_132 ) ;
}
for ( V_132 = V_137 ; V_132 <= V_138 ;
V_132 ++ ) {
for ( V_59 = 0 ; V_59 < V_47 -> V_85 ; V_59 ++ )
F_79 ( V_47 , V_59 , V_132 ) ;
}
V_47 -> V_85 = 0 ;
}
static void F_81 ( struct V_60 * V_47 ,
struct V_4 * V_5 )
{
int V_3 ;
if ( V_47 -> V_139 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_47 -> V_140 ; V_3 ++ ) {
struct V_141 * V_142 = & V_47 -> V_139 [ V_3 ] ;
if ( V_142 -> F_71 && ! strcmp ( V_5 -> V_49 , V_142 -> F_71 ) ) {
V_5 -> V_143 = V_142 -> V_143 ;
break;
}
}
}
static int F_82 ( struct V_60 * V_47 ,
struct V_4 * V_5 )
{
int V_14 = 0 ;
const struct V_144 * V_10 = V_5 -> V_10 ;
struct V_58 * V_59 ;
V_5 -> V_47 = V_47 ;
V_5 -> V_54 . V_47 = V_47 ;
F_81 ( V_47 , V_5 ) ;
if ( ! F_83 ( V_5 -> V_27 -> V_10 -> V_131 ) )
return - V_145 ;
F_23 ( V_5 ) ;
if ( V_10 -> V_146 )
F_84 ( & V_5 -> V_54 , V_10 -> V_146 ,
V_10 -> V_147 ) ;
F_34 (dai, &dai_list, list) {
if ( V_59 -> V_27 != V_5 -> V_27 )
continue;
F_85 ( & V_5 -> V_54 , V_59 ) ;
}
V_5 -> V_54 . V_105 = V_10 -> V_105 ;
if ( V_10 -> V_148 ) {
V_14 = V_10 -> V_148 ( V_5 ) ;
if ( V_14 < 0 ) {
F_50 ( V_5 -> V_27 ,
L_34 , V_14 ) ;
goto V_149;
}
F_86 ( V_5 -> V_54 . V_105 &&
V_5 -> V_54 . V_100 != V_106 ,
L_35 ,
V_5 -> V_49 ) ;
}
if ( ! V_5 -> V_150 && F_87 ( V_5 -> V_27 , NULL ) )
F_88 ( V_5 , 0 , 0 , V_151 ) ;
if ( V_10 -> V_152 )
F_89 ( V_5 , V_10 -> V_152 ,
V_10 -> V_153 ) ;
if ( V_10 -> V_154 )
F_90 ( & V_5 -> V_54 , V_10 -> V_154 ,
V_10 -> V_155 ) ;
V_5 -> V_129 = 1 ;
F_91 ( & V_5 -> V_130 , & V_47 -> V_82 ) ;
F_91 ( & V_5 -> V_54 . V_156 , & V_47 -> V_157 ) ;
return 0 ;
V_149:
F_29 ( V_5 ) ;
F_75 ( V_5 -> V_27 -> V_10 -> V_131 ) ;
return V_14 ;
}
static int F_92 ( struct V_60 * V_47 ,
struct V_55 * V_56 )
{
int V_14 = 0 ;
const struct V_158 * V_10 = V_56 -> V_10 ;
struct V_58 * V_59 ;
V_56 -> V_47 = V_47 ;
V_56 -> V_54 . V_47 = V_47 ;
if ( ! F_83 ( V_56 -> V_27 -> V_10 -> V_131 ) )
return - V_145 ;
F_31 ( V_56 ) ;
if ( V_10 -> V_146 )
F_84 ( & V_56 -> V_54 ,
V_10 -> V_146 , V_10 -> V_147 ) ;
F_34 (dai, &dai_list, list) {
if ( V_59 -> V_27 != V_56 -> V_27 )
continue;
F_85 ( & V_56 -> V_54 , V_59 ) ;
}
V_56 -> V_54 . V_105 = 1 ;
if ( V_10 -> V_148 ) {
V_14 = V_10 -> V_148 ( V_56 ) ;
if ( V_14 < 0 ) {
F_50 ( V_56 -> V_27 ,
L_36 , V_14 ) ;
goto V_149;
}
}
if ( V_10 -> V_152 )
F_93 ( V_56 , V_10 -> V_152 ,
V_10 -> V_153 ) ;
if ( V_10 -> V_154 )
F_90 ( & V_56 -> V_54 , V_10 -> V_154 ,
V_10 -> V_155 ) ;
V_56 -> V_129 = 1 ;
F_91 ( & V_56 -> V_130 , & V_47 -> V_159 ) ;
F_91 ( & V_56 -> V_54 . V_156 , & V_47 -> V_157 ) ;
return 0 ;
V_149:
F_32 ( V_56 ) ;
F_75 ( V_56 -> V_27 -> V_10 -> V_131 ) ;
return V_14 ;
}
static void F_94 ( struct V_26 * V_27 )
{
F_16 ( V_27 ) ;
}
static int F_95 ( struct V_60 * V_47 ,
struct V_4 * V_5 ,
int V_117 , int V_160 )
{
struct V_118 * V_65 = NULL ;
struct V_161 * V_162 = NULL ;
struct V_30 * V_31 ;
const char * V_163 , * V_49 ;
int V_14 = 0 ;
if ( ! V_160 ) {
V_65 = & V_47 -> V_65 [ V_117 ] ;
V_31 = & V_47 -> V_31 [ V_117 ] ;
V_49 = V_65 -> V_49 ;
} else {
V_162 = & V_47 -> V_162 [ V_117 ] ;
V_31 = & V_47 -> V_164 [ V_117 ] ;
V_49 = V_162 -> V_49 ;
}
V_31 -> V_47 = V_47 ;
V_163 = V_5 -> V_143 ;
V_5 -> V_143 = NULL ;
if ( ! V_160 && V_65 -> V_165 )
V_14 = V_65 -> V_165 ( V_31 ) ;
else if ( V_160 && V_162 -> V_165 )
V_14 = V_162 -> V_165 ( & V_5 -> V_54 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 , L_37 , V_49 , V_14 ) ;
return V_14 ;
}
V_5 -> V_143 = V_163 ;
V_31 -> V_5 = V_5 ;
V_31 -> V_27 = F_96 ( sizeof( struct V_26 ) , V_37 ) ;
if ( ! V_31 -> V_27 )
return - V_38 ;
F_97 ( V_31 -> V_27 ) ;
V_31 -> V_27 -> V_76 = V_47 -> V_27 ;
V_31 -> V_27 -> V_77 = F_94 ;
V_31 -> V_27 -> V_166 = V_49 ;
F_98 ( V_31 -> V_27 , V_31 ) ;
F_99 ( & V_31 -> V_167 ) ;
F_100 ( & V_31 -> V_168 [ V_101 ] . V_169 ) ;
F_100 ( & V_31 -> V_168 [ V_103 ] . V_169 ) ;
F_100 ( & V_31 -> V_168 [ V_101 ] . V_170 ) ;
F_100 ( & V_31 -> V_168 [ V_103 ] . V_170 ) ;
V_14 = F_101 ( V_31 -> V_27 ) ;
if ( V_14 < 0 ) {
F_102 ( V_31 -> V_27 ) ;
F_50 ( V_47 -> V_27 ,
L_38 , V_14 ) ;
return V_14 ;
}
V_31 -> V_133 = 1 ;
V_14 = F_103 ( V_31 -> V_27 ) ;
if ( V_14 < 0 )
F_50 ( V_5 -> V_27 ,
L_39 , V_14 ) ;
V_14 = F_104 ( V_31 -> V_27 , & V_135 ) ;
if ( V_14 < 0 )
F_50 ( V_5 -> V_27 ,
L_40 , V_14 ) ;
#ifdef F_105
if ( ! V_160 && ! V_65 -> V_171 )
goto V_172;
V_14 = F_106 ( V_31 ) ;
if ( V_14 < 0 )
F_50 ( V_31 -> V_27 , L_41 , V_14 ) ;
V_172:
#endif
return 0 ;
}
static int F_107 ( struct V_60 * V_47 , int V_117 ,
int V_132 )
{
struct V_30 * V_31 = & V_47 -> V_31 [ V_117 ] ;
struct V_58 * V_94 = V_31 -> V_94 ;
struct V_58 * V_86 = V_31 -> V_86 ;
struct V_55 * V_56 = V_31 -> V_56 ;
int V_14 ;
if ( V_94 -> V_5 &&
! V_94 -> V_5 -> V_129 &&
V_94 -> V_5 -> V_10 -> V_173 == V_132 ) {
V_14 = F_82 ( V_47 , V_94 -> V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_86 -> V_5 -> V_129 &&
V_86 -> V_5 -> V_10 -> V_173 == V_132 ) {
V_14 = F_82 ( V_47 , V_86 -> V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_56 -> V_129 &&
V_56 -> V_10 -> V_173 == V_132 ) {
V_14 = F_92 ( V_47 , V_56 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
static int F_108 ( struct V_60 * V_47 , int V_117 , int V_132 )
{
struct V_118 * V_65 = & V_47 -> V_65 [ V_117 ] ;
struct V_30 * V_31 = & V_47 -> V_31 [ V_117 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
struct V_55 * V_56 = V_31 -> V_56 ;
struct V_58 * V_86 = V_31 -> V_86 ;
struct V_58 * V_94 = V_31 -> V_94 ;
struct V_174 * V_175 , * V_176 ;
int V_14 ;
F_42 ( V_47 -> V_27 , L_42 ,
V_47 -> V_49 , V_117 , V_132 ) ;
V_94 -> V_56 = V_56 ;
V_86 -> V_47 = V_47 ;
V_94 -> V_47 = V_47 ;
V_31 -> V_32 = V_32 ;
if ( ! V_94 -> V_129 &&
V_94 -> V_10 -> V_173 == V_132 ) {
if ( ! V_94 -> V_5 ) {
V_94 -> V_54 . V_47 = V_47 ;
if ( ! F_83 ( V_94 -> V_27 -> V_10 -> V_131 ) )
return - V_145 ;
F_91 ( & V_94 -> V_54 . V_156 , & V_47 -> V_157 ) ;
}
if ( V_94 -> V_10 -> V_148 ) {
V_14 = V_94 -> V_10 -> V_148 ( V_94 ) ;
if ( V_14 < 0 ) {
F_50 ( V_94 -> V_27 ,
L_43 ,
V_94 -> V_49 , V_14 ) ;
F_75 ( V_94 -> V_27 -> V_10 -> V_131 ) ;
return V_14 ;
}
}
V_94 -> V_129 = 1 ;
F_91 ( & V_94 -> V_130 , & V_47 -> V_177 ) ;
}
if ( ! V_86 -> V_129 && V_86 -> V_10 -> V_173 == V_132 ) {
if ( V_86 -> V_10 -> V_148 ) {
V_14 = V_86 -> V_10 -> V_148 ( V_86 ) ;
if ( V_14 < 0 ) {
F_50 ( V_86 -> V_27 ,
L_44 ,
V_86 -> V_49 , V_14 ) ;
return V_14 ;
}
}
V_86 -> V_129 = 1 ;
F_91 ( & V_86 -> V_130 , & V_47 -> V_177 ) ;
}
if ( V_132 != V_138 )
return 0 ;
V_14 = F_95 ( V_47 , V_5 , V_117 , 0 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_104 ( V_31 -> V_27 , & V_134 ) ;
if ( V_14 < 0 )
F_25 ( V_31 -> V_27 , L_45 ,
V_14 ) ;
if ( V_94 -> V_10 -> V_178 ) {
V_14 = F_109 ( V_31 , V_117 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 , L_46 ,
V_65 -> V_179 ) ;
return V_14 ;
}
} else {
if ( ! V_65 -> V_180 ) {
V_14 = F_110 ( V_31 , V_117 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 , L_47 ,
V_65 -> V_179 , V_14 ) ;
return V_14 ;
}
} else {
F_111 ( & V_31 -> V_98 ,
F_51 ) ;
V_175 = V_86 -> V_181 ;
V_176 = V_94 -> V_182 ;
if ( V_175 && V_176 ) {
V_14 = F_112 ( V_47 , V_65 -> V_180 ,
V_176 , V_175 ) ;
if ( V_14 != 0 ) {
F_50 ( V_47 -> V_27 , L_48 ,
V_175 -> V_49 , V_176 -> V_49 , V_14 ) ;
return V_14 ;
}
}
V_175 = V_94 -> V_181 ;
V_176 = V_86 -> V_182 ;
if ( V_175 && V_176 ) {
V_14 = F_112 ( V_47 , V_65 -> V_180 ,
V_176 , V_175 ) ;
if ( V_14 != 0 ) {
F_50 ( V_47 -> V_27 , L_48 ,
V_175 -> V_49 , V_176 -> V_49 , V_14 ) ;
return V_14 ;
}
}
}
}
if ( V_31 -> V_86 -> V_10 -> V_96 )
F_113 ( V_5 -> V_72 , V_31 -> V_94 -> V_183 ) ;
return 0 ;
}
static int F_114 ( struct V_30 * V_31 )
{
int V_14 ;
if ( V_31 -> V_86 -> V_10 -> V_96 && ! V_31 -> V_5 -> V_184 ) {
if ( ! V_31 -> V_5 -> V_185 )
return 0 ;
V_14 = F_47 ( V_31 -> V_5 ) ;
if ( V_14 < 0 ) {
F_50 ( V_31 -> V_5 -> V_27 ,
L_49 , V_14 ) ;
return V_14 ;
}
V_31 -> V_5 -> V_184 = 1 ;
}
return 0 ;
}
static void F_115 ( struct V_4 * V_5 )
{
if ( V_5 -> V_184 ) {
F_44 ( V_5 ) ;
V_5 -> V_184 = 0 ;
}
}
static int F_116 ( struct V_60 * V_47 , int V_117 )
{
struct V_161 * V_162 = & V_47 -> V_162 [ V_117 ] ;
struct V_4 * V_5 ;
F_34 (codec, &codec_list, list) {
if ( ! strcmp ( V_5 -> V_49 , V_162 -> V_126 ) )
return 0 ;
}
F_50 ( V_47 -> V_27 , L_50 , V_162 -> V_126 ) ;
return - V_124 ;
}
static int F_117 ( struct V_60 * V_47 , int V_117 )
{
struct V_161 * V_162 = & V_47 -> V_162 [ V_117 ] ;
struct V_4 * V_5 ;
int V_14 = - V_145 ;
F_34 (codec, &codec_list, list) {
if ( ! strcmp ( V_5 -> V_49 , V_162 -> V_126 ) ) {
if ( V_5 -> V_129 ) {
F_50 ( V_5 -> V_27 ,
L_51 ) ;
V_14 = - V_186 ;
goto V_172;
}
goto V_187;
}
}
F_50 ( V_47 -> V_27 , L_52 , V_162 -> V_126 ) ;
return - V_124 ;
V_187:
V_14 = F_82 ( V_47 , V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_95 ( V_47 , V_5 , V_117 , 1 ) ;
V_172:
return V_14 ;
}
static void F_118 ( struct V_60 * V_47 , int V_117 )
{
struct V_30 * V_31 = & V_47 -> V_164 [ V_117 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
if ( V_31 -> V_133 ) {
F_78 ( V_31 -> V_27 , & V_135 ) ;
F_45 ( V_31 -> V_27 ) ;
V_31 -> V_133 = 0 ;
}
if ( V_5 && V_5 -> V_129 )
F_76 ( V_5 ) ;
}
static int F_119 ( struct V_4 * V_5 )
{
int V_14 ;
if ( V_5 -> V_188 )
return 0 ;
V_14 = F_120 ( V_5 ) ;
if ( V_14 < 0 ) {
F_50 ( V_5 -> V_27 ,
L_53 ,
V_14 ) ;
return V_14 ;
}
V_5 -> V_188 = 1 ;
return 0 ;
}
static int F_121 ( struct V_60 * V_47 )
{
struct V_4 * V_5 ;
struct V_118 * V_65 ;
int V_14 , V_3 , V_132 , V_189 ;
F_122 ( & V_47 -> V_190 , V_191 ) ;
for ( V_3 = 0 ; V_3 < V_47 -> V_67 ; V_3 ++ ) {
V_14 = F_70 ( V_47 , V_3 ) ;
if ( V_14 != 0 )
goto V_192;
}
for ( V_3 = 0 ; V_3 < V_47 -> V_193 ; V_3 ++ ) {
V_14 = F_116 ( V_47 , V_3 ) ;
if ( V_14 != 0 )
goto V_192;
}
F_34 (codec, &codec_list, list) {
if ( V_5 -> V_188 )
continue;
V_14 = F_119 ( V_5 ) ;
if ( V_14 < 0 )
goto V_192;
}
V_14 = F_123 ( V_194 , V_195 ,
V_47 -> V_131 , 0 , & V_47 -> V_78 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 ,
L_54 ,
V_47 -> V_49 , V_14 ) ;
goto V_192;
}
V_47 -> V_78 -> V_27 = V_47 -> V_27 ;
V_47 -> V_54 . V_100 = V_106 ;
V_47 -> V_54 . V_27 = V_47 -> V_27 ;
V_47 -> V_54 . V_47 = V_47 ;
F_91 ( & V_47 -> V_54 . V_156 , & V_47 -> V_157 ) ;
#ifdef F_105
F_28 ( & V_47 -> V_54 , V_47 -> V_46 ) ;
#endif
#ifdef F_124
F_125 ( & V_47 -> V_110 , F_65 ) ;
#endif
if ( V_47 -> V_146 )
F_84 ( & V_47 -> V_54 , V_47 -> V_146 ,
V_47 -> V_147 ) ;
if ( V_47 -> V_148 ) {
V_14 = V_47 -> V_148 ( V_47 ) ;
if ( V_14 < 0 )
goto V_196;
}
for ( V_132 = V_137 ; V_132 <= V_138 ;
V_132 ++ ) {
for ( V_3 = 0 ; V_3 < V_47 -> V_67 ; V_3 ++ ) {
V_14 = F_107 ( V_47 , V_3 , V_132 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 ,
L_55 ,
V_14 ) ;
goto V_197;
}
}
}
for ( V_132 = V_137 ; V_132 <= V_138 ;
V_132 ++ ) {
for ( V_3 = 0 ; V_3 < V_47 -> V_67 ; V_3 ++ ) {
V_14 = F_108 ( V_47 , V_3 , V_132 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 ,
L_55 ,
V_14 ) ;
goto V_197;
}
}
}
for ( V_3 = 0 ; V_3 < V_47 -> V_193 ; V_3 ++ ) {
V_14 = F_117 ( V_47 , V_3 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 ,
L_56 ,
V_14 ) ;
goto V_198;
}
}
F_126 ( V_47 ) ;
F_127 ( V_47 ) ;
if ( V_47 -> V_152 )
F_128 ( V_47 , V_47 -> V_152 , V_47 -> V_153 ) ;
if ( V_47 -> V_154 )
F_90 ( & V_47 -> V_54 , V_47 -> V_154 ,
V_47 -> V_155 ) ;
for ( V_3 = 0 ; V_3 < V_47 -> V_67 ; V_3 ++ ) {
V_65 = & V_47 -> V_65 [ V_3 ] ;
V_189 = V_65 -> V_189 ;
if ( V_189 ) {
V_14 = F_129 ( V_47 -> V_31 [ V_3 ] . V_86 ,
V_189 ) ;
if ( V_14 != 0 && V_14 != - V_199 )
F_25 ( V_47 -> V_31 [ V_3 ] . V_86 -> V_27 ,
L_57 ,
V_14 ) ;
}
if ( V_189 &&
( V_65 -> V_119 || V_65 -> V_128 ) ) {
V_14 = F_129 ( V_47 -> V_31 [ V_3 ] . V_94 ,
V_189 ) ;
if ( V_14 != 0 && V_14 != - V_199 )
F_25 ( V_47 -> V_31 [ V_3 ] . V_94 -> V_27 ,
L_57 ,
V_14 ) ;
} else if ( V_189 ) {
V_189 &= ~ V_200 ;
switch ( V_65 -> V_189 &
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
V_14 = F_129 ( V_47 -> V_31 [ V_3 ] . V_94 ,
V_189 ) ;
if ( V_14 != 0 && V_14 != - V_199 )
F_25 ( V_47 -> V_31 [ V_3 ] . V_94 -> V_27 ,
L_57 ,
V_14 ) ;
}
}
snprintf ( V_47 -> V_78 -> V_205 , sizeof( V_47 -> V_78 -> V_205 ) ,
L_58 , V_47 -> V_49 ) ;
snprintf ( V_47 -> V_78 -> V_206 , sizeof( V_47 -> V_78 -> V_206 ) ,
L_58 , V_47 -> V_207 ? V_47 -> V_207 : V_47 -> V_49 ) ;
snprintf ( V_47 -> V_78 -> V_10 , sizeof( V_47 -> V_78 -> V_10 ) ,
L_58 , V_47 -> V_208 ? V_47 -> V_208 : V_47 -> V_49 ) ;
for ( V_3 = 0 ; V_3 < F_130 ( V_47 -> V_78 -> V_10 ) ; V_3 ++ ) {
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
if ( V_47 -> V_209 ) {
V_14 = V_47 -> V_209 ( V_47 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 , L_59 ,
V_47 -> V_49 , V_14 ) ;
goto V_198;
}
}
if ( V_47 -> V_210 )
F_34 (codec, &card->codec_dev_list, card_list)
F_131 ( V_5 ) ;
F_132 ( V_47 ) ;
V_14 = F_133 ( V_47 -> V_78 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 , L_60 ,
V_14 ) ;
goto V_198;
}
#ifdef F_134
for ( V_3 = 0 ; V_3 < V_47 -> V_85 ; V_3 ++ ) {
V_14 = F_114 ( & V_47 -> V_31 [ V_3 ] ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 ,
L_61 , V_14 ) ;
while ( -- V_3 >= 0 )
F_115 ( V_47 -> V_31 [ V_3 ] . V_5 ) ;
goto V_198;
}
}
#endif
V_47 -> V_211 = 1 ;
F_62 ( & V_47 -> V_54 ) ;
F_135 ( & V_47 -> V_190 ) ;
return 0 ;
V_198:
for ( V_3 = 0 ; V_3 < V_47 -> V_193 ; V_3 ++ )
F_118 ( V_47 , V_3 ) ;
V_197:
F_80 ( V_47 ) ;
V_196:
if ( V_47 -> remove )
V_47 -> remove ( V_47 ) ;
F_136 ( V_47 -> V_78 ) ;
V_192:
F_135 ( & V_47 -> V_190 ) ;
return V_14 ;
}
static int F_137 ( struct V_212 * V_213 )
{
struct V_60 * V_47 = F_138 ( V_213 ) ;
if ( ! V_47 )
return - V_17 ;
F_25 ( & V_213 -> V_27 ,
L_62 ,
V_47 -> V_49 ) ;
V_47 -> V_27 = & V_213 -> V_27 ;
return F_139 ( V_47 ) ;
}
static int F_140 ( struct V_60 * V_47 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_47 -> V_85 ; V_3 ++ ) {
struct V_30 * V_31 = & V_47 -> V_31 [ V_3 ] ;
F_59 ( & V_31 -> V_98 ) ;
}
for ( V_3 = 0 ; V_3 < V_47 -> V_193 ; V_3 ++ )
F_118 ( V_47 , V_3 ) ;
F_80 ( V_47 ) ;
F_40 ( V_47 ) ;
if ( V_47 -> remove )
V_47 -> remove ( V_47 ) ;
F_73 ( & V_47 -> V_54 ) ;
F_136 ( V_47 -> V_78 ) ;
return 0 ;
}
static int F_141 ( struct V_212 * V_213 )
{
struct V_60 * V_47 = F_138 ( V_213 ) ;
F_142 ( V_47 ) ;
return 0 ;
}
int F_143 ( struct V_26 * V_27 )
{
struct V_60 * V_47 = F_9 ( V_27 ) ;
int V_3 ;
if ( ! V_47 -> V_211 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_47 -> V_85 ; V_3 ++ ) {
struct V_30 * V_31 = & V_47 -> V_31 [ V_3 ] ;
F_59 ( & V_31 -> V_98 ) ;
}
F_144 ( V_47 ) ;
for ( V_3 = 0 ; V_3 < V_47 -> V_85 ; V_3 ++ ) {
struct V_58 * V_94 = V_47 -> V_31 [ V_3 ] . V_94 ;
struct V_58 * V_86 = V_47 -> V_31 [ V_3 ] . V_86 ;
F_64 ( V_86 -> V_27 ) ;
F_64 ( V_94 -> V_27 ) ;
}
return 0 ;
}
int F_145 ( struct V_4 * V_5 ,
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
int F_146 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_216 )
return V_5 -> V_216 ( V_5 , V_6 ) ;
else
return 1 ;
}
int F_147 ( struct V_55 * V_56 ,
unsigned int V_6 )
{
unsigned int V_14 ;
if ( ! V_56 -> V_10 -> V_217 ) {
F_50 ( V_56 -> V_27 , L_63 ) ;
return - 1 ;
}
V_14 = V_56 -> V_10 -> V_217 ( V_56 , V_6 ) ;
F_42 ( V_56 -> V_27 , L_64 , V_6 , V_14 ) ;
F_148 ( V_56 , V_6 , V_14 ) ;
return V_14 ;
}
int F_149 ( struct V_55 * V_56 ,
unsigned int V_6 , unsigned int V_1 )
{
if ( ! V_56 -> V_10 -> V_150 ) {
F_50 ( V_56 -> V_27 , L_65 ) ;
return - 1 ;
}
F_42 ( V_56 -> V_27 , L_66 , V_6 , V_1 ) ;
F_150 ( V_56 , V_6 , V_1 ) ;
return V_56 -> V_10 -> V_150 ( V_56 , V_6 , V_1 ) ;
}
int F_151 ( struct V_4 * V_5 ,
struct V_218 * V_90 , int V_117 )
{
F_152 ( & V_5 -> V_190 ) ;
V_5 -> V_72 = F_96 ( sizeof( struct V_219 ) , V_37 ) ;
if ( V_5 -> V_72 == NULL ) {
F_135 ( & V_5 -> V_190 ) ;
return - V_38 ;
}
V_5 -> V_72 -> V_73 = F_96 ( sizeof( struct V_220 ) , V_37 ) ;
if ( V_5 -> V_72 -> V_73 == NULL ) {
F_16 ( V_5 -> V_72 ) ;
V_5 -> V_72 = NULL ;
F_135 ( & V_5 -> V_190 ) ;
return - V_38 ;
}
V_5 -> V_72 -> V_73 -> V_90 = V_90 ;
V_5 -> V_72 -> V_117 = V_117 ;
V_5 -> V_185 = 1 ;
F_135 ( & V_5 -> V_190 ) ;
return 0 ;
}
static void F_153 ( struct V_219 * V_72 )
{
struct V_221 * V_222 = V_223 . V_222 ;
F_154 ( V_222 , V_223 . V_224 ) ;
F_155 ( V_223 . V_225 , 1 ) ;
F_156 ( 10 ) ;
F_155 ( V_223 . V_225 , 0 ) ;
F_154 ( V_222 , V_223 . V_226 ) ;
F_157 ( 2 ) ;
}
static void F_158 ( struct V_219 * V_72 )
{
struct V_221 * V_222 = V_223 . V_222 ;
F_154 ( V_222 , V_223 . V_227 ) ;
F_155 ( V_223 . V_225 , 0 ) ;
F_155 ( V_223 . V_228 , 0 ) ;
F_155 ( V_223 . V_229 , 0 ) ;
F_156 ( 10 ) ;
F_155 ( V_223 . V_229 , 1 ) ;
F_154 ( V_222 , V_223 . V_226 ) ;
F_157 ( 2 ) ;
}
static int F_159 ( struct V_26 * V_27 ,
struct V_230 * V_231 )
{
struct V_221 * V_22 ;
struct V_232 * V_233 ;
int V_234 ;
int V_14 ;
V_22 = F_160 ( V_27 ) ;
if ( F_161 ( V_22 ) ) {
F_50 ( V_27 , L_67 ) ;
return F_162 ( V_22 ) ;
}
V_231 -> V_222 = V_22 ;
V_233 = F_163 ( V_22 , L_68 ) ;
if ( F_161 ( V_233 ) ) {
F_50 ( V_27 , L_69 ) ;
return F_162 ( V_233 ) ;
}
V_231 -> V_227 = V_233 ;
V_233 = F_163 ( V_22 , L_70 ) ;
if ( F_161 ( V_233 ) ) {
F_50 ( V_27 , L_71 ) ;
return F_162 ( V_233 ) ;
}
V_231 -> V_224 = V_233 ;
V_233 = F_163 ( V_22 , L_72 ) ;
if ( F_161 ( V_233 ) ) {
F_50 ( V_27 , L_73 ) ;
return F_162 ( V_233 ) ;
}
V_231 -> V_226 = V_233 ;
V_234 = F_164 ( V_27 -> V_121 , L_74 , 0 ) ;
if ( V_234 < 0 ) {
F_50 ( V_27 , L_75 ) ;
return V_234 ;
}
V_14 = F_165 ( V_27 , V_234 , L_76 ) ;
if ( V_14 ) {
F_50 ( V_27 , L_77 ) ;
return V_14 ;
}
V_231 -> V_225 = V_234 ;
V_234 = F_164 ( V_27 -> V_121 , L_74 , 1 ) ;
if ( V_234 < 0 ) {
F_50 ( V_27 , L_78 , V_234 ) ;
return V_234 ;
}
V_14 = F_165 ( V_27 , V_234 , L_79 ) ;
if ( V_14 ) {
F_50 ( V_27 , L_80 ) ;
return V_14 ;
}
V_231 -> V_228 = V_234 ;
V_234 = F_164 ( V_27 -> V_121 , L_74 , 2 ) ;
if ( V_234 < 0 ) {
F_50 ( V_27 , L_81 ) ;
return V_234 ;
}
V_14 = F_165 ( V_27 , V_234 , L_82 ) ;
if ( V_14 ) {
F_50 ( V_27 , L_83 ) ;
return V_14 ;
}
V_231 -> V_229 = V_234 ;
return 0 ;
}
int F_166 ( struct V_218 * V_90 )
{
if ( V_90 == V_235 )
return 0 ;
if ( V_235 && V_90 )
return - V_186 ;
V_235 = V_90 ;
return 0 ;
}
int F_167 ( struct V_218 * V_90 ,
struct V_212 * V_213 )
{
struct V_26 * V_27 = & V_213 -> V_27 ;
struct V_230 V_231 ;
int V_14 ;
V_14 = F_159 ( V_27 , & V_231 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_166 ( V_90 ) ;
if ( V_14 )
return V_14 ;
V_90 -> V_236 = F_153 ;
V_90 -> V_237 = F_158 ;
V_223 = V_231 ;
return 0 ;
}
void F_168 ( struct V_4 * V_5 )
{
F_152 ( & V_5 -> V_190 ) ;
#ifdef F_134
F_115 ( V_5 ) ;
#endif
F_16 ( V_5 -> V_72 -> V_73 ) ;
F_16 ( V_5 -> V_72 ) ;
V_5 -> V_72 = NULL ;
V_5 -> V_185 = 0 ;
F_135 ( & V_5 -> V_190 ) ;
}
unsigned int F_4 ( struct V_4 * V_5 , unsigned int V_6 )
{
unsigned int V_14 ;
V_14 = V_5 -> V_217 ( V_5 , V_6 ) ;
F_42 ( V_5 -> V_27 , L_64 , V_6 , V_14 ) ;
F_169 ( V_5 , V_6 , V_14 ) ;
return V_14 ;
}
unsigned int F_22 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned int V_1 )
{
F_42 ( V_5 -> V_27 , L_66 , V_6 , V_1 ) ;
F_170 ( V_5 , V_6 , V_1 ) ;
return V_5 -> V_150 ( V_5 , V_6 , V_1 ) ;
}
int F_171 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_238 , unsigned int V_42 )
{
bool V_239 ;
unsigned int V_240 , V_241 ;
int V_14 ;
if ( V_5 -> V_107 ) {
V_14 = F_172 ( V_5 -> V_108 , V_6 ,
V_238 , V_42 , & V_239 ) ;
} else {
V_14 = F_4 ( V_5 , V_6 ) ;
if ( V_14 < 0 )
return V_14 ;
V_240 = V_14 ;
V_241 = ( V_240 & ~ V_238 ) | ( V_42 & V_238 ) ;
V_239 = V_240 != V_241 ;
if ( V_239 )
V_14 = F_22 ( V_5 , V_6 , V_241 ) ;
}
if ( V_14 < 0 )
return V_14 ;
return V_239 ;
}
int F_173 ( struct V_4 * V_5 ,
unsigned short V_6 , unsigned int V_238 ,
unsigned int V_42 )
{
int V_239 ;
F_152 ( & V_5 -> V_190 ) ;
V_239 = F_171 ( V_5 , V_6 , V_238 , V_42 ) ;
F_135 ( & V_5 -> V_190 ) ;
return V_239 ;
}
int F_174 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_238 , unsigned int V_42 )
{
int V_239 ;
unsigned int V_240 , V_241 ;
V_240 = F_4 ( V_5 , V_6 ) ;
V_241 = ( V_240 & ~ V_238 ) | V_42 ;
V_239 = V_240 != V_241 ;
return V_239 ;
}
struct V_242 * F_175 ( const struct V_243 * V_244 ,
void * V_245 , const char * V_207 ,
const char * V_246 )
{
struct V_243 V_247 ;
struct V_242 * V_248 ;
char * V_49 = NULL ;
memcpy ( & V_247 , V_244 , sizeof( V_247 ) ) ;
V_247 . V_249 = 0 ;
if ( ! V_207 )
V_207 = V_247 . V_49 ;
if ( V_246 ) {
V_49 = F_176 ( V_37 , L_84 , V_246 , V_207 ) ;
if ( ! V_49 )
return NULL ;
V_247 . V_49 = V_49 ;
} else {
V_247 . V_49 = V_207 ;
}
V_248 = F_177 ( & V_247 , V_245 ) ;
F_16 ( V_49 ) ;
return V_248 ;
}
static int F_178 ( struct V_78 * V_47 , struct V_26 * V_27 ,
const struct V_243 * V_152 , int V_153 ,
const char * V_246 , void * V_245 )
{
int V_74 , V_3 ;
for ( V_3 = 0 ; V_3 < V_153 ; V_3 ++ ) {
const struct V_243 * V_250 = & V_152 [ V_3 ] ;
V_74 = F_179 ( V_47 , F_175 ( V_250 , V_245 ,
V_250 -> V_49 , V_246 ) ) ;
if ( V_74 < 0 ) {
F_50 ( V_27 , L_85 ,
V_250 -> V_49 , V_74 ) ;
return V_74 ;
}
}
return 0 ;
}
struct V_242 * F_180 ( struct V_60 * V_251 ,
const char * V_49 )
{
struct V_78 * V_47 = V_251 -> V_78 ;
struct V_242 * V_252 ;
if ( F_181 ( ! V_49 ) )
return NULL ;
F_34 (kctl, &card->controls, list)
if ( ! strncmp ( V_252 -> V_253 . V_49 , V_49 , sizeof( V_252 -> V_253 . V_49 ) ) )
return V_252 ;
return NULL ;
}
int F_89 ( struct V_4 * V_5 ,
const struct V_243 * V_152 , int V_153 )
{
struct V_78 * V_47 = V_5 -> V_47 -> V_78 ;
return F_178 ( V_47 , V_5 -> V_27 , V_152 , V_153 ,
V_5 -> V_143 , V_5 ) ;
}
int F_93 ( struct V_55 * V_56 ,
const struct V_243 * V_152 , int V_153 )
{
struct V_78 * V_47 = V_56 -> V_47 -> V_78 ;
return F_178 ( V_47 , V_56 -> V_27 , V_152 , V_153 ,
NULL , V_56 ) ;
}
int F_128 ( struct V_60 * V_251 ,
const struct V_243 * V_152 , int V_153 )
{
struct V_78 * V_47 = V_251 -> V_78 ;
return F_178 ( V_47 , V_251 -> V_27 , V_152 , V_153 ,
NULL , V_251 ) ;
}
int F_182 ( struct V_58 * V_59 ,
const struct V_243 * V_152 , int V_153 )
{
struct V_78 * V_47 = V_59 -> V_47 -> V_78 ;
return F_178 ( V_47 , V_59 -> V_27 , V_152 , V_153 ,
NULL , V_59 ) ;
}
int F_183 ( struct V_242 * V_248 ,
struct V_254 * V_255 )
{
struct V_256 * V_257 = (struct V_256 * ) V_248 -> V_258 ;
V_255 -> type = V_259 ;
V_255 -> V_18 = V_257 -> V_260 == V_257 -> V_261 ? 1 : 2 ;
V_255 -> V_42 . V_262 . V_263 = V_257 -> V_264 ;
if ( V_255 -> V_42 . V_262 . V_265 > V_257 -> V_264 - 1 )
V_255 -> V_42 . V_262 . V_265 = V_257 -> V_264 - 1 ;
F_184 ( V_255 -> V_42 . V_262 . V_49 ,
V_257 -> V_266 [ V_255 -> V_42 . V_262 . V_265 ] ,
sizeof( V_255 -> V_42 . V_262 . V_49 ) ) ;
return 0 ;
}
int F_185 ( struct V_242 * V_248 ,
struct V_267 * V_268 )
{
struct V_4 * V_5 = F_186 ( V_248 ) ;
struct V_256 * V_257 = (struct V_256 * ) V_248 -> V_258 ;
unsigned int V_1 ;
V_1 = F_4 ( V_5 , V_257 -> V_6 ) ;
V_268 -> V_42 . V_262 . V_265 [ 0 ]
= ( V_1 >> V_257 -> V_260 ) & V_257 -> V_238 ;
if ( V_257 -> V_260 != V_257 -> V_261 )
V_268 -> V_42 . V_262 . V_265 [ 1 ] =
( V_1 >> V_257 -> V_261 ) & V_257 -> V_238 ;
return 0 ;
}
int F_187 ( struct V_242 * V_248 ,
struct V_267 * V_268 )
{
struct V_4 * V_5 = F_186 ( V_248 ) ;
struct V_256 * V_257 = (struct V_256 * ) V_248 -> V_258 ;
unsigned int V_1 ;
unsigned int V_238 ;
if ( V_268 -> V_42 . V_262 . V_265 [ 0 ] > V_257 -> V_264 - 1 )
return - V_17 ;
V_1 = V_268 -> V_42 . V_262 . V_265 [ 0 ] << V_257 -> V_260 ;
V_238 = V_257 -> V_238 << V_257 -> V_260 ;
if ( V_257 -> V_260 != V_257 -> V_261 ) {
if ( V_268 -> V_42 . V_262 . V_265 [ 1 ] > V_257 -> V_264 - 1 )
return - V_17 ;
V_1 |= V_268 -> V_42 . V_262 . V_265 [ 1 ] << V_257 -> V_261 ;
V_238 |= V_257 -> V_238 << V_257 -> V_261 ;
}
return F_173 ( V_5 , V_257 -> V_6 , V_238 , V_1 ) ;
}
int F_188 ( struct V_242 * V_248 ,
struct V_267 * V_268 )
{
struct V_4 * V_5 = F_186 ( V_248 ) ;
struct V_256 * V_257 = (struct V_256 * ) V_248 -> V_258 ;
unsigned int V_269 , V_1 , V_270 ;
V_269 = F_4 ( V_5 , V_257 -> V_6 ) ;
V_1 = ( V_269 >> V_257 -> V_260 ) & V_257 -> V_238 ;
for ( V_270 = 0 ; V_270 < V_257 -> V_264 ; V_270 ++ ) {
if ( V_1 == V_257 -> V_271 [ V_270 ] )
break;
}
V_268 -> V_42 . V_262 . V_265 [ 0 ] = V_270 ;
if ( V_257 -> V_260 != V_257 -> V_261 ) {
V_1 = ( V_269 >> V_257 -> V_261 ) & V_257 -> V_238 ;
for ( V_270 = 0 ; V_270 < V_257 -> V_264 ; V_270 ++ ) {
if ( V_1 == V_257 -> V_271 [ V_270 ] )
break;
}
V_268 -> V_42 . V_262 . V_265 [ 1 ] = V_270 ;
}
return 0 ;
}
int F_189 ( struct V_242 * V_248 ,
struct V_267 * V_268 )
{
struct V_4 * V_5 = F_186 ( V_248 ) ;
struct V_256 * V_257 = (struct V_256 * ) V_248 -> V_258 ;
unsigned int V_1 ;
unsigned int V_238 ;
if ( V_268 -> V_42 . V_262 . V_265 [ 0 ] > V_257 -> V_264 - 1 )
return - V_17 ;
V_1 = V_257 -> V_271 [ V_268 -> V_42 . V_262 . V_265 [ 0 ] ] << V_257 -> V_260 ;
V_238 = V_257 -> V_238 << V_257 -> V_260 ;
if ( V_257 -> V_260 != V_257 -> V_261 ) {
if ( V_268 -> V_42 . V_262 . V_265 [ 1 ] > V_257 -> V_264 - 1 )
return - V_17 ;
V_1 |= V_257 -> V_271 [ V_268 -> V_42 . V_262 . V_265 [ 1 ] ] << V_257 -> V_261 ;
V_238 |= V_257 -> V_238 << V_257 -> V_261 ;
}
return F_173 ( V_5 , V_257 -> V_6 , V_238 , V_1 ) ;
}
int F_190 ( struct V_242 * V_248 ,
struct V_254 * V_255 )
{
struct V_272 * V_273 =
(struct V_272 * ) V_248 -> V_258 ;
int V_274 ;
if ( ! V_273 -> V_274 )
V_273 -> V_274 = V_273 -> V_264 ;
V_274 = V_273 -> V_274 ;
if ( V_274 == 1 && ! strstr ( V_248 -> V_253 . V_49 , L_86 ) )
V_255 -> type = V_275 ;
else
V_255 -> type = V_276 ;
V_255 -> V_18 = F_191 ( V_273 ) ? 2 : 1 ;
V_255 -> V_42 . integer . F_7 = 0 ;
V_255 -> V_42 . integer . V_264 = V_274 ;
return 0 ;
}
int F_192 ( struct V_242 * V_248 ,
struct V_267 * V_268 )
{
struct V_272 * V_273 =
(struct V_272 * ) V_248 -> V_258 ;
struct V_4 * V_5 = F_186 ( V_248 ) ;
unsigned int V_6 = V_273 -> V_6 ;
unsigned int V_277 = V_273 -> V_278 ;
unsigned int V_279 = V_273 -> V_279 ;
unsigned int V_280 = V_273 -> V_280 ;
int V_264 = V_273 -> V_264 ;
unsigned int V_238 = ( 1 << F_193 ( V_264 ) ) - 1 ;
unsigned int V_281 = V_273 -> V_281 ;
V_268 -> V_42 . integer . V_42 [ 0 ] =
( F_4 ( V_5 , V_6 ) >> V_279 ) & V_238 ;
if ( V_281 )
V_268 -> V_42 . integer . V_42 [ 0 ] =
V_264 - V_268 -> V_42 . integer . V_42 [ 0 ] ;
if ( F_191 ( V_273 ) ) {
if ( V_6 == V_277 )
V_268 -> V_42 . integer . V_42 [ 1 ] =
( F_4 ( V_5 , V_6 ) >> V_280 ) & V_238 ;
else
V_268 -> V_42 . integer . V_42 [ 1 ] =
( F_4 ( V_5 , V_277 ) >> V_279 ) & V_238 ;
if ( V_281 )
V_268 -> V_42 . integer . V_42 [ 1 ] =
V_264 - V_268 -> V_42 . integer . V_42 [ 1 ] ;
}
return 0 ;
}
int F_194 ( struct V_242 * V_248 ,
struct V_267 * V_268 )
{
struct V_272 * V_273 =
(struct V_272 * ) V_248 -> V_258 ;
struct V_4 * V_5 = F_186 ( V_248 ) ;
unsigned int V_6 = V_273 -> V_6 ;
unsigned int V_277 = V_273 -> V_278 ;
unsigned int V_279 = V_273 -> V_279 ;
unsigned int V_280 = V_273 -> V_280 ;
int V_264 = V_273 -> V_264 ;
unsigned int V_238 = ( 1 << F_193 ( V_264 ) ) - 1 ;
unsigned int V_281 = V_273 -> V_281 ;
int V_74 ;
bool V_282 = 0 ;
unsigned int V_283 = 0 ;
unsigned int V_1 , V_284 ;
V_1 = ( V_268 -> V_42 . integer . V_42 [ 0 ] & V_238 ) ;
if ( V_281 )
V_1 = V_264 - V_1 ;
V_284 = V_238 << V_279 ;
V_1 = V_1 << V_279 ;
if ( F_191 ( V_273 ) ) {
V_283 = ( V_268 -> V_42 . integer . V_42 [ 1 ] & V_238 ) ;
if ( V_281 )
V_283 = V_264 - V_283 ;
if ( V_6 == V_277 ) {
V_284 |= V_238 << V_280 ;
V_1 |= V_283 << V_280 ;
} else {
V_283 = V_283 << V_279 ;
V_282 = 1 ;
}
}
V_74 = F_173 ( V_5 , V_6 , V_284 , V_1 ) ;
if ( V_74 < 0 )
return V_74 ;
if ( V_282 )
V_74 = F_173 ( V_5 , V_277 , V_284 , V_283 ) ;
return V_74 ;
}
int F_195 ( struct V_242 * V_248 ,
struct V_267 * V_268 )
{
struct V_4 * V_5 = F_186 ( V_248 ) ;
struct V_272 * V_273 =
(struct V_272 * ) V_248 -> V_258 ;
unsigned int V_6 = V_273 -> V_6 ;
unsigned int V_277 = V_273 -> V_278 ;
unsigned int V_279 = V_273 -> V_279 ;
unsigned int V_280 = V_273 -> V_280 ;
int V_264 = V_273 -> V_264 ;
int F_7 = V_273 -> F_7 ;
int V_238 = ( 1 << ( F_193 ( F_7 + V_264 ) - 1 ) ) - 1 ;
V_268 -> V_42 . integer . V_42 [ 0 ] =
( ( F_4 ( V_5 , V_6 ) >> V_279 ) - F_7 ) & V_238 ;
if ( F_191 ( V_273 ) )
V_268 -> V_42 . integer . V_42 [ 1 ] =
( ( F_4 ( V_5 , V_277 ) >> V_280 ) - F_7 ) & V_238 ;
return 0 ;
}
int F_196 ( struct V_242 * V_248 ,
struct V_267 * V_268 )
{
struct V_4 * V_5 = F_186 ( V_248 ) ;
struct V_272 * V_273 =
(struct V_272 * ) V_248 -> V_258 ;
unsigned int V_6 = V_273 -> V_6 ;
unsigned int V_277 = V_273 -> V_278 ;
unsigned int V_279 = V_273 -> V_279 ;
unsigned int V_280 = V_273 -> V_280 ;
int V_264 = V_273 -> V_264 ;
int F_7 = V_273 -> F_7 ;
int V_238 = ( 1 << ( F_193 ( F_7 + V_264 ) - 1 ) ) - 1 ;
int V_74 = 0 ;
unsigned short V_1 , V_284 , V_283 = 0 ;
V_284 = V_238 << V_279 ;
V_1 = ( V_268 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & V_238 ;
V_1 = V_1 << V_279 ;
V_74 = F_173 ( V_5 , V_6 , V_284 , V_1 ) ;
if ( V_74 < 0 )
return V_74 ;
if ( F_191 ( V_273 ) ) {
V_284 = V_238 << V_280 ;
V_283 = ( V_268 -> V_42 . integer . V_42 [ 1 ] + F_7 ) & V_238 ;
V_283 = V_283 << V_280 ;
if ( F_173 ( V_5 , V_277 , V_284 , V_283 ) )
return V_74 ;
}
return 0 ;
}
int F_197 ( struct V_242 * V_248 ,
struct V_254 * V_255 )
{
struct V_272 * V_273 =
(struct V_272 * ) V_248 -> V_258 ;
int V_274 ;
int F_7 = V_273 -> F_7 ;
if ( ! V_273 -> V_274 )
V_273 -> V_274 = V_273 -> V_264 ;
V_274 = V_273 -> V_274 ;
V_255 -> type = V_276 ;
V_255 -> V_18 = 2 ;
V_255 -> V_42 . integer . F_7 = 0 ;
V_255 -> V_42 . integer . V_264 = V_274 - F_7 ;
return 0 ;
}
int F_198 ( struct V_242 * V_248 ,
struct V_267 * V_268 )
{
struct V_272 * V_273 =
(struct V_272 * ) V_248 -> V_258 ;
struct V_4 * V_5 = F_186 ( V_248 ) ;
unsigned int V_6 = V_273 -> V_6 ;
int F_7 = V_273 -> F_7 ;
int V_1 = F_4 ( V_5 , V_6 ) ;
V_268 -> V_42 . integer . V_42 [ 0 ] =
( ( signed char ) ( V_1 & 0xff ) ) - F_7 ;
V_268 -> V_42 . integer . V_42 [ 1 ] =
( ( signed char ) ( ( V_1 >> 8 ) & 0xff ) ) - F_7 ;
return 0 ;
}
int F_199 ( struct V_242 * V_248 ,
struct V_267 * V_268 )
{
struct V_272 * V_273 =
(struct V_272 * ) V_248 -> V_258 ;
struct V_4 * V_5 = F_186 ( V_248 ) ;
unsigned int V_6 = V_273 -> V_6 ;
int F_7 = V_273 -> F_7 ;
unsigned int V_1 ;
V_1 = ( V_268 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & 0xff ;
V_1 |= ( ( V_268 -> V_42 . integer . V_42 [ 1 ] + F_7 ) & 0xff ) << 8 ;
return F_173 ( V_5 , V_6 , 0xffff , V_1 ) ;
}
int F_200 ( struct V_242 * V_248 ,
struct V_254 * V_255 )
{
struct V_272 * V_273 =
(struct V_272 * ) V_248 -> V_258 ;
int V_274 ;
int F_7 = V_273 -> F_7 ;
if ( ! V_273 -> V_274 )
V_273 -> V_274 = V_273 -> V_264 ;
V_274 = V_273 -> V_274 ;
V_255 -> type = V_276 ;
V_255 -> V_18 = F_191 ( V_273 ) ? 2 : 1 ;
V_255 -> V_42 . integer . F_7 = 0 ;
V_255 -> V_42 . integer . V_264 = V_274 - F_7 ;
return 0 ;
}
int F_201 ( struct V_242 * V_248 ,
struct V_267 * V_268 )
{
struct V_272 * V_273 =
(struct V_272 * ) V_248 -> V_258 ;
struct V_4 * V_5 = F_186 ( V_248 ) ;
unsigned int V_6 = V_273 -> V_6 ;
unsigned int V_278 = V_273 -> V_278 ;
unsigned int V_279 = V_273 -> V_279 ;
int F_7 = V_273 -> F_7 ;
int V_264 = V_273 -> V_264 ;
unsigned int V_238 = ( 1 << F_193 ( V_264 ) ) - 1 ;
unsigned int V_281 = V_273 -> V_281 ;
unsigned int V_1 , V_284 ;
int V_14 ;
V_1 = ( ( V_268 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & V_238 ) ;
if ( V_281 )
V_1 = V_264 - V_1 ;
V_284 = V_238 << V_279 ;
V_1 = V_1 << V_279 ;
V_14 = F_173 ( V_5 , V_6 , V_284 , V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( F_191 ( V_273 ) ) {
V_1 = ( ( V_268 -> V_42 . integer . V_42 [ 1 ] + F_7 ) & V_238 ) ;
if ( V_281 )
V_1 = V_264 - V_1 ;
V_284 = V_238 << V_279 ;
V_1 = V_1 << V_279 ;
V_14 = F_173 ( V_5 , V_278 , V_284 , V_1 ) ;
}
return V_14 ;
}
int F_202 ( struct V_242 * V_248 ,
struct V_267 * V_268 )
{
struct V_272 * V_273 =
(struct V_272 * ) V_248 -> V_258 ;
struct V_4 * V_5 = F_186 ( V_248 ) ;
unsigned int V_6 = V_273 -> V_6 ;
unsigned int V_278 = V_273 -> V_278 ;
unsigned int V_279 = V_273 -> V_279 ;
int F_7 = V_273 -> F_7 ;
int V_264 = V_273 -> V_264 ;
unsigned int V_238 = ( 1 << F_193 ( V_264 ) ) - 1 ;
unsigned int V_281 = V_273 -> V_281 ;
V_268 -> V_42 . integer . V_42 [ 0 ] =
( F_4 ( V_5 , V_6 ) >> V_279 ) & V_238 ;
if ( V_281 )
V_268 -> V_42 . integer . V_42 [ 0 ] =
V_264 - V_268 -> V_42 . integer . V_42 [ 0 ] ;
V_268 -> V_42 . integer . V_42 [ 0 ] =
V_268 -> V_42 . integer . V_42 [ 0 ] - F_7 ;
if ( F_191 ( V_273 ) ) {
V_268 -> V_42 . integer . V_42 [ 1 ] =
( F_4 ( V_5 , V_278 ) >> V_279 ) & V_238 ;
if ( V_281 )
V_268 -> V_42 . integer . V_42 [ 1 ] =
V_264 - V_268 -> V_42 . integer . V_42 [ 1 ] ;
V_268 -> V_42 . integer . V_42 [ 1 ] =
V_268 -> V_42 . integer . V_42 [ 1 ] - F_7 ;
}
return 0 ;
}
int F_203 ( struct V_4 * V_5 ,
const char * V_49 , int V_264 )
{
struct V_78 * V_47 = V_5 -> V_47 -> V_78 ;
struct V_242 * V_252 ;
struct V_272 * V_273 ;
int V_187 = 0 ;
int V_14 = - V_17 ;
if ( F_181 ( ! V_49 || V_264 <= 0 ) )
return - V_17 ;
F_34 (kctl, &card->controls, list) {
if ( ! strncmp ( V_252 -> V_253 . V_49 , V_49 , sizeof( V_252 -> V_253 . V_49 ) ) ) {
V_187 = 1 ;
break;
}
}
if ( V_187 ) {
V_273 = (struct V_272 * ) V_252 -> V_258 ;
if ( V_264 <= V_273 -> V_264 ) {
V_273 -> V_274 = V_264 ;
V_14 = 0 ;
}
}
return V_14 ;
}
int F_204 ( struct V_242 * V_248 ,
struct V_254 * V_255 )
{
struct V_4 * V_5 = F_186 ( V_248 ) ;
struct V_285 * V_180 = ( void * ) V_248 -> V_258 ;
V_255 -> type = V_286 ;
V_255 -> V_18 = V_180 -> V_287 * V_5 -> V_288 ;
return 0 ;
}
int F_205 ( struct V_242 * V_248 ,
struct V_267 * V_268 )
{
struct V_285 * V_180 = ( void * ) V_248 -> V_258 ;
struct V_4 * V_5 = F_186 ( V_248 ) ;
int V_14 ;
if ( V_5 -> V_107 )
V_14 = F_206 ( V_5 -> V_108 , V_180 -> V_289 ,
V_268 -> V_42 . V_290 . V_245 ,
V_180 -> V_287 * V_5 -> V_288 ) ;
else
V_14 = - V_17 ;
if ( V_14 == 0 && V_180 -> V_238 ) {
switch ( V_5 -> V_288 ) {
case 1 :
V_268 -> V_42 . V_290 . V_245 [ 0 ] &= ~ V_180 -> V_238 ;
break;
case 2 :
( ( V_291 * ) ( & V_268 -> V_42 . V_290 . V_245 ) ) [ 0 ]
&= F_207 ( ~ V_180 -> V_238 ) ;
break;
case 4 :
( ( V_292 * ) ( & V_268 -> V_42 . V_290 . V_245 ) ) [ 0 ]
&= F_208 ( ~ V_180 -> V_238 ) ;
break;
default:
return - V_17 ;
}
}
return V_14 ;
}
int F_209 ( struct V_242 * V_248 ,
struct V_267 * V_268 )
{
struct V_285 * V_180 = ( void * ) V_248 -> V_258 ;
struct V_4 * V_5 = F_186 ( V_248 ) ;
int V_14 , V_8 ;
unsigned int V_1 ;
void * V_245 ;
if ( ! V_5 -> V_107 )
return - V_17 ;
V_8 = V_180 -> V_287 * V_5 -> V_288 ;
V_245 = F_210 ( V_268 -> V_42 . V_290 . V_245 , V_8 , V_37 | V_293 ) ;
if ( ! V_245 )
return - V_38 ;
if ( V_180 -> V_238 ) {
V_14 = F_211 ( V_5 -> V_108 , V_180 -> V_289 , & V_1 ) ;
if ( V_14 != 0 )
goto V_172;
V_1 &= V_180 -> V_238 ;
switch ( V_5 -> V_288 ) {
case 1 :
( ( V_294 * ) V_245 ) [ 0 ] &= ~ V_180 -> V_238 ;
( ( V_294 * ) V_245 ) [ 0 ] |= V_1 ;
break;
case 2 :
( ( V_291 * ) V_245 ) [ 0 ] &= F_207 ( ~ V_180 -> V_238 ) ;
( ( V_291 * ) V_245 ) [ 0 ] |= F_207 ( V_1 ) ;
break;
case 4 :
( ( V_292 * ) V_245 ) [ 0 ] &= F_208 ( ~ V_180 -> V_238 ) ;
( ( V_292 * ) V_245 ) [ 0 ] |= F_208 ( V_1 ) ;
break;
default:
V_14 = - V_17 ;
goto V_172;
}
}
V_14 = F_212 ( V_5 -> V_108 , V_180 -> V_289 ,
V_245 , V_8 ) ;
V_172:
F_16 ( V_245 ) ;
return V_14 ;
}
int F_213 ( struct V_242 * V_248 ,
struct V_254 * V_255 )
{
struct V_295 * V_273 =
(struct V_295 * ) V_248 -> V_258 ;
V_255 -> type = V_276 ;
V_255 -> V_18 = 1 ;
V_255 -> V_42 . integer . F_7 = V_273 -> F_7 ;
V_255 -> V_42 . integer . V_264 = V_273 -> V_264 ;
return 0 ;
}
int F_214 ( struct V_242 * V_248 ,
struct V_267 * V_268 )
{
struct V_295 * V_273 =
(struct V_295 * ) V_248 -> V_258 ;
struct V_4 * V_5 = F_186 ( V_248 ) ;
unsigned int V_296 = V_273 -> V_296 ;
unsigned int V_297 = V_273 -> V_297 ;
unsigned int V_298 = V_5 -> V_10 -> V_13 * V_299 ;
unsigned int V_300 = ( 1 << V_298 ) - 1 ;
unsigned int V_281 = V_273 -> V_281 ;
unsigned long V_238 = ( 1UL << V_273 -> V_301 ) - 1 ;
long F_7 = V_273 -> F_7 ;
long V_264 = V_273 -> V_264 ;
long V_1 = 0 ;
unsigned long V_302 ;
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_297 ; V_3 ++ ) {
V_302 = F_4 ( V_5 , V_296 + V_3 ) & V_300 ;
V_1 |= V_302 << ( V_298 * ( V_297 - V_3 - 1 ) ) ;
}
V_1 &= V_238 ;
if ( F_7 < 0 && V_1 > V_264 )
V_1 |= ~ V_238 ;
if ( V_281 )
V_1 = V_264 - V_1 ;
V_268 -> V_42 . integer . V_42 [ 0 ] = V_1 ;
return 0 ;
}
int F_215 ( struct V_242 * V_248 ,
struct V_267 * V_268 )
{
struct V_295 * V_273 =
(struct V_295 * ) V_248 -> V_258 ;
struct V_4 * V_5 = F_186 ( V_248 ) ;
unsigned int V_296 = V_273 -> V_296 ;
unsigned int V_297 = V_273 -> V_297 ;
unsigned int V_298 = V_5 -> V_10 -> V_13 * V_299 ;
unsigned int V_300 = ( 1 << V_298 ) - 1 ;
unsigned int V_281 = V_273 -> V_281 ;
unsigned long V_238 = ( 1UL << V_273 -> V_301 ) - 1 ;
long V_264 = V_273 -> V_264 ;
long V_1 = V_268 -> V_42 . integer . V_42 [ 0 ] ;
unsigned int V_3 , V_302 , V_303 ;
int V_74 ;
if ( V_281 )
V_1 = V_264 - V_1 ;
V_1 &= V_238 ;
for ( V_3 = 0 ; V_3 < V_297 ; V_3 ++ ) {
V_302 = ( V_1 >> ( V_298 * ( V_297 - V_3 - 1 ) ) ) & V_300 ;
V_303 = ( V_238 >> ( V_298 * ( V_297 - V_3 - 1 ) ) ) & V_300 ;
V_74 = F_173 ( V_5 , V_296 + V_3 ,
V_303 , V_302 ) ;
if ( V_74 < 0 )
return V_74 ;
}
return 0 ;
}
int F_216 ( struct V_242 * V_248 ,
struct V_267 * V_268 )
{
struct V_272 * V_273 =
(struct V_272 * ) V_248 -> V_258 ;
struct V_4 * V_5 = F_186 ( V_248 ) ;
unsigned int V_6 = V_273 -> V_6 ;
unsigned int V_279 = V_273 -> V_279 ;
unsigned int V_238 = 1 << V_279 ;
unsigned int V_281 = V_273 -> V_281 != 0 ;
unsigned int V_1 = F_4 ( V_5 , V_6 ) & V_238 ;
if ( V_279 != 0 && V_1 != 0 )
V_1 = V_1 >> V_279 ;
V_268 -> V_42 . V_262 . V_265 [ 0 ] = V_1 ^ V_281 ;
return 0 ;
}
int F_217 ( struct V_242 * V_248 ,
struct V_267 * V_268 )
{
struct V_272 * V_273 =
(struct V_272 * ) V_248 -> V_258 ;
struct V_4 * V_5 = F_186 ( V_248 ) ;
unsigned int V_6 = V_273 -> V_6 ;
unsigned int V_279 = V_273 -> V_279 ;
unsigned int V_238 = 1 << V_279 ;
unsigned int V_281 = V_273 -> V_281 != 0 ;
unsigned int V_304 = V_268 -> V_42 . V_262 . V_265 [ 0 ] != 0 ;
unsigned int V_305 = ( V_304 ^ V_281 ) ? V_238 : 0 ;
unsigned int V_283 = ( V_304 ^ V_281 ) ? 0 : V_238 ;
int V_74 ;
V_74 = F_173 ( V_5 , V_6 , V_238 , V_305 ) ;
if ( V_74 < 0 )
return V_74 ;
V_74 = F_173 ( V_5 , V_6 , V_238 , V_283 ) ;
return V_74 ;
}
int F_218 ( struct V_58 * V_59 , int V_306 ,
unsigned int V_307 , int V_308 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_90 -> V_309 )
return V_59 -> V_10 -> V_90 -> V_309 ( V_59 , V_306 , V_307 , V_308 ) ;
else if ( V_59 -> V_5 && V_59 -> V_5 -> V_10 -> V_309 )
return V_59 -> V_5 -> V_10 -> V_309 ( V_59 -> V_5 , V_306 , 0 ,
V_307 , V_308 ) ;
else
return - V_199 ;
}
int F_219 ( struct V_4 * V_5 , int V_306 ,
int V_310 , unsigned int V_307 , int V_308 )
{
if ( V_5 -> V_10 -> V_309 )
return V_5 -> V_10 -> V_309 ( V_5 , V_306 , V_310 ,
V_307 , V_308 ) ;
else
return - V_199 ;
}
int F_220 ( struct V_58 * V_59 ,
int V_311 , int div )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_90 -> V_312 )
return V_59 -> V_10 -> V_90 -> V_312 ( V_59 , V_311 , div ) ;
else
return - V_17 ;
}
int F_221 ( struct V_58 * V_59 , int V_313 , int V_310 ,
unsigned int V_314 , unsigned int V_315 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_90 -> V_316 )
return V_59 -> V_10 -> V_90 -> V_316 ( V_59 , V_313 , V_310 ,
V_314 , V_315 ) ;
else if ( V_59 -> V_5 && V_59 -> V_5 -> V_10 -> V_316 )
return V_59 -> V_5 -> V_10 -> V_316 ( V_59 -> V_5 , V_313 , V_310 ,
V_314 , V_315 ) ;
else
return - V_17 ;
}
int F_222 ( struct V_4 * V_5 , int V_313 , int V_310 ,
unsigned int V_314 , unsigned int V_315 )
{
if ( V_5 -> V_10 -> V_316 )
return V_5 -> V_10 -> V_316 ( V_5 , V_313 , V_310 ,
V_314 , V_315 ) ;
else
return - V_17 ;
}
int F_223 ( struct V_58 * V_59 , unsigned int V_317 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_90 -> V_318 )
return V_59 -> V_10 -> V_90 -> V_318 ( V_59 , V_317 ) ;
else
return - V_17 ;
}
int F_129 ( struct V_58 * V_59 , unsigned int V_319 )
{
if ( V_59 -> V_10 == NULL )
return - V_17 ;
if ( V_59 -> V_10 -> V_90 -> V_320 == NULL )
return - V_199 ;
return V_59 -> V_10 -> V_90 -> V_320 ( V_59 , V_319 ) ;
}
int F_224 ( struct V_58 * V_59 ,
unsigned int V_321 , unsigned int V_322 , int V_323 , int V_324 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_90 -> V_325 )
return V_59 -> V_10 -> V_90 -> V_325 ( V_59 , V_321 , V_322 ,
V_323 , V_324 ) ;
else
return - V_17 ;
}
int F_225 ( struct V_58 * V_59 ,
unsigned int V_326 , unsigned int * V_327 ,
unsigned int V_328 , unsigned int * V_329 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_90 -> V_330 )
return V_59 -> V_10 -> V_90 -> V_330 ( V_59 , V_326 , V_327 ,
V_328 , V_329 ) ;
else
return - V_17 ;
}
int F_226 ( struct V_58 * V_59 , int V_331 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_90 -> V_332 )
return V_59 -> V_10 -> V_90 -> V_332 ( V_59 , V_331 ) ;
else
return - V_17 ;
}
int F_227 ( struct V_58 * V_59 , int V_333 ,
int V_334 )
{
if ( ! V_59 -> V_10 )
return - V_199 ;
if ( V_59 -> V_10 -> V_90 -> V_335 )
return V_59 -> V_10 -> V_90 -> V_335 ( V_59 , V_333 , V_334 ) ;
else if ( V_334 == V_101 &&
V_59 -> V_10 -> V_90 -> V_91 )
return V_59 -> V_10 -> V_90 -> V_91 ( V_59 , V_333 ) ;
else
return - V_199 ;
}
int F_139 ( struct V_60 * V_47 )
{
int V_3 , V_14 ;
if ( ! V_47 -> V_49 || ! V_47 -> V_27 )
return - V_17 ;
for ( V_3 = 0 ; V_3 < V_47 -> V_67 ; V_3 ++ ) {
struct V_118 * V_336 = & V_47 -> V_65 [ V_3 ] ;
if ( ! ! V_336 -> V_126 == ! ! V_336 -> V_125 ) {
F_50 ( V_47 -> V_27 ,
L_87 ,
V_336 -> V_49 ) ;
return - V_17 ;
}
if ( ! V_336 -> V_127 ) {
F_50 ( V_47 -> V_27 ,
L_88 ,
V_336 -> V_49 ) ;
return - V_17 ;
}
if ( V_336 -> V_119 && V_336 -> V_128 ) {
F_50 ( V_47 -> V_27 ,
L_89 ,
V_336 -> V_49 ) ;
return - V_17 ;
}
if ( V_336 -> V_122 && V_336 -> V_120 ) {
F_50 ( V_47 -> V_27 ,
L_90 ,
V_336 -> V_49 ) ;
return - V_17 ;
}
if ( ! V_336 -> V_123 &&
! ( V_336 -> V_122 || V_336 -> V_120 ) ) {
F_50 ( V_47 -> V_27 ,
L_91 ,
V_336 -> V_49 ) ;
return - V_17 ;
}
}
F_98 ( V_47 -> V_27 , V_47 ) ;
F_228 ( V_47 ) ;
F_38 ( V_47 ) ;
V_47 -> V_31 = F_229 ( V_47 -> V_27 ,
sizeof( struct V_30 ) *
( V_47 -> V_67 + V_47 -> V_193 ) ,
V_37 ) ;
if ( V_47 -> V_31 == NULL )
return - V_38 ;
V_47 -> V_85 = 0 ;
V_47 -> V_164 = & V_47 -> V_31 [ V_47 -> V_67 ] ;
for ( V_3 = 0 ; V_3 < V_47 -> V_67 ; V_3 ++ )
V_47 -> V_31 [ V_3 ] . V_65 = & V_47 -> V_65 [ V_3 ] ;
F_100 ( & V_47 -> V_156 ) ;
F_100 ( & V_47 -> V_337 ) ;
V_47 -> V_211 = 0 ;
F_99 ( & V_47 -> V_190 ) ;
F_99 ( & V_47 -> V_338 ) ;
V_14 = F_121 ( V_47 ) ;
if ( V_14 != 0 )
F_40 ( V_47 ) ;
for ( V_3 = 0 ; V_3 < V_47 -> V_85 ; V_3 ++ ) {
struct V_58 * V_94 = V_47 -> V_31 [ V_3 ] . V_94 ;
struct V_58 * V_86 = V_47 -> V_31 [ V_3 ] . V_86 ;
if ( ! V_86 -> V_116 )
F_64 ( V_86 -> V_27 ) ;
if ( ! V_94 -> V_116 )
F_64 ( V_94 -> V_27 ) ;
}
return V_14 ;
}
int F_142 ( struct V_60 * V_47 )
{
if ( V_47 -> V_211 )
F_140 ( V_47 ) ;
F_42 ( V_47 -> V_27 , L_92 , V_47 -> V_49 ) ;
return 0 ;
}
static char * F_230 ( struct V_26 * V_27 , int * V_253 )
{
char * V_187 , V_49 [ V_339 ] ;
int V_340 , V_341 ;
if ( F_71 ( V_27 ) == NULL )
return NULL ;
F_184 ( V_49 , F_71 ( V_27 ) , V_339 ) ;
V_187 = strstr ( V_49 , V_27 -> V_10 -> V_49 ) ;
if ( V_187 ) {
if ( sscanf ( & V_187 [ strlen ( V_27 -> V_10 -> V_49 ) ] , L_93 , V_253 ) == 1 ) {
if ( * V_253 == - 1 )
V_187 [ strlen ( V_27 -> V_10 -> V_49 ) ] = '\0' ;
}
} else {
if ( sscanf ( V_49 , L_94 , & V_340 , & V_341 ) == 2 ) {
char V_342 [ V_339 ] ;
* V_253 = ( ( V_340 & 0xffff ) << 16 ) + V_341 ;
snprintf ( V_342 , V_339 , L_95 , V_27 -> V_10 -> V_49 , V_49 ) ;
F_184 ( V_49 , V_342 , V_339 ) ;
} else
* V_253 = 0 ;
}
return F_231 ( V_49 , V_37 ) ;
}
static inline char * F_232 ( struct V_26 * V_27 ,
struct V_87 * V_343 )
{
if ( V_343 -> V_49 == NULL ) {
F_50 ( V_27 ,
L_96 ,
F_71 ( V_27 ) ) ;
return NULL ;
}
return F_231 ( V_343 -> V_49 , V_37 ) ;
}
static int F_233 ( struct V_26 * V_27 ,
struct V_87 * V_343 )
{
struct V_4 * V_5 ;
struct V_58 * V_59 ;
F_42 ( V_27 , L_97 , F_71 ( V_27 ) ) ;
V_59 = F_96 ( sizeof( struct V_58 ) , V_37 ) ;
if ( V_59 == NULL )
return - V_38 ;
V_59 -> V_49 = F_230 ( V_27 , & V_59 -> V_253 ) ;
if ( V_59 -> V_49 == NULL ) {
F_16 ( V_59 ) ;
return - V_38 ;
}
V_59 -> V_27 = V_27 ;
V_59 -> V_10 = V_343 ;
V_59 -> V_54 . V_27 = V_27 ;
if ( ! V_59 -> V_10 -> V_90 )
V_59 -> V_10 -> V_90 = & V_344 ;
F_152 ( & V_345 ) ;
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
F_91 ( & V_59 -> V_156 , & V_346 ) ;
F_135 ( & V_345 ) ;
F_42 ( V_27 , L_99 , V_59 -> V_49 ) ;
return 0 ;
}
static void F_234 ( struct V_26 * V_27 )
{
struct V_58 * V_59 ;
F_34 (dai, &dai_list, list) {
if ( V_27 == V_59 -> V_27 )
goto V_187;
}
return;
V_187:
F_152 ( & V_345 ) ;
F_74 ( & V_59 -> V_156 ) ;
F_135 ( & V_345 ) ;
F_42 ( V_27 , L_100 , V_59 -> V_49 ) ;
F_16 ( V_59 -> V_49 ) ;
F_16 ( V_59 ) ;
}
static int F_235 ( struct V_26 * V_27 ,
struct V_87 * V_343 , T_1 V_18 )
{
struct V_4 * V_5 ;
struct V_58 * V_59 ;
int V_3 , V_14 = 0 ;
F_42 ( V_27 , L_101 , F_71 ( V_27 ) , V_18 ) ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ ) {
V_59 = F_96 ( sizeof( struct V_58 ) , V_37 ) ;
if ( V_59 == NULL ) {
V_14 = - V_38 ;
goto V_74;
}
V_59 -> V_49 = F_232 ( V_27 , & V_343 [ V_3 ] ) ;
if ( V_59 -> V_49 == NULL ) {
F_16 ( V_59 ) ;
V_14 = - V_17 ;
goto V_74;
}
V_59 -> V_27 = V_27 ;
V_59 -> V_10 = & V_343 [ V_3 ] ;
if ( V_59 -> V_10 -> V_253 )
V_59 -> V_253 = V_59 -> V_10 -> V_253 ;
else
V_59 -> V_253 = V_3 ;
V_59 -> V_54 . V_27 = V_27 ;
if ( ! V_59 -> V_10 -> V_90 )
V_59 -> V_10 -> V_90 = & V_344 ;
F_152 ( & V_345 ) ;
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
F_91 ( & V_59 -> V_156 , & V_346 ) ;
F_135 ( & V_345 ) ;
F_42 ( V_59 -> V_27 , L_99 , V_59 -> V_49 ) ;
}
return 0 ;
V_74:
for ( V_3 -- ; V_3 >= 0 ; V_3 -- )
F_234 ( V_27 ) ;
return V_14 ;
}
static void F_236 ( struct V_26 * V_27 , T_1 V_18 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ )
F_234 ( V_27 ) ;
}
static int
F_237 ( struct V_26 * V_27 ,
struct V_347 * V_348 ,
const struct V_349 * V_350 ,
struct V_87 * V_343 ,
int V_351 , bool V_352 )
{
int V_14 ;
F_42 ( V_27 , L_102 , F_71 ( V_27 ) ) ;
if ( ! V_348 ) {
F_50 ( V_27 , L_103 ) ;
return - V_38 ;
}
V_348 -> V_49 = F_230 ( V_27 , & V_348 -> V_253 ) ;
if ( ! V_348 -> V_49 ) {
F_50 ( V_27 , L_104 ) ;
return - V_38 ;
}
V_348 -> V_27 = V_27 ;
V_348 -> V_10 = V_350 ;
V_348 -> V_343 = V_343 ;
V_348 -> V_351 = V_351 ;
if ( ( 1 == V_351 ) && V_352 )
V_14 = F_233 ( V_27 , V_343 ) ;
else
V_14 = F_235 ( V_27 , V_343 , V_351 ) ;
if ( V_14 < 0 ) {
F_50 ( V_27 , L_105 , V_14 ) ;
goto V_353;
}
F_152 ( & V_345 ) ;
F_91 ( & V_348 -> V_156 , & V_354 ) ;
F_135 ( & V_345 ) ;
F_42 ( V_348 -> V_27 , L_106 , V_348 -> V_49 ) ;
return V_14 ;
V_353:
F_16 ( V_348 -> V_49 ) ;
return V_14 ;
}
int F_238 ( struct V_26 * V_27 ,
const struct V_349 * V_350 ,
struct V_87 * V_343 ,
int V_351 )
{
struct V_347 * V_348 ;
V_348 = F_229 ( V_27 , sizeof( * V_348 ) , V_37 ) ;
if ( ! V_348 ) {
F_50 ( V_27 , L_107 ) ;
return - V_38 ;
}
return F_237 ( V_27 , V_348 , V_350 ,
V_343 , V_351 , true ) ;
}
void F_239 ( struct V_26 * V_27 )
{
struct V_347 * V_348 ;
F_34 (cmpnt, &component_list, list) {
if ( V_27 == V_348 -> V_27 )
goto V_187;
}
return;
V_187:
F_236 ( V_27 , V_348 -> V_351 ) ;
F_152 ( & V_345 ) ;
F_74 ( & V_348 -> V_156 ) ;
F_135 ( & V_345 ) ;
F_42 ( V_27 , L_108 , V_348 -> V_49 ) ;
F_16 ( V_348 -> V_49 ) ;
}
int F_240 ( struct V_26 * V_27 , struct V_55 * V_56 ,
const struct V_158 * V_355 )
{
V_56 -> V_49 = F_230 ( V_27 , & V_56 -> V_253 ) ;
if ( V_56 -> V_49 == NULL )
return - V_38 ;
V_56 -> V_27 = V_27 ;
V_56 -> V_10 = V_355 ;
V_56 -> V_54 . V_27 = V_27 ;
V_56 -> V_54 . V_56 = V_56 ;
V_56 -> V_54 . V_356 = V_355 -> V_356 ;
F_99 ( & V_56 -> V_190 ) ;
F_152 ( & V_345 ) ;
F_91 ( & V_56 -> V_156 , & V_357 ) ;
F_135 ( & V_345 ) ;
F_42 ( V_27 , L_109 , V_56 -> V_49 ) ;
return 0 ;
}
int F_241 ( struct V_26 * V_27 ,
const struct V_158 * V_355 )
{
struct V_55 * V_56 ;
int V_14 ;
F_42 ( V_27 , L_110 , F_71 ( V_27 ) ) ;
V_56 = F_96 ( sizeof( struct V_55 ) , V_37 ) ;
if ( V_56 == NULL )
return - V_38 ;
V_14 = F_240 ( V_27 , V_56 , V_355 ) ;
if ( V_14 )
F_16 ( V_56 ) ;
return V_14 ;
}
void F_242 ( struct V_55 * V_56 )
{
F_152 ( & V_345 ) ;
F_74 ( & V_56 -> V_156 ) ;
F_135 ( & V_345 ) ;
F_42 ( V_56 -> V_27 , L_111 ,
V_56 -> V_49 ) ;
F_16 ( V_56 -> V_49 ) ;
}
struct V_55 * F_243 ( struct V_26 * V_27 )
{
struct V_55 * V_56 ;
F_34 (platform, &platform_list, list) {
if ( V_27 == V_56 -> V_27 )
return V_56 ;
}
return NULL ;
}
void F_244 ( struct V_26 * V_27 )
{
struct V_55 * V_56 ;
V_56 = F_243 ( V_27 ) ;
if ( ! V_56 )
return;
F_242 ( V_56 ) ;
F_16 ( V_56 ) ;
}
static void F_245 ( struct V_358 * V_66 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_130 ( V_359 ) ; V_3 ++ )
if ( V_66 -> V_360 & V_359 [ V_3 ] )
V_66 -> V_360 |= V_359 [ V_3 ] ;
}
int F_246 ( struct V_26 * V_27 ,
const struct V_144 * V_361 ,
struct V_87 * V_343 ,
int V_351 )
{
struct V_4 * V_5 ;
int V_14 , V_3 ;
F_42 ( V_27 , L_112 , F_71 ( V_27 ) ) ;
V_5 = F_96 ( sizeof( struct V_4 ) , V_37 ) ;
if ( V_5 == NULL )
return - V_38 ;
V_5 -> V_49 = F_230 ( V_27 , & V_5 -> V_253 ) ;
if ( V_5 -> V_49 == NULL ) {
V_14 = - V_38 ;
goto V_362;
}
V_5 -> V_150 = V_361 -> V_150 ;
V_5 -> V_217 = V_361 -> V_217 ;
V_5 -> V_214 = V_361 -> V_214 ;
V_5 -> V_215 = V_361 -> V_215 ;
V_5 -> V_216 = V_361 -> V_216 ;
V_5 -> V_363 = V_361 -> V_363 ;
V_5 -> V_54 . V_100 = V_106 ;
V_5 -> V_54 . V_27 = V_27 ;
V_5 -> V_54 . V_5 = V_5 ;
V_5 -> V_54 . V_364 = V_361 -> V_364 ;
V_5 -> V_54 . V_356 = V_361 -> V_356 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_10 = V_361 ;
V_5 -> V_351 = V_351 ;
F_99 ( & V_5 -> V_190 ) ;
for ( V_3 = 0 ; V_3 < V_351 ; V_3 ++ ) {
F_245 ( & V_343 [ V_3 ] . V_365 ) ;
F_245 ( & V_343 [ V_3 ] . V_366 ) ;
}
F_152 ( & V_345 ) ;
F_91 ( & V_5 -> V_156 , & V_367 ) ;
F_135 ( & V_345 ) ;
V_14 = F_237 ( V_27 , & V_5 -> V_368 ,
& V_361 -> V_369 ,
V_343 , V_351 , false ) ;
if ( V_14 < 0 ) {
F_50 ( V_5 -> V_27 , L_113 , V_14 ) ;
goto V_370;
}
F_42 ( V_5 -> V_27 , L_114 , V_5 -> V_49 ) ;
return 0 ;
V_370:
F_152 ( & V_345 ) ;
F_74 ( & V_5 -> V_156 ) ;
F_135 ( & V_345 ) ;
F_16 ( V_5 -> V_49 ) ;
V_362:
F_16 ( V_5 ) ;
return V_14 ;
}
void F_247 ( struct V_26 * V_27 )
{
struct V_4 * V_5 ;
F_34 (codec, &codec_list, list) {
if ( V_27 == V_5 -> V_27 )
goto V_187;
}
return;
V_187:
F_239 ( V_27 ) ;
F_152 ( & V_345 ) ;
F_74 ( & V_5 -> V_156 ) ;
F_135 ( & V_345 ) ;
F_42 ( V_5 -> V_27 , L_115 , V_5 -> V_49 ) ;
F_248 ( V_5 ) ;
F_16 ( V_5 -> V_49 ) ;
F_16 ( V_5 ) ;
}
int F_249 ( struct V_60 * V_47 ,
const char * V_371 )
{
struct V_372 * V_373 = V_47 -> V_27 -> V_121 ;
int V_14 ;
V_14 = F_250 ( V_373 , V_371 , 0 , & V_47 -> V_49 ) ;
if ( V_14 < 0 && V_14 != - V_17 ) {
F_50 ( V_47 -> V_27 ,
L_116 ,
V_371 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
int F_251 ( struct V_60 * V_47 ,
const char * V_371 )
{
struct V_372 * V_373 = V_47 -> V_27 -> V_121 ;
int V_374 ;
struct V_375 * V_376 ;
int V_3 , V_14 ;
V_374 = F_252 ( V_373 , V_371 ) ;
if ( V_374 < 0 || V_374 & 1 ) {
F_50 ( V_47 -> V_27 ,
L_117 ,
V_371 ) ;
return - V_17 ;
}
V_374 /= 2 ;
if ( ! V_374 ) {
F_50 ( V_47 -> V_27 , L_118 ,
V_371 ) ;
return - V_17 ;
}
V_376 = F_229 ( V_47 -> V_27 , V_374 * sizeof( * V_376 ) ,
V_37 ) ;
if ( ! V_376 ) {
F_50 ( V_47 -> V_27 ,
L_119 ) ;
return - V_17 ;
}
for ( V_3 = 0 ; V_3 < V_374 ; V_3 ++ ) {
V_14 = F_250 ( V_373 , V_371 ,
2 * V_3 , & V_376 [ V_3 ] . V_377 ) ;
if ( V_14 ) {
F_50 ( V_47 -> V_27 ,
L_120 ,
V_371 , 2 * V_3 , V_14 ) ;
return - V_17 ;
}
V_14 = F_250 ( V_373 , V_371 ,
( 2 * V_3 ) + 1 , & V_376 [ V_3 ] . V_310 ) ;
if ( V_14 ) {
F_50 ( V_47 -> V_27 ,
L_120 ,
V_371 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_17 ;
}
}
V_47 -> V_155 = V_374 ;
V_47 -> V_154 = V_376 ;
return 0 ;
}
unsigned int F_253 ( struct V_372 * V_373 ,
const char * V_246 )
{
int V_14 , V_3 ;
char V_378 [ 128 ] ;
unsigned int V_379 = 0 ;
int V_380 , V_381 ;
const char * V_382 ;
struct {
char * V_49 ;
unsigned int V_1 ;
} V_383 [] = {
{ L_121 , V_384 } ,
{ L_122 , V_385 } ,
{ L_123 , V_386 } ,
{ L_124 , V_387 } ,
{ L_125 , V_388 } ,
{ L_126 , V_389 } ,
{ L_127 , V_390 } ,
{ L_128 , V_391 } ,
{ L_129 , V_392 } ,
} ;
if ( ! V_246 )
V_246 = L_130 ;
snprintf ( V_378 , sizeof( V_378 ) , L_131 , V_246 ) ;
V_14 = F_254 ( V_373 , V_378 , & V_382 ) ;
if ( V_14 == 0 ) {
for ( V_3 = 0 ; V_3 < F_130 ( V_383 ) ; V_3 ++ ) {
if ( strcmp ( V_382 , V_383 [ V_3 ] . V_49 ) == 0 ) {
V_379 |= V_383 [ V_3 ] . V_1 ;
break;
}
}
}
snprintf ( V_378 , sizeof( V_378 ) , L_132 , V_246 ) ;
if ( F_255 ( V_373 , V_378 , NULL ) )
V_379 |= V_393 ;
else
V_379 |= V_394 ;
snprintf ( V_378 , sizeof( V_378 ) , L_133 , V_246 ) ;
V_380 = ! ! F_255 ( V_373 , V_378 , NULL ) ;
snprintf ( V_378 , sizeof( V_378 ) , L_134 , V_246 ) ;
V_381 = ! ! F_255 ( V_373 , V_378 , NULL ) ;
switch ( ( V_380 << 4 ) + V_381 ) {
case 0x11 :
V_379 |= V_395 ;
break;
case 0x10 :
V_379 |= V_396 ;
break;
case 0x01 :
V_379 |= V_397 ;
break;
default:
break;
}
snprintf ( V_378 , sizeof( V_378 ) , L_135 , V_246 ) ;
V_380 = ! ! F_255 ( V_373 , V_378 , NULL ) ;
snprintf ( V_378 , sizeof( V_378 ) , L_136 , V_246 ) ;
V_381 = ! ! F_255 ( V_373 , V_378 , NULL ) ;
switch ( ( V_380 << 4 ) + V_381 ) {
case 0x11 :
V_379 |= V_201 ;
break;
case 0x10 :
V_379 |= V_203 ;
break;
case 0x01 :
V_379 |= V_204 ;
break;
default:
V_379 |= V_202 ;
break;
}
return V_379 ;
}
int F_256 ( struct V_372 * V_121 ,
const char * * V_398 )
{
struct V_347 * V_19 ;
struct V_399 args ;
int V_14 ;
V_14 = F_257 ( V_121 , L_137 ,
L_138 , 0 , & args ) ;
if ( V_14 )
return V_14 ;
V_14 = - V_124 ;
F_152 ( & V_345 ) ;
F_34 (pos, &component_list, list) {
if ( V_19 -> V_27 -> V_121 != args . V_373 )
continue;
if ( V_19 -> V_10 -> V_400 ) {
V_14 = V_19 -> V_10 -> V_400 ( V_19 , & args , V_398 ) ;
} else {
int V_253 = - 1 ;
switch ( args . V_401 ) {
case 0 :
V_253 = 0 ;
break;
case 1 :
V_253 = args . args [ 0 ] ;
break;
default:
break;
}
if ( V_253 < 0 || V_253 >= V_19 -> V_351 ) {
V_14 = - V_17 ;
break;
}
V_14 = 0 ;
* V_398 = V_19 -> V_343 [ V_253 ] . V_49 ;
if ( ! * V_398 )
* V_398 = V_19 -> V_49 ;
}
break;
}
F_135 ( & V_345 ) ;
F_258 ( args . V_373 ) ;
return V_14 ;
}
static int T_5 F_259 ( void )
{
#ifdef F_105
V_61 = F_24 ( L_139 , NULL ) ;
if ( F_161 ( V_61 ) || ! V_61 ) {
F_260 ( L_140 ) ;
V_61 = NULL ;
}
if ( ! F_27 ( L_141 , 0444 , V_61 , NULL ,
& V_402 ) )
F_260 ( L_142 ) ;
if ( ! F_27 ( L_143 , 0444 , V_61 , NULL ,
& V_403 ) )
F_260 ( L_144 ) ;
if ( ! F_27 ( L_145 , 0444 , V_61 , NULL ,
& V_404 ) )
F_260 ( L_146 ) ;
#endif
F_261 () ;
return F_262 ( & V_405 ) ;
}
static void T_6 F_263 ( void )
{
F_264 () ;
#ifdef F_105
F_30 ( V_61 ) ;
#endif
F_265 ( & V_405 ) ;
}
