static T_1 int F_1 ( struct V_1 * V_2 )
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
return V_2 ;
error:
F_17 ( V_2 -> V_30 . V_15 ) ;
F_17 ( V_2 -> V_5 ) ;
F_17 ( V_2 ) ;
return F_13 ( V_22 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_34 ; V_33 ++ )
F_19 ( & V_2 -> args [ V_33 ] ) ;
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
static int F_22 ( struct V_1 * V_2 , int V_35 )
{
int V_22 = 0 ;
V_2 -> V_8 |= V_35 ;
if ( F_4 ( V_2 ) && F_5 ( V_2 ) &&
! F_6 ( V_2 ) ) {
if ( F_1 ( V_2 ) )
V_22 = F_23 ( & V_2 -> V_3 ) ;
else
V_22 = F_24 ( & V_2 -> V_3 . V_6 ) ;
}
return V_22 ;
}
static void F_25 ( struct V_1 * V_2 , int V_35 )
{
V_2 -> V_8 &= ~ V_35 ;
if ( ! F_4 ( V_2 ) && F_5 ( V_2 ) ) {
if ( F_1 ( V_2 ) )
F_26 ( & V_2 -> V_3 ) ;
else
F_27 ( & V_2 -> V_3 . V_6 ) ;
}
}
static int F_28 ( struct V_1 * V_2 )
{
int V_33 , V_22 ;
if ( F_5 ( V_2 ) )
return - V_29 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_34 ; V_33 ++ )
F_29 ( & V_2 -> args [ V_33 ] ) ;
if ( F_4 ( V_2 ) )
V_2 -> V_3 . V_6 . V_8 &= ~ V_36 ;
else
V_2 -> V_3 . V_6 . V_8 |= V_36 ;
if ( F_1 ( V_2 ) )
V_22 = F_30 ( & V_2 -> V_3 ) ;
else
V_22 = F_31 ( & V_2 -> V_3 . V_6 ) ;
if ( V_22 == 0 )
V_2 -> V_8 |= V_11 ;
else {
F_32 ( L_2 ,
F_2 ( V_2 ) , F_3 ( V_2 ) , V_22 ) ;
if ( V_22 == - V_37 && F_9 ( V_2 ) ) {
F_32 ( L_3
L_4 ) ;
V_22 = 0 ;
} else if ( V_22 == - V_38 ) {
F_32 ( L_5
L_6 ,
V_2 -> V_3 . V_6 . V_18 ) ;
V_22 = - V_29 ;
}
}
return V_22 ;
}
static void F_33 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 ) ) {
if ( F_1 ( V_2 ) )
F_34 ( & V_2 -> V_3 ) ;
else
F_35 ( & V_2 -> V_3 . V_6 ) ;
V_2 -> V_8 &= ~ V_11 ;
if ( V_2 -> V_3 . V_6 . V_25 )
V_2 -> V_3 . V_6 . V_18 = NULL ;
}
}
static int F_36 ( struct V_1 * V_2 )
{
if ( F_4 ( V_2 ) )
return - V_39 ;
F_33 ( V_2 ) ;
F_37 ( & V_2 -> V_32 ) ;
F_38 ( V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_1 * V_40 ;
int V_22 ;
F_40 ( & V_41 ) ;
V_40 = F_20 ( V_2 -> V_30 . V_15 , V_2 -> V_30 . V_31 -> system ) ;
if ( V_40 ) {
V_22 = F_36 ( V_40 ) ;
if ( V_22 < 0 )
goto V_42;
F_18 ( V_40 ) ;
}
V_22 = F_41 ( V_2 ) ;
if ( V_22 ) {
F_32 ( L_7 , V_22 ) ;
goto V_42;
}
V_22 = F_28 ( V_2 ) ;
if ( V_22 < 0 )
F_38 ( V_2 ) ;
else
F_42 ( & V_2 -> V_32 , & V_43 ) ;
V_42:
F_43 ( & V_41 ) ;
return V_22 ;
}
static int F_44 ( struct V_44 * V_45 ,
unsigned long V_46 , void * V_47 )
{
struct V_12 * V_13 = V_47 ;
struct V_1 * V_2 ;
int V_22 ;
if ( V_46 != V_48 )
return V_49 ;
F_40 ( & V_41 ) ;
F_21 (tp, &probe_list, list) {
if ( F_8 ( V_2 , V_13 ) ) {
F_33 ( V_2 ) ;
V_22 = F_28 ( V_2 ) ;
if ( V_22 )
F_32 ( L_8
L_9 ,
V_2 -> V_30 . V_15 , V_13 -> V_15 , V_22 ) ;
}
}
F_43 ( & V_41 ) ;
return V_49 ;
}
static int F_45 ( int V_50 , char * * V_51 )
{
struct V_1 * V_2 ;
int V_33 , V_22 = 0 ;
bool V_21 = false , V_52 = false ;
char * V_5 = NULL , * V_17 = NULL , * V_16 = NULL ;
char * V_53 ;
unsigned long V_7 = 0 ;
void * V_18 = NULL ;
char V_54 [ V_55 ] ;
if ( V_51 [ 0 ] [ 0 ] == 'p' )
V_21 = false ;
else if ( V_51 [ 0 ] [ 0 ] == 'r' )
V_21 = true ;
else if ( V_51 [ 0 ] [ 0 ] == '-' )
V_52 = true ;
else {
F_46 ( L_10
L_11 ) ;
return - V_29 ;
}
if ( V_51 [ 0 ] [ 1 ] == ':' ) {
V_17 = & V_51 [ 0 ] [ 2 ] ;
if ( strchr ( V_17 , '/' ) ) {
V_16 = V_17 ;
V_17 = strchr ( V_16 , '/' ) + 1 ;
V_17 [ - 1 ] = '\0' ;
if ( strlen ( V_16 ) == 0 ) {
F_46 ( L_12 ) ;
return - V_29 ;
}
}
if ( strlen ( V_17 ) == 0 ) {
F_46 ( L_13 ) ;
return - V_29 ;
}
}
if ( ! V_16 )
V_16 = V_56 ;
if ( V_52 ) {
if ( ! V_17 ) {
F_46 ( L_14 ) ;
return - V_29 ;
}
F_40 ( & V_41 ) ;
V_2 = F_20 ( V_17 , V_16 ) ;
if ( ! V_2 ) {
F_43 ( & V_41 ) ;
F_46 ( L_15 , V_16 , V_17 ) ;
return - V_37 ;
}
V_22 = F_36 ( V_2 ) ;
if ( V_22 == 0 )
F_18 ( V_2 ) ;
F_43 ( & V_41 ) ;
return V_22 ;
}
if ( V_50 < 2 ) {
F_46 ( L_16 ) ;
return - V_29 ;
}
if ( isdigit ( V_51 [ 1 ] [ 0 ] ) ) {
if ( V_21 ) {
F_46 ( L_17 ) ;
return - V_29 ;
}
V_22 = F_47 ( & V_51 [ 1 ] [ 0 ] , 0 , ( unsigned long * ) & V_18 ) ;
if ( V_22 ) {
F_46 ( L_18 ) ;
return V_22 ;
}
} else {
V_5 = V_51 [ 1 ] ;
V_22 = F_48 ( V_5 , & V_7 ) ;
if ( V_22 ) {
F_46 ( L_19 ) ;
return V_22 ;
}
if ( V_7 && V_21 ) {
F_46 ( L_20 ) ;
return - V_29 ;
}
}
V_50 -= 2 ; V_51 += 2 ;
if ( ! V_17 ) {
if ( V_5 )
snprintf ( V_54 , V_55 , L_21 ,
V_21 ? 'r' : 'p' , V_5 , V_7 ) ;
else
snprintf ( V_54 , V_55 , L_22 ,
V_21 ? 'r' : 'p' , V_18 ) ;
V_17 = V_54 ;
}
V_2 = F_10 ( V_16 , V_17 , V_18 , V_5 , V_7 , V_50 ,
V_21 ) ;
if ( F_49 ( V_2 ) ) {
F_46 ( L_23 ,
( int ) F_50 ( V_2 ) ) ;
return F_50 ( V_2 ) ;
}
V_22 = 0 ;
for ( V_33 = 0 ; V_33 < V_50 && V_33 < V_57 ; V_33 ++ ) {
V_2 -> V_34 ++ ;
V_53 = strchr ( V_51 [ V_33 ] , '=' ) ;
if ( V_53 ) {
* V_53 ++ = '\0' ;
V_2 -> args [ V_33 ] . V_15 = F_14 ( V_51 [ V_33 ] , V_24 ) ;
} else {
V_53 = V_51 [ V_33 ] ;
snprintf ( V_54 , V_55 , L_24 , V_33 + 1 ) ;
V_2 -> args [ V_33 ] . V_15 = F_14 ( V_54 , V_24 ) ;
}
if ( ! V_2 -> args [ V_33 ] . V_15 ) {
F_46 ( L_25 , V_33 ) ;
V_22 = - V_23 ;
goto error;
}
if ( ! F_15 ( V_2 -> args [ V_33 ] . V_15 ) ) {
F_46 ( L_26 ,
V_33 , V_2 -> args [ V_33 ] . V_15 ) ;
V_22 = - V_29 ;
goto error;
}
if ( F_51 ( V_2 -> args [ V_33 ] . V_15 ,
V_2 -> args , V_33 ) ) {
F_46 ( L_27
L_28 , V_33 , V_51 [ V_33 ] ) ;
V_22 = - V_29 ;
goto error;
}
V_22 = F_52 ( V_53 , & V_2 -> V_58 , & V_2 -> args [ V_33 ] ,
V_21 , true ) ;
if ( V_22 ) {
F_46 ( L_29 , V_33 , V_22 ) ;
goto error;
}
}
V_22 = F_39 ( V_2 ) ;
if ( V_22 )
goto error;
return 0 ;
error:
F_18 ( V_2 ) ;
return V_22 ;
}
static int F_53 ( void )
{
struct V_1 * V_2 ;
int V_22 = 0 ;
F_40 ( & V_41 ) ;
F_21 (tp, &probe_list, list)
if ( F_4 ( V_2 ) ) {
V_22 = - V_39 ;
goto V_42;
}
while ( ! F_54 ( & V_43 ) ) {
V_2 = F_55 ( V_43 . V_59 , struct V_1 , V_32 ) ;
F_36 ( V_2 ) ;
F_18 ( V_2 ) ;
}
V_42:
F_43 ( & V_41 ) ;
return V_22 ;
}
static void * F_56 ( struct V_60 * V_61 , T_2 * V_62 )
{
F_40 ( & V_41 ) ;
return F_57 ( & V_43 , * V_62 ) ;
}
static void * F_58 ( struct V_60 * V_61 , void * V_63 , T_2 * V_62 )
{
return F_59 ( V_63 , & V_43 , V_62 ) ;
}
static void F_60 ( struct V_60 * V_61 , void * V_63 )
{
F_43 ( & V_41 ) ;
}
static int F_61 ( struct V_60 * V_61 , void * V_63 )
{
struct V_1 * V_2 = V_63 ;
int V_33 ;
F_62 ( V_61 , L_30 , F_1 ( V_2 ) ? 'r' : 'p' ) ;
F_62 ( V_61 , L_31 , V_2 -> V_30 . V_31 -> system , V_2 -> V_30 . V_15 ) ;
if ( ! V_2 -> V_5 )
F_62 ( V_61 , L_32 , V_2 -> V_3 . V_6 . V_18 ) ;
else if ( V_2 -> V_3 . V_6 . V_7 )
F_62 ( V_61 , L_33 , F_2 ( V_2 ) ,
V_2 -> V_3 . V_6 . V_7 ) ;
else
F_62 ( V_61 , L_34 , F_2 ( V_2 ) ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_34 ; V_33 ++ )
F_62 ( V_61 , L_35 , V_2 -> args [ V_33 ] . V_15 , V_2 -> args [ V_33 ] . V_64 ) ;
F_62 ( V_61 , L_36 ) ;
return 0 ;
}
static int F_63 ( struct V_65 * V_65 , struct V_66 * V_66 )
{
int V_22 ;
if ( ( V_66 -> V_67 & V_68 ) && ( V_66 -> V_69 & V_70 ) ) {
V_22 = F_53 () ;
if ( V_22 < 0 )
return V_22 ;
}
return F_64 ( V_66 , & V_71 ) ;
}
static T_3 F_65 ( struct V_66 * V_66 , const char T_4 * V_72 ,
T_5 V_73 , T_2 * V_74 )
{
return F_66 ( V_66 , V_72 , V_73 , V_74 ,
F_45 ) ;
}
static int F_67 ( struct V_60 * V_61 , void * V_63 )
{
struct V_1 * V_2 = V_63 ;
F_62 ( V_61 , L_37 , V_2 -> V_30 . V_15 , V_2 -> V_75 ,
V_2 -> V_3 . V_6 . V_76 ) ;
return 0 ;
}
static int F_68 ( struct V_65 * V_65 , struct V_66 * V_66 )
{
return F_64 ( V_66 , & V_77 ) ;
}
static T_1 int F_69 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
int V_33 , V_22 = 0 ;
T_6 V_14 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_34 ; V_33 ++ )
if ( F_70 ( V_2 -> args [ V_33 ] . V_80 . V_81 ) ) {
F_71 ( & V_2 -> args [ V_33 ] . V_80 , V_79 , & V_14 ) ;
V_22 += V_14 ;
}
return V_22 ;
}
static T_1 void F_72 ( int V_82 , struct V_1 * V_2 ,
struct V_78 * V_79 ,
T_7 * V_47 , int V_83 )
{
int V_33 ;
T_6 V_42 = V_2 -> V_58 ;
T_6 * V_84 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_34 ; V_33 ++ ) {
if ( F_70 ( V_2 -> args [ V_33 ] . V_80 . V_81 ) ) {
V_84 = ( T_6 * ) ( V_47 + V_2 -> args [ V_33 ] . V_7 ) ;
* V_84 = F_73 ( V_83 , V_42 - V_2 -> args [ V_33 ] . V_7 ) ;
F_71 ( & V_2 -> args [ V_33 ] . V_85 , V_79 , V_84 ) ;
V_42 += F_74 ( * V_84 ) ;
V_83 -= F_74 ( * V_84 ) ;
* V_84 = F_75 ( * V_84 ,
V_82 + V_2 -> args [ V_33 ] . V_7 ) ;
} else
F_71 ( & V_2 -> args [ V_33 ] . V_85 , V_79 ,
V_47 + V_2 -> args [ V_33 ] . V_7 ) ;
}
}
static T_1 void F_76 ( struct V_86 * V_6 , struct V_78 * V_79 )
{
struct V_1 * V_2 = F_77 ( V_6 , struct V_1 , V_3 . V_6 ) ;
struct V_87 * V_88 ;
struct V_89 * V_17 ;
struct V_90 * V_72 ;
int V_58 , V_91 , V_92 ;
unsigned long V_93 ;
struct V_94 * V_30 = & V_2 -> V_30 ;
V_2 -> V_75 ++ ;
F_78 ( V_93 ) ;
V_92 = F_79 () ;
V_91 = F_69 ( V_2 , V_79 ) ;
V_58 = sizeof( * V_88 ) + V_2 -> V_58 + V_91 ;
V_17 = F_80 ( & V_72 , V_30 -> V_17 . type ,
V_58 , V_93 , V_92 ) ;
if ( ! V_17 )
return;
V_88 = F_81 ( V_17 ) ;
V_88 -> V_95 = ( unsigned long ) V_6 -> V_18 ;
F_72 ( sizeof( * V_88 ) , V_2 , V_79 , ( T_7 * ) & V_88 [ 1 ] , V_91 ) ;
if ( ! F_82 ( V_72 , V_30 , V_88 , V_17 ) )
F_83 ( V_72 , V_17 ,
V_93 , V_92 , V_79 ) ;
}
static T_1 void F_84 ( struct V_96 * V_97 ,
struct V_78 * V_79 )
{
struct V_1 * V_2 = F_77 ( V_97 -> V_3 , struct V_1 , V_3 ) ;
struct V_98 * V_88 ;
struct V_89 * V_17 ;
struct V_90 * V_72 ;
int V_58 , V_92 , V_91 ;
unsigned long V_93 ;
struct V_94 * V_30 = & V_2 -> V_30 ;
F_78 ( V_93 ) ;
V_92 = F_79 () ;
V_91 = F_69 ( V_2 , V_79 ) ;
V_58 = sizeof( * V_88 ) + V_2 -> V_58 + V_91 ;
V_17 = F_80 ( & V_72 , V_30 -> V_17 . type ,
V_58 , V_93 , V_92 ) ;
if ( ! V_17 )
return;
V_88 = F_81 ( V_17 ) ;
V_88 -> V_99 = ( unsigned long ) V_2 -> V_3 . V_6 . V_18 ;
V_88 -> V_100 = ( unsigned long ) V_97 -> V_101 ;
F_72 ( sizeof( * V_88 ) , V_2 , V_79 , ( T_7 * ) & V_88 [ 1 ] , V_91 ) ;
if ( ! F_82 ( V_72 , V_30 , V_88 , V_17 ) )
F_83 ( V_72 , V_17 ,
V_93 , V_92 , V_79 ) ;
}
enum V_102
F_85 ( struct V_103 * V_104 , int V_8 ,
struct V_105 * V_17 )
{
struct V_87 * V_106 ;
struct V_107 * V_108 = & V_104 -> V_109 ;
struct V_1 * V_2 ;
T_7 * V_47 ;
int V_33 ;
V_106 = (struct V_87 * ) V_104 -> V_110 ;
V_2 = F_77 ( V_17 , struct V_1 , V_30 . V_17 ) ;
if ( ! F_86 ( V_108 , L_38 , V_2 -> V_30 . V_15 ) )
goto V_111;
if ( ! F_87 ( V_108 , V_106 -> V_95 , V_8 | V_112 ) )
goto V_111;
if ( ! F_88 ( V_108 , L_39 ) )
goto V_111;
V_47 = ( T_7 * ) & V_106 [ 1 ] ;
for ( V_33 = 0 ; V_33 < V_2 -> V_34 ; V_33 ++ )
if ( ! V_2 -> args [ V_33 ] . type -> V_113 ( V_108 , V_2 -> args [ V_33 ] . V_15 ,
V_47 + V_2 -> args [ V_33 ] . V_7 , V_106 ) )
goto V_111;
if ( ! F_88 ( V_108 , L_36 ) )
goto V_111;
return V_114 ;
V_111:
return V_115 ;
}
enum V_102
F_89 ( struct V_103 * V_104 , int V_8 ,
struct V_105 * V_17 )
{
struct V_98 * V_106 ;
struct V_107 * V_108 = & V_104 -> V_109 ;
struct V_1 * V_2 ;
T_7 * V_47 ;
int V_33 ;
V_106 = (struct V_98 * ) V_104 -> V_110 ;
V_2 = F_77 ( V_17 , struct V_1 , V_30 . V_17 ) ;
if ( ! F_86 ( V_108 , L_38 , V_2 -> V_30 . V_15 ) )
goto V_111;
if ( ! F_87 ( V_108 , V_106 -> V_100 , V_8 | V_112 ) )
goto V_111;
if ( ! F_88 ( V_108 , L_40 ) )
goto V_111;
if ( ! F_87 ( V_108 , V_106 -> V_99 , V_8 & ~ V_112 ) )
goto V_111;
if ( ! F_88 ( V_108 , L_39 ) )
goto V_111;
V_47 = ( T_7 * ) & V_106 [ 1 ] ;
for ( V_33 = 0 ; V_33 < V_2 -> V_34 ; V_33 ++ )
if ( ! V_2 -> args [ V_33 ] . type -> V_113 ( V_108 , V_2 -> args [ V_33 ] . V_15 ,
V_47 + V_2 -> args [ V_33 ] . V_7 , V_106 ) )
goto V_111;
if ( ! F_88 ( V_108 , L_36 ) )
goto V_111;
return V_114 ;
V_111:
return V_115 ;
}
static int F_90 ( struct V_94 * V_116 )
{
int V_22 , V_33 ;
struct V_87 V_106 ;
struct V_1 * V_2 = (struct V_1 * ) V_116 -> V_47 ;
F_91 (unsigned long, ip, FIELD_STRING_IP, 0 ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_34 ; V_33 ++ ) {
V_22 = F_92 ( V_116 , V_2 -> args [ V_33 ] . type -> V_117 ,
V_2 -> args [ V_33 ] . V_15 ,
sizeof( V_106 ) + V_2 -> args [ V_33 ] . V_7 ,
V_2 -> args [ V_33 ] . type -> V_58 ,
V_2 -> args [ V_33 ] . type -> V_118 ,
V_119 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static int F_93 ( struct V_94 * V_116 )
{
int V_22 , V_33 ;
struct V_98 V_106 ;
struct V_1 * V_2 = (struct V_1 * ) V_116 -> V_47 ;
F_91 (unsigned long, func, FIELD_STRING_FUNC, 0 ) ;
F_91 (unsigned long, ret_ip, FIELD_STRING_RETIP, 0 ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_34 ; V_33 ++ ) {
V_22 = F_92 ( V_116 , V_2 -> args [ V_33 ] . type -> V_117 ,
V_2 -> args [ V_33 ] . V_15 ,
sizeof( V_106 ) + V_2 -> args [ V_33 ] . V_7 ,
V_2 -> args [ V_33 ] . type -> V_58 ,
V_2 -> args [ V_33 ] . type -> V_118 ,
V_119 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static int F_94 ( struct V_1 * V_2 , char * V_54 , int V_14 )
{
int V_33 ;
int V_62 = 0 ;
const char * V_120 , * V_53 ;
if ( ! F_1 ( V_2 ) ) {
V_120 = L_41 ;
V_53 = L_42 V_121 ;
} else {
V_120 = L_43 ;
V_53 = L_42 V_122 L_44 V_123 ;
}
#define F_95 (len ? len - pos : 0)
V_62 += snprintf ( V_54 + V_62 , F_95 , L_45 , V_120 ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_34 ; V_33 ++ ) {
V_62 += snprintf ( V_54 + V_62 , F_95 , L_35 ,
V_2 -> args [ V_33 ] . V_15 , V_2 -> args [ V_33 ] . type -> V_120 ) ;
}
V_62 += snprintf ( V_54 + V_62 , F_95 , L_46 , V_53 ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_34 ; V_33 ++ ) {
if ( strcmp ( V_2 -> args [ V_33 ] . type -> V_15 , L_47 ) == 0 )
V_62 += snprintf ( V_54 + V_62 , F_95 ,
L_48 ,
V_2 -> args [ V_33 ] . V_15 ) ;
else
V_62 += snprintf ( V_54 + V_62 , F_95 , L_49 ,
V_2 -> args [ V_33 ] . V_15 ) ;
}
#undef F_95
return V_62 ;
}
static int F_96 ( struct V_1 * V_2 )
{
int V_14 ;
char * V_124 ;
V_14 = F_94 ( V_2 , NULL , 0 ) ;
V_124 = F_97 ( V_14 + 1 , V_24 ) ;
if ( ! V_124 )
return - V_23 ;
F_94 ( V_2 , V_124 , V_14 + 1 ) ;
V_2 -> V_30 . V_124 = V_124 ;
return 0 ;
}
static T_1 void F_98 ( struct V_86 * V_6 ,
struct V_78 * V_79 )
{
struct V_1 * V_2 = F_77 ( V_6 , struct V_1 , V_3 . V_6 ) ;
struct V_94 * V_30 = & V_2 -> V_30 ;
struct V_87 * V_88 ;
struct V_125 * V_126 ;
int V_58 , V_127 , V_91 ;
int V_128 ;
V_91 = F_69 ( V_2 , V_79 ) ;
V_127 = sizeof( * V_88 ) + V_2 -> V_58 + V_91 ;
V_58 = F_99 ( V_127 + sizeof( T_6 ) , sizeof( V_129 ) ) ;
V_58 -= sizeof( T_6 ) ;
if ( F_100 ( V_58 > V_130 ,
L_50 ) )
return;
V_88 = F_101 ( V_58 , V_30 -> V_17 . type , V_79 , & V_128 ) ;
if ( ! V_88 )
return;
V_88 -> V_95 = ( unsigned long ) V_6 -> V_18 ;
memset ( & V_88 [ 1 ] , 0 , V_91 ) ;
F_72 ( sizeof( * V_88 ) , V_2 , V_79 , ( T_7 * ) & V_88 [ 1 ] , V_91 ) ;
V_126 = F_102 ( V_30 -> V_131 ) ;
F_103 ( V_88 , V_58 , V_128 ,
V_88 -> V_95 , 1 , V_79 , V_126 , NULL ) ;
}
static T_1 void F_104 ( struct V_96 * V_97 ,
struct V_78 * V_79 )
{
struct V_1 * V_2 = F_77 ( V_97 -> V_3 , struct V_1 , V_3 ) ;
struct V_94 * V_30 = & V_2 -> V_30 ;
struct V_98 * V_88 ;
struct V_125 * V_126 ;
int V_58 , V_127 , V_91 ;
int V_128 ;
V_91 = F_69 ( V_2 , V_79 ) ;
V_127 = sizeof( * V_88 ) + V_2 -> V_58 + V_91 ;
V_58 = F_99 ( V_127 + sizeof( T_6 ) , sizeof( V_129 ) ) ;
V_58 -= sizeof( T_6 ) ;
if ( F_100 ( V_58 > V_130 ,
L_50 ) )
return;
V_88 = F_101 ( V_58 , V_30 -> V_17 . type , V_79 , & V_128 ) ;
if ( ! V_88 )
return;
V_88 -> V_99 = ( unsigned long ) V_2 -> V_3 . V_6 . V_18 ;
V_88 -> V_100 = ( unsigned long ) V_97 -> V_101 ;
F_72 ( sizeof( * V_88 ) , V_2 , V_79 , ( T_7 * ) & V_88 [ 1 ] , V_91 ) ;
V_126 = F_102 ( V_30 -> V_131 ) ;
F_103 ( V_88 , V_58 , V_128 ,
V_88 -> V_100 , 1 , V_79 , V_126 , NULL ) ;
}
static T_1
int F_105 ( struct V_94 * V_17 ,
enum V_132 type , void * V_47 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_47 ;
switch ( type ) {
case V_133 :
return F_22 ( V_2 , V_9 ) ;
case V_134 :
F_25 ( V_2 , V_9 ) ;
return 0 ;
#ifdef F_106
case V_135 :
return F_22 ( V_2 , V_10 ) ;
case V_136 :
F_25 ( V_2 , V_10 ) ;
return 0 ;
case V_137 :
case V_138 :
case V_139 :
case V_140 :
return 0 ;
#endif
}
return 0 ;
}
static T_1
int V_28 ( struct V_86 * V_6 , struct V_78 * V_79 )
{
struct V_1 * V_2 = F_77 ( V_6 , struct V_1 , V_3 . V_6 ) ;
if ( V_2 -> V_8 & V_9 )
F_76 ( V_6 , V_79 ) ;
#ifdef F_106
if ( V_2 -> V_8 & V_10 )
F_98 ( V_6 , V_79 ) ;
#endif
return 0 ;
}
static T_1
int V_26 ( struct V_96 * V_97 , struct V_78 * V_79 )
{
struct V_1 * V_2 = F_77 ( V_97 -> V_3 , struct V_1 , V_3 ) ;
if ( V_2 -> V_8 & V_9 )
F_84 ( V_97 , V_79 ) ;
#ifdef F_106
if ( V_2 -> V_8 & V_10 )
F_104 ( V_97 , V_79 ) ;
#endif
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_94 * V_30 = & V_2 -> V_30 ;
int V_22 ;
F_16 ( & V_30 -> V_31 -> V_141 ) ;
if ( F_1 ( V_2 ) ) {
V_30 -> V_17 . V_142 = & V_143 ;
V_30 -> V_31 -> V_144 = F_93 ;
} else {
V_30 -> V_17 . V_142 = & V_145 ;
V_30 -> V_31 -> V_144 = F_90 ;
}
if ( F_96 ( V_2 ) < 0 )
return - V_23 ;
V_22 = F_107 ( & V_30 -> V_17 ) ;
if ( ! V_22 ) {
F_17 ( V_30 -> V_124 ) ;
return - V_146 ;
}
V_30 -> V_8 = 0 ;
V_30 -> V_31 -> V_147 = F_105 ;
V_30 -> V_47 = V_2 ;
V_22 = F_108 ( V_30 ) ;
if ( V_22 ) {
F_46 ( L_51 , V_30 -> V_15 ) ;
F_17 ( V_30 -> V_124 ) ;
F_109 ( & V_30 -> V_17 ) ;
}
return V_22 ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_110 ( & V_2 -> V_30 ) ;
F_17 ( V_2 -> V_30 . V_124 ) ;
}
static T_8 int F_111 ( void )
{
struct V_148 * V_149 ;
struct V_148 * V_88 ;
if ( F_112 ( & V_150 ) )
return - V_29 ;
V_149 = F_113 () ;
if ( ! V_149 )
return 0 ;
V_88 = F_114 ( L_52 , 0644 , V_149 ,
NULL , & V_151 ) ;
if ( ! V_88 )
F_32 ( L_53
L_54 ) ;
V_88 = F_114 ( L_55 , 0444 , V_149 ,
NULL , & V_152 ) ;
if ( ! V_88 )
F_32 ( L_53
L_56 ) ;
return 0 ;
}
static T_9 int F_115 ( int V_153 , int V_154 , int V_155 ,
int V_156 , int V_157 , int V_158 )
{
return V_153 + V_154 + V_155 + V_156 + V_157 + V_158 ;
}
static T_8 int F_116 ( void )
{
int V_22 , V_159 = 0 ;
int (* F_117)( int , int , int , int , int , int );
struct V_1 * V_2 ;
F_117 = F_115 ;
F_46 ( L_57 ) ;
V_22 = F_118 ( L_58
L_59 ,
F_45 ) ;
if ( F_119 ( V_22 ) ) {
F_32 ( L_60 ) ;
V_159 ++ ;
} else {
V_2 = F_20 ( L_61 , V_56 ) ;
if ( F_119 ( V_2 == NULL ) ) {
F_32 ( L_62 ) ;
V_159 ++ ;
} else
F_22 ( V_2 , V_9 ) ;
}
V_22 = F_118 ( L_63
L_64 , F_45 ) ;
if ( F_119 ( V_22 ) ) {
F_32 ( L_65 ) ;
V_159 ++ ;
} else {
V_2 = F_20 ( L_66 , V_56 ) ;
if ( F_119 ( V_2 == NULL ) ) {
F_32 ( L_62 ) ;
V_159 ++ ;
} else
F_22 ( V_2 , V_9 ) ;
}
if ( V_159 )
goto V_42;
V_22 = F_117 ( 1 , 2 , 3 , 4 , 5 , 6 ) ;
V_2 = F_20 ( L_61 , V_56 ) ;
if ( F_119 ( V_2 == NULL ) ) {
F_32 ( L_67 ) ;
V_159 ++ ;
} else
F_25 ( V_2 , V_9 ) ;
V_2 = F_20 ( L_66 , V_56 ) ;
if ( F_119 ( V_2 == NULL ) ) {
F_32 ( L_68 ) ;
V_159 ++ ;
} else
F_25 ( V_2 , V_9 ) ;
V_22 = F_118 ( L_69 , F_45 ) ;
if ( F_119 ( V_22 ) ) {
F_32 ( L_70 ) ;
V_159 ++ ;
}
V_22 = F_118 ( L_71 , F_45 ) ;
if ( F_119 ( V_22 ) ) {
F_32 ( L_70 ) ;
V_159 ++ ;
}
V_42:
F_53 () ;
if ( V_159 )
F_120 ( L_72 ) ;
else
F_120 ( L_73 ) ;
return 0 ;
}
