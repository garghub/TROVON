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
V_7 -> V_17 . V_24 |= V_25 ;
return V_7 ;
error:
F_13 ( V_7 -> V_17 . V_19 ) ;
F_13 ( V_7 ) ;
return F_9 ( - V_16 ) ;
}
static void F_14 ( struct V_6 * V_7 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_7 -> V_27 ; V_26 ++ )
F_15 ( & V_7 -> args [ V_26 ] ) ;
F_16 ( V_7 -> V_28 ) ;
F_13 ( V_7 -> V_17 . V_18 -> system ) ;
F_13 ( V_7 -> V_17 . V_19 ) ;
F_13 ( V_7 -> V_29 ) ;
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
static int F_19 ( struct V_6 * V_7 )
{
int V_30 ;
V_30 = F_20 ( V_7 ) ;
if ( V_30 )
return V_30 ;
F_21 ( & V_7 -> V_20 ) ;
F_14 ( V_7 ) ;
return 0 ;
}
static int F_22 ( struct V_6 * V_7 )
{
struct V_6 * V_31 ;
int V_30 ;
F_23 ( & V_32 ) ;
V_31 = F_17 ( V_7 -> V_17 . V_19 , V_7 -> V_17 . V_18 -> system ) ;
if ( V_31 ) {
V_30 = F_19 ( V_31 ) ;
if ( V_30 )
goto V_33;
}
V_30 = F_24 ( V_7 ) ;
if ( V_30 ) {
F_25 ( L_1 , V_30 ) ;
goto V_33;
}
F_26 ( & V_7 -> V_20 , & V_34 ) ;
V_33:
F_27 ( & V_32 ) ;
return V_30 ;
}
static int F_28 ( int V_35 , char * * V_36 )
{
struct V_6 * V_7 ;
struct V_28 * V_28 ;
char * V_37 , * V_11 , * V_10 , * V_29 ;
char V_38 [ V_39 ] ;
struct V_40 V_40 ;
unsigned long V_41 ;
bool V_42 , V_43 ;
int V_26 , V_30 ;
V_28 = NULL ;
V_30 = 0 ;
V_42 = false ;
V_43 = false ;
V_11 = NULL ;
V_10 = NULL ;
if ( V_36 [ 0 ] [ 0 ] == '-' )
V_42 = true ;
else if ( V_36 [ 0 ] [ 0 ] == 'r' )
V_43 = true ;
else if ( V_36 [ 0 ] [ 0 ] != 'p' ) {
F_29 ( L_2 ) ;
return - V_14 ;
}
if ( V_36 [ 0 ] [ 1 ] == ':' ) {
V_11 = & V_36 [ 0 ] [ 2 ] ;
V_37 = strchr ( V_11 , '/' ) ;
if ( V_37 ) {
V_10 = V_11 ;
V_11 = V_37 + 1 ;
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
V_10 = V_44 ;
if ( V_42 ) {
int V_30 ;
if ( ! V_11 ) {
F_29 ( L_5 ) ;
return - V_14 ;
}
F_23 ( & V_32 ) ;
V_7 = F_17 ( V_11 , V_10 ) ;
if ( ! V_7 ) {
F_27 ( & V_32 ) ;
F_29 ( L_6 , V_10 , V_11 ) ;
return - V_45 ;
}
V_30 = F_19 ( V_7 ) ;
F_27 ( & V_32 ) ;
return V_30 ;
}
if ( V_35 < 2 ) {
F_29 ( L_7 ) ;
return - V_14 ;
}
if ( isdigit ( V_36 [ 1 ] [ 0 ] ) ) {
F_29 ( L_8 ) ;
return - V_14 ;
}
V_37 = strchr ( V_36 [ 1 ] , ':' ) ;
if ( ! V_37 ) {
V_30 = - V_14 ;
goto V_46;
}
* V_37 ++ = '\0' ;
V_29 = V_36 [ 1 ] ;
V_30 = F_30 ( V_29 , V_47 , & V_40 ) ;
if ( V_30 )
goto V_46;
V_28 = F_31 ( V_40 . V_48 -> V_49 ) ;
F_32 ( & V_40 ) ;
if ( ! V_28 || ! F_33 ( V_28 -> V_50 ) ) {
V_30 = - V_14 ;
goto V_46;
}
V_30 = F_34 ( V_37 , 0 , & V_41 ) ;
if ( V_30 )
goto V_46;
V_35 -= 2 ;
V_36 += 2 ;
if ( ! V_11 ) {
char * V_51 ;
char * V_52 ;
V_51 = F_12 ( F_35 ( V_29 ) , V_15 ) ;
if ( ! V_51 ) {
V_30 = - V_16 ;
goto V_46;
}
V_52 = strpbrk ( V_51 , L_9 ) ;
if ( V_52 )
* V_52 = '\0' ;
snprintf ( V_38 , V_39 , L_10 , 'p' , V_51 , V_41 ) ;
V_11 = V_38 ;
F_13 ( V_51 ) ;
}
V_7 = F_7 ( V_10 , V_11 , V_35 , V_43 ) ;
if ( F_36 ( V_7 ) ) {
F_29 ( L_11 , ( int ) F_37 ( V_7 ) ) ;
V_30 = F_37 ( V_7 ) ;
goto V_46;
}
V_7 -> V_41 = V_41 ;
V_7 -> V_28 = V_28 ;
V_7 -> V_29 = F_12 ( V_29 , V_15 ) ;
if ( ! V_7 -> V_29 ) {
F_29 ( L_12 ) ;
V_30 = - V_16 ;
goto error;
}
V_30 = 0 ;
for ( V_26 = 0 ; V_26 < V_35 && V_26 < V_53 ; V_26 ++ ) {
V_7 -> V_27 ++ ;
V_37 = strchr ( V_36 [ V_26 ] , '=' ) ;
if ( V_37 ) {
* V_37 ++ = '\0' ;
V_7 -> args [ V_26 ] . V_19 = F_12 ( V_36 [ V_26 ] , V_15 ) ;
} else {
V_37 = V_36 [ V_26 ] ;
snprintf ( V_38 , V_39 , L_13 , V_26 + 1 ) ;
V_7 -> args [ V_26 ] . V_19 = F_12 ( V_38 , V_15 ) ;
}
if ( ! V_7 -> args [ V_26 ] . V_19 ) {
F_29 ( L_14 , V_26 ) ;
V_30 = - V_16 ;
goto error;
}
if ( ! F_8 ( V_7 -> args [ V_26 ] . V_19 ) ) {
F_29 ( L_15 , V_26 , V_7 -> args [ V_26 ] . V_19 ) ;
V_30 = - V_14 ;
goto error;
}
if ( F_38 ( V_7 -> args [ V_26 ] . V_19 , V_7 -> args , V_26 ) ) {
F_29 ( L_16
L_17 , V_26 , V_36 [ V_26 ] ) ;
V_30 = - V_14 ;
goto error;
}
V_30 = F_39 ( V_37 , & V_7 -> V_54 , & V_7 -> args [ V_26 ] , false , false ) ;
if ( V_30 ) {
F_29 ( L_18 , V_26 , V_30 ) ;
goto error;
}
}
V_30 = F_22 ( V_7 ) ;
if ( V_30 )
goto error;
return 0 ;
error:
F_14 ( V_7 ) ;
return V_30 ;
V_46:
if ( V_28 )
F_16 ( V_28 ) ;
F_29 ( L_19 ) ;
return V_30 ;
}
static int F_40 ( void )
{
struct V_6 * V_7 ;
int V_30 = 0 ;
F_23 ( & V_32 ) ;
while ( ! F_5 ( & V_34 ) ) {
V_7 = F_41 ( V_34 . V_55 , struct V_6 , V_20 ) ;
V_30 = F_19 ( V_7 ) ;
if ( V_30 )
break;
}
F_27 ( & V_32 ) ;
return V_30 ;
}
static void * F_42 ( struct V_56 * V_57 , T_1 * V_58 )
{
F_23 ( & V_32 ) ;
return F_43 ( & V_34 , * V_58 ) ;
}
static void * F_44 ( struct V_56 * V_57 , void * V_59 , T_1 * V_58 )
{
return F_45 ( V_59 , & V_34 , V_58 ) ;
}
static void F_46 ( struct V_56 * V_57 , void * V_59 )
{
F_27 ( & V_32 ) ;
}
static int F_47 ( struct V_56 * V_57 , void * V_59 )
{
struct V_6 * V_7 = V_59 ;
char V_60 = F_6 ( V_7 ) ? 'r' : 'p' ;
int V_26 ;
F_48 ( V_57 , L_20 , V_60 , V_7 -> V_17 . V_18 -> system , V_7 -> V_17 . V_19 ) ;
F_48 ( V_57 , L_21 , V_7 -> V_29 , ( void * ) V_7 -> V_41 ) ;
for ( V_26 = 0 ; V_26 < V_7 -> V_27 ; V_26 ++ )
F_48 ( V_57 , L_22 , V_7 -> args [ V_26 ] . V_19 , V_7 -> args [ V_26 ] . V_61 ) ;
F_48 ( V_57 , L_23 ) ;
return 0 ;
}
static int F_49 ( struct V_28 * V_28 , struct V_62 * V_62 )
{
int V_30 ;
if ( ( V_62 -> V_63 & V_64 ) && ( V_62 -> V_65 & V_66 ) ) {
V_30 = F_40 () ;
if ( V_30 )
return V_30 ;
}
return F_50 ( V_62 , & V_67 ) ;
}
static T_2 F_51 ( struct V_62 * V_62 , const char T_3 * V_68 ,
T_4 V_69 , T_1 * V_70 )
{
return F_52 ( V_62 , V_68 , V_69 , V_70 , F_28 ) ;
}
static int F_53 ( struct V_56 * V_57 , void * V_59 )
{
struct V_6 * V_7 = V_59 ;
F_48 ( V_57 , L_24 , V_7 -> V_29 , V_7 -> V_17 . V_19 , V_7 -> V_71 ) ;
return 0 ;
}
static int F_54 ( struct V_28 * V_28 , struct V_62 * V_62 )
{
return F_50 ( V_62 , & V_72 ) ;
}
static void F_55 ( struct V_6 * V_7 ,
unsigned long V_73 , struct V_74 * V_75 )
{
struct V_76 * V_77 ;
struct V_78 * V_11 ;
struct V_79 * V_68 ;
void * V_80 ;
int V_54 , V_26 ;
struct V_81 * V_17 = & V_7 -> V_17 ;
V_54 = F_56 ( F_6 ( V_7 ) ) ;
V_11 = F_57 ( & V_68 , V_17 -> V_11 . type ,
V_54 + V_7 -> V_54 , 0 , 0 ) ;
if ( ! V_11 )
return;
V_77 = F_58 ( V_11 ) ;
if ( F_6 ( V_7 ) ) {
V_77 -> V_82 [ 0 ] = V_73 ;
V_77 -> V_82 [ 1 ] = F_59 ( V_75 ) ;
V_80 = F_60 ( V_77 , true ) ;
} else {
V_77 -> V_82 [ 0 ] = F_59 ( V_75 ) ;
V_80 = F_60 ( V_77 , false ) ;
}
for ( V_26 = 0 ; V_26 < V_7 -> V_27 ; V_26 ++ )
F_61 ( & V_7 -> args [ V_26 ] . V_83 , V_75 , V_80 + V_7 -> args [ V_26 ] . V_41 ) ;
if ( ! F_62 ( V_17 , V_77 , V_68 , V_11 ) )
F_63 ( V_68 , V_11 , 0 , 0 ) ;
}
static int F_64 ( struct V_6 * V_7 , struct V_74 * V_75 )
{
if ( ! F_6 ( V_7 ) )
F_55 ( V_7 , 0 , V_75 ) ;
return 0 ;
}
static void F_65 ( struct V_6 * V_7 , unsigned long V_73 ,
struct V_74 * V_75 )
{
F_55 ( V_7 , V_73 , V_75 ) ;
}
static enum V_84
F_66 ( struct V_85 * V_86 , int V_24 , struct V_87 * V_11 )
{
struct V_76 * V_77 ;
struct V_88 * V_89 = & V_86 -> V_90 ;
struct V_6 * V_7 ;
T_5 * V_80 ;
int V_26 ;
V_77 = (struct V_76 * ) V_86 -> V_91 ;
V_7 = F_67 ( V_11 , struct V_6 , V_17 . V_11 ) ;
if ( F_6 ( V_7 ) ) {
if ( ! F_68 ( V_89 , L_25 , V_7 -> V_17 . V_19 ,
V_77 -> V_82 [ 1 ] , V_77 -> V_82 [ 0 ] ) )
goto V_92;
V_80 = F_60 ( V_77 , true ) ;
} else {
if ( ! F_68 ( V_89 , L_26 , V_7 -> V_17 . V_19 ,
V_77 -> V_82 [ 0 ] ) )
goto V_92;
V_80 = F_60 ( V_77 , false ) ;
}
for ( V_26 = 0 ; V_26 < V_7 -> V_27 ; V_26 ++ ) {
if ( ! V_7 -> args [ V_26 ] . type -> V_93 ( V_89 , V_7 -> args [ V_26 ] . V_19 ,
V_80 + V_7 -> args [ V_26 ] . V_41 , V_77 ) )
goto V_92;
}
if ( F_69 ( V_89 , L_23 ) )
return V_94 ;
V_92:
return V_95 ;
}
static inline bool F_70 ( struct V_6 * V_7 )
{
return V_7 -> V_24 & ( V_96 | V_97 ) ;
}
static int
F_71 ( struct V_6 * V_7 , int V_98 , T_6 V_2 )
{
int V_30 = 0 ;
if ( F_70 ( V_7 ) )
return - V_99 ;
F_72 ( ! F_4 ( & V_7 -> V_2 ) ) ;
V_7 -> V_24 |= V_98 ;
V_7 -> V_8 . V_2 = V_2 ;
V_30 = F_73 ( V_7 -> V_28 , V_7 -> V_41 , & V_7 -> V_8 ) ;
if ( V_30 )
V_7 -> V_24 &= ~ V_98 ;
return V_30 ;
}
static void F_74 ( struct V_6 * V_7 , int V_98 )
{
if ( ! F_70 ( V_7 ) )
return;
F_72 ( ! F_4 ( & V_7 -> V_2 ) ) ;
F_75 ( V_7 -> V_28 , V_7 -> V_41 , & V_7 -> V_8 ) ;
V_7 -> V_24 &= ~ V_98 ;
}
static int F_76 ( struct V_81 * V_100 )
{
int V_30 , V_26 , V_54 ;
struct V_76 V_101 ;
struct V_6 * V_7 = V_100 -> V_80 ;
if ( F_6 ( V_7 ) ) {
F_77 (unsigned long, vaddr[0], FIELD_STRING_FUNC, 0 ) ;
F_77 (unsigned long, vaddr[1], FIELD_STRING_RETIP, 0 ) ;
V_54 = F_56 ( true ) ;
} else {
F_77 (unsigned long, vaddr[0], FIELD_STRING_IP, 0 ) ;
V_54 = F_56 ( false ) ;
}
for ( V_26 = 0 ; V_26 < V_7 -> V_27 ; V_26 ++ ) {
V_30 = F_78 ( V_100 , V_7 -> args [ V_26 ] . type -> V_102 ,
V_7 -> args [ V_26 ] . V_19 ,
V_54 + V_7 -> args [ V_26 ] . V_41 ,
V_7 -> args [ V_26 ] . type -> V_54 ,
V_7 -> args [ V_26 ] . type -> V_103 ,
V_104 ) ;
if ( V_30 )
return V_30 ;
}
return 0 ;
}
static int F_79 ( struct V_6 * V_7 , char * V_38 , int V_105 )
{
const char * V_106 , * V_37 ;
int V_26 ;
int V_58 = 0 ;
if ( F_6 ( V_7 ) ) {
V_106 = L_27 ;
V_37 = L_28 V_107 L_29 V_108 ;
} else {
V_106 = L_30 ;
V_37 = L_28 V_109 ;
}
V_58 += snprintf ( V_38 + V_58 , V_110 , L_31 , V_106 ) ;
for ( V_26 = 0 ; V_26 < V_7 -> V_27 ; V_26 ++ ) {
V_58 += snprintf ( V_38 + V_58 , V_110 , L_22 ,
V_7 -> args [ V_26 ] . V_19 , V_7 -> args [ V_26 ] . type -> V_106 ) ;
}
V_58 += snprintf ( V_38 + V_58 , V_110 , L_32 , V_37 ) ;
for ( V_26 = 0 ; V_26 < V_7 -> V_27 ; V_26 ++ ) {
V_58 += snprintf ( V_38 + V_58 , V_110 , L_33 ,
V_7 -> args [ V_26 ] . V_19 ) ;
}
return V_58 ;
}
static int F_80 ( struct V_6 * V_7 )
{
char * V_111 ;
int V_105 ;
V_105 = F_79 ( V_7 , NULL , 0 ) ;
V_111 = F_81 ( V_105 + 1 , V_15 ) ;
if ( ! V_111 )
return - V_16 ;
F_79 ( V_7 , V_111 , V_105 + 1 ) ;
V_7 -> V_17 . V_111 = V_111 ;
return 0 ;
}
static bool
F_82 ( struct V_1 * V_2 , struct V_112 * V_113 )
{
struct V_114 * V_11 ;
if ( V_2 -> V_4 )
return true ;
F_18 (event, &filter->perf_events, hw.tp_list) {
if ( V_11 -> V_115 . V_116 -> V_113 == V_113 )
return true ;
}
return false ;
}
static inline bool
F_83 ( struct V_6 * V_7 , struct V_114 * V_11 )
{
return F_82 ( & V_7 -> V_2 , V_11 -> V_115 . V_116 -> V_113 ) ;
}
static int F_84 ( struct V_6 * V_7 , struct V_114 * V_11 )
{
bool V_117 ;
F_85 ( & V_7 -> V_2 . V_3 ) ;
if ( V_11 -> V_115 . V_116 ) {
V_117 = V_7 -> V_2 . V_4 ||
V_11 -> V_118 || V_11 -> V_119 . V_120 ||
F_83 ( V_7 , V_11 ) ;
F_86 ( & V_11 -> V_115 . V_121 , & V_7 -> V_2 . V_5 ) ;
} else {
V_117 = V_7 -> V_2 . V_4 ;
V_7 -> V_2 . V_4 ++ ;
}
F_87 ( & V_7 -> V_2 . V_3 ) ;
if ( ! V_117 )
F_88 ( V_7 -> V_28 , V_7 -> V_41 , & V_7 -> V_8 , true ) ;
return 0 ;
}
static int F_89 ( struct V_6 * V_7 , struct V_114 * V_11 )
{
bool V_117 ;
F_85 ( & V_7 -> V_2 . V_3 ) ;
if ( V_11 -> V_115 . V_116 ) {
F_21 ( & V_11 -> V_115 . V_121 ) ;
V_117 = V_7 -> V_2 . V_4 ||
( V_11 -> V_115 . V_116 -> V_24 & V_122 ) ||
F_83 ( V_7 , V_11 ) ;
} else {
V_7 -> V_2 . V_4 -- ;
V_117 = V_7 -> V_2 . V_4 ;
}
F_87 ( & V_7 -> V_2 . V_3 ) ;
if ( ! V_117 )
F_88 ( V_7 -> V_28 , V_7 -> V_41 , & V_7 -> V_8 , false ) ;
return 0 ;
}
static bool F_90 ( struct V_123 * V_124 ,
enum V_125 V_126 , struct V_112 * V_113 )
{
struct V_6 * V_7 ;
int V_30 ;
V_7 = F_67 ( V_124 , struct V_6 , V_8 ) ;
F_91 ( & V_7 -> V_2 . V_3 ) ;
V_30 = F_82 ( & V_7 -> V_2 , V_113 ) ;
F_92 ( & V_7 -> V_2 . V_3 ) ;
return V_30 ;
}
static void F_93 ( struct V_6 * V_7 ,
unsigned long V_73 , struct V_74 * V_75 )
{
struct V_81 * V_17 = & V_7 -> V_17 ;
struct V_76 * V_77 ;
struct V_127 * V_128 ;
void * V_80 ;
int V_54 , V_129 , V_26 ;
V_54 = F_56 ( F_6 ( V_7 ) ) ;
V_54 = F_94 ( V_54 + V_7 -> V_54 + sizeof( V_130 ) , sizeof( V_131 ) ) - sizeof( V_130 ) ;
F_95 () ;
V_128 = F_96 ( V_17 -> V_5 ) ;
if ( F_97 ( V_128 ) )
goto V_132;
V_77 = F_98 ( V_54 , V_17 -> V_11 . type , V_75 , & V_129 ) ;
if ( ! V_77 )
goto V_132;
if ( F_6 ( V_7 ) ) {
V_77 -> V_82 [ 0 ] = V_73 ;
V_77 -> V_82 [ 1 ] = F_59 ( V_75 ) ;
V_80 = F_60 ( V_77 , true ) ;
} else {
V_77 -> V_82 [ 0 ] = F_59 ( V_75 ) ;
V_80 = F_60 ( V_77 , false ) ;
}
for ( V_26 = 0 ; V_26 < V_7 -> V_27 ; V_26 ++ )
F_61 ( & V_7 -> args [ V_26 ] . V_83 , V_75 , V_80 + V_7 -> args [ V_26 ] . V_41 ) ;
F_99 ( V_77 , V_54 , V_129 , 0 , 1 , V_75 , V_128 , NULL ) ;
V_132:
F_100 () ;
}
static int F_101 ( struct V_6 * V_7 , struct V_74 * V_75 )
{
if ( ! F_90 ( & V_7 -> V_8 , 0 , V_133 -> V_113 ) )
return V_134 ;
if ( ! F_6 ( V_7 ) )
F_93 ( V_7 , 0 , V_75 ) ;
return 0 ;
}
static void F_102 ( struct V_6 * V_7 , unsigned long V_73 ,
struct V_74 * V_75 )
{
F_93 ( V_7 , V_73 , V_75 ) ;
}
static
int F_103 ( struct V_81 * V_11 , enum V_135 type , void * V_80 )
{
struct V_6 * V_7 = V_11 -> V_80 ;
switch ( type ) {
case V_136 :
return F_71 ( V_7 , V_96 , NULL ) ;
case V_137 :
F_74 ( V_7 , V_96 ) ;
return 0 ;
#ifdef F_104
case V_138 :
return F_71 ( V_7 , V_97 , F_90 ) ;
case V_139 :
F_74 ( V_7 , V_97 ) ;
return 0 ;
case V_140 :
return F_84 ( V_7 , V_80 ) ;
case V_141 :
return F_89 ( V_7 , V_80 ) ;
#endif
default:
return 0 ;
}
return 0 ;
}
static int V_22 ( struct V_123 * V_142 , struct V_74 * V_75 )
{
struct V_6 * V_7 ;
int V_30 = 0 ;
V_7 = F_67 ( V_142 , struct V_6 , V_8 ) ;
V_7 -> V_71 ++ ;
if ( V_7 -> V_24 & V_96 )
V_30 |= F_64 ( V_7 , V_75 ) ;
#ifdef F_104
if ( V_7 -> V_24 & V_97 )
V_30 |= F_101 ( V_7 , V_75 ) ;
#endif
return V_30 ;
}
static int V_23 ( struct V_123 * V_142 ,
unsigned long V_73 , struct V_74 * V_75 )
{
struct V_6 * V_7 ;
V_7 = F_67 ( V_142 , struct V_6 , V_8 ) ;
if ( V_7 -> V_24 & V_96 )
F_65 ( V_7 , V_73 , V_75 ) ;
#ifdef F_104
if ( V_7 -> V_24 & V_97 )
F_102 ( V_7 , V_73 , V_75 ) ;
#endif
return 0 ;
}
static int F_24 ( struct V_6 * V_7 )
{
struct V_81 * V_17 = & V_7 -> V_17 ;
int V_30 ;
F_3 ( & V_17 -> V_18 -> V_143 ) ;
V_17 -> V_11 . V_144 = & V_145 ;
V_17 -> V_18 -> V_146 = F_76 ;
if ( F_80 ( V_7 ) < 0 )
return - V_16 ;
V_30 = F_105 ( & V_17 -> V_11 ) ;
if ( ! V_30 ) {
F_13 ( V_17 -> V_111 ) ;
return - V_147 ;
}
V_17 -> V_24 = 0 ;
V_17 -> V_18 -> V_148 = F_103 ;
V_17 -> V_80 = V_7 ;
V_30 = F_106 ( V_17 ) ;
if ( V_30 ) {
F_29 ( L_34 , V_17 -> V_19 ) ;
F_13 ( V_17 -> V_111 ) ;
F_107 ( & V_17 -> V_11 ) ;
}
return V_30 ;
}
static int F_20 ( struct V_6 * V_7 )
{
int V_30 ;
V_30 = F_108 ( & V_7 -> V_17 ) ;
if ( V_30 )
return V_30 ;
F_13 ( V_7 -> V_17 . V_111 ) ;
V_7 -> V_17 . V_111 = NULL ;
return 0 ;
}
static T_7 int F_109 ( void )
{
struct V_48 * V_149 ;
V_149 = F_110 () ;
if ( ! V_149 )
return 0 ;
F_111 ( L_35 , 0644 , V_149 ,
NULL , & V_150 ) ;
F_111 ( L_36 , 0444 , V_149 ,
NULL , & V_151 ) ;
return 0 ;
}
