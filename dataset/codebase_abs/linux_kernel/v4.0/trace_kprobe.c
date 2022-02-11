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
if ( V_5 ) {
V_2 -> V_5 = F_14 ( V_5 , V_16 ) ;
if ( ! V_2 -> V_5 )
goto error;
V_2 -> V_3 . V_6 . V_24 = V_2 -> V_5 ;
V_2 -> V_3 . V_6 . V_7 = V_19 ;
} else
V_2 -> V_3 . V_6 . V_14 = V_14 ;
if ( V_21 )
V_2 -> V_3 . V_4 = V_25 ;
else
V_2 -> V_3 . V_6 . V_26 = V_27 ;
if ( ! V_18 || ! F_18 ( V_18 ) ) {
V_22 = - V_28 ;
goto error;
}
V_2 -> V_29 . V_30 . V_31 = & V_2 -> V_29 . V_31 ;
V_2 -> V_29 . V_30 . V_11 = F_14 ( V_18 , V_16 ) ;
if ( ! V_2 -> V_29 . V_30 . V_11 )
goto error;
if ( ! V_17 || ! F_18 ( V_17 ) ) {
V_22 = - V_28 ;
goto error;
}
V_2 -> V_29 . V_31 . system = F_14 ( V_17 , V_16 ) ;
if ( ! V_2 -> V_29 . V_31 . system )
goto error;
F_19 ( & V_2 -> V_32 ) ;
F_19 ( & V_2 -> V_29 . V_33 ) ;
return V_2 ;
error:
F_11 ( V_2 -> V_29 . V_30 . V_11 ) ;
F_11 ( V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
return F_17 ( V_22 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_2 -> V_29 . V_35 ; V_34 ++ )
F_21 ( & V_2 -> V_29 . args [ V_34 ] ) ;
F_11 ( V_2 -> V_29 . V_30 . V_31 -> system ) ;
F_11 ( V_2 -> V_29 . V_30 . V_11 ) ;
F_11 ( V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
}
static struct V_1 * F_22 ( const char * V_18 ,
const char * V_17 )
{
struct V_1 * V_2 ;
F_23 (tk, &probe_list, list)
if ( strcmp ( F_24 ( & V_2 -> V_29 . V_30 ) , V_18 ) == 0 &&
strcmp ( V_2 -> V_29 . V_30 . V_31 -> system , V_17 ) == 0 )
return V_2 ;
return NULL ;
}
static int
F_25 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
int V_22 = 0 ;
if ( V_37 ) {
struct V_38 * V_39 ;
V_39 = F_26 ( sizeof( * V_39 ) , V_16 ) ;
if ( ! V_39 ) {
V_22 = - V_23 ;
goto V_40;
}
V_39 -> V_37 = V_37 ;
F_27 ( & V_39 -> V_32 , & V_2 -> V_29 . V_33 ) ;
V_2 -> V_29 . V_41 |= V_42 ;
} else
V_2 -> V_29 . V_41 |= V_43 ;
if ( F_28 ( & V_2 -> V_29 ) && ! F_4 ( V_2 ) ) {
if ( F_1 ( V_2 ) )
V_22 = F_29 ( & V_2 -> V_3 ) ;
else
V_22 = F_30 ( & V_2 -> V_3 . V_6 ) ;
}
V_40:
return V_22 ;
}
static int
F_31 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
struct V_38 * V_39 = NULL ;
int V_44 = 0 ;
int V_22 = 0 ;
if ( V_37 ) {
V_39 = F_32 ( & V_2 -> V_29 , V_37 ) ;
if ( ! V_39 ) {
V_22 = - V_28 ;
goto V_40;
}
F_33 ( & V_39 -> V_32 ) ;
V_44 = 1 ;
if ( ! F_34 ( & V_2 -> V_29 . V_33 ) )
goto V_40;
V_2 -> V_29 . V_41 &= ~ V_42 ;
} else
V_2 -> V_29 . V_41 &= ~ V_43 ;
if ( ! F_35 ( & V_2 -> V_29 ) && F_28 ( & V_2 -> V_29 ) ) {
if ( F_1 ( V_2 ) )
F_36 ( & V_2 -> V_3 ) ;
else
F_37 ( & V_2 -> V_3 . V_6 ) ;
V_44 = 1 ;
}
V_40:
if ( V_44 ) {
F_38 () ;
F_11 ( V_39 ) ;
}
return V_22 ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_34 , V_22 ;
if ( F_28 ( & V_2 -> V_29 ) )
return - V_28 ;
for ( V_34 = 0 ; V_34 < V_2 -> V_29 . V_35 ; V_34 ++ )
F_40 ( & V_2 -> V_29 . args [ V_34 ] ) ;
if ( F_35 ( & V_2 -> V_29 ) )
V_2 -> V_3 . V_6 . V_41 &= ~ V_45 ;
else
V_2 -> V_3 . V_6 . V_41 |= V_45 ;
if ( F_1 ( V_2 ) )
V_22 = F_41 ( & V_2 -> V_3 ) ;
else
V_22 = F_42 ( & V_2 -> V_3 . V_6 ) ;
if ( V_22 == 0 )
V_2 -> V_29 . V_41 |= V_46 ;
else {
F_43 ( L_2 ,
F_2 ( V_2 ) , F_3 ( V_2 ) , V_22 ) ;
if ( V_22 == - V_47 && F_7 ( V_2 ) ) {
F_43 ( L_3
L_4 ) ;
V_22 = 0 ;
} else if ( V_22 == - V_48 ) {
F_43 ( L_5
L_6 ,
V_2 -> V_3 . V_6 . V_14 ) ;
V_22 = - V_28 ;
}
}
return V_22 ;
}
static void F_44 ( struct V_1 * V_2 )
{
if ( F_28 ( & V_2 -> V_29 ) ) {
if ( F_1 ( V_2 ) )
F_45 ( & V_2 -> V_3 ) ;
else
F_46 ( & V_2 -> V_3 . V_6 ) ;
V_2 -> V_29 . V_41 &= ~ V_46 ;
if ( V_2 -> V_3 . V_6 . V_24 )
V_2 -> V_3 . V_6 . V_14 = NULL ;
}
}
static int F_47 ( struct V_1 * V_2 )
{
if ( F_35 ( & V_2 -> V_29 ) )
return - V_49 ;
if ( F_48 ( V_2 ) )
return - V_49 ;
F_44 ( V_2 ) ;
F_49 ( & V_2 -> V_32 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_1 * V_50 ;
int V_22 ;
F_51 ( & V_51 ) ;
V_50 = F_22 ( F_24 ( & V_2 -> V_29 . V_30 ) ,
V_2 -> V_29 . V_30 . V_31 -> system ) ;
if ( V_50 ) {
V_22 = F_47 ( V_50 ) ;
if ( V_22 < 0 )
goto V_52;
F_20 ( V_50 ) ;
}
V_22 = F_52 ( V_2 ) ;
if ( V_22 ) {
F_43 ( L_7 , V_22 ) ;
goto V_52;
}
V_22 = F_39 ( V_2 ) ;
if ( V_22 < 0 )
F_48 ( V_2 ) ;
else
F_53 ( & V_2 -> V_32 , & V_53 ) ;
V_52:
F_54 ( & V_51 ) ;
return V_22 ;
}
static int F_55 ( struct V_54 * V_55 ,
unsigned long V_56 , void * V_57 )
{
struct V_8 * V_9 = V_57 ;
struct V_1 * V_2 ;
int V_22 ;
if ( V_56 != V_58 )
return V_59 ;
F_51 ( & V_51 ) ;
F_23 (tk, &probe_list, list) {
if ( F_6 ( V_2 , V_9 ) ) {
F_44 ( V_2 ) ;
V_22 = F_39 ( V_2 ) ;
if ( V_22 )
F_43 ( L_8
L_9 ,
F_24 ( & V_2 -> V_29 . V_30 ) ,
V_9 -> V_11 , V_22 ) ;
}
}
F_54 ( & V_51 ) ;
return V_59 ;
}
static int F_56 ( int V_60 , char * * V_61 )
{
struct V_1 * V_2 ;
int V_34 , V_22 = 0 ;
bool V_21 = false , V_62 = false ;
char * V_5 = NULL , * V_18 = NULL , * V_17 = NULL ;
char * V_63 ;
unsigned long V_7 = 0 ;
void * V_14 = NULL ;
char V_64 [ V_65 ] ;
if ( V_61 [ 0 ] [ 0 ] == 'p' )
V_21 = false ;
else if ( V_61 [ 0 ] [ 0 ] == 'r' )
V_21 = true ;
else if ( V_61 [ 0 ] [ 0 ] == '-' )
V_62 = true ;
else {
F_57 ( L_10
L_11 ) ;
return - V_28 ;
}
if ( V_61 [ 0 ] [ 1 ] == ':' ) {
V_18 = & V_61 [ 0 ] [ 2 ] ;
if ( strchr ( V_18 , '/' ) ) {
V_17 = V_18 ;
V_18 = strchr ( V_17 , '/' ) + 1 ;
V_18 [ - 1 ] = '\0' ;
if ( strlen ( V_17 ) == 0 ) {
F_57 ( L_12 ) ;
return - V_28 ;
}
}
if ( strlen ( V_18 ) == 0 ) {
F_57 ( L_13 ) ;
return - V_28 ;
}
}
if ( ! V_17 )
V_17 = V_66 ;
if ( V_62 ) {
if ( ! V_18 ) {
F_57 ( L_14 ) ;
return - V_28 ;
}
F_51 ( & V_51 ) ;
V_2 = F_22 ( V_18 , V_17 ) ;
if ( ! V_2 ) {
F_54 ( & V_51 ) ;
F_57 ( L_15 , V_17 , V_18 ) ;
return - V_47 ;
}
V_22 = F_47 ( V_2 ) ;
if ( V_22 == 0 )
F_20 ( V_2 ) ;
F_54 ( & V_51 ) ;
return V_22 ;
}
if ( V_60 < 2 ) {
F_57 ( L_16 ) ;
return - V_28 ;
}
if ( isdigit ( V_61 [ 1 ] [ 0 ] ) ) {
if ( V_21 ) {
F_57 ( L_17 ) ;
return - V_28 ;
}
V_22 = F_58 ( & V_61 [ 1 ] [ 0 ] , 0 , ( unsigned long * ) & V_14 ) ;
if ( V_22 ) {
F_57 ( L_18 ) ;
return V_22 ;
}
} else {
V_5 = V_61 [ 1 ] ;
V_22 = F_59 ( V_5 , & V_7 ) ;
if ( V_22 ) {
F_57 ( L_19 ) ;
return V_22 ;
}
if ( V_7 && V_21 ) {
F_57 ( L_20 ) ;
return - V_28 ;
}
}
V_60 -= 2 ; V_61 += 2 ;
if ( ! V_18 ) {
if ( V_5 )
snprintf ( V_64 , V_65 , L_21 ,
V_21 ? 'r' : 'p' , V_5 , V_7 ) ;
else
snprintf ( V_64 , V_65 , L_22 ,
V_21 ? 'r' : 'p' , V_14 ) ;
V_18 = V_64 ;
}
V_2 = F_15 ( V_17 , V_18 , V_14 , V_5 , V_7 , V_60 ,
V_21 ) ;
if ( F_60 ( V_2 ) ) {
F_57 ( L_23 ,
( int ) F_61 ( V_2 ) ) ;
return F_61 ( V_2 ) ;
}
V_22 = 0 ;
for ( V_34 = 0 ; V_34 < V_60 && V_34 < V_67 ; V_34 ++ ) {
struct V_68 * V_69 = & V_2 -> V_29 . args [ V_34 ] ;
V_2 -> V_29 . V_35 ++ ;
V_63 = strchr ( V_61 [ V_34 ] , '=' ) ;
if ( V_63 ) {
* V_63 ++ = '\0' ;
V_69 -> V_11 = F_14 ( V_61 [ V_34 ] , V_16 ) ;
} else {
V_63 = V_61 [ V_34 ] ;
snprintf ( V_64 , V_65 , L_24 , V_34 + 1 ) ;
V_69 -> V_11 = F_14 ( V_64 , V_16 ) ;
}
if ( ! V_69 -> V_11 ) {
F_57 ( L_25 , V_34 ) ;
V_22 = - V_23 ;
goto error;
}
if ( ! F_18 ( V_69 -> V_11 ) ) {
F_57 ( L_26 ,
V_34 , V_69 -> V_11 ) ;
V_22 = - V_28 ;
goto error;
}
if ( F_62 ( V_69 -> V_11 ,
V_2 -> V_29 . args , V_34 ) ) {
F_57 ( L_27
L_28 , V_34 , V_61 [ V_34 ] ) ;
V_22 = - V_28 ;
goto error;
}
V_22 = F_63 ( V_63 , & V_2 -> V_29 . V_70 , V_69 ,
V_21 , true ) ;
if ( V_22 ) {
F_57 ( L_29 , V_34 , V_22 ) ;
goto error;
}
}
V_22 = F_50 ( V_2 ) ;
if ( V_22 )
goto error;
return 0 ;
error:
F_20 ( V_2 ) ;
return V_22 ;
}
static int F_64 ( void )
{
struct V_1 * V_2 ;
int V_22 = 0 ;
F_51 ( & V_51 ) ;
F_23 (tk, &probe_list, list)
if ( F_35 ( & V_2 -> V_29 ) ) {
V_22 = - V_49 ;
goto V_52;
}
while ( ! F_34 ( & V_53 ) ) {
V_2 = F_65 ( V_53 . V_71 , struct V_1 , V_32 ) ;
V_22 = F_47 ( V_2 ) ;
if ( V_22 )
goto V_52;
F_20 ( V_2 ) ;
}
V_52:
F_54 ( & V_51 ) ;
return V_22 ;
}
static void * F_66 ( struct V_72 * V_73 , T_2 * V_74 )
{
F_51 ( & V_51 ) ;
return F_67 ( & V_53 , * V_74 ) ;
}
static void * F_68 ( struct V_72 * V_73 , void * V_75 , T_2 * V_74 )
{
return F_69 ( V_75 , & V_53 , V_74 ) ;
}
static void F_70 ( struct V_72 * V_73 , void * V_75 )
{
F_54 ( & V_51 ) ;
}
static int F_71 ( struct V_72 * V_73 , void * V_75 )
{
struct V_1 * V_2 = V_75 ;
int V_34 ;
F_72 ( V_73 , F_1 ( V_2 ) ? 'r' : 'p' ) ;
F_73 ( V_73 , L_30 , V_2 -> V_29 . V_30 . V_31 -> system ,
F_24 ( & V_2 -> V_29 . V_30 ) ) ;
if ( ! V_2 -> V_5 )
F_73 ( V_73 , L_31 , V_2 -> V_3 . V_6 . V_14 ) ;
else if ( V_2 -> V_3 . V_6 . V_7 )
F_73 ( V_73 , L_32 , F_2 ( V_2 ) ,
V_2 -> V_3 . V_6 . V_7 ) ;
else
F_73 ( V_73 , L_33 , F_2 ( V_2 ) ) ;
for ( V_34 = 0 ; V_34 < V_2 -> V_29 . V_35 ; V_34 ++ )
F_73 ( V_73 , L_34 , V_2 -> V_29 . args [ V_34 ] . V_11 , V_2 -> V_29 . args [ V_34 ] . V_76 ) ;
F_72 ( V_73 , '\n' ) ;
return 0 ;
}
static int F_74 ( struct V_77 * V_77 , struct V_37 * V_37 )
{
int V_22 ;
if ( ( V_37 -> V_78 & V_79 ) && ( V_37 -> V_80 & V_81 ) ) {
V_22 = F_64 () ;
if ( V_22 < 0 )
return V_22 ;
}
return F_75 ( V_37 , & V_82 ) ;
}
static T_3 F_76 ( struct V_37 * V_37 , const char T_4 * V_83 ,
T_5 V_84 , T_2 * V_85 )
{
return F_77 ( V_37 , V_83 , V_84 , V_85 ,
F_56 ) ;
}
static int F_78 ( struct V_72 * V_73 , void * V_75 )
{
struct V_1 * V_2 = V_75 ;
F_73 ( V_73 , L_35 ,
F_24 ( & V_2 -> V_29 . V_30 ) , V_2 -> V_86 ,
V_2 -> V_3 . V_6 . V_87 ) ;
return 0 ;
}
static int F_79 ( struct V_77 * V_77 , struct V_37 * V_37 )
{
return F_75 ( V_37 , & V_88 ) ;
}
static T_1 void
F_80 ( struct V_1 * V_2 , struct V_89 * V_90 ,
struct V_36 * V_91 )
{
struct V_92 * V_93 ;
struct V_94 * V_18 ;
struct V_95 * V_83 ;
int V_70 , V_96 , V_97 ;
unsigned long V_98 ;
struct V_99 * V_30 = & V_2 -> V_29 . V_30 ;
F_81 ( V_30 != V_91 -> V_100 ) ;
if ( F_82 ( V_91 ) )
return;
F_83 ( V_98 ) ;
V_97 = F_84 () ;
V_96 = F_85 ( & V_2 -> V_29 , V_90 ) ;
V_70 = sizeof( * V_93 ) + V_2 -> V_29 . V_70 + V_96 ;
V_18 = F_86 ( & V_83 , V_91 ,
V_30 -> V_18 . type ,
V_70 , V_98 , V_97 ) ;
if ( ! V_18 )
return;
V_93 = F_87 ( V_18 ) ;
V_93 -> V_101 = ( unsigned long ) V_2 -> V_3 . V_6 . V_14 ;
F_88 ( sizeof( * V_93 ) , & V_2 -> V_29 , V_90 , ( V_102 * ) & V_93 [ 1 ] , V_96 ) ;
F_89 ( V_91 , V_83 , V_18 ,
V_93 , V_98 , V_97 , V_90 ) ;
}
static void
F_90 ( struct V_1 * V_2 , struct V_89 * V_90 )
{
struct V_38 * V_39 ;
F_91 (link, &tk->tp.files, list)
F_80 ( V_2 , V_90 , V_39 -> V_37 ) ;
}
static T_1 void
F_92 ( struct V_1 * V_2 , struct V_103 * V_104 ,
struct V_89 * V_90 ,
struct V_36 * V_91 )
{
struct V_105 * V_93 ;
struct V_94 * V_18 ;
struct V_95 * V_83 ;
int V_70 , V_97 , V_96 ;
unsigned long V_98 ;
struct V_99 * V_30 = & V_2 -> V_29 . V_30 ;
F_81 ( V_30 != V_91 -> V_100 ) ;
if ( F_82 ( V_91 ) )
return;
F_83 ( V_98 ) ;
V_97 = F_84 () ;
V_96 = F_85 ( & V_2 -> V_29 , V_90 ) ;
V_70 = sizeof( * V_93 ) + V_2 -> V_29 . V_70 + V_96 ;
V_18 = F_86 ( & V_83 , V_91 ,
V_30 -> V_18 . type ,
V_70 , V_98 , V_97 ) ;
if ( ! V_18 )
return;
V_93 = F_87 ( V_18 ) ;
V_93 -> V_106 = ( unsigned long ) V_2 -> V_3 . V_6 . V_14 ;
V_93 -> V_107 = ( unsigned long ) V_104 -> V_108 ;
F_88 ( sizeof( * V_93 ) , & V_2 -> V_29 , V_90 , ( V_102 * ) & V_93 [ 1 ] , V_96 ) ;
F_89 ( V_91 , V_83 , V_18 ,
V_93 , V_98 , V_97 , V_90 ) ;
}
static void
F_93 ( struct V_1 * V_2 , struct V_103 * V_104 ,
struct V_89 * V_90 )
{
struct V_38 * V_39 ;
F_91 (link, &tk->tp.files, list)
F_92 ( V_2 , V_104 , V_90 , V_39 -> V_37 ) ;
}
static enum V_109
F_94 ( struct V_110 * V_111 , int V_41 ,
struct V_112 * V_18 )
{
struct V_92 * V_113 ;
struct V_114 * V_115 = & V_111 -> V_116 ;
struct V_117 * V_29 ;
V_102 * V_57 ;
int V_34 ;
V_113 = (struct V_92 * ) V_111 -> V_118 ;
V_29 = F_95 ( V_18 , struct V_117 , V_30 . V_18 ) ;
F_96 ( V_115 , L_36 , F_24 ( & V_29 -> V_30 ) ) ;
if ( ! F_97 ( V_115 , V_113 -> V_101 , V_41 | V_119 ) )
goto V_40;
F_98 ( V_115 , ')' ) ;
V_57 = ( V_102 * ) & V_113 [ 1 ] ;
for ( V_34 = 0 ; V_34 < V_29 -> V_35 ; V_34 ++ )
if ( ! V_29 -> args [ V_34 ] . type -> V_120 ( V_115 , V_29 -> args [ V_34 ] . V_11 ,
V_57 + V_29 -> args [ V_34 ] . V_7 , V_113 ) )
goto V_40;
F_98 ( V_115 , '\n' ) ;
V_40:
return F_99 ( V_115 ) ;
}
static enum V_109
F_100 ( struct V_110 * V_111 , int V_41 ,
struct V_112 * V_18 )
{
struct V_105 * V_113 ;
struct V_114 * V_115 = & V_111 -> V_116 ;
struct V_117 * V_29 ;
V_102 * V_57 ;
int V_34 ;
V_113 = (struct V_105 * ) V_111 -> V_118 ;
V_29 = F_95 ( V_18 , struct V_117 , V_30 . V_18 ) ;
F_96 ( V_115 , L_36 , F_24 ( & V_29 -> V_30 ) ) ;
if ( ! F_97 ( V_115 , V_113 -> V_107 , V_41 | V_119 ) )
goto V_40;
F_101 ( V_115 , L_37 ) ;
if ( ! F_97 ( V_115 , V_113 -> V_106 , V_41 & ~ V_119 ) )
goto V_40;
F_98 ( V_115 , ')' ) ;
V_57 = ( V_102 * ) & V_113 [ 1 ] ;
for ( V_34 = 0 ; V_34 < V_29 -> V_35 ; V_34 ++ )
if ( ! V_29 -> args [ V_34 ] . type -> V_120 ( V_115 , V_29 -> args [ V_34 ] . V_11 ,
V_57 + V_29 -> args [ V_34 ] . V_7 , V_113 ) )
goto V_40;
F_98 ( V_115 , '\n' ) ;
V_40:
return F_99 ( V_115 ) ;
}
static int F_102 ( struct V_99 * V_100 )
{
int V_22 , V_34 ;
struct V_92 V_113 ;
struct V_1 * V_2 = (struct V_1 * ) V_100 -> V_57 ;
F_103 (unsigned long, ip, FIELD_STRING_IP, 0 ) ;
for ( V_34 = 0 ; V_34 < V_2 -> V_29 . V_35 ; V_34 ++ ) {
struct V_68 * V_69 = & V_2 -> V_29 . args [ V_34 ] ;
V_22 = F_104 ( V_100 , V_69 -> type -> V_121 ,
V_69 -> V_11 ,
sizeof( V_113 ) + V_69 -> V_7 ,
V_69 -> type -> V_70 ,
V_69 -> type -> V_122 ,
V_123 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static int F_105 ( struct V_99 * V_100 )
{
int V_22 , V_34 ;
struct V_105 V_113 ;
struct V_1 * V_2 = (struct V_1 * ) V_100 -> V_57 ;
F_103 (unsigned long, func, FIELD_STRING_FUNC, 0 ) ;
F_103 (unsigned long, ret_ip, FIELD_STRING_RETIP, 0 ) ;
for ( V_34 = 0 ; V_34 < V_2 -> V_29 . V_35 ; V_34 ++ ) {
struct V_68 * V_69 = & V_2 -> V_29 . args [ V_34 ] ;
V_22 = F_104 ( V_100 , V_69 -> type -> V_121 ,
V_69 -> V_11 ,
sizeof( V_113 ) + V_69 -> V_7 ,
V_69 -> type -> V_70 ,
V_69 -> type -> V_122 ,
V_123 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static void
F_106 ( struct V_1 * V_2 , struct V_89 * V_90 )
{
struct V_99 * V_30 = & V_2 -> V_29 . V_30 ;
struct V_92 * V_93 ;
struct V_124 * V_125 ;
int V_70 , V_126 , V_96 ;
int V_127 ;
V_125 = F_107 ( V_30 -> V_128 ) ;
if ( F_108 ( V_125 ) )
return;
V_96 = F_85 ( & V_2 -> V_29 , V_90 ) ;
V_126 = sizeof( * V_93 ) + V_2 -> V_29 . V_70 + V_96 ;
V_70 = F_109 ( V_126 + sizeof( V_129 ) , sizeof( V_130 ) ) ;
V_70 -= sizeof( V_129 ) ;
V_93 = F_110 ( V_70 , V_30 -> V_18 . type , NULL , & V_127 ) ;
if ( ! V_93 )
return;
V_93 -> V_101 = ( unsigned long ) V_2 -> V_3 . V_6 . V_14 ;
memset ( & V_93 [ 1 ] , 0 , V_96 ) ;
F_88 ( sizeof( * V_93 ) , & V_2 -> V_29 , V_90 , ( V_102 * ) & V_93 [ 1 ] , V_96 ) ;
F_111 ( V_93 , V_70 , V_127 , 0 , 1 , V_90 , V_125 , NULL ) ;
}
static void
F_112 ( struct V_1 * V_2 , struct V_103 * V_104 ,
struct V_89 * V_90 )
{
struct V_99 * V_30 = & V_2 -> V_29 . V_30 ;
struct V_105 * V_93 ;
struct V_124 * V_125 ;
int V_70 , V_126 , V_96 ;
int V_127 ;
V_125 = F_107 ( V_30 -> V_128 ) ;
if ( F_108 ( V_125 ) )
return;
V_96 = F_85 ( & V_2 -> V_29 , V_90 ) ;
V_126 = sizeof( * V_93 ) + V_2 -> V_29 . V_70 + V_96 ;
V_70 = F_109 ( V_126 + sizeof( V_129 ) , sizeof( V_130 ) ) ;
V_70 -= sizeof( V_129 ) ;
V_93 = F_110 ( V_70 , V_30 -> V_18 . type , NULL , & V_127 ) ;
if ( ! V_93 )
return;
V_93 -> V_106 = ( unsigned long ) V_2 -> V_3 . V_6 . V_14 ;
V_93 -> V_107 = ( unsigned long ) V_104 -> V_108 ;
F_88 ( sizeof( * V_93 ) , & V_2 -> V_29 , V_90 , ( V_102 * ) & V_93 [ 1 ] , V_96 ) ;
F_111 ( V_93 , V_70 , V_127 , 0 , 1 , V_90 , V_125 , NULL ) ;
}
static int F_113 ( struct V_99 * V_18 ,
enum V_131 type , void * V_57 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_57 ;
struct V_36 * V_37 = V_57 ;
switch ( type ) {
case V_132 :
return F_25 ( V_2 , V_37 ) ;
case V_133 :
return F_31 ( V_2 , V_37 ) ;
#ifdef F_114
case V_134 :
return F_25 ( V_2 , NULL ) ;
case V_135 :
return F_31 ( V_2 , NULL ) ;
case V_136 :
case V_137 :
case V_138 :
case V_139 :
return 0 ;
#endif
}
return 0 ;
}
static int V_27 ( struct V_140 * V_6 , struct V_89 * V_90 )
{
struct V_1 * V_2 = F_95 ( V_6 , struct V_1 , V_3 . V_6 ) ;
V_2 -> V_86 ++ ;
if ( V_2 -> V_29 . V_41 & V_42 )
F_90 ( V_2 , V_90 ) ;
#ifdef F_114
if ( V_2 -> V_29 . V_41 & V_43 )
F_106 ( V_2 , V_90 ) ;
#endif
return 0 ;
}
static int
V_25 ( struct V_103 * V_104 , struct V_89 * V_90 )
{
struct V_1 * V_2 = F_95 ( V_104 -> V_3 , struct V_1 , V_3 ) ;
V_2 -> V_86 ++ ;
if ( V_2 -> V_29 . V_41 & V_42 )
F_93 ( V_2 , V_104 , V_90 ) ;
#ifdef F_114
if ( V_2 -> V_29 . V_41 & V_43 )
F_112 ( V_2 , V_104 , V_90 ) ;
#endif
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_99 * V_30 = & V_2 -> V_29 . V_30 ;
int V_22 ;
F_19 ( & V_30 -> V_31 -> V_141 ) ;
if ( F_1 ( V_2 ) ) {
V_30 -> V_18 . V_142 = & V_143 ;
V_30 -> V_31 -> V_144 = F_105 ;
} else {
V_30 -> V_18 . V_142 = & V_145 ;
V_30 -> V_31 -> V_144 = F_102 ;
}
if ( F_115 ( & V_2 -> V_29 , F_1 ( V_2 ) ) < 0 )
return - V_23 ;
V_22 = F_116 ( & V_30 -> V_18 ) ;
if ( ! V_22 ) {
F_11 ( V_30 -> V_146 ) ;
return - V_147 ;
}
V_30 -> V_41 = 0 ;
V_30 -> V_31 -> V_148 = F_113 ;
V_30 -> V_57 = V_2 ;
V_22 = F_117 ( V_30 ) ;
if ( V_22 ) {
F_57 ( L_38 ,
F_24 ( V_30 ) ) ;
F_11 ( V_30 -> V_146 ) ;
F_118 ( & V_30 -> V_18 ) ;
}
return V_22 ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_22 ;
V_22 = F_119 ( & V_2 -> V_29 . V_30 ) ;
if ( ! V_22 )
F_11 ( V_2 -> V_29 . V_30 . V_146 ) ;
return V_22 ;
}
static T_6 int F_120 ( void )
{
struct V_149 * V_150 ;
struct V_149 * V_93 ;
if ( F_121 ( & V_151 ) )
return - V_28 ;
V_150 = F_122 () ;
if ( F_60 ( V_150 ) )
return 0 ;
V_93 = F_123 ( L_39 , 0644 , V_150 ,
NULL , & V_152 ) ;
if ( ! V_93 )
F_43 ( L_40
L_41 ) ;
V_93 = F_123 ( L_42 , 0444 , V_150 ,
NULL , & V_153 ) ;
if ( ! V_93 )
F_43 ( L_40
L_43 ) ;
return 0 ;
}
static T_7 int F_124 ( int V_154 , int V_155 , int V_156 ,
int V_157 , int V_158 , int V_159 )
{
return V_154 + V_155 + V_156 + V_157 + V_158 + V_159 ;
}
static struct V_36 *
F_125 ( struct V_1 * V_2 , struct V_160 * V_161 )
{
struct V_36 * V_37 ;
F_23 (file, &tr->events, list)
if ( V_37 -> V_100 == & V_2 -> V_29 . V_30 )
return V_37 ;
return NULL ;
}
static T_6 int F_126 ( void )
{
int V_22 , V_162 = 0 ;
int (* F_127)( int , int , int , int , int , int );
struct V_1 * V_2 ;
struct V_36 * V_37 ;
if ( F_128 () )
return - V_147 ;
F_127 = F_124 ;
F_57 ( L_44 ) ;
V_22 = F_129 ( L_45
L_46 ,
F_56 ) ;
if ( F_130 ( V_22 ) ) {
F_131 ( L_47 ) ;
V_162 ++ ;
} else {
V_2 = F_22 ( L_48 , V_66 ) ;
if ( F_130 ( V_2 == NULL ) ) {
F_131 ( L_49 ) ;
V_162 ++ ;
} else {
V_37 = F_125 ( V_2 , F_132 () ) ;
if ( F_130 ( V_37 == NULL ) ) {
F_131 ( L_50 ) ;
V_162 ++ ;
} else
F_25 ( V_2 , V_37 ) ;
}
}
V_22 = F_129 ( L_51
L_52 , F_56 ) ;
if ( F_130 ( V_22 ) ) {
F_131 ( L_53 ) ;
V_162 ++ ;
} else {
V_2 = F_22 ( L_54 , V_66 ) ;
if ( F_130 ( V_2 == NULL ) ) {
F_131 ( L_55 ) ;
V_162 ++ ;
} else {
V_37 = F_125 ( V_2 , F_132 () ) ;
if ( F_130 ( V_37 == NULL ) ) {
F_131 ( L_50 ) ;
V_162 ++ ;
} else
F_25 ( V_2 , V_37 ) ;
}
}
if ( V_162 )
goto V_52;
V_22 = F_127 ( 1 , 2 , 3 , 4 , 5 , 6 ) ;
V_2 = F_22 ( L_48 , V_66 ) ;
if ( F_130 ( V_2 == NULL ) ) {
F_131 ( L_56 ) ;
V_162 ++ ;
} else {
V_37 = F_125 ( V_2 , F_132 () ) ;
if ( F_130 ( V_37 == NULL ) ) {
F_131 ( L_50 ) ;
V_162 ++ ;
} else
F_31 ( V_2 , V_37 ) ;
}
V_2 = F_22 ( L_54 , V_66 ) ;
if ( F_130 ( V_2 == NULL ) ) {
F_131 ( L_57 ) ;
V_162 ++ ;
} else {
V_37 = F_125 ( V_2 , F_132 () ) ;
if ( F_130 ( V_37 == NULL ) ) {
F_131 ( L_50 ) ;
V_162 ++ ;
} else
F_31 ( V_2 , V_37 ) ;
}
V_22 = F_129 ( L_58 , F_56 ) ;
if ( F_130 ( V_22 ) ) {
F_131 ( L_59 ) ;
V_162 ++ ;
}
V_22 = F_129 ( L_60 , F_56 ) ;
if ( F_130 ( V_22 ) ) {
F_131 ( L_59 ) ;
V_162 ++ ;
}
V_52:
F_64 () ;
if ( V_162 )
F_133 ( L_61 ) ;
else
F_133 ( L_62 ) ;
return 0 ;
}
