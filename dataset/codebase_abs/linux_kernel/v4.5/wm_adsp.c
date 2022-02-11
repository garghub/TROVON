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
static int F_42 ( struct V_39 * V_68 ,
struct V_69 * V_70 )
{
struct V_71 * V_72 = (struct V_71 * ) V_68 -> V_45 ;
V_70 -> type = V_73 ;
V_70 -> V_16 = V_72 -> V_3 ;
return 0 ;
}
static int F_43 ( struct V_71 * V_72 ,
const void * V_6 , T_1 V_3 )
{
struct V_74 * V_75 = & V_72 -> V_75 ;
const struct V_55 * V_57 ;
struct V_8 * V_9 = V_72 -> V_9 ;
void * V_65 ;
int V_19 ;
unsigned int V_76 ;
V_57 = F_34 ( V_9 , V_75 -> type ) ;
if ( ! V_57 ) {
F_21 ( V_9 , L_11 ,
V_75 -> type ) ;
return - V_52 ;
}
V_76 = V_72 -> V_75 . V_60 + V_72 -> V_58 ;
V_76 = F_35 ( V_57 , V_76 ) ;
V_65 = F_44 ( V_6 , V_72 -> V_3 , V_7 | V_77 ) ;
if ( ! V_65 )
return - V_78 ;
V_19 = F_45 ( V_9 -> V_66 , V_76 , V_65 ,
V_72 -> V_3 ) ;
if ( V_19 ) {
F_21 ( V_9 , L_12 ,
V_72 -> V_3 , V_76 , V_19 ) ;
F_10 ( V_65 ) ;
return V_19 ;
}
F_40 ( V_9 , L_13 , V_72 -> V_3 , V_76 ) ;
F_10 ( V_65 ) ;
return 0 ;
}
static int F_46 ( struct V_39 * V_68 ,
struct V_41 * V_42 )
{
struct V_71 * V_72 = (struct V_71 * ) V_68 -> V_45 ;
char * V_79 = V_42 -> V_46 . V_80 . V_81 ;
int V_19 = 0 ;
F_16 ( & V_72 -> V_9 -> V_20 ) ;
memcpy ( V_72 -> V_82 , V_79 , V_72 -> V_3 ) ;
V_72 -> V_83 = 1 ;
if ( V_72 -> V_84 )
V_19 = F_43 ( V_72 , V_79 , V_72 -> V_3 ) ;
F_18 ( & V_72 -> V_9 -> V_20 ) ;
return V_19 ;
}
static int F_47 ( struct V_71 * V_72 ,
void * V_6 , T_1 V_3 )
{
struct V_74 * V_75 = & V_72 -> V_75 ;
const struct V_55 * V_57 ;
struct V_8 * V_9 = V_72 -> V_9 ;
void * V_65 ;
int V_19 ;
unsigned int V_76 ;
V_57 = F_34 ( V_9 , V_75 -> type ) ;
if ( ! V_57 ) {
F_21 ( V_9 , L_11 ,
V_75 -> type ) ;
return - V_52 ;
}
V_76 = V_72 -> V_75 . V_60 + V_72 -> V_58 ;
V_76 = F_35 ( V_57 , V_76 ) ;
V_65 = F_22 ( V_72 -> V_3 , V_7 | V_77 ) ;
if ( ! V_65 )
return - V_78 ;
V_19 = F_39 ( V_9 -> V_66 , V_76 , V_65 , V_72 -> V_3 ) ;
if ( V_19 ) {
F_21 ( V_9 , L_14 ,
V_72 -> V_3 , V_76 , V_19 ) ;
F_10 ( V_65 ) ;
return V_19 ;
}
F_40 ( V_9 , L_15 , V_72 -> V_3 , V_76 ) ;
memcpy ( V_6 , V_65 , V_72 -> V_3 ) ;
F_10 ( V_65 ) ;
return 0 ;
}
static int F_48 ( struct V_39 * V_68 ,
struct V_41 * V_42 )
{
struct V_71 * V_72 = (struct V_71 * ) V_68 -> V_45 ;
char * V_79 = V_42 -> V_46 . V_80 . V_81 ;
int V_19 = 0 ;
F_16 ( & V_72 -> V_9 -> V_20 ) ;
if ( V_72 -> V_85 & V_86 ) {
if ( V_72 -> V_84 )
V_19 = F_47 ( V_72 , V_79 , V_72 -> V_3 ) ;
else
V_19 = - V_87 ;
} else {
if ( ! V_72 -> V_85 && V_72 -> V_84 )
V_19 = F_47 ( V_72 , V_72 -> V_82 , V_72 -> V_3 ) ;
memcpy ( V_79 , V_72 -> V_82 , V_72 -> V_3 ) ;
}
F_18 ( & V_72 -> V_9 -> V_20 ) ;
return V_19 ;
}
static int F_49 ( struct V_8 * V_9 , struct V_71 * V_72 )
{
struct V_88 * V_40 ;
int V_19 ;
if ( ! V_72 || ! V_72 -> V_37 )
return - V_52 ;
V_40 = F_2 ( sizeof( * V_40 ) , V_7 ) ;
if ( ! V_40 )
return - V_78 ;
V_40 -> V_89 = V_90 ;
V_40 -> V_37 = V_72 -> V_37 ;
V_40 -> V_91 = F_42 ;
V_40 -> V_92 = F_48 ;
V_40 -> V_93 = F_46 ;
V_40 -> V_45 = ( unsigned long ) V_72 ;
if ( V_72 -> V_85 ) {
if ( V_72 -> V_85 & V_94 )
V_40 -> V_95 |= V_96 ;
if ( V_72 -> V_85 & V_97 )
V_40 -> V_95 |= V_98 ;
if ( V_72 -> V_85 & V_86 )
V_40 -> V_95 |= V_99 ;
}
V_19 = F_50 ( V_9 -> V_100 ,
V_40 , 1 ) ;
if ( V_19 < 0 )
goto V_101;
F_10 ( V_40 ) ;
V_72 -> V_40 = F_51 ( V_9 -> V_100 ,
V_72 -> V_37 ) ;
return 0 ;
V_101:
F_10 ( V_40 ) ;
return V_19 ;
}
static int F_52 ( struct V_8 * V_9 )
{
struct V_71 * V_72 ;
int V_19 ;
F_53 (ctl, &dsp->ctl_list, list) {
if ( ! V_72 -> V_84 || V_72 -> V_83 )
continue;
if ( V_72 -> V_85 & V_86 )
continue;
V_19 = F_47 ( V_72 ,
V_72 -> V_82 ,
V_72 -> V_3 ) ;
if ( V_19 < 0 )
return V_19 ;
}
return 0 ;
}
static int F_54 ( struct V_8 * V_9 )
{
struct V_71 * V_72 ;
int V_19 ;
F_53 (ctl, &dsp->ctl_list, list) {
if ( ! V_72 -> V_84 )
continue;
if ( V_72 -> V_83 && ! ( V_72 -> V_85 & V_86 ) ) {
V_19 = F_43 ( V_72 ,
V_72 -> V_82 ,
V_72 -> V_3 ) ;
if ( V_19 < 0 )
return V_19 ;
}
}
return 0 ;
}
static void F_55 ( struct V_102 * V_103 )
{
struct V_104 * V_105 = F_56 ( V_103 ,
struct V_104 ,
V_103 ) ;
F_49 ( V_105 -> V_9 , V_105 -> V_72 ) ;
F_10 ( V_105 ) ;
}
static int F_57 ( struct V_8 * V_9 ,
const struct V_74 * V_75 ,
unsigned int V_58 , unsigned int V_3 ,
const char * V_106 , unsigned int V_107 ,
unsigned int V_85 )
{
struct V_71 * V_72 ;
struct V_104 * V_105 ;
char V_37 [ V_108 ] ;
char * V_109 ;
int V_19 ;
if ( V_85 & V_110 )
return 0 ;
switch ( V_75 -> type ) {
case V_59 :
V_109 = L_16 ;
break;
case V_61 :
V_109 = L_17 ;
break;
case V_62 :
V_109 = L_18 ;
break;
case V_63 :
V_109 = L_19 ;
break;
case V_64 :
V_109 = L_20 ;
break;
default:
F_21 ( V_9 , L_21 , V_75 -> type ) ;
return - V_52 ;
}
switch ( V_9 -> V_111 ) {
case 0 :
case 1 :
snprintf ( V_37 , V_108 , L_22 ,
V_9 -> V_32 , V_109 , V_75 -> V_112 ) ;
break;
default:
V_19 = snprintf ( V_37 , V_108 ,
L_23 , V_9 -> V_32 , * V_109 ,
V_113 [ V_9 -> V_50 ] , V_75 -> V_112 ) ;
if ( V_106 ) {
int V_114 = V_108 - V_19 - 2 ;
int V_115 = 0 ;
if ( V_107 > V_114 )
V_115 = V_107 - V_114 ;
snprintf ( V_37 + V_19 ,
V_108 - V_19 , L_24 ,
V_107 - V_115 , V_106 + V_115 ) ;
}
break;
}
F_53 (ctl, &dsp->ctl_list, list) {
if ( ! strcmp ( V_72 -> V_37 , V_37 ) ) {
if ( ! V_72 -> V_84 )
V_72 -> V_84 = 1 ;
return 0 ;
}
}
V_72 = F_2 ( sizeof( * V_72 ) , V_7 ) ;
if ( ! V_72 )
return - V_78 ;
V_72 -> V_116 = V_113 [ V_9 -> V_50 ] ;
V_72 -> V_75 = * V_75 ;
V_72 -> V_37 = F_44 ( V_37 , strlen ( V_37 ) + 1 , V_7 ) ;
if ( ! V_72 -> V_37 ) {
V_19 = - V_78 ;
goto V_117;
}
V_72 -> V_84 = 1 ;
V_72 -> V_83 = 0 ;
V_72 -> V_118 . V_119 = F_48 ;
V_72 -> V_118 . V_120 = F_46 ;
V_72 -> V_9 = V_9 ;
V_72 -> V_85 = V_85 ;
V_72 -> V_58 = V_58 ;
if ( V_3 > 512 ) {
F_58 ( V_9 , L_25 ,
V_72 -> V_37 , V_3 ) ;
V_3 = 512 ;
}
V_72 -> V_3 = V_3 ;
V_72 -> V_82 = F_2 ( V_72 -> V_3 , V_7 ) ;
if ( ! V_72 -> V_82 ) {
V_19 = - V_78 ;
goto V_121;
}
F_59 ( & V_72 -> V_5 , & V_9 -> V_122 ) ;
V_105 = F_2 ( sizeof( * V_105 ) , V_7 ) ;
if ( ! V_105 ) {
V_19 = - V_78 ;
goto V_123;
}
V_105 -> V_9 = V_9 ;
V_105 -> V_72 = V_72 ;
F_60 ( & V_105 -> V_103 , F_55 ) ;
F_61 ( & V_105 -> V_103 ) ;
return 0 ;
V_123:
F_10 ( V_72 -> V_82 ) ;
V_121:
F_10 ( V_72 -> V_37 ) ;
V_117:
F_10 ( V_72 ) ;
return V_19 ;
}
static int F_62 ( int V_80 , const T_6 * * V_124 , const T_6 * * V_125 )
{
int V_126 ;
switch ( V_80 ) {
case 1 :
V_126 = * * V_124 ;
break;
case 2 :
V_126 = F_63 ( * ( ( V_127 * ) * V_124 ) ) ;
break;
default:
return 0 ;
}
if ( V_125 )
* V_125 = * V_124 + V_80 ;
* V_124 += ( ( V_126 + V_80 ) + 3 ) & ~ 0x03 ;
return V_126 ;
}
static int F_64 ( int V_80 , const T_6 * * V_124 )
{
int V_128 = 0 ;
switch ( V_80 ) {
case 2 :
V_128 = F_63 ( * ( ( V_127 * ) * V_124 ) ) ;
break;
case 4 :
V_128 = F_65 ( * ( ( V_129 * ) * V_124 ) ) ;
break;
default:
break;
}
* V_124 += V_80 ;
return V_128 ;
}
static inline void F_66 ( struct V_8 * V_9 , const T_6 * * V_81 ,
struct V_130 * V_131 )
{
const struct V_132 * V_133 ;
switch ( V_9 -> V_111 ) {
case 0 :
case 1 :
V_133 = ( const struct V_132 * ) * V_81 ;
* V_81 = V_133 -> V_81 ;
V_131 -> V_134 = F_65 ( V_133 -> V_134 ) ;
V_131 -> V_37 = V_133 -> V_37 ;
V_131 -> V_135 = strlen ( V_133 -> V_37 ) ;
V_131 -> V_136 = F_65 ( V_133 -> V_136 ) ;
break;
default:
V_131 -> V_134 = F_64 ( sizeof( V_133 -> V_134 ) , V_81 ) ;
V_131 -> V_135 = F_62 ( sizeof( T_6 ) , V_81 ,
& V_131 -> V_37 ) ;
F_62 ( sizeof( T_5 ) , V_81 , NULL ) ;
V_131 -> V_136 = F_64 ( sizeof( V_133 -> V_136 ) , V_81 ) ;
break;
}
F_40 ( V_9 , L_26 , V_131 -> V_134 ) ;
F_40 ( V_9 , L_27 , V_131 -> V_135 , V_131 -> V_37 ) ;
F_40 ( V_9 , L_28 , V_131 -> V_136 ) ;
}
static inline void F_67 ( struct V_8 * V_9 , const T_6 * * V_81 ,
struct V_137 * V_131 )
{
const struct V_138 * V_133 ;
const T_6 * V_11 ;
int V_126 ;
switch ( V_9 -> V_111 ) {
case 0 :
case 1 :
V_133 = ( const struct V_138 * ) * V_81 ;
* V_81 = * V_81 + sizeof( V_133 -> V_139 ) + F_65 ( V_133 -> V_139 . V_140 ) ;
V_131 -> V_58 = F_63 ( V_133 -> V_139 . V_58 ) ;
V_131 -> V_141 = F_63 ( V_133 -> V_139 . type ) ;
V_131 -> V_37 = V_133 -> V_37 ;
V_131 -> V_135 = strlen ( V_133 -> V_37 ) ;
V_131 -> V_142 = F_63 ( V_133 -> V_142 ) ;
V_131 -> V_85 = F_63 ( V_133 -> V_85 ) ;
V_131 -> V_3 = F_65 ( V_133 -> V_3 ) ;
break;
default:
V_11 = * V_81 ;
V_131 -> V_58 = F_64 ( sizeof( V_133 -> V_139 . V_58 ) , & V_11 ) ;
V_131 -> V_141 = F_64 ( sizeof( V_133 -> V_139 . type ) , & V_11 ) ;
V_126 = F_64 ( sizeof( V_133 -> V_139 . V_140 ) , & V_11 ) ;
V_131 -> V_135 = F_62 ( sizeof( T_6 ) , & V_11 ,
& V_131 -> V_37 ) ;
F_62 ( sizeof( T_6 ) , & V_11 , NULL ) ;
F_62 ( sizeof( T_5 ) , & V_11 , NULL ) ;
V_131 -> V_142 = F_64 ( sizeof( V_133 -> V_142 ) , & V_11 ) ;
V_131 -> V_85 = F_64 ( sizeof( V_133 -> V_85 ) , & V_11 ) ;
V_131 -> V_3 = F_64 ( sizeof( V_133 -> V_3 ) , & V_11 ) ;
* V_81 = * V_81 + sizeof( V_133 -> V_139 ) + V_126 ;
break;
}
F_40 ( V_9 , L_29 , V_131 -> V_141 ) ;
F_40 ( V_9 , L_30 , V_131 -> V_58 ) ;
F_40 ( V_9 , L_31 , V_131 -> V_135 , V_131 -> V_37 ) ;
F_40 ( V_9 , L_32 , V_131 -> V_85 ) ;
F_40 ( V_9 , L_33 , V_131 -> V_142 ) ;
F_40 ( V_9 , L_34 , V_131 -> V_3 ) ;
}
static int F_68 ( struct V_8 * V_9 ,
const struct V_143 * V_144 )
{
struct V_74 V_75 = {} ;
struct V_130 V_145 ;
struct V_137 V_146 ;
const T_6 * V_81 = V_144 -> V_81 ;
int V_27 , V_19 ;
F_66 ( V_9 , & V_81 , & V_145 ) ;
for ( V_27 = 0 ; V_27 < V_145 . V_136 ; V_27 ++ ) {
F_67 ( V_9 , & V_81 , & V_146 ) ;
switch ( V_146 . V_142 ) {
case V_73 :
break;
default:
F_21 ( V_9 , L_35 ,
V_146 . V_142 ) ;
return - V_52 ;
}
V_75 . type = V_146 . V_141 ;
V_75 . V_112 = V_145 . V_134 ;
V_19 = F_57 ( V_9 , & V_75 ,
V_146 . V_58 ,
V_146 . V_3 ,
V_146 . V_37 ,
V_146 . V_135 ,
V_146 . V_85 ) ;
if ( V_19 < 0 )
F_21 ( V_9 , L_36 ,
V_146 . V_135 , V_146 . V_37 , V_19 ) ;
}
return 0 ;
}
static int F_69 ( struct V_8 * V_9 )
{
F_70 ( V_147 ) ;
const struct V_148 * V_148 ;
struct V_66 * V_66 = V_9 -> V_66 ;
unsigned int V_124 = 0 ;
const struct V_149 * V_150 ;
const struct V_151 * V_152 ;
const struct V_153 * V_154 ;
const struct V_155 * V_156 ;
const struct V_143 * V_144 ;
const struct V_55 * V_57 ;
const char * V_109 ;
char * V_14 , * V_157 ;
struct V_1 * V_6 ;
unsigned int V_76 ;
int V_158 = 0 ;
int V_19 , V_58 , type , V_159 ;
V_14 = F_2 ( V_31 , V_7 ) ;
if ( V_14 == NULL )
return - V_78 ;
snprintf ( V_14 , V_31 , L_37 , V_9 -> V_160 , V_9 -> V_32 ,
V_161 [ V_9 -> V_50 ] . V_14 ) ;
V_14 [ V_31 - 1 ] = '\0' ;
V_19 = F_71 ( & V_148 , V_14 , V_9 -> V_162 ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_38 , V_14 ) ;
goto V_163;
}
V_19 = - V_52 ;
V_124 = sizeof( * V_150 ) + sizeof( * V_152 ) + sizeof( * V_156 ) ;
if ( V_124 >= V_148 -> V_140 ) {
F_21 ( V_9 , L_39 ,
V_14 , V_148 -> V_140 ) ;
goto V_164;
}
V_150 = ( void * ) & V_148 -> V_81 [ 0 ] ;
if ( memcmp ( & V_150 -> V_165 [ 0 ] , L_40 , 4 ) != 0 ) {
F_21 ( V_9 , L_41 , V_14 ) ;
goto V_164;
}
switch ( V_150 -> V_166 ) {
case 0 :
F_58 ( V_9 , L_42 ,
V_14 , V_150 -> V_166 ) ;
break;
case 1 :
case 2 :
break;
default:
F_21 ( V_9 , L_43 ,
V_14 , V_150 -> V_166 ) ;
goto V_164;
}
F_72 ( V_9 , L_44 , V_150 -> V_166 ) ;
V_9 -> V_111 = V_150 -> V_166 ;
if ( V_150 -> V_167 != V_9 -> type ) {
F_21 ( V_9 , L_45 ,
V_14 , V_150 -> V_167 , V_9 -> type ) ;
goto V_164;
}
switch ( V_9 -> type ) {
case V_168 :
V_124 = sizeof( * V_150 ) + sizeof( * V_152 ) + sizeof( * V_156 ) ;
V_152 = ( void * ) & ( V_150 [ 1 ] ) ;
V_156 = ( void * ) & ( V_152 [ 1 ] ) ;
V_159 = sizeof( * V_152 ) ;
F_40 ( V_9 , L_46 ,
V_14 , F_65 ( V_152 -> V_169 ) ,
F_65 ( V_152 -> V_170 ) ,
F_65 ( V_152 -> V_171 ) ) ;
break;
case V_172 :
V_124 = sizeof( * V_150 ) + sizeof( * V_154 ) + sizeof( * V_156 ) ;
V_154 = ( void * ) & ( V_150 [ 1 ] ) ;
V_156 = ( void * ) & ( V_154 [ 1 ] ) ;
V_159 = sizeof( * V_154 ) ;
F_40 ( V_9 , L_47 ,
V_14 , F_65 ( V_154 -> V_173 ) ,
F_65 ( V_154 -> V_174 ) ,
F_65 ( V_154 -> V_170 ) ,
F_65 ( V_154 -> V_171 ) ) ;
break;
default:
F_37 ( 1 , L_48 ) ;
goto V_164;
}
if ( F_65 ( V_150 -> V_3 ) != sizeof( * V_150 ) +
V_159 + sizeof( * V_156 ) ) {
F_21 ( V_9 , L_49 ,
V_14 , F_65 ( V_150 -> V_3 ) ) ;
goto V_164;
}
F_40 ( V_9 , L_50 , V_14 ,
F_73 ( V_156 -> V_175 ) ) ;
while ( V_124 < V_148 -> V_140 &&
V_124 - V_148 -> V_140 > sizeof( * V_144 ) ) {
V_144 = ( void * ) & ( V_148 -> V_81 [ V_124 ] ) ;
V_109 = L_51 ;
V_76 = 0 ;
V_157 = NULL ;
V_58 = F_65 ( V_144 -> V_58 ) & 0xffffff ;
type = F_74 ( V_144 -> type ) & 0xff ;
V_57 = F_34 ( V_9 , type ) ;
switch ( type ) {
case V_176 :
V_109 = L_52 ;
V_157 = F_2 ( F_65 ( V_144 -> V_3 ) + 1 ,
V_7 ) ;
break;
case V_177 :
V_109 = L_53 ;
V_19 = F_68 ( V_9 , V_144 ) ;
if ( V_19 != 0 )
goto V_164;
break;
case V_178 :
V_109 = L_54 ;
V_157 = F_2 ( F_65 ( V_144 -> V_3 ) + 1 ,
V_7 ) ;
break;
case V_179 :
V_109 = L_55 ;
V_76 = V_58 ;
break;
case V_59 :
V_109 = L_16 ;
V_76 = F_35 ( V_57 , V_58 ) ;
break;
case V_61 :
V_109 = L_17 ;
V_76 = F_35 ( V_57 , V_58 ) ;
break;
case V_62 :
V_109 = L_18 ;
V_76 = F_35 ( V_57 , V_58 ) ;
break;
case V_63 :
V_109 = L_19 ;
V_76 = F_35 ( V_57 , V_58 ) ;
break;
case V_64 :
V_109 = L_20 ;
V_76 = F_35 ( V_57 , V_58 ) ;
break;
default:
F_58 ( V_9 ,
L_56 ,
V_14 , V_158 , type , V_124 , V_124 ) ;
break;
}
F_40 ( V_9 , L_57 , V_14 ,
V_158 , F_65 ( V_144 -> V_3 ) , V_58 ,
V_109 ) ;
if ( V_157 ) {
memcpy ( V_157 , V_144 -> V_81 , F_65 ( V_144 -> V_3 ) ) ;
F_72 ( V_9 , L_58 , V_14 , V_157 ) ;
F_10 ( V_157 ) ;
}
if ( V_76 ) {
V_6 = F_1 ( V_144 -> V_81 ,
F_65 ( V_144 -> V_3 ) ,
& V_147 ) ;
if ( ! V_6 ) {
F_21 ( V_9 , L_59 ) ;
V_19 = - V_78 ;
goto V_164;
}
V_19 = F_75 ( V_66 , V_76 , V_6 -> V_6 ,
F_65 ( V_144 -> V_3 ) ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 ,
L_60 ,
V_14 , V_158 ,
F_65 ( V_144 -> V_3 ) , V_58 ,
V_109 , V_19 ) ;
goto V_164;
}
}
V_124 += F_65 ( V_144 -> V_3 ) + sizeof( * V_144 ) ;
V_158 ++ ;
}
V_19 = F_76 ( V_66 ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_61 , V_19 ) ;
goto V_164;
}
if ( V_124 > V_148 -> V_140 )
F_58 ( V_9 , L_62 ,
V_14 , V_158 , V_124 - V_148 -> V_140 ) ;
F_11 ( V_9 , V_14 ) ;
V_164:
F_76 ( V_66 ) ;
F_6 ( & V_147 ) ;
F_77 ( V_148 ) ;
V_163:
F_10 ( V_14 ) ;
return V_19 ;
}
static void F_78 ( struct V_8 * V_9 ,
const struct V_74 * V_75 )
{
struct V_71 * V_72 ;
F_53 (ctl, &dsp->ctl_list, list) {
if ( V_72 -> V_116 == V_113 [ V_9 -> V_50 ] &&
V_75 -> V_112 == V_72 -> V_75 . V_112 &&
V_75 -> type == V_72 -> V_75 . type ) {
V_72 -> V_75 . V_60 = V_75 -> V_60 ;
}
}
}
static void * F_79 ( struct V_8 * V_9 , T_1 V_180 ,
unsigned int V_124 , unsigned int V_3 )
{
void * V_112 ;
int V_19 ;
T_7 V_128 ;
if ( V_180 == 0 ) {
F_21 ( V_9 , L_63 ) ;
return F_80 ( - V_52 ) ;
}
if ( V_180 > 1024 ) {
F_21 ( V_9 , L_64 , V_180 ) ;
return F_80 ( - V_52 ) ;
}
V_19 = F_39 ( V_9 -> V_66 , V_124 + V_3 , & V_128 , sizeof( V_128 ) ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_65 ,
V_19 ) ;
return F_80 ( V_19 ) ;
}
if ( F_74 ( V_128 ) != 0xbedead )
F_58 ( V_9 , L_66 ,
V_124 + V_3 , F_74 ( V_128 ) ) ;
V_112 = F_2 ( V_3 * 2 , V_7 | V_77 ) ;
if ( ! V_112 )
return F_80 ( - V_78 ) ;
V_19 = F_39 ( V_9 -> V_66 , V_124 , V_112 , V_3 * 2 ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_67 ,
V_19 ) ;
F_10 ( V_112 ) ;
return F_80 ( V_19 ) ;
}
return V_112 ;
}
static struct V_74 *
F_81 ( struct V_8 * V_9 , int type , unsigned int V_134 )
{
struct V_74 * V_75 ;
F_53 (alg_region, &dsp->alg_regions, list) {
if ( V_134 == V_75 -> V_112 && type == V_75 -> type )
return V_75 ;
}
return NULL ;
}
static struct V_74 * F_82 ( struct V_8 * V_9 ,
int type , T_7 V_134 ,
T_7 V_60 )
{
struct V_74 * V_75 ;
V_75 = F_2 ( sizeof( * V_75 ) , V_7 ) ;
if ( ! V_75 )
return F_80 ( - V_78 ) ;
V_75 -> type = type ;
V_75 -> V_112 = F_74 ( V_134 ) ;
V_75 -> V_60 = F_74 ( V_60 ) ;
F_5 ( & V_75 -> V_5 , & V_9 -> V_181 ) ;
if ( V_9 -> V_111 > 0 )
F_78 ( V_9 , V_75 ) ;
return V_75 ;
}
static int F_83 ( struct V_8 * V_9 )
{
struct V_182 V_183 ;
struct V_184 * V_185 ;
struct V_74 * V_75 ;
const struct V_55 * V_57 ;
unsigned int V_124 , V_3 ;
T_1 V_180 ;
int V_27 , V_19 ;
V_57 = F_34 ( V_9 , V_61 ) ;
if ( F_36 ( ! V_57 ) )
return - V_52 ;
V_19 = F_39 ( V_9 -> V_66 , V_57 -> V_60 , & V_183 ,
sizeof( V_183 ) ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_68 ,
V_19 ) ;
return V_19 ;
}
V_180 = F_74 ( V_183 . V_180 ) ;
V_9 -> V_34 = F_74 ( V_183 . V_50 . V_134 ) ;
F_72 ( V_9 , L_69 ,
V_9 -> V_34 ,
( F_74 ( V_183 . V_50 . V_166 ) & 0xff0000 ) >> 16 ,
( F_74 ( V_183 . V_50 . V_166 ) & 0xff00 ) >> 8 ,
F_74 ( V_183 . V_50 . V_166 ) & 0xff ,
V_180 ) ;
V_75 = F_82 ( V_9 , V_64 ,
V_183 . V_50 . V_134 , V_183 . V_171 ) ;
if ( F_84 ( V_75 ) )
return F_85 ( V_75 ) ;
V_75 = F_82 ( V_9 , V_61 ,
V_183 . V_50 . V_134 , V_183 . V_169 ) ;
if ( F_84 ( V_75 ) )
return F_85 ( V_75 ) ;
V_124 = sizeof( V_183 ) / 2 ;
V_3 = ( sizeof( * V_185 ) * V_180 ) / 2 ;
V_185 = F_79 ( V_9 , V_180 , V_57 -> V_60 + V_124 , V_3 ) ;
if ( F_84 ( V_185 ) )
return F_85 ( V_185 ) ;
for ( V_27 = 0 ; V_27 < V_180 ; V_27 ++ ) {
F_72 ( V_9 , L_70 ,
V_27 , F_74 ( V_185 [ V_27 ] . V_112 . V_134 ) ,
( F_74 ( V_185 [ V_27 ] . V_112 . V_166 ) & 0xff0000 ) >> 16 ,
( F_74 ( V_185 [ V_27 ] . V_112 . V_166 ) & 0xff00 ) >> 8 ,
F_74 ( V_185 [ V_27 ] . V_112 . V_166 ) & 0xff ,
F_74 ( V_185 [ V_27 ] . V_169 ) ,
F_74 ( V_185 [ V_27 ] . V_171 ) ) ;
V_75 = F_82 ( V_9 , V_61 ,
V_185 [ V_27 ] . V_112 . V_134 ,
V_185 [ V_27 ] . V_169 ) ;
if ( F_84 ( V_75 ) ) {
V_19 = F_85 ( V_75 ) ;
goto V_163;
}
if ( V_9 -> V_111 == 0 ) {
if ( V_27 + 1 < V_180 ) {
V_3 = F_74 ( V_185 [ V_27 + 1 ] . V_169 ) ;
V_3 -= F_74 ( V_185 [ V_27 ] . V_169 ) ;
V_3 *= 4 ;
F_57 ( V_9 , V_75 , 0 ,
V_3 , NULL , 0 , 0 ) ;
} else {
F_58 ( V_9 , L_71 ,
F_74 ( V_185 [ V_27 ] . V_112 . V_134 ) ) ;
}
}
V_75 = F_82 ( V_9 , V_64 ,
V_185 [ V_27 ] . V_112 . V_134 ,
V_185 [ V_27 ] . V_171 ) ;
if ( F_84 ( V_75 ) ) {
V_19 = F_85 ( V_75 ) ;
goto V_163;
}
if ( V_9 -> V_111 == 0 ) {
if ( V_27 + 1 < V_180 ) {
V_3 = F_74 ( V_185 [ V_27 + 1 ] . V_171 ) ;
V_3 -= F_74 ( V_185 [ V_27 ] . V_171 ) ;
V_3 *= 4 ;
F_57 ( V_9 , V_75 , 0 ,
V_3 , NULL , 0 , 0 ) ;
} else {
F_58 ( V_9 , L_72 ,
F_74 ( V_185 [ V_27 ] . V_112 . V_134 ) ) ;
}
}
}
V_163:
F_10 ( V_185 ) ;
return V_19 ;
}
static int F_86 ( struct V_8 * V_9 )
{
struct V_186 V_187 ;
struct V_188 * V_189 ;
struct V_74 * V_75 ;
const struct V_55 * V_57 ;
unsigned int V_124 , V_3 ;
T_1 V_180 ;
int V_27 , V_19 ;
V_57 = F_34 ( V_9 , V_62 ) ;
if ( F_36 ( ! V_57 ) )
return - V_52 ;
V_19 = F_39 ( V_9 -> V_66 , V_57 -> V_60 , & V_187 ,
sizeof( V_187 ) ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_68 ,
V_19 ) ;
return V_19 ;
}
V_180 = F_74 ( V_187 . V_180 ) ;
V_9 -> V_34 = F_74 ( V_187 . V_50 . V_134 ) ;
V_9 -> V_35 = F_74 ( V_187 . V_50 . V_166 ) ;
F_72 ( V_9 , L_69 ,
V_9 -> V_34 ,
( V_9 -> V_35 & 0xff0000 ) >> 16 ,
( V_9 -> V_35 & 0xff00 ) >> 8 ,
V_9 -> V_35 & 0xff ,
V_180 ) ;
V_75 = F_82 ( V_9 , V_62 ,
V_187 . V_50 . V_134 , V_187 . V_173 ) ;
if ( F_84 ( V_75 ) )
return F_85 ( V_75 ) ;
V_75 = F_82 ( V_9 , V_63 ,
V_187 . V_50 . V_134 , V_187 . V_174 ) ;
if ( F_84 ( V_75 ) )
return F_85 ( V_75 ) ;
V_75 = F_82 ( V_9 , V_190 ,
V_187 . V_50 . V_134 , V_187 . V_171 ) ;
if ( F_84 ( V_75 ) )
return F_85 ( V_75 ) ;
V_124 = sizeof( V_187 ) / 2 ;
V_3 = ( sizeof( * V_189 ) * V_180 ) / 2 ;
V_189 = F_79 ( V_9 , V_180 , V_57 -> V_60 + V_124 , V_3 ) ;
if ( F_84 ( V_189 ) )
return F_85 ( V_189 ) ;
for ( V_27 = 0 ; V_27 < V_180 ; V_27 ++ ) {
F_72 ( V_9 ,
L_73 ,
V_27 , F_74 ( V_189 [ V_27 ] . V_112 . V_134 ) ,
( F_74 ( V_189 [ V_27 ] . V_112 . V_166 ) & 0xff0000 ) >> 16 ,
( F_74 ( V_189 [ V_27 ] . V_112 . V_166 ) & 0xff00 ) >> 8 ,
F_74 ( V_189 [ V_27 ] . V_112 . V_166 ) & 0xff ,
F_74 ( V_189 [ V_27 ] . V_173 ) ,
F_74 ( V_189 [ V_27 ] . V_174 ) ,
F_74 ( V_189 [ V_27 ] . V_171 ) ) ;
V_75 = F_82 ( V_9 , V_62 ,
V_189 [ V_27 ] . V_112 . V_134 ,
V_189 [ V_27 ] . V_173 ) ;
if ( F_84 ( V_75 ) ) {
V_19 = F_85 ( V_75 ) ;
goto V_163;
}
if ( V_9 -> V_111 == 0 ) {
if ( V_27 + 1 < V_180 ) {
V_3 = F_74 ( V_189 [ V_27 + 1 ] . V_173 ) ;
V_3 -= F_74 ( V_189 [ V_27 ] . V_173 ) ;
V_3 *= 4 ;
F_57 ( V_9 , V_75 , 0 ,
V_3 , NULL , 0 , 0 ) ;
} else {
F_58 ( V_9 , L_74 ,
F_74 ( V_189 [ V_27 ] . V_112 . V_134 ) ) ;
}
}
V_75 = F_82 ( V_9 , V_63 ,
V_189 [ V_27 ] . V_112 . V_134 ,
V_189 [ V_27 ] . V_174 ) ;
if ( F_84 ( V_75 ) ) {
V_19 = F_85 ( V_75 ) ;
goto V_163;
}
if ( V_9 -> V_111 == 0 ) {
if ( V_27 + 1 < V_180 ) {
V_3 = F_74 ( V_189 [ V_27 + 1 ] . V_174 ) ;
V_3 -= F_74 ( V_189 [ V_27 ] . V_174 ) ;
V_3 *= 4 ;
F_57 ( V_9 , V_75 , 0 ,
V_3 , NULL , 0 , 0 ) ;
} else {
F_58 ( V_9 , L_75 ,
F_74 ( V_189 [ V_27 ] . V_112 . V_134 ) ) ;
}
}
V_75 = F_82 ( V_9 , V_190 ,
V_189 [ V_27 ] . V_112 . V_134 ,
V_189 [ V_27 ] . V_171 ) ;
if ( F_84 ( V_75 ) ) {
V_19 = F_85 ( V_75 ) ;
goto V_163;
}
if ( V_9 -> V_111 == 0 ) {
if ( V_27 + 1 < V_180 ) {
V_3 = F_74 ( V_189 [ V_27 + 1 ] . V_171 ) ;
V_3 -= F_74 ( V_189 [ V_27 ] . V_171 ) ;
V_3 *= 4 ;
F_57 ( V_9 , V_75 , 0 ,
V_3 , NULL , 0 , 0 ) ;
} else {
F_58 ( V_9 , L_72 ,
F_74 ( V_189 [ V_27 ] . V_112 . V_134 ) ) ;
}
}
}
V_163:
F_10 ( V_189 ) ;
return V_19 ;
}
static int F_87 ( struct V_8 * V_9 )
{
F_70 ( V_147 ) ;
struct V_66 * V_66 = V_9 -> V_66 ;
struct V_191 * V_139 ;
struct V_192 * V_131 ;
const struct V_148 * V_148 ;
const struct V_55 * V_57 ;
struct V_74 * V_75 ;
const char * V_109 ;
int V_19 , V_124 , V_193 , type , V_58 , V_76 ;
char * V_14 ;
struct V_1 * V_6 ;
V_14 = F_2 ( V_31 , V_7 ) ;
if ( V_14 == NULL )
return - V_78 ;
snprintf ( V_14 , V_31 , L_76 , V_9 -> V_160 , V_9 -> V_32 ,
V_161 [ V_9 -> V_50 ] . V_14 ) ;
V_14 [ V_31 - 1 ] = '\0' ;
V_19 = F_71 ( & V_148 , V_14 , V_9 -> V_162 ) ;
if ( V_19 != 0 ) {
F_58 ( V_9 , L_38 , V_14 ) ;
V_19 = 0 ;
goto V_163;
}
V_19 = - V_52 ;
if ( sizeof( * V_139 ) >= V_148 -> V_140 ) {
F_21 ( V_9 , L_39 ,
V_14 , V_148 -> V_140 ) ;
goto V_164;
}
V_139 = ( void * ) & V_148 -> V_81 [ 0 ] ;
if ( memcmp ( V_139 -> V_165 , L_77 , 4 ) != 0 ) {
F_21 ( V_9 , L_41 , V_14 ) ;
goto V_164;
}
switch ( F_74 ( V_139 -> V_194 ) & 0xff ) {
case 1 :
break;
default:
F_21 ( V_9 , L_78 ,
V_14 , F_74 ( V_139 -> V_194 ) & 0xff ) ;
V_19 = - V_52 ;
goto V_164;
}
F_40 ( V_9 , L_79 , V_14 ,
( F_65 ( V_139 -> V_166 ) >> 16 ) & 0xff ,
( F_65 ( V_139 -> V_166 ) >> 8 ) & 0xff ,
F_65 ( V_139 -> V_166 ) & 0xff ) ;
V_124 = F_65 ( V_139 -> V_3 ) ;
V_193 = 0 ;
while ( V_124 < V_148 -> V_140 &&
V_124 - V_148 -> V_140 > sizeof( * V_131 ) ) {
V_131 = ( void * ) ( & V_148 -> V_81 [ V_124 ] ) ;
type = F_63 ( V_131 -> type ) ;
V_58 = F_63 ( V_131 -> V_58 ) ;
F_40 ( V_9 , L_80 ,
V_14 , V_193 , F_65 ( V_131 -> V_134 ) ,
( F_65 ( V_131 -> V_166 ) >> 16 ) & 0xff ,
( F_65 ( V_131 -> V_166 ) >> 8 ) & 0xff ,
F_65 ( V_131 -> V_166 ) & 0xff ) ;
F_40 ( V_9 , L_81 ,
V_14 , V_193 , F_65 ( V_131 -> V_3 ) , V_58 , type ) ;
V_76 = 0 ;
V_109 = L_51 ;
switch ( type ) {
case ( V_176 << 8 ) :
case ( V_178 << 8 ) :
break;
case ( V_179 << 8 ) :
if ( F_65 ( V_131 -> V_134 ) == V_9 -> V_34 &&
V_58 == 0 ) {
V_109 = L_82 ;
V_57 = F_34 ( V_9 , type ) ;
if ( ! V_57 ) {
F_21 ( V_9 , L_83 ) ;
break;
}
V_76 = F_35 ( V_57 , 0 ) ;
} else {
V_109 = L_84 ;
V_76 = V_58 ;
}
break;
case V_61 :
case V_64 :
case V_62 :
case V_63 :
F_40 ( V_9 , L_85 ,
V_14 , V_193 , F_65 ( V_131 -> V_3 ) ,
type , F_65 ( V_131 -> V_134 ) ) ;
V_57 = F_34 ( V_9 , type ) ;
if ( ! V_57 ) {
F_21 ( V_9 , L_11 , type ) ;
break;
}
V_75 = F_81 ( V_9 , type ,
F_65 ( V_131 -> V_134 ) ) ;
if ( V_75 ) {
V_76 = V_75 -> V_60 ;
V_76 = F_35 ( V_57 , V_76 ) ;
V_76 += V_58 ;
} else {
F_21 ( V_9 , L_86 ,
type , F_65 ( V_131 -> V_134 ) ) ;
}
break;
default:
F_21 ( V_9 , L_87 ,
V_14 , V_193 , type , V_124 ) ;
break;
}
if ( V_76 ) {
V_6 = F_1 ( V_131 -> V_81 ,
F_65 ( V_131 -> V_3 ) ,
& V_147 ) ;
if ( ! V_6 ) {
F_21 ( V_9 , L_59 ) ;
V_19 = - V_78 ;
goto V_164;
}
F_40 ( V_9 , L_88 ,
V_14 , V_193 , F_65 ( V_131 -> V_3 ) ,
V_76 ) ;
V_19 = F_75 ( V_66 , V_76 , V_6 -> V_6 ,
F_65 ( V_131 -> V_3 ) ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 ,
L_89 ,
V_14 , V_193 , V_76 , V_109 , V_19 ) ;
}
}
V_124 += ( F_65 ( V_131 -> V_3 ) + sizeof( * V_131 ) + 3 ) & ~ 0x03 ;
V_193 ++ ;
}
V_19 = F_76 ( V_66 ) ;
if ( V_19 != 0 )
F_21 ( V_9 , L_61 , V_19 ) ;
if ( V_124 > V_148 -> V_140 )
F_58 ( V_9 , L_62 ,
V_14 , V_193 , V_124 - V_148 -> V_140 ) ;
F_13 ( V_9 , V_14 ) ;
V_164:
F_76 ( V_66 ) ;
F_77 ( V_148 ) ;
F_6 ( & V_147 ) ;
V_163:
F_10 ( V_14 ) ;
return V_19 ;
}
int F_88 ( struct V_8 * V_9 )
{
F_89 ( & V_9 -> V_181 ) ;
F_90 ( & V_9 -> V_20 ) ;
return 0 ;
}
int F_91 ( struct V_195 * V_196 ,
struct V_39 * V_40 ,
int V_197 )
{
struct V_22 * V_23 = F_92 ( V_196 -> V_198 ) ;
struct V_8 * V_199 = F_32 ( V_23 ) ;
struct V_8 * V_9 = & V_199 [ V_196 -> V_200 ] ;
struct V_74 * V_75 ;
struct V_71 * V_72 ;
int V_19 ;
unsigned int V_128 ;
V_9 -> V_100 = V_23 -> V_28 . V_100 ;
F_16 ( & V_9 -> V_20 ) ;
switch ( V_197 ) {
case V_201 :
F_93 ( V_9 -> V_66 , V_9 -> V_60 + V_202 ,
V_203 , V_203 ) ;
if ( V_9 -> V_204 ) {
V_19 = F_94 ( V_9 -> V_66 , V_9 -> V_204 , & V_128 ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_90 ,
V_19 ) ;
goto V_205;
}
V_128 = ( V_128 & V_9 -> V_206 )
>> V_9 -> V_207 ;
V_19 = F_93 ( V_9 -> V_66 ,
V_9 -> V_60 + V_208 ,
V_209 , V_128 ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_91 ,
V_19 ) ;
goto V_205;
}
}
V_19 = F_69 ( V_9 ) ;
if ( V_19 != 0 )
goto V_210;
V_19 = F_83 ( V_9 ) ;
if ( V_19 != 0 )
goto V_210;
V_19 = F_87 ( V_9 ) ;
if ( V_19 != 0 )
goto V_210;
V_19 = F_52 ( V_9 ) ;
if ( V_19 != 0 )
goto V_210;
V_19 = F_54 ( V_9 ) ;
if ( V_19 != 0 )
goto V_210;
F_93 ( V_9 -> V_66 , V_9 -> V_60 + V_202 ,
V_211 | V_212 ,
V_211 | V_212 ) ;
break;
case V_213 :
F_93 ( V_9 -> V_66 , V_9 -> V_60 + V_202 ,
V_211 | V_212 , 0 ) ;
F_93 ( V_9 -> V_66 , V_9 -> V_60 + V_214 ,
V_215 , 0 ) ;
F_93 ( V_9 -> V_66 , V_9 -> V_60 + V_202 ,
V_203 , 0 ) ;
F_53 (ctl, &dsp->ctl_list, list)
V_72 -> V_84 = 0 ;
while ( ! F_7 ( & V_9 -> V_181 ) ) {
V_75 = F_8 ( & V_9 -> V_181 ,
struct V_74 ,
V_5 ) ;
F_9 ( & V_75 -> V_5 ) ;
F_10 ( V_75 ) ;
}
break;
default:
break;
}
F_18 ( & V_9 -> V_20 ) ;
return 0 ;
V_210:
F_93 ( V_9 -> V_66 , V_9 -> V_60 + V_202 ,
V_203 , 0 ) ;
V_205:
F_18 ( & V_9 -> V_20 ) ;
return V_19 ;
}
static int F_95 ( struct V_8 * V_9 )
{
unsigned int V_128 ;
int V_19 , V_16 ;
V_19 = F_96 ( V_9 -> V_66 , V_9 -> V_60 + V_216 ,
V_217 , V_217 ) ;
if ( V_19 != 0 )
return V_19 ;
for ( V_16 = 0 ; V_16 < 10 ; ++ V_16 ) {
V_19 = F_94 ( V_9 -> V_66 , V_9 -> V_60 + V_218 ,
& V_128 ) ;
if ( V_19 != 0 )
return V_19 ;
if ( V_128 & V_219 )
break;
F_97 ( 1 ) ;
}
if ( ! ( V_128 & V_219 ) ) {
F_21 ( V_9 , L_92 ) ;
return - V_54 ;
}
F_40 ( V_9 , L_93 , V_16 ) ;
return 0 ;
}
static void F_98 ( struct V_102 * V_103 )
{
struct V_8 * V_9 = F_56 ( V_103 ,
struct V_8 ,
V_220 ) ;
int V_19 ;
unsigned int V_128 ;
F_16 ( & V_9 -> V_20 ) ;
V_19 = F_94 ( V_9 -> V_66 , V_221 , & V_128 ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_90 , V_19 ) ;
goto V_205;
}
V_128 = ( V_128 & V_222 )
>> V_223 ;
V_19 = F_96 ( V_9 -> V_66 ,
V_9 -> V_60 + V_224 ,
V_225 , V_128 ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_91 , V_19 ) ;
goto V_205;
}
V_19 = F_95 ( V_9 ) ;
if ( V_19 != 0 )
goto V_205;
V_19 = F_69 ( V_9 ) ;
if ( V_19 != 0 )
goto V_210;
V_19 = F_86 ( V_9 ) ;
if ( V_19 != 0 )
goto V_210;
V_19 = F_87 ( V_9 ) ;
if ( V_19 != 0 )
goto V_210;
V_19 = F_52 ( V_9 ) ;
if ( V_19 != 0 )
goto V_210;
V_19 = F_54 ( V_9 ) ;
if ( V_19 != 0 )
goto V_210;
V_9 -> V_21 = true ;
F_18 ( & V_9 -> V_20 ) ;
return;
V_210:
F_93 ( V_9 -> V_66 , V_9 -> V_60 + V_216 ,
V_217 | V_226 | V_227 , 0 ) ;
V_205:
F_18 ( & V_9 -> V_20 ) ;
}
int F_99 ( struct V_195 * V_196 ,
struct V_39 * V_40 , int V_197 )
{
struct V_22 * V_23 = F_92 ( V_196 -> V_198 ) ;
struct V_8 * V_199 = F_32 ( V_23 ) ;
struct V_8 * V_9 = & V_199 [ V_196 -> V_200 ] ;
V_9 -> V_100 = V_23 -> V_28 . V_100 ;
switch ( V_197 ) {
case V_228 :
F_100 ( V_229 , & V_9 -> V_220 ) ;
break;
default:
break;
}
return 0 ;
}
int F_101 ( struct V_195 * V_196 ,
struct V_39 * V_40 , int V_197 )
{
struct V_22 * V_23 = F_92 ( V_196 -> V_198 ) ;
struct V_8 * V_199 = F_32 ( V_23 ) ;
struct V_8 * V_9 = & V_199 [ V_196 -> V_200 ] ;
struct V_74 * V_75 ;
struct V_71 * V_72 ;
int V_19 ;
switch ( V_197 ) {
case V_201 :
F_102 ( & V_9 -> V_220 ) ;
if ( ! V_9 -> V_21 )
return - V_230 ;
V_19 = F_93 ( V_9 -> V_66 ,
V_9 -> V_60 + V_216 ,
V_226 | V_227 ,
V_226 | V_227 ) ;
if ( V_19 != 0 )
goto V_30;
if ( V_161 [ V_9 -> V_50 ] . V_231 != 0 )
V_19 = F_103 ( V_9 ) ;
break;
case V_213 :
F_38 ( V_9 ) ;
F_16 ( & V_9 -> V_20 ) ;
F_14 ( V_9 ) ;
V_9 -> V_34 = 0 ;
V_9 -> V_35 = 0 ;
V_9 -> V_21 = false ;
F_93 ( V_9 -> V_66 , V_9 -> V_60 + V_216 ,
V_217 | V_226 |
V_227 , 0 ) ;
F_104 ( V_9 -> V_66 , V_9 -> V_60 + V_232 , 0 ) ;
F_104 ( V_9 -> V_66 , V_9 -> V_60 + V_233 , 0 ) ;
F_104 ( V_9 -> V_66 , V_9 -> V_60 + V_234 , 0 ) ;
F_53 (ctl, &dsp->ctl_list, list)
V_72 -> V_84 = 0 ;
while ( ! F_7 ( & V_9 -> V_181 ) ) {
V_75 = F_8 ( & V_9 -> V_181 ,
struct V_74 ,
V_5 ) ;
F_9 ( & V_75 -> V_5 ) ;
F_10 ( V_75 ) ;
}
if ( V_161 [ V_9 -> V_50 ] . V_231 != 0 )
F_105 ( V_9 ) ;
F_18 ( & V_9 -> V_20 ) ;
F_40 ( V_9 , L_94 ) ;
break;
default:
break;
}
return 0 ;
V_30:
F_93 ( V_9 -> V_66 , V_9 -> V_60 + V_216 ,
V_217 | V_226 | V_227 , 0 ) ;
return V_19 ;
}
int F_106 ( struct V_8 * V_9 , struct V_22 * V_23 )
{
F_20 ( V_9 , V_23 ) ;
return F_107 ( V_23 ,
& V_235 [ V_9 -> V_32 - 1 ] ,
1 ) ;
}
int F_108 ( struct V_8 * V_9 , struct V_22 * V_23 )
{
F_29 ( V_9 ) ;
return 0 ;
}
int F_109 ( struct V_8 * V_9 )
{
int V_19 ;
V_19 = F_93 ( V_9 -> V_66 , V_9 -> V_60 + V_216 ,
V_236 , 0 ) ;
if ( V_19 != 0 ) {
F_21 ( V_9 , L_95 , V_19 ) ;
return V_19 ;
}
F_89 ( & V_9 -> V_181 ) ;
F_89 ( & V_9 -> V_122 ) ;
F_60 ( & V_9 -> V_220 , F_98 ) ;
F_90 ( & V_9 -> V_20 ) ;
return 0 ;
}
int F_110 ( struct V_8 * V_9 , struct V_237 * V_238 )
{
struct V_239 * V_53 ;
int V_19 = 0 ;
F_16 ( & V_9 -> V_20 ) ;
if ( V_161 [ V_9 -> V_50 ] . V_231 == 0 ) {
F_21 ( V_9 , L_96 ) ;
V_19 = - V_240 ;
goto V_163;
}
if ( V_161 [ V_9 -> V_50 ] . V_241 != V_238 -> V_242 ) {
F_21 ( V_9 , L_97 ) ;
V_19 = - V_52 ;
goto V_163;
}
if ( V_9 -> V_53 ) {
F_21 ( V_9 , L_98 ) ;
V_19 = - V_54 ;
goto V_163;
}
V_53 = F_2 ( sizeof( * V_53 ) , V_7 ) ;
if ( ! V_53 ) {
V_19 = - V_78 ;
goto V_163;
}
V_53 -> V_9 = V_9 ;
V_53 -> V_238 = V_238 ;
V_9 -> V_53 = V_53 ;
V_238 -> V_243 -> V_18 = V_53 ;
V_163:
F_18 ( & V_9 -> V_20 ) ;
return V_19 ;
}
int F_111 ( struct V_237 * V_238 )
{
struct V_239 * V_53 = V_238 -> V_243 -> V_18 ;
struct V_8 * V_9 = V_53 -> V_9 ;
F_16 ( & V_9 -> V_20 ) ;
V_9 -> V_53 = NULL ;
F_10 ( V_53 -> V_244 ) ;
F_10 ( V_53 ) ;
F_18 ( & V_9 -> V_20 ) ;
return 0 ;
}
static int F_112 ( struct V_237 * V_238 ,
struct V_245 * V_246 )
{
struct V_239 * V_53 = V_238 -> V_243 -> V_18 ;
struct V_8 * V_9 = V_53 -> V_9 ;
const struct V_247 * V_248 ;
const struct V_249 * V_250 ;
int V_27 , V_251 ;
if ( V_246 -> V_252 . V_253 < V_254 ||
V_246 -> V_252 . V_253 > V_255 ||
V_246 -> V_252 . V_256 < V_257 ||
V_246 -> V_252 . V_256 > V_258 ||
V_246 -> V_252 . V_253 % V_259 ) {
F_21 ( V_9 , L_99 ,
V_246 -> V_252 . V_253 ,
V_246 -> V_252 . V_256 ) ;
return - V_52 ;
}
for ( V_27 = 0 ; V_27 < V_161 [ V_9 -> V_50 ] . V_231 ; V_27 ++ ) {
V_248 = & V_161 [ V_9 -> V_50 ] . V_248 [ V_27 ] ;
V_250 = & V_248 -> V_250 ;
if ( V_248 -> V_134 != V_246 -> V_23 . V_134 )
continue;
if ( V_238 -> V_242 == V_260 ) {
if ( V_250 -> V_261 < V_246 -> V_23 . V_262 )
continue;
} else {
if ( V_250 -> V_261 < V_246 -> V_23 . V_263 )
continue;
}
if ( ! ( V_250 -> V_264 & ( 1 << V_246 -> V_23 . V_265 ) ) )
continue;
for ( V_251 = 0 ; V_251 < V_250 -> V_266 ; ++ V_251 )
if ( V_250 -> V_267 [ V_251 ] == V_246 -> V_23 . V_268 )
return 0 ;
}
F_21 ( V_9 , L_100 ,
V_246 -> V_23 . V_134 , V_246 -> V_23 . V_263 , V_246 -> V_23 . V_262 ,
V_246 -> V_23 . V_268 , V_246 -> V_23 . V_265 ) ;
return - V_52 ;
}
static inline unsigned int F_113 ( struct V_239 * V_53 )
{
return V_53 -> V_140 . V_253 / V_259 ;
}
int F_114 ( struct V_237 * V_238 ,
struct V_245 * V_246 )
{
struct V_239 * V_53 = V_238 -> V_243 -> V_18 ;
unsigned int V_140 ;
int V_19 ;
V_19 = F_112 ( V_238 , V_246 ) ;
if ( V_19 )
return V_19 ;
V_53 -> V_140 = V_246 -> V_252 ;
F_40 ( V_53 -> V_9 , L_101 ,
V_53 -> V_140 . V_253 , V_53 -> V_140 . V_256 ) ;
V_140 = F_113 ( V_53 ) * sizeof( * V_53 -> V_244 ) ;
V_53 -> V_244 = F_22 ( V_140 , V_77 | V_7 ) ;
if ( ! V_53 -> V_244 )
return - V_78 ;
return 0 ;
}
int F_115 ( struct V_237 * V_238 ,
struct V_269 * V_248 )
{
struct V_239 * V_53 = V_238 -> V_243 -> V_18 ;
int V_50 = V_53 -> V_9 -> V_50 ;
int V_27 ;
if ( V_161 [ V_50 ] . V_248 ) {
for ( V_27 = 0 ; V_27 < V_161 [ V_50 ] . V_231 ; V_27 ++ )
V_248 -> V_270 [ V_27 ] = V_161 [ V_50 ] . V_248 [ V_27 ] . V_134 ;
V_248 -> V_271 = V_27 ;
V_248 -> V_242 = V_161 [ V_50 ] . V_241 ;
V_248 -> V_272 = V_254 ;
V_248 -> V_273 = V_255 ;
V_248 -> V_274 = V_257 ;
V_248 -> V_275 = V_258 ;
}
return 0 ;
}
static int F_116 ( struct V_8 * V_9 , int V_141 ,
unsigned int V_276 ,
unsigned int V_277 , T_8 * V_81 )
{
struct V_55 const * V_57 = F_34 ( V_9 , V_141 ) ;
unsigned int V_27 , V_76 ;
int V_19 ;
if ( ! V_57 )
return - V_52 ;
V_76 = F_35 ( V_57 , V_276 ) ;
V_19 = F_39 ( V_9 -> V_66 , V_76 , V_81 ,
sizeof( * V_81 ) * V_277 ) ;
if ( V_19 < 0 )
return V_19 ;
for ( V_27 = 0 ; V_27 < V_277 ; ++ V_27 )
V_81 [ V_27 ] = F_74 ( V_81 [ V_27 ] ) & 0x00ffffffu ;
return 0 ;
}
static inline int F_117 ( struct V_8 * V_9 , int V_141 ,
unsigned int V_276 , T_8 * V_81 )
{
return F_116 ( V_9 , V_141 , V_276 , 1 , V_81 ) ;
}
static int F_118 ( struct V_8 * V_9 , int V_141 ,
unsigned int V_276 , T_8 V_81 )
{
struct V_55 const * V_57 = F_34 ( V_9 , V_141 ) ;
unsigned int V_76 ;
if ( ! V_57 )
return - V_52 ;
V_76 = F_35 ( V_57 , V_276 ) ;
V_81 = F_119 ( V_81 & 0x00ffffffu ) ;
return F_45 ( V_9 -> V_66 , V_76 , & V_81 , sizeof( V_81 ) ) ;
}
static inline int F_120 ( struct V_278 * V_6 ,
unsigned int V_279 , T_8 * V_81 )
{
return F_117 ( V_6 -> V_9 , V_62 ,
V_6 -> V_280 + V_279 , V_81 ) ;
}
static inline int F_121 ( struct V_278 * V_6 ,
unsigned int V_279 , T_8 V_81 )
{
return F_118 ( V_6 -> V_9 , V_62 ,
V_6 -> V_280 + V_279 , V_81 ) ;
}
static int F_122 ( struct V_278 * V_6 )
{
struct V_74 * V_75 ;
struct V_8 * V_9 = V_6 -> V_9 ;
T_8 V_281 , V_282 , V_165 ;
int V_27 , V_19 ;
V_75 = F_81 ( V_9 , V_62 , V_9 -> V_34 ) ;
V_281 = sizeof( struct V_283 ) / sizeof( T_7 ) ;
V_282 = V_75 -> V_60 + V_281 + F_123 ( V_165 ) ;
V_19 = F_117 ( V_9 , V_62 , V_282 , & V_165 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_165 != V_284 )
return - V_52 ;
V_282 = V_75 -> V_60 + V_281 + F_123 ( V_280 ) ;
for ( V_27 = 0 ; V_27 < 5 ; ++ V_27 ) {
V_19 = F_117 ( V_9 , V_62 , V_282 ,
& V_6 -> V_280 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_6 -> V_280 )
break;
F_124 ( 1000 , 2000 ) ;
}
if ( ! V_6 -> V_280 )
return - V_230 ;
F_40 ( V_9 , L_102 , V_6 -> V_280 ) ;
return 0 ;
}
static int F_125 ( struct V_278 * V_6 )
{
const struct V_247 * V_248 = V_161 [ V_6 -> V_9 -> V_50 ] . V_248 ;
struct V_285 * V_144 ;
T_8 V_58 = 0 ;
int V_27 , V_19 ;
for ( V_27 = 0 ; V_27 < V_248 -> V_286 ; ++ V_27 ) {
V_144 = & V_6 -> V_158 [ V_27 ] ;
V_144 -> V_58 = V_58 ;
V_144 -> V_141 = V_248 -> V_287 [ V_27 ] . V_141 ;
V_19 = F_120 ( V_6 , V_248 -> V_287 [ V_27 ] . V_288 ,
& V_144 -> V_289 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_120 ( V_6 , V_248 -> V_287 [ V_27 ] . V_290 ,
& V_58 ) ;
if ( V_19 < 0 )
return V_19 ;
V_144 -> V_291 = V_58 ;
F_40 ( V_6 -> V_9 ,
L_103 ,
V_27 , V_144 -> V_141 , V_144 -> V_289 ,
V_144 -> V_58 , V_144 -> V_291 ) ;
}
return 0 ;
}
static int F_103 ( struct V_8 * V_9 )
{
struct V_278 * V_6 ;
int V_19 ;
V_6 = F_2 ( sizeof( * V_6 ) , V_7 ) ;
if ( ! V_6 )
return - V_78 ;
V_6 -> V_9 = V_9 ;
V_6 -> V_292 = - 1 ;
V_6 -> V_293 = 0xFFFFFFFF ;
V_19 = F_122 ( V_6 ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 , L_104 , V_19 ) ;
goto V_294;
}
V_6 -> V_158 = F_126 ( V_161 [ V_9 -> V_50 ] . V_248 -> V_286 ,
sizeof( * V_6 -> V_158 ) , V_7 ) ;
if ( ! V_6 -> V_158 ) {
V_19 = - V_78 ;
goto V_294;
}
V_19 = F_125 ( V_6 ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 , L_105 , V_19 ) ;
goto V_295;
}
V_9 -> V_252 = V_6 ;
return 0 ;
V_295:
F_10 ( V_6 -> V_158 ) ;
V_294:
F_10 ( V_6 ) ;
return V_19 ;
}
static int F_105 ( struct V_8 * V_9 )
{
if ( V_9 -> V_252 ) {
F_10 ( V_9 -> V_252 -> V_158 ) ;
F_10 ( V_9 -> V_252 ) ;
V_9 -> V_252 = NULL ;
}
return 0 ;
}
static inline int F_127 ( struct V_239 * V_53 )
{
return V_53 -> V_6 != NULL ;
}
static int F_128 ( struct V_239 * V_53 )
{
if ( ! V_53 -> V_9 -> V_252 )
return - V_52 ;
V_53 -> V_6 = V_53 -> V_9 -> V_252 ;
return 0 ;
}
int F_129 ( struct V_237 * V_238 , int V_296 )
{
struct V_239 * V_53 = V_238 -> V_243 -> V_18 ;
struct V_8 * V_9 = V_53 -> V_9 ;
int V_19 = 0 ;
F_40 ( V_9 , L_106 , V_296 ) ;
F_16 ( & V_9 -> V_20 ) ;
switch ( V_296 ) {
case V_297 :
if ( F_127 ( V_53 ) )
break;
V_19 = F_128 ( V_53 ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 , L_107 ,
V_19 ) ;
break;
}
V_19 = F_121 ( V_53 -> V_6 ,
F_130 ( V_298 ) ,
F_113 ( V_53 ) ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 , L_108 ,
V_19 ) ;
break;
}
break;
case V_299 :
break;
default:
V_19 = - V_52 ;
break;
}
F_18 ( & V_9 -> V_20 ) ;
return V_19 ;
}
static inline int F_131 ( struct V_278 * V_6 )
{
int V_300 = V_161 [ V_6 -> V_9 -> V_50 ] . V_248 -> V_286 - 1 ;
return V_6 -> V_158 [ V_300 ] . V_291 ;
}
static int F_132 ( struct V_278 * V_6 )
{
T_8 V_301 , V_302 ;
int V_303 , V_292 , V_114 ;
int V_19 ;
if ( V_6 -> V_292 < 0 ) {
V_19 = F_120 ( V_6 ,
F_130 ( V_301 ) ,
& V_301 ) ;
if ( V_19 < 0 )
return V_19 ;
V_292 = F_133 ( V_301 , 23 ) ;
if ( V_292 < 0 ) {
F_40 ( V_6 -> V_9 , L_109 ) ;
return 0 ;
}
V_6 -> V_292 = V_292 ;
}
V_19 = F_120 ( V_6 , F_130 ( V_302 ) ,
& V_302 ) ;
if ( V_19 < 0 )
return V_19 ;
V_303 = F_133 ( V_302 , 23 ) ;
V_114 = V_303 - V_6 -> V_292 ;
if ( V_114 < 0 )
V_114 += F_131 ( V_6 ) ;
F_40 ( V_6 -> V_9 , L_110 ,
V_6 -> V_292 , V_303 , V_114 ) ;
V_6 -> V_114 = V_114 ;
return 0 ;
}
int F_134 ( struct V_8 * V_9 )
{
struct V_278 * V_6 = V_9 -> V_252 ;
struct V_239 * V_53 = V_9 -> V_53 ;
int V_19 = 0 ;
F_16 ( & V_9 -> V_20 ) ;
if ( ! V_6 ) {
F_21 ( V_9 , L_111 ) ;
V_19 = - V_304 ;
goto V_163;
}
F_40 ( V_9 , L_112 ) ;
V_19 = F_120 ( V_6 , F_130 ( error ) , & V_6 -> error ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 , L_113 , V_19 ) ;
goto V_163;
}
if ( V_6 -> error != 0 ) {
F_21 ( V_9 , L_114 , V_6 -> error ) ;
V_19 = - V_230 ;
goto V_163;
}
V_19 = F_120 ( V_6 , F_130 ( V_293 ) ,
& V_6 -> V_293 ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 , L_115 , V_19 ) ;
goto V_163;
}
V_19 = F_132 ( V_6 ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 , L_116 , V_19 ) ;
goto V_163;
}
if ( V_53 -> V_238 )
F_135 ( V_53 -> V_238 ) ;
V_163:
F_18 ( & V_9 -> V_20 ) ;
return V_19 ;
}
static int F_136 ( struct V_278 * V_6 )
{
if ( V_6 -> V_293 & 0x01 )
return 0 ;
F_40 ( V_6 -> V_9 , L_117 ,
V_6 -> V_293 ) ;
V_6 -> V_293 |= 0x01 ;
return F_121 ( V_6 , F_130 ( V_305 ) ,
V_6 -> V_293 ) ;
}
int F_137 ( struct V_237 * V_238 ,
struct V_306 * V_307 )
{
struct V_239 * V_53 = V_238 -> V_243 -> V_18 ;
struct V_278 * V_6 = V_53 -> V_6 ;
struct V_8 * V_9 = V_53 -> V_9 ;
int V_19 = 0 ;
F_40 ( V_9 , L_118 ) ;
F_16 ( & V_9 -> V_20 ) ;
if ( ! V_53 -> V_6 ) {
V_19 = - V_240 ;
goto V_163;
}
if ( V_53 -> V_6 -> error ) {
V_19 = - V_230 ;
goto V_163;
}
if ( V_6 -> V_114 < F_113 ( V_53 ) ) {
V_19 = F_132 ( V_6 ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 , L_116 , V_19 ) ;
goto V_163;
}
if ( V_6 -> V_114 < F_113 ( V_53 ) ) {
V_19 = F_136 ( V_6 ) ;
if ( V_19 < 0 ) {
F_21 ( V_9 ,
L_119 ,
V_19 ) ;
goto V_163;
}
}
}
V_307 -> V_308 = V_53 -> V_308 ;
V_307 -> V_308 += V_6 -> V_114 * V_259 ;
V_163:
F_18 ( & V_9 -> V_20 ) ;
return V_19 ;
}
static int F_138 ( struct V_239 * V_53 , int V_309 )
{
struct V_278 * V_6 = V_53 -> V_6 ;
T_6 * V_310 = ( T_6 * ) V_53 -> V_244 ;
T_6 * V_311 = ( T_6 * ) V_53 -> V_244 ;
unsigned int V_312 ;
int V_141 , V_313 , V_314 ;
int V_27 , V_251 , V_19 ;
for ( V_27 = 0 ; V_27 < V_161 [ V_6 -> V_9 -> V_50 ] . V_248 -> V_286 ; ++ V_27 )
if ( V_6 -> V_292 < V_6 -> V_158 [ V_27 ] . V_291 )
break;
if ( V_27 == V_161 [ V_6 -> V_9 -> V_50 ] . V_248 -> V_286 )
return - V_52 ;
V_141 = V_6 -> V_158 [ V_27 ] . V_141 ;
V_312 = V_6 -> V_158 [ V_27 ] . V_289 +
( V_6 -> V_292 - V_6 -> V_158 [ V_27 ] . V_58 ) ;
V_314 = F_113 ( V_53 ) ;
V_313 = V_6 -> V_158 [ V_27 ] . V_291 - V_6 -> V_292 ;
if ( V_313 > V_309 )
V_313 = V_309 ;
if ( V_313 > V_6 -> V_114 )
V_313 = V_6 -> V_114 ;
if ( V_313 > V_314 )
V_313 = V_314 ;
if ( ! V_313 )
return 0 ;
V_19 = F_116 ( V_6 -> V_9 , V_141 , V_312 ,
V_313 , V_53 -> V_244 ) ;
if ( V_19 < 0 )
return V_19 ;
for ( V_27 = 0 ; V_27 < V_313 ; V_27 ++ ) {
for ( V_251 = 0 ; V_251 < V_259 ; V_251 ++ )
* V_311 ++ = * V_310 ++ ;
V_310 += sizeof( * ( V_53 -> V_244 ) ) - V_259 ;
}
V_6 -> V_292 += V_313 ;
if ( V_6 -> V_292 == F_131 ( V_6 ) )
V_6 -> V_292 = 0 ;
V_19 = F_121 ( V_6 , F_130 ( V_301 ) ,
V_6 -> V_292 ) ;
if ( V_19 < 0 )
return V_19 ;
V_6 -> V_114 -= V_313 ;
return V_313 ;
}
static int F_139 ( struct V_239 * V_53 ,
char T_3 * V_6 , T_1 V_16 )
{
struct V_8 * V_9 = V_53 -> V_9 ;
int V_315 = 0 ;
int V_313 , V_316 ;
F_40 ( V_9 , L_120 , V_16 ) ;
if ( ! V_53 -> V_6 )
return - V_240 ;
if ( V_53 -> V_6 -> error )
return - V_230 ;
V_16 /= V_259 ;
do {
V_313 = F_138 ( V_53 , V_16 ) ;
if ( V_313 < 0 ) {
F_21 ( V_9 , L_121 , V_313 ) ;
return V_313 ;
}
V_316 = V_313 * V_259 ;
F_40 ( V_9 , L_122 , V_316 ) ;
if ( F_140 ( V_6 + V_315 , V_53 -> V_244 , V_316 ) ) {
F_21 ( V_9 , L_123 ,
V_315 , V_316 ) ;
return - V_317 ;
}
V_16 -= V_313 ;
V_315 += V_316 ;
} while ( V_313 > 0 && V_16 > 0 );
V_53 -> V_308 += V_315 ;
return V_315 ;
}
int F_141 ( struct V_237 * V_238 , char T_3 * V_6 ,
T_1 V_16 )
{
struct V_239 * V_53 = V_238 -> V_243 -> V_18 ;
struct V_8 * V_9 = V_53 -> V_9 ;
int V_19 ;
F_16 ( & V_9 -> V_20 ) ;
if ( V_238 -> V_242 == V_318 )
V_19 = F_139 ( V_53 , V_6 , V_16 ) ;
else
V_19 = - V_319 ;
F_18 ( & V_9 -> V_20 ) ;
return V_19 ;
}
