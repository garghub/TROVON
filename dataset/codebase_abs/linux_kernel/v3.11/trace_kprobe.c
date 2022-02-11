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
return ! ! ( V_2 -> V_8 & ( V_9 | V_10 ) ) ;
}
static T_1 bool F_5 ( struct V_1 * V_2 )
{
return ! ! ( V_2 -> V_8 & V_11 ) ;
}
static T_1 bool F_6 ( struct V_1 * V_2 )
{
return ! ! ( F_7 ( & V_2 -> V_3 . V_6 ) ) ;
}
static T_1 bool F_8 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
int V_14 = strlen ( V_13 -> V_15 ) ;
const char * V_15 = F_2 ( V_2 ) ;
return strncmp ( V_13 -> V_15 , V_15 , V_14 ) == 0 && V_15 [ V_14 ] == ':' ;
}
static T_1 bool F_9 ( struct V_1 * V_2 )
{
return ! ! strchr ( F_2 ( V_2 ) , ':' ) ;
}
static struct V_1 * F_10 ( const char * V_16 ,
const char * V_17 ,
void * V_18 ,
const char * V_5 ,
unsigned long V_19 ,
int V_20 , bool V_21 )
{
struct V_1 * V_2 ;
int V_22 = - V_23 ;
V_2 = F_11 ( F_12 ( V_20 ) , V_24 ) ;
if ( ! V_2 )
return F_13 ( V_22 ) ;
if ( V_5 ) {
V_2 -> V_5 = F_14 ( V_5 , V_24 ) ;
if ( ! V_2 -> V_5 )
goto error;
V_2 -> V_3 . V_6 . V_25 = V_2 -> V_5 ;
V_2 -> V_3 . V_6 . V_7 = V_19 ;
} else
V_2 -> V_3 . V_6 . V_18 = V_18 ;
if ( V_21 )
V_2 -> V_3 . V_4 = V_26 ;
else
V_2 -> V_3 . V_6 . V_27 = V_28 ;
if ( ! V_17 || ! F_15 ( V_17 ) ) {
V_22 = - V_29 ;
goto error;
}
V_2 -> V_30 . V_31 = & V_2 -> V_31 ;
V_2 -> V_30 . V_15 = F_14 ( V_17 , V_24 ) ;
if ( ! V_2 -> V_30 . V_15 )
goto error;
if ( ! V_16 || ! F_15 ( V_16 ) ) {
V_22 = - V_29 ;
goto error;
}
V_2 -> V_31 . system = F_14 ( V_16 , V_24 ) ;
if ( ! V_2 -> V_31 . system )
goto error;
F_16 ( & V_2 -> V_32 ) ;
F_16 ( & V_2 -> V_33 ) ;
return V_2 ;
error:
F_17 ( V_2 -> V_30 . V_15 ) ;
F_17 ( V_2 -> V_5 ) ;
F_17 ( V_2 ) ;
return F_13 ( V_22 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_2 -> V_35 ; V_34 ++ )
F_19 ( & V_2 -> args [ V_34 ] ) ;
F_17 ( V_2 -> V_30 . V_31 -> system ) ;
F_17 ( V_2 -> V_30 . V_15 ) ;
F_17 ( V_2 -> V_5 ) ;
F_17 ( V_2 ) ;
}
static struct V_1 * F_20 ( const char * V_17 ,
const char * V_16 )
{
struct V_1 * V_2 ;
F_21 (tp, &probe_list, list)
if ( strcmp ( V_2 -> V_30 . V_15 , V_17 ) == 0 &&
strcmp ( V_2 -> V_30 . V_31 -> system , V_16 ) == 0 )
return V_2 ;
return NULL ;
}
static int
F_22 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
int V_22 = 0 ;
if ( V_37 ) {
struct V_38 * V_39 ;
V_39 = F_23 ( sizeof( * V_39 ) , V_24 ) ;
if ( ! V_39 ) {
V_22 = - V_23 ;
goto V_40;
}
V_39 -> V_37 = V_37 ;
F_24 ( & V_39 -> V_32 , & V_2 -> V_33 ) ;
V_2 -> V_8 |= V_9 ;
} else
V_2 -> V_8 |= V_10 ;
if ( F_5 ( V_2 ) && ! F_6 ( V_2 ) ) {
if ( F_1 ( V_2 ) )
V_22 = F_25 ( & V_2 -> V_3 ) ;
else
V_22 = F_26 ( & V_2 -> V_3 . V_6 ) ;
}
V_40:
return V_22 ;
}
static struct V_38 *
F_27 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
struct V_38 * V_39 ;
F_21 (link, &tp->files, list)
if ( V_39 -> V_37 == V_37 )
return V_39 ;
return NULL ;
}
static int
F_28 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
struct V_38 * V_39 = NULL ;
int V_41 = 0 ;
int V_22 = 0 ;
if ( V_37 ) {
V_39 = F_27 ( V_2 , V_37 ) ;
if ( ! V_39 ) {
V_22 = - V_29 ;
goto V_40;
}
F_29 ( & V_39 -> V_32 ) ;
V_41 = 1 ;
if ( ! F_30 ( & V_2 -> V_33 ) )
goto V_40;
V_2 -> V_8 &= ~ V_9 ;
} else
V_2 -> V_8 &= ~ V_10 ;
if ( ! F_4 ( V_2 ) && F_5 ( V_2 ) ) {
if ( F_1 ( V_2 ) )
F_31 ( & V_2 -> V_3 ) ;
else
F_32 ( & V_2 -> V_3 . V_6 ) ;
V_41 = 1 ;
}
V_40:
if ( V_41 ) {
F_33 () ;
F_17 ( V_39 ) ;
}
return V_22 ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_34 , V_22 ;
if ( F_5 ( V_2 ) )
return - V_29 ;
for ( V_34 = 0 ; V_34 < V_2 -> V_35 ; V_34 ++ )
F_35 ( & V_2 -> args [ V_34 ] ) ;
if ( F_4 ( V_2 ) )
V_2 -> V_3 . V_6 . V_8 &= ~ V_42 ;
else
V_2 -> V_3 . V_6 . V_8 |= V_42 ;
if ( F_1 ( V_2 ) )
V_22 = F_36 ( & V_2 -> V_3 ) ;
else
V_22 = F_37 ( & V_2 -> V_3 . V_6 ) ;
if ( V_22 == 0 )
V_2 -> V_8 |= V_11 ;
else {
F_38 ( L_2 ,
F_2 ( V_2 ) , F_3 ( V_2 ) , V_22 ) ;
if ( V_22 == - V_43 && F_9 ( V_2 ) ) {
F_38 ( L_3
L_4 ) ;
V_22 = 0 ;
} else if ( V_22 == - V_44 ) {
F_38 ( L_5
L_6 ,
V_2 -> V_3 . V_6 . V_18 ) ;
V_22 = - V_29 ;
}
}
return V_22 ;
}
static void F_39 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 ) ) {
if ( F_1 ( V_2 ) )
F_40 ( & V_2 -> V_3 ) ;
else
F_41 ( & V_2 -> V_3 . V_6 ) ;
V_2 -> V_8 &= ~ V_11 ;
if ( V_2 -> V_3 . V_6 . V_25 )
V_2 -> V_3 . V_6 . V_18 = NULL ;
}
}
static int F_42 ( struct V_1 * V_2 )
{
if ( F_4 ( V_2 ) )
return - V_45 ;
if ( F_43 ( V_2 ) )
return - V_45 ;
F_39 ( V_2 ) ;
F_44 ( & V_2 -> V_32 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_1 * V_46 ;
int V_22 ;
F_46 ( & V_47 ) ;
V_46 = F_20 ( V_2 -> V_30 . V_15 , V_2 -> V_30 . V_31 -> system ) ;
if ( V_46 ) {
V_22 = F_42 ( V_46 ) ;
if ( V_22 < 0 )
goto V_48;
F_18 ( V_46 ) ;
}
V_22 = F_47 ( V_2 ) ;
if ( V_22 ) {
F_38 ( L_7 , V_22 ) ;
goto V_48;
}
V_22 = F_34 ( V_2 ) ;
if ( V_22 < 0 )
F_43 ( V_2 ) ;
else
F_48 ( & V_2 -> V_32 , & V_49 ) ;
V_48:
F_49 ( & V_47 ) ;
return V_22 ;
}
static int F_50 ( struct V_50 * V_51 ,
unsigned long V_52 , void * V_53 )
{
struct V_12 * V_13 = V_53 ;
struct V_1 * V_2 ;
int V_22 ;
if ( V_52 != V_54 )
return V_55 ;
F_46 ( & V_47 ) ;
F_21 (tp, &probe_list, list) {
if ( F_8 ( V_2 , V_13 ) ) {
F_39 ( V_2 ) ;
V_22 = F_34 ( V_2 ) ;
if ( V_22 )
F_38 ( L_8
L_9 ,
V_2 -> V_30 . V_15 , V_13 -> V_15 , V_22 ) ;
}
}
F_49 ( & V_47 ) ;
return V_55 ;
}
static int F_51 ( int V_56 , char * * V_57 )
{
struct V_1 * V_2 ;
int V_34 , V_22 = 0 ;
bool V_21 = false , V_58 = false ;
char * V_5 = NULL , * V_17 = NULL , * V_16 = NULL ;
char * V_59 ;
unsigned long V_7 = 0 ;
void * V_18 = NULL ;
char V_60 [ V_61 ] ;
if ( V_57 [ 0 ] [ 0 ] == 'p' )
V_21 = false ;
else if ( V_57 [ 0 ] [ 0 ] == 'r' )
V_21 = true ;
else if ( V_57 [ 0 ] [ 0 ] == '-' )
V_58 = true ;
else {
F_52 ( L_10
L_11 ) ;
return - V_29 ;
}
if ( V_57 [ 0 ] [ 1 ] == ':' ) {
V_17 = & V_57 [ 0 ] [ 2 ] ;
if ( strchr ( V_17 , '/' ) ) {
V_16 = V_17 ;
V_17 = strchr ( V_16 , '/' ) + 1 ;
V_17 [ - 1 ] = '\0' ;
if ( strlen ( V_16 ) == 0 ) {
F_52 ( L_12 ) ;
return - V_29 ;
}
}
if ( strlen ( V_17 ) == 0 ) {
F_52 ( L_13 ) ;
return - V_29 ;
}
}
if ( ! V_16 )
V_16 = V_62 ;
if ( V_58 ) {
if ( ! V_17 ) {
F_52 ( L_14 ) ;
return - V_29 ;
}
F_46 ( & V_47 ) ;
V_2 = F_20 ( V_17 , V_16 ) ;
if ( ! V_2 ) {
F_49 ( & V_47 ) ;
F_52 ( L_15 , V_16 , V_17 ) ;
return - V_43 ;
}
V_22 = F_42 ( V_2 ) ;
if ( V_22 == 0 )
F_18 ( V_2 ) ;
F_49 ( & V_47 ) ;
return V_22 ;
}
if ( V_56 < 2 ) {
F_52 ( L_16 ) ;
return - V_29 ;
}
if ( isdigit ( V_57 [ 1 ] [ 0 ] ) ) {
if ( V_21 ) {
F_52 ( L_17 ) ;
return - V_29 ;
}
V_22 = F_53 ( & V_57 [ 1 ] [ 0 ] , 0 , ( unsigned long * ) & V_18 ) ;
if ( V_22 ) {
F_52 ( L_18 ) ;
return V_22 ;
}
} else {
V_5 = V_57 [ 1 ] ;
V_22 = F_54 ( V_5 , & V_7 ) ;
if ( V_22 ) {
F_52 ( L_19 ) ;
return V_22 ;
}
if ( V_7 && V_21 ) {
F_52 ( L_20 ) ;
return - V_29 ;
}
}
V_56 -= 2 ; V_57 += 2 ;
if ( ! V_17 ) {
if ( V_5 )
snprintf ( V_60 , V_61 , L_21 ,
V_21 ? 'r' : 'p' , V_5 , V_7 ) ;
else
snprintf ( V_60 , V_61 , L_22 ,
V_21 ? 'r' : 'p' , V_18 ) ;
V_17 = V_60 ;
}
V_2 = F_10 ( V_16 , V_17 , V_18 , V_5 , V_7 , V_56 ,
V_21 ) ;
if ( F_55 ( V_2 ) ) {
F_52 ( L_23 ,
( int ) F_56 ( V_2 ) ) ;
return F_56 ( V_2 ) ;
}
V_22 = 0 ;
for ( V_34 = 0 ; V_34 < V_56 && V_34 < V_63 ; V_34 ++ ) {
V_2 -> V_35 ++ ;
V_59 = strchr ( V_57 [ V_34 ] , '=' ) ;
if ( V_59 ) {
* V_59 ++ = '\0' ;
V_2 -> args [ V_34 ] . V_15 = F_14 ( V_57 [ V_34 ] , V_24 ) ;
} else {
V_59 = V_57 [ V_34 ] ;
snprintf ( V_60 , V_61 , L_24 , V_34 + 1 ) ;
V_2 -> args [ V_34 ] . V_15 = F_14 ( V_60 , V_24 ) ;
}
if ( ! V_2 -> args [ V_34 ] . V_15 ) {
F_52 ( L_25 , V_34 ) ;
V_22 = - V_23 ;
goto error;
}
if ( ! F_15 ( V_2 -> args [ V_34 ] . V_15 ) ) {
F_52 ( L_26 ,
V_34 , V_2 -> args [ V_34 ] . V_15 ) ;
V_22 = - V_29 ;
goto error;
}
if ( F_57 ( V_2 -> args [ V_34 ] . V_15 ,
V_2 -> args , V_34 ) ) {
F_52 ( L_27
L_28 , V_34 , V_57 [ V_34 ] ) ;
V_22 = - V_29 ;
goto error;
}
V_22 = F_58 ( V_59 , & V_2 -> V_64 , & V_2 -> args [ V_34 ] ,
V_21 , true ) ;
if ( V_22 ) {
F_52 ( L_29 , V_34 , V_22 ) ;
goto error;
}
}
V_22 = F_45 ( V_2 ) ;
if ( V_22 )
goto error;
return 0 ;
error:
F_18 ( V_2 ) ;
return V_22 ;
}
static int F_59 ( void )
{
struct V_1 * V_2 ;
int V_22 = 0 ;
F_46 ( & V_47 ) ;
F_21 (tp, &probe_list, list)
if ( F_4 ( V_2 ) ) {
V_22 = - V_45 ;
goto V_48;
}
while ( ! F_30 ( & V_49 ) ) {
V_2 = F_60 ( V_49 . V_65 , struct V_1 , V_32 ) ;
V_22 = F_42 ( V_2 ) ;
if ( V_22 )
goto V_48;
F_18 ( V_2 ) ;
}
V_48:
F_49 ( & V_47 ) ;
return V_22 ;
}
static void * F_61 ( struct V_66 * V_67 , T_2 * V_68 )
{
F_46 ( & V_47 ) ;
return F_62 ( & V_49 , * V_68 ) ;
}
static void * F_63 ( struct V_66 * V_67 , void * V_69 , T_2 * V_68 )
{
return F_64 ( V_69 , & V_49 , V_68 ) ;
}
static void F_65 ( struct V_66 * V_67 , void * V_69 )
{
F_49 ( & V_47 ) ;
}
static int F_66 ( struct V_66 * V_67 , void * V_69 )
{
struct V_1 * V_2 = V_69 ;
int V_34 ;
F_67 ( V_67 , L_30 , F_1 ( V_2 ) ? 'r' : 'p' ) ;
F_67 ( V_67 , L_31 , V_2 -> V_30 . V_31 -> system , V_2 -> V_30 . V_15 ) ;
if ( ! V_2 -> V_5 )
F_67 ( V_67 , L_32 , V_2 -> V_3 . V_6 . V_18 ) ;
else if ( V_2 -> V_3 . V_6 . V_7 )
F_67 ( V_67 , L_33 , F_2 ( V_2 ) ,
V_2 -> V_3 . V_6 . V_7 ) ;
else
F_67 ( V_67 , L_34 , F_2 ( V_2 ) ) ;
for ( V_34 = 0 ; V_34 < V_2 -> V_35 ; V_34 ++ )
F_67 ( V_67 , L_35 , V_2 -> args [ V_34 ] . V_15 , V_2 -> args [ V_34 ] . V_70 ) ;
F_67 ( V_67 , L_36 ) ;
return 0 ;
}
static int F_68 ( struct V_71 * V_71 , struct V_37 * V_37 )
{
int V_22 ;
if ( ( V_37 -> V_72 & V_73 ) && ( V_37 -> V_74 & V_75 ) ) {
V_22 = F_59 () ;
if ( V_22 < 0 )
return V_22 ;
}
return F_69 ( V_37 , & V_76 ) ;
}
static T_3 F_70 ( struct V_37 * V_37 , const char T_4 * V_77 ,
T_5 V_78 , T_2 * V_79 )
{
return F_71 ( V_37 , V_77 , V_78 , V_79 ,
F_51 ) ;
}
static int F_72 ( struct V_66 * V_67 , void * V_69 )
{
struct V_1 * V_2 = V_69 ;
F_67 ( V_67 , L_37 , V_2 -> V_30 . V_15 , V_2 -> V_80 ,
V_2 -> V_3 . V_6 . V_81 ) ;
return 0 ;
}
static int F_73 ( struct V_71 * V_71 , struct V_37 * V_37 )
{
return F_69 ( V_37 , & V_82 ) ;
}
static T_1 int F_74 ( struct V_1 * V_2 ,
struct V_83 * V_84 )
{
int V_34 , V_22 = 0 ;
T_6 V_14 ;
for ( V_34 = 0 ; V_34 < V_2 -> V_35 ; V_34 ++ )
if ( F_75 ( V_2 -> args [ V_34 ] . V_85 . V_86 ) ) {
F_76 ( & V_2 -> args [ V_34 ] . V_85 , V_84 , & V_14 ) ;
V_22 += V_14 ;
}
return V_22 ;
}
static T_1 void F_77 ( int V_87 , struct V_1 * V_2 ,
struct V_83 * V_84 ,
T_7 * V_53 , int V_88 )
{
int V_34 ;
T_6 V_48 = V_2 -> V_64 ;
T_6 * V_89 ;
for ( V_34 = 0 ; V_34 < V_2 -> V_35 ; V_34 ++ ) {
if ( F_75 ( V_2 -> args [ V_34 ] . V_85 . V_86 ) ) {
V_89 = ( T_6 * ) ( V_53 + V_2 -> args [ V_34 ] . V_7 ) ;
* V_89 = F_78 ( V_88 , V_48 - V_2 -> args [ V_34 ] . V_7 ) ;
F_76 ( & V_2 -> args [ V_34 ] . V_90 , V_84 , V_89 ) ;
V_48 += F_79 ( * V_89 ) ;
V_88 -= F_79 ( * V_89 ) ;
* V_89 = F_80 ( * V_89 ,
V_87 + V_2 -> args [ V_34 ] . V_7 ) ;
} else
F_76 ( & V_2 -> args [ V_34 ] . V_90 , V_84 ,
V_53 + V_2 -> args [ V_34 ] . V_7 ) ;
}
}
static T_1 void
F_81 ( struct V_1 * V_2 , struct V_83 * V_84 ,
struct V_36 * V_91 )
{
struct V_92 * V_93 ;
struct V_94 * V_17 ;
struct V_95 * V_77 ;
int V_64 , V_96 , V_97 ;
unsigned long V_98 ;
struct V_99 * V_30 = & V_2 -> V_30 ;
F_82 ( V_30 != V_91 -> V_100 ) ;
if ( F_83 ( V_101 , & V_91 -> V_8 ) )
return;
F_84 ( V_98 ) ;
V_97 = F_85 () ;
V_96 = F_74 ( V_2 , V_84 ) ;
V_64 = sizeof( * V_93 ) + V_2 -> V_64 + V_96 ;
V_17 = F_86 ( & V_77 , V_91 ,
V_30 -> V_17 . type ,
V_64 , V_98 , V_97 ) ;
if ( ! V_17 )
return;
V_93 = F_87 ( V_17 ) ;
V_93 -> V_102 = ( unsigned long ) V_2 -> V_3 . V_6 . V_18 ;
F_77 ( sizeof( * V_93 ) , V_2 , V_84 , ( T_7 * ) & V_93 [ 1 ] , V_96 ) ;
if ( ! F_88 ( V_77 , V_30 , V_93 , V_17 ) )
F_89 ( V_77 , V_17 ,
V_98 , V_97 , V_84 ) ;
}
static T_1 void
F_90 ( struct V_1 * V_2 , struct V_83 * V_84 )
{
struct V_38 * V_39 ;
F_91 (link, &tp->files, list)
F_81 ( V_2 , V_84 , V_39 -> V_37 ) ;
}
static T_1 void
F_92 ( struct V_1 * V_2 , struct V_103 * V_104 ,
struct V_83 * V_84 ,
struct V_36 * V_91 )
{
struct V_105 * V_93 ;
struct V_94 * V_17 ;
struct V_95 * V_77 ;
int V_64 , V_97 , V_96 ;
unsigned long V_98 ;
struct V_99 * V_30 = & V_2 -> V_30 ;
F_82 ( V_30 != V_91 -> V_100 ) ;
if ( F_83 ( V_101 , & V_91 -> V_8 ) )
return;
F_84 ( V_98 ) ;
V_97 = F_85 () ;
V_96 = F_74 ( V_2 , V_84 ) ;
V_64 = sizeof( * V_93 ) + V_2 -> V_64 + V_96 ;
V_17 = F_86 ( & V_77 , V_91 ,
V_30 -> V_17 . type ,
V_64 , V_98 , V_97 ) ;
if ( ! V_17 )
return;
V_93 = F_87 ( V_17 ) ;
V_93 -> V_106 = ( unsigned long ) V_2 -> V_3 . V_6 . V_18 ;
V_93 -> V_107 = ( unsigned long ) V_104 -> V_108 ;
F_77 ( sizeof( * V_93 ) , V_2 , V_84 , ( T_7 * ) & V_93 [ 1 ] , V_96 ) ;
if ( ! F_88 ( V_77 , V_30 , V_93 , V_17 ) )
F_89 ( V_77 , V_17 ,
V_98 , V_97 , V_84 ) ;
}
static T_1 void
F_93 ( struct V_1 * V_2 , struct V_103 * V_104 ,
struct V_83 * V_84 )
{
struct V_38 * V_39 ;
F_91 (link, &tp->files, list)
F_92 ( V_2 , V_104 , V_84 , V_39 -> V_37 ) ;
}
static enum V_109
F_94 ( struct V_110 * V_111 , int V_8 ,
struct V_112 * V_17 )
{
struct V_92 * V_113 ;
struct V_114 * V_115 = & V_111 -> V_116 ;
struct V_1 * V_2 ;
T_7 * V_53 ;
int V_34 ;
V_113 = (struct V_92 * ) V_111 -> V_117 ;
V_2 = F_95 ( V_17 , struct V_1 , V_30 . V_17 ) ;
if ( ! F_96 ( V_115 , L_38 , V_2 -> V_30 . V_15 ) )
goto V_118;
if ( ! F_97 ( V_115 , V_113 -> V_102 , V_8 | V_119 ) )
goto V_118;
if ( ! F_98 ( V_115 , L_39 ) )
goto V_118;
V_53 = ( T_7 * ) & V_113 [ 1 ] ;
for ( V_34 = 0 ; V_34 < V_2 -> V_35 ; V_34 ++ )
if ( ! V_2 -> args [ V_34 ] . type -> V_120 ( V_115 , V_2 -> args [ V_34 ] . V_15 ,
V_53 + V_2 -> args [ V_34 ] . V_7 , V_113 ) )
goto V_118;
if ( ! F_98 ( V_115 , L_36 ) )
goto V_118;
return V_121 ;
V_118:
return V_122 ;
}
static enum V_109
F_99 ( struct V_110 * V_111 , int V_8 ,
struct V_112 * V_17 )
{
struct V_105 * V_113 ;
struct V_114 * V_115 = & V_111 -> V_116 ;
struct V_1 * V_2 ;
T_7 * V_53 ;
int V_34 ;
V_113 = (struct V_105 * ) V_111 -> V_117 ;
V_2 = F_95 ( V_17 , struct V_1 , V_30 . V_17 ) ;
if ( ! F_96 ( V_115 , L_38 , V_2 -> V_30 . V_15 ) )
goto V_118;
if ( ! F_97 ( V_115 , V_113 -> V_107 , V_8 | V_119 ) )
goto V_118;
if ( ! F_98 ( V_115 , L_40 ) )
goto V_118;
if ( ! F_97 ( V_115 , V_113 -> V_106 , V_8 & ~ V_119 ) )
goto V_118;
if ( ! F_98 ( V_115 , L_39 ) )
goto V_118;
V_53 = ( T_7 * ) & V_113 [ 1 ] ;
for ( V_34 = 0 ; V_34 < V_2 -> V_35 ; V_34 ++ )
if ( ! V_2 -> args [ V_34 ] . type -> V_120 ( V_115 , V_2 -> args [ V_34 ] . V_15 ,
V_53 + V_2 -> args [ V_34 ] . V_7 , V_113 ) )
goto V_118;
if ( ! F_98 ( V_115 , L_36 ) )
goto V_118;
return V_121 ;
V_118:
return V_122 ;
}
static int F_100 ( struct V_99 * V_100 )
{
int V_22 , V_34 ;
struct V_92 V_113 ;
struct V_1 * V_2 = (struct V_1 * ) V_100 -> V_53 ;
F_101 (unsigned long, ip, FIELD_STRING_IP, 0 ) ;
for ( V_34 = 0 ; V_34 < V_2 -> V_35 ; V_34 ++ ) {
V_22 = F_102 ( V_100 , V_2 -> args [ V_34 ] . type -> V_123 ,
V_2 -> args [ V_34 ] . V_15 ,
sizeof( V_113 ) + V_2 -> args [ V_34 ] . V_7 ,
V_2 -> args [ V_34 ] . type -> V_64 ,
V_2 -> args [ V_34 ] . type -> V_124 ,
V_125 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static int F_103 ( struct V_99 * V_100 )
{
int V_22 , V_34 ;
struct V_105 V_113 ;
struct V_1 * V_2 = (struct V_1 * ) V_100 -> V_53 ;
F_101 (unsigned long, func, FIELD_STRING_FUNC, 0 ) ;
F_101 (unsigned long, ret_ip, FIELD_STRING_RETIP, 0 ) ;
for ( V_34 = 0 ; V_34 < V_2 -> V_35 ; V_34 ++ ) {
V_22 = F_102 ( V_100 , V_2 -> args [ V_34 ] . type -> V_123 ,
V_2 -> args [ V_34 ] . V_15 ,
sizeof( V_113 ) + V_2 -> args [ V_34 ] . V_7 ,
V_2 -> args [ V_34 ] . type -> V_64 ,
V_2 -> args [ V_34 ] . type -> V_124 ,
V_125 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static int F_104 ( struct V_1 * V_2 , char * V_60 , int V_14 )
{
int V_34 ;
int V_68 = 0 ;
const char * V_126 , * V_59 ;
if ( ! F_1 ( V_2 ) ) {
V_126 = L_41 ;
V_59 = L_42 V_127 ;
} else {
V_126 = L_43 ;
V_59 = L_42 V_128 L_44 V_129 ;
}
#define F_105 (len ? len - pos : 0)
V_68 += snprintf ( V_60 + V_68 , F_105 , L_45 , V_126 ) ;
for ( V_34 = 0 ; V_34 < V_2 -> V_35 ; V_34 ++ ) {
V_68 += snprintf ( V_60 + V_68 , F_105 , L_35 ,
V_2 -> args [ V_34 ] . V_15 , V_2 -> args [ V_34 ] . type -> V_126 ) ;
}
V_68 += snprintf ( V_60 + V_68 , F_105 , L_46 , V_59 ) ;
for ( V_34 = 0 ; V_34 < V_2 -> V_35 ; V_34 ++ ) {
if ( strcmp ( V_2 -> args [ V_34 ] . type -> V_15 , L_47 ) == 0 )
V_68 += snprintf ( V_60 + V_68 , F_105 ,
L_48 ,
V_2 -> args [ V_34 ] . V_15 ) ;
else
V_68 += snprintf ( V_60 + V_68 , F_105 , L_49 ,
V_2 -> args [ V_34 ] . V_15 ) ;
}
#undef F_105
return V_68 ;
}
static int F_106 ( struct V_1 * V_2 )
{
int V_14 ;
char * V_130 ;
V_14 = F_104 ( V_2 , NULL , 0 ) ;
V_130 = F_23 ( V_14 + 1 , V_24 ) ;
if ( ! V_130 )
return - V_23 ;
F_104 ( V_2 , V_130 , V_14 + 1 ) ;
V_2 -> V_30 . V_130 = V_130 ;
return 0 ;
}
static T_1 void
F_107 ( struct V_1 * V_2 , struct V_83 * V_84 )
{
struct V_99 * V_30 = & V_2 -> V_30 ;
struct V_92 * V_93 ;
struct V_131 * V_132 ;
int V_64 , V_133 , V_96 ;
int V_134 ;
V_132 = F_108 ( V_30 -> V_135 ) ;
if ( F_109 ( V_132 ) )
return;
V_96 = F_74 ( V_2 , V_84 ) ;
V_133 = sizeof( * V_93 ) + V_2 -> V_64 + V_96 ;
V_64 = F_110 ( V_133 + sizeof( T_6 ) , sizeof( V_136 ) ) ;
V_64 -= sizeof( T_6 ) ;
V_93 = F_111 ( V_64 , V_30 -> V_17 . type , V_84 , & V_134 ) ;
if ( ! V_93 )
return;
V_93 -> V_102 = ( unsigned long ) V_2 -> V_3 . V_6 . V_18 ;
memset ( & V_93 [ 1 ] , 0 , V_96 ) ;
F_77 ( sizeof( * V_93 ) , V_2 , V_84 , ( T_7 * ) & V_93 [ 1 ] , V_96 ) ;
F_112 ( V_93 , V_64 , V_134 , 0 , 1 , V_84 , V_132 , NULL ) ;
}
static T_1 void
F_113 ( struct V_1 * V_2 , struct V_103 * V_104 ,
struct V_83 * V_84 )
{
struct V_99 * V_30 = & V_2 -> V_30 ;
struct V_105 * V_93 ;
struct V_131 * V_132 ;
int V_64 , V_133 , V_96 ;
int V_134 ;
V_132 = F_108 ( V_30 -> V_135 ) ;
if ( F_109 ( V_132 ) )
return;
V_96 = F_74 ( V_2 , V_84 ) ;
V_133 = sizeof( * V_93 ) + V_2 -> V_64 + V_96 ;
V_64 = F_110 ( V_133 + sizeof( T_6 ) , sizeof( V_136 ) ) ;
V_64 -= sizeof( T_6 ) ;
V_93 = F_111 ( V_64 , V_30 -> V_17 . type , V_84 , & V_134 ) ;
if ( ! V_93 )
return;
V_93 -> V_106 = ( unsigned long ) V_2 -> V_3 . V_6 . V_18 ;
V_93 -> V_107 = ( unsigned long ) V_104 -> V_108 ;
F_77 ( sizeof( * V_93 ) , V_2 , V_84 , ( T_7 * ) & V_93 [ 1 ] , V_96 ) ;
F_112 ( V_93 , V_64 , V_134 , 0 , 1 , V_84 , V_132 , NULL ) ;
}
static T_1
int F_114 ( struct V_99 * V_17 ,
enum V_137 type , void * V_53 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_53 ;
struct V_36 * V_37 = V_53 ;
switch ( type ) {
case V_138 :
return F_22 ( V_2 , V_37 ) ;
case V_139 :
return F_28 ( V_2 , V_37 ) ;
#ifdef F_115
case V_140 :
return F_22 ( V_2 , NULL ) ;
case V_141 :
return F_28 ( V_2 , NULL ) ;
case V_142 :
case V_143 :
case V_144 :
case V_145 :
return 0 ;
#endif
}
return 0 ;
}
static T_1
int V_28 ( struct V_146 * V_6 , struct V_83 * V_84 )
{
struct V_1 * V_2 = F_95 ( V_6 , struct V_1 , V_3 . V_6 ) ;
V_2 -> V_80 ++ ;
if ( V_2 -> V_8 & V_9 )
F_90 ( V_2 , V_84 ) ;
#ifdef F_115
if ( V_2 -> V_8 & V_10 )
F_107 ( V_2 , V_84 ) ;
#endif
return 0 ;
}
static T_1
int V_26 ( struct V_103 * V_104 , struct V_83 * V_84 )
{
struct V_1 * V_2 = F_95 ( V_104 -> V_3 , struct V_1 , V_3 ) ;
V_2 -> V_80 ++ ;
if ( V_2 -> V_8 & V_9 )
F_93 ( V_2 , V_104 , V_84 ) ;
#ifdef F_115
if ( V_2 -> V_8 & V_10 )
F_113 ( V_2 , V_104 , V_84 ) ;
#endif
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_99 * V_30 = & V_2 -> V_30 ;
int V_22 ;
F_16 ( & V_30 -> V_31 -> V_147 ) ;
if ( F_1 ( V_2 ) ) {
V_30 -> V_17 . V_148 = & V_149 ;
V_30 -> V_31 -> V_150 = F_103 ;
} else {
V_30 -> V_17 . V_148 = & V_151 ;
V_30 -> V_31 -> V_150 = F_100 ;
}
if ( F_106 ( V_2 ) < 0 )
return - V_23 ;
V_22 = F_116 ( & V_30 -> V_17 ) ;
if ( ! V_22 ) {
F_17 ( V_30 -> V_130 ) ;
return - V_152 ;
}
V_30 -> V_8 = 0 ;
V_30 -> V_31 -> V_153 = F_114 ;
V_30 -> V_53 = V_2 ;
V_22 = F_117 ( V_30 ) ;
if ( V_22 ) {
F_52 ( L_50 , V_30 -> V_15 ) ;
F_17 ( V_30 -> V_130 ) ;
F_118 ( & V_30 -> V_17 ) ;
}
return V_22 ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_22 ;
V_22 = F_119 ( & V_2 -> V_30 ) ;
if ( ! V_22 )
F_17 ( V_2 -> V_30 . V_130 ) ;
return V_22 ;
}
static T_8 int F_120 ( void )
{
struct V_154 * V_155 ;
struct V_154 * V_93 ;
if ( F_121 ( & V_156 ) )
return - V_29 ;
V_155 = F_122 () ;
if ( ! V_155 )
return 0 ;
V_93 = F_123 ( L_51 , 0644 , V_155 ,
NULL , & V_157 ) ;
if ( ! V_93 )
F_38 ( L_52
L_53 ) ;
V_93 = F_123 ( L_54 , 0444 , V_155 ,
NULL , & V_158 ) ;
if ( ! V_93 )
F_38 ( L_52
L_55 ) ;
return 0 ;
}
static T_9 int F_124 ( int V_159 , int V_160 , int V_161 ,
int V_162 , int V_163 , int V_164 )
{
return V_159 + V_160 + V_161 + V_162 + V_163 + V_164 ;
}
static struct V_36 *
F_125 ( struct V_1 * V_2 , struct V_165 * V_166 )
{
struct V_36 * V_37 ;
F_21 (file, &tr->events, list)
if ( V_37 -> V_100 == & V_2 -> V_30 )
return V_37 ;
return NULL ;
}
static T_8 int F_126 ( void )
{
int V_22 , V_167 = 0 ;
int (* F_127)( int , int , int , int , int , int );
struct V_1 * V_2 ;
struct V_36 * V_37 ;
F_127 = F_124 ;
F_52 ( L_56 ) ;
V_22 = F_128 ( L_57
L_58 ,
F_51 ) ;
if ( F_129 ( V_22 ) ) {
F_130 ( L_59 ) ;
V_167 ++ ;
} else {
V_2 = F_20 ( L_60 , V_62 ) ;
if ( F_129 ( V_2 == NULL ) ) {
F_130 ( L_61 ) ;
V_167 ++ ;
} else {
V_37 = F_125 ( V_2 , F_131 () ) ;
if ( F_129 ( V_37 == NULL ) ) {
F_130 ( L_62 ) ;
V_167 ++ ;
} else
F_22 ( V_2 , V_37 ) ;
}
}
V_22 = F_128 ( L_63
L_64 , F_51 ) ;
if ( F_129 ( V_22 ) ) {
F_130 ( L_65 ) ;
V_167 ++ ;
} else {
V_2 = F_20 ( L_66 , V_62 ) ;
if ( F_129 ( V_2 == NULL ) ) {
F_130 ( L_67 ) ;
V_167 ++ ;
} else {
V_37 = F_125 ( V_2 , F_131 () ) ;
if ( F_129 ( V_37 == NULL ) ) {
F_130 ( L_62 ) ;
V_167 ++ ;
} else
F_22 ( V_2 , V_37 ) ;
}
}
if ( V_167 )
goto V_48;
V_22 = F_127 ( 1 , 2 , 3 , 4 , 5 , 6 ) ;
V_2 = F_20 ( L_60 , V_62 ) ;
if ( F_129 ( V_2 == NULL ) ) {
F_130 ( L_68 ) ;
V_167 ++ ;
} else {
V_37 = F_125 ( V_2 , F_131 () ) ;
if ( F_129 ( V_37 == NULL ) ) {
F_130 ( L_62 ) ;
V_167 ++ ;
} else
F_28 ( V_2 , V_37 ) ;
}
V_2 = F_20 ( L_66 , V_62 ) ;
if ( F_129 ( V_2 == NULL ) ) {
F_130 ( L_69 ) ;
V_167 ++ ;
} else {
V_37 = F_125 ( V_2 , F_131 () ) ;
if ( F_129 ( V_37 == NULL ) ) {
F_130 ( L_62 ) ;
V_167 ++ ;
} else
F_28 ( V_2 , V_37 ) ;
}
V_22 = F_128 ( L_70 , F_51 ) ;
if ( F_129 ( V_22 ) ) {
F_130 ( L_71 ) ;
V_167 ++ ;
}
V_22 = F_128 ( L_72 , F_51 ) ;
if ( F_129 ( V_22 ) ) {
F_130 ( L_71 ) ;
V_167 ++ ;
}
V_48:
F_59 () ;
if ( V_167 )
F_132 ( L_73 ) ;
else
F_132 ( L_74 ) ;
return 0 ;
}
