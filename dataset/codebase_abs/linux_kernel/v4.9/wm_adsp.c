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
if ( ! F_24 ( L_5 , V_33 , V_25 , & V_9 -> V_34 ) )
goto V_30;
if ( ! F_25 ( L_6 , V_33 , V_25 , & V_9 -> V_35 ) )
goto V_30;
if ( ! F_25 ( L_7 , V_33 , V_25 ,
& V_9 -> V_36 ) )
goto V_30;
for ( V_27 = 0 ; V_27 < F_26 ( V_37 ) ; ++ V_27 ) {
if ( ! F_27 ( V_37 [ V_27 ] . V_38 ,
V_33 , V_25 , V_9 ,
& V_37 [ V_27 ] . V_39 ) )
goto V_30;
}
V_9 -> V_29 = V_25 ;
return;
V_30:
F_28 ( V_25 ) ;
F_21 ( V_9 , L_8 ) ;
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
static int F_30 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_22 * V_23 = F_31 ( V_41 ) ;
struct V_44 * V_45 = (struct V_44 * ) V_41 -> V_46 ;
struct V_8 * V_9 = F_32 ( V_23 ) ;
V_43 -> V_47 . V_48 . V_49 [ 0 ] = V_9 [ V_45 -> V_50 ] . V_51 ;
return 0 ;
}
static int F_33 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_22 * V_23 = F_31 ( V_41 ) ;
struct V_44 * V_45 = (struct V_44 * ) V_41 -> V_46 ;
struct V_8 * V_9 = F_32 ( V_23 ) ;
int V_19 = 0 ;
if ( V_43 -> V_47 . V_48 . V_49 [ 0 ] == V_9 [ V_45 -> V_50 ] . V_51 )
return 0 ;
if ( V_43 -> V_47 . V_48 . V_49 [ 0 ] >= V_52 )
return - V_53 ;
F_16 ( & V_9 [ V_45 -> V_50 ] . V_20 ) ;
if ( V_9 [ V_45 -> V_50 ] . V_21 || V_9 [ V_45 -> V_50 ] . V_54 )
V_19 = - V_55 ;
else
V_9 [ V_45 -> V_50 ] . V_51 = V_43 -> V_47 . V_48 . V_49 [ 0 ] ;
F_18 ( & V_9 [ V_45 -> V_50 ] . V_20 ) ;
return V_19 ;
}
static struct V_56 const * F_34 ( struct V_8 * V_9 ,
int type )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_9 -> V_57 ; V_27 ++ )
if ( V_9 -> V_58 [ V_27 ] . type == type )
return & V_9 -> V_58 [ V_27 ] ;
return NULL ;
}
static unsigned int F_35 ( struct V_56 const * V_58 ,
unsigned int V_59 )
{
if ( F_36 ( ! V_58 ) )
return V_59 ;
switch ( V_58 -> type ) {
case V_60 :
return V_58 -> V_61 + ( V_59 * 3 ) ;
case V_62 :
return V_58 -> V_61 + ( V_59 * 2 ) ;
case V_63 :
return V_58 -> V_61 + ( V_59 * 2 ) ;
case V_64 :
return V_58 -> V_61 + ( V_59 * 2 ) ;
case V_65 :
return V_58 -> V_61 + ( V_59 * 2 ) ;
default:
F_37 ( 1 , L_9 ) ;
return V_59 ;
}
}
static void F_38 ( struct V_8 * V_9 )
{
T_5 V_66 [ 4 ] ;
int V_19 ;
V_19 = F_39 ( V_9 -> V_67 , V_9 -> V_61 + V_68 ,
V_66 , sizeof( V_66 ) ) ;
if ( V_19 ) {
F_21 ( V_9 , L_10 , V_19 ) ;
return;
}
F_40 ( V_9 , L_11 ,
F_41 ( V_66 [ 0 ] ) ,
F_41 ( V_66 [ 1 ] ) ,
F_41 ( V_66 [ 2 ] ) ,
F_41 ( V_66 [ 3 ] ) ) ;
}
static inline struct V_69 * F_42 ( struct V_70 * V_71 )
{
return F_43 ( V_71 , struct V_69 , V_72 ) ;
}
static int F_44 ( struct V_40 * V_73 ,
struct V_74 * V_75 )
{
struct V_70 * V_72 =
(struct V_70 * ) V_73 -> V_46 ;
struct V_69 * V_76 = F_42 ( V_72 ) ;
V_75 -> type = V_77 ;
V_75 -> V_16 = V_76 -> V_3 ;
return 0 ;
}
static int F_45 ( struct V_69 * V_76 ,
const void * V_6 , T_1 V_3 )
{
struct V_78 * V_79 = & V_76 -> V_79 ;
const struct V_56 * V_58 ;
struct V_8 * V_9 = V_76 -> V_9 ;
void * V_66 ;
int V_19 ;
unsigned int V_80 ;
V_58 = F_34 ( V_9 , V_79 -> type ) ;
if ( ! V_58 ) {
F_21 ( V_9 , L_12 ,
V_79 -> type ) ;
return - V_53 ;
}
V_80 = V_76 -> V_79 . V_61 + V_76 -> V_59 ;
V_80 = F_35 ( V_58 , V_80 ) ;
V_66 = F_46 ( V_6 , V_3 , V_7 | V_81 ) ;
if ( ! V_66 )
return - V_82 ;
V_19 = F_47 ( V_9 -> V_67 , V_80 , V_66 ,
V_3 ) ;
if ( V_19 ) {
F_21 ( V_9 , L_13 ,
V_3 , V_80 , V_19 ) ;
F_10 ( V_66 ) ;
return V_19 ;
}
F_40 ( V_9 , L_14 , V_3 , V_80 ) ;
F_10 ( V_66 ) ;
return 0 ;
}
static int F_48 ( struct V_40 * V_73 ,
struct V_42 * V_43 )
{
struct V_70 * V_72 =
(struct V_70 * ) V_73 -> V_46 ;
struct V_69 * V_76 = F_42 ( V_72 ) ;
char * V_83 = V_43 -> V_47 . V_84 . V_85 ;
int V_19 = 0 ;
F_16 ( & V_76 -> V_9 -> V_20 ) ;
memcpy ( V_76 -> V_86 , V_83 , V_76 -> V_3 ) ;
V_76 -> V_87 = 1 ;
if ( V_76 -> V_88 && V_76 -> V_9 -> V_34 )
V_19 = F_45 ( V_76 , V_83 , V_76 -> V_3 ) ;
F_18 ( & V_76 -> V_9 -> V_20 ) ;
return V_19 ;
}
static int F_49 ( struct V_40 * V_73 ,
const unsigned int T_3 * V_84 , unsigned int V_89 )
{
struct V_70 * V_72 =
(struct V_70 * ) V_73 -> V_46 ;
struct V_69 * V_76 = F_42 ( V_72 ) ;
int V_19 = 0 ;
F_16 ( & V_76 -> V_9 -> V_20 ) ;
if ( F_50 ( V_76 -> V_86 , V_84 , V_89 ) ) {
V_19 = - V_90 ;
} else {
V_76 -> V_87 = 1 ;
if ( V_76 -> V_88 && V_76 -> V_9 -> V_34 )
V_19 = F_45 ( V_76 , V_76 -> V_86 , V_89 ) ;
}
F_18 ( & V_76 -> V_9 -> V_20 ) ;
return V_19 ;
}
static int F_51 ( struct V_69 * V_76 ,
void * V_6 , T_1 V_3 )
{
struct V_78 * V_79 = & V_76 -> V_79 ;
const struct V_56 * V_58 ;
struct V_8 * V_9 = V_76 -> V_9 ;
void * V_66 ;
int V_19 ;
unsigned int V_80 ;
V_58 = F_34 ( V_9 , V_79 -> type ) ;
if ( ! V_58 ) {
F_21 ( V_9 , L_12 ,
V_79 -> type ) ;
return - V_53 ;
}
V_80 = V_76 -> V_79 . V_61 + V_76 -> V_59 ;
V_80 = F_35 ( V_58 , V_80 ) ;
V_66 = F_22 ( V_3 , V_7 | V_81 ) ;
if ( ! V_66 )
return - V_82 ;
V_19 = F_39 ( V_9 -> V_67 , V_80 , V_66 , V_3 ) ;
if ( V_19 ) {
F_21 ( V_9 , L_15 ,
V_3 , V_80 , V_19 ) ;
F_10 ( V_66 ) ;
return V_19 ;
}
F_40 ( V_9 , L_16 , V_3 , V_80 ) ;
memcpy ( V_6 , V_66 , V_3 ) ;
F_10 ( V_66 ) ;
return 0 ;
}
static int F_52 ( struct V_40 * V_73 ,
struct V_42 * V_43 )
{
struct V_70 * V_72 =
(struct V_70 * ) V_73 -> V_46 ;
struct V_69 * V_76 = F_42 ( V_72 ) ;
char * V_83 = V_43 -> V_47 . V_84 . V_85 ;
int V_19 = 0 ;
F_16 ( & V_76 -> V_9 -> V_20 ) ;
if ( V_76 -> V_91 & V_92 ) {
if ( V_76 -> V_88 && V_76 -> V_9 -> V_34 )
V_19 = F_51 ( V_76 , V_83 , V_76 -> V_3 ) ;
else
V_19 = - V_93 ;
} else {
if ( ! V_76 -> V_91 && V_76 -> V_88 && V_76 -> V_9 -> V_34 )
V_19 = F_51 ( V_76 , V_76 -> V_86 , V_76 -> V_3 ) ;
memcpy ( V_83 , V_76 -> V_86 , V_76 -> V_3 ) ;
}
F_18 ( & V_76 -> V_9 -> V_20 ) ;
return V_19 ;
}
static int F_53 ( struct V_40 * V_73 ,
unsigned int T_3 * V_84 , unsigned int V_89 )
{
struct V_70 * V_72 =
(struct V_70 * ) V_73 -> V_46 ;
struct V_69 * V_76 = F_42 ( V_72 ) ;
int V_19 = 0 ;
F_16 ( & V_76 -> V_9 -> V_20 ) ;
if ( V_76 -> V_91 & V_92 ) {
if ( V_76 -> V_88 && V_76 -> V_9 -> V_34 )
V_19 = F_51 ( V_76 , V_76 -> V_86 , V_89 ) ;
else
V_19 = - V_93 ;
} else {
if ( ! V_76 -> V_91 && V_76 -> V_88 && V_76 -> V_9 -> V_34 )
V_19 = F_51 ( V_76 , V_76 -> V_86 , V_89 ) ;
}
if ( ! V_19 && F_54 ( V_84 , V_76 -> V_86 , V_89 ) )
V_19 = - V_90 ;
F_18 ( & V_76 -> V_9 -> V_20 ) ;
return V_19 ;
}
static unsigned int F_55 ( unsigned int V_94 , unsigned int V_3 )
{
unsigned int V_95 , V_96 , V_97 , V_98 ;
if ( V_3 > V_99 ) {
V_96 = V_100 ;
V_97 = V_101 ;
V_98 = V_102 ;
V_95 = V_103 ;
} else {
V_96 = V_104 ;
V_97 = V_105 ;
V_98 = V_102 ;
V_95 = 0 ;
}
if ( V_94 ) {
if ( V_94 & V_106 )
V_95 |= V_96 ;
if ( V_94 & V_107 )
V_95 |= V_97 ;
if ( V_94 & V_92 )
V_95 |= V_98 ;
} else {
V_95 |= V_96 | V_97 | V_98 ;
}
return V_95 ;
}
static int F_56 ( struct V_8 * V_9 , struct V_69 * V_76 )
{
struct V_108 * V_41 ;
int V_19 ;
if ( ! V_76 || ! V_76 -> V_38 )
return - V_53 ;
V_41 = F_2 ( sizeof( * V_41 ) , V_7 ) ;
if ( ! V_41 )
return - V_82 ;
V_41 -> V_109 = V_110 ;
V_41 -> V_38 = V_76 -> V_38 ;
V_41 -> V_111 = F_44 ;
V_41 -> V_112 = F_52 ;
V_41 -> V_113 = F_48 ;
V_41 -> V_109 = V_110 ;
V_41 -> V_114 . V_115 = V_116 ;
V_41 -> V_46 = ( unsigned long ) & V_76 -> V_72 ;
V_76 -> V_72 . V_117 = V_76 -> V_3 ;
V_76 -> V_72 . V_112 = F_53 ;
V_76 -> V_72 . V_113 = F_49 ;
V_41 -> V_118 = F_55 ( V_76 -> V_91 , V_76 -> V_3 ) ;
V_19 = F_57 ( V_9 -> V_119 , V_41 , 1 ) ;
if ( V_19 < 0 )
goto V_120;
F_10 ( V_41 ) ;
V_76 -> V_41 = F_58 ( V_9 -> V_119 , V_76 -> V_38 ) ;
return 0 ;
V_120:
F_10 ( V_41 ) ;
return V_19 ;
}
static int F_59 ( struct V_8 * V_9 )
{
struct V_69 * V_76 ;
int V_19 ;
F_60 (ctl, &dsp->ctl_list, list) {
if ( ! V_76 -> V_88 || V_76 -> V_87 )
continue;
if ( V_76 -> V_91 & V_92 )
continue;
V_19 = F_51 ( V_76 , V_76 -> V_86 , V_76 -> V_3 ) ;
if ( V_19 < 0 )
return V_19 ;
}
return 0 ;
}
static int F_61 ( struct V_8 * V_9 )
{
struct V_69 * V_76 ;
int V_19 ;
F_60 (ctl, &dsp->ctl_list, list) {
if ( ! V_76 -> V_88 )
continue;
if ( V_76 -> V_87 && ! ( V_76 -> V_91 & V_92 ) ) {
V_19 = F_45 ( V_76 , V_76 -> V_86 , V_76 -> V_3 ) ;
if ( V_19 < 0 )
return V_19 ;
}
}
return 0 ;
}
static void F_62 ( struct V_121 * V_122 )
{
struct V_123 * V_124 = F_43 ( V_122 ,
struct V_123 ,
V_122 ) ;
F_56 ( V_124 -> V_9 , V_124 -> V_76 ) ;
F_10 ( V_124 ) ;
}
static void F_63 ( struct V_69 * V_76 )
{
F_10 ( V_76 -> V_86 ) ;
F_10 ( V_76 -> V_38 ) ;
F_10 ( V_76 ) ;
}
static int F_64 ( struct V_8 * V_9 ,
const struct V_78 * V_79 ,
unsigned int V_59 , unsigned int V_3 ,
const char * V_125 , unsigned int V_126 ,
unsigned int V_91 )
{
struct V_69 * V_76 ;
struct V_123 * V_124 ;
char V_38 [ V_127 ] ;
char * V_128 ;
int V_19 ;
if ( V_91 & V_129 )
return 0 ;
switch ( V_79 -> type ) {
case V_60 :
V_128 = L_17 ;
break;
case V_62 :
V_128 = L_18 ;
break;
case V_63 :
V_128 = L_19 ;
break;
case V_64 :
V_128 = L_20 ;
break;
case V_65 :
V_128 = L_21 ;
break;
default:
F_21 ( V_9 , L_22 , V_79 -> type ) ;
return - V_53 ;
}
switch ( V_9 -> V_130 ) {
case 0 :
case 1 :
snprintf ( V_38 , V_127 , L_23 ,
V_9 -> V_32 , V_128 , V_79 -> V_131 ) ;
break;
default:
V_19 = snprintf ( V_38 , V_127 ,
L_24 , V_9 -> V_32 , * V_128 ,
V_132 [ V_9 -> V_51 ] , V_79 -> V_131 ) ;
if ( V_125 ) {
int V_133 = V_127 - V_19 - 2 ;
int V_134 = 0 ;
if ( V_126 > V_133 )
V_134 = V_126 - V_133 ;
snprintf ( V_38 + V_19 ,
V_127 - V_19 , L_25 ,
V_126 - V_134 , V_125 + V_134 ) ;
}
break;
}
F_60 (ctl, &dsp->ctl_list, list) {
if ( ! strcmp ( V_76 -> V_38 , V_38 ) ) {
if ( ! V_76 -> V_88 )
V_76 -> V_88 = 1 ;
return 0 ;
}
}
V_76 = F_2 ( sizeof( * V_76 ) , V_7 ) ;
if ( ! V_76 )
return - V_82 ;
V_76 -> V_135 = V_132 [ V_9 -> V_51 ] ;
V_76 -> V_79 = * V_79 ;
V_76 -> V_38 = F_46 ( V_38 , strlen ( V_38 ) + 1 , V_7 ) ;
if ( ! V_76 -> V_38 ) {
V_19 = - V_82 ;
goto V_136;
}
V_76 -> V_88 = 1 ;
V_76 -> V_87 = 0 ;
V_76 -> V_137 . V_138 = F_52 ;
V_76 -> V_137 . V_139 = F_48 ;
V_76 -> V_9 = V_9 ;
V_76 -> V_91 = V_91 ;
V_76 -> V_59 = V_59 ;
V_76 -> V_3 = V_3 ;
V_76 -> V_86 = F_2 ( V_76 -> V_3 , V_7 ) ;
if ( ! V_76 -> V_86 ) {
V_19 = - V_82 ;
goto V_140;
}
F_65 ( & V_76 -> V_5 , & V_9 -> V_141 ) ;
V_124 = F_2 ( sizeof( * V_124 ) , V_7 ) ;
if ( ! V_124 ) {
V_19 = - V_82 ;
goto V_142;
}
V_124 -> V_9 = V_9 ;
V_124 -> V_76 = V_76 ;
F_66 ( & V_124 -> V_122 , F_62 ) ;
F_67 ( & V_124 -> V_122 ) ;
return 0 ;
V_142:
F_10 ( V_76 -> V_86 ) ;
V_140:
F_10 ( V_76 -> V_38 ) ;
V_136:
F_10 ( V_76 ) ;
return V_19 ;
}
static int F_68 ( int V_84 , const T_6 * * V_143 , const T_6 * * V_144 )
{
int V_145 ;
switch ( V_84 ) {
case 1 :
V_145 = * * V_143 ;
break;
case 2 :
V_145 = F_69 ( * ( ( V_146 * ) * V_143 ) ) ;
break;
default:
return 0 ;
}
if ( V_144 )
* V_144 = * V_143 + V_84 ;
* V_143 += ( ( V_145 + V_84 ) + 3 ) & ~ 0x03 ;
return V_145 ;
}
static int F_70 ( int V_84 , const T_6 * * V_143 )
{
int V_147 = 0 ;
switch ( V_84 ) {
case 2 :
V_147 = F_69 ( * ( ( V_146 * ) * V_143 ) ) ;
break;
case 4 :
V_147 = F_71 ( * ( ( V_148 * ) * V_143 ) ) ;
break;
default:
break;
}
* V_143 += V_84 ;
return V_147 ;
}
static inline void F_72 ( struct V_8 * V_9 , const T_6 * * V_85 ,
struct V_149 * V_150 )
{
const struct V_151 * V_152 ;
switch ( V_9 -> V_130 ) {
case 0 :
case 1 :
V_152 = ( const struct V_151 * ) * V_85 ;
* V_85 = V_152 -> V_85 ;
V_150 -> V_153 = F_71 ( V_152 -> V_153 ) ;
V_150 -> V_38 = V_152 -> V_38 ;
V_150 -> V_154 = strlen ( V_152 -> V_38 ) ;
V_150 -> V_155 = F_71 ( V_152 -> V_155 ) ;
break;
default:
V_150 -> V_153 = F_70 ( sizeof( V_152 -> V_153 ) , V_85 ) ;
V_150 -> V_154 = F_68 ( sizeof( T_6 ) , V_85 ,
& V_150 -> V_38 ) ;
F_68 ( sizeof( T_5 ) , V_85 , NULL ) ;
V_150 -> V_155 = F_70 ( sizeof( V_152 -> V_155 ) , V_85 ) ;
break;
}
F_40 ( V_9 , L_26 , V_150 -> V_153 ) ;
F_40 ( V_9 , L_27 , V_150 -> V_154 , V_150 -> V_38 ) ;
F_40 ( V_9 , L_28 , V_150 -> V_155 ) ;
}
static inline void F_73 ( struct V_8 * V_9 , const T_6 * * V_85 ,
struct V_156 * V_150 )
{
const struct V_157 * V_152 ;
const T_6 * V_11 ;
int V_145 ;
switch ( V_9 -> V_130 ) {
case 0 :
case 1 :
V_152 = ( const struct V_157 * ) * V_85 ;
* V_85 = * V_85 + sizeof( V_152 -> V_158 ) + F_71 ( V_152 -> V_158 . V_89 ) ;
V_150 -> V_59 = F_69 ( V_152 -> V_158 . V_59 ) ;
V_150 -> V_159 = F_69 ( V_152 -> V_158 . type ) ;
V_150 -> V_38 = V_152 -> V_38 ;
V_150 -> V_154 = strlen ( V_152 -> V_38 ) ;
V_150 -> V_160 = F_69 ( V_152 -> V_160 ) ;
V_150 -> V_91 = F_69 ( V_152 -> V_91 ) ;
V_150 -> V_3 = F_71 ( V_152 -> V_3 ) ;
break;
default:
V_11 = * V_85 ;
V_150 -> V_59 = F_70 ( sizeof( V_152 -> V_158 . V_59 ) , & V_11 ) ;
V_150 -> V_159 = F_70 ( sizeof( V_152 -> V_158 . type ) , & V_11 ) ;
V_145 = F_70 ( sizeof( V_152 -> V_158 . V_89 ) , & V_11 ) ;
V_150 -> V_154 = F_68 ( sizeof( T_6 ) , & V_11 ,
& V_150 -> V_38 ) ;
F_68 ( sizeof( T_6 ) , & V_11 , NULL ) ;
F_68 ( sizeof( T_5 ) , & V_11 , NULL ) ;
V_150 -> V_160 = F_70 ( sizeof( V_152 -> V_160 ) , & V_11 ) ;
V_150 -> V_91 = F_70 ( sizeof( V_152 -> V_91 ) , & V_11 ) ;
V_150 -> V_3 = F_70 ( sizeof( V_152 -> V_3 ) , & V_11 ) ;
* V_85 = * V_85 + sizeof( V_152 -> V_158 ) + V_145 ;
break;
}
F_40 ( V_9 , L_29 , V_150 -> V_159 ) ;
F_40 ( V_9 , L_30 , V_150 -> V_59 ) ;
F_40 ( V_9 , L_31 , V_150 -> V_154 , V_150 -> V_38 ) ;
F_40 ( V_9 , L_32 , V_150 -> V_91 ) ;
F_40 ( V_9 , L_33 , V_150 -> V_160 ) ;
F_40 ( V_9 , L_34 , V_150 -> V_3 ) ;
}
static int F_74 ( struct V_8 * V_9 ,
const struct V_161 * V_162 )
{
struct V_78 V_79 = {} ;
struct V_149 V_163 ;
struct V_156 V_164 ;
const T_6 * V_85 = V_162 -> V_85 ;
int V_27 , V_19 ;
F_72 ( V_9 , & V_85 , & V_163 ) ;
for ( V_27 = 0 ; V_27 < V_163 . V_155 ; V_27 ++ ) {
F_73 ( V_9 , & V_85 , & V_164 ) ;
switch ( V_164 . V_160 ) {
case V_77 :
break;
default:
F_21 ( V_9 , L_35 ,
V_164 . V_160 ) ;
return - V_53 ;
}
V_79 . type = V_164 . V_159 ;
V_79 . V_131 = V_163 . V_153 ;
V_19 = F_64 ( V_9 , & V_79 ,
V_164 . V_59 ,
V_164 . V_3 ,
V_164 . V_38 ,
V_164 . V_154 ,
V_164 . V_91 ) ;
if ( V_19 < 0 )
F_21 ( V_9 , L_36 ,
V_164 . V_154 , V_164 . V_38 , V_19 ) ;
}
return 0 ;
}
static int F_75 ( struct V_8 * V_9 )
{
F_76 ( V_165 ) ;
const struct V_166 * V_166 ;
struct V_67 * V_67 = V_9 -> V_67 ;
unsigned int V_143 = 0 ;
const struct V_167 * V_168 ;
const struct V_169 * V_170 ;
const struct V_171 * V_172 ;
const struct V_173 * V_174 ;
const struct V_161 * V_162 ;
const struct V_56 * V_58 ;
const char * V_128 ;
char * V_14 , * V_175 ;
struct V_1 * V_6 ;
unsigned int V_80 ;
int V_176 = 0 ;
int V_19 , V_59 , type , V_177 ;
V_14 = F_2 ( V_31 , V_7 ) ;
if ( V_14 == NULL )
return - V_82 ;
snprintf ( V_14 , V_31 , L_37 , V_9 -> V_178 , V_9 -> V_32 ,
V_179 [ V_9 -> V_51 ] . V_14 ) ;
V_14 [ V_31 - 1 ] = '\0' ;
V_19 = F_77 ( & V_166 , V_14 , V_9 -> V_180 ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_38 , V_14 ) ;
goto V_95;
}
V_19 = - V_53 ;
V_143 = sizeof( * V_168 ) + sizeof( * V_170 ) + sizeof( * V_174 ) ;
if ( V_143 >= V_166 -> V_89 ) {
F_21 ( V_9 , L_39 ,
V_14 , V_166 -> V_89 ) ;
goto V_181;
}
V_168 = ( void * ) & V_166 -> V_85 [ 0 ] ;
if ( memcmp ( & V_168 -> V_182 [ 0 ] , L_40 , 4 ) != 0 ) {
F_21 ( V_9 , L_41 , V_14 ) ;
goto V_181;
}
switch ( V_168 -> V_183 ) {
case 0 :
F_78 ( V_9 , L_42 ,
V_14 , V_168 -> V_183 ) ;
break;
case 1 :
case 2 :
break;
default:
F_21 ( V_9 , L_43 ,
V_14 , V_168 -> V_183 ) ;
goto V_181;
}
F_79 ( V_9 , L_44 , V_168 -> V_183 ) ;
V_9 -> V_130 = V_168 -> V_183 ;
if ( V_168 -> V_184 != V_9 -> type ) {
F_21 ( V_9 , L_45 ,
V_14 , V_168 -> V_184 , V_9 -> type ) ;
goto V_181;
}
switch ( V_9 -> type ) {
case V_185 :
V_143 = sizeof( * V_168 ) + sizeof( * V_170 ) + sizeof( * V_174 ) ;
V_170 = ( void * ) & ( V_168 [ 1 ] ) ;
V_174 = ( void * ) & ( V_170 [ 1 ] ) ;
V_177 = sizeof( * V_170 ) ;
F_40 ( V_9 , L_46 ,
V_14 , F_71 ( V_170 -> V_186 ) ,
F_71 ( V_170 -> V_187 ) ,
F_71 ( V_170 -> V_188 ) ) ;
break;
case V_189 :
V_143 = sizeof( * V_168 ) + sizeof( * V_172 ) + sizeof( * V_174 ) ;
V_172 = ( void * ) & ( V_168 [ 1 ] ) ;
V_174 = ( void * ) & ( V_172 [ 1 ] ) ;
V_177 = sizeof( * V_172 ) ;
F_40 ( V_9 , L_47 ,
V_14 , F_71 ( V_172 -> V_190 ) ,
F_71 ( V_172 -> V_191 ) ,
F_71 ( V_172 -> V_187 ) ,
F_71 ( V_172 -> V_188 ) ) ;
break;
default:
F_37 ( 1 , L_48 ) ;
goto V_181;
}
if ( F_71 ( V_168 -> V_3 ) != sizeof( * V_168 ) +
V_177 + sizeof( * V_174 ) ) {
F_21 ( V_9 , L_49 ,
V_14 , F_71 ( V_168 -> V_3 ) ) ;
goto V_181;
}
F_40 ( V_9 , L_50 , V_14 ,
F_80 ( V_174 -> V_192 ) ) ;
while ( V_143 < V_166 -> V_89 &&
V_143 - V_166 -> V_89 > sizeof( * V_162 ) ) {
V_162 = ( void * ) & ( V_166 -> V_85 [ V_143 ] ) ;
V_128 = L_51 ;
V_80 = 0 ;
V_175 = NULL ;
V_59 = F_71 ( V_162 -> V_59 ) & 0xffffff ;
type = F_81 ( V_162 -> type ) & 0xff ;
V_58 = F_34 ( V_9 , type ) ;
switch ( type ) {
case V_193 :
V_128 = L_52 ;
V_175 = F_2 ( F_71 ( V_162 -> V_3 ) + 1 ,
V_7 ) ;
break;
case V_194 :
V_128 = L_53 ;
V_19 = F_74 ( V_9 , V_162 ) ;
if ( V_19 != 0 )
goto V_181;
break;
case V_195 :
V_128 = L_54 ;
V_175 = F_2 ( F_71 ( V_162 -> V_3 ) + 1 ,
V_7 ) ;
break;
case V_196 :
V_128 = L_55 ;
V_80 = V_59 ;
break;
case V_60 :
V_128 = L_17 ;
V_80 = F_35 ( V_58 , V_59 ) ;
break;
case V_62 :
V_128 = L_18 ;
V_80 = F_35 ( V_58 , V_59 ) ;
break;
case V_63 :
V_128 = L_19 ;
V_80 = F_35 ( V_58 , V_59 ) ;
break;
case V_64 :
V_128 = L_20 ;
V_80 = F_35 ( V_58 , V_59 ) ;
break;
case V_65 :
V_128 = L_21 ;
V_80 = F_35 ( V_58 , V_59 ) ;
break;
default:
F_78 ( V_9 ,
L_56 ,
V_14 , V_176 , type , V_143 , V_143 ) ;
break;
}
F_40 ( V_9 , L_57 , V_14 ,
V_176 , F_71 ( V_162 -> V_3 ) , V_59 ,
V_128 ) ;
if ( V_175 ) {
memcpy ( V_175 , V_162 -> V_85 , F_71 ( V_162 -> V_3 ) ) ;
F_79 ( V_9 , L_58 , V_14 , V_175 ) ;
F_10 ( V_175 ) ;
}
if ( V_80 ) {
V_6 = F_1 ( V_162 -> V_85 ,
F_71 ( V_162 -> V_3 ) ,
& V_165 ) ;
if ( ! V_6 ) {
F_21 ( V_9 , L_59 ) ;
V_19 = - V_82 ;
goto V_181;
}
V_19 = F_82 ( V_67 , V_80 , V_6 -> V_6 ,
F_71 ( V_162 -> V_3 ) ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 ,
L_60 ,
V_14 , V_176 ,
F_71 ( V_162 -> V_3 ) , V_59 ,
V_128 , V_19 ) ;
goto V_181;
}
}
V_143 += F_71 ( V_162 -> V_3 ) + sizeof( * V_162 ) ;
V_176 ++ ;
}
V_19 = F_83 ( V_67 ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_61 , V_19 ) ;
goto V_181;
}
if ( V_143 > V_166 -> V_89 )
F_78 ( V_9 , L_62 ,
V_14 , V_176 , V_143 - V_166 -> V_89 ) ;
F_11 ( V_9 , V_14 ) ;
V_181:
F_83 ( V_67 ) ;
F_6 ( & V_165 ) ;
F_84 ( V_166 ) ;
V_95:
F_10 ( V_14 ) ;
return V_19 ;
}
static void F_85 ( struct V_8 * V_9 ,
const struct V_78 * V_79 )
{
struct V_69 * V_76 ;
F_60 (ctl, &dsp->ctl_list, list) {
if ( V_76 -> V_135 == V_132 [ V_9 -> V_51 ] &&
V_79 -> V_131 == V_76 -> V_79 . V_131 &&
V_79 -> type == V_76 -> V_79 . type ) {
V_76 -> V_79 . V_61 = V_79 -> V_61 ;
}
}
}
static void * F_86 ( struct V_8 * V_9 , T_1 V_197 ,
unsigned int V_143 , unsigned int V_3 )
{
void * V_131 ;
int V_19 ;
T_7 V_147 ;
if ( V_197 == 0 ) {
F_21 ( V_9 , L_63 ) ;
return F_87 ( - V_53 ) ;
}
if ( V_197 > 1024 ) {
F_21 ( V_9 , L_64 , V_197 ) ;
return F_87 ( - V_53 ) ;
}
V_19 = F_39 ( V_9 -> V_67 , V_143 + V_3 , & V_147 , sizeof( V_147 ) ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_65 ,
V_19 ) ;
return F_87 ( V_19 ) ;
}
if ( F_81 ( V_147 ) != 0xbedead )
F_78 ( V_9 , L_66 ,
V_143 + V_3 , F_81 ( V_147 ) ) ;
V_131 = F_2 ( V_3 * 2 , V_7 | V_81 ) ;
if ( ! V_131 )
return F_87 ( - V_82 ) ;
V_19 = F_39 ( V_9 -> V_67 , V_143 , V_131 , V_3 * 2 ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_67 , V_19 ) ;
F_10 ( V_131 ) ;
return F_87 ( V_19 ) ;
}
return V_131 ;
}
static struct V_78 *
F_88 ( struct V_8 * V_9 , int type , unsigned int V_153 )
{
struct V_78 * V_79 ;
F_60 (alg_region, &dsp->alg_regions, list) {
if ( V_153 == V_79 -> V_131 && type == V_79 -> type )
return V_79 ;
}
return NULL ;
}
static struct V_78 * F_89 ( struct V_8 * V_9 ,
int type , T_7 V_153 ,
T_7 V_61 )
{
struct V_78 * V_79 ;
V_79 = F_2 ( sizeof( * V_79 ) , V_7 ) ;
if ( ! V_79 )
return F_87 ( - V_82 ) ;
V_79 -> type = type ;
V_79 -> V_131 = F_81 ( V_153 ) ;
V_79 -> V_61 = F_81 ( V_61 ) ;
F_5 ( & V_79 -> V_5 , & V_9 -> V_198 ) ;
if ( V_9 -> V_130 > 0 )
F_85 ( V_9 , V_79 ) ;
return V_79 ;
}
static void F_90 ( struct V_8 * V_9 )
{
struct V_78 * V_79 ;
while ( ! F_7 ( & V_9 -> V_198 ) ) {
V_79 = F_8 ( & V_9 -> V_198 ,
struct V_78 ,
V_5 ) ;
F_9 ( & V_79 -> V_5 ) ;
F_10 ( V_79 ) ;
}
}
static int F_91 ( struct V_8 * V_9 )
{
struct V_199 V_200 ;
struct V_201 * V_202 ;
struct V_78 * V_79 ;
const struct V_56 * V_58 ;
unsigned int V_143 , V_3 ;
T_1 V_197 ;
int V_27 , V_19 ;
V_58 = F_34 ( V_9 , V_62 ) ;
if ( F_36 ( ! V_58 ) )
return - V_53 ;
V_19 = F_39 ( V_9 -> V_67 , V_58 -> V_61 , & V_200 ,
sizeof( V_200 ) ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_68 ,
V_19 ) ;
return V_19 ;
}
V_197 = F_81 ( V_200 . V_197 ) ;
V_9 -> V_35 = F_81 ( V_200 . V_51 . V_153 ) ;
F_79 ( V_9 , L_69 ,
V_9 -> V_35 ,
( F_81 ( V_200 . V_51 . V_183 ) & 0xff0000 ) >> 16 ,
( F_81 ( V_200 . V_51 . V_183 ) & 0xff00 ) >> 8 ,
F_81 ( V_200 . V_51 . V_183 ) & 0xff ,
V_197 ) ;
V_79 = F_89 ( V_9 , V_65 ,
V_200 . V_51 . V_153 , V_200 . V_188 ) ;
if ( F_92 ( V_79 ) )
return F_93 ( V_79 ) ;
V_79 = F_89 ( V_9 , V_62 ,
V_200 . V_51 . V_153 , V_200 . V_186 ) ;
if ( F_92 ( V_79 ) )
return F_93 ( V_79 ) ;
V_143 = sizeof( V_200 ) / 2 ;
V_3 = ( sizeof( * V_202 ) * V_197 ) / 2 ;
V_202 = F_86 ( V_9 , V_197 , V_58 -> V_61 + V_143 , V_3 ) ;
if ( F_92 ( V_202 ) )
return F_93 ( V_202 ) ;
for ( V_27 = 0 ; V_27 < V_197 ; V_27 ++ ) {
F_79 ( V_9 , L_70 ,
V_27 , F_81 ( V_202 [ V_27 ] . V_131 . V_153 ) ,
( F_81 ( V_202 [ V_27 ] . V_131 . V_183 ) & 0xff0000 ) >> 16 ,
( F_81 ( V_202 [ V_27 ] . V_131 . V_183 ) & 0xff00 ) >> 8 ,
F_81 ( V_202 [ V_27 ] . V_131 . V_183 ) & 0xff ,
F_81 ( V_202 [ V_27 ] . V_186 ) ,
F_81 ( V_202 [ V_27 ] . V_188 ) ) ;
V_79 = F_89 ( V_9 , V_62 ,
V_202 [ V_27 ] . V_131 . V_153 ,
V_202 [ V_27 ] . V_186 ) ;
if ( F_92 ( V_79 ) ) {
V_19 = F_93 ( V_79 ) ;
goto V_95;
}
if ( V_9 -> V_130 == 0 ) {
if ( V_27 + 1 < V_197 ) {
V_3 = F_81 ( V_202 [ V_27 + 1 ] . V_186 ) ;
V_3 -= F_81 ( V_202 [ V_27 ] . V_186 ) ;
V_3 *= 4 ;
F_64 ( V_9 , V_79 , 0 ,
V_3 , NULL , 0 , 0 ) ;
} else {
F_78 ( V_9 , L_71 ,
F_81 ( V_202 [ V_27 ] . V_131 . V_153 ) ) ;
}
}
V_79 = F_89 ( V_9 , V_65 ,
V_202 [ V_27 ] . V_131 . V_153 ,
V_202 [ V_27 ] . V_188 ) ;
if ( F_92 ( V_79 ) ) {
V_19 = F_93 ( V_79 ) ;
goto V_95;
}
if ( V_9 -> V_130 == 0 ) {
if ( V_27 + 1 < V_197 ) {
V_3 = F_81 ( V_202 [ V_27 + 1 ] . V_188 ) ;
V_3 -= F_81 ( V_202 [ V_27 ] . V_188 ) ;
V_3 *= 4 ;
F_64 ( V_9 , V_79 , 0 ,
V_3 , NULL , 0 , 0 ) ;
} else {
F_78 ( V_9 , L_72 ,
F_81 ( V_202 [ V_27 ] . V_131 . V_153 ) ) ;
}
}
}
V_95:
F_10 ( V_202 ) ;
return V_19 ;
}
static int F_94 ( struct V_8 * V_9 )
{
struct V_203 V_204 ;
struct V_205 * V_206 ;
struct V_78 * V_79 ;
const struct V_56 * V_58 ;
unsigned int V_143 , V_3 ;
T_1 V_197 ;
int V_27 , V_19 ;
V_58 = F_34 ( V_9 , V_63 ) ;
if ( F_36 ( ! V_58 ) )
return - V_53 ;
V_19 = F_39 ( V_9 -> V_67 , V_58 -> V_61 , & V_204 ,
sizeof( V_204 ) ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_68 ,
V_19 ) ;
return V_19 ;
}
V_197 = F_81 ( V_204 . V_197 ) ;
V_9 -> V_35 = F_81 ( V_204 . V_51 . V_153 ) ;
V_9 -> V_36 = F_81 ( V_204 . V_51 . V_183 ) ;
F_79 ( V_9 , L_69 ,
V_9 -> V_35 ,
( V_9 -> V_36 & 0xff0000 ) >> 16 ,
( V_9 -> V_36 & 0xff00 ) >> 8 ,
V_9 -> V_36 & 0xff ,
V_197 ) ;
V_79 = F_89 ( V_9 , V_63 ,
V_204 . V_51 . V_153 , V_204 . V_190 ) ;
if ( F_92 ( V_79 ) )
return F_93 ( V_79 ) ;
V_79 = F_89 ( V_9 , V_64 ,
V_204 . V_51 . V_153 , V_204 . V_191 ) ;
if ( F_92 ( V_79 ) )
return F_93 ( V_79 ) ;
V_79 = F_89 ( V_9 , V_207 ,
V_204 . V_51 . V_153 , V_204 . V_188 ) ;
if ( F_92 ( V_79 ) )
return F_93 ( V_79 ) ;
V_143 = sizeof( V_204 ) / 2 ;
V_3 = ( sizeof( * V_206 ) * V_197 ) / 2 ;
V_206 = F_86 ( V_9 , V_197 , V_58 -> V_61 + V_143 , V_3 ) ;
if ( F_92 ( V_206 ) )
return F_93 ( V_206 ) ;
for ( V_27 = 0 ; V_27 < V_197 ; V_27 ++ ) {
F_79 ( V_9 ,
L_73 ,
V_27 , F_81 ( V_206 [ V_27 ] . V_131 . V_153 ) ,
( F_81 ( V_206 [ V_27 ] . V_131 . V_183 ) & 0xff0000 ) >> 16 ,
( F_81 ( V_206 [ V_27 ] . V_131 . V_183 ) & 0xff00 ) >> 8 ,
F_81 ( V_206 [ V_27 ] . V_131 . V_183 ) & 0xff ,
F_81 ( V_206 [ V_27 ] . V_190 ) ,
F_81 ( V_206 [ V_27 ] . V_191 ) ,
F_81 ( V_206 [ V_27 ] . V_188 ) ) ;
V_79 = F_89 ( V_9 , V_63 ,
V_206 [ V_27 ] . V_131 . V_153 ,
V_206 [ V_27 ] . V_190 ) ;
if ( F_92 ( V_79 ) ) {
V_19 = F_93 ( V_79 ) ;
goto V_95;
}
if ( V_9 -> V_130 == 0 ) {
if ( V_27 + 1 < V_197 ) {
V_3 = F_81 ( V_206 [ V_27 + 1 ] . V_190 ) ;
V_3 -= F_81 ( V_206 [ V_27 ] . V_190 ) ;
V_3 *= 4 ;
F_64 ( V_9 , V_79 , 0 ,
V_3 , NULL , 0 , 0 ) ;
} else {
F_78 ( V_9 , L_74 ,
F_81 ( V_206 [ V_27 ] . V_131 . V_153 ) ) ;
}
}
V_79 = F_89 ( V_9 , V_64 ,
V_206 [ V_27 ] . V_131 . V_153 ,
V_206 [ V_27 ] . V_191 ) ;
if ( F_92 ( V_79 ) ) {
V_19 = F_93 ( V_79 ) ;
goto V_95;
}
if ( V_9 -> V_130 == 0 ) {
if ( V_27 + 1 < V_197 ) {
V_3 = F_81 ( V_206 [ V_27 + 1 ] . V_191 ) ;
V_3 -= F_81 ( V_206 [ V_27 ] . V_191 ) ;
V_3 *= 4 ;
F_64 ( V_9 , V_79 , 0 ,
V_3 , NULL , 0 , 0 ) ;
} else {
F_78 ( V_9 , L_75 ,
F_81 ( V_206 [ V_27 ] . V_131 . V_153 ) ) ;
}
}
V_79 = F_89 ( V_9 , V_207 ,
V_206 [ V_27 ] . V_131 . V_153 ,
V_206 [ V_27 ] . V_188 ) ;
if ( F_92 ( V_79 ) ) {
V_19 = F_93 ( V_79 ) ;
goto V_95;
}
if ( V_9 -> V_130 == 0 ) {
if ( V_27 + 1 < V_197 ) {
V_3 = F_81 ( V_206 [ V_27 + 1 ] . V_188 ) ;
V_3 -= F_81 ( V_206 [ V_27 ] . V_188 ) ;
V_3 *= 4 ;
F_64 ( V_9 , V_79 , 0 ,
V_3 , NULL , 0 , 0 ) ;
} else {
F_78 ( V_9 , L_72 ,
F_81 ( V_206 [ V_27 ] . V_131 . V_153 ) ) ;
}
}
}
V_95:
F_10 ( V_206 ) ;
return V_19 ;
}
static int F_95 ( struct V_8 * V_9 )
{
F_76 ( V_165 ) ;
struct V_67 * V_67 = V_9 -> V_67 ;
struct V_208 * V_158 ;
struct V_209 * V_150 ;
const struct V_166 * V_166 ;
const struct V_56 * V_58 ;
struct V_78 * V_79 ;
const char * V_128 ;
int V_19 , V_143 , V_210 , type , V_59 , V_80 ;
char * V_14 ;
struct V_1 * V_6 ;
V_14 = F_2 ( V_31 , V_7 ) ;
if ( V_14 == NULL )
return - V_82 ;
snprintf ( V_14 , V_31 , L_76 , V_9 -> V_178 , V_9 -> V_32 ,
V_179 [ V_9 -> V_51 ] . V_14 ) ;
V_14 [ V_31 - 1 ] = '\0' ;
V_19 = F_77 ( & V_166 , V_14 , V_9 -> V_180 ) ;
if ( V_19 != 0 ) {
F_78 ( V_9 , L_38 , V_14 ) ;
V_19 = 0 ;
goto V_95;
}
V_19 = - V_53 ;
if ( sizeof( * V_158 ) >= V_166 -> V_89 ) {
F_21 ( V_9 , L_39 ,
V_14 , V_166 -> V_89 ) ;
goto V_181;
}
V_158 = ( void * ) & V_166 -> V_85 [ 0 ] ;
if ( memcmp ( V_158 -> V_182 , L_77 , 4 ) != 0 ) {
F_21 ( V_9 , L_41 , V_14 ) ;
goto V_181;
}
switch ( F_81 ( V_158 -> V_211 ) & 0xff ) {
case 1 :
break;
default:
F_21 ( V_9 , L_78 ,
V_14 , F_81 ( V_158 -> V_211 ) & 0xff ) ;
V_19 = - V_53 ;
goto V_181;
}
F_40 ( V_9 , L_79 , V_14 ,
( F_71 ( V_158 -> V_183 ) >> 16 ) & 0xff ,
( F_71 ( V_158 -> V_183 ) >> 8 ) & 0xff ,
F_71 ( V_158 -> V_183 ) & 0xff ) ;
V_143 = F_71 ( V_158 -> V_3 ) ;
V_210 = 0 ;
while ( V_143 < V_166 -> V_89 &&
V_143 - V_166 -> V_89 > sizeof( * V_150 ) ) {
V_150 = ( void * ) ( & V_166 -> V_85 [ V_143 ] ) ;
type = F_69 ( V_150 -> type ) ;
V_59 = F_69 ( V_150 -> V_59 ) ;
F_40 ( V_9 , L_80 ,
V_14 , V_210 , F_71 ( V_150 -> V_153 ) ,
( F_71 ( V_150 -> V_183 ) >> 16 ) & 0xff ,
( F_71 ( V_150 -> V_183 ) >> 8 ) & 0xff ,
F_71 ( V_150 -> V_183 ) & 0xff ) ;
F_40 ( V_9 , L_81 ,
V_14 , V_210 , F_71 ( V_150 -> V_3 ) , V_59 , type ) ;
V_80 = 0 ;
V_128 = L_51 ;
switch ( type ) {
case ( V_193 << 8 ) :
case ( V_195 << 8 ) :
break;
case ( V_196 << 8 ) :
if ( F_71 ( V_150 -> V_153 ) == V_9 -> V_35 &&
V_59 == 0 ) {
V_128 = L_82 ;
V_58 = F_34 ( V_9 , type ) ;
if ( ! V_58 ) {
F_21 ( V_9 , L_83 ) ;
break;
}
V_80 = F_35 ( V_58 , 0 ) ;
} else {
V_128 = L_84 ;
V_80 = V_59 ;
}
break;
case V_62 :
case V_65 :
case V_63 :
case V_64 :
F_40 ( V_9 , L_85 ,
V_14 , V_210 , F_71 ( V_150 -> V_3 ) ,
type , F_71 ( V_150 -> V_153 ) ) ;
V_58 = F_34 ( V_9 , type ) ;
if ( ! V_58 ) {
F_21 ( V_9 , L_12 , type ) ;
break;
}
V_79 = F_88 ( V_9 , type ,
F_71 ( V_150 -> V_153 ) ) ;
if ( V_79 ) {
V_80 = V_79 -> V_61 ;
V_80 = F_35 ( V_58 , V_80 ) ;
V_80 += V_59 ;
} else {
F_21 ( V_9 , L_86 ,
type , F_71 ( V_150 -> V_153 ) ) ;
}
break;
default:
F_21 ( V_9 , L_87 ,
V_14 , V_210 , type , V_143 ) ;
break;
}
if ( V_80 ) {
V_6 = F_1 ( V_150 -> V_85 ,
F_71 ( V_150 -> V_3 ) ,
& V_165 ) ;
if ( ! V_6 ) {
F_21 ( V_9 , L_59 ) ;
V_19 = - V_82 ;
goto V_181;
}
F_40 ( V_9 , L_88 ,
V_14 , V_210 , F_71 ( V_150 -> V_3 ) ,
V_80 ) ;
V_19 = F_82 ( V_67 , V_80 , V_6 -> V_6 ,
F_71 ( V_150 -> V_3 ) ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 ,
L_89 ,
V_14 , V_210 , V_80 , V_128 , V_19 ) ;
}
}
V_143 += ( F_71 ( V_150 -> V_3 ) + sizeof( * V_150 ) + 3 ) & ~ 0x03 ;
V_210 ++ ;
}
V_19 = F_83 ( V_67 ) ;
if ( V_19 != 0 )
F_21 ( V_9 , L_61 , V_19 ) ;
if ( V_143 > V_166 -> V_89 )
F_78 ( V_9 , L_62 ,
V_14 , V_210 , V_143 - V_166 -> V_89 ) ;
F_13 ( V_9 , V_14 ) ;
V_181:
F_83 ( V_67 ) ;
F_84 ( V_166 ) ;
F_6 ( & V_165 ) ;
V_95:
F_10 ( V_14 ) ;
return V_19 ;
}
int F_96 ( struct V_8 * V_9 )
{
F_97 ( & V_9 -> V_198 ) ;
F_98 ( & V_9 -> V_20 ) ;
return 0 ;
}
int F_99 ( struct V_212 * V_213 ,
struct V_40 * V_41 ,
int V_214 )
{
struct V_22 * V_23 = F_100 ( V_213 -> V_215 ) ;
struct V_8 * V_216 = F_32 ( V_23 ) ;
struct V_8 * V_9 = & V_216 [ V_213 -> V_217 ] ;
struct V_69 * V_76 ;
int V_19 ;
unsigned int V_147 ;
V_9 -> V_119 = V_23 -> V_28 . V_119 ;
F_16 ( & V_9 -> V_20 ) ;
switch ( V_214 ) {
case V_218 :
F_101 ( V_9 -> V_67 , V_9 -> V_61 + V_219 ,
V_220 , V_220 ) ;
if ( V_9 -> V_221 ) {
V_19 = F_102 ( V_9 -> V_67 , V_9 -> V_221 , & V_147 ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_90 ,
V_19 ) ;
goto V_222;
}
V_147 = ( V_147 & V_9 -> V_223 ) >> V_9 -> V_224 ;
V_19 = F_101 ( V_9 -> V_67 ,
V_9 -> V_61 + V_225 ,
V_226 , V_147 ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_91 ,
V_19 ) ;
goto V_222;
}
}
V_19 = F_75 ( V_9 ) ;
if ( V_19 != 0 )
goto V_227;
V_19 = F_91 ( V_9 ) ;
if ( V_19 != 0 )
goto V_227;
V_19 = F_95 ( V_9 ) ;
if ( V_19 != 0 )
goto V_227;
V_19 = F_59 ( V_9 ) ;
if ( V_19 != 0 )
goto V_227;
V_19 = F_61 ( V_9 ) ;
if ( V_19 != 0 )
goto V_227;
V_9 -> V_21 = true ;
F_101 ( V_9 -> V_67 , V_9 -> V_61 + V_219 ,
V_228 | V_229 ,
V_228 | V_229 ) ;
V_9 -> V_34 = true ;
break;
case V_230 :
V_9 -> V_34 = false ;
V_9 -> V_21 = false ;
F_101 ( V_9 -> V_67 , V_9 -> V_61 + V_219 ,
V_228 | V_229 , 0 ) ;
F_101 ( V_9 -> V_67 , V_9 -> V_61 + V_231 ,
V_232 , 0 ) ;
F_101 ( V_9 -> V_67 , V_9 -> V_61 + V_219 ,
V_220 , 0 ) ;
F_60 (ctl, &dsp->ctl_list, list)
V_76 -> V_88 = 0 ;
F_90 ( V_9 ) ;
break;
default:
break;
}
F_18 ( & V_9 -> V_20 ) ;
return 0 ;
V_227:
F_101 ( V_9 -> V_67 , V_9 -> V_61 + V_219 ,
V_220 , 0 ) ;
V_222:
F_18 ( & V_9 -> V_20 ) ;
return V_19 ;
}
static int F_103 ( struct V_8 * V_9 )
{
unsigned int V_147 ;
int V_19 , V_16 ;
V_19 = F_104 ( V_9 -> V_67 , V_9 -> V_61 + V_233 ,
V_234 , V_234 ) ;
if ( V_19 != 0 )
return V_19 ;
for ( V_16 = 0 ; V_16 < 10 ; ++ V_16 ) {
V_19 = F_102 ( V_9 -> V_67 , V_9 -> V_61 + V_235 , & V_147 ) ;
if ( V_19 != 0 )
return V_19 ;
if ( V_147 & V_236 )
break;
F_105 ( 250 , 500 ) ;
}
if ( ! ( V_147 & V_236 ) ) {
F_21 ( V_9 , L_92 ) ;
return - V_55 ;
}
F_40 ( V_9 , L_93 , V_16 ) ;
return 0 ;
}
static void F_106 ( struct V_121 * V_122 )
{
struct V_8 * V_9 = F_43 ( V_122 ,
struct V_8 ,
V_237 ) ;
int V_19 ;
F_16 ( & V_9 -> V_20 ) ;
V_19 = F_101 ( V_9 -> V_67 , V_9 -> V_61 + V_233 ,
V_238 , V_238 ) ;
if ( V_19 != 0 )
goto V_222;
V_19 = F_103 ( V_9 ) ;
if ( V_19 != 0 )
goto V_222;
V_19 = F_75 ( V_9 ) ;
if ( V_19 != 0 )
goto V_227;
V_19 = F_94 ( V_9 ) ;
if ( V_19 != 0 )
goto V_227;
V_19 = F_95 ( V_9 ) ;
if ( V_19 != 0 )
goto V_227;
V_19 = F_59 ( V_9 ) ;
if ( V_19 != 0 )
goto V_227;
V_9 -> V_21 = true ;
V_19 = F_101 ( V_9 -> V_67 , V_9 -> V_61 + V_233 ,
V_234 , 0 ) ;
if ( V_19 != 0 )
goto V_227;
F_18 ( & V_9 -> V_20 ) ;
return;
V_227:
F_101 ( V_9 -> V_67 , V_9 -> V_61 + V_233 ,
V_234 | V_239 | V_240 , 0 ) ;
V_222:
F_18 ( & V_9 -> V_20 ) ;
}
static void F_107 ( struct V_8 * V_9 , unsigned int V_241 )
{
int V_19 ;
V_19 = F_104 ( V_9 -> V_67 ,
V_9 -> V_61 + V_242 ,
V_243 ,
V_241 << V_244 ) ;
if ( V_19 != 0 )
F_21 ( V_9 , L_91 , V_19 ) ;
}
int F_108 ( struct V_212 * V_213 ,
struct V_40 * V_41 , int V_214 ,
unsigned int V_241 )
{
struct V_22 * V_23 = F_100 ( V_213 -> V_215 ) ;
struct V_8 * V_216 = F_32 ( V_23 ) ;
struct V_8 * V_9 = & V_216 [ V_213 -> V_217 ] ;
struct V_69 * V_76 ;
V_9 -> V_119 = V_23 -> V_28 . V_119 ;
switch ( V_214 ) {
case V_245 :
F_107 ( V_9 , V_241 ) ;
F_109 ( V_246 , & V_9 -> V_237 ) ;
break;
case V_230 :
F_14 ( V_9 ) ;
V_9 -> V_35 = 0 ;
V_9 -> V_36 = 0 ;
V_9 -> V_21 = false ;
F_101 ( V_9 -> V_67 , V_9 -> V_61 + V_233 ,
V_238 , 0 ) ;
F_60 (ctl, &dsp->ctl_list, list)
V_76 -> V_88 = 0 ;
F_90 ( V_9 ) ;
F_40 ( V_9 , L_94 ) ;
break;
default:
break;
}
return 0 ;
}
int F_110 ( struct V_212 * V_213 ,
struct V_40 * V_41 , int V_214 )
{
struct V_22 * V_23 = F_100 ( V_213 -> V_215 ) ;
struct V_8 * V_216 = F_32 ( V_23 ) ;
struct V_8 * V_9 = & V_216 [ V_213 -> V_217 ] ;
int V_19 ;
switch ( V_214 ) {
case V_218 :
F_111 ( & V_9 -> V_237 ) ;
if ( ! V_9 -> V_21 )
return - V_247 ;
V_19 = F_103 ( V_9 ) ;
if ( V_19 != 0 )
goto V_30;
V_19 = F_61 ( V_9 ) ;
if ( V_19 != 0 )
goto V_30;
V_19 = F_101 ( V_9 -> V_67 ,
V_9 -> V_61 + V_233 ,
V_239 | V_240 ,
V_239 | V_240 ) ;
if ( V_19 != 0 )
goto V_30;
V_9 -> V_34 = true ;
F_16 ( & V_9 -> V_20 ) ;
if ( V_179 [ V_9 -> V_51 ] . V_248 != 0 )
V_19 = F_112 ( V_9 ) ;
F_18 ( & V_9 -> V_20 ) ;
break;
case V_230 :
F_38 ( V_9 ) ;
F_16 ( & V_9 -> V_20 ) ;
V_9 -> V_34 = false ;
F_101 ( V_9 -> V_67 , V_9 -> V_61 + V_233 ,
V_239 | V_240 , 0 ) ;
F_113 ( V_9 -> V_67 , V_9 -> V_61 + V_249 , 0 ) ;
F_113 ( V_9 -> V_67 , V_9 -> V_61 + V_250 , 0 ) ;
F_113 ( V_9 -> V_67 , V_9 -> V_61 + V_251 , 0 ) ;
F_101 ( V_9 -> V_67 , V_9 -> V_61 + V_233 ,
V_234 , 0 ) ;
if ( V_179 [ V_9 -> V_51 ] . V_248 != 0 )
F_114 ( V_9 ) ;
F_18 ( & V_9 -> V_20 ) ;
F_40 ( V_9 , L_95 ) ;
break;
default:
break;
}
return 0 ;
V_30:
F_101 ( V_9 -> V_67 , V_9 -> V_61 + V_233 ,
V_234 | V_239 | V_240 , 0 ) ;
return V_19 ;
}
int F_115 ( struct V_8 * V_9 , struct V_22 * V_23 )
{
F_20 ( V_9 , V_23 ) ;
return F_116 ( V_23 ,
& V_252 [ V_9 -> V_32 - 1 ] ,
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
V_19 = F_101 ( V_9 -> V_67 , V_9 -> V_61 + V_233 ,
V_238 , 0 ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_96 , V_19 ) ;
return V_19 ;
}
F_97 ( & V_9 -> V_198 ) ;
F_97 ( & V_9 -> V_141 ) ;
F_66 ( & V_9 -> V_237 , F_106 ) ;
F_98 ( & V_9 -> V_20 ) ;
return 0 ;
}
void F_119 ( struct V_8 * V_9 )
{
struct V_69 * V_76 ;
while ( ! F_7 ( & V_9 -> V_141 ) ) {
V_76 = F_8 ( & V_9 -> V_141 , struct V_69 ,
V_5 ) ;
F_9 ( & V_76 -> V_5 ) ;
F_63 ( V_76 ) ;
}
}
static inline int F_120 ( struct V_253 * V_54 )
{
return V_54 -> V_6 != NULL ;
}
static int F_121 ( struct V_253 * V_54 )
{
if ( ! V_54 -> V_9 -> V_254 )
return - V_53 ;
V_54 -> V_6 = V_54 -> V_9 -> V_254 ;
V_54 -> V_6 -> V_54 = V_54 ;
return 0 ;
}
static void F_122 ( struct V_253 * V_54 )
{
if ( ! V_54 )
return;
if ( V_54 -> V_255 )
F_123 ( V_54 -> V_255 ) ;
if ( F_120 ( V_54 ) ) {
V_54 -> V_6 -> V_54 = NULL ;
V_54 -> V_6 = NULL ;
}
}
int F_124 ( struct V_8 * V_9 , struct V_256 * V_255 )
{
struct V_253 * V_54 ;
int V_19 = 0 ;
F_16 ( & V_9 -> V_20 ) ;
if ( V_179 [ V_9 -> V_51 ] . V_248 == 0 ) {
F_21 ( V_9 , L_97 ) ;
V_19 = - V_257 ;
goto V_95;
}
if ( V_179 [ V_9 -> V_51 ] . V_258 != V_255 -> V_259 ) {
F_21 ( V_9 , L_98 ) ;
V_19 = - V_53 ;
goto V_95;
}
if ( V_9 -> V_54 ) {
F_21 ( V_9 , L_99 ) ;
V_19 = - V_55 ;
goto V_95;
}
V_54 = F_2 ( sizeof( * V_54 ) , V_7 ) ;
if ( ! V_54 ) {
V_19 = - V_82 ;
goto V_95;
}
V_54 -> V_9 = V_9 ;
V_54 -> V_255 = V_255 ;
V_9 -> V_54 = V_54 ;
V_255 -> V_260 -> V_18 = V_54 ;
V_95:
F_18 ( & V_9 -> V_20 ) ;
return V_19 ;
}
int F_125 ( struct V_256 * V_255 )
{
struct V_253 * V_54 = V_255 -> V_260 -> V_18 ;
struct V_8 * V_9 = V_54 -> V_9 ;
F_16 ( & V_9 -> V_20 ) ;
F_122 ( V_54 ) ;
V_9 -> V_54 = NULL ;
F_10 ( V_54 -> V_261 ) ;
F_10 ( V_54 ) ;
F_18 ( & V_9 -> V_20 ) ;
return 0 ;
}
static int F_126 ( struct V_256 * V_255 ,
struct V_262 * V_263 )
{
struct V_253 * V_54 = V_255 -> V_260 -> V_18 ;
struct V_8 * V_9 = V_54 -> V_9 ;
const struct V_264 * V_265 ;
const struct V_266 * V_267 ;
int V_27 , V_268 ;
if ( V_263 -> V_254 . V_269 < V_270 ||
V_263 -> V_254 . V_269 > V_271 ||
V_263 -> V_254 . V_272 < V_273 ||
V_263 -> V_254 . V_272 > V_274 ||
V_263 -> V_254 . V_269 % V_275 ) {
F_21 ( V_9 , L_100 ,
V_263 -> V_254 . V_269 ,
V_263 -> V_254 . V_272 ) ;
return - V_53 ;
}
for ( V_27 = 0 ; V_27 < V_179 [ V_9 -> V_51 ] . V_248 ; V_27 ++ ) {
V_265 = & V_179 [ V_9 -> V_51 ] . V_265 [ V_27 ] ;
V_267 = & V_265 -> V_267 ;
if ( V_265 -> V_153 != V_263 -> V_23 . V_153 )
continue;
if ( V_255 -> V_259 == V_276 ) {
if ( V_267 -> V_277 < V_263 -> V_23 . V_278 )
continue;
} else {
if ( V_267 -> V_277 < V_263 -> V_23 . V_279 )
continue;
}
if ( ! ( V_267 -> V_280 & ( 1 << V_263 -> V_23 . V_281 ) ) )
continue;
for ( V_268 = 0 ; V_268 < V_267 -> V_282 ; ++ V_268 )
if ( V_267 -> V_283 [ V_268 ] == V_263 -> V_23 . V_284 )
return 0 ;
}
F_21 ( V_9 , L_101 ,
V_263 -> V_23 . V_153 , V_263 -> V_23 . V_279 , V_263 -> V_23 . V_278 ,
V_263 -> V_23 . V_284 , V_263 -> V_23 . V_281 ) ;
return - V_53 ;
}
static inline unsigned int F_127 ( struct V_253 * V_54 )
{
return V_54 -> V_89 . V_269 / V_275 ;
}
int F_128 ( struct V_256 * V_255 ,
struct V_262 * V_263 )
{
struct V_253 * V_54 = V_255 -> V_260 -> V_18 ;
unsigned int V_89 ;
int V_19 ;
V_19 = F_126 ( V_255 , V_263 ) ;
if ( V_19 )
return V_19 ;
V_54 -> V_89 = V_263 -> V_254 ;
F_40 ( V_54 -> V_9 , L_102 ,
V_54 -> V_89 . V_269 , V_54 -> V_89 . V_272 ) ;
V_89 = F_127 ( V_54 ) * sizeof( * V_54 -> V_261 ) ;
V_54 -> V_261 = F_22 ( V_89 , V_81 | V_7 ) ;
if ( ! V_54 -> V_261 )
return - V_82 ;
V_54 -> V_284 = V_263 -> V_23 . V_284 ;
return 0 ;
}
int F_129 ( struct V_256 * V_255 ,
struct V_285 * V_265 )
{
struct V_253 * V_54 = V_255 -> V_260 -> V_18 ;
int V_51 = V_54 -> V_9 -> V_51 ;
int V_27 ;
if ( V_179 [ V_51 ] . V_265 ) {
for ( V_27 = 0 ; V_27 < V_179 [ V_51 ] . V_248 ; V_27 ++ )
V_265 -> V_286 [ V_27 ] = V_179 [ V_51 ] . V_265 [ V_27 ] . V_153 ;
V_265 -> V_287 = V_27 ;
V_265 -> V_259 = V_179 [ V_51 ] . V_258 ;
V_265 -> V_288 = V_270 ;
V_265 -> V_289 = V_271 ;
V_265 -> V_290 = V_273 ;
V_265 -> V_291 = V_274 ;
}
return 0 ;
}
static int F_130 ( struct V_8 * V_9 , int V_159 ,
unsigned int V_292 ,
unsigned int V_293 , T_8 * V_85 )
{
struct V_56 const * V_58 = F_34 ( V_9 , V_159 ) ;
unsigned int V_27 , V_80 ;
int V_19 ;
if ( ! V_58 )
return - V_53 ;
V_80 = F_35 ( V_58 , V_292 ) ;
V_19 = F_39 ( V_9 -> V_67 , V_80 , V_85 ,
sizeof( * V_85 ) * V_293 ) ;
if ( V_19 < 0 )
return V_19 ;
for ( V_27 = 0 ; V_27 < V_293 ; ++ V_27 )
V_85 [ V_27 ] = F_81 ( V_85 [ V_27 ] ) & 0x00ffffffu ;
return 0 ;
}
static inline int F_131 ( struct V_8 * V_9 , int V_159 ,
unsigned int V_292 , T_8 * V_85 )
{
return F_130 ( V_9 , V_159 , V_292 , 1 , V_85 ) ;
}
static int F_132 ( struct V_8 * V_9 , int V_159 ,
unsigned int V_292 , T_8 V_85 )
{
struct V_56 const * V_58 = F_34 ( V_9 , V_159 ) ;
unsigned int V_80 ;
if ( ! V_58 )
return - V_53 ;
V_80 = F_35 ( V_58 , V_292 ) ;
V_85 = F_133 ( V_85 & 0x00ffffffu ) ;
return F_47 ( V_9 -> V_67 , V_80 , & V_85 , sizeof( V_85 ) ) ;
}
static inline int F_134 ( struct V_294 * V_6 ,
unsigned int V_295 , T_8 * V_85 )
{
return F_131 ( V_6 -> V_9 , V_63 ,
V_6 -> V_296 + V_295 , V_85 ) ;
}
static inline int F_135 ( struct V_294 * V_6 ,
unsigned int V_295 , T_8 V_85 )
{
return F_132 ( V_6 -> V_9 , V_63 ,
V_6 -> V_296 + V_295 , V_85 ) ;
}
static int F_136 ( struct V_294 * V_6 )
{
struct V_78 * V_79 ;
struct V_8 * V_9 = V_6 -> V_9 ;
T_8 V_297 , V_298 , V_182 ;
int V_27 , V_19 ;
V_79 = F_88 ( V_9 , V_63 , V_9 -> V_35 ) ;
V_297 = sizeof( struct V_299 ) / sizeof( T_7 ) ;
V_298 = V_79 -> V_61 + V_297 + F_137 ( V_182 ) ;
V_19 = F_131 ( V_9 , V_63 , V_298 , & V_182 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_182 != V_300 )
return - V_53 ;
V_298 = V_79 -> V_61 + V_297 + F_137 ( V_296 ) ;
for ( V_27 = 0 ; V_27 < 5 ; ++ V_27 ) {
V_19 = F_131 ( V_9 , V_63 , V_298 ,
& V_6 -> V_296 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_6 -> V_296 )
break;
F_105 ( 1000 , 2000 ) ;
}
if ( ! V_6 -> V_296 )
return - V_247 ;
F_40 ( V_9 , L_103 , V_6 -> V_296 ) ;
return 0 ;
}
static int F_138 ( struct V_294 * V_6 )
{
const struct V_264 * V_265 = V_179 [ V_6 -> V_9 -> V_51 ] . V_265 ;
struct V_301 * V_162 ;
T_8 V_59 = 0 ;
int V_27 , V_19 ;
for ( V_27 = 0 ; V_27 < V_265 -> V_302 ; ++ V_27 ) {
V_162 = & V_6 -> V_176 [ V_27 ] ;
V_162 -> V_59 = V_59 ;
V_162 -> V_159 = V_265 -> V_303 [ V_27 ] . V_159 ;
V_19 = F_134 ( V_6 , V_265 -> V_303 [ V_27 ] . V_304 ,
& V_162 -> V_305 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_134 ( V_6 , V_265 -> V_303 [ V_27 ] . V_306 ,
& V_59 ) ;
if ( V_19 < 0 )
return V_19 ;
V_162 -> V_307 = V_59 ;
F_40 ( V_6 -> V_9 ,
L_104 ,
V_27 , V_162 -> V_159 , V_162 -> V_305 ,
V_162 -> V_59 , V_162 -> V_307 ) ;
}
return 0 ;
}
static int F_112 ( struct V_8 * V_9 )
{
struct V_294 * V_6 ;
int V_19 ;
V_6 = F_2 ( sizeof( * V_6 ) , V_7 ) ;
if ( ! V_6 )
return - V_82 ;
V_6 -> V_9 = V_9 ;
V_6 -> V_308 = - 1 ;
V_6 -> V_309 = 0xFFFFFFFF ;
V_19 = F_136 ( V_6 ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 , L_105 , V_19 ) ;
goto V_310;
}
V_6 -> V_176 = F_139 ( V_179 [ V_9 -> V_51 ] . V_265 -> V_302 ,
sizeof( * V_6 -> V_176 ) , V_7 ) ;
if ( ! V_6 -> V_176 ) {
V_19 = - V_82 ;
goto V_310;
}
V_19 = F_138 ( V_6 ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 , L_106 , V_19 ) ;
goto V_311;
}
V_9 -> V_254 = V_6 ;
return 0 ;
V_311:
F_10 ( V_6 -> V_176 ) ;
V_310:
F_10 ( V_6 ) ;
return V_19 ;
}
static int F_114 ( struct V_8 * V_9 )
{
if ( V_9 -> V_254 ) {
F_122 ( V_9 -> V_254 -> V_54 ) ;
F_10 ( V_9 -> V_254 -> V_176 ) ;
F_10 ( V_9 -> V_254 ) ;
V_9 -> V_254 = NULL ;
}
return 0 ;
}
int F_140 ( struct V_256 * V_255 , int V_312 )
{
struct V_253 * V_54 = V_255 -> V_260 -> V_18 ;
struct V_8 * V_9 = V_54 -> V_9 ;
int V_19 = 0 ;
F_40 ( V_9 , L_107 , V_312 ) ;
F_16 ( & V_9 -> V_20 ) ;
switch ( V_312 ) {
case V_313 :
if ( F_120 ( V_54 ) )
break;
V_19 = F_121 ( V_54 ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 , L_108 ,
V_19 ) ;
break;
}
V_19 = F_135 ( V_54 -> V_6 ,
F_141 ( V_314 ) ,
F_127 ( V_54 ) ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 , L_109 ,
V_19 ) ;
break;
}
break;
case V_315 :
break;
default:
V_19 = - V_53 ;
break;
}
F_18 ( & V_9 -> V_20 ) ;
return V_19 ;
}
static inline int F_142 ( struct V_294 * V_6 )
{
int V_316 = V_179 [ V_6 -> V_9 -> V_51 ] . V_265 -> V_302 - 1 ;
return V_6 -> V_176 [ V_316 ] . V_307 ;
}
static int F_143 ( struct V_294 * V_6 )
{
T_8 V_317 , V_318 ;
int V_319 , V_308 , V_133 ;
int V_19 ;
if ( V_6 -> V_308 < 0 ) {
V_19 = F_134 ( V_6 ,
F_141 ( V_317 ) ,
& V_317 ) ;
if ( V_19 < 0 )
return V_19 ;
V_308 = F_144 ( V_317 , 23 ) ;
if ( V_308 < 0 ) {
F_40 ( V_6 -> V_9 , L_110 ) ;
return 0 ;
}
V_6 -> V_308 = V_308 ;
}
V_19 = F_134 ( V_6 , F_141 ( V_318 ) ,
& V_318 ) ;
if ( V_19 < 0 )
return V_19 ;
V_319 = F_144 ( V_318 , 23 ) ;
V_133 = V_319 - V_6 -> V_308 ;
if ( V_133 < 0 )
V_133 += F_142 ( V_6 ) ;
F_40 ( V_6 -> V_9 , L_111 ,
V_6 -> V_308 , V_319 , V_133 * V_275 ) ;
V_6 -> V_133 = V_133 ;
return 0 ;
}
static int F_145 ( struct V_294 * V_6 )
{
int V_19 ;
V_19 = F_134 ( V_6 , F_141 ( error ) , & V_6 -> error ) ;
if ( V_19 < 0 ) {
F_21 ( V_6 -> V_9 , L_112 , V_19 ) ;
return V_19 ;
}
if ( V_6 -> error != 0 ) {
F_21 ( V_6 -> V_9 , L_113 , V_6 -> error ) ;
return - V_247 ;
}
return 0 ;
}
int F_146 ( struct V_8 * V_9 )
{
struct V_294 * V_6 ;
struct V_253 * V_54 ;
int V_19 = 0 ;
F_16 ( & V_9 -> V_20 ) ;
V_6 = V_9 -> V_254 ;
V_54 = V_9 -> V_54 ;
if ( ! V_6 ) {
V_19 = - V_320 ;
goto V_95;
}
F_40 ( V_9 , L_114 ) ;
V_19 = F_145 ( V_6 ) ;
if ( V_19 < 0 )
goto V_321;
V_19 = F_134 ( V_6 , F_141 ( V_309 ) ,
& V_6 -> V_309 ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 , L_115 , V_19 ) ;
goto V_95;
}
V_19 = F_143 ( V_6 ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 , L_116 , V_19 ) ;
goto V_95;
}
if ( V_179 [ V_9 -> V_51 ] . V_322 && V_6 -> V_309 == 2 )
V_19 = V_323 ;
V_321:
if ( V_54 && V_54 -> V_255 )
F_123 ( V_54 -> V_255 ) ;
V_95:
F_18 ( & V_9 -> V_20 ) ;
return V_19 ;
}
static int F_147 ( struct V_294 * V_6 )
{
if ( V_6 -> V_309 & 0x01 )
return 0 ;
F_40 ( V_6 -> V_9 , L_117 ,
V_6 -> V_309 ) ;
V_6 -> V_309 |= 0x01 ;
return F_135 ( V_6 , F_141 ( V_324 ) ,
V_6 -> V_309 ) ;
}
int F_148 ( struct V_256 * V_255 ,
struct V_325 * V_326 )
{
struct V_253 * V_54 = V_255 -> V_260 -> V_18 ;
struct V_8 * V_9 = V_54 -> V_9 ;
struct V_294 * V_6 ;
int V_19 = 0 ;
F_40 ( V_9 , L_118 ) ;
F_16 ( & V_9 -> V_20 ) ;
V_6 = V_54 -> V_6 ;
if ( ! V_54 -> V_6 || V_54 -> V_6 -> error ) {
F_149 ( V_255 , V_327 ) ;
V_19 = - V_247 ;
goto V_95;
}
if ( V_6 -> V_133 < F_127 ( V_54 ) ) {
V_19 = F_143 ( V_6 ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 , L_116 , V_19 ) ;
goto V_95;
}
if ( V_6 -> V_133 < F_127 ( V_54 ) ) {
V_19 = F_145 ( V_6 ) ;
if ( V_19 < 0 ) {
if ( V_54 -> V_6 -> error )
F_149 ( V_255 ,
V_327 ) ;
goto V_95;
}
V_19 = F_147 ( V_6 ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 ,
L_119 ,
V_19 ) ;
goto V_95;
}
}
}
V_326 -> V_328 = V_54 -> V_328 ;
V_326 -> V_328 += V_6 -> V_133 * V_275 ;
V_326 -> V_329 = V_54 -> V_284 ;
V_95:
F_18 ( & V_9 -> V_20 ) ;
return V_19 ;
}
static int F_150 ( struct V_253 * V_54 , int V_330 )
{
struct V_294 * V_6 = V_54 -> V_6 ;
T_6 * V_331 = ( T_6 * ) V_54 -> V_261 ;
T_6 * V_332 = ( T_6 * ) V_54 -> V_261 ;
unsigned int V_333 ;
int V_159 , V_334 , V_335 ;
int V_27 , V_268 , V_19 ;
for ( V_27 = 0 ; V_27 < V_179 [ V_6 -> V_9 -> V_51 ] . V_265 -> V_302 ; ++ V_27 )
if ( V_6 -> V_308 < V_6 -> V_176 [ V_27 ] . V_307 )
break;
if ( V_27 == V_179 [ V_6 -> V_9 -> V_51 ] . V_265 -> V_302 )
return - V_53 ;
V_159 = V_6 -> V_176 [ V_27 ] . V_159 ;
V_333 = V_6 -> V_176 [ V_27 ] . V_305 +
( V_6 -> V_308 - V_6 -> V_176 [ V_27 ] . V_59 ) ;
V_335 = F_127 ( V_54 ) ;
V_334 = V_6 -> V_176 [ V_27 ] . V_307 - V_6 -> V_308 ;
if ( V_334 > V_330 )
V_334 = V_330 ;
if ( V_334 > V_6 -> V_133 )
V_334 = V_6 -> V_133 ;
if ( V_334 > V_335 )
V_334 = V_335 ;
if ( ! V_334 )
return 0 ;
V_19 = F_130 ( V_6 -> V_9 , V_159 , V_333 ,
V_334 , V_54 -> V_261 ) ;
if ( V_19 < 0 )
return V_19 ;
for ( V_27 = 0 ; V_27 < V_334 ; V_27 ++ ) {
for ( V_268 = 0 ; V_268 < V_275 ; V_268 ++ )
* V_332 ++ = * V_331 ++ ;
V_331 += sizeof( * ( V_54 -> V_261 ) ) - V_275 ;
}
V_6 -> V_308 += V_334 ;
if ( V_6 -> V_308 == F_142 ( V_6 ) )
V_6 -> V_308 = 0 ;
V_19 = F_135 ( V_6 , F_141 ( V_317 ) ,
V_6 -> V_308 ) ;
if ( V_19 < 0 )
return V_19 ;
V_6 -> V_133 -= V_334 ;
return V_334 ;
}
static int F_151 ( struct V_253 * V_54 ,
char T_3 * V_6 , T_1 V_16 )
{
struct V_8 * V_9 = V_54 -> V_9 ;
int V_336 = 0 ;
int V_334 , V_337 ;
F_40 ( V_9 , L_120 , V_16 ) ;
if ( ! V_54 -> V_6 || V_54 -> V_6 -> error ) {
F_149 ( V_54 -> V_255 , V_327 ) ;
return - V_247 ;
}
V_16 /= V_275 ;
do {
V_334 = F_150 ( V_54 , V_16 ) ;
if ( V_334 < 0 ) {
F_21 ( V_9 , L_121 , V_334 ) ;
return V_334 ;
}
V_337 = V_334 * V_275 ;
F_40 ( V_9 , L_122 , V_337 ) ;
if ( F_54 ( V_6 + V_336 , V_54 -> V_261 , V_337 ) ) {
F_21 ( V_9 , L_123 ,
V_336 , V_337 ) ;
return - V_90 ;
}
V_16 -= V_334 ;
V_336 += V_337 ;
} while ( V_334 > 0 && V_16 > 0 );
V_54 -> V_328 += V_336 ;
return V_336 ;
}
int F_152 ( struct V_256 * V_255 , char T_3 * V_6 ,
T_1 V_16 )
{
struct V_253 * V_54 = V_255 -> V_260 -> V_18 ;
struct V_8 * V_9 = V_54 -> V_9 ;
int V_19 ;
F_16 ( & V_9 -> V_20 ) ;
if ( V_255 -> V_259 == V_338 )
V_19 = F_151 ( V_54 , V_6 , V_16 ) ;
else
V_19 = - V_339 ;
F_18 ( & V_9 -> V_20 ) ;
return V_19 ;
}
