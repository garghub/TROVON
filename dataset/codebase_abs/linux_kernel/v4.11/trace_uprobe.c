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
return V_16 ;
error:
F_18 ( V_16 -> V_33 . V_34 . V_36 ) ;
F_18 ( V_16 ) ;
return F_14 ( - V_32 ) ;
}
static void F_19 ( struct V_23 * V_16 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_16 -> V_33 . V_43 ; V_42 ++ )
F_20 ( & V_16 -> V_33 . args [ V_42 ] ) ;
F_21 ( V_16 -> V_44 ) ;
F_18 ( V_16 -> V_33 . V_34 . V_35 -> system ) ;
F_18 ( V_16 -> V_33 . V_34 . V_36 ) ;
F_18 ( V_16 -> V_45 ) ;
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
struct V_23 * V_46 ;
int V_5 ;
F_29 ( & V_47 ) ;
V_46 = F_22 ( F_24 ( & V_16 -> V_33 . V_34 ) ,
V_16 -> V_33 . V_34 . V_35 -> system ) ;
if ( V_46 ) {
V_5 = F_25 ( V_46 ) ;
if ( V_5 )
goto V_48;
}
V_5 = F_30 ( V_16 ) ;
if ( V_5 ) {
F_31 ( L_1 , V_5 ) ;
goto V_48;
}
F_32 ( & V_16 -> V_37 , & V_49 ) ;
V_48:
F_33 ( & V_47 ) ;
return V_5 ;
}
static int F_34 ( int V_50 , char * * V_51 )
{
struct V_23 * V_16 ;
struct V_44 * V_44 ;
char * V_52 , * V_27 , * V_26 , * V_45 ;
char V_53 [ V_54 ] ;
struct V_55 V_55 ;
unsigned long V_17 ;
bool V_56 , V_57 ;
int V_42 , V_5 ;
V_44 = NULL ;
V_5 = 0 ;
V_56 = false ;
V_57 = false ;
V_27 = NULL ;
V_26 = NULL ;
if ( V_51 [ 0 ] [ 0 ] == '-' )
V_56 = true ;
else if ( V_51 [ 0 ] [ 0 ] == 'r' )
V_57 = true ;
else if ( V_51 [ 0 ] [ 0 ] != 'p' ) {
F_35 ( L_2 ) ;
return - V_30 ;
}
if ( V_51 [ 0 ] [ 1 ] == ':' ) {
V_27 = & V_51 [ 0 ] [ 2 ] ;
V_52 = strchr ( V_27 , '/' ) ;
if ( V_52 ) {
V_26 = V_27 ;
V_27 = V_52 + 1 ;
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
V_26 = V_58 ;
if ( V_56 ) {
int V_5 ;
if ( ! V_27 ) {
F_35 ( L_5 ) ;
return - V_30 ;
}
F_29 ( & V_47 ) ;
V_16 = F_22 ( V_27 , V_26 ) ;
if ( ! V_16 ) {
F_33 ( & V_47 ) ;
F_35 ( L_6 , V_26 , V_27 ) ;
return - V_59 ;
}
V_5 = F_25 ( V_16 ) ;
F_33 ( & V_47 ) ;
return V_5 ;
}
if ( V_50 < 2 ) {
F_35 ( L_7 ) ;
return - V_30 ;
}
V_52 = strrchr ( V_51 [ 1 ] , ':' ) ;
if ( ! V_52 ) {
V_5 = - V_30 ;
goto V_60;
}
* V_52 ++ = '\0' ;
V_45 = V_51 [ 1 ] ;
V_5 = F_36 ( V_45 , V_61 , & V_55 ) ;
if ( V_5 )
goto V_60;
V_44 = F_37 ( F_38 ( V_55 . V_62 ) ) ;
F_39 ( & V_55 ) ;
if ( ! V_44 || ! F_40 ( V_44 -> V_63 ) ) {
V_5 = - V_30 ;
goto V_60;
}
V_5 = F_41 ( V_52 , 0 , & V_17 ) ;
if ( V_5 )
goto V_60;
V_50 -= 2 ;
V_51 += 2 ;
if ( ! V_27 ) {
char * V_64 ;
char * V_65 ;
V_64 = F_17 ( F_42 ( V_45 ) , V_31 ) ;
if ( ! V_64 ) {
V_5 = - V_32 ;
goto V_60;
}
V_65 = strpbrk ( V_64 , L_8 ) ;
if ( V_65 )
* V_65 = '\0' ;
snprintf ( V_53 , V_54 , L_9 , 'p' , V_64 , V_17 ) ;
V_27 = V_53 ;
F_18 ( V_64 ) ;
}
V_16 = F_12 ( V_26 , V_27 , V_50 , V_57 ) ;
if ( F_43 ( V_16 ) ) {
F_35 ( L_10 , ( int ) F_44 ( V_16 ) ) ;
V_5 = F_44 ( V_16 ) ;
goto V_60;
}
V_16 -> V_17 = V_17 ;
V_16 -> V_44 = V_44 ;
V_16 -> V_45 = F_17 ( V_45 , V_31 ) ;
if ( ! V_16 -> V_45 ) {
F_35 ( L_11 ) ;
V_5 = - V_32 ;
goto error;
}
V_5 = 0 ;
for ( V_42 = 0 ; V_42 < V_50 && V_42 < V_66 ; V_42 ++ ) {
struct V_67 * V_68 = & V_16 -> V_33 . args [ V_42 ] ;
V_16 -> V_33 . V_43 ++ ;
V_52 = strchr ( V_51 [ V_42 ] , '=' ) ;
if ( V_52 ) {
* V_52 ++ = '\0' ;
V_68 -> V_36 = F_17 ( V_51 [ V_42 ] , V_31 ) ;
} else {
V_52 = V_51 [ V_42 ] ;
snprintf ( V_53 , V_54 , L_12 , V_42 + 1 ) ;
V_68 -> V_36 = F_17 ( V_53 , V_31 ) ;
}
if ( ! V_68 -> V_36 ) {
F_35 ( L_13 , V_42 ) ;
V_5 = - V_32 ;
goto error;
}
if ( ! F_13 ( V_68 -> V_36 ) ) {
F_35 ( L_14 , V_42 , V_68 -> V_36 ) ;
V_5 = - V_30 ;
goto error;
}
if ( F_45 ( V_68 -> V_36 , V_16 -> V_33 . args , V_42 ) ) {
F_35 ( L_15
L_16 , V_42 , V_51 [ V_42 ] ) ;
V_5 = - V_30 ;
goto error;
}
V_5 = F_46 ( V_52 , & V_16 -> V_33 . V_69 , V_68 ,
V_57 , false ,
V_70 ) ;
if ( V_5 ) {
F_35 ( L_17 , V_42 , V_5 ) ;
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
V_60:
F_21 ( V_44 ) ;
F_35 ( L_18 ) ;
return V_5 ;
}
static int F_47 ( void )
{
struct V_23 * V_16 ;
int V_5 = 0 ;
F_29 ( & V_47 ) ;
while ( ! F_10 ( & V_49 ) ) {
V_16 = F_48 ( V_49 . V_71 , struct V_23 , V_37 ) ;
V_5 = F_25 ( V_16 ) ;
if ( V_5 )
break;
}
F_33 ( & V_47 ) ;
return V_5 ;
}
static void * F_49 ( struct V_72 * V_73 , T_1 * V_74 )
{
F_29 ( & V_47 ) ;
return F_50 ( & V_49 , * V_74 ) ;
}
static void * F_51 ( struct V_72 * V_73 , void * V_75 , T_1 * V_74 )
{
return F_52 ( V_75 , & V_49 , V_74 ) ;
}
static void F_53 ( struct V_72 * V_73 , void * V_75 )
{
F_33 ( & V_47 ) ;
}
static int F_54 ( struct V_72 * V_73 , void * V_75 )
{
struct V_23 * V_16 = V_75 ;
char V_76 = F_11 ( V_16 ) ? 'r' : 'p' ;
int V_42 ;
F_55 ( V_73 , L_19 , V_76 , V_16 -> V_33 . V_34 . V_35 -> system ,
F_24 ( & V_16 -> V_33 . V_34 ) ) ;
F_55 ( V_73 , L_20 , V_16 -> V_45 ) ;
if ( V_16 -> V_17 ) {
F_55 ( V_73 , L_21 , ( void * ) V_16 -> V_17 ) ;
} else {
switch ( sizeof( void * ) ) {
case 4 :
F_55 ( V_73 , L_22 ) ;
break;
case 8 :
default:
F_55 ( V_73 , L_23 ) ;
break;
}
}
for ( V_42 = 0 ; V_42 < V_16 -> V_33 . V_43 ; V_42 ++ )
F_55 ( V_73 , L_24 , V_16 -> V_33 . args [ V_42 ] . V_36 , V_16 -> V_33 . args [ V_42 ] . V_77 ) ;
F_56 ( V_73 , '\n' ) ;
return 0 ;
}
static int F_57 ( struct V_44 * V_44 , struct V_78 * V_78 )
{
int V_5 ;
if ( ( V_78 -> V_79 & V_80 ) && ( V_78 -> V_81 & V_82 ) ) {
V_5 = F_47 () ;
if ( V_5 )
return V_5 ;
}
return F_58 ( V_78 , & V_83 ) ;
}
static T_2 F_59 ( struct V_78 * V_78 , const char V_7 * V_84 ,
T_3 V_85 , T_1 * V_86 )
{
return F_60 ( V_78 , V_84 , V_85 , V_86 , F_34 ) ;
}
static int F_61 ( struct V_72 * V_73 , void * V_75 )
{
struct V_23 * V_16 = V_75 ;
F_55 ( V_73 , L_25 , V_16 -> V_45 ,
F_24 ( & V_16 -> V_33 . V_34 ) , V_16 -> V_87 ) ;
return 0 ;
}
static int F_62 ( struct V_44 * V_44 , struct V_78 * V_78 )
{
return F_58 ( V_78 , & V_88 ) ;
}
static int F_63 ( void )
{
int V_89 , V_90 ;
V_91 = F_64 ( struct V_91 ) ;
if ( V_91 == NULL )
return - V_32 ;
F_65 (cpu) {
struct V_92 * V_93 = F_66 ( F_67 ( V_89 ) ,
V_31 , 0 ) ;
if ( V_93 == NULL ) {
V_90 = V_89 ;
goto V_94;
}
F_68 ( V_91 , V_89 ) -> V_53 = F_69 ( V_93 ) ;
F_70 ( & F_68 ( V_91 , V_89 ) -> V_95 ) ;
}
return 0 ;
V_94:
F_65 (cpu) {
if ( V_89 == V_90 )
break;
F_71 ( ( unsigned long ) F_68 ( V_91 , V_89 ) -> V_53 ) ;
}
F_72 ( V_91 ) ;
return - V_32 ;
}
static int F_73 ( void )
{
int V_5 = 0 ;
F_74 ( ! F_75 ( & V_96 ) ) ;
if ( V_97 ++ == 0 ) {
V_5 = F_63 () ;
if ( V_5 < 0 )
V_97 -- ;
}
return V_5 ;
}
static void F_76 ( void )
{
int V_89 ;
F_74 ( ! F_75 ( & V_96 ) ) ;
if ( -- V_97 == 0 ) {
F_65 (cpu)
F_71 ( ( unsigned long ) F_68 ( V_91 ,
V_89 ) -> V_53 ) ;
F_72 ( V_91 ) ;
V_91 = NULL ;
}
}
static struct V_91 * F_77 ( void )
{
struct V_91 * V_98 ;
int V_89 ;
V_89 = F_78 () ;
V_98 = F_68 ( V_91 , V_89 ) ;
F_29 ( & V_98 -> V_95 ) ;
return V_98 ;
}
static void F_79 ( struct V_91 * V_98 )
{
F_33 ( & V_98 -> V_95 ) ;
}
static void F_80 ( struct V_23 * V_16 ,
unsigned long V_99 , struct V_3 * V_4 ,
struct V_91 * V_98 , int V_100 ,
struct V_101 * V_102 )
{
struct V_103 * V_104 ;
struct V_105 * V_27 ;
struct V_106 * V_84 ;
void * V_107 ;
int V_69 , V_108 ;
struct V_109 * V_34 = & V_16 -> V_33 . V_34 ;
F_81 ( V_34 != V_102 -> V_110 ) ;
if ( F_82 ( V_16 -> V_33 . V_69 + V_100 > V_111 ) )
return;
if ( F_83 ( V_102 ) )
return;
V_108 = F_84 ( F_11 ( V_16 ) ) ;
V_69 = V_108 + V_16 -> V_33 . V_69 + V_100 ;
V_27 = F_85 ( & V_84 , V_102 ,
V_34 -> V_27 . type , V_69 , 0 , 0 ) ;
if ( ! V_27 )
return;
V_104 = F_86 ( V_27 ) ;
if ( F_11 ( V_16 ) ) {
V_104 -> V_14 [ 0 ] = V_99 ;
V_104 -> V_14 [ 1 ] = F_87 ( V_4 ) ;
V_107 = F_88 ( V_104 , true ) ;
} else {
V_104 -> V_14 [ 0 ] = F_87 ( V_4 ) ;
V_107 = F_88 ( V_104 , false ) ;
}
memcpy ( V_107 , V_98 -> V_53 , V_16 -> V_33 . V_69 + V_100 ) ;
F_89 ( V_102 , V_84 , V_27 , V_104 , 0 , 0 ) ;
}
static int F_90 ( struct V_23 * V_16 , struct V_3 * V_4 ,
struct V_91 * V_98 , int V_100 )
{
struct V_112 * V_113 ;
if ( F_11 ( V_16 ) )
return 0 ;
F_91 () ;
F_92 (link, &tu->tp.files, list)
F_80 ( V_16 , 0 , V_4 , V_98 , V_100 , V_113 -> V_78 ) ;
F_93 () ;
return 0 ;
}
static void F_94 ( struct V_23 * V_16 , unsigned long V_99 ,
struct V_3 * V_4 ,
struct V_91 * V_98 , int V_100 )
{
struct V_112 * V_113 ;
F_91 () ;
F_92 (link, &tu->tp.files, list)
F_80 ( V_16 , V_99 , V_4 , V_98 , V_100 , V_113 -> V_78 ) ;
F_93 () ;
}
static enum V_114
F_95 ( struct V_115 * V_116 , int V_117 , struct V_118 * V_27 )
{
struct V_103 * V_104 ;
struct V_119 * V_120 = & V_116 -> V_121 ;
struct V_23 * V_16 ;
T_4 * V_107 ;
int V_42 ;
V_104 = (struct V_103 * ) V_116 -> V_122 ;
V_16 = F_96 ( V_27 , struct V_23 , V_33 . V_34 . V_27 ) ;
if ( F_11 ( V_16 ) ) {
F_97 ( V_120 , L_26 ,
F_24 ( & V_16 -> V_33 . V_34 ) ,
V_104 -> V_14 [ 1 ] , V_104 -> V_14 [ 0 ] ) ;
V_107 = F_88 ( V_104 , true ) ;
} else {
F_97 ( V_120 , L_27 ,
F_24 ( & V_16 -> V_33 . V_34 ) ,
V_104 -> V_14 [ 0 ] ) ;
V_107 = F_88 ( V_104 , false ) ;
}
for ( V_42 = 0 ; V_42 < V_16 -> V_33 . V_43 ; V_42 ++ ) {
struct V_67 * V_68 = & V_16 -> V_33 . args [ V_42 ] ;
if ( ! V_68 -> type -> V_123 ( V_120 , V_68 -> V_36 , V_107 + V_68 -> V_17 , V_104 ) )
goto V_124;
}
F_98 ( V_120 , '\n' ) ;
V_124:
return F_99 ( V_120 ) ;
}
static int
F_100 ( struct V_23 * V_16 , struct V_101 * V_78 ,
T_5 V_19 )
{
bool V_125 = F_101 ( & V_16 -> V_33 ) ;
struct V_112 * V_113 = NULL ;
int V_5 ;
if ( V_78 ) {
if ( V_16 -> V_33 . V_117 & V_126 )
return - V_127 ;
V_113 = F_102 ( sizeof( * V_113 ) , V_31 ) ;
if ( ! V_113 )
return - V_32 ;
V_113 -> V_78 = V_78 ;
F_103 ( & V_113 -> V_37 , & V_16 -> V_33 . V_38 ) ;
V_16 -> V_33 . V_117 |= V_128 ;
} else {
if ( V_16 -> V_33 . V_117 & V_128 )
return - V_127 ;
V_16 -> V_33 . V_117 |= V_126 ;
}
F_81 ( ! F_9 ( & V_16 -> V_19 ) ) ;
if ( V_125 )
return 0 ;
V_5 = F_73 () ;
if ( V_5 )
goto V_129;
V_16 -> V_24 . V_19 = V_19 ;
V_5 = F_104 ( V_16 -> V_44 , V_16 -> V_17 , & V_16 -> V_24 ) ;
if ( V_5 )
goto V_130;
return 0 ;
V_130:
F_76 () ;
V_129:
if ( V_78 ) {
F_27 ( & V_113 -> V_37 ) ;
F_18 ( V_113 ) ;
V_16 -> V_33 . V_117 &= ~ V_128 ;
} else {
V_16 -> V_33 . V_117 &= ~ V_126 ;
}
return V_5 ;
}
static void
F_105 ( struct V_23 * V_16 , struct V_101 * V_78 )
{
if ( ! F_101 ( & V_16 -> V_33 ) )
return;
if ( V_78 ) {
struct V_112 * V_113 ;
V_113 = F_106 ( & V_16 -> V_33 , V_78 ) ;
if ( ! V_113 )
return;
F_107 ( & V_113 -> V_37 ) ;
F_108 () ;
F_18 ( V_113 ) ;
if ( ! F_10 ( & V_16 -> V_33 . V_38 ) )
return;
}
F_81 ( ! F_9 ( & V_16 -> V_19 ) ) ;
F_109 ( V_16 -> V_44 , V_16 -> V_17 , & V_16 -> V_24 ) ;
V_16 -> V_33 . V_117 &= V_78 ? ~ V_128 : ~ V_126 ;
F_76 () ;
}
static int F_110 ( struct V_109 * V_110 )
{
int V_5 , V_42 , V_69 ;
struct V_103 V_131 ;
struct V_23 * V_16 = V_110 -> V_107 ;
if ( F_11 ( V_16 ) ) {
F_111 (unsigned long, vaddr[0], FIELD_STRING_FUNC, 0 ) ;
F_111 (unsigned long, vaddr[1], FIELD_STRING_RETIP, 0 ) ;
V_69 = F_84 ( true ) ;
} else {
F_111 (unsigned long, vaddr[0], FIELD_STRING_IP, 0 ) ;
V_69 = F_84 ( false ) ;
}
for ( V_42 = 0 ; V_42 < V_16 -> V_33 . V_43 ; V_42 ++ ) {
struct V_67 * V_68 = & V_16 -> V_33 . args [ V_42 ] ;
V_5 = F_112 ( V_110 , V_68 -> type -> V_132 ,
V_68 -> V_36 , V_69 + V_68 -> V_17 ,
V_68 -> type -> V_69 , V_68 -> type -> V_133 ,
V_134 ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
static bool
F_113 ( struct V_18 * V_19 , struct V_135 * V_136 )
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
F_114 ( struct V_23 * V_16 , struct V_137 * V_27 )
{
return F_113 ( & V_16 -> V_19 , V_27 -> V_138 . V_139 -> V_136 ) ;
}
static int F_115 ( struct V_23 * V_16 , struct V_137 * V_27 )
{
bool V_140 ;
F_116 ( & V_16 -> V_19 . V_20 ) ;
if ( V_27 -> V_138 . V_139 ) {
F_27 ( & V_27 -> V_138 . V_141 ) ;
V_140 = V_16 -> V_19 . V_21 ||
( V_27 -> V_138 . V_139 -> V_117 & V_142 ) ||
F_114 ( V_16 , V_27 ) ;
} else {
V_16 -> V_19 . V_21 -- ;
V_140 = V_16 -> V_19 . V_21 ;
}
F_117 ( & V_16 -> V_19 . V_20 ) ;
if ( ! V_140 )
return F_118 ( V_16 -> V_44 , V_16 -> V_17 , & V_16 -> V_24 , false ) ;
return 0 ;
}
static int F_119 ( struct V_23 * V_16 , struct V_137 * V_27 )
{
bool V_140 ;
int V_94 ;
F_116 ( & V_16 -> V_19 . V_20 ) ;
if ( V_27 -> V_138 . V_139 ) {
V_140 = V_16 -> V_19 . V_21 ||
V_27 -> V_143 || V_27 -> V_144 . V_145 ||
F_114 ( V_16 , V_27 ) ;
F_120 ( & V_27 -> V_138 . V_141 , & V_16 -> V_19 . V_22 ) ;
} else {
V_140 = V_16 -> V_19 . V_21 ;
V_16 -> V_19 . V_21 ++ ;
}
F_117 ( & V_16 -> V_19 . V_20 ) ;
V_94 = 0 ;
if ( ! V_140 ) {
V_94 = F_118 ( V_16 -> V_44 , V_16 -> V_17 , & V_16 -> V_24 , true ) ;
if ( V_94 )
F_115 ( V_16 , V_27 ) ;
}
return V_94 ;
}
static bool F_121 ( struct V_146 * V_147 ,
enum V_148 V_149 , struct V_135 * V_136 )
{
struct V_23 * V_16 ;
int V_5 ;
V_16 = F_96 ( V_147 , struct V_23 , V_24 ) ;
F_122 ( & V_16 -> V_19 . V_20 ) ;
V_5 = F_113 ( & V_16 -> V_19 , V_136 ) ;
F_123 ( & V_16 -> V_19 . V_20 ) ;
return V_5 ;
}
static void F_124 ( struct V_23 * V_16 ,
unsigned long V_99 , struct V_3 * V_4 ,
struct V_91 * V_98 , int V_100 )
{
struct V_109 * V_34 = & V_16 -> V_33 . V_34 ;
struct V_103 * V_104 ;
struct V_150 * V_151 = V_34 -> V_151 ;
struct V_152 * V_153 ;
void * V_107 ;
int V_69 , V_108 ;
int V_154 ;
if ( V_151 && ! F_125 ( V_151 , V_4 ) )
return;
V_108 = F_84 ( F_11 ( V_16 ) ) ;
V_69 = V_108 + V_16 -> V_33 . V_69 + V_100 ;
V_69 = F_126 ( V_69 + sizeof( V_155 ) , sizeof( V_156 ) ) - sizeof( V_155 ) ;
if ( F_127 ( V_69 > V_157 , L_28 ) )
return;
F_128 () ;
V_153 = F_129 ( V_34 -> V_22 ) ;
if ( F_130 ( V_153 ) )
goto V_124;
V_104 = F_131 ( V_69 , NULL , & V_154 ) ;
if ( ! V_104 )
goto V_124;
if ( F_11 ( V_16 ) ) {
V_104 -> V_14 [ 0 ] = V_99 ;
V_104 -> V_14 [ 1 ] = F_87 ( V_4 ) ;
V_107 = F_88 ( V_104 , true ) ;
} else {
V_104 -> V_14 [ 0 ] = F_87 ( V_4 ) ;
V_107 = F_88 ( V_104 , false ) ;
}
memcpy ( V_107 , V_98 -> V_53 , V_16 -> V_33 . V_69 + V_100 ) ;
if ( V_69 - V_108 > V_16 -> V_33 . V_69 + V_100 ) {
int V_158 = V_16 -> V_33 . V_69 + V_100 ;
memset ( V_107 + V_158 , 0 , V_69 - V_108 - V_158 ) ;
}
F_132 ( V_104 , V_69 , V_154 , V_34 -> V_27 . type , 1 , V_4 ,
V_153 , NULL ) ;
V_124:
F_133 () ;
}
static int F_134 ( struct V_23 * V_16 , struct V_3 * V_4 ,
struct V_91 * V_98 , int V_100 )
{
if ( ! F_121 ( & V_16 -> V_24 , 0 , V_12 -> V_136 ) )
return V_159 ;
if ( ! F_11 ( V_16 ) )
F_124 ( V_16 , 0 , V_4 , V_98 , V_100 ) ;
return 0 ;
}
static void F_135 ( struct V_23 * V_16 , unsigned long V_99 ,
struct V_3 * V_4 ,
struct V_91 * V_98 , int V_100 )
{
F_124 ( V_16 , V_99 , V_4 , V_98 , V_100 ) ;
}
static int
F_136 ( struct V_109 * V_27 , enum V_160 type ,
void * V_107 )
{
struct V_23 * V_16 = V_27 -> V_107 ;
struct V_101 * V_78 = V_107 ;
switch ( type ) {
case V_161 :
return F_100 ( V_16 , V_78 , NULL ) ;
case V_162 :
F_105 ( V_16 , V_78 ) ;
return 0 ;
#ifdef F_137
case V_163 :
return F_100 ( V_16 , NULL , F_121 ) ;
case V_164 :
F_105 ( V_16 , NULL ) ;
return 0 ;
case V_165 :
return F_119 ( V_16 , V_107 ) ;
case V_166 :
return F_115 ( V_16 , V_107 ) ;
#endif
default:
return 0 ;
}
return 0 ;
}
static int V_40 ( struct V_146 * V_167 , struct V_3 * V_4 )
{
struct V_23 * V_16 ;
struct V_10 V_11 ;
struct V_91 * V_98 ;
int V_100 , V_108 ;
int V_5 = 0 ;
V_16 = F_96 ( V_167 , struct V_23 , V_24 ) ;
V_16 -> V_87 ++ ;
V_11 . V_16 = V_16 ;
V_11 . V_15 = F_87 ( V_4 ) ;
V_12 -> V_13 -> V_14 = ( unsigned long ) & V_11 ;
if ( F_82 ( ! V_91 ) )
return 0 ;
V_100 = F_138 ( & V_16 -> V_33 , V_4 ) ;
V_108 = F_84 ( F_11 ( V_16 ) ) ;
V_98 = F_77 () ;
F_139 ( V_108 , & V_16 -> V_33 , V_4 , V_98 -> V_53 , V_100 ) ;
if ( V_16 -> V_33 . V_117 & V_128 )
V_5 |= F_90 ( V_16 , V_4 , V_98 , V_100 ) ;
#ifdef F_137
if ( V_16 -> V_33 . V_117 & V_126 )
V_5 |= F_134 ( V_16 , V_4 , V_98 , V_100 ) ;
#endif
F_79 ( V_98 ) ;
return V_5 ;
}
static int V_41 ( struct V_146 * V_167 ,
unsigned long V_99 , struct V_3 * V_4 )
{
struct V_23 * V_16 ;
struct V_10 V_11 ;
struct V_91 * V_98 ;
int V_100 , V_108 ;
V_16 = F_96 ( V_167 , struct V_23 , V_24 ) ;
V_11 . V_16 = V_16 ;
V_11 . V_15 = V_99 ;
V_12 -> V_13 -> V_14 = ( unsigned long ) & V_11 ;
if ( F_82 ( ! V_91 ) )
return 0 ;
V_100 = F_138 ( & V_16 -> V_33 , V_4 ) ;
V_108 = F_84 ( F_11 ( V_16 ) ) ;
V_98 = F_77 () ;
F_139 ( V_108 , & V_16 -> V_33 , V_4 , V_98 -> V_53 , V_100 ) ;
if ( V_16 -> V_33 . V_117 & V_128 )
F_94 ( V_16 , V_99 , V_4 , V_98 , V_100 ) ;
#ifdef F_137
if ( V_16 -> V_33 . V_117 & V_126 )
F_135 ( V_16 , V_99 , V_4 , V_98 , V_100 ) ;
#endif
F_79 ( V_98 ) ;
return 0 ;
}
static int F_30 ( struct V_23 * V_16 )
{
struct V_109 * V_34 = & V_16 -> V_33 . V_34 ;
int V_5 ;
F_8 ( & V_34 -> V_35 -> V_168 ) ;
V_34 -> V_27 . V_169 = & V_170 ;
V_34 -> V_35 -> V_171 = F_110 ;
if ( F_140 ( & V_16 -> V_33 , F_11 ( V_16 ) ) < 0 )
return - V_32 ;
V_5 = F_141 ( & V_34 -> V_27 ) ;
if ( ! V_5 ) {
F_18 ( V_34 -> V_172 ) ;
return - V_173 ;
}
V_34 -> V_117 = V_174 ;
V_34 -> V_35 -> V_175 = F_136 ;
V_34 -> V_107 = V_16 ;
V_5 = F_142 ( V_34 ) ;
if ( V_5 ) {
F_35 ( L_29 ,
F_24 ( V_34 ) ) ;
F_18 ( V_34 -> V_172 ) ;
F_143 ( & V_34 -> V_27 ) ;
}
return V_5 ;
}
static int F_26 ( struct V_23 * V_16 )
{
int V_5 ;
V_5 = F_144 ( & V_16 -> V_33 . V_34 ) ;
if ( V_5 )
return V_5 ;
F_18 ( V_16 -> V_33 . V_34 . V_172 ) ;
V_16 -> V_33 . V_34 . V_172 = NULL ;
return 0 ;
}
static T_6 int F_145 ( void )
{
struct V_62 * V_176 ;
V_176 = F_146 () ;
if ( F_43 ( V_176 ) )
return 0 ;
F_147 ( L_30 , 0644 , V_176 ,
NULL , & V_177 ) ;
F_147 ( L_31 , 0444 , V_176 ,
NULL , & V_178 ) ;
return 0 ;
}
