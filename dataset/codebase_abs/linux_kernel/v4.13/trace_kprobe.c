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
static T_1 unsigned long F_8 ( struct V_1 * V_2 )
{
unsigned long V_12 = 0 ;
int V_13 ;
F_9 (cpu)
V_12 += * F_10 ( V_2 -> V_12 , V_13 ) ;
return V_12 ;
}
unsigned long F_11 ( struct V_14 * V_15 )
{
V_15 -> V_16 = ( unsigned long ) F_12 ( V_15 -> V_5 ) ;
if ( V_15 -> V_16 )
V_15 -> V_16 += V_15 -> V_7 ;
return V_15 -> V_16 ;
}
void F_13 ( struct V_14 * V_15 )
{
F_14 ( V_15 -> V_5 ) ;
F_14 ( V_15 ) ;
}
struct V_14 * F_15 ( const char * V_17 , long V_7 )
{
struct V_14 * V_15 ;
if ( ! V_17 || strlen ( V_17 ) == 0 )
return NULL ;
V_15 = F_16 ( sizeof( struct V_14 ) , V_18 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_5 = F_17 ( V_17 , V_18 ) ;
if ( ! V_15 -> V_5 ) {
F_14 ( V_15 ) ;
return NULL ;
}
V_15 -> V_7 = V_7 ;
F_11 ( V_15 ) ;
return V_15 ;
}
static struct V_1 * F_18 ( const char * V_19 ,
const char * V_20 ,
void * V_16 ,
const char * V_5 ,
unsigned long V_21 ,
int V_22 ,
int V_23 , bool V_24 )
{
struct V_1 * V_2 ;
int V_25 = - V_26 ;
V_2 = F_16 ( F_19 ( V_23 ) , V_18 ) ;
if ( ! V_2 )
return F_20 ( V_25 ) ;
V_2 -> V_12 = F_21 (unsigned long) ;
if ( ! V_2 -> V_12 )
goto error;
if ( V_5 ) {
V_2 -> V_5 = F_17 ( V_5 , V_18 ) ;
if ( ! V_2 -> V_5 )
goto error;
V_2 -> V_3 . V_6 . V_27 = V_2 -> V_5 ;
V_2 -> V_3 . V_6 . V_7 = V_21 ;
} else
V_2 -> V_3 . V_6 . V_16 = V_16 ;
if ( V_24 )
V_2 -> V_3 . V_4 = V_28 ;
else
V_2 -> V_3 . V_6 . V_29 = V_30 ;
V_2 -> V_3 . V_22 = V_22 ;
if ( ! V_20 || ! F_22 ( V_20 ) ) {
V_25 = - V_31 ;
goto error;
}
V_2 -> V_32 . V_33 . V_34 = & V_2 -> V_32 . V_34 ;
V_2 -> V_32 . V_33 . V_11 = F_17 ( V_20 , V_18 ) ;
if ( ! V_2 -> V_32 . V_33 . V_11 )
goto error;
if ( ! V_19 || ! F_22 ( V_19 ) ) {
V_25 = - V_31 ;
goto error;
}
V_2 -> V_32 . V_34 . system = F_17 ( V_19 , V_18 ) ;
if ( ! V_2 -> V_32 . V_34 . system )
goto error;
F_23 ( & V_2 -> V_35 ) ;
F_23 ( & V_2 -> V_32 . V_36 ) ;
return V_2 ;
error:
F_14 ( V_2 -> V_32 . V_33 . V_11 ) ;
F_14 ( V_2 -> V_5 ) ;
F_24 ( V_2 -> V_12 ) ;
F_14 ( V_2 ) ;
return F_20 ( V_25 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_32 . V_38 ; V_37 ++ )
F_26 ( & V_2 -> V_32 . args [ V_37 ] ) ;
F_14 ( V_2 -> V_32 . V_33 . V_34 -> system ) ;
F_14 ( V_2 -> V_32 . V_33 . V_11 ) ;
F_14 ( V_2 -> V_5 ) ;
F_24 ( V_2 -> V_12 ) ;
F_14 ( V_2 ) ;
}
static struct V_1 * F_27 ( const char * V_20 ,
const char * V_19 )
{
struct V_1 * V_2 ;
F_28 (tk, &probe_list, list)
if ( strcmp ( F_29 ( & V_2 -> V_32 . V_33 ) , V_20 ) == 0 &&
strcmp ( V_2 -> V_32 . V_33 . V_34 -> system , V_19 ) == 0 )
return V_2 ;
return NULL ;
}
static int
F_30 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
int V_25 = 0 ;
if ( V_40 ) {
struct V_41 * V_42 ;
V_42 = F_31 ( sizeof( * V_42 ) , V_18 ) ;
if ( ! V_42 ) {
V_25 = - V_26 ;
goto V_43;
}
V_42 -> V_40 = V_40 ;
F_32 ( & V_42 -> V_35 , & V_2 -> V_32 . V_36 ) ;
V_2 -> V_32 . V_44 |= V_45 ;
} else
V_2 -> V_32 . V_44 |= V_46 ;
if ( F_33 ( & V_2 -> V_32 ) && ! F_4 ( V_2 ) ) {
if ( F_1 ( V_2 ) )
V_25 = F_34 ( & V_2 -> V_3 ) ;
else
V_25 = F_35 ( & V_2 -> V_3 . V_6 ) ;
}
V_43:
return V_25 ;
}
static int
F_36 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
struct V_41 * V_42 = NULL ;
int V_47 = 0 ;
int V_25 = 0 ;
if ( V_40 ) {
V_42 = F_37 ( & V_2 -> V_32 , V_40 ) ;
if ( ! V_42 ) {
V_25 = - V_31 ;
goto V_43;
}
F_38 ( & V_42 -> V_35 ) ;
V_47 = 1 ;
if ( ! F_39 ( & V_2 -> V_32 . V_36 ) )
goto V_43;
V_2 -> V_32 . V_44 &= ~ V_45 ;
} else
V_2 -> V_32 . V_44 &= ~ V_46 ;
if ( ! F_40 ( & V_2 -> V_32 ) && F_33 ( & V_2 -> V_32 ) ) {
if ( F_1 ( V_2 ) )
F_41 ( & V_2 -> V_3 ) ;
else
F_42 ( & V_2 -> V_3 . V_6 ) ;
V_47 = 1 ;
}
V_43:
if ( V_47 ) {
F_43 () ;
F_14 ( V_42 ) ;
}
return V_25 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_37 , V_25 ;
if ( F_33 ( & V_2 -> V_32 ) )
return - V_31 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_32 . V_38 ; V_37 ++ )
F_45 ( & V_2 -> V_32 . args [ V_37 ] ) ;
if ( F_40 ( & V_2 -> V_32 ) )
V_2 -> V_3 . V_6 . V_44 &= ~ V_48 ;
else
V_2 -> V_3 . V_6 . V_44 |= V_48 ;
if ( F_1 ( V_2 ) )
V_25 = F_46 ( & V_2 -> V_3 ) ;
else
V_25 = F_47 ( & V_2 -> V_3 . V_6 ) ;
if ( V_25 == 0 )
V_2 -> V_32 . V_44 |= V_49 ;
else {
F_48 ( L_2 ,
F_2 ( V_2 ) , F_3 ( V_2 ) , V_25 ) ;
if ( V_25 == - V_50 && F_7 ( V_2 ) ) {
F_48 ( L_3 ) ;
V_25 = 0 ;
} else if ( V_25 == - V_51 ) {
F_48 ( L_4 ,
V_2 -> V_3 . V_6 . V_16 ) ;
V_25 = - V_31 ;
}
}
return V_25 ;
}
static void F_49 ( struct V_1 * V_2 )
{
if ( F_33 ( & V_2 -> V_32 ) ) {
if ( F_1 ( V_2 ) )
F_50 ( & V_2 -> V_3 ) ;
else
F_51 ( & V_2 -> V_3 . V_6 ) ;
V_2 -> V_32 . V_44 &= ~ V_49 ;
if ( V_2 -> V_3 . V_6 . V_27 )
V_2 -> V_3 . V_6 . V_16 = NULL ;
}
}
static int F_52 ( struct V_1 * V_2 )
{
if ( F_40 ( & V_2 -> V_32 ) )
return - V_52 ;
if ( F_53 ( V_2 ) )
return - V_52 ;
F_49 ( V_2 ) ;
F_54 ( & V_2 -> V_35 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_1 * V_53 ;
int V_25 ;
F_56 ( & V_54 ) ;
V_53 = F_27 ( F_29 ( & V_2 -> V_32 . V_33 ) ,
V_2 -> V_32 . V_33 . V_34 -> system ) ;
if ( V_53 ) {
V_25 = F_52 ( V_53 ) ;
if ( V_25 < 0 )
goto V_55;
F_25 ( V_53 ) ;
}
V_25 = F_57 ( V_2 ) ;
if ( V_25 ) {
F_48 ( L_5 , V_25 ) ;
goto V_55;
}
V_25 = F_44 ( V_2 ) ;
if ( V_25 < 0 )
F_53 ( V_2 ) ;
else
F_58 ( & V_2 -> V_35 , & V_56 ) ;
V_55:
F_59 ( & V_54 ) ;
return V_25 ;
}
static int F_60 ( struct V_57 * V_58 ,
unsigned long V_59 , void * V_60 )
{
struct V_8 * V_9 = V_60 ;
struct V_1 * V_2 ;
int V_25 ;
if ( V_59 != V_61 )
return V_62 ;
F_56 ( & V_54 ) ;
F_28 (tk, &probe_list, list) {
if ( F_6 ( V_2 , V_9 ) ) {
F_49 ( V_2 ) ;
V_25 = F_44 ( V_2 ) ;
if ( V_25 )
F_48 ( L_6 ,
F_29 ( & V_2 -> V_32 . V_33 ) ,
V_9 -> V_11 , V_25 ) ;
}
}
F_59 ( & V_54 ) ;
return V_62 ;
}
static inline void F_61 ( char * V_11 )
{
while ( * V_11 ++ != '\0' )
if ( * V_11 == ':' || * V_11 == '.' )
* V_11 = '_' ;
}
static int F_62 ( int V_63 , char * * V_64 )
{
struct V_1 * V_2 ;
int V_37 , V_25 = 0 ;
bool V_24 = false , V_65 = false ;
char * V_5 = NULL , * V_20 = NULL , * V_19 = NULL ;
int V_22 = 0 ;
char * V_66 ;
unsigned long V_7 = 0 ;
void * V_16 = NULL ;
char V_67 [ V_68 ] ;
if ( V_64 [ 0 ] [ 0 ] == 'p' )
V_24 = false ;
else if ( V_64 [ 0 ] [ 0 ] == 'r' )
V_24 = true ;
else if ( V_64 [ 0 ] [ 0 ] == '-' )
V_65 = true ;
else {
F_63 ( L_7
L_8 ) ;
return - V_31 ;
}
V_20 = strchr ( & V_64 [ 0 ] [ 1 ] , ':' ) ;
if ( V_20 ) {
V_20 [ 0 ] = '\0' ;
V_20 ++ ;
}
if ( V_24 && isdigit ( V_64 [ 0 ] [ 1 ] ) ) {
V_25 = F_64 ( & V_64 [ 0 ] [ 1 ] , 0 , & V_22 ) ;
if ( V_25 ) {
F_63 ( L_9 ) ;
return V_25 ;
}
if ( V_22 > V_69 ) {
F_63 ( L_10 ,
V_22 , V_69 ) ;
return - V_70 ;
}
}
if ( V_20 ) {
if ( strchr ( V_20 , '/' ) ) {
V_19 = V_20 ;
V_20 = strchr ( V_19 , '/' ) + 1 ;
V_20 [ - 1 ] = '\0' ;
if ( strlen ( V_19 ) == 0 ) {
F_63 ( L_11 ) ;
return - V_31 ;
}
}
if ( strlen ( V_20 ) == 0 ) {
F_63 ( L_12 ) ;
return - V_31 ;
}
}
if ( ! V_19 )
V_19 = V_71 ;
if ( V_65 ) {
if ( ! V_20 ) {
F_63 ( L_13 ) ;
return - V_31 ;
}
F_56 ( & V_54 ) ;
V_2 = F_27 ( V_20 , V_19 ) ;
if ( ! V_2 ) {
F_59 ( & V_54 ) ;
F_63 ( L_14 , V_19 , V_20 ) ;
return - V_50 ;
}
V_25 = F_52 ( V_2 ) ;
if ( V_25 == 0 )
F_25 ( V_2 ) ;
F_59 ( & V_54 ) ;
return V_25 ;
}
if ( V_63 < 2 ) {
F_63 ( L_15 ) ;
return - V_31 ;
}
if ( F_65 ( V_64 [ 1 ] , 0 , ( unsigned long * ) & V_16 ) ) {
V_5 = V_64 [ 1 ] ;
V_25 = F_66 ( V_5 , & V_7 ) ;
if ( V_25 ) {
F_63 ( L_16 ) ;
return V_25 ;
}
if ( V_7 && V_24 &&
! F_67 ( NULL , V_5 , V_7 ) ) {
F_63 ( L_17 ) ;
return - V_31 ;
}
}
V_63 -= 2 ; V_64 += 2 ;
if ( ! V_20 ) {
if ( V_5 )
snprintf ( V_67 , V_68 , L_18 ,
V_24 ? 'r' : 'p' , V_5 , V_7 ) ;
else
snprintf ( V_67 , V_68 , L_19 ,
V_24 ? 'r' : 'p' , V_16 ) ;
F_61 ( V_67 ) ;
V_20 = V_67 ;
}
V_2 = F_18 ( V_19 , V_20 , V_16 , V_5 , V_7 , V_22 ,
V_63 , V_24 ) ;
if ( F_68 ( V_2 ) ) {
F_63 ( L_20 ,
( int ) F_69 ( V_2 ) ) ;
return F_69 ( V_2 ) ;
}
V_25 = 0 ;
for ( V_37 = 0 ; V_37 < V_63 && V_37 < V_72 ; V_37 ++ ) {
struct V_73 * V_74 = & V_2 -> V_32 . args [ V_37 ] ;
V_2 -> V_32 . V_38 ++ ;
V_66 = strchr ( V_64 [ V_37 ] , '=' ) ;
if ( V_66 ) {
* V_66 ++ = '\0' ;
V_74 -> V_11 = F_17 ( V_64 [ V_37 ] , V_18 ) ;
} else {
V_66 = V_64 [ V_37 ] ;
snprintf ( V_67 , V_68 , L_21 , V_37 + 1 ) ;
V_74 -> V_11 = F_17 ( V_67 , V_18 ) ;
}
if ( ! V_74 -> V_11 ) {
F_63 ( L_22 , V_37 ) ;
V_25 = - V_26 ;
goto error;
}
if ( ! F_22 ( V_74 -> V_11 ) ) {
F_63 ( L_23 ,
V_37 , V_74 -> V_11 ) ;
V_25 = - V_31 ;
goto error;
}
if ( F_70 ( V_74 -> V_11 ,
V_2 -> V_32 . args , V_37 ) ) {
F_63 ( L_24
L_25 , V_37 , V_64 [ V_37 ] ) ;
V_25 = - V_31 ;
goto error;
}
V_25 = F_71 ( V_66 , & V_2 -> V_32 . V_75 , V_74 ,
V_24 , true ,
V_76 ) ;
if ( V_25 ) {
F_63 ( L_26 , V_37 , V_25 ) ;
goto error;
}
}
V_25 = F_55 ( V_2 ) ;
if ( V_25 )
goto error;
return 0 ;
error:
F_25 ( V_2 ) ;
return V_25 ;
}
static int F_72 ( void )
{
struct V_1 * V_2 ;
int V_25 = 0 ;
F_56 ( & V_54 ) ;
F_28 (tk, &probe_list, list)
if ( F_40 ( & V_2 -> V_32 ) ) {
V_25 = - V_52 ;
goto V_55;
}
while ( ! F_39 ( & V_56 ) ) {
V_2 = F_73 ( V_56 . V_77 , struct V_1 , V_35 ) ;
V_25 = F_52 ( V_2 ) ;
if ( V_25 )
goto V_55;
F_25 ( V_2 ) ;
}
V_55:
F_59 ( & V_54 ) ;
return V_25 ;
}
static void * F_74 ( struct V_78 * V_79 , T_2 * V_80 )
{
F_56 ( & V_54 ) ;
return F_75 ( & V_56 , * V_80 ) ;
}
static void * F_76 ( struct V_78 * V_79 , void * V_81 , T_2 * V_80 )
{
return F_77 ( V_81 , & V_56 , V_80 ) ;
}
static void F_78 ( struct V_78 * V_79 , void * V_81 )
{
F_59 ( & V_54 ) ;
}
static int F_79 ( struct V_78 * V_79 , void * V_81 )
{
struct V_1 * V_2 = V_81 ;
int V_37 ;
F_80 ( V_79 , F_1 ( V_2 ) ? 'r' : 'p' ) ;
F_81 ( V_79 , L_27 , V_2 -> V_32 . V_33 . V_34 -> system ,
F_29 ( & V_2 -> V_32 . V_33 ) ) ;
if ( ! V_2 -> V_5 )
F_81 ( V_79 , L_28 , V_2 -> V_3 . V_6 . V_16 ) ;
else if ( V_2 -> V_3 . V_6 . V_7 )
F_81 ( V_79 , L_29 , F_2 ( V_2 ) ,
V_2 -> V_3 . V_6 . V_7 ) ;
else
F_81 ( V_79 , L_30 , F_2 ( V_2 ) ) ;
for ( V_37 = 0 ; V_37 < V_2 -> V_32 . V_38 ; V_37 ++ )
F_81 ( V_79 , L_31 , V_2 -> V_32 . args [ V_37 ] . V_11 , V_2 -> V_32 . args [ V_37 ] . V_82 ) ;
F_80 ( V_79 , '\n' ) ;
return 0 ;
}
static int F_82 ( struct V_83 * V_83 , struct V_40 * V_40 )
{
int V_25 ;
if ( ( V_40 -> V_84 & V_85 ) && ( V_40 -> V_86 & V_87 ) ) {
V_25 = F_72 () ;
if ( V_25 < 0 )
return V_25 ;
}
return F_83 ( V_40 , & V_88 ) ;
}
static T_3 F_84 ( struct V_40 * V_40 , const char T_4 * V_89 ,
T_5 V_90 , T_2 * V_91 )
{
return F_85 ( V_40 , V_89 , V_90 , V_91 ,
F_62 ) ;
}
static int F_86 ( struct V_78 * V_79 , void * V_81 )
{
struct V_1 * V_2 = V_81 ;
F_81 ( V_79 , L_32 ,
F_29 ( & V_2 -> V_32 . V_33 ) ,
F_8 ( V_2 ) ,
V_2 -> V_3 . V_6 . V_92 ) ;
return 0 ;
}
static int F_87 ( struct V_83 * V_83 , struct V_40 * V_40 )
{
return F_83 ( V_40 , & V_93 ) ;
}
static T_1 void
F_88 ( struct V_1 * V_2 , struct V_94 * V_95 ,
struct V_39 * V_96 )
{
struct V_97 * V_98 ;
struct V_99 * V_20 ;
struct V_100 * V_89 ;
int V_75 , V_101 , V_102 ;
unsigned long V_103 ;
struct V_104 * V_33 = & V_2 -> V_32 . V_33 ;
F_89 ( V_33 != V_96 -> V_105 ) ;
if ( F_90 ( V_96 ) )
return;
F_91 ( V_103 ) ;
V_102 = F_92 () ;
V_101 = F_93 ( & V_2 -> V_32 , V_95 ) ;
V_75 = sizeof( * V_98 ) + V_2 -> V_32 . V_75 + V_101 ;
V_20 = F_94 ( & V_89 , V_96 ,
V_33 -> V_20 . type ,
V_75 , V_103 , V_102 ) ;
if ( ! V_20 )
return;
V_98 = F_95 ( V_20 ) ;
V_98 -> V_106 = ( unsigned long ) V_2 -> V_3 . V_6 . V_16 ;
F_96 ( sizeof( * V_98 ) , & V_2 -> V_32 , V_95 , ( V_107 * ) & V_98 [ 1 ] , V_101 ) ;
F_97 ( V_96 , V_89 , V_20 ,
V_98 , V_103 , V_102 , V_95 ) ;
}
static void
F_98 ( struct V_1 * V_2 , struct V_94 * V_95 )
{
struct V_41 * V_42 ;
F_99 (link, &tk->tp.files, list)
F_88 ( V_2 , V_95 , V_42 -> V_40 ) ;
}
static T_1 void
F_100 ( struct V_1 * V_2 , struct V_108 * V_109 ,
struct V_94 * V_95 ,
struct V_39 * V_96 )
{
struct V_110 * V_98 ;
struct V_99 * V_20 ;
struct V_100 * V_89 ;
int V_75 , V_102 , V_101 ;
unsigned long V_103 ;
struct V_104 * V_33 = & V_2 -> V_32 . V_33 ;
F_89 ( V_33 != V_96 -> V_105 ) ;
if ( F_90 ( V_96 ) )
return;
F_91 ( V_103 ) ;
V_102 = F_92 () ;
V_101 = F_93 ( & V_2 -> V_32 , V_95 ) ;
V_75 = sizeof( * V_98 ) + V_2 -> V_32 . V_75 + V_101 ;
V_20 = F_94 ( & V_89 , V_96 ,
V_33 -> V_20 . type ,
V_75 , V_103 , V_102 ) ;
if ( ! V_20 )
return;
V_98 = F_95 ( V_20 ) ;
V_98 -> V_111 = ( unsigned long ) V_2 -> V_3 . V_6 . V_16 ;
V_98 -> V_112 = ( unsigned long ) V_109 -> V_113 ;
F_96 ( sizeof( * V_98 ) , & V_2 -> V_32 , V_95 , ( V_107 * ) & V_98 [ 1 ] , V_101 ) ;
F_97 ( V_96 , V_89 , V_20 ,
V_98 , V_103 , V_102 , V_95 ) ;
}
static void
F_101 ( struct V_1 * V_2 , struct V_108 * V_109 ,
struct V_94 * V_95 )
{
struct V_41 * V_42 ;
F_99 (link, &tk->tp.files, list)
F_100 ( V_2 , V_109 , V_95 , V_42 -> V_40 ) ;
}
static enum V_114
F_102 ( struct V_115 * V_116 , int V_44 ,
struct V_117 * V_20 )
{
struct V_97 * V_118 ;
struct V_119 * V_120 = & V_116 -> V_121 ;
struct V_122 * V_32 ;
V_107 * V_60 ;
int V_37 ;
V_118 = (struct V_97 * ) V_116 -> V_123 ;
V_32 = F_103 ( V_20 , struct V_122 , V_33 . V_20 ) ;
F_104 ( V_120 , L_33 , F_29 ( & V_32 -> V_33 ) ) ;
if ( ! F_105 ( V_120 , V_118 -> V_106 , V_44 | V_124 ) )
goto V_43;
F_106 ( V_120 , ')' ) ;
V_60 = ( V_107 * ) & V_118 [ 1 ] ;
for ( V_37 = 0 ; V_37 < V_32 -> V_38 ; V_37 ++ )
if ( ! V_32 -> args [ V_37 ] . type -> V_125 ( V_120 , V_32 -> args [ V_37 ] . V_11 ,
V_60 + V_32 -> args [ V_37 ] . V_7 , V_118 ) )
goto V_43;
F_106 ( V_120 , '\n' ) ;
V_43:
return F_107 ( V_120 ) ;
}
static enum V_114
F_108 ( struct V_115 * V_116 , int V_44 ,
struct V_117 * V_20 )
{
struct V_110 * V_118 ;
struct V_119 * V_120 = & V_116 -> V_121 ;
struct V_122 * V_32 ;
V_107 * V_60 ;
int V_37 ;
V_118 = (struct V_110 * ) V_116 -> V_123 ;
V_32 = F_103 ( V_20 , struct V_122 , V_33 . V_20 ) ;
F_104 ( V_120 , L_33 , F_29 ( & V_32 -> V_33 ) ) ;
if ( ! F_105 ( V_120 , V_118 -> V_112 , V_44 | V_124 ) )
goto V_43;
F_109 ( V_120 , L_34 ) ;
if ( ! F_105 ( V_120 , V_118 -> V_111 , V_44 & ~ V_124 ) )
goto V_43;
F_106 ( V_120 , ')' ) ;
V_60 = ( V_107 * ) & V_118 [ 1 ] ;
for ( V_37 = 0 ; V_37 < V_32 -> V_38 ; V_37 ++ )
if ( ! V_32 -> args [ V_37 ] . type -> V_125 ( V_120 , V_32 -> args [ V_37 ] . V_11 ,
V_60 + V_32 -> args [ V_37 ] . V_7 , V_118 ) )
goto V_43;
F_106 ( V_120 , '\n' ) ;
V_43:
return F_107 ( V_120 ) ;
}
static int F_110 ( struct V_104 * V_105 )
{
int V_25 , V_37 ;
struct V_97 V_118 ;
struct V_1 * V_2 = (struct V_1 * ) V_105 -> V_60 ;
F_111 (unsigned long, ip, FIELD_STRING_IP, 0 ) ;
for ( V_37 = 0 ; V_37 < V_2 -> V_32 . V_38 ; V_37 ++ ) {
struct V_73 * V_74 = & V_2 -> V_32 . args [ V_37 ] ;
V_25 = F_112 ( V_105 , V_74 -> type -> V_126 ,
V_74 -> V_11 ,
sizeof( V_118 ) + V_74 -> V_7 ,
V_74 -> type -> V_75 ,
V_74 -> type -> V_127 ,
V_128 ) ;
if ( V_25 )
return V_25 ;
}
return 0 ;
}
static int F_113 ( struct V_104 * V_105 )
{
int V_25 , V_37 ;
struct V_110 V_118 ;
struct V_1 * V_2 = (struct V_1 * ) V_105 -> V_60 ;
F_111 (unsigned long, func, FIELD_STRING_FUNC, 0 ) ;
F_111 (unsigned long, ret_ip, FIELD_STRING_RETIP, 0 ) ;
for ( V_37 = 0 ; V_37 < V_2 -> V_32 . V_38 ; V_37 ++ ) {
struct V_73 * V_74 = & V_2 -> V_32 . args [ V_37 ] ;
V_25 = F_112 ( V_105 , V_74 -> type -> V_126 ,
V_74 -> V_11 ,
sizeof( V_118 ) + V_74 -> V_7 ,
V_74 -> type -> V_75 ,
V_74 -> type -> V_127 ,
V_128 ) ;
if ( V_25 )
return V_25 ;
}
return 0 ;
}
static void
F_114 ( struct V_1 * V_2 , struct V_94 * V_95 )
{
struct V_104 * V_33 = & V_2 -> V_32 . V_33 ;
struct V_129 * V_130 = V_33 -> V_130 ;
struct V_97 * V_98 ;
struct V_131 * V_132 ;
int V_75 , V_133 , V_101 ;
int V_134 ;
if ( V_130 && ! F_115 ( V_130 , V_95 ) )
return;
V_132 = F_116 ( V_33 -> V_135 ) ;
if ( F_117 ( V_132 ) )
return;
V_101 = F_93 ( & V_2 -> V_32 , V_95 ) ;
V_133 = sizeof( * V_98 ) + V_2 -> V_32 . V_75 + V_101 ;
V_75 = F_118 ( V_133 + sizeof( V_136 ) , sizeof( V_137 ) ) ;
V_75 -= sizeof( V_136 ) ;
V_98 = F_119 ( V_75 , NULL , & V_134 ) ;
if ( ! V_98 )
return;
V_98 -> V_106 = ( unsigned long ) V_2 -> V_3 . V_6 . V_16 ;
memset ( & V_98 [ 1 ] , 0 , V_101 ) ;
F_96 ( sizeof( * V_98 ) , & V_2 -> V_32 , V_95 , ( V_107 * ) & V_98 [ 1 ] , V_101 ) ;
F_120 ( V_98 , V_75 , V_134 , V_33 -> V_20 . type , 1 , V_95 ,
V_132 , NULL , NULL ) ;
}
static void
F_121 ( struct V_1 * V_2 , struct V_108 * V_109 ,
struct V_94 * V_95 )
{
struct V_104 * V_33 = & V_2 -> V_32 . V_33 ;
struct V_129 * V_130 = V_33 -> V_130 ;
struct V_110 * V_98 ;
struct V_131 * V_132 ;
int V_75 , V_133 , V_101 ;
int V_134 ;
if ( V_130 && ! F_115 ( V_130 , V_95 ) )
return;
V_132 = F_116 ( V_33 -> V_135 ) ;
if ( F_117 ( V_132 ) )
return;
V_101 = F_93 ( & V_2 -> V_32 , V_95 ) ;
V_133 = sizeof( * V_98 ) + V_2 -> V_32 . V_75 + V_101 ;
V_75 = F_118 ( V_133 + sizeof( V_136 ) , sizeof( V_137 ) ) ;
V_75 -= sizeof( V_136 ) ;
V_98 = F_119 ( V_75 , NULL , & V_134 ) ;
if ( ! V_98 )
return;
V_98 -> V_111 = ( unsigned long ) V_2 -> V_3 . V_6 . V_16 ;
V_98 -> V_112 = ( unsigned long ) V_109 -> V_113 ;
F_96 ( sizeof( * V_98 ) , & V_2 -> V_32 , V_95 , ( V_107 * ) & V_98 [ 1 ] , V_101 ) ;
F_120 ( V_98 , V_75 , V_134 , V_33 -> V_20 . type , 1 , V_95 ,
V_132 , NULL , NULL ) ;
}
static int F_122 ( struct V_104 * V_20 ,
enum V_138 type , void * V_60 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 -> V_60 ;
struct V_39 * V_40 = V_60 ;
switch ( type ) {
case V_139 :
return F_30 ( V_2 , V_40 ) ;
case V_140 :
return F_36 ( V_2 , V_40 ) ;
#ifdef F_123
case V_141 :
return F_30 ( V_2 , NULL ) ;
case V_142 :
return F_36 ( V_2 , NULL ) ;
case V_143 :
case V_144 :
case V_145 :
case V_146 :
return 0 ;
#endif
}
return 0 ;
}
static int V_30 ( struct V_147 * V_6 , struct V_94 * V_95 )
{
struct V_1 * V_2 = F_103 ( V_6 , struct V_1 , V_3 . V_6 ) ;
F_124 ( * V_2 -> V_12 ) ;
if ( V_2 -> V_32 . V_44 & V_45 )
F_98 ( V_2 , V_95 ) ;
#ifdef F_123
if ( V_2 -> V_32 . V_44 & V_46 )
F_114 ( V_2 , V_95 ) ;
#endif
return 0 ;
}
static int
V_28 ( struct V_108 * V_109 , struct V_94 * V_95 )
{
struct V_1 * V_2 = F_103 ( V_109 -> V_3 , struct V_1 , V_3 ) ;
F_124 ( * V_2 -> V_12 ) ;
if ( V_2 -> V_32 . V_44 & V_45 )
F_101 ( V_2 , V_109 , V_95 ) ;
#ifdef F_123
if ( V_2 -> V_32 . V_44 & V_46 )
F_121 ( V_2 , V_109 , V_95 ) ;
#endif
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_104 * V_33 = & V_2 -> V_32 . V_33 ;
int V_25 ;
F_23 ( & V_33 -> V_34 -> V_148 ) ;
if ( F_1 ( V_2 ) ) {
V_33 -> V_20 . V_149 = & V_150 ;
V_33 -> V_34 -> V_151 = F_113 ;
} else {
V_33 -> V_20 . V_149 = & V_152 ;
V_33 -> V_34 -> V_151 = F_110 ;
}
if ( F_125 ( & V_2 -> V_32 , F_1 ( V_2 ) ) < 0 )
return - V_26 ;
V_25 = F_126 ( & V_33 -> V_20 ) ;
if ( ! V_25 ) {
F_14 ( V_33 -> V_153 ) ;
return - V_154 ;
}
V_33 -> V_44 = V_155 ;
V_33 -> V_34 -> V_156 = F_122 ;
V_33 -> V_60 = V_2 ;
V_25 = F_127 ( V_33 ) ;
if ( V_25 ) {
F_63 ( L_35 ,
F_29 ( V_33 ) ) ;
F_14 ( V_33 -> V_153 ) ;
F_128 ( & V_33 -> V_20 ) ;
}
return V_25 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_25 ;
V_25 = F_129 ( & V_2 -> V_32 . V_33 ) ;
if ( ! V_25 )
F_14 ( V_2 -> V_32 . V_33 . V_153 ) ;
return V_25 ;
}
static T_6 int F_130 ( void )
{
struct V_157 * V_158 ;
struct V_157 * V_98 ;
if ( F_131 ( & V_159 ) )
return - V_31 ;
V_158 = F_132 () ;
if ( F_68 ( V_158 ) )
return 0 ;
V_98 = F_133 ( L_36 , 0644 , V_158 ,
NULL , & V_160 ) ;
if ( ! V_98 )
F_48 ( L_37 ) ;
V_98 = F_133 ( L_38 , 0444 , V_158 ,
NULL , & V_161 ) ;
if ( ! V_98 )
F_48 ( L_39 ) ;
return 0 ;
}
static T_7 T_6 T_8 int
F_134 ( int V_162 , int V_163 , int V_164 , int V_165 , int V_166 , int V_167 )
{
return V_162 + V_163 + V_164 + V_165 + V_166 + V_167 ;
}
T_6 int F_135 ( void )
{
int V_25 , V_168 = 0 ;
int (* F_136)( int , int , int , int , int , int );
struct V_1 * V_2 ;
struct V_39 * V_40 ;
if ( F_137 () )
return - V_154 ;
F_136 = F_134 ;
F_63 ( L_40 ) ;
V_25 = F_138 ( L_41
L_42 ,
F_62 ) ;
if ( F_139 ( V_25 ) ) {
F_48 ( L_43 ) ;
V_168 ++ ;
} else {
V_2 = F_27 ( L_44 , V_71 ) ;
if ( F_139 ( V_2 == NULL ) ) {
F_48 ( L_45 ) ;
V_168 ++ ;
} else {
V_40 = F_140 ( V_2 , F_141 () ) ;
if ( F_139 ( V_40 == NULL ) ) {
F_48 ( L_46 ) ;
V_168 ++ ;
} else
F_30 ( V_2 , V_40 ) ;
}
}
V_25 = F_138 ( L_47
L_48 , F_62 ) ;
if ( F_139 ( V_25 ) ) {
F_48 ( L_49 ) ;
V_168 ++ ;
} else {
V_2 = F_27 ( L_50 , V_71 ) ;
if ( F_139 ( V_2 == NULL ) ) {
F_48 ( L_51 ) ;
V_168 ++ ;
} else {
V_40 = F_140 ( V_2 , F_141 () ) ;
if ( F_139 ( V_40 == NULL ) ) {
F_48 ( L_46 ) ;
V_168 ++ ;
} else
F_30 ( V_2 , V_40 ) ;
}
}
if ( V_168 )
goto V_55;
V_25 = F_136 ( 1 , 2 , 3 , 4 , 5 , 6 ) ;
if ( V_25 != 21 )
V_168 ++ ;
V_2 = F_27 ( L_44 , V_71 ) ;
if ( F_139 ( V_2 == NULL ) ) {
F_48 ( L_52 ) ;
V_168 ++ ;
} else {
if ( F_8 ( V_2 ) != 1 ) {
F_48 ( L_53 ) ;
V_168 ++ ;
}
V_40 = F_140 ( V_2 , F_141 () ) ;
if ( F_139 ( V_40 == NULL ) ) {
F_48 ( L_46 ) ;
V_168 ++ ;
} else
F_36 ( V_2 , V_40 ) ;
}
V_2 = F_27 ( L_50 , V_71 ) ;
if ( F_139 ( V_2 == NULL ) ) {
F_48 ( L_54 ) ;
V_168 ++ ;
} else {
if ( F_8 ( V_2 ) != 1 ) {
F_48 ( L_55 ) ;
V_168 ++ ;
}
V_40 = F_140 ( V_2 , F_141 () ) ;
if ( F_139 ( V_40 == NULL ) ) {
F_48 ( L_46 ) ;
V_168 ++ ;
} else
F_36 ( V_2 , V_40 ) ;
}
V_25 = F_138 ( L_56 , F_62 ) ;
if ( F_139 ( V_25 ) ) {
F_48 ( L_57 ) ;
V_168 ++ ;
}
V_25 = F_138 ( L_58 , F_62 ) ;
if ( F_139 ( V_25 ) ) {
F_48 ( L_57 ) ;
V_168 ++ ;
}
V_55:
F_72 () ;
F_142 () ;
if ( V_168 )
F_143 ( L_59 ) ;
else
F_143 ( L_60 ) ;
return 0 ;
}
