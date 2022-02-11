static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
V_2 -> V_4 = 0 ;
F_3 ( & V_2 -> V_5 ) ;
}
static inline bool F_4 ( struct V_1 * V_2 )
{
return ! V_2 -> V_4 && F_5 ( & V_2 -> V_5 ) ;
}
static struct V_6 *
F_6 ( const char * V_7 , const char * V_8 , int V_9 )
{
struct V_6 * V_10 ;
if ( ! V_8 || ! F_7 ( V_8 ) )
return F_8 ( - V_11 ) ;
if ( ! V_7 || ! F_7 ( V_7 ) )
return F_8 ( - V_11 ) ;
V_10 = F_9 ( F_10 ( V_9 ) , V_12 ) ;
if ( ! V_10 )
return F_8 ( - V_13 ) ;
V_10 -> V_14 . V_15 = & V_10 -> V_15 ;
V_10 -> V_14 . V_16 = F_11 ( V_8 , V_12 ) ;
if ( ! V_10 -> V_14 . V_16 )
goto error;
V_10 -> V_15 . system = F_11 ( V_7 , V_12 ) ;
if ( ! V_10 -> V_15 . system )
goto error;
F_3 ( & V_10 -> V_17 ) ;
V_10 -> V_18 . V_19 = V_20 ;
F_1 ( & V_10 -> V_2 ) ;
return V_10 ;
error:
F_12 ( V_10 -> V_14 . V_16 ) ;
F_12 ( V_10 ) ;
return F_8 ( - V_13 ) ;
}
static void F_13 ( struct V_6 * V_10 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_10 -> V_22 ; V_21 ++ )
F_14 ( & V_10 -> args [ V_21 ] ) ;
F_15 ( V_10 -> V_23 ) ;
F_12 ( V_10 -> V_14 . V_15 -> system ) ;
F_12 ( V_10 -> V_14 . V_16 ) ;
F_12 ( V_10 -> V_24 ) ;
F_12 ( V_10 ) ;
}
static struct V_6 * F_16 ( const char * V_8 , const char * V_7 )
{
struct V_6 * V_10 ;
F_17 (tu, &uprobe_list, list)
if ( strcmp ( V_10 -> V_14 . V_16 , V_8 ) == 0 &&
strcmp ( V_10 -> V_14 . V_15 -> system , V_7 ) == 0 )
return V_10 ;
return NULL ;
}
static void F_18 ( struct V_6 * V_10 )
{
F_19 ( & V_10 -> V_17 ) ;
F_20 ( V_10 ) ;
F_13 ( V_10 ) ;
}
static int F_21 ( struct V_6 * V_10 )
{
struct V_6 * V_25 ;
int V_26 ;
F_22 ( & V_27 ) ;
V_25 = F_16 ( V_10 -> V_14 . V_16 , V_10 -> V_14 . V_15 -> system ) ;
if ( V_25 )
F_18 ( V_25 ) ;
V_26 = F_23 ( V_10 ) ;
if ( V_26 ) {
F_24 ( L_1 , V_26 ) ;
goto V_28;
}
F_25 ( & V_10 -> V_17 , & V_29 ) ;
V_28:
F_26 ( & V_27 ) ;
return V_26 ;
}
static int F_27 ( int V_30 , char * * V_31 )
{
struct V_6 * V_10 ;
struct V_23 * V_23 ;
char * V_32 , * V_8 , * V_7 , * V_24 ;
char V_33 [ V_34 ] ;
struct V_35 V_35 ;
unsigned long V_36 ;
bool V_37 ;
int V_21 , V_26 ;
V_23 = NULL ;
V_26 = 0 ;
V_37 = false ;
V_8 = NULL ;
V_7 = NULL ;
if ( V_31 [ 0 ] [ 0 ] == '-' )
V_37 = true ;
else if ( V_31 [ 0 ] [ 0 ] != 'p' ) {
F_28 ( L_2 ) ;
return - V_11 ;
}
if ( V_31 [ 0 ] [ 1 ] == ':' ) {
V_8 = & V_31 [ 0 ] [ 2 ] ;
V_32 = strchr ( V_8 , '/' ) ;
if ( V_32 ) {
V_7 = V_8 ;
V_8 = V_32 + 1 ;
V_8 [ - 1 ] = '\0' ;
if ( strlen ( V_7 ) == 0 ) {
F_28 ( L_3 ) ;
return - V_11 ;
}
}
if ( strlen ( V_8 ) == 0 ) {
F_28 ( L_4 ) ;
return - V_11 ;
}
}
if ( ! V_7 )
V_7 = V_38 ;
if ( V_37 ) {
if ( ! V_8 ) {
F_28 ( L_5 ) ;
return - V_11 ;
}
F_22 ( & V_27 ) ;
V_10 = F_16 ( V_8 , V_7 ) ;
if ( ! V_10 ) {
F_26 ( & V_27 ) ;
F_28 ( L_6 , V_7 , V_8 ) ;
return - V_39 ;
}
F_18 ( V_10 ) ;
F_26 ( & V_27 ) ;
return 0 ;
}
if ( V_30 < 2 ) {
F_28 ( L_7 ) ;
return - V_11 ;
}
if ( isdigit ( V_31 [ 1 ] [ 0 ] ) ) {
F_28 ( L_8 ) ;
return - V_11 ;
}
V_32 = strchr ( V_31 [ 1 ] , ':' ) ;
if ( ! V_32 )
goto V_40;
* V_32 ++ = '\0' ;
V_24 = V_31 [ 1 ] ;
V_26 = F_29 ( V_24 , V_41 , & V_35 ) ;
if ( V_26 )
goto V_40;
V_23 = F_30 ( V_35 . V_42 -> V_43 ) ;
F_31 ( & V_35 ) ;
if ( ! V_23 || ! F_32 ( V_23 -> V_44 ) ) {
V_26 = - V_11 ;
goto V_40;
}
V_26 = F_33 ( V_32 , 0 , & V_36 ) ;
if ( V_26 )
goto V_40;
V_30 -= 2 ;
V_31 += 2 ;
if ( ! V_8 ) {
char * V_45 ;
char * V_46 ;
V_45 = F_11 ( F_34 ( V_24 ) , V_12 ) ;
if ( ! V_45 ) {
V_26 = - V_13 ;
goto V_40;
}
V_46 = strpbrk ( V_45 , L_9 ) ;
if ( V_46 )
* V_46 = '\0' ;
snprintf ( V_33 , V_34 , L_10 , 'p' , V_45 , V_36 ) ;
V_8 = V_33 ;
F_12 ( V_45 ) ;
}
V_10 = F_6 ( V_7 , V_8 , V_30 ) ;
if ( F_35 ( V_10 ) ) {
F_28 ( L_11 , ( int ) F_36 ( V_10 ) ) ;
V_26 = F_36 ( V_10 ) ;
goto V_40;
}
V_10 -> V_36 = V_36 ;
V_10 -> V_23 = V_23 ;
V_10 -> V_24 = F_11 ( V_24 , V_12 ) ;
if ( ! V_10 -> V_24 ) {
F_28 ( L_12 ) ;
V_26 = - V_13 ;
goto error;
}
V_26 = 0 ;
for ( V_21 = 0 ; V_21 < V_30 && V_21 < V_47 ; V_21 ++ ) {
V_10 -> V_22 ++ ;
V_32 = strchr ( V_31 [ V_21 ] , '=' ) ;
if ( V_32 ) {
* V_32 ++ = '\0' ;
V_10 -> args [ V_21 ] . V_16 = F_11 ( V_31 [ V_21 ] , V_12 ) ;
} else {
V_32 = V_31 [ V_21 ] ;
snprintf ( V_33 , V_34 , L_13 , V_21 + 1 ) ;
V_10 -> args [ V_21 ] . V_16 = F_11 ( V_33 , V_12 ) ;
}
if ( ! V_10 -> args [ V_21 ] . V_16 ) {
F_28 ( L_14 , V_21 ) ;
V_26 = - V_13 ;
goto error;
}
if ( ! F_7 ( V_10 -> args [ V_21 ] . V_16 ) ) {
F_28 ( L_15 , V_21 , V_10 -> args [ V_21 ] . V_16 ) ;
V_26 = - V_11 ;
goto error;
}
if ( F_37 ( V_10 -> args [ V_21 ] . V_16 , V_10 -> args , V_21 ) ) {
F_28 ( L_16
L_17 , V_21 , V_31 [ V_21 ] ) ;
V_26 = - V_11 ;
goto error;
}
V_26 = F_38 ( V_32 , & V_10 -> V_48 , & V_10 -> args [ V_21 ] , false , false ) ;
if ( V_26 ) {
F_28 ( L_18 , V_21 , V_26 ) ;
goto error;
}
}
V_26 = F_21 ( V_10 ) ;
if ( V_26 )
goto error;
return 0 ;
error:
F_13 ( V_10 ) ;
return V_26 ;
V_40:
if ( V_23 )
F_15 ( V_23 ) ;
F_28 ( L_19 ) ;
return V_26 ;
}
static void F_39 ( void )
{
struct V_6 * V_10 ;
F_22 ( & V_27 ) ;
while ( ! F_5 ( & V_29 ) ) {
V_10 = F_40 ( V_29 . V_49 , struct V_6 , V_17 ) ;
F_18 ( V_10 ) ;
}
F_26 ( & V_27 ) ;
}
static void * F_41 ( struct V_50 * V_51 , T_1 * V_52 )
{
F_22 ( & V_27 ) ;
return F_42 ( & V_29 , * V_52 ) ;
}
static void * F_43 ( struct V_50 * V_51 , void * V_53 , T_1 * V_52 )
{
return F_44 ( V_53 , & V_29 , V_52 ) ;
}
static void F_45 ( struct V_50 * V_51 , void * V_53 )
{
F_26 ( & V_27 ) ;
}
static int F_46 ( struct V_50 * V_51 , void * V_53 )
{
struct V_6 * V_10 = V_53 ;
int V_21 ;
F_47 ( V_51 , L_20 , V_10 -> V_14 . V_15 -> system , V_10 -> V_14 . V_16 ) ;
F_47 ( V_51 , L_21 , V_10 -> V_24 , ( void * ) V_10 -> V_36 ) ;
for ( V_21 = 0 ; V_21 < V_10 -> V_22 ; V_21 ++ )
F_47 ( V_51 , L_22 , V_10 -> args [ V_21 ] . V_16 , V_10 -> args [ V_21 ] . V_54 ) ;
F_47 ( V_51 , L_23 ) ;
return 0 ;
}
static int F_48 ( struct V_23 * V_23 , struct V_55 * V_55 )
{
if ( ( V_55 -> V_56 & V_57 ) && ( V_55 -> V_58 & V_59 ) )
F_39 () ;
return F_49 ( V_55 , & V_60 ) ;
}
static T_2 F_50 ( struct V_55 * V_55 , const char T_3 * V_61 ,
T_4 V_62 , T_1 * V_63 )
{
return F_51 ( V_55 , V_61 , V_62 , V_63 , F_27 ) ;
}
static int F_52 ( struct V_50 * V_51 , void * V_53 )
{
struct V_6 * V_10 = V_53 ;
F_47 ( V_51 , L_24 , V_10 -> V_24 , V_10 -> V_14 . V_16 , V_10 -> V_64 ) ;
return 0 ;
}
static int F_53 ( struct V_23 * V_23 , struct V_55 * V_55 )
{
return F_49 ( V_55 , & V_65 ) ;
}
static int F_54 ( struct V_6 * V_10 , struct V_66 * V_67 )
{
struct V_68 * V_69 ;
struct V_70 * V_8 ;
struct V_71 * V_61 ;
T_5 * V_72 ;
int V_48 , V_21 , V_73 ;
unsigned long V_74 ;
struct V_75 * V_14 = & V_10 -> V_14 ;
F_55 ( V_74 ) ;
V_73 = F_56 () ;
V_48 = sizeof( * V_69 ) + V_10 -> V_48 ;
V_8 = F_57 ( & V_61 , V_14 -> V_8 . type ,
V_48 , V_74 , V_73 ) ;
if ( ! V_8 )
return 0 ;
V_69 = F_58 ( V_8 ) ;
V_69 -> V_76 = F_59 ( F_60 ( V_77 ) ) ;
V_72 = ( T_5 * ) & V_69 [ 1 ] ;
for ( V_21 = 0 ; V_21 < V_10 -> V_22 ; V_21 ++ )
F_61 ( & V_10 -> args [ V_21 ] . V_78 , V_67 , V_72 + V_10 -> args [ V_21 ] . V_36 ) ;
if ( ! F_62 ( V_61 , V_14 , V_69 , V_8 ) )
F_63 ( V_61 , V_8 , V_74 , V_73 ) ;
return 0 ;
}
static enum V_79
F_64 ( struct V_80 * V_81 , int V_82 , struct V_83 * V_8 )
{
struct V_68 * V_84 ;
struct V_85 * V_86 = & V_81 -> V_87 ;
struct V_6 * V_10 ;
T_5 * V_72 ;
int V_21 ;
V_84 = (struct V_68 * ) V_81 -> V_88 ;
V_10 = F_65 ( V_8 , struct V_6 , V_14 . V_8 ) ;
if ( ! F_66 ( V_86 , L_25 , V_10 -> V_14 . V_16 ) )
goto V_89;
if ( ! F_67 ( V_86 , V_84 -> V_76 , V_82 | V_90 ) )
goto V_89;
if ( ! F_68 ( V_86 , L_26 ) )
goto V_89;
V_72 = ( T_5 * ) & V_84 [ 1 ] ;
for ( V_21 = 0 ; V_21 < V_10 -> V_22 ; V_21 ++ ) {
if ( ! V_10 -> args [ V_21 ] . type -> V_91 ( V_86 , V_10 -> args [ V_21 ] . V_16 ,
V_72 + V_10 -> args [ V_21 ] . V_36 , V_84 ) )
goto V_89;
}
if ( F_68 ( V_86 , L_23 ) )
return V_92 ;
V_89:
return V_93 ;
}
static inline bool F_69 ( struct V_6 * V_10 )
{
return V_10 -> V_82 & ( V_94 | V_95 ) ;
}
static int
F_70 ( struct V_6 * V_10 , int V_96 , T_6 V_2 )
{
int V_26 = 0 ;
if ( F_69 ( V_10 ) )
return - V_97 ;
F_71 ( ! F_4 ( & V_10 -> V_2 ) ) ;
V_10 -> V_82 |= V_96 ;
V_10 -> V_18 . V_2 = V_2 ;
V_26 = F_72 ( V_10 -> V_23 , V_10 -> V_36 , & V_10 -> V_18 ) ;
if ( V_26 )
V_10 -> V_82 &= ~ V_96 ;
return V_26 ;
}
static void F_73 ( struct V_6 * V_10 , int V_96 )
{
if ( ! F_69 ( V_10 ) )
return;
F_71 ( ! F_4 ( & V_10 -> V_2 ) ) ;
F_74 ( V_10 -> V_23 , V_10 -> V_36 , & V_10 -> V_18 ) ;
V_10 -> V_82 &= ~ V_96 ;
}
static int F_75 ( struct V_75 * V_98 )
{
int V_26 , V_21 ;
struct V_68 V_84 ;
struct V_6 * V_10 = (struct V_6 * ) V_98 -> V_72 ;
F_76 (unsigned long, ip, FIELD_STRING_IP, 0 ) ;
for ( V_21 = 0 ; V_21 < V_10 -> V_22 ; V_21 ++ ) {
V_26 = F_77 ( V_98 , V_10 -> args [ V_21 ] . type -> V_99 ,
V_10 -> args [ V_21 ] . V_16 ,
sizeof( V_84 ) + V_10 -> args [ V_21 ] . V_36 ,
V_10 -> args [ V_21 ] . type -> V_48 ,
V_10 -> args [ V_21 ] . type -> V_100 ,
V_101 ) ;
if ( V_26 )
return V_26 ;
}
return 0 ;
}
static int F_78 ( struct V_6 * V_10 , char * V_33 , int V_102 )
{
const char * V_103 , * V_32 ;
int V_21 ;
int V_52 = 0 ;
V_103 = L_27 ;
V_32 = L_28 V_104 ;
V_52 += snprintf ( V_33 + V_52 , V_105 , L_29 , V_103 ) ;
for ( V_21 = 0 ; V_21 < V_10 -> V_22 ; V_21 ++ ) {
V_52 += snprintf ( V_33 + V_52 , V_105 , L_22 ,
V_10 -> args [ V_21 ] . V_16 , V_10 -> args [ V_21 ] . type -> V_103 ) ;
}
V_52 += snprintf ( V_33 + V_52 , V_105 , L_30 , V_32 ) ;
for ( V_21 = 0 ; V_21 < V_10 -> V_22 ; V_21 ++ ) {
V_52 += snprintf ( V_33 + V_52 , V_105 , L_31 ,
V_10 -> args [ V_21 ] . V_16 ) ;
}
return V_52 ;
}
static int F_79 ( struct V_6 * V_10 )
{
char * V_106 ;
int V_102 ;
V_102 = F_78 ( V_10 , NULL , 0 ) ;
V_106 = F_80 ( V_102 + 1 , V_12 ) ;
if ( ! V_106 )
return - V_13 ;
F_78 ( V_10 , V_106 , V_102 + 1 ) ;
V_10 -> V_14 . V_106 = V_106 ;
return 0 ;
}
static bool
F_81 ( struct V_1 * V_2 , struct V_107 * V_108 )
{
struct V_109 * V_8 ;
if ( V_2 -> V_4 )
return true ;
F_17 (event, &filter->perf_events, hw.tp_list) {
if ( V_8 -> V_110 . V_111 -> V_108 == V_108 )
return true ;
}
return false ;
}
static inline bool
F_82 ( struct V_6 * V_10 , struct V_109 * V_8 )
{
return F_81 ( & V_10 -> V_2 , V_8 -> V_110 . V_111 -> V_108 ) ;
}
static int F_83 ( struct V_6 * V_10 , struct V_109 * V_8 )
{
bool V_112 ;
F_84 ( & V_10 -> V_2 . V_3 ) ;
if ( V_8 -> V_110 . V_111 ) {
V_112 = V_10 -> V_2 . V_4 ||
V_8 -> V_113 || V_8 -> V_114 . V_115 ||
F_82 ( V_10 , V_8 ) ;
F_85 ( & V_8 -> V_110 . V_116 , & V_10 -> V_2 . V_5 ) ;
} else {
V_112 = V_10 -> V_2 . V_4 ;
V_10 -> V_2 . V_4 ++ ;
}
F_86 ( & V_10 -> V_2 . V_3 ) ;
if ( ! V_112 )
F_87 ( V_10 -> V_23 , V_10 -> V_36 , & V_10 -> V_18 , true ) ;
return 0 ;
}
static int F_88 ( struct V_6 * V_10 , struct V_109 * V_8 )
{
bool V_112 ;
F_84 ( & V_10 -> V_2 . V_3 ) ;
if ( V_8 -> V_110 . V_111 ) {
F_19 ( & V_8 -> V_110 . V_116 ) ;
V_112 = V_10 -> V_2 . V_4 ||
( V_8 -> V_110 . V_111 -> V_82 & V_117 ) ||
F_82 ( V_10 , V_8 ) ;
} else {
V_10 -> V_2 . V_4 -- ;
V_112 = V_10 -> V_2 . V_4 ;
}
F_86 ( & V_10 -> V_2 . V_3 ) ;
if ( ! V_112 )
F_87 ( V_10 -> V_23 , V_10 -> V_36 , & V_10 -> V_18 , false ) ;
return 0 ;
}
static bool F_89 ( struct V_118 * V_119 ,
enum V_120 V_121 , struct V_107 * V_108 )
{
struct V_6 * V_10 ;
int V_26 ;
V_10 = F_65 ( V_119 , struct V_6 , V_18 ) ;
F_90 ( & V_10 -> V_2 . V_3 ) ;
V_26 = F_81 ( & V_10 -> V_2 , V_108 ) ;
F_91 ( & V_10 -> V_2 . V_3 ) ;
return V_26 ;
}
static int F_92 ( struct V_6 * V_10 , struct V_66 * V_67 )
{
struct V_75 * V_14 = & V_10 -> V_14 ;
struct V_68 * V_69 ;
struct V_122 * V_123 ;
T_5 * V_72 ;
int V_48 , V_124 , V_21 ;
int V_125 ;
if ( ! F_89 ( & V_10 -> V_18 , 0 , V_77 -> V_108 ) )
return V_126 ;
V_124 = sizeof( * V_69 ) + V_10 -> V_48 ;
V_48 = F_93 ( V_124 + sizeof( V_127 ) , sizeof( V_128 ) ) ;
V_48 -= sizeof( V_127 ) ;
if ( F_94 ( V_48 > V_129 , L_32 ) )
return 0 ;
F_95 () ;
V_69 = F_96 ( V_48 , V_14 -> V_8 . type , V_67 , & V_125 ) ;
if ( ! V_69 )
goto V_130;
V_69 -> V_76 = F_59 ( F_60 ( V_77 ) ) ;
V_72 = ( T_5 * ) & V_69 [ 1 ] ;
for ( V_21 = 0 ; V_21 < V_10 -> V_22 ; V_21 ++ )
F_61 ( & V_10 -> args [ V_21 ] . V_78 , V_67 , V_72 + V_10 -> args [ V_21 ] . V_36 ) ;
V_123 = F_97 ( V_14 -> V_5 ) ;
F_98 ( V_69 , V_48 , V_125 , V_69 -> V_76 , 1 , V_67 , V_123 , NULL ) ;
V_130:
F_99 () ;
return 0 ;
}
static
int F_100 ( struct V_75 * V_8 , enum V_131 type , void * V_72 )
{
struct V_6 * V_10 = (struct V_6 * ) V_8 -> V_72 ;
switch ( type ) {
case V_132 :
return F_70 ( V_10 , V_94 , NULL ) ;
case V_133 :
F_73 ( V_10 , V_94 ) ;
return 0 ;
#ifdef F_101
case V_134 :
return F_70 ( V_10 , V_95 , F_89 ) ;
case V_135 :
F_73 ( V_10 , V_95 ) ;
return 0 ;
case V_136 :
return F_83 ( V_10 , V_72 ) ;
case V_137 :
return F_88 ( V_10 , V_72 ) ;
#endif
default:
return 0 ;
}
return 0 ;
}
static int V_20 ( struct V_118 * V_138 , struct V_66 * V_67 )
{
struct V_6 * V_10 ;
int V_26 = 0 ;
V_10 = F_65 ( V_138 , struct V_6 , V_18 ) ;
V_10 -> V_64 ++ ;
if ( V_10 -> V_82 & V_94 )
V_26 |= F_54 ( V_10 , V_67 ) ;
#ifdef F_101
if ( V_10 -> V_82 & V_95 )
V_26 |= F_92 ( V_10 , V_67 ) ;
#endif
return V_26 ;
}
static int F_23 ( struct V_6 * V_10 )
{
struct V_75 * V_14 = & V_10 -> V_14 ;
int V_26 ;
F_3 ( & V_14 -> V_15 -> V_139 ) ;
V_14 -> V_8 . V_140 = & V_141 ;
V_14 -> V_15 -> V_142 = F_75 ;
if ( F_79 ( V_10 ) < 0 )
return - V_13 ;
V_26 = F_102 ( & V_14 -> V_8 ) ;
if ( ! V_26 ) {
F_12 ( V_14 -> V_106 ) ;
return - V_143 ;
}
V_14 -> V_82 = 0 ;
V_14 -> V_15 -> V_144 = F_100 ;
V_14 -> V_72 = V_10 ;
V_26 = F_103 ( V_14 ) ;
if ( V_26 ) {
F_28 ( L_33 , V_14 -> V_16 ) ;
F_12 ( V_14 -> V_106 ) ;
F_104 ( & V_14 -> V_8 ) ;
}
return V_26 ;
}
static void F_20 ( struct V_6 * V_10 )
{
F_105 ( & V_10 -> V_14 ) ;
F_12 ( V_10 -> V_14 . V_106 ) ;
V_10 -> V_14 . V_106 = NULL ;
}
static T_7 int F_106 ( void )
{
struct V_42 * V_145 ;
V_145 = F_107 () ;
if ( ! V_145 )
return 0 ;
F_108 ( L_34 , 0644 , V_145 ,
NULL , & V_146 ) ;
F_108 ( L_35 , 0444 , V_145 ,
NULL , & V_147 ) ;
return 0 ;
}
