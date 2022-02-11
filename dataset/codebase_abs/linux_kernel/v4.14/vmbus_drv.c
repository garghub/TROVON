static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
void * args )
{
struct V_4 * V_5 ;
V_5 = F_2 () ;
F_3 ( V_5 ) ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned long V_3 ,
void * args )
{
struct V_7 * V_8 = (struct V_7 * ) args ;
struct V_4 * V_5 = V_8 -> V_5 ;
F_3 ( V_5 ) ;
return V_6 ;
}
static int F_5 ( void )
{
if ( V_9 == NULL )
return - V_10 ;
return 0 ;
}
static void F_6 ( struct V_11 * V_12 , char * V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 += 2 )
sprintf ( & V_13 [ V_14 ] , L_1 , V_12 -> V_16 . V_17 [ V_14 / 2 ] ) ;
}
static T_1 F_7 ( struct V_18 * V_19 )
{
return ( T_1 ) V_19 -> V_20 . V_21 / 32 ;
}
static T_1 F_8 ( struct V_18 * V_19 )
{
return ( T_1 ) V_19 -> V_20 . V_21 % 32 ;
}
static T_2 F_9 ( struct V_18 * V_19 ,
struct V_22 * V_23 )
{
T_1 V_24 = F_7 ( V_19 ) ;
return V_23 -> V_25 [ V_24 ] . V_26 ;
}
static T_2 F_10 ( struct V_18 * V_19 ,
struct V_22 * V_23 )
{
T_1 V_24 = F_7 ( V_19 ) ;
T_1 V_27 = F_8 ( V_19 ) ;
return V_23 -> V_28 [ V_24 ] [ V_27 ] ;
}
static T_2 F_11 ( struct V_18 * V_19 ,
struct V_22 * V_23 )
{
T_1 V_24 = F_7 ( V_19 ) ;
T_1 V_27 = F_8 ( V_19 ) ;
return V_23 -> V_29 [ V_24 ] [ V_27 ] . V_30 . V_31 . V_32 ;
}
static T_3 F_12 ( struct V_33 * V_34 , struct V_35 * V_36 ,
char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
if ( ! V_12 -> V_19 )
return - V_10 ;
return sprintf ( V_37 , L_2 , V_12 -> V_19 -> V_20 . V_38 ) ;
}
static T_3 F_14 ( struct V_33 * V_34 , struct V_35 * V_36 ,
char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
if ( ! V_12 -> V_19 )
return - V_10 ;
return sprintf ( V_37 , L_2 , V_12 -> V_19 -> V_39 ) ;
}
static T_3 F_15 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
if ( ! V_12 -> V_19 )
return - V_10 ;
return sprintf ( V_37 , L_2 , V_12 -> V_19 -> V_20 . V_21 ) ;
}
static T_3 F_16 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
if ( ! V_12 -> V_19 )
return - V_10 ;
return sprintf ( V_37 , L_3 ,
V_12 -> V_19 -> V_20 . V_40 . V_41 . V_17 ) ;
}
static T_3 F_17 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
if ( ! V_12 -> V_19 )
return - V_10 ;
return sprintf ( V_37 , L_3 ,
V_12 -> V_19 -> V_20 . V_40 . V_42 . V_17 ) ;
}
static T_3 F_18 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
char V_13 [ V_15 + 1 ] ;
F_6 ( V_12 , V_13 ) ;
return sprintf ( V_37 , L_4 , V_13 ) ;
}
static T_3 F_19 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
if ( ! V_12 -> V_19 )
return - V_10 ;
return sprintf ( V_37 , L_2 ,
F_9 ( V_12 -> V_19 ,
V_43 . V_44 [ 1 ] ) ) ;
}
static T_3 F_20 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
if ( ! V_12 -> V_19 )
return - V_10 ;
return sprintf ( V_37 , L_2 ,
F_9 ( V_12 -> V_19 ,
V_43 . V_44 [ 1 ] ) ) ;
}
static T_3 F_21 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
if ( ! V_12 -> V_19 )
return - V_10 ;
return sprintf ( V_37 , L_2 ,
F_10 ( V_12 -> V_19 ,
V_43 . V_44 [ 0 ] ) ) ;
}
static T_3 F_22 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
if ( ! V_12 -> V_19 )
return - V_10 ;
return sprintf ( V_37 , L_2 ,
F_10 ( V_12 -> V_19 ,
V_43 . V_44 [ 1 ] ) ) ;
}
static T_3 F_23 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
if ( ! V_12 -> V_19 )
return - V_10 ;
return sprintf ( V_37 , L_2 ,
F_11 ( V_12 -> V_19 ,
V_43 . V_44 [ 0 ] ) ) ;
}
static T_3 F_24 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
if ( ! V_12 -> V_19 )
return - V_10 ;
return sprintf ( V_37 , L_2 ,
F_11 ( V_12 -> V_19 ,
V_43 . V_44 [ 1 ] ) ) ;
}
static T_3 F_25 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
struct V_45 V_46 ;
if ( ! V_12 -> V_19 )
return - V_10 ;
F_26 ( & V_12 -> V_19 -> V_46 , & V_46 ) ;
return sprintf ( V_37 , L_2 , V_46 . V_47 ) ;
}
static T_3 F_27 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
struct V_45 V_46 ;
if ( ! V_12 -> V_19 )
return - V_10 ;
F_26 ( & V_12 -> V_19 -> V_46 , & V_46 ) ;
return sprintf ( V_37 , L_2 , V_46 . V_48 ) ;
}
static T_3 F_28 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
struct V_45 V_46 ;
if ( ! V_12 -> V_19 )
return - V_10 ;
F_26 ( & V_12 -> V_19 -> V_46 , & V_46 ) ;
return sprintf ( V_37 , L_2 , V_46 . V_49 ) ;
}
static T_3 F_29 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
struct V_45 V_46 ;
if ( ! V_12 -> V_19 )
return - V_10 ;
F_26 ( & V_12 -> V_19 -> V_46 , & V_46 ) ;
return sprintf ( V_37 , L_2 , V_46 . V_50 ) ;
}
static T_3 F_30 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
struct V_45 V_46 ;
if ( ! V_12 -> V_19 )
return - V_10 ;
F_26 ( & V_12 -> V_19 -> V_46 , & V_46 ) ;
return sprintf ( V_37 , L_2 , V_46 . V_51 ) ;
}
static T_3 F_31 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
struct V_45 V_52 ;
if ( ! V_12 -> V_19 )
return - V_10 ;
F_26 ( & V_12 -> V_19 -> V_52 , & V_52 ) ;
return sprintf ( V_37 , L_2 , V_52 . V_47 ) ;
}
static T_3 F_32 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
struct V_45 V_52 ;
if ( ! V_12 -> V_19 )
return - V_10 ;
F_26 ( & V_12 -> V_19 -> V_52 , & V_52 ) ;
return sprintf ( V_37 , L_2 , V_52 . V_48 ) ;
}
static T_3 F_33 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
struct V_45 V_52 ;
if ( ! V_12 -> V_19 )
return - V_10 ;
F_26 ( & V_12 -> V_19 -> V_52 , & V_52 ) ;
return sprintf ( V_37 , L_2 , V_52 . V_49 ) ;
}
static T_3 F_34 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
struct V_45 V_52 ;
if ( ! V_12 -> V_19 )
return - V_10 ;
F_26 ( & V_12 -> V_19 -> V_52 , & V_52 ) ;
return sprintf ( V_37 , L_2 , V_52 . V_50 ) ;
}
static T_3 F_35 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
struct V_45 V_52 ;
if ( ! V_12 -> V_19 )
return - V_10 ;
F_26 ( & V_12 -> V_19 -> V_52 , & V_52 ) ;
return sprintf ( V_37 , L_2 , V_52 . V_51 ) ;
}
static T_3 F_36 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
struct V_18 * V_19 = V_12 -> V_19 , * V_53 ;
unsigned long V_54 ;
int V_55 = V_56 , V_57 , V_58 ;
struct V_59 * V_60 ;
if ( ! V_19 )
return - V_10 ;
V_58 = snprintf ( V_37 , V_55 , L_5 ,
V_19 -> V_20 . V_38 , V_19 -> V_61 ) ;
F_37 ( & V_19 -> V_62 , V_54 ) ;
F_38 (cur, &channel->sc_list) {
if ( V_58 >= V_55 - 1 )
break;
V_53 = F_39 ( V_60 , struct V_18 , V_63 ) ;
V_57 = F_40 ( V_37 + V_58 ,
V_55 - V_58 ,
L_5 ,
V_53 -> V_20 . V_38 ,
V_53 -> V_61 ) ;
V_58 += V_57 ;
}
F_41 ( & V_19 -> V_62 , V_54 ) ;
return V_58 ;
}
static T_3 F_42 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
return sprintf ( V_37 , L_6 , V_12 -> V_64 ) ;
}
static T_3 F_43 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_11 * V_12 = F_13 ( V_34 ) ;
return sprintf ( V_37 , L_6 , V_12 -> V_65 ) ;
}
static int F_44 ( struct V_33 * V_33 , struct V_66 * V_67 )
{
struct V_11 * V_34 = F_13 ( V_33 ) ;
int V_68 ;
char V_13 [ V_15 + 1 ] ;
F_6 ( V_34 , V_13 ) ;
V_68 = F_45 ( V_67 , L_7 , V_13 ) ;
return V_68 ;
}
static inline bool F_46 ( const T_4 * V_69 )
{
if ( F_47 ( * V_69 , V_70 ) )
return false ;
return true ;
}
static const struct V_71 * F_48 ( struct V_72 * V_73 ,
const T_4 * V_69 )
{
const struct V_71 * V_32 = NULL ;
struct V_74 * V_75 ;
F_49 ( & V_73 -> V_76 . V_62 ) ;
F_50 (dynid, &drv->dynids.list, node) {
if ( ! F_47 ( V_75 -> V_32 . V_69 , * V_69 ) ) {
V_32 = & V_75 -> V_32 ;
break;
}
}
F_51 ( & V_73 -> V_76 . V_62 ) ;
if ( V_32 )
return V_32 ;
V_32 = V_73 -> V_77 ;
if ( V_32 == NULL )
return NULL ;
for (; ! F_46 ( & V_32 -> V_69 ) ; V_32 ++ )
if ( ! F_47 ( V_32 -> V_69 , * V_69 ) )
return V_32 ;
return NULL ;
}
static int F_52 ( struct V_72 * V_73 , T_4 * V_69 )
{
struct V_74 * V_75 ;
V_75 = F_53 ( sizeof( * V_75 ) , V_78 ) ;
if ( ! V_75 )
return - V_79 ;
V_75 -> V_32 . V_69 = * V_69 ;
F_49 ( & V_73 -> V_76 . V_62 ) ;
F_54 ( & V_75 -> V_80 , & V_73 -> V_76 . V_81 ) ;
F_51 ( & V_73 -> V_76 . V_62 ) ;
return F_55 ( & V_73 -> V_82 ) ;
}
static void F_56 ( struct V_72 * V_73 )
{
struct V_74 * V_75 , * V_83 ;
F_49 ( & V_73 -> V_76 . V_62 ) ;
F_57 (dynid, n, &drv->dynids.list, node) {
F_58 ( & V_75 -> V_80 ) ;
F_59 ( V_75 ) ;
}
F_51 ( & V_73 -> V_76 . V_62 ) ;
}
static T_3 F_60 ( struct V_84 * V_82 , const char * V_37 ,
T_5 V_85 )
{
struct V_72 * V_73 = F_61 ( V_82 ) ;
T_4 V_69 ;
T_3 V_86 ;
V_86 = F_62 ( V_37 , & V_69 ) ;
if ( V_86 )
return V_86 ;
if ( F_48 ( V_73 , & V_69 ) )
return - V_87 ;
V_86 = F_52 ( V_73 , & V_69 ) ;
if ( V_86 )
return V_86 ;
return V_85 ;
}
static T_3 F_63 ( struct V_84 * V_82 , const char * V_37 ,
T_5 V_85 )
{
struct V_72 * V_73 = F_61 ( V_82 ) ;
struct V_74 * V_75 , * V_83 ;
T_4 V_69 ;
T_3 V_86 ;
V_86 = F_62 ( V_37 , & V_69 ) ;
if ( V_86 )
return V_86 ;
V_86 = - V_10 ;
F_49 ( & V_73 -> V_76 . V_62 ) ;
F_57 (dynid, n, &drv->dynids.list, node) {
struct V_71 * V_32 = & V_75 -> V_32 ;
if ( ! F_47 ( V_32 -> V_69 , V_69 ) ) {
F_58 ( & V_75 -> V_80 ) ;
F_59 ( V_75 ) ;
V_86 = V_85 ;
break;
}
}
F_51 ( & V_73 -> V_76 . V_62 ) ;
return V_86 ;
}
static int F_64 ( struct V_33 * V_33 , struct V_84 * V_82 )
{
struct V_72 * V_73 = F_61 ( V_82 ) ;
struct V_11 * V_12 = F_13 ( V_33 ) ;
if ( F_65 ( V_12 -> V_19 ) )
return V_73 -> V_88 ;
if ( F_48 ( V_73 , & V_12 -> V_16 ) )
return 1 ;
return 0 ;
}
static int F_66 ( struct V_33 * V_89 )
{
int V_68 = 0 ;
struct V_72 * V_73 =
F_61 ( V_89 -> V_82 ) ;
struct V_11 * V_34 = F_13 ( V_89 ) ;
const struct V_71 * V_90 ;
V_90 = F_48 ( V_73 , & V_34 -> V_16 ) ;
if ( V_73 -> V_91 ) {
V_68 = V_73 -> V_91 ( V_34 , V_90 ) ;
if ( V_68 != 0 )
F_67 ( L_8 ,
F_68 ( V_89 ) , V_68 ) ;
} else {
F_67 ( L_9 ,
F_68 ( V_89 ) ) ;
V_68 = - V_10 ;
}
return V_68 ;
}
static int F_69 ( struct V_33 * V_89 )
{
struct V_72 * V_73 ;
struct V_11 * V_34 = F_13 ( V_89 ) ;
if ( V_89 -> V_82 ) {
V_73 = F_61 ( V_89 -> V_82 ) ;
if ( V_73 -> remove )
V_73 -> remove ( V_34 ) ;
}
return 0 ;
}
static void F_70 ( struct V_33 * V_89 )
{
struct V_72 * V_73 ;
struct V_11 * V_34 = F_13 ( V_89 ) ;
if ( ! V_89 -> V_82 )
return;
V_73 = F_61 ( V_89 -> V_82 ) ;
if ( V_73 -> V_92 )
V_73 -> V_92 ( V_34 ) ;
}
static void F_71 ( struct V_33 * V_33 )
{
struct V_11 * V_12 = F_13 ( V_33 ) ;
struct V_18 * V_19 = V_12 -> V_19 ;
F_72 ( & V_43 . V_93 ) ;
F_73 ( V_19 -> V_20 . V_38 ) ;
F_74 ( & V_43 . V_93 ) ;
F_59 ( V_12 ) ;
}
static void F_75 ( struct V_94 * V_95 )
{
struct V_96 * V_97 ;
if ( V_43 . V_98 == V_99 )
return;
V_97 = F_76 ( V_95 , struct V_96 ,
V_95 ) ;
F_77 ( & V_97 -> V_100 ) ;
F_59 ( V_97 ) ;
}
static void F_78 ( struct V_101 * V_100 ,
struct V_102 * V_103 )
{
struct V_104 * V_34 = V_103 -> V_105 ;
if ( V_34 -> V_106 )
V_34 -> V_106 ( V_34 ) ;
F_79 ( V_100 , V_107 ) ;
}
void F_80 ( unsigned long V_108 )
{
struct V_102 * V_103 = ( void * ) V_108 ;
void * V_109 = V_103 -> V_110 ;
struct V_101 * V_100 = (struct V_101 * ) V_109 +
V_111 ;
struct V_112 * V_113 ;
const struct V_114 * V_115 ;
struct V_96 * V_97 ;
T_2 V_116 = V_100 -> V_117 . V_116 ;
if ( V_116 == V_118 )
return;
V_113 = (struct V_112 * ) V_100 -> V_31 . V_119 ;
if ( V_113 -> V_120 >= V_121 ) {
F_81 ( 1 , L_10 , V_113 -> V_120 ) ;
goto V_122;
}
V_115 = & V_123 [ V_113 -> V_120 ] ;
if ( V_115 -> V_124 == V_125 ) {
V_97 = F_82 ( sizeof( * V_97 ) , V_126 ) ;
if ( V_97 == NULL )
return;
F_83 ( & V_97 -> V_95 , F_75 ) ;
memcpy ( & V_97 -> V_100 , V_100 , sizeof( * V_100 ) ) ;
switch ( V_113 -> V_120 ) {
case V_127 :
F_84 ( V_43 . V_128 ,
& V_97 -> V_95 ) ;
break;
case V_129 :
F_85 ( & V_43 . V_130 ) ;
F_86 ( V_43 . V_128 ,
V_43 . V_131 ,
& V_97 -> V_95 ) ;
break;
default:
F_87 ( V_43 . V_131 , & V_97 -> V_95 ) ;
}
} else
V_115 -> V_132 ( V_113 ) ;
V_122:
F_79 ( V_100 , V_116 ) ;
}
static void F_88 ( struct V_18 * V_19 )
{
void (* F_89)( void * );
F_89 = F_90 ( V_19 -> V_133 ) ;
if ( F_91 ( F_89 != NULL ) )
(* F_89)( V_19 -> V_134 ) ;
}
static void F_92 ( struct V_102 * V_103 )
{
unsigned long * V_135 ;
T_2 V_136 , V_137 ;
if ( V_138 < V_139 ) {
V_136 = V_140 ;
V_135 = V_43 . V_135 ;
} else {
void * V_109 = V_103 -> V_141 ;
union V_142 * V_143
= (union V_142 * ) V_109 +
V_111 ;
V_136 = V_144 ;
V_135 = V_143 -> V_54 ;
}
if ( F_93 ( ! V_135 ) )
return;
F_94 (relid, recv_int_page, maxbits) {
struct V_18 * V_19 ;
if ( ! F_95 ( V_137 , V_135 ) )
continue;
if ( V_137 == 0 )
continue;
F_96 () ;
F_97 (channel, &hv_cpu->chan_list, percpu_list) {
if ( V_19 -> V_20 . V_38 != V_137 )
continue;
if ( V_19 -> V_145 )
continue;
switch ( V_19 -> V_146 ) {
case V_147 :
F_88 ( V_19 ) ;
break;
case V_148 :
F_98 ( & V_19 -> V_52 ) ;
case V_149 :
F_99 ( & V_19 -> V_150 ) ;
}
}
F_100 () ;
}
}
static void F_101 ( void )
{
struct V_102 * V_103
= F_102 ( V_151 . V_152 ) ;
void * V_109 = V_103 -> V_141 ;
struct V_101 * V_100 ;
union V_142 * V_143 ;
bool V_153 = false ;
if ( F_93 ( V_109 == NULL ) )
return;
V_143 = (union V_142 * ) V_109 +
V_111 ;
if ( ( V_138 == V_154 ) ||
( V_138 == V_155 ) ) {
if ( F_95 ( 0 , V_143 -> V_54 ) )
V_153 = true ;
} else {
V_153 = true ;
}
if ( V_153 )
F_92 ( V_103 ) ;
V_109 = V_103 -> V_110 ;
V_100 = (struct V_101 * ) V_109 + V_111 ;
if ( V_100 -> V_117 . V_116 != V_118 ) {
if ( V_100 -> V_117 . V_116 == V_107 )
F_78 ( V_100 , V_103 ) ;
else
F_99 ( & V_103 -> V_156 ) ;
}
F_103 ( V_157 , 0 ) ;
}
static int F_104 ( void )
{
int V_68 ;
V_68 = F_105 () ;
if ( V_68 != 0 ) {
F_67 ( L_11 , V_68 ) ;
return V_68 ;
}
V_68 = F_106 ( & V_158 ) ;
if ( V_68 )
return V_68 ;
F_107 ( F_101 ) ;
V_68 = F_108 () ;
if ( V_68 )
goto V_159;
V_68 = F_109 ( V_160 , L_12 ,
V_161 , V_162 ) ;
if ( V_68 < 0 )
goto V_159;
V_163 = V_68 ;
V_68 = F_110 () ;
if ( V_68 )
goto V_164;
if ( V_165 . V_166 & V_167 ) {
F_111 ( & V_168 ) ;
F_112 ( & V_169 ,
& V_170 ) ;
}
F_113 () ;
return 0 ;
V_164:
F_114 ( V_163 ) ;
V_159:
F_115 () ;
F_116 () ;
F_117 ( & V_158 ) ;
return V_68 ;
}
int F_118 ( struct V_72 * V_72 , struct V_171 * V_172 , const char * V_173 )
{
int V_68 ;
F_119 ( L_13 , V_72 -> V_174 ) ;
V_68 = F_5 () ;
if ( V_68 < 0 )
return V_68 ;
V_72 -> V_82 . V_174 = V_72 -> V_174 ;
V_72 -> V_82 . V_172 = V_172 ;
V_72 -> V_82 . V_173 = V_173 ;
V_72 -> V_82 . V_175 = & V_158 ;
F_120 ( & V_72 -> V_76 . V_62 ) ;
F_121 ( & V_72 -> V_76 . V_81 ) ;
V_68 = F_122 ( & V_72 -> V_82 ) ;
return V_68 ;
}
void F_123 ( struct V_72 * V_72 )
{
F_119 ( L_14 , V_72 -> V_174 ) ;
if ( ! F_5 () ) {
F_124 ( & V_72 -> V_82 ) ;
F_56 ( V_72 ) ;
}
}
struct V_11 * F_125 ( const T_4 * type ,
const T_4 * V_176 ,
struct V_18 * V_19 )
{
struct V_11 * V_177 ;
V_177 = F_53 ( sizeof( struct V_11 ) , V_78 ) ;
if ( ! V_177 ) {
F_67 ( L_15 ) ;
return NULL ;
}
V_177 -> V_19 = V_19 ;
memcpy ( & V_177 -> V_16 , type , sizeof( T_4 ) ) ;
memcpy ( & V_177 -> V_178 , V_176 ,
sizeof( T_4 ) ) ;
V_177 -> V_64 = 0x1414 ;
return V_177 ;
}
int F_126 ( struct V_11 * V_177 )
{
int V_68 = 0 ;
F_127 ( & V_177 -> V_33 , L_16 ,
V_177 -> V_19 -> V_20 . V_40 . V_42 . V_17 ) ;
V_177 -> V_33 . V_175 = & V_158 ;
V_177 -> V_33 . V_179 = & V_9 -> V_34 ;
V_177 -> V_33 . V_180 = F_71 ;
V_68 = F_128 ( & V_177 -> V_33 ) ;
if ( V_68 )
F_67 ( L_17 ) ;
else
F_129 ( L_18 ,
F_68 ( & V_177 -> V_33 ) ) ;
return V_68 ;
}
void F_130 ( struct V_11 * V_181 )
{
F_129 ( L_19 ,
F_68 ( & V_181 -> V_33 ) ) ;
F_131 ( & V_181 -> V_33 ) ;
}
static T_6 F_132 ( struct V_182 * V_183 , void * V_97 )
{
T_7 V_184 = 0 ;
T_7 V_185 = 0 ;
struct V_186 * V_187 ;
struct V_186 * * V_188 = & V_189 ;
struct V_186 * * V_190 = NULL ;
switch ( V_183 -> type ) {
case V_191 :
V_184 = V_183 -> V_108 . V_192 . V_193 . V_194 ;
V_185 = V_183 -> V_108 . V_192 . V_193 . V_195 ;
break;
case V_196 :
V_184 = V_183 -> V_108 . V_197 . V_193 . V_194 ;
V_185 = V_183 -> V_108 . V_197 . V_193 . V_195 ;
break;
default:
return V_198 ;
}
if ( V_185 < 0x100000 )
return V_198 ;
V_187 = F_53 ( sizeof( * V_187 ) , V_126 ) ;
if ( ! V_187 )
return V_199 ;
if ( V_185 > V_200 && V_184 < V_200 )
V_185 = V_200 ;
V_187 -> V_174 = L_20 ;
V_187 -> V_54 = V_201 ;
V_187 -> V_184 = V_184 ;
V_187 -> V_185 = V_185 ;
do {
if ( ! * V_188 ) {
* V_188 = V_187 ;
break;
}
if ( ( ( * V_188 ) -> V_185 + 1 ) == V_187 -> V_184 ) {
( * V_188 ) -> V_185 = V_187 -> V_185 ;
F_59 ( V_187 ) ;
break;
}
if ( ( * V_188 ) -> V_184 == V_187 -> V_185 + 1 ) {
( * V_188 ) -> V_184 = V_187 -> V_184 ;
F_59 ( V_187 ) ;
break;
}
if ( ( * V_188 ) -> V_184 > V_187 -> V_185 ) {
V_187 -> V_202 = * V_188 ;
if ( V_190 )
( * V_190 ) -> V_202 = V_187 ;
* V_188 = V_187 ;
break;
}
V_190 = V_188 ;
V_188 = & ( * V_188 ) -> V_202 ;
} while ( 1 );
return V_198 ;
}
static int F_133 ( struct V_203 * V_33 )
{
struct V_186 * V_204 ;
struct V_186 * V_205 ;
if ( V_189 ) {
if ( V_206 ) {
F_134 ( V_189 , V_206 -> V_184 ,
F_135 ( V_206 ) ) ;
V_206 = NULL ;
}
for ( V_204 = V_189 ; V_204 ; V_204 = V_205 ) {
V_205 = V_204 -> V_202 ;
F_59 ( V_204 ) ;
}
}
return 0 ;
}
static void F_136 ( void )
{
int V_207 ;
if ( V_208 . V_209 ) {
if ( F_137 ( V_210 ) )
V_207 = F_138 ( V_211 , V_208 . V_212 , 0x800000 ) ;
else
V_207 = F_138 ( V_211 , V_208 . V_212 , 0x4000000 ) ;
for (; ! V_206 && ( V_207 >= 0x100000 ) ; V_207 >>= 1 ) {
V_206 = F_139 ( V_189 ,
V_208 . V_209 , V_207 ,
V_213 , 0 ) ;
}
}
}
int F_140 ( struct V_186 * * V_214 , struct V_11 * V_181 ,
T_7 V_215 , T_7 V_216 ,
T_7 V_207 , T_7 V_217 ,
bool V_218 )
{
struct V_186 * V_219 , * V_220 ;
T_7 V_221 , V_222 , V_184 ;
const char * V_223 = F_68 ( & V_181 -> V_33 ) ;
int V_86 ;
V_86 = - V_224 ;
F_141 ( & V_225 ) ;
if ( V_218 && V_206 && ! ( V_215 > V_206 -> V_185 ) &&
! ( V_216 < V_206 -> V_184 ) ) {
V_221 = V_206 -> V_184 ;
V_222 = V_206 -> V_185 ;
V_184 = ( V_221 + V_217 - 1 ) & ~ ( V_217 - 1 ) ;
for (; V_184 + V_207 - 1 <= V_222 ; V_184 += V_217 ) {
* V_214 = F_142 ( V_184 , V_207 , V_223 ) ;
if ( * V_214 ) {
V_86 = 0 ;
goto exit;
}
}
}
for ( V_219 = V_189 ; V_219 ; V_219 = V_219 -> V_202 ) {
if ( ( V_219 -> V_184 >= V_216 ) || ( V_219 -> V_185 <= V_215 ) )
continue;
V_221 = V_219 -> V_184 ;
V_222 = V_219 -> V_185 ;
V_184 = ( V_221 + V_217 - 1 ) & ~ ( V_217 - 1 ) ;
for (; V_184 + V_207 - 1 <= V_222 ; V_184 += V_217 ) {
V_220 = F_139 ( V_219 , V_184 , V_207 , NULL ,
V_226 ) ;
if ( ! V_220 )
continue;
* V_214 = F_142 ( V_184 , V_207 , V_223 ) ;
if ( * V_214 ) {
V_220 -> V_174 = ( char * ) * V_214 ;
V_86 = 0 ;
goto exit;
}
F_134 ( V_219 , V_184 , V_207 ) ;
}
}
exit:
F_143 ( & V_225 ) ;
return V_86 ;
}
void F_144 ( T_7 V_184 , T_7 V_207 )
{
struct V_186 * V_219 ;
F_141 ( & V_225 ) ;
for ( V_219 = V_189 ; V_219 ; V_219 = V_219 -> V_202 ) {
if ( ( V_219 -> V_184 >= V_184 + V_207 ) || ( V_219 -> V_185 <= V_184 ) )
continue;
F_134 ( V_219 , V_184 , V_207 ) ;
}
F_145 ( V_184 , V_207 ) ;
F_143 ( & V_225 ) ;
}
static int F_146 ( struct V_203 * V_33 )
{
T_6 V_227 ;
int V_228 = - V_10 ;
struct V_203 * V_229 ;
V_9 = V_33 ;
V_227 = F_147 ( V_33 -> V_230 , V_231 ,
F_132 , NULL ) ;
if ( F_148 ( V_227 ) )
goto V_232;
for ( V_229 = V_33 -> V_179 ; V_229 ; V_229 = V_229 -> V_179 ) {
V_227 = F_147 ( V_229 -> V_230 , V_231 ,
F_132 , NULL ) ;
if ( F_148 ( V_227 ) )
continue;
if ( V_189 ) {
F_136 () ;
break;
}
}
V_228 = 0 ;
V_232:
F_149 ( & V_233 ) ;
if ( V_228 )
F_133 ( V_33 ) ;
return V_228 ;
}
static void F_150 ( void )
{
F_151 () ;
F_152 ( false ) ;
V_43 . V_98 = V_99 ;
F_153 () ;
F_114 ( V_163 ) ;
F_154 () ;
}
static void F_155 ( struct V_4 * V_5 )
{
F_152 ( true ) ;
V_43 . V_98 = V_99 ;
V_162 ( F_156 () ) ;
F_154 () ;
}
static int T_8 F_157 ( void )
{
int V_68 , V_234 ;
if ( V_235 != & V_236 )
return - V_10 ;
F_158 ( & V_233 ) ;
V_68 = F_159 ( & V_237 ) ;
if ( V_68 )
return V_68 ;
V_234 = F_160 ( & V_233 , 5 * V_238 ) ;
if ( V_234 == 0 ) {
V_68 = - V_239 ;
goto V_240;
}
V_68 = F_104 () ;
if ( V_68 )
goto V_240;
F_161 ( F_150 ) ;
F_162 ( F_155 ) ;
return 0 ;
V_240:
F_163 ( & V_237 ) ;
V_9 = NULL ;
return V_68 ;
}
static void T_9 F_164 ( void )
{
int V_241 ;
F_165 () ;
F_166 () ;
V_43 . V_98 = V_99 ;
F_151 () ;
F_167 () ;
F_116 () ;
F_168 (cpu) {
struct V_102 * V_103
= F_169 ( V_151 . V_152 , V_241 ) ;
F_170 ( & V_103 -> V_156 ) ;
}
F_171 () ;
if ( V_165 . V_166 & V_167 ) {
F_172 ( & V_168 ) ;
F_173 ( & V_169 ,
& V_170 ) ;
}
F_117 ( & V_158 ) ;
F_114 ( V_163 ) ;
F_115 () ;
F_163 ( & V_237 ) ;
}
