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
static int F_41 ( struct V_4 * V_5 )
{
if ( V_5 -> V_63 -> V_27 . V_64 )
F_42 ( & V_5 -> V_63 -> V_27 ) ;
return 0 ;
}
static void F_43 ( struct V_26 * V_27 ) {}
static int F_44 ( struct V_4 * V_5 )
{
int V_65 ;
V_5 -> V_63 -> V_27 . V_64 = & V_66 ;
V_5 -> V_63 -> V_27 . V_67 = V_5 -> V_46 -> V_27 ;
V_5 -> V_63 -> V_27 . V_68 = F_43 ;
F_45 ( & V_5 -> V_63 -> V_27 , L_14 ,
V_5 -> V_46 -> V_69 -> V_70 , 0 , V_5 -> V_48 ) ;
V_65 = F_46 ( & V_5 -> V_63 -> V_27 ) ;
if ( V_65 < 0 ) {
F_47 ( V_71 L_15 ) ;
V_5 -> V_63 -> V_27 . V_64 = NULL ;
return V_65 ;
}
return 0 ;
}
int F_48 ( struct V_26 * V_27 )
{
struct V_59 * V_46 = F_9 ( V_27 ) ;
struct V_4 * V_5 ;
int V_3 ;
if ( F_49 ( & V_46 -> V_72 ) )
return 0 ;
F_50 ( V_46 -> V_69 ) ;
F_51 ( V_46 -> V_69 , V_73 ) ;
F_52 ( V_46 -> V_69 ) ;
F_53 ( V_46 -> V_69 , V_74 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_75 ; V_3 ++ ) {
struct V_57 * V_58 = V_46 -> V_31 [ V_3 ] . V_76 ;
struct V_77 * V_78 = V_58 -> V_10 ;
if ( V_46 -> V_31 [ V_3 ] . V_79 -> V_80 )
continue;
if ( V_78 -> V_81 -> V_82 && V_58 -> V_83 )
V_78 -> V_81 -> V_82 ( V_58 , 1 ) ;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_75 ; V_3 ++ ) {
if ( V_46 -> V_31 [ V_3 ] . V_79 -> V_80 )
continue;
F_54 ( V_46 -> V_31 [ V_3 ] . V_84 ) ;
}
if ( V_46 -> V_85 )
V_46 -> V_85 ( V_46 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_75 ; V_3 ++ ) {
struct V_57 * V_86 = V_46 -> V_31 [ V_3 ] . V_86 ;
struct V_54 * V_55 = V_46 -> V_31 [ V_3 ] . V_55 ;
if ( V_46 -> V_31 [ V_3 ] . V_79 -> V_80 )
continue;
if ( V_86 -> V_10 -> V_87 && ! V_86 -> V_10 -> V_88 )
V_86 -> V_10 -> V_87 ( V_86 ) ;
if ( V_55 -> V_10 -> V_87 && ! V_55 -> V_89 ) {
V_55 -> V_10 -> V_87 ( V_86 ) ;
V_55 -> V_89 = 1 ;
}
}
for ( V_3 = 0 ; V_3 < V_46 -> V_75 ; V_3 ++ ) {
F_55 ( & V_46 -> V_31 [ V_3 ] . V_90 ) ;
V_46 -> V_31 [ V_3 ] . V_5 -> V_53 . V_91 = V_46 -> V_31 [ V_3 ] . V_5 -> V_53 . V_92 ;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_75 ; V_3 ++ ) {
struct V_57 * V_76 = V_46 -> V_31 [ V_3 ] . V_76 ;
if ( V_46 -> V_31 [ V_3 ] . V_79 -> V_80 )
continue;
F_56 ( & V_46 -> V_31 [ V_3 ] ,
V_93 ,
V_76 ,
V_94 ) ;
F_56 ( & V_46 -> V_31 [ V_3 ] ,
V_95 ,
V_76 ,
V_94 ) ;
}
F_34 (codec, &card->codec_dev_list, card_list) {
if ( ! V_5 -> V_89 && V_5 -> V_10 -> V_87 ) {
switch ( V_5 -> V_53 . V_92 ) {
case V_96 :
if ( V_5 -> V_53 . V_97 ) {
F_57 ( V_5 -> V_27 ,
L_16 ) ;
break;
}
case V_98 :
V_5 -> V_10 -> V_87 ( V_5 ) ;
V_5 -> V_89 = 1 ;
V_5 -> V_49 = 1 ;
break;
default:
F_57 ( V_5 -> V_27 , L_17 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_46 -> V_75 ; V_3 ++ ) {
struct V_57 * V_86 = V_46 -> V_31 [ V_3 ] . V_86 ;
if ( V_46 -> V_31 [ V_3 ] . V_79 -> V_80 )
continue;
if ( V_86 -> V_10 -> V_87 && V_86 -> V_10 -> V_88 )
V_86 -> V_10 -> V_87 ( V_86 ) ;
}
if ( V_46 -> V_99 )
V_46 -> V_99 ( V_46 ) ;
return 0 ;
}
static void F_58 ( struct V_100 * V_101 )
{
struct V_59 * V_46 =
F_59 ( V_101 , struct V_59 , V_102 ) ;
struct V_4 * V_5 ;
int V_3 ;
F_57 ( V_46 -> V_27 , L_18 ) ;
F_53 ( V_46 -> V_69 , V_103 ) ;
if ( V_46 -> V_104 )
V_46 -> V_104 ( V_46 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_75 ; V_3 ++ ) {
struct V_57 * V_86 = V_46 -> V_31 [ V_3 ] . V_86 ;
if ( V_46 -> V_31 [ V_3 ] . V_79 -> V_80 )
continue;
if ( V_86 -> V_10 -> V_105 && V_86 -> V_10 -> V_88 )
V_86 -> V_10 -> V_105 ( V_86 ) ;
}
F_34 (codec, &card->codec_dev_list, card_list) {
if ( V_5 -> V_10 -> V_105 && V_5 -> V_89 ) {
switch ( V_5 -> V_53 . V_92 ) {
case V_96 :
case V_98 :
V_5 -> V_10 -> V_105 ( V_5 ) ;
V_5 -> V_89 = 0 ;
break;
default:
F_57 ( V_5 -> V_27 , L_19 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_46 -> V_75 ; V_3 ++ ) {
struct V_57 * V_76 = V_46 -> V_31 [ V_3 ] . V_76 ;
if ( V_46 -> V_31 [ V_3 ] . V_79 -> V_80 )
continue;
F_56 ( & V_46 -> V_31 [ V_3 ] ,
V_93 , V_76 ,
V_106 ) ;
F_56 ( & V_46 -> V_31 [ V_3 ] ,
V_95 , V_76 ,
V_106 ) ;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_75 ; V_3 ++ ) {
struct V_57 * V_58 = V_46 -> V_31 [ V_3 ] . V_76 ;
struct V_77 * V_78 = V_58 -> V_10 ;
if ( V_46 -> V_31 [ V_3 ] . V_79 -> V_80 )
continue;
if ( V_78 -> V_81 -> V_82 && V_58 -> V_83 )
V_78 -> V_81 -> V_82 ( V_58 , 0 ) ;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_75 ; V_3 ++ ) {
struct V_57 * V_86 = V_46 -> V_31 [ V_3 ] . V_86 ;
struct V_54 * V_55 = V_46 -> V_31 [ V_3 ] . V_55 ;
if ( V_46 -> V_31 [ V_3 ] . V_79 -> V_80 )
continue;
if ( V_86 -> V_10 -> V_105 && ! V_86 -> V_10 -> V_88 )
V_86 -> V_10 -> V_105 ( V_86 ) ;
if ( V_55 -> V_10 -> V_105 && V_55 -> V_89 ) {
V_55 -> V_10 -> V_105 ( V_86 ) ;
V_55 -> V_89 = 0 ;
}
}
if ( V_46 -> V_107 )
V_46 -> V_107 ( V_46 ) ;
F_57 ( V_46 -> V_27 , L_20 ) ;
F_53 ( V_46 -> V_69 , V_73 ) ;
}
int F_60 ( struct V_26 * V_27 )
{
struct V_59 * V_46 = F_9 ( V_27 ) ;
int V_3 , V_88 = 0 ;
if ( F_49 ( & V_46 -> V_72 ) )
return 0 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_75 ; V_3 ++ ) {
struct V_57 * V_86 = V_46 -> V_31 [ V_3 ] . V_86 ;
V_88 |= V_86 -> V_10 -> V_88 ;
}
if ( V_88 ) {
F_57 ( V_27 , L_21 ) ;
F_58 ( & V_46 -> V_102 ) ;
} else {
F_57 ( V_27 , L_22 ) ;
if ( ! F_61 ( & V_46 -> V_102 ) )
F_62 ( V_27 , L_23 ) ;
}
return 0 ;
}
static int F_63 ( struct V_59 * V_46 , int V_108 )
{
struct V_109 * V_79 = & V_46 -> V_79 [ V_108 ] ;
struct V_30 * V_31 = & V_46 -> V_31 [ V_108 ] ;
struct V_4 * V_5 ;
struct V_54 * V_55 ;
struct V_57 * V_76 , * V_86 ;
const char * V_110 ;
if ( V_31 -> V_111 )
return 1 ;
F_57 ( V_46 -> V_27 , L_24 , V_79 -> V_48 , V_108 ) ;
if ( V_31 -> V_86 ) {
goto V_112;
}
F_34 (cpu_dai, &dai_list, list) {
if ( V_79 -> V_113 ) {
if ( V_86 -> V_27 -> V_114 != V_79 -> V_113 )
continue;
} else {
if ( strcmp ( V_86 -> V_48 , V_79 -> V_115 ) )
continue;
}
V_31 -> V_86 = V_86 ;
goto V_112;
}
F_57 ( V_46 -> V_27 , L_25 ,
V_79 -> V_115 ) ;
V_112:
if ( V_31 -> V_5 ) {
goto V_116;
}
F_34 (codec, &codec_list, list) {
if ( V_79 -> V_117 ) {
if ( V_5 -> V_27 -> V_114 != V_79 -> V_117 )
continue;
} else {
if ( strcmp ( V_5 -> V_48 , V_79 -> V_118 ) )
continue;
}
V_31 -> V_5 = V_5 ;
F_34 (codec_dai, &dai_list, list) {
if ( V_5 -> V_27 == V_76 -> V_27 &&
! strcmp ( V_76 -> V_48 ,
V_79 -> V_119 ) ) {
V_31 -> V_76 = V_76 ;
goto V_116;
}
}
F_57 ( V_46 -> V_27 , L_26 ,
V_79 -> V_119 ) ;
goto V_116;
}
F_57 ( V_46 -> V_27 , L_27 ,
V_79 -> V_118 ) ;
V_116:
if ( V_31 -> V_55 )
goto V_120;
V_110 = V_79 -> V_110 ;
if ( ! V_110 && ! V_79 -> V_121 )
V_110 = L_28 ;
F_34 (platform, &platform_list, list) {
if ( V_79 -> V_121 ) {
if ( V_55 -> V_27 -> V_114 !=
V_79 -> V_121 )
continue;
} else {
if ( strcmp ( V_55 -> V_48 , V_110 ) )
continue;
}
V_31 -> V_55 = V_55 ;
goto V_120;
}
F_57 ( V_46 -> V_27 , L_29 ,
V_79 -> V_110 ) ;
return 0 ;
V_120:
if ( V_31 -> V_5 && V_31 -> V_76 && V_31 -> V_55 && V_31 -> V_86 ) {
V_31 -> V_111 = 1 ;
V_46 -> V_75 ++ ;
}
return 1 ;
}
static void F_64 ( struct V_4 * V_5 )
{
int V_65 ;
if ( V_5 -> V_10 -> remove ) {
V_65 = V_5 -> V_10 -> remove ( V_5 ) ;
if ( V_65 < 0 )
F_62 ( V_5 -> V_27 ,
L_30 ,
V_5 -> V_48 , V_65 ) ;
}
F_65 ( & V_5 -> V_53 ) ;
F_29 ( V_5 ) ;
V_5 -> V_122 = 0 ;
F_66 ( & V_5 -> V_123 ) ;
F_67 ( V_5 -> V_27 -> V_10 -> V_124 ) ;
}
static void F_68 ( struct V_59 * V_46 , int V_108 , int V_125 )
{
struct V_30 * V_31 = & V_46 -> V_31 [ V_108 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
struct V_54 * V_55 = V_31 -> V_55 ;
struct V_57 * V_76 = V_31 -> V_76 , * V_86 = V_31 -> V_86 ;
int V_65 ;
if ( V_31 -> V_126 ) {
F_69 ( V_31 -> V_27 , & V_127 ) ;
F_69 ( V_31 -> V_27 , & V_128 ) ;
F_42 ( V_31 -> V_27 ) ;
V_31 -> V_126 = 0 ;
}
if ( V_76 && V_76 -> V_122 &&
V_76 -> V_10 -> V_129 == V_125 ) {
if ( V_76 -> V_10 -> remove ) {
V_65 = V_76 -> V_10 -> remove ( V_76 ) ;
if ( V_65 < 0 )
F_70 ( L_30 ,
V_76 -> V_48 , V_65 ) ;
}
V_76 -> V_122 = 0 ;
F_66 ( & V_76 -> V_123 ) ;
}
if ( V_55 && V_55 -> V_122 &&
V_55 -> V_10 -> V_129 == V_125 ) {
if ( V_55 -> V_10 -> remove ) {
V_65 = V_55 -> V_10 -> remove ( V_55 ) ;
if ( V_65 < 0 )
F_70 ( L_30 ,
V_55 -> V_48 , V_65 ) ;
}
F_65 ( & V_55 -> V_53 ) ;
F_32 ( V_55 ) ;
V_55 -> V_122 = 0 ;
F_66 ( & V_55 -> V_123 ) ;
F_67 ( V_55 -> V_27 -> V_10 -> V_124 ) ;
}
if ( V_5 && V_5 -> V_122 &&
V_5 -> V_10 -> V_129 == V_125 )
F_64 ( V_5 ) ;
if ( V_86 && V_86 -> V_122 &&
V_86 -> V_10 -> V_129 == V_125 ) {
if ( V_86 -> V_10 -> remove ) {
V_65 = V_86 -> V_10 -> remove ( V_86 ) ;
if ( V_65 < 0 )
F_70 ( L_30 ,
V_86 -> V_48 , V_65 ) ;
}
V_86 -> V_122 = 0 ;
F_66 ( & V_86 -> V_123 ) ;
F_67 ( V_86 -> V_27 -> V_10 -> V_124 ) ;
}
}
static void F_71 ( struct V_59 * V_46 )
{
int V_58 , V_125 ;
for ( V_125 = V_130 ; V_125 <= V_131 ;
V_125 ++ ) {
for ( V_58 = 0 ; V_58 < V_46 -> V_75 ; V_58 ++ )
F_68 ( V_46 , V_58 , V_125 ) ;
}
V_46 -> V_75 = 0 ;
}
static void F_72 ( struct V_59 * V_46 ,
struct V_4 * V_5 )
{
int V_3 ;
if ( V_46 -> V_132 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_46 -> V_133 ; V_3 ++ ) {
struct V_134 * V_135 = & V_46 -> V_132 [ V_3 ] ;
if ( V_135 -> V_136 && ! strcmp ( V_5 -> V_48 , V_135 -> V_136 ) ) {
V_5 -> V_137 = V_135 -> V_137 ;
break;
}
}
}
static int F_73 ( struct V_59 * V_46 ,
struct V_4 * V_5 )
{
int V_14 = 0 ;
const struct V_138 * V_10 = V_5 -> V_10 ;
struct V_57 * V_58 ;
V_5 -> V_46 = V_46 ;
V_5 -> V_53 . V_46 = V_46 ;
F_72 ( V_46 , V_5 ) ;
if ( ! F_74 ( V_5 -> V_27 -> V_10 -> V_124 ) )
return - V_139 ;
F_23 ( V_5 ) ;
if ( V_10 -> V_140 )
F_75 ( & V_5 -> V_53 , V_10 -> V_140 ,
V_10 -> V_141 ) ;
F_34 (dai, &dai_list, list) {
if ( V_58 -> V_27 != V_5 -> V_27 )
continue;
F_76 ( & V_5 -> V_53 , V_58 ) ;
}
V_5 -> V_53 . V_97 = V_10 -> V_97 ;
if ( V_10 -> V_142 ) {
V_14 = V_10 -> V_142 ( V_5 ) ;
if ( V_14 < 0 ) {
F_62 ( V_5 -> V_27 ,
L_31 ,
V_5 -> V_48 , V_14 ) ;
goto V_143;
}
}
if ( V_10 -> V_144 )
F_77 ( V_5 , V_10 -> V_144 ,
V_10 -> V_145 ) ;
if ( V_10 -> V_146 )
F_78 ( & V_5 -> V_53 , V_10 -> V_146 ,
V_10 -> V_147 ) ;
V_5 -> V_122 = 1 ;
F_79 ( & V_5 -> V_123 , & V_46 -> V_72 ) ;
F_79 ( & V_5 -> V_53 . V_148 , & V_46 -> V_149 ) ;
return 0 ;
V_143:
F_29 ( V_5 ) ;
F_67 ( V_5 -> V_27 -> V_10 -> V_124 ) ;
return V_14 ;
}
static int F_80 ( struct V_59 * V_46 ,
struct V_54 * V_55 )
{
int V_14 = 0 ;
const struct V_150 * V_10 = V_55 -> V_10 ;
V_55 -> V_46 = V_46 ;
V_55 -> V_53 . V_46 = V_46 ;
if ( ! F_74 ( V_55 -> V_27 -> V_10 -> V_124 ) )
return - V_139 ;
F_31 ( V_55 ) ;
if ( V_10 -> V_140 )
F_75 ( & V_55 -> V_53 ,
V_10 -> V_140 , V_10 -> V_141 ) ;
V_55 -> V_53 . V_97 = 1 ;
if ( V_10 -> V_142 ) {
V_14 = V_10 -> V_142 ( V_55 ) ;
if ( V_14 < 0 ) {
F_62 ( V_55 -> V_27 ,
L_32 ,
V_55 -> V_48 , V_14 ) ;
goto V_143;
}
}
if ( V_10 -> V_144 )
F_81 ( V_55 , V_10 -> V_144 ,
V_10 -> V_145 ) ;
if ( V_10 -> V_146 )
F_78 ( & V_55 -> V_53 , V_10 -> V_146 ,
V_10 -> V_147 ) ;
V_55 -> V_122 = 1 ;
F_79 ( & V_55 -> V_123 , & V_46 -> V_151 ) ;
F_79 ( & V_55 -> V_53 . V_148 , & V_46 -> V_149 ) ;
return 0 ;
V_143:
F_32 ( V_55 ) ;
F_67 ( V_55 -> V_27 -> V_10 -> V_124 ) ;
return V_14 ;
}
static void F_82 ( struct V_26 * V_27 )
{
F_16 ( V_27 ) ;
}
static int F_83 ( struct V_59 * V_46 ,
struct V_4 * V_5 ,
int V_108 , int V_152 )
{
struct V_109 * V_79 = NULL ;
struct V_153 * V_154 = NULL ;
struct V_30 * V_31 ;
const char * V_155 , * V_48 ;
int V_14 = 0 ;
if ( ! V_152 ) {
V_79 = & V_46 -> V_79 [ V_108 ] ;
V_31 = & V_46 -> V_31 [ V_108 ] ;
V_48 = V_79 -> V_48 ;
} else {
V_154 = & V_46 -> V_154 [ V_108 ] ;
V_31 = & V_46 -> V_156 [ V_108 ] ;
V_48 = V_154 -> V_48 ;
}
V_31 -> V_46 = V_46 ;
F_84 ( & V_5 -> V_53 ) ;
V_155 = V_5 -> V_137 ;
V_5 -> V_137 = NULL ;
if ( ! V_152 && V_79 -> V_157 )
V_14 = V_79 -> V_157 ( V_31 ) ;
else if ( V_152 && V_154 -> V_157 )
V_14 = V_154 -> V_157 ( & V_5 -> V_53 ) ;
if ( V_14 < 0 ) {
F_62 ( V_46 -> V_27 , L_33 , V_48 , V_14 ) ;
return V_14 ;
}
V_5 -> V_137 = V_155 ;
V_31 -> V_5 = V_5 ;
V_31 -> V_27 = F_85 ( sizeof( struct V_26 ) , V_37 ) ;
if ( ! V_31 -> V_27 )
return - V_38 ;
F_86 ( V_31 -> V_27 ) ;
V_31 -> V_27 -> V_67 = V_46 -> V_27 ;
V_31 -> V_27 -> V_68 = F_82 ;
V_31 -> V_27 -> V_158 = V_48 ;
F_87 ( V_31 -> V_27 , V_31 ) ;
F_88 ( & V_31 -> V_159 ) ;
V_14 = F_89 ( V_31 -> V_27 ) ;
if ( V_14 < 0 ) {
F_62 ( V_46 -> V_27 ,
L_34 , V_14 ) ;
return V_14 ;
}
V_31 -> V_126 = 1 ;
V_14 = F_90 ( V_31 -> V_27 ) ;
if ( V_14 < 0 )
F_62 ( V_5 -> V_27 ,
L_35 ,
V_14 ) ;
V_14 = F_91 ( V_31 -> V_27 , & V_128 ) ;
if ( V_14 < 0 )
F_62 ( V_5 -> V_27 ,
L_36 , V_14 ) ;
return 0 ;
}
static int F_92 ( struct V_59 * V_46 , int V_108 , int V_125 )
{
struct V_109 * V_79 = & V_46 -> V_79 [ V_108 ] ;
struct V_30 * V_31 = & V_46 -> V_31 [ V_108 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
struct V_54 * V_55 = V_31 -> V_55 ;
struct V_57 * V_76 = V_31 -> V_76 , * V_86 = V_31 -> V_86 ;
int V_14 ;
F_57 ( V_46 -> V_27 , L_37 ,
V_46 -> V_48 , V_108 , V_125 ) ;
V_76 -> V_5 = V_5 ;
V_86 -> V_55 = V_55 ;
V_76 -> V_46 = V_46 ;
V_86 -> V_46 = V_46 ;
V_31 -> V_32 = V_32 ;
if ( ! V_86 -> V_122 &&
V_86 -> V_10 -> V_160 == V_125 ) {
if ( ! F_74 ( V_86 -> V_27 -> V_10 -> V_124 ) )
return - V_139 ;
if ( V_86 -> V_10 -> V_142 ) {
V_14 = V_86 -> V_10 -> V_142 ( V_86 ) ;
if ( V_14 < 0 ) {
F_70 ( L_38 ,
V_86 -> V_48 , V_14 ) ;
F_67 ( V_86 -> V_27 -> V_10 -> V_124 ) ;
return V_14 ;
}
}
V_86 -> V_122 = 1 ;
F_79 ( & V_86 -> V_123 , & V_46 -> V_161 ) ;
}
if ( ! V_5 -> V_122 &&
V_5 -> V_10 -> V_160 == V_125 ) {
V_14 = F_73 ( V_46 , V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_55 -> V_122 &&
V_55 -> V_10 -> V_160 == V_125 ) {
V_14 = F_80 ( V_46 , V_55 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_76 -> V_122 && V_76 -> V_10 -> V_160 == V_125 ) {
if ( V_76 -> V_10 -> V_142 ) {
V_14 = V_76 -> V_10 -> V_142 ( V_76 ) ;
if ( V_14 < 0 ) {
F_70 ( L_39 ,
V_76 -> V_48 , V_14 ) ;
return V_14 ;
}
}
V_76 -> V_122 = 1 ;
F_79 ( & V_76 -> V_123 , & V_46 -> V_161 ) ;
}
if ( V_125 != V_131 )
return 0 ;
V_14 = F_83 ( V_46 , V_5 , V_108 , 0 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_91 ( V_31 -> V_27 , & V_127 ) ;
if ( V_14 < 0 )
F_93 ( L_40 , V_14 ) ;
V_14 = F_94 ( V_31 , V_108 ) ;
if ( V_14 < 0 ) {
F_70 ( L_41 ,
V_79 -> V_162 , V_14 ) ;
return V_14 ;
}
if ( V_31 -> V_76 -> V_10 -> V_88 )
F_95 ( V_5 -> V_63 , V_31 -> V_86 -> V_163 ) ;
return 0 ;
}
static int F_96 ( struct V_30 * V_31 )
{
int V_14 ;
if ( V_31 -> V_76 -> V_10 -> V_88 && ! V_31 -> V_5 -> V_164 ) {
if ( ! V_31 -> V_5 -> V_165 )
return 0 ;
V_14 = F_44 ( V_31 -> V_5 ) ;
if ( V_14 < 0 ) {
F_70 ( L_42 , V_14 ) ;
return V_14 ;
}
V_31 -> V_5 -> V_164 = 1 ;
}
return 0 ;
}
static void F_97 ( struct V_4 * V_5 )
{
if ( V_5 -> V_164 ) {
F_41 ( V_5 ) ;
V_5 -> V_164 = 0 ;
}
}
static int F_98 ( struct V_59 * V_46 , int V_108 )
{
struct V_153 * V_154 = & V_46 -> V_154 [ V_108 ] ;
struct V_4 * V_5 ;
int V_14 = - V_139 ;
F_34 (codec, &codec_list, list) {
if ( ! strcmp ( V_5 -> V_48 , V_154 -> V_118 ) ) {
if ( V_5 -> V_122 ) {
F_62 ( V_5 -> V_27 ,
L_43 ) ;
V_14 = - V_166 ;
goto V_120;
}
goto V_167;
}
}
F_62 ( V_46 -> V_27 , L_44 , V_154 -> V_118 ) ;
goto V_120;
V_167:
V_14 = F_73 ( V_46 , V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_83 ( V_46 , V_5 , V_108 , 1 ) ;
V_120:
return V_14 ;
}
static void F_99 ( struct V_59 * V_46 , int V_108 )
{
struct V_30 * V_31 = & V_46 -> V_156 [ V_108 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
if ( V_31 -> V_126 ) {
F_69 ( V_31 -> V_27 , & V_128 ) ;
F_100 ( V_31 -> V_27 ) ;
V_31 -> V_126 = 0 ;
}
if ( V_5 && V_5 -> V_122 )
F_64 ( V_5 ) ;
}
static int F_101 ( struct V_4 * V_5 ,
enum V_168 V_169 )
{
int V_14 ;
if ( V_5 -> V_170 )
return 0 ;
if ( V_169 && V_5 -> V_169 != V_169 )
V_5 -> V_169 = V_169 ;
V_14 = F_102 ( V_5 ) ;
if ( V_14 < 0 ) {
F_62 ( V_5 -> V_27 , L_45 ,
V_14 ) ;
return V_14 ;
}
V_5 -> V_170 = 1 ;
return 0 ;
}
static void F_103 ( struct V_59 * V_46 )
{
struct V_4 * V_5 ;
struct V_134 * V_132 ;
enum V_168 V_169 ;
struct V_109 * V_79 ;
int V_14 , V_3 , V_125 ;
F_104 ( & V_46 -> V_171 ) ;
if ( V_46 -> V_172 ) {
F_105 ( & V_46 -> V_171 ) ;
return;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_173 ; V_3 ++ )
F_63 ( V_46 , V_3 ) ;
if ( V_46 -> V_75 != V_46 -> V_173 ) {
F_105 ( & V_46 -> V_171 ) ;
return;
}
F_34 (codec, &codec_list, list) {
if ( V_5 -> V_170 )
continue;
V_169 = 0 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_133 ; ++ V_3 ) {
V_132 = & V_46 -> V_132 [ V_3 ] ;
if ( ! strcmp ( V_5 -> V_48 , V_132 -> V_136 ) ) {
V_169 = V_132 -> V_169 ;
if ( V_169 && V_169
!= V_5 -> V_169 )
break;
}
}
V_14 = F_101 ( V_5 , V_169 ) ;
if ( V_14 < 0 ) {
F_105 ( & V_46 -> V_171 ) ;
return;
}
}
V_14 = F_106 ( V_174 , V_175 ,
V_46 -> V_124 , 0 , & V_46 -> V_69 ) ;
if ( V_14 < 0 ) {
F_70 ( L_46 ,
V_46 -> V_48 , V_14 ) ;
F_105 ( & V_46 -> V_171 ) ;
return;
}
V_46 -> V_69 -> V_27 = V_46 -> V_27 ;
V_46 -> V_53 . V_92 = V_98 ;
V_46 -> V_53 . V_27 = V_46 -> V_27 ;
V_46 -> V_53 . V_46 = V_46 ;
F_79 ( & V_46 -> V_53 . V_148 , & V_46 -> V_149 ) ;
#ifdef F_107
F_28 ( & V_46 -> V_53 , V_46 -> V_45 ) ;
#endif
#ifdef F_108
F_109 ( & V_46 -> V_102 , F_58 ) ;
#endif
if ( V_46 -> V_140 )
F_75 ( & V_46 -> V_53 , V_46 -> V_140 ,
V_46 -> V_141 ) ;
if ( V_46 -> V_142 ) {
V_14 = V_46 -> V_142 ( V_46 ) ;
if ( V_14 < 0 )
goto V_176;
}
for ( V_125 = V_130 ; V_125 <= V_131 ;
V_125 ++ ) {
for ( V_3 = 0 ; V_3 < V_46 -> V_173 ; V_3 ++ ) {
V_14 = F_92 ( V_46 , V_3 , V_125 ) ;
if ( V_14 < 0 ) {
F_70 ( L_47 ,
V_46 -> V_48 , V_14 ) ;
goto V_177;
}
}
}
for ( V_3 = 0 ; V_3 < V_46 -> V_178 ; V_3 ++ ) {
V_14 = F_98 ( V_46 , V_3 ) ;
if ( V_14 < 0 ) {
F_70 ( L_48 ,
V_46 -> V_48 , V_14 ) ;
goto V_179;
}
}
F_110 ( V_46 ) ;
if ( V_46 -> V_144 )
F_111 ( V_46 , V_46 -> V_144 , V_46 -> V_145 ) ;
if ( V_46 -> V_146 )
F_78 ( & V_46 -> V_53 , V_46 -> V_146 ,
V_46 -> V_147 ) ;
F_84 ( & V_46 -> V_53 ) ;
for ( V_3 = 0 ; V_3 < V_46 -> V_173 ; V_3 ++ ) {
V_79 = & V_46 -> V_79 [ V_3 ] ;
if ( V_79 -> V_180 ) {
V_14 = F_112 ( V_46 -> V_31 [ V_3 ] . V_76 ,
V_79 -> V_180 ) ;
if ( V_14 != 0 && V_14 != - V_181 )
F_25 ( V_46 -> V_31 [ V_3 ] . V_76 -> V_27 ,
L_49 ,
V_14 ) ;
V_14 = F_112 ( V_46 -> V_31 [ V_3 ] . V_86 ,
V_79 -> V_180 ) ;
if ( V_14 != 0 && V_14 != - V_181 )
F_25 ( V_46 -> V_31 [ V_3 ] . V_86 -> V_27 ,
L_49 ,
V_14 ) ;
}
}
snprintf ( V_46 -> V_69 -> V_182 , sizeof( V_46 -> V_69 -> V_182 ) ,
L_50 , V_46 -> V_48 ) ;
snprintf ( V_46 -> V_69 -> V_183 , sizeof( V_46 -> V_69 -> V_183 ) ,
L_50 , V_46 -> V_184 ? V_46 -> V_184 : V_46 -> V_48 ) ;
snprintf ( V_46 -> V_69 -> V_10 , sizeof( V_46 -> V_69 -> V_10 ) ,
L_50 , V_46 -> V_185 ? V_46 -> V_185 : V_46 -> V_48 ) ;
for ( V_3 = 0 ; V_3 < F_113 ( V_46 -> V_69 -> V_10 ) ; V_3 ++ ) {
switch ( V_46 -> V_69 -> V_10 [ V_3 ] ) {
case '_' :
case '-' :
case '\0' :
break;
default:
if ( ! isalnum ( V_46 -> V_69 -> V_10 [ V_3 ] ) )
V_46 -> V_69 -> V_10 [ V_3 ] = '_' ;
break;
}
}
if ( V_46 -> V_186 ) {
V_14 = V_46 -> V_186 ( V_46 ) ;
if ( V_14 < 0 ) {
F_62 ( V_46 -> V_27 , L_51 ,
V_46 -> V_48 , V_14 ) ;
goto V_179;
}
}
F_84 ( & V_46 -> V_53 ) ;
if ( V_46 -> V_187 )
F_34 (codec, &card->codec_dev_list, card_list)
F_114 ( V_5 ) ;
V_14 = F_115 ( V_46 -> V_69 ) ;
if ( V_14 < 0 ) {
F_70 ( L_52 ,
V_46 -> V_48 , V_14 ) ;
goto V_179;
}
#ifdef F_116
for ( V_3 = 0 ; V_3 < V_46 -> V_75 ; V_3 ++ ) {
V_14 = F_96 ( & V_46 -> V_31 [ V_3 ] ) ;
if ( V_14 < 0 ) {
F_70 ( L_53 ,
V_46 -> V_48 , V_14 ) ;
while ( -- V_3 >= 0 )
F_97 ( V_46 -> V_31 [ V_3 ] . V_5 ) ;
goto V_179;
}
}
#endif
V_46 -> V_172 = 1 ;
F_117 ( & V_46 -> V_53 ) ;
F_105 ( & V_46 -> V_171 ) ;
return;
V_179:
for ( V_3 = 0 ; V_3 < V_46 -> V_178 ; V_3 ++ )
F_99 ( V_46 , V_3 ) ;
V_177:
F_71 ( V_46 ) ;
V_176:
if ( V_46 -> remove )
V_46 -> remove ( V_46 ) ;
F_118 ( V_46 -> V_69 ) ;
F_105 ( & V_46 -> V_171 ) ;
}
static void F_119 ( void )
{
struct V_59 * V_46 ;
F_34 (card, &card_list, list)
F_103 ( V_46 ) ;
}
static int F_120 ( struct V_188 * V_189 )
{
struct V_59 * V_46 = F_121 ( V_189 ) ;
int V_14 = 0 ;
if ( ! V_46 )
return - V_17 ;
F_25 ( & V_189 -> V_27 ,
L_54 ,
V_46 -> V_48 ) ;
V_46 -> V_27 = & V_189 -> V_27 ;
V_14 = F_122 ( V_46 ) ;
if ( V_14 != 0 ) {
F_62 ( & V_189 -> V_27 , L_55 ) ;
return V_14 ;
}
return 0 ;
}
static int F_123 ( struct V_59 * V_46 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_75 ; V_3 ++ ) {
struct V_30 * V_31 = & V_46 -> V_31 [ V_3 ] ;
F_55 ( & V_31 -> V_90 ) ;
}
for ( V_3 = 0 ; V_3 < V_46 -> V_178 ; V_3 ++ )
F_99 ( V_46 , V_3 ) ;
F_71 ( V_46 ) ;
F_40 ( V_46 ) ;
if ( V_46 -> remove )
V_46 -> remove ( V_46 ) ;
F_65 ( & V_46 -> V_53 ) ;
F_118 ( V_46 -> V_69 ) ;
return 0 ;
}
static int F_124 ( struct V_188 * V_189 )
{
struct V_59 * V_46 = F_121 ( V_189 ) ;
F_125 ( V_46 ) ;
return 0 ;
}
int F_126 ( struct V_26 * V_27 )
{
struct V_59 * V_46 = F_9 ( V_27 ) ;
int V_3 ;
if ( ! V_46 -> V_172 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_75 ; V_3 ++ ) {
struct V_30 * V_31 = & V_46 -> V_31 [ V_3 ] ;
F_55 ( & V_31 -> V_90 ) ;
}
F_127 ( V_46 ) ;
return 0 ;
}
int F_128 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_190 )
return V_5 -> V_190 ( V_5 , V_6 ) ;
else
return 0 ;
}
int F_6 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_191 )
return V_5 -> V_191 ( V_5 , V_6 ) ;
else
return 1 ;
}
int F_129 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_192 )
return V_5 -> V_192 ( V_5 , V_6 ) ;
else
return 1 ;
}
int F_130 ( struct V_54 * V_55 ,
unsigned int V_6 )
{
unsigned int V_14 ;
if ( ! V_55 -> V_10 -> V_193 ) {
F_62 ( V_55 -> V_27 , L_56 ) ;
return - 1 ;
}
V_14 = V_55 -> V_10 -> V_193 ( V_55 , V_6 ) ;
F_57 ( V_55 -> V_27 , L_57 , V_6 , V_14 ) ;
F_131 ( V_55 , V_6 , V_14 ) ;
return V_14 ;
}
int F_132 ( struct V_54 * V_55 ,
unsigned int V_6 , unsigned int V_1 )
{
if ( ! V_55 -> V_10 -> V_194 ) {
F_62 ( V_55 -> V_27 , L_58 ) ;
return - 1 ;
}
F_57 ( V_55 -> V_27 , L_59 , V_6 , V_1 ) ;
F_133 ( V_55 , V_6 , V_1 ) ;
return V_55 -> V_10 -> V_194 ( V_55 , V_6 , V_1 ) ;
}
int F_134 ( struct V_4 * V_5 ,
struct V_195 * V_81 , int V_108 )
{
F_104 ( & V_5 -> V_171 ) ;
V_5 -> V_63 = F_85 ( sizeof( struct V_196 ) , V_37 ) ;
if ( V_5 -> V_63 == NULL ) {
F_105 ( & V_5 -> V_171 ) ;
return - V_38 ;
}
V_5 -> V_63 -> V_64 = F_85 ( sizeof( struct V_197 ) , V_37 ) ;
if ( V_5 -> V_63 -> V_64 == NULL ) {
F_16 ( V_5 -> V_63 ) ;
V_5 -> V_63 = NULL ;
F_105 ( & V_5 -> V_171 ) ;
return - V_38 ;
}
V_5 -> V_63 -> V_64 -> V_81 = V_81 ;
V_5 -> V_63 -> V_108 = V_108 ;
V_5 -> V_165 = 1 ;
F_105 ( & V_5 -> V_171 ) ;
return 0 ;
}
void F_135 ( struct V_4 * V_5 )
{
F_104 ( & V_5 -> V_171 ) ;
#ifdef F_116
F_97 ( V_5 ) ;
#endif
F_16 ( V_5 -> V_63 -> V_64 ) ;
F_16 ( V_5 -> V_63 ) ;
V_5 -> V_63 = NULL ;
V_5 -> V_165 = 0 ;
F_105 ( & V_5 -> V_171 ) ;
}
unsigned int F_4 ( struct V_4 * V_5 , unsigned int V_6 )
{
unsigned int V_14 ;
V_14 = V_5 -> V_193 ( V_5 , V_6 ) ;
F_57 ( V_5 -> V_27 , L_57 , V_6 , V_14 ) ;
F_136 ( V_5 , V_6 , V_14 ) ;
return V_14 ;
}
unsigned int F_22 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned int V_1 )
{
F_57 ( V_5 -> V_27 , L_59 , V_6 , V_1 ) ;
F_137 ( V_5 , V_6 , V_1 ) ;
return V_5 -> V_194 ( V_5 , V_6 , V_1 ) ;
}
unsigned int F_138 ( struct V_4 * V_5 ,
unsigned int V_6 , const void * V_198 , T_1 V_8 )
{
return V_5 -> V_199 ( V_5 , V_6 , V_198 , V_8 ) ;
}
int F_139 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_200 , unsigned int V_42 )
{
bool V_201 ;
unsigned int V_202 , V_203 ;
int V_14 ;
if ( V_5 -> V_204 ) {
V_14 = F_140 ( V_5 -> V_205 , V_6 ,
V_200 , V_42 , & V_201 ) ;
} else {
V_14 = F_4 ( V_5 , V_6 ) ;
if ( V_14 < 0 )
return V_14 ;
V_202 = V_14 ;
V_203 = ( V_202 & ~ V_200 ) | ( V_42 & V_200 ) ;
V_201 = V_202 != V_203 ;
if ( V_201 )
V_14 = F_22 ( V_5 , V_6 , V_203 ) ;
}
if ( V_14 < 0 )
return V_14 ;
return V_201 ;
}
int F_141 ( struct V_4 * V_5 ,
unsigned short V_6 , unsigned int V_200 ,
unsigned int V_42 )
{
int V_201 ;
F_104 ( & V_5 -> V_171 ) ;
V_201 = F_139 ( V_5 , V_6 , V_200 , V_42 ) ;
F_105 ( & V_5 -> V_171 ) ;
return V_201 ;
}
int F_142 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_200 , unsigned int V_42 )
{
int V_201 ;
unsigned int V_202 , V_203 ;
V_202 = F_4 ( V_5 , V_6 ) ;
V_203 = ( V_202 & ~ V_200 ) | V_42 ;
V_201 = V_202 != V_203 ;
return V_201 ;
}
int F_143 ( struct V_206 * V_207 ,
const struct V_208 * V_209 )
{
struct V_210 * V_211 = V_207 -> V_211 ;
V_211 -> V_209 . V_212 = V_209 -> V_212 ;
V_211 -> V_209 . V_213 = V_209 -> V_213 ;
V_211 -> V_209 . V_214 = V_209 -> V_214 ;
V_211 -> V_209 . V_215 = V_209 -> V_215 ;
V_211 -> V_209 . V_216 = V_209 -> V_216 ;
V_211 -> V_209 . V_217 = V_209 -> V_217 ;
V_211 -> V_209 . V_218 = V_209 -> V_218 ;
V_211 -> V_209 . V_219 = V_209 -> V_219 ;
return 0 ;
}
struct V_220 * F_144 ( const struct V_221 * V_222 ,
void * V_198 , const char * V_184 ,
const char * V_223 )
{
struct V_221 V_224 ;
struct V_220 * V_225 ;
char * V_48 = NULL ;
int V_226 ;
memcpy ( & V_224 , V_222 , sizeof( V_224 ) ) ;
V_224 . V_227 = 0 ;
if ( ! V_184 )
V_184 = V_224 . V_48 ;
if ( V_223 ) {
V_226 = strlen ( V_184 ) + strlen ( V_223 ) + 2 ;
V_48 = F_14 ( V_226 , V_37 ) ;
if ( ! V_48 )
return NULL ;
snprintf ( V_48 , V_226 , L_60 , V_223 , V_184 ) ;
V_224 . V_48 = V_48 ;
} else {
V_224 . V_48 = V_184 ;
}
V_225 = F_145 ( & V_224 , V_198 ) ;
F_16 ( V_48 ) ;
return V_225 ;
}
static int F_146 ( struct V_69 * V_46 , struct V_26 * V_27 ,
const struct V_221 * V_144 , int V_145 ,
const char * V_223 , void * V_198 )
{
int V_65 , V_3 ;
for ( V_3 = 0 ; V_3 < V_145 ; V_3 ++ ) {
const struct V_221 * V_228 = & V_144 [ V_3 ] ;
V_65 = F_147 ( V_46 , F_144 ( V_228 , V_198 ,
V_228 -> V_48 , V_223 ) ) ;
if ( V_65 < 0 ) {
F_62 ( V_27 , L_61 , V_228 -> V_48 , V_65 ) ;
return V_65 ;
}
}
return 0 ;
}
int F_77 ( struct V_4 * V_5 ,
const struct V_221 * V_144 , int V_145 )
{
struct V_69 * V_46 = V_5 -> V_46 -> V_69 ;
return F_146 ( V_46 , V_5 -> V_27 , V_144 , V_145 ,
V_5 -> V_137 , V_5 ) ;
}
int F_81 ( struct V_54 * V_55 ,
const struct V_221 * V_144 , int V_145 )
{
struct V_69 * V_46 = V_55 -> V_46 -> V_69 ;
return F_146 ( V_46 , V_55 -> V_27 , V_144 , V_145 ,
NULL , V_55 ) ;
}
int F_111 ( struct V_59 * V_229 ,
const struct V_221 * V_144 , int V_145 )
{
struct V_69 * V_46 = V_229 -> V_69 ;
return F_146 ( V_46 , V_229 -> V_27 , V_144 , V_145 ,
NULL , V_229 ) ;
}
int F_148 ( struct V_57 * V_58 ,
const struct V_221 * V_144 , int V_145 )
{
struct V_69 * V_46 = V_58 -> V_46 -> V_69 ;
return F_146 ( V_46 , V_58 -> V_27 , V_144 , V_145 ,
NULL , V_58 ) ;
}
int F_149 ( struct V_220 * V_225 ,
struct V_230 * V_231 )
{
struct V_232 * V_233 = (struct V_232 * ) V_225 -> V_234 ;
V_231 -> type = V_235 ;
V_231 -> V_18 = V_233 -> V_236 == V_233 -> V_237 ? 1 : 2 ;
V_231 -> V_42 . V_238 . V_239 = V_233 -> V_240 ;
if ( V_231 -> V_42 . V_238 . V_241 > V_233 -> V_240 - 1 )
V_231 -> V_42 . V_238 . V_241 = V_233 -> V_240 - 1 ;
strcpy ( V_231 -> V_42 . V_238 . V_48 ,
V_233 -> V_242 [ V_231 -> V_42 . V_238 . V_241 ] ) ;
return 0 ;
}
int F_150 ( struct V_220 * V_225 ,
struct V_243 * V_244 )
{
struct V_4 * V_5 = F_151 ( V_225 ) ;
struct V_232 * V_233 = (struct V_232 * ) V_225 -> V_234 ;
unsigned int V_1 , V_245 ;
for ( V_245 = 1 ; V_245 < V_233 -> V_240 ; V_245 <<= 1 )
;
V_1 = F_4 ( V_5 , V_233 -> V_6 ) ;
V_244 -> V_42 . V_238 . V_241 [ 0 ]
= ( V_1 >> V_233 -> V_236 ) & ( V_245 - 1 ) ;
if ( V_233 -> V_236 != V_233 -> V_237 )
V_244 -> V_42 . V_238 . V_241 [ 1 ] =
( V_1 >> V_233 -> V_237 ) & ( V_245 - 1 ) ;
return 0 ;
}
int F_152 ( struct V_220 * V_225 ,
struct V_243 * V_244 )
{
struct V_4 * V_5 = F_151 ( V_225 ) ;
struct V_232 * V_233 = (struct V_232 * ) V_225 -> V_234 ;
unsigned int V_1 ;
unsigned int V_200 , V_245 ;
for ( V_245 = 1 ; V_245 < V_233 -> V_240 ; V_245 <<= 1 )
;
if ( V_244 -> V_42 . V_238 . V_241 [ 0 ] > V_233 -> V_240 - 1 )
return - V_17 ;
V_1 = V_244 -> V_42 . V_238 . V_241 [ 0 ] << V_233 -> V_236 ;
V_200 = ( V_245 - 1 ) << V_233 -> V_236 ;
if ( V_233 -> V_236 != V_233 -> V_237 ) {
if ( V_244 -> V_42 . V_238 . V_241 [ 1 ] > V_233 -> V_240 - 1 )
return - V_17 ;
V_1 |= V_244 -> V_42 . V_238 . V_241 [ 1 ] << V_233 -> V_237 ;
V_200 |= ( V_245 - 1 ) << V_233 -> V_237 ;
}
return F_141 ( V_5 , V_233 -> V_6 , V_200 , V_1 ) ;
}
int F_153 ( struct V_220 * V_225 ,
struct V_243 * V_244 )
{
struct V_4 * V_5 = F_151 ( V_225 ) ;
struct V_232 * V_233 = (struct V_232 * ) V_225 -> V_234 ;
unsigned int V_246 , V_1 , V_247 ;
V_246 = F_4 ( V_5 , V_233 -> V_6 ) ;
V_1 = ( V_246 >> V_233 -> V_236 ) & V_233 -> V_200 ;
for ( V_247 = 0 ; V_247 < V_233 -> V_240 ; V_247 ++ ) {
if ( V_1 == V_233 -> V_248 [ V_247 ] )
break;
}
V_244 -> V_42 . V_238 . V_241 [ 0 ] = V_247 ;
if ( V_233 -> V_236 != V_233 -> V_237 ) {
V_1 = ( V_246 >> V_233 -> V_237 ) & V_233 -> V_200 ;
for ( V_247 = 0 ; V_247 < V_233 -> V_240 ; V_247 ++ ) {
if ( V_1 == V_233 -> V_248 [ V_247 ] )
break;
}
V_244 -> V_42 . V_238 . V_241 [ 1 ] = V_247 ;
}
return 0 ;
}
int F_154 ( struct V_220 * V_225 ,
struct V_243 * V_244 )
{
struct V_4 * V_5 = F_151 ( V_225 ) ;
struct V_232 * V_233 = (struct V_232 * ) V_225 -> V_234 ;
unsigned int V_1 ;
unsigned int V_200 ;
if ( V_244 -> V_42 . V_238 . V_241 [ 0 ] > V_233 -> V_240 - 1 )
return - V_17 ;
V_1 = V_233 -> V_248 [ V_244 -> V_42 . V_238 . V_241 [ 0 ] ] << V_233 -> V_236 ;
V_200 = V_233 -> V_200 << V_233 -> V_236 ;
if ( V_233 -> V_236 != V_233 -> V_237 ) {
if ( V_244 -> V_42 . V_238 . V_241 [ 1 ] > V_233 -> V_240 - 1 )
return - V_17 ;
V_1 |= V_233 -> V_248 [ V_244 -> V_42 . V_238 . V_241 [ 1 ] ] << V_233 -> V_237 ;
V_200 |= V_233 -> V_200 << V_233 -> V_237 ;
}
return F_141 ( V_5 , V_233 -> V_6 , V_200 , V_1 ) ;
}
int F_155 ( struct V_220 * V_225 ,
struct V_230 * V_231 )
{
struct V_232 * V_233 = (struct V_232 * ) V_225 -> V_234 ;
V_231 -> type = V_235 ;
V_231 -> V_18 = 1 ;
V_231 -> V_42 . V_238 . V_239 = V_233 -> V_240 ;
if ( V_231 -> V_42 . V_238 . V_241 > V_233 -> V_240 - 1 )
V_231 -> V_42 . V_238 . V_241 = V_233 -> V_240 - 1 ;
strcpy ( V_231 -> V_42 . V_238 . V_48 ,
V_233 -> V_242 [ V_231 -> V_42 . V_238 . V_241 ] ) ;
return 0 ;
}
int F_156 ( struct V_220 * V_225 ,
struct V_230 * V_231 )
{
int V_240 = V_225 -> V_234 ;
if ( V_240 == 1 && ! strstr ( V_225 -> V_249 . V_48 , L_62 ) )
V_231 -> type = V_250 ;
else
V_231 -> type = V_251 ;
V_231 -> V_18 = 1 ;
V_231 -> V_42 . integer . F_7 = 0 ;
V_231 -> V_42 . integer . V_240 = V_240 ;
return 0 ;
}
int F_157 ( struct V_220 * V_225 ,
struct V_230 * V_231 )
{
struct V_252 * V_253 =
(struct V_252 * ) V_225 -> V_234 ;
int V_254 ;
if ( ! V_253 -> V_254 )
V_253 -> V_254 = V_253 -> V_240 ;
V_254 = V_253 -> V_254 ;
if ( V_254 == 1 && ! strstr ( V_225 -> V_249 . V_48 , L_62 ) )
V_231 -> type = V_250 ;
else
V_231 -> type = V_251 ;
V_231 -> V_18 = F_158 ( V_253 ) ? 2 : 1 ;
V_231 -> V_42 . integer . F_7 = 0 ;
V_231 -> V_42 . integer . V_240 = V_254 ;
return 0 ;
}
int F_159 ( struct V_220 * V_225 ,
struct V_243 * V_244 )
{
struct V_252 * V_253 =
(struct V_252 * ) V_225 -> V_234 ;
struct V_4 * V_5 = F_151 ( V_225 ) ;
unsigned int V_6 = V_253 -> V_6 ;
unsigned int V_255 = V_253 -> V_256 ;
unsigned int V_257 = V_253 -> V_257 ;
unsigned int V_258 = V_253 -> V_258 ;
int V_240 = V_253 -> V_240 ;
unsigned int V_200 = ( 1 << F_160 ( V_240 ) ) - 1 ;
unsigned int V_259 = V_253 -> V_259 ;
V_244 -> V_42 . integer . V_42 [ 0 ] =
( F_4 ( V_5 , V_6 ) >> V_257 ) & V_200 ;
if ( V_259 )
V_244 -> V_42 . integer . V_42 [ 0 ] =
V_240 - V_244 -> V_42 . integer . V_42 [ 0 ] ;
if ( F_158 ( V_253 ) ) {
if ( V_6 == V_255 )
V_244 -> V_42 . integer . V_42 [ 1 ] =
( F_4 ( V_5 , V_6 ) >> V_258 ) & V_200 ;
else
V_244 -> V_42 . integer . V_42 [ 1 ] =
( F_4 ( V_5 , V_255 ) >> V_257 ) & V_200 ;
if ( V_259 )
V_244 -> V_42 . integer . V_42 [ 1 ] =
V_240 - V_244 -> V_42 . integer . V_42 [ 1 ] ;
}
return 0 ;
}
int F_161 ( struct V_220 * V_225 ,
struct V_243 * V_244 )
{
struct V_252 * V_253 =
(struct V_252 * ) V_225 -> V_234 ;
struct V_4 * V_5 = F_151 ( V_225 ) ;
unsigned int V_6 = V_253 -> V_6 ;
unsigned int V_255 = V_253 -> V_256 ;
unsigned int V_257 = V_253 -> V_257 ;
unsigned int V_258 = V_253 -> V_258 ;
int V_240 = V_253 -> V_240 ;
unsigned int V_200 = ( 1 << F_160 ( V_240 ) ) - 1 ;
unsigned int V_259 = V_253 -> V_259 ;
int V_65 ;
bool V_260 = 0 ;
unsigned int V_261 = 0 ;
unsigned int V_1 , V_262 ;
V_1 = ( V_244 -> V_42 . integer . V_42 [ 0 ] & V_200 ) ;
if ( V_259 )
V_1 = V_240 - V_1 ;
V_262 = V_200 << V_257 ;
V_1 = V_1 << V_257 ;
if ( F_158 ( V_253 ) ) {
V_261 = ( V_244 -> V_42 . integer . V_42 [ 1 ] & V_200 ) ;
if ( V_259 )
V_261 = V_240 - V_261 ;
if ( V_6 == V_255 ) {
V_262 |= V_200 << V_258 ;
V_1 |= V_261 << V_258 ;
} else {
V_261 = V_261 << V_257 ;
V_260 = 1 ;
}
}
V_65 = F_141 ( V_5 , V_6 , V_262 , V_1 ) ;
if ( V_65 < 0 )
return V_65 ;
if ( V_260 )
V_65 = F_141 ( V_5 , V_255 , V_262 , V_261 ) ;
return V_65 ;
}
int F_162 ( struct V_220 * V_225 ,
struct V_230 * V_231 )
{
struct V_252 * V_253 =
(struct V_252 * ) V_225 -> V_234 ;
int V_254 ;
int F_7 = V_253 -> F_7 ;
if ( ! V_253 -> V_254 )
V_253 -> V_254 = V_253 -> V_240 ;
V_254 = V_253 -> V_254 ;
V_231 -> type = V_251 ;
V_231 -> V_18 = 2 ;
V_231 -> V_42 . integer . F_7 = 0 ;
V_231 -> V_42 . integer . V_240 = V_254 - F_7 ;
return 0 ;
}
int F_163 ( struct V_220 * V_225 ,
struct V_243 * V_244 )
{
struct V_252 * V_253 =
(struct V_252 * ) V_225 -> V_234 ;
struct V_4 * V_5 = F_151 ( V_225 ) ;
unsigned int V_6 = V_253 -> V_6 ;
int F_7 = V_253 -> F_7 ;
int V_1 = F_4 ( V_5 , V_6 ) ;
V_244 -> V_42 . integer . V_42 [ 0 ] =
( ( signed char ) ( V_1 & 0xff ) ) - F_7 ;
V_244 -> V_42 . integer . V_42 [ 1 ] =
( ( signed char ) ( ( V_1 >> 8 ) & 0xff ) ) - F_7 ;
return 0 ;
}
int F_164 ( struct V_220 * V_225 ,
struct V_243 * V_244 )
{
struct V_252 * V_253 =
(struct V_252 * ) V_225 -> V_234 ;
struct V_4 * V_5 = F_151 ( V_225 ) ;
unsigned int V_6 = V_253 -> V_6 ;
int F_7 = V_253 -> F_7 ;
unsigned int V_1 ;
V_1 = ( V_244 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & 0xff ;
V_1 |= ( ( V_244 -> V_42 . integer . V_42 [ 1 ] + F_7 ) & 0xff ) << 8 ;
return F_141 ( V_5 , V_6 , 0xffff , V_1 ) ;
}
int F_165 ( struct V_4 * V_5 ,
const char * V_48 , int V_240 )
{
struct V_69 * V_46 = V_5 -> V_46 -> V_69 ;
struct V_220 * V_263 ;
struct V_252 * V_253 ;
int V_167 = 0 ;
int V_14 = - V_17 ;
if ( F_166 ( ! V_48 || V_240 <= 0 ) )
return - V_17 ;
F_34 (kctl, &card->controls, list) {
if ( ! strncmp ( V_263 -> V_249 . V_48 , V_48 , sizeof( V_263 -> V_249 . V_48 ) ) ) {
V_167 = 1 ;
break;
}
}
if ( V_167 ) {
V_253 = (struct V_252 * ) V_263 -> V_234 ;
if ( V_240 <= V_253 -> V_240 ) {
V_253 -> V_254 = V_240 ;
V_14 = 0 ;
}
}
return V_14 ;
}
int F_167 ( struct V_220 * V_225 ,
struct V_230 * V_231 )
{
struct V_252 * V_253 =
(struct V_252 * ) V_225 -> V_234 ;
int V_240 = V_253 -> V_240 ;
int F_7 = V_253 -> F_7 ;
V_231 -> type = V_251 ;
V_231 -> V_18 = 2 ;
V_231 -> V_42 . integer . F_7 = 0 ;
V_231 -> V_42 . integer . V_240 = V_240 - F_7 ;
return 0 ;
}
int F_168 ( struct V_220 * V_225 ,
struct V_243 * V_244 )
{
struct V_252 * V_253 =
(struct V_252 * ) V_225 -> V_234 ;
struct V_4 * V_5 = F_151 ( V_225 ) ;
unsigned int V_200 = ( 1 << V_253 -> V_257 ) - 1 ;
int F_7 = V_253 -> F_7 ;
int V_1 = F_4 ( V_5 , V_253 -> V_6 ) & V_200 ;
int V_264 = F_4 ( V_5 , V_253 -> V_256 ) & V_200 ;
V_244 -> V_42 . integer . V_42 [ 0 ] = ( ( V_1 & 0xff ) - F_7 ) & V_200 ;
V_244 -> V_42 . integer . V_42 [ 1 ] = ( ( V_264 & 0xff ) - F_7 ) & V_200 ;
return 0 ;
}
int F_169 ( struct V_220 * V_225 ,
struct V_243 * V_244 )
{
struct V_252 * V_253 =
(struct V_252 * ) V_225 -> V_234 ;
struct V_4 * V_5 = F_151 ( V_225 ) ;
unsigned int V_200 = ( 1 << V_253 -> V_257 ) - 1 ;
int F_7 = V_253 -> F_7 ;
int V_14 ;
unsigned int V_1 , V_264 , V_265 , V_266 ;
V_1 = ( ( V_244 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & 0xff ) ;
V_1 &= V_200 ;
V_264 = ( ( V_244 -> V_42 . integer . V_42 [ 1 ] + F_7 ) & 0xff ) ;
V_264 &= V_200 ;
V_265 = F_4 ( V_5 , V_253 -> V_6 ) & V_200 ;
V_266 = F_4 ( V_5 , V_253 -> V_256 ) & V_200 ;
V_14 = 0 ;
if ( V_265 != V_1 ) {
V_14 = F_22 ( V_5 , V_253 -> V_6 , V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( V_266 != V_264 ) {
V_14 = F_22 ( V_5 , V_253 -> V_256 , V_264 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
int F_170 ( struct V_220 * V_225 ,
struct V_230 * V_231 )
{
struct V_4 * V_5 = F_151 ( V_225 ) ;
struct V_267 * V_268 = ( void * ) V_225 -> V_234 ;
V_231 -> type = V_269 ;
V_231 -> V_18 = V_268 -> V_270 * V_5 -> V_271 ;
return 0 ;
}
int F_171 ( struct V_220 * V_225 ,
struct V_243 * V_244 )
{
struct V_267 * V_268 = ( void * ) V_225 -> V_234 ;
struct V_4 * V_5 = F_151 ( V_225 ) ;
int V_14 ;
if ( V_5 -> V_204 )
V_14 = F_172 ( V_5 -> V_205 , V_268 -> V_272 ,
V_244 -> V_42 . V_273 . V_198 ,
V_268 -> V_270 * V_5 -> V_271 ) ;
else
V_14 = - V_17 ;
if ( V_14 == 0 && V_268 -> V_200 ) {
switch ( V_5 -> V_271 ) {
case 1 :
V_244 -> V_42 . V_273 . V_198 [ 0 ] &= ~ V_268 -> V_200 ;
break;
case 2 :
( ( V_274 * ) ( & V_244 -> V_42 . V_273 . V_198 ) ) [ 0 ]
&= ~ V_268 -> V_200 ;
break;
case 4 :
( ( V_275 * ) ( & V_244 -> V_42 . V_273 . V_198 ) ) [ 0 ]
&= ~ V_268 -> V_200 ;
break;
default:
return - V_17 ;
}
}
return V_14 ;
}
int F_173 ( struct V_220 * V_225 ,
struct V_243 * V_244 )
{
struct V_267 * V_268 = ( void * ) V_225 -> V_234 ;
struct V_4 * V_5 = F_151 ( V_225 ) ;
int V_14 , V_8 ;
unsigned int V_1 ;
void * V_198 ;
if ( ! V_5 -> V_204 )
return - V_17 ;
V_198 = V_244 -> V_42 . V_273 . V_198 ;
V_8 = V_268 -> V_270 * V_5 -> V_271 ;
if ( V_268 -> V_200 ) {
V_14 = F_174 ( V_5 -> V_205 , V_268 -> V_272 , & V_1 ) ;
if ( V_14 != 0 )
return V_14 ;
V_1 &= V_268 -> V_200 ;
V_198 = F_175 ( V_198 , V_8 , V_37 ) ;
if ( ! V_198 )
return - V_38 ;
switch ( V_5 -> V_271 ) {
case 1 :
( ( V_276 * ) V_198 ) [ 0 ] &= ~ V_268 -> V_200 ;
( ( V_276 * ) V_198 ) [ 0 ] |= V_1 ;
break;
case 2 :
( ( V_274 * ) V_198 ) [ 0 ] &= F_176 ( ~ V_268 -> V_200 ) ;
( ( V_274 * ) V_198 ) [ 0 ] |= F_176 ( V_1 ) ;
break;
case 4 :
( ( V_275 * ) V_198 ) [ 0 ] &= F_177 ( ~ V_268 -> V_200 ) ;
( ( V_275 * ) V_198 ) [ 0 ] |= F_177 ( V_1 ) ;
break;
default:
return - V_17 ;
}
}
V_14 = F_178 ( V_5 -> V_205 , V_268 -> V_272 ,
V_198 , V_8 ) ;
if ( V_268 -> V_200 )
F_16 ( V_198 ) ;
return V_14 ;
}
int F_179 ( struct V_57 * V_58 , int V_277 ,
unsigned int V_278 , int V_279 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_81 -> V_280 )
return V_58 -> V_10 -> V_81 -> V_280 ( V_58 , V_277 , V_278 , V_279 ) ;
else if ( V_58 -> V_5 && V_58 -> V_5 -> V_10 -> V_280 )
return V_58 -> V_5 -> V_10 -> V_280 ( V_58 -> V_5 , V_277 , 0 ,
V_278 , V_279 ) ;
else
return - V_17 ;
}
int F_180 ( struct V_4 * V_5 , int V_277 ,
int V_281 , unsigned int V_278 , int V_279 )
{
if ( V_5 -> V_10 -> V_280 )
return V_5 -> V_10 -> V_280 ( V_5 , V_277 , V_281 ,
V_278 , V_279 ) ;
else
return - V_17 ;
}
int F_181 ( struct V_57 * V_58 ,
int V_282 , int div )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_81 -> V_283 )
return V_58 -> V_10 -> V_81 -> V_283 ( V_58 , V_282 , div ) ;
else
return - V_17 ;
}
int F_182 ( struct V_57 * V_58 , int V_284 , int V_281 ,
unsigned int V_285 , unsigned int V_286 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_81 -> V_287 )
return V_58 -> V_10 -> V_81 -> V_287 ( V_58 , V_284 , V_281 ,
V_285 , V_286 ) ;
else if ( V_58 -> V_5 && V_58 -> V_5 -> V_10 -> V_287 )
return V_58 -> V_5 -> V_10 -> V_287 ( V_58 -> V_5 , V_284 , V_281 ,
V_285 , V_286 ) ;
else
return - V_17 ;
}
int F_183 ( struct V_4 * V_5 , int V_284 , int V_281 ,
unsigned int V_285 , unsigned int V_286 )
{
if ( V_5 -> V_10 -> V_287 )
return V_5 -> V_10 -> V_287 ( V_5 , V_284 , V_281 ,
V_285 , V_286 ) ;
else
return - V_17 ;
}
int F_112 ( struct V_57 * V_58 , unsigned int V_288 )
{
if ( V_58 -> V_10 == NULL )
return - V_17 ;
if ( V_58 -> V_10 -> V_81 -> V_289 == NULL )
return - V_181 ;
return V_58 -> V_10 -> V_81 -> V_289 ( V_58 , V_288 ) ;
}
int F_184 ( struct V_57 * V_58 ,
unsigned int V_290 , unsigned int V_291 , int V_292 , int V_293 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_81 -> V_294 )
return V_58 -> V_10 -> V_81 -> V_294 ( V_58 , V_290 , V_291 ,
V_292 , V_293 ) ;
else
return - V_17 ;
}
int F_185 ( struct V_57 * V_58 ,
unsigned int V_295 , unsigned int * V_296 ,
unsigned int V_297 , unsigned int * V_298 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_81 -> V_299 )
return V_58 -> V_10 -> V_81 -> V_299 ( V_58 , V_295 , V_296 ,
V_297 , V_298 ) ;
else
return - V_17 ;
}
int F_186 ( struct V_57 * V_58 , int V_300 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_81 -> V_301 )
return V_58 -> V_10 -> V_81 -> V_301 ( V_58 , V_300 ) ;
else
return - V_17 ;
}
int F_187 ( struct V_57 * V_58 , int V_302 )
{
if ( V_58 -> V_10 && V_58 -> V_10 -> V_81 -> V_82 )
return V_58 -> V_10 -> V_81 -> V_82 ( V_58 , V_302 ) ;
else
return - V_17 ;
}
int F_122 ( struct V_59 * V_46 )
{
int V_3 ;
if ( ! V_46 -> V_48 || ! V_46 -> V_27 )
return - V_17 ;
for ( V_3 = 0 ; V_3 < V_46 -> V_173 ; V_3 ++ ) {
struct V_109 * V_303 = & V_46 -> V_79 [ V_3 ] ;
if ( ! ! V_303 -> V_118 == ! ! V_303 -> V_117 ) {
F_62 ( V_46 -> V_27 ,
L_63 ,
V_303 -> V_48 ) ;
return - V_17 ;
}
if ( V_303 -> V_110 && V_303 -> V_121 ) {
F_62 ( V_46 -> V_27 ,
L_64 , V_303 -> V_48 ) ;
return - V_17 ;
}
if ( ! ! V_303 -> V_115 == ! ! V_303 -> V_113 ) {
F_62 ( V_46 -> V_27 ,
L_65 ,
V_303 -> V_48 ) ;
return - V_17 ;
}
}
F_87 ( V_46 -> V_27 , V_46 ) ;
F_188 ( V_46 ) ;
F_38 ( V_46 ) ;
V_46 -> V_31 = F_189 ( V_46 -> V_27 ,
sizeof( struct V_30 ) *
( V_46 -> V_173 + V_46 -> V_178 ) ,
V_37 ) ;
if ( V_46 -> V_31 == NULL )
return - V_38 ;
V_46 -> V_75 = 0 ;
V_46 -> V_156 = & V_46 -> V_31 [ V_46 -> V_173 ] ;
for ( V_3 = 0 ; V_3 < V_46 -> V_173 ; V_3 ++ )
V_46 -> V_31 [ V_3 ] . V_79 = & V_46 -> V_79 [ V_3 ] ;
F_190 ( & V_46 -> V_148 ) ;
F_190 ( & V_46 -> V_304 ) ;
V_46 -> V_172 = 0 ;
F_88 ( & V_46 -> V_171 ) ;
F_104 ( & V_305 ) ;
F_79 ( & V_46 -> V_148 , & V_123 ) ;
F_119 () ;
F_105 ( & V_305 ) ;
F_57 ( V_46 -> V_27 , L_66 , V_46 -> V_48 ) ;
return 0 ;
}
int F_125 ( struct V_59 * V_46 )
{
if ( V_46 -> V_172 )
F_123 ( V_46 ) ;
F_104 ( & V_305 ) ;
F_66 ( & V_46 -> V_148 ) ;
F_105 ( & V_305 ) ;
F_57 ( V_46 -> V_27 , L_67 , V_46 -> V_48 ) ;
return 0 ;
}
static char * F_191 ( struct V_26 * V_27 , int * V_249 )
{
char * V_167 , V_48 [ V_306 ] ;
int V_307 , V_308 ;
if ( V_136 ( V_27 ) == NULL )
return NULL ;
F_192 ( V_48 , V_136 ( V_27 ) , V_306 ) ;
V_167 = strstr ( V_48 , V_27 -> V_10 -> V_48 ) ;
if ( V_167 ) {
if ( sscanf ( & V_167 [ strlen ( V_27 -> V_10 -> V_48 ) ] , L_68 , V_249 ) == 1 ) {
if ( * V_249 == - 1 )
V_167 [ strlen ( V_27 -> V_10 -> V_48 ) ] = '\0' ;
}
} else {
if ( sscanf ( V_48 , L_69 , & V_307 , & V_308 ) == 2 ) {
char V_309 [ V_306 ] ;
* V_249 = ( ( V_307 & 0xffff ) << 16 ) + V_308 ;
snprintf ( V_309 , V_306 , L_70 , V_27 -> V_10 -> V_48 , V_48 ) ;
F_192 ( V_48 , V_309 , V_306 ) ;
} else
* V_249 = 0 ;
}
return F_193 ( V_48 , V_37 ) ;
}
static inline char * F_194 ( struct V_26 * V_27 ,
struct V_77 * V_310 )
{
if ( V_310 -> V_48 == NULL ) {
F_70 ( L_71 ,
V_136 ( V_27 ) ) ;
return NULL ;
}
return F_193 ( V_310 -> V_48 , V_37 ) ;
}
int F_195 ( struct V_26 * V_27 ,
struct V_77 * V_310 )
{
struct V_57 * V_58 ;
F_57 ( V_27 , L_72 , V_136 ( V_27 ) ) ;
V_58 = F_85 ( sizeof( struct V_57 ) , V_37 ) ;
if ( V_58 == NULL )
return - V_38 ;
V_58 -> V_48 = F_191 ( V_27 , & V_58 -> V_249 ) ;
if ( V_58 -> V_48 == NULL ) {
F_16 ( V_58 ) ;
return - V_38 ;
}
V_58 -> V_27 = V_27 ;
V_58 -> V_10 = V_310 ;
if ( ! V_58 -> V_10 -> V_81 )
V_58 -> V_10 -> V_81 = & V_311 ;
F_104 ( & V_305 ) ;
F_79 ( & V_58 -> V_148 , & V_312 ) ;
F_119 () ;
F_105 ( & V_305 ) ;
F_196 ( L_73 , V_58 -> V_48 ) ;
return 0 ;
}
void F_197 ( struct V_26 * V_27 )
{
struct V_57 * V_58 ;
F_34 (dai, &dai_list, list) {
if ( V_27 == V_58 -> V_27 )
goto V_167;
}
return;
V_167:
F_104 ( & V_305 ) ;
F_66 ( & V_58 -> V_148 ) ;
F_105 ( & V_305 ) ;
F_196 ( L_74 , V_58 -> V_48 ) ;
F_16 ( V_58 -> V_48 ) ;
F_16 ( V_58 ) ;
}
int F_198 ( struct V_26 * V_27 ,
struct V_77 * V_310 , T_1 V_18 )
{
struct V_57 * V_58 ;
int V_3 , V_14 = 0 ;
F_57 ( V_27 , L_75 , V_136 ( V_27 ) , V_18 ) ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ ) {
V_58 = F_85 ( sizeof( struct V_57 ) , V_37 ) ;
if ( V_58 == NULL ) {
V_14 = - V_38 ;
goto V_65;
}
V_58 -> V_48 = F_194 ( V_27 , & V_310 [ V_3 ] ) ;
if ( V_58 -> V_48 == NULL ) {
F_16 ( V_58 ) ;
V_14 = - V_17 ;
goto V_65;
}
V_58 -> V_27 = V_27 ;
V_58 -> V_10 = & V_310 [ V_3 ] ;
if ( V_58 -> V_10 -> V_249 )
V_58 -> V_249 = V_58 -> V_10 -> V_249 ;
else
V_58 -> V_249 = V_3 ;
if ( ! V_58 -> V_10 -> V_81 )
V_58 -> V_10 -> V_81 = & V_311 ;
F_104 ( & V_305 ) ;
F_79 ( & V_58 -> V_148 , & V_312 ) ;
F_105 ( & V_305 ) ;
F_196 ( L_73 , V_58 -> V_48 ) ;
}
F_104 ( & V_305 ) ;
F_119 () ;
F_105 ( & V_305 ) ;
return 0 ;
V_65:
for ( V_3 -- ; V_3 >= 0 ; V_3 -- )
F_197 ( V_27 ) ;
return V_14 ;
}
void F_199 ( struct V_26 * V_27 , T_1 V_18 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ )
F_197 ( V_27 ) ;
}
int F_200 ( struct V_26 * V_27 ,
struct V_150 * V_313 )
{
struct V_54 * V_55 ;
F_57 ( V_27 , L_76 , V_136 ( V_27 ) ) ;
V_55 = F_85 ( sizeof( struct V_54 ) , V_37 ) ;
if ( V_55 == NULL )
return - V_38 ;
V_55 -> V_48 = F_191 ( V_27 , & V_55 -> V_249 ) ;
if ( V_55 -> V_48 == NULL ) {
F_16 ( V_55 ) ;
return - V_38 ;
}
V_55 -> V_27 = V_27 ;
V_55 -> V_10 = V_313 ;
V_55 -> V_53 . V_27 = V_27 ;
V_55 -> V_53 . V_55 = V_55 ;
V_55 -> V_53 . V_314 = V_313 -> V_314 ;
F_88 ( & V_55 -> V_171 ) ;
F_104 ( & V_305 ) ;
F_79 ( & V_55 -> V_148 , & V_315 ) ;
F_119 () ;
F_105 ( & V_305 ) ;
F_196 ( L_77 , V_55 -> V_48 ) ;
return 0 ;
}
void F_201 ( struct V_26 * V_27 )
{
struct V_54 * V_55 ;
F_34 (platform, &platform_list, list) {
if ( V_27 == V_55 -> V_27 )
goto V_167;
}
return;
V_167:
F_104 ( & V_305 ) ;
F_66 ( & V_55 -> V_148 ) ;
F_105 ( & V_305 ) ;
F_196 ( L_78 , V_55 -> V_48 ) ;
F_16 ( V_55 -> V_48 ) ;
F_16 ( V_55 ) ;
}
static void F_202 ( struct V_316 * V_317 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_113 ( V_318 ) ; V_3 ++ )
if ( V_317 -> V_213 & V_318 [ V_3 ] )
V_317 -> V_213 |= V_318 [ V_3 ] ;
}
int F_203 ( struct V_26 * V_27 ,
const struct V_138 * V_319 ,
struct V_77 * V_310 ,
int V_320 )
{
T_1 V_321 ;
struct V_4 * V_5 ;
int V_14 , V_3 ;
F_57 ( V_27 , L_79 , V_136 ( V_27 ) ) ;
V_5 = F_85 ( sizeof( struct V_4 ) , V_37 ) ;
if ( V_5 == NULL )
return - V_38 ;
V_5 -> V_48 = F_191 ( V_27 , & V_5 -> V_249 ) ;
if ( V_5 -> V_48 == NULL ) {
F_16 ( V_5 ) ;
return - V_38 ;
}
if ( V_319 -> V_169 )
V_5 -> V_169 = V_319 -> V_169 ;
else
V_5 -> V_169 = V_322 ;
V_5 -> V_194 = V_319 -> V_194 ;
V_5 -> V_193 = V_319 -> V_193 ;
V_5 -> V_190 = V_319 -> V_190 ;
V_5 -> V_191 = V_319 -> V_191 ;
V_5 -> V_192 = V_319 -> V_192 ;
V_5 -> V_323 = V_319 -> V_323 ;
V_5 -> V_53 . V_92 = V_98 ;
V_5 -> V_53 . V_27 = V_27 ;
V_5 -> V_53 . V_5 = V_5 ;
V_5 -> V_53 . V_324 = V_319 -> V_324 ;
V_5 -> V_53 . V_314 = V_319 -> V_314 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_10 = V_319 ;
V_5 -> V_320 = V_320 ;
F_88 ( & V_5 -> V_171 ) ;
if ( V_319 -> V_11 && V_319 -> V_13 ) {
V_321 = V_319 -> V_11 * V_319 -> V_13 ;
V_5 -> V_321 = V_321 ;
if ( V_319 -> V_325 ) {
V_5 -> V_326 = F_175 ( V_319 -> V_325 ,
V_321 , V_37 ) ;
if ( ! V_5 -> V_326 ) {
V_14 = - V_38 ;
goto V_327;
}
}
}
if ( V_319 -> V_328 && V_319 -> V_329 ) {
if ( ! V_5 -> V_190 )
V_5 -> V_190 = V_330 ;
if ( ! V_5 -> V_191 )
V_5 -> V_191 = V_331 ;
if ( ! V_5 -> V_192 )
V_5 -> V_192 = V_332 ;
}
for ( V_3 = 0 ; V_3 < V_320 ; V_3 ++ ) {
F_202 ( & V_310 [ V_3 ] . V_333 ) ;
F_202 ( & V_310 [ V_3 ] . V_334 ) ;
}
if ( V_320 ) {
V_14 = F_198 ( V_27 , V_310 , V_320 ) ;
if ( V_14 < 0 )
goto V_327;
}
F_104 ( & V_305 ) ;
F_79 ( & V_5 -> V_148 , & V_335 ) ;
F_119 () ;
F_105 ( & V_305 ) ;
F_196 ( L_80 , V_5 -> V_48 ) ;
return 0 ;
V_327:
F_16 ( V_5 -> V_326 ) ;
V_5 -> V_326 = NULL ;
F_16 ( V_5 -> V_48 ) ;
F_16 ( V_5 ) ;
return V_14 ;
}
void F_204 ( struct V_26 * V_27 )
{
struct V_4 * V_5 ;
int V_3 ;
F_34 (codec, &codec_list, list) {
if ( V_27 == V_5 -> V_27 )
goto V_167;
}
return;
V_167:
if ( V_5 -> V_320 )
for ( V_3 = 0 ; V_3 < V_5 -> V_320 ; V_3 ++ )
F_197 ( V_27 ) ;
F_104 ( & V_305 ) ;
F_66 ( & V_5 -> V_148 ) ;
F_105 ( & V_305 ) ;
F_196 ( L_81 , V_5 -> V_48 ) ;
F_205 ( V_5 ) ;
F_16 ( V_5 -> V_326 ) ;
F_16 ( V_5 -> V_48 ) ;
F_16 ( V_5 ) ;
}
int F_206 ( struct V_59 * V_46 ,
const char * V_336 )
{
struct V_337 * V_338 = V_46 -> V_27 -> V_114 ;
int V_14 ;
V_14 = F_207 ( V_338 , V_336 , 0 , & V_46 -> V_48 ) ;
if ( V_14 < 0 && V_14 != - V_17 ) {
F_62 ( V_46 -> V_27 ,
L_82 ,
V_336 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
int F_208 ( struct V_59 * V_46 ,
const char * V_336 )
{
struct V_337 * V_338 = V_46 -> V_27 -> V_114 ;
int V_339 ;
struct V_340 * V_341 ;
int V_3 , V_14 ;
V_339 = F_209 ( V_338 , V_336 ) ;
if ( V_339 < 0 || V_339 & 1 ) {
F_62 ( V_46 -> V_27 ,
L_83 ,
V_336 ) ;
return - V_17 ;
}
V_339 /= 2 ;
if ( ! V_339 ) {
F_62 ( V_46 -> V_27 ,
L_84 ,
V_336 ) ;
return - V_17 ;
}
V_341 = F_189 ( V_46 -> V_27 , V_339 * sizeof( * V_341 ) ,
V_37 ) ;
if ( ! V_341 ) {
F_62 ( V_46 -> V_27 ,
L_85 ) ;
return - V_17 ;
}
for ( V_3 = 0 ; V_3 < V_339 ; V_3 ++ ) {
V_14 = F_207 ( V_338 , V_336 ,
2 * V_3 , & V_341 [ V_3 ] . V_342 ) ;
if ( V_14 ) {
F_62 ( V_46 -> V_27 ,
L_86 ,
V_336 , 2 * V_3 , V_14 ) ;
return - V_17 ;
}
V_14 = F_207 ( V_338 , V_336 ,
( 2 * V_3 ) + 1 , & V_341 [ V_3 ] . V_281 ) ;
if ( V_14 ) {
F_62 ( V_46 -> V_27 ,
L_86 ,
V_336 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_17 ;
}
}
V_46 -> V_147 = V_339 ;
V_46 -> V_146 = V_341 ;
return 0 ;
}
static int T_5 F_210 ( void )
{
#ifdef F_107
V_60 = F_24 ( L_87 , NULL ) ;
if ( F_211 ( V_60 ) || ! V_60 ) {
F_93 ( L_88 ) ;
V_60 = NULL ;
}
if ( ! F_27 ( L_89 , 0444 , V_60 , NULL ,
& V_343 ) )
F_93 ( L_90 ) ;
if ( ! F_27 ( L_91 , 0444 , V_60 , NULL ,
& V_344 ) )
F_93 ( L_92 ) ;
if ( ! F_27 ( L_93 , 0444 , V_60 , NULL ,
& V_345 ) )
F_93 ( L_94 ) ;
#endif
F_212 () ;
return F_213 ( & V_346 ) ;
}
static void T_6 F_214 ( void )
{
F_215 () ;
#ifdef F_107
F_30 ( V_60 ) ;
#endif
F_216 ( & V_346 ) ;
}
