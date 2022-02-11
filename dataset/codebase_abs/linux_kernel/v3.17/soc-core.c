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
if ( V_22 >= V_19 ) {
if ( V_21 + V_8 >= V_18 - 1 )
break;
F_2 ( V_5 , V_3 , V_7 + V_21 , V_8 ) ;
V_21 += V_8 ;
}
V_22 += V_8 ;
}
V_21 = F_6 ( V_21 , V_18 - 1 ) ;
return V_21 ;
}
static T_2 F_7 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_7 )
{
struct V_28 * V_29 = F_8 ( V_25 ) ;
return F_5 ( V_29 -> V_5 , V_7 , V_30 , 0 ) ;
}
static T_2 F_9 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_7 )
{
struct V_28 * V_29 = F_8 ( V_25 ) ;
return sprintf ( V_7 , L_3 , V_29 -> V_31 ) ;
}
static T_2 F_10 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
const char * V_7 , T_1 V_18 )
{
struct V_28 * V_29 = F_8 ( V_25 ) ;
int V_14 ;
V_14 = F_11 ( V_7 , 10 , & V_29 -> V_31 ) ;
if ( V_14 )
return V_14 ;
return V_18 ;
}
static T_2 F_12 ( struct V_32 * V_32 , char T_4 * V_33 ,
T_1 V_18 , T_3 * V_34 )
{
T_2 V_14 ;
struct V_4 * V_5 = V_32 -> V_35 ;
char * V_7 ;
if ( * V_34 < 0 || ! V_18 )
return - V_17 ;
V_7 = F_13 ( V_18 , V_36 ) ;
if ( ! V_7 )
return - V_37 ;
V_14 = F_5 ( V_5 , V_7 , V_18 , * V_34 ) ;
if ( V_14 >= 0 ) {
if ( F_14 ( V_33 , V_7 , V_14 ) ) {
F_15 ( V_7 ) ;
return - V_38 ;
}
* V_34 += V_14 ;
}
F_15 ( V_7 ) ;
return V_14 ;
}
static T_2 F_16 ( struct V_32 * V_32 ,
const char T_4 * V_33 , T_1 V_18 , T_3 * V_34 )
{
char V_7 [ 32 ] ;
T_1 V_39 ;
char * V_40 = V_7 ;
unsigned long V_6 , V_41 ;
struct V_4 * V_5 = V_32 -> V_35 ;
int V_14 ;
V_39 = F_6 ( V_18 , ( sizeof( V_7 ) - 1 ) ) ;
if ( F_17 ( V_7 , V_33 , V_39 ) )
return - V_38 ;
V_7 [ V_39 ] = 0 ;
while ( * V_40 == ' ' )
V_40 ++ ;
V_6 = F_18 ( V_40 , & V_40 , 16 ) ;
while ( * V_40 == ' ' )
V_40 ++ ;
V_14 = F_19 ( V_40 , 16 , & V_41 ) ;
if ( V_14 )
return V_14 ;
F_20 ( V_42 , V_43 ) ;
F_21 ( V_5 , V_6 , V_41 ) ;
return V_39 ;
}
static struct V_44 * F_22 ( struct V_44 * V_45 ,
const char * V_46 , ... )
{
struct V_44 * V_47 ;
T_5 V_48 ;
char * V_49 ;
va_start ( V_48 , V_46 ) ;
V_49 = F_23 ( V_36 , V_46 , V_48 ) ;
va_end ( V_48 ) ;
if ( ! V_49 )
return NULL ;
V_47 = F_24 ( V_49 , V_45 ) ;
F_15 ( V_49 ) ;
return V_47 ;
}
static void F_25 ( struct V_4 * V_5 )
{
struct V_44 * V_50 = V_5 -> V_51 . V_52 -> V_50 ;
V_5 -> V_53 = F_22 ( V_50 ,
L_4 ,
V_5 -> V_51 . V_54 ) ;
if ( ! V_5 -> V_53 ) {
F_26 ( V_5 -> V_25 ,
L_5 ) ;
return;
}
F_27 ( L_6 , 0444 , V_5 -> V_53 ,
& V_5 -> V_55 ) ;
F_27 ( L_7 , 0444 , V_5 -> V_53 ,
& V_5 -> V_56 ) ;
V_5 -> V_57 = F_28 ( L_8 , 0644 ,
V_5 -> V_53 ,
V_5 , & V_58 ) ;
if ( ! V_5 -> V_57 )
F_26 ( V_5 -> V_25 ,
L_9 ) ;
F_29 ( & V_5 -> V_59 , V_5 -> V_53 ) ;
}
static void F_30 ( struct V_4 * V_5 )
{
F_31 ( V_5 -> V_53 ) ;
}
static void F_32 ( struct V_60 * V_61 )
{
struct V_44 * V_50 = V_61 -> V_51 . V_52 -> V_50 ;
V_61 -> V_62 = F_22 ( V_50 ,
L_10 ,
V_61 -> V_51 . V_54 ) ;
if ( ! V_61 -> V_62 ) {
F_26 ( V_61 -> V_25 ,
L_11 ) ;
return;
}
F_29 ( & V_61 -> V_51 . V_59 ,
V_61 -> V_62 ) ;
}
static void F_33 ( struct V_60 * V_61 )
{
F_31 ( V_61 -> V_62 ) ;
}
static T_2 F_34 ( struct V_32 * V_32 , char T_4 * V_33 ,
T_1 V_18 , T_3 * V_34 )
{
char * V_7 = F_13 ( V_30 , V_36 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_4 * V_5 ;
if ( ! V_7 )
return - V_37 ;
F_35 (codec, &codec_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_30 - V_14 , L_12 ,
V_5 -> V_51 . V_54 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_30 ) {
V_14 = V_30 ;
break;
}
}
if ( V_14 >= 0 )
V_14 = F_36 ( V_33 , V_18 , V_34 , V_7 , V_14 ) ;
F_15 ( V_7 ) ;
return V_14 ;
}
static T_2 F_37 ( struct V_32 * V_32 , char T_4 * V_33 ,
T_1 V_18 , T_3 * V_34 )
{
char * V_7 = F_13 ( V_30 , V_36 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_63 * V_51 ;
struct V_64 * V_65 ;
if ( ! V_7 )
return - V_37 ;
F_35 (component, &component_list, list) {
F_35 (dai, &component->dai_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_30 - V_14 , L_12 ,
V_65 -> V_54 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_30 ) {
V_14 = V_30 ;
break;
}
}
}
V_14 = F_36 ( V_33 , V_18 , V_34 , V_7 , V_14 ) ;
F_15 ( V_7 ) ;
return V_14 ;
}
static T_2 F_38 ( struct V_32 * V_32 ,
char T_4 * V_33 ,
T_1 V_18 , T_3 * V_34 )
{
char * V_7 = F_13 ( V_30 , V_36 ) ;
T_2 V_8 , V_14 = 0 ;
struct V_60 * V_61 ;
if ( ! V_7 )
return - V_37 ;
F_35 (platform, &platform_list, list) {
V_8 = snprintf ( V_7 + V_14 , V_30 - V_14 , L_12 ,
V_61 -> V_51 . V_54 ) ;
if ( V_8 >= 0 )
V_14 += V_8 ;
if ( V_14 > V_30 ) {
V_14 = V_30 ;
break;
}
}
V_14 = F_36 ( V_33 , V_18 , V_34 , V_7 , V_14 ) ;
F_15 ( V_7 ) ;
return V_14 ;
}
static void F_39 ( struct V_66 * V_52 )
{
V_52 -> V_50 = F_24 ( V_52 -> V_54 ,
V_67 ) ;
if ( ! V_52 -> V_50 ) {
F_26 ( V_52 -> V_25 ,
L_13 ) ;
return;
}
V_52 -> V_68 = F_40 ( L_14 , 0644 ,
V_52 -> V_50 ,
& V_52 -> V_69 ) ;
if ( ! V_52 -> V_68 )
F_26 ( V_52 -> V_25 ,
L_15 ) ;
}
static void F_41 ( struct V_66 * V_52 )
{
F_31 ( V_52 -> V_50 ) ;
}
static inline void F_25 ( struct V_4 * V_5 )
{
}
static inline void F_30 ( struct V_4 * V_5 )
{
}
static inline void F_32 ( struct V_60 * V_61 )
{
}
static inline void F_33 ( struct V_60 * V_61 )
{
}
static inline void F_39 ( struct V_66 * V_52 )
{
}
static inline void F_41 ( struct V_66 * V_52 )
{
}
struct V_70 * F_42 ( struct V_66 * V_52 ,
const char * V_71 , int V_72 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_52 -> V_73 ; V_3 ++ ) {
if ( V_52 -> V_29 [ V_3 ] . V_71 -> V_74 &&
! strcmp ( V_52 -> V_29 [ V_3 ] . V_71 -> V_54 , V_71 ) )
return V_52 -> V_29 [ V_3 ] . V_75 -> V_76 [ V_72 ] . V_77 ;
}
F_43 ( V_52 -> V_25 , L_16 , V_71 ) ;
return NULL ;
}
struct V_28 * F_44 ( struct V_66 * V_52 ,
const char * V_71 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_52 -> V_73 ; V_3 ++ ) {
if ( ! strcmp ( V_52 -> V_29 [ V_3 ] . V_71 -> V_54 , V_71 ) )
return & V_52 -> V_29 [ V_3 ] ;
}
F_43 ( V_52 -> V_25 , L_17 , V_71 ) ;
return NULL ;
}
static int F_45 ( struct V_4 * V_5 )
{
if ( V_5 -> V_78 -> V_25 . V_79 )
F_46 ( & V_5 -> V_78 -> V_25 ) ;
return 0 ;
}
static void F_47 ( struct V_24 * V_25 ) {}
static int F_48 ( struct V_4 * V_5 )
{
int V_80 ;
V_5 -> V_78 -> V_25 . V_79 = & V_81 ;
V_5 -> V_78 -> V_25 . V_45 = V_5 -> V_51 . V_52 -> V_25 ;
V_5 -> V_78 -> V_25 . V_82 = F_47 ;
F_49 ( & V_5 -> V_78 -> V_25 , L_18 ,
V_5 -> V_51 . V_52 -> V_83 -> V_84 , 0 ,
V_5 -> V_51 . V_54 ) ;
V_80 = F_50 ( & V_5 -> V_78 -> V_25 ) ;
if ( V_80 < 0 ) {
F_51 ( V_5 -> V_25 , L_19 ) ;
V_5 -> V_78 -> V_25 . V_79 = NULL ;
return V_80 ;
}
return 0 ;
}
static void F_52 ( struct V_85 * V_86 )
{
}
int F_53 ( struct V_24 * V_25 )
{
struct V_66 * V_52 = F_8 ( V_25 ) ;
struct V_4 * V_5 ;
int V_3 , V_87 ;
if ( F_54 ( & V_52 -> V_88 ) )
return 0 ;
F_55 ( V_52 -> V_83 ) ;
F_56 ( V_52 -> V_83 , V_89 ) ;
F_57 ( V_52 -> V_83 ) ;
F_58 ( V_52 -> V_83 , V_90 ) ;
for ( V_3 = 0 ; V_3 < V_52 -> V_91 ; V_3 ++ ) {
if ( V_52 -> V_29 [ V_3 ] . V_71 -> V_92 )
continue;
for ( V_87 = 0 ; V_87 < V_52 -> V_29 [ V_3 ] . V_93 ; V_87 ++ ) {
struct V_64 * V_65 = V_52 -> V_29 [ V_3 ] . V_94 [ V_87 ] ;
struct V_95 * V_96 = V_65 -> V_10 ;
if ( V_96 -> V_97 -> V_98 && V_65 -> V_99 )
V_96 -> V_97 -> V_98 ( V_65 , 1 ) ;
}
}
for ( V_3 = 0 ; V_3 < V_52 -> V_91 ; V_3 ++ ) {
if ( V_52 -> V_29 [ V_3 ] . V_71 -> V_92 )
continue;
F_59 ( V_52 -> V_29 [ V_3 ] . V_75 ) ;
}
if ( V_52 -> V_100 )
V_52 -> V_100 ( V_52 ) ;
for ( V_3 = 0 ; V_3 < V_52 -> V_91 ; V_3 ++ ) {
struct V_64 * V_101 = V_52 -> V_29 [ V_3 ] . V_101 ;
struct V_60 * V_61 = V_52 -> V_29 [ V_3 ] . V_61 ;
if ( V_52 -> V_29 [ V_3 ] . V_71 -> V_92 )
continue;
if ( V_101 -> V_10 -> V_102 && ! V_101 -> V_10 -> V_103 )
V_101 -> V_10 -> V_102 ( V_101 ) ;
if ( V_61 -> V_10 -> V_102 && ! V_61 -> V_104 ) {
V_61 -> V_10 -> V_102 ( V_101 ) ;
V_61 -> V_104 = 1 ;
}
}
for ( V_3 = 0 ; V_3 < V_52 -> V_91 ; V_3 ++ ) {
struct V_64 * * V_94 = V_52 -> V_29 [ V_3 ] . V_94 ;
F_60 ( & V_52 -> V_29 [ V_3 ] . V_105 ) ;
for ( V_87 = 0 ; V_87 < V_52 -> V_29 [ V_3 ] . V_93 ; V_87 ++ ) {
V_94 [ V_87 ] -> V_5 -> V_59 . V_106 =
V_94 [ V_87 ] -> V_5 -> V_59 . V_107 ;
}
}
for ( V_3 = 0 ; V_3 < V_52 -> V_91 ; V_3 ++ ) {
if ( V_52 -> V_29 [ V_3 ] . V_71 -> V_92 )
continue;
F_61 ( & V_52 -> V_29 [ V_3 ] ,
V_108 ,
V_109 ) ;
F_61 ( & V_52 -> V_29 [ V_3 ] ,
V_110 ,
V_109 ) ;
}
F_62 ( & V_52 -> V_59 ) ;
F_63 ( & V_52 -> V_59 ) ;
F_35 (codec, &card->codec_dev_list, card_list) {
if ( ! V_5 -> V_104 && V_5 -> V_10 -> V_102 ) {
switch ( V_5 -> V_59 . V_107 ) {
case V_111 :
if ( V_5 -> V_59 . V_112 ) {
F_43 ( V_5 -> V_25 ,
L_20 ) ;
break;
}
case V_113 :
V_5 -> V_10 -> V_102 ( V_5 ) ;
V_5 -> V_104 = 1 ;
V_5 -> V_55 = 1 ;
if ( V_5 -> V_51 . V_114 )
F_64 ( V_5 -> V_51 . V_114 ) ;
F_65 ( V_5 -> V_25 ) ;
break;
default:
F_43 ( V_5 -> V_25 ,
L_21 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_52 -> V_91 ; V_3 ++ ) {
struct V_64 * V_101 = V_52 -> V_29 [ V_3 ] . V_101 ;
if ( V_52 -> V_29 [ V_3 ] . V_71 -> V_92 )
continue;
if ( V_101 -> V_10 -> V_102 && V_101 -> V_10 -> V_103 )
V_101 -> V_10 -> V_102 ( V_101 ) ;
F_65 ( V_101 -> V_25 ) ;
}
if ( V_52 -> V_115 )
V_52 -> V_115 ( V_52 ) ;
return 0 ;
}
static void F_66 ( struct V_85 * V_86 )
{
struct V_66 * V_52 =
F_67 ( V_86 , struct V_66 , V_116 ) ;
struct V_4 * V_5 ;
int V_3 , V_87 ;
F_43 ( V_52 -> V_25 , L_22 ) ;
F_58 ( V_52 -> V_83 , V_117 ) ;
if ( V_52 -> V_118 )
V_52 -> V_118 ( V_52 ) ;
for ( V_3 = 0 ; V_3 < V_52 -> V_91 ; V_3 ++ ) {
struct V_64 * V_101 = V_52 -> V_29 [ V_3 ] . V_101 ;
if ( V_52 -> V_29 [ V_3 ] . V_71 -> V_92 )
continue;
if ( V_101 -> V_10 -> V_119 && V_101 -> V_10 -> V_103 )
V_101 -> V_10 -> V_119 ( V_101 ) ;
}
F_35 (codec, &card->codec_dev_list, card_list) {
if ( V_5 -> V_10 -> V_119 && V_5 -> V_104 ) {
switch ( V_5 -> V_59 . V_107 ) {
case V_111 :
case V_113 :
V_5 -> V_10 -> V_119 ( V_5 ) ;
V_5 -> V_104 = 0 ;
break;
default:
F_43 ( V_5 -> V_25 ,
L_23 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_52 -> V_91 ; V_3 ++ ) {
if ( V_52 -> V_29 [ V_3 ] . V_71 -> V_92 )
continue;
F_61 ( & V_52 -> V_29 [ V_3 ] ,
V_108 ,
V_120 ) ;
F_61 ( & V_52 -> V_29 [ V_3 ] ,
V_110 ,
V_120 ) ;
}
for ( V_3 = 0 ; V_3 < V_52 -> V_91 ; V_3 ++ ) {
if ( V_52 -> V_29 [ V_3 ] . V_71 -> V_92 )
continue;
for ( V_87 = 0 ; V_87 < V_52 -> V_29 [ V_3 ] . V_93 ; V_87 ++ ) {
struct V_64 * V_65 = V_52 -> V_29 [ V_3 ] . V_94 [ V_87 ] ;
struct V_95 * V_96 = V_65 -> V_10 ;
if ( V_96 -> V_97 -> V_98 && V_65 -> V_99 )
V_96 -> V_97 -> V_98 ( V_65 , 0 ) ;
}
}
for ( V_3 = 0 ; V_3 < V_52 -> V_91 ; V_3 ++ ) {
struct V_64 * V_101 = V_52 -> V_29 [ V_3 ] . V_101 ;
struct V_60 * V_61 = V_52 -> V_29 [ V_3 ] . V_61 ;
if ( V_52 -> V_29 [ V_3 ] . V_71 -> V_92 )
continue;
if ( V_101 -> V_10 -> V_119 && ! V_101 -> V_10 -> V_103 )
V_101 -> V_10 -> V_119 ( V_101 ) ;
if ( V_61 -> V_10 -> V_119 && V_61 -> V_104 ) {
V_61 -> V_10 -> V_119 ( V_101 ) ;
V_61 -> V_104 = 0 ;
}
}
if ( V_52 -> V_121 )
V_52 -> V_121 ( V_52 ) ;
F_43 ( V_52 -> V_25 , L_24 ) ;
F_58 ( V_52 -> V_83 , V_89 ) ;
F_62 ( & V_52 -> V_59 ) ;
F_63 ( & V_52 -> V_59 ) ;
}
int F_68 ( struct V_24 * V_25 )
{
struct V_66 * V_52 = F_8 ( V_25 ) ;
int V_3 , V_103 = 0 ;
if ( F_54 ( & V_52 -> V_88 ) )
return 0 ;
for ( V_3 = 0 ; V_3 < V_52 -> V_91 ; V_3 ++ ) {
struct V_28 * V_29 = & V_52 -> V_29 [ V_3 ] ;
struct V_64 * * V_94 = V_29 -> V_94 ;
struct V_64 * V_101 = V_29 -> V_101 ;
int V_87 ;
if ( V_101 -> V_122 )
F_69 ( V_101 -> V_25 ) ;
for ( V_87 = 0 ; V_87 < V_29 -> V_93 ; V_87 ++ ) {
struct V_64 * V_123 = V_94 [ V_87 ] ;
if ( V_123 -> V_122 )
F_69 ( V_123 -> V_25 ) ;
}
}
for ( V_3 = 0 ; V_3 < V_52 -> V_91 ; V_3 ++ ) {
struct V_64 * V_101 = V_52 -> V_29 [ V_3 ] . V_101 ;
V_103 |= V_101 -> V_10 -> V_103 ;
}
if ( V_103 ) {
F_43 ( V_25 , L_25 ) ;
F_66 ( & V_52 -> V_116 ) ;
} else {
F_43 ( V_25 , L_26 ) ;
if ( ! F_70 ( & V_52 -> V_116 ) )
F_51 ( V_25 , L_27 ) ;
}
return 0 ;
}
static struct V_4 * F_71 (
const struct V_124 * V_125 ,
const char * V_126 )
{
struct V_4 * V_5 ;
F_35 (codec, &codec_list, list) {
if ( V_125 ) {
if ( V_5 -> V_25 -> V_127 != V_125 )
continue;
} else {
if ( strcmp ( V_5 -> V_51 . V_54 , V_126 ) )
continue;
}
return V_5 ;
}
return NULL ;
}
static struct V_64 * F_72 ( struct V_4 * V_5 ,
const char * V_128 )
{
struct V_64 * V_123 ;
F_35 (codec_dai, &codec->component.dai_list, list) {
if ( ! strcmp ( V_123 -> V_54 , V_128 ) ) {
return V_123 ;
}
}
return NULL ;
}
static int F_73 ( struct V_66 * V_52 , int V_129 )
{
struct V_130 * V_71 = & V_52 -> V_71 [ V_129 ] ;
struct V_28 * V_29 = & V_52 -> V_29 [ V_129 ] ;
struct V_63 * V_51 ;
struct V_131 * V_132 = V_71 -> V_132 ;
struct V_64 * * V_94 = V_29 -> V_94 ;
struct V_60 * V_61 ;
struct V_64 * V_101 ;
const char * V_133 ;
int V_3 ;
F_43 ( V_52 -> V_25 , L_28 , V_71 -> V_54 , V_129 ) ;
F_35 (component, &component_list, list) {
if ( V_71 -> V_134 &&
V_51 -> V_25 -> V_127 != V_71 -> V_134 )
continue;
if ( V_71 -> V_135 &&
strcmp ( F_74 ( V_51 -> V_25 ) , V_71 -> V_135 ) )
continue;
F_35 (cpu_dai, &component->dai_list, list) {
if ( V_71 -> V_136 &&
strcmp ( V_101 -> V_54 , V_71 -> V_136 ) )
continue;
V_29 -> V_101 = V_101 ;
}
}
if ( ! V_29 -> V_101 ) {
F_51 ( V_52 -> V_25 , L_29 ,
V_71 -> V_136 ) ;
return - V_137 ;
}
V_29 -> V_93 = V_71 -> V_93 ;
for ( V_3 = 0 ; V_3 < V_29 -> V_93 ; V_3 ++ ) {
struct V_4 * V_5 ;
V_5 = F_71 ( V_132 [ V_3 ] . V_127 , V_132 [ V_3 ] . V_54 ) ;
if ( ! V_5 ) {
F_51 ( V_52 -> V_25 , L_30 ,
V_132 [ V_3 ] . V_54 ) ;
return - V_137 ;
}
V_94 [ V_3 ] = F_72 ( V_5 , V_132 [ V_3 ] . V_138 ) ;
if ( ! V_94 [ V_3 ] ) {
F_51 ( V_52 -> V_25 , L_31 ,
V_132 [ V_3 ] . V_138 ) ;
return - V_137 ;
}
}
V_29 -> V_123 = V_94 [ 0 ] ;
V_29 -> V_5 = V_29 -> V_123 -> V_5 ;
V_133 = V_71 -> V_133 ;
if ( ! V_133 && ! V_71 -> V_139 )
V_133 = L_32 ;
F_35 (platform, &platform_list, list) {
if ( V_71 -> V_139 ) {
if ( V_61 -> V_25 -> V_127 !=
V_71 -> V_139 )
continue;
} else {
if ( strcmp ( V_61 -> V_51 . V_54 , V_133 ) )
continue;
}
V_29 -> V_61 = V_61 ;
}
if ( ! V_29 -> V_61 ) {
F_51 ( V_52 -> V_25 , L_33 ,
V_71 -> V_133 ) ;
return - V_137 ;
}
V_52 -> V_91 ++ ;
return 0 ;
}
static int F_75 ( struct V_60 * V_61 )
{
int V_14 ;
if ( V_61 -> V_10 -> remove ) {
V_14 = V_61 -> V_10 -> remove ( V_61 ) ;
if ( V_14 < 0 )
F_51 ( V_61 -> V_25 , L_34 ,
V_14 ) ;
}
F_76 ( & V_61 -> V_51 . V_59 ) ;
F_33 ( V_61 ) ;
V_61 -> V_140 = 0 ;
F_77 ( V_61 -> V_25 -> V_10 -> V_141 ) ;
return 0 ;
}
static void F_78 ( struct V_4 * V_5 )
{
int V_80 ;
if ( V_5 -> V_10 -> remove ) {
V_80 = V_5 -> V_10 -> remove ( V_5 ) ;
if ( V_80 < 0 )
F_51 ( V_5 -> V_25 , L_34 , V_80 ) ;
}
F_76 ( & V_5 -> V_59 ) ;
F_30 ( V_5 ) ;
V_5 -> V_140 = 0 ;
F_79 ( & V_5 -> V_142 ) ;
F_77 ( V_5 -> V_25 -> V_10 -> V_141 ) ;
}
static void F_80 ( struct V_64 * V_123 , int V_143 )
{
int V_80 ;
if ( V_123 && V_123 -> V_140 &&
V_123 -> V_10 -> V_144 == V_143 ) {
if ( V_123 -> V_10 -> remove ) {
V_80 = V_123 -> V_10 -> remove ( V_123 ) ;
if ( V_80 < 0 )
F_51 ( V_123 -> V_25 ,
L_35 ,
V_123 -> V_54 , V_80 ) ;
}
V_123 -> V_140 = 0 ;
}
}
static void F_81 ( struct V_66 * V_52 , int V_129 , int V_143 )
{
struct V_28 * V_29 = & V_52 -> V_29 [ V_129 ] ;
struct V_64 * V_101 = V_29 -> V_101 ;
int V_3 , V_80 ;
if ( V_29 -> V_145 ) {
F_82 ( V_29 -> V_25 , & V_146 ) ;
F_82 ( V_29 -> V_25 , & V_147 ) ;
F_46 ( V_29 -> V_25 ) ;
V_29 -> V_145 = 0 ;
}
for ( V_3 = 0 ; V_3 < V_29 -> V_93 ; V_3 ++ )
F_80 ( V_29 -> V_94 [ V_3 ] , V_143 ) ;
if ( V_101 && V_101 -> V_140 &&
V_101 -> V_10 -> V_144 == V_143 ) {
if ( V_101 -> V_10 -> remove ) {
V_80 = V_101 -> V_10 -> remove ( V_101 ) ;
if ( V_80 < 0 )
F_51 ( V_101 -> V_25 ,
L_35 ,
V_101 -> V_54 , V_80 ) ;
}
V_101 -> V_140 = 0 ;
if ( ! V_101 -> V_5 )
F_77 ( V_101 -> V_25 -> V_10 -> V_141 ) ;
}
}
static void F_83 ( struct V_66 * V_52 , int V_129 ,
int V_143 )
{
struct V_28 * V_29 = & V_52 -> V_29 [ V_129 ] ;
struct V_64 * V_101 = V_29 -> V_101 ;
struct V_60 * V_61 = V_29 -> V_61 ;
struct V_4 * V_5 ;
int V_3 ;
if ( V_61 && V_61 -> V_140 &&
V_61 -> V_10 -> V_144 == V_143 ) {
F_75 ( V_61 ) ;
}
for ( V_3 = 0 ; V_3 < V_29 -> V_93 ; V_3 ++ ) {
V_5 = V_29 -> V_94 [ V_3 ] -> V_5 ;
if ( V_5 && V_5 -> V_140 &&
V_5 -> V_10 -> V_144 == V_143 )
F_78 ( V_5 ) ;
}
if ( V_101 ) {
V_5 = V_101 -> V_5 ;
if ( V_5 && V_5 -> V_140 &&
V_5 -> V_10 -> V_144 == V_143 )
F_78 ( V_5 ) ;
}
}
static void F_84 ( struct V_66 * V_52 )
{
int V_65 , V_143 ;
for ( V_143 = V_148 ; V_143 <= V_149 ;
V_143 ++ ) {
for ( V_65 = 0 ; V_65 < V_52 -> V_91 ; V_65 ++ )
F_81 ( V_52 , V_65 , V_143 ) ;
}
for ( V_143 = V_148 ; V_143 <= V_149 ;
V_143 ++ ) {
for ( V_65 = 0 ; V_65 < V_52 -> V_91 ; V_65 ++ )
F_83 ( V_52 , V_65 , V_143 ) ;
}
V_52 -> V_91 = 0 ;
}
static void F_85 ( struct V_66 * V_52 ,
struct V_63 * V_51 )
{
int V_3 ;
if ( V_52 -> V_150 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_52 -> V_151 ; V_3 ++ ) {
struct V_152 * V_153 = & V_52 -> V_150 [ V_3 ] ;
if ( V_153 -> V_127 && V_51 -> V_25 -> V_127 != V_153 -> V_127 )
continue;
if ( V_153 -> F_74 && strcmp ( V_51 -> V_54 , V_153 -> F_74 ) )
continue;
V_51 -> V_154 = V_153 -> V_154 ;
break;
}
}
static int F_86 ( struct V_66 * V_52 ,
struct V_4 * V_5 )
{
int V_14 = 0 ;
const struct V_155 * V_10 = V_5 -> V_10 ;
struct V_64 * V_65 ;
V_5 -> V_51 . V_52 = V_52 ;
V_5 -> V_59 . V_52 = V_52 ;
F_85 ( V_52 , & V_5 -> V_51 ) ;
if ( ! F_87 ( V_5 -> V_25 -> V_10 -> V_141 ) )
return - V_156 ;
F_25 ( V_5 ) ;
if ( V_10 -> V_157 ) {
V_14 = F_88 ( & V_5 -> V_59 ,
V_10 -> V_157 ,
V_10 -> V_158 ) ;
if ( V_14 != 0 ) {
F_51 ( V_5 -> V_25 ,
L_36 , V_14 ) ;
goto V_159;
}
}
F_35 (dai, &codec->component.dai_list, list) {
V_14 = F_89 ( & V_5 -> V_59 , V_65 ) ;
if ( V_14 != 0 ) {
F_51 ( V_5 -> V_25 ,
L_37 , V_14 ) ;
goto V_159;
}
}
V_5 -> V_59 . V_112 = V_10 -> V_112 ;
if ( V_10 -> V_160 ) {
V_14 = V_10 -> V_160 ( V_5 ) ;
if ( V_14 < 0 ) {
F_51 ( V_5 -> V_25 ,
L_38 , V_14 ) ;
goto V_159;
}
F_90 ( V_5 -> V_59 . V_112 &&
V_5 -> V_59 . V_107 != V_113 ,
L_39 ,
V_5 -> V_51 . V_54 ) ;
}
if ( V_10 -> V_161 )
F_91 ( V_5 , V_10 -> V_161 ,
V_10 -> V_162 ) ;
if ( V_10 -> V_163 )
F_92 ( & V_5 -> V_59 , V_10 -> V_163 ,
V_10 -> V_164 ) ;
V_5 -> V_140 = 1 ;
F_93 ( & V_5 -> V_142 , & V_52 -> V_88 ) ;
F_93 ( & V_5 -> V_59 . V_165 , & V_52 -> V_166 ) ;
return 0 ;
V_159:
F_30 ( V_5 ) ;
F_77 ( V_5 -> V_25 -> V_10 -> V_141 ) ;
return V_14 ;
}
static int F_94 ( struct V_66 * V_52 ,
struct V_60 * V_61 )
{
int V_14 = 0 ;
const struct V_167 * V_10 = V_61 -> V_10 ;
struct V_63 * V_51 ;
struct V_64 * V_65 ;
V_61 -> V_51 . V_52 = V_52 ;
V_61 -> V_51 . V_59 . V_52 = V_52 ;
if ( ! F_87 ( V_61 -> V_25 -> V_10 -> V_141 ) )
return - V_156 ;
F_32 ( V_61 ) ;
if ( V_10 -> V_157 )
F_88 ( & V_61 -> V_51 . V_59 ,
V_10 -> V_157 , V_10 -> V_158 ) ;
F_35 (component, &component_list, list) {
if ( V_51 -> V_25 != V_61 -> V_25 )
continue;
F_35 (dai, &component->dai_list, list)
F_89 ( & V_61 -> V_51 . V_59 ,
V_65 ) ;
}
V_61 -> V_51 . V_59 . V_112 = 1 ;
if ( V_10 -> V_160 ) {
V_14 = V_10 -> V_160 ( V_61 ) ;
if ( V_14 < 0 ) {
F_51 ( V_61 -> V_25 ,
L_40 , V_14 ) ;
goto V_159;
}
}
if ( V_10 -> V_161 )
F_95 ( V_61 , V_10 -> V_161 ,
V_10 -> V_162 ) ;
if ( V_10 -> V_163 )
F_92 ( & V_61 -> V_51 . V_59 ,
V_10 -> V_163 , V_10 -> V_164 ) ;
V_61 -> V_140 = 1 ;
F_93 ( & V_61 -> V_51 . V_59 . V_165 , & V_52 -> V_166 ) ;
return 0 ;
V_159:
F_33 ( V_61 ) ;
F_77 ( V_61 -> V_25 -> V_10 -> V_141 ) ;
return V_14 ;
}
static void F_96 ( struct V_24 * V_25 )
{
F_15 ( V_25 ) ;
}
static int F_97 ( struct V_28 * V_29 ,
const char * V_54 )
{
int V_14 = 0 ;
V_29 -> V_25 = F_98 ( sizeof( struct V_24 ) , V_36 ) ;
if ( ! V_29 -> V_25 )
return - V_37 ;
F_99 ( V_29 -> V_25 ) ;
V_29 -> V_25 -> V_45 = V_29 -> V_52 -> V_25 ;
V_29 -> V_25 -> V_82 = F_96 ;
F_49 ( V_29 -> V_25 , L_41 , V_54 ) ;
F_100 ( V_29 -> V_25 , V_29 ) ;
F_101 ( & V_29 -> V_168 ) ;
F_102 ( & V_29 -> V_169 [ V_108 ] . V_170 ) ;
F_102 ( & V_29 -> V_169 [ V_110 ] . V_170 ) ;
F_102 ( & V_29 -> V_169 [ V_108 ] . V_171 ) ;
F_102 ( & V_29 -> V_169 [ V_110 ] . V_171 ) ;
V_14 = F_103 ( V_29 -> V_25 ) ;
if ( V_14 < 0 ) {
F_104 ( V_29 -> V_25 ) ;
F_51 ( V_29 -> V_52 -> V_25 ,
L_42 , V_14 ) ;
return V_14 ;
}
V_29 -> V_145 = 1 ;
V_14 = F_105 ( V_29 -> V_25 ) ;
if ( V_14 < 0 )
F_51 ( V_29 -> V_25 ,
L_43 , V_14 ) ;
V_14 = F_106 ( V_29 -> V_25 , & V_147 ) ;
if ( V_14 < 0 )
F_51 ( V_29 -> V_25 ,
L_44 , V_14 ) ;
return 0 ;
}
static int F_107 ( struct V_66 * V_52 , int V_129 ,
int V_143 )
{
struct V_28 * V_29 = & V_52 -> V_29 [ V_129 ] ;
struct V_64 * V_101 = V_29 -> V_101 ;
struct V_60 * V_61 = V_29 -> V_61 ;
int V_3 , V_14 ;
if ( V_101 -> V_5 &&
! V_101 -> V_5 -> V_140 &&
V_101 -> V_5 -> V_10 -> V_172 == V_143 ) {
V_14 = F_86 ( V_52 , V_101 -> V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
for ( V_3 = 0 ; V_3 < V_29 -> V_93 ; V_3 ++ ) {
if ( ! V_29 -> V_94 [ V_3 ] -> V_5 -> V_140 &&
V_29 -> V_94 [ V_3 ] -> V_5 -> V_10 -> V_172 == V_143 ) {
V_14 = F_86 ( V_52 , V_29 -> V_94 [ V_3 ] -> V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
}
if ( ! V_61 -> V_140 &&
V_61 -> V_10 -> V_172 == V_143 ) {
V_14 = F_94 ( V_52 , V_61 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
static int F_108 ( struct V_66 * V_52 ,
struct V_64 * V_123 ,
int V_143 )
{
int V_14 ;
if ( ! V_123 -> V_140 && V_123 -> V_10 -> V_172 == V_143 ) {
if ( V_123 -> V_10 -> V_160 ) {
V_14 = V_123 -> V_10 -> V_160 ( V_123 ) ;
if ( V_14 < 0 ) {
F_51 ( V_123 -> V_25 ,
L_45 ,
V_123 -> V_54 , V_14 ) ;
return V_14 ;
}
}
V_123 -> V_140 = 1 ;
}
return 0 ;
}
static int F_109 ( struct V_66 * V_52 ,
struct V_130 * V_71 ,
struct V_28 * V_29 )
{
struct V_64 * V_101 = V_29 -> V_101 ;
struct V_64 * V_123 = V_29 -> V_123 ;
struct V_173 * V_174 , * V_175 ;
int V_14 ;
if ( V_29 -> V_93 > 1 )
F_26 ( V_52 -> V_25 , L_46 ) ;
V_174 = V_123 -> V_176 ;
V_175 = V_101 -> V_177 ;
if ( V_174 && V_175 ) {
V_14 = F_110 ( V_52 , V_71 -> V_178 ,
V_175 , V_174 ) ;
if ( V_14 != 0 ) {
F_51 ( V_52 -> V_25 , L_47 ,
V_174 -> V_54 , V_175 -> V_54 , V_14 ) ;
return V_14 ;
}
}
V_174 = V_101 -> V_176 ;
V_175 = V_123 -> V_177 ;
if ( V_174 && V_175 ) {
V_14 = F_110 ( V_52 , V_71 -> V_178 ,
V_175 , V_174 ) ;
if ( V_14 != 0 ) {
F_51 ( V_52 -> V_25 , L_47 ,
V_174 -> V_54 , V_175 -> V_54 , V_14 ) ;
return V_14 ;
}
}
return 0 ;
}
static int F_111 ( struct V_66 * V_52 , int V_129 , int V_143 )
{
struct V_130 * V_71 = & V_52 -> V_71 [ V_129 ] ;
struct V_28 * V_29 = & V_52 -> V_29 [ V_129 ] ;
struct V_60 * V_61 = V_29 -> V_61 ;
struct V_64 * V_101 = V_29 -> V_101 ;
int V_3 , V_14 ;
F_43 ( V_52 -> V_25 , L_48 ,
V_52 -> V_54 , V_129 , V_143 ) ;
V_101 -> V_61 = V_61 ;
V_101 -> V_52 = V_52 ;
for ( V_3 = 0 ; V_3 < V_29 -> V_93 ; V_3 ++ )
V_29 -> V_94 [ V_3 ] -> V_52 = V_52 ;
V_29 -> V_31 = V_31 ;
if ( ! V_101 -> V_140 &&
V_101 -> V_10 -> V_172 == V_143 ) {
if ( ! V_101 -> V_5 ) {
if ( ! F_87 ( V_101 -> V_25 -> V_10 -> V_141 ) )
return - V_156 ;
}
if ( V_101 -> V_10 -> V_160 ) {
V_14 = V_101 -> V_10 -> V_160 ( V_101 ) ;
if ( V_14 < 0 ) {
F_51 ( V_101 -> V_25 ,
L_49 ,
V_101 -> V_54 , V_14 ) ;
F_77 ( V_101 -> V_25 -> V_10 -> V_141 ) ;
return V_14 ;
}
}
V_101 -> V_140 = 1 ;
}
for ( V_3 = 0 ; V_3 < V_29 -> V_93 ; V_3 ++ ) {
V_14 = F_108 ( V_52 , V_29 -> V_94 [ V_3 ] , V_143 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_143 != V_149 )
return 0 ;
if ( V_71 -> V_179 ) {
V_14 = V_71 -> V_179 ( V_29 ) ;
if ( V_14 < 0 ) {
F_51 ( V_52 -> V_25 , L_50 ,
V_71 -> V_54 , V_14 ) ;
return V_14 ;
}
}
V_14 = F_97 ( V_29 , V_71 -> V_54 ) ;
if ( V_14 )
return V_14 ;
#ifdef F_112
if ( V_71 -> V_180 ) {
V_14 = F_113 ( V_29 ) ;
if ( V_14 < 0 ) {
F_51 ( V_29 -> V_25 ,
L_51 ,
V_14 ) ;
return V_14 ;
}
}
#endif
V_14 = F_106 ( V_29 -> V_25 , & V_146 ) ;
if ( V_14 < 0 )
F_26 ( V_29 -> V_25 , L_52 ,
V_14 ) ;
if ( V_101 -> V_10 -> V_181 ) {
V_14 = F_114 ( V_29 , V_129 ) ;
if ( V_14 < 0 ) {
F_51 ( V_52 -> V_25 , L_53 ,
V_71 -> V_182 ) ;
return V_14 ;
}
} else {
if ( ! V_71 -> V_178 ) {
V_14 = F_115 ( V_29 , V_129 ) ;
if ( V_14 < 0 ) {
F_51 ( V_52 -> V_25 , L_54 ,
V_71 -> V_182 , V_14 ) ;
return V_14 ;
}
} else {
F_116 ( & V_29 -> V_105 ,
F_52 ) ;
V_14 = F_109 ( V_52 , V_71 , V_29 ) ;
if ( V_14 )
return V_14 ;
}
}
for ( V_3 = 0 ; V_3 < V_29 -> V_93 ; V_3 ++ ) {
if ( V_29 -> V_94 [ V_3 ] -> V_10 -> V_103 )
F_117 ( V_29 -> V_94 [ V_3 ] -> V_5 -> V_78 ,
V_29 -> V_101 -> V_183 ) ;
}
return 0 ;
}
static int F_118 ( struct V_4 * V_5 ,
struct V_64 * V_123 )
{
int V_14 ;
if ( V_123 -> V_10 -> V_103 && ! V_5 -> V_184 ) {
if ( ! V_5 -> V_185 )
return 0 ;
V_14 = F_48 ( V_5 ) ;
if ( V_14 < 0 ) {
F_51 ( V_5 -> V_25 ,
L_55 , V_14 ) ;
return V_14 ;
}
V_5 -> V_184 = 1 ;
}
return 0 ;
}
static void F_119 ( struct V_4 * V_5 )
{
if ( V_5 -> V_184 ) {
F_45 ( V_5 ) ;
V_5 -> V_184 = 0 ;
}
}
static int F_120 ( struct V_28 * V_29 )
{
int V_3 , V_14 ;
for ( V_3 = 0 ; V_3 < V_29 -> V_93 ; V_3 ++ ) {
struct V_64 * V_123 = V_29 -> V_94 [ V_3 ] ;
V_14 = F_118 ( V_123 -> V_5 , V_123 ) ;
if ( V_14 ) {
while ( -- V_3 >= 0 )
F_119 ( V_123 -> V_5 ) ;
return V_14 ;
}
}
return 0 ;
}
static void F_121 ( struct V_28 * V_29 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_29 -> V_93 ; V_3 ++ )
F_119 ( V_29 -> V_94 [ V_3 ] -> V_5 ) ;
}
static int F_122 ( struct V_66 * V_52 , int V_129 )
{
struct V_28 * V_29 = & V_52 -> V_186 [ V_129 ] ;
struct V_187 * V_188 = & V_52 -> V_188 [ V_129 ] ;
const char * V_189 = V_188 -> V_126 ;
V_29 -> V_5 = F_71 ( V_188 -> V_125 , V_189 ) ;
if ( ! V_29 -> V_5 ) {
if ( V_188 -> V_125 )
V_189 = F_123 ( V_188 -> V_125 ) ;
F_51 ( V_52 -> V_25 , L_56 , V_189 ) ;
return - V_137 ;
}
return 0 ;
}
static int F_124 ( struct V_66 * V_52 , int V_129 )
{
struct V_28 * V_29 = & V_52 -> V_186 [ V_129 ] ;
struct V_187 * V_188 = & V_52 -> V_188 [ V_129 ] ;
int V_14 ;
if ( V_29 -> V_5 -> V_140 ) {
F_51 ( V_29 -> V_5 -> V_25 , L_57 ) ;
return - V_190 ;
}
V_14 = F_86 ( V_52 , V_29 -> V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_188 -> V_179 ) {
V_14 = V_188 -> V_179 ( & V_29 -> V_5 -> V_59 ) ;
if ( V_14 < 0 ) {
F_51 ( V_52 -> V_25 , L_50 ,
V_188 -> V_54 , V_14 ) ;
return V_14 ;
}
}
return F_97 ( V_29 , V_188 -> V_54 ) ;
}
static void F_125 ( struct V_66 * V_52 , int V_129 )
{
struct V_28 * V_29 = & V_52 -> V_186 [ V_129 ] ;
struct V_4 * V_5 = V_29 -> V_5 ;
if ( V_29 -> V_145 ) {
F_82 ( V_29 -> V_25 , & V_147 ) ;
F_46 ( V_29 -> V_25 ) ;
V_29 -> V_145 = 0 ;
}
if ( V_5 && V_5 -> V_140 )
F_78 ( V_5 ) ;
}
static int F_126 ( struct V_4 * V_5 )
{
int V_14 ;
if ( V_5 -> V_191 )
return 0 ;
V_14 = F_127 ( V_5 ) ;
if ( V_14 < 0 ) {
F_51 ( V_5 -> V_25 ,
L_58 ,
V_14 ) ;
return V_14 ;
}
V_5 -> V_191 = 1 ;
return 0 ;
}
static int F_128 ( struct V_66 * V_52 )
{
struct V_4 * V_5 ;
struct V_130 * V_71 ;
int V_14 , V_3 , V_143 , V_192 ;
F_129 ( & V_52 -> V_193 , V_194 ) ;
for ( V_3 = 0 ; V_3 < V_52 -> V_73 ; V_3 ++ ) {
V_14 = F_73 ( V_52 , V_3 ) ;
if ( V_14 != 0 )
goto V_195;
}
for ( V_3 = 0 ; V_3 < V_52 -> V_196 ; V_3 ++ ) {
V_14 = F_122 ( V_52 , V_3 ) ;
if ( V_14 != 0 )
goto V_195;
}
F_35 (codec, &codec_list, list) {
if ( V_5 -> V_191 )
continue;
V_14 = F_126 ( V_5 ) ;
if ( V_14 < 0 )
goto V_195;
}
V_14 = F_130 ( V_52 -> V_25 , V_197 , V_198 ,
V_52 -> V_141 , 0 , & V_52 -> V_83 ) ;
if ( V_14 < 0 ) {
F_51 ( V_52 -> V_25 ,
L_59 ,
V_52 -> V_54 , V_14 ) ;
goto V_195;
}
V_52 -> V_59 . V_107 = V_113 ;
V_52 -> V_59 . V_25 = V_52 -> V_25 ;
V_52 -> V_59 . V_52 = V_52 ;
F_93 ( & V_52 -> V_59 . V_165 , & V_52 -> V_166 ) ;
#ifdef F_112
F_29 ( & V_52 -> V_59 , V_52 -> V_50 ) ;
#endif
#ifdef F_131
F_132 ( & V_52 -> V_116 , F_66 ) ;
#endif
if ( V_52 -> V_157 )
F_88 ( & V_52 -> V_59 , V_52 -> V_157 ,
V_52 -> V_158 ) ;
if ( V_52 -> V_160 ) {
V_14 = V_52 -> V_160 ( V_52 ) ;
if ( V_14 < 0 )
goto V_199;
}
for ( V_143 = V_148 ; V_143 <= V_149 ;
V_143 ++ ) {
for ( V_3 = 0 ; V_3 < V_52 -> V_73 ; V_3 ++ ) {
V_14 = F_107 ( V_52 , V_3 , V_143 ) ;
if ( V_14 < 0 ) {
F_51 ( V_52 -> V_25 ,
L_60 ,
V_14 ) ;
goto V_200;
}
}
}
for ( V_143 = V_148 ; V_143 <= V_149 ;
V_143 ++ ) {
for ( V_3 = 0 ; V_3 < V_52 -> V_73 ; V_3 ++ ) {
V_14 = F_111 ( V_52 , V_3 , V_143 ) ;
if ( V_14 < 0 ) {
F_51 ( V_52 -> V_25 ,
L_60 ,
V_14 ) ;
goto V_200;
}
}
}
for ( V_3 = 0 ; V_3 < V_52 -> V_196 ; V_3 ++ ) {
V_14 = F_124 ( V_52 , V_3 ) ;
if ( V_14 < 0 ) {
F_51 ( V_52 -> V_25 ,
L_61 ,
V_14 ) ;
goto V_201;
}
}
F_133 ( V_52 ) ;
F_134 ( V_52 ) ;
if ( V_52 -> V_161 )
F_135 ( V_52 , V_52 -> V_161 , V_52 -> V_162 ) ;
if ( V_52 -> V_163 )
F_92 ( & V_52 -> V_59 , V_52 -> V_163 ,
V_52 -> V_164 ) ;
for ( V_3 = 0 ; V_3 < V_52 -> V_73 ; V_3 ++ ) {
struct V_28 * V_29 = & V_52 -> V_29 [ V_3 ] ;
V_71 = & V_52 -> V_71 [ V_3 ] ;
V_192 = V_71 -> V_192 ;
if ( V_192 ) {
struct V_64 * * V_94 = V_29 -> V_94 ;
int V_87 ;
for ( V_87 = 0 ; V_87 < V_29 -> V_93 ; V_87 ++ ) {
struct V_64 * V_123 = V_94 [ V_87 ] ;
V_14 = F_136 ( V_123 , V_192 ) ;
if ( V_14 != 0 && V_14 != - V_202 )
F_26 ( V_123 -> V_25 ,
L_62 ,
V_14 ) ;
}
}
if ( V_192 &&
( V_71 -> V_133 || V_71 -> V_139 ) ) {
V_14 = F_136 ( V_52 -> V_29 [ V_3 ] . V_101 ,
V_192 ) ;
if ( V_14 != 0 && V_14 != - V_202 )
F_26 ( V_52 -> V_29 [ V_3 ] . V_101 -> V_25 ,
L_62 ,
V_14 ) ;
} else if ( V_192 ) {
V_192 &= ~ V_203 ;
switch ( V_71 -> V_192 &
V_203 ) {
case V_204 :
V_192 |= V_205 ;
break;
case V_206 :
V_192 |= V_207 ;
break;
case V_207 :
V_192 |= V_206 ;
break;
case V_205 :
V_192 |= V_204 ;
break;
}
V_14 = F_136 ( V_52 -> V_29 [ V_3 ] . V_101 ,
V_192 ) ;
if ( V_14 != 0 && V_14 != - V_202 )
F_26 ( V_52 -> V_29 [ V_3 ] . V_101 -> V_25 ,
L_62 ,
V_14 ) ;
}
}
snprintf ( V_52 -> V_83 -> V_208 , sizeof( V_52 -> V_83 -> V_208 ) ,
L_41 , V_52 -> V_54 ) ;
snprintf ( V_52 -> V_83 -> V_209 , sizeof( V_52 -> V_83 -> V_209 ) ,
L_41 , V_52 -> V_210 ? V_52 -> V_210 : V_52 -> V_54 ) ;
snprintf ( V_52 -> V_83 -> V_10 , sizeof( V_52 -> V_83 -> V_10 ) ,
L_41 , V_52 -> V_211 ? V_52 -> V_211 : V_52 -> V_54 ) ;
for ( V_3 = 0 ; V_3 < F_137 ( V_52 -> V_83 -> V_10 ) ; V_3 ++ ) {
switch ( V_52 -> V_83 -> V_10 [ V_3 ] ) {
case '_' :
case '-' :
case '\0' :
break;
default:
if ( ! isalnum ( V_52 -> V_83 -> V_10 [ V_3 ] ) )
V_52 -> V_83 -> V_10 [ V_3 ] = '_' ;
break;
}
}
if ( V_52 -> V_212 ) {
V_14 = V_52 -> V_212 ( V_52 ) ;
if ( V_14 < 0 ) {
F_51 ( V_52 -> V_25 , L_63 ,
V_52 -> V_54 , V_14 ) ;
goto V_201;
}
}
if ( V_52 -> V_213 )
F_138 ( V_52 ) ;
F_139 ( V_52 ) ;
V_14 = F_140 ( V_52 -> V_83 ) ;
if ( V_14 < 0 ) {
F_51 ( V_52 -> V_25 , L_64 ,
V_14 ) ;
goto V_201;
}
#ifdef F_141
for ( V_3 = 0 ; V_3 < V_52 -> V_91 ; V_3 ++ ) {
V_14 = F_120 ( & V_52 -> V_29 [ V_3 ] ) ;
if ( V_14 < 0 ) {
F_51 ( V_52 -> V_25 ,
L_65 , V_14 ) ;
while ( -- V_3 >= 0 )
F_121 ( & V_52 -> V_29 [ V_3 ] ) ;
goto V_201;
}
}
#endif
V_52 -> V_214 = 1 ;
F_63 ( & V_52 -> V_59 ) ;
F_142 ( & V_52 -> V_193 ) ;
return 0 ;
V_201:
for ( V_3 = 0 ; V_3 < V_52 -> V_196 ; V_3 ++ )
F_125 ( V_52 , V_3 ) ;
V_200:
F_84 ( V_52 ) ;
V_199:
if ( V_52 -> remove )
V_52 -> remove ( V_52 ) ;
F_143 ( V_52 -> V_83 ) ;
V_195:
F_142 ( & V_52 -> V_193 ) ;
return V_14 ;
}
static int F_144 ( struct V_215 * V_216 )
{
struct V_66 * V_52 = F_145 ( V_216 ) ;
if ( ! V_52 )
return - V_17 ;
F_26 ( & V_216 -> V_25 ,
L_66 ,
V_52 -> V_54 ) ;
V_52 -> V_25 = & V_216 -> V_25 ;
return F_146 ( V_52 ) ;
}
static int F_147 ( struct V_66 * V_52 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_52 -> V_91 ; V_3 ++ ) {
struct V_28 * V_29 = & V_52 -> V_29 [ V_3 ] ;
F_60 ( & V_29 -> V_105 ) ;
}
for ( V_3 = 0 ; V_3 < V_52 -> V_196 ; V_3 ++ )
F_125 ( V_52 , V_3 ) ;
F_84 ( V_52 ) ;
F_41 ( V_52 ) ;
if ( V_52 -> remove )
V_52 -> remove ( V_52 ) ;
F_76 ( & V_52 -> V_59 ) ;
F_143 ( V_52 -> V_83 ) ;
return 0 ;
}
static int F_148 ( struct V_215 * V_216 )
{
struct V_66 * V_52 = F_145 ( V_216 ) ;
F_149 ( V_52 ) ;
return 0 ;
}
int F_150 ( struct V_24 * V_25 )
{
struct V_66 * V_52 = F_8 ( V_25 ) ;
int V_3 ;
if ( ! V_52 -> V_214 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_52 -> V_91 ; V_3 ++ ) {
struct V_28 * V_29 = & V_52 -> V_29 [ V_3 ] ;
F_60 ( & V_29 -> V_105 ) ;
}
F_151 ( V_52 ) ;
for ( V_3 = 0 ; V_3 < V_52 -> V_91 ; V_3 ++ ) {
struct V_28 * V_29 = & V_52 -> V_29 [ V_3 ] ;
struct V_64 * V_101 = V_29 -> V_101 ;
int V_87 ;
F_65 ( V_101 -> V_25 ) ;
for ( V_87 = 0 ; V_87 < V_29 -> V_93 ; V_87 ++ ) {
struct V_64 * V_123 = V_29 -> V_94 [ V_87 ] ;
F_65 ( V_123 -> V_25 ) ;
}
}
return 0 ;
}
int F_152 ( struct V_4 * V_5 ,
struct V_217 * V_97 , int V_129 )
{
F_153 ( & V_5 -> V_193 ) ;
V_5 -> V_78 = F_98 ( sizeof( struct V_218 ) , V_36 ) ;
if ( V_5 -> V_78 == NULL ) {
F_142 ( & V_5 -> V_193 ) ;
return - V_37 ;
}
V_5 -> V_78 -> V_79 = F_98 ( sizeof( struct V_219 ) , V_36 ) ;
if ( V_5 -> V_78 -> V_79 == NULL ) {
F_15 ( V_5 -> V_78 ) ;
V_5 -> V_78 = NULL ;
F_142 ( & V_5 -> V_193 ) ;
return - V_37 ;
}
V_5 -> V_78 -> V_79 -> V_97 = V_97 ;
V_5 -> V_78 -> V_129 = V_129 ;
V_5 -> V_185 = 1 ;
F_142 ( & V_5 -> V_193 ) ;
return 0 ;
}
static void F_154 ( struct V_218 * V_78 )
{
struct V_220 * V_221 = V_222 . V_221 ;
F_155 ( V_221 , V_222 . V_223 ) ;
F_156 ( V_222 . V_224 , 1 ) ;
F_157 ( 10 ) ;
F_156 ( V_222 . V_224 , 0 ) ;
F_155 ( V_221 , V_222 . V_225 ) ;
F_158 ( 2 ) ;
}
static void F_159 ( struct V_218 * V_78 )
{
struct V_220 * V_221 = V_222 . V_221 ;
F_155 ( V_221 , V_222 . V_226 ) ;
F_156 ( V_222 . V_224 , 0 ) ;
F_156 ( V_222 . V_227 , 0 ) ;
F_156 ( V_222 . V_228 , 0 ) ;
F_157 ( 10 ) ;
F_156 ( V_222 . V_228 , 1 ) ;
F_155 ( V_221 , V_222 . V_225 ) ;
F_158 ( 2 ) ;
}
static int F_160 ( struct V_24 * V_25 ,
struct V_229 * V_230 )
{
struct V_220 * V_22 ;
struct V_231 * V_232 ;
int V_233 ;
int V_14 ;
V_22 = F_161 ( V_25 ) ;
if ( F_162 ( V_22 ) ) {
F_51 ( V_25 , L_67 ) ;
return F_163 ( V_22 ) ;
}
V_230 -> V_221 = V_22 ;
V_232 = F_164 ( V_22 , L_68 ) ;
if ( F_162 ( V_232 ) ) {
F_51 ( V_25 , L_69 ) ;
return F_163 ( V_232 ) ;
}
V_230 -> V_226 = V_232 ;
V_232 = F_164 ( V_22 , L_70 ) ;
if ( F_162 ( V_232 ) ) {
F_51 ( V_25 , L_71 ) ;
return F_163 ( V_232 ) ;
}
V_230 -> V_223 = V_232 ;
V_232 = F_164 ( V_22 , L_72 ) ;
if ( F_162 ( V_232 ) ) {
F_51 ( V_25 , L_73 ) ;
return F_163 ( V_232 ) ;
}
V_230 -> V_225 = V_232 ;
V_233 = F_165 ( V_25 -> V_127 , L_74 , 0 ) ;
if ( V_233 < 0 ) {
F_51 ( V_25 , L_75 ) ;
return V_233 ;
}
V_14 = F_166 ( V_25 , V_233 , L_76 ) ;
if ( V_14 ) {
F_51 ( V_25 , L_77 ) ;
return V_14 ;
}
V_230 -> V_224 = V_233 ;
V_233 = F_165 ( V_25 -> V_127 , L_74 , 1 ) ;
if ( V_233 < 0 ) {
F_51 ( V_25 , L_78 , V_233 ) ;
return V_233 ;
}
V_14 = F_166 ( V_25 , V_233 , L_79 ) ;
if ( V_14 ) {
F_51 ( V_25 , L_80 ) ;
return V_14 ;
}
V_230 -> V_227 = V_233 ;
V_233 = F_165 ( V_25 -> V_127 , L_74 , 2 ) ;
if ( V_233 < 0 ) {
F_51 ( V_25 , L_81 ) ;
return V_233 ;
}
V_14 = F_166 ( V_25 , V_233 , L_82 ) ;
if ( V_14 ) {
F_51 ( V_25 , L_83 ) ;
return V_14 ;
}
V_230 -> V_228 = V_233 ;
return 0 ;
}
int F_167 ( struct V_217 * V_97 )
{
if ( V_97 == V_234 )
return 0 ;
if ( V_234 && V_97 )
return - V_190 ;
V_234 = V_97 ;
return 0 ;
}
int F_168 ( struct V_217 * V_97 ,
struct V_215 * V_216 )
{
struct V_24 * V_25 = & V_216 -> V_25 ;
struct V_229 V_230 ;
int V_14 ;
V_14 = F_160 ( V_25 , & V_230 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_167 ( V_97 ) ;
if ( V_14 )
return V_14 ;
V_97 -> V_235 = F_154 ;
V_97 -> V_236 = F_159 ;
V_222 = V_230 ;
return 0 ;
}
void F_169 ( struct V_4 * V_5 )
{
F_153 ( & V_5 -> V_193 ) ;
#ifdef F_141
F_119 ( V_5 ) ;
#endif
F_15 ( V_5 -> V_78 -> V_79 ) ;
F_15 ( V_5 -> V_78 ) ;
V_5 -> V_78 = NULL ;
V_5 -> V_185 = 0 ;
F_142 ( & V_5 -> V_193 ) ;
}
struct V_237 * F_170 ( const struct V_238 * V_239 ,
void * V_240 , const char * V_210 ,
const char * V_241 )
{
struct V_238 V_242 ;
struct V_237 * V_243 ;
char * V_54 = NULL ;
memcpy ( & V_242 , V_239 , sizeof( V_242 ) ) ;
V_242 . V_244 = 0 ;
if ( ! V_210 )
V_210 = V_242 . V_54 ;
if ( V_241 ) {
V_54 = F_171 ( V_36 , L_84 , V_241 , V_210 ) ;
if ( ! V_54 )
return NULL ;
V_242 . V_54 = V_54 ;
} else {
V_242 . V_54 = V_210 ;
}
V_243 = F_172 ( & V_242 , V_240 ) ;
F_15 ( V_54 ) ;
return V_243 ;
}
static int F_173 ( struct V_83 * V_52 , struct V_24 * V_25 ,
const struct V_238 * V_161 , int V_162 ,
const char * V_241 , void * V_240 )
{
int V_80 , V_3 ;
for ( V_3 = 0 ; V_3 < V_162 ; V_3 ++ ) {
const struct V_238 * V_245 = & V_161 [ V_3 ] ;
V_80 = F_174 ( V_52 , F_170 ( V_245 , V_240 ,
V_245 -> V_54 , V_241 ) ) ;
if ( V_80 < 0 ) {
F_51 ( V_25 , L_85 ,
V_245 -> V_54 , V_80 ) ;
return V_80 ;
}
}
return 0 ;
}
struct V_237 * F_175 ( struct V_66 * V_246 ,
const char * V_54 )
{
struct V_83 * V_52 = V_246 -> V_83 ;
struct V_237 * V_247 ;
if ( F_176 ( ! V_54 ) )
return NULL ;
F_35 (kctl, &card->controls, list)
if ( ! strncmp ( V_247 -> V_248 . V_54 , V_54 , sizeof( V_247 -> V_248 . V_54 ) ) )
return V_247 ;
return NULL ;
}
int F_177 ( struct V_63 * V_51 ,
const struct V_238 * V_161 , unsigned int V_162 )
{
struct V_83 * V_52 = V_51 -> V_52 -> V_83 ;
return F_173 ( V_52 , V_51 -> V_25 , V_161 ,
V_162 , V_51 -> V_154 , V_51 ) ;
}
int F_91 ( struct V_4 * V_5 ,
const struct V_238 * V_161 , unsigned int V_162 )
{
return F_177 ( & V_5 -> V_51 , V_161 ,
V_162 ) ;
}
int F_95 ( struct V_60 * V_61 ,
const struct V_238 * V_161 , unsigned int V_162 )
{
return F_177 ( & V_61 -> V_51 , V_161 ,
V_162 ) ;
}
int F_135 ( struct V_66 * V_246 ,
const struct V_238 * V_161 , int V_162 )
{
struct V_83 * V_52 = V_246 -> V_83 ;
return F_173 ( V_52 , V_246 -> V_25 , V_161 , V_162 ,
NULL , V_246 ) ;
}
int F_178 ( struct V_64 * V_65 ,
const struct V_238 * V_161 , int V_162 )
{
struct V_83 * V_52 = V_65 -> V_52 -> V_83 ;
return F_173 ( V_52 , V_65 -> V_25 , V_161 , V_162 ,
NULL , V_65 ) ;
}
int F_179 ( struct V_237 * V_243 ,
struct V_249 * V_250 )
{
struct V_251 * V_252 = (struct V_251 * ) V_243 -> V_253 ;
V_250 -> type = V_254 ;
V_250 -> V_18 = V_252 -> V_255 == V_252 -> V_256 ? 1 : 2 ;
V_250 -> V_41 . V_257 . V_258 = V_252 -> V_258 ;
if ( V_250 -> V_41 . V_257 . V_259 >= V_252 -> V_258 )
V_250 -> V_41 . V_257 . V_259 = V_252 -> V_258 - 1 ;
F_180 ( V_250 -> V_41 . V_257 . V_54 ,
V_252 -> V_260 [ V_250 -> V_41 . V_257 . V_259 ] ,
sizeof( V_250 -> V_41 . V_257 . V_54 ) ) ;
return 0 ;
}
int F_181 ( struct V_237 * V_243 ,
struct V_261 * V_262 )
{
struct V_63 * V_51 = F_182 ( V_243 ) ;
struct V_251 * V_252 = (struct V_251 * ) V_243 -> V_253 ;
unsigned int V_1 , V_259 ;
unsigned int V_263 ;
int V_14 ;
V_14 = F_183 ( V_51 , V_252 -> V_6 , & V_263 ) ;
if ( V_14 )
return V_14 ;
V_1 = ( V_263 >> V_252 -> V_255 ) & V_252 -> V_264 ;
V_259 = F_184 ( V_252 , V_1 ) ;
V_262 -> V_41 . V_257 . V_259 [ 0 ] = V_259 ;
if ( V_252 -> V_255 != V_252 -> V_256 ) {
V_1 = ( V_263 >> V_252 -> V_255 ) & V_252 -> V_264 ;
V_259 = F_184 ( V_252 , V_1 ) ;
V_262 -> V_41 . V_257 . V_259 [ 1 ] = V_259 ;
}
return 0 ;
}
int F_185 ( struct V_237 * V_243 ,
struct V_261 * V_262 )
{
struct V_63 * V_51 = F_182 ( V_243 ) ;
struct V_251 * V_252 = (struct V_251 * ) V_243 -> V_253 ;
unsigned int * V_259 = V_262 -> V_41 . V_257 . V_259 ;
unsigned int V_1 ;
unsigned int V_264 ;
if ( V_259 [ 0 ] >= V_252 -> V_258 )
return - V_17 ;
V_1 = F_186 ( V_252 , V_259 [ 0 ] ) << V_252 -> V_255 ;
V_264 = V_252 -> V_264 << V_252 -> V_255 ;
if ( V_252 -> V_255 != V_252 -> V_256 ) {
if ( V_259 [ 1 ] >= V_252 -> V_258 )
return - V_17 ;
V_1 |= F_186 ( V_252 , V_259 [ 1 ] ) << V_252 -> V_256 ;
V_264 |= V_252 -> V_264 << V_252 -> V_256 ;
}
return F_187 ( V_51 , V_252 -> V_6 , V_264 , V_1 ) ;
}
static int F_188 ( struct V_63 * V_51 ,
unsigned int V_6 , unsigned int V_264 , unsigned int V_265 ,
unsigned int V_266 , int * V_267 )
{
int V_14 ;
unsigned int V_1 ;
V_14 = F_183 ( V_51 , V_6 , & V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
V_1 = ( V_1 >> V_265 ) & V_264 ;
if ( ! V_266 ) {
* V_267 = V_1 ;
return 0 ;
}
if ( ! ( V_1 & F_189 ( V_266 ) ) ) {
* V_267 = V_1 ;
return 0 ;
}
V_14 = V_1 ;
V_14 |= ~ ( ( int ) ( F_189 ( V_266 ) - 1 ) ) ;
* V_267 = V_14 ;
return 0 ;
}
int F_190 ( struct V_237 * V_243 ,
struct V_249 * V_250 )
{
struct V_268 * V_269 =
(struct V_268 * ) V_243 -> V_253 ;
int V_270 ;
if ( ! V_269 -> V_270 )
V_269 -> V_270 = V_269 -> V_271 ;
V_270 = V_269 -> V_270 ;
if ( V_270 == 1 && ! strstr ( V_243 -> V_248 . V_54 , L_86 ) )
V_250 -> type = V_272 ;
else
V_250 -> type = V_273 ;
V_250 -> V_18 = F_191 ( V_269 ) ? 2 : 1 ;
V_250 -> V_41 . integer . F_6 = 0 ;
V_250 -> V_41 . integer . V_271 = V_270 - V_269 -> F_6 ;
return 0 ;
}
int F_192 ( struct V_237 * V_243 ,
struct V_261 * V_262 )
{
struct V_63 * V_51 = F_182 ( V_243 ) ;
struct V_268 * V_269 =
(struct V_268 * ) V_243 -> V_253 ;
unsigned int V_6 = V_269 -> V_6 ;
unsigned int V_274 = V_269 -> V_275 ;
unsigned int V_265 = V_269 -> V_265 ;
unsigned int V_276 = V_269 -> V_276 ;
int V_271 = V_269 -> V_271 ;
int F_6 = V_269 -> F_6 ;
int V_266 = V_269 -> V_266 ;
unsigned int V_264 = ( 1 << F_193 ( V_271 ) ) - 1 ;
unsigned int V_277 = V_269 -> V_277 ;
int V_1 ;
int V_14 ;
if ( V_266 )
V_264 = F_189 ( V_266 + 1 ) - 1 ;
V_14 = F_188 ( V_51 , V_6 , V_264 , V_265 , V_266 , & V_1 ) ;
if ( V_14 )
return V_14 ;
V_262 -> V_41 . integer . V_41 [ 0 ] = V_1 - F_6 ;
if ( V_277 )
V_262 -> V_41 . integer . V_41 [ 0 ] =
V_271 - V_262 -> V_41 . integer . V_41 [ 0 ] ;
if ( F_191 ( V_269 ) ) {
if ( V_6 == V_274 )
V_14 = F_188 ( V_51 , V_6 , V_264 , V_276 ,
V_266 , & V_1 ) ;
else
V_14 = F_188 ( V_51 , V_274 , V_264 , V_265 ,
V_266 , & V_1 ) ;
if ( V_14 )
return V_14 ;
V_262 -> V_41 . integer . V_41 [ 1 ] = V_1 - F_6 ;
if ( V_277 )
V_262 -> V_41 . integer . V_41 [ 1 ] =
V_271 - V_262 -> V_41 . integer . V_41 [ 1 ] ;
}
return 0 ;
}
int F_194 ( struct V_237 * V_243 ,
struct V_261 * V_262 )
{
struct V_63 * V_51 = F_182 ( V_243 ) ;
struct V_268 * V_269 =
(struct V_268 * ) V_243 -> V_253 ;
unsigned int V_6 = V_269 -> V_6 ;
unsigned int V_274 = V_269 -> V_275 ;
unsigned int V_265 = V_269 -> V_265 ;
unsigned int V_276 = V_269 -> V_276 ;
int V_271 = V_269 -> V_271 ;
int F_6 = V_269 -> F_6 ;
unsigned int V_266 = V_269 -> V_266 ;
unsigned int V_264 = ( 1 << F_193 ( V_271 ) ) - 1 ;
unsigned int V_277 = V_269 -> V_277 ;
int V_80 ;
bool V_278 = false ;
unsigned int V_279 = 0 ;
unsigned int V_1 , V_280 ;
if ( V_266 )
V_264 = F_189 ( V_266 + 1 ) - 1 ;
V_1 = ( ( V_262 -> V_41 . integer . V_41 [ 0 ] + F_6 ) & V_264 ) ;
if ( V_277 )
V_1 = V_271 - V_1 ;
V_280 = V_264 << V_265 ;
V_1 = V_1 << V_265 ;
if ( F_191 ( V_269 ) ) {
V_279 = ( ( V_262 -> V_41 . integer . V_41 [ 1 ] + F_6 ) & V_264 ) ;
if ( V_277 )
V_279 = V_271 - V_279 ;
if ( V_6 == V_274 ) {
V_280 |= V_264 << V_276 ;
V_1 |= V_279 << V_276 ;
} else {
V_279 = V_279 << V_265 ;
V_278 = true ;
}
}
V_80 = F_187 ( V_51 , V_6 , V_280 , V_1 ) ;
if ( V_80 < 0 )
return V_80 ;
if ( V_278 )
V_80 = F_187 ( V_51 , V_274 , V_280 ,
V_279 ) ;
return V_80 ;
}
int F_195 ( struct V_237 * V_243 ,
struct V_261 * V_262 )
{
struct V_63 * V_51 = F_182 ( V_243 ) ;
struct V_268 * V_269 =
(struct V_268 * ) V_243 -> V_253 ;
unsigned int V_6 = V_269 -> V_6 ;
unsigned int V_274 = V_269 -> V_275 ;
unsigned int V_265 = V_269 -> V_265 ;
unsigned int V_276 = V_269 -> V_276 ;
int V_271 = V_269 -> V_271 ;
int F_6 = V_269 -> F_6 ;
int V_264 = ( 1 << ( F_193 ( F_6 + V_271 ) - 1 ) ) - 1 ;
unsigned int V_1 ;
int V_14 ;
V_14 = F_183 ( V_51 , V_6 , & V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
V_262 -> V_41 . integer . V_41 [ 0 ] = ( ( V_1 >> V_265 ) - F_6 ) & V_264 ;
if ( F_191 ( V_269 ) ) {
V_14 = F_183 ( V_51 , V_274 , & V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
V_1 = ( ( V_1 >> V_276 ) - F_6 ) & V_264 ;
V_262 -> V_41 . integer . V_41 [ 1 ] = V_1 ;
}
return 0 ;
}
int F_196 ( struct V_237 * V_243 ,
struct V_261 * V_262 )
{
struct V_63 * V_51 = F_182 ( V_243 ) ;
struct V_268 * V_269 =
(struct V_268 * ) V_243 -> V_253 ;
unsigned int V_6 = V_269 -> V_6 ;
unsigned int V_274 = V_269 -> V_275 ;
unsigned int V_265 = V_269 -> V_265 ;
unsigned int V_276 = V_269 -> V_276 ;
int V_271 = V_269 -> V_271 ;
int F_6 = V_269 -> F_6 ;
int V_264 = ( 1 << ( F_193 ( F_6 + V_271 ) - 1 ) ) - 1 ;
int V_80 = 0 ;
unsigned int V_1 , V_280 , V_279 = 0 ;
V_280 = V_264 << V_265 ;
V_1 = ( V_262 -> V_41 . integer . V_41 [ 0 ] + F_6 ) & V_264 ;
V_1 = V_1 << V_265 ;
V_80 = F_187 ( V_51 , V_6 , V_280 , V_1 ) ;
if ( V_80 < 0 )
return V_80 ;
if ( F_191 ( V_269 ) ) {
V_280 = V_264 << V_276 ;
V_279 = ( V_262 -> V_41 . integer . V_41 [ 1 ] + F_6 ) & V_264 ;
V_279 = V_279 << V_276 ;
V_80 = F_187 ( V_51 , V_274 , V_280 ,
V_279 ) ;
}
return V_80 ;
}
int F_197 ( struct V_237 * V_243 ,
struct V_249 * V_250 )
{
struct V_268 * V_269 =
(struct V_268 * ) V_243 -> V_253 ;
int V_270 ;
int F_6 = V_269 -> F_6 ;
if ( ! V_269 -> V_270 )
V_269 -> V_270 = V_269 -> V_271 ;
V_270 = V_269 -> V_270 ;
V_250 -> type = V_273 ;
V_250 -> V_18 = 2 ;
V_250 -> V_41 . integer . F_6 = 0 ;
V_250 -> V_41 . integer . V_271 = V_270 - F_6 ;
return 0 ;
}
int F_198 ( struct V_237 * V_243 ,
struct V_261 * V_262 )
{
struct V_268 * V_269 =
(struct V_268 * ) V_243 -> V_253 ;
struct V_63 * V_51 = F_182 ( V_243 ) ;
unsigned int V_6 = V_269 -> V_6 ;
unsigned int V_1 ;
int F_6 = V_269 -> F_6 ;
int V_14 ;
V_14 = F_183 ( V_51 , V_6 , & V_1 ) ;
if ( V_14 )
return V_14 ;
V_262 -> V_41 . integer . V_41 [ 0 ] =
( ( signed char ) ( V_1 & 0xff ) ) - F_6 ;
V_262 -> V_41 . integer . V_41 [ 1 ] =
( ( signed char ) ( ( V_1 >> 8 ) & 0xff ) ) - F_6 ;
return 0 ;
}
int F_199 ( struct V_237 * V_243 ,
struct V_261 * V_262 )
{
struct V_268 * V_269 =
(struct V_268 * ) V_243 -> V_253 ;
struct V_63 * V_51 = F_182 ( V_243 ) ;
unsigned int V_6 = V_269 -> V_6 ;
int F_6 = V_269 -> F_6 ;
unsigned int V_1 ;
V_1 = ( V_262 -> V_41 . integer . V_41 [ 0 ] + F_6 ) & 0xff ;
V_1 |= ( ( V_262 -> V_41 . integer . V_41 [ 1 ] + F_6 ) & 0xff ) << 8 ;
return F_187 ( V_51 , V_6 , 0xffff , V_1 ) ;
}
int F_200 ( struct V_237 * V_243 ,
struct V_249 * V_250 )
{
struct V_268 * V_269 =
(struct V_268 * ) V_243 -> V_253 ;
int V_270 ;
int F_6 = V_269 -> F_6 ;
if ( ! V_269 -> V_270 )
V_269 -> V_270 = V_269 -> V_271 ;
V_270 = V_269 -> V_270 ;
V_250 -> type = V_273 ;
V_250 -> V_18 = F_191 ( V_269 ) ? 2 : 1 ;
V_250 -> V_41 . integer . F_6 = 0 ;
V_250 -> V_41 . integer . V_271 = V_270 - F_6 ;
return 0 ;
}
int F_201 ( struct V_237 * V_243 ,
struct V_261 * V_262 )
{
struct V_268 * V_269 =
(struct V_268 * ) V_243 -> V_253 ;
struct V_63 * V_51 = F_182 ( V_243 ) ;
unsigned int V_6 = V_269 -> V_6 ;
unsigned int V_275 = V_269 -> V_275 ;
unsigned int V_265 = V_269 -> V_265 ;
int F_6 = V_269 -> F_6 ;
int V_271 = V_269 -> V_271 ;
unsigned int V_264 = ( 1 << F_193 ( V_271 ) ) - 1 ;
unsigned int V_277 = V_269 -> V_277 ;
unsigned int V_1 , V_280 ;
int V_14 ;
V_1 = ( ( V_262 -> V_41 . integer . V_41 [ 0 ] + F_6 ) & V_264 ) ;
if ( V_277 )
V_1 = V_271 - V_1 ;
V_280 = V_264 << V_265 ;
V_1 = V_1 << V_265 ;
V_14 = F_187 ( V_51 , V_6 , V_280 , V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( F_191 ( V_269 ) ) {
V_1 = ( ( V_262 -> V_41 . integer . V_41 [ 1 ] + F_6 ) & V_264 ) ;
if ( V_277 )
V_1 = V_271 - V_1 ;
V_280 = V_264 << V_265 ;
V_1 = V_1 << V_265 ;
V_14 = F_187 ( V_51 , V_275 , V_280 ,
V_1 ) ;
}
return V_14 ;
}
int F_202 ( struct V_237 * V_243 ,
struct V_261 * V_262 )
{
struct V_63 * V_51 = F_182 ( V_243 ) ;
struct V_268 * V_269 =
(struct V_268 * ) V_243 -> V_253 ;
unsigned int V_6 = V_269 -> V_6 ;
unsigned int V_275 = V_269 -> V_275 ;
unsigned int V_265 = V_269 -> V_265 ;
int F_6 = V_269 -> F_6 ;
int V_271 = V_269 -> V_271 ;
unsigned int V_264 = ( 1 << F_193 ( V_271 ) ) - 1 ;
unsigned int V_277 = V_269 -> V_277 ;
unsigned int V_1 ;
int V_14 ;
V_14 = F_183 ( V_51 , V_6 , & V_1 ) ;
if ( V_14 )
return V_14 ;
V_262 -> V_41 . integer . V_41 [ 0 ] = ( V_1 >> V_265 ) & V_264 ;
if ( V_277 )
V_262 -> V_41 . integer . V_41 [ 0 ] =
V_271 - V_262 -> V_41 . integer . V_41 [ 0 ] ;
V_262 -> V_41 . integer . V_41 [ 0 ] =
V_262 -> V_41 . integer . V_41 [ 0 ] - F_6 ;
if ( F_191 ( V_269 ) ) {
V_14 = F_183 ( V_51 , V_275 , & V_1 ) ;
if ( V_14 )
return V_14 ;
V_262 -> V_41 . integer . V_41 [ 1 ] = ( V_1 >> V_265 ) & V_264 ;
if ( V_277 )
V_262 -> V_41 . integer . V_41 [ 1 ] =
V_271 - V_262 -> V_41 . integer . V_41 [ 1 ] ;
V_262 -> V_41 . integer . V_41 [ 1 ] =
V_262 -> V_41 . integer . V_41 [ 1 ] - F_6 ;
}
return 0 ;
}
int F_203 ( struct V_4 * V_5 ,
const char * V_54 , int V_271 )
{
struct V_83 * V_52 = V_5 -> V_51 . V_52 -> V_83 ;
struct V_237 * V_247 ;
struct V_268 * V_269 ;
int V_281 = 0 ;
int V_14 = - V_17 ;
if ( F_176 ( ! V_54 || V_271 <= 0 ) )
return - V_17 ;
F_35 (kctl, &card->controls, list) {
if ( ! strncmp ( V_247 -> V_248 . V_54 , V_54 , sizeof( V_247 -> V_248 . V_54 ) ) ) {
V_281 = 1 ;
break;
}
}
if ( V_281 ) {
V_269 = (struct V_268 * ) V_247 -> V_253 ;
if ( V_271 <= V_269 -> V_271 ) {
V_269 -> V_270 = V_271 ;
V_14 = 0 ;
}
}
return V_14 ;
}
int F_204 ( struct V_237 * V_243 ,
struct V_249 * V_250 )
{
struct V_63 * V_51 = F_182 ( V_243 ) ;
struct V_282 * V_178 = ( void * ) V_243 -> V_253 ;
V_250 -> type = V_283 ;
V_250 -> V_18 = V_178 -> V_284 * V_51 -> V_285 ;
return 0 ;
}
int F_205 ( struct V_237 * V_243 ,
struct V_261 * V_262 )
{
struct V_63 * V_51 = F_182 ( V_243 ) ;
struct V_282 * V_178 = ( void * ) V_243 -> V_253 ;
int V_14 ;
if ( V_51 -> V_114 )
V_14 = F_206 ( V_51 -> V_114 , V_178 -> V_286 ,
V_262 -> V_41 . V_287 . V_240 ,
V_178 -> V_284 * V_51 -> V_285 ) ;
else
V_14 = - V_17 ;
if ( V_14 == 0 && V_178 -> V_264 ) {
switch ( V_51 -> V_285 ) {
case 1 :
V_262 -> V_41 . V_287 . V_240 [ 0 ] &= ~ V_178 -> V_264 ;
break;
case 2 :
( ( V_288 * ) ( & V_262 -> V_41 . V_287 . V_240 ) ) [ 0 ]
&= F_207 ( ~ V_178 -> V_264 ) ;
break;
case 4 :
( ( V_289 * ) ( & V_262 -> V_41 . V_287 . V_240 ) ) [ 0 ]
&= F_208 ( ~ V_178 -> V_264 ) ;
break;
default:
return - V_17 ;
}
}
return V_14 ;
}
int F_209 ( struct V_237 * V_243 ,
struct V_261 * V_262 )
{
struct V_63 * V_51 = F_182 ( V_243 ) ;
struct V_282 * V_178 = ( void * ) V_243 -> V_253 ;
int V_14 , V_8 ;
unsigned int V_1 , V_264 ;
void * V_240 ;
if ( ! V_51 -> V_114 || ! V_178 -> V_284 )
return - V_17 ;
V_8 = V_178 -> V_284 * V_51 -> V_285 ;
V_240 = F_210 ( V_262 -> V_41 . V_287 . V_240 , V_8 , V_36 | V_290 ) ;
if ( ! V_240 )
return - V_37 ;
if ( V_178 -> V_264 ) {
V_14 = F_211 ( V_51 -> V_114 , V_178 -> V_286 , & V_1 ) ;
if ( V_14 != 0 )
goto V_291;
V_1 &= V_178 -> V_264 ;
switch ( V_51 -> V_285 ) {
case 1 :
( ( V_292 * ) V_240 ) [ 0 ] &= ~ V_178 -> V_264 ;
( ( V_292 * ) V_240 ) [ 0 ] |= V_1 ;
break;
case 2 :
V_264 = ~ V_178 -> V_264 ;
V_14 = F_212 ( V_51 -> V_114 ,
& V_264 , & V_264 ) ;
if ( V_14 != 0 )
goto V_291;
( ( V_288 * ) V_240 ) [ 0 ] &= V_264 ;
V_14 = F_212 ( V_51 -> V_114 ,
& V_1 , & V_1 ) ;
if ( V_14 != 0 )
goto V_291;
( ( V_288 * ) V_240 ) [ 0 ] |= V_1 ;
break;
case 4 :
V_264 = ~ V_178 -> V_264 ;
V_14 = F_212 ( V_51 -> V_114 ,
& V_264 , & V_264 ) ;
if ( V_14 != 0 )
goto V_291;
( ( V_289 * ) V_240 ) [ 0 ] &= V_264 ;
V_14 = F_212 ( V_51 -> V_114 ,
& V_1 , & V_1 ) ;
if ( V_14 != 0 )
goto V_291;
( ( V_289 * ) V_240 ) [ 0 ] |= V_1 ;
break;
default:
V_14 = - V_17 ;
goto V_291;
}
}
V_14 = F_213 ( V_51 -> V_114 , V_178 -> V_286 ,
V_240 , V_8 ) ;
V_291:
F_15 ( V_240 ) ;
return V_14 ;
}
int F_214 ( struct V_237 * V_243 ,
struct V_249 * V_262 )
{
struct V_293 * V_178 = ( void * ) V_243 -> V_253 ;
V_262 -> type = V_283 ;
V_262 -> V_18 = V_178 -> V_271 ;
return 0 ;
}
int F_215 ( struct V_237 * V_243 , int V_294 ,
unsigned int V_295 , unsigned int T_4 * V_296 )
{
struct V_293 * V_178 = ( void * ) V_243 -> V_253 ;
unsigned int V_18 = V_295 < V_178 -> V_271 ? V_295 : V_178 -> V_271 ;
int V_14 = - V_297 ;
switch ( V_294 ) {
case V_298 :
if ( V_178 -> V_299 )
V_14 = V_178 -> V_299 ( V_296 , V_18 ) ;
break;
case V_300 :
if ( V_178 -> V_301 )
V_14 = V_178 -> V_301 ( V_296 , V_18 ) ;
break;
}
return V_14 ;
}
int F_216 ( struct V_237 * V_243 ,
struct V_249 * V_250 )
{
struct V_302 * V_269 =
(struct V_302 * ) V_243 -> V_253 ;
V_250 -> type = V_273 ;
V_250 -> V_18 = 1 ;
V_250 -> V_41 . integer . F_6 = V_269 -> F_6 ;
V_250 -> V_41 . integer . V_271 = V_269 -> V_271 ;
return 0 ;
}
int F_217 ( struct V_237 * V_243 ,
struct V_261 * V_262 )
{
struct V_63 * V_51 = F_182 ( V_243 ) ;
struct V_302 * V_269 =
(struct V_302 * ) V_243 -> V_253 ;
unsigned int V_303 = V_269 -> V_303 ;
unsigned int V_304 = V_269 -> V_304 ;
unsigned int V_305 = V_51 -> V_285 * V_306 ;
unsigned int V_307 = ( 1 << V_305 ) - 1 ;
unsigned int V_277 = V_269 -> V_277 ;
unsigned long V_264 = ( 1UL << V_269 -> V_308 ) - 1 ;
long F_6 = V_269 -> F_6 ;
long V_271 = V_269 -> V_271 ;
long V_1 = 0 ;
unsigned int V_309 ;
unsigned int V_3 ;
int V_14 ;
for ( V_3 = 0 ; V_3 < V_304 ; V_3 ++ ) {
V_14 = F_183 ( V_51 , V_303 + V_3 , & V_309 ) ;
if ( V_14 )
return V_14 ;
V_1 |= ( V_309 & V_307 ) << ( V_305 * ( V_304 - V_3 - 1 ) ) ;
}
V_1 &= V_264 ;
if ( F_6 < 0 && V_1 > V_271 )
V_1 |= ~ V_264 ;
if ( V_277 )
V_1 = V_271 - V_1 ;
V_262 -> V_41 . integer . V_41 [ 0 ] = V_1 ;
return 0 ;
}
int F_218 ( struct V_237 * V_243 ,
struct V_261 * V_262 )
{
struct V_63 * V_51 = F_182 ( V_243 ) ;
struct V_302 * V_269 =
(struct V_302 * ) V_243 -> V_253 ;
unsigned int V_303 = V_269 -> V_303 ;
unsigned int V_304 = V_269 -> V_304 ;
unsigned int V_305 = V_51 -> V_285 * V_306 ;
unsigned int V_307 = ( 1 << V_305 ) - 1 ;
unsigned int V_277 = V_269 -> V_277 ;
unsigned long V_264 = ( 1UL << V_269 -> V_308 ) - 1 ;
long V_271 = V_269 -> V_271 ;
long V_1 = V_262 -> V_41 . integer . V_41 [ 0 ] ;
unsigned int V_3 , V_309 , V_310 ;
int V_80 ;
if ( V_277 )
V_1 = V_271 - V_1 ;
V_1 &= V_264 ;
for ( V_3 = 0 ; V_3 < V_304 ; V_3 ++ ) {
V_309 = ( V_1 >> ( V_305 * ( V_304 - V_3 - 1 ) ) ) & V_307 ;
V_310 = ( V_264 >> ( V_305 * ( V_304 - V_3 - 1 ) ) ) & V_307 ;
V_80 = F_187 ( V_51 , V_303 + V_3 ,
V_310 , V_309 ) ;
if ( V_80 < 0 )
return V_80 ;
}
return 0 ;
}
int F_219 ( struct V_237 * V_243 ,
struct V_261 * V_262 )
{
struct V_63 * V_51 = F_182 ( V_243 ) ;
struct V_268 * V_269 =
(struct V_268 * ) V_243 -> V_253 ;
unsigned int V_6 = V_269 -> V_6 ;
unsigned int V_265 = V_269 -> V_265 ;
unsigned int V_264 = 1 << V_265 ;
unsigned int V_277 = V_269 -> V_277 != 0 ;
unsigned int V_1 ;
int V_14 ;
V_14 = F_183 ( V_51 , V_6 , & V_1 ) ;
if ( V_14 )
return V_14 ;
V_1 &= V_264 ;
if ( V_265 != 0 && V_1 != 0 )
V_1 = V_1 >> V_265 ;
V_262 -> V_41 . V_257 . V_259 [ 0 ] = V_1 ^ V_277 ;
return 0 ;
}
int F_220 ( struct V_237 * V_243 ,
struct V_261 * V_262 )
{
struct V_63 * V_51 = F_182 ( V_243 ) ;
struct V_268 * V_269 =
(struct V_268 * ) V_243 -> V_253 ;
unsigned int V_6 = V_269 -> V_6 ;
unsigned int V_265 = V_269 -> V_265 ;
unsigned int V_264 = 1 << V_265 ;
unsigned int V_277 = V_269 -> V_277 != 0 ;
unsigned int V_311 = V_262 -> V_41 . V_257 . V_259 [ 0 ] != 0 ;
unsigned int V_312 = ( V_311 ^ V_277 ) ? V_264 : 0 ;
unsigned int V_279 = ( V_311 ^ V_277 ) ? 0 : V_264 ;
int V_80 ;
V_80 = F_187 ( V_51 , V_6 , V_264 , V_312 ) ;
if ( V_80 < 0 )
return V_80 ;
return F_187 ( V_51 , V_6 , V_264 , V_279 ) ;
}
int F_221 ( struct V_64 * V_65 , int V_313 ,
unsigned int V_314 , int V_315 )
{
if ( V_65 -> V_10 && V_65 -> V_10 -> V_97 -> V_316 )
return V_65 -> V_10 -> V_97 -> V_316 ( V_65 , V_313 , V_314 , V_315 ) ;
else if ( V_65 -> V_5 && V_65 -> V_5 -> V_10 -> V_316 )
return V_65 -> V_5 -> V_10 -> V_316 ( V_65 -> V_5 , V_313 , 0 ,
V_314 , V_315 ) ;
else
return - V_202 ;
}
int F_222 ( struct V_4 * V_5 , int V_313 ,
int V_317 , unsigned int V_314 , int V_315 )
{
if ( V_5 -> V_10 -> V_316 )
return V_5 -> V_10 -> V_316 ( V_5 , V_313 , V_317 ,
V_314 , V_315 ) ;
else
return - V_202 ;
}
int F_223 ( struct V_64 * V_65 ,
int V_318 , int div )
{
if ( V_65 -> V_10 && V_65 -> V_10 -> V_97 -> V_319 )
return V_65 -> V_10 -> V_97 -> V_319 ( V_65 , V_318 , div ) ;
else
return - V_17 ;
}
int F_224 ( struct V_64 * V_65 , int V_320 , int V_317 ,
unsigned int V_321 , unsigned int V_322 )
{
if ( V_65 -> V_10 && V_65 -> V_10 -> V_97 -> V_323 )
return V_65 -> V_10 -> V_97 -> V_323 ( V_65 , V_320 , V_317 ,
V_321 , V_322 ) ;
else if ( V_65 -> V_5 && V_65 -> V_5 -> V_10 -> V_323 )
return V_65 -> V_5 -> V_10 -> V_323 ( V_65 -> V_5 , V_320 , V_317 ,
V_321 , V_322 ) ;
else
return - V_17 ;
}
int F_225 ( struct V_4 * V_5 , int V_320 , int V_317 ,
unsigned int V_321 , unsigned int V_322 )
{
if ( V_5 -> V_10 -> V_323 )
return V_5 -> V_10 -> V_323 ( V_5 , V_320 , V_317 ,
V_321 , V_322 ) ;
else
return - V_17 ;
}
int F_226 ( struct V_64 * V_65 , unsigned int V_324 )
{
if ( V_65 -> V_10 && V_65 -> V_10 -> V_97 -> V_325 )
return V_65 -> V_10 -> V_97 -> V_325 ( V_65 , V_324 ) ;
else
return - V_17 ;
}
int F_136 ( struct V_64 * V_65 , unsigned int V_46 )
{
if ( V_65 -> V_10 == NULL )
return - V_17 ;
if ( V_65 -> V_10 -> V_97 -> V_326 == NULL )
return - V_202 ;
return V_65 -> V_10 -> V_97 -> V_326 ( V_65 , V_46 ) ;
}
static int F_227 ( unsigned int V_327 ,
unsigned int * V_328 ,
unsigned int * V_329 )
{
if ( * V_328 || * V_329 )
return 0 ;
if ( ! V_327 )
return - V_17 ;
* V_328 = ( 1 << V_327 ) - 1 ;
* V_329 = ( 1 << V_327 ) - 1 ;
return 0 ;
}
int F_228 ( struct V_64 * V_65 ,
unsigned int V_328 , unsigned int V_329 , int V_327 , int V_330 )
{
if ( V_65 -> V_10 && V_65 -> V_10 -> V_97 -> V_331 )
V_65 -> V_10 -> V_97 -> V_331 ( V_327 ,
& V_328 , & V_329 ) ;
else
F_227 ( V_327 , & V_328 , & V_329 ) ;
V_65 -> V_328 = V_328 ;
V_65 -> V_329 = V_329 ;
if ( V_65 -> V_10 && V_65 -> V_10 -> V_97 -> V_332 )
return V_65 -> V_10 -> V_97 -> V_332 ( V_65 , V_328 , V_329 ,
V_327 , V_330 ) ;
else
return - V_202 ;
}
int F_229 ( struct V_64 * V_65 ,
unsigned int V_333 , unsigned int * V_334 ,
unsigned int V_335 , unsigned int * V_336 )
{
if ( V_65 -> V_10 && V_65 -> V_10 -> V_97 -> V_337 )
return V_65 -> V_10 -> V_97 -> V_337 ( V_65 , V_333 , V_334 ,
V_335 , V_336 ) ;
else
return - V_17 ;
}
int F_230 ( struct V_64 * V_65 , int V_338 )
{
if ( V_65 -> V_10 && V_65 -> V_10 -> V_97 -> V_339 )
return V_65 -> V_10 -> V_97 -> V_339 ( V_65 , V_338 ) ;
else
return - V_17 ;
}
int F_231 ( struct V_64 * V_65 , int V_340 ,
int V_341 )
{
if ( ! V_65 -> V_10 )
return - V_202 ;
if ( V_65 -> V_10 -> V_97 -> V_342 )
return V_65 -> V_10 -> V_97 -> V_342 ( V_65 , V_340 , V_341 ) ;
else if ( V_341 == V_108 &&
V_65 -> V_10 -> V_97 -> V_98 )
return V_65 -> V_10 -> V_97 -> V_98 ( V_65 , V_340 ) ;
else
return - V_202 ;
}
static int F_232 ( struct V_66 * V_52 ,
struct V_130 * V_71 )
{
if ( V_71 -> V_126 || V_71 -> V_125 ||
V_71 -> V_128 ) {
V_71 -> V_93 = 1 ;
V_71 -> V_132 = F_233 ( V_52 -> V_25 ,
sizeof( struct V_131 ) ,
V_36 ) ;
if ( ! V_71 -> V_132 )
return - V_37 ;
V_71 -> V_132 [ 0 ] . V_54 = V_71 -> V_126 ;
V_71 -> V_132 [ 0 ] . V_127 = V_71 -> V_125 ;
V_71 -> V_132 [ 0 ] . V_138 = V_71 -> V_128 ;
}
if ( ! V_71 -> V_132 ) {
F_51 ( V_52 -> V_25 , L_87 ) ;
return - V_17 ;
}
return 0 ;
}
int F_146 ( struct V_66 * V_52 )
{
int V_3 , V_87 , V_14 ;
if ( ! V_52 -> V_54 || ! V_52 -> V_25 )
return - V_17 ;
for ( V_3 = 0 ; V_3 < V_52 -> V_73 ; V_3 ++ ) {
struct V_130 * V_343 = & V_52 -> V_71 [ V_3 ] ;
V_14 = F_232 ( V_52 , V_343 ) ;
if ( V_14 ) {
F_51 ( V_52 -> V_25 , L_88 ) ;
return V_14 ;
}
for ( V_87 = 0 ; V_87 < V_343 -> V_93 ; V_87 ++ ) {
if ( ! ! V_343 -> V_132 [ V_87 ] . V_54 ==
! ! V_343 -> V_132 [ V_87 ] . V_127 ) {
F_51 ( V_52 -> V_25 , L_89 ,
V_343 -> V_54 ) ;
return - V_17 ;
}
if ( ! V_343 -> V_132 [ V_87 ] . V_138 ) {
F_51 ( V_52 -> V_25 , L_90 ,
V_343 -> V_54 ) ;
return - V_17 ;
}
}
if ( V_343 -> V_133 && V_343 -> V_139 ) {
F_51 ( V_52 -> V_25 ,
L_91 ,
V_343 -> V_54 ) ;
return - V_17 ;
}
if ( V_343 -> V_135 && V_343 -> V_134 ) {
F_51 ( V_52 -> V_25 ,
L_92 ,
V_343 -> V_54 ) ;
return - V_17 ;
}
if ( ! V_343 -> V_136 &&
! ( V_343 -> V_135 || V_343 -> V_134 ) ) {
F_51 ( V_52 -> V_25 ,
L_93 ,
V_343 -> V_54 ) ;
return - V_17 ;
}
}
F_100 ( V_52 -> V_25 , V_52 ) ;
F_234 ( V_52 ) ;
F_39 ( V_52 ) ;
V_52 -> V_29 = F_233 ( V_52 -> V_25 ,
sizeof( struct V_28 ) *
( V_52 -> V_73 + V_52 -> V_196 ) ,
V_36 ) ;
if ( V_52 -> V_29 == NULL )
return - V_37 ;
V_52 -> V_91 = 0 ;
V_52 -> V_186 = & V_52 -> V_29 [ V_52 -> V_73 ] ;
for ( V_3 = 0 ; V_3 < V_52 -> V_73 ; V_3 ++ ) {
V_52 -> V_29 [ V_3 ] . V_52 = V_52 ;
V_52 -> V_29 [ V_3 ] . V_71 = & V_52 -> V_71 [ V_3 ] ;
V_52 -> V_29 [ V_3 ] . V_94 = F_233 ( V_52 -> V_25 ,
sizeof( struct V_64 * ) *
( V_52 -> V_29 [ V_3 ] . V_71 -> V_93 ) ,
V_36 ) ;
if ( V_52 -> V_29 [ V_3 ] . V_94 == NULL )
return - V_37 ;
}
for ( V_3 = 0 ; V_3 < V_52 -> V_196 ; V_3 ++ )
V_52 -> V_186 [ V_3 ] . V_52 = V_52 ;
F_102 ( & V_52 -> V_344 ) ;
V_52 -> V_214 = 0 ;
F_101 ( & V_52 -> V_193 ) ;
F_101 ( & V_52 -> V_345 ) ;
V_14 = F_128 ( V_52 ) ;
if ( V_14 != 0 )
F_41 ( V_52 ) ;
for ( V_3 = 0 ; V_3 < V_52 -> V_91 ; V_3 ++ ) {
struct V_28 * V_29 = & V_52 -> V_29 [ V_3 ] ;
struct V_64 * V_101 = V_29 -> V_101 ;
int V_87 ;
for ( V_87 = 0 ; V_87 < V_29 -> V_93 ; V_87 ++ ) {
struct V_64 * V_123 = V_29 -> V_94 [ V_87 ] ;
if ( ! V_123 -> V_122 )
F_65 ( V_123 -> V_25 ) ;
}
if ( ! V_101 -> V_122 )
F_65 ( V_101 -> V_25 ) ;
}
return V_14 ;
}
int F_149 ( struct V_66 * V_52 )
{
if ( V_52 -> V_214 )
F_147 ( V_52 ) ;
F_43 ( V_52 -> V_25 , L_94 , V_52 -> V_54 ) ;
return 0 ;
}
static char * F_235 ( struct V_24 * V_25 , int * V_248 )
{
char * V_281 , V_54 [ V_346 ] ;
int V_347 , V_348 ;
if ( F_74 ( V_25 ) == NULL )
return NULL ;
F_180 ( V_54 , F_74 ( V_25 ) , V_346 ) ;
V_281 = strstr ( V_54 , V_25 -> V_10 -> V_54 ) ;
if ( V_281 ) {
if ( sscanf ( & V_281 [ strlen ( V_25 -> V_10 -> V_54 ) ] , L_95 , V_248 ) == 1 ) {
if ( * V_248 == - 1 )
V_281 [ strlen ( V_25 -> V_10 -> V_54 ) ] = '\0' ;
}
} else {
if ( sscanf ( V_54 , L_96 , & V_347 , & V_348 ) == 2 ) {
char V_349 [ V_346 ] ;
* V_248 = ( ( V_347 & 0xffff ) << 16 ) + V_348 ;
snprintf ( V_349 , V_346 , L_97 , V_25 -> V_10 -> V_54 , V_54 ) ;
F_180 ( V_54 , V_349 , V_346 ) ;
} else
* V_248 = 0 ;
}
return F_236 ( V_54 , V_36 ) ;
}
static inline char * F_237 ( struct V_24 * V_25 ,
struct V_95 * V_350 )
{
if ( V_350 -> V_54 == NULL ) {
F_51 ( V_25 ,
L_98 ,
F_74 ( V_25 ) ) ;
return NULL ;
}
return F_236 ( V_350 -> V_54 , V_36 ) ;
}
static void F_238 ( struct V_63 * V_51 )
{
struct V_64 * V_65 , * V_351 ;
F_239 (dai, _dai, &component->dai_list, list) {
F_43 ( V_51 -> V_25 , L_99 ,
V_65 -> V_54 ) ;
F_79 ( & V_65 -> V_165 ) ;
F_15 ( V_65 -> V_54 ) ;
F_15 ( V_65 ) ;
}
}
static int F_240 ( struct V_63 * V_51 ,
struct V_95 * V_350 , T_1 V_18 ,
bool V_352 )
{
struct V_24 * V_25 = V_51 -> V_25 ;
struct V_64 * V_65 ;
unsigned int V_3 ;
int V_14 ;
F_43 ( V_25 , L_100 , F_74 ( V_25 ) , V_18 ) ;
V_51 -> V_350 = V_350 ;
V_51 -> V_353 = V_18 ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ ) {
V_65 = F_98 ( sizeof( struct V_64 ) , V_36 ) ;
if ( V_65 == NULL ) {
V_14 = - V_37 ;
goto V_80;
}
if ( V_18 == 1 && V_352 ) {
V_65 -> V_54 = F_235 ( V_25 , & V_65 -> V_248 ) ;
} else {
V_65 -> V_54 = F_237 ( V_25 , & V_350 [ V_3 ] ) ;
if ( V_350 [ V_3 ] . V_248 )
V_65 -> V_248 = V_350 [ V_3 ] . V_248 ;
else
V_65 -> V_248 = V_3 ;
}
if ( V_65 -> V_54 == NULL ) {
F_15 ( V_65 ) ;
V_14 = - V_37 ;
goto V_80;
}
V_65 -> V_51 = V_51 ;
V_65 -> V_25 = V_25 ;
V_65 -> V_10 = & V_350 [ V_3 ] ;
if ( ! V_65 -> V_10 -> V_97 )
V_65 -> V_10 -> V_97 = & V_354 ;
F_93 ( & V_65 -> V_165 , & V_51 -> V_355 ) ;
F_43 ( V_25 , L_101 , V_65 -> V_54 ) ;
}
return 0 ;
V_80:
F_238 ( V_51 ) ;
return V_14 ;
}
static void F_241 ( struct V_356 * V_59 ,
enum V_357 type , int V_358 )
{
struct V_63 * V_51 = V_59 -> V_51 ;
V_51 -> V_10 -> V_359 ( V_51 , type , V_358 ) ;
}
static int F_242 ( struct V_356 * V_59 ,
int V_360 )
{
struct V_63 * V_51 = V_59 -> V_51 ;
return V_51 -> V_10 -> V_361 ( V_51 , V_360 ) ;
}
static int F_243 ( struct V_63 * V_51 ,
const struct V_362 * V_10 , struct V_24 * V_25 )
{
struct V_356 * V_59 ;
V_51 -> V_54 = F_235 ( V_25 , & V_51 -> V_248 ) ;
if ( ! V_51 -> V_54 ) {
F_51 ( V_25 , L_102 ) ;
return - V_37 ;
}
V_51 -> V_25 = V_25 ;
V_51 -> V_10 = V_10 ;
if ( ! V_51 -> V_363 )
V_51 -> V_363 = & V_51 -> V_59 ;
V_59 = V_51 -> V_363 ;
V_59 -> V_25 = V_25 ;
V_59 -> V_51 = V_51 ;
V_59 -> V_107 = V_113 ;
if ( V_10 -> V_359 )
V_59 -> V_359 = F_241 ;
if ( V_10 -> V_361 )
V_59 -> V_361 = F_242 ;
F_102 ( & V_51 -> V_355 ) ;
F_101 ( & V_51 -> V_364 ) ;
return 0 ;
}
static void F_244 ( struct V_63 * V_51 )
{
F_93 ( & V_51 -> V_165 , & V_365 ) ;
}
static void F_245 ( struct V_63 * V_51 )
{
F_153 ( & V_366 ) ;
F_244 ( V_51 ) ;
F_142 ( & V_366 ) ;
}
static void F_246 ( struct V_63 * V_51 )
{
F_238 ( V_51 ) ;
F_15 ( V_51 -> V_54 ) ;
}
static void F_247 ( struct V_63 * V_51 )
{
F_79 ( & V_51 -> V_165 ) ;
}
static void F_248 ( struct V_63 * V_51 )
{
F_153 ( & V_366 ) ;
F_247 ( V_51 ) ;
F_142 ( & V_366 ) ;
}
int F_249 ( struct V_24 * V_25 ,
const struct V_362 * V_367 ,
struct V_95 * V_350 ,
int V_353 )
{
struct V_63 * V_368 ;
int V_14 ;
V_368 = F_98 ( sizeof( * V_368 ) , V_36 ) ;
if ( ! V_368 ) {
F_51 ( V_25 , L_103 ) ;
return - V_37 ;
}
V_14 = F_243 ( V_368 , V_367 , V_25 ) ;
if ( V_14 )
goto V_369;
V_368 -> V_370 = true ;
V_368 -> V_371 = true ;
V_14 = F_240 ( V_368 , V_350 , V_353 , true ) ;
if ( V_14 < 0 ) {
F_51 ( V_25 , L_104 , V_14 ) ;
goto V_372;
}
F_245 ( V_368 ) ;
return 0 ;
V_372:
F_246 ( V_368 ) ;
V_369:
F_15 ( V_368 ) ;
return V_14 ;
}
void F_250 ( struct V_24 * V_25 )
{
struct V_63 * V_368 ;
F_35 (cmpnt, &component_list, list) {
if ( V_25 == V_368 -> V_25 && V_368 -> V_371 )
goto V_281;
}
return;
V_281:
F_248 ( V_368 ) ;
F_246 ( V_368 ) ;
F_15 ( V_368 ) ;
}
static int F_251 ( struct V_63 * V_51 ,
unsigned int V_6 , unsigned int V_1 )
{
struct V_60 * V_61 = F_252 ( V_51 ) ;
return V_61 -> V_10 -> V_373 ( V_61 , V_6 , V_1 ) ;
}
static int F_253 ( struct V_63 * V_51 ,
unsigned int V_6 , unsigned int * V_1 )
{
struct V_60 * V_61 = F_252 ( V_51 ) ;
* V_1 = V_61 -> V_10 -> V_374 ( V_61 , V_6 ) ;
return 0 ;
}
int F_254 ( struct V_24 * V_25 , struct V_60 * V_61 ,
const struct V_167 * V_375 )
{
int V_14 ;
V_14 = F_243 ( & V_61 -> V_51 ,
& V_375 -> V_376 , V_25 ) ;
if ( V_14 )
return V_14 ;
V_61 -> V_25 = V_25 ;
V_61 -> V_10 = V_375 ;
if ( V_375 -> V_373 )
V_61 -> V_51 . V_373 = F_251 ;
if ( V_375 -> V_374 )
V_61 -> V_51 . V_374 = F_253 ;
F_153 ( & V_366 ) ;
F_244 ( & V_61 -> V_51 ) ;
F_93 ( & V_61 -> V_165 , & V_377 ) ;
F_142 ( & V_366 ) ;
F_43 ( V_25 , L_105 ,
V_61 -> V_51 . V_54 ) ;
return 0 ;
}
int F_255 ( struct V_24 * V_25 ,
const struct V_167 * V_375 )
{
struct V_60 * V_61 ;
int V_14 ;
F_43 ( V_25 , L_106 , F_74 ( V_25 ) ) ;
V_61 = F_98 ( sizeof( struct V_60 ) , V_36 ) ;
if ( V_61 == NULL )
return - V_37 ;
V_14 = F_254 ( V_25 , V_61 , V_375 ) ;
if ( V_14 )
F_15 ( V_61 ) ;
return V_14 ;
}
void F_256 ( struct V_60 * V_61 )
{
F_153 ( & V_366 ) ;
F_79 ( & V_61 -> V_165 ) ;
F_247 ( & V_61 -> V_51 ) ;
F_142 ( & V_366 ) ;
F_246 ( & V_61 -> V_51 ) ;
F_43 ( V_61 -> V_25 , L_107 ,
V_61 -> V_51 . V_54 ) ;
}
struct V_60 * F_257 ( struct V_24 * V_25 )
{
struct V_60 * V_61 ;
F_35 (platform, &platform_list, list) {
if ( V_25 == V_61 -> V_25 )
return V_61 ;
}
return NULL ;
}
void F_258 ( struct V_24 * V_25 )
{
struct V_60 * V_61 ;
V_61 = F_257 ( V_25 ) ;
if ( ! V_61 )
return;
F_256 ( V_61 ) ;
F_15 ( V_61 ) ;
}
static void F_259 ( struct V_378 * V_72 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_137 ( V_379 ) ; V_3 ++ )
if ( V_72 -> V_380 & V_379 [ V_3 ] )
V_72 -> V_380 |= V_379 [ V_3 ] ;
}
static int F_260 ( struct V_63 * V_51 ,
unsigned int V_6 , unsigned int V_1 )
{
struct V_4 * V_5 = F_261 ( V_51 ) ;
return V_5 -> V_10 -> V_373 ( V_5 , V_6 , V_1 ) ;
}
static int F_262 ( struct V_63 * V_51 ,
unsigned int V_6 , unsigned int * V_1 )
{
struct V_4 * V_5 = F_261 ( V_51 ) ;
* V_1 = V_5 -> V_10 -> V_374 ( V_5 , V_6 ) ;
return 0 ;
}
static int F_263 ( struct V_356 * V_59 ,
enum V_381 V_382 )
{
struct V_4 * V_5 = F_264 ( V_59 ) ;
return V_5 -> V_10 -> V_383 ( V_5 , V_382 ) ;
}
int F_265 ( struct V_24 * V_25 ,
const struct V_155 * V_384 ,
struct V_95 * V_350 ,
int V_353 )
{
struct V_4 * V_5 ;
struct V_64 * V_65 ;
struct V_114 * V_114 ;
int V_14 , V_3 ;
F_43 ( V_25 , L_108 , F_74 ( V_25 ) ) ;
V_5 = F_98 ( sizeof( struct V_4 ) , V_36 ) ;
if ( V_5 == NULL )
return - V_37 ;
V_5 -> V_51 . V_363 = & V_5 -> V_59 ;
V_14 = F_243 ( & V_5 -> V_51 ,
& V_384 -> V_376 , V_25 ) ;
if ( V_14 )
goto V_369;
if ( V_384 -> V_373 )
V_5 -> V_51 . V_373 = F_260 ;
if ( V_384 -> V_374 )
V_5 -> V_51 . V_374 = F_262 ;
V_5 -> V_51 . V_370 = V_384 -> V_370 ;
V_5 -> V_59 . V_5 = V_5 ;
if ( V_384 -> V_359 )
V_5 -> V_59 . V_359 = V_384 -> V_359 ;
if ( V_384 -> V_383 )
V_5 -> V_59 . V_383 = F_263 ;
V_5 -> V_25 = V_25 ;
V_5 -> V_10 = V_384 ;
V_5 -> V_51 . V_285 = V_384 -> V_13 ;
F_101 ( & V_5 -> V_193 ) ;
if ( ! V_5 -> V_51 . V_373 ) {
if ( V_384 -> V_385 )
V_114 = V_384 -> V_385 ( V_25 ) ;
else
V_114 = F_266 ( V_25 , NULL ) ;
if ( V_114 ) {
V_14 = F_267 ( & V_5 -> V_51 ,
V_114 ) ;
if ( V_14 ) {
F_51 ( V_5 -> V_25 ,
L_109 ,
V_14 ) ;
goto V_372;
}
}
}
for ( V_3 = 0 ; V_3 < V_353 ; V_3 ++ ) {
F_259 ( & V_350 [ V_3 ] . V_386 ) ;
F_259 ( & V_350 [ V_3 ] . V_387 ) ;
}
V_14 = F_240 ( & V_5 -> V_51 , V_350 , V_353 , false ) ;
if ( V_14 < 0 ) {
F_51 ( V_25 , L_104 , V_14 ) ;
goto V_372;
}
F_35 (dai, &codec->component.dai_list, list)
V_65 -> V_5 = V_5 ;
F_153 ( & V_366 ) ;
F_244 ( & V_5 -> V_51 ) ;
F_93 ( & V_5 -> V_165 , & V_388 ) ;
F_142 ( & V_366 ) ;
F_43 ( V_5 -> V_25 , L_110 ,
V_5 -> V_51 . V_54 ) ;
return 0 ;
V_372:
F_246 ( & V_5 -> V_51 ) ;
V_369:
F_15 ( V_5 ) ;
return V_14 ;
}
void F_268 ( struct V_24 * V_25 )
{
struct V_4 * V_5 ;
F_35 (codec, &codec_list, list) {
if ( V_25 == V_5 -> V_25 )
goto V_281;
}
return;
V_281:
F_153 ( & V_366 ) ;
F_79 ( & V_5 -> V_165 ) ;
F_247 ( & V_5 -> V_51 ) ;
F_142 ( & V_366 ) ;
F_43 ( V_5 -> V_25 , L_111 ,
V_5 -> V_51 . V_54 ) ;
F_246 ( & V_5 -> V_51 ) ;
F_269 ( V_5 ) ;
F_15 ( V_5 ) ;
}
int F_270 ( struct V_66 * V_52 ,
const char * V_389 )
{
struct V_124 * V_390 ;
int V_14 ;
if ( ! V_52 -> V_25 ) {
F_271 ( L_112 , V_391 ) ;
return - V_17 ;
}
V_390 = V_52 -> V_25 -> V_127 ;
V_14 = F_272 ( V_390 , V_389 , 0 , & V_52 -> V_54 ) ;
if ( V_14 < 0 && V_14 != - V_17 ) {
F_51 ( V_52 -> V_25 ,
L_113 ,
V_389 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
int F_273 ( struct V_66 * V_52 ,
const char * V_389 )
{
struct V_124 * V_390 = V_52 -> V_25 -> V_127 ;
struct V_173 * V_392 ;
const char * V_242 , * V_393 ;
int V_3 , V_87 , V_394 , V_14 ;
V_394 = F_274 ( V_390 , V_389 ) ;
if ( V_394 < 0 ) {
F_51 ( V_52 -> V_25 ,
L_114 , V_389 ) ;
return - V_17 ;
}
if ( V_394 & 1 ) {
F_51 ( V_52 -> V_25 ,
L_115 , V_389 ) ;
return - V_17 ;
}
V_394 /= 2 ;
if ( ! V_394 ) {
F_51 ( V_52 -> V_25 , L_116 ,
V_389 ) ;
return - V_17 ;
}
V_392 = F_275 ( V_52 -> V_25 , V_394 , sizeof( * V_392 ) ,
V_36 ) ;
if ( ! V_392 ) {
F_51 ( V_52 -> V_25 ,
L_117 ) ;
return - V_37 ;
}
for ( V_3 = 0 ; V_3 < V_394 ; V_3 ++ ) {
V_14 = F_272 ( V_390 , V_389 ,
2 * V_3 , & V_242 ) ;
if ( V_14 ) {
F_51 ( V_52 -> V_25 ,
L_118 ,
V_389 , 2 * V_3 , V_14 ) ;
return - V_17 ;
}
for ( V_87 = 0 ; V_87 < F_137 ( V_395 ) ; V_87 ++ ) {
if ( ! strncmp ( V_242 , V_395 [ V_87 ] . V_54 ,
strlen ( V_395 [ V_87 ] . V_54 ) ) ) {
V_392 [ V_3 ] = V_395 [ V_87 ] ;
break;
}
}
if ( V_87 >= F_137 ( V_395 ) ) {
F_51 ( V_52 -> V_25 ,
L_119 ,
V_242 ) ;
return - V_17 ;
}
V_14 = F_272 ( V_390 , V_389 ,
( 2 * V_3 ) + 1 ,
& V_393 ) ;
if ( V_14 ) {
F_51 ( V_52 -> V_25 ,
L_118 ,
V_389 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_17 ;
}
V_392 [ V_3 ] . V_54 = V_393 ;
}
V_52 -> V_157 = V_392 ;
V_52 -> V_158 = V_394 ;
return 0 ;
}
int F_276 ( struct V_124 * V_390 ,
unsigned int * V_327 ,
unsigned int * V_330 )
{
V_289 V_1 ;
int V_14 ;
if ( F_277 ( V_390 , L_120 ) ) {
V_14 = F_278 ( V_390 , L_120 , & V_1 ) ;
if ( V_14 )
return V_14 ;
if ( V_327 )
* V_327 = V_1 ;
}
if ( F_277 ( V_390 , L_121 ) ) {
V_14 = F_278 ( V_390 , L_121 , & V_1 ) ;
if ( V_14 )
return V_14 ;
if ( V_330 )
* V_330 = V_1 ;
}
return 0 ;
}
int F_279 ( struct V_66 * V_52 ,
const char * V_389 )
{
struct V_124 * V_390 = V_52 -> V_25 -> V_127 ;
int V_396 ;
struct V_397 * V_398 ;
int V_3 , V_14 ;
V_396 = F_274 ( V_390 , V_389 ) ;
if ( V_396 < 0 || V_396 & 1 ) {
F_51 ( V_52 -> V_25 ,
L_122 ,
V_389 ) ;
return - V_17 ;
}
V_396 /= 2 ;
if ( ! V_396 ) {
F_51 ( V_52 -> V_25 , L_116 ,
V_389 ) ;
return - V_17 ;
}
V_398 = F_233 ( V_52 -> V_25 , V_396 * sizeof( * V_398 ) ,
V_36 ) ;
if ( ! V_398 ) {
F_51 ( V_52 -> V_25 ,
L_123 ) ;
return - V_17 ;
}
for ( V_3 = 0 ; V_3 < V_396 ; V_3 ++ ) {
V_14 = F_272 ( V_390 , V_389 ,
2 * V_3 , & V_398 [ V_3 ] . V_399 ) ;
if ( V_14 ) {
F_51 ( V_52 -> V_25 ,
L_124 ,
V_389 , 2 * V_3 , V_14 ) ;
return - V_17 ;
}
V_14 = F_272 ( V_390 , V_389 ,
( 2 * V_3 ) + 1 , & V_398 [ V_3 ] . V_317 ) ;
if ( V_14 ) {
F_51 ( V_52 -> V_25 ,
L_124 ,
V_389 , ( 2 * V_3 ) + 1 , V_14 ) ;
return - V_17 ;
}
}
V_52 -> V_164 = V_396 ;
V_52 -> V_163 = V_398 ;
return 0 ;
}
unsigned int F_280 ( struct V_124 * V_390 ,
const char * V_241 ,
struct V_124 * * V_400 ,
struct V_124 * * V_401 )
{
int V_14 , V_3 ;
char V_402 [ 128 ] ;
unsigned int V_403 = 0 ;
int V_404 , V_405 ;
const char * V_406 ;
struct {
char * V_54 ;
unsigned int V_1 ;
} V_407 [] = {
{ L_125 , V_408 } ,
{ L_126 , V_409 } ,
{ L_127 , V_410 } ,
{ L_128 , V_411 } ,
{ L_129 , V_412 } ,
{ L_130 , V_413 } ,
{ L_131 , V_414 } ,
{ L_132 , V_415 } ,
{ L_133 , V_416 } ,
} ;
if ( ! V_241 )
V_241 = L_134 ;
snprintf ( V_402 , sizeof( V_402 ) , L_135 , V_241 ) ;
V_14 = F_281 ( V_390 , V_402 , & V_406 ) ;
if ( V_14 == 0 ) {
for ( V_3 = 0 ; V_3 < F_137 ( V_407 ) ; V_3 ++ ) {
if ( strcmp ( V_406 , V_407 [ V_3 ] . V_54 ) == 0 ) {
V_403 |= V_407 [ V_3 ] . V_1 ;
break;
}
}
}
snprintf ( V_402 , sizeof( V_402 ) , L_136 , V_241 ) ;
if ( F_282 ( V_390 , V_402 , NULL ) )
V_403 |= V_417 ;
else
V_403 |= V_418 ;
snprintf ( V_402 , sizeof( V_402 ) , L_137 , V_241 ) ;
V_404 = ! ! F_282 ( V_390 , V_402 , NULL ) ;
snprintf ( V_402 , sizeof( V_402 ) , L_138 , V_241 ) ;
V_405 = ! ! F_282 ( V_390 , V_402 , NULL ) ;
switch ( ( V_404 << 4 ) + V_405 ) {
case 0x11 :
V_403 |= V_419 ;
break;
case 0x10 :
V_403 |= V_420 ;
break;
case 0x01 :
V_403 |= V_421 ;
break;
default:
break;
}
snprintf ( V_402 , sizeof( V_402 ) , L_139 , V_241 ) ;
V_404 = ! ! F_282 ( V_390 , V_402 , NULL ) ;
if ( V_404 && V_400 )
* V_400 = F_283 ( V_390 , V_402 , 0 ) ;
snprintf ( V_402 , sizeof( V_402 ) , L_140 , V_241 ) ;
V_405 = ! ! F_282 ( V_390 , V_402 , NULL ) ;
if ( V_405 && V_401 )
* V_401 = F_283 ( V_390 , V_402 , 0 ) ;
switch ( ( V_404 << 4 ) + V_405 ) {
case 0x11 :
V_403 |= V_204 ;
break;
case 0x10 :
V_403 |= V_206 ;
break;
case 0x01 :
V_403 |= V_207 ;
break;
default:
V_403 |= V_205 ;
break;
}
return V_403 ;
}
int F_284 ( struct V_124 * V_127 ,
const char * * V_138 )
{
struct V_63 * V_19 ;
struct V_422 args ;
int V_14 ;
V_14 = F_285 ( V_127 , L_141 ,
L_142 , 0 , & args ) ;
if ( V_14 )
return V_14 ;
V_14 = - V_137 ;
F_153 ( & V_366 ) ;
F_35 (pos, &component_list, list) {
if ( V_19 -> V_25 -> V_127 != args . V_390 )
continue;
if ( V_19 -> V_10 -> V_423 ) {
V_14 = V_19 -> V_10 -> V_423 ( V_19 , & args , V_138 ) ;
} else {
int V_248 = - 1 ;
switch ( args . V_424 ) {
case 0 :
V_248 = 0 ;
break;
case 1 :
V_248 = args . args [ 0 ] ;
break;
default:
break;
}
if ( V_248 < 0 || V_248 >= V_19 -> V_353 ) {
V_14 = - V_17 ;
continue;
}
V_14 = 0 ;
* V_138 = V_19 -> V_350 [ V_248 ] . V_54 ;
if ( ! * V_138 )
* V_138 = V_19 -> V_54 ;
}
break;
}
F_142 ( & V_366 ) ;
F_286 ( args . V_390 ) ;
return V_14 ;
}
static int T_6 F_287 ( void )
{
#ifdef F_112
V_67 = F_24 ( L_143 , NULL ) ;
if ( F_162 ( V_67 ) || ! V_67 ) {
F_288 ( L_144 ) ;
V_67 = NULL ;
}
if ( ! F_28 ( L_145 , 0444 , V_67 , NULL ,
& V_425 ) )
F_288 ( L_146 ) ;
if ( ! F_28 ( L_147 , 0444 , V_67 , NULL ,
& V_426 ) )
F_288 ( L_148 ) ;
if ( ! F_28 ( L_149 , 0444 , V_67 , NULL ,
& V_427 ) )
F_288 ( L_150 ) ;
#endif
F_289 () ;
return F_290 ( & V_428 ) ;
}
static void T_7 F_291 ( void )
{
F_292 () ;
#ifdef F_112
F_31 ( V_67 ) ;
#endif
F_293 ( & V_428 ) ;
}
