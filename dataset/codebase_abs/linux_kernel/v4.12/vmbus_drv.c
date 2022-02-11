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
static int F_60 ( const char * V_84 , T_4 * V_85 )
{
unsigned int V_17 [ 16 ] ;
int V_14 ;
if ( strlen ( V_84 ) < 37 )
return - 1 ;
for ( V_14 = 0 ; V_14 < 36 ; V_14 ++ ) {
switch ( V_14 ) {
case 8 : case 13 : case 18 : case 23 :
if ( V_84 [ V_14 ] != '-' )
return - 1 ;
break;
default:
if ( ! isxdigit ( V_84 [ V_14 ] ) )
return - 1 ;
}
}
if ( sscanf ( V_84 ,
L_8 ,
& V_17 [ 3 ] , & V_17 [ 2 ] , & V_17 [ 1 ] , & V_17 [ 0 ] ,
& V_17 [ 5 ] , & V_17 [ 4 ] , & V_17 [ 7 ] , & V_17 [ 6 ] , & V_17 [ 8 ] , & V_17 [ 9 ] ,
& V_17 [ 10 ] , & V_17 [ 11 ] , & V_17 [ 12 ] , & V_17 [ 13 ] , & V_17 [ 14 ] , & V_17 [ 15 ] ) != 16 )
return - 1 ;
for ( V_14 = 0 ; V_14 < 16 ; V_14 ++ )
V_85 -> V_17 [ V_14 ] = V_17 [ V_14 ] ;
return 0 ;
}
static T_3 F_61 ( struct V_86 * V_82 , const char * V_37 ,
T_5 V_87 )
{
struct V_72 * V_73 = F_62 ( V_82 ) ;
T_4 V_69 = V_88 ;
T_3 V_89 ;
if ( F_60 ( V_37 , & V_69 ) != 0 )
return - V_90 ;
if ( F_48 ( V_73 , & V_69 ) )
return - V_91 ;
V_89 = F_52 ( V_73 , & V_69 ) ;
if ( V_89 )
return V_89 ;
return V_87 ;
}
static T_3 F_63 ( struct V_86 * V_82 , const char * V_37 ,
T_5 V_87 )
{
struct V_72 * V_73 = F_62 ( V_82 ) ;
struct V_74 * V_75 , * V_83 ;
T_4 V_69 = V_88 ;
T_5 V_89 = - V_10 ;
if ( F_60 ( V_37 , & V_69 ) )
return - V_90 ;
F_49 ( & V_73 -> V_76 . V_62 ) ;
F_57 (dynid, n, &drv->dynids.list, node) {
struct V_71 * V_32 = & V_75 -> V_32 ;
if ( ! F_47 ( V_32 -> V_69 , V_69 ) ) {
F_58 ( & V_75 -> V_80 ) ;
F_59 ( V_75 ) ;
V_89 = V_87 ;
break;
}
}
F_51 ( & V_73 -> V_76 . V_62 ) ;
return V_89 ;
}
static int F_64 ( struct V_33 * V_33 , struct V_86 * V_82 )
{
struct V_72 * V_73 = F_62 ( V_82 ) ;
struct V_11 * V_12 = F_13 ( V_33 ) ;
if ( F_65 ( V_12 -> V_19 ) )
return V_73 -> V_92 ;
if ( F_48 ( V_73 , & V_12 -> V_16 ) )
return 1 ;
return 0 ;
}
static int F_66 ( struct V_33 * V_93 )
{
int V_68 = 0 ;
struct V_72 * V_73 =
F_62 ( V_93 -> V_82 ) ;
struct V_11 * V_34 = F_13 ( V_93 ) ;
const struct V_71 * V_94 ;
V_94 = F_48 ( V_73 , & V_34 -> V_16 ) ;
if ( V_73 -> V_95 ) {
V_68 = V_73 -> V_95 ( V_34 , V_94 ) ;
if ( V_68 != 0 )
F_67 ( L_9 ,
F_68 ( V_93 ) , V_68 ) ;
} else {
F_67 ( L_10 ,
F_68 ( V_93 ) ) ;
V_68 = - V_10 ;
}
return V_68 ;
}
static int F_69 ( struct V_33 * V_93 )
{
struct V_72 * V_73 ;
struct V_11 * V_34 = F_13 ( V_93 ) ;
if ( V_93 -> V_82 ) {
V_73 = F_62 ( V_93 -> V_82 ) ;
if ( V_73 -> remove )
V_73 -> remove ( V_34 ) ;
}
return 0 ;
}
static void F_70 ( struct V_33 * V_93 )
{
struct V_72 * V_73 ;
struct V_11 * V_34 = F_13 ( V_93 ) ;
if ( ! V_93 -> V_82 )
return;
V_73 = F_62 ( V_93 -> V_82 ) ;
if ( V_73 -> V_96 )
V_73 -> V_96 ( V_34 ) ;
}
static void F_71 ( struct V_33 * V_33 )
{
struct V_11 * V_12 = F_13 ( V_33 ) ;
struct V_18 * V_19 = V_12 -> V_19 ;
F_72 ( V_19 ,
V_19 -> V_20 . V_38 ) ;
F_59 ( V_12 ) ;
}
static void F_73 ( struct V_97 * V_98 )
{
struct V_99 * V_100 ;
if ( V_43 . V_101 == V_102 )
return;
V_100 = F_74 ( V_98 , struct V_99 ,
V_98 ) ;
F_75 ( & V_100 -> V_103 ) ;
F_59 ( V_100 ) ;
}
static void F_76 ( struct V_104 * V_103 ,
struct V_105 * V_106 )
{
struct V_107 * V_34 = V_106 -> V_108 ;
if ( V_34 -> V_109 )
V_34 -> V_109 ( V_34 ) ;
F_77 ( V_103 , V_110 ) ;
}
void F_78 ( unsigned long V_111 )
{
struct V_105 * V_106 = ( void * ) V_111 ;
void * V_112 = V_106 -> V_113 ;
struct V_104 * V_103 = (struct V_104 * ) V_112 +
V_114 ;
struct V_115 * V_116 ;
const struct V_117 * V_118 ;
struct V_99 * V_100 ;
T_2 V_119 = V_103 -> V_120 . V_119 ;
if ( V_119 == V_121 )
return;
V_116 = (struct V_115 * ) V_103 -> V_31 . V_122 ;
if ( V_116 -> V_123 >= V_124 ) {
F_79 ( 1 , L_11 , V_116 -> V_123 ) ;
goto V_125;
}
V_118 = & V_126 [ V_116 -> V_123 ] ;
if ( V_118 -> V_127 == V_128 ) {
V_100 = F_80 ( sizeof( * V_100 ) , V_129 ) ;
if ( V_100 == NULL )
return;
F_81 ( & V_100 -> V_98 , F_73 ) ;
memcpy ( & V_100 -> V_103 , V_103 , sizeof( * V_103 ) ) ;
F_82 ( V_43 . V_130 , & V_100 -> V_98 ) ;
} else
V_118 -> V_131 ( V_116 ) ;
V_125:
F_77 ( V_103 , V_119 ) ;
}
static void F_83 ( struct V_18 * V_19 )
{
void (* F_84)( void * );
F_84 = F_85 ( V_19 -> V_132 ) ;
if ( F_86 ( F_84 != NULL ) )
(* F_84)( V_19 -> V_133 ) ;
}
static void F_87 ( struct V_105 * V_106 )
{
unsigned long * V_134 ;
T_2 V_135 , V_136 ;
if ( V_137 < V_138 ) {
V_135 = V_139 ;
V_134 = V_43 . V_134 ;
} else {
void * V_112 = V_106 -> V_140 ;
union V_141 * V_142
= (union V_141 * ) V_112 +
V_114 ;
V_135 = V_143 ;
V_134 = V_142 -> V_54 ;
}
if ( F_88 ( ! V_134 ) )
return;
F_89 (relid, recv_int_page, maxbits) {
struct V_18 * V_19 ;
if ( ! F_90 ( V_136 , V_134 ) )
continue;
if ( V_136 == 0 )
continue;
F_91 () ;
F_92 (channel, &hv_cpu->chan_list, percpu_list) {
if ( V_19 -> V_20 . V_38 != V_136 )
continue;
switch ( V_19 -> V_144 ) {
case V_145 :
F_83 ( V_19 ) ;
break;
case V_146 :
F_93 ( & V_19 -> V_52 ) ;
case V_147 :
F_94 ( & V_19 -> V_148 ) ;
}
}
F_95 () ;
}
}
static void F_96 ( void )
{
struct V_105 * V_106
= F_97 ( V_149 . V_150 ) ;
void * V_112 = V_106 -> V_140 ;
struct V_104 * V_103 ;
union V_141 * V_142 ;
bool V_151 = false ;
if ( F_88 ( V_112 == NULL ) )
return;
V_142 = (union V_141 * ) V_112 +
V_114 ;
if ( ( V_137 == V_152 ) ||
( V_137 == V_153 ) ) {
if ( F_90 ( 0 , V_142 -> V_54 ) )
V_151 = true ;
} else {
V_151 = true ;
}
if ( V_151 )
F_87 ( V_106 ) ;
V_112 = V_106 -> V_113 ;
V_103 = (struct V_104 * ) V_112 + V_114 ;
if ( V_103 -> V_120 . V_119 != V_121 ) {
if ( V_103 -> V_120 . V_119 == V_110 )
F_76 ( V_103 , V_106 ) ;
else
F_94 ( & V_106 -> V_154 ) ;
}
F_98 ( V_155 , 0 ) ;
}
static int F_99 ( void )
{
int V_68 ;
V_68 = F_100 () ;
if ( V_68 != 0 ) {
F_67 ( L_12 , V_68 ) ;
return V_68 ;
}
V_68 = F_101 ( & V_156 ) ;
if ( V_68 )
return V_68 ;
F_102 ( F_96 ) ;
V_68 = F_103 () ;
if ( V_68 )
goto V_157;
V_68 = F_104 ( V_158 , L_13 ,
V_159 , V_160 ) ;
if ( V_68 < 0 )
goto V_157;
V_161 = V_68 ;
V_68 = F_105 () ;
if ( V_68 )
goto V_162;
if ( V_163 . V_164 & V_165 ) {
F_106 ( & V_166 ) ;
F_107 ( & V_167 ,
& V_168 ) ;
}
F_108 () ;
return 0 ;
V_162:
F_109 ( V_161 ) ;
V_157:
F_110 () ;
F_111 () ;
F_112 ( & V_156 ) ;
return V_68 ;
}
int F_113 ( struct V_72 * V_72 , struct V_169 * V_170 , const char * V_171 )
{
int V_68 ;
F_114 ( L_14 , V_72 -> V_172 ) ;
V_68 = F_5 () ;
if ( V_68 < 0 )
return V_68 ;
V_72 -> V_82 . V_172 = V_72 -> V_172 ;
V_72 -> V_82 . V_170 = V_170 ;
V_72 -> V_82 . V_171 = V_171 ;
V_72 -> V_82 . V_173 = & V_156 ;
F_115 ( & V_72 -> V_76 . V_62 ) ;
F_116 ( & V_72 -> V_76 . V_81 ) ;
V_68 = F_117 ( & V_72 -> V_82 ) ;
return V_68 ;
}
void F_118 ( struct V_72 * V_72 )
{
F_114 ( L_15 , V_72 -> V_172 ) ;
if ( ! F_5 () ) {
F_119 ( & V_72 -> V_82 ) ;
F_56 ( V_72 ) ;
}
}
struct V_11 * F_120 ( const T_4 * type ,
const T_4 * V_174 ,
struct V_18 * V_19 )
{
struct V_11 * V_175 ;
V_175 = F_53 ( sizeof( struct V_11 ) , V_78 ) ;
if ( ! V_175 ) {
F_67 ( L_16 ) ;
return NULL ;
}
V_175 -> V_19 = V_19 ;
memcpy ( & V_175 -> V_16 , type , sizeof( T_4 ) ) ;
memcpy ( & V_175 -> V_176 , V_174 ,
sizeof( T_4 ) ) ;
V_175 -> V_64 = 0x1414 ;
return V_175 ;
}
int F_121 ( struct V_11 * V_175 )
{
int V_68 = 0 ;
F_122 ( & V_175 -> V_33 , L_17 ,
V_175 -> V_19 -> V_20 . V_40 . V_42 . V_17 ) ;
V_175 -> V_33 . V_173 = & V_156 ;
V_175 -> V_33 . V_177 = & V_9 -> V_34 ;
V_175 -> V_33 . V_178 = F_71 ;
V_68 = F_123 ( & V_175 -> V_33 ) ;
if ( V_68 )
F_67 ( L_18 ) ;
else
F_124 ( L_19 ,
F_68 ( & V_175 -> V_33 ) ) ;
return V_68 ;
}
void F_125 ( struct V_11 * V_179 )
{
F_124 ( L_20 ,
F_68 ( & V_179 -> V_33 ) ) ;
F_126 ( & V_179 -> V_33 ) ;
}
static T_6 F_127 ( struct V_180 * V_181 , void * V_100 )
{
T_7 V_182 = 0 ;
T_7 V_183 = 0 ;
struct V_184 * V_185 ;
struct V_184 * * V_186 = & V_187 ;
struct V_184 * * V_188 = NULL ;
switch ( V_181 -> type ) {
case V_189 :
V_182 = V_181 -> V_111 . V_190 . V_191 . V_192 ;
V_183 = V_181 -> V_111 . V_190 . V_191 . V_193 ;
break;
case V_194 :
V_182 = V_181 -> V_111 . V_195 . V_191 . V_192 ;
V_183 = V_181 -> V_111 . V_195 . V_191 . V_193 ;
break;
default:
return V_196 ;
}
if ( V_183 < 0x100000 )
return V_196 ;
V_185 = F_53 ( sizeof( * V_185 ) , V_129 ) ;
if ( ! V_185 )
return V_197 ;
if ( V_183 > V_198 && V_182 < V_198 )
V_183 = V_198 ;
V_185 -> V_172 = L_21 ;
V_185 -> V_54 = V_199 ;
V_185 -> V_182 = V_182 ;
V_185 -> V_183 = V_183 ;
do {
if ( ! * V_186 ) {
* V_186 = V_185 ;
break;
}
if ( ( ( * V_186 ) -> V_183 + 1 ) == V_185 -> V_182 ) {
( * V_186 ) -> V_183 = V_185 -> V_183 ;
F_59 ( V_185 ) ;
break;
}
if ( ( * V_186 ) -> V_182 == V_185 -> V_183 + 1 ) {
( * V_186 ) -> V_182 = V_185 -> V_182 ;
F_59 ( V_185 ) ;
break;
}
if ( ( * V_186 ) -> V_182 > V_185 -> V_183 ) {
V_185 -> V_200 = * V_186 ;
if ( V_188 )
( * V_188 ) -> V_200 = V_185 ;
* V_186 = V_185 ;
break;
}
V_188 = V_186 ;
V_186 = & ( * V_186 ) -> V_200 ;
} while ( 1 );
return V_196 ;
}
static int F_128 ( struct V_201 * V_33 )
{
struct V_184 * V_202 ;
struct V_184 * V_203 ;
if ( V_187 ) {
if ( V_204 ) {
F_129 ( V_187 , V_204 -> V_182 ,
F_130 ( V_204 ) ) ;
V_204 = NULL ;
}
for ( V_202 = V_187 ; V_202 ; V_202 = V_203 ) {
V_203 = V_202 -> V_200 ;
F_59 ( V_202 ) ;
}
}
return 0 ;
}
static void F_131 ( void )
{
int V_205 ;
if ( V_206 . V_207 ) {
if ( F_132 ( V_208 ) )
V_205 = F_133 ( V_209 , V_206 . V_210 , 0x800000 ) ;
else
V_205 = F_133 ( V_209 , V_206 . V_210 , 0x4000000 ) ;
for (; ! V_204 && ( V_205 >= 0x100000 ) ; V_205 >>= 1 ) {
V_204 = F_134 ( V_187 ,
V_206 . V_207 , V_205 ,
V_211 , 0 ) ;
}
}
}
int F_135 ( struct V_184 * * V_212 , struct V_11 * V_179 ,
T_7 V_213 , T_7 V_214 ,
T_7 V_205 , T_7 V_215 ,
bool V_216 )
{
struct V_184 * V_217 , * V_218 ;
T_7 V_219 , V_220 , V_182 ;
const char * V_221 = F_68 ( & V_179 -> V_33 ) ;
int V_89 ;
V_89 = - V_222 ;
F_136 ( & V_223 ) ;
if ( V_216 && V_204 && ! ( V_213 > V_204 -> V_183 ) &&
! ( V_214 < V_204 -> V_182 ) ) {
V_219 = V_204 -> V_182 ;
V_220 = V_204 -> V_183 ;
V_182 = ( V_219 + V_215 - 1 ) & ~ ( V_215 - 1 ) ;
for (; V_182 + V_205 - 1 <= V_220 ; V_182 += V_215 ) {
* V_212 = F_137 ( V_182 , V_205 , V_221 ) ;
if ( * V_212 ) {
V_89 = 0 ;
goto exit;
}
}
}
for ( V_217 = V_187 ; V_217 ; V_217 = V_217 -> V_200 ) {
if ( ( V_217 -> V_182 >= V_214 ) || ( V_217 -> V_183 <= V_213 ) )
continue;
V_219 = V_217 -> V_182 ;
V_220 = V_217 -> V_183 ;
V_182 = ( V_219 + V_215 - 1 ) & ~ ( V_215 - 1 ) ;
for (; V_182 + V_205 - 1 <= V_220 ; V_182 += V_215 ) {
V_218 = F_134 ( V_217 , V_182 , V_205 , NULL ,
V_224 ) ;
if ( ! V_218 )
continue;
* V_212 = F_137 ( V_182 , V_205 , V_221 ) ;
if ( * V_212 ) {
V_218 -> V_172 = ( char * ) * V_212 ;
V_89 = 0 ;
goto exit;
}
F_129 ( V_217 , V_182 , V_205 ) ;
}
}
exit:
F_138 ( & V_223 ) ;
return V_89 ;
}
void F_139 ( T_7 V_182 , T_7 V_205 )
{
struct V_184 * V_217 ;
F_136 ( & V_223 ) ;
for ( V_217 = V_187 ; V_217 ; V_217 = V_217 -> V_200 ) {
if ( ( V_217 -> V_182 >= V_182 + V_205 ) || ( V_217 -> V_183 <= V_182 ) )
continue;
F_129 ( V_217 , V_182 , V_205 ) ;
}
F_140 ( V_182 , V_205 ) ;
F_138 ( & V_223 ) ;
}
int F_141 ( int V_225 )
{
return V_149 . V_226 [ V_225 ] ;
}
static int F_142 ( struct V_201 * V_33 )
{
T_6 V_227 ;
int V_228 = - V_10 ;
struct V_201 * V_229 ;
V_9 = V_33 ;
V_227 = F_143 ( V_33 -> V_230 , V_231 ,
F_127 , NULL ) ;
if ( F_144 ( V_227 ) )
goto V_232;
for ( V_229 = V_33 -> V_177 ; V_229 ; V_229 = V_229 -> V_177 ) {
V_227 = F_143 ( V_229 -> V_230 , V_231 ,
F_127 , NULL ) ;
if ( F_144 ( V_227 ) )
continue;
if ( V_187 ) {
F_131 () ;
break;
}
}
V_228 = 0 ;
V_232:
F_145 ( & V_233 ) ;
if ( V_228 )
F_128 ( V_33 ) ;
return V_228 ;
}
static void F_146 ( void )
{
F_147 () ;
F_148 ( false ) ;
V_43 . V_101 = V_102 ;
F_149 () ;
F_109 ( V_161 ) ;
F_150 () ;
}
static void F_151 ( struct V_4 * V_5 )
{
F_148 ( true ) ;
V_43 . V_101 = V_102 ;
V_160 ( F_152 () ) ;
F_150 () ;
}
static int T_8 F_153 ( void )
{
int V_68 , V_234 ;
if ( V_235 != & V_236 )
return - V_10 ;
F_154 ( & V_233 ) ;
V_68 = F_155 ( & V_237 ) ;
if ( V_68 )
return V_68 ;
V_234 = F_156 ( & V_233 , 5 * V_238 ) ;
if ( V_234 == 0 ) {
V_68 = - V_239 ;
goto V_240;
}
V_68 = F_99 () ;
if ( V_68 )
goto V_240;
F_157 ( F_146 ) ;
F_158 ( F_151 ) ;
return 0 ;
V_240:
F_159 ( & V_237 ) ;
V_9 = NULL ;
return V_68 ;
}
static void T_9 F_160 ( void )
{
int V_241 ;
F_161 () ;
F_162 () ;
V_43 . V_101 = V_102 ;
F_147 () ;
F_163 () ;
F_111 () ;
F_164 (cpu) {
struct V_105 * V_106
= F_165 ( V_149 . V_150 , V_241 ) ;
F_166 ( & V_106 -> V_154 ) ;
}
F_167 () ;
if ( V_163 . V_164 & V_165 ) {
F_168 ( & V_166 ) ;
F_169 ( & V_167 ,
& V_168 ) ;
}
F_112 ( & V_156 ) ;
F_109 ( V_161 ) ;
F_110 () ;
F_159 ( & V_237 ) ;
}
