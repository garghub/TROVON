static struct V_1 * F_1 ( const void * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 = F_2 ( sizeof( * V_6 ) , V_7 ) ;
if ( V_6 == NULL )
return NULL ;
V_6 -> V_6 = F_3 ( V_3 ) ;
if ( ! V_6 -> V_6 ) {
F_4 ( V_6 ) ;
return NULL ;
}
memcpy ( V_6 -> V_6 , V_2 , V_3 ) ;
if ( V_5 )
F_5 ( & V_6 -> V_5 , V_5 ) ;
return V_6 ;
}
static void F_6 ( struct V_4 * V_5 )
{
while ( ! F_7 ( V_5 ) ) {
struct V_1 * V_6 = F_8 ( V_5 ,
struct V_1 ,
V_5 ) ;
F_9 ( & V_6 -> V_5 ) ;
F_10 ( V_6 -> V_6 ) ;
F_4 ( V_6 ) ;
}
}
static const char * F_11 ( unsigned int type )
{
switch ( type ) {
case V_8 :
return L_1 ;
case V_9 :
return L_2 ;
case V_10 :
return L_3 ;
case V_11 :
return L_4 ;
case V_12 :
return L_5 ;
default:
return NULL ;
}
}
static void F_12 ( struct V_13 * V_14 , const char * V_15 )
{
char * V_16 = F_13 ( V_7 , L_6 , V_15 ) ;
F_4 ( V_14 -> V_17 ) ;
V_14 -> V_17 = V_16 ;
}
static void F_14 ( struct V_13 * V_14 , const char * V_15 )
{
char * V_16 = F_13 ( V_7 , L_6 , V_15 ) ;
F_4 ( V_14 -> V_18 ) ;
V_14 -> V_18 = V_16 ;
}
static void F_15 ( struct V_13 * V_14 )
{
F_4 ( V_14 -> V_17 ) ;
F_4 ( V_14 -> V_18 ) ;
V_14 -> V_17 = NULL ;
V_14 -> V_18 = NULL ;
}
static T_2 F_16 ( struct V_19 * V_19 ,
char T_3 * V_20 ,
T_1 V_21 , T_4 * V_22 )
{
struct V_13 * V_14 = V_19 -> V_23 ;
T_2 V_24 ;
F_17 ( & V_14 -> V_25 ) ;
if ( ! V_14 -> V_17 || ! V_14 -> V_26 )
V_24 = 0 ;
else
V_24 = F_18 ( V_20 , V_21 , V_22 ,
V_14 -> V_17 ,
strlen ( V_14 -> V_17 ) ) ;
F_19 ( & V_14 -> V_25 ) ;
return V_24 ;
}
static T_2 F_20 ( struct V_19 * V_19 ,
char T_3 * V_20 ,
T_1 V_21 , T_4 * V_22 )
{
struct V_13 * V_14 = V_19 -> V_23 ;
T_2 V_24 ;
F_17 ( & V_14 -> V_25 ) ;
if ( ! V_14 -> V_18 || ! V_14 -> V_26 )
V_24 = 0 ;
else
V_24 = F_18 ( V_20 , V_21 , V_22 ,
V_14 -> V_18 ,
strlen ( V_14 -> V_18 ) ) ;
F_19 ( & V_14 -> V_25 ) ;
return V_24 ;
}
static void F_21 ( struct V_13 * V_14 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 = NULL ;
char * V_31 ;
int V_32 ;
if ( ! V_28 -> V_33 . V_34 ) {
F_22 ( V_14 , L_7 ) ;
goto V_35;
}
V_31 = F_23 ( V_36 , V_7 ) ;
if ( ! V_31 )
goto V_35;
snprintf ( V_31 , V_36 , L_8 , V_14 -> V_37 ) ;
V_30 = F_24 ( V_31 , V_28 -> V_33 . V_34 ) ;
F_4 ( V_31 ) ;
if ( ! V_30 )
goto V_35;
if ( ! F_25 ( L_9 , V_38 , V_30 , & V_14 -> V_26 ) )
goto V_35;
if ( ! F_25 ( L_10 , V_38 , V_30 , & V_14 -> V_39 ) )
goto V_35;
if ( ! F_26 ( L_11 , V_38 , V_30 , & V_14 -> V_40 ) )
goto V_35;
if ( ! F_26 ( L_12 , V_38 , V_30 ,
& V_14 -> V_41 ) )
goto V_35;
for ( V_32 = 0 ; V_32 < F_27 ( V_42 ) ; ++ V_32 ) {
if ( ! F_28 ( V_42 [ V_32 ] . V_43 ,
V_38 , V_30 , V_14 ,
& V_42 [ V_32 ] . V_44 ) )
goto V_35;
}
V_14 -> V_34 = V_30 ;
return;
V_35:
F_29 ( V_30 ) ;
F_22 ( V_14 , L_13 ) ;
}
static void F_30 ( struct V_13 * V_14 )
{
F_15 ( V_14 ) ;
F_29 ( V_14 -> V_34 ) ;
}
static inline void F_21 ( struct V_13 * V_14 ,
struct V_27 * V_28 )
{
}
static inline void F_30 ( struct V_13 * V_14 )
{
}
static inline void F_12 ( struct V_13 * V_14 ,
const char * V_15 )
{
}
static inline void F_14 ( struct V_13 * V_14 ,
const char * V_15 )
{
}
static inline void F_15 ( struct V_13 * V_14 )
{
}
static int F_31 ( struct V_45 * V_46 ,
struct V_47 * V_48 )
{
struct V_27 * V_28 = F_32 ( V_46 ) ;
struct V_49 * V_50 = (struct V_49 * ) V_46 -> V_51 ;
struct V_13 * V_14 = F_33 ( V_28 ) ;
V_48 -> V_52 . V_53 . V_54 [ 0 ] = V_14 [ V_50 -> V_55 ] . V_56 ;
return 0 ;
}
static int F_34 ( struct V_45 * V_46 ,
struct V_47 * V_48 )
{
struct V_27 * V_28 = F_32 ( V_46 ) ;
struct V_49 * V_50 = (struct V_49 * ) V_46 -> V_51 ;
struct V_13 * V_14 = F_33 ( V_28 ) ;
int V_24 = 0 ;
if ( V_48 -> V_52 . V_53 . V_54 [ 0 ] == V_14 [ V_50 -> V_55 ] . V_56 )
return 0 ;
if ( V_48 -> V_52 . V_53 . V_54 [ 0 ] >= V_57 )
return - V_58 ;
F_17 ( & V_14 [ V_50 -> V_55 ] . V_25 ) ;
if ( V_14 [ V_50 -> V_55 ] . V_26 || V_14 [ V_50 -> V_55 ] . V_59 )
V_24 = - V_60 ;
else
V_14 [ V_50 -> V_55 ] . V_56 = V_48 -> V_52 . V_53 . V_54 [ 0 ] ;
F_19 ( & V_14 [ V_50 -> V_55 ] . V_25 ) ;
return V_24 ;
}
static struct V_61 const * F_35 ( struct V_13 * V_14 ,
int type )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_14 -> V_62 ; V_32 ++ )
if ( V_14 -> V_63 [ V_32 ] . type == type )
return & V_14 -> V_63 [ V_32 ] ;
return NULL ;
}
static unsigned int F_36 ( struct V_61 const * V_63 ,
unsigned int V_64 )
{
if ( F_37 ( ! V_63 ) )
return V_64 ;
switch ( V_63 -> type ) {
case V_8 :
return V_63 -> V_65 + ( V_64 * 3 ) ;
case V_9 :
return V_63 -> V_65 + ( V_64 * 2 ) ;
case V_10 :
return V_63 -> V_65 + ( V_64 * 2 ) ;
case V_11 :
return V_63 -> V_65 + ( V_64 * 2 ) ;
case V_12 :
return V_63 -> V_65 + ( V_64 * 2 ) ;
default:
F_38 ( 1 , L_14 ) ;
return V_64 ;
}
}
static void F_39 ( struct V_13 * V_14 )
{
T_5 V_66 [ 4 ] ;
int V_24 ;
V_24 = F_40 ( V_14 -> V_67 , V_14 -> V_65 + V_68 ,
V_66 , sizeof( V_66 ) ) ;
if ( V_24 ) {
F_22 ( V_14 , L_15 , V_24 ) ;
return;
}
F_41 ( V_14 , L_16 ,
F_42 ( V_66 [ 0 ] ) ,
F_42 ( V_66 [ 1 ] ) ,
F_42 ( V_66 [ 2 ] ) ,
F_42 ( V_66 [ 3 ] ) ) ;
}
static inline struct V_69 * F_43 ( struct V_70 * V_71 )
{
return F_44 ( V_71 , struct V_69 , V_72 ) ;
}
static int F_45 ( struct V_69 * V_73 , unsigned int * V_74 )
{
const struct V_75 * V_76 = & V_73 -> V_76 ;
struct V_13 * V_14 = V_73 -> V_14 ;
const struct V_61 * V_63 ;
V_63 = F_35 ( V_14 , V_76 -> type ) ;
if ( ! V_63 ) {
F_22 ( V_14 , L_17 ,
V_76 -> type ) ;
return - V_58 ;
}
* V_74 = F_36 ( V_63 , V_73 -> V_76 . V_65 + V_73 -> V_64 ) ;
return 0 ;
}
static int F_46 ( struct V_45 * V_77 ,
struct V_78 * V_79 )
{
struct V_70 * V_72 =
(struct V_70 * ) V_77 -> V_51 ;
struct V_69 * V_73 = F_43 ( V_72 ) ;
switch ( V_73 -> type ) {
case V_80 :
V_79 -> type = V_81 ;
V_79 -> V_52 . integer . V_82 = V_83 ;
V_79 -> V_52 . integer . V_84 = V_85 ;
V_79 -> V_52 . integer . V_86 = 1 ;
V_79 -> V_21 = 1 ;
break;
default:
V_79 -> type = V_87 ;
V_79 -> V_21 = V_73 -> V_3 ;
break;
}
return 0 ;
}
static int F_47 ( struct V_69 * V_73 ,
unsigned int V_88 )
{
struct V_13 * V_14 = V_73 -> V_14 ;
T_6 V_89 = F_48 ( V_88 ) ;
unsigned int V_74 ;
int V_32 , V_24 ;
V_24 = F_45 ( V_73 , & V_74 ) ;
if ( V_24 )
return V_24 ;
F_41 ( V_14 , L_18 ,
V_88 , V_73 -> V_76 . V_90 ,
F_11 ( V_73 -> V_76 . type ) , V_73 -> V_64 ) ;
V_24 = F_49 ( V_14 -> V_67 , V_74 , & V_89 , sizeof( V_89 ) ) ;
if ( V_24 ) {
F_22 ( V_14 , L_19 , V_74 , V_24 ) ;
return V_24 ;
}
for ( V_32 = 0 ; V_32 < V_91 ; ) {
switch ( V_32 ) {
case 0 ... V_92 - 1 :
F_50 ( 1000 , 2000 ) ;
V_32 ++ ;
break;
default:
F_50 ( 10000 , 20000 ) ;
V_32 += 10 ;
break;
}
V_24 = F_40 ( V_14 -> V_67 , V_74 , & V_89 , sizeof( V_89 ) ) ;
if ( V_24 ) {
F_22 ( V_14 , L_20 , V_74 , V_24 ) ;
return V_24 ;
}
if ( V_89 == 0 ) {
F_41 ( V_14 , L_21 , V_32 ) ;
return 0 ;
}
}
F_51 ( V_14 , L_22 ,
V_74 , V_73 -> V_76 . V_90 ,
F_11 ( V_73 -> V_76 . type ) ,
V_73 -> V_64 ) ;
return - V_93 ;
}
static int F_52 ( struct V_69 * V_73 ,
const void * V_6 , T_1 V_3 )
{
struct V_13 * V_14 = V_73 -> V_14 ;
void * V_66 ;
int V_24 ;
unsigned int V_74 ;
V_24 = F_45 ( V_73 , & V_74 ) ;
if ( V_24 )
return V_24 ;
V_66 = F_53 ( V_6 , V_3 , V_7 | V_94 ) ;
if ( ! V_66 )
return - V_95 ;
V_24 = F_49 ( V_14 -> V_67 , V_74 , V_66 ,
V_3 ) ;
if ( V_24 ) {
F_22 ( V_14 , L_23 ,
V_3 , V_74 , V_24 ) ;
F_4 ( V_66 ) ;
return V_24 ;
}
F_41 ( V_14 , L_24 , V_3 , V_74 ) ;
F_4 ( V_66 ) ;
return 0 ;
}
static int F_54 ( struct V_45 * V_77 ,
struct V_47 * V_48 )
{
struct V_70 * V_72 =
(struct V_70 * ) V_77 -> V_51 ;
struct V_69 * V_73 = F_43 ( V_72 ) ;
char * V_96 = V_48 -> V_52 . V_97 . V_98 ;
int V_24 = 0 ;
F_17 ( & V_73 -> V_14 -> V_25 ) ;
memcpy ( V_73 -> V_99 , V_96 , V_73 -> V_3 ) ;
V_73 -> V_100 = 1 ;
if ( V_73 -> V_101 && V_73 -> V_14 -> V_39 )
V_24 = F_52 ( V_73 , V_96 , V_73 -> V_3 ) ;
F_19 ( & V_73 -> V_14 -> V_25 ) ;
return V_24 ;
}
static int F_55 ( struct V_45 * V_77 ,
const unsigned int T_3 * V_97 , unsigned int V_102 )
{
struct V_70 * V_72 =
(struct V_70 * ) V_77 -> V_51 ;
struct V_69 * V_73 = F_43 ( V_72 ) ;
int V_24 = 0 ;
F_17 ( & V_73 -> V_14 -> V_25 ) ;
if ( F_56 ( V_73 -> V_99 , V_97 , V_102 ) ) {
V_24 = - V_103 ;
} else {
V_73 -> V_100 = 1 ;
if ( V_73 -> V_101 && V_73 -> V_14 -> V_39 )
V_24 = F_52 ( V_73 , V_73 -> V_99 , V_102 ) ;
}
F_19 ( & V_73 -> V_14 -> V_25 ) ;
return V_24 ;
}
static int F_57 ( struct V_45 * V_77 ,
struct V_47 * V_48 )
{
struct V_70 * V_72 =
(struct V_70 * ) V_77 -> V_51 ;
struct V_69 * V_73 = F_43 ( V_72 ) ;
unsigned int V_89 = V_48 -> V_52 . integer . V_52 [ 0 ] ;
int V_24 ;
if ( V_89 == 0 )
return 0 ;
F_17 ( & V_73 -> V_14 -> V_25 ) ;
if ( V_73 -> V_101 )
V_24 = F_47 ( V_73 , V_89 ) ;
else
V_24 = - V_104 ;
F_19 ( & V_73 -> V_14 -> V_25 ) ;
return V_24 ;
}
static int F_58 ( struct V_69 * V_73 ,
void * V_6 , T_1 V_3 )
{
struct V_13 * V_14 = V_73 -> V_14 ;
void * V_66 ;
int V_24 ;
unsigned int V_74 ;
V_24 = F_45 ( V_73 , & V_74 ) ;
if ( V_24 )
return V_24 ;
V_66 = F_23 ( V_3 , V_7 | V_94 ) ;
if ( ! V_66 )
return - V_95 ;
V_24 = F_40 ( V_14 -> V_67 , V_74 , V_66 , V_3 ) ;
if ( V_24 ) {
F_22 ( V_14 , L_25 ,
V_3 , V_74 , V_24 ) ;
F_4 ( V_66 ) ;
return V_24 ;
}
F_41 ( V_14 , L_26 , V_3 , V_74 ) ;
memcpy ( V_6 , V_66 , V_3 ) ;
F_4 ( V_66 ) ;
return 0 ;
}
static int F_59 ( struct V_45 * V_77 ,
struct V_47 * V_48 )
{
struct V_70 * V_72 =
(struct V_70 * ) V_77 -> V_51 ;
struct V_69 * V_73 = F_43 ( V_72 ) ;
char * V_96 = V_48 -> V_52 . V_97 . V_98 ;
int V_24 = 0 ;
F_17 ( & V_73 -> V_14 -> V_25 ) ;
if ( V_73 -> V_105 & V_106 ) {
if ( V_73 -> V_101 && V_73 -> V_14 -> V_39 )
V_24 = F_58 ( V_73 , V_96 , V_73 -> V_3 ) ;
else
V_24 = - V_104 ;
} else {
if ( ! V_73 -> V_105 && V_73 -> V_101 && V_73 -> V_14 -> V_39 )
V_24 = F_58 ( V_73 , V_73 -> V_99 , V_73 -> V_3 ) ;
memcpy ( V_96 , V_73 -> V_99 , V_73 -> V_3 ) ;
}
F_19 ( & V_73 -> V_14 -> V_25 ) ;
return V_24 ;
}
static int F_60 ( struct V_45 * V_77 ,
unsigned int T_3 * V_97 , unsigned int V_102 )
{
struct V_70 * V_72 =
(struct V_70 * ) V_77 -> V_51 ;
struct V_69 * V_73 = F_43 ( V_72 ) ;
int V_24 = 0 ;
F_17 ( & V_73 -> V_14 -> V_25 ) ;
if ( V_73 -> V_105 & V_106 ) {
if ( V_73 -> V_101 && V_73 -> V_14 -> V_39 )
V_24 = F_58 ( V_73 , V_73 -> V_99 , V_102 ) ;
else
V_24 = - V_104 ;
} else {
if ( ! V_73 -> V_105 && V_73 -> V_101 && V_73 -> V_14 -> V_39 )
V_24 = F_58 ( V_73 , V_73 -> V_99 , V_102 ) ;
}
if ( ! V_24 && F_61 ( V_97 , V_73 -> V_99 , V_102 ) )
V_24 = - V_103 ;
F_19 ( & V_73 -> V_14 -> V_25 ) ;
return V_24 ;
}
static int F_62 ( struct V_45 * V_46 ,
struct V_47 * V_48 )
{
V_48 -> V_52 . integer . V_52 [ 0 ] = 0 ;
return 0 ;
}
static unsigned int F_63 ( unsigned int V_107 , unsigned int V_3 )
{
unsigned int V_108 , V_109 , V_110 , V_111 ;
if ( V_3 > V_112 ) {
V_109 = V_113 ;
V_110 = V_114 ;
V_111 = V_115 ;
V_108 = V_116 ;
} else {
V_109 = V_117 ;
V_110 = V_118 ;
V_111 = V_115 ;
V_108 = 0 ;
}
if ( V_107 ) {
if ( V_107 & V_119 )
V_108 |= V_109 ;
if ( V_107 & V_120 )
V_108 |= V_110 ;
if ( V_107 & V_106 )
V_108 |= V_111 ;
} else {
V_108 |= V_109 | V_110 | V_111 ;
}
return V_108 ;
}
static int F_64 ( struct V_13 * V_14 , struct V_69 * V_73 )
{
struct V_121 * V_46 ;
int V_24 ;
if ( ! V_73 || ! V_73 -> V_43 )
return - V_58 ;
V_46 = F_2 ( sizeof( * V_46 ) , V_7 ) ;
if ( ! V_46 )
return - V_95 ;
V_46 -> V_43 = V_73 -> V_43 ;
V_46 -> V_122 = F_46 ;
V_46 -> V_123 = V_124 ;
V_46 -> V_125 . V_126 = V_127 ;
V_46 -> V_51 = ( unsigned long ) & V_73 -> V_72 ;
V_46 -> V_128 = F_63 ( V_73 -> V_105 , V_73 -> V_3 ) ;
switch ( V_73 -> type ) {
case V_80 :
V_46 -> V_129 = F_62 ;
V_46 -> V_130 = F_57 ;
break;
default:
V_46 -> V_129 = F_59 ;
V_46 -> V_130 = F_54 ;
V_73 -> V_72 . V_84 = V_73 -> V_3 ;
V_73 -> V_72 . V_129 = F_60 ;
V_73 -> V_72 . V_130 = F_55 ;
break;
}
V_24 = F_65 ( V_14 -> V_28 , V_46 , 1 ) ;
if ( V_24 < 0 )
goto V_131;
F_4 ( V_46 ) ;
return 0 ;
V_131:
F_4 ( V_46 ) ;
return V_24 ;
}
static int F_66 ( struct V_13 * V_14 )
{
struct V_69 * V_73 ;
int V_24 ;
F_67 (ctl, &dsp->ctl_list, list) {
if ( ! V_73 -> V_101 || V_73 -> V_100 )
continue;
if ( V_73 -> V_105 & V_106 )
continue;
V_24 = F_58 ( V_73 , V_73 -> V_99 , V_73 -> V_3 ) ;
if ( V_24 < 0 )
return V_24 ;
}
return 0 ;
}
static int F_68 ( struct V_13 * V_14 )
{
struct V_69 * V_73 ;
int V_24 ;
F_67 (ctl, &dsp->ctl_list, list) {
if ( ! V_73 -> V_101 )
continue;
if ( V_73 -> V_100 && ! ( V_73 -> V_105 & V_106 ) ) {
V_24 = F_52 ( V_73 , V_73 -> V_99 , V_73 -> V_3 ) ;
if ( V_24 < 0 )
return V_24 ;
}
}
return 0 ;
}
static void F_69 ( struct V_13 * V_14 ,
unsigned int V_132 )
{
struct V_69 * V_73 ;
int V_24 ;
F_67 (ctl, &dsp->ctl_list, list) {
if ( V_73 -> type != V_133 )
continue;
if ( ! V_73 -> V_101 )
continue;
V_24 = F_47 ( V_73 , V_132 ) ;
if ( V_24 )
F_51 ( V_14 ,
L_27 ,
V_132 , V_73 -> V_76 . V_90 , V_24 ) ;
}
}
static void F_70 ( struct V_134 * V_135 )
{
struct V_136 * V_137 = F_44 ( V_135 ,
struct V_136 ,
V_135 ) ;
F_64 ( V_137 -> V_14 , V_137 -> V_73 ) ;
F_4 ( V_137 ) ;
}
static void F_71 ( struct V_69 * V_73 )
{
F_4 ( V_73 -> V_99 ) ;
F_4 ( V_73 -> V_43 ) ;
F_4 ( V_73 ) ;
}
static int F_72 ( struct V_13 * V_14 ,
const struct V_75 * V_76 ,
unsigned int V_64 , unsigned int V_3 ,
const char * V_138 , unsigned int V_139 ,
unsigned int V_105 , unsigned int type )
{
struct V_69 * V_73 ;
struct V_136 * V_137 ;
char V_43 [ V_140 ] ;
const char * V_141 ;
int V_24 ;
V_141 = F_11 ( V_76 -> type ) ;
if ( ! V_141 ) {
F_22 ( V_14 , L_28 , V_76 -> type ) ;
return - V_58 ;
}
switch ( V_14 -> V_142 ) {
case 0 :
case 1 :
snprintf ( V_43 , V_140 , L_29 ,
V_14 -> V_37 , V_141 , V_76 -> V_90 ) ;
break;
default:
V_24 = snprintf ( V_43 , V_140 ,
L_30 , V_14 -> V_37 , * V_141 ,
V_143 [ V_14 -> V_56 ] , V_76 -> V_90 ) ;
if ( V_138 ) {
int V_144 = V_140 - V_24 - 2 ;
int V_145 = 0 ;
if ( V_139 > V_144 )
V_145 = V_139 - V_144 ;
snprintf ( V_43 + V_24 ,
V_140 - V_24 , L_31 ,
V_139 - V_145 , V_138 + V_145 ) ;
}
break;
}
F_67 (ctl, &dsp->ctl_list, list) {
if ( ! strcmp ( V_73 -> V_43 , V_43 ) ) {
if ( ! V_73 -> V_101 )
V_73 -> V_101 = 1 ;
return 0 ;
}
}
V_73 = F_2 ( sizeof( * V_73 ) , V_7 ) ;
if ( ! V_73 )
return - V_95 ;
V_73 -> V_146 = V_143 [ V_14 -> V_56 ] ;
V_73 -> V_76 = * V_76 ;
V_73 -> V_43 = F_53 ( V_43 , strlen ( V_43 ) + 1 , V_7 ) ;
if ( ! V_73 -> V_43 ) {
V_24 = - V_95 ;
goto V_147;
}
V_73 -> V_101 = 1 ;
V_73 -> V_100 = 0 ;
V_73 -> V_148 . V_149 = F_59 ;
V_73 -> V_148 . V_150 = F_54 ;
V_73 -> V_14 = V_14 ;
V_73 -> V_105 = V_105 ;
V_73 -> type = type ;
V_73 -> V_64 = V_64 ;
V_73 -> V_3 = V_3 ;
V_73 -> V_99 = F_2 ( V_73 -> V_3 , V_7 ) ;
if ( ! V_73 -> V_99 ) {
V_24 = - V_95 ;
goto V_151;
}
F_73 ( & V_73 -> V_5 , & V_14 -> V_152 ) ;
if ( V_105 & V_153 )
return 0 ;
V_137 = F_2 ( sizeof( * V_137 ) , V_7 ) ;
if ( ! V_137 ) {
V_24 = - V_95 ;
goto V_154;
}
V_137 -> V_14 = V_14 ;
V_137 -> V_73 = V_73 ;
F_74 ( & V_137 -> V_135 , F_70 ) ;
F_75 ( & V_137 -> V_135 ) ;
return 0 ;
V_154:
F_4 ( V_73 -> V_99 ) ;
V_151:
F_4 ( V_73 -> V_43 ) ;
V_147:
F_4 ( V_73 ) ;
return V_24 ;
}
static int F_76 ( int V_97 , const T_7 * * V_155 , const T_7 * * V_156 )
{
int V_157 ;
switch ( V_97 ) {
case 1 :
V_157 = * * V_155 ;
break;
case 2 :
V_157 = F_77 ( * ( ( V_158 * ) * V_155 ) ) ;
break;
default:
return 0 ;
}
if ( V_156 )
* V_156 = * V_155 + V_97 ;
* V_155 += ( ( V_157 + V_97 ) + 3 ) & ~ 0x03 ;
return V_157 ;
}
static int F_78 ( int V_97 , const T_7 * * V_155 )
{
int V_89 = 0 ;
switch ( V_97 ) {
case 2 :
V_89 = F_77 ( * ( ( V_158 * ) * V_155 ) ) ;
break;
case 4 :
V_89 = F_79 ( * ( ( V_159 * ) * V_155 ) ) ;
break;
default:
break;
}
* V_155 += V_97 ;
return V_89 ;
}
static inline void F_80 ( struct V_13 * V_14 , const T_7 * * V_98 ,
struct V_160 * V_161 )
{
const struct V_162 * V_163 ;
switch ( V_14 -> V_142 ) {
case 0 :
case 1 :
V_163 = ( const struct V_162 * ) * V_98 ;
* V_98 = V_163 -> V_98 ;
V_161 -> V_164 = F_79 ( V_163 -> V_164 ) ;
V_161 -> V_43 = V_163 -> V_43 ;
V_161 -> V_165 = strlen ( V_163 -> V_43 ) ;
V_161 -> V_166 = F_79 ( V_163 -> V_166 ) ;
break;
default:
V_161 -> V_164 = F_78 ( sizeof( V_163 -> V_164 ) , V_98 ) ;
V_161 -> V_165 = F_76 ( sizeof( T_7 ) , V_98 ,
& V_161 -> V_43 ) ;
F_76 ( sizeof( T_5 ) , V_98 , NULL ) ;
V_161 -> V_166 = F_78 ( sizeof( V_163 -> V_166 ) , V_98 ) ;
break;
}
F_41 ( V_14 , L_32 , V_161 -> V_164 ) ;
F_41 ( V_14 , L_33 , V_161 -> V_165 , V_161 -> V_43 ) ;
F_41 ( V_14 , L_34 , V_161 -> V_166 ) ;
}
static inline void F_81 ( struct V_13 * V_14 , const T_7 * * V_98 ,
struct V_167 * V_161 )
{
const struct V_168 * V_163 ;
const T_7 * V_16 ;
int V_157 ;
switch ( V_14 -> V_142 ) {
case 0 :
case 1 :
V_163 = ( const struct V_168 * ) * V_98 ;
* V_98 = * V_98 + sizeof( V_163 -> V_169 ) + F_79 ( V_163 -> V_169 . V_102 ) ;
V_161 -> V_64 = F_77 ( V_163 -> V_169 . V_64 ) ;
V_161 -> V_170 = F_77 ( V_163 -> V_169 . type ) ;
V_161 -> V_43 = V_163 -> V_43 ;
V_161 -> V_165 = strlen ( V_163 -> V_43 ) ;
V_161 -> V_171 = F_77 ( V_163 -> V_171 ) ;
V_161 -> V_105 = F_77 ( V_163 -> V_105 ) ;
V_161 -> V_3 = F_79 ( V_163 -> V_3 ) ;
break;
default:
V_16 = * V_98 ;
V_161 -> V_64 = F_78 ( sizeof( V_163 -> V_169 . V_64 ) , & V_16 ) ;
V_161 -> V_170 = F_78 ( sizeof( V_163 -> V_169 . type ) , & V_16 ) ;
V_157 = F_78 ( sizeof( V_163 -> V_169 . V_102 ) , & V_16 ) ;
V_161 -> V_165 = F_76 ( sizeof( T_7 ) , & V_16 ,
& V_161 -> V_43 ) ;
F_76 ( sizeof( T_7 ) , & V_16 , NULL ) ;
F_76 ( sizeof( T_5 ) , & V_16 , NULL ) ;
V_161 -> V_171 = F_78 ( sizeof( V_163 -> V_171 ) , & V_16 ) ;
V_161 -> V_105 = F_78 ( sizeof( V_163 -> V_105 ) , & V_16 ) ;
V_161 -> V_3 = F_78 ( sizeof( V_163 -> V_3 ) , & V_16 ) ;
* V_98 = * V_98 + sizeof( V_163 -> V_169 ) + V_157 ;
break;
}
F_41 ( V_14 , L_35 , V_161 -> V_170 ) ;
F_41 ( V_14 , L_36 , V_161 -> V_64 ) ;
F_41 ( V_14 , L_37 , V_161 -> V_165 , V_161 -> V_43 ) ;
F_41 ( V_14 , L_38 , V_161 -> V_105 ) ;
F_41 ( V_14 , L_39 , V_161 -> V_171 ) ;
F_41 ( V_14 , L_40 , V_161 -> V_3 ) ;
}
static int F_82 ( struct V_13 * V_14 ,
const struct V_167 * V_172 ,
unsigned int V_173 ,
unsigned int V_174 )
{
if ( ( V_172 -> V_105 & V_174 ) ||
( ( V_172 -> V_105 & V_173 ) != V_173 ) ) {
F_22 ( V_14 , L_41 ,
V_172 -> V_105 , V_172 -> V_171 ) ;
return - V_58 ;
}
return 0 ;
}
static int F_83 ( struct V_13 * V_14 ,
const struct V_175 * V_176 )
{
struct V_75 V_76 = {} ;
struct V_160 V_177 ;
struct V_167 V_172 ;
const T_7 * V_98 = V_176 -> V_98 ;
int V_32 , V_24 ;
F_80 ( V_14 , & V_98 , & V_177 ) ;
for ( V_32 = 0 ; V_32 < V_177 . V_166 ; V_32 ++ ) {
F_81 ( V_14 , & V_98 , & V_172 ) ;
switch ( V_172 . V_171 ) {
case V_87 :
break;
case V_80 :
if ( V_172 . V_105 & V_153 )
continue;
V_24 = F_82 ( V_14 , & V_172 ,
V_106 |
V_120 |
V_119 ,
0 ) ;
if ( V_24 )
return - V_58 ;
break;
case V_133 :
V_24 = F_82 ( V_14 , & V_172 ,
V_153 |
V_106 |
V_120 |
V_119 ,
0 ) ;
if ( V_24 )
return - V_58 ;
break;
default:
F_22 ( V_14 , L_42 ,
V_172 . V_171 ) ;
return - V_58 ;
}
V_76 . type = V_172 . V_170 ;
V_76 . V_90 = V_177 . V_164 ;
V_24 = F_72 ( V_14 , & V_76 ,
V_172 . V_64 ,
V_172 . V_3 ,
V_172 . V_43 ,
V_172 . V_165 ,
V_172 . V_105 ,
V_172 . V_171 ) ;
if ( V_24 < 0 )
F_22 ( V_14 , L_43 ,
V_172 . V_165 , V_172 . V_43 , V_24 ) ;
}
return 0 ;
}
static int F_84 ( struct V_13 * V_14 )
{
F_85 ( V_178 ) ;
const struct V_179 * V_179 ;
struct V_67 * V_67 = V_14 -> V_67 ;
unsigned int V_155 = 0 ;
const struct V_180 * V_181 ;
const struct V_182 * V_183 ;
const struct V_184 * V_185 ;
const struct V_186 * V_187 ;
const struct V_175 * V_176 ;
const struct V_61 * V_63 ;
const char * V_141 ;
char * V_19 , * V_188 = NULL ;
struct V_1 * V_6 ;
unsigned int V_74 ;
int V_189 = 0 ;
int V_24 , V_64 , type , V_190 ;
V_19 = F_2 ( V_36 , V_7 ) ;
if ( V_19 == NULL )
return - V_95 ;
snprintf ( V_19 , V_36 , L_44 , V_14 -> V_191 , V_14 -> V_37 ,
V_192 [ V_14 -> V_56 ] . V_19 ) ;
V_19 [ V_36 - 1 ] = '\0' ;
V_24 = F_86 ( & V_179 , V_19 , V_14 -> V_193 ) ;
if ( V_24 != 0 ) {
F_22 ( V_14 , L_45 , V_19 ) ;
goto V_108;
}
V_24 = - V_58 ;
V_155 = sizeof( * V_181 ) + sizeof( * V_183 ) + sizeof( * V_187 ) ;
if ( V_155 >= V_179 -> V_102 ) {
F_22 ( V_14 , L_46 ,
V_19 , V_179 -> V_102 ) ;
goto V_194;
}
V_181 = ( void * ) & V_179 -> V_98 [ 0 ] ;
if ( memcmp ( & V_181 -> V_195 [ 0 ] , L_47 , 4 ) != 0 ) {
F_22 ( V_14 , L_48 , V_19 ) ;
goto V_194;
}
switch ( V_181 -> V_196 ) {
case 0 :
F_51 ( V_14 , L_49 ,
V_19 , V_181 -> V_196 ) ;
break;
case 1 :
case 2 :
break;
default:
F_22 ( V_14 , L_50 ,
V_19 , V_181 -> V_196 ) ;
goto V_194;
}
F_87 ( V_14 , L_51 , V_181 -> V_196 ) ;
V_14 -> V_142 = V_181 -> V_196 ;
if ( V_181 -> V_197 != V_14 -> type ) {
F_22 ( V_14 , L_52 ,
V_19 , V_181 -> V_197 , V_14 -> type ) ;
goto V_194;
}
switch ( V_14 -> type ) {
case V_198 :
V_155 = sizeof( * V_181 ) + sizeof( * V_183 ) + sizeof( * V_187 ) ;
V_183 = ( void * ) & ( V_181 [ 1 ] ) ;
V_187 = ( void * ) & ( V_183 [ 1 ] ) ;
V_190 = sizeof( * V_183 ) ;
F_41 ( V_14 , L_53 ,
V_19 , F_79 ( V_183 -> V_199 ) ,
F_79 ( V_183 -> V_200 ) ,
F_79 ( V_183 -> V_201 ) ) ;
break;
case V_202 :
V_155 = sizeof( * V_181 ) + sizeof( * V_185 ) + sizeof( * V_187 ) ;
V_185 = ( void * ) & ( V_181 [ 1 ] ) ;
V_187 = ( void * ) & ( V_185 [ 1 ] ) ;
V_190 = sizeof( * V_185 ) ;
F_41 ( V_14 , L_54 ,
V_19 , F_79 ( V_185 -> V_203 ) ,
F_79 ( V_185 -> V_204 ) ,
F_79 ( V_185 -> V_200 ) ,
F_79 ( V_185 -> V_201 ) ) ;
break;
default:
F_38 ( 1 , L_55 ) ;
goto V_194;
}
if ( F_79 ( V_181 -> V_3 ) != sizeof( * V_181 ) +
V_190 + sizeof( * V_187 ) ) {
F_22 ( V_14 , L_56 ,
V_19 , F_79 ( V_181 -> V_3 ) ) ;
goto V_194;
}
F_41 ( V_14 , L_57 , V_19 ,
F_88 ( V_187 -> V_205 ) ) ;
while ( V_155 < V_179 -> V_102 &&
V_155 - V_179 -> V_102 > sizeof( * V_176 ) ) {
V_176 = ( void * ) & ( V_179 -> V_98 [ V_155 ] ) ;
V_141 = L_58 ;
V_74 = 0 ;
V_188 = NULL ;
V_64 = F_79 ( V_176 -> V_64 ) & 0xffffff ;
type = F_89 ( V_176 -> type ) & 0xff ;
V_63 = F_35 ( V_14 , type ) ;
switch ( type ) {
case V_206 :
V_141 = L_59 ;
V_188 = F_2 ( F_79 ( V_176 -> V_3 ) + 1 ,
V_7 ) ;
break;
case V_207 :
V_141 = L_60 ;
V_24 = F_83 ( V_14 , V_176 ) ;
if ( V_24 != 0 )
goto V_194;
break;
case V_208 :
V_141 = L_61 ;
V_188 = F_2 ( F_79 ( V_176 -> V_3 ) + 1 ,
V_7 ) ;
break;
case V_209 :
V_141 = L_62 ;
V_74 = V_64 ;
break;
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
V_141 = F_11 ( type ) ;
V_74 = F_36 ( V_63 , V_64 ) ;
break;
default:
F_51 ( V_14 ,
L_63 ,
V_19 , V_189 , type , V_155 , V_155 ) ;
break;
}
F_41 ( V_14 , L_64 , V_19 ,
V_189 , F_79 ( V_176 -> V_3 ) , V_64 ,
V_141 ) ;
if ( ( V_155 + F_79 ( V_176 -> V_3 ) + sizeof( * V_176 ) ) >
V_179 -> V_102 ) {
F_22 ( V_14 ,
L_65 ,
V_19 , V_189 , V_141 ,
F_79 ( V_176 -> V_3 ) , V_179 -> V_102 ) ;
V_24 = - V_58 ;
goto V_194;
}
if ( V_188 ) {
memcpy ( V_188 , V_176 -> V_98 , F_79 ( V_176 -> V_3 ) ) ;
F_87 ( V_14 , L_66 , V_19 , V_188 ) ;
F_4 ( V_188 ) ;
V_188 = NULL ;
}
if ( V_74 ) {
V_6 = F_1 ( V_176 -> V_98 ,
F_79 ( V_176 -> V_3 ) ,
& V_178 ) ;
if ( ! V_6 ) {
F_22 ( V_14 , L_67 ) ;
V_24 = - V_95 ;
goto V_194;
}
V_24 = F_90 ( V_67 , V_74 , V_6 -> V_6 ,
F_79 ( V_176 -> V_3 ) ) ;
if ( V_24 != 0 ) {
F_22 ( V_14 ,
L_68 ,
V_19 , V_189 ,
F_79 ( V_176 -> V_3 ) , V_64 ,
V_141 , V_24 ) ;
goto V_194;
}
}
V_155 += F_79 ( V_176 -> V_3 ) + sizeof( * V_176 ) ;
V_189 ++ ;
}
V_24 = F_91 ( V_67 ) ;
if ( V_24 != 0 ) {
F_22 ( V_14 , L_69 , V_24 ) ;
goto V_194;
}
if ( V_155 > V_179 -> V_102 )
F_51 ( V_14 , L_70 ,
V_19 , V_189 , V_155 - V_179 -> V_102 ) ;
F_12 ( V_14 , V_19 ) ;
V_194:
F_91 ( V_67 ) ;
F_6 ( & V_178 ) ;
F_92 ( V_179 ) ;
F_4 ( V_188 ) ;
V_108:
F_4 ( V_19 ) ;
return V_24 ;
}
static void F_93 ( struct V_13 * V_14 ,
const struct V_75 * V_76 )
{
struct V_69 * V_73 ;
F_67 (ctl, &dsp->ctl_list, list) {
if ( V_73 -> V_146 == V_143 [ V_14 -> V_56 ] &&
V_76 -> V_90 == V_73 -> V_76 . V_90 &&
V_76 -> type == V_73 -> V_76 . type ) {
V_73 -> V_76 . V_65 = V_76 -> V_65 ;
}
}
}
static void * F_94 ( struct V_13 * V_14 , T_1 V_210 ,
unsigned int V_155 , unsigned int V_3 )
{
void * V_90 ;
int V_24 ;
T_8 V_89 ;
if ( V_210 == 0 ) {
F_22 ( V_14 , L_71 ) ;
return F_95 ( - V_58 ) ;
}
if ( V_210 > 1024 ) {
F_22 ( V_14 , L_72 , V_210 ) ;
return F_95 ( - V_58 ) ;
}
V_24 = F_40 ( V_14 -> V_67 , V_155 + V_3 , & V_89 , sizeof( V_89 ) ) ;
if ( V_24 != 0 ) {
F_22 ( V_14 , L_73 ,
V_24 ) ;
return F_95 ( V_24 ) ;
}
if ( F_89 ( V_89 ) != 0xbedead )
F_51 ( V_14 , L_74 ,
V_155 + V_3 , F_89 ( V_89 ) ) ;
V_90 = F_2 ( V_3 * 2 , V_7 | V_94 ) ;
if ( ! V_90 )
return F_95 ( - V_95 ) ;
V_24 = F_40 ( V_14 -> V_67 , V_155 , V_90 , V_3 * 2 ) ;
if ( V_24 != 0 ) {
F_22 ( V_14 , L_75 , V_24 ) ;
F_4 ( V_90 ) ;
return F_95 ( V_24 ) ;
}
return V_90 ;
}
static struct V_75 *
F_96 ( struct V_13 * V_14 , int type , unsigned int V_164 )
{
struct V_75 * V_76 ;
F_67 (alg_region, &dsp->alg_regions, list) {
if ( V_164 == V_76 -> V_90 && type == V_76 -> type )
return V_76 ;
}
return NULL ;
}
static struct V_75 * F_97 ( struct V_13 * V_14 ,
int type , T_8 V_164 ,
T_8 V_65 )
{
struct V_75 * V_76 ;
V_76 = F_2 ( sizeof( * V_76 ) , V_7 ) ;
if ( ! V_76 )
return F_95 ( - V_95 ) ;
V_76 -> type = type ;
V_76 -> V_90 = F_89 ( V_164 ) ;
V_76 -> V_65 = F_89 ( V_65 ) ;
F_5 ( & V_76 -> V_5 , & V_14 -> V_211 ) ;
if ( V_14 -> V_142 > 0 )
F_93 ( V_14 , V_76 ) ;
return V_76 ;
}
static void F_98 ( struct V_13 * V_14 )
{
struct V_75 * V_76 ;
while ( ! F_7 ( & V_14 -> V_211 ) ) {
V_76 = F_8 ( & V_14 -> V_211 ,
struct V_75 ,
V_5 ) ;
F_9 ( & V_76 -> V_5 ) ;
F_4 ( V_76 ) ;
}
}
static int F_99 ( struct V_13 * V_14 )
{
struct V_212 V_213 ;
struct V_214 * V_215 ;
struct V_75 * V_76 ;
const struct V_61 * V_63 ;
unsigned int V_155 , V_3 ;
T_1 V_210 ;
int V_32 , V_24 ;
V_63 = F_35 ( V_14 , V_9 ) ;
if ( F_37 ( ! V_63 ) )
return - V_58 ;
V_24 = F_40 ( V_14 -> V_67 , V_63 -> V_65 , & V_213 ,
sizeof( V_213 ) ) ;
if ( V_24 != 0 ) {
F_22 ( V_14 , L_76 ,
V_24 ) ;
return V_24 ;
}
V_210 = F_89 ( V_213 . V_210 ) ;
V_14 -> V_40 = F_89 ( V_213 . V_56 . V_164 ) ;
F_87 ( V_14 , L_77 ,
V_14 -> V_40 ,
( F_89 ( V_213 . V_56 . V_196 ) & 0xff0000 ) >> 16 ,
( F_89 ( V_213 . V_56 . V_196 ) & 0xff00 ) >> 8 ,
F_89 ( V_213 . V_56 . V_196 ) & 0xff ,
V_210 ) ;
V_76 = F_97 ( V_14 , V_12 ,
V_213 . V_56 . V_164 , V_213 . V_201 ) ;
if ( F_100 ( V_76 ) )
return F_101 ( V_76 ) ;
V_76 = F_97 ( V_14 , V_9 ,
V_213 . V_56 . V_164 , V_213 . V_199 ) ;
if ( F_100 ( V_76 ) )
return F_101 ( V_76 ) ;
V_155 = sizeof( V_213 ) / 2 ;
V_3 = ( sizeof( * V_215 ) * V_210 ) / 2 ;
V_215 = F_94 ( V_14 , V_210 , V_63 -> V_65 + V_155 , V_3 ) ;
if ( F_100 ( V_215 ) )
return F_101 ( V_215 ) ;
for ( V_32 = 0 ; V_32 < V_210 ; V_32 ++ ) {
F_87 ( V_14 , L_78 ,
V_32 , F_89 ( V_215 [ V_32 ] . V_90 . V_164 ) ,
( F_89 ( V_215 [ V_32 ] . V_90 . V_196 ) & 0xff0000 ) >> 16 ,
( F_89 ( V_215 [ V_32 ] . V_90 . V_196 ) & 0xff00 ) >> 8 ,
F_89 ( V_215 [ V_32 ] . V_90 . V_196 ) & 0xff ,
F_89 ( V_215 [ V_32 ] . V_199 ) ,
F_89 ( V_215 [ V_32 ] . V_201 ) ) ;
V_76 = F_97 ( V_14 , V_9 ,
V_215 [ V_32 ] . V_90 . V_164 ,
V_215 [ V_32 ] . V_199 ) ;
if ( F_100 ( V_76 ) ) {
V_24 = F_101 ( V_76 ) ;
goto V_108;
}
if ( V_14 -> V_142 == 0 ) {
if ( V_32 + 1 < V_210 ) {
V_3 = F_89 ( V_215 [ V_32 + 1 ] . V_199 ) ;
V_3 -= F_89 ( V_215 [ V_32 ] . V_199 ) ;
V_3 *= 4 ;
F_72 ( V_14 , V_76 , 0 ,
V_3 , NULL , 0 , 0 ,
V_87 ) ;
} else {
F_51 ( V_14 , L_79 ,
F_89 ( V_215 [ V_32 ] . V_90 . V_164 ) ) ;
}
}
V_76 = F_97 ( V_14 , V_12 ,
V_215 [ V_32 ] . V_90 . V_164 ,
V_215 [ V_32 ] . V_201 ) ;
if ( F_100 ( V_76 ) ) {
V_24 = F_101 ( V_76 ) ;
goto V_108;
}
if ( V_14 -> V_142 == 0 ) {
if ( V_32 + 1 < V_210 ) {
V_3 = F_89 ( V_215 [ V_32 + 1 ] . V_201 ) ;
V_3 -= F_89 ( V_215 [ V_32 ] . V_201 ) ;
V_3 *= 4 ;
F_72 ( V_14 , V_76 , 0 ,
V_3 , NULL , 0 , 0 ,
V_87 ) ;
} else {
F_51 ( V_14 , L_80 ,
F_89 ( V_215 [ V_32 ] . V_90 . V_164 ) ) ;
}
}
}
V_108:
F_4 ( V_215 ) ;
return V_24 ;
}
static int F_102 ( struct V_13 * V_14 )
{
struct V_216 V_217 ;
struct V_218 * V_219 ;
struct V_75 * V_76 ;
const struct V_61 * V_63 ;
unsigned int V_155 , V_3 ;
T_1 V_210 ;
int V_32 , V_24 ;
V_63 = F_35 ( V_14 , V_10 ) ;
if ( F_37 ( ! V_63 ) )
return - V_58 ;
V_24 = F_40 ( V_14 -> V_67 , V_63 -> V_65 , & V_217 ,
sizeof( V_217 ) ) ;
if ( V_24 != 0 ) {
F_22 ( V_14 , L_76 ,
V_24 ) ;
return V_24 ;
}
V_210 = F_89 ( V_217 . V_210 ) ;
V_14 -> V_40 = F_89 ( V_217 . V_56 . V_164 ) ;
V_14 -> V_41 = F_89 ( V_217 . V_56 . V_196 ) ;
F_87 ( V_14 , L_77 ,
V_14 -> V_40 ,
( V_14 -> V_41 & 0xff0000 ) >> 16 ,
( V_14 -> V_41 & 0xff00 ) >> 8 ,
V_14 -> V_41 & 0xff ,
V_210 ) ;
V_76 = F_97 ( V_14 , V_10 ,
V_217 . V_56 . V_164 , V_217 . V_203 ) ;
if ( F_100 ( V_76 ) )
return F_101 ( V_76 ) ;
V_76 = F_97 ( V_14 , V_11 ,
V_217 . V_56 . V_164 , V_217 . V_204 ) ;
if ( F_100 ( V_76 ) )
return F_101 ( V_76 ) ;
V_76 = F_97 ( V_14 , V_220 ,
V_217 . V_56 . V_164 , V_217 . V_201 ) ;
if ( F_100 ( V_76 ) )
return F_101 ( V_76 ) ;
V_155 = sizeof( V_217 ) / 2 ;
V_3 = ( sizeof( * V_219 ) * V_210 ) / 2 ;
V_219 = F_94 ( V_14 , V_210 , V_63 -> V_65 + V_155 , V_3 ) ;
if ( F_100 ( V_219 ) )
return F_101 ( V_219 ) ;
for ( V_32 = 0 ; V_32 < V_210 ; V_32 ++ ) {
F_87 ( V_14 ,
L_81 ,
V_32 , F_89 ( V_219 [ V_32 ] . V_90 . V_164 ) ,
( F_89 ( V_219 [ V_32 ] . V_90 . V_196 ) & 0xff0000 ) >> 16 ,
( F_89 ( V_219 [ V_32 ] . V_90 . V_196 ) & 0xff00 ) >> 8 ,
F_89 ( V_219 [ V_32 ] . V_90 . V_196 ) & 0xff ,
F_89 ( V_219 [ V_32 ] . V_203 ) ,
F_89 ( V_219 [ V_32 ] . V_204 ) ,
F_89 ( V_219 [ V_32 ] . V_201 ) ) ;
V_76 = F_97 ( V_14 , V_10 ,
V_219 [ V_32 ] . V_90 . V_164 ,
V_219 [ V_32 ] . V_203 ) ;
if ( F_100 ( V_76 ) ) {
V_24 = F_101 ( V_76 ) ;
goto V_108;
}
if ( V_14 -> V_142 == 0 ) {
if ( V_32 + 1 < V_210 ) {
V_3 = F_89 ( V_219 [ V_32 + 1 ] . V_203 ) ;
V_3 -= F_89 ( V_219 [ V_32 ] . V_203 ) ;
V_3 *= 4 ;
F_72 ( V_14 , V_76 , 0 ,
V_3 , NULL , 0 , 0 ,
V_87 ) ;
} else {
F_51 ( V_14 , L_82 ,
F_89 ( V_219 [ V_32 ] . V_90 . V_164 ) ) ;
}
}
V_76 = F_97 ( V_14 , V_11 ,
V_219 [ V_32 ] . V_90 . V_164 ,
V_219 [ V_32 ] . V_204 ) ;
if ( F_100 ( V_76 ) ) {
V_24 = F_101 ( V_76 ) ;
goto V_108;
}
if ( V_14 -> V_142 == 0 ) {
if ( V_32 + 1 < V_210 ) {
V_3 = F_89 ( V_219 [ V_32 + 1 ] . V_204 ) ;
V_3 -= F_89 ( V_219 [ V_32 ] . V_204 ) ;
V_3 *= 4 ;
F_72 ( V_14 , V_76 , 0 ,
V_3 , NULL , 0 , 0 ,
V_87 ) ;
} else {
F_51 ( V_14 , L_83 ,
F_89 ( V_219 [ V_32 ] . V_90 . V_164 ) ) ;
}
}
V_76 = F_97 ( V_14 , V_220 ,
V_219 [ V_32 ] . V_90 . V_164 ,
V_219 [ V_32 ] . V_201 ) ;
if ( F_100 ( V_76 ) ) {
V_24 = F_101 ( V_76 ) ;
goto V_108;
}
if ( V_14 -> V_142 == 0 ) {
if ( V_32 + 1 < V_210 ) {
V_3 = F_89 ( V_219 [ V_32 + 1 ] . V_201 ) ;
V_3 -= F_89 ( V_219 [ V_32 ] . V_201 ) ;
V_3 *= 4 ;
F_72 ( V_14 , V_76 , 0 ,
V_3 , NULL , 0 , 0 ,
V_87 ) ;
} else {
F_51 ( V_14 , L_80 ,
F_89 ( V_219 [ V_32 ] . V_90 . V_164 ) ) ;
}
}
}
V_108:
F_4 ( V_219 ) ;
return V_24 ;
}
static int F_103 ( struct V_13 * V_14 )
{
F_85 ( V_178 ) ;
struct V_67 * V_67 = V_14 -> V_67 ;
struct V_221 * V_169 ;
struct V_222 * V_161 ;
const struct V_179 * V_179 ;
const struct V_61 * V_63 ;
struct V_75 * V_76 ;
const char * V_141 ;
int V_24 , V_155 , V_223 , type , V_64 , V_74 ;
char * V_19 ;
struct V_1 * V_6 ;
V_19 = F_2 ( V_36 , V_7 ) ;
if ( V_19 == NULL )
return - V_95 ;
snprintf ( V_19 , V_36 , L_84 , V_14 -> V_191 , V_14 -> V_37 ,
V_192 [ V_14 -> V_56 ] . V_19 ) ;
V_19 [ V_36 - 1 ] = '\0' ;
V_24 = F_86 ( & V_179 , V_19 , V_14 -> V_193 ) ;
if ( V_24 != 0 ) {
F_51 ( V_14 , L_45 , V_19 ) ;
V_24 = 0 ;
goto V_108;
}
V_24 = - V_58 ;
if ( sizeof( * V_169 ) >= V_179 -> V_102 ) {
F_22 ( V_14 , L_46 ,
V_19 , V_179 -> V_102 ) ;
goto V_194;
}
V_169 = ( void * ) & V_179 -> V_98 [ 0 ] ;
if ( memcmp ( V_169 -> V_195 , L_85 , 4 ) != 0 ) {
F_22 ( V_14 , L_48 , V_19 ) ;
goto V_194;
}
switch ( F_89 ( V_169 -> V_224 ) & 0xff ) {
case 1 :
break;
default:
F_22 ( V_14 , L_86 ,
V_19 , F_89 ( V_169 -> V_224 ) & 0xff ) ;
V_24 = - V_58 ;
goto V_194;
}
F_41 ( V_14 , L_87 , V_19 ,
( F_79 ( V_169 -> V_196 ) >> 16 ) & 0xff ,
( F_79 ( V_169 -> V_196 ) >> 8 ) & 0xff ,
F_79 ( V_169 -> V_196 ) & 0xff ) ;
V_155 = F_79 ( V_169 -> V_3 ) ;
V_223 = 0 ;
while ( V_155 < V_179 -> V_102 &&
V_155 - V_179 -> V_102 > sizeof( * V_161 ) ) {
V_161 = ( void * ) ( & V_179 -> V_98 [ V_155 ] ) ;
type = F_77 ( V_161 -> type ) ;
V_64 = F_77 ( V_161 -> V_64 ) ;
F_41 ( V_14 , L_88 ,
V_19 , V_223 , F_79 ( V_161 -> V_164 ) ,
( F_79 ( V_161 -> V_196 ) >> 16 ) & 0xff ,
( F_79 ( V_161 -> V_196 ) >> 8 ) & 0xff ,
F_79 ( V_161 -> V_196 ) & 0xff ) ;
F_41 ( V_14 , L_89 ,
V_19 , V_223 , F_79 ( V_161 -> V_3 ) , V_64 , type ) ;
V_74 = 0 ;
V_141 = L_58 ;
switch ( type ) {
case ( V_206 << 8 ) :
case ( V_208 << 8 ) :
break;
case ( V_209 << 8 ) :
if ( F_79 ( V_161 -> V_164 ) == V_14 -> V_40 &&
V_64 == 0 ) {
V_141 = L_90 ;
V_63 = F_35 ( V_14 , type ) ;
if ( ! V_63 ) {
F_22 ( V_14 , L_91 ) ;
break;
}
V_74 = F_36 ( V_63 , 0 ) ;
} else {
V_141 = L_92 ;
V_74 = V_64 ;
}
break;
case V_9 :
case V_12 :
case V_10 :
case V_11 :
F_41 ( V_14 , L_93 ,
V_19 , V_223 , F_79 ( V_161 -> V_3 ) ,
type , F_79 ( V_161 -> V_164 ) ) ;
V_63 = F_35 ( V_14 , type ) ;
if ( ! V_63 ) {
F_22 ( V_14 , L_17 , type ) ;
break;
}
V_76 = F_96 ( V_14 , type ,
F_79 ( V_161 -> V_164 ) ) ;
if ( V_76 ) {
V_74 = V_76 -> V_65 ;
V_74 = F_36 ( V_63 , V_74 ) ;
V_74 += V_64 ;
} else {
F_22 ( V_14 , L_94 ,
type , F_79 ( V_161 -> V_164 ) ) ;
}
break;
default:
F_22 ( V_14 , L_95 ,
V_19 , V_223 , type , V_155 ) ;
break;
}
if ( V_74 ) {
if ( ( V_155 + F_79 ( V_161 -> V_3 ) + sizeof( * V_161 ) ) >
V_179 -> V_102 ) {
F_22 ( V_14 ,
L_65 ,
V_19 , V_223 , V_141 ,
F_79 ( V_161 -> V_3 ) ,
V_179 -> V_102 ) ;
V_24 = - V_58 ;
goto V_194;
}
V_6 = F_1 ( V_161 -> V_98 ,
F_79 ( V_161 -> V_3 ) ,
& V_178 ) ;
if ( ! V_6 ) {
F_22 ( V_14 , L_67 ) ;
V_24 = - V_95 ;
goto V_194;
}
F_41 ( V_14 , L_96 ,
V_19 , V_223 , F_79 ( V_161 -> V_3 ) ,
V_74 ) ;
V_24 = F_90 ( V_67 , V_74 , V_6 -> V_6 ,
F_79 ( V_161 -> V_3 ) ) ;
if ( V_24 != 0 ) {
F_22 ( V_14 ,
L_97 ,
V_19 , V_223 , V_74 , V_141 , V_24 ) ;
}
}
V_155 += ( F_79 ( V_161 -> V_3 ) + sizeof( * V_161 ) + 3 ) & ~ 0x03 ;
V_223 ++ ;
}
V_24 = F_91 ( V_67 ) ;
if ( V_24 != 0 )
F_22 ( V_14 , L_69 , V_24 ) ;
if ( V_155 > V_179 -> V_102 )
F_51 ( V_14 , L_70 ,
V_19 , V_223 , V_155 - V_179 -> V_102 ) ;
F_14 ( V_14 , V_19 ) ;
V_194:
F_91 ( V_67 ) ;
F_92 ( V_179 ) ;
F_6 ( & V_178 ) ;
V_108:
F_4 ( V_19 ) ;
return V_24 ;
}
int F_104 ( struct V_13 * V_14 )
{
F_105 ( & V_14 -> V_211 ) ;
F_106 ( & V_14 -> V_25 ) ;
return 0 ;
}
int F_107 ( struct V_225 * V_226 ,
struct V_45 * V_46 ,
int V_132 )
{
struct V_27 * V_28 = F_108 ( V_226 -> V_227 ) ;
struct V_13 * V_228 = F_33 ( V_28 ) ;
struct V_13 * V_14 = & V_228 [ V_226 -> V_229 ] ;
struct V_69 * V_73 ;
int V_24 ;
unsigned int V_89 ;
V_14 -> V_28 = V_28 ;
F_17 ( & V_14 -> V_25 ) ;
switch ( V_132 ) {
case V_230 :
F_109 ( V_14 -> V_67 , V_14 -> V_65 + V_231 ,
V_232 , V_232 ) ;
if ( V_14 -> V_233 ) {
V_24 = F_110 ( V_14 -> V_67 , V_14 -> V_233 , & V_89 ) ;
if ( V_24 != 0 ) {
F_22 ( V_14 , L_98 ,
V_24 ) ;
goto V_234;
}
V_89 = ( V_89 & V_14 -> V_235 ) >> V_14 -> V_236 ;
V_24 = F_109 ( V_14 -> V_67 ,
V_14 -> V_65 + V_237 ,
V_238 , V_89 ) ;
if ( V_24 != 0 ) {
F_22 ( V_14 , L_99 ,
V_24 ) ;
goto V_234;
}
}
V_24 = F_84 ( V_14 ) ;
if ( V_24 != 0 )
goto V_239;
V_24 = F_99 ( V_14 ) ;
if ( V_24 != 0 )
goto V_239;
V_24 = F_103 ( V_14 ) ;
if ( V_24 != 0 )
goto V_239;
V_24 = F_66 ( V_14 ) ;
if ( V_24 != 0 )
goto V_239;
V_24 = F_68 ( V_14 ) ;
if ( V_24 != 0 )
goto V_239;
V_14 -> V_26 = true ;
F_109 ( V_14 -> V_67 , V_14 -> V_65 + V_231 ,
V_240 | V_241 ,
V_240 | V_241 ) ;
V_14 -> V_39 = true ;
break;
case V_242 :
V_14 -> V_39 = false ;
V_14 -> V_26 = false ;
F_109 ( V_14 -> V_67 , V_14 -> V_65 + V_231 ,
V_240 | V_241 , 0 ) ;
F_109 ( V_14 -> V_67 , V_14 -> V_65 + V_243 ,
V_244 , 0 ) ;
F_109 ( V_14 -> V_67 , V_14 -> V_65 + V_231 ,
V_232 , 0 ) ;
F_67 (ctl, &dsp->ctl_list, list)
V_73 -> V_101 = 0 ;
F_98 ( V_14 ) ;
break;
default:
break;
}
F_19 ( & V_14 -> V_25 ) ;
return 0 ;
V_239:
F_109 ( V_14 -> V_67 , V_14 -> V_65 + V_231 ,
V_232 , 0 ) ;
V_234:
F_19 ( & V_14 -> V_25 ) ;
return V_24 ;
}
static int F_111 ( struct V_13 * V_14 )
{
unsigned int V_89 ;
int V_24 , V_21 ;
V_24 = F_112 ( V_14 -> V_67 , V_14 -> V_65 + V_245 ,
V_246 , V_246 ) ;
if ( V_24 != 0 )
return V_24 ;
for ( V_21 = 0 ; V_21 < 10 ; ++ V_21 ) {
V_24 = F_110 ( V_14 -> V_67 , V_14 -> V_65 + V_247 , & V_89 ) ;
if ( V_24 != 0 )
return V_24 ;
if ( V_89 & V_248 )
break;
F_50 ( 250 , 500 ) ;
}
if ( ! ( V_89 & V_248 ) ) {
F_22 ( V_14 , L_100 ) ;
return - V_60 ;
}
F_41 ( V_14 , L_101 , V_21 ) ;
return 0 ;
}
static void F_113 ( struct V_134 * V_135 )
{
struct V_13 * V_14 = F_44 ( V_135 ,
struct V_13 ,
V_249 ) ;
int V_24 ;
F_17 ( & V_14 -> V_25 ) ;
V_24 = F_109 ( V_14 -> V_67 , V_14 -> V_65 + V_245 ,
V_250 , V_250 ) ;
if ( V_24 != 0 )
goto V_234;
V_24 = F_111 ( V_14 ) ;
if ( V_24 != 0 )
goto V_234;
V_24 = F_84 ( V_14 ) ;
if ( V_24 != 0 )
goto V_239;
V_24 = F_102 ( V_14 ) ;
if ( V_24 != 0 )
goto V_239;
V_24 = F_103 ( V_14 ) ;
if ( V_24 != 0 )
goto V_239;
V_24 = F_66 ( V_14 ) ;
if ( V_24 != 0 )
goto V_239;
V_14 -> V_26 = true ;
V_24 = F_109 ( V_14 -> V_67 , V_14 -> V_65 + V_245 ,
V_246 , 0 ) ;
if ( V_24 != 0 )
goto V_239;
F_19 ( & V_14 -> V_25 ) ;
return;
V_239:
F_109 ( V_14 -> V_67 , V_14 -> V_65 + V_245 ,
V_246 | V_251 | V_252 , 0 ) ;
V_234:
F_19 ( & V_14 -> V_25 ) ;
}
static void F_114 ( struct V_13 * V_14 , unsigned int V_253 )
{
int V_24 ;
V_24 = F_112 ( V_14 -> V_67 ,
V_14 -> V_65 + V_254 ,
V_255 ,
V_253 << V_256 ) ;
if ( V_24 != 0 )
F_22 ( V_14 , L_99 , V_24 ) ;
}
int F_115 ( struct V_225 * V_226 ,
struct V_45 * V_46 , int V_132 ,
unsigned int V_253 )
{
struct V_27 * V_28 = F_108 ( V_226 -> V_227 ) ;
struct V_13 * V_228 = F_33 ( V_28 ) ;
struct V_13 * V_14 = & V_228 [ V_226 -> V_229 ] ;
struct V_69 * V_73 ;
switch ( V_132 ) {
case V_257 :
F_114 ( V_14 , V_253 ) ;
F_116 ( V_258 , & V_14 -> V_249 ) ;
break;
case V_242 :
F_15 ( V_14 ) ;
V_14 -> V_40 = 0 ;
V_14 -> V_41 = 0 ;
V_14 -> V_26 = false ;
F_109 ( V_14 -> V_67 , V_14 -> V_65 + V_245 ,
V_250 , 0 ) ;
F_67 (ctl, &dsp->ctl_list, list)
V_73 -> V_101 = 0 ;
F_98 ( V_14 ) ;
F_41 ( V_14 , L_102 ) ;
break;
default:
break;
}
return 0 ;
}
int F_117 ( struct V_225 * V_226 ,
struct V_45 * V_46 , int V_132 )
{
struct V_27 * V_28 = F_108 ( V_226 -> V_227 ) ;
struct V_13 * V_228 = F_33 ( V_28 ) ;
struct V_13 * V_14 = & V_228 [ V_226 -> V_229 ] ;
int V_24 ;
switch ( V_132 ) {
case V_230 :
F_118 ( & V_14 -> V_249 ) ;
if ( ! V_14 -> V_26 )
return - V_259 ;
V_24 = F_111 ( V_14 ) ;
if ( V_24 != 0 )
goto V_35;
V_24 = F_68 ( V_14 ) ;
if ( V_24 != 0 )
goto V_35;
V_24 = F_109 ( V_14 -> V_67 ,
V_14 -> V_65 + V_245 ,
V_251 | V_252 ,
V_251 | V_252 ) ;
if ( V_24 != 0 )
goto V_35;
V_14 -> V_39 = true ;
F_17 ( & V_14 -> V_25 ) ;
if ( V_192 [ V_14 -> V_56 ] . V_260 != 0 ) {
V_24 = F_119 ( V_14 ) ;
if ( V_24 < 0 ) {
F_19 ( & V_14 -> V_25 ) ;
goto V_35;
}
}
F_19 ( & V_14 -> V_25 ) ;
break;
case V_242 :
F_69 ( V_14 , V_261 ) ;
F_39 ( V_14 ) ;
F_17 ( & V_14 -> V_25 ) ;
V_14 -> V_39 = false ;
F_109 ( V_14 -> V_67 , V_14 -> V_65 + V_245 ,
V_251 | V_252 , 0 ) ;
F_120 ( V_14 -> V_67 , V_14 -> V_65 + V_262 , 0 ) ;
F_120 ( V_14 -> V_67 , V_14 -> V_65 + V_263 , 0 ) ;
F_120 ( V_14 -> V_67 , V_14 -> V_65 + V_264 , 0 ) ;
F_109 ( V_14 -> V_67 , V_14 -> V_65 + V_245 ,
V_246 , 0 ) ;
if ( V_192 [ V_14 -> V_56 ] . V_260 != 0 )
F_121 ( V_14 ) ;
F_19 ( & V_14 -> V_25 ) ;
F_41 ( V_14 , L_103 ) ;
break;
default:
break;
}
return 0 ;
V_35:
F_109 ( V_14 -> V_67 , V_14 -> V_65 + V_245 ,
V_246 | V_251 | V_252 , 0 ) ;
return V_24 ;
}
int F_122 ( struct V_13 * V_14 , struct V_27 * V_28 )
{
V_14 -> V_28 = V_28 ;
F_21 ( V_14 , V_28 ) ;
return F_65 ( V_28 ,
& V_265 [ V_14 -> V_37 - 1 ] ,
1 ) ;
}
int F_123 ( struct V_13 * V_14 , struct V_27 * V_28 )
{
F_30 ( V_14 ) ;
return 0 ;
}
int F_124 ( struct V_13 * V_14 )
{
int V_24 ;
V_24 = F_109 ( V_14 -> V_67 , V_14 -> V_65 + V_245 ,
V_250 , 0 ) ;
if ( V_24 != 0 ) {
F_22 ( V_14 , L_104 , V_24 ) ;
return V_24 ;
}
F_105 ( & V_14 -> V_211 ) ;
F_105 ( & V_14 -> V_152 ) ;
F_74 ( & V_14 -> V_249 , F_113 ) ;
F_106 ( & V_14 -> V_25 ) ;
return 0 ;
}
void F_125 ( struct V_13 * V_14 )
{
struct V_69 * V_73 ;
while ( ! F_7 ( & V_14 -> V_152 ) ) {
V_73 = F_8 ( & V_14 -> V_152 , struct V_69 ,
V_5 ) ;
F_9 ( & V_73 -> V_5 ) ;
F_71 ( V_73 ) ;
}
}
static inline int F_126 ( struct V_266 * V_59 )
{
return V_59 -> V_6 != NULL ;
}
static int F_127 ( struct V_266 * V_59 )
{
if ( ! V_59 -> V_14 -> V_267 )
return - V_58 ;
V_59 -> V_6 = V_59 -> V_14 -> V_267 ;
V_59 -> V_6 -> V_59 = V_59 ;
return 0 ;
}
static void F_128 ( struct V_266 * V_59 )
{
if ( ! V_59 )
return;
if ( V_59 -> V_268 )
F_129 ( V_59 -> V_268 ) ;
if ( F_126 ( V_59 ) ) {
V_59 -> V_6 -> V_59 = NULL ;
V_59 -> V_6 = NULL ;
}
}
int F_130 ( struct V_13 * V_14 , struct V_269 * V_268 )
{
struct V_266 * V_59 ;
int V_24 = 0 ;
F_17 ( & V_14 -> V_25 ) ;
if ( V_192 [ V_14 -> V_56 ] . V_260 == 0 ) {
F_22 ( V_14 , L_105 ) ;
V_24 = - V_270 ;
goto V_108;
}
if ( V_192 [ V_14 -> V_56 ] . V_271 != V_268 -> V_272 ) {
F_22 ( V_14 , L_106 ) ;
V_24 = - V_58 ;
goto V_108;
}
if ( V_14 -> V_59 ) {
F_22 ( V_14 , L_107 ) ;
V_24 = - V_60 ;
goto V_108;
}
V_59 = F_2 ( sizeof( * V_59 ) , V_7 ) ;
if ( ! V_59 ) {
V_24 = - V_95 ;
goto V_108;
}
V_59 -> V_14 = V_14 ;
V_59 -> V_268 = V_268 ;
V_14 -> V_59 = V_59 ;
V_268 -> V_273 -> V_23 = V_59 ;
V_108:
F_19 ( & V_14 -> V_25 ) ;
return V_24 ;
}
int F_131 ( struct V_269 * V_268 )
{
struct V_266 * V_59 = V_268 -> V_273 -> V_23 ;
struct V_13 * V_14 = V_59 -> V_14 ;
F_17 ( & V_14 -> V_25 ) ;
F_128 ( V_59 ) ;
V_14 -> V_59 = NULL ;
F_4 ( V_59 -> V_274 ) ;
F_4 ( V_59 ) ;
F_19 ( & V_14 -> V_25 ) ;
return 0 ;
}
static int F_132 ( struct V_269 * V_268 ,
struct V_275 * V_276 )
{
struct V_266 * V_59 = V_268 -> V_273 -> V_23 ;
struct V_13 * V_14 = V_59 -> V_14 ;
const struct V_277 * V_278 ;
const struct V_279 * V_280 ;
int V_32 , V_281 ;
if ( V_276 -> V_267 . V_282 < V_283 ||
V_276 -> V_267 . V_282 > V_284 ||
V_276 -> V_267 . V_285 < V_286 ||
V_276 -> V_267 . V_285 > V_287 ||
V_276 -> V_267 . V_282 % V_288 ) {
F_22 ( V_14 , L_108 ,
V_276 -> V_267 . V_282 ,
V_276 -> V_267 . V_285 ) ;
return - V_58 ;
}
for ( V_32 = 0 ; V_32 < V_192 [ V_14 -> V_56 ] . V_260 ; V_32 ++ ) {
V_278 = & V_192 [ V_14 -> V_56 ] . V_278 [ V_32 ] ;
V_280 = & V_278 -> V_280 ;
if ( V_278 -> V_164 != V_276 -> V_28 . V_164 )
continue;
if ( V_268 -> V_272 == V_289 ) {
if ( V_280 -> V_290 < V_276 -> V_28 . V_291 )
continue;
} else {
if ( V_280 -> V_290 < V_276 -> V_28 . V_292 )
continue;
}
if ( ! ( V_280 -> V_293 & ( 1 << V_276 -> V_28 . V_294 ) ) )
continue;
for ( V_281 = 0 ; V_281 < V_280 -> V_295 ; ++ V_281 )
if ( V_280 -> V_296 [ V_281 ] == V_276 -> V_28 . V_297 )
return 0 ;
}
F_22 ( V_14 , L_109 ,
V_276 -> V_28 . V_164 , V_276 -> V_28 . V_292 , V_276 -> V_28 . V_291 ,
V_276 -> V_28 . V_297 , V_276 -> V_28 . V_294 ) ;
return - V_58 ;
}
static inline unsigned int F_133 ( struct V_266 * V_59 )
{
return V_59 -> V_102 . V_282 / V_288 ;
}
int F_134 ( struct V_269 * V_268 ,
struct V_275 * V_276 )
{
struct V_266 * V_59 = V_268 -> V_273 -> V_23 ;
unsigned int V_102 ;
int V_24 ;
V_24 = F_132 ( V_268 , V_276 ) ;
if ( V_24 )
return V_24 ;
V_59 -> V_102 = V_276 -> V_267 ;
F_41 ( V_59 -> V_14 , L_110 ,
V_59 -> V_102 . V_282 , V_59 -> V_102 . V_285 ) ;
V_102 = F_133 ( V_59 ) * sizeof( * V_59 -> V_274 ) ;
V_59 -> V_274 = F_23 ( V_102 , V_94 | V_7 ) ;
if ( ! V_59 -> V_274 )
return - V_95 ;
V_59 -> V_297 = V_276 -> V_28 . V_297 ;
return 0 ;
}
int F_135 ( struct V_269 * V_268 ,
struct V_298 * V_278 )
{
struct V_266 * V_59 = V_268 -> V_273 -> V_23 ;
int V_56 = V_59 -> V_14 -> V_56 ;
int V_32 ;
if ( V_192 [ V_56 ] . V_278 ) {
for ( V_32 = 0 ; V_32 < V_192 [ V_56 ] . V_260 ; V_32 ++ )
V_278 -> V_299 [ V_32 ] = V_192 [ V_56 ] . V_278 [ V_32 ] . V_164 ;
V_278 -> V_300 = V_32 ;
V_278 -> V_272 = V_192 [ V_56 ] . V_271 ;
V_278 -> V_301 = V_283 ;
V_278 -> V_302 = V_284 ;
V_278 -> V_303 = V_286 ;
V_278 -> V_304 = V_287 ;
}
return 0 ;
}
static int F_136 ( struct V_13 * V_14 , int V_170 ,
unsigned int V_305 ,
unsigned int V_306 , T_6 * V_98 )
{
struct V_61 const * V_63 = F_35 ( V_14 , V_170 ) ;
unsigned int V_32 , V_74 ;
int V_24 ;
if ( ! V_63 )
return - V_58 ;
V_74 = F_36 ( V_63 , V_305 ) ;
V_24 = F_40 ( V_14 -> V_67 , V_74 , V_98 ,
sizeof( * V_98 ) * V_306 ) ;
if ( V_24 < 0 )
return V_24 ;
for ( V_32 = 0 ; V_32 < V_306 ; ++ V_32 )
V_98 [ V_32 ] = F_89 ( V_98 [ V_32 ] ) & 0x00ffffffu ;
return 0 ;
}
static inline int F_137 ( struct V_13 * V_14 , int V_170 ,
unsigned int V_305 , T_6 * V_98 )
{
return F_136 ( V_14 , V_170 , V_305 , 1 , V_98 ) ;
}
static int F_138 ( struct V_13 * V_14 , int V_170 ,
unsigned int V_305 , T_6 V_98 )
{
struct V_61 const * V_63 = F_35 ( V_14 , V_170 ) ;
unsigned int V_74 ;
if ( ! V_63 )
return - V_58 ;
V_74 = F_36 ( V_63 , V_305 ) ;
V_98 = F_48 ( V_98 & 0x00ffffffu ) ;
return F_49 ( V_14 -> V_67 , V_74 , & V_98 , sizeof( V_98 ) ) ;
}
static inline int F_139 ( struct V_307 * V_6 ,
unsigned int V_308 , T_6 * V_98 )
{
return F_137 ( V_6 -> V_14 , V_10 ,
V_6 -> V_309 + V_308 , V_98 ) ;
}
static inline int F_140 ( struct V_307 * V_6 ,
unsigned int V_308 , T_6 V_98 )
{
return F_138 ( V_6 -> V_14 , V_10 ,
V_6 -> V_309 + V_308 , V_98 ) ;
}
static int F_141 ( struct V_307 * V_6 )
{
struct V_75 * V_76 ;
struct V_13 * V_14 = V_6 -> V_14 ;
T_6 V_310 , V_311 , V_195 ;
int V_32 , V_24 ;
V_76 = F_96 ( V_14 , V_10 , V_14 -> V_40 ) ;
V_310 = sizeof( struct V_312 ) / sizeof( T_8 ) ;
V_311 = V_76 -> V_65 + V_310 + F_142 ( V_195 ) ;
V_24 = F_137 ( V_14 , V_10 , V_311 , & V_195 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_195 != V_313 )
return - V_58 ;
V_311 = V_76 -> V_65 + V_310 + F_142 ( V_309 ) ;
for ( V_32 = 0 ; V_32 < 5 ; ++ V_32 ) {
V_24 = F_137 ( V_14 , V_10 , V_311 ,
& V_6 -> V_309 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_6 -> V_309 )
break;
F_50 ( 1000 , 2000 ) ;
}
if ( ! V_6 -> V_309 )
return - V_259 ;
F_41 ( V_14 , L_111 , V_6 -> V_309 ) ;
return 0 ;
}
static int F_143 ( struct V_307 * V_6 )
{
const struct V_277 * V_278 = V_192 [ V_6 -> V_14 -> V_56 ] . V_278 ;
struct V_314 * V_176 ;
T_6 V_64 = 0 ;
int V_32 , V_24 ;
for ( V_32 = 0 ; V_32 < V_278 -> V_315 ; ++ V_32 ) {
V_176 = & V_6 -> V_189 [ V_32 ] ;
V_176 -> V_64 = V_64 ;
V_176 -> V_170 = V_278 -> V_316 [ V_32 ] . V_170 ;
V_24 = F_139 ( V_6 , V_278 -> V_316 [ V_32 ] . V_317 ,
& V_176 -> V_318 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_139 ( V_6 , V_278 -> V_316 [ V_32 ] . V_319 ,
& V_64 ) ;
if ( V_24 < 0 )
return V_24 ;
V_176 -> V_320 = V_64 ;
F_41 ( V_6 -> V_14 ,
L_112 ,
V_32 , V_176 -> V_170 , V_176 -> V_318 ,
V_176 -> V_64 , V_176 -> V_320 ) ;
}
return 0 ;
}
static int F_119 ( struct V_13 * V_14 )
{
struct V_307 * V_6 ;
int V_24 ;
V_6 = F_2 ( sizeof( * V_6 ) , V_7 ) ;
if ( ! V_6 )
return - V_95 ;
V_6 -> V_14 = V_14 ;
V_6 -> V_321 = - 1 ;
V_6 -> V_322 = 0xFFFFFFFF ;
V_24 = F_141 ( V_6 ) ;
if ( V_24 < 0 ) {
F_22 ( V_14 , L_113 , V_24 ) ;
goto V_323;
}
V_6 -> V_189 = F_144 ( V_192 [ V_14 -> V_56 ] . V_278 -> V_315 ,
sizeof( * V_6 -> V_189 ) , V_7 ) ;
if ( ! V_6 -> V_189 ) {
V_24 = - V_95 ;
goto V_323;
}
V_24 = F_143 ( V_6 ) ;
if ( V_24 < 0 ) {
F_22 ( V_14 , L_114 , V_24 ) ;
goto V_324;
}
V_14 -> V_267 = V_6 ;
return 0 ;
V_324:
F_4 ( V_6 -> V_189 ) ;
V_323:
F_4 ( V_6 ) ;
return V_24 ;
}
static int F_121 ( struct V_13 * V_14 )
{
if ( V_14 -> V_267 ) {
F_128 ( V_14 -> V_267 -> V_59 ) ;
F_4 ( V_14 -> V_267 -> V_189 ) ;
F_4 ( V_14 -> V_267 ) ;
V_14 -> V_267 = NULL ;
}
return 0 ;
}
int F_145 ( struct V_269 * V_268 , int V_325 )
{
struct V_266 * V_59 = V_268 -> V_273 -> V_23 ;
struct V_13 * V_14 = V_59 -> V_14 ;
int V_24 = 0 ;
F_41 ( V_14 , L_115 , V_325 ) ;
F_17 ( & V_14 -> V_25 ) ;
switch ( V_325 ) {
case V_326 :
if ( F_126 ( V_59 ) )
break;
V_24 = F_127 ( V_59 ) ;
if ( V_24 < 0 ) {
F_22 ( V_14 , L_116 ,
V_24 ) ;
break;
}
V_24 = F_140 ( V_59 -> V_6 ,
F_146 ( V_327 ) ,
F_133 ( V_59 ) ) ;
if ( V_24 < 0 ) {
F_22 ( V_14 , L_117 ,
V_24 ) ;
break;
}
break;
case V_328 :
break;
default:
V_24 = - V_58 ;
break;
}
F_19 ( & V_14 -> V_25 ) ;
return V_24 ;
}
static inline int F_147 ( struct V_307 * V_6 )
{
int V_329 = V_192 [ V_6 -> V_14 -> V_56 ] . V_278 -> V_315 - 1 ;
return V_6 -> V_189 [ V_329 ] . V_320 ;
}
static int F_148 ( struct V_307 * V_6 )
{
T_6 V_330 , V_331 ;
int V_332 , V_321 , V_144 ;
int V_24 ;
if ( V_6 -> V_321 < 0 ) {
V_24 = F_139 ( V_6 ,
F_146 ( V_330 ) ,
& V_330 ) ;
if ( V_24 < 0 )
return V_24 ;
V_321 = F_149 ( V_330 , 23 ) ;
if ( V_321 < 0 ) {
F_41 ( V_6 -> V_14 , L_118 ) ;
return 0 ;
}
V_6 -> V_321 = V_321 ;
}
V_24 = F_139 ( V_6 , F_146 ( V_331 ) ,
& V_331 ) ;
if ( V_24 < 0 )
return V_24 ;
V_332 = F_149 ( V_331 , 23 ) ;
V_144 = V_332 - V_6 -> V_321 ;
if ( V_144 < 0 )
V_144 += F_147 ( V_6 ) ;
F_41 ( V_6 -> V_14 , L_119 ,
V_6 -> V_321 , V_332 , V_144 * V_288 ) ;
V_6 -> V_144 = V_144 ;
return 0 ;
}
static int F_150 ( struct V_307 * V_6 )
{
int V_24 ;
V_24 = F_139 ( V_6 , F_146 ( error ) , & V_6 -> error ) ;
if ( V_24 < 0 ) {
F_22 ( V_6 -> V_14 , L_120 , V_24 ) ;
return V_24 ;
}
if ( V_6 -> error != 0 ) {
F_22 ( V_6 -> V_14 , L_121 , V_6 -> error ) ;
return - V_259 ;
}
return 0 ;
}
int F_151 ( struct V_13 * V_14 )
{
struct V_307 * V_6 ;
struct V_266 * V_59 ;
int V_24 = 0 ;
F_17 ( & V_14 -> V_25 ) ;
V_6 = V_14 -> V_267 ;
V_59 = V_14 -> V_59 ;
if ( ! V_6 ) {
V_24 = - V_333 ;
goto V_108;
}
F_41 ( V_14 , L_122 ) ;
V_24 = F_150 ( V_6 ) ;
if ( V_24 < 0 )
goto V_334;
V_24 = F_139 ( V_6 , F_146 ( V_322 ) ,
& V_6 -> V_322 ) ;
if ( V_24 < 0 ) {
F_22 ( V_14 , L_123 , V_24 ) ;
goto V_108;
}
V_24 = F_148 ( V_6 ) ;
if ( V_24 < 0 ) {
F_22 ( V_14 , L_124 , V_24 ) ;
goto V_108;
}
if ( V_192 [ V_14 -> V_56 ] . V_335 && V_6 -> V_322 == 2 )
V_24 = V_336 ;
V_334:
if ( V_59 && V_59 -> V_268 )
F_129 ( V_59 -> V_268 ) ;
V_108:
F_19 ( & V_14 -> V_25 ) ;
return V_24 ;
}
static int F_152 ( struct V_307 * V_6 )
{
if ( V_6 -> V_322 & 0x01 )
return 0 ;
F_41 ( V_6 -> V_14 , L_125 ,
V_6 -> V_322 ) ;
V_6 -> V_322 |= 0x01 ;
return F_140 ( V_6 , F_146 ( V_337 ) ,
V_6 -> V_322 ) ;
}
int F_153 ( struct V_269 * V_268 ,
struct V_338 * V_339 )
{
struct V_266 * V_59 = V_268 -> V_273 -> V_23 ;
struct V_13 * V_14 = V_59 -> V_14 ;
struct V_307 * V_6 ;
int V_24 = 0 ;
F_41 ( V_14 , L_126 ) ;
F_17 ( & V_14 -> V_25 ) ;
V_6 = V_59 -> V_6 ;
if ( ! V_59 -> V_6 || V_59 -> V_6 -> error ) {
F_154 ( V_268 , V_340 ) ;
V_24 = - V_259 ;
goto V_108;
}
if ( V_6 -> V_144 < F_133 ( V_59 ) ) {
V_24 = F_148 ( V_6 ) ;
if ( V_24 < 0 ) {
F_22 ( V_14 , L_124 , V_24 ) ;
goto V_108;
}
if ( V_6 -> V_144 < F_133 ( V_59 ) ) {
V_24 = F_150 ( V_6 ) ;
if ( V_24 < 0 ) {
if ( V_59 -> V_6 -> error )
F_154 ( V_268 ,
V_340 ) ;
goto V_108;
}
V_24 = F_152 ( V_6 ) ;
if ( V_24 < 0 ) {
F_22 ( V_14 ,
L_127 ,
V_24 ) ;
goto V_108;
}
}
}
V_339 -> V_341 = V_59 -> V_341 ;
V_339 -> V_341 += V_6 -> V_144 * V_288 ;
V_339 -> V_342 = V_59 -> V_297 ;
V_108:
F_19 ( & V_14 -> V_25 ) ;
return V_24 ;
}
static int F_155 ( struct V_266 * V_59 , int V_343 )
{
struct V_307 * V_6 = V_59 -> V_6 ;
T_7 * V_344 = ( T_7 * ) V_59 -> V_274 ;
T_7 * V_345 = ( T_7 * ) V_59 -> V_274 ;
unsigned int V_346 ;
int V_170 , V_347 , V_348 ;
int V_32 , V_281 , V_24 ;
for ( V_32 = 0 ; V_32 < V_192 [ V_6 -> V_14 -> V_56 ] . V_278 -> V_315 ; ++ V_32 )
if ( V_6 -> V_321 < V_6 -> V_189 [ V_32 ] . V_320 )
break;
if ( V_32 == V_192 [ V_6 -> V_14 -> V_56 ] . V_278 -> V_315 )
return - V_58 ;
V_170 = V_6 -> V_189 [ V_32 ] . V_170 ;
V_346 = V_6 -> V_189 [ V_32 ] . V_318 +
( V_6 -> V_321 - V_6 -> V_189 [ V_32 ] . V_64 ) ;
V_348 = F_133 ( V_59 ) ;
V_347 = V_6 -> V_189 [ V_32 ] . V_320 - V_6 -> V_321 ;
if ( V_347 > V_343 )
V_347 = V_343 ;
if ( V_347 > V_6 -> V_144 )
V_347 = V_6 -> V_144 ;
if ( V_347 > V_348 )
V_347 = V_348 ;
if ( ! V_347 )
return 0 ;
V_24 = F_136 ( V_6 -> V_14 , V_170 , V_346 ,
V_347 , V_59 -> V_274 ) ;
if ( V_24 < 0 )
return V_24 ;
for ( V_32 = 0 ; V_32 < V_347 ; V_32 ++ ) {
for ( V_281 = 0 ; V_281 < V_288 ; V_281 ++ )
* V_345 ++ = * V_344 ++ ;
V_344 += sizeof( * ( V_59 -> V_274 ) ) - V_288 ;
}
V_6 -> V_321 += V_347 ;
if ( V_6 -> V_321 == F_147 ( V_6 ) )
V_6 -> V_321 = 0 ;
V_24 = F_140 ( V_6 , F_146 ( V_330 ) ,
V_6 -> V_321 ) ;
if ( V_24 < 0 )
return V_24 ;
V_6 -> V_144 -= V_347 ;
return V_347 ;
}
static int F_156 ( struct V_266 * V_59 ,
char T_3 * V_6 , T_1 V_21 )
{
struct V_13 * V_14 = V_59 -> V_14 ;
int V_349 = 0 ;
int V_347 , V_350 ;
F_41 ( V_14 , L_128 , V_21 ) ;
if ( ! V_59 -> V_6 || V_59 -> V_6 -> error ) {
F_154 ( V_59 -> V_268 , V_340 ) ;
return - V_259 ;
}
V_21 /= V_288 ;
do {
V_347 = F_155 ( V_59 , V_21 ) ;
if ( V_347 < 0 ) {
F_22 ( V_14 , L_129 , V_347 ) ;
return V_347 ;
}
V_350 = V_347 * V_288 ;
F_41 ( V_14 , L_130 , V_350 ) ;
if ( F_61 ( V_6 + V_349 , V_59 -> V_274 , V_350 ) ) {
F_22 ( V_14 , L_131 ,
V_349 , V_350 ) ;
return - V_103 ;
}
V_21 -= V_347 ;
V_349 += V_350 ;
} while ( V_347 > 0 && V_21 > 0 );
V_59 -> V_341 += V_349 ;
return V_349 ;
}
int F_157 ( struct V_269 * V_268 , char T_3 * V_6 ,
T_1 V_21 )
{
struct V_266 * V_59 = V_268 -> V_273 -> V_23 ;
struct V_13 * V_14 = V_59 -> V_14 ;
int V_24 ;
F_17 ( & V_14 -> V_25 ) ;
if ( V_268 -> V_272 == V_351 )
V_24 = F_156 ( V_59 , V_6 , V_21 ) ;
else
V_24 = - V_352 ;
F_19 ( & V_14 -> V_25 ) ;
return V_24 ;
}
