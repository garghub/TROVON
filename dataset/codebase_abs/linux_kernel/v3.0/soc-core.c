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
static int F_47 ( struct V_75 * V_76 )
{
struct V_31 * V_32 = V_76 -> V_36 ;
struct V_58 * V_77 = V_32 -> V_77 ;
struct V_58 * V_78 = V_32 -> V_78 ;
int V_14 ;
if ( ! V_78 -> V_10 -> V_79 &&
! V_77 -> V_10 -> V_79 &&
! V_32 -> V_80 -> V_79 )
return 0 ;
if ( ! V_32 -> V_81 ) {
F_37 ( & V_32 -> V_28 ,
L_14 ) ;
return 0 ;
}
F_48 ( & V_32 -> V_28 , L_15 , V_32 -> V_81 ) ;
V_14 = F_49 ( V_76 -> V_82 ,
V_83 ,
V_32 -> V_81 , V_32 -> V_81 ) ;
if ( V_14 < 0 ) {
F_50 ( & V_32 -> V_28 ,
L_16 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_51 ( struct V_75 * V_76 )
{
struct V_31 * V_32 = V_76 -> V_36 ;
struct V_84 * V_82 = V_76 -> V_82 ;
struct V_60 * V_61 = V_32 -> V_61 ;
struct V_58 * V_77 = V_32 -> V_77 ;
struct V_58 * V_78 = V_32 -> V_78 ;
struct V_85 * V_86 = V_77 -> V_10 ;
struct V_85 * V_87 = V_78 -> V_10 ;
int V_14 = 0 ;
F_52 ( & V_88 ) ;
if ( V_77 -> V_10 -> V_89 -> V_90 ) {
V_14 = V_77 -> V_10 -> V_89 -> V_90 ( V_76 , V_77 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_17 ,
V_77 -> V_51 ) ;
goto V_91;
}
}
if ( V_61 -> V_10 -> V_89 && V_61 -> V_10 -> V_89 -> V_92 ) {
V_14 = V_61 -> V_10 -> V_89 -> V_92 ( V_76 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_18 , V_61 -> V_51 ) ;
goto V_93;
}
}
if ( V_78 -> V_10 -> V_89 -> V_90 ) {
V_14 = V_78 -> V_10 -> V_89 -> V_90 ( V_76 , V_78 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_19 ,
V_78 -> V_51 ) ;
goto V_94;
}
}
if ( V_32 -> V_80 -> V_89 && V_32 -> V_80 -> V_89 -> V_90 ) {
V_14 = V_32 -> V_80 -> V_89 -> V_90 ( V_76 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_20 , V_32 -> V_80 -> V_51 ) ;
goto V_95;
}
}
if ( V_76 -> V_96 == V_97 ) {
V_82 -> V_98 . V_99 =
F_53 ( V_87 -> V_100 . V_99 ,
V_86 -> V_100 . V_99 ) ;
V_82 -> V_98 . V_101 =
F_6 ( V_87 -> V_100 . V_101 ,
V_86 -> V_100 . V_101 ) ;
V_82 -> V_98 . V_102 =
F_53 ( V_87 -> V_100 . V_102 ,
V_86 -> V_100 . V_102 ) ;
V_82 -> V_98 . V_103 =
F_6 ( V_87 -> V_100 . V_103 ,
V_86 -> V_100 . V_103 ) ;
V_82 -> V_98 . V_104 =
V_87 -> V_100 . V_104 & V_86 -> V_100 . V_104 ;
V_82 -> V_98 . V_105 =
V_87 -> V_100 . V_105 & V_86 -> V_100 . V_105 ;
if ( V_87 -> V_100 . V_105
& ( V_106 | V_107 ) )
V_82 -> V_98 . V_105 |= V_86 -> V_100 . V_105 ;
if ( V_86 -> V_100 . V_105
& ( V_106 | V_107 ) )
V_82 -> V_98 . V_105 |= V_87 -> V_100 . V_105 ;
} else {
V_82 -> V_98 . V_99 =
F_53 ( V_87 -> V_108 . V_99 ,
V_86 -> V_108 . V_99 ) ;
V_82 -> V_98 . V_101 =
F_6 ( V_87 -> V_108 . V_101 ,
V_86 -> V_108 . V_101 ) ;
V_82 -> V_98 . V_102 =
F_53 ( V_87 -> V_108 . V_102 ,
V_86 -> V_108 . V_102 ) ;
V_82 -> V_98 . V_103 =
F_6 ( V_87 -> V_108 . V_103 ,
V_86 -> V_108 . V_103 ) ;
V_82 -> V_98 . V_104 =
V_87 -> V_108 . V_104 & V_86 -> V_108 . V_104 ;
V_82 -> V_98 . V_105 =
V_87 -> V_108 . V_105 & V_86 -> V_108 . V_105 ;
if ( V_87 -> V_108 . V_105
& ( V_106 | V_107 ) )
V_82 -> V_98 . V_105 |= V_86 -> V_108 . V_105 ;
if ( V_86 -> V_108 . V_105
& ( V_106 | V_107 ) )
V_82 -> V_98 . V_105 |= V_87 -> V_108 . V_105 ;
}
V_14 = - V_17 ;
F_54 ( V_82 ) ;
if ( ! V_82 -> V_98 . V_105 ) {
F_25 ( V_74 L_21 ,
V_78 -> V_51 , V_77 -> V_51 ) ;
goto V_109;
}
if ( ! V_82 -> V_98 . V_104 ) {
F_25 ( V_74 L_22 ,
V_78 -> V_51 , V_77 -> V_51 ) ;
goto V_109;
}
if ( ! V_82 -> V_98 . V_102 || ! V_82 -> V_98 . V_103 ||
V_82 -> V_98 . V_102 > V_82 -> V_98 . V_103 ) {
F_25 ( V_74 L_23 ,
V_78 -> V_51 , V_77 -> V_51 ) ;
goto V_109;
}
if ( V_77 -> V_110 || V_78 -> V_110 ) {
V_14 = F_47 ( V_76 ) ;
if ( V_14 != 0 )
goto V_109;
}
F_55 ( L_24 ,
V_78 -> V_51 , V_77 -> V_51 ) ;
F_55 ( L_25 , V_82 -> V_98 . V_105 ) ;
F_55 ( L_26 , V_82 -> V_98 . V_102 ,
V_82 -> V_98 . V_103 ) ;
F_55 ( L_27 , V_82 -> V_98 . V_99 ,
V_82 -> V_98 . V_101 ) ;
if ( V_76 -> V_96 == V_97 ) {
V_77 -> V_111 ++ ;
V_78 -> V_111 ++ ;
} else {
V_77 -> V_112 ++ ;
V_78 -> V_112 ++ ;
}
V_77 -> V_110 ++ ;
V_78 -> V_110 ++ ;
V_32 -> V_5 -> V_110 ++ ;
F_56 ( & V_88 ) ;
return 0 ;
V_109:
if ( V_32 -> V_80 -> V_89 && V_32 -> V_80 -> V_89 -> V_113 )
V_32 -> V_80 -> V_89 -> V_113 ( V_76 ) ;
V_95:
if ( V_78 -> V_10 -> V_89 -> V_113 )
V_78 -> V_10 -> V_89 -> V_113 ( V_76 , V_78 ) ;
V_94:
if ( V_61 -> V_10 -> V_89 && V_61 -> V_10 -> V_89 -> V_114 )
V_61 -> V_10 -> V_89 -> V_114 ( V_76 ) ;
V_93:
if ( V_77 -> V_10 -> V_89 -> V_113 )
V_77 -> V_10 -> V_89 -> V_113 ( V_76 , V_77 ) ;
V_91:
F_56 ( & V_88 ) ;
return V_14 ;
}
static void F_57 ( struct V_115 * V_116 )
{
struct V_31 * V_32 =
F_8 ( V_116 , struct V_31 , V_117 . V_116 ) ;
struct V_58 * V_78 = V_32 -> V_78 ;
F_52 ( & V_88 ) ;
F_55 ( L_28 ,
V_78 -> V_10 -> V_100 . V_118 ,
V_78 -> V_111 ? L_29 : L_30 ,
V_78 -> V_119 ? L_31 : L_32 ) ;
if ( V_78 -> V_119 == 1 ) {
V_78 -> V_119 = 0 ;
F_58 ( V_32 ,
V_78 -> V_10 -> V_100 . V_118 ,
V_120 ) ;
}
F_56 ( & V_88 ) ;
}
static int F_59 ( struct V_75 * V_76 )
{
struct V_31 * V_32 = V_76 -> V_36 ;
struct V_60 * V_61 = V_32 -> V_61 ;
struct V_58 * V_77 = V_32 -> V_77 ;
struct V_58 * V_78 = V_32 -> V_78 ;
struct V_4 * V_5 = V_32 -> V_5 ;
F_52 ( & V_88 ) ;
if ( V_76 -> V_96 == V_97 ) {
V_77 -> V_111 -- ;
V_78 -> V_111 -- ;
} else {
V_77 -> V_112 -- ;
V_78 -> V_112 -- ;
}
V_77 -> V_110 -- ;
V_78 -> V_110 -- ;
V_5 -> V_110 -- ;
if ( V_76 -> V_96 == V_97 )
F_60 ( V_78 , 1 ) ;
if ( V_77 -> V_10 -> V_89 -> V_113 )
V_77 -> V_10 -> V_89 -> V_113 ( V_76 , V_77 ) ;
if ( V_78 -> V_10 -> V_89 -> V_113 )
V_78 -> V_10 -> V_89 -> V_113 ( V_76 , V_78 ) ;
if ( V_32 -> V_80 -> V_89 && V_32 -> V_80 -> V_89 -> V_113 )
V_32 -> V_80 -> V_89 -> V_113 ( V_76 ) ;
if ( V_61 -> V_10 -> V_89 && V_61 -> V_10 -> V_89 -> V_114 )
V_61 -> V_10 -> V_89 -> V_114 ( V_76 ) ;
V_77 -> V_82 = NULL ;
if ( V_76 -> V_96 == V_97 ) {
V_78 -> V_119 = 1 ;
F_61 ( & V_32 -> V_117 ,
F_62 ( V_32 -> V_33 ) ) ;
} else {
F_58 ( V_32 ,
V_78 -> V_10 -> V_108 . V_118 ,
V_120 ) ;
}
F_56 ( & V_88 ) ;
return 0 ;
}
static int F_63 ( struct V_75 * V_76 )
{
struct V_31 * V_32 = V_76 -> V_36 ;
struct V_60 * V_61 = V_32 -> V_61 ;
struct V_58 * V_77 = V_32 -> V_77 ;
struct V_58 * V_78 = V_32 -> V_78 ;
int V_14 = 0 ;
F_52 ( & V_88 ) ;
if ( V_32 -> V_80 -> V_89 && V_32 -> V_80 -> V_89 -> V_121 ) {
V_14 = V_32 -> V_80 -> V_89 -> V_121 ( V_76 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_33 ) ;
goto V_91;
}
}
if ( V_61 -> V_10 -> V_89 && V_61 -> V_10 -> V_89 -> V_121 ) {
V_14 = V_61 -> V_10 -> V_89 -> V_121 ( V_76 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_34 ) ;
goto V_91;
}
}
if ( V_78 -> V_10 -> V_89 -> V_121 ) {
V_14 = V_78 -> V_10 -> V_89 -> V_121 ( V_76 , V_78 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_35 ) ;
goto V_91;
}
}
if ( V_77 -> V_10 -> V_89 -> V_121 ) {
V_14 = V_77 -> V_10 -> V_89 -> V_121 ( V_76 , V_77 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_36 ) ;
goto V_91;
}
}
if ( V_76 -> V_96 == V_97 &&
V_78 -> V_119 ) {
V_78 -> V_119 = 0 ;
F_64 ( & V_32 -> V_117 ) ;
}
if ( V_76 -> V_96 == V_97 )
F_58 ( V_32 ,
V_78 -> V_10 -> V_100 . V_118 ,
V_122 ) ;
else
F_58 ( V_32 ,
V_78 -> V_10 -> V_108 . V_118 ,
V_122 ) ;
F_60 ( V_78 , 0 ) ;
V_91:
F_56 ( & V_88 ) ;
return V_14 ;
}
static int F_65 ( struct V_75 * V_76 ,
struct V_123 * V_124 )
{
struct V_31 * V_32 = V_76 -> V_36 ;
struct V_60 * V_61 = V_32 -> V_61 ;
struct V_58 * V_77 = V_32 -> V_77 ;
struct V_58 * V_78 = V_32 -> V_78 ;
int V_14 = 0 ;
F_52 ( & V_88 ) ;
if ( V_32 -> V_80 -> V_89 && V_32 -> V_80 -> V_89 -> V_125 ) {
V_14 = V_32 -> V_80 -> V_89 -> V_125 ( V_76 , V_124 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_37 ) ;
goto V_91;
}
}
if ( V_78 -> V_10 -> V_89 -> V_125 ) {
V_14 = V_78 -> V_10 -> V_89 -> V_125 ( V_76 , V_124 , V_78 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_38 ,
V_78 -> V_51 ) ;
goto V_126;
}
}
if ( V_77 -> V_10 -> V_89 -> V_125 ) {
V_14 = V_77 -> V_10 -> V_89 -> V_125 ( V_76 , V_124 , V_77 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_39 ,
V_77 -> V_51 ) ;
goto V_127;
}
}
if ( V_61 -> V_10 -> V_89 && V_61 -> V_10 -> V_89 -> V_125 ) {
V_14 = V_61 -> V_10 -> V_89 -> V_125 ( V_76 , V_124 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_40 ,
V_61 -> V_51 ) ;
goto V_93;
}
}
V_32 -> V_81 = F_66 ( V_124 ) ;
V_91:
F_56 ( & V_88 ) ;
return V_14 ;
V_93:
if ( V_77 -> V_10 -> V_89 -> V_128 )
V_77 -> V_10 -> V_89 -> V_128 ( V_76 , V_77 ) ;
V_127:
if ( V_78 -> V_10 -> V_89 -> V_128 )
V_78 -> V_10 -> V_89 -> V_128 ( V_76 , V_78 ) ;
V_126:
if ( V_32 -> V_80 -> V_89 && V_32 -> V_80 -> V_89 -> V_128 )
V_32 -> V_80 -> V_89 -> V_128 ( V_76 ) ;
F_56 ( & V_88 ) ;
return V_14 ;
}
static int F_67 ( struct V_75 * V_76 )
{
struct V_31 * V_32 = V_76 -> V_36 ;
struct V_60 * V_61 = V_32 -> V_61 ;
struct V_58 * V_77 = V_32 -> V_77 ;
struct V_58 * V_78 = V_32 -> V_78 ;
struct V_4 * V_5 = V_32 -> V_5 ;
F_52 ( & V_88 ) ;
if ( ! V_5 -> V_110 )
F_60 ( V_78 , 1 ) ;
if ( V_32 -> V_80 -> V_89 && V_32 -> V_80 -> V_89 -> V_128 )
V_32 -> V_80 -> V_89 -> V_128 ( V_76 ) ;
if ( V_61 -> V_10 -> V_89 && V_61 -> V_10 -> V_89 -> V_128 )
V_61 -> V_10 -> V_89 -> V_128 ( V_76 ) ;
if ( V_78 -> V_10 -> V_89 -> V_128 )
V_78 -> V_10 -> V_89 -> V_128 ( V_76 , V_78 ) ;
if ( V_77 -> V_10 -> V_89 -> V_128 )
V_77 -> V_10 -> V_89 -> V_128 ( V_76 , V_77 ) ;
F_56 ( & V_88 ) ;
return 0 ;
}
static int F_68 ( struct V_75 * V_76 , int V_129 )
{
struct V_31 * V_32 = V_76 -> V_36 ;
struct V_60 * V_61 = V_32 -> V_61 ;
struct V_58 * V_77 = V_32 -> V_77 ;
struct V_58 * V_78 = V_32 -> V_78 ;
int V_14 ;
if ( V_78 -> V_10 -> V_89 -> V_130 ) {
V_14 = V_78 -> V_10 -> V_89 -> V_130 ( V_76 , V_129 , V_78 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( V_61 -> V_10 -> V_89 && V_61 -> V_10 -> V_89 -> V_130 ) {
V_14 = V_61 -> V_10 -> V_89 -> V_130 ( V_76 , V_129 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( V_77 -> V_10 -> V_89 -> V_130 ) {
V_14 = V_77 -> V_10 -> V_89 -> V_130 ( V_76 , V_129 , V_77 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
static T_5 F_69 ( struct V_75 * V_76 )
{
struct V_31 * V_32 = V_76 -> V_36 ;
struct V_60 * V_61 = V_32 -> V_61 ;
struct V_58 * V_77 = V_32 -> V_77 ;
struct V_58 * V_78 = V_32 -> V_78 ;
struct V_84 * V_82 = V_76 -> V_82 ;
T_5 V_131 = 0 ;
T_6 V_132 = 0 ;
if ( V_61 -> V_10 -> V_89 && V_61 -> V_10 -> V_89 -> V_133 )
V_131 = V_61 -> V_10 -> V_89 -> V_133 ( V_76 ) ;
if ( V_77 -> V_10 -> V_89 -> V_132 )
V_132 += V_77 -> V_10 -> V_89 -> V_132 ( V_76 , V_77 ) ;
if ( V_78 -> V_10 -> V_89 -> V_132 )
V_132 += V_78 -> V_10 -> V_89 -> V_132 ( V_76 , V_78 ) ;
if ( V_61 -> V_10 -> V_132 )
V_132 += V_61 -> V_10 -> V_132 ( V_76 , V_78 ) ;
V_82 -> V_132 = V_132 ;
return V_131 ;
}
int F_70 ( struct V_27 * V_28 )
{
struct V_62 * V_49 = F_71 ( V_28 ) ;
struct V_4 * V_5 ;
int V_3 ;
if ( F_72 ( & V_49 -> V_134 ) )
return 0 ;
F_73 ( V_49 -> V_72 ) ;
F_74 ( V_49 -> V_72 , V_135 ) ;
F_75 ( V_49 -> V_72 ) ;
F_76 ( V_49 -> V_72 , V_136 ) ;
for ( V_3 = 0 ; V_3 < V_49 -> V_137 ; V_3 ++ ) {
struct V_58 * V_59 = V_49 -> V_32 [ V_3 ] . V_78 ;
struct V_85 * V_138 = V_59 -> V_10 ;
if ( V_49 -> V_32 [ V_3 ] . V_80 -> V_139 )
continue;
if ( V_138 -> V_89 -> V_140 && V_59 -> V_111 )
V_138 -> V_89 -> V_140 ( V_59 , 1 ) ;
}
for ( V_3 = 0 ; V_3 < V_49 -> V_137 ; V_3 ++ ) {
if ( V_49 -> V_32 [ V_3 ] . V_80 -> V_139 )
continue;
F_77 ( V_49 -> V_32 [ V_3 ] . V_141 ) ;
}
if ( V_49 -> V_142 )
V_49 -> V_142 ( V_49 ) ;
for ( V_3 = 0 ; V_3 < V_49 -> V_137 ; V_3 ++ ) {
struct V_58 * V_77 = V_49 -> V_32 [ V_3 ] . V_77 ;
struct V_60 * V_61 = V_49 -> V_32 [ V_3 ] . V_61 ;
if ( V_49 -> V_32 [ V_3 ] . V_80 -> V_139 )
continue;
if ( V_77 -> V_10 -> V_143 && ! V_77 -> V_10 -> V_144 )
V_77 -> V_10 -> V_143 ( V_77 ) ;
if ( V_61 -> V_10 -> V_143 && ! V_61 -> V_145 ) {
V_61 -> V_10 -> V_143 ( V_77 ) ;
V_61 -> V_145 = 1 ;
}
}
for ( V_3 = 0 ; V_3 < V_49 -> V_137 ; V_3 ++ ) {
F_78 ( & V_49 -> V_32 [ V_3 ] . V_117 ) ;
V_49 -> V_32 [ V_3 ] . V_5 -> V_57 . V_146 = V_49 -> V_32 [ V_3 ] . V_5 -> V_57 . V_147 ;
}
for ( V_3 = 0 ; V_3 < V_49 -> V_137 ; V_3 ++ ) {
struct V_85 * V_10 = V_49 -> V_32 [ V_3 ] . V_78 -> V_10 ;
if ( V_49 -> V_32 [ V_3 ] . V_80 -> V_139 )
continue;
if ( V_10 -> V_100 . V_118 != NULL )
F_58 ( & V_49 -> V_32 [ V_3 ] , V_10 -> V_100 . V_118 ,
V_148 ) ;
if ( V_10 -> V_108 . V_118 != NULL )
F_58 ( & V_49 -> V_32 [ V_3 ] , V_10 -> V_108 . V_118 ,
V_148 ) ;
}
F_32 (codec, &card->codec_dev_list, card_list) {
if ( ! V_5 -> V_145 && V_5 -> V_10 -> V_143 ) {
switch ( V_5 -> V_57 . V_147 ) {
case V_149 :
case V_150 :
V_5 -> V_10 -> V_143 ( V_5 , V_151 ) ;
V_5 -> V_145 = 1 ;
break;
default:
F_48 ( V_5 -> V_28 , L_41 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_49 -> V_137 ; V_3 ++ ) {
struct V_58 * V_77 = V_49 -> V_32 [ V_3 ] . V_77 ;
if ( V_49 -> V_32 [ V_3 ] . V_80 -> V_139 )
continue;
if ( V_77 -> V_10 -> V_143 && V_77 -> V_10 -> V_144 )
V_77 -> V_10 -> V_143 ( V_77 ) ;
}
if ( V_49 -> V_152 )
V_49 -> V_152 ( V_49 ) ;
return 0 ;
}
static void F_79 ( struct V_115 * V_116 )
{
struct V_62 * V_49 =
F_8 ( V_116 , struct V_62 , V_153 ) ;
struct V_4 * V_5 ;
int V_3 ;
F_48 ( V_49 -> V_28 , L_42 ) ;
F_76 ( V_49 -> V_72 , V_154 ) ;
if ( V_49 -> V_155 )
V_49 -> V_155 ( V_49 ) ;
for ( V_3 = 0 ; V_3 < V_49 -> V_137 ; V_3 ++ ) {
struct V_58 * V_77 = V_49 -> V_32 [ V_3 ] . V_77 ;
if ( V_49 -> V_32 [ V_3 ] . V_80 -> V_139 )
continue;
if ( V_77 -> V_10 -> V_156 && V_77 -> V_10 -> V_144 )
V_77 -> V_10 -> V_156 ( V_77 ) ;
}
F_32 (codec, &card->codec_dev_list, card_list) {
if ( V_5 -> V_10 -> V_156 && V_5 -> V_145 ) {
switch ( V_5 -> V_57 . V_147 ) {
case V_149 :
case V_150 :
V_5 -> V_10 -> V_156 ( V_5 ) ;
V_5 -> V_145 = 0 ;
break;
default:
F_48 ( V_5 -> V_28 , L_43 ) ;
break;
}
}
}
for ( V_3 = 0 ; V_3 < V_49 -> V_137 ; V_3 ++ ) {
struct V_85 * V_10 = V_49 -> V_32 [ V_3 ] . V_78 -> V_10 ;
if ( V_49 -> V_32 [ V_3 ] . V_80 -> V_139 )
continue;
if ( V_10 -> V_100 . V_118 != NULL )
F_58 ( & V_49 -> V_32 [ V_3 ] , V_10 -> V_100 . V_118 ,
V_157 ) ;
if ( V_10 -> V_108 . V_118 != NULL )
F_58 ( & V_49 -> V_32 [ V_3 ] , V_10 -> V_108 . V_118 ,
V_157 ) ;
}
for ( V_3 = 0 ; V_3 < V_49 -> V_137 ; V_3 ++ ) {
struct V_58 * V_59 = V_49 -> V_32 [ V_3 ] . V_78 ;
struct V_85 * V_138 = V_59 -> V_10 ;
if ( V_49 -> V_32 [ V_3 ] . V_80 -> V_139 )
continue;
if ( V_138 -> V_89 -> V_140 && V_59 -> V_111 )
V_138 -> V_89 -> V_140 ( V_59 , 0 ) ;
}
for ( V_3 = 0 ; V_3 < V_49 -> V_137 ; V_3 ++ ) {
struct V_58 * V_77 = V_49 -> V_32 [ V_3 ] . V_77 ;
struct V_60 * V_61 = V_49 -> V_32 [ V_3 ] . V_61 ;
if ( V_49 -> V_32 [ V_3 ] . V_80 -> V_139 )
continue;
if ( V_77 -> V_10 -> V_156 && ! V_77 -> V_10 -> V_144 )
V_77 -> V_10 -> V_156 ( V_77 ) ;
if ( V_61 -> V_10 -> V_156 && V_61 -> V_145 ) {
V_61 -> V_10 -> V_156 ( V_77 ) ;
V_61 -> V_145 = 0 ;
}
}
if ( V_49 -> V_158 )
V_49 -> V_158 ( V_49 ) ;
F_48 ( V_49 -> V_28 , L_44 ) ;
F_76 ( V_49 -> V_72 , V_135 ) ;
}
int F_80 ( struct V_27 * V_28 )
{
struct V_62 * V_49 = F_71 ( V_28 ) ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_49 -> V_137 ; V_3 ++ ) {
struct V_58 * V_77 = V_49 -> V_32 [ V_3 ] . V_77 ;
if ( V_77 -> V_10 -> V_144 ) {
F_48 ( V_28 , L_45 ) ;
F_79 ( & V_49 -> V_153 ) ;
} else {
F_48 ( V_28 , L_46 ) ;
if ( ! F_81 ( & V_49 -> V_153 ) )
F_50 ( V_28 , L_47 ) ;
}
}
return 0 ;
}
static int F_82 ( struct V_62 * V_49 , int V_159 )
{
struct V_160 * V_80 = & V_49 -> V_80 [ V_159 ] ;
struct V_31 * V_32 = & V_49 -> V_32 [ V_159 ] ;
struct V_4 * V_5 ;
struct V_60 * V_61 ;
struct V_58 * V_78 , * V_77 ;
const char * V_161 ;
if ( V_32 -> V_162 )
return 1 ;
F_48 ( V_49 -> V_28 , L_48 , V_80 -> V_51 , V_159 ) ;
if ( V_32 -> V_77 ) {
goto V_163;
}
F_32 (cpu_dai, &dai_list, list) {
if ( ! strcmp ( V_77 -> V_51 , V_80 -> V_164 ) ) {
V_32 -> V_77 = V_77 ;
goto V_163;
}
}
F_48 ( V_49 -> V_28 , L_49 ,
V_80 -> V_164 ) ;
V_163:
if ( V_32 -> V_5 ) {
goto V_165;
}
F_32 (codec, &codec_list, list) {
if ( ! strcmp ( V_5 -> V_51 , V_80 -> V_166 ) ) {
V_32 -> V_5 = V_5 ;
F_32 (codec_dai, &dai_list, list) {
if ( V_5 -> V_28 == V_78 -> V_28 &&
! strcmp ( V_78 -> V_51 , V_80 -> V_167 ) ) {
V_32 -> V_78 = V_78 ;
goto V_165;
}
}
F_48 ( V_49 -> V_28 , L_50 ,
V_80 -> V_167 ) ;
goto V_165;
}
}
F_48 ( V_49 -> V_28 , L_51 ,
V_80 -> V_166 ) ;
V_165:
if ( V_32 -> V_61 )
goto V_91;
V_161 = V_80 -> V_161 ;
if ( ! V_161 )
V_161 = L_52 ;
F_32 (platform, &platform_list, list) {
if ( ! strcmp ( V_61 -> V_51 , V_161 ) ) {
V_32 -> V_61 = V_61 ;
goto V_91;
}
}
F_48 ( V_49 -> V_28 , L_53 ,
V_80 -> V_161 ) ;
return 0 ;
V_91:
if ( V_32 -> V_5 && V_32 -> V_78 && V_32 -> V_61 && V_32 -> V_77 ) {
V_32 -> V_162 = 1 ;
V_49 -> V_137 ++ ;
}
return 1 ;
}
static void F_83 ( struct V_4 * V_5 )
{
int V_68 ;
if ( V_5 -> V_10 -> remove ) {
V_68 = V_5 -> V_10 -> remove ( V_5 ) ;
if ( V_68 < 0 )
F_50 ( V_5 -> V_28 ,
L_54 ,
V_5 -> V_51 , V_68 ) ;
}
F_84 ( & V_5 -> V_57 ) ;
F_29 ( V_5 ) ;
V_5 -> V_168 = 0 ;
F_85 ( & V_5 -> V_169 ) ;
F_86 ( V_5 -> V_28 -> V_10 -> V_170 ) ;
}
static void F_87 ( struct V_62 * V_49 , int V_159 )
{
struct V_31 * V_32 = & V_49 -> V_32 [ V_159 ] ;
struct V_4 * V_5 = V_32 -> V_5 ;
struct V_60 * V_61 = V_32 -> V_61 ;
struct V_58 * V_78 = V_32 -> V_78 , * V_77 = V_32 -> V_77 ;
int V_68 ;
if ( V_32 -> V_171 ) {
F_88 ( & V_32 -> V_28 , & V_172 ) ;
F_88 ( & V_32 -> V_28 , & V_173 ) ;
F_41 ( & V_32 -> V_28 ) ;
V_32 -> V_171 = 0 ;
}
if ( V_78 && V_78 -> V_168 ) {
if ( V_78 -> V_10 -> remove ) {
V_68 = V_78 -> V_10 -> remove ( V_78 ) ;
if ( V_68 < 0 )
F_25 ( V_74 L_55 , V_78 -> V_51 ) ;
}
V_78 -> V_168 = 0 ;
F_85 ( & V_78 -> V_169 ) ;
}
if ( V_61 && V_61 -> V_168 ) {
if ( V_61 -> V_10 -> remove ) {
V_68 = V_61 -> V_10 -> remove ( V_61 ) ;
if ( V_68 < 0 )
F_25 ( V_74 L_55 , V_61 -> V_51 ) ;
}
V_61 -> V_168 = 0 ;
F_85 ( & V_61 -> V_169 ) ;
F_86 ( V_61 -> V_28 -> V_10 -> V_170 ) ;
}
if ( V_5 && V_5 -> V_168 )
F_83 ( V_5 ) ;
if ( V_77 && V_77 -> V_168 ) {
if ( V_77 -> V_10 -> remove ) {
V_68 = V_77 -> V_10 -> remove ( V_77 ) ;
if ( V_68 < 0 )
F_25 ( V_74 L_55 , V_77 -> V_51 ) ;
}
V_77 -> V_168 = 0 ;
F_85 ( & V_77 -> V_169 ) ;
F_86 ( V_77 -> V_28 -> V_10 -> V_170 ) ;
}
}
static void F_89 ( struct V_62 * V_49 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_49 -> V_137 ; V_3 ++ )
F_87 ( V_49 , V_3 ) ;
V_49 -> V_137 = 0 ;
}
static void F_90 ( struct V_62 * V_49 ,
struct V_4 * V_5 )
{
int V_3 ;
if ( V_49 -> V_174 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_49 -> V_175 ; V_3 ++ ) {
struct V_176 * V_177 = & V_49 -> V_174 [ V_3 ] ;
if ( V_177 -> V_178 && ! strcmp ( V_5 -> V_51 , V_177 -> V_178 ) ) {
V_5 -> V_179 = V_177 -> V_179 ;
break;
}
}
}
static int F_91 ( struct V_62 * V_49 ,
struct V_4 * V_5 )
{
int V_14 = 0 ;
const struct V_180 * V_10 = V_5 -> V_10 ;
V_5 -> V_49 = V_49 ;
V_5 -> V_57 . V_49 = V_49 ;
F_90 ( V_49 , V_5 ) ;
if ( ! F_92 ( V_5 -> V_28 -> V_10 -> V_170 ) )
return - V_181 ;
F_23 ( V_5 ) ;
if ( V_10 -> V_182 )
F_93 ( & V_5 -> V_57 , V_10 -> V_182 ,
V_10 -> V_183 ) ;
if ( V_10 -> V_184 ) {
V_14 = V_10 -> V_184 ( V_5 ) ;
if ( V_14 < 0 ) {
F_50 ( V_5 -> V_28 ,
L_56 ,
V_5 -> V_51 , V_14 ) ;
goto V_185;
}
}
if ( V_10 -> V_186 )
F_94 ( V_5 , V_10 -> V_186 ,
V_10 -> V_187 ) ;
if ( V_10 -> V_188 )
F_95 ( & V_5 -> V_57 , V_10 -> V_188 ,
V_10 -> V_189 ) ;
V_5 -> V_168 = 1 ;
F_96 ( & V_5 -> V_169 , & V_49 -> V_134 ) ;
F_96 ( & V_5 -> V_57 . V_190 , & V_49 -> V_191 ) ;
return 0 ;
V_185:
F_29 ( V_5 ) ;
F_86 ( V_5 -> V_28 -> V_10 -> V_170 ) ;
return V_14 ;
}
static void F_97 ( struct V_27 * V_28 ) {}
static int F_98 ( struct V_62 * V_49 ,
struct V_4 * V_5 ,
int V_159 , int V_192 )
{
struct V_160 * V_80 = NULL ;
struct V_193 * V_194 = NULL ;
struct V_31 * V_32 ;
const char * V_195 , * V_51 ;
int V_14 = 0 ;
if ( ! V_192 ) {
V_80 = & V_49 -> V_80 [ V_159 ] ;
V_32 = & V_49 -> V_32 [ V_159 ] ;
V_51 = V_80 -> V_51 ;
} else {
V_194 = & V_49 -> V_194 [ V_159 ] ;
V_32 = & V_49 -> V_196 [ V_159 ] ;
V_51 = V_194 -> V_51 ;
}
V_32 -> V_49 = V_49 ;
V_195 = V_5 -> V_179 ;
V_5 -> V_179 = NULL ;
if ( ! V_192 && V_80 -> V_197 )
V_14 = V_80 -> V_197 ( V_32 ) ;
else if ( V_192 && V_194 -> V_197 )
V_14 = V_194 -> V_197 ( & V_5 -> V_57 ) ;
if ( V_14 < 0 ) {
F_50 ( V_49 -> V_28 , L_57 , V_51 , V_14 ) ;
return V_14 ;
}
V_5 -> V_179 = V_195 ;
F_99 ( & V_5 -> V_57 ) ;
V_32 -> V_5 = V_5 ;
V_32 -> V_28 . V_70 = V_49 -> V_28 ;
V_32 -> V_28 . V_71 = F_97 ;
V_32 -> V_28 . V_198 = V_51 ;
V_14 = F_45 ( & V_32 -> V_28 ) ;
if ( V_14 < 0 ) {
F_50 ( V_49 -> V_28 ,
L_58 , V_14 ) ;
return V_14 ;
}
V_32 -> V_171 = 1 ;
V_14 = F_100 ( & V_32 -> V_28 ) ;
if ( V_14 < 0 )
F_50 ( V_5 -> V_28 ,
L_59 ,
V_14 ) ;
V_14 = F_101 ( & V_32 -> V_28 , & V_173 ) ;
if ( V_14 < 0 )
F_50 ( V_5 -> V_28 ,
L_60 , V_14 ) ;
return 0 ;
}
static int F_102 ( struct V_62 * V_49 , int V_159 )
{
struct V_160 * V_80 = & V_49 -> V_80 [ V_159 ] ;
struct V_31 * V_32 = & V_49 -> V_32 [ V_159 ] ;
struct V_4 * V_5 = V_32 -> V_5 ;
struct V_60 * V_61 = V_32 -> V_61 ;
struct V_58 * V_78 = V_32 -> V_78 , * V_77 = V_32 -> V_77 ;
int V_14 ;
F_48 ( V_49 -> V_28 , L_61 , V_49 -> V_51 , V_159 ) ;
V_78 -> V_5 = V_5 ;
V_77 -> V_61 = V_61 ;
V_78 -> V_49 = V_49 ;
V_77 -> V_49 = V_49 ;
V_32 -> V_33 = V_33 ;
if ( ! V_77 -> V_168 ) {
if ( ! F_92 ( V_77 -> V_28 -> V_10 -> V_170 ) )
return - V_181 ;
if ( V_77 -> V_10 -> V_184 ) {
V_14 = V_77 -> V_10 -> V_184 ( V_77 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_62 ,
V_77 -> V_51 ) ;
F_86 ( V_77 -> V_28 -> V_10 -> V_170 ) ;
return V_14 ;
}
}
V_77 -> V_168 = 1 ;
F_96 ( & V_77 -> V_169 , & V_49 -> V_199 ) ;
}
if ( ! V_5 -> V_168 ) {
V_14 = F_91 ( V_49 , V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( ! V_61 -> V_168 ) {
if ( ! F_92 ( V_61 -> V_28 -> V_10 -> V_170 ) )
return - V_181 ;
if ( V_61 -> V_10 -> V_184 ) {
V_14 = V_61 -> V_10 -> V_184 ( V_61 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_63 ,
V_61 -> V_51 ) ;
F_86 ( V_61 -> V_28 -> V_10 -> V_170 ) ;
return V_14 ;
}
}
V_61 -> V_168 = 1 ;
F_96 ( & V_61 -> V_169 , & V_49 -> V_200 ) ;
}
if ( ! V_78 -> V_168 ) {
if ( V_78 -> V_10 -> V_184 ) {
V_14 = V_78 -> V_10 -> V_184 ( V_78 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_64 ,
V_78 -> V_51 ) ;
return V_14 ;
}
}
V_78 -> V_168 = 1 ;
F_96 ( & V_78 -> V_169 , & V_49 -> V_199 ) ;
}
F_103 ( & V_32 -> V_117 , F_57 ) ;
V_14 = F_98 ( V_49 , V_5 , V_159 , 0 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_101 ( & V_32 -> V_28 , & V_172 ) ;
if ( V_14 < 0 )
F_25 ( V_52 L_65 ) ;
V_14 = F_104 ( V_32 , V_159 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_66 , V_80 -> V_118 ) ;
return V_14 ;
}
if ( V_32 -> V_78 -> V_10 -> V_144 )
F_105 ( V_5 -> V_66 , V_32 -> V_77 -> V_201 ) ;
return 0 ;
}
static int F_106 ( struct V_31 * V_32 )
{
int V_14 ;
if ( V_32 -> V_78 -> V_10 -> V_144 && ! V_32 -> V_5 -> V_202 ) {
if ( ! V_32 -> V_5 -> V_203 )
return 0 ;
V_14 = F_43 ( V_32 -> V_5 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_67 ) ;
return V_14 ;
}
V_32 -> V_5 -> V_202 = 1 ;
}
return 0 ;
}
static void F_107 ( struct V_4 * V_5 )
{
if ( V_5 -> V_202 ) {
F_40 ( V_5 ) ;
V_5 -> V_202 = 0 ;
}
}
static int F_108 ( struct V_62 * V_49 , int V_159 )
{
struct V_193 * V_194 = & V_49 -> V_194 [ V_159 ] ;
struct V_4 * V_5 ;
int V_14 = - V_181 ;
F_32 (codec, &codec_list, list) {
if ( ! strcmp ( V_5 -> V_51 , V_194 -> V_166 ) ) {
if ( V_5 -> V_168 ) {
F_50 ( V_5 -> V_28 ,
L_68 ) ;
V_14 = - V_204 ;
goto V_91;
}
goto V_205;
}
}
F_50 ( V_49 -> V_28 , L_69 , V_194 -> V_166 ) ;
goto V_91;
V_205:
V_14 = F_91 ( V_49 , V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_98 ( V_49 , V_5 , V_159 , 1 ) ;
V_91:
return V_14 ;
}
static void F_109 ( struct V_62 * V_49 , int V_159 )
{
struct V_31 * V_32 = & V_49 -> V_196 [ V_159 ] ;
struct V_4 * V_5 = V_32 -> V_5 ;
if ( V_32 -> V_171 ) {
F_88 ( & V_32 -> V_28 , & V_173 ) ;
F_41 ( & V_32 -> V_28 ) ;
V_32 -> V_171 = 0 ;
}
if ( V_5 && V_5 -> V_168 )
F_83 ( V_5 ) ;
}
static int F_110 ( struct V_4 * V_5 ,
enum V_206 V_207 )
{
int V_14 ;
if ( V_5 -> V_208 )
return 0 ;
if ( V_207 && V_5 -> V_207 != V_207 )
V_5 -> V_207 = V_207 ;
V_14 = F_111 ( V_5 ) ;
if ( V_14 < 0 ) {
F_50 ( V_5 -> V_28 , L_70 ,
V_14 ) ;
return V_14 ;
}
V_5 -> V_208 = 1 ;
return 0 ;
}
static void F_112 ( struct V_62 * V_49 )
{
struct V_4 * V_5 ;
struct V_176 * V_174 ;
enum V_206 V_207 ;
int V_14 , V_3 ;
F_52 ( & V_49 -> V_209 ) ;
if ( V_49 -> V_210 ) {
F_56 ( & V_49 -> V_209 ) ;
return;
}
for ( V_3 = 0 ; V_3 < V_49 -> V_211 ; V_3 ++ )
F_82 ( V_49 , V_3 ) ;
if ( V_49 -> V_137 != V_49 -> V_211 ) {
F_56 ( & V_49 -> V_209 ) ;
return;
}
F_32 (codec, &codec_list, list) {
if ( V_5 -> V_208 )
continue;
V_207 = 0 ;
for ( V_3 = 0 ; V_3 < V_49 -> V_175 ; ++ V_3 ) {
V_174 = & V_49 -> V_174 [ V_3 ] ;
if ( ! strcmp ( V_5 -> V_51 , V_174 -> V_178 ) ) {
V_207 = V_174 -> V_207 ;
if ( V_207 && V_207
!= V_5 -> V_207 )
break;
}
}
V_14 = F_110 ( V_5 , V_207 ) ;
if ( V_14 < 0 ) {
F_56 ( & V_49 -> V_209 ) ;
return;
}
}
V_14 = F_113 ( V_212 , V_213 ,
V_49 -> V_170 , 0 , & V_49 -> V_72 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_71 ,
V_49 -> V_51 ) ;
F_56 ( & V_49 -> V_209 ) ;
return;
}
V_49 -> V_72 -> V_28 = V_49 -> V_28 ;
V_49 -> V_57 . V_147 = V_150 ;
V_49 -> V_57 . V_28 = V_49 -> V_28 ;
V_49 -> V_57 . V_49 = V_49 ;
F_96 ( & V_49 -> V_57 . V_190 , & V_49 -> V_191 ) ;
#ifdef F_114
F_28 ( & V_49 -> V_57 , V_49 -> V_48 ) ;
#endif
#ifdef F_115
F_116 ( & V_49 -> V_153 , F_79 ) ;
#endif
if ( V_49 -> V_182 )
F_93 ( & V_49 -> V_57 , V_49 -> V_182 ,
V_49 -> V_183 ) ;
if ( V_49 -> V_184 ) {
V_14 = V_49 -> V_184 ( V_49 ) ;
if ( V_14 < 0 )
goto V_214;
}
for ( V_3 = 0 ; V_3 < V_49 -> V_211 ; V_3 ++ ) {
V_14 = F_102 ( V_49 , V_3 ) ;
if ( V_14 < 0 ) {
F_117 ( L_72 ,
V_49 -> V_51 , V_14 ) ;
goto V_215;
}
}
for ( V_3 = 0 ; V_3 < V_49 -> V_216 ; V_3 ++ ) {
V_14 = F_108 ( V_49 , V_3 ) ;
if ( V_14 < 0 ) {
F_117 ( L_73 ,
V_49 -> V_51 , V_14 ) ;
goto V_217;
}
}
if ( V_49 -> V_186 )
F_94 ( F_118 ( & V_49 -> V_134 ,
struct V_4 ,
V_169 ) ,
V_49 -> V_186 ,
V_49 -> V_187 ) ;
if ( V_49 -> V_188 )
F_95 ( & V_49 -> V_57 , V_49 -> V_188 ,
V_49 -> V_189 ) ;
snprintf ( V_49 -> V_72 -> V_218 , sizeof( V_49 -> V_72 -> V_218 ) ,
L_74 , V_49 -> V_51 ) ;
snprintf ( V_49 -> V_72 -> V_219 , sizeof( V_49 -> V_72 -> V_219 ) ,
L_74 , V_49 -> V_220 ? V_49 -> V_220 : V_49 -> V_51 ) ;
if ( V_49 -> V_221 )
F_119 ( V_49 -> V_72 -> V_10 , V_49 -> V_221 ,
sizeof( V_49 -> V_72 -> V_10 ) ) ;
if ( V_49 -> V_222 ) {
V_14 = V_49 -> V_222 ( V_49 ) ;
if ( V_14 < 0 ) {
F_50 ( V_49 -> V_28 , L_75 ,
V_49 -> V_51 , V_14 ) ;
goto V_217;
}
}
V_14 = F_120 ( V_49 -> V_72 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_76 , V_49 -> V_51 ) ;
goto V_217;
}
#ifdef F_121
for ( V_3 = 0 ; V_3 < V_49 -> V_137 ; V_3 ++ ) {
V_14 = F_106 ( & V_49 -> V_32 [ V_3 ] ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_77 , V_49 -> V_51 ) ;
while ( -- V_3 >= 0 )
F_107 ( V_49 -> V_32 [ V_3 ] . V_5 ) ;
goto V_217;
}
}
#endif
V_49 -> V_210 = 1 ;
F_56 ( & V_49 -> V_209 ) ;
return;
V_217:
for ( V_3 = 0 ; V_3 < V_49 -> V_216 ; V_3 ++ )
F_109 ( V_49 , V_3 ) ;
V_215:
F_89 ( V_49 ) ;
V_214:
if ( V_49 -> remove )
V_49 -> remove ( V_49 ) ;
F_122 ( V_49 -> V_72 ) ;
F_56 ( & V_49 -> V_209 ) ;
}
static void F_123 ( void )
{
struct V_62 * V_49 ;
F_32 (card, &card_list, list)
F_112 ( V_49 ) ;
}
static int F_124 ( struct V_223 * V_224 )
{
struct V_62 * V_49 = F_125 ( V_224 ) ;
int V_14 = 0 ;
if ( ! V_49 )
return - V_17 ;
V_49 -> V_28 = & V_224 -> V_28 ;
V_14 = F_126 ( V_49 ) ;
if ( V_14 != 0 ) {
F_50 ( & V_224 -> V_28 , L_78 ) ;
return V_14 ;
}
return 0 ;
}
static int F_127 ( struct V_62 * V_49 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_49 -> V_137 ; V_3 ++ ) {
struct V_31 * V_32 = & V_49 -> V_32 [ V_3 ] ;
F_78 ( & V_32 -> V_117 ) ;
}
for ( V_3 = 0 ; V_3 < V_49 -> V_216 ; V_3 ++ )
F_109 ( V_49 , V_3 ) ;
F_89 ( V_49 ) ;
F_39 ( V_49 ) ;
if ( V_49 -> remove )
V_49 -> remove ( V_49 ) ;
F_84 ( & V_49 -> V_57 ) ;
F_16 ( V_49 -> V_32 ) ;
F_122 ( V_49 -> V_72 ) ;
return 0 ;
}
static int F_128 ( struct V_223 * V_224 )
{
struct V_62 * V_49 = F_125 ( V_224 ) ;
F_129 ( V_49 ) ;
return 0 ;
}
int F_130 ( struct V_27 * V_28 )
{
struct V_62 * V_49 = F_71 ( V_28 ) ;
int V_3 ;
if ( ! V_49 -> V_210 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_49 -> V_137 ; V_3 ++ ) {
struct V_31 * V_32 = & V_49 -> V_32 [ V_3 ] ;
F_78 ( & V_32 -> V_117 ) ;
}
F_131 ( V_49 ) ;
return 0 ;
}
static int F_104 ( struct V_31 * V_32 , int V_159 )
{
struct V_4 * V_5 = V_32 -> V_5 ;
struct V_60 * V_61 = V_32 -> V_61 ;
struct V_58 * V_78 = V_32 -> V_78 ;
struct V_58 * V_77 = V_32 -> V_77 ;
struct V_225 * V_141 ;
char V_226 [ 64 ] ;
int V_14 = 0 , V_100 = 0 , V_108 = 0 ;
snprintf ( V_226 , sizeof( V_226 ) , L_79 ,
V_32 -> V_80 -> V_118 , V_78 -> V_51 , V_159 ) ;
if ( V_78 -> V_10 -> V_100 . V_102 )
V_100 = 1 ;
if ( V_78 -> V_10 -> V_108 . V_102 )
V_108 = 1 ;
F_48 ( V_32 -> V_49 -> V_28 , L_80 , V_159 , V_226 ) ;
V_14 = F_132 ( V_32 -> V_49 -> V_72 , V_226 ,
V_159 , V_100 , V_108 , & V_141 ) ;
if ( V_14 < 0 ) {
F_25 ( V_74 L_81 , V_5 -> V_51 ) ;
return V_14 ;
}
V_32 -> V_141 = V_141 ;
V_141 -> V_36 = V_32 ;
if ( V_61 -> V_10 -> V_89 ) {
V_227 . V_228 = V_61 -> V_10 -> V_89 -> V_228 ;
V_227 . V_133 = V_61 -> V_10 -> V_89 -> V_133 ;
V_227 . V_229 = V_61 -> V_10 -> V_89 -> V_229 ;
V_227 . V_230 = V_61 -> V_10 -> V_89 -> V_230 ;
V_227 . V_231 = V_61 -> V_10 -> V_89 -> V_231 ;
V_227 . V_232 = V_61 -> V_10 -> V_89 -> V_232 ;
V_227 . V_233 = V_61 -> V_10 -> V_89 -> V_233 ;
}
if ( V_100 )
F_133 ( V_141 , V_97 , & V_227 ) ;
if ( V_108 )
F_133 ( V_141 , V_234 , & V_227 ) ;
if ( V_61 -> V_10 -> V_235 ) {
V_14 = V_61 -> V_10 -> V_235 ( V_32 -> V_49 -> V_72 ,
V_78 , V_141 ) ;
if ( V_14 < 0 ) {
F_117 ( L_82 ) ;
return V_14 ;
}
}
V_141 -> V_236 = V_61 -> V_10 -> V_237 ;
F_25 ( V_238 L_83 , V_78 -> V_51 ,
V_77 -> V_51 ) ;
return V_14 ;
}
int F_134 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_239 )
return V_5 -> V_239 ( V_5 , V_6 ) ;
else
return 0 ;
}
int F_135 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_24 )
return V_5 -> V_24 ( V_5 , V_6 ) ;
else
return 0 ;
}
int F_136 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
if ( V_5 -> V_240 )
return V_5 -> V_240 ( V_5 , V_6 ) ;
else
return 0 ;
}
int F_137 ( struct V_4 * V_5 ,
struct V_241 * V_89 , int V_159 )
{
F_52 ( & V_5 -> V_209 ) ;
V_5 -> V_66 = F_138 ( sizeof( struct V_242 ) , V_40 ) ;
if ( V_5 -> V_66 == NULL ) {
F_56 ( & V_5 -> V_209 ) ;
return - V_41 ;
}
V_5 -> V_66 -> V_67 = F_138 ( sizeof( struct V_243 ) , V_40 ) ;
if ( V_5 -> V_66 -> V_67 == NULL ) {
F_16 ( V_5 -> V_66 ) ;
V_5 -> V_66 = NULL ;
F_56 ( & V_5 -> V_209 ) ;
return - V_41 ;
}
V_5 -> V_66 -> V_67 -> V_89 = V_89 ;
V_5 -> V_66 -> V_159 = V_159 ;
V_5 -> V_203 = 1 ;
F_56 ( & V_5 -> V_209 ) ;
return 0 ;
}
void F_139 ( struct V_4 * V_5 )
{
F_52 ( & V_5 -> V_209 ) ;
#ifdef F_121
F_107 ( V_5 ) ;
#endif
F_16 ( V_5 -> V_66 -> V_67 ) ;
F_16 ( V_5 -> V_66 ) ;
V_5 -> V_66 = NULL ;
V_5 -> V_203 = 0 ;
F_56 ( & V_5 -> V_209 ) ;
}
unsigned int F_4 ( struct V_4 * V_5 , unsigned int V_6 )
{
unsigned int V_14 ;
V_14 = V_5 -> V_244 ( V_5 , V_6 ) ;
F_48 ( V_5 -> V_28 , L_84 , V_6 , V_14 ) ;
F_140 ( V_5 , V_6 , V_14 ) ;
return V_14 ;
}
unsigned int F_22 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned int V_1 )
{
F_48 ( V_5 -> V_28 , L_85 , V_6 , V_1 ) ;
F_141 ( V_5 , V_6 , V_1 ) ;
return V_5 -> V_245 ( V_5 , V_6 , V_1 ) ;
}
unsigned int F_142 ( struct V_4 * V_5 ,
unsigned int V_6 , const void * V_246 , T_1 V_8 )
{
return V_5 -> V_247 ( V_5 , V_6 , V_246 , V_8 ) ;
}
int F_143 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_248 , unsigned int V_45 )
{
int V_249 ;
unsigned int V_250 , V_251 ;
int V_14 ;
V_14 = F_4 ( V_5 , V_6 ) ;
if ( V_14 < 0 )
return V_14 ;
V_250 = V_14 ;
V_251 = ( V_250 & ~ V_248 ) | V_45 ;
V_249 = V_250 != V_251 ;
if ( V_249 ) {
V_14 = F_22 ( V_5 , V_6 , V_251 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return V_249 ;
}
int F_144 ( struct V_4 * V_5 ,
unsigned short V_6 , unsigned int V_248 ,
unsigned int V_45 )
{
int V_249 ;
F_52 ( & V_5 -> V_209 ) ;
V_249 = F_143 ( V_5 , V_6 , V_248 , V_45 ) ;
F_56 ( & V_5 -> V_209 ) ;
return V_249 ;
}
int F_145 ( struct V_4 * V_5 , unsigned short V_6 ,
unsigned int V_248 , unsigned int V_45 )
{
int V_249 ;
unsigned int V_250 , V_251 ;
V_250 = F_4 ( V_5 , V_6 ) ;
V_251 = ( V_250 & ~ V_248 ) | V_45 ;
V_249 = V_250 != V_251 ;
return V_249 ;
}
int F_146 ( struct V_75 * V_76 ,
const struct V_252 * V_98 )
{
struct V_84 * V_82 = V_76 -> V_82 ;
V_82 -> V_98 . V_253 = V_98 -> V_253 ;
V_82 -> V_98 . V_104 = V_98 -> V_104 ;
V_82 -> V_98 . V_254 = V_98 -> V_254 ;
V_82 -> V_98 . V_255 = V_98 -> V_255 ;
V_82 -> V_98 . V_256 = V_98 -> V_256 ;
V_82 -> V_98 . V_257 = V_98 -> V_257 ;
V_82 -> V_98 . V_258 = V_98 -> V_258 ;
V_82 -> V_98 . V_259 = V_98 -> V_259 ;
return 0 ;
}
struct V_260 * F_147 ( const struct V_261 * V_262 ,
void * V_246 , char * V_220 ,
const char * V_263 )
{
struct V_261 V_264 ;
struct V_260 * V_265 ;
char * V_51 = NULL ;
int V_266 ;
memcpy ( & V_264 , V_262 , sizeof( V_264 ) ) ;
V_264 . V_267 = 0 ;
if ( ! V_220 )
V_220 = V_264 . V_51 ;
if ( V_263 ) {
V_266 = strlen ( V_220 ) + strlen ( V_263 ) + 2 ;
V_51 = F_14 ( V_266 , V_268 ) ;
if ( ! V_51 )
return NULL ;
snprintf ( V_51 , V_266 , L_86 , V_263 , V_220 ) ;
V_264 . V_51 = V_51 ;
} else {
V_264 . V_51 = V_220 ;
}
V_265 = F_148 ( & V_264 , V_246 ) ;
F_16 ( V_51 ) ;
return V_265 ;
}
int F_94 ( struct V_4 * V_5 ,
const struct V_261 * V_186 , int V_187 )
{
struct V_72 * V_49 = V_5 -> V_49 -> V_72 ;
int V_68 , V_3 ;
for ( V_3 = 0 ; V_3 < V_187 ; V_3 ++ ) {
const struct V_261 * V_269 = & V_186 [ V_3 ] ;
V_68 = F_149 ( V_49 , F_147 ( V_269 , V_5 ,
V_269 -> V_51 ,
V_5 -> V_179 ) ) ;
if ( V_68 < 0 ) {
F_50 ( V_5 -> V_28 , L_87 ,
V_5 -> V_51 , V_269 -> V_51 , V_68 ) ;
return V_68 ;
}
}
return 0 ;
}
int F_150 ( struct V_260 * V_265 ,
struct V_270 * V_271 )
{
struct V_272 * V_273 = (struct V_272 * ) V_265 -> V_274 ;
V_271 -> type = V_275 ;
V_271 -> V_18 = V_273 -> V_276 == V_273 -> V_277 ? 1 : 2 ;
V_271 -> V_45 . V_278 . V_279 = V_273 -> F_53 ;
if ( V_271 -> V_45 . V_278 . V_280 > V_273 -> F_53 - 1 )
V_271 -> V_45 . V_278 . V_280 = V_273 -> F_53 - 1 ;
strcpy ( V_271 -> V_45 . V_278 . V_51 ,
V_273 -> V_281 [ V_271 -> V_45 . V_278 . V_280 ] ) ;
return 0 ;
}
int F_151 ( struct V_260 * V_265 ,
struct V_282 * V_283 )
{
struct V_4 * V_5 = F_152 ( V_265 ) ;
struct V_272 * V_273 = (struct V_272 * ) V_265 -> V_274 ;
unsigned int V_1 , V_284 ;
for ( V_284 = 1 ; V_284 < V_273 -> F_53 ; V_284 <<= 1 )
;
V_1 = F_4 ( V_5 , V_273 -> V_6 ) ;
V_283 -> V_45 . V_278 . V_280 [ 0 ]
= ( V_1 >> V_273 -> V_276 ) & ( V_284 - 1 ) ;
if ( V_273 -> V_276 != V_273 -> V_277 )
V_283 -> V_45 . V_278 . V_280 [ 1 ] =
( V_1 >> V_273 -> V_277 ) & ( V_284 - 1 ) ;
return 0 ;
}
int F_153 ( struct V_260 * V_265 ,
struct V_282 * V_283 )
{
struct V_4 * V_5 = F_152 ( V_265 ) ;
struct V_272 * V_273 = (struct V_272 * ) V_265 -> V_274 ;
unsigned int V_1 ;
unsigned int V_248 , V_284 ;
for ( V_284 = 1 ; V_284 < V_273 -> F_53 ; V_284 <<= 1 )
;
if ( V_283 -> V_45 . V_278 . V_280 [ 0 ] > V_273 -> F_53 - 1 )
return - V_17 ;
V_1 = V_283 -> V_45 . V_278 . V_280 [ 0 ] << V_273 -> V_276 ;
V_248 = ( V_284 - 1 ) << V_273 -> V_276 ;
if ( V_273 -> V_276 != V_273 -> V_277 ) {
if ( V_283 -> V_45 . V_278 . V_280 [ 1 ] > V_273 -> F_53 - 1 )
return - V_17 ;
V_1 |= V_283 -> V_45 . V_278 . V_280 [ 1 ] << V_273 -> V_277 ;
V_248 |= ( V_284 - 1 ) << V_273 -> V_277 ;
}
return F_144 ( V_5 , V_273 -> V_6 , V_248 , V_1 ) ;
}
int F_154 ( struct V_260 * V_265 ,
struct V_282 * V_283 )
{
struct V_4 * V_5 = F_152 ( V_265 ) ;
struct V_272 * V_273 = (struct V_272 * ) V_265 -> V_274 ;
unsigned int V_285 , V_1 , V_286 ;
V_285 = F_4 ( V_5 , V_273 -> V_6 ) ;
V_1 = ( V_285 >> V_273 -> V_276 ) & V_273 -> V_248 ;
for ( V_286 = 0 ; V_286 < V_273 -> F_53 ; V_286 ++ ) {
if ( V_1 == V_273 -> V_287 [ V_286 ] )
break;
}
V_283 -> V_45 . V_278 . V_280 [ 0 ] = V_286 ;
if ( V_273 -> V_276 != V_273 -> V_277 ) {
V_1 = ( V_285 >> V_273 -> V_277 ) & V_273 -> V_248 ;
for ( V_286 = 0 ; V_286 < V_273 -> F_53 ; V_286 ++ ) {
if ( V_1 == V_273 -> V_287 [ V_286 ] )
break;
}
V_283 -> V_45 . V_278 . V_280 [ 1 ] = V_286 ;
}
return 0 ;
}
int F_155 ( struct V_260 * V_265 ,
struct V_282 * V_283 )
{
struct V_4 * V_5 = F_152 ( V_265 ) ;
struct V_272 * V_273 = (struct V_272 * ) V_265 -> V_274 ;
unsigned int V_1 ;
unsigned int V_248 ;
if ( V_283 -> V_45 . V_278 . V_280 [ 0 ] > V_273 -> F_53 - 1 )
return - V_17 ;
V_1 = V_273 -> V_287 [ V_283 -> V_45 . V_278 . V_280 [ 0 ] ] << V_273 -> V_276 ;
V_248 = V_273 -> V_248 << V_273 -> V_276 ;
if ( V_273 -> V_276 != V_273 -> V_277 ) {
if ( V_283 -> V_45 . V_278 . V_280 [ 1 ] > V_273 -> F_53 - 1 )
return - V_17 ;
V_1 |= V_273 -> V_287 [ V_283 -> V_45 . V_278 . V_280 [ 1 ] ] << V_273 -> V_277 ;
V_248 |= V_273 -> V_248 << V_273 -> V_277 ;
}
return F_144 ( V_5 , V_273 -> V_6 , V_248 , V_1 ) ;
}
int F_156 ( struct V_260 * V_265 ,
struct V_270 * V_271 )
{
struct V_272 * V_273 = (struct V_272 * ) V_265 -> V_274 ;
V_271 -> type = V_275 ;
V_271 -> V_18 = 1 ;
V_271 -> V_45 . V_278 . V_279 = V_273 -> F_53 ;
if ( V_271 -> V_45 . V_278 . V_280 > V_273 -> F_53 - 1 )
V_271 -> V_45 . V_278 . V_280 = V_273 -> F_53 - 1 ;
strcpy ( V_271 -> V_45 . V_278 . V_51 ,
V_273 -> V_281 [ V_271 -> V_45 . V_278 . V_280 ] ) ;
return 0 ;
}
int F_157 ( struct V_260 * V_265 ,
struct V_270 * V_271 )
{
int F_53 = V_265 -> V_274 ;
if ( F_53 == 1 && ! strstr ( V_265 -> V_288 . V_51 , L_88 ) )
V_271 -> type = V_289 ;
else
V_271 -> type = V_290 ;
V_271 -> V_18 = 1 ;
V_271 -> V_45 . integer . F_6 = 0 ;
V_271 -> V_45 . integer . F_53 = F_53 ;
return 0 ;
}
int F_158 ( struct V_260 * V_265 ,
struct V_270 * V_271 )
{
struct V_291 * V_292 =
(struct V_291 * ) V_265 -> V_274 ;
int V_293 ;
unsigned int V_294 = V_292 -> V_294 ;
unsigned int V_295 = V_292 -> V_295 ;
if ( ! V_292 -> V_293 )
V_292 -> V_293 = V_292 -> F_53 ;
V_293 = V_292 -> V_293 ;
if ( V_293 == 1 && ! strstr ( V_265 -> V_288 . V_51 , L_88 ) )
V_271 -> type = V_289 ;
else
V_271 -> type = V_290 ;
V_271 -> V_18 = V_294 == V_295 ? 1 : 2 ;
V_271 -> V_45 . integer . F_6 = 0 ;
V_271 -> V_45 . integer . F_53 = V_293 ;
return 0 ;
}
int F_159 ( struct V_260 * V_265 ,
struct V_282 * V_283 )
{
struct V_291 * V_292 =
(struct V_291 * ) V_265 -> V_274 ;
struct V_4 * V_5 = F_152 ( V_265 ) ;
unsigned int V_6 = V_292 -> V_6 ;
unsigned int V_294 = V_292 -> V_294 ;
unsigned int V_295 = V_292 -> V_295 ;
int F_53 = V_292 -> F_53 ;
unsigned int V_248 = ( 1 << F_160 ( F_53 ) ) - 1 ;
unsigned int V_296 = V_292 -> V_296 ;
V_283 -> V_45 . integer . V_45 [ 0 ] =
( F_4 ( V_5 , V_6 ) >> V_294 ) & V_248 ;
if ( V_294 != V_295 )
V_283 -> V_45 . integer . V_45 [ 1 ] =
( F_4 ( V_5 , V_6 ) >> V_295 ) & V_248 ;
if ( V_296 ) {
V_283 -> V_45 . integer . V_45 [ 0 ] =
F_53 - V_283 -> V_45 . integer . V_45 [ 0 ] ;
if ( V_294 != V_295 )
V_283 -> V_45 . integer . V_45 [ 1 ] =
F_53 - V_283 -> V_45 . integer . V_45 [ 1 ] ;
}
return 0 ;
}
int F_161 ( struct V_260 * V_265 ,
struct V_282 * V_283 )
{
struct V_291 * V_292 =
(struct V_291 * ) V_265 -> V_274 ;
struct V_4 * V_5 = F_152 ( V_265 ) ;
unsigned int V_6 = V_292 -> V_6 ;
unsigned int V_294 = V_292 -> V_294 ;
unsigned int V_295 = V_292 -> V_295 ;
int F_53 = V_292 -> F_53 ;
unsigned int V_248 = ( 1 << F_160 ( F_53 ) ) - 1 ;
unsigned int V_296 = V_292 -> V_296 ;
unsigned int V_1 , V_297 , V_298 ;
V_1 = ( V_283 -> V_45 . integer . V_45 [ 0 ] & V_248 ) ;
if ( V_296 )
V_1 = F_53 - V_1 ;
V_298 = V_248 << V_294 ;
V_1 = V_1 << V_294 ;
if ( V_294 != V_295 ) {
V_297 = ( V_283 -> V_45 . integer . V_45 [ 1 ] & V_248 ) ;
if ( V_296 )
V_297 = F_53 - V_297 ;
V_298 |= V_248 << V_295 ;
V_1 |= V_297 << V_295 ;
}
return F_144 ( V_5 , V_6 , V_298 , V_1 ) ;
}
int F_162 ( struct V_260 * V_265 ,
struct V_270 * V_271 )
{
struct V_291 * V_292 =
(struct V_291 * ) V_265 -> V_274 ;
int V_293 ;
if ( ! V_292 -> V_293 )
V_292 -> V_293 = V_292 -> F_53 ;
V_293 = V_292 -> V_293 ;
if ( V_293 == 1 && ! strstr ( V_265 -> V_288 . V_51 , L_88 ) )
V_271 -> type = V_289 ;
else
V_271 -> type = V_290 ;
V_271 -> V_18 = 2 ;
V_271 -> V_45 . integer . F_6 = 0 ;
V_271 -> V_45 . integer . F_53 = V_293 ;
return 0 ;
}
int F_163 ( struct V_260 * V_265 ,
struct V_282 * V_283 )
{
struct V_291 * V_292 =
(struct V_291 * ) V_265 -> V_274 ;
struct V_4 * V_5 = F_152 ( V_265 ) ;
unsigned int V_6 = V_292 -> V_6 ;
unsigned int V_299 = V_292 -> V_300 ;
unsigned int V_294 = V_292 -> V_294 ;
int F_53 = V_292 -> F_53 ;
unsigned int V_248 = ( 1 << F_160 ( F_53 ) ) - 1 ;
unsigned int V_296 = V_292 -> V_296 ;
V_283 -> V_45 . integer . V_45 [ 0 ] =
( F_4 ( V_5 , V_6 ) >> V_294 ) & V_248 ;
V_283 -> V_45 . integer . V_45 [ 1 ] =
( F_4 ( V_5 , V_299 ) >> V_294 ) & V_248 ;
if ( V_296 ) {
V_283 -> V_45 . integer . V_45 [ 0 ] =
F_53 - V_283 -> V_45 . integer . V_45 [ 0 ] ;
V_283 -> V_45 . integer . V_45 [ 1 ] =
F_53 - V_283 -> V_45 . integer . V_45 [ 1 ] ;
}
return 0 ;
}
int F_164 ( struct V_260 * V_265 ,
struct V_282 * V_283 )
{
struct V_291 * V_292 =
(struct V_291 * ) V_265 -> V_274 ;
struct V_4 * V_5 = F_152 ( V_265 ) ;
unsigned int V_6 = V_292 -> V_6 ;
unsigned int V_299 = V_292 -> V_300 ;
unsigned int V_294 = V_292 -> V_294 ;
int F_53 = V_292 -> F_53 ;
unsigned int V_248 = ( 1 << F_160 ( F_53 ) ) - 1 ;
unsigned int V_296 = V_292 -> V_296 ;
int V_68 ;
unsigned int V_1 , V_297 , V_298 ;
V_298 = V_248 << V_294 ;
V_1 = ( V_283 -> V_45 . integer . V_45 [ 0 ] & V_248 ) ;
V_297 = ( V_283 -> V_45 . integer . V_45 [ 1 ] & V_248 ) ;
if ( V_296 ) {
V_1 = F_53 - V_1 ;
V_297 = F_53 - V_297 ;
}
V_1 = V_1 << V_294 ;
V_297 = V_297 << V_294 ;
V_68 = F_144 ( V_5 , V_6 , V_298 , V_1 ) ;
if ( V_68 < 0 )
return V_68 ;
V_68 = F_144 ( V_5 , V_299 , V_298 , V_297 ) ;
return V_68 ;
}
int F_165 ( struct V_260 * V_265 ,
struct V_270 * V_271 )
{
struct V_291 * V_292 =
(struct V_291 * ) V_265 -> V_274 ;
int V_293 ;
int F_6 = V_292 -> F_6 ;
if ( ! V_292 -> V_293 )
V_292 -> V_293 = V_292 -> F_53 ;
V_293 = V_292 -> V_293 ;
V_271 -> type = V_290 ;
V_271 -> V_18 = 2 ;
V_271 -> V_45 . integer . F_6 = 0 ;
V_271 -> V_45 . integer . F_53 = V_293 - F_6 ;
return 0 ;
}
int F_166 ( struct V_260 * V_265 ,
struct V_282 * V_283 )
{
struct V_291 * V_292 =
(struct V_291 * ) V_265 -> V_274 ;
struct V_4 * V_5 = F_152 ( V_265 ) ;
unsigned int V_6 = V_292 -> V_6 ;
int F_6 = V_292 -> F_6 ;
int V_1 = F_4 ( V_5 , V_6 ) ;
V_283 -> V_45 . integer . V_45 [ 0 ] =
( ( signed char ) ( V_1 & 0xff ) ) - F_6 ;
V_283 -> V_45 . integer . V_45 [ 1 ] =
( ( signed char ) ( ( V_1 >> 8 ) & 0xff ) ) - F_6 ;
return 0 ;
}
int F_167 ( struct V_260 * V_265 ,
struct V_282 * V_283 )
{
struct V_291 * V_292 =
(struct V_291 * ) V_265 -> V_274 ;
struct V_4 * V_5 = F_152 ( V_265 ) ;
unsigned int V_6 = V_292 -> V_6 ;
int F_6 = V_292 -> F_6 ;
unsigned int V_1 ;
V_1 = ( V_283 -> V_45 . integer . V_45 [ 0 ] + F_6 ) & 0xff ;
V_1 |= ( ( V_283 -> V_45 . integer . V_45 [ 1 ] + F_6 ) & 0xff ) << 8 ;
return F_144 ( V_5 , V_6 , 0xffff , V_1 ) ;
}
int F_168 ( struct V_4 * V_5 ,
const char * V_51 , int F_53 )
{
struct V_72 * V_49 = V_5 -> V_49 -> V_72 ;
struct V_260 * V_301 ;
struct V_291 * V_292 ;
int V_205 = 0 ;
int V_14 = - V_17 ;
if ( F_169 ( ! V_51 || F_53 <= 0 ) )
return - V_17 ;
F_32 (kctl, &card->controls, list) {
if ( ! strncmp ( V_301 -> V_288 . V_51 , V_51 , sizeof( V_301 -> V_288 . V_51 ) ) ) {
V_205 = 1 ;
break;
}
}
if ( V_205 ) {
V_292 = (struct V_291 * ) V_301 -> V_274 ;
if ( F_53 <= V_292 -> F_53 ) {
V_292 -> V_293 = F_53 ;
V_14 = 0 ;
}
}
return V_14 ;
}
int F_170 ( struct V_260 * V_265 ,
struct V_270 * V_271 )
{
struct V_291 * V_292 =
(struct V_291 * ) V_265 -> V_274 ;
int F_53 = V_292 -> F_53 ;
int F_6 = V_292 -> F_6 ;
V_271 -> type = V_290 ;
V_271 -> V_18 = 2 ;
V_271 -> V_45 . integer . F_6 = 0 ;
V_271 -> V_45 . integer . F_53 = F_53 - F_6 ;
return 0 ;
}
int F_171 ( struct V_260 * V_265 ,
struct V_282 * V_283 )
{
struct V_291 * V_292 =
(struct V_291 * ) V_265 -> V_274 ;
struct V_4 * V_5 = F_152 ( V_265 ) ;
unsigned int V_248 = ( 1 << V_292 -> V_294 ) - 1 ;
int F_6 = V_292 -> F_6 ;
int V_1 = F_4 ( V_5 , V_292 -> V_6 ) & V_248 ;
int V_302 = F_4 ( V_5 , V_292 -> V_300 ) & V_248 ;
V_283 -> V_45 . integer . V_45 [ 0 ] = ( ( V_1 & 0xff ) - F_6 ) & V_248 ;
V_283 -> V_45 . integer . V_45 [ 1 ] = ( ( V_302 & 0xff ) - F_6 ) & V_248 ;
return 0 ;
}
int F_172 ( struct V_260 * V_265 ,
struct V_282 * V_283 )
{
struct V_291 * V_292 =
(struct V_291 * ) V_265 -> V_274 ;
struct V_4 * V_5 = F_152 ( V_265 ) ;
unsigned int V_248 = ( 1 << V_292 -> V_294 ) - 1 ;
int F_6 = V_292 -> F_6 ;
int V_14 ;
unsigned int V_1 , V_302 , V_303 , V_304 ;
V_1 = ( ( V_283 -> V_45 . integer . V_45 [ 0 ] + F_6 ) & 0xff ) ;
V_1 &= V_248 ;
V_302 = ( ( V_283 -> V_45 . integer . V_45 [ 1 ] + F_6 ) & 0xff ) ;
V_302 &= V_248 ;
V_303 = F_4 ( V_5 , V_292 -> V_6 ) & V_248 ;
V_304 = F_4 ( V_5 , V_292 -> V_300 ) & V_248 ;
V_14 = 0 ;
if ( V_303 != V_1 ) {
V_14 = F_22 ( V_5 , V_292 -> V_6 , V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( V_304 != V_302 ) {
V_14 = F_22 ( V_5 , V_292 -> V_300 , V_302 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
int F_173 ( struct V_58 * V_59 , int V_305 ,
unsigned int V_306 , int V_307 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_89 -> V_308 )
return V_59 -> V_10 -> V_89 -> V_308 ( V_59 , V_305 , V_306 , V_307 ) ;
else if ( V_59 -> V_5 && V_59 -> V_5 -> V_10 -> V_308 )
return V_59 -> V_5 -> V_10 -> V_308 ( V_59 -> V_5 , V_305 ,
V_306 , V_307 ) ;
else
return - V_17 ;
}
int F_174 ( struct V_4 * V_5 , int V_305 ,
unsigned int V_306 , int V_307 )
{
if ( V_5 -> V_10 -> V_308 )
return V_5 -> V_10 -> V_308 ( V_5 , V_305 , V_306 , V_307 ) ;
else
return - V_17 ;
}
int F_175 ( struct V_58 * V_59 ,
int V_309 , int div )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_89 -> V_310 )
return V_59 -> V_10 -> V_89 -> V_310 ( V_59 , V_309 , div ) ;
else
return - V_17 ;
}
int F_176 ( struct V_58 * V_59 , int V_311 , int V_312 ,
unsigned int V_313 , unsigned int V_314 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_89 -> V_315 )
return V_59 -> V_10 -> V_89 -> V_315 ( V_59 , V_311 , V_312 ,
V_313 , V_314 ) ;
else if ( V_59 -> V_5 && V_59 -> V_5 -> V_10 -> V_315 )
return V_59 -> V_5 -> V_10 -> V_315 ( V_59 -> V_5 , V_311 , V_312 ,
V_313 , V_314 ) ;
else
return - V_17 ;
}
int F_177 ( struct V_4 * V_5 , int V_311 , int V_312 ,
unsigned int V_313 , unsigned int V_314 )
{
if ( V_5 -> V_10 -> V_315 )
return V_5 -> V_10 -> V_315 ( V_5 , V_311 , V_312 ,
V_313 , V_314 ) ;
else
return - V_17 ;
}
int F_178 ( struct V_58 * V_59 , unsigned int V_316 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_89 -> V_317 )
return V_59 -> V_10 -> V_89 -> V_317 ( V_59 , V_316 ) ;
else
return - V_17 ;
}
int F_179 ( struct V_58 * V_59 ,
unsigned int V_318 , unsigned int V_319 , int V_320 , int V_321 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_89 -> V_322 )
return V_59 -> V_10 -> V_89 -> V_322 ( V_59 , V_318 , V_319 ,
V_320 , V_321 ) ;
else
return - V_17 ;
}
int F_180 ( struct V_58 * V_59 ,
unsigned int V_323 , unsigned int * V_324 ,
unsigned int V_325 , unsigned int * V_326 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_89 -> V_327 )
return V_59 -> V_10 -> V_89 -> V_327 ( V_59 , V_323 , V_324 ,
V_325 , V_326 ) ;
else
return - V_17 ;
}
int F_181 ( struct V_58 * V_59 , int V_328 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_89 -> V_329 )
return V_59 -> V_10 -> V_89 -> V_329 ( V_59 , V_328 ) ;
else
return - V_17 ;
}
int F_60 ( struct V_58 * V_59 , int V_330 )
{
if ( V_59 -> V_10 && V_59 -> V_10 -> V_89 -> V_140 )
return V_59 -> V_10 -> V_89 -> V_140 ( V_59 , V_330 ) ;
else
return - V_17 ;
}
int F_126 ( struct V_62 * V_49 )
{
int V_3 ;
if ( ! V_49 -> V_51 || ! V_49 -> V_28 )
return - V_17 ;
F_182 ( V_49 -> V_28 , V_49 ) ;
F_183 ( V_49 ) ;
F_36 ( V_49 ) ;
V_49 -> V_32 = F_138 ( sizeof( struct V_31 ) *
( V_49 -> V_211 + V_49 -> V_216 ) ,
V_40 ) ;
if ( V_49 -> V_32 == NULL )
return - V_41 ;
V_49 -> V_196 = & V_49 -> V_32 [ V_49 -> V_211 ] ;
for ( V_3 = 0 ; V_3 < V_49 -> V_211 ; V_3 ++ )
V_49 -> V_32 [ V_3 ] . V_80 = & V_49 -> V_80 [ V_3 ] ;
F_184 ( & V_49 -> V_190 ) ;
V_49 -> V_210 = 0 ;
F_185 ( & V_49 -> V_209 ) ;
F_52 ( & V_331 ) ;
F_96 ( & V_49 -> V_190 , & V_169 ) ;
F_123 () ;
F_56 ( & V_331 ) ;
F_48 ( V_49 -> V_28 , L_89 , V_49 -> V_51 ) ;
return 0 ;
}
int F_129 ( struct V_62 * V_49 )
{
if ( V_49 -> V_210 )
F_127 ( V_49 ) ;
F_52 ( & V_331 ) ;
F_85 ( & V_49 -> V_190 ) ;
F_56 ( & V_331 ) ;
F_48 ( V_49 -> V_28 , L_90 , V_49 -> V_51 ) ;
return 0 ;
}
static char * F_186 ( struct V_27 * V_28 , int * V_288 )
{
char * V_205 , V_51 [ V_332 ] ;
int V_333 , V_334 ;
if ( V_178 ( V_28 ) == NULL )
return NULL ;
F_119 ( V_51 , V_178 ( V_28 ) , V_332 ) ;
V_205 = strstr ( V_51 , V_28 -> V_10 -> V_51 ) ;
if ( V_205 ) {
if ( sscanf ( & V_205 [ strlen ( V_28 -> V_10 -> V_51 ) ] , L_91 , V_288 ) == 1 ) {
if ( * V_288 == - 1 )
V_205 [ strlen ( V_28 -> V_10 -> V_51 ) ] = '\0' ;
}
} else {
if ( sscanf ( V_51 , L_92 , & V_333 , & V_334 ) == 2 ) {
char V_335 [ V_332 ] ;
* V_288 = ( ( V_333 & 0xffff ) << 16 ) + V_334 ;
snprintf ( V_335 , V_332 , L_93 , V_28 -> V_10 -> V_51 , V_51 ) ;
F_119 ( V_51 , V_335 , V_332 ) ;
} else
* V_288 = 0 ;
}
return F_187 ( V_51 , V_40 ) ;
}
static inline char * F_188 ( struct V_27 * V_28 ,
struct V_85 * V_336 )
{
if ( V_336 -> V_51 == NULL ) {
F_25 ( V_74 L_94 ,
V_178 ( V_28 ) ) ;
return NULL ;
}
return F_187 ( V_336 -> V_51 , V_40 ) ;
}
int F_189 ( struct V_27 * V_28 ,
struct V_85 * V_336 )
{
struct V_58 * V_59 ;
F_48 ( V_28 , L_95 , V_178 ( V_28 ) ) ;
V_59 = F_138 ( sizeof( struct V_58 ) , V_40 ) ;
if ( V_59 == NULL )
return - V_41 ;
V_59 -> V_51 = F_186 ( V_28 , & V_59 -> V_288 ) ;
if ( V_59 -> V_51 == NULL ) {
F_16 ( V_59 ) ;
return - V_41 ;
}
V_59 -> V_28 = V_28 ;
V_59 -> V_10 = V_336 ;
if ( ! V_59 -> V_10 -> V_89 )
V_59 -> V_10 -> V_89 = & V_337 ;
F_52 ( & V_331 ) ;
F_96 ( & V_59 -> V_190 , & V_338 ) ;
F_123 () ;
F_56 ( & V_331 ) ;
F_55 ( L_96 , V_59 -> V_51 ) ;
return 0 ;
}
void F_190 ( struct V_27 * V_28 )
{
struct V_58 * V_59 ;
F_32 (dai, &dai_list, list) {
if ( V_28 == V_59 -> V_28 )
goto V_205;
}
return;
V_205:
F_52 ( & V_331 ) ;
F_85 ( & V_59 -> V_190 ) ;
F_56 ( & V_331 ) ;
F_55 ( L_97 , V_59 -> V_51 ) ;
F_16 ( V_59 -> V_51 ) ;
F_16 ( V_59 ) ;
}
int F_191 ( struct V_27 * V_28 ,
struct V_85 * V_336 , T_1 V_18 )
{
struct V_58 * V_59 ;
int V_3 , V_14 = 0 ;
F_48 ( V_28 , L_98 , V_178 ( V_28 ) , V_18 ) ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ ) {
V_59 = F_138 ( sizeof( struct V_58 ) , V_40 ) ;
if ( V_59 == NULL ) {
V_14 = - V_41 ;
goto V_68;
}
V_59 -> V_51 = F_188 ( V_28 , & V_336 [ V_3 ] ) ;
if ( V_59 -> V_51 == NULL ) {
F_16 ( V_59 ) ;
V_14 = - V_17 ;
goto V_68;
}
V_59 -> V_28 = V_28 ;
V_59 -> V_10 = & V_336 [ V_3 ] ;
if ( V_59 -> V_10 -> V_288 )
V_59 -> V_288 = V_59 -> V_10 -> V_288 ;
else
V_59 -> V_288 = V_3 ;
if ( ! V_59 -> V_10 -> V_89 )
V_59 -> V_10 -> V_89 = & V_337 ;
F_52 ( & V_331 ) ;
F_96 ( & V_59 -> V_190 , & V_338 ) ;
F_56 ( & V_331 ) ;
F_55 ( L_96 , V_59 -> V_51 ) ;
}
F_52 ( & V_331 ) ;
F_123 () ;
F_56 ( & V_331 ) ;
return 0 ;
V_68:
for ( V_3 -- ; V_3 >= 0 ; V_3 -- )
F_190 ( V_28 ) ;
return V_14 ;
}
void F_192 ( struct V_27 * V_28 , T_1 V_18 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ )
F_190 ( V_28 ) ;
}
int F_193 ( struct V_27 * V_28 ,
struct V_339 * V_340 )
{
struct V_60 * V_61 ;
F_48 ( V_28 , L_99 , V_178 ( V_28 ) ) ;
V_61 = F_138 ( sizeof( struct V_60 ) , V_40 ) ;
if ( V_61 == NULL )
return - V_41 ;
V_61 -> V_51 = F_186 ( V_28 , & V_61 -> V_288 ) ;
if ( V_61 -> V_51 == NULL ) {
F_16 ( V_61 ) ;
return - V_41 ;
}
V_61 -> V_28 = V_28 ;
V_61 -> V_10 = V_340 ;
F_52 ( & V_331 ) ;
F_96 ( & V_61 -> V_190 , & V_341 ) ;
F_123 () ;
F_56 ( & V_331 ) ;
F_55 ( L_100 , V_61 -> V_51 ) ;
return 0 ;
}
void F_194 ( struct V_27 * V_28 )
{
struct V_60 * V_61 ;
F_32 (platform, &platform_list, list) {
if ( V_28 == V_61 -> V_28 )
goto V_205;
}
return;
V_205:
F_52 ( & V_331 ) ;
F_85 ( & V_61 -> V_190 ) ;
F_56 ( & V_331 ) ;
F_55 ( L_101 , V_61 -> V_51 ) ;
F_16 ( V_61 -> V_51 ) ;
F_16 ( V_61 ) ;
}
static void F_195 ( struct V_342 * V_96 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_196 ( V_343 ) ; V_3 ++ )
if ( V_96 -> V_104 & V_343 [ V_3 ] )
V_96 -> V_104 |= V_343 [ V_3 ] ;
}
int F_197 ( struct V_27 * V_28 ,
const struct V_180 * V_344 ,
struct V_85 * V_336 ,
int V_345 )
{
T_1 V_346 ;
struct V_4 * V_5 ;
int V_14 , V_3 ;
F_48 ( V_28 , L_102 , V_178 ( V_28 ) ) ;
V_5 = F_138 ( sizeof( struct V_4 ) , V_40 ) ;
if ( V_5 == NULL )
return - V_41 ;
V_5 -> V_51 = F_186 ( V_28 , & V_5 -> V_288 ) ;
if ( V_5 -> V_51 == NULL ) {
F_16 ( V_5 ) ;
return - V_41 ;
}
if ( V_344 -> V_207 )
V_5 -> V_207 = V_344 -> V_207 ;
else
V_5 -> V_207 = V_347 ;
V_5 -> V_245 = V_344 -> V_245 ;
V_5 -> V_244 = V_344 -> V_244 ;
V_5 -> V_239 = V_344 -> V_239 ;
V_5 -> V_24 = V_344 -> V_24 ;
V_5 -> V_240 = V_344 -> V_240 ;
V_5 -> V_57 . V_147 = V_150 ;
V_5 -> V_57 . V_28 = V_28 ;
V_5 -> V_57 . V_5 = V_5 ;
V_5 -> V_57 . V_348 = V_344 -> V_348 ;
V_5 -> V_28 = V_28 ;
V_5 -> V_10 = V_344 ;
V_5 -> V_345 = V_345 ;
F_185 ( & V_5 -> V_209 ) ;
if ( V_344 -> V_11 && V_344 -> V_13 ) {
V_346 = V_344 -> V_11 * V_344 -> V_13 ;
V_5 -> V_346 = V_346 ;
if ( V_344 -> V_349 ) {
V_5 -> V_350 = F_198 ( V_344 -> V_349 ,
V_346 , V_40 ) ;
if ( ! V_5 -> V_350 ) {
V_14 = - V_41 ;
goto V_351;
}
}
}
if ( V_344 -> V_352 && V_344 -> V_353 ) {
if ( ! V_5 -> V_239 )
V_5 -> V_239 = V_354 ;
if ( ! V_5 -> V_24 )
V_5 -> V_24 = V_355 ;
if ( ! V_5 -> V_240 )
V_5 -> V_240 = V_356 ;
}
for ( V_3 = 0 ; V_3 < V_345 ; V_3 ++ ) {
F_195 ( & V_336 [ V_3 ] . V_100 ) ;
F_195 ( & V_336 [ V_3 ] . V_108 ) ;
}
if ( V_345 ) {
V_14 = F_191 ( V_28 , V_336 , V_345 ) ;
if ( V_14 < 0 )
goto V_351;
}
F_52 ( & V_331 ) ;
F_96 ( & V_5 -> V_190 , & V_357 ) ;
F_123 () ;
F_56 ( & V_331 ) ;
F_55 ( L_103 , V_5 -> V_51 ) ;
return 0 ;
V_351:
F_16 ( V_5 -> V_350 ) ;
V_5 -> V_350 = NULL ;
F_16 ( V_5 -> V_51 ) ;
F_16 ( V_5 ) ;
return V_14 ;
}
void F_199 ( struct V_27 * V_28 )
{
struct V_4 * V_5 ;
int V_3 ;
F_32 (codec, &codec_list, list) {
if ( V_28 == V_5 -> V_28 )
goto V_205;
}
return;
V_205:
if ( V_5 -> V_345 )
for ( V_3 = 0 ; V_3 < V_5 -> V_345 ; V_3 ++ )
F_190 ( V_28 ) ;
F_52 ( & V_331 ) ;
F_85 ( & V_5 -> V_190 ) ;
F_56 ( & V_331 ) ;
F_55 ( L_104 , V_5 -> V_51 ) ;
F_200 ( V_5 ) ;
F_16 ( V_5 -> V_350 ) ;
F_16 ( V_5 -> V_51 ) ;
F_16 ( V_5 ) ;
}
static int T_7 F_201 ( void )
{
#ifdef F_114
V_63 = F_24 ( L_105 , NULL ) ;
if ( F_202 ( V_63 ) || ! V_63 ) {
F_25 ( V_52
L_106 ) ;
V_63 = NULL ;
}
if ( ! F_27 ( L_107 , 0444 , V_63 , NULL ,
& V_358 ) )
F_203 ( L_108 ) ;
if ( ! F_27 ( L_109 , 0444 , V_63 , NULL ,
& V_359 ) )
F_203 ( L_110 ) ;
if ( ! F_27 ( L_111 , 0444 , V_63 , NULL ,
& V_360 ) )
F_203 ( L_112 ) ;
#endif
F_204 () ;
return F_205 ( & V_361 ) ;
}
static void T_8 F_206 ( void )
{
F_207 () ;
#ifdef F_114
F_30 ( V_63 ) ;
#endif
F_208 ( & V_361 ) ;
}
