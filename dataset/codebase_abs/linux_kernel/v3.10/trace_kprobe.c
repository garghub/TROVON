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
static int F_22 ( struct V_1 * V_2 )
{
struct V_35 * * V_36 ;
int V_22 = 0 ;
V_36 = F_23 ( V_2 -> V_37 ) ;
if ( V_36 )
while ( * ( V_36 ++ ) )
V_22 ++ ;
return V_22 ;
}
static int
F_24 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
int V_22 = 0 ;
F_25 ( & V_38 ) ;
if ( V_36 ) {
struct V_35 * * V_39 , * * V_40 ;
int V_41 = F_22 ( V_2 ) ;
V_40 = F_23 ( V_2 -> V_37 ) ;
V_39 = F_11 ( ( V_41 + 2 ) * sizeof( struct V_35 * ) ,
V_24 ) ;
if ( ! V_39 ) {
V_22 = - V_23 ;
goto V_42;
}
memcpy ( V_39 , V_40 , V_41 * sizeof( struct V_35 * ) ) ;
V_39 [ V_41 ] = V_36 ;
F_26 ( V_2 -> V_37 , V_39 ) ;
V_2 -> V_8 |= V_9 ;
if ( V_40 ) {
F_27 () ;
F_17 ( V_40 ) ;
}
} else
V_2 -> V_8 |= V_10 ;
if ( F_4 ( V_2 ) && F_5 ( V_2 ) &&
! F_6 ( V_2 ) ) {
if ( F_1 ( V_2 ) )
V_22 = F_28 ( & V_2 -> V_3 ) ;
else
V_22 = F_29 ( & V_2 -> V_3 . V_6 ) ;
}
V_42:
F_30 ( & V_38 ) ;
return V_22 ;
}
static int
F_31 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_35 * * V_37 ;
int V_33 ;
V_37 = F_23 ( V_2 -> V_37 ) ;
if ( V_37 ) {
for ( V_33 = 0 ; V_37 [ V_33 ] ; V_33 ++ )
if ( V_37 [ V_33 ] == V_36 )
return V_33 ;
}
return - 1 ;
}
static int
F_32 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
int V_22 = 0 ;
F_25 ( & V_38 ) ;
if ( V_36 ) {
struct V_35 * * V_39 , * * V_40 ;
int V_41 = F_22 ( V_2 ) ;
int V_33 , V_43 ;
V_40 = F_23 ( V_2 -> V_37 ) ;
if ( V_41 == 0 || F_31 ( V_2 , V_36 ) < 0 ) {
V_22 = - V_29 ;
goto V_42;
}
if ( V_41 == 1 ) {
V_2 -> V_8 &= ~ V_9 ;
V_39 = NULL ;
} else {
V_39 = F_11 ( V_41 * sizeof( struct V_35 * ) ,
V_24 ) ;
if ( ! V_39 ) {
V_22 = - V_23 ;
goto V_42;
}
for ( V_33 = 0 , V_43 = 0 ; V_43 < V_41 && V_33 < V_41 + 1 ; V_33 ++ )
if ( V_40 [ V_33 ] != V_36 )
V_39 [ V_43 ++ ] = V_40 [ V_33 ] ;
}
F_26 ( V_2 -> V_37 , V_39 ) ;
F_27 () ;
F_17 ( V_40 ) ;
} else
V_2 -> V_8 &= ~ V_10 ;
if ( ! F_4 ( V_2 ) && F_5 ( V_2 ) ) {
if ( F_1 ( V_2 ) )
F_33 ( & V_2 -> V_3 ) ;
else
F_34 ( & V_2 -> V_3 . V_6 ) ;
}
V_42:
F_30 ( & V_38 ) ;
return V_22 ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_33 , V_22 ;
if ( F_5 ( V_2 ) )
return - V_29 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_34 ; V_33 ++ )
F_36 ( & V_2 -> args [ V_33 ] ) ;
if ( F_4 ( V_2 ) )
V_2 -> V_3 . V_6 . V_8 &= ~ V_44 ;
else
V_2 -> V_3 . V_6 . V_8 |= V_44 ;
if ( F_1 ( V_2 ) )
V_22 = F_37 ( & V_2 -> V_3 ) ;
else
V_22 = F_38 ( & V_2 -> V_3 . V_6 ) ;
if ( V_22 == 0 )
V_2 -> V_8 |= V_11 ;
else {
F_39 ( L_2 ,
F_2 ( V_2 ) , F_3 ( V_2 ) , V_22 ) ;
if ( V_22 == - V_45 && F_9 ( V_2 ) ) {
F_39 ( L_3
L_4 ) ;
V_22 = 0 ;
} else if ( V_22 == - V_46 ) {
F_39 ( L_5
L_6 ,
V_2 -> V_3 . V_6 . V_18 ) ;
V_22 = - V_29 ;
}
}
return V_22 ;
}
static void F_40 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 ) ) {
if ( F_1 ( V_2 ) )
F_41 ( & V_2 -> V_3 ) ;
else
F_42 ( & V_2 -> V_3 . V_6 ) ;
V_2 -> V_8 &= ~ V_11 ;
if ( V_2 -> V_3 . V_6 . V_25 )
V_2 -> V_3 . V_6 . V_18 = NULL ;
}
}
static int F_43 ( struct V_1 * V_2 )
{
if ( F_4 ( V_2 ) )
return - V_47 ;
F_40 ( V_2 ) ;
F_44 ( & V_2 -> V_32 ) ;
F_45 ( V_2 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_1 * V_48 ;
int V_22 ;
F_25 ( & V_49 ) ;
V_48 = F_20 ( V_2 -> V_30 . V_15 , V_2 -> V_30 . V_31 -> system ) ;
if ( V_48 ) {
V_22 = F_43 ( V_48 ) ;
if ( V_22 < 0 )
goto V_50;
F_18 ( V_48 ) ;
}
V_22 = F_47 ( V_2 ) ;
if ( V_22 ) {
F_39 ( L_7 , V_22 ) ;
goto V_50;
}
V_22 = F_35 ( V_2 ) ;
if ( V_22 < 0 )
F_45 ( V_2 ) ;
else
F_48 ( & V_2 -> V_32 , & V_51 ) ;
V_50:
F_30 ( & V_49 ) ;
return V_22 ;
}
static int F_49 ( struct V_52 * V_53 ,
unsigned long V_54 , void * V_55 )
{
struct V_12 * V_13 = V_55 ;
struct V_1 * V_2 ;
int V_22 ;
if ( V_54 != V_56 )
return V_57 ;
F_25 ( & V_49 ) ;
F_21 (tp, &probe_list, list) {
if ( F_8 ( V_2 , V_13 ) ) {
F_40 ( V_2 ) ;
V_22 = F_35 ( V_2 ) ;
if ( V_22 )
F_39 ( L_8
L_9 ,
V_2 -> V_30 . V_15 , V_13 -> V_15 , V_22 ) ;
}
}
F_30 ( & V_49 ) ;
return V_57 ;
}
static int F_50 ( int V_58 , char * * V_59 )
{
struct V_1 * V_2 ;
int V_33 , V_22 = 0 ;
bool V_21 = false , V_60 = false ;
char * V_5 = NULL , * V_17 = NULL , * V_16 = NULL ;
char * V_61 ;
unsigned long V_7 = 0 ;
void * V_18 = NULL ;
char V_62 [ V_63 ] ;
if ( V_59 [ 0 ] [ 0 ] == 'p' )
V_21 = false ;
else if ( V_59 [ 0 ] [ 0 ] == 'r' )
V_21 = true ;
else if ( V_59 [ 0 ] [ 0 ] == '-' )
V_60 = true ;
else {
F_51 ( L_10
L_11 ) ;
return - V_29 ;
}
if ( V_59 [ 0 ] [ 1 ] == ':' ) {
V_17 = & V_59 [ 0 ] [ 2 ] ;
if ( strchr ( V_17 , '/' ) ) {
V_16 = V_17 ;
V_17 = strchr ( V_16 , '/' ) + 1 ;
V_17 [ - 1 ] = '\0' ;
if ( strlen ( V_16 ) == 0 ) {
F_51 ( L_12 ) ;
return - V_29 ;
}
}
if ( strlen ( V_17 ) == 0 ) {
F_51 ( L_13 ) ;
return - V_29 ;
}
}
if ( ! V_16 )
V_16 = V_64 ;
if ( V_60 ) {
if ( ! V_17 ) {
F_51 ( L_14 ) ;
return - V_29 ;
}
F_25 ( & V_49 ) ;
V_2 = F_20 ( V_17 , V_16 ) ;
if ( ! V_2 ) {
F_30 ( & V_49 ) ;
F_51 ( L_15 , V_16 , V_17 ) ;
return - V_45 ;
}
V_22 = F_43 ( V_2 ) ;
if ( V_22 == 0 )
F_18 ( V_2 ) ;
F_30 ( & V_49 ) ;
return V_22 ;
}
if ( V_58 < 2 ) {
F_51 ( L_16 ) ;
return - V_29 ;
}
if ( isdigit ( V_59 [ 1 ] [ 0 ] ) ) {
if ( V_21 ) {
F_51 ( L_17 ) ;
return - V_29 ;
}
V_22 = F_52 ( & V_59 [ 1 ] [ 0 ] , 0 , ( unsigned long * ) & V_18 ) ;
if ( V_22 ) {
F_51 ( L_18 ) ;
return V_22 ;
}
} else {
V_5 = V_59 [ 1 ] ;
V_22 = F_53 ( V_5 , & V_7 ) ;
if ( V_22 ) {
F_51 ( L_19 ) ;
return V_22 ;
}
if ( V_7 && V_21 ) {
F_51 ( L_20 ) ;
return - V_29 ;
}
}
V_58 -= 2 ; V_59 += 2 ;
if ( ! V_17 ) {
if ( V_5 )
snprintf ( V_62 , V_63 , L_21 ,
V_21 ? 'r' : 'p' , V_5 , V_7 ) ;
else
snprintf ( V_62 , V_63 , L_22 ,
V_21 ? 'r' : 'p' , V_18 ) ;
V_17 = V_62 ;
}
V_2 = F_10 ( V_16 , V_17 , V_18 , V_5 , V_7 , V_58 ,
V_21 ) ;
if ( F_54 ( V_2 ) ) {
F_51 ( L_23 ,
( int ) F_55 ( V_2 ) ) ;
return F_55 ( V_2 ) ;
}
V_22 = 0 ;
for ( V_33 = 0 ; V_33 < V_58 && V_33 < V_65 ; V_33 ++ ) {
V_2 -> V_34 ++ ;
V_61 = strchr ( V_59 [ V_33 ] , '=' ) ;
if ( V_61 ) {
* V_61 ++ = '\0' ;
V_2 -> args [ V_33 ] . V_15 = F_14 ( V_59 [ V_33 ] , V_24 ) ;
} else {
V_61 = V_59 [ V_33 ] ;
snprintf ( V_62 , V_63 , L_24 , V_33 + 1 ) ;
V_2 -> args [ V_33 ] . V_15 = F_14 ( V_62 , V_24 ) ;
}
if ( ! V_2 -> args [ V_33 ] . V_15 ) {
F_51 ( L_25 , V_33 ) ;
V_22 = - V_23 ;
goto error;
}
if ( ! F_15 ( V_2 -> args [ V_33 ] . V_15 ) ) {
F_51 ( L_26 ,
V_33 , V_2 -> args [ V_33 ] . V_15 ) ;
V_22 = - V_29 ;
goto error;
}
if ( F_56 ( V_2 -> args [ V_33 ] . V_15 ,
V_2 -> args , V_33 ) ) {
F_51 ( L_27
L_28 , V_33 , V_59 [ V_33 ] ) ;
V_22 = - V_29 ;
goto error;
}
V_22 = F_57 ( V_61 , & V_2 -> V_66 , & V_2 -> args [ V_33 ] ,
V_21 , true ) ;
if ( V_22 ) {
F_51 ( L_29 , V_33 , V_22 ) ;
goto error;
}
}
V_22 = F_46 ( V_2 ) ;
if ( V_22 )
goto error;
return 0 ;
error:
F_18 ( V_2 ) ;
return V_22 ;
}
static int F_58 ( void )
{
struct V_1 * V_2 ;
int V_22 = 0 ;
F_25 ( & V_49 ) ;
F_21 (tp, &probe_list, list)
if ( F_4 ( V_2 ) ) {
V_22 = - V_47 ;
goto V_50;
}
while ( ! F_59 ( & V_51 ) ) {
V_2 = F_60 ( V_51 . V_67 , struct V_1 , V_32 ) ;
F_43 ( V_2 ) ;
F_18 ( V_2 ) ;
}
V_50:
F_30 ( & V_49 ) ;
return V_22 ;
}
static void * F_61 ( struct V_68 * V_69 , T_2 * V_70 )
{
F_25 ( & V_49 ) ;
return F_62 ( & V_51 , * V_70 ) ;
}
static void * F_63 ( struct V_68 * V_69 , void * V_71 , T_2 * V_70 )
{
return F_64 ( V_71 , & V_51 , V_70 ) ;
}
static void F_65 ( struct V_68 * V_69 , void * V_71 )
{
F_30 ( & V_49 ) ;
}
static int F_66 ( struct V_68 * V_69 , void * V_71 )
{
struct V_1 * V_2 = V_71 ;
int V_33 ;
F_67 ( V_69 , L_30 , F_1 ( V_2 ) ? 'r' : 'p' ) ;
F_67 ( V_69 , L_31 , V_2 -> V_30 . V_31 -> system , V_2 -> V_30 . V_15 ) ;
if ( ! V_2 -> V_5 )
F_67 ( V_69 , L_32 , V_2 -> V_3 . V_6 . V_18 ) ;
else if ( V_2 -> V_3 . V_6 . V_7 )
F_67 ( V_69 , L_33 , F_2 ( V_2 ) ,
V_2 -> V_3 . V_6 . V_7 ) ;
else
F_67 ( V_69 , L_34 , F_2 ( V_2 ) ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_34 ; V_33 ++ )
F_67 ( V_69 , L_35 , V_2 -> args [ V_33 ] . V_15 , V_2 -> args [ V_33 ] . V_72 ) ;
F_67 ( V_69 , L_36 ) ;
return 0 ;
}
static int F_68 ( struct V_73 * V_73 , struct V_36 * V_36 )
{
int V_22 ;
if ( ( V_36 -> V_74 & V_75 ) && ( V_36 -> V_76 & V_77 ) ) {
V_22 = F_58 () ;
if ( V_22 < 0 )
return V_22 ;
}
return F_69 ( V_36 , & V_78 ) ;
}
static T_3 F_70 ( struct V_36 * V_36 , const char T_4 * V_79 ,
T_5 V_80 , T_2 * V_81 )
{
return F_71 ( V_36 , V_79 , V_80 , V_81 ,
F_50 ) ;
}
static int F_72 ( struct V_68 * V_69 , void * V_71 )
{
struct V_1 * V_2 = V_71 ;
F_67 ( V_69 , L_37 , V_2 -> V_30 . V_15 , V_2 -> V_82 ,
V_2 -> V_3 . V_6 . V_83 ) ;
return 0 ;
}
static int F_73 ( struct V_73 * V_73 , struct V_36 * V_36 )
{
return F_69 ( V_36 , & V_84 ) ;
}
static T_1 int F_74 ( struct V_1 * V_2 ,
struct V_85 * V_86 )
{
int V_33 , V_22 = 0 ;
T_6 V_14 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_34 ; V_33 ++ )
if ( F_75 ( V_2 -> args [ V_33 ] . V_87 . V_88 ) ) {
F_76 ( & V_2 -> args [ V_33 ] . V_87 , V_86 , & V_14 ) ;
V_22 += V_14 ;
}
return V_22 ;
}
static T_1 void F_77 ( int V_89 , struct V_1 * V_2 ,
struct V_85 * V_86 ,
T_7 * V_55 , int V_90 )
{
int V_33 ;
T_6 V_50 = V_2 -> V_66 ;
T_6 * V_91 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_34 ; V_33 ++ ) {
if ( F_75 ( V_2 -> args [ V_33 ] . V_87 . V_88 ) ) {
V_91 = ( T_6 * ) ( V_55 + V_2 -> args [ V_33 ] . V_7 ) ;
* V_91 = F_78 ( V_90 , V_50 - V_2 -> args [ V_33 ] . V_7 ) ;
F_76 ( & V_2 -> args [ V_33 ] . V_92 , V_86 , V_91 ) ;
V_50 += F_79 ( * V_91 ) ;
V_90 -= F_79 ( * V_91 ) ;
* V_91 = F_80 ( * V_91 ,
V_89 + V_2 -> args [ V_33 ] . V_7 ) ;
} else
F_76 ( & V_2 -> args [ V_33 ] . V_92 , V_86 ,
V_55 + V_2 -> args [ V_33 ] . V_7 ) ;
}
}
static T_1 void
F_81 ( struct V_1 * V_2 , struct V_85 * V_86 ,
struct V_35 * V_93 )
{
struct V_94 * V_95 ;
struct V_96 * V_17 ;
struct V_97 * V_79 ;
int V_66 , V_98 , V_99 ;
unsigned long V_100 ;
struct V_101 * V_30 = & V_2 -> V_30 ;
F_82 ( V_30 != V_93 -> V_102 ) ;
if ( F_83 ( V_103 , & V_93 -> V_8 ) )
return;
F_84 ( V_100 ) ;
V_99 = F_85 () ;
V_98 = F_74 ( V_2 , V_86 ) ;
V_66 = sizeof( * V_95 ) + V_2 -> V_66 + V_98 ;
V_17 = F_86 ( & V_79 , V_93 ,
V_30 -> V_17 . type ,
V_66 , V_100 , V_99 ) ;
if ( ! V_17 )
return;
V_95 = F_87 ( V_17 ) ;
V_95 -> V_104 = ( unsigned long ) V_2 -> V_3 . V_6 . V_18 ;
F_77 ( sizeof( * V_95 ) , V_2 , V_86 , ( T_7 * ) & V_95 [ 1 ] , V_98 ) ;
if ( ! F_88 ( V_79 , V_30 , V_95 , V_17 ) )
F_89 ( V_79 , V_17 ,
V_100 , V_99 , V_86 ) ;
}
static T_1 void
F_90 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
struct V_35 * * V_36 = F_23 ( V_2 -> V_37 ) ;
if ( F_75 ( ! V_36 ) )
return;
while ( * V_36 ) {
F_81 ( V_2 , V_86 , * V_36 ) ;
V_36 ++ ;
}
}
static T_1 void
F_91 ( struct V_1 * V_2 , struct V_105 * V_106 ,
struct V_85 * V_86 ,
struct V_35 * V_93 )
{
struct V_107 * V_95 ;
struct V_96 * V_17 ;
struct V_97 * V_79 ;
int V_66 , V_99 , V_98 ;
unsigned long V_100 ;
struct V_101 * V_30 = & V_2 -> V_30 ;
F_82 ( V_30 != V_93 -> V_102 ) ;
if ( F_83 ( V_103 , & V_93 -> V_8 ) )
return;
F_84 ( V_100 ) ;
V_99 = F_85 () ;
V_98 = F_74 ( V_2 , V_86 ) ;
V_66 = sizeof( * V_95 ) + V_2 -> V_66 + V_98 ;
V_17 = F_86 ( & V_79 , V_93 ,
V_30 -> V_17 . type ,
V_66 , V_100 , V_99 ) ;
if ( ! V_17 )
return;
V_95 = F_87 ( V_17 ) ;
V_95 -> V_108 = ( unsigned long ) V_2 -> V_3 . V_6 . V_18 ;
V_95 -> V_109 = ( unsigned long ) V_106 -> V_110 ;
F_77 ( sizeof( * V_95 ) , V_2 , V_86 , ( T_7 * ) & V_95 [ 1 ] , V_98 ) ;
if ( ! F_88 ( V_79 , V_30 , V_95 , V_17 ) )
F_89 ( V_79 , V_17 ,
V_100 , V_99 , V_86 ) ;
}
static T_1 void
F_92 ( struct V_1 * V_2 , struct V_105 * V_106 ,
struct V_85 * V_86 )
{
struct V_35 * * V_36 = F_23 ( V_2 -> V_37 ) ;
if ( F_75 ( ! V_36 ) )
return;
while ( * V_36 ) {
F_91 ( V_2 , V_106 , V_86 , * V_36 ) ;
V_36 ++ ;
}
}
static enum V_111
F_93 ( struct V_112 * V_113 , int V_8 ,
struct V_114 * V_17 )
{
struct V_94 * V_115 ;
struct V_116 * V_117 = & V_113 -> V_118 ;
struct V_1 * V_2 ;
T_7 * V_55 ;
int V_33 ;
V_115 = (struct V_94 * ) V_113 -> V_119 ;
V_2 = F_94 ( V_17 , struct V_1 , V_30 . V_17 ) ;
if ( ! F_95 ( V_117 , L_38 , V_2 -> V_30 . V_15 ) )
goto V_120;
if ( ! F_96 ( V_117 , V_115 -> V_104 , V_8 | V_121 ) )
goto V_120;
if ( ! F_97 ( V_117 , L_39 ) )
goto V_120;
V_55 = ( T_7 * ) & V_115 [ 1 ] ;
for ( V_33 = 0 ; V_33 < V_2 -> V_34 ; V_33 ++ )
if ( ! V_2 -> args [ V_33 ] . type -> V_122 ( V_117 , V_2 -> args [ V_33 ] . V_15 ,
V_55 + V_2 -> args [ V_33 ] . V_7 , V_115 ) )
goto V_120;
if ( ! F_97 ( V_117 , L_36 ) )
goto V_120;
return V_123 ;
V_120:
return V_124 ;
}
static enum V_111
F_98 ( struct V_112 * V_113 , int V_8 ,
struct V_114 * V_17 )
{
struct V_107 * V_115 ;
struct V_116 * V_117 = & V_113 -> V_118 ;
struct V_1 * V_2 ;
T_7 * V_55 ;
int V_33 ;
V_115 = (struct V_107 * ) V_113 -> V_119 ;
V_2 = F_94 ( V_17 , struct V_1 , V_30 . V_17 ) ;
if ( ! F_95 ( V_117 , L_38 , V_2 -> V_30 . V_15 ) )
goto V_120;
if ( ! F_96 ( V_117 , V_115 -> V_109 , V_8 | V_121 ) )
goto V_120;
if ( ! F_97 ( V_117 , L_40 ) )
goto V_120;
if ( ! F_96 ( V_117 , V_115 -> V_108 , V_8 & ~ V_121 ) )
goto V_120;
if ( ! F_97 ( V_117 , L_39 ) )
goto V_120;
V_55 = ( T_7 * ) & V_115 [ 1 ] ;
for ( V_33 = 0 ; V_33 < V_2 -> V_34 ; V_33 ++ )
if ( ! V_2 -> args [ V_33 ] . type -> V_122 ( V_117 , V_2 -> args [ V_33 ] . V_15 ,
V_55 + V_2 -> args [ V_33 ] . V_7 , V_115 ) )
goto V_120;
if ( ! F_97 ( V_117 , L_36 ) )
goto V_120;
return V_123 ;
V_120:
return V_124 ;
}
static int F_99 ( struct V_101 * V_102 )
{
int V_22 , V_33 ;
struct V_94 V_115 ;
struct V_1 * V_2 = (struct V_1 * ) V_102 -> V_55 ;
F_100 (unsigned long, ip, FIELD_STRING_IP, 0 ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_34 ; V_33 ++ ) {
V_22 = F_101 ( V_102 , V_2 -> args [ V_33 ] . type -> V_125 ,
V_2 -> args [ V_33 ] . V_15 ,
sizeof( V_115 ) + V_2 -> args [ V_33 ] . V_7 ,
V_2 -> args [ V_33 ] . type -> V_66 ,
V_2 -> args [ V_33 ] . type -> V_126 ,
V_127 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static int F_102 ( struct V_101 * V_102 )
{
int V_22 , V_33 ;
struct V_107 V_115 ;
struct V_1 * V_2 = (struct V_1 * ) V_102 -> V_55 ;
F_100 (unsigned long, func, FIELD_STRING_FUNC, 0 ) ;
F_100 (unsigned long, ret_ip, FIELD_STRING_RETIP, 0 ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_34 ; V_33 ++ ) {
V_22 = F_101 ( V_102 , V_2 -> args [ V_33 ] . type -> V_125 ,
V_2 -> args [ V_33 ] . V_15 ,
sizeof( V_115 ) + V_2 -> args [ V_33 ] . V_7 ,
V_2 -> args [ V_33 ] . type -> V_66 ,
V_2 -> args [ V_33 ] . type -> V_126 ,
V_127 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static int F_103 ( struct V_1 * V_2 , char * V_62 , int V_14 )
{
int V_33 ;
int V_70 = 0 ;
const char * V_128 , * V_61 ;
if ( ! F_1 ( V_2 ) ) {
V_128 = L_41 ;
V_61 = L_42 V_129 ;
} else {
V_128 = L_43 ;
V_61 = L_42 V_130 L_44 V_131 ;
}
#define F_104 (len ? len - pos : 0)
V_70 += snprintf ( V_62 + V_70 , F_104 , L_45 , V_128 ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_34 ; V_33 ++ ) {
V_70 += snprintf ( V_62 + V_70 , F_104 , L_35 ,
V_2 -> args [ V_33 ] . V_15 , V_2 -> args [ V_33 ] . type -> V_128 ) ;
}
V_70 += snprintf ( V_62 + V_70 , F_104 , L_46 , V_61 ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_34 ; V_33 ++ ) {
if ( strcmp ( V_2 -> args [ V_33 ] . type -> V_15 , L_47 ) == 0 )
V_70 += snprintf ( V_62 + V_70 , F_104 ,
L_48 ,
V_2 -> args [ V_33 ] . V_15 ) ;
else
V_70 += snprintf ( V_62 + V_70 , F_104 , L_49 ,
V_2 -> args [ V_33 ] . V_15 ) ;
}
#undef F_104
return V_70 ;
}
static int F_105 ( struct V_1 * V_2 )
{
int V_14 ;
char * V_132 ;
V_14 = F_103 ( V_2 , NULL , 0 ) ;
V_132 = F_106 ( V_14 + 1 , V_24 ) ;
if ( ! V_132 )
return - V_23 ;
F_103 ( V_2 , V_132 , V_14 + 1 ) ;
V_2 -> V_30 . V_132 = V_132 ;
return 0 ;
}
static T_1 void
F_107 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
struct V_101 * V_30 = & V_2 -> V_30 ;
struct V_94 * V_95 ;
struct V_133 * V_134 ;
int V_66 , V_135 , V_98 ;
int V_136 ;
V_98 = F_74 ( V_2 , V_86 ) ;
V_135 = sizeof( * V_95 ) + V_2 -> V_66 + V_98 ;
V_66 = F_108 ( V_135 + sizeof( T_6 ) , sizeof( V_137 ) ) ;
V_66 -= sizeof( T_6 ) ;
if ( F_109 ( V_66 > V_138 ,
L_50 ) )
return;
V_95 = F_110 ( V_66 , V_30 -> V_17 . type , V_86 , & V_136 ) ;
if ( ! V_95 )
return;
V_95 -> V_104 = ( unsigned long ) V_2 -> V_3 . V_6 . V_18 ;
memset ( & V_95 [ 1 ] , 0 , V_98 ) ;
F_77 ( sizeof( * V_95 ) , V_2 , V_86 , ( T_7 * ) & V_95 [ 1 ] , V_98 ) ;
V_134 = F_111 ( V_30 -> V_139 ) ;
F_112 ( V_95 , V_66 , V_136 ,
V_95 -> V_104 , 1 , V_86 , V_134 , NULL ) ;
}
static T_1 void
F_113 ( struct V_1 * V_2 , struct V_105 * V_106 ,
struct V_85 * V_86 )
{
struct V_101 * V_30 = & V_2 -> V_30 ;
struct V_107 * V_95 ;
struct V_133 * V_134 ;
int V_66 , V_135 , V_98 ;
int V_136 ;
V_98 = F_74 ( V_2 , V_86 ) ;
V_135 = sizeof( * V_95 ) + V_2 -> V_66 + V_98 ;
V_66 = F_108 ( V_135 + sizeof( T_6 ) , sizeof( V_137 ) ) ;
V_66 -= sizeof( T_6 ) ;
if ( F_109 ( V_66 > V_138 ,
L_50 ) )
return;
V_95 = F_110 ( V_66 , V_30 -> V_17 . type , V_86 , & V_136 ) ;
if ( ! V_95 )
return;
V_95 -> V_108 = ( unsigned long ) V_2 -> V_3 . V_6 . V_18 ;
V_95 -> V_109 = ( unsigned long ) V_106 -> V_110 ;
F_77 ( sizeof( * V_95 ) , V_2 , V_86 , ( T_7 * ) & V_95 [ 1 ] , V_98 ) ;
V_134 = F_111 ( V_30 -> V_139 ) ;
F_112 ( V_95 , V_66 , V_136 ,
V_95 -> V_109 , 1 , V_86 , V_134 , NULL ) ;
}
static T_1
int F_114 ( struct V_101 * V_17 ,
enum V_140 type , void * V_55 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_55 ;
struct V_35 * V_36 = V_55 ;
switch ( type ) {
case V_141 :
return F_24 ( V_2 , V_36 ) ;
case V_142 :
return F_32 ( V_2 , V_36 ) ;
#ifdef F_115
case V_143 :
return F_24 ( V_2 , NULL ) ;
case V_144 :
return F_32 ( V_2 , NULL ) ;
case V_145 :
case V_146 :
case V_147 :
case V_148 :
return 0 ;
#endif
}
return 0 ;
}
static T_1
int V_28 ( struct V_149 * V_6 , struct V_85 * V_86 )
{
struct V_1 * V_2 = F_94 ( V_6 , struct V_1 , V_3 . V_6 ) ;
V_2 -> V_82 ++ ;
if ( V_2 -> V_8 & V_9 )
F_90 ( V_2 , V_86 ) ;
#ifdef F_115
if ( V_2 -> V_8 & V_10 )
F_107 ( V_2 , V_86 ) ;
#endif
return 0 ;
}
static T_1
int V_26 ( struct V_105 * V_106 , struct V_85 * V_86 )
{
struct V_1 * V_2 = F_94 ( V_106 -> V_3 , struct V_1 , V_3 ) ;
V_2 -> V_82 ++ ;
if ( V_2 -> V_8 & V_9 )
F_92 ( V_2 , V_106 , V_86 ) ;
#ifdef F_115
if ( V_2 -> V_8 & V_10 )
F_113 ( V_2 , V_106 , V_86 ) ;
#endif
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_101 * V_30 = & V_2 -> V_30 ;
int V_22 ;
F_16 ( & V_30 -> V_31 -> V_150 ) ;
if ( F_1 ( V_2 ) ) {
V_30 -> V_17 . V_151 = & V_152 ;
V_30 -> V_31 -> V_153 = F_102 ;
} else {
V_30 -> V_17 . V_151 = & V_154 ;
V_30 -> V_31 -> V_153 = F_99 ;
}
if ( F_105 ( V_2 ) < 0 )
return - V_23 ;
V_22 = F_116 ( & V_30 -> V_17 ) ;
if ( ! V_22 ) {
F_17 ( V_30 -> V_132 ) ;
return - V_155 ;
}
V_30 -> V_8 = 0 ;
V_30 -> V_31 -> V_156 = F_114 ;
V_30 -> V_55 = V_2 ;
V_22 = F_117 ( V_30 ) ;
if ( V_22 ) {
F_51 ( L_51 , V_30 -> V_15 ) ;
F_17 ( V_30 -> V_132 ) ;
F_118 ( & V_30 -> V_17 ) ;
}
return V_22 ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_119 ( & V_2 -> V_30 ) ;
F_17 ( V_2 -> V_30 . V_132 ) ;
}
static T_8 int F_120 ( void )
{
struct V_157 * V_158 ;
struct V_157 * V_95 ;
if ( F_121 ( & V_159 ) )
return - V_29 ;
V_158 = F_122 () ;
if ( ! V_158 )
return 0 ;
V_95 = F_123 ( L_52 , 0644 , V_158 ,
NULL , & V_160 ) ;
if ( ! V_95 )
F_39 ( L_53
L_54 ) ;
V_95 = F_123 ( L_55 , 0444 , V_158 ,
NULL , & V_161 ) ;
if ( ! V_95 )
F_39 ( L_53
L_56 ) ;
return 0 ;
}
static T_9 int F_124 ( int V_162 , int V_163 , int V_164 ,
int V_165 , int V_166 , int V_167 )
{
return V_162 + V_163 + V_164 + V_165 + V_166 + V_167 ;
}
static struct V_35 *
F_125 ( struct V_1 * V_2 , struct V_168 * V_169 )
{
struct V_35 * V_36 ;
F_21 (file, &tr->events, list)
if ( V_36 -> V_102 == & V_2 -> V_30 )
return V_36 ;
return NULL ;
}
static T_8 int F_126 ( void )
{
int V_22 , V_170 = 0 ;
int (* F_127)( int , int , int , int , int , int );
struct V_1 * V_2 ;
struct V_35 * V_36 ;
F_127 = F_124 ;
F_51 ( L_57 ) ;
V_22 = F_128 ( L_58
L_59 ,
F_50 ) ;
if ( F_129 ( V_22 ) ) {
F_130 ( L_60 ) ;
V_170 ++ ;
} else {
V_2 = F_20 ( L_61 , V_64 ) ;
if ( F_129 ( V_2 == NULL ) ) {
F_130 ( L_62 ) ;
V_170 ++ ;
} else {
V_36 = F_125 ( V_2 , F_131 () ) ;
if ( F_129 ( V_36 == NULL ) ) {
F_130 ( L_63 ) ;
V_170 ++ ;
} else
F_24 ( V_2 , V_36 ) ;
}
}
V_22 = F_128 ( L_64
L_65 , F_50 ) ;
if ( F_129 ( V_22 ) ) {
F_130 ( L_66 ) ;
V_170 ++ ;
} else {
V_2 = F_20 ( L_67 , V_64 ) ;
if ( F_129 ( V_2 == NULL ) ) {
F_130 ( L_68 ) ;
V_170 ++ ;
} else {
V_36 = F_125 ( V_2 , F_131 () ) ;
if ( F_129 ( V_36 == NULL ) ) {
F_130 ( L_63 ) ;
V_170 ++ ;
} else
F_24 ( V_2 , V_36 ) ;
}
}
if ( V_170 )
goto V_50;
V_22 = F_127 ( 1 , 2 , 3 , 4 , 5 , 6 ) ;
V_2 = F_20 ( L_61 , V_64 ) ;
if ( F_129 ( V_2 == NULL ) ) {
F_130 ( L_69 ) ;
V_170 ++ ;
} else {
V_36 = F_125 ( V_2 , F_131 () ) ;
if ( F_129 ( V_36 == NULL ) ) {
F_130 ( L_63 ) ;
V_170 ++ ;
} else
F_32 ( V_2 , V_36 ) ;
}
V_2 = F_20 ( L_67 , V_64 ) ;
if ( F_129 ( V_2 == NULL ) ) {
F_130 ( L_70 ) ;
V_170 ++ ;
} else {
V_36 = F_125 ( V_2 , F_131 () ) ;
if ( F_129 ( V_36 == NULL ) ) {
F_130 ( L_63 ) ;
V_170 ++ ;
} else
F_32 ( V_2 , V_36 ) ;
}
V_22 = F_128 ( L_71 , F_50 ) ;
if ( F_129 ( V_22 ) ) {
F_130 ( L_72 ) ;
V_170 ++ ;
}
V_22 = F_128 ( L_73 , F_50 ) ;
if ( F_129 ( V_22 ) ) {
F_130 ( L_72 ) ;
V_170 ++ ;
}
V_50:
F_58 () ;
if ( V_170 )
F_132 ( L_74 ) ;
else
F_132 ( L_75 ) ;
return 0 ;
}
