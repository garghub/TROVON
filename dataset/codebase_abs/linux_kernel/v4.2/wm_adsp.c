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
F_13 ( & V_9 -> V_12 ) ;
F_10 ( V_9 -> V_13 ) ;
V_9 -> V_13 = V_11 ;
F_14 ( & V_9 -> V_12 ) ;
}
static void F_15 ( struct V_8 * V_9 , const char * V_10 )
{
char * V_11 = F_12 ( V_7 , L_1 , V_10 ) ;
F_13 ( & V_9 -> V_12 ) ;
F_10 ( V_9 -> V_14 ) ;
V_9 -> V_14 = V_11 ;
F_14 ( & V_9 -> V_12 ) ;
}
static void F_16 ( struct V_8 * V_9 )
{
F_13 ( & V_9 -> V_12 ) ;
F_10 ( V_9 -> V_13 ) ;
F_10 ( V_9 -> V_14 ) ;
V_9 -> V_13 = NULL ;
V_9 -> V_14 = NULL ;
F_14 ( & V_9 -> V_12 ) ;
}
static T_2 F_17 ( struct V_15 * V_15 ,
char T_3 * V_16 ,
T_1 V_17 , T_4 * V_18 )
{
struct V_8 * V_9 = V_15 -> V_19 ;
T_2 V_20 ;
F_13 ( & V_9 -> V_12 ) ;
if ( ! V_9 -> V_13 || ! V_9 -> V_21 )
V_20 = 0 ;
else
V_20 = F_18 ( V_16 , V_17 , V_18 ,
V_9 -> V_13 ,
strlen ( V_9 -> V_13 ) ) ;
F_14 ( & V_9 -> V_12 ) ;
return V_20 ;
}
static T_2 F_19 ( struct V_15 * V_15 ,
char T_3 * V_16 ,
T_1 V_17 , T_4 * V_18 )
{
struct V_8 * V_9 = V_15 -> V_19 ;
T_2 V_20 ;
F_13 ( & V_9 -> V_12 ) ;
if ( ! V_9 -> V_14 || ! V_9 -> V_21 )
V_20 = 0 ;
else
V_20 = F_18 ( V_16 , V_17 , V_18 ,
V_9 -> V_14 ,
strlen ( V_9 -> V_14 ) ) ;
F_14 ( & V_9 -> V_12 ) ;
return V_20 ;
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
F_16 ( V_9 ) ;
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
static inline void F_15 ( struct V_8 * V_9 ,
const char * V_10 )
{
}
static inline void F_16 ( struct V_8 * V_9 )
{
}
static int F_30 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_22 * V_23 = F_31 ( V_40 ) ;
struct V_43 * V_44 = (struct V_43 * ) V_40 -> V_45 ;
struct V_8 * V_9 = F_32 ( V_23 ) ;
V_42 -> V_46 . integer . V_46 [ 0 ] = V_9 [ V_44 -> V_47 ] . V_48 ;
return 0 ;
}
static int F_33 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_22 * V_23 = F_31 ( V_40 ) ;
struct V_43 * V_44 = (struct V_43 * ) V_40 -> V_45 ;
struct V_8 * V_9 = F_32 ( V_23 ) ;
if ( V_42 -> V_46 . integer . V_46 [ 0 ] == V_9 [ V_44 -> V_47 ] . V_48 )
return 0 ;
if ( V_42 -> V_46 . integer . V_46 [ 0 ] >= V_49 )
return - V_50 ;
if ( V_9 [ V_44 -> V_47 ] . V_21 )
return - V_51 ;
V_9 [ V_44 -> V_47 ] . V_48 = V_42 -> V_46 . integer . V_46 [ 0 ] ;
return 0 ;
}
static struct V_52 const * F_34 ( struct V_8 * V_9 ,
int type )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_9 -> V_53 ; V_27 ++ )
if ( V_9 -> V_54 [ V_27 ] . type == type )
return & V_9 -> V_54 [ V_27 ] ;
return NULL ;
}
static unsigned int F_35 ( struct V_52 const * V_54 ,
unsigned int V_55 )
{
if ( F_36 ( ! V_54 ) )
return V_55 ;
switch ( V_54 -> type ) {
case V_56 :
return V_54 -> V_57 + ( V_55 * 3 ) ;
case V_58 :
return V_54 -> V_57 + ( V_55 * 2 ) ;
case V_59 :
return V_54 -> V_57 + ( V_55 * 2 ) ;
case V_60 :
return V_54 -> V_57 + ( V_55 * 2 ) ;
case V_61 :
return V_54 -> V_57 + ( V_55 * 2 ) ;
default:
F_37 ( 1 , L_8 ) ;
return V_55 ;
}
}
static void F_38 ( struct V_8 * V_9 )
{
T_5 V_62 [ 4 ] ;
int V_20 ;
V_20 = F_39 ( V_9 -> V_63 , V_9 -> V_57 + V_64 ,
V_62 , sizeof( V_62 ) ) ;
if ( V_20 ) {
F_21 ( V_9 , L_9 , V_20 ) ;
return;
}
F_40 ( V_9 , L_10 ,
F_41 ( V_62 [ 0 ] ) ,
F_41 ( V_62 [ 1 ] ) ,
F_41 ( V_62 [ 2 ] ) ,
F_41 ( V_62 [ 3 ] ) ) ;
}
static int F_42 ( struct V_39 * V_40 ,
struct V_65 * V_66 )
{
struct V_67 * V_68 = (struct V_67 * ) V_40 -> V_45 ;
V_66 -> type = V_69 ;
V_66 -> V_17 = V_68 -> V_3 ;
return 0 ;
}
static int F_43 ( struct V_67 * V_68 ,
const void * V_6 , T_1 V_3 )
{
struct V_70 * V_71 = & V_68 -> V_71 ;
const struct V_52 * V_54 ;
struct V_8 * V_9 = V_68 -> V_9 ;
void * V_62 ;
int V_20 ;
unsigned int V_72 ;
V_54 = F_34 ( V_9 , V_71 -> type ) ;
if ( ! V_54 ) {
F_21 ( V_9 , L_11 ,
V_71 -> type ) ;
return - V_50 ;
}
V_72 = V_68 -> V_71 . V_57 + V_68 -> V_55 ;
V_72 = F_35 ( V_54 , V_72 ) ;
V_62 = F_44 ( V_6 , V_68 -> V_3 , V_7 | V_73 ) ;
if ( ! V_62 )
return - V_74 ;
V_20 = F_45 ( V_9 -> V_63 , V_72 , V_62 ,
V_68 -> V_3 ) ;
if ( V_20 ) {
F_21 ( V_9 , L_12 ,
V_68 -> V_3 , V_72 , V_20 ) ;
F_10 ( V_62 ) ;
return V_20 ;
}
F_40 ( V_9 , L_13 , V_68 -> V_3 , V_72 ) ;
F_10 ( V_62 ) ;
return 0 ;
}
static int F_46 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_67 * V_68 = (struct V_67 * ) V_40 -> V_45 ;
char * V_75 = V_42 -> V_46 . V_76 . V_77 ;
memcpy ( V_68 -> V_78 , V_75 , V_68 -> V_3 ) ;
V_68 -> V_79 = 1 ;
if ( ! V_68 -> V_80 )
return 0 ;
return F_43 ( V_68 , V_75 , V_68 -> V_3 ) ;
}
static int F_47 ( struct V_67 * V_68 ,
void * V_6 , T_1 V_3 )
{
struct V_70 * V_71 = & V_68 -> V_71 ;
const struct V_52 * V_54 ;
struct V_8 * V_9 = V_68 -> V_9 ;
void * V_62 ;
int V_20 ;
unsigned int V_72 ;
V_54 = F_34 ( V_9 , V_71 -> type ) ;
if ( ! V_54 ) {
F_21 ( V_9 , L_11 ,
V_71 -> type ) ;
return - V_50 ;
}
V_72 = V_68 -> V_71 . V_57 + V_68 -> V_55 ;
V_72 = F_35 ( V_54 , V_72 ) ;
V_62 = F_22 ( V_68 -> V_3 , V_7 | V_73 ) ;
if ( ! V_62 )
return - V_74 ;
V_20 = F_39 ( V_9 -> V_63 , V_72 , V_62 , V_68 -> V_3 ) ;
if ( V_20 ) {
F_21 ( V_9 , L_14 ,
V_68 -> V_3 , V_72 , V_20 ) ;
F_10 ( V_62 ) ;
return V_20 ;
}
F_40 ( V_9 , L_15 , V_68 -> V_3 , V_72 ) ;
memcpy ( V_6 , V_62 , V_68 -> V_3 ) ;
F_10 ( V_62 ) ;
return 0 ;
}
static int F_48 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_67 * V_68 = (struct V_67 * ) V_40 -> V_45 ;
char * V_75 = V_42 -> V_46 . V_76 . V_77 ;
if ( V_68 -> V_81 & V_82 ) {
if ( V_68 -> V_80 )
return F_47 ( V_68 , V_75 , V_68 -> V_3 ) ;
else
return - V_83 ;
}
memcpy ( V_75 , V_68 -> V_78 , V_68 -> V_3 ) ;
return 0 ;
}
static int F_49 ( struct V_8 * V_9 , struct V_67 * V_68 )
{
struct V_84 * V_40 ;
int V_20 ;
if ( ! V_68 || ! V_68 -> V_37 )
return - V_50 ;
V_40 = F_2 ( sizeof( * V_40 ) , V_7 ) ;
if ( ! V_40 )
return - V_74 ;
V_40 -> V_85 = V_86 ;
V_40 -> V_37 = V_68 -> V_37 ;
V_40 -> V_87 = F_42 ;
V_40 -> V_88 = F_48 ;
V_40 -> V_89 = F_46 ;
V_40 -> V_45 = ( unsigned long ) V_68 ;
if ( V_68 -> V_81 ) {
if ( V_68 -> V_81 & V_90 )
V_40 -> V_91 |= V_92 ;
if ( V_68 -> V_81 & V_93 )
V_40 -> V_91 |= V_94 ;
if ( V_68 -> V_81 & V_82 )
V_40 -> V_91 |= V_95 ;
}
V_20 = F_50 ( V_9 -> V_96 ,
V_40 , 1 ) ;
if ( V_20 < 0 )
goto V_97;
F_10 ( V_40 ) ;
V_68 -> V_40 = F_51 ( V_9 -> V_96 ,
V_68 -> V_37 ) ;
return 0 ;
V_97:
F_10 ( V_40 ) ;
return V_20 ;
}
static int F_52 ( struct V_8 * V_9 )
{
struct V_67 * V_68 ;
int V_20 ;
F_53 (ctl, &dsp->ctl_list, list) {
if ( ! V_68 -> V_80 || V_68 -> V_79 )
continue;
if ( V_68 -> V_81 & V_82 )
continue;
V_20 = F_47 ( V_68 ,
V_68 -> V_78 ,
V_68 -> V_3 ) ;
if ( V_20 < 0 )
return V_20 ;
}
return 0 ;
}
static int F_54 ( struct V_8 * V_9 )
{
struct V_67 * V_68 ;
int V_20 ;
F_53 (ctl, &dsp->ctl_list, list) {
if ( ! V_68 -> V_80 )
continue;
if ( V_68 -> V_79 && ! ( V_68 -> V_81 & V_82 ) ) {
V_20 = F_43 ( V_68 ,
V_68 -> V_78 ,
V_68 -> V_3 ) ;
if ( V_20 < 0 )
return V_20 ;
}
}
return 0 ;
}
static void F_55 ( struct V_98 * V_99 )
{
struct V_100 * V_101 = F_56 ( V_99 ,
struct V_100 ,
V_99 ) ;
F_49 ( V_101 -> V_9 , V_101 -> V_68 ) ;
F_10 ( V_101 ) ;
}
static int F_57 ( struct V_8 * V_9 ,
const struct V_70 * V_71 ,
unsigned int V_55 , unsigned int V_3 ,
const char * V_102 , unsigned int V_103 ,
unsigned int V_81 )
{
struct V_67 * V_68 ;
struct V_100 * V_101 ;
char V_37 [ V_104 ] ;
char * V_105 ;
int V_20 ;
if ( V_81 & V_106 )
return 0 ;
switch ( V_71 -> type ) {
case V_56 :
V_105 = L_16 ;
break;
case V_58 :
V_105 = L_17 ;
break;
case V_59 :
V_105 = L_18 ;
break;
case V_60 :
V_105 = L_19 ;
break;
case V_61 :
V_105 = L_20 ;
break;
default:
F_21 ( V_9 , L_21 , V_71 -> type ) ;
return - V_50 ;
}
switch ( V_9 -> V_107 ) {
case 0 :
case 1 :
snprintf ( V_37 , V_104 , L_22 ,
V_9 -> V_32 , V_105 , V_71 -> V_108 ) ;
break;
default:
V_20 = snprintf ( V_37 , V_104 ,
L_23 , V_9 -> V_32 , * V_105 ,
V_109 [ V_9 -> V_48 ] , V_71 -> V_108 ) ;
if ( V_102 ) {
int V_110 = V_104 - V_20 - 2 ;
int V_111 = 0 ;
if ( V_103 > V_110 )
V_111 = V_103 - V_110 ;
snprintf ( V_37 + V_20 ,
V_104 - V_20 , L_24 ,
V_103 - V_111 , V_102 + V_111 ) ;
}
break;
}
F_53 (ctl, &dsp->ctl_list,
list) {
if ( ! strcmp ( V_68 -> V_37 , V_37 ) ) {
if ( ! V_68 -> V_80 )
V_68 -> V_80 = 1 ;
return 0 ;
}
}
V_68 = F_2 ( sizeof( * V_68 ) , V_7 ) ;
if ( ! V_68 )
return - V_74 ;
V_68 -> V_112 = V_109 [ V_9 -> V_48 ] ;
V_68 -> V_71 = * V_71 ;
V_68 -> V_37 = F_44 ( V_37 , strlen ( V_37 ) + 1 , V_7 ) ;
if ( ! V_68 -> V_37 ) {
V_20 = - V_74 ;
goto V_113;
}
V_68 -> V_80 = 1 ;
V_68 -> V_79 = 0 ;
V_68 -> V_114 . V_115 = F_48 ;
V_68 -> V_114 . V_116 = F_46 ;
V_68 -> V_9 = V_9 ;
V_68 -> V_81 = V_81 ;
V_68 -> V_55 = V_55 ;
if ( V_3 > 512 ) {
F_58 ( V_9 , L_25 ,
V_68 -> V_37 , V_3 ) ;
V_3 = 512 ;
}
V_68 -> V_3 = V_3 ;
V_68 -> V_78 = F_2 ( V_68 -> V_3 , V_7 ) ;
if ( ! V_68 -> V_78 ) {
V_20 = - V_74 ;
goto V_117;
}
F_59 ( & V_68 -> V_5 , & V_9 -> V_118 ) ;
V_101 = F_2 ( sizeof( * V_101 ) , V_7 ) ;
if ( ! V_101 ) {
V_20 = - V_74 ;
goto V_119;
}
V_101 -> V_9 = V_9 ;
V_101 -> V_68 = V_68 ;
F_60 ( & V_101 -> V_99 , F_55 ) ;
F_61 ( & V_101 -> V_99 ) ;
return 0 ;
V_119:
F_10 ( V_68 -> V_78 ) ;
V_117:
F_10 ( V_68 -> V_37 ) ;
V_113:
F_10 ( V_68 ) ;
return V_20 ;
}
static int F_62 ( int V_76 , const T_6 * * V_120 , const T_6 * * V_121 )
{
int V_122 ;
switch ( V_76 ) {
case 1 :
V_122 = * * V_120 ;
break;
case 2 :
V_122 = F_63 ( * ( ( V_123 * ) * V_120 ) ) ;
break;
default:
return 0 ;
}
if ( V_121 )
* V_121 = * V_120 + V_76 ;
* V_120 += ( ( V_122 + V_76 ) + 3 ) & ~ 0x03 ;
return V_122 ;
}
static int F_64 ( int V_76 , const T_6 * * V_120 )
{
int V_124 = 0 ;
switch ( V_76 ) {
case 2 :
V_124 = F_63 ( * ( ( V_123 * ) * V_120 ) ) ;
break;
case 4 :
V_124 = F_65 ( * ( ( V_125 * ) * V_120 ) ) ;
break;
default:
break;
}
* V_120 += V_76 ;
return V_124 ;
}
static inline void F_66 ( struct V_8 * V_9 , const T_6 * * V_77 ,
struct V_126 * V_127 )
{
const struct V_128 * V_129 ;
switch ( V_9 -> V_107 ) {
case 0 :
case 1 :
V_129 = ( const struct V_128 * ) * V_77 ;
* V_77 = V_129 -> V_77 ;
V_127 -> V_130 = F_65 ( V_129 -> V_130 ) ;
V_127 -> V_37 = V_129 -> V_37 ;
V_127 -> V_131 = strlen ( V_129 -> V_37 ) ;
V_127 -> V_132 = F_65 ( V_129 -> V_132 ) ;
break;
default:
V_127 -> V_130 = F_64 ( sizeof( V_129 -> V_130 ) , V_77 ) ;
V_127 -> V_131 = F_62 ( sizeof( T_6 ) , V_77 ,
& V_127 -> V_37 ) ;
F_62 ( sizeof( T_5 ) , V_77 , NULL ) ;
V_127 -> V_132 = F_64 ( sizeof( V_129 -> V_132 ) , V_77 ) ;
break;
}
F_40 ( V_9 , L_26 , V_127 -> V_130 ) ;
F_40 ( V_9 , L_27 , V_127 -> V_131 , V_127 -> V_37 ) ;
F_40 ( V_9 , L_28 , V_127 -> V_132 ) ;
}
static inline void F_67 ( struct V_8 * V_9 , const T_6 * * V_77 ,
struct V_133 * V_127 )
{
const struct V_134 * V_129 ;
const T_6 * V_11 ;
int V_122 ;
switch ( V_9 -> V_107 ) {
case 0 :
case 1 :
V_129 = ( const struct V_134 * ) * V_77 ;
* V_77 = * V_77 + sizeof( V_129 -> V_135 ) + F_65 ( V_129 -> V_135 . V_136 ) ;
V_127 -> V_55 = F_63 ( V_129 -> V_135 . V_55 ) ;
V_127 -> V_137 = F_63 ( V_129 -> V_135 . type ) ;
V_127 -> V_37 = V_129 -> V_37 ;
V_127 -> V_131 = strlen ( V_129 -> V_37 ) ;
V_127 -> V_138 = F_63 ( V_129 -> V_138 ) ;
V_127 -> V_81 = F_63 ( V_129 -> V_81 ) ;
V_127 -> V_3 = F_65 ( V_129 -> V_3 ) ;
break;
default:
V_11 = * V_77 ;
V_127 -> V_55 = F_64 ( sizeof( V_129 -> V_135 . V_55 ) , & V_11 ) ;
V_127 -> V_137 = F_64 ( sizeof( V_129 -> V_135 . type ) , & V_11 ) ;
V_122 = F_64 ( sizeof( V_129 -> V_135 . V_136 ) , & V_11 ) ;
V_127 -> V_131 = F_62 ( sizeof( T_6 ) , & V_11 ,
& V_127 -> V_37 ) ;
F_62 ( sizeof( T_6 ) , & V_11 , NULL ) ;
F_62 ( sizeof( T_5 ) , & V_11 , NULL ) ;
V_127 -> V_138 = F_64 ( sizeof( V_129 -> V_138 ) , & V_11 ) ;
V_127 -> V_81 = F_64 ( sizeof( V_129 -> V_81 ) , & V_11 ) ;
V_127 -> V_3 = F_64 ( sizeof( V_129 -> V_3 ) , & V_11 ) ;
* V_77 = * V_77 + sizeof( V_129 -> V_135 ) + V_122 ;
break;
}
F_40 ( V_9 , L_29 , V_127 -> V_137 ) ;
F_40 ( V_9 , L_30 , V_127 -> V_55 ) ;
F_40 ( V_9 , L_31 , V_127 -> V_131 , V_127 -> V_37 ) ;
F_40 ( V_9 , L_32 , V_127 -> V_81 ) ;
F_40 ( V_9 , L_33 , V_127 -> V_138 ) ;
F_40 ( V_9 , L_34 , V_127 -> V_3 ) ;
}
static int F_68 ( struct V_8 * V_9 ,
const struct V_139 * V_140 )
{
struct V_70 V_71 = {} ;
struct V_126 V_141 ;
struct V_133 V_142 ;
const T_6 * V_77 = V_140 -> V_77 ;
int V_27 , V_20 ;
F_66 ( V_9 , & V_77 , & V_141 ) ;
for ( V_27 = 0 ; V_27 < V_141 . V_132 ; V_27 ++ ) {
F_67 ( V_9 , & V_77 , & V_142 ) ;
switch ( V_142 . V_138 ) {
case V_69 :
break;
default:
F_21 ( V_9 , L_35 ,
V_142 . V_138 ) ;
return - V_50 ;
}
V_71 . type = V_142 . V_137 ;
V_71 . V_108 = V_141 . V_130 ;
V_20 = F_57 ( V_9 , & V_71 ,
V_142 . V_55 ,
V_142 . V_3 ,
V_142 . V_37 ,
V_142 . V_131 ,
V_142 . V_81 ) ;
if ( V_20 < 0 )
F_21 ( V_9 , L_36 ,
V_142 . V_131 , V_142 . V_37 , V_20 ) ;
}
return 0 ;
}
static int F_69 ( struct V_8 * V_9 )
{
F_70 ( V_143 ) ;
const struct V_144 * V_144 ;
struct V_63 * V_63 = V_9 -> V_63 ;
unsigned int V_120 = 0 ;
const struct V_145 * V_146 ;
const struct V_147 * V_148 ;
const struct V_149 * V_150 ;
const struct V_151 * V_152 ;
const struct V_139 * V_140 ;
const struct V_52 * V_54 ;
const char * V_105 ;
char * V_15 , * V_153 ;
struct V_1 * V_6 ;
unsigned int V_72 ;
int V_154 = 0 ;
int V_20 , V_55 , type , V_155 ;
V_15 = F_2 ( V_31 , V_7 ) ;
if ( V_15 == NULL )
return - V_74 ;
snprintf ( V_15 , V_31 , L_37 , V_9 -> V_156 , V_9 -> V_32 ,
V_157 [ V_9 -> V_48 ] . V_15 ) ;
V_15 [ V_31 - 1 ] = '\0' ;
V_20 = F_71 ( & V_144 , V_15 , V_9 -> V_158 ) ;
if ( V_20 != 0 ) {
F_21 ( V_9 , L_38 , V_15 ) ;
goto V_159;
}
V_20 = - V_50 ;
V_120 = sizeof( * V_146 ) + sizeof( * V_148 ) + sizeof( * V_152 ) ;
if ( V_120 >= V_144 -> V_136 ) {
F_21 ( V_9 , L_39 ,
V_15 , V_144 -> V_136 ) ;
goto V_160;
}
V_146 = ( void * ) & V_144 -> V_77 [ 0 ] ;
if ( memcmp ( & V_146 -> V_161 [ 0 ] , L_40 , 4 ) != 0 ) {
F_21 ( V_9 , L_41 , V_15 ) ;
goto V_160;
}
switch ( V_146 -> V_162 ) {
case 0 :
F_58 ( V_9 , L_42 ,
V_15 , V_146 -> V_162 ) ;
break;
case 1 :
case 2 :
break;
default:
F_21 ( V_9 , L_43 ,
V_15 , V_146 -> V_162 ) ;
goto V_160;
}
F_72 ( V_9 , L_44 , V_146 -> V_162 ) ;
V_9 -> V_107 = V_146 -> V_162 ;
if ( V_146 -> V_163 != V_9 -> type ) {
F_21 ( V_9 , L_45 ,
V_15 , V_146 -> V_163 , V_9 -> type ) ;
goto V_160;
}
switch ( V_9 -> type ) {
case V_164 :
V_120 = sizeof( * V_146 ) + sizeof( * V_148 ) + sizeof( * V_152 ) ;
V_148 = ( void * ) & ( V_146 [ 1 ] ) ;
V_152 = ( void * ) & ( V_148 [ 1 ] ) ;
V_155 = sizeof( * V_148 ) ;
F_40 ( V_9 , L_46 ,
V_15 , F_65 ( V_148 -> V_165 ) ,
F_65 ( V_148 -> V_166 ) ,
F_65 ( V_148 -> V_167 ) ) ;
break;
case V_168 :
V_120 = sizeof( * V_146 ) + sizeof( * V_150 ) + sizeof( * V_152 ) ;
V_150 = ( void * ) & ( V_146 [ 1 ] ) ;
V_152 = ( void * ) & ( V_150 [ 1 ] ) ;
V_155 = sizeof( * V_150 ) ;
F_40 ( V_9 , L_47 ,
V_15 , F_65 ( V_150 -> V_169 ) ,
F_65 ( V_150 -> V_170 ) ,
F_65 ( V_150 -> V_166 ) ,
F_65 ( V_150 -> V_167 ) ) ;
break;
default:
F_37 ( 1 , L_48 ) ;
goto V_160;
}
if ( F_65 ( V_146 -> V_3 ) != sizeof( * V_146 ) +
V_155 + sizeof( * V_152 ) ) {
F_21 ( V_9 , L_49 ,
V_15 , F_65 ( V_146 -> V_3 ) ) ;
goto V_160;
}
F_40 ( V_9 , L_50 , V_15 ,
F_73 ( V_152 -> V_171 ) ) ;
while ( V_120 < V_144 -> V_136 &&
V_120 - V_144 -> V_136 > sizeof( * V_140 ) ) {
V_140 = ( void * ) & ( V_144 -> V_77 [ V_120 ] ) ;
V_105 = L_51 ;
V_72 = 0 ;
V_153 = NULL ;
V_55 = F_65 ( V_140 -> V_55 ) & 0xffffff ;
type = F_74 ( V_140 -> type ) & 0xff ;
V_54 = F_34 ( V_9 , type ) ;
switch ( type ) {
case V_172 :
V_105 = L_52 ;
V_153 = F_2 ( F_65 ( V_140 -> V_3 ) + 1 ,
V_7 ) ;
break;
case V_173 :
V_105 = L_53 ;
V_20 = F_68 ( V_9 , V_140 ) ;
if ( V_20 != 0 )
goto V_160;
break;
case V_174 :
V_105 = L_54 ;
V_153 = F_2 ( F_65 ( V_140 -> V_3 ) + 1 ,
V_7 ) ;
break;
case V_175 :
V_105 = L_55 ;
V_72 = V_55 ;
break;
case V_56 :
V_105 = L_16 ;
V_72 = F_35 ( V_54 , V_55 ) ;
break;
case V_58 :
V_105 = L_17 ;
V_72 = F_35 ( V_54 , V_55 ) ;
break;
case V_59 :
V_105 = L_18 ;
V_72 = F_35 ( V_54 , V_55 ) ;
break;
case V_60 :
V_105 = L_19 ;
V_72 = F_35 ( V_54 , V_55 ) ;
break;
case V_61 :
V_105 = L_20 ;
V_72 = F_35 ( V_54 , V_55 ) ;
break;
default:
F_58 ( V_9 ,
L_56 ,
V_15 , V_154 , type , V_120 , V_120 ) ;
break;
}
F_40 ( V_9 , L_57 , V_15 ,
V_154 , F_65 ( V_140 -> V_3 ) , V_55 ,
V_105 ) ;
if ( V_153 ) {
memcpy ( V_153 , V_140 -> V_77 , F_65 ( V_140 -> V_3 ) ) ;
F_72 ( V_9 , L_58 , V_15 , V_153 ) ;
F_10 ( V_153 ) ;
}
if ( V_72 ) {
V_6 = F_1 ( V_140 -> V_77 ,
F_65 ( V_140 -> V_3 ) ,
& V_143 ) ;
if ( ! V_6 ) {
F_21 ( V_9 , L_59 ) ;
V_20 = - V_74 ;
goto V_160;
}
V_20 = F_75 ( V_63 , V_72 , V_6 -> V_6 ,
F_65 ( V_140 -> V_3 ) ) ;
if ( V_20 != 0 ) {
F_21 ( V_9 ,
L_60 ,
V_15 , V_154 ,
F_65 ( V_140 -> V_3 ) , V_55 ,
V_105 , V_20 ) ;
goto V_160;
}
}
V_120 += F_65 ( V_140 -> V_3 ) + sizeof( * V_140 ) ;
V_154 ++ ;
}
V_20 = F_76 ( V_63 ) ;
if ( V_20 != 0 ) {
F_21 ( V_9 , L_61 , V_20 ) ;
goto V_160;
}
if ( V_120 > V_144 -> V_136 )
F_58 ( V_9 , L_62 ,
V_15 , V_154 , V_120 - V_144 -> V_136 ) ;
F_11 ( V_9 , V_15 ) ;
V_160:
F_76 ( V_63 ) ;
F_6 ( & V_143 ) ;
F_77 ( V_144 ) ;
V_159:
F_10 ( V_15 ) ;
return V_20 ;
}
static void F_78 ( struct V_8 * V_9 ,
const struct V_70 * V_71 )
{
struct V_67 * V_68 ;
F_53 (ctl, &dsp->ctl_list, list) {
if ( V_68 -> V_112 == V_109 [ V_9 -> V_48 ] &&
V_71 -> V_108 == V_68 -> V_71 . V_108 &&
V_71 -> type == V_68 -> V_71 . type ) {
V_68 -> V_71 . V_57 = V_71 -> V_57 ;
}
}
}
static void * F_79 ( struct V_8 * V_9 , T_1 V_176 ,
unsigned int V_120 , unsigned int V_3 )
{
void * V_108 ;
int V_20 ;
T_7 V_124 ;
if ( V_176 == 0 ) {
F_21 ( V_9 , L_63 ) ;
return F_80 ( - V_50 ) ;
}
if ( V_176 > 1024 ) {
F_21 ( V_9 , L_64 , V_176 ) ;
return F_80 ( - V_50 ) ;
}
V_20 = F_39 ( V_9 -> V_63 , V_120 + V_3 , & V_124 , sizeof( V_124 ) ) ;
if ( V_20 != 0 ) {
F_21 ( V_9 , L_65 ,
V_20 ) ;
return F_80 ( V_20 ) ;
}
if ( F_74 ( V_124 ) != 0xbedead )
F_58 ( V_9 , L_66 ,
V_120 + V_3 , F_74 ( V_124 ) ) ;
V_108 = F_2 ( V_3 * 2 , V_7 | V_73 ) ;
if ( ! V_108 )
return F_80 ( - V_74 ) ;
V_20 = F_39 ( V_9 -> V_63 , V_120 , V_108 , V_3 * 2 ) ;
if ( V_20 != 0 ) {
F_21 ( V_9 , L_67 ,
V_20 ) ;
F_10 ( V_108 ) ;
return F_80 ( V_20 ) ;
}
return V_108 ;
}
static struct V_70 * F_81 ( struct V_8 * V_9 ,
int type , T_7 V_130 ,
T_7 V_57 )
{
struct V_70 * V_71 ;
V_71 = F_2 ( sizeof( * V_71 ) , V_7 ) ;
if ( ! V_71 )
return F_80 ( - V_74 ) ;
V_71 -> type = type ;
V_71 -> V_108 = F_74 ( V_130 ) ;
V_71 -> V_57 = F_74 ( V_57 ) ;
F_5 ( & V_71 -> V_5 , & V_9 -> V_177 ) ;
if ( V_9 -> V_107 > 0 )
F_78 ( V_9 , V_71 ) ;
return V_71 ;
}
static int F_82 ( struct V_8 * V_9 )
{
struct V_178 V_179 ;
struct V_180 * V_181 ;
struct V_70 * V_71 ;
const struct V_52 * V_54 ;
unsigned int V_120 , V_3 ;
T_1 V_176 ;
int V_27 , V_20 ;
V_54 = F_34 ( V_9 , V_58 ) ;
if ( F_36 ( ! V_54 ) )
return - V_50 ;
V_20 = F_39 ( V_9 -> V_63 , V_54 -> V_57 , & V_179 ,
sizeof( V_179 ) ) ;
if ( V_20 != 0 ) {
F_21 ( V_9 , L_68 ,
V_20 ) ;
return V_20 ;
}
V_176 = F_74 ( V_179 . V_176 ) ;
V_9 -> V_34 = F_74 ( V_179 . V_48 . V_130 ) ;
F_72 ( V_9 , L_69 ,
V_9 -> V_34 ,
( F_74 ( V_179 . V_48 . V_162 ) & 0xff0000 ) >> 16 ,
( F_74 ( V_179 . V_48 . V_162 ) & 0xff00 ) >> 8 ,
F_74 ( V_179 . V_48 . V_162 ) & 0xff ,
V_176 ) ;
V_71 = F_81 ( V_9 , V_61 ,
V_179 . V_48 . V_130 , V_179 . V_167 ) ;
if ( F_83 ( V_71 ) )
return F_84 ( V_71 ) ;
V_71 = F_81 ( V_9 , V_58 ,
V_179 . V_48 . V_130 , V_179 . V_165 ) ;
if ( F_83 ( V_71 ) )
return F_84 ( V_71 ) ;
V_120 = sizeof( V_179 ) / 2 ;
V_3 = ( sizeof( * V_181 ) * V_176 ) / 2 ;
V_181 = F_79 ( V_9 , V_176 , V_54 -> V_57 + V_120 , V_3 ) ;
if ( F_83 ( V_181 ) )
return F_84 ( V_181 ) ;
for ( V_27 = 0 ; V_27 < V_176 ; V_27 ++ ) {
F_72 ( V_9 , L_70 ,
V_27 , F_74 ( V_181 [ V_27 ] . V_108 . V_130 ) ,
( F_74 ( V_181 [ V_27 ] . V_108 . V_162 ) & 0xff0000 ) >> 16 ,
( F_74 ( V_181 [ V_27 ] . V_108 . V_162 ) & 0xff00 ) >> 8 ,
F_74 ( V_181 [ V_27 ] . V_108 . V_162 ) & 0xff ,
F_74 ( V_181 [ V_27 ] . V_165 ) ,
F_74 ( V_181 [ V_27 ] . V_167 ) ) ;
V_71 = F_81 ( V_9 , V_58 ,
V_181 [ V_27 ] . V_108 . V_130 ,
V_181 [ V_27 ] . V_165 ) ;
if ( F_83 ( V_71 ) ) {
V_20 = F_84 ( V_71 ) ;
goto V_159;
}
if ( V_9 -> V_107 == 0 ) {
if ( V_27 + 1 < V_176 ) {
V_3 = F_74 ( V_181 [ V_27 + 1 ] . V_165 ) ;
V_3 -= F_74 ( V_181 [ V_27 ] . V_165 ) ;
V_3 *= 4 ;
F_57 ( V_9 , V_71 , 0 ,
V_3 , NULL , 0 , 0 ) ;
} else {
F_58 ( V_9 , L_71 ,
F_74 ( V_181 [ V_27 ] . V_108 . V_130 ) ) ;
}
}
V_71 = F_81 ( V_9 , V_61 ,
V_181 [ V_27 ] . V_108 . V_130 ,
V_181 [ V_27 ] . V_167 ) ;
if ( F_83 ( V_71 ) ) {
V_20 = F_84 ( V_71 ) ;
goto V_159;
}
if ( V_9 -> V_107 == 0 ) {
if ( V_27 + 1 < V_176 ) {
V_3 = F_74 ( V_181 [ V_27 + 1 ] . V_167 ) ;
V_3 -= F_74 ( V_181 [ V_27 ] . V_167 ) ;
V_3 *= 4 ;
F_57 ( V_9 , V_71 , 0 ,
V_3 , NULL , 0 , 0 ) ;
} else {
F_58 ( V_9 , L_72 ,
F_74 ( V_181 [ V_27 ] . V_108 . V_130 ) ) ;
}
}
}
V_159:
F_10 ( V_181 ) ;
return V_20 ;
}
static int F_85 ( struct V_8 * V_9 )
{
struct V_182 V_183 ;
struct V_184 * V_185 ;
struct V_70 * V_71 ;
const struct V_52 * V_54 ;
unsigned int V_120 , V_3 ;
T_1 V_176 ;
int V_27 , V_20 ;
V_54 = F_34 ( V_9 , V_59 ) ;
if ( F_36 ( ! V_54 ) )
return - V_50 ;
V_20 = F_39 ( V_9 -> V_63 , V_54 -> V_57 , & V_183 ,
sizeof( V_183 ) ) ;
if ( V_20 != 0 ) {
F_21 ( V_9 , L_68 ,
V_20 ) ;
return V_20 ;
}
V_176 = F_74 ( V_183 . V_176 ) ;
V_9 -> V_34 = F_74 ( V_183 . V_48 . V_130 ) ;
V_9 -> V_35 = F_74 ( V_183 . V_48 . V_162 ) ;
F_72 ( V_9 , L_69 ,
V_9 -> V_34 ,
( V_9 -> V_35 & 0xff0000 ) >> 16 ,
( V_9 -> V_35 & 0xff00 ) >> 8 ,
V_9 -> V_35 & 0xff ,
V_176 ) ;
V_71 = F_81 ( V_9 , V_59 ,
V_183 . V_48 . V_130 , V_183 . V_169 ) ;
if ( F_83 ( V_71 ) )
return F_84 ( V_71 ) ;
V_71 = F_81 ( V_9 , V_60 ,
V_183 . V_48 . V_130 , V_183 . V_170 ) ;
if ( F_83 ( V_71 ) )
return F_84 ( V_71 ) ;
V_71 = F_81 ( V_9 , V_186 ,
V_183 . V_48 . V_130 , V_183 . V_167 ) ;
if ( F_83 ( V_71 ) )
return F_84 ( V_71 ) ;
V_120 = sizeof( V_183 ) / 2 ;
V_3 = ( sizeof( * V_185 ) * V_176 ) / 2 ;
V_185 = F_79 ( V_9 , V_176 , V_54 -> V_57 + V_120 , V_3 ) ;
if ( F_83 ( V_185 ) )
return F_84 ( V_185 ) ;
for ( V_27 = 0 ; V_27 < V_176 ; V_27 ++ ) {
F_72 ( V_9 ,
L_73 ,
V_27 , F_74 ( V_185 [ V_27 ] . V_108 . V_130 ) ,
( F_74 ( V_185 [ V_27 ] . V_108 . V_162 ) & 0xff0000 ) >> 16 ,
( F_74 ( V_185 [ V_27 ] . V_108 . V_162 ) & 0xff00 ) >> 8 ,
F_74 ( V_185 [ V_27 ] . V_108 . V_162 ) & 0xff ,
F_74 ( V_185 [ V_27 ] . V_169 ) ,
F_74 ( V_185 [ V_27 ] . V_170 ) ,
F_74 ( V_185 [ V_27 ] . V_167 ) ) ;
V_71 = F_81 ( V_9 , V_59 ,
V_185 [ V_27 ] . V_108 . V_130 ,
V_185 [ V_27 ] . V_169 ) ;
if ( F_83 ( V_71 ) ) {
V_20 = F_84 ( V_71 ) ;
goto V_159;
}
if ( V_9 -> V_107 == 0 ) {
if ( V_27 + 1 < V_176 ) {
V_3 = F_74 ( V_185 [ V_27 + 1 ] . V_169 ) ;
V_3 -= F_74 ( V_185 [ V_27 ] . V_169 ) ;
V_3 *= 4 ;
F_57 ( V_9 , V_71 , 0 ,
V_3 , NULL , 0 , 0 ) ;
} else {
F_58 ( V_9 , L_74 ,
F_74 ( V_185 [ V_27 ] . V_108 . V_130 ) ) ;
}
}
V_71 = F_81 ( V_9 , V_60 ,
V_185 [ V_27 ] . V_108 . V_130 ,
V_185 [ V_27 ] . V_170 ) ;
if ( F_83 ( V_71 ) ) {
V_20 = F_84 ( V_71 ) ;
goto V_159;
}
if ( V_9 -> V_107 == 0 ) {
if ( V_27 + 1 < V_176 ) {
V_3 = F_74 ( V_185 [ V_27 + 1 ] . V_170 ) ;
V_3 -= F_74 ( V_185 [ V_27 ] . V_170 ) ;
V_3 *= 4 ;
F_57 ( V_9 , V_71 , 0 ,
V_3 , NULL , 0 , 0 ) ;
} else {
F_58 ( V_9 , L_75 ,
F_74 ( V_185 [ V_27 ] . V_108 . V_130 ) ) ;
}
}
V_71 = F_81 ( V_9 , V_186 ,
V_185 [ V_27 ] . V_108 . V_130 ,
V_185 [ V_27 ] . V_167 ) ;
if ( F_83 ( V_71 ) ) {
V_20 = F_84 ( V_71 ) ;
goto V_159;
}
if ( V_9 -> V_107 == 0 ) {
if ( V_27 + 1 < V_176 ) {
V_3 = F_74 ( V_185 [ V_27 + 1 ] . V_167 ) ;
V_3 -= F_74 ( V_185 [ V_27 ] . V_167 ) ;
V_3 *= 4 ;
F_57 ( V_9 , V_71 , 0 ,
V_3 , NULL , 0 , 0 ) ;
} else {
F_58 ( V_9 , L_72 ,
F_74 ( V_185 [ V_27 ] . V_108 . V_130 ) ) ;
}
}
}
V_159:
F_10 ( V_185 ) ;
return V_20 ;
}
static int F_86 ( struct V_8 * V_9 )
{
F_70 ( V_143 ) ;
struct V_63 * V_63 = V_9 -> V_63 ;
struct V_187 * V_135 ;
struct V_188 * V_127 ;
const struct V_144 * V_144 ;
const struct V_52 * V_54 ;
struct V_70 * V_71 ;
const char * V_105 ;
int V_20 , V_120 , V_189 , type , V_55 , V_72 ;
char * V_15 ;
struct V_1 * V_6 ;
V_15 = F_2 ( V_31 , V_7 ) ;
if ( V_15 == NULL )
return - V_74 ;
snprintf ( V_15 , V_31 , L_76 , V_9 -> V_156 , V_9 -> V_32 ,
V_157 [ V_9 -> V_48 ] . V_15 ) ;
V_15 [ V_31 - 1 ] = '\0' ;
V_20 = F_71 ( & V_144 , V_15 , V_9 -> V_158 ) ;
if ( V_20 != 0 ) {
F_58 ( V_9 , L_38 , V_15 ) ;
V_20 = 0 ;
goto V_159;
}
V_20 = - V_50 ;
if ( sizeof( * V_135 ) >= V_144 -> V_136 ) {
F_21 ( V_9 , L_39 ,
V_15 , V_144 -> V_136 ) ;
goto V_160;
}
V_135 = ( void * ) & V_144 -> V_77 [ 0 ] ;
if ( memcmp ( V_135 -> V_161 , L_77 , 4 ) != 0 ) {
F_21 ( V_9 , L_41 , V_15 ) ;
goto V_160;
}
switch ( F_74 ( V_135 -> V_190 ) & 0xff ) {
case 1 :
break;
default:
F_21 ( V_9 , L_78 ,
V_15 , F_74 ( V_135 -> V_190 ) & 0xff ) ;
V_20 = - V_50 ;
goto V_160;
}
F_40 ( V_9 , L_79 , V_15 ,
( F_65 ( V_135 -> V_162 ) >> 16 ) & 0xff ,
( F_65 ( V_135 -> V_162 ) >> 8 ) & 0xff ,
F_65 ( V_135 -> V_162 ) & 0xff ) ;
V_120 = F_65 ( V_135 -> V_3 ) ;
V_189 = 0 ;
while ( V_120 < V_144 -> V_136 &&
V_120 - V_144 -> V_136 > sizeof( * V_127 ) ) {
V_127 = ( void * ) ( & V_144 -> V_77 [ V_120 ] ) ;
type = F_63 ( V_127 -> type ) ;
V_55 = F_63 ( V_127 -> V_55 ) ;
F_40 ( V_9 , L_80 ,
V_15 , V_189 , F_65 ( V_127 -> V_130 ) ,
( F_65 ( V_127 -> V_162 ) >> 16 ) & 0xff ,
( F_65 ( V_127 -> V_162 ) >> 8 ) & 0xff ,
F_65 ( V_127 -> V_162 ) & 0xff ) ;
F_40 ( V_9 , L_81 ,
V_15 , V_189 , F_65 ( V_127 -> V_3 ) , V_55 , type ) ;
V_72 = 0 ;
V_105 = L_51 ;
switch ( type ) {
case ( V_172 << 8 ) :
case ( V_174 << 8 ) :
break;
case ( V_175 << 8 ) :
if ( F_65 ( V_127 -> V_130 ) == V_9 -> V_34 &&
V_55 == 0 ) {
V_105 = L_82 ;
V_54 = F_34 ( V_9 , type ) ;
if ( ! V_54 ) {
F_21 ( V_9 , L_83 ) ;
break;
}
V_72 = F_35 ( V_54 , 0 ) ;
} else {
V_105 = L_84 ;
V_72 = V_55 ;
}
break;
case V_58 :
case V_61 :
case V_59 :
case V_60 :
F_40 ( V_9 , L_85 ,
V_15 , V_189 , F_65 ( V_127 -> V_3 ) ,
type , F_65 ( V_127 -> V_130 ) ) ;
V_54 = F_34 ( V_9 , type ) ;
if ( ! V_54 ) {
F_21 ( V_9 , L_11 , type ) ;
break;
}
V_72 = 0 ;
F_53 (alg_region,
&dsp->alg_regions, list) {
if ( F_65 ( V_127 -> V_130 ) == V_71 -> V_108 &&
type == V_71 -> type ) {
V_72 = V_71 -> V_57 ;
V_72 = F_35 ( V_54 ,
V_72 ) ;
V_72 += V_55 ;
break;
}
}
if ( V_72 == 0 )
F_21 ( V_9 , L_86 ,
type , F_65 ( V_127 -> V_130 ) ) ;
break;
default:
F_21 ( V_9 , L_87 ,
V_15 , V_189 , type , V_120 ) ;
break;
}
if ( V_72 ) {
V_6 = F_1 ( V_127 -> V_77 ,
F_65 ( V_127 -> V_3 ) ,
& V_143 ) ;
if ( ! V_6 ) {
F_21 ( V_9 , L_59 ) ;
V_20 = - V_74 ;
goto V_160;
}
F_40 ( V_9 , L_88 ,
V_15 , V_189 , F_65 ( V_127 -> V_3 ) ,
V_72 ) ;
V_20 = F_75 ( V_63 , V_72 , V_6 -> V_6 ,
F_65 ( V_127 -> V_3 ) ) ;
if ( V_20 != 0 ) {
F_21 ( V_9 ,
L_89 ,
V_15 , V_189 , V_72 , V_105 , V_20 ) ;
}
}
V_120 += ( F_65 ( V_127 -> V_3 ) + sizeof( * V_127 ) + 3 ) & ~ 0x03 ;
V_189 ++ ;
}
V_20 = F_76 ( V_63 ) ;
if ( V_20 != 0 )
F_21 ( V_9 , L_61 , V_20 ) ;
if ( V_120 > V_144 -> V_136 )
F_58 ( V_9 , L_62 ,
V_15 , V_189 , V_120 - V_144 -> V_136 ) ;
F_15 ( V_9 , V_15 ) ;
V_160:
F_76 ( V_63 ) ;
F_77 ( V_144 ) ;
F_6 ( & V_143 ) ;
V_159:
F_10 ( V_15 ) ;
return V_20 ;
}
int F_87 ( struct V_8 * V_9 )
{
F_88 ( & V_9 -> V_177 ) ;
#ifdef F_89
F_90 ( & V_9 -> V_12 ) ;
#endif
return 0 ;
}
int F_91 ( struct V_191 * V_192 ,
struct V_39 * V_40 ,
int V_193 )
{
struct V_22 * V_23 = F_92 ( V_192 -> V_194 ) ;
struct V_8 * V_195 = F_32 ( V_23 ) ;
struct V_8 * V_9 = & V_195 [ V_192 -> V_196 ] ;
struct V_70 * V_71 ;
struct V_67 * V_68 ;
int V_20 ;
int V_124 ;
V_9 -> V_96 = V_23 -> V_28 . V_96 ;
switch ( V_193 ) {
case V_197 :
F_93 ( V_9 -> V_63 , V_9 -> V_57 + V_198 ,
V_199 , V_199 ) ;
if( V_9 -> V_200 ) {
V_20 = F_94 ( V_9 -> V_63 , V_9 -> V_200 , & V_124 ) ;
if ( V_20 != 0 ) {
F_21 ( V_9 , L_90 ,
V_20 ) ;
return V_20 ;
}
V_124 = ( V_124 & V_9 -> V_201 )
>> V_9 -> V_202 ;
V_20 = F_93 ( V_9 -> V_63 ,
V_9 -> V_57 + V_203 ,
V_204 , V_124 ) ;
if ( V_20 != 0 ) {
F_21 ( V_9 , L_91 ,
V_20 ) ;
return V_20 ;
}
}
V_20 = F_69 ( V_9 ) ;
if ( V_20 != 0 )
goto V_30;
V_20 = F_82 ( V_9 ) ;
if ( V_20 != 0 )
goto V_30;
V_20 = F_86 ( V_9 ) ;
if ( V_20 != 0 )
goto V_30;
V_20 = F_52 ( V_9 ) ;
if ( V_20 != 0 )
goto V_30;
V_20 = F_54 ( V_9 ) ;
if ( V_20 != 0 )
goto V_30;
F_93 ( V_9 -> V_63 , V_9 -> V_57 + V_198 ,
V_205 | V_206 ,
V_205 | V_206 ) ;
break;
case V_207 :
F_93 ( V_9 -> V_63 , V_9 -> V_57 + V_198 ,
V_205 | V_206 , 0 ) ;
F_93 ( V_9 -> V_63 , V_9 -> V_57 + V_208 ,
V_209 , 0 ) ;
F_93 ( V_9 -> V_63 , V_9 -> V_57 + V_198 ,
V_199 , 0 ) ;
F_53 (ctl, &dsp->ctl_list, list)
V_68 -> V_80 = 0 ;
while ( ! F_7 ( & V_9 -> V_177 ) ) {
V_71 = F_8 ( & V_9 -> V_177 ,
struct V_70 ,
V_5 ) ;
F_9 ( & V_71 -> V_5 ) ;
F_10 ( V_71 ) ;
}
break;
default:
break;
}
return 0 ;
V_30:
F_93 ( V_9 -> V_63 , V_9 -> V_57 + V_198 ,
V_199 , 0 ) ;
return V_20 ;
}
static int F_95 ( struct V_8 * V_9 )
{
unsigned int V_124 ;
int V_20 , V_17 ;
V_20 = F_96 ( V_9 -> V_63 , V_9 -> V_57 + V_210 ,
V_211 , V_211 ) ;
if ( V_20 != 0 )
return V_20 ;
for ( V_17 = 0 ; V_17 < 10 ; ++ V_17 ) {
V_20 = F_94 ( V_9 -> V_63 , V_9 -> V_57 + V_212 ,
& V_124 ) ;
if ( V_20 != 0 )
return V_20 ;
if ( V_124 & V_213 )
break;
F_97 ( 1 ) ;
}
if ( ! ( V_124 & V_213 ) ) {
F_21 ( V_9 , L_92 ) ;
return - V_51 ;
}
F_40 ( V_9 , L_93 , V_17 ) ;
return 0 ;
}
static void F_98 ( struct V_98 * V_99 )
{
struct V_8 * V_9 = F_56 ( V_99 ,
struct V_8 ,
V_214 ) ;
int V_20 ;
unsigned int V_124 ;
V_20 = F_94 ( V_9 -> V_63 , V_215 , & V_124 ) ;
if ( V_20 != 0 ) {
F_21 ( V_9 , L_90 , V_20 ) ;
return;
}
V_124 = ( V_124 & V_216 )
>> V_217 ;
V_20 = F_96 ( V_9 -> V_63 ,
V_9 -> V_57 + V_218 ,
V_219 , V_124 ) ;
if ( V_20 != 0 ) {
F_21 ( V_9 , L_91 , V_20 ) ;
return;
}
V_20 = F_95 ( V_9 ) ;
if ( V_20 != 0 )
return;
V_20 = F_69 ( V_9 ) ;
if ( V_20 != 0 )
goto V_30;
V_20 = F_85 ( V_9 ) ;
if ( V_20 != 0 )
goto V_30;
V_20 = F_86 ( V_9 ) ;
if ( V_20 != 0 )
goto V_30;
V_20 = F_52 ( V_9 ) ;
if ( V_20 != 0 )
goto V_30;
V_20 = F_54 ( V_9 ) ;
if ( V_20 != 0 )
goto V_30;
V_9 -> V_21 = true ;
return;
V_30:
F_93 ( V_9 -> V_63 , V_9 -> V_57 + V_210 ,
V_211 | V_220 | V_221 , 0 ) ;
}
int F_99 ( struct V_191 * V_192 ,
struct V_39 * V_40 , int V_193 )
{
struct V_22 * V_23 = F_92 ( V_192 -> V_194 ) ;
struct V_8 * V_195 = F_32 ( V_23 ) ;
struct V_8 * V_9 = & V_195 [ V_192 -> V_196 ] ;
V_9 -> V_96 = V_23 -> V_28 . V_96 ;
switch ( V_193 ) {
case V_222 :
F_100 ( V_223 , & V_9 -> V_214 ) ;
break;
default:
break;
}
return 0 ;
}
int F_101 ( struct V_191 * V_192 ,
struct V_39 * V_40 , int V_193 )
{
struct V_22 * V_23 = F_92 ( V_192 -> V_194 ) ;
struct V_8 * V_195 = F_32 ( V_23 ) ;
struct V_8 * V_9 = & V_195 [ V_192 -> V_196 ] ;
struct V_70 * V_71 ;
struct V_67 * V_68 ;
int V_20 ;
switch ( V_193 ) {
case V_197 :
F_102 ( & V_9 -> V_214 ) ;
if ( ! V_9 -> V_21 )
return - V_224 ;
V_20 = F_93 ( V_9 -> V_63 ,
V_9 -> V_57 + V_210 ,
V_220 | V_221 ,
V_220 | V_221 ) ;
if ( V_20 != 0 )
goto V_30;
break;
case V_207 :
F_38 ( V_9 ) ;
F_16 ( V_9 ) ;
V_9 -> V_34 = 0 ;
V_9 -> V_35 = 0 ;
V_9 -> V_21 = false ;
F_93 ( V_9 -> V_63 , V_9 -> V_57 + V_210 ,
V_211 | V_220 |
V_221 , 0 ) ;
F_103 ( V_9 -> V_63 , V_9 -> V_57 + V_225 , 0 ) ;
F_103 ( V_9 -> V_63 , V_9 -> V_57 + V_226 , 0 ) ;
F_103 ( V_9 -> V_63 , V_9 -> V_57 + V_227 , 0 ) ;
F_53 (ctl, &dsp->ctl_list, list)
V_68 -> V_80 = 0 ;
while ( ! F_7 ( & V_9 -> V_177 ) ) {
V_71 = F_8 ( & V_9 -> V_177 ,
struct V_70 ,
V_5 ) ;
F_9 ( & V_71 -> V_5 ) ;
F_10 ( V_71 ) ;
}
F_40 ( V_9 , L_94 ) ;
break;
default:
break;
}
return 0 ;
V_30:
F_93 ( V_9 -> V_63 , V_9 -> V_57 + V_210 ,
V_211 | V_220 | V_221 , 0 ) ;
return V_20 ;
}
int F_104 ( struct V_8 * V_9 , struct V_22 * V_23 )
{
F_20 ( V_9 , V_23 ) ;
return F_105 ( V_23 ,
& V_228 [ V_9 -> V_32 - 1 ] ,
1 ) ;
}
int F_106 ( struct V_8 * V_9 , struct V_22 * V_23 )
{
F_29 ( V_9 ) ;
return 0 ;
}
int F_107 ( struct V_8 * V_9 )
{
int V_20 ;
V_20 = F_93 ( V_9 -> V_63 , V_9 -> V_57 + V_210 ,
V_229 , 0 ) ;
if ( V_20 != 0 ) {
F_21 ( V_9 , L_95 , V_20 ) ;
return V_20 ;
}
F_88 ( & V_9 -> V_177 ) ;
F_88 ( & V_9 -> V_118 ) ;
F_60 ( & V_9 -> V_214 , F_98 ) ;
#ifdef F_89
F_90 ( & V_9 -> V_12 ) ;
#endif
return 0 ;
}
