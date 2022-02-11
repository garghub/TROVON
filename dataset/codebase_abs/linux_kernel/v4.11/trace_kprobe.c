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
int V_22 , bool V_23 )
{
struct V_1 * V_2 ;
int V_24 = - V_25 ;
V_2 = F_16 ( F_19 ( V_22 ) , V_18 ) ;
if ( ! V_2 )
return F_20 ( V_24 ) ;
V_2 -> V_12 = F_21 (unsigned long) ;
if ( ! V_2 -> V_12 )
goto error;
if ( V_5 ) {
V_2 -> V_5 = F_17 ( V_5 , V_18 ) ;
if ( ! V_2 -> V_5 )
goto error;
V_2 -> V_3 . V_6 . V_26 = V_2 -> V_5 ;
V_2 -> V_3 . V_6 . V_7 = V_21 ;
} else
V_2 -> V_3 . V_6 . V_16 = V_16 ;
if ( V_23 )
V_2 -> V_3 . V_4 = V_27 ;
else
V_2 -> V_3 . V_6 . V_28 = V_29 ;
if ( ! V_20 || ! F_22 ( V_20 ) ) {
V_24 = - V_30 ;
goto error;
}
V_2 -> V_31 . V_32 . V_33 = & V_2 -> V_31 . V_33 ;
V_2 -> V_31 . V_32 . V_11 = F_17 ( V_20 , V_18 ) ;
if ( ! V_2 -> V_31 . V_32 . V_11 )
goto error;
if ( ! V_19 || ! F_22 ( V_19 ) ) {
V_24 = - V_30 ;
goto error;
}
V_2 -> V_31 . V_33 . system = F_17 ( V_19 , V_18 ) ;
if ( ! V_2 -> V_31 . V_33 . system )
goto error;
F_23 ( & V_2 -> V_34 ) ;
F_23 ( & V_2 -> V_31 . V_35 ) ;
return V_2 ;
error:
F_14 ( V_2 -> V_31 . V_32 . V_11 ) ;
F_14 ( V_2 -> V_5 ) ;
F_24 ( V_2 -> V_12 ) ;
F_14 ( V_2 ) ;
return F_20 ( V_24 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_31 . V_37 ; V_36 ++ )
F_26 ( & V_2 -> V_31 . args [ V_36 ] ) ;
F_14 ( V_2 -> V_31 . V_32 . V_33 -> system ) ;
F_14 ( V_2 -> V_31 . V_32 . V_11 ) ;
F_14 ( V_2 -> V_5 ) ;
F_24 ( V_2 -> V_12 ) ;
F_14 ( V_2 ) ;
}
static struct V_1 * F_27 ( const char * V_20 ,
const char * V_19 )
{
struct V_1 * V_2 ;
F_28 (tk, &probe_list, list)
if ( strcmp ( F_29 ( & V_2 -> V_31 . V_32 ) , V_20 ) == 0 &&
strcmp ( V_2 -> V_31 . V_32 . V_33 -> system , V_19 ) == 0 )
return V_2 ;
return NULL ;
}
static int
F_30 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
int V_24 = 0 ;
if ( V_39 ) {
struct V_40 * V_41 ;
V_41 = F_31 ( sizeof( * V_41 ) , V_18 ) ;
if ( ! V_41 ) {
V_24 = - V_25 ;
goto V_42;
}
V_41 -> V_39 = V_39 ;
F_32 ( & V_41 -> V_34 , & V_2 -> V_31 . V_35 ) ;
V_2 -> V_31 . V_43 |= V_44 ;
} else
V_2 -> V_31 . V_43 |= V_45 ;
if ( F_33 ( & V_2 -> V_31 ) && ! F_4 ( V_2 ) ) {
if ( F_1 ( V_2 ) )
V_24 = F_34 ( & V_2 -> V_3 ) ;
else
V_24 = F_35 ( & V_2 -> V_3 . V_6 ) ;
}
V_42:
return V_24 ;
}
static int
F_36 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
struct V_40 * V_41 = NULL ;
int V_46 = 0 ;
int V_24 = 0 ;
if ( V_39 ) {
V_41 = F_37 ( & V_2 -> V_31 , V_39 ) ;
if ( ! V_41 ) {
V_24 = - V_30 ;
goto V_42;
}
F_38 ( & V_41 -> V_34 ) ;
V_46 = 1 ;
if ( ! F_39 ( & V_2 -> V_31 . V_35 ) )
goto V_42;
V_2 -> V_31 . V_43 &= ~ V_44 ;
} else
V_2 -> V_31 . V_43 &= ~ V_45 ;
if ( ! F_40 ( & V_2 -> V_31 ) && F_33 ( & V_2 -> V_31 ) ) {
if ( F_1 ( V_2 ) )
F_41 ( & V_2 -> V_3 ) ;
else
F_42 ( & V_2 -> V_3 . V_6 ) ;
V_46 = 1 ;
}
V_42:
if ( V_46 ) {
F_43 () ;
F_14 ( V_41 ) ;
}
return V_24 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_36 , V_24 ;
if ( F_33 ( & V_2 -> V_31 ) )
return - V_30 ;
for ( V_36 = 0 ; V_36 < V_2 -> V_31 . V_37 ; V_36 ++ )
F_45 ( & V_2 -> V_31 . args [ V_36 ] ) ;
if ( F_40 ( & V_2 -> V_31 ) )
V_2 -> V_3 . V_6 . V_43 &= ~ V_47 ;
else
V_2 -> V_3 . V_6 . V_43 |= V_47 ;
if ( F_1 ( V_2 ) )
V_24 = F_46 ( & V_2 -> V_3 ) ;
else
V_24 = F_47 ( & V_2 -> V_3 . V_6 ) ;
if ( V_24 == 0 )
V_2 -> V_31 . V_43 |= V_48 ;
else {
F_48 ( L_2 ,
F_2 ( V_2 ) , F_3 ( V_2 ) , V_24 ) ;
if ( V_24 == - V_49 && F_7 ( V_2 ) ) {
F_48 ( L_3 ) ;
V_24 = 0 ;
} else if ( V_24 == - V_50 ) {
F_48 ( L_4 ,
V_2 -> V_3 . V_6 . V_16 ) ;
V_24 = - V_30 ;
}
}
return V_24 ;
}
static void F_49 ( struct V_1 * V_2 )
{
if ( F_33 ( & V_2 -> V_31 ) ) {
if ( F_1 ( V_2 ) )
F_50 ( & V_2 -> V_3 ) ;
else
F_51 ( & V_2 -> V_3 . V_6 ) ;
V_2 -> V_31 . V_43 &= ~ V_48 ;
if ( V_2 -> V_3 . V_6 . V_26 )
V_2 -> V_3 . V_6 . V_16 = NULL ;
}
}
static int F_52 ( struct V_1 * V_2 )
{
if ( F_40 ( & V_2 -> V_31 ) )
return - V_51 ;
if ( F_53 ( V_2 ) )
return - V_51 ;
F_49 ( V_2 ) ;
F_54 ( & V_2 -> V_34 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_1 * V_52 ;
int V_24 ;
F_56 ( & V_53 ) ;
V_52 = F_27 ( F_29 ( & V_2 -> V_31 . V_32 ) ,
V_2 -> V_31 . V_32 . V_33 -> system ) ;
if ( V_52 ) {
V_24 = F_52 ( V_52 ) ;
if ( V_24 < 0 )
goto V_54;
F_25 ( V_52 ) ;
}
V_24 = F_57 ( V_2 ) ;
if ( V_24 ) {
F_48 ( L_5 , V_24 ) ;
goto V_54;
}
V_24 = F_44 ( V_2 ) ;
if ( V_24 < 0 )
F_53 ( V_2 ) ;
else
F_58 ( & V_2 -> V_34 , & V_55 ) ;
V_54:
F_59 ( & V_53 ) ;
return V_24 ;
}
static int F_60 ( struct V_56 * V_57 ,
unsigned long V_58 , void * V_59 )
{
struct V_8 * V_9 = V_59 ;
struct V_1 * V_2 ;
int V_24 ;
if ( V_58 != V_60 )
return V_61 ;
F_56 ( & V_53 ) ;
F_28 (tk, &probe_list, list) {
if ( F_6 ( V_2 , V_9 ) ) {
F_49 ( V_2 ) ;
V_24 = F_44 ( V_2 ) ;
if ( V_24 )
F_48 ( L_6 ,
F_29 ( & V_2 -> V_31 . V_32 ) ,
V_9 -> V_11 , V_24 ) ;
}
}
F_59 ( & V_53 ) ;
return V_61 ;
}
static int F_61 ( int V_62 , char * * V_63 )
{
struct V_1 * V_2 ;
int V_36 , V_24 = 0 ;
bool V_23 = false , V_64 = false ;
char * V_5 = NULL , * V_20 = NULL , * V_19 = NULL ;
char * V_65 ;
unsigned long V_7 = 0 ;
void * V_16 = NULL ;
char V_66 [ V_67 ] ;
if ( V_63 [ 0 ] [ 0 ] == 'p' )
V_23 = false ;
else if ( V_63 [ 0 ] [ 0 ] == 'r' )
V_23 = true ;
else if ( V_63 [ 0 ] [ 0 ] == '-' )
V_64 = true ;
else {
F_62 ( L_7
L_8 ) ;
return - V_30 ;
}
if ( V_63 [ 0 ] [ 1 ] == ':' ) {
V_20 = & V_63 [ 0 ] [ 2 ] ;
if ( strchr ( V_20 , '/' ) ) {
V_19 = V_20 ;
V_20 = strchr ( V_19 , '/' ) + 1 ;
V_20 [ - 1 ] = '\0' ;
if ( strlen ( V_19 ) == 0 ) {
F_62 ( L_9 ) ;
return - V_30 ;
}
}
if ( strlen ( V_20 ) == 0 ) {
F_62 ( L_10 ) ;
return - V_30 ;
}
}
if ( ! V_19 )
V_19 = V_68 ;
if ( V_64 ) {
if ( ! V_20 ) {
F_62 ( L_11 ) ;
return - V_30 ;
}
F_56 ( & V_53 ) ;
V_2 = F_27 ( V_20 , V_19 ) ;
if ( ! V_2 ) {
F_59 ( & V_53 ) ;
F_62 ( L_12 , V_19 , V_20 ) ;
return - V_49 ;
}
V_24 = F_52 ( V_2 ) ;
if ( V_24 == 0 )
F_25 ( V_2 ) ;
F_59 ( & V_53 ) ;
return V_24 ;
}
if ( V_62 < 2 ) {
F_62 ( L_13 ) ;
return - V_30 ;
}
if ( isdigit ( V_63 [ 1 ] [ 0 ] ) ) {
if ( V_23 ) {
F_62 ( L_14 ) ;
return - V_30 ;
}
V_24 = F_63 ( & V_63 [ 1 ] [ 0 ] , 0 , ( unsigned long * ) & V_16 ) ;
if ( V_24 ) {
F_62 ( L_15 ) ;
return V_24 ;
}
} else {
V_5 = V_63 [ 1 ] ;
V_24 = F_64 ( V_5 , & V_7 ) ;
if ( V_24 ) {
F_62 ( L_16 ) ;
return V_24 ;
}
if ( V_7 && V_23 ) {
F_62 ( L_17 ) ;
return - V_30 ;
}
}
V_62 -= 2 ; V_63 += 2 ;
if ( ! V_20 ) {
if ( V_5 )
snprintf ( V_66 , V_67 , L_18 ,
V_23 ? 'r' : 'p' , V_5 , V_7 ) ;
else
snprintf ( V_66 , V_67 , L_19 ,
V_23 ? 'r' : 'p' , V_16 ) ;
V_20 = V_66 ;
}
V_2 = F_18 ( V_19 , V_20 , V_16 , V_5 , V_7 , V_62 ,
V_23 ) ;
if ( F_65 ( V_2 ) ) {
F_62 ( L_20 ,
( int ) F_66 ( V_2 ) ) ;
return F_66 ( V_2 ) ;
}
V_24 = 0 ;
for ( V_36 = 0 ; V_36 < V_62 && V_36 < V_69 ; V_36 ++ ) {
struct V_70 * V_71 = & V_2 -> V_31 . args [ V_36 ] ;
V_2 -> V_31 . V_37 ++ ;
V_65 = strchr ( V_63 [ V_36 ] , '=' ) ;
if ( V_65 ) {
* V_65 ++ = '\0' ;
V_71 -> V_11 = F_17 ( V_63 [ V_36 ] , V_18 ) ;
} else {
V_65 = V_63 [ V_36 ] ;
snprintf ( V_66 , V_67 , L_21 , V_36 + 1 ) ;
V_71 -> V_11 = F_17 ( V_66 , V_18 ) ;
}
if ( ! V_71 -> V_11 ) {
F_62 ( L_22 , V_36 ) ;
V_24 = - V_25 ;
goto error;
}
if ( ! F_22 ( V_71 -> V_11 ) ) {
F_62 ( L_23 ,
V_36 , V_71 -> V_11 ) ;
V_24 = - V_30 ;
goto error;
}
if ( F_67 ( V_71 -> V_11 ,
V_2 -> V_31 . args , V_36 ) ) {
F_62 ( L_24
L_25 , V_36 , V_63 [ V_36 ] ) ;
V_24 = - V_30 ;
goto error;
}
V_24 = F_68 ( V_65 , & V_2 -> V_31 . V_72 , V_71 ,
V_23 , true ,
V_73 ) ;
if ( V_24 ) {
F_62 ( L_26 , V_36 , V_24 ) ;
goto error;
}
}
V_24 = F_55 ( V_2 ) ;
if ( V_24 )
goto error;
return 0 ;
error:
F_25 ( V_2 ) ;
return V_24 ;
}
static int F_69 ( void )
{
struct V_1 * V_2 ;
int V_24 = 0 ;
F_56 ( & V_53 ) ;
F_28 (tk, &probe_list, list)
if ( F_40 ( & V_2 -> V_31 ) ) {
V_24 = - V_51 ;
goto V_54;
}
while ( ! F_39 ( & V_55 ) ) {
V_2 = F_70 ( V_55 . V_74 , struct V_1 , V_34 ) ;
V_24 = F_52 ( V_2 ) ;
if ( V_24 )
goto V_54;
F_25 ( V_2 ) ;
}
V_54:
F_59 ( & V_53 ) ;
return V_24 ;
}
static void * F_71 ( struct V_75 * V_76 , T_2 * V_77 )
{
F_56 ( & V_53 ) ;
return F_72 ( & V_55 , * V_77 ) ;
}
static void * F_73 ( struct V_75 * V_76 , void * V_78 , T_2 * V_77 )
{
return F_74 ( V_78 , & V_55 , V_77 ) ;
}
static void F_75 ( struct V_75 * V_76 , void * V_78 )
{
F_59 ( & V_53 ) ;
}
static int F_76 ( struct V_75 * V_76 , void * V_78 )
{
struct V_1 * V_2 = V_78 ;
int V_36 ;
F_77 ( V_76 , F_1 ( V_2 ) ? 'r' : 'p' ) ;
F_78 ( V_76 , L_27 , V_2 -> V_31 . V_32 . V_33 -> system ,
F_29 ( & V_2 -> V_31 . V_32 ) ) ;
if ( ! V_2 -> V_5 )
F_78 ( V_76 , L_28 , V_2 -> V_3 . V_6 . V_16 ) ;
else if ( V_2 -> V_3 . V_6 . V_7 )
F_78 ( V_76 , L_29 , F_2 ( V_2 ) ,
V_2 -> V_3 . V_6 . V_7 ) ;
else
F_78 ( V_76 , L_30 , F_2 ( V_2 ) ) ;
for ( V_36 = 0 ; V_36 < V_2 -> V_31 . V_37 ; V_36 ++ )
F_78 ( V_76 , L_31 , V_2 -> V_31 . args [ V_36 ] . V_11 , V_2 -> V_31 . args [ V_36 ] . V_79 ) ;
F_77 ( V_76 , '\n' ) ;
return 0 ;
}
static int F_79 ( struct V_80 * V_80 , struct V_39 * V_39 )
{
int V_24 ;
if ( ( V_39 -> V_81 & V_82 ) && ( V_39 -> V_83 & V_84 ) ) {
V_24 = F_69 () ;
if ( V_24 < 0 )
return V_24 ;
}
return F_80 ( V_39 , & V_85 ) ;
}
static T_3 F_81 ( struct V_39 * V_39 , const char T_4 * V_86 ,
T_5 V_87 , T_2 * V_88 )
{
return F_82 ( V_39 , V_86 , V_87 , V_88 ,
F_61 ) ;
}
static int F_83 ( struct V_75 * V_76 , void * V_78 )
{
struct V_1 * V_2 = V_78 ;
F_78 ( V_76 , L_32 ,
F_29 ( & V_2 -> V_31 . V_32 ) ,
F_8 ( V_2 ) ,
V_2 -> V_3 . V_6 . V_89 ) ;
return 0 ;
}
static int F_84 ( struct V_80 * V_80 , struct V_39 * V_39 )
{
return F_80 ( V_39 , & V_90 ) ;
}
static T_1 void
F_85 ( struct V_1 * V_2 , struct V_91 * V_92 ,
struct V_38 * V_93 )
{
struct V_94 * V_95 ;
struct V_96 * V_20 ;
struct V_97 * V_86 ;
int V_72 , V_98 , V_99 ;
unsigned long V_100 ;
struct V_101 * V_32 = & V_2 -> V_31 . V_32 ;
F_86 ( V_32 != V_93 -> V_102 ) ;
if ( F_87 ( V_93 ) )
return;
F_88 ( V_100 ) ;
V_99 = F_89 () ;
V_98 = F_90 ( & V_2 -> V_31 , V_92 ) ;
V_72 = sizeof( * V_95 ) + V_2 -> V_31 . V_72 + V_98 ;
V_20 = F_91 ( & V_86 , V_93 ,
V_32 -> V_20 . type ,
V_72 , V_100 , V_99 ) ;
if ( ! V_20 )
return;
V_95 = F_92 ( V_20 ) ;
V_95 -> V_103 = ( unsigned long ) V_2 -> V_3 . V_6 . V_16 ;
F_93 ( sizeof( * V_95 ) , & V_2 -> V_31 , V_92 , ( V_104 * ) & V_95 [ 1 ] , V_98 ) ;
F_94 ( V_93 , V_86 , V_20 ,
V_95 , V_100 , V_99 , V_92 ) ;
}
static void
F_95 ( struct V_1 * V_2 , struct V_91 * V_92 )
{
struct V_40 * V_41 ;
F_96 (link, &tk->tp.files, list)
F_85 ( V_2 , V_92 , V_41 -> V_39 ) ;
}
static T_1 void
F_97 ( struct V_1 * V_2 , struct V_105 * V_106 ,
struct V_91 * V_92 ,
struct V_38 * V_93 )
{
struct V_107 * V_95 ;
struct V_96 * V_20 ;
struct V_97 * V_86 ;
int V_72 , V_99 , V_98 ;
unsigned long V_100 ;
struct V_101 * V_32 = & V_2 -> V_31 . V_32 ;
F_86 ( V_32 != V_93 -> V_102 ) ;
if ( F_87 ( V_93 ) )
return;
F_88 ( V_100 ) ;
V_99 = F_89 () ;
V_98 = F_90 ( & V_2 -> V_31 , V_92 ) ;
V_72 = sizeof( * V_95 ) + V_2 -> V_31 . V_72 + V_98 ;
V_20 = F_91 ( & V_86 , V_93 ,
V_32 -> V_20 . type ,
V_72 , V_100 , V_99 ) ;
if ( ! V_20 )
return;
V_95 = F_92 ( V_20 ) ;
V_95 -> V_108 = ( unsigned long ) V_2 -> V_3 . V_6 . V_16 ;
V_95 -> V_109 = ( unsigned long ) V_106 -> V_110 ;
F_93 ( sizeof( * V_95 ) , & V_2 -> V_31 , V_92 , ( V_104 * ) & V_95 [ 1 ] , V_98 ) ;
F_94 ( V_93 , V_86 , V_20 ,
V_95 , V_100 , V_99 , V_92 ) ;
}
static void
F_98 ( struct V_1 * V_2 , struct V_105 * V_106 ,
struct V_91 * V_92 )
{
struct V_40 * V_41 ;
F_96 (link, &tk->tp.files, list)
F_97 ( V_2 , V_106 , V_92 , V_41 -> V_39 ) ;
}
static enum V_111
F_99 ( struct V_112 * V_113 , int V_43 ,
struct V_114 * V_20 )
{
struct V_94 * V_115 ;
struct V_116 * V_117 = & V_113 -> V_118 ;
struct V_119 * V_31 ;
V_104 * V_59 ;
int V_36 ;
V_115 = (struct V_94 * ) V_113 -> V_120 ;
V_31 = F_100 ( V_20 , struct V_119 , V_32 . V_20 ) ;
F_101 ( V_117 , L_33 , F_29 ( & V_31 -> V_32 ) ) ;
if ( ! F_102 ( V_117 , V_115 -> V_103 , V_43 | V_121 ) )
goto V_42;
F_103 ( V_117 , ')' ) ;
V_59 = ( V_104 * ) & V_115 [ 1 ] ;
for ( V_36 = 0 ; V_36 < V_31 -> V_37 ; V_36 ++ )
if ( ! V_31 -> args [ V_36 ] . type -> V_122 ( V_117 , V_31 -> args [ V_36 ] . V_11 ,
V_59 + V_31 -> args [ V_36 ] . V_7 , V_115 ) )
goto V_42;
F_103 ( V_117 , '\n' ) ;
V_42:
return F_104 ( V_117 ) ;
}
static enum V_111
F_105 ( struct V_112 * V_113 , int V_43 ,
struct V_114 * V_20 )
{
struct V_107 * V_115 ;
struct V_116 * V_117 = & V_113 -> V_118 ;
struct V_119 * V_31 ;
V_104 * V_59 ;
int V_36 ;
V_115 = (struct V_107 * ) V_113 -> V_120 ;
V_31 = F_100 ( V_20 , struct V_119 , V_32 . V_20 ) ;
F_101 ( V_117 , L_33 , F_29 ( & V_31 -> V_32 ) ) ;
if ( ! F_102 ( V_117 , V_115 -> V_109 , V_43 | V_121 ) )
goto V_42;
F_106 ( V_117 , L_34 ) ;
if ( ! F_102 ( V_117 , V_115 -> V_108 , V_43 & ~ V_121 ) )
goto V_42;
F_103 ( V_117 , ')' ) ;
V_59 = ( V_104 * ) & V_115 [ 1 ] ;
for ( V_36 = 0 ; V_36 < V_31 -> V_37 ; V_36 ++ )
if ( ! V_31 -> args [ V_36 ] . type -> V_122 ( V_117 , V_31 -> args [ V_36 ] . V_11 ,
V_59 + V_31 -> args [ V_36 ] . V_7 , V_115 ) )
goto V_42;
F_103 ( V_117 , '\n' ) ;
V_42:
return F_104 ( V_117 ) ;
}
static int F_107 ( struct V_101 * V_102 )
{
int V_24 , V_36 ;
struct V_94 V_115 ;
struct V_1 * V_2 = (struct V_1 * ) V_102 -> V_59 ;
F_108 (unsigned long, ip, FIELD_STRING_IP, 0 ) ;
for ( V_36 = 0 ; V_36 < V_2 -> V_31 . V_37 ; V_36 ++ ) {
struct V_70 * V_71 = & V_2 -> V_31 . args [ V_36 ] ;
V_24 = F_109 ( V_102 , V_71 -> type -> V_123 ,
V_71 -> V_11 ,
sizeof( V_115 ) + V_71 -> V_7 ,
V_71 -> type -> V_72 ,
V_71 -> type -> V_124 ,
V_125 ) ;
if ( V_24 )
return V_24 ;
}
return 0 ;
}
static int F_110 ( struct V_101 * V_102 )
{
int V_24 , V_36 ;
struct V_107 V_115 ;
struct V_1 * V_2 = (struct V_1 * ) V_102 -> V_59 ;
F_108 (unsigned long, func, FIELD_STRING_FUNC, 0 ) ;
F_108 (unsigned long, ret_ip, FIELD_STRING_RETIP, 0 ) ;
for ( V_36 = 0 ; V_36 < V_2 -> V_31 . V_37 ; V_36 ++ ) {
struct V_70 * V_71 = & V_2 -> V_31 . args [ V_36 ] ;
V_24 = F_109 ( V_102 , V_71 -> type -> V_123 ,
V_71 -> V_11 ,
sizeof( V_115 ) + V_71 -> V_7 ,
V_71 -> type -> V_72 ,
V_71 -> type -> V_124 ,
V_125 ) ;
if ( V_24 )
return V_24 ;
}
return 0 ;
}
static void
F_111 ( struct V_1 * V_2 , struct V_91 * V_92 )
{
struct V_101 * V_32 = & V_2 -> V_31 . V_32 ;
struct V_126 * V_127 = V_32 -> V_127 ;
struct V_94 * V_95 ;
struct V_128 * V_129 ;
int V_72 , V_130 , V_98 ;
int V_131 ;
if ( V_127 && ! F_112 ( V_127 , V_92 ) )
return;
V_129 = F_113 ( V_32 -> V_132 ) ;
if ( F_114 ( V_129 ) )
return;
V_98 = F_90 ( & V_2 -> V_31 , V_92 ) ;
V_130 = sizeof( * V_95 ) + V_2 -> V_31 . V_72 + V_98 ;
V_72 = F_115 ( V_130 + sizeof( V_133 ) , sizeof( V_134 ) ) ;
V_72 -= sizeof( V_133 ) ;
V_95 = F_116 ( V_72 , NULL , & V_131 ) ;
if ( ! V_95 )
return;
V_95 -> V_103 = ( unsigned long ) V_2 -> V_3 . V_6 . V_16 ;
memset ( & V_95 [ 1 ] , 0 , V_98 ) ;
F_93 ( sizeof( * V_95 ) , & V_2 -> V_31 , V_92 , ( V_104 * ) & V_95 [ 1 ] , V_98 ) ;
F_117 ( V_95 , V_72 , V_131 , V_32 -> V_20 . type , 1 , V_92 ,
V_129 , NULL ) ;
}
static void
F_118 ( struct V_1 * V_2 , struct V_105 * V_106 ,
struct V_91 * V_92 )
{
struct V_101 * V_32 = & V_2 -> V_31 . V_32 ;
struct V_126 * V_127 = V_32 -> V_127 ;
struct V_107 * V_95 ;
struct V_128 * V_129 ;
int V_72 , V_130 , V_98 ;
int V_131 ;
if ( V_127 && ! F_112 ( V_127 , V_92 ) )
return;
V_129 = F_113 ( V_32 -> V_132 ) ;
if ( F_114 ( V_129 ) )
return;
V_98 = F_90 ( & V_2 -> V_31 , V_92 ) ;
V_130 = sizeof( * V_95 ) + V_2 -> V_31 . V_72 + V_98 ;
V_72 = F_115 ( V_130 + sizeof( V_133 ) , sizeof( V_134 ) ) ;
V_72 -= sizeof( V_133 ) ;
V_95 = F_116 ( V_72 , NULL , & V_131 ) ;
if ( ! V_95 )
return;
V_95 -> V_108 = ( unsigned long ) V_2 -> V_3 . V_6 . V_16 ;
V_95 -> V_109 = ( unsigned long ) V_106 -> V_110 ;
F_93 ( sizeof( * V_95 ) , & V_2 -> V_31 , V_92 , ( V_104 * ) & V_95 [ 1 ] , V_98 ) ;
F_117 ( V_95 , V_72 , V_131 , V_32 -> V_20 . type , 1 , V_92 ,
V_129 , NULL ) ;
}
static int F_119 ( struct V_101 * V_20 ,
enum V_135 type , void * V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 -> V_59 ;
struct V_38 * V_39 = V_59 ;
switch ( type ) {
case V_136 :
return F_30 ( V_2 , V_39 ) ;
case V_137 :
return F_36 ( V_2 , V_39 ) ;
#ifdef F_120
case V_138 :
return F_30 ( V_2 , NULL ) ;
case V_139 :
return F_36 ( V_2 , NULL ) ;
case V_140 :
case V_141 :
case V_142 :
case V_143 :
return 0 ;
#endif
}
return 0 ;
}
static int V_29 ( struct V_144 * V_6 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_100 ( V_6 , struct V_1 , V_3 . V_6 ) ;
F_121 ( * V_2 -> V_12 ) ;
if ( V_2 -> V_31 . V_43 & V_44 )
F_95 ( V_2 , V_92 ) ;
#ifdef F_120
if ( V_2 -> V_31 . V_43 & V_45 )
F_111 ( V_2 , V_92 ) ;
#endif
return 0 ;
}
static int
V_27 ( struct V_105 * V_106 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_100 ( V_106 -> V_3 , struct V_1 , V_3 ) ;
F_121 ( * V_2 -> V_12 ) ;
if ( V_2 -> V_31 . V_43 & V_44 )
F_98 ( V_2 , V_106 , V_92 ) ;
#ifdef F_120
if ( V_2 -> V_31 . V_43 & V_45 )
F_118 ( V_2 , V_106 , V_92 ) ;
#endif
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_101 * V_32 = & V_2 -> V_31 . V_32 ;
int V_24 ;
F_23 ( & V_32 -> V_33 -> V_145 ) ;
if ( F_1 ( V_2 ) ) {
V_32 -> V_20 . V_146 = & V_147 ;
V_32 -> V_33 -> V_148 = F_110 ;
} else {
V_32 -> V_20 . V_146 = & V_149 ;
V_32 -> V_33 -> V_148 = F_107 ;
}
if ( F_122 ( & V_2 -> V_31 , F_1 ( V_2 ) ) < 0 )
return - V_25 ;
V_24 = F_123 ( & V_32 -> V_20 ) ;
if ( ! V_24 ) {
F_14 ( V_32 -> V_150 ) ;
return - V_151 ;
}
V_32 -> V_43 = V_152 ;
V_32 -> V_33 -> V_153 = F_119 ;
V_32 -> V_59 = V_2 ;
V_24 = F_124 ( V_32 ) ;
if ( V_24 ) {
F_62 ( L_35 ,
F_29 ( V_32 ) ) ;
F_14 ( V_32 -> V_150 ) ;
F_125 ( & V_32 -> V_20 ) ;
}
return V_24 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_24 ;
V_24 = F_126 ( & V_2 -> V_31 . V_32 ) ;
if ( ! V_24 )
F_14 ( V_2 -> V_31 . V_32 . V_150 ) ;
return V_24 ;
}
static T_6 int F_127 ( void )
{
struct V_154 * V_155 ;
struct V_154 * V_95 ;
if ( F_128 ( & V_156 ) )
return - V_30 ;
V_155 = F_129 () ;
if ( F_65 ( V_155 ) )
return 0 ;
V_95 = F_130 ( L_36 , 0644 , V_155 ,
NULL , & V_157 ) ;
if ( ! V_95 )
F_48 ( L_37 ) ;
V_95 = F_130 ( L_38 , 0444 , V_155 ,
NULL , & V_158 ) ;
if ( ! V_95 )
F_48 ( L_39 ) ;
return 0 ;
}
static T_7 T_6 T_8 int
F_131 ( int V_159 , int V_160 , int V_161 , int V_162 , int V_163 , int V_164 )
{
return V_159 + V_160 + V_161 + V_162 + V_163 + V_164 ;
}
T_6 int F_132 ( void )
{
int V_24 , V_165 = 0 ;
int (* F_133)( int , int , int , int , int , int );
struct V_1 * V_2 ;
struct V_38 * V_39 ;
if ( F_134 () )
return - V_151 ;
F_133 = F_131 ;
F_62 ( L_40 ) ;
V_24 = F_135 ( L_41
L_42 ,
F_61 ) ;
if ( F_136 ( V_24 ) ) {
F_48 ( L_43 ) ;
V_165 ++ ;
} else {
V_2 = F_27 ( L_44 , V_68 ) ;
if ( F_136 ( V_2 == NULL ) ) {
F_48 ( L_45 ) ;
V_165 ++ ;
} else {
V_39 = F_137 ( V_2 , F_138 () ) ;
if ( F_136 ( V_39 == NULL ) ) {
F_48 ( L_46 ) ;
V_165 ++ ;
} else
F_30 ( V_2 , V_39 ) ;
}
}
V_24 = F_135 ( L_47
L_48 , F_61 ) ;
if ( F_136 ( V_24 ) ) {
F_48 ( L_49 ) ;
V_165 ++ ;
} else {
V_2 = F_27 ( L_50 , V_68 ) ;
if ( F_136 ( V_2 == NULL ) ) {
F_48 ( L_51 ) ;
V_165 ++ ;
} else {
V_39 = F_137 ( V_2 , F_138 () ) ;
if ( F_136 ( V_39 == NULL ) ) {
F_48 ( L_46 ) ;
V_165 ++ ;
} else
F_30 ( V_2 , V_39 ) ;
}
}
if ( V_165 )
goto V_54;
V_24 = F_133 ( 1 , 2 , 3 , 4 , 5 , 6 ) ;
if ( V_24 != 21 )
V_165 ++ ;
V_2 = F_27 ( L_44 , V_68 ) ;
if ( F_136 ( V_2 == NULL ) ) {
F_48 ( L_52 ) ;
V_165 ++ ;
} else {
if ( F_8 ( V_2 ) != 1 ) {
F_48 ( L_53 ) ;
V_165 ++ ;
}
V_39 = F_137 ( V_2 , F_138 () ) ;
if ( F_136 ( V_39 == NULL ) ) {
F_48 ( L_46 ) ;
V_165 ++ ;
} else
F_36 ( V_2 , V_39 ) ;
}
V_2 = F_27 ( L_50 , V_68 ) ;
if ( F_136 ( V_2 == NULL ) ) {
F_48 ( L_54 ) ;
V_165 ++ ;
} else {
if ( F_8 ( V_2 ) != 1 ) {
F_48 ( L_55 ) ;
V_165 ++ ;
}
V_39 = F_137 ( V_2 , F_138 () ) ;
if ( F_136 ( V_39 == NULL ) ) {
F_48 ( L_46 ) ;
V_165 ++ ;
} else
F_36 ( V_2 , V_39 ) ;
}
V_24 = F_135 ( L_56 , F_61 ) ;
if ( F_136 ( V_24 ) ) {
F_48 ( L_57 ) ;
V_165 ++ ;
}
V_24 = F_135 ( L_58 , F_61 ) ;
if ( F_136 ( V_24 ) ) {
F_48 ( L_57 ) ;
V_165 ++ ;
}
V_54:
F_69 () ;
if ( V_165 )
F_139 ( L_59 ) ;
else
F_139 ( L_60 ) ;
return 0 ;
}
