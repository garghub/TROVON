static unsigned long F_1 ( unsigned long V_1 , unsigned int V_2 )
{
return V_1 - ( V_2 * sizeof( long ) ) ;
}
static unsigned long F_1 ( unsigned long V_1 , unsigned int V_2 )
{
return V_1 + ( V_2 * sizeof( long ) ) ;
}
static unsigned long F_2 ( struct V_3 * V_4 , unsigned int V_2 )
{
unsigned long V_5 ;
unsigned long V_1 = F_3 ( V_4 ) ;
V_1 = F_1 ( V_1 , V_2 ) ;
if ( F_4 ( & V_5 , ( void V_6 V_7 * ) V_1 , sizeof( V_5 ) ) )
return 0 ;
return V_5 ;
}
static unsigned long F_5 ( void * V_8 )
{
unsigned long V_9 ;
struct V_10 * V_11 ;
V_11 = ( void * ) V_12 -> V_13 -> V_14 ;
V_9 = V_11 -> V_15 - V_11 -> V_16 -> V_17 ;
return V_9 + ( unsigned long ) V_8 ;
}
static inline void F_6 ( struct V_18 * V_19 )
{
F_7 ( & V_19 -> V_20 ) ;
V_19 -> V_21 = 0 ;
F_8 ( & V_19 -> V_22 ) ;
}
static inline bool F_9 ( struct V_18 * V_19 )
{
return ! V_19 -> V_21 && F_10 ( & V_19 -> V_22 ) ;
}
static inline bool F_11 ( struct V_23 * V_16 )
{
return V_16 -> V_24 . V_25 != NULL ;
}
static struct V_23 *
F_12 ( const char * V_26 , const char * V_27 , int V_28 , bool V_29 )
{
struct V_23 * V_16 ;
if ( ! V_27 || ! F_13 ( V_27 ) )
return F_14 ( - V_30 ) ;
if ( ! V_26 || ! F_13 ( V_26 ) )
return F_14 ( - V_30 ) ;
V_16 = F_15 ( F_16 ( V_28 ) , V_31 ) ;
if ( ! V_16 )
return F_14 ( - V_32 ) ;
V_16 -> V_33 . V_34 . V_35 = & V_16 -> V_33 . V_35 ;
V_16 -> V_33 . V_34 . V_36 = F_17 ( V_27 , V_31 ) ;
if ( ! V_16 -> V_33 . V_34 . V_36 )
goto error;
V_16 -> V_33 . V_35 . system = F_17 ( V_26 , V_31 ) ;
if ( ! V_16 -> V_33 . V_35 . system )
goto error;
F_8 ( & V_16 -> V_37 ) ;
V_16 -> V_24 . V_38 = V_39 ;
if ( V_29 )
V_16 -> V_24 . V_25 = V_40 ;
F_6 ( & V_16 -> V_19 ) ;
V_16 -> V_33 . V_34 . V_41 |= V_42 ;
return V_16 ;
error:
F_18 ( V_16 -> V_33 . V_34 . V_36 ) ;
F_18 ( V_16 ) ;
return F_14 ( - V_32 ) ;
}
static void F_19 ( struct V_23 * V_16 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_16 -> V_33 . V_44 ; V_43 ++ )
F_20 ( & V_16 -> V_33 . args [ V_43 ] ) ;
F_21 ( V_16 -> V_45 ) ;
F_18 ( V_16 -> V_33 . V_34 . V_35 -> system ) ;
F_18 ( V_16 -> V_33 . V_34 . V_36 ) ;
F_18 ( V_16 -> V_46 ) ;
F_18 ( V_16 ) ;
}
static struct V_23 * F_22 ( const char * V_27 , const char * V_26 )
{
struct V_23 * V_16 ;
F_23 (tu, &uprobe_list, list)
if ( strcmp ( V_16 -> V_33 . V_34 . V_36 , V_27 ) == 0 &&
strcmp ( V_16 -> V_33 . V_34 . V_35 -> system , V_26 ) == 0 )
return V_16 ;
return NULL ;
}
static int F_24 ( struct V_23 * V_16 )
{
int V_5 ;
V_5 = F_25 ( V_16 ) ;
if ( V_5 )
return V_5 ;
F_26 ( & V_16 -> V_37 ) ;
F_19 ( V_16 ) ;
return 0 ;
}
static int F_27 ( struct V_23 * V_16 )
{
struct V_23 * V_47 ;
int V_5 ;
F_28 ( & V_48 ) ;
V_47 = F_22 ( V_16 -> V_33 . V_34 . V_36 , V_16 -> V_33 . V_34 . V_35 -> system ) ;
if ( V_47 ) {
V_5 = F_24 ( V_47 ) ;
if ( V_5 )
goto V_49;
}
V_5 = F_29 ( V_16 ) ;
if ( V_5 ) {
F_30 ( L_1 , V_5 ) ;
goto V_49;
}
F_31 ( & V_16 -> V_37 , & V_50 ) ;
V_49:
F_32 ( & V_48 ) ;
return V_5 ;
}
static int F_33 ( int V_51 , char * * V_52 )
{
struct V_23 * V_16 ;
struct V_45 * V_45 ;
char * V_53 , * V_27 , * V_26 , * V_46 ;
char V_54 [ V_55 ] ;
struct V_56 V_56 ;
unsigned long V_17 ;
bool V_57 , V_58 ;
int V_43 , V_5 ;
V_45 = NULL ;
V_5 = 0 ;
V_57 = false ;
V_58 = false ;
V_27 = NULL ;
V_26 = NULL ;
if ( V_52 [ 0 ] [ 0 ] == '-' )
V_57 = true ;
else if ( V_52 [ 0 ] [ 0 ] == 'r' )
V_58 = true ;
else if ( V_52 [ 0 ] [ 0 ] != 'p' ) {
F_34 ( L_2 ) ;
return - V_30 ;
}
if ( V_52 [ 0 ] [ 1 ] == ':' ) {
V_27 = & V_52 [ 0 ] [ 2 ] ;
V_53 = strchr ( V_27 , '/' ) ;
if ( V_53 ) {
V_26 = V_27 ;
V_27 = V_53 + 1 ;
V_27 [ - 1 ] = '\0' ;
if ( strlen ( V_26 ) == 0 ) {
F_34 ( L_3 ) ;
return - V_30 ;
}
}
if ( strlen ( V_27 ) == 0 ) {
F_34 ( L_4 ) ;
return - V_30 ;
}
}
if ( ! V_26 )
V_26 = V_59 ;
if ( V_57 ) {
int V_5 ;
if ( ! V_27 ) {
F_34 ( L_5 ) ;
return - V_30 ;
}
F_28 ( & V_48 ) ;
V_16 = F_22 ( V_27 , V_26 ) ;
if ( ! V_16 ) {
F_32 ( & V_48 ) ;
F_34 ( L_6 , V_26 , V_27 ) ;
return - V_60 ;
}
V_5 = F_24 ( V_16 ) ;
F_32 ( & V_48 ) ;
return V_5 ;
}
if ( V_51 < 2 ) {
F_34 ( L_7 ) ;
return - V_30 ;
}
if ( isdigit ( V_52 [ 1 ] [ 0 ] ) ) {
F_34 ( L_8 ) ;
return - V_30 ;
}
V_53 = strchr ( V_52 [ 1 ] , ':' ) ;
if ( ! V_53 ) {
V_5 = - V_30 ;
goto V_61;
}
* V_53 ++ = '\0' ;
V_46 = V_52 [ 1 ] ;
V_5 = F_35 ( V_46 , V_62 , & V_56 ) ;
if ( V_5 )
goto V_61;
V_45 = F_36 ( V_56 . V_63 -> V_64 ) ;
F_37 ( & V_56 ) ;
if ( ! V_45 || ! F_38 ( V_45 -> V_65 ) ) {
V_5 = - V_30 ;
goto V_61;
}
V_5 = F_39 ( V_53 , 0 , & V_17 ) ;
if ( V_5 )
goto V_61;
V_51 -= 2 ;
V_52 += 2 ;
if ( ! V_27 ) {
char * V_66 ;
char * V_67 ;
V_66 = F_17 ( F_40 ( V_46 ) , V_31 ) ;
if ( ! V_66 ) {
V_5 = - V_32 ;
goto V_61;
}
V_67 = strpbrk ( V_66 , L_9 ) ;
if ( V_67 )
* V_67 = '\0' ;
snprintf ( V_54 , V_55 , L_10 , 'p' , V_66 , V_17 ) ;
V_27 = V_54 ;
F_18 ( V_66 ) ;
}
V_16 = F_12 ( V_26 , V_27 , V_51 , V_58 ) ;
if ( F_41 ( V_16 ) ) {
F_34 ( L_11 , ( int ) F_42 ( V_16 ) ) ;
V_5 = F_42 ( V_16 ) ;
goto V_61;
}
V_16 -> V_17 = V_17 ;
V_16 -> V_45 = V_45 ;
V_16 -> V_46 = F_17 ( V_46 , V_31 ) ;
if ( ! V_16 -> V_46 ) {
F_34 ( L_12 ) ;
V_5 = - V_32 ;
goto error;
}
V_5 = 0 ;
for ( V_43 = 0 ; V_43 < V_51 && V_43 < V_68 ; V_43 ++ ) {
struct V_69 * V_70 = & V_16 -> V_33 . args [ V_43 ] ;
V_16 -> V_33 . V_44 ++ ;
V_53 = strchr ( V_52 [ V_43 ] , '=' ) ;
if ( V_53 ) {
* V_53 ++ = '\0' ;
V_70 -> V_36 = F_17 ( V_52 [ V_43 ] , V_31 ) ;
} else {
V_53 = V_52 [ V_43 ] ;
snprintf ( V_54 , V_55 , L_13 , V_43 + 1 ) ;
V_70 -> V_36 = F_17 ( V_54 , V_31 ) ;
}
if ( ! V_70 -> V_36 ) {
F_34 ( L_14 , V_43 ) ;
V_5 = - V_32 ;
goto error;
}
if ( ! F_13 ( V_70 -> V_36 ) ) {
F_34 ( L_15 , V_43 , V_70 -> V_36 ) ;
V_5 = - V_30 ;
goto error;
}
if ( F_43 ( V_70 -> V_36 , V_16 -> V_33 . args , V_43 ) ) {
F_34 ( L_16
L_17 , V_43 , V_52 [ V_43 ] ) ;
V_5 = - V_30 ;
goto error;
}
V_5 = F_44 ( V_53 , & V_16 -> V_33 . V_71 , V_70 ,
V_58 , false ) ;
if ( V_5 ) {
F_34 ( L_18 , V_43 , V_5 ) ;
goto error;
}
}
V_5 = F_27 ( V_16 ) ;
if ( V_5 )
goto error;
return 0 ;
error:
F_19 ( V_16 ) ;
return V_5 ;
V_61:
if ( V_45 )
F_21 ( V_45 ) ;
F_34 ( L_19 ) ;
return V_5 ;
}
static int F_45 ( void )
{
struct V_23 * V_16 ;
int V_5 = 0 ;
F_28 ( & V_48 ) ;
while ( ! F_10 ( & V_50 ) ) {
V_16 = F_46 ( V_50 . V_72 , struct V_23 , V_37 ) ;
V_5 = F_24 ( V_16 ) ;
if ( V_5 )
break;
}
F_32 ( & V_48 ) ;
return V_5 ;
}
static void * F_47 ( struct V_73 * V_74 , T_1 * V_75 )
{
F_28 ( & V_48 ) ;
return F_48 ( & V_50 , * V_75 ) ;
}
static void * F_49 ( struct V_73 * V_74 , void * V_76 , T_1 * V_75 )
{
return F_50 ( V_76 , & V_50 , V_75 ) ;
}
static void F_51 ( struct V_73 * V_74 , void * V_76 )
{
F_32 ( & V_48 ) ;
}
static int F_52 ( struct V_73 * V_74 , void * V_76 )
{
struct V_23 * V_16 = V_76 ;
char V_77 = F_11 ( V_16 ) ? 'r' : 'p' ;
int V_43 ;
F_53 ( V_74 , L_20 , V_77 , V_16 -> V_33 . V_34 . V_35 -> system , V_16 -> V_33 . V_34 . V_36 ) ;
F_53 ( V_74 , L_21 , V_16 -> V_46 , ( void * ) V_16 -> V_17 ) ;
for ( V_43 = 0 ; V_43 < V_16 -> V_33 . V_44 ; V_43 ++ )
F_53 ( V_74 , L_22 , V_16 -> V_33 . args [ V_43 ] . V_36 , V_16 -> V_33 . args [ V_43 ] . V_78 ) ;
F_53 ( V_74 , L_23 ) ;
return 0 ;
}
static int F_54 ( struct V_45 * V_45 , struct V_79 * V_79 )
{
int V_5 ;
if ( ( V_79 -> V_80 & V_81 ) && ( V_79 -> V_82 & V_83 ) ) {
V_5 = F_45 () ;
if ( V_5 )
return V_5 ;
}
return F_55 ( V_79 , & V_84 ) ;
}
static T_2 F_56 ( struct V_79 * V_79 , const char V_7 * V_85 ,
T_3 V_86 , T_1 * V_87 )
{
return F_57 ( V_79 , V_85 , V_86 , V_87 , F_33 ) ;
}
static int F_58 ( struct V_73 * V_74 , void * V_76 )
{
struct V_23 * V_16 = V_76 ;
F_53 ( V_74 , L_24 , V_16 -> V_46 , V_16 -> V_33 . V_34 . V_36 , V_16 -> V_88 ) ;
return 0 ;
}
static int F_59 ( struct V_45 * V_45 , struct V_79 * V_79 )
{
return F_55 ( V_79 , & V_89 ) ;
}
static int F_60 ( void )
{
int V_90 , V_91 ;
V_92 = F_61 ( struct V_92 ) ;
if ( V_92 == NULL )
return - V_32 ;
F_62 (cpu) {
struct V_93 * V_94 = F_63 ( F_64 ( V_90 ) ,
V_31 , 0 ) ;
if ( V_94 == NULL ) {
V_91 = V_90 ;
goto V_95;
}
F_65 ( V_92 , V_90 ) -> V_54 = F_66 ( V_94 ) ;
F_67 ( & F_65 ( V_92 , V_90 ) -> V_96 ) ;
}
return 0 ;
V_95:
F_62 (cpu) {
if ( V_90 == V_91 )
break;
F_68 ( ( unsigned long ) F_65 ( V_92 , V_90 ) -> V_54 ) ;
}
F_69 ( V_92 ) ;
return - V_32 ;
}
static int F_70 ( void )
{
int V_5 = 0 ;
F_71 ( ! F_72 ( & V_97 ) ) ;
if ( V_98 ++ == 0 ) {
V_5 = F_60 () ;
if ( V_5 < 0 )
V_98 -- ;
}
return V_5 ;
}
static void F_73 ( void )
{
F_71 ( ! F_72 ( & V_97 ) ) ;
if ( -- V_98 == 0 ) {
F_69 ( V_92 ) ;
V_92 = NULL ;
}
}
static struct V_92 * F_74 ( void )
{
struct V_92 * V_99 ;
int V_90 ;
V_90 = F_75 () ;
V_99 = F_65 ( V_92 , V_90 ) ;
F_28 ( & V_99 -> V_96 ) ;
return V_99 ;
}
static void F_76 ( struct V_92 * V_99 )
{
F_32 ( & V_99 -> V_96 ) ;
}
static void F_77 ( struct V_23 * V_16 ,
unsigned long V_100 , struct V_3 * V_4 )
{
struct V_101 * V_102 ;
struct V_103 * V_27 ;
struct V_104 * V_85 ;
struct V_92 * V_99 ;
void * V_105 ;
int V_71 , V_106 , V_107 ;
struct V_108 * V_34 = & V_16 -> V_33 . V_34 ;
V_106 = F_78 ( & V_16 -> V_33 , V_4 ) ;
V_107 = F_79 ( F_11 ( V_16 ) ) ;
if ( F_80 ( ! V_92 || V_16 -> V_33 . V_71 + V_106 > V_109 ) )
return;
V_99 = F_74 () ;
F_81 ( V_107 , & V_16 -> V_33 , V_4 , V_99 -> V_54 , V_106 ) ;
V_71 = V_107 + V_16 -> V_33 . V_71 + V_106 ;
V_27 = F_82 ( & V_85 , V_34 -> V_27 . type ,
V_71 , 0 , 0 ) ;
if ( ! V_27 )
goto V_110;
V_102 = F_83 ( V_27 ) ;
if ( F_11 ( V_16 ) ) {
V_102 -> V_14 [ 0 ] = V_100 ;
V_102 -> V_14 [ 1 ] = F_84 ( V_4 ) ;
V_105 = F_85 ( V_102 , true ) ;
} else {
V_102 -> V_14 [ 0 ] = F_84 ( V_4 ) ;
V_105 = F_85 ( V_102 , false ) ;
}
memcpy ( V_105 , V_99 -> V_54 , V_16 -> V_33 . V_71 + V_106 ) ;
if ( ! F_86 ( V_34 , V_102 , V_85 , V_27 ) )
F_87 ( V_85 , V_27 , 0 , 0 ) ;
V_110:
F_76 ( V_99 ) ;
}
static int F_88 ( struct V_23 * V_16 , struct V_3 * V_4 )
{
if ( ! F_11 ( V_16 ) )
F_77 ( V_16 , 0 , V_4 ) ;
return 0 ;
}
static void F_89 ( struct V_23 * V_16 , unsigned long V_100 ,
struct V_3 * V_4 )
{
F_77 ( V_16 , V_100 , V_4 ) ;
}
static enum V_111
F_90 ( struct V_112 * V_113 , int V_41 , struct V_114 * V_27 )
{
struct V_101 * V_102 ;
struct V_115 * V_116 = & V_113 -> V_117 ;
struct V_23 * V_16 ;
T_4 * V_105 ;
int V_43 ;
V_102 = (struct V_101 * ) V_113 -> V_118 ;
V_16 = F_91 ( V_27 , struct V_23 , V_33 . V_34 . V_27 ) ;
if ( F_11 ( V_16 ) ) {
if ( ! F_92 ( V_116 , L_25 , V_16 -> V_33 . V_34 . V_36 ,
V_102 -> V_14 [ 1 ] , V_102 -> V_14 [ 0 ] ) )
goto V_119;
V_105 = F_85 ( V_102 , true ) ;
} else {
if ( ! F_92 ( V_116 , L_26 , V_16 -> V_33 . V_34 . V_36 ,
V_102 -> V_14 [ 0 ] ) )
goto V_119;
V_105 = F_85 ( V_102 , false ) ;
}
for ( V_43 = 0 ; V_43 < V_16 -> V_33 . V_44 ; V_43 ++ ) {
struct V_69 * V_70 = & V_16 -> V_33 . args [ V_43 ] ;
if ( ! V_70 -> type -> V_120 ( V_116 , V_70 -> V_36 , V_105 + V_70 -> V_17 , V_102 ) )
goto V_119;
}
if ( F_93 ( V_116 , L_23 ) )
return V_121 ;
V_119:
return V_122 ;
}
static int
F_94 ( struct V_23 * V_16 , int V_123 , T_5 V_19 )
{
int V_5 = 0 ;
if ( F_95 ( & V_16 -> V_33 ) )
return - V_124 ;
V_5 = F_70 () ;
if ( V_5 < 0 )
return V_5 ;
F_96 ( ! F_9 ( & V_16 -> V_19 ) ) ;
V_16 -> V_33 . V_41 |= V_123 ;
V_16 -> V_24 . V_19 = V_19 ;
V_5 = F_97 ( V_16 -> V_45 , V_16 -> V_17 , & V_16 -> V_24 ) ;
if ( V_5 )
V_16 -> V_33 . V_41 &= ~ V_123 ;
return V_5 ;
}
static void F_98 ( struct V_23 * V_16 , int V_123 )
{
if ( ! F_95 ( & V_16 -> V_33 ) )
return;
F_96 ( ! F_9 ( & V_16 -> V_19 ) ) ;
F_99 ( V_16 -> V_45 , V_16 -> V_17 , & V_16 -> V_24 ) ;
V_16 -> V_33 . V_41 &= ~ V_123 ;
F_73 () ;
}
static int F_100 ( struct V_108 * V_125 )
{
int V_5 , V_43 , V_71 ;
struct V_101 V_126 ;
struct V_23 * V_16 = V_125 -> V_105 ;
if ( F_11 ( V_16 ) ) {
F_101 (unsigned long, vaddr[0], FIELD_STRING_FUNC, 0 ) ;
F_101 (unsigned long, vaddr[1], FIELD_STRING_RETIP, 0 ) ;
V_71 = F_79 ( true ) ;
} else {
F_101 (unsigned long, vaddr[0], FIELD_STRING_IP, 0 ) ;
V_71 = F_79 ( false ) ;
}
for ( V_43 = 0 ; V_43 < V_16 -> V_33 . V_44 ; V_43 ++ ) {
struct V_69 * V_70 = & V_16 -> V_33 . args [ V_43 ] ;
V_5 = F_102 ( V_125 , V_70 -> type -> V_127 ,
V_70 -> V_36 , V_71 + V_70 -> V_17 ,
V_70 -> type -> V_71 , V_70 -> type -> V_128 ,
V_129 ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
static bool
F_103 ( struct V_18 * V_19 , struct V_130 * V_131 )
{
struct V_132 * V_27 ;
if ( V_19 -> V_21 )
return true ;
F_23 (event, &filter->perf_events, hw.tp_list) {
if ( V_27 -> V_133 . V_134 -> V_131 == V_131 )
return true ;
}
return false ;
}
static inline bool
F_104 ( struct V_23 * V_16 , struct V_132 * V_27 )
{
return F_103 ( & V_16 -> V_19 , V_27 -> V_133 . V_134 -> V_131 ) ;
}
static int F_105 ( struct V_23 * V_16 , struct V_132 * V_27 )
{
bool V_135 ;
F_106 ( & V_16 -> V_19 . V_20 ) ;
if ( V_27 -> V_133 . V_134 ) {
V_135 = V_16 -> V_19 . V_21 ||
V_27 -> V_136 || V_27 -> V_137 . V_138 ||
F_104 ( V_16 , V_27 ) ;
F_107 ( & V_27 -> V_133 . V_139 , & V_16 -> V_19 . V_22 ) ;
} else {
V_135 = V_16 -> V_19 . V_21 ;
V_16 -> V_19 . V_21 ++ ;
}
F_108 ( & V_16 -> V_19 . V_20 ) ;
if ( ! V_135 )
F_109 ( V_16 -> V_45 , V_16 -> V_17 , & V_16 -> V_24 , true ) ;
return 0 ;
}
static int F_110 ( struct V_23 * V_16 , struct V_132 * V_27 )
{
bool V_135 ;
F_106 ( & V_16 -> V_19 . V_20 ) ;
if ( V_27 -> V_133 . V_134 ) {
F_26 ( & V_27 -> V_133 . V_139 ) ;
V_135 = V_16 -> V_19 . V_21 ||
( V_27 -> V_133 . V_134 -> V_41 & V_140 ) ||
F_104 ( V_16 , V_27 ) ;
} else {
V_16 -> V_19 . V_21 -- ;
V_135 = V_16 -> V_19 . V_21 ;
}
F_108 ( & V_16 -> V_19 . V_20 ) ;
if ( ! V_135 )
F_109 ( V_16 -> V_45 , V_16 -> V_17 , & V_16 -> V_24 , false ) ;
return 0 ;
}
static bool F_111 ( struct V_141 * V_142 ,
enum V_143 V_144 , struct V_130 * V_131 )
{
struct V_23 * V_16 ;
int V_5 ;
V_16 = F_91 ( V_142 , struct V_23 , V_24 ) ;
F_112 ( & V_16 -> V_19 . V_20 ) ;
V_5 = F_103 ( & V_16 -> V_19 , V_131 ) ;
F_113 ( & V_16 -> V_19 . V_20 ) ;
return V_5 ;
}
static void F_114 ( struct V_23 * V_16 ,
unsigned long V_100 , struct V_3 * V_4 )
{
struct V_108 * V_34 = & V_16 -> V_33 . V_34 ;
struct V_101 * V_102 ;
struct V_145 * V_146 ;
struct V_92 * V_99 ;
void * V_105 ;
int V_71 , V_106 , V_107 ;
int V_147 ;
V_106 = F_78 ( & V_16 -> V_33 , V_4 ) ;
V_107 = F_79 ( F_11 ( V_16 ) ) ;
if ( F_80 ( ! V_92 ) )
return;
V_71 = V_107 + V_16 -> V_33 . V_71 + V_106 ;
V_71 = F_115 ( V_71 + sizeof( V_148 ) , sizeof( V_149 ) ) - sizeof( V_148 ) ;
if ( F_116 ( V_71 > V_150 , L_27 ) )
return;
V_99 = F_74 () ;
F_81 ( V_107 , & V_16 -> V_33 , V_4 , V_99 -> V_54 , V_106 ) ;
F_117 () ;
V_146 = F_118 ( V_34 -> V_22 ) ;
if ( F_119 ( V_146 ) )
goto V_110;
V_102 = F_120 ( V_71 , V_34 -> V_27 . type , V_4 , & V_147 ) ;
if ( ! V_102 )
goto V_110;
if ( F_11 ( V_16 ) ) {
V_102 -> V_14 [ 0 ] = V_100 ;
V_102 -> V_14 [ 1 ] = F_84 ( V_4 ) ;
V_105 = F_85 ( V_102 , true ) ;
} else {
V_102 -> V_14 [ 0 ] = F_84 ( V_4 ) ;
V_105 = F_85 ( V_102 , false ) ;
}
memcpy ( V_105 , V_99 -> V_54 , V_16 -> V_33 . V_71 + V_106 ) ;
if ( V_71 - V_107 > V_16 -> V_33 . V_71 + V_106 ) {
int V_151 = V_16 -> V_33 . V_71 + V_106 ;
memset ( V_105 + V_151 , 0 , V_71 - V_107 - V_151 ) ;
}
F_121 ( V_102 , V_71 , V_147 , 0 , 1 , V_4 , V_146 , NULL ) ;
V_110:
F_122 () ;
F_76 ( V_99 ) ;
}
static int F_123 ( struct V_23 * V_16 , struct V_3 * V_4 )
{
if ( ! F_111 ( & V_16 -> V_24 , 0 , V_12 -> V_131 ) )
return V_152 ;
if ( ! F_11 ( V_16 ) )
F_114 ( V_16 , 0 , V_4 ) ;
return 0 ;
}
static void F_124 ( struct V_23 * V_16 , unsigned long V_100 ,
struct V_3 * V_4 )
{
F_114 ( V_16 , V_100 , V_4 ) ;
}
static
int F_125 ( struct V_108 * V_27 , enum V_153 type , void * V_105 )
{
struct V_23 * V_16 = V_27 -> V_105 ;
switch ( type ) {
case V_154 :
return F_94 ( V_16 , V_155 , NULL ) ;
case V_156 :
F_98 ( V_16 , V_155 ) ;
return 0 ;
#ifdef F_126
case V_157 :
return F_94 ( V_16 , V_158 , F_111 ) ;
case V_159 :
F_98 ( V_16 , V_158 ) ;
return 0 ;
case V_160 :
return F_105 ( V_16 , V_105 ) ;
case V_161 :
return F_110 ( V_16 , V_105 ) ;
#endif
default:
return 0 ;
}
return 0 ;
}
static int V_39 ( struct V_141 * V_162 , struct V_3 * V_4 )
{
struct V_23 * V_16 ;
struct V_10 V_11 ;
int V_5 = 0 ;
V_16 = F_91 ( V_162 , struct V_23 , V_24 ) ;
V_16 -> V_88 ++ ;
V_11 . V_16 = V_16 ;
V_11 . V_15 = F_84 ( V_4 ) ;
V_12 -> V_13 -> V_14 = ( unsigned long ) & V_11 ;
if ( V_16 -> V_33 . V_41 & V_155 )
V_5 |= F_88 ( V_16 , V_4 ) ;
#ifdef F_126
if ( V_16 -> V_33 . V_41 & V_158 )
V_5 |= F_123 ( V_16 , V_4 ) ;
#endif
return V_5 ;
}
static int V_40 ( struct V_141 * V_162 ,
unsigned long V_100 , struct V_3 * V_4 )
{
struct V_23 * V_16 ;
struct V_10 V_11 ;
V_16 = F_91 ( V_162 , struct V_23 , V_24 ) ;
V_11 . V_16 = V_16 ;
V_11 . V_15 = V_100 ;
V_12 -> V_13 -> V_14 = ( unsigned long ) & V_11 ;
if ( V_16 -> V_33 . V_41 & V_155 )
F_89 ( V_16 , V_100 , V_4 ) ;
#ifdef F_126
if ( V_16 -> V_33 . V_41 & V_158 )
F_124 ( V_16 , V_100 , V_4 ) ;
#endif
return 0 ;
}
static int F_29 ( struct V_23 * V_16 )
{
struct V_108 * V_34 = & V_16 -> V_33 . V_34 ;
int V_5 ;
F_8 ( & V_34 -> V_35 -> V_163 ) ;
V_34 -> V_27 . V_164 = & V_165 ;
V_34 -> V_35 -> V_166 = F_100 ;
if ( F_127 ( & V_16 -> V_33 , F_11 ( V_16 ) ) < 0 )
return - V_32 ;
V_5 = F_128 ( & V_34 -> V_27 ) ;
if ( ! V_5 ) {
F_18 ( V_34 -> V_167 ) ;
return - V_168 ;
}
V_34 -> V_41 = 0 ;
V_34 -> V_35 -> V_169 = F_125 ;
V_34 -> V_105 = V_16 ;
V_5 = F_129 ( V_34 ) ;
if ( V_5 ) {
F_34 ( L_28 , V_34 -> V_36 ) ;
F_18 ( V_34 -> V_167 ) ;
F_130 ( & V_34 -> V_27 ) ;
}
return V_5 ;
}
static int F_25 ( struct V_23 * V_16 )
{
int V_5 ;
V_5 = F_131 ( & V_16 -> V_33 . V_34 ) ;
if ( V_5 )
return V_5 ;
F_18 ( V_16 -> V_33 . V_34 . V_167 ) ;
V_16 -> V_33 . V_34 . V_167 = NULL ;
return 0 ;
}
static T_6 int F_132 ( void )
{
struct V_63 * V_170 ;
V_170 = F_133 () ;
if ( ! V_170 )
return 0 ;
F_134 ( L_29 , 0644 , V_170 ,
NULL , & V_171 ) ;
F_134 ( L_30 , 0444 , V_170 ,
NULL , & V_172 ) ;
return 0 ;
}
