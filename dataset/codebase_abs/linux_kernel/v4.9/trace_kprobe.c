static T_1 bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 != NULL ;
}
static T_1 const char * F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_5 ? V_2 -> V_5 : L_1 ;
}
static T_1 unsigned long F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_6 . V_7 ;
}
static T_1 bool F_4 ( struct V_1 * V_2 )
{
return ! ! ( F_5 ( & V_2 -> V_3 . V_6 ) ) ;
}
static T_1 bool F_6 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
int V_10 = strlen ( V_9 -> V_11 ) ;
const char * V_11 = F_2 ( V_2 ) ;
return strncmp ( V_9 -> V_11 , V_11 , V_10 ) == 0 && V_11 [ V_10 ] == ':' ;
}
static T_1 bool F_7 ( struct V_1 * V_2 )
{
return ! ! strchr ( F_2 ( V_2 ) , ':' ) ;
}
unsigned long F_8 ( struct V_12 * V_13 )
{
V_13 -> V_14 = ( unsigned long ) F_9 ( V_13 -> V_5 ) ;
if ( V_13 -> V_14 )
V_13 -> V_14 += V_13 -> V_7 ;
return V_13 -> V_14 ;
}
void F_10 ( struct V_12 * V_13 )
{
F_11 ( V_13 -> V_5 ) ;
F_11 ( V_13 ) ;
}
struct V_12 * F_12 ( const char * V_15 , long V_7 )
{
struct V_12 * V_13 ;
if ( ! V_15 || strlen ( V_15 ) == 0 )
return NULL ;
V_13 = F_13 ( sizeof( struct V_12 ) , V_16 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_5 = F_14 ( V_15 , V_16 ) ;
if ( ! V_13 -> V_5 ) {
F_11 ( V_13 ) ;
return NULL ;
}
V_13 -> V_7 = V_7 ;
F_8 ( V_13 ) ;
return V_13 ;
}
static struct V_1 * F_15 ( const char * V_17 ,
const char * V_18 ,
void * V_14 ,
const char * V_5 ,
unsigned long V_19 ,
int V_20 , bool V_21 )
{
struct V_1 * V_2 ;
int V_22 = - V_23 ;
V_2 = F_13 ( F_16 ( V_20 ) , V_16 ) ;
if ( ! V_2 )
return F_17 ( V_22 ) ;
V_2 -> V_24 = F_18 (unsigned long) ;
if ( ! V_2 -> V_24 )
goto error;
if ( V_5 ) {
V_2 -> V_5 = F_14 ( V_5 , V_16 ) ;
if ( ! V_2 -> V_5 )
goto error;
V_2 -> V_3 . V_6 . V_25 = V_2 -> V_5 ;
V_2 -> V_3 . V_6 . V_7 = V_19 ;
} else
V_2 -> V_3 . V_6 . V_14 = V_14 ;
if ( V_21 )
V_2 -> V_3 . V_4 = V_26 ;
else
V_2 -> V_3 . V_6 . V_27 = V_28 ;
if ( ! V_18 || ! F_19 ( V_18 ) ) {
V_22 = - V_29 ;
goto error;
}
V_2 -> V_30 . V_31 . V_32 = & V_2 -> V_30 . V_32 ;
V_2 -> V_30 . V_31 . V_11 = F_14 ( V_18 , V_16 ) ;
if ( ! V_2 -> V_30 . V_31 . V_11 )
goto error;
if ( ! V_17 || ! F_19 ( V_17 ) ) {
V_22 = - V_29 ;
goto error;
}
V_2 -> V_30 . V_32 . system = F_14 ( V_17 , V_16 ) ;
if ( ! V_2 -> V_30 . V_32 . system )
goto error;
F_20 ( & V_2 -> V_33 ) ;
F_20 ( & V_2 -> V_30 . V_34 ) ;
return V_2 ;
error:
F_11 ( V_2 -> V_30 . V_31 . V_11 ) ;
F_11 ( V_2 -> V_5 ) ;
F_21 ( V_2 -> V_24 ) ;
F_11 ( V_2 ) ;
return F_17 ( V_22 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_30 . V_36 ; V_35 ++ )
F_23 ( & V_2 -> V_30 . args [ V_35 ] ) ;
F_11 ( V_2 -> V_30 . V_31 . V_32 -> system ) ;
F_11 ( V_2 -> V_30 . V_31 . V_11 ) ;
F_11 ( V_2 -> V_5 ) ;
F_21 ( V_2 -> V_24 ) ;
F_11 ( V_2 ) ;
}
static struct V_1 * F_24 ( const char * V_18 ,
const char * V_17 )
{
struct V_1 * V_2 ;
F_25 (tk, &probe_list, list)
if ( strcmp ( F_26 ( & V_2 -> V_30 . V_31 ) , V_18 ) == 0 &&
strcmp ( V_2 -> V_30 . V_31 . V_32 -> system , V_17 ) == 0 )
return V_2 ;
return NULL ;
}
static int
F_27 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
int V_22 = 0 ;
if ( V_38 ) {
struct V_39 * V_40 ;
V_40 = F_28 ( sizeof( * V_40 ) , V_16 ) ;
if ( ! V_40 ) {
V_22 = - V_23 ;
goto V_41;
}
V_40 -> V_38 = V_38 ;
F_29 ( & V_40 -> V_33 , & V_2 -> V_30 . V_34 ) ;
V_2 -> V_30 . V_42 |= V_43 ;
} else
V_2 -> V_30 . V_42 |= V_44 ;
if ( F_30 ( & V_2 -> V_30 ) && ! F_4 ( V_2 ) ) {
if ( F_1 ( V_2 ) )
V_22 = F_31 ( & V_2 -> V_3 ) ;
else
V_22 = F_32 ( & V_2 -> V_3 . V_6 ) ;
}
V_41:
return V_22 ;
}
static int
F_33 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
struct V_39 * V_40 = NULL ;
int V_45 = 0 ;
int V_22 = 0 ;
if ( V_38 ) {
V_40 = F_34 ( & V_2 -> V_30 , V_38 ) ;
if ( ! V_40 ) {
V_22 = - V_29 ;
goto V_41;
}
F_35 ( & V_40 -> V_33 ) ;
V_45 = 1 ;
if ( ! F_36 ( & V_2 -> V_30 . V_34 ) )
goto V_41;
V_2 -> V_30 . V_42 &= ~ V_43 ;
} else
V_2 -> V_30 . V_42 &= ~ V_44 ;
if ( ! F_37 ( & V_2 -> V_30 ) && F_30 ( & V_2 -> V_30 ) ) {
if ( F_1 ( V_2 ) )
F_38 ( & V_2 -> V_3 ) ;
else
F_39 ( & V_2 -> V_3 . V_6 ) ;
V_45 = 1 ;
}
V_41:
if ( V_45 ) {
F_40 () ;
F_11 ( V_40 ) ;
}
return V_22 ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_35 , V_22 ;
if ( F_30 ( & V_2 -> V_30 ) )
return - V_29 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_30 . V_36 ; V_35 ++ )
F_42 ( & V_2 -> V_30 . args [ V_35 ] ) ;
if ( F_37 ( & V_2 -> V_30 ) )
V_2 -> V_3 . V_6 . V_42 &= ~ V_46 ;
else
V_2 -> V_3 . V_6 . V_42 |= V_46 ;
if ( F_1 ( V_2 ) )
V_22 = F_43 ( & V_2 -> V_3 ) ;
else
V_22 = F_44 ( & V_2 -> V_3 . V_6 ) ;
if ( V_22 == 0 )
V_2 -> V_30 . V_42 |= V_47 ;
else {
F_45 ( L_2 ,
F_2 ( V_2 ) , F_3 ( V_2 ) , V_22 ) ;
if ( V_22 == - V_48 && F_7 ( V_2 ) ) {
F_45 ( L_3 ) ;
V_22 = 0 ;
} else if ( V_22 == - V_49 ) {
F_45 ( L_4 ,
V_2 -> V_3 . V_6 . V_14 ) ;
V_22 = - V_29 ;
}
}
return V_22 ;
}
static void F_46 ( struct V_1 * V_2 )
{
if ( F_30 ( & V_2 -> V_30 ) ) {
if ( F_1 ( V_2 ) )
F_47 ( & V_2 -> V_3 ) ;
else
F_48 ( & V_2 -> V_3 . V_6 ) ;
V_2 -> V_30 . V_42 &= ~ V_47 ;
if ( V_2 -> V_3 . V_6 . V_25 )
V_2 -> V_3 . V_6 . V_14 = NULL ;
}
}
static int F_49 ( struct V_1 * V_2 )
{
if ( F_37 ( & V_2 -> V_30 ) )
return - V_50 ;
if ( F_50 ( V_2 ) )
return - V_50 ;
F_46 ( V_2 ) ;
F_51 ( & V_2 -> V_33 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_1 * V_51 ;
int V_22 ;
F_53 ( & V_52 ) ;
V_51 = F_24 ( F_26 ( & V_2 -> V_30 . V_31 ) ,
V_2 -> V_30 . V_31 . V_32 -> system ) ;
if ( V_51 ) {
V_22 = F_49 ( V_51 ) ;
if ( V_22 < 0 )
goto V_53;
F_22 ( V_51 ) ;
}
V_22 = F_54 ( V_2 ) ;
if ( V_22 ) {
F_45 ( L_5 , V_22 ) ;
goto V_53;
}
V_22 = F_41 ( V_2 ) ;
if ( V_22 < 0 )
F_50 ( V_2 ) ;
else
F_55 ( & V_2 -> V_33 , & V_54 ) ;
V_53:
F_56 ( & V_52 ) ;
return V_22 ;
}
static int F_57 ( struct V_55 * V_56 ,
unsigned long V_57 , void * V_58 )
{
struct V_8 * V_9 = V_58 ;
struct V_1 * V_2 ;
int V_22 ;
if ( V_57 != V_59 )
return V_60 ;
F_53 ( & V_52 ) ;
F_25 (tk, &probe_list, list) {
if ( F_6 ( V_2 , V_9 ) ) {
F_46 ( V_2 ) ;
V_22 = F_41 ( V_2 ) ;
if ( V_22 )
F_45 ( L_6 ,
F_26 ( & V_2 -> V_30 . V_31 ) ,
V_9 -> V_11 , V_22 ) ;
}
}
F_56 ( & V_52 ) ;
return V_60 ;
}
static int F_58 ( int V_61 , char * * V_62 )
{
struct V_1 * V_2 ;
int V_35 , V_22 = 0 ;
bool V_21 = false , V_63 = false ;
char * V_5 = NULL , * V_18 = NULL , * V_17 = NULL ;
char * V_64 ;
unsigned long V_7 = 0 ;
void * V_14 = NULL ;
char V_65 [ V_66 ] ;
if ( V_62 [ 0 ] [ 0 ] == 'p' )
V_21 = false ;
else if ( V_62 [ 0 ] [ 0 ] == 'r' )
V_21 = true ;
else if ( V_62 [ 0 ] [ 0 ] == '-' )
V_63 = true ;
else {
F_59 ( L_7
L_8 ) ;
return - V_29 ;
}
if ( V_62 [ 0 ] [ 1 ] == ':' ) {
V_18 = & V_62 [ 0 ] [ 2 ] ;
if ( strchr ( V_18 , '/' ) ) {
V_17 = V_18 ;
V_18 = strchr ( V_17 , '/' ) + 1 ;
V_18 [ - 1 ] = '\0' ;
if ( strlen ( V_17 ) == 0 ) {
F_59 ( L_9 ) ;
return - V_29 ;
}
}
if ( strlen ( V_18 ) == 0 ) {
F_59 ( L_10 ) ;
return - V_29 ;
}
}
if ( ! V_17 )
V_17 = V_67 ;
if ( V_63 ) {
if ( ! V_18 ) {
F_59 ( L_11 ) ;
return - V_29 ;
}
F_53 ( & V_52 ) ;
V_2 = F_24 ( V_18 , V_17 ) ;
if ( ! V_2 ) {
F_56 ( & V_52 ) ;
F_59 ( L_12 , V_17 , V_18 ) ;
return - V_48 ;
}
V_22 = F_49 ( V_2 ) ;
if ( V_22 == 0 )
F_22 ( V_2 ) ;
F_56 ( & V_52 ) ;
return V_22 ;
}
if ( V_61 < 2 ) {
F_59 ( L_13 ) ;
return - V_29 ;
}
if ( isdigit ( V_62 [ 1 ] [ 0 ] ) ) {
if ( V_21 ) {
F_59 ( L_14 ) ;
return - V_29 ;
}
V_22 = F_60 ( & V_62 [ 1 ] [ 0 ] , 0 , ( unsigned long * ) & V_14 ) ;
if ( V_22 ) {
F_59 ( L_15 ) ;
return V_22 ;
}
} else {
V_5 = V_62 [ 1 ] ;
V_22 = F_61 ( V_5 , & V_7 ) ;
if ( V_22 ) {
F_59 ( L_16 ) ;
return V_22 ;
}
if ( V_7 && V_21 ) {
F_59 ( L_17 ) ;
return - V_29 ;
}
}
V_61 -= 2 ; V_62 += 2 ;
if ( ! V_18 ) {
if ( V_5 )
snprintf ( V_65 , V_66 , L_18 ,
V_21 ? 'r' : 'p' , V_5 , V_7 ) ;
else
snprintf ( V_65 , V_66 , L_19 ,
V_21 ? 'r' : 'p' , V_14 ) ;
V_18 = V_65 ;
}
V_2 = F_15 ( V_17 , V_18 , V_14 , V_5 , V_7 , V_61 ,
V_21 ) ;
if ( F_62 ( V_2 ) ) {
F_59 ( L_20 ,
( int ) F_63 ( V_2 ) ) ;
return F_63 ( V_2 ) ;
}
V_22 = 0 ;
for ( V_35 = 0 ; V_35 < V_61 && V_35 < V_68 ; V_35 ++ ) {
struct V_69 * V_70 = & V_2 -> V_30 . args [ V_35 ] ;
V_2 -> V_30 . V_36 ++ ;
V_64 = strchr ( V_62 [ V_35 ] , '=' ) ;
if ( V_64 ) {
* V_64 ++ = '\0' ;
V_70 -> V_11 = F_14 ( V_62 [ V_35 ] , V_16 ) ;
} else {
V_64 = V_62 [ V_35 ] ;
snprintf ( V_65 , V_66 , L_21 , V_35 + 1 ) ;
V_70 -> V_11 = F_14 ( V_65 , V_16 ) ;
}
if ( ! V_70 -> V_11 ) {
F_59 ( L_22 , V_35 ) ;
V_22 = - V_23 ;
goto error;
}
if ( ! F_19 ( V_70 -> V_11 ) ) {
F_59 ( L_23 ,
V_35 , V_70 -> V_11 ) ;
V_22 = - V_29 ;
goto error;
}
if ( F_64 ( V_70 -> V_11 ,
V_2 -> V_30 . args , V_35 ) ) {
F_59 ( L_24
L_25 , V_35 , V_62 [ V_35 ] ) ;
V_22 = - V_29 ;
goto error;
}
V_22 = F_65 ( V_64 , & V_2 -> V_30 . V_71 , V_70 ,
V_21 , true ,
V_72 ) ;
if ( V_22 ) {
F_59 ( L_26 , V_35 , V_22 ) ;
goto error;
}
}
V_22 = F_52 ( V_2 ) ;
if ( V_22 )
goto error;
return 0 ;
error:
F_22 ( V_2 ) ;
return V_22 ;
}
static int F_66 ( void )
{
struct V_1 * V_2 ;
int V_22 = 0 ;
F_53 ( & V_52 ) ;
F_25 (tk, &probe_list, list)
if ( F_37 ( & V_2 -> V_30 ) ) {
V_22 = - V_50 ;
goto V_53;
}
while ( ! F_36 ( & V_54 ) ) {
V_2 = F_67 ( V_54 . V_73 , struct V_1 , V_33 ) ;
V_22 = F_49 ( V_2 ) ;
if ( V_22 )
goto V_53;
F_22 ( V_2 ) ;
}
V_53:
F_56 ( & V_52 ) ;
return V_22 ;
}
static void * F_68 ( struct V_74 * V_75 , T_2 * V_76 )
{
F_53 ( & V_52 ) ;
return F_69 ( & V_54 , * V_76 ) ;
}
static void * F_70 ( struct V_74 * V_75 , void * V_77 , T_2 * V_76 )
{
return F_71 ( V_77 , & V_54 , V_76 ) ;
}
static void F_72 ( struct V_74 * V_75 , void * V_77 )
{
F_56 ( & V_52 ) ;
}
static int F_73 ( struct V_74 * V_75 , void * V_77 )
{
struct V_1 * V_2 = V_77 ;
int V_35 ;
F_74 ( V_75 , F_1 ( V_2 ) ? 'r' : 'p' ) ;
F_75 ( V_75 , L_27 , V_2 -> V_30 . V_31 . V_32 -> system ,
F_26 ( & V_2 -> V_30 . V_31 ) ) ;
if ( ! V_2 -> V_5 )
F_75 ( V_75 , L_28 , V_2 -> V_3 . V_6 . V_14 ) ;
else if ( V_2 -> V_3 . V_6 . V_7 )
F_75 ( V_75 , L_29 , F_2 ( V_2 ) ,
V_2 -> V_3 . V_6 . V_7 ) ;
else
F_75 ( V_75 , L_30 , F_2 ( V_2 ) ) ;
for ( V_35 = 0 ; V_35 < V_2 -> V_30 . V_36 ; V_35 ++ )
F_75 ( V_75 , L_31 , V_2 -> V_30 . args [ V_35 ] . V_11 , V_2 -> V_30 . args [ V_35 ] . V_78 ) ;
F_74 ( V_75 , '\n' ) ;
return 0 ;
}
static int F_76 ( struct V_79 * V_79 , struct V_38 * V_38 )
{
int V_22 ;
if ( ( V_38 -> V_80 & V_81 ) && ( V_38 -> V_82 & V_83 ) ) {
V_22 = F_66 () ;
if ( V_22 < 0 )
return V_22 ;
}
return F_77 ( V_38 , & V_84 ) ;
}
static T_3 F_78 ( struct V_38 * V_38 , const char T_4 * V_85 ,
T_5 V_86 , T_2 * V_87 )
{
return F_79 ( V_38 , V_85 , V_86 , V_87 ,
F_58 ) ;
}
static int F_80 ( struct V_74 * V_75 , void * V_77 )
{
struct V_1 * V_2 = V_77 ;
unsigned long V_24 = 0 ;
int V_88 ;
F_81 (cpu)
V_24 += * F_82 ( V_2 -> V_24 , V_88 ) ;
F_75 ( V_75 , L_32 ,
F_26 ( & V_2 -> V_30 . V_31 ) , V_24 ,
V_2 -> V_3 . V_6 . V_89 ) ;
return 0 ;
}
static int F_83 ( struct V_79 * V_79 , struct V_38 * V_38 )
{
return F_77 ( V_38 , & V_90 ) ;
}
static T_1 void
F_84 ( struct V_1 * V_2 , struct V_91 * V_92 ,
struct V_37 * V_93 )
{
struct V_94 * V_95 ;
struct V_96 * V_18 ;
struct V_97 * V_85 ;
int V_71 , V_98 , V_99 ;
unsigned long V_100 ;
struct V_101 * V_31 = & V_2 -> V_30 . V_31 ;
F_85 ( V_31 != V_93 -> V_102 ) ;
if ( F_86 ( V_93 ) )
return;
F_87 ( V_100 ) ;
V_99 = F_88 () ;
V_98 = F_89 ( & V_2 -> V_30 , V_92 ) ;
V_71 = sizeof( * V_95 ) + V_2 -> V_30 . V_71 + V_98 ;
V_18 = F_90 ( & V_85 , V_93 ,
V_31 -> V_18 . type ,
V_71 , V_100 , V_99 ) ;
if ( ! V_18 )
return;
V_95 = F_91 ( V_18 ) ;
V_95 -> V_103 = ( unsigned long ) V_2 -> V_3 . V_6 . V_14 ;
F_92 ( sizeof( * V_95 ) , & V_2 -> V_30 , V_92 , ( V_104 * ) & V_95 [ 1 ] , V_98 ) ;
F_93 ( V_93 , V_85 , V_18 ,
V_95 , V_100 , V_99 , V_92 ) ;
}
static void
F_94 ( struct V_1 * V_2 , struct V_91 * V_92 )
{
struct V_39 * V_40 ;
F_95 (link, &tk->tp.files, list)
F_84 ( V_2 , V_92 , V_40 -> V_38 ) ;
}
static T_1 void
F_96 ( struct V_1 * V_2 , struct V_105 * V_106 ,
struct V_91 * V_92 ,
struct V_37 * V_93 )
{
struct V_107 * V_95 ;
struct V_96 * V_18 ;
struct V_97 * V_85 ;
int V_71 , V_99 , V_98 ;
unsigned long V_100 ;
struct V_101 * V_31 = & V_2 -> V_30 . V_31 ;
F_85 ( V_31 != V_93 -> V_102 ) ;
if ( F_86 ( V_93 ) )
return;
F_87 ( V_100 ) ;
V_99 = F_88 () ;
V_98 = F_89 ( & V_2 -> V_30 , V_92 ) ;
V_71 = sizeof( * V_95 ) + V_2 -> V_30 . V_71 + V_98 ;
V_18 = F_90 ( & V_85 , V_93 ,
V_31 -> V_18 . type ,
V_71 , V_100 , V_99 ) ;
if ( ! V_18 )
return;
V_95 = F_91 ( V_18 ) ;
V_95 -> V_108 = ( unsigned long ) V_2 -> V_3 . V_6 . V_14 ;
V_95 -> V_109 = ( unsigned long ) V_106 -> V_110 ;
F_92 ( sizeof( * V_95 ) , & V_2 -> V_30 , V_92 , ( V_104 * ) & V_95 [ 1 ] , V_98 ) ;
F_93 ( V_93 , V_85 , V_18 ,
V_95 , V_100 , V_99 , V_92 ) ;
}
static void
F_97 ( struct V_1 * V_2 , struct V_105 * V_106 ,
struct V_91 * V_92 )
{
struct V_39 * V_40 ;
F_95 (link, &tk->tp.files, list)
F_96 ( V_2 , V_106 , V_92 , V_40 -> V_38 ) ;
}
static enum V_111
F_98 ( struct V_112 * V_113 , int V_42 ,
struct V_114 * V_18 )
{
struct V_94 * V_115 ;
struct V_116 * V_117 = & V_113 -> V_118 ;
struct V_119 * V_30 ;
V_104 * V_58 ;
int V_35 ;
V_115 = (struct V_94 * ) V_113 -> V_120 ;
V_30 = F_99 ( V_18 , struct V_119 , V_31 . V_18 ) ;
F_100 ( V_117 , L_33 , F_26 ( & V_30 -> V_31 ) ) ;
if ( ! F_101 ( V_117 , V_115 -> V_103 , V_42 | V_121 ) )
goto V_41;
F_102 ( V_117 , ')' ) ;
V_58 = ( V_104 * ) & V_115 [ 1 ] ;
for ( V_35 = 0 ; V_35 < V_30 -> V_36 ; V_35 ++ )
if ( ! V_30 -> args [ V_35 ] . type -> V_122 ( V_117 , V_30 -> args [ V_35 ] . V_11 ,
V_58 + V_30 -> args [ V_35 ] . V_7 , V_115 ) )
goto V_41;
F_102 ( V_117 , '\n' ) ;
V_41:
return F_103 ( V_117 ) ;
}
static enum V_111
F_104 ( struct V_112 * V_113 , int V_42 ,
struct V_114 * V_18 )
{
struct V_107 * V_115 ;
struct V_116 * V_117 = & V_113 -> V_118 ;
struct V_119 * V_30 ;
V_104 * V_58 ;
int V_35 ;
V_115 = (struct V_107 * ) V_113 -> V_120 ;
V_30 = F_99 ( V_18 , struct V_119 , V_31 . V_18 ) ;
F_100 ( V_117 , L_33 , F_26 ( & V_30 -> V_31 ) ) ;
if ( ! F_101 ( V_117 , V_115 -> V_109 , V_42 | V_121 ) )
goto V_41;
F_105 ( V_117 , L_34 ) ;
if ( ! F_101 ( V_117 , V_115 -> V_108 , V_42 & ~ V_121 ) )
goto V_41;
F_102 ( V_117 , ')' ) ;
V_58 = ( V_104 * ) & V_115 [ 1 ] ;
for ( V_35 = 0 ; V_35 < V_30 -> V_36 ; V_35 ++ )
if ( ! V_30 -> args [ V_35 ] . type -> V_122 ( V_117 , V_30 -> args [ V_35 ] . V_11 ,
V_58 + V_30 -> args [ V_35 ] . V_7 , V_115 ) )
goto V_41;
F_102 ( V_117 , '\n' ) ;
V_41:
return F_103 ( V_117 ) ;
}
static int F_106 ( struct V_101 * V_102 )
{
int V_22 , V_35 ;
struct V_94 V_115 ;
struct V_1 * V_2 = (struct V_1 * ) V_102 -> V_58 ;
F_107 (unsigned long, ip, FIELD_STRING_IP, 0 ) ;
for ( V_35 = 0 ; V_35 < V_2 -> V_30 . V_36 ; V_35 ++ ) {
struct V_69 * V_70 = & V_2 -> V_30 . args [ V_35 ] ;
V_22 = F_108 ( V_102 , V_70 -> type -> V_123 ,
V_70 -> V_11 ,
sizeof( V_115 ) + V_70 -> V_7 ,
V_70 -> type -> V_71 ,
V_70 -> type -> V_124 ,
V_125 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static int F_109 ( struct V_101 * V_102 )
{
int V_22 , V_35 ;
struct V_107 V_115 ;
struct V_1 * V_2 = (struct V_1 * ) V_102 -> V_58 ;
F_107 (unsigned long, func, FIELD_STRING_FUNC, 0 ) ;
F_107 (unsigned long, ret_ip, FIELD_STRING_RETIP, 0 ) ;
for ( V_35 = 0 ; V_35 < V_2 -> V_30 . V_36 ; V_35 ++ ) {
struct V_69 * V_70 = & V_2 -> V_30 . args [ V_35 ] ;
V_22 = F_108 ( V_102 , V_70 -> type -> V_123 ,
V_70 -> V_11 ,
sizeof( V_115 ) + V_70 -> V_7 ,
V_70 -> type -> V_71 ,
V_70 -> type -> V_124 ,
V_125 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static void
F_110 ( struct V_1 * V_2 , struct V_91 * V_92 )
{
struct V_101 * V_31 = & V_2 -> V_30 . V_31 ;
struct V_126 * V_127 = V_31 -> V_127 ;
struct V_94 * V_95 ;
struct V_128 * V_129 ;
int V_71 , V_130 , V_98 ;
int V_131 ;
if ( V_127 && ! F_111 ( V_127 , V_92 ) )
return;
V_129 = F_112 ( V_31 -> V_132 ) ;
if ( F_113 ( V_129 ) )
return;
V_98 = F_89 ( & V_2 -> V_30 , V_92 ) ;
V_130 = sizeof( * V_95 ) + V_2 -> V_30 . V_71 + V_98 ;
V_71 = F_114 ( V_130 + sizeof( V_133 ) , sizeof( V_134 ) ) ;
V_71 -= sizeof( V_133 ) ;
V_95 = F_115 ( V_71 , NULL , & V_131 ) ;
if ( ! V_95 )
return;
V_95 -> V_103 = ( unsigned long ) V_2 -> V_3 . V_6 . V_14 ;
memset ( & V_95 [ 1 ] , 0 , V_98 ) ;
F_92 ( sizeof( * V_95 ) , & V_2 -> V_30 , V_92 , ( V_104 * ) & V_95 [ 1 ] , V_98 ) ;
F_116 ( V_95 , V_71 , V_131 , V_31 -> V_18 . type , 1 , V_92 ,
V_129 , NULL ) ;
}
static void
F_117 ( struct V_1 * V_2 , struct V_105 * V_106 ,
struct V_91 * V_92 )
{
struct V_101 * V_31 = & V_2 -> V_30 . V_31 ;
struct V_126 * V_127 = V_31 -> V_127 ;
struct V_107 * V_95 ;
struct V_128 * V_129 ;
int V_71 , V_130 , V_98 ;
int V_131 ;
if ( V_127 && ! F_111 ( V_127 , V_92 ) )
return;
V_129 = F_112 ( V_31 -> V_132 ) ;
if ( F_113 ( V_129 ) )
return;
V_98 = F_89 ( & V_2 -> V_30 , V_92 ) ;
V_130 = sizeof( * V_95 ) + V_2 -> V_30 . V_71 + V_98 ;
V_71 = F_114 ( V_130 + sizeof( V_133 ) , sizeof( V_134 ) ) ;
V_71 -= sizeof( V_133 ) ;
V_95 = F_115 ( V_71 , NULL , & V_131 ) ;
if ( ! V_95 )
return;
V_95 -> V_108 = ( unsigned long ) V_2 -> V_3 . V_6 . V_14 ;
V_95 -> V_109 = ( unsigned long ) V_106 -> V_110 ;
F_92 ( sizeof( * V_95 ) , & V_2 -> V_30 , V_92 , ( V_104 * ) & V_95 [ 1 ] , V_98 ) ;
F_116 ( V_95 , V_71 , V_131 , V_31 -> V_18 . type , 1 , V_92 ,
V_129 , NULL ) ;
}
static int F_118 ( struct V_101 * V_18 ,
enum V_135 type , void * V_58 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_58 ;
struct V_37 * V_38 = V_58 ;
switch ( type ) {
case V_136 :
return F_27 ( V_2 , V_38 ) ;
case V_137 :
return F_33 ( V_2 , V_38 ) ;
#ifdef F_119
case V_138 :
return F_27 ( V_2 , NULL ) ;
case V_139 :
return F_33 ( V_2 , NULL ) ;
case V_140 :
case V_141 :
case V_142 :
case V_143 :
return 0 ;
#endif
}
return 0 ;
}
static int V_28 ( struct V_144 * V_6 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_99 ( V_6 , struct V_1 , V_3 . V_6 ) ;
F_120 ( * V_2 -> V_24 ) ;
if ( V_2 -> V_30 . V_42 & V_43 )
F_94 ( V_2 , V_92 ) ;
#ifdef F_119
if ( V_2 -> V_30 . V_42 & V_44 )
F_110 ( V_2 , V_92 ) ;
#endif
return 0 ;
}
static int
V_26 ( struct V_105 * V_106 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_99 ( V_106 -> V_3 , struct V_1 , V_3 ) ;
F_120 ( * V_2 -> V_24 ) ;
if ( V_2 -> V_30 . V_42 & V_43 )
F_97 ( V_2 , V_106 , V_92 ) ;
#ifdef F_119
if ( V_2 -> V_30 . V_42 & V_44 )
F_117 ( V_2 , V_106 , V_92 ) ;
#endif
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_101 * V_31 = & V_2 -> V_30 . V_31 ;
int V_22 ;
F_20 ( & V_31 -> V_32 -> V_145 ) ;
if ( F_1 ( V_2 ) ) {
V_31 -> V_18 . V_146 = & V_147 ;
V_31 -> V_32 -> V_148 = F_109 ;
} else {
V_31 -> V_18 . V_146 = & V_149 ;
V_31 -> V_32 -> V_148 = F_106 ;
}
if ( F_121 ( & V_2 -> V_30 , F_1 ( V_2 ) ) < 0 )
return - V_23 ;
V_22 = F_122 ( & V_31 -> V_18 ) ;
if ( ! V_22 ) {
F_11 ( V_31 -> V_150 ) ;
return - V_151 ;
}
V_31 -> V_42 = V_152 ;
V_31 -> V_32 -> V_153 = F_118 ;
V_31 -> V_58 = V_2 ;
V_22 = F_123 ( V_31 ) ;
if ( V_22 ) {
F_59 ( L_35 ,
F_26 ( V_31 ) ) ;
F_11 ( V_31 -> V_150 ) ;
F_124 ( & V_31 -> V_18 ) ;
}
return V_22 ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_22 ;
V_22 = F_125 ( & V_2 -> V_30 . V_31 ) ;
if ( ! V_22 )
F_11 ( V_2 -> V_30 . V_31 . V_150 ) ;
return V_22 ;
}
static T_6 int F_126 ( void )
{
struct V_154 * V_155 ;
struct V_154 * V_95 ;
if ( F_127 ( & V_156 ) )
return - V_29 ;
V_155 = F_128 () ;
if ( F_62 ( V_155 ) )
return 0 ;
V_95 = F_129 ( L_36 , 0644 , V_155 ,
NULL , & V_157 ) ;
if ( ! V_95 )
F_45 ( L_37 ) ;
V_95 = F_129 ( L_38 , 0444 , V_155 ,
NULL , & V_158 ) ;
if ( ! V_95 )
F_45 ( L_39 ) ;
return 0 ;
}
static T_7 int F_130 ( int V_159 , int V_160 , int V_161 ,
int V_162 , int V_163 , int V_164 )
{
return V_159 + V_160 + V_161 + V_162 + V_163 + V_164 ;
}
static struct V_37 *
F_131 ( struct V_1 * V_2 , struct V_165 * V_166 )
{
struct V_37 * V_38 ;
F_25 (file, &tr->events, list)
if ( V_38 -> V_102 == & V_2 -> V_30 . V_31 )
return V_38 ;
return NULL ;
}
static T_6 int F_132 ( void )
{
int V_22 , V_167 = 0 ;
int (* F_133)( int , int , int , int , int , int );
struct V_1 * V_2 ;
struct V_37 * V_38 ;
if ( F_134 () )
return - V_151 ;
F_133 = F_130 ;
F_59 ( L_40 ) ;
V_22 = F_135 ( L_41
L_42 ,
F_58 ) ;
if ( F_136 ( V_22 ) ) {
F_45 ( L_43 ) ;
V_167 ++ ;
} else {
V_2 = F_24 ( L_44 , V_67 ) ;
if ( F_136 ( V_2 == NULL ) ) {
F_45 ( L_45 ) ;
V_167 ++ ;
} else {
V_38 = F_131 ( V_2 , F_137 () ) ;
if ( F_136 ( V_38 == NULL ) ) {
F_45 ( L_46 ) ;
V_167 ++ ;
} else
F_27 ( V_2 , V_38 ) ;
}
}
V_22 = F_135 ( L_47
L_48 , F_58 ) ;
if ( F_136 ( V_22 ) ) {
F_45 ( L_49 ) ;
V_167 ++ ;
} else {
V_2 = F_24 ( L_50 , V_67 ) ;
if ( F_136 ( V_2 == NULL ) ) {
F_45 ( L_51 ) ;
V_167 ++ ;
} else {
V_38 = F_131 ( V_2 , F_137 () ) ;
if ( F_136 ( V_38 == NULL ) ) {
F_45 ( L_46 ) ;
V_167 ++ ;
} else
F_27 ( V_2 , V_38 ) ;
}
}
if ( V_167 )
goto V_53;
V_22 = F_133 ( 1 , 2 , 3 , 4 , 5 , 6 ) ;
V_2 = F_24 ( L_44 , V_67 ) ;
if ( F_136 ( V_2 == NULL ) ) {
F_45 ( L_52 ) ;
V_167 ++ ;
} else {
V_38 = F_131 ( V_2 , F_137 () ) ;
if ( F_136 ( V_38 == NULL ) ) {
F_45 ( L_46 ) ;
V_167 ++ ;
} else
F_33 ( V_2 , V_38 ) ;
}
V_2 = F_24 ( L_50 , V_67 ) ;
if ( F_136 ( V_2 == NULL ) ) {
F_45 ( L_53 ) ;
V_167 ++ ;
} else {
V_38 = F_131 ( V_2 , F_137 () ) ;
if ( F_136 ( V_38 == NULL ) ) {
F_45 ( L_46 ) ;
V_167 ++ ;
} else
F_33 ( V_2 , V_38 ) ;
}
V_22 = F_135 ( L_54 , F_58 ) ;
if ( F_136 ( V_22 ) ) {
F_45 ( L_55 ) ;
V_167 ++ ;
}
V_22 = F_135 ( L_56 , F_58 ) ;
if ( F_136 ( V_22 ) ) {
F_45 ( L_55 ) ;
V_167 ++ ;
}
V_53:
F_66 () ;
if ( V_167 )
F_138 ( L_57 ) ;
else
F_138 ( L_58 ) ;
return 0 ;
}
