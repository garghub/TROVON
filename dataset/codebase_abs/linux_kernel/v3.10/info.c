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
unsigned int V_6 )
{
char * V_7 ;
V_6 = F_3 ( V_6 ) ;
V_7 = F_4 ( V_5 -> V_5 , V_6 , V_8 | V_9 ) ;
if ( ! V_7 )
return - V_10 ;
V_5 -> V_5 = V_7 ;
V_5 -> V_11 = V_6 ;
return 0 ;
}
int F_5 ( struct V_4 * V_5 , const char * V_12 , ... )
{
T_1 args ;
int V_11 , V_13 ;
int V_14 = 0 ;
F_6 () ;
if ( V_5 -> V_15 || V_5 -> error )
return 0 ;
V_11 = V_5 -> V_11 - V_5 -> V_16 ;
va_start ( args , V_12 ) ;
for (; ; ) {
T_1 V_17 ;
F_7 ( V_17 , args ) ;
V_13 = vsnprintf ( V_5 -> V_5 + V_5 -> V_18 , V_11 , V_12 , V_17 ) ;
va_end ( V_17 ) ;
if ( V_13 < V_11 )
break;
V_14 = F_2 ( V_5 , V_5 -> V_11 + V_19 ) ;
if ( V_14 < 0 )
break;
V_11 = V_5 -> V_11 - V_5 -> V_16 ;
}
va_end ( args ) ;
if ( V_14 < 0 )
return V_14 ;
V_5 -> V_18 += V_13 ;
V_5 -> V_16 += V_13 ;
return V_13 ;
}
static T_2 F_8 ( struct V_20 * V_20 , T_2 V_21 , int V_22 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 ;
T_2 V_27 = - V_28 , V_16 ;
V_24 = V_20 -> V_29 ;
V_26 = V_24 -> V_26 ;
F_9 ( & V_26 -> V_30 ) ;
if ( V_26 -> V_31 == V_32 &&
V_26 -> V_33 . V_34 -> V_35 ) {
V_21 = V_26 -> V_33 . V_34 -> V_35 ( V_26 ,
V_24 -> V_36 ,
V_20 , V_21 , V_22 ) ;
goto V_37;
}
if ( V_26 -> V_31 == V_32 )
V_16 = V_26 -> V_16 ;
else
V_16 = 0 ;
switch ( V_22 ) {
case V_38 :
break;
case V_39 :
V_21 += V_20 -> V_40 ;
break;
case V_41 :
if ( ! V_16 )
goto V_37;
V_21 += V_16 ;
break;
default:
goto V_37;
}
if ( V_21 < 0 )
goto V_37;
if ( V_16 && V_21 > V_16 )
V_21 = V_16 ;
V_20 -> V_40 = V_21 ;
V_27 = V_21 ;
V_37:
F_10 ( & V_26 -> V_30 ) ;
return V_27 ;
}
static T_3 F_11 ( struct V_20 * V_20 , char T_4 * V_5 ,
T_5 V_42 , T_2 * V_21 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_4 * V_43 ;
T_5 V_16 = 0 ;
T_2 V_44 ;
V_24 = V_20 -> V_29 ;
if ( F_12 ( ! V_24 ) )
return - V_45 ;
V_44 = * V_21 ;
if ( V_44 < 0 || ( long ) V_44 != V_44 || ( T_3 ) V_42 < 0 )
return - V_46 ;
if ( ( unsigned long ) V_44 + ( unsigned long ) V_42 < ( unsigned long ) V_44 )
return - V_46 ;
V_26 = V_24 -> V_26 ;
switch ( V_26 -> V_31 ) {
case V_47 :
V_43 = V_24 -> V_48 ;
if ( V_43 == NULL )
return - V_46 ;
if ( V_44 >= V_43 -> V_16 )
return 0 ;
V_16 = V_43 -> V_16 - V_44 ;
V_16 = F_13 ( V_42 , V_16 ) ;
if ( F_14 ( V_5 , V_43 -> V_5 + V_44 , V_16 ) )
return - V_49 ;
break;
case V_32 :
if ( V_44 >= V_26 -> V_16 )
return 0 ;
if ( V_26 -> V_33 . V_34 -> V_50 ) {
V_16 = V_26 -> V_16 - V_44 ;
V_16 = F_13 ( V_42 , V_16 ) ;
V_16 = V_26 -> V_33 . V_34 -> V_50 ( V_26 ,
V_24 -> V_36 ,
V_20 , V_5 , V_16 , V_44 ) ;
}
break;
}
if ( ( T_3 ) V_16 > 0 )
* V_21 = V_44 + V_16 ;
return V_16 ;
}
static T_3 F_15 ( struct V_20 * V_20 , const char T_4 * V_5 ,
T_5 V_42 , T_2 * V_21 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_4 * V_43 ;
T_3 V_16 = 0 ;
T_2 V_44 ;
V_24 = V_20 -> V_29 ;
if ( F_12 ( ! V_24 ) )
return - V_45 ;
V_26 = V_24 -> V_26 ;
V_44 = * V_21 ;
if ( V_44 < 0 || ( long ) V_44 != V_44 || ( T_3 ) V_42 < 0 )
return - V_46 ;
if ( ( unsigned long ) V_44 + ( unsigned long ) V_42 < ( unsigned long ) V_44 )
return - V_46 ;
switch ( V_26 -> V_31 ) {
case V_47 :
V_43 = V_24 -> V_51 ;
if ( V_43 == NULL )
return - V_46 ;
F_9 ( & V_26 -> V_30 ) ;
if ( V_44 + V_42 >= V_43 -> V_11 ) {
if ( F_2 ( V_43 , V_44 + V_42 ) ) {
F_10 ( & V_26 -> V_30 ) ;
return - V_10 ;
}
}
if ( F_16 ( V_43 -> V_5 + V_44 , V_5 , V_42 ) ) {
F_10 ( & V_26 -> V_30 ) ;
return - V_49 ;
}
V_43 -> V_16 = V_44 + V_42 ;
F_10 ( & V_26 -> V_30 ) ;
V_16 = V_42 ;
break;
case V_32 :
if ( V_26 -> V_33 . V_34 -> V_52 && V_42 > 0 ) {
T_5 V_53 = V_26 -> V_16 - V_44 ;
V_42 = F_13 ( V_42 , V_53 ) ;
V_16 = V_26 -> V_33 . V_34 -> V_52 ( V_26 ,
V_24 -> V_36 ,
V_20 , V_5 , V_42 , V_44 ) ;
}
break;
}
if ( ( T_3 ) V_16 > 0 )
* V_21 = V_44 + V_16 ;
return V_16 ;
}
static int F_17 ( struct V_54 * V_54 , struct V_20 * V_20 )
{
struct V_25 * V_26 ;
struct V_23 * V_24 ;
struct V_4 * V_5 ;
int V_55 , V_14 ;
F_9 ( & V_56 ) ;
V_26 = F_18 ( V_54 ) ;
if ( V_26 == NULL || ! V_26 -> V_57 ) {
F_10 ( & V_56 ) ;
return - V_58 ;
}
if ( ! F_19 ( V_26 -> V_59 ) ) {
V_14 = - V_49 ;
goto V_60;
}
V_55 = V_20 -> V_61 & V_62 ;
if ( V_55 == V_63 || V_55 == V_64 ) {
if ( ( V_26 -> V_31 == V_32 &&
V_26 -> V_33 . V_34 -> V_50 == NULL ) ) {
V_14 = - V_58 ;
goto V_65;
}
}
if ( V_55 == V_66 || V_55 == V_64 ) {
if ( ( V_26 -> V_31 == V_32 &&
V_26 -> V_33 . V_34 -> V_52 == NULL ) ) {
V_14 = - V_58 ;
goto V_65;
}
}
V_24 = F_20 ( sizeof( * V_24 ) , V_8 ) ;
if ( V_24 == NULL ) {
V_14 = - V_10 ;
goto V_65;
}
V_24 -> V_26 = V_26 ;
switch ( V_26 -> V_31 ) {
case V_47 :
if ( V_55 == V_63 || V_55 == V_64 ) {
V_5 = F_20 ( sizeof( * V_5 ) , V_8 ) ;
if ( V_5 == NULL )
goto V_67;
V_24 -> V_48 = V_5 ;
V_5 -> V_11 = V_19 ;
V_5 -> V_5 = F_20 ( V_5 -> V_11 , V_8 ) ;
if ( V_5 -> V_5 == NULL )
goto V_67;
}
if ( V_55 == V_66 || V_55 == V_64 ) {
V_5 = F_20 ( sizeof( * V_5 ) , V_8 ) ;
if ( V_5 == NULL )
goto V_67;
V_24 -> V_51 = V_5 ;
V_5 -> V_11 = V_19 ;
V_5 -> V_5 = F_21 ( V_5 -> V_11 , V_8 ) ;
if ( V_5 -> V_5 == NULL )
goto V_67;
}
break;
case V_32 :
if ( V_26 -> V_33 . V_34 -> V_68 ) {
if ( ( V_14 = V_26 -> V_33 . V_34 -> V_68 ( V_26 , V_55 ,
& V_24 -> V_36 ) ) < 0 ) {
F_22 ( V_24 ) ;
goto V_65;
}
}
break;
}
V_20 -> V_29 = V_24 ;
F_10 ( & V_56 ) ;
if ( V_26 -> V_31 == V_47 &&
( V_55 == V_63 || V_55 == V_64 ) ) {
if ( V_26 -> V_33 . V_69 . V_50 ) {
F_9 ( & V_26 -> V_30 ) ;
V_26 -> V_33 . V_69 . V_50 ( V_26 , V_24 -> V_48 ) ;
F_10 ( & V_26 -> V_30 ) ;
}
}
return 0 ;
V_67:
if ( V_24 -> V_48 ) {
F_22 ( V_24 -> V_48 -> V_5 ) ;
F_22 ( V_24 -> V_48 ) ;
}
if ( V_24 -> V_51 ) {
F_22 ( V_24 -> V_51 -> V_5 ) ;
F_22 ( V_24 -> V_51 ) ;
}
F_22 ( V_24 ) ;
V_14 = - V_10 ;
V_65:
F_23 ( V_26 -> V_59 ) ;
V_60:
F_10 ( & V_56 ) ;
return V_14 ;
}
static int F_24 ( struct V_54 * V_54 , struct V_20 * V_20 )
{
struct V_25 * V_26 ;
struct V_23 * V_24 ;
int V_55 ;
V_55 = V_20 -> V_61 & V_62 ;
V_24 = V_20 -> V_29 ;
V_26 = V_24 -> V_26 ;
switch ( V_26 -> V_31 ) {
case V_47 :
if ( V_24 -> V_48 ) {
F_22 ( V_24 -> V_48 -> V_5 ) ;
F_22 ( V_24 -> V_48 ) ;
}
if ( V_24 -> V_51 ) {
if ( V_26 -> V_33 . V_69 . V_52 ) {
V_26 -> V_33 . V_69 . V_52 ( V_26 , V_24 -> V_51 ) ;
if ( V_24 -> V_51 -> error ) {
F_25 ( V_70 L_13 ,
V_26 -> V_71 ,
V_24 -> V_51 -> error ) ;
}
}
F_22 ( V_24 -> V_51 -> V_5 ) ;
F_22 ( V_24 -> V_51 ) ;
}
break;
case V_32 :
if ( V_26 -> V_33 . V_34 -> V_72 )
V_26 -> V_33 . V_34 -> V_72 ( V_26 , V_55 ,
V_24 -> V_36 ) ;
break;
}
F_23 ( V_26 -> V_59 ) ;
F_22 ( V_24 ) ;
return 0 ;
}
static unsigned int F_26 ( struct V_20 * V_20 , T_6 * V_73 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 ;
unsigned int V_74 ;
V_24 = V_20 -> V_29 ;
if ( V_24 == NULL )
return 0 ;
V_26 = V_24 -> V_26 ;
V_74 = 0 ;
switch ( V_26 -> V_31 ) {
case V_32 :
if ( V_26 -> V_33 . V_34 -> V_75 )
return V_26 -> V_33 . V_34 -> V_75 ( V_26 ,
V_24 -> V_36 ,
V_20 , V_73 ) ;
if ( V_26 -> V_33 . V_34 -> V_50 )
V_74 |= V_76 | V_77 ;
if ( V_26 -> V_33 . V_34 -> V_52 )
V_74 |= V_78 | V_79 ;
break;
}
return V_74 ;
}
static long F_27 ( struct V_20 * V_20 , unsigned int V_80 ,
unsigned long V_81 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 ;
V_24 = V_20 -> V_29 ;
if ( V_24 == NULL )
return 0 ;
V_26 = V_24 -> V_26 ;
switch ( V_26 -> V_31 ) {
case V_32 :
if ( V_26 -> V_33 . V_34 -> V_82 )
return V_26 -> V_33 . V_34 -> V_82 ( V_26 ,
V_24 -> V_36 ,
V_20 , V_80 , V_81 ) ;
break;
}
return - V_83 ;
}
static int F_28 ( struct V_20 * V_20 , struct V_84 * V_85 )
{
struct V_54 * V_54 = F_29 ( V_20 ) ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
V_24 = V_20 -> V_29 ;
if ( V_24 == NULL )
return 0 ;
V_26 = V_24 -> V_26 ;
switch ( V_26 -> V_31 ) {
case V_32 :
if ( V_26 -> V_33 . V_34 -> V_86 )
return V_26 -> V_33 . V_34 -> V_86 ( V_26 ,
V_24 -> V_36 ,
V_54 , V_20 , V_85 ) ;
break;
}
return - V_45 ;
}
int T_7 F_30 ( void )
{
struct V_87 * V_57 ;
V_57 = F_31 ( L_14 , NULL ) ;
if ( V_57 == NULL )
return - V_10 ;
V_88 = V_57 ;
#ifdef F_32
{
struct V_25 * V_26 ;
if ( ( V_26 = F_33 ( V_89 , L_6 , NULL ) ) == NULL )
return - V_10 ;
V_26 -> V_55 = V_90 | V_91 | V_92 ;
if ( F_34 ( V_26 ) < 0 ) {
F_35 ( V_26 ) ;
return - V_10 ;
}
V_93 = V_26 ;
}
#endif
#if F_36 ( V_94 ) || F_36 ( V_95 )
{
struct V_25 * V_26 ;
if ( ( V_26 = F_33 ( V_89 , L_11 , NULL ) ) == NULL )
return - V_10 ;
V_26 -> V_55 = V_90 | V_91 | V_92 ;
if ( F_34 ( V_26 ) < 0 ) {
F_35 ( V_26 ) ;
return - V_10 ;
}
V_96 = V_26 ;
}
#endif
F_37 () ;
F_38 () ;
F_39 () ;
F_40 () ;
return 0 ;
}
int T_8 F_41 ( void )
{
F_42 () ;
F_43 () ;
F_44 () ;
F_45 () ;
if ( V_88 ) {
#if F_36 ( V_94 ) || F_36 ( V_95 )
F_35 ( V_96 ) ;
#endif
#ifdef F_32
F_35 ( V_93 ) ;
#endif
F_46 ( V_88 ) ;
}
return 0 ;
}
int F_47 ( struct V_97 * V_98 )
{
char V_1 [ 8 ] ;
struct V_25 * V_26 ;
if ( F_12 ( ! V_98 ) )
return - V_45 ;
sprintf ( V_1 , L_15 , V_98 -> V_99 ) ;
if ( ( V_26 = F_33 ( V_98 -> V_59 , V_1 , NULL ) ) == NULL )
return - V_10 ;
V_26 -> V_55 = V_90 | V_91 | V_92 ;
if ( F_34 ( V_26 ) < 0 ) {
F_35 ( V_26 ) ;
return - V_10 ;
}
V_98 -> V_100 = V_26 ;
return 0 ;
}
int F_48 ( struct V_97 * V_98 )
{
struct V_87 * V_57 ;
if ( F_12 ( ! V_98 ) )
return - V_45 ;
if ( ! strcmp ( V_98 -> V_101 , V_98 -> V_100 -> V_71 ) )
return 0 ;
V_57 = F_49 ( V_98 -> V_101 , V_88 , V_98 -> V_100 -> V_71 ) ;
if ( V_57 == NULL )
return - V_10 ;
V_98 -> V_102 = V_57 ;
return 0 ;
}
void F_50 ( struct V_97 * V_98 )
{
F_9 ( & V_56 ) ;
if ( V_98 -> V_102 ) {
F_46 ( V_98 -> V_102 ) ;
V_98 -> V_102 = NULL ;
}
if ( strcmp ( V_98 -> V_101 , V_98 -> V_100 -> V_71 ) )
V_98 -> V_102 = F_49 ( V_98 -> V_101 ,
V_88 ,
V_98 -> V_100 -> V_71 ) ;
F_10 ( & V_56 ) ;
}
void F_51 ( struct V_97 * V_98 )
{
if ( ! V_98 )
return;
F_9 ( & V_56 ) ;
F_46 ( V_98 -> V_102 ) ;
V_98 -> V_102 = NULL ;
if ( V_98 -> V_100 )
F_52 ( V_98 -> V_100 ) ;
F_10 ( & V_56 ) ;
}
int F_53 ( struct V_97 * V_98 )
{
if ( ! V_98 )
return 0 ;
F_35 ( V_98 -> V_100 ) ;
V_98 -> V_100 = NULL ;
return 0 ;
}
int F_54 ( struct V_4 * V_5 , char * line , int V_11 )
{
int V_33 = - 1 ;
if ( F_12 ( ! V_5 || ! V_5 -> V_5 ) )
return 1 ;
if ( V_11 <= 0 || V_5 -> V_15 || V_5 -> error )
return 1 ;
while ( ! V_5 -> V_15 ) {
V_33 = V_5 -> V_5 [ V_5 -> V_18 ++ ] ;
if ( V_5 -> V_18 >= V_5 -> V_16 )
V_5 -> V_15 = 1 ;
if ( V_33 == '\n' )
break;
if ( V_11 ) {
V_11 -- ;
* line ++ = V_33 ;
}
}
* line = '\0' ;
return 0 ;
}
const char * F_55 ( char * V_103 , const char * V_104 , int V_11 )
{
int V_33 ;
while ( * V_104 == ' ' || * V_104 == '\t' )
V_104 ++ ;
if ( * V_104 == '"' || * V_104 == '\'' ) {
V_33 = * V_104 ++ ;
while ( -- V_11 > 0 && * V_104 && * V_104 != V_33 ) {
* V_103 ++ = * V_104 ++ ;
}
if ( * V_104 == V_33 )
V_104 ++ ;
} else {
while ( -- V_11 > 0 && * V_104 && * V_104 != ' ' && * V_104 != '\t' ) {
* V_103 ++ = * V_104 ++ ;
}
}
* V_103 = 0 ;
while ( * V_104 == ' ' || * V_104 == '\t' )
V_104 ++ ;
return V_104 ;
}
static struct V_25 * F_56 ( const char * V_71 )
{
struct V_25 * V_26 ;
V_26 = F_20 ( sizeof( * V_26 ) , V_8 ) ;
if ( V_26 == NULL )
return NULL ;
V_26 -> V_71 = F_57 ( V_71 , V_8 ) ;
if ( V_26 -> V_71 == NULL ) {
F_22 ( V_26 ) ;
return NULL ;
}
V_26 -> V_55 = V_105 | V_91 ;
V_26 -> V_31 = V_47 ;
F_58 ( & V_26 -> V_30 ) ;
F_59 ( & V_26 -> V_106 ) ;
F_59 ( & V_26 -> V_107 ) ;
return V_26 ;
}
struct V_25 * F_33 ( struct V_59 * V_59 ,
const char * V_71 ,
struct V_25 * V_108 )
{
struct V_25 * V_26 = F_56 ( V_71 ) ;
if ( V_26 ) {
V_26 -> V_59 = V_59 ;
V_26 -> V_108 = V_108 ;
}
return V_26 ;
}
struct V_25 * F_60 ( struct V_97 * V_98 ,
const char * V_71 ,
struct V_25 * V_108 )
{
struct V_25 * V_26 = F_56 ( V_71 ) ;
if ( V_26 ) {
V_26 -> V_59 = V_98 -> V_59 ;
V_26 -> V_98 = V_98 ;
V_26 -> V_108 = V_108 ;
}
return V_26 ;
}
static void F_52 ( struct V_25 * V_26 )
{
struct V_109 * V_57 , * V_110 ;
struct V_87 * V_111 ;
F_61 (p, n, &entry->children) {
F_52 ( F_62 ( V_57 , struct V_25 , V_107 ) ) ;
}
if ( ! V_26 -> V_57 )
return;
F_63 ( & V_26 -> V_107 ) ;
V_111 = V_26 -> V_108 == NULL ? V_88 : V_26 -> V_108 -> V_57 ;
F_12 ( ! V_111 ) ;
F_46 ( V_26 -> V_57 ) ;
V_26 -> V_57 = NULL ;
}
static int F_64 ( struct V_112 * V_113 )
{
struct V_25 * V_26 = V_113 -> V_114 ;
F_35 ( V_26 ) ;
return 0 ;
}
static int F_65 ( struct V_112 * V_113 )
{
struct V_25 * V_26 = V_113 -> V_114 ;
return F_34 ( V_26 ) ;
}
int F_66 ( struct V_97 * V_98 , const char * V_71 ,
struct V_25 * * V_115 )
{
static struct V_116 V_34 = {
. V_117 = F_64 ,
. V_118 = F_65 ,
} ;
struct V_25 * V_26 ;
int V_14 ;
V_26 = F_60 ( V_98 , V_71 , V_98 -> V_100 ) ;
if ( ! V_26 )
return - V_10 ;
if ( ( V_14 = F_67 ( V_98 , V_119 , V_26 , & V_34 ) ) < 0 ) {
F_35 ( V_26 ) ;
return V_14 ;
}
if ( V_115 )
* V_115 = V_26 ;
return 0 ;
}
void F_35 ( struct V_25 * V_26 )
{
if ( V_26 == NULL )
return;
if ( V_26 -> V_57 ) {
F_9 ( & V_56 ) ;
F_52 ( V_26 ) ;
F_10 ( & V_56 ) ;
}
F_22 ( V_26 -> V_71 ) ;
if ( V_26 -> V_120 )
V_26 -> V_120 ( V_26 ) ;
F_22 ( V_26 ) ;
}
int F_34 ( struct V_25 * V_26 )
{
struct V_87 * V_111 , * V_57 = NULL ;
if ( F_12 ( ! V_26 ) )
return - V_45 ;
V_111 = V_26 -> V_108 == NULL ? V_88 : V_26 -> V_108 -> V_57 ;
F_9 ( & V_56 ) ;
if ( F_68 ( V_26 -> V_55 ) ) {
V_57 = F_69 ( V_26 -> V_71 , V_26 -> V_55 , V_111 ) ;
if ( ! V_57 ) {
F_10 ( & V_56 ) ;
return - V_10 ;
}
} else {
V_57 = F_70 ( V_26 -> V_71 , V_26 -> V_55 , V_111 ,
& V_121 , V_26 ) ;
if ( ! V_57 ) {
F_10 ( & V_56 ) ;
return - V_10 ;
}
F_71 ( V_57 , V_26 -> V_16 ) ;
}
V_26 -> V_57 = V_57 ;
if ( V_26 -> V_108 )
F_72 ( & V_26 -> V_107 , & V_26 -> V_108 -> V_106 ) ;
F_10 ( & V_56 ) ;
return 0 ;
}
static void F_73 ( struct V_25 * V_26 , struct V_4 * V_5 )
{
F_5 ( V_5 ,
L_16 ,
F_74 () -> V_72 ) ;
}
static int T_7 F_37 ( void )
{
struct V_25 * V_26 ;
V_26 = F_33 ( V_89 , L_1 , NULL ) ;
if ( V_26 == NULL )
return - V_10 ;
V_26 -> V_33 . V_69 . V_50 = F_73 ;
if ( F_34 ( V_26 ) < 0 ) {
F_35 ( V_26 ) ;
return - V_10 ;
}
V_122 = V_26 ;
return 0 ;
}
static int T_8 F_45 ( void )
{
F_35 ( V_122 ) ;
return 0 ;
}
