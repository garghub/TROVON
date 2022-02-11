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
struct V_30 * V_31 =
F_9 ( V_27 , struct V_30 , V_27 ) ;
return F_5 ( V_31 -> V_5 , V_7 , V_25 , 0 ) ;
}
static T_2 F_10 ( struct V_26 * V_27 ,
struct V_28 * V_29 , char * V_7 )
{
struct V_30 * V_31 =
F_9 ( V_27 , struct V_30 , V_27 ) ;
return sprintf ( V_7 , L_3 , V_31 -> V_32 ) ;
}
static T_2 F_11 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
const char * V_7 , T_1 V_18 )
{
struct V_30 * V_31 =
F_9 ( V_27 , struct V_30 , V_27 ) ;
int V_14 ;
V_14 = F_12 ( V_7 , 10 , & V_31 -> V_32 ) ;
if ( V_14 )
return V_14 ;
return V_18 ;
}
static int F_13 ( struct V_33 * V_33 , struct V_34 * V_34 )
{
V_34 -> V_35 = V_33 -> V_36 ;
return 0 ;
}
static T_2 F_14 ( struct V_34 * V_34 , char T_4 * V_37 ,
T_1 V_18 , T_3 * V_38 )
{
T_2 V_14 ;
struct V_4 * V_5 = V_34 -> V_35 ;
char * V_7 ;
if ( * V_38 < 0 || ! V_18 )
return - V_17 ;
V_7 = F_15 ( V_18 , V_39 ) ;
if ( ! V_7 )
return - V_40 ;
V_14 = F_5 ( V_5 , V_7 , V_18 , * V_38 ) ;
if ( V_14 >= 0 ) {
if ( F_16 ( V_37 , V_7 , V_14 ) ) {
F_17 ( V_7 ) ;
return - V_41 ;
}
* V_38 += V_14 ;
}
F_17 ( V_7 ) ;
return V_14 ;
}
static T_2 F_18 ( struct V_34 * V_34 ,
const char T_4 * V_37 , T_1 V_18 , T_3 * V_38 )
{
char V_7 [ 32 ] ;
T_1 V_42 ;
char * V_43 = V_7 ;
unsigned long V_6 , V_44 ;
struct V_4 * V_5 = V_34 -> V_35 ;
V_42 = F_7 ( V_18 , ( sizeof( V_7 ) - 1 ) ) ;
if ( F_19 ( V_7 , V_37 , V_42 ) )
return - V_41 ;
V_7 [ V_42 ] = 0 ;
while ( * V_43 == ' ' )
V_43 ++ ;
V_6 = F_20 ( V_43 , & V_43 , 16 ) ;
while ( * V_43 == ' ' )
V_43 ++ ;
if ( F_21 ( V_43 , 16 , & V_44 ) )
return - V_17 ;
F_22 ( V_45 ) ;
F_23 ( V_5 , V_6 , V_44 ) ;
return V_42 ;
}
static void F_24 ( struct V_4 * V_5 )
{
struct V_46 * V_47 = V_5 -> V_48 -> V_47 ;
V_5 -> V_49 = F_25 ( V_5 -> V_50 ,
V_47 ) ;
if ( ! V_5 -> V_49 ) {
F_26 ( V_51
L_4 ) ;
return;
}
F_27 ( L_5 , 0444 , V_5 -> V_49 ,
& V_5 -> V_52 ) ;
F_27 ( L_6 , 0444 , V_5 -> V_49 ,
& V_5 -> V_53 ) ;
V_5 -> V_54 = F_28 ( L_7 , 0644 ,
V_5 -> V_49 ,
V_5 , & V_55 ) ;
if ( ! V_5 -> V_54 )
F_26 ( V_51
L_8 ) ;
F_29 ( & V_5 -> V_56 , V_5 -> V_49 ) ;
}
static void F_30 ( struct V_4 * V_5 )
{
F_31 ( V_5 -> V_49 ) ;
}
static T_2 F_32 ( struct V_34 * V_34 , char T_4 * V_37 ,
T_1 V_18 , T_3 * V_38 )
{
char * V_7 = F_15 ( V_25 , V_39 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_4 * V_5 ;
if ( ! V_7 )
return - V_40 ;
F_33 (codec, &codec_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_25 - V_14 , L_9 ,
V_5 -> V_50 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_25 ) {
V_14 = V_25 ;
break;
}
}
if ( V_14 >= 0 )
V_14 = F_34 ( V_37 , V_18 , V_38 , V_7 , V_14 ) ;
F_17 ( V_7 ) ;
return V_14 ;
}
static T_2 F_35 ( struct V_34 * V_34 , char T_4 * V_37 ,
T_1 V_18 , T_3 * V_38 )
{
char * V_7 = F_15 ( V_25 , V_39 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_57 * V_58 ;
if ( ! V_7 )
return - V_40 ;
F_33 (dai, &dai_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_25 - V_14 , L_9 , V_58 -> V_50 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_25 ) {
V_14 = V_25 ;
break;
}
}
V_14 = F_34 ( V_37 , V_18 , V_38 , V_7 , V_14 ) ;
F_17 ( V_7 ) ;
return V_14 ;
}
static T_2 F_36 ( struct V_34 * V_34 ,
char T_4 * V_37 ,
T_1 V_18 , T_3 * V_38 )
{
char * V_7 = F_15 ( V_25 , V_39 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_59 * V_60 ;
if ( ! V_7 )
return - V_40 ;
F_33 (platform, &platform_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_25 - V_14 , L_9 ,
V_60 -> V_50 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_25 ) {
V_14 = V_25 ;
break;
}
}
V_14 = F_34 ( V_37 , V_18 , V_38 , V_7 , V_14 ) ;
F_17 ( V_7 ) ;
return V_14 ;
}
static void F_37 ( struct V_61 * V_48 )
{
V_48 -> V_47 = F_25 ( V_48 -> V_50 ,
V_62 ) ;
if ( ! V_48 -> V_47 ) {
F_38 ( V_48 -> V_27 ,
L_4 ) ;
return;
}
V_48 -> V_63 = F_39 ( L_10 , 0644 ,
V_48 -> V_47 ,
& V_48 -> V_64 ) ;
if ( ! V_48 -> V_63 )
F_38 ( V_48 -> V_27 ,
L_11 ) ;
}
static void F_40 ( struct V_61 * V_48 )
{
F_31 ( V_48 -> V_47 ) ;
}
static inline void F_24 ( struct V_4 * V_5 )
{
}
static inline void F_30 ( struct V_4 * V_5 )
{
}
static inline void F_37 ( struct V_61 * V_48 )
{
}
static inline void F_40 ( struct V_61 * V_48 )
{
}
static int F_41 ( struct V_4 * V_5 )
{
if ( V_5 -> V_65 -> V_27 . V_66 )
F_42 ( & V_5 -> V_65 -> V_27 ) ;
return 0 ;
}
static void F_43 ( struct V_26 * V_27 ) {}
static int F_44 ( struct V_4 * V_5 )
{
int V_67 ;
V_5 -> V_65 -> V_27 . V_66 = & V_68 ;
V_5 -> V_65 -> V_27 . V_69 = V_5 -> V_48 -> V_27 ;
V_5 -> V_65 -> V_27 . V_70 = F_43 ;
F_45 ( & V_5 -> V_65 -> V_27 , L_12 ,
V_5 -> V_48 -> V_71 -> V_72 , 0 , V_5 -> V_50 ) ;
V_67 = F_46 ( & V_5 -> V_65 -> V_27 ) ;
if ( V_67 < 0 ) {
F_47 ( V_73 L_13 ) ;
V_5 -> V_65 -> V_27 . V_66 = NULL ;
return V_67 ;
}
return 0 ;
}
int F_48 ( struct V_26 * V_27 )
{
struct V_61 * V_48 = F_49 ( V_27 ) ;
struct V_4 * V_5 ;
int V_3 ;
if ( F_50 ( & V_48 -> V_74 ) )
return 0 ;
F_51 ( V_48 -> V_71 ) ;
F_52 ( V_48 -> V_71 , V_75 ) ;
F_53 ( V_48 -> V_71 ) ;
F_54 ( V_48 -> V_71 , V_76 ) ;
for ( V_3 = 0 ; V_3 < V_48 -> V_77 ; V_3 ++ ) {
struct V_57 * V_58 = V_48 -> V_31 [ V_3 ] . V_78 ;
struct V_79 * V_80 = V_58 -> V_10 ;
if ( V_48 -> V_31 [ V_3 ] . V_81 -> V_82 )
continue;
if ( V_80 -> V_83 -> V_84 && V_58 -> V_85 )
V_80 -> V_83 -> V_84 ( V_58 , 1 ) ;
}
for ( V_3 = 0 ; V_3 < V_48 -> V_77 ; V_3 ++ ) {
if ( V_48 -> V_31 [ V_3 ] . V_81 -> V_82 )
continue;
F_55 ( V_48 -> V_31 [ V_3 ] . V_86 ) ;
}
if ( V_48 -> V_87 )
V_48 -> V_87 ( V_48 ) ;
for ( V_3 = 0 ; V_3 < V_48 -> V_77 ; V_3 ++ ) {
struct V_57 * V_88 = V_48 -> V_31 [ V_3 ] . V_88 ;
struct V_59 * V_60 = V_48 -> V_31 [ V_3 ] . V_60 ;
if ( V_48 -> V_31 [ V_3 ] . V_81 -> V_82 )
continue;
if ( V_88 -> V_10 -> V_89 && ! V_88 -> V_10 -> V_90 )
V_88 -> V_10 -> V_89 ( V_88 ) ;
if ( V_60 -> V_10 -> V_89 && ! V_60 -> V_91 ) {
V_60 -> V_10 -> V_89 ( V_88 ) ;
V_60 -> V_91 = 1 ;
}
}
for ( V_3 = 0 ; V_3 < V_48 -> V_77 ; V_3 ++ ) {
F_56 ( & V_48 -> V_31 [ V_3 ] . V_92 ) ;
V_48 -> V_31 [ V_3 ] . V_5 -> V_56 . V_93 = V_48 -> V_31 [ V_3 ] . V_5 -> V_56 . V_94 ;
}
for ( V_3 = 0 ; V_3 < V_48 -> V_77 ; V_3 ++ ) {
struct V_79 * V_10 = V_48 -> V_31 [ V_3 ] . V_78 -> V_10 ;
if ( V_48 -> V_31 [ V_3 ] . V_81 -> V_82 )
continue;
if ( V_10 -> V_95 . V_96 != NULL )
F_57 ( & V_48 -> V_31 [ V_3 ] , V_10 -> V_95 . V_96 ,
V_97 ) ;
if ( V_10 -> V_98 . V_96 != NULL )
F_57 ( & V_48 -> V_31 [ V_3 ] , V_10 -> V_98 . V_96 ,
V_97 ) ;
}
F_33 (codec, &card->codec_dev_list, card_list) {
if ( ! V_5 -> V_91 && V_5 -> V_10 -> V_89 ) {
switch ( V_5 -> V_56 . V_94 ) {
case V_99 :
case V_100 :
V_5 -> V_10 -> V_89 ( V_5 , V_101 ) ;
V_5 -> V_91 = 1 ;
V_5 -> V_52 = 1 ;
break;
default:
F_58 ( V_5 -> V_27 , L_14 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_48 -> V_77 ; V_3 ++ ) {
struct V_57 * V_88 = V_48 -> V_31 [ V_3 ] . V_88 ;
if ( V_48 -> V_31 [ V_3 ] . V_81 -> V_82 )
continue;
if ( V_88 -> V_10 -> V_89 && V_88 -> V_10 -> V_90 )
V_88 -> V_10 -> V_89 ( V_88 ) ;
}
if ( V_48 -> V_102 )
V_48 -> V_102 ( V_48 ) ;
return 0 ;
}
static void F_59 ( struct V_103 * V_104 )
{
struct V_61 * V_48 =
F_9 ( V_104 , struct V_61 , V_105 ) ;
struct V_4 * V_5 ;
int V_3 ;
F_58 ( V_48 -> V_27 , L_15 ) ;
F_54 ( V_48 -> V_71 , V_106 ) ;
if ( V_48 -> V_107 )
V_48 -> V_107 ( V_48 ) ;
for ( V_3 = 0 ; V_3 < V_48 -> V_77 ; V_3 ++ ) {
struct V_57 * V_88 = V_48 -> V_31 [ V_3 ] . V_88 ;
if ( V_48 -> V_31 [ V_3 ] . V_81 -> V_82 )
continue;
if ( V_88 -> V_10 -> V_108 && V_88 -> V_10 -> V_90 )
V_88 -> V_10 -> V_108 ( V_88 ) ;
}
F_33 (codec, &card->codec_dev_list, card_list) {
if ( V_5 -> V_10 -> V_108 && V_5 -> V_91 ) {
switch ( V_5 -> V_56 . V_94 ) {
case V_99 :
case V_100 :
V_5 -> V_10 -> V_108 ( V_5 ) ;
V_5 -> V_91 = 0 ;
break;
default:
F_58 ( V_5 -> V_27 , L_16 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_48 -> V_77 ; V_3 ++ ) {
struct V_79 * V_10 = V_48 -> V_31 [ V_3 ] . V_78 -> V_10 ;
if ( V_48 -> V_31 [ V_3 ] . V_81 -> V_82 )
continue;
if ( V_10 -> V_95 . V_96 != NULL )
F_57 ( & V_48 -> V_31 [ V_3 ] , V_10 -> V_95 . V_96 ,
V_109 ) ;
if ( V_10 -> V_98 . V_96 != NULL )
F_57 ( & V_48 -> V_31 [ V_3 ] , V_10 -> V_98 . V_96 ,
V_109 ) ;
}
for ( V_3 = 0 ; V_3 < V_48 -> V_77 ; V_3 ++ ) {
struct V_57 * V_58 = V_48 -> V_31 [ V_3 ] . V_78 ;
struct V_79 * V_80 = V_58 -> V_10 ;
if ( V_48 -> V_31 [ V_3 ] . V_81 -> V_82 )
continue;
if ( V_80 -> V_83 -> V_84 && V_58 -> V_85 )
V_80 -> V_83 -> V_84 ( V_58 , 0 ) ;
}
for ( V_3 = 0 ; V_3 < V_48 -> V_77 ; V_3 ++ ) {
struct V_57 * V_88 = V_48 -> V_31 [ V_3 ] . V_88 ;
struct V_59 * V_60 = V_48 -> V_31 [ V_3 ] . V_60 ;
if ( V_48 -> V_31 [ V_3 ] . V_81 -> V_82 )
continue;
if ( V_88 -> V_10 -> V_108 && ! V_88 -> V_10 -> V_90 )
V_88 -> V_10 -> V_108 ( V_88 ) ;
if ( V_60 -> V_10 -> V_108 && V_60 -> V_91 ) {
V_60 -> V_10 -> V_108 ( V_88 ) ;
V_60 -> V_91 = 0 ;
}
}
if ( V_48 -> V_110 )
V_48 -> V_110 ( V_48 ) ;
F_58 ( V_48 -> V_27 , L_17 ) ;
F_54 ( V_48 -> V_71 , V_75 ) ;
}
int F_60 ( struct V_26 * V_27 )
{
struct V_61 * V_48 = F_49 ( V_27 ) ;
int V_3 , V_90 = 0 ;
if ( F_50 ( & V_48 -> V_74 ) )
return 0 ;
for ( V_3 = 0 ; V_3 < V_48 -> V_77 ; V_3 ++ ) {
struct V_57 * V_88 = V_48 -> V_31 [ V_3 ] . V_88 ;
V_90 |= V_88 -> V_10 -> V_90 ;
}
if ( V_90 ) {
F_58 ( V_27 , L_18 ) ;
F_59 ( & V_48 -> V_105 ) ;
} else {
F_58 ( V_27 , L_19 ) ;
if ( ! F_61 ( & V_48 -> V_105 ) )
F_62 ( V_27 , L_20 ) ;
}
return 0 ;
}
static int F_63 ( struct V_61 * V_48 , int V_111 )
{
struct V_112 * V_81 = & V_48 -> V_81 [ V_111 ] ;
struct V_30 * V_31 = & V_48 -> V_31 [ V_111 ] ;
struct V_4 * V_5 ;
struct V_59 * V_60 ;
struct V_57 * V_78 , * V_88 ;
const char * V_113 ;
if ( V_31 -> V_114 )
return 1 ;
F_58 ( V_48 -> V_27 , L_21 , V_81 -> V_50 , V_111 ) ;
if ( V_31 -> V_88 ) {
goto V_115;
}
F_33 (cpu_dai, &dai_list, list) {
if ( ! strcmp ( V_88 -> V_50 , V_81 -> V_116 ) ) {
V_31 -> V_88 = V_88 ;
goto V_115;
}
}
F_58 ( V_48 -> V_27 , L_22 ,
V_81 -> V_116 ) ;
V_115:
if ( V_31 -> V_5 ) {
goto V_117;
}
F_33 (codec, &codec_list, list) {
if ( ! strcmp ( V_5 -> V_50 , V_81 -> V_118 ) ) {
V_31 -> V_5 = V_5 ;
F_33 (codec_dai, &dai_list, list) {
if ( V_5 -> V_27 == V_78 -> V_27 &&
! strcmp ( V_78 -> V_50 , V_81 -> V_119 ) ) {
V_31 -> V_78 = V_78 ;
goto V_117;
}
}
F_58 ( V_48 -> V_27 , L_23 ,
V_81 -> V_119 ) ;
goto V_117;
}
}
F_58 ( V_48 -> V_27 , L_24 ,
V_81 -> V_118 ) ;
V_117:
if ( V_31 -> V_60 )
goto V_120;
V_113 = V_81 -> V_113 ;
if ( ! V_113 )
V_113 = L_25 ;
F_33 (platform, &platform_list, list) {
if ( ! strcmp ( V_60 -> V_50 , V_113 ) ) {
V_31 -> V_60 = V_60 ;
goto V_120;
}
}
F_58 ( V_48 -> V_27 , L_26 ,
V_81 -> V_113 ) ;
return 0 ;
V_120:
if ( V_31 -> V_5 && V_31 -> V_78 && V_31 -> V_60 && V_31 -> V_88 ) {
V_31 -> V_114 = 1 ;
V_48 -> V_77 ++ ;
}
return 1 ;
}
static void F_64 ( struct V_4 * V_5 )
{
int V_67 ;
if ( V_5 -> V_10 -> remove ) {
V_67 = V_5 -> V_10 -> remove ( V_5 ) ;
if ( V_67 < 0 )
F_62 ( V_5 -> V_27 ,
L_27 ,
V_5 -> V_50 , V_67 ) ;
}
F_65 ( & V_5 -> V_56 ) ;
F_30 ( V_5 ) ;
V_5 -> V_121 = 0 ;
F_66 ( & V_5 -> V_122 ) ;
F_67 ( V_5 -> V_27 -> V_10 -> V_123 ) ;
}
static void F_68 ( struct V_61 * V_48 , int V_111 , int V_124 )
{
struct V_30 * V_31 = & V_48 -> V_31 [ V_111 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
struct V_59 * V_60 = V_31 -> V_60 ;
struct V_57 * V_78 = V_31 -> V_78 , * V_88 = V_31 -> V_88 ;
int V_67 ;
if ( V_31 -> V_125 ) {
F_69 ( & V_31 -> V_27 , & V_126 ) ;
F_69 ( & V_31 -> V_27 , & V_127 ) ;
F_42 ( & V_31 -> V_27 ) ;
V_31 -> V_125 = 0 ;
}
if ( V_78 && V_78 -> V_121 &&
V_78 -> V_10 -> V_128 == V_124 ) {
if ( V_78 -> V_10 -> remove ) {
V_67 = V_78 -> V_10 -> remove ( V_78 ) ;
if ( V_67 < 0 )
F_26 ( V_73 L_28 , V_78 -> V_50 ) ;
}
V_78 -> V_121 = 0 ;
F_66 ( & V_78 -> V_122 ) ;
}
if ( V_60 && V_60 -> V_121 &&
V_60 -> V_10 -> V_128 == V_124 ) {
if ( V_60 -> V_10 -> remove ) {
V_67 = V_60 -> V_10 -> remove ( V_60 ) ;
if ( V_67 < 0 )
F_26 ( V_73 L_28 , V_60 -> V_50 ) ;
}
V_60 -> V_121 = 0 ;
F_66 ( & V_60 -> V_122 ) ;
F_67 ( V_60 -> V_27 -> V_10 -> V_123 ) ;
}
if ( V_5 && V_5 -> V_121 &&
V_5 -> V_10 -> V_128 == V_124 )
F_64 ( V_5 ) ;
if ( V_88 && V_88 -> V_121 &&
V_88 -> V_10 -> V_128 == V_124 ) {
if ( V_88 -> V_10 -> remove ) {
V_67 = V_88 -> V_10 -> remove ( V_88 ) ;
if ( V_67 < 0 )
F_26 ( V_73 L_28 , V_88 -> V_50 ) ;
}
V_88 -> V_121 = 0 ;
F_66 ( & V_88 -> V_122 ) ;
F_67 ( V_88 -> V_27 -> V_10 -> V_123 ) ;
}
}
static void F_70 ( struct V_61 * V_48 )
{
int V_58 , V_124 ;
for ( V_124 = V_129 ; V_124 <= V_130 ;
V_124 ++ ) {
for ( V_58 = 0 ; V_58 < V_48 -> V_77 ; V_58 ++ )
F_68 ( V_48 , V_58 , V_124 ) ;
}
V_48 -> V_77 = 0 ;
}
static void F_71 ( struct V_61 * V_48 ,
struct V_4 * V_5 )
{
int V_3 ;
if ( V_48 -> V_131 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_48 -> V_132 ; V_3 ++ ) {
struct V_133 * V_134 = & V_48 -> V_131 [ V_3 ] ;
if ( V_134 -> V_135 && ! strcmp ( V_5 -> V_50 , V_134 -> V_135 ) ) {
V_5 -> V_136 = V_134 -> V_136 ;
break;
}
}
}
static int F_72 ( struct V_61 * V_48 ,
struct V_4 * V_5 )
{
int V_14 = 0 ;
const struct V_137 * V_10 = V_5 -> V_10 ;
V_5 -> V_48 = V_48 ;
V_5 -> V_56 . V_48 = V_48 ;
F_71 ( V_48 , V_5 ) ;
if ( ! F_73 ( V_5 -> V_27 -> V_10 -> V_123 ) )
return - V_138 ;
F_24 ( V_5 ) ;
if ( V_10 -> V_139 )
F_74 ( & V_5 -> V_56 , V_10 -> V_139 ,
V_10 -> V_140 ) ;
V_5 -> V_56 . V_141 = V_10 -> V_141 ;
if ( V_10 -> V_142 ) {
V_14 = V_10 -> V_142 ( V_5 ) ;
if ( V_14 < 0 ) {
F_62 ( V_5 -> V_27 ,
L_29 ,
V_5 -> V_50 , V_14 ) ;
goto V_143;
}
}
if ( V_10 -> V_144 )
F_75 ( V_5 , V_10 -> V_144 ,
V_10 -> V_145 ) ;
if ( V_10 -> V_146 )
F_76 ( & V_5 -> V_56 , V_10 -> V_146 ,
V_10 -> V_147 ) ;
V_5 -> V_121 = 1 ;
F_77 ( & V_5 -> V_122 , & V_48 -> V_74 ) ;
F_77 ( & V_5 -> V_56 . V_148 , & V_48 -> V_149 ) ;
return 0 ;
V_143:
F_30 ( V_5 ) ;
F_67 ( V_5 -> V_27 -> V_10 -> V_123 ) ;
return V_14 ;
}
static int F_78 ( struct V_61 * V_48 ,
struct V_59 * V_60 )
{
int V_14 = 0 ;
const struct V_150 * V_10 = V_60 -> V_10 ;
V_60 -> V_48 = V_48 ;
V_60 -> V_56 . V_48 = V_48 ;
if ( ! F_73 ( V_60 -> V_27 -> V_10 -> V_123 ) )
return - V_138 ;
if ( V_10 -> V_139 )
F_74 ( & V_60 -> V_56 ,
V_10 -> V_139 , V_10 -> V_140 ) ;
if ( V_10 -> V_142 ) {
V_14 = V_10 -> V_142 ( V_60 ) ;
if ( V_14 < 0 ) {
F_62 ( V_60 -> V_27 ,
L_30 ,
V_60 -> V_50 , V_14 ) ;
goto V_143;
}
}
if ( V_10 -> V_144 )
F_79 ( V_60 , V_10 -> V_144 ,
V_10 -> V_145 ) ;
if ( V_10 -> V_146 )
F_76 ( & V_60 -> V_56 , V_10 -> V_146 ,
V_10 -> V_147 ) ;
V_60 -> V_121 = 1 ;
F_77 ( & V_60 -> V_122 , & V_48 -> V_151 ) ;
F_77 ( & V_60 -> V_56 . V_148 , & V_48 -> V_149 ) ;
return 0 ;
V_143:
F_67 ( V_60 -> V_27 -> V_10 -> V_123 ) ;
return V_14 ;
}
static void F_80 ( struct V_26 * V_27 ) {}
static int F_81 ( struct V_61 * V_48 ,
struct V_4 * V_5 ,
int V_111 , int V_152 )
{
struct V_112 * V_81 = NULL ;
struct V_153 * V_154 = NULL ;
struct V_30 * V_31 ;
const char * V_155 , * V_50 ;
int V_14 = 0 ;
if ( ! V_152 ) {
V_81 = & V_48 -> V_81 [ V_111 ] ;
V_31 = & V_48 -> V_31 [ V_111 ] ;
V_50 = V_81 -> V_50 ;
} else {
V_154 = & V_48 -> V_154 [ V_111 ] ;
V_31 = & V_48 -> V_156 [ V_111 ] ;
V_50 = V_154 -> V_50 ;
}
V_31 -> V_48 = V_48 ;
F_82 ( & V_5 -> V_56 ) ;
V_155 = V_5 -> V_136 ;
V_5 -> V_136 = NULL ;
if ( ! V_152 && V_81 -> V_157 )
V_14 = V_81 -> V_157 ( V_31 ) ;
else if ( V_152 && V_154 -> V_157 )
V_14 = V_154 -> V_157 ( & V_5 -> V_56 ) ;
if ( V_14 < 0 ) {
F_62 ( V_48 -> V_27 , L_31 , V_50 , V_14 ) ;
return V_14 ;
}
V_5 -> V_136 = V_155 ;
V_31 -> V_5 = V_5 ;
V_31 -> V_27 . V_69 = V_48 -> V_27 ;
V_31 -> V_27 . V_70 = F_80 ;
V_31 -> V_27 . V_158 = V_50 ;
F_83 ( & V_31 -> V_159 ) ;
V_14 = F_46 ( & V_31 -> V_27 ) ;
if ( V_14 < 0 ) {
F_62 ( V_48 -> V_27 ,
L_32 , V_14 ) ;
return V_14 ;
}
V_31 -> V_125 = 1 ;
V_14 = F_84 ( & V_31 -> V_27 ) ;
if ( V_14 < 0 )
F_62 ( V_5 -> V_27 ,
L_33 ,
V_14 ) ;
V_14 = F_85 ( & V_31 -> V_27 , & V_127 ) ;
if ( V_14 < 0 )
F_62 ( V_5 -> V_27 ,
L_34 , V_14 ) ;
return 0 ;
}
static int F_86 ( struct V_61 * V_48 , int V_111 , int V_124 )
{
struct V_112 * V_81 = & V_48 -> V_81 [ V_111 ] ;
struct V_30 * V_31 = & V_48 -> V_31 [ V_111 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
struct V_59 * V_60 = V_31 -> V_60 ;
struct V_57 * V_78 = V_31 -> V_78 , * V_88 = V_31 -> V_88 ;
int V_14 ;
F_58 ( V_48 -> V_27 , L_35 ,
V_48 -> V_50 , V_111 , V_124 ) ;
V_78 -> V_5 = V_5 ;
V_88 -> V_60 = V_60 ;
V_78 -> V_48 = V_48 ;
V_88 -> V_48 = V_48 ;
V_31 -> V_32 = V_32 ;
if ( ! V_88 -> V_121 &&
V_88 -> V_10 -> V_160 == V_124 ) {
if ( ! F_73 ( V_88 -> V_27 -> V_10 -> V_123 ) )
return - V_138 ;
if ( V_88 -> V_10 -> V_142 ) {
V_14 = V_88 -> V_10 -> V_142 ( V_88 ) ;
if ( V_14 < 0 ) {
F_26 ( V_73 L_36 ,
V_88 -> V_50 ) ;
F_67 ( V_88 -> V_27 -> V_10 -> V_123 ) ;
return V_14 ;
}
}
V_88 -> V_121 = 1 ;
F_77 ( & V_88 -> V_122 , & V_48 -> V_161 ) ;
}
if ( ! V_5 -> V_121 &&
V_5 -> V_10 -> V_160 == V_124 ) {
V_14 = F_72 ( V_48 , V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_60 -> V_121 &&
V_60 -> V_10 -> V_160 == V_124 ) {
V_14 = F_78 ( V_48 , V_60 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_78 -> V_121 && V_78 -> V_10 -> V_160 == V_124 ) {
if ( V_78 -> V_10 -> V_142 ) {
V_14 = V_78 -> V_10 -> V_142 ( V_78 ) ;
if ( V_14 < 0 ) {
F_26 ( V_73 L_37 ,
V_78 -> V_50 ) ;
return V_14 ;
}
}
V_78 -> V_121 = 1 ;
F_77 ( & V_78 -> V_122 , & V_48 -> V_161 ) ;
}
if ( V_124 != V_130 )
return 0 ;
V_14 = F_81 ( V_48 , V_5 , V_111 , 0 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_85 ( & V_31 -> V_27 , & V_126 ) ;
if ( V_14 < 0 )
F_26 ( V_51 L_38 ) ;
V_14 = F_87 ( V_31 , V_111 ) ;
if ( V_14 < 0 ) {
F_26 ( V_73 L_39 , V_81 -> V_96 ) ;
return V_14 ;
}
if ( V_31 -> V_78 -> V_10 -> V_90 )
F_88 ( V_5 -> V_65 , V_31 -> V_88 -> V_162 ) ;
return 0 ;
}
static int F_89 ( struct V_30 * V_31 )
{
int V_14 ;
if ( V_31 -> V_78 -> V_10 -> V_90 && ! V_31 -> V_5 -> V_163 ) {
if ( ! V_31 -> V_5 -> V_164 )
return 0 ;
V_14 = F_44 ( V_31 -> V_5 ) ;
if ( V_14 < 0 ) {
F_26 ( V_73 L_40 ) ;
return V_14 ;
}
V_31 -> V_5 -> V_163 = 1 ;
}
return 0 ;
}
static void F_90 ( struct V_4 * V_5 )
{
if ( V_5 -> V_163 ) {
F_41 ( V_5 ) ;
V_5 -> V_163 = 0 ;
}
}
static int F_91 ( struct V_61 * V_48 , int V_111 )
{
struct V_153 * V_154 = & V_48 -> V_154 [ V_111 ] ;
struct V_4 * V_5 ;
int V_14 = - V_138 ;
F_33 (codec, &codec_list, list) {
if ( ! strcmp ( V_5 -> V_50 , V_154 -> V_118 ) ) {
if ( V_5 -> V_121 ) {
F_62 ( V_5 -> V_27 ,
L_41 ) ;
V_14 = - V_165 ;
goto V_120;
}
goto V_166;
}
}
F_62 ( V_48 -> V_27 , L_42 , V_154 -> V_118 ) ;
goto V_120;
V_166:
V_14 = F_72 ( V_48 , V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_81 ( V_48 , V_5 , V_111 , 1 ) ;
V_120:
return V_14 ;
}
static void F_92 ( struct V_61 * V_48 , int V_111 )
{
struct V_30 * V_31 = & V_48 -> V_156 [ V_111 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
if ( V_31 -> V_125 ) {
F_69 ( & V_31 -> V_27 , & V_127 ) ;
F_42 ( & V_31 -> V_27 ) ;
V_31 -> V_125 = 0 ;
}
if ( V_5 && V_5 -> V_121 )
F_64 ( V_5 ) ;
}
static int F_93 ( struct V_4 * V_5 ,
enum V_167 V_168 )
{
int V_14 ;
if ( V_5 -> V_169 )
return 0 ;
if ( V_168 && V_5 -> V_168 != V_168 )
V_5 -> V_168 = V_168 ;
V_14 = F_94 ( V_5 ) ;
if ( V_14 < 0 ) {
F_62 ( V_5 -> V_27 , L_43 ,
V_14 ) ;
return V_14 ;
}
V_5 -> V_169 = 1 ;
return 0 ;
}
static void F_95 ( struct V_61 * V_48 )
{
struct V_4 * V_5 ;
struct V_133 * V_131 ;
enum V_167 V_168 ;
struct V_112 * V_81 ;
int V_14 , V_3 , V_124 ;
F_96 ( & V_48 -> V_170 ) ;
if ( V_48 -> V_171 ) {
F_97 ( & V_48 -> V_170 ) ;
return;
}
for ( V_3 = 0 ; V_3 < V_48 -> V_172 ; V_3 ++ )
F_63 ( V_48 , V_3 ) ;
if ( V_48 -> V_77 != V_48 -> V_172 ) {
F_97 ( & V_48 -> V_170 ) ;
return;
}
F_33 (codec, &codec_list, list) {
if ( V_5 -> V_169 )
continue;
V_168 = 0 ;
for ( V_3 = 0 ; V_3 < V_48 -> V_132 ; ++ V_3 ) {
V_131 = & V_48 -> V_131 [ V_3 ] ;
if ( ! strcmp ( V_5 -> V_50 , V_131 -> V_135 ) ) {
V_168 = V_131 -> V_168 ;
if ( V_168 && V_168
!= V_5 -> V_168 )
break;
}
}
V_14 = F_93 ( V_5 , V_168 ) ;
if ( V_14 < 0 ) {
F_97 ( & V_48 -> V_170 ) ;
return;
}
}
V_14 = F_98 ( V_173 , V_174 ,
V_48 -> V_123 , 0 , & V_48 -> V_71 ) ;
if ( V_14 < 0 ) {
F_26 ( V_73 L_44 ,
V_48 -> V_50 ) ;
F_97 ( & V_48 -> V_170 ) ;
return;
}
V_48 -> V_71 -> V_27 = V_48 -> V_27 ;
V_48 -> V_56 . V_94 = V_100 ;
V_48 -> V_56 . V_27 = V_48 -> V_27 ;
V_48 -> V_56 . V_48 = V_48 ;
F_77 ( & V_48 -> V_56 . V_148 , & V_48 -> V_149 ) ;
#ifdef F_99
F_29 ( & V_48 -> V_56 , V_48 -> V_47 ) ;
#endif
#ifdef F_100
F_101 ( & V_48 -> V_105 , F_59 ) ;
#endif
if ( V_48 -> V_139 )
F_74 ( & V_48 -> V_56 , V_48 -> V_139 ,
V_48 -> V_140 ) ;
if ( V_48 -> V_142 ) {
V_14 = V_48 -> V_142 ( V_48 ) ;
if ( V_14 < 0 )
goto V_175;
}
for ( V_124 = V_129 ; V_124 <= V_130 ;
V_124 ++ ) {
for ( V_3 = 0 ; V_3 < V_48 -> V_172 ; V_3 ++ ) {
V_14 = F_86 ( V_48 , V_3 , V_124 ) ;
if ( V_14 < 0 ) {
F_102 ( L_45 ,
V_48 -> V_50 , V_14 ) ;
goto V_176;
}
}
}
for ( V_3 = 0 ; V_3 < V_48 -> V_177 ; V_3 ++ ) {
V_14 = F_91 ( V_48 , V_3 ) ;
if ( V_14 < 0 ) {
F_102 ( L_46 ,
V_48 -> V_50 , V_14 ) ;
goto V_178;
}
}
if ( V_48 -> V_144 )
F_75 ( F_103 ( & V_48 -> V_74 ,
struct V_4 ,
V_122 ) ,
V_48 -> V_144 ,
V_48 -> V_145 ) ;
if ( V_48 -> V_146 )
F_76 ( & V_48 -> V_56 , V_48 -> V_146 ,
V_48 -> V_147 ) ;
F_82 ( & V_48 -> V_56 ) ;
for ( V_3 = 0 ; V_3 < V_48 -> V_172 ; V_3 ++ ) {
V_81 = & V_48 -> V_81 [ V_3 ] ;
if ( V_81 -> V_179 ) {
V_14 = F_104 ( V_48 -> V_31 [ V_3 ] . V_78 ,
V_81 -> V_179 ) ;
if ( V_14 != 0 )
F_38 ( V_48 -> V_31 [ V_3 ] . V_78 -> V_27 ,
L_47 ,
V_14 ) ;
V_14 = F_104 ( V_48 -> V_31 [ V_3 ] . V_88 ,
V_81 -> V_179 ) ;
if ( V_14 != 0 )
F_38 ( V_48 -> V_31 [ V_3 ] . V_88 -> V_27 ,
L_47 ,
V_14 ) ;
}
}
snprintf ( V_48 -> V_71 -> V_180 , sizeof( V_48 -> V_71 -> V_180 ) ,
L_48 , V_48 -> V_50 ) ;
snprintf ( V_48 -> V_71 -> V_181 , sizeof( V_48 -> V_71 -> V_181 ) ,
L_48 , V_48 -> V_182 ? V_48 -> V_182 : V_48 -> V_50 ) ;
snprintf ( V_48 -> V_71 -> V_10 , sizeof( V_48 -> V_71 -> V_10 ) ,
L_48 , V_48 -> V_183 ? V_48 -> V_183 : V_48 -> V_50 ) ;
for ( V_3 = 0 ; V_3 < F_105 ( V_48 -> V_71 -> V_10 ) ; V_3 ++ ) {
switch ( V_48 -> V_71 -> V_10 [ V_3 ] ) {
case '_' :
case '-' :
case '\0' :
break;
default:
if ( ! isalnum ( V_48 -> V_71 -> V_10 [ V_3 ] ) )
V_48 -> V_71 -> V_10 [ V_3 ] = '_' ;
break;
}
}
if ( V_48 -> V_184 ) {
V_14 = V_48 -> V_184 ( V_48 ) ;
if ( V_14 < 0 ) {
F_62 ( V_48 -> V_27 , L_49 ,
V_48 -> V_50 , V_14 ) ;
goto V_178;
}
}
F_82 ( & V_48 -> V_56 ) ;
V_14 = F_106 ( V_48 -> V_71 ) ;
if ( V_14 < 0 ) {
F_26 ( V_73 L_50 , V_48 -> V_50 ) ;
goto V_178;
}
#ifdef F_107
for ( V_3 = 0 ; V_3 < V_48 -> V_77 ; V_3 ++ ) {
V_14 = F_89 ( & V_48 -> V_31 [ V_3 ] ) ;
if ( V_14 < 0 ) {
F_26 ( V_73 L_51 , V_48 -> V_50 ) ;
while ( -- V_3 >= 0 )
F_90 ( V_48 -> V_31 [ V_3 ] . V_5 ) ;
goto V_178;
}
}
#endif
V_48 -> V_171 = 1 ;
F_108 ( & V_48 -> V_56 ) ;
F_97 ( & V_48 -> V_170 ) ;
return;
V_178:
for ( V_3 = 0 ; V_3 < V_48 -> V_177 ; V_3 ++ )
F_92 ( V_48 , V_3 ) ;
V_176:
F_70 ( V_48 ) ;
V_175:
if ( V_48 -> remove )
V_48 -> remove ( V_48 ) ;
F_109 ( V_48 -> V_71 ) ;
F_97 ( & V_48 -> V_170 ) ;
}
static void F_110 ( void )
{
struct V_61 * V_48 ;
F_33 (card, &card_list, list)
F_95 ( V_48 ) ;
}
static int F_111 ( struct V_185 * V_186 )
{
struct V_61 * V_48 = F_112 ( V_186 ) ;
int V_14 = 0 ;
if ( ! V_48 )
return - V_17 ;
V_48 -> V_27 = & V_186 -> V_27 ;
V_14 = F_113 ( V_48 ) ;
if ( V_14 != 0 ) {
F_62 ( & V_186 -> V_27 , L_52 ) ;
return V_14 ;
}
return 0 ;
}
static int F_114 ( struct V_61 * V_48 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_48 -> V_77 ; V_3 ++ ) {
struct V_30 * V_31 = & V_48 -> V_31 [ V_3 ] ;
F_56 ( & V_31 -> V_92 ) ;
}
for ( V_3 = 0 ; V_3 < V_48 -> V_177 ; V_3 ++ )
F_92 ( V_48 , V_3 ) ;
F_70 ( V_48 ) ;
F_40 ( V_48 ) ;
if ( V_48 -> remove )
V_48 -> remove ( V_48 ) ;
F_65 ( & V_48 -> V_56 ) ;
F_17 ( V_48 -> V_31 ) ;
F_109 ( V_48 -> V_71 ) ;
return 0 ;
}
static int F_115 ( struct V_185 * V_186 )
{
struct V_61 * V_48 = F_112 ( V_186 ) ;
F_116 ( V_48 ) ;
return 0 ;
}
int F_117 ( struct V_26 * V_27 )
{
struct V_61 * V_48 = F_49 ( V_27 ) ;
int V_3 ;
if ( ! V_48 -> V_171 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_48 -> V_77 ; V_3 ++ ) {
struct V_30 * V_31 = & V_48 -> V_31 [ V_3 ] ;
F_56 ( & V_31 -> V_92 ) ;
}
F_118 ( V_48 ) ;
return 0 ;
}
int F_119 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_187 )
return V_5 -> V_187 ( V_5 , V_6 ) ;
else
return 0 ;
}
int F_6 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_188 )
return V_5 -> V_188 ( V_5 , V_6 ) ;
else
return 1 ;
}
int F_120 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_189 )
return V_5 -> V_189 ( V_5 , V_6 ) ;
else
return 1 ;
}
int F_121 ( struct V_59 * V_60 ,
unsigned int V_6 )
{
unsigned int V_14 ;
if ( ! V_60 -> V_10 -> V_190 ) {
F_62 ( V_60 -> V_27 , L_53 ) ;
return - 1 ;
}
V_14 = V_60 -> V_10 -> V_190 ( V_60 , V_6 ) ;
F_58 ( V_60 -> V_27 , L_54 , V_6 , V_14 ) ;
F_122 ( V_60 , V_6 , V_14 ) ;
return V_14 ;
}
int F_123 ( struct V_59 * V_60 ,
unsigned int V_6 , unsigned int V_1 )
{
if ( ! V_60 -> V_10 -> V_191 ) {
F_62 ( V_60 -> V_27 , L_55 ) ;
return - 1 ;
}
F_58 ( V_60 -> V_27 , L_56 , V_6 , V_1 ) ;
F_124 ( V_60 , V_6 , V_1 ) ;
return V_60 -> V_10 -> V_191 ( V_60 , V_6 , V_1 ) ;
}
int F_125 ( struct V_4 * V_5 ,
struct V_192 * V_83 , int V_111 )
{
F_96 ( & V_5 -> V_170 ) ;
V_5 -> V_65 = F_126 ( sizeof( struct V_193 ) , V_39 ) ;
if ( V_5 -> V_65 == NULL ) {
F_97 ( & V_5 -> V_170 ) ;
return - V_40 ;
}
V_5 -> V_65 -> V_66 = F_126 ( sizeof( struct V_194 ) , V_39 ) ;
if ( V_5 -> V_65 -> V_66 == NULL ) {
F_17 ( V_5 -> V_65 ) ;
V_5 -> V_65 = NULL ;
F_97 ( & V_5 -> V_170 ) ;
return - V_40 ;
}
V_5 -> V_65 -> V_66 -> V_83 = V_83 ;
V_5 -> V_65 -> V_111 = V_111 ;
V_5 -> V_164 = 1 ;
F_97 ( & V_5 -> V_170 ) ;
return 0 ;
}
void F_127 ( struct V_4 * V_5 )
{
F_96 ( & V_5 -> V_170 ) ;
#ifdef F_107
F_90 ( V_5 ) ;
#endif
F_17 ( V_5 -> V_65 -> V_66 ) ;
F_17 ( V_5 -> V_65 ) ;
V_5 -> V_65 = NULL ;
V_5 -> V_164 = 0 ;
F_97 ( & V_5 -> V_170 ) ;
}
unsigned int F_4 ( struct V_4 * V_5 , unsigned int V_6 )
{
unsigned int V_14 ;
V_14 = V_5 -> V_190 ( V_5 , V_6 ) ;
F_58 ( V_5 -> V_27 , L_54 , V_6 , V_14 ) ;
F_128 ( V_5 , V_6 , V_14 ) ;
return V_14 ;
}
unsigned int F_23 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned int V_1 )
{
F_58 ( V_5 -> V_27 , L_56 , V_6 , V_1 ) ;
F_129 ( V_5 , V_6 , V_1 ) ;
return V_5 -> V_191 ( V_5 , V_6 , V_1 ) ;
}
unsigned int F_130 ( struct V_4 * V_5 ,
unsigned int V_6 , const void * V_195 , T_1 V_8 )
{
return V_5 -> V_196 ( V_5 , V_6 , V_195 , V_8 ) ;
}
int F_131 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_197 , unsigned int V_44 )
{
int V_198 ;
unsigned int V_199 , V_200 ;
int V_14 ;
V_14 = F_4 ( V_5 , V_6 ) ;
if ( V_14 < 0 )
return V_14 ;
V_199 = V_14 ;
V_200 = ( V_199 & ~ V_197 ) | ( V_44 & V_197 ) ;
V_198 = V_199 != V_200 ;
if ( V_198 ) {
V_14 = F_23 ( V_5 , V_6 , V_200 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return V_198 ;
}
int F_132 ( struct V_4 * V_5 ,
unsigned short V_6 , unsigned int V_197 ,
unsigned int V_44 )
{
int V_198 ;
F_96 ( & V_5 -> V_170 ) ;
V_198 = F_131 ( V_5 , V_6 , V_197 , V_44 ) ;
F_97 ( & V_5 -> V_170 ) ;
return V_198 ;
}
int F_133 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_197 , unsigned int V_44 )
{
int V_198 ;
unsigned int V_199 , V_200 ;
V_199 = F_4 ( V_5 , V_6 ) ;
V_200 = ( V_199 & ~ V_197 ) | V_44 ;
V_198 = V_199 != V_200 ;
return V_198 ;
}
int F_134 ( struct V_201 * V_202 ,
const struct V_203 * V_204 )
{
struct V_205 * V_206 = V_202 -> V_206 ;
V_206 -> V_204 . V_207 = V_204 -> V_207 ;
V_206 -> V_204 . V_208 = V_204 -> V_208 ;
V_206 -> V_204 . V_209 = V_204 -> V_209 ;
V_206 -> V_204 . V_210 = V_204 -> V_210 ;
V_206 -> V_204 . V_211 = V_204 -> V_211 ;
V_206 -> V_204 . V_212 = V_204 -> V_212 ;
V_206 -> V_204 . V_213 = V_204 -> V_213 ;
V_206 -> V_204 . V_214 = V_204 -> V_214 ;
return 0 ;
}
struct V_215 * F_135 ( const struct V_216 * V_217 ,
void * V_195 , char * V_182 ,
const char * V_218 )
{
struct V_216 V_219 ;
struct V_215 * V_220 ;
char * V_50 = NULL ;
int V_221 ;
memcpy ( & V_219 , V_217 , sizeof( V_219 ) ) ;
V_219 . V_222 = 0 ;
if ( ! V_182 )
V_182 = V_219 . V_50 ;
if ( V_218 ) {
V_221 = strlen ( V_182 ) + strlen ( V_218 ) + 2 ;
V_50 = F_15 ( V_221 , V_39 ) ;
if ( ! V_50 )
return NULL ;
snprintf ( V_50 , V_221 , L_57 , V_218 , V_182 ) ;
V_219 . V_50 = V_50 ;
} else {
V_219 . V_50 = V_182 ;
}
V_220 = F_136 ( & V_219 , V_195 ) ;
F_17 ( V_50 ) ;
return V_220 ;
}
int F_75 ( struct V_4 * V_5 ,
const struct V_216 * V_144 , int V_145 )
{
struct V_71 * V_48 = V_5 -> V_48 -> V_71 ;
int V_67 , V_3 ;
for ( V_3 = 0 ; V_3 < V_145 ; V_3 ++ ) {
const struct V_216 * V_223 = & V_144 [ V_3 ] ;
V_67 = F_137 ( V_48 , F_135 ( V_223 , V_5 ,
V_223 -> V_50 ,
V_5 -> V_136 ) ) ;
if ( V_67 < 0 ) {
F_62 ( V_5 -> V_27 , L_58 ,
V_5 -> V_50 , V_223 -> V_50 , V_67 ) ;
return V_67 ;
}
}
return 0 ;
}
int F_79 ( struct V_59 * V_60 ,
const struct V_216 * V_144 , int V_145 )
{
struct V_71 * V_48 = V_60 -> V_48 -> V_71 ;
int V_67 , V_3 ;
for ( V_3 = 0 ; V_3 < V_145 ; V_3 ++ ) {
const struct V_216 * V_223 = & V_144 [ V_3 ] ;
V_67 = F_137 ( V_48 , F_135 ( V_223 , V_60 ,
V_223 -> V_50 , NULL ) ) ;
if ( V_67 < 0 ) {
F_62 ( V_60 -> V_27 , L_59 , V_223 -> V_50 , V_67 ) ;
return V_67 ;
}
}
return 0 ;
}
int F_138 ( struct V_215 * V_220 ,
struct V_224 * V_225 )
{
struct V_226 * V_227 = (struct V_226 * ) V_220 -> V_228 ;
V_225 -> type = V_229 ;
V_225 -> V_18 = V_227 -> V_230 == V_227 -> V_231 ? 1 : 2 ;
V_225 -> V_44 . V_232 . V_233 = V_227 -> V_234 ;
if ( V_225 -> V_44 . V_232 . V_235 > V_227 -> V_234 - 1 )
V_225 -> V_44 . V_232 . V_235 = V_227 -> V_234 - 1 ;
strcpy ( V_225 -> V_44 . V_232 . V_50 ,
V_227 -> V_236 [ V_225 -> V_44 . V_232 . V_235 ] ) ;
return 0 ;
}
int F_139 ( struct V_215 * V_220 ,
struct V_237 * V_238 )
{
struct V_4 * V_5 = F_140 ( V_220 ) ;
struct V_226 * V_227 = (struct V_226 * ) V_220 -> V_228 ;
unsigned int V_1 , V_239 ;
for ( V_239 = 1 ; V_239 < V_227 -> V_234 ; V_239 <<= 1 )
;
V_1 = F_4 ( V_5 , V_227 -> V_6 ) ;
V_238 -> V_44 . V_232 . V_235 [ 0 ]
= ( V_1 >> V_227 -> V_230 ) & ( V_239 - 1 ) ;
if ( V_227 -> V_230 != V_227 -> V_231 )
V_238 -> V_44 . V_232 . V_235 [ 1 ] =
( V_1 >> V_227 -> V_231 ) & ( V_239 - 1 ) ;
return 0 ;
}
int F_141 ( struct V_215 * V_220 ,
struct V_237 * V_238 )
{
struct V_4 * V_5 = F_140 ( V_220 ) ;
struct V_226 * V_227 = (struct V_226 * ) V_220 -> V_228 ;
unsigned int V_1 ;
unsigned int V_197 , V_239 ;
for ( V_239 = 1 ; V_239 < V_227 -> V_234 ; V_239 <<= 1 )
;
if ( V_238 -> V_44 . V_232 . V_235 [ 0 ] > V_227 -> V_234 - 1 )
return - V_17 ;
V_1 = V_238 -> V_44 . V_232 . V_235 [ 0 ] << V_227 -> V_230 ;
V_197 = ( V_239 - 1 ) << V_227 -> V_230 ;
if ( V_227 -> V_230 != V_227 -> V_231 ) {
if ( V_238 -> V_44 . V_232 . V_235 [ 1 ] > V_227 -> V_234 - 1 )
return - V_17 ;
V_1 |= V_238 -> V_44 . V_232 . V_235 [ 1 ] << V_227 -> V_231 ;
V_197 |= ( V_239 - 1 ) << V_227 -> V_231 ;
}
return F_132 ( V_5 , V_227 -> V_6 , V_197 , V_1 ) ;
}
int F_142 ( struct V_215 * V_220 ,
struct V_237 * V_238 )
{
struct V_4 * V_5 = F_140 ( V_220 ) ;
struct V_226 * V_227 = (struct V_226 * ) V_220 -> V_228 ;
unsigned int V_240 , V_1 , V_241 ;
V_240 = F_4 ( V_5 , V_227 -> V_6 ) ;
V_1 = ( V_240 >> V_227 -> V_230 ) & V_227 -> V_197 ;
for ( V_241 = 0 ; V_241 < V_227 -> V_234 ; V_241 ++ ) {
if ( V_1 == V_227 -> V_242 [ V_241 ] )
break;
}
V_238 -> V_44 . V_232 . V_235 [ 0 ] = V_241 ;
if ( V_227 -> V_230 != V_227 -> V_231 ) {
V_1 = ( V_240 >> V_227 -> V_231 ) & V_227 -> V_197 ;
for ( V_241 = 0 ; V_241 < V_227 -> V_234 ; V_241 ++ ) {
if ( V_1 == V_227 -> V_242 [ V_241 ] )
break;
}
V_238 -> V_44 . V_232 . V_235 [ 1 ] = V_241 ;
}
return 0 ;
}
int F_143 ( struct V_215 * V_220 ,
struct V_237 * V_238 )
{
struct V_4 * V_5 = F_140 ( V_220 ) ;
struct V_226 * V_227 = (struct V_226 * ) V_220 -> V_228 ;
unsigned int V_1 ;
unsigned int V_197 ;
if ( V_238 -> V_44 . V_232 . V_235 [ 0 ] > V_227 -> V_234 - 1 )
return - V_17 ;
V_1 = V_227 -> V_242 [ V_238 -> V_44 . V_232 . V_235 [ 0 ] ] << V_227 -> V_230 ;
V_197 = V_227 -> V_197 << V_227 -> V_230 ;
if ( V_227 -> V_230 != V_227 -> V_231 ) {
if ( V_238 -> V_44 . V_232 . V_235 [ 1 ] > V_227 -> V_234 - 1 )
return - V_17 ;
V_1 |= V_227 -> V_242 [ V_238 -> V_44 . V_232 . V_235 [ 1 ] ] << V_227 -> V_231 ;
V_197 |= V_227 -> V_197 << V_227 -> V_231 ;
}
return F_132 ( V_5 , V_227 -> V_6 , V_197 , V_1 ) ;
}
int F_144 ( struct V_215 * V_220 ,
struct V_224 * V_225 )
{
struct V_226 * V_227 = (struct V_226 * ) V_220 -> V_228 ;
V_225 -> type = V_229 ;
V_225 -> V_18 = 1 ;
V_225 -> V_44 . V_232 . V_233 = V_227 -> V_234 ;
if ( V_225 -> V_44 . V_232 . V_235 > V_227 -> V_234 - 1 )
V_225 -> V_44 . V_232 . V_235 = V_227 -> V_234 - 1 ;
strcpy ( V_225 -> V_44 . V_232 . V_50 ,
V_227 -> V_236 [ V_225 -> V_44 . V_232 . V_235 ] ) ;
return 0 ;
}
int F_145 ( struct V_215 * V_220 ,
struct V_224 * V_225 )
{
int V_234 = V_220 -> V_228 ;
if ( V_234 == 1 && ! strstr ( V_220 -> V_243 . V_50 , L_60 ) )
V_225 -> type = V_244 ;
else
V_225 -> type = V_245 ;
V_225 -> V_18 = 1 ;
V_225 -> V_44 . integer . F_7 = 0 ;
V_225 -> V_44 . integer . V_234 = V_234 ;
return 0 ;
}
int F_146 ( struct V_215 * V_220 ,
struct V_224 * V_225 )
{
struct V_246 * V_247 =
(struct V_246 * ) V_220 -> V_228 ;
int V_248 ;
if ( ! V_247 -> V_248 )
V_247 -> V_248 = V_247 -> V_234 ;
V_248 = V_247 -> V_248 ;
if ( V_248 == 1 && ! strstr ( V_220 -> V_243 . V_50 , L_60 ) )
V_225 -> type = V_244 ;
else
V_225 -> type = V_245 ;
V_225 -> V_18 = F_147 ( V_247 ) ? 2 : 1 ;
V_225 -> V_44 . integer . F_7 = 0 ;
V_225 -> V_44 . integer . V_234 = V_248 ;
return 0 ;
}
int F_148 ( struct V_215 * V_220 ,
struct V_237 * V_238 )
{
struct V_246 * V_247 =
(struct V_246 * ) V_220 -> V_228 ;
struct V_4 * V_5 = F_140 ( V_220 ) ;
unsigned int V_6 = V_247 -> V_6 ;
unsigned int V_249 = V_247 -> V_250 ;
unsigned int V_251 = V_247 -> V_251 ;
unsigned int V_252 = V_247 -> V_252 ;
int V_234 = V_247 -> V_234 ;
unsigned int V_197 = ( 1 << F_149 ( V_234 ) ) - 1 ;
unsigned int V_253 = V_247 -> V_253 ;
V_238 -> V_44 . integer . V_44 [ 0 ] =
( F_4 ( V_5 , V_6 ) >> V_251 ) & V_197 ;
if ( V_253 )
V_238 -> V_44 . integer . V_44 [ 0 ] =
V_234 - V_238 -> V_44 . integer . V_44 [ 0 ] ;
if ( F_147 ( V_247 ) ) {
if ( V_6 == V_249 )
V_238 -> V_44 . integer . V_44 [ 1 ] =
( F_4 ( V_5 , V_6 ) >> V_252 ) & V_197 ;
else
V_238 -> V_44 . integer . V_44 [ 1 ] =
( F_4 ( V_5 , V_249 ) >> V_251 ) & V_197 ;
if ( V_253 )
V_238 -> V_44 . integer . V_44 [ 1 ] =
V_234 - V_238 -> V_44 . integer . V_44 [ 1 ] ;
}
return 0 ;
}
int F_150 ( struct V_215 * V_220 ,
struct V_237 * V_238 )
{
struct V_246 * V_247 =
(struct V_246 * ) V_220 -> V_228 ;
struct V_4 * V_5 = F_140 ( V_220 ) ;
unsigned int V_6 = V_247 -> V_6 ;
unsigned int V_249 = V_247 -> V_250 ;
unsigned int V_251 = V_247 -> V_251 ;
unsigned int V_252 = V_247 -> V_252 ;
int V_234 = V_247 -> V_234 ;
unsigned int V_197 = ( 1 << F_149 ( V_234 ) ) - 1 ;
unsigned int V_253 = V_247 -> V_253 ;
int V_67 ;
bool V_254 = 0 ;
unsigned int V_255 = 0 ;
unsigned int V_1 , V_256 ;
V_1 = ( V_238 -> V_44 . integer . V_44 [ 0 ] & V_197 ) ;
if ( V_253 )
V_1 = V_234 - V_1 ;
V_256 = V_197 << V_251 ;
V_1 = V_1 << V_251 ;
if ( F_147 ( V_247 ) ) {
V_255 = ( V_238 -> V_44 . integer . V_44 [ 1 ] & V_197 ) ;
if ( V_253 )
V_255 = V_234 - V_255 ;
if ( V_6 == V_249 ) {
V_256 |= V_197 << V_252 ;
V_1 |= V_255 << V_252 ;
} else {
V_255 = V_255 << V_251 ;
V_254 = 1 ;
}
}
V_67 = F_132 ( V_5 , V_6 , V_256 , V_1 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( V_254 )
V_67 = F_132 ( V_5 , V_249 , V_256 , V_255 ) ;
return V_67 ;
}
int F_151 ( struct V_215 * V_220 ,
struct V_224 * V_225 )
{
struct V_246 * V_247 =
(struct V_246 * ) V_220 -> V_228 ;
int V_248 ;
int F_7 = V_247 -> F_7 ;
if ( ! V_247 -> V_248 )
V_247 -> V_248 = V_247 -> V_234 ;
V_248 = V_247 -> V_248 ;
V_225 -> type = V_245 ;
V_225 -> V_18 = 2 ;
V_225 -> V_44 . integer . F_7 = 0 ;
V_225 -> V_44 . integer . V_234 = V_248 - F_7 ;
return 0 ;
}
int F_152 ( struct V_215 * V_220 ,
struct V_237 * V_238 )
{
struct V_246 * V_247 =
(struct V_246 * ) V_220 -> V_228 ;
struct V_4 * V_5 = F_140 ( V_220 ) ;
unsigned int V_6 = V_247 -> V_6 ;
int F_7 = V_247 -> F_7 ;
int V_1 = F_4 ( V_5 , V_6 ) ;
V_238 -> V_44 . integer . V_44 [ 0 ] =
( ( signed char ) ( V_1 & 0xff ) ) - F_7 ;
V_238 -> V_44 . integer . V_44 [ 1 ] =
( ( signed char ) ( ( V_1 >> 8 ) & 0xff ) ) - F_7 ;
return 0 ;
}
int F_153 ( struct V_215 * V_220 ,
struct V_237 * V_238 )
{
struct V_246 * V_247 =
(struct V_246 * ) V_220 -> V_228 ;
struct V_4 * V_5 = F_140 ( V_220 ) ;
unsigned int V_6 = V_247 -> V_6 ;
int F_7 = V_247 -> F_7 ;
unsigned int V_1 ;
V_1 = ( V_238 -> V_44 . integer . V_44 [ 0 ] + F_7 ) & 0xff ;
V_1 |= ( ( V_238 -> V_44 . integer . V_44 [ 1 ] + F_7 ) & 0xff ) << 8 ;
return F_132 ( V_5 , V_6 , 0xffff , V_1 ) ;
}
int F_154 ( struct V_4 * V_5 ,
const char * V_50 , int V_234 )
{
struct V_71 * V_48 = V_5 -> V_48 -> V_71 ;
struct V_215 * V_257 ;
struct V_246 * V_247 ;
int V_166 = 0 ;
int V_14 = - V_17 ;
if ( F_155 ( ! V_50 || V_234 <= 0 ) )
return - V_17 ;
F_33 (kctl, &card->controls, list) {
if ( ! strncmp ( V_257 -> V_243 . V_50 , V_50 , sizeof( V_257 -> V_243 . V_50 ) ) ) {
V_166 = 1 ;
break;
}
}
if ( V_166 ) {
V_247 = (struct V_246 * ) V_257 -> V_228 ;
if ( V_234 <= V_247 -> V_234 ) {
V_247 -> V_248 = V_234 ;
V_14 = 0 ;
}
}
return V_14 ;
}
int F_156 ( struct V_215 * V_220 ,
struct V_224 * V_225 )
{
struct V_246 * V_247 =
(struct V_246 * ) V_220 -> V_228 ;
int V_234 = V_247 -> V_234 ;
int F_7 = V_247 -> F_7 ;
V_225 -> type = V_245 ;
V_225 -> V_18 = 2 ;
V_225 -> V_44 . integer . F_7 = 0 ;
V_225 -> V_44 . integer . V_234 = V_234 - F_7 ;
return 0 ;
}
int F_157 ( struct V_215 * V_220 ,
struct V_237 * V_238 )
{
struct V_246 * V_247 =
(struct V_246 * ) V_220 -> V_228 ;
struct V_4 * V_5 = F_140 ( V_220 ) ;
unsigned int V_197 = ( 1 << V_247 -> V_251 ) - 1 ;
int F_7 = V_247 -> F_7 ;
int V_1 = F_4 ( V_5 , V_247 -> V_6 ) & V_197 ;
int V_258 = F_4 ( V_5 , V_247 -> V_250 ) & V_197 ;
V_238 -> V_44 . integer . V_44 [ 0 ] = ( ( V_1 & 0xff ) - F_7 ) & V_197 ;
V_238 -> V_44 . integer . V_44 [ 1 ] = ( ( V_258 & 0xff ) - F_7 ) & V_197 ;
return 0 ;
}
int F_158 ( struct V_215 * V_220 ,
struct V_237 * V_238 )
{
struct V_246 * V_247 =
(struct V_246 * ) V_220 -> V_228 ;
struct V_4 * V_5 = F_140 ( V_220 ) ;
unsigned int V_197 = ( 1 << V_247 -> V_251 ) - 1 ;
int F_7 = V_247 -> F_7 ;
int V_14 ;
unsigned int V_1 , V_258 , V_259 , V_260 ;
V_1 = ( ( V_238 -> V_44 . integer . V_44 [ 0 ] + F_7 ) & 0xff ) ;
V_1 &= V_197 ;
V_258 = ( ( V_238 -> V_44 . integer . V_44 [ 1 ] + F_7 ) & 0xff ) ;
V_258 &= V_197 ;
V_259 = F_4 ( V_5 , V_247 -> V_6 ) & V_197 ;
V_260 = F_4 ( V_5 , V_247 -> V_250 ) & V_197 ;
V_14 = 0 ;
if ( V_259 != V_1 ) {
V_14 = F_23 ( V_5 , V_247 -> V_6 , V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( V_260 != V_258 ) {
V_14 = F_23 ( V_5 , V_247 -> V_250 , V_258 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
int F_159 ( struct V_57 * V_58 , int V_261 ,
unsigned int V_262 , int V_263 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_83 -> V_264 )
return V_58 -> V_10 -> V_83 -> V_264 ( V_58 , V_261 , V_262 , V_263 ) ;
else if ( V_58 -> V_5 && V_58 -> V_5 -> V_10 -> V_264 )
return V_58 -> V_5 -> V_10 -> V_264 ( V_58 -> V_5 , V_261 , 0 ,
V_262 , V_263 ) ;
else
return - V_17 ;
}
int F_160 ( struct V_4 * V_5 , int V_261 ,
int V_265 , unsigned int V_262 , int V_263 )
{
if ( V_5 -> V_10 -> V_264 )
return V_5 -> V_10 -> V_264 ( V_5 , V_261 , V_265 ,
V_262 , V_263 ) ;
else
return - V_17 ;
}
int F_161 ( struct V_57 * V_58 ,
int V_266 , int div )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_83 -> V_267 )
return V_58 -> V_10 -> V_83 -> V_267 ( V_58 , V_266 , div ) ;
else
return - V_17 ;
}
int F_162 ( struct V_57 * V_58 , int V_268 , int V_265 ,
unsigned int V_269 , unsigned int V_270 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_83 -> V_271 )
return V_58 -> V_10 -> V_83 -> V_271 ( V_58 , V_268 , V_265 ,
V_269 , V_270 ) ;
else if ( V_58 -> V_5 && V_58 -> V_5 -> V_10 -> V_271 )
return V_58 -> V_5 -> V_10 -> V_271 ( V_58 -> V_5 , V_268 , V_265 ,
V_269 , V_270 ) ;
else
return - V_17 ;
}
int F_163 ( struct V_4 * V_5 , int V_268 , int V_265 ,
unsigned int V_269 , unsigned int V_270 )
{
if ( V_5 -> V_10 -> V_271 )
return V_5 -> V_10 -> V_271 ( V_5 , V_268 , V_265 ,
V_269 , V_270 ) ;
else
return - V_17 ;
}
int F_104 ( struct V_57 * V_58 , unsigned int V_272 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_83 -> V_273 )
return V_58 -> V_10 -> V_83 -> V_273 ( V_58 , V_272 ) ;
else
return - V_17 ;
}
int F_164 ( struct V_57 * V_58 ,
unsigned int V_274 , unsigned int V_275 , int V_276 , int V_277 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_83 -> V_278 )
return V_58 -> V_10 -> V_83 -> V_278 ( V_58 , V_274 , V_275 ,
V_276 , V_277 ) ;
else
return - V_17 ;
}
int F_165 ( struct V_57 * V_58 ,
unsigned int V_279 , unsigned int * V_280 ,
unsigned int V_281 , unsigned int * V_282 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_83 -> V_283 )
return V_58 -> V_10 -> V_83 -> V_283 ( V_58 , V_279 , V_280 ,
V_281 , V_282 ) ;
else
return - V_17 ;
}
int F_166 ( struct V_57 * V_58 , int V_284 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_83 -> V_285 )
return V_58 -> V_10 -> V_83 -> V_285 ( V_58 , V_284 ) ;
else
return - V_17 ;
}
int F_167 ( struct V_57 * V_58 , int V_286 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_83 -> V_84 )
return V_58 -> V_10 -> V_83 -> V_84 ( V_58 , V_286 ) ;
else
return - V_17 ;
}
int F_113 ( struct V_61 * V_48 )
{
int V_3 ;
if ( ! V_48 -> V_50 || ! V_48 -> V_27 )
return - V_17 ;
F_168 ( V_48 -> V_27 , V_48 ) ;
F_169 ( V_48 ) ;
F_37 ( V_48 ) ;
V_48 -> V_31 = F_126 ( sizeof( struct V_30 ) *
( V_48 -> V_172 + V_48 -> V_177 ) ,
V_39 ) ;
if ( V_48 -> V_31 == NULL )
return - V_40 ;
V_48 -> V_156 = & V_48 -> V_31 [ V_48 -> V_172 ] ;
for ( V_3 = 0 ; V_3 < V_48 -> V_172 ; V_3 ++ )
V_48 -> V_31 [ V_3 ] . V_81 = & V_48 -> V_81 [ V_3 ] ;
F_170 ( & V_48 -> V_148 ) ;
F_170 ( & V_48 -> V_287 ) ;
V_48 -> V_171 = 0 ;
F_83 ( & V_48 -> V_170 ) ;
F_96 ( & V_288 ) ;
F_77 ( & V_48 -> V_148 , & V_122 ) ;
F_110 () ;
F_97 ( & V_288 ) ;
F_58 ( V_48 -> V_27 , L_61 , V_48 -> V_50 ) ;
return 0 ;
}
int F_116 ( struct V_61 * V_48 )
{
if ( V_48 -> V_171 )
F_114 ( V_48 ) ;
F_96 ( & V_288 ) ;
F_66 ( & V_48 -> V_148 ) ;
F_97 ( & V_288 ) ;
F_58 ( V_48 -> V_27 , L_62 , V_48 -> V_50 ) ;
return 0 ;
}
static char * F_171 ( struct V_26 * V_27 , int * V_243 )
{
char * V_166 , V_50 [ V_289 ] ;
int V_290 , V_291 ;
if ( V_135 ( V_27 ) == NULL )
return NULL ;
F_172 ( V_50 , V_135 ( V_27 ) , V_289 ) ;
V_166 = strstr ( V_50 , V_27 -> V_10 -> V_50 ) ;
if ( V_166 ) {
if ( sscanf ( & V_166 [ strlen ( V_27 -> V_10 -> V_50 ) ] , L_63 , V_243 ) == 1 ) {
if ( * V_243 == - 1 )
V_166 [ strlen ( V_27 -> V_10 -> V_50 ) ] = '\0' ;
}
} else {
if ( sscanf ( V_50 , L_64 , & V_290 , & V_291 ) == 2 ) {
char V_292 [ V_289 ] ;
* V_243 = ( ( V_290 & 0xffff ) << 16 ) + V_291 ;
snprintf ( V_292 , V_289 , L_65 , V_27 -> V_10 -> V_50 , V_50 ) ;
F_172 ( V_50 , V_292 , V_289 ) ;
} else
* V_243 = 0 ;
}
return F_173 ( V_50 , V_39 ) ;
}
static inline char * F_174 ( struct V_26 * V_27 ,
struct V_79 * V_293 )
{
if ( V_293 -> V_50 == NULL ) {
F_26 ( V_73 L_66 ,
V_135 ( V_27 ) ) ;
return NULL ;
}
return F_173 ( V_293 -> V_50 , V_39 ) ;
}
int F_175 ( struct V_26 * V_27 ,
struct V_79 * V_293 )
{
struct V_57 * V_58 ;
F_58 ( V_27 , L_67 , V_135 ( V_27 ) ) ;
V_58 = F_126 ( sizeof( struct V_57 ) , V_39 ) ;
if ( V_58 == NULL )
return - V_40 ;
V_58 -> V_50 = F_171 ( V_27 , & V_58 -> V_243 ) ;
if ( V_58 -> V_50 == NULL ) {
F_17 ( V_58 ) ;
return - V_40 ;
}
V_58 -> V_27 = V_27 ;
V_58 -> V_10 = V_293 ;
if ( ! V_58 -> V_10 -> V_83 )
V_58 -> V_10 -> V_83 = & V_294 ;
F_96 ( & V_288 ) ;
F_77 ( & V_58 -> V_148 , & V_295 ) ;
F_110 () ;
F_97 ( & V_288 ) ;
F_176 ( L_68 , V_58 -> V_50 ) ;
return 0 ;
}
void F_177 ( struct V_26 * V_27 )
{
struct V_57 * V_58 ;
F_33 (dai, &dai_list, list) {
if ( V_27 == V_58 -> V_27 )
goto V_166;
}
return;
V_166:
F_96 ( & V_288 ) ;
F_66 ( & V_58 -> V_148 ) ;
F_97 ( & V_288 ) ;
F_176 ( L_69 , V_58 -> V_50 ) ;
F_17 ( V_58 -> V_50 ) ;
F_17 ( V_58 ) ;
}
int F_178 ( struct V_26 * V_27 ,
struct V_79 * V_293 , T_1 V_18 )
{
struct V_57 * V_58 ;
int V_3 , V_14 = 0 ;
F_58 ( V_27 , L_70 , V_135 ( V_27 ) , V_18 ) ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ ) {
V_58 = F_126 ( sizeof( struct V_57 ) , V_39 ) ;
if ( V_58 == NULL ) {
V_14 = - V_40 ;
goto V_67;
}
V_58 -> V_50 = F_174 ( V_27 , & V_293 [ V_3 ] ) ;
if ( V_58 -> V_50 == NULL ) {
F_17 ( V_58 ) ;
V_14 = - V_17 ;
goto V_67;
}
V_58 -> V_27 = V_27 ;
V_58 -> V_10 = & V_293 [ V_3 ] ;
if ( V_58 -> V_10 -> V_243 )
V_58 -> V_243 = V_58 -> V_10 -> V_243 ;
else
V_58 -> V_243 = V_3 ;
if ( ! V_58 -> V_10 -> V_83 )
V_58 -> V_10 -> V_83 = & V_294 ;
F_96 ( & V_288 ) ;
F_77 ( & V_58 -> V_148 , & V_295 ) ;
F_97 ( & V_288 ) ;
F_176 ( L_68 , V_58 -> V_50 ) ;
}
F_96 ( & V_288 ) ;
F_110 () ;
F_97 ( & V_288 ) ;
return 0 ;
V_67:
for ( V_3 -- ; V_3 >= 0 ; V_3 -- )
F_177 ( V_27 ) ;
return V_14 ;
}
void F_179 ( struct V_26 * V_27 , T_1 V_18 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ )
F_177 ( V_27 ) ;
}
int F_180 ( struct V_26 * V_27 ,
struct V_150 * V_296 )
{
struct V_59 * V_60 ;
F_58 ( V_27 , L_71 , V_135 ( V_27 ) ) ;
V_60 = F_126 ( sizeof( struct V_59 ) , V_39 ) ;
if ( V_60 == NULL )
return - V_40 ;
V_60 -> V_50 = F_171 ( V_27 , & V_60 -> V_243 ) ;
if ( V_60 -> V_50 == NULL ) {
F_17 ( V_60 ) ;
return - V_40 ;
}
V_60 -> V_27 = V_27 ;
V_60 -> V_10 = V_296 ;
V_60 -> V_56 . V_27 = V_27 ;
V_60 -> V_56 . V_60 = V_60 ;
V_60 -> V_56 . V_297 = V_296 -> V_297 ;
F_96 ( & V_288 ) ;
F_77 ( & V_60 -> V_148 , & V_298 ) ;
F_110 () ;
F_97 ( & V_288 ) ;
F_176 ( L_72 , V_60 -> V_50 ) ;
return 0 ;
}
void F_181 ( struct V_26 * V_27 )
{
struct V_59 * V_60 ;
F_33 (platform, &platform_list, list) {
if ( V_27 == V_60 -> V_27 )
goto V_166;
}
return;
V_166:
F_96 ( & V_288 ) ;
F_66 ( & V_60 -> V_148 ) ;
F_97 ( & V_288 ) ;
F_176 ( L_73 , V_60 -> V_50 ) ;
F_17 ( V_60 -> V_50 ) ;
F_17 ( V_60 ) ;
}
static void F_182 ( struct V_299 * V_300 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_105 ( V_301 ) ; V_3 ++ )
if ( V_300 -> V_208 & V_301 [ V_3 ] )
V_300 -> V_208 |= V_301 [ V_3 ] ;
}
int F_183 ( struct V_26 * V_27 ,
const struct V_137 * V_302 ,
struct V_79 * V_293 ,
int V_303 )
{
T_1 V_304 ;
struct V_4 * V_5 ;
int V_14 , V_3 ;
F_58 ( V_27 , L_74 , V_135 ( V_27 ) ) ;
V_5 = F_126 ( sizeof( struct V_4 ) , V_39 ) ;
if ( V_5 == NULL )
return - V_40 ;
V_5 -> V_50 = F_171 ( V_27 , & V_5 -> V_243 ) ;
if ( V_5 -> V_50 == NULL ) {
F_17 ( V_5 ) ;
return - V_40 ;
}
if ( V_302 -> V_168 )
V_5 -> V_168 = V_302 -> V_168 ;
else
V_5 -> V_168 = V_305 ;
V_5 -> V_191 = V_302 -> V_191 ;
V_5 -> V_190 = V_302 -> V_190 ;
V_5 -> V_187 = V_302 -> V_187 ;
V_5 -> V_188 = V_302 -> V_188 ;
V_5 -> V_189 = V_302 -> V_189 ;
V_5 -> V_56 . V_94 = V_100 ;
V_5 -> V_56 . V_27 = V_27 ;
V_5 -> V_56 . V_5 = V_5 ;
V_5 -> V_56 . V_306 = V_302 -> V_306 ;
V_5 -> V_56 . V_297 = V_302 -> V_297 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_10 = V_302 ;
V_5 -> V_303 = V_303 ;
F_83 ( & V_5 -> V_170 ) ;
if ( V_302 -> V_11 && V_302 -> V_13 ) {
V_304 = V_302 -> V_11 * V_302 -> V_13 ;
V_5 -> V_304 = V_304 ;
if ( V_302 -> V_307 ) {
V_5 -> V_308 = F_184 ( V_302 -> V_307 ,
V_304 , V_39 ) ;
if ( ! V_5 -> V_308 ) {
V_14 = - V_40 ;
goto V_309;
}
}
}
if ( V_302 -> V_310 && V_302 -> V_311 ) {
if ( ! V_5 -> V_187 )
V_5 -> V_187 = V_312 ;
if ( ! V_5 -> V_188 )
V_5 -> V_188 = V_313 ;
if ( ! V_5 -> V_189 )
V_5 -> V_189 = V_314 ;
}
for ( V_3 = 0 ; V_3 < V_303 ; V_3 ++ ) {
F_182 ( & V_293 [ V_3 ] . V_95 ) ;
F_182 ( & V_293 [ V_3 ] . V_98 ) ;
}
if ( V_303 ) {
V_14 = F_178 ( V_27 , V_293 , V_303 ) ;
if ( V_14 < 0 )
goto V_309;
}
F_96 ( & V_288 ) ;
F_77 ( & V_5 -> V_148 , & V_315 ) ;
F_110 () ;
F_97 ( & V_288 ) ;
F_176 ( L_75 , V_5 -> V_50 ) ;
return 0 ;
V_309:
F_17 ( V_5 -> V_308 ) ;
V_5 -> V_308 = NULL ;
F_17 ( V_5 -> V_50 ) ;
F_17 ( V_5 ) ;
return V_14 ;
}
void F_185 ( struct V_26 * V_27 )
{
struct V_4 * V_5 ;
int V_3 ;
F_33 (codec, &codec_list, list) {
if ( V_27 == V_5 -> V_27 )
goto V_166;
}
return;
V_166:
if ( V_5 -> V_303 )
for ( V_3 = 0 ; V_3 < V_5 -> V_303 ; V_3 ++ )
F_177 ( V_27 ) ;
F_96 ( & V_288 ) ;
F_66 ( & V_5 -> V_148 ) ;
F_97 ( & V_288 ) ;
F_176 ( L_76 , V_5 -> V_50 ) ;
F_186 ( V_5 ) ;
F_17 ( V_5 -> V_308 ) ;
F_17 ( V_5 -> V_50 ) ;
F_17 ( V_5 ) ;
}
static int T_5 F_187 ( void )
{
#ifdef F_99
V_62 = F_25 ( L_77 , NULL ) ;
if ( F_188 ( V_62 ) || ! V_62 ) {
F_26 ( V_51
L_78 ) ;
V_62 = NULL ;
}
if ( ! F_28 ( L_79 , 0444 , V_62 , NULL ,
& V_316 ) )
F_189 ( L_80 ) ;
if ( ! F_28 ( L_81 , 0444 , V_62 , NULL ,
& V_317 ) )
F_189 ( L_82 ) ;
if ( ! F_28 ( L_83 , 0444 , V_62 , NULL ,
& V_318 ) )
F_189 ( L_84 ) ;
#endif
F_190 () ;
return F_191 ( & V_319 ) ;
}
static void T_6 F_192 ( void )
{
F_193 () ;
#ifdef F_99
F_31 ( V_62 ) ;
#endif
F_194 ( & V_319 ) ;
}
