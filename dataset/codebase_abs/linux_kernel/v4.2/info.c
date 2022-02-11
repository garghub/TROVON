int F_1 ( const char * V_1 )
{
static char * V_2 [] =
{
L_1 ,
L_2 ,
L_3 ,
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 ,
L_11 ,
NULL
} ;
char * * V_3 = V_2 ;
while ( * V_3 ) {
if ( ! strcmp ( * V_3 , V_1 ) )
return 0 ;
V_3 ++ ;
}
if ( ! strncmp ( V_1 , L_12 , 4 ) )
return 0 ;
return 1 ;
}
static int F_2 ( struct V_4 * V_5 ,
struct V_6 * * V_7 )
{
struct V_6 * V_8 ;
if ( ! V_5 || ! V_5 -> V_9 )
return - V_10 ;
if ( ! F_3 ( V_5 -> V_11 ) )
return - V_12 ;
V_8 = F_4 ( sizeof( * V_8 ) , V_13 ) ;
if ( ! V_8 ) {
F_5 ( V_5 -> V_11 ) ;
return - V_14 ;
}
V_8 -> V_5 = V_5 ;
* V_7 = V_8 ;
return 0 ;
}
static bool F_6 ( T_1 V_15 , T_2 V_16 )
{
if ( V_15 < 0 || ( long ) V_15 != V_15 || ( V_17 ) V_16 < 0 )
return false ;
if ( ( unsigned long ) V_15 + ( unsigned long ) V_16 < ( unsigned long ) V_15 )
return false ;
return true ;
}
static T_1 F_7 ( struct V_18 * V_18 , T_1 V_19 , int V_20 )
{
struct V_6 * V_8 ;
struct V_4 * V_5 ;
T_1 V_7 = - V_21 , V_22 ;
V_8 = V_18 -> V_23 ;
V_5 = V_8 -> V_5 ;
F_8 ( & V_5 -> V_24 ) ;
if ( V_5 -> V_25 . V_26 -> V_27 ) {
V_19 = V_5 -> V_25 . V_26 -> V_27 ( V_5 ,
V_8 -> V_28 ,
V_18 , V_19 , V_20 ) ;
goto V_29;
}
V_22 = V_5 -> V_22 ;
switch ( V_20 ) {
case V_30 :
break;
case V_31 :
V_19 += V_18 -> V_32 ;
break;
case V_33 :
if ( ! V_22 )
goto V_29;
V_19 += V_22 ;
break;
default:
goto V_29;
}
if ( V_19 < 0 )
goto V_29;
if ( V_22 && V_19 > V_22 )
V_19 = V_22 ;
V_18 -> V_32 = V_19 ;
V_7 = V_19 ;
V_29:
F_9 ( & V_5 -> V_24 ) ;
return V_7 ;
}
static V_17 F_10 ( struct V_18 * V_18 , char T_3 * V_34 ,
T_2 V_16 , T_1 * V_19 )
{
struct V_6 * V_8 = V_18 -> V_23 ;
struct V_4 * V_5 = V_8 -> V_5 ;
T_2 V_22 ;
T_1 V_15 ;
V_15 = * V_19 ;
if ( ! F_6 ( V_15 , V_16 ) )
return - V_35 ;
if ( V_15 >= V_5 -> V_22 )
return 0 ;
V_22 = V_5 -> V_22 - V_15 ;
V_22 = F_11 ( V_16 , V_22 ) ;
V_22 = V_5 -> V_25 . V_26 -> V_36 ( V_5 , V_8 -> V_28 ,
V_18 , V_34 , V_22 , V_15 ) ;
if ( ( V_17 ) V_22 > 0 )
* V_19 = V_15 + V_22 ;
return V_22 ;
}
static V_17 F_12 ( struct V_18 * V_18 , const char T_3 * V_34 ,
T_2 V_16 , T_1 * V_19 )
{
struct V_6 * V_8 = V_18 -> V_23 ;
struct V_4 * V_5 = V_8 -> V_5 ;
V_17 V_22 = 0 ;
T_1 V_15 ;
V_15 = * V_19 ;
if ( ! F_6 ( V_15 , V_16 ) )
return - V_35 ;
if ( V_16 > 0 ) {
T_2 V_37 = V_5 -> V_22 - V_15 ;
V_16 = F_11 ( V_16 , V_37 ) ;
V_22 = V_5 -> V_25 . V_26 -> V_38 ( V_5 , V_8 -> V_28 ,
V_18 , V_34 , V_16 , V_15 ) ;
}
if ( V_22 > 0 )
* V_19 = V_15 + V_22 ;
return V_22 ;
}
static unsigned int F_13 ( struct V_18 * V_18 , T_4 * V_39 )
{
struct V_6 * V_8 = V_18 -> V_23 ;
struct V_4 * V_5 = V_8 -> V_5 ;
unsigned int V_40 = 0 ;
if ( V_5 -> V_25 . V_26 -> V_41 )
return V_5 -> V_25 . V_26 -> V_41 ( V_5 ,
V_8 -> V_28 ,
V_18 , V_39 ) ;
if ( V_5 -> V_25 . V_26 -> V_36 )
V_40 |= V_42 | V_43 ;
if ( V_5 -> V_25 . V_26 -> V_38 )
V_40 |= V_44 | V_45 ;
return V_40 ;
}
static long F_14 ( struct V_18 * V_18 , unsigned int V_46 ,
unsigned long V_47 )
{
struct V_6 * V_8 = V_18 -> V_23 ;
struct V_4 * V_5 = V_8 -> V_5 ;
if ( ! V_5 -> V_25 . V_26 -> V_48 )
return - V_49 ;
return V_5 -> V_25 . V_26 -> V_48 ( V_5 , V_8 -> V_28 ,
V_18 , V_46 , V_47 ) ;
}
static int F_15 ( struct V_18 * V_18 , struct V_50 * V_51 )
{
struct V_52 * V_52 = F_16 ( V_18 ) ;
struct V_6 * V_8 ;
struct V_4 * V_5 ;
V_8 = V_18 -> V_23 ;
if ( V_8 == NULL )
return 0 ;
V_5 = V_8 -> V_5 ;
if ( ! V_5 -> V_25 . V_26 -> V_53 )
return - V_54 ;
return V_5 -> V_25 . V_26 -> V_53 ( V_5 , V_8 -> V_28 ,
V_52 , V_18 , V_51 ) ;
}
static int F_17 ( struct V_52 * V_52 , struct V_18 * V_18 )
{
struct V_4 * V_5 = F_18 ( V_52 ) ;
struct V_6 * V_8 ;
int V_55 , V_56 ;
F_8 ( & V_57 ) ;
V_56 = F_2 ( V_5 , & V_8 ) ;
if ( V_56 < 0 )
goto V_58;
V_55 = V_18 -> V_59 & V_60 ;
if ( ( ( V_55 == V_61 || V_55 == V_62 ) && ! V_5 -> V_25 . V_26 -> V_36 ) ||
( ( V_55 == V_63 || V_55 == V_62 ) && ! V_5 -> V_25 . V_26 -> V_38 ) ) {
V_56 = - V_10 ;
goto error;
}
if ( V_5 -> V_25 . V_26 -> V_64 ) {
V_56 = V_5 -> V_25 . V_26 -> V_64 ( V_5 , V_55 , & V_8 -> V_28 ) ;
if ( V_56 < 0 )
goto error;
}
V_18 -> V_23 = V_8 ;
F_9 ( & V_57 ) ;
return 0 ;
error:
F_19 ( V_8 ) ;
F_5 ( V_5 -> V_11 ) ;
V_58:
F_9 ( & V_57 ) ;
return V_56 ;
}
static int F_20 ( struct V_52 * V_52 , struct V_18 * V_18 )
{
struct V_6 * V_8 = V_18 -> V_23 ;
struct V_4 * V_5 = V_8 -> V_5 ;
if ( V_5 -> V_25 . V_26 -> V_65 )
V_5 -> V_25 . V_26 -> V_65 ( V_5 , V_18 -> V_59 & V_60 ,
V_8 -> V_28 ) ;
F_5 ( V_5 -> V_11 ) ;
F_19 ( V_8 ) ;
return 0 ;
}
static V_17 F_21 ( struct V_18 * V_18 ,
const char T_3 * V_34 ,
T_2 V_16 , T_1 * V_19 )
{
struct V_66 * V_67 = V_18 -> V_23 ;
struct V_6 * V_8 = V_67 -> V_68 ;
struct V_4 * V_5 = V_8 -> V_5 ;
struct V_69 * V_70 ;
T_1 V_15 ;
T_2 V_71 ;
int V_56 = 0 ;
V_15 = * V_19 ;
if ( ! F_6 ( V_15 , V_16 ) )
return - V_35 ;
V_71 = V_15 + V_16 ;
F_8 ( & V_5 -> V_24 ) ;
V_70 = V_8 -> V_72 ;
if ( ! V_70 ) {
V_8 -> V_72 = V_70 = F_4 ( sizeof( * V_70 ) , V_13 ) ;
if ( ! V_70 ) {
V_56 = - V_14 ;
goto error;
}
}
if ( V_71 > V_70 -> V_73 ) {
char * V_74 = F_22 ( V_70 -> V_34 , F_23 ( V_71 ) ,
V_13 | V_75 ) ;
if ( ! V_74 ) {
V_56 = - V_14 ;
goto error;
}
V_70 -> V_34 = V_74 ;
V_70 -> V_73 = F_23 ( V_71 ) ;
}
if ( F_24 ( V_70 -> V_34 + V_15 , V_34 , V_16 ) ) {
V_56 = - V_12 ;
goto error;
}
V_70 -> V_22 = V_71 ;
error:
F_9 ( & V_5 -> V_24 ) ;
if ( V_56 < 0 )
return V_56 ;
* V_19 = V_71 ;
return V_16 ;
}
static int F_25 ( struct V_66 * V_76 , void * V_9 )
{
struct V_6 * V_8 = V_76 -> V_68 ;
struct V_4 * V_5 = V_8 -> V_5 ;
if ( V_5 -> V_25 . V_77 . V_36 ) {
V_8 -> V_78 -> V_34 = ( char * ) V_76 ;
V_5 -> V_25 . V_77 . V_36 ( V_5 , V_8 -> V_78 ) ;
}
return 0 ;
}
static int F_26 ( struct V_52 * V_52 , struct V_18 * V_18 )
{
struct V_4 * V_5 = F_18 ( V_52 ) ;
struct V_6 * V_8 ;
int V_56 ;
F_8 ( & V_57 ) ;
V_56 = F_2 ( V_5 , & V_8 ) ;
if ( V_56 < 0 )
goto V_58;
V_8 -> V_78 = F_4 ( sizeof( * V_8 -> V_78 ) , V_13 ) ;
if ( ! V_8 -> V_78 ) {
V_56 = - V_14 ;
goto error;
}
if ( V_5 -> V_22 )
V_56 = F_27 ( V_18 , F_25 , V_8 ,
V_5 -> V_22 ) ;
else
V_56 = F_28 ( V_18 , F_25 , V_8 ) ;
if ( V_56 < 0 )
goto error;
F_9 ( & V_57 ) ;
return 0 ;
error:
F_19 ( V_8 -> V_78 ) ;
F_19 ( V_8 ) ;
F_5 ( V_5 -> V_11 ) ;
V_58:
F_9 ( & V_57 ) ;
return V_56 ;
}
static int F_29 ( struct V_52 * V_52 , struct V_18 * V_18 )
{
struct V_66 * V_67 = V_18 -> V_23 ;
struct V_6 * V_8 = V_67 -> V_68 ;
struct V_4 * V_5 = V_8 -> V_5 ;
if ( V_8 -> V_72 && V_5 -> V_25 . V_77 . V_38 )
V_5 -> V_25 . V_77 . V_38 ( V_5 , V_8 -> V_72 ) ;
F_30 ( V_52 , V_18 ) ;
F_19 ( V_8 -> V_78 ) ;
if ( V_8 -> V_72 ) {
F_19 ( V_8 -> V_72 -> V_34 ) ;
F_19 ( V_8 -> V_72 ) ;
}
F_5 ( V_5 -> V_11 ) ;
F_19 ( V_8 ) ;
return 0 ;
}
static struct V_4 * F_31 ( struct V_11 * V_79 ,
const char * V_80 )
{
struct V_4 * V_5 ;
V_5 = F_32 ( V_79 , V_80 , NULL ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_55 = V_81 | V_82 | V_83 ;
if ( F_33 ( V_5 ) < 0 ) {
F_34 ( V_5 ) ;
return NULL ;
}
return V_5 ;
}
int T_5 F_35 ( void )
{
V_84 = F_36 ( L_13 , NULL ) ;
if ( ! V_84 )
return - V_14 ;
V_84 -> V_55 = V_81 | V_82 | V_83 ;
V_84 -> V_9 = F_37 ( L_13 , NULL ) ;
if ( ! V_84 -> V_9 )
goto error;
#ifdef F_38
V_85 = F_31 ( V_86 , L_6 ) ;
if ( ! V_85 )
goto error;
#endif
#if F_39 ( V_87 )
V_88 = F_31 ( V_86 , L_11 ) ;
if ( ! V_88 )
goto error;
#endif
if ( F_40 () < 0 ||
F_41 () < 0 ||
F_42 () < 0 ||
F_43 () < 0 ||
F_44 () < 0 )
goto error;
return 0 ;
error:
F_34 ( V_84 ) ;
return - V_14 ;
}
int T_6 F_45 ( void )
{
F_34 ( V_84 ) ;
return 0 ;
}
int F_46 ( struct V_89 * V_90 )
{
char V_1 [ 8 ] ;
struct V_4 * V_5 ;
if ( F_47 ( ! V_90 ) )
return - V_54 ;
sprintf ( V_1 , L_14 , V_90 -> V_91 ) ;
V_5 = F_31 ( V_90 -> V_11 , V_1 ) ;
if ( ! V_5 )
return - V_14 ;
V_90 -> V_92 = V_5 ;
return 0 ;
}
static int F_48 ( struct V_4 * V_5 )
{
struct V_4 * V_9 ;
int V_56 ;
if ( ! V_5 -> V_9 ) {
V_56 = F_33 ( V_5 ) ;
if ( V_56 < 0 )
return V_56 ;
}
F_49 (p, &entry->children, list) {
V_56 = F_48 ( V_9 ) ;
if ( V_56 < 0 )
return V_56 ;
}
return 0 ;
}
int F_50 ( struct V_89 * V_90 )
{
struct V_93 * V_9 ;
int V_56 ;
if ( F_47 ( ! V_90 ) )
return - V_54 ;
V_56 = F_48 ( V_90 -> V_92 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( ! strcmp ( V_90 -> V_94 , V_90 -> V_92 -> V_80 ) )
return 0 ;
if ( V_90 -> V_95 )
return 0 ;
V_9 = F_51 ( V_90 -> V_94 , V_84 -> V_9 , V_90 -> V_92 -> V_80 ) ;
if ( ! V_9 )
return - V_14 ;
V_90 -> V_95 = V_9 ;
return 0 ;
}
void F_52 ( struct V_89 * V_90 )
{
F_8 ( & V_57 ) ;
if ( V_90 -> V_95 ) {
F_53 ( V_90 -> V_95 ) ;
V_90 -> V_95 = NULL ;
}
if ( strcmp ( V_90 -> V_94 , V_90 -> V_92 -> V_80 ) )
V_90 -> V_95 = F_51 ( V_90 -> V_94 ,
V_84 -> V_9 ,
V_90 -> V_92 -> V_80 ) ;
F_9 ( & V_57 ) ;
}
void F_54 ( struct V_89 * V_90 )
{
if ( ! V_90 )
return;
F_8 ( & V_57 ) ;
F_53 ( V_90 -> V_95 ) ;
V_90 -> V_95 = NULL ;
if ( V_90 -> V_92 )
F_55 ( V_90 -> V_92 ) ;
F_9 ( & V_57 ) ;
}
int F_56 ( struct V_89 * V_90 )
{
if ( ! V_90 )
return 0 ;
F_34 ( V_90 -> V_92 ) ;
V_90 -> V_92 = NULL ;
return 0 ;
}
int F_57 ( struct V_69 * V_34 , char * line , int V_73 )
{
int V_25 = - 1 ;
if ( F_47 ( ! V_34 || ! V_34 -> V_34 ) )
return 1 ;
if ( V_73 <= 0 || V_34 -> V_96 || V_34 -> error )
return 1 ;
while ( ! V_34 -> V_96 ) {
V_25 = V_34 -> V_34 [ V_34 -> V_97 ++ ] ;
if ( V_34 -> V_97 >= V_34 -> V_22 )
V_34 -> V_96 = 1 ;
if ( V_25 == '\n' )
break;
if ( V_73 > 1 ) {
V_73 -- ;
* line ++ = V_25 ;
}
}
* line = '\0' ;
return 0 ;
}
const char * F_58 ( char * V_98 , const char * V_99 , int V_73 )
{
int V_25 ;
while ( * V_99 == ' ' || * V_99 == '\t' )
V_99 ++ ;
if ( * V_99 == '"' || * V_99 == '\'' ) {
V_25 = * V_99 ++ ;
while ( -- V_73 > 0 && * V_99 && * V_99 != V_25 ) {
* V_98 ++ = * V_99 ++ ;
}
if ( * V_99 == V_25 )
V_99 ++ ;
} else {
while ( -- V_73 > 0 && * V_99 && * V_99 != ' ' && * V_99 != '\t' ) {
* V_98 ++ = * V_99 ++ ;
}
}
* V_98 = 0 ;
while ( * V_99 == ' ' || * V_99 == '\t' )
V_99 ++ ;
return V_99 ;
}
static struct V_4 *
F_36 ( const char * V_80 , struct V_4 * V_100 )
{
struct V_4 * V_5 ;
V_5 = F_4 ( sizeof( * V_5 ) , V_13 ) ;
if ( V_5 == NULL )
return NULL ;
V_5 -> V_80 = F_59 ( V_80 , V_13 ) ;
if ( V_5 -> V_80 == NULL ) {
F_19 ( V_5 ) ;
return NULL ;
}
V_5 -> V_55 = V_101 | V_82 ;
V_5 -> V_102 = V_103 ;
F_60 ( & V_5 -> V_24 ) ;
F_61 ( & V_5 -> V_104 ) ;
F_61 ( & V_5 -> V_105 ) ;
V_5 -> V_100 = V_100 ;
if ( V_100 )
F_62 ( & V_5 -> V_105 , & V_100 -> V_104 ) ;
return V_5 ;
}
struct V_4 * F_32 ( struct V_11 * V_11 ,
const char * V_80 ,
struct V_4 * V_100 )
{
struct V_4 * V_5 = F_36 ( V_80 , V_100 ) ;
if ( V_5 )
V_5 -> V_11 = V_11 ;
return V_5 ;
}
struct V_4 * F_63 ( struct V_89 * V_90 ,
const char * V_80 ,
struct V_4 * V_100 )
{
struct V_4 * V_5 = F_36 ( V_80 , V_100 ) ;
if ( V_5 ) {
V_5 -> V_11 = V_90 -> V_11 ;
V_5 -> V_90 = V_90 ;
}
return V_5 ;
}
static void F_55 ( struct V_4 * V_5 )
{
struct V_4 * V_9 ;
if ( ! V_5 -> V_9 )
return;
F_49 (p, &entry->children, list)
F_55 ( V_9 ) ;
F_53 ( V_5 -> V_9 ) ;
V_5 -> V_9 = NULL ;
}
void F_34 ( struct V_4 * V_5 )
{
struct V_4 * V_9 , * V_106 ;
if ( ! V_5 )
return;
if ( V_5 -> V_9 ) {
F_8 ( & V_57 ) ;
F_55 ( V_5 ) ;
F_9 ( & V_57 ) ;
}
F_64 (p, n, &entry->children, list)
F_34 ( V_9 ) ;
F_65 ( & V_5 -> V_105 ) ;
F_19 ( V_5 -> V_80 ) ;
if ( V_5 -> V_107 )
V_5 -> V_107 ( V_5 ) ;
F_19 ( V_5 ) ;
}
int F_33 ( struct V_4 * V_5 )
{
struct V_93 * V_108 , * V_9 = NULL ;
if ( F_47 ( ! V_5 ) )
return - V_54 ;
V_108 = V_5 -> V_100 == NULL ? V_84 -> V_9 : V_5 -> V_100 -> V_9 ;
F_8 ( & V_57 ) ;
if ( F_66 ( V_5 -> V_55 ) ) {
V_9 = F_67 ( V_5 -> V_80 , V_5 -> V_55 , V_108 ) ;
if ( ! V_9 ) {
F_9 ( & V_57 ) ;
return - V_14 ;
}
} else {
const struct V_109 * V_26 ;
if ( V_5 -> V_102 == V_110 )
V_26 = & V_111 ;
else
V_26 = & V_112 ;
V_9 = F_68 ( V_5 -> V_80 , V_5 -> V_55 , V_108 ,
V_26 , V_5 ) ;
if ( ! V_9 ) {
F_9 ( & V_57 ) ;
return - V_14 ;
}
F_69 ( V_9 , V_5 -> V_22 ) ;
}
V_5 -> V_9 = V_9 ;
F_9 ( & V_57 ) ;
return 0 ;
}
static void F_70 ( struct V_4 * V_5 , struct V_69 * V_34 )
{
F_71 ( V_34 ,
L_15 ,
F_72 () -> V_65 ) ;
}
static int T_5 F_40 ( void )
{
struct V_4 * V_5 ;
V_5 = F_32 ( V_86 , L_1 , NULL ) ;
if ( V_5 == NULL )
return - V_14 ;
V_5 -> V_25 . V_77 . V_36 = F_70 ;
return F_33 ( V_5 ) ;
}
