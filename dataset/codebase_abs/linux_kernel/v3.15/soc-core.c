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
struct V_60 * V_61 ;
if ( ! V_7 )
return - V_38 ;
F_34 (component, &component_list, list) {
F_34 (dai, &component->dai_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_25 - V_14 , L_10 ,
V_61 -> V_49 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_25 ) {
V_14 = V_25 ;
break;
}
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
static void F_38 ( struct V_62 * V_47 )
{
V_47 -> V_46 = F_24 ( V_47 -> V_49 ,
V_63 ) ;
if ( ! V_47 -> V_46 ) {
F_25 ( V_47 -> V_27 ,
L_11 ) ;
return;
}
V_47 -> V_64 = F_39 ( L_12 , 0644 ,
V_47 -> V_46 ,
& V_47 -> V_65 ) ;
if ( ! V_47 -> V_64 )
F_25 ( V_47 -> V_27 ,
L_13 ) ;
}
static void F_40 ( struct V_62 * V_47 )
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
static inline void F_38 ( struct V_62 * V_47 )
{
}
static inline void F_40 ( struct V_62 * V_47 )
{
}
struct V_66 * F_41 ( struct V_62 * V_47 ,
const char * V_67 , int V_68 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_47 -> V_69 ; V_3 ++ ) {
if ( V_47 -> V_31 [ V_3 ] . V_67 -> V_70 &&
! strcmp ( V_47 -> V_31 [ V_3 ] . V_67 -> V_49 , V_67 ) )
return V_47 -> V_31 [ V_3 ] . V_71 -> V_72 [ V_68 ] . V_73 ;
}
F_42 ( V_47 -> V_27 , L_14 , V_67 ) ;
return NULL ;
}
struct V_30 * F_43 ( struct V_62 * V_47 ,
const char * V_67 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_47 -> V_69 ; V_3 ++ ) {
if ( ! strcmp ( V_47 -> V_31 [ V_3 ] . V_67 -> V_49 , V_67 ) )
return & V_47 -> V_31 [ V_3 ] ;
}
F_42 ( V_47 -> V_27 , L_15 , V_67 ) ;
return NULL ;
}
static int F_44 ( struct V_4 * V_5 )
{
if ( V_5 -> V_74 -> V_27 . V_75 )
F_45 ( & V_5 -> V_74 -> V_27 ) ;
return 0 ;
}
static void F_46 ( struct V_26 * V_27 ) {}
static int F_47 ( struct V_4 * V_5 )
{
int V_76 ;
V_5 -> V_74 -> V_27 . V_75 = & V_77 ;
V_5 -> V_74 -> V_27 . V_78 = V_5 -> V_47 -> V_27 ;
V_5 -> V_74 -> V_27 . V_79 = F_46 ;
F_48 ( & V_5 -> V_74 -> V_27 , L_16 ,
V_5 -> V_47 -> V_80 -> V_81 , 0 , V_5 -> V_49 ) ;
V_76 = F_49 ( & V_5 -> V_74 -> V_27 ) ;
if ( V_76 < 0 ) {
F_50 ( V_5 -> V_27 , L_17 ) ;
V_5 -> V_74 -> V_27 . V_75 = NULL ;
return V_76 ;
}
return 0 ;
}
static void F_51 ( struct V_82 * V_83 )
{
}
int F_52 ( struct V_26 * V_27 )
{
struct V_62 * V_47 = F_9 ( V_27 ) ;
struct V_4 * V_5 ;
int V_3 ;
if ( F_53 ( & V_47 -> V_84 ) )
return 0 ;
F_54 ( V_47 -> V_80 ) ;
F_55 ( V_47 -> V_80 , V_85 ) ;
F_56 ( V_47 -> V_80 ) ;
F_57 ( V_47 -> V_80 , V_86 ) ;
for ( V_3 = 0 ; V_3 < V_47 -> V_87 ; V_3 ++ ) {
struct V_60 * V_61 = V_47 -> V_31 [ V_3 ] . V_88 ;
struct V_89 * V_90 = V_61 -> V_10 ;
if ( V_47 -> V_31 [ V_3 ] . V_67 -> V_91 )
continue;
if ( V_90 -> V_92 -> V_93 && V_61 -> V_94 )
V_90 -> V_92 -> V_93 ( V_61 , 1 ) ;
}
for ( V_3 = 0 ; V_3 < V_47 -> V_87 ; V_3 ++ ) {
if ( V_47 -> V_31 [ V_3 ] . V_67 -> V_91 )
continue;
F_58 ( V_47 -> V_31 [ V_3 ] . V_71 ) ;
}
if ( V_47 -> V_95 )
V_47 -> V_95 ( V_47 ) ;
for ( V_3 = 0 ; V_3 < V_47 -> V_87 ; V_3 ++ ) {
struct V_60 * V_96 = V_47 -> V_31 [ V_3 ] . V_96 ;
struct V_55 * V_56 = V_47 -> V_31 [ V_3 ] . V_56 ;
if ( V_47 -> V_31 [ V_3 ] . V_67 -> V_91 )
continue;
if ( V_96 -> V_10 -> V_97 && ! V_96 -> V_10 -> V_98 )
V_96 -> V_10 -> V_97 ( V_96 ) ;
if ( V_56 -> V_10 -> V_97 && ! V_56 -> V_99 ) {
V_56 -> V_10 -> V_97 ( V_96 ) ;
V_56 -> V_99 = 1 ;
}
}
for ( V_3 = 0 ; V_3 < V_47 -> V_87 ; V_3 ++ ) {
F_59 ( & V_47 -> V_31 [ V_3 ] . V_100 ) ;
V_47 -> V_31 [ V_3 ] . V_5 -> V_54 . V_101 = V_47 -> V_31 [ V_3 ] . V_5 -> V_54 . V_102 ;
}
for ( V_3 = 0 ; V_3 < V_47 -> V_87 ; V_3 ++ ) {
if ( V_47 -> V_31 [ V_3 ] . V_67 -> V_91 )
continue;
F_60 ( & V_47 -> V_31 [ V_3 ] ,
V_103 ,
V_104 ) ;
F_60 ( & V_47 -> V_31 [ V_3 ] ,
V_105 ,
V_104 ) ;
}
F_61 ( & V_47 -> V_54 ) ;
F_62 ( & V_47 -> V_54 ) ;
F_34 (codec, &card->codec_dev_list, card_list) {
if ( ! V_5 -> V_99 && V_5 -> V_10 -> V_97 ) {
switch ( V_5 -> V_54 . V_102 ) {
case V_106 :
if ( V_5 -> V_54 . V_107 ) {
F_42 ( V_5 -> V_27 ,
L_18 ) ;
break;
}
case V_108 :
V_5 -> V_10 -> V_97 ( V_5 ) ;
V_5 -> V_99 = 1 ;
V_5 -> V_50 = 1 ;
if ( V_5 -> V_109 )
F_63 ( V_5 -> V_110 ) ;
F_64 ( V_5 -> V_27 ) ;
break;
default:
F_42 ( V_5 -> V_27 ,
L_19 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_47 -> V_87 ; V_3 ++ ) {
struct V_60 * V_96 = V_47 -> V_31 [ V_3 ] . V_96 ;
if ( V_47 -> V_31 [ V_3 ] . V_67 -> V_91 )
continue;
if ( V_96 -> V_10 -> V_97 && V_96 -> V_10 -> V_98 )
V_96 -> V_10 -> V_97 ( V_96 ) ;
F_64 ( V_96 -> V_27 ) ;
}
if ( V_47 -> V_111 )
V_47 -> V_111 ( V_47 ) ;
return 0 ;
}
static void F_65 ( struct V_82 * V_83 )
{
struct V_62 * V_47 =
F_66 ( V_83 , struct V_62 , V_112 ) ;
struct V_4 * V_5 ;
int V_3 ;
F_42 ( V_47 -> V_27 , L_20 ) ;
F_57 ( V_47 -> V_80 , V_113 ) ;
if ( V_47 -> V_114 )
V_47 -> V_114 ( V_47 ) ;
for ( V_3 = 0 ; V_3 < V_47 -> V_87 ; V_3 ++ ) {
struct V_60 * V_96 = V_47 -> V_31 [ V_3 ] . V_96 ;
if ( V_47 -> V_31 [ V_3 ] . V_67 -> V_91 )
continue;
if ( V_96 -> V_10 -> V_115 && V_96 -> V_10 -> V_98 )
V_96 -> V_10 -> V_115 ( V_96 ) ;
}
F_34 (codec, &card->codec_dev_list, card_list) {
if ( V_5 -> V_10 -> V_115 && V_5 -> V_99 ) {
switch ( V_5 -> V_54 . V_102 ) {
case V_106 :
case V_108 :
V_5 -> V_10 -> V_115 ( V_5 ) ;
V_5 -> V_99 = 0 ;
break;
default:
F_42 ( V_5 -> V_27 ,
L_21 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_47 -> V_87 ; V_3 ++ ) {
if ( V_47 -> V_31 [ V_3 ] . V_67 -> V_91 )
continue;
F_60 ( & V_47 -> V_31 [ V_3 ] ,
V_103 ,
V_116 ) ;
F_60 ( & V_47 -> V_31 [ V_3 ] ,
V_105 ,
V_116 ) ;
}
for ( V_3 = 0 ; V_3 < V_47 -> V_87 ; V_3 ++ ) {
struct V_60 * V_61 = V_47 -> V_31 [ V_3 ] . V_88 ;
struct V_89 * V_90 = V_61 -> V_10 ;
if ( V_47 -> V_31 [ V_3 ] . V_67 -> V_91 )
continue;
if ( V_90 -> V_92 -> V_93 && V_61 -> V_94 )
V_90 -> V_92 -> V_93 ( V_61 , 0 ) ;
}
for ( V_3 = 0 ; V_3 < V_47 -> V_87 ; V_3 ++ ) {
struct V_60 * V_96 = V_47 -> V_31 [ V_3 ] . V_96 ;
struct V_55 * V_56 = V_47 -> V_31 [ V_3 ] . V_56 ;
if ( V_47 -> V_31 [ V_3 ] . V_67 -> V_91 )
continue;
if ( V_96 -> V_10 -> V_115 && ! V_96 -> V_10 -> V_98 )
V_96 -> V_10 -> V_115 ( V_96 ) ;
if ( V_56 -> V_10 -> V_115 && V_56 -> V_99 ) {
V_56 -> V_10 -> V_115 ( V_96 ) ;
V_56 -> V_99 = 0 ;
}
}
if ( V_47 -> V_117 )
V_47 -> V_117 ( V_47 ) ;
F_42 ( V_47 -> V_27 , L_22 ) ;
F_57 ( V_47 -> V_80 , V_85 ) ;
F_61 ( & V_47 -> V_54 ) ;
F_62 ( & V_47 -> V_54 ) ;
}
int F_67 ( struct V_26 * V_27 )
{
struct V_62 * V_47 = F_9 ( V_27 ) ;
int V_3 , V_98 = 0 ;
if ( F_53 ( & V_47 -> V_84 ) )
return 0 ;
for ( V_3 = 0 ; V_3 < V_47 -> V_87 ; V_3 ++ ) {
struct V_60 * V_96 = V_47 -> V_31 [ V_3 ] . V_96 ;
struct V_60 * V_88 = V_47 -> V_31 [ V_3 ] . V_88 ;
if ( V_96 -> V_118 )
F_68 ( V_96 -> V_27 ) ;
if ( V_88 -> V_118 )
F_68 ( V_88 -> V_27 ) ;
}
for ( V_3 = 0 ; V_3 < V_47 -> V_87 ; V_3 ++ ) {
struct V_60 * V_96 = V_47 -> V_31 [ V_3 ] . V_96 ;
V_98 |= V_96 -> V_10 -> V_98 ;
}
if ( V_98 ) {
F_42 ( V_27 , L_23 ) ;
F_65 ( & V_47 -> V_112 ) ;
} else {
F_42 ( V_27 , L_24 ) ;
if ( ! F_69 ( & V_47 -> V_112 ) )
F_50 ( V_27 , L_25 ) ;
}
return 0 ;
}
static int F_70 ( struct V_62 * V_47 , int V_119 )
{
struct V_120 * V_67 = & V_47 -> V_67 [ V_119 ] ;
struct V_30 * V_31 = & V_47 -> V_31 [ V_119 ] ;
struct V_58 * V_59 ;
struct V_4 * V_5 ;
struct V_55 * V_56 ;
struct V_60 * V_88 , * V_96 ;
const char * V_121 ;
F_42 ( V_47 -> V_27 , L_26 , V_67 -> V_49 , V_119 ) ;
F_34 (component, &component_list, list) {
if ( V_67 -> V_122 &&
V_59 -> V_27 -> V_123 != V_67 -> V_122 )
continue;
if ( V_67 -> V_124 &&
strcmp ( F_71 ( V_59 -> V_27 ) , V_67 -> V_124 ) )
continue;
F_34 (cpu_dai, &component->dai_list, list) {
if ( V_67 -> V_125 &&
strcmp ( V_96 -> V_49 , V_67 -> V_125 ) )
continue;
V_31 -> V_96 = V_96 ;
}
}
if ( ! V_31 -> V_96 ) {
F_50 ( V_47 -> V_27 , L_27 ,
V_67 -> V_125 ) ;
return - V_126 ;
}
F_34 (codec, &codec_list, list) {
if ( V_67 -> V_127 ) {
if ( V_5 -> V_27 -> V_123 != V_67 -> V_127 )
continue;
} else {
if ( strcmp ( V_5 -> V_49 , V_67 -> V_128 ) )
continue;
}
V_31 -> V_5 = V_5 ;
F_34 (codec_dai, &codec->component.dai_list, list) {
if ( ! strcmp ( V_88 -> V_49 , V_67 -> V_129 ) ) {
V_31 -> V_88 = V_88 ;
break;
}
}
if ( ! V_31 -> V_88 ) {
F_50 ( V_47 -> V_27 , L_28 ,
V_67 -> V_129 ) ;
return - V_126 ;
}
}
if ( ! V_31 -> V_5 ) {
F_50 ( V_47 -> V_27 , L_29 ,
V_67 -> V_128 ) ;
return - V_126 ;
}
V_121 = V_67 -> V_121 ;
if ( ! V_121 && ! V_67 -> V_130 )
V_121 = L_30 ;
F_34 (platform, &platform_list, list) {
if ( V_67 -> V_130 ) {
if ( V_56 -> V_27 -> V_123 !=
V_67 -> V_130 )
continue;
} else {
if ( strcmp ( V_56 -> V_49 , V_121 ) )
continue;
}
V_31 -> V_56 = V_56 ;
}
if ( ! V_31 -> V_56 ) {
F_50 ( V_47 -> V_27 , L_31 ,
V_67 -> V_121 ) ;
return - V_126 ;
}
V_47 -> V_87 ++ ;
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
V_56 -> V_131 = 0 ;
F_74 ( & V_56 -> V_132 ) ;
F_75 ( V_56 -> V_27 -> V_10 -> V_133 ) ;
return 0 ;
}
static void F_76 ( struct V_4 * V_5 )
{
int V_76 ;
if ( V_5 -> V_10 -> remove ) {
V_76 = V_5 -> V_10 -> remove ( V_5 ) ;
if ( V_76 < 0 )
F_50 ( V_5 -> V_27 , L_32 , V_76 ) ;
}
F_73 ( & V_5 -> V_54 ) ;
F_29 ( V_5 ) ;
V_5 -> V_131 = 0 ;
F_74 ( & V_5 -> V_132 ) ;
F_75 ( V_5 -> V_27 -> V_10 -> V_133 ) ;
}
static void F_77 ( struct V_62 * V_47 , int V_119 , int V_134 )
{
struct V_30 * V_31 = & V_47 -> V_31 [ V_119 ] ;
struct V_60 * V_88 = V_31 -> V_88 , * V_96 = V_31 -> V_96 ;
int V_76 ;
if ( V_31 -> V_135 ) {
F_78 ( V_31 -> V_27 , & V_136 ) ;
F_78 ( V_31 -> V_27 , & V_137 ) ;
F_45 ( V_31 -> V_27 ) ;
V_31 -> V_135 = 0 ;
}
if ( V_88 && V_88 -> V_131 &&
V_88 -> V_10 -> V_138 == V_134 ) {
if ( V_88 -> V_10 -> remove ) {
V_76 = V_88 -> V_10 -> remove ( V_88 ) ;
if ( V_76 < 0 )
F_50 ( V_88 -> V_27 ,
L_33 ,
V_88 -> V_49 , V_76 ) ;
}
V_88 -> V_131 = 0 ;
F_74 ( & V_88 -> V_132 ) ;
}
if ( V_96 && V_96 -> V_131 &&
V_96 -> V_10 -> V_138 == V_134 ) {
if ( V_96 -> V_10 -> remove ) {
V_76 = V_96 -> V_10 -> remove ( V_96 ) ;
if ( V_76 < 0 )
F_50 ( V_96 -> V_27 ,
L_33 ,
V_96 -> V_49 , V_76 ) ;
}
V_96 -> V_131 = 0 ;
F_74 ( & V_96 -> V_132 ) ;
if ( ! V_96 -> V_5 ) {
F_73 ( & V_96 -> V_54 ) ;
F_75 ( V_96 -> V_27 -> V_10 -> V_133 ) ;
}
}
}
static void F_79 ( struct V_62 * V_47 , int V_119 ,
int V_134 )
{
struct V_30 * V_31 = & V_47 -> V_31 [ V_119 ] ;
struct V_60 * V_96 = V_31 -> V_96 ;
struct V_60 * V_88 = V_31 -> V_88 ;
struct V_55 * V_56 = V_31 -> V_56 ;
struct V_4 * V_5 ;
if ( V_56 && V_56 -> V_131 &&
V_56 -> V_10 -> V_138 == V_134 ) {
F_72 ( V_56 ) ;
}
if ( V_88 ) {
V_5 = V_88 -> V_5 ;
if ( V_5 && V_5 -> V_131 &&
V_5 -> V_10 -> V_138 == V_134 )
F_76 ( V_5 ) ;
}
if ( V_96 ) {
V_5 = V_96 -> V_5 ;
if ( V_5 && V_5 -> V_131 &&
V_5 -> V_10 -> V_138 == V_134 )
F_76 ( V_5 ) ;
}
}
static void F_80 ( struct V_62 * V_47 )
{
int V_61 , V_134 ;
for ( V_134 = V_139 ; V_134 <= V_140 ;
V_134 ++ ) {
for ( V_61 = 0 ; V_61 < V_47 -> V_87 ; V_61 ++ )
F_77 ( V_47 , V_61 , V_134 ) ;
}
for ( V_134 = V_139 ; V_134 <= V_140 ;
V_134 ++ ) {
for ( V_61 = 0 ; V_61 < V_47 -> V_87 ; V_61 ++ )
F_79 ( V_47 , V_61 , V_134 ) ;
}
V_47 -> V_87 = 0 ;
}
static void F_81 ( struct V_62 * V_47 ,
struct V_4 * V_5 )
{
int V_3 ;
if ( V_47 -> V_141 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_47 -> V_142 ; V_3 ++ ) {
struct V_143 * V_144 = & V_47 -> V_141 [ V_3 ] ;
if ( V_144 -> F_71 && ! strcmp ( V_5 -> V_49 , V_144 -> F_71 ) ) {
V_5 -> V_145 = V_144 -> V_145 ;
break;
}
}
}
static int F_82 ( struct V_62 * V_47 ,
struct V_4 * V_5 )
{
int V_14 = 0 ;
const struct V_146 * V_10 = V_5 -> V_10 ;
struct V_60 * V_61 ;
V_5 -> V_47 = V_47 ;
V_5 -> V_54 . V_47 = V_47 ;
F_81 ( V_47 , V_5 ) ;
if ( ! F_83 ( V_5 -> V_27 -> V_10 -> V_133 ) )
return - V_147 ;
F_23 ( V_5 ) ;
if ( V_10 -> V_148 )
F_84 ( & V_5 -> V_54 , V_10 -> V_148 ,
V_10 -> V_149 ) ;
F_34 (dai, &codec->component.dai_list, list)
F_85 ( & V_5 -> V_54 , V_61 ) ;
V_5 -> V_54 . V_107 = V_10 -> V_107 ;
if ( ! V_5 -> V_150 && F_86 ( V_5 -> V_27 , NULL ) ) {
V_14 = F_87 ( V_5 , NULL ) ;
if ( V_14 < 0 ) {
F_50 ( V_5 -> V_27 ,
L_34 , V_14 ) ;
goto V_151;
}
}
if ( V_10 -> V_152 ) {
V_14 = V_10 -> V_152 ( V_5 ) ;
if ( V_14 < 0 ) {
F_50 ( V_5 -> V_27 ,
L_35 , V_14 ) ;
goto V_151;
}
F_88 ( V_5 -> V_54 . V_107 &&
V_5 -> V_54 . V_102 != V_108 ,
L_36 ,
V_5 -> V_49 ) ;
}
if ( V_10 -> V_153 )
F_89 ( V_5 , V_10 -> V_153 ,
V_10 -> V_154 ) ;
if ( V_10 -> V_155 )
F_90 ( & V_5 -> V_54 , V_10 -> V_155 ,
V_10 -> V_156 ) ;
V_5 -> V_131 = 1 ;
F_91 ( & V_5 -> V_132 , & V_47 -> V_84 ) ;
F_91 ( & V_5 -> V_54 . V_157 , & V_47 -> V_158 ) ;
return 0 ;
V_151:
F_29 ( V_5 ) ;
F_75 ( V_5 -> V_27 -> V_10 -> V_133 ) ;
return V_14 ;
}
static int F_92 ( struct V_62 * V_47 ,
struct V_55 * V_56 )
{
int V_14 = 0 ;
const struct V_159 * V_10 = V_56 -> V_10 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
V_56 -> V_47 = V_47 ;
V_56 -> V_54 . V_47 = V_47 ;
if ( ! F_83 ( V_56 -> V_27 -> V_10 -> V_133 ) )
return - V_147 ;
F_31 ( V_56 ) ;
if ( V_10 -> V_148 )
F_84 ( & V_56 -> V_54 ,
V_10 -> V_148 , V_10 -> V_149 ) ;
F_34 (component, &component_list, list) {
if ( V_59 -> V_27 != V_56 -> V_27 )
continue;
F_34 (dai, &component->dai_list, list)
F_85 ( & V_56 -> V_54 , V_61 ) ;
}
V_56 -> V_54 . V_107 = 1 ;
if ( V_10 -> V_152 ) {
V_14 = V_10 -> V_152 ( V_56 ) ;
if ( V_14 < 0 ) {
F_50 ( V_56 -> V_27 ,
L_37 , V_14 ) ;
goto V_151;
}
}
if ( V_10 -> V_153 )
F_93 ( V_56 , V_10 -> V_153 ,
V_10 -> V_154 ) ;
if ( V_10 -> V_155 )
F_90 ( & V_56 -> V_54 , V_10 -> V_155 ,
V_10 -> V_156 ) ;
V_56 -> V_131 = 1 ;
F_91 ( & V_56 -> V_132 , & V_47 -> V_160 ) ;
F_91 ( & V_56 -> V_54 . V_157 , & V_47 -> V_158 ) ;
return 0 ;
V_151:
F_32 ( V_56 ) ;
F_75 ( V_56 -> V_27 -> V_10 -> V_133 ) ;
return V_14 ;
}
static void F_94 ( struct V_26 * V_27 )
{
F_16 ( V_27 ) ;
}
static int F_95 ( struct V_62 * V_47 ,
struct V_4 * V_5 ,
int V_119 , int V_161 )
{
struct V_120 * V_67 = NULL ;
struct V_162 * V_163 = NULL ;
struct V_30 * V_31 ;
const char * V_49 ;
int V_14 = 0 ;
if ( ! V_161 ) {
V_67 = & V_47 -> V_67 [ V_119 ] ;
V_31 = & V_47 -> V_31 [ V_119 ] ;
V_49 = V_67 -> V_49 ;
} else {
V_163 = & V_47 -> V_163 [ V_119 ] ;
V_31 = & V_47 -> V_164 [ V_119 ] ;
V_49 = V_163 -> V_49 ;
}
V_31 -> V_47 = V_47 ;
if ( ! V_161 && V_67 -> V_165 )
V_14 = V_67 -> V_165 ( V_31 ) ;
else if ( V_161 && V_163 -> V_165 )
V_14 = V_163 -> V_165 ( & V_5 -> V_54 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 , L_38 , V_49 , V_14 ) ;
return V_14 ;
}
V_31 -> V_5 = V_5 ;
V_31 -> V_27 = F_96 ( sizeof( struct V_26 ) , V_37 ) ;
if ( ! V_31 -> V_27 )
return - V_38 ;
F_97 ( V_31 -> V_27 ) ;
V_31 -> V_27 -> V_78 = V_47 -> V_27 ;
V_31 -> V_27 -> V_79 = F_94 ;
V_31 -> V_27 -> V_166 = V_49 ;
F_98 ( V_31 -> V_27 , V_31 ) ;
F_99 ( & V_31 -> V_167 ) ;
F_100 ( & V_31 -> V_168 [ V_103 ] . V_169 ) ;
F_100 ( & V_31 -> V_168 [ V_105 ] . V_169 ) ;
F_100 ( & V_31 -> V_168 [ V_103 ] . V_170 ) ;
F_100 ( & V_31 -> V_168 [ V_105 ] . V_170 ) ;
V_14 = F_101 ( V_31 -> V_27 ) ;
if ( V_14 < 0 ) {
F_102 ( V_31 -> V_27 ) ;
F_50 ( V_47 -> V_27 ,
L_39 , V_14 ) ;
return V_14 ;
}
V_31 -> V_135 = 1 ;
V_14 = F_103 ( V_31 -> V_27 ) ;
if ( V_14 < 0 )
F_50 ( V_5 -> V_27 ,
L_40 , V_14 ) ;
V_14 = F_104 ( V_31 -> V_27 , & V_137 ) ;
if ( V_14 < 0 )
F_50 ( V_5 -> V_27 ,
L_41 , V_14 ) ;
#ifdef F_105
if ( ! V_161 && ! V_67 -> V_171 )
goto V_172;
V_14 = F_106 ( V_31 ) ;
if ( V_14 < 0 )
F_50 ( V_31 -> V_27 , L_42 , V_14 ) ;
V_172:
#endif
return 0 ;
}
static int F_107 ( struct V_62 * V_47 , int V_119 ,
int V_134 )
{
struct V_30 * V_31 = & V_47 -> V_31 [ V_119 ] ;
struct V_60 * V_96 = V_31 -> V_96 ;
struct V_60 * V_88 = V_31 -> V_88 ;
struct V_55 * V_56 = V_31 -> V_56 ;
int V_14 ;
if ( V_96 -> V_5 &&
! V_96 -> V_5 -> V_131 &&
V_96 -> V_5 -> V_10 -> V_173 == V_134 ) {
V_14 = F_82 ( V_47 , V_96 -> V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_88 -> V_5 -> V_131 &&
V_88 -> V_5 -> V_10 -> V_173 == V_134 ) {
V_14 = F_82 ( V_47 , V_88 -> V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_56 -> V_131 &&
V_56 -> V_10 -> V_173 == V_134 ) {
V_14 = F_92 ( V_47 , V_56 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
static int F_108 ( struct V_62 * V_47 , int V_119 , int V_134 )
{
struct V_120 * V_67 = & V_47 -> V_67 [ V_119 ] ;
struct V_30 * V_31 = & V_47 -> V_31 [ V_119 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
struct V_55 * V_56 = V_31 -> V_56 ;
struct V_60 * V_88 = V_31 -> V_88 ;
struct V_60 * V_96 = V_31 -> V_96 ;
struct V_174 * V_175 , * V_176 ;
int V_14 ;
F_42 ( V_47 -> V_27 , L_43 ,
V_47 -> V_49 , V_119 , V_134 ) ;
V_96 -> V_56 = V_56 ;
V_88 -> V_47 = V_47 ;
V_96 -> V_47 = V_47 ;
V_31 -> V_32 = V_32 ;
if ( ! V_96 -> V_131 &&
V_96 -> V_10 -> V_173 == V_134 ) {
if ( ! V_96 -> V_5 ) {
V_96 -> V_54 . V_47 = V_47 ;
if ( ! F_83 ( V_96 -> V_27 -> V_10 -> V_133 ) )
return - V_147 ;
F_91 ( & V_96 -> V_54 . V_157 , & V_47 -> V_158 ) ;
}
if ( V_96 -> V_10 -> V_152 ) {
V_14 = V_96 -> V_10 -> V_152 ( V_96 ) ;
if ( V_14 < 0 ) {
F_50 ( V_96 -> V_27 ,
L_44 ,
V_96 -> V_49 , V_14 ) ;
F_75 ( V_96 -> V_27 -> V_10 -> V_133 ) ;
return V_14 ;
}
}
V_96 -> V_131 = 1 ;
F_91 ( & V_96 -> V_132 , & V_47 -> V_177 ) ;
}
if ( ! V_88 -> V_131 && V_88 -> V_10 -> V_173 == V_134 ) {
if ( V_88 -> V_10 -> V_152 ) {
V_14 = V_88 -> V_10 -> V_152 ( V_88 ) ;
if ( V_14 < 0 ) {
F_50 ( V_88 -> V_27 ,
L_45 ,
V_88 -> V_49 , V_14 ) ;
return V_14 ;
}
}
V_88 -> V_131 = 1 ;
F_91 ( & V_88 -> V_132 , & V_47 -> V_177 ) ;
}
if ( V_134 != V_140 )
return 0 ;
V_14 = F_95 ( V_47 , V_5 , V_119 , 0 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_104 ( V_31 -> V_27 , & V_136 ) ;
if ( V_14 < 0 )
F_25 ( V_31 -> V_27 , L_46 ,
V_14 ) ;
if ( V_96 -> V_10 -> V_178 ) {
V_14 = F_109 ( V_31 , V_119 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 , L_47 ,
V_67 -> V_179 ) ;
return V_14 ;
}
} else {
if ( ! V_67 -> V_180 ) {
V_14 = F_110 ( V_31 , V_119 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 , L_48 ,
V_67 -> V_179 , V_14 ) ;
return V_14 ;
}
} else {
F_111 ( & V_31 -> V_100 ,
F_51 ) ;
V_175 = V_88 -> V_181 ;
V_176 = V_96 -> V_182 ;
if ( V_175 && V_176 ) {
V_14 = F_112 ( V_47 , V_67 -> V_180 ,
V_176 , V_175 ) ;
if ( V_14 != 0 ) {
F_50 ( V_47 -> V_27 , L_49 ,
V_175 -> V_49 , V_176 -> V_49 , V_14 ) ;
return V_14 ;
}
}
V_175 = V_96 -> V_181 ;
V_176 = V_88 -> V_182 ;
if ( V_175 && V_176 ) {
V_14 = F_112 ( V_47 , V_67 -> V_180 ,
V_176 , V_175 ) ;
if ( V_14 != 0 ) {
F_50 ( V_47 -> V_27 , L_49 ,
V_175 -> V_49 , V_176 -> V_49 , V_14 ) ;
return V_14 ;
}
}
}
}
if ( V_31 -> V_88 -> V_10 -> V_98 )
F_113 ( V_5 -> V_74 , V_31 -> V_96 -> V_183 ) ;
return 0 ;
}
static int F_114 ( struct V_30 * V_31 )
{
int V_14 ;
if ( V_31 -> V_88 -> V_10 -> V_98 && ! V_31 -> V_5 -> V_184 ) {
if ( ! V_31 -> V_5 -> V_185 )
return 0 ;
V_14 = F_47 ( V_31 -> V_5 ) ;
if ( V_14 < 0 ) {
F_50 ( V_31 -> V_5 -> V_27 ,
L_50 , V_14 ) ;
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
static int F_116 ( struct V_62 * V_47 , int V_119 )
{
struct V_162 * V_163 = & V_47 -> V_163 [ V_119 ] ;
struct V_4 * V_5 ;
F_34 (codec, &codec_list, list) {
if ( ! strcmp ( V_5 -> V_49 , V_163 -> V_128 ) )
return 0 ;
}
F_50 ( V_47 -> V_27 , L_51 , V_163 -> V_128 ) ;
return - V_126 ;
}
static int F_117 ( struct V_62 * V_47 , int V_119 )
{
struct V_162 * V_163 = & V_47 -> V_163 [ V_119 ] ;
struct V_4 * V_5 ;
int V_14 = - V_147 ;
F_34 (codec, &codec_list, list) {
if ( ! strcmp ( V_5 -> V_49 , V_163 -> V_128 ) ) {
if ( V_5 -> V_131 ) {
F_50 ( V_5 -> V_27 ,
L_52 ) ;
V_14 = - V_186 ;
goto V_172;
}
goto V_187;
}
}
F_50 ( V_47 -> V_27 , L_53 , V_163 -> V_128 ) ;
return - V_126 ;
V_187:
V_14 = F_82 ( V_47 , V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_95 ( V_47 , V_5 , V_119 , 1 ) ;
V_172:
return V_14 ;
}
static void F_118 ( struct V_62 * V_47 , int V_119 )
{
struct V_30 * V_31 = & V_47 -> V_164 [ V_119 ] ;
struct V_4 * V_5 = V_31 -> V_5 ;
if ( V_31 -> V_135 ) {
F_78 ( V_31 -> V_27 , & V_137 ) ;
F_45 ( V_31 -> V_27 ) ;
V_31 -> V_135 = 0 ;
}
if ( V_5 && V_5 -> V_131 )
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
L_54 ,
V_14 ) ;
return V_14 ;
}
V_5 -> V_188 = 1 ;
return 0 ;
}
static int F_121 ( struct V_62 * V_47 )
{
struct V_4 * V_5 ;
struct V_120 * V_67 ;
int V_14 , V_3 , V_134 , V_189 ;
F_122 ( & V_47 -> V_190 , V_191 ) ;
for ( V_3 = 0 ; V_3 < V_47 -> V_69 ; V_3 ++ ) {
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
V_14 = F_123 ( V_47 -> V_27 , V_194 , V_195 ,
V_47 -> V_133 , 0 , & V_47 -> V_80 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 ,
L_55 ,
V_47 -> V_49 , V_14 ) ;
goto V_192;
}
V_47 -> V_54 . V_102 = V_108 ;
V_47 -> V_54 . V_27 = V_47 -> V_27 ;
V_47 -> V_54 . V_47 = V_47 ;
F_91 ( & V_47 -> V_54 . V_157 , & V_47 -> V_158 ) ;
#ifdef F_105
F_28 ( & V_47 -> V_54 , V_47 -> V_46 ) ;
#endif
#ifdef F_124
F_125 ( & V_47 -> V_112 , F_65 ) ;
#endif
if ( V_47 -> V_148 )
F_84 ( & V_47 -> V_54 , V_47 -> V_148 ,
V_47 -> V_149 ) ;
if ( V_47 -> V_152 ) {
V_14 = V_47 -> V_152 ( V_47 ) ;
if ( V_14 < 0 )
goto V_196;
}
for ( V_134 = V_139 ; V_134 <= V_140 ;
V_134 ++ ) {
for ( V_3 = 0 ; V_3 < V_47 -> V_69 ; V_3 ++ ) {
V_14 = F_107 ( V_47 , V_3 , V_134 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 ,
L_56 ,
V_14 ) ;
goto V_197;
}
}
}
for ( V_134 = V_139 ; V_134 <= V_140 ;
V_134 ++ ) {
for ( V_3 = 0 ; V_3 < V_47 -> V_69 ; V_3 ++ ) {
V_14 = F_108 ( V_47 , V_3 , V_134 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 ,
L_56 ,
V_14 ) ;
goto V_197;
}
}
}
for ( V_3 = 0 ; V_3 < V_47 -> V_193 ; V_3 ++ ) {
V_14 = F_117 ( V_47 , V_3 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 ,
L_57 ,
V_14 ) ;
goto V_198;
}
}
F_126 ( V_47 ) ;
F_127 ( V_47 ) ;
if ( V_47 -> V_153 )
F_128 ( V_47 , V_47 -> V_153 , V_47 -> V_154 ) ;
if ( V_47 -> V_155 )
F_90 ( & V_47 -> V_54 , V_47 -> V_155 ,
V_47 -> V_156 ) ;
for ( V_3 = 0 ; V_3 < V_47 -> V_69 ; V_3 ++ ) {
V_67 = & V_47 -> V_67 [ V_3 ] ;
V_189 = V_67 -> V_189 ;
if ( V_189 ) {
V_14 = F_129 ( V_47 -> V_31 [ V_3 ] . V_88 ,
V_189 ) ;
if ( V_14 != 0 && V_14 != - V_199 )
F_25 ( V_47 -> V_31 [ V_3 ] . V_88 -> V_27 ,
L_58 ,
V_14 ) ;
}
if ( V_189 &&
( V_67 -> V_121 || V_67 -> V_130 ) ) {
V_14 = F_129 ( V_47 -> V_31 [ V_3 ] . V_96 ,
V_189 ) ;
if ( V_14 != 0 && V_14 != - V_199 )
F_25 ( V_47 -> V_31 [ V_3 ] . V_96 -> V_27 ,
L_58 ,
V_14 ) ;
} else if ( V_189 ) {
V_189 &= ~ V_200 ;
switch ( V_67 -> V_189 &
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
V_14 = F_129 ( V_47 -> V_31 [ V_3 ] . V_96 ,
V_189 ) ;
if ( V_14 != 0 && V_14 != - V_199 )
F_25 ( V_47 -> V_31 [ V_3 ] . V_96 -> V_27 ,
L_58 ,
V_14 ) ;
}
}
snprintf ( V_47 -> V_80 -> V_205 , sizeof( V_47 -> V_80 -> V_205 ) ,
L_59 , V_47 -> V_49 ) ;
snprintf ( V_47 -> V_80 -> V_206 , sizeof( V_47 -> V_80 -> V_206 ) ,
L_59 , V_47 -> V_207 ? V_47 -> V_207 : V_47 -> V_49 ) ;
snprintf ( V_47 -> V_80 -> V_10 , sizeof( V_47 -> V_80 -> V_10 ) ,
L_59 , V_47 -> V_208 ? V_47 -> V_208 : V_47 -> V_49 ) ;
for ( V_3 = 0 ; V_3 < F_130 ( V_47 -> V_80 -> V_10 ) ; V_3 ++ ) {
switch ( V_47 -> V_80 -> V_10 [ V_3 ] ) {
case '_' :
case '-' :
case '\0' :
break;
default:
if ( ! isalnum ( V_47 -> V_80 -> V_10 [ V_3 ] ) )
V_47 -> V_80 -> V_10 [ V_3 ] = '_' ;
break;
}
}
if ( V_47 -> V_209 ) {
V_14 = V_47 -> V_209 ( V_47 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 , L_60 ,
V_47 -> V_49 , V_14 ) ;
goto V_198;
}
}
if ( V_47 -> V_210 )
F_34 (codec, &card->codec_dev_list, card_list)
F_131 ( V_5 ) ;
F_132 ( V_47 ) ;
V_14 = F_133 ( V_47 -> V_80 ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 , L_61 ,
V_14 ) ;
goto V_198;
}
#ifdef F_134
for ( V_3 = 0 ; V_3 < V_47 -> V_87 ; V_3 ++ ) {
V_14 = F_114 ( & V_47 -> V_31 [ V_3 ] ) ;
if ( V_14 < 0 ) {
F_50 ( V_47 -> V_27 ,
L_62 , V_14 ) ;
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
F_136 ( V_47 -> V_80 ) ;
V_192:
F_135 ( & V_47 -> V_190 ) ;
return V_14 ;
}
static int F_137 ( struct V_212 * V_213 )
{
struct V_62 * V_47 = F_138 ( V_213 ) ;
if ( ! V_47 )
return - V_17 ;
F_25 ( & V_213 -> V_27 ,
L_63 ,
V_47 -> V_49 ) ;
V_47 -> V_27 = & V_213 -> V_27 ;
return F_139 ( V_47 ) ;
}
static int F_140 ( struct V_62 * V_47 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_47 -> V_87 ; V_3 ++ ) {
struct V_30 * V_31 = & V_47 -> V_31 [ V_3 ] ;
F_59 ( & V_31 -> V_100 ) ;
}
for ( V_3 = 0 ; V_3 < V_47 -> V_193 ; V_3 ++ )
F_118 ( V_47 , V_3 ) ;
F_80 ( V_47 ) ;
F_40 ( V_47 ) ;
if ( V_47 -> remove )
V_47 -> remove ( V_47 ) ;
F_73 ( & V_47 -> V_54 ) ;
F_136 ( V_47 -> V_80 ) ;
return 0 ;
}
static int F_141 ( struct V_212 * V_213 )
{
struct V_62 * V_47 = F_138 ( V_213 ) ;
F_142 ( V_47 ) ;
return 0 ;
}
int F_143 ( struct V_26 * V_27 )
{
struct V_62 * V_47 = F_9 ( V_27 ) ;
int V_3 ;
if ( ! V_47 -> V_211 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_47 -> V_87 ; V_3 ++ ) {
struct V_30 * V_31 = & V_47 -> V_31 [ V_3 ] ;
F_59 ( & V_31 -> V_100 ) ;
}
F_144 ( V_47 ) ;
for ( V_3 = 0 ; V_3 < V_47 -> V_87 ; V_3 ++ ) {
struct V_60 * V_96 = V_47 -> V_31 [ V_3 ] . V_96 ;
struct V_60 * V_88 = V_47 -> V_31 [ V_3 ] . V_88 ;
F_64 ( V_88 -> V_27 ) ;
F_64 ( V_96 -> V_27 ) ;
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
F_50 ( V_56 -> V_27 , L_64 ) ;
return - 1 ;
}
V_14 = V_56 -> V_10 -> V_217 ( V_56 , V_6 ) ;
F_42 ( V_56 -> V_27 , L_65 , V_6 , V_14 ) ;
F_148 ( V_56 , V_6 , V_14 ) ;
return V_14 ;
}
int F_149 ( struct V_55 * V_56 ,
unsigned int V_6 , unsigned int V_1 )
{
if ( ! V_56 -> V_10 -> V_150 ) {
F_50 ( V_56 -> V_27 , L_66 ) ;
return - 1 ;
}
F_42 ( V_56 -> V_27 , L_67 , V_6 , V_1 ) ;
F_150 ( V_56 , V_6 , V_1 ) ;
return V_56 -> V_10 -> V_150 ( V_56 , V_6 , V_1 ) ;
}
int F_151 ( struct V_4 * V_5 ,
struct V_218 * V_92 , int V_119 )
{
F_152 ( & V_5 -> V_190 ) ;
V_5 -> V_74 = F_96 ( sizeof( struct V_219 ) , V_37 ) ;
if ( V_5 -> V_74 == NULL ) {
F_135 ( & V_5 -> V_190 ) ;
return - V_38 ;
}
V_5 -> V_74 -> V_75 = F_96 ( sizeof( struct V_220 ) , V_37 ) ;
if ( V_5 -> V_74 -> V_75 == NULL ) {
F_16 ( V_5 -> V_74 ) ;
V_5 -> V_74 = NULL ;
F_135 ( & V_5 -> V_190 ) ;
return - V_38 ;
}
V_5 -> V_74 -> V_75 -> V_92 = V_92 ;
V_5 -> V_74 -> V_119 = V_119 ;
V_5 -> V_185 = 1 ;
F_135 ( & V_5 -> V_190 ) ;
return 0 ;
}
static void F_153 ( struct V_219 * V_74 )
{
struct V_221 * V_222 = V_223 . V_222 ;
F_154 ( V_222 , V_223 . V_224 ) ;
F_155 ( V_223 . V_225 , 1 ) ;
F_156 ( 10 ) ;
F_155 ( V_223 . V_225 , 0 ) ;
F_154 ( V_222 , V_223 . V_226 ) ;
F_157 ( 2 ) ;
}
static void F_158 ( struct V_219 * V_74 )
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
F_50 ( V_27 , L_68 ) ;
return F_162 ( V_22 ) ;
}
V_231 -> V_222 = V_22 ;
V_233 = F_163 ( V_22 , L_69 ) ;
if ( F_161 ( V_233 ) ) {
F_50 ( V_27 , L_70 ) ;
return F_162 ( V_233 ) ;
}
V_231 -> V_227 = V_233 ;
V_233 = F_163 ( V_22 , L_71 ) ;
if ( F_161 ( V_233 ) ) {
F_50 ( V_27 , L_72 ) ;
return F_162 ( V_233 ) ;
}
V_231 -> V_224 = V_233 ;
V_233 = F_163 ( V_22 , L_73 ) ;
if ( F_161 ( V_233 ) ) {
F_50 ( V_27 , L_74 ) ;
return F_162 ( V_233 ) ;
}
V_231 -> V_226 = V_233 ;
V_234 = F_164 ( V_27 -> V_123 , L_75 , 0 ) ;
if ( V_234 < 0 ) {
F_50 ( V_27 , L_76 ) ;
return V_234 ;
}
V_14 = F_165 ( V_27 , V_234 , L_77 ) ;
if ( V_14 ) {
F_50 ( V_27 , L_78 ) ;
return V_14 ;
}
V_231 -> V_225 = V_234 ;
V_234 = F_164 ( V_27 -> V_123 , L_75 , 1 ) ;
if ( V_234 < 0 ) {
F_50 ( V_27 , L_79 , V_234 ) ;
return V_234 ;
}
V_14 = F_165 ( V_27 , V_234 , L_80 ) ;
if ( V_14 ) {
F_50 ( V_27 , L_81 ) ;
return V_14 ;
}
V_231 -> V_228 = V_234 ;
V_234 = F_164 ( V_27 -> V_123 , L_75 , 2 ) ;
if ( V_234 < 0 ) {
F_50 ( V_27 , L_82 ) ;
return V_234 ;
}
V_14 = F_165 ( V_27 , V_234 , L_83 ) ;
if ( V_14 ) {
F_50 ( V_27 , L_84 ) ;
return V_14 ;
}
V_231 -> V_229 = V_234 ;
return 0 ;
}
int F_166 ( struct V_218 * V_92 )
{
if ( V_92 == V_235 )
return 0 ;
if ( V_235 && V_92 )
return - V_186 ;
V_235 = V_92 ;
return 0 ;
}
int F_167 ( struct V_218 * V_92 ,
struct V_212 * V_213 )
{
struct V_26 * V_27 = & V_213 -> V_27 ;
struct V_230 V_231 ;
int V_14 ;
V_14 = F_159 ( V_27 , & V_231 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_166 ( V_92 ) ;
if ( V_14 )
return V_14 ;
V_92 -> V_236 = F_153 ;
V_92 -> V_237 = F_158 ;
V_223 = V_231 ;
return 0 ;
}
void F_168 ( struct V_4 * V_5 )
{
F_152 ( & V_5 -> V_190 ) ;
#ifdef F_134
F_115 ( V_5 ) ;
#endif
F_16 ( V_5 -> V_74 -> V_75 ) ;
F_16 ( V_5 -> V_74 ) ;
V_5 -> V_74 = NULL ;
V_5 -> V_185 = 0 ;
F_135 ( & V_5 -> V_190 ) ;
}
unsigned int F_4 ( struct V_4 * V_5 , unsigned int V_6 )
{
unsigned int V_14 ;
V_14 = V_5 -> V_217 ( V_5 , V_6 ) ;
F_42 ( V_5 -> V_27 , L_65 , V_6 , V_14 ) ;
F_169 ( V_5 , V_6 , V_14 ) ;
return V_14 ;
}
unsigned int F_22 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned int V_1 )
{
F_42 ( V_5 -> V_27 , L_67 , V_6 , V_1 ) ;
F_170 ( V_5 , V_6 , V_1 ) ;
return V_5 -> V_150 ( V_5 , V_6 , V_1 ) ;
}
int F_171 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_238 , unsigned int V_42 )
{
bool V_239 ;
unsigned int V_240 , V_241 ;
int V_14 ;
if ( V_5 -> V_109 ) {
V_14 = F_172 ( V_5 -> V_110 , V_6 ,
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
V_49 = F_176 ( V_37 , L_85 , V_246 , V_207 ) ;
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
static int F_178 ( struct V_80 * V_47 , struct V_26 * V_27 ,
const struct V_243 * V_153 , int V_154 ,
const char * V_246 , void * V_245 )
{
int V_76 , V_3 ;
for ( V_3 = 0 ; V_3 < V_154 ; V_3 ++ ) {
const struct V_243 * V_250 = & V_153 [ V_3 ] ;
V_76 = F_179 ( V_47 , F_175 ( V_250 , V_245 ,
V_250 -> V_49 , V_246 ) ) ;
if ( V_76 < 0 ) {
F_50 ( V_27 , L_86 ,
V_250 -> V_49 , V_76 ) ;
return V_76 ;
}
}
return 0 ;
}
struct V_242 * F_180 ( struct V_62 * V_251 ,
const char * V_49 )
{
struct V_80 * V_47 = V_251 -> V_80 ;
struct V_242 * V_252 ;
if ( F_181 ( ! V_49 ) )
return NULL ;
F_34 (kctl, &card->controls, list)
if ( ! strncmp ( V_252 -> V_253 . V_49 , V_49 , sizeof( V_252 -> V_253 . V_49 ) ) )
return V_252 ;
return NULL ;
}
int F_89 ( struct V_4 * V_5 ,
const struct V_243 * V_153 , int V_154 )
{
struct V_80 * V_47 = V_5 -> V_47 -> V_80 ;
return F_178 ( V_47 , V_5 -> V_27 , V_153 , V_154 ,
V_5 -> V_145 , V_5 ) ;
}
int F_93 ( struct V_55 * V_56 ,
const struct V_243 * V_153 , int V_154 )
{
struct V_80 * V_47 = V_56 -> V_47 -> V_80 ;
return F_178 ( V_47 , V_56 -> V_27 , V_153 , V_154 ,
NULL , V_56 ) ;
}
int F_128 ( struct V_62 * V_251 ,
const struct V_243 * V_153 , int V_154 )
{
struct V_80 * V_47 = V_251 -> V_80 ;
return F_178 ( V_47 , V_251 -> V_27 , V_153 , V_154 ,
NULL , V_251 ) ;
}
int F_182 ( struct V_60 * V_61 ,
const struct V_243 * V_153 , int V_154 )
{
struct V_80 * V_47 = V_61 -> V_47 -> V_80 ;
return F_178 ( V_47 , V_61 -> V_27 , V_153 , V_154 ,
NULL , V_61 ) ;
}
int F_183 ( struct V_242 * V_248 ,
struct V_254 * V_255 )
{
struct V_256 * V_257 = (struct V_256 * ) V_248 -> V_258 ;
V_255 -> type = V_259 ;
V_255 -> V_18 = V_257 -> V_260 == V_257 -> V_261 ? 1 : 2 ;
V_255 -> V_42 . V_262 . V_263 = V_257 -> V_263 ;
if ( V_255 -> V_42 . V_262 . V_264 >= V_257 -> V_263 )
V_255 -> V_42 . V_262 . V_264 = V_257 -> V_263 - 1 ;
F_184 ( V_255 -> V_42 . V_262 . V_49 ,
V_257 -> V_265 [ V_255 -> V_42 . V_262 . V_264 ] ,
sizeof( V_255 -> V_42 . V_262 . V_49 ) ) ;
return 0 ;
}
int F_185 ( struct V_242 * V_248 ,
struct V_266 * V_267 )
{
struct V_4 * V_5 = F_186 ( V_248 ) ;
struct V_256 * V_257 = (struct V_256 * ) V_248 -> V_258 ;
unsigned int V_1 , V_264 ;
unsigned int V_268 ;
V_268 = F_4 ( V_5 , V_257 -> V_6 ) ;
V_1 = ( V_268 >> V_257 -> V_260 ) & V_257 -> V_238 ;
V_264 = F_187 ( V_257 , V_1 ) ;
V_267 -> V_42 . V_262 . V_264 [ 0 ] = V_264 ;
if ( V_257 -> V_260 != V_257 -> V_261 ) {
V_1 = ( V_268 >> V_257 -> V_260 ) & V_257 -> V_238 ;
V_264 = F_187 ( V_257 , V_1 ) ;
V_267 -> V_42 . V_262 . V_264 [ 1 ] = V_264 ;
}
return 0 ;
}
int F_188 ( struct V_242 * V_248 ,
struct V_266 * V_267 )
{
struct V_4 * V_5 = F_186 ( V_248 ) ;
struct V_256 * V_257 = (struct V_256 * ) V_248 -> V_258 ;
unsigned int * V_264 = V_267 -> V_42 . V_262 . V_264 ;
unsigned int V_1 ;
unsigned int V_238 ;
if ( V_264 [ 0 ] >= V_257 -> V_263 )
return - V_17 ;
V_1 = F_189 ( V_257 , V_264 [ 0 ] ) << V_257 -> V_260 ;
V_238 = V_257 -> V_238 << V_257 -> V_260 ;
if ( V_257 -> V_260 != V_257 -> V_261 ) {
if ( V_264 [ 1 ] >= V_257 -> V_263 )
return - V_17 ;
V_1 |= F_189 ( V_257 , V_264 [ 1 ] ) << V_257 -> V_261 ;
V_238 |= V_257 -> V_238 << V_257 -> V_261 ;
}
return F_173 ( V_5 , V_257 -> V_6 , V_238 , V_1 ) ;
}
static int F_190 ( struct V_4 * V_5 , unsigned int V_6 ,
unsigned int V_238 , unsigned int V_269 , unsigned int V_270 )
{
int V_14 ;
unsigned int V_1 ;
V_1 = ( F_4 ( V_5 , V_6 ) >> V_269 ) & V_238 ;
if ( ! V_270 )
return V_1 ;
if ( ! ( V_1 & F_191 ( V_270 ) ) )
return V_1 ;
V_14 = V_1 ;
V_14 |= ~ ( ( int ) ( F_191 ( V_270 ) - 1 ) ) ;
return V_14 ;
}
int F_192 ( struct V_242 * V_248 ,
struct V_254 * V_255 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_248 -> V_258 ;
int V_273 ;
if ( ! V_272 -> V_273 )
V_272 -> V_273 = V_272 -> V_274 ;
V_273 = V_272 -> V_273 ;
if ( V_273 == 1 && ! strstr ( V_248 -> V_253 . V_49 , L_87 ) )
V_255 -> type = V_275 ;
else
V_255 -> type = V_276 ;
V_255 -> V_18 = F_193 ( V_272 ) ? 2 : 1 ;
V_255 -> V_42 . integer . F_7 = 0 ;
V_255 -> V_42 . integer . V_274 = V_273 - V_272 -> F_7 ;
return 0 ;
}
int F_194 ( struct V_242 * V_248 ,
struct V_266 * V_267 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_248 -> V_258 ;
struct V_4 * V_5 = F_186 ( V_248 ) ;
unsigned int V_6 = V_272 -> V_6 ;
unsigned int V_277 = V_272 -> V_278 ;
unsigned int V_269 = V_272 -> V_269 ;
unsigned int V_279 = V_272 -> V_279 ;
int V_274 = V_272 -> V_274 ;
int F_7 = V_272 -> F_7 ;
int V_270 = V_272 -> V_270 ;
unsigned int V_238 = ( 1 << F_195 ( V_274 ) ) - 1 ;
unsigned int V_280 = V_272 -> V_280 ;
if ( V_270 )
V_238 = F_191 ( V_270 + 1 ) - 1 ;
V_267 -> V_42 . integer . V_42 [ 0 ] = F_190 ( V_5 , V_6 , V_238 ,
V_269 , V_270 ) - F_7 ;
if ( V_280 )
V_267 -> V_42 . integer . V_42 [ 0 ] =
V_274 - V_267 -> V_42 . integer . V_42 [ 0 ] ;
if ( F_193 ( V_272 ) ) {
if ( V_6 == V_277 )
V_267 -> V_42 . integer . V_42 [ 1 ] =
F_190 ( V_5 , V_6 , V_238 , V_279 ,
V_270 ) - F_7 ;
else
V_267 -> V_42 . integer . V_42 [ 1 ] =
F_190 ( V_5 , V_277 , V_238 , V_269 ,
V_270 ) - F_7 ;
if ( V_280 )
V_267 -> V_42 . integer . V_42 [ 1 ] =
V_274 - V_267 -> V_42 . integer . V_42 [ 1 ] ;
}
return 0 ;
}
int F_196 ( struct V_242 * V_248 ,
struct V_266 * V_267 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_248 -> V_258 ;
struct V_4 * V_5 = F_186 ( V_248 ) ;
unsigned int V_6 = V_272 -> V_6 ;
unsigned int V_277 = V_272 -> V_278 ;
unsigned int V_269 = V_272 -> V_269 ;
unsigned int V_279 = V_272 -> V_279 ;
int V_274 = V_272 -> V_274 ;
int F_7 = V_272 -> F_7 ;
unsigned int V_270 = V_272 -> V_270 ;
unsigned int V_238 = ( 1 << F_195 ( V_274 ) ) - 1 ;
unsigned int V_280 = V_272 -> V_280 ;
int V_76 ;
bool V_281 = false ;
unsigned int V_282 = 0 ;
unsigned int V_1 , V_283 ;
if ( V_270 )
V_238 = F_191 ( V_270 + 1 ) - 1 ;
V_1 = ( ( V_267 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & V_238 ) ;
if ( V_280 )
V_1 = V_274 - V_1 ;
V_283 = V_238 << V_269 ;
V_1 = V_1 << V_269 ;
if ( F_193 ( V_272 ) ) {
V_282 = ( ( V_267 -> V_42 . integer . V_42 [ 1 ] + F_7 ) & V_238 ) ;
if ( V_280 )
V_282 = V_274 - V_282 ;
if ( V_6 == V_277 ) {
V_283 |= V_238 << V_279 ;
V_1 |= V_282 << V_279 ;
} else {
V_282 = V_282 << V_269 ;
V_281 = true ;
}
}
V_76 = F_173 ( V_5 , V_6 , V_283 , V_1 ) ;
if ( V_76 < 0 )
return V_76 ;
if ( V_281 )
V_76 = F_173 ( V_5 , V_277 , V_283 , V_282 ) ;
return V_76 ;
}
int F_197 ( struct V_242 * V_248 ,
struct V_266 * V_267 )
{
struct V_4 * V_5 = F_186 ( V_248 ) ;
struct V_271 * V_272 =
(struct V_271 * ) V_248 -> V_258 ;
unsigned int V_6 = V_272 -> V_6 ;
unsigned int V_277 = V_272 -> V_278 ;
unsigned int V_269 = V_272 -> V_269 ;
unsigned int V_279 = V_272 -> V_279 ;
int V_274 = V_272 -> V_274 ;
int F_7 = V_272 -> F_7 ;
int V_238 = ( 1 << ( F_195 ( F_7 + V_274 ) - 1 ) ) - 1 ;
V_267 -> V_42 . integer . V_42 [ 0 ] =
( ( F_4 ( V_5 , V_6 ) >> V_269 ) - F_7 ) & V_238 ;
if ( F_193 ( V_272 ) )
V_267 -> V_42 . integer . V_42 [ 1 ] =
( ( F_4 ( V_5 , V_277 ) >> V_279 ) - F_7 ) & V_238 ;
return 0 ;
}
int F_198 ( struct V_242 * V_248 ,
struct V_266 * V_267 )
{
struct V_4 * V_5 = F_186 ( V_248 ) ;
struct V_271 * V_272 =
(struct V_271 * ) V_248 -> V_258 ;
unsigned int V_6 = V_272 -> V_6 ;
unsigned int V_277 = V_272 -> V_278 ;
unsigned int V_269 = V_272 -> V_269 ;
unsigned int V_279 = V_272 -> V_279 ;
int V_274 = V_272 -> V_274 ;
int F_7 = V_272 -> F_7 ;
int V_238 = ( 1 << ( F_195 ( F_7 + V_274 ) - 1 ) ) - 1 ;
int V_76 = 0 ;
unsigned short V_1 , V_283 , V_282 = 0 ;
V_283 = V_238 << V_269 ;
V_1 = ( V_267 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & V_238 ;
V_1 = V_1 << V_269 ;
V_76 = F_173 ( V_5 , V_6 , V_283 , V_1 ) ;
if ( V_76 < 0 )
return V_76 ;
if ( F_193 ( V_272 ) ) {
V_283 = V_238 << V_279 ;
V_282 = ( V_267 -> V_42 . integer . V_42 [ 1 ] + F_7 ) & V_238 ;
V_282 = V_282 << V_279 ;
if ( F_173 ( V_5 , V_277 , V_283 , V_282 ) )
return V_76 ;
}
return 0 ;
}
int F_199 ( struct V_242 * V_248 ,
struct V_254 * V_255 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_248 -> V_258 ;
int V_273 ;
int F_7 = V_272 -> F_7 ;
if ( ! V_272 -> V_273 )
V_272 -> V_273 = V_272 -> V_274 ;
V_273 = V_272 -> V_273 ;
V_255 -> type = V_276 ;
V_255 -> V_18 = 2 ;
V_255 -> V_42 . integer . F_7 = 0 ;
V_255 -> V_42 . integer . V_274 = V_273 - F_7 ;
return 0 ;
}
int F_200 ( struct V_242 * V_248 ,
struct V_266 * V_267 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_248 -> V_258 ;
struct V_4 * V_5 = F_186 ( V_248 ) ;
unsigned int V_6 = V_272 -> V_6 ;
int F_7 = V_272 -> F_7 ;
int V_1 = F_4 ( V_5 , V_6 ) ;
V_267 -> V_42 . integer . V_42 [ 0 ] =
( ( signed char ) ( V_1 & 0xff ) ) - F_7 ;
V_267 -> V_42 . integer . V_42 [ 1 ] =
( ( signed char ) ( ( V_1 >> 8 ) & 0xff ) ) - F_7 ;
return 0 ;
}
int F_201 ( struct V_242 * V_248 ,
struct V_266 * V_267 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_248 -> V_258 ;
struct V_4 * V_5 = F_186 ( V_248 ) ;
unsigned int V_6 = V_272 -> V_6 ;
int F_7 = V_272 -> F_7 ;
unsigned int V_1 ;
V_1 = ( V_267 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & 0xff ;
V_1 |= ( ( V_267 -> V_42 . integer . V_42 [ 1 ] + F_7 ) & 0xff ) << 8 ;
return F_173 ( V_5 , V_6 , 0xffff , V_1 ) ;
}
int F_202 ( struct V_242 * V_248 ,
struct V_254 * V_255 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_248 -> V_258 ;
int V_273 ;
int F_7 = V_272 -> F_7 ;
if ( ! V_272 -> V_273 )
V_272 -> V_273 = V_272 -> V_274 ;
V_273 = V_272 -> V_273 ;
V_255 -> type = V_276 ;
V_255 -> V_18 = F_193 ( V_272 ) ? 2 : 1 ;
V_255 -> V_42 . integer . F_7 = 0 ;
V_255 -> V_42 . integer . V_274 = V_273 - F_7 ;
return 0 ;
}
int F_203 ( struct V_242 * V_248 ,
struct V_266 * V_267 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_248 -> V_258 ;
struct V_4 * V_5 = F_186 ( V_248 ) ;
unsigned int V_6 = V_272 -> V_6 ;
unsigned int V_278 = V_272 -> V_278 ;
unsigned int V_269 = V_272 -> V_269 ;
int F_7 = V_272 -> F_7 ;
int V_274 = V_272 -> V_274 ;
unsigned int V_238 = ( 1 << F_195 ( V_274 ) ) - 1 ;
unsigned int V_280 = V_272 -> V_280 ;
unsigned int V_1 , V_283 ;
int V_14 ;
V_1 = ( ( V_267 -> V_42 . integer . V_42 [ 0 ] + F_7 ) & V_238 ) ;
if ( V_280 )
V_1 = V_274 - V_1 ;
V_283 = V_238 << V_269 ;
V_1 = V_1 << V_269 ;
V_14 = F_173 ( V_5 , V_6 , V_283 , V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( F_193 ( V_272 ) ) {
V_1 = ( ( V_267 -> V_42 . integer . V_42 [ 1 ] + F_7 ) & V_238 ) ;
if ( V_280 )
V_1 = V_274 - V_1 ;
V_283 = V_238 << V_269 ;
V_1 = V_1 << V_269 ;
V_14 = F_173 ( V_5 , V_278 , V_283 , V_1 ) ;
}
return V_14 ;
}
int F_204 ( struct V_242 * V_248 ,
struct V_266 * V_267 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_248 -> V_258 ;
struct V_4 * V_5 = F_186 ( V_248 ) ;
unsigned int V_6 = V_272 -> V_6 ;
unsigned int V_278 = V_272 -> V_278 ;
unsigned int V_269 = V_272 -> V_269 ;
int F_7 = V_272 -> F_7 ;
int V_274 = V_272 -> V_274 ;
unsigned int V_238 = ( 1 << F_195 ( V_274 ) ) - 1 ;
unsigned int V_280 = V_272 -> V_280 ;
V_267 -> V_42 . integer . V_42 [ 0 ] =
( F_4 ( V_5 , V_6 ) >> V_269 ) & V_238 ;
if ( V_280 )
V_267 -> V_42 . integer . V_42 [ 0 ] =
V_274 - V_267 -> V_42 . integer . V_42 [ 0 ] ;
V_267 -> V_42 . integer . V_42 [ 0 ] =
V_267 -> V_42 . integer . V_42 [ 0 ] - F_7 ;
if ( F_193 ( V_272 ) ) {
V_267 -> V_42 . integer . V_42 [ 1 ] =
( F_4 ( V_5 , V_278 ) >> V_269 ) & V_238 ;
if ( V_280 )
V_267 -> V_42 . integer . V_42 [ 1 ] =
V_274 - V_267 -> V_42 . integer . V_42 [ 1 ] ;
V_267 -> V_42 . integer . V_42 [ 1 ] =
V_267 -> V_42 . integer . V_42 [ 1 ] - F_7 ;
}
return 0 ;
}
int F_205 ( struct V_4 * V_5 ,
const char * V_49 , int V_274 )
{
struct V_80 * V_47 = V_5 -> V_47 -> V_80 ;
struct V_242 * V_252 ;
struct V_271 * V_272 ;
int V_187 = 0 ;
int V_14 = - V_17 ;
if ( F_181 ( ! V_49 || V_274 <= 0 ) )
return - V_17 ;
F_34 (kctl, &card->controls, list) {
if ( ! strncmp ( V_252 -> V_253 . V_49 , V_49 , sizeof( V_252 -> V_253 . V_49 ) ) ) {
V_187 = 1 ;
break;
}
}
if ( V_187 ) {
V_272 = (struct V_271 * ) V_252 -> V_258 ;
if ( V_274 <= V_272 -> V_274 ) {
V_272 -> V_273 = V_274 ;
V_14 = 0 ;
}
}
return V_14 ;
}
int F_206 ( struct V_242 * V_248 ,
struct V_254 * V_255 )
{
struct V_4 * V_5 = F_186 ( V_248 ) ;
struct V_284 * V_180 = ( void * ) V_248 -> V_258 ;
V_255 -> type = V_285 ;
V_255 -> V_18 = V_180 -> V_286 * V_5 -> V_287 ;
return 0 ;
}
int F_207 ( struct V_242 * V_248 ,
struct V_266 * V_267 )
{
struct V_284 * V_180 = ( void * ) V_248 -> V_258 ;
struct V_4 * V_5 = F_186 ( V_248 ) ;
int V_14 ;
if ( V_5 -> V_109 )
V_14 = F_208 ( V_5 -> V_110 , V_180 -> V_288 ,
V_267 -> V_42 . V_289 . V_245 ,
V_180 -> V_286 * V_5 -> V_287 ) ;
else
V_14 = - V_17 ;
if ( V_14 == 0 && V_180 -> V_238 ) {
switch ( V_5 -> V_287 ) {
case 1 :
V_267 -> V_42 . V_289 . V_245 [ 0 ] &= ~ V_180 -> V_238 ;
break;
case 2 :
( ( V_290 * ) ( & V_267 -> V_42 . V_289 . V_245 ) ) [ 0 ]
&= F_209 ( ~ V_180 -> V_238 ) ;
break;
case 4 :
( ( V_291 * ) ( & V_267 -> V_42 . V_289 . V_245 ) ) [ 0 ]
&= F_210 ( ~ V_180 -> V_238 ) ;
break;
default:
return - V_17 ;
}
}
return V_14 ;
}
int F_211 ( struct V_242 * V_248 ,
struct V_266 * V_267 )
{
struct V_284 * V_180 = ( void * ) V_248 -> V_258 ;
struct V_4 * V_5 = F_186 ( V_248 ) ;
int V_14 , V_8 ;
unsigned int V_1 , V_238 ;
void * V_245 ;
if ( ! V_5 -> V_109 )
return - V_17 ;
V_8 = V_180 -> V_286 * V_5 -> V_287 ;
V_245 = F_212 ( V_267 -> V_42 . V_289 . V_245 , V_8 , V_37 | V_292 ) ;
if ( ! V_245 )
return - V_38 ;
if ( V_180 -> V_238 ) {
V_14 = F_213 ( V_5 -> V_110 , V_180 -> V_288 , & V_1 ) ;
if ( V_14 != 0 )
goto V_172;
V_1 &= V_180 -> V_238 ;
switch ( V_5 -> V_287 ) {
case 1 :
( ( V_293 * ) V_245 ) [ 0 ] &= ~ V_180 -> V_238 ;
( ( V_293 * ) V_245 ) [ 0 ] |= V_1 ;
break;
case 2 :
V_238 = ~ V_180 -> V_238 ;
V_14 = F_214 ( V_5 -> V_110 ,
& V_238 , & V_238 ) ;
if ( V_14 != 0 )
goto V_172;
( ( V_290 * ) V_245 ) [ 0 ] &= V_238 ;
V_14 = F_214 ( V_5 -> V_110 ,
& V_1 , & V_1 ) ;
if ( V_14 != 0 )
goto V_172;
( ( V_290 * ) V_245 ) [ 0 ] |= V_1 ;
break;
case 4 :
V_238 = ~ V_180 -> V_238 ;
V_14 = F_214 ( V_5 -> V_110 ,
& V_238 , & V_238 ) ;
if ( V_14 != 0 )
goto V_172;
( ( V_291 * ) V_245 ) [ 0 ] &= V_238 ;
V_14 = F_214 ( V_5 -> V_110 ,
& V_1 , & V_1 ) ;
if ( V_14 != 0 )
goto V_172;
( ( V_291 * ) V_245 ) [ 0 ] |= V_1 ;
break;
default:
V_14 = - V_17 ;
goto V_172;
}
}
V_14 = F_215 ( V_5 -> V_110 , V_180 -> V_288 ,
V_245 , V_8 ) ;
V_172:
F_16 ( V_245 ) ;
return V_14 ;
}
int F_216 ( struct V_242 * V_248 ,
struct V_254 * V_255 )
{
struct V_294 * V_272 =
(struct V_294 * ) V_248 -> V_258 ;
V_255 -> type = V_276 ;
V_255 -> V_18 = 1 ;
V_255 -> V_42 . integer . F_7 = V_272 -> F_7 ;
V_255 -> V_42 . integer . V_274 = V_272 -> V_274 ;
return 0 ;
}
int F_217 ( struct V_242 * V_248 ,
struct V_266 * V_267 )
{
struct V_294 * V_272 =
(struct V_294 * ) V_248 -> V_258 ;
struct V_4 * V_5 = F_186 ( V_248 ) ;
unsigned int V_295 = V_272 -> V_295 ;
unsigned int V_296 = V_272 -> V_296 ;
unsigned int V_297 = V_5 -> V_10 -> V_13 * V_298 ;
unsigned int V_299 = ( 1 << V_297 ) - 1 ;
unsigned int V_280 = V_272 -> V_280 ;
unsigned long V_238 = ( 1UL << V_272 -> V_300 ) - 1 ;
long F_7 = V_272 -> F_7 ;
long V_274 = V_272 -> V_274 ;
long V_1 = 0 ;
unsigned long V_301 ;
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_296 ; V_3 ++ ) {
V_301 = F_4 ( V_5 , V_295 + V_3 ) & V_299 ;
V_1 |= V_301 << ( V_297 * ( V_296 - V_3 - 1 ) ) ;
}
V_1 &= V_238 ;
if ( F_7 < 0 && V_1 > V_274 )
V_1 |= ~ V_238 ;
if ( V_280 )
V_1 = V_274 - V_1 ;
V_267 -> V_42 . integer . V_42 [ 0 ] = V_1 ;
return 0 ;
}
int F_218 ( struct V_242 * V_248 ,
struct V_266 * V_267 )
{
struct V_294 * V_272 =
(struct V_294 * ) V_248 -> V_258 ;
struct V_4 * V_5 = F_186 ( V_248 ) ;
unsigned int V_295 = V_272 -> V_295 ;
unsigned int V_296 = V_272 -> V_296 ;
unsigned int V_297 = V_5 -> V_10 -> V_13 * V_298 ;
unsigned int V_299 = ( 1 << V_297 ) - 1 ;
unsigned int V_280 = V_272 -> V_280 ;
unsigned long V_238 = ( 1UL << V_272 -> V_300 ) - 1 ;
long V_274 = V_272 -> V_274 ;
long V_1 = V_267 -> V_42 . integer . V_42 [ 0 ] ;
unsigned int V_3 , V_301 , V_302 ;
int V_76 ;
if ( V_280 )
V_1 = V_274 - V_1 ;
V_1 &= V_238 ;
for ( V_3 = 0 ; V_3 < V_296 ; V_3 ++ ) {
V_301 = ( V_1 >> ( V_297 * ( V_296 - V_3 - 1 ) ) ) & V_299 ;
V_302 = ( V_238 >> ( V_297 * ( V_296 - V_3 - 1 ) ) ) & V_299 ;
V_76 = F_173 ( V_5 , V_295 + V_3 ,
V_302 , V_301 ) ;
if ( V_76 < 0 )
return V_76 ;
}
return 0 ;
}
int F_219 ( struct V_242 * V_248 ,
struct V_266 * V_267 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_248 -> V_258 ;
struct V_4 * V_5 = F_186 ( V_248 ) ;
unsigned int V_6 = V_272 -> V_6 ;
unsigned int V_269 = V_272 -> V_269 ;
unsigned int V_238 = 1 << V_269 ;
unsigned int V_280 = V_272 -> V_280 != 0 ;
unsigned int V_1 = F_4 ( V_5 , V_6 ) & V_238 ;
if ( V_269 != 0 && V_1 != 0 )
V_1 = V_1 >> V_269 ;
V_267 -> V_42 . V_262 . V_264 [ 0 ] = V_1 ^ V_280 ;
return 0 ;
}
int F_220 ( struct V_242 * V_248 ,
struct V_266 * V_267 )
{
struct V_271 * V_272 =
(struct V_271 * ) V_248 -> V_258 ;
struct V_4 * V_5 = F_186 ( V_248 ) ;
unsigned int V_6 = V_272 -> V_6 ;
unsigned int V_269 = V_272 -> V_269 ;
unsigned int V_238 = 1 << V_269 ;
unsigned int V_280 = V_272 -> V_280 != 0 ;
unsigned int V_303 = V_267 -> V_42 . V_262 . V_264 [ 0 ] != 0 ;
unsigned int V_304 = ( V_303 ^ V_280 ) ? V_238 : 0 ;
unsigned int V_282 = ( V_303 ^ V_280 ) ? 0 : V_238 ;
int V_76 ;
V_76 = F_173 ( V_5 , V_6 , V_238 , V_304 ) ;
if ( V_76 < 0 )
return V_76 ;
V_76 = F_173 ( V_5 , V_6 , V_238 , V_282 ) ;
return V_76 ;
}
int F_221 ( struct V_60 * V_61 , int V_305 ,
unsigned int V_306 , int V_307 )
{
if ( V_61 -> V_10 && V_61 -> V_10 -> V_92 -> V_308 )
return V_61 -> V_10 -> V_92 -> V_308 ( V_61 , V_305 , V_306 , V_307 ) ;
else if ( V_61 -> V_5 && V_61 -> V_5 -> V_10 -> V_308 )
return V_61 -> V_5 -> V_10 -> V_308 ( V_61 -> V_5 , V_305 , 0 ,
V_306 , V_307 ) ;
else
return - V_199 ;
}
int F_222 ( struct V_4 * V_5 , int V_305 ,
int V_309 , unsigned int V_306 , int V_307 )
{
if ( V_5 -> V_10 -> V_308 )
return V_5 -> V_10 -> V_308 ( V_5 , V_305 , V_309 ,
V_306 , V_307 ) ;
else
return - V_199 ;
}
int F_223 ( struct V_60 * V_61 ,
int V_310 , int div )
{
if ( V_61 -> V_10 && V_61 -> V_10 -> V_92 -> V_311 )
return V_61 -> V_10 -> V_92 -> V_311 ( V_61 , V_310 , div ) ;
else
return - V_17 ;
}
int F_224 ( struct V_60 * V_61 , int V_312 , int V_309 ,
unsigned int V_313 , unsigned int V_314 )
{
if ( V_61 -> V_10 && V_61 -> V_10 -> V_92 -> V_315 )
return V_61 -> V_10 -> V_92 -> V_315 ( V_61 , V_312 , V_309 ,
V_313 , V_314 ) ;
else if ( V_61 -> V_5 && V_61 -> V_5 -> V_10 -> V_315 )
return V_61 -> V_5 -> V_10 -> V_315 ( V_61 -> V_5 , V_312 , V_309 ,
V_313 , V_314 ) ;
else
return - V_17 ;
}
int F_225 ( struct V_4 * V_5 , int V_312 , int V_309 ,
unsigned int V_313 , unsigned int V_314 )
{
if ( V_5 -> V_10 -> V_315 )
return V_5 -> V_10 -> V_315 ( V_5 , V_312 , V_309 ,
V_313 , V_314 ) ;
else
return - V_17 ;
}
int F_226 ( struct V_60 * V_61 , unsigned int V_316 )
{
if ( V_61 -> V_10 && V_61 -> V_10 -> V_92 -> V_317 )
return V_61 -> V_10 -> V_92 -> V_317 ( V_61 , V_316 ) ;
else
return - V_17 ;
}
int F_129 ( struct V_60 * V_61 , unsigned int V_318 )
{
if ( V_61 -> V_10 == NULL )
return - V_17 ;
if ( V_61 -> V_10 -> V_92 -> V_319 == NULL )
return - V_199 ;
return V_61 -> V_10 -> V_92 -> V_319 ( V_61 , V_318 ) ;
}
static int F_227 ( unsigned int V_320 ,
unsigned int * V_321 ,
unsigned int * V_322 )
{
if ( * V_321 || * V_322 )
return 0 ;
if ( ! V_320 )
return - V_17 ;
* V_321 = ( 1 << V_320 ) - 1 ;
* V_322 = ( 1 << V_320 ) - 1 ;
return 0 ;
}
int F_228 ( struct V_60 * V_61 ,
unsigned int V_321 , unsigned int V_322 , int V_320 , int V_323 )
{
if ( V_61 -> V_10 && V_61 -> V_10 -> V_92 -> V_324 )
V_61 -> V_10 -> V_92 -> V_324 ( V_320 ,
& V_321 , & V_322 ) ;
else
F_227 ( V_320 , & V_321 , & V_322 ) ;
if ( V_61 -> V_10 && V_61 -> V_10 -> V_92 -> V_325 )
return V_61 -> V_10 -> V_92 -> V_325 ( V_61 , V_321 , V_322 ,
V_320 , V_323 ) ;
else
return - V_199 ;
}
int F_229 ( struct V_60 * V_61 ,
unsigned int V_326 , unsigned int * V_327 ,
unsigned int V_328 , unsigned int * V_329 )
{
if ( V_61 -> V_10 && V_61 -> V_10 -> V_92 -> V_330 )
return V_61 -> V_10 -> V_92 -> V_330 ( V_61 , V_326 , V_327 ,
V_328 , V_329 ) ;
else
return - V_17 ;
}
int F_230 ( struct V_60 * V_61 , int V_331 )
{
if ( V_61 -> V_10 && V_61 -> V_10 -> V_92 -> V_332 )
return V_61 -> V_10 -> V_92 -> V_332 ( V_61 , V_331 ) ;
else
return - V_17 ;
}
int F_231 ( struct V_60 * V_61 , int V_333 ,
int V_334 )
{
if ( ! V_61 -> V_10 )
return - V_199 ;
if ( V_61 -> V_10 -> V_92 -> V_335 )
return V_61 -> V_10 -> V_92 -> V_335 ( V_61 , V_333 , V_334 ) ;
else if ( V_334 == V_103 &&
V_61 -> V_10 -> V_92 -> V_93 )
return V_61 -> V_10 -> V_92 -> V_93 ( V_61 , V_333 ) ;
else
return - V_199 ;
}
int F_139 ( struct V_62 * V_47 )
{
int V_3 , V_14 ;
if ( ! V_47 -> V_49 || ! V_47 -> V_27 )
return - V_17 ;
for ( V_3 = 0 ; V_3 < V_47 -> V_69 ; V_3 ++ ) {
struct V_120 * V_336 = & V_47 -> V_67 [ V_3 ] ;
if ( ! ! V_336 -> V_128 == ! ! V_336 -> V_127 ) {
F_50 ( V_47 -> V_27 ,
L_88 ,
V_336 -> V_49 ) ;
return - V_17 ;
}
if ( ! V_336 -> V_129 ) {
F_50 ( V_47 -> V_27 ,
L_89 ,
V_336 -> V_49 ) ;
return - V_17 ;
}
if ( V_336 -> V_121 && V_336 -> V_130 ) {
F_50 ( V_47 -> V_27 ,
L_90 ,
V_336 -> V_49 ) ;
return - V_17 ;
}
if ( V_336 -> V_124 && V_336 -> V_122 ) {
F_50 ( V_47 -> V_27 ,
L_91 ,
V_336 -> V_49 ) ;
return - V_17 ;
}
if ( ! V_336 -> V_125 &&
! ( V_336 -> V_124 || V_336 -> V_122 ) ) {
F_50 ( V_47 -> V_27 ,
L_92 ,
V_336 -> V_49 ) ;
return - V_17 ;
}
}
F_98 ( V_47 -> V_27 , V_47 ) ;
F_232 ( V_47 ) ;
F_38 ( V_47 ) ;
V_47 -> V_31 = F_233 ( V_47 -> V_27 ,
sizeof( struct V_30 ) *
( V_47 -> V_69 + V_47 -> V_193 ) ,
V_37 ) ;
if ( V_47 -> V_31 == NULL )
return - V_38 ;
V_47 -> V_87 = 0 ;
V_47 -> V_164 = & V_47 -> V_31 [ V_47 -> V_69 ] ;
for ( V_3 = 0 ; V_3 < V_47 -> V_69 ; V_3 ++ )
V_47 -> V_31 [ V_3 ] . V_67 = & V_47 -> V_67 [ V_3 ] ;
F_100 ( & V_47 -> V_157 ) ;
F_100 ( & V_47 -> V_337 ) ;
V_47 -> V_211 = 0 ;
F_99 ( & V_47 -> V_190 ) ;
F_99 ( & V_47 -> V_338 ) ;
V_14 = F_121 ( V_47 ) ;
if ( V_14 != 0 )
F_40 ( V_47 ) ;
for ( V_3 = 0 ; V_3 < V_47 -> V_87 ; V_3 ++ ) {
struct V_60 * V_96 = V_47 -> V_31 [ V_3 ] . V_96 ;
struct V_60 * V_88 = V_47 -> V_31 [ V_3 ] . V_88 ;
if ( ! V_88 -> V_118 )
F_64 ( V_88 -> V_27 ) ;
if ( ! V_96 -> V_118 )
F_64 ( V_96 -> V_27 ) ;
}
return V_14 ;
}
int F_142 ( struct V_62 * V_47 )
{
if ( V_47 -> V_211 )
F_140 ( V_47 ) ;
F_42 ( V_47 -> V_27 , L_93 , V_47 -> V_49 ) ;
return 0 ;
}
static char * F_234 ( struct V_26 * V_27 , int * V_253 )
{
char * V_187 , V_49 [ V_339 ] ;
int V_340 , V_341 ;
if ( F_71 ( V_27 ) == NULL )
return NULL ;
F_184 ( V_49 , F_71 ( V_27 ) , V_339 ) ;
V_187 = strstr ( V_49 , V_27 -> V_10 -> V_49 ) ;
if ( V_187 ) {
if ( sscanf ( & V_187 [ strlen ( V_27 -> V_10 -> V_49 ) ] , L_94 , V_253 ) == 1 ) {
if ( * V_253 == - 1 )
V_187 [ strlen ( V_27 -> V_10 -> V_49 ) ] = '\0' ;
}
} else {
if ( sscanf ( V_49 , L_95 , & V_340 , & V_341 ) == 2 ) {
char V_342 [ V_339 ] ;
* V_253 = ( ( V_340 & 0xffff ) << 16 ) + V_341 ;
snprintf ( V_342 , V_339 , L_96 , V_27 -> V_10 -> V_49 , V_49 ) ;
F_184 ( V_49 , V_342 , V_339 ) ;
} else
* V_253 = 0 ;
}
return F_235 ( V_49 , V_37 ) ;
}
static inline char * F_236 ( struct V_26 * V_27 ,
struct V_89 * V_343 )
{
if ( V_343 -> V_49 == NULL ) {
F_50 ( V_27 ,
L_97 ,
F_71 ( V_27 ) ) ;
return NULL ;
}
return F_235 ( V_343 -> V_49 , V_37 ) ;
}
static void F_237 ( struct V_58 * V_59 )
{
struct V_60 * V_61 , * V_344 ;
F_238 (dai, _dai, &component->dai_list, list) {
F_42 ( V_59 -> V_27 , L_98 ,
V_61 -> V_49 ) ;
F_74 ( & V_61 -> V_157 ) ;
F_16 ( V_61 -> V_49 ) ;
F_16 ( V_61 ) ;
}
}
static int F_239 ( struct V_58 * V_59 ,
struct V_4 * V_5 , struct V_89 * V_343 ,
T_1 V_18 , bool V_345 )
{
struct V_26 * V_27 = V_59 -> V_27 ;
struct V_60 * V_61 ;
unsigned int V_3 ;
int V_14 ;
F_42 ( V_27 , L_99 , F_71 ( V_27 ) , V_18 ) ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ ) {
V_61 = F_96 ( sizeof( struct V_60 ) , V_37 ) ;
if ( V_61 == NULL ) {
V_14 = - V_38 ;
goto V_76;
}
if ( V_18 == 1 && V_345 ) {
V_61 -> V_49 = F_234 ( V_27 , & V_61 -> V_253 ) ;
} else {
V_61 -> V_49 = F_236 ( V_27 , & V_343 [ V_3 ] ) ;
if ( V_343 [ V_3 ] . V_253 )
V_61 -> V_253 = V_343 [ V_3 ] . V_253 ;
else
V_61 -> V_253 = V_3 ;
}
if ( V_61 -> V_49 == NULL ) {
F_16 ( V_61 ) ;
V_14 = - V_38 ;
goto V_76;
}
V_61 -> V_59 = V_59 ;
V_61 -> V_5 = V_5 ;
V_61 -> V_27 = V_27 ;
V_61 -> V_10 = & V_343 [ V_3 ] ;
V_61 -> V_54 . V_27 = V_27 ;
if ( ! V_61 -> V_10 -> V_92 )
V_61 -> V_10 -> V_92 = & V_346 ;
if ( ! V_61 -> V_5 )
V_61 -> V_54 . V_107 = 1 ;
F_91 ( & V_61 -> V_157 , & V_59 -> V_347 ) ;
F_42 ( V_27 , L_100 , V_61 -> V_49 ) ;
}
return 0 ;
V_76:
F_237 ( V_59 ) ;
return V_14 ;
}
static int
F_240 ( struct V_26 * V_27 ,
struct V_58 * V_348 ,
const struct V_349 * V_350 ,
struct V_4 * V_5 ,
struct V_89 * V_343 ,
int V_351 , bool V_352 )
{
int V_14 ;
F_42 ( V_27 , L_101 , F_71 ( V_27 ) ) ;
if ( ! V_348 ) {
F_50 ( V_27 , L_102 ) ;
return - V_38 ;
}
V_348 -> V_49 = F_234 ( V_27 , & V_348 -> V_253 ) ;
if ( ! V_348 -> V_49 ) {
F_50 ( V_27 , L_103 ) ;
return - V_38 ;
}
V_348 -> V_27 = V_27 ;
V_348 -> V_10 = V_350 ;
V_348 -> V_343 = V_343 ;
V_348 -> V_351 = V_351 ;
F_100 ( & V_348 -> V_347 ) ;
V_14 = F_239 ( V_348 , V_5 , V_343 , V_351 ,
V_352 ) ;
if ( V_14 < 0 ) {
F_50 ( V_27 , L_104 , V_14 ) ;
goto V_353;
}
F_152 ( & V_354 ) ;
F_91 ( & V_348 -> V_157 , & V_355 ) ;
F_135 ( & V_354 ) ;
F_42 ( V_348 -> V_27 , L_105 , V_348 -> V_49 ) ;
return V_14 ;
V_353:
F_16 ( V_348 -> V_49 ) ;
return V_14 ;
}
int F_241 ( struct V_26 * V_27 ,
const struct V_349 * V_350 ,
struct V_89 * V_343 ,
int V_351 )
{
struct V_58 * V_348 ;
V_348 = F_233 ( V_27 , sizeof( * V_348 ) , V_37 ) ;
if ( ! V_348 ) {
F_50 ( V_27 , L_106 ) ;
return - V_38 ;
}
V_348 -> V_356 = true ;
return F_240 ( V_27 , V_348 , V_350 , NULL ,
V_343 , V_351 , true ) ;
}
void F_242 ( struct V_26 * V_27 )
{
struct V_58 * V_348 ;
F_34 (cmpnt, &component_list, list) {
if ( V_27 == V_348 -> V_27 )
goto V_187;
}
return;
V_187:
F_237 ( V_348 ) ;
F_152 ( & V_354 ) ;
F_74 ( & V_348 -> V_157 ) ;
F_135 ( & V_354 ) ;
F_42 ( V_27 , L_107 , V_348 -> V_49 ) ;
F_16 ( V_348 -> V_49 ) ;
}
int F_243 ( struct V_26 * V_27 , struct V_55 * V_56 ,
const struct V_159 * V_357 )
{
V_56 -> V_49 = F_234 ( V_27 , & V_56 -> V_253 ) ;
if ( V_56 -> V_49 == NULL )
return - V_38 ;
V_56 -> V_27 = V_27 ;
V_56 -> V_10 = V_357 ;
V_56 -> V_54 . V_27 = V_27 ;
V_56 -> V_54 . V_56 = V_56 ;
V_56 -> V_54 . V_358 = V_357 -> V_358 ;
F_99 ( & V_56 -> V_190 ) ;
F_152 ( & V_354 ) ;
F_91 ( & V_56 -> V_157 , & V_359 ) ;
F_135 ( & V_354 ) ;
F_42 ( V_27 , L_108 , V_56 -> V_49 ) ;
return 0 ;
}
int F_244 ( struct V_26 * V_27 ,
const struct V_159 * V_357 )
{
struct V_55 * V_56 ;
int V_14 ;
F_42 ( V_27 , L_109 , F_71 ( V_27 ) ) ;
V_56 = F_96 ( sizeof( struct V_55 ) , V_37 ) ;
if ( V_56 == NULL )
return - V_38 ;
V_14 = F_243 ( V_27 , V_56 , V_357 ) ;
if ( V_14 )
F_16 ( V_56 ) ;
return V_14 ;
}
void F_245 ( struct V_55 * V_56 )
{
F_152 ( & V_354 ) ;
F_74 ( & V_56 -> V_157 ) ;
F_135 ( & V_354 ) ;
F_42 ( V_56 -> V_27 , L_110 ,
V_56 -> V_49 ) ;
F_16 ( V_56 -> V_49 ) ;
}
struct V_55 * F_246 ( struct V_26 * V_27 )
{
struct V_55 * V_56 ;
F_34 (platform, &platform_list, list) {
if ( V_27 == V_56 -> V_27 )
return V_56 ;
}
return NULL ;
}
void F_247 ( struct V_26 * V_27 )
{
struct V_55 * V_56 ;
V_56 = F_246 ( V_27 ) ;
if ( ! V_56 )
return;
F_245 ( V_56 ) ;
F_16 ( V_56 ) ;
}
static void F_248 ( struct V_360 * V_68 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_130 ( V_361 ) ; V_3 ++ )
if ( V_68 -> V_362 & V_361 [ V_3 ] )
V_68 -> V_362 |= V_361 [ V_3 ] ;
}
int F_249 ( struct V_26 * V_27 ,
const struct V_146 * V_363 ,
struct V_89 * V_343 ,
int V_351 )
{
struct V_4 * V_5 ;
int V_14 , V_3 ;
F_42 ( V_27 , L_111 , F_71 ( V_27 ) ) ;
V_5 = F_96 ( sizeof( struct V_4 ) , V_37 ) ;
if ( V_5 == NULL )
return - V_38 ;
V_5 -> V_49 = F_234 ( V_27 , & V_5 -> V_253 ) ;
if ( V_5 -> V_49 == NULL ) {
V_14 = - V_38 ;
goto V_364;
}
V_5 -> V_150 = V_363 -> V_150 ;
V_5 -> V_217 = V_363 -> V_217 ;
V_5 -> V_214 = V_363 -> V_214 ;
V_5 -> V_215 = V_363 -> V_215 ;
V_5 -> V_216 = V_363 -> V_216 ;
V_5 -> V_59 . V_356 = V_363 -> V_356 ;
V_5 -> V_54 . V_102 = V_108 ;
V_5 -> V_54 . V_27 = V_27 ;
V_5 -> V_54 . V_5 = V_5 ;
V_5 -> V_54 . V_365 = V_363 -> V_365 ;
V_5 -> V_54 . V_358 = V_363 -> V_358 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_10 = V_363 ;
V_5 -> V_351 = V_351 ;
F_99 ( & V_5 -> V_190 ) ;
for ( V_3 = 0 ; V_3 < V_351 ; V_3 ++ ) {
F_248 ( & V_343 [ V_3 ] . V_366 ) ;
F_248 ( & V_343 [ V_3 ] . V_367 ) ;
}
F_152 ( & V_354 ) ;
F_91 ( & V_5 -> V_157 , & V_368 ) ;
F_135 ( & V_354 ) ;
V_14 = F_240 ( V_27 , & V_5 -> V_59 ,
& V_363 -> V_369 ,
V_5 , V_343 , V_351 , false ) ;
if ( V_14 < 0 ) {
F_50 ( V_5 -> V_27 , L_112 , V_14 ) ;
goto V_370;
}
F_42 ( V_5 -> V_27 , L_113 , V_5 -> V_49 ) ;
return 0 ;
V_370:
F_152 ( & V_354 ) ;
F_74 ( & V_5 -> V_157 ) ;
F_135 ( & V_354 ) ;
F_16 ( V_5 -> V_49 ) ;
V_364:
F_16 ( V_5 ) ;
return V_14 ;
}
void F_250 ( struct V_26 * V_27 )
{
struct V_4 * V_5 ;
F_34 (codec, &codec_list, list) {
if ( V_27 == V_5 -> V_27 )
goto V_187;
}
return;
V_187:
F_242 ( V_27 ) ;
F_152 ( & V_354 ) ;
F_74 ( & V_5 -> V_157 ) ;
F_135 ( & V_354 ) ;
F_42 ( V_5 -> V_27 , L_114 , V_5 -> V_49 ) ;
F_251 ( V_5 ) ;
F_16 ( V_5 -> V_49 ) ;
F_16 ( V_5 ) ;
}
int F_252 ( struct V_62 * V_47 ,
const char * V_371 )
{
struct V_372 * V_373 = V_47 -> V_27 -> V_123 ;
int V_14 ;
V_14 = F_253 ( V_373 , V_371 , 0 , & V_47 -> V_49 ) ;
if ( V_14 < 0 && V_14 != - V_17 ) {
F_50 ( V_47 -> V_27 ,
L_115 ,
V_371 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
int F_254 ( struct V_62 * V_47 ,
const char * V_371 )
{
struct V_372 * V_373 = V_47 -> V_27 -> V_123 ;
struct V_174 * V_374 ;
const char * V_247 , * V_375 ;
int V_3 , V_376 , V_377 , V_14 ;
V_377 = F_255 ( V_373 , V_371 ) ;
if ( V_377 < 0 ) {
F_50 ( V_47 -> V_27 ,
L_116 , V_371 ) ;
return - V_17 ;
}
if ( V_377 & 1 ) {
F_50 ( V_47 -> V_27 ,
L_117 , V_371 ) ;
return - V_17 ;
}
V_377 /= 2 ;
if ( ! V_377 ) {
F_50 ( V_47 -> V_27 , L_118 ,
V_371 ) ;
return - V_17 ;
}
V_374 = F_256 ( V_47 -> V_27 , V_377 , sizeof( * V_374 ) ,
V_37 ) ;
if ( ! V_374 ) {
F_50 ( V_47 -> V_27 ,
L_119 ) ;
return - V_38 ;
}
for ( V_3 = 0 ; V_3 < V_377 ; V_3 ++ ) {
V_14 = F_253 ( V_373 , V_371 ,
2 * V_3 , & V_247 ) ;
if ( V_14 ) {
F_50 ( V_47 -> V_27 ,
L_120 ,
V_371 , 2 * V_3 , V_14 ) ;
return - V_17 ;
}
for ( V_376 = 0 ; V_376 < F_130 ( V_378 ) ; V_376 ++ ) {
if ( ! strncmp ( V_247 , V_378 [ V_376 ] . V_49 ,
strlen ( V_378 [ V_376 ] . V_49 ) ) ) {
V_374 [ V_3 ] = V_378 [ V_376 ] ;
break;
}
}
if ( V_376 >= F_130 ( V_378 ) ) {
F_50 ( V_47 -> V_27 ,
L_121 ,
V_247 ) ;
return - V_17 ;
}
V_14 = F_253 ( V_373 , V_371 ,
( 2 * V_3 ) + 1 ,
& V_375 ) ;
if ( V_14 ) {
F_50 ( V_47 -> V_27 ,
L_120 ,
V_371 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_17 ;
}
V_374 [ V_3 ] . V_49 = V_375 ;
}
V_47 -> V_148 = V_374 ;
V_47 -> V_149 = V_377 ;
return 0 ;
}
int F_257 ( struct V_372 * V_373 ,
unsigned int * V_320 ,
unsigned int * V_323 )
{
V_291 V_1 ;
int V_14 ;
if ( F_258 ( V_373 , L_122 ) ) {
V_14 = F_259 ( V_373 , L_122 , & V_1 ) ;
if ( V_14 )
return V_14 ;
if ( V_320 )
* V_320 = V_1 ;
}
if ( F_258 ( V_373 , L_123 ) ) {
V_14 = F_259 ( V_373 , L_123 , & V_1 ) ;
if ( V_14 )
return V_14 ;
if ( V_323 )
* V_323 = V_1 ;
}
return 0 ;
}
int F_260 ( struct V_62 * V_47 ,
const char * V_371 )
{
struct V_372 * V_373 = V_47 -> V_27 -> V_123 ;
int V_379 ;
struct V_380 * V_381 ;
int V_3 , V_14 ;
V_379 = F_255 ( V_373 , V_371 ) ;
if ( V_379 < 0 || V_379 & 1 ) {
F_50 ( V_47 -> V_27 ,
L_124 ,
V_371 ) ;
return - V_17 ;
}
V_379 /= 2 ;
if ( ! V_379 ) {
F_50 ( V_47 -> V_27 , L_118 ,
V_371 ) ;
return - V_17 ;
}
V_381 = F_233 ( V_47 -> V_27 , V_379 * sizeof( * V_381 ) ,
V_37 ) ;
if ( ! V_381 ) {
F_50 ( V_47 -> V_27 ,
L_125 ) ;
return - V_17 ;
}
for ( V_3 = 0 ; V_3 < V_379 ; V_3 ++ ) {
V_14 = F_253 ( V_373 , V_371 ,
2 * V_3 , & V_381 [ V_3 ] . V_382 ) ;
if ( V_14 ) {
F_50 ( V_47 -> V_27 ,
L_126 ,
V_371 , 2 * V_3 , V_14 ) ;
return - V_17 ;
}
V_14 = F_253 ( V_373 , V_371 ,
( 2 * V_3 ) + 1 , & V_381 [ V_3 ] . V_309 ) ;
if ( V_14 ) {
F_50 ( V_47 -> V_27 ,
L_126 ,
V_371 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_17 ;
}
}
V_47 -> V_156 = V_379 ;
V_47 -> V_155 = V_381 ;
return 0 ;
}
unsigned int F_261 ( struct V_372 * V_373 ,
const char * V_246 )
{
int V_14 , V_3 ;
char V_383 [ 128 ] ;
unsigned int V_384 = 0 ;
int V_385 , V_386 ;
const char * V_387 ;
struct {
char * V_49 ;
unsigned int V_1 ;
} V_388 [] = {
{ L_127 , V_389 } ,
{ L_128 , V_390 } ,
{ L_129 , V_391 } ,
{ L_130 , V_392 } ,
{ L_131 , V_393 } ,
{ L_132 , V_394 } ,
{ L_133 , V_395 } ,
{ L_134 , V_396 } ,
{ L_135 , V_397 } ,
} ;
if ( ! V_246 )
V_246 = L_136 ;
snprintf ( V_383 , sizeof( V_383 ) , L_137 , V_246 ) ;
V_14 = F_262 ( V_373 , V_383 , & V_387 ) ;
if ( V_14 == 0 ) {
for ( V_3 = 0 ; V_3 < F_130 ( V_388 ) ; V_3 ++ ) {
if ( strcmp ( V_387 , V_388 [ V_3 ] . V_49 ) == 0 ) {
V_384 |= V_388 [ V_3 ] . V_1 ;
break;
}
}
}
snprintf ( V_383 , sizeof( V_383 ) , L_138 , V_246 ) ;
if ( F_263 ( V_373 , V_383 , NULL ) )
V_384 |= V_398 ;
else
V_384 |= V_399 ;
snprintf ( V_383 , sizeof( V_383 ) , L_139 , V_246 ) ;
V_385 = ! ! F_263 ( V_373 , V_383 , NULL ) ;
snprintf ( V_383 , sizeof( V_383 ) , L_140 , V_246 ) ;
V_386 = ! ! F_263 ( V_373 , V_383 , NULL ) ;
switch ( ( V_385 << 4 ) + V_386 ) {
case 0x11 :
V_384 |= V_400 ;
break;
case 0x10 :
V_384 |= V_401 ;
break;
case 0x01 :
V_384 |= V_402 ;
break;
default:
break;
}
snprintf ( V_383 , sizeof( V_383 ) , L_141 , V_246 ) ;
V_385 = ! ! F_263 ( V_373 , V_383 , NULL ) ;
snprintf ( V_383 , sizeof( V_383 ) , L_142 , V_246 ) ;
V_386 = ! ! F_263 ( V_373 , V_383 , NULL ) ;
switch ( ( V_385 << 4 ) + V_386 ) {
case 0x11 :
V_384 |= V_201 ;
break;
case 0x10 :
V_384 |= V_203 ;
break;
case 0x01 :
V_384 |= V_204 ;
break;
default:
V_384 |= V_202 ;
break;
}
return V_384 ;
}
int F_264 ( struct V_372 * V_123 ,
const char * * V_403 )
{
struct V_58 * V_19 ;
struct V_404 args ;
int V_14 ;
V_14 = F_265 ( V_123 , L_143 ,
L_144 , 0 , & args ) ;
if ( V_14 )
return V_14 ;
V_14 = - V_126 ;
F_152 ( & V_354 ) ;
F_34 (pos, &component_list, list) {
if ( V_19 -> V_27 -> V_123 != args . V_373 )
continue;
if ( V_19 -> V_10 -> V_405 ) {
V_14 = V_19 -> V_10 -> V_405 ( V_19 , & args , V_403 ) ;
} else {
int V_253 = - 1 ;
switch ( args . V_406 ) {
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
* V_403 = V_19 -> V_343 [ V_253 ] . V_49 ;
if ( ! * V_403 )
* V_403 = V_19 -> V_49 ;
}
break;
}
F_135 ( & V_354 ) ;
F_266 ( args . V_373 ) ;
return V_14 ;
}
static int T_5 F_267 ( void )
{
#ifdef F_105
V_63 = F_24 ( L_145 , NULL ) ;
if ( F_161 ( V_63 ) || ! V_63 ) {
F_268 ( L_146 ) ;
V_63 = NULL ;
}
if ( ! F_27 ( L_147 , 0444 , V_63 , NULL ,
& V_407 ) )
F_268 ( L_148 ) ;
if ( ! F_27 ( L_149 , 0444 , V_63 , NULL ,
& V_408 ) )
F_268 ( L_150 ) ;
if ( ! F_27 ( L_151 , 0444 , V_63 , NULL ,
& V_409 ) )
F_268 ( L_152 ) ;
#endif
F_269 () ;
return F_270 ( & V_410 ) ;
}
static void T_6 F_271 ( void )
{
F_272 () ;
#ifdef F_105
F_30 ( V_63 ) ;
#endif
F_273 ( & V_410 ) ;
}
