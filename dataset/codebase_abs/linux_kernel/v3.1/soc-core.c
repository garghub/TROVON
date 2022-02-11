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
if ( V_5 -> V_24 && ! V_5 -> V_24 ( V_5 , V_3 ) )
continue;
if ( V_5 -> V_10 -> V_25 ) {
V_18 += V_5 -> V_10 -> V_25 ( V_5 , V_7 + V_18 ,
V_26 - V_18 , V_3 ) ;
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
V_21 = F_6 ( V_21 , V_18 - 1 ) ;
return V_21 ;
}
static T_2 F_7 ( struct V_27 * V_28 ,
struct V_29 * V_30 , char * V_7 )
{
struct V_31 * V_32 =
F_8 ( V_28 , struct V_31 , V_28 ) ;
return F_5 ( V_32 -> V_5 , V_7 , V_26 , 0 ) ;
}
static T_2 F_9 ( struct V_27 * V_28 ,
struct V_29 * V_30 , char * V_7 )
{
struct V_31 * V_32 =
F_8 ( V_28 , struct V_31 , V_28 ) ;
return sprintf ( V_7 , L_3 , V_32 -> V_33 ) ;
}
static T_2 F_10 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
const char * V_7 , T_1 V_18 )
{
struct V_31 * V_32 =
F_8 ( V_28 , struct V_31 , V_28 ) ;
int V_14 ;
V_14 = F_11 ( V_7 , 10 , & V_32 -> V_33 ) ;
if ( V_14 )
return V_14 ;
return V_18 ;
}
static int F_12 ( struct V_34 * V_34 , struct V_35 * V_35 )
{
V_35 -> V_36 = V_34 -> V_37 ;
return 0 ;
}
static T_2 F_13 ( struct V_35 * V_35 , char T_4 * V_38 ,
T_1 V_18 , T_3 * V_39 )
{
T_2 V_14 ;
struct V_4 * V_5 = V_35 -> V_36 ;
char * V_7 ;
if ( * V_39 < 0 || ! V_18 )
return - V_17 ;
V_7 = F_14 ( V_18 , V_40 ) ;
if ( ! V_7 )
return - V_41 ;
V_14 = F_5 ( V_5 , V_7 , V_18 , * V_39 ) ;
if ( V_14 >= 0 ) {
if ( F_15 ( V_38 , V_7 , V_14 ) ) {
F_16 ( V_7 ) ;
return - V_42 ;
}
* V_39 += V_14 ;
}
F_16 ( V_7 ) ;
return V_14 ;
}
static T_2 F_17 ( struct V_35 * V_35 ,
const char T_4 * V_38 , T_1 V_18 , T_3 * V_39 )
{
char V_7 [ 32 ] ;
T_1 V_43 ;
char * V_44 = V_7 ;
unsigned long V_6 , V_45 ;
int V_20 = 1 ;
struct V_4 * V_5 = V_35 -> V_36 ;
V_43 = F_6 ( V_18 , ( sizeof( V_7 ) - 1 ) ) ;
if ( F_18 ( V_7 , V_38 , V_43 ) )
return - V_42 ;
V_7 [ V_43 ] = 0 ;
if ( V_5 -> V_10 -> V_23 )
V_20 = V_5 -> V_10 -> V_23 ;
while ( * V_44 == ' ' )
V_44 ++ ;
V_6 = F_19 ( V_44 , & V_44 , 16 ) ;
while ( * V_44 == ' ' )
V_44 ++ ;
if ( F_20 ( V_44 , 16 , & V_45 ) )
return - V_17 ;
F_21 ( V_46 ) ;
F_22 ( V_5 , V_6 , V_45 ) ;
return V_43 ;
}
static void F_23 ( struct V_4 * V_5 )
{
struct V_47 * V_48 = V_5 -> V_49 -> V_48 ;
V_5 -> V_50 = F_24 ( V_5 -> V_51 ,
V_48 ) ;
if ( ! V_5 -> V_50 ) {
F_25 ( V_52
L_4 ) ;
return;
}
F_26 ( L_5 , 0444 , V_5 -> V_50 ,
& V_5 -> V_53 ) ;
F_26 ( L_6 , 0444 , V_5 -> V_50 ,
& V_5 -> V_54 ) ;
V_5 -> V_55 = F_27 ( L_7 , 0644 ,
V_5 -> V_50 ,
V_5 , & V_56 ) ;
if ( ! V_5 -> V_55 )
F_25 ( V_52
L_8 ) ;
F_28 ( & V_5 -> V_57 , V_5 -> V_50 ) ;
}
static void F_29 ( struct V_4 * V_5 )
{
F_30 ( V_5 -> V_50 ) ;
}
static T_2 F_31 ( struct V_35 * V_35 , char T_4 * V_38 ,
T_1 V_18 , T_3 * V_39 )
{
char * V_7 = F_14 ( V_26 , V_40 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_4 * V_5 ;
if ( ! V_7 )
return - V_41 ;
F_32 (codec, &codec_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_26 - V_14 , L_9 ,
V_5 -> V_51 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_26 ) {
V_14 = V_26 ;
break;
}
}
if ( V_14 >= 0 )
V_14 = F_33 ( V_38 , V_18 , V_39 , V_7 , V_14 ) ;
F_16 ( V_7 ) ;
return V_14 ;
}
static T_2 F_34 ( struct V_35 * V_35 , char T_4 * V_38 ,
T_1 V_18 , T_3 * V_39 )
{
char * V_7 = F_14 ( V_26 , V_40 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_58 * V_59 ;
if ( ! V_7 )
return - V_41 ;
F_32 (dai, &dai_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_26 - V_14 , L_9 , V_59 -> V_51 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_26 ) {
V_14 = V_26 ;
break;
}
}
V_14 = F_33 ( V_38 , V_18 , V_39 , V_7 , V_14 ) ;
F_16 ( V_7 ) ;
return V_14 ;
}
static T_2 F_35 ( struct V_35 * V_35 ,
char T_4 * V_38 ,
T_1 V_18 , T_3 * V_39 )
{
char * V_7 = F_14 ( V_26 , V_40 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_60 * V_61 ;
if ( ! V_7 )
return - V_41 ;
F_32 (platform, &platform_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_26 - V_14 , L_9 ,
V_61 -> V_51 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_26 ) {
V_14 = V_26 ;
break;
}
}
V_14 = F_33 ( V_38 , V_18 , V_39 , V_7 , V_14 ) ;
F_16 ( V_7 ) ;
return V_14 ;
}
static void F_36 ( struct V_62 * V_49 )
{
V_49 -> V_48 = F_24 ( V_49 -> V_51 ,
V_63 ) ;
if ( ! V_49 -> V_48 ) {
F_37 ( V_49 -> V_28 ,
L_4 ) ;
return;
}
V_49 -> V_64 = F_38 ( L_10 , 0644 ,
V_49 -> V_48 ,
& V_49 -> V_65 ) ;
if ( ! V_49 -> V_64 )
F_37 ( V_49 -> V_28 ,
L_11 ) ;
}
static void F_39 ( struct V_62 * V_49 )
{
F_30 ( V_49 -> V_48 ) ;
}
static inline void F_23 ( struct V_4 * V_5 )
{
}
static inline void F_29 ( struct V_4 * V_5 )
{
}
static inline void F_36 ( struct V_62 * V_49 )
{
}
static inline void F_39 ( struct V_62 * V_49 )
{
}
static int F_40 ( struct V_4 * V_5 )
{
if ( V_5 -> V_66 -> V_28 . V_67 )
F_41 ( & V_5 -> V_66 -> V_28 ) ;
return 0 ;
}
static void F_42 ( struct V_27 * V_28 ) {}
static int F_43 ( struct V_4 * V_5 )
{
int V_68 ;
V_5 -> V_66 -> V_28 . V_67 = & V_69 ;
V_5 -> V_66 -> V_28 . V_70 = V_5 -> V_49 -> V_28 ;
V_5 -> V_66 -> V_28 . V_71 = F_42 ;
F_44 ( & V_5 -> V_66 -> V_28 , L_12 ,
V_5 -> V_49 -> V_72 -> V_73 , 0 , V_5 -> V_51 ) ;
V_68 = F_45 ( & V_5 -> V_66 -> V_28 ) ;
if ( V_68 < 0 ) {
F_46 ( V_74 L_13 ) ;
V_5 -> V_66 -> V_28 . V_67 = NULL ;
return V_68 ;
}
return 0 ;
}
int F_47 ( struct V_27 * V_28 )
{
struct V_62 * V_49 = F_48 ( V_28 ) ;
struct V_4 * V_5 ;
int V_3 ;
if ( F_49 ( & V_49 -> V_75 ) )
return 0 ;
F_50 ( V_49 -> V_72 ) ;
F_51 ( V_49 -> V_72 , V_76 ) ;
F_52 ( V_49 -> V_72 ) ;
F_53 ( V_49 -> V_72 , V_77 ) ;
for ( V_3 = 0 ; V_3 < V_49 -> V_78 ; V_3 ++ ) {
struct V_58 * V_59 = V_49 -> V_32 [ V_3 ] . V_79 ;
struct V_80 * V_81 = V_59 -> V_10 ;
if ( V_49 -> V_32 [ V_3 ] . V_82 -> V_83 )
continue;
if ( V_81 -> V_84 -> V_85 && V_59 -> V_86 )
V_81 -> V_84 -> V_85 ( V_59 , 1 ) ;
}
for ( V_3 = 0 ; V_3 < V_49 -> V_78 ; V_3 ++ ) {
if ( V_49 -> V_32 [ V_3 ] . V_82 -> V_83 )
continue;
F_54 ( V_49 -> V_32 [ V_3 ] . V_87 ) ;
}
if ( V_49 -> V_88 )
V_49 -> V_88 ( V_49 ) ;
for ( V_3 = 0 ; V_3 < V_49 -> V_78 ; V_3 ++ ) {
struct V_58 * V_89 = V_49 -> V_32 [ V_3 ] . V_89 ;
struct V_60 * V_61 = V_49 -> V_32 [ V_3 ] . V_61 ;
if ( V_49 -> V_32 [ V_3 ] . V_82 -> V_83 )
continue;
if ( V_89 -> V_10 -> V_90 && ! V_89 -> V_10 -> V_91 )
V_89 -> V_10 -> V_90 ( V_89 ) ;
if ( V_61 -> V_10 -> V_90 && ! V_61 -> V_92 ) {
V_61 -> V_10 -> V_90 ( V_89 ) ;
V_61 -> V_92 = 1 ;
}
}
for ( V_3 = 0 ; V_3 < V_49 -> V_78 ; V_3 ++ ) {
F_55 ( & V_49 -> V_32 [ V_3 ] . V_93 ) ;
V_49 -> V_32 [ V_3 ] . V_5 -> V_57 . V_94 = V_49 -> V_32 [ V_3 ] . V_5 -> V_57 . V_95 ;
}
for ( V_3 = 0 ; V_3 < V_49 -> V_78 ; V_3 ++ ) {
struct V_80 * V_10 = V_49 -> V_32 [ V_3 ] . V_79 -> V_10 ;
if ( V_49 -> V_32 [ V_3 ] . V_82 -> V_83 )
continue;
if ( V_10 -> V_96 . V_97 != NULL )
F_56 ( & V_49 -> V_32 [ V_3 ] , V_10 -> V_96 . V_97 ,
V_98 ) ;
if ( V_10 -> V_99 . V_97 != NULL )
F_56 ( & V_49 -> V_32 [ V_3 ] , V_10 -> V_99 . V_97 ,
V_98 ) ;
}
F_32 (codec, &card->codec_dev_list, card_list) {
if ( ! V_5 -> V_92 && V_5 -> V_10 -> V_90 ) {
switch ( V_5 -> V_57 . V_95 ) {
case V_100 :
case V_101 :
V_5 -> V_10 -> V_90 ( V_5 , V_102 ) ;
V_5 -> V_92 = 1 ;
V_5 -> V_53 = 1 ;
break;
default:
F_57 ( V_5 -> V_28 , L_14 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_49 -> V_78 ; V_3 ++ ) {
struct V_58 * V_89 = V_49 -> V_32 [ V_3 ] . V_89 ;
if ( V_49 -> V_32 [ V_3 ] . V_82 -> V_83 )
continue;
if ( V_89 -> V_10 -> V_90 && V_89 -> V_10 -> V_91 )
V_89 -> V_10 -> V_90 ( V_89 ) ;
}
if ( V_49 -> V_103 )
V_49 -> V_103 ( V_49 ) ;
return 0 ;
}
static void F_58 ( struct V_104 * V_105 )
{
struct V_62 * V_49 =
F_8 ( V_105 , struct V_62 , V_106 ) ;
struct V_4 * V_5 ;
int V_3 ;
F_57 ( V_49 -> V_28 , L_15 ) ;
F_53 ( V_49 -> V_72 , V_107 ) ;
if ( V_49 -> V_108 )
V_49 -> V_108 ( V_49 ) ;
for ( V_3 = 0 ; V_3 < V_49 -> V_78 ; V_3 ++ ) {
struct V_58 * V_89 = V_49 -> V_32 [ V_3 ] . V_89 ;
if ( V_49 -> V_32 [ V_3 ] . V_82 -> V_83 )
continue;
if ( V_89 -> V_10 -> V_109 && V_89 -> V_10 -> V_91 )
V_89 -> V_10 -> V_109 ( V_89 ) ;
}
F_32 (codec, &card->codec_dev_list, card_list) {
if ( V_5 -> V_10 -> V_109 && V_5 -> V_92 ) {
switch ( V_5 -> V_57 . V_95 ) {
case V_100 :
case V_101 :
V_5 -> V_10 -> V_109 ( V_5 ) ;
V_5 -> V_92 = 0 ;
break;
default:
F_57 ( V_5 -> V_28 , L_16 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_49 -> V_78 ; V_3 ++ ) {
struct V_80 * V_10 = V_49 -> V_32 [ V_3 ] . V_79 -> V_10 ;
if ( V_49 -> V_32 [ V_3 ] . V_82 -> V_83 )
continue;
if ( V_10 -> V_96 . V_97 != NULL )
F_56 ( & V_49 -> V_32 [ V_3 ] , V_10 -> V_96 . V_97 ,
V_110 ) ;
if ( V_10 -> V_99 . V_97 != NULL )
F_56 ( & V_49 -> V_32 [ V_3 ] , V_10 -> V_99 . V_97 ,
V_110 ) ;
}
for ( V_3 = 0 ; V_3 < V_49 -> V_78 ; V_3 ++ ) {
struct V_58 * V_59 = V_49 -> V_32 [ V_3 ] . V_79 ;
struct V_80 * V_81 = V_59 -> V_10 ;
if ( V_49 -> V_32 [ V_3 ] . V_82 -> V_83 )
continue;
if ( V_81 -> V_84 -> V_85 && V_59 -> V_86 )
V_81 -> V_84 -> V_85 ( V_59 , 0 ) ;
}
for ( V_3 = 0 ; V_3 < V_49 -> V_78 ; V_3 ++ ) {
struct V_58 * V_89 = V_49 -> V_32 [ V_3 ] . V_89 ;
struct V_60 * V_61 = V_49 -> V_32 [ V_3 ] . V_61 ;
if ( V_49 -> V_32 [ V_3 ] . V_82 -> V_83 )
continue;
if ( V_89 -> V_10 -> V_109 && ! V_89 -> V_10 -> V_91 )
V_89 -> V_10 -> V_109 ( V_89 ) ;
if ( V_61 -> V_10 -> V_109 && V_61 -> V_92 ) {
V_61 -> V_10 -> V_109 ( V_89 ) ;
V_61 -> V_92 = 0 ;
}
}
if ( V_49 -> V_111 )
V_49 -> V_111 ( V_49 ) ;
F_57 ( V_49 -> V_28 , L_17 ) ;
F_53 ( V_49 -> V_72 , V_76 ) ;
}
int F_59 ( struct V_27 * V_28 )
{
struct V_62 * V_49 = F_48 ( V_28 ) ;
int V_3 , V_91 = 0 ;
for ( V_3 = 0 ; V_3 < V_49 -> V_78 ; V_3 ++ ) {
struct V_58 * V_89 = V_49 -> V_32 [ V_3 ] . V_89 ;
V_91 |= V_89 -> V_10 -> V_91 ;
}
if ( V_91 ) {
F_57 ( V_28 , L_18 ) ;
F_58 ( & V_49 -> V_106 ) ;
} else {
F_57 ( V_28 , L_19 ) ;
if ( ! F_60 ( & V_49 -> V_106 ) )
F_61 ( V_28 , L_20 ) ;
}
return 0 ;
}
static int F_62 ( struct V_62 * V_49 , int V_112 )
{
struct V_113 * V_82 = & V_49 -> V_82 [ V_112 ] ;
struct V_31 * V_32 = & V_49 -> V_32 [ V_112 ] ;
struct V_4 * V_5 ;
struct V_60 * V_61 ;
struct V_58 * V_79 , * V_89 ;
const char * V_114 ;
if ( V_32 -> V_115 )
return 1 ;
F_57 ( V_49 -> V_28 , L_21 , V_82 -> V_51 , V_112 ) ;
if ( V_32 -> V_89 ) {
goto V_116;
}
F_32 (cpu_dai, &dai_list, list) {
if ( ! strcmp ( V_89 -> V_51 , V_82 -> V_117 ) ) {
V_32 -> V_89 = V_89 ;
goto V_116;
}
}
F_57 ( V_49 -> V_28 , L_22 ,
V_82 -> V_117 ) ;
V_116:
if ( V_32 -> V_5 ) {
goto V_118;
}
F_32 (codec, &codec_list, list) {
if ( ! strcmp ( V_5 -> V_51 , V_82 -> V_119 ) ) {
V_32 -> V_5 = V_5 ;
F_32 (codec_dai, &dai_list, list) {
if ( V_5 -> V_28 == V_79 -> V_28 &&
! strcmp ( V_79 -> V_51 , V_82 -> V_120 ) ) {
V_32 -> V_79 = V_79 ;
goto V_118;
}
}
F_57 ( V_49 -> V_28 , L_23 ,
V_82 -> V_120 ) ;
goto V_118;
}
}
F_57 ( V_49 -> V_28 , L_24 ,
V_82 -> V_119 ) ;
V_118:
if ( V_32 -> V_61 )
goto V_121;
V_114 = V_82 -> V_114 ;
if ( ! V_114 )
V_114 = L_25 ;
F_32 (platform, &platform_list, list) {
if ( ! strcmp ( V_61 -> V_51 , V_114 ) ) {
V_32 -> V_61 = V_61 ;
goto V_121;
}
}
F_57 ( V_49 -> V_28 , L_26 ,
V_82 -> V_114 ) ;
return 0 ;
V_121:
if ( V_32 -> V_5 && V_32 -> V_79 && V_32 -> V_61 && V_32 -> V_89 ) {
V_32 -> V_115 = 1 ;
V_49 -> V_78 ++ ;
}
return 1 ;
}
static void F_63 ( struct V_4 * V_5 )
{
int V_68 ;
if ( V_5 -> V_10 -> remove ) {
V_68 = V_5 -> V_10 -> remove ( V_5 ) ;
if ( V_68 < 0 )
F_61 ( V_5 -> V_28 ,
L_27 ,
V_5 -> V_51 , V_68 ) ;
}
F_64 ( & V_5 -> V_57 ) ;
F_29 ( V_5 ) ;
V_5 -> V_122 = 0 ;
F_65 ( & V_5 -> V_123 ) ;
F_66 ( V_5 -> V_28 -> V_10 -> V_124 ) ;
}
static void F_67 ( struct V_62 * V_49 , int V_112 , int V_125 )
{
struct V_31 * V_32 = & V_49 -> V_32 [ V_112 ] ;
struct V_4 * V_5 = V_32 -> V_5 ;
struct V_60 * V_61 = V_32 -> V_61 ;
struct V_58 * V_79 = V_32 -> V_79 , * V_89 = V_32 -> V_89 ;
int V_68 ;
if ( V_32 -> V_126 ) {
F_68 ( & V_32 -> V_28 , & V_127 ) ;
F_68 ( & V_32 -> V_28 , & V_128 ) ;
F_41 ( & V_32 -> V_28 ) ;
V_32 -> V_126 = 0 ;
}
if ( V_79 && V_79 -> V_122 &&
V_79 -> V_10 -> V_129 == V_125 ) {
if ( V_79 -> V_10 -> remove ) {
V_68 = V_79 -> V_10 -> remove ( V_79 ) ;
if ( V_68 < 0 )
F_25 ( V_74 L_28 , V_79 -> V_51 ) ;
}
V_79 -> V_122 = 0 ;
F_65 ( & V_79 -> V_123 ) ;
}
if ( V_61 && V_61 -> V_122 &&
V_61 -> V_10 -> V_129 == V_125 ) {
if ( V_61 -> V_10 -> remove ) {
V_68 = V_61 -> V_10 -> remove ( V_61 ) ;
if ( V_68 < 0 )
F_25 ( V_74 L_28 , V_61 -> V_51 ) ;
}
V_61 -> V_122 = 0 ;
F_65 ( & V_61 -> V_123 ) ;
F_66 ( V_61 -> V_28 -> V_10 -> V_124 ) ;
}
if ( V_5 && V_5 -> V_122 &&
V_5 -> V_10 -> V_129 == V_125 )
F_63 ( V_5 ) ;
if ( V_89 && V_89 -> V_122 &&
V_89 -> V_10 -> V_129 == V_125 ) {
if ( V_89 -> V_10 -> remove ) {
V_68 = V_89 -> V_10 -> remove ( V_89 ) ;
if ( V_68 < 0 )
F_25 ( V_74 L_28 , V_89 -> V_51 ) ;
}
V_89 -> V_122 = 0 ;
F_65 ( & V_89 -> V_123 ) ;
F_66 ( V_89 -> V_28 -> V_10 -> V_124 ) ;
}
}
static void F_69 ( struct V_62 * V_49 )
{
int V_59 , V_125 ;
for ( V_125 = V_130 ; V_125 <= V_131 ;
V_125 ++ ) {
for ( V_59 = 0 ; V_59 < V_49 -> V_78 ; V_59 ++ )
F_67 ( V_49 , V_59 , V_125 ) ;
}
V_49 -> V_78 = 0 ;
}
static void F_70 ( struct V_62 * V_49 ,
struct V_4 * V_5 )
{
int V_3 ;
if ( V_49 -> V_132 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_49 -> V_133 ; V_3 ++ ) {
struct V_134 * V_135 = & V_49 -> V_132 [ V_3 ] ;
if ( V_135 -> V_136 && ! strcmp ( V_5 -> V_51 , V_135 -> V_136 ) ) {
V_5 -> V_137 = V_135 -> V_137 ;
break;
}
}
}
static int F_71 ( struct V_62 * V_49 ,
struct V_4 * V_5 )
{
int V_14 = 0 ;
const struct V_138 * V_10 = V_5 -> V_10 ;
V_5 -> V_49 = V_49 ;
V_5 -> V_57 . V_49 = V_49 ;
F_70 ( V_49 , V_5 ) ;
if ( ! F_72 ( V_5 -> V_28 -> V_10 -> V_124 ) )
return - V_139 ;
F_23 ( V_5 ) ;
if ( V_10 -> V_140 )
F_73 ( & V_5 -> V_57 , V_10 -> V_140 ,
V_10 -> V_141 ) ;
if ( V_10 -> V_142 ) {
V_14 = V_10 -> V_142 ( V_5 ) ;
if ( V_14 < 0 ) {
F_61 ( V_5 -> V_28 ,
L_29 ,
V_5 -> V_51 , V_14 ) ;
goto V_143;
}
}
if ( V_10 -> V_144 )
F_74 ( V_5 , V_10 -> V_144 ,
V_10 -> V_145 ) ;
if ( V_10 -> V_146 )
F_75 ( & V_5 -> V_57 , V_10 -> V_146 ,
V_10 -> V_147 ) ;
V_5 -> V_122 = 1 ;
F_76 ( & V_5 -> V_123 , & V_49 -> V_75 ) ;
F_76 ( & V_5 -> V_57 . V_148 , & V_49 -> V_149 ) ;
return 0 ;
V_143:
F_29 ( V_5 ) ;
F_66 ( V_5 -> V_28 -> V_10 -> V_124 ) ;
return V_14 ;
}
static int F_77 ( struct V_62 * V_49 ,
struct V_60 * V_61 )
{
int V_14 = 0 ;
const struct V_150 * V_10 = V_61 -> V_10 ;
V_61 -> V_49 = V_49 ;
V_61 -> V_57 . V_49 = V_49 ;
if ( ! F_72 ( V_61 -> V_28 -> V_10 -> V_124 ) )
return - V_139 ;
if ( V_10 -> V_140 )
F_73 ( & V_61 -> V_57 ,
V_10 -> V_140 , V_10 -> V_141 ) ;
if ( V_10 -> V_142 ) {
V_14 = V_10 -> V_142 ( V_61 ) ;
if ( V_14 < 0 ) {
F_61 ( V_61 -> V_28 ,
L_30 ,
V_61 -> V_51 , V_14 ) ;
goto V_143;
}
}
if ( V_10 -> V_144 )
F_78 ( V_61 , V_10 -> V_144 ,
V_10 -> V_145 ) ;
if ( V_10 -> V_146 )
F_75 ( & V_61 -> V_57 , V_10 -> V_146 ,
V_10 -> V_147 ) ;
V_61 -> V_122 = 1 ;
F_76 ( & V_61 -> V_123 , & V_49 -> V_151 ) ;
F_76 ( & V_61 -> V_57 . V_148 , & V_49 -> V_149 ) ;
return 0 ;
V_143:
F_66 ( V_61 -> V_28 -> V_10 -> V_124 ) ;
return V_14 ;
}
static void F_79 ( struct V_27 * V_28 ) {}
static int F_80 ( struct V_62 * V_49 ,
struct V_4 * V_5 ,
int V_112 , int V_152 )
{
struct V_113 * V_82 = NULL ;
struct V_153 * V_154 = NULL ;
struct V_31 * V_32 ;
const char * V_155 , * V_51 ;
int V_14 = 0 ;
if ( ! V_152 ) {
V_82 = & V_49 -> V_82 [ V_112 ] ;
V_32 = & V_49 -> V_32 [ V_112 ] ;
V_51 = V_82 -> V_51 ;
} else {
V_154 = & V_49 -> V_154 [ V_112 ] ;
V_32 = & V_49 -> V_156 [ V_112 ] ;
V_51 = V_154 -> V_51 ;
}
V_32 -> V_49 = V_49 ;
V_155 = V_5 -> V_137 ;
V_5 -> V_137 = NULL ;
if ( ! V_152 && V_82 -> V_157 )
V_14 = V_82 -> V_157 ( V_32 ) ;
else if ( V_152 && V_154 -> V_157 )
V_14 = V_154 -> V_157 ( & V_5 -> V_57 ) ;
if ( V_14 < 0 ) {
F_61 ( V_49 -> V_28 , L_31 , V_51 , V_14 ) ;
return V_14 ;
}
V_5 -> V_137 = V_155 ;
F_81 ( & V_5 -> V_57 ) ;
V_32 -> V_5 = V_5 ;
V_32 -> V_28 . V_70 = V_49 -> V_28 ;
V_32 -> V_28 . V_71 = F_79 ;
V_32 -> V_28 . V_158 = V_51 ;
F_82 ( & V_32 -> V_159 ) ;
V_14 = F_45 ( & V_32 -> V_28 ) ;
if ( V_14 < 0 ) {
F_61 ( V_49 -> V_28 ,
L_32 , V_14 ) ;
return V_14 ;
}
V_32 -> V_126 = 1 ;
V_14 = F_83 ( & V_32 -> V_28 ) ;
if ( V_14 < 0 )
F_61 ( V_5 -> V_28 ,
L_33 ,
V_14 ) ;
V_14 = F_84 ( & V_32 -> V_28 , & V_128 ) ;
if ( V_14 < 0 )
F_61 ( V_5 -> V_28 ,
L_34 , V_14 ) ;
return 0 ;
}
static int F_85 ( struct V_62 * V_49 , int V_112 , int V_125 )
{
struct V_113 * V_82 = & V_49 -> V_82 [ V_112 ] ;
struct V_31 * V_32 = & V_49 -> V_32 [ V_112 ] ;
struct V_4 * V_5 = V_32 -> V_5 ;
struct V_60 * V_61 = V_32 -> V_61 ;
struct V_58 * V_79 = V_32 -> V_79 , * V_89 = V_32 -> V_89 ;
int V_14 ;
F_57 ( V_49 -> V_28 , L_35 ,
V_49 -> V_51 , V_112 , V_125 ) ;
V_79 -> V_5 = V_5 ;
V_89 -> V_61 = V_61 ;
V_79 -> V_49 = V_49 ;
V_89 -> V_49 = V_49 ;
V_32 -> V_33 = V_33 ;
if ( ! V_89 -> V_122 &&
V_89 -> V_10 -> V_160 == V_125 ) {
if ( ! F_72 ( V_89 -> V_28 -> V_10 -> V_124 ) )
return - V_139 ;
if ( V_89 -> V_10 -> V_142 ) {
V_14 = V_89 -> V_10 -> V_142 ( V_89 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_36 ,
V_89 -> V_51 ) ;
F_66 ( V_89 -> V_28 -> V_10 -> V_124 ) ;
return V_14 ;
}
}
V_89 -> V_122 = 1 ;
F_76 ( & V_89 -> V_123 , & V_49 -> V_161 ) ;
}
if ( ! V_5 -> V_122 &&
V_5 -> V_10 -> V_160 == V_125 ) {
V_14 = F_71 ( V_49 , V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_61 -> V_122 &&
V_61 -> V_10 -> V_160 == V_125 ) {
V_14 = F_77 ( V_49 , V_61 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_79 -> V_122 && V_79 -> V_10 -> V_160 == V_125 ) {
if ( V_79 -> V_10 -> V_142 ) {
V_14 = V_79 -> V_10 -> V_142 ( V_79 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_37 ,
V_79 -> V_51 ) ;
return V_14 ;
}
}
V_79 -> V_122 = 1 ;
F_76 ( & V_79 -> V_123 , & V_49 -> V_161 ) ;
}
if ( V_125 != V_131 )
return 0 ;
V_14 = F_80 ( V_49 , V_5 , V_112 , 0 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_84 ( & V_32 -> V_28 , & V_127 ) ;
if ( V_14 < 0 )
F_25 ( V_52 L_38 ) ;
V_14 = F_86 ( V_32 , V_112 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_39 , V_82 -> V_97 ) ;
return V_14 ;
}
if ( V_32 -> V_79 -> V_10 -> V_91 )
F_87 ( V_5 -> V_66 , V_32 -> V_89 -> V_162 ) ;
return 0 ;
}
static int F_88 ( struct V_31 * V_32 )
{
int V_14 ;
if ( V_32 -> V_79 -> V_10 -> V_91 && ! V_32 -> V_5 -> V_163 ) {
if ( ! V_32 -> V_5 -> V_164 )
return 0 ;
V_14 = F_43 ( V_32 -> V_5 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_40 ) ;
return V_14 ;
}
V_32 -> V_5 -> V_163 = 1 ;
}
return 0 ;
}
static void F_89 ( struct V_4 * V_5 )
{
if ( V_5 -> V_163 ) {
F_40 ( V_5 ) ;
V_5 -> V_163 = 0 ;
}
}
static int F_90 ( struct V_62 * V_49 , int V_112 )
{
struct V_153 * V_154 = & V_49 -> V_154 [ V_112 ] ;
struct V_4 * V_5 ;
int V_14 = - V_139 ;
F_32 (codec, &codec_list, list) {
if ( ! strcmp ( V_5 -> V_51 , V_154 -> V_119 ) ) {
if ( V_5 -> V_122 ) {
F_61 ( V_5 -> V_28 ,
L_41 ) ;
V_14 = - V_165 ;
goto V_121;
}
goto V_166;
}
}
F_61 ( V_49 -> V_28 , L_42 , V_154 -> V_119 ) ;
goto V_121;
V_166:
V_14 = F_71 ( V_49 , V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_80 ( V_49 , V_5 , V_112 , 1 ) ;
V_121:
return V_14 ;
}
static void F_91 ( struct V_62 * V_49 , int V_112 )
{
struct V_31 * V_32 = & V_49 -> V_156 [ V_112 ] ;
struct V_4 * V_5 = V_32 -> V_5 ;
if ( V_32 -> V_126 ) {
F_68 ( & V_32 -> V_28 , & V_128 ) ;
F_41 ( & V_32 -> V_28 ) ;
V_32 -> V_126 = 0 ;
}
if ( V_5 && V_5 -> V_122 )
F_63 ( V_5 ) ;
}
static int F_92 ( struct V_4 * V_5 ,
enum V_167 V_168 )
{
int V_14 ;
if ( V_5 -> V_169 )
return 0 ;
if ( V_168 && V_5 -> V_168 != V_168 )
V_5 -> V_168 = V_168 ;
V_14 = F_93 ( V_5 ) ;
if ( V_14 < 0 ) {
F_61 ( V_5 -> V_28 , L_43 ,
V_14 ) ;
return V_14 ;
}
V_5 -> V_169 = 1 ;
return 0 ;
}
static void F_94 ( struct V_62 * V_49 )
{
struct V_4 * V_5 ;
struct V_134 * V_132 ;
enum V_167 V_168 ;
int V_14 , V_3 , V_125 ;
F_95 ( & V_49 -> V_170 ) ;
if ( V_49 -> V_171 ) {
F_96 ( & V_49 -> V_170 ) ;
return;
}
for ( V_3 = 0 ; V_3 < V_49 -> V_172 ; V_3 ++ )
F_62 ( V_49 , V_3 ) ;
if ( V_49 -> V_78 != V_49 -> V_172 ) {
F_96 ( & V_49 -> V_170 ) ;
return;
}
F_32 (codec, &codec_list, list) {
if ( V_5 -> V_169 )
continue;
V_168 = 0 ;
for ( V_3 = 0 ; V_3 < V_49 -> V_133 ; ++ V_3 ) {
V_132 = & V_49 -> V_132 [ V_3 ] ;
if ( ! strcmp ( V_5 -> V_51 , V_132 -> V_136 ) ) {
V_168 = V_132 -> V_168 ;
if ( V_168 && V_168
!= V_5 -> V_168 )
break;
}
}
V_14 = F_92 ( V_5 , V_168 ) ;
if ( V_14 < 0 ) {
F_96 ( & V_49 -> V_170 ) ;
return;
}
}
V_14 = F_97 ( V_173 , V_174 ,
V_49 -> V_124 , 0 , & V_49 -> V_72 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_44 ,
V_49 -> V_51 ) ;
F_96 ( & V_49 -> V_170 ) ;
return;
}
V_49 -> V_72 -> V_28 = V_49 -> V_28 ;
V_49 -> V_57 . V_95 = V_101 ;
V_49 -> V_57 . V_28 = V_49 -> V_28 ;
V_49 -> V_57 . V_49 = V_49 ;
F_76 ( & V_49 -> V_57 . V_148 , & V_49 -> V_149 ) ;
#ifdef F_98
F_28 ( & V_49 -> V_57 , V_49 -> V_48 ) ;
#endif
#ifdef F_99
F_100 ( & V_49 -> V_106 , F_58 ) ;
#endif
if ( V_49 -> V_140 )
F_73 ( & V_49 -> V_57 , V_49 -> V_140 ,
V_49 -> V_141 ) ;
if ( V_49 -> V_142 ) {
V_14 = V_49 -> V_142 ( V_49 ) ;
if ( V_14 < 0 )
goto V_175;
}
for ( V_125 = V_130 ; V_125 <= V_131 ;
V_125 ++ ) {
for ( V_3 = 0 ; V_3 < V_49 -> V_172 ; V_3 ++ ) {
V_14 = F_85 ( V_49 , V_3 , V_125 ) ;
if ( V_14 < 0 ) {
F_101 ( L_45 ,
V_49 -> V_51 , V_14 ) ;
goto V_176;
}
}
}
for ( V_3 = 0 ; V_3 < V_49 -> V_177 ; V_3 ++ ) {
V_14 = F_90 ( V_49 , V_3 ) ;
if ( V_14 < 0 ) {
F_101 ( L_46 ,
V_49 -> V_51 , V_14 ) ;
goto V_178;
}
}
if ( V_49 -> V_144 )
F_74 ( F_102 ( & V_49 -> V_75 ,
struct V_4 ,
V_123 ) ,
V_49 -> V_144 ,
V_49 -> V_145 ) ;
if ( V_49 -> V_146 )
F_75 ( & V_49 -> V_57 , V_49 -> V_146 ,
V_49 -> V_147 ) ;
snprintf ( V_49 -> V_72 -> V_179 , sizeof( V_49 -> V_72 -> V_179 ) ,
L_47 , V_49 -> V_51 ) ;
snprintf ( V_49 -> V_72 -> V_180 , sizeof( V_49 -> V_72 -> V_180 ) ,
L_47 , V_49 -> V_181 ? V_49 -> V_181 : V_49 -> V_51 ) ;
snprintf ( V_49 -> V_72 -> V_10 , sizeof( V_49 -> V_72 -> V_10 ) ,
L_47 , V_49 -> V_182 ? V_49 -> V_182 : V_49 -> V_51 ) ;
for ( V_3 = 0 ; V_3 < F_103 ( V_49 -> V_72 -> V_10 ) ; V_3 ++ ) {
switch ( V_49 -> V_72 -> V_10 [ V_3 ] ) {
case '_' :
case '-' :
case '\0' :
break;
default:
if ( ! isalnum ( V_49 -> V_72 -> V_10 [ V_3 ] ) )
V_49 -> V_72 -> V_10 [ V_3 ] = '_' ;
break;
}
}
if ( V_49 -> V_183 ) {
V_14 = V_49 -> V_183 ( V_49 ) ;
if ( V_14 < 0 ) {
F_61 ( V_49 -> V_28 , L_48 ,
V_49 -> V_51 , V_14 ) ;
goto V_178;
}
}
V_14 = F_104 ( V_49 -> V_72 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_49 , V_49 -> V_51 ) ;
goto V_178;
}
#ifdef F_105
for ( V_3 = 0 ; V_3 < V_49 -> V_78 ; V_3 ++ ) {
V_14 = F_88 ( & V_49 -> V_32 [ V_3 ] ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_50 , V_49 -> V_51 ) ;
while ( -- V_3 >= 0 )
F_89 ( V_49 -> V_32 [ V_3 ] . V_5 ) ;
goto V_178;
}
}
#endif
V_49 -> V_171 = 1 ;
F_96 ( & V_49 -> V_170 ) ;
return;
V_178:
for ( V_3 = 0 ; V_3 < V_49 -> V_177 ; V_3 ++ )
F_91 ( V_49 , V_3 ) ;
V_176:
F_69 ( V_49 ) ;
V_175:
if ( V_49 -> remove )
V_49 -> remove ( V_49 ) ;
F_106 ( V_49 -> V_72 ) ;
F_96 ( & V_49 -> V_170 ) ;
}
static void F_107 ( void )
{
struct V_62 * V_49 ;
F_32 (card, &card_list, list)
F_94 ( V_49 ) ;
}
static int F_108 ( struct V_184 * V_185 )
{
struct V_62 * V_49 = F_109 ( V_185 ) ;
int V_14 = 0 ;
if ( ! V_49 )
return - V_17 ;
V_49 -> V_28 = & V_185 -> V_28 ;
V_14 = F_110 ( V_49 ) ;
if ( V_14 != 0 ) {
F_61 ( & V_185 -> V_28 , L_51 ) ;
return V_14 ;
}
return 0 ;
}
static int F_111 ( struct V_62 * V_49 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_49 -> V_78 ; V_3 ++ ) {
struct V_31 * V_32 = & V_49 -> V_32 [ V_3 ] ;
F_55 ( & V_32 -> V_93 ) ;
}
for ( V_3 = 0 ; V_3 < V_49 -> V_177 ; V_3 ++ )
F_91 ( V_49 , V_3 ) ;
F_69 ( V_49 ) ;
F_39 ( V_49 ) ;
if ( V_49 -> remove )
V_49 -> remove ( V_49 ) ;
F_64 ( & V_49 -> V_57 ) ;
F_16 ( V_49 -> V_32 ) ;
F_106 ( V_49 -> V_72 ) ;
return 0 ;
}
static int F_112 ( struct V_184 * V_185 )
{
struct V_62 * V_49 = F_109 ( V_185 ) ;
F_113 ( V_49 ) ;
return 0 ;
}
int F_114 ( struct V_27 * V_28 )
{
struct V_62 * V_49 = F_48 ( V_28 ) ;
int V_3 ;
if ( ! V_49 -> V_171 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_49 -> V_78 ; V_3 ++ ) {
struct V_31 * V_32 = & V_49 -> V_32 [ V_3 ] ;
F_55 ( & V_32 -> V_93 ) ;
}
F_115 ( V_49 ) ;
return 0 ;
}
int F_116 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_186 )
return V_5 -> V_186 ( V_5 , V_6 ) ;
else
return 0 ;
}
int F_117 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_24 )
return V_5 -> V_24 ( V_5 , V_6 ) ;
else
return 1 ;
}
int F_118 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_187 )
return V_5 -> V_187 ( V_5 , V_6 ) ;
else
return 1 ;
}
int F_119 ( struct V_60 * V_61 ,
unsigned int V_6 )
{
unsigned int V_14 ;
if ( ! V_61 -> V_10 -> V_188 ) {
F_61 ( V_61 -> V_28 , L_52 ) ;
return - 1 ;
}
V_14 = V_61 -> V_10 -> V_188 ( V_61 , V_6 ) ;
F_57 ( V_61 -> V_28 , L_53 , V_6 , V_14 ) ;
F_120 ( V_61 , V_6 , V_14 ) ;
return V_14 ;
}
int F_121 ( struct V_60 * V_61 ,
unsigned int V_6 , unsigned int V_1 )
{
if ( ! V_61 -> V_10 -> V_189 ) {
F_61 ( V_61 -> V_28 , L_54 ) ;
return - 1 ;
}
F_57 ( V_61 -> V_28 , L_55 , V_6 , V_1 ) ;
F_122 ( V_61 , V_6 , V_1 ) ;
return V_61 -> V_10 -> V_189 ( V_61 , V_6 , V_1 ) ;
}
int F_123 ( struct V_4 * V_5 ,
struct V_190 * V_84 , int V_112 )
{
F_95 ( & V_5 -> V_170 ) ;
V_5 -> V_66 = F_124 ( sizeof( struct V_191 ) , V_40 ) ;
if ( V_5 -> V_66 == NULL ) {
F_96 ( & V_5 -> V_170 ) ;
return - V_41 ;
}
V_5 -> V_66 -> V_67 = F_124 ( sizeof( struct V_192 ) , V_40 ) ;
if ( V_5 -> V_66 -> V_67 == NULL ) {
F_16 ( V_5 -> V_66 ) ;
V_5 -> V_66 = NULL ;
F_96 ( & V_5 -> V_170 ) ;
return - V_41 ;
}
V_5 -> V_66 -> V_67 -> V_84 = V_84 ;
V_5 -> V_66 -> V_112 = V_112 ;
V_5 -> V_164 = 1 ;
F_96 ( & V_5 -> V_170 ) ;
return 0 ;
}
void F_125 ( struct V_4 * V_5 )
{
F_95 ( & V_5 -> V_170 ) ;
#ifdef F_105
F_89 ( V_5 ) ;
#endif
F_16 ( V_5 -> V_66 -> V_67 ) ;
F_16 ( V_5 -> V_66 ) ;
V_5 -> V_66 = NULL ;
V_5 -> V_164 = 0 ;
F_96 ( & V_5 -> V_170 ) ;
}
unsigned int F_4 ( struct V_4 * V_5 , unsigned int V_6 )
{
unsigned int V_14 ;
V_14 = V_5 -> V_188 ( V_5 , V_6 ) ;
F_57 ( V_5 -> V_28 , L_53 , V_6 , V_14 ) ;
F_126 ( V_5 , V_6 , V_14 ) ;
return V_14 ;
}
unsigned int F_22 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned int V_1 )
{
F_57 ( V_5 -> V_28 , L_55 , V_6 , V_1 ) ;
F_127 ( V_5 , V_6 , V_1 ) ;
return V_5 -> V_189 ( V_5 , V_6 , V_1 ) ;
}
unsigned int F_128 ( struct V_4 * V_5 ,
unsigned int V_6 , const void * V_193 , T_1 V_8 )
{
return V_5 -> V_194 ( V_5 , V_6 , V_193 , V_8 ) ;
}
int F_129 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_195 , unsigned int V_45 )
{
int V_196 ;
unsigned int V_197 , V_198 ;
int V_14 ;
V_14 = F_4 ( V_5 , V_6 ) ;
if ( V_14 < 0 )
return V_14 ;
V_197 = V_14 ;
V_198 = ( V_197 & ~ V_195 ) | ( V_45 & V_195 ) ;
V_196 = V_197 != V_198 ;
if ( V_196 ) {
V_14 = F_22 ( V_5 , V_6 , V_198 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return V_196 ;
}
int F_130 ( struct V_4 * V_5 ,
unsigned short V_6 , unsigned int V_195 ,
unsigned int V_45 )
{
int V_196 ;
F_95 ( & V_5 -> V_170 ) ;
V_196 = F_129 ( V_5 , V_6 , V_195 , V_45 ) ;
F_96 ( & V_5 -> V_170 ) ;
return V_196 ;
}
int F_131 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_195 , unsigned int V_45 )
{
int V_196 ;
unsigned int V_197 , V_198 ;
V_197 = F_4 ( V_5 , V_6 ) ;
V_198 = ( V_197 & ~ V_195 ) | V_45 ;
V_196 = V_197 != V_198 ;
return V_196 ;
}
int F_132 ( struct V_199 * V_200 ,
const struct V_201 * V_202 )
{
struct V_203 * V_204 = V_200 -> V_204 ;
V_204 -> V_202 . V_205 = V_202 -> V_205 ;
V_204 -> V_202 . V_206 = V_202 -> V_206 ;
V_204 -> V_202 . V_207 = V_202 -> V_207 ;
V_204 -> V_202 . V_208 = V_202 -> V_208 ;
V_204 -> V_202 . V_209 = V_202 -> V_209 ;
V_204 -> V_202 . V_210 = V_202 -> V_210 ;
V_204 -> V_202 . V_211 = V_202 -> V_211 ;
V_204 -> V_202 . V_212 = V_202 -> V_212 ;
return 0 ;
}
struct V_213 * F_133 ( const struct V_214 * V_215 ,
void * V_193 , char * V_181 ,
const char * V_216 )
{
struct V_214 V_217 ;
struct V_213 * V_218 ;
char * V_51 = NULL ;
int V_219 ;
memcpy ( & V_217 , V_215 , sizeof( V_217 ) ) ;
V_217 . V_220 = 0 ;
if ( ! V_181 )
V_181 = V_217 . V_51 ;
if ( V_216 ) {
V_219 = strlen ( V_181 ) + strlen ( V_216 ) + 2 ;
V_51 = F_14 ( V_219 , V_40 ) ;
if ( ! V_51 )
return NULL ;
snprintf ( V_51 , V_219 , L_56 , V_216 , V_181 ) ;
V_217 . V_51 = V_51 ;
} else {
V_217 . V_51 = V_181 ;
}
V_218 = F_134 ( & V_217 , V_193 ) ;
F_16 ( V_51 ) ;
return V_218 ;
}
int F_74 ( struct V_4 * V_5 ,
const struct V_214 * V_144 , int V_145 )
{
struct V_72 * V_49 = V_5 -> V_49 -> V_72 ;
int V_68 , V_3 ;
for ( V_3 = 0 ; V_3 < V_145 ; V_3 ++ ) {
const struct V_214 * V_221 = & V_144 [ V_3 ] ;
V_68 = F_135 ( V_49 , F_133 ( V_221 , V_5 ,
V_221 -> V_51 ,
V_5 -> V_137 ) ) ;
if ( V_68 < 0 ) {
F_61 ( V_5 -> V_28 , L_57 ,
V_5 -> V_51 , V_221 -> V_51 , V_68 ) ;
return V_68 ;
}
}
return 0 ;
}
int F_78 ( struct V_60 * V_61 ,
const struct V_214 * V_144 , int V_145 )
{
struct V_72 * V_49 = V_61 -> V_49 -> V_72 ;
int V_68 , V_3 ;
for ( V_3 = 0 ; V_3 < V_145 ; V_3 ++ ) {
const struct V_214 * V_221 = & V_144 [ V_3 ] ;
V_68 = F_135 ( V_49 , F_133 ( V_221 , V_61 ,
V_221 -> V_51 , NULL ) ) ;
if ( V_68 < 0 ) {
F_61 ( V_61 -> V_28 , L_58 , V_221 -> V_51 , V_68 ) ;
return V_68 ;
}
}
return 0 ;
}
int F_136 ( struct V_213 * V_218 ,
struct V_222 * V_223 )
{
struct V_224 * V_225 = (struct V_224 * ) V_218 -> V_226 ;
V_223 -> type = V_227 ;
V_223 -> V_18 = V_225 -> V_228 == V_225 -> V_229 ? 1 : 2 ;
V_223 -> V_45 . V_230 . V_231 = V_225 -> V_232 ;
if ( V_223 -> V_45 . V_230 . V_233 > V_225 -> V_232 - 1 )
V_223 -> V_45 . V_230 . V_233 = V_225 -> V_232 - 1 ;
strcpy ( V_223 -> V_45 . V_230 . V_51 ,
V_225 -> V_234 [ V_223 -> V_45 . V_230 . V_233 ] ) ;
return 0 ;
}
int F_137 ( struct V_213 * V_218 ,
struct V_235 * V_236 )
{
struct V_4 * V_5 = F_138 ( V_218 ) ;
struct V_224 * V_225 = (struct V_224 * ) V_218 -> V_226 ;
unsigned int V_1 , V_237 ;
for ( V_237 = 1 ; V_237 < V_225 -> V_232 ; V_237 <<= 1 )
;
V_1 = F_4 ( V_5 , V_225 -> V_6 ) ;
V_236 -> V_45 . V_230 . V_233 [ 0 ]
= ( V_1 >> V_225 -> V_228 ) & ( V_237 - 1 ) ;
if ( V_225 -> V_228 != V_225 -> V_229 )
V_236 -> V_45 . V_230 . V_233 [ 1 ] =
( V_1 >> V_225 -> V_229 ) & ( V_237 - 1 ) ;
return 0 ;
}
int F_139 ( struct V_213 * V_218 ,
struct V_235 * V_236 )
{
struct V_4 * V_5 = F_138 ( V_218 ) ;
struct V_224 * V_225 = (struct V_224 * ) V_218 -> V_226 ;
unsigned int V_1 ;
unsigned int V_195 , V_237 ;
for ( V_237 = 1 ; V_237 < V_225 -> V_232 ; V_237 <<= 1 )
;
if ( V_236 -> V_45 . V_230 . V_233 [ 0 ] > V_225 -> V_232 - 1 )
return - V_17 ;
V_1 = V_236 -> V_45 . V_230 . V_233 [ 0 ] << V_225 -> V_228 ;
V_195 = ( V_237 - 1 ) << V_225 -> V_228 ;
if ( V_225 -> V_228 != V_225 -> V_229 ) {
if ( V_236 -> V_45 . V_230 . V_233 [ 1 ] > V_225 -> V_232 - 1 )
return - V_17 ;
V_1 |= V_236 -> V_45 . V_230 . V_233 [ 1 ] << V_225 -> V_229 ;
V_195 |= ( V_237 - 1 ) << V_225 -> V_229 ;
}
return F_130 ( V_5 , V_225 -> V_6 , V_195 , V_1 ) ;
}
int F_140 ( struct V_213 * V_218 ,
struct V_235 * V_236 )
{
struct V_4 * V_5 = F_138 ( V_218 ) ;
struct V_224 * V_225 = (struct V_224 * ) V_218 -> V_226 ;
unsigned int V_238 , V_1 , V_239 ;
V_238 = F_4 ( V_5 , V_225 -> V_6 ) ;
V_1 = ( V_238 >> V_225 -> V_228 ) & V_225 -> V_195 ;
for ( V_239 = 0 ; V_239 < V_225 -> V_232 ; V_239 ++ ) {
if ( V_1 == V_225 -> V_240 [ V_239 ] )
break;
}
V_236 -> V_45 . V_230 . V_233 [ 0 ] = V_239 ;
if ( V_225 -> V_228 != V_225 -> V_229 ) {
V_1 = ( V_238 >> V_225 -> V_229 ) & V_225 -> V_195 ;
for ( V_239 = 0 ; V_239 < V_225 -> V_232 ; V_239 ++ ) {
if ( V_1 == V_225 -> V_240 [ V_239 ] )
break;
}
V_236 -> V_45 . V_230 . V_233 [ 1 ] = V_239 ;
}
return 0 ;
}
int F_141 ( struct V_213 * V_218 ,
struct V_235 * V_236 )
{
struct V_4 * V_5 = F_138 ( V_218 ) ;
struct V_224 * V_225 = (struct V_224 * ) V_218 -> V_226 ;
unsigned int V_1 ;
unsigned int V_195 ;
if ( V_236 -> V_45 . V_230 . V_233 [ 0 ] > V_225 -> V_232 - 1 )
return - V_17 ;
V_1 = V_225 -> V_240 [ V_236 -> V_45 . V_230 . V_233 [ 0 ] ] << V_225 -> V_228 ;
V_195 = V_225 -> V_195 << V_225 -> V_228 ;
if ( V_225 -> V_228 != V_225 -> V_229 ) {
if ( V_236 -> V_45 . V_230 . V_233 [ 1 ] > V_225 -> V_232 - 1 )
return - V_17 ;
V_1 |= V_225 -> V_240 [ V_236 -> V_45 . V_230 . V_233 [ 1 ] ] << V_225 -> V_229 ;
V_195 |= V_225 -> V_195 << V_225 -> V_229 ;
}
return F_130 ( V_5 , V_225 -> V_6 , V_195 , V_1 ) ;
}
int F_142 ( struct V_213 * V_218 ,
struct V_222 * V_223 )
{
struct V_224 * V_225 = (struct V_224 * ) V_218 -> V_226 ;
V_223 -> type = V_227 ;
V_223 -> V_18 = 1 ;
V_223 -> V_45 . V_230 . V_231 = V_225 -> V_232 ;
if ( V_223 -> V_45 . V_230 . V_233 > V_225 -> V_232 - 1 )
V_223 -> V_45 . V_230 . V_233 = V_225 -> V_232 - 1 ;
strcpy ( V_223 -> V_45 . V_230 . V_51 ,
V_225 -> V_234 [ V_223 -> V_45 . V_230 . V_233 ] ) ;
return 0 ;
}
int F_143 ( struct V_213 * V_218 ,
struct V_222 * V_223 )
{
int V_232 = V_218 -> V_226 ;
if ( V_232 == 1 && ! strstr ( V_218 -> V_241 . V_51 , L_59 ) )
V_223 -> type = V_242 ;
else
V_223 -> type = V_243 ;
V_223 -> V_18 = 1 ;
V_223 -> V_45 . integer . F_6 = 0 ;
V_223 -> V_45 . integer . V_232 = V_232 ;
return 0 ;
}
int F_144 ( struct V_213 * V_218 ,
struct V_222 * V_223 )
{
struct V_244 * V_245 =
(struct V_244 * ) V_218 -> V_226 ;
int V_246 ;
unsigned int V_247 = V_245 -> V_247 ;
unsigned int V_248 = V_245 -> V_248 ;
if ( ! V_245 -> V_246 )
V_245 -> V_246 = V_245 -> V_232 ;
V_246 = V_245 -> V_246 ;
if ( V_246 == 1 && ! strstr ( V_218 -> V_241 . V_51 , L_59 ) )
V_223 -> type = V_242 ;
else
V_223 -> type = V_243 ;
V_223 -> V_18 = V_247 == V_248 ? 1 : 2 ;
V_223 -> V_45 . integer . F_6 = 0 ;
V_223 -> V_45 . integer . V_232 = V_246 ;
return 0 ;
}
int F_145 ( struct V_213 * V_218 ,
struct V_235 * V_236 )
{
struct V_244 * V_245 =
(struct V_244 * ) V_218 -> V_226 ;
struct V_4 * V_5 = F_138 ( V_218 ) ;
unsigned int V_6 = V_245 -> V_6 ;
unsigned int V_247 = V_245 -> V_247 ;
unsigned int V_248 = V_245 -> V_248 ;
int V_232 = V_245 -> V_232 ;
unsigned int V_195 = ( 1 << F_146 ( V_232 ) ) - 1 ;
unsigned int V_249 = V_245 -> V_249 ;
V_236 -> V_45 . integer . V_45 [ 0 ] =
( F_4 ( V_5 , V_6 ) >> V_247 ) & V_195 ;
if ( V_247 != V_248 )
V_236 -> V_45 . integer . V_45 [ 1 ] =
( F_4 ( V_5 , V_6 ) >> V_248 ) & V_195 ;
if ( V_249 ) {
V_236 -> V_45 . integer . V_45 [ 0 ] =
V_232 - V_236 -> V_45 . integer . V_45 [ 0 ] ;
if ( V_247 != V_248 )
V_236 -> V_45 . integer . V_45 [ 1 ] =
V_232 - V_236 -> V_45 . integer . V_45 [ 1 ] ;
}
return 0 ;
}
int F_147 ( struct V_213 * V_218 ,
struct V_235 * V_236 )
{
struct V_244 * V_245 =
(struct V_244 * ) V_218 -> V_226 ;
struct V_4 * V_5 = F_138 ( V_218 ) ;
unsigned int V_6 = V_245 -> V_6 ;
unsigned int V_247 = V_245 -> V_247 ;
unsigned int V_248 = V_245 -> V_248 ;
int V_232 = V_245 -> V_232 ;
unsigned int V_195 = ( 1 << F_146 ( V_232 ) ) - 1 ;
unsigned int V_249 = V_245 -> V_249 ;
unsigned int V_1 , V_250 , V_251 ;
V_1 = ( V_236 -> V_45 . integer . V_45 [ 0 ] & V_195 ) ;
if ( V_249 )
V_1 = V_232 - V_1 ;
V_251 = V_195 << V_247 ;
V_1 = V_1 << V_247 ;
if ( V_247 != V_248 ) {
V_250 = ( V_236 -> V_45 . integer . V_45 [ 1 ] & V_195 ) ;
if ( V_249 )
V_250 = V_232 - V_250 ;
V_251 |= V_195 << V_248 ;
V_1 |= V_250 << V_248 ;
}
return F_130 ( V_5 , V_6 , V_251 , V_1 ) ;
}
int F_148 ( struct V_213 * V_218 ,
struct V_222 * V_223 )
{
struct V_244 * V_245 =
(struct V_244 * ) V_218 -> V_226 ;
int V_246 ;
if ( ! V_245 -> V_246 )
V_245 -> V_246 = V_245 -> V_232 ;
V_246 = V_245 -> V_246 ;
if ( V_246 == 1 && ! strstr ( V_218 -> V_241 . V_51 , L_59 ) )
V_223 -> type = V_242 ;
else
V_223 -> type = V_243 ;
V_223 -> V_18 = 2 ;
V_223 -> V_45 . integer . F_6 = 0 ;
V_223 -> V_45 . integer . V_232 = V_246 ;
return 0 ;
}
int F_149 ( struct V_213 * V_218 ,
struct V_235 * V_236 )
{
struct V_244 * V_245 =
(struct V_244 * ) V_218 -> V_226 ;
struct V_4 * V_5 = F_138 ( V_218 ) ;
unsigned int V_6 = V_245 -> V_6 ;
unsigned int V_252 = V_245 -> V_253 ;
unsigned int V_247 = V_245 -> V_247 ;
int V_232 = V_245 -> V_232 ;
unsigned int V_195 = ( 1 << F_146 ( V_232 ) ) - 1 ;
unsigned int V_249 = V_245 -> V_249 ;
V_236 -> V_45 . integer . V_45 [ 0 ] =
( F_4 ( V_5 , V_6 ) >> V_247 ) & V_195 ;
V_236 -> V_45 . integer . V_45 [ 1 ] =
( F_4 ( V_5 , V_252 ) >> V_247 ) & V_195 ;
if ( V_249 ) {
V_236 -> V_45 . integer . V_45 [ 0 ] =
V_232 - V_236 -> V_45 . integer . V_45 [ 0 ] ;
V_236 -> V_45 . integer . V_45 [ 1 ] =
V_232 - V_236 -> V_45 . integer . V_45 [ 1 ] ;
}
return 0 ;
}
int F_150 ( struct V_213 * V_218 ,
struct V_235 * V_236 )
{
struct V_244 * V_245 =
(struct V_244 * ) V_218 -> V_226 ;
struct V_4 * V_5 = F_138 ( V_218 ) ;
unsigned int V_6 = V_245 -> V_6 ;
unsigned int V_252 = V_245 -> V_253 ;
unsigned int V_247 = V_245 -> V_247 ;
int V_232 = V_245 -> V_232 ;
unsigned int V_195 = ( 1 << F_146 ( V_232 ) ) - 1 ;
unsigned int V_249 = V_245 -> V_249 ;
int V_68 ;
unsigned int V_1 , V_250 , V_251 ;
V_251 = V_195 << V_247 ;
V_1 = ( V_236 -> V_45 . integer . V_45 [ 0 ] & V_195 ) ;
V_250 = ( V_236 -> V_45 . integer . V_45 [ 1 ] & V_195 ) ;
if ( V_249 ) {
V_1 = V_232 - V_1 ;
V_250 = V_232 - V_250 ;
}
V_1 = V_1 << V_247 ;
V_250 = V_250 << V_247 ;
V_68 = F_130 ( V_5 , V_6 , V_251 , V_1 ) ;
if ( V_68 < 0 )
return V_68 ;
V_68 = F_130 ( V_5 , V_252 , V_251 , V_250 ) ;
return V_68 ;
}
int F_151 ( struct V_213 * V_218 ,
struct V_222 * V_223 )
{
struct V_244 * V_245 =
(struct V_244 * ) V_218 -> V_226 ;
int V_246 ;
int F_6 = V_245 -> F_6 ;
if ( ! V_245 -> V_246 )
V_245 -> V_246 = V_245 -> V_232 ;
V_246 = V_245 -> V_246 ;
V_223 -> type = V_243 ;
V_223 -> V_18 = 2 ;
V_223 -> V_45 . integer . F_6 = 0 ;
V_223 -> V_45 . integer . V_232 = V_246 - F_6 ;
return 0 ;
}
int F_152 ( struct V_213 * V_218 ,
struct V_235 * V_236 )
{
struct V_244 * V_245 =
(struct V_244 * ) V_218 -> V_226 ;
struct V_4 * V_5 = F_138 ( V_218 ) ;
unsigned int V_6 = V_245 -> V_6 ;
int F_6 = V_245 -> F_6 ;
int V_1 = F_4 ( V_5 , V_6 ) ;
V_236 -> V_45 . integer . V_45 [ 0 ] =
( ( signed char ) ( V_1 & 0xff ) ) - F_6 ;
V_236 -> V_45 . integer . V_45 [ 1 ] =
( ( signed char ) ( ( V_1 >> 8 ) & 0xff ) ) - F_6 ;
return 0 ;
}
int F_153 ( struct V_213 * V_218 ,
struct V_235 * V_236 )
{
struct V_244 * V_245 =
(struct V_244 * ) V_218 -> V_226 ;
struct V_4 * V_5 = F_138 ( V_218 ) ;
unsigned int V_6 = V_245 -> V_6 ;
int F_6 = V_245 -> F_6 ;
unsigned int V_1 ;
V_1 = ( V_236 -> V_45 . integer . V_45 [ 0 ] + F_6 ) & 0xff ;
V_1 |= ( ( V_236 -> V_45 . integer . V_45 [ 1 ] + F_6 ) & 0xff ) << 8 ;
return F_130 ( V_5 , V_6 , 0xffff , V_1 ) ;
}
int F_154 ( struct V_4 * V_5 ,
const char * V_51 , int V_232 )
{
struct V_72 * V_49 = V_5 -> V_49 -> V_72 ;
struct V_213 * V_254 ;
struct V_244 * V_245 ;
int V_166 = 0 ;
int V_14 = - V_17 ;
if ( F_155 ( ! V_51 || V_232 <= 0 ) )
return - V_17 ;
F_32 (kctl, &card->controls, list) {
if ( ! strncmp ( V_254 -> V_241 . V_51 , V_51 , sizeof( V_254 -> V_241 . V_51 ) ) ) {
V_166 = 1 ;
break;
}
}
if ( V_166 ) {
V_245 = (struct V_244 * ) V_254 -> V_226 ;
if ( V_232 <= V_245 -> V_232 ) {
V_245 -> V_246 = V_232 ;
V_14 = 0 ;
}
}
return V_14 ;
}
int F_156 ( struct V_213 * V_218 ,
struct V_222 * V_223 )
{
struct V_244 * V_245 =
(struct V_244 * ) V_218 -> V_226 ;
int V_232 = V_245 -> V_232 ;
int F_6 = V_245 -> F_6 ;
V_223 -> type = V_243 ;
V_223 -> V_18 = 2 ;
V_223 -> V_45 . integer . F_6 = 0 ;
V_223 -> V_45 . integer . V_232 = V_232 - F_6 ;
return 0 ;
}
int F_157 ( struct V_213 * V_218 ,
struct V_235 * V_236 )
{
struct V_244 * V_245 =
(struct V_244 * ) V_218 -> V_226 ;
struct V_4 * V_5 = F_138 ( V_218 ) ;
unsigned int V_195 = ( 1 << V_245 -> V_247 ) - 1 ;
int F_6 = V_245 -> F_6 ;
int V_1 = F_4 ( V_5 , V_245 -> V_6 ) & V_195 ;
int V_255 = F_4 ( V_5 , V_245 -> V_253 ) & V_195 ;
V_236 -> V_45 . integer . V_45 [ 0 ] = ( ( V_1 & 0xff ) - F_6 ) & V_195 ;
V_236 -> V_45 . integer . V_45 [ 1 ] = ( ( V_255 & 0xff ) - F_6 ) & V_195 ;
return 0 ;
}
int F_158 ( struct V_213 * V_218 ,
struct V_235 * V_236 )
{
struct V_244 * V_245 =
(struct V_244 * ) V_218 -> V_226 ;
struct V_4 * V_5 = F_138 ( V_218 ) ;
unsigned int V_195 = ( 1 << V_245 -> V_247 ) - 1 ;
int F_6 = V_245 -> F_6 ;
int V_14 ;
unsigned int V_1 , V_255 , V_256 , V_257 ;
V_1 = ( ( V_236 -> V_45 . integer . V_45 [ 0 ] + F_6 ) & 0xff ) ;
V_1 &= V_195 ;
V_255 = ( ( V_236 -> V_45 . integer . V_45 [ 1 ] + F_6 ) & 0xff ) ;
V_255 &= V_195 ;
V_256 = F_4 ( V_5 , V_245 -> V_6 ) & V_195 ;
V_257 = F_4 ( V_5 , V_245 -> V_253 ) & V_195 ;
V_14 = 0 ;
if ( V_256 != V_1 ) {
V_14 = F_22 ( V_5 , V_245 -> V_6 , V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( V_257 != V_255 ) {
V_14 = F_22 ( V_5 , V_245 -> V_253 , V_255 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
int F_159 ( struct V_58 * V_59 , int V_258 ,
unsigned int V_259 , int V_260 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_84 -> V_261 )
return V_59 -> V_10 -> V_84 -> V_261 ( V_59 , V_258 , V_259 , V_260 ) ;
else if ( V_59 -> V_5 && V_59 -> V_5 -> V_10 -> V_261 )
return V_59 -> V_5 -> V_10 -> V_261 ( V_59 -> V_5 , V_258 ,
V_259 , V_260 ) ;
else
return - V_17 ;
}
int F_160 ( struct V_4 * V_5 , int V_258 ,
unsigned int V_259 , int V_260 )
{
if ( V_5 -> V_10 -> V_261 )
return V_5 -> V_10 -> V_261 ( V_5 , V_258 , V_259 , V_260 ) ;
else
return - V_17 ;
}
int F_161 ( struct V_58 * V_59 ,
int V_262 , int div )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_84 -> V_263 )
return V_59 -> V_10 -> V_84 -> V_263 ( V_59 , V_262 , div ) ;
else
return - V_17 ;
}
int F_162 ( struct V_58 * V_59 , int V_264 , int V_265 ,
unsigned int V_266 , unsigned int V_267 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_84 -> V_268 )
return V_59 -> V_10 -> V_84 -> V_268 ( V_59 , V_264 , V_265 ,
V_266 , V_267 ) ;
else if ( V_59 -> V_5 && V_59 -> V_5 -> V_10 -> V_268 )
return V_59 -> V_5 -> V_10 -> V_268 ( V_59 -> V_5 , V_264 , V_265 ,
V_266 , V_267 ) ;
else
return - V_17 ;
}
int F_163 ( struct V_4 * V_5 , int V_264 , int V_265 ,
unsigned int V_266 , unsigned int V_267 )
{
if ( V_5 -> V_10 -> V_268 )
return V_5 -> V_10 -> V_268 ( V_5 , V_264 , V_265 ,
V_266 , V_267 ) ;
else
return - V_17 ;
}
int F_164 ( struct V_58 * V_59 , unsigned int V_269 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_84 -> V_270 )
return V_59 -> V_10 -> V_84 -> V_270 ( V_59 , V_269 ) ;
else
return - V_17 ;
}
int F_165 ( struct V_58 * V_59 ,
unsigned int V_271 , unsigned int V_272 , int V_273 , int V_274 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_84 -> V_275 )
return V_59 -> V_10 -> V_84 -> V_275 ( V_59 , V_271 , V_272 ,
V_273 , V_274 ) ;
else
return - V_17 ;
}
int F_166 ( struct V_58 * V_59 ,
unsigned int V_276 , unsigned int * V_277 ,
unsigned int V_278 , unsigned int * V_279 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_84 -> V_280 )
return V_59 -> V_10 -> V_84 -> V_280 ( V_59 , V_276 , V_277 ,
V_278 , V_279 ) ;
else
return - V_17 ;
}
int F_167 ( struct V_58 * V_59 , int V_281 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_84 -> V_282 )
return V_59 -> V_10 -> V_84 -> V_282 ( V_59 , V_281 ) ;
else
return - V_17 ;
}
int F_168 ( struct V_58 * V_59 , int V_283 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_84 -> V_85 )
return V_59 -> V_10 -> V_84 -> V_85 ( V_59 , V_283 ) ;
else
return - V_17 ;
}
int F_110 ( struct V_62 * V_49 )
{
int V_3 ;
if ( ! V_49 -> V_51 || ! V_49 -> V_28 )
return - V_17 ;
F_169 ( V_49 -> V_28 , V_49 ) ;
F_170 ( V_49 ) ;
F_36 ( V_49 ) ;
V_49 -> V_32 = F_124 ( sizeof( struct V_31 ) *
( V_49 -> V_172 + V_49 -> V_177 ) ,
V_40 ) ;
if ( V_49 -> V_32 == NULL )
return - V_41 ;
V_49 -> V_156 = & V_49 -> V_32 [ V_49 -> V_172 ] ;
for ( V_3 = 0 ; V_3 < V_49 -> V_172 ; V_3 ++ )
V_49 -> V_32 [ V_3 ] . V_82 = & V_49 -> V_82 [ V_3 ] ;
F_171 ( & V_49 -> V_148 ) ;
V_49 -> V_171 = 0 ;
F_82 ( & V_49 -> V_170 ) ;
F_95 ( & V_284 ) ;
F_76 ( & V_49 -> V_148 , & V_123 ) ;
F_107 () ;
F_96 ( & V_284 ) ;
F_57 ( V_49 -> V_28 , L_60 , V_49 -> V_51 ) ;
return 0 ;
}
int F_113 ( struct V_62 * V_49 )
{
if ( V_49 -> V_171 )
F_111 ( V_49 ) ;
F_95 ( & V_284 ) ;
F_65 ( & V_49 -> V_148 ) ;
F_96 ( & V_284 ) ;
F_57 ( V_49 -> V_28 , L_61 , V_49 -> V_51 ) ;
return 0 ;
}
static char * F_172 ( struct V_27 * V_28 , int * V_241 )
{
char * V_166 , V_51 [ V_285 ] ;
int V_286 , V_287 ;
if ( V_136 ( V_28 ) == NULL )
return NULL ;
F_173 ( V_51 , V_136 ( V_28 ) , V_285 ) ;
V_166 = strstr ( V_51 , V_28 -> V_10 -> V_51 ) ;
if ( V_166 ) {
if ( sscanf ( & V_166 [ strlen ( V_28 -> V_10 -> V_51 ) ] , L_62 , V_241 ) == 1 ) {
if ( * V_241 == - 1 )
V_166 [ strlen ( V_28 -> V_10 -> V_51 ) ] = '\0' ;
}
} else {
if ( sscanf ( V_51 , L_63 , & V_286 , & V_287 ) == 2 ) {
char V_288 [ V_285 ] ;
* V_241 = ( ( V_286 & 0xffff ) << 16 ) + V_287 ;
snprintf ( V_288 , V_285 , L_64 , V_28 -> V_10 -> V_51 , V_51 ) ;
F_173 ( V_51 , V_288 , V_285 ) ;
} else
* V_241 = 0 ;
}
return F_174 ( V_51 , V_40 ) ;
}
static inline char * F_175 ( struct V_27 * V_28 ,
struct V_80 * V_289 )
{
if ( V_289 -> V_51 == NULL ) {
F_25 ( V_74 L_65 ,
V_136 ( V_28 ) ) ;
return NULL ;
}
return F_174 ( V_289 -> V_51 , V_40 ) ;
}
int F_176 ( struct V_27 * V_28 ,
struct V_80 * V_289 )
{
struct V_58 * V_59 ;
F_57 ( V_28 , L_66 , V_136 ( V_28 ) ) ;
V_59 = F_124 ( sizeof( struct V_58 ) , V_40 ) ;
if ( V_59 == NULL )
return - V_41 ;
V_59 -> V_51 = F_172 ( V_28 , & V_59 -> V_241 ) ;
if ( V_59 -> V_51 == NULL ) {
F_16 ( V_59 ) ;
return - V_41 ;
}
V_59 -> V_28 = V_28 ;
V_59 -> V_10 = V_289 ;
if ( ! V_59 -> V_10 -> V_84 )
V_59 -> V_10 -> V_84 = & V_290 ;
F_95 ( & V_284 ) ;
F_76 ( & V_59 -> V_148 , & V_291 ) ;
F_107 () ;
F_96 ( & V_284 ) ;
F_177 ( L_67 , V_59 -> V_51 ) ;
return 0 ;
}
void F_178 ( struct V_27 * V_28 )
{
struct V_58 * V_59 ;
F_32 (dai, &dai_list, list) {
if ( V_28 == V_59 -> V_28 )
goto V_166;
}
return;
V_166:
F_95 ( & V_284 ) ;
F_65 ( & V_59 -> V_148 ) ;
F_96 ( & V_284 ) ;
F_177 ( L_68 , V_59 -> V_51 ) ;
F_16 ( V_59 -> V_51 ) ;
F_16 ( V_59 ) ;
}
int F_179 ( struct V_27 * V_28 ,
struct V_80 * V_289 , T_1 V_18 )
{
struct V_58 * V_59 ;
int V_3 , V_14 = 0 ;
F_57 ( V_28 , L_69 , V_136 ( V_28 ) , V_18 ) ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ ) {
V_59 = F_124 ( sizeof( struct V_58 ) , V_40 ) ;
if ( V_59 == NULL ) {
V_14 = - V_41 ;
goto V_68;
}
V_59 -> V_51 = F_175 ( V_28 , & V_289 [ V_3 ] ) ;
if ( V_59 -> V_51 == NULL ) {
F_16 ( V_59 ) ;
V_14 = - V_17 ;
goto V_68;
}
V_59 -> V_28 = V_28 ;
V_59 -> V_10 = & V_289 [ V_3 ] ;
if ( V_59 -> V_10 -> V_241 )
V_59 -> V_241 = V_59 -> V_10 -> V_241 ;
else
V_59 -> V_241 = V_3 ;
if ( ! V_59 -> V_10 -> V_84 )
V_59 -> V_10 -> V_84 = & V_290 ;
F_95 ( & V_284 ) ;
F_76 ( & V_59 -> V_148 , & V_291 ) ;
F_96 ( & V_284 ) ;
F_177 ( L_67 , V_59 -> V_51 ) ;
}
F_95 ( & V_284 ) ;
F_107 () ;
F_96 ( & V_284 ) ;
return 0 ;
V_68:
for ( V_3 -- ; V_3 >= 0 ; V_3 -- )
F_178 ( V_28 ) ;
return V_14 ;
}
void F_180 ( struct V_27 * V_28 , T_1 V_18 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ )
F_178 ( V_28 ) ;
}
int F_181 ( struct V_27 * V_28 ,
struct V_150 * V_292 )
{
struct V_60 * V_61 ;
F_57 ( V_28 , L_70 , V_136 ( V_28 ) ) ;
V_61 = F_124 ( sizeof( struct V_60 ) , V_40 ) ;
if ( V_61 == NULL )
return - V_41 ;
V_61 -> V_51 = F_172 ( V_28 , & V_61 -> V_241 ) ;
if ( V_61 -> V_51 == NULL ) {
F_16 ( V_61 ) ;
return - V_41 ;
}
V_61 -> V_28 = V_28 ;
V_61 -> V_10 = V_292 ;
V_61 -> V_57 . V_28 = V_28 ;
V_61 -> V_57 . V_61 = V_61 ;
F_95 ( & V_284 ) ;
F_76 ( & V_61 -> V_148 , & V_293 ) ;
F_107 () ;
F_96 ( & V_284 ) ;
F_177 ( L_71 , V_61 -> V_51 ) ;
return 0 ;
}
void F_182 ( struct V_27 * V_28 )
{
struct V_60 * V_61 ;
F_32 (platform, &platform_list, list) {
if ( V_28 == V_61 -> V_28 )
goto V_166;
}
return;
V_166:
F_95 ( & V_284 ) ;
F_65 ( & V_61 -> V_148 ) ;
F_96 ( & V_284 ) ;
F_177 ( L_72 , V_61 -> V_51 ) ;
F_16 ( V_61 -> V_51 ) ;
F_16 ( V_61 ) ;
}
static void F_183 ( struct V_294 * V_295 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_103 ( V_296 ) ; V_3 ++ )
if ( V_295 -> V_206 & V_296 [ V_3 ] )
V_295 -> V_206 |= V_296 [ V_3 ] ;
}
int F_184 ( struct V_27 * V_28 ,
const struct V_138 * V_297 ,
struct V_80 * V_289 ,
int V_298 )
{
T_1 V_299 ;
struct V_4 * V_5 ;
int V_14 , V_3 ;
F_57 ( V_28 , L_73 , V_136 ( V_28 ) ) ;
V_5 = F_124 ( sizeof( struct V_4 ) , V_40 ) ;
if ( V_5 == NULL )
return - V_41 ;
V_5 -> V_51 = F_172 ( V_28 , & V_5 -> V_241 ) ;
if ( V_5 -> V_51 == NULL ) {
F_16 ( V_5 ) ;
return - V_41 ;
}
if ( V_297 -> V_168 )
V_5 -> V_168 = V_297 -> V_168 ;
else
V_5 -> V_168 = V_300 ;
V_5 -> V_189 = V_297 -> V_189 ;
V_5 -> V_188 = V_297 -> V_188 ;
V_5 -> V_186 = V_297 -> V_186 ;
V_5 -> V_24 = V_297 -> V_24 ;
V_5 -> V_187 = V_297 -> V_187 ;
V_5 -> V_57 . V_95 = V_101 ;
V_5 -> V_57 . V_28 = V_28 ;
V_5 -> V_57 . V_5 = V_5 ;
V_5 -> V_57 . V_301 = V_297 -> V_301 ;
V_5 -> V_28 = V_28 ;
V_5 -> V_10 = V_297 ;
V_5 -> V_298 = V_298 ;
F_82 ( & V_5 -> V_170 ) ;
if ( V_297 -> V_11 && V_297 -> V_13 ) {
V_299 = V_297 -> V_11 * V_297 -> V_13 ;
V_5 -> V_299 = V_299 ;
if ( V_297 -> V_302 ) {
V_5 -> V_303 = F_185 ( V_297 -> V_302 ,
V_299 , V_40 ) ;
if ( ! V_5 -> V_303 ) {
V_14 = - V_41 ;
goto V_304;
}
}
}
if ( V_297 -> V_305 && V_297 -> V_306 ) {
if ( ! V_5 -> V_186 )
V_5 -> V_186 = V_307 ;
if ( ! V_5 -> V_24 )
V_5 -> V_24 = V_308 ;
if ( ! V_5 -> V_187 )
V_5 -> V_187 = V_309 ;
}
for ( V_3 = 0 ; V_3 < V_298 ; V_3 ++ ) {
F_183 ( & V_289 [ V_3 ] . V_96 ) ;
F_183 ( & V_289 [ V_3 ] . V_99 ) ;
}
if ( V_298 ) {
V_14 = F_179 ( V_28 , V_289 , V_298 ) ;
if ( V_14 < 0 )
goto V_304;
}
F_95 ( & V_284 ) ;
F_76 ( & V_5 -> V_148 , & V_310 ) ;
F_107 () ;
F_96 ( & V_284 ) ;
F_177 ( L_74 , V_5 -> V_51 ) ;
return 0 ;
V_304:
F_16 ( V_5 -> V_303 ) ;
V_5 -> V_303 = NULL ;
F_16 ( V_5 -> V_51 ) ;
F_16 ( V_5 ) ;
return V_14 ;
}
void F_186 ( struct V_27 * V_28 )
{
struct V_4 * V_5 ;
int V_3 ;
F_32 (codec, &codec_list, list) {
if ( V_28 == V_5 -> V_28 )
goto V_166;
}
return;
V_166:
if ( V_5 -> V_298 )
for ( V_3 = 0 ; V_3 < V_5 -> V_298 ; V_3 ++ )
F_178 ( V_28 ) ;
F_95 ( & V_284 ) ;
F_65 ( & V_5 -> V_148 ) ;
F_96 ( & V_284 ) ;
F_177 ( L_75 , V_5 -> V_51 ) ;
F_187 ( V_5 ) ;
F_16 ( V_5 -> V_303 ) ;
F_16 ( V_5 -> V_51 ) ;
F_16 ( V_5 ) ;
}
static int T_5 F_188 ( void )
{
#ifdef F_98
V_63 = F_24 ( L_76 , NULL ) ;
if ( F_189 ( V_63 ) || ! V_63 ) {
F_25 ( V_52
L_77 ) ;
V_63 = NULL ;
}
if ( ! F_27 ( L_78 , 0444 , V_63 , NULL ,
& V_311 ) )
F_190 ( L_79 ) ;
if ( ! F_27 ( L_80 , 0444 , V_63 , NULL ,
& V_312 ) )
F_190 ( L_81 ) ;
if ( ! F_27 ( L_82 , 0444 , V_63 , NULL ,
& V_313 ) )
F_190 ( L_83 ) ;
#endif
F_191 () ;
return F_192 ( & V_314 ) ;
}
static void T_6 F_193 ( void )
{
F_194 () ;
#ifdef F_98
F_30 ( V_63 ) ;
#endif
F_195 ( & V_314 ) ;
}
