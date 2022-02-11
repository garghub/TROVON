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
static inline bool F_6 ( struct V_6 * V_7 )
{
return V_7 -> V_8 . V_9 != NULL ;
}
static struct V_6 *
F_7 ( const char * V_10 , const char * V_11 , int V_12 , bool V_13 )
{
struct V_6 * V_7 ;
if ( ! V_11 || ! F_8 ( V_11 ) )
return F_9 ( - V_14 ) ;
if ( ! V_10 || ! F_8 ( V_10 ) )
return F_9 ( - V_14 ) ;
V_7 = F_10 ( F_11 ( V_12 ) , V_15 ) ;
if ( ! V_7 )
return F_9 ( - V_16 ) ;
V_7 -> V_17 . V_18 = & V_7 -> V_18 ;
V_7 -> V_17 . V_19 = F_12 ( V_11 , V_15 ) ;
if ( ! V_7 -> V_17 . V_19 )
goto error;
V_7 -> V_18 . system = F_12 ( V_10 , V_15 ) ;
if ( ! V_7 -> V_18 . system )
goto error;
F_3 ( & V_7 -> V_20 ) ;
V_7 -> V_8 . V_21 = V_22 ;
if ( V_13 )
V_7 -> V_8 . V_9 = V_23 ;
F_1 ( & V_7 -> V_2 ) ;
return V_7 ;
error:
F_13 ( V_7 -> V_17 . V_19 ) ;
F_13 ( V_7 ) ;
return F_9 ( - V_16 ) ;
}
static void F_14 ( struct V_6 * V_7 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_7 -> V_25 ; V_24 ++ )
F_15 ( & V_7 -> args [ V_24 ] ) ;
F_16 ( V_7 -> V_26 ) ;
F_13 ( V_7 -> V_17 . V_18 -> system ) ;
F_13 ( V_7 -> V_17 . V_19 ) ;
F_13 ( V_7 -> V_27 ) ;
F_13 ( V_7 ) ;
}
static struct V_6 * F_17 ( const char * V_11 , const char * V_10 )
{
struct V_6 * V_7 ;
F_18 (tu, &uprobe_list, list)
if ( strcmp ( V_7 -> V_17 . V_19 , V_11 ) == 0 &&
strcmp ( V_7 -> V_17 . V_18 -> system , V_10 ) == 0 )
return V_7 ;
return NULL ;
}
static void F_19 ( struct V_6 * V_7 )
{
F_20 ( & V_7 -> V_20 ) ;
F_21 ( V_7 ) ;
F_14 ( V_7 ) ;
}
static int F_22 ( struct V_6 * V_7 )
{
struct V_6 * V_28 ;
int V_29 ;
F_23 ( & V_30 ) ;
V_28 = F_17 ( V_7 -> V_17 . V_19 , V_7 -> V_17 . V_18 -> system ) ;
if ( V_28 )
F_19 ( V_28 ) ;
V_29 = F_24 ( V_7 ) ;
if ( V_29 ) {
F_25 ( L_1 , V_29 ) ;
goto V_31;
}
F_26 ( & V_7 -> V_20 , & V_32 ) ;
V_31:
F_27 ( & V_30 ) ;
return V_29 ;
}
static int F_28 ( int V_33 , char * * V_34 )
{
struct V_6 * V_7 ;
struct V_26 * V_26 ;
char * V_35 , * V_11 , * V_10 , * V_27 ;
char V_36 [ V_37 ] ;
struct V_38 V_38 ;
unsigned long V_39 ;
bool V_40 , V_41 ;
int V_24 , V_29 ;
V_26 = NULL ;
V_29 = 0 ;
V_40 = false ;
V_41 = false ;
V_11 = NULL ;
V_10 = NULL ;
if ( V_34 [ 0 ] [ 0 ] == '-' )
V_40 = true ;
else if ( V_34 [ 0 ] [ 0 ] == 'r' )
V_41 = true ;
else if ( V_34 [ 0 ] [ 0 ] != 'p' ) {
F_29 ( L_2 ) ;
return - V_14 ;
}
if ( V_34 [ 0 ] [ 1 ] == ':' ) {
V_11 = & V_34 [ 0 ] [ 2 ] ;
V_35 = strchr ( V_11 , '/' ) ;
if ( V_35 ) {
V_10 = V_11 ;
V_11 = V_35 + 1 ;
V_11 [ - 1 ] = '\0' ;
if ( strlen ( V_10 ) == 0 ) {
F_29 ( L_3 ) ;
return - V_14 ;
}
}
if ( strlen ( V_11 ) == 0 ) {
F_29 ( L_4 ) ;
return - V_14 ;
}
}
if ( ! V_10 )
V_10 = V_42 ;
if ( V_40 ) {
if ( ! V_11 ) {
F_29 ( L_5 ) ;
return - V_14 ;
}
F_23 ( & V_30 ) ;
V_7 = F_17 ( V_11 , V_10 ) ;
if ( ! V_7 ) {
F_27 ( & V_30 ) ;
F_29 ( L_6 , V_10 , V_11 ) ;
return - V_43 ;
}
F_19 ( V_7 ) ;
F_27 ( & V_30 ) ;
return 0 ;
}
if ( V_33 < 2 ) {
F_29 ( L_7 ) ;
return - V_14 ;
}
if ( isdigit ( V_34 [ 1 ] [ 0 ] ) ) {
F_29 ( L_8 ) ;
return - V_14 ;
}
V_35 = strchr ( V_34 [ 1 ] , ':' ) ;
if ( ! V_35 )
goto V_44;
* V_35 ++ = '\0' ;
V_27 = V_34 [ 1 ] ;
V_29 = F_30 ( V_27 , V_45 , & V_38 ) ;
if ( V_29 )
goto V_44;
V_26 = F_31 ( V_38 . V_46 -> V_47 ) ;
F_32 ( & V_38 ) ;
if ( ! V_26 || ! F_33 ( V_26 -> V_48 ) ) {
V_29 = - V_14 ;
goto V_44;
}
V_29 = F_34 ( V_35 , 0 , & V_39 ) ;
if ( V_29 )
goto V_44;
V_33 -= 2 ;
V_34 += 2 ;
if ( ! V_11 ) {
char * V_49 ;
char * V_50 ;
V_49 = F_12 ( F_35 ( V_27 ) , V_15 ) ;
if ( ! V_49 ) {
V_29 = - V_16 ;
goto V_44;
}
V_50 = strpbrk ( V_49 , L_9 ) ;
if ( V_50 )
* V_50 = '\0' ;
snprintf ( V_36 , V_37 , L_10 , 'p' , V_49 , V_39 ) ;
V_11 = V_36 ;
F_13 ( V_49 ) ;
}
V_7 = F_7 ( V_10 , V_11 , V_33 , V_41 ) ;
if ( F_36 ( V_7 ) ) {
F_29 ( L_11 , ( int ) F_37 ( V_7 ) ) ;
V_29 = F_37 ( V_7 ) ;
goto V_44;
}
V_7 -> V_39 = V_39 ;
V_7 -> V_26 = V_26 ;
V_7 -> V_27 = F_12 ( V_27 , V_15 ) ;
if ( ! V_7 -> V_27 ) {
F_29 ( L_12 ) ;
V_29 = - V_16 ;
goto error;
}
V_29 = 0 ;
for ( V_24 = 0 ; V_24 < V_33 && V_24 < V_51 ; V_24 ++ ) {
V_7 -> V_25 ++ ;
V_35 = strchr ( V_34 [ V_24 ] , '=' ) ;
if ( V_35 ) {
* V_35 ++ = '\0' ;
V_7 -> args [ V_24 ] . V_19 = F_12 ( V_34 [ V_24 ] , V_15 ) ;
} else {
V_35 = V_34 [ V_24 ] ;
snprintf ( V_36 , V_37 , L_13 , V_24 + 1 ) ;
V_7 -> args [ V_24 ] . V_19 = F_12 ( V_36 , V_15 ) ;
}
if ( ! V_7 -> args [ V_24 ] . V_19 ) {
F_29 ( L_14 , V_24 ) ;
V_29 = - V_16 ;
goto error;
}
if ( ! F_8 ( V_7 -> args [ V_24 ] . V_19 ) ) {
F_29 ( L_15 , V_24 , V_7 -> args [ V_24 ] . V_19 ) ;
V_29 = - V_14 ;
goto error;
}
if ( F_38 ( V_7 -> args [ V_24 ] . V_19 , V_7 -> args , V_24 ) ) {
F_29 ( L_16
L_17 , V_24 , V_34 [ V_24 ] ) ;
V_29 = - V_14 ;
goto error;
}
V_29 = F_39 ( V_35 , & V_7 -> V_52 , & V_7 -> args [ V_24 ] , false , false ) ;
if ( V_29 ) {
F_29 ( L_18 , V_24 , V_29 ) ;
goto error;
}
}
V_29 = F_22 ( V_7 ) ;
if ( V_29 )
goto error;
return 0 ;
error:
F_14 ( V_7 ) ;
return V_29 ;
V_44:
if ( V_26 )
F_16 ( V_26 ) ;
F_29 ( L_19 ) ;
return V_29 ;
}
static void F_40 ( void )
{
struct V_6 * V_7 ;
F_23 ( & V_30 ) ;
while ( ! F_5 ( & V_32 ) ) {
V_7 = F_41 ( V_32 . V_53 , struct V_6 , V_20 ) ;
F_19 ( V_7 ) ;
}
F_27 ( & V_30 ) ;
}
static void * F_42 ( struct V_54 * V_55 , T_1 * V_56 )
{
F_23 ( & V_30 ) ;
return F_43 ( & V_32 , * V_56 ) ;
}
static void * F_44 ( struct V_54 * V_55 , void * V_57 , T_1 * V_56 )
{
return F_45 ( V_57 , & V_32 , V_56 ) ;
}
static void F_46 ( struct V_54 * V_55 , void * V_57 )
{
F_27 ( & V_30 ) ;
}
static int F_47 ( struct V_54 * V_55 , void * V_57 )
{
struct V_6 * V_7 = V_57 ;
char V_58 = F_6 ( V_7 ) ? 'r' : 'p' ;
int V_24 ;
F_48 ( V_55 , L_20 , V_58 , V_7 -> V_17 . V_18 -> system , V_7 -> V_17 . V_19 ) ;
F_48 ( V_55 , L_21 , V_7 -> V_27 , ( void * ) V_7 -> V_39 ) ;
for ( V_24 = 0 ; V_24 < V_7 -> V_25 ; V_24 ++ )
F_48 ( V_55 , L_22 , V_7 -> args [ V_24 ] . V_19 , V_7 -> args [ V_24 ] . V_59 ) ;
F_48 ( V_55 , L_23 ) ;
return 0 ;
}
static int F_49 ( struct V_26 * V_26 , struct V_60 * V_60 )
{
if ( ( V_60 -> V_61 & V_62 ) && ( V_60 -> V_63 & V_64 ) )
F_40 () ;
return F_50 ( V_60 , & V_65 ) ;
}
static T_2 F_51 ( struct V_60 * V_60 , const char T_3 * V_66 ,
T_4 V_67 , T_1 * V_68 )
{
return F_52 ( V_60 , V_66 , V_67 , V_68 , F_28 ) ;
}
static int F_53 ( struct V_54 * V_55 , void * V_57 )
{
struct V_6 * V_7 = V_57 ;
F_48 ( V_55 , L_24 , V_7 -> V_27 , V_7 -> V_17 . V_19 , V_7 -> V_69 ) ;
return 0 ;
}
static int F_54 ( struct V_26 * V_26 , struct V_60 * V_60 )
{
return F_50 ( V_60 , & V_70 ) ;
}
static void F_55 ( struct V_6 * V_7 ,
unsigned long V_71 , struct V_72 * V_73 )
{
struct V_74 * V_75 ;
struct V_76 * V_11 ;
struct V_77 * V_66 ;
void * V_78 ;
int V_52 , V_24 ;
struct V_79 * V_17 = & V_7 -> V_17 ;
V_52 = F_56 ( F_6 ( V_7 ) ) ;
V_11 = F_57 ( & V_66 , V_17 -> V_11 . type ,
V_52 + V_7 -> V_52 , 0 , 0 ) ;
if ( ! V_11 )
return;
V_75 = F_58 ( V_11 ) ;
if ( F_6 ( V_7 ) ) {
V_75 -> V_80 [ 0 ] = V_71 ;
V_75 -> V_80 [ 1 ] = F_59 ( V_73 ) ;
V_78 = F_60 ( V_75 , true ) ;
} else {
V_75 -> V_80 [ 0 ] = F_59 ( V_73 ) ;
V_78 = F_60 ( V_75 , false ) ;
}
for ( V_24 = 0 ; V_24 < V_7 -> V_25 ; V_24 ++ )
F_61 ( & V_7 -> args [ V_24 ] . V_81 , V_73 , V_78 + V_7 -> args [ V_24 ] . V_39 ) ;
if ( ! F_62 ( V_66 , V_17 , V_75 , V_11 ) )
F_63 ( V_66 , V_11 , 0 , 0 ) ;
}
static int F_64 ( struct V_6 * V_7 , struct V_72 * V_73 )
{
if ( ! F_6 ( V_7 ) )
F_55 ( V_7 , 0 , V_73 ) ;
return 0 ;
}
static void F_65 ( struct V_6 * V_7 , unsigned long V_71 ,
struct V_72 * V_73 )
{
F_55 ( V_7 , V_71 , V_73 ) ;
}
static enum V_82
F_66 ( struct V_83 * V_84 , int V_85 , struct V_86 * V_11 )
{
struct V_74 * V_75 ;
struct V_87 * V_88 = & V_84 -> V_89 ;
struct V_6 * V_7 ;
T_5 * V_78 ;
int V_24 ;
V_75 = (struct V_74 * ) V_84 -> V_90 ;
V_7 = F_67 ( V_11 , struct V_6 , V_17 . V_11 ) ;
if ( F_6 ( V_7 ) ) {
if ( ! F_68 ( V_88 , L_25 , V_7 -> V_17 . V_19 ,
V_75 -> V_80 [ 1 ] , V_75 -> V_80 [ 0 ] ) )
goto V_91;
V_78 = F_60 ( V_75 , true ) ;
} else {
if ( ! F_68 ( V_88 , L_26 , V_7 -> V_17 . V_19 ,
V_75 -> V_80 [ 0 ] ) )
goto V_91;
V_78 = F_60 ( V_75 , false ) ;
}
for ( V_24 = 0 ; V_24 < V_7 -> V_25 ; V_24 ++ ) {
if ( ! V_7 -> args [ V_24 ] . type -> V_92 ( V_88 , V_7 -> args [ V_24 ] . V_19 ,
V_78 + V_7 -> args [ V_24 ] . V_39 , V_75 ) )
goto V_91;
}
if ( F_69 ( V_88 , L_23 ) )
return V_93 ;
V_91:
return V_94 ;
}
static inline bool F_70 ( struct V_6 * V_7 )
{
return V_7 -> V_85 & ( V_95 | V_96 ) ;
}
static int
F_71 ( struct V_6 * V_7 , int V_97 , T_6 V_2 )
{
int V_29 = 0 ;
if ( F_70 ( V_7 ) )
return - V_98 ;
F_72 ( ! F_4 ( & V_7 -> V_2 ) ) ;
V_7 -> V_85 |= V_97 ;
V_7 -> V_8 . V_2 = V_2 ;
V_29 = F_73 ( V_7 -> V_26 , V_7 -> V_39 , & V_7 -> V_8 ) ;
if ( V_29 )
V_7 -> V_85 &= ~ V_97 ;
return V_29 ;
}
static void F_74 ( struct V_6 * V_7 , int V_97 )
{
if ( ! F_70 ( V_7 ) )
return;
F_72 ( ! F_4 ( & V_7 -> V_2 ) ) ;
F_75 ( V_7 -> V_26 , V_7 -> V_39 , & V_7 -> V_8 ) ;
V_7 -> V_85 &= ~ V_97 ;
}
static int F_76 ( struct V_79 * V_99 )
{
int V_29 , V_24 , V_52 ;
struct V_74 V_100 ;
struct V_6 * V_7 = V_99 -> V_78 ;
if ( F_6 ( V_7 ) ) {
F_77 (unsigned long, vaddr[0], FIELD_STRING_FUNC, 0 ) ;
F_77 (unsigned long, vaddr[1], FIELD_STRING_RETIP, 0 ) ;
V_52 = F_56 ( true ) ;
} else {
F_77 (unsigned long, vaddr[0], FIELD_STRING_IP, 0 ) ;
V_52 = F_56 ( false ) ;
}
for ( V_24 = 0 ; V_24 < V_7 -> V_25 ; V_24 ++ ) {
V_29 = F_78 ( V_99 , V_7 -> args [ V_24 ] . type -> V_101 ,
V_7 -> args [ V_24 ] . V_19 ,
V_52 + V_7 -> args [ V_24 ] . V_39 ,
V_7 -> args [ V_24 ] . type -> V_52 ,
V_7 -> args [ V_24 ] . type -> V_102 ,
V_103 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int F_79 ( struct V_6 * V_7 , char * V_36 , int V_104 )
{
const char * V_105 , * V_35 ;
int V_24 ;
int V_56 = 0 ;
if ( F_6 ( V_7 ) ) {
V_105 = L_27 ;
V_35 = L_28 V_106 L_29 V_107 ;
} else {
V_105 = L_30 ;
V_35 = L_28 V_108 ;
}
V_56 += snprintf ( V_36 + V_56 , V_109 , L_31 , V_105 ) ;
for ( V_24 = 0 ; V_24 < V_7 -> V_25 ; V_24 ++ ) {
V_56 += snprintf ( V_36 + V_56 , V_109 , L_22 ,
V_7 -> args [ V_24 ] . V_19 , V_7 -> args [ V_24 ] . type -> V_105 ) ;
}
V_56 += snprintf ( V_36 + V_56 , V_109 , L_32 , V_35 ) ;
for ( V_24 = 0 ; V_24 < V_7 -> V_25 ; V_24 ++ ) {
V_56 += snprintf ( V_36 + V_56 , V_109 , L_33 ,
V_7 -> args [ V_24 ] . V_19 ) ;
}
return V_56 ;
}
static int F_80 ( struct V_6 * V_7 )
{
char * V_110 ;
int V_104 ;
V_104 = F_79 ( V_7 , NULL , 0 ) ;
V_110 = F_81 ( V_104 + 1 , V_15 ) ;
if ( ! V_110 )
return - V_16 ;
F_79 ( V_7 , V_110 , V_104 + 1 ) ;
V_7 -> V_17 . V_110 = V_110 ;
return 0 ;
}
static bool
F_82 ( struct V_1 * V_2 , struct V_111 * V_112 )
{
struct V_113 * V_11 ;
if ( V_2 -> V_4 )
return true ;
F_18 (event, &filter->perf_events, hw.tp_list) {
if ( V_11 -> V_114 . V_115 -> V_112 == V_112 )
return true ;
}
return false ;
}
static inline bool
F_83 ( struct V_6 * V_7 , struct V_113 * V_11 )
{
return F_82 ( & V_7 -> V_2 , V_11 -> V_114 . V_115 -> V_112 ) ;
}
static int F_84 ( struct V_6 * V_7 , struct V_113 * V_11 )
{
bool V_116 ;
F_85 ( & V_7 -> V_2 . V_3 ) ;
if ( V_11 -> V_114 . V_115 ) {
V_116 = V_7 -> V_2 . V_4 ||
V_11 -> V_117 || V_11 -> V_118 . V_119 ||
F_83 ( V_7 , V_11 ) ;
F_86 ( & V_11 -> V_114 . V_120 , & V_7 -> V_2 . V_5 ) ;
} else {
V_116 = V_7 -> V_2 . V_4 ;
V_7 -> V_2 . V_4 ++ ;
}
F_87 ( & V_7 -> V_2 . V_3 ) ;
if ( ! V_116 )
F_88 ( V_7 -> V_26 , V_7 -> V_39 , & V_7 -> V_8 , true ) ;
return 0 ;
}
static int F_89 ( struct V_6 * V_7 , struct V_113 * V_11 )
{
bool V_116 ;
F_85 ( & V_7 -> V_2 . V_3 ) ;
if ( V_11 -> V_114 . V_115 ) {
F_20 ( & V_11 -> V_114 . V_120 ) ;
V_116 = V_7 -> V_2 . V_4 ||
( V_11 -> V_114 . V_115 -> V_85 & V_121 ) ||
F_83 ( V_7 , V_11 ) ;
} else {
V_7 -> V_2 . V_4 -- ;
V_116 = V_7 -> V_2 . V_4 ;
}
F_87 ( & V_7 -> V_2 . V_3 ) ;
if ( ! V_116 )
F_88 ( V_7 -> V_26 , V_7 -> V_39 , & V_7 -> V_8 , false ) ;
return 0 ;
}
static bool F_90 ( struct V_122 * V_123 ,
enum V_124 V_125 , struct V_111 * V_112 )
{
struct V_6 * V_7 ;
int V_29 ;
V_7 = F_67 ( V_123 , struct V_6 , V_8 ) ;
F_91 ( & V_7 -> V_2 . V_3 ) ;
V_29 = F_82 ( & V_7 -> V_2 , V_112 ) ;
F_92 ( & V_7 -> V_2 . V_3 ) ;
return V_29 ;
}
static void F_93 ( struct V_6 * V_7 ,
unsigned long V_71 , struct V_72 * V_73 )
{
struct V_79 * V_17 = & V_7 -> V_17 ;
struct V_74 * V_75 ;
struct V_126 * V_127 ;
void * V_78 ;
int V_52 , V_128 , V_24 ;
V_52 = F_56 ( F_6 ( V_7 ) ) ;
V_52 = F_94 ( V_52 + V_7 -> V_52 + sizeof( V_129 ) , sizeof( V_130 ) ) - sizeof( V_129 ) ;
if ( F_95 ( V_52 > V_131 , L_34 ) )
return;
F_96 () ;
V_127 = F_97 ( V_17 -> V_5 ) ;
if ( F_98 ( V_127 ) )
goto V_132;
V_75 = F_99 ( V_52 , V_17 -> V_11 . type , V_73 , & V_128 ) ;
if ( ! V_75 )
goto V_132;
if ( F_6 ( V_7 ) ) {
V_75 -> V_80 [ 0 ] = V_71 ;
V_75 -> V_80 [ 1 ] = F_59 ( V_73 ) ;
V_78 = F_60 ( V_75 , true ) ;
} else {
V_75 -> V_80 [ 0 ] = F_59 ( V_73 ) ;
V_78 = F_60 ( V_75 , false ) ;
}
for ( V_24 = 0 ; V_24 < V_7 -> V_25 ; V_24 ++ )
F_61 ( & V_7 -> args [ V_24 ] . V_81 , V_73 , V_78 + V_7 -> args [ V_24 ] . V_39 ) ;
F_100 ( V_75 , V_52 , V_128 , 0 , 1 , V_73 , V_127 , NULL ) ;
V_132:
F_101 () ;
}
static int F_102 ( struct V_6 * V_7 , struct V_72 * V_73 )
{
if ( ! F_90 ( & V_7 -> V_8 , 0 , V_133 -> V_112 ) )
return V_134 ;
if ( ! F_6 ( V_7 ) )
F_93 ( V_7 , 0 , V_73 ) ;
return 0 ;
}
static void F_103 ( struct V_6 * V_7 , unsigned long V_71 ,
struct V_72 * V_73 )
{
F_93 ( V_7 , V_71 , V_73 ) ;
}
static
int F_104 ( struct V_79 * V_11 , enum V_135 type , void * V_78 )
{
struct V_6 * V_7 = V_11 -> V_78 ;
switch ( type ) {
case V_136 :
return F_71 ( V_7 , V_95 , NULL ) ;
case V_137 :
F_74 ( V_7 , V_95 ) ;
return 0 ;
#ifdef F_105
case V_138 :
return F_71 ( V_7 , V_96 , F_90 ) ;
case V_139 :
F_74 ( V_7 , V_96 ) ;
return 0 ;
case V_140 :
return F_84 ( V_7 , V_78 ) ;
case V_141 :
return F_89 ( V_7 , V_78 ) ;
#endif
default:
return 0 ;
}
return 0 ;
}
static int V_22 ( struct V_122 * V_142 , struct V_72 * V_73 )
{
struct V_6 * V_7 ;
int V_29 = 0 ;
V_7 = F_67 ( V_142 , struct V_6 , V_8 ) ;
V_7 -> V_69 ++ ;
if ( V_7 -> V_85 & V_95 )
V_29 |= F_64 ( V_7 , V_73 ) ;
#ifdef F_105
if ( V_7 -> V_85 & V_96 )
V_29 |= F_102 ( V_7 , V_73 ) ;
#endif
return V_29 ;
}
static int V_23 ( struct V_122 * V_142 ,
unsigned long V_71 , struct V_72 * V_73 )
{
struct V_6 * V_7 ;
V_7 = F_67 ( V_142 , struct V_6 , V_8 ) ;
if ( V_7 -> V_85 & V_95 )
F_65 ( V_7 , V_71 , V_73 ) ;
#ifdef F_105
if ( V_7 -> V_85 & V_96 )
F_103 ( V_7 , V_71 , V_73 ) ;
#endif
return 0 ;
}
static int F_24 ( struct V_6 * V_7 )
{
struct V_79 * V_17 = & V_7 -> V_17 ;
int V_29 ;
F_3 ( & V_17 -> V_18 -> V_143 ) ;
V_17 -> V_11 . V_144 = & V_145 ;
V_17 -> V_18 -> V_146 = F_76 ;
if ( F_80 ( V_7 ) < 0 )
return - V_16 ;
V_29 = F_106 ( & V_17 -> V_11 ) ;
if ( ! V_29 ) {
F_13 ( V_17 -> V_110 ) ;
return - V_147 ;
}
V_17 -> V_85 = 0 ;
V_17 -> V_18 -> V_148 = F_104 ;
V_17 -> V_78 = V_7 ;
V_29 = F_107 ( V_17 ) ;
if ( V_29 ) {
F_29 ( L_35 , V_17 -> V_19 ) ;
F_13 ( V_17 -> V_110 ) ;
F_108 ( & V_17 -> V_11 ) ;
}
return V_29 ;
}
static void F_21 ( struct V_6 * V_7 )
{
F_109 ( & V_7 -> V_17 ) ;
F_13 ( V_7 -> V_17 . V_110 ) ;
V_7 -> V_17 . V_110 = NULL ;
}
static T_7 int F_110 ( void )
{
struct V_46 * V_149 ;
V_149 = F_111 () ;
if ( ! V_149 )
return 0 ;
F_112 ( L_36 , 0644 , V_149 ,
NULL , & V_150 ) ;
F_112 ( L_37 , 0444 , V_149 ,
NULL , & V_151 ) ;
return 0 ;
}
