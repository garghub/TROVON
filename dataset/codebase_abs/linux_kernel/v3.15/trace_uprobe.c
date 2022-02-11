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
F_8 ( & V_16 -> V_33 . V_38 ) ;
V_16 -> V_24 . V_39 = V_40 ;
if ( V_29 )
V_16 -> V_24 . V_25 = V_41 ;
F_6 ( & V_16 -> V_19 ) ;
V_16 -> V_33 . V_34 . V_42 |= V_43 ;
return V_16 ;
error:
F_18 ( V_16 -> V_33 . V_34 . V_36 ) ;
F_18 ( V_16 ) ;
return F_14 ( - V_32 ) ;
}
static void F_19 ( struct V_23 * V_16 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_16 -> V_33 . V_45 ; V_44 ++ )
F_20 ( & V_16 -> V_33 . args [ V_44 ] ) ;
F_21 ( V_16 -> V_46 ) ;
F_18 ( V_16 -> V_33 . V_34 . V_35 -> system ) ;
F_18 ( V_16 -> V_33 . V_34 . V_36 ) ;
F_18 ( V_16 -> V_47 ) ;
F_18 ( V_16 ) ;
}
static struct V_23 * F_22 ( const char * V_27 , const char * V_26 )
{
struct V_23 * V_16 ;
F_23 (tu, &uprobe_list, list)
if ( strcmp ( F_24 ( & V_16 -> V_33 . V_34 ) , V_27 ) == 0 &&
strcmp ( V_16 -> V_33 . V_34 . V_35 -> system , V_26 ) == 0 )
return V_16 ;
return NULL ;
}
static int F_25 ( struct V_23 * V_16 )
{
int V_5 ;
V_5 = F_26 ( V_16 ) ;
if ( V_5 )
return V_5 ;
F_27 ( & V_16 -> V_37 ) ;
F_19 ( V_16 ) ;
return 0 ;
}
static int F_28 ( struct V_23 * V_16 )
{
struct V_23 * V_48 ;
int V_5 ;
F_29 ( & V_49 ) ;
V_48 = F_22 ( F_24 ( & V_16 -> V_33 . V_34 ) ,
V_16 -> V_33 . V_34 . V_35 -> system ) ;
if ( V_48 ) {
V_5 = F_25 ( V_48 ) ;
if ( V_5 )
goto V_50;
}
V_5 = F_30 ( V_16 ) ;
if ( V_5 ) {
F_31 ( L_1 , V_5 ) ;
goto V_50;
}
F_32 ( & V_16 -> V_37 , & V_51 ) ;
V_50:
F_33 ( & V_49 ) ;
return V_5 ;
}
static int F_34 ( int V_52 , char * * V_53 )
{
struct V_23 * V_16 ;
struct V_46 * V_46 ;
char * V_54 , * V_27 , * V_26 , * V_47 ;
char V_55 [ V_56 ] ;
struct V_57 V_57 ;
unsigned long V_17 ;
bool V_58 , V_59 ;
int V_44 , V_5 ;
V_46 = NULL ;
V_5 = 0 ;
V_58 = false ;
V_59 = false ;
V_27 = NULL ;
V_26 = NULL ;
if ( V_53 [ 0 ] [ 0 ] == '-' )
V_58 = true ;
else if ( V_53 [ 0 ] [ 0 ] == 'r' )
V_59 = true ;
else if ( V_53 [ 0 ] [ 0 ] != 'p' ) {
F_35 ( L_2 ) ;
return - V_30 ;
}
if ( V_53 [ 0 ] [ 1 ] == ':' ) {
V_27 = & V_53 [ 0 ] [ 2 ] ;
V_54 = strchr ( V_27 , '/' ) ;
if ( V_54 ) {
V_26 = V_27 ;
V_27 = V_54 + 1 ;
V_27 [ - 1 ] = '\0' ;
if ( strlen ( V_26 ) == 0 ) {
F_35 ( L_3 ) ;
return - V_30 ;
}
}
if ( strlen ( V_27 ) == 0 ) {
F_35 ( L_4 ) ;
return - V_30 ;
}
}
if ( ! V_26 )
V_26 = V_60 ;
if ( V_58 ) {
int V_5 ;
if ( ! V_27 ) {
F_35 ( L_5 ) ;
return - V_30 ;
}
F_29 ( & V_49 ) ;
V_16 = F_22 ( V_27 , V_26 ) ;
if ( ! V_16 ) {
F_33 ( & V_49 ) ;
F_35 ( L_6 , V_26 , V_27 ) ;
return - V_61 ;
}
V_5 = F_25 ( V_16 ) ;
F_33 ( & V_49 ) ;
return V_5 ;
}
if ( V_52 < 2 ) {
F_35 ( L_7 ) ;
return - V_30 ;
}
if ( isdigit ( V_53 [ 1 ] [ 0 ] ) ) {
F_35 ( L_8 ) ;
return - V_30 ;
}
V_54 = strchr ( V_53 [ 1 ] , ':' ) ;
if ( ! V_54 ) {
V_5 = - V_30 ;
goto V_62;
}
* V_54 ++ = '\0' ;
V_47 = V_53 [ 1 ] ;
V_5 = F_36 ( V_47 , V_63 , & V_57 ) ;
if ( V_5 )
goto V_62;
V_46 = F_37 ( V_57 . V_64 -> V_65 ) ;
F_38 ( & V_57 ) ;
if ( ! V_46 || ! F_39 ( V_46 -> V_66 ) ) {
V_5 = - V_30 ;
goto V_62;
}
V_5 = F_40 ( V_54 , 0 , & V_17 ) ;
if ( V_5 )
goto V_62;
V_52 -= 2 ;
V_53 += 2 ;
if ( ! V_27 ) {
char * V_67 ;
char * V_68 ;
V_67 = F_17 ( F_41 ( V_47 ) , V_31 ) ;
if ( ! V_67 ) {
V_5 = - V_32 ;
goto V_62;
}
V_68 = strpbrk ( V_67 , L_9 ) ;
if ( V_68 )
* V_68 = '\0' ;
snprintf ( V_55 , V_56 , L_10 , 'p' , V_67 , V_17 ) ;
V_27 = V_55 ;
F_18 ( V_67 ) ;
}
V_16 = F_12 ( V_26 , V_27 , V_52 , V_59 ) ;
if ( F_42 ( V_16 ) ) {
F_35 ( L_11 , ( int ) F_43 ( V_16 ) ) ;
V_5 = F_43 ( V_16 ) ;
goto V_62;
}
V_16 -> V_17 = V_17 ;
V_16 -> V_46 = V_46 ;
V_16 -> V_47 = F_17 ( V_47 , V_31 ) ;
if ( ! V_16 -> V_47 ) {
F_35 ( L_12 ) ;
V_5 = - V_32 ;
goto error;
}
V_5 = 0 ;
for ( V_44 = 0 ; V_44 < V_52 && V_44 < V_69 ; V_44 ++ ) {
struct V_70 * V_71 = & V_16 -> V_33 . args [ V_44 ] ;
V_16 -> V_33 . V_45 ++ ;
V_54 = strchr ( V_53 [ V_44 ] , '=' ) ;
if ( V_54 ) {
* V_54 ++ = '\0' ;
V_71 -> V_36 = F_17 ( V_53 [ V_44 ] , V_31 ) ;
} else {
V_54 = V_53 [ V_44 ] ;
snprintf ( V_55 , V_56 , L_13 , V_44 + 1 ) ;
V_71 -> V_36 = F_17 ( V_55 , V_31 ) ;
}
if ( ! V_71 -> V_36 ) {
F_35 ( L_14 , V_44 ) ;
V_5 = - V_32 ;
goto error;
}
if ( ! F_13 ( V_71 -> V_36 ) ) {
F_35 ( L_15 , V_44 , V_71 -> V_36 ) ;
V_5 = - V_30 ;
goto error;
}
if ( F_44 ( V_71 -> V_36 , V_16 -> V_33 . args , V_44 ) ) {
F_35 ( L_16
L_17 , V_44 , V_53 [ V_44 ] ) ;
V_5 = - V_30 ;
goto error;
}
V_5 = F_45 ( V_54 , & V_16 -> V_33 . V_72 , V_71 ,
V_59 , false ) ;
if ( V_5 ) {
F_35 ( L_18 , V_44 , V_5 ) ;
goto error;
}
}
V_5 = F_28 ( V_16 ) ;
if ( V_5 )
goto error;
return 0 ;
error:
F_19 ( V_16 ) ;
return V_5 ;
V_62:
if ( V_46 )
F_21 ( V_46 ) ;
F_35 ( L_19 ) ;
return V_5 ;
}
static int F_46 ( void )
{
struct V_23 * V_16 ;
int V_5 = 0 ;
F_29 ( & V_49 ) ;
while ( ! F_10 ( & V_51 ) ) {
V_16 = F_47 ( V_51 . V_73 , struct V_23 , V_37 ) ;
V_5 = F_25 ( V_16 ) ;
if ( V_5 )
break;
}
F_33 ( & V_49 ) ;
return V_5 ;
}
static void * F_48 ( struct V_74 * V_75 , T_1 * V_76 )
{
F_29 ( & V_49 ) ;
return F_49 ( & V_51 , * V_76 ) ;
}
static void * F_50 ( struct V_74 * V_75 , void * V_77 , T_1 * V_76 )
{
return F_51 ( V_77 , & V_51 , V_76 ) ;
}
static void F_52 ( struct V_74 * V_75 , void * V_77 )
{
F_33 ( & V_49 ) ;
}
static int F_53 ( struct V_74 * V_75 , void * V_77 )
{
struct V_23 * V_16 = V_77 ;
char V_78 = F_11 ( V_16 ) ? 'r' : 'p' ;
int V_44 ;
F_54 ( V_75 , L_20 , V_78 , V_16 -> V_33 . V_34 . V_35 -> system ,
F_24 ( & V_16 -> V_33 . V_34 ) ) ;
F_54 ( V_75 , L_21 , V_16 -> V_47 , ( void * ) V_16 -> V_17 ) ;
for ( V_44 = 0 ; V_44 < V_16 -> V_33 . V_45 ; V_44 ++ )
F_54 ( V_75 , L_22 , V_16 -> V_33 . args [ V_44 ] . V_36 , V_16 -> V_33 . args [ V_44 ] . V_79 ) ;
F_54 ( V_75 , L_23 ) ;
return 0 ;
}
static int F_55 ( struct V_46 * V_46 , struct V_80 * V_80 )
{
int V_5 ;
if ( ( V_80 -> V_81 & V_82 ) && ( V_80 -> V_83 & V_84 ) ) {
V_5 = F_46 () ;
if ( V_5 )
return V_5 ;
}
return F_56 ( V_80 , & V_85 ) ;
}
static T_2 F_57 ( struct V_80 * V_80 , const char V_7 * V_86 ,
T_3 V_87 , T_1 * V_88 )
{
return F_58 ( V_80 , V_86 , V_87 , V_88 , F_34 ) ;
}
static int F_59 ( struct V_74 * V_75 , void * V_77 )
{
struct V_23 * V_16 = V_77 ;
F_54 ( V_75 , L_24 , V_16 -> V_47 ,
F_24 ( & V_16 -> V_33 . V_34 ) , V_16 -> V_89 ) ;
return 0 ;
}
static int F_60 ( struct V_46 * V_46 , struct V_80 * V_80 )
{
return F_56 ( V_80 , & V_90 ) ;
}
static int F_61 ( void )
{
int V_91 , V_92 ;
V_93 = F_62 ( struct V_93 ) ;
if ( V_93 == NULL )
return - V_32 ;
F_63 (cpu) {
struct V_94 * V_95 = F_64 ( F_65 ( V_91 ) ,
V_31 , 0 ) ;
if ( V_95 == NULL ) {
V_92 = V_91 ;
goto V_96;
}
F_66 ( V_93 , V_91 ) -> V_55 = F_67 ( V_95 ) ;
F_68 ( & F_66 ( V_93 , V_91 ) -> V_97 ) ;
}
return 0 ;
V_96:
F_63 (cpu) {
if ( V_91 == V_92 )
break;
F_69 ( ( unsigned long ) F_66 ( V_93 , V_91 ) -> V_55 ) ;
}
F_70 ( V_93 ) ;
return - V_32 ;
}
static int F_71 ( void )
{
int V_5 = 0 ;
F_72 ( ! F_73 ( & V_98 ) ) ;
if ( V_99 ++ == 0 ) {
V_5 = F_61 () ;
if ( V_5 < 0 )
V_99 -- ;
}
return V_5 ;
}
static void F_74 ( void )
{
int V_91 ;
F_72 ( ! F_73 ( & V_98 ) ) ;
if ( -- V_99 == 0 ) {
F_63 (cpu)
F_69 ( ( unsigned long ) F_66 ( V_93 ,
V_91 ) -> V_55 ) ;
F_70 ( V_93 ) ;
V_93 = NULL ;
}
}
static struct V_93 * F_75 ( void )
{
struct V_93 * V_100 ;
int V_91 ;
V_91 = F_76 () ;
V_100 = F_66 ( V_93 , V_91 ) ;
F_29 ( & V_100 -> V_97 ) ;
return V_100 ;
}
static void F_77 ( struct V_93 * V_100 )
{
F_33 ( & V_100 -> V_97 ) ;
}
static void F_78 ( struct V_23 * V_16 ,
unsigned long V_101 , struct V_3 * V_4 ,
struct V_93 * V_100 , int V_102 ,
struct V_103 * V_104 )
{
struct V_105 * V_106 ;
struct V_107 * V_27 ;
struct V_108 * V_86 ;
void * V_109 ;
int V_72 , V_110 ;
struct V_111 * V_34 = & V_16 -> V_33 . V_34 ;
F_79 ( V_34 != V_104 -> V_112 ) ;
if ( F_80 ( V_16 -> V_33 . V_72 + V_102 > V_113 ) )
return;
if ( F_81 ( V_104 ) )
return;
V_110 = F_82 ( F_11 ( V_16 ) ) ;
V_72 = V_110 + V_16 -> V_33 . V_72 + V_102 ;
V_27 = F_83 ( & V_86 , V_104 ,
V_34 -> V_27 . type , V_72 , 0 , 0 ) ;
if ( ! V_27 )
return;
V_106 = F_84 ( V_27 ) ;
if ( F_11 ( V_16 ) ) {
V_106 -> V_14 [ 0 ] = V_101 ;
V_106 -> V_14 [ 1 ] = F_85 ( V_4 ) ;
V_109 = F_86 ( V_106 , true ) ;
} else {
V_106 -> V_14 [ 0 ] = F_85 ( V_4 ) ;
V_109 = F_86 ( V_106 , false ) ;
}
memcpy ( V_109 , V_100 -> V_55 , V_16 -> V_33 . V_72 + V_102 ) ;
F_87 ( V_104 , V_86 , V_27 , V_106 , 0 , 0 ) ;
}
static int F_88 ( struct V_23 * V_16 , struct V_3 * V_4 ,
struct V_93 * V_100 , int V_102 )
{
struct V_114 * V_115 ;
if ( F_11 ( V_16 ) )
return 0 ;
F_89 () ;
F_90 (link, &tu->tp.files, list)
F_78 ( V_16 , 0 , V_4 , V_100 , V_102 , V_115 -> V_80 ) ;
F_91 () ;
return 0 ;
}
static void F_92 ( struct V_23 * V_16 , unsigned long V_101 ,
struct V_3 * V_4 ,
struct V_93 * V_100 , int V_102 )
{
struct V_114 * V_115 ;
F_89 () ;
F_90 (link, &tu->tp.files, list)
F_78 ( V_16 , V_101 , V_4 , V_100 , V_102 , V_115 -> V_80 ) ;
F_91 () ;
}
static enum V_116
F_93 ( struct V_117 * V_118 , int V_42 , struct V_119 * V_27 )
{
struct V_105 * V_106 ;
struct V_120 * V_121 = & V_118 -> V_122 ;
struct V_23 * V_16 ;
T_4 * V_109 ;
int V_44 ;
V_106 = (struct V_105 * ) V_118 -> V_123 ;
V_16 = F_94 ( V_27 , struct V_23 , V_33 . V_34 . V_27 ) ;
if ( F_11 ( V_16 ) ) {
if ( ! F_95 ( V_121 , L_25 ,
F_24 ( & V_16 -> V_33 . V_34 ) ,
V_106 -> V_14 [ 1 ] , V_106 -> V_14 [ 0 ] ) )
goto V_124;
V_109 = F_86 ( V_106 , true ) ;
} else {
if ( ! F_95 ( V_121 , L_26 ,
F_24 ( & V_16 -> V_33 . V_34 ) ,
V_106 -> V_14 [ 0 ] ) )
goto V_124;
V_109 = F_86 ( V_106 , false ) ;
}
for ( V_44 = 0 ; V_44 < V_16 -> V_33 . V_45 ; V_44 ++ ) {
struct V_70 * V_71 = & V_16 -> V_33 . args [ V_44 ] ;
if ( ! V_71 -> type -> V_125 ( V_121 , V_71 -> V_36 , V_109 + V_71 -> V_17 , V_106 ) )
goto V_124;
}
if ( F_96 ( V_121 , L_23 ) )
return V_126 ;
V_124:
return V_127 ;
}
static int
F_97 ( struct V_23 * V_16 , struct V_103 * V_80 ,
T_5 V_19 )
{
bool V_128 = F_98 ( & V_16 -> V_33 ) ;
struct V_114 * V_115 = NULL ;
int V_5 ;
if ( V_80 ) {
V_115 = F_99 ( sizeof( * V_115 ) , V_31 ) ;
if ( ! V_115 )
return - V_32 ;
V_115 -> V_80 = V_80 ;
F_100 ( & V_115 -> V_37 , & V_16 -> V_33 . V_38 ) ;
V_16 -> V_33 . V_42 |= V_129 ;
} else
V_16 -> V_33 . V_42 |= V_130 ;
V_5 = F_71 () ;
if ( V_5 < 0 )
return V_5 ;
F_79 ( ! F_9 ( & V_16 -> V_19 ) ) ;
if ( V_128 )
return 0 ;
V_16 -> V_24 . V_19 = V_19 ;
V_5 = F_101 ( V_16 -> V_46 , V_16 -> V_17 , & V_16 -> V_24 ) ;
if ( V_5 ) {
if ( V_80 ) {
F_27 ( & V_115 -> V_37 ) ;
F_18 ( V_115 ) ;
V_16 -> V_33 . V_42 &= ~ V_129 ;
} else
V_16 -> V_33 . V_42 &= ~ V_130 ;
}
return V_5 ;
}
static void
F_102 ( struct V_23 * V_16 , struct V_103 * V_80 )
{
if ( ! F_98 ( & V_16 -> V_33 ) )
return;
if ( V_80 ) {
struct V_114 * V_115 ;
V_115 = F_103 ( & V_16 -> V_33 , V_80 ) ;
if ( ! V_115 )
return;
F_104 ( & V_115 -> V_37 ) ;
F_105 () ;
F_18 ( V_115 ) ;
if ( ! F_10 ( & V_16 -> V_33 . V_38 ) )
return;
}
F_79 ( ! F_9 ( & V_16 -> V_19 ) ) ;
F_106 ( V_16 -> V_46 , V_16 -> V_17 , & V_16 -> V_24 ) ;
V_16 -> V_33 . V_42 &= V_80 ? ~ V_129 : ~ V_130 ;
F_74 () ;
}
static int F_107 ( struct V_111 * V_112 )
{
int V_5 , V_44 , V_72 ;
struct V_105 V_131 ;
struct V_23 * V_16 = V_112 -> V_109 ;
if ( F_11 ( V_16 ) ) {
F_108 (unsigned long, vaddr[0], FIELD_STRING_FUNC, 0 ) ;
F_108 (unsigned long, vaddr[1], FIELD_STRING_RETIP, 0 ) ;
V_72 = F_82 ( true ) ;
} else {
F_108 (unsigned long, vaddr[0], FIELD_STRING_IP, 0 ) ;
V_72 = F_82 ( false ) ;
}
for ( V_44 = 0 ; V_44 < V_16 -> V_33 . V_45 ; V_44 ++ ) {
struct V_70 * V_71 = & V_16 -> V_33 . args [ V_44 ] ;
V_5 = F_109 ( V_112 , V_71 -> type -> V_132 ,
V_71 -> V_36 , V_72 + V_71 -> V_17 ,
V_71 -> type -> V_72 , V_71 -> type -> V_133 ,
V_134 ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
static bool
F_110 ( struct V_18 * V_19 , struct V_135 * V_136 )
{
struct V_137 * V_27 ;
if ( V_19 -> V_21 )
return true ;
F_23 (event, &filter->perf_events, hw.tp_list) {
if ( V_27 -> V_138 . V_139 -> V_136 == V_136 )
return true ;
}
return false ;
}
static inline bool
F_111 ( struct V_23 * V_16 , struct V_137 * V_27 )
{
return F_110 ( & V_16 -> V_19 , V_27 -> V_138 . V_139 -> V_136 ) ;
}
static int F_112 ( struct V_23 * V_16 , struct V_137 * V_27 )
{
bool V_140 ;
F_113 ( & V_16 -> V_19 . V_20 ) ;
if ( V_27 -> V_138 . V_139 ) {
V_140 = V_16 -> V_19 . V_21 ||
V_27 -> V_141 || V_27 -> V_142 . V_143 ||
F_111 ( V_16 , V_27 ) ;
F_114 ( & V_27 -> V_138 . V_144 , & V_16 -> V_19 . V_22 ) ;
} else {
V_140 = V_16 -> V_19 . V_21 ;
V_16 -> V_19 . V_21 ++ ;
}
F_115 ( & V_16 -> V_19 . V_20 ) ;
if ( ! V_140 )
F_116 ( V_16 -> V_46 , V_16 -> V_17 , & V_16 -> V_24 , true ) ;
return 0 ;
}
static int F_117 ( struct V_23 * V_16 , struct V_137 * V_27 )
{
bool V_140 ;
F_113 ( & V_16 -> V_19 . V_20 ) ;
if ( V_27 -> V_138 . V_139 ) {
F_27 ( & V_27 -> V_138 . V_144 ) ;
V_140 = V_16 -> V_19 . V_21 ||
( V_27 -> V_138 . V_139 -> V_42 & V_145 ) ||
F_111 ( V_16 , V_27 ) ;
} else {
V_16 -> V_19 . V_21 -- ;
V_140 = V_16 -> V_19 . V_21 ;
}
F_115 ( & V_16 -> V_19 . V_20 ) ;
if ( ! V_140 )
F_116 ( V_16 -> V_46 , V_16 -> V_17 , & V_16 -> V_24 , false ) ;
return 0 ;
}
static bool F_118 ( struct V_146 * V_147 ,
enum V_148 V_149 , struct V_135 * V_136 )
{
struct V_23 * V_16 ;
int V_5 ;
V_16 = F_94 ( V_147 , struct V_23 , V_24 ) ;
F_119 ( & V_16 -> V_19 . V_20 ) ;
V_5 = F_110 ( & V_16 -> V_19 , V_136 ) ;
F_120 ( & V_16 -> V_19 . V_20 ) ;
return V_5 ;
}
static void F_121 ( struct V_23 * V_16 ,
unsigned long V_101 , struct V_3 * V_4 ,
struct V_93 * V_100 , int V_102 )
{
struct V_111 * V_34 = & V_16 -> V_33 . V_34 ;
struct V_105 * V_106 ;
struct V_150 * V_151 ;
void * V_109 ;
int V_72 , V_110 ;
int V_152 ;
V_110 = F_82 ( F_11 ( V_16 ) ) ;
V_72 = V_110 + V_16 -> V_33 . V_72 + V_102 ;
V_72 = F_122 ( V_72 + sizeof( V_153 ) , sizeof( V_154 ) ) - sizeof( V_153 ) ;
if ( F_123 ( V_72 > V_155 , L_27 ) )
return;
F_124 () ;
V_151 = F_125 ( V_34 -> V_22 ) ;
if ( F_126 ( V_151 ) )
goto V_156;
V_106 = F_127 ( V_72 , V_34 -> V_27 . type , V_4 , & V_152 ) ;
if ( ! V_106 )
goto V_156;
if ( F_11 ( V_16 ) ) {
V_106 -> V_14 [ 0 ] = V_101 ;
V_106 -> V_14 [ 1 ] = F_85 ( V_4 ) ;
V_109 = F_86 ( V_106 , true ) ;
} else {
V_106 -> V_14 [ 0 ] = F_85 ( V_4 ) ;
V_109 = F_86 ( V_106 , false ) ;
}
memcpy ( V_109 , V_100 -> V_55 , V_16 -> V_33 . V_72 + V_102 ) ;
if ( V_72 - V_110 > V_16 -> V_33 . V_72 + V_102 ) {
int V_157 = V_16 -> V_33 . V_72 + V_102 ;
memset ( V_109 + V_157 , 0 , V_72 - V_110 - V_157 ) ;
}
F_128 ( V_106 , V_72 , V_152 , 0 , 1 , V_4 , V_151 , NULL ) ;
V_156:
F_129 () ;
}
static int F_130 ( struct V_23 * V_16 , struct V_3 * V_4 ,
struct V_93 * V_100 , int V_102 )
{
if ( ! F_118 ( & V_16 -> V_24 , 0 , V_12 -> V_136 ) )
return V_158 ;
if ( ! F_11 ( V_16 ) )
F_121 ( V_16 , 0 , V_4 , V_100 , V_102 ) ;
return 0 ;
}
static void F_131 ( struct V_23 * V_16 , unsigned long V_101 ,
struct V_3 * V_4 ,
struct V_93 * V_100 , int V_102 )
{
F_121 ( V_16 , V_101 , V_4 , V_100 , V_102 ) ;
}
static int
F_132 ( struct V_111 * V_27 , enum V_159 type ,
void * V_109 )
{
struct V_23 * V_16 = V_27 -> V_109 ;
struct V_103 * V_80 = V_109 ;
switch ( type ) {
case V_160 :
return F_97 ( V_16 , V_80 , NULL ) ;
case V_161 :
F_102 ( V_16 , V_80 ) ;
return 0 ;
#ifdef F_133
case V_162 :
return F_97 ( V_16 , NULL , F_118 ) ;
case V_163 :
F_102 ( V_16 , NULL ) ;
return 0 ;
case V_164 :
return F_112 ( V_16 , V_109 ) ;
case V_165 :
return F_117 ( V_16 , V_109 ) ;
#endif
default:
return 0 ;
}
return 0 ;
}
static int V_40 ( struct V_146 * V_166 , struct V_3 * V_4 )
{
struct V_23 * V_16 ;
struct V_10 V_11 ;
struct V_93 * V_100 ;
int V_102 , V_110 ;
int V_5 = 0 ;
V_16 = F_94 ( V_166 , struct V_23 , V_24 ) ;
V_16 -> V_89 ++ ;
V_11 . V_16 = V_16 ;
V_11 . V_15 = F_85 ( V_4 ) ;
V_12 -> V_13 -> V_14 = ( unsigned long ) & V_11 ;
#ifdef F_133
if ( ( V_16 -> V_33 . V_42 & V_129 ) == 0 &&
! F_118 ( & V_16 -> V_24 , 0 , V_12 -> V_136 ) )
return V_158 ;
#endif
if ( F_80 ( ! V_93 ) )
return 0 ;
V_102 = F_134 ( & V_16 -> V_33 , V_4 ) ;
V_110 = F_82 ( F_11 ( V_16 ) ) ;
V_100 = F_75 () ;
F_135 ( V_110 , & V_16 -> V_33 , V_4 , V_100 -> V_55 , V_102 ) ;
if ( V_16 -> V_33 . V_42 & V_129 )
V_5 |= F_88 ( V_16 , V_4 , V_100 , V_102 ) ;
#ifdef F_133
if ( V_16 -> V_33 . V_42 & V_130 )
V_5 |= F_130 ( V_16 , V_4 , V_100 , V_102 ) ;
#endif
F_77 ( V_100 ) ;
return V_5 ;
}
static int V_41 ( struct V_146 * V_166 ,
unsigned long V_101 , struct V_3 * V_4 )
{
struct V_23 * V_16 ;
struct V_10 V_11 ;
struct V_93 * V_100 ;
int V_102 , V_110 ;
V_16 = F_94 ( V_166 , struct V_23 , V_24 ) ;
V_11 . V_16 = V_16 ;
V_11 . V_15 = V_101 ;
V_12 -> V_13 -> V_14 = ( unsigned long ) & V_11 ;
if ( F_80 ( ! V_93 ) )
return 0 ;
V_102 = F_134 ( & V_16 -> V_33 , V_4 ) ;
V_110 = F_82 ( F_11 ( V_16 ) ) ;
V_100 = F_75 () ;
F_135 ( V_110 , & V_16 -> V_33 , V_4 , V_100 -> V_55 , V_102 ) ;
if ( V_16 -> V_33 . V_42 & V_129 )
F_92 ( V_16 , V_101 , V_4 , V_100 , V_102 ) ;
#ifdef F_133
if ( V_16 -> V_33 . V_42 & V_130 )
F_131 ( V_16 , V_101 , V_4 , V_100 , V_102 ) ;
#endif
F_77 ( V_100 ) ;
return 0 ;
}
static int F_30 ( struct V_23 * V_16 )
{
struct V_111 * V_34 = & V_16 -> V_33 . V_34 ;
int V_5 ;
F_8 ( & V_34 -> V_35 -> V_167 ) ;
V_34 -> V_27 . V_168 = & V_169 ;
V_34 -> V_35 -> V_170 = F_107 ;
if ( F_136 ( & V_16 -> V_33 , F_11 ( V_16 ) ) < 0 )
return - V_32 ;
V_5 = F_137 ( & V_34 -> V_27 ) ;
if ( ! V_5 ) {
F_18 ( V_34 -> V_171 ) ;
return - V_172 ;
}
V_34 -> V_42 = 0 ;
V_34 -> V_35 -> V_173 = F_132 ;
V_34 -> V_109 = V_16 ;
V_5 = F_138 ( V_34 ) ;
if ( V_5 ) {
F_35 ( L_28 ,
F_24 ( V_34 ) ) ;
F_18 ( V_34 -> V_171 ) ;
F_139 ( & V_34 -> V_27 ) ;
}
return V_5 ;
}
static int F_26 ( struct V_23 * V_16 )
{
int V_5 ;
V_5 = F_140 ( & V_16 -> V_33 . V_34 ) ;
if ( V_5 )
return V_5 ;
F_18 ( V_16 -> V_33 . V_34 . V_171 ) ;
V_16 -> V_33 . V_34 . V_171 = NULL ;
return 0 ;
}
static T_6 int F_141 ( void )
{
struct V_64 * V_174 ;
V_174 = F_142 () ;
if ( ! V_174 )
return 0 ;
F_143 ( L_29 , 0644 , V_174 ,
NULL , & V_175 ) ;
F_143 ( L_30 , 0444 , V_174 ,
NULL , & V_176 ) ;
return 0 ;
}
