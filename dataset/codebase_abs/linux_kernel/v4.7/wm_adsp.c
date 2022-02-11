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
F_4 ( V_6 -> V_6 ) ;
F_10 ( V_6 ) ;
}
}
static void F_11 ( struct V_8 * V_9 , const char * V_10 )
{
char * V_11 = F_12 ( V_7 , L_1 , V_10 ) ;
F_10 ( V_9 -> V_12 ) ;
V_9 -> V_12 = V_11 ;
}
static void F_13 ( struct V_8 * V_9 , const char * V_10 )
{
char * V_11 = F_12 ( V_7 , L_1 , V_10 ) ;
F_10 ( V_9 -> V_13 ) ;
V_9 -> V_13 = V_11 ;
}
static void F_14 ( struct V_8 * V_9 )
{
F_10 ( V_9 -> V_12 ) ;
F_10 ( V_9 -> V_13 ) ;
V_9 -> V_12 = NULL ;
V_9 -> V_13 = NULL ;
}
static T_2 F_15 ( struct V_14 * V_14 ,
char T_3 * V_15 ,
T_1 V_16 , T_4 * V_17 )
{
struct V_8 * V_9 = V_14 -> V_18 ;
T_2 V_19 ;
F_16 ( & V_9 -> V_20 ) ;
if ( ! V_9 -> V_12 || ! V_9 -> V_21 )
V_19 = 0 ;
else
V_19 = F_17 ( V_15 , V_16 , V_17 ,
V_9 -> V_12 ,
strlen ( V_9 -> V_12 ) ) ;
F_18 ( & V_9 -> V_20 ) ;
return V_19 ;
}
static T_2 F_19 ( struct V_14 * V_14 ,
char T_3 * V_15 ,
T_1 V_16 , T_4 * V_17 )
{
struct V_8 * V_9 = V_14 -> V_18 ;
T_2 V_19 ;
F_16 ( & V_9 -> V_20 ) ;
if ( ! V_9 -> V_13 || ! V_9 -> V_21 )
V_19 = 0 ;
else
V_19 = F_17 ( V_15 , V_16 , V_17 ,
V_9 -> V_13 ,
strlen ( V_9 -> V_13 ) ) ;
F_18 ( & V_9 -> V_20 ) ;
return V_19 ;
}
static void F_20 ( struct V_8 * V_9 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = NULL ;
char * V_26 ;
int V_27 ;
if ( ! V_23 -> V_28 . V_29 ) {
F_21 ( V_9 , L_2 ) ;
goto V_30;
}
V_26 = F_22 ( V_31 , V_7 ) ;
if ( ! V_26 )
goto V_30;
snprintf ( V_26 , V_31 , L_3 , V_9 -> V_32 ) ;
V_25 = F_23 ( V_26 , V_23 -> V_28 . V_29 ) ;
F_10 ( V_26 ) ;
if ( ! V_25 )
goto V_30;
if ( ! F_24 ( L_4 , V_33 , V_25 , & V_9 -> V_21 ) )
goto V_30;
if ( ! F_25 ( L_5 , V_33 , V_25 , & V_9 -> V_34 ) )
goto V_30;
if ( ! F_25 ( L_6 , V_33 , V_25 ,
& V_9 -> V_35 ) )
goto V_30;
for ( V_27 = 0 ; V_27 < F_26 ( V_36 ) ; ++ V_27 ) {
if ( ! F_27 ( V_36 [ V_27 ] . V_37 ,
V_33 , V_25 , V_9 ,
& V_36 [ V_27 ] . V_38 ) )
goto V_30;
}
V_9 -> V_29 = V_25 ;
return;
V_30:
F_28 ( V_25 ) ;
F_21 ( V_9 , L_7 ) ;
}
static void F_29 ( struct V_8 * V_9 )
{
F_14 ( V_9 ) ;
F_28 ( V_9 -> V_29 ) ;
}
static inline void F_20 ( struct V_8 * V_9 ,
struct V_22 * V_23 )
{
}
static inline void F_29 ( struct V_8 * V_9 )
{
}
static inline void F_11 ( struct V_8 * V_9 ,
const char * V_10 )
{
}
static inline void F_13 ( struct V_8 * V_9 ,
const char * V_10 )
{
}
static inline void F_14 ( struct V_8 * V_9 )
{
}
static int F_30 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_22 * V_23 = F_31 ( V_40 ) ;
struct V_43 * V_44 = (struct V_43 * ) V_40 -> V_45 ;
struct V_8 * V_9 = F_32 ( V_23 ) ;
V_42 -> V_46 . V_47 . V_48 [ 0 ] = V_9 [ V_44 -> V_49 ] . V_50 ;
return 0 ;
}
static int F_33 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_22 * V_23 = F_31 ( V_40 ) ;
struct V_43 * V_44 = (struct V_43 * ) V_40 -> V_45 ;
struct V_8 * V_9 = F_32 ( V_23 ) ;
int V_19 = 0 ;
if ( V_42 -> V_46 . V_47 . V_48 [ 0 ] == V_9 [ V_44 -> V_49 ] . V_50 )
return 0 ;
if ( V_42 -> V_46 . V_47 . V_48 [ 0 ] >= V_51 )
return - V_52 ;
F_16 ( & V_9 [ V_44 -> V_49 ] . V_20 ) ;
if ( V_9 [ V_44 -> V_49 ] . V_21 || V_9 [ V_44 -> V_49 ] . V_53 )
V_19 = - V_54 ;
else
V_9 [ V_44 -> V_49 ] . V_50 = V_42 -> V_46 . V_47 . V_48 [ 0 ] ;
F_18 ( & V_9 [ V_44 -> V_49 ] . V_20 ) ;
return V_19 ;
}
static struct V_55 const * F_34 ( struct V_8 * V_9 ,
int type )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_9 -> V_56 ; V_27 ++ )
if ( V_9 -> V_57 [ V_27 ] . type == type )
return & V_9 -> V_57 [ V_27 ] ;
return NULL ;
}
static unsigned int F_35 ( struct V_55 const * V_57 ,
unsigned int V_58 )
{
if ( F_36 ( ! V_57 ) )
return V_58 ;
switch ( V_57 -> type ) {
case V_59 :
return V_57 -> V_60 + ( V_58 * 3 ) ;
case V_61 :
return V_57 -> V_60 + ( V_58 * 2 ) ;
case V_62 :
return V_57 -> V_60 + ( V_58 * 2 ) ;
case V_63 :
return V_57 -> V_60 + ( V_58 * 2 ) ;
case V_64 :
return V_57 -> V_60 + ( V_58 * 2 ) ;
default:
F_37 ( 1 , L_8 ) ;
return V_58 ;
}
}
static void F_38 ( struct V_8 * V_9 )
{
T_5 V_65 [ 4 ] ;
int V_19 ;
V_19 = F_39 ( V_9 -> V_66 , V_9 -> V_60 + V_67 ,
V_65 , sizeof( V_65 ) ) ;
if ( V_19 ) {
F_21 ( V_9 , L_9 , V_19 ) ;
return;
}
F_40 ( V_9 , L_10 ,
F_41 ( V_65 [ 0 ] ) ,
F_41 ( V_65 [ 1 ] ) ,
F_41 ( V_65 [ 2 ] ) ,
F_41 ( V_65 [ 3 ] ) ) ;
}
static inline struct V_68 * F_42 ( struct V_69 * V_70 )
{
return F_43 ( V_70 , struct V_68 , V_71 ) ;
}
static int F_44 ( struct V_39 * V_72 ,
struct V_73 * V_74 )
{
struct V_69 * V_71 =
(struct V_69 * ) V_72 -> V_45 ;
struct V_68 * V_75 = F_42 ( V_71 ) ;
V_74 -> type = V_76 ;
V_74 -> V_16 = V_75 -> V_3 ;
return 0 ;
}
static int F_45 ( struct V_68 * V_75 ,
const void * V_6 , T_1 V_3 )
{
struct V_77 * V_78 = & V_75 -> V_78 ;
const struct V_55 * V_57 ;
struct V_8 * V_9 = V_75 -> V_9 ;
void * V_65 ;
int V_19 ;
unsigned int V_79 ;
V_57 = F_34 ( V_9 , V_78 -> type ) ;
if ( ! V_57 ) {
F_21 ( V_9 , L_11 ,
V_78 -> type ) ;
return - V_52 ;
}
V_79 = V_75 -> V_78 . V_60 + V_75 -> V_58 ;
V_79 = F_35 ( V_57 , V_79 ) ;
V_65 = F_46 ( V_6 , V_3 , V_7 | V_80 ) ;
if ( ! V_65 )
return - V_81 ;
V_19 = F_47 ( V_9 -> V_66 , V_79 , V_65 ,
V_3 ) ;
if ( V_19 ) {
F_21 ( V_9 , L_12 ,
V_3 , V_79 , V_19 ) ;
F_10 ( V_65 ) ;
return V_19 ;
}
F_40 ( V_9 , L_13 , V_3 , V_79 ) ;
F_10 ( V_65 ) ;
return 0 ;
}
static int F_48 ( struct V_39 * V_72 ,
struct V_41 * V_42 )
{
struct V_69 * V_71 =
(struct V_69 * ) V_72 -> V_45 ;
struct V_68 * V_75 = F_42 ( V_71 ) ;
char * V_82 = V_42 -> V_46 . V_83 . V_84 ;
int V_19 = 0 ;
F_16 ( & V_75 -> V_9 -> V_20 ) ;
memcpy ( V_75 -> V_85 , V_82 , V_75 -> V_3 ) ;
V_75 -> V_86 = 1 ;
if ( V_75 -> V_87 )
V_19 = F_45 ( V_75 , V_82 , V_75 -> V_3 ) ;
F_18 ( & V_75 -> V_9 -> V_20 ) ;
return V_19 ;
}
static int F_49 ( struct V_39 * V_72 ,
const unsigned int T_3 * V_83 , unsigned int V_88 )
{
struct V_69 * V_71 =
(struct V_69 * ) V_72 -> V_45 ;
struct V_68 * V_75 = F_42 ( V_71 ) ;
int V_19 = 0 ;
F_16 ( & V_75 -> V_9 -> V_20 ) ;
if ( F_50 ( V_75 -> V_85 , V_83 , V_88 ) ) {
V_19 = - V_89 ;
} else {
V_75 -> V_86 = 1 ;
if ( V_75 -> V_87 )
V_19 = F_45 ( V_75 , V_75 -> V_85 , V_88 ) ;
}
F_18 ( & V_75 -> V_9 -> V_20 ) ;
return V_19 ;
}
static int F_51 ( struct V_68 * V_75 ,
void * V_6 , T_1 V_3 )
{
struct V_77 * V_78 = & V_75 -> V_78 ;
const struct V_55 * V_57 ;
struct V_8 * V_9 = V_75 -> V_9 ;
void * V_65 ;
int V_19 ;
unsigned int V_79 ;
V_57 = F_34 ( V_9 , V_78 -> type ) ;
if ( ! V_57 ) {
F_21 ( V_9 , L_11 ,
V_78 -> type ) ;
return - V_52 ;
}
V_79 = V_75 -> V_78 . V_60 + V_75 -> V_58 ;
V_79 = F_35 ( V_57 , V_79 ) ;
V_65 = F_22 ( V_3 , V_7 | V_80 ) ;
if ( ! V_65 )
return - V_81 ;
V_19 = F_39 ( V_9 -> V_66 , V_79 , V_65 , V_3 ) ;
if ( V_19 ) {
F_21 ( V_9 , L_14 ,
V_3 , V_79 , V_19 ) ;
F_10 ( V_65 ) ;
return V_19 ;
}
F_40 ( V_9 , L_15 , V_3 , V_79 ) ;
memcpy ( V_6 , V_65 , V_3 ) ;
F_10 ( V_65 ) ;
return 0 ;
}
static int F_52 ( struct V_39 * V_72 ,
struct V_41 * V_42 )
{
struct V_69 * V_71 =
(struct V_69 * ) V_72 -> V_45 ;
struct V_68 * V_75 = F_42 ( V_71 ) ;
char * V_82 = V_42 -> V_46 . V_83 . V_84 ;
int V_19 = 0 ;
F_16 ( & V_75 -> V_9 -> V_20 ) ;
if ( V_75 -> V_90 & V_91 ) {
if ( V_75 -> V_87 )
V_19 = F_51 ( V_75 , V_82 , V_75 -> V_3 ) ;
else
V_19 = - V_92 ;
} else {
if ( ! V_75 -> V_90 && V_75 -> V_87 )
V_19 = F_51 ( V_75 , V_75 -> V_85 , V_75 -> V_3 ) ;
memcpy ( V_82 , V_75 -> V_85 , V_75 -> V_3 ) ;
}
F_18 ( & V_75 -> V_9 -> V_20 ) ;
return V_19 ;
}
static int F_53 ( struct V_39 * V_72 ,
unsigned int T_3 * V_83 , unsigned int V_88 )
{
struct V_69 * V_71 =
(struct V_69 * ) V_72 -> V_45 ;
struct V_68 * V_75 = F_42 ( V_71 ) ;
int V_19 = 0 ;
F_16 ( & V_75 -> V_9 -> V_20 ) ;
if ( V_75 -> V_90 & V_91 ) {
if ( V_75 -> V_87 )
V_19 = F_51 ( V_75 , V_75 -> V_85 , V_88 ) ;
else
V_19 = - V_92 ;
} else {
if ( ! V_75 -> V_90 && V_75 -> V_87 )
V_19 = F_51 ( V_75 , V_75 -> V_85 , V_88 ) ;
}
if ( ! V_19 && F_54 ( V_83 , V_75 -> V_85 , V_88 ) )
V_19 = - V_89 ;
F_18 ( & V_75 -> V_9 -> V_20 ) ;
return V_19 ;
}
static unsigned int F_55 ( unsigned int V_93 , unsigned int V_3 )
{
unsigned int V_94 , V_95 , V_96 , V_97 ;
if ( V_3 > V_98 ) {
V_95 = V_99 ;
V_96 = V_100 ;
V_97 = V_101 ;
V_94 = V_102 ;
} else {
V_95 = V_103 ;
V_96 = V_104 ;
V_97 = V_101 ;
V_94 = 0 ;
}
if ( V_93 ) {
if ( V_93 & V_105 )
V_94 |= V_95 ;
if ( V_93 & V_106 )
V_94 |= V_96 ;
if ( V_93 & V_91 )
V_94 |= V_97 ;
} else {
V_94 |= V_95 | V_96 | V_97 ;
}
return V_94 ;
}
static int F_56 ( struct V_8 * V_9 , struct V_68 * V_75 )
{
struct V_107 * V_40 ;
int V_19 ;
if ( ! V_75 || ! V_75 -> V_37 )
return - V_52 ;
V_40 = F_2 ( sizeof( * V_40 ) , V_7 ) ;
if ( ! V_40 )
return - V_81 ;
V_40 -> V_108 = V_109 ;
V_40 -> V_37 = V_75 -> V_37 ;
V_40 -> V_110 = F_44 ;
V_40 -> V_111 = F_52 ;
V_40 -> V_112 = F_48 ;
V_40 -> V_108 = V_109 ;
V_40 -> V_113 . V_114 = V_115 ;
V_40 -> V_45 = ( unsigned long ) & V_75 -> V_71 ;
V_75 -> V_71 . V_116 = V_75 -> V_3 ;
V_75 -> V_71 . V_111 = F_53 ;
V_75 -> V_71 . V_112 = F_49 ;
V_40 -> V_117 = F_55 ( V_75 -> V_90 , V_75 -> V_3 ) ;
V_19 = F_57 ( V_9 -> V_118 , V_40 , 1 ) ;
if ( V_19 < 0 )
goto V_119;
F_10 ( V_40 ) ;
V_75 -> V_40 = F_58 ( V_9 -> V_118 , V_75 -> V_37 ) ;
return 0 ;
V_119:
F_10 ( V_40 ) ;
return V_19 ;
}
static int F_59 ( struct V_8 * V_9 )
{
struct V_68 * V_75 ;
int V_19 ;
F_60 (ctl, &dsp->ctl_list, list) {
if ( ! V_75 -> V_87 || V_75 -> V_86 )
continue;
if ( V_75 -> V_90 & V_91 )
continue;
V_19 = F_51 ( V_75 , V_75 -> V_85 , V_75 -> V_3 ) ;
if ( V_19 < 0 )
return V_19 ;
}
return 0 ;
}
static int F_61 ( struct V_8 * V_9 )
{
struct V_68 * V_75 ;
int V_19 ;
F_60 (ctl, &dsp->ctl_list, list) {
if ( ! V_75 -> V_87 )
continue;
if ( V_75 -> V_86 && ! ( V_75 -> V_90 & V_91 ) ) {
V_19 = F_45 ( V_75 , V_75 -> V_85 , V_75 -> V_3 ) ;
if ( V_19 < 0 )
return V_19 ;
}
}
return 0 ;
}
static void F_62 ( struct V_120 * V_121 )
{
struct V_122 * V_123 = F_43 ( V_121 ,
struct V_122 ,
V_121 ) ;
F_56 ( V_123 -> V_9 , V_123 -> V_75 ) ;
F_10 ( V_123 ) ;
}
static void F_63 ( struct V_68 * V_75 )
{
F_10 ( V_75 -> V_85 ) ;
F_10 ( V_75 -> V_37 ) ;
F_10 ( V_75 ) ;
}
static int F_64 ( struct V_8 * V_9 ,
const struct V_77 * V_78 ,
unsigned int V_58 , unsigned int V_3 ,
const char * V_124 , unsigned int V_125 ,
unsigned int V_90 )
{
struct V_68 * V_75 ;
struct V_122 * V_123 ;
char V_37 [ V_126 ] ;
char * V_127 ;
int V_19 ;
if ( V_90 & V_128 )
return 0 ;
switch ( V_78 -> type ) {
case V_59 :
V_127 = L_16 ;
break;
case V_61 :
V_127 = L_17 ;
break;
case V_62 :
V_127 = L_18 ;
break;
case V_63 :
V_127 = L_19 ;
break;
case V_64 :
V_127 = L_20 ;
break;
default:
F_21 ( V_9 , L_21 , V_78 -> type ) ;
return - V_52 ;
}
switch ( V_9 -> V_129 ) {
case 0 :
case 1 :
snprintf ( V_37 , V_126 , L_22 ,
V_9 -> V_32 , V_127 , V_78 -> V_130 ) ;
break;
default:
V_19 = snprintf ( V_37 , V_126 ,
L_23 , V_9 -> V_32 , * V_127 ,
V_131 [ V_9 -> V_50 ] , V_78 -> V_130 ) ;
if ( V_124 ) {
int V_132 = V_126 - V_19 - 2 ;
int V_133 = 0 ;
if ( V_125 > V_132 )
V_133 = V_125 - V_132 ;
snprintf ( V_37 + V_19 ,
V_126 - V_19 , L_24 ,
V_125 - V_133 , V_124 + V_133 ) ;
}
break;
}
F_60 (ctl, &dsp->ctl_list, list) {
if ( ! strcmp ( V_75 -> V_37 , V_37 ) ) {
if ( ! V_75 -> V_87 )
V_75 -> V_87 = 1 ;
return 0 ;
}
}
V_75 = F_2 ( sizeof( * V_75 ) , V_7 ) ;
if ( ! V_75 )
return - V_81 ;
V_75 -> V_134 = V_131 [ V_9 -> V_50 ] ;
V_75 -> V_78 = * V_78 ;
V_75 -> V_37 = F_46 ( V_37 , strlen ( V_37 ) + 1 , V_7 ) ;
if ( ! V_75 -> V_37 ) {
V_19 = - V_81 ;
goto V_135;
}
V_75 -> V_87 = 1 ;
V_75 -> V_86 = 0 ;
V_75 -> V_136 . V_137 = F_52 ;
V_75 -> V_136 . V_138 = F_48 ;
V_75 -> V_9 = V_9 ;
V_75 -> V_90 = V_90 ;
V_75 -> V_58 = V_58 ;
V_75 -> V_3 = V_3 ;
V_75 -> V_85 = F_2 ( V_75 -> V_3 , V_7 ) ;
if ( ! V_75 -> V_85 ) {
V_19 = - V_81 ;
goto V_139;
}
F_65 ( & V_75 -> V_5 , & V_9 -> V_140 ) ;
V_123 = F_2 ( sizeof( * V_123 ) , V_7 ) ;
if ( ! V_123 ) {
V_19 = - V_81 ;
goto V_141;
}
V_123 -> V_9 = V_9 ;
V_123 -> V_75 = V_75 ;
F_66 ( & V_123 -> V_121 , F_62 ) ;
F_67 ( & V_123 -> V_121 ) ;
return 0 ;
V_141:
F_10 ( V_75 -> V_85 ) ;
V_139:
F_10 ( V_75 -> V_37 ) ;
V_135:
F_10 ( V_75 ) ;
return V_19 ;
}
static int F_68 ( int V_83 , const T_6 * * V_142 , const T_6 * * V_143 )
{
int V_144 ;
switch ( V_83 ) {
case 1 :
V_144 = * * V_142 ;
break;
case 2 :
V_144 = F_69 ( * ( ( V_145 * ) * V_142 ) ) ;
break;
default:
return 0 ;
}
if ( V_143 )
* V_143 = * V_142 + V_83 ;
* V_142 += ( ( V_144 + V_83 ) + 3 ) & ~ 0x03 ;
return V_144 ;
}
static int F_70 ( int V_83 , const T_6 * * V_142 )
{
int V_146 = 0 ;
switch ( V_83 ) {
case 2 :
V_146 = F_69 ( * ( ( V_145 * ) * V_142 ) ) ;
break;
case 4 :
V_146 = F_71 ( * ( ( V_147 * ) * V_142 ) ) ;
break;
default:
break;
}
* V_142 += V_83 ;
return V_146 ;
}
static inline void F_72 ( struct V_8 * V_9 , const T_6 * * V_84 ,
struct V_148 * V_149 )
{
const struct V_150 * V_151 ;
switch ( V_9 -> V_129 ) {
case 0 :
case 1 :
V_151 = ( const struct V_150 * ) * V_84 ;
* V_84 = V_151 -> V_84 ;
V_149 -> V_152 = F_71 ( V_151 -> V_152 ) ;
V_149 -> V_37 = V_151 -> V_37 ;
V_149 -> V_153 = strlen ( V_151 -> V_37 ) ;
V_149 -> V_154 = F_71 ( V_151 -> V_154 ) ;
break;
default:
V_149 -> V_152 = F_70 ( sizeof( V_151 -> V_152 ) , V_84 ) ;
V_149 -> V_153 = F_68 ( sizeof( T_6 ) , V_84 ,
& V_149 -> V_37 ) ;
F_68 ( sizeof( T_5 ) , V_84 , NULL ) ;
V_149 -> V_154 = F_70 ( sizeof( V_151 -> V_154 ) , V_84 ) ;
break;
}
F_40 ( V_9 , L_25 , V_149 -> V_152 ) ;
F_40 ( V_9 , L_26 , V_149 -> V_153 , V_149 -> V_37 ) ;
F_40 ( V_9 , L_27 , V_149 -> V_154 ) ;
}
static inline void F_73 ( struct V_8 * V_9 , const T_6 * * V_84 ,
struct V_155 * V_149 )
{
const struct V_156 * V_151 ;
const T_6 * V_11 ;
int V_144 ;
switch ( V_9 -> V_129 ) {
case 0 :
case 1 :
V_151 = ( const struct V_156 * ) * V_84 ;
* V_84 = * V_84 + sizeof( V_151 -> V_157 ) + F_71 ( V_151 -> V_157 . V_88 ) ;
V_149 -> V_58 = F_69 ( V_151 -> V_157 . V_58 ) ;
V_149 -> V_158 = F_69 ( V_151 -> V_157 . type ) ;
V_149 -> V_37 = V_151 -> V_37 ;
V_149 -> V_153 = strlen ( V_151 -> V_37 ) ;
V_149 -> V_159 = F_69 ( V_151 -> V_159 ) ;
V_149 -> V_90 = F_69 ( V_151 -> V_90 ) ;
V_149 -> V_3 = F_71 ( V_151 -> V_3 ) ;
break;
default:
V_11 = * V_84 ;
V_149 -> V_58 = F_70 ( sizeof( V_151 -> V_157 . V_58 ) , & V_11 ) ;
V_149 -> V_158 = F_70 ( sizeof( V_151 -> V_157 . type ) , & V_11 ) ;
V_144 = F_70 ( sizeof( V_151 -> V_157 . V_88 ) , & V_11 ) ;
V_149 -> V_153 = F_68 ( sizeof( T_6 ) , & V_11 ,
& V_149 -> V_37 ) ;
F_68 ( sizeof( T_6 ) , & V_11 , NULL ) ;
F_68 ( sizeof( T_5 ) , & V_11 , NULL ) ;
V_149 -> V_159 = F_70 ( sizeof( V_151 -> V_159 ) , & V_11 ) ;
V_149 -> V_90 = F_70 ( sizeof( V_151 -> V_90 ) , & V_11 ) ;
V_149 -> V_3 = F_70 ( sizeof( V_151 -> V_3 ) , & V_11 ) ;
* V_84 = * V_84 + sizeof( V_151 -> V_157 ) + V_144 ;
break;
}
F_40 ( V_9 , L_28 , V_149 -> V_158 ) ;
F_40 ( V_9 , L_29 , V_149 -> V_58 ) ;
F_40 ( V_9 , L_30 , V_149 -> V_153 , V_149 -> V_37 ) ;
F_40 ( V_9 , L_31 , V_149 -> V_90 ) ;
F_40 ( V_9 , L_32 , V_149 -> V_159 ) ;
F_40 ( V_9 , L_33 , V_149 -> V_3 ) ;
}
static int F_74 ( struct V_8 * V_9 ,
const struct V_160 * V_161 )
{
struct V_77 V_78 = {} ;
struct V_148 V_162 ;
struct V_155 V_163 ;
const T_6 * V_84 = V_161 -> V_84 ;
int V_27 , V_19 ;
F_72 ( V_9 , & V_84 , & V_162 ) ;
for ( V_27 = 0 ; V_27 < V_162 . V_154 ; V_27 ++ ) {
F_73 ( V_9 , & V_84 , & V_163 ) ;
switch ( V_163 . V_159 ) {
case V_76 :
break;
default:
F_21 ( V_9 , L_34 ,
V_163 . V_159 ) ;
return - V_52 ;
}
V_78 . type = V_163 . V_158 ;
V_78 . V_130 = V_162 . V_152 ;
V_19 = F_64 ( V_9 , & V_78 ,
V_163 . V_58 ,
V_163 . V_3 ,
V_163 . V_37 ,
V_163 . V_153 ,
V_163 . V_90 ) ;
if ( V_19 < 0 )
F_21 ( V_9 , L_35 ,
V_163 . V_153 , V_163 . V_37 , V_19 ) ;
}
return 0 ;
}
static int F_75 ( struct V_8 * V_9 )
{
F_76 ( V_164 ) ;
const struct V_165 * V_165 ;
struct V_66 * V_66 = V_9 -> V_66 ;
unsigned int V_142 = 0 ;
const struct V_166 * V_167 ;
const struct V_168 * V_169 ;
const struct V_170 * V_171 ;
const struct V_172 * V_173 ;
const struct V_160 * V_161 ;
const struct V_55 * V_57 ;
const char * V_127 ;
char * V_14 , * V_174 ;
struct V_1 * V_6 ;
unsigned int V_79 ;
int V_175 = 0 ;
int V_19 , V_58 , type , V_176 ;
V_14 = F_2 ( V_31 , V_7 ) ;
if ( V_14 == NULL )
return - V_81 ;
snprintf ( V_14 , V_31 , L_36 , V_9 -> V_177 , V_9 -> V_32 ,
V_178 [ V_9 -> V_50 ] . V_14 ) ;
V_14 [ V_31 - 1 ] = '\0' ;
V_19 = F_77 ( & V_165 , V_14 , V_9 -> V_179 ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_37 , V_14 ) ;
goto V_94;
}
V_19 = - V_52 ;
V_142 = sizeof( * V_167 ) + sizeof( * V_169 ) + sizeof( * V_173 ) ;
if ( V_142 >= V_165 -> V_88 ) {
F_21 ( V_9 , L_38 ,
V_14 , V_165 -> V_88 ) ;
goto V_180;
}
V_167 = ( void * ) & V_165 -> V_84 [ 0 ] ;
if ( memcmp ( & V_167 -> V_181 [ 0 ] , L_39 , 4 ) != 0 ) {
F_21 ( V_9 , L_40 , V_14 ) ;
goto V_180;
}
switch ( V_167 -> V_182 ) {
case 0 :
F_78 ( V_9 , L_41 ,
V_14 , V_167 -> V_182 ) ;
break;
case 1 :
case 2 :
break;
default:
F_21 ( V_9 , L_42 ,
V_14 , V_167 -> V_182 ) ;
goto V_180;
}
F_79 ( V_9 , L_43 , V_167 -> V_182 ) ;
V_9 -> V_129 = V_167 -> V_182 ;
if ( V_167 -> V_183 != V_9 -> type ) {
F_21 ( V_9 , L_44 ,
V_14 , V_167 -> V_183 , V_9 -> type ) ;
goto V_180;
}
switch ( V_9 -> type ) {
case V_184 :
V_142 = sizeof( * V_167 ) + sizeof( * V_169 ) + sizeof( * V_173 ) ;
V_169 = ( void * ) & ( V_167 [ 1 ] ) ;
V_173 = ( void * ) & ( V_169 [ 1 ] ) ;
V_176 = sizeof( * V_169 ) ;
F_40 ( V_9 , L_45 ,
V_14 , F_71 ( V_169 -> V_185 ) ,
F_71 ( V_169 -> V_186 ) ,
F_71 ( V_169 -> V_187 ) ) ;
break;
case V_188 :
V_142 = sizeof( * V_167 ) + sizeof( * V_171 ) + sizeof( * V_173 ) ;
V_171 = ( void * ) & ( V_167 [ 1 ] ) ;
V_173 = ( void * ) & ( V_171 [ 1 ] ) ;
V_176 = sizeof( * V_171 ) ;
F_40 ( V_9 , L_46 ,
V_14 , F_71 ( V_171 -> V_189 ) ,
F_71 ( V_171 -> V_190 ) ,
F_71 ( V_171 -> V_186 ) ,
F_71 ( V_171 -> V_187 ) ) ;
break;
default:
F_37 ( 1 , L_47 ) ;
goto V_180;
}
if ( F_71 ( V_167 -> V_3 ) != sizeof( * V_167 ) +
V_176 + sizeof( * V_173 ) ) {
F_21 ( V_9 , L_48 ,
V_14 , F_71 ( V_167 -> V_3 ) ) ;
goto V_180;
}
F_40 ( V_9 , L_49 , V_14 ,
F_80 ( V_173 -> V_191 ) ) ;
while ( V_142 < V_165 -> V_88 &&
V_142 - V_165 -> V_88 > sizeof( * V_161 ) ) {
V_161 = ( void * ) & ( V_165 -> V_84 [ V_142 ] ) ;
V_127 = L_50 ;
V_79 = 0 ;
V_174 = NULL ;
V_58 = F_71 ( V_161 -> V_58 ) & 0xffffff ;
type = F_81 ( V_161 -> type ) & 0xff ;
V_57 = F_34 ( V_9 , type ) ;
switch ( type ) {
case V_192 :
V_127 = L_51 ;
V_174 = F_2 ( F_71 ( V_161 -> V_3 ) + 1 ,
V_7 ) ;
break;
case V_193 :
V_127 = L_52 ;
V_19 = F_74 ( V_9 , V_161 ) ;
if ( V_19 != 0 )
goto V_180;
break;
case V_194 :
V_127 = L_53 ;
V_174 = F_2 ( F_71 ( V_161 -> V_3 ) + 1 ,
V_7 ) ;
break;
case V_195 :
V_127 = L_54 ;
V_79 = V_58 ;
break;
case V_59 :
V_127 = L_16 ;
V_79 = F_35 ( V_57 , V_58 ) ;
break;
case V_61 :
V_127 = L_17 ;
V_79 = F_35 ( V_57 , V_58 ) ;
break;
case V_62 :
V_127 = L_18 ;
V_79 = F_35 ( V_57 , V_58 ) ;
break;
case V_63 :
V_127 = L_19 ;
V_79 = F_35 ( V_57 , V_58 ) ;
break;
case V_64 :
V_127 = L_20 ;
V_79 = F_35 ( V_57 , V_58 ) ;
break;
default:
F_78 ( V_9 ,
L_55 ,
V_14 , V_175 , type , V_142 , V_142 ) ;
break;
}
F_40 ( V_9 , L_56 , V_14 ,
V_175 , F_71 ( V_161 -> V_3 ) , V_58 ,
V_127 ) ;
if ( V_174 ) {
memcpy ( V_174 , V_161 -> V_84 , F_71 ( V_161 -> V_3 ) ) ;
F_79 ( V_9 , L_57 , V_14 , V_174 ) ;
F_10 ( V_174 ) ;
}
if ( V_79 ) {
V_6 = F_1 ( V_161 -> V_84 ,
F_71 ( V_161 -> V_3 ) ,
& V_164 ) ;
if ( ! V_6 ) {
F_21 ( V_9 , L_58 ) ;
V_19 = - V_81 ;
goto V_180;
}
V_19 = F_82 ( V_66 , V_79 , V_6 -> V_6 ,
F_71 ( V_161 -> V_3 ) ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 ,
L_59 ,
V_14 , V_175 ,
F_71 ( V_161 -> V_3 ) , V_58 ,
V_127 , V_19 ) ;
goto V_180;
}
}
V_142 += F_71 ( V_161 -> V_3 ) + sizeof( * V_161 ) ;
V_175 ++ ;
}
V_19 = F_83 ( V_66 ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_60 , V_19 ) ;
goto V_180;
}
if ( V_142 > V_165 -> V_88 )
F_78 ( V_9 , L_61 ,
V_14 , V_175 , V_142 - V_165 -> V_88 ) ;
F_11 ( V_9 , V_14 ) ;
V_180:
F_83 ( V_66 ) ;
F_6 ( & V_164 ) ;
F_84 ( V_165 ) ;
V_94:
F_10 ( V_14 ) ;
return V_19 ;
}
static void F_85 ( struct V_8 * V_9 ,
const struct V_77 * V_78 )
{
struct V_68 * V_75 ;
F_60 (ctl, &dsp->ctl_list, list) {
if ( V_75 -> V_134 == V_131 [ V_9 -> V_50 ] &&
V_78 -> V_130 == V_75 -> V_78 . V_130 &&
V_78 -> type == V_75 -> V_78 . type ) {
V_75 -> V_78 . V_60 = V_78 -> V_60 ;
}
}
}
static void * F_86 ( struct V_8 * V_9 , T_1 V_196 ,
unsigned int V_142 , unsigned int V_3 )
{
void * V_130 ;
int V_19 ;
T_7 V_146 ;
if ( V_196 == 0 ) {
F_21 ( V_9 , L_62 ) ;
return F_87 ( - V_52 ) ;
}
if ( V_196 > 1024 ) {
F_21 ( V_9 , L_63 , V_196 ) ;
return F_87 ( - V_52 ) ;
}
V_19 = F_39 ( V_9 -> V_66 , V_142 + V_3 , & V_146 , sizeof( V_146 ) ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_64 ,
V_19 ) ;
return F_87 ( V_19 ) ;
}
if ( F_81 ( V_146 ) != 0xbedead )
F_78 ( V_9 , L_65 ,
V_142 + V_3 , F_81 ( V_146 ) ) ;
V_130 = F_2 ( V_3 * 2 , V_7 | V_80 ) ;
if ( ! V_130 )
return F_87 ( - V_81 ) ;
V_19 = F_39 ( V_9 -> V_66 , V_142 , V_130 , V_3 * 2 ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_66 , V_19 ) ;
F_10 ( V_130 ) ;
return F_87 ( V_19 ) ;
}
return V_130 ;
}
static struct V_77 *
F_88 ( struct V_8 * V_9 , int type , unsigned int V_152 )
{
struct V_77 * V_78 ;
F_60 (alg_region, &dsp->alg_regions, list) {
if ( V_152 == V_78 -> V_130 && type == V_78 -> type )
return V_78 ;
}
return NULL ;
}
static struct V_77 * F_89 ( struct V_8 * V_9 ,
int type , T_7 V_152 ,
T_7 V_60 )
{
struct V_77 * V_78 ;
V_78 = F_2 ( sizeof( * V_78 ) , V_7 ) ;
if ( ! V_78 )
return F_87 ( - V_81 ) ;
V_78 -> type = type ;
V_78 -> V_130 = F_81 ( V_152 ) ;
V_78 -> V_60 = F_81 ( V_60 ) ;
F_5 ( & V_78 -> V_5 , & V_9 -> V_197 ) ;
if ( V_9 -> V_129 > 0 )
F_85 ( V_9 , V_78 ) ;
return V_78 ;
}
static void F_90 ( struct V_8 * V_9 )
{
struct V_77 * V_78 ;
while ( ! F_7 ( & V_9 -> V_197 ) ) {
V_78 = F_8 ( & V_9 -> V_197 ,
struct V_77 ,
V_5 ) ;
F_9 ( & V_78 -> V_5 ) ;
F_10 ( V_78 ) ;
}
}
static int F_91 ( struct V_8 * V_9 )
{
struct V_198 V_199 ;
struct V_200 * V_201 ;
struct V_77 * V_78 ;
const struct V_55 * V_57 ;
unsigned int V_142 , V_3 ;
T_1 V_196 ;
int V_27 , V_19 ;
V_57 = F_34 ( V_9 , V_61 ) ;
if ( F_36 ( ! V_57 ) )
return - V_52 ;
V_19 = F_39 ( V_9 -> V_66 , V_57 -> V_60 , & V_199 ,
sizeof( V_199 ) ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_67 ,
V_19 ) ;
return V_19 ;
}
V_196 = F_81 ( V_199 . V_196 ) ;
V_9 -> V_34 = F_81 ( V_199 . V_50 . V_152 ) ;
F_79 ( V_9 , L_68 ,
V_9 -> V_34 ,
( F_81 ( V_199 . V_50 . V_182 ) & 0xff0000 ) >> 16 ,
( F_81 ( V_199 . V_50 . V_182 ) & 0xff00 ) >> 8 ,
F_81 ( V_199 . V_50 . V_182 ) & 0xff ,
V_196 ) ;
V_78 = F_89 ( V_9 , V_64 ,
V_199 . V_50 . V_152 , V_199 . V_187 ) ;
if ( F_92 ( V_78 ) )
return F_93 ( V_78 ) ;
V_78 = F_89 ( V_9 , V_61 ,
V_199 . V_50 . V_152 , V_199 . V_185 ) ;
if ( F_92 ( V_78 ) )
return F_93 ( V_78 ) ;
V_142 = sizeof( V_199 ) / 2 ;
V_3 = ( sizeof( * V_201 ) * V_196 ) / 2 ;
V_201 = F_86 ( V_9 , V_196 , V_57 -> V_60 + V_142 , V_3 ) ;
if ( F_92 ( V_201 ) )
return F_93 ( V_201 ) ;
for ( V_27 = 0 ; V_27 < V_196 ; V_27 ++ ) {
F_79 ( V_9 , L_69 ,
V_27 , F_81 ( V_201 [ V_27 ] . V_130 . V_152 ) ,
( F_81 ( V_201 [ V_27 ] . V_130 . V_182 ) & 0xff0000 ) >> 16 ,
( F_81 ( V_201 [ V_27 ] . V_130 . V_182 ) & 0xff00 ) >> 8 ,
F_81 ( V_201 [ V_27 ] . V_130 . V_182 ) & 0xff ,
F_81 ( V_201 [ V_27 ] . V_185 ) ,
F_81 ( V_201 [ V_27 ] . V_187 ) ) ;
V_78 = F_89 ( V_9 , V_61 ,
V_201 [ V_27 ] . V_130 . V_152 ,
V_201 [ V_27 ] . V_185 ) ;
if ( F_92 ( V_78 ) ) {
V_19 = F_93 ( V_78 ) ;
goto V_94;
}
if ( V_9 -> V_129 == 0 ) {
if ( V_27 + 1 < V_196 ) {
V_3 = F_81 ( V_201 [ V_27 + 1 ] . V_185 ) ;
V_3 -= F_81 ( V_201 [ V_27 ] . V_185 ) ;
V_3 *= 4 ;
F_64 ( V_9 , V_78 , 0 ,
V_3 , NULL , 0 , 0 ) ;
} else {
F_78 ( V_9 , L_70 ,
F_81 ( V_201 [ V_27 ] . V_130 . V_152 ) ) ;
}
}
V_78 = F_89 ( V_9 , V_64 ,
V_201 [ V_27 ] . V_130 . V_152 ,
V_201 [ V_27 ] . V_187 ) ;
if ( F_92 ( V_78 ) ) {
V_19 = F_93 ( V_78 ) ;
goto V_94;
}
if ( V_9 -> V_129 == 0 ) {
if ( V_27 + 1 < V_196 ) {
V_3 = F_81 ( V_201 [ V_27 + 1 ] . V_187 ) ;
V_3 -= F_81 ( V_201 [ V_27 ] . V_187 ) ;
V_3 *= 4 ;
F_64 ( V_9 , V_78 , 0 ,
V_3 , NULL , 0 , 0 ) ;
} else {
F_78 ( V_9 , L_71 ,
F_81 ( V_201 [ V_27 ] . V_130 . V_152 ) ) ;
}
}
}
V_94:
F_10 ( V_201 ) ;
return V_19 ;
}
static int F_94 ( struct V_8 * V_9 )
{
struct V_202 V_203 ;
struct V_204 * V_205 ;
struct V_77 * V_78 ;
const struct V_55 * V_57 ;
unsigned int V_142 , V_3 ;
T_1 V_196 ;
int V_27 , V_19 ;
V_57 = F_34 ( V_9 , V_62 ) ;
if ( F_36 ( ! V_57 ) )
return - V_52 ;
V_19 = F_39 ( V_9 -> V_66 , V_57 -> V_60 , & V_203 ,
sizeof( V_203 ) ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_67 ,
V_19 ) ;
return V_19 ;
}
V_196 = F_81 ( V_203 . V_196 ) ;
V_9 -> V_34 = F_81 ( V_203 . V_50 . V_152 ) ;
V_9 -> V_35 = F_81 ( V_203 . V_50 . V_182 ) ;
F_79 ( V_9 , L_68 ,
V_9 -> V_34 ,
( V_9 -> V_35 & 0xff0000 ) >> 16 ,
( V_9 -> V_35 & 0xff00 ) >> 8 ,
V_9 -> V_35 & 0xff ,
V_196 ) ;
V_78 = F_89 ( V_9 , V_62 ,
V_203 . V_50 . V_152 , V_203 . V_189 ) ;
if ( F_92 ( V_78 ) )
return F_93 ( V_78 ) ;
V_78 = F_89 ( V_9 , V_63 ,
V_203 . V_50 . V_152 , V_203 . V_190 ) ;
if ( F_92 ( V_78 ) )
return F_93 ( V_78 ) ;
V_78 = F_89 ( V_9 , V_206 ,
V_203 . V_50 . V_152 , V_203 . V_187 ) ;
if ( F_92 ( V_78 ) )
return F_93 ( V_78 ) ;
V_142 = sizeof( V_203 ) / 2 ;
V_3 = ( sizeof( * V_205 ) * V_196 ) / 2 ;
V_205 = F_86 ( V_9 , V_196 , V_57 -> V_60 + V_142 , V_3 ) ;
if ( F_92 ( V_205 ) )
return F_93 ( V_205 ) ;
for ( V_27 = 0 ; V_27 < V_196 ; V_27 ++ ) {
F_79 ( V_9 ,
L_72 ,
V_27 , F_81 ( V_205 [ V_27 ] . V_130 . V_152 ) ,
( F_81 ( V_205 [ V_27 ] . V_130 . V_182 ) & 0xff0000 ) >> 16 ,
( F_81 ( V_205 [ V_27 ] . V_130 . V_182 ) & 0xff00 ) >> 8 ,
F_81 ( V_205 [ V_27 ] . V_130 . V_182 ) & 0xff ,
F_81 ( V_205 [ V_27 ] . V_189 ) ,
F_81 ( V_205 [ V_27 ] . V_190 ) ,
F_81 ( V_205 [ V_27 ] . V_187 ) ) ;
V_78 = F_89 ( V_9 , V_62 ,
V_205 [ V_27 ] . V_130 . V_152 ,
V_205 [ V_27 ] . V_189 ) ;
if ( F_92 ( V_78 ) ) {
V_19 = F_93 ( V_78 ) ;
goto V_94;
}
if ( V_9 -> V_129 == 0 ) {
if ( V_27 + 1 < V_196 ) {
V_3 = F_81 ( V_205 [ V_27 + 1 ] . V_189 ) ;
V_3 -= F_81 ( V_205 [ V_27 ] . V_189 ) ;
V_3 *= 4 ;
F_64 ( V_9 , V_78 , 0 ,
V_3 , NULL , 0 , 0 ) ;
} else {
F_78 ( V_9 , L_73 ,
F_81 ( V_205 [ V_27 ] . V_130 . V_152 ) ) ;
}
}
V_78 = F_89 ( V_9 , V_63 ,
V_205 [ V_27 ] . V_130 . V_152 ,
V_205 [ V_27 ] . V_190 ) ;
if ( F_92 ( V_78 ) ) {
V_19 = F_93 ( V_78 ) ;
goto V_94;
}
if ( V_9 -> V_129 == 0 ) {
if ( V_27 + 1 < V_196 ) {
V_3 = F_81 ( V_205 [ V_27 + 1 ] . V_190 ) ;
V_3 -= F_81 ( V_205 [ V_27 ] . V_190 ) ;
V_3 *= 4 ;
F_64 ( V_9 , V_78 , 0 ,
V_3 , NULL , 0 , 0 ) ;
} else {
F_78 ( V_9 , L_74 ,
F_81 ( V_205 [ V_27 ] . V_130 . V_152 ) ) ;
}
}
V_78 = F_89 ( V_9 , V_206 ,
V_205 [ V_27 ] . V_130 . V_152 ,
V_205 [ V_27 ] . V_187 ) ;
if ( F_92 ( V_78 ) ) {
V_19 = F_93 ( V_78 ) ;
goto V_94;
}
if ( V_9 -> V_129 == 0 ) {
if ( V_27 + 1 < V_196 ) {
V_3 = F_81 ( V_205 [ V_27 + 1 ] . V_187 ) ;
V_3 -= F_81 ( V_205 [ V_27 ] . V_187 ) ;
V_3 *= 4 ;
F_64 ( V_9 , V_78 , 0 ,
V_3 , NULL , 0 , 0 ) ;
} else {
F_78 ( V_9 , L_71 ,
F_81 ( V_205 [ V_27 ] . V_130 . V_152 ) ) ;
}
}
}
V_94:
F_10 ( V_205 ) ;
return V_19 ;
}
static int F_95 ( struct V_8 * V_9 )
{
F_76 ( V_164 ) ;
struct V_66 * V_66 = V_9 -> V_66 ;
struct V_207 * V_157 ;
struct V_208 * V_149 ;
const struct V_165 * V_165 ;
const struct V_55 * V_57 ;
struct V_77 * V_78 ;
const char * V_127 ;
int V_19 , V_142 , V_209 , type , V_58 , V_79 ;
char * V_14 ;
struct V_1 * V_6 ;
V_14 = F_2 ( V_31 , V_7 ) ;
if ( V_14 == NULL )
return - V_81 ;
snprintf ( V_14 , V_31 , L_75 , V_9 -> V_177 , V_9 -> V_32 ,
V_178 [ V_9 -> V_50 ] . V_14 ) ;
V_14 [ V_31 - 1 ] = '\0' ;
V_19 = F_77 ( & V_165 , V_14 , V_9 -> V_179 ) ;
if ( V_19 != 0 ) {
F_78 ( V_9 , L_37 , V_14 ) ;
V_19 = 0 ;
goto V_94;
}
V_19 = - V_52 ;
if ( sizeof( * V_157 ) >= V_165 -> V_88 ) {
F_21 ( V_9 , L_38 ,
V_14 , V_165 -> V_88 ) ;
goto V_180;
}
V_157 = ( void * ) & V_165 -> V_84 [ 0 ] ;
if ( memcmp ( V_157 -> V_181 , L_76 , 4 ) != 0 ) {
F_21 ( V_9 , L_40 , V_14 ) ;
goto V_180;
}
switch ( F_81 ( V_157 -> V_210 ) & 0xff ) {
case 1 :
break;
default:
F_21 ( V_9 , L_77 ,
V_14 , F_81 ( V_157 -> V_210 ) & 0xff ) ;
V_19 = - V_52 ;
goto V_180;
}
F_40 ( V_9 , L_78 , V_14 ,
( F_71 ( V_157 -> V_182 ) >> 16 ) & 0xff ,
( F_71 ( V_157 -> V_182 ) >> 8 ) & 0xff ,
F_71 ( V_157 -> V_182 ) & 0xff ) ;
V_142 = F_71 ( V_157 -> V_3 ) ;
V_209 = 0 ;
while ( V_142 < V_165 -> V_88 &&
V_142 - V_165 -> V_88 > sizeof( * V_149 ) ) {
V_149 = ( void * ) ( & V_165 -> V_84 [ V_142 ] ) ;
type = F_69 ( V_149 -> type ) ;
V_58 = F_69 ( V_149 -> V_58 ) ;
F_40 ( V_9 , L_79 ,
V_14 , V_209 , F_71 ( V_149 -> V_152 ) ,
( F_71 ( V_149 -> V_182 ) >> 16 ) & 0xff ,
( F_71 ( V_149 -> V_182 ) >> 8 ) & 0xff ,
F_71 ( V_149 -> V_182 ) & 0xff ) ;
F_40 ( V_9 , L_80 ,
V_14 , V_209 , F_71 ( V_149 -> V_3 ) , V_58 , type ) ;
V_79 = 0 ;
V_127 = L_50 ;
switch ( type ) {
case ( V_192 << 8 ) :
case ( V_194 << 8 ) :
break;
case ( V_195 << 8 ) :
if ( F_71 ( V_149 -> V_152 ) == V_9 -> V_34 &&
V_58 == 0 ) {
V_127 = L_81 ;
V_57 = F_34 ( V_9 , type ) ;
if ( ! V_57 ) {
F_21 ( V_9 , L_82 ) ;
break;
}
V_79 = F_35 ( V_57 , 0 ) ;
} else {
V_127 = L_83 ;
V_79 = V_58 ;
}
break;
case V_61 :
case V_64 :
case V_62 :
case V_63 :
F_40 ( V_9 , L_84 ,
V_14 , V_209 , F_71 ( V_149 -> V_3 ) ,
type , F_71 ( V_149 -> V_152 ) ) ;
V_57 = F_34 ( V_9 , type ) ;
if ( ! V_57 ) {
F_21 ( V_9 , L_11 , type ) ;
break;
}
V_78 = F_88 ( V_9 , type ,
F_71 ( V_149 -> V_152 ) ) ;
if ( V_78 ) {
V_79 = V_78 -> V_60 ;
V_79 = F_35 ( V_57 , V_79 ) ;
V_79 += V_58 ;
} else {
F_21 ( V_9 , L_85 ,
type , F_71 ( V_149 -> V_152 ) ) ;
}
break;
default:
F_21 ( V_9 , L_86 ,
V_14 , V_209 , type , V_142 ) ;
break;
}
if ( V_79 ) {
V_6 = F_1 ( V_149 -> V_84 ,
F_71 ( V_149 -> V_3 ) ,
& V_164 ) ;
if ( ! V_6 ) {
F_21 ( V_9 , L_58 ) ;
V_19 = - V_81 ;
goto V_180;
}
F_40 ( V_9 , L_87 ,
V_14 , V_209 , F_71 ( V_149 -> V_3 ) ,
V_79 ) ;
V_19 = F_82 ( V_66 , V_79 , V_6 -> V_6 ,
F_71 ( V_149 -> V_3 ) ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 ,
L_88 ,
V_14 , V_209 , V_79 , V_127 , V_19 ) ;
}
}
V_142 += ( F_71 ( V_149 -> V_3 ) + sizeof( * V_149 ) + 3 ) & ~ 0x03 ;
V_209 ++ ;
}
V_19 = F_83 ( V_66 ) ;
if ( V_19 != 0 )
F_21 ( V_9 , L_60 , V_19 ) ;
if ( V_142 > V_165 -> V_88 )
F_78 ( V_9 , L_61 ,
V_14 , V_209 , V_142 - V_165 -> V_88 ) ;
F_13 ( V_9 , V_14 ) ;
V_180:
F_83 ( V_66 ) ;
F_84 ( V_165 ) ;
F_6 ( & V_164 ) ;
V_94:
F_10 ( V_14 ) ;
return V_19 ;
}
int F_96 ( struct V_8 * V_9 )
{
F_97 ( & V_9 -> V_197 ) ;
F_98 ( & V_9 -> V_20 ) ;
return 0 ;
}
int F_99 ( struct V_211 * V_212 ,
struct V_39 * V_40 ,
int V_213 )
{
struct V_22 * V_23 = F_100 ( V_212 -> V_214 ) ;
struct V_8 * V_215 = F_32 ( V_23 ) ;
struct V_8 * V_9 = & V_215 [ V_212 -> V_216 ] ;
struct V_68 * V_75 ;
int V_19 ;
unsigned int V_146 ;
V_9 -> V_118 = V_23 -> V_28 . V_118 ;
F_16 ( & V_9 -> V_20 ) ;
switch ( V_213 ) {
case V_217 :
F_101 ( V_9 -> V_66 , V_9 -> V_60 + V_218 ,
V_219 , V_219 ) ;
if ( V_9 -> V_220 ) {
V_19 = F_102 ( V_9 -> V_66 , V_9 -> V_220 , & V_146 ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_89 ,
V_19 ) ;
goto V_221;
}
V_146 = ( V_146 & V_9 -> V_222 ) >> V_9 -> V_223 ;
V_19 = F_101 ( V_9 -> V_66 ,
V_9 -> V_60 + V_224 ,
V_225 , V_146 ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_90 ,
V_19 ) ;
goto V_221;
}
}
V_19 = F_75 ( V_9 ) ;
if ( V_19 != 0 )
goto V_226;
V_19 = F_91 ( V_9 ) ;
if ( V_19 != 0 )
goto V_226;
V_19 = F_95 ( V_9 ) ;
if ( V_19 != 0 )
goto V_226;
V_19 = F_59 ( V_9 ) ;
if ( V_19 != 0 )
goto V_226;
V_19 = F_61 ( V_9 ) ;
if ( V_19 != 0 )
goto V_226;
F_101 ( V_9 -> V_66 , V_9 -> V_60 + V_218 ,
V_227 | V_228 ,
V_227 | V_228 ) ;
break;
case V_229 :
F_101 ( V_9 -> V_66 , V_9 -> V_60 + V_218 ,
V_227 | V_228 , 0 ) ;
F_101 ( V_9 -> V_66 , V_9 -> V_60 + V_230 ,
V_231 , 0 ) ;
F_101 ( V_9 -> V_66 , V_9 -> V_60 + V_218 ,
V_219 , 0 ) ;
F_60 (ctl, &dsp->ctl_list, list)
V_75 -> V_87 = 0 ;
F_90 ( V_9 ) ;
break;
default:
break;
}
F_18 ( & V_9 -> V_20 ) ;
return 0 ;
V_226:
F_101 ( V_9 -> V_66 , V_9 -> V_60 + V_218 ,
V_219 , 0 ) ;
V_221:
F_18 ( & V_9 -> V_20 ) ;
return V_19 ;
}
static int F_103 ( struct V_8 * V_9 )
{
unsigned int V_146 ;
int V_19 , V_16 ;
V_19 = F_104 ( V_9 -> V_66 , V_9 -> V_60 + V_232 ,
V_233 , V_233 ) ;
if ( V_19 != 0 )
return V_19 ;
for ( V_16 = 0 ; V_16 < 10 ; ++ V_16 ) {
V_19 = F_102 ( V_9 -> V_66 , V_9 -> V_60 + V_234 , & V_146 ) ;
if ( V_19 != 0 )
return V_19 ;
if ( V_146 & V_235 )
break;
F_105 ( 1 ) ;
}
if ( ! ( V_146 & V_235 ) ) {
F_21 ( V_9 , L_91 ) ;
return - V_54 ;
}
F_40 ( V_9 , L_92 , V_16 ) ;
return 0 ;
}
static void F_106 ( struct V_120 * V_121 )
{
struct V_8 * V_9 = F_43 ( V_121 ,
struct V_8 ,
V_236 ) ;
int V_19 ;
F_16 ( & V_9 -> V_20 ) ;
V_19 = F_103 ( V_9 ) ;
if ( V_19 != 0 )
goto V_221;
V_19 = F_75 ( V_9 ) ;
if ( V_19 != 0 )
goto V_226;
V_19 = F_94 ( V_9 ) ;
if ( V_19 != 0 )
goto V_226;
V_19 = F_95 ( V_9 ) ;
if ( V_19 != 0 )
goto V_226;
V_19 = F_59 ( V_9 ) ;
if ( V_19 != 0 )
goto V_226;
V_19 = F_61 ( V_9 ) ;
if ( V_19 != 0 )
goto V_226;
V_9 -> V_21 = true ;
F_18 ( & V_9 -> V_20 ) ;
return;
V_226:
F_101 ( V_9 -> V_66 , V_9 -> V_60 + V_232 ,
V_233 | V_237 | V_238 , 0 ) ;
V_221:
F_18 ( & V_9 -> V_20 ) ;
}
static void F_107 ( struct V_8 * V_9 , unsigned int V_239 )
{
int V_19 ;
V_19 = F_104 ( V_9 -> V_66 ,
V_9 -> V_60 + V_240 ,
V_241 ,
V_239 << V_242 ) ;
if ( V_19 != 0 )
F_21 ( V_9 , L_90 , V_19 ) ;
}
int F_108 ( struct V_211 * V_212 ,
struct V_39 * V_40 , int V_213 ,
unsigned int V_239 )
{
struct V_22 * V_23 = F_100 ( V_212 -> V_214 ) ;
struct V_8 * V_215 = F_32 ( V_23 ) ;
struct V_8 * V_9 = & V_215 [ V_212 -> V_216 ] ;
V_9 -> V_118 = V_23 -> V_28 . V_118 ;
switch ( V_213 ) {
case V_243 :
F_107 ( V_9 , V_239 ) ;
F_109 ( V_244 , & V_9 -> V_236 ) ;
break;
default:
break;
}
return 0 ;
}
int F_110 ( struct V_211 * V_212 ,
struct V_39 * V_40 , int V_213 )
{
struct V_22 * V_23 = F_100 ( V_212 -> V_214 ) ;
struct V_8 * V_215 = F_32 ( V_23 ) ;
struct V_8 * V_9 = & V_215 [ V_212 -> V_216 ] ;
struct V_68 * V_75 ;
int V_19 ;
switch ( V_213 ) {
case V_217 :
F_111 ( & V_9 -> V_236 ) ;
if ( ! V_9 -> V_21 )
return - V_245 ;
V_19 = F_101 ( V_9 -> V_66 ,
V_9 -> V_60 + V_232 ,
V_237 | V_238 ,
V_237 | V_238 ) ;
if ( V_19 != 0 )
goto V_30;
F_16 ( & V_9 -> V_20 ) ;
if ( V_178 [ V_9 -> V_50 ] . V_246 != 0 )
V_19 = F_112 ( V_9 ) ;
F_18 ( & V_9 -> V_20 ) ;
break;
case V_229 :
F_38 ( V_9 ) ;
F_16 ( & V_9 -> V_20 ) ;
F_14 ( V_9 ) ;
V_9 -> V_34 = 0 ;
V_9 -> V_35 = 0 ;
V_9 -> V_21 = false ;
F_101 ( V_9 -> V_66 , V_9 -> V_60 + V_232 ,
V_233 | V_237 |
V_238 , 0 ) ;
F_113 ( V_9 -> V_66 , V_9 -> V_60 + V_247 , 0 ) ;
F_113 ( V_9 -> V_66 , V_9 -> V_60 + V_248 , 0 ) ;
F_113 ( V_9 -> V_66 , V_9 -> V_60 + V_249 , 0 ) ;
F_60 (ctl, &dsp->ctl_list, list)
V_75 -> V_87 = 0 ;
F_90 ( V_9 ) ;
if ( V_178 [ V_9 -> V_50 ] . V_246 != 0 )
F_114 ( V_9 ) ;
F_18 ( & V_9 -> V_20 ) ;
F_40 ( V_9 , L_93 ) ;
break;
default:
break;
}
return 0 ;
V_30:
F_101 ( V_9 -> V_66 , V_9 -> V_60 + V_232 ,
V_233 | V_237 | V_238 , 0 ) ;
return V_19 ;
}
int F_115 ( struct V_8 * V_9 , struct V_22 * V_23 )
{
F_20 ( V_9 , V_23 ) ;
return F_116 ( V_23 ,
& V_250 [ V_9 -> V_32 - 1 ] ,
1 ) ;
}
int F_117 ( struct V_8 * V_9 , struct V_22 * V_23 )
{
F_29 ( V_9 ) ;
return 0 ;
}
int F_118 ( struct V_8 * V_9 )
{
int V_19 ;
V_19 = F_101 ( V_9 -> V_66 , V_9 -> V_60 + V_232 ,
V_251 , 0 ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_94 , V_19 ) ;
return V_19 ;
}
F_97 ( & V_9 -> V_197 ) ;
F_97 ( & V_9 -> V_140 ) ;
F_66 ( & V_9 -> V_236 , F_106 ) ;
F_98 ( & V_9 -> V_20 ) ;
return 0 ;
}
void F_119 ( struct V_8 * V_9 )
{
struct V_68 * V_75 ;
while ( ! F_7 ( & V_9 -> V_140 ) ) {
V_75 = F_8 ( & V_9 -> V_140 , struct V_68 ,
V_5 ) ;
F_9 ( & V_75 -> V_5 ) ;
F_63 ( V_75 ) ;
}
}
static inline int F_120 ( struct V_252 * V_53 )
{
return V_53 -> V_6 != NULL ;
}
static int F_121 ( struct V_252 * V_53 )
{
if ( ! V_53 -> V_9 -> V_253 )
return - V_52 ;
V_53 -> V_6 = V_53 -> V_9 -> V_253 ;
V_53 -> V_6 -> V_53 = V_53 ;
return 0 ;
}
static void F_122 ( struct V_252 * V_53 )
{
if ( ! V_53 )
return;
if ( V_53 -> V_254 )
F_123 ( V_53 -> V_254 ) ;
if ( F_120 ( V_53 ) ) {
V_53 -> V_6 -> V_53 = NULL ;
V_53 -> V_6 = NULL ;
}
}
int F_124 ( struct V_8 * V_9 , struct V_255 * V_254 )
{
struct V_252 * V_53 ;
int V_19 = 0 ;
F_16 ( & V_9 -> V_20 ) ;
if ( V_178 [ V_9 -> V_50 ] . V_246 == 0 ) {
F_21 ( V_9 , L_95 ) ;
V_19 = - V_256 ;
goto V_94;
}
if ( V_178 [ V_9 -> V_50 ] . V_257 != V_254 -> V_258 ) {
F_21 ( V_9 , L_96 ) ;
V_19 = - V_52 ;
goto V_94;
}
if ( V_9 -> V_53 ) {
F_21 ( V_9 , L_97 ) ;
V_19 = - V_54 ;
goto V_94;
}
V_53 = F_2 ( sizeof( * V_53 ) , V_7 ) ;
if ( ! V_53 ) {
V_19 = - V_81 ;
goto V_94;
}
V_53 -> V_9 = V_9 ;
V_53 -> V_254 = V_254 ;
V_9 -> V_53 = V_53 ;
V_254 -> V_259 -> V_18 = V_53 ;
V_94:
F_18 ( & V_9 -> V_20 ) ;
return V_19 ;
}
int F_125 ( struct V_255 * V_254 )
{
struct V_252 * V_53 = V_254 -> V_259 -> V_18 ;
struct V_8 * V_9 = V_53 -> V_9 ;
F_16 ( & V_9 -> V_20 ) ;
F_122 ( V_53 ) ;
V_9 -> V_53 = NULL ;
F_10 ( V_53 -> V_260 ) ;
F_10 ( V_53 ) ;
F_18 ( & V_9 -> V_20 ) ;
return 0 ;
}
static int F_126 ( struct V_255 * V_254 ,
struct V_261 * V_262 )
{
struct V_252 * V_53 = V_254 -> V_259 -> V_18 ;
struct V_8 * V_9 = V_53 -> V_9 ;
const struct V_263 * V_264 ;
const struct V_265 * V_266 ;
int V_27 , V_267 ;
if ( V_262 -> V_253 . V_268 < V_269 ||
V_262 -> V_253 . V_268 > V_270 ||
V_262 -> V_253 . V_271 < V_272 ||
V_262 -> V_253 . V_271 > V_273 ||
V_262 -> V_253 . V_268 % V_274 ) {
F_21 ( V_9 , L_98 ,
V_262 -> V_253 . V_268 ,
V_262 -> V_253 . V_271 ) ;
return - V_52 ;
}
for ( V_27 = 0 ; V_27 < V_178 [ V_9 -> V_50 ] . V_246 ; V_27 ++ ) {
V_264 = & V_178 [ V_9 -> V_50 ] . V_264 [ V_27 ] ;
V_266 = & V_264 -> V_266 ;
if ( V_264 -> V_152 != V_262 -> V_23 . V_152 )
continue;
if ( V_254 -> V_258 == V_275 ) {
if ( V_266 -> V_276 < V_262 -> V_23 . V_277 )
continue;
} else {
if ( V_266 -> V_276 < V_262 -> V_23 . V_278 )
continue;
}
if ( ! ( V_266 -> V_279 & ( 1 << V_262 -> V_23 . V_280 ) ) )
continue;
for ( V_267 = 0 ; V_267 < V_266 -> V_281 ; ++ V_267 )
if ( V_266 -> V_282 [ V_267 ] == V_262 -> V_23 . V_283 )
return 0 ;
}
F_21 ( V_9 , L_99 ,
V_262 -> V_23 . V_152 , V_262 -> V_23 . V_278 , V_262 -> V_23 . V_277 ,
V_262 -> V_23 . V_283 , V_262 -> V_23 . V_280 ) ;
return - V_52 ;
}
static inline unsigned int F_127 ( struct V_252 * V_53 )
{
return V_53 -> V_88 . V_268 / V_274 ;
}
int F_128 ( struct V_255 * V_254 ,
struct V_261 * V_262 )
{
struct V_252 * V_53 = V_254 -> V_259 -> V_18 ;
unsigned int V_88 ;
int V_19 ;
V_19 = F_126 ( V_254 , V_262 ) ;
if ( V_19 )
return V_19 ;
V_53 -> V_88 = V_262 -> V_253 ;
F_40 ( V_53 -> V_9 , L_100 ,
V_53 -> V_88 . V_268 , V_53 -> V_88 . V_271 ) ;
V_88 = F_127 ( V_53 ) * sizeof( * V_53 -> V_260 ) ;
V_53 -> V_260 = F_22 ( V_88 , V_80 | V_7 ) ;
if ( ! V_53 -> V_260 )
return - V_81 ;
V_53 -> V_283 = V_262 -> V_23 . V_283 ;
return 0 ;
}
int F_129 ( struct V_255 * V_254 ,
struct V_284 * V_264 )
{
struct V_252 * V_53 = V_254 -> V_259 -> V_18 ;
int V_50 = V_53 -> V_9 -> V_50 ;
int V_27 ;
if ( V_178 [ V_50 ] . V_264 ) {
for ( V_27 = 0 ; V_27 < V_178 [ V_50 ] . V_246 ; V_27 ++ )
V_264 -> V_285 [ V_27 ] = V_178 [ V_50 ] . V_264 [ V_27 ] . V_152 ;
V_264 -> V_286 = V_27 ;
V_264 -> V_258 = V_178 [ V_50 ] . V_257 ;
V_264 -> V_287 = V_269 ;
V_264 -> V_288 = V_270 ;
V_264 -> V_289 = V_272 ;
V_264 -> V_290 = V_273 ;
}
return 0 ;
}
static int F_130 ( struct V_8 * V_9 , int V_158 ,
unsigned int V_291 ,
unsigned int V_292 , T_8 * V_84 )
{
struct V_55 const * V_57 = F_34 ( V_9 , V_158 ) ;
unsigned int V_27 , V_79 ;
int V_19 ;
if ( ! V_57 )
return - V_52 ;
V_79 = F_35 ( V_57 , V_291 ) ;
V_19 = F_39 ( V_9 -> V_66 , V_79 , V_84 ,
sizeof( * V_84 ) * V_292 ) ;
if ( V_19 < 0 )
return V_19 ;
for ( V_27 = 0 ; V_27 < V_292 ; ++ V_27 )
V_84 [ V_27 ] = F_81 ( V_84 [ V_27 ] ) & 0x00ffffffu ;
return 0 ;
}
static inline int F_131 ( struct V_8 * V_9 , int V_158 ,
unsigned int V_291 , T_8 * V_84 )
{
return F_130 ( V_9 , V_158 , V_291 , 1 , V_84 ) ;
}
static int F_132 ( struct V_8 * V_9 , int V_158 ,
unsigned int V_291 , T_8 V_84 )
{
struct V_55 const * V_57 = F_34 ( V_9 , V_158 ) ;
unsigned int V_79 ;
if ( ! V_57 )
return - V_52 ;
V_79 = F_35 ( V_57 , V_291 ) ;
V_84 = F_133 ( V_84 & 0x00ffffffu ) ;
return F_47 ( V_9 -> V_66 , V_79 , & V_84 , sizeof( V_84 ) ) ;
}
static inline int F_134 ( struct V_293 * V_6 ,
unsigned int V_294 , T_8 * V_84 )
{
return F_131 ( V_6 -> V_9 , V_62 ,
V_6 -> V_295 + V_294 , V_84 ) ;
}
static inline int F_135 ( struct V_293 * V_6 ,
unsigned int V_294 , T_8 V_84 )
{
return F_132 ( V_6 -> V_9 , V_62 ,
V_6 -> V_295 + V_294 , V_84 ) ;
}
static int F_136 ( struct V_293 * V_6 )
{
struct V_77 * V_78 ;
struct V_8 * V_9 = V_6 -> V_9 ;
T_8 V_296 , V_297 , V_181 ;
int V_27 , V_19 ;
V_78 = F_88 ( V_9 , V_62 , V_9 -> V_34 ) ;
V_296 = sizeof( struct V_298 ) / sizeof( T_7 ) ;
V_297 = V_78 -> V_60 + V_296 + F_137 ( V_181 ) ;
V_19 = F_131 ( V_9 , V_62 , V_297 , & V_181 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_181 != V_299 )
return - V_52 ;
V_297 = V_78 -> V_60 + V_296 + F_137 ( V_295 ) ;
for ( V_27 = 0 ; V_27 < 5 ; ++ V_27 ) {
V_19 = F_131 ( V_9 , V_62 , V_297 ,
& V_6 -> V_295 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_6 -> V_295 )
break;
F_138 ( 1000 , 2000 ) ;
}
if ( ! V_6 -> V_295 )
return - V_245 ;
F_40 ( V_9 , L_101 , V_6 -> V_295 ) ;
return 0 ;
}
static int F_139 ( struct V_293 * V_6 )
{
const struct V_263 * V_264 = V_178 [ V_6 -> V_9 -> V_50 ] . V_264 ;
struct V_300 * V_161 ;
T_8 V_58 = 0 ;
int V_27 , V_19 ;
for ( V_27 = 0 ; V_27 < V_264 -> V_301 ; ++ V_27 ) {
V_161 = & V_6 -> V_175 [ V_27 ] ;
V_161 -> V_58 = V_58 ;
V_161 -> V_158 = V_264 -> V_302 [ V_27 ] . V_158 ;
V_19 = F_134 ( V_6 , V_264 -> V_302 [ V_27 ] . V_303 ,
& V_161 -> V_304 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_134 ( V_6 , V_264 -> V_302 [ V_27 ] . V_305 ,
& V_58 ) ;
if ( V_19 < 0 )
return V_19 ;
V_161 -> V_306 = V_58 ;
F_40 ( V_6 -> V_9 ,
L_102 ,
V_27 , V_161 -> V_158 , V_161 -> V_304 ,
V_161 -> V_58 , V_161 -> V_306 ) ;
}
return 0 ;
}
static int F_112 ( struct V_8 * V_9 )
{
struct V_293 * V_6 ;
int V_19 ;
V_6 = F_2 ( sizeof( * V_6 ) , V_7 ) ;
if ( ! V_6 )
return - V_81 ;
V_6 -> V_9 = V_9 ;
V_6 -> V_307 = - 1 ;
V_6 -> V_308 = 0xFFFFFFFF ;
V_19 = F_136 ( V_6 ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 , L_103 , V_19 ) ;
goto V_309;
}
V_6 -> V_175 = F_140 ( V_178 [ V_9 -> V_50 ] . V_264 -> V_301 ,
sizeof( * V_6 -> V_175 ) , V_7 ) ;
if ( ! V_6 -> V_175 ) {
V_19 = - V_81 ;
goto V_309;
}
V_19 = F_139 ( V_6 ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 , L_104 , V_19 ) ;
goto V_310;
}
V_9 -> V_253 = V_6 ;
return 0 ;
V_310:
F_10 ( V_6 -> V_175 ) ;
V_309:
F_10 ( V_6 ) ;
return V_19 ;
}
static int F_114 ( struct V_8 * V_9 )
{
if ( V_9 -> V_253 ) {
F_122 ( V_9 -> V_253 -> V_53 ) ;
F_10 ( V_9 -> V_253 -> V_175 ) ;
F_10 ( V_9 -> V_253 ) ;
V_9 -> V_253 = NULL ;
}
return 0 ;
}
int F_141 ( struct V_255 * V_254 , int V_311 )
{
struct V_252 * V_53 = V_254 -> V_259 -> V_18 ;
struct V_8 * V_9 = V_53 -> V_9 ;
int V_19 = 0 ;
F_40 ( V_9 , L_105 , V_311 ) ;
F_16 ( & V_9 -> V_20 ) ;
switch ( V_311 ) {
case V_312 :
if ( F_120 ( V_53 ) )
break;
V_19 = F_121 ( V_53 ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 , L_106 ,
V_19 ) ;
break;
}
V_19 = F_135 ( V_53 -> V_6 ,
F_142 ( V_313 ) ,
F_127 ( V_53 ) ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 , L_107 ,
V_19 ) ;
break;
}
break;
case V_314 :
break;
default:
V_19 = - V_52 ;
break;
}
F_18 ( & V_9 -> V_20 ) ;
return V_19 ;
}
static inline int F_143 ( struct V_293 * V_6 )
{
int V_315 = V_178 [ V_6 -> V_9 -> V_50 ] . V_264 -> V_301 - 1 ;
return V_6 -> V_175 [ V_315 ] . V_306 ;
}
static int F_144 ( struct V_293 * V_6 )
{
T_8 V_316 , V_317 ;
int V_318 , V_307 , V_132 ;
int V_19 ;
if ( V_6 -> V_307 < 0 ) {
V_19 = F_134 ( V_6 ,
F_142 ( V_316 ) ,
& V_316 ) ;
if ( V_19 < 0 )
return V_19 ;
V_307 = F_145 ( V_316 , 23 ) ;
if ( V_307 < 0 ) {
F_40 ( V_6 -> V_9 , L_108 ) ;
return 0 ;
}
V_6 -> V_307 = V_307 ;
}
V_19 = F_134 ( V_6 , F_142 ( V_317 ) ,
& V_317 ) ;
if ( V_19 < 0 )
return V_19 ;
V_318 = F_145 ( V_317 , 23 ) ;
V_132 = V_318 - V_6 -> V_307 ;
if ( V_132 < 0 )
V_132 += F_143 ( V_6 ) ;
F_40 ( V_6 -> V_9 , L_109 ,
V_6 -> V_307 , V_318 , V_132 * V_274 ) ;
V_6 -> V_132 = V_132 ;
return 0 ;
}
static int F_146 ( struct V_293 * V_6 )
{
int V_19 ;
V_19 = F_134 ( V_6 , F_142 ( error ) , & V_6 -> error ) ;
if ( V_19 < 0 ) {
F_21 ( V_6 -> V_9 , L_110 , V_19 ) ;
return V_19 ;
}
if ( V_6 -> error != 0 ) {
F_21 ( V_6 -> V_9 , L_111 , V_6 -> error ) ;
return - V_245 ;
}
return 0 ;
}
int F_147 ( struct V_8 * V_9 )
{
struct V_293 * V_6 ;
struct V_252 * V_53 ;
int V_19 = 0 ;
F_16 ( & V_9 -> V_20 ) ;
V_6 = V_9 -> V_253 ;
V_53 = V_9 -> V_53 ;
if ( ! V_6 ) {
V_19 = - V_319 ;
goto V_94;
}
F_40 ( V_9 , L_112 ) ;
V_19 = F_146 ( V_6 ) ;
if ( V_19 < 0 )
goto V_320;
V_19 = F_134 ( V_6 , F_142 ( V_308 ) ,
& V_6 -> V_308 ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 , L_113 , V_19 ) ;
goto V_94;
}
V_19 = F_144 ( V_6 ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 , L_114 , V_19 ) ;
goto V_94;
}
V_320:
if ( V_53 && V_53 -> V_254 )
F_123 ( V_53 -> V_254 ) ;
V_94:
F_18 ( & V_9 -> V_20 ) ;
return V_19 ;
}
static int F_148 ( struct V_293 * V_6 )
{
if ( V_6 -> V_308 & 0x01 )
return 0 ;
F_40 ( V_6 -> V_9 , L_115 ,
V_6 -> V_308 ) ;
V_6 -> V_308 |= 0x01 ;
return F_135 ( V_6 , F_142 ( V_321 ) ,
V_6 -> V_308 ) ;
}
int F_149 ( struct V_255 * V_254 ,
struct V_322 * V_323 )
{
struct V_252 * V_53 = V_254 -> V_259 -> V_18 ;
struct V_8 * V_9 = V_53 -> V_9 ;
struct V_293 * V_6 ;
int V_19 = 0 ;
F_40 ( V_9 , L_116 ) ;
F_16 ( & V_9 -> V_20 ) ;
V_6 = V_53 -> V_6 ;
if ( ! V_53 -> V_6 ) {
V_19 = - V_256 ;
goto V_94;
}
if ( V_53 -> V_6 -> error ) {
V_19 = - V_245 ;
goto V_94;
}
if ( V_6 -> V_132 < F_127 ( V_53 ) ) {
V_19 = F_144 ( V_6 ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 , L_114 , V_19 ) ;
goto V_94;
}
if ( V_6 -> V_132 < F_127 ( V_53 ) ) {
V_19 = F_146 ( V_6 ) ;
if ( V_19 < 0 )
goto V_94;
V_19 = F_148 ( V_6 ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 ,
L_117 ,
V_19 ) ;
goto V_94;
}
}
}
V_323 -> V_324 = V_53 -> V_324 ;
V_323 -> V_324 += V_6 -> V_132 * V_274 ;
V_323 -> V_325 = V_53 -> V_283 ;
V_94:
F_18 ( & V_9 -> V_20 ) ;
return V_19 ;
}
static int F_150 ( struct V_252 * V_53 , int V_326 )
{
struct V_293 * V_6 = V_53 -> V_6 ;
T_6 * V_327 = ( T_6 * ) V_53 -> V_260 ;
T_6 * V_328 = ( T_6 * ) V_53 -> V_260 ;
unsigned int V_329 ;
int V_158 , V_330 , V_331 ;
int V_27 , V_267 , V_19 ;
for ( V_27 = 0 ; V_27 < V_178 [ V_6 -> V_9 -> V_50 ] . V_264 -> V_301 ; ++ V_27 )
if ( V_6 -> V_307 < V_6 -> V_175 [ V_27 ] . V_306 )
break;
if ( V_27 == V_178 [ V_6 -> V_9 -> V_50 ] . V_264 -> V_301 )
return - V_52 ;
V_158 = V_6 -> V_175 [ V_27 ] . V_158 ;
V_329 = V_6 -> V_175 [ V_27 ] . V_304 +
( V_6 -> V_307 - V_6 -> V_175 [ V_27 ] . V_58 ) ;
V_331 = F_127 ( V_53 ) ;
V_330 = V_6 -> V_175 [ V_27 ] . V_306 - V_6 -> V_307 ;
if ( V_330 > V_326 )
V_330 = V_326 ;
if ( V_330 > V_6 -> V_132 )
V_330 = V_6 -> V_132 ;
if ( V_330 > V_331 )
V_330 = V_331 ;
if ( ! V_330 )
return 0 ;
V_19 = F_130 ( V_6 -> V_9 , V_158 , V_329 ,
V_330 , V_53 -> V_260 ) ;
if ( V_19 < 0 )
return V_19 ;
for ( V_27 = 0 ; V_27 < V_330 ; V_27 ++ ) {
for ( V_267 = 0 ; V_267 < V_274 ; V_267 ++ )
* V_328 ++ = * V_327 ++ ;
V_327 += sizeof( * ( V_53 -> V_260 ) ) - V_274 ;
}
V_6 -> V_307 += V_330 ;
if ( V_6 -> V_307 == F_143 ( V_6 ) )
V_6 -> V_307 = 0 ;
V_19 = F_135 ( V_6 , F_142 ( V_316 ) ,
V_6 -> V_307 ) ;
if ( V_19 < 0 )
return V_19 ;
V_6 -> V_132 -= V_330 ;
return V_330 ;
}
static int F_151 ( struct V_252 * V_53 ,
char T_3 * V_6 , T_1 V_16 )
{
struct V_8 * V_9 = V_53 -> V_9 ;
int V_332 = 0 ;
int V_330 , V_333 ;
F_40 ( V_9 , L_118 , V_16 ) ;
if ( ! V_53 -> V_6 )
return - V_256 ;
if ( V_53 -> V_6 -> error )
return - V_245 ;
V_16 /= V_274 ;
do {
V_330 = F_150 ( V_53 , V_16 ) ;
if ( V_330 < 0 ) {
F_21 ( V_9 , L_119 , V_330 ) ;
return V_330 ;
}
V_333 = V_330 * V_274 ;
F_40 ( V_9 , L_120 , V_333 ) ;
if ( F_54 ( V_6 + V_332 , V_53 -> V_260 , V_333 ) ) {
F_21 ( V_9 , L_121 ,
V_332 , V_333 ) ;
return - V_89 ;
}
V_16 -= V_330 ;
V_332 += V_333 ;
} while ( V_330 > 0 && V_16 > 0 );
V_53 -> V_324 += V_332 ;
return V_332 ;
}
int F_152 ( struct V_255 * V_254 , char T_3 * V_6 ,
T_1 V_16 )
{
struct V_252 * V_53 = V_254 -> V_259 -> V_18 ;
struct V_8 * V_9 = V_53 -> V_9 ;
int V_19 ;
F_16 ( & V_9 -> V_20 ) ;
if ( V_254 -> V_258 == V_334 )
V_19 = F_151 ( V_53 , V_6 , V_16 ) ;
else
V_19 = - V_335 ;
F_18 ( & V_9 -> V_20 ) ;
return V_19 ;
}
