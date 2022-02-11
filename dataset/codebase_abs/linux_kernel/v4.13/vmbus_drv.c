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
F_73 ( V_19 ,
V_19 -> V_20 . V_38 ) ;
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
switch ( V_19 -> V_145 ) {
case V_146 :
F_88 ( V_19 ) ;
break;
case V_147 :
F_98 ( & V_19 -> V_52 ) ;
case V_148 :
F_99 ( & V_19 -> V_149 ) ;
}
}
F_100 () ;
}
}
static void F_101 ( void )
{
struct V_102 * V_103
= F_102 ( V_150 . V_151 ) ;
void * V_109 = V_103 -> V_141 ;
struct V_101 * V_100 ;
union V_142 * V_143 ;
bool V_152 = false ;
if ( F_93 ( V_109 == NULL ) )
return;
V_143 = (union V_142 * ) V_109 +
V_111 ;
if ( ( V_138 == V_153 ) ||
( V_138 == V_154 ) ) {
if ( F_95 ( 0 , V_143 -> V_54 ) )
V_152 = true ;
} else {
V_152 = true ;
}
if ( V_152 )
F_92 ( V_103 ) ;
V_109 = V_103 -> V_110 ;
V_100 = (struct V_101 * ) V_109 + V_111 ;
if ( V_100 -> V_117 . V_116 != V_118 ) {
if ( V_100 -> V_117 . V_116 == V_107 )
F_78 ( V_100 , V_103 ) ;
else
F_99 ( & V_103 -> V_155 ) ;
}
F_103 ( V_156 , 0 ) ;
}
static int F_104 ( void )
{
int V_68 ;
V_68 = F_105 () ;
if ( V_68 != 0 ) {
F_67 ( L_11 , V_68 ) ;
return V_68 ;
}
V_68 = F_106 ( & V_157 ) ;
if ( V_68 )
return V_68 ;
F_107 ( F_101 ) ;
V_68 = F_108 () ;
if ( V_68 )
goto V_158;
V_68 = F_109 ( V_159 , L_12 ,
V_160 , V_161 ) ;
if ( V_68 < 0 )
goto V_158;
V_162 = V_68 ;
V_68 = F_110 () ;
if ( V_68 )
goto V_163;
if ( V_164 . V_165 & V_166 ) {
F_111 ( & V_167 ) ;
F_112 ( & V_168 ,
& V_169 ) ;
}
F_113 () ;
return 0 ;
V_163:
F_114 ( V_162 ) ;
V_158:
F_115 () ;
F_116 () ;
F_117 ( & V_157 ) ;
return V_68 ;
}
int F_118 ( struct V_72 * V_72 , struct V_170 * V_171 , const char * V_172 )
{
int V_68 ;
F_119 ( L_13 , V_72 -> V_173 ) ;
V_68 = F_5 () ;
if ( V_68 < 0 )
return V_68 ;
V_72 -> V_82 . V_173 = V_72 -> V_173 ;
V_72 -> V_82 . V_171 = V_171 ;
V_72 -> V_82 . V_172 = V_172 ;
V_72 -> V_82 . V_174 = & V_157 ;
F_120 ( & V_72 -> V_76 . V_62 ) ;
F_121 ( & V_72 -> V_76 . V_81 ) ;
V_68 = F_122 ( & V_72 -> V_82 ) ;
return V_68 ;
}
void F_123 ( struct V_72 * V_72 )
{
F_119 ( L_14 , V_72 -> V_173 ) ;
if ( ! F_5 () ) {
F_124 ( & V_72 -> V_82 ) ;
F_56 ( V_72 ) ;
}
}
struct V_11 * F_125 ( const T_4 * type ,
const T_4 * V_175 ,
struct V_18 * V_19 )
{
struct V_11 * V_176 ;
V_176 = F_53 ( sizeof( struct V_11 ) , V_78 ) ;
if ( ! V_176 ) {
F_67 ( L_15 ) ;
return NULL ;
}
V_176 -> V_19 = V_19 ;
memcpy ( & V_176 -> V_16 , type , sizeof( T_4 ) ) ;
memcpy ( & V_176 -> V_177 , V_175 ,
sizeof( T_4 ) ) ;
V_176 -> V_64 = 0x1414 ;
return V_176 ;
}
int F_126 ( struct V_11 * V_176 )
{
int V_68 = 0 ;
F_127 ( & V_176 -> V_33 , L_16 ,
V_176 -> V_19 -> V_20 . V_40 . V_42 . V_17 ) ;
V_176 -> V_33 . V_174 = & V_157 ;
V_176 -> V_33 . V_178 = & V_9 -> V_34 ;
V_176 -> V_33 . V_179 = F_71 ;
V_68 = F_128 ( & V_176 -> V_33 ) ;
if ( V_68 )
F_67 ( L_17 ) ;
else
F_129 ( L_18 ,
F_68 ( & V_176 -> V_33 ) ) ;
return V_68 ;
}
void F_130 ( struct V_11 * V_180 )
{
F_129 ( L_19 ,
F_68 ( & V_180 -> V_33 ) ) ;
F_131 ( & V_180 -> V_33 ) ;
}
static T_6 F_132 ( struct V_181 * V_182 , void * V_97 )
{
T_7 V_183 = 0 ;
T_7 V_184 = 0 ;
struct V_185 * V_186 ;
struct V_185 * * V_187 = & V_188 ;
struct V_185 * * V_189 = NULL ;
switch ( V_182 -> type ) {
case V_190 :
V_183 = V_182 -> V_108 . V_191 . V_192 . V_193 ;
V_184 = V_182 -> V_108 . V_191 . V_192 . V_194 ;
break;
case V_195 :
V_183 = V_182 -> V_108 . V_196 . V_192 . V_193 ;
V_184 = V_182 -> V_108 . V_196 . V_192 . V_194 ;
break;
default:
return V_197 ;
}
if ( V_184 < 0x100000 )
return V_197 ;
V_186 = F_53 ( sizeof( * V_186 ) , V_126 ) ;
if ( ! V_186 )
return V_198 ;
if ( V_184 > V_199 && V_183 < V_199 )
V_184 = V_199 ;
V_186 -> V_173 = L_20 ;
V_186 -> V_54 = V_200 ;
V_186 -> V_183 = V_183 ;
V_186 -> V_184 = V_184 ;
do {
if ( ! * V_187 ) {
* V_187 = V_186 ;
break;
}
if ( ( ( * V_187 ) -> V_184 + 1 ) == V_186 -> V_183 ) {
( * V_187 ) -> V_184 = V_186 -> V_184 ;
F_59 ( V_186 ) ;
break;
}
if ( ( * V_187 ) -> V_183 == V_186 -> V_184 + 1 ) {
( * V_187 ) -> V_183 = V_186 -> V_183 ;
F_59 ( V_186 ) ;
break;
}
if ( ( * V_187 ) -> V_183 > V_186 -> V_184 ) {
V_186 -> V_201 = * V_187 ;
if ( V_189 )
( * V_189 ) -> V_201 = V_186 ;
* V_187 = V_186 ;
break;
}
V_189 = V_187 ;
V_187 = & ( * V_187 ) -> V_201 ;
} while ( 1 );
return V_197 ;
}
static int F_133 ( struct V_202 * V_33 )
{
struct V_185 * V_203 ;
struct V_185 * V_204 ;
if ( V_188 ) {
if ( V_205 ) {
F_134 ( V_188 , V_205 -> V_183 ,
F_135 ( V_205 ) ) ;
V_205 = NULL ;
}
for ( V_203 = V_188 ; V_203 ; V_203 = V_204 ) {
V_204 = V_203 -> V_201 ;
F_59 ( V_203 ) ;
}
}
return 0 ;
}
static void F_136 ( void )
{
int V_206 ;
if ( V_207 . V_208 ) {
if ( F_137 ( V_209 ) )
V_206 = F_138 ( V_210 , V_207 . V_211 , 0x800000 ) ;
else
V_206 = F_138 ( V_210 , V_207 . V_211 , 0x4000000 ) ;
for (; ! V_205 && ( V_206 >= 0x100000 ) ; V_206 >>= 1 ) {
V_205 = F_139 ( V_188 ,
V_207 . V_208 , V_206 ,
V_212 , 0 ) ;
}
}
}
int F_140 ( struct V_185 * * V_213 , struct V_11 * V_180 ,
T_7 V_214 , T_7 V_215 ,
T_7 V_206 , T_7 V_216 ,
bool V_217 )
{
struct V_185 * V_218 , * V_219 ;
T_7 V_220 , V_221 , V_183 ;
const char * V_222 = F_68 ( & V_180 -> V_33 ) ;
int V_86 ;
V_86 = - V_223 ;
F_141 ( & V_224 ) ;
if ( V_217 && V_205 && ! ( V_214 > V_205 -> V_184 ) &&
! ( V_215 < V_205 -> V_183 ) ) {
V_220 = V_205 -> V_183 ;
V_221 = V_205 -> V_184 ;
V_183 = ( V_220 + V_216 - 1 ) & ~ ( V_216 - 1 ) ;
for (; V_183 + V_206 - 1 <= V_221 ; V_183 += V_216 ) {
* V_213 = F_142 ( V_183 , V_206 , V_222 ) ;
if ( * V_213 ) {
V_86 = 0 ;
goto exit;
}
}
}
for ( V_218 = V_188 ; V_218 ; V_218 = V_218 -> V_201 ) {
if ( ( V_218 -> V_183 >= V_215 ) || ( V_218 -> V_184 <= V_214 ) )
continue;
V_220 = V_218 -> V_183 ;
V_221 = V_218 -> V_184 ;
V_183 = ( V_220 + V_216 - 1 ) & ~ ( V_216 - 1 ) ;
for (; V_183 + V_206 - 1 <= V_221 ; V_183 += V_216 ) {
V_219 = F_139 ( V_218 , V_183 , V_206 , NULL ,
V_225 ) ;
if ( ! V_219 )
continue;
* V_213 = F_142 ( V_183 , V_206 , V_222 ) ;
if ( * V_213 ) {
V_219 -> V_173 = ( char * ) * V_213 ;
V_86 = 0 ;
goto exit;
}
F_134 ( V_218 , V_183 , V_206 ) ;
}
}
exit:
F_143 ( & V_224 ) ;
return V_86 ;
}
void F_144 ( T_7 V_183 , T_7 V_206 )
{
struct V_185 * V_218 ;
F_141 ( & V_224 ) ;
for ( V_218 = V_188 ; V_218 ; V_218 = V_218 -> V_201 ) {
if ( ( V_218 -> V_183 >= V_183 + V_206 ) || ( V_218 -> V_184 <= V_183 ) )
continue;
F_134 ( V_218 , V_183 , V_206 ) ;
}
F_145 ( V_183 , V_206 ) ;
F_143 ( & V_224 ) ;
}
int F_146 ( int V_226 )
{
return V_150 . V_227 [ V_226 ] ;
}
static int F_147 ( struct V_202 * V_33 )
{
T_6 V_228 ;
int V_229 = - V_10 ;
struct V_202 * V_230 ;
V_9 = V_33 ;
V_228 = F_148 ( V_33 -> V_231 , V_232 ,
F_132 , NULL ) ;
if ( F_149 ( V_228 ) )
goto V_233;
for ( V_230 = V_33 -> V_178 ; V_230 ; V_230 = V_230 -> V_178 ) {
V_228 = F_148 ( V_230 -> V_231 , V_232 ,
F_132 , NULL ) ;
if ( F_149 ( V_228 ) )
continue;
if ( V_188 ) {
F_136 () ;
break;
}
}
V_229 = 0 ;
V_233:
F_150 ( & V_234 ) ;
if ( V_229 )
F_133 ( V_33 ) ;
return V_229 ;
}
static void F_151 ( void )
{
F_152 () ;
F_153 ( false ) ;
V_43 . V_98 = V_99 ;
F_154 () ;
F_114 ( V_162 ) ;
F_155 () ;
}
static void F_156 ( struct V_4 * V_5 )
{
F_153 ( true ) ;
V_43 . V_98 = V_99 ;
V_161 ( F_157 () ) ;
F_155 () ;
}
static int T_8 F_158 ( void )
{
int V_68 , V_235 ;
if ( V_236 != & V_237 )
return - V_10 ;
F_159 ( & V_234 ) ;
V_68 = F_160 ( & V_238 ) ;
if ( V_68 )
return V_68 ;
V_235 = F_161 ( & V_234 , 5 * V_239 ) ;
if ( V_235 == 0 ) {
V_68 = - V_240 ;
goto V_241;
}
V_68 = F_104 () ;
if ( V_68 )
goto V_241;
F_162 ( F_151 ) ;
F_163 ( F_156 ) ;
return 0 ;
V_241:
F_164 ( & V_238 ) ;
V_9 = NULL ;
return V_68 ;
}
static void T_9 F_165 ( void )
{
int V_242 ;
F_166 () ;
F_167 () ;
V_43 . V_98 = V_99 ;
F_152 () ;
F_168 () ;
F_116 () ;
F_169 (cpu) {
struct V_102 * V_103
= F_170 ( V_150 . V_151 , V_242 ) ;
F_171 ( & V_103 -> V_155 ) ;
}
F_172 () ;
if ( V_164 . V_165 & V_166 ) {
F_173 ( & V_167 ) ;
F_174 ( & V_168 ,
& V_169 ) ;
}
F_117 ( & V_157 ) ;
F_114 ( V_162 ) ;
F_115 () ;
F_164 ( & V_238 ) ;
}
