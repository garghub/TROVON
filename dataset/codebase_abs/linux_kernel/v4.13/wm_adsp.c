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
static void F_43 ( struct V_13 * V_14 )
{
T_6 V_66 [ 2 ] ;
int V_24 ;
V_24 = F_40 ( V_14 -> V_67 , V_14 -> V_65 + V_69 ,
V_66 , sizeof( V_66 ) ) ;
if ( V_24 ) {
F_22 ( V_14 , L_15 , V_24 ) ;
return;
}
V_66 [ 0 ] = F_44 ( V_66 [ 0 ] ) ;
V_66 [ 1 ] = F_44 ( V_66 [ 1 ] ) ;
F_41 ( V_14 , L_16 ,
V_66 [ 0 ] & 0xFFFF ,
V_66 [ 0 ] >> 16 ,
V_66 [ 1 ] & 0xFFFF ,
V_66 [ 1 ] >> 16 ) ;
}
static inline struct V_70 * F_45 ( struct V_71 * V_72 )
{
return F_46 ( V_72 , struct V_70 , V_73 ) ;
}
static int F_47 ( struct V_70 * V_74 , unsigned int * V_75 )
{
const struct V_76 * V_77 = & V_74 -> V_77 ;
struct V_13 * V_14 = V_74 -> V_14 ;
const struct V_61 * V_63 ;
V_63 = F_35 ( V_14 , V_77 -> type ) ;
if ( ! V_63 ) {
F_22 ( V_14 , L_17 ,
V_77 -> type ) ;
return - V_58 ;
}
* V_75 = F_36 ( V_63 , V_74 -> V_77 . V_65 + V_74 -> V_64 ) ;
return 0 ;
}
static int F_48 ( struct V_45 * V_78 ,
struct V_79 * V_80 )
{
struct V_71 * V_73 =
(struct V_71 * ) V_78 -> V_51 ;
struct V_70 * V_74 = F_45 ( V_73 ) ;
switch ( V_74 -> type ) {
case V_81 :
V_80 -> type = V_82 ;
V_80 -> V_52 . integer . V_83 = V_84 ;
V_80 -> V_52 . integer . V_85 = V_86 ;
V_80 -> V_52 . integer . V_87 = 1 ;
V_80 -> V_21 = 1 ;
break;
default:
V_80 -> type = V_88 ;
V_80 -> V_21 = V_74 -> V_3 ;
break;
}
return 0 ;
}
static int F_49 ( struct V_70 * V_74 ,
unsigned int V_89 )
{
struct V_13 * V_14 = V_74 -> V_14 ;
T_6 V_90 = F_50 ( V_89 ) ;
unsigned int V_75 ;
int V_32 , V_24 ;
V_24 = F_47 ( V_74 , & V_75 ) ;
if ( V_24 )
return V_24 ;
F_41 ( V_14 , L_18 ,
V_89 , V_74 -> V_77 . V_91 ,
F_11 ( V_74 -> V_77 . type ) , V_74 -> V_64 ) ;
V_24 = F_51 ( V_14 -> V_67 , V_75 , & V_90 , sizeof( V_90 ) ) ;
if ( V_24 ) {
F_22 ( V_14 , L_19 , V_75 , V_24 ) ;
return V_24 ;
}
for ( V_32 = 0 ; V_32 < V_92 ; ) {
switch ( V_32 ) {
case 0 ... V_93 - 1 :
F_52 ( 1000 , 2000 ) ;
V_32 ++ ;
break;
default:
F_52 ( 10000 , 20000 ) ;
V_32 += 10 ;
break;
}
V_24 = F_40 ( V_14 -> V_67 , V_75 , & V_90 , sizeof( V_90 ) ) ;
if ( V_24 ) {
F_22 ( V_14 , L_20 , V_75 , V_24 ) ;
return V_24 ;
}
if ( V_90 == 0 ) {
F_41 ( V_14 , L_21 , V_32 ) ;
return 0 ;
}
}
F_53 ( V_14 , L_22 ,
V_75 , V_74 -> V_77 . V_91 ,
F_11 ( V_74 -> V_77 . type ) ,
V_74 -> V_64 ) ;
return - V_94 ;
}
static int F_54 ( struct V_70 * V_74 ,
const void * V_6 , T_1 V_3 )
{
struct V_13 * V_14 = V_74 -> V_14 ;
void * V_66 ;
int V_24 ;
unsigned int V_75 ;
V_24 = F_47 ( V_74 , & V_75 ) ;
if ( V_24 )
return V_24 ;
V_66 = F_55 ( V_6 , V_3 , V_7 | V_95 ) ;
if ( ! V_66 )
return - V_96 ;
V_24 = F_51 ( V_14 -> V_67 , V_75 , V_66 ,
V_3 ) ;
if ( V_24 ) {
F_22 ( V_14 , L_23 ,
V_3 , V_75 , V_24 ) ;
F_4 ( V_66 ) ;
return V_24 ;
}
F_41 ( V_14 , L_24 , V_3 , V_75 ) ;
F_4 ( V_66 ) ;
return 0 ;
}
static int F_56 ( struct V_45 * V_78 ,
struct V_47 * V_48 )
{
struct V_71 * V_73 =
(struct V_71 * ) V_78 -> V_51 ;
struct V_70 * V_74 = F_45 ( V_73 ) ;
char * V_97 = V_48 -> V_52 . V_98 . V_99 ;
int V_24 = 0 ;
F_17 ( & V_74 -> V_14 -> V_25 ) ;
if ( V_74 -> V_100 & V_101 )
V_24 = - V_102 ;
else
memcpy ( V_74 -> V_103 , V_97 , V_74 -> V_3 ) ;
V_74 -> V_104 = 1 ;
if ( V_74 -> V_105 && V_74 -> V_14 -> V_39 )
V_24 = F_54 ( V_74 , V_97 , V_74 -> V_3 ) ;
F_19 ( & V_74 -> V_14 -> V_25 ) ;
return V_24 ;
}
static int F_57 ( struct V_45 * V_78 ,
const unsigned int T_3 * V_98 , unsigned int V_106 )
{
struct V_71 * V_73 =
(struct V_71 * ) V_78 -> V_51 ;
struct V_70 * V_74 = F_45 ( V_73 ) ;
int V_24 = 0 ;
F_17 ( & V_74 -> V_14 -> V_25 ) ;
if ( F_58 ( V_74 -> V_103 , V_98 , V_106 ) ) {
V_24 = - V_107 ;
} else {
V_74 -> V_104 = 1 ;
if ( V_74 -> V_105 && V_74 -> V_14 -> V_39 )
V_24 = F_54 ( V_74 , V_74 -> V_103 , V_106 ) ;
else if ( V_74 -> V_100 & V_101 )
V_24 = - V_102 ;
}
F_19 ( & V_74 -> V_14 -> V_25 ) ;
return V_24 ;
}
static int F_59 ( struct V_45 * V_78 ,
struct V_47 * V_48 )
{
struct V_71 * V_73 =
(struct V_71 * ) V_78 -> V_51 ;
struct V_70 * V_74 = F_45 ( V_73 ) ;
unsigned int V_90 = V_48 -> V_52 . integer . V_52 [ 0 ] ;
int V_24 ;
if ( V_90 == 0 )
return 0 ;
F_17 ( & V_74 -> V_14 -> V_25 ) ;
if ( V_74 -> V_105 && V_74 -> V_14 -> V_39 )
V_24 = F_49 ( V_74 , V_90 ) ;
else
V_24 = - V_102 ;
F_19 ( & V_74 -> V_14 -> V_25 ) ;
return V_24 ;
}
static int F_60 ( struct V_70 * V_74 ,
void * V_6 , T_1 V_3 )
{
struct V_13 * V_14 = V_74 -> V_14 ;
void * V_66 ;
int V_24 ;
unsigned int V_75 ;
V_24 = F_47 ( V_74 , & V_75 ) ;
if ( V_24 )
return V_24 ;
V_66 = F_23 ( V_3 , V_7 | V_95 ) ;
if ( ! V_66 )
return - V_96 ;
V_24 = F_40 ( V_14 -> V_67 , V_75 , V_66 , V_3 ) ;
if ( V_24 ) {
F_22 ( V_14 , L_25 ,
V_3 , V_75 , V_24 ) ;
F_4 ( V_66 ) ;
return V_24 ;
}
F_41 ( V_14 , L_26 , V_3 , V_75 ) ;
memcpy ( V_6 , V_66 , V_3 ) ;
F_4 ( V_66 ) ;
return 0 ;
}
static int F_61 ( struct V_45 * V_78 ,
struct V_47 * V_48 )
{
struct V_71 * V_73 =
(struct V_71 * ) V_78 -> V_51 ;
struct V_70 * V_74 = F_45 ( V_73 ) ;
char * V_97 = V_48 -> V_52 . V_98 . V_99 ;
int V_24 = 0 ;
F_17 ( & V_74 -> V_14 -> V_25 ) ;
if ( V_74 -> V_100 & V_101 ) {
if ( V_74 -> V_105 && V_74 -> V_14 -> V_39 )
V_24 = F_60 ( V_74 , V_97 , V_74 -> V_3 ) ;
else
V_24 = - V_102 ;
} else {
if ( ! V_74 -> V_100 && V_74 -> V_105 && V_74 -> V_14 -> V_39 )
V_24 = F_60 ( V_74 , V_74 -> V_103 , V_74 -> V_3 ) ;
memcpy ( V_97 , V_74 -> V_103 , V_74 -> V_3 ) ;
}
F_19 ( & V_74 -> V_14 -> V_25 ) ;
return V_24 ;
}
static int F_62 ( struct V_45 * V_78 ,
unsigned int T_3 * V_98 , unsigned int V_106 )
{
struct V_71 * V_73 =
(struct V_71 * ) V_78 -> V_51 ;
struct V_70 * V_74 = F_45 ( V_73 ) ;
int V_24 = 0 ;
F_17 ( & V_74 -> V_14 -> V_25 ) ;
if ( V_74 -> V_100 & V_101 ) {
if ( V_74 -> V_105 && V_74 -> V_14 -> V_39 )
V_24 = F_60 ( V_74 , V_74 -> V_103 , V_106 ) ;
else
V_24 = - V_102 ;
} else {
if ( ! V_74 -> V_100 && V_74 -> V_105 && V_74 -> V_14 -> V_39 )
V_24 = F_60 ( V_74 , V_74 -> V_103 , V_106 ) ;
}
if ( ! V_24 && F_63 ( V_98 , V_74 -> V_103 , V_106 ) )
V_24 = - V_107 ;
F_19 ( & V_74 -> V_14 -> V_25 ) ;
return V_24 ;
}
static int F_64 ( struct V_45 * V_46 ,
struct V_47 * V_48 )
{
V_48 -> V_52 . integer . V_52 [ 0 ] = 0 ;
return 0 ;
}
static unsigned int F_65 ( unsigned int V_108 , unsigned int V_3 )
{
unsigned int V_109 , V_110 , V_111 , V_112 ;
if ( V_3 > V_113 ) {
V_110 = V_114 ;
V_111 = V_115 ;
V_112 = V_116 ;
V_109 = V_117 ;
} else {
V_110 = V_118 ;
V_111 = V_119 ;
V_112 = V_116 ;
V_109 = 0 ;
}
if ( V_108 ) {
if ( V_108 & V_120 )
V_109 |= V_110 ;
if ( V_108 & V_121 )
V_109 |= V_111 ;
if ( V_108 & V_101 )
V_109 |= V_112 ;
} else {
V_109 |= V_110 | V_111 | V_112 ;
}
return V_109 ;
}
static int F_66 ( struct V_13 * V_14 , struct V_70 * V_74 )
{
struct V_122 * V_46 ;
int V_24 ;
if ( ! V_74 || ! V_74 -> V_43 )
return - V_58 ;
V_46 = F_2 ( sizeof( * V_46 ) , V_7 ) ;
if ( ! V_46 )
return - V_96 ;
V_46 -> V_43 = V_74 -> V_43 ;
V_46 -> V_123 = F_48 ;
V_46 -> V_124 = V_125 ;
V_46 -> V_126 . V_127 = V_128 ;
V_46 -> V_51 = ( unsigned long ) & V_74 -> V_73 ;
V_46 -> V_129 = F_65 ( V_74 -> V_100 , V_74 -> V_3 ) ;
switch ( V_74 -> type ) {
case V_81 :
V_46 -> V_130 = F_64 ;
V_46 -> V_131 = F_59 ;
break;
default:
V_46 -> V_130 = F_61 ;
V_46 -> V_131 = F_56 ;
V_74 -> V_73 . V_85 = V_74 -> V_3 ;
V_74 -> V_73 . V_130 = F_62 ;
V_74 -> V_73 . V_131 = F_57 ;
break;
}
V_24 = F_67 ( V_14 -> V_28 , V_46 , 1 ) ;
if ( V_24 < 0 )
goto V_132;
F_4 ( V_46 ) ;
return 0 ;
V_132:
F_4 ( V_46 ) ;
return V_24 ;
}
static int F_68 ( struct V_13 * V_14 )
{
struct V_70 * V_74 ;
int V_24 ;
F_69 (ctl, &dsp->ctl_list, list) {
if ( ! V_74 -> V_105 || V_74 -> V_104 )
continue;
if ( V_74 -> V_100 & V_101 )
continue;
V_24 = F_60 ( V_74 , V_74 -> V_103 , V_74 -> V_3 ) ;
if ( V_24 < 0 )
return V_24 ;
}
return 0 ;
}
static int F_70 ( struct V_13 * V_14 )
{
struct V_70 * V_74 ;
int V_24 ;
F_69 (ctl, &dsp->ctl_list, list) {
if ( ! V_74 -> V_105 )
continue;
if ( V_74 -> V_104 && ! ( V_74 -> V_100 & V_101 ) ) {
V_24 = F_54 ( V_74 , V_74 -> V_103 , V_74 -> V_3 ) ;
if ( V_24 < 0 )
return V_24 ;
}
}
return 0 ;
}
static void F_71 ( struct V_13 * V_14 ,
unsigned int V_133 )
{
struct V_70 * V_74 ;
int V_24 ;
F_69 (ctl, &dsp->ctl_list, list) {
if ( V_74 -> type != V_134 )
continue;
if ( ! V_74 -> V_105 )
continue;
V_24 = F_49 ( V_74 , V_133 ) ;
if ( V_24 )
F_53 ( V_14 ,
L_27 ,
V_133 , V_74 -> V_77 . V_91 , V_24 ) ;
}
}
static void F_72 ( struct V_135 * V_136 )
{
struct V_137 * V_138 = F_46 ( V_136 ,
struct V_137 ,
V_136 ) ;
F_66 ( V_138 -> V_14 , V_138 -> V_74 ) ;
F_4 ( V_138 ) ;
}
static void F_73 ( struct V_70 * V_74 )
{
F_4 ( V_74 -> V_103 ) ;
F_4 ( V_74 -> V_43 ) ;
F_4 ( V_74 ) ;
}
static int F_74 ( struct V_13 * V_14 ,
const struct V_76 * V_77 ,
unsigned int V_64 , unsigned int V_3 ,
const char * V_139 , unsigned int V_140 ,
unsigned int V_100 , unsigned int type )
{
struct V_70 * V_74 ;
struct V_137 * V_138 ;
char V_43 [ V_141 ] ;
const char * V_142 ;
int V_24 ;
V_142 = F_11 ( V_77 -> type ) ;
if ( ! V_142 ) {
F_22 ( V_14 , L_28 , V_77 -> type ) ;
return - V_58 ;
}
switch ( V_14 -> V_143 ) {
case 0 :
case 1 :
snprintf ( V_43 , V_141 , L_29 ,
V_14 -> V_37 , V_142 , V_77 -> V_91 ) ;
break;
default:
V_24 = snprintf ( V_43 , V_141 ,
L_30 , V_14 -> V_37 , * V_142 ,
V_144 [ V_14 -> V_56 ] , V_77 -> V_91 ) ;
if ( V_139 ) {
int V_145 = V_141 - V_24 - 2 ;
int V_146 = 0 ;
if ( V_140 > V_145 )
V_146 = V_140 - V_145 ;
snprintf ( V_43 + V_24 ,
V_141 - V_24 , L_31 ,
V_140 - V_146 , V_139 + V_146 ) ;
}
break;
}
F_69 (ctl, &dsp->ctl_list, list) {
if ( ! strcmp ( V_74 -> V_43 , V_43 ) ) {
if ( ! V_74 -> V_105 )
V_74 -> V_105 = 1 ;
return 0 ;
}
}
V_74 = F_2 ( sizeof( * V_74 ) , V_7 ) ;
if ( ! V_74 )
return - V_96 ;
V_74 -> V_147 = V_144 [ V_14 -> V_56 ] ;
V_74 -> V_77 = * V_77 ;
V_74 -> V_43 = F_55 ( V_43 , strlen ( V_43 ) + 1 , V_7 ) ;
if ( ! V_74 -> V_43 ) {
V_24 = - V_96 ;
goto V_148;
}
V_74 -> V_105 = 1 ;
V_74 -> V_104 = 0 ;
V_74 -> V_149 . V_150 = F_61 ;
V_74 -> V_149 . V_151 = F_56 ;
V_74 -> V_14 = V_14 ;
V_74 -> V_100 = V_100 ;
V_74 -> type = type ;
V_74 -> V_64 = V_64 ;
V_74 -> V_3 = V_3 ;
V_74 -> V_103 = F_2 ( V_74 -> V_3 , V_7 ) ;
if ( ! V_74 -> V_103 ) {
V_24 = - V_96 ;
goto V_152;
}
F_75 ( & V_74 -> V_5 , & V_14 -> V_153 ) ;
if ( V_100 & V_154 )
return 0 ;
V_138 = F_2 ( sizeof( * V_138 ) , V_7 ) ;
if ( ! V_138 ) {
V_24 = - V_96 ;
goto V_155;
}
V_138 -> V_14 = V_14 ;
V_138 -> V_74 = V_74 ;
F_76 ( & V_138 -> V_136 , F_72 ) ;
F_77 ( & V_138 -> V_136 ) ;
return 0 ;
V_155:
F_4 ( V_74 -> V_103 ) ;
V_152:
F_4 ( V_74 -> V_43 ) ;
V_148:
F_4 ( V_74 ) ;
return V_24 ;
}
static int F_78 ( int V_98 , const T_7 * * V_156 , const T_7 * * V_157 )
{
int V_158 ;
switch ( V_98 ) {
case 1 :
V_158 = * * V_156 ;
break;
case 2 :
V_158 = F_79 ( * ( ( V_159 * ) * V_156 ) ) ;
break;
default:
return 0 ;
}
if ( V_157 )
* V_157 = * V_156 + V_98 ;
* V_156 += ( ( V_158 + V_98 ) + 3 ) & ~ 0x03 ;
return V_158 ;
}
static int F_80 ( int V_98 , const T_7 * * V_156 )
{
int V_90 = 0 ;
switch ( V_98 ) {
case 2 :
V_90 = F_79 ( * ( ( V_159 * ) * V_156 ) ) ;
break;
case 4 :
V_90 = F_81 ( * ( ( V_160 * ) * V_156 ) ) ;
break;
default:
break;
}
* V_156 += V_98 ;
return V_90 ;
}
static inline void F_82 ( struct V_13 * V_14 , const T_7 * * V_99 ,
struct V_161 * V_162 )
{
const struct V_163 * V_164 ;
switch ( V_14 -> V_143 ) {
case 0 :
case 1 :
V_164 = ( const struct V_163 * ) * V_99 ;
* V_99 = V_164 -> V_99 ;
V_162 -> V_165 = F_81 ( V_164 -> V_165 ) ;
V_162 -> V_43 = V_164 -> V_43 ;
V_162 -> V_166 = strlen ( V_164 -> V_43 ) ;
V_162 -> V_167 = F_81 ( V_164 -> V_167 ) ;
break;
default:
V_162 -> V_165 = F_80 ( sizeof( V_164 -> V_165 ) , V_99 ) ;
V_162 -> V_166 = F_78 ( sizeof( T_7 ) , V_99 ,
& V_162 -> V_43 ) ;
F_78 ( sizeof( T_5 ) , V_99 , NULL ) ;
V_162 -> V_167 = F_80 ( sizeof( V_164 -> V_167 ) , V_99 ) ;
break;
}
F_41 ( V_14 , L_32 , V_162 -> V_165 ) ;
F_41 ( V_14 , L_33 , V_162 -> V_166 , V_162 -> V_43 ) ;
F_41 ( V_14 , L_34 , V_162 -> V_167 ) ;
}
static inline void F_83 ( struct V_13 * V_14 , const T_7 * * V_99 ,
struct V_168 * V_162 )
{
const struct V_169 * V_164 ;
const T_7 * V_16 ;
int V_158 ;
switch ( V_14 -> V_143 ) {
case 0 :
case 1 :
V_164 = ( const struct V_169 * ) * V_99 ;
* V_99 = * V_99 + sizeof( V_164 -> V_170 ) + F_81 ( V_164 -> V_170 . V_106 ) ;
V_162 -> V_64 = F_79 ( V_164 -> V_170 . V_64 ) ;
V_162 -> V_171 = F_79 ( V_164 -> V_170 . type ) ;
V_162 -> V_43 = V_164 -> V_43 ;
V_162 -> V_166 = strlen ( V_164 -> V_43 ) ;
V_162 -> V_172 = F_79 ( V_164 -> V_172 ) ;
V_162 -> V_100 = F_79 ( V_164 -> V_100 ) ;
V_162 -> V_3 = F_81 ( V_164 -> V_3 ) ;
break;
default:
V_16 = * V_99 ;
V_162 -> V_64 = F_80 ( sizeof( V_164 -> V_170 . V_64 ) , & V_16 ) ;
V_162 -> V_171 = F_80 ( sizeof( V_164 -> V_170 . type ) , & V_16 ) ;
V_158 = F_80 ( sizeof( V_164 -> V_170 . V_106 ) , & V_16 ) ;
V_162 -> V_166 = F_78 ( sizeof( T_7 ) , & V_16 ,
& V_162 -> V_43 ) ;
F_78 ( sizeof( T_7 ) , & V_16 , NULL ) ;
F_78 ( sizeof( T_5 ) , & V_16 , NULL ) ;
V_162 -> V_172 = F_80 ( sizeof( V_164 -> V_172 ) , & V_16 ) ;
V_162 -> V_100 = F_80 ( sizeof( V_164 -> V_100 ) , & V_16 ) ;
V_162 -> V_3 = F_80 ( sizeof( V_164 -> V_3 ) , & V_16 ) ;
* V_99 = * V_99 + sizeof( V_164 -> V_170 ) + V_158 ;
break;
}
F_41 ( V_14 , L_35 , V_162 -> V_171 ) ;
F_41 ( V_14 , L_36 , V_162 -> V_64 ) ;
F_41 ( V_14 , L_37 , V_162 -> V_166 , V_162 -> V_43 ) ;
F_41 ( V_14 , L_38 , V_162 -> V_100 ) ;
F_41 ( V_14 , L_39 , V_162 -> V_172 ) ;
F_41 ( V_14 , L_40 , V_162 -> V_3 ) ;
}
static int F_84 ( struct V_13 * V_14 ,
const struct V_168 * V_173 ,
unsigned int V_174 ,
unsigned int V_175 )
{
if ( ( V_173 -> V_100 & V_175 ) ||
( ( V_173 -> V_100 & V_174 ) != V_174 ) ) {
F_22 ( V_14 , L_41 ,
V_173 -> V_100 , V_173 -> V_172 ) ;
return - V_58 ;
}
return 0 ;
}
static int F_85 ( struct V_13 * V_14 ,
const struct V_176 * V_177 )
{
struct V_76 V_77 = {} ;
struct V_161 V_178 ;
struct V_168 V_173 ;
const T_7 * V_99 = V_177 -> V_99 ;
int V_32 , V_24 ;
F_82 ( V_14 , & V_99 , & V_178 ) ;
for ( V_32 = 0 ; V_32 < V_178 . V_167 ; V_32 ++ ) {
F_83 ( V_14 , & V_99 , & V_173 ) ;
switch ( V_173 . V_172 ) {
case V_88 :
break;
case V_81 :
if ( V_173 . V_100 & V_154 )
continue;
V_24 = F_84 ( V_14 , & V_173 ,
V_101 |
V_121 |
V_120 ,
0 ) ;
if ( V_24 )
return - V_58 ;
break;
case V_134 :
V_24 = F_84 ( V_14 , & V_173 ,
V_154 |
V_101 |
V_121 |
V_120 ,
0 ) ;
if ( V_24 )
return - V_58 ;
break;
default:
F_22 ( V_14 , L_42 ,
V_173 . V_172 ) ;
return - V_58 ;
}
V_77 . type = V_173 . V_171 ;
V_77 . V_91 = V_178 . V_165 ;
V_24 = F_74 ( V_14 , & V_77 ,
V_173 . V_64 ,
V_173 . V_3 ,
V_173 . V_43 ,
V_173 . V_166 ,
V_173 . V_100 ,
V_173 . V_172 ) ;
if ( V_24 < 0 )
F_22 ( V_14 , L_43 ,
V_173 . V_166 , V_173 . V_43 , V_24 ) ;
}
return 0 ;
}
static int F_86 ( struct V_13 * V_14 )
{
F_87 ( V_179 ) ;
const struct V_180 * V_180 ;
struct V_67 * V_67 = V_14 -> V_67 ;
unsigned int V_156 = 0 ;
const struct V_181 * V_182 ;
const struct V_183 * V_184 ;
const struct V_185 * V_186 ;
const struct V_187 * V_188 ;
const struct V_176 * V_177 ;
const struct V_61 * V_63 ;
const char * V_142 ;
char * V_19 , * V_189 = NULL ;
struct V_1 * V_6 ;
unsigned int V_75 ;
int V_190 = 0 ;
int V_24 , V_64 , type , V_191 ;
V_19 = F_2 ( V_36 , V_7 ) ;
if ( V_19 == NULL )
return - V_96 ;
snprintf ( V_19 , V_36 , L_44 , V_14 -> V_192 , V_14 -> V_37 ,
V_193 [ V_14 -> V_56 ] . V_19 ) ;
V_19 [ V_36 - 1 ] = '\0' ;
V_24 = F_88 ( & V_180 , V_19 , V_14 -> V_194 ) ;
if ( V_24 != 0 ) {
F_22 ( V_14 , L_45 , V_19 ) ;
goto V_109;
}
V_24 = - V_58 ;
V_156 = sizeof( * V_182 ) + sizeof( * V_184 ) + sizeof( * V_188 ) ;
if ( V_156 >= V_180 -> V_106 ) {
F_22 ( V_14 , L_46 ,
V_19 , V_180 -> V_106 ) ;
goto V_195;
}
V_182 = ( void * ) & V_180 -> V_99 [ 0 ] ;
if ( memcmp ( & V_182 -> V_196 [ 0 ] , L_47 , 4 ) != 0 ) {
F_22 ( V_14 , L_48 , V_19 ) ;
goto V_195;
}
switch ( V_182 -> V_197 ) {
case 0 :
F_53 ( V_14 , L_49 ,
V_19 , V_182 -> V_197 ) ;
break;
case 1 :
case 2 :
break;
default:
F_22 ( V_14 , L_50 ,
V_19 , V_182 -> V_197 ) ;
goto V_195;
}
F_89 ( V_14 , L_51 , V_182 -> V_197 ) ;
V_14 -> V_143 = V_182 -> V_197 ;
if ( V_182 -> V_198 != V_14 -> type ) {
F_22 ( V_14 , L_52 ,
V_19 , V_182 -> V_198 , V_14 -> type ) ;
goto V_195;
}
switch ( V_14 -> type ) {
case V_199 :
V_156 = sizeof( * V_182 ) + sizeof( * V_184 ) + sizeof( * V_188 ) ;
V_184 = ( void * ) & ( V_182 [ 1 ] ) ;
V_188 = ( void * ) & ( V_184 [ 1 ] ) ;
V_191 = sizeof( * V_184 ) ;
F_41 ( V_14 , L_53 ,
V_19 , F_81 ( V_184 -> V_200 ) ,
F_81 ( V_184 -> V_201 ) ,
F_81 ( V_184 -> V_202 ) ) ;
break;
case V_203 :
V_156 = sizeof( * V_182 ) + sizeof( * V_186 ) + sizeof( * V_188 ) ;
V_186 = ( void * ) & ( V_182 [ 1 ] ) ;
V_188 = ( void * ) & ( V_186 [ 1 ] ) ;
V_191 = sizeof( * V_186 ) ;
F_41 ( V_14 , L_54 ,
V_19 , F_81 ( V_186 -> V_204 ) ,
F_81 ( V_186 -> V_205 ) ,
F_81 ( V_186 -> V_201 ) ,
F_81 ( V_186 -> V_202 ) ) ;
break;
default:
F_38 ( 1 , L_55 ) ;
goto V_195;
}
if ( F_81 ( V_182 -> V_3 ) != sizeof( * V_182 ) +
V_191 + sizeof( * V_188 ) ) {
F_22 ( V_14 , L_56 ,
V_19 , F_81 ( V_182 -> V_3 ) ) ;
goto V_195;
}
F_41 ( V_14 , L_57 , V_19 ,
F_90 ( V_188 -> V_206 ) ) ;
while ( V_156 < V_180 -> V_106 &&
V_156 - V_180 -> V_106 > sizeof( * V_177 ) ) {
V_177 = ( void * ) & ( V_180 -> V_99 [ V_156 ] ) ;
V_142 = L_58 ;
V_75 = 0 ;
V_189 = NULL ;
V_64 = F_81 ( V_177 -> V_64 ) & 0xffffff ;
type = F_44 ( V_177 -> type ) & 0xff ;
V_63 = F_35 ( V_14 , type ) ;
switch ( type ) {
case V_207 :
V_142 = L_59 ;
V_189 = F_2 ( F_81 ( V_177 -> V_3 ) + 1 ,
V_7 ) ;
break;
case V_208 :
V_142 = L_60 ;
V_24 = F_85 ( V_14 , V_177 ) ;
if ( V_24 != 0 )
goto V_195;
break;
case V_209 :
V_142 = L_61 ;
V_189 = F_2 ( F_81 ( V_177 -> V_3 ) + 1 ,
V_7 ) ;
break;
case V_210 :
V_142 = L_62 ;
V_75 = V_64 ;
break;
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
V_142 = F_11 ( type ) ;
V_75 = F_36 ( V_63 , V_64 ) ;
break;
default:
F_53 ( V_14 ,
L_63 ,
V_19 , V_190 , type , V_156 , V_156 ) ;
break;
}
F_41 ( V_14 , L_64 , V_19 ,
V_190 , F_81 ( V_177 -> V_3 ) , V_64 ,
V_142 ) ;
if ( ( V_156 + F_81 ( V_177 -> V_3 ) + sizeof( * V_177 ) ) >
V_180 -> V_106 ) {
F_22 ( V_14 ,
L_65 ,
V_19 , V_190 , V_142 ,
F_81 ( V_177 -> V_3 ) , V_180 -> V_106 ) ;
V_24 = - V_58 ;
goto V_195;
}
if ( V_189 ) {
memcpy ( V_189 , V_177 -> V_99 , F_81 ( V_177 -> V_3 ) ) ;
F_89 ( V_14 , L_66 , V_19 , V_189 ) ;
F_4 ( V_189 ) ;
V_189 = NULL ;
}
if ( V_75 ) {
V_6 = F_1 ( V_177 -> V_99 ,
F_81 ( V_177 -> V_3 ) ,
& V_179 ) ;
if ( ! V_6 ) {
F_22 ( V_14 , L_67 ) ;
V_24 = - V_96 ;
goto V_195;
}
V_24 = F_91 ( V_67 , V_75 , V_6 -> V_6 ,
F_81 ( V_177 -> V_3 ) ) ;
if ( V_24 != 0 ) {
F_22 ( V_14 ,
L_68 ,
V_19 , V_190 ,
F_81 ( V_177 -> V_3 ) , V_64 ,
V_142 , V_24 ) ;
goto V_195;
}
}
V_156 += F_81 ( V_177 -> V_3 ) + sizeof( * V_177 ) ;
V_190 ++ ;
}
V_24 = F_92 ( V_67 ) ;
if ( V_24 != 0 ) {
F_22 ( V_14 , L_69 , V_24 ) ;
goto V_195;
}
if ( V_156 > V_180 -> V_106 )
F_53 ( V_14 , L_70 ,
V_19 , V_190 , V_156 - V_180 -> V_106 ) ;
F_12 ( V_14 , V_19 ) ;
V_195:
F_92 ( V_67 ) ;
F_6 ( & V_179 ) ;
F_93 ( V_180 ) ;
F_4 ( V_189 ) ;
V_109:
F_4 ( V_19 ) ;
return V_24 ;
}
static void F_94 ( struct V_13 * V_14 ,
const struct V_76 * V_77 )
{
struct V_70 * V_74 ;
F_69 (ctl, &dsp->ctl_list, list) {
if ( V_74 -> V_147 == V_144 [ V_14 -> V_56 ] &&
V_77 -> V_91 == V_74 -> V_77 . V_91 &&
V_77 -> type == V_74 -> V_77 . type ) {
V_74 -> V_77 . V_65 = V_77 -> V_65 ;
}
}
}
static void * F_95 ( struct V_13 * V_14 , T_1 V_211 ,
unsigned int V_156 , unsigned int V_3 )
{
void * V_91 ;
int V_24 ;
T_8 V_90 ;
if ( V_211 == 0 ) {
F_22 ( V_14 , L_71 ) ;
return F_96 ( - V_58 ) ;
}
if ( V_211 > 1024 ) {
F_22 ( V_14 , L_72 , V_211 ) ;
return F_96 ( - V_58 ) ;
}
V_24 = F_40 ( V_14 -> V_67 , V_156 + V_3 , & V_90 , sizeof( V_90 ) ) ;
if ( V_24 != 0 ) {
F_22 ( V_14 , L_73 ,
V_24 ) ;
return F_96 ( V_24 ) ;
}
if ( F_44 ( V_90 ) != 0xbedead )
F_53 ( V_14 , L_74 ,
V_156 + V_3 , F_44 ( V_90 ) ) ;
V_91 = F_2 ( V_3 * 2 , V_7 | V_95 ) ;
if ( ! V_91 )
return F_96 ( - V_96 ) ;
V_24 = F_40 ( V_14 -> V_67 , V_156 , V_91 , V_3 * 2 ) ;
if ( V_24 != 0 ) {
F_22 ( V_14 , L_75 , V_24 ) ;
F_4 ( V_91 ) ;
return F_96 ( V_24 ) ;
}
return V_91 ;
}
static struct V_76 *
F_97 ( struct V_13 * V_14 , int type , unsigned int V_165 )
{
struct V_76 * V_77 ;
F_69 (alg_region, &dsp->alg_regions, list) {
if ( V_165 == V_77 -> V_91 && type == V_77 -> type )
return V_77 ;
}
return NULL ;
}
static struct V_76 * F_98 ( struct V_13 * V_14 ,
int type , T_8 V_165 ,
T_8 V_65 )
{
struct V_76 * V_77 ;
V_77 = F_2 ( sizeof( * V_77 ) , V_7 ) ;
if ( ! V_77 )
return F_96 ( - V_96 ) ;
V_77 -> type = type ;
V_77 -> V_91 = F_44 ( V_165 ) ;
V_77 -> V_65 = F_44 ( V_65 ) ;
F_5 ( & V_77 -> V_5 , & V_14 -> V_212 ) ;
if ( V_14 -> V_143 > 0 )
F_94 ( V_14 , V_77 ) ;
return V_77 ;
}
static void F_99 ( struct V_13 * V_14 )
{
struct V_76 * V_77 ;
while ( ! F_7 ( & V_14 -> V_212 ) ) {
V_77 = F_8 ( & V_14 -> V_212 ,
struct V_76 ,
V_5 ) ;
F_9 ( & V_77 -> V_5 ) ;
F_4 ( V_77 ) ;
}
}
static int F_100 ( struct V_13 * V_14 )
{
struct V_213 V_214 ;
struct V_215 * V_216 ;
struct V_76 * V_77 ;
const struct V_61 * V_63 ;
unsigned int V_156 , V_3 ;
T_1 V_211 ;
int V_32 , V_24 ;
V_63 = F_35 ( V_14 , V_9 ) ;
if ( F_37 ( ! V_63 ) )
return - V_58 ;
V_24 = F_40 ( V_14 -> V_67 , V_63 -> V_65 , & V_214 ,
sizeof( V_214 ) ) ;
if ( V_24 != 0 ) {
F_22 ( V_14 , L_76 ,
V_24 ) ;
return V_24 ;
}
V_211 = F_44 ( V_214 . V_211 ) ;
V_14 -> V_40 = F_44 ( V_214 . V_56 . V_165 ) ;
F_89 ( V_14 , L_77 ,
V_14 -> V_40 ,
( F_44 ( V_214 . V_56 . V_197 ) & 0xff0000 ) >> 16 ,
( F_44 ( V_214 . V_56 . V_197 ) & 0xff00 ) >> 8 ,
F_44 ( V_214 . V_56 . V_197 ) & 0xff ,
V_211 ) ;
V_77 = F_98 ( V_14 , V_12 ,
V_214 . V_56 . V_165 , V_214 . V_202 ) ;
if ( F_101 ( V_77 ) )
return F_102 ( V_77 ) ;
V_77 = F_98 ( V_14 , V_9 ,
V_214 . V_56 . V_165 , V_214 . V_200 ) ;
if ( F_101 ( V_77 ) )
return F_102 ( V_77 ) ;
V_156 = sizeof( V_214 ) / 2 ;
V_3 = ( sizeof( * V_216 ) * V_211 ) / 2 ;
V_216 = F_95 ( V_14 , V_211 , V_63 -> V_65 + V_156 , V_3 ) ;
if ( F_101 ( V_216 ) )
return F_102 ( V_216 ) ;
for ( V_32 = 0 ; V_32 < V_211 ; V_32 ++ ) {
F_89 ( V_14 , L_78 ,
V_32 , F_44 ( V_216 [ V_32 ] . V_91 . V_165 ) ,
( F_44 ( V_216 [ V_32 ] . V_91 . V_197 ) & 0xff0000 ) >> 16 ,
( F_44 ( V_216 [ V_32 ] . V_91 . V_197 ) & 0xff00 ) >> 8 ,
F_44 ( V_216 [ V_32 ] . V_91 . V_197 ) & 0xff ,
F_44 ( V_216 [ V_32 ] . V_200 ) ,
F_44 ( V_216 [ V_32 ] . V_202 ) ) ;
V_77 = F_98 ( V_14 , V_9 ,
V_216 [ V_32 ] . V_91 . V_165 ,
V_216 [ V_32 ] . V_200 ) ;
if ( F_101 ( V_77 ) ) {
V_24 = F_102 ( V_77 ) ;
goto V_109;
}
if ( V_14 -> V_143 == 0 ) {
if ( V_32 + 1 < V_211 ) {
V_3 = F_44 ( V_216 [ V_32 + 1 ] . V_200 ) ;
V_3 -= F_44 ( V_216 [ V_32 ] . V_200 ) ;
V_3 *= 4 ;
F_74 ( V_14 , V_77 , 0 ,
V_3 , NULL , 0 , 0 ,
V_88 ) ;
} else {
F_53 ( V_14 , L_79 ,
F_44 ( V_216 [ V_32 ] . V_91 . V_165 ) ) ;
}
}
V_77 = F_98 ( V_14 , V_12 ,
V_216 [ V_32 ] . V_91 . V_165 ,
V_216 [ V_32 ] . V_202 ) ;
if ( F_101 ( V_77 ) ) {
V_24 = F_102 ( V_77 ) ;
goto V_109;
}
if ( V_14 -> V_143 == 0 ) {
if ( V_32 + 1 < V_211 ) {
V_3 = F_44 ( V_216 [ V_32 + 1 ] . V_202 ) ;
V_3 -= F_44 ( V_216 [ V_32 ] . V_202 ) ;
V_3 *= 4 ;
F_74 ( V_14 , V_77 , 0 ,
V_3 , NULL , 0 , 0 ,
V_88 ) ;
} else {
F_53 ( V_14 , L_80 ,
F_44 ( V_216 [ V_32 ] . V_91 . V_165 ) ) ;
}
}
}
V_109:
F_4 ( V_216 ) ;
return V_24 ;
}
static int F_103 ( struct V_13 * V_14 )
{
struct V_217 V_218 ;
struct V_219 * V_220 ;
struct V_76 * V_77 ;
const struct V_61 * V_63 ;
unsigned int V_156 , V_3 ;
T_1 V_211 ;
int V_32 , V_24 ;
V_63 = F_35 ( V_14 , V_10 ) ;
if ( F_37 ( ! V_63 ) )
return - V_58 ;
V_24 = F_40 ( V_14 -> V_67 , V_63 -> V_65 , & V_218 ,
sizeof( V_218 ) ) ;
if ( V_24 != 0 ) {
F_22 ( V_14 , L_76 ,
V_24 ) ;
return V_24 ;
}
V_211 = F_44 ( V_218 . V_211 ) ;
V_14 -> V_40 = F_44 ( V_218 . V_56 . V_165 ) ;
V_14 -> V_41 = F_44 ( V_218 . V_56 . V_197 ) ;
F_89 ( V_14 , L_77 ,
V_14 -> V_40 ,
( V_14 -> V_41 & 0xff0000 ) >> 16 ,
( V_14 -> V_41 & 0xff00 ) >> 8 ,
V_14 -> V_41 & 0xff ,
V_211 ) ;
V_77 = F_98 ( V_14 , V_10 ,
V_218 . V_56 . V_165 , V_218 . V_204 ) ;
if ( F_101 ( V_77 ) )
return F_102 ( V_77 ) ;
V_77 = F_98 ( V_14 , V_11 ,
V_218 . V_56 . V_165 , V_218 . V_205 ) ;
if ( F_101 ( V_77 ) )
return F_102 ( V_77 ) ;
V_77 = F_98 ( V_14 , V_221 ,
V_218 . V_56 . V_165 , V_218 . V_202 ) ;
if ( F_101 ( V_77 ) )
return F_102 ( V_77 ) ;
V_156 = sizeof( V_218 ) / 2 ;
V_3 = ( sizeof( * V_220 ) * V_211 ) / 2 ;
V_220 = F_95 ( V_14 , V_211 , V_63 -> V_65 + V_156 , V_3 ) ;
if ( F_101 ( V_220 ) )
return F_102 ( V_220 ) ;
for ( V_32 = 0 ; V_32 < V_211 ; V_32 ++ ) {
F_89 ( V_14 ,
L_81 ,
V_32 , F_44 ( V_220 [ V_32 ] . V_91 . V_165 ) ,
( F_44 ( V_220 [ V_32 ] . V_91 . V_197 ) & 0xff0000 ) >> 16 ,
( F_44 ( V_220 [ V_32 ] . V_91 . V_197 ) & 0xff00 ) >> 8 ,
F_44 ( V_220 [ V_32 ] . V_91 . V_197 ) & 0xff ,
F_44 ( V_220 [ V_32 ] . V_204 ) ,
F_44 ( V_220 [ V_32 ] . V_205 ) ,
F_44 ( V_220 [ V_32 ] . V_202 ) ) ;
V_77 = F_98 ( V_14 , V_10 ,
V_220 [ V_32 ] . V_91 . V_165 ,
V_220 [ V_32 ] . V_204 ) ;
if ( F_101 ( V_77 ) ) {
V_24 = F_102 ( V_77 ) ;
goto V_109;
}
if ( V_14 -> V_143 == 0 ) {
if ( V_32 + 1 < V_211 ) {
V_3 = F_44 ( V_220 [ V_32 + 1 ] . V_204 ) ;
V_3 -= F_44 ( V_220 [ V_32 ] . V_204 ) ;
V_3 *= 4 ;
F_74 ( V_14 , V_77 , 0 ,
V_3 , NULL , 0 , 0 ,
V_88 ) ;
} else {
F_53 ( V_14 , L_82 ,
F_44 ( V_220 [ V_32 ] . V_91 . V_165 ) ) ;
}
}
V_77 = F_98 ( V_14 , V_11 ,
V_220 [ V_32 ] . V_91 . V_165 ,
V_220 [ V_32 ] . V_205 ) ;
if ( F_101 ( V_77 ) ) {
V_24 = F_102 ( V_77 ) ;
goto V_109;
}
if ( V_14 -> V_143 == 0 ) {
if ( V_32 + 1 < V_211 ) {
V_3 = F_44 ( V_220 [ V_32 + 1 ] . V_205 ) ;
V_3 -= F_44 ( V_220 [ V_32 ] . V_205 ) ;
V_3 *= 4 ;
F_74 ( V_14 , V_77 , 0 ,
V_3 , NULL , 0 , 0 ,
V_88 ) ;
} else {
F_53 ( V_14 , L_83 ,
F_44 ( V_220 [ V_32 ] . V_91 . V_165 ) ) ;
}
}
V_77 = F_98 ( V_14 , V_221 ,
V_220 [ V_32 ] . V_91 . V_165 ,
V_220 [ V_32 ] . V_202 ) ;
if ( F_101 ( V_77 ) ) {
V_24 = F_102 ( V_77 ) ;
goto V_109;
}
if ( V_14 -> V_143 == 0 ) {
if ( V_32 + 1 < V_211 ) {
V_3 = F_44 ( V_220 [ V_32 + 1 ] . V_202 ) ;
V_3 -= F_44 ( V_220 [ V_32 ] . V_202 ) ;
V_3 *= 4 ;
F_74 ( V_14 , V_77 , 0 ,
V_3 , NULL , 0 , 0 ,
V_88 ) ;
} else {
F_53 ( V_14 , L_80 ,
F_44 ( V_220 [ V_32 ] . V_91 . V_165 ) ) ;
}
}
}
V_109:
F_4 ( V_220 ) ;
return V_24 ;
}
static int F_104 ( struct V_13 * V_14 )
{
F_87 ( V_179 ) ;
struct V_67 * V_67 = V_14 -> V_67 ;
struct V_222 * V_170 ;
struct V_223 * V_162 ;
const struct V_180 * V_180 ;
const struct V_61 * V_63 ;
struct V_76 * V_77 ;
const char * V_142 ;
int V_24 , V_156 , V_224 , type , V_64 , V_75 ;
char * V_19 ;
struct V_1 * V_6 ;
V_19 = F_2 ( V_36 , V_7 ) ;
if ( V_19 == NULL )
return - V_96 ;
snprintf ( V_19 , V_36 , L_84 , V_14 -> V_192 , V_14 -> V_37 ,
V_193 [ V_14 -> V_56 ] . V_19 ) ;
V_19 [ V_36 - 1 ] = '\0' ;
V_24 = F_88 ( & V_180 , V_19 , V_14 -> V_194 ) ;
if ( V_24 != 0 ) {
F_53 ( V_14 , L_45 , V_19 ) ;
V_24 = 0 ;
goto V_109;
}
V_24 = - V_58 ;
if ( sizeof( * V_170 ) >= V_180 -> V_106 ) {
F_22 ( V_14 , L_46 ,
V_19 , V_180 -> V_106 ) ;
goto V_195;
}
V_170 = ( void * ) & V_180 -> V_99 [ 0 ] ;
if ( memcmp ( V_170 -> V_196 , L_85 , 4 ) != 0 ) {
F_22 ( V_14 , L_48 , V_19 ) ;
goto V_195;
}
switch ( F_44 ( V_170 -> V_225 ) & 0xff ) {
case 1 :
break;
default:
F_22 ( V_14 , L_86 ,
V_19 , F_44 ( V_170 -> V_225 ) & 0xff ) ;
V_24 = - V_58 ;
goto V_195;
}
F_41 ( V_14 , L_87 , V_19 ,
( F_81 ( V_170 -> V_197 ) >> 16 ) & 0xff ,
( F_81 ( V_170 -> V_197 ) >> 8 ) & 0xff ,
F_81 ( V_170 -> V_197 ) & 0xff ) ;
V_156 = F_81 ( V_170 -> V_3 ) ;
V_224 = 0 ;
while ( V_156 < V_180 -> V_106 &&
V_156 - V_180 -> V_106 > sizeof( * V_162 ) ) {
V_162 = ( void * ) ( & V_180 -> V_99 [ V_156 ] ) ;
type = F_79 ( V_162 -> type ) ;
V_64 = F_79 ( V_162 -> V_64 ) ;
F_41 ( V_14 , L_88 ,
V_19 , V_224 , F_81 ( V_162 -> V_165 ) ,
( F_81 ( V_162 -> V_197 ) >> 16 ) & 0xff ,
( F_81 ( V_162 -> V_197 ) >> 8 ) & 0xff ,
F_81 ( V_162 -> V_197 ) & 0xff ) ;
F_41 ( V_14 , L_89 ,
V_19 , V_224 , F_81 ( V_162 -> V_3 ) , V_64 , type ) ;
V_75 = 0 ;
V_142 = L_58 ;
switch ( type ) {
case ( V_207 << 8 ) :
case ( V_209 << 8 ) :
break;
case ( V_210 << 8 ) :
if ( F_81 ( V_162 -> V_165 ) == V_14 -> V_40 &&
V_64 == 0 ) {
V_142 = L_90 ;
V_63 = F_35 ( V_14 , type ) ;
if ( ! V_63 ) {
F_22 ( V_14 , L_91 ) ;
break;
}
V_75 = F_36 ( V_63 , 0 ) ;
} else {
V_142 = L_92 ;
V_75 = V_64 ;
}
break;
case V_9 :
case V_12 :
case V_10 :
case V_11 :
F_41 ( V_14 , L_93 ,
V_19 , V_224 , F_81 ( V_162 -> V_3 ) ,
type , F_81 ( V_162 -> V_165 ) ) ;
V_63 = F_35 ( V_14 , type ) ;
if ( ! V_63 ) {
F_22 ( V_14 , L_17 , type ) ;
break;
}
V_77 = F_97 ( V_14 , type ,
F_81 ( V_162 -> V_165 ) ) ;
if ( V_77 ) {
V_75 = V_77 -> V_65 ;
V_75 = F_36 ( V_63 , V_75 ) ;
V_75 += V_64 ;
} else {
F_22 ( V_14 , L_94 ,
type , F_81 ( V_162 -> V_165 ) ) ;
}
break;
default:
F_22 ( V_14 , L_95 ,
V_19 , V_224 , type , V_156 ) ;
break;
}
if ( V_75 ) {
if ( ( V_156 + F_81 ( V_162 -> V_3 ) + sizeof( * V_162 ) ) >
V_180 -> V_106 ) {
F_22 ( V_14 ,
L_65 ,
V_19 , V_224 , V_142 ,
F_81 ( V_162 -> V_3 ) ,
V_180 -> V_106 ) ;
V_24 = - V_58 ;
goto V_195;
}
V_6 = F_1 ( V_162 -> V_99 ,
F_81 ( V_162 -> V_3 ) ,
& V_179 ) ;
if ( ! V_6 ) {
F_22 ( V_14 , L_67 ) ;
V_24 = - V_96 ;
goto V_195;
}
F_41 ( V_14 , L_96 ,
V_19 , V_224 , F_81 ( V_162 -> V_3 ) ,
V_75 ) ;
V_24 = F_91 ( V_67 , V_75 , V_6 -> V_6 ,
F_81 ( V_162 -> V_3 ) ) ;
if ( V_24 != 0 ) {
F_22 ( V_14 ,
L_97 ,
V_19 , V_224 , V_75 , V_142 , V_24 ) ;
}
}
V_156 += ( F_81 ( V_162 -> V_3 ) + sizeof( * V_162 ) + 3 ) & ~ 0x03 ;
V_224 ++ ;
}
V_24 = F_92 ( V_67 ) ;
if ( V_24 != 0 )
F_22 ( V_14 , L_69 , V_24 ) ;
if ( V_156 > V_180 -> V_106 )
F_53 ( V_14 , L_70 ,
V_19 , V_224 , V_156 - V_180 -> V_106 ) ;
F_14 ( V_14 , V_19 ) ;
V_195:
F_92 ( V_67 ) ;
F_93 ( V_180 ) ;
F_6 ( & V_179 ) ;
V_109:
F_4 ( V_19 ) ;
return V_24 ;
}
int F_105 ( struct V_13 * V_14 )
{
F_106 ( & V_14 -> V_212 ) ;
F_107 ( & V_14 -> V_25 ) ;
return 0 ;
}
int F_108 ( struct V_226 * V_227 ,
struct V_45 * V_46 ,
int V_133 )
{
struct V_27 * V_28 = F_109 ( V_227 -> V_228 ) ;
struct V_13 * V_229 = F_33 ( V_28 ) ;
struct V_13 * V_14 = & V_229 [ V_227 -> V_230 ] ;
struct V_70 * V_74 ;
int V_24 ;
unsigned int V_90 ;
V_14 -> V_28 = V_28 ;
F_17 ( & V_14 -> V_25 ) ;
switch ( V_133 ) {
case V_231 :
F_110 ( V_14 -> V_67 , V_14 -> V_65 + V_232 ,
V_233 , V_233 ) ;
if ( V_14 -> V_234 ) {
V_24 = F_111 ( V_14 -> V_67 , V_14 -> V_234 , & V_90 ) ;
if ( V_24 != 0 ) {
F_22 ( V_14 , L_98 ,
V_24 ) ;
goto V_235;
}
V_90 = ( V_90 & V_14 -> V_236 ) >> V_14 -> V_237 ;
V_24 = F_110 ( V_14 -> V_67 ,
V_14 -> V_65 + V_238 ,
V_239 , V_90 ) ;
if ( V_24 != 0 ) {
F_22 ( V_14 , L_99 ,
V_24 ) ;
goto V_235;
}
}
V_24 = F_86 ( V_14 ) ;
if ( V_24 != 0 )
goto V_240;
V_24 = F_100 ( V_14 ) ;
if ( V_24 != 0 )
goto V_240;
V_24 = F_104 ( V_14 ) ;
if ( V_24 != 0 )
goto V_240;
V_24 = F_68 ( V_14 ) ;
if ( V_24 != 0 )
goto V_240;
V_24 = F_70 ( V_14 ) ;
if ( V_24 != 0 )
goto V_240;
V_14 -> V_26 = true ;
F_110 ( V_14 -> V_67 , V_14 -> V_65 + V_232 ,
V_241 | V_242 ,
V_241 | V_242 ) ;
V_14 -> V_39 = true ;
break;
case V_243 :
V_14 -> V_39 = false ;
V_14 -> V_26 = false ;
F_110 ( V_14 -> V_67 , V_14 -> V_65 + V_232 ,
V_241 | V_242 , 0 ) ;
F_110 ( V_14 -> V_67 , V_14 -> V_65 + V_244 ,
V_245 , 0 ) ;
F_110 ( V_14 -> V_67 , V_14 -> V_65 + V_232 ,
V_233 , 0 ) ;
F_69 (ctl, &dsp->ctl_list, list)
V_74 -> V_105 = 0 ;
F_99 ( V_14 ) ;
break;
default:
break;
}
F_19 ( & V_14 -> V_25 ) ;
return 0 ;
V_240:
F_110 ( V_14 -> V_67 , V_14 -> V_65 + V_232 ,
V_233 , 0 ) ;
V_235:
F_19 ( & V_14 -> V_25 ) ;
return V_24 ;
}
static int F_112 ( struct V_13 * V_14 )
{
unsigned int V_90 ;
int V_24 , V_21 ;
switch ( V_14 -> V_225 ) {
case 0 :
V_24 = F_113 ( V_14 -> V_67 ,
V_14 -> V_65 + V_246 ,
V_247 , V_247 ) ;
if ( V_24 != 0 )
return V_24 ;
break;
default:
break;
}
for ( V_21 = 0 ; V_21 < 10 ; ++ V_21 ) {
V_24 = F_111 ( V_14 -> V_67 , V_14 -> V_65 + V_248 , & V_90 ) ;
if ( V_24 != 0 )
return V_24 ;
if ( V_90 & V_249 )
break;
F_52 ( 250 , 500 ) ;
}
if ( ! ( V_90 & V_249 ) ) {
F_22 ( V_14 , L_100 ) ;
return - V_60 ;
}
F_41 ( V_14 , L_101 , V_21 ) ;
return 0 ;
}
static void F_114 ( struct V_135 * V_136 )
{
struct V_13 * V_14 = F_46 ( V_136 ,
struct V_13 ,
V_250 ) ;
int V_24 ;
F_17 ( & V_14 -> V_25 ) ;
V_24 = F_110 ( V_14 -> V_67 , V_14 -> V_65 + V_246 ,
V_251 , V_251 ) ;
if ( V_24 != 0 )
goto V_235;
V_24 = F_112 ( V_14 ) ;
if ( V_24 != 0 )
goto V_252;
V_24 = F_86 ( V_14 ) ;
if ( V_24 != 0 )
goto V_240;
V_24 = F_103 ( V_14 ) ;
if ( V_24 != 0 )
goto V_240;
V_24 = F_104 ( V_14 ) ;
if ( V_24 != 0 )
goto V_240;
V_24 = F_68 ( V_14 ) ;
if ( V_24 != 0 )
goto V_240;
switch ( V_14 -> V_225 ) {
case 0 :
V_24 = F_110 ( V_14 -> V_67 , V_14 -> V_65 + V_246 ,
V_247 , 0 ) ;
if ( V_24 != 0 )
goto V_240;
break;
default:
break;
}
V_14 -> V_26 = true ;
F_19 ( & V_14 -> V_25 ) ;
return;
V_240:
F_110 ( V_14 -> V_67 , V_14 -> V_65 + V_246 ,
V_247 | V_253 | V_254 , 0 ) ;
V_252:
F_110 ( V_14 -> V_67 , V_14 -> V_65 + V_246 ,
V_251 , 0 ) ;
V_235:
F_19 ( & V_14 -> V_25 ) ;
}
static void F_115 ( struct V_13 * V_14 , unsigned int V_255 )
{
int V_24 ;
switch ( V_14 -> V_225 ) {
case 0 :
V_24 = F_113 ( V_14 -> V_67 ,
V_14 -> V_65 + V_256 ,
V_257 ,
V_255 << V_258 ) ;
if ( V_24 ) {
F_22 ( V_14 , L_99 , V_24 ) ;
return;
}
break;
default:
break;
}
}
int F_116 ( struct V_45 * V_46 ,
struct V_47 * V_48 )
{
struct V_27 * V_28 = F_32 ( V_46 ) ;
struct V_13 * V_14 = F_33 ( V_28 ) ;
V_48 -> V_52 . integer . V_52 [ 0 ] = V_14 -> V_259 ;
return 0 ;
}
int F_117 ( struct V_45 * V_46 ,
struct V_47 * V_48 )
{
struct V_27 * V_28 = F_32 ( V_46 ) ;
struct V_13 * V_14 = F_33 ( V_28 ) ;
struct V_260 * V_228 = F_118 ( V_28 ) ;
struct V_261 * V_262 =
(struct V_261 * ) V_46 -> V_51 ;
char V_263 [ 32 ] ;
snprintf ( V_263 , F_27 ( V_263 ) , L_102 , V_262 -> V_230 ) ;
V_14 -> V_259 = V_48 -> V_52 . integer . V_52 [ 0 ] ;
if ( V_48 -> V_52 . integer . V_52 [ 0 ] )
F_119 ( V_228 , V_263 ) ;
else
F_120 ( V_228 , V_263 ) ;
F_121 ( V_228 ) ;
return 0 ;
}
static void F_122 ( struct V_13 * V_14 )
{
switch ( V_14 -> V_225 ) {
case 0 :
case 1 :
return;
default:
F_110 ( V_14 -> V_67 , V_14 -> V_65 + V_264 ,
V_265 , 0 ) ;
}
}
int F_123 ( struct V_226 * V_227 ,
struct V_45 * V_46 , int V_133 ,
unsigned int V_255 )
{
struct V_27 * V_28 = F_109 ( V_227 -> V_228 ) ;
struct V_13 * V_229 = F_33 ( V_28 ) ;
struct V_13 * V_14 = & V_229 [ V_227 -> V_230 ] ;
struct V_70 * V_74 ;
switch ( V_133 ) {
case V_266 :
F_115 ( V_14 , V_255 ) ;
F_124 ( V_267 , & V_14 -> V_250 ) ;
break;
case V_243 :
F_17 ( & V_14 -> V_25 ) ;
F_15 ( V_14 ) ;
V_14 -> V_40 = 0 ;
V_14 -> V_41 = 0 ;
V_14 -> V_26 = false ;
F_110 ( V_14 -> V_67 , V_14 -> V_65 + V_246 ,
V_251 , 0 ) ;
F_69 (ctl, &dsp->ctl_list, list)
V_74 -> V_105 = 0 ;
F_99 ( V_14 ) ;
F_19 ( & V_14 -> V_25 ) ;
F_41 ( V_14 , L_103 ) ;
break;
default:
break;
}
return 0 ;
}
int F_125 ( struct V_226 * V_227 ,
struct V_45 * V_46 , int V_133 )
{
struct V_27 * V_28 = F_109 ( V_227 -> V_228 ) ;
struct V_13 * V_229 = F_33 ( V_28 ) ;
struct V_13 * V_14 = & V_229 [ V_227 -> V_230 ] ;
int V_24 ;
switch ( V_133 ) {
case V_231 :
F_126 ( & V_14 -> V_250 ) ;
F_17 ( & V_14 -> V_25 ) ;
if ( ! V_14 -> V_26 ) {
V_24 = - V_268 ;
goto V_35;
}
V_24 = F_112 ( V_14 ) ;
if ( V_24 != 0 )
goto V_35;
V_24 = F_70 ( V_14 ) ;
if ( V_24 != 0 )
goto V_35;
F_127 ( V_14 , V_14 -> V_269 ) ;
V_24 = F_110 ( V_14 -> V_67 ,
V_14 -> V_65 + V_246 ,
V_253 | V_254 ,
V_253 | V_254 ) ;
if ( V_24 != 0 )
goto V_35;
if ( V_193 [ V_14 -> V_56 ] . V_270 != 0 ) {
V_24 = F_128 ( V_14 ) ;
if ( V_24 < 0 )
goto V_35;
}
V_14 -> V_39 = true ;
F_19 ( & V_14 -> V_25 ) ;
break;
case V_243 :
F_71 ( V_14 , V_271 ) ;
F_122 ( V_14 ) ;
switch ( V_14 -> V_225 ) {
case 0 :
F_39 ( V_14 ) ;
break;
default:
F_43 ( V_14 ) ;
break;
}
F_17 ( & V_14 -> V_25 ) ;
V_14 -> V_39 = false ;
F_110 ( V_14 -> V_67 ,
V_14 -> V_65 + V_246 ,
V_253 | V_254 , 0 ) ;
switch ( V_14 -> V_225 ) {
case 0 :
F_129 ( V_14 -> V_67 ,
V_14 -> V_65 + V_272 , 0 ) ;
F_129 ( V_14 -> V_67 ,
V_14 -> V_65 + V_273 , 0 ) ;
F_129 ( V_14 -> V_67 ,
V_14 -> V_65 + V_274 , 0 ) ;
F_110 ( V_14 -> V_67 ,
V_14 -> V_65 + V_246 ,
V_247 , 0 ) ;
break;
default:
F_129 ( V_14 -> V_67 ,
V_14 -> V_65 + V_272 , 0 ) ;
F_129 ( V_14 -> V_67 ,
V_14 -> V_65 + V_273 , 0 ) ;
F_129 ( V_14 -> V_67 ,
V_14 -> V_65 + V_275 , 0 ) ;
break;
}
if ( V_193 [ V_14 -> V_56 ] . V_270 != 0 )
F_130 ( V_14 ) ;
F_19 ( & V_14 -> V_25 ) ;
F_41 ( V_14 , L_104 ) ;
break;
default:
break;
}
return 0 ;
V_35:
F_110 ( V_14 -> V_67 , V_14 -> V_65 + V_246 ,
V_247 | V_253 | V_254 , 0 ) ;
F_19 ( & V_14 -> V_25 ) ;
return V_24 ;
}
int F_131 ( struct V_13 * V_14 , struct V_27 * V_28 )
{
struct V_260 * V_228 = F_118 ( V_28 ) ;
char V_263 [ 32 ] ;
snprintf ( V_263 , F_27 ( V_263 ) , L_105 , V_14 -> V_37 ) ;
F_120 ( V_228 , V_263 ) ;
F_21 ( V_14 , V_28 ) ;
V_14 -> V_28 = V_28 ;
return F_67 ( V_28 ,
& V_276 [ V_14 -> V_37 - 1 ] ,
1 ) ;
}
int F_132 ( struct V_13 * V_14 , struct V_27 * V_28 )
{
F_30 ( V_14 ) ;
return 0 ;
}
int F_133 ( struct V_13 * V_14 )
{
int V_24 ;
switch ( V_14 -> V_225 ) {
case 0 :
V_24 = F_110 ( V_14 -> V_67 , V_14 -> V_65 + V_246 ,
V_251 , 0 ) ;
if ( V_24 ) {
F_22 ( V_14 ,
L_106 , V_24 ) ;
return V_24 ;
}
break;
default:
break;
}
F_106 ( & V_14 -> V_212 ) ;
F_106 ( & V_14 -> V_153 ) ;
F_76 ( & V_14 -> V_250 , F_114 ) ;
F_107 ( & V_14 -> V_25 ) ;
return 0 ;
}
void F_134 ( struct V_13 * V_14 )
{
struct V_70 * V_74 ;
while ( ! F_7 ( & V_14 -> V_153 ) ) {
V_74 = F_8 ( & V_14 -> V_153 , struct V_70 ,
V_5 ) ;
F_9 ( & V_74 -> V_5 ) ;
F_73 ( V_74 ) ;
}
}
static inline int F_135 ( struct V_277 * V_59 )
{
return V_59 -> V_6 != NULL ;
}
static int F_136 ( struct V_277 * V_59 )
{
if ( ! V_59 -> V_14 -> V_278 )
return - V_58 ;
V_59 -> V_6 = V_59 -> V_14 -> V_278 ;
V_59 -> V_6 -> V_59 = V_59 ;
return 0 ;
}
static void F_137 ( struct V_277 * V_59 )
{
if ( ! V_59 )
return;
if ( V_59 -> V_279 )
F_138 ( V_59 -> V_279 ) ;
if ( F_135 ( V_59 ) ) {
V_59 -> V_6 -> V_59 = NULL ;
V_59 -> V_6 = NULL ;
}
}
int F_139 ( struct V_13 * V_14 , struct V_280 * V_279 )
{
struct V_277 * V_59 ;
int V_24 = 0 ;
F_17 ( & V_14 -> V_25 ) ;
if ( V_193 [ V_14 -> V_56 ] . V_270 == 0 ) {
F_22 ( V_14 , L_107 ) ;
V_24 = - V_281 ;
goto V_109;
}
if ( V_193 [ V_14 -> V_56 ] . V_282 != V_279 -> V_283 ) {
F_22 ( V_14 , L_108 ) ;
V_24 = - V_58 ;
goto V_109;
}
if ( V_14 -> V_59 ) {
F_22 ( V_14 , L_109 ) ;
V_24 = - V_60 ;
goto V_109;
}
V_59 = F_2 ( sizeof( * V_59 ) , V_7 ) ;
if ( ! V_59 ) {
V_24 = - V_96 ;
goto V_109;
}
V_59 -> V_14 = V_14 ;
V_59 -> V_279 = V_279 ;
V_14 -> V_59 = V_59 ;
V_279 -> V_284 -> V_23 = V_59 ;
V_109:
F_19 ( & V_14 -> V_25 ) ;
return V_24 ;
}
int F_140 ( struct V_280 * V_279 )
{
struct V_277 * V_59 = V_279 -> V_284 -> V_23 ;
struct V_13 * V_14 = V_59 -> V_14 ;
F_17 ( & V_14 -> V_25 ) ;
F_137 ( V_59 ) ;
V_14 -> V_59 = NULL ;
F_4 ( V_59 -> V_285 ) ;
F_4 ( V_59 ) ;
F_19 ( & V_14 -> V_25 ) ;
return 0 ;
}
static int F_141 ( struct V_280 * V_279 ,
struct V_286 * V_287 )
{
struct V_277 * V_59 = V_279 -> V_284 -> V_23 ;
struct V_13 * V_14 = V_59 -> V_14 ;
const struct V_288 * V_289 ;
const struct V_290 * V_291 ;
int V_32 , V_292 ;
if ( V_287 -> V_278 . V_293 < V_294 ||
V_287 -> V_278 . V_293 > V_295 ||
V_287 -> V_278 . V_296 < V_297 ||
V_287 -> V_278 . V_296 > V_298 ||
V_287 -> V_278 . V_293 % V_299 ) {
F_22 ( V_14 , L_110 ,
V_287 -> V_278 . V_293 ,
V_287 -> V_278 . V_296 ) ;
return - V_58 ;
}
for ( V_32 = 0 ; V_32 < V_193 [ V_14 -> V_56 ] . V_270 ; V_32 ++ ) {
V_289 = & V_193 [ V_14 -> V_56 ] . V_289 [ V_32 ] ;
V_291 = & V_289 -> V_291 ;
if ( V_289 -> V_165 != V_287 -> V_28 . V_165 )
continue;
if ( V_279 -> V_283 == V_300 ) {
if ( V_291 -> V_301 < V_287 -> V_28 . V_302 )
continue;
} else {
if ( V_291 -> V_301 < V_287 -> V_28 . V_303 )
continue;
}
if ( ! ( V_291 -> V_304 & ( 1 << V_287 -> V_28 . V_305 ) ) )
continue;
for ( V_292 = 0 ; V_292 < V_291 -> V_306 ; ++ V_292 )
if ( V_291 -> V_307 [ V_292 ] == V_287 -> V_28 . V_308 )
return 0 ;
}
F_22 ( V_14 , L_111 ,
V_287 -> V_28 . V_165 , V_287 -> V_28 . V_303 , V_287 -> V_28 . V_302 ,
V_287 -> V_28 . V_308 , V_287 -> V_28 . V_305 ) ;
return - V_58 ;
}
static inline unsigned int F_142 ( struct V_277 * V_59 )
{
return V_59 -> V_106 . V_293 / V_299 ;
}
int F_143 ( struct V_280 * V_279 ,
struct V_286 * V_287 )
{
struct V_277 * V_59 = V_279 -> V_284 -> V_23 ;
unsigned int V_106 ;
int V_24 ;
V_24 = F_141 ( V_279 , V_287 ) ;
if ( V_24 )
return V_24 ;
V_59 -> V_106 = V_287 -> V_278 ;
F_41 ( V_59 -> V_14 , L_112 ,
V_59 -> V_106 . V_293 , V_59 -> V_106 . V_296 ) ;
V_106 = F_142 ( V_59 ) * sizeof( * V_59 -> V_285 ) ;
V_59 -> V_285 = F_23 ( V_106 , V_95 | V_7 ) ;
if ( ! V_59 -> V_285 )
return - V_96 ;
V_59 -> V_308 = V_287 -> V_28 . V_308 ;
return 0 ;
}
int F_144 ( struct V_280 * V_279 ,
struct V_309 * V_289 )
{
struct V_277 * V_59 = V_279 -> V_284 -> V_23 ;
int V_56 = V_59 -> V_14 -> V_56 ;
int V_32 ;
if ( V_193 [ V_56 ] . V_289 ) {
for ( V_32 = 0 ; V_32 < V_193 [ V_56 ] . V_270 ; V_32 ++ )
V_289 -> V_310 [ V_32 ] = V_193 [ V_56 ] . V_289 [ V_32 ] . V_165 ;
V_289 -> V_311 = V_32 ;
V_289 -> V_283 = V_193 [ V_56 ] . V_282 ;
V_289 -> V_312 = V_294 ;
V_289 -> V_313 = V_295 ;
V_289 -> V_314 = V_297 ;
V_289 -> V_315 = V_298 ;
}
return 0 ;
}
static int F_145 ( struct V_13 * V_14 , int V_171 ,
unsigned int V_316 ,
unsigned int V_317 , T_6 * V_99 )
{
struct V_61 const * V_63 = F_35 ( V_14 , V_171 ) ;
unsigned int V_32 , V_75 ;
int V_24 ;
if ( ! V_63 )
return - V_58 ;
V_75 = F_36 ( V_63 , V_316 ) ;
V_24 = F_40 ( V_14 -> V_67 , V_75 , V_99 ,
sizeof( * V_99 ) * V_317 ) ;
if ( V_24 < 0 )
return V_24 ;
for ( V_32 = 0 ; V_32 < V_317 ; ++ V_32 )
V_99 [ V_32 ] = F_44 ( V_99 [ V_32 ] ) & 0x00ffffffu ;
return 0 ;
}
static inline int F_146 ( struct V_13 * V_14 , int V_171 ,
unsigned int V_316 , T_6 * V_99 )
{
return F_145 ( V_14 , V_171 , V_316 , 1 , V_99 ) ;
}
static int F_147 ( struct V_13 * V_14 , int V_171 ,
unsigned int V_316 , T_6 V_99 )
{
struct V_61 const * V_63 = F_35 ( V_14 , V_171 ) ;
unsigned int V_75 ;
if ( ! V_63 )
return - V_58 ;
V_75 = F_36 ( V_63 , V_316 ) ;
V_99 = F_50 ( V_99 & 0x00ffffffu ) ;
return F_51 ( V_14 -> V_67 , V_75 , & V_99 , sizeof( V_99 ) ) ;
}
static inline int F_148 ( struct V_318 * V_6 ,
unsigned int V_319 , T_6 * V_99 )
{
return F_146 ( V_6 -> V_14 , V_10 ,
V_6 -> V_320 + V_319 , V_99 ) ;
}
static inline int F_149 ( struct V_318 * V_6 ,
unsigned int V_319 , T_6 V_99 )
{
return F_147 ( V_6 -> V_14 , V_10 ,
V_6 -> V_320 + V_319 , V_99 ) ;
}
static int F_150 ( struct V_318 * V_6 )
{
struct V_76 * V_77 ;
struct V_13 * V_14 = V_6 -> V_14 ;
T_6 V_321 , V_322 , V_196 ;
int V_32 , V_24 ;
V_77 = F_97 ( V_14 , V_10 , V_14 -> V_40 ) ;
V_321 = sizeof( struct V_323 ) / sizeof( T_8 ) ;
V_322 = V_77 -> V_65 + V_321 + F_151 ( V_196 ) ;
V_24 = F_146 ( V_14 , V_10 , V_322 , & V_196 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_196 != V_324 )
return - V_58 ;
V_322 = V_77 -> V_65 + V_321 + F_151 ( V_320 ) ;
for ( V_32 = 0 ; V_32 < 5 ; ++ V_32 ) {
V_24 = F_146 ( V_14 , V_10 , V_322 ,
& V_6 -> V_320 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_6 -> V_320 )
break;
F_52 ( 1000 , 2000 ) ;
}
if ( ! V_6 -> V_320 )
return - V_268 ;
F_41 ( V_14 , L_113 , V_6 -> V_320 ) ;
return 0 ;
}
static int F_152 ( struct V_318 * V_6 )
{
const struct V_288 * V_289 = V_193 [ V_6 -> V_14 -> V_56 ] . V_289 ;
struct V_325 * V_177 ;
T_6 V_64 = 0 ;
int V_32 , V_24 ;
for ( V_32 = 0 ; V_32 < V_289 -> V_326 ; ++ V_32 ) {
V_177 = & V_6 -> V_190 [ V_32 ] ;
V_177 -> V_64 = V_64 ;
V_177 -> V_171 = V_289 -> V_327 [ V_32 ] . V_171 ;
V_24 = F_148 ( V_6 , V_289 -> V_327 [ V_32 ] . V_328 ,
& V_177 -> V_329 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_148 ( V_6 , V_289 -> V_327 [ V_32 ] . V_330 ,
& V_64 ) ;
if ( V_24 < 0 )
return V_24 ;
V_177 -> V_331 = V_64 ;
F_41 ( V_6 -> V_14 ,
L_114 ,
V_32 , V_177 -> V_171 , V_177 -> V_329 ,
V_177 -> V_64 , V_177 -> V_331 ) ;
}
return 0 ;
}
static int F_128 ( struct V_13 * V_14 )
{
struct V_318 * V_6 ;
int V_24 ;
V_6 = F_2 ( sizeof( * V_6 ) , V_7 ) ;
if ( ! V_6 )
return - V_96 ;
V_6 -> V_14 = V_14 ;
V_6 -> V_332 = - 1 ;
V_6 -> V_333 = 0xFFFFFFFF ;
V_24 = F_150 ( V_6 ) ;
if ( V_24 < 0 ) {
F_22 ( V_14 , L_115 , V_24 ) ;
goto V_334;
}
V_6 -> V_190 = F_153 ( V_193 [ V_14 -> V_56 ] . V_289 -> V_326 ,
sizeof( * V_6 -> V_190 ) , V_7 ) ;
if ( ! V_6 -> V_190 ) {
V_24 = - V_96 ;
goto V_334;
}
V_24 = F_152 ( V_6 ) ;
if ( V_24 < 0 ) {
F_22 ( V_14 , L_116 , V_24 ) ;
goto V_335;
}
V_14 -> V_278 = V_6 ;
return 0 ;
V_335:
F_4 ( V_6 -> V_190 ) ;
V_334:
F_4 ( V_6 ) ;
return V_24 ;
}
static int F_130 ( struct V_13 * V_14 )
{
if ( V_14 -> V_278 ) {
F_137 ( V_14 -> V_278 -> V_59 ) ;
F_4 ( V_14 -> V_278 -> V_190 ) ;
F_4 ( V_14 -> V_278 ) ;
V_14 -> V_278 = NULL ;
}
return 0 ;
}
int F_154 ( struct V_280 * V_279 , int V_336 )
{
struct V_277 * V_59 = V_279 -> V_284 -> V_23 ;
struct V_13 * V_14 = V_59 -> V_14 ;
int V_24 = 0 ;
F_41 ( V_14 , L_117 , V_336 ) ;
F_17 ( & V_14 -> V_25 ) ;
switch ( V_336 ) {
case V_337 :
if ( F_135 ( V_59 ) )
break;
V_24 = F_136 ( V_59 ) ;
if ( V_24 < 0 ) {
F_22 ( V_14 , L_118 ,
V_24 ) ;
break;
}
V_24 = F_149 ( V_59 -> V_6 ,
F_155 ( V_338 ) ,
F_142 ( V_59 ) ) ;
if ( V_24 < 0 ) {
F_22 ( V_14 , L_119 ,
V_24 ) ;
break;
}
break;
case V_339 :
break;
default:
V_24 = - V_58 ;
break;
}
F_19 ( & V_14 -> V_25 ) ;
return V_24 ;
}
static inline int F_156 ( struct V_318 * V_6 )
{
int V_340 = V_193 [ V_6 -> V_14 -> V_56 ] . V_289 -> V_326 - 1 ;
return V_6 -> V_190 [ V_340 ] . V_331 ;
}
static int F_157 ( struct V_318 * V_6 )
{
T_6 V_341 , V_342 ;
int V_343 , V_332 , V_145 ;
int V_24 ;
if ( V_6 -> V_332 < 0 ) {
V_24 = F_148 ( V_6 ,
F_155 ( V_341 ) ,
& V_341 ) ;
if ( V_24 < 0 )
return V_24 ;
V_332 = F_158 ( V_341 , 23 ) ;
if ( V_332 < 0 ) {
F_41 ( V_6 -> V_14 , L_120 ) ;
return 0 ;
}
V_6 -> V_332 = V_332 ;
}
V_24 = F_148 ( V_6 , F_155 ( V_342 ) ,
& V_342 ) ;
if ( V_24 < 0 )
return V_24 ;
V_343 = F_158 ( V_342 , 23 ) ;
V_145 = V_343 - V_6 -> V_332 ;
if ( V_145 < 0 )
V_145 += F_156 ( V_6 ) ;
F_41 ( V_6 -> V_14 , L_121 ,
V_6 -> V_332 , V_343 , V_145 * V_299 ) ;
V_6 -> V_145 = V_145 ;
return 0 ;
}
static int F_159 ( struct V_318 * V_6 )
{
int V_24 ;
V_24 = F_148 ( V_6 , F_155 ( error ) , & V_6 -> error ) ;
if ( V_24 < 0 ) {
F_22 ( V_6 -> V_14 , L_122 , V_24 ) ;
return V_24 ;
}
if ( V_6 -> error != 0 ) {
F_22 ( V_6 -> V_14 , L_123 , V_6 -> error ) ;
return - V_268 ;
}
return 0 ;
}
int F_160 ( struct V_13 * V_14 )
{
struct V_318 * V_6 ;
struct V_277 * V_59 ;
int V_24 = 0 ;
F_17 ( & V_14 -> V_25 ) ;
V_6 = V_14 -> V_278 ;
V_59 = V_14 -> V_59 ;
if ( ! V_6 ) {
V_24 = - V_344 ;
goto V_109;
}
F_41 ( V_14 , L_124 ) ;
V_24 = F_159 ( V_6 ) ;
if ( V_24 < 0 )
goto V_345;
V_24 = F_148 ( V_6 , F_155 ( V_333 ) ,
& V_6 -> V_333 ) ;
if ( V_24 < 0 ) {
F_22 ( V_14 , L_125 , V_24 ) ;
goto V_109;
}
V_24 = F_157 ( V_6 ) ;
if ( V_24 < 0 ) {
F_22 ( V_14 , L_126 , V_24 ) ;
goto V_109;
}
if ( V_193 [ V_14 -> V_56 ] . V_346 && V_6 -> V_333 == 2 )
V_24 = V_347 ;
V_345:
if ( V_59 && V_59 -> V_279 )
F_138 ( V_59 -> V_279 ) ;
V_109:
F_19 ( & V_14 -> V_25 ) ;
return V_24 ;
}
static int F_161 ( struct V_318 * V_6 )
{
if ( V_6 -> V_333 & 0x01 )
return 0 ;
F_41 ( V_6 -> V_14 , L_127 ,
V_6 -> V_333 ) ;
V_6 -> V_333 |= 0x01 ;
return F_149 ( V_6 , F_155 ( V_348 ) ,
V_6 -> V_333 ) ;
}
int F_162 ( struct V_280 * V_279 ,
struct V_349 * V_350 )
{
struct V_277 * V_59 = V_279 -> V_284 -> V_23 ;
struct V_13 * V_14 = V_59 -> V_14 ;
struct V_318 * V_6 ;
int V_24 = 0 ;
F_41 ( V_14 , L_128 ) ;
F_17 ( & V_14 -> V_25 ) ;
V_6 = V_59 -> V_6 ;
if ( ! V_59 -> V_6 || V_59 -> V_6 -> error ) {
F_163 ( V_279 , V_351 ) ;
V_24 = - V_268 ;
goto V_109;
}
if ( V_6 -> V_145 < F_142 ( V_59 ) ) {
V_24 = F_157 ( V_6 ) ;
if ( V_24 < 0 ) {
F_22 ( V_14 , L_126 , V_24 ) ;
goto V_109;
}
if ( V_6 -> V_145 < F_142 ( V_59 ) ) {
V_24 = F_159 ( V_6 ) ;
if ( V_24 < 0 ) {
if ( V_59 -> V_6 -> error )
F_163 ( V_279 ,
V_351 ) ;
goto V_109;
}
V_24 = F_161 ( V_6 ) ;
if ( V_24 < 0 ) {
F_22 ( V_14 ,
L_129 ,
V_24 ) ;
goto V_109;
}
}
}
V_350 -> V_352 = V_59 -> V_352 ;
V_350 -> V_352 += V_6 -> V_145 * V_299 ;
V_350 -> V_353 = V_59 -> V_308 ;
V_109:
F_19 ( & V_14 -> V_25 ) ;
return V_24 ;
}
static int F_164 ( struct V_277 * V_59 , int V_354 )
{
struct V_318 * V_6 = V_59 -> V_6 ;
T_7 * V_355 = ( T_7 * ) V_59 -> V_285 ;
T_7 * V_356 = ( T_7 * ) V_59 -> V_285 ;
unsigned int V_357 ;
int V_171 , V_358 , V_359 ;
int V_32 , V_292 , V_24 ;
for ( V_32 = 0 ; V_32 < V_193 [ V_6 -> V_14 -> V_56 ] . V_289 -> V_326 ; ++ V_32 )
if ( V_6 -> V_332 < V_6 -> V_190 [ V_32 ] . V_331 )
break;
if ( V_32 == V_193 [ V_6 -> V_14 -> V_56 ] . V_289 -> V_326 )
return - V_58 ;
V_171 = V_6 -> V_190 [ V_32 ] . V_171 ;
V_357 = V_6 -> V_190 [ V_32 ] . V_329 +
( V_6 -> V_332 - V_6 -> V_190 [ V_32 ] . V_64 ) ;
V_359 = F_142 ( V_59 ) ;
V_358 = V_6 -> V_190 [ V_32 ] . V_331 - V_6 -> V_332 ;
if ( V_358 > V_354 )
V_358 = V_354 ;
if ( V_358 > V_6 -> V_145 )
V_358 = V_6 -> V_145 ;
if ( V_358 > V_359 )
V_358 = V_359 ;
if ( ! V_358 )
return 0 ;
V_24 = F_145 ( V_6 -> V_14 , V_171 , V_357 ,
V_358 , V_59 -> V_285 ) ;
if ( V_24 < 0 )
return V_24 ;
for ( V_32 = 0 ; V_32 < V_358 ; V_32 ++ ) {
for ( V_292 = 0 ; V_292 < V_299 ; V_292 ++ )
* V_356 ++ = * V_355 ++ ;
V_355 += sizeof( * ( V_59 -> V_285 ) ) - V_299 ;
}
V_6 -> V_332 += V_358 ;
if ( V_6 -> V_332 == F_156 ( V_6 ) )
V_6 -> V_332 = 0 ;
V_24 = F_149 ( V_6 , F_155 ( V_341 ) ,
V_6 -> V_332 ) ;
if ( V_24 < 0 )
return V_24 ;
V_6 -> V_145 -= V_358 ;
return V_358 ;
}
static int F_165 ( struct V_277 * V_59 ,
char T_3 * V_6 , T_1 V_21 )
{
struct V_13 * V_14 = V_59 -> V_14 ;
int V_360 = 0 ;
int V_358 , V_361 ;
F_41 ( V_14 , L_130 , V_21 ) ;
if ( ! V_59 -> V_6 || V_59 -> V_6 -> error ) {
F_163 ( V_59 -> V_279 , V_351 ) ;
return - V_268 ;
}
V_21 /= V_299 ;
do {
V_358 = F_164 ( V_59 , V_21 ) ;
if ( V_358 < 0 ) {
F_22 ( V_14 , L_131 , V_358 ) ;
return V_358 ;
}
V_361 = V_358 * V_299 ;
F_41 ( V_14 , L_132 , V_361 ) ;
if ( F_63 ( V_6 + V_360 , V_59 -> V_285 , V_361 ) ) {
F_22 ( V_14 , L_133 ,
V_360 , V_361 ) ;
return - V_107 ;
}
V_21 -= V_358 ;
V_360 += V_361 ;
} while ( V_358 > 0 && V_21 > 0 );
V_59 -> V_352 += V_360 ;
return V_360 ;
}
int F_166 ( struct V_280 * V_279 , char T_3 * V_6 ,
T_1 V_21 )
{
struct V_277 * V_59 = V_279 -> V_284 -> V_23 ;
struct V_13 * V_14 = V_59 -> V_14 ;
int V_24 ;
F_17 ( & V_14 -> V_25 ) ;
if ( V_279 -> V_283 == V_362 )
V_24 = F_165 ( V_59 , V_6 , V_21 ) ;
else
V_24 = - V_363 ;
F_19 ( & V_14 -> V_25 ) ;
return V_24 ;
}
int F_127 ( struct V_13 * V_14 , unsigned int V_269 )
{
struct V_67 * V_67 = V_14 -> V_67 ;
unsigned int V_364 , V_365 , V_366 ;
if ( ! ( V_269 & V_367 ) )
return 0 ;
V_269 &= V_367 ;
V_366 = V_14 -> V_65 + V_368 ;
while ( V_269 ) {
V_364 = V_365 = 0 ;
if ( V_269 & F_167 ( 0 ) ) {
V_364 = V_369 ;
V_365 = V_370 ;
}
if ( V_269 & F_167 ( 1 ) ) {
V_364 |= V_369 << V_371 ;
V_365 |= V_370 << V_371 ;
}
F_129 ( V_67 , V_366 , V_364 ) ;
F_129 ( V_67 , V_366 , V_365 ) ;
V_269 >>= 2 ;
V_366 += 2 ;
}
return 0 ;
}
T_9 F_168 ( struct V_13 * V_14 )
{
unsigned int V_90 ;
struct V_67 * V_67 = V_14 -> V_67 ;
int V_24 = 0 ;
V_24 = F_111 ( V_67 , V_14 -> V_65 + V_372 , & V_90 ) ;
if ( V_24 ) {
F_22 ( V_14 ,
L_134 , V_24 ) ;
return V_373 ;
}
if ( V_90 & V_374 ) {
F_22 ( V_14 , L_135 ) ;
F_122 ( V_14 ) ;
}
if ( V_90 & ( V_375 | V_376 ) ) {
if ( V_90 & V_375 )
F_22 ( V_14 , L_136 ) ;
else
F_22 ( V_14 , L_137 ) ;
V_24 = F_111 ( V_67 , V_14 -> V_65 + V_377 , & V_90 ) ;
if ( V_24 ) {
F_22 ( V_14 ,
L_138 ,
V_24 ) ;
return V_373 ;
}
F_22 ( V_14 , L_139 ,
V_90 & V_378 ) ;
V_24 = F_111 ( V_67 ,
V_14 -> V_65 + V_379 ,
& V_90 ) ;
if ( V_24 ) {
F_22 ( V_14 ,
L_140 ,
V_24 ) ;
return V_373 ;
}
F_22 ( V_14 , L_141 ,
V_90 & V_380 ) ;
F_22 ( V_14 , L_142 ,
( V_90 & V_381 ) >>
V_382 ) ;
}
F_110 ( V_67 , V_14 -> V_65 + V_372 ,
V_383 , V_383 ) ;
return V_373 ;
}
