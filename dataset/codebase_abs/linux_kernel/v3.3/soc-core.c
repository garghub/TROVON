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
L_10 ) ;
return;
}
V_48 -> V_63 = F_39 ( L_11 , 0644 ,
V_48 -> V_47 ,
& V_48 -> V_64 ) ;
if ( ! V_48 -> V_63 )
F_38 ( V_48 -> V_27 ,
L_12 ) ;
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
F_45 ( & V_5 -> V_65 -> V_27 , L_13 ,
V_5 -> V_48 -> V_71 -> V_72 , 0 , V_5 -> V_50 ) ;
V_67 = F_46 ( & V_5 -> V_65 -> V_27 ) ;
if ( V_67 < 0 ) {
F_47 ( V_73 L_14 ) ;
V_5 -> V_65 -> V_27 . V_66 = NULL ;
return V_67 ;
}
return 0 ;
}
int F_48 ( struct V_26 * V_27 )
{
struct V_61 * V_48 = F_9 ( V_27 ) ;
struct V_4 * V_5 ;
int V_3 ;
if ( F_49 ( & V_48 -> V_74 ) )
return 0 ;
F_50 ( V_48 -> V_71 ) ;
F_51 ( V_48 -> V_71 , V_75 ) ;
F_52 ( V_48 -> V_71 ) ;
F_53 ( V_48 -> V_71 , V_76 ) ;
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
F_54 ( V_48 -> V_31 [ V_3 ] . V_86 ) ;
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
F_55 ( & V_48 -> V_31 [ V_3 ] . V_92 ) ;
V_48 -> V_31 [ V_3 ] . V_5 -> V_56 . V_93 = V_48 -> V_31 [ V_3 ] . V_5 -> V_56 . V_94 ;
}
for ( V_3 = 0 ; V_3 < V_48 -> V_77 ; V_3 ++ ) {
struct V_79 * V_10 = V_48 -> V_31 [ V_3 ] . V_78 -> V_10 ;
if ( V_48 -> V_31 [ V_3 ] . V_81 -> V_82 )
continue;
if ( V_10 -> V_95 . V_96 != NULL )
F_56 ( & V_48 -> V_31 [ V_3 ] , V_10 -> V_95 . V_96 ,
V_97 ) ;
if ( V_10 -> V_98 . V_96 != NULL )
F_56 ( & V_48 -> V_31 [ V_3 ] , V_10 -> V_98 . V_96 ,
V_97 ) ;
}
F_33 (codec, &card->codec_dev_list, card_list) {
if ( ! V_5 -> V_91 && V_5 -> V_10 -> V_89 ) {
switch ( V_5 -> V_56 . V_94 ) {
case V_99 :
if ( V_5 -> V_56 . V_100 ) {
F_57 ( V_5 -> V_27 ,
L_15 ) ;
break;
}
case V_101 :
V_5 -> V_10 -> V_89 ( V_5 ) ;
V_5 -> V_91 = 1 ;
V_5 -> V_52 = 1 ;
break;
default:
F_57 ( V_5 -> V_27 , L_16 ) ;
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
static void F_58 ( struct V_103 * V_104 )
{
struct V_61 * V_48 =
F_59 ( V_104 , struct V_61 , V_105 ) ;
struct V_4 * V_5 ;
int V_3 ;
F_57 ( V_48 -> V_27 , L_17 ) ;
F_53 ( V_48 -> V_71 , V_106 ) ;
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
case V_101 :
V_5 -> V_10 -> V_108 ( V_5 ) ;
V_5 -> V_91 = 0 ;
break;
default:
F_57 ( V_5 -> V_27 , L_18 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_48 -> V_77 ; V_3 ++ ) {
struct V_79 * V_10 = V_48 -> V_31 [ V_3 ] . V_78 -> V_10 ;
if ( V_48 -> V_31 [ V_3 ] . V_81 -> V_82 )
continue;
if ( V_10 -> V_95 . V_96 != NULL )
F_56 ( & V_48 -> V_31 [ V_3 ] , V_10 -> V_95 . V_96 ,
V_109 ) ;
if ( V_10 -> V_98 . V_96 != NULL )
F_56 ( & V_48 -> V_31 [ V_3 ] , V_10 -> V_98 . V_96 ,
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
F_57 ( V_48 -> V_27 , L_19 ) ;
F_53 ( V_48 -> V_71 , V_75 ) ;
}
int F_60 ( struct V_26 * V_27 )
{
struct V_61 * V_48 = F_9 ( V_27 ) ;
int V_3 , V_90 = 0 ;
if ( F_49 ( & V_48 -> V_74 ) )
return 0 ;
for ( V_3 = 0 ; V_3 < V_48 -> V_77 ; V_3 ++ ) {
struct V_57 * V_88 = V_48 -> V_31 [ V_3 ] . V_88 ;
V_90 |= V_88 -> V_10 -> V_90 ;
}
if ( V_90 ) {
F_57 ( V_27 , L_20 ) ;
F_58 ( & V_48 -> V_105 ) ;
} else {
F_57 ( V_27 , L_21 ) ;
if ( ! F_61 ( & V_48 -> V_105 ) )
F_62 ( V_27 , L_22 ) ;
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
F_57 ( V_48 -> V_27 , L_23 , V_81 -> V_50 , V_111 ) ;
if ( V_31 -> V_88 ) {
goto V_115;
}
F_33 (cpu_dai, &dai_list, list) {
if ( V_81 -> V_116 ) {
if ( V_88 -> V_27 -> V_117 != V_81 -> V_116 )
continue;
} else {
if ( strcmp ( V_88 -> V_50 , V_81 -> V_118 ) )
continue;
}
V_31 -> V_88 = V_88 ;
goto V_115;
}
F_57 ( V_48 -> V_27 , L_24 ,
V_81 -> V_118 ) ;
V_115:
if ( V_31 -> V_5 ) {
goto V_119;
}
F_33 (codec, &codec_list, list) {
if ( V_81 -> V_120 ) {
if ( V_5 -> V_27 -> V_117 != V_81 -> V_120 )
continue;
} else {
if ( strcmp ( V_5 -> V_50 , V_81 -> V_121 ) )
continue;
}
V_31 -> V_5 = V_5 ;
F_33 (codec_dai, &dai_list, list) {
if ( V_5 -> V_27 == V_78 -> V_27 &&
! strcmp ( V_78 -> V_50 ,
V_81 -> V_122 ) ) {
V_31 -> V_78 = V_78 ;
goto V_119;
}
}
F_57 ( V_48 -> V_27 , L_25 ,
V_81 -> V_122 ) ;
goto V_119;
}
F_57 ( V_48 -> V_27 , L_26 ,
V_81 -> V_121 ) ;
V_119:
if ( V_31 -> V_60 )
goto V_123;
V_113 = V_81 -> V_113 ;
if ( ! V_113 && ! V_81 -> V_124 )
V_113 = L_27 ;
F_33 (platform, &platform_list, list) {
if ( V_81 -> V_124 ) {
if ( V_60 -> V_27 -> V_117 !=
V_81 -> V_124 )
continue;
} else {
if ( strcmp ( V_60 -> V_50 , V_113 ) )
continue;
}
V_31 -> V_60 = V_60 ;
goto V_123;
}
F_57 ( V_48 -> V_27 , L_28 ,
V_81 -> V_113 ) ;
return 0 ;
V_123:
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
L_29 ,
V_5 -> V_50 , V_67 ) ;
}
F_65 ( & V_5 -> V_56 ) ;
F_30 ( V_5 ) ;
V_5 -> V_125 = 0 ;
F_66 ( & V_5 -> V_126 ) ;
F_67 ( V_5 -> V_27 -> V_10 -> V_127 ) ;
}
static void F_68 ( struct V_61 * V_48 , int V_111 , int V_128 )
{
struct V_30 * V_31 = & V_48 -> V_31 [ V_111 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
struct V_59 * V_60 = V_31 -> V_60 ;
struct V_57 * V_78 = V_31 -> V_78 , * V_88 = V_31 -> V_88 ;
int V_67 ;
if ( V_31 -> V_129 ) {
F_69 ( V_31 -> V_27 , & V_130 ) ;
F_69 ( V_31 -> V_27 , & V_131 ) ;
F_42 ( V_31 -> V_27 ) ;
V_31 -> V_129 = 0 ;
}
if ( V_78 && V_78 -> V_125 &&
V_78 -> V_10 -> V_132 == V_128 ) {
if ( V_78 -> V_10 -> remove ) {
V_67 = V_78 -> V_10 -> remove ( V_78 ) ;
if ( V_67 < 0 )
F_26 ( V_73 L_30 , V_78 -> V_50 ) ;
}
V_78 -> V_125 = 0 ;
F_66 ( & V_78 -> V_126 ) ;
}
if ( V_60 && V_60 -> V_125 &&
V_60 -> V_10 -> V_132 == V_128 ) {
if ( V_60 -> V_10 -> remove ) {
V_67 = V_60 -> V_10 -> remove ( V_60 ) ;
if ( V_67 < 0 )
F_26 ( V_73 L_30 , V_60 -> V_50 ) ;
}
F_65 ( & V_60 -> V_56 ) ;
V_60 -> V_125 = 0 ;
F_66 ( & V_60 -> V_126 ) ;
F_67 ( V_60 -> V_27 -> V_10 -> V_127 ) ;
}
if ( V_5 && V_5 -> V_125 &&
V_5 -> V_10 -> V_132 == V_128 )
F_64 ( V_5 ) ;
if ( V_88 && V_88 -> V_125 &&
V_88 -> V_10 -> V_132 == V_128 ) {
if ( V_88 -> V_10 -> remove ) {
V_67 = V_88 -> V_10 -> remove ( V_88 ) ;
if ( V_67 < 0 )
F_26 ( V_73 L_30 , V_88 -> V_50 ) ;
}
V_88 -> V_125 = 0 ;
F_66 ( & V_88 -> V_126 ) ;
F_67 ( V_88 -> V_27 -> V_10 -> V_127 ) ;
}
}
static void F_70 ( struct V_61 * V_48 )
{
int V_58 , V_128 ;
for ( V_128 = V_133 ; V_128 <= V_134 ;
V_128 ++ ) {
for ( V_58 = 0 ; V_58 < V_48 -> V_77 ; V_58 ++ )
F_68 ( V_48 , V_58 , V_128 ) ;
}
V_48 -> V_77 = 0 ;
}
static void F_71 ( struct V_61 * V_48 ,
struct V_4 * V_5 )
{
int V_3 ;
if ( V_48 -> V_135 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_48 -> V_136 ; V_3 ++ ) {
struct V_137 * V_138 = & V_48 -> V_135 [ V_3 ] ;
if ( V_138 -> V_139 && ! strcmp ( V_5 -> V_50 , V_138 -> V_139 ) ) {
V_5 -> V_140 = V_138 -> V_140 ;
break;
}
}
}
static int F_72 ( struct V_61 * V_48 ,
struct V_4 * V_5 )
{
int V_14 = 0 ;
const struct V_141 * V_10 = V_5 -> V_10 ;
V_5 -> V_48 = V_48 ;
V_5 -> V_56 . V_48 = V_48 ;
F_71 ( V_48 , V_5 ) ;
if ( ! F_73 ( V_5 -> V_27 -> V_10 -> V_127 ) )
return - V_142 ;
F_24 ( V_5 ) ;
if ( V_10 -> V_143 )
F_74 ( & V_5 -> V_56 , V_10 -> V_143 ,
V_10 -> V_144 ) ;
V_5 -> V_56 . V_100 = V_10 -> V_100 ;
if ( V_10 -> V_145 ) {
V_14 = V_10 -> V_145 ( V_5 ) ;
if ( V_14 < 0 ) {
F_62 ( V_5 -> V_27 ,
L_31 ,
V_5 -> V_50 , V_14 ) ;
goto V_146;
}
}
if ( V_10 -> V_147 )
F_75 ( V_5 , V_10 -> V_147 ,
V_10 -> V_148 ) ;
if ( V_10 -> V_149 )
F_76 ( & V_5 -> V_56 , V_10 -> V_149 ,
V_10 -> V_150 ) ;
V_5 -> V_125 = 1 ;
F_77 ( & V_5 -> V_126 , & V_48 -> V_74 ) ;
F_77 ( & V_5 -> V_56 . V_151 , & V_48 -> V_152 ) ;
return 0 ;
V_146:
F_30 ( V_5 ) ;
F_67 ( V_5 -> V_27 -> V_10 -> V_127 ) ;
return V_14 ;
}
static int F_78 ( struct V_61 * V_48 ,
struct V_59 * V_60 )
{
int V_14 = 0 ;
const struct V_153 * V_10 = V_60 -> V_10 ;
V_60 -> V_48 = V_48 ;
V_60 -> V_56 . V_48 = V_48 ;
if ( ! F_73 ( V_60 -> V_27 -> V_10 -> V_127 ) )
return - V_142 ;
if ( V_10 -> V_143 )
F_74 ( & V_60 -> V_56 ,
V_10 -> V_143 , V_10 -> V_144 ) ;
if ( V_10 -> V_145 ) {
V_14 = V_10 -> V_145 ( V_60 ) ;
if ( V_14 < 0 ) {
F_62 ( V_60 -> V_27 ,
L_32 ,
V_60 -> V_50 , V_14 ) ;
goto V_146;
}
}
if ( V_10 -> V_147 )
F_79 ( V_60 , V_10 -> V_147 ,
V_10 -> V_148 ) ;
if ( V_10 -> V_149 )
F_76 ( & V_60 -> V_56 , V_10 -> V_149 ,
V_10 -> V_150 ) ;
V_60 -> V_125 = 1 ;
F_77 ( & V_60 -> V_126 , & V_48 -> V_154 ) ;
F_77 ( & V_60 -> V_56 . V_151 , & V_48 -> V_152 ) ;
return 0 ;
V_146:
F_67 ( V_60 -> V_27 -> V_10 -> V_127 ) ;
return V_14 ;
}
static void F_80 ( struct V_26 * V_27 )
{
F_17 ( V_27 ) ;
}
static int F_81 ( struct V_61 * V_48 ,
struct V_4 * V_5 ,
int V_111 , int V_155 )
{
struct V_112 * V_81 = NULL ;
struct V_156 * V_157 = NULL ;
struct V_30 * V_31 ;
const char * V_158 , * V_50 ;
int V_14 = 0 ;
if ( ! V_155 ) {
V_81 = & V_48 -> V_81 [ V_111 ] ;
V_31 = & V_48 -> V_31 [ V_111 ] ;
V_50 = V_81 -> V_50 ;
} else {
V_157 = & V_48 -> V_157 [ V_111 ] ;
V_31 = & V_48 -> V_159 [ V_111 ] ;
V_50 = V_157 -> V_50 ;
}
V_31 -> V_48 = V_48 ;
F_82 ( & V_5 -> V_56 ) ;
V_158 = V_5 -> V_140 ;
V_5 -> V_140 = NULL ;
if ( ! V_155 && V_81 -> V_160 )
V_14 = V_81 -> V_160 ( V_31 ) ;
else if ( V_155 && V_157 -> V_160 )
V_14 = V_157 -> V_160 ( & V_5 -> V_56 ) ;
if ( V_14 < 0 ) {
F_62 ( V_48 -> V_27 , L_33 , V_50 , V_14 ) ;
return V_14 ;
}
V_5 -> V_140 = V_158 ;
V_31 -> V_5 = V_5 ;
V_31 -> V_27 = F_83 ( sizeof( struct V_26 ) , V_39 ) ;
if ( ! V_31 -> V_27 )
return - V_40 ;
F_84 ( V_31 -> V_27 ) ;
V_31 -> V_27 -> V_69 = V_48 -> V_27 ;
V_31 -> V_27 -> V_70 = F_80 ;
V_31 -> V_27 -> V_161 = V_50 ;
F_85 ( V_31 -> V_27 , V_31 ) ;
F_86 ( & V_31 -> V_162 ) ;
V_14 = F_87 ( V_31 -> V_27 ) ;
if ( V_14 < 0 ) {
F_62 ( V_48 -> V_27 ,
L_34 , V_14 ) ;
return V_14 ;
}
V_31 -> V_129 = 1 ;
V_14 = F_88 ( V_31 -> V_27 ) ;
if ( V_14 < 0 )
F_62 ( V_5 -> V_27 ,
L_35 ,
V_14 ) ;
V_14 = F_89 ( V_31 -> V_27 , & V_131 ) ;
if ( V_14 < 0 )
F_62 ( V_5 -> V_27 ,
L_36 , V_14 ) ;
return 0 ;
}
static int F_90 ( struct V_61 * V_48 , int V_111 , int V_128 )
{
struct V_112 * V_81 = & V_48 -> V_81 [ V_111 ] ;
struct V_30 * V_31 = & V_48 -> V_31 [ V_111 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
struct V_59 * V_60 = V_31 -> V_60 ;
struct V_57 * V_78 = V_31 -> V_78 , * V_88 = V_31 -> V_88 ;
int V_14 ;
F_57 ( V_48 -> V_27 , L_37 ,
V_48 -> V_50 , V_111 , V_128 ) ;
V_78 -> V_5 = V_5 ;
V_88 -> V_60 = V_60 ;
V_78 -> V_48 = V_48 ;
V_88 -> V_48 = V_48 ;
V_31 -> V_32 = V_32 ;
if ( ! V_88 -> V_125 &&
V_88 -> V_10 -> V_163 == V_128 ) {
if ( ! F_73 ( V_88 -> V_27 -> V_10 -> V_127 ) )
return - V_142 ;
if ( V_88 -> V_10 -> V_145 ) {
V_14 = V_88 -> V_10 -> V_145 ( V_88 ) ;
if ( V_14 < 0 ) {
F_26 ( V_73 L_38 ,
V_88 -> V_50 ) ;
F_67 ( V_88 -> V_27 -> V_10 -> V_127 ) ;
return V_14 ;
}
}
V_88 -> V_125 = 1 ;
F_77 ( & V_88 -> V_126 , & V_48 -> V_164 ) ;
}
if ( ! V_5 -> V_125 &&
V_5 -> V_10 -> V_163 == V_128 ) {
V_14 = F_72 ( V_48 , V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_60 -> V_125 &&
V_60 -> V_10 -> V_163 == V_128 ) {
V_14 = F_78 ( V_48 , V_60 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_78 -> V_125 && V_78 -> V_10 -> V_163 == V_128 ) {
if ( V_78 -> V_10 -> V_145 ) {
V_14 = V_78 -> V_10 -> V_145 ( V_78 ) ;
if ( V_14 < 0 ) {
F_26 ( V_73 L_39 ,
V_78 -> V_50 ) ;
return V_14 ;
}
}
V_78 -> V_125 = 1 ;
F_77 ( & V_78 -> V_126 , & V_48 -> V_164 ) ;
}
if ( V_128 != V_134 )
return 0 ;
V_14 = F_81 ( V_48 , V_5 , V_111 , 0 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_89 ( V_31 -> V_27 , & V_130 ) ;
if ( V_14 < 0 )
F_26 ( V_51 L_40 ) ;
V_14 = F_91 ( V_31 , V_111 ) ;
if ( V_14 < 0 ) {
F_26 ( V_73 L_41 , V_81 -> V_96 ) ;
return V_14 ;
}
if ( V_31 -> V_78 -> V_10 -> V_90 )
F_92 ( V_5 -> V_65 , V_31 -> V_88 -> V_165 ) ;
return 0 ;
}
static int F_93 ( struct V_30 * V_31 )
{
int V_14 ;
if ( V_31 -> V_78 -> V_10 -> V_90 && ! V_31 -> V_5 -> V_166 ) {
if ( ! V_31 -> V_5 -> V_167 )
return 0 ;
V_14 = F_44 ( V_31 -> V_5 ) ;
if ( V_14 < 0 ) {
F_26 ( V_73 L_42 ) ;
return V_14 ;
}
V_31 -> V_5 -> V_166 = 1 ;
}
return 0 ;
}
static void F_94 ( struct V_4 * V_5 )
{
if ( V_5 -> V_166 ) {
F_41 ( V_5 ) ;
V_5 -> V_166 = 0 ;
}
}
static int F_95 ( struct V_61 * V_48 , int V_111 )
{
struct V_156 * V_157 = & V_48 -> V_157 [ V_111 ] ;
struct V_4 * V_5 ;
int V_14 = - V_142 ;
F_33 (codec, &codec_list, list) {
if ( ! strcmp ( V_5 -> V_50 , V_157 -> V_121 ) ) {
if ( V_5 -> V_125 ) {
F_62 ( V_5 -> V_27 ,
L_43 ) ;
V_14 = - V_168 ;
goto V_123;
}
goto V_169;
}
}
F_62 ( V_48 -> V_27 , L_44 , V_157 -> V_121 ) ;
goto V_123;
V_169:
V_14 = F_72 ( V_48 , V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_81 ( V_48 , V_5 , V_111 , 1 ) ;
V_123:
return V_14 ;
}
static void F_96 ( struct V_61 * V_48 , int V_111 )
{
struct V_30 * V_31 = & V_48 -> V_159 [ V_111 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
if ( V_31 -> V_129 ) {
F_69 ( V_31 -> V_27 , & V_131 ) ;
F_97 ( V_31 -> V_27 ) ;
V_31 -> V_129 = 0 ;
}
if ( V_5 && V_5 -> V_125 )
F_64 ( V_5 ) ;
}
static int F_98 ( struct V_4 * V_5 ,
enum V_170 V_171 )
{
int V_14 ;
if ( V_5 -> V_172 )
return 0 ;
if ( V_171 && V_5 -> V_171 != V_171 )
V_5 -> V_171 = V_171 ;
V_14 = F_99 ( V_5 ) ;
if ( V_14 < 0 ) {
F_62 ( V_5 -> V_27 , L_45 ,
V_14 ) ;
return V_14 ;
}
V_5 -> V_172 = 1 ;
return 0 ;
}
static void F_100 ( struct V_61 * V_48 )
{
struct V_4 * V_5 ;
struct V_137 * V_135 ;
enum V_170 V_171 ;
struct V_112 * V_81 ;
int V_14 , V_3 , V_128 ;
F_101 ( & V_48 -> V_173 ) ;
if ( V_48 -> V_174 ) {
F_102 ( & V_48 -> V_173 ) ;
return;
}
for ( V_3 = 0 ; V_3 < V_48 -> V_175 ; V_3 ++ )
F_63 ( V_48 , V_3 ) ;
if ( V_48 -> V_77 != V_48 -> V_175 ) {
F_102 ( & V_48 -> V_173 ) ;
return;
}
F_33 (codec, &codec_list, list) {
if ( V_5 -> V_172 )
continue;
V_171 = 0 ;
for ( V_3 = 0 ; V_3 < V_48 -> V_136 ; ++ V_3 ) {
V_135 = & V_48 -> V_135 [ V_3 ] ;
if ( ! strcmp ( V_5 -> V_50 , V_135 -> V_139 ) ) {
V_171 = V_135 -> V_171 ;
if ( V_171 && V_171
!= V_5 -> V_171 )
break;
}
}
V_14 = F_98 ( V_5 , V_171 ) ;
if ( V_14 < 0 ) {
F_102 ( & V_48 -> V_173 ) ;
return;
}
}
V_14 = F_103 ( V_176 , V_177 ,
V_48 -> V_127 , 0 , & V_48 -> V_71 ) ;
if ( V_14 < 0 ) {
F_26 ( V_73 L_46 ,
V_48 -> V_50 ) ;
F_102 ( & V_48 -> V_173 ) ;
return;
}
V_48 -> V_71 -> V_27 = V_48 -> V_27 ;
V_48 -> V_56 . V_94 = V_101 ;
V_48 -> V_56 . V_27 = V_48 -> V_27 ;
V_48 -> V_56 . V_48 = V_48 ;
F_77 ( & V_48 -> V_56 . V_151 , & V_48 -> V_152 ) ;
#ifdef F_104
F_29 ( & V_48 -> V_56 , V_48 -> V_47 ) ;
#endif
#ifdef F_105
F_106 ( & V_48 -> V_105 , F_58 ) ;
#endif
if ( V_48 -> V_143 )
F_74 ( & V_48 -> V_56 , V_48 -> V_143 ,
V_48 -> V_144 ) ;
if ( V_48 -> V_145 ) {
V_14 = V_48 -> V_145 ( V_48 ) ;
if ( V_14 < 0 )
goto V_178;
}
for ( V_128 = V_133 ; V_128 <= V_134 ;
V_128 ++ ) {
for ( V_3 = 0 ; V_3 < V_48 -> V_175 ; V_3 ++ ) {
V_14 = F_90 ( V_48 , V_3 , V_128 ) ;
if ( V_14 < 0 ) {
F_107 ( L_47 ,
V_48 -> V_50 , V_14 ) ;
goto V_179;
}
}
}
for ( V_3 = 0 ; V_3 < V_48 -> V_180 ; V_3 ++ ) {
V_14 = F_95 ( V_48 , V_3 ) ;
if ( V_14 < 0 ) {
F_107 ( L_48 ,
V_48 -> V_50 , V_14 ) ;
goto V_181;
}
}
if ( V_48 -> V_147 )
F_75 ( F_108 ( & V_48 -> V_74 ,
struct V_4 ,
V_126 ) ,
V_48 -> V_147 ,
V_48 -> V_148 ) ;
if ( V_48 -> V_149 )
F_76 ( & V_48 -> V_56 , V_48 -> V_149 ,
V_48 -> V_150 ) ;
F_82 ( & V_48 -> V_56 ) ;
for ( V_3 = 0 ; V_3 < V_48 -> V_175 ; V_3 ++ ) {
V_81 = & V_48 -> V_81 [ V_3 ] ;
if ( V_81 -> V_182 ) {
V_14 = F_109 ( V_48 -> V_31 [ V_3 ] . V_78 ,
V_81 -> V_182 ) ;
if ( V_14 != 0 )
F_38 ( V_48 -> V_31 [ V_3 ] . V_78 -> V_27 ,
L_49 ,
V_14 ) ;
V_14 = F_109 ( V_48 -> V_31 [ V_3 ] . V_88 ,
V_81 -> V_182 ) ;
if ( V_14 != 0 )
F_38 ( V_48 -> V_31 [ V_3 ] . V_88 -> V_27 ,
L_49 ,
V_14 ) ;
}
}
snprintf ( V_48 -> V_71 -> V_183 , sizeof( V_48 -> V_71 -> V_183 ) ,
L_50 , V_48 -> V_50 ) ;
snprintf ( V_48 -> V_71 -> V_184 , sizeof( V_48 -> V_71 -> V_184 ) ,
L_50 , V_48 -> V_185 ? V_48 -> V_185 : V_48 -> V_50 ) ;
snprintf ( V_48 -> V_71 -> V_10 , sizeof( V_48 -> V_71 -> V_10 ) ,
L_50 , V_48 -> V_186 ? V_48 -> V_186 : V_48 -> V_50 ) ;
for ( V_3 = 0 ; V_3 < F_110 ( V_48 -> V_71 -> V_10 ) ; V_3 ++ ) {
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
if ( V_48 -> V_187 ) {
V_14 = V_48 -> V_187 ( V_48 ) ;
if ( V_14 < 0 ) {
F_62 ( V_48 -> V_27 , L_51 ,
V_48 -> V_50 , V_14 ) ;
goto V_181;
}
}
F_82 ( & V_48 -> V_56 ) ;
if ( V_48 -> V_188 )
F_33 (codec, &card->codec_dev_list, card_list)
F_111 ( V_5 ) ;
V_14 = F_112 ( V_48 -> V_71 ) ;
if ( V_14 < 0 ) {
F_26 ( V_73 L_52 , V_48 -> V_50 ) ;
goto V_181;
}
#ifdef F_113
for ( V_3 = 0 ; V_3 < V_48 -> V_77 ; V_3 ++ ) {
V_14 = F_93 ( & V_48 -> V_31 [ V_3 ] ) ;
if ( V_14 < 0 ) {
F_26 ( V_73 L_53 , V_48 -> V_50 ) ;
while ( -- V_3 >= 0 )
F_94 ( V_48 -> V_31 [ V_3 ] . V_5 ) ;
goto V_181;
}
}
#endif
V_48 -> V_174 = 1 ;
F_114 ( & V_48 -> V_56 ) ;
F_102 ( & V_48 -> V_173 ) ;
return;
V_181:
for ( V_3 = 0 ; V_3 < V_48 -> V_180 ; V_3 ++ )
F_96 ( V_48 , V_3 ) ;
V_179:
F_70 ( V_48 ) ;
V_178:
if ( V_48 -> remove )
V_48 -> remove ( V_48 ) ;
F_115 ( V_48 -> V_71 ) ;
F_102 ( & V_48 -> V_173 ) ;
}
static void F_116 ( void )
{
struct V_61 * V_48 ;
F_33 (card, &card_list, list)
F_100 ( V_48 ) ;
}
static int F_117 ( struct V_189 * V_190 )
{
struct V_61 * V_48 = F_118 ( V_190 ) ;
int V_14 = 0 ;
if ( ! V_48 )
return - V_17 ;
V_48 -> V_27 = & V_190 -> V_27 ;
V_14 = F_119 ( V_48 ) ;
if ( V_14 != 0 ) {
F_62 ( & V_190 -> V_27 , L_54 ) ;
return V_14 ;
}
return 0 ;
}
static int F_120 ( struct V_61 * V_48 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_48 -> V_77 ; V_3 ++ ) {
struct V_30 * V_31 = & V_48 -> V_31 [ V_3 ] ;
F_55 ( & V_31 -> V_92 ) ;
}
for ( V_3 = 0 ; V_3 < V_48 -> V_180 ; V_3 ++ )
F_96 ( V_48 , V_3 ) ;
F_70 ( V_48 ) ;
F_40 ( V_48 ) ;
if ( V_48 -> remove )
V_48 -> remove ( V_48 ) ;
F_65 ( & V_48 -> V_56 ) ;
F_17 ( V_48 -> V_31 ) ;
F_115 ( V_48 -> V_71 ) ;
return 0 ;
}
static int F_121 ( struct V_189 * V_190 )
{
struct V_61 * V_48 = F_118 ( V_190 ) ;
F_122 ( V_48 ) ;
return 0 ;
}
int F_123 ( struct V_26 * V_27 )
{
struct V_61 * V_48 = F_9 ( V_27 ) ;
int V_3 ;
if ( ! V_48 -> V_174 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_48 -> V_77 ; V_3 ++ ) {
struct V_30 * V_31 = & V_48 -> V_31 [ V_3 ] ;
F_55 ( & V_31 -> V_92 ) ;
}
F_124 ( V_48 ) ;
return 0 ;
}
int F_125 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_191 )
return V_5 -> V_191 ( V_5 , V_6 ) ;
else
return 0 ;
}
int F_6 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_192 )
return V_5 -> V_192 ( V_5 , V_6 ) ;
else
return 1 ;
}
int F_126 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_193 )
return V_5 -> V_193 ( V_5 , V_6 ) ;
else
return 1 ;
}
int F_127 ( struct V_59 * V_60 ,
unsigned int V_6 )
{
unsigned int V_14 ;
if ( ! V_60 -> V_10 -> V_194 ) {
F_62 ( V_60 -> V_27 , L_55 ) ;
return - 1 ;
}
V_14 = V_60 -> V_10 -> V_194 ( V_60 , V_6 ) ;
F_57 ( V_60 -> V_27 , L_56 , V_6 , V_14 ) ;
F_128 ( V_60 , V_6 , V_14 ) ;
return V_14 ;
}
int F_129 ( struct V_59 * V_60 ,
unsigned int V_6 , unsigned int V_1 )
{
if ( ! V_60 -> V_10 -> V_195 ) {
F_62 ( V_60 -> V_27 , L_57 ) ;
return - 1 ;
}
F_57 ( V_60 -> V_27 , L_58 , V_6 , V_1 ) ;
F_130 ( V_60 , V_6 , V_1 ) ;
return V_60 -> V_10 -> V_195 ( V_60 , V_6 , V_1 ) ;
}
int F_131 ( struct V_4 * V_5 ,
struct V_196 * V_83 , int V_111 )
{
F_101 ( & V_5 -> V_173 ) ;
V_5 -> V_65 = F_83 ( sizeof( struct V_197 ) , V_39 ) ;
if ( V_5 -> V_65 == NULL ) {
F_102 ( & V_5 -> V_173 ) ;
return - V_40 ;
}
V_5 -> V_65 -> V_66 = F_83 ( sizeof( struct V_198 ) , V_39 ) ;
if ( V_5 -> V_65 -> V_66 == NULL ) {
F_17 ( V_5 -> V_65 ) ;
V_5 -> V_65 = NULL ;
F_102 ( & V_5 -> V_173 ) ;
return - V_40 ;
}
V_5 -> V_65 -> V_66 -> V_83 = V_83 ;
V_5 -> V_65 -> V_111 = V_111 ;
V_5 -> V_167 = 1 ;
F_102 ( & V_5 -> V_173 ) ;
return 0 ;
}
void F_132 ( struct V_4 * V_5 )
{
F_101 ( & V_5 -> V_173 ) ;
#ifdef F_113
F_94 ( V_5 ) ;
#endif
F_17 ( V_5 -> V_65 -> V_66 ) ;
F_17 ( V_5 -> V_65 ) ;
V_5 -> V_65 = NULL ;
V_5 -> V_167 = 0 ;
F_102 ( & V_5 -> V_173 ) ;
}
unsigned int F_4 ( struct V_4 * V_5 , unsigned int V_6 )
{
unsigned int V_14 ;
V_14 = V_5 -> V_194 ( V_5 , V_6 ) ;
F_57 ( V_5 -> V_27 , L_56 , V_6 , V_14 ) ;
F_133 ( V_5 , V_6 , V_14 ) ;
return V_14 ;
}
unsigned int F_23 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned int V_1 )
{
F_57 ( V_5 -> V_27 , L_58 , V_6 , V_1 ) ;
F_134 ( V_5 , V_6 , V_1 ) ;
return V_5 -> V_195 ( V_5 , V_6 , V_1 ) ;
}
unsigned int F_135 ( struct V_4 * V_5 ,
unsigned int V_6 , const void * V_199 , T_1 V_8 )
{
return V_5 -> V_200 ( V_5 , V_6 , V_199 , V_8 ) ;
}
int F_136 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_201 , unsigned int V_44 )
{
int V_202 ;
unsigned int V_203 , V_204 ;
int V_14 ;
V_14 = F_4 ( V_5 , V_6 ) ;
if ( V_14 < 0 )
return V_14 ;
V_203 = V_14 ;
V_204 = ( V_203 & ~ V_201 ) | ( V_44 & V_201 ) ;
V_202 = V_203 != V_204 ;
if ( V_202 ) {
V_14 = F_23 ( V_5 , V_6 , V_204 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return V_202 ;
}
int F_137 ( struct V_4 * V_5 ,
unsigned short V_6 , unsigned int V_201 ,
unsigned int V_44 )
{
int V_202 ;
F_101 ( & V_5 -> V_173 ) ;
V_202 = F_136 ( V_5 , V_6 , V_201 , V_44 ) ;
F_102 ( & V_5 -> V_173 ) ;
return V_202 ;
}
int F_138 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_201 , unsigned int V_44 )
{
int V_202 ;
unsigned int V_203 , V_204 ;
V_203 = F_4 ( V_5 , V_6 ) ;
V_204 = ( V_203 & ~ V_201 ) | V_44 ;
V_202 = V_203 != V_204 ;
return V_202 ;
}
int F_139 ( struct V_205 * V_206 ,
const struct V_207 * V_208 )
{
struct V_209 * V_210 = V_206 -> V_210 ;
V_210 -> V_208 . V_211 = V_208 -> V_211 ;
V_210 -> V_208 . V_212 = V_208 -> V_212 ;
V_210 -> V_208 . V_213 = V_208 -> V_213 ;
V_210 -> V_208 . V_214 = V_208 -> V_214 ;
V_210 -> V_208 . V_215 = V_208 -> V_215 ;
V_210 -> V_208 . V_216 = V_208 -> V_216 ;
V_210 -> V_208 . V_217 = V_208 -> V_217 ;
V_210 -> V_208 . V_218 = V_208 -> V_218 ;
return 0 ;
}
struct V_219 * F_140 ( const struct V_220 * V_221 ,
void * V_199 , char * V_185 ,
const char * V_222 )
{
struct V_220 V_223 ;
struct V_219 * V_224 ;
char * V_50 = NULL ;
int V_225 ;
memcpy ( & V_223 , V_221 , sizeof( V_223 ) ) ;
V_223 . V_226 = 0 ;
if ( ! V_185 )
V_185 = V_223 . V_50 ;
if ( V_222 ) {
V_225 = strlen ( V_185 ) + strlen ( V_222 ) + 2 ;
V_50 = F_15 ( V_225 , V_39 ) ;
if ( ! V_50 )
return NULL ;
snprintf ( V_50 , V_225 , L_59 , V_222 , V_185 ) ;
V_223 . V_50 = V_50 ;
} else {
V_223 . V_50 = V_185 ;
}
V_224 = F_141 ( & V_223 , V_199 ) ;
F_17 ( V_50 ) ;
return V_224 ;
}
int F_75 ( struct V_4 * V_5 ,
const struct V_220 * V_147 , int V_148 )
{
struct V_71 * V_48 = V_5 -> V_48 -> V_71 ;
int V_67 , V_3 ;
for ( V_3 = 0 ; V_3 < V_148 ; V_3 ++ ) {
const struct V_220 * V_227 = & V_147 [ V_3 ] ;
V_67 = F_142 ( V_48 , F_140 ( V_227 , V_5 ,
V_227 -> V_50 ,
V_5 -> V_140 ) ) ;
if ( V_67 < 0 ) {
F_62 ( V_5 -> V_27 , L_60 ,
V_5 -> V_50 , V_227 -> V_50 , V_67 ) ;
return V_67 ;
}
}
return 0 ;
}
int F_79 ( struct V_59 * V_60 ,
const struct V_220 * V_147 , int V_148 )
{
struct V_71 * V_48 = V_60 -> V_48 -> V_71 ;
int V_67 , V_3 ;
for ( V_3 = 0 ; V_3 < V_148 ; V_3 ++ ) {
const struct V_220 * V_227 = & V_147 [ V_3 ] ;
V_67 = F_142 ( V_48 , F_140 ( V_227 , V_60 ,
V_227 -> V_50 , NULL ) ) ;
if ( V_67 < 0 ) {
F_62 ( V_60 -> V_27 , L_61 , V_227 -> V_50 , V_67 ) ;
return V_67 ;
}
}
return 0 ;
}
int F_143 ( struct V_219 * V_224 ,
struct V_228 * V_229 )
{
struct V_230 * V_231 = (struct V_230 * ) V_224 -> V_232 ;
V_229 -> type = V_233 ;
V_229 -> V_18 = V_231 -> V_234 == V_231 -> V_235 ? 1 : 2 ;
V_229 -> V_44 . V_236 . V_237 = V_231 -> V_238 ;
if ( V_229 -> V_44 . V_236 . V_239 > V_231 -> V_238 - 1 )
V_229 -> V_44 . V_236 . V_239 = V_231 -> V_238 - 1 ;
strcpy ( V_229 -> V_44 . V_236 . V_50 ,
V_231 -> V_240 [ V_229 -> V_44 . V_236 . V_239 ] ) ;
return 0 ;
}
int F_144 ( struct V_219 * V_224 ,
struct V_241 * V_242 )
{
struct V_4 * V_5 = F_145 ( V_224 ) ;
struct V_230 * V_231 = (struct V_230 * ) V_224 -> V_232 ;
unsigned int V_1 , V_243 ;
for ( V_243 = 1 ; V_243 < V_231 -> V_238 ; V_243 <<= 1 )
;
V_1 = F_4 ( V_5 , V_231 -> V_6 ) ;
V_242 -> V_44 . V_236 . V_239 [ 0 ]
= ( V_1 >> V_231 -> V_234 ) & ( V_243 - 1 ) ;
if ( V_231 -> V_234 != V_231 -> V_235 )
V_242 -> V_44 . V_236 . V_239 [ 1 ] =
( V_1 >> V_231 -> V_235 ) & ( V_243 - 1 ) ;
return 0 ;
}
int F_146 ( struct V_219 * V_224 ,
struct V_241 * V_242 )
{
struct V_4 * V_5 = F_145 ( V_224 ) ;
struct V_230 * V_231 = (struct V_230 * ) V_224 -> V_232 ;
unsigned int V_1 ;
unsigned int V_201 , V_243 ;
for ( V_243 = 1 ; V_243 < V_231 -> V_238 ; V_243 <<= 1 )
;
if ( V_242 -> V_44 . V_236 . V_239 [ 0 ] > V_231 -> V_238 - 1 )
return - V_17 ;
V_1 = V_242 -> V_44 . V_236 . V_239 [ 0 ] << V_231 -> V_234 ;
V_201 = ( V_243 - 1 ) << V_231 -> V_234 ;
if ( V_231 -> V_234 != V_231 -> V_235 ) {
if ( V_242 -> V_44 . V_236 . V_239 [ 1 ] > V_231 -> V_238 - 1 )
return - V_17 ;
V_1 |= V_242 -> V_44 . V_236 . V_239 [ 1 ] << V_231 -> V_235 ;
V_201 |= ( V_243 - 1 ) << V_231 -> V_235 ;
}
return F_137 ( V_5 , V_231 -> V_6 , V_201 , V_1 ) ;
}
int F_147 ( struct V_219 * V_224 ,
struct V_241 * V_242 )
{
struct V_4 * V_5 = F_145 ( V_224 ) ;
struct V_230 * V_231 = (struct V_230 * ) V_224 -> V_232 ;
unsigned int V_244 , V_1 , V_245 ;
V_244 = F_4 ( V_5 , V_231 -> V_6 ) ;
V_1 = ( V_244 >> V_231 -> V_234 ) & V_231 -> V_201 ;
for ( V_245 = 0 ; V_245 < V_231 -> V_238 ; V_245 ++ ) {
if ( V_1 == V_231 -> V_246 [ V_245 ] )
break;
}
V_242 -> V_44 . V_236 . V_239 [ 0 ] = V_245 ;
if ( V_231 -> V_234 != V_231 -> V_235 ) {
V_1 = ( V_244 >> V_231 -> V_235 ) & V_231 -> V_201 ;
for ( V_245 = 0 ; V_245 < V_231 -> V_238 ; V_245 ++ ) {
if ( V_1 == V_231 -> V_246 [ V_245 ] )
break;
}
V_242 -> V_44 . V_236 . V_239 [ 1 ] = V_245 ;
}
return 0 ;
}
int F_148 ( struct V_219 * V_224 ,
struct V_241 * V_242 )
{
struct V_4 * V_5 = F_145 ( V_224 ) ;
struct V_230 * V_231 = (struct V_230 * ) V_224 -> V_232 ;
unsigned int V_1 ;
unsigned int V_201 ;
if ( V_242 -> V_44 . V_236 . V_239 [ 0 ] > V_231 -> V_238 - 1 )
return - V_17 ;
V_1 = V_231 -> V_246 [ V_242 -> V_44 . V_236 . V_239 [ 0 ] ] << V_231 -> V_234 ;
V_201 = V_231 -> V_201 << V_231 -> V_234 ;
if ( V_231 -> V_234 != V_231 -> V_235 ) {
if ( V_242 -> V_44 . V_236 . V_239 [ 1 ] > V_231 -> V_238 - 1 )
return - V_17 ;
V_1 |= V_231 -> V_246 [ V_242 -> V_44 . V_236 . V_239 [ 1 ] ] << V_231 -> V_235 ;
V_201 |= V_231 -> V_201 << V_231 -> V_235 ;
}
return F_137 ( V_5 , V_231 -> V_6 , V_201 , V_1 ) ;
}
int F_149 ( struct V_219 * V_224 ,
struct V_228 * V_229 )
{
struct V_230 * V_231 = (struct V_230 * ) V_224 -> V_232 ;
V_229 -> type = V_233 ;
V_229 -> V_18 = 1 ;
V_229 -> V_44 . V_236 . V_237 = V_231 -> V_238 ;
if ( V_229 -> V_44 . V_236 . V_239 > V_231 -> V_238 - 1 )
V_229 -> V_44 . V_236 . V_239 = V_231 -> V_238 - 1 ;
strcpy ( V_229 -> V_44 . V_236 . V_50 ,
V_231 -> V_240 [ V_229 -> V_44 . V_236 . V_239 ] ) ;
return 0 ;
}
int F_150 ( struct V_219 * V_224 ,
struct V_228 * V_229 )
{
int V_238 = V_224 -> V_232 ;
if ( V_238 == 1 && ! strstr ( V_224 -> V_247 . V_50 , L_62 ) )
V_229 -> type = V_248 ;
else
V_229 -> type = V_249 ;
V_229 -> V_18 = 1 ;
V_229 -> V_44 . integer . F_7 = 0 ;
V_229 -> V_44 . integer . V_238 = V_238 ;
return 0 ;
}
int F_151 ( struct V_219 * V_224 ,
struct V_228 * V_229 )
{
struct V_250 * V_251 =
(struct V_250 * ) V_224 -> V_232 ;
int V_252 ;
if ( ! V_251 -> V_252 )
V_251 -> V_252 = V_251 -> V_238 ;
V_252 = V_251 -> V_252 ;
if ( V_252 == 1 && ! strstr ( V_224 -> V_247 . V_50 , L_62 ) )
V_229 -> type = V_248 ;
else
V_229 -> type = V_249 ;
V_229 -> V_18 = F_152 ( V_251 ) ? 2 : 1 ;
V_229 -> V_44 . integer . F_7 = 0 ;
V_229 -> V_44 . integer . V_238 = V_252 ;
return 0 ;
}
int F_153 ( struct V_219 * V_224 ,
struct V_241 * V_242 )
{
struct V_250 * V_251 =
(struct V_250 * ) V_224 -> V_232 ;
struct V_4 * V_5 = F_145 ( V_224 ) ;
unsigned int V_6 = V_251 -> V_6 ;
unsigned int V_253 = V_251 -> V_254 ;
unsigned int V_255 = V_251 -> V_255 ;
unsigned int V_256 = V_251 -> V_256 ;
int V_238 = V_251 -> V_238 ;
unsigned int V_201 = ( 1 << F_154 ( V_238 ) ) - 1 ;
unsigned int V_257 = V_251 -> V_257 ;
V_242 -> V_44 . integer . V_44 [ 0 ] =
( F_4 ( V_5 , V_6 ) >> V_255 ) & V_201 ;
if ( V_257 )
V_242 -> V_44 . integer . V_44 [ 0 ] =
V_238 - V_242 -> V_44 . integer . V_44 [ 0 ] ;
if ( F_152 ( V_251 ) ) {
if ( V_6 == V_253 )
V_242 -> V_44 . integer . V_44 [ 1 ] =
( F_4 ( V_5 , V_6 ) >> V_256 ) & V_201 ;
else
V_242 -> V_44 . integer . V_44 [ 1 ] =
( F_4 ( V_5 , V_253 ) >> V_255 ) & V_201 ;
if ( V_257 )
V_242 -> V_44 . integer . V_44 [ 1 ] =
V_238 - V_242 -> V_44 . integer . V_44 [ 1 ] ;
}
return 0 ;
}
int F_155 ( struct V_219 * V_224 ,
struct V_241 * V_242 )
{
struct V_250 * V_251 =
(struct V_250 * ) V_224 -> V_232 ;
struct V_4 * V_5 = F_145 ( V_224 ) ;
unsigned int V_6 = V_251 -> V_6 ;
unsigned int V_253 = V_251 -> V_254 ;
unsigned int V_255 = V_251 -> V_255 ;
unsigned int V_256 = V_251 -> V_256 ;
int V_238 = V_251 -> V_238 ;
unsigned int V_201 = ( 1 << F_154 ( V_238 ) ) - 1 ;
unsigned int V_257 = V_251 -> V_257 ;
int V_67 ;
bool V_258 = 0 ;
unsigned int V_259 = 0 ;
unsigned int V_1 , V_260 ;
V_1 = ( V_242 -> V_44 . integer . V_44 [ 0 ] & V_201 ) ;
if ( V_257 )
V_1 = V_238 - V_1 ;
V_260 = V_201 << V_255 ;
V_1 = V_1 << V_255 ;
if ( F_152 ( V_251 ) ) {
V_259 = ( V_242 -> V_44 . integer . V_44 [ 1 ] & V_201 ) ;
if ( V_257 )
V_259 = V_238 - V_259 ;
if ( V_6 == V_253 ) {
V_260 |= V_201 << V_256 ;
V_1 |= V_259 << V_256 ;
} else {
V_259 = V_259 << V_255 ;
V_258 = 1 ;
}
}
V_67 = F_137 ( V_5 , V_6 , V_260 , V_1 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( V_258 )
V_67 = F_137 ( V_5 , V_253 , V_260 , V_259 ) ;
return V_67 ;
}
int F_156 ( struct V_219 * V_224 ,
struct V_228 * V_229 )
{
struct V_250 * V_251 =
(struct V_250 * ) V_224 -> V_232 ;
int V_252 ;
int F_7 = V_251 -> F_7 ;
if ( ! V_251 -> V_252 )
V_251 -> V_252 = V_251 -> V_238 ;
V_252 = V_251 -> V_252 ;
V_229 -> type = V_249 ;
V_229 -> V_18 = 2 ;
V_229 -> V_44 . integer . F_7 = 0 ;
V_229 -> V_44 . integer . V_238 = V_252 - F_7 ;
return 0 ;
}
int F_157 ( struct V_219 * V_224 ,
struct V_241 * V_242 )
{
struct V_250 * V_251 =
(struct V_250 * ) V_224 -> V_232 ;
struct V_4 * V_5 = F_145 ( V_224 ) ;
unsigned int V_6 = V_251 -> V_6 ;
int F_7 = V_251 -> F_7 ;
int V_1 = F_4 ( V_5 , V_6 ) ;
V_242 -> V_44 . integer . V_44 [ 0 ] =
( ( signed char ) ( V_1 & 0xff ) ) - F_7 ;
V_242 -> V_44 . integer . V_44 [ 1 ] =
( ( signed char ) ( ( V_1 >> 8 ) & 0xff ) ) - F_7 ;
return 0 ;
}
int F_158 ( struct V_219 * V_224 ,
struct V_241 * V_242 )
{
struct V_250 * V_251 =
(struct V_250 * ) V_224 -> V_232 ;
struct V_4 * V_5 = F_145 ( V_224 ) ;
unsigned int V_6 = V_251 -> V_6 ;
int F_7 = V_251 -> F_7 ;
unsigned int V_1 ;
V_1 = ( V_242 -> V_44 . integer . V_44 [ 0 ] + F_7 ) & 0xff ;
V_1 |= ( ( V_242 -> V_44 . integer . V_44 [ 1 ] + F_7 ) & 0xff ) << 8 ;
return F_137 ( V_5 , V_6 , 0xffff , V_1 ) ;
}
int F_159 ( struct V_4 * V_5 ,
const char * V_50 , int V_238 )
{
struct V_71 * V_48 = V_5 -> V_48 -> V_71 ;
struct V_219 * V_261 ;
struct V_250 * V_251 ;
int V_169 = 0 ;
int V_14 = - V_17 ;
if ( F_160 ( ! V_50 || V_238 <= 0 ) )
return - V_17 ;
F_33 (kctl, &card->controls, list) {
if ( ! strncmp ( V_261 -> V_247 . V_50 , V_50 , sizeof( V_261 -> V_247 . V_50 ) ) ) {
V_169 = 1 ;
break;
}
}
if ( V_169 ) {
V_251 = (struct V_250 * ) V_261 -> V_232 ;
if ( V_238 <= V_251 -> V_238 ) {
V_251 -> V_252 = V_238 ;
V_14 = 0 ;
}
}
return V_14 ;
}
int F_161 ( struct V_219 * V_224 ,
struct V_228 * V_229 )
{
struct V_250 * V_251 =
(struct V_250 * ) V_224 -> V_232 ;
int V_238 = V_251 -> V_238 ;
int F_7 = V_251 -> F_7 ;
V_229 -> type = V_249 ;
V_229 -> V_18 = 2 ;
V_229 -> V_44 . integer . F_7 = 0 ;
V_229 -> V_44 . integer . V_238 = V_238 - F_7 ;
return 0 ;
}
int F_162 ( struct V_219 * V_224 ,
struct V_241 * V_242 )
{
struct V_250 * V_251 =
(struct V_250 * ) V_224 -> V_232 ;
struct V_4 * V_5 = F_145 ( V_224 ) ;
unsigned int V_201 = ( 1 << V_251 -> V_255 ) - 1 ;
int F_7 = V_251 -> F_7 ;
int V_1 = F_4 ( V_5 , V_251 -> V_6 ) & V_201 ;
int V_262 = F_4 ( V_5 , V_251 -> V_254 ) & V_201 ;
V_242 -> V_44 . integer . V_44 [ 0 ] = ( ( V_1 & 0xff ) - F_7 ) & V_201 ;
V_242 -> V_44 . integer . V_44 [ 1 ] = ( ( V_262 & 0xff ) - F_7 ) & V_201 ;
return 0 ;
}
int F_163 ( struct V_219 * V_224 ,
struct V_241 * V_242 )
{
struct V_250 * V_251 =
(struct V_250 * ) V_224 -> V_232 ;
struct V_4 * V_5 = F_145 ( V_224 ) ;
unsigned int V_201 = ( 1 << V_251 -> V_255 ) - 1 ;
int F_7 = V_251 -> F_7 ;
int V_14 ;
unsigned int V_1 , V_262 , V_263 , V_264 ;
V_1 = ( ( V_242 -> V_44 . integer . V_44 [ 0 ] + F_7 ) & 0xff ) ;
V_1 &= V_201 ;
V_262 = ( ( V_242 -> V_44 . integer . V_44 [ 1 ] + F_7 ) & 0xff ) ;
V_262 &= V_201 ;
V_263 = F_4 ( V_5 , V_251 -> V_6 ) & V_201 ;
V_264 = F_4 ( V_5 , V_251 -> V_254 ) & V_201 ;
V_14 = 0 ;
if ( V_263 != V_1 ) {
V_14 = F_23 ( V_5 , V_251 -> V_6 , V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( V_264 != V_262 ) {
V_14 = F_23 ( V_5 , V_251 -> V_254 , V_262 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
int F_164 ( struct V_57 * V_58 , int V_265 ,
unsigned int V_266 , int V_267 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_83 -> V_268 )
return V_58 -> V_10 -> V_83 -> V_268 ( V_58 , V_265 , V_266 , V_267 ) ;
else if ( V_58 -> V_5 && V_58 -> V_5 -> V_10 -> V_268 )
return V_58 -> V_5 -> V_10 -> V_268 ( V_58 -> V_5 , V_265 , 0 ,
V_266 , V_267 ) ;
else
return - V_17 ;
}
int F_165 ( struct V_4 * V_5 , int V_265 ,
int V_269 , unsigned int V_266 , int V_267 )
{
if ( V_5 -> V_10 -> V_268 )
return V_5 -> V_10 -> V_268 ( V_5 , V_265 , V_269 ,
V_266 , V_267 ) ;
else
return - V_17 ;
}
int F_166 ( struct V_57 * V_58 ,
int V_270 , int div )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_83 -> V_271 )
return V_58 -> V_10 -> V_83 -> V_271 ( V_58 , V_270 , div ) ;
else
return - V_17 ;
}
int F_167 ( struct V_57 * V_58 , int V_272 , int V_269 ,
unsigned int V_273 , unsigned int V_274 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_83 -> V_275 )
return V_58 -> V_10 -> V_83 -> V_275 ( V_58 , V_272 , V_269 ,
V_273 , V_274 ) ;
else if ( V_58 -> V_5 && V_58 -> V_5 -> V_10 -> V_275 )
return V_58 -> V_5 -> V_10 -> V_275 ( V_58 -> V_5 , V_272 , V_269 ,
V_273 , V_274 ) ;
else
return - V_17 ;
}
int F_168 ( struct V_4 * V_5 , int V_272 , int V_269 ,
unsigned int V_273 , unsigned int V_274 )
{
if ( V_5 -> V_10 -> V_275 )
return V_5 -> V_10 -> V_275 ( V_5 , V_272 , V_269 ,
V_273 , V_274 ) ;
else
return - V_17 ;
}
int F_109 ( struct V_57 * V_58 , unsigned int V_276 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_83 -> V_277 )
return V_58 -> V_10 -> V_83 -> V_277 ( V_58 , V_276 ) ;
else
return - V_17 ;
}
int F_169 ( struct V_57 * V_58 ,
unsigned int V_278 , unsigned int V_279 , int V_280 , int V_281 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_83 -> V_282 )
return V_58 -> V_10 -> V_83 -> V_282 ( V_58 , V_278 , V_279 ,
V_280 , V_281 ) ;
else
return - V_17 ;
}
int F_170 ( struct V_57 * V_58 ,
unsigned int V_283 , unsigned int * V_284 ,
unsigned int V_285 , unsigned int * V_286 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_83 -> V_287 )
return V_58 -> V_10 -> V_83 -> V_287 ( V_58 , V_283 , V_284 ,
V_285 , V_286 ) ;
else
return - V_17 ;
}
int F_171 ( struct V_57 * V_58 , int V_288 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_83 -> V_289 )
return V_58 -> V_10 -> V_83 -> V_289 ( V_58 , V_288 ) ;
else
return - V_17 ;
}
int F_172 ( struct V_57 * V_58 , int V_290 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_83 -> V_84 )
return V_58 -> V_10 -> V_83 -> V_84 ( V_58 , V_290 ) ;
else
return - V_17 ;
}
int F_119 ( struct V_61 * V_48 )
{
int V_3 ;
if ( ! V_48 -> V_50 || ! V_48 -> V_27 )
return - V_17 ;
for ( V_3 = 0 ; V_3 < V_48 -> V_175 ; V_3 ++ ) {
struct V_112 * V_291 = & V_48 -> V_81 [ V_3 ] ;
if ( ! ! V_291 -> V_121 == ! ! V_291 -> V_120 ) {
F_62 ( V_48 -> V_27 ,
L_63 ) ;
return - V_17 ;
}
if ( V_291 -> V_113 && V_291 -> V_124 ) {
F_62 ( V_48 -> V_27 ,
L_64 ) ;
return - V_17 ;
}
if ( ! ! V_291 -> V_118 == ! ! V_291 -> V_116 ) {
F_62 ( V_48 -> V_27 ,
L_65 ) ;
return - V_17 ;
}
}
F_85 ( V_48 -> V_27 , V_48 ) ;
F_173 ( V_48 ) ;
F_37 ( V_48 ) ;
V_48 -> V_31 = F_83 ( sizeof( struct V_30 ) *
( V_48 -> V_175 + V_48 -> V_180 ) ,
V_39 ) ;
if ( V_48 -> V_31 == NULL )
return - V_40 ;
V_48 -> V_159 = & V_48 -> V_31 [ V_48 -> V_175 ] ;
for ( V_3 = 0 ; V_3 < V_48 -> V_175 ; V_3 ++ )
V_48 -> V_31 [ V_3 ] . V_81 = & V_48 -> V_81 [ V_3 ] ;
F_174 ( & V_48 -> V_151 ) ;
F_174 ( & V_48 -> V_292 ) ;
V_48 -> V_174 = 0 ;
F_86 ( & V_48 -> V_173 ) ;
F_101 ( & V_293 ) ;
F_77 ( & V_48 -> V_151 , & V_126 ) ;
F_116 () ;
F_102 ( & V_293 ) ;
F_57 ( V_48 -> V_27 , L_66 , V_48 -> V_50 ) ;
return 0 ;
}
int F_122 ( struct V_61 * V_48 )
{
if ( V_48 -> V_174 )
F_120 ( V_48 ) ;
F_101 ( & V_293 ) ;
F_66 ( & V_48 -> V_151 ) ;
F_102 ( & V_293 ) ;
F_57 ( V_48 -> V_27 , L_67 , V_48 -> V_50 ) ;
return 0 ;
}
static char * F_175 ( struct V_26 * V_27 , int * V_247 )
{
char * V_169 , V_50 [ V_294 ] ;
int V_295 , V_296 ;
if ( V_139 ( V_27 ) == NULL )
return NULL ;
F_176 ( V_50 , V_139 ( V_27 ) , V_294 ) ;
V_169 = strstr ( V_50 , V_27 -> V_10 -> V_50 ) ;
if ( V_169 ) {
if ( sscanf ( & V_169 [ strlen ( V_27 -> V_10 -> V_50 ) ] , L_68 , V_247 ) == 1 ) {
if ( * V_247 == - 1 )
V_169 [ strlen ( V_27 -> V_10 -> V_50 ) ] = '\0' ;
}
} else {
if ( sscanf ( V_50 , L_69 , & V_295 , & V_296 ) == 2 ) {
char V_297 [ V_294 ] ;
* V_247 = ( ( V_295 & 0xffff ) << 16 ) + V_296 ;
snprintf ( V_297 , V_294 , L_70 , V_27 -> V_10 -> V_50 , V_50 ) ;
F_176 ( V_50 , V_297 , V_294 ) ;
} else
* V_247 = 0 ;
}
return F_177 ( V_50 , V_39 ) ;
}
static inline char * F_178 ( struct V_26 * V_27 ,
struct V_79 * V_298 )
{
if ( V_298 -> V_50 == NULL ) {
F_26 ( V_73 L_71 ,
V_139 ( V_27 ) ) ;
return NULL ;
}
return F_177 ( V_298 -> V_50 , V_39 ) ;
}
int F_179 ( struct V_26 * V_27 ,
struct V_79 * V_298 )
{
struct V_57 * V_58 ;
F_57 ( V_27 , L_72 , V_139 ( V_27 ) ) ;
V_58 = F_83 ( sizeof( struct V_57 ) , V_39 ) ;
if ( V_58 == NULL )
return - V_40 ;
V_58 -> V_50 = F_175 ( V_27 , & V_58 -> V_247 ) ;
if ( V_58 -> V_50 == NULL ) {
F_17 ( V_58 ) ;
return - V_40 ;
}
V_58 -> V_27 = V_27 ;
V_58 -> V_10 = V_298 ;
if ( ! V_58 -> V_10 -> V_83 )
V_58 -> V_10 -> V_83 = & V_299 ;
F_101 ( & V_293 ) ;
F_77 ( & V_58 -> V_151 , & V_300 ) ;
F_116 () ;
F_102 ( & V_293 ) ;
F_180 ( L_73 , V_58 -> V_50 ) ;
return 0 ;
}
void F_181 ( struct V_26 * V_27 )
{
struct V_57 * V_58 ;
F_33 (dai, &dai_list, list) {
if ( V_27 == V_58 -> V_27 )
goto V_169;
}
return;
V_169:
F_101 ( & V_293 ) ;
F_66 ( & V_58 -> V_151 ) ;
F_102 ( & V_293 ) ;
F_180 ( L_74 , V_58 -> V_50 ) ;
F_17 ( V_58 -> V_50 ) ;
F_17 ( V_58 ) ;
}
int F_182 ( struct V_26 * V_27 ,
struct V_79 * V_298 , T_1 V_18 )
{
struct V_57 * V_58 ;
int V_3 , V_14 = 0 ;
F_57 ( V_27 , L_75 , V_139 ( V_27 ) , V_18 ) ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ ) {
V_58 = F_83 ( sizeof( struct V_57 ) , V_39 ) ;
if ( V_58 == NULL ) {
V_14 = - V_40 ;
goto V_67;
}
V_58 -> V_50 = F_178 ( V_27 , & V_298 [ V_3 ] ) ;
if ( V_58 -> V_50 == NULL ) {
F_17 ( V_58 ) ;
V_14 = - V_17 ;
goto V_67;
}
V_58 -> V_27 = V_27 ;
V_58 -> V_10 = & V_298 [ V_3 ] ;
if ( V_58 -> V_10 -> V_247 )
V_58 -> V_247 = V_58 -> V_10 -> V_247 ;
else
V_58 -> V_247 = V_3 ;
if ( ! V_58 -> V_10 -> V_83 )
V_58 -> V_10 -> V_83 = & V_299 ;
F_101 ( & V_293 ) ;
F_77 ( & V_58 -> V_151 , & V_300 ) ;
F_102 ( & V_293 ) ;
F_180 ( L_73 , V_58 -> V_50 ) ;
}
F_101 ( & V_293 ) ;
F_116 () ;
F_102 ( & V_293 ) ;
return 0 ;
V_67:
for ( V_3 -- ; V_3 >= 0 ; V_3 -- )
F_181 ( V_27 ) ;
return V_14 ;
}
void F_183 ( struct V_26 * V_27 , T_1 V_18 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ )
F_181 ( V_27 ) ;
}
int F_184 ( struct V_26 * V_27 ,
struct V_153 * V_301 )
{
struct V_59 * V_60 ;
F_57 ( V_27 , L_76 , V_139 ( V_27 ) ) ;
V_60 = F_83 ( sizeof( struct V_59 ) , V_39 ) ;
if ( V_60 == NULL )
return - V_40 ;
V_60 -> V_50 = F_175 ( V_27 , & V_60 -> V_247 ) ;
if ( V_60 -> V_50 == NULL ) {
F_17 ( V_60 ) ;
return - V_40 ;
}
V_60 -> V_27 = V_27 ;
V_60 -> V_10 = V_301 ;
V_60 -> V_56 . V_27 = V_27 ;
V_60 -> V_56 . V_60 = V_60 ;
V_60 -> V_56 . V_302 = V_301 -> V_302 ;
F_101 ( & V_293 ) ;
F_77 ( & V_60 -> V_151 , & V_303 ) ;
F_116 () ;
F_102 ( & V_293 ) ;
F_180 ( L_77 , V_60 -> V_50 ) ;
return 0 ;
}
void F_185 ( struct V_26 * V_27 )
{
struct V_59 * V_60 ;
F_33 (platform, &platform_list, list) {
if ( V_27 == V_60 -> V_27 )
goto V_169;
}
return;
V_169:
F_101 ( & V_293 ) ;
F_66 ( & V_60 -> V_151 ) ;
F_102 ( & V_293 ) ;
F_180 ( L_78 , V_60 -> V_50 ) ;
F_17 ( V_60 -> V_50 ) ;
F_17 ( V_60 ) ;
}
static void F_186 ( struct V_304 * V_305 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_110 ( V_306 ) ; V_3 ++ )
if ( V_305 -> V_212 & V_306 [ V_3 ] )
V_305 -> V_212 |= V_306 [ V_3 ] ;
}
int F_187 ( struct V_26 * V_27 ,
const struct V_141 * V_307 ,
struct V_79 * V_298 ,
int V_308 )
{
T_1 V_309 ;
struct V_4 * V_5 ;
int V_14 , V_3 ;
F_57 ( V_27 , L_79 , V_139 ( V_27 ) ) ;
V_5 = F_83 ( sizeof( struct V_4 ) , V_39 ) ;
if ( V_5 == NULL )
return - V_40 ;
V_5 -> V_50 = F_175 ( V_27 , & V_5 -> V_247 ) ;
if ( V_5 -> V_50 == NULL ) {
F_17 ( V_5 ) ;
return - V_40 ;
}
if ( V_307 -> V_171 )
V_5 -> V_171 = V_307 -> V_171 ;
else
V_5 -> V_171 = V_310 ;
V_5 -> V_195 = V_307 -> V_195 ;
V_5 -> V_194 = V_307 -> V_194 ;
V_5 -> V_191 = V_307 -> V_191 ;
V_5 -> V_192 = V_307 -> V_192 ;
V_5 -> V_193 = V_307 -> V_193 ;
V_5 -> V_56 . V_94 = V_101 ;
V_5 -> V_56 . V_27 = V_27 ;
V_5 -> V_56 . V_5 = V_5 ;
V_5 -> V_56 . V_311 = V_307 -> V_311 ;
V_5 -> V_56 . V_302 = V_307 -> V_302 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_10 = V_307 ;
V_5 -> V_308 = V_308 ;
F_86 ( & V_5 -> V_173 ) ;
if ( V_307 -> V_11 && V_307 -> V_13 ) {
V_309 = V_307 -> V_11 * V_307 -> V_13 ;
V_5 -> V_309 = V_309 ;
if ( V_307 -> V_312 ) {
V_5 -> V_313 = F_188 ( V_307 -> V_312 ,
V_309 , V_39 ) ;
if ( ! V_5 -> V_313 ) {
V_14 = - V_40 ;
goto V_314;
}
}
}
if ( V_307 -> V_315 && V_307 -> V_316 ) {
if ( ! V_5 -> V_191 )
V_5 -> V_191 = V_317 ;
if ( ! V_5 -> V_192 )
V_5 -> V_192 = V_318 ;
if ( ! V_5 -> V_193 )
V_5 -> V_193 = V_319 ;
}
for ( V_3 = 0 ; V_3 < V_308 ; V_3 ++ ) {
F_186 ( & V_298 [ V_3 ] . V_95 ) ;
F_186 ( & V_298 [ V_3 ] . V_98 ) ;
}
if ( V_308 ) {
V_14 = F_182 ( V_27 , V_298 , V_308 ) ;
if ( V_14 < 0 )
goto V_314;
}
F_101 ( & V_293 ) ;
F_77 ( & V_5 -> V_151 , & V_320 ) ;
F_116 () ;
F_102 ( & V_293 ) ;
F_180 ( L_80 , V_5 -> V_50 ) ;
return 0 ;
V_314:
F_17 ( V_5 -> V_313 ) ;
V_5 -> V_313 = NULL ;
F_17 ( V_5 -> V_50 ) ;
F_17 ( V_5 ) ;
return V_14 ;
}
void F_189 ( struct V_26 * V_27 )
{
struct V_4 * V_5 ;
int V_3 ;
F_33 (codec, &codec_list, list) {
if ( V_27 == V_5 -> V_27 )
goto V_169;
}
return;
V_169:
if ( V_5 -> V_308 )
for ( V_3 = 0 ; V_3 < V_5 -> V_308 ; V_3 ++ )
F_181 ( V_27 ) ;
F_101 ( & V_293 ) ;
F_66 ( & V_5 -> V_151 ) ;
F_102 ( & V_293 ) ;
F_180 ( L_81 , V_5 -> V_50 ) ;
F_190 ( V_5 ) ;
F_17 ( V_5 -> V_313 ) ;
F_17 ( V_5 -> V_50 ) ;
F_17 ( V_5 ) ;
}
int F_191 ( struct V_61 * V_48 ,
const char * V_321 )
{
struct V_322 * V_323 = V_48 -> V_27 -> V_117 ;
int V_14 ;
V_14 = F_192 ( V_323 , V_321 , 0 , & V_48 -> V_50 ) ;
if ( V_14 < 0 && V_14 != - V_17 ) {
F_62 ( V_48 -> V_27 ,
L_82 ,
V_321 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
int F_193 ( struct V_61 * V_48 ,
const char * V_321 )
{
struct V_322 * V_323 = V_48 -> V_27 -> V_117 ;
int V_324 ;
struct V_325 * V_326 ;
int V_3 , V_14 ;
V_324 = F_194 ( V_323 , V_321 ) ;
if ( V_324 & 1 ) {
F_62 ( V_48 -> V_27 ,
L_83 ,
V_321 ) ;
return - V_17 ;
}
V_324 /= 2 ;
if ( ! V_324 ) {
F_62 ( V_48 -> V_27 ,
L_84 ,
V_321 ) ;
return - V_17 ;
}
V_326 = F_195 ( V_48 -> V_27 , V_324 * sizeof( * V_326 ) ,
V_39 ) ;
if ( ! V_326 ) {
F_62 ( V_48 -> V_27 ,
L_85 ) ;
return - V_17 ;
}
for ( V_3 = 0 ; V_3 < V_324 ; V_3 ++ ) {
V_14 = F_192 ( V_323 , V_321 ,
2 * V_3 , & V_326 [ V_3 ] . V_327 ) ;
if ( V_14 ) {
F_62 ( V_48 -> V_27 ,
L_86 ,
V_321 , 2 * V_3 , V_14 ) ;
return - V_17 ;
}
V_14 = F_192 ( V_323 , V_321 ,
( 2 * V_3 ) + 1 , & V_326 [ V_3 ] . V_269 ) ;
if ( V_14 ) {
F_62 ( V_48 -> V_27 ,
L_86 ,
V_321 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_17 ;
}
}
V_48 -> V_150 = V_324 ;
V_48 -> V_149 = V_326 ;
return 0 ;
}
static int T_5 F_196 ( void )
{
#ifdef F_104
V_62 = F_25 ( L_87 , NULL ) ;
if ( F_197 ( V_62 ) || ! V_62 ) {
F_26 ( V_51
L_88 ) ;
V_62 = NULL ;
}
if ( ! F_28 ( L_89 , 0444 , V_62 , NULL ,
& V_328 ) )
F_198 ( L_90 ) ;
if ( ! F_28 ( L_91 , 0444 , V_62 , NULL ,
& V_329 ) )
F_198 ( L_92 ) ;
if ( ! F_28 ( L_93 , 0444 , V_62 , NULL ,
& V_330 ) )
F_198 ( L_94 ) ;
#endif
F_199 () ;
return F_200 ( & V_331 ) ;
}
static void T_6 F_201 ( void )
{
F_202 () ;
#ifdef F_104
F_31 ( V_62 ) ;
#endif
F_203 ( & V_331 ) ;
}
